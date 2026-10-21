#include "matching.h"
#include "common.h"
#include "mobyfunc.h"
#include "drawutil.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "hud.h"

/* Partial record layout: only access widths/offsets proved by the retail
 * routines below are described. Reserved bytes retain unknown meaning. */
typedef struct {
    unsigned char reserved00[0x20];
    int unk20, unk24, unk28, unk2C, unk30, unk34;
    unsigned char unk38;
    unsigned char reserved39[0xF];
    short unk48;
    unsigned char reserved4A[0x36];
    int unk80, unk84, unk88;
    unsigned char reserved8C[2];
    short unk8E;
    int unk90, unk94, unk98;
    unsigned char reserved9C[0xC];
    unsigned char unkA8[0x30];
} DecodedOverlayRecord;


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
int func_level_22_8008F920(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

void func_level_22_8008FC3C(Moby* moby, int mode) {
    spyro.unk20a = 1;
    spyro.unk20b = mode;
    spyro.critterMobyPtr = moby;
    if ((camera.cameraState == CAMERA_FIRST_PERSON && (unsigned int)camera.unk50 >= 2) ||
        (spyro.unk17b & 0x2000)) {
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
    } else {
        moby->lowDrawDistance = 0x10;
    }
}

#define Controller582CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller582CPlayer[] __asm__("D_80070328");
extern void* Controller582CLinked0 __asm__("D_80070328 + 0x250");
extern void* Controller582CLinked1 __asm__("D_80070328 + 0x250");
extern void* Controller582CLinked2 __asm__("D_80070328 + 0x250");
extern unsigned char Controller582CSave[] __asm__("D_8006C7F8");
extern int D_8006C6C0, D_8006C710, D_8006E524, D_8007203C, D_80072040;
int Controller582CHelper3B7B4(void*, int, void*) __asm__("func_8003B7B4");
int Controller582CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller582CHelper3BE70(int) __asm__("func_8003BE70");
int Controller582CHelper3BFC0(void*, int) __asm__("func_8003BFC0");
int Controller582CHelper498C0(void) __asm__("func_800498C0");
int Controller582CHelper4BEF8(int) __asm__("func_8004BEF8");
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
int func_level_22_8008FCB4(int inputMask) {
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
            Controller582CHelper4BEF8(helperArgument);
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
                            Controller582CHelper4BEF8(0x8C);
                            nextWord = Controller582CField(record0, int*, 0x24) - 1;
                        } else if (({
                                       register int selector __asm__("$2");
                                       MATCHING_BARRIER("$2");
                                       selector = selectedBits & 2;
                                       MATCHING_KEEP(selector);
                                       selector;
                                   })) {
                            Controller582CHelper4BEF8(0x8C);
                            nextWord = Controller582CField(record0, int*, 0x24) - 3;
                        } else {
                            Controller582CHelper4BEF8(0x8D);
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
                        Controller582CHelper3B7B4(record0 + 0x24, 4, Controller582CSave);
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
                    if (Controller582CHelper3BFC0(Controller582CLinked1,
                                                  Controller582CField(record1, int*, 0x48)) != 0) {
                        if (Controller582CHelper3BFC0(Controller582CLinked2,
                                                      Controller582CField(record1, int*, 0x48)) !=
                            0)
                            Controller582CHelper3BE70(Controller582CField(record1, int*, 0x48));
                        Controller582CField(record1, int*, 0x48) = -1;
                    }
                    Controller582CHelper498C0();
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


/* Only the retail pointer array at +0x3C is described here. */
typedef struct {
    unsigned char reserved00[0x3C];
    unsigned char* frames[1];
} DecodedFrameTable;
extern DecodedFrameTable* D_8006EE2C[];
void func_level_22_80090138(Moby* moby, int increment, int* accumulator) {
    if (moby->animationState.id != moby->animationState.nextId) {
        *accumulator = 0;
    } else {
        *accumulator += increment;
        moby->animationState.frame =
            (*accumulator >> 4) % D_8006EE2C[moby->mobyClass]->frames[moby->animationState.id][0];
        moby->animationState.nextFrame =
            (moby->animationState.frame + 1) %
            D_8006EE2C[moby->mobyClass]->frames[moby->animationState.id][0];
        moby->animationProgress = *accumulator & 0xF;
    }
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
void func_level_22_80090248(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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

/*
 * USA SCUS-94467 Rev 0: representative func_level_11_80086468,
 * 0x80086468..0x800869E4 (352 instructions). Per-copy evidence is
 * recorded in overlay-batch-2026-10-04-1268.md.
 * Packet fields follow the retail store offsets, including byte colour
 * truncation and signed halfword coordinates. Empty asm constraints emit
 * no instructions; they retain GCC 2.7.2 register allocation/store order.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct {
    unsigned int tag;
    unsigned char red, green, blue, code;
    short x0, y0, x1, y1;
} DecodedHudLine;
typedef struct {
    unsigned int tag;
    unsigned char red0, green0, blue0, code;
    short x0, y0;
    unsigned char red1, green1, blue1, reserved0F;
    short x1, y1;
    unsigned char red2, green2, blue2, reserved17;
    short x2, y2;
    unsigned char red3, green3, blue3, reserved1F;
    short x3, y3;
} DecodedHudQuad;
extern unsigned char* DecodedHudPacketCursor __asm__("D_8006C664");
int DecodedHudSprite(SpriteData*, int, int) __asm__("func_800289C8");
int func_level_22_80090938(HudEntry* argument) {
    int x, y, verticalOffset, reserved1C, barY, reserved24;
    HudEntry* hud = argument;
    register int top __asm__("$20");
    register int bottom __asm__("$17");
    register unsigned int lineTag __asm__("$18");
    register int lineCode __asm__("$19");
    register int colour __asm__("$16");
    register DecodedHudLine* line __asm__("$22");
    register DecodedHudLine* lineArgument __asm__("$4");
    register SpriteData* sprite __asm__("$23");
    register DecodedHudQuad* quad __asm__("$19");
    register DecodedHudQuad* quadArgument __asm__("$4");
    register int width __asm__("$21");
    register int result __asm__("$3");
    register int centredY __asm__("$16");
    register int* xArgument __asm__("$5") = &x;
    register int* yArgument __asm__("$6");
    MATCHING_OBSERVE(xArgument);
    {
        register int frame __asm__("$2") = (unsigned char)hud->unk1C.frame;
        register int initialX __asm__("$3");
        register int initialY __asm__("$7");
        register SpriteData* sprites __asm__("$3");
        MATCHING_KEEP(frame);
        initialX = hud->unk0;
        initialY = hud->unk2;
        MATCHING_OBSERVE2_CLOBBER(initialX, initialY, "$6");
        yArgument = &y;
        MATCHING_OBSERVE3(initialX, initialY, yArgument);
        x = initialX;
        sprites = D_8006C788;
        __asm__("" : "=r"(frame) : "0"(frame), "r"(sprites));
        frame *= 8;
        MATCHING_KEEP(frame);
        y = initialY;
        __asm__ volatile("" : : "m"(y));
        sprite = (SpriteData*)((int)sprites + frame);
    }
    /* Apply the existing HUD position and movement helpers. */
    func_80029674(hud, xArgument, yArgument);
    if ((unsigned char)hud->movementFrame) {
        verticalOffset = ((unsigned char)hud->movementFrame + 10) >> 1;
    } else {
        verticalOffset = 0;
    }
    func_80029708(hud, &verticalOffset, &x, &y);
    {
        register int height __asm__("$2") = sprite->unk5;
        register int low __asm__("$3") = sprite->unk1;
        register int storedY __asm__("$3");
        MATCHING_OBSERVE2(height, low);
        height -= low;
        MATCHING_KEEP(height);
        storedY = y;
        centredY = storedY - (height >> 1);
        y = centredY;
    }
    /* Select the retail bar origin from the sprite bounds. */
    if (hud->displayMode & 1) {
        centredY++;
        MATCHING_KEEP(centredY);
        barY = centredY;
    } else {
        register int edge __asm__("$2") = centredY + sprite->unk5;
        edge -= sprite->unk1;
        edge -= 7;
        MATCHING_KEEP(edge);
        barY = edge;
    }
    /* Bit 3 places the bordered bar before the sprite. */
    if (hud->displayMode & 8) {
        lineCode = 64;
        colour = 192;
        lineTag = 0x03000000;
        line = (DecodedHudLine*)DecodedHudPacketCursor;
        top = barY - 1;
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(line);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->y0 = top;
        MATCHING_BARRIER_VOLATILE("memory");
        bottom = barY + 6;
        MATCHING_KEEP(bottom);
        line->y1 = bottom;
        line->x1 = x + 96;
        line->x0 = x + 96;
        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->y1 = bottom;
        line->y0 = bottom;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(lineArgument);
        line++;
        MATCHING_KEEP(line);
        {
            register DecodedHudLine* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            MATCHING_KEEP(lastLine);
            lastLine->code = lineCode;

            lastLine->red = colour;
            lastLine->green = colour;
            lastLine->blue = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (DecodedHudQuad*)(lastLine + 1);
            MATCHING_KEEP(quad);
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = bottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        /* Four border lines are followed by one gradient quad. */
        quad->tag = 0x08000000;
        quad->code = 56;
        {
            int channel = -32 - hud->unk40 * 224 / 96;
            MATCHING_KEEP(channel);
            quad->red0 = quad->red2 = channel;
            __asm__ volatile("" : : "m"(quad->red0), "m"(quad->red2));
        }
        {
            register int numerator __asm__("$3") = hud->unk40 * 224;
            int greenChannel;
            __asm__("" : "=r"(quad) : "0"(quad), "r"(numerator));
            greenChannel = numerator / 96;
            quad->blue0 = quad->blue2 = 0;
            quad->green1 = quad->green3 = 0;
            quad->blue1 = quad->blue3 = 0;
            MATCHING_KEEP(quad);
            quadArgument = quad;
            MATCHING_OBSERVE(quadArgument);
            quad->red1 = quad->red3 = 224;
            quad->green0 = quad->green2 = greenChannel;
        }
        MATCHING_BARRIER_VOLATILE("memory");
        {
            register int value __asm__("$3") = hud->unk40;
            register int barCoordinate __asm__("$2");
            register int coordinate __asm__("$2");
            MATCHING_BARRIER_VOLATILE("memory");
            barCoordinate = (unsigned short)barY;
            MATCHING_KEEP(barCoordinate);
            quad->y2 = quad->y3 = bottom;
            quad->y0 = quad->y1 = barCoordinate;
            MATCHING_BARRIER_VOLATILE("memory");
            coordinate = x;
            __asm__("" : "=r"(value) : "0"(value), "r"(coordinate));
            value -= 96;
            value = coordinate - value;
            MATCHING_KEEP(value);
            coordinate += 96;
            quad->x0 = quad->x2 = value;
            quad->x1 = quad->x3 = coordinate;
            func_8004E758(quadArgument);
        }
        quad++;
        DecodedHudPacketCursor = (unsigned char*)quad;
        x += 106;
        DecodedHudSprite(sprite, x, y);
        {
            register int spriteWidth __asm__("$2") = sprite->unk4;
            register int left __asm__("$3") = sprite->unk0;
            MATCHING_OBSERVE2(spriteWidth, left);
            spriteWidth -= left;
            MATCHING_KEEP(spriteWidth);
            result = spriteWidth + 106;
        }
    } else {
        /* The other branch draws the sprite before the bordered bar. */
        register int defaultColour __asm__("$17");
        register int defaultBottom __asm__("$16");
        {
            register SpriteData* spriteArgument __asm__("$4") = sprite;
            register int callX __asm__("$5");
            int origin;
            register int callY __asm__("$6");
            MATCHING_OBSERVE(spriteArgument);
            callX = x;
            MATCHING_KEEP(callX);
            origin = barY;
            callY = y;
            top = origin - 1;
            DecodedHudSprite(spriteArgument, callX, callY);
        }
        lineCode = 64;
        defaultColour = 192;
        lineTag = 0x03000000;
        MATCHING_OBSERVE3(lineCode, defaultColour, lineTag);
        width = sprite->unk4;
        MATCHING_KEEP(width);
        {
            register int left __asm__("$2") = sprite->unk0;
            line = (DecodedHudLine*)DecodedHudPacketCursor;
            __asm__("" : "=r"(left) : "0"(left), "r"(line));
            width -= left;
        }
        {
            register int currentX __asm__("$2") = x;
            register int offset __asm__("$3");
            __asm__("" : "=r"(width) : "0"(width), "r"(currentX));
            offset = width + 10;
            MATCHING_KEEP(offset);
            x = currentX + offset;
        }

        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(line);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->y0 = top;
        MATCHING_BARRIER_VOLATILE("memory");
        defaultBottom = barY + 6;
        MATCHING_KEEP(defaultBottom);
        line->y1 = defaultBottom;
        line->x1 = x + 96;
        line->x0 = x + 96;
        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->y1 = defaultBottom;
        line->y0 = defaultBottom;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(lineArgument);
        line++;
        MATCHING_KEEP(line);
        {
            register DecodedHudLine* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            MATCHING_KEEP(lastLine);
            lastLine->code = lineCode;

            lastLine->red = 0;
            lastLine->green = 0;
            lastLine->blue = defaultColour;
            MATCHING_BARRIER_VOLATILE("memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (DecodedHudQuad*)(lastLine + 1);
            MATCHING_KEEP(quad);
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = defaultBottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        /* Four border lines are followed by one gradient quad. */
        quad->tag = 0x08000000;
        quad->code = 56;
        quad->red0 = quad->red2 = 224;
        quad->green0 = quad->green2 = 0;
        quad->blue0 = quad->blue2 = 0;
        {
            int channel = -32 - hud->unk40 * 224 / 96;
            MATCHING_KEEP(channel);
            quad->red1 = quad->red3 = channel;
            __asm__ volatile("" : : "m"(quad->red1), "m"(quad->red3));
        }
        {
            register int numerator __asm__("$2") = hud->unk40 * 224;
            int greenChannel;
            __asm__("" : "=r"(quad) : "0"(quad), "r"(numerator));
            greenChannel = numerator / 96;
            quad->blue1 = quad->blue3 = 0;
            MATCHING_KEEP(quad);
            quad->green1 = quad->green3 = greenChannel;
        }
        MATCHING_BARRIER_VOLATILE("memory");
        {
            register int currentX __asm__("$5") = x;
            register DecodedHudQuad* argument __asm__("$4");
            register int coordinate __asm__("$2");
            register int barCoordinate __asm__("$2");
            register int value __asm__("$3");
            MATCHING_OBSERVE_CLOBBER(currentX, "$4");
            argument = quad;
            MATCHING_OBSERVE(argument);
            coordinate = currentX;
            quad->x0 = quad->x2 = coordinate;
            MATCHING_BARRIER_VOLATILE("memory");
            value = hud->unk40;
            MATCHING_BARRIER_VOLATILE("memory");
            barCoordinate = (unsigned short)barY;
            MATCHING_KEEP(barCoordinate);
            quad->y2 = quad->y3 = defaultBottom;
            value += currentX;
            MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
            quad->y0 = quad->y1 = barCoordinate;
            quad->x1 = quad->x3 = value;
            func_8004E758(argument);
        }
        quad++;
        DecodedHudPacketCursor = (unsigned char*)quad;
        result = width + 116;
    }
    MATCHING_KEEP(result);
    return result;
}

void func_level_22_80090EB8(HudEntry* hud) {
    int value, maximum;
    func_80027D60(hud);
    hud->unk3C += 0x6A;
    if (hud->unk28 != 0) {
        value = *hud->unk28;
        maximum = hud->unk26;
        if (value > maximum)
            value = maximum;
        if (value < 0)
            value = 0;
        hud->unk40 = hud->unk42 = value * 96 / maximum;
    }
}

void func_level_22_80090F60(HudEntry* hud) {
    int value, maximum, current;
    if (hud->unk28 != 0) {
        value = *hud->unk28;
        maximum = hud->unk26;
        if (value > maximum)
            value = maximum;
        if (value < 0)
            value = 0;
        value = value * 96 / maximum;
        if (value < 0)
            value = 0;
        current = hud->unk40;
        hud->unk42 = value;
        if ((unsigned short)current < hud->unk42)
            hud->unk40 = current + 1;
        else if (hud->unk42 < (unsigned short)current)
            hud->unk40 = current - 1;
        if (*hud->unk28 > 0 && hud->unk40 == 0)
            hud->unk40 = 1;
    }
    func_8002798C(hud);
}

#define Timer86B88High(a, b)                                                         \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
#define Timer86B88Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int Timer86B88Motion __asm__("D_8006C64C");
extern unsigned char* Timer86B88SpriteBase __asm__("D_8006C788");
extern short Timer86B88DigitBase __asm__("D_800719CC");
int Timer86B88Place(void*, int*, int*, int*) __asm__("func_80029708");
int Timer86B88Draw(void*, int, int) __asm__("func_800289C8");
/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 356-instruction timer family is the authority. Byte access widths,
 * signed high products, shifts and draw argument sequences retain the disc
 * representation. Counter time units, caller cadence and helper contracts
 * remain unresolved; divisor-based names describe arithmetic only.
 * The high-product constraint follows the existing drawutil.c MULT_HI idiom.
 * Empty constraints emit no instructions. Acceptance requires full retail
 * hashes and unmasked linked instruction words, not a semantic runtime claim.
 */
int func_level_22_80091058(void* input) {
    register unsigned char* owner __asm__("$21");
    struct {
        int drawOrdinal, drawPositionX, drawPositionY, pad1C, quotient3600, pad24, digitWidth,
            pad2C, divide10Multiplier, pad34;
    } frame;
    int* counterPointer;
    register int singleLeadingDigit __asm__("$2");
    int motionFlags;
    register int entryFlags __asm__("$4");
    register int* horizontalOutput __asm__("$23");
    register int* verticalOutput;
    register void* drawOwner __asm__("$4");
    register int* drawIndex __asm__("$5");
    register int* drawX __asm__("$6");
    register int* drawY __asm__("$7");
    register int digitQuotient __asm__("$16");
    register unsigned char* sprite __asm__("$17");
    register int index __asm__("$18");
    register int x __asm__("$19");
    register int remainder60 __asm__("$20");
    register int y __asm__("$22");
    register int counter __asm__("$9");
    register int quotient60 __asm__("$10");
    register int scaled __asm__("$3");
    register int scaledRemainder __asm__("$8");
    register int counterSign __asm__("$11");
    {
        register int digit __asm__("$2") = Timer86B88DigitBase;
        register unsigned char* base __asm__("$3") = Timer86B88SpriteBase;
        register int width __asm__("$2");
        register int other __asm__("$3");
        owner = input;
        MATCHING_OBSERVE3_GNU_VOLATILE_CLOBBER(owner, digit, base, "$4");
        x = Timer86B88Field(owner, short*, 0);
        MATCHING_KEEP3(x, digit, base);
        digit <<= 3;
        sprite = base + digit;
        width = Timer86B88Field(sprite, unsigned char*, 5);
        other = Timer86B88Field(sprite, unsigned char*, 1);
        {
            register int flags __asm__("$4") = Timer86B88Field(owner, unsigned char*, 24);
            MATCHING_KEEP3(width, other, flags);
            motionFlags = flags;
        }
        width -= other;
        other = Timer86B88Field(owner, short*, 2);
        width >>= 1;
        y = other - width;
    }
    if (motionFlags & 2) {
        y -= Timer86B88Motion;
    } else if (motionFlags & 1) {
        y += Timer86B88Motion;
    }
    {
        register int width __asm__("$3") = Timer86B88Field(sprite, unsigned char*, 4);
        register int other __asm__("$2") = Timer86B88Field(sprite, unsigned char*, 0);
        entryFlags = Timer86B88Field(owner, unsigned char*, 63);
        MATCHING_KEEP3(width, other, entryFlags);
        width -= other;
        frame.digitWidth = width;
        if (entryFlags) {
            other = entryFlags + 10;
            MATCHING_KEEP(other);
            index = other >> 1;
        } else {
            MATCHING_BARRIER("$4");
            index = 0;
        }
    }
    counterPointer = Timer86B88Field(owner, int**, 0x28);
    counter = *counterPointer;
    {
        register int magic60 __asm__("$4") = (int)0x88888889;
        register int magic10 __asm__("$12");
        register int width __asm__("$13");
        register int value __asm__("$2");
        register int highFirst __asm__("hi");
        register int highSecond __asm__("hi");
        register int highTens __asm__("hi");
        register int highMinutes __asm__("hi");
        register int digit __asm__("$3");
        register unsigned char* base __asm__("$2");
        highFirst = Timer86B88High(counter, magic60);
        counterSign = counter >> 31;
        {
            register int word __asm__("$12") = highFirst;
            MATCHING_KEEP2(word, counterSign);
            quotient60 = ((word + counter) >> 5) - counterSign;
        }
        value = counter - quotient60 * 60;
        scaled = value * 100;
        highSecond = Timer86B88High(scaled, magic60);
        drawIndex = &frame.drawOrdinal;
        horizontalOutput = &frame.drawPositionX;
        width = frame.digitWidth;
        drawX = horizontalOutput;
        x -= width;
        __asm__(""
                : "=r"(drawIndex), "=r"(horizontalOutput), "=r"(drawX), "=r"(x)
                : "0"(drawIndex), "1"(horizontalOutput), "2"(drawX), "3"(x), "r"(width)
                : "$12");
        magic10 = 0x66666667;
        {
            register int word __asm__("$13") = highSecond;
            MATCHING_KEEP(word);
            scaledRemainder = ((word + scaled) >> 5) - (scaled >> 31);
        }
        highTens = Timer86B88High(scaledRemainder, magic10);
        verticalOutput = &frame.drawPositionY;
        drawY = verticalOutput;
        MATCHING_KEEP(drawY);
        frame.drawOrdinal = index;
        index--;
        frame.drawPositionX = x;
        frame.drawPositionY = y;
        __asm__ __volatile__("" ::: "$2", "$4", "memory");
        value = (int)0x91A2B3C5;
        drawOwner = owner;
        MATCHING_KEEP2(value, drawOwner);
        frame.divide10Multiplier = magic10;
        {
            register int nextWidth __asm__("$12") = frame.digitWidth;
            register int word __asm__("$13");
            __asm__(""
                    : "=r"(nextWidth), "=h"(highTens)
                    : "0"(nextWidth), "1"(highTens)
                    : "memory");
            word = highTens;
            __asm__("" : "=r"(word) : "0"(word) : "$3", "memory");
            digit = Timer86B88DigitBase;
            MATCHING_KEEP_CLOBBER(word, "memory");
            digitQuotient = word >> 2;
            __asm__("" : "=r"(counter), "=r"(digit) : "0"(counter), "1"(digit), "r"(digitQuotient));
            highMinutes = Timer86B88High(counter, value);
            x -= nextWidth;
        }
        value = scaledRemainder >> 31;
        digitQuotient -= value;
        scaledRemainder -= digitQuotient * 10;
        digit += scaledRemainder;
        __asm__("" : "=r"(digit) : "0"(digit) : "$2", "memory");
        base = Timer86B88SpriteBase;
        MATCHING_KEEP2(digit, base);
        digit <<= 3;
        sprite = base + digit;
        __asm__("" : "=r"(sprite), "=h"(highMinutes) : "0"(sprite), "1"(highMinutes));
        {
            register int word __asm__("$12") = highMinutes;
            MATCHING_KEEP(word);
            counter = ((word + counter) >> 11) - counterSign;
        }
        value = counter * 60;
        remainder60 = quotient60 - value;
        frame.quotient3600 = counter;
    }
    Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
    Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
    {
        register int digit __asm__("$2");
        register unsigned char* base __asm__("$3");
        drawOwner = owner;
        drawIndex = &frame.drawOrdinal;
        drawX = horizontalOutput;
        __asm__(""
                : "=r"(drawOwner), "=r"(drawIndex), "=r"(drawX)
                : "0"(drawOwner), "1"(drawIndex), "2"(drawX)
                : "$2", "$3", "memory");
        digit = Timer86B88DigitBase;
        base = Timer86B88SpriteBase;
        __asm__("" : "=r"(digit) : "0"(digit) : "$7", "memory");
        drawY = verticalOutput;
        MATCHING_KEEP2_CLOBBER(digit, drawY, "memory");
        frame.drawOrdinal = index;
        index--;
        frame.drawPositionX = x;
        frame.drawPositionY = y;
        MATCHING_KEEP_CLOBBER(digit, "memory");
        digit += digitQuotient;
        digit <<= 3;
        MATCHING_KEEP2(digit, base);
        sprite = base + digit;
        Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
        Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
    }
    {
        register int digit __asm__("$2");
        register unsigned char* base __asm__("$3");
        register int other __asm__("$3");
        drawOwner = owner;
        drawIndex = &frame.drawOrdinal;
        drawX = horizontalOutput;
        __asm__(""
                : "=r"(drawOwner), "=r"(drawIndex), "=r"(drawX)
                : "0"(drawOwner), "1"(drawIndex), "2"(drawX)
                : "$2", "$3", "memory");
        digit = Timer86B88DigitBase;
        base = Timer86B88SpriteBase;
        digit <<= 3;
        digit += 96;
        MATCHING_KEEP2_CLOBBER(digit, base, "$7");
        sprite = base + digit;
        digit = Timer86B88Field(sprite, unsigned char*, 4);
        other = Timer86B88Field(sprite, unsigned char*, 0);
        drawY = verticalOutput;
        frame.drawPositionY = y;
        frame.drawOrdinal = index;
        MATCHING_KEEP3_CLOBBER(digit, other, drawY, "memory");
        digit -= other;
        x -= digit;
        frame.drawPositionX = x;
        Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
        Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
    }
    {
        register int test __asm__("$13") = frame.quotient3600;
        MATCHING_KEEP(test);
        drawIndex = &frame.drawOrdinal;
        if (test) {
            register int magic __asm__("$12");
            register int high __asm__("hi");
            register int width __asm__("$13");
            register int digit __asm__("$3");
            register int value __asm__("$2");
            register unsigned char* base __asm__("$2");
            register int word __asm__("$12");
            index--;
            drawOwner = owner;
            MATCHING_KEEP2_CLOBBER(index, drawOwner, "memory");
            magic = frame.divide10Multiplier;
            high = Timer86B88High(remainder60, magic);
            drawX = horizontalOutput;
            drawY = verticalOutput;
            frame.drawOrdinal = index;
            index--;
            width = frame.digitWidth;
            digit = Timer86B88DigitBase;
            value = remainder60 >> 31;
            frame.drawPositionY = y;
            MATCHING_KEEP5_CLOBBER(drawOwner, drawX, drawY, x, value, "memory");
            x -= width;
            frame.drawPositionX = x;
            __asm__("" : "=r"(x), "=h"(high) : "0"(x), "1"(high) : "memory");
            x -= width;
            __asm__("" : "=r"(x), "=h"(high) : "0"(x), "1"(high), "r"(width));
            word = high;
            MATCHING_KEEP(word);
            digitQuotient = (word >> 2) - value;
            value = remainder60 - digitQuotient * 10;
            digit += value;
            __asm__("" : "=r"(digit) : "0"(digit) : "$2", "memory");
            base = Timer86B88SpriteBase;
            MATCHING_KEEP2(digit, base);
            digit <<= 3;
            sprite = base + digit;
            Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
            Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
            {
                register int nextDigit __asm__("$2");
                register unsigned char* nextBase __asm__("$3");
                drawOwner = owner;
                drawIndex = &frame.drawOrdinal;
                drawX = horizontalOutput;
                __asm__(""
                        : "=r"(drawOwner), "=r"(drawIndex), "=r"(drawX)
                        : "0"(drawOwner), "1"(drawIndex), "2"(drawX)
                        : "$2", "$3", "memory");
                nextDigit = Timer86B88DigitBase;
                nextBase = Timer86B88SpriteBase;
                __asm__("" : "=r"(nextDigit) : "0"(nextDigit) : "$7", "memory");
                drawY = verticalOutput;
                MATCHING_KEEP2_CLOBBER(nextDigit, drawY, "memory");
                frame.drawOrdinal = index;
                index--;
                frame.drawPositionX = x;
                frame.drawPositionY = y;
                MATCHING_KEEP_CLOBBER(nextDigit, "memory");
                nextDigit += digitQuotient;
                nextDigit <<= 3;
                MATCHING_KEEP2(nextDigit, nextBase);
                sprite = nextBase + nextDigit;
                Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
                Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
            }
            {
                register int nextDigit __asm__("$2");
                register unsigned char* nextBase __asm__("$3");
                register int other __asm__("$3");
                drawOwner = owner;
                drawIndex = &frame.drawOrdinal;
                drawX = horizontalOutput;
                __asm__(""
                        : "=r"(drawOwner), "=r"(drawIndex), "=r"(drawX)
                        : "0"(drawOwner), "1"(drawIndex), "2"(drawX)
                        : "$2", "$3", "memory");
                nextDigit = Timer86B88DigitBase;
                nextBase = Timer86B88SpriteBase;
                nextDigit <<= 3;
                nextDigit += 88;
                MATCHING_KEEP2_CLOBBER(nextDigit, nextBase, "$7");
                sprite = nextBase + nextDigit;
                nextDigit = Timer86B88Field(sprite, unsigned char*, 4);
                other = Timer86B88Field(sprite, unsigned char*, 0);
                drawY = verticalOutput;
                frame.drawPositionY = y;
                frame.drawOrdinal = index;
                MATCHING_KEEP3_CLOBBER(nextDigit, other, drawY, "memory");
                nextDigit -= other;
                x -= nextDigit;
                frame.drawPositionX = x;
                Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
                Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
            }
            {
                register int number __asm__("$13") = frame.quotient3600;
                register int factor __asm__("$12") = frame.divide10Multiplier;
                register int productHigh __asm__("hi");
                register int remainder __asm__("$2");
                register int digitBase __asm__("$3");
                register unsigned char* sprites __asm__("$2");
                MATCHING_KEEP3(index, number, factor);
                index--;
                productHigh = Timer86B88High(number, factor);
                drawOwner = owner;
                drawIndex = &frame.drawOrdinal;
                number = frame.digitWidth;
                drawX = horizontalOutput;
                x -= number;
                __asm__(""
                        : "=r"(drawOwner), "=r"(drawIndex), "=r"(drawX), "=r"(x)
                        : "0"(drawOwner), "1"(drawIndex), "2"(drawX), "3"(x), "r"(number)
                        : "memory");
                number = frame.quotient3600;
                drawY = verticalOutput;
                frame.drawPositionY = y;
                frame.drawOrdinal = index;
                frame.drawPositionX = x;
                remainder = number >> 31;
                __asm__(""
                        : "=h"(productHigh), "=r"(remainder), "=r"(number)
                        : "0"(productHigh), "1"(remainder), "2"(number)
                        : "memory");
                factor = productHigh;
                MATCHING_KEEP(factor);
                digitBase = factor >> 2;
                digitQuotient = digitBase - remainder;
                remainder = digitQuotient * 10;
                digitBase = Timer86B88DigitBase;
                remainder = number - remainder;
                digitBase += remainder;
                __asm__("" : "=r"(digitBase) : "0"(digitBase) : "$2", "memory");
                sprites = Timer86B88SpriteBase;
                MATCHING_KEEP2(digitBase, sprites);
                digitBase <<= 3;
                sprite = sprites + digitBase;
                Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
                Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
                factor = frame.quotient3600;
                MATCHING_KEEP(factor);
                singleLeadingDigit = factor < 10;
            }
        } else {
            register int factor __asm__("$12");
            register int productHigh __asm__("hi");
            register int width __asm__("$13");
            register int value __asm__("$2");
            register int digit __asm__("$3");
            register unsigned char* base __asm__("$2");
            factor = frame.divide10Multiplier;
            productHigh = Timer86B88High(remainder60, factor);
            index--;
            drawOwner = owner;
            drawX = horizontalOutput;
            drawY = verticalOutput;
            width = frame.digitWidth;
            value = remainder60 >> 31;
            frame.drawPositionY = y;
            frame.drawOrdinal = index;
            MATCHING_KEEP5_CLOBBER(drawOwner, drawX, drawY, x, value, "memory");
            x -= width;
            frame.drawPositionX = x;
            __asm__(""
                    : "=r"(x), "=h"(productHigh)
                    : "0"(x), "1"(productHigh), "r"(width)
                    : "memory");
            factor = productHigh;
            MATCHING_KEEP(factor);
            digit = factor >> 2;
            digitQuotient = digit - value;
            value = digitQuotient * 10;
            digit = Timer86B88DigitBase;
            value = remainder60 - value;
            digit += value;
            __asm__("" : "=r"(digit) : "0"(digit) : "$2", "memory");
            base = Timer86B88SpriteBase;
            MATCHING_KEEP2(digit, base);
            digit <<= 3;
            sprite = base + digit;
            Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
            Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
            singleLeadingDigit = remainder60 < 10;
        }
    }
    MATCHING_KEEP(singleLeadingDigit);
    if (!singleLeadingDigit) {
        register int width __asm__("$13");
        register int digit __asm__("$2");
        register unsigned char* base __asm__("$3");
        index--;
        drawOwner = owner;
        drawIndex = &frame.drawOrdinal;
        drawX = horizontalOutput;
        __asm__(""
                : "=r"(drawOwner), "=r"(drawIndex), "=r"(drawX)
                : "0"(drawOwner), "1"(drawIndex), "2"(drawX)
                : "$2", "$3", "memory");
        width = frame.digitWidth;
        digit = Timer86B88DigitBase;
        base = Timer86B88SpriteBase;
        drawY = verticalOutput;
        frame.drawPositionY = y;
        frame.drawOrdinal = index;
        MATCHING_KEEP5_CLOBBER(x, digit, base, width, drawY, "memory");
        x -= width;
        digit += digitQuotient;
        digit <<= 3;
        MATCHING_KEEP2(digit, base);
        sprite = base + digit;
        frame.drawPositionX = x;
        Timer86B88Place(drawOwner, drawIndex, drawX, drawY);
        Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
    }
    return 0;
}

#undef Timer86B88Field

#undef Timer86B88High

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
int func_level_22_800915E8(Moby* argument, DecodedPathList* pathArgument,
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
    register Moby* moby __asm__("$19") = argument;
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
int func_level_22_80091A24(Moby* moby, DecodedBlendPath* path, Vector3D* previous, int* timer,
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

/* AI generated;
not yet human reviewed. SCUS-94467 USA Rev 0.
* Original 410 instructions per copy are the acceptance authority.
* Retain byte offsets, access widths, table indices, signed integer products,
* shifts and helper/indirect-call register and stack arguments.
* Physical units, full helper contracts, table meanings and caller cadence
* remain unresolved. Empty constraints retain allocation and scheduling and
* emit no instructions. No semantic runtime completeness is claimed.
* Falsifiable check: every original linked word and full retail binary hashes.
*/
#ifndef Geometry87118Field
#define Geometry87118Field(base, type, offset) (*(type)((unsigned char*)(base) + (offset)))
#endif
extern short D_80065920[], D_800658A0[];
int func_8003585C(Moby*, int, int, int, int, int);
int func_80035DDC(Moby*, int, int, int, int);
int func_8004F334(Vector3D*, Vector3D*);
int func_8004EDE8(Vector3D*, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
extern int (*Geometry87118Callback)(Moby*, unsigned char*, int, int, int, int, int, int, int, int,
                                    int, int, int) __asm__("unk_ovlheader_80074314");
int func_800387AC(unsigned char*, Vector3D*, int*, int*, int, int);
/* extern */
int func_level_22_80091E2C(Moby* owner, int tableSelector, int tableMultiplier, int helperInput,
                           volatile int helperStack0, volatile int helperStack1,
                           unsigned char** records, volatile int recordCount,
                           unsigned char* volatile alternateRecords) {
    register Moby* moby __asm__("$22") = owner;
    struct {
        Vector3D point;
        int pad44;
        int projectedX, projectedY;
        int temporaryX, temporaryY;
        int selectedAngle, pad5C;
        Vector3D differenceVector;
        int pad6C;
        Vector3D endpoint;
        int pad7C;
        int angle, pad84, radius, pad8C, helperInput;
        int originalSpillSpace[8];
    } scratch;
    register unsigned char* temp_a2 __asm__("$6");
    register unsigned char* raw2 __asm__("$2");
    register unsigned char* raw3 __asm__("$3");
    int temp_a0_2;
    int temp_a0_3;
    register int temp_a1 __asm__("$5");
    register int temp_a1_2 __asm__("$5");
    register int temp_a1_3 __asm__("$5");
    register int maskedWord __asm__("$19");
    register int temp_v0 __asm__("$2");
    register int product10 __asm__("$10");
    register int product8 __asm__("$8");
    register int product7 __asm__("$7");
    register int point4 __asm__("$4");
    register int point6 __asm__("$6");
    register Moby* callOwner __asm__("$4");
    register int call5 __asm__("$5");
    register int call6 __asm__("$6");
    register int call7 __asm__("$7");
    register int call9 __asm__("$9");
    int (*callback2)(Moby*, unsigned char*, int, int, int, int, int, int, int, int, int, int, int);
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    register int temp_v1 __asm__("$3");
    register int temp_v1_2 __asm__("$3");
    register int var_a1 __asm__("$5");
    int var_a2;
    register int var_s0 __asm__("$16");
    register int edgeCursor __asm__("$17");
    register int projectionCursor __asm__("$17");
    register int alternateCursor __asm__("$18");
    register int edgeOffset __asm__("$19");
    register int alternateOffset __asm__("$20");
    register int minimumResult __asm__("$21");
    register int recordCursor __asm__("$23");
    register int var_v0 __asm__("$2");
    unsigned char** recordPointer;
    register unsigned char* temp_a0 __asm__("$4");
    register unsigned char* edge __asm__("$16");
    register unsigned char* record __asm__("$18");
    unsigned char* temp_v0_6;
    unsigned char* temp_v0_7;
    unsigned char* temp_v0_8;
    unsigned char* temp_v1_3;
    register unsigned char* selectedEntry __asm__("$20");
    register int tableIndex __asm__("$4");
    register int spilledValue __asm__("$9");
    register int pointX __asm__("$8");
    register int pointY __asm__("$7");
    register int edgeCount __asm__("$2");
    register int polygonCount __asm__("$9");
    register int currentOffset __asm__("$17");
    register unsigned char* alternate __asm__("$9");
    register int shiftedProduct __asm__("$3");
    register int originalTableValue __asm__("$2");
    register Vector3D* differenceVector __asm__("$21");
    scratch.angle = tableSelector;
    scratch.radius = tableMultiplier;
    scratch.helperInput = helperInput;
    scratch.selectedAngle = -1;
    func_8004F178(&scratch.point, &moby->position);
    spilledValue = scratch.angle;
    MATCHING_KEEP_CLOBBER(spilledValue, "memory");
    tableIndex = spilledValue << 1;
    originalTableValue = *(short*)((unsigned char*)D_80065920 + tableIndex);
    MATCHING_KEEP2_CLOBBER(originalTableValue, tableIndex, "memory");
    spilledValue = scratch.radius;
    spilledValue = originalTableValue * spilledValue;
    MATCHING_KEEP(spilledValue);
    shiftedProduct = spilledValue >> 12;
    MATCHING_KEEP(shiftedProduct);
    scratch.point.x += shiftedProduct;
    MATCHING_BARRIER_VOLATILE("memory");
    originalTableValue = *(short*)((unsigned char*)D_800658A0 + tableIndex);
    MATCHING_KEEP2_CLOBBER(originalTableValue, tableIndex, "memory");
    spilledValue = scratch.radius;
    spilledValue = originalTableValue * spilledValue;
    MATCHING_KEEP(spilledValue);
    shiftedProduct = spilledValue >> 12;
    MATCHING_KEEP(shiftedProduct);
    polygonCount = recordCount;
    scratch.point.y += shiftedProduct;
    if (polygonCount != 0) {
        recordCursor = 0;
        if (polygonCount > 0) {
            recordPointer = records;
            MATCHING_KEEP(recordPointer);
        recordLoop:
            record = *recordPointer;
            if (Geometry87118Field(record, unsigned char*, 0) == 0) {
                if (func_8004F334(&moby->position, (Vector3D*)(record + 4)) <
                    Geometry87118Field(record, short*, 2)) {
                    edgeCount = Geometry87118Field(record, unsigned char*, 1);
                    MATCHING_KEEP(edgeCount);
                    edgeCursor = 0;
                    if (edgeCount > 0) {
                        var_a2 = 0xC;
                        pointX = scratch.point.x;
                        pointY = scratch.point.y;
                        MATCHING_KEEP2(pointX, pointY);
                    edgeLoop:
                        MATCHING_KEEP2_VOLATILE(edgeCursor, record);
                        temp_a0 = record + var_a2;
                        temp_a1 = pointX - Geometry87118Field(temp_a0, int*, 8);
                        scratch.temporaryX = temp_a1;
                        temp_v1 = pointY - Geometry87118Field(temp_a0, int*, 0xC);
                        scratch.temporaryY = temp_v1;
                        temp_v1 = Geometry87118Field(temp_a0, int*, 0) * temp_v1;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(temp_v1, "memory");
                        temp_v0 = Geometry87118Field(temp_a0, int*, 4);
                        MATCHING_KEEP(temp_v0);
                        product10 = temp_v0 * temp_a1;
                        MATCHING_KEEP2(temp_v1, product10);
                        var_v0 = temp_v1 - product10;
                        MATCHING_KEEP(var_v0);
                        if (var_v0 >= 0) {
                            edgeCount = Geometry87118Field(record, unsigned char*, 1);
                            MATCHING_KEEP2(edgeCount, edgeCursor);
                            edgeCursor += 1;
                            var_a2 += 0x1C;
                            if (edgeCursor < edgeCount) {
                                goto edgeLoop;
                            }
                        }
                        edgeCount = Geometry87118Field(record, unsigned char*, 1);
                    }
                    if (edgeCursor == edgeCount) {
                        minimumResult = 0x98967F;
                        projectionCursor = 0;
                        selectedEntry = 0;
                        if (edgeCount != 0) {
                            edgeOffset = 0xC;
                            do {
                                MATCHING_KEEP2_VOLATILE(edgeOffset, projectionCursor);
                                edge = record + edgeOffset;
                                MATCHING_KEEP_VOLATILE(edge);
                                temp_a1_2 = Geometry87118Field(edge, int*, 16);
                                point4 = scratch.point.x;
                                MATCHING_KEEP2(temp_a1_2, point4);
                                product7 = temp_a1_2 * point4;
                                temp_v0 = Geometry87118Field(edge, int*, 20);
                                point6 = scratch.point.y;
                                product8 = temp_v0 * point6;
                                temp_v1_2 = Geometry87118Field(edge, int*, 24);
                                MATCHING_KEEP5(product7, product8, temp_v1_2, point4, point6);
                                temp_v0 = product7 + product8;
                                temp_v1_2 += temp_v0;
                                temp_v1_2 >>= 10;
                                product8 = temp_v1_2 * temp_a1_2;
                                MATCHING_KEEP4(product8, point4, point6, temp_v1_2);
                                temp_v0 = product8 >> 10;
                                point4 -= temp_v0;
                                scratch.temporaryX = point4;
                                temp_v0 = Geometry87118Field(edge, int*, 20);
                                temp_v1_2 *= temp_v0;
                                MATCHING_KEEP2(temp_v1_2, point6);
                                temp_v0 = temp_v1_2 >> 10;
                                point6 -= temp_v0;
                                scratch.temporaryY = point6;
                                temp_v0 =
                                    func_8004F334((Vector3D*)&scratch.temporaryX, &scratch.point);
                                point4 = temp_v0;
                                MATCHING_KEEP(point4);
                                temp_v0 = point4 < minimumResult;
                                if (temp_v0) {
                                    selectedEntry = edge;
                                    temp_v0 = scratch.temporaryX;
                                    temp_v1 = scratch.temporaryY;
                                    MATCHING_KEEP3(temp_v0, temp_v1, point4);
                                    minimumResult = point4;
                                    scratch.projectedX = temp_v0;
                                    scratch.projectedY = temp_v1;
                                }
                                edgeCount = Geometry87118Field(record, unsigned char*, 1);
                                MATCHING_KEEP2(edgeCount, projectionCursor);
                                projectionCursor += 1;
                                edgeOffset += 0x1C;
                            } while (projectionCursor < edgeCount);
                        }
                        temp_v0_2 = func_8004E880(Geometry87118Field(selectedEntry, int*, 0),
                                                  Geometry87118Field(selectedEntry, int*, 4), 0);
                        scratch.selectedAngle = temp_v0_2;
                        if (func_8004F264(temp_v0_2, (int)moby->angle.yaw) >= 0x41) {
                            scratch.selectedAngle = (scratch.selectedAngle + 0x80) & 0xFF;
                        }
                    }
                }
                goto nextRecord;
            }
            if (func_800387AC(record, &scratch.point, &scratch.projectedX, &scratch.selectedAngle,
                              (int)moby->angle.yaw, 0x200) != 0x2000) {
            nextRecord:
                polygonCount = recordCount;
                MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(polygonCount, recordCursor, "memory");
                recordCursor++;
                temp_v0 = recordCursor < polygonCount;
                MATCHING_KEEP2(temp_v0, recordPointer);
                recordPointer++;
                if (temp_v0 == 0)
                    goto checkSelectedValue;
                goto recordLoop;
            }
            return 0x2000;
        }
    }
checkSelectedValue:
    if (scratch.selectedAngle != -1) {
        if (func_8004F264(scratch.angle, scratch.selectedAngle) >= 0x51) {
            scratch.selectedAngle = (scratch.selectedAngle + 0x80) & 0xFF;
        }
        if (func_8003585C(moby, scratch.selectedAngle, 4, 3, 0, 0) != 0) {
            callOwner = moby;
            temp_v0 = moby->position.x;
            call5 = scratch.radius;
            temp_v1 = scratch.projectedX;
            call6 = scratch.helperInput;
            MATCHING_KEEP5(temp_v0, call5, temp_v1, call6, callOwner);
            scratch.temporaryX = temp_v0;
            temp_v0 = moby->position.y;
            MATCHING_KEEP(temp_v0);
            scratch.temporaryY = temp_v0;
            moby->position.x = temp_v1;
            temp_v0 = scratch.projectedY;
            call7 = helperStack0;
            MATCHING_KEEP2(temp_v0, call7);
            moby->position.y = temp_v0;
            __asm__ __volatile__("" ::: "$9", "memory");
            call9 = helperStack1;
            MATCHING_KEEP(call9);
            temp_v0 = func_80035DDC(callOwner, call5, call6, call7, call9);
            point4 = moby->position.x;
            temp_v1 = scratch.temporaryX;
            __asm__ __volatile__("" ::: "$5", "memory");
            temp_a1_3 = temp_v0;
            MATCHING_KEEP3(point4, temp_v1, temp_a1_3);
            temp_a0_2 = point4;
            temp_v0_3 = point4 - temp_v1;
            if (temp_v0_3 >= 0) {
                if (temp_v0_3 >= 5) {
                    var_a1 = temp_a1_3 | 0x1000;
                } else {
                    goto checkSecondComponent;
                }
            } else if (({
                           var_v0 = temp_v1 - temp_a0_2;
                           MATCHING_KEEP(var_v0);
                           var_v0;
                       }) < 5) {
            checkSecondComponent:
                temp_a0_3 = moby->position.y;
                temp_v0_4 = temp_a0_3 - scratch.temporaryY;
                if (temp_v0_4 >= 0) {
                    if (temp_v0_4 >= 5) {
                        var_a1 = temp_a1_3 | 0x1000;
                    } else {
                        goto setBit2000;
                    }
                } else if ((scratch.temporaryY - temp_a0_3) < 5) {
                setBit2000:
                    var_a1 = temp_a1_3 | 0x2000;
                } else {
                    goto setBit1000;
                }
            } else {
            setBit1000:
                var_a1 = temp_a1_3 | 0x1000;
            }
            return var_a1;
        }
        goto returnZero;
    }
    alternate = alternateRecords;
    MATCHING_KEEP(alternate);
    if (alternate == 0)
        goto fallback3585C;
    alternateCursor = 0;
    if (Geometry87118Field(alternate, short*, 0) <= 0)
        goto fallback3585C;
    differenceVector = &scratch.differenceVector;
    MATCHING_KEEP(differenceVector);
    alternateOffset = 0;
alternateLoop:
    alternate = alternateRecords;
    MATCHING_KEEP(alternate);
    temp_v0 = (int)Geometry87118Field(alternate, unsigned char**, 12);
    __asm__ __volatile__("" ::: "$17", "memory");
    currentOffset = alternateOffset;
    MATCHING_KEEP2(temp_v0, currentOffset);
    temp_a2 = (unsigned char*)(currentOffset + temp_v0);
    temp_v0 = Geometry87118Field(temp_a2, int*, 12);
    maskedWord = temp_v0 & 0x7FFF;
    MATCHING_KEEP2(maskedWord, temp_v0);
    var_s0 = maskedWord;
    if (temp_v0 & 0x8000) {
        temp_v0 = maskedWord << 2;
        temp_v0 += maskedWord;
        MATCHING_KEEP(temp_v0);
        var_s0 = temp_v0 >> 2;
    }
    func_8004F1C8(differenceVector, &scratch.point, (Vector3D*)temp_a2);
    temp_v0 = func_8004EDE8(differenceVector, 0);
    call6 = 0;
    if (temp_v0 >= var_s0)
        goto clearAlternateFlag;
    alternate = alternateRecords;
    point4 = moby->position.x;
    raw2 = Geometry87118Field(alternate, unsigned char**, 12);
    __asm__ __volatile__("" ::: "$5", "memory");
    call5 = moby->position.y;
    MATCHING_KEEP4(alternate, point4, raw2, call5);
    raw2 = (unsigned char*)(currentOffset + (int)raw2);
    temp_v1 = Geometry87118Field(raw2, int*, 0);
    temp_v0 = Geometry87118Field(raw2, int*, 4);
    MATCHING_KEEP4(temp_v1, temp_v0, point4, call5);
    point4 = temp_v1 - point4;
    call5 = temp_v0 - call5;
    temp_v0 = func_8004E880(point4, call5, call6);
    temp_v0 = func_8004F264(scratch.angle, temp_v0);
    point4 = (int)&scratch.endpoint;
    if (temp_v0 < 64)
        goto hitAlternate;
clearAlternateFlag:
    {
        alternate = alternateRecords;
        MATCHING_KEEP(alternate);
        raw2 = Geometry87118Field(alternate, unsigned char**, 12);
        MATCHING_KEEP(raw2);
        raw2 = (unsigned char*)(currentOffset + (int)raw2);
        temp_v1 = Geometry87118Field(raw2, int*, 12);
        MATCHING_KEEP(temp_v1);
        temp_v1 &= 0x7FFF;
        Geometry87118Field(raw2, int*, 12) = temp_v1;
        temp_v0 = Geometry87118Field(alternate, short*, 0);
        MATCHING_KEEP2(temp_v0, alternateCursor);
        alternateCursor++;
        temp_v0 = alternateCursor < temp_v0;
        MATCHING_KEEP2(temp_v0, currentOffset);
        alternateOffset = currentOffset + 16;
        if (temp_v0)
            goto alternateLoop;
    }
fallback3585C:
    callOwner = moby;
    call6 = 4;
    call7 = 24;
    call5 = scratch.angle;
    MATCHING_KEEP4(callOwner, call6, call7, call5);
    if (func_8003585C(callOwner, call5, call6, call7, 1, 0) != 0)
        goto tail35DDC;
returnZero:
    return 0;
hitAlternate:
    alternate = alternateRecords;
    MATCHING_KEEP(alternate);
    raw3 = Geometry87118Field(alternate, unsigned char**, 12);
    MATCHING_KEEP(raw3);
    raw3 = (unsigned char*)(alternateOffset + (int)raw3);
    temp_v0 = Geometry87118Field(raw3, int*, 12);
    temp_v0 |= 0x8000;
    Geometry87118Field(raw3, int*, 12) = temp_v0;
    func_8004F178((Vector3D*)point4, &moby->position);
    spilledValue = scratch.angle;
    temp_v1 = scratch.endpoint.x;
    MATCHING_KEEP2(spilledValue, temp_v1);
    tableIndex = spilledValue << 1;
    temp_v0 = *(short*)((unsigned char*)D_80065920 + tableIndex);
    call5 = scratch.endpoint.y;
    MATCHING_KEEP4(temp_v0, call5, temp_v1, tableIndex);
    temp_v1 += temp_v0;
    scratch.endpoint.x = temp_v1;
    MATCHING_BARRIER_GNU_VOLATILE("memory");
    temp_v0 = *(short*)((unsigned char*)D_800658A0 + tableIndex);
    alternate = alternateRecords;
    MATCHING_KEEP4(temp_v0, alternate, call5, temp_v1);
    call5 += temp_v0;
    scratch.endpoint.y = call5;
    raw2 = Geometry87118Field(alternate, unsigned char**, 12);
    __asm__ __volatile__("" ::: "$6", "memory");
    call6 = 0;
    MATCHING_KEEP2(raw2, call6);
    raw2 = (unsigned char*)(alternateOffset + (int)raw2);
    point4 = Geometry87118Field(raw2, int*, 0);
    temp_v0 = Geometry87118Field(raw2, int*, 4);
    MATCHING_KEEP4(point4, temp_v0, temp_v1, call5);
    point4 = temp_v1 - point4;
    call5 -= temp_v0;
    temp_v0 = func_8004E880(point4, call5, call6);
    call9 = scratch.radius;
    MATCHING_KEEP(call9);
    call6 = maskedWord - call9;
    MATCHING_KEEP(call6);
    alternate = alternateRecords;
    call7 = temp_v0;
    call5 = (int)Geometry87118Field(alternate, unsigned char**, 12);
    call9 = scratch.radius;
    callOwner = moby;
    return Geometry87118Callback(callOwner, (unsigned char*)(call5 + alternateOffset), call6, call7,
                                 8, call9, 4, 64, 255, 255, 0, 0, ({
                                     register int final9 __asm__("$9") = helperStack1;
                                     MATCHING_KEEP(final9);
                                     final9;
                                 })) |
           0x4000;
tail35DDC:
    callOwner = moby;
    call9 = helperStack1;
    call5 = scratch.radius;
    call6 = scratch.helperInput;
    call7 = helperStack0;
    MATCHING_KEEP5(call9, call5, call6, call7, callOwner);
    return func_80035DDC(callOwner, call5, call6, call7, call9);
}

typedef struct {
    short packetIndex, selector;
    int x, y, z;
    int nextX, nextY, nextZ;
} DecodedPackedPosition;
extern int D_8006C77C;
extern DecodedPackedPosition* D_8006C724;
extern unsigned int** D_8006D048;
void func_level_22_80092494(int selectorArg, Vector3D* positionArg) {
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

void DecodedPolygonSubtract(void*, void*, void*) __asm__("func_8004F1C8");
int DecodedPolygonLength(void*, int) __asm__("func_8004EDE8");
/* Original polygon record: byte count, signed halfword bound, 28-byte entries. */
int func_level_22_800925C8(unsigned char* polygonArg, Vector3D* positionArg) {
    register unsigned char* polygon __asm__("$19") = polygonArg;
    register Vector3D* position __asm__("$23") = positionArg;
    int sides[2];
    Vector3D delta;
    register int nearest __asm__("$21");
    int minimum;
    int reservedStack[2];
    register int index __asm__("$17");
    register int offset __asm__("$18");
    int distance, neighbor, countMinusOne, sum, limit;
    register unsigned char* nearestEntry __asm__("$2");
    register int count __asm__("$4");
    register unsigned char* entry __asm__("$16");
    register Vector3D* work __asm__("$20");
    __asm__("" : "=r"(polygon) : "0"(polygon), "r"(position) : "$22");
    minimum = 0xFFFFFF;
    entry = (unsigned char*)&delta;
    DecodedPolygonSubtract(entry, position, polygon + 4);
    distance = DecodedPolygonLength(entry, 0);
    if (*(short*)(polygon + 2) < distance)
        goto outside;
    nearest = -1;
    limit = polygon[1];
    MATCHING_KEEP(limit);
    index = 0;
    if (limit > 0) {
        work = (Vector3D*)entry;
        offset = 12;
        do {
            entry = polygon + offset;
            DecodedPolygonSubtract(work, position, entry + 8);
            distance = DecodedPolygonLength(work, 0);
            if (nearest < 0 || distance < minimum) {
                nearest = index;
                minimum = distance;
            }
            limit = polygon[1];
            MATCHING_KEEP(limit);
            index++;
            offset += 28;
        } while (index < limit);
    }
    for (index = 0; index < 2; index++) {
        count = polygon[1];
        MATCHING_KEEP_VOLATILE_CLOBBER(index, "memory");
        sum = nearest + index;

        countMinusOne = count - 1;
        neighbor = (sum + countMinusOne) % count;
        neighbor = neighbor * 28 + 12;
        MATCHING_KEEP(neighbor);
        entry = polygon + neighbor;
        DecodedPolygonSubtract(&delta, position, entry + 8);
        sides[index] = delta.x * *(int*)(entry + 16) + delta.y * *(int*)(entry + 20);
    }
    neighbor = polygon[1] - 1;
    MATCHING_KEEP(neighbor);
    index = (nearest + neighbor) % polygon[1];
    MATCHING_KEEP(index);
    neighbor = index * 28 + 12;
    MATCHING_KEEP(neighbor);
    entry = polygon + neighbor;
    MATCHING_KEEP(entry);
    neighbor = nearest * 28;
    MATCHING_KEEP(neighbor);
    /* Empty constraints retain the original address computation and registers. */
    nearestEntry = polygon + neighbor;
    MATCHING_KEEP(nearestEntry);
    if (*(int*)(nearestEntry + 12) * *(int*)(entry + 16) +
            *(int*)(nearestEntry + 16) * *(int*)(entry + 20) >=
        0) {
        if (sides[0] < 0)
            return 0;
        __asm__ volatile("" : :);
    } else {
        if (sides[0] >= 0)
            return 1;
    }
    if (sides[1] >= 0)
        return 1;
outside:
    return 0;
}

void func_8004F6C4(Vector3D16*, SHORTMATRIX*, SHORTMATRIX*);
void func_8004ECF4(SHORTMATRIX*, SHORTMATRIX*);
void func_8005F35C(SHORTMATRIX*, SHORTMATRIX*, SHORTMATRIX*);
void func_8004E56C(Angle12*, SHORTMATRIX*);
void func_level_22_8009284C(Moby* moby, int roll, int pitch, int yaw) {
    Vector3D16 angle;
    SHORTMATRIX first, second, result;
    Angle12 output;
    angle.x = moby->angle.roll << 4;
    angle.y = -(moby->angle.pitch << 4);
    angle.z = moby->angle.yaw << 4;
    func_8004F6C4(&angle, &first, &second);
    func_8004ECF4(&first, &first);
    angle.x = roll << 4;
    angle.y = pitch << 4;
    angle.z = yaw << 4;
    func_8004F6C4(&angle, &second, &result);
    func_8004ECF4(&second, &second);
    func_8005F35C(&first, &second, &result);
    func_8004E56C(&output, &result);
    moby->angle.roll = output.roll >> 4;
    moby->angle.pitch = output.pitch >> 4;
    moby->angle.yaw = output.yaw >> 4;
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Two originals each contain 432 instructions and no owned rodata.
 * Preserve the full-word selector, 40-byte frame, three-word axis loop,
 * byte scan order, 32-byte wrap, post-store rereads and halfword paths.
 * Register suffixes identify original producer lifetimes, not units.
 * The incoming argument6 is reused as a copy cursor after its last test;
 * register7 first holds the selector, then original byte/word addresses.
 * Empty compiler constraints emit no instructions. Buffer meanings,
 * caller cadence and synchronized retail runtime interpretation remain
 * unresolved. Acceptance requires every linked original word and hash.
 */
#define Leaf87A04Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int Leaf87A04Tick __asm__("D_8006C648");
void func_level_22_8009297C(int incomingSelector, void* buffer, int forceOrCopyCursor6) {
    struct {
        int reserved[10];
    } originalFrame;
    register void* buffer5 __asm__("5");
    int oldRingIndex;
    int pendingWord84;
    int acceptedWord84;
    int nextRingIndex;
    register int ringCursor4 __asm__("4");
    int copyIndex6;
    int recomputeIndex6;
    int finalCopyIndex6;
    int copyIndex7;
    register int axisIndex8 __asm__("8");
    register int matchedBytes8 __asm__("8");
    register int axisChanged9 __asm__("9");
    register int patternLength9 __asm__("9");
    register int patternOffset10 __asm__("10");
    register int accumulatedWord12 __asm__("12");
    register int workWord2 __asm__("2");
    int ringDivisionWord;
    register int workWord3 __asm__("3");
    register int workWord4 __asm__("4");
    unsigned short timerHalfword8E;
    unsigned short settleHalfword8E;
    register unsigned char* ringAddress7 __asm__("7");
    void* selectedAddress4;
    register void* patternBase11 __asm__("11");
    register void* patternScan3 __asm__("3");
    void* byteAddress3;
    void* shiftEntry3;
    void* finalByteAddress3;
    register void* copyAddress4 __asm__("4");
    register void* finalCopyAddress4 __asm__("4");
    register void* selectorOrAxis7 __asm__("7");
    void* wordAddress7;
    register int clamp8 __asm__("8");

    buffer5 = buffer;
    MATCHING_KEEP(buffer5);
    selectorOrAxis7 = (void*)incomingSelector;
    MATCHING_KEEP(selectorOrAxis7);
    __asm__("" : : "m"(originalFrame));
    accumulatedWord12 = 0;
    if (Leaf87A04Field(buffer5, int*, 0x28) != 0) {
        if ((int)selectorOrAxis7 >= 0x30) {
            workWord2 = Leaf87A04Field(buffer5, int*, 0x24);
            workWord2 = (int)buffer5 + workWord2;
            Leaf87A04Field((void*)workWord2, unsigned char*, 0x38) = 0;
            return;
        }
        if ((int)selectorOrAxis7 != 0) {
            workWord2 = (int)selectorOrAxis7 * 2;
            workWord3 = Leaf87A04Field(buffer5, int*, 0xA0);
            workWord2 += workWord3;
            MATCHING_KEEP_CLOBBER(workWord2, "memory");
            workWord3 = *(short*)workWord2;
            workWord2 = (int)buffer5 + (int)selectorOrAxis7;
            workWord4 = Leaf87A04Field((void*)workWord2, unsigned char*, 0xA8);
            workWord2 = Leaf87A04Field(buffer5, int*, 0x24);
            workWord3 >>= workWord4;
            workWord2 *= 2;
            workWord2 += (int)buffer5;
            Leaf87A04Field((void*)workWord2, short*, 0x48) = workWord3;
            workWord2 = Leaf87A04Field(buffer5, int*, 0x24);
            workWord3 = workWord2 + 1;
            workWord2 = (int)buffer5 + workWord2;
            Leaf87A04Field(buffer5, int*, 0x24) = workWord3;
            Leaf87A04Field((void*)workWord2, unsigned char*, 0x38) = (int)selectorOrAxis7;
        }
        axisChanged9 = 0;
        workWord4 = 0;
        axisIndex8 = 0;
        selectorOrAxis7 = buffer5 + 0x90;
        do {
            selectorOrAxis7 = selectorOrAxis7 + (axisIndex8 * 4);
            workWord3 = *(int*)selectorOrAxis7;
            if (axisIndex8 == 1)
                goto axis1;
            if (axisIndex8 < 2) {
                if (axisIndex8 == 0)
                    goto axis0;
                axisIndex8 += 1;
                goto axisLoopEnd;
            }
            if (axisIndex8 == 2)
                goto axis2;
            axisIndex8 += 1;
            goto axisLoopEnd;
        axis0:
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            if (workWord2 < 0x601)
                goto axisNext;
            workWord4 = workWord3;
            workWord3 *= 2;
            axisChanged9 = 1;
            if (workWord3 >= 0x801)
                workWord3 = 0x800;
            workWord2 = workWord3 < -0x800;
            if (workWord2) {
                workWord3 = -0x800;
                MATCHING_KEEP(workWord3);
            }
            workWord2 = workWord4 - workWord3;
            *(int*)selectorOrAxis7 = workWord2;
            workWord4 = 4;
            if (workWord3 < 0)
                workWord4 = 3;
            workWord2 = Leaf87A04Field(buffer5, int*, 0x2C);
            if (workWord2 != 0)
                workWord4 += 6;
            Leaf87A04Field(buffer5, int*, 0x2C) = workWord2 == 0;
            goto axisNext;
        axis1:
            MATCHING_KEEP(axisIndex8);
            if (workWord3 < 0)
                workWord3 -= 0x200;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            if (workWord2 < 0x601) {
                workWord3 *= 2;
                goto axisNext;
            }
            workWord3 *= 2;
            axisChanged9 = 1;
            if (workWord3 >= 0x801)
                workWord3 = 0x800;
            if (workWord3 < -0x800)
                workWord3 = -0x800;
            workWord2 = *(int*)selectorOrAxis7;
            workWord4 = 1;
            workWord2 -= workWord3;
            *(int*)selectorOrAxis7 = workWord2;
            if (workWord3 > 0)
                workWord4 = 2;
            workWord2 = Leaf87A04Field(buffer5, int*, 0x30);
            if (workWord2 != 0)
                workWord4 += 6;
            Leaf87A04Field(buffer5, int*, 0x30) = workWord2 == 0;
            goto axisNext;
        axis2:
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            if (workWord2 < 0x601)
                goto axisNext;
            workWord4 = workWord3;
            workWord3 *= 2;
            axisChanged9 = 1;
            if (workWord3 >= 0x801)
                workWord3 = 0x800;
            workWord2 = workWord3 < -0x800;
            if (workWord2) {
                workWord3 = -0x800;
                MATCHING_KEEP(workWord3);
            }
            workWord2 = workWord4 - workWord3;
            *(int*)selectorOrAxis7 = workWord2;
            workWord4 = 6;
            if (workWord3 > 0)
                workWord4 = 5;
            workWord2 = Leaf87A04Field(buffer5, int*, 0x34);
            if (workWord2 != 0)
                workWord4 += 6;
            Leaf87A04Field(buffer5, int*, 0x34) = workWord2 == 0;
        axisNext:
            axisIndex8 += 1;
        axisLoopEnd:
            selectorOrAxis7 = buffer5 + 0x90;
        } while (axisIndex8 < 3);
        if (axisChanged9 != 0) {
            Leaf87A04Field(buffer5 + Leaf87A04Field(buffer5, int*, 0x20), unsigned char*, 0) =
                workWord4;
            oldRingIndex = Leaf87A04Field(buffer5, int*, 0x20);
            nextRingIndex = oldRingIndex + 1;
            ringDivisionWord = nextRingIndex;
            if (nextRingIndex < 0) {
                ringDivisionWord = oldRingIndex + 0x20;
            }
            Leaf87A04Field(buffer5, int*, 0x20) =
                (int)(nextRingIndex - ((ringDivisionWord >> 5) << 5));
            patternOffset10 = 0;
        nextPatternScan:
            workWord2 = Leaf87A04Field(buffer5, int*, 0xA4);
            patternScan3 = (void*)(patternOffset10 + workWord2);
            patternLength9 = 0;
            if (Leaf87A04Field(patternScan3, unsigned char*, 1) != 0) {
                MATCHING_KEEP(patternLength9);
                patternLength9 += 1;
                do {
                    workWord2 = Leaf87A04Field((void*)(patternLength9 + (int)patternScan3),
                                               unsigned char*, 1);
                    patternLength9 += 1;
                } while (workWord2 != 0);
                patternLength9 -= 1;
            }
            workWord2 = Leaf87A04Field(buffer5, int*, 0x20);
            ringCursor4 = workWord2 - patternLength9;
            if (ringCursor4 < 0) {
                ringCursor4 += 0x20;
            }
            matchedBytes8 = 0;
            if (patternLength9 > 0) {
                workWord2 = Leaf87A04Field(buffer5, int*, 0xA4);
                ringAddress7 = (void*)(ringCursor4 + (int)buffer5);
                patternBase11 = (void*)(patternOffset10 + workWord2);
                MATCHING_KEEP(matchedBytes8);
                workWord2 = matchedBytes8 + (int)patternBase11;
            comparePatternBytes:
                workWord3 = *ringAddress7;
                workWord2 = Leaf87A04Field((void*)workWord2, unsigned char*, 1);
                ringCursor4 += 1;
                if (workWord3 != workWord2)
                    goto comparisonMismatch;
                ringAddress7 += 1;
                if (ringCursor4 >= 0x20) {
                    ringAddress7 -= 0x20;
                    ringCursor4 -= 0x20;
                }
                matchedBytes8 += 1;
                if (matchedBytes8 < patternLength9) {
                    workWord2 = matchedBytes8 + (int)patternBase11;
                    goto comparePatternBytes;
                }
            }
        comparisonDone:
            if (matchedBytes8 != patternLength9)
                goto nextPattern;
            workWord2 = Leaf87A04Field(buffer5, int*, 0xA4);
            workWord3 = Leaf87A04Field(buffer5, int*, 0x24);
            workWord2 = patternOffset10 + workWord2;
            MATCHING_KEEP(workWord2);
            workWord4 = Leaf87A04Field((void*)workWord2, unsigned char*, 0);
            workWord2 = workWord3 + 1;
            workWord3 = (int)buffer5 + workWord3;
            Leaf87A04Field(buffer5, int*, 0x24) = workWord2;
            Leaf87A04Field((void*)workWord3, unsigned char*, 0x38) = workWord4;
            goto scanResult;
        comparisonMismatch:
            matchedBytes8 = -1;
            goto comparisonDone;
        nextPattern:
            patternOffset10 += 0x10;
            if (patternOffset10 < 0x400)
                goto nextPatternScan;
        scanResult:
            if ((Leaf87A04Field(buffer5, int*, 0x20) >= 0xA) &&
                (Leaf87A04Field(buffer5, int*, 0x24) == 1) &&
                (Leaf87A04Field(buffer5, unsigned char*, 0x38) == 0x27)) {
                Leaf87A04Field(buffer5, int*, 0x24) = 2;
                Leaf87A04Field(buffer5, signed char*, 0x39) = 0x2B;
                goto reloadTerminator;
            }
            if (Leaf87A04Field(buffer5, int*, 0x20) >= 5) {
                workWord2 = Leaf87A04Field(buffer5, int*, 0x24);
                if (workWord2 != 0) {
                    workWord2 = (int)buffer5 + workWord2;
                    goto terminateSelector;
                }
                Leaf87A04Field(buffer5, int*, 0x24) = 1;
                Leaf87A04Field(buffer5, unsigned char*, 0x38) = 0x27;
            }
        }
    reloadTerminator:
        workWord2 = Leaf87A04Field(buffer5, int*, 0x24);
        workWord2 = (int)buffer5 + workWord2;
    terminateSelector:
        MATCHING_KEEP(workWord2);
        Leaf87A04Field((void*)workWord2, unsigned char*, 0x38) = 0;
        if (Leaf87A04Field(buffer5, int*, 0x84) != 0) {
            if (Leaf87A04Field(buffer5, short*, 0x8C) == 0) {
                copyIndex6 = 0;
                if (Leaf87A04Field(buffer5, int*, 0x24) > 0) {
                    copyAddress4 = buffer5;
                    MATCHING_KEEP(copyAddress4);
                    do {
                        byteAddress3 = buffer5 + copyIndex6;
                        Leaf87A04Field(byteAddress3, unsigned char*, 0x68) =
                            (unsigned char)Leaf87A04Field(byteAddress3, unsigned char*, 0x38);
                        copyIndex6 += 1;
                        Leaf87A04Field(copyAddress4, unsigned short*, 0x70) =
                            (unsigned short)Leaf87A04Field(copyAddress4, unsigned short*, 0x48);
                        copyAddress4 += 2;
                    } while (copyIndex6 < Leaf87A04Field(buffer5, int*, 0x24));
                }
                Leaf87A04Field((buffer5 + Leaf87A04Field(buffer5, int*, 0x24)), signed char*,
                               0x68) = 0;
                pendingWord84 = Leaf87A04Field(buffer5, int*, 0x84);
                Leaf87A04Field(buffer5, int*, 0x24) = 0;
                Leaf87A04Field(buffer5, int*, 0x84) = 0;
                Leaf87A04Field(buffer5, unsigned short*, 0x8E) = 0U;
                Leaf87A04Field(buffer5, int*, 0x88) = (int)-pendingWord84;
                return;
            }
            timerHalfword8E = Leaf87A04Field(buffer5, unsigned short*, 0x8E) + Leaf87A04Tick;
            Leaf87A04Field(buffer5, unsigned short*, 0x8E) = timerHalfword8E;
            copyIndex7 = 0;
            if (((short)timerHalfword8E >= 0x1E) || (forceOrCopyCursor6 != 0)) {
                Leaf87A04Field(buffer5, int*, 0x80) = (int)(Leaf87A04Field(buffer5, int*, 0x80) +
                                                            Leaf87A04Field(buffer5, int*, 0x84));
                if (Leaf87A04Field(buffer5, int*, 0x24) > 0) {
                    clamp8 = 8;
                    MATCHING_KEEP(clamp8);
                    forceOrCopyCursor6 = (int)buffer5;
                    MATCHING_KEEP(forceOrCopyCursor6);
                    do {
                        selectedAddress4 = buffer5 + copyIndex7;
                        workWord3 = Leaf87A04Field(selectedAddress4, unsigned char*, 0x38);
                        MATCHING_KEEP(workWord3);
                        workWord3 = (int)buffer5 + workWord3;
                        Leaf87A04Field((void*)workWord3, unsigned char*, 0xA8) =
                            Leaf87A04Field((void*)workWord3, unsigned char*, 0xA8) + 1;
                        shiftEntry3 =
                            buffer5 + Leaf87A04Field(selectedAddress4, unsigned char*, 0x38);
                        if ((unsigned char)Leaf87A04Field(shiftEntry3, unsigned char*, 0xA8) >=
                            9U) {
                            Leaf87A04Field(shiftEntry3, unsigned char*, 0xA8) = clamp8;
                        }
                        Leaf87A04Field(selectedAddress4, unsigned char*, 0x68) =
                            (unsigned char)Leaf87A04Field(selectedAddress4, unsigned char*, 0x38);
                        copyIndex7 += 1;
                        MATCHING_KEEP(forceOrCopyCursor6);
                        Leaf87A04Field((void*)forceOrCopyCursor6, unsigned short*, 0x70) =
                            (unsigned short)Leaf87A04Field((void*)forceOrCopyCursor6,
                                                           unsigned short*, 0x48);
                        forceOrCopyCursor6 += 2;
                    } while (copyIndex7 < Leaf87A04Field(buffer5, int*, 0x24));
                }
                Leaf87A04Field((buffer5 + Leaf87A04Field(buffer5, int*, 0x24)), signed char*,
                               0x68) = 0;
                acceptedWord84 = Leaf87A04Field(buffer5, int*, 0x84);
                Leaf87A04Field(buffer5, int*, 0x84) = 0;
                Leaf87A04Field(buffer5, unsigned short*, 0x8E) = 0U;
                Leaf87A04Field(buffer5, int*, 0x24) = 0;
                Leaf87A04Field(buffer5, int*, 0x88) = acceptedWord84;
            }
        } else {
            if (Leaf87A04Field(buffer5, int*, 0x88) != 0) {
                settleHalfword8E = Leaf87A04Field(buffer5, unsigned short*, 0x8E) + Leaf87A04Tick;
                Leaf87A04Field(buffer5, unsigned short*, 0x8E) = settleHalfword8E;
                if ((short)settleHalfword8E >= 0x78) {
                    Leaf87A04Field(buffer5, int*, 0x88) = 0;
                    Leaf87A04Field(buffer5, unsigned short*, 0x8E) = 0U;
                }
            }
            recomputeIndex6 = 0;
            if (Leaf87A04Field(buffer5, int*, 0x24) > 0) {
                wordAddress7 = buffer5;
                do {
                    workWord2 = (int)buffer5 + recomputeIndex6;
                    workWord3 = Leaf87A04Field((void*)workWord2, unsigned char*, 0x38);
                    workWord4 = Leaf87A04Field(buffer5, int*, 0xA0);
                    workWord2 = workWord3 * 2;
                    workWord2 += workWord4;
                    MATCHING_KEEP2(workWord2, workWord3);
                    workWord3 = (int)buffer5 + workWord3;
                    workWord2 = *(short*)workWord2;
                    workWord3 = Leaf87A04Field((void*)workWord3, unsigned char*, 0xA8);
                    recomputeIndex6 += 1;
                    workWord2 >>= workWord3;
                    accumulatedWord12 += workWord2;
                    Leaf87A04Field(wordAddress7, short*, 0x48) = workWord2;
                    wordAddress7 += 2;
                } while (recomputeIndex6 < Leaf87A04Field(buffer5, int*, 0x24));
            }
            if (Leaf87A04Field(buffer5, short*, 0x8C) == 1 && accumulatedWord12 != 0) {
                Leaf87A04Field(buffer5, int*, 0x88) = 0;
                Leaf87A04Field(buffer5, unsigned short*, 0x8E) = 0U;
                Leaf87A04Field(buffer5, int*, 0x84) = accumulatedWord12;
                return;
            }
            if (Leaf87A04Field(buffer5, short*, 0x8C) == 0) {
                if (accumulatedWord12 != 0) {
                    finalCopyIndex6 = 0;
                    if (Leaf87A04Field(buffer5, int*, 0x24) > 0) {
                        finalCopyAddress4 = buffer5;
                        MATCHING_KEEP(finalCopyAddress4);
                        do {
                            finalByteAddress3 = buffer5 + finalCopyIndex6;
                            Leaf87A04Field(finalByteAddress3, unsigned char*, 0x68) =
                                (unsigned char)Leaf87A04Field(finalByteAddress3, unsigned char*,
                                                              0x38);
                            finalCopyIndex6 += 1;
                            Leaf87A04Field(finalCopyAddress4, unsigned short*, 0x70) =
                                (unsigned short)Leaf87A04Field(finalCopyAddress4, unsigned short*,
                                                               0x48);
                            finalCopyAddress4 += 2;
                        } while (finalCopyIndex6 < Leaf87A04Field(buffer5, int*, 0x24));
                    }
                    Leaf87A04Field((buffer5 + Leaf87A04Field(buffer5, int*, 0x24)), signed char*,
                                   0x68) = 0;
                    MATCHING_KEEP_CLOBBER(accumulatedWord12, "memory");
                    workWord2 = -accumulatedWord12;
                    MATCHING_KEEP(workWord2);
                    Leaf87A04Field(buffer5, int*, 0x88) = workWord2;
                    Leaf87A04Field(buffer5, unsigned short*, 0x8E) = 0U;
                }
                Leaf87A04Field(buffer5, int*, 0x24) = 0;
            }
        }
    }
}

#undef Leaf87A04Field


extern void (*DecodedRecordInit)(void*) asm("unk_ovlheader_80074444");
void func_level_22_8009303C(DecodedOverlayRecord* record) {
    register int index asm("$2");
    record->unk80 = 0;
    record->unk84 = 0;
    record->unk88 = 0;
    record->unk8E = 0;
    DecodedRecordInit(record);
    index = 0x2F;
    /* Non-emitting constraint preserves the retail pointer/count ordering. */
    MATCHING_KEEP2_VOLATILE(index, record);
    {
        unsigned char* bytes = (unsigned char*)record + 0x2F;
        do {
            bytes[0xA8] = 0;
            index--;
            bytes--;
        } while (index >= 0);
    }
}

extern void (*DecodedRecordReset)(int, void*, int) asm("unk_ovlheader_8007443C");
void func_level_22_80093094(DecodedOverlayRecord* record) {
    if (record->unk28 != 0) {
        DecodedRecordReset(0, record, 1);
        record->unk90 = 0;
        record->unk94 = 0;
        record->unk98 = 0;
        record->unk2C = 0;
        record->unk30 = 0;
        record->unk34 = 0;
        record->unk20 = 0;
        record->unk24 = 0;
        record->unk38 = 0;
        record->unk48 = 0;
    }
}

void func_level_22_80093108(HudEntry* hud) {
    SpriteDefinition* definition = &D_8006C738[hud->unk1C.index];
    int* record = hud->unk28;
    if (record) {
        hud->unk42 = record[0x20];
        if (hud->unk26 < hud->unk42)
            hud->unk42 = hud->unk26;
        hud->unk40 = hud->unk42;
    } else {
        hud->unk42 = 0x63;
        hud->unk40 = 0x63;
    }
    hud->unk44 = 0xB4;
    if (hud->unk24 != -1) {
        SpriteData* sprite = &D_8006C788[(unsigned char)definition->frame];
        hud->unk3D = sprite->unk5 - sprite->unk1;
    } else {
        hud->unk3D = 0;
    }
    hud->unk3C = 0xE6;
    hud->unk4C = 0;
    hud->unk50 = 0;
}

/* AI generated; not human reviewed. Partial layout from retail access widths. */
typedef struct {
    unsigned char reserved00[0x24];
    int count24;
    unsigned char reserved28[0x10];
    unsigned char indices38[16];
    short values48[16];
    unsigned char indices68[8];
    short values70[8];
    unsigned char reserved80[8];
    int value88;
    unsigned char reserved8C[0x10];
    char** strings9C;
} Decoded155Record;
extern char D_level_22_80074B70[];
extern int sprintf(char*, const char*, ...);
int func_level_22_800931B8(HudEntry* hud) {
    char buffer[16];
    int x, y;
    int i, colour;
    Decoded155Record* record = (Decoded155Record*)hud->unk28;
    x = hud->unk0;
    y = hud->unk2;
    func_80029674(hud, &x, &y);
    y -= 4;
    if (record->value88) {
        for (i = 0; record->indices68[i] && i < 8; i++) {
        }
        colour = 11;
        y -= i * 14;
        if (record->value88 > 0)
            colour = 1;
        for (i = 0; record->indices68[i] && i < 8; i++) {
            func_8002E748(record->strings9C[record->indices68[i]], x, y, colour, 0);
            sprintf(buffer, D_level_22_80074B70, record->values70[i]);
            func_8002E748(buffer, x + 180, y, colour, 0);
            y += 14;
        }
        {
            register int value __asm__("$6") = record->value88;
            register char* format __asm__("$5") = D_level_22_80074B70;
            MATCHING_KEEP2(value, format);
            if (value < 0)
                value = -value;
            sprintf(buffer, format, value);
        }
        func_8002E748(buffer, x + 180, y, colour, 0);
    } else {
        y -= record->count24 * 14;
        for (i = 0; i < record->count24; i++) {
            func_8002E748(record->strings9C[record->indices38[i]], x, y, 0, 0);
            sprintf(buffer, D_level_22_80074B70, record->values48[i]);
            func_8002E748(buffer, x + 180, y, 0, 0);
            y += 14;
        }
    }
    func_80029904(hud);
    return hud->unk3C;
}

/* Unsigned HUD values; elapsed comparisons use the stored signed low halfword. */
extern int D_8006C648;
void func_level_22_80093424(HudEntry* hud) {
    int elapsed, difference, step;
    if (hud->unk28)
        hud->unk42 = hud->unk28[0x20];
    if (hud->unk40 == hud->unk42)
        return;
    {
        int cadence = D_8006C648;
        hud->unk44 = 180;
        elapsed = *(unsigned short*)&hud->unk46 + cadence;
    }
    hud->unk46 = elapsed;
    if (hud->movementFrame)
        return;
    {
        int rawDifference = hud->unk40 - hud->unk42;
        /* Keep the original subtract then negate path; no emitted assembly. */
        MATCHING_KEEP(rawDifference);
        difference = ABS(rawDifference);
    }
    if (difference < 40) {
        if (difference >= 10 && (short)elapsed >= 4)
            goto update;
        if ((short)elapsed < 6)
            return;
    }
update:
    if (difference >= 640)
        step = 7;
    else if (difference >= 320)
        step = 6;
    else if (difference >= 160)
        step = 5;
    else if (difference >= 80)
        step = 4;
    else if (difference >= 40)
        step = 3;
    else
        step = 1;
    if (hud->unk40 > hud->unk42)
        hud->unk40 -= step;
    else
        hud->unk40 += step;
    hud->unk46 = 0;
}

void func_8003BEDC(int);
extern int D_8006E344, D_8006FA70, D_8006FBC4, D_8006FBD4, D_8006FBD0, D_8006FBC8;
void func_level_22_80093544(int value) {
    int* flags;
    int bits;
    func_8003BEDC(value);

    flags = &spyro.unk17a;
    D_8006E344 = 0x12;
    D_8006FA70 = value;
    D_8006FBC4 = 0;
    D_8006FBD4 = 0;
    MATCHING_BARRIER_VOLATILE("memory");
    bits = *flags;
    D_8006FBD0 = 1;
    D_8006FBC8 = 0;
    *flags = bits | 2;
}

extern int D_800718D0, D_8006FA70, D_8006E344;
void func_level_22_800935B8(void) {
    int* bound = &D_800718D0;
    if (D_8006FA70 > *bound)
        *bound = D_8006FA70;
    D_8006E344 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_22/level", D_level_22_80074B70);

/* AI generated; not human reviewed. SCUS-94467 level11 80088678 numeric state route. */
extern int D_8006FBC4, D_8006FBC8, D_8006FBD4, D_8006E53C, D_8006C648;
extern void (*Decoded153Callback)(void) __asm__("unk_ovlheader_80074480");
void func_level_22_800935F0(void) {
    spyro.unk17a |= 0x10000002;
    switch (D_8006FBC8) {
        case 0:
            if (D_8006E53C & 0x840)
                D_8006FBD4 = 1;
            {
                register int* timer __asm__("$4") = &D_8006FBC4;
                MATCHING_KEEP(timer);
                *timer += D_8006C648;
                if (*timer >= 30 || D_8006FBD4 != 0) {
                    *timer = 0;
                    D_8006FBC8 = 1;
                }
            }
            break;
        case 1:
            if (D_8006E53C & 0x840)
                D_8006FBD4 = 1;
            {
                register int* timer __asm__("$4") = &D_8006FBC4;
                MATCHING_KEEP(timer);
                *timer += D_8006C648;
                if (*timer >= 30 || D_8006FBD4 != 0) {
                    *timer = 0;
                    D_8006FBC8 = 2;
                }
            }
            break;
        case 2:
            if (D_8006E53C & 0x840)
                D_8006FBD4 = 1;
            {
                register int* timer __asm__("$4") = &D_8006FBC4;
                MATCHING_KEEP(timer);
                *timer += D_8006C648;
                if (*timer >= 30 || D_8006FBD4 != 0) {
                    *timer = 0;
                    D_8006FBC8 = 3;
                }
            }
            break;
        case 3:
            if (D_8006E53C & 0x840)
                D_8006FBD4 = 1;
            {
                register int* timer __asm__("$4") = &D_8006FBC4;
                MATCHING_KEEP(timer);
                *timer += D_8006C648;
                if (*timer >= 30 || D_8006FBD4 != 0) {
                    *timer = 0;
                    D_8006FBC8 = 5;
                }
            }
            break;
        case 5: {
            register int* timer __asm__("$5") = &D_8006FBC4;
            register int value __asm__("$2") = *timer;
            register int delta __asm__("$4") = D_8006C648;
            register int mask __asm__("$3") = D_8006E53C;
            MATCHING_KEEP4(timer, value, delta, mask);
            *timer = value + delta;
            if (mask & 0x840)
                Decoded153Callback();
        } break;
    }
}


/* AI generated; not human reviewed. Retail numeric display routing. */
extern int D_8006FBC8, D_8006FBC4, D_8006FA70, D_8006C76C, D_8006C5BC, D_800718CC, D_800718D0;
extern char* D_8006C450[];
extern char* D_8006C454[];
extern char* D_8006C458[];
extern char* D_8006C45C[];
extern char* D_8006C43C[];
extern char D_level_22_80074B70[];
extern int sprintf(char*, const char*, ...);
void func_level_22_8009383C(void) {
    char first[16], second[16];
    int* state = &D_8006FBC8;
    func_8001FD00(112, 400, 72, 176);
    func_8001FB74(144, 94, 368, 94);
    func_8001FB74(144, 140, 368, 140);
    if (*state > 0) {
        DrawStringCentered(D_8006C450[D_8006C76C], 192, 104, 2);
        func_8002EBB0(D_8006C450[D_8006C76C]);
        sprintf(first, D_level_22_80074B70, D_8006FA70);
        DrawStringCentered(first, 192, 121, 2);
    }
    if (*state >= 2) {
        DrawStringCentered(D_8006C454[D_8006C76C], 320, 104, 2);
        func_8002EBB0(D_8006C454[D_8006C76C]);
        sprintf(second, D_level_22_80074B70, D_8006C5BC == 11 ? D_800718CC : D_800718D0);
        DrawStringCentered(second, 320, 121, 2);
    }
    if (D_8006FBC8 >= 3) {
        if (D_8006FA70 > D_800718D0)
            DrawStringCentered(D_8006C458[D_8006C76C], 256, 80, (D_8006FBC4 & 31) < 22 ? 3 : 2);
        else
            DrawStringCentered(D_8006C45C[D_8006C76C], 256, 80, 2);
    }
    if (D_8006FBC8 == 5)
        DrawStringCentered(D_8006C43C[D_8006C76C], 256, 154, (D_8006FBC4 & 31) < 22 ? 3 : 2);
}
