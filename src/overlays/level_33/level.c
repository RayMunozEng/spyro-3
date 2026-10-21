#include "matching.h"
#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
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
int func_level_33_800934C8(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

void func_level_33_800937E4(Moby* moby, int mode) {
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

/* AI-generated; not human reviewed. Verified 582C sibling with original
 * per-overlay global switch branches. Raw units, helper meanings and
 * cadence remain unresolved. See original controller sibling 3784 evidence. */
extern int Controller582CLevel __asm__("D_8006C5BC");
extern int Controller582CMode __asm__("D_8006C5C8");
extern int Controller582CStage __asm__("D_8006E044");
extern int Controller582CWord __asm__("D_8006C6D4");
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
/* USA Rev 0, 289 original instructions and eight owned switch-table words.
 * Reuses verified level11/8008582C; target case0 passes 0x1D at 0x80087F84.
 * Units, helper/field semantic chains and caller cadence remain unresolved.
 * Empty compiler constraints contain no opcodes. AI generated; not human reviewed.
 */
int func_level_33_8009385C(int inputMask) {
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
                case 4: {
                    register int stage __asm__("$3") = Controller582CStage;
                    if (stage == 31 || stage == 40) {
                        Controller582CWord = 255;
                    }
                }
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

/* Only the retail pointer array at +0x3C is described here. */
typedef struct {
    unsigned char reserved00[0x3C];
    unsigned char* frames[1];
} DecodedFrameTable;
extern DecodedFrameTable* D_8006EE2C[];
void func_level_33_80093D08(Moby* moby, int increment, int* accumulator) {
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

#define Controller93E18Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int Controller93E18D_8006C644 __asm__("D_8006C644");
extern unsigned char Controller93E18D_80070328[] __asm__("D_80070328");
extern int Controller93E18D_80071900 __asm__("D_80071900");
extern int Controller93E18D_80071918 __asm__("D_80071918");
extern int Controller93E18D_8007191C __asm__("D_8007191C");
extern int Controller93E18D_80071920 __asm__("D_80071920");
int Controller93E18Helper18368(void*, void*) __asm__("func_80018368");
int Controller93E18Helper1AD60(void*, void*, int, int, void*) __asm__("func_8001AD60");
int Controller93E18Helper1BA30(void*, int, int, int, int, void*) __asm__("func_8001BA30");
int Controller93E18PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller93E18PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller93E18Helper4ECF4(void*, void*) __asm__("func_8004ECF4");
int Controller93E18TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller93E18MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Controller93E18ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller93E18CopyVector(void*, void*) __asm__("func_8004F178");
int Controller93E18AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller93E18Helper4F6C4(void*, void*, void*) __asm__("func_8004F6C4");
int Controller93E18Helper50B00(void*, void*, void*, void*, int) __asm__("func_80050B00");
int Controller93E18DeleteMoby(void*) __asm__("func_80055B18");
extern void* (*Controller93E18SpawnMoby)(int, void*)__asm__("SpawnMoby");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level33/80093E18, level43/8008BF10, level44/800897EC,
 * level46/8008A32C; 354 identical original instructions each, exact helper
 * and global symbols, no owned tables. Preserve stack offsets 0x18/0x28/
 * 0x38/0x54/0x60, angle shorts at 0x70, two opaque 24-byte regions at
 * 0x78/0x90, saved owner at 0xA8 and count at 0xB0.
 * Original signed shifts/clamps, two vertex-count increments, trace branches,
 * callback arguments, pointer rereads, colour/index stores and terminators
 * retain exact word sequences. Regions and helper names imply no decoded
 * semantic contract; coordinate units, fixed-point domains and caller cadence
 * remain unresolved. Updates occur once per invocation. Confidence: exact
 * native/linked words and full retail hashes, not semantic runtime review.
 * Falsifiable vectors: all 1,416 original words and EXE/all-overlay SHA set.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_33_80093E18(void** inputOwner) {
    struct {
        Vector3D first;
        int pad24;
        Vector3D second;
        int pad34;
        Vector3D third;
        int pad44[4];
        Vector3D left;
        Vector3D right;
        int pad6C;
        short angles[3];
        short pad76;
        unsigned char matrix[24];
        unsigned char alternate[24];
        void** volatile owner;
        int padAC;
        int count;
        int padB4[3];
    } frame;
    register int initialSteps __asm__("$17");
    register int nextVertexOffset __asm__("$20");
    int resourceResult;
    register int scaledCounter __asm__("$2");
    register int halfStep __asm__("$20");
    register int clamp __asm__("$21");
    register void* matrixVector __asm__("$16");
    register void* leftVector __asm__("$18");
    register void* rightVector __asm__("$17");
    register void* thirdVector;
    int firstDecrement;
    int halfDecrement;
    int loopDecrement;
    int pairDecrement;
    register int initialStepIndex __asm__("$18");
    register int segmentIndex __asm__("$18");
    register int vertexOffset __asm__("$20");
    register int vertexCount __asm__("$21");
    register int colourCount __asm__("$23");
    int remainingPredicate;
    int twiceVertexCount;
    register int colourWord __asm__("$3");
    register void* colourOwner __asm__("$2");
    register int secondColourIndex __asm__("$2");
    register int firstColourIndex __asm__("$3");
    void* childForCheck;
    void* childToRemove;
    void* finalChild;
    register void* sourceOrVector __asm__("$16");
    register void* data __asm__("$19");
    void* createdChild;
    void* terminator;
    register void* indexCursor __asm__("$17");
    register void* colourCursor __asm__("$22");

    frame.owner = inputOwner;
    data = *inputOwner;
    if ((Controller93E18Field(data, int*, 0x88) != 0) ||
        (resourceResult =
             Controller93E18Helper50B00(data + 0x8C, data + 0x3B0, data + 0x3F4, data + 0x80, 1),
         Controller93E18Field(data, int*, 0x88) = resourceResult, (resourceResult != 0))) {
        sourceOrVector = Controller93E18D_80070328 + 0x64;
        {
            register void* prepared __asm__("$4") = sourceOrVector - 0x34;
            register void* firstVector __asm__("$5");
            register int value __asm__("$2");
            register int negativeAngle __asm__("$3");
            MATCHING_KEEP(prepared);
            value = Controller93E18Field(data, int*, 0x60);
            MATCHING_KEEP(value);
            firstVector = &frame.first.x;
            MATCHING_KEEP(firstVector);
            frame.third.y = 0;
            frame.third.z = 0;
            frame.angles[0] = 0;
            frame.third.x = value;
            MATCHING_BARRIER_VOLATILE("memory");
            negativeAngle = Controller93E18Field(data, int*, 0x5C);
            value = *(int*)sourceOrVector;
            MATCHING_KEEP2_CLOBBER(value, negativeAngle, "$6");
            {
                register void* thirdArgument __asm__("$6") = firstVector;
                MATCHING_KEEP3(thirdArgument, value, negativeAngle);
                frame.angles[2] = value;
                value = -327;
                frame.first.x = value;
                __asm__ volatile("" : : : "$2", "memory");
                value = -140;
                frame.first.y = value;
                __asm__ volatile("" : : : "$2", "memory");
                value = 284;
                negativeAngle = -negativeAngle;
                MATCHING_KEEP2(negativeAngle, value);
                frame.first.z = value;
                frame.angles[1] = negativeAngle;
                Controller93E18TransformVectorByBasis(prepared, firstVector, thirdArgument);
            }
        }
        Controller93E18AddVector(&frame.first.x, &frame.first.x, sourceOrVector - 0x64);
        {
            register void* prepared __asm__("$4") = &frame.angles[0];
            MATCHING_KEEP(prepared);
            matrixVector = &frame.matrix[0];
            Controller93E18Helper4F6C4(prepared, matrixVector, &frame.alternate[0]);
        }
        Controller93E18Helper4ECF4(matrixVector, matrixVector);
        Controller93E18TransformVectorByBasis(matrixVector, &frame.third.x, &frame.third.x);
        sourceOrVector = &frame.second.x;
        Controller93E18CopyVector(sourceOrVector, &frame.first.x);
        {
            register int source __asm__("$3") = Controller93E18D_8006C644;
            MATCHING_KEEP_CLOBBER(source, "$18");
            initialStepIndex = 0;
            scaledCounter = (source * 96) >> 7;
        }
        initialSteps = scaledCounter & 7;
        MATCHING_KEEP(initialSteps);
        initialSteps >>= 1;
        halfStep = scaledCounter & 1;
        if (initialSteps != 0) {
            clamp = -512;
            MATCHING_KEEP(clamp);
            do {
                Controller93E18AddVector(sourceOrVector, &frame.first.x, &frame.third.x);
                firstDecrement = frame.third.z - 8;
                frame.third.z = firstDecrement;
                if (firstDecrement < -0x200) {
                    frame.third.z = clamp;
                }
                Controller93E18CopyVector(&frame.first.x, sourceOrVector);
                initialStepIndex += 1;
            } while (initialStepIndex < initialSteps);
        }
        sourceOrVector = &frame.second.x;
        if (halfStep) {
            Controller93E18AddVector(sourceOrVector, &frame.first.x, &frame.third.x);
            Controller93E18AddVector(sourceOrVector, &frame.first.x, sourceOrVector);
            Controller93E18ShiftVectorRightTowardZero(sourceOrVector, 1);
            halfDecrement = frame.third.z - 5;
            frame.third.z = halfDecrement;
            if (halfDecrement < -0x200) {
                frame.third.z = -0x200;
            }
        }
        frame.left.y = 0x40;
        frame.left.x = 0;
        frame.left.z = 0;
        frame.right.x = 0;
        frame.right.y = -0x40;
        frame.right.z = 0;
        {
            register int zero __asm__("$4") = 0;
            MATCHING_KEEP(zero);
            leftVector = &frame.left.x;
            Controller93E18TransformVectorByBasis((void*)zero, leftVector, leftVector);
        }
        {
            register int zero __asm__("$4") = 0;
            MATCHING_KEEP(zero);
            rightVector = &frame.right.x;
            Controller93E18TransformVectorByBasis((void*)zero, rightVector, rightVector);
        }
        {
            register void* prepared __asm__("$4") = data + 0x8C;
            MATCHING_KEEP(prepared);
            sourceOrVector = &frame.second.x;
            {
                register void* secondArgument __asm__("$5") = sourceOrVector;
                register void* thirdArgument __asm__("$6") = leftVector;
                MATCHING_KEEP2(secondArgument, thirdArgument);
                frame.count = 0;
                Controller93E18AddVector(prepared, secondArgument, thirdArgument);
            }
        }
        Controller93E18AddVector(data + 0x98, sourceOrVector, rightVector);
        MATCHING_BARRIER_VOLATILE("$21");
        vertexCount = 2;
        colourCount = 1;
        segmentIndex = 0;
        thirdVector = &frame.third.x;
        MATCHING_KEEP2_VOLATILE(thirdVector, sourceOrVector);
        indexCursor = data;
        MATCHING_BARRIER_VOLATILE("$22");
        colourCursor = data + 4;
        vertexOffset = 0xA4;
        Controller93E18Field(data, unsigned char*, 0x3B0) = 0x80;
        Controller93E18Field(data, signed char*, 0x3B1) = 0;
        Controller93E18Field(data, signed char*, 0x3B2) = 0;
    produceSegment:
        Controller93E18AddVector(sourceOrVector, sourceOrVector, thirdVector);
        loopDecrement = frame.third.z - 8;
        frame.third.z = loopDecrement;
        if (loopDecrement < -0x200) {
            frame.third.z = -0x200;
        }
        Controller93E18AddVector(sourceOrVector, sourceOrVector, thirdVector);
        if (!(segmentIndex & 1)) {
            if (Controller93E18Helper18368(&frame.first.x, sourceOrVector) != 0) {
                Controller93E18CopyVector(sourceOrVector, &Controller93E18D_80071900);
                if (Controller93E18Field(data, void**, 0x70) == 0) {
                    register void* (*create)(int, void*)__asm__("$2") = Controller93E18SpawnMoby;
                    register void* ownerArgument __asm__("$5");
                    MATCHING_KEEP_CLOBBER(create, "$5");
                    ownerArgument = frame.owner;
                    createdChild = create(101, ownerArgument);
                    Controller93E18Field(data, void**, 0x70) = createdChild;
                    if (createdChild == 0)
                        goto finishSegments;
                }
                {
                    Controller93E18CopyVector(Controller93E18Field(data, void**, 0x70) + 0xC,
                                              sourceOrVector);
                    if (Controller93E18Helper1BA30(Controller93E18Field(data, void**, 0x70) + 0xC,
                                                   0x3E8, 3, 0, 0,
                                                   Controller93E18Field(data, void**, 0x70)) != 0) {
                        childForCheck = Controller93E18Field(data, void**, 0x70);
                        if (Controller93E18Field(childForCheck, unsigned char*, 0x54) == 0xFF) {
                            Controller93E18PlayMobySoundEvent(childForCheck, 0, 0);
                        }
                        colourWord = 0x3F000000;
                        MATCHING_KEEP_CLOBBER(colourWord, "$2");
                        colourOwner = Controller93E18Field(data, void**, 0x70);
                        MATCHING_KEEP(colourOwner);
                        colourWord |= 0xFF00;
                        goto storeColour;
                    } else {
                        colourWord = 0x3F000000;
                        MATCHING_KEEP_CLOBBER(colourWord, "$2");
                        colourOwner = Controller93E18Field(data, void**, 0x70);
                        MATCHING_KEEP(colourOwner);
                        colourWord |= 0xFF;
                    }
                storeColour:
                    Controller93E18Field(colourOwner, int*, 0x54) = colourWord;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Controller93E18Field(Controller93E18Field(data, void**, 0x70), signed char*,
                                         0x45) =
                        (signed char)(Controller93E18PlanarHeadingLookup(
                                          Controller93E18MeasureVectorLength(
                                              &Controller93E18D_80071918, 0),
                                          Controller93E18D_80071920, 0) -
                                      0x40);
                    Controller93E18Field(Controller93E18Field(data, void**, 0x70), signed char*,
                                         0x46) =
                        Controller93E18PlanarHeadingLookup(Controller93E18D_80071918,
                                                           Controller93E18D_8007191C, 0);
                }
                goto finishSegments;
            }
            {
                register void* ownerArgument __asm__("$8") = frame.owner;
                if (Controller93E18Helper1AD60(&frame.first.x, sourceOrVector, 0, 0,
                                               ownerArgument) != 0) {
                    childToRemove = Controller93E18Field(data, void**, 0x70);
                    remainingPredicate = segmentIndex < 0x20;
                    if (childToRemove != 0) {
                        Controller93E18DeleteMoby(childToRemove);
                        Controller93E18Field(data, void**, 0x70) = 0;
                        goto finishSegments;
                    }
                } else {
                    Controller93E18CopyVector(&frame.first.x, sourceOrVector);
                    goto producePair;
                }
            }
        } else {
        producePair:
            pairDecrement = frame.third.z - 8;
            frame.third.z = pairDecrement;
            if (pairDecrement < -0x200) {
                frame.third.z = -0x200;
            }
            Controller93E18AddVector(data + vertexOffset, sourceOrVector, &frame.left.x);
            nextVertexOffset = vertexOffset + 0xC;
            vertexCount++;
            MATCHING_KEEP(vertexCount);
            Controller93E18AddVector(data + nextVertexOffset, sourceOrVector, &frame.right.x);
            vertexOffset = nextVertexOffset + 0xC;
            vertexCount++;
            if (!(segmentIndex & 1)) {
                {
                    register int value __asm__("$2");
                    value = segmentIndex << 2;
                    MATCHING_KEEP(value);
                    value -= 128;
                    Controller93E18Field(colourCursor, unsigned char*, 0x3B0) = value;
                    __asm__ volatile("" : : : "$2", "memory");
                    value = segmentIndex << 3;
                    Controller93E18Field(colourCursor, unsigned char*, 0x3B1) = value;
                }
                Controller93E18Field(colourCursor, unsigned char*, 0x3B2) = 0;
                colourCursor += 4;
                colourCount++;
                {
                    register int value __asm__("$2");
                    value = vertexCount - 3;
                    Controller93E18Field(indexCursor, unsigned char*, 0x3F4) = value;
                    __asm__ volatile("" : : : "$2", "memory");
                    value = vertexCount - 1;
                    Controller93E18Field(indexCursor, unsigned char*, 0x3F5) = value;
                    __asm__ volatile("" : : : "$2", "memory");
                    value = vertexCount - 4;
                    Controller93E18Field(indexCursor, unsigned char*, 0x3F6) = value;
                    __asm__ volatile("" : : : "$2", "memory");
                    value = vertexCount - 2;
                    firstColourIndex = colourCount - 2;
                    Controller93E18Field(indexCursor, unsigned char*, 0x3F7) = value;
                }
                MATCHING_BARRIER_VOLATILE("$2");
                secondColourIndex = colourCount - 1;
                Controller93E18Field(indexCursor, signed char*, 0x3F8) = firstColourIndex;
                Controller93E18Field(indexCursor, signed char*, 0x3F9) = secondColourIndex;
                Controller93E18Field(indexCursor, signed char*, 0x3FA) = firstColourIndex;
                Controller93E18Field(indexCursor, signed char*, 0x3FB) = secondColourIndex;
                indexCursor += 8;
                {
                    register int count __asm__("$8") = frame.count;
                    count++;
                    frame.count = count;
                }
            }
            segmentIndex += 1;
            if (segmentIndex >= 0x20) {
            finishSegments:
                remainingPredicate = segmentIndex < 0x20;
            } else {
                goto produceSegment;
            }
        }
        if (remainingPredicate == 0) {
            finalChild = Controller93E18Field(data, void**, 0x70);
            twiceVertexCount = vertexCount * 2;
            if (finalChild != 0) {
                Controller93E18DeleteMoby(finalChild);
                Controller93E18Field(data, void**, 0x70) = 0;
                goto computeTerminator;
            }
        } else {
        computeTerminator:
            twiceVertexCount = vertexCount * 2;
        }
        {
            register int offset __asm__("$2") = twiceVertexCount + vertexCount;
            MATCHING_KEEP(offset);
            terminator = data + offset * 4;
        }
        Controller93E18Field(terminator, int*, 0x8C) = -1;
        Controller93E18Field(terminator, int*, 0x90) = -1;
        Controller93E18Field(terminator, int*, 0x94) = -1;
        {
            register int count __asm__("$8") = frame.count;
            register int offset __asm__("$2");
            MATCHING_KEEP(count);
            offset = count * 8;
            MATCHING_KEEP(offset);
            Controller93E18Field((void*)(offset + (int)data), int*, 0x3F4) = -1;
        }
    }
}

#undef Controller93E18Field


typedef struct {
    unsigned char reserved00[0x5C];
    int selector, result;
    Vector3D point;
} DecodedRatioRecord;
int func_8004EDE8(Vector3D*, int);
int func_8004E9E4(int);
int func_8004EA2C(int);
int func_8004F388(int);
void func_level_33_800943A0(Moby* moby) {
    Vector3D delta;
    DecodedRatioRecord* tag = moby->mobyTag;
    register int distance __asm__("$16");
    register int firstDivisor __asm__("$17");
    register int secondDivisor __asm__("$4");
    register int quotient __asm__("$2");
    func_8004F178(&delta, &moby->position);
    delta.z += 0x200;
    func_8004F1C8(&delta, &tag->point, &delta);
    distance = func_8004EDE8(&delta, 0);
    firstDivisor = func_8004E9E4(tag->selector);
    /* Empty constraints retain the retail divisor and quotient registers. */
    MATCHING_KEEP(firstDivisor);
    if (!firstDivisor)
        firstDivisor = 1;
    secondDivisor = func_8004EA2C(tag->selector);
    MATCHING_KEEP(secondDivisor);
    if (!secondDivisor)
        secondDivisor = 1;
    distance <<= 14;
    quotient = distance / firstDivisor;
    MATCHING_KEEP(quotient);
    distance = quotient << 12;
    tag->result = func_8004F388(distance / secondDivisor);
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
void func_level_33_800944B4(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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
            /* Rev0 class646 writes updateDistance255 and lowDrawDistance64; see batch1602. */
            if (source->mobyClass == 646) {
                child->updateDistance = 255;
                child->lowDrawDistance = 64;
            }
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
            /* Keep all five RNG calls in their original order. */
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
int func_level_33_80094BC4(HudEntry* argument) {
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

void func_level_33_80095144(HudEntry* hud) {
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

void func_level_33_800951EC(HudEntry* hud) {
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

void func_80055F14(Moby*, int, Vector3D*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_8004F388(int);
void func_80055D24(Moby*, int);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
extern short DecodedOrientationCos[] __asm__("D_80065920");
extern short DecodedOrientationSin[] __asm__("D_800658A0");
void func_level_33_800952E4(Moby* moby, Moby* source, int index) {
    struct {
        Vector3D point;
        int reserved1C;
        Vector3D delta;
        int reserved2C;
        Vector3D rotated;
        int reserved3C;
    } work;
    int length;
    func_80055F14(source, index, &work.point);
    func_80055F14(source, index + 1, &work.delta);
    func_8004F1C8(&work.delta, &work.delta, &work.point);
    moby->angle.yaw = func_8004E880(work.delta.x, work.delta.y, 0);
    func_80055F14(source, index + 2, &work.delta);
    func_8004F1C8(&work.delta, &work.point, &work.delta);
    work.rotated.x = (work.delta.x * DecodedOrientationCos[moby->angle.yaw] +
                      work.delta.y * DecodedOrientationSin[moby->angle.yaw]) >>
                     12;
    work.rotated.y = (-work.delta.x * DecodedOrientationSin[moby->angle.yaw] +
                      work.delta.y * DecodedOrientationCos[moby->angle.yaw]) >>
                     12;
    work.rotated.z = work.delta.z;
    length = func_8004F388(work.rotated.x * work.rotated.x + work.delta.z * work.delta.z);
    moby->angle.roll = -func_8004E880(length, work.rotated.y, 0);
    moby->angle.pitch = -func_8004E880(work.rotated.z, work.rotated.x, 0);
    func_80055D24(moby, 4);
    work.delta.x = 0;
    work.delta.y = 0;
    work.delta.z = 0x60;
    func_8004ED6C(&moby->rotationMatrix, &work.delta, &work.delta);
    func_8004F194(&moby->position, &work.point, &work.delta);
}

void func_level_33_800954BC(HudEntry* hud) {
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
int func_level_33_800955B4(HudEntry* hud) {
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

void func_level_33_80095884(HudEntry* hud) {
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

extern int D_80071934;
extern Moby* DecodedQueryCritter __asm__("D_80070578");
int DecodedSegmentWorldQuery(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001830C");
Moby* DecodedSegmentActorQuery(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001AD60");
int func_level_33_80095948(Vector3D* start, Vector3D* end, int flags, int argument) {
    Vector3D delta, current, next;
    register Vector3D* origin __asm__("$17") = start;
    register int count __asm__("$16");
    register int options __asm__("$20");
    register int parameter __asm__("$21");
    int index;
    MATCHING_KEEP(origin);
    options = flags;
    parameter = argument;
    D_80071934 = 0;
    func_8004F1C8(&delta, end, origin);
    if (options & 4)
        delta.z += 0x80;
    count = (func_8004EDE8(&delta, 1) >> 10) + 1;
    if (count >= 2) {
        int x = delta.x / count, y = delta.y / count, z = delta.z / count;
        delta.x = x;
        delta.y = y;
        delta.z = z;
    }
    func_8004F178(&current, origin);
    for (index = 0; index < count; index++) {
        Moby* hit;
        func_8004F194(&next, &current, &delta);
        if (DecodedSegmentWorldQuery(&current, &next, 2, parameter, DecodedQueryCritter) &&
            !D_80071934)
            return 0;
        if ((options & 2) && D_80071934)
            return 0;
        if (options & 1) {
            hit = DecodedSegmentActorQuery(&current, &next, 1, 0, DecodedQueryCritter);
            if (hit && !(hit->difficultyFlags & 0x80))
                return 0;
        }
        func_8004F178(&current, &next);
    }
    return 1;
}

int func_8001AD60(Vector3D*, Vector3D*, int, int, Moby*);
int func_level_33_80095B78(Vector3D* start, Vector3D* end, int flags) {
    Vector3D step, position, next;
    int count, i, result;
    func_8004F1C8(&step, end, start);
    if (flags & 4)
        step.z += 0x80;
    count = (func_8004EDE8(&step, 1) >> 10) + 1;
    if (count >= 2) {
        int x = step.x / count;
        int y = step.y / count;
        int z = step.z / count;
        step.x = x;
        step.y = y;
        step.z = z;
    }
    func_8004F178(&position, start);
    for (i = 0; i < count; i++) {
        func_8004F194(&next, &position, &step);
        result = func_8001AD60(&position, &next, 1, 0, spyro.critterMobyPtr);
        if (result)
            return result;
        func_8004F178(&position, &next);
    }
    return 0;
}

extern int D_8006E044, D_8006E538;
extern unsigned char D_8006E535;
extern int DecodedControlRate __asm__("D_80070328 + 0xA8");
extern int DecodedControlScale __asm__("D_80070328 + 0xAC");
extern int DecodedControlTurn __asm__("D_80070328 + 0xB0");
extern int DecodedControlFlag __asm__("D_80070328 + 0xB8");
extern unsigned char DecodedControlMode __asm__("D_80070328 + 0xFC");
extern int DecodedControlVertical __asm__("D_80070328 + 0xA0");
extern Vector3D DecodedControlWork __asm__("D_80070328 + 0x80");
void func_80040F48(int*, int);
void func_80041404(int);
void func_800417FC(int, int);
void func_8004F168(Vector3D*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
/* Original input scaling, rate approach, and player-relative vector transforms. */
void func_level_33_80095D10(void) {
    int axes[2];
    register int scaled __asm__("$2");
    register int target __asm__("$5");
    register int turn __asm__("$3");
    register int numerator __asm__("$2");
    register int* directionRate __asm__("$3");
    register int* rate __asm__("$6");
    register int* clampRate __asm__("$3");
    register Vector3D* work __asm__("$16");
    register Vector3D* velocity __asm__("$17");
    int product;
    func_80040F48(axes, 1);
    if (D_8006E044 == 40)
        scaled = axes[0] * 30;
    else
        scaled = axes[0] * 20;
    MATCHING_KEEP(scaled);
    target = scaled >> 7;
    if (target == 0) {
        /* Empty constraints retain the original literal-zero store and branch. */
        MATCHING_KEEP(target);
        DecodedControlRate = 0;
        __asm__ volatile("" : :);
    } else if (target < 0) {
        directionRate = &DecodedControlRate;
        MATCHING_KEEP(directionRate);
        if (*directionRate > 0)
            *directionRate = 0;
    } else {
        directionRate = &DecodedControlRate;
        MATCHING_KEEP(directionRate);
        if (*directionRate < 0)
            *directionRate = 0;
    }
    rate = &DecodedControlRate;
    MATCHING_KEEP(rate);
    if (*rate < target) {
        if (D_8006E044 == 40)
            (*rate)++;
        else
            *rate += 4;
        clampRate = &DecodedControlRate;
        MATCHING_KEEP(clampRate);
        if (*clampRate > target)
            *clampRate = target;
    } else {
        if (D_8006E044 == 40)
            (*rate)--;
        else
            *rate -= 4;
        clampRate = &DecodedControlRate;
        MATCHING_KEEP(clampRate);
        if (*clampRate < target)
            *clampRate = target;
    }
    func_80041404(DecodedControlRate);
    if (D_8006E535 && !(D_8006E538 & 12))
        DecodedControlScale = 0;
    else
        DecodedControlScale = 0xF00;
    func_800417FC(192, 192);
    func_8004F168(&DecodedControlWork);
    if (D_8006E538 & 8) {
        numerator = (-DecodedControlTurn * 5) << 9;
        /* Preserve signed truncation after the original 32-bit numerator. */
        turn = numerator / 3840;
        DecodedControlWork.y = turn;
    } else if (D_8006E538 & 4) {
        numerator = (DecodedControlTurn * 5) << 9;
        /* Preserve signed truncation after the original 32-bit numerator. */
        turn = numerator / 3840;
        DecodedControlWork.y = turn;
    }
    product = axes[1] * DecodedControlTurn;
    work = &DecodedControlWork;
    work->x = product >> 7;
    func_8004ED6C((SHORTMATRIX*)((char*)work - 80), work, work);
    velocity = (Vector3D*)((char*)work + 12);
    func_8004F178(velocity, work);
    if (DecodedControlMode || DecodedControlFlag) {
        velocity->z = DecodedControlVertical - 192;
    } else {
        func_8004F194(velocity, velocity, (Vector3D*)((char*)work + 104));
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
typedef struct {
    unsigned int tag;
    unsigned char red, green, blue, code;
    short x0, y0, x1, y1;
} Hud33Line;
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
} Hud33Quad;
extern unsigned char* Hud33PacketCursor __asm__("D_8006C664");

int Hud33Draw(void*) __asm__("func_80029904");
int func_level_33_80095FF0(HudEntry* argument) {
    int x, y, verticalOffset;
    register HudEntry* hud __asm__("$23") = argument;
    register SpriteData* sprite __asm__("$21");
    int colour;
    register int centredY __asm__("$16");
    register int barY __asm__("$22");
    register int top __asm__("$19");
    register int bottom __asm__("$16");
    register int lineCode __asm__("$17");
    register int greenByte __asm__("$8");
    register unsigned int lineTag __asm__("$18");
    register Hud33Line* line __asm__("$20");
    register Hud33Line* lineArgument __asm__("$4");
    register Hud33Quad* quad __asm__("$17");
    register Hud33Quad* quadArgument __asm__("$4");
    register int width __asm__("$21");
    register int* xArg __asm__("$5");
    register int* yArg __asm__("$6");
    __asm__("" : : "r"(hud) : "$5", "$6");
    xArg = &x;
    yArg = &y;
    MATCHING_OBSERVE2(xArg, yArg);
    {
        register int index __asm__("$7") = (unsigned char)hud->unk1C.frame;
        register int initialY __asm__("$2") = hud->unk2;
        register int initialX __asm__("$3");
        register SpriteData* table __asm__("$2");
        MATCHING_KEEP2_CLOBBER(index, initialY, "$3");
        initialX = 2;
        x = initialX;
        MATCHING_BARRIER_VOLATILE("memory");
        initialY += 6;
        MATCHING_KEEP(initialY);
        y = initialY;
        MATCHING_BARRIER_VOLATILE("memory");
        table = D_8006C788;
        __asm__("" : "=r"(table) : "0"(table), "r"(index));
        index *= 8;
        sprite = (SpriteData*)((int)table + index);
    }
    func_80029674(hud, xArg, yArg);
    colour = 91;
    if ((unsigned char)hud->movementFrame) {
        MATCHING_KEEP(colour);
        verticalOffset = ((unsigned char)hud->movementFrame + 10) >> 1;
    } else {
        MATCHING_KEEP(colour);
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
    barY = centredY + 1;
    if (!(*(volatile unsigned char*)((unsigned char*)hud + 24) & 1)) {
        register int edge __asm__("$2") = centredY + sprite->unk5;
        edge -= sprite->unk1;
        barY = edge - 29;
    }
    top = barY - 1;
    if (*(volatile unsigned char*)((unsigned char*)hud + 24) & 8) {
        lineCode = 64;
        line = (Hud33Line*)Hud33PacketCursor;
        MATCHING_KEEP_VOLATILE_CLOBBER(line, "memory");
        lineTag = 0x03000000;
        MATCHING_KEEP(lineTag);
        greenByte = 46;
        MATCHING_KEEP(greenByte);
        line->code = lineCode;
        line->red = colour;
        line->green = greenByte;
        line->blue = 0;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 510;
        func_8004E758(line);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        greenByte = 46;
        MATCHING_KEEP(greenByte);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = greenByte;
        line->blue = 0;
        line->y0 = top;
        MATCHING_BARRIER_VOLATILE("memory");
        {
            register int rawX __asm__("$2") = x;
            MATCHING_KEEP(rawX);
            bottom = barY + 28;
            __asm__("" : "=r"(bottom) : "0"(bottom), "r"(rawX));
            line->y1 = bottom;
            MATCHING_KEEP_VOLATILE_CLOBBER(rawX, "memory");
            rawX += 510;
            line->x1 = rawX;
            line->x0 = rawX;
        }

        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        greenByte = 46;
        MATCHING_KEEP(greenByte);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = greenByte;
        line->blue = 0;
        line->y1 = bottom;
        line->y0 = bottom;
        line->x0 = x - 1;
        line->x1 = x + 510;
        func_8004E758(lineArgument);
        line++;
        MATCHING_KEEP(line);
        {
            register Hud33Line* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            MATCHING_KEEP(lastLine);
            greenByte = 46;
            MATCHING_KEEP(greenByte);
            lastLine->code = lineCode;

            lastLine->red = colour;
            lastLine->green = greenByte;
            lastLine->blue = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (Hud33Quad*)(lastLine + 1);
            MATCHING_KEEP(quad);
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = bottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        quadArgument = quad;
        MATCHING_KEEP(quadArgument);
        {
            register unsigned int rawTag __asm__("$2") = 0x08000000;
            MATCHING_KEEP(rawTag);
            quad->tag = rawTag;
            MATCHING_BARRIER_VOLATILE("memory");
        }
        {
            register int code __asm__("$2") = 56;
            register int red __asm__("$5") = 179;
            register int green __asm__("$3") = 142;
            register int blue __asm__("$2");
            MATCHING_KEEP3(code, red, green);
            quad->code = code;
            blue = 77;
            MATCHING_KEEP(blue);
            quad->red2 = red;
            quad->red0 = red;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->green2 = green;
            quad->green0 = green;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->blue2 = blue;
            quad->blue0 = blue;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->red3 = red;
            quad->red1 = red;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->green3 = green;
            quad->green1 = green;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->blue3 = blue;
            quad->blue1 = blue;
            MATCHING_BARRIER_VOLATILE("memory");
        }
        {
            register int coordinate __asm__("$3") = x;
            register int rawY __asm__("$2");
            MATCHING_KEEP_CLOBBER(coordinate, "$2");
            rawY = barY;
            MATCHING_KEEP2(coordinate, rawY);
            quad->y1 = rawY;
            quad->y0 = rawY;
            quad->y3 = bottom;
            quad->y2 = bottom;
            MATCHING_BARRIER_VOLATILE("memory");
            coordinate += 510;
            quad->x2 = coordinate;
            quad->x0 = coordinate;
            quad->x3 = coordinate;
            quad->x1 = coordinate;
            func_8004E758(quadArgument);
        }
        quad++;
        Hud33PacketCursor = (unsigned char*)quad;
        x += 520;
        Hud33Draw(hud);
        {
            register int spriteWidth __asm__("$2") = sprite->unk4;
            register int left __asm__("$3") = sprite->unk0;
            MATCHING_OBSERVE2(spriteWidth, left);
            spriteWidth -= left;
            MATCHING_KEEP(spriteWidth);
            width = spriteWidth + 520;
        }
    } else {
        {
            register int initialX __asm__("$2") = 2;
            register int right __asm__("$3");
            register int left __asm__("$5");
            __asm__("" : "=r"(initialX) : "0"(initialX) : "$17", "$20");
            lineCode = 64;
            line = (Hud33Line*)Hud33PacketCursor;
            __asm__("" : "=r"(line) : "0"(line) : "$3", "$5");
            right = sprite->unk4;
            left = sprite->unk0;
            MATCHING_KEEP2(right, left);
            lineTag = 0x03000000;
            MATCHING_KEEP(lineTag);
            x = initialX;
            MATCHING_BARRIER_VOLATILE("memory");
            right -= left;
            width = right + 520;
        }
        greenByte = 46;
        MATCHING_KEEP(greenByte);
        line->code = lineCode;
        line->red = colour;
        line->green = greenByte;
        line->blue = 0;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 510;
        func_8004E758(line);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        greenByte = 46;
        MATCHING_KEEP(greenByte);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = greenByte;
        line->blue = 0;
        line->y0 = top;
        MATCHING_BARRIER_VOLATILE("memory");
        {
            register int rawX __asm__("$2") = x;
            MATCHING_KEEP(rawX);
            bottom = barY + 28;
            __asm__("" : "=r"(bottom) : "0"(bottom), "r"(rawX));
            line->y1 = bottom;
            MATCHING_KEEP_VOLATILE_CLOBBER(rawX, "memory");
            rawX += 510;
            line->x1 = rawX;
            line->x0 = rawX;
        }

        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        greenByte = 46;
        MATCHING_KEEP(greenByte);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = greenByte;
        line->blue = 0;
        line->y1 = bottom;
        line->y0 = bottom;
        line->x0 = x - 1;
        line->x1 = x + 510;
        func_8004E758(lineArgument);
        line++;
        MATCHING_KEEP(line);
        {
            register Hud33Line* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            MATCHING_KEEP(lastLine);
            greenByte = 46;
            MATCHING_KEEP(greenByte);
            lastLine->code = lineCode;

            lastLine->red = colour;
            lastLine->green = greenByte;
            lastLine->blue = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (Hud33Quad*)(lastLine + 1);
            MATCHING_KEEP(quad);
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = bottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        quadArgument = quad;
        MATCHING_KEEP(quadArgument);
        {
            register unsigned int rawTag __asm__("$2") = 0x08000000;
            MATCHING_KEEP(rawTag);
            quad->tag = rawTag;
            MATCHING_BARRIER_VOLATILE("memory");
        }
        {
            register int code __asm__("$2") = 56;
            register int red __asm__("$5") = 179;
            register int green __asm__("$3") = 142;
            register int blue __asm__("$2");
            MATCHING_KEEP3(code, red, green);
            quad->code = code;
            blue = 77;
            MATCHING_KEEP(blue);
            quad->red2 = red;
            quad->red0 = red;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->green2 = green;
            quad->green0 = green;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->blue2 = blue;
            quad->blue0 = blue;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->red3 = red;
            quad->red1 = red;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->green3 = green;
            quad->green1 = green;
            MATCHING_BARRIER_VOLATILE("memory");
            quad->blue3 = blue;
            quad->blue1 = blue;
            MATCHING_BARRIER_VOLATILE("memory");
        }
        {
            register int coordinate __asm__("$3") = x;
            register int rawY __asm__("$2");
            MATCHING_KEEP_CLOBBER(coordinate, "$2");
            rawY = barY;
            MATCHING_KEEP2(coordinate, rawY);
            quad->y1 = rawY;
            quad->y0 = rawY;
            quad->y3 = bottom;
            quad->y2 = bottom;
            MATCHING_BARRIER_VOLATILE("memory");
            {
                register int end __asm__("$2") = coordinate + 510;
                quad->x2 = coordinate;
                quad->x0 = coordinate;
                quad->x3 = end;
                quad->x1 = end;
            }
            func_8004E758(quadArgument);
        }
        quad++;
        Hud33PacketCursor = (unsigned char*)quad;
        Hud33Draw(hud);
    }
    return width;
}

extern short D_800719CC;
void func_level_33_8009649C(HudEntry* hud) {
    SpriteData* sprite;
    int scaledValue;

    sprite = &D_8006C788[D_800719CC];
    func_80027D60(hud);
    scaledValue = (int)(*hud->unk28 * 0x64) / (int)hud->unk26;
    hud->unk42 = (unsigned short)scaledValue;
    if (!(scaledValue & 0xFFFF)) {
        hud->unk42 = 1;
    }
    hud->unk40 = hud->unk42;
    hud->unk3C = (unsigned char)hud->unk3C + (((sprite->unk4 - sprite->unk0) * 3) + 0xA);
}

void func_level_33_80096584(HudEntry* value) {
    int* temp_v1;
    int var_v1;

    temp_v1 = value->unk28;
    if ((temp_v1 != 0) && (value->unk42 != 0)) {
        var_v1 = (int)(*temp_v1 * 0x64) / (int)value->unk26;
        if (var_v1 == 0) {
            var_v1 = 1;
        }
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        value->unk42 = (unsigned short)var_v1;
    }
    func_8002798C(value);
}
