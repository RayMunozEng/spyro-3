#include "matching.h"
#include "common.h"
#include "camera.h"
#include "hud.h"
#include "mobyutil.h"
#include "spyro.h"
#include "stdutil.h"
#include "ovl_header.h"

/**
 * ???() - func_level_43_8008B598()
 * https://decomp.me/scratch/luN8U
 */
extern short D_80065920[], D_800658A0[];
extern int D_8006C648;
int func_8004E880(int, int, int);
int func_8003613C(int, int);
int func_8004F264(int, int);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003585C(Moby*, int, int, int, int, int);
int func_80035EE0(Moby*, int, int, int, int, int);
int func_80035DDC(Moby*, int, int, int, int);
int func_level_43_8008B598(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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
 * UpdateActiveCritter() - func_level_43_8008B8B4() - MATCHING
 * https://decomp.me/scratch/QyTEy
 */
extern void func_level_43_8008B8B4(Moby* pCritterMoby, int arg1) {
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
int Controller582CRegisterTrackedValue(void*, int, void*) __asm__("func_8003B7B4");
int Controller582CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller582CTransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Controller582CSoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Controller582CUpdatePlayerRetryState(void) __asm__("func_800498C0");
int Controller582CDispatchPlayerStateRequest(int) __asm__("func_8004BEF8");
/* USA Rev 0, 289 original instructions and eight owned switch-table words.
 * Reuses verified level11/8008582C; target case0 passes 0x1D at 0x80087F84.
 * Units, helper/field semantic chains and caller cadence remain unresolved.
 * Empty compiler constraints contain no opcodes. AI generated; not human reviewed.
 */
int func_level_43_8008B92C(int inputMask) {
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
                    helperArgument = Controller582CLevel;
                    if ((helperArgument == 50 && Controller582CMode == 3) ||
                        (helperArgument == 43 && Controller582CMode == 1)) {
                        D_8006E524 = 15;
                    }
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

/* Only the retail pointer array at +0x3C is described here. */
typedef struct {
    unsigned char reserved00[0x3C];
    unsigned char* frames[1];
} DecodedFrameTable;
extern DecodedFrameTable* D_8006EE2C[];
void func_level_43_8008BE00(Moby* moby, int increment, int* accumulator) {
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
int Controller93E18QueryWorldSegment(void*, void*) __asm__("func_80018368");
int Controller93E18QueryDynamicObjectSegment(void*, void*, int, int,
                                             void*) __asm__("func_8001AD60");
int Controller93E18QueryDynamicMobyGeometry(void*, int, int, int, int,
                                            void*) __asm__("func_8001BA30");
int Controller93E18PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller93E18PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller93E18TransposePackedHalfwordMatrix3x3(void*, void*) __asm__("func_8004ECF4");
int Controller93E18TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller93E18MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Controller93E18ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller93E18CopyVector(void*, void*) __asm__("func_8004F178");
int Controller93E18AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller93E18BuildEulerBasisPair(void*, void*, void*) __asm__("func_8004F6C4");
int Controller93E18AllocateFiveWordSlot(void*, void*, void*, void*, int) __asm__("func_80050B00");
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
void func_level_43_8008BF10(void** inputOwner) {
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
        (resourceResult = Controller93E18AllocateFiveWordSlot(data + 0x8C, data + 0x3B0,
                                                              data + 0x3F4, data + 0x80, 1),
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
            Controller93E18BuildEulerBasisPair(prepared, matrixVector, &frame.alternate[0]);
        }
        Controller93E18TransposePackedHalfwordMatrix3x3(matrixVector, matrixVector);
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
            if (Controller93E18QueryWorldSegment(&frame.first.x, sourceOrVector) != 0) {
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
                    if (Controller93E18QueryDynamicMobyGeometry(
                            Controller93E18Field(data, void**, 0x70) + 0xC, 0x3E8, 3, 0, 0,
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
                if (Controller93E18QueryDynamicObjectSegment(&frame.first.x, sourceOrVector, 0, 0,
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
void func_level_43_8008C498(Moby* moby) {
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

/*
 * ???() - func_level_43_8008C5AC() - MATCHING
 * https://decomp.me/scratch/Jm37m
 */
int func_level_43_8008C5AC(Vector3D* vec, int arg1, Moby* pMoby) {
    int ret;

    ret = (spyro.unk17c == 2);
    spyro.unk17a = 0x10000040;
    spyro.m_WhirlwindPointer = pMoby;
    func_8004F178(&spyro.unk19, vec);
    spyro.unk20[0] = arg1;
    return ret;
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
void func_level_43_8008C620(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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
    short count;
    unsigned char reserved02[0xA];
    PathNode* nodes;
} DecodedNearestPath;
int func_8004F334(Vector3D*, Vector3D*);
int func_level_43_8008CD10(Vector3D* position, DecodedNearestPath* path, int center, int radius) {
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

void func_80055F14(Moby*, int, Vector3D*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_8004F388(int);
void func_80055D24(Moby*, int);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
extern short DecodedOrientationCos[] __asm__("D_80065920");
extern short DecodedOrientationSin[] __asm__("D_800658A0");
void func_level_43_8008CE08(Moby* moby, Moby* source, int index) {
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

void DecodedPolygonSubtract(void*, void*, void*) __asm__("func_8004F1C8");
int DecodedPolygonLength(void*, int) __asm__("func_8004EDE8");
/* Original polygon record: byte count, signed halfword bound, 28-byte entries. */
int func_level_43_8008CFE0(unsigned char* polygonArg, Vector3D* positionArg) {
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
int func_level_43_8008D264(unsigned char* argument, Vector3D* position, int* nearest, int* farthest,
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


/* Rev0 8008D58C..8008D73C,108 original words. Existing Moby and
 * vector/movement helpers reused; callback record stride28 and raw offsets
 * 1C/20, constants4/-1/30/20 follow retail. Work vectors retain raw32-bit
 * components; producer units, callback meaning/effects and caller cadence
 * remain unresolved. Previous-position argument is prepared after callback
 * and rebuilt after correction helpers, as its caller-saved lifetime requires.
 * Empty constraints emit no instructions and retain native GCC2.7.2 register
 * and read/store lifetimes. AI-generated; not yet human reviewed. */
typedef struct {
    Vector3D previous;
    int pad24;
    int index, value;
    Vector3D offset;
    int pad3C;
} DecodedBoundaryWork;
extern int (*DecodedBoundary)(void*, Vector3D*, int*, int*, int) __asm__("unk_ovlheader_80074418");
extern int D_8007190C, D_80071910;
int func_80019194(Vector3D*, int);
int func_8004EDE8(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void* DecodedBoundaryProbe(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
int func_level_43_8008D58C(Moby* mobyArgument, int speedArg, void* boundsArg, int radiusArg) {
    DecodedBoundaryWork work;
    register Moby* moby __asm__("$18");
    register int speed __asm__("$16");
    register void* bounds __asm__("$20");
    register int radius __asm__("$19");
    register int allowed __asm__("$21");
    register Vector3D* position __asm__("$17");
    moby = mobyArgument;
    MATCHING_KEEP(moby);
    speed = speedArg;
    MATCHING_KEEP(speed);
    bounds = boundsArg;
    MATCHING_KEEP(bounds);
    radius = radiusArg;
    MATCHING_KEEP(radius);
    allowed = 1;
    MATCHING_KEEP(allowed);
    position = &moby->position;
    func_8004F178(&work.previous, position);
    /* Keep both boundary callback result paths and original record accesses. */
    func_80035DDC(moby, speed, 0, 0, 4);
    {
        register int inside __asm__("$2") =
            DecodedBoundary(bounds, position, &work.index, &work.value, -1);
        register Vector3D* previousArgument __asm__("$4") = &work.previous;
        if (!inside) {
            register Vector3D* offset __asm__("$16");
            register int* record __asm__("$2");
            register int normalX __asm__("$3");
            register int normalY __asm__("$2");
            func_8004F178(position, &work.previous);
            offset = &work.offset;
            record = (int*)((char*)bounds + work.index * 28);
            MATCHING_KEEP(record);
            normalX = record[7];
            work.offset.x = normalX;
            normalY = record[8];
            MATCHING_KEEP_CLOBBER(normalY, "$21");
            allowed = 0;
            work.offset.z = 0;
            work.offset.y = normalY;
            func_8004F08C(offset, func_8004EDE8(offset, 0), 30);
            func_8004F194(position, position, offset);
            previousArgument = &work.previous;
        }
        func_8004F178(previousArgument, position);
    }
    /* Original probes change only X/Y through these fresh result words. */
    work.previous.z += radius + 20;
    {
        register int hit __asm__("$2") = func_80019194(&work.previous, radius);
        register Vector3D* probePosition __asm__("$4") = position;
        if (hit) {
            moby->position.x = D_8007190C;
            MATCHING_BARRIER_VOLATILE("memory");
            moby->position.y = D_80071910;
        }
        if (DecodedBoundaryProbe(probePosition, radius, 0, 0, 0, moby)) {
            moby->position.x = D_8007190C;
            MATCHING_BARRIER_VOLATILE("memory");
            moby->position.y = D_80071910;
        }
    }
    return allowed;
}

extern int D_80071934;
extern Moby* DecodedQueryCritter __asm__("D_80070578");
int DecodedSegmentWorldQuery(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001830C");
Moby* DecodedSegmentActorQuery(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001AD60");
int func_level_43_8008D73C(Vector3D* start, Vector3D* end, int flags, int argument) {
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
int func_level_43_8008D96C(Vector3D* start, Vector3D* end, int flags) {
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
void func_level_43_8008DB04(void) {
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

/**
 * ???() - func_level_43_8008DDE4() - MATCHING
 * https://decomp.me/scratch/2DGL7
 */
void func_level_43_8008DDE4(HudEntry* arg0) {
    int sp18;
    int sp1C;
    int sp20;
    int sp24;
    int sp28;

    sp18 = arg0->unk0;
    sp1C = arg0->unk2;
    if (arg0->movementFrame != 0) {
        sp20 = (arg0->movementFrame + 10) >> 1;
    } else {
        sp20 = 0;
    }
    func_80029674(arg0, &sp18, &sp1C);
    sp24 = sp18;
    sp28 = sp1C;
    func_80029708(arg0, &sp20, &sp24, &sp28);
    func_800293C4(arg0->unk40, arg0->unk26, sp18, sp1C, sp20);
}
