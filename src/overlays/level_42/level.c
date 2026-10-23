#include "matching.h"
#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

extern short D_80065920[], D_800658A0[];
extern int D_8006C648;
int func_8004E880(int, int, int);
int func_8003613C(int, int);
int func_8004F264(int, int);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003585C(Moby*, int, int, int, int, int);
int func_80035EE0(Moby*, int, int, int, int, int);
int func_80035DDC(Moby*, int, int, int, int);
int func_level_42_80084AB8(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
                           int speed, int turnA, int turnB, int avoidA, int avoidB, int argA,
                           int argB, int flags) {
    register Moby* current __asm__("$19");
    register Vector3D* target __asm__("$20");
    register int range __asm__("$23");
    register int rate __asm__("$22");
    register int limit __asm__("$17");
    int avoid;
    register int angle __asm__("$18");
    register int error __asm__("$21");
    register int absolute __asm__("$2");
    register int distance __asm__("$3");
    register int initialHeading __asm__("$16");
    int result;
    register int lowAngle __asm__("$16");
    Vector3D destination;
    current = actor;
    MATCHING_KEEP(current);
    target = center;
    MATCHING_KEEP(target);
    range = radius;
    MATCHING_KEEP(range);
    initialHeading = heading;
    MATCHING_KEEP(initialHeading);
    rate = speed;
    MATCHING_KEEP(rate);
    limit = tolerance;
    avoid = avoidA;
    angle = func_8004E880(current->position.x - target->x, current->position.y - target->y, 0);
    error = func_8003613C(initialHeading, angle & 0xFF);
    distance = func_8004F334(&current->position, target);
    absolute = error;
    if (error < 0)
        absolute = -absolute;
    if (absolute < limit) {
        int radial = distance - range;
        if (radial < 0)
            radial = range - distance;
        if (radial < 0xC8)
            goto done;
    }
    if (avoid != 0xFF) {
        lowAngle = angle & 0xFF;
        if (func_8004F264(lowAngle, avoid) < 5) {
            result = func_8003613C(avoid, lowAngle);
            if (error < 0 && result < 0)
                return 0x100;
            if (error > 0 && result > 0)
                return 0x100;
        }
    }
    if (avoidB != 0xFF) {
        lowAngle = angle & 0xFF;
        if (func_8004F264(lowAngle, avoidB) < 5) {
            result = func_8003613C(avoidB, lowAngle);
            if (error < 0 && result < 0)
                return 0x100;
            if (error > 0 && result > 0)
                return 0x100;
        }
    }
    if (error < 0)
        angle += 3;
    else
        angle -= 3;
    {
        register int lookup __asm__("$3") = angle & 0xFF;
        register int x __asm__("$7");
        MATCHING_KEEP(lookup);
        {
            register int product __asm__("$2") = (D_80065920[lookup] * range) >> 12;
            x = target->x;
            MATCHING_KEEP2(product, x);
            x += product;
        }
        destination.x = x;
        destination.y = target->y + ((D_800658A0[lookup] * range) >> 12);
        heading = func_8004E880(x - current->position.x, destination.y - current->position.y, 0);
    }
    if (D_8006C648 == 3)
        rate += rate >> 1;
    else if (D_8006C648 == 4)
        rate <<= 1;
    if (flags & 8) {
        result = func_8004E880(target->x - current->position.x, target->y - current->position.y, 0);
        func_8003585C(current, result, turnA, 0, 0, 0);
        result = func_80035EE0(current, heading, rate, argA, argB, flags);
    } else {
        if (!func_8003585C(current, heading, turnA, turnB, 1, 0))
            goto done;
        result = func_80035DDC(current, rate, argA, argB, flags);
    }
    if (result)
        return -result;
done:
    return ABS(error);
}

/**
 * UpdateActiveCritter() - func_level_42_80084DD4() - MATCHING
 * https://decomp.me/scratch/atGPB
 */
void func_level_42_80084DD4(Moby* pCritterMoby, int arg1) {
    spyro.unk20a = 1;
    spyro.unk20b = arg1;
    spyro.critterMobyPtr = pCritterMoby;
    if (((g_Camera.cameraState == CAMERA_FIRST_PERSON) && (g_Camera.unk50 >= 2U)) || (spyro.unk17b & 0x2000)) {
        pCritterMoby->lowDrawDistance = 0;
        pCritterMoby->drawn = 0;
        return;
    }
    pCritterMoby->lowDrawDistance = 0x10;
}


#define Controller582CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller582CPlayer[] __asm__("D_80070328");
extern void* Controller582CLinked0 __asm__("D_80070328 + 0x250");
extern void* Controller582CLinked1 __asm__("D_80070328 + 0x250");
extern void* Controller582CLinked2 __asm__("D_80070328 + 0x250");
extern unsigned char Controller582CSave[] __asm__("D_8006C7F8");
extern int D_8006C6C0, D_8006C710, D_8006E524, D_8007203C, D_80072040;
int Controller582CRegisterTrackedValue(void*, int, void*) __asm__("func_8003B7B4");
int Controller582CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller582CTransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Controller582CSoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Controller582CUpdatePlayerRetryState(void) __asm__("func_800498C0");
int Controller582CDispatchPlayerStateRequest(int) __asm__("func_8004BEF8");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original289 instructions and eight owned jump-table words per copy.
 * Original instruction streams, global/helper symbols and table offsets checked
 * independently across23 level copies. Representative: level11/8008582C.
 * Exact entry guards, input mask, word/halfword access widths and eight dispatch
 * targets retained. Eight particle calls retain two rand calls per iteration,
 * signed halfword samples and product shifts7/12. The linked pointer at+250 is
 * reread at the original call boundaries; repeated tests are not consolidated.
 * Numeric units, semantic helper/table producers and caller cadence remain
 * unresolved; once per invocation. Names do not establish semantic meanings.
 * Confidence: exact compiled and linked original words/full retail hashes.
 * Falsifiable vectors: all original words and complete retail SHA values.
 * Empty constraints preserve original register phases without opcode patches.
 */
