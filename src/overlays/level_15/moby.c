#include "matching.h"
#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "mobyutil.h"

/* AI generated; not yet human reviewed. Derived from the original SCUS-94467
 * USA Rev 0 instructions, including all five dispatch targets and padding.
 * Field offsets and integer operations preserve the disc representation.
 * Helper semantics, physical units, and caller update cadence remain unresolved;
 * this routine describes one invocation. Empty constraints preserve compiler
 * allocation/scheduling and emit no instruction or opcode patch.
 */
#define Controller74C50Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller74C50Helper13E38(void*, void*, int) __asm__("func_80013E38");
int Controller74C50Helper19194(void*, int) __asm__("func_80019194");
int Controller74C50Helper1A358(void*, int) __asm__("func_8001A358");
void* Controller74C50Helper2F040(int) __asm__("func_8002F040");
int Controller74C50Helper36188(void*) __asm__("func_80036188");
int Controller74C50Helper36E60(void*) __asm__("func_80036E60");
int Controller74C50Helper37014(void*) __asm__("func_80037014");
int Controller74C50PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller74C50Helper3BFC0(void*, int) __asm__("func_8003BFC0");
int Controller74C50PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller74C50TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller74C50MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Controller74C50Helper4EF74(void*, void*, void*) __asm__("func_8004EF74");
int Controller74C50ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller74C50CopyVector(void*, void*) __asm__("func_8004F178");
int Controller74C50AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller74C50SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Controller74C50MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Controller74C50DivideVector(void*, void*, int) __asm__("func_8004F228");
int Controller74C50AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller74C50ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller74C50Helper4F52C(void*, void*) __asm__("func_8004F52C");
int Controller74C50Helper4F5DC(int, void*) __asm__("func_8004F5DC");
int Controller74C50DeleteMoby(void*) __asm__("func_80055B18");
int Controller74C50RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller74C50Helper56270(void*) __asm__("func_80056270");
int Controller74C50Helper5629C(void*) __asm__("func_8005629C");
extern int Controller74C50D_80065810 __asm__("D_80065810");
extern int Controller74C50D_80065818 __asm__("D_80065818");
extern unsigned char Controller74C50D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller74C50D_80065920[] __asm__("D_80065920");
extern unsigned char Controller74C50D_80066964[] __asm__("D_80066964");
extern unsigned char Controller74C50D_80066988[] __asm__("D_80066988");
extern unsigned char Controller74C50D_80066990[] __asm__("D_80066990");
extern unsigned char Controller74C50D_80066A48[] __asm__("D_80066A48");
extern int Controller74C50D_8006C648 __asm__("D_8006C648");
extern void* Controller74C50D_8006C65C __asm__("D_8006C65C");
extern unsigned char Controller74C50D_8006DEF8[] __asm__("D_8006DEF8");
extern int Controller74C50D_8006E020 __asm__("D_8006E020");
extern int Controller74C50D_8006E024 __asm__("D_8006E024");
extern unsigned short Controller74C50D_8006E040 __asm__("D_8006E040");
extern unsigned char Controller74C50D_80070328[] __asm__("D_80070328");
extern int Controller74C50D_80071908 __asm__("D_80071908");
extern unsigned char Controller74C50D_80071918[] __asm__("D_80071918");
extern int Controller74C50D_8007192C __asm__("D_8007192C");
extern int (*Controller74C50SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
void func_level_15_800749AC(void* input) {
    struct {
        struct {
            int x, y, z;
        } first;
        int p1C;
        struct {
            int x, y, z;
        } second, third, fourth;
        int p44;
        struct {
            int x, y, z;
        } fifth;
        int p54;
        struct {
            int x, y, z;
        } sixth;
        int p64;
        struct {
            int x, y, z;
        } seventh;
        int p74;
        struct {
            int x, y, z;
        } eighth;
        int p84;
        struct {
            int x, y, z;
        } ninth;
        int p94;
        int pad98[4];
    } frame;
    register unsigned char* owner __asm__("$18") = input;
    int thirty;
    register int timer __asm__("$3");
    register int timerCondition __asm__("$2");
    register void* selectorOwner __asm__("$4");
    register int selectorMode __asm__("$5");
    register int ten __asm__("$21");
    register int five __asm__("$23");
    register void* savedPlayer __asm__("$20");
    register void* stateThreeVector __asm__("$19");
    register void* stateThreeDelta __asm__("$16");
    register void* stateTwoNormal __asm__("$21");
    register int temp_v0 __asm__("$2");
    register int temp_v0_4 __asm__("$2");
    register unsigned char* resourceRecord __asm__("$16");
    register unsigned char* workingPosition __asm__("$19");
    register unsigned char* ownerPosition __asm__("$20");
    register unsigned char* selectedResource __asm__("$16");
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    register int sampledHeight __asm__("$16");
    register int distanceResult __asm__("$22");
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    register int var_a0 __asm__("$4");
    register int var_a1 __asm__("$5");
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    signed char signedAngleResult;
    register int temp_s0 __asm__("$16");
    unsigned char temp_v0_2;
    unsigned char temp_v1;
    register int temp_v1_2 __asm__("$3");
    register unsigned char* tag __asm__("$17");
    register unsigned char* callbackTag __asm__("$17");
    void* callbackOwnerReference;
    void* temp_v1_6;

    workingPosition = owner + 0xC;
    tag = Controller74C50Field(owner, void**, 0);
    distanceResult =
        Controller74C50ApproximatePlanarDistance(workingPosition, Controller74C50D_80070328);
    temp_v0 = Controller74C50Field(tag, short*, 0xA);
    MATCHING_KEEP(temp_v0);
    timer = temp_v0;
    timerCondition = temp_v0 < 0x218;
    MATCHING_KEEP_VOLATILE_CLOBBER(timerCondition, "$30");
    thirty = 30;
    if (timerCondition) {
        MATCHING_KEEP(thirty);
        temp_v0 = Controller74C50D_8006C648;
        MATCHING_KEEP(temp_v0);
        temp_v0 = timer + temp_v0;
        Controller74C50Field(tag, short*, 0xA) = temp_v0;
    } else {
        MATCHING_KEEP(thirty);
        MATCHING_BARRIER_VOLATILE("$2");
        selectedResource = 0;
        if (Controller74C50AbsoluteByteAngleDelta(
                (int)(Controller74C50D_8006E040 << 0x10) >> 0x14,
                Controller74C50PlanarHeadingLookup(
                    Controller74C50Field(owner, int*, 0xC) - Controller74C50D_8006E020,
                    Controller74C50Field(owner, int*, 0x10) - Controller74C50D_8006E024, 0)) <
            0x20) {
            selectedResource =
                Controller74C50Helper2F040(Controller74C50Field(owner, unsigned char*, 0x49));
        }
        if (selectedResource != 0) {
            if (distanceResult < 0x3000) {
                Controller74C50Field(tag, unsigned char*, 0x13) =
                    (unsigned char)((int)(selectedResource - Controller74C50D_8006DEF8) >> 4);
                Controller74C50Field(tag, short*, 0xA) =
                    (short)((unsigned short)Controller74C50Field(tag, short*, 0xA) - 0x20);
                Controller74C50Field(tag, unsigned char*, 0x14) =
                    (unsigned char)((Controller74C50Field(owner, unsigned char*, 0x49) * 2) +
                                    (rand() & 1));
            } else {
                Controller74C50CopyVector(selectedResource, workingPosition);
                if (distanceResult <= 0x7FFF) {
                    Controller74C50Field(tag, short*, 0xA) =
                        (short)((unsigned short)Controller74C50Field(tag, short*, 0xA) - 0x80);
                    Controller74C50Field(selectedResource, int*, 8) =
                        (int)(Controller74C50Field(selectedResource, int*, 8) + 0x80);
                } else {
                    Controller74C50Field(tag, short*, 0xA) =
                        (short)((unsigned short)Controller74C50Field(tag, short*, 0xA) - 0x100);
                }
                Controller74C50Field(tag, unsigned char*, 0x13) = 0xFFU;
            }
            Controller74C50Field(selectedResource, unsigned char*, 0xD) =
                (unsigned char)(Controller74C50Field(selectedResource, unsigned char*, 0xD) +
                                (rand() & 0x3F));
        } else {
            Controller74C50Field(tag, short*, 0xA) =
                (short)((unsigned short)Controller74C50Field(tag, short*, 0xA) - 0x100);
        }
        Controller74C50Field(tag, short*, 0xA) =
            (short)((unsigned short)Controller74C50Field(tag, short*, 0xA) - (rand() & 0xFF));
    }
    temp_s0 = Controller74C50Field(tag, unsigned char*, 0x13);
    MATCHING_KEEP(temp_s0);
    selectorOwner = owner;
    if (temp_s0 < 0x10U) {
        MATCHING_KEEP(selectorOwner);
        selectorMode = 4;
        MATCHING_KEEP(selectorMode);
        temp_s0 *= 16;
        MATCHING_KEEP_CLOBBER(temp_s0, "$2");
        {
            register unsigned char* base __asm__("$2") = Controller74C50D_8006DEF8;
            resourceRecord = (unsigned char*)(temp_s0 + (int)base);
        }
        Controller74C50RefreshMobySpatialGridAndBasis(selectorOwner, selectorMode);
        Controller74C50CopyVector(resourceRecord,
                                  (Controller74C50Field(tag, unsigned char*, 0x14) * 0xC) +
                                      (Controller74C50D_80066A48 + 0x30));
        Controller74C50TransformVectorByBasis(owner + 0x20, resourceRecord, resourceRecord);
        Controller74C50AddVector(resourceRecord, resourceRecord, owner + 0xC);
        if ((unsigned char)Controller74C50Field(resourceRecord, unsigned char*, 0xC) < 4U) {
            Controller74C50Field(tag, unsigned char*, 0x13) = 0xFFU;
        }
    }
    if ((Controller74C50Field(owner, unsigned char*, 0x4D) != 0) || (distanceResult < 0x1801) ||
        (Controller74C50Field(owner, unsigned char*, 0x48) != 1) ||
        (Controller74C50Field(tag, unsigned char*, 0x11) != 0)) {
        if (Controller74C50Field(owner, int*, 0x14) < 0x401) {
            Controller74C50CopyVector(owner + 0xC, Controller74C50D_80070328);
        }
        temp_v1 = Controller74C50Field(owner, unsigned char*, 0x48);
        switch (temp_v1) { /* switch 1; irregular */
            case 0:        /* switch 1 */
                Controller74C50CopyVector(&frame.first.x, owner + 0xC);
                frame.first.z += 0x400;
                Controller74C50Helper1A358(&frame.first.x, 0x10000);
                Controller74C50Helper36188(tag + 0xE);
                if (Controller74C50Field(tag, int*, 0xC) & 0xFFFF0000) {
                    Controller74C50Field(owner, unsigned char*, 0x46) = 0U;
                }
                Controller74C50Field(owner, int*, 0x14) = (int)Controller74C50D_80071908;
                Controller74C50Field(tag, short*, 0xA) = (short)((rand() & 0xFF) + 0x100);
                Controller74C50Field(owner, unsigned char*, 0x48) = 1U;
                temp_v0_2 = *(Controller74C50D_80066964 +
                              Controller74C50Field(owner, unsigned char*, 0x50));
                Controller74C50Field(owner, unsigned char*, 0x49) = temp_v0_2;
                Controller74C50Field(owner, unsigned char*, 0x3C) =
                    (unsigned char)*(Controller74C50D_80066988 + (temp_v0_2 & 0xFF));
                Controller74C50Field(owner, unsigned char*, 0x54) = (unsigned char)*(
                    Controller74C50D_80066990 + Controller74C50Field(owner, unsigned char*, 0x49));
                goto block_75;
            case 1: /* switch 1 */
                temp_v1_2 = Controller74C50Field(tag, unsigned char*, 0x11);
                if (temp_v1_2 == 0)
                    goto stateOneTail;
                if (temp_v1_2 == 1) {
                    Controller74C50Helper37014(owner);
                    Controller74C50Helper36188(tag + 0xE);
                    goto stateOneTail;
                }
                if (temp_v1_2 == 2) {
                    Controller74C50Helper4F5DC((short)Controller74C50Field(tag, int*, 0xC),
                                               &frame.second.x);
                    Controller74C50AddVector(&frame.second.x, &frame.second.x, &frame.third.x);
                    Controller74C50AddVector(&frame.second.x, &frame.second.x, &frame.fourth.x);
                    Controller74C50DivideVector(&frame.second.x, &frame.second.x, 3);
                    Controller74C50RefreshMobySpatialGridAndBasis(owner, 2);
                    Controller74C50Helper37014(owner);
                    goto stateOneTail;
                }
                Controller74C50CopyVector(&frame.fifth.x, owner + 0xC);
                frame.fifth.z += 0x400;
                if (Controller74C50Helper1A358(&frame.fifth.x, 0x1000) > 0) {
                    {
                        register int value __asm__("$3") = Controller74C50D_8007192C;
                        register int two __asm__("$2") = 2;
                        MATCHING_KEEP2(value, two);
                        Controller74C50Field(tag, unsigned char*, 0x11) = two;
                        Controller74C50Field(tag, short*, 0xC) = value;
                    }
                }
            stateOneTail:
                if (Controller74C50Field(tag, short*, 0xA) >= 0x1E) {
                    MATCHING_KEEP_VOLATILE_CLOBBER(distanceResult, "$4");
                    temp_a0 = Controller74C50Field(Controller74C50D_80070328, int*, 0x44) + 0x80;
                    if (distanceResult < temp_a0) {
                        temp_v1_3 = Controller74C50Field(Controller74C50D_80070328, int*, 8) -
                                    Controller74C50Field(owner, int*, 0x14);
                        if (temp_v1_3 < temp_a0) {
                            var_v0_2 = -Controller74C50Field(Controller74C50D_80070328, int*, 0x44);
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_v0_2, "$6");
                            var_v0_2 = var_v0_2 < temp_v1_3;
                            goto block_69;
                        }
                    }
                }
                goto block_75;
            case 2: /* switch 1 */
                frame.fifth.x = Controller74C50Field(tag, short*, 4) * Controller74C50D_8006C648;
                frame.fifth.y = Controller74C50Field(tag, short*, 6) * Controller74C50D_8006C648;
                frame.fifth.z = Controller74C50Field(tag, short*, 8) * Controller74C50D_8006C648;
                workingPosition = (unsigned char*)&frame.fifth.x;
                MATCHING_KEEP(workingPosition);
                Controller74C50ShiftVectorRightTowardZero(workingPosition, 1);
                {
                    register void* first __asm__("$4") = workingPosition;
                    MATCHING_KEEP_CLOBBER(first, "$20");
                    ownerPosition = owner + 12;
                    Controller74C50AddVector(first, ownerPosition, workingPosition);
                }
                temp_v0_4 = Controller74C50Field(tag, short*, 8);
                MATCHING_KEEP(temp_v0_4);
                {
                    register int old __asm__("$4") = temp_v0_4;
                    temp_v0_4 = temp_v0_4 < -215;
                    if (!temp_v0_4) {
                        register int delta __asm__("$3") = Controller74C50D_8006C648;
                        register int product __asm__("$2");
                        MATCHING_KEEP2(old, delta);
                        product = delta * 5;
                        product = old - product;
                        Controller74C50Field(tag, short*, 8) = product;
                    }
                }
                if (frame.fifth.z < 0x400) {
                    Controller74C50Helper36E60(owner);
                    Controller74C50DeleteMoby(owner);
                    return;
                }
                frame.fifth.z += 0xF0;
                if (Controller74C50Helper19194(workingPosition, 0xF0) != 0) {
                    stateTwoNormal = &frame.sixth.x;
                    MATCHING_KEEP(stateTwoNormal);
                    Controller74C50CopyVector(stateTwoNormal, Controller74C50D_80071918);
                    Controller74C50CopyVector(ownerPosition, Controller74C50D_80071918 - 0xC);
                    Controller74C50Field(owner, int*, 0x14) =
                        (int)(Controller74C50Field(owner, int*, 0x14) - 0xF0);
                    if (Controller74C50Field(tag, unsigned char*, 0x12) == 0) {
                        {
                            register int height __asm__("$2") =
                                Controller74C50Helper1A358(workingPosition, 0x400);
                            register void* first __asm__("$4") = stateTwoNormal;
                            register int zero __asm__("$5") = 0;
                            register int magnitude __asm__("$5");
                            register int signedAngle __asm__("$2");
                            MATCHING_KEEP2_CLOBBER(first, zero, "$16");
                            sampledHeight = height;
                            magnitude = Controller74C50MeasureVectorLength(first, zero);
                            signedAngle =
                                Controller74C50PlanarHeadingLookup(frame.sixth.z, magnitude, 0);
                            signedAngle <<= 24;
                            MATCHING_KEEP(signedAngle);
                            signedAngleResult = signedAngle >> 24;
                        }
                        if (((frame.fifth.z - 0x190) < sampledHeight) &&
                            (signedAngleResult < 0x18)) {
                            Controller74C50Field(owner, unsigned char*, 0x48) = 1U;
                            Controller74C50CopyVector(ownerPosition, workingPosition);
                            Controller74C50Field(owner, int*, 0x14) = sampledHeight;
                            Controller74C50Helper36188(tag + 0xE);
                            if (Controller74C50Field(tag, int*, 0xC) & 0xFFFF0000) {
                                Controller74C50Field(owner, unsigned char*, 0x46) = 0U;
                            }
                            Controller74C50Field(owner, signed char*, 0x52) = 0;
                            Controller74C50Helper56270(owner);
                            Controller74C50Helper5629C(owner);
                        } else {
                            Controller74C50Field(tag, unsigned char*, 0x12) =
                                (unsigned char)(Controller74C50Field(tag, unsigned char*, 0x12) +
                                                1);
                        }
                        if (Controller74C50Field(tag, unsigned char*, 0x12) != 0) {
                            goto block_52;
                        }
                    } else {
                    block_52:
                        frame.seventh.x = (int)Controller74C50Field(tag, short*, 4);
                        frame.seventh.y = (int)Controller74C50Field(tag, short*, 6);
                        frame.seventh.z = (int)Controller74C50Field(tag, short*, 8);
                        if (Controller74C50Helper4EF74(&frame.seventh.x, &frame.sixth.x,
                                                       &frame.seventh.x) != 0) {
                            Controller74C50Field(tag, unsigned char*, 0x12) =
                                (unsigned char)(Controller74C50Field(tag, unsigned char*, 0x12) -
                                                1);
                            Controller74C50Field(tag, short*, 4) = (short)frame.seventh.x;
                            Controller74C50Field(tag, short*, 6) = (short)frame.seventh.y;
                            Controller74C50Field(tag, short*, 8) = (short)frame.seventh.z;
                            Controller74C50Field(tag, short*, 4) =
                                (short)((((int)((unsigned short)Controller74C50Field(tag, short*, 4)
                                                << 0x10) >>
                                          0x13) +
                                         (rand() & 0x3F)) -
                                        0x20);
                            Controller74C50Field(tag, short*, 6) =
                                (short)((((int)((unsigned short)Controller74C50Field(tag, short*, 6)
                                                << 0x10) >>
                                          0x13) +
                                         (rand() & 0x3F)) -
                                        0x20);
                            Controller74C50Field(tag, short*, 8) =
                                (short)(((int)((unsigned short)Controller74C50Field(tag, short*, 8)
                                               << 0x10) >>
                                         0x12) +
                                        (rand() & 0xF));
                            Controller74C50PlayMobySoundEvent(owner, 1, 0);
                        }
                    }
                } else {
                    frame.fifth.z -= 0xF0;
                    Controller74C50CopyVector(ownerPosition, workingPosition);
                    Controller74C50Helper1A358(workingPosition, 0x10000);
                    Controller74C50Helper5629C(owner);
                }
                MATCHING_BARRIER_VOLATILE("memory");
                if (Controller74C50Field(tag, short*, 0xA) >= 0x1E) {
                    MATCHING_KEEP_VOLATILE_CLOBBER(distanceResult, "$5");
                    temp_a0_2 = Controller74C50Field(Controller74C50D_80070328, int*, 0x44) + 0x80;
                    if (distanceResult < temp_a0_2) {
                        temp_v1_4 = Controller74C50Field(Controller74C50D_80070328, int*, 8) -
                                    Controller74C50Field(owner, int*, 0x14);
                        if (temp_v1_4 < temp_a0_2) {
                            var_v0_2 = -Controller74C50Field(Controller74C50D_80070328, int*, 0x44);
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_v0_2, "$7");
                            var_v0_2 = var_v0_2 < temp_v1_4;
                            goto block_69;
                        }
                    }
                }
                goto block_75;
            case 3: /* switch 1 */
                stateThreeVector = &frame.eighth.x;
                MATCHING_KEEP(stateThreeVector);
                Controller74C50Helper4F52C(stateThreeVector, tag + 4);
                ten = 10;
                MATCHING_KEEP(ten);
                five = 5;
                if (Controller74C50Field(tag, short*, 0xA) >= thirty) {
                    MATCHING_KEEP(five);
                    Controller74C50CopyVector(owner + 0xC, Controller74C50D_80070328);
                } else {
                    MATCHING_KEEP(five);
                    stateThreeDelta = &frame.seventh.x;
                    MATCHING_KEEP_CLOBBER(stateThreeDelta, "$20");
                    {
                        register void* first __asm__("$4") = stateThreeDelta;
                        MATCHING_KEEP_CLOBBER(first, "$20");
                        savedPlayer = Controller74C50D_80070328;
                        Controller74C50SubtractVector(first, savedPlayer, stateThreeVector);
                    }
                    Controller74C50DivideVector(stateThreeDelta, stateThreeDelta, thirty);
                    if (Controller74C50MeasureVectorLength(stateThreeDelta, 1) >= 0x1E1) {
                        Controller74C50CopyVector(owner + 12, savedPlayer);
                        Controller74C50Field(tag, short*, 0xA) = thirty;
                    } else {
                        Controller74C50MultiplyVectorGpfSf0(stateThreeDelta, stateThreeDelta,
                                                            Controller74C50Field(tag, short*, 0xA));
                        Controller74C50AddVector(owner + 0xC, stateThreeVector, stateThreeDelta);
                        Controller74C50Field(owner, int*, 0x14) =
                            (int)(Controller74C50Field(owner, int*, 0x14) +
                                  ((short)*(
                                       unsigned short*)(Controller74C50D_800658A0 +
                                                        (Controller74C50Field(tag, short*, 0xA) *
                                                         five * 2)) /
                                   ten));
                    }
                }
                {
                    register int offset __asm__("$2") =
                        Controller74C50Field(tag, unsigned char*, 0xE);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = Controller74C50Field(owner, unsigned char*, 0x44);
                    offset += 249;
                    old += offset;
                    Controller74C50Field(owner, unsigned char*, 0x44) = old;
                }
                {
                    register int offset __asm__("$2") =
                        Controller74C50Field(tag, unsigned char*, 0xF);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = Controller74C50Field(owner, unsigned char*, 0x45);
                    offset += 249;
                    old += offset;
                    Controller74C50Field(owner, unsigned char*, 0x45) = old;
                }
                {
                    register int offset __asm__("$2") =
                        Controller74C50Field(tag, unsigned char*, 0x10);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = Controller74C50Field(owner, unsigned char*, 0x46);
                    offset += 249;
                    old += offset;
                    Controller74C50Field(owner, unsigned char*, 0x46) = old;
                }
                if ((Controller74C50Field(tag, short*, 0xA) < 0xF) ||
                    (temp_a0_3 = Controller74C50Field(Controller74C50D_80070328, int*, 0x44) + 0x80,
                     ((distanceResult < temp_a0_3) == 0)) ||
                    (temp_v1_5 = Controller74C50Field(Controller74C50D_80070328, int*, 8) -
                                 Controller74C50Field(owner, int*, 0x14),
                     ((temp_v1_5 < temp_a0_3) == 0)) ||
                    (-Controller74C50Field(Controller74C50D_80070328, int*, 0x44) >= temp_v1_5)) {
                    var_v0_2 = Controller74C50Field(tag, short*, 0xA) > thirty;
                    goto block_69;
                }
                goto block_70;
            block_69:
                if (!var_v0_2)
                    goto block_75;
            block_70:
                Controller74C50Field(owner, unsigned char*, 0x48) = 4;
                goto block_75;
            case 4: /* switch 1 */
                if (Controller74C50D_8006C65C != 0) {
                    temp_v1_6 = Controller74C50Field(Controller74C50D_8006C65C, void**, 0);
                    if (Controller74C50Field(temp_v1_6, int*, 0x14) == owner) {
                        Controller74C50Field(temp_v1_6, int*, 0x14) = 0;
                    }
                }
                Controller74C50RefreshMobySpatialGridAndBasis(owner, 4);
                {
                    register int type __asm__("$4") = 4;
                    register int subtype __asm__("$5") = 12;
                    register int (*emit)(int, int, void*, int) __asm__("$2");
                    register int selector __asm__("$7");
                    MATCHING_KEEP2_CLOBBER(type, subtype, "$2");
                    emit = Controller74C50SpawnParticle;
                    MATCHING_KEEP_CLOBBER(emit, "$7");
                    selector = Controller74C50Field(owner, unsigned char*, 0x49);
                    emit(type, subtype, owner, selector);
                }
                Controller74C50Helper36E60(owner);
                Controller74C50PlayMobySoundEvent(owner, 0, 0);
                Controller74C50DeleteMoby(owner);
                goto block_75;
        }
    block_75:
        if ((unsigned char)Controller74C50Field(owner, unsigned char*, 0x48) < 3U) {

                {
                register int sample __asm__("$2") =
                    *(unsigned short*)(Controller74C50D_80065920 +
                                       (Controller74C50Field(tag, unsigned char*, 0x10) * 2));
                register int base __asm__("$3");
                MATCHING_KEEP_CLOBBER(sample, "$3");
                base = Controller74C50Field(tag, unsigned char*, 0xE);
                MATCHING_KEEP2(sample, base);
                sample = (sample << 16) >> 23;
                sample += base;
                Controller74C50Field(owner, unsigned char*, 0x44) = sample;
            }
            {
                register int sample __asm__("$2") =
                    *(unsigned short*)(Controller74C50D_800658A0 +
                                       (Controller74C50Field(tag, unsigned char*, 0x10) * 2));
                register int base __asm__("$3");
                MATCHING_KEEP_CLOBBER(sample, "$3");
                base = Controller74C50Field(tag, unsigned char*, 0xF);
                MATCHING_KEEP2(sample, base);
                sample = (sample << 16) >> 23;
                sample += base;
                Controller74C50Field(owner, unsigned char*, 0x45) = sample;
            }
            Controller74C50Field(tag, unsigned char*, 0x10) =
                (unsigned char)(Controller74C50Field(tag, unsigned char*, 0x10) +
                                (Controller74C50D_8006C648 * 2));
            var_a1 = Controller74C50D_80065810;
            {
                register int state __asm__("$3") =
                    Controller74C50Field(Controller74C50D_80070328, int*, 0x50);
                if (state == 6)
                    goto commonIncreasedThreshold;
                {
                    register unsigned int index __asm__("$2") = state - 11;
                    MATCHING_KEEP(index);
                    if (index < 2) {
                        register int source __asm__("$3") = Controller74C50D_80065818;
                        register int product __asm__("$2") = (var_a1 << 1) + var_a1;
                        MATCHING_KEEP2(source, product);
                        var_a1 = product >> 1;
                        var_a0 = source + 512;
                        goto commonThresholdReady;
                    }
                }
                state = Controller74C50Field(Controller74C50D_80070328, int*, 0x24C);
                if (state != 3)
                    goto commonNormalThreshold;
            }
        commonIncreasedThreshold:
            {
                register int source __asm__("$2") = Controller74C50D_80065818;
                MATCHING_KEEP(source);
                var_a0 = source + 512;
                goto commonThresholdReady;
            }
        commonNormalThreshold:
            var_a0 = Controller74C50D_80065818;
        commonThresholdReady:
            if (({
                    register int inRange __asm__("$2") = distanceResult < var_a1;
                    MATCHING_KEEP(inRange);
                    inRange;
                })) {
                {
                    register int height __asm__("$3") = Controller74C50Field(owner, int*, 0x14);
                    register int playerZ __asm__("$2") =
                        Controller74C50Field(Controller74C50D_80070328, int*, 8);
                    MATCHING_KEEP2(height, playerZ);
                    height += 356;
                    var_v0 = playerZ - height;
                }
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < var_a0) && (Controller74C50D_8006C65C != 0) &&
                    ((Controller74C50Field(owner, unsigned char*, 0x48) != 2) ||
                     ((unsigned char)Controller74C50Field(tag, unsigned char*, 0x12) < 3U)) &&
                    (callbackTag = Controller74C50Field(Controller74C50D_8006C65C, void**, 0),
                     Controller74C50CopyVector(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64,
                     (Controller74C50Helper13E38(Controller74C50D_8006C65C + 0xC, &frame.ninth.x,
                                                 0) != 0))) {
                    callbackOwnerReference = Controller74C50Field(callbackTag, void**, 0x14);
                    if (callbackOwnerReference != 0) {
                        if ((callbackOwnerReference != owner) &&
                            (Controller74C50Field(callbackTag, short*, 0) > 0)) {
                            Controller74C50Field(callbackTag, short*, 0) = 0;
                            return;
                        }
                    } else {
                        Controller74C50Field(Controller74C50D_8006C65C, signed char*, 0x49) = 4;
                        {
                            register void* callbackOwner __asm__("$4") = Controller74C50D_8006C65C;
                            register int selector __asm__("$5") =
                                Controller74C50Field(callbackTag, unsigned char*, 2);
                            MATCHING_KEEP2_CLOBBER(callbackOwner, selector, "memory");
                            Controller74C50Field(callbackTag, void**, 0x14) = owner;
                            Controller74C50Field(callbackTag, short*, 0) = 0;
                            if (Controller74C50Helper3BFC0(callbackOwner, selector) == 0) {
                                Controller74C50Field(callbackTag, unsigned char*, 2) =
                                    Controller74C50PlayMobySoundEvent(Controller74C50D_8006C65C, 0,
                                                                      0);
                            }
                        }
                    }
                }
            }
        }
    }
}

#undef Controller74C50Field


/* AI generated; not yet human reviewed. Derived from SCUS-94467 USA Rev 0
 * original instructions and all five dispatch tables, including padding.
 * Offsets, signedness, shifts, and integer operations preserve the disc data.
 * Physical units, helper meanings, and caller cadence remain unresolved;
 * this routine describes one invocation. Empty compiler constraints preserve
 * proven register allocation and scheduling without emitting instructions.
 */
extern unsigned char Controller75F38TablePlayer[] __asm__("D_80070328");
#define Controller75F38Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller75F38Helper19194(void*, int) __asm__("func_80019194");
void* Controller75F38Helper2EC50(int, int, int) __asm__("func_8002EC50");
int Controller75F38RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller75F38EmptyAnimationTransitionHook(void*, int) __asm__("func_80035734");
int Controller75F38TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Controller75F38CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller75F38Helper36018(int, int, int) __asm__("func_80036018");
unsigned int Controller75F38RandBetween(int, int) __asm__("func_8003636C");
int Controller75F38PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller75F38Helper3BFC0(void*, int) __asm__("func_8003BFC0");
int Controller75F38PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller75F38Helper4EA74(int) __asm__("func_8004EA74");
int Controller75F38Helper4ECF4(void*, void*) __asm__("func_8004ECF4");
int Controller75F38TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller75F38MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Controller75F38NormalizeVectorToLength(void*, int) __asm__("func_8004EF04");
int Controller75F38ScaleVectorRatioQ15(void*, int, int) __asm__("func_8004F08C");
int Controller75F38ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller75F38CopyVector(void*, void*) __asm__("func_8004F178");
int Controller75F38AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller75F38SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Controller75F38SignedByteAngleDelta(int, int) __asm__("func_8004F2A4");
int Controller75F38ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller75F38PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
int Controller75F38Helper4F554(void*, void*) __asm__("func_8004F554");
int Controller75F38DeleteMoby(void*) __asm__("func_80055B18");
int Controller75F38RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller75F38InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern unsigned char Controller75F38D_80065830[] __asm__("D_80065830");
extern unsigned char Controller75F38D_8006585C[] __asm__("D_8006585C");
extern unsigned char Controller75F38D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller75F38D_80065920[] __asm__("D_80065920");
extern unsigned char Controller75F38D_8006E00C[] __asm__("D_8006E00C");
extern unsigned char Controller75F38D_80070328[] __asm__("D_80070328");
extern unsigned char Controller75F38D_8007190C[] __asm__("D_8007190C");
extern int Controller75F38D_8006580C __asm__("D_8006580C");
extern int Controller75F38D_80065814 __asm__("D_80065814");
extern int Controller75F38D_80065820 __asm__("D_80065820");
extern int Controller75F38D_80065828 __asm__("D_80065828");
extern int Controller75F38D_8006C644 __asm__("D_8006C644");
extern int Controller75F38D_8006C648 __asm__("D_8006C648");
extern int Controller75F38D_8006C65C __asm__("D_8006C65C");
extern int Controller75F38D_8006C770 __asm__("D_8006C770");
extern int Controller75F38D_8006C784 __asm__("D_8006C784");
extern int Controller75F38D_8006E020 __asm__("D_8006E020");
extern int Controller75F38D_8006E024 __asm__("D_8006E024");
extern int Controller75F38D_8006E044 __asm__("D_8006E044");
extern int Controller75F38D_8006E538 __asm__("D_8006E538");
extern void* Controller75F38D_8006C550 __asm__("D_8006C550");
extern unsigned short Controller75F38D_8006E040 __asm__("D_8006E040");
extern unsigned char Controller75F38D_8006E534 __asm__("D_8006E534");
extern void* (*Controller75F38SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int (*Controller75F38SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
extern int (*Controller75F38Callback)(void*, void*, int, int, int, int, int, int, int, int, int,
                                      int, int) __asm__("unk_ovlheader_80074314");
void func_level_15_80075608(void* input) {
    register unsigned char* owner __asm__("$20") = input;
    struct {
        struct {
            int x, y, z;
        } first;
        int p44;
        struct {
            int x, y, z;
        } second;
        int p54;
        struct {
            int x, y, z;
        } third;
        int p64;
        struct {
            int x, y, z;
        } fourth;
        int p74;
        struct {
            int x, y, z;
        } fifth;
        int p84;
        int matrix[6];
        struct {
            int x, y, z;
        } sixth;
        int padAC[1];
    } frame;
    short temp_a0_2;
    short temp_a0_7;
    short temp_v0_12;
    register int temp_v1_10 __asm__("$3");
    register int var_v0_8 __asm__("$2");
    int var_v0_9;
    unsigned char* temp_a0_4;
    unsigned char* temp_a0_5;
    unsigned char* temp_a0_6;
    unsigned char* temp_a1;
    unsigned char* temp_a2;
    register unsigned char* temp_s0_2 __asm__("$16");
    register unsigned char* temp_s0_4 __asm__("$16");
    register unsigned char* temp_s0_5 __asm__("$16");
    register unsigned char* temp_s1 __asm__("$17");
    register unsigned char* ownerPosition __asm__("$22");
    unsigned char* temp_v0_11;
    register unsigned char* temp_v0_8 __asm__("$2");
    unsigned char* temp_v1_2;
    register unsigned char* var_a2_5 __asm__("$6");
    register void* matrixFirst __asm__("$4");
    register void* matrixSecond __asm__("$5");
    register void* commonOwner __asm__("$4");
    register void* movementPosition __asm__("$4");
    register int movementRadius __asm__("$5");
    register int temp_a1_4 __asm__("$5");
    register int temp_s0 __asm__("$16");
    register int magnitudeDelta __asm__("$16");
    register unsigned char* temp_s1_3 __asm__("$17");
    register int initialMagnitude __asm__("$17");
    register int adjustedMagnitude __asm__("$17");
    register int adjustedAngle __asm__("$21");
    register int temp_v0_10 __asm__("$5");
    int temp_v0_5;
    int temp_v0_6;
    register int temp_v0_9 __asm__("$5");
    int temp_v1;
    int temp_v1_14;
    int temp_v1_5;
    register int temp_v1_8 __asm__("$3");
    register int var_a0_2 __asm__("$4");
    register int var_a0_3 __asm__("$4");
    register int tailMagnitude __asm__("$2");
    register int var_a0_4 __asm__("$4");
    register int var_a1 __asm__("$5");
    int var_a1_2;
    register int var_a2 __asm__("$6");
    register int var_a2_2 __asm__("$6");
    register int var_a2_3 __asm__("$6");
    register int var_a2_4 __asm__("$6");
    register int verticalStep __asm__("$16");
    register int var_v0 __asm__("$2");
    register int var_v0_10 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int thirdY __asm__("$3");
    register int scanEnabled __asm__("$2");
    register unsigned char* candidateBase __asm__("$5");
    register unsigned char* candidateRecords __asm__("$18");
    register int var_v0_3 __asm__("$2");
    int var_v0_5;
    int var_v0_6;
    int var_v0_7;
    register int var_v1 __asm__("$3");
    register int var_v1_2 __asm__("$3");
    register unsigned int temp_s0_3 __asm__("$16");
    unsigned int temp_v0_13;
    register unsigned char* var_s0 __asm__("$16");
    register int temp_a0_3 __asm__("$4");
    int temp_a1_2;
    register int temp_a1_3 __asm__("$5");
    register int temp_s1_2 __asm__("$17");
    register int initialAngle __asm__("$21");
    register int originalAngle __asm__("$23");
    int temp_v0_4;
    register int temp_v0_7 __asm__("$2");
    unsigned char temp_v1_11;
    unsigned char temp_v1_12;
    unsigned char temp_v1_13;
    register int temp_v1_4 __asm__("$3");
    unsigned char temp_v1_6;
    int temp_v1_7;
    register int temp_v1_9 __asm__("$3");
    register int stateValue __asm__("$2");
    unsigned char var_a0;
    register int var_a1_3 __asm__("$5");
    register int var_v0_11 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    register void* temp_a0 __asm__("$4");
    register void* tag __asm__("$19");
    register void* temp_v0 __asm__("$2");
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v1_15;
    void* temp_v1_3;
    register void* var_s1 __asm__("$17");

    tag = Controller75F38Field(owner, void**, 0);
    originalAngle = Controller75F38Field(owner, unsigned char*, 0x46);
    if (((unsigned int)(Controller75F38Field(Controller75F38D_80070328, int*, 0x50) - 0xB) < 2U) &&
        (Controller75F38Field(tag, unsigned char*, 0xA) == 0) &&
        (Controller75F38Field(owner, unsigned char*, 0x4D) != 0)) {
        {
            register int one __asm__("$6");
            register int model __asm__("$5");
            register int value __asm__("$3");
            temp_v0 = Controller75F38SpawnMoby(0xAA, owner);
            temp_a0 = Controller75F38Field(temp_v0, void**, 0);
            MATCHING_KEEP_CLOBBER(temp_a0, "$6");
            one = 1;
            __asm__("" : "=r"(temp_a0), "=r"(one) : "0"(temp_a0), "1"(one) : "$3", "$5");
            Controller75F38Field(temp_a0, void**, 4) = owner;
            Controller75F38Field(temp_a0, unsigned char*, 0) = one;
            __asm__ volatile("" ::: "$3", "memory");
            model = Controller75F38Field(owner, unsigned short*, 0x36);
            MATCHING_KEEP_CLOBBER(model, "$3");
            value = 28;
            MATCHING_KEEP(value);
            Controller75F38Field(temp_a0, short*, 2) = value;
            value = 127;
            MATCHING_KEEP2_CLOBBER(value, model, "memory");
            Controller75F38Field(temp_a0, unsigned char*, 1) = model;
            Controller75F38Field(temp_v0, unsigned char*, 0x4F) = value;
            value = 7;
            MATCHING_KEEP(value);
            Controller75F38Field(temp_v0, unsigned char*, 0x47) = value;
            Controller75F38Field(tag, unsigned char*, 0xA) = one;
        }
    }
    if ((Controller75F38Field(Controller75F38D_80070328, int*, 0x280) >= 2) &&
        (Controller75F38Field(owner, unsigned char*, 0x4D) != 0)) {
        {
            register void* particleVector __asm__("$16") = &frame.second.x;
            register void* first __asm__("$4") = particleVector;
            register int angleIndex __asm__("$3") =
                Controller75F38Field(owner, unsigned char*, 0x46);
            register void* second __asm__("$5");
            register int sample __asm__("$6");
            register int value __asm__("$2");
            register int otherSample __asm__("$3");
            register void* third __asm__("$6");
            MATCHING_KEEP2_CLOBBER(first, angleIndex, "$5");
            second = &frame.first.x;
            MATCHING_KEEP_CLOBBER(second, "$17");
            angleIndex = ((angleIndex + 64) & 255) * 2;
            sample = *(short*)(Controller75F38D_80065920 + angleIndex);
            MATCHING_KEEP_CLOBBER(sample, "$17");
            temp_s1 = owner + 12;
            value = (sample * 25) >> 10;
            frame.first.x = value;
            otherSample = *(short*)(Controller75F38D_800658A0 + angleIndex);
            MATCHING_KEEP_CLOBBER(otherSample, "$6");
            third = temp_s1;
            frame.first.z = 0;
            __asm__ volatile("" ::: "$2", "memory");
            value = (otherSample * 25) >> 10;
            frame.first.y = value;
            Controller75F38AddVector(first, second, third);
            Controller75F38SpawnParticle(2, 0x42, particleVector, 0);
            Controller75F38SubtractVector(particleVector, temp_s1, &frame.first.x);
            Controller75F38SpawnParticle(2, 0x42, particleVector, 0);
        }
    }
    if ((Controller75F38Field(Controller75F38D_80070328, int*, 0x280) >= 3) &&
        (Controller75F38Field(owner, unsigned char*, 0x4C) != 0)) {
        if (Controller75F38Field(tag, void**, 0x10) == 0) {
            Controller75F38Field(tag, void**, 0x10) = Controller75F38Helper2EC50(1, 0x40, 0x489090);
        }
    } else {
        temp_v0_2 = Controller75F38Field(tag, void**, 0x10);
        if (temp_v0_2 != 0) {
            Controller75F38Field(temp_v0_2, signed char*, 0x10) = 0;
            Controller75F38Field(tag, void**, 0x10) = 0;
        }
    }
    temp_a1 = Controller75F38D_80070328 + 0x280;
    if (Controller75F38Field(Controller75F38D_80070328, int*, 0x280) <= 0) {
        temp_v1_2 = Controller75F38Field(tag, unsigned char**, 0x14);
        if ((temp_v1_2 != 0) &&
            ((unsigned char)Controller75F38Field(temp_v1_2, unsigned char*, 0x48) < 0x80U) &&
            ((temp_a0_2 = Controller75F38Field(temp_v1_2, short*, 0x36), (temp_a0_2 == 0x10)) ||
             (temp_a0_2 == 0xD3))) {
            Controller75F38Field(temp_v1_2, unsigned char*, 0x48) = 0U;
        }
        temp_v0_3 = Controller75F38Field(tag, void**, 0x10);
        Controller75F38D_8006C65C = 0;
        if (temp_v0_3 != 0) {
            Controller75F38Field(temp_v0_3, signed char*, 0x10) = 0;
            Controller75F38Field(tag, void**, 0x10) = 0;
        }
        Controller75F38DeleteMoby(owner);
        return;
    }
    if ((Controller75F38Field(tag, unsigned char**, 0x14) != 0) &&
        (Controller75F38ApproximatePlanarDistance(owner + 0xC, temp_a1 - 0x280) >= 0xC01)) {
        Controller75F38Field(tag, short*, 0) = 0;
    }
    temp_v1_3 = Controller75F38Field(tag, void**, 0x10);
    if (temp_v1_3 != 0) {
        Controller75F38Field(temp_v1_3, signed char*, 0x13) = 4;
    }
    scanEnabled = Controller75F38D_80065820;
    MATCHING_KEEP_CLOBBER(scanEnabled, "$5");
    candidateBase = Controller75F38D_80065830;
    MATCHING_KEEP2(scanEnabled, candidateBase);
    Controller75F38Field(candidateBase, void**, 0) = 0;
    if ((scanEnabled != 0) && ((Controller75F38D_8006E538 & 0xE) == 0xE)) {
        var_s1 = Controller75F38D_8006C550;
        var_a0 = Controller75F38Field(var_s1, unsigned char*, 0x48);
        if ((var_a0 & 0xFF) != 0xFF) {
            candidateRecords = candidateBase;
            MATCHING_KEEP_CLOBBER(candidateRecords, "$16");
            var_s0 = var_s1 + 0x48;
            do {
                if ((unsigned int)(var_a0 & 255) < 128) {
                    if (Controller75F38Field(var_s0, short*, -0x12) == 1)
                        goto eligibleCandidate;
                    temp_v1_4 = Controller75F38Field(var_s0, unsigned char*, 8);
                    {
                        register unsigned int index __asm__("$2") = temp_v1_4 - 1;
                        index = index < 2;
                        MATCHING_KEEP_CLOBBER(index, "$4");
                        MATCHING_KEEP(temp_v1_4);
                        temp_v1_4 &= 255;
                        if (index)
                            goto eligibleCandidate;
                        if (temp_v1_4 == 5)
                            goto eligibleCandidate;
                        if (temp_v1_4 == 10)
                            goto eligibleCandidate;
                        if (temp_v1_4 != 25)
                            goto nextCandidate;
                    }
                eligibleCandidate:
                    MATCHING_BARRIER_VOLATILE("$4");
                    Controller75F38SubtractVector(&frame.first.x, var_s1 + 0xC,
                                                  Controller75F38D_80070328);
                    var_a0_2 = frame.first.x;
                    var_v1 = frame.first.y;
                    var_v0 = frame.first.z;
                    MATCHING_KEEP3(var_a0_2, var_v1, var_v0);
                    if (var_a0_2 < 0) {
                        var_a0_2 = -var_a0_2;
                    }
                    if (var_v1 < 0) {
                        var_v1 = -var_v1;
                    }
                    var_a0_2 += var_v1;
                    MATCHING_KEEP2(var_a0_2, var_v0);
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    var_a0_3 = var_a0_2 + var_v0;
                    if (var_a0_3 < 0x4000) {
                        var_a0_3 = Controller75F38MeasureVectorLength(&frame.first.x, 1);
                    }
                    if ((Controller75F38Field(candidateRecords, void**, 0) == 0) ||
                        (var_a0_3 < Controller75F38Field(candidateRecords, int*, -8))) {
                        Controller75F38Field(candidateRecords, void**, 0) = var_s1;
                        Controller75F38Field(candidateRecords, int*, -8) = var_a0_3;
                    }
                }
            nextCandidate:
                var_s0 += 0x58;
                var_a0 = *var_s0;
                var_s1 += 0x58;
            } while ((var_a0 & 0xFF) != 0xFF);
        }
    }
    if (Controller75F38Field(tag, unsigned char**, 0x14) != 0) {
        temp_v1_6 = Controller75F38Field(owner, unsigned char*, 0x49);
        switch (temp_v1_6) { /* switch 1 */
            case 0:          /* switch 1 */
                temp_s1_2 = Controller75F38Field(owner, unsigned char*, 0x3D);
                Controller75F38CopyVector(&frame.third.x,
                                          Controller75F38Field(tag, unsigned char**, 0x14) + 0xC);
                if (temp_s1_2 == 0) {
                    MATCHING_KEEP_VOLATILE(temp_s1_2);
                    frame.third.x -= (int)(*(unsigned short*)(Controller75F38D_80065920 +
                                                              (Controller75F38Field(
                                                                   Controller75F38Field(
                                                                       tag, unsigned char**, 0x14),
                                                                   unsigned char*, 0x46) *
                                                               2))
                                           << 0x10) >>
                                     0x14;
                    var_v0_2 =
                        *(unsigned short*)(Controller75F38D_800658A0 +
                                           (Controller75F38Field(
                                                Controller75F38Field(tag, unsigned char**, 0x14),
                                                unsigned char*, 0x46) *
                                            2));
                    MATCHING_KEEP_CLOBBER(var_v0_2, "$3");
                    thirdY = frame.third.y;
                    MATCHING_KEEP2(var_v0_2, thirdY);
                    var_v0_2 = (var_v0_2 << 16) >> 0x14;
                } else {
                    frame.third.x -= (int)(*(unsigned short*)(Controller75F38D_80065920 +
                                                              (Controller75F38Field(
                                                                   Controller75F38Field(
                                                                       tag, unsigned char**, 0x14),
                                                                   unsigned char*, 0x46) *
                                                               2))
                                           << 0x10) >>
                                     0x16;
                    var_v0_2 =
                        *(unsigned short*)(Controller75F38D_800658A0 +
                                           (Controller75F38Field(
                                                Controller75F38Field(tag, unsigned char**, 0x14),
                                                unsigned char*, 0x46) *
                                            2));
                    MATCHING_KEEP_CLOBBER(var_v0_2, "$3");
                    thirdY = frame.third.y;
                    MATCHING_KEEP2(var_v0_2, thirdY);
                    var_v0_2 = (var_v0_2 << 16) >> 0x16;
                }
                thirdY -= var_v0_2;
                frame.third.y = thirdY;
                if (temp_s1_2 != 0) {
                    if ((unsigned char)Controller75F38Field(owner, unsigned char*, 0x3F) >= 7U) {
                        Controller75F38Field(owner, unsigned char*, 0x49) =
                            (unsigned char)(Controller75F38Field(owner, unsigned char*, 0x49) + 1);
                    }
                    temp_a0_3 = Controller75F38Field(owner, unsigned char*, 0x45);
                    var_v1_2 = -(int)temp_a0_3;
                    if ((unsigned int)((temp_a0_3 - 3) & 0xFF) < 0xFBU) {
                        var_v0_3 = var_v1_2 < 3;
                        if (var_v0_3) {
                            var_v0_3 = var_v1_2 < -2;
                        } else {
                            var_v1_2 = 2;
                            MATCHING_KEEP(var_v1_2);
                            var_v0_3 = var_v1_2 < -2;
                        }
                        if (var_v0_3) {
                            var_v1_2 = -2;
                            MATCHING_KEEP(var_v1_2);
                            var_v0_3 = temp_a0_3 + var_v1_2;
                        } else
                            var_v0_3 = temp_a0_3 + var_v1_2;
                        Controller75F38Field(owner, unsigned char*, 0x45) = var_v0_3;
                    }
                }
                temp_s0_2 = (unsigned char*)&frame.third.x;
                MATCHING_KEEP(temp_s0_2);
                Controller75F38SubtractVector(temp_s0_2, temp_s0_2, owner + 12);
                temp_s0 = Controller75F38MeasureVectorLength(temp_s0_2, 1);
                if ((temp_s1_2 == 0) && (Controller75F38CountTimerDown(tag, 2) != 0)) {
                    MATCHING_KEEP_VOLATILE(temp_s1_2);
                    if (Controller75F38Helper3BFC0(
                            owner, Controller75F38Field(tag, unsigned char*, 2)) == 0) {
                        Controller75F38Field(tag, unsigned char*, 2) =
                            Controller75F38PlayMobySoundEvent(owner, 0, 0);
                    }
                    if (Controller75F38Field(owner, unsigned char*, 0x3D) != 1) {
                        Controller75F38D_8006C770 = 0;
                        temp_v1_7 = Controller75F38Field(owner, unsigned char*, 0x3D);
                        temp_a1_2 = Controller75F38Field(owner, unsigned char*, 0x3F);
                        Controller75F38Field(owner, signed char*, 0x40) = 0x72;
                        Controller75F38Field(owner, unsigned char*, 0x3D) = 1U;
                        Controller75F38Field(owner, unsigned char*, 0x3F) = 0U;
                        Controller75F38Field(owner, unsigned char*, 0x3C) = temp_v1_7;
                        Controller75F38Field(owner, unsigned char*, 0x3E) = temp_a1_2;
                        Controller75F38EmptyAnimationTransitionHook(owner, temp_a1_2);
                    }
                }
                var_a2 = 0x82;
                if (temp_s1_2 != 0) {
                    var_a2 = 0x96;
                }
                temp_v1_8 = var_a2 + 5;
                {
                    register void* adjustedVector __asm__("$4");
                    register int magnitude __asm__("$5");
                    if (temp_v1_8 < temp_s0) {
                        adjustedVector = &frame.third.x;
                        magnitude = temp_s0;
                        MATCHING_KEEP2(adjustedVector, magnitude);
                        var_a2_2 = temp_v1_8;
                        goto stateZeroAdjust;
                    }
                    adjustedVector = &frame.third.x;
                    magnitude = temp_s0;
                    MATCHING_KEEP2(adjustedVector, magnitude);
                    var_a2_2 = var_a2 - 5;
                stateZeroAdjust:
                    Controller75F38ScaleVectorRatioQ15(adjustedVector, magnitude, var_a2_2);
                }
                {
                    register void* first __asm__("$4") = owner + 12;
                    register void* second __asm__("$5") = first;
                    __asm__(""
                            : "=r"(first), "=r"(second)
                            : "0"(first), "1"(second)
                            : "$16", "$17");
                    temp_s0_2 = (unsigned char*)&frame.third.x;
                    MATCHING_KEEP(temp_s0_2);
                    Controller75F38AddVector(first, second, temp_s0_2);
                }
                Controller75F38TurnMobyTowardHeading(
                    owner, Controller75F38PlanarHeadingLookup(frame.third.x, frame.third.y, 0),
                    0xAU, 0, 0, 0);
                tailMagnitude = Controller75F38MeasureVectorLength(temp_s0_2, 0);
                MATCHING_KEEP_VOLATILE_CLOBBER(tailMagnitude, "$6");
                var_a0_4 = tailMagnitude;
                var_a1 = frame.third.z;
                goto block_97;
            case 1: /* switch 1 */
                if (Controller75F38Field(Controller75F38Field(tag, unsigned char**, 0x14), short*,
                                         0x36) == 0x10) {
                    temp_v0_5 = Controller75F38Field(Controller75F38D_80070328, int*, 0x280) + 1;
                    Controller75F38Field(Controller75F38D_80070328, int*, 0x280) = temp_v0_5;
                    if (Controller75F38D_8006580C < temp_v0_5) {
                        Controller75F38Field(Controller75F38D_80070328, int*, 0x280) =
                            (int)Controller75F38D_8006580C;
                    }
                } else {
                    temp_v0_6 = Controller75F38D_8006C784 + 1;
                    Controller75F38D_8006C784 = temp_v0_6;
                    Controller75F38Field(Controller75F38D_80070328, int*, 0x280) =
                        (int)Controller75F38D_8006580C;
                    if (temp_v0_6 >= 0x64) {
                        Controller75F38D_8006C784 = 0x63;
                    }
                }
                Controller75F38Field(owner, unsigned char*, 0x49) =
                    (unsigned char)(Controller75F38Field(owner, unsigned char*, 0x49) + 1);
                Controller75F38DeleteMoby(Controller75F38Field(tag, unsigned char**, 0x14));
                break;
            case 2: /* switch 1 */
                if (Controller75F38D_8006C770 != 0) {
                    register void* callbackOwner __asm__("$4") = owner;
                    if (Controller75F38Field(owner, unsigned char*, 0x3D) != 0) {
                        MATCHING_KEEP(callbackOwner);
                        Controller75F38D_8006C770 = 0;
                        temp_v0_7 = Controller75F38Field(owner, unsigned char*, 0x3D);
                        temp_a1_3 = Controller75F38Field(owner, unsigned char*, 0x3F);
                        {
                            register int value __asm__("$3");
                            MATCHING_KEEP2_CLOBBER(temp_v0_7, temp_a1_3, "$3");
                            value = 114;
                            MATCHING_KEEP(value);
                            Controller75F38Field(owner, unsigned char*, 0x40) = value;
                            Controller75F38Field(owner, unsigned char*, 0x3D) = 0U;
                            Controller75F38Field(owner, unsigned char*, 0x3F) = 0U;
                            Controller75F38Field(owner, unsigned char*, 0x3C) = temp_v0_7;
                            Controller75F38Field(owner, unsigned char*, 0x3E) = temp_a1_3;
                            Controller75F38EmptyAnimationTransitionHook(callbackOwner, temp_a1_3);
                        }
                    }
                    Controller75F38Field(owner, unsigned char*, 0x49) = 0U;
                    Controller75F38Field(tag, unsigned char**, 0x14) = 0;
                }
                break;
            case 4: /* switch 1 */
                temp_v0_8 = Controller75F38Field(tag, unsigned char**, 0x14);
                temp_s1_3 = Controller75F38Field(temp_v0_8, void**, 0);
                temp_s0_4 = (unsigned char*)&frame.fourth.x;
                MATCHING_KEEP(temp_s0_4);
                Controller75F38SubtractVector(temp_s0_4, temp_v0_8 + 12, owner + 12);
                temp_v0_9 = Controller75F38MeasureVectorLength(temp_s0_4, 1);
                if (temp_v0_9 < 0x200) {
                    Controller75F38RefreshMobySpatialGridAndBasis(
                        Controller75F38Field(tag, unsigned char**, 0x14), 4);
                    temp_a2 = Controller75F38Field(tag, unsigned char**, 0x14);
                    Controller75F38SpawnParticle(
                        4, 0xC, temp_a2, Controller75F38Field(temp_a2, unsigned char*, 0x49));
                    Controller75F38Field(temp_s1_3, short*, 0xA) = 0;
                    Controller75F38Field(temp_s1_3, signed char*, 0xE) =
                        (signed char)(rand() & 0xE);
                    Controller75F38Field(temp_s1_3, signed char*, 0xF) =
                        (signed char)(rand() & 0xE);
                    Controller75F38Field(temp_s1_3, signed char*, 0x10) =
                        (signed char)(rand() & 0xE);
                    Controller75F38PackVectorShiftRight2(
                        temp_s1_3 + 4, Controller75F38Field(tag, unsigned char**, 0x14) + 0xC);
                    Controller75F38Field(Controller75F38Field(tag, unsigned char**, 0x14),
                                         unsigned char*, 0x48) = 3U;
                    Controller75F38PlayMobySoundEvent(
                        Controller75F38Field(tag, unsigned char**, 0x14), 1, 0);
                    Controller75F38Field(tag, unsigned char**, 0x14) = 0;
                } else {
                    {
                        register int threshold __asm__("$2") = 310;
                        register void* adjustedVector __asm__("$4");
                        MATCHING_KEEP(threshold);
                        if (threshold < temp_v0_9) {
                            var_a2_3 = 310;
                            adjustedVector = temp_s0_4;
                            goto stateFourAdjust;
                        }
                        adjustedVector = temp_s0_4;
                        MATCHING_KEEP(adjustedVector);
                        var_a2_3 = 290;
                    stateFourAdjust:
                        Controller75F38ScaleVectorRatioQ15(adjustedVector, temp_v0_9, var_a2_3);
                    }
                    {
                        register void* first __asm__("$4") = owner + 12;
                        register void* second __asm__("$5") = first;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$16", "$18");
                        temp_s0_4 = (unsigned char*)&frame.fourth.x;
                        MATCHING_KEEP(temp_s0_4);
                        Controller75F38AddVector(first, second, temp_s0_4);
                    }
                    Controller75F38TurnMobyTowardHeading(
                        owner,
                        Controller75F38PlanarHeadingLookup(frame.fourth.x, frame.fourth.y, 0), 0xAU,
                        0, 0, 0);
                    tailMagnitude = Controller75F38MeasureVectorLength(temp_s0_4, 0);
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailMagnitude, "$7");
                    var_a0_4 = tailMagnitude;
                    var_a1 = frame.fourth.z;
                    goto block_97;
                }
                break;
            case 5: {
                register int value __asm__("$2");
                register int offset __asm__("$3");
                register void* first __asm__("$4");
                register void* second __asm__("$5");
                register void* third __asm__("$6");
                temp_s0_5 = (unsigned char*)&frame.fifth.x;
                MATCHING_KEEP(temp_s0_5);
                value = (int)Controller75F38Field(tag, void**, 0x14);
                offset = Controller75F38Field(tag, short*, 4);
                value = Controller75F38Field((void*)value, int*, 12);
                MATCHING_KEEP2_CLOBBER(value, offset, "$4");
                first = temp_s0_5;
                value += offset;
                frame.fifth.x = value;
                value = (int)Controller75F38Field(tag, void**, 0x14);
                offset = Controller75F38Field(tag, short*, 6);
                value = Controller75F38Field((void*)value, int*, 16);
                MATCHING_KEEP2_CLOBBER(value, offset, "$5");
                second = temp_s0_5;
                value += offset;
                frame.fifth.y = value;
                value = (int)Controller75F38Field(tag, void**, 0x14);
                offset = Controller75F38Field(tag, short*, 8);
                value = Controller75F38Field((void*)value, int*, 20);
                MATCHING_KEEP2_CLOBBER(value, offset, "$6");
                third = owner + 12;
                value += offset;
                frame.fifth.z = value;
                Controller75F38SubtractVector(first, second, third);
            }
                temp_v0_10 = Controller75F38MeasureVectorLength(temp_s0_5, 1);
                if (temp_v0_10 < 0x200) {
                    temp_v0_11 = Controller75F38Field(tag, unsigned char**, 0x14);
                    Controller75F38Field(temp_v0_11, int*, 0x18) =
                        (int)(Controller75F38Field(temp_v0_11, int*, 0x18) | 0x10000000);
                    Controller75F38Field(tag, unsigned char**, 0x14) = 0;
                } else {
                    var_a2_4 = Controller75F38D_80065814 + 0xA;
                    if (var_a2_4 >= temp_v0_10) {
                        var_a2_4 = Controller75F38D_80065814 - 0xA;
                    }
                    {
                        register void* adjustedVector __asm__("$4") = temp_s0_5;
                        MATCHING_KEEP(adjustedVector);
                        Controller75F38ScaleVectorRatioQ15(adjustedVector, temp_v0_10, var_a2_4);
                    }
                    MATCHING_KEEP_VOLATILE(owner);
                    {
                        register void* first __asm__("$4") = owner + 12;
                        register void* second __asm__("$5") = first;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$16", "$17", "$18", "$21", "$22", "memory");
                        {
                            register unsigned char* stack __asm__("$29");
                            __asm__ volatile("" : "=r"(stack));
                            temp_s0_5 = stack + 0x78;
                        }
                        MATCHING_KEEP(temp_s0_5);
                        Controller75F38AddVector(first, second, temp_s0_5);
                    }
                    Controller75F38TurnMobyTowardHeading(
                        owner, Controller75F38PlanarHeadingLookup(frame.fifth.x, frame.fifth.y, 0),
                        0xAU, 0, 0, 0);
                    var_a0_4 = Controller75F38MeasureVectorLength(temp_s0_5, 0);
                    var_a1 = frame.fifth.z;
                    goto block_97;
                }
                break;
            block_97:
                temp_v0_4 = Controller75F38PlanarHeadingLookup(var_a0_4, var_a1, 0);
                Controller75F38Field(owner, unsigned char*, 0x45) = temp_v0_4;
                Controller75F38Field(owner, unsigned char*, 0x45) =
                    Controller75F38Helper36018(temp_v0_4 & 0xFF, 0, 0x30);
                break;
            case 9: /* switch 1 */
                Controller75F38Field(tag, short*, 8) = 0x180;
                Controller75F38Field(tag, short*, 4) = 0;
                Controller75F38Field(tag, short*, 6) = 0;
                Controller75F38Field(owner, unsigned char*, 0x49) = 5U;
                break;
        }
    } else if (Controller75F38Field(Controller75F38D_80065830, void**, 0) != 0) {
        Controller75F38SubtractVector(
            &frame.first.x, Controller75F38Field(Controller75F38D_80065830, void**, 0) + 0xC,
            Controller75F38D_80070328);
        if (Controller75F38D_80065828 >= 0x401) {
            if (Controller75F38D_80065828 >= 0x4001) {
                Controller75F38ShiftVectorRightTowardZero(
                    &frame.first.x, Controller75F38Helper4EA74(Controller75F38D_80065828) - 0xE);
            }
            {
                register int sample __asm__("$2") =
                    *(unsigned short*)(Controller75F38D_800658A0 +
                                       ((Controller75F38D_8006C644 * 16) & 0x1F0));
                register void* vector __asm__("$4");
                MATCHING_KEEP_CLOBBER(sample, "$4");
                vector = &frame.first.x;
                MATCHING_KEEP2(sample, vector);
                sample = (sample << 16) >> 21;
                Controller75F38NormalizeVectorToLength(vector, sample + 1024);
            }
        }
        if (frame.first.z < -0x100) {
            frame.first.z = -0x100;
        }
        Controller75F38Field(owner, signed char*, 0x44) = 0;
        Controller75F38Field(owner, unsigned char*, 0x45) = Controller75F38PlanarHeadingLookup(
            Controller75F38MeasureVectorLength(&frame.first.x, 0), frame.first.z, 0);
        Controller75F38Field(owner, unsigned char*, 0x46) = Controller75F38PlanarHeadingLookup(
            Controller75F38Field(owner, int*, 0xC) -
                Controller75F38Field(Controller75F38D_80070328, int*, 0),
            Controller75F38Field(owner, int*, 0x10) -
                Controller75F38Field(Controller75F38D_80070328, int*, 4),
            0);
        Controller75F38AddVector(&frame.first.x, &frame.first.x, Controller75F38D_80070328);
        {
            register void* first __asm__("$4") = &frame.first.x;
            register void* second __asm__("$5") = first;
            MATCHING_KEEP2_CLOBBER(first, second, "$16");
            temp_s0_2 = owner + 12;
            Controller75F38SubtractVector(first, second, temp_s0_2);
        }
        Controller75F38ShiftVectorRightTowardZero(&frame.first.x, 2);
        Controller75F38AddVector(temp_s0_2, temp_s0_2, &frame.first.x);
        if (Controller75F38Helper19194(temp_s0_2, 0x100) != 0) {
            Controller75F38CopyVector(temp_s0_2, Controller75F38D_8007190C);
        }
    } else {
        var_a1_2 = 0;
        if ((Controller75F38Field(Controller75F38D_80070328, int*, 0x50) == 0) &&
            (Controller75F38Field(Controller75F38D_80070328, int*, 0x240) == 0) &&
            !(Controller75F38Field(Controller75F38D_80070328, int*, 0x20C) & 8)) {
            var_a1_2 = Controller75F38D_8006E534 != 0;
        }
        if (var_a1_2 != 0) {
            var_a1_2 = Controller75F38CountTimerDown(tag + 0xD, 1);
        } else {
            Controller75F38Field(tag, signed char*, 0xD) = 0x78;
        }
        temp_v0_12 = Controller75F38Field(tag, short*, 0);
        if (temp_v0_12 <= 0) {
            temp_v1_9 = Controller75F38Field(tag, unsigned char*, 3);
            MATCHING_KEEP(temp_v1_9);
            switch (temp_v1_9) {
                case 0:
                case 1:
                case 3:
                case 6:
                    MATCHING_OBSERVE_VOLATILE(temp_v1_9);
                    if ((var_a1_2 != 0) && (rand() < 0x2AAA)) {
                        temp_v0_13 = Controller75F38RandBetween(0, 9);
                        switch (temp_v0_13) {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                                stateValue = 16;
                                Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                                stateValue = 3;
                                MATCHING_KEEP(stateValue);
                                Controller75F38Field(tag, unsigned char*, 3) = stateValue;
                                goto reloadSelectedState;
                            case 4:
                            case 5:
                            case 6:
                                stateValue = 12;
                                Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                                stateValue = 2;
                                MATCHING_KEEP(stateValue);
                                Controller75F38Field(tag, unsigned char*, 3) = stateValue;
                                goto reloadSelectedState;
                            case 7:
                            case 8:
                                stateValue = 20;
                                Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                                stateValue = 6;
                                MATCHING_KEEP(stateValue);
                                Controller75F38Field(tag, unsigned char*, 3) = stateValue;
                                goto reloadSelectedState;
                            case 9:
                                stateValue = 16;
                                Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                                goto selectFour;
                        }
                        goto reloadSelectedState;
                    }
                    temp_v1_9 = Controller75F38Field(tag, unsigned char*, 3);
                    if (temp_v1_9 == 3)
                        goto resetLarge;
                    stateValue = 4;
                    Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                    goto resetZero;
                case 2:
                    stateValue = 12;
                    Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                    if (var_a1_2 == 0)
                        goto selectOneNoRandom;
                    stateValue = rand() < 0x3FFF;
                    if (!stateValue) {
                        stateValue = 1;
                        goto selectOne;
                    }
                selectFour:
                    stateValue = 4;
                    MATCHING_KEEP(stateValue);
                    Controller75F38Field(tag, unsigned char*, 3) = stateValue;
                    goto reloadSelectedState;
                selectOneNoRandom:
                    stateValue = 1;
                selectOne:
                    MATCHING_KEEP(stateValue);
                    Controller75F38Field(tag, unsigned char*, 3) = stateValue;
                    goto reloadSelectedState;
                case 4:
                    stateValue = 16;
                    Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                    stateValue = 5;
                    MATCHING_KEEP(stateValue);
                    Controller75F38Field(tag, unsigned char*, 3) = stateValue;
                    goto reloadSelectedState;
                case 5:
                resetLarge:
                    stateValue = 16;
                    Controller75F38Field(tag, unsigned char*, 12) = stateValue;
                resetZero:
                    Controller75F38Field(tag, unsigned char*, 3) = 0;
                    goto reloadSelectedState;
                default:
                    goto dispatchSelectedState;
            }
        reloadSelectedState:
            temp_v1_9 = Controller75F38Field(tag, unsigned char*, 3);
        dispatchSelectedState:
            MATCHING_KEEP_VOLATILE(temp_v1_9);
            switch (temp_v1_9) { /* switch 4 */
                case 0:          /* switch 4 */
                case 1:          /* switch 4 */
                    MATCHING_OBSERVE_VOLATILE(temp_v1_9);
                    frame.first.x = -0x258;
                    frame.first.y = (rand() & 0x310) - 0x188;
                    if (Controller75F38D_8006E044 == 2) {
                        var_v0_5 = (rand() & 0x7F) + 0x64;
                    } else {
                        var_v0_5 = (rand() & 0x1FF) - 0xC8;
                    }
                    frame.first.z = var_v0_5;
                    if (Controller75F38Field(tag, unsigned char*, 0xA) != 0) {
                        frame.first.x = -0xC8;
                        frame.first.z = (rand() & 0x7F) - 0xFA;
                    }
                    Controller75F38Field(tag, short*, 4) = (short)frame.first.x;
                    Controller75F38Field(tag, short*, 6) = (short)frame.first.y;
                    Controller75F38Field(tag, short*, 8) = (short)frame.first.z;
                    if (Controller75F38Field(tag, unsigned char*, 3) == 0) {
                        Controller75F38Field(tag, short*, 0) = (short)((rand() & 0x3F) + 0x3C);
                        Controller75F38Field(tag, unsigned char*, 0xB) = 5U;
                    } else
                        goto resetTimer;
                    break;
                case 2: /* switch 4 */
                    Controller75F38Field(tag, short*, 4) = 0x1F4;
                    Controller75F38Field(tag, short*, 8) = 0x12C;
                    Controller75F38Field(tag, short*, 6) = 0;
                    Controller75F38Field(tag, short*, 0) = 0x78;
                    break;
                case 3: /* switch 4 */
                    Controller75F38Field(tag, short*, 0) = (short)((rand() & 0x1F) + 0x3C);
                    break;
                case 4: /* switch 4 */
                case 5: /* switch 4 */
                {
                    register int selected __asm__("$2") = Controller75F38RandBetween(0, 3);
                    register int value __asm__("$3") = 700;
                    MATCHING_KEEP2_CLOBBER(selected, value, "$16");
                    temp_s0_3 = selected;
                    Controller75F38Field(tag, short*, 4) = value;
                }
                    if (Controller75F38Field(tag, unsigned char*, 3) == 4) {
                        var_v0_8 = rand() < 0x3FFF;
                        if (var_v0_8) {
                            var_v0_8 = temp_s0_3 << 1;
                            goto positiveOffset;
                        }
                        var_v0_8 = temp_s0_3 << 1;
                        var_v0_8 += temp_s0_3;
                        goto negativeCompute;
                    }
                    var_v0_8 = Controller75F38Field(tag, short*, 6);
                    if (var_v0_8 >= 0) {
                        var_v0_8 = temp_s0_3 << 1;
                        goto negativeOffset;
                    }
                    var_v0_8 = temp_s0_3 << 1;
                positiveOffset:
                    var_v0_8 += temp_s0_3;
                    MATCHING_KEEP_CLOBBER(var_v0_8, "$7");
                    var_v0_8 = (var_v0_8 << 3) + temp_s0_3;
                    var_v0_8 <<= 1;
                    var_v0_8 += 100;
                    goto storeOffset;
                negativeOffset:
                    MATCHING_KEEP_VOLATILE(temp_s0_3);
                    var_v0_8 += temp_s0_3;
                negativeCompute:
                    MATCHING_KEEP_CLOBBER(var_v0_8, "$6");
                    var_v0_8 = (var_v0_8 << 3) + temp_s0_3;
                    var_v0_8 <<= 1;
                    var_v0_8 = -var_v0_8 - 100;
                storeOffset:
                    Controller75F38Field(tag, short*, 6) = var_v0_8;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register int selected __asm__("$2") = Controller75F38RandBetween(0, 3);
                        temp_v1_10 = selected * 50;
                        MATCHING_KEEP_CLOBBER(temp_v1_10, "$2");
                        stateValue = 60;
                        Controller75F38Field(tag, short*, 0) = stateValue;
                        stateValue = 10;
                        MATCHING_KEEP(stateValue);
                        Controller75F38Field(tag, short*, 8) = temp_v1_10;
                        Controller75F38Field(tag, unsigned char*, 11) = stateValue;
                    }
                    break;
                case 6:
                resetTimer:
                    Controller75F38Field(tag, short*, 0) = 120;
                    break;
            }
        } else {
            Controller75F38Field(tag, short*, 0) = (short)(temp_v0_12 - Controller75F38D_8006C648);
            if ((Controller75F38Field(tag, unsigned char*, 3) != 0) && (var_a1_2 == 0)) {
                Controller75F38Field(tag, short*, 0) = 0;
            }
            temp_v1_11 = Controller75F38Field(tag, unsigned char*, 3);
            switch (temp_v1_11) { /* switch 5 */
                case 0:           /* switch 5 */
                case 4:           /* switch 5 */
                case 5:           /* switch 5 */
                    temp_v1_12 = Controller75F38Field(tag, unsigned char*, 0xB);
                    if (temp_v1_12 & 1) {
                        if ((Controller75F38D_8006E044 == 2) ||
                            (Controller75F38Field(Controller75F38D_80070328, int*, 0x50) == 0xC)) {
                            frame.first.x =
                                Controller75F38Field(tag, short*, 4) +
                                ((int)Controller75F38Field(Controller75F38D_80070328, int*, 0xB0) >>
                                 2);
                            frame.first.y = (int)Controller75F38Field(tag, short*, 6);
                            temp_a0_7 = Controller75F38Field(tag, short*, 8);
                            frame.first.z = (int)temp_a0_7;
                            if ((Controller75F38Field(Controller75F38D_80070328, int*, 0x50) !=
                                 0xC) &&
                                (temp_a0_7 < 0x64)) {
                                frame.first.z = 0x64;
                            }
                        } else {
                            if (Controller75F38D_8006E044 == 7) {
                                var_v0_9 = Controller75F38Field(tag, short*, 4) - 0x200;
                            } else {
                                var_v0_9 = Controller75F38Field(tag, short*, 4);
                            }
                            frame.first.x = (int)var_v0_9;
                            frame.first.y = (int)Controller75F38Field(tag, short*, 6);
                            frame.first.z = (int)Controller75F38Field(tag, short*, 8);
                        }
                        temp_s0_4 = Controller75F38D_80070328 + 0x30;
                        Controller75F38TransformVectorByBasis(temp_s0_4, &frame.first.x,
                                                              &frame.first.x);
                        matrixFirst = &frame.first.x;
                        matrixSecond = matrixFirst;
                        MATCHING_KEEP2_CLOBBER(matrixFirst, matrixSecond, "$6");
                        var_a2_5 = temp_s0_4 - 0x30;
                        goto transformOffset;
                    }
                    if (temp_v1_12 & 2) {
                        Controller75F38Helper4ECF4(&frame.matrix[0], Controller75F38D_8006E00C);
                        Controller75F38Helper4F554(&frame.first.x, tag + 4);
                        Controller75F38TransformVectorByBasis(&frame.matrix[0], &frame.first.x,
                                                              &frame.first.x);
                        matrixFirst = &frame.first.x;
                        matrixSecond = matrixFirst;
                        MATCHING_KEEP2_CLOBBER(matrixFirst, matrixSecond, "$6");
                        var_a2_5 = Controller75F38D_8006E00C + 0x14;
                    transformOffset:
                        Controller75F38AddVector(matrixFirst, matrixSecond, var_a2_5);
                    }
                    {
                        register void* first __asm__("$4") = &frame.first.x;
                        register void* second __asm__("$5") = first;
                        MATCHING_KEEP2_CLOBBER(first, second, "$16");
                        temp_s0_5 = owner + 12;
                        Controller75F38SubtractVector(first, second, temp_s0_5);
                    }
                    Controller75F38ShiftVectorRightTowardZero(&frame.first.x, 2);
                    Controller75F38AddVector(temp_s0_5, temp_s0_5, &frame.first.x);
                    if (Controller75F38Helper19194(temp_s0_5, 0x100) != 0) {
                        Controller75F38CopyVector(temp_s0_5, Controller75F38D_8007190C);
                    }
                    if (frame.first.z >= 0x21) {
                        frame.first.z = 0x20;
                    }
                    if (frame.first.z < -0x20) {
                        frame.first.z = -0x20;
                    }
                    Controller75F38Field(owner, signed char*, 0x44) = 0;
                    Controller75F38Field(owner, unsigned char*, 0x45) =
                        (unsigned char)frame.first.z;
                    temp_v1_13 = Controller75F38Field(tag, unsigned char*, 0xB);
                    {
                        register int flag __asm__("$2") = temp_v1_13 & 4;
                        MATCHING_KEEP_CLOBBER(flag, "$4");
                        commonOwner = owner;
                        if (flag) {
                            var_a1_3 = Controller75F38Field(Controller75F38D_80070328,
                                                            unsigned char*, 0xE);
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_a1_3, "$6");
                            goto applyOwnerAngle;
                        } else {
                            MATCHING_KEEP_VOLATILE(temp_v1_13);
                            {
                                register int zero __asm__("$7");
                                flag = temp_v1_13 & 8;
                                MATCHING_KEEP_CLOBBER(flag, "$7");
                                zero = 0;
                                if (flag) {
                                    MATCHING_KEEP(zero);
                                    Controller75F38TurnMobyTowardHeading(
                                        commonOwner,
                                        (((int)(Controller75F38D_8006E040 << 0x10) >> 0x14) +
                                         0x80) &
                                            0xFF,
                                        Controller75F38Field(tag, unsigned char*, 0xC), zero, 0, 0);
                                }
                            }
                        }
                    }
                    break;
                case 1: /* switch 5 */
                case 2: /* switch 5 */
                    temp_s0_5 = &frame.sixth.x;
                    {
                        register void* vector __asm__("$4") = temp_s0_5;
                        MATCHING_KEEP_CLOBBER(vector, "$22");
                        ownerPosition = owner + 12;
                        Controller75F38SubtractVector(vector, ownerPosition,
                                                      Controller75F38D_80070328);
                    }
                    initialMagnitude = Controller75F38MeasureVectorLength(&frame.sixth.x, 0);
                    initialAngle =
                        Controller75F38PlanarHeadingLookup(frame.sixth.x, frame.sixth.y, 0);
                    Controller75F38Helper4F554(&frame.sixth.x, tag + 4);
                    Controller75F38TransformVectorByBasis(Controller75F38D_80070328 + 0x30,
                                                          &frame.sixth.x, &frame.sixth.x);
                    {
                        register int magnitude __asm__("$2") =
                            Controller75F38MeasureVectorLength(&frame.sixth.x, 0);
                        register int zero __asm__("$6") = 0;
                        register int x __asm__("$4");
                        register int y __asm__("$5");
                        MATCHING_KEEP_VOLATILE(magnitude);
                        __asm__("" : "=r"(zero) : "0"(zero) : "$4", "$5");
                        x = frame.sixth.x;
                        y = frame.sixth.y;
                        MATCHING_KEEP3(x, y, magnitude);
                        magnitudeDelta = magnitude;
                        magnitude = Controller75F38PlanarHeadingLookup(x, y, zero);
                        x = magnitude;
                        y = initialAngle;
                        MATCHING_KEEP3(x, y, magnitudeDelta);
                        magnitudeDelta = (magnitudeDelta - initialMagnitude) >> 3;
                        magnitude = Controller75F38SignedByteAngleDelta(x, y);
                        magnitude >>= 3;
                        magnitude = initialAngle + magnitude;
                        adjustedAngle = magnitude & 255;
                    }
                    temp_a1_4 = adjustedAngle * 2;
                    {
                        register int sample __asm__("$2") =
                            *(short*)(Controller75F38D_80065920 + temp_a1_4);
                        register int vertical __asm__("$3");
                        register int playerX __asm__("$4");
                        register int playerZ __asm__("$6");
                        register int product __asm__("$8");
                        MATCHING_KEEP_CLOBBER(sample, "$17");
                        adjustedMagnitude = initialMagnitude + magnitudeDelta;
                        product = sample * adjustedMagnitude;
                        vertical = frame.sixth.z;
                        playerX = Controller75F38Field(Controller75F38D_80070328, int*, 0);
                        playerZ = Controller75F38Field(Controller75F38D_80070328, int*, 8);
                        MATCHING_KEEP4(vertical, playerX, playerZ, product);
                        sample = (product >> 12) + playerX;
                        Controller75F38Field(owner, int*, 12) = sample;
                        sample = *(short*)(Controller75F38D_800658A0 + temp_a1_4);
                        product = sample * adjustedMagnitude;
                        __asm__(""
                                : "=r"(sample), "=r"(vertical)
                                : "0"(sample), "1"(vertical)
                                : "$4", "$5");
                        vertical += playerZ;
                        movementPosition = ownerPosition;
                        __asm__("" : "=r"(movementPosition) : "0"(movementPosition) : "$2", "$5");
                        sample = Controller75F38Field(owner, int*, 20);
                        MATCHING_KEEP_CLOBBER(sample, "$5");
                        movementRadius = 256;
                        MATCHING_KEEP3(sample, vertical, movementRadius);
                        vertical -= sample;
                        verticalStep = vertical >> 3;
                        sample = Controller75F38Field(owner, int*, 20);
                        vertical = Controller75F38Field(Controller75F38D_80070328, int*, 4);
                        MATCHING_KEEP2(sample, vertical);
                        sample += verticalStep;
                        Controller75F38Field(owner, int*, 20) = sample;
                        MATCHING_BARRIER_VOLATILE("memory");
                        sample = (product >> 12) + vertical;
                        Controller75F38Field(owner, int*, 16) = sample;
                    }
                    if (Controller75F38Helper19194(movementPosition, movementRadius) != 0) {
                        Controller75F38CopyVector(ownerPosition, Controller75F38D_8007190C);
                        MATCHING_KEEP_VOLATILE(verticalStep);
                    }
                    var_v0_10 = verticalStep < 0x21;
                    Controller75F38Field(owner, signed char*, 0x44) = 0;
                    if (var_v0_10 == 0) {
                        verticalStep = 0x20;
                    }
                    if (verticalStep < -0x20) {
                        verticalStep = -0x20;
                    }
                    Controller75F38Field(owner, unsigned char*, 0x45) = (unsigned char)verticalStep;
                    {
                        register int state __asm__("$3") =
                            Controller75F38Field(tag, unsigned char*, 3);
                        register int one __asm__("$2");
                        MATCHING_KEEP_CLOBBER(state, "$2");
                        one = 1;
                        if (state == one) {
                            if (Controller75F38Field(tag, short*, 0) < 0x65) {
                                commonOwner = owner;
                                MATCHING_KEEP_CLOBBER(commonOwner, "$5");
                                var_a1_3 = Controller75F38Field(Controller75F38D_80070328,
                                                                unsigned char*, 0xE);
                                MATCHING_KEEP_VOLATILE_CLOBBER(var_a1_3, "$7");
                                goto applyOwnerAngle;
                            }
                            var_v0_11 = adjustedAngle - 0x80;
                            goto storeOwnerAngle;
                        } else {
                            var_v0_11 = adjustedAngle - 128;
                        }
                    }
                storeOwnerAngle:
                    MATCHING_OBSERVE_VOLATILE(adjustedAngle);
                    Controller75F38Field(owner, unsigned char*, 0x46) = var_v0_11;
                    break;
                case 3: /* switch 5 */
                {
                    register int angle __asm__("$2") = Controller75F38PlanarHeadingLookup(
                        Controller75F38D_8006E020 - Controller75F38Field(owner, int*, 0xC),
                        Controller75F38D_8006E024 - Controller75F38Field(owner, int*, 0x10), 0);
                    commonOwner = owner;
                    MATCHING_KEEP_CLOBBER(commonOwner, "$5");
                    var_a1_3 = angle;
                }
                applyOwnerAngle:
                    Controller75F38TurnMobyTowardHeading(
                        commonOwner, var_a1_3, Controller75F38Field(tag, unsigned char*, 12), 0, 0,
                        0);
                    break;
                case 6: /* switch 5 */
                    if (Controller75F38Callback(owner, Controller75F38D_80070328, 0,
                                                Controller75F38Field(owner, unsigned char*, 0x46),
                                                8, 0xA0,
                                                (int)Controller75F38Field(tag, unsigned char*, 0xC),
                                                0x80, 0xFF, 0xFF, 0, 0, 0) < 0) {
                        Controller75F38Field(tag, short*, 0) = 0;
                    }
                    {
                        register int ownerHeight __asm__("$2") =
                            Controller75F38Field(owner, int*, 20);
                        register int playerHeight __asm__("$3") =
                            Controller75F38Field(Controller75F38D_80070328, int*, 8);
                        MATCHING_KEEP2(ownerHeight, playerHeight);
                        ownerHeight -= 300;
                        playerHeight -= ownerHeight;
                        playerHeight >>= 2;
                        frame.first.z = playerHeight;
                        ownerHeight = Controller75F38Field(owner, int*, 20);
                        Controller75F38Field(owner, int*, 20) = ownerHeight + playerHeight;
                    }
                    break;
            }
        }
    }
    if ((Controller75F38Field(tag, void**, 0x10) != 0) &&
        (Controller75F38Field(owner, unsigned char*, 0x46) != originalAngle)) {
        Controller75F38RefreshMobySpatialGridAndBasis(owner, 4);
    }
    {
        register int tableIndex __asm__("$2") =
            Controller75F38Field(Controller75F38TablePlayer, int*, 0x280);
        MATCHING_KEEP(tableIndex);
        Controller75F38Field(owner, int*, 0x54) =
            *(int*)(Controller75F38D_8006585C + (tableIndex << 2));
    }
    __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
    temp_v1_15 = Controller75F38Field(tag, void**, 0x10);
    if (temp_v1_15 != 0) {
        if (Controller75F38Field(Controller75F38D_80070328, int*, 0x280) >= 4) {
            Controller75F38Field(temp_v1_15, signed char*, 0x10) =
                (signed char)Controller75F38Field(Controller75F38D_80070328, int*, 0x280);
        } else {
            Controller75F38Field(temp_v1_15, signed char*, 0x10) = 1;
        }
        Controller75F38InterpolateMobyVertex(owner, 0, Controller75F38Field(tag, void**, 0x10));
    }
    if ((Controller75F38Field(owner, unsigned char*, 0x3D) == 1) &&
        (Controller75F38D_8006C770 != 0)) {
        Controller75F38RequestMobyAnimation(owner, 0);
    }
}

#undef Controller75F38Field


typedef struct {
    short counter;
    unsigned char unk2, unk3;
} DecodedColourTag;
void func_80055B18(Moby*);
void func_level_15_80076B58(Moby* moby) {
    DecodedColourTag* tag = moby->mobyTag;
    if (func_800359A4(tag, 2))
        func_80055B18(moby);
    if (tag->unk2 == 0) {
        short value = tag->counter;
        if (value < 8) {
            moby->colour.r = value << 4;
            moby->colour.g = 0;
        } else
            moby->colour.g = (value - 8) << 4;
    } else if (tag->unk2 == 1) {
        short value = tag->counter;
        if (value < 8) {
            moby->colour.g = value << 4;
            moby->colour.r = 0;
        } else
            moby->colour.r = (value - 8) << 4;
    } else if (tag->unk2 == 2) {
        moby->colour.r -= 8;
        moby->colour.g -= 8;
        moby->colour.b -= 8;
        moby->colour.a = (unsigned short)tag->counter;
    }
    if (tag->unk3 == 0)
        moby->size = *(unsigned char*)tag * 2 + 0x30;
    else
        moby->size = *(unsigned char*)tag * 4 + 0x34;
}

extern int deltaTime;
int func_800359A4(void*, int);
void func_80055B18(Moby*);
void func_level_15_80076C94(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4))
        func_80055B18(moby);
    {
        int value = 0x10 - tag[0];
        if (value < 0)
            value = 0;
        moby->colour.a = value + 0x30;
    }
    moby->size -= deltaTime * 6;
    if (moby->size >= 0x80)
        moby->size = 0;
    if (moby->size < 0x18)
        moby->size = 0x18;
}

extern int deltaTime;
int func_800359A4(void*, int);
void func_80055B18(Moby*);
void func_level_15_80076D50(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4))
        func_80055B18(moby);
    moby->colour.r = tag[0] << 3;
    moby->colour.g = tag[0] << 2;
    moby->size -= deltaTime * 3;
    if (moby->size >= 0x80)
        moby->size = 0;
    if (moby->size < 0xE)
        moby->size = 0xE;
}

extern int D_8006E020, D_8006E024, D_8007191C, D_80071920;
extern Vector3D D_8007190C;
extern int D_8006C644;
extern short D_800658A0[], D_80065920[];
int func_80019194(Vector3D*, int);
int func_8001A358(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8005629C(Moby*);
/* AI-generated source reuse, not human reviewed. Exact existing L17 raw260
 * typed body; original native/frame/data/helper gates remain mandatory.
 * Unknown fields retain original names; no new semantic decode is claimed. */
extern CollisionData D_80071900;
/* Existing Camera member at camera+0x28; no new storage definition. */
extern Vector3D Raw260CameraPosition __asm__("camera+40");
void func_level_15_80076E04(Moby* moby) {
    // MOBY_UPDATE_FUNC(260)
    // MOBY_UPDATE_FUNC(260, LEVEL_ID) {
    //MobyUpdate_260(moby);
    Vector3D offset;
    int dotProduct;
    unsigned char temp_v0_5;
    unsigned char angleByte;
    Vector3D* temp_a0;
    Vector3D* position;
    MobyTag_260* mobyTag;

    mobyTag = (MobyTag_260*)moby->mobyTag;
    if (moby->substate == 0) {
        if (mobyTag->unk4 > 0) {
            moby->angle.yaw++;
            mobyTag->unkC.z = mobyTag->unkC.z - 6;
            if (mobyTag->unkC.z < -0x80) {
                mobyTag->unkC.z = -0x80;
            }
            moby->position.x += mobyTag->unkC.x;
            moby->position.y += mobyTag->unkC.y;
            moby->position.z += mobyTag->unkC.z;
            position = &moby->position;
            if (moby->position.z >= 0x400) {
                func_8001A358(position, 0x2000);
                func_8005629C(moby);
                if (func_80019194(position, 0x100) != 0) {
                    func_8004F178(position, &D_80071900.targetedPosition);
                    func_8004EF04(&D_80071900.D_80071918, 0x1000);
                    dotProduct = DOTPRODUCT(mobyTag->unkC, D_80071900.D_80071918) >> 0xB;
                    if (dotProduct < 0) {
                        func_8004F08C(&D_80071900.D_80071918, 0x1000, -dotProduct);
                        func_8004F194(&mobyTag->unkC, &mobyTag->unkC, &D_80071900.D_80071918);
                    }
                }
                mobyTag->unk4--;
                return;
            }
            func_80055B18(moby);
            return;
        }
        ovlHeader.SpawnParticle(0xA, 0x47, &moby->position, 0);
        func_80055B18(moby);
        return;
    }
    if (mobyTag->unk0->state != 0) {
        func_80055B18(moby);
        return;
    }

    angleByte = func_8004E880(Raw260CameraPosition.x - moby->position.x,
                              Raw260CameraPosition.y - moby->position.y, 0);
    moby->angle.yaw =
        (D_800658A0[(unsigned char)(D_8006C644 * 4)] >> 0x7) + (unsigned char)(angleByte + 0x80);
    if (moby->substate == 2) {
        angleByte += 0x80;
    }

    offset.x = 0;
    offset.y = 0;
    if (moby->substate != 3) {
        offset.x = D_800658A0[angleByte] / 28;
        offset.y = -D_80065920[angleByte] / 28;
    }
    offset.z = 0x520;
    func_8004F194(&moby->position, &mobyTag->unk0->position, &offset);
}


#define Controller78288Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller78288Helper1A358(void*, int) __asm__("func_8001A358");
void* Controller78288Helper2EC50(int, int, int) __asm__("func_8002EC50");
void* Controller78288Helper2F540(int, int, int) __asm__("func_8002F540");
int Controller78288RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller78288TurnMobyTowardPlayer(void*, int, int, int) __asm__("func_8003573C");
int Controller78288TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Controller78288Helper37BBC(void*, int) __asm__("func_80037BBC");
int Controller78288Helper3B634(void*, void*, int) __asm__("func_8003B634");
int Controller78288PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller78288Helper492DC(void*) __asm__("func_800492DC");
int Controller78288PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller78288ShiftVectorLeft(void*, int) __asm__("func_8004F0E8");
int Controller78288ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller78288CopyVector(void*, void*) __asm__("func_8004F178");
int Controller78288AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller78288SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Controller78288DivideVector(void*, void*, int) __asm__("func_8004F228");
int Controller78288ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller78288Helper512E4(void*, int, int) __asm__("func_800512E4");
int Controller78288DeleteMoby(void*) __asm__("func_80055B18");
int Controller78288RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller78288Helper55E84(void*) __asm__("func_80055E84");
int Controller78288InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern unsigned char Controller78288D_80065920[] __asm__("D_80065920");
extern int Controller78288D_8006C550 __asm__("D_8006C550");
extern int Controller78288D_8006C58C __asm__("D_8006C58C");
extern int Controller78288D_8006C644 __asm__("D_8006C644");
extern int Controller78288D_8006C704 __asm__("D_8006C704");
extern int Controller78288D_8006C770 __asm__("D_8006C770");
extern int Controller78288D_8006C79C __asm__("D_8006C79C");
extern unsigned char Controller78288D_8006D088[] __asm__("D_8006D088");
extern int Controller78288D_8006E044 __asm__("D_8006E044");
extern int Controller78288D_8006E160 __asm__("D_8006E160");
extern int Controller78288D_8006E344 __asm__("D_8006E344");
extern unsigned char Controller78288D_80070328[] __asm__("D_80070328");
extern unsigned char Controller78288D_80071AB0[] __asm__("D_80071AB0");
extern int (*Controller78288SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original authority: the 32 copies in build/family3038.json, beginning
 * level12/80078288. All 733 instructions, exact helper/global identities
 * and eight jump-table target offsets were independently compared.
 * Retain the 112-byte frame and four byte-addressed vector slots at
 * 0x18/0x28/0x38/0x48; original signed/unsigned reads, index low products,
 * bitset banks, state exits, handle reloads, clamps and helper arguments.
 * Empty compiler constraints preserve original allocation/scheduling;
 * no opcode patches. Numeric domains, helper semantics and caller cadence
 * remain unresolved. Updates occur once per invocation. Confidence is
 * exact compiled native/linked words and complete retail hashes, not a
 * semantic runtime review. Falsifiable vectors: every original word/table
 * at its recorded address and full executable/all-overlay SHA set.
 */
void func_level_15_80077108(void* input) {
    struct {
        struct {
            int x, y, z;
        } first;
        int p24;
        struct {
            int x, y, z;
        } second;
        int p34;
        struct {
            int x, y, z;
        } third;
        int p44;
        struct {
            int x, y, z;
        } fourth;
        int p54;
    } frame;
    register int kind __asm__("$3");
    register unsigned char* owner __asm__("$18") = input;
    register unsigned char* handleOwnerPosition __asm__("$16");
    register unsigned char* playerHeightAddress __asm__("$16");
    register unsigned char* savedOwnerPosition __asm__("$16");
    register unsigned char* particleOwnerPosition __asm__("$16");
    unsigned char* extraHandle;
    unsigned char* allocatedHandle;
    unsigned char* oldPrimaryHandle;
    register unsigned char* cleanupHandle __asm__("$2");
    register unsigned char* extraPosition __asm__("$4");
    register unsigned char* extraTarget __asm__("$5");
    register unsigned char* particleTarget __asm__("$5");
    register int bitIndex __asm__("$5");
    register int ownerPositionWord __asm__("$16");
    register int phaseResult __asm__("$16");
    register int distanceResult __asm__("$20");
    register int colourChannel __asm__("$2");
    int heightDelta;
    int heightResult;
    int ownerHeight;
    register int ownerIndex __asm__("$3");
    register int clampTest __asm__("$2");
    register int scaledDistance __asm__("$3");
    register int tagKind __asm__("$16");
    register int savedSelector __asm__("$17");
    unsigned char state;
    unsigned char substate;
    register int stateValue __asm__("$2");
    register int nextSubstate __asm__("$2");
    void* indexedOwner;
    register unsigned char* prefixTag __asm__("$17");
    register unsigned char* tag __asm__("$19");

    if (owner >= (unsigned char*)Controller78288D_8006C704) {
        MATCHING_KEEP(owner);
        tag = Controller78288Field(owner, void**, 0);
        prefixTag = 0;
    } else {
        MATCHING_KEEP(owner);
        prefixTag = Controller78288Field(owner, void**, 0);
        tag = prefixTag + 0x2C;
    }
    ownerPositionWord = (int)(owner + 0xC);
    distanceResult = Controller78288ApproximatePlanarDistance((void*)ownerPositionWord,
                                                              Controller78288D_80070328);
    state = Controller78288Field(owner, unsigned char*, 0x48);
    switch (state) {
        case 0:
            substate = Controller78288Field(owner, unsigned char*, 0x49);
            switch (substate) {
                case 0:
                    kind = Controller78288Field(tag, unsigned char*, 2);
                    MATCHING_KEEP_CLOBBER(kind, "$2");
                    {
                        register int two __asm__("$2") = 2;
                        MATCHING_KEEP(two);
                        if (kind == two)
                            goto caseZeroOne;
                    }
                    {
                        {
                            register int product __asm__("$3") =
                                -(((int)owner - ({
                                       register int base __asm__("$4") = Controller78288D_8006C550;
                                       MATCHING_KEEP(base);
                                       base;
                                   })) *
                                  0x45D1745D);
                            product >>= 3;
                            MATCHING_KEEP(product);
                            {
                                register int base __asm__("$2") = Controller78288D_8006C79C;
                                register int byte __asm__("$4");
                                MATCHING_KEEP_CLOBBER(base, "$4");
                                byte = Controller78288Field(tag, unsigned char*, 4);
                                MATCHING_KEEP(byte);
                                bitIndex = product + base;
                                if (byte == 0)
                                    Controller78288Field(tag, unsigned char*, 4) =
                                        Controller78288Field(owner, unsigned char*, 0x46);
                            }
                        }
                        {
                            register int bank __asm__("$3") = Controller78288D_8006C58C;
                            register int address __asm__("$2");
                            MATCHING_KEEP_CLOBBER(bank, "$2");
                            address = (int)Controller78288D_80071AB0;
                            MATCHING_KEEP2(bank, address);
                            bank <<= 5;
                            bank += address;
                            MATCHING_KEEP(bank);
                            address = (bitIndex >> 5) * 4;
                            address += bank;
                            address = *(int*)address;
                            MATCHING_KEEP_VOLATILE_CLOBBER(address, "$3");
                            bank = bitIndex & 31;
                            address = (address >> bank) & 1;
                            if (address) {
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            Controller78288Field(prefixTag, unsigned char*, 5) = 1U;
                            Controller78288Field(tag, short*, 6) = -0x280;
                            Controller78288Field(owner, int*, 0x14) =
                                (int)(Controller78288Field(owner, int*, 0x14) - 0x280);
                        } else {
                            Controller78288Field(prefixTag, unsigned char*, 5) = 0U;
                        }
                        {
                            register int heading __asm__("$2") =
                                Controller78288Field(owner, unsigned char*, 0x46);
                            kind = Controller78288Field(tag, unsigned char*, 2);
                            MATCHING_KEEP2(heading, kind);
                            Controller78288Field(tag, unsigned char*, 3) = heading;
                        }
                        if (kind != 1)
                            goto caseZeroCompare;
                        stateValue = Controller78288Field(prefixTag, unsigned char*, 5);
                        if (stateValue != 0)
                            goto caseZeroOne;
                    caseZeroCompare:
                        stateValue = distanceResult < 0x1000;
                        if (stateValue) {
                            stateValue = 5;
                            goto caseZeroStore;
                        }
                    }
                caseZeroOne:
                    stateValue = 1;
                caseZeroStore:
                    Controller78288Field(owner, unsigned char*, 0x49) = stateValue;
                    Controller78288Field(owner, signed char*, 0x41) = 0;
                    Controller78288Field(owner, signed char*, 0x4C) = 0;
                    Controller78288Field(owner, unsigned char*, 0x4D) = 0U;
                    goto clearExtraHandle;
                case 1:
                    if ((distanceResult < 0x2400) ||
                        (Controller78288Field(tag, unsigned char*, 2) == 2)) {
                        {
                            register int one __asm__("$3") = 1;
                            MATCHING_KEEP(one);
                            Controller78288Field(owner, signed char*, 0x4C) = 24;
                            Controller78288Field(owner, signed char*, 0x41) = one;
                            Controller78288Field(owner, unsigned char*, 0x4D) = one;
                            Controller78288Field(owner, unsigned char*, 0x4F) = 127;
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            Controller78288Field(owner, unsigned char*, 0x46) =
                                (unsigned char)Controller78288Field(tag, unsigned char*, 3);
                        } else {
                            Controller78288Field(owner, unsigned char*, 0x46) =
                                Controller78288PlanarHeadingLookup(
                                    Controller78288Field(Controller78288D_80070328, int*, 0) -
                                        Controller78288Field(owner, int*, 0xC),
                                    Controller78288Field(Controller78288D_80070328, int*, 4) -
                                        Controller78288Field(owner, int*, 0x10),
                                    0);
                        }
                        Controller78288Field(owner, unsigned char*, 0x49) = 2U;
                        Controller78288Field(owner, unsigned char*, 0x46) =
                            (unsigned char)(Controller78288Field(owner, unsigned char*, 0x46) +
                                            0x67);
                    }
                    goto clearExtraHandle;
                case 2:
                    Controller78288Field(owner, unsigned char*, 0x46) =
                        (unsigned char)(Controller78288Field(owner, unsigned char*, 0x46) + 8);
                    Controller78288Field(owner, unsigned char*, 0x4F) =
                        (unsigned char)(Controller78288Field(owner, unsigned char*, 0x4F) - 5);
                    if ((Controller78288Field(Controller78288D_80070328, int*, 0xB4) >= 0x1400) ||
                        (Controller78288Field(tag, unsigned char*, 2) == 2)) {
                        Controller78288Field(owner, unsigned char*, 0x46) =
                            (unsigned char)(Controller78288Field(owner, unsigned char*, 0x46) + 8);
                        Controller78288Field(owner, unsigned char*, 0x4F) =
                            (unsigned char)(Controller78288Field(owner, unsigned char*, 0x4F) - 5);
                    }
                    Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
                    Controller78288SpawnParticle(1, 0xC, owner, 5);
                    if ((unsigned char)Controller78288Field(owner, unsigned char*, 0x4F) < 0x21U) {
                        Controller78288Field(owner, unsigned char*, 0x4F) = 0x20U;
                        goto setSubstateFour;
                    }
                    goto clearExtraHandle;
                case 3:
                case 5:
                    if (Controller78288Field(owner, unsigned char*, 0x4F) == 0) {
                        Controller78288Field(owner, unsigned char*, 0x4F) = 0x20U;
                    }
                    Controller78288Field(owner, unsigned char*, 0x46) =
                        (unsigned char)(Controller78288Field(owner, unsigned char*, 0x46) - 8);
                    Controller78288Field(owner, unsigned char*, 0x4F) =
                        (unsigned char)(Controller78288Field(owner, unsigned char*, 0x4F) + 5);
                    Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
                    if ((unsigned char)Controller78288Field(owner, unsigned char*, 0x4F) >= 0x7FU) {
                        Controller78288SpawnParticle(6, 0xC, owner, 5);
                        if (Controller78288Field(tag, unsigned char*, 2) == 2) {
                            oldPrimaryHandle = Controller78288Field(tag, int**, 8);
                            if (oldPrimaryHandle != 0) {
                                Controller78288Field(oldPrimaryHandle, signed char*, 0x10) = 0;
                            }
                            Controller78288DeleteMoby(owner);
                            return;
                        }
                        Controller78288Field(owner, signed char*, 0x41) = 0;
                        Controller78288Field(owner, signed char*, 0x4C) = 0;
                        Controller78288Field(owner, unsigned char*, 0x4D) = 0U;
                        {
                            register int state __asm__("$3") =
                                Controller78288Field(owner, unsigned char*, 0x49);
                            register int five __asm__("$2") = 5;
                            MATCHING_KEEP2(state, five);
                            if (state != five)
                                goto caseThreeOne;
                        }
                        nextSubstate = 6;
                        goto storeSubstate;
                    caseThreeOne:
                        nextSubstate = 1;
                        goto storeSubstate;
                    }
                    Controller78288SpawnParticle(1, 0xC, owner, 3);
                    goto clearExtraHandle;
                case 4:
                    tagKind = Controller78288Field(tag, unsigned char*, 2);
                    if (tagKind != 2) {
                        if (tagKind == 1) {
                            if (Controller78288Helper37BBC(owner, 0xC) != 0) {
                                Controller78288Helper512E4(owner, 0, 0);
                                {
                                    register int diff __asm__("$4") = Controller78288D_8006C550;
                                    register int product __asm__("$3");
                                    register int bank __asm__("$2");
                                    MATCHING_KEEP(diff);
                                    diff = (int)owner - diff;
                                    product = -(diff * 0x45D1745D);
                                    MATCHING_KEEP_CLOBBER(product, "$2");
                                    bank = Controller78288D_8006C79C;
                                    product >>= 3;
                                    product += bank;
                                    MATCHING_KEEP(product);
                                    bank = Controller78288D_8006C58C;
                                    MATCHING_KEEP_CLOBBER(bank, "$4");
                                    diff = (int)Controller78288D_80071AB0;
                                    MATCHING_KEEP2(diff, bank);
                                    bank <<= 5;
                                    bank = bank + diff;
                                    MATCHING_KEEP(bank);
                                    diff = product >> 5;
                                    MATCHING_KEEP(diff);
                                    diff *= 4;
                                    diff += bank;
                                    MATCHING_KEEP_CLOBBER(diff, "$3");
                                    product &= 31;
                                    bank = *(int*)diff;
                                    product = tagKind << product;
                                    bank |= product;
                                    *(int*)diff = bank;
                                }
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                                Controller78288Field(owner, unsigned char*, 0x49) = 7U;
                            }
                        } else {
                            Controller78288TurnMobyTowardPlayer(owner, 4, 0, 0);
                            Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
                            if (distanceResult >= 0x2801) {
                                Controller78288Field(owner, unsigned char*, 0x49) = 3U;
                            } else if (distanceResult < 0x1000) {
                                ownerHeight = Controller78288Field(owner, int*, 0x14) -
                                              Controller78288Field(owner, short*, 0x38);
                                heightDelta = ownerHeight - Controller78288Field(
                                                                Controller78288D_80070328, int*, 8);
                                if (heightDelta >= 0) {
                                    if (heightDelta < 0x800) {
                                        goto checkHeightAndPlayer;
                                    }
                                } else if ((Controller78288Field(Controller78288D_80070328, int*,
                                                                 8) -
                                            ownerHeight) < 0x800) {
                                checkHeightAndPlayer:
                                    playerHeightAddress = Controller78288D_80070328 + 8;
                                    if ((((Controller78288Field(owner, int*, 0x14) -
                                           Controller78288Field(owner, short*, 0x38)) -
                                          Controller78288Field(Controller78288D_80070328, int*,
                                                               8)) >= -0x1F3) &&
                                        ((Controller78288Field(Controller78288D_80070328, int*,
                                                               0x50) < 5) ||
                                         ((unsigned int)(Controller78288Field(
                                                             Controller78288D_80070328, int*,
                                                             0x50) -
                                                         0xB) < 2U))) {
                                        Controller78288CopyVector(&frame.first.x,
                                                                  playerHeightAddress + 0x90);
                                        {
                                            register void* vector __asm__("$4") = &frame.first.x;
                                            register int six __asm__("$5") = 6;
                                            register int x __asm__("$2") = frame.first.x;
                                            register int z __asm__("$3") = frame.first.z;
                                            MATCHING_KEEP4(vector, six, x, z);
                                            x <<= 5;
                                            frame.first.x = x;
                                            x = frame.first.y;
                                            z <<= 5;
                                            frame.first.z = z;
                                            MATCHING_KEEP_VOLATILE_CLOBBER(x, "memory");
                                            x <<= 5;
                                            frame.first.y = x;
                                            Controller78288ShiftVectorRightTowardZero(vector, six);
                                        }
                                        Controller78288AddVector(&frame.first.x, &frame.first.x,
                                                                 playerHeightAddress - 8);
                                        if (distanceResult >= 0x800) {
                                            if (Controller78288ApproximatePlanarDistance(
                                                    owner + 0xC, &frame.first.x) < 0x800) {
                                                goto enterStateOneFromRange;
                                            }
                                        } else {
                                            goto enterStateOne;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                    enterStateOneFromRange:
                    enterStateOne:
                        Controller78288Field(owner, unsigned char*, 0x48) = 1U;
                        Controller78288RequestMobyAnimation(owner, 1);
                    }
                    if ((Controller78288D_8006C644 & 0xF) < 2) {
                        {
                            register void* vector __asm__("$17") = &frame.second.x;
                            register void* argument __asm__("$4") = vector;
                            MATCHING_KEEP_CLOBBER(argument, "$16");
                            savedOwnerPosition = owner + 0xC;
                            Controller78288CopyVector(argument, savedOwnerPosition);
                        }
                        Controller78288InterpolateMobyVertex(owner, 0, savedOwnerPosition);
                        Controller78288SpawnParticle(1, 0xC, owner, 3);
                        Controller78288CopyVector(savedOwnerPosition, &frame.second.x);
                    }
                    goto clearExtraHandle;
                case 6:
                    if (distanceResult >= 0x2801) {
                        Controller78288Field(owner, unsigned char*, 0x49) = 1U;
                    }
                    goto clearExtraHandle;
                case 7:
                    if (Controller78288D_8006E344 != 1) {
                        goto setSubstateFour;
                    }
                    goto clearExtraHandle;
            }
            goto clearExtraHandle;
        setSubstateFour:
            nextSubstate = 4;
        storeSubstate:
            Controller78288Field(owner, unsigned char*, 0x49) = nextSubstate;
        clearExtraHandle:
            extraHandle = Controller78288Field(tag, int**, 0xC);
            if (extraHandle != 0) {
                Controller78288Field(extraHandle, signed char*, 0x1C) = 0;
                Controller78288Field(tag, int**, 0xC) = 0;
            }
            goto updatePrimaryHandle;
        case 1:
            if (Controller78288Field(tag, unsigned char*, 2) == state) {
                Controller78288Field(Controller78288D_80070328, int*, 0x20C) = 0x10000002;
                Controller78288Helper492DC(ownerPositionWord);
            }
            phaseResult = Controller78288Helper55E84(owner);
            ownerIndex = Controller78288Field(tag, int*, 0x10);
            if (ownerIndex >= 0) {
                indexedOwner = (ownerIndex * 0x58) + Controller78288D_8006C550;
                Controller78288TurnMobyTowardHeading(
                    owner,
                    Controller78288PlanarHeadingLookup(
                        Controller78288Field(indexedOwner, int*, 0xC) -
                            Controller78288Field(owner, int*, 0xC),
                        Controller78288Field(indexedOwner, int*, 0x10) -
                            Controller78288Field(owner, int*, 0x10),
                        0),
                    6, 0, 0, 0);
            } else {
                Controller78288TurnMobyTowardPlayer(owner, 6, 0, 0);
            }
            Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
            if (phaseResult < 0x14) {
                if ((Controller78288Field(tag, unsigned char*, 2) != 2) &&
                    (distanceResult >= 0x1001)) {
                    Controller78288Field(owner, unsigned char*, 0x48) = 0U;
                    Controller78288RequestMobyAnimation(owner, 0);
                }
            } else if (({
                           register int within __asm__("$2") = phaseResult < 0x1F;
                           MATCHING_KEEP_CLOBBER(within, "$3");
                           within;
                       })) {
                if (Controller78288Field(owner, unsigned char*, 0x49) != 5) {
                    Controller78288CopyVector(&frame.second.x, owner + 0xC);
                    savedSelector = Controller78288Field(tag, unsigned char*, 4);
                    heightResult = Controller78288Helper1A358(&frame.second.x, 0x800);
                    frame.second.z = heightResult;
                    if (heightResult == 0) {
                        frame.second.z = Controller78288Field(Controller78288D_80070328, int*, 8);
                    }
                    Controller78288Helper3B634(Controller78288D_8006D088, &frame.second.x,
                                               savedSelector);
                    Controller78288PlayMobySoundEvent(owner, 0, 0x80);
                    Controller78288Field(owner, unsigned char*, 0x49) = 5U;
                }
                {
                    register void* handle __asm__("$2") = Controller78288Field(tag, void**, 0xC);
                    register void* prepared __asm__("$4") = owner;
                    if (handle != 0)
                        goto handleReady;
                    {
                        register int close __asm__("$2") = distanceResult < 0x1000;
                        MATCHING_KEEP_CLOBBER(close, "$4");
                        prepared = (void*)4;
                        if (close) {
                            MATCHING_KEEP(prepared);
                            Controller78288Field(tag, void**, 0xC) =
                                Controller78288Helper2F540((int)prepared, 1, 0x608080);
                        }
                    }
                    handle = Controller78288Field(tag, void**, 0xC);
                    prepared = owner;
                    if (handle == 0)
                        goto handleFinished;
                handleReady:
                    MATCHING_KEEP(prepared);
                    Controller78288InterpolateMobyVertex(prepared, 0, &frame.third.x);
                    Controller78288CopyVector(Controller78288Field(tag, int**, 0xC),
                                              &frame.third.x);
                    {
                        register int index __asm__("$3") = Controller78288Field(tag, int*, 0x10);
                        register int offset __asm__("$2");
                        if (index >= 0) {
                            offset = index * 0x58;
                            __asm__("" : "=r"(offset) : "0"(offset) : "$4", "$5");
                            extraPosition = Controller78288Field(tag, unsigned char**, 0xC);
                            extraTarget = (unsigned char*)Controller78288D_8006C550;
                            MATCHING_KEEP2(extraPosition, extraTarget);
                            extraPosition += 12;
                            extraTarget += offset;
                            extraTarget += 12;
                        } else {
                            extraPosition = Controller78288Field(tag, unsigned char**, 0xC);
                            extraTarget = Controller78288D_80070328;
                            MATCHING_KEEP2(extraPosition, extraTarget);
                            extraPosition += 12;
                        }
                    }
                    Controller78288CopyVector(extraPosition, extraTarget);
                }
            handleFinished:
                {
                    register void* argument __asm__("$4");
                    argument = &frame.fourth.x;
                    MATCHING_KEEP_CLOBBER(argument, "$16");
                    particleOwnerPosition = owner + 0xC;
                    Controller78288CopyVector(argument, particleOwnerPosition);
                }
                {
                    register int index __asm__("$3") = Controller78288Field(tag, int*, 0x10);
                    register void* prepared __asm__("$4");
                    MATCHING_KEEP_CLOBBER(index, "$4");
                    prepared = particleOwnerPosition;
                    if (index >= 0) {
                        register int offset __asm__("$2") = index * 11;
                        MATCHING_KEEP_CLOBBER(offset, "$5");
                        particleTarget = (unsigned char*)Controller78288D_8006C550;
                        offset *= 8;
                        particleTarget += offset;
                        particleTarget += 12;
                    } else
                        particleTarget = Controller78288D_80070328;
                    Controller78288CopyVector(prepared, particleTarget);
                }
                Controller78288SpawnParticle(1, 0xC, owner, 3);
                Controller78288CopyVector(owner + 0xC, &frame.fourth.x);
            } else {
                cleanupHandle = Controller78288Field(tag, int**, 0xC);
                if (cleanupHandle != 0) {
                    Controller78288Field(cleanupHandle, signed char*, 0x1C) = 0;
                    {
                        register int minusOne __asm__("$2") = -1;
                        MATCHING_KEEP_CLOBBER(minusOne, "memory");
                        Controller78288Field(tag, int**, 0xC) = 0;
                        Controller78288Field(tag, int*, 0x10) = minusOne;
                    }
                }
            }
            if ((Controller78288Field(tag, short*, 6) < 0) &&
                (Controller78288Field(tag, unsigned char*, 2) != 1)) {
                Controller78288Field(owner, int*, 0x14) =
                    (int)(Controller78288Field(owner, int*, 0x14) + 0x20);
                Controller78288Field(tag, short*, 6) =
                    (short)((unsigned short)Controller78288Field(tag, short*, 6) + 0x20);
            }
            if (Controller78288D_8006C770 != 0) {
                if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                    Controller78288Field(owner, unsigned char*, 0x49) = 4U;
                    if ((Controller78288Field(tag, int*, 0x14) != 0) &&
                        (Controller78288D_8006E044 == 0x11)) {
                        Controller78288D_8006E160 = 0;
                        Controller78288Field(tag, int*, 0x14) = 0;
                    }
                }
                Controller78288Field(owner, unsigned char*, 0x48) = 0U;
                Controller78288RequestMobyAnimation(owner, 0);
            }
            goto updatePrimaryHandle;
    }

updatePrimaryHandle:
    MATCHING_KEEP_VOLATILE(distanceResult);
    {
        register void* handle __asm__("$2") = Controller78288Field(tag, void**, 8);
        MATCHING_KEEP_CLOBBER(handle, "$3");
        scaledDistance = distanceResult >> 6;
        if (handle == 0) {
            allocatedHandle =
                Controller78288Helper2EC50(4, 0x40, ({
                                               register int zero __asm__("$6");
                                               MATCHING_KEEP_VOLATILE_CLOBBER(handle, "$6");
                                               zero = 0;
                                               zero;
                                           }));
            Controller78288Field(tag, int**, 8) = allocatedHandle;
            if (allocatedHandle != 0) {
                MATCHING_KEEP_VOLATILE(distanceResult);
                scaledDistance = distanceResult >> 6;
                MATCHING_KEEP(scaledDistance);
                goto clampPrimaryHandle;
            }
        } else {
        clampPrimaryHandle:
            clampTest = scaledDistance < 0x50;
            if (clampTest) {
                scaledDistance = 0x50;
                MATCHING_KEEP(scaledDistance);
            }
            clampTest = scaledDistance < 0xA1;
            if (!clampTest)
                scaledDistance = 0xA0;
            Controller78288Field(Controller78288Field(tag, int**, 8), signed char*, 0x11) =
                (signed char)scaledDistance;
            colourChannel = ((int)(*(unsigned short*)(Controller78288D_80065920 +
                                                      ((Controller78288D_8006C644 * 8) & 0x1F8))
                                   << 0x10) >>
                             0x17) +
                            0x70;
            Controller78288Field(Controller78288Field(tag, int**, 8), int*, 0xC) =
                (int)(({
                          register int colour __asm__("$3") = colourChannel << 8;
                          MATCHING_KEEP(colour);
                          colour = colourChannel + colour;
                          MATCHING_KEEP(colour);
                          colour;
                      }) +
                      ((colourChannel >> 1) << 0x10));
            if (Controller78288Field(owner, unsigned char*, 0x4D) != 0) {
                Controller78288InterpolateMobyVertex(owner, 0, &frame.first.x);
                {
                    register void* first __asm__("$4") = &frame.first.x;
                    register void* second __asm__("$5") = first;
                    MATCHING_KEEP2_CLOBBER(first, second, "$16");
                    handleOwnerPosition = owner + 12;
                    Controller78288SubtractVector(first, second, handleOwnerPosition);
                }
                Controller78288ShiftVectorLeft(&frame.first.x, 5);
                Controller78288DivideVector(&frame.first.x, &frame.first.x,
                                            Controller78288Field(owner, unsigned char*, 0x4F));
                Controller78288AddVector(Controller78288Field(tag, int**, 8), handleOwnerPosition,
                                         &frame.first.x);
                return;
            }
            Controller78288CopyVector(Controller78288Field(tag, int**, 8), owner + 0xC);
            return;
        }
    }
}

#undef Controller78288Field


typedef struct {
    short x, y, z;
    unsigned char roll, reserved07, pitch, reserved09, yaw, reserved0B;
    short timer, lifetime, reserved10, mode;
} DecodedFragmentUpdate;
extern int D_8006C648, D_8006C640;
extern Vector3D D_80071918;
int rand(void);
int func_80019194(Vector3D*, int);
int func_8004EF74(Vector3D*, Vector3D*, Vector3D*);
int func_8003636C(int, int);
void func_level_15_80077C7C(Moby* moby) {
    DecodedFragmentUpdate* tag = moby->mobyTag;
    Vector3D vector;
    /* Retail reserves further frame storage; its source purpose is unknown. */
    int reservedStack;
    if (tag->lifetime == 0)
        return;
    if (tag->lifetime >= 2) {
        tag->lifetime -= D_8006C648;
        if (tag->lifetime <= 0)
            tag->lifetime = 1;
    }
    if (func_800359A4(&tag->timer, 2) || (!moby->drawn && tag->lifetime == 1)) {
        SpawnParticle(8, 0x46, &moby->position, (Vector3D*)0x10);
        func_80055B18(moby);
        return;
    }
    if (func_80019194(&moby->position, 0x12C)) {
        vector.x = tag->x;
        vector.y = tag->y;
        vector.z = tag->z;
        if (func_8004EF74(&vector, &D_80071918, &vector)) {
            tag->x = vector.x;
            tag->y = vector.y;
            tag->z = vector.z;
        }
    }
    moby->position.x += tag->x;
    moby->position.y += tag->y;
    if (tag->mode == 3)
        tag->z -= 5;
    else
        tag->z -= 10;
    if (tag->z < -0xC8)
        tag->z = -0xC8;
    moby->position.z += tag->z;
    moby->angle.roll += tag->roll;
    moby->angle.pitch += tag->pitch;
    moby->angle.yaw += tag->yaw;
    if (tag->mode != 2 && D_8006C640 % 5 == 0) {
        vector.x = rand() & 3;
        vector.y = rand() & 3;
        vector.z = 0x14;
        if (tag->mode == 1)
            SpawnParticle(1, 0, &moby->position, &vector);
        else if (tag->mode == 0)
            SpawnParticle(1, 1, &moby->position, &vector);
        else if (tag->mode == 3) {
            vector.x = tag->x >> 2;
            vector.y = tag->x >> 2;
            vector.z = tag->z >> 2;
            vector.z += func_8003636C(0xA, 0x14);
            SpawnParticle(1, 0x27, &moby->position, &vector);
        }
    }
}

int rand(void);
int func_80039714(Moby*);
extern int D_8006C640;
void func_level_15_80077F98(Moby* moby) {
    Vector3D offset;
    func_80039714(moby);
    if (moby->mobyClass == 0x17A && (D_8006C640 & 1)) {
        offset.x = rand() & 3;
        offset.y = rand() & 3;
        offset.z = 0x14;
        SpawnParticle(1, 1, &moby->position, &offset);
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007802C.
* Assembly SHA256 06d6580777a9e071a11285d5985a55270b927191481da05d68d9025ecab7a7bc.
* AI generated; not human reviewed. All1024 original instructions and22
* selector words and actual targets are required. Frame0xB8 retains
* S0..S4/RA and the full136-byte SP18..9F local extent. Common incoming,
* spawn/vector,shrink,group-spawn and particle sections reuse verified
* func_level_50_80081180 C with this target's original stack addresses.
* New child behavior remains independently decoded from this original.
* Three ordinary signed division-by3 sequences,variable DIV,complete low
* products,signed trig inputs,shifts11/12,timer/clamp control,retained S1
* literal and independent pre/post-helper child reloads remain exact.
* The two child angle consumers retain different original callees:
* func8004F264 and func8003613C. Their complete original arguments and
* physical transfers are independently required. Reused argument producers
* and consumers refer to the same fully initialized C object.
* Empty initialized dependencies,late consumers and dead clobbers emit0
* instructions. No partial HI,FP shortcut,live-alias overlap or opcode
* assembly. Confidence is binary identity after all gates. Raw units/fixed
* point,full helper contracts,caller cadence and synchronized runtime remain
* open. Cadence is per invocation. Falsification: every native/linked word,
* actual transfer/table target,original data byte,EXE and all overlay hashes. */
#define Actor15_7802CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor15_7802CCall1830CView1() __asm__("func_8001830C");
int Actor15_7802CCall1C288View1() __asm__("func_8001C288");
int Actor15_7802CCountTimerDownView1() __asm__("func_800359A4");
int Actor15_7802CSubAngle8View1() __asm__("func_8003613C");
int Actor15_7802CRandBetweenView1() __asm__("func_8003636C");
int Actor15_7802CRandSignedBetweenView1() __asm__("func_800363DC");
int Actor15_7802CPlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor15_7802CCall3BE70View1() __asm__("func_8003BE70");
int Actor15_7802CCall3BFC0View1() __asm__("func_8003BFC0");
int Actor15_7802CCall3C014View1() __asm__("func_8003C014");
int Actor15_7802CPlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor15_7802CBuildPackedAngleBasisMatrixView1() __asm__("func_8004EA90");
int Actor15_7802CTransformVectorByBasisView1() __asm__("func_8004ED6C");
int Actor15_7802CMeasureVectorLengthView1() __asm__("func_8004EDE8");
int Actor15_7802CScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Actor15_7802CShiftVectorLeftView1() __asm__("func_8004F0E8");
int Actor15_7802CShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Actor15_7802CCopyVectorView1() __asm__("func_8004F178");
int Actor15_7802CAddVectorView1() __asm__("func_8004F194");
int Actor15_7802CAbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor15_7802CApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor15_7802CDeleteMobyView1() __asm__("func_80055B18");
int Actor15_7802CRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor15_7802CInterpolateMobyVertexView1() __asm__("func_80055F14");
int Actor15_7802CCallrandView1() __asm__("rand");
extern int Actor15_7802CData658A0View1 __asm__("D_800658A0");
extern int Actor15_7802CData65920View1 __asm__("D_80065920");
extern int Actor15_7802CData6C550View1 __asm__("D_8006C550");
extern int Actor15_7802CData6C574View1 __asm__("D_8006C574");
extern int Actor15_7802CData6C578View1 __asm__("D_8006C578");
extern int Actor15_7802CData6C640View1 __asm__("D_8006C640");
extern int Actor15_7802CData6C7E8View1 __asm__("D_8006C7E8");
extern int Actor15_7802CData6E020View1 __asm__("D_8006E020");
extern int Actor15_7802CData6E024View1 __asm__("D_8006E024");
extern unsigned short Actor15_7802CData6E040View1 __asm__("D_8006E040");
extern int Actor15_7802CData6EE2CView1 __asm__("D_8006EE2C");
extern int Actor15_7802CData70328View1 __asm__("D_80070328");
extern void* (*Actor15_7802CDataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor15_7802CDataSpawnParticleView1)() __asm__("SpawnParticle");
extern int (*Actor15_7802CData743E8View1)() __asm__("unk_ovlheader_800743E8");
void func_level_15_8007802C(void* input) {
    register void* ownerRecord20 __asm__("$20");
    register int retainedWord16 __asm__("$16"), retainedWordOrAddress17 __asm__("$17"),
        retainedAngleOrRecord18 __asm__("$18"), privateRecord19 __asm__("$19");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64;
        unsigned char sp68, sp69, sp6A, sp6B;
        int sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C;
    } originalFrame;
    int completeLowProduct;
    int divisionWord;
    int distanceWord;
    void* reuse708_temp_v0_5;
    void* reuse708_temp_v1;
    void* ownerPositionAddress;
    void* particleCountdownAddress;
    int* temporaryWord2;
    int temporaryWord4;
    int temporaryWord8;
    int temporaryWord11;
    unsigned short temporaryWord10;
    unsigned char temporaryWord1;
    unsigned char temporaryWord9;
    void* temporaryPointer3;
    void* childRecord;
    void* firstChildReload;
    void* secondChildReload;
    ownerRecord20 = input;
    MATCHING_KEEP(ownerRecord20);
    privateRecord19 = (int)Actor15_7802CField(ownerRecord20, void**, 0);
    if (Actor15_7802CField(ownerRecord20, int*, 0x18) & 0x100000) {
        rawWord2 = 2;
        argumentWord4 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x48);
        MATCHING_KEEP(argumentWord4);
        rawWord3 = argumentWord4 & 255;
        if (rawWord3 == rawWord2)
            goto incomingStateReady;
        rawWord2 = argumentWord4 - 20;
        if ((unsigned int)rawWord2 < 2)
            goto incomingStateReady;
        {
            reuse708_temp_v1 = Actor15_7802CField(privateRecord19, void**, 0x44);
            if (reuse708_temp_v1 != 0) {
                Actor15_7802CField(reuse708_temp_v1, signed char*, 0x49) = 4;
                Actor15_7802CField(privateRecord19, void**, 0x44) = 0;
            }
            if (Actor15_7802CCall3BFC0View1(ownerRecord20,
                                            Actor15_7802CField(privateRecord19, int*, 0x4C)) != 0) {
                Actor15_7802CCall3BE70View1(Actor15_7802CField(privateRecord19, int*, 0x4C));
            }
            Actor15_7802CField(privateRecord19, int*, 0x4C) = -1;
            Actor15_7802CPlayMobySoundEventView1(ownerRecord20, 3, 1);
            Actor15_7802CPlayMobySoundEventView1(ownerRecord20, 0, 1);
            Actor15_7802CField(ownerRecord20, unsigned char*, 0x48) = 0x14U;
        }
    }
incomingStateReady:
    if ((Actor15_7802CData6C640View1 == 0) &&
        (Actor15_7802CField(ownerRecord20, unsigned char*, 0x48) == 0) &&
        ((temporaryWord8 = Actor15_7802CField(privateRecord19, int*, 0x3C),
          (temporaryWord8 == -1)) ||
         (Actor15_7802CField(((temporaryWord8 * 0x58) + Actor15_7802CData6C550View1),
                             unsigned char*, 0x48) != 2))) {
        Actor15_7802CField(ownerRecord20, signed char*, 0x4A) = 0;
        Actor15_7802CField(ownerRecord20, int*, 8) = 0;
        Actor15_7802CField(ownerRecord20, signed char*, 0x41) = 0;
        Actor15_7802CField(ownerRecord20, signed char*, 0x4C) = 0;
        Actor15_7802CField(ownerRecord20, signed char*, 0x4D) = 0;
        Actor15_7802CField(ownerRecord20, unsigned char*, 0x48) = 0xAU;
    }
    temporaryWord9 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x48);
    switch (temporaryWord9) {
        case 0:
        case 1:
            if (Actor15_7802CData6C640View1 == ((Actor15_7802CData6C640View1 / 3) * 3)) {
                ownerPositionAddress = ownerRecord20 + 0xC;
                if ((Actor15_7802CData6C578View1 - Actor15_7802CData6C574View1) >= 0x15) {
                    retainedAngleOrRecord18 = Actor15_7802CDataSpawnMobyView1(
                        Actor15_7802CField(ownerRecord20, short*, 0x36), ownerRecord20);
                    if (retainedAngleOrRecord18 != 0) {
                        Actor15_7802CField(retainedAngleOrRecord18, signed char*, 0x4C) = 0x50;
                        Actor15_7802CField(retainedAngleOrRecord18, signed char*, 0x4E) = 0x50;
                        Actor15_7802CRefreshMobySpatialGridAndBasisView1(ownerRecord20, 4);
                        Actor15_7802CInterpolateMobyVertexView1(ownerRecord20, 0,
                                                                &originalFrame.sp18);
                        argumentWord4 = (int)ownerRecord20;
                        argumentWord5 = 1;
                        MATCHING_OBSERVE2_GNU_VOLATILE(argumentWord4, argumentWord5);
                        retainedWordOrAddress17 = (int)&originalFrame.sp28;
                        Actor15_7802CInterpolateMobyVertexView1(argumentWord4, argumentWord5,
                                                                retainedWordOrAddress17);
                        retainedWord16 = retainedAngleOrRecord18 + 0xC;
                        Actor15_7802CAddVectorView1(retainedWord16, &originalFrame.sp18,
                                                    retainedWordOrAddress17);
                        Actor15_7802CShiftVectorRightTowardZeroView1(retainedWord16, 1);
                        rawWord2 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x45);
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x45) =
                            rawWord2;
                        rawWord3 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x46);
                        rawWord2 = Actor15_7802CField(retainedAngleOrRecord18, short*, 0x36);
                        argumentWord4 = 2;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x48) =
                            argumentWord4;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x42) = 0;
                        rawWord2 <<= 2;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x46) =
                            rawWord3;
                        rawWord2 = Actor15_7802CField(&Actor15_7802CData6EE2CView1, int*, rawWord2);
                        rawWord2 = Actor15_7802CField(rawWord2, int*, 0x44);
                        rawWord2 = Actor15_7802CField(rawWord2, unsigned char*, 0);
                        rawWord3 = 1;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x3C) =
                            argumentWord4;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x3D) =
                            argumentWord4;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x3E) = 0;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x3F) =
                            rawWord3;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x48) =
                            argumentWord4;
                        Actor15_7802CField(retainedAngleOrRecord18, int*, 8) = 0;
                        rawWord2 = (unsigned int)rawWord2 >= 2;
                        rawWord2 = -rawWord2;
                        rawWord2 &= 48;
                        Actor15_7802CField(retainedAngleOrRecord18, unsigned char*, 0x40) =
                            rawWord2;
                    }
                    goto prepareOwnerPosition;
                }
            } else {
            prepareOwnerPosition:
                ownerPositionAddress = ownerRecord20 + 0xC;
            }
            temporaryWord4 = Actor15_7802CApproximatePlanarDistanceView1(
                ownerPositionAddress, &Actor15_7802CData70328View1);
            Actor15_7802CField(privateRecord19, short*, 0xE) = 0x32;
            Actor15_7802CField(privateRecord19, unsigned short*, 0xC) = 0x12CU;
            if ((temporaryWord4 < 0x5000) &&
                (Actor15_7802CAbsoluteByteAngleDeltaView1(
                     Actor15_7802CField(&Actor15_7802CData70328View1, unsigned char*, 0xE),
                     Actor15_7802CPlanarHeadingLookupView1(
                         Actor15_7802CField(ownerRecord20, int*, 0xC) -
                             Actor15_7802CField(&Actor15_7802CData70328View1, int*, 0),
                         Actor15_7802CField(ownerRecord20, int*, 0x10) -
                             Actor15_7802CField(&Actor15_7802CData70328View1, int*, 4),
                         0)) < 0x40)) {
                if (temporaryWord4 < 0x3000) {
                    temporaryWord10 =
                        Actor15_7802CField(privateRecord19, unsigned short*, 0xC) + 0xAA;
                } else {
                    temporaryWord10 =
                        Actor15_7802CField(privateRecord19, unsigned short*, 0xC) + 0x6E;
                }
                Actor15_7802CField(privateRecord19, unsigned short*, 0xC) = temporaryWord10;
            }
            Actor15_7802CData743E8View1(ownerRecord20, Actor15_7802CField(privateRecord19, int*, 0),
                                        privateRecord19 + 8);
            childRecord = Actor15_7802CField(privateRecord19, void**, 0x44);
            if (childRecord == 0) {
                rawWord2 = Actor15_7802CAbsoluteByteAngleDeltaView1(
                    Actor15_7802CField(ownerRecord20, unsigned char*, 0x46),
                    Actor15_7802CPlanarHeadingLookupView1(
                        Actor15_7802CField(&Actor15_7802CData70328View1, int*, 0) -
                            Actor15_7802CField(ownerRecord20, int*, 0xC),
                        Actor15_7802CField(&Actor15_7802CData70328View1, int*, 4) -
                            Actor15_7802CField(ownerRecord20, int*, 0x10),
                        0));
                rawWord3 = 128;
                retainedAngleOrRecord18 = rawWord3 - rawWord2;
                rawWord2 = retainedAngleOrRecord18 < 49;
                argumentWord4 = privateRecord19 + 64;
                if (rawWord2)
                    goto updateChildCountdown;
                rawWord2 = Actor15_7802CField(privateRecord19, int*, 64);
                rawWord2 = rawWord2 < 30;
                if (!rawWord2)
                    goto updateChildCountdown;
                rawWord2 = 30;
                Actor15_7802CField(privateRecord19, int*, 64) = rawWord2;
                MATCHING_KEEP_GNU_VOLATILE(privateRecord19);
                argumentWord4 = privateRecord19 + 64;
            updateChildCountdown:
                if (Actor15_7802CCountTimerDownView1(argumentWord4, 4) != 0) {
                    rawWord2 =
                        (Actor15_7802CAbsoluteByteAngleDeltaView1(
                             ((int)(Actor15_7802CData6E040View1 << 0x10) >> 0x14),
                             Actor15_7802CPlanarHeadingLookupView1(
                                 Actor15_7802CField(ownerRecord20, int*, 0xC) -
                                     Actor15_7802CField(&Actor15_7802CData6E020View1, int*, 0),
                                 Actor15_7802CField(ownerRecord20, int*, 0x10) -
                                     Actor15_7802CData6E024View1,
                                 0)) < 0xC);
                    retainedWord16 = (int)ownerRecord20 + 12;
                    if (!rawWord2)
                        goto checkOwnerDistanceAndVector;
                    argumentWord4 = retainedWord16;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                    retainedWordOrAddress17 = (int)&Actor15_7802CData70328View1;
                    rawWord2 = Actor15_7802CApproximatePlanarDistanceView1(argumentWord4,
                                                                           retainedWordOrAddress17);
                    rawWord3 = 0x9FFF;
                    rawWord3 = rawWord3 < rawWord2;
                    argumentWord4 = retainedWord16;
                    if (rawWord3)
                        goto checkOwnerDistanceAndVector;
                    rawWord2 = Actor15_7802CApproximatePlanarDistanceView1(argumentWord4,
                                                                           retainedWordOrAddress17);
                    if (rawWord2 < 0x2801)
                        goto checkOwnerDistanceAndVector;
                    {
                        temporaryWord11 =
                            ((Actor15_7802CField(ownerRecord20, int*, 0x14) -
                              Actor15_7802CField(ownerRecord20, short*, 0x38)) -
                             Actor15_7802CField(&Actor15_7802CData70328View1, int*, 8)) +
                            Actor15_7802CField(&Actor15_7802CData70328View1, int*, 0x44);
                        if (temporaryWord11 < 0) {
                            temporaryWord11 = -temporaryWord11;
                        }
                        rawWord2 = temporaryWord11 < 0x1C00;
                        if (!rawWord2)
                            goto checkOwnerDistanceAndVector;
                        rawWord2 = retainedAngleOrRecord18 < 28;
                        argumentWord4 = 0x25C;
                        if (!rawWord2)
                            goto checkOwnerDistanceAndVector;
                        {
                            argumentWord5 = (int)ownerRecord20;
                            rawWord3 = (int)Actor15_7802CDataSpawnMobyView1;
                            MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord3, "$2");
                            rawWord2 = 180;
                            Actor15_7802CField(privateRecord19, int*, 64) = rawWord2;
                            rawWord2 = (int)((void* (*)())rawWord3)(argumentWord4, argumentWord5);
                            argumentWord4 = (int)ownerRecord20;
                            retainedWordOrAddress17 = 80;
                            Actor15_7802CField(privateRecord19, int*, 0x44) = rawWord2;
                            Actor15_7802CField(rawWord2, unsigned char*, 0x4C) =
                                retainedWordOrAddress17;
                            rawWord2 = Actor15_7802CField(privateRecord19, int*, 0x44);
                            argumentWord5 = 4;
                            Actor15_7802CField(rawWord2, unsigned char*, 0x4E) =
                                retainedWordOrAddress17;
                            rawWord2 = 1;
                            Actor15_7802CField(privateRecord19, short*, 0x48) = rawWord2;
                            rawWord2 = 30;
                            Actor15_7802CField(privateRecord19, short*, 0x4A) = rawWord2;
                            Actor15_7802CRefreshMobySpatialGridAndBasisView1(argumentWord4,
                                                                             argumentWord5);
                            Actor15_7802CInterpolateMobyVertexView1(ownerRecord20, 0,
                                                                    &originalFrame.sp18);
                            Actor15_7802CInterpolateMobyVertexView1(ownerRecord20, 1,
                                                                    &originalFrame.sp38);
                            Actor15_7802CAddVectorView1(
                                Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC,
                                &originalFrame.sp18, &originalFrame.sp38);
                            Actor15_7802CShiftVectorRightTowardZeroView1(
                                Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC, 1);
                            Actor15_7802CPlayMobySoundEventView1(ownerRecord20, 1, 1);
                            MATCHING_KEEP_GNU_VOLATILE(retainedWordOrAddress17);
                            Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                               signed char*, 0x4C) = retainedWordOrAddress17;
                            Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                               signed char*, 0x4E) = retainedWordOrAddress17;
                            Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                               unsigned char*, 0x46) =
                                (unsigned char)(Actor15_7802CField(ownerRecord20, unsigned char*,
                                                                   0x46) +
                                                0x80);
                        }
                    }
                }
                goto checkOwnerDistanceAndVector;
            }
            if (Actor15_7802CField(childRecord, unsigned char*, 0x49) == 5) {
                rawWord2 = Actor15_7802CCountTimerDownView1(privateRecord19 + 0x4A, 2);
                argumentWord6 = 0;
                if (rawWord2 == 0) {
                    retainedWord16 = (int)&Actor15_7802CData6E020View1;
                    MATCHING_KEEP(retainedWord16);
                    firstChildReload = Actor15_7802CField(privateRecord19, void**, 0x44);
                    if (Actor15_7802CAbsoluteByteAngleDeltaView1(
                            ((int)(Actor15_7802CField(retainedWord16, unsigned short*, 0x20)
                                   << 0x10) >>
                             0x14),
                            Actor15_7802CPlanarHeadingLookupView1(
                                Actor15_7802CField(firstChildReload, int*, 0xC) -
                                    Actor15_7802CField(retainedWord16, int*, 0),
                                Actor15_7802CField(firstChildReload, int*, 0x10) -
                                    Actor15_7802CField(retainedWord16, int*, 4),
                                argumentWord6)) < 0x31) {
                        secondChildReload = Actor15_7802CField(privateRecord19, void**, 0x44);
                        if ((Actor15_7802CAbsoluteByteAngleDeltaView1(
                                 ((int)(Actor15_7802CField(retainedWord16, unsigned short*, 0x20)
                                        << 0x10) >>
                                  0x14),
                                 Actor15_7802CPlanarHeadingLookupView1(
                                     Actor15_7802CField(secondChildReload, int*, 0xC) -
                                         Actor15_7802CField(retainedWord16, int*, 0),
                                     Actor15_7802CField(secondChildReload, int*, 0x10) -
                                         Actor15_7802CField(retainedWord16, int*, 4),
                                     0)) >= 0x1D) ||
                            (0, ((({
                                      argumentWord6 = 0;
                                      rawWord2 = Actor15_7802CField(privateRecord19, int*, 0x44);
                                      __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "$3");
                                      argumentWord7 =
                                          Actor15_7802CField(&Actor15_7802CData70328View1, int*, 0);
                                      rawWord3 =
                                          Actor15_7802CField(&Actor15_7802CData70328View1, int*, 4);
                                      __asm__ __volatile__("" ::"r"(argumentWord7), "r"(rawWord3)
                                                           : "$4", "$5");
                                      argumentWord4 = Actor15_7802CField(rawWord2, int*, 12);
                                      argumentWord5 = Actor15_7802CField(rawWord2, int*, 16);
                                      argumentWord4 = argumentWord7 - argumentWord4;
                                      argumentWord5 = rawWord3 - argumentWord5;
                                      rawWord2 = Actor15_7802CPlanarHeadingLookupView1(
                                          argumentWord4, argumentWord5, argumentWord6,
                                          argumentWord7);
                                      rawWord3 = Actor15_7802CField(privateRecord19, int*, 0x44);
                                      argumentWord4 =
                                          Actor15_7802CField(rawWord3, unsigned char*, 0x46);
                                      Actor15_7802CAbsoluteByteAngleDeltaView1(argumentWord4,
                                                                               rawWord2);
                                  }) < 0x41) == 0))) {
                            Actor15_7802CField(privateRecord19, short*, 0x48) = 0;
                        }
                        if (Actor15_7802CField(privateRecord19, short*, 0x48) != 0) {
                            if (Actor15_7802CData6C640View1 ==
                                ((Actor15_7802CData6C640View1 / 3) * 3)) {
                                argumentWord4 = Actor15_7802CSubAngle8View1(
                                    Actor15_7802CField(
                                        Actor15_7802CField(privateRecord19, void**, 0x44),
                                        unsigned char*, 0x45),
                                    Actor15_7802CPlanarHeadingLookupView1(
                                        ({
                                            argumentWord6 = 0;
                                            argumentWord4 =
                                                Actor15_7802CField(privateRecord19, int*, 0x44);
                                            MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4,
                                                                                  "$5");
                                            argumentWord5 = (int)&Actor15_7802CData70328View1;
                                            __asm__ __volatile__(""
                                                                 : "=r"(argumentWord4)
                                                                 : "0"(argumentWord4),
                                                                   "r"(argumentWord5));
                                            argumentWord4 += 12;
                                            Actor15_7802CApproximatePlanarDistanceView1(
                                                argumentWord4, argumentWord5, argumentWord6);
                                        }),
                                        Actor15_7802CField(&Actor15_7802CData70328View1, int*, 8) -
                                            Actor15_7802CField(
                                                Actor15_7802CField(privateRecord19, void**, 0x44),
                                                int*, 0x14),
                                        0));
                                rawWord2 = argumentWord4 < 2;
                                if (rawWord2) {
                                    rawWord2 = argumentWord4 < -1;
                                    goto checkFirstChildClamp;
                                }
                                argumentWord4 = 1;
                                MATCHING_KEEP(argumentWord4);
                                rawWord2 = argumentWord4 < -1;
                            checkFirstChildClamp:
                                if (rawWord2)
                                    argumentWord4 = -1;
                                rawWord3 = Actor15_7802CField(privateRecord19, void**, 0x44);
                                Actor15_7802CField(rawWord3, unsigned char*, 0x45) =
                                    (unsigned char)(Actor15_7802CField(rawWord3, unsigned char*,
                                                                       0x45) +
                                                    argumentWord4);
                            }
                            0;
                            argumentWord4 = ({
                                argumentWord6 = 0;
                                rawWord2 = Actor15_7802CField(privateRecord19, int*, 0x44);
                                __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "$3");
                                argumentWord7 =
                                    Actor15_7802CField(&Actor15_7802CData70328View1, int*, 0);
                                rawWord3 =
                                    Actor15_7802CField(&Actor15_7802CData70328View1, int*, 4);
                                __asm__ __volatile__("" ::"r"(argumentWord7), "r"(rawWord3)
                                                     : "$4", "$5");
                                argumentWord4 = Actor15_7802CField(rawWord2, int*, 12);
                                argumentWord5 = Actor15_7802CField(rawWord2, int*, 16);
                                argumentWord4 = argumentWord7 - argumentWord4;
                                argumentWord5 = rawWord3 - argumentWord5;
                                rawWord2 = Actor15_7802CPlanarHeadingLookupView1(
                                    argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                                rawWord3 = Actor15_7802CField(privateRecord19, int*, 0x44);
                                argumentWord4 = Actor15_7802CField(rawWord3, unsigned char*, 0x46);
                                Actor15_7802CSubAngle8View1(argumentWord4, rawWord2);
                            });
                            rawWord2 = argumentWord4 < 5;
                            if (rawWord2) {
                                rawWord2 = argumentWord4 < -4;
                                goto checkSecondChildClamp;
                            }
                            argumentWord4 = 4;
                            MATCHING_KEEP(argumentWord4);
                            rawWord2 = argumentWord4 < -4;
                        checkSecondChildClamp:
                            if (rawWord2)
                                argumentWord4 = -4;
                            rawWord3 = Actor15_7802CField(privateRecord19, void**, 0x44);
                            Actor15_7802CField(rawWord3, unsigned char*, 0x46) =
                                (unsigned char)(Actor15_7802CField(rawWord3, unsigned char*, 0x46) +
                                                argumentWord4);
                        }
                        Actor15_7802CCopyVectorView1(
                            &originalFrame.sp18,
                            Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC);
                        argumentWord5 = Actor15_7802CField(privateRecord19, int*, 0x44);
                        rawWord2 = Actor15_7802CField(argumentWord5, unsigned char*, 0x46);
                        rawWord2 <<= 1;
                        argumentWord4 =
                            Actor15_7802CField(&Actor15_7802CData65920View1, short*, rawWord2);
                        rawWord2 = Actor15_7802CField(argumentWord5, unsigned char*, 0x45);
                        rawWord3 = (unsigned int)argumentWord4 << 6;
                        rawWord3 += argumentWord4;
                        rawWord2 <<= 1;
                        rawWord2 =
                            Actor15_7802CField(&Actor15_7802CData65920View1, short*, rawWord2);
                        rawWord3 >>= 11;
                        completeLowProduct = rawWord3 * rawWord2;
                        rawWord2 = completeLowProduct >> 12;
                        originalFrame.sp28 = rawWord2;
                        argumentWord5 = Actor15_7802CField(privateRecord19, int*, 0x44);
                        rawWord2 = Actor15_7802CField(argumentWord5, unsigned char*, 0x46);
                        rawWord2 <<= 1;
                        argumentWord4 =
                            Actor15_7802CField(&Actor15_7802CData658A0View1, short*, rawWord2);
                        rawWord2 = Actor15_7802CField(argumentWord5, unsigned char*, 0x45);
                        rawWord3 = (unsigned int)argumentWord4 << 6;
                        rawWord3 += argumentWord4;
                        rawWord2 <<= 1;
                        rawWord2 =
                            Actor15_7802CField(&Actor15_7802CData65920View1, short*, rawWord2);
                        rawWord3 >>= 11;
                        completeLowProduct = rawWord3 * rawWord2;
                        rawWord2 = completeLowProduct >> 12;
                        originalFrame.sp2C = rawWord2;
                        rawWord2 = Actor15_7802CField(privateRecord19, int*, 0x44);
                        rawWord2 = Actor15_7802CField(rawWord2, unsigned char*, 0x45);
                        rawWord2 <<= 1;
                        rawWord3 =
                            Actor15_7802CField(&Actor15_7802CData658A0View1, short*, rawWord2);
                        rawWord2 = (unsigned int)rawWord3 << 6;
                        rawWord2 += rawWord3;
                        rawWord2 >>= 11;
                        originalFrame.sp30 = rawWord2;
                        temporaryWord2 = Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC;
                        Actor15_7802CAddVectorView1(temporaryWord2, temporaryWord2,
                                                    &originalFrame.sp28);
                        temporaryPointer3 = Actor15_7802CField(privateRecord19, void**, 0x44);
                        if ((Actor15_7802CField(temporaryPointer3, int*, 0xC) < 0x7D0) ||
                            (Actor15_7802CField(temporaryPointer3, int*, 0x10) < 0x7D0) ||
                            (Actor15_7802CField(temporaryPointer3, int*, 0x14) < 0x7D0) ||
                            (Actor15_7802CCall1C288View1(temporaryPointer3 + 0xC, 0x64, 7) != 0) ||
                            (Actor15_7802CCall1830CView1(
                                 &originalFrame.sp18,
                                 Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC, 3, 0,
                                 0) != 0)) {
                            goto clearChildRecord;
                        }
                        goto checkOwnerDistanceAndVector;
                    }
                }
            clearChildRecord:
                Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                   unsigned char*, 0x49) = 4U;
                Actor15_7802CField(privateRecord19, void**, 0x44) = 0;
                return;
            }
            Actor15_7802CRefreshMobySpatialGridAndBasisView1(ownerRecord20, 4);
            Actor15_7802CInterpolateMobyVertexView1(ownerRecord20, 0, &originalFrame.sp48);
            Actor15_7802CInterpolateMobyVertexView1(ownerRecord20, 1, &originalFrame.sp58);
            Actor15_7802CAddVectorView1(Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC,
                                        &originalFrame.sp48, &originalFrame.sp58);
            Actor15_7802CShiftVectorRightTowardZeroView1(
                Actor15_7802CField(privateRecord19, void**, 0x44) + 0xC, 1);
            if (Actor15_7802CCountTimerDownView1(privateRecord19 + 0x4A, 2) != 0) {
                Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                   unsigned char*, 0x46) =
                    (unsigned char)(Actor15_7802CField(ownerRecord20, unsigned char*, 0x46) + 0x80);
                argumentWord4 = Actor15_7802CSubAngle8View1(
                    Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                       unsigned char*, 0x46),
                    Actor15_7802CPlanarHeadingLookupView1(
                        Actor15_7802CField(&Actor15_7802CData70328View1, int*, 0) -
                            Actor15_7802CField(ownerRecord20, int*, 0xC),
                        Actor15_7802CField(&Actor15_7802CData70328View1, int*, 4) -
                            Actor15_7802CField(ownerRecord20, int*, 0x10),
                        0));
                rawWord2 = argumentWord4 < 2;
                if (rawWord2) {
                    rawWord2 = argumentWord4 < -1;
                    goto checkThirdChildClamp;
                }
                argumentWord4 = 1;
                MATCHING_KEEP(argumentWord4);
                rawWord2 = argumentWord4 < -1;
            checkThirdChildClamp:
                if (rawWord2)
                    argumentWord4 = -1;
                if (argumentWord4 == 0) {
                    argumentWord4 = 1;
                }
                rawWord3 = Actor15_7802CField(privateRecord19, void**, 0x44);
                Actor15_7802CField(rawWord3, unsigned char*, 0x46) =
                    (unsigned char)(Actor15_7802CField(rawWord3, unsigned char*, 0x46) +
                                    (argumentWord4 << 6));
                Actor15_7802CField(Actor15_7802CField(privateRecord19, void**, 0x44),
                                   unsigned char*, 0x49) = 5U;
                Actor15_7802CField(privateRecord19, short*, 0x4A) = 0xF0;
            }
        checkOwnerDistanceAndVector:
            distanceWord = Actor15_7802CApproximatePlanarDistanceView1(
                ownerRecord20 + 0xC, &Actor15_7802CData6E020View1);
            if (distanceWord >= 0x6401) {
                if (Actor15_7802CCall3BFC0View1(
                        ownerRecord20, Actor15_7802CField(privateRecord19, int*, 0x4C)) != 0) {
                    Actor15_7802CCall3BE70View1(Actor15_7802CField(privateRecord19, int*, 0x4C));
                }
                Actor15_7802CField(privateRecord19, int*, 0x4C) = -1;
                return;
            }
            if (distanceWord < 0x5000) {
                rawWord2 = Actor15_7802CCall3BFC0View1(
                    ownerRecord20, Actor15_7802CField(privateRecord19, int*, 0x4C));
                argumentWord4 = (int)ownerRecord20;
                if (rawWord2 == 0) {
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$5");
                    Actor15_7802CField(privateRecord19, int*, 0x4C) =
                        Actor15_7802CPlayMobySoundEventView1(argumentWord4, 2, 4);
                }
                rawWord3 = Actor15_7802CField(privateRecord19, int*, 0x4C);
                rawWord2 = -1;
                argumentWord4 = (int)&originalFrame.sp18;
                if (rawWord3 != rawWord2) {
                    MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                    rawWord2 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x46);
                    rawWord2 <<= 1;
                    rawWord3 = Actor15_7802CField(&Actor15_7802CData65920View1, short*, rawWord2);
                    rawWord2 = Actor15_7802CField(privateRecord19, short*, 12);
                    completeLowProduct = rawWord3 * rawWord2;
                    rawWord2 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x45);
                    rawWord2 <<= 1;
                    rawWord3 = Actor15_7802CField(&Actor15_7802CData65920View1, short*, rawWord2);
                    rawWord2 = completeLowProduct >> 12;
                    completeLowProduct = rawWord2 * rawWord3;
                    rawWord2 = completeLowProduct >> 12;
                    originalFrame.sp18 = rawWord2;
                    rawWord2 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x46);
                    rawWord2 <<= 1;
                    rawWord3 = Actor15_7802CField(&Actor15_7802CData658A0View1, short*, rawWord2);
                    rawWord2 = Actor15_7802CField(privateRecord19, short*, 12);
                    completeLowProduct = rawWord3 * rawWord2;
                    rawWord2 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x45);
                    rawWord2 <<= 1;
                    rawWord3 = Actor15_7802CField(&Actor15_7802CData65920View1, short*, rawWord2);
                    rawWord2 = completeLowProduct >> 12;
                    completeLowProduct = rawWord2 * rawWord3;
                    rawWord2 = completeLowProduct >> 12;
                    originalFrame.sp1C = rawWord2;
                    rawWord2 = Actor15_7802CField(ownerRecord20, unsigned char*, 0x45);
                    rawWord2 <<= 1;
                    rawWord3 = Actor15_7802CField(&Actor15_7802CData658A0View1, short*, rawWord2);
                    rawWord2 = Actor15_7802CField(privateRecord19, short*, 12);
                    completeLowProduct = rawWord3 * rawWord2;
                    argumentWord5 = 1;
                    rawWord2 = completeLowProduct >> 12;
                    originalFrame.sp20 = rawWord2;
                    Actor15_7802CShiftVectorLeftView1(argumentWord4, argumentWord5);
                    Actor15_7802CCall3C014View1(Actor15_7802CField(privateRecord19, int*, 0x4C),
                                                &originalFrame.sp18);
                    return;
                }
            } else {
                return;
            }
            break;
        case 2:
            if (Actor15_7802CCountTimerDownView1(privateRecord19 + 4, 4) == 0) {
                divisionWord =
                    0x4000 / (int)(0x320 - (Actor15_7802CField(privateRecord19, int*, 4) * 0xE));
                Actor15_7802CField(ownerRecord20, unsigned char*, 0x4F) =
                    (unsigned char)divisionWord;
                if ((unsigned int)(divisionWord & 0xFF) >= 0x80U) {
                    Actor15_7802CField(ownerRecord20, unsigned char*, 0x4F) = 0x7FU;
                }
                if ((unsigned char)Actor15_7802CField(ownerRecord20, unsigned char*, 0x4F) <
                    0x12U) {
                    Actor15_7802CField(ownerRecord20, unsigned char*, 0x4F) = 0x12U;
                }
                Actor15_7802CField(ownerRecord20, signed char*, 0x54) =
                    (signed char)(Actor15_7802CField(privateRecord19, int*, 4) * 2);
                Actor15_7802CField(ownerRecord20, signed char*, 0x55) =
                    (signed char)(Actor15_7802CField(privateRecord19, int*, 4) * 2);
                Actor15_7802CField(ownerRecord20, signed char*, 0x56) =
                    (signed char)(Actor15_7802CField(privateRecord19, int*, 4) * 2);
                return;
            }
            goto callSharedRemovalHelper;
        case 20:
            retainedWordOrAddress17 = 0;
            retainedAngleOrRecord18 = (int)((unsigned char*)&Actor15_7802CData70328View1 + 0x98);
            MATCHING_KEEP(retainedAngleOrRecord18);
        loop_37:
            if ((Actor15_7802CData6C578View1 - Actor15_7802CData6C574View1) >= 0x15) {
                retainedWord16 = Actor15_7802CDataSpawnMobyView1(0x2CB, ownerRecord20);
                MATCHING_KEEP(retainedWord16);
                if (retainedWord16 != 0) {
                    Actor15_7802CField(retainedWord16, signed char*, 0x4C) = 0x3F;
                    Actor15_7802CField(retainedWord16, unsigned char*, 0x4A) = 0xFF;
                    Actor15_7802CField(retainedWord16, signed char*, 0x3C) =
                        (signed char)(retainedWordOrAddress17 % 3);
                    retainedWord16 = Actor15_7802CField(retainedWord16, void**, 0);
                    originalFrame.sp18 = Actor15_7802CRandSignedBetweenView1(0x64, 0x190);
                    originalFrame.sp1C = Actor15_7802CRandSignedBetweenView1(0x64, 0x190);
                    originalFrame.sp20 = Actor15_7802CRandSignedBetweenView1(0x32, 0xC8);
                    Actor15_7802CScaleVectorRatioQ15View1(
                        &originalFrame.sp18,
                        Actor15_7802CMeasureVectorLengthView1(&originalFrame.sp18, 1), 0xF0);
                    Actor15_7802CField(retainedWord16, unsigned short*, 0) =
                        (unsigned short)originalFrame.sp18;
                    Actor15_7802CField(retainedWord16, unsigned short*, 2) =
                        (unsigned short)originalFrame.sp1C;
                    Actor15_7802CField(retainedWord16, short*, 4) = (short)originalFrame.sp20;
                    Actor15_7802CField(retainedWord16, unsigned short*, 0) =
                        (unsigned short)(Actor15_7802CField(retainedWord16, unsigned short*, 0) +
                                         ((int)Actor15_7802CField(retainedAngleOrRecord18, int*,
                                                                  0) >>
                                          5));
                    Actor15_7802CField(retainedWord16, unsigned short*, 2) =
                        (unsigned short)(Actor15_7802CField(retainedWord16, unsigned short*, 2) +
                                         ((int)Actor15_7802CField(retainedAngleOrRecord18, int*,
                                                                  4) >>
                                          5));
                    Actor15_7802CField(retainedWord16, short*, 4) =
                        Actor15_7802CRandBetweenView1(0x32, 0x8C);
                }
                retainedWordOrAddress17 += 1;
                if (retainedWordOrAddress17 >= 0xC) {
                    if (((Actor15_7802CData6C578View1 - Actor15_7802CData6C574View1) >= 0x15) &&
                        (Actor15_7802CData6C7E8View1 >= 0x7531)) {
                        reuse708_temp_v0_5 = Actor15_7802CDataSpawnMobyView1(0x146, ownerRecord20);
                        if (reuse708_temp_v0_5 != 0) {
                            Actor15_7802CField(reuse708_temp_v0_5, signed char*, 0x47) = 7;
                        }
                    }
                } else {
                    goto loop_37;
                }
            }
            rawWord2 = Actor15_7802CData6C578View1;
            rawWord3 = Actor15_7802CData6C574View1;
            rawWord2 -= rawWord3;
            rawWord2 = rawWord2 < 21;
            retainedWordOrAddress17 = 0;
            if (rawWord2)
                goto prepareState21Timer;
            retainedWord16 = 63;
        loop_47:
            rawWord2 = Actor15_7802CData6C7E8View1;
            rawWord2 = rawWord2 < 0x7531;
            argumentWord4 = 0x21D;
            if (!rawWord2) {
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                argumentWord4 = (int)Actor15_7802CDataSpawnMobyView1(argumentWord4, ownerRecord20);
                rawWord3 = retainedWordOrAddress17 << 1;
                if (argumentWord4 != 0) {
                    rawWord2 = Actor15_7802CField(privateRecord19, int*, 0x2C);
                    rawWord2 += rawWord3;
                    rawWord2 = Actor15_7802CField(rawWord2, unsigned char*, 0);
                    Actor15_7802CField(argumentWord4, unsigned char*, 0x46) = rawWord2;
                    rawWord2 = Actor15_7802CField(privateRecord19, int*, 0x2C);
                    rawWord3 += rawWord2;
                    rawWord3 = Actor15_7802CField(rawWord3, unsigned char*, 1);
                    rawWord2 = 8;
                    Actor15_7802CField(argumentWord4, unsigned char*, 0x47) = rawWord2;
                    Actor15_7802CField(argumentWord4, unsigned char*, 0x4C) = retainedWord16;
                    Actor15_7802CField(argumentWord4, unsigned char*, 0x4E) = retainedWord16;
                    Actor15_7802CField(argumentWord4, unsigned char*, 0x45) = rawWord3;
                }
                retainedWordOrAddress17 += 1;
                rawWord2 = retainedWordOrAddress17 < 7;
                if (!rawWord2) {
                    rawWord2 = 120;
                    goto storeState21Timer;
                }
                {
                    rawWord2 = Actor15_7802CData6C578View1;
                    rawWord3 = Actor15_7802CData6C574View1;
                    rawWord2 -= rawWord3;
                    rawWord2 = rawWord2 < 21;
                    if (!rawWord2)
                        goto loop_47;
                }
            }
        prepareState21Timer:
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            rawWord2 = 120;
        storeState21Timer:
            Actor15_7802CField(ownerRecord20, signed char*, 0x41) = 0;
            Actor15_7802CField(ownerRecord20, signed char*, 0x4C) = 0;
            Actor15_7802CField(ownerRecord20, signed char*, 0x4D) = 0;
            Actor15_7802CField(ownerRecord20, int*, 8) = 0;
            Actor15_7802CField(privateRecord19, int*, 4) = rawWord2;
            Actor15_7802CField(ownerRecord20, unsigned char*, 0x48) = 0x15U;
        case 21:
        updateParticleTail:
            particleCountdownAddress = privateRecord19 + 4;
            if (Actor15_7802CField(privateRecord19, int*, 4) >= 0x51) {
                retainedWordOrAddress17 = 0;
                do {
                    originalFrame.sp68 = 0;
                    originalFrame.sp69 = Actor15_7802CCallrandView1(particleCountdownAddress);
                    originalFrame.sp6A = Actor15_7802CCallrandView1();
                    Actor15_7802CBuildPackedAngleBasisMatrixView1(&originalFrame.sp68,
                                                                  &originalFrame.sp38, 0);
                    retainedWordOrAddress17 += 1;
                    originalFrame.sp18 = (Actor15_7802CCallrandView1() & 0x1F) + 0x64;
                    originalFrame.sp1C = 0;
                    originalFrame.sp20 = 0;
                    Actor15_7802CTransformVectorByBasisView1(
                        &originalFrame.sp38, &originalFrame.sp18, &originalFrame.sp18);
                    Actor15_7802CCopyVectorView1(&originalFrame.sp28, &originalFrame.sp18);
                    Actor15_7802CShiftVectorLeftView1(&originalFrame.sp28, 2);
                    Actor15_7802CAddVectorView1(&originalFrame.sp28, &originalFrame.sp28,
                                                ownerRecord20 + 0xC);
                    Actor15_7802CDataSpawnParticleView1(1, 0x3A, &originalFrame.sp28,
                                                        &originalFrame.sp18);
                    particleCountdownAddress = privateRecord19 + 4;
                } while (retainedWordOrAddress17 < 4);
            }
            if (Actor15_7802CCountTimerDownView1(particleCountdownAddress, 4) != 0) {
            callSharedRemovalHelper:
                Actor15_7802CDeleteMobyView1(ownerRecord20);
            }
            break;
    }
}
#undef Actor15_7802CField


typedef struct {
    Vector3D velocity;
    int timer;
} DecodedBoundedProjectileTag;
extern void (*DecodedBoundedProjectileBurst)(Vector3D*, int, int, int,
                                             int) __asm__("unk_ovlheader_80074410");
Moby* DecodedBoundedProjectileQuery(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
int func_80018368(Vector3D*, Vector3D*);
void func_level_15_8007902C(Moby* moby) {
    DecodedBoundedProjectileTag* tag = moby->mobyTag;
    Vector3D previous;
    Moby* target;
    switch (moby->state) {
        case 0:
            if (moby->position.x < 0x800 || moby->position.y < 0x800 || moby->position.z < 0x800)
                goto remove;
            if (func_800359A4(&tag->timer, 4))
                goto remove;
            if (moby->position.x > 0x3D400 || moby->position.y > 0x3D400 ||
                moby->position.z > 0x1E000)
                goto remove;
            if (!moby->substate) {
                func_8003BABC(moby, 0, 0);
                moby->substate = 1;
            }
            func_8004F178(&previous, &moby->position);
            func_8004F194(&moby->position, &moby->position, &tag->velocity);
            if (func_80018368(&previous, &moby->position)) {
                func_8004F178(&moby->position, &previous);
                moby->state = 1;
            } else {
                target = DecodedBoundedProjectileQuery(&moby->position, 0x177, 0, 0, 0x100000, 0);
                if (target) {
                    moby->state = 1;
                    target->unkb = func_8004E880(tag->velocity.x, tag->velocity.y, 0);
                    if (!target->unkb)
                        target->unkb = 1;
                }
            }
            func_80055D24(moby, 2);
            break;
        case 1:
            DecodedBoundedProjectileBurst(&moby->position, 0xD, 0xC, 0x19, 0x23);
        remove:
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_15/moby/func_level_15_8007920C.s SHA256 b3b263372bea62bfbbf7d4136a7319141f677f8bd9b83f1986745e2b62faa9b3. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level15_7920C_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level15_7920C_func_800135A4() __asm__("func_800135A4");
/* extern */
short Level15_7920C_func_8002803C() __asm__("func_8002803C");
/* extern */
int Level15_7920CSetMobyAnimation() __asm__("func_80034F80");
/* extern */
int Level15_7920C_func_800369D8() __asm__("func_800369D8");
/* extern */
int Level15_7920C_func_80037BBC() __asm__("func_80037BBC");
/* extern */
int Level15_7920C_func_8003B74C() __asm__("func_8003B74C");
/* extern */
int Level15_7920C_func_8003B7B4() __asm__("func_8003B7B4");
/* extern */
int Level15_7920CTransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
int Level15_7920CMeasureVectorLength() __asm__("func_8004EDE8");
/* extern */
int Level15_7920CSubtractVector() __asm__("func_8004F1C8");
/* extern */
int Level15_7920C_func_800512E4() __asm__("func_800512E4");
/* extern */
int Level15_7920CDeleteMoby() __asm__("func_80055B18");
/* extern */
int Level15_7920CRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int Level15_7920CInterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
int Level15_7920C_func_8005629C() __asm__("func_8005629C");
/* extern */
extern unsigned char Level15_7920C_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level15_7920C_D_80065920 __asm__("D_80065920");
extern unsigned char Level15_7920C_D_80068F7C __asm__("D_80068F7C");
extern unsigned char Level15_7920C_D_80068F90 __asm__("D_80068F90");
extern int Level15_7920C_D_8006C550 __asm__("D_8006C550");
extern int Level15_7920C_D_8006C598 __asm__("D_8006C598");
extern int Level15_7920C_D_8006C628 __asm__("D_8006C628");
extern unsigned char Level15_7920C_D_8006C62C __asm__("D_8006C62C");
extern int Level15_7920C_D_8006C640 __asm__("D_8006C640");
extern int Level15_7920C_D_8006C6C4 __asm__("D_8006C6C4");
extern int Level15_7920C_D_8006C6D0 __asm__("D_8006C6D0");
extern void* Level15_7920C_D_8006C730 __asm__("D_8006C730");
extern unsigned char Level15_7920C_D_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char Level15_7920C_D_8006C7F8 __asm__("D_8006C7F8");
extern unsigned char Level15_7920C_D_8006D088 __asm__("D_8006D088");
extern int Level15_7920C_D_8006E344 __asm__("D_8006E344");
extern int Level15_7920C_D_8006E538 __asm__("D_8006E538");
extern int Level15_7920C_D_8006FA40 __asm__("D_8006FA40");
extern Vector3D Level15_7920C_D_8006FA48 __asm__("D_8006FA48");
extern int Level15_7920C_D_8006FA50 __asm__("D_8006FA50");
extern int Level15_7920C_D_8006FA54 __asm__("D_8006FA54");
extern unsigned char Level15_7920C_D_80070328 __asm__("D_80070328");
extern unsigned char Level15_7920C_D_8007159A __asm__("D_8007159A");
extern unsigned char Level15_7920C_D_800719A8 __asm__("D_800719A8");
extern unsigned char Level15_7920C_D_800719F0 __asm__("D_800719F0");
extern unsigned char Level15_7920C_func_80027A60 __asm__("func_80027A60");
extern unsigned char Level15_7920C_func_80027EE4 __asm__("func_80027EE4");
extern unsigned char Level15_7920C_func_80029AA0 __asm__("func_80029AA0");
void func_level_15_8007920C(Moby* moby) {
    /* SCUS-94467 USA Rev0 address8007920C; original assembly/SHA above.
    * 753 original instructions; frame80 with raw vectors20/30/40, saves
    *16..23/30 at58..78 and RA7C. Owner19/private20 lifetimes retained.
    * Original pointer domains add BYTES: FA40+8, vector+10, player48+68
    * to playerB0, and the signed player148 halfword at B0+98. Matrix18,
    * playerB0 and table22/23 roles retain their original constructors.
    * Tables use signed LH words. Literal2496 remains the original signed
    * MULT/SRA12 chain; combined C products permit original scratch8 in all
    * paths, without a fixed8 variable reserving it across the function.
    * The old item is processed, then its signed halfword decides the back
    * edge before byte2 cursor advancement. Record state keeps the original
    * full-word mask. The masked index and byte88 record addresses retain
    * the original pool-base-first ADDU operands.
    * The indirect header call explicitly projects original input4 owner
    * and input5 literalAF; the SDK placeholder and callee remain unchanged.
    * This proves caller inputs, not the full callee contract or meaning.
    * Random calls independently rebuild their original arguments, and SP48
    * is stored before matrix-helper entry. Player148 halfword3 is read
    * before SP38 store, as on disc; its initialized zero-path observer keeps
    * literal-zero5 independent of3. Zero/flag/byte stores precede original
    * consumers and increments. Shared callbacks remain at the original tail.
    * Every empty constraint consumes initialized original values. Dead
    * clobbers precede replacement producers. No instruction asm, patches,
    * compiler options or matching-gate changes. AI generated; not human
    * reviewed. Falsification: every native/linked word and conditional/
    * internal J target, preserved data and full EXE/every-overlay hashes.
    * Physical units/fixed point, complete helper/SFX/asset meanings, caller/
    * frame cadence and synchronized runtime verification remain unresolved.
    * Cadence per invocation; no frame frequency or browser parity claim. */
    struct {
        int sp20, sp24, sp28, pad2C, sp30, sp34, sp38, pad3C, sp40, sp44, sp48, pad4C, pad50, pad54;
    } originalFrame;
    Moby* createdMoby;
    Vector3D* temp_a2;
    int temp_a1;
    register int scaledWord16 __asm__("$16");
    int temp_v0_2;
    register int temp_v0_3 __asm__("2");
    register int randomBoundArgument5 __asm__("5");
    register int randomZeroArgument4 __asm__("4");
    register int var_s0 __asm__("$16");
    register int iteration __asm__("$17");
    register int iterationLimit __asm__("$21");
    int var_v0;
    int var_v0_2;
    unsigned short* halfwordCursor;
    register int signedCurrentItem __asm__("2");
    register unsigned char* temp_s0 __asm__("$16");
    register unsigned char* temp_s0_2 __asm__("$16");
    register unsigned char* temp_s0_3 __asm__("$16");
    unsigned char temp_v0;
    unsigned char temp_v1;
    unsigned int recordStateWord;
    register void* player48Pointer4 __asm__("4");
    register int selector2 __asm__("2");
    register void* matrixPointer __asm__("18");
    void* playerB0Pointer;
    register int player148Halfword3 __asm__("3");
    register unsigned char* table65920Pointer __asm__("22");
    register unsigned char* table658A0Pointer __asm__("23");
    register void* createdData __asm__("$16");
    register void* privateData __asm__("$20");
    void* var_a0_2;
    register int* globalFA40Pointer4 __asm__("4");
    register int flags2 __asm__("2");
    register int* globalFA40Pointer16 __asm__("16");
    moby->updateDistance = 0xFF;
    privateData = moby->mobyTag;
    if (Level15_7920C_D_8007159A != 0) {
        Level15_7920CDeleteMoby(moby);
        return;
    }
    temp_v1 = moby->state;
    switch (temp_v1) {
            /* switch 1; irregular */
        case 0:
            /* switch 1 */
            moby->distanceToGround = 0;
            Level15_7920C_Field(privateData, signed char*, 5) = 1;
            if (Level15_7920C_D_8006C598 == 0) {
                if (moby->substate == 2) {
                    Level15_7920C_D_8006C7B4 |= 4;
                    Level15_7920C_D_8006C62C &= 0xFB;
                    Level15_7920C_Field(privateData, signed char*, 5) = 2;
                    Level15_7920C_Field(privateData, signed char*, 2) = 4;
                    moby->substate = 0;
                }
                if (Level15_7920C_func_80037BBC(moby, 0) != 0) {
                    Level15_7920C_func_800512E4(moby, 0, 1);
                    moby->state = 1;
                }
            }
        default:
            /* switch 1 */
            goto commonCallbacks;
        case 1:
            /* switch 1 */
            if (Level15_7920C_D_8006E344 != 1) {
                if (Level15_7920C_Field(privateData, unsigned char*, 4) == 2) {
                    flags2 = 0x10000002;
                    globalFA40Pointer4 = &Level15_7920C_D_8006FA40;
                    MATCHING_KEEP2(flags2, globalFA40Pointer4);
                    Level15_7920C_Field(&Level15_7920C_D_80070328, int*, 0x20C) = flags2;
                    *globalFA40Pointer4 = 3;
                    moby->state = 2;
                    func_8004F178(
                        (Vector3D*)((unsigned char*)globalFA40Pointer4 + 8),
                        Level15_7920C_Field(Level15_7920C_Field(privateData, void**, 0x24),
                                            Vector3D**, 0xC));
                    Level15_7920C_D_8006FA50 += 0x200;
                    temp_a2 = Level15_7920C_Field(Level15_7920C_Field(privateData, void**, 0x24),
                                                  Vector3D**, 0xC);
                    Level15_7920CSubtractVector(&originalFrame.sp20,
                                                ((unsigned char*)temp_a2 + 0x10), temp_a2);
                    Level15_7920C_D_8006FA54 =
                        func_8004E880(originalFrame.sp20, originalFrame.sp24, 0);
                    Level15_7920C_Field(Level15_7920C_Field(privateData, void**, 0x24), short*, 2) =
                        1;
                    Level15_7920C_func_8003B7B4(Level15_7920C_Field(privateData, void**, 0x24) + 2,
                                                2, &Level15_7920C_D_8006D088);
                    Level15_7920C_func_8003B7B4(Level15_7920C_Field(privateData, void**, 0x24) + 2,
                                                2, &Level15_7920C_D_8006C7F8);
                    temp_s0 = &moby->state;
                    Level15_7920C_func_8003B7B4(temp_s0, 1, &Level15_7920C_D_8006D088);
                    Level15_7920C_func_8003B7B4(temp_s0, 1, &Level15_7920C_D_8006C7F8);
                }
                moby->substate = 0;
                Level15_7920C_func_8003B7B4(&moby->substate, 1, &Level15_7920C_D_8006D088);
                Level15_7920C_func_8003B7B4(&moby->substate, 1, &Level15_7920C_D_8006C7F8);
                Level15_7920C_func_8003B74C(&Level15_7920C_D_8006D088);
                moby->state = 3;
                return;
            }
            goto commonCallbacks;
        case 2:
            /* switch 1 */
            temp_v0 = moby->substate;
            switch (temp_v0) {
                    /* switch 2; irregular */
                case 0:
                    /* switch 2 */
                    func_8004F178(&moby->position, &Level15_7920C_D_8006FA48);
                    temp_s0_2 = &moby->state;
                    moby->unknownCollision = 0;
                    moby->state = 0;
                    Level15_7920C_func_8003B7B4(temp_s0_2, 1, &Level15_7920C_D_8006D088);
                    Level15_7920C_func_8003B7B4(temp_s0_2, 1, &Level15_7920C_D_8006C7F8);
                    moby->state = 2;
                    moby->substate = 1;
                    /* fallthrough */
                case 1:
                    /* switch 2 */
                    if (({
                            globalFA40Pointer16 = &Level15_7920C_D_8006FA40;
                            MATCHING_KEEP(globalFA40Pointer16);
                            *globalFA40Pointer16;
                        }) == 0) {
                        {
                            register int sample3 __asm__("3");
                            register int value2 __asm__("2");
                            register void* vector4 __asm__("4");
                            register void* vector5 __asm__("5");
                            register void* vector6 __asm__("6");
                            sample3 = *(short*)(&Level15_7920C_D_80065920 +
                                                (Level15_7920C_Field(privateData, int*, 0x3C) * 2));
                            MATCHING_KEEP_VOLATILE_CLOBBER(sample3, "4");
                            vector4 = (unsigned char*)globalFA40Pointer16 + 8;
                            MATCHING_KEEP2(sample3, vector4);
                            value2 = (sample3 * 13) >> 5;
                            originalFrame.sp20 = value2;
                            value2 = Level15_7920C_Field(privateData, int*, 0x3C);
                            MATCHING_KEEP_VOLATILE_CLOBBER(value2, "5");
                            vector5 = &originalFrame.sp20;
                            MATCHING_KEEP2(value2, vector5);
                            sample3 = *(short*)(&Level15_7920C_D_800658A0 + (value2 * 2));
                            MATCHING_KEEP_VOLATILE_CLOBBER(sample3, "6");
                            vector6 = privateData + 0x28;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(sample3, vector6, "memory");
                            originalFrame.sp28 = 0;
                            MATCHING_KEEP_VOLATILE_CLOBBER(sample3, "memory");
                            value2 = (sample3 * 13) >> 5;
                            originalFrame.sp24 = value2;
                            func_8004F194(vector4, vector5, vector6);
                        }
                        Level15_7920C_D_8006FA50 += 0x164;
                        {
                            register int field2 __asm__("2");
                            register int literal3 __asm__("3");
                            field2 = Level15_7920C_Field(privateData, int*, 0x3C);
                            MATCHING_KEEP_VOLATILE_CLOBBER(field2, "3");
                            literal3 = 3;
                            MATCHING_KEEP2(field2, literal3);
                            *globalFA40Pointer16 = literal3;
                            MATCHING_KEEP_VOLATILE_CLOBBER(field2, "memory");
                            field2 += 0x80;
                            Level15_7920C_D_8006FA54 = field2;
                        }
                    }
                    break;
            }
            moby->unknownCollision = 0;
            moby->distanceToGround = 0x200;
            ((void (*)(Moby*, int))unk_ovlheader_80074318)(moby, 0xAF);
            Level15_7920C_D_8006C6D0 = 0;
            Level15_7920C_func_800135A4(&Level15_7920C_D_800719A8, &Level15_7920C_D_80068F7C, 0);
            Level15_7920C_func_800135A4(&Level15_7920C_D_800719F0, &Level15_7920C_D_80068F90, 0);
            if (Level15_7920C_Field(&Level15_7920C_D_80070328, int*, 0x24C) == 0xA) {
                temp_a1 = Level15_7920C_Field(&Level15_7920C_D_80070328, int*, 0x48) - 0xAD;
                if (temp_a1 != moby->animationState.nextId) {
                    Level15_7920CSetMobyAnimation(moby, temp_a1);
                }
            }
            Level15_7920CRefreshMobySpatialGridAndBasis(moby, 4);
            if (Level15_7920C_Field(privateData, int*, 0x44) == -1) {
                temp_v0_2 = Level15_7920C_func_800369D8(2);
                Level15_7920C_D_8006C6C4 = temp_v0_2;
                Level15_7920C_Field(privateData, int*, 0x44) = (int)Level15_7920C_func_8002803C(
                    0x17, 0x9A, &Level15_7920C_func_80027EE4, &Level15_7920C_func_80027A60,
                    &Level15_7920C_func_80029AA0, &Level15_7920C_D_8006C628, temp_v0_2);
            }
            Level15_7920C_D_8006C628 = 0;
            halfwordCursor = Level15_7920C_Field(Level15_7920C_D_8006C730, unsigned short**, 8);
            do {
                recordStateWord =
                    Level15_7920C_Field((({
                                            register int offset3 __asm__("3");
                                            unsigned char* pool;
                                            pool = (unsigned char*)Level15_7920C_D_8006C550;
                                            offset3 = (*halfwordCursor & 0x7FFF) * 0x58;
                                            MATCHING_KEEP(offset3);
                                            pool + offset3;
                                        })),
                                        unsigned char*, 0x48);
                MATCHING_KEEP(recordStateWord);
                if (((unsigned int)(recordStateWord & 0xFF) >= 0x80U) ||
                    ((unsigned int)(recordStateWord - 0x14) < 2U)) {
                    Level15_7920C_D_8006C628 += 1;
                }
                signedCurrentItem = *(short*)halfwordCursor;
                halfwordCursor = (unsigned short*)((unsigned char*)halfwordCursor + 2);
            } while (signedCurrentItem >= 0);
            if (Level15_7920C_D_8006C628 == Level15_7920C_D_8006C6C4) {
                var_a0_2 = privateData + 0x48;
                if (Level15_7920C_Field(privateData, int*, 0x48) == 0) {
                    Level15_7920C_Field(privateData, int*, 0x48) = 0x3C;
                    goto afterCounterReset;
                }
            } else {
            afterCounterReset:
                var_a0_2 = privateData + 0x48;
            }
            if (func_800359A4(var_a0_2, 4) == 2) {
                Level15_7920C_D_8006C7B4 |= 4;
                func_8004F178((Vector3D*)&originalFrame.sp20, privateData + 0x28);
                originalFrame.sp28 += 0x164;
                {
                    register int sample2 __asm__("2");
                    register int coefficient4 __asm__("4");
                    register int old2 __asm__("2");
                    register int shifted3 __asm__("3");
                    register void* destination4 __asm__("4");
                    register void* source5 __asm__("5");
                    sample2 = *(short*)(&Level15_7920C_D_80065920 +
                                        (Level15_7920C_Field(privateData, int*, 0x3C) * 2));
                    MATCHING_KEEP_VOLATILE_CLOBBER(sample2, "4");
                    coefficient4 = 0x9C0;
                    MATCHING_KEEP(coefficient4);
                    shifted3 = (sample2 * coefficient4) >> 12;
                    old2 = originalFrame.sp20;
                    MATCHING_KEEP2(shifted3, old2);
                    old2 += shifted3;
                    originalFrame.sp20 = old2;
                    sample2 = *(short*)(&Level15_7920C_D_800658A0 +
                                        (Level15_7920C_Field(privateData, int*, 0x3C) * 2));
                    shifted3 = (sample2 * coefficient4) >> 12;
                    source5 = &originalFrame.sp20;
                    destination4 = &Level15_7920C_D_8006FA48;
                    old2 = originalFrame.sp24;
                    MATCHING_KEEP4(shifted3, old2, source5, destination4);
                    old2 += shifted3;
                    originalFrame.sp24 = old2;
                    func_8004F178(destination4, source5);
                }
                temp_s0_3 = &moby->substate;
                {
                    register void* state4 __asm__("4");
                    register int literal5 __asm__("5");
                    register unsigned char* descriptor17 __asm__("17");
                    register void* descriptor6 __asm__("6");
                    register int field2 __asm__("2");
                    register int literal3 __asm__("3");
                    state4 = temp_s0_3;
                    literal5 = 1;
                    descriptor17 = &Level15_7920C_D_8006D088;
                    descriptor6 = descriptor17;
                    MATCHING_KEEP3(state4, literal5, descriptor6);
                    field2 = Level15_7920C_Field(privateData, int*, 0x3C);
                    MATCHING_KEEP_VOLATILE_CLOBBER(field2, "3");
                    literal3 = 3;
                    MATCHING_KEEP2(field2, literal3);
                    Level15_7920C_D_8006FA40 = literal3;
                    MATCHING_KEEP_VOLATILE_CLOBBER(field2, "memory");
                    field2 += 0x80;
                    field2 &= 0xFF;
                    Level15_7920C_D_8006FA54 = field2;
                    moby->substate = 2;
                    Level15_7920C_func_8003B7B4(state4, literal5, descriptor6);
                }
                Level15_7920C_func_8003B7B4(temp_s0_3, 1, &Level15_7920C_D_8006C7F8);
                Level15_7920C_func_8003B74C(&Level15_7920C_D_8006D088);
                return;
            }
            selector2 = 0xAF;
            MATCHING_KEEP(selector2);
            player48Pointer4 = &Level15_7920C_D_80070328 + 0x48;
            MATCHING_KEEP(player48Pointer4);
            if (Level15_7920C_Field(player48Pointer4, int*, 0) == selector2) {
                if (Level15_7920C_D_8006E538 & 0xC0) {
                    Level15_7920C_Field(&Level15_7920C_D_80070328, short*, 0x148) = 5;
                }
                if ((Level15_7920C_Field(&Level15_7920C_D_80070328, short*, 0x148) != 0) ||
                    (Level15_7920C_D_8006C640 & 1)) {
                    iterationLimit = 1;
                    if (Level15_7920C_Field(&Level15_7920C_D_80070328, short*, 0x148) != 0) {
                        iterationLimit = 3;
                    }
                    iteration = 0;
                    if (iterationLimit != 0) {
                        matrixPointer = &originalFrame.sp40;
                        playerB0Pointer = (unsigned char*)player48Pointer4 + 0x68;
                        table65920Pointer = &Level15_7920C_D_80065920;
                        table658A0Pointer = &Level15_7920C_D_800658A0;
                        MATCHING_KEEP4(matrixPointer, playerB0Pointer, table65920Pointer,
                                       table658A0Pointer);
                        do {
                            Level15_7920CInterpolateMobyVertex(moby, 2, &originalFrame.sp20);
                            originalFrame.sp40 = 0;
                            if (Level15_7920C_Field(&Level15_7920C_D_80070328, short*, 0x148) !=
                                0) {
                                var_v0 = func_800363DC(0, 0x3C);
                                randomZeroArgument4 = 0;
                                MATCHING_KEEP(randomZeroArgument4);
                                randomBoundArgument5 = 0x3C;
                            } else {
                                var_v0 = func_800363DC(0, 0x1E);
                                randomZeroArgument4 = 0;
                                MATCHING_KEEP(randomZeroArgument4);
                                randomBoundArgument5 = 0x1E;
                            }
                            originalFrame.sp44 = var_v0;
                            originalFrame.sp48 =
                                func_800363DC(randomZeroArgument4, randomBoundArgument5);
                            __asm__ volatile("" : : "m"(originalFrame.sp48) : "memory");
                            Level15_7920CTransformVectorByBasis(&moby->rotationMatrix,
                                                                matrixPointer, matrixPointer);
                            func_8004F194((Vector3D*)&originalFrame.sp20, (Vector3D*)matrixPointer,
                                          (Vector3D*)&originalFrame.sp20);
                            temp_v0_3 = Level15_7920C_Field(playerB0Pointer, int*, 0);
                            var_s0 = temp_v0_3 >> 6;
                            if (temp_v0_3 < 0) {
                                temp_v0_3 += 0x3F;
                                var_s0 = temp_v0_3 >> 6;
                            }
                            scaledWord16 = (int)(var_s0 * (func_800363DC(0, 0x8C) + 0x100)) >> 8;
                            originalFrame.sp30 =
                                (int)(((int)(*(short*)((moby->angle.yaw * 2) + table65920Pointer) *
                                             scaledWord16) >>
                                       0xC) *
                                      *(short*)((moby->angle.pitch * 2) + table65920Pointer)) >>
                                0xC;
                            originalFrame.sp34 =
                                (int)(((int)(*(short*)((moby->angle.yaw * 2) + table658A0Pointer) *
                                             scaledWord16) >>
                                       0xC) *
                                      *(short*)((moby->angle.pitch * 2) + table65920Pointer)) >>
                                0xC;
                            originalFrame.sp38 = ({
                                int zValue;
                                zValue = (*(short*)((moby->angle.pitch * 2) + table658A0Pointer) *
                                          scaledWord16) >>
                                         12;
                                player148Halfword3 =
                                    Level15_7920C_Field(playerB0Pointer, short*, 0x98);
                                zValue;
                            });
                            if (player148Halfword3 != 0) {
                                SpawnParticle(1, 0xD, (Vector3D*)&originalFrame.sp20,
                                              (Vector3D*)&originalFrame.sp30);
                                iteration += 1;
                            } else {
                                MATCHING_KEEP(player148Halfword3);
                                Level15_7920C_Field(SpawnParticle(1, 0,
                                                                  (Vector3D*)&originalFrame.sp20,
                                                                  (Vector3D*)&originalFrame.sp30),
                                                    signed char*, 2) = 0xC;
                                MATCHING_BARRIER_VOLATILE("memory");
                                iteration += 1;
                            }
                        } while (iteration < iterationLimit);
                    }
                }
                MATCHING_BARRIER_VOLATILE("4");
                if ((func_800359A4(privateData + 0x40, 2) != 0) &&
                    (Level15_7920C_D_8006E538 & 0x20)) {
                    createdMoby = SpawnMoby(0xED, moby);
                    if (createdMoby != 0) {
                        createdData = createdMoby->mobyTag;
                        Level15_7920C_Field(createdData, int*, 0xC) = 0x78;
                        Level15_7920C_Field(createdData, int*, 0) = 0x2EE;
                        Level15_7920CTransformVectorByBasis(&moby->rotationMatrix,
                                                            (int*)createdData, (int*)createdData);
                        createdMoby->lowDrawDistance = 0x3F;
                        createdMoby->highDrawDistance = 0x3F;
                        createdMoby->angle.yaw =
                            func_8004E880(Level15_7920C_Field(createdData, int*, 0),
                                          Level15_7920C_Field(createdData, int*, 4), 0);
                        createdMoby->angle.pitch =
                            func_8004E880(Level15_7920CMeasureVectorLength(createdData, 0),
                                          Level15_7920C_Field(createdData, int*, 8), 0);
                        Level15_7920CInterpolateMobyVertex(
                            moby, Level15_7920C_Field(privateData, short*, 0x42) + 3,
                            &createdMoby->position.x);
                        Level15_7920C_Field(privateData, short*, 0x42) =
                            (short)(Level15_7920C_Field(privateData, short*, 0x42) == 0);
                    }
                    Level15_7920C_Field(privateData, short*, 0x40) = 6;
                }
                if (Level15_7920C_Field(&Level15_7920C_D_80070328, short*, 0x148) == 0) {
                    if (func_8003BFC0(moby, Level15_7920C_Field(privateData, int*, 0x4C)) != 0) {
                        func_8003BE70(Level15_7920C_Field(privateData, int*, 0x4C));
                    }
                    Level15_7920C_Field(privateData, int*, 0x4C) = -1;
                    if (func_8003BFC0(moby, Level15_7920C_Field(privateData, int*, 0x70)) == 0) {
                        Level15_7920C_Field(privateData, int*, 0x70) = func_8003BABC(moby, 1, 4);
                    }
                } else {
                    if (func_8003BFC0(moby, Level15_7920C_Field(privateData, int*, 0x70)) != 0) {
                        func_8003BE70(Level15_7920C_Field(privateData, int*, 0x70));
                    }
                    Level15_7920C_Field(privateData, int*, 0x70) = -1;
                    if (func_8003BFC0(moby, Level15_7920C_Field(privateData, int*, 0x4C)) == 0) {
                        Level15_7920C_Field(privateData, int*, 0x4C) = func_8003BABC(moby, 0, 4);
                    }
                }
            } else if (Level15_7920C_Field(player48Pointer4, int*, 0) == 0xB0) {
                if (func_8003BFC0(moby, Level15_7920C_Field(privateData, int*, 0x4C)) != 0) {
                    func_8003BE70(Level15_7920C_Field(privateData, int*, 0x4C));
                }
                Level15_7920C_Field(privateData, int*, 0x4C) = -1;
                if (func_8003BFC0(moby, Level15_7920C_Field(privateData, int*, 0x70)) != 0) {
                    func_8003BE70(Level15_7920C_Field(privateData, int*, 0x70));
                }
                Level15_7920C_Field(privateData, int*, 0x70) = -1;
                var_v0_2 = func_8003613C((int)moby->angle.pitch, 0x80);
                if (var_v0_2 < 0) {
                    var_v0_2 = -var_v0_2;
                }
                if (var_v0_2 >= 0xB) {
                    moby->angle.pitch -= 5;
                }
                if (Level15_7920C_Field(privateData, int*, 0x68) == 0) {
                    func_8003BABC(moby, 2, 0);
                    func_8003BABC(moby, 3, 0);
                    Level15_7920C_Field(privateData, int*, 0x68) = 1;
                    SpawnFragments(4, 0x17A, moby,
                                   Level15_7920C_Field(privateData, Vector3D**, 0x6C), 0, 0x100);
                }
            }
            goto commonCallbacks;
        case 3:
            /* switch 1 */
            Level15_7920C_Field(&Level15_7920C_D_80070328, int*, 0x20C) = 0x10000002;
            goto commonCallbacks;
    }
    return;
commonCallbacks:
    func_80035D38(moby);
    Level15_7920C_func_8005629C(moby);
    return;
}
#undef Level15_7920C_Field

typedef struct {
    SpeechProps speech;
    unsigned char reserved14[0xC];
    int word20;
} DecodedDialogueStateTag;
extern int D_8006C640, D_8006E53C, D_8006E344;
extern unsigned char D_8007159A;
void func_80055B18(Moby*);
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
void func_level_15_80079DD0(Moby* moby) {
    int flags = D_8006C640;
    DecodedDialogueStateTag* tag = moby->mobyTag;
    if (!flags && moby->mobyClass == 0x220 && !D_8007159A) {
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
        case 0:
            if (tag->speech.nextMsg == 2)
                tag->speech.autoTalk = 0;
            if (!tag->speech.autoTalk) {
                if (D_8006E53C & 0x10) {
                    if (func_80037BBC(moby, 0))
                        goto start;
                    tag->speech.talkable = 0;
                    /* Preserve the original store-before-load ordering. */
                    MATCHING_BARRIER_VOLATILE("memory");
                }
                if (!tag->speech.autoTalk)
                    return;
            }
            if (func_80037BBC(moby, 0)) {
            start:
                func_800512E4(moby, 0, 0);
                moby->state = 1;
            } else
                tag->speech.talkable = 0;
            break;
        case 1:
            if (D_8006E344 != 1) {
                tag->word20 = 1;
                moby->state = 0;
            }
            break;
    }
}

/* AI-generated reconstruction; not human reviewed. Original Rev0 span
 * 80079F10..8007A1FC,187 words. Private offsets0/2/4/8/C..14 follow original
 * signed/unsigned halfword and pointer accesses. State10 synchronizes three
 * child slots; state20 retains pre-update signed speed, increments speed by
 * 12*raw tick below800 and wraps phase to16 bits before per-axis rotation.
 * Each route transforms its own vector; GCC merges only the original common
 * call tail. Empty constraints preserve native read/argument lifetimes and
 * emit no instructions. Units, private-record producer, helpers/effect and
 * particle meanings, callback timing and caller cadence remain unresolved. */
typedef struct {
    short speed;
    unsigned short phase;
    void* effect;
    unsigned char* particle;
    Moby* children[3];
} DecodedSpeedwayCarryTag;
extern int D_8006C648;
void SpeedwayCarryStop(void*) __asm__("func_800509E8");
void* SpeedwayCarryEffect(Vector3D*, int, int, int) __asm__("func_80050844");
void SpeedwayCarryTransform(void*, void*, void*) __asm__("func_8004ED6C");
void SpeedwayCarryAdd(void*, void*, void*) __asm__("func_8004F194");
void func_level_15_80079F10(Moby* argument) {
    register Moby* moby __asm__("$18") = argument;
    register DecodedSpeedwayCarryTag* tag __asm__("$16") = moby->mobyTag;
    register int index __asm__("$17");
    Vector3D velocity;
    int reserved[2];
    switch (moby->state) {
        case 10:
            if (moby->substate == 4) {
                register DecodedSpeedwayCarryTag* cursor __asm__("$3");
                index = 0;
                if (tag->particle) {
                    tag->particle[0x10] = 0;
                    tag->particle = 0;
                }
                {
                    register int clearState __asm__("$4") = 4;
                    MATCHING_OBSERVE(clearState);
                    cursor = tag;
                    for (; index < 3;
                         index++, cursor = (DecodedSpeedwayCarryTag*)((char*)cursor + 4)) {
                        MATCHING_KEEP(cursor);
                        if (cursor->children[0]) {
                            cursor->children[0]->substate = clearState;
                            cursor->children[0] = 0;
                        }
                    }
                }
                goto remove;
            } else {
                if (moby->size > 60) {
                    moby->size -= 12;
                    if (moby->size < 60)
                        moby->size = 60;
                }
                if (tag->particle[0x11] < 244)
                    tag->particle[0x11] += 12;
                {
                    register Vector3D* particleArgument __asm__("$4") = (Vector3D*)tag->particle;
                    register Vector3D* positionArgument __asm__("$5");
                    MATCHING_OBSERVE(particleArgument);
                    positionArgument = &moby->position;
                    MATCHING_OBSERVE(positionArgument);
                    index = 0;
                    func_8004F178(particleArgument, positionArgument);
                }
                for (; index < 3; index++, tag = (DecodedSpeedwayCarryTag*)((char*)tag + 4)) {
                    if (tag->children[0]) {
                        func_8004F178(&tag->children[0]->position, &moby->position);
                        tag->children[0]->angle.roll = moby->angle.roll;
                        MATCHING_BARRIER("memory");
                        tag->children[0]->angle.pitch = moby->angle.pitch;
                        MATCHING_BARRIER("memory");
                        tag->children[0]->angle.yaw = moby->angle.yaw;
                    }
                }
            }
            break;
        case 20:
            if (moby->substate == 4) {
                if (tag->effect)
                    SpeedwayCarryStop(tag->effect);
            remove:
                func_80055B18(moby);
                break;
            }
            index = tag->speed;
            {
                if (index < 800) {
                    register int speedBase __asm__("$4") = index;
                    MATCHING_OBSERVE(speedBase);
                    {
                        register int tick __asm__("$3") = D_8006C648;
                        register int newSpeed __asm__("$2") = speedBase + tick * 12;
                        MATCHING_OBSERVE(newSpeed);
                        tag->speed = newSpeed;
                    }
                }
            }
            MATCHING_BARRIER("memory");
            tag->phase += D_8006C648;
            if (moby->substate == 3) {
                moby->angle.yaw += (short)tag->phase * 8;
                func_80055D24(moby, 4);
                velocity.x = index;
                velocity.y = 0;
                velocity.z = 0;
                SpeedwayCarryTransform(&moby->rotationMatrix, &velocity, &velocity);
            } else if (moby->substate == 2) {
                moby->angle.pitch += (short)tag->phase * 8;
                func_80055D24(moby, 4);
                velocity.x = index;
                velocity.y = 0;
                velocity.z = 0;
                SpeedwayCarryTransform(&moby->rotationMatrix, &velocity, &velocity);
            } else {
                moby->angle.roll += (short)tag->phase * 8;
                func_80055D24(moby, 4);
                velocity.x = 0;
                velocity.y = index;
                velocity.z = 0;
                SpeedwayCarryTransform(&moby->rotationMatrix, &velocity, &velocity);
            }

            MATCHING_KEEP(moby);
            SpeedwayCarryAdd(&moby->position, &moby->position, &velocity);
            MATCHING_KEEP(moby);
            if (!tag->effect)
                tag->effect = SpeedwayCarryEffect(&moby->position, 8, 10, 0x40C0C0);
            break;
    }
}

#define Controller7A1FCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller7A1FCCameraBytes[] __asm__("D_8006FA40");
extern unsigned char Controller7A1FCPlayer[] __asm__("D_80070328");
extern unsigned char Controller7A1FCContext[] __asm__("D_8006D088");
extern unsigned char Controller7A1FCSin[] __asm__("D_800658A0"), Controller7A1FCCos[] __asm__(
                                                                     "D_80065920");
extern int Controller7A1FCD_8006586C __asm__("D_8006586C");
extern int Controller7A1FCD_8006E344 __asm__("D_8006E344");
extern int Controller7A1FCD_8006FA3C __asm__("D_8006FA3C");
extern int Controller7A1FCD_8006FA40 __asm__("D_8006FA40");
extern int Controller7A1FCD_8006FA54 __asm__("D_8006FA54");
extern unsigned char Controller7A1FCD_8006C62C __asm__("D_8006C62C");
extern unsigned char Controller7A1FCD_8006C7B4 __asm__("D_8006C7B4");
void* Controller7A1FCHelper2EC50(int, int, int) __asm__("func_8002EC50");
int Controller7A1FCTurnMobyTowardPlayer(void*, int, int, int) __asm__("func_8003573C");
int Controller7A1FCTurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Controller7A1FCHelper35DDC(void*, int, int, int, int) __asm__("func_80035DDC");
int Controller7A1FCHelper3B74C(void*) __asm__("func_8003B74C");
int Controller7A1FCPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller7A1FCCopyVector(void*, int) __asm__("func_8004F178");
int Controller7A1FCAddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller7A1FCSubtractVector(void*, int, int) __asm__("func_8004F1C8");
int Controller7A1FCApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller7A1FCHelper512E4(void*, int, int) __asm__("func_800512E4");
int Controller7A1FCHelper53F50(int, int) __asm__("func_80053F50");
int Controller7A1FCDeleteMoby(void*) __asm__("func_80055B18");
int Controller7A1FCRefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller7A1FCInterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern int (*Controller7A1FCParticle)(int, int, void*, int) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level15/8007A1FC, level25/80078580, level35/80078C58 and
 * level45/80078CDC, original moby text. All four copies have 308 original
 * instructions, equal original helper/global symbols and no owned table rows.
 * Three stack vectors retain offsets 0x18/0x28/0x38. Preserve resource creation,
 * paired particle callback sequences and signed z averages, flag-bit checks,
 * signed table products (39 >> 6 and 13 >> 5), nested state paths, six-argument
 * helper stack slots, tag/record pointer rereads and camera-mode producers.
 * Helper semantics, vector coordinate domains, fixed-point meanings and caller
 * cadence remain unresolved; updates below are once per invocation.
 * Confidence: exact native/linked original words and complete retail SHA set.
 * Falsifiable vectors: every original instruction and EXE/all-overlay hashes.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_15_8007A1FC(void* input) {
    register unsigned char* owner __asm__("$16") = input;
    struct {
        Vector3D first;
        int padding24;
        Vector3D second;
        int padding34;
        Vector3D third;
        int padding44;
    } frame;
    void* resource;
    int wideTableOffset;
    int narrowTableOffset;
    int firstRecordAddress;
    int secondRecordAddress;
    int deltaX;
    int deltaY;
    int var_v0;
    int var_v0_2;
    int offsetY;
    register int selectedMode __asm__("$5");
    register int state __asm__("$3");
    register int substate __asm__("$3");
    register unsigned char* tag __asm__("$17");

    tag = Controller7A1FCField(owner, void**, 0);
    {
        register void* resource __asm__("$2") = Controller7A1FCField(tag, void**, 0x38);
        MATCHING_KEEP_CLOBBER(resource, "$4");
        if (resource == 0) {
            Controller7A1FCField(tag, void**, 0x38) = Controller7A1FCHelper2EC50(1, 0x80, 0x489090);
            Controller7A1FCField(owner, int*, 0x54) = (int)Controller7A1FCD_8006586C;
        } else {
            Controller7A1FCInterpolateMobyVertex(owner, 1, &frame.first);
            frame.first.z = (int)(frame.first.z + Controller7A1FCField(owner, int*, 0x14)) >> 1;
            Controller7A1FCParticle(2, 0x42, &frame.first, 0);
            Controller7A1FCInterpolateMobyVertex(owner, 2, &frame.first);
            frame.first.z = (int)(frame.first.z + Controller7A1FCField(owner, int*, 0x14)) >> 1;
            Controller7A1FCParticle(2, 0x42, &frame.first, 0);
            Controller7A1FCField(Controller7A1FCField(tag, void**, 0x38), signed char*, 0x10) = 1;
            Controller7A1FCInterpolateMobyVertex(owner, 0, Controller7A1FCField(tag, void**, 0x38));
        }
    }
    state = Controller7A1FCField(owner, unsigned char*, 0x48);
    MATCHING_KEEP(state);
    switch (state) {
        case 0:
            if (Controller7A1FCD_8006FA3C == 0) {
                {
                    register int mask __asm__("$4") = 0x10000000;
                    register int* flags __asm__("$3");
                    register int previous __asm__("$2");
                    MATCHING_KEEP(mask);
                    flags = (int*)(Controller7A1FCPlayer + 0x20C);
                    previous = *flags;
                    mask |= 2;
                    *flags = previous | mask;
                }
                substate = Controller7A1FCField(owner, unsigned char*, 0x49);
                MATCHING_KEEP(substate);
                switch (substate) {
                    case 0: {
                        register int flags __asm__("$3") = Controller7A1FCD_8006C7B4;
                        register int predicate __asm__("$2");
                        MATCHING_KEEP(flags);
                        if (flags & 1) {
                            if (!(Controller7A1FCD_8006C62C & 1))
                                goto wideOffset;
                        }
                        predicate = flags & 2;
                        if (predicate) {
                            if (!(Controller7A1FCD_8006C62C & 2))
                                goto wideOffset;
                        }
                        predicate = flags & 4;
                        if (predicate && !(Controller7A1FCD_8006C62C & 4)) {
                        wideOffset:
                            wideTableOffset =
                                Controller7A1FCField(&Controller7A1FCPlayer, unsigned char*, 0xE) *
                                2;
                            frame.second.x =
                                (int)(*(short*)(Controller7A1FCCos + wideTableOffset) * 0x27) >> 6;
                            {
                                register int sample __asm__("$3") =
                                    *(short*)(Controller7A1FCSin + wideTableOffset);
                                MATCHING_KEEP_CLOBBER(sample, "memory");
                                frame.second.z = 0;
                                MATCHING_BARRIER_VOLATILE("memory");
                                offsetY = (sample * 0x27) >> 6;
                            }
                        } else {
                            narrowTableOffset =
                                Controller7A1FCField(&Controller7A1FCPlayer, unsigned char*, 0xE) *
                                2;
                            frame.second.x =
                                (int)(*(short*)(Controller7A1FCCos + narrowTableOffset) * 0xD) >> 5;
                            {
                                register int sample __asm__("$3") =
                                    *(short*)(Controller7A1FCSin + narrowTableOffset);
                                MATCHING_KEEP_CLOBBER(sample, "memory");
                                frame.second.z = 0;
                                MATCHING_BARRIER_VOLATILE("memory");
                                offsetY = (sample * 0xD) >> 5;
                            }
                        }
                    }
                        frame.second.y = offsetY;
                        MATCHING_BARRIER_VOLATILE("memory");
                        Controller7A1FCAddVector(&frame.second, &Controller7A1FCPlayer,
                                                 &frame.second);
                        if (Controller7A1FCTurnMobyTowardHeading(
                                owner,
                                Controller7A1FCPlanarHeadingLookup(
                                    frame.second.x - Controller7A1FCField(owner, int*, 0xC),
                                    frame.second.y - Controller7A1FCField(owner, int*, 0x10), 0),
                                8, 0x10, 1, 0) != 0) {
                            Controller7A1FCHelper35DDC(owner, 0xC0, 0, 0, 0);
                            if (Controller7A1FCApproximatePlanarDistance(&frame.second,
                                                                         owner + 0xC) < 0x100) {
                                Controller7A1FCField(owner, unsigned char*, 0x49) = 1U;
                            }
                        }
                        break;
                    case 1:
                        MATCHING_BARRIER_VOLATILE("$3");
                        if (Controller7A1FCTurnMobyTowardPlayer(owner, 8, 4, 1) != 0) {
                            Controller7A1FCField(tag, signed char*, 5) = 1;
                            Controller7A1FCField(owner, unsigned char*, 0x49) = 2U;
                        }
                        break;
                    case 2:
                        Controller7A1FCHelper512E4(owner, 0, 0);
                        Controller7A1FCField(owner, unsigned char*, 0x48) = 1U;
                        break;
                }
                goto updateOwner;
            }
            resource = Controller7A1FCField(tag, void**, 0x38);
            if (resource != 0) {
                Controller7A1FCField(resource, signed char*, 0x10) = 0;
            }
            Controller7A1FCDeleteMoby(owner);
            goto finished;
        updateOwner:
            Controller7A1FCRefreshMobySpatialGridAndBasis(owner, 4);
            goto finished;
        case 1:
            if (Controller7A1FCD_8006E344 != state) {
                selectedMode = Controller7A1FCField(tag, unsigned char*, 4);
                if (selectedMode == state) {
                    {
                        register unsigned char* camera __asm__("$4") = Controller7A1FCCameraBytes;
                        MATCHING_KEEP(camera);
                        *(int*)camera = selectedMode;
                        Controller7A1FCCopyVector(
                            camera + 8, Controller7A1FCField(
                                            Controller7A1FCField(tag, void**, 0x3C), int*, 0xC));
                    }
                    firstRecordAddress =
                        Controller7A1FCField(Controller7A1FCField(tag, void**, 0x3C), int*, 0xC);
                    Controller7A1FCSubtractVector(&frame.second, firstRecordAddress + 0x10,
                                                  firstRecordAddress);
                    deltaX = frame.second.x;
                    deltaY = frame.second.y;
                    goto applyCameraResult;
                }
                if (selectedMode == 2) {
                    {
                        register unsigned char* camera __asm__("$4") = Controller7A1FCCameraBytes;
                        MATCHING_KEEP(camera);
                        *(int*)camera = selectedMode;
                        Controller7A1FCCopyVector(
                            camera + 8, Controller7A1FCField(
                                            Controller7A1FCField(tag, void**, 0x40), int*, 0xC));
                    }
                    secondRecordAddress =
                        Controller7A1FCField(Controller7A1FCField(tag, void**, 0x40), int*, 0xC);
                    Controller7A1FCSubtractVector(&frame.third, secondRecordAddress + 0x10,
                                                  secondRecordAddress);
                    deltaX = frame.third.x;
                    deltaY = frame.third.y;
                applyCameraResult:
                    {
                        register int angle __asm__("$2") =
                            Controller7A1FCPlanarHeadingLookup(deltaX, deltaY, 0);
                        register void* context __asm__("$4") = Controller7A1FCContext;
                        MATCHING_KEEP_CLOBBER(context, "memory");
                        Controller7A1FCD_8006FA54 = angle;
                        Controller7A1FCHelper3B74C(context);
                    }
                    return;
                }
                if (selectedMode == 3) {
                    MATCHING_KEEP(selectedMode);
                    Controller7A1FCHelper53F50(-1, selectedMode);
                    return;
                }
                Controller7A1FCField(tag, signed char*, 5) = 1;
                Controller7A1FCField(owner, unsigned char*, 0x48) = 0U;
            } else {
                return;
            }
            break;
    }
finished:;
}

#undef Controller7A1FCField

/* AI-generated reconstruction; not human reviewed. Rev0 original181 words
 * at8007A6CC..8007A9A0. Reuses Rev1 raw329 source-local state/child routes;
 * Rev0 first sample byte offset uses phase<<3 (Rev1 uses phase<<2).
 * Tag words0/4/8 and byte/halfword access widths follow original instructions.
 * Physical coordinate units, table producers, helper effects, SFX meaning and
 * caller cadence remain unresolved. Empty constraints preserve fresh reads
 * and forget the incoming A0 lifetime without emitting instructions. */
typedef struct {
    int handle;
    Moby* child;
    unsigned int phase;
} DecodedRaw329Tag;
extern int D_8006FA3C, D_8006C648;
extern unsigned char Raw329StateTable[] __asm__("D_80066964");
extern unsigned char Raw329AnimationTable[] __asm__("D_80066988");
extern unsigned char Raw329ColourTable[] __asm__("D_80066990");
extern unsigned short Raw329Samples[] __asm__("D_80065920");
extern unsigned char Raw329Player[] __asm__("D_80070328");
extern int (*Raw329Check)(Moby*, void*, int, int) __asm__("unk_ovlheader_8007439C");
extern void (*Raw329Finish)(Moby*) __asm__("unk_ovlheader_80074384");
int Raw329HandleCheck(Moby*, int) __asm__("func_8003BFC0");
int Raw329HandleStart(Moby*, int, int) __asm__("func_8003BABC");
void Raw329HandleStop(int) __asm__("func_8003BE70");
void func_level_15_8007A6CC(Moby* argument) {
    register Moby* moby __asm__("$18") = argument;
    register DecodedRaw329Tag* tag __asm__("$17") = moby->mobyTag;
    int reservedStack[2];
    register unsigned char* childTag __asm__("$16");
    MATCHING_BARRIER("$4");
    switch (moby->state) {
        case 0:
            if ((unsigned int)(D_8006FA3C - 2) < 2)
                goto remove;
            if (moby->gemValue != 255) {
                tag->child = SpawnMoby(1, moby);
                if (tag->child) {
                    childTag = tag->child->mobyTag;
                    func_8004F178(&tag->child->position, &moby->position);
                    tag->child->state = 5;
                    tag->child->substate = Raw329StateTable[moby->gemValue];
                    MATCHING_BARRIER("memory");
                    tag->child->animationState.id = Raw329AnimationTable[tag->child->substate];
                    MATCHING_BARRIER("memory");
                    tag->child->colour.r = Raw329ColourTable[tag->child->substate];
                    MATCHING_BARRIER("memory");
                    tag->child->lowDrawDistance = moby->lowDrawDistance;
                    MATCHING_BARRIER("memory");
                    tag->child->highDrawDistance = moby->highDrawDistance;
                    childTag[0x13] = 255;
                    tag->phase = rand() & 255;
                }
            }
            moby->state = 1;
            break;
        case 1:
            if (!Raw329HandleCheck(moby, tag->handle))
                tag->handle = Raw329HandleStart(moby, 1, 4);
            moby->angle.roll += 8;
            if (tag->child) {
                tag->phase += D_8006C648;
                tag->child->angle.pitch = *(unsigned short*)((unsigned char*)Raw329Samples +
                                                             ((tag->phase << 3) & 0x1F8)) >>
                                          8;
                MATCHING_BARRIER("memory");
                tag->child->angle.yaw += 4;
                MATCHING_BARRIER("memory");
                tag->child->position.z =
                    moby->position.z +
                    ((int)(short)*(unsigned short*)((unsigned char*)Raw329Samples +
                                                    ((tag->phase << 2) & 0x1FC)) >>
                     4);
            }
            if (Raw329Check(moby, Raw329Player, 0xC00, 0))
                moby->state = 2;
            break;
        case 2:
            Raw329Finish(moby);
            if (tag->child)
                tag->child->state = 4;
            if (Raw329HandleCheck(moby, tag->handle))
                Raw329HandleStop(tag->handle);
            tag->handle = -1;
            Raw329HandleStart(moby, 0, 0);
        remove:
            func_80055B18(moby);
            break;
    }
}

/* Original private record: word timer/mode and signed halfword range bounds. */
typedef struct {
    int timer, mode;
    short lower, upper;
} DecodedTimedPickupTag;
extern int D_8006FA3C, D_8006FA80;
extern unsigned short DecodedPickupYaw __asm__("D_8006E040");
extern unsigned short DecodedPickupPitch __asm__("D_8006E03E");
extern char DecodedPickupPlayer[] __asm__("D_80070328");
extern int DecodedPickupHeading __asm__("D_80070328 + 0x15C");
extern int (*DecodedPickupQuery)(Moby*, void*, int) __asm__("unk_ovlheader_800743A0");
int rand(void);
int func_800359A4(void*, int);
int func_8003BABC(Moby*, int, int);
void func_8004F178(Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
void func_80055B18(Moby*);
void func_level_15_8007A9A0(Moby* moby) {
    Vector3D velocity;
    register DecodedTimedPickupTag* tag __asm__("$19") = (DecodedTimedPickupTag*)moby->mobyTag;
    register Vector3D* playerVelocity __asm__("$18");
    register int sign __asm__("$2");
    int noise;
    register int heading __asm__("$3");
    register int boost __asm__("$2");
    register int biased __asm__("$3");
    register int index __asm__("$17");
    switch (moby->state) {
        case 0:
            if (D_8006FA3C == 2) {
                if (!tag->mode) {
                    func_80055B18(moby);
                    break;
                }
            } else if (D_8006FA3C == 3 || tag->mode) {
                func_80055B18(moby);
                break;
            }
            moby->state = 1;
            break;
        case 1:
            if (tag->lower && tag->upper) {
                if (tag->lower < D_8006FA80 && D_8006FA80 < tag->upper) {
                    moby->unknown3[0] = 0;
                    moby->lowDrawDistance = 0;
                    moby->drawn = 0;
                } else {
                    moby->unknown3[0] = 1;
                    moby->lowDrawDistance = 63;
                    moby->drawn = 1;
                }
            }
            moby->angle.yaw = ((int)(DecodedPickupYaw << 16) >> 20) - 128;
            moby->angle.pitch = DecodedPickupPitch >> 4;
            if (DecodedPickupQuery(moby, DecodedPickupPlayer, 1024))
                moby->state = 2;
            break;
        case 2:
            func_8003BABC(moby, 0, 0);
            index = 0;
            /* Empty constraints preserve retail loop setup and legacy compiler scheduling. */
            MATCHING_OBSERVE_VOLATILE_CLOBBER(index, "$18");
            playerVelocity = (Vector3D*)(DecodedPickupPlayer + 152);
            for (; index < 8; index++) {
                func_8004F178(&velocity, playerVelocity);
                func_8004F110(&velocity, 5);
                noise = rand();
                biased = velocity.x - 127;
                __asm__("" : "=r"(biased) : "0"(biased), "r"(noise & 254));
                velocity.x = biased + (noise & 254);
                noise = rand();
                biased = velocity.y - 127;
                __asm__("" : "=r"(biased) : "0"(biased), "r"(noise & 254));
                velocity.y = biased + (noise & 254);
                noise = rand();
                biased = velocity.z - 127;
                __asm__("" : "=r"(biased) : "0"(biased), "r"(noise & 254));
                velocity.z = biased + (noise & 254);
                SpawnParticle(1, 23, (Vector3D*)((char*)playerVelocity - 152), &velocity);
            }
            MATCHING_KEEP(playerVelocity);
            heading = DecodedPickupHeading;
            __asm__ volatile("" : : : "$2", "memory");
            boost = 75;
            *(short*)((char*)playerVelocity + 176) = boost;
            if (heading >= 0) {
                MATCHING_OBSERVE_VOLATILE(boost);
                sign = 1;
            } else {
                MATCHING_OBSERVE_VOLATILE(boost);
                sign = -1;
            }
            *(short*)((char*)playerVelocity + 178) = sign;
            moby->updateDistance = 255;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            tag->timer = 60;
            moby->state = 3;
            break;
        case 3:
            if (func_800359A4(tag, 4)) {
                moby->angle.yaw = ((int)(DecodedPickupYaw << 16) >> 20) - 128;
                moby->angle.pitch = DecodedPickupPitch >> 4;
                moby->lowDrawDistance = 63;
                moby->updateDistance = 16;
                moby->state = 1;
            }
            break;
    }
}

void func_level_15_8007AC80(Moby* moby) {
    func_80039714(moby);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Sources: level_15/moby/func_level_15_8007ACA0.s,
 * level_25/moby/func_level_25_8007A674.s,
 * level_35/moby/func_level_35_80079428.s,
 * level_45/moby/func_level_45_80079598.s.
 * All 204 instructions and six owned table/padding words per copy read.
 * Tag words at +0/+4; indexed Moby records have the original 88-byte stride.
 * Byte fields wrap as in retail. Helper argument four is stack+0x10;
 * its first output word is compared signed against 513.
 * Once per invocation. Helper semantics, output units, global producers and
 * caller cadence remain unresolved. Existing field names are not evidence.
 * Confidence: exact compiled words. Falsifiable vectors: every linked original
 * code/table word at the source addresses and every complete retail hash.
 * Empty constraints preserve register lifetimes without opcode patches.
 */
extern int D_8006C640;
extern int D_8006FA3C;
extern int D_8006FA44;
extern int D_8006FA74;
extern int D_8006FA78;

extern Moby* ControllerACA0Mobys __asm__("D_8006C550");
extern unsigned char ControllerACA0Player[] __asm__("D_80070328");
extern int (*ControllerACA0Test)(Moby*, void*, int, int*) __asm__("unk_ovlheader_8007439C");
void func_level_15_8007ACA0(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    Vector3D helperOutput;
    register Moby* linkedMoby __asm__("$17");
    register Moby* nextLinkedMoby __asm__("$17");
    register int one __asm__("$5");
    register Moby* prepared __asm__("$4");
    register unsigned char* player __asm__("$5");
    int completedCount;
    unsigned char state;
    unsigned char nextState;
    register int* tag __asm__("$18");

    state = moby->state;
    tag = moby->mobyTag;
    switch (state) {
        case 0:
            if (D_8006FA3C != 2) {
                func_80055B18(moby);
                moby->lowDrawDistance = 0;
            } else {
                if (tag[1] != 0) {
                    func_80034F80(moby, 0);
                    moby->updateDistance = 0xFF;
                    nextState = 2;
                } else {
                    func_80034F80(moby, 1);
                    moby->updateDistance = 0x10;
                    nextState = 1;
                }
                moby->state = nextState;
                goto clearDistance;
            }
            goto clearDrawnFlag;
        default:
            return;
        case 1:
            moby->angle.roll += 8;
            return;
        case 2: {
            register int skip __asm__("$2") = D_8006C640 < 11;
            MATCHING_KEEP2_CLOBBER(skip, moby, "$4");
            prepared = moby;
            if (skip)
                goto sharedTest;
        }
            if (D_8006FA74 <= 0) {
                MATCHING_BARRIER("$4");
                prepared = moby;
                func_8003BABC(prepared, 2, 33);
                func_80034F80(moby, 2);
                moby->state = 3;
                goto prepareSharedTest;
            }
            if (D_8006FA74 < 61) {
                register int compare __asm__("$2") = 1;
                register int current __asm__("$3");
                MATCHING_KEEP_CLOBBER(compare, "$3");
                current = moby->animationState.id;
                MATCHING_KEEP2_CLOBBER(current, moby, "$4");
                prepared = moby;
                if (current == compare)
                    goto prepareSharedTest;
                func_8003BABC(prepared, 1, 33);
                func_80034F80(moby, 1);
                prepared = moby;
                goto sharedTest;
            }
            {
                register int counter __asm__("$3") = D_8006FA74;
                register int skip __asm__("$2");
                MATCHING_KEEP_CLOBBER(counter, "$2");
                skip = counter < 121;
                MATCHING_KEEP2_CLOBBER(skip, moby, "$4");
                prepared = moby;
                if (!skip)
                    goto sharedTest;
            }
            if ((unsigned char)moby->lowDrawDistance >= 63)
                goto sharedTest;
            func_8003BABC(prepared, 1, 33);
            moby->lowDrawDistance = 63;
        case 3:
        prepareSharedTest:
            prepared = moby;
        sharedTest:
            {
                register int index __asm__("$3") = tag[0];
                register int offset __asm__("$2");
                register Moby* target __asm__("$3");
                MATCHING_KEEP(index);
                player = ControllerACA0Player;
                MATCHING_KEEP(player);
                offset = index * 11;
                target = ControllerACA0Mobys;
                MATCHING_KEEP2(offset, target);
                offset *= 8;
                target = (Moby*)((char*)target + offset);
                target->lowDrawDistance = 63;
            }
            moby->angle.roll += 8;
            if (ControllerACA0Test(prepared, player, 0x1000, &helperOutput.x) != 0) {
                moby->state = 4;
                return;
            }
            if (helperOutput.x >= 0x201) {
                unk_ovlheader_80074374();
                D_8006FA44 = 3;
                return;
            }
            break;
        case 4: {
            register int zero5 __asm__("$5");
            register int zero6 __asm__("$6");
            prepared = moby;
            __asm__("" : "=r"(prepared) : "0"(prepared) : "$5", "$3");
            zero5 = 0;
            __asm__("" : "=r"(prepared), "=r"(zero5) : "0"(prepared), "1"(zero5) : "$2", "$3");
            {
                register int index __asm__("$3") = tag[0];
                register int offset __asm__("$2");
                register Moby* base __asm__("$3");
                MATCHING_KEEP_CLOBBER(index, "$6");
                zero6 = 0;
                MATCHING_KEEP2(index, zero6);
                offset = index * 11;
                base = ControllerACA0Mobys;
                MATCHING_KEEP2(offset, base);
                offset *= 8;
                linkedMoby = (Moby*)((char*)base + offset);
            }
            func_8003BABC(prepared, zero5, zero6);
        }
            if (tag[1] != 0) {
                {
                    register int* count __asm__("$2") = &D_8006FA78;
                    register int incremented __asm__("$3");
                    MATCHING_KEEP(count);
                    incremented = *count + 1;
                    *count = incremented;
                    MATCHING_KEEP(incremented);
                    completedCount = incremented;
                }
                if (completedCount == 4) {
                    unk_ovlheader_80074374();
                }
            }
            linkedMoby->updateDistance = 0xFF;
            linkedMoby->state = 3;
            func_80034F80(linkedMoby, 2);
            {
                register int index __asm__("$3") = *(int*)linkedMoby->mobyTag;
                register int offset __asm__("$2");
                register Moby* base __asm__("$3");
                MATCHING_KEEP_CLOBBER(index, "$5");
                one = 1;
                MATCHING_KEEP2(one, index);
                offset = index * 11;
                base = ControllerACA0Mobys;
                MATCHING_KEEP2(offset, base);
                offset *= 8;
                nextLinkedMoby = (Moby*)((char*)base + offset);
            }
            nextLinkedMoby->lowDrawDistance = 0x3F;
            func_80034F80(nextLinkedMoby, one);
            moby->state = 1;
            moby->updateDistance = 0x10;
            goto clearDistance;
    }
    return;
clearDistance:
    moby->lowDrawDistance = 0;
clearDrawnFlag:
    moby->drawn = 0;
}

/* Retail path records have 16-byte point stride and a signed halfword count. */
typedef struct {
    Vector3D position;
    int reserved0C;
} DecodedChainPoint;
typedef struct {
    short count;
    unsigned char reserved02[10];
    DecodedChainPoint* points;
} DecodedChainPath;
typedef struct {
    DecodedChainPath* path;
    int pointIndex;
} DecodedChainTag;
extern int D_8006FA3C, D_8006FA80, D_8006C648;
extern unsigned short DecodedChainYaw __asm__("D_8006E040");
extern unsigned short DecodedChainPitch __asm__("D_8006E03E");
void DecodedChainFindPoint(Vector3D*, DecodedChainPath*, int*) __asm__("func_80036518");
void func_80055B18(Moby*);
void func_level_15_8007AFD0(Moby* moby) {
    DecodedChainTag* tag = moby->mobyTag;
    DecodedChainTag* childTag;
    Moby* child;
    int pointIndex, index;
    register int elapsed __asm__("$4");
    register int difference __asm__("$3");
    register int count __asm__("$4");
    int packedCount;
    register int alpha __asm__("$4");
    register int rawAlpha __asm__("$2");
    register int step __asm__("$3");
    register int encodedAlpha __asm__("$2");
    switch (moby->state) {
        case 0:
            if (D_8006FA3C != 2) {
                func_80055B18(moby);
                break;
            }
            DecodedChainFindPoint(&moby->position, tag->path, &pointIndex);
            tag->pointIndex = pointIndex;
            for (index = 1; index < 10; index++) {
                pointIndex += 3;
                child = SpawnMoby(0x16B, moby);
                if (child) {
                    childTag = child->mobyTag;
                    childTag->pointIndex = pointIndex;
                    childTag->path = tag->path;
                    func_8004F178(&child->position,
                                  &tag->path->points[childTag->pointIndex].position);
                    child->lowDrawDistance = moby->lowDrawDistance;
                    child->highDrawDistance = moby->highDrawDistance;
                    child->updateDistance = 255;
                    child->state = 1;
                }
            }
            moby->state = 1;
            break;
        case 1:
            moby->angle.yaw = ((int)(DecodedChainYaw << 16) >> 20) - 128;
            moby->angle.pitch = DecodedChainPitch >> 4;
            elapsed = D_8006FA80;
            if (elapsed < 0)
                break;
            elapsed = (elapsed + 1) % tag->path->count;
            MATCHING_KEEP_VOLATILE_CLOBBER(elapsed, "memory");
            difference = (tag->pointIndex - elapsed + tag->path->count) % tag->path->count;
            MATCHING_KEEP_VOLATILE_CLOBBER(difference, "memory");
            /* Preserve the independent count read and both original stack stores. */
            packedCount = (unsigned short)tag->path->count << 16;
            pointIndex = elapsed;
            MATCHING_BARRIER_VOLATILE("memory");
            count = packedCount >> 16;
            pointIndex = difference;
            MATCHING_KEEP(count);
            if (difference >= (packedCount >> 17)) {
                tag->pointIndex = (tag->pointIndex + 30) % count;
                moby->state = 2;
            }
            break;
        case 2:
            /* Empty constraints preserve original byte loads and compiler registers. */
            rawAlpha = ((unsigned char*)&moby->colour)[3];
            step = D_8006C648;
            alpha = (rawAlpha & 15) + step;
            __asm__("" : "=r"(alpha) : "0"(alpha), "r"(rawAlpha), "r"(step));
            if (alpha >= 16) {
                *(unsigned int*)&moby->colour = 0;
                func_8004F178(&moby->position, &tag->path->points[tag->pointIndex].position);
                moby->state = 1;
            } else {
                ((unsigned char*)&moby->colour)[0] = 0;
                ((unsigned char*)&moby->colour)[1] = 0;
                ((unsigned char*)&moby->colour)[2] = 0;
                encodedAlpha = alpha | 48;
                ((unsigned char*)&moby->colour)[3] = encodedAlpha;
                MATCHING_KEEP_VOLATILE(encodedAlpha);
            }
            moby->angle.yaw = ((int)(DecodedChainYaw << 16) >> 20) - 128;
            moby->angle.pitch = DecodedChainPitch >> 4;
            break;
    }
}

extern int D_8006FA3C, D_8006FA78, D_8006C640;
void func_level_15_8007B2E8(Moby* actor) {
    Moby** tag = actor->mobyTag;
    Moby* child;
    Vector3D childPoint, parentPoint;
    switch (actor->state) {
        case 0:
        case 1:
            actor->lowDrawDistance = (*tag)->lowDrawDistance;
            if (!actor->lowDrawDistance)
                actor->drawn = 0;
            break;
        case 2:
            switch (actor->substate) {
                case 0:
                    if (D_8006FA3C != 2) {
                        func_80055B18(actor);
                        break;
                    }
                    child = SpawnMoby(0x17F, actor);
                    if (child) {
                        func_80034F80(child, 0);
                        child->state = 0;
                        func_80055F14(child, 0, &childPoint);
                        func_80055F14(actor, 0, &parentPoint);
                        func_8004F1C8(&childPoint, &parentPoint, &childPoint);
                        func_8004F194(&child->position, &child->position, &childPoint);
                    }
                    child = SpawnMoby(0x17F, actor);
                    if (child) {
                        func_80034F80(child, 1);
                        child->state = 1;
                        func_80055F14(child, 1, &childPoint);
                        func_80055F14(actor, 1, &parentPoint);
                        func_8004F1C8(&childPoint, &parentPoint, &childPoint);
                        func_8004F194(&child->position, &child->position, &childPoint);
                    }
                    actor->substate = 1;
                    break;
                case 1:
                    if (D_8006FA78 == 3 && D_8006C640 >= 0xB) {
                        actor->lowDrawDistance = 0x3F;
                        actor->substate = 2;
                    }
                    break;
            }
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007B4D0..8007B7D8. Rev1 raw609 routes; original fresh pool and
 * private reads, vector helper sequence and signed shifts control C.
 * Pool/private producers, helper/callback semantics and cadence remain open. */
extern int D_8006FA3C;
extern Moby* D_8006C550;
extern unsigned char DecodedMushroomPlayer[] __asm__("D_80070328");
extern void (*DecodedMushroomCallback)(Moby*) __asm__("unk_ovlheader_80074384");
void func_80036A68(Moby*, int, int, int);
void func_8003BA00(Moby*);
void func_80055F14(Moby*, int, Vector3D*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004ECF4(SHORTMATRIX*, SHORTMATRIX*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
void func_level_15_8007B4D0(Moby* argument) {
    int gate = D_8006FA3C;
    Vector3D first;
    int reserved1C;
    Vector3D difference;
    int reserved2C;
    Vector3D other;
    int reserved3C;
    SHORTMATRIX matrix;
    int reserved54;
    register Moby* moby __asm__("$18") = argument;
    register Moby* deleteArgument __asm__("$4") = moby;
    register unsigned char* tag __asm__("$19") = moby->mobyTag;
    register Vector3D* scratch __asm__("$16");
    register SHORTMATRIX* transpose __asm__("$17");
    register Vector3D* extra __asm__("$17");
    if ((unsigned int)(gate - 2) < 2)
        goto remove;
    MATCHING_BARRIER_VOLATILE("$4");
    switch (moby->state) {
        case 0:
        case 1:
            if (D_8006C550[*(int*)(tag + 24)].state == 2)
                break;
            deleteArgument = moby;
            MATCHING_KEEP_VOLATILE(deleteArgument);
            goto remove;
            break;
        case 2:
            if (moby->damageFlags) {
                func_8003BABC(moby, 0, 0);
                func_80036A68(moby, 16, 0, 0);
                DecodedMushroomCallback(moby);
                func_80038F14(moby, tag, 6, 3);
                {
                    register int height __asm__("$3") = *(int*)(DecodedMushroomPlayer + 180);
                    tag[14] = 6;
                    tag[22] = 120;
                    *(unsigned short*)(tag + 4) += height >> 5;
                }
                moby->unknownCollision = 0;
                break;
            }
            moby->angle.yaw = D_8006C550[*(int*)(tag + 24)].angle.yaw;
            func_80055F14(&D_8006C550[*(int*)(tag + 24)], 0, &first);
            scratch = &difference;
            func_80055F14(&D_8006C550[*(int*)(tag + 24)], 1, scratch);
            func_8004F1C8(scratch, &first, scratch);
            transpose = &matrix;
            func_8004ECF4(transpose, &D_8006C550[*(int*)(tag + 24)].rotationMatrix);
            func_8004ED6C(transpose, scratch, scratch);
            moby->angle.roll = func_8004E880(-difference.z, difference.y, 0);
            func_80055D24(moby, 4);
            func_80055F14(moby, 2, scratch);
            {
                register Moby* prepared __asm__("$4") = moby;
                register int mode __asm__("$5") = 3;
                MATCHING_KEEP2_CLOBBER(prepared, mode, "$17");
                extra = &other;
                func_80055F14(prepared, mode, extra);
            }
            func_8004F194(scratch, scratch, extra);
            func_8004F110(scratch, 1);
            func_8004F1C8(scratch, &first, scratch);
            func_8004F194(&moby->position, &moby->position, scratch);
            func_80055D24(moby, 2);
            break;
        case 3:
            if (func_80035194(moby, tag) == 256) {
                func_80055D24(moby, 4);
                func_8003BA00(moby);
                func_800369B8(moby, 48);
                deleteArgument = moby;
                MATCHING_KEEP_VOLATILE(deleteArgument);
                goto remove;
            }
            break;
    }
    return;
remove:
    func_80055B18(deleteArgument);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 func_level_15_8007B7DC; original assembly SHA256
 * 1e6cc54ee5d46e6f7fcbedb8df56dbe324b035241fc95058fd6a4c3ac0ee150f. AI generated; not human
 * reviewed. Reuses the independently matched1182 family source, with target-specific native
 * branches, field widths, stack homes, helper arguments and table entries separately verified. 1182
 * native instructions; 6 selectors; 0 zero padding words. Frame 160 bytes. Descriptor
 * count/current/step are signed16; record stride16, actor stride88. Current linked signed16 entry
 * is read BEFORE cursor+2 on both scans. Path changes pass the OLD current-path index to the
 * original callback; the later player-path callback receives the full32 initialized index. The
 * signed /12 product executes before the independent timer predicate. Three complete signed64
 * products preserve original high/low projections; each empty h/l output consumes the entire
 * initialized x product, never a partial HI/LO input. Constant and low-word arithmetic retains
 * retail modulo32 and signed shift domains. Whole initialized GP/address/field metadata emits zero
 * CPU instructions; clobbers end only dead GP phases. No CPU opcode asm, fixed FP/SP, incoming
 * saved value, unwritten local read or overlapping live fixed alias is introduced. The original
 * local frame padding is declared but never read as invented behavior. Authored instances and
 * original dynamic-child constructor/state guards are audited separately in family1182 ownership
 * evidence. Helpers with unresolved meanings keep original word ABI. Units beyond raw shifts, full
 * producer/caller chains, cadence beyond per invocation, Rev1 mapping, SFX semantics and
 * synchronized runtime captures remain unresolved. Acceptance requires every native/linked word,
 * actual conditional/J/call/ table target, original data symbol/addend and all retail hashes. Full
 * linked EXE/every-overlay hashes remain pending parent integration.
 */
#define Family1182Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Family1182_func_80019194() __asm__("func_80019194");
int Family1182RequestMobyAnimation() __asm__("func_80034F40");
int Family1182CountTimerDown(void*, int) __asm__("func_800359A4");
int Family1182GetClosestPathNodeByVectorLength(void*, void*, void*) __asm__("func_80036518");
int Family1182_func_80036A68() __asm__("func_80036A68");
int Family1182PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Family1182_func_8004E4E4(int) __asm__("func_8004E4E4");
int Family1182TransformVectorByBasis() __asm__("func_8004ED6C");
int Family1182MeasureVectorLength() __asm__("func_8004EDE8");
int Family1182AddVector() __asm__("func_8004F194");
int Family1182ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Family1182DeleteMoby() __asm__("func_80055B18");
int Family1182RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Family1182InterpolateMobyVertex() __asm__("func_80055F14");
int Family1182_rand() __asm__("rand");
extern int Family1182_D_80065920 __asm__("D_80065920");
extern int Family1182_D_8006C550 __asm__("D_8006C550");
extern int Family1182_D_8006C648 __asm__("D_8006C648");
extern int Family1182_D_8006C730 __asm__("D_8006C730");
extern int Family1182_D_8006C770 __asm__("D_8006C770");
extern int Family1182_D_8006C7C4 __asm__("D_8006C7C4");
extern int Family1182_D_8006E020 __asm__("D_8006E020");
extern int Family1182_D_8006FA3C __asm__("D_8006FA3C");
extern int Family1182_D_8006FA78 __asm__("D_8006FA78");
extern int Family1182_D_8006FA7C __asm__("D_8006FA7C");
extern int Family1182_D_8006FA80 __asm__("D_8006FA80");
extern int Family1182_D_80070328 __asm__("D_80070328");
extern int (*Family1182_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Family1182_unk_ovlheader_80074384)() __asm__("unk_ovlheader_80074384");
extern int (*Family1182_unk_ovlheader_80074398)() __asm__("unk_ovlheader_80074398");
extern int (*Family1182_unk_ovlheader_8007439C)() __asm__("unk_ovlheader_8007439C");
extern int (*Family1182_unk_ovlheader_800743A0)() __asm__("unk_ovlheader_800743A0");
extern int (*Family1182_unk_ovlheader_800743A4)() __asm__("unk_ovlheader_800743A4");
extern int (*Family1182_unk_ovlheader_800743EC)() __asm__("unk_ovlheader_800743EC");
void func_level_15_8007B7DC(void* input) {
    register int ownerRecord20 __asm__("$20"), privateRecord19 __asm__("$19"),
        retainedFactorCounterOrVector16 __asm__("$16"), retainedPathOrAngle17 __asm__("$17"),
        retainedVectorOrAngle18 __asm__("$18"), retainedRemainderMinimum21 __asm__("$21"),
        retainedRemainderMinimum22 __asm__("$22");
    int finalProductLow;
    long long completeFinalProduct, completeSpeedProduct, completeDivisionProduct;
    int speedProductLow, divisionProductHigh;
    register int rawWord10 __asm__("$10");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        rawWord8 __asm__("$8"), rawWord9 __asm__("$9");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C;
    } originalFrame;
    int signedRemainder;
    ownerRecord20 = (int)input;
    MATCHING_KEEP(ownerRecord20);
    privateRecord19 = Family1182Field(ownerRecord20, void**, 0);
    if (Family1182_D_8006C7C4 == 2) {
        rawWord9 = 0x400;
    } else {
        rawWord9 = 0x18;
        if (Family1182_D_8006C7C4 == 1) {
            rawWord9 = 0x190;
        }
    }
    __asm__(""
            : "=r"(retainedRemainderMinimum21), "=r"(retainedRemainderMinimum22),
              "=m"(originalFrame.sp18));
    if (Family1182Field(privateRecord19, int*, 0) != 0) {
        if ((Family1182Field(ownerRecord20, int*, 0x18) != 0) &&
            (Family1182Field(ownerRecord20, unsigned char*, 0x48) != 5)) {
            Family1182Field(privateRecord19, short*, 0x3C) = 0xF0;
            Family1182Field(ownerRecord20, unsigned char*, 0x48) = 5U;
        }
        argumentWord5 = Family1182Field(privateRecord19, short**, 0x10);
        if (argumentWord5 != 0) {
            retainedRemainderMinimum22 = 5;
            rawWord8 = Family1182_D_8006C550;
            __asm__ volatile("" ::: "$21", "memory");
            retainedRemainderMinimum21 = 5;
            __asm__(""
                    : "=r"(retainedRemainderMinimum21)
                    : "0"(retainedRemainderMinimum21), "r"(rawWord8));
            argumentWord4 = ownerRecord20 - rawWord8;
            rawWord2 = ((unsigned)argumentWord4 << 5) - argumentWord4;
            rawWord2 = ((unsigned)rawWord2 << 5) + argumentWord4;
            MATCHING_KEEP(rawWord2);
            rawWord3 = (unsigned)rawWord2 << 3;
            rawWord2 += rawWord3;
            MATCHING_KEEP(rawWord2);
            rawWord3 = ((unsigned)rawWord2 << 15) - rawWord2;
            rawWord3 = ((unsigned)rawWord3 << 2) + argumentWord4;
            rawWord3 = -(unsigned)rawWord3;
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(argumentWord5));
            rawWord2 = Family1182Field(argumentWord5, short*, 2);
            rawWord10 = rawWord3 >> 3;
            originalFrame.sp18 = rawWord2;
            rawWord2 = Family1182Field(ownerRecord20, unsigned char*, 0x43);
            rawWord3 = Family1182_D_8006C730;
            argumentWord7 = Family1182Field(rawWord3, int*, rawWord2 * 4);
            do {
                rawWord2 = Family1182Field(argumentWord7, unsigned short*, 0);
                rawWord3 = rawWord2 & 0x7fff;
                MATCHING_KEEP(rawWord3);
                if (rawWord10 != rawWord3) {
                    rawWord2 = rawWord3 * 88;
                    rawWord2 = rawWord2 + rawWord8;
                    argumentWord6 = Family1182Field(rawWord2, int*, 0);
                    argumentWord4 = Family1182Field(privateRecord19, int*, 0x10);
                    rawWord3 = Family1182Field(argumentWord6, int*, 0x10);
                    rawWord2 = Family1182Field(argumentWord4, short*, 2);
                    rawWord3 = Family1182Field(rawWord3, short*, 2);
                    argumentWord5 = Family1182Field(argumentWord4, short*, 0);
                    rawWord2 = rawWord2 - rawWord3;
                    rawWord2 = rawWord2 + argumentWord5;
                    argumentWord4 = rawWord2 % argumentWord5;
                    if (argumentWord4 == 0) {
                        rawWord3 = Family1182Field(argumentWord6, int*, 0x54);
                        rawWord2 = Family1182Field(privateRecord19, int*, 0x54);
                        if (rawWord2 < rawWord3) {
                            argumentWord4 = argumentWord5;
                            MATCHING_KEEP(argumentWord4);
                        }
                    }
                    rawWord2 = argumentWord4 < retainedRemainderMinimum22;
                    if (rawWord2)
                        retainedRemainderMinimum22 = argumentWord4;
                    rawWord2 = Family1182Field(privateRecord19, int*, 0x10);
                    rawWord2 = Family1182Field(rawWord2, short*, 0);
                    argumentWord4 = rawWord2 - argumentWord4;
                    if (argumentWord4 < retainedRemainderMinimum21)
                        retainedRemainderMinimum21 = argumentWord4;
                }
                rawWord2 = Family1182Field(argumentWord7, short*, 0);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord7, "memory");
                argumentWord7 += 2;
            } while (rawWord2 >= 0);
        }
        goto dispatchOriginalState;
    }
    if (Family1182Field(ownerRecord20, int*, 0x18) != 0) {
        if (Family1182Field(ownerRecord20, unsigned char*, 0x48) != 1) {
            Family1182_func_80036A68(ownerRecord20, 0x10, 0, 0);
            Family1182_unk_ovlheader_80074384(ownerRecord20);
            Family1182Field(privateRecord19, int*, 0x44) = 0x78;
            Family1182Field(privateRecord19, int*, 0x18) =
                (int)(Family1182MeasureVectorLength(privateRecord19 + 0x28, 1) * 2);
            Family1182Field(privateRecord19, int*, 0x20) =
                (int)(Family1182Field(ownerRecord20, unsigned char*, 0x45) * 0x10);
            Family1182Field(privateRecord19, int*, 0x24) =
                (int)(Family1182Field(ownerRecord20, unsigned char*, 0x46) * 0x10);
            if (Family1182_rand() & 1) {
                Family1182Field(privateRecord19, int*, 0x28) = -0x40;
                rawWord2 = 0x10;
            } else {
                Family1182Field(privateRecord19, int*, 0x28) = 0x40;
                rawWord2 = -0x10;
            }
            Family1182Field(privateRecord19, int*, 0x30) = rawWord2;
            __asm__ volatile("" ::"m"(Family1182Field(privateRecord19, int*, 0x30)) : "memory");
            Family1182Field(privateRecord19, int*, 0x2C) = -0x20;
            Family1182Field(ownerRecord20, int*, 8) = 0;
            Family1182Field(ownerRecord20, unsigned char*, 0x48) = 1U;
            Family1182RequestMobyAnimation(ownerRecord20, 1);
            return;
        }
        goto dispatchPreparedOriginalState;
    }
dispatchOriginalState:
dispatchPreparedOriginalState:
    switch (Family1182Field(ownerRecord20, unsigned char*, 0x48)) {
        case 0:
            if (Family1182Field(privateRecord19, int*, 0) != 0) {
                if (Family1182_D_8006FA3C == 2) {
                    rawWord3 = Family1182Field(privateRecord19, void***, 4);
                    if ((*(int*)rawWord3) == 0) {
                        (*(int*)rawWord3) = ownerRecord20;
                        Family1182GetClosestPathNodeByVectorLength(
                            Family1182_D_8006C550 +
                                (Family1182Field(privateRecord19, int*, 0x4C) * 0x58) + 0xC,
                            Family1182Field(privateRecord19, short**, 8),
                            Family1182Field(privateRecord19, int**, 0x50));
                        Family1182_D_8006FA80 = -2;
                    }
                    rawWord2 = Family1182Field(ownerRecord20, unsigned char*, 0x44);
                    rawWord2 *= 16;
                    Family1182Field(privateRecord19, int*, 0x1C) = rawWord2;
                    __asm__ volatile("" ::"m"(Family1182Field(privateRecord19, int*, 0x1C))
                                     : "memory");
                    rawWord2 = Family1182Field(ownerRecord20, unsigned char*, 0x45);
                    argumentWord4 = Family1182Field(privateRecord19, int*, 8);
                    rawWord2 *= 16;
                    Family1182Field(privateRecord19, int*, 0x20) = rawWord2;
                    rawWord3 = Family1182Field(ownerRecord20, unsigned char*, 0x46);
                    __asm__ volatile("" ::: "$2", "memory");
                    rawWord2 = Family1182Field(privateRecord19, int*, 0x54);
                    Family1182Field(privateRecord19, int*, 0x10) = argumentWord4;
                    rawWord2 = rawWord2 * 32 + 128;
                    rawWord3 *= 16;
                    Family1182Field(privateRecord19, int*, 0x14) = rawWord2;
                    Family1182Field(privateRecord19, int*, 0x24) = rawWord3;
                    goto initializeOriginalPath;
                }
                goto deleteOriginalActor;
            }
            if ((unsigned int)(Family1182_D_8006FA3C - 2) >= 2U) {
            initializeOriginalPath:
                Family1182Field(Family1182Field(privateRecord19, short**, 0x10), short*, 0xA) = 1;
                Family1182GetClosestPathNodeByVectorLength(
                    ownerRecord20 + 0xC, Family1182Field(privateRecord19, short**, 0x10),
                    &originalFrame.sp18);
                Family1182Field(Family1182Field(privateRecord19, short**, 0x10), short*, 2) =
                    (short)originalFrame.sp18;
                argumentWord4 = Family1182Field(privateRecord19, short**, 0x10);
                rawWord3 = Family1182Field(argumentWord4, short*, 0);
                Family1182Field(argumentWord4, short*, 2) =
                    (short)((int)(Family1182Field(argumentWord4, short*, 2) +
                                  Family1182Field(argumentWord4, short*, 0xA) + rawWord3) %
                            rawWord3);
                argumentWord5 = 0x7fffffff;
                rawWord3 = Family1182Field(privateRecord19, int*, 0x54);
                rawWord2 = Family1182Field(privateRecord19, int*, 0x58);
                rawWord3 = rawWord3 * 4 + rawWord2;
                rawWord2 = Family1182Field(ownerRecord20, int*, 0x1C);
                rawWord3 = Family1182Field(rawWord3, int*, 0);
                rawWord2 &= argumentWord5;
                Family1182Field(ownerRecord20, int*, 0x1C) = rawWord2;
                rawWord2 = 2;
                Family1182Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
                Family1182Field(ownerRecord20, int*, 0x54) = rawWord3;
                Family1182Field(ownerRecord20, signed char*, 0x57) = 0;
            } else
                goto deleteOriginalActor;
        default:
            goto processOriginalCommonPath;
        case 1:
            Family1182CountTimerDown(privateRecord19 + 0x44, 4);
            if (Family1182Field(ownerRecord20, unsigned short*, 0x3C) != 0x101) {
                if (Family1182Field(privateRecord19, int*, 0x44) != 0) {
                    goto updateOriginalFallAngles;
                }
                goto deleteOriginalActor;
            }
            if (Family1182_D_8006C770 != 0) {
                Family1182RequestMobyAnimation(ownerRecord20, 2);
            }
        updateOriginalFallAngles:
            rawWord2 = Family1182Field(privateRecord19, int*, 0x1C);
            argumentWord4 = Family1182Field(privateRecord19, int*, 0x28);
            rawWord3 = Family1182Field(privateRecord19, int*, 0x20);
            argumentWord5 = Family1182Field(privateRecord19, int*, 0x2C);
            rawWord2 += argumentWord4;
            Family1182Field(privateRecord19, int*, 0x1C) = rawWord2;
            rawWord3 = (rawWord3 + argumentWord5) & 0xfff;
            Family1182Field(privateRecord19, int*, 0x20) = rawWord3;
            if (rawWord3 >= 2049) {
                rawWord2 = rawWord3 - 4096;
                Family1182Field(privateRecord19, int*, 0x20) = rawWord2;
                MATCHING_OBSERVE2_VOLATILE(rawWord2, rawWord3);
            }
            if (Family1182Field(privateRecord19, int*, 0x20) < -0x200) {
                Family1182Field(privateRecord19, int*, 0x20) = -0x200;
            }
            Family1182Field(privateRecord19, int*, 0x24) =
                (int)(Family1182Field(privateRecord19, int*, 0x24) +
                      Family1182Field(privateRecord19, int*, 0x30));
            Family1182Field(ownerRecord20, unsigned char*, 0x44) =
                (unsigned char)((int)Family1182Field(privateRecord19, int*, 0x1C) >> 4);
            Family1182Field(ownerRecord20, unsigned char*, 0x45) =
                (unsigned char)((int)Family1182Field(privateRecord19, int*, 0x20) >> 4);
            Family1182Field(ownerRecord20, unsigned char*, 0x46) =
                (unsigned char)((int)Family1182Field(privateRecord19, int*, 0x24) >> 4);
            Family1182RefreshMobySpatialGridAndBasis(ownerRecord20, 4);
            argumentWord4 = ownerRecord20 + 32;
            retainedFactorCounterOrVector16 = (int)&originalFrame.sp20;
            argumentWord5 = retainedFactorCounterOrVector16;
            rawWord2 = Family1182Field(privateRecord19, int*, 0x18);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedFactorCounterOrVector16;
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                               "memory");
            originalFrame.sp24 = 0;
            originalFrame.sp28 = 0;
            originalFrame.sp20 = rawWord2;
            Family1182TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
            retainedPathOrAngle17 = ownerRecord20 + 0xC;
            Family1182AddVector(retainedPathOrAngle17, retainedPathOrAngle17, &originalFrame.sp20);
            Family1182InterpolateMobyVertex(ownerRecord20, 1, &originalFrame.sp30);
            originalFrame.sp20 = (Family1182_rand() & 0x3E) - 0x1F;
            originalFrame.sp24 = (Family1182_rand() & 0x3E) - 0x1F;
            originalFrame.sp28 = (Family1182_rand() & 0x3E) - 0x1F;
            Family1182_SpawnParticle(1, 1, &originalFrame.sp30, &originalFrame.sp20);
            if (Family1182_func_80019194(retainedPathOrAngle17, 0x400) != 0) {
                goto deleteOriginalActor;
            }
            goto processOriginalCommonPath;
        case 2:
            if (Family1182Field(privateRecord19, int*, 0) != 0) {
                Family1182Field(privateRecord19, int*, 0x18) = Family1182_func_8004E4E4(
                    Family1182Field(ownerRecord20, int*, 0x14) -
                    ((int)((rawWord9 * (Family1182Field(privateRecord19, int*, 0x54) + 2))
                           << 0xE) >>
                     0x10));
                rawWord2 = Family1182ApproximatePlanarDistance(ownerRecord20 + 12,
                                                               (int)&Family1182_D_8006E020);
                rawWord2 = rawWord2 < 2048;
                if (rawWord2) {
                    rawWord2 = Family1182Field(privateRecord19, int*, 0x18);
                    rawWord2 -= 2048;
                    Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
                }
                rawWord2 = retainedRemainderMinimum21 < 5;
                if (rawWord2) {
                    rawWord2 = Family1182Field(privateRecord19, int*, 0x18);
                    rawWord2 -= 1024;
                    Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
                }
                rawWord3 = Family1182Field(privateRecord19, int*, 0x18);
                rawWord2 = Family1182_D_8006C648;
                completeSpeedProduct = (long long)(int)rawWord3 * (int)rawWord2;
                argumentWord4 = ownerRecord20;
                argumentWord6 = privateRecord19 + 0x18;
                argumentWord5 = Family1182Field(privateRecord19, int*, 0x10);
                rawWord3 = (int)Family1182_unk_ovlheader_80074398;
                __asm__(""
                        : "=l"(speedProductLow)
                        : "x"(completeSpeedProduct), "r"(rawWord3), "r"(argumentWord6));
                rawWord2 = speedProductLow >> 6;
                Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
                ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6);
                rawWord2 = Family1182_D_8006C730;
                __asm__ volatile("" ::: "$18", "memory");
                retainedVectorOrAngle18 = (int)&originalFrame.sp40;
                retainedPathOrAngle17 = Family1182Field(rawWord2, int*, 4);
            scanOriginalLinkedEntry:
                rawWord3 = Family1182Field(retainedPathOrAngle17, unsigned short*, 0);
                rawWord3 &= 0x7fff;
                MATCHING_KEEP(rawWord3);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Family1182_D_8006C550;
                retainedFactorCounterOrVector16 = rawWord3 + rawWord2;
                if (Family1182_unk_ovlheader_800743A0(retainedFactorCounterOrVector16,
                                                      ownerRecord20 + 0xC, 0x400) != 0) {
                    Family1182PlayMobySoundEvent(retainedFactorCounterOrVector16, 1, 0);
                    retainedFactorCounterOrVector16 = 0;
                    argumentWord4 = ownerRecord20 + 0x20;
                    do {
                        argumentWord5 = retainedVectorOrAngle18;
                        rawWord2 = Family1182Field(privateRecord19, int*, 0x18);
                        __asm__ volatile("" ::: "$6", "memory");
                        argumentWord6 = retainedVectorOrAngle18;
                        MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5,
                                                           argumentWord6, "memory");
                        originalFrame.sp44 = 0;
                        originalFrame.sp48 = 0;
                        originalFrame.sp40 = rawWord2;
                        Family1182TransformVectorByBasis(argumentWord4, argumentWord5,
                                                         argumentWord6);
                        retainedFactorCounterOrVector16 += 1;
                        rawWord2 = Family1182_rand();
                        rawWord3 = originalFrame.sp40;
                        rawWord2 &= 0xFE;
                        rawWord3 -= 127;
                        rawWord3 += rawWord2;
                        originalFrame.sp40 = rawWord3;
                        rawWord2 = Family1182_rand();
                        rawWord3 = originalFrame.sp44;
                        rawWord2 &= 0xFE;
                        rawWord3 -= 127;
                        rawWord3 += rawWord2;
                        originalFrame.sp44 = rawWord3;
                        rawWord2 = Family1182_rand();
                        argumentWord4 = 1;
                        argumentWord5 = 23;
                        argumentWord6 = ownerRecord20 + 12;
                        argumentWord7 = (int)retainedVectorOrAngle18;
                        MATCHING_OBSERVE4_VOLATILE(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7);
                        rawWord2 &= 254;
                        rawWord3 = originalFrame.sp48;
                        rawWord3 -= 127;
                        rawWord3 += rawWord2;
                        originalFrame.sp48 = rawWord3;
                        Family1182_SpawnParticle(argumentWord4, argumentWord5, argumentWord6,
                                                 argumentWord7);
                        argumentWord4 = ownerRecord20 + 0x20;
                    } while (retainedFactorCounterOrVector16 < 8);
                    rawWord3 = Family1182Field(privateRecord19, int*, 0x30);
                    __asm__ volatile("" ::: "$2", "memory");
                    rawWord2 = 48;
                    Family1182Field(privateRecord19, short*, 0x3C) = rawWord2;
                    if (rawWord3 >= 0) {
                        rawWord2 = -1;
                    } else {
                        MATCHING_BARRIER_VOLATILE("$2");
                        rawWord2 = 1;
                    }
                    Family1182Field(privateRecord19, short*, 0x3E) = rawWord2;
                    rawWord2 = 3;
                writeOriginalTransitionState:
                    Family1182Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
                } else {
                    rawWord2 = Family1182Field(retainedPathOrAngle17, short*, 0);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(retainedPathOrAngle17, "memory");
                    retainedPathOrAngle17 += 2;
                    if (rawWord2 < 0) {
                    } else {
                        goto scanOriginalLinkedEntry;
                    }
                }
                goto processOriginalCommonPath;
            }
            if (Family1182_D_8006FA3C == 2) {
            deleteOriginalActor:
                Family1182DeleteMoby(ownerRecord20);
                return;
            }
            retainedFactorCounterOrVector16 = Family1182Field(ownerRecord20, unsigned char*, 0x46);
            Family1182_unk_ovlheader_800743EC(
                ownerRecord20, Family1182Field(privateRecord19, short**, 0x10),
                privateRecord19 + 0x28, privateRecord19 + 0x44, 0x12, 0);
            rawWord2 = Family1182Field(ownerRecord20, unsigned char*, 0x46);
            rawWord2 = retainedFactorCounterOrVector16 - rawWord2;
            retainedFactorCounterOrVector16 = rawWord2 & 255;
            if (retainedFactorCounterOrVector16 >= 0x81) {
                retainedFactorCounterOrVector16 -= 0x100;
            }
            rawWord2 = Family1182Field(ownerRecord20, unsigned char*, 0x44);
            rawWord3 = (unsigned)retainedFactorCounterOrVector16 << 6;
            rawWord3 -= rawWord2;
            retainedFactorCounterOrVector16 = rawWord3 & 255;
            if (retainedFactorCounterOrVector16 >= 0x81) {
                retainedFactorCounterOrVector16 -= 0x100;
            }
            argumentWord4 = Family1182Field(privateRecord19, int*, 0x34);
            rawWord3 = (unsigned)retainedFactorCounterOrVector16 << 3;
            rawWord2 = argumentWord4 * 12;
            rawWord3 = rawWord3 - rawWord2;
            MATCHING_OBSERVE_VOLATILE(rawWord3);
            rawWord3 >>= 6;
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(retainedFactorCounterOrVector16));
            rawWord2 = Family1182Field(privateRecord19, int*, 0x1C);
            argumentWord4 += rawWord3;
            Family1182Field(privateRecord19, int*, 0x34) = argumentWord4;
            rawWord2 += argumentWord4;
            rawWord3 = rawWord2 & 4095;
            Family1182Field(privateRecord19, int*, 0x1C) = rawWord3;
            if (rawWord3 >= 0x801) {
                rawWord2 = rawWord3 - 4096;
                Family1182Field(privateRecord19, int*, 0x1C) = rawWord2;
                MATCHING_OBSERVE2_VOLATILE(rawWord2, rawWord3);
            }
            rawWord2 = Family1182Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::: "$3", "memory");
            rawWord3 = Family1182Field(privateRecord19, int*, 0x38);
            if (rawWord3 < rawWord2) {
                Family1182Field(privateRecord19, int*, 0x1C) = rawWord3;
            }
            rawWord3 = -Family1182Field(privateRecord19, int*, 0x38);
            if (Family1182Field(privateRecord19, int*, 0x1C) < rawWord3) {
                Family1182Field(privateRecord19, int*, 0x1C) = rawWord3;
            }
            Family1182Field(ownerRecord20, unsigned char*, 0x44) =
                (unsigned char)((int)Family1182Field(privateRecord19, int*, 0x1C) >> 4);
            Family1182RefreshMobySpatialGridAndBasis(ownerRecord20, 4);
            goto processOriginalCommonPath;
        case 3:
            rawWord2 = Family1182Field(privateRecord19, int*, 0x54) + 2;
            argumentWord4 = Family1182Field(ownerRecord20, int*, 0x14);
            retainedFactorCounterOrVector16 = (int)(rawWord9 * rawWord2) >> 2;
            __asm__(""
                    : "=r"(retainedFactorCounterOrVector16)
                    : "0"(retainedFactorCounterOrVector16), "r"(argumentWord4));
            rawWord3 = Family1182_func_8004E4E4(argumentWord4 - retainedFactorCounterOrVector16);
            MATCHING_KEEP(rawWord3);
            Family1182Field(privateRecord19, int*, 0x18) = rawWord3;
            if (retainedRemainderMinimum21 < 5) {
                rawWord2 = rawWord3 - 1024;
            } else
                rawWord2 = rawWord3 + 8192;
            Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord2, rawWord3, "memory");
            rawWord3 = Family1182Field(privateRecord19, int*, 0x18);
            rawWord2 = Family1182_D_8006C648;
            rawWord2 = (int)(rawWord3 * rawWord2) >> 6;
            Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
            retainedFactorCounterOrVector16 = Family1182Field(privateRecord19, int*, 0x1C);
            Family1182_unk_ovlheader_80074398(ownerRecord20,
                                              Family1182Field(privateRecord19, short**, 0x10),
                                              privateRecord19 + 0x18);
            rawWord2 = Family1182Field(privateRecord19, short*, 0x3E) << 7;
            retainedFactorCounterOrVector16 = (retainedFactorCounterOrVector16 + rawWord2) & 0xFFF;
            Family1182Field(privateRecord19, int*, 0x1C) = retainedFactorCounterOrVector16;
            Family1182Field(privateRecord19, int*, 0x28) = rawWord2;
            Family1182Field(ownerRecord20, unsigned char*, 0x44) =
                (unsigned char)(retainedFactorCounterOrVector16 >> 4);
            if (Family1182CountTimerDown(privateRecord19 + 0x3C, 2) != 0) {
                Family1182Field(ownerRecord20, unsigned char*, 0x48) = 4U;
            }
            retainedFactorCounterOrVector16 = 0;
            retainedPathOrAngle17 = (int)&originalFrame.sp40;
            argumentWord4 = ownerRecord20 + 32;
            do {
                argumentWord5 = retainedPathOrAngle17;
                rawWord2 = Family1182Field(privateRecord19, int*, 0x18);
                __asm__ volatile("" ::: "$6", "memory");
                argumentWord6 = retainedPathOrAngle17;
                MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                                   "memory");
                originalFrame.sp44 = 0;
                originalFrame.sp48 = 0;
                rawWord2 >>= 2;
                originalFrame.sp40 = rawWord2;
                Family1182TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
                retainedFactorCounterOrVector16 += 1;
                rawWord2 = Family1182_rand();
                rawWord3 = originalFrame.sp40;
                rawWord2 &= 0xFE;
                rawWord3 -= 127;
                rawWord3 += rawWord2;
                originalFrame.sp40 = rawWord3;
                rawWord2 = Family1182_rand();
                rawWord3 = originalFrame.sp44;
                rawWord2 &= 0xFE;
                rawWord3 -= 127;
                rawWord3 += rawWord2;
                originalFrame.sp44 = rawWord3;
                rawWord2 = Family1182_rand();
                argumentWord4 = 1;
                argumentWord5 = 23;
                argumentWord6 = ownerRecord20 + 12;
                argumentWord7 = retainedPathOrAngle17;
                MATCHING_OBSERVE4_VOLATILE(argumentWord4, argumentWord5, argumentWord6,
                                           argumentWord7);
                rawWord2 &= 254;
                rawWord3 = originalFrame.sp48;
                rawWord3 -= 127;
                rawWord3 += rawWord2;
                originalFrame.sp48 = rawWord3;
                Family1182_SpawnParticle(argumentWord4, argumentWord5, argumentWord6,
                                         argumentWord7);
                argumentWord4 = ownerRecord20 + 0x20;
            } while (retainedFactorCounterOrVector16 < 2);
            goto processOriginalCommonPath;
        case 4:
            rawWord2 = Family1182Field(privateRecord19, int*, 0x54) + 2;
            argumentWord4 = Family1182Field(ownerRecord20, int*, 0x14);
            retainedPathOrAngle17 = (int)(rawWord9 * rawWord2) >> 2;
            __asm__(""
                    : "=r"(retainedPathOrAngle17)
                    : "0"(retainedPathOrAngle17), "r"(argumentWord4));
            retainedPathOrAngle17 = Family1182_func_8004E4E4(argumentWord4 - retainedPathOrAngle17);
            if (retainedRemainderMinimum21 < 5) {
                Family1182Field(privateRecord19, int*, 0x18) =
                    (int)(Family1182Field(privateRecord19, int*, 0x18) - 0x400);
            }
            argumentWord4 = Family1182Field(privateRecord19, int*, 0x18);
            retainedPathOrAngle17 = (int)(retainedPathOrAngle17 * Family1182_D_8006C648) >> 6;
            if ((argumentWord4 - retainedPathOrAngle17) >= 4) {
                rawWord2 = argumentWord4 - (Family1182_D_8006C648 * 3);
                Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
            } else {
                Family1182Field(privateRecord19, int*, 0x18) = retainedPathOrAngle17;
                Family1182Field(ownerRecord20, unsigned char*, 0x48) = 2U;
            }
            retainedVectorOrAngle18 = Family1182Field(privateRecord19, int*, 0x1C);
            retainedPathOrAngle17 = Family1182Field(privateRecord19, int*, 0x28);
            Family1182_unk_ovlheader_80074398(ownerRecord20,
                                              Family1182Field(privateRecord19, short**, 0x10),
                                              privateRecord19 + 0x18);
            rawWord2 = -retainedVectorOrAngle18;
            retainedVectorOrAngle18 = rawWord2 & 0xFFF;
            Family1182Field(privateRecord19, int*, 0x28) = retainedPathOrAngle17;
            if (retainedVectorOrAngle18 >= 0x801) {
                retainedVectorOrAngle18 -= 0x1000;
            }
            argumentWord4 = ownerRecord20 + 32;
            retainedFactorCounterOrVector16 = (int)&originalFrame.sp50;
            argumentWord5 = retainedFactorCounterOrVector16;
            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
            rawWord2 = retainedPathOrAngle17 +
                       ((int)(retainedVectorOrAngle18 - (retainedPathOrAngle17 * 0x18)) >> 6);
            Family1182Field(privateRecord19, int*, 0x28) = rawWord2;
            rawWord3 = (Family1182Field(privateRecord19, int*, 0x1C) + rawWord2) & 0xFFF;
            Family1182Field(privateRecord19, int*, 0x1C) = rawWord3;
            Family1182Field(ownerRecord20, unsigned char*, 0x44) = (unsigned char)(rawWord3 >> 4);
            rawWord2 = Family1182Field(privateRecord19, int*, 0x18);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedFactorCounterOrVector16;
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                               "memory");
            originalFrame.sp54 = 0;
            originalFrame.sp58 = 0;
            rawWord2 >>= 2;
            originalFrame.sp50 = rawWord2;
            Family1182TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 = Family1182_rand();
            rawWord3 = originalFrame.sp50;
            rawWord2 &= 0xFE;
            rawWord3 -= 127;
            rawWord3 += rawWord2;
            originalFrame.sp50 = rawWord3;
            rawWord2 = Family1182_rand();
            rawWord3 = originalFrame.sp54;
            rawWord2 &= 0xFE;
            rawWord3 -= 127;
            rawWord3 += rawWord2;
            originalFrame.sp54 = rawWord3;
            rawWord2 = Family1182_rand();
            argumentWord4 = 1;
            argumentWord5 = 23;
            argumentWord6 = ownerRecord20 + 12;
            argumentWord7 = (int)&originalFrame.sp50;
            MATCHING_OBSERVE4_VOLATILE(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            rawWord2 &= 254;
            rawWord3 = originalFrame.sp58;
            rawWord3 -= 127;
            rawWord3 += rawWord2;
            originalFrame.sp58 = rawWord3;
            Family1182_SpawnParticle(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            goto processOriginalCommonPath;
        case 5:
            rawWord2 = Family1182Field(privateRecord19, int*, 0x54) + 2;
            argumentWord4 = Family1182Field(ownerRecord20, int*, 0x14);
            retainedFactorCounterOrVector16 = (int)(rawWord9 * rawWord2) >> 2;
            __asm__(""
                    : "=r"(retainedFactorCounterOrVector16)
                    : "0"(retainedFactorCounterOrVector16), "r"(argumentWord4));
            rawWord3 = Family1182_func_8004E4E4(argumentWord4 - retainedFactorCounterOrVector16);
            MATCHING_KEEP(rawWord3);
            Family1182Field(privateRecord19, int*, 0x18) = rawWord3;
            if (retainedRemainderMinimum22 >= 5) {
                rawWord2 = rawWord3 - 0x1000;
                Family1182Field(privateRecord19, int*, 0x18) = rawWord2;
                MATCHING_OBSERVE2_VOLATILE(rawWord2, rawWord3);
            }
            if (Family1182Field(privateRecord19, int*, 0x18) < 0x800) {
                Family1182Field(privateRecord19, int*, 0x18) = 0x800;
            }
            retainedPathOrAngle17 = Family1182Field(privateRecord19, int*, 0x1C);
            Family1182Field(privateRecord19, int*, 0x18) =
                (int)((int)(Family1182Field(privateRecord19, int*, 0x18) * Family1182_D_8006C648) >>
                      6);
            retainedFactorCounterOrVector16 = Family1182Field(privateRecord19, int*, 0x28);
            Family1182_unk_ovlheader_80074398(ownerRecord20,
                                              Family1182Field(privateRecord19, short**, 0x10),
                                              privateRecord19 + 0x18);
            Family1182Field(privateRecord19, int*, 0x28) = retainedFactorCounterOrVector16;
            Family1182Field(privateRecord19, int*, 0x1C) = retainedPathOrAngle17;
            rawWord3 = Family1182Field(privateRecord19, short*, 0x3C);
            rawWord2 = 240 - rawWord3;
            retainedFactorCounterOrVector16 = (unsigned)rawWord2 << 3;
            MATCHING_KEEP(retainedFactorCounterOrVector16);
            rawWord2 = retainedFactorCounterOrVector16 & 0x1f8;
            rawWord2 = Family1182Field((int)&Family1182_D_80065920, unsigned short*, rawWord2);
            MATCHING_KEEP(rawWord2);
            rawWord2 = (unsigned)rawWord2 << 16;
            retainedFactorCounterOrVector16 = rawWord2 >> 19;
            MATCHING_KEEP(retainedFactorCounterOrVector16);
            rawWord2 = retainedFactorCounterOrVector16 - retainedPathOrAngle17;
            retainedPathOrAngle17 = rawWord2 & 0xfff;
            if (retainedPathOrAngle17 >= 0x801) {
                retainedPathOrAngle17 -= 0xFFF;
            }
            argumentWord5 = 0x2aaaaaab;
            argumentWord4 = Family1182Field(privateRecord19, int*, 0x28);
            rawWord3 = retainedPathOrAngle17 * 2;
            rawWord2 = argumentWord4 * 24;
            rawWord3 -= rawWord2;
            rawWord3 >>= 6;
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(retainedPathOrAngle17));
            argumentWord4 += rawWord3;
            Family1182Field(privateRecord19, int*, 0x28) = argumentWord4;
            rawWord2 = (Family1182Field(privateRecord19, int*, 0x1C) + argumentWord4) & 0xFFF;
            Family1182Field(privateRecord19, int*, 0x1C) = rawWord2;
            Family1182Field(ownerRecord20, unsigned char*, 0x44) = (unsigned char)(rawWord2 >> 4);
            rawWord3 = Family1182Field(privateRecord19, short*, 0x3C);
            rawWord2 = 90 - rawWord3;
            completeDivisionProduct = (long long)(int)rawWord2 * (int)argumentWord5;
            rawWord2 >>= 31;
            rawWord3 = rawWord3 < 90;
            __asm__(""
                    : "=h"(divisionProductHigh)
                    : "x"(completeDivisionProduct), "r"(rawWord2), "r"(rawWord3));
            argumentWord4 = divisionProductHigh >> 1;
            retainedFactorCounterOrVector16 = argumentWord4 - rawWord2;
            if (!rawWord3 || __extension__({
                    rawWord2 = retainedFactorCounterOrVector16 & 1;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(retainedFactorCounterOrVector16));
                    argumentWord4 = privateRecord19 + 0x3C;
                    rawWord2;
                })) {
                Family1182InterpolateMobyVertex(ownerRecord20, 1, &originalFrame.sp70);
                retainedFactorCounterOrVector16 = 0;
                do {
                    retainedFactorCounterOrVector16 += 1;
                    originalFrame.sp60 = (Family1182_rand() & 0x3E) - 0x1F;
                    originalFrame.sp64 = (Family1182_rand() & 0x3E) - 0x1F;
                    originalFrame.sp68 = (Family1182_rand() & 0x3E) - 0x1F;
                    Family1182_SpawnParticle(1, 1, &originalFrame.sp70, &originalFrame.sp60);
                    argumentWord4 = privateRecord19 + 0x3C;
                } while (retainedFactorCounterOrVector16 < 2);
            }
            if (Family1182CountTimerDown(argumentWord4, 2) != 0) {
                Family1182Field(ownerRecord20, int*, 0x18) = 0;
                rawWord2 = 2;
                Family1182Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
            }
            goto processOriginalCommonPath;
    }
processOriginalCommonPath:
    if (Family1182Field(privateRecord19, int*, 0) != 0) {
        argumentWord4 = Family1182Field(privateRecord19, short**, 0x10);
        rawWord3 = Family1182Field(argumentWord4, short*, 2);
        if ((rawWord3 != originalFrame.sp18) &&
            (Family1182Field(((rawWord3 * 0x10) + Family1182Field(argumentWord4, int*, 0xC)), int*,
                             0xC) != 0)) {
            rawWord2 = retainedRemainderMinimum22 < 5;
            if (rawWord2) {
                rawWord2 = 1;
                originalFrame.sp18 = rawWord2;
            } else {
                rawWord2 = retainedRemainderMinimum21 < 5;
                if (!rawWord2) {
                    rawWord2 = Family1182Field(privateRecord19, int*, 0x54);
                    rawWord3 = Family1182Field(privateRecord19, int*, 0x14);
                    rawWord2 = rawWord2 * 8 + 128;
                    rawWord3 = rawWord3 + rawWord2;
                    Family1182Field(privateRecord19, int*, 0x14) = rawWord3;
                    rawWord3 = rawWord3 < 345;
                    if (!rawWord3) {
                        rawWord3 = 1;
                        MATCHING_KEEP_VOLATILE_CLOBBER(rawWord3, "memory");
                        rawWord2 = Family1182Field(privateRecord19, int*, 0x14);
                        originalFrame.sp18 = rawWord3;
                        rawWord2 -= 345;
                        Family1182Field(privateRecord19, int*, 0x14) = rawWord2;
                        goto family1182Selected;
                    }
                }
                originalFrame.sp18 = 0;
            }
        family1182Selected:
            rawWord2 = originalFrame.sp18;
            rawWord3 = Family1182Field(privateRecord19, int*, 0x10);
            rawWord2 = rawWord2 * 4 + privateRecord19;
            argumentWord5 = Family1182Field(rawWord2, int*, 8);
            argumentWord4 = ownerRecord20 + 12;
            if (rawWord3 != argumentWord5) {
                argumentWord6 = Family1182Field(rawWord3, short*, 2);
                rawWord2 = (int)Family1182_unk_ovlheader_800743A4;
                rawWord2 = ((int (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, 3);
                rawWord3 = originalFrame.sp18 * 4 + privateRecord19;
                argumentWord4 = Family1182Field(rawWord3, int*, 8);
                Family1182Field(argumentWord4, short*, 2) = rawWord2;
                rawWord3 = Family1182Field(rawWord3, int*, 8);
                rawWord2 = 1;
                Family1182Field(privateRecord19, int*, 0x10) = rawWord3;
                Family1182Field(rawWord3, short*, 0xA) = rawWord2;
                argumentWord5 = Family1182Field(privateRecord19, int*, 0x10);
                rawWord3 = Family1182Field(argumentWord5, short*, 0);
                rawWord2 = Family1182Field(argumentWord5, short*, 2);
                argumentWord4 = rawWord3 + 2;
                rawWord2 = rawWord2 + argumentWord4;
                rawWord3 = rawWord2 % rawWord3;
                Family1182Field(argumentWord5, short*, 2) = rawWord3;
            }
        }
        argumentWord4 = privateRecord19 + 0x44;
        if (*Family1182Field(privateRecord19, void***, 4) == ownerRecord20) {
            Family1182Field((int)&Family1182_D_8006FA7C, int*, 0) = 0;
            if (Family1182Field((int)&Family1182_D_8006FA7C, int*, 4) == -1) {
                Family1182GetClosestPathNodeByVectorLength(
                    (int)&Family1182_D_80070328, Family1182Field(privateRecord19, short**, 8),
                    (int)&Family1182_D_8006FA7C + 4);
            } else if (Family1182Field((int)&Family1182_D_8006FA7C, int*, 4) == -2) {
                Family1182Field((int)&Family1182_D_8006FA7C, int*, 4) = -1;
            }
            retainedPathOrAngle17 = (int)&Family1182_D_8006FA80;
            retainedFactorCounterOrVector16 = Family1182Field(retainedPathOrAngle17, int*, 0);
            if (retainedFactorCounterOrVector16 >= 0) {
                argumentWord6 = retainedFactorCounterOrVector16;
                rawWord3 = Family1182_unk_ovlheader_800743A4(
                    (int)&Family1182_D_80070328, Family1182Field(privateRecord19, int*, 8),
                    argumentWord6, 10);
                Family1182Field(retainedPathOrAngle17, int*, 0) = rawWord3;
                rawWord2 = retainedFactorCounterOrVector16 < 10;
                if (rawWord2) {
                    rawWord2 = Family1182Field(privateRecord19, int*, 8);
                    rawWord2 = Family1182Field(rawWord2, short*, 0);
                    rawWord2 -= 11;
                    if (rawWord2 < rawWord3) {
                        rawWord2 = 10;
                        Family1182Field(retainedPathOrAngle17, int*, 0) = rawWord2;
                    }
                }
            }
            argumentWord4 = privateRecord19 + 0x44;
        }
        if ((Family1182CountTimerDown(argumentWord4, 4) != 0) &&
            (Family1182_unk_ovlheader_8007439C(
                 Family1182_D_8006C550 + (Family1182Field(privateRecord19, int*, 0x4C) * 0x58),
                 ownerRecord20 + 0xC, 0x1000, 0) != 0)) {
            Family1182Field(privateRecord19, int*, 0x44) = 0x78;
            Family1182Field(privateRecord19, int*, 0x40) =
                (int)(Family1182Field(privateRecord19, int*, 0x40) + 1);
        }
        argumentWord4 = *Family1182Field(privateRecord19, short**, 8);
        retainedFactorCounterOrVector16 = (int)((Family1182_D_8006FA80 + argumentWord4) -
                                                *Family1182Field(privateRecord19, int**, 0x50)) %
                                          argumentWord4;
        if ((Family1182Field(
                 ((Family1182Field(privateRecord19, int*, 0x4C) * 0x58) + Family1182_D_8006C550),
                 unsigned char*, 0x48) == 3) &&
            (retainedFactorCounterOrVector16 == 0)) {
            retainedFactorCounterOrVector16 = (int)argumentWord4;
        }
        argumentWord5 = Family1182Field(privateRecord19, short**, 8);
        retainedFactorCounterOrVector16 =
            retainedFactorCounterOrVector16 + ((*((short*)argumentWord5)) * Family1182_D_8006FA78);
        rawWord2 = Family1182_unk_ovlheader_800743A4(
            ownerRecord20 + 0xC, argumentWord5,
            Family1182Field(Family1182Field(privateRecord19, short**, 0x10), short*, 2), 3);
        originalFrame.sp18 = rawWord2;
        rawWord3 = *Family1182Field(privateRecord19, short**, 8);
        signedRemainder =
            (int)((rawWord2 + rawWord3) - *Family1182Field(privateRecord19, int**, 0x50)) %
            rawWord3;
        originalFrame.sp18 = signedRemainder;
        if ((signedRemainder == 0) && (Family1182Field(privateRecord19, int*, 0x44) == 0)) {
            originalFrame.sp18 = (int)*Family1182Field(privateRecord19, short**, 8);
        }
        rawWord2 = Family1182Field(privateRecord19, int*, 8);
        rawWord3 = Family1182Field(rawWord2, short*, 0);
        rawWord2 = Family1182Field(privateRecord19, int*, 0x40);
        completeFinalProduct = (long long)(int)rawWord3 * (int)rawWord2;
        rawWord2 = originalFrame.sp18;
        __asm__("" : "=l"(finalProductLow) : "x"(completeFinalProduct), "r"(rawWord2));
        rawWord3 = rawWord2 + finalProductLow;
        originalFrame.sp18 = rawWord3;
        argumentWord4 = Family1182Field(privateRecord19, int*, 0x48);
        if (argumentWord4 == 1) {
            rawWord2 = rawWord3 + 1;
            goto family1182Adjusted;
        } else if (argumentWord4 == 2) {
            rawWord2 = rawWord3 - 1;
        family1182Adjusted:
            originalFrame.sp18 = rawWord2;
        }
        rawWord2 = originalFrame.sp18;
        rawWord2 = retainedFactorCounterOrVector16 < rawWord2;
        if (rawWord2) {
            rawWord2 = (int)&Family1182_D_8006FA7C;
            rawWord3 = Family1182Field(rawWord2, int*, 0);
            rawWord3++;
            Family1182Field(rawWord2, int*, 0) = rawWord3;
            rawWord2 = 1;
        } else
            rawWord2 = 2;
        Family1182Field(privateRecord19, int*, 0x48) = rawWord2;
    }
    return;
}
#undef Family1182Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level15
 * original8007CA54 complete256 instructions in sibling4534 and original
 * assembly. Verified spawn/count and vector/trigonometric C forms reused;
 * every branch, field, helper argument and constant follows original15.
 * Raw units/helper meanings/cadence unresolved; native/linked/full hashes
 * required. Original frame storage includes unresolved unused stack padding. */
#define A15F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int A15Mode __asm__("D_8006FA3C"), A15Count0 __asm__("D_8006C578"),
    A15Count1 __asm__("D_8006C574"), A15Tick __asm__("D_8006C644");
extern unsigned char A15Cos[] __asm__("D_80065920"), A15Sin[] __asm__("D_800658A0");
extern unsigned char A15Player98[] __asm__("D_80070328 + 0x98");
extern unsigned short A15CameraHeading __asm__("D_8006E040");
extern void* (*A15Spawn)() __asm__("SpawnMoby");
extern void* (*A15Fragments)() __asm__("SpawnFragments");
extern int (*A15Callback)() __asm__("unk_ovlheader_80074384");
int A15InterpolateMobyVertex() __asm__("func_80055F14");
int A15PlayMobySoundEvent() __asm__("func_8003BABC");
int A15H36A68() __asm__("func_80036A68");
int A15DeleteMoby() __asm__("func_80055B18");
int A15CopyVector() __asm__("func_8004F178");
int A15AddVector() __asm__("func_8004F194");
int A15ShiftVectorRightTowardZero() __asm__("func_8004F110");
int A15CountTimerDown() __asm__("func_800359A4");
int A15SubtractVector() __asm__("func_8004F1C8");
int A15MeasureVectorLength() __asm__("func_8004EDE8");
int A15ScaleVectorRatioQ15() __asm__("func_8004F08C");
void func_level_15_8007CA54(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* saved16 __asm__("$16");
    register unsigned char* saved18 __asm__("$18");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work5 __asm__("$5");
    register int work4 __asm__("$4");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    int vector[10];
    register int product8 __asm__("$8");
    MATCHING_KEEP(owner);
    work3 = owner[0x48];
    MATCHING_KEEP_CLOBBER(work3, "$5");
    if (work3 == 0)
        goto state0;
    if (work3 == 1)
        goto state1;
    return;
state0:
    work3 = owner[0x49];
    saved16 = A15F(owner, unsigned char**, 0);
    if (!work3)
        goto create;
    call4 = owner;
    if (work3 == 1)
        goto active;
    return;
create:
    work3 = A15Mode;
    MATCHING_KEEP(work3);
    if (work3 == 2)
        goto remove;
    MATCHING_BARRIER("$3");
    A15F(saved16, int*, 8) = 0;
spawnLoop:
    MATCHING_BARRIER_VOLATILE("memory");
    work2 = A15Count0;
    work3 = A15Count1;
    work2 -= work3;
    if (work2 < 21)
        goto spawned;
    A15Spawn(A15F(owner, short*, 0x36), owner);
    work2 = A15F(saved16, int*, 8) + 1;
    A15F(saved16, int*, 8) = work2;
    if (work2 < 12)
        goto spawnLoop;
spawned:
    owner[0x49] = 1;
    return;
active:
    call5 = 0;
    MATCHING_KEEP_CLOBBER(call5, "$18");
    saved18 = saved16 + 12;
    A15InterpolateMobyVertex(call4, call5, saved18);
    if (!A15F(owner, int*, 24))
        return;
    A15PlayMobySoundEvent(owner, 0, 0);
    A15H36A68(owner, 16, saved18, 0);
    A15Callback(owner);
    A15Fragments(3, 612, owner, A15F(saved16, int*, 4), 0, 0);
    goto remove;
state1:
    work2 = owner[0x49];
    saved18 = A15F(owner, unsigned char**, 0);
    if (!work2)
        goto initialize;
    call4 = saved18 + 16;
    if (work2 == work3)
        goto timer;
    return;
initialize:
    call5 = A15F(saved18, void**, 0);
    saved16 = saved18 + 4;
    if (!(A15F(call5, unsigned char*, 0x48) & 128)) {
        A15CopyVector(owner + 12, A15F(call5, unsigned char**, 0) + 12);
        return;
    }
    work2 = owner[0x46];
    work3 = owner[0x45];
    work2 <<= 1;
    work3 <<= 1;
    MATCHING_KEEP2(work2, work3);
    work4 = A15F(A15Cos + work2, short*, 0);
    work2 = A15F(A15Cos + work3, short*, 0);
    product8 = work4 * work2;
    MATCHING_KEEP(product8);
    work2 = product8;
    work2 >>= 12;
    A15F(saved18, int*, 4) = work2;
    work2 = owner[0x46];
    work3 = owner[0x45];
    work2 <<= 1;
    work3 <<= 1;
    MATCHING_KEEP2(work2, work3);
    work4 = A15F(A15Sin + work2, short*, 0);
    work2 = A15F(A15Cos + work3, short*, 0);
    product8 = work4 * work2;
    MATCHING_KEEP(product8);
    work2 = product8;
    call5 = saved16;
    work2 >>= 12;
    A15F(saved18, int*, 8) = work2;
    work2 = owner[0x45];
    call6 = A15Player98;
    work2 <<= 1;
    work2 = A15F(A15Sin + work2, short*, 0);
    call4 = saved16;
    work2 += 2048;
    A15F(saved18, int*, 12) = work2;
    A15AddVector(call4, saved16, call6);
    A15ShiftVectorRightTowardZero(saved16, 5);
    work2 = rand() & 31;
    work3 = 120 - work2;
    A15F(saved18, int*, 16) = work3;
    owner[0x49] = 1;
    __asm__ volatile("" ::: "memory", "$4");
    call4 = saved18 + 16;
timer:
    work2 = A15CountTimerDown(call4, 4);
    call4 = owner + 12;
    if (work2) {
    remove:
        A15DeleteMoby(owner);
        return;
    }
    call5 = call4;
    saved16 = saved18 + 4;
    A15AddVector(call4, call5, saved16);
    A15CopyVector(vector, A15Player98);
    A15ShiftVectorRightTowardZero(vector, 6);
    vector[2] = -24;
    A15SubtractVector(vector, vector, saved16);
    work5 = A15MeasureVectorLength(vector, 1);
    if (work5 >= 7)
        A15ScaleVectorRatioQ15(vector, work5, 6);
    A15AddVector(saved16, saved16, vector);
    work2 = A15CameraHeading;
    work3 = owner[0x46];
    work2 = (work2 << 16) >> 20;
    work5 = work2 + 64;
    work2 = work5 - work3;
    work5 = work2 & 255;
    if (work5 > 128)
        work5 -= 256;
    if (work5 < -4)
        work5 = -4;
    if (work5 > 4)
        work5 = 4;
    work2 = work3 + work5;
    owner[0x46] = work2;
    work2 = A15Tick;
    work2 = (work2 << 2) & 508;
    work2 = A15F(A15Cos + work2, unsigned short*, 0);
    work3 = owner[0x45];
    work2 = (work2 << 16) >> 24;
    work5 = work2 + 64;
    work2 = work5 - work3;
    work5 = work2 & 255;
    if (work5 > 128)
        work5 -= 256;
    if (work5 < -4)
        work5 = -4;
    if (work5 > 4)
        work5 = 4;
    work2 = work3 + work5;
    owner[0x45] = work2;
}
#undef A15F

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * asm/nonmatchings/overlays/level_15/moby/func_level_15_8007CE54.s
 * SHA256 2369fca12f248465d930d8749cea36bca15275a0c70d322ce5856b6e29b13b60.
 * 510 instructions and 8 original selector words. Original native/linked
 * words and full disc hashes are required; no semantic/runtime parity claim.
 * Raw units, helper contracts, producer chains and cadence remain unresolved. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))
struct _m2c_stack_func_level_15_8007CE54 {
    /* 0x00 */ char pad0[0x30];
}; /* size = 0x30 */

int SpeedwayController_func_8002803C() __asm__("func_8002803C"); /* extern */
int SpeedwayController_func_80028154() __asm__("func_80028154"); /* extern */
int SpeedwayControllerCountTimerDown() __asm__("func_800359A4"); /* extern */
int SpeedwayController_func_8003BB10() __asm__("func_8003BB10"); /* extern */
extern unsigned char SpeedwayController_D_80067262 __asm__("D_80067262");
extern unsigned char SpeedwayController_D_80067287 __asm__("D_80067287");
extern short SpeedwayController_D_8006728C __asm__("D_8006728C");
extern int SpeedwayController_D_8006C58C __asm__("D_8006C58C");
extern int SpeedwayController_D_8006C5BC __asm__("D_8006C5BC");
extern int SpeedwayController_D_8006C648 __asm__("D_8006C648");
extern unsigned char SpeedwayController_D_8006C7B4 __asm__("D_8006C7B4");
extern int SpeedwayController_D_8006C7C4 __asm__("D_8006C7C4");
extern int SpeedwayController_D_8006E344 __asm__("D_8006E344");
extern unsigned char SpeedwayController_D_8006FA3C __asm__("D_8006FA3C");
extern int SpeedwayController_D_8006FA58 __asm__("D_8006FA58");
extern int SpeedwayController_D_8006FA5C __asm__("D_8006FA5C");
extern int SpeedwayController_D_8006FA60 __asm__("D_8006FA60");
extern int SpeedwayController_D_8006FA64 __asm__("D_8006FA64");
extern unsigned char SpeedwayController_D_8006FA68 __asm__("D_8006FA68");
extern int SpeedwayController_D_8006FA6C __asm__("D_8006FA6C");
extern int SpeedwayController_D_8006FA70 __asm__("D_8006FA70");
extern int SpeedwayController_D_8006FA74 __asm__("D_8006FA74");
extern short SpeedwayController_D_8006FA84 __asm__("D_8006FA84");
extern short SpeedwayController_D_8006FA86 __asm__("D_8006FA86");
extern short SpeedwayController_D_8006FA88 __asm__("D_8006FA88");
extern unsigned char SpeedwayController_D_80070300 __asm__("D_80070300");
extern unsigned char SpeedwayController_D_80070328 __asm__("D_80070328");
extern unsigned char SpeedwayController_D_800716AC __asm__("D_800716AC");
extern short SpeedwayController_D_800719DE __asm__("D_800719DE");
extern unsigned char SpeedwayController_func_80027A60 __asm__("func_80027A60");
extern unsigned char SpeedwayController_func_80027D60 __asm__("func_80027D60");
extern unsigned char SpeedwayController_func_80027EE4 __asm__("func_80027EE4");
extern unsigned char SpeedwayController_func_8002982C __asm__("func_8002982C");
extern unsigned char SpeedwayController_func_80029AA0 __asm__("func_80029AA0");
extern unsigned char speedwayRecords;
extern unsigned char* SpeedwayController_unk_ovlheader_80074370 __asm__("unk_ovlheader_80074370");
extern unsigned char (*SpeedwayController_unk_ovlheader_80074374)() __asm__(
    "unk_ovlheader_80074374");
extern unsigned char* SpeedwayController_unk_ovlheader_80074388 __asm__("unk_ovlheader_80074388");
extern unsigned char* SpeedwayController_unk_ovlheader_8007438C __asm__("unk_ovlheader_8007438C");
extern unsigned char* SpeedwayController_unk_ovlheader_80074390 __asm__("unk_ovlheader_80074390");
extern unsigned char* SpeedwayController_unk_ovlheader_80074394 __asm__("unk_ovlheader_80074394");

void func_level_15_8007CE54(void* input_arg0) {
    register int* outgoing __asm__("$29");
    register void* arg0 __asm__("$18") = input_arg0;
    register int* temp_s0 __asm__("$16");
    int* var_v0;
    register int initial4 __asm__("$4"), initial3 __asm__("$3"), initial5 __asm__("$5");
    register int temp_a0 __asm__("$4");
    int temp_a0_2;
    register int temp_a0_3 __asm__("$4");
    int temp_a0_4;
    register int raw3 __asm__("$3"), work2 __asm__("$2"), remaining6 __asm__("$6");
    int newQuotient3;
    register int* time5 __asm__("$5");
    register int temp_s1 __asm__("$17");
    register int temp_v0 __asm__("$2");
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    register int temp_v1_2 __asm__("$3");
    int temp_v1_5;
    register int *counter3 __asm__("$3"), *counter4 __asm__("$4");
    register int var_a0 __asm__("$4");
    register int var_a1 __asm__("$5");
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int (*route2)() __asm__("$2");
    register int selected8 __asm__("$8"), arg7 __asm__("$7"), arg6 __asm__("$6");
    int var_v1;
    unsigned char temp_v1;
    unsigned char temp_v1_3;
    unsigned char temp_v1_4;

    temp_v1 = M2C_FIELD(arg0, unsigned char*, 0x48);
    temp_s0 = M2C_FIELD(arg0, int**, 0);
    switch (temp_v1) {
        case 0:
            var_v1 = 3;
            var_v0 = &SpeedwayController_D_8006FA64;
            do {
                *var_v0 = 0;
                var_v1 -= 1;
                var_v0 -= 1;
            } while (var_v1 >= 0);
            initial4 = 0x25F94;
            initial3 = 0x1D870;
            initial5 = 0x12600;
            MATCHING_KEEP3(initial4, initial3, initial5);
            M2C_FIELD(&SpeedwayController_D_8006FA68, int*, 0) = -1;
            SpeedwayController_D_8006FA6C = -1;
            SpeedwayController_D_8006FA84 = -1;
            SpeedwayController_D_8006FA88 = -1;
            SpeedwayController_D_8006FA86 = -1;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x254) = 5;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x260) = 0x2023;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x258) = initial4;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x25C) = initial3;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x264) = initial5;
            M2C_FIELD(arg0, unsigned char*, 0x48) = 1U;
            break;
        case 1:
            temp_s0 = (int*)&SpeedwayController_D_8006FA3C;
            MATCHING_KEEP(temp_s0);
            temp_s1 = M2C_FIELD(temp_s0, int*, 0);
            if (temp_s1 == 1) {
                SpeedwayController_D_8006FA84 = SpeedwayController_func_8002803C(
                    0x12, 3, 0, 0, SpeedwayController_unk_ovlheader_80074370,
                    (unsigned char*)temp_s0 + 0x34, 0x8CA0);
                temp_v0 = SpeedwayController_func_8002803C(
                    0x17, SpeedwayController_D_8006C5BC * 0xA,
                    SpeedwayController_unk_ovlheader_80074390, 0,
                    SpeedwayController_unk_ovlheader_8007438C, (unsigned char*)temp_s0 + 0x54, 0);
                raw3 = M2C_FIELD(temp_s0, int*, -4);
                SpeedwayController_D_8006FA88 = temp_v0;
                MATCHING_KEEP(raw3);
                work2 = raw3 * 3;
                work2 *= 4;
                work2 -= raw3;
                temp_v1_2 = work2 * 4;
                if (M2C_FIELD(&speedwayRecords, int*, 0x10 + temp_v1_2) != 0) {
                    M2C_FIELD(temp_s0, int*, 0x34) = 0;
                    M2C_FIELD(temp_s0, int*, 0x38) = 0;
                    M2C_FIELD(arg0, unsigned char*, 0x48) = 3U;
                } else {
                    temp_v0 = M2C_FIELD(&speedwayRecords, int*, 0x18 + temp_v1_2);
                    raw3 = SpeedwayController_D_8006C7C4;
                    M2C_FIELD(temp_s0, int*, 0x34) = temp_v0;
                    if (raw3 == temp_s1) {
                        var_v0_2 = temp_v0 + 0x12C;
                        goto block_11;
                    }
                    var_v0_2 = temp_v0 + 0x258;
                    if (raw3 == 0) {
                    block_11:
                        M2C_FIELD(temp_s0, int*, 0x34) = var_v0_2;
                    }
                    SpeedwayController_D_8006FA74 = 0;
                    M2C_FIELD(arg0, unsigned char*, 0x48) = 2U;
                    raw3 = SpeedwayController_D_8006C58C;
                    MATCHING_KEEP(raw3);
                    work2 = raw3 * 3;
                    MATCHING_KEEP(work2);
                    temp_a0 = work2 * 2;
                    temp_v1_3 = *(&SpeedwayController_D_800716AC + temp_a0);
                    if (temp_v1_3 < 0xFFU) {
                        *(&SpeedwayController_D_800716AC + temp_a0) = temp_v1_3 + 1;
                    }
                }
            } else if (temp_s1 == 2) {
                SpeedwayController_D_8006FA84 = SpeedwayController_func_8002803C(
                    0x12, 3, 0, 0, SpeedwayController_unk_ovlheader_80074370,
                    (unsigned char*)temp_s0 + 0x34, 0x8CA0);
                SpeedwayController_D_8006FA86 = SpeedwayController_func_8002803C(
                    0x15, 0x7D0, &SpeedwayController_func_80027EE4,
                    &SpeedwayController_func_80027A60, &SpeedwayController_func_80029AA0,
                    (unsigned char*)temp_s0 + 0x3C, 3);
                SpeedwayController_D_8006FA88 = SpeedwayController_func_8002803C(
                    0x17, 0x7D1, &SpeedwayController_func_80027D60,
                    SpeedwayController_unk_ovlheader_80074394, &SpeedwayController_func_8002982C,
                    (unsigned char*)temp_s0 + 0x40, 5);
                M2C_FIELD(temp_s0, int*, 0x34) = 0;
                SpeedwayController_D_8006FA74 = 0xB4;
                M2C_FIELD(temp_s0, int*, 0x3C) = 0;
                M2C_FIELD(temp_s0, int*, 0x40) = 0;
                M2C_FIELD(arg0, unsigned char*, 0x48) = 5U;
                if (!(SpeedwayController_D_8006C7B4 & 2) &&
                    !(*(&SpeedwayController_D_80070300 + SpeedwayController_D_8006C58C) & 2)) {
                    temp_a0_2 = SpeedwayController_D_8006C58C * 6;
                    temp_v1_4 = *(&SpeedwayController_D_800716AC + 1 + temp_a0_2);
                    if (temp_v1_4 < 0xFFU) {
                        *(&SpeedwayController_D_800716AC + 1 + temp_a0_2) = temp_v1_4 + 1;
                    }
                }
            }
            break;
        case 2:
            if ((SpeedwayController_D_8006E344 == 0) &&
                (M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x50) != 8) &&
                (M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x1CC) == 0)) {
                time5 = &SpeedwayController_D_8006FA70;
                MATCHING_OBSERVE(time5);
                temp_a0_3 = *(volatile int*)time5;
                work2 = SpeedwayController_D_8006C648;
                raw3 = SpeedwayController_D_8006FA74;
                remaining6 = temp_a0_3 - work2;
                raw3 += work2;
                *time5 = remaining6;
                SpeedwayController_D_8006FA74 = raw3;
                temp_a0_3 /= 60;
                if (raw3 > 0x8C9F)
                    SpeedwayController_D_8006FA74 = 0x8C9F;
                newQuotient3 = remaining6 / 60;
                __asm__("" : "=r"(newQuotient3) : "0"(newQuotient3), "r"(remaining6));
                if (temp_a0_3 < 11 && temp_a0_3 != newQuotient3)
                    SpeedwayController_func_8003BB10(0, 1, 1);
                counter3 = &SpeedwayController_D_8006FA70;
                MATCHING_KEEP(counter3);
                work2 = *counter3;
                if (work2 <= 0) {
                    route2 = (void*)SpeedwayController_unk_ovlheader_80074374;
                    MATCHING_KEEP(route2);
                    *counter3 = 0;
                    route2();
                }
                raw3 = SpeedwayController_D_8006FA58;
                work2 = 8;
                if (raw3 == work2)
                    goto equalCounts;
                goto controllerFooter;
            }
            break;
        case 3:
            if (SpeedwayController_D_8006E344 != 0)
                goto controllerFooter;
            if (M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x50) == 8)
                goto controllerFooter;
            counter4 = &SpeedwayController_D_8006FA74;
            MATCHING_KEEP(counter4);
            temp_v0_2 = *counter4 + SpeedwayController_D_8006C648;
            *counter4 = temp_v0_2;
            if (temp_v0_2 > 0x8C9F)
                *counter4 = 0x8C9F;
            SpeedwayController_D_8006FA70 = *counter4;
            raw3 = SpeedwayController_D_8006FA58;
            if (raw3 != 8)
                goto controllerFooter;
        equalCounts:
            work2 = SpeedwayController_D_8006FA5C;
            if (work2 != raw3)
                goto controllerFooter;
            raw3 = SpeedwayController_D_8006FA60;
            if (raw3 != work2)
                goto controllerFooter;
            work2 = SpeedwayController_D_8006FA64;
            if (work2 != raw3)
                goto controllerFooter;
            *temp_s0 = 120;
            M2C_FIELD(arg0, unsigned char*, 72) = 4;
            break;
        case 4:
            if ((SpeedwayControllerCountTimerDown(temp_s0, 4) != 0) &&
                (SpeedwayController_D_800719DE == 0)) {
                SpeedwayController_func_8003BB10(0, 0, 1);
                SpeedwayController_D_8006C7B4 |= 1;
                SpeedwayController_unk_ovlheader_80074374();
            }
            break;
        case 5:
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x20C) = 0x10000002;
            if (SpeedwayControllerCountTimerDown(&SpeedwayController_D_8006FA74, 4) != 0) {
                M2C_FIELD(arg0, unsigned char*, 0x48) = 6U;
            }
            break;
        case 6:
            if ((SpeedwayController_D_8006E344 == 0) &&
                (M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x50) != 8)) {
                counter4 = &SpeedwayController_D_8006FA74;
                MATCHING_KEEP(counter4);
                temp_v0_3 = *counter4 + SpeedwayController_D_8006C648;
                *counter4 = temp_v0_3;
                if (temp_v0_3 > 0x8C9F) {
                    *counter4 = 0x8C9F;
                }
                SpeedwayController_D_8006FA70 = *counter4;
            }
            break;
    }
controllerFooter:
    time5 = (int*)&SpeedwayController_D_8006FA3C;
    MATCHING_KEEP(time5);
    raw3 = *time5;
    work2 = 1;
    if (raw3 != work2)
        goto footerDone;
    work2 = SpeedwayController_D_8006FA6C;
    if (work2 < 0) {
        work2 = SpeedwayController_D_8006FA86;
        var_a0 = 0;
        if (work2 >= 0) {
            temp_s0 = (int*)((unsigned char*)time5 + 0x4A);
            raw3 = M2C_FIELD(time5, short*, 0x4A);
            MATCHING_KEEP2(temp_s0, raw3);
            var_a1 = 0;
            do {
                work2 = M2C_FIELD(&SpeedwayController_D_80067262, short*, var_a1);
                if (work2 == raw3) {
                    work2 = var_a0 * 4;
                    goto recordFound;
                }
                var_a0++;
                work2 = var_a0 < 8;
                var_a1 += 0x54;
            } while (work2);
            work2 = var_a0 * 4;
        recordFound:
            work2 += var_a0;
            work2 *= 4;
            work2 += var_a0;
            work2 *= 4;
            raw3 = 50;
            M2C_FIELD(&SpeedwayController_D_80067287, unsigned char*, work2) = raw3;
            M2C_FIELD(&SpeedwayController_D_8006728C, short*, work2) = 0;
            var_a0 = M2C_FIELD(temp_s0, short*, 0);
            M2C_FIELD(temp_s0, short*, 4) = 0;
            SpeedwayController_func_80028154(var_a0, var_a1);
            work2 = -1;
            M2C_FIELD(temp_s0, short*, 0) = work2;
        }
    }
    temp_s0 = (int*)&SpeedwayController_D_8006FA68;
    MATCHING_KEEP(temp_s0);
    selected8 = *temp_s0;
    if (selected8 < 0)
        goto footerDone;
    work2 = temp_s0[1];
    if (selected8 == work2)
        goto footerDone;
    var_a0 = 21;
    if (work2 >= 0) {
        work2 = SpeedwayController_D_8006FA6C;
        work2 <<= 2;
        work2 = (int)temp_s0 + work2;
        work2 = M2C_FIELD((void*)work2, int*, -16);
        work2 = work2 < 8;
        if (!work2)
            goto footerDone;
    }
    arg6 = 0;
    arg7 = 0;
    MATCHING_KEEP3(var_a0, arg6, arg7);
    /* Original words 482..498 explicitly stage arguments 5..7 in the
     * outgoing frame at SP+10, SP+14 and SP+18. This is the original
     * seven-argument ABI, written explicitly for compiler comparison.
     * Helper contracts, units and semantic meaning remain unresolved. */
    __asm__("" : "=r"(outgoing));
    raw3 = SpeedwayController_D_8006C5BC;
    work2 = 8;
    outgoing[6] = work2;
    work2 = M2C_FIELD(temp_s0, volatile int*, 0);
    var_a1 = raw3 * 10 + selected8;
    raw3 = (int)SpeedwayController_unk_ovlheader_80074388;
    work2 *= 4;
    outgoing[4] = raw3;
    raw3 = (int)temp_s0 - 16;
    work2 += raw3;
    outgoing[5] = work2;
    temp_v0 = SpeedwayController_func_8002803C(var_a0, var_a1, arg6, arg7);
    raw3 = *temp_s0;
    SpeedwayController_D_8006FA86 = temp_v0;
    temp_s0[1] = raw3;
footerDone:;
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Reuses verified func_level_10_800821F8
 * with this overlay's original fragment selector. Raw field units, helper
 * meanings and update cadence remain unverified. See batch 3771 provenance. */
extern unsigned char Controller821F8AngleTable[] __asm__("D_80065398");
extern unsigned char Controller821F8InitialTable[] __asm__("D_80066BDC");
#define Controller821F8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller821F8CDLoadTime(void) __asm__("CDLoadTime");
int Controller821F8func_8002803C(int, int, void*, int, void*, int, int) __asm__("func_8002803C");
int Controller821F8func_80028154(int) __asm__("func_80028154");
int Controller821F8func_8002AF9C(void*, int, int) __asm__("func_8002AF9C");
int Controller821F8RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller821F8CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller821F8SubAngle8(int, int) __asm__("func_8003613C");
int Controller821F8func_80039974(int, int, int) __asm__("func_80039974");
int Controller821F8PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller821F8func_8003BE70(int) __asm__("func_8003BE70");
int Controller821F8func_8003BFC0(void*, int) __asm__("func_8003BFC0");
int Controller821F8func_8003C140(int, int) __asm__("func_8003C140");
int Controller821F8func_800492DC(void*, int) __asm__("func_800492DC");
int Controller821F8PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller821F8CopyVector(void*, void*) __asm__("func_8004F178");
int Controller821F8AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller821F8ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller821F8func_800527C4(void*, int) __asm__("func_800527C4");
int Controller821F8DeleteMoby(void*) __asm__("func_80055B18");
int Controller821F8RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller821F8InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern unsigned char Controller821F8D_80065398[] __asm__("D_80065398");
extern unsigned char Controller821F8D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller821F8D_80065920[] __asm__("D_80065920");
extern unsigned char Controller821F8D_80066BDC[] __asm__("D_80066BDC");
extern unsigned char Controller821F8D_80066BDD[] __asm__("D_80066BDD");
extern unsigned char Controller821F8D_80066BDE[] __asm__("D_80066BDE");
extern unsigned char Controller821F8D_80070300[] __asm__("D_80070300");
extern unsigned char Controller821F8D_80070328[] __asm__("D_80070328");
extern unsigned char Controller821F8D_800715BC[] __asm__("D_800715BC");
extern unsigned char Controller821F8D_800716AC[] __asm__("D_800716AC");
extern unsigned char Controller821F8func_80027F88[] __asm__("func_80027F88");
extern unsigned char Controller821F8func_80029CF8[] __asm__("func_80029CF8");
extern int Controller821F8D_8006C3EC __asm__("D_8006C3EC");
extern int Controller821F8D_8006C58C __asm__("D_8006C58C");
extern int Controller821F8D_8006C5C8 __asm__("D_8006C5C8");
extern int Controller821F8D_8006C5F4 __asm__("D_8006C5F4");
extern unsigned char Controller821F8D_8006C62C __asm__("D_8006C62C");
extern int Controller821F8D_8006C648 __asm__("D_8006C648");
extern int Controller821F8D_8006C660 __asm__("D_8006C660");
extern unsigned int Controller821F8D_8006C704 __asm__("D_8006C704");
extern int Controller821F8D_8006C770 __asm__("D_8006C770");
extern int Controller821F8D_8006C7A0 __asm__("D_8006C7A0");
extern int Controller821F8D_8006C7A8 __asm__("D_8006C7A8");
extern unsigned char Controller821F8D_8006C7B4 __asm__("D_8006C7B4");
extern int Controller821F8D_8006C7D0 __asm__("D_8006C7D0");
extern int Controller821F8D_8006E48C __asm__("D_8006E48C");
extern int Controller821F8D_8006E49C __asm__("D_8006E49C");
extern int Controller821F8D_8006E53C __asm__("D_8006E53C");
extern unsigned int* Controller821F8D_8006C5B0 __asm__("D_8006C5B0");
extern void* (*Controller821F8SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int (*Controller821F8SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
extern int (*Controller821F8SpawnFragments)(int, int, void*, void*, int,
                                            int) __asm__("SpawnFragments");
void func_level_15_8007D64C(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    struct {
        int vector[4];
        short rect[4];
    } frame;
    short temp_a0_2;
    register int temp_a1_2 __asm__("$5");
    short temp_v0_2;
    register int temp_v0_3 __asm__("$2");
    short temp_v0_7;
    short temp_v0_8;
    short temp_v1_2;
    register int var_a0 __asm__("$4");
    int temp_a0_5;
    register int temp_t0 __asm__("$8");
    register int temp_v0 __asm__("$2");
    int temp_v0_10;
    int nextTableIndex;
    register int temp_v1_15 __asm__("$3");
    int temp_v1_6;
    register int var_a1 __asm__("$5");
    register int var_a2 __asm__("$6");
    register int var_a3 __asm__("$7");
    register int distance __asm__("$19");
    register int scanEnabled __asm__("$2");
    register int heightOffset __asm__("$2");
    register void* finishOwner __asm__("$4");
    register int verticalDistance __asm__("$20");
    register int sharedTailEnabled __asm__("$21");
    int var_v0;
    register int var_v0_3 __asm__("$2");
    int var_v1;
    int var_v1_2;
    int var_v1_3;
    register int var_v1_4 __asm__("$3");
    register int var_a2_2 __asm__("$6");
    unsigned short temp_v1_3;
    unsigned char* temp_v1_4;
    register int temp_a0_12 __asm__("$4");
    register int temp_a0_3 __asm__("$4");
    unsigned char temp_a1;
    register int temp_v1 __asm__("$3");
    unsigned char temp_v1_11;
    unsigned char temp_v1_13;
    unsigned char temp_v1_5;
    unsigned char temp_v1_7;
    unsigned char temp_v1_9;
    register int var_a0_2 __asm__("$4");
    register int var_v0_2 __asm__("$2");
    register void* temp_a0 __asm__("$4");
    void* temp_a0_10;
    void* temp_a0_11;
    void* temp_a0_4;
    void* temp_a0_6;
    void* temp_a0_7;
    void* temp_a0_8;
    void* temp_a0_9;
    register unsigned char* tag __asm__("$16");
    void* childForAngle;
    void* spawnedChild;
    void* spawnedRecord;
    void* temp_v1_10;
    void* temp_v1_12;
    void* temp_v1_14;
    void* temp_v1_8;

    tag = Controller821F8Field(owner, void**, 0);
    distance = Controller821F8ApproximatePlanarDistance(owner + 0xC, Controller821F8D_80070328);
    {
        register int heightOffset __asm__("$3") = Controller821F8Field(owner, short*, 0x38);
        temp_v0 = Controller821F8Field(owner, int*, 20);
        MATCHING_KEEP2(heightOffset, temp_v0);
        temp_v0 -= heightOffset;
        MATCHING_KEEP_CLOBBER(temp_v0, "$3");
        heightOffset = Controller821F8Field(Controller821F8D_80070328, int*, 8);
        {
            register int base __asm__("$4") =
                Controller821F8Field(Controller821F8D_80070328, int*, 0x44);
            MATCHING_KEEP2(heightOffset, base);
            temp_v0 -= heightOffset;
            temp_v0 += base;
        }
    }
    temp_a0 = Controller821F8Field(tag, void**, 8);
    verticalDistance = temp_v0;
    if (temp_v0 < 0) {
        verticalDistance = -verticalDistance;
    }
    sharedTailEnabled = 0;
    if (temp_a0 != 0) {
        Controller821F8InterpolateMobyVertex(temp_a0, 0, &frame.vector);
    }
    MATCHING_KEEP_VOLATILE(sharedTailEnabled);
    temp_v1 = Controller821F8Field(owner, unsigned char*, 0x48);
    switch (temp_v1) { /* switch 1 */
        case 0:        /* switch 1 */
            if (Controller821F8Field(tag, short*, 6) < 0) {
                Controller821F8Field(tag, short*, 6) =
                    (short)Controller821F8Field(owner, unsigned char*, 0x46);
            }
            temp_v1_2 = Controller821F8Field(tag, short*, 0);
            if (temp_v1_2 >= 0) {
                if ((((int)Controller821F8D_8006C7B4 >> temp_v1_2) & 1) ||
                    (((int)*(Controller821F8D_80070300 + Controller821F8D_8006C58C) >> temp_v1_2) &
                     1)) {
                    Controller821F8DeleteMoby(owner);
                } else if (Controller821F8ApproximatePlanarDistance(
                               owner + 0xC, Controller821F8D_80070328) < 0x2000) {
                    var_v0 = ((Controller821F8Field(owner, int*, 0x14) -
                               Controller821F8Field(owner, short*, 0x38)) -
                              Controller821F8Field(Controller821F8D_80070328, int*, 8)) +
                             Controller821F8Field(Controller821F8D_80070328, int*, 0x44);
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    if ((var_v0 < 0x800) &&
                        ((Controller821F8AbsoluteByteAngleDelta(
                              Controller821F8Field(owner, unsigned char*, 0x46),
                              Controller821F8PlanarHeadingLookup(
                                  Controller821F8Field(Controller821F8D_80070328, int*, 0) -
                                      Controller821F8Field(owner, int*, 0xC),
                                  Controller821F8Field(Controller821F8D_80070328, int*, 4) -
                                      Controller821F8Field(owner, int*, 0x10),
                                  0)) < 0x20) ||
                         (Controller821F8Field(tag, short*, 0x16) != 0))) {
                        Controller821F8Field(owner, unsigned char*, 0x48) = 7U;
                        Controller821F8Field(tag, unsigned short*, 0xC) = 0U;
                    }
                }
            }
        default: /* switch 1 */
            goto sharedTail;
        case 7: /* switch 1 */
            if ((distance >= 0x2401) || (verticalDistance >= 0x901)) {
                Controller821F8Field(owner, unsigned char*, 0x48) = 0U;
            } else if ((distance < 0x800) && (verticalDistance < 0x200) &&
                       ((Controller821F8Field(Controller821F8D_80070328, int*, 0xB8) == 0) ||
                        ((unsigned int)(Controller821F8Field(Controller821F8D_80070328, int*,
                                                             0x50) -
                                        0xB) < 2U)) &&
                       ((Controller821F8AbsoluteByteAngleDelta(
                             Controller821F8Field(owner, unsigned char*, 0x46),
                             Controller821F8PlanarHeadingLookup(
                                 Controller821F8Field(Controller821F8D_80070328, int*, 0) -
                                     Controller821F8Field(owner, int*, 0xC),
                                 Controller821F8Field(Controller821F8D_80070328, int*, 4) -
                                     Controller821F8Field(owner, int*, 0x10),
                                 0)) < 0x20) ||
                        (Controller821F8Field(tag, short*, 0x16) != 0))) {
                Controller821F8Field(owner, unsigned char*, 0x48) = 1U;
            }
            goto sharedTail;
        case 1: /* switch 1 */
            Controller821F8func_800527C4(owner, Controller821F8Field(tag, short*, 0));
            /* fallthrough */
        case 2: /* switch 1 */
            if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short*, 0x14)) == 0) {
                temp_v0_2 = Controller821F8PlayMobySoundEvent(owner, 0, 4);
                Controller821F8Field(tag, short*, 0x14) = temp_v0_2;
                if (temp_v0_2 >= 0) {
                    Controller821F8func_8003C140(temp_v0_2, 1);
                }
            }
            temp_a0_2 = Controller821F8Field(tag, short*, 0);
            temp_v1_4 = Controller821F8D_8006C58C + Controller821F8D_80070300;
            temp_a1 = *temp_v1_4;
            if (!(((int)temp_a1 >> temp_a0_2) & 1)) {
                *temp_v1_4 = temp_a1 | (1 << temp_a0_2);
                Controller821F8D_8006C660 += 1;
            } else {
                Controller821F8D_8006C7D0 = 1;
            }
            var_a1 = 0x10000002;
            {
                register int flags __asm__("$2") =
                    Controller821F8Field(Controller821F8D_80070328, int*, 0x20C);
                MATCHING_KEEP2(flags, var_a1);
                Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) = flags | var_a1;
            }
            Controller821F8func_800492DC(owner + 0xC, var_a1);
            Controller821F8Field(tag, short*, 2) = 0xB4;
            Controller821F8D_8006C3EC = 0;
            Controller821F8Field(owner, unsigned char*, 0x48) = 3U;
            if (Controller821F8Field(
                    ((Controller821F8Field(tag, short*, 0) * 0xC) + Controller821F8D_8006C7A0),
                    unsigned char*, 7) == 0xFF) {
                Controller821F8Field(tag, short*, 4) = -1;
                Controller821F8Field(owner, unsigned char*, 0x49) = 4U;
            } else {
                Controller821F8Field(tag, short*, 4) = Controller821F8func_8002803C(
                    0x36, -1, Controller821F8func_80027F88, 0, Controller821F8func_80029CF8,
                    *(int*)((Controller821F8Field(tag, short*, 0) * 0xC) +
                            Controller821F8D_8006C7A0),
                    0);
                Controller821F8D_8006E49C = 1;
                Controller821F8Field(owner, unsigned char*, 0x49) = 0U;
            }
            goto sharedTail;
        case 3: /* switch 1 */
            if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short*, 0x14)) == 0) {
                temp_v0_3 = Controller821F8PlayMobySoundEvent(owner, 0, 4);
                Controller821F8Field(tag, short*, 0x14) = temp_v0_3;
                var_a0 = (temp_v0_3 << 16) >> 16;
                if (var_a0 >= 0) {
                    var_a1 = Controller821F8D_8006C3EC << 0xC;
                    goto updateOwnerHeight;
                }
            } else {
                var_a1 = Controller821F8D_8006C3EC;
                {
                    register int condition __asm__("$2") = var_a1 < 65;
                    MATCHING_KEEP(condition);
                    var_a1 <<= 12;
                    if (condition) {
                        var_a0 = Controller821F8Field(tag, short*, 0x14);
                    updateOwnerHeight:
                        Controller821F8func_8003C140(var_a0, (var_a1 >> 6) | 1);
                    }
                }
            }
            {
                register int selector __asm__("$4") = 1;
                register int kind __asm__("$5") = 12;
                register void* particleOwner __asm__("$6") = owner;
                register int mode __asm__("$7") = 5;
                register int height __asm__("$2");
                register int alpha __asm__("$3");
                register int (*particle)(int, int, void*, int) __asm__("$8");
                __asm__(""
                        : "=r"(selector), "=r"(kind), "=r"(particleOwner), "=r"(mode)
                        : "0"(selector), "1"(kind), "2"(particleOwner), "3"(mode)
                        : "$2", "$3", "$8");
                height = Controller821F8Field(owner, int*, 20);
                alpha = Controller821F8Field(owner, unsigned char*, 79);
                MATCHING_KEEP2_CLOBBER(height, alpha, "$8");
                particle = Controller821F8SpawnParticle;
                MATCHING_KEEP2(particle, height);
                height += 128;
                height -= alpha;
                Controller821F8Field(owner, int*, 20) = height;
                particle(selector, kind, particleOwner, mode);
                height = Controller821F8Field(owner, int*, 20);
                alpha = Controller821F8Field(owner, unsigned char*, 79);
                __asm__ volatile(""
                                 : "=r"(height), "=r"(alpha)
                                 : "0"(height), "1"(alpha)
                                 : "$4", "memory");
                temp_a0_3 = Controller821F8Field(owner, unsigned char*, 79);
                MATCHING_KEEP3(temp_a0_3, height, alpha);
                height -= 128;
                height += alpha;
                Controller821F8Field(owner, int*, 20) = height;
            }
            if ((temp_a0_3 != 0) &&
                ((unsigned int)owner >= (unsigned int)Controller821F8D_8006C704)) {
                Controller821F8Field(owner, unsigned char*, 0x4F) = (unsigned char)*(
                    int*)(Controller821F8D_80065398 + 0xA4 + (Controller821F8D_8006C3EC * 0xC));
            }
            Controller821F8Field(owner, unsigned char*, 0x44) = (unsigned char)*(
                int*)(Controller821F8AngleTable + 0x9C + (Controller821F8D_8006C3EC * 0xC));
            Controller821F8Field(owner, unsigned char*, 0x45) = (unsigned char)*(
                int*)(Controller821F8D_80065398 + 0xA0 + (Controller821F8D_8006C3EC * 0xC));
            nextTableIndex = Controller821F8D_8006C3EC + 1;
            Controller821F8D_8006C3EC = nextTableIndex;
            if (nextTableIndex >= 0x40) {
                Controller821F8D_8006C3EC = 0x2F;
            }
            temp_v1_5 = Controller821F8Field(owner, unsigned char*, 0x49);
            switch (temp_v1_5) {
                case 0:
                    if (Controller821F8D_8006E48C != 0)
                        goto loadingDone;
                    if (Controller821F8CDLoadTime() != 0)
                        goto loadingBusy;
                    var_a1 = 0;
                    MATCHING_KEEP_CLOBBER(var_a1, "$4");
                    var_a0 = Controller821F8Field(tag, short*, 0);
                    Controller821F8func_80039974(var_a0, var_a1, 0x3000);
                    var_v0_2 = 1;
                    goto storeLoadingState;
                case 1:
                    if (Controller821F8CDLoadTime() != 0)
                        goto loadingBusy;
                    DrawSync(0);
                    frame.rect[0] = 0x380;
                    frame.rect[1] = 0x100;
                    frame.rect[2] = 0x40;
                    frame.rect[3] = 0x60;
                    LoadImage((RECT*)&frame.rect[0], Controller821F8D_8006C5B0);
                    var_v0_2 = 2;
                    goto storeLoadingState;
                case 2:
                    if (Controller821F8CDLoadTime() != 0)
                        goto loadingBusy;
                    var_a1 = 0x3000;
                    MATCHING_KEEP_CLOBBER(var_a1, "$4");
                    var_a0 = Controller821F8Field(tag, short*, 0);
                    Controller821F8func_80039974(var_a0, var_a1, 0);
                    var_v0_2 = 3;
                    goto storeLoadingState;
                case 3:
                    if (Controller821F8CDLoadTime() != 0)
                        goto loadingBusy;
                    var_a1 = 500;
                    MATCHING_KEEP_CLOBBER(var_a1, "$4");
                    Controller821F8func_8002AF9C(Controller821F8D_8006C5B0, var_a1, 0x80400000);
                    var_v0_2 = 4;
                storeLoadingState:
                    Controller821F8Field(owner, unsigned char*, 73) = var_v0_2;
                loadingBusy:
                default:
                loadingDone:
                    break;
            }
            var_a1 = 0x10000002;
            {
                register int flags __asm__("$2") =
                    Controller821F8Field(Controller821F8D_80070328, int*, 0x20C);
                MATCHING_KEEP2(flags, var_a1);
                Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) = flags | var_a1;
            }
            Controller821F8func_800492DC(owner + 0xC, var_a1);
            if ((Controller821F8CountTimerDown(tag + 2, 2) != 0) &&
                (Controller821F8Field(owner, unsigned char*, 0x49) == 4)) {
                if (Controller821F8Field(
                        ((Controller821F8Field(tag, short*, 0) * 0xC) + Controller821F8D_8006C7A0),
                        unsigned char*, 7) == 0xFF) {
                    Controller821F8Field(tag, void**, 8) = 0;
                } else {
                    Controller821F8Field(tag, void**, 8) = Controller821F8SpawnMoby(0x1F4, owner);
                }
                if (Controller821F8Field(tag, void**, 8) != 0) {
                    if (Controller821F8Field(tag, short*, 0) == 1) {
                        Controller821F8SpawnFragments(5, 0x1F5, owner, Controller821F8D_80065398, 8,
                                                      0x100);
                    } else {
                        Controller821F8SpawnFragments(0xD, 0x1F5, owner, Controller821F8D_80065398,
                                                      0, 0x100);
                    }
                    childForAngle = Controller821F8Field(tag, void**, 8);
                    Controller821F8Field(Controller821F8Field(tag, void**, 8), signed char*, 0x46) =
                        Controller821F8PlanarHeadingLookup(
                            Controller821F8Field(Controller821F8D_80070328, int*, 0) -
                                Controller821F8Field(childForAngle, int*, 0xC),
                            Controller821F8Field(Controller821F8D_80070328, int*, 4) -
                                Controller821F8Field(childForAngle, int*, 0x10),
                            0);
                    Controller821F8D_8006E49C = 0;
                    Controller821F8Field(owner, unsigned char*, 0x48) = 4U;
                    Controller821F8D_8006C3EC = 0;
                    Controller821F8Field(owner, signed char*, 0x4C) = 0;
                    Controller821F8Field(owner, signed char*, 0x4D) = 0;
                    Controller821F8RefreshMobySpatialGridAndBasis(
                        Controller821F8Field(tag, void**, 8), 4);
                    if (Controller821F8func_8003BFC0(
                            owner, Controller821F8Field(tag, short*, 0x14)) != 0) {
                        Controller821F8func_8003BE70(Controller821F8Field(tag, short*, 0x14));
                    }
                    Controller821F8Field(tag, short*, 0x14) = -1;
                    Controller821F8PlayMobySoundEvent(owner, 1, 4);
                } else {
                    goto enterStateFive;
                }
            }
            goto sharedTail;
        case 4: /* switch 1 */
            var_a1 = 0x10000002;
            {
                register int flags __asm__("$2") =
                    Controller821F8Field(Controller821F8D_80070328, int*, 0x20C);
                MATCHING_KEEP2(flags, var_a1);
                Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) = flags | var_a1;
            }
            Controller821F8func_800492DC(&frame.vector, var_a1);
            if (({
                    register unsigned char* child __asm__("$2") =
                        Controller821F8Field(tag, void**, 8);
                    MATCHING_KEEP_CLOBBER(child, "$4");
                    Controller821F8Field(child, unsigned char*, 66) & 2;
                }) ||
                (Controller821F8D_8006E53C & 0x800)) {
                temp_a0_4 = Controller821F8Field(tag, void**, 8);
                Controller821F8Field(tag, short*, 2) = -0x200;
                if (Controller821F8Field(temp_a0_4, unsigned char*, 0x42) & 2) {
                    Controller821F8RequestMobyAnimation(temp_a0_4, 1);
                }
                Controller821F8CopyVector(owner + 0xC, &frame.vector);
                heightOffset = Controller821F8Field(tag, short*, 2);
                MATCHING_KEEP_CLOBBER(heightOffset, "$3");
                {
                    register unsigned char* child __asm__("$3") =
                        Controller821F8Field(tag, void**, 8);
                    MATCHING_KEEP2_CLOBBER(child, heightOffset, "$4");
                    temp_a0_5 = Controller821F8Field(owner, int*, 20);
                    temp_v1_6 = Controller821F8Field(child, int*, 20);
                }
                if ((temp_a0_5 + heightOffset) < temp_v1_6) {
                    Controller821F8Field(tag, short*, 2) = (short)(temp_v1_6 - temp_a0_5);
                }
                spawnedChild = Controller821F8SpawnMoby(0x171, owner);
                Controller821F8Field(tag, void**, 0x10) = spawnedChild;
                if (spawnedChild != 0) {
                    Controller821F8Field(spawnedChild, int*, 0x14) =
                        (int)(Controller821F8Field(spawnedChild, int*, 0x14) +
                              Controller821F8Field(tag, short*, 2));
                    Controller821F8Field(Controller821F8Field(tag, void**, 0x10), unsigned char*,
                                         0x4F) = 0xFFU;
                }
                Controller821F8PlayMobySoundEvent(owner, 2, 0);
                Controller821F8Field(owner, unsigned char*, 0x48) = 8U;
            }
            goto sharedTail;
        case 9: /* switch 1 */
            if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short*, 0x14)) != 0) {
                Controller821F8func_8003BE70(Controller821F8Field(tag, short*, 0x14));
            }
            Controller821F8Field(tag, short*, 0x14) = -1;
            var_a1 = 0x10000002;
            {
                register int flags __asm__("$2") =
                    Controller821F8Field(Controller821F8D_80070328, int*, 0x20C);
                MATCHING_KEEP2(flags, var_a1);
                Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) = flags | var_a1;
            }
            Controller821F8func_800492DC(owner + 0xC, var_a1);
            Controller821F8Field(owner, int*, 0x54) =
                (int)(((Controller821F8Field(owner, int*, 0x14) +
                        Controller821F8Field(tag, short*, 2)) &
                       0xFFFFFF) |
                      0x80000000);
            temp_a0_6 = Controller821F8Field(tag, void**, 0x10);
            if (temp_a0_6 != 0) {
                Controller821F8Field(temp_a0_6, int*, 0x14) =
                    (int)(Controller821F8Field(owner, int*, 0x14) +
                          Controller821F8Field(tag, short*, 2));
            }
            temp_v0_7 = (unsigned short)Controller821F8Field(tag, short*, 2) +
                        (Controller821F8D_8006C648 << 5);
            Controller821F8Field(tag, short*, 2) = temp_v0_7;
            if (temp_v0_7 >= 0x185) {
                temp_a0_7 = Controller821F8Field(tag, void**, 0x10);
                temp_v1_7 = Controller821F8Field(temp_a0_7, unsigned char*, 0x4F);
                if (temp_v1_7 < 0x7FU) {
                    Controller821F8Field(temp_a0_7, unsigned char*, 0x4F) =
                        (unsigned char)(temp_v1_7 + (Controller821F8D_8006C648 * 8));
                }
                temp_v1_8 = Controller821F8Field(tag, void**, 0x10);
                if ((unsigned char)Controller821F8Field(temp_v1_8, unsigned char*, 0x4F) >= 0x80U) {
                    Controller821F8Field(temp_v1_8, unsigned char*, 0x4F) = 0x7FU;
                }
            } else {
                temp_a0_8 = Controller821F8Field(tag, void**, 0x10);
                temp_v1_9 = Controller821F8Field(temp_a0_8, unsigned char*, 0x4F);
                if (temp_v1_9 >= 0x21U) {
                    Controller821F8Field(temp_a0_8, unsigned char*, 0x4F) =
                        (unsigned char)(temp_v1_9 - (Controller821F8D_8006C648 * 8));
                }
                temp_v1_10 = Controller821F8Field(tag, void**, 0x10);
                if ((unsigned int)(Controller821F8Field(temp_v1_10, unsigned char*, 0x4F) - 0x20) >=
                    0x60U) {
                    Controller821F8Field(temp_v1_10, unsigned char*, 0x4F) = 0x20U;
                }
            }
            {
                register int below __asm__("$2") = Controller821F8Field(tag, short*, 2) < 769;
                MATCHING_KEEP(below);
                if (below)
                    goto sharedTail;
                finishOwner = Controller821F8Field(tag, void**, 16);
                goto releaseSecondaryChild;
            }
        case 8: /* switch 1 */
            if (Controller821F8D_8006C770 != 0) {
                Controller821F8RequestMobyAnimation(Controller821F8Field(tag, void**, 8), 1);
            }
            var_a1 = 0x10000002;
            {
                register int flags __asm__("$2") =
                    Controller821F8Field(Controller821F8D_80070328, int*, 0x20C);
                MATCHING_KEEP2(flags, var_a1);
                Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) = flags | var_a1;
            }
            Controller821F8func_800492DC(&frame.vector, var_a1);
            Controller821F8CopyVector(owner + 0xC, &frame.vector);
            Controller821F8Field(Controller821F8Field(tag, void**, 8), int*, 0x54) =
                (int)(((Controller821F8Field(owner, int*, 0x14) +
                        Controller821F8Field(tag, short*, 2)) &
                       0xFFFFFF) |
                      0x80000000);
            temp_a0_9 = Controller821F8Field(tag, void**, 0x10);
            if (temp_a0_9 != 0) {
                Controller821F8Field(temp_a0_9, int*, 0x14) =
                    (int)(Controller821F8Field(owner, int*, 0x14) +
                          Controller821F8Field(tag, short*, 2));
            }
            temp_v0_8 = (unsigned short)Controller821F8Field(tag, short*, 2) +
                        (Controller821F8D_8006C648 << 5);
            Controller821F8Field(tag, short*, 2) = temp_v0_8;
            if (temp_v0_8 >= 0x185) {
                temp_a0_10 = Controller821F8Field(tag, void**, 0x10);
                temp_v1_11 = Controller821F8Field(temp_a0_10, unsigned char*, 0x4F);
                if (temp_v1_11 < 0x7FU) {
                    Controller821F8Field(temp_a0_10, unsigned char*, 0x4F) =
                        (unsigned char)(temp_v1_11 + (Controller821F8D_8006C648 * 8));
                }
                temp_v1_12 = Controller821F8Field(tag, void**, 0x10);
                if ((unsigned char)Controller821F8Field(temp_v1_12, unsigned char*, 0x4F) >=
                    0x80U) {
                    Controller821F8Field(temp_v1_12, unsigned char*, 0x4F) = 0x7FU;
                }
            } else {
                temp_a0_11 = Controller821F8Field(tag, void**, 0x10);
                temp_v1_13 = Controller821F8Field(temp_a0_11, unsigned char*, 0x4F);
                if (temp_v1_13 >= 0x21U) {
                    Controller821F8Field(temp_a0_11, unsigned char*, 0x4F) =
                        (unsigned char)(temp_v1_13 - (Controller821F8D_8006C648 * 8));
                }
                temp_v1_14 = Controller821F8Field(tag, void**, 0x10);
                if ((unsigned int)(Controller821F8Field(temp_v1_14, unsigned char*, 0x4F) - 0x20) >=
                    0x60U) {
                    Controller821F8Field(temp_v1_14, unsigned char*, 0x4F) = 0x20U;
                }
            }
            if (Controller821F8Field(tag, short*, 2) >= 0x301) {
                Controller821F8DeleteMoby(Controller821F8Field(tag, void**, 8));
                finishOwner = Controller821F8Field(tag, void**, 16);
                Controller821F8Field(tag, void**, 8) = 0;
            releaseSecondaryChild:
                if (finishOwner != 0) {
                    Controller821F8DeleteMoby(finishOwner);
                }
            enterStateFive:
                Controller821F8Field(owner, unsigned char*, 72) = 5;
            }
            goto sharedTail;
        case 5: /* switch 1 */
            Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) =
                (int)(Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) | 0x10000002);
            spawnedRecord = Controller821F8SpawnMoby(0x110, owner);
            if (spawnedRecord != 0) {
                Controller821F8Field(spawnedRecord, signed char*, 0x46) =
                    (signed char)(unsigned short)Controller821F8Field(tag, short*, 6);
                Controller821F8Field(Controller821F8Field(spawnedRecord, void**, 0), signed char*,
                                     4) =
                    (signed char)(unsigned short)Controller821F8Field(tag, short*, 6);
            }
            Controller821F8func_80028154(Controller821F8Field(tag, short*, 4));
            {
                register int index __asm__("$2") = Controller821F8Field(tag, short*, 0);
                register int level __asm__("$4") = Controller821F8D_8006C58C;
                register int offset __asm__("$3");
                MATCHING_KEEP2_CLOBBER(index, level, "$3");
                offset = (index << 1) + index;
                MATCHING_KEEP_CLOBBER(offset, "$2");
                index = ((level << 3) + level) << 1;
                offset += index;
                offset = *(Controller821F8InitialTable + offset);
                MATCHING_KEEP_CLOBBER(offset, "$2");
                scanEnabled = Controller821F8D_8006C5C8;
                Controller821F8D_8006C5F4 = 0;
                MATCHING_KEEP2(scanEnabled, offset);
                temp_t0 = offset & 0xF0;
            }
            if (scanEnabled != 0) {
                register unsigned char* scanOutput __asm__("$9");
                register int expectedKind __asm__("$10");
                var_a2 = 0;
                expectedKind = 16;
                __asm__(""
                        : "=r"(var_a2), "=r"(expectedKind)
                        : "0"(var_a2), "1"(expectedKind)
                        : "$9", "$7");
                scanOutput = Controller821F8D_800716AC;
                MATCHING_KEEP_CLOBBER(scanOutput, "$7");
                var_a3 = 0;
                do {
                    register int value __asm__("$2") = Controller821F8Field(tag, short*, 0);
                    register int selectedKind __asm__("$3");
                    register int level __asm__("$5");
                    MATCHING_KEEP(value);
                    if (var_a2 == value)
                        goto advanceScan;
                    level = Controller821F8D_8006C58C;
                    value = ((level << 3) + level) << 1;
                    MATCHING_KEEP(value);
                    value = var_a3 + value;
                    temp_a0_12 = *(Controller821F8D_80066BDC + value);
                    MATCHING_KEEP_CLOBBER(temp_a0_12, "$3");
                    selectedKind = Controller821F8D_8006C5C8;
                    value = temp_a0_12 & 15;
                    if (value != selectedKind)
                        goto advanceScan;
                    value = temp_a0_12 & 240;
                    if (value != expectedKind)
                        goto advanceScan;
                    value = ((level << 1) + level) << 1;
                    value += (int)scanOutput;
                    MATCHING_KEEP(value);
                    value += var_a2;
                    *(unsigned char*)value = 0;
                advanceScan:
                    var_a2 += 1;
                    var_a3 += 3;
                } while (var_a2 < 6);
            }
            {
                register unsigned char* stateEntry __asm__("$2") = Controller821F8D_800715BC;
                register int level __asm__("$7");
                register int value __asm__("$2");
                MATCHING_KEEP_CLOBBER(stateEntry, "$7");
                level = Controller821F8D_8006C58C;
                MATCHING_KEEP_CLOBBER(level, "$5");
                temp_a1_2 = Controller821F8Field(tag, short*, 0);
                MATCHING_KEEP_CLOBBER(temp_a1_2, "$3");
                temp_v1_15 = ((level << 1) + level) << 1;
                stateEntry = (unsigned char*)((int)temp_v1_15 + (int)stateEntry);
                stateEntry += temp_a1_2;
                value = *stateEntry;
                if (value == 0) {
                    var_a2_2 = 2;
                    switch (temp_t0) {
                        default:
                            goto classificationReady;
                        case 16: {
                            register unsigned char* entry __asm__("$4") = Controller821F8D_800716AC;
                            MATCHING_KEEP(entry);
                            entry = (unsigned char*)((int)temp_v1_15 + (int)entry);
                            entry += temp_a1_2;
                            MATCHING_KEEP_CLOBBER(entry, "$3");
                            var_v1_4 = (temp_a1_2 << 1) + temp_a1_2;
                            value = level << 3;
                            value += level;
                            value <<= 1;
                            var_v1_4 += value;
                            var_a0_2 = *entry;
                            value = *(Controller821F8D_80066BDD + var_v1_4);
                            MATCHING_KEEP2_VOLATILE_CLOBBER(value, var_a0_2, "$7");
                            value = var_a0_2 < value;
                            if (!value)
                                goto classifyUpper;
                            MATCHING_KEEP_VOLATILE_CLOBBER(value, "$7");
                            var_a2_2 = 1;
                            goto classificationReady;
                        }
                        case 32:
                            value = level << 3;
                            {
                                register unsigned char* entry __asm__("$4") =
                                    Controller821F8D_800716AC;
                                MATCHING_KEEP(entry);
                                entry = (unsigned char*)((int)temp_v1_15 + (int)entry);
                                entry += temp_a1_2;
                                MATCHING_KEEP_CLOBBER(entry, "$3");
                                var_v1_4 = (temp_a1_2 << 1) + temp_a1_2;
                                value += level;
                                value <<= 1;
                                var_v1_4 += value;
                                var_a0_2 = *entry;
                                value = *(Controller821F8D_80066BDD + var_v1_4);
                                MATCHING_KEEP2_VOLATILE_CLOBBER(value, var_a0_2, "$5");
                                value = var_a0_2 < value;
                                if (!value)
                                    goto classifyUpper;
                                MATCHING_KEEP_VOLATILE_CLOBBER(value, "$5");
                                var_a2_2 = 1;
                                goto classificationReady;
                            }
                    }
                classifyUpper:
                    value = *(Controller821F8D_80066BDE + var_v1_4);
                    MATCHING_KEEP2_VOLATILE(value, var_a0_2);
                    var_a2_2 = 3;
                    if (value < var_a0_2)
                        goto classificationReady;
                    var_a2_2 = 2;
                classificationReady:
                    if (temp_t0 != 0x30) {
                        {
                            register int level __asm__("$3") = Controller821F8D_8006C58C;
                            register unsigned char* base __asm__("$4");
                            register int result __asm__("$2");
                            MATCHING_KEEP_CLOBBER(level, "$4");
                            base = Controller821F8D_800715BC;
                            MATCHING_KEEP2(level, base);
                            result = ((level << 1) + level) << 1;
                            MATCHING_KEEP_CLOBBER(result, "$3");
                            level = Controller821F8Field(tag, short*, 0);
                            result += (int)base;
                            result += level;
                            *(unsigned char*)result = var_a2_2;
                        }
                        if (var_a2_2 == 1) {
                            value = Controller821F8D_8006C7A8 - 10;
                            Controller821F8D_8006C7A8 = value;
                            value = value < -40;
                            if (!value)
                                goto resetClassificationRecord;
                            value = -40;
                            goto storeClassificationCounter;
                        } else if (var_a2_2 == 2) {
                            register int current __asm__("$3") = Controller821F8D_8006C7A8;
                            MATCHING_KEEP(current);
                            if (current > 0) {
                                value = Controller821F8Field(tag, short*, 0);
                                if (value != 0) {
                                    value = current - 5;
                                    Controller821F8D_8006C7A8 = value;
                                    MATCHING_BARRIER_VOLATILE("memory");
                                    current = Controller821F8D_8006C7A8;
                                }
                            }
                            if (current >= 0)
                                goto resetClassificationRecord;
                            value = Controller821F8Field(tag, short*, 0);
                            if (value == 0)
                                goto resetClassificationRecord;
                            value = current + 5;
                        storeClassificationCounter:
                            Controller821F8D_8006C7A8 = value;
                        }
                    resetClassificationRecord:
                        {
                            register int level __asm__("$3") = Controller821F8D_8006C58C;
                            register unsigned char* base __asm__("$4");
                            register int result __asm__("$2");
                            MATCHING_KEEP_CLOBBER(level, "$4");
                            base = Controller821F8D_800716AC;
                            MATCHING_KEEP2(level, base);
                            result = ((level << 1) + level) << 1;
                            MATCHING_KEEP_CLOBBER(result, "$3");
                            level = Controller821F8Field(tag, short*, 0);
                            result += (int)base;
                            result += level;
                            *(unsigned char*)result = 0;
                        }
                    }
                }
            }
            Controller821F8D_8006C7B4 |= 1 << Controller821F8Field(tag, short*, 0);
            Controller821F8D_8006C62C |= 1 << Controller821F8Field(tag, short*, 0);
            Controller821F8Field(owner, unsigned char*, 0x48) = 0xAU;
            return;
        case 10: /* switch 1 */
            if (Controller821F8CDLoadTime() == 0) {
                Controller821F8D_8006E49C = 0;
                Controller821F8DeleteMoby(owner);
                return;
            }
            break;
    }
    return;
sharedTail:
    if (sharedTailEnabled != 0) {
        if ((distance >= 0x2401) || !({
                register int condition __asm__("$2") = verticalDistance < 2305;
                MATCHING_KEEP(condition);
                condition;
            })) {
            if (Controller821F8Field(owner, unsigned short*, 0x44) != 0) {
                var_v1 =
                    Controller821F8SubAngle8(Controller821F8Field(owner, unsigned char*, 0x44), 0);
                if (var_v1 < 0) {
                    var_v1 -= 1;
                } else if (var_v1 > 0) {
                    var_v1 += 1;
                }
                Controller821F8Field(owner, unsigned char*, 0x44) =
                    (unsigned char)(Controller821F8Field(owner, unsigned char*, 0x44) +
                                    (var_v1 >> 1));
                return;
            }
        } else {
            if (distance < 0xC00) {
                distance = 0xC00;
            }
            temp_v1_3 =
                Controller821F8Field(tag, unsigned short*, 0xC) + ((int)(0x2400 - distance) >> 6);
            Controller821F8Field(tag, unsigned short*, 0xC) = temp_v1_3;
            var_v1_2 = Controller821F8SubAngle8(
                Controller821F8Field(owner, unsigned char*, 0x44),
                (int)(*(unsigned short*)(Controller821F8D_800658A0 + (temp_v1_3 & 0x1FE))
                      << 0x10) >>
                    0x18);
            if (var_v1_2 < 0) {
                var_v1_2 -= 1;
            } else if (var_v1_2 > 0) {
                var_v1_2 += 1;
            }
            Controller821F8Field(owner, unsigned char*, 0x44) =
                (unsigned char)(Controller821F8Field(owner, unsigned char*, 0x44) +
                                (var_v1_2 >> 1));
            var_v1_3 = Controller821F8SubAngle8(
                Controller821F8Field(owner, unsigned char*, 0x45),
                (int)(*(unsigned short*)(Controller821F8D_80065920 +
                                         (Controller821F8Field(tag, unsigned short*, 0xC) & 0x1FE))
                      << 0x10) >>
                    0x18);
            if (var_v1_3 < 0) {
                var_v1_3 -= 1;
            } else if (var_v1_3 > 0) {
                var_v1_3 += 1;
            }
            Controller821F8Field(owner, unsigned char*, 0x45) =
                (unsigned char)(Controller821F8Field(owner, unsigned char*, 0x45) +
                                (var_v1_3 >> 1));
        }
    } else {
        return;
    }
}

extern int func_80039714(Moby*);

/**
 * MobyUpdate_501() - func_level_15_8007E7D8()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_15_8007E7D8(Moby* moby) {
    func_80039714(moby);
}

/* SCUS-94467 Rev0 representative 8008336C..8008356C, 128 words.
 * Table halfwords are interpreted as signed via the packed arithmetic shift.
 * Preserve native signed /5 and /3 and their short-result truncation, raw
 * byte heading wrap, tag offsets 6/7, and fresh parent/table reads.
 * Empty constraints emit no instructions: they preserve GCC2.7.2 lifetimes
 * and keep the full +128 heading value observable before its byte store.
 * Physical units, table producers and caller cadence remain unresolved.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct {
    unsigned char reserved00[6];
    signed char offset6;
    unsigned char count7;
} DecodedOrbitParentTag;
typedef struct {
    Moby* parent;
} DecodedOrbitTag;
extern unsigned short DecodedOrbitCos[] __asm__("D_80065920");
extern unsigned short DecodedOrbitSin[] __asm__("D_800658A0");
extern int D_8006C644;
extern unsigned char D_80067555[], D_80067556[];
void func_80055B18(Moby*);
static __inline__ short DecodedOrbitQuotientFive(int packed) {
    return (packed >> 16) / 5;
}
static __inline__ short DecodedOrbitQuotientThree(int packed) {
    return (packed >> 16) / 3;
}
void func_level_15_8007E7F8(Moby* argument) {
    register Moby* moby __asm__("$10") = argument;
    int reservedStack[6];
    register DecodedOrbitTag* tag __asm__("$14") = moby->mobyTag;
    register Moby* parent __asm__("$11") = tag->parent;
    DecodedOrbitParentTag* parentTag = parent->mobyTag;
    register unsigned int angleByteOffset __asm__("$5");
    register int step __asm__("$5");
    register int phase __asm__("$7");
    register int cosine __asm__("$4");
    register int sine __asm__("$5");
    register int phaseCosine __asm__("$3");
    register int phaseSine __asm__("$3");
    register int parentY __asm__("$6");
    if (parentTag->count7 == 0) {
        func_80055B18(moby);
        return;
    }
    phase = parent->angle.yaw;
    angleByteOffset = phase * 2;
    __asm__("" : "=r"(angleByteOffset) : "0"(angleByteOffset), "r"(phase));
    cosine = (int)(*(unsigned short*)((char*)DecodedOrbitCos + angleByteOffset) << 16);
    phase += D_80067555[moby->substate * 4];
    phaseCosine = (int)((DecodedOrbitCos[phase & 255]) << 16);
    sine = (int)(*(unsigned short*)((char*)DecodedOrbitSin + angleByteOffset) << 16);
    /* Retain the original quotient truncation before combining coordinates. */
    {
        register int basePart __asm__("$2") = DecodedOrbitQuotientFive(cosine);
        register int phasePart __asm__("$3") = DecodedOrbitQuotientThree(phaseCosine);
        register int positionX __asm__("$4") = parent->position.x - basePart;
        MATCHING_KEEP2_CLOBBER(positionX, phasePart, "memory");
        parentY = *(volatile int*)&parent->position.y;
        MATCHING_KEEP(parentY);
        positionX += phasePart;
        MATCHING_OBSERVE2(positionX, parentY);
        moby->position.x = positionX;
    }
    phaseSine = (int)((DecodedOrbitSin[phase & 255]) << 16);
    {
        register int basePart __asm__("$2") = DecodedOrbitQuotientFive(sine);
        register int phasePart __asm__("$3") = DecodedOrbitQuotientThree(phaseSine);
        register int positionY __asm__("$6") = parentY - basePart;
        step = D_8006C644;
        positionY += phasePart;
        __asm__("" : "=r"(positionY) : "0"(positionY), "r"(step));
        moby->position.y = positionY;
    }
    moby->position.z = tag->parent->position.z +
                       ((DecodedOrbitParentTag*)tag->parent->mobyTag)->offset6 * 16 +
                       D_80067556[moby->substate * 4];
    {
        int sample = *(short*)((char*)D_80065920 + ((moby->substate + step) * 8 & 0x1F8));
        __asm__("" : "=r"(phase) : "0"(phase), "r"(sample));
        phase += 0x80;
        MATCHING_OBSERVE(phase);
        moby->angle.yaw = phase + ((sample * 3) >> 9);
    }
    if (moby->animationState.id == 0)
        ((DecodedOrbitParentTag*)tag->parent->mobyTag)->count7--;
}
