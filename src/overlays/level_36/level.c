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
int func_level_36_8007FF64(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

void func_level_36_80080280(Moby* moby, int mode) {
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
int func_level_36_800802F8(int inputMask) {
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
void func_level_36_8008077C(Moby* moby, int increment, int* accumulator) {
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
void func_level_36_8008088C(Vector3D* outputArg, Vector3D* position,
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
void func_level_36_80080B48(void) {
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
void func_level_36_80080D84(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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
int func_level_36_80081474(Moby* owner, int tableSelector, int tableMultiplier, int helperInput,
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

