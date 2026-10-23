#include "matching.h"
#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "spu.h"
#include "hud.h"
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
int func_level_41_80089564(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

void func_level_41_80089880(Moby* moby, int mode) {
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
int func_level_41_800898F8(int inputMask) {
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


/* Only the retail pointer array at +0x3C is described here. */
typedef struct {
    unsigned char reserved00[0x3C];
    unsigned char* frames[1];
} DecodedFrameTable;
extern DecodedFrameTable* D_8006EE2C[];
void func_level_41_80089D7C(Moby* moby, int increment, int* accumulator) {
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

int func_level_41_80089E8C(Vector3D* position, int value, Moby* whirlwind) {
    int previousState = spyro.unk17c == 2;
    spyro.unk17a = 0x10000040;
    spyro.m_WhirlwindPointer = whirlwind;
    func_8004F178(&spyro.unk19, position);
    spyro.unk20[0] = value;
    return previousState;
}

/* Rev0 representative8008E034..8008E2F0,175 original instructions.
 * Reuses the inspected1057 oriented-bounds reconstruction. Fields at C/10/14,
 * signed trig halfwords, low-word products and arithmetic shifts12 follow
 * the original instructions. Physical units, table/angle producers and caller
 * cadence remain unresolved. Empty constraints emit no instructions and retain
 * GCC2.7.2 register lifetimes, access order and native multiply destinations.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct {
    Vector3D position;
    int width, height, angle;
} DecodedOrientedBounds;
typedef struct {
    int local[2];
    int reserved18[2];
    Vector3D delta;
    int reserved2C;
} DecodedBoundsWorkspace;
extern short D_80065920[], D_800658A0[];
void DecodedBoundsSubtract(void*, void*, void*) __asm__("func_8004F1C8");
void DecodedBoundsAdd(void*, void*, void*) __asm__("func_8004F194");
void func_level_41_80089F00(Vector3D* outputArg, Vector3D* position,
                            DecodedOrientedBounds* boundsArg, int marginArg) {
    DecodedBoundsWorkspace work;
    register DecodedOrientedBounds* bounds __asm__("$18");
    register int margin __asm__("$19");
    register int incomingMargin __asm__("$7") = marginArg;
    register Vector3D* output __asm__("$20");
    register int magnitude __asm__("$3");
    register int sourceWidth __asm__("$2");
    int width;
    int height;
    register int distanceX __asm__("$2");
    register int x __asm__("$6");
    register int y __asm__("$4");
    register int distanceY __asm__("$3");
    MATCHING_BARRIER("$20");
    bounds = boundsArg;
    MATCHING_KEEP2(bounds, incomingMargin);
    margin = incomingMargin;
    MATCHING_KEEP(margin);
    magnitude = margin;
    sourceWidth = bounds->width;
    if (margin < 0)
        magnitude = -magnitude;
    MATCHING_KEEP(magnitude);
    width = sourceWidth - magnitude;
    output = outputArg;
    if (width < 0)
        width = 0;
    height = bounds->height - magnitude;
    if (height < 0)
        height = 0;
    {
        register void* deltaArgument __asm__("$4") = &work.delta;
        MATCHING_KEEP(deltaArgument);
        DecodedBoundsSubtract(deltaArgument, position, bounds);
    }
    MATCHING_OBSERVE_VOLATILE(margin);
    /* Transform the helper output into the two raw local coordinates. */
    {
        register int firstProduct __asm__("$3") = work.delta.x * D_80065920[bounds->angle];
        register int secondProduct __asm__("$2") = work.delta.y * D_800658A0[bounds->angle];
        MATCHING_KEEP2(firstProduct, secondProduct);
        x = (firstProduct - secondProduct) >> 12;
    }
    work.local[0] = x;
    {
        register int firstProduct __asm__("$3") = work.delta.x * D_800658A0[bounds->angle];
        register int secondProduct __asm__("$2") = work.delta.y * D_80065920[bounds->angle];
        MATCHING_KEEP2(firstProduct, secondProduct);
        y = (firstProduct + secondProduct) >> 12;
        MATCHING_KEEP(y);
    }
    work.local[1] = y;
    /* Preserve the retail signed-margin branches and independent clamps. */
    if (margin >= 0) {
        {
            register int lower __asm__("$3") = -width;
            register int condition __asm__("$2") = x < lower;
            MATCHING_KEEP(condition);
            if (condition)
                work.local[0] = lower;
        }
        if (work.local[0] > width)
            work.local[0] = width;
        {
            register int lower __asm__("$3") = -height;
            register int condition __asm__("$2") = y < lower;
            MATCHING_KEEP(condition);
            if (condition)
                work.local[1] = lower;
        }
        if (work.local[1] > height)
            work.local[1] = height;
    } else {
        register int absolute __asm__("$2");
        absolute = x;
        if (x < 0)
            absolute = -absolute;
        if (absolute < width) {
            absolute = y;
            if (y < 0)
                absolute = -absolute;
            if (absolute < height) {
                if (x < 0)
                    distanceX = x + width;
                else
                    distanceX = width - x;
                MATCHING_KEEP(distanceX);
                distanceY = work.local[1];
                if (distanceY < 0)
                    distanceY += height;
                else
                    distanceY = height - distanceY;
                MATCHING_KEEP(distanceY);
                if (distanceX < distanceY) {
                    if (work.local[0] < 0)
                        work.local[0] = -width;
                    else
                        work.local[0] = width;
                } else {
                    if (work.local[1] < 0)
                        work.local[1] = -height;
                    else
                        work.local[1] = height;
                }
            }
        }
    }
    /* Transform the selected local coordinates back through the same tables. */
    {
        register int localX __asm__("$4") = work.local[0];
        register int localY __asm__("$5") = work.local[1];
        register int firstProduct __asm__("$3") = localX * D_80065920[bounds->angle];
        register int secondProduct __asm__("$2") = localY * D_800658A0[bounds->angle];
        MATCHING_KEEP2(firstProduct, secondProduct);
        work.delta.x = (firstProduct + secondProduct) >> 12;
        firstProduct = -localX * D_800658A0[bounds->angle];
        secondProduct = localY * D_80065920[bounds->angle];
        MATCHING_KEEP2(firstProduct, secondProduct);
        work.delta.y = (firstProduct + secondProduct) >> 12;
    }
    DecodedBoundsAdd(output, &work.delta, bounds);
}

/* Private list header: signed count/argument, then 24-byte query records. */
typedef struct {
    int count, argument;
    unsigned char bounds[1][24];
} DecodedClosestList;
typedef struct {
    char reserved00[0x4C];
    Moby* actor;
    int reserved50;
    DecodedClosestList* list;
    DecodedClosestList* boundsList;
    int boundCount;
} DecodedClosestTag;
typedef struct {
    Vector3D value;
    int reserved0C;
} DecodedClosestSlot;
extern Moby* DecodedClosestPlayer __asm__("D_80070328 + 0x250");
extern char DecodedClosestPlayerData[] __asm__("D_80070328");
extern void (*DecodedClosestQuery)(Vector3D*, Vector3D*, void*,
                                   int) __asm__("unk_ovlheader_80074340");
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
int DecodedClosestBounds(Vector3D*, void*, int, int) __asm__("func_80036220");
void func_level_41_8008A1BC(void) {
    /* Original 16-byte stack slots at sp+0x10, +0x20 and +0x30. */
    DecodedClosestSlot slots[3];
    int reservedStack[2];
    DecodedClosestTag* tag = DecodedClosestPlayer->mobyTag;
    Vector3D* direction;
    register Vector3D* vectorArgument __asm__("$4");
    DecodedClosestList* list;
    DecodedClosestList* boundsList;
    int boundCount;
    int index, byteOffset, hit, distance, minimum;
    if (!tag->actor)
        return;
    direction = (Vector3D*)(DecodedClosestPlayerData + 0xCC);
    func_8004F178(&slots[0].value, direction);
    func_8004EF04(&slots[0].value, 4096);
    MATCHING_KEEP(direction);
    /* Original low-32-bit products/sum and arithmetic right shift by 12. */
    distance = ((*(int*)((char*)direction - 0x58) * slots[0].value.x +
                 *(int*)(DecodedClosestPlayerData + 0x78) * slots[0].value.y) +
                *(int*)(DecodedClosestPlayerData + 0x7C) * slots[0].value.z) >>
               12;
    func_8004F08C(&slots[0].value, 4096, distance);
    vectorArgument = &slots[0].value;
    MATCHING_OBSERVE2_VOLATILE(direction, vectorArgument);
    direction = (Vector3D*)((char*)direction - 0x58);
    func_8004F1C8(vectorArgument, direction, vectorArgument);
    MATCHING_OBSERVE_VOLATILE(direction);
    func_8004F110(&slots[0].value, 6);
    func_8004F194(&slots[0].value, &tag->actor->position, &slots[0].value);
    boundsList = tag->list;
    hit = 0;
    index = 0;
    if (boundsList->count > 0) {
        byteOffset = 8;
        do {
            int isHit;
            register Vector3D* hitPoint __asm__("$5");
            isHit = DecodedClosestBounds(&slots[0].value, (char*)boundsList + byteOffset,
                                         -boundsList->argument, 0);
            hitPoint = &slots[0].value;
            if (isHit) {
                Moby* hitActor = tag->actor;
                MATCHING_OBSERVE2_VOLATILE(hitActor, hitPoint);
                hit = 1;
                func_8004F178(&hitActor->position, hitPoint);
                break;
            }
            boundsList = tag->list;
            boundCount = boundsList->count;
            MATCHING_OBSERVE_VOLATILE(boundCount);
            index++;
            byteOffset += 24;
        } while (index < boundCount);
    }
    if (!hit) {
        list = tag->list;
        DecodedClosestQuery(&slots[2].value, &slots[0].value, list->bounds, list->argument);
        minimum = func_8004F334(&slots[2].value, &slots[0].value);
        index = 1;
        list = tag->list;
        if (index < list->count) {
            do {
                /* Retail repeatedly passes the list head, not an index-offset record. */
                DecodedClosestQuery(&slots[1].value, &slots[0].value, list->bounds, list->argument);
                distance = func_8004F334(&slots[1].value, &slots[0].value);
                if (distance < minimum) {
                    minimum = distance;
                    func_8004F178(&slots[2].value, &slots[1].value);
                }
                list = tag->list;
                index++;
            } while (index < list->count);
        }
        func_8004F178(&tag->actor->position, &slots[2].value);
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
void func_level_41_8008A3F8(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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
int Timer86B88ApplyHudMovement(void*, int*, int*, int*) __asm__("func_80029708");
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
int func_level_41_8008AAE8(void* input) {
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
    Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
        Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
        Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
            Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
                Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
                Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
                Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
            Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
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
        Timer86B88ApplyHudMovement(drawOwner, drawIndex, drawX, drawY);
        Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
    }
    return 0;
}

#undef Timer86B88Field

#undef Timer86B88High


void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_8004EDE8(Vector3D*, int);
int func_level_41_8008B078(Moby* moby, Vector3D* position, int limit) {
    Vector3D delta;
    func_8004F1C8(&delta, position, &moby->position);
    if (ABS(delta.x) < limit && ABS(delta.y) < limit && ABS(delta.z) < limit) {
        if (func_8004EDE8(&delta, 1) < limit)
            return 1;
    }
    return 0;
}

typedef struct {
    short count;
    unsigned char reserved02[0xA];
    PathNode* nodes;
} DecodedNearestPath;
int func_8004F334(Vector3D*, Vector3D*);
int func_level_41_8008B120(Vector3D* position, DecodedNearestPath* path, int center, int radius) {
    /* Eight further retail stack bytes have an unknown source purpose. */
    int reservedStack[2];
    int bestDistance = 0xFFFFFF;
    register int index __asm__("$16") = 0;
    register int bestIndex __asm__("$18") = 0;
    register int extent __asm__("$3") = radius * 2;
    register int count __asm__("$21");
    int first;
    /* Empty constraints retain the original temporary and loop registers. */
    MATCHING_KEEP(extent);
    if (extent > 0) {
        first = center - radius;
        count = extent;
        MATCHING_KEEP(count);
        do {
            register int wrapped __asm__("$17") = (first + index + path->count) % path->count;
            int distance = func_8004F334(position, &path->nodes[wrapped].pos);
            if (distance < bestDistance) {
                bestDistance = distance;
                bestIndex = wrapped;
            }
            index++;
        } while (index < count);
    }
    return bestIndex;
}

void func_level_41_8008B218(HudEntry* hud) {
    int frame, height;
    SpriteData* sprite;
    func_80027D60(hud);
    hud->unk3D = 0x18;
    frame = D_8006C738[func_80027934(7)].frame;
    sprite = &D_8006C788[frame];
    hud->unk4C = frame;
    hud->unk3C = sprite->unk4 - sprite->unk0;
    height = hud->unk3D + (sprite->unk5 - sprite->unk1);
    hud->unk3D = height;
    sprite = &D_8006C788[hud->unk4C + 2];
    height += (sprite->unk5 - sprite->unk1) * 6;
    hud->unk3D = height;
    sprite = &D_8006C788[hud->unk4C + 1];
    height += sprite->unk5 - sprite->unk1;
    hud->unk3D = height;
}

extern int* DecodedDrawClipped(SpriteData*, int, int, int) __asm__("func_80028D30");
int func_level_41_8008B310(HudEntry* hud) {
    Vector3D position;
    register SpriteData* sprite __asm__("$18");
    SpriteData* previous;
    register SpriteData* sprites __asm__("$4");
    register int firstRight __asm__("$6");
    register int firstLeft __asm__("$5");
    register int oldTop __asm__("$3");
    register int oldBottom __asm__("$7");
    register int secondBottom __asm__("$5");
    register int drawX __asm__("$5");
    register int drawY __asm__("$6");
    int secondRight, secondLeft;
    register SpriteData* firstDraw __asm__("$4");
    register int baseIndex __asm__("$2");
    register int frameIndex __asm__("$3");
    register int x __asm__("$2");
    register int y __asm__("$3");
    register int width __asm__("$17");
    int height, remaining, fill, index;
    register int endIndex __asm__("$2");
    register int clipFlags __asm__("$7");
    register SpriteData* endBase __asm__("$3");
    /* Empty constraints retain retail allocation and ordering; emit no instructions. */
    x = hud->unk0;
    y = hud->unk2;
    MATCHING_KEEP2(x, y);
    position.x = x;
    position.y = y;
    if (*(unsigned char*)&hud->movementFrame)
        position.z = (*(unsigned char*)&hud->movementFrame + 10) >> 1;
    else
        position.z = 0;
    func_80029674(hud, &position.x, &position.y);
    func_80029708(hud, &position.z, &position.x, &position.y);
    /* Select the original sprite records and retain their byte dimensions. */
    baseIndex = hud->unk4C;
    sprites = D_8006C788;
    frameIndex = (unsigned char)hud->unk1C.frame;
    MATCHING_KEEP3(baseIndex, sprites, frameIndex);
    sprite = &sprites[baseIndex];
    MATCHING_KEEP(sprite);
    firstRight = sprite->unk4;
    frameIndex *= sizeof(SpriteData);
    firstLeft = sprite->unk0;
    MATCHING_KEEP2(firstRight, firstLeft);
    sprite = (SpriteData*)((char*)sprites + frameIndex);
    MATCHING_KEEP(sprite);
    firstDraw = sprite;
    MATCHING_KEEP(firstDraw);
    secondRight = sprite->unk4;
    secondLeft = sprite->unk0;
    MATCHING_KEEP2_CLOBBER(firstRight, firstLeft, "memory");
    width = firstRight - firstLeft;
    MATCHING_KEEP(width);
    width = (width - (secondRight - secondLeft)) >> 1;
    MATCHING_KEEP_CLOBBER(width, "memory");
    position.y += 22 - (sprite->unk5 - sprite->unk1);
    func_800289C8(firstDraw, position.x + width, position.y);
    baseIndex = hud->unk4C;
    drawX = position.x;
    oldTop = sprite->unk5;
    sprites = D_8006C788;
    oldBottom = sprite->unk1;
    drawY = position.y;
    MATCHING_KEEP5_CLOBBER(baseIndex, sprites, oldTop, oldBottom, drawX, "memory");
    sprite = &sprites[baseIndex];
    firstDraw = sprite;
    MATCHING_KEEP(firstDraw);
    drawY += 2;
    MATCHING_KEEP2(drawY, oldTop);
    oldTop -= oldBottom;
    drawY += oldTop;
    position.y = drawY;
    func_800289C8(firstDraw, drawX, drawY);
    baseIndex = hud->unk4C;
    oldTop = sprite->unk5;
    sprites = D_8006C788;
    secondBottom = sprite->unk1;
    MATCHING_KEEP4(baseIndex, sprites, oldTop, secondBottom);
    sprite = &sprites[baseIndex + 2];
    position.y += oldTop - secondBottom;
    height = sprite->unk5 - sprite->unk1;
    /* Six segments; signed division and the original trap paths are retained. */
    remaining = height * 6;
    fill = *hud->unk28 * remaining / hud->unk26;
    remaining -= height;
    for (index = 0; index < 6; index++) {
        if (fill >= remaining)
            break;
        func_800289C8(sprite, position.x, position.y);
        remaining -= height;
        position.y += height;
    }
    /* Two clipped draws split the transition between sprite records. */
    fill -= remaining;
    DecodedDrawClipped(sprite, position.x, position.y, ((fill - height) << 16) | 8);
    clipFlags = ((height - fill) << 16) | 8;
    drawX = position.x;
    endIndex = hud->unk4C;
    MATCHING_KEEP2_VOLATILE_CLOBBER(clipFlags, drawX, "memory");
    drawY = position.y;
    endBase = D_8006C788;
    MATCHING_KEEP4(endIndex, endBase, drawX, drawY);
    sprite = &endBase[endIndex + 3];
    DecodedDrawClipped(sprite, drawX, drawY, clipFlags);
    goto advance;
    do {
        func_800289C8(sprite, position.x, position.y);
    advance:
        position.y += height;
        index++;
        MATCHING_BARRIER_VOLATILE("memory");
    } while (index < 6);
    func_800289C8(&D_8006C788[hud->unk4C + 1], position.x, position.y);
    return 0;
}

void func_level_41_8008B5E0(HudEntry* hud) {
    int value, step;
    func_80027A60(hud);
    value = *hud->unk28;
    step = value / 30;
    if (step < hud->unk50 && value != 0 && (step < 8 || (step < 16 && (step & 1)))) {
        PlaySound(D_8006C654->timerRunOut, 0, 0);
    }
    hud->unk50 = step;
    if (*hud->unk28 == 0)
        func_80028154(hud->unk1A);
}

typedef struct {
    short count;
    unsigned char reserved02[0xA];
    PathNode* nodes;
} DecodedPathRecord;
int func_8004F334(Vector3D*, Vector3D*);
int func_level_41_8008B6A4(DecodedPathRecord* path) {
    int farthestDistance = 0;
    int farthestIndex = 0;
    int index;
    for (index = 0; index < path->count; index++) {
        int distance = func_8004F334(&spyro.position, &path->nodes[index].pos);
        if (farthestDistance < distance) {
            farthestDistance = distance;
            farthestIndex = index;
        }
    }
    return farthestIndex;
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
int func_level_41_8008B740(Moby* mobyArgument, DecodedPathList* pathArgument,
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

void DecodedPolygonSubtract(void*, void*, void*) __asm__("func_8004F1C8");
int DecodedPolygonLength(void*, int) __asm__("func_8004EDE8");
/* Original polygon record: byte count, signed halfword bound, 28-byte entries. */
int func_level_41_8008BB7C(unsigned char* polygonArg, Vector3D* positionArg) {
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

/* AI generated; not human reviewed.
 * SCUS-94467 USA Rev0 representative 80091970..80091C94.
 * Shared 28-byte record addressing and signed side-test pattern also occurs
 * in verified func_level_41_8008BB7C. Original instructions additionally
 * select nearest/farthest indices and the heading-filtered farthest entry.
 * Native signed remainder/division traps and both ordered multiplies remain.
 * Empty asm constraints emit no instructions and retain temporary lifetimes.
 * Bound/distance/heading units, record producer and caller cadence are open.
 * Acceptance requires every copy's original linked words and full hashes.
 */
void SelectionSubtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
int SelectionLength(Vector3D*, int) __asm__("func_8004EDE8");
int SelectionHeading(int, int, int) __asm__("func_8004E880");
int SelectionAngleDistance(int, int) __asm__("func_8004F264");
int func_level_41_8008BE00(unsigned char* argument, Vector3D* position, int* nearest, int* farthest,
                           volatile int heading) {
    register unsigned char* polygon __asm__("$18") = argument;
    int farthestDistance = 0;
    register int directionalDistance __asm__("$22") = 0;
    register int nearestDistance __asm__("$23");
    register unsigned char* entry __asm__("$16");
    register Vector3D* delta __asm__("$21");
    register int nearestIndex __asm__("$20");
    register int index __asm__("$17");
    register int offset __asm__("$19");
    register int distance __asm__("$16");
    int sides[2];
    Vector3D deltaVector;
    Vector3D* volatile positions[2];
    int* volatile nearestSlots[2];
    int* volatile farthestSlots[2];
    int directionalIndexSlots[2], farthestIndexSlots[4];
    register Vector3D* positionArgument __asm__("$5");
    MATCHING_KEEP(polygon);
    nearestDistance = 0xFFFFFF;
    entry = (unsigned char*)&deltaVector;
    positions[0] = position;
    positionArgument = positions[0];
    ((int**)nearestSlots)[0] = nearest;
    ((int**)farthestSlots)[0] = farthest;
    SelectionSubtract((Vector3D*)entry, positionArgument, (Vector3D*)(polygon + 4));
    {
        int extent = SelectionLength((Vector3D*)entry, 0);
        MATCHING_OBSERVE_CLOBBER(extent, "memory");
        if (*(short*)(polygon + 2) < extent)
            goto outside;
    }
    nearestIndex = -1;
    {
        int limit = polygon[1];
        MATCHING_KEEP(limit);
        index = 0;
        if (limit > 0) {
            delta = (Vector3D*)entry;
            offset = 12;
            do {
                entry = polygon + offset;
                SelectionSubtract(delta, positions[0], (Vector3D*)(entry + 8));
                distance = SelectionLength(delta, 0);
                if (farthestDistance < distance) {
                    farthestDistance = distance;
                    farthestIndexSlots[0] = index;
                }
                if (directionalDistance < distance) {
                    register int currentHeading __asm__("$8");
                    __asm__("" : "=r"(currentHeading) : "0"(heading));
                    if (currentHeading < 0 ||
                        SelectionAngleDistance(
                            heading, SelectionHeading(deltaVector.x, deltaVector.y, 0)) < 64) {
                        directionalDistance = distance;
                        directionalIndexSlots[0] = index;
                    }
                }
                if (nearestIndex < 0 || distance < nearestDistance) {
                    nearestIndex = index;
                    {
                        register int* result __asm__("$9");
                        __asm__("" : "=r"(result) : "0"(nearestSlots[0]));
                        nearestDistance = distance;
                        *result = index;
                    }
                }
                limit = polygon[1];
                MATCHING_KEEP(limit);
                index++;
                offset += 28;
            } while (index < limit);
        }
    }
    {
        register int selected __asm__("$9");
        if (!directionalDistance)
            selected = farthestIndexSlots[0];
        else
            selected = directionalIndexSlots[0];
        MATCHING_KEEP(selected);
        {
            register int* result __asm__("$8");
            __asm__("" : "=r"(result) : "0"(farthestSlots[0]));
            *result = selected;
            __asm__ volatile("" : "=r"(index) : "0"(index), "m"(*result));
        }
    }
    for (index = 0; index < 2;) {
        register int count __asm__("$4") = polygon[1];
        register int selected __asm__("$2");
        int sum, previous;
        MATCHING_KEEP_VOLATILE_CLOBBER(index, "memory");
        sum = nearestIndex + index;
        previous = count - 1;
        selected = (sum + previous) % count;
        selected = 12 + selected * 28;
        MATCHING_KEEP(selected);
        entry = polygon + selected;
        SelectionSubtract(&deltaVector, positions[0], (Vector3D*)(entry + 8));
        {
            register int component __asm__("$3") = deltaVector.x;
            register int factor __asm__("$2") = *(int*)(entry + 16);
            register int firstProduct __asm__("$4"), secondProduct __asm__("$10");
            register int total __asm__("$2");
            MATCHING_KEEP2(component, factor);
            firstProduct = component * factor;
            component = deltaVector.y;
            factor = *(int*)(entry + 20);
            MATCHING_KEEP3(firstProduct, component, factor);
            secondProduct = component * factor;
            {
                register unsigned int slotOffset __asm__("$3") = index * 4;
                register unsigned char* slotBase __asm__("$2");
                register int* slot __asm__("$3");
                index++;
                slotBase = (unsigned char*)sides;
                MATCHING_KEEP2(slotOffset, slotBase);
                slot = (int*)(slotOffset + (unsigned int)slotBase);
                MATCHING_KEEP2(slot, secondProduct);
                total = firstProduct + secondProduct;
                MATCHING_KEEP(total);
                *slot = total;
            }
        }
    }
    {
        int previous = polygon[1] - 1;
        register int address __asm__("$2");
        MATCHING_KEEP(previous);
        index = (nearestIndex + previous) % (int)polygon[1];
        MATCHING_KEEP(index);
        address = 12 + index * 28;
        MATCHING_KEEP(address);
        entry = polygon + address;
    }
    MATCHING_KEEP(entry);
    {
        int offset = nearestIndex * 28;
        register unsigned char* selected __asm__("$2");
        MATCHING_KEEP(offset);
        selected = polygon + offset;
        MATCHING_KEEP(selected);
        {
            register int firstProduct __asm__("$4");
            register int left __asm__("$4") = *(int*)(selected + 12);
            register int firstFactor __asm__("$3") = *(int*)(entry + 16);
            register int component __asm__("$3");
            register int factor __asm__("$2");
            register int secondProduct __asm__("$3");
            register int orientation __asm__("$2");
            MATCHING_KEEP2(left, firstFactor);
            firstProduct = left * firstFactor;
            component = *(int*)(selected + 16);
            factor = *(int*)(entry + 20);
            MATCHING_KEEP3(firstProduct, component, factor);
            secondProduct = component * factor;
            MATCHING_KEEP(secondProduct);
            orientation = firstProduct + secondProduct;
            MATCHING_KEEP(orientation);
            if (orientation >= 0) {
                if (sides[0] < 0)
                    return 0;
                __asm__ volatile("" : :);
            } else if (sides[0] >= 0)
                return 1;
            if (sides[1] >= 0)
                return 1;
            MATCHING_BARRIER("$2");
        }
    }
outside:
    MATCHING_BARRIER("$2");
    return 0;
}

typedef struct {
    unsigned char reserved00[8];
    Vector3D point;
    unsigned char reserved14[8];
} DecodedPointQueryRecord;
typedef struct {
    unsigned char reserved00, count, reserved02[10];
    DecodedPointQueryRecord records[1];
} DecodedPointQueryHeader;
void func_level_41_8008C128(Moby* moby, Vector3D* point, DecodedPointQueryHeader* path, short* next,
                            short* direction) {
    int distance = 9999999;
    int pointIndex = -1;
    int mobyIndex = -1;
    int index, byteOffset, candidateDistance;
    register unsigned int count __asm__("$2");
    register int oldDirection __asm__("$2");
    for (index = 0; index < path->count; index++) {
        candidateDistance = func_8004F334(&path->records[index].point, point);
        if (candidateDistance < distance) {
            pointIndex = index;
            distance = candidateDistance;
        }
    }
    distance = 9999999;
    for (index = 0; index < path->count; index++) {
        candidateDistance = func_8004F334(&path->records[index].point, &moby->position);
        if (candidateDistance < distance) {
            mobyIndex = index;
            distance = candidateDistance;
        }
    }
    *direction = pointIndex < mobyIndex ? -1 : 1;
    __asm__("" : : : "memory", "$3");
    candidateDistance = mobyIndex - pointIndex;
    count = path->count;
    __asm__("" : "=r"(count) : "0"(count), "r"(candidateDistance));
    if (candidateDistance < 0)
        candidateDistance = -candidateDistance;
    if ((int)(count >> 1) < candidateDistance) {
        oldDirection = *direction;
        MATCHING_KEEP(oldDirection);
        *direction = -oldDirection;
    }
    *next = (mobyIndex + *direction + path->count) % path->count;
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * level34 80091E50..800921D0; original numeric route, units/cadence open. */
typedef struct {
    int x, y, dx, dy, reserved[3];
} Decoded225Node;
typedef struct {
    unsigned char header[20];
    Decoded225Node node[1];
} Decoded225Path;
typedef struct {
    Vector3D aim;
    int pad0;
    Vector3D ahead;
    int pad1;
    Vector3D previous;
    int pad2;
    Vector3D edge;
    int pad3;
} Decoded225Vectors;
int Decoded225Length(Vector3D*, int) __asm__("func_8004EDE8");
void Decoded225Scale(Vector3D*, int, int) __asm__("func_8004F08C");
int Decoded225Angle(int, int, int) __asm__("func_8004E880");
int Decoded225Turn(Moby*, int, int, int, int, int) __asm__("func_8003585C");
void Decoded225Move(Moby*, int, int, int, int) __asm__("func_80035DDC");
extern int (*Decoded225Probe)(Decoded225Path*, Vector3D*, int*, int*,
                              int) __asm__("unk_ovlheader_80074418");
extern int (*Decoded225Inside)(Decoded225Path*, Vector3D*) __asm__("unk_ovlheader_80074414");
int func_level_41_8008C2E0(Moby* mobyArgument, int speed, int turn, int move, Vector3D* target,
                           Decoded225Path* pathArgument, short* selectedArgument, short* step,
                           int distanceLimit) {
    Decoded225Vectors vectors;
    int foundIndex, foundValue;
    register Moby* moby __asm__("$19");
    register int currentSpeed __asm__("$17");
    register int turnRate __asm__("$16");
    register int moveArgument __asm__("$18");
    register Decoded225Path* path __asm__("$21");
    register short* selected __asm__("$23");
    register Vector3D* position __asm__("$20");
    register Vector3D* previous __asm__("$22");
    register Vector3D* temporary __asm__("$16");
    int heading;
    selected = selectedArgument;
    MATCHING_KEEP(selected);
    path = pathArgument;
    MATCHING_KEEP(path);
    moby = mobyArgument;
    currentSpeed = speed;
    turnRate = turn;
    MATCHING_KEEP3(moby, currentSpeed, turnRate);
    {
        register int value __asm__("$2") = path->node[*selected].dx;
        moveArgument = move;
        vectors.aim.x = value;
    }
    {
        register int slot __asm__("$3") = *selected;
        register Vector3D* aim __asm__("$4");
        MATCHING_KEEP_VOLATILE_CLOBBER(slot, "$4");
        aim = &vectors.aim;
        vectors.aim.y = path->node[slot].dy;
        vectors.aim.z = 0;
        {
            int length = Decoded225Length(aim, 0);
            Decoded225Scale(&vectors.aim, length, 800);
        }
    }

    {
        register int slot __asm__("$3") = *selected;
        register int* record __asm__("$2");
        register int offset __asm__("$2");
        register int value __asm__("$3");
        MATCHING_KEEP(slot);
        record = (int*)((char*)path + slot * 28);
        value = vectors.aim.x;
        MATCHING_BARRIER_VOLATILE("$22");
        offset = record[5];
        previous = &vectors.previous;
        value += offset;
        MATCHING_KEEP(value);
        vectors.aim.x = value;
    }
    {
        register int slot __asm__("$3");
        register int* record __asm__("$2");
        register int offset __asm__("$2");
        register int value __asm__("$3");
        register Vector3D* destination __asm__("$4");
        slot = *selected;
        MATCHING_KEEP_VOLATILE_CLOBBER(slot, "$4");
        destination = previous;
        MATCHING_KEEP(destination);
        record = (int*)((char*)path + slot * 28);
        value = vectors.aim.y;
        offset = record[6];
        position = &moby->position;
        value += offset;
        MATCHING_KEEP(value);
        vectors.aim.y = value;
        vectors.aim.z = moby->position.z + 512;
        func_8004F178(destination, position);
    }
    Decoded225Turn(
        moby,
        Decoded225Angle(vectors.aim.x - moby->position.x, vectors.aim.y - moby->position.y, 0),
        turnRate, 2, 1, 0);
    Decoded225Move(moby, currentSpeed, 0, 0, moveArgument);
    if (!Decoded225Probe(path, position, &foundIndex, &foundValue, -1)) {
        func_8004F178(position, previous);
        temporary = &vectors.edge;
        {
            register int* record __asm__("$2") = (int*)((char*)path + foundIndex * 28);
            MATCHING_KEEP(record);
            temporary->x = record[7];
            temporary->y = record[8];
            temporary->z = 0;
        }
        Decoded225Scale(temporary, Decoded225Length(temporary, 0), 30);
        func_8004F194(position, position, temporary);
        return 0;
    }
    if (func_8004F264(
            Decoded225Angle(target->x - moby->position.x, target->y - moby->position.y, 0),
            moby->angle.yaw) < 60) {
        temporary = &vectors.ahead;
        func_8004F1C8(temporary, target, position);
        Decoded225Scale(temporary, Decoded225Length(temporary, 0), 300);
        func_8004F194(temporary, position, temporary);
        if (Decoded225Inside(path, temporary))
            return 1;
    }
    currentSpeed = (*selected + *step + path->header[1]) % path->header[1];
    {
        register int* record __asm__("$2") = (int*)((char*)path + *selected * 28);
        register int x __asm__("$4") = record[5];
        register int y __asm__("$5") = record[6];
        register int* next __asm__("$3");
        MATCHING_KEEP2(x, y);
        next = (int*)((char*)path + currentSpeed * 28);
        {
            register int nextX __asm__("$7") = next[5];
            register int nextY __asm__("$3") = next[6];
            int angle;
            MATCHING_KEEP2(nextX, nextY);
            angle = Decoded225Angle(nextX - x, nextY - y, 0);
            heading = angle;
        }
    }
    if (func_8004F334(&moby->position, &vectors.aim) < distanceLimit &&
        func_8004F264(heading, moby->angle.yaw) < 64)
        *selected = currentSpeed;
    return 0;
}
