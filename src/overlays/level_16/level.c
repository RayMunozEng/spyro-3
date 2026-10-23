#include "matching.h"
#include "common.h"
#include "mobyutil.h"
#include "ovl_header.h"
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
int func_level_16_8007F8AC(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

void func_level_16_8007FBC8(Moby* moby, int mode) {
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
int func_level_16_8007FC40(int inputMask) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_16/level/func_level_16_800800C4.s SHA256 931f50252d4152dcd4ece528bdb7466993a54f9b83b7cbf38acca74367122852. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level16_800C4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level16_800C4_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level16_800C4_D_80065920[0x100] __asm__("D_80065920");
extern Spyro Level16_800C4_D_80070328 __asm__("D_80070328");
extern int Level16_800C4QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
int Level16_800C4TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
int Level16_800C4CountTimerDown(void*, int) __asm__("func_800359A4");
int Level16_800C4ResolveMobyYawStep(Moby* owner19, int private17, int mode18, int arg3,
                                    int arg4) __asm__("func_80035DDC");
int Level16_800C4RandBetween(int low, int high) __asm__("func_8003636C");
extern int Level16_800C4PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level16_800C4AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level16_800C4ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");

extern void* Level16_800C4_D_80071930 __asm__("D_80071930");

void func_level_16_800800C4(Moby* inputOwner, Vector3D* inputPrivate, int inputMode) {
    /* Original 0x50 frame, scratch vector SP18/1C/20 and distinct byte
     * producers are retained. The private helper pointer advances 15 bytes,
     * and the successful probe still performs the original byte stores
     * before entering the shared fallback. The raw modes 0x77 and 0x22,
     * callback flags and final integer blend follow the disc instructions.
     * Empty constraints and comment markers emit no instructions. Memory
     * constraints retain the original LH3/LBU2/LBU4 load order.
     * Helper contracts, physical units/fixed point, frame cadence and runtime
     * capture validation remain unresolved. AI generated;
      not human reviewed. */
    register Moby* owner19 __asm__("$19") = inputOwner;
    register Vector3D* private17 __asm__("$17") = inputPrivate;
    register int mode18 __asm__("$18");

    struct {
        int sp18;
        int sp1C;
        int sp20;
        unsigned char pad24[12];
    } scratch;

    register Vector3D* ownerPosition16 __asm__("$16");
    register int rawRange18 __asm__("$18");
    register int resultFlags16 __asm__("$16");
    register int distance18 __asm__("$18");
    register Vector3D* player16 __asm__("$16");
    register int randArgument4 __asm__("$4");
    register int argument6 __asm__("$6");
    register int one8 __asm__("$8");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register Vector3D* call4 __asm__("$4");
    register Vector3D* call5 __asm__("$5");
    register short* cosine20 __asm__("$20");
    register int cosine21 __asm__("$21");
    register int step16 __asm__("$16");
    int callbackMode;
    int nextByte13;
    register int byte20 __asm__("$20");
    register int state3 __asm__("$3");
    register int initialByte16 __asm__("$16");

    __asm__("" : "=r"(owner19), "=r"(private17), "=r"(mode18) : "0"(owner19), "1"(private17));
    one8 = 1;
    MATCHING_KEEP(one8);
    state3 = Level16_800C4Field(private17, unsigned char*, 0xE);
    initialByte16 = Level16_800C4Field(private17, unsigned char*, 0x10);
    __asm__("" : "=r"(mode18) : "0"(mode18), "r"(state3), "r"(initialByte16));
    __asm__("" : "=r"(state3) : "0"(state3), "r"(initialByte16), "r"(inputMode));
    mode18 = inputMode;
    if (state3 == one8)
        goto state1;
    if (state3 < 2) {
        randArgument4 = -32;
        if (!state3)
            goto state0;
        goto afterDispatch;
    }
    value2 = 2;
    if (state3 == value2)
        goto state2;
    value2 = 3;
    if (state3 == value2)
        goto state3;
    goto afterDispatch;
state0:
    Level16_800C4Field(private17, unsigned char*, 0x13) =
        (unsigned char)(Level16_800C4Field(private17, unsigned char*, 0x13) +
                        Level16_800C4RandBetween(randArgument4, 0x20));
    Level16_800C4Field(private17, signed char*, 0xF) = Level16_800C4RandBetween(0x1E, 0x5A);
    Level16_800C4Field(private17, unsigned char*, 0xE) = 1U;
    goto afterDispatch;
state1:
    MATCHING_KEEP(state3);
    Level16_800C4TurnMobyTowardHeading(
        owner19, (int)Level16_800C4Field(private17, unsigned char*, 0x13),
        (int)Level16_800C4Field(private17, unsigned char*, 0x11), 0, one8, 0);
    if (Level16_800C4CountTimerDown((unsigned char*)private17 + 0xF, 1) != 0) {
        Level16_800C4Field(private17, unsigned char*, 0xE) = 0U;
    }
    goto afterDispatch;
state2:
    if (Level16_800C4TurnMobyTowardHeading(
            owner19, (int)Level16_800C4Field(private17, unsigned char*, 0x13),
            (int)Level16_800C4Field(private17, unsigned char*, 0x11), 8, one8, 0) != 0) {
        call4 = (Vector3D*)30;
        call5 = (Vector3D*)90;
        goto resetPrivateTimer;
    }
    goto functionReturn;
state3:
    value2 = Level16_800C4TurnMobyTowardHeading(
        owner19, (int)Level16_800C4Field(private17, unsigned char*, 19),
        (int)Level16_800C4Field(private17, unsigned char*, 17), 8, one8, 0);
    randArgument4 = 30;
    if (value2) {
        Level16_800C4Field(private17, signed char*, 15) =
            Level16_800C4RandBetween(randArgument4, 90);
        Level16_800C4Field(private17, unsigned char*, 0xE) = 1U;
    }
    initialByte16 = (int)initialByte16 >> 1;
    goto afterDispatch;
afterDispatch:
    call4 = (Vector3D*)owner19;
    if (mode18) {
        __asm__ volatile("# post-dispatch-nonzero");
        call5 = (Vector3D*)initialByte16;
        argument6 = Level16_800C4Field(private17, short*, 12);
        value2 = 119;
    } else {
        __asm__ volatile("# post-dispatch-zero");
        call5 = (Vector3D*)initialByte16;
        argument6 = Level16_800C4Field(private17, short*, 12);
        value2 = 34;
    }
    resultFlags16 =
        Level16_800C4ResolveMobyYawStep((Moby*)call4, (int)call5, argument6, argument6, value2);
    MATCHING_KEEP(resultFlags16);
    argument6 = 0;
    if (resultFlags16 & 1) {
        Level16_800C4Field(private17, unsigned char*, 0x13) = Level16_800C4PlanarHeadingLookup(
            owner19->position.x - Level16_800C4Field(Level16_800C4_D_80071930, int*, 0xC),
            owner19->position.y - Level16_800C4Field(Level16_800C4_D_80071930, int*, 0x10),
            argument6);
        Level16_800C4Field(private17, unsigned char*, 0xE) = 3U;
        return;
    }
    goto checkProbeMode;
probeAccepted:
    value2 = 2;
    Level16_800C4Field(private17, volatile unsigned char*, 0x13) = byte20;
    Level16_800C4Field(private17, unsigned char*, 0xE) = value2;
    goto fallbackByte13;
checkProbeMode:
    __asm__ volatile("" : "=r"(argument6));
    argument6 = (int)&owner19->position;
    if (!mode18)
        goto checkPrivateRange;
    MATCHING_KEEP(argument6);
    value3 = Level16_800C4Field(private17, short*, 12);
    value2 = owner19->angle.yaw;
    MATCHING_BARRIER_VOLATILE("memory");
    call4 = (Vector3D*)Level16_800C4Field(private17, unsigned char*, 16);
    value3 *= 2;
    value2 *= 2;
    value2 = *(short*)((unsigned char*)Level16_800C4_D_80065920 + value2);
    rawRange18 = (int)call4 + value3;
    scratch.sp18 = (value2 * rawRange18) >> 12;
    value2 = Level16_800C4_D_800658A0[owner19->angle.yaw];
    call4 = (Vector3D*)&scratch.sp18;
    call5 = call4;
    scratch.sp20 = 0;
    scratch.sp1C = (value2 * rawRange18) >> 12;
    scratch.sp20 = 128 - owner19->distanceToGround;
    Level16_800C4AddVector(call4, call5, (Vector3D*)argument6);
    call4 = (Vector3D*)&scratch.sp18;
    MATCHING_KEEP(call4);
    cosine20 = Level16_800C4_D_80065920;
    MATCHING_KEEP(cosine20);
    value2 = Level16_800C4QueryWorldHeight(call4, 256);
    if (!value2)
        goto startHeadingSearch;
    value2 = resultFlags16 & 2;
    if (!value2)
        goto checkPrivateRange;
startHeadingSearch:
    step16 = 32;
    cosine21 = (int)cosine20;
    MATCHING_KEEP(cosine21);
probeNextAngle:
    value2 = owner19->angle.yaw;
    value2 += step16;
    byte20 = value2 & 255;
    value3 = byte20 * 2;
    value2 = *(short*)(value3 + cosine21);
    scratch.sp18 = (value2 * rawRange18) >> 12;
    value2 = *(short*)((unsigned char*)Level16_800C4_D_800658A0 + value3);
    call4 = (Vector3D*)&scratch.sp18;
    call5 = call4;
    scratch.sp20 = 0;
    scratch.sp1C = (value2 * rawRange18) >> 12;
    scratch.sp20 = 128 - owner19->distanceToGround;
    Level16_800C4AddVector(call4, call5, &owner19->position);
    value2 = Level16_800C4QueryWorldHeight((Vector3D*)&scratch.sp18, 256);
    step16 += 64;
    if (value2)
        goto probeAccepted;
    if (step16 < 256)
        goto probeNextAngle;
fallbackByte13:
    value2 = owner19->angle.yaw;
    value3 = 2;
    Level16_800C4Field(private17, unsigned char*, 14) = value3;
    nextByte13 = value2 + 128;
    goto storePrivateByte13;
checkPrivateRange:
    ownerPosition16 = &owner19->position;
    if (Level16_800C4Field(private17, unsigned char*, 0xE) != 3) {
        value2 = Level16_800C4ApproximatePlanarDistance(ownerPosition16, private17);
        value3 = Level16_800C4Field(private17, unsigned char*, 18);
        value3 <<= 4;
        value3 = value3 < value2;
        if (value3) {
            Level16_800C4Field(private17, unsigned char*, 0x13) = Level16_800C4PlanarHeadingLookup(
                private17->x - owner19->position.x, private17->y - owner19->position.y, 0);
            call4 = (Vector3D*)30;
            call5 = (Vector3D*)90;
        resetPrivateTimer:
            Level16_800C4Field(private17, signed char*, 15) =
                Level16_800C4RandBetween((int)call4, (int)call5);
            Level16_800C4Field(private17, unsigned char*, 0xE) = 1U;
            return;
        }
        call4 = ownerPosition16;
        player16 = &Level16_800C4_D_80070328.position;
        MATCHING_KEEP(player16);
        distance18 = Level16_800C4ApproximatePlanarDistance(call4, player16);
        MATCHING_KEEP(distance18);
        if (distance18 < 0x1000) {
            value2 = Level16_800C4PlanarHeadingLookup(
                owner19->position.x - player16->x,
                owner19->position.y - Level16_800C4_D_80070328.position.y, 0);
            value3 = Level16_800C4Field(private17, unsigned char*, 19);
            call4 = (Vector3D*)(value3 * distance18);
            value3 = 4096;
            value3 -= distance18;
            value3 = value2 * value3;
            MATCHING_KEEP(value3);
            value2 = (int)call4 + value3;
            nextByte13 = value2 >> 12;
        storePrivateByte13:
            Level16_800C4Field(private17, unsigned char*, 0x13) = (unsigned char)nextByte13;
        }
    } else {
        return;
    }
functionReturn:;
}
#undef Level16_800C4Field

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
void func_level_16_800804F0(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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

extern int D_8006C580;
extern short** D_8006C730;
extern Moby* D_8006C550;
void func_level_16_80080BE0(int index, int substate) {
    if (index < D_8006C580) {
        short* entry = D_8006C730[index];
        do {
            D_8006C550[*entry & 0x7FFF].substate = substate;
        } while (*entry++ >= 0);
    }
}

int rand(void);
int func_8003636C(int, int);
void func_8004EA90(Angle*, SHORTMATRIX*, int);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
void func_8004F0E8(Vector3D*, int);
void func_level_16_80080C58(Vector3D* origin, int particleClass, int count, int low, int high) {
    Vector3D velocity;
    Vector3D position;
    SHORTMATRIX matrix;
    Angle angle;
    int index = 0;
    while (index < count) {
        angle.roll = 0;
        angle.pitch = rand();
        angle.yaw = rand();
        func_8004EA90(&angle, &matrix, 0);
        velocity.x = func_8003636C(low, high);
        velocity.y = 0;
        velocity.z = 0;
        func_8004ED6C(&matrix, &velocity, &velocity);
        func_8004F178(&position, &velocity);
        func_8004F0E8(&position, 2);
        func_8004F194(&position, &position, origin);
        {
            register int kind __asm__("$4") = 1;
            register int selector __asm__("$5") = particleClass;
            register Vector3D* point __asm__("$6") = &position;
            /* Empty constraint retains the original argument/loop scheduling. */
            __asm__("" : "=r"(index) : "0"(index), "r"(kind), "r"(selector), "r"(point));
            index++;
            SpawnParticle(kind, selector, point, &velocity);
        }
    }
}