int func_level_42_80084E4C(int inputMask) {
    register int* gateWord __asm__("$5") = (int*)(Controller582CPlayer + 0x284);
    register signed short* cosine __asm__("$21");
    register signed short* sine __asm__("$20");
    Vector3D offset;
    register int helperArgument __asm__("$4");
    register signed short* cosinePointer __asm__("$5");
    register int firstSample __asm__("$16");
    register int firstTableWord __asm__("$16");
    register int selectedBits __asm__("$19");
    register int secondTableWord __asm__("$2");
    register int particleIndex __asm__("$18");
    int nextWord;
    unsigned char* resultRecord;
    register unsigned char* record0 __asm__("$17");
    register unsigned char* record1 __asm__("$17");

    if ((*gateWord == 0) && (Controller582CField(Controller582CPlayer, int*, 0x1CC) == 0)) {
        if (Controller582CField(Controller582CPlayer, unsigned int*, 0x24C) == 5) {
            Controller582CField(Controller582CPlayer, int*, 0x24) = (int)Controller582CField(
                Controller582CField(Controller582CPlayer, void**, 0x250), int*, 0x18);
            Controller582CField(Controller582CField(Controller582CPlayer, void**, 0x250), int*,
                                0x18) = 0;
        }
        {
            register int inputBits __asm__("$2") =
                Controller582CField(Controller582CPlayer, int*, 0x24);
            MATCHING_KEEP(inputBits);
            selectedBits = inputBits & inputMask;
        }
        if (selectedBits != 0) {
            if (Controller582CField(Controller582CPlayer, unsigned int*, 0x24C) == 5) {
                Controller582CField(Controller582CPlayer, unsigned int*, 0x284) =
                    (unsigned int)Controller582CField(Controller582CPlayer, unsigned int*, 0x24C);
                goto dispatch;
            }
            if (Controller582CField(Controller582CPlayer, int*, 0x48) == 0x26) {
                helperArgument = 0x39;
                Controller582CField(Controller582CPlayer, int*, 0x244) = 0;
                Controller582CField(Controller582CPlayer, void**, 0x250) = 0;
                goto sharedCall;
            }
            goto afterCall;
        sharedCall:
            Controller582CDispatchPlayerStateRequest(helperArgument);
        handled:
            MATCHING_BARRIER_VOLATILE("$2");
            return 1;
        afterCall:
            if (Controller582CField(Controller582CPlayer, unsigned int*, 0x24C) != 7) {
                {
                    register int literal __asm__("$2") = 90;
                    register int remaining __asm__("$3") =
                        Controller582CField(Controller582CPlayer, int*, 0x280);
                    MATCHING_KEEP2(literal, remaining);
                    *gateWord = literal;
                    if (remaining >= 0) {
                        {
                            register int next __asm__("$2") = remaining - 1;
                            Controller582CField(Controller582CPlayer, int*, 0x280) = next;
                            MATCHING_BARRIER_VOLATILE("memory");
                        }
                        D_8006C6C0 += 1;
                        D_8006C710 += 1;
                    }
                }
            }
        dispatch:
            switch (Controller582CField(Controller582CPlayer, unsigned int*, 0x24C)) {
                default:
                    goto handled;
                case 0:
                    helperArgument = 0x1B;
                    goto sharedCall;
                case 1:
                    helperArgument = 0x48;
                    goto sharedCall;
                case 2:
                    helperArgument = 0x58;
                    goto sharedCall;
                case 3:
                    if (({
                            register int selector __asm__("$2") = selectedBits & 8;
                            MATCHING_KEEP(selector);
                            selector;
                        })) {
                        helperArgument = 0x6C;
                        if (Controller582CField(Controller582CPlayer, int*, 0x280) >= 0) {
                            helperArgument = 0x6B;
                        }
                    } else {
                        helperArgument = 0x69;
                        if (Controller582CField(Controller582CPlayer, int*, 0x280) >= 0) {
                            helperArgument = 0x68;
                        }
                    }
                    goto sharedCall;
                case 4:
                    helperArgument = 0x79;
                    goto sharedCall;
                case 5:
                    record0 = Controller582CField(
                        Controller582CField(Controller582CPlayer, void**, 0x250), void**, 0);
                    if (Controller582CField(Controller582CPlayer, int*, 0x240) == 0) {
                        particleIndex = 0;
                        cosine = D_80065920;
                        sine = D_800658A0;
                        do {
                            particleIndex += 1;
                            firstSample = rand() & 0xFF;
                            secondTableWord = rand() & 255;
                            MATCHING_KEEP2(secondTableWord, firstSample);
                            firstTableWord = firstSample * 2;
                            {
                                register int firstAddress __asm__("$3") =
                                    firstTableWord + (int)cosine;
                                register int sample __asm__("$3");
                                register int factor __asm__("$4");
                                register int product __asm__("$8");
                                MATCHING_KEEP(firstAddress);
                                secondTableWord *= 2;
                                cosinePointer = (signed short*)(secondTableWord + (int)cosine);
                                sample = *(signed short*)firstAddress;
                                factor = *cosinePointer;
                                MATCHING_KEEP2(sample, factor);
                                sample >>= 7;
                                product = sample * factor;
                                firstTableWord += (int)sine;
                                MATCHING_KEEP2(product, firstTableWord);
                                sample = product >> 12;
                                MATCHING_KEEP(sample);
                                offset.x = sample;
                                sample = *(signed short*)firstTableWord;
                                factor = *cosinePointer;
                                MATCHING_KEEP2(sample, factor);
                                sample >>= 7;
                                product = sample * factor;
                                {
                                    register unsigned char* position __asm__("$6") = record0 + 0x30;
                                    register Vector3D* prepared __asm__("$7");
                                    register void (*callback)(int, int, Vector3D*,
                                                              Vector3D*) __asm__("$2");
                                    register int zero __asm__("$5");
                                    secondTableWord += (int)sine;
                                    MATCHING_KEEP2_CLOBBER(secondTableWord, position, "$7");
                                    prepared = &offset;
                                    MATCHING_KEEP4(product, position, prepared, secondTableWord);
                                    sample = product >> 12;
                                    MATCHING_KEEP(sample);
                                    offset.y = sample;
                                    secondTableWord = *(signed short*)secondTableWord;
                                    MATCHING_KEEP_CLOBBER(secondTableWord, "$5");
                                    zero = 0;
                                    MATCHING_KEEP2(secondTableWord, zero);
                                    offset.z = secondTableWord >> 7;
                                    MATCHING_BARRIER_VOLATILE("memory");
                                    callback =
                                        (void (*)(int, int, Vector3D*, Vector3D*))SpawnParticle;
                                    MATCHING_KEEP_CLOBBER(callback, "$4");
                                    callback(1, zero, (Vector3D*)position, prepared);
                                }
                            }

                        } while (particleIndex < 8);
                        D_80072040 = 0xC8;
                        D_8007203C = 0xA;
                        if (selectedBits & 1) {
                            Controller582CDispatchPlayerStateRequest(0x8C);
                            nextWord = Controller582CField(record0, int*, 0x24) - 1;
                        } else if (({
                                       register int selector __asm__("$2");
                                       MATCHING_BARRIER("$2");
                                       selector = selectedBits & 2;
                                       MATCHING_KEEP(selector);
                                       selector;
                                   })) {
                            Controller582CDispatchPlayerStateRequest(0x8C);
                            nextWord = Controller582CField(record0, int*, 0x24) - 3;
                        } else {
                            Controller582CDispatchPlayerStateRequest(0x8D);
                            nextWord = Controller582CField(record0, int*, 0x24) - 2;
                        }
                        Controller582CField(record0, int*, 0x24) = nextWord;
                        D_8006C6C0 += 1;
                        MATCHING_BARRIER_VOLATILE("memory");
                        {
                            register int counter __asm__("$2") = D_8006C710;
                            register int remaining __asm__("$3") =
                                Controller582CField(record0, int*, 0x24);
                            MATCHING_KEEP2(counter, remaining);
                            D_8006C710 = counter + 1;
                            if (remaining < 0) {
                                Controller582CField(record0, int*, 0x24) = 0;
                            }
                        }
                        Controller582CRegisterTrackedValue(record0 + 0x24, 4, Controller582CSave);
                        return 1;
                    }

                    return 0;
                case 7: {
                    register void* linked __asm__("$2") = Controller582CLinked0;
                    MATCHING_KEEP(linked);
                    record1 = *(unsigned char**)linked;
                }
                    if (Controller582CField(record1, int*, 0x1C) & 1)
                        return 1;
                    {
                        register int duration __asm__("$16") = 15;
                        Controller582CField(Controller582CPlayer, int*, 0x284) = duration;
                        {
                            register int count __asm__("$2") =
                                Controller582CField(record1, int*, 0x28);
                            register int second __asm__("$5");
                            MATCHING_KEEP_CLOBBER(count, "$5");
                            second = 2;
                            MATCHING_KEEP2(count, second);
                            Controller582CField(record1, int*, 0x28) = count - 1;
                            MATCHING_BARRIER_VOLATILE("memory");
                            Controller582CPlayMobySoundEvent(Controller582CLinked0, second, 0);
                        }
                        D_8006E524 = duration;
                    }
                    if (Controller582CField(Controller582CPlayer, int*, 0x280) > 0 &&
                        Controller582CField(record1, int*, 0x28) > 0)
                        return 1;
                    if (Controller582CSoundHandleMatchesOwnerInStates1Or2(
                            Controller582CLinked1, Controller582CField(record1, int*, 0x48)) != 0) {
                        if (Controller582CSoundHandleMatchesOwnerInStates1Or2(
                                Controller582CLinked2, Controller582CField(record1, int*, 0x48)) !=
                            0)
                            Controller582CTransitionSoundHandleTo3Or5(
                                Controller582CField(record1, int*, 0x48));
                        Controller582CField(record1, int*, 0x48) = -1;
                    }
                    Controller582CUpdatePlayerRetryState();
                    return 1;
                case 6:
                    resultRecord = Controller582CField(
                        Controller582CField(Controller582CPlayer, void**, 0x250), void**, 0);
                    Controller582CField(resultRecord, unsigned short*, 0x66) =
                        (unsigned short)(Controller582CField(resultRecord, unsigned short*, 0x66) |
                                         selectedBits);
                    return 0;
            }
        } else {

            return 0;
        }
    } else {
        return 0;
    }
}

