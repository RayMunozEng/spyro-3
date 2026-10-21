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
int func_level_46_80089764(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

void func_level_46_80089A80(Moby* moby, int mode) {
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
int func_level_46_80089AF8(int inputMask) {
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
void func_level_46_80089F7C(Moby* moby, int increment, int* accumulator) {
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

typedef struct {
    char value[7];
} DecodedBurstChoices;
extern DecodedBurstChoices DecodedBurstChoiceData __asm__("D_level_46_80074A08");
extern int D_8006C578, D_8006C574;
int rand(void);
void func_level_46_8008A08C(Moby* moby, int selection) {
    Colour colour;
    DecodedBurstChoices choices;
    int reservedStack[2];
    register int type __asm__("$18") = 0;
    register int count __asm__("$20") = 0;
    register int lifetime __asm__("$19") = 0;
    int index;
    Moby* spawned;
    int* tag;
    unsigned char* choice;
    register int* sourceTag __asm__("$3");
    MATCHING_KEEP3(type, count, lifetime);
    choices = DecodedBurstChoiceData;
    if (moby->mobyClass == 0x5C) {
        sourceTag = moby->mobyTag;
        MATCHING_KEEP(sourceTag);
        *(int*)&colour = sourceTag[3];
        if (moby->state == 2) {
            type = count;
            count = 4;
            lifetime = 16;
        } else if (moby->state == 4) {
            type = 5;
            count = 1;
            lifetime = 32;
            colour.r = 255;
            colour.g = 255;
            colour.b = 255;
        }
    } else {
        choice = (unsigned char*)choices.value + selection;
        if (selection < 0)
            choice = (unsigned char*)choices.value + func_8003636C(0, 6);
        type = *choice;
        if (type == 3) {
            colour.r = 255;
            colour.g = 0;
            colour.b = 0;
        } else if (type == 4) {
            colour.r = 255;
            colour.g = 255;
            colour.b = 64;
        } else {
            switch (rand() & 3) {
                case 0:
                    colour.r = 255;
                    colour.g = 0;
                    colour.b = 0;
                    break;
                case 1:
                    colour.r = 255;
                    colour.g = 255;
                    colour.b = 0;
                    break;
                case 2:
                    colour.r = 0;
                    colour.g = 255;
                    colour.b = 0;
                    break;
                case 3:
                    colour.r = 255;
                    colour.g = 0;
                    colour.b = 255;
                    break;
            }
        }
        count = 16;
        if (type == 2)
            lifetime = 48;
        else if (type == 3)
            lifetime = 88;
        else
            lifetime = 64;
    }
    colour.a = 63;
    index = 0;
    if (!count)
        goto done;
loop:
    if (D_8006C578 - D_8006C574 < 21)
        goto done;
    spawned = SpawnMoby(0x5C, moby);
    if (spawned) {
        if (type == 4) {
            spawned->state = type;
            spawned->substate = rand() & 3;
        } else
            spawned->state = type;
        if (type == 1)
            spawned->substate = rand() & 15;
        tag = spawned->mobyTag;
        tag[3] = *(int*)&colour;
        tag[4] = lifetime;
    }
    index++;
    if (index < count)
        goto loop;
done:
    return;
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
void func_level_46_8008A32C(void** inputOwner) {
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
void func_level_46_8008A8B4(Moby* moby) {
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
void func_level_46_8008A9C8(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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

void func_80055F14(Moby*, int, Vector3D*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_8004F388(int);
void func_80055D24(Moby*, int);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
extern short DecodedOrientationCos[] __asm__("D_80065920");
extern short DecodedOrientationSin[] __asm__("D_800658A0");
void func_level_46_8008B0B8(Moby* moby, Moby* source, int index) {
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
int func_level_46_8008B290(Moby* owner, int tableSelector, int tableMultiplier, int helperInput,
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

void DecodedPolygonSubtract(void*, void*, void*) __asm__("func_8004F1C8");
int DecodedPolygonLength(void*, int) __asm__("func_8004EDE8");
/* Original polygon record: byte count, signed halfword bound, 28-byte entries. */
int func_level_46_8008B8F8(unsigned char* polygonArg, Vector3D* positionArg) {
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

extern int D_80071934;
extern Moby* DecodedQueryCritter __asm__("D_80070578");
int DecodedSegmentWorldQuery(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001830C");
Moby* DecodedSegmentActorQuery(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001AD60");
int func_level_46_8008BB7C(Vector3D* start, Vector3D* end, int flags, int argument) {
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
int func_level_46_8008BDAC(Vector3D* start, Vector3D* end, int flags) {
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
void func_level_46_8008BF44(void) {
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

INCLUDE_RODATA("asm/nonmatchings/overlays/level_46/level", D_level_46_80074A08);