#undef Controller582CField



/**
 * ???() - func_level_42_800852D0() - MATCHING
 * https://decomp.me/scratch/oWPff
 */
int func_level_42_800852D0(Vector3D* vec, int arg1, Moby* pMoby) {
    int temp_s0;

    temp_s0 = spyro.unk17c == 2;
    spyro.unk17a = 0x10000040;
    spyro.m_WhirlwindPointer = pMoby; //whirlwind
    func_8004F178(&spyro.unk19, vec); //fSetVector
    spyro.unk20[0] = arg1;
    return temp_s0;
}

extern int D_8006C578, D_8006C574;
extern short D_80065920[], D_800658A0[];
extern unsigned char DecodedBatchPlayer[] __asm__("D_80070328");
void DecodedBatchZero(Vector3D*) __asm__("func_8004F168");
void DecodedBatchCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DecodedBatchAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedBatchRotate(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int DecodedBatchLength(Vector3D*, int) __asm__("func_8004EDE8");
void DecodedBatchScale(Vector3D*, int, int) __asm__("func_8004F08C");
void DecodedBatchMode(Moby*, int) __asm__("func_80055D24");
int DecodedBatchRandom(int, int) __asm__("func_8003636C");
int DecodedBatchAngle(int, int, int) __asm__("func_8004E880");
void DecodedBatchAnimation(Moby*, int) __asm__("func_80034F80");
int rand(void);
/* Rev 0 representative: level_10 0x80084418..0x80084B04.
 * Preserve the original signed divisions, halfword truncation, class/flag
 * branches and ordered random calls. Empty asm constraints emit no code;
 * they retain the original compiler's argument and temporary lifetimes.
 * AI generated; not yet human reviewed. See the batch provenance document.
 */
void func_level_42_80085344(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
                            int firstAnimation, int argument5) {
    Vector3D average;
    int reserved1C;
    Vector3D temporary;
    int reserved2C;
    Vector3D impulse;
    int reserved3C;
    struct {
        int childClass;
        int reserved44;
        Vector3D* offsets;
    } saved;
    int reservedStack[4];
    register int index __asm__("$19");
    register Moby* source __asm__("$18") = sourceMoby;
    register Moby* child __asm__("$17");
    register short* tag __asm__("$16");
    register Vector3D* temporaryPtr __asm__("$20");
    register unsigned char* player __asm__("$22");
    register short* sine __asm__("$23");
    short* cosine;
    Vector3D* cursor;
    int averageX, averageY, averageZ;
    int randomLow, randomHigh, angle;
    register int impulseX __asm__("$3");
    register int sample0 __asm__("$2");
    register int sample4 __asm__("$4");
    register short* samplePointer __asm__("$4");
    register unsigned int trigByteOffset __asm__("$4");
    register Vector3D* averageArgument __asm__("$4");
    register int offsetArgument __asm__("$5");
    register Vector3D* copyArgument __asm__("$4");
    register Vector3D* offsetBase __asm__("$8");
    register int stackArgument4 __asm__("$8");
    register unsigned int stackArgument5 __asm__("$8");
    MATCHING_KEEP(source);
    averageArgument = &average;
    MATCHING_OBSERVE(averageArgument);
    saved.childClass = childClass;
    saved.offsets = offsets;
    DecodedBatchZero(averageArgument);
    __asm__("" : "=m"(saved) : "m"(saved));
    index = 0;
    if (count > 0) {
        cursor = saved.offsets;
        do {
            DecodedBatchAdd(&average, &average, cursor);
            index++;
            cursor++;
        } while (index < count);
    }
    /* Native division retains the retail zero and overflow traps. */
    averageX = average.x / count;
    averageY = average.y / count;
    averageZ = average.z / count;
    average.x = averageX;
    average.y = averageY;
    average.z = averageZ;
    {
        register int modeArgument __asm__("$5") = 4;
        __asm__("" : "=r"(index) : "0"(0), "r"(modeArgument));
        DecodedBatchMode(source, modeArgument);
    }
    temporaryPtr = &temporary;
    if (count <= 0)
        return;
    cosine = D_80065920;
    sine = D_800658A0;
    player = DecodedBatchPlayer;
    __asm__("" : "=r"(cosine) : "0"(cosine), "r"(sine), "r"(player), "r"(temporaryPtr));
    do {
        /* Capacity exhaustion ends the whole spawn request. */
        if (D_8006C578 - D_8006C574 < 21)
            return;
        __asm__("" : "=m"(saved) : "m"(saved));
        child = SpawnMoby(saved.childClass, source);
        MATCHING_KEEP(child);
        copyArgument = temporaryPtr;
        if (child != 0) {
            offsetArgument = index * 12;
            __asm__("" : "=r"(offsetArgument) : "0"(offsetArgument), "r"(copyArgument));
            offsetBase = saved.offsets;
            tag = child->mobyTag;
            DecodedBatchCopy(copyArgument, (Vector3D*)((char*)offsetBase + offsetArgument));
            DecodedBatchRotate(&source->rotationMatrix, temporaryPtr, temporaryPtr);
            tag[0] = (temporary.x - average.x) >> 2;
            tag[1] = (temporary.y - average.y) >> 2;
            tag[2] = (temporary.z - average.z) >> 2;
            DecodedBatchAdd(&child->position, temporaryPtr, &source->position);
            if (source->mobyClass == 254) {
                child->size = 20;
                child->position.z += 1000;
                tag[0] = (unsigned short)tag[0] + ((cosine[source->unkb] * 5) >> 8);
                tag[1] = (unsigned short)tag[1] + ((sine[source->unkb] * 5) >> 8);
                randomLow = 250;
                randomHigh = 350;
                goto randomZ;
            } else if (source->mobyClass == 132) {
                tag[0] = tag[0] * 3 / 2;
                tag[1] = tag[1] * 3 / 2;
                tag[2] = tag[2] * 2;
                goto finish;
            } else if (source->mobyClass == 999) {
                if (*(int*)(DecodedBatchPlayer + 0x48) == 42) {
                    DecodedBatchCopy(temporaryPtr, (Vector3D*)(DecodedBatchPlayer + 0x8C));
                    DecodedBatchScale(temporaryPtr, DecodedBatchLength(temporaryPtr, 0), 300);
                    tag[0] = (unsigned short)tag[0] + temporary.x;
                    tag[1] = (unsigned short)tag[1] + temporary.y;
                } else {
                    temporary.x = 140;
                    temporary.y = 0;
                    temporary.z = 0;
                    /* The original class-999 branch passes a null matrix. */
                    DecodedBatchRotate(0, temporaryPtr, temporaryPtr);
                    tag[0] = (unsigned short)tag[0] + temporary.x;
                    tag[1] = (unsigned short)tag[1] + temporary.y;
                    tag[2] = (unsigned short)tag[2] + temporary.z;
                }
                goto finish;
            } else if (source->unkb != 0 && (source->damageFlags & 0x100000)) {
                tag[0] = (unsigned short)tag[0] + ((cosine[source->unkb] * 75) >> 11);
                tag[1] = (unsigned short)tag[1] + ((sine[source->unkb] * 75) >> 11);
                randomLow = 40;
                randomHigh = 70;
            randomZ:
                tag[2] = (unsigned short)tag[2] + DecodedBatchRandom(randomLow, randomHigh);
                goto finish;
            } else if (source->damageFlags & 0x40000) {
                tag[0] = (unsigned short)tag[0] + (*(int*)(DecodedBatchPlayer + 0x8C) >> 5);
                tag[1] = (unsigned short)tag[1] + (*(int*)(DecodedBatchPlayer + 0x90) >> 5);
                goto finish;
            } else if (source->damageFlags & 0x2000000) {
                sample0 = cosine[DecodedBatchAngle(child->position.x - *(int*)player,
                                                   child->position.y - *(int*)(player + 4), 0)];
                MATCHING_KEEP(sample0);
                impulse.x = sample0 >> 4;
                sample0 = sine[DecodedBatchAngle(child->position.x - *(int*)player,
                                                 child->position.y - *(int*)(player + 4), 0)];
                MATCHING_KEEP(sample0);
                impulseX = impulse.x;
                impulse.y = sample0 >> 4;
                impulse.z = 0;
                __asm__("" : : "m"(impulse.z), "r"(impulseX));
            } else if ((source->damageFlags & 0x20000) &&
                       (*(int*)(DecodedBatchPlayer + 0x50) == 4 ||
                        *(int*)(DecodedBatchPlayer + 0x50) == 12)) {
                tag[0] = (unsigned short)tag[0] + (*(int*)(DecodedBatchPlayer + 0x8C) >> 6);
                tag[1] = (unsigned short)tag[1] + (*(int*)(DecodedBatchPlayer + 0x90) >> 6);
                goto finish;
            } else {
                if (source->mobyClass == 132)
                    goto finish;
                angle = source->unkb;
                if (angle == 0)
                    angle = DecodedBatchAngle(child->position.x - *(int*)player,
                                              child->position.y - *(int*)(player + 4), 0);
                trigByteOffset = angle * 2;
                MATCHING_KEEP(trigByteOffset);
                sample0 = *(short*)(trigByteOffset + (unsigned int)cosine);
                __asm__("" : "=r"(trigByteOffset) : "0"(trigByteOffset), "r"(sample0));
                samplePointer = (short*)(trigByteOffset + (unsigned int)sine);
                MATCHING_KEEP2(sample0, samplePointer);
                impulseX = (sample0 * 35) >> 10;
                impulse.x = impulseX;
                sample4 = *samplePointer;
                MATCHING_KEEP(sample4);
                impulse.y = (sample4 * 35) >> 10;
                impulse.z = 0;
                __asm__("" : : "m"(impulse.z), "r"(impulseX));
            }
            tag[0] = (unsigned short)tag[0] + impulseX;
            tag[1] = (unsigned short)tag[1] + impulse.y;
        finish:
            child->angle.roll = source->angle.roll;
            child->angle.pitch = source->angle.pitch;
            child->angle.yaw = source->angle.yaw;
            /* Keep the random calls in their original order. */
            tag[3] = (rand() & 6) - 3;
            tag[4] = (rand() & 6) - 3;
            tag[5] = (rand() & 6) - 3;
            tag[7] = source->position.z - 64;
            {
                int lifetime = DecodedBatchRandom(30, 50);
                register int animationArgument __asm__("$5");
                __asm__(""
                        : "=m"(firstAnimation), "=m"(argument5)
                        : "m"(firstAnimation), "m"(argument5));
                stackArgument4 = *(int*)&firstAnimation;
                tag[6] = lifetime;
                tag[8] = 8;
                animationArgument = stackArgument4 + index;
                stackArgument5 = *(unsigned short*)&argument5;
                MATCHING_KEEP(stackArgument5);
                tag[9] = stackArgument5;
                DecodedBatchAnimation(child, animationArgument);
            }
            *(int*)(tag + 10) = 1;
            child->unknownCollision = 0;
        }
        index++;
    } while (index < count);
}

typedef struct {
    Vector3D origin;
    int unkC, unk10, unk14;
} DecodedVectorRecord;
extern short D_800658A0[], D_80065920[];
void func_level_42_80085A34(Vector3D* out, int x, int y, DecodedVectorRecord* record) {
    Vector3D scaled;
    short* cosine;
    short* sine;
    int angle;
    int sineProduct;
    angle = record->unk14;
    scaled.x = (x * record->unkC) >> 7;
    scaled.y = (y * record->unk10) >> 7;
    cosine = D_80065920;
    /* Non-emitting constraint preserves the retail table-base load before index scaling. */
    __asm__("" : "=r"(angle) : "0"(angle), "r"(cosine));
    cosine += angle;
    sine = &D_800658A0[angle];
    out->x = (scaled.x * *cosine + scaled.y * *sine) >> 12;
    sineProduct = scaled.x * *sine;
    out->y = (scaled.y * *cosine - sineProduct) >> 12;
    out->z = 0;
    func_8004F194(out, out, &record->origin);
}

typedef struct {
    short count, index;
    short reserved04[3], step;
    unsigned char* records;
} DecodedPathList;
typedef struct {
    short pitch, yaw, speed, turnLimit;
    short pitchStep, yawStep, arrivalRadius, advanceOnTurn;
} DecodedPathAngles;
int DecodedPathAngle(int, int, int) __asm__("func_8004E880");
int DecodedPathDifference(int, int) __asm__("func_8003615C");
int DecodedPathTrigA(int) __asm__("func_8004EA2C");
int DecodedPathTrigB(int) __asm__("func_8004E9E4");
void DecodedPathMatrix(Angle*, SHORTMATRIX*, int) __asm__("func_8004EA90");
void DecodedPathRotate(SHORTMATRIX*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
void DecodedPathCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DecodedPathAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedPathSubtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
int DecodedPathDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int DecodedPathLength(Vector3D*, int) __asm__("func_8004EDE8");
void DecodedPathPrepare(Moby*, int) __asm__("func_80055D24");
/*
 * USA SCUS-94467 Rev 0: representative func_level_14_8008F74C,
 * 0x8008F74C..0x8008FB88 (271 words). Per-copy original sources and
 * word digests are recorded in overlay-batch-2026-10-04-1312.md.
 * Angle accumulators start at packed byte angles times 16 and wrap
 * with 0xFFF; steps/limits retain signed-halfword reads and stores.
 * Compiled products retain the original low words and signed shifts.
 * Empty asm constraints emit no instructions and preserve the original
 * register lifetimes, fresh reads, stack layout and scheduling.
 * AI-generated reconstruction; not yet human reviewed. Caller cadence,
 * helper return domains and browser/runtime interpretation are unresolved.
 */
int func_level_42_80085B0C(Moby* mobyArgument, DecodedPathList* pathArgument,
                           DecodedPathAngles* angleArgument) {
    Vector3D position;
    int reserved1C;
    Vector3D velocity;
    int reserved2C;
    Vector3D groundOffset;
    int reserved3C;
    SHORTMATRIX matrix;
    Angle orientation;
    Vector3D distance;
    int reserved6C;
    register Moby* moby __asm__("$19") = mobyArgument;
    register DecodedPathList* path __asm__("$20");
    register DecodedPathAngles* angles __asm__("$17");
    register int advanced __asm__("$23");
    register int wrongFacing __asm__("$22");
    register Vector3D* target __asm__("$21");
    register int yawDifference __asm__("$18");
    register int pitchDifference __asm__("$5");
    register int temporary __asm__("$16");
    register int product __asm__("$7");
    register int secondTrig __asm__("$2");
    register int scaled __asm__("$3");
    MATCHING_KEEP(moby);
    path = pathArgument;
    MATCHING_KEEP(path);
    angles = angleArgument;
    MATCHING_KEEP(angles);
    advanced = 0;
    MATCHING_BARRIER("$22");
    {
        register int index __asm__("$2") = path->index;
        register unsigned char* records __asm__("$3") = path->records;
        __asm__("" : "=r"(index) : "0"(index), "r"(records));
        index *= 16;
        target = (Vector3D*)(records + index);
        MATCHING_KEEP(target);
    }
    /* Initialise the two raw angle accumulators only for the -1 sentinel. */
    {
        register int initialPitch __asm__("$3") = angles->pitch;
        register int uninitialised __asm__("$2");
        __asm__("" : : "r"(initialPitch) : "$2", "$22");
        uninitialised = -1;
        wrongFacing = 0;
        if (initialPitch == uninitialised) {
            angles->pitch = moby->angle.pitch * 16;
            angles->yaw = moby->angle.yaw * 16;
        }
    }
    MATCHING_BARRIER_VOLATILE("memory");
    DecodedPathCopy(&position, &moby->position);
    /* Preserve the original ground-offset matrix and vector helper chain. */
    if (moby->distanceToGround) {
        orientation.roll = 0;
        orientation.pitch = (unsigned short)angles->pitch >> 4;
        orientation.yaw = (unsigned short)angles->yaw >> 4;
        DecodedPathMatrix(&orientation, &matrix, 0);
        groundOffset.x = 0;
        groundOffset.y = 0;
        groundOffset.z = -moby->distanceToGround;
        DecodedPathRotate(&matrix, &groundOffset, &groundOffset);
        DecodedPathAdd(&position, &position, &groundOffset);
    }
    secondTrig = DecodedPathAngle(target->x - position.x, target->y - position.y, 1);
    {
        register Vector3D* positionArgument __asm__("$4") = &position;
        register Vector3D* targetArgument __asm__("$5") = target;
        int horizontal;
        int targetPitch;
        __asm__("" : "=r"(targetArgument) : "0"(targetArgument), "r"(positionArgument));
        temporary = secondTrig;
        horizontal = DecodedPathDistance(positionArgument, targetArgument);
        targetPitch = DecodedPathAngle(horizontal, target->z - position.z, 1);
        yawDifference = DecodedPathDifference(angles->yaw, temporary);
        pitchDifference = DecodedPathDifference(angles->pitch, targetPitch);
    }
    /* The optional flag uses the original absolute-difference threshold. */
    if (angles->advanceOnTurn) {
        register int magnitude __asm__("$2") = yawDifference;
        if (yawDifference < 0)
            magnitude = -magnitude;
        MATCHING_KEEP(magnitude);
        if (magnitude > 1024)
            goto turnExceeded;
        magnitude = pitchDifference;
        if (pitchDifference < 0)
            magnitude = -magnitude;
        MATCHING_KEEP(magnitude);
        if (magnitude <= 1024)
            goto turnAccepted;
    turnExceeded:
        wrongFacing = 1;
    }
turnAccepted:
    {
        int limit = angles->turnLimit;
        int negativeLimit = -limit;
        if (yawDifference > limit)
            yawDifference = limit;
        if (yawDifference < negativeLimit)
            yawDifference = negativeLimit;
        if (pitchDifference > limit)
            pitchDifference = limit;
        if (pitchDifference < negativeLimit)
            pitchDifference = negativeLimit;
    }
    /* Accumulate steps, retain the fresh signed read, then clamp both steps. */
    {
        register unsigned int newYawStep __asm__("$2") = (unsigned short)angles->yawStep;
        register unsigned int newPitchStep __asm__("$3") = (unsigned short)angles->pitchStep;
        newYawStep += yawDifference;
        MATCHING_KEEP(newYawStep);
        if (yawDifference < 0)
            yawDifference = -yawDifference;
        newPitchStep += pitchDifference;
        angles->yawStep = newYawStep;
        /* Retail reloads the stored halfword instead of forwarding its word value. */
        MATCHING_OBSERVE_VOLATILE_CLOBBER(newPitchStep, "memory");
        {
            register int currentYawStep __asm__("$2") = angles->yawStep;
            MATCHING_KEEP(currentYawStep);
            if (pitchDifference < 0)
                pitchDifference = -pitchDifference;
            angles->pitchStep = newPitchStep;
            if (currentYawStep > yawDifference)
                angles->yawStep = yawDifference;
        }
    }
    {
        register int currentStep __asm__("$2") = angles->yawStep;
        register int negative __asm__("$3") = -yawDifference;
        __asm__("" : "=r"(negative) : "0"(negative), "r"(currentStep));
        if (currentStep < negative)
            angles->yawStep = negative;
    }
    if (angles->pitchStep > pitchDifference)
        angles->pitchStep = pitchDifference;
    {
        register int currentStep __asm__("$2") = angles->pitchStep;
        register int negative __asm__("$3") = -pitchDifference;
        __asm__("" : "=r"(negative) : "0"(negative), "r"(currentStep));
        if (currentStep < negative)
            angles->pitchStep = negative;
    }
    /* Wrap at 12 bits before writing the packed byte-angle fields. */
    {
        register unsigned int pitch __asm__("$3") = (unsigned short)angles->pitch;
        register unsigned int pitchStep __asm__("$2") = (unsigned short)angles->pitchStep;
        register unsigned int yawStep __asm__("$4") = (unsigned short)angles->yawStep;
        register unsigned int yaw __asm__("$2");
        register unsigned int pitchByte __asm__("$5");
        pitch += pitchStep;
        pitch &= 0xFFF;
        yaw = (unsigned short)angles->yaw;
        pitchByte = pitch >> 4;
        angles->pitch = pitch;
        yaw += yawStep;
        yaw &= 0xFFF;
        angles->yaw = yaw;
        moby->angle.pitch = pitchByte;
        moby->angle.yaw = (unsigned short)angles->yaw >> 4;
    }
    /* Preserve both successive signed shifts in each horizontal component. */
    temporary = DecodedPathTrigA(angles->yaw);
    secondTrig = DecodedPathTrigA(angles->pitch);
    scaled = angles->speed;
    MATCHING_KEEP(scaled);
    product = temporary * scaled;
    scaled = product >> 12;
    MATCHING_KEEP(scaled);
    product = scaled * secondTrig;
    secondTrig = product >> 12;
    MATCHING_KEEP(secondTrig);
    velocity.x = secondTrig;
    temporary = DecodedPathTrigB(angles->yaw);
    secondTrig = DecodedPathTrigA(angles->pitch);
    scaled = angles->speed;
    MATCHING_KEEP(scaled);
    product = temporary * scaled;
    scaled = product >> 12;
    MATCHING_KEEP(scaled);
    product = scaled * secondTrig;
    secondTrig = product >> 12;
    MATCHING_KEEP(secondTrig);
    velocity.y = secondTrig;
    secondTrig = DecodedPathTrigB(angles->pitch);
    scaled = angles->speed;
    MATCHING_KEEP(scaled);
    product = secondTrig * scaled;
    secondTrig = product >> 12;
    MATCHING_KEEP(secondTrig);
    velocity.z = secondTrig;
    DecodedPathAdd(&moby->position, &moby->position, &velocity);
    DecodedPathAdd(&position, &position, &velocity);
    DecodedPathPrepare(moby, 2);
    DecodedPathSubtract(&distance, &position, target);
    /* Signed remainder and the original division traps are retained by the build. */
    if (DecodedPathLength(&distance, 1) < angles->arrivalRadius || wrongFacing) {
        path->index = (path->index + path->step + path->count) % path->count;
        advanced = 1;
    }
    return advanced;
}

typedef struct {
    Vector3D position;
    int reserved0C;
} DecodedBlendPoint;
typedef struct {
    short count, index;
    short reserved04[3], step;
    DecodedBlendPoint* points;
} DecodedBlendPath;
typedef struct {
    short current, previous;
} DecodedBlendWeight;
extern DecodedBlendWeight DecodedBlendWeights[] __asm__("D_80066F0C");
extern DecodedBlendWeight DecodedSingleWeight __asm__("D_8006C410");
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004F1FC(Vector3D*, Vector3D*, int);
void func_8004F110(Vector3D*, int);
int func_8004EDE8(Vector3D*, int);
void func_80037014(Moby*);
void func_80055D24(Moby*, int);
int func_level_42_80085F48(Moby* moby, DecodedBlendPath* path, Vector3D* previous, int* timer,
                           int period, int flags) {
    struct {
        Vector3D delta;
        int reserved1C;
        Vector3D weightedPrevious;
        int reserved2C;
    } work;
    DecodedBlendWeight* weights;
    int threshold;
    int result = 0;
    int flat;
    /* Retail selects weight-table blocks by the supplied period. */
    if (period >= 9) {
        weights = DecodedBlendWeights + 10;
        threshold = 7;
    } else if (period >= 7) {
        weights = DecodedBlendWeights + 4;
        threshold = 5;
    } else if (period >= 5) {
        weights = DecodedBlendWeights;
        threshold = 3;
    } else {
        weights = &DecodedSingleWeight;
        threshold = 1;
    }
    if (*timer >= period) {
        short next;
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        func_8004F178(previous, &work.delta);
        next = (path->index + path->step + path->count) % path->count;
        path->index = next;
        result = 1;
        if ((path->step < 0 && next == path->count - 1) || (path->step > 0 && next == 0))
            result |= 2;
        *timer = 0;
    } else if (*timer > threshold) {
        int divisor;
        register int elapsed __asm__("$2");
        register int x __asm__("$4"), y __asm__("$3"), z __asm__("$2");
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        /* Empty constraints retain the original subtraction and division allocation. */
        elapsed = *timer - 1;
        MATCHING_KEEP(elapsed);
        divisor = period - elapsed;
        x = work.delta.x / divisor;
        y = work.delta.y / divisor;
        z = work.delta.z / divisor;
        MATCHING_KEEP3(x, y, z);
        work.delta.x = x;
        work.delta.y = y;
        work.delta.z = z;
        (*timer)++;
    } else {
        int divisor;
        register int elapsed __asm__("$2");
        register int x __asm__("$4"), y __asm__("$3"), z __asm__("$2");
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        /* Empty constraints retain the original subtraction and division allocation. */
        elapsed = *timer - 1;
        MATCHING_KEEP(elapsed);
        divisor = period - elapsed;
        x = work.delta.x / divisor;
        y = work.delta.y / divisor;
        z = work.delta.z / divisor;
        MATCHING_KEEP3(x, y, z);
        work.delta.x = x;
        work.delta.y = y;
        work.delta.z = z;
        func_8004F1FC(&work.delta, &work.delta, weights[*timer].current);
        func_8004F1FC(&work.weightedPrevious, previous, weights[*timer].previous);
        func_8004F194(&work.delta, &work.delta, &work.weightedPrevious);
        func_8004F110(&work.delta, 10);
        (*timer)++;
    }
    /* Bit 2 clears the vertical displacement and gates the extra actor helper. */
    flat = flags & 4;
    if (flat)
        work.delta.z = 0;
    moby->angle.yaw = func_8004E880(work.delta.x, work.delta.y, 0);
    moby->angle.pitch = -func_8004E880(work.delta.z, func_8004EDE8(&work.delta, 0), 0) + 0x40;
    func_8004F194(&moby->position, &moby->position, &work.delta);
    if (flat)
        func_80037014(moby);
    func_80055D24(moby, 2);
    return result;
}

typedef struct {
    short packetIndex, selector;
    int x, y, z;
    int nextX, nextY, nextZ;
} DecodedPackedPosition;
extern int D_8006C77C;
extern DecodedPackedPosition* D_8006C724;
extern unsigned int** D_8006D048;
void func_level_42_80086350(int selectorArg, Vector3D* positionArg) {
    register Vector3D* position __asm__("$10") = positionArg;
    register int selector __asm__("$13") = selectorArg;
    register int index __asm__("$12");
    register unsigned int byteOffset __asm__("$11");
    int reservedStack[2];
    /* Empty constraints preserve retail allocation and emit no instructions. */
    MATCHING_KEEP(position);
    MATCHING_KEEP(selector);
    index = 0;
    if (D_8006C77C > 0) {
        byteOffset = 0;
        do {
            DecodedPackedPosition* entry =
                (DecodedPackedPosition*)(byteOffset + (unsigned int)D_8006C724);
            if (entry->selector == (selector & 255)) {
                register unsigned int mask __asm__("$7") = 0x1FFFF;
                register unsigned int* packet __asm__("$6");
                int nextX;
                int offsetZ;
                unsigned int preservedHalf;
                unsigned int packedXY;
                register DecodedPackedPosition* firstEntry __asm__("$5");
                int nextZ;
                unsigned int packetFlags;
                int firstZ;
                register unsigned int retainedWord __asm__("$8");
                MATCHING_KEEP(mask);
                packet = D_8006D048[entry->packetIndex];
                nextX = entry->nextX;
                offsetZ = position->z >> 4;
                packedXY = ((nextX + (position->x >> 4)) << 16) |
                           ((entry->nextY + (position->y >> 4)) & 65535);
                preservedHalf = *(unsigned short*)((char*)packet + 4);
                nextZ = entry->nextZ;
                packet[0] = packedXY;
                preservedHalf |= (nextZ + offsetZ) << 16;
                /* Retail rereads the table base between these packet stores. */
                firstEntry = D_8006C724;
                packetFlags = packet[3];
                MATCHING_BARRIER_VOLATILE("memory");
                firstEntry = (DecodedPackedPosition*)(byteOffset + (unsigned int)firstEntry);
                MATCHING_KEEP2_CLOBBER(firstEntry, preservedHalf, "memory");
                __asm__ volatile("" : "=r"(retainedWord) : "0"(packedXY));
                packet[1] = preservedHalf;
                /* Preserve the low 17 bits when packing the first Z value. */
                preservedHalf = packetFlags & mask;
                packedXY = ((firstEntry->x + (position->x >> 4)) << 16) |
                           ((firstEntry->y + (position->y >> 4)) & 65535);
                firstZ = firstEntry->z + (position->z >> 5);
                packet[2] = packedXY;
                preservedHalf |= firstZ << 17;
                packet[3] = preservedHalf;
            }
            byteOffset += 28;
        } while (++index < D_8006C77C);
    }
}
