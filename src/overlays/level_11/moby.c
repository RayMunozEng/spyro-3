#include "matching.h"
#include "common.h"
#include "camera.h"
#include "spu.h"
#include "savepoint.h"
#include "mobyutil.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"

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
void func_level_11_800751C0(void* input) {
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


typedef struct {
    Vector3D anchor;
    short turnSign, lifetime;
    unsigned char heading, turnTimer, phase, amplitude;
} DecodedButterflyTag;
typedef struct {
    short counter;
    unsigned char sound;
    unsigned char reserved03[17];
    Moby* target;
} DecodedButterflySparxTag;
extern Moby* DecodedButterflySparx __asm__("D_8006C65C");
extern int DecodedButterflyLives __asm__("D_8006C784");
extern int DecodedButterflyFlags __asm__("D_8006C640");
extern int DecodedButterflyTick __asm__("D_8006C648");
extern unsigned char DecodedButterflyPlayer[] __asm__("D_80070328");
extern int DecodedButterflyRecovery __asm__("D_80070328 + 0x280");
extern short DecodedButterflyCos[] __asm__("D_80065920");
extern short DecodedButterflySin[] __asm__("D_800658A0");
extern int (*DecodedButterflyPursuit)(Moby*, Vector3D*, int, int, int, int, int, int, int, int, int,
                                      int, int) __asm__("unk_ovlheader_80074314");
int DecodedButterflyDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int DecodedButterflyCountdown(void*, int) __asm__("func_800359A4");
int DecodedButterflySoundActive(Moby*, int) __asm__("func_8003BFC0");
int DecodedButterflySound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedButterflyAngle(int, int, int) __asm__("func_8004E880");
int DecodedButterflyAngleDifference(int, int) __asm__("func_8003613C");
int DecodedButterflyAddAngle(int, int) __asm__("func_8003617C");
int DecodedButterflyRandom(int, int) __asm__("func_8003636C");
int DecodedButterflyHeadingRandom(int, int) __asm__("func_800363DC");
int DecodedButterflyTurn(Moby*, int, int, int, int, int) __asm__("func_8003585C");
void DecodedButterflyAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedButterflyCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
int DecodedButterflyCollision(Vector3D*, int) __asm__("func_80019194");
int DecodedButterflyGroundQuery(Vector3D*, int) __asm__("func_8001A358");
int DecodedButterflyGround(Moby*) __asm__("func_80035D38");
void DecodedButterflyRefresh(Moby*) __asm__("func_8005629C");
void DecodedButterflyDelete(Moby*) __asm__("func_80055B18");
int rand(void);
/* Rev 0 representative: level_10 0x800758AC..0x80075F34.
 * Reuses the Rev 1 shared-butterfly source chain, checked against every
 * original Rev 0 branch and access width. Empty asm constraints emit no
 * instructions and retain the retail compiler's temporary lifetimes.
 * AI generated; not yet human reviewed. See the batch provenance document.
 */
void func_level_11_80075E1C(Moby* argument) {
    Vector3D candidatePosition;
    register Moby* moby __asm__("$17") = argument;
    register DecodedButterflyTag* tag __asm__("$18");
    register int distanceOrTurned __asm__("$20");
    register int collision __asm__("$19");
    register DecodedButterflySparxTag* sparxTag __asm__("$16");
    int delta, speed, groundHeight, phase, targetZ;
    register Vector3D* position __asm__("$16");
    register Vector3D* initialPlayer __asm__("$5");
    register Moby* activeSparx __asm__("$2");
    MATCHING_KEEP(moby);
    tag = moby->mobyTag;
    initialPlayer = (Vector3D*)DecodedButterflyPlayer;
    MATCHING_KEEP(initialPlayer);
    distanceOrTurned = DecodedButterflyDistance(&moby->position, initialPlayer);
    if (moby->state == 2) {
        moby->angle.yaw += 2;
        return;
    }
    if (distanceOrTurned < 3000) {
        int height = moby->position.z - moby->distanceToGround;
        int playerHeight = *(int*)(DecodedButterflyPlayer + 8);
        /* Retail keeps two distinct signed height-admission paths. */
        if (height - playerHeight < 0)
            goto negativeHeight;
        if (height - playerHeight >= 2800)
            goto dispatch;
        MATCHING_BARRIER_VOLATILE("memory");
        goto closeHeight;
    negativeHeight:
        if (playerHeight - height >= 2800)
            goto dispatch;
    closeHeight:
        {
            activeSparx = DecodedButterflySparx;
            MATCHING_KEEP(activeSparx);
            if (activeSparx == 0) {
                int* recovery = &DecodedButterflyRecovery;
                if (*recovery >= 0) {
                    DecodedButterflySparx = SpawnMoby(120, moby);
                    if (DecodedButterflySparx != 0) {
                        sparxTag = DecodedButterflySparx->mobyTag;
                        if (!DecodedButterflySoundActive(DecodedButterflySparx, sparxTag->sound))
                            sparxTag->sound = DecodedButterflySound(DecodedButterflySparx, 0, 0);
                        if (moby->mobyClass == 16)
                            *recovery = 1;
                        else {
                            *recovery = 3;
                            DecodedButterflyLives++;
                            if (DecodedButterflyLives >= 100)
                                DecodedButterflyLives = 99;
                        }
                        goto deleteActor;
                    }
                }
            } else {
                sparxTag = activeSparx->mobyTag;
                if (sparxTag->target != 0) {
                    if (sparxTag->target != moby && sparxTag->counter >= 31)
                        sparxTag->counter = 30;
                } else {
                    delta = DecodedButterflyAngle(
                        moby->position.x - *(int*)DecodedButterflyPlayer,
                        moby->position.y - *(int*)(DecodedButterflyPlayer + 4), 0);
                    delta = DecodedButterflyAngleDifference(DecodedButterflyPlayer[0xE], delta);
                    /* Preserve the returned helper-result sign convention. */
                    tag->turnSign = delta >= 0 ? -1 : 1;
                    tag->phase = 0;
                    moby->state = 1;
                    DecodedButterflySparx->substate = 0;
                    sparxTag->target = moby;
                    sparxTag->counter = DecodedButterflyRandom(80, 130);
                }
            }
        }
    }
dispatch:
    switch (moby->state) {
        case 0:
            if (DecodedButterflyCountdown(&tag->lifetime, 2)) {
                if (!moby->drawn) {
                deleteActor:
                    DecodedButterflyDelete(moby);
                    return;
                }
            } else if (!moby->drawn)
                goto hidden;
            if (distanceOrTurned < 12289) {
                if (DecodedButterflyCountdown(&tag->turnTimer, 1)) {
                    int heading;
                    MATCHING_OBSERVE(distanceOrTurned);
                    heading = DecodedButterflyHeadingRandom(30, 90);
                    if (rand() & 1)
                        heading = -heading;
                    tag->heading = DecodedButterflyAddAngle(tag->heading, heading);
                    tag->turnTimer = DecodedButterflyRandom(60, 140);
                }
                distanceOrTurned = DecodedButterflyTurn(moby, tag->heading, 4, 10, 1, 0);
                speed = 30;
                if (DecodedButterflyTick == 3)
                    speed = 45;
                else if (DecodedButterflyTick == 4)
                    speed = 60;
                candidatePosition.x = (DecodedButterflyCos[moby->angle.yaw] * speed) >> 12;
                candidatePosition.y = (DecodedButterflySin[moby->angle.yaw] * speed) >> 12;
                candidatePosition.z = 0;
                position = &moby->position;
                MATCHING_KEEP(position);
                DecodedButterflyAdd(&candidatePosition, &candidatePosition, position);
                collision = DecodedButterflyCollision(&candidatePosition, 50);
                if (!collision)
                    DecodedButterflyCopy(position, &candidatePosition);
                if (!(DecodedButterflyFlags & 4)) {
                    DecodedButterflyGroundQuery(position, 2048);
                    DecodedButterflyRefresh(moby);
                }
                if (distanceOrTurned && collision) {
                    tag->heading =
                        DecodedButterflyAddAngle(tag->heading, DecodedButterflyRandom(98, 158));
                    tag->turnTimer = DecodedButterflyRandom(30, 80);
                }
                if (!(DecodedButterflyFlags & 3) &&
                    DecodedButterflyDistance(&moby->position, &tag->anchor) >= 2001) {
                    tag->heading = DecodedButterflyAngle(tag->anchor.x - moby->position.x,
                                                         tag->anchor.y - moby->position.y, 0);
                    tag->turnTimer = 40;
                }
            }
            break;
        case 1:
            if (DecodedButterflySparx != 0) {
                register int zeroArgument __asm__("$6") = 0;
                register Vector3D* player __asm__("$16") = (Vector3D*)DecodedButterflyPlayer;
                __asm__("" : "=r"(player) : "0"(player), "r"(zeroArgument));
                delta = DecodedButterflyAngle(
                    moby->position.x - player->x,
                    moby->position.y - *(int*)(DecodedButterflyPlayer + 4), zeroArgument);
                delta = DecodedButterflyAddAngle(delta, tag->turnSign * 10);
                if (DecodedButterflyPursuit(moby, player, 800, delta, 8, 120, 14, 128, 255, 255, 0,
                                            0, 0) < 0 &&
                    DecodedButterflySparx != 0)
                    ((DecodedButterflySparxTag*)DecodedButterflySparx->mobyTag)->counter = 0;
            } else
                moby->state = 0;
            break;
    }
    if (!moby->drawn) {
    hidden:
        if (moby->state != 1)
            goto effect;
    }
    {
        register Moby* refreshArgument __asm__("$4");
        int result = DecodedButterflyGround(moby);
        refreshArgument = moby;
        MATCHING_OBSERVE(refreshArgument);
        groundHeight = result;
        DecodedButterflyRefresh(refreshArgument);
    }
    if (groundHeight != 0) {
        phase = tag->phase;
        targetZ = groundHeight + 640 + ((DecodedButterflySin[phase] * tag->amplitude) >> 12);
        /* The random result is truncated to the original amplitude byte. */
        if (phase == 0 || phase == 128)
            tag->amplitude = DecodedButterflyRandom(256, 512);
        tag->phase -= 4;
        groundHeight = targetZ - moby->position.z;
        if (groundHeight > 32)
            groundHeight = 32;
        if (groundHeight < -32)
            groundHeight = -32;
        moby->position.z += groundHeight;
    }
effect:
    if (moby->mobyClass == 211 && !(DecodedButterflyFlags & 1))
        SpawnParticle(1, 12, moby, 6);
}

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
void func_level_11_800764A8(void* input) {
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
    short timer;
    unsigned char selector, reserved03;
    unsigned char reserved04[0x10];
    Moby* target;
} DecodedFocusTag;
extern int D_8006581C, D_80065810, D_80065818, D_8006C578, D_8006C574;
extern Moby* D_8006C65C;
int func_8004F334(Vector3D*, Vector3D*);
int func_80013E38(Vector3D*, Vector3D*, int);
void func_80037014(Moby*);
void func_80036A68(Moby*, int, int, int);
int rand(void);
void func_level_11_800779F8(Moby* moby) {
    int i;
    Vector3D position;
    if (*(int*)moby->mobyTag)
        func_80037014(moby);
    if (D_8006581C > 0 && func_8004F334(&moby->position, (Vector3D*)&spyro) < D_80065810) {
        register int actorZ __asm__("$2") = moby->position.z;
        register int z __asm__("$3") = spyro.position.z;
        MATCHING_KEEP2(actorZ, z);
        actorZ += 0x164;
        z -= actorZ;
        {
            register int limit __asm__("$2") = D_80065818;
            __asm__("" : "=r"(limit) : "0"(limit), "r"(z));
            if (z < 0)
                z = -z;
            z = z < limit;
            MATCHING_KEEP(z);
            if (z && D_8006C65C && func_80013E38(&D_8006C65C->position, &moby->position, 4)) {
                DecodedFocusTag* tag = D_8006C65C->mobyTag;
                if (tag->target) {
                    if (tag->target != moby && tag->timer > 0)
                        tag->timer = 0;
                } else {
                    D_8006C65C->substate = 9;
                    tag->target = moby;
                    tag->timer = 0;
                    if (!func_8003BFC0(D_8006C65C, tag->selector))
                        tag->selector = func_8003BABC(D_8006C65C, 0, 0);
                }
            }
        }
    }
    if (moby->damageFlags) {
        func_8003BABC(moby, 0, 0);
        moby->substate = 0x70;
        for (i = 0; i < 0xC; i++) {
            Moby* piece;
            if (D_8006C578 - D_8006C574 < 0x15)
                break;
            piece = SpawnMoby(0x132, moby);
            if (i < 5)
                piece->substate = 3;
            else
                piece->animationState.id = 1;
        }
        i = 0;
        do {
            func_8004F178(&position, &moby->position);
            i++;
            {
                register int random __asm__("$2") = rand();
                register int coordinate __asm__("$3") = position.x;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                random &= 0x1FF;
                coordinate += 0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                coordinate -= random;
                MATCHING_KEEP(coordinate);
                position.x = coordinate;
            }
            {
                register int random __asm__("$2") = rand();
                register int coordinate __asm__("$3") = position.y;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                random &= 0x1FF;
                coordinate += 0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                coordinate -= random;
                MATCHING_KEEP(coordinate);
                position.y = coordinate;
            }
            position.z += rand() & 0x1FF;
            SpawnParticle(1, 2, &position, 0);
            SpawnParticle(4, 0x46, &position, (Vector3D*)0x18);
        } while (i < 4);
        func_80036A68(moby, 0, 0, 0);
        func_80055B18(moby);
    }
}

typedef struct {
    int timer, roll, pitch, z, groundGate, feedback;
    signed char* table;
} DecodedRaw201Tag;
typedef struct {
    short counter;
    unsigned char sound, reserved03[17];
    Moby* target;
} DecodedRaw201SparxTag;
extern int DecodedRaw201Profile __asm__("D_80070328 + 0x24C");
extern unsigned char DecodedRaw201Player[] __asm__("D_80070328");
extern int DecodedRaw201Enable __asm__("D_8006581C");
extern int DecodedRaw201Planar __asm__("D_80065810");
extern int DecodedRaw201Vertical __asm__("D_80065818");
extern int DecodedRaw201Tick __asm__("D_8006C648");
extern Moby* DecodedRaw201Sparx __asm__("D_8006C65C");
extern int DecodedRaw201Capacity __asm__("D_8006C578");
extern int DecodedRaw201Active __asm__("D_8006C574");
void DecodedRaw201Ground(Moby*) __asm__("func_80037014");
int DecodedRaw201Distance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int DecodedRaw201Collision(Vector3D*, Vector3D*, int) __asm__("func_80013E38");
int DecodedRaw201SoundActive(Moby*, int) __asm__("func_8003BFC0");
int DecodedRaw201Sound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedRaw201Feedback(Moby*, int, int) __asm__("func_800368A4");
void DecodedRaw201Copy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DecodedRaw201Collectible(Moby*, int, int, int) __asm__("func_80036A68");
void DecodedRaw201Delete(Moby*) __asm__("func_80055B18");
int rand(void);
/* SCUS-94467 Rev 0: level_10 0x80077748..0x80077C64.
* Baseline: Rev 1 sunrise_spring_type201_runtime.py, checked against each
* original Rev 0 branch, mask and access width. Empty asm constraints emit
* no instructions; they preserve the retail compiler temporary lifetimes.
* AI generated; not yet human reviewed. See the batch provenance document.
*/
void func_level_11_80077CB8(Moby* argument) {
    Vector3D particlePosition;
    int reservedStack[2];
    register Moby* moby __asm__("$17") = argument;
    register int* profile __asm__("$20");
    register unsigned int breakMask __asm__("$19");
    register DecodedRaw201Tag* tag __asm__("$18");
    MATCHING_KEEP(moby);
    breakMask = 0x04140000;
    profile = &DecodedRaw201Profile;
    tag = moby->mobyTag;
    {
        register int currentProfile __asm__("$2") = *profile;
        register int expectedProfile __asm__("$3") = 1;
        if (currentProfile == expectedProfile)
            breakMask = 0x041C0000;
        MATCHING_OBSERVE(expectedProfile);
    }
    if (tag->groundGate)
        DecodedRaw201Ground(moby);
    if (DecodedRaw201Enable >= 2 && moby->mobyClass == 201) {
        register Vector3D* position __asm__("$16") = &moby->position;
        register int delta __asm__("$3");
        if (DecodedRaw201Distance(position, (Vector3D*)((char*)profile - 0x24C)) <
            DecodedRaw201Planar) {
            {
                register int actorHeight __asm__("$2") = moby->position.z + 356;
                MATCHING_KEEP(actorHeight);
                delta = *(int*)(DecodedRaw201Player + 8) - actorHeight;
            }
            {
                register int limit __asm__("$2") = DecodedRaw201Vertical;
                MATCHING_KEEP(limit);
                if (delta < 0)
                    delta = -delta;
                delta = delta < limit;
                MATCHING_KEEP(delta);
                if (delta && DecodedRaw201Sparx &&
                    DecodedRaw201Collision(&DecodedRaw201Sparx->position, position, 4)) {
                    register DecodedRaw201SparxTag* sparxTag __asm__("$16") =
                        DecodedRaw201Sparx->mobyTag;
                    if (sparxTag->target) {
                        if (sparxTag->target != moby && sparxTag->counter > 0)
                            sparxTag->counter = 0;
                    } else {
                        DecodedRaw201Sparx->substate = 9;
                        sparxTag->target = moby;
                        sparxTag->counter = 0;
                        if (!DecodedRaw201SoundActive(DecodedRaw201Sparx, sparxTag->sound))
                            sparxTag->sound = DecodedRaw201Sound(DecodedRaw201Sparx, 0, 0);
                    }
                }
            }
        }
    }
    if (tag->timer) {
        tag->timer += DecodedRaw201Tick;
        if (tag->timer < 64) {
            register int first __asm__("$3");
            register int second __asm__("$2");
            register signed char* pair __asm__("$2");
            moby->angle.roll = (unsigned char)tag->table[(tag->timer >> 1) * 2] + tag->roll;
            moby->angle.pitch = (unsigned char)tag->table[(tag->timer >> 1) * 2 + 1] + tag->pitch;
            pair = (signed char*)((tag->timer >> 1) * 2 + (unsigned int)tag->table);
            MATCHING_KEEP(pair);
            first = pair[0];
            second = pair[1];
            if (first < 0)
                first = -first;
            if (second < 0)
                second = -second;
            first += second;
            MATCHING_KEEP(first);
            second = first * 3;
            MATCHING_KEEP(second);
            first = tag->z;
            MATCHING_KEEP(first);
            first += second * 2;
            moby->position.z = first;
        } else {
            tag->timer = 0;
            moby->angle.roll = tag->roll;
            moby->angle.pitch = tag->pitch;
            moby->position.z = tag->z;
        }
    }
    if (moby->mobyClass == 201)
        breakMask |= 0x12820000;
    else if (moby->mobyClass == 202)
        breakMask |= 0x80000;
    if (moby->damageFlags & breakMask) {
        register int attempts __asm__("$18");
        register int leadingCount __asm__("$20");
        register int childClass __asm__("$19");
        register int index __asm__("$16");
        register int leadingMode __asm__("$22");
        register int one __asm__("$21");
        int brokenSubstate;
        DecodedRaw201Sound(moby, 0, 0);
        if (moby->mobyClass == 201) {
            brokenSubstate = 100;
            attempts = 12;
            leadingCount = 5;
            childClass = 307;
        } else {
            brokenSubstate = 144;
            attempts = 16;
            leadingCount = 8;
            childClass = 308;
        }
        moby->substate = brokenSubstate;
        MATCHING_KEEP(attempts);
        index = 0;
        if (attempts != 0) {
            leadingMode = 5;
            one = 1;
            do {
                register Moby* child __asm__("$4");
                register int normalMode __asm__("$2");
                register int parentClass __asm__("$3");
                register int expectedClass __asm__("$2");
                if (DecodedRaw201Capacity - DecodedRaw201Active < 21)
                    break;
                child = SpawnMoby(childClass, moby);
                MATCHING_KEEP(child);
                if (index < leadingCount)
                    child->substate = leadingMode;
                else {
                    normalMode = 4;
                    MATCHING_KEEP(normalMode);
                    child->animationState.id = one;
                    child->substate = normalMode;
                }
                parentClass = moby->mobyClass;
                expectedClass = 201;
                MATCHING_KEEP(expectedClass);
                if (parentClass != expectedClass)
                    child->colour.r = one;
                index++;
            } while (index < attempts);
        }
        index = 0;
        if (moby->mobyClass != 201)
            goto particleLoop;
    fourParticles:
        if (index >= 4)
            goto particlesDone;
    particleLoop:
        {
            DecodedRaw201Copy(&particlePosition, &moby->position);
            index++;
            {
                register int sample __asm__("$2") = rand() & 255;
                register int coordinate __asm__("$3") = particlePosition.x + 128;
                MATCHING_KEEP(coordinate);
                coordinate -= sample;
                MATCHING_KEEP(coordinate);
                particlePosition.x = coordinate;
            }
            {
                register int sample __asm__("$2") = rand() & 255;
                register int coordinate __asm__("$3") = particlePosition.y + 128;
                MATCHING_KEEP(coordinate);
                coordinate -= sample;
                MATCHING_KEEP(coordinate);
                particlePosition.y = coordinate;
            }
            particlePosition.z += rand() & 511;
            SpawnParticle(1, 2, &particlePosition, 0);
            SpawnParticle(4, 70, &particlePosition, 24);
        }
        if (moby->mobyClass == 201)
            goto fourParticles;
        /* Preserve the original four-count branch and delay slot. */
        MATCHING_BARRIER_VOLATILE("memory");
        if (index < 8)
            goto particleLoop;
    particlesDone:
        DecodedRaw201Collectible(moby, 0, 0, 0);
        DecodedRaw201Delete(moby);
        moby->damageFlags = 0;
        return;
    }
    tag->feedback = DecodedRaw201Feedback(moby, tag->feedback, moby->mobyClass != 201);
    if ((moby->damageFlags & 0x30000) && !tag->timer) {
        tag->timer = 1;
        tag->roll = moby->angle.roll;
        tag->pitch = moby->angle.pitch;
        tag->z = moby->position.z;
        if ((unsigned int)(unsigned short)moby->mobyClass - 202 < 2)
            DecodedRaw201Sound(moby, 1, 0);
    }
    moby->damageFlags = 0;
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
void func_level_11_800781D8(Moby* moby) {
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

    angleByte = func_8004E880(camera.nextCameraPosCartesian.x - moby->position.x,
                              camera.nextCameraPosCartesian.y - moby->position.y, 0);
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


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
extern unsigned char Controller78288D_8006E17C[] __asm__("D_8006E17C");
extern int Controller78288D_8006E160 __asm__("D_8006E160");
int Controller78288Helper136F0(void*, void*, void*) __asm__("func_800136F0");
void func_level_11_800784DC(void* input) {
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
    register int ownerPositionWord __asm__("$17");
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
    register unsigned char* prefixTag __asm__("$16");
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
                case 7: {
                    register int globalGate __asm__("$2") = Controller78288D_8006E344;
                    register int one __asm__("$4");
                    register int expected __asm__("$2");
                    register int prefixKind __asm__("$3");
                    register int prefixState __asm__("$2");
                    register int savedOne __asm__("$17");
                    register unsigned char* cameraAddress __asm__("$16");
                    register unsigned char* recordPointer __asm__("$2");
                    register unsigned char* sourcePointer __asm__("$5");
                    register void* firstArgument __asm__("$4");
                    register void* thirdArgument __asm__("$6");
                    MATCHING_KEEP_CLOBBER(globalGate, "$4");
                    one = 1;
                    MATCHING_KEEP2(one, globalGate);
                    if (globalGate == one)
                        goto clearExtraHandle;
                    expected = 11;
                    MATCHING_KEEP_CLOBBER(expected, "$3");
                    prefixKind = Controller78288Field(prefixTag, unsigned char*, 0);
                    if (prefixKind != expected)
                        goto setSubstateFour;
                    prefixState = Controller78288Field(prefixTag, unsigned char*, 4);
                    MATCHING_KEEP_CLOBBER(prefixState, "$17");
                    savedOne = 1;
                    if (prefixState == 0) {
                        Controller78288Field(tag, unsigned char*, 2) = savedOne;
                        Controller78288Field(prefixTag, unsigned char*, 5) = savedOne;
                        recordPointer = Controller78288Field(tag, unsigned char**, 0x14);
                        if (recordPointer != 0) {
                            cameraAddress = Controller78288D_8006E17C;
                            MATCHING_KEEP_CLOBBER(cameraAddress, "$5");
                            sourcePointer =
                                Controller78288Field(recordPointer, unsigned char**, 0xC);
                            firstArgument = cameraAddress;
                            Controller78288CopyVector(firstArgument, sourcePointer + 16);
                            recordPointer = Controller78288Field(tag, unsigned char**, 0x14);
                            sourcePointer =
                                Controller78288Field(recordPointer, unsigned char**, 0xC);
                            firstArgument = cameraAddress - 20;
                            thirdArgument = sourcePointer + 16;
                            Controller78288Helper136F0(firstArgument, sourcePointer, thirdArgument);
                            nextSubstate = 17;
                            Controller78288D_8006E160 = nextSubstate;
                        }
                        Controller78288Field(owner, unsigned char*, 0x48) = savedOne;
                        Controller78288RequestMobyAnimation(owner, 1);
                        goto setSubstateFour;
                    }
                    if (prefixState != one)
                        goto setSubstateFour;
                    nextSubstate = 5;
                    goto storeSubstate;
                }
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

/* Rev 0 private record: signed halfword velocity and low-byte angle deltas. */
typedef struct {
    Vector3D16 velocity;
    unsigned short rollDelta, pitchDelta, yawDelta;
    int remaining, zLimit;
} DecodedMotionTag;
extern Vector3D DecodedMotionNormal __asm__("D_80071918");
extern int DecodedMotionNormalY __asm__("D_8007191C");
extern int DecodedMotionNormalZ __asm__("D_80071920");
int func_80019194(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_80055B18(Moby*);
int rand(void);
void func_level_11_800790EC(Moby* moby) {
    Vector3D particle;
    int reservedStack[6]; /* Preserve the original local frame layout. */
    DecodedMotionTag* tag = moby->mobyTag;
    int dot, index;
    register int projection __asm__("$16");
    register Vector3D* normal __asm__("$19");
    if (tag->remaining <= 0 || !moby->drawn)
        goto retire;
    if (!(moby->substate & 1)) {
        int positionZ = moby->position.z;
        MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
        if (tag->zLimit >= positionZ)
            goto retire;
    } else if (func_80019194(&moby->position, 256)) {
        /* Empty constraints preserve the original compiler register allocation. */
        normal = &DecodedMotionNormal;
        MATCHING_KEEP(normal);
        func_8004EF04(normal, 4096);
        dot = tag->velocity.x * normal->x + tag->velocity.y * DecodedMotionNormalY +
              tag->velocity.z * DecodedMotionNormalZ;
        projection = dot >> 11;
        MATCHING_KEEP(projection);
        if (projection < 0) {
            func_8004F08C(normal, 4096, (dot >> 13) - projection);
            tag->velocity.x = (unsigned short)tag->velocity.x + normal->x;
            MATCHING_BARRIER_VOLATILE("memory");
            tag->velocity.y = (unsigned short)tag->velocity.y + DecodedMotionNormalY;
            MATCHING_BARRIER_VOLATILE("memory");
            tag->velocity.z = (unsigned short)tag->velocity.z + DecodedMotionNormalZ;
        }
    }
    moby->position.x += tag->velocity.x;
    moby->position.y += tag->velocity.y;
    if (moby->substate & 8)
        tag->velocity.z = (unsigned short)tag->velocity.z - 3;
    else if (moby->mobyClass == 0x12F)
        tag->velocity.z = (unsigned short)tag->velocity.z - 16;
    else
        tag->velocity.z = (unsigned short)tag->velocity.z - 6;
    if (tag->velocity.z < -128)
        tag->velocity.z = -128;
    moby->position.z += tag->velocity.z;
    moby->angle.roll += (unsigned char)tag->rollDelta;
    moby->angle.pitch += (unsigned char)tag->pitchDelta;
    moby->angle.yaw += (unsigned char)tag->yawDelta;
    if ((moby->substate & 2) && !(tag->remaining & 3)) {
        particle.x = rand() & 3;
        particle.y = rand() & 3;
        particle.z = 20;
        SpawnParticle(1, 1, &moby->position, &particle);
    } else if (moby->substate & 4) {
        register int count __asm__("$2") = 1;
        /* Retail retains this initially true guard before the particle loop. */
        MATCHING_KEEP(count);
        index = 0;
        if (count) {
            do {
                index++;
                particle.x = 64 - (rand() & 127);
                particle.y = 64 - (rand() & 127);
                particle.z = 64 - (rand() & 127);
                func_8004F194(&particle, &particle, &moby->position);
                SpawnParticle(1, 0x42, &particle, (Vector3D*)1);
            } while (index < ((moby->substate & 1) * 2 + 1));
        }
    } else if ((moby->substate & 8) && !(tag->remaining & 7)) {
        particle.x = 8 - (rand() & 15);
        particle.y = 8 - (rand() & 15);
        particle.z = 4 - (rand() & 7);
        SpawnParticle(1, 0x27, &moby->position, &particle);
    }
    tag->remaining--;
    return;
retire:
    if (moby->substate & 1) {
        if (moby->substate & 16)
            SpawnParticle(8, 15, &moby->position, 0);
        else
            SpawnParticle(8, 0x46, &moby->position, (Vector3D*)16);
    }
    func_80055B18(moby);
}

typedef struct {
    Moby* actor;
    int timer;
} DecodedParticleAttachment;
extern int D_8006C648, D_8006C578, D_8006C574, D_8006C79C, D_8006C58C;
extern Moby* D_8006C550;
extern int D_80071AB0[][8];
extern unsigned short DecodedCosine[] __asm__("D_80065920");
extern unsigned short DecodedSine[] __asm__("D_800658A0");
extern Vector3D* DecodedParticleAllocation(int) __asm__("func_8002F040");
int rand(void);
void func_level_11_8007951C(Moby* moby) {
    DecodedParticleAttachment* tag = moby->mobyTag;
    Vector3D position;
    int i;
    if (!tag->actor) {
        tag->actor = SpawnMoby(0xD3, moby);
        if (tag->actor) {
            tag->actor->position.z = moby->position.z + 0xE0;
            tag->actor->state = 2;
            tag->actor->unknown = 0;
        }
    }
    if (moby->drawn) {
        if (tag->timer < 0x190)
            tag->timer += D_8006C648;
        else {
            Vector3D* particle = DecodedParticleAllocation(5);
            if (particle) {
                register int random __asm__("$2");
                register int angle __asm__("$16");
                register Vector3D* destination __asm__("$4");
                register Vector3D* origin __asm__("$5");
                random = rand();
                destination = particle;
                origin = &moby->position;
                __asm__(""
                        : "=r"(destination), "=r"(origin)
                        : "0"(destination), "1"(origin), "r"(random)
                        : "$16");
                angle = random;
                func_8004F178(destination, origin);
                angle &= 0xFF;
                {
                    register unsigned int cosine __asm__("$2") = DecodedCosine[angle];
                    register int x __asm__("$3") = particle->x;
                    MATCHING_KEEP2(cosine, x);
                    x += (short)cosine >> 4;
                    {
                        register int z __asm__("$2") = particle->z;
                        __asm__("" : "=r"(z) : "0"(z), "r"(x));
                        particle->x = x;
                        {
                            register unsigned int sine __asm__("$3") = DecodedSine[angle];
                            __asm__("" : "=r"(sine) : "0"(sine), "r"(z));
                            z += 0x180;
                            sine <<= 16;
                            __asm__("" : "=r"(sine) : "0"(sine), "r"(z));
                            particle->z = z;
                            {
                                register int y __asm__("$2") = particle->y;
                                __asm__("" : "=r"(y) : "0"(y), "r"(sine));
                                y += (int)sine >> 20;
                                MATCHING_KEEP(y);
                                particle->y = y;
                            }
                        }
                    }
                }
            }
            {
                register int random __asm__("$2") = rand();
                register int timer __asm__("$3") = tag->timer;
                __asm__("" : "=r"(timer) : "0"(timer), "r"(random));
                random &= 0xFF;
                timer -= 0x80;
                __asm__("" : "=r"(timer) : "0"(timer), "r"(random));
                timer -= random;
                MATCHING_KEEP(timer);
                tag->timer = timer;
            }
        }
    }
    if (moby->damageFlags) {
        if (tag->actor) {
            tag->actor->state = 0;
            tag->actor->unknown = -1;
        }
        moby->substate = 0x70;
        for (i = 0; i < 0x10; i++) {
            Moby* piece;
            if (D_8006C578 - D_8006C574 < 0x15)
                break;
            piece = SpawnMoby(0x238, moby);
            piece->animationState.id = rand() % 3;
        }
        i = 0;
        do {
            func_8004F178(&position, &moby->position);
            i++;
            {
                register int random __asm__("$2") = rand();
                register int coordinate __asm__("$3") = position.x;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                random &= 0x1FF;
                coordinate += 0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                coordinate -= random;
                MATCHING_KEEP(coordinate);
                position.x = coordinate;
            }
            {
                register int random __asm__("$2") = rand();
                register int coordinate __asm__("$3") = position.y;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                random &= 0x1FF;
                coordinate += 0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate), "r"(random));
                coordinate -= random;
                MATCHING_KEEP(coordinate);
                position.y = coordinate;
            }
            position.z += rand() & 0x1FF;
            SpawnParticle(1, 2, &position, 0);
            SpawnParticle(4, 0x46, &position, (Vector3D*)0x18);
        } while (i < 4);

        func_8003BABC(moby, 0, 0);
        func_8003BA00(moby);
        {
            int packed = (moby - D_8006C550) + D_8006C79C;
            D_80071AB0[D_8006C58C][packed >> 5] |= 1 << (packed & 0x1F);
        }
        func_80055B18(moby);
    }
}

/* Tag words at +0/+4/+8 and model pointer at +0x3C only. */
typedef struct {
    int mobyClass, countdown, reset;
} DecodedRespawnTag;
typedef struct {
    unsigned char reserved00[0x3C];
    unsigned char* frames[1];
} DecodedRespawnModel;
extern DecodedRespawnModel* D_8006EE2C[];
extern Moby* D_8006C550;
extern Moby* D_8006C704;
extern int D_8006C7C4;
int func_8004F334(Vector3D*, Vector3D*);
void func_80055C24(Moby*);
void func_8005629C(Moby*);
void func_level_11_80079884(Moby* owner) {
    DecodedRespawnTag* tag = owner->mobyTag;
    Moby* moby;
    register unsigned char* pitch __asm__("$16");
    unsigned int animationFrames;
    register int multipleFrames __asm__("$3");
    register Moby* callArgument __asm__("$4");
    func_8004F178(&owner->position, &spyro.position);
    if (func_800359A4(&tag->countdown, 4)) {
        moby = D_8006C550;
        tag->countdown = tag->reset;
        if (moby < D_8006C704) {
            pitch = &moby->angle.pitch;
            MATCHING_OBSERVE_VOLATILE(pitch);
            do {
                if (*(short*)(pitch - 15) == tag->mobyClass &&
                    *(unsigned char*)(pitch + 3) >= 0x80 &&
                    ((*(unsigned char*)(pitch + 14) >> D_8006C7C4) & 1) &&
                    func_8004F334(&spyro.position, moby->mobyTag) > 0x6000) {
                    func_8004F178(&moby->position, moby->mobyTag);
                    func_80055C24(moby);
                    *(int*)(pitch - 45) = 0;
                    *(unsigned char*)(pitch + 12) = 0;
                    *(unsigned char*)(pitch + 3) = 0;
                    *(unsigned char*)(pitch - 3) = 0;
                    callArgument = moby;
                    animationFrames = D_8006EE2C[*(short*)(pitch - 15)]->frames[0][0];
                    MATCHING_OBSERVE_VOLATILE(callArgument);
                    *(unsigned char*)(pitch - 9) = 0;
                    *(unsigned char*)(pitch - 8) = 0;
                    *(unsigned char*)(pitch - 7) = 0;
                    *(unsigned char*)(pitch - 6) = 1;
                    *(unsigned char*)(pitch - 1) = 0;
                    *(unsigned char*)(pitch + 0) = 0;
                    multipleFrames = animationFrames >= 2;
                    MATCHING_KEEP_VOLATILE(multipleFrames);
                    *(unsigned char*)(pitch - 5) = -multipleFrames & 0x30;
                    func_80035D38(callArgument);
                    func_8005629C(moby);
                    break;
                }
                {
                    Moby* limit = D_8006C704;
                    __asm__ volatile("" : "=r"(moby) : "0"(moby), "r"(limit));
                    moby++;
                    pitch += sizeof(Moby);
                    if (moby >= limit)
                        break;
                }
            } while (1);
        }
    }
}

typedef struct {
    unsigned char unk0, unk1;
    short offset;
    Moby* parent;
} DecodedFollowTag;
extern unsigned short D_8006E040, D_8006E03E;
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_11_80079A10(Moby* moby) {
    DecodedFollowTag* tag;
    moby->angle.yaw = ((short)D_8006E040 >> 4) - 0x80;
    moby->angle.pitch = D_8006E03E >> 4;
    tag = moby->mobyTag;
    if (tag->unk0 == 1) {
        if (tag->parent->state >= 0x80 || tag->parent->mobyClass != tag->unk1) {
            func_80055B18(moby);
            return;
        }
        if (tag->parent->mobyClass == 0x78) {
            moby->size -= deltaTime * 4;
            if (moby->size < 0x1A)
                moby->size = 0x1A;
            if ((unsigned int)(spyro.movementState - 0xB) >= 2 || tag->parent->drawn == 0) {
                ((unsigned char*)tag->parent->mobyTag)[0xA] = 0;
                func_80055B18(moby);
                return;
            }
        }
        func_8004F178(&moby->position, &tag->parent->position);
        moby->position.z += tag->offset;
    }
}

typedef struct {
    unsigned char reserved00[2];
    unsigned char mode, reserved03, reserved04, byte05, reserved06, byte07;
    unsigned char reserved08[0x18];
    int state20;
} DecodedCallbackMergedTag;
extern unsigned char D_8007158A, D_80066FCC[], D_80070300[];
extern int D_8006E53C, D_8006E344;
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern int D_8006C640;
extern unsigned char D_8007159A;
void func_80055B18(Moby*);
/* USA SCUS-94467 Rev 0: level22 0x8007DB5C..0x8007DCF4,
 * level11 0x80079B64..0x80079CFC, 102 words each.
 * Baselines: verified level13 callback and level15 removal guard.
 * Per-copy class/flag/table index values come from the original assembly.
 * Tag bytes and state word preserve access widths, with no inferred timing
 * or dialogue/SFX meaning. Producers and helper semantic chains remain open.
 * AI generated; not yet human reviewed.
 */
void func_level_11_80079B64(Moby* argument) {
    int flags = D_8006C640;
    register Moby* moby __asm__("$17") = argument;
    register DecodedCallbackMergedTag* tag __asm__("$16") = moby->mobyTag;
    if (!flags && moby->mobyClass == 0x220 && !D_8007159A) {
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
        case 0:
            if (moby->mobyClass == 0x2AB) {
                if (!D_8007158A)
                    tag->mode = 0;
                else {
                    register int selected __asm__("$2") = D_80070300[D_80066FCC[0x10]] & 1;
                    MATCHING_KEEP(selected);
                    if (!selected)
                        selected = 1;
                    else
                        selected = 2;
                    MATCHING_KEEP(selected);
                    tag->mode = selected;
                }
            }
            if (tag->mode == 2)
                tag->byte05 = 0;
            if (!tag->byte05) {
                if (!(D_8006E53C & 0x10))
                    goto check;
                if (func_80037BBC(moby, 0))
                    goto fire;
                tag->byte07 = 0;
                MATCHING_BARRIER("memory");
            }
        check:
            if (tag->byte05) {
                if (func_80037BBC(moby, 0)) {
                fire:
                    func_800512E4(moby, 0, 0);
                    moby->state = 1;
                } else
                    tag->byte07 = 0;
            }
            break;
        case 1:
            if (D_8006E344 != 1) {
                tag->state20 = 1;
                moby->state = 0;
            }
            break;
    }
}

typedef struct {
    int linkedIndex, animationA, animationB;
} DecodedLinkedModelTag;
extern Moby* D_8006C550;
int DecodedLinkedModelHeadingDifference(int, int) __asm__("func_8004F264");
void func_level_11_80079CFC(Moby* moby) {
    DecodedLinkedModelTag* tag = moby->mobyTag;
    Moby* linked = &D_8006C550[tag->linkedIndex];
    Vector3D modelPoint, position, delta;
    int angle, length;
    if (linked->state >= 0x80) {
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
        case 0:
            if (linked->animationState.nextId != tag->animationA &&
                linked->animationState.nextId != tag->animationB) {
                moby->unknownCollision = 0;
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
                moby->state = 1;
                break;
            }
            angle = linked->angle.yaw - 0x40;
            func_8004F178(&position, &linked->position);
            angle &= 0xFF;
            position.x += (D_80065920[angle] * 275) >> 11;
            position.y += (D_800658A0[angle] * 275) >> 11;
            position.z = linked->position.z - linked->distanceToGround;
            func_80055D24(linked, 4);
            func_80055F14(linked, 2, &modelPoint);
            func_8004F178(&moby->position, &position);
            func_8004F1C8(&delta, &position, &modelPoint);
            moby->angle.yaw = linked->angle.yaw + 0x7A;
            length = func_8004EDE8(&delta, 0);
            angle = func_8004E880(delta.x, delta.y, 0);
            if (DecodedLinkedModelHeadingDifference(angle, linked->angle.yaw) < 0x40)
                length = -length;
            moby->angle.pitch = func_8004E880(length, delta.z, 0) - 1;
            break;
        case 1:
            if (linked->animationState.nextId == tag->animationA ||
                linked->animationState.nextId == tag->animationB) {
                moby->unknown3[0] = 1;
                moby->lowDrawDistance = 0x28;
                moby->drawn = 1;
                func_80055D24(moby, 1);
                moby->state = 0;
            }
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev 0 five-state controller.
 * All180 instructions and six owned table/padding words of both copies read.
 * Original byte/halfword/word widths and twelve-byte table stride retained.
 * Sources: level_11/moby/func_level_11_80079F68.s and
 * level_32/moby/func_level_32_8008A03C.s. Once per invocation; helper/table
 * producers, coordinate units and caller cadence remain unresolved.
 * Confidence: exact original compiled words. Falsifiable vectors: all linked
 * instruction/table words at those addresses and all retail hashes.
 * Empty constraints preserve original register lifetimes without opcodes.
 */
extern int D_8006C640, D_8006C754, D_8006E044, D_8006E048;
extern int D_8006E160, D_8006E1A0, D_8006E344, D_8006E53C;
extern unsigned char* Controller79F68Records __asm__("D_8006C758");
void func_level_11_80079F68(Moby* argument) {
    register Moby* moby __asm__("$17") = argument;
    Vector3D position;
    int sampledHeight;
    unsigned char state;
    register int value __asm__("$2");
    register Vector3D* prepared __asm__("$4");
    register int* transitionWord __asm__("$4");
    register Moby* removalTarget __asm__("$4");
    register unsigned char* stateAddress __asm__("$16");
    register int* playerControl __asm__("$16");
    register unsigned char* record __asm__("$3");

    state = moby->state;
    switch (state) {
        case 0: {
            register int blocked __asm__("$2") = D_8006C640;
            MATCHING_KEEP2_CLOBBER(blocked, moby, "$4");
            removalTarget = moby;
            if (blocked)
                goto removeMoby;
            if (!D_8006C754)
                goto removeMoby;
            MATCHING_BARRIER_VOLATILE("memory");
            stateAddress = &moby->state;
            if (!Controller79F68Records)
                goto removeMoby;
            moby->state = 4;
            func_8003B7B4(stateAddress, 1, &savedData);
            func_8003B7B4(stateAddress, 1, &unsavedData);
            func_80013CC4(D_8006C754, 8);
            D_8006E344 = 14;
            moby->state = 1;
            return;
        }
        case 1:
            transitionWord = &D_8006E160;
            MATCHING_KEEP(transitionWord);
            if (*transitionWord == 10) {
                if (!(D_8006E53C & 0x850))
                    goto loadSelectedRecord;
                *transitionWord = 0;
                value = 3;
            } else
                value = 2;
            moby->state = value;
            goto loadSelectedRecord;
        case 2:
            /* Word at player +0x20C; fallback height at player +8. */
            MATCHING_BARRIER_VOLATILE("memory");
            value = 0x10000082;
            prepared = &position;
            MATCHING_KEEP2_CLOBBER(value, prepared, "$16");
            playerControl = &spyro.unk17a;
            *playerControl = value;
            spyro.unk20[1] = 0x12;
            func_8004F178(prepared, (Vector3D*)((unsigned char*)playerControl - 0x20C));
            sampledHeight = func_8001A358(&position, 0x1000);
            position.z = sampledHeight;
            if (sampledHeight == 0) {
                MATCHING_KEEP(playerControl);
                position.z = *(int*)((unsigned char*)playerControl - 0x204);
            } else {
                position.z = sampledHeight + spyro.unk4a;
            }
            func_8003B634(&savedData, &position, spyro.bodyRotation.yaw);
            __asm__ volatile("" : : : "$4", "memory");
            D_8006E344 = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            MATCHING_KEEP_CLOBBER(moby, "$4");
            removalTarget = moby;
            goto removeMoby;
        case 3:
            if ((D_8006E044 != 0xA) || (D_8006E048 == 0x81)) {
                goto saveSelected;
            }
        loadSelectedRecord:
            /* Original stride is 12, including the halfword read at +14.
         * Coordinate halves are multiplied by four; rotation halves shift
         * right four before byte stores. Their source units are unresolved. */
            {
                register int index __asm__("$3");
                value = 0x10010000;
                index = D_8006E1A0;
                MATCHING_KEEP2(value, index);
                value |= 0x8000;
                spyro.unk17a = value;
                value = index * 3;
                record = Controller79F68Records;
                MATCHING_KEEP2(value, record);
                value *= 4;
                record += value;
            }
            spyro.unk19.x = *(unsigned short*)(record + 4) * 4;
            spyro.unk19.y = *(unsigned short*)(record + 6) * 4;
            spyro.unk19.z = *(unsigned short*)(record + 8) * 4;
            spyro.unk18.roll =
                (unsigned char)((unsigned short)*(unsigned short*)(record + 0xA) >> 4);
            spyro.unk18.pitch =
                (unsigned char)((unsigned short)*(unsigned short*)(record + 0xC) >> 4);
            value = *(unsigned short*)(record + 0xE);
            MATCHING_KEEP_CLOBBER(value, "$3");
            {
                register int literal __asm__("$3") = 17;
                MATCHING_KEEP(literal);
                spyro.unk20[1] = literal;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            spyro.unk18.yaw = (unsigned int)value >> 4;
            return;
        saveSelected:
            func_8003B634(&savedData, &spyro.unk19, spyro.unk18.yaw);
            __asm__ volatile("" : : : "$5", "memory");
            D_8006E344 = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            MATCHING_KEEP_CLOBBER(moby, "$4");
            removalTarget = moby;
            goto removeMoby;
        case 4:
            MATCHING_KEEP_CLOBBER(moby, "$4");
            removalTarget = moby;
        removeMoby:
            func_80055B18(removalTarget);
            return;
    }
}

typedef struct {
    int box[6];
    int innerBox[6];
    int actorIndex, selector, outerLimit, innerLimit, level;
} DecodedStreamTrigger;
extern int D_8006C5C8, D_8006E480, D_8006E344, D_8006E48C, D_8006C58C, D_8006E470, D_8006E49C,
    D_8006C4F8;
extern int D_80072098[];
extern int D_8006DBE8[][4];
extern Moby* D_8006C550;
void func_80052918(int, Moby*);
int func_8005E0BC(int, void*, int);
int func_8005F46C(int, void*);
void func_level_11_8007A238(Moby* actor) {
    register Moby* current __asm__("$18") = actor;
    register DecodedStreamTrigger* tag __asm__("$16");
    register Spyro* player __asm__("$17");
    register int* streamState __asm__("$20");
    unsigned char parameter;
    int record, offset;
    MATCHING_KEEP(current);
    tag = current->mobyTag;
    if (tag->level != D_8006C5C8)
        return;
    streamState = &D_8006E480;
    MATCHING_KEEP(streamState);
    if (*streamState || D_8006E344 == 1 || D_8006E344 == 0xF)
        return;
    player = &g_Spyro;
    if (func_80036220((Vector3D*)player, (void*)tag, 0, tag->outerLimit)) {
        func_80052918(tag->selector, &D_8006C550[tag->actorIndex]);
        return;
    }
    switch (current->state) {
        case 0:
            if (func_80036220((Vector3D*)player, (void*)tag->innerBox, 0, tag->innerLimit)) {
                D_8006E49C = 1;
                current->state = 1;
            }
            break;
        case 1:
            if (!func_80036220((Vector3D*)player, (void*)tag->innerBox, 0x400,
                               tag->innerLimit + 0x400)) {
                D_8006E49C = 0;
                current->state = 0;
                break;
            }
            if (D_8006E48C)
                break;
            record = 2;
            parameter = 0x80;
            if (D_8006C5C8)
                record = D_8006C5C8 * 2 + 2;
            offset = D_80072098[record * 2] + D_8006DBE8[D_8006C58C][0];
            func_8005E0BC(0xE, &parameter, 0);
            {
                register int sector __asm__("$4") = offset;
                register void* buffer __asm__("$16");
                MATCHING_KEEP(sector);
                buffer = (void*)((int)streamState - 8);
                func_8005F46C(D_8006E470 + sector / 0x800, buffer);
                func_8005E0BC(2, buffer, 0);
            }
            func_8005E0BC(0x16, 0, 0);
            current->state = 2;
            break;
        case 2:
            if (!func_80036220((Vector3D*)player, (void*)tag->innerBox, 0x400,
                               tag->innerLimit + 0x400)) {
                D_8006E49C = 0;
                current->state = 0;
            } else if (D_8006E48C) {
                D_8006E49C = 1;
                current->state = 1;
            }
            break;
        case 3:
            func_80052918(tag->selector, &D_8006C550[tag->actorIndex]);
            D_8006C4F8 = 2;
            break;
    }
}

#define ControllerA4E4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char ControllerA4E4Player[] __asm__("D_80070328");
extern int D_8006C3F4, D_8006C4F8, D_8006C598, D_8006C640, D_8006C648, D_8006C6D0, D_8006C6E0,
    D_8006E344;
extern unsigned char D_80071575;
extern unsigned char ControllerA4E4Data0[] __asm__("D_800652B0");
extern unsigned char ControllerA4E4Data4[] __asm__("D_800652B4");
extern unsigned char ControllerA4E4Data6[] __asm__("D_800652B6");
extern unsigned char ControllerA4E4Control0[] __asm__("D_8006D088");
extern unsigned char ControllerA4E4Control1[] __asm__("D_8006C7F8");
extern Vector3D ControllerA4E4Vector __asm__("D_800719BC");
extern int ControllerA4E4VectorY __asm__("D_800719C0");
extern int ControllerA4E4VectorZ __asm__("D_800719C4");
extern unsigned char ControllerA4E4Camera0[] __asm__("D_800719A8");
extern unsigned char ControllerA4E4Camera1[] __asm__("D_800719F0");
extern unsigned char ControllerA4E4CameraSource0[] __asm__("D_80068F7C");
extern unsigned char ControllerA4E4CameraSource1[] __asm__("D_80068F90");
extern void (*ControllerA4E4Header)(Moby*, int) __asm__("unk_ovlheader_80074318");
int ControllerA4E4Helper3B74C(void*) __asm__("func_8003B74C");
int ControllerA4E4Helper3B7B4(unsigned char*, int, void*) __asm__("func_8003B7B4");
int ControllerA4E4Helper512E4(Moby*, int, int) __asm__("func_800512E4");
int ControllerA4E4Helper135A4(void*, void*, int) __asm__("func_800135A4");
int ControllerA4E4Helper4F984(int, int, int) __asm__("func_8004F984");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Sources: level11/8007A4E4, level14/8007A4D8, level23/8007AE74.
 * All269 original instructions and helper/global symbols checked per copy.
 * The original per-level flag bytes are71575,71579 and71578 respectively.
 * Tag accesses: byte+5, words+34/+48/+50. Four states0/1/3/15.
 * Signed halfword samples multiply13 and shift5; colour word and alpha byte
 * writes remain distinct. Header callback arguments are(owner,65).
 * Timing units, table/helper producers, fixed-point domains and caller cadence
 * remain unresolved; updates occur once per call. Names imply no semantics.
 * Confidence: exact native instructions and linked words/full retail hashes.
 * Falsifiable vectors: all recorded original words and complete retail SHAs.
 * Empty constraints preserve compiler scheduling; no opcode patches.
 */
void func_level_11_8007A4E4(Moby* input) {
    register Moby* owner __asm__("$18") = input;
    int dataStart;
    int animationOffset;
    int value;
    register unsigned char* statePointer0 __asm__("$16");
    register unsigned char* statePointer1 __asm__("$16");
    unsigned char state;
    register unsigned char* tag __asm__("$16");

    owner->updateDistance = 0xFF;
    tag = owner->mobyTag;
    if ((D_8006C640 > 0) && (ControllerA4E4Field(tag, int*, 0x50) == 0)) {
        dataStart = D_8006C3F4 + ControllerA4E4Field(&ControllerA4E4Data0, int*, 0x40);
        ControllerA4E4Helper4F984(
            dataStart, dataStart + ControllerA4E4Field(&ControllerA4E4Data4, unsigned short*, 0x40),
            (int)ControllerA4E4Field(&ControllerA4E4Data6, unsigned short*, 0x40));
        ControllerA4E4Field(tag, int*, 0x50) = 1;
    }
    state = owner->state;
    switch (state) { /* irregular */
        case 0:
            if ((D_8006E344 == 0xD) && (owner->substate == 0)) {
                if (D_8006C4F8 != 1) {
                    owner->state = 3;
                    statePointer0 = (unsigned char*)owner + 0x48;
                    ControllerA4E4Helper3B7B4(statePointer0, 1, &ControllerA4E4Control0);
                    ControllerA4E4Helper3B7B4(statePointer0, 1, &ControllerA4E4Control1);
                } else {
                    ControllerA4E4Vector.x = (int)(D_80065920[owner->angle.yaw] * 0xD) >> 5;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register int index __asm__("$2") = owner->angle.yaw;
                        register Vector3D* first __asm__("$4") = &ControllerA4E4Vector;
                        register Vector3D* second __asm__("$5");
                        register int sample __asm__("$3");
                        MATCHING_KEEP2_CLOBBER(index, first, "$5");
                        second = first;
                        MATCHING_KEEP3(index, first, second);
                        sample = D_800658A0[index];
                        MATCHING_KEEP_VOLATILE_CLOBBER(sample, "memory");
                        ControllerA4E4VectorZ = 0;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(sample, "memory");
                        ControllerA4E4VectorY = (sample * 13) >> 5;
                        func_8004F194(first, second, &owner->position);
                    }
                    D_8006C6E0 = ((owner->angle.yaw + 0x80) * 0x10) & 0xFFF;
                    goto initializeTag;
                }
            } else {
            initializeTag:
                owner->distanceToGround = 0;
                ControllerA4E4Field(tag, signed char*, 5) = 1;
                if ((D_8006C598 == 0) && (func_80037BBC(owner, 0) != 0)) {
                    ControllerA4E4Helper512E4(owner, 0, 0xF);
                    owner->state = 0xF;
                }
            }
            break;
        case 15:
            if (D_8006E344 != 1) {
                ControllerA4E4Field(ControllerA4E4Player, int*, 0x20C) = 0x10000002;
                D_80071575 = 1;
                ControllerA4E4Field(tag, int*, 0x48) = 0x3C;
                owner->state = 1;
                func_80034F40(owner, 1);
            }
            break;
        case 1:
            ControllerA4E4Field(ControllerA4E4Player, int*, 0x20C) = 0x10000002;
            if (func_8003585C(owner, ControllerA4E4Field(tag, int*, 0x34) + 0x80, 8, 0x10, 1, 0) !=
                0) {
                func_80035DDC(owner, 0x80, 0, 0, 0);
            }
            value = func_800359A4((unsigned char*)tag + 0x48, 4);
            statePointer1 = &owner->state;
            if (value == 2) {
                owner->state = 3;
                ControllerA4E4Helper3B7B4(statePointer1, 1, &ControllerA4E4Control0);
                ControllerA4E4Helper3B7B4(statePointer1, 1, &ControllerA4E4Control1);
                ControllerA4E4Helper3B74C(&ControllerA4E4Control0);
                owner->state = 1;
            }
            break;
        case 3:
            ControllerA4E4Header(owner, 0x41);
            D_8006C6D0 = 0;
            ControllerA4E4Helper135A4(&ControllerA4E4Camera0, &ControllerA4E4CameraSource0, 0);
            ControllerA4E4Helper135A4(&ControllerA4E4Camera1, &ControllerA4E4CameraSource1, 0);
            if (ControllerA4E4Field(ControllerA4E4Player, int*, 0x24C) == 1) {
                animationOffset = ControllerA4E4Field(ControllerA4E4Player, int*, 0x48) - 0x41;
                if (animationOffset != owner->animationState.nextId) {
                    func_80034F40(owner, animationOffset);
                }
            }
            if (ControllerA4E4Field(ControllerA4E4Player, int*, 0x50) == 10) {
                *(unsigned int*)&owner->colour =
                    -ControllerA4E4Field(ControllerA4E4Player, int*, 0xF4) & 0xFFFFFF;
                owner->colour.a = 0x80;
            } else {
                *(unsigned int*)&owner->colour = 0;
            }
            if ((unsigned int)(ControllerA4E4Field(ControllerA4E4Player, int*, 0x50) - 2) >= 2U) {
                value = ControllerA4E4Field(tag, int*, 0x48) + D_8006C648;
                ControllerA4E4Field(tag, int*, 0x48) = value;
                if (value >= 0x1771) {
                    ControllerA4E4Field(tag, int*, 0x48) = 0x1770;
                }
            }
            break;
    }
    func_80035D38(owner);
    func_8005629C(owner);
}

#undef ControllerA4E4Field

extern unsigned char D_8006C7B4;
extern int D_8006C58C, D_8006E344;
extern int ControllerA918NormalX __asm__("D_80071918");
extern int ControllerA918NormalY __asm__("D_8007191C");
extern int ControllerA918NormalZ __asm__("D_80071920");
extern unsigned char ControllerA918Saved[] __asm__("D_80070300");
extern unsigned char ControllerA918Table[] __asm__("D_80066650");
extern unsigned char* ControllerA918Output __asm__("D_8006C530");
extern Moby* ControllerA918Hit __asm__("D_80071930");
int ControllerA918Helper80018368(Vector3D*, Vector3D*) __asm__("func_80018368");
void ControllerA918Helper8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
void ControllerA918Helper8004F1C8(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void ControllerA918Helper8004F1FC(Vector3D*, Vector3D*, int) __asm__("func_8004F1FC");
void ControllerA918Helper8004F110(Vector3D*, int) __asm__("func_8004F110");
int ControllerA918Helper8004F284(int, int) __asm__("func_8004F284");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original five-state controller: 259 instructions per overlay copy.
 * Tag word +0; position increments 64 and initial offset -2048.
 * Five table vectors have a 12-byte stride; phase rises by16, clamped256.
 * State4 retains signed table division by8, angle thresholds and exact
 * unsigned collision comparisons. Original load widths and pointer lifetimes
 * are preserved. Empty compiler constraints emit no opcode patches.
 * Units, fixed-point domains, helper/table producers and caller cadence remain
 * unresolved; updates occur once per call. Existing names imply no semantics.
 * Confidence: exact compiled instructions, linked table words and retail hashes.
 * Falsifiable test: compare every original linked word and complete retail SHA.
 */
void func_level_11_8007A918(Moby* input) {
    register Moby* owner __asm__("$18") = input;
    Vector3D origin;
    Vector3D transformed;
    Vector3D direction;
    int sample;
    register int* phase __asm__("$20");
    int nextPhase;
    int nextHeight;
    register int byteOffset __asm__("$17");
    register int pointIndex __asm__("$19");
    register unsigned char* playerField __asm__("$17");
    register Vector3D* scratch __asm__("$16");
    register Vector3D* player __asm__("$16");
    unsigned char state;
    register int headingValue __asm__("$16");

    state = owner->state;
    phase = owner->mobyTag;
    switch (state) {
        case 0: {
            register int flags __asm__("$2") = D_8006C7B4;
            *phase = 0;
            if ((flags & 1) || (ControllerA918Saved[D_8006C58C] & 1)) {
                owner->state = 3;
                return;
            }
        }
            *(unsigned int*)&owner->colour = (owner->position.z & 0xFFFFFF) | 0x80000000;
            owner->position.z -= 0x800;
            *phase = -0x800;
            func_80055D24(owner, 2);
            owner->unknown3[0] = 0;
            owner->lowDrawDistance = 0;
            owner->drawn = 0;
            owner->state = 1;
            return;
        case 1:
            if ((D_8006C7B4 & 1) && (D_8006E344 == 0)) {
                register int one __asm__("$2") = 1;
                register int literal __asm__("$3");
                MATCHING_KEEP_CLOBBER(one, "$3");
                literal = 42;
                MATCHING_KEEP2(one, literal);
                owner->unknown3[0] = one;
                owner->drawn = one;
                owner->lowDrawDistance = literal;
                owner->state = 2;
                return;
            }
        default:
            return;
        case 2:
            owner->position.z += 0x40;
            nextHeight = *phase + 0x40;
            *phase = nextHeight;
            if (nextHeight >= 0) {
                owner->position.z -= nextHeight;
                *phase = 0;
                *(unsigned int*)&owner->colour = 0;
                owner->state = 3;
            }
            func_80055D24(owner, 2);
            return;
        case 3:
            ControllerA918Output[0x40] = 16;
            func_8004F178(&origin, &owner->position);
            origin.z += 0x300;
            nextPhase = *phase + 0x10;
            *phase = nextPhase;
            if (nextPhase >= 0x101) {
                *phase = 0x100;
            }
            MATCHING_BARRIER("$19");
            pointIndex = 0;
            scratch = &transformed;
            byteOffset = 0;
            do {
                ControllerA918Helper8004ED6C(
                    &owner->rotationMatrix, (Vector3D*)(ControllerA918Table + byteOffset), scratch);
                func_8004F194(scratch, scratch, &owner->position);
                ControllerA918Helper8004F1C8(scratch, scratch, &origin);
                {
                    register Vector3D* first __asm__("$4") = scratch;
                    register Vector3D* second __asm__("$5") = scratch;
                    MATCHING_KEEP2(first, second);
                    ControllerA918Helper8004F1FC(first, second, *phase);
                }
                pointIndex += 1;
                ControllerA918Helper8004F110(scratch, 8);
                func_8004F194((Vector3D*)(ControllerA918Output + byteOffset), scratch, &origin);
                byteOffset += 0xC;
            } while (pointIndex < 5);
            if (*phase >= 0x100) {
                owner->state = 4;
                return;
            }
            break;
        case 4: {
            register Vector3D* prepared __asm__("$4") = &owner->position;
            MATCHING_KEEP_CLOBBER(prepared, "$16");
            player = &spyro.position;
            if (func_8004F334(prepared, player) < 0x800) {
                if (func_8004F264((int)owner->angle.yaw,
                                  func_8004E880(spyro.position.x - owner->position.x,
                                                spyro.position.y - owner->position.y, 0)) < 0x41) {
                    register int heading __asm__("$2") = owner->angle.yaw + 128;
                    MATCHING_KEEP(heading);
                    headingValue = heading & 255;
                } else {
                    headingValue = owner->angle.yaw;
                }
                playerField = &spyro.bodyRotation.yaw;
                if (func_8004F264((int)headingValue, (int)*playerField) < 0x1F) {
                    register int index __asm__("$4") = headingValue * 2;
                    MATCHING_KEEP(index);
                    direction.x = *(short*)((char*)D_80065920 + index) / 8;
                    sample = *(short*)((char*)D_800658A0 + index);
                    scratch = &direction;
                    if (sample < 0) {
                        sample += 7;
                    }
                    {
                        register Vector3D* first __asm__("$4") = scratch;
                        register Vector3D* second __asm__("$5") = scratch;
                        MATCHING_KEEP3(first, second, playerField);
                        playerField -= 0xE;
                        direction.y = sample >> 3;
                        direction.z = 0;
                        func_8004F194(first, second, (Vector3D*)playerField);
                    }
                    if ((ControllerA918Helper80018368((Vector3D*)playerField, scratch) != 0) &&
                        (ControllerA918Hit == owner) &&
                        ((unsigned int)(ControllerA918NormalZ + 0x28) < 0x51U) &&
                        ((unsigned int)(ControllerA918Helper8004F284(
                                            func_8004E880(ControllerA918NormalX,
                                                          ControllerA918NormalY, 1),
                                            owner->angle.yaw * 0x10) -
                                        0x21) >= 0x7BFU)) {
                        func_80053F50(0);
                    }
                }
            }
        } break;
    }
}

typedef struct {
    Vector3D vector;
    int timer;
} DecodedTimedVectorRecord;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_8004EF04(Vector3D*, int);
void func_level_11_8007AD24(Moby* moby) {
    Vector3D offset;
    DecodedTimedVectorRecord* tag = moby->mobyTag;
    if (func_800359A4(&tag->timer, 4)) {
        func_80055B18(moby);
        return;
    }
    func_8004F178(&offset, &tag->vector);
    offset.z += 0x20;
    func_8004EF04(&offset, 8);
    func_8004F1C8(&tag->vector, &tag->vector, &offset);
    func_8004F194(&moby->position, &moby->position, &tag->vector);
    moby->angle.roll = *(unsigned short*)((char*)D_80065920 + ((tag->timer * 8) & 0x1F8)) >> 7;
}

extern unsigned char D_80066FCC[], D_80070300[];
void func_80021ED8(void*, int, int);
void func_80055B18(Moby*);
void func_level_11_8007ADE0(Moby* moby) {
    int* tag = moby->mobyTag;
    if (D_80070300[D_80066FCC[tag[0]]] & 1) {
        func_80021ED8((void*)tag[1], 0xFC, 0);
    }
    func_80055B18(moby);
}

typedef struct {
    int actorIndex;
    Vector3D position;
    int timer;
    int* counter;
} DecodedLinkedActor;
extern Moby* D_8006C550;
extern int D_8006C79C, D_8006C58C;
extern int D_80071AB0[][8];

extern Moby* DecodedActorCallback(Moby*, int, Vector3D*, Vector3D*) __asm__("func_80036A68");
int func_8001A358(Vector3D*, int);
void func_level_11_8007AE4C(Moby* moby) {
    DecodedLinkedActor* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (D_8006C550[tag->actorIndex].state & 0x80) {
                Moby* actor;
                int height;
                func_8004F178(&tag->position, &D_8006C550[tag->actorIndex].position);
                actor = DecodedActorCallback(moby, 1, &tag->position, &moby->position);
                if (!actor)
                    return;
                func_8004F178(&actor->position, &moby->position);
                height = func_8001A358(&actor->position, 0x400);
                if (height)
                    actor->position.z = height;
                {
                    unsigned char gem = moby->gemValue;
                    actor->state = 0;
                    actor->gemValue = gem;
                }
                func_80055B18(moby);
                return;
            }
            func_8004F178(&tag->position, &moby->position);
            func_8004F178(&moby->position, &D_8006C550[tag->actorIndex].position);
            moby->substate = *tag->counter;
            tag->timer = moby->substate * 15;
            (*tag->counter)++;
            moby->state = 1;
            break;
        case 1:
            if (D_8006C550[tag->actorIndex].mobyClass == 0xCE)
                func_8004F178(&moby->position, &D_8006C550[tag->actorIndex].position);
            if (D_8006C550[tag->actorIndex].state & 0x80)
                moby->state = 2;
            break;
        case 2:
            if (func_800359A4(&tag->timer, 4))
                moby->state = 3;
            break;
        case 3: {
            int handle;
            if (D_8006C550[tag->actorIndex].gemValue == 0xFF) {
                func_8003BA00(&D_8006C550[tag->actorIndex]);
                {
                    register int packed __asm__("$3") = tag->actorIndex;
                    register int offset __asm__("$2") = D_8006C79C;
                    register unsigned char* base __asm__("$4");
                    register int bit __asm__("$5");
                    MATCHING_KEEP2_CLOBBER(packed, offset, "$4");
                    base = (unsigned char*)D_80071AB0;
                    __asm__("" : "=r"(base) : "0"(base), "r"(packed), "r"(offset));
                    packed += offset;
                    bit = packed & 0x1F;
                    packed >>= 5;
                    {
                        register int level __asm__("$2") = D_8006C58C;
                        __asm__("" : "=r"(level) : "0"(level), "r"(packed), "r"(bit));
                        packed <<= 2;
                        level <<= 5;
                        level += (int)base;
                        packed += level;
                        __asm__("" : "=r"(packed) : "0"(packed), "r"(bit));
                        *(int*)packed |= 1 << bit;
                    }
                }
            }
            if (DecodedActorCallback(moby, 1, &moby->position, &tag->position)) {
                handle = PlaySound(((unsigned char*)D_8006C654)[0x1A], moby, 0);
                if (handle >= 0)
                    func_8003C0B0(handle, (moby->substate << 8) + 0x1000);
                func_80055B18(moby);
            }
            break;
        }
    }
}

typedef struct {
    unsigned char reserved00[0xA];
    unsigned short threshold;
    unsigned char reserved0C[4];
    unsigned char enabled;
    unsigned char reserved11[3];
} DecodedSelectorDescriptor;
typedef struct {
    unsigned char reserved00[0xC];
    unsigned char* records;
} DecodedSelectorAttachment;
typedef struct {
    int minimum, maximum, timerMinimum, timerMaximum;
    DecodedSelectorAttachment* attachment;
    int timer, handle;
} DecodedSelectorUpdate;
extern unsigned char* D_8006C708;
extern DecodedSelectorDescriptor* D_8006C6A0;
extern int D_8006E044, D_8006E028;
int func_8004F334(Vector3D*, Vector3D*);
int func_8003636C(int, int);
void func_80036518(void*, void*, int*);
void func_level_11_8007B17C(Moby* actor) {
    register Moby* moby __asm__("$17") = actor;
    register DecodedSelectorUpdate* tag __asm__("$16");
    int index;
    MATCHING_KEEP(moby);
    tag = moby->mobyTag;
    if (D_8006C6A0[D_8006C708[tag->minimum]].enabled) {
        register int distance __asm__("$2");
        register int z __asm__("$3");
        register int total __asm__("$5");
        register int* mode __asm__("$5") = &D_8006E044;
        MATCHING_KEEP(mode);
        if ((unsigned int)(*mode - 9) < 2) {
            distance = func_8004F334(&moby->position, (Vector3D*)((char*)mode - 0x24));
            {
                register int actorZ __asm__("$3") = moby->position.z;
                register int otherZ __asm__("$4") = D_8006E028;
                MATCHING_KEEP2(actorZ, otherZ);
                z = actorZ - otherZ;
            }
        } else {
            distance = func_8004F334(&moby->position, (Vector3D*)&spyro);
            {
                register int actorZ __asm__("$3") = moby->position.z;
                register int otherZ __asm__("$4") = spyro.position.z;
                MATCHING_KEEP2(actorZ, otherZ);
                z = actorZ - otherZ;
            }
        }
        if (z < 0)
            z = -z;
        __asm__("" : "=r"(z) : "0"(z), "r"(distance));
        total = z + distance;
        total = ((total << 2) - total) >> 4;
        {
            register int within __asm__("$2") =
                total < D_8006C6A0[D_8006C708[tag->minimum]].threshold;
            MATCHING_KEEP(within);
            if (within && !func_8003BFC0(moby, tag->handle))
                tag->handle = func_8003BB10(moby, tag->minimum, 4);
        }
    } else if (func_800359A4(&tag->timer, 4)) {
        register int minimum __asm__("$4") = tag->minimum;
        register int maximum __asm__("$5") = tag->maximum;
        register int selector __asm__("$18") = minimum;
        if (minimum < maximum)
            selector = func_8003636C(minimum, maximum);
        if (tag->timerMinimum < tag->timerMaximum)
            tag->timer = func_8003636C(tag->timerMinimum, tag->timerMaximum);
        else
            tag->timer = tag->timerMinimum;
        func_8003BB10(moby, selector, 0);
    }
    if (tag->attachment) {
        func_80036518(&spyro, tag->attachment, &index);
        func_8004F178(&moby->position, (Vector3D*)(tag->attachment->records + (index << 4)));
    }
}

typedef struct {
    int verticalLimit, radialLimit, selector;
    int timer, soundHandle, linkedIndex;
} DecodedProximityTag;
extern unsigned char DecodedProximityPlayer[] __asm__("D_80070328");
extern int DecodedProximityAnimation __asm__("D_80070328 + 0x48");
extern int DecodedProximityZ __asm__("D_80070328 + 8");
extern int DecodedProximityDisabled __asm__("D_80070328 + 0x244");
extern int DecodedProximityRequest __asm__("D_80070328 + 0x20C");
extern Moby* DecodedProximityOwner __asm__("D_80070328 + 0x218");
extern unsigned char* DecodedProximitySounds __asm__("D_8006C654");
extern unsigned char D_8006C7B4, D_80070300[];
extern int D_8006C58C, D_8006C640, D_8006E344;
extern Moby* D_8006C550;
extern void* (*DecodedProximityParticle)(int, int, Moby*, void*)__asm__("SpawnParticle");
int func_8004F334(Vector3D*, Vector3D*);
/* USA SCUS-94467 Rev 0: representative level11
 * 0x8007B388..0x8007B8B0, 330 words; per-copy source identity in batch1376.
 * Retain raw selector bits, states/substates, signed distance/height comparisons,
 * timer helper argument4, sound-table byte0x1D and particle IDs6/0x52.
 * Coordinates and helper results retain their retail arithmetic representation;
 * physical units, cadence and complete producer/helper semantic chains are open.
 * Particle and sound payload/event meanings are not inferred from IDs or names.
 * Empty constraints retain original register lifetimes and emit no instructions.
 * AI generated; not yet human reviewed.
 */
void func_level_11_8007B388(Moby* argument) {
    Vector3D difference;
    int kind;
    register Moby* moby __asm__("$17") = argument;
    register DecodedProximityTag* tag __asm__("$18");
    register Vector3D* position __asm__("$19");
    register int two __asm__("$20");
    register int* playerMode __asm__("$21") = (int*)(DecodedProximityPlayer + 0x50);
    register int distance __asm__("$22");
    register Vector3D* playerPosition __asm__("$23");
    MATCHING_KEEP(moby);
    MATCHING_KEEP(playerMode);
    tag = moby->mobyTag;
    if (*playerMode == 6 || DecodedProximityDisabled) {
        if (moby->state)
            moby->state = 2;
        return;
    }
    two = 2;
    MATCHING_KEEP(two);
    if (moby->state == two)
        moby->state = 1;
    playerPosition = (Vector3D*)((char*)playerMode - 0x50);
    kind = tag->selector & 0x7F;
    position = &moby->position;
    func_8004F1C8(&difference, playerPosition, position);
    distance = func_8004EDE8(&difference, 0);
    /* Shared state transitions preserve the original dispatch/jump structure. */
    if (!kind)
        goto activate;
    {
        register int one __asm__("$4") = 1;
        register int substate __asm__("$3");
        register int condition __asm__("$2");
        MATCHING_KEEP(one);
        if (kind == one) {
            substate = moby->substate;
            if (substate == kind)
                goto kindOneWaiting;
            if (substate < 2) {
                if (!substate)
                    goto kindOneInitial;
                goto update;
            }
            if (substate == two)
                goto kindOneActive;
            if (substate == 3)
                goto kindOneFinished;
            goto update;
        kindOneInitial:
            if (distance < tag->radialLimit + 0x400 && ABS(difference.z) < 0x400) {
                tag->timer = 60;
                moby->substate = 1;
            }
            goto update;
        kindOneWaiting:
            if (!func_800359A4(&tag->timer, 4))
                goto update;
            goto secondSubstate;
        kindOneActive:
            if (DecodedProximityAnimation != 19)
                goto update;
            goto thirdSubstate;
        kindOneFinished:
            if (DecodedProximityAnimation != 19 && func_800359A4(&tag->timer, 4)) {
                moby->substate = 0;
                moby->state = 0;
            }
            goto update;
        } else if (kind == 3) {
            substate = moby->substate;
            if (substate == one)
                goto kindThreeWaiting;
            if (substate < 2) {
                if (!substate)
                    goto kindThreeInitial;
                goto update;
            }
            if (substate == two)
                goto kindThreeActive;
            if (substate == kind)
                goto kindThreeFinished;
            goto update;
        kindThreeInitial:
            if (distance <= tag->radialLimit + 0x800 || distance >= 0x2000)
                goto update;
            condition = ABS(difference.z) < 0x400;
            goto checkSecond;
        kindThreeWaiting:
            condition = distance > tag->radialLimit + 0x800;
        checkSecond:
            if (!condition)
                goto update;
        timedSecond:
            tag->timer = 60;
        secondSubstate:
            moby->substate = 2;
        activate:
            moby->state = 1;
            goto update;
        kindThreeActive:
            if (DecodedProximityAnimation != 19 && distance <= 0x2800 &&
                DecodedProximityZ - moby->position.z <= 0xC00)
                goto update;
        thirdSubstate:
            tag->timer = 60;
            moby->substate = 3;
            goto update;
        kindThreeFinished:
            if (playerMode[-2] != 19 && func_800359A4(&tag->timer, 4)) {
                moby->substate = 0;
                moby->state = 0;
            }
            goto update;
        }
    }
    if (kind == 4) {
        if ((D_8006C7B4 & 1) || (D_80070300[D_8006C58C] & 1)) {
            if (func_8004F334(position, playerPosition) > 0x800 && D_8006C640 > 0)
                goto clearKind;
        }
    } else if (kind == 5) {
        if (tag->linkedIndex != -1 && D_8006C550[tag->linkedIndex].state >= 0x80)
            goto clearKind;
    }
    goto update;
clearKind:
    tag->selector &= 0x80;
update:
    /* Active/inactive sound-handle paths and both callbacks retain retail order. */
    MATCHING_OBSERVE(two);
    if (moby->state) {
        if (!func_8003BFC0(moby, tag->soundHandle))
            tag->soundHandle = PlaySound(DecodedProximitySounds[0x1D], moby, 4);
        if (!(D_8006C640 & 1))
            DecodedProximityParticle(1, 6, moby, 0);
        DecodedProximityParticle(1, 0x52, moby, 0);
        if (DecodedProximityAnimation != 19 && distance < tag->radialLimit && !D_8006E344 &&
            difference.z >= -0x3FF && difference.z < tag->verticalLimit &&
            DecodedProximityZ + 0xC00 < moby->position.z + tag->verticalLimit) {
            DecodedProximityRequest = 0x10000020;
            DecodedProximityOwner = moby;
            MATCHING_OBSERVE2(tag, distance);
        }
    } else {
        if (func_8003BFC0(moby, tag->soundHandle)) {
            func_8003BE70(tag->soundHandle);
            tag->soundHandle = -1;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007B8B0.
* Assembly SHA256 eb5d9241a81c2d807b35077895ce3e027135de04ed570f4d6df02aae7d0f1aa3.
* AI generated; not human reviewed. All823 instructions,
* six selector words and actual targets are required. Original frame0x80
* retains all original saved words and full SP18..67 local extent.
* The823 base has independently decoded891/922 deltas:the original68-word
* insertion and2440 global literal in891;initialized S5,timer/two36220 calls,
* original2000 global literal and hook arguments in922. No target identity
* follows from similarity alone. Full target-native/control/data gates apply.
* Sequential S0 angle roles copy the first value to A0 before overwriting S0.
* Signed input/clamps,word handles at+15C,stored halfword handles followed by
* original SLL/SRA into A0,and complete low products preserve their domains.
* Stack source bases change from S0/SP38 to S0/SP58;the independent S3/SP48
* source remains separate. The first collision has two physical entries:
* one initializes A0 and the other retains its already prepared value.
* Shared countdown/state3 exit and three hook joins preserve actual targets.
* Empty initialized identities,late consumers,dead clobbers and compiler
* memory barriers emit zero CPU instructions. No opcode assembly,partialHI,
* FP shortcut or live-alias overlap. Confidence is binary identity after
* all gates. Raw units/fixed point,complete helper contracts,caller cadence
* and synchronized retail runtime remain open. Cadence is per invocation.
* Falsification:every native/linked word,actual transfer/table target,owned
* data byte,EXE and every overlay retail hash. */
#define Actor11_7B8B0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor11_7B8B0Call18368View1() __asm__("func_80018368");
int Actor11_7B8B0Call19194View1() __asm__("func_80019194");
int Actor11_7B8B0Call1BA30View1() __asm__("func_8001BA30");
int Actor11_7B8B0Call1C288View1() __asm__("func_8001C288");
int Actor11_7B8B0SetMobyAnimationView1() __asm__("func_80034F80");
int Actor11_7B8B0CountTimerDownView1() __asm__("func_800359A4");
int Actor11_7B8B0Call369B8View1() __asm__("func_800369B8");
int Actor11_7B8B0PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor11_7B8B0Call3BE70View1() __asm__("func_8003BE70");
int Actor11_7B8B0Call3BFC0View1() __asm__("func_8003BFC0");
int Actor11_7B8B0Call3C0B0View1() __asm__("func_8003C0B0");
int Actor11_7B8B0Call3C140View1() __asm__("func_8003C140");
int Actor11_7B8B0PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor11_7B8B0TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Actor11_7B8B0MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Actor11_7B8B0Call4EF74View1() __asm__("func_8004EF74");
int Actor11_7B8B0ClearVectorView1() __asm__("func_8004F168");
int Actor11_7B8B0CopyVectorView1() __asm__("func_8004F178");
int Actor11_7B8B0AddVectorView1() __asm__("func_8004F194");
int Actor11_7B8B0SubtractVectorView1() __asm__("func_8004F1C8");
int Actor11_7B8B0Absolute12BitAngleDeltaView1() __asm__("func_8004F284");
int Actor11_7B8B0ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor11_7B8B0RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor11_7B8B0InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Actor11_7B8B0Data658A0View1 __asm__("D_800658A0");
extern int Actor11_7B8B0Data65920View1 __asm__("D_80065920");
extern int Actor11_7B8B0Data6C550View1 __asm__("D_8006C550");
extern int Actor11_7B8B0Data6C700View1 __asm__("D_8006C700");
extern short Actor11_7B8B0Data6E03EView1 __asm__("D_8006E03E");
extern short Actor11_7B8B0Data6E040View1 __asm__("D_8006E040");
extern int Actor11_7B8B0Data70328View1 __asm__("D_80070328");
extern int Actor11_7B8B0Data71918View1 __asm__("D_80071918");
extern int Actor11_7B8B0Datag_CheatFlagsView1 __asm__("g_CheatFlags");
extern void* (*Actor11_7B8B0DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor11_7B8B0Data7443CView1)() __asm__("unk_ovlheader_8007443C");
extern int (*Actor11_7B8B0Data74444View1)() __asm__("unk_ovlheader_80074444");
void func_level_11_8007B8B0(void* input) {
    register void* ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int retainedAngleOrAddress16 __asm__("$16"), privateRecord17 __asm__("$17"),
        secondaryResult20 __asm__("$20"), retainedStackAddress19 __asm__("$19");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64;
    } originalFrame;
    ownerRecord18 = input;
    MATCHING_KEEP(ownerRecord18);
    privateRecord17 = Actor11_7B8B0Field(ownerRecord18, void**, 0);
    if ((unsigned int)(Actor11_7B8B0Field(privateRecord17, int*, 0) - 1) < 2U) {
        if ((Actor11_7B8B0Field(privateRecord17, void**, 0x2C) != 0) ||
            ((rawWord3 = Actor11_7B8B0DataSpawnMobyView1(0x1CE, ownerRecord18),
              Actor11_7B8B0Field(privateRecord17, void**, 0x2C) = rawWord3, (rawWord3 != 0)) &&
             (Actor11_7B8B0Field(rawWord3, int*, 20) = Actor11_7B8B0Field(rawWord3, int*, 20) + 512,
              Actor11_7B8B0Field(Actor11_7B8B0Field(privateRecord17, void**, 0x2C), signed char*,
                                 0x45) = 0x30,
              (Actor11_7B8B0Field(privateRecord17, void**, 0x2C) != 0)))) {
            rawWord3 = Actor11_7B8B0Field(privateRecord17, void**, 0x2C);
            Actor11_7B8B0Field(rawWord3, unsigned char*, 0x46) =
                (unsigned char)(Actor11_7B8B0Field(rawWord3, unsigned char*, 0x46) + 8);
        }
        if (Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48) != 6) {
            if (Actor11_7B8B0Call3BFC0View1(
                    ownerRecord18, Actor11_7B8B0Field(privateRecord17, short*, 0x28)) == 0) {
                Actor11_7B8B0Field(privateRecord17, short*, 0x28) =
                    Actor11_7B8B0PlayMobySoundEventView1(ownerRecord18, 3, 4);
            }
            if ((Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48) != 6) &&
                (Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                     Actor11_7B8B0Data6C550View1),
                                    unsigned char*, 0x48) != 1) &&
                (retainedAngleOrAddress16 = ownerRecord18 + 0xC,
                 (((unsigned int)(Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x50) -
                                  7) < 2U) == 0)) &&
                (Actor11_7B8B0ApproximatePlanarDistanceView1(
                     retainedAngleOrAddress16, (&Actor11_7B8B0Data70328View1 + 0x50) - 0x50) <
                 0x400)) {
                rawWord2 = (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 8) -
                            Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x44)) -
                           Actor11_7B8B0Field(ownerRecord18, int*, 0x14);
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if (rawWord2 < 0x140) {
                    Actor11_7B8B0CopyVectorView1(
                        Actor11_7B8B0Data6C550View1 +
                            (Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) + 0xC,
                        retainedAngleOrAddress16);
                    Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                        Actor11_7B8B0Data6C550View1),
                                       signed char*, 0x44) = 0;
                    Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                        Actor11_7B8B0Data6C550View1),
                                       signed char*, 0x45) = 0;
                    Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                        Actor11_7B8B0Data6C550View1),
                                       unsigned char*, 0x46) =
                        (unsigned char)Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1,
                                                          unsigned char*, 0xE);
                    Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                        Actor11_7B8B0Data6C550View1),
                                       signed char*, 0x4C) = 0x20;
                    Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                        Actor11_7B8B0Data6C550View1),
                                       signed char*, 0x48) = 4;
                    Actor11_7B8B0Call369B8View1(
                        Actor11_7B8B0Data6C550View1 +
                            (Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58),
                        0x18);
                    Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x23C) = 0x24;
                    Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x20C) =
                        (int)(Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x20C) |
                              0x10000080);
                    Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, void**, 0x250) =
                        (void*)(Actor11_7B8B0Data6C550View1 +
                                (Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58));
                    Actor11_7B8B0Field(((Actor11_7B8B0Field(privateRecord17, int*, 4) * 0x58) +
                                        Actor11_7B8B0Data6C550View1),
                                       signed char*, 0x48) = 4;
                    Actor11_7B8B0Data6C700View1 = 0x2000;
                }
            }
        }
    } else {
        if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x50) == 0x13) {
            if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x4C) == 5) {
                Actor11_7B8B0Field(privateRecord17, short*, 0xF0) = 3;
            } else if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x4C) == 4) {
                Actor11_7B8B0Field(privateRecord17, short*, 0xF0) = 2;
            } else {
                Actor11_7B8B0Field(privateRecord17, short*, 0xF0) = 1;
            }
        } else {
            Actor11_7B8B0Field(privateRecord17, short*, 0xF0) = 0;
        }
        rawWord3 = Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48);
        switch (rawWord3) {
            case 0:
                rawWord3 = Actor11_7B8B0Field(ownerRecord18, short*, 0x36);
                if ((rawWord3 == 0x36) || (rawWord3 == 0x294) || (rawWord3 == 0xFB)) {
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x41) = 0;
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x4C) = 0;
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x4D) = 0;
                    goto prepareHookArgument4;
                }
                argumentWord4 = 0;
                goto prepareHookArgument5;
            default:
                argumentWord4 = 0;
                goto prepareHookArgument5;
            case 4:
                if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x50) == 0x13) {
                    Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48) = 1U;
                }
                argumentWord4 = 0;
                goto prepareHookArgument5;
            case 1:
                Actor11_7B8B0ClearVectorView1(&originalFrame.sp18);
                originalFrame.sp20 = -0x400;
                Actor11_7B8B0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 4);
                Actor11_7B8B0TransformVectorByBasisView1(ownerRecord18 + 0x20, &originalFrame.sp18,
                                                         &originalFrame.sp18);
                rawWord2 = Actor11_7B8B0PlanarHeadingLookupView1(
                    Actor11_7B8B0MeasureVectorLengthView1(&originalFrame.sp18, 0),
                    originalFrame.sp20, 1);
                argumentWord6 = 1;
                MATCHING_OBSERVE_CLOBBER(argumentWord6, "$16");
                retainedAngleOrAddress16 = rawWord2;
                rawWord2 = Actor11_7B8B0PlanarHeadingLookupView1(originalFrame.sp18,
                                                                 originalFrame.sp1C, argumentWord6);
                argumentWord4 = retainedAngleOrAddress16;
                rawWord3 = 4;
                retainedAngleOrAddress16 = rawWord2 + 0x800;
                Actor11_7B8B0Field(ownerRecord18, signed char*, 0x47) = rawWord3;
                argumentWord5 = Actor11_7B8B0Data6E03EView1;
                retainedAngleOrAddress16 &= 0xFFF;
                rawWord2 = Actor11_7B8B0Absolute12BitAngleDeltaView1(argumentWord4, argumentWord5);
                argumentWord4 = retainedAngleOrAddress16;
                argumentWord5 = Actor11_7B8B0Data6E040View1;
                retainedAngleOrAddress16 = rawWord2;
                rawWord2 = Actor11_7B8B0Absolute12BitAngleDeltaView1(argumentWord4, argumentWord5);
                retainedAngleOrAddress16 = retainedAngleOrAddress16 < 600;
                rawWord2 = rawWord2 < 600;
                if (retainedAngleOrAddress16 && rawWord2) {
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x47) = 9;
                }
                rawWord2 =
                    Actor11_7B8B0Field(&Actor11_7B8B0Datag_CheatFlagsView1, unsigned char*, 1);
                argumentWord4 = (int)ownerRecord18;
                if (rawWord2) {
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord2, "$5");
                    argumentWord5 = 1;
                } else {
                    MATCHING_BARRIER_GNU_VOLATILE("$2");
                    argumentWord5 = 0;
                    MATCHING_KEEP(argumentWord5);
                }
                Actor11_7B8B0SetMobyAnimationView1(argumentWord4, argumentWord5);
                if (Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x3D) == 0) {
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x41) = 0;
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x3E) = 0;
                    argumentWord5 = 0;
                    if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0xB8) == 0) {
                        argumentWord5 =
                            Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, unsigned char*, 0xC);
                    }
                    if ((int)argumentWord5 >= 0x81) {
                        argumentWord5 -= 0x100;
                    }
                    if (argumentWord5 <= 0)
                        goto clampNonPositiveInput;
                    rawWord2 = argumentWord5 < 16;
                    if (rawWord2) {
                        rawWord2 = 1;
                        goto storeInputBytes;
                    }
                    rawWord2 = 1;
                    argumentWord5 = 15;
                    goto storeInputBytes;
                clampNonPositiveInput:
                    argumentWord5 = -argumentWord5;
                    rawWord2 = argumentWord5 < 16;
                    if (rawWord2) {
                        rawWord2 = 2;
                        goto storeInputBytes;
                    }
                    rawWord2 = 2;
                    argumentWord5 = 15;
                storeInputBytes:
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x3F) = rawWord2;
                    rawWord2 = argumentWord5 & 15;
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x40) = rawWord2;
                } else {
                    Actor11_7B8B0Field(ownerRecord18, signed char*, 0x41) = 1;
                }
                if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0xB8) != 0) {
                    if (Actor11_7B8B0Call3BFC0View1(
                            ownerRecord18, Actor11_7B8B0Field(privateRecord17, short*, 0x28)) !=
                        0) {
                        Actor11_7B8B0Call3BE70View1(
                            Actor11_7B8B0Field(privateRecord17, short*, 0x28));
                    }
                    Actor11_7B8B0Field(privateRecord17, short*, 0x28) = -1;
                } else {
                    if (Actor11_7B8B0Call3BFC0View1(
                            ownerRecord18, Actor11_7B8B0Field(privateRecord17, short*, 0x28)) ==
                        0) {
                        Actor11_7B8B0Field(privateRecord17, short*, 0x28) =
                            Actor11_7B8B0PlayMobySoundEventView1(ownerRecord18, 0, 4);
                    }
                    argumentWord4 = Actor11_7B8B0Field(privateRecord17, short*, 0x28);
                    if (argumentWord4 >= 0) {
                        rawWord2 = Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x5C);
                        argumentWord5 = rawWord2 & 0xFFF;
                        if (argumentWord5 >= 0x801) {
                            argumentWord5 -= 0x1000;
                        }
                        argumentWord5 = argumentWord5 * 4;
                        if (argumentWord5 < 0) {
                            argumentWord5 = -argumentWord5;
                        }
                        Actor11_7B8B0Call3C0B0View1(argumentWord4, argumentWord5 + 0x1000);
                    }
                }
                if (Actor11_7B8B0Field(privateRecord17, int*, 0xC) != 0) {
                    if ((unsigned int)(Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*,
                                                          0x4C) -
                                       4) >= 2U) {
                        Actor11_7B8B0Field(privateRecord17, int*, 0xC) = 0;
                    }
                } else if ((unsigned int)(Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*,
                                                             0x4C) -
                                          4) < 2U) {
                    argumentWord4 = privateRecord17 + 100;
                    rawWord3 = (int)Actor11_7B8B0Data74444View1;
                    rawWord2 = 1;
                    Actor11_7B8B0Field(privateRecord17, int*, 12) = rawWord2;
                    ((int (*)())rawWord3)(argumentWord4);
                }
                Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, void**, 0x250) = ownerRecord18;
                if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x50) != 0x13) {
                    argumentWord5 = privateRecord17 + 0x64;
                    if (Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x240) == 0) {
                        Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x49) = 0U;
                        Actor11_7B8B0Field(privateRecord17, short*, 0x22) = 0x1E;
                        Actor11_7B8B0Field(privateRecord17, short*, 0x20) = 0x78;
                        Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26) = 0U;
                        Actor11_7B8B0Field(privateRecord17, short*, 0x24) = 0xC;
                        rawWord2 =
                            Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, unsigned char*, 14);
                        argumentWord4 = (int)ownerRecord18;
                        rawWord2 += 128;
                        rawWord2 &= 255;
                        rawWord2 <<= 1;
                        rawWord3 =
                            Actor11_7B8B0Field(&Actor11_7B8B0Data65920View1, short*, rawWord2);
                        argumentWord5 = 4;
                        rawWord2 = rawWord3 * 25;
                        rawWord2 >>= 9;
                        Actor11_7B8B0Field(privateRecord17, int*, 20) = rawWord2;
                        rawWord2 =
                            Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, unsigned char*, 14);
                        argumentWord6 = 0;
                        rawWord2 += 128;
                        rawWord2 &= 255;
                        rawWord2 <<= 1;
                        rawWord3 =
                            Actor11_7B8B0Field(&Actor11_7B8B0Data658A0View1, short*, rawWord2);
                        rawWord2 = 125;
                        Actor11_7B8B0Field(privateRecord17, int*, 28) = rawWord2;
                        rawWord2 = rawWord3 * 25;
                        rawWord2 >>= 9;
                        Actor11_7B8B0Field(privateRecord17, int*, 24) = rawWord2;
                        Actor11_7B8B0PlayMobySoundEventView1(argumentWord4, argumentWord5,
                                                             argumentWord6);
                        Actor11_7B8B0Field(privateRecord17, short*, 0x2A) = -1;
                        Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48) = 2U;
                        if (Actor11_7B8B0Call3BFC0View1(
                                ownerRecord18, Actor11_7B8B0Field(privateRecord17, int*, 0x15C)) !=
                            0) {
                            Actor11_7B8B0Call3BE70View1(
                                Actor11_7B8B0Field(privateRecord17, int*, 0x15C));
                        }
                        Actor11_7B8B0Field(privateRecord17, int*, 0x15C) = -1;
                        if (Actor11_7B8B0Call3BFC0View1(
                                ownerRecord18, Actor11_7B8B0Field(privateRecord17, short*, 0x28)) !=
                            0) {
                            Actor11_7B8B0Call3BE70View1(
                                Actor11_7B8B0Field(privateRecord17, short*, 0x28));
                        }
                        Actor11_7B8B0Field(privateRecord17, short*, 0x28) = -1;
                        goto prepareHookArgument4;
                    }
                } else {
                    argumentWord4 = 0;
                    goto prepareHookArgument5;
                }
                argumentWord4 = 0;
                goto callSharedHook;
            case 3:
                Actor11_7B8B0Call369B8View1(ownerRecord18, 0x18);
                Actor11_7B8B0Field(ownerRecord18, signed char*, 0x4D) = 0;
                Actor11_7B8B0Field(ownerRecord18, signed char*, 0x4C) = 0;
                Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48) = 0U;
                goto prepareHookArgument4;
            case 2:
                argumentWord4 = (int)&originalFrame.sp28;
                MATCHING_OBSERVE_CLOBBER(argumentWord4, "$16");
                retainedAngleOrAddress16 = (int)ownerRecord18 + 12;
                Actor11_7B8B0CopyVectorView1(argumentWord4, retainedAngleOrAddress16);
                if (Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x49) != 0) {
                    argumentWord6 =
                        (unsigned char)Actor11_7B8B0Field(privateRecord17, short*, 0x24);
                    Actor11_7B8B0Field(privateRecord17, int*, 0x1C) =
                        (int)(Actor11_7B8B0Field(privateRecord17, int*, 0x1C) - 0xC);
                    Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x45) =
                        (unsigned char)(Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x45) +
                                        argumentWord6);
                    Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x44) =
                        (unsigned char)(Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x44) +
                                        8);
                    Actor11_7B8B0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 4,
                                                                     argumentWord6);
                    if ((Actor11_7B8B0Field(ownerRecord18, int*, 0xC) >= 0x400) &&
                        (Actor11_7B8B0Field(ownerRecord18, int*, 0x10) >= 0x400) &&
                        (Actor11_7B8B0Field(ownerRecord18, int*, 0x14) >= 0x400)) {
                        Actor11_7B8B0AddVectorView1(retainedAngleOrAddress16,
                                                    retainedAngleOrAddress16,
                                                    privateRecord17 + 0x14);
                        goto prepareState2Sources;
                    }
                    goto storeState3AndReturn;
                }
            prepareState2Sources:
                Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x49) = 1;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(ownerRecord18, "$16");
                argumentWord4 = (int)ownerRecord18;
                argumentWord5 = 0;
                MATCHING_OBSERVE2_CLOBBER(argumentWord4, argumentWord5, "$16");
                retainedAngleOrAddress16 = (int)&originalFrame.sp38;
                Actor11_7B8B0InterpolateMobyVertexView1(argumentWord4, argumentWord5,
                                                        retainedAngleOrAddress16);
                retainedStackAddress19 = (int)&originalFrame.sp48;
                Actor11_7B8B0InterpolateMobyVertexView1(ownerRecord18, 1, retainedStackAddress19);
                secondaryResult20 = 0;
                if (Actor11_7B8B0CountTimerDownView1(privateRecord17 + 0x22, 2) != 0) {
                    if ((Actor11_7B8B0Call1C288View1(retainedAngleOrAddress16, 0x64, 0) != 0) ||
                        (rawWord2 = Actor11_7B8B0Call1C288View1(retainedStackAddress19, 0x64, 0),
                         secondaryResult20 = rawWord2 != 0, (rawWord2 != 0))) {
                        rawWord2 = Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26);
                        rawWord2 += 1;
                        MATCHING_KEEP(rawWord2);
                        Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26) = rawWord2;
                        if (secondaryResult20 != 0) {
                            rawWord2 = -0xC;
                        } else {
                            MATCHING_BARRIER_GNU_VOLATILE("$2");
                            rawWord2 = 12;
                        }
                        Actor11_7B8B0Field(privateRecord17, short*, 0x24) = rawWord2;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        Actor11_7B8B0Field(&Actor11_7B8B0Data70328View1, int*, 0x298) =
                            Actor11_7B8B0PlanarHeadingLookupView1(
                                Actor11_7B8B0Field(privateRecord17, int*, 0x14),
                                Actor11_7B8B0Field(privateRecord17, int*, 0x18), 0);
                        (retainedAngleOrAddress16 = (int)&originalFrame.sp58,
                         Actor11_7B8B0SubtractVectorView1(
                             retainedAngleOrAddress16, ownerRecord18 + 0xC,
                             (&Actor11_7B8B0Data70328View1 + 0x298) - 0x298));
                        argumentWord4 = privateRecord17 + 0x14;
                        rawWord2 = Actor11_7B8B0Call4EF74View1(
                            argumentWord4, retainedAngleOrAddress16, argumentWord4);
                        argumentWord4 = (int)ownerRecord18;
                        if (rawWord2) {
                            Actor11_7B8B0Field(privateRecord17, int*, 0x14) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x14) * 6) >>
                                      3);
                            Actor11_7B8B0Field(privateRecord17, int*, 0x18) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x18) * 6) >>
                                      3);
                            Actor11_7B8B0Field(privateRecord17, int*, 0x1C) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x1C) * 6) >>
                                      3);
                            rawWord2 = Actor11_7B8B0Call3BFC0View1(
                                argumentWord4, Actor11_7B8B0Field(privateRecord17, short*, 0x2A));
                            argumentWord4 = (int)&originalFrame.sp38;
                            if (rawWord2)
                                goto callFirstCollisionWithPreparedA0;
                            {
                                MATCHING_BARRIER_GNU_VOLATILE("$2");
                                rawWord2 =
                                    Actor11_7B8B0PlayMobySoundEventView1(ownerRecord18, 4, 0);
                                Actor11_7B8B0Field(privateRecord17, short*, 0x2A) = rawWord2;
                                rawWord2 = (unsigned int)rawWord2 << 16;
                                argumentWord4 = rawWord2 >> 16;
                                if (argumentWord4 >= 0) {
                                    rawWord2 = Actor11_7B8B0Field(privateRecord17, int*, 0x1C);
                                    if (rawWord2 < 0) {
                                        rawWord2 = -rawWord2;
                                    }
                                    Actor11_7B8B0Call3C140View1(argumentWord4, rawWord2 * 40);
                                }
                            }
                        }
                    }
                prepareFirstCollisionStack:
                    MATCHING_BARRIER_GNU_VOLATILE("$4");
                    argumentWord4 = (int)&originalFrame.sp38;
                callFirstCollisionWithPreparedA0:
                    argumentWord5 = 150;
                    argumentWord6 = Actor11_7B8B0Call1BA30View1(argumentWord4, argumentWord5, 1, 0,
                                                                0x10000000, ownerRecord18);
                    argumentWord4 = (int)&originalFrame.sp48;
                    if (argumentWord6 == 0) {
                        MATCHING_OBSERVE_CLOBBER(argumentWord4, "$5");
                        argumentWord5 = 150;
                        argumentWord6 = Actor11_7B8B0Call1BA30View1(argumentWord4, argumentWord5, 1,
                                                                    0, 0x10000000, ownerRecord18);
                        argumentWord4 = privateRecord17 + 0x20;
                        if (argumentWord6 != 0) {
                            secondaryResult20 = 1;
                            goto handleSecondCollisionResult;
                        }
                    } else {
                    handleSecondCollisionResult:
                        rawWord2 = Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26);
                        rawWord2 += 1;
                        MATCHING_KEEP(rawWord2);
                        Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26) = rawWord2;
                        if (secondaryResult20 != 0) {
                            rawWord2 = -0xC;
                        } else {
                            MATCHING_BARRIER_GNU_VOLATILE("$2");
                            rawWord2 = 12;
                        }
                        Actor11_7B8B0Field(privateRecord17, short*, 0x24) = rawWord2;
                        retainedAngleOrAddress16 = (int)&originalFrame.sp58;
                        Actor11_7B8B0SubtractVectorView1(retainedAngleOrAddress16,
                                                         ownerRecord18 + 12, argumentWord6 + 12);
                        argumentWord4 = privateRecord17 + 0x14;
                        if (Actor11_7B8B0Call4EF74View1(argumentWord4, retainedAngleOrAddress16,
                                                        argumentWord4) != 0) {
                            Actor11_7B8B0Field(privateRecord17, int*, 0x14) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x14) * 6) >>
                                      3);
                            Actor11_7B8B0Field(privateRecord17, int*, 0x18) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x18) * 6) >>
                                      3);
                            Actor11_7B8B0Field(privateRecord17, int*, 0x1C) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x1C) * 6) >>
                                      3);
                            argumentWord4 = privateRecord17 + 0x20;
                            rawWord2 = Actor11_7B8B0Call3BFC0View1(
                                ownerRecord18, Actor11_7B8B0Field(privateRecord17, short*, 0x2A));
                            argumentWord4 = privateRecord17 + 32;
                            if (rawWord2)
                                goto callState2CountdownHelper;
                            {
                                MATCHING_BARRIER_GNU_VOLATILE("$2");
                                rawWord2 =
                                    Actor11_7B8B0PlayMobySoundEventView1(ownerRecord18, 4, 0);
                                Actor11_7B8B0Field(privateRecord17, short*, 0x2A) = rawWord2;
                                rawWord2 = (unsigned int)rawWord2 << 16;
                                argumentWord4 = rawWord2 >> 16;
                                if (argumentWord4 >= 0) {
                                    rawWord2 = Actor11_7B8B0Field(privateRecord17, int*, 0x1C);
                                    if (rawWord2 < 0) {
                                        rawWord2 = -rawWord2;
                                    }
                                    Actor11_7B8B0Call3C140View1(argumentWord4, rawWord2 * 40);
                                }
                                goto prepareState2Countdown;
                            }
                        } else {
                            goto prepareState2Countdown;
                        }
                    }
                } else {
                prepareState2Countdown:
                    argumentWord4 = privateRecord17 + 0x20;
                }
            callState2CountdownHelper:
                if (Actor11_7B8B0CountTimerDownView1(argumentWord4, 2))
                    goto storeState3AndReturn;
                rawWord2 = Actor11_7B8B0Field(privateRecord17, short*, 0x26);
                rawWord2 = rawWord2 < 31;
                if (rawWord2)
                    goto probeState2SurfaceSources;
            storeState3AndReturn:
                rawWord2 = 3;
                Actor11_7B8B0Field(ownerRecord18, unsigned char*, 0x48) = rawWord2;
                return;
            probeState2SurfaceSources:
                {
                    if (Actor11_7B8B0Call19194View1(&originalFrame.sp38, 0x96) == 0) {
                        if (Actor11_7B8B0Call19194View1(&originalFrame.sp48, 0x96) != 0) {
                            secondaryResult20 = 1;
                            goto handleSurfaceResult;
                        }
                        if (Actor11_7B8B0Call18368View1(&originalFrame.sp28, ownerRecord18 + 0xC) !=
                            0) {
                            goto handleSurfaceResult;
                        }
                    } else {
                    handleSurfaceResult:
                        rawWord2 = Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26);
                        rawWord2 += 1;
                        MATCHING_KEEP(rawWord2);
                        Actor11_7B8B0Field(privateRecord17, unsigned short*, 0x26) = rawWord2;
                        if (secondaryResult20 != 0) {
                            rawWord2 = -0xC;
                        } else {
                            MATCHING_BARRIER_GNU_VOLATILE("$2");
                            rawWord2 = 12;
                        }
                        Actor11_7B8B0Field(privateRecord17, short*, 0x24) = rawWord2;
                        argumentWord4 = privateRecord17 + 0x14;
                        if (Actor11_7B8B0Call4EF74View1(argumentWord4, &Actor11_7B8B0Data71918View1,
                                                        argumentWord4) != 0) {
                            Actor11_7B8B0Field(privateRecord17, int*, 0x14) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x14) * 6) >>
                                      3);
                            Actor11_7B8B0Field(privateRecord17, int*, 0x18) =
                                (int)((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x18) * 6) >>
                                      3);
                            Actor11_7B8B0Field(privateRecord17, int*, 0x1C) =
                                (int)(((int)(Actor11_7B8B0Field(privateRecord17, int*, 0x1C) * 6) >>
                                       3) +
                                      0x14);
                            if (Actor11_7B8B0Call3BFC0View1(
                                    ownerRecord18,
                                    Actor11_7B8B0Field(privateRecord17, short*, 0x2A)) == 0) {
                                rawWord2 =
                                    Actor11_7B8B0PlayMobySoundEventView1(ownerRecord18, 4, 0);
                                Actor11_7B8B0Field(privateRecord17, short*, 0x2A) = rawWord2;
                                rawWord2 = (unsigned int)rawWord2 << 16;
                                argumentWord4 = rawWord2 >> 16;
                                if (argumentWord4 >= 0) {
                                    rawWord2 = Actor11_7B8B0Field(privateRecord17, int*, 0x1C);
                                    if (rawWord2 < 0) {
                                        rawWord2 = -rawWord2;
                                    }
                                    Actor11_7B8B0Call3C140View1(argumentWord4, rawWord2 * 40);
                                }
                            }
                        }
                    }
                    argumentWord4 = 0;
                    goto prepareHookArgument5;
                }
        }
    }
    return;
prepareHookArgument4:
    argumentWord4 = 0;
prepareHookArgument5:
    argumentWord5 = privateRecord17 + 0x64;
callSharedHook:
    Actor11_7B8B0Data7443CView1(argumentWord4, argumentWord5, 0);
}
#undef Actor11_7B8B0Field

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
void func_level_11_8007C58C(void* input) {
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
                    if (Controller821F8Field(tag, short*, 0) == 0 ||
                        Controller821F8Field(tag, short*, 0) == 5) {
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

extern void func_80039714(Moby*);

/**
 * MobyUpdate_501() - func_level_11_8007D728()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_11_8007D728(Moby* moby) {
    func_80039714(moby);
}

Moby* DecodedDamageFragments(int, int, Moby*, int, int, int, int) __asm__("func_800391E8");
void DecodedDamageAnimation(Moby*) __asm__("func_80039714");
int rand(void);
void func_level_11_8007D748(Moby* moby) {
    Vector3D velocity;
    Moby* spawned;
    void* tag;
    int index;
    if (moby->animationState.id == 1) {
        DecodedDamageAnimation(moby);
    } else if (moby->damageFlags & 0x10000) {
        index = 0;
        do {
            spawned = DecodedDamageFragments(1, moby->mobyClass, moby, 1, 1, 0x20, 0x100);
            if (spawned) {
                tag = spawned->mobyTag;
                *(short*)((char*)tag + 4) += 0x32;
                *(short*)((char*)tag + 0xC) = *(short*)((char*)tag + 0xC) >> 1;
                spawned->colour.r = 0;
                spawned->colour.g = 0;
                spawned->colour.b = 0;
                spawned->colour.a = 0x3F;
            }
            velocity.x = (rand() & 0xF) - 8;
            velocity.y = (rand() & 0xF) - 8;
            velocity.z = (rand() & 0xF) + 8;
            SpawnParticle(1, 0x37, &moby->position, &velocity);
            index++;
        } while (index < 7);
        func_80055B18(moby);
    } else if (moby->damageFlags & 0x20000) {
        DecodedDamageFragments(7, moby->mobyClass, moby, 1, 1, 0x40, 0x100);
        func_80055B18(moby);
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007D8B8:300 instructions, nine dispatch words and padding, original4657.
 * Verified13/36 helper forms reused only where original agrees. Raw fields;
 * units, helper contracts, cadence and runtime parity unresolved. */
#define A11Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* A11Active __asm__("D_8006E164");
extern int A11Type __asm__("D_8006E160");
extern unsigned char* A11Pool __asm__("D_8006C550");
extern unsigned char A11Player[] __asm__("D_80070328");
extern int A11Contact __asm__("D_8006C770");
int A11Helper36A68() __asm__("func_80036A68");
int A11Helper38F14() __asm__("func_80038F14");
int A11RequestMobyAnimation() __asm__("func_80034F40");
int A11Helper55E84() __asm__("func_80055E84");
int A11Helper35194() __asm__("func_80035194");
int A11RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int A11Helper3BA00() __asm__("func_8003BA00");
int A11Helper369B8() __asm__("func_800369B8");
int A11DeleteMoby() __asm__("func_80055B18");
extern void* (*A11SpawnMoby)(int, void*)__asm__("SpawnMoby");
int A11TurnMobyTowardPlayer() __asm__("func_8003573C");
int A11ApproximatePlanarDistance() __asm__("func_8004F334");
int A11RandBetween() __asm__("func_8003636C");
int A11PlanarHeadingLookup() __asm__("func_8004E880");
int A11AbsoluteByteAngleDelta() __asm__("func_8004F264");
void func_level_11_8007D8B8(void* input) {
    register unsigned char* owner __asm__("$16") = input;
    register unsigned char* tag __asm__("$17");
    register unsigned char* player19 __asm__("$19");
    register unsigned char* player17 __asm__("$17");
    register int distance18 __asm__("$18");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    MATCHING_KEEP(owner);
    value = owner[72];
    tag = A11Field(owner, unsigned char**, 0);
    if ((unsigned int)value < 8 && (A11Field(owner, int*, 24) & 0x90000)) {
        A11Helper36A68(input, 1, 0, 0);
        A11Helper38F14(owner, tag + 12, 1, 8);
        A11RefreshMobySpatialGridAndBasis(owner, 5);
    }
    if ((unsigned int)(A11Field(A11Player, int*, 80) - 7) < 2) {
        other = owner[72];
        if (other != 5) {
            owner[72] = 7;
            A11RequestMobyAnimation(owner, 7);
        } else
            owner[73] = 2;
    }
    switch (owner[72]) {
        case 0:
            call4 = owner;
            if (A11Contact) {
                if (!owner[73]) {
                    A11RequestMobyAnimation(call4, 1);
                    owner[73] = A11RandBetween(2, 4);
                } else {
                    A11RequestMobyAnimation(call4, 0);
                    owner[73]--;
                }
                call4 = owner;
            }
            A11TurnMobyTowardPlayer(call4, 6, 0, 1);
            if (A11ApproximatePlanarDistance(owner + 12, A11Player) < A11Field(tag, int*, 0)) {
                owner[72] = 3;
                A11RequestMobyAnimation(owner, 3);
            }
            break;
        case 3:
            A11TurnMobyTowardPlayer(owner, 6, 0, 1);
            if (A11Contact) {
                owner[72] = 4;
                A11RequestMobyAnimation(owner, 4);
            }
            break;
        case 4:
            player19 = A11Player;
            distance18 = A11ApproximatePlanarDistance(owner + 12, player19);
            A11TurnMobyTowardPlayer(owner, 6, 0, 1);
            if ((unsigned int)(A11Field(A11Player, int*, 80) - 7) < 2)
                goto retreat;
            if (A11Field(A11Player, int*, 576))
                goto retreat;
            other = A11Field(owner, int*, 20);
            call4 = (void*)A11Field(A11Player, int*, 8);
            value = other - 2048;
            if (value >= (int)call4)
                goto retreat;
            other += 2048;
            value = (int)call4 - A11Field(A11Player, int*, 68);
            if (value >= other)
                goto retreat;
            value =
                A11PlanarHeadingLookup(A11Field(player19, int*, 0) - A11Field(owner, int*, 12),
                                       A11Field(A11Player, int*, 4) - A11Field(owner, int*, 16), 0);
            if (A11AbsoluteByteAngleDelta(owner[70], value) >= 24)
                goto retreat;
            value = distance18 < A11Field(tag, int*, 4);
            call4 = owner;
            if (value) {
                arg5 = 5;
                value = 5;
                goto enter_with_value;
            }
        retreat:
            if (distance18 > A11Field(tag, int*, 0) + 1024) {
                owner[72] = 6;
                A11RequestMobyAnimation(owner, 6);
            }
            break;
        case 5:
            call4 = owner;
            if (owner[73])
                goto animate5;
            MATCHING_BARRIER("$4");
            value = A11Helper55E84(owner);
            call4 = owner;
            if (value < 37)
                goto animate5;
            arg6 = 0;
            value = 1;
            MATCHING_KEEP2(arg6, value);
            player17 = A11Player;
            owner[73] = value;
            value = A11PlanarHeadingLookup(A11Field(player17, int*, 0) - A11Field(owner, int*, 12),
                                           A11Field(A11Player, int*, 4) - A11Field(owner, int*, 16),
                                           arg6);
            value = A11AbsoluteByteAngleDelta(owner[70], value);
            call4 = owner;
            if (value >= 16)
                goto animate5;
            other = A11Field(owner, int*, 20);
            call4 = (void*)A11Field(A11Player, int*, 8);
            if (other >= (int)call4)
                goto prepare_animate5;
            other += 1024;
            value = (int)call4 - A11Field(A11Player, int*, 68);
            call4 = owner + 12;
            if (value >= other)
                goto prepare_animate5;
            value = A11ApproximatePlanarDistance(call4, player17);
            call4 = owner;
            if (value >= 3072)
                goto animate5;
            A11Field(A11Player, int*, 36) |= 22;
        prepare_animate5:
            call4 = owner;
        animate5:
            A11TurnMobyTowardPlayer(call4, 6, 0, 1);
            if (!A11Contact)
                goto done;
            other = owner[73];
            call4 = owner;
            if (other == 2) {
                arg5 = 7;
                value = 7;
            enter_with_value:
                ((unsigned char*)call4)[73] = 0;
                ((unsigned char*)call4)[72] = value;
                A11RequestMobyAnimation(call4, arg5);
                goto done;
            }
            goto enter0;
        case 6:
        case 7:
            A11TurnMobyTowardPlayer(owner, 6, 0, 1);
            if (!A11Contact)
                goto done;
        enter0:
            owner[72] = 0;
            A11RequestMobyAnimation(owner, 0);
            break;
        case 8:
            value = A11Helper35194(owner, tag + 12);
            call4 = owner;
            if (value != 256)
                goto done;
            A11RefreshMobySpatialGridAndBasis(call4, 4);
            A11Helper3BA00(owner);
            A11Helper369B8(owner, 48);
            A11DeleteMoby(owner);
            break;
    }
done:;
}
#undef A11Field


/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007DD68..8007E0BC. Original instructions define numeric branches.
 * Verified Charmed184 C; original Cloud214 differences is discovery only; indirect extra arguments remain unknown. */
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern int D_8006C770;
int func_80055E84(Moby*);
void func_level_11_8007DD68(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    register int* tag __asm__("$17") = moby->mobyTag;
    int angle;
    if (moby->state != 4) {
        if (*(unsigned int*)((unsigned char*)moby + 0x18) & 0x10000) {
            tag[8] = 250;
            angle = *((unsigned char*)moby + 0x51);
            if (!angle)
                angle = func_800360F8(
                    func_8004E880(moby->position.x - *(int*)DecodedCrystalPlayer,
                                  moby->position.y - *(int*)(DecodedCrystalPlayer + 4), 0),
                    DecodedCrystalPlayer[14], 32, 64);
            tag[7] = angle;
            tag[9] = 140;
            moby->unknownCollision = 0;
            SpawnMoby(16, moby);
            moby->state = 4;
            func_80034F40(moby, 4);
        } else if (*(unsigned int*)((unsigned char*)moby + 0x18)) {
            tag[8] = 300;
            angle = *((unsigned char*)moby + 0x51);
            if (!angle)
                angle = func_800360F8(
                    func_8004E880(moby->position.x - *(int*)DecodedCrystalPlayer,
                                  moby->position.y - *(int*)(DecodedCrystalPlayer + 4), 0),
                    DecodedCrystalPlayer[14], 32, 64);
            tag[7] = angle;
            tag[9] = 120;
            moby->unknownCollision = 0;
            SpawnMoby(16, moby);
            moby->state = 4;
            func_80034F40(moby, 4);
        }
    }
    switch (moby->state) {
        case 0:
            if (*((unsigned char*)moby + 0x4D) &&
                func_8004F334(&moby->position, (Vector3D*)DecodedCrystalPlayer) < 16384) {
                /* Reread the global separately before the later timer transition. */
                if (D_8006C770) {
                    if (tag[10] == 0) {
                        if (rand() & 1)
                            func_80034F40(moby, 2);
                        else
                            func_80034F40(moby, 3);
                        tag[10] = func_8003636C(2, 3);
                    } else {
                        func_80034F40(moby, 0);
                        tag[10]--;
                    }
                }
                if (func_800359A4(tag + 6, 4) && D_8006C770) {
                    tag[6] = func_8003636C(3, 7);
                    moby->state = 1;
                    func_80034F40(moby, 1);
                }
            }
            break;
        case 1:
            if ((unsigned int)(func_80055E84(moby) - 9) < 19)
                func_80037168(moby, (Vector3D*)tag, 1);
            if (D_8006C770 && --tag[6] <= 0) {
                tag[6] = func_8003636C(30, 90);
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        case 4:
            func_80035030(moby, tag + 8, tag[7], tag + 9, 12, 16, 320, 1);
            if (D_8006C770) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 24);
                func_80055B18(moby);
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
extern int State464Flags __asm__("D_80070328 + 0x24");
extern unsigned char State464Global8 __asm__("D_80070328+8");
extern unsigned char State464Global68 __asm__("D_80070328+0x44");
extern unsigned char State464Global0 __asm__("D_80070328+0");
extern unsigned char State464Global4 __asm__("D_80070328+4");
extern unsigned char State464Global524 __asm__("D_80070328+0x20C");
extern unsigned char State464Global36 __asm__("D_80070328+0x24");
extern unsigned char State464Global540 __asm__("D_80070328+0x21C");
extern unsigned char State464Global548 __asm__("D_80070328+0x224");
extern unsigned char State464Global544 __asm__("D_80070328+0x220");
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_11/moby/func_level_11_8007E0C0.s SHA256 31706881a404aa4928fc8f3b2f27e888a51a4df304e2b50a51d55facd1861657. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define State464Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char State464_func_80034F40() __asm__("func_80034F40");
/* extern */
int State464_func_80035194() __asm__("func_80035194");
/* extern */
unsigned char State464TurnMobyTowardPlayer() __asm__("func_8003573C");
/* extern */
int State464CountTimerDown() __asm__("func_800359A4");
/* extern */
unsigned char State464_func_800369B8() __asm__("func_800369B8");
/* extern */
unsigned char State464_func_80036A68() __asm__("func_80036A68");
/* extern */
unsigned char State464_func_80038BF8() __asm__("func_80038BF8");
/* extern */
unsigned char State464_func_8003BA00() __asm__("func_8003BA00");
/* extern */
int State464PlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned char State464_func_8004ECF4() __asm__("func_8004ECF4");
/* extern */
unsigned char State464TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
unsigned char State464SubtractVector() __asm__("func_8004F1C8");
/* extern */
int State464AbsoluteByteAngleDelta() __asm__("func_8004F264");
/* extern */
int State464ApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned char State464DeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned char State464RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int State464_func_80055E84() __asm__("func_80055E84");
/* extern */
extern unsigned char State464_D_800658A0 __asm__("D_800658A0");
extern unsigned char State464_D_80065920 __asm__("D_80065920");
extern int State464_D_8006C770 __asm__("D_8006C770");
extern int State464_D_8006E020 __asm__("D_8006E020");
extern int State464_D_8006E024 __asm__("D_8006E024");
extern unsigned short State464_D_8006E040 __asm__("D_8006E040");
extern unsigned char State464_D_80070328 __asm__("D_80070328");
extern unsigned char (*State464_unk_ovlheader_800743F0)() __asm__("unk_ovlheader_800743F0");
extern int (*State464_unk_ovlheader_80074414)() __asm__("unk_ovlheader_80074414");

void func_level_11_8007E0C0(void* input) {
    register void* owner17 __asm__("$17") = input;
    /* Original 0x68-byte frame: scratch SP+0x28..0x4F,
     * saved registers SP+0x50..0x60, final alignment through 0x67.
     * Traced fields and table elements retain their original byte offsets.
     * Table samples use signed LH and a signed product shifted right by 11.
     * Units/fixed-point domains, helper meanings and frame cadence are unknown.
     * Initialized empty constraints preserve raw producers and store order;
     * no instruction assembly or compiler-pipeline changes are used. */
    struct {
        int sp28;
        int sp2C;
        int sp30;
        unsigned char pad34[4];
        unsigned char sp38;
        unsigned char pad39[23];
    } originalFrame;

    register int argument5 __asm__("$5");
    int temp_a0;
    int temp_a1;
    register int case0Word16 __asm__("$16");
    register int case2Word16 __asm__("$16");
    register int case6Word16 __asm__("$16");
    register int result18 __asm__("$18");
    int var_v0;
    int var_v0_2;
    register int case2Word3 __asm__("$3");
    register int state3 __asm__("$3");
    register void* pointer16 __asm__("$16");
    register void* storage19 __asm__("$19");
    register void* call4 __asm__("$4");
    register void* player18 __asm__("$18");
    register int result2 __asm__("$2");
    register int argument6 __asm__("$6");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int argument7 __asm__("$7");
    void* var_a0;

    MATCHING_KEEP(owner17);
    storage19 = State464Field(owner17, void**, 0);
    if (((unsigned char)State464Field(owner17, unsigned char*, 0x48) < 8U) &&
        (State464Field(owner17, int*, 0x18) != 0)) {
        State464_func_80036A68(input, 0, 0, 0);
        State464_func_80038BF8(owner17, storage19 + 0x10, 1, 8);
        State464RefreshMobySpatialGridAndBasis(owner17, 5);
    }
    state3 = State464Field(owner17, unsigned char*, 0x48);
    State464Field(owner17, int*, 0x18) = 0;
    switch (state3) {
        case 8:
            if (State464_func_80035194(owner17, storage19 + 0x10) == 0x100) {
                State464RefreshMobySpatialGridAndBasis(owner17, 4);
                State464_func_8003BA00(owner17);
                State464_func_800369B8(owner17, 0x30);
                State464DeleteMoby(owner17);
                return;
            }
        default:
            return;
        case 0:
            pointer16 = owner17 + 0xC;
            result2 = State464ApproximatePlanarDistance(pointer16, storage19 + 0x28);
            call4 = owner17;
            if (result2 >= 0x801) {
                {
                    register int state2 __asm__("$2") = 1;
                    MATCHING_KEEP_VOLATILE(state2);
                    State464Field(owner17, unsigned char*, 0x48) = state2;
                }
                argument5 = 1;
                goto callStateHelper;
            }
            State464TurnMobyTowardPlayer(owner17, 6, 0, 1);
            case0Word16 = State464ApproximatePlanarDistance(pointer16, &State464_D_80070328);
            temp_a1 = State464Field(storage19, int*, 0x34);
            if (temp_a1 != 0) {
                var_v0 =
                    ((State464Field(owner17, int*, 0x14) - State464Field(owner17, short*, 0x38)) -
                     State464Field(&State464Global8, int*, 0)) +
                    State464Field(&State464Global68, int*, 0);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < 0x600) &&
                    (State464_unk_ovlheader_80074414(temp_a1, &State464_D_80070328) != 0)) {
                    {
                        register int state2 __asm__("$2") = 2;
                        MATCHING_KEEP_VOLATILE(state2);
                        State464Field(owner17, unsigned char*, 0x48) = state2;
                    }
                    call4 = owner17;
                    MATCHING_KEEP(call4);
                    argument5 = 2;
                    goto callStateHelper;
                }
                goto block_15;
            }
        block_15:
            {
                register int comparison2 __asm__("$2") =
                    case0Word16 < State464Field(storage19, int*, 4);
                MATCHING_KEEP(comparison2);
                if (comparison2) {
                    {
                        register int state2 __asm__("$2") = 3;
                        MATCHING_KEEP_VOLATILE(state2);
                        State464Field(owner17, unsigned char*, 0x48) = state2;
                    }
                    call4 = owner17;
                    MATCHING_KEEP(call4);
                    argument5 = 3;
                    goto callStateHelper;
                }
            }
            break;
        case 1:
            State464_unk_ovlheader_800743F0(
                owner17,
                State464PlanarHeadingLookup(
                    State464Field(storage19, int*, 0x28) - State464Field(owner17, int*, 0xC),
                    State464Field(storage19, int*, 0x2C) - State464Field(owner17, int*, 0x10), 0),
                0x64, 0x200, 0x200, 0x27, storage19 + 0x34, 1, 0);
            if (State464ApproximatePlanarDistance(owner17 + 0xC, storage19 + 0x28) < 0x200) {
                State464Field(owner17, unsigned char*, 0x48) = 0;
                call4 = owner17;
                MATCHING_KEEP(call4);
                argument5 = 0;
                goto callStateHelper;
            }
            break;
        case 2:
            argument6 = 0;
            MATCHING_KEEP_CLOBBER(argument6, "$18");
            player18 = &State464_D_80070328;
            MATCHING_KEEP(player18);
            State464_unk_ovlheader_800743F0(
                owner17,
                State464PlanarHeadingLookup(
                    State464Field(player18, int*, 0) - State464Field(owner17, int*, 0xC),
                    State464Field(&State464Global4, int*, 0) - State464Field(owner17, int*, 0x10),
                    argument6),
                0x96, 0x200, 0x200, 0x27, storage19 + 0x34, 1, 0);
            case2Word16 = State464ApproximatePlanarDistance(owner17 + 0xC, player18);
            case2Word3 =
                ((State464Field(owner17, int*, 0x14) - State464Field(owner17, short*, 0x38)) -
                 State464Field(&State464Global8, int*, 0)) +
                State464Field(&State464Global68, int*, 0);
            if (case2Word3 < 0) {
                case2Word3 = -case2Word3;
            }
            MATCHING_KEEP(case2Word3);
            if ((case2Word3 >= 0x701) ||
                ((State464_unk_ovlheader_80074414(State464Field(storage19, int*, 0x34), player18) ==
                  0) &&
                 ((State464Field(storage19, int*, 0) + 0x200) < case2Word16))) {
                {
                    register int state2 __asm__("$2") = 1;
                    MATCHING_KEEP_VOLATILE(state2);
                    State464Field(owner17, unsigned char*, 0x48) = state2;
                }
                call4 = owner17;
                MATCHING_KEEP(call4);
                argument5 = 1;
                goto callStateHelper;
            }
            {
                register int comparison2 __asm__("$2") =
                    case2Word16 < State464Field(storage19, int*, 4);
                MATCHING_KEEP(comparison2);
                if (comparison2) {
                    {
                        register int state2 __asm__("$2") = 3;
                        MATCHING_KEEP_VOLATILE(state2);
                        State464Field(owner17, unsigned char*, 0x48) = state2;
                    }
                    call4 = owner17;
                    MATCHING_KEEP(call4);
                    argument5 = 3;
                    goto callStateHelper;
                }
            }
            break;
        case 3:
            State464TurnMobyTowardPlayer(owner17, 6, 0, 1);
        case 7:
            goto checkSharedFlag;
        case 6:
            result2 = State464ApproximatePlanarDistance(owner17 + 0xC, &State464_D_80070328);
            call4 = owner17;
            MATCHING_KEEP_CLOBBER(call4, "$5");
            argument5 = 6;
            MATCHING_KEEP_CLOBBER(argument5, "$6");
            argument6 = 0;
            MATCHING_KEEP_CLOBBER(argument6, "$7");
            argument7 = 1;
            MATCHING_KEEP_CLOBBER(argument7, "$16");
            case6Word16 = result2;
            State464TurnMobyTowardPlayer(call4, argument5, argument6, argument7);

            if (((unsigned int)((State464Field(&State464Global8, int*, 0) -
                                 State464Field(owner17, int*, 0x14)) +
                                0x1FF) < 0x9FFU) &&
                (case6Word16 < State464Field(storage19, int*, 8))) {
                if (State464AbsoluteByteAngleDelta(
                        (int)(State464_D_8006E040 << 0x10) >> 0x14,
                        State464PlanarHeadingLookup(
                            State464Field(owner17, int*, 0xC) - State464_D_8006E020,
                            State464Field(owner17, int*, 0x10) - State464_D_8006E024, 0)) < 0x18) {
                    {
                        register int state2 __asm__("$2") = 4;
                        MATCHING_KEEP_VOLATILE(state2);
                        State464Field(owner17, unsigned char*, 0x48) = state2;
                    }
                    call4 = owner17;
                    MATCHING_KEEP(call4);
                    argument5 = 4;
                    goto callStateHelper;
                }
                goto checkStorageHalf;
            }
        checkStorageHalf:
            if ((State464CountTimerDown(storage19 + 0xE, 2) != 0) &&
                ((State464Field(storage19, int*, 4) + 0x200) < case6Word16)) {
                {
                    register int state2 __asm__("$2") = 5;
                    MATCHING_KEEP_VOLATILE(state2);
                    State464Field(owner17, unsigned char*, 0x48) = state2;
                }
                call4 = owner17;
                MATCHING_KEEP(call4);
                argument5 = 5;
                goto callStateHelper;
            }
            break;
        case 4:
            State464TurnMobyTowardPlayer(owner17, 4, 0, 1);
            if (State464Field(owner17, unsigned char*, 0x3C) == 4) {
                result18 = State464_func_80055E84(owner17);
                MATCHING_KEEP(result18);
                if (result18 < 0x10) {
                    State464RefreshMobySpatialGridAndBasis(owner17, 4);
                    pointer16 = &originalFrame.sp38;
                    MATCHING_KEEP(pointer16);
                    State464_func_8004ECF4(pointer16, owner17 + 0x20);
                    State464SubtractVector(&originalFrame.sp28, &State464_D_80070328,
                                           owner17 + 0xC);
                    State464TransformVectorByBasis(pointer16, &originalFrame.sp28,
                                                   &originalFrame.sp28);
                    if ((originalFrame.sp28 > 0) && (originalFrame.sp28 < (result18 * 0x60))) {
                        var_v0_2 = originalFrame.sp2C;
                        if (var_v0_2 < 0) {
                            var_v0_2 = -var_v0_2;
                        }
                        if ((var_v0_2 < 0x200) &&
                            ((unsigned int)(originalFrame.sp30 + 0x1FF) < 0x9FFU)) {
                            word3 = 0x10000000;
                            MATCHING_KEEP(word3);
                            word2 = State464Flags;
                            __asm__("" : "=r"(word2) : "0"(word2), "r"(word3));
                            word3 |= 0x400;
                            State464Field(&State464Global524, int*, 0) = word3;
                            MATCHING_KEEP_VOLATILE_CLOBBER(word2, "memory");
                            word2 |= 1;
                            State464Flags = word2;
                            State464Field(&State464Global540, int*, 0) =
                                (int)((int)(State464Field(
                                                &State464_D_80065920, short*,
                                                State464Field(owner17, unsigned char*, 0x46) * 2) *
                                            0x55) >>
                                      0xB);
                            word3 = State464Field(&State464_D_800658A0, short*,
                                                  State464Field(owner17, unsigned char*, 0x46) * 2);
                            MATCHING_KEEP_VOLATILE_CLOBBER(word3, "memory");
                            word2 = 0x32;
                            State464Field(&State464Global548, int*, 0) = word2;
                            MATCHING_KEEP_VOLATILE_CLOBBER(word3, "memory");
                            State464Field(&State464Global544, int*, 0) = (word3 * 0x55) >> 11;
                            State464Field(owner17, unsigned char*, 0x49) = 1U;
                        }
                    }
                }
            }
            if (State464_D_8006C770 != 0) {
                if (State464Field(owner17, unsigned char*, 0x49) != 0) {
                    {
                        register int state2 __asm__("$2") = 7;
                        MATCHING_KEEP_VOLATILE(state2);
                        State464Field(owner17, unsigned char*, 0x48) = state2;
                    }
                    call4 = owner17;
                    MATCHING_KEEP(call4);
                    argument5 = 7;
                } else {
                    call4 = owner17;
                    MATCHING_KEEP_CLOBBER(call4, "$2");
                    word2 = State464Field(storage19, unsigned short*, 0xC);
                    MATCHING_KEEP_CLOBBER(word2, "$5");
                    argument5 = 6;
                    State464Field(storage19, unsigned short*, 0xE) = word2;
                    MATCHING_BARRIER_VOLATILE("memory");
                    word2 = 6;
                    State464Field(call4, unsigned char*, 0x48) = word2;
                }
                goto callStateHelper;
            }
            break;
        case 5:
            State464TurnMobyTowardPlayer(owner17, 6, 0, 1);
            if (State464_D_8006C770 != 0) {
                temp_a0 = State464Field(storage19, int*, 0x34);
                if (temp_a0 != 0) {
                    if (State464_unk_ovlheader_80074414(temp_a0, &State464_D_80070328) != 0) {
                        {
                            register int state2 __asm__("$2") = 2;
                            MATCHING_KEEP_VOLATILE(state2);
                            State464Field(owner17, unsigned char*, 0x48) = state2;
                        }
                        call4 = owner17;
                        MATCHING_KEEP(call4);
                        argument5 = 2;
                    } else if ((State464Field(storage19, int*, 0x34) != 0) &&
                               (State464ApproximatePlanarDistance(owner17 + 0xC,
                                                                  storage19 + 0x28) >= 0x401)) {
                        {
                            register int state2 __asm__("$2") = 1;
                            MATCHING_KEEP_VOLATILE(state2);
                            State464Field(owner17, unsigned char*, 0x48) = state2;
                        }
                        call4 = owner17;
                        MATCHING_KEEP(call4);
                        argument5 = 1;
                    } else {
                        goto block_56;
                    }
                } else {
                block_56:
                    State464Field(owner17, unsigned char*, 0x48) = 0;
                    call4 = owner17;
                    MATCHING_KEEP(call4);
                    argument5 = 0;
                }
                goto callStateHelper;
            }
            break;
    }
    goto finished;
checkSharedFlag:
    if (State464_D_8006C770 != 0) {
        {
            register int state2 __asm__("$2") = 6;
            MATCHING_KEEP_VOLATILE(state2);
            State464Field(owner17, unsigned char*, 0x48) = state2;
        }
        call4 = owner17;
        MATCHING_KEEP(call4);
        argument5 = 6;
        goto callStateHelper;
    }
    goto finished;
callStateHelper:
    State464_func_80034F40(call4, argument5);
finished:;
}
#undef State464Field


/**
 * MobyUpdate_249() - func_level_11_8007E800()
 * Lion NPC
 * WIP
 * https://decomp.me/scratch/IZwRP
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original11 8007E800.
* Assembly SHA256 1e80a6bf527c52a4d23912319343010983d741ba857544bff5bc26388976f2e9.
* AI generated; not human reviewed. Exactly908 native instructions and22
* original selector words=930 owned words; no selector padding belongs here.
* Accepted674 supplies both full-word CRC and late-return source patterns.
* Frame60hex retains SP20..47 local homes and S0..S4/RA saves at SP48..5C.
* Original damage/status snapshots,linked88-byte record checks,kind/substate
* paths,private offsets,global bytes and callback/store order remain exact.
* CRC streams retain original function/end symbols,main_TEXT_START+2 and
* caller cursor fields. Every byte feeds eight rounds of WHOLE32-bit shift/
* XOR with8000/8005; no16-bit accumulator truncation is introduced. Starting
* at0,byte1 yields00018005. Main cursor step is the complete final word&3,+1.
* Original state2 initializes S3=6 at517 before every path; original arms
*554/558/591 change it to10. Every35A80 call supplies all eight physical
* words:owner,path,256,speed20/200,300,initialized6/10,40,flags5/20005.
* No outgoing parameter is guessed or read from an unwritten slot. The raw
* decoder's five-argument rendering was incomplete and is not used here.
* Handwritten55E84 consumes only A0; at55EA0 it overwrites A1 before use.
* Other extra physical register words retain their original ABI observations
* without invented helper meanings. Saved result16 captures the whole V0
* only after the original vector/address/private48 producers,then tests bit1.
* Separate frame vectors,late SP40+512 store,descriptor signed16 indices,
* acceleration-12,and shared delete/reset/final entries retain original order.
* Empty metadata consumes complete initialized values/addresses or original
* written fields,or clobbers dead GP before a fresh value;zero CPU words.
* No opcode asm,partial HI/LO,fixed FP/SP,unwritten local read,incoming saved
* value or overlapping live fixed aliases. Compiler/filter/flags stay frozen.
* Every native/linked word,actual conditional/internal-J/call/JALR/table
* destination,original data symbol/addend and full EXE/every-overlay retail
* hash must pass. Confidence is native identity after these gates; physical
* units,full field/helper/caller producer chains,cadence,Rev1 mapping,human
* review and synchronized retail captures remain open.
*/
#define Level11_7E800Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level11_7E800Call34F40View() __asm__("func_80034F40");
int Level11_7E800CountTimerDownView(void*, int) __asm__("func_800359A4");
int Level11_7E800Call35A80View() __asm__("func_80035A80");
int Level11_7E800RandBetweenView(int, int) __asm__("func_8003636C");
int Level11_7E800GetClosestPathNodeView() __asm__("func_8003645C");
int Level11_7E800Call365E4View() __asm__("func_800365E4");
int Level11_7E800Call37BBCView() __asm__("func_80037BBC");
int Level11_7E800Call492DCView() __asm__("func_800492DC");
int Level11_7E800PlanarHeadingLookupView() __asm__("func_8004E880");
int Level11_7E800CopyVectorView() __asm__("func_8004F178");
int Level11_7E800ApproximatePlanarDistanceView() __asm__("func_8004F334");
int Level11_7E800Call512E4View() __asm__("func_800512E4");
int Level11_7E800DeleteMobyView() __asm__("func_80055B18");
int Level11_7E800Call55E84View(void*) __asm__("func_80055E84");
int Level11_7E800DatarandView() __asm__("rand");
extern int Level11_7E800Data6C550View __asm__("D_8006C550");
extern int Level11_7E800Data6C58CView __asm__("D_8006C58C");
extern int Level11_7E800Data6C640View __asm__("D_8006C640");
extern int Level11_7E800Data6C770View __asm__("D_8006C770");
extern unsigned char Level11_7E800Data6C7B4View __asm__("D_8006C7B4");
extern int Level11_7E800Data6E344View __asm__("D_8006E344");
extern unsigned char Level11_7E800Data70300View __asm__("D_80070300");
extern unsigned char Level11_7E800Data70328View __asm__("D_80070328");
extern unsigned char Level11_7E800Data91ED4View __asm__("D_level_11_80091ED4");
extern void* (*Level11_7E800DataSpawnMobyView)() __asm__("SpawnMoby");
extern void* (*Level11_7E800DataSpawnParticleView)() __asm__("SpawnParticle");
extern unsigned char Level11_7E800Call751C0View __asm__("func_level_11_800751C0");
extern unsigned char Level11_7E800Datamain_TEXT_ENDView __asm__("main_TEXT_END");
extern unsigned char Level11_7E800Datamain_TEXT_STARTView __asm__("main_TEXT_START");
void func_level_11_8007E800(void* ownerParameter) {
    register void* ownerRecord18 __asm__("$18");
    register int privateRecord17 __asm__("$17"), createdRecordOrRetainedResult16 __asm__("$16"),
        initializedSpeedOrOwnerPosition19 __asm__("$19"),
        originalFlagOrSignedIndex20 __asm__("$20");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    } originalFrame;
    short temporaryValue15;
    short temporaryValue16;
    int temporaryValue3;
    int temporaryValue17;
    int temporaryValue21;
    int temporaryValue22;
    int temporaryValue26;
    int temporaryValue27;
    int temporaryValue28;
    int temporaryValue30;
    unsigned char temporaryValue1;
    unsigned char temporaryValue4;
    unsigned char temporaryValue6;
    unsigned char temporaryValue7;
    unsigned char temporaryValue10;
    unsigned char temporaryValue23;
    unsigned char temporaryValue29;
    unsigned char temporaryValue31;
    void* temporaryValue2;
    void* temporaryValue5;
    void* temporaryValue8;
    void* temporaryValue9;
    void* temporaryValue11;
    void* temporaryValue12;
    void* temporaryValue13;
    void* temporaryValue14;
    void* temporaryValue18;
    void* temporaryValue19;
    void* temporaryValue20;
    void* temporaryValue24;
    void* temporaryValue25;
    unsigned int temporaryWord11;
    unsigned int temporaryWord12;
    unsigned int temporaryWord13;
    ownerRecord18 = ownerParameter;
    MATCHING_KEEP(ownerRecord18);
    temporaryValue21 = Level11_7E800Field(ownerRecord18, int*, 0x18);
    privateRecord17 = Level11_7E800Field(ownerRecord18, void**, 0);
    if (temporaryValue21 != 0) {
        if (temporaryValue21 & 0x10000) {
            Level11_7E800Field(privateRecord17, unsigned char*, 0x32) = 1U;
        }
        temporaryValue1 = Level11_7E800Field(ownerRecord18, unsigned char*, 0x48);
        if ((temporaryValue1 & 0xFF) != 4) {
            Level11_7E800Field(privateRecord17, unsigned char*, 0x30) = temporaryValue1;
            Level11_7E800Field(privateRecord17, unsigned char*, 0x31) =
                (unsigned char)Level11_7E800Field(ownerRecord18, unsigned char*, 0x3D);
        }
        Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 4U;
        Level11_7E800Call34F40View(ownerRecord18, 4U);
    }
    Level11_7E800Field(ownerRecord18, int*, 0x18) = 0;
    if (Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 3) {
        if ((Level11_7E800Data6C7B4View & 1) ||
            (*(&Level11_7E800Data70300View + Level11_7E800Data6C58CView) & 1)) {
            if (Level11_7E800Data6C640View < 3) {
                temporaryValue26 = Level11_7E800Field(privateRecord17, int*, 0x38);
                if (temporaryValue26 >= 0) {
                    Level11_7E800Field(((temporaryValue26 * 0x58) + Level11_7E800Data6C550View),
                                       signed char*, 0x49) = 1;
                }
                argumentWord4 = Level11_7E800Field(privateRecord17, int*, 0x3C);
                if (argumentWord4 >= 0) {
                    Level11_7E800Field(((argumentWord4 * 0x58) + Level11_7E800Data6C550View),
                                       signed char*, 0x49) = 1;
                }
                goto deleteOriginalOwner874;
            }
            goto reloadOriginalKind83;
        }
    reloadOriginalKind83:
        if (Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 3) {
            temporaryValue27 = Level11_7E800Field(privateRecord17, int*, 0x28);
            if ((temporaryValue27 >= 0) &&
                (Level11_7E800Field(((temporaryValue27 * 0x58) + Level11_7E800Data6C550View),
                                    unsigned char*, 0x48) &
                 0x80)) {
                temporaryValue28 = Level11_7E800Field(privateRecord17, int*, 0x3C);
                if (temporaryValue28 >= 0) {
                    Level11_7E800Field(((temporaryValue28 * 0x58) + Level11_7E800Data6C550View),
                                       signed char*, 0x49) = 1;
                }
            }
            temporaryValue4 = Level11_7E800Field(privateRecord17, unsigned char*, 0x33);
            if ((temporaryValue4 == 3) && (Level11_7E800Data6C7B4View & 1)) {
                temporaryValue29 = Level11_7E800Field(ownerRecord18, unsigned char*, 0x48);
                if ((temporaryValue29 != temporaryValue4) && (temporaryValue29 != 0x15)) {
                    temporaryValue30 = Level11_7E800Field(privateRecord17, int*, 0x38);
                    if (temporaryValue30 >= 0) {
                        Level11_7E800Field(((temporaryValue30 * 0x58) + Level11_7E800Data6C550View),
                                           signed char*, 0x49) = 1;
                    }
                }
            }
        }
        goto checkOriginalInvocation143;
    }
checkOriginalInvocation143:
    if (Level11_7E800Data6C640View == 0) {
        if ((Level11_7E800Field(privateRecord17, unsigned char*, 0) == 5) &&
            (Level11_7E800Field(((Level11_7E800Field(privateRecord17, int*, 0x28) * 0x58) +
                                 Level11_7E800Data6C550View),
                                unsigned char*, 0x48) &
             0x80) &&
            ((Level11_7E800Data6C7B4View & 1) ||
             (*(&Level11_7E800Data70300View + Level11_7E800Data6C58CView) & 1))) {
            temporaryValue18 = Level11_7E800DataSpawnMobyView(0x1A3, ownerRecord18);
            if (temporaryValue18 != 0) {
                Level11_7E800CopyVectorView(
                    temporaryValue18 + 0xC,
                    Level11_7E800Field(Level11_7E800Field(privateRecord17, void**, 0x20), void**,
                                       0xC) +
                        0x70);
                temporaryValue19 = Level11_7E800Field(
                    Level11_7E800Field(privateRecord17, void**, 0x20), void**, 0xC);
                temporaryValue17 = Level11_7E800Field(temporaryValue19, int*, 0x80);
                Level11_7E800Field(temporaryValue18, signed char*, 0x46) =
                    Level11_7E800PlanarHeadingLookupView(
                        temporaryValue17 - Level11_7E800Field(temporaryValue19, int*, 0x70),
                        Level11_7E800Field(temporaryValue19, int*, 0x84) -
                            Level11_7E800Field(temporaryValue19, int*, 0x74),
                        0, temporaryValue17);
                rawWord2 = 3;
                Level11_7E800Field(temporaryValue18, signed char*, 0x48) = rawWord2;
            } else {
                rawWord2 = 2;
            }
            Level11_7E800Field(privateRecord17, unsigned char*, 2) = rawWord2;
        }
        if (Level11_7E800Field(privateRecord17, unsigned char*, 0) == 0) {
            if (Level11_7E800Data6C7B4View & 1) {
                rawWord2 = 2;
                Level11_7E800Field(privateRecord17, unsigned char*, 2) = rawWord2;
            } else if (*(&Level11_7E800Data70300View + Level11_7E800Data6C58CView) & 1) {
                rawWord2 = 3;
                Level11_7E800Field(privateRecord17, unsigned char*, 2) = rawWord2;
            }
            goto checkOriginalOverlayStream232;
        }
    } else {
    checkOriginalOverlayStream232:
        if ((Level11_7E800Field(privateRecord17, unsigned char*, 0) == 0) &&
            (unsigned int)Level11_7E800Field(privateRecord17, unsigned int*, 0x24) >=
                (unsigned int)&Level11_7E800Call751C0View) {
            argumentWord5 = 0;
            argumentWord6 = (int)&Level11_7E800Data91ED4View;
        readOriginalOverlayByte:
            temporaryWord11 = Level11_7E800Field(privateRecord17, unsigned int*, 0x24);
            if (temporaryWord11 < (unsigned int)argumentWord6) {
                argumentWord4 = 0;
                Level11_7E800Field(privateRecord17, int*, 0x34) =
                    (int)(Level11_7E800Field(privateRecord17, int*, 0x34) ^
                          (Level11_7E800Field(temporaryWord11, unsigned char*, 0) << 8));
                do {
                    rawWord3 = Level11_7E800Field(privateRecord17, int*, 0x34);
                    if (rawWord3 & 0x8000) {
                        rawWord2 = ((unsigned int)rawWord3 << 1) ^ 0x8005;
                    } else {
                        rawWord2 = (unsigned int)rawWord3 << 1;
                    }
                    Level11_7E800Field(privateRecord17, int*, 0x34) = rawWord2;
                    __asm__ __volatile__("" ::"m"(Level11_7E800Field(privateRecord17, int*, 0x34))
                                         : "memory");
                    argumentWord4 += 1;
                } while (argumentWord4 < 8);
                argumentWord5 += 1;
                Level11_7E800Field(privateRecord17, unsigned int*, 0x24) =
                    (unsigned int)(Level11_7E800Field(privateRecord17, unsigned int*, 0x24) + 1);
                if (argumentWord5 < 0x40) {
                    goto readOriginalOverlayByte;
                }
            }
        }
    }
    temporaryValue31 = Level11_7E800Field(ownerRecord18, unsigned char*, 0x48);
    switch (temporaryValue31) {
        case 0:
            if (Level11_7E800Data6C770View != 0) {
                if (Level11_7E800Field(ownerRecord18, unsigned char*, 0x49) == 0) {
                    Level11_7E800Call34F40View(ownerRecord18, 1U);
                    Level11_7E800Field(ownerRecord18, unsigned char*, 0x49) =
                        Level11_7E800RandBetweenView(2, 4);
                } else {
                    Level11_7E800Call34F40View(ownerRecord18, 0U);
                    Level11_7E800Field(ownerRecord18, unsigned char*, 0x49) =
                        (unsigned char)(Level11_7E800Field(ownerRecord18, unsigned char*, 0x49) -
                                        1);
                }
            }
            if ((Level11_7E800Field(privateRecord17, void**, 0x20) != 0) &&
                (temporaryValue22 = Level11_7E800Field(privateRecord17, int*, 0x28),
                 (temporaryValue22 >= 0)) &&
                (temporaryValue5 = (temporaryValue22 * 0x58) + Level11_7E800Data6C550View,
                 (Level11_7E800Field(temporaryValue5, short*, 0x36) == 0xFD))) {
                if (Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 2) {
                    temporaryValue6 = Level11_7E800Field(temporaryValue5, unsigned char*, 0x48);
                    if (temporaryValue6 == 5) {
                        if (Level11_7E800Field(
                                ((Level11_7E800Field(privateRecord17, int*, 0x2C) * 0x58) +
                                 Level11_7E800Data6C550View),
                                unsigned char*, 0x48) != temporaryValue6) {
                            goto checkOriginalLinkedKind333;
                        }
                        goto selectOriginalDescriptor352;
                    }
                }
            checkOriginalLinkedKind333:
                if (Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 1) {
                    temporaryValue7 = Level11_7E800Field(
                        ((Level11_7E800Field(privateRecord17, int*, 0x28) * 0x58) +
                         Level11_7E800Data6C550View),
                        unsigned char*, 0x48);
                    if ((temporaryValue7 & 0xFF) == 2) {
                    selectOriginalDescriptor352:
                        Level11_7E800GetClosestPathNodeView(
                            ownerRecord18 + 0xC, Level11_7E800Field(privateRecord17, void**, 0x20),
                            &originalFrame.sp20);
                        temporaryValue14 = Level11_7E800Field(privateRecord17, void**, 0x20);
                        Level11_7E800Field(temporaryValue14, short*, 2) =
                            (short)((int)(originalFrame.sp20 + 1) %
                                    (short)Level11_7E800Field(temporaryValue14, short*, 0));
                        Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 2U;
                        Level11_7E800Call34F40View(ownerRecord18, 2U, temporaryValue14);
                    } else {
                        rawWord2 = Level11_7E800Field(privateRecord17, unsigned char*, 2);
                        if (rawWord2)
                            goto callOriginalCommonHelper492;
                        rawWord2 = temporaryValue7 & 128;
                        goto testOriginalLinkedBit429;
                    }
                } else if ((Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 2) &&
                           (Level11_7E800Field(privateRecord17, unsigned char*, 2) == 0)) {
                    if (Level11_7E800Field(
                            ((Level11_7E800Field(privateRecord17, int*, 0x28) * 0x58) +
                             Level11_7E800Data6C550View),
                            unsigned char*, 0x48) &
                        0x80) {
                        rawWord2 = Level11_7E800Field(
                                       ((Level11_7E800Field(privateRecord17, int*, 0x2C) * 0x58) +
                                        Level11_7E800Data6C550View),
                                       unsigned char*, 0x48) &
                                   0x80;
                    testOriginalLinkedBit429:
                        if (rawWord2 != 0) {
                            Level11_7E800Field(privateRecord17, unsigned char*, 2) = 1U;
                        }
                    }
                }
            } else if (Level11_7E800Field(privateRecord17, unsigned char*, 0) == 0) {
                if (Level11_7E800Field(privateRecord17, unsigned int*, 0x24) == 0) {
                    Level11_7E800Field(privateRecord17, unsigned int*, 0x24) =
                        (unsigned int)(Level11_7E800Data6C58CView +
                                       (&Level11_7E800Datamain_TEXT_STARTView + 2));
                }
                rawWord2 = Level11_7E800Field(privateRecord17, unsigned int*, 0x24);
                rawWord3 = (int)&Level11_7E800Datamain_TEXT_ENDView;
                __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2));
                argumentWord5 = 0;
                if ((unsigned int)rawWord2 < (unsigned int)rawWord3) {
                    argumentWord6 = rawWord3;
                readOriginalMainByte:
                    temporaryWord12 = Level11_7E800Field(privateRecord17, unsigned int*, 0x24);
                    argumentWord4 = 0;
                    if (temporaryWord12 < (unsigned int)argumentWord6) {
                        Level11_7E800Field(privateRecord17, int*, 0x34) =
                            (int)(Level11_7E800Field(privateRecord17, int*, 0x34) ^
                                  (Level11_7E800Field(temporaryWord12, unsigned char*, 0) << 8));
                        do {
                            rawWord3 = Level11_7E800Field(privateRecord17, int*, 0x34);
                            if (rawWord3 & 0x8000) {
                                rawWord2 = ((unsigned int)rawWord3 << 1) ^ 0x8005;
                            } else {
                                rawWord2 = (unsigned int)rawWord3 << 1;
                            }
                            Level11_7E800Field(privateRecord17, int*, 0x34) = rawWord2;
                            __asm__ __volatile__(
                                "" ::"m"(Level11_7E800Field(privateRecord17, int*, 0x34))
                                : "memory");
                            argumentWord4 += 1;
                        } while (argumentWord4 < 8);
                        argumentWord5 += 1;
                        rawWord2 = Level11_7E800Field(privateRecord17, int*, 0x34);
                        rawWord3 = Level11_7E800Field(privateRecord17, int*, 0x24);
                        rawWord2 = (rawWord2 & 3) + 1;
                        rawWord3 += rawWord2;
                        temporaryWord13 = rawWord3;
                        Level11_7E800Field(privateRecord17, unsigned int*, 0x24) = temporaryWord13;
                        if (argumentWord5 >= 0x40) {
                            if (temporaryWord13 >=
                                (unsigned int)&Level11_7E800Datamain_TEXT_ENDView) {
                                goto resetOriginalCursor;
                            }
                        } else {
                            goto readOriginalMainByte;
                        }
                    } else {
                    resetOriginalCursor:
                        Level11_7E800Field(privateRecord17, unsigned int*, 0x24) =
                            (unsigned int)&Level11_7E800Call751C0View;
                    }
                }
            }
        callOriginalCommonHelper492:
            if (Level11_7E800Call37BBCView(ownerRecord18, 0) != 0) {
                if (Level11_7E800Field(privateRecord17, unsigned char*, 0) == 3) {
                    if (!(Level11_7E800Data6C7B4View & 1)) {
                        Level11_7E800Data6C7B4View |= 1;
                    }
                }
                Level11_7E800Call512E4View(ownerRecord18, 0, 3);
                Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 3U;
                return;
            }
        default:
            return;
        case 2:
            initializedSpeedOrOwnerPosition19 = 6;
            MATCHING_KEEP(initializedSpeedOrOwnerPosition19);
            originalFlagOrSignedIndex20 = 0;
            if (Level11_7E800Data6C770View != 0) {
                Level11_7E800Call34F40View(ownerRecord18, 2U);
            }
            if (Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 2) {
                temporaryValue8 = (Level11_7E800Field(privateRecord17, int*, 0x28) * 0x58) +
                                  Level11_7E800Data6C550View;
                if ((Level11_7E800Field(temporaryValue8, unsigned char*, 0x3C) == 5) &&
                    (Level11_7E800Call55E84View(temporaryValue8) >= 8)) {
                    if (Level11_7E800Field(Level11_7E800Field(privateRecord17, void**, 0x20),
                                           short*, 2) == 0) {
                        Level11_7E800Call34F40View(ownerRecord18, 4U);
                    }
                    initializedSpeedOrOwnerPosition19 = 10;
                    Level11_7E800Field(Level11_7E800Field(privateRecord17, void**, 0x20), short*,
                                       2) = 1;
                } else {
                    temporaryValue9 = (Level11_7E800Field(privateRecord17, int*, 0x2C) * 0x58) +
                                      Level11_7E800Data6C550View;
                    if ((Level11_7E800Field(temporaryValue9, unsigned char*, 0x3C) == 5) &&
                        (Level11_7E800Call55E84View(temporaryValue9) >= 8)) {
                        if (Level11_7E800Field(Level11_7E800Field(privateRecord17, void**, 0x20),
                                               short*, 2) == 1) {
                            Level11_7E800Call34F40View(ownerRecord18, 4U);
                        }
                        initializedSpeedOrOwnerPosition19 = 10;
                        Level11_7E800Field(Level11_7E800Field(privateRecord17, void**, 0x20),
                                           short*, 2) = 0;
                    }
                }
                temporaryValue11 = (Level11_7E800Field(privateRecord17, int*, 0x28) * 0x58) +
                                   Level11_7E800Data6C550View;
                temporaryValue10 = Level11_7E800Field(temporaryValue11, unsigned char*, 0x48);
                createdRecordOrRetainedResult16 = ownerRecord18 + 0xC;
                if (((temporaryValue10 != 5) ||
                     (Level11_7E800Field(((Level11_7E800Field(privateRecord17, int*, 0x2C) * 0x58) +
                                          Level11_7E800Data6C550View),
                                         unsigned char*, 0x48) != temporaryValue10)) &&
                    (Level11_7E800ApproximatePlanarDistanceView(
                         createdRecordOrRetainedResult16, temporaryValue11 + 0xC,
                         Level11_7E800Data6C550View) >= 0x1801) &&
                    (Level11_7E800ApproximatePlanarDistanceView(
                         createdRecordOrRetainedResult16,
                         Level11_7E800Data6C550View +
                             (Level11_7E800Field(privateRecord17, int*, 0x2C) * 0x58) + 0xC) >=
                     0x1801)) {
                    originalFlagOrSignedIndex20 = 1;
                }
            } else {
                temporaryValue2 = (Level11_7E800Field(privateRecord17, int*, 0x28) * 0x58) +
                                  Level11_7E800Data6C550View;
                if ((Level11_7E800Field(temporaryValue2, short*, 0x36) == 0xFD) &&
                    (Level11_7E800Field(temporaryValue2, unsigned char*, 0x48) != 2)) {
                    originalFlagOrSignedIndex20 = 1;
                }
            }
            rawWord2 = Level11_7E800Field(ownerRecord18, unsigned char*, 0x3C);
            rawWord3 = 2;
            MATCHING_KEEP(rawWord3);
            argumentWord7 = 20;
            if (rawWord2 == rawWord3)
                argumentWord7 = 200;
            rawWord2 = Level11_7E800Field(privateRecord17, unsigned char*, 0x33);
            if (rawWord2 == rawWord3)
                Level11_7E800Call35A80View(
                    ownerRecord18, Level11_7E800Field(privateRecord17, void**, 0x20), 256,
                    argumentWord7, 300, initializedSpeedOrOwnerPosition19, 40, 5);
            else
                Level11_7E800Call35A80View(
                    ownerRecord18, Level11_7E800Field(privateRecord17, void**, 0x20), 256,
                    argumentWord7, 300, initializedSpeedOrOwnerPosition19, 40, 0x20005);
            temporaryValue3 = Level11_7E800Field(privateRecord17, int*, 0x28);
            if (temporaryValue3 >= 0) {
                if ((Level11_7E800Field(privateRecord17, unsigned char*, 0x33) != 1) ||
                    !(Level11_7E800Field(((temporaryValue3 * 0x58) + Level11_7E800Data6C550View),
                                         unsigned char*, 0x48) &
                      0x80)) {
                    if (originalFlagOrSignedIndex20 != 0) {
                        Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 0U;
                        goto callOriginalStateZero733;
                    }
                } else {
                    goto storeOriginalStateZero732;
                }
            }
            break;
        case 3:
            if (Level11_7E800Data6E344View != 1) {
                if ((Level11_7E800Field(privateRecord17, unsigned char*, 0x33) == 3) &&
                    (Level11_7E800Field(privateRecord17, unsigned char*, 4) == 1)) {
                    Level11_7E800Field(ownerRecord18, unsigned char*, 0x49) = 0U;
                    Level11_7E800Field(privateRecord17, int*, 0x48) = 0x3C;
                    Level11_7E800Call34F40View(ownerRecord18, 0U);
                    Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 0x15U;
                    return;
                }
            storeOriginalStateZero732:
                Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 0U;
            callOriginalStateZero733:
                Level11_7E800Call34F40View(ownerRecord18, 0U);
                return;
            }
            break;
        case 4:
            if (Level11_7E800Field(privateRecord17, unsigned char*, 0x32) != 0) {
                originalFrame.sp28 = (Level11_7E800DatarandView() & 0xF) - 8;
                originalFrame.sp2C = (Level11_7E800DatarandView() & 0xF) - 8;
                originalFrame.sp30 = (Level11_7E800DatarandView() & 0xF) + 8;
                temporaryValue20 = Level11_7E800DataSpawnParticleView(1, 0x37, ownerRecord18 + 0xC,
                                                                      &originalFrame.sp28);
                if (temporaryValue20 != 0) {
                    Level11_7E800Field(temporaryValue20, unsigned short*, 8) =
                        (unsigned short)(Level11_7E800Field(temporaryValue20, unsigned short*, 8) +
                                         (Level11_7E800DatarandView() & 0xFF));
                }
            }
            if (Level11_7E800Data6C770View != 0) {
                Level11_7E800Field(privateRecord17, unsigned char*, 0x32) = 0U;
                Level11_7E800Call34F40View(
                    ownerRecord18, Level11_7E800Field(privateRecord17, unsigned char*, 0x31));
                Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) =
                    (unsigned char)Level11_7E800Field(privateRecord17, unsigned char*, 0x30);
                return;
            }
            break;
        case 21:
            if (Level11_7E800CountTimerDownView(privateRecord17 + 0x48, 4) != 0) {
                Level11_7E800Call34F40View(ownerRecord18, 2U);
                Level11_7E800Field(ownerRecord18, unsigned char*, 0x48) = 0x14U;
            }
            goto updateOriginalSharedWord893;
        case 20:
            temporaryValue23 = Level11_7E800Field(ownerRecord18, unsigned char*, 0x49);
            originalFlagOrSignedIndex20 =
                Level11_7E800Field(Level11_7E800Field(privateRecord17, void**, 0x20), short*, 2);
            switch (temporaryValue23) {
                case 0:
                    if (Level11_7E800Call35A80View(
                            ownerRecord18, Level11_7E800Field(privateRecord17, void**, 0x20), 0x200,
                            0x80, 0, 8, 0xC, 5) &
                        1) {
                        temporaryValue12 = Level11_7E800Field(privateRecord17, void**, 0x20);
                        temporaryValue15 = Level11_7E800Field(temporaryValue12, short*, 2);
                        if (temporaryValue15 != 0) {
                            temporaryValue24 = Level11_7E800Field(temporaryValue12, void**, 0xC);
                            if (Level11_7E800Field(
                                    ((originalFlagOrSignedIndex20 * 0x10) + temporaryValue24), int*,
                                    0xC) &
                                1) {
                                Level11_7E800Field(privateRecord17, int*, 0x48) =
                                    Level11_7E800Call365E4View(ownerRecord18 + 0xC,
                                                               temporaryValue24 +
                                                                   (temporaryValue15 * 0x10),
                                                               0x80, -0xC, 0);
                                Level11_7E800Field(ownerRecord18, unsigned char*, 0x49) = 1U;
                            }
                            goto updateOriginalSharedWord893;
                        }
                        goto deleteOriginalOwner874;
                    }
                    goto updateOriginalSharedWord893;
                case 1:
                    rawWord2 = Level11_7E800Call35A80View(
                        ownerRecord18, Level11_7E800Field(privateRecord17, void**, 0x20), 512, 128,
                        0, 8, 12, 0);
                    argumentWord4 = (int)&originalFrame.sp38;
                    MATCHING_KEEP(argumentWord4);
                    initializedSpeedOrOwnerPosition19 = (int)ownerRecord18 + 12;
                    MATCHING_KEEP(initializedSpeedOrOwnerPosition19);
                    argumentWord6 = Level11_7E800Field(privateRecord17, int*, 0x48);
                    argumentWord5 = initializedSpeedOrOwnerPosition19;
                    argumentWord6 -= 12;
                    Level11_7E800Field(privateRecord17, int*, 0x48) = argumentWord6;
                    rawWord3 = Level11_7E800Field(ownerRecord18, int*, 20);
                    createdRecordOrRetainedResult16 = rawWord2;
                    rawWord3 += argumentWord6;
                    Level11_7E800Field(ownerRecord18, int*, 20) = rawWord3;
                    Level11_7E800CopyVectorView(argumentWord4, argumentWord5, argumentWord6);
                    rawWord2 = originalFrame.sp40;
                    rawWord2 += 512;
                    originalFrame.sp40 = rawWord2;
                    rawWord2 = createdRecordOrRetainedResult16 & 1;
                    if (rawWord2) {
                        temporaryValue13 = Level11_7E800Field(privateRecord17, void**, 0x20);
                        temporaryValue16 = Level11_7E800Field(temporaryValue13, short*, 2);
                        if (temporaryValue16 == 0) {
                        deleteOriginalOwner874:
                            Level11_7E800DeleteMobyView(ownerRecord18);
                            return;
                        }
                        temporaryValue25 = Level11_7E800Field(temporaryValue13, void**, 0xC);
                        if (Level11_7E800Field(
                                ((originalFlagOrSignedIndex20 * 0x10) + temporaryValue25), int*,
                                0xC) &
                            1) {
                            Level11_7E800Field(privateRecord17, int*, 0x48) =
                                Level11_7E800Call365E4View(
                                    initializedSpeedOrOwnerPosition19,
                                    temporaryValue25 + (temporaryValue16 * 0x10), 0x80, -0xC, 0);
                        }
                        goto updateOriginalSharedWord893;
                    }
                    goto updateOriginalSharedWord893;
                default:
                    goto updateOriginalSharedWord893;
            }
        updateOriginalSharedWord893:
            Level11_7E800Field(&Level11_7E800Data70328View, int*, 0x20C) = 0x10000002;
            Level11_7E800Call492DCView(ownerRecord18 + 0xC);
            break;
    }
}
#undef Level11_7E800Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_11/moby/func_level_11_8007F630.s SHA256 d92400bdcbb3eef51882710da8fc23bef45530fed9b6d3daf54f52acc9570846. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level11_F630Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level11_F630_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level11_F630_D_80065920[0x100] __asm__("D_80065920");
extern unsigned char Level11_F630_D_80066BC8[20] __asm__("D_80066BC8");
extern Moby* Level11_F630_D_8006C550 __asm__("D_8006C550");
extern int Level11_F630_D_8006C648 __asm__("D_8006C648");
extern SoundTable* Level11_F630_D_8006C654 __asm__("D_8006C654");
extern Spyro Level11_F630_D_80070328 __asm__("D_80070328");
int Level11_F630CountTimerDown(void*, int) __asm__("func_800359A4");
int Level11_F630PlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
extern void Level11_F630CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern int Level11_F630_rand() __asm__("rand");

extern unsigned short** Level11_F630_D_8006C730 __asm__("D_8006C730");
extern unsigned char* Level11_F630_D_8006EE2C[] __asm__("D_8006EE2C");
extern signed char Level11_F630_D_800715B3 __asm__("D_800715B3");
extern short Level11_F630_D_800719DC __asm__("D_800719DC");
extern unsigned char Level11_F630_D_level_11_80091ED4 __asm__("D_level_11_80091ED4");

void func_level_11_8007F630(Moby* inputOwner) {
    /* Original 0x40 frame with scratch vectors at SP10 and SP20. Pointer
     * table 6C730 is loaded before the halfword list;
      its cursor advances
     * two bytes, and each masked index addresses the 88-byte Moby pool.
     * The signed byte sum, distinct table reads, model-header pointer chain
     * and repeated field stores follow the original instructions. Empty
     * constraints retain raw register producers and emit no instructions.
     * Helper/SFX meanings, physical units/fixed point, cadence and runtime
     * capture validation remain unresolved. AI generated;
      not human reviewed. */
    register Moby* owner17 __asm__("$17") = inputOwner;
    struct {
        int first[4];
        int second[4];
    } scratch;
    register Moby* spawned16 __asm__("$16");
    register int anchorIndex4 __asm__("$4");
    register int sineSample4 __asm__("$4");
    register unsigned char* model2 __asm__("$2");
    int counter;
    int updatedCounter;
    register int inactiveCount6 __asm__("$6");
    register signed char* particle16 __asm__("$16");
    register signed char* alternateParticle16 __asm__("$16");
    register int raw2 __asm__("$2");
    register int raw3 __asm__("$3");
    register unsigned short* list4 __asm__("$4");
    register int listWord5 __asm__("$5");
    register int selector4 __asm__("$4");
    unsigned char reloadedColourByte;
    register int state3 __asm__("$3");
    unsigned char colourByte;
    register void* anchorPrivate4 __asm__("$4");
    register Moby* pool7 __asm__("$7");
    register void* private18 __asm__("$18");
    void* temp_v0;

    MATCHING_KEEP(owner17);
    private18 = owner17->mobyTag;
    MATCHING_KEEP(private18);
    counter = Level11_F630Field(private18, int*, 0);
    if (counter != 0) {
        updatedCounter = counter + Level11_F630_D_8006C648;
        Level11_F630Field(private18, int*, 0) = updatedCounter;
        if (updatedCounter < 0x40) {
            owner17->angle.roll = *(unsigned char*)(((updatedCounter >> 1) * 2) +
                                                    Level11_F630Field(private18, int*, 0x1C)) +
                                  Level11_F630Field(private18, int*, 8);
            owner17->angle.pitch =
                Level11_F630Field(((((int)Level11_F630Field(private18, int*, 0) >> 1) * 2) +
                                   Level11_F630Field(private18, int*, 0x1C)),
                                  unsigned char*, 1) +
                Level11_F630Field(private18, int*, 0xC);
            temp_v0 = (((int)Level11_F630Field(private18, int*, 0) >> 1) * 2) +
                      Level11_F630Field(private18, int*, 0x1C);
            raw3 = Level11_F630Field(temp_v0, signed char*, 0);
            raw2 = Level11_F630Field(temp_v0, signed char*, 1);
            if (raw3 < 0) {
                raw3 = -raw3;
            }
            if (raw2 < 0) {
                raw2 = -raw2;
            }
            raw3 += raw2;
            MATCHING_KEEP(raw3);
            raw2 = raw3 * 3;
            raw3 = Level11_F630Field(private18, int*, 16);
            raw2 *= 2;
            raw3 += raw2;
            MATCHING_KEEP(raw3);
            owner17->position.z = raw3;
        } else {
            Level11_F630Field(private18, int*, 0) = 0;
            owner17->angle.roll = (unsigned char)Level11_F630Field(private18, int*, 8);
            owner17->angle.pitch = (unsigned char)Level11_F630Field(private18, int*, 0xC);
            owner17->position.z = Level11_F630Field(private18, int*, 0x10);
        }
    }
    if ((owner17->damageFlags & 0x10000) && (Level11_F630Field(private18, int*, 0x18) == 0)) {
        if (owner17->state == 0) {
            Level11_F630PlayMobySoundEvent(owner17, 0, 0);
            Level11_F630Field(private18, int*, 0x18) = 0x78;
            selector4 = owner17->animationRun;
            owner17->state = 2;
            owner17->colour.r = 0x7F;
            owner17->colour.g = 0x7F;
            owner17->colour.b = 0x7F;
            owner17->colour.a = 0;
            if (selector4 != 0xFF) {
                inactiveCount6 = 0;
                list4 = Level11_F630_D_8006C730[selector4];
                pool7 = Level11_F630_D_8006C550;
                do {
                    listWord5 = *list4;
                    raw2 = listWord5 & 0x7FFF;
                    MATCHING_KEEP(raw2);
                    raw3 = raw2 * 88;
                    raw3 += (int)pool7;
                    raw2 = Level11_F630Field((void*)raw3, unsigned char*, 72);
                    if (!raw2) {
                        inactiveCount6 += 1;
                    }
                    raw2 = listWord5 << 16;
                    list4 += 1;
                } while (raw2 >= 0);
                if (inactiveCount6 == 0) {
                    *Level11_F630_D_80066BC8 = 3;
                    Level11_F630_D_800719DC = 1;
                    PlaySound((int)Level11_F630_D_8006C654->skillPoint, owner17, 0xA1);
                    spawned16 = SpawnMoby(0xD3, owner17);
                    MATCHING_KEEP(spawned16);
                    if (spawned16 != 0) {
                        Level11_F630CopyVector(&spawned16->position,
                                               &Level11_F630_D_80070328.position);
                        raw2 = Level11_F630_D_80070328.bodyRotation.yaw;
                        raw2 *= 2;
                        raw3 = *(short*)((unsigned char*)Level11_F630_D_80065920 + raw2);
                        raw2 = raw3 * 25;
                        MATCHING_KEEP(raw2);
                        raw3 = spawned16->position.x;
                        raw2 >>= 7;
                        raw3 += raw2;
                        spawned16->position.x = raw3;
                        MATCHING_BARRIER_VOLATILE("memory");
                        raw2 = Level11_F630_D_80070328.bodyRotation.yaw;
                        raw3 = spawned16->position.z;
                        raw2 *= 2;
                        sineSample4 = *(short*)((unsigned char*)Level11_F630_D_800658A0 + raw2);
                        raw3 += 500;
                        spawned16->position.z = raw3;
                        raw3 = spawned16->position.y;
                        raw2 = sineSample4 * 25;
                        raw2 >>= 7;
                        raw3 += raw2;
                        spawned16->position.y = raw3;
                    }
                }
            }
        } else {
            Level11_F630Field(private18, int*, 0x18) = 0x3C;
            owner17->state = 3;
        }
    }
    if ((owner17->damageFlags & 0x20000) && (Level11_F630Field(private18, int*, 0) == 0)) {
        Level11_F630Field(private18, int*, 0) = 1;
        Level11_F630Field(private18, int*, 8) = (int)owner17->angle.roll;
        Level11_F630Field(private18, int*, 0xC) = (int)owner17->angle.pitch;
        Level11_F630Field(private18, int*, 0x10) = (int)owner17->position.z;
        Level11_F630PlayMobySoundEvent(owner17, 1, 0);
    }
    state3 = owner17->state;
    owner17->damageFlags = 0;
    switch (state3) { /* irregular */
        case 0:
            owner17->colour.r = 0x80;
            owner17->colour.g = 0x80;
            anchorIndex4 = Level11_F630Field(private18, int*, 4);
            MATCHING_KEEP(anchorIndex4);
            if (anchorIndex4 >= 0) {
                raw2 = anchorIndex4 * 88;
                raw3 = (int)Level11_F630_D_8006C550;
                raw2 += raw3;
                anchorPrivate4 = Level11_F630Field((void*)raw2, void**, 0);
                raw3 = Level11_F630Field(anchorPrivate4, int*, 36);
                raw2 = (int)&Level11_F630_D_level_11_80091ED4;
                if (raw3 == raw2) {
                    if (Level11_F630Field(anchorPrivate4, int*, 0x34) != 0) {
                        Level11_F630_D_800715B3 = 1;
                        Level11_F630Field(anchorPrivate4, int*, 0x34) = 0;
                    }
                }
            }
            owner17->colour.b = 0x80;
            owner17->colour.a = 0;
            return;
        case 2:
            if (Level11_F630CountTimerDown(private18 + 0x18, 4) != 0) {
                owner17->colour.r = 0;
                owner17->colour.g = 0;
                owner17->colour.b = 0;
                owner17->colour.a = 0;
                raw3 = 1;
                MATCHING_KEEP(raw3);
                raw2 = owner17->mobyClass;
                owner17->state = raw3;
                model2 = Level11_F630_D_8006EE2C[raw2];
                model2 = Level11_F630Field(model2, unsigned char**, 64);
                raw2 = model2[0];
                MATCHING_BARRIER_VOLATILE("memory");
                owner17->animationState.id = raw3;
                owner17->animationState.nextId = raw3;
                owner17->animationState.frame = 0;
                owner17->animationState.nextFrame = raw3;
                raw2 = (unsigned int)raw2 < 2;
                MATCHING_KEEP(raw2);
                raw2 ^= 1;
                raw2 = -raw2;
                raw2 &= 48;
                owner17->animationProgress = raw2;
                return;
            }
            scratch.first[0] = (Level11_F630_rand() & 0xF) - 8;
            scratch.first[1] = (Level11_F630_rand() & 0xF) - 8;
            scratch.first[2] = (Level11_F630_rand() & 0xF) + 8;
            particle16 = SpawnParticle(1, 0x37, &owner17->position, (Vector3D*)&scratch.first[0]);
            if (particle16 != 0) {
                Level11_F630Field(particle16, signed char*, 0x11) = 7;
                raw2 = Level11_F630_rand();
                raw3 = Level11_F630Field(particle16, unsigned short*, 8);
                raw2 &= 511;
                raw3 += 128;
                MATCHING_KEEP(raw3);
                raw3 += raw2;
                Level11_F630Field(particle16, unsigned short*, 8) = raw3;
            }
            colourByte = owner17->colour.r;
            if (colourByte >= 5U) {
                owner17->colour.r = colourByte - 4;
            } else {
                owner17->colour.r = 0;
            }
            reloadedColourByte = owner17->colour.r;
            owner17->colour.b = reloadedColourByte;
            owner17->colour.g = reloadedColourByte;
            owner17->colour.a = (unsigned char)((int)(0x7F - owner17->colour.r) >> 3);
            return;
        case 3:
            if (Level11_F630CountTimerDown(private18 + 0x18, 4) != 0) {
                owner17->state = 1;
                return;
            }
            scratch.second[0] = (Level11_F630_rand() & 0xF) - 8;
            scratch.second[1] = (Level11_F630_rand() & 0xF) - 8;
            scratch.second[2] = (Level11_F630_rand() & 0xF) + 8;
            alternateParticle16 =
                SpawnParticle(1, 1, &owner17->position, (Vector3D*)&scratch.second[0]);
            if (alternateParticle16 != 0) {
                Level11_F630Field(alternateParticle16, signed char*, 0x11) = 6;
                raw2 = Level11_F630_rand();
                raw3 = Level11_F630Field(alternateParticle16, unsigned short*, 8);
                raw2 &= 511;
                raw3 += 128;
                MATCHING_KEEP(raw3);
                raw3 += raw2;
                Level11_F630Field(alternateParticle16, unsigned short*, 8) = raw3;
            }
        case 1:
            return;
    }
}
#undef Level11_F630Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_11/moby/func_level_11_8007FC04.s SHA256 4d771289b47f7b779837e0536464e7b38b43f702e1b1974d2395a21b890bc735. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level11_7FC04Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level11_7FC04_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level11_7FC04_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level11_7FC04_D_8006C550 __asm__("D_8006C550");
extern Spyro Level11_7FC04_D_80070328 __asm__("D_80070328");
void Level11_7FC04RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level11_7FC04_func_80035194(Moby*, void*) __asm__("func_80035194");
int Level11_7FC04TurnMobyTowardPlayer(Moby* ownerRecord16, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level11_7FC04TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
int Level11_7FC04ProbeGroundFromRaisedMoby(Moby* moby) __asm__("func_80035D38");
int Level11_7FC04_func_80035EE0(Moby*, int, int, int, int, int) __asm__("func_80035EE0");
void Level11_7FC04_func_800369B8() __asm__("func_800369B8");
void Level11_7FC04_func_80038BF8(Moby*, EnemyTag*, int, int) __asm__("func_80038BF8");
void Level11_7FC04_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
int Level11_7FC04PlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
void Level11_7FC04_func_8003BE70(int) __asm__("func_8003BE70");
int Level11_7FC04_func_8003BFC0(Moby*, int) __asm__("func_8003BFC0");
extern int Level11_7FC04PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level11_7FC04AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level11_7FC04AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level11_7FC04ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level11_7FC04DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level11_7FC04RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level11_7FC04_func_80055E84(Moby*) __asm__("func_80055E84");

int Level11_7FC04_func_80018368() __asm__("func_80018368");
/* extern */
int Level11_7FC04_func_80035A80() __asm__("func_80035A80");
/* extern */
int Level11_7FC04_func_80036220() __asm__("func_80036220");
/* extern */
int Level11_7FC04_func_800365E4() __asm__("func_800365E4");
/* extern */
unsigned int Level11_7FC04_func_80036A68() __asm__("func_80036A68");
/* extern */
extern int Level11_7FC04_D_8006C770 __asm__("D_8006C770");
extern int Level11_7FC04_D_8006E020 __asm__("D_8006E020");
extern int Level11_7FC04_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level11_7FC04_D_8006E040 __asm__("D_8006E040");
extern int Level11_7FC04_D_8006E344 __asm__("D_8006E344");

void func_level_11_8007FC04(Moby* ownerRecord16) {
    /* Original0x50-byte frame;
     scratch atSP+0x20, savedS0 atSP+0x38.
     * Raw pointer and field literals preserve original byte offsets.
     * Cached state3 feeds the compiler's original51-entry switch range.
     * Native446..469 passes8 arguments to35A80;
      original branch selects
     * stack argument5 as0/300, followed by6/40/selected saved18 word.
     * Signed table LH2 and adjacent caller/512-word producers are explicit.
     * All empty constraints have initialized inputs;
      no instruction asm.
     * Literal4 is produced before the second private+8 pointer load.
     * Shared state/reset tails retain original calls and branch joins.
     * Units/helper semantics/frame cadence unresolved;
      per invocation only. */
    struct {
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        unsigned char sp30;
        unsigned char pad31[7];
    } originalFrame;

    Moby* temp_a0;
    Moby* temp_a0_4;
    Moby* temp_a1_2;
    Moby* temp_v0_5;
    Vector3D* temp_s2;
    Vector3D* temp_s2_2;
    int temp_v0_4;
    int temp_v1_10;
    int temp_v1_3;
    int temp_v1_5;
    int temp_v1_9;
    register int var_a1 __asm__("5");
    register Moby* stateOwner4 __asm__("4");
    register int selectedWord18 __asm__("18");
    int var_s2_2;
    int var_v0;
    int var_v0_2;
    int var_v0_3;
    int helperResult3;
    register int selectedBit2 __asm__("2");
    unsigned int modeWord4;
    register unsigned int temp_v0_6 __asm__("4");
    unsigned int temp_v1_2;
    register unsigned int temp_v1 __asm__("3");
    register unsigned int nextRawState19 __asm__("19");
    void* temp_a0_2;
    void* temp_a1;
    void* privateRecord17;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v1_4;
    void* temp_v1_6;
    void* selectedData3;
    void* temp_v1_8;

    privateRecord17 = ownerRecord16->mobyTag;
    if (ownerRecord16->damageFlags != 0) {
        temp_v1 = ownerRecord16->state;
        if (temp_v1 != 8) {
            if (Level11_7FC04_func_8003BFC0(ownerRecord16,
                                            Level11_7FC04Field(privateRecord17, int*, 0x60)) != 0) {
                Level11_7FC04_func_8003BE70(Level11_7FC04Field(privateRecord17, int*, 0x60));
            }
            Level11_7FC04Field(privateRecord17, int*, 0x60) = -1;
            Level11_7FC04_func_80038BF8(ownerRecord16, privateRecord17 + 0xC, 6, 8);
            ownerRecord16->state = 8;
            Level11_7FC04_func_80036A68(ownerRecord16, 0, 0, 0);
            goto block_5;
        }
    } else {
    block_5:
        temp_v1 = ownerRecord16->state;
    }

        switch (temp_v1) { /* switch 1 */
        case 0:
            MATCHING_OBSERVE(temp_v1);
            /* switch 1 */
            selectedWord18 = 0;
            temp_v1_2 = Level11_7FC04Field(privateRecord17, unsigned int*, 0);
            nextRawState19 = -1U;
            switch (temp_v1_2) { /* switch 2 */
                case 0:          /* switch 2 */
                    if ((Level11_7FC04_D_8006E344 != 0xE) &&
                        (Level11_7FC04Field(privateRecord17, void**, 4) != 0) &&
                        (Level11_7FC04_func_80036220(&Level11_7FC04_D_80070328,
                                                     privateRecord17 + 0x28, 0, 0) != 0)) {
                        MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(privateRecord17, nextRawState19,
                                                               "memory");
                        nextRawState19 = 4;
                        goto block_44;
                    }
                    break;
                case 1: /* switch 2 */
                    temp_v1_3 = Level11_7FC04Field(privateRecord17, int*, 0x5C);
                    if ((temp_v1_3 < 0) || (Level11_7FC04_D_8006C550[temp_v1_3].state == 0)) {
                        nextRawState19 = 2;
                        goto block_44;
                    }
                    break;
                case 2: /* switch 2 */
                    if (Level11_7FC04ApproximatePlanarDistance(&ownerRecord16->position,
                                                               &Level11_7FC04_D_80070328.position) <
                        Level11_7FC04Field(privateRecord17, int*, 0x58)) {
                        var_v0_2 = ((ownerRecord16->position.z - ownerRecord16->distanceToGround) -
                                    Level11_7FC04_D_80070328.position.z) +
                                   Level11_7FC04_D_80070328.unk4a;
                        if (var_v0_2 < 0) {
                            var_v0_2 = -var_v0_2;
                        }
                        if ((var_v0_2 < 0x200) &&
                            (Level11_7FC04AbsoluteByteAngleDelta(
                                 (int)(Level11_7FC04_D_8006E040 << 0x10) >> 0x14,
                                 Level11_7FC04PlanarHeadingLookup(
                                     ownerRecord16->position.x - Level11_7FC04_D_8006E020,
                                     ownerRecord16->position.y - Level11_7FC04_D_8006E024, 0)) <
                             0x1C)) {
                            Level11_7FC04Field(privateRecord17, void**, 4) = 0;
                        } else {
                            goto block_23;
                        }
                    } else {
                    block_23:
                        if ((Level11_7FC04Field(privateRecord17, void**, 4) != 0) &&
                            (Level11_7FC04_func_80036220(&Level11_7FC04_D_80070328,
                                                         privateRecord17 + 0x28, 0, 0) != 0)) {
                            nextRawState19 = 4;
                            goto block_44;
                        }
                    }
                    break;
                case 3: /* switch 2 */
                    if ((Level11_7FC04_D_8006E344 != 0xE) &&
                        (Level11_7FC04Field(privateRecord17, void**, 4) != 0) &&
                        (Level11_7FC04_func_80036220(&Level11_7FC04_D_80070328,
                                                     privateRecord17 + 0x28, 0, 0) != 0)) {
                        MATCHING_BARRIER_GNU_VOLATILE("19");
                        nextRawState19 = 4;
                        goto block_44;
                    }
                    if ((Level11_7FC04Field(privateRecord17, void**, 8) != 0) &&
                        (Level11_7FC04_func_80036220(&Level11_7FC04_D_80070328,
                                                     privateRecord17 + 0x40, 0, 0) != 0)) {
                        nextRawState19 = 4;
                        temp_v0 = Level11_7FC04Field(privateRecord17, void**, 8);
                        selectedWord18 = 1;
                        Level11_7FC04Field(privateRecord17, void**, 8) = 0;
                        Level11_7FC04Field(privateRecord17, void**, 4) = temp_v0;
                    }
                    break;
                case 4: /* switch 2 */
                case 5: /* switch 2 */
                    if ((Level11_7FC04Field(privateRecord17, void**, 4) != 0) &&
                        (Level11_7FC04ApproximatePlanarDistance(
                             &ownerRecord16->position, &Level11_7FC04_D_80070328.position) <
                         Level11_7FC04Field(privateRecord17, int*, 0x58))) {
                        if (Level11_7FC04Field(privateRecord17, unsigned int*, 0) == 5) {
                            temp_v1_4 = Level11_7FC04Field(privateRecord17, void**, 4);
                            Level11_7FC04Field(temp_v1_4, short*, 2) =
                                (short)(Level11_7FC04Field(temp_v1_4, unsigned short*, 0) - 1);
                            Level11_7FC04Field(Level11_7FC04Field(privateRecord17, void**, 4),
                                               short*, 0xA) = -1;
                        }
                        temp_v1_5 = Level11_7FC04Field(privateRecord17, int*, 0x5C);
                        nextRawState19 = 4;
                        if (temp_v1_5 >= 0) {
                            temp_a0 = (Moby*)(((temp_v1_5) * 0x58) + (int)Level11_7FC04_D_8006C550);
                            if (!(temp_a0->state & 0x80) &&
                                (temp_a0->mobyClass == ownerRecord16->mobyClass)) {
                                temp_a0_2 = temp_a0->mobyTag;
                                if (Level11_7FC04Field(temp_a0_2, int*, 0) == 5) {
                                    temp_v1_6 = Level11_7FC04Field(temp_a0_2, void**, 4);
                                    Level11_7FC04Field(temp_v1_6, short*, 2) =
                                        (short)(Level11_7FC04Field(temp_v1_6, unsigned short*, 0) -
                                                1);
                                    Level11_7FC04Field(Level11_7FC04Field(temp_a0_2, void**, 4),
                                                       short*, 0xA) = -1;
                                }
                                Level11_7FC04RequestMobyAnimation(
                                    (Moby*)((int)Level11_7FC04_D_8006C550 +
                                            ((Level11_7FC04Field(privateRecord17, int*, 0x5C)) *
                                             0x58)),
                                    4);
                                Level11_7FC04_D_8006C550[Level11_7FC04Field(privateRecord17, int*,
                                                                            0x5C)]
                                    .state = nextRawState19;
                            }
                        }
                        goto block_44;
                    }
                    break;
                case 6: /* switch 2 */
                    nextRawState19 = 5;
                block_44:
                    selectedWord18 = 1;
            }
            MATCHING_KEEP2(selectedWord18, nextRawState19);
            if (selectedWord18 != 0) {
                ownerRecord16->state = nextRawState19;
                Level11_7FC04RequestMobyAnimation(ownerRecord16, (int)nextRawState19);
                return;
            }
            MATCHING_KEEP(selectedWord18);
            if ((Level11_7FC04Field(privateRecord17, void**, 4) == 0) &
                (Level11_7FC04Field(privateRecord17, void**, 8) == 0)) {
                Level11_7FC04TurnMobyTowardPlayer(ownerRecord16, 4, 0, 1);
                if (Level11_7FC04ApproximatePlanarDistance(
                        &ownerRecord16->position, &Level11_7FC04_D_80070328.position) >= 0x1800) {
                    return;
                }
                goto block_101;
            }
            break;
        case 4: /* switch 1 */
            Level11_7FC04_func_80035A80(ownerRecord16,
                                        Level11_7FC04Field(privateRecord17, void**, 4), 0x100, 0x14,
                                        0x12C, 6, 4, 6);
            if (Level11_7FC04_D_8006C770 != 0) {
                ownerRecord16->state = 2;
                Level11_7FC04RequestMobyAnimation(ownerRecord16, 2);
                return;
            }
            break;
        case 2: /* switch 1 */
            if (Level11_7FC04Field(privateRecord17, unsigned int*, 0) == 2) {
                temp_v0_2 = Level11_7FC04Field(privateRecord17, void**, 4);
                if ((Level11_7FC04Field(temp_v0_2, short*, 2) <
                     ((int)(Level11_7FC04Field(temp_v0_2, unsigned short*, 0) << 0x10) >> 0x11)) &&
                    (Level11_7FC04ApproximatePlanarDistance(&ownerRecord16->position,
                                                            &Level11_7FC04_D_80070328.position) <
                     Level11_7FC04Field(privateRecord17, int*, 0x58))) {
                    var_v0_3 = ((ownerRecord16->position.z - ownerRecord16->distanceToGround) -
                                Level11_7FC04_D_80070328.position.z) +
                               Level11_7FC04_D_80070328.unk4a;
                    if (var_v0_3 < 0) {
                        var_v0_3 = -var_v0_3;
                    }
                    if (var_v0_3 < 0x200) {
                        temp_v0_3 = Level11_7FC04Field(privateRecord17, void**, 4);
                        Level11_7FC04Field(temp_v0_3, short*, 2) =
                            (short)(Level11_7FC04Field(temp_v0_3, unsigned short*, 0) -
                                    (unsigned short)Level11_7FC04Field(temp_v0_3, short*, 2));
                        goto block_64;
                    }
                    goto block_59;
                }
            block_59:
                goto block_60;
            }
        block_60:
            if ((Level11_7FC04Field(privateRecord17, unsigned int*, 0) == 1) &&
                (ownerRecord16->animationState.id == 2) &&
                (Level11_7FC04ApproximatePlanarDistance(
                     &ownerRecord16->position, &Level11_7FC04_D_80070328.position) < 0x1800)) {
                Level11_7FC04RequestMobyAnimation(ownerRecord16, 0xA);
                ownerRecord16->state = 0x32;
                return;
            }
        block_64:
            if (ownerRecord16->substate != 0) {
                ownerRecord16->position.z += Level11_7FC04Field(privateRecord17, int*, 0x24);
                Level11_7FC04Field(privateRecord17, int*, 0x24) =
                    (int)(Level11_7FC04Field(privateRecord17, int*, 0x24) - 0xE);
                temp_v0_4 = Level11_7FC04ProbeGroundFromRaisedMoby(ownerRecord16);
                var_s2_2 = 3;
                if (temp_v0_4 >= ownerRecord16->position.z) {
                    ownerRecord16->position.z = temp_v0_4;
                    Level11_7FC04Field(privateRecord17, int*, 0x24) = 0;
                    ownerRecord16->substate = 0;
                    Level11_7FC04RequestMobyAnimation(ownerRecord16, 2);
                } else if (Level11_7FC04_D_8006C770 != 0) {
                    Level11_7FC04RequestMobyAnimation(ownerRecord16, 0xC);
                }
            } else {
                if (Level11_7FC04_D_8006C770 != 0) {
                    Level11_7FC04RequestMobyAnimation(ownerRecord16, 2);
                }
                var_s2_2 = 7;
                if ((unsigned int)(Level11_7FC04Field(privateRecord17, unsigned int*, 0) - 4) <
                    2U) {
                    var_s2_2 = 5;
                }
            }
            if (ownerRecord16->animationState.id != 0xD) {
                {
                    register int default3 __asm__("3");
                    default3 = 0;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(default3, "memory");
                }
                if ((unsigned int)(Level11_7FC04Field(privateRecord17, unsigned int*, 0) - 4) <
                    2U) {
                    helperResult3 = Level11_7FC04_func_80035A80(
                        ownerRecord16, Level11_7FC04Field(privateRecord17, void**, 4), 0x100, 0xC8,
                        0, 6, 0x28, var_s2_2);
                } else {
                    helperResult3 = Level11_7FC04_func_80035A80(
                        ownerRecord16, Level11_7FC04Field(privateRecord17, void**, 4), 0x100, 0xC8,
                        0x12C, 6, 0x28, var_s2_2);
                }
            } else {
                helperResult3 = 0;
            }
            {
                register int flags3 __asm__("3");
                flags3 = helperResult3;
                MATCHING_KEEP(flags3);
                helperResult3 = flags3;
            }
            modeWord4 = Level11_7FC04Field(privateRecord17, unsigned int*, 0);
            if ((modeWord4 != 1) && (helperResult3 & 2)) {
                if ((modeWord4 == 2) && (Level11_7FC04Field(privateRecord17, void**, 8) != 0) &&
                    (Level11_7FC04Field(privateRecord17, int*, 0x5C) >= 0)) {
                    {
                        register unsigned int type2 __asm__("2");
                        type2 = 4;
                        MATCHING_KEEP(type2);
                        selectedData3 = Level11_7FC04Field(privateRecord17, void* volatile*, 8);
                        Level11_7FC04Field(privateRecord17, unsigned int*, 0) = type2;
                    }
                    Level11_7FC04Field(privateRecord17, void**, 8) = 0;
                    Level11_7FC04Field(privateRecord17, void**, 4) = selectedData3;
                } else {
                    stateOwner4 = ownerRecord16;
                    var_a1 = 0;
                    MATCHING_KEEP2(stateOwner4, var_a1);
                    Level11_7FC04Field(privateRecord17, void**, 4) = 0;
                    Level11_7FC04Field(privateRecord17, void**, 8) = 0;
                    ownerRecord16->state = 0;
                    goto block_88;
                }
            } else if ((({
                           selectedBit2 = helperResult3 & 1;
                           __asm__("" : "=r"(selectedBit2) : "0"(selectedBit2), "r"(helperResult3));
                           selectedBit2;
                       }))) {
                temp_v1_8 = Level11_7FC04Field(privateRecord17, void**, 4);
                temp_a1 = (Level11_7FC04Field(temp_v1_8, short*, 2) * 0x10) +
                          Level11_7FC04Field(temp_v1_8, int*, 0xC);
                if (Level11_7FC04Field(temp_a1, int*, 0xC) != 0) {
                    {
                        int helperWord = Level11_7FC04_func_800365E4(
                            &ownerRecord16->position, temp_a1, 0xC8, -0xE, &originalFrame.sp30);
                        stateOwner4 = ownerRecord16;
                        var_a1 = 0xB;
                        MATCHING_KEEP2(stateOwner4, var_a1);
                        Level11_7FC04Field(privateRecord17, int*, 0x24) = helperWord;
                    }
                    ownerRecord16->substate = 1;
                block_88:
                    Level11_7FC04RequestMobyAnimation(stateOwner4, var_a1);
                }
            }
            {
                register Vector3D* frame4 __asm__("4");
                register Vector3D* frame5 __asm__("5");
                register Vector3D* position18 __asm__("18");
                register Vector3D* position6 __asm__("6");
                register int word2 __asm__("2");
                register int literal3 __asm__("3");
                frame4 = (Vector3D*)&originalFrame.sp20;
                word2 = ownerRecord16->angle.yaw;
                MATCHING_KEEP_CLOBBER(word2, "5");
                frame5 = frame4;
                MATCHING_KEEP2(word2, frame5);
                word2 = Level11_7FC04_D_80065920[word2];
                MATCHING_KEEP_CLOBBER(word2, "18");
                position18 = &ownerRecord16->position;
                __asm__("" : "=r"(position18) : "0"(position18), "r"(word2));
                originalFrame.sp20 = word2 >> 3;
                word2 = ownerRecord16->angle.yaw;
                MATCHING_KEEP_CLOBBER(word2, "6");
                position6 = position18;
                MATCHING_KEEP2(word2, position6);
                word2 = Level11_7FC04_D_800658A0[word2];
                MATCHING_KEEP_CLOBBER(word2, "3");
                literal3 = 0x200;
                MATCHING_KEEP2(word2, literal3);
                originalFrame.sp28 = literal3;
                __asm__("" : "=r"(word2) : "0"(word2), "m"(originalFrame.sp28));
                originalFrame.sp24 = word2 >> 3;
                Level11_7FC04AddVector(frame4, frame5, position6);
                temp_s2 = position18;
            }
            if (ownerRecord16->substate == 0) {
                ownerRecord16->position.z += 0x200;
                if (Level11_7FC04_func_80018368(temp_s2, &originalFrame.sp20) != 0) {
                    ownerRecord16->state = 6;
                    Level11_7FC04RequestMobyAnimation(ownerRecord16, 6);
                } else if ((unsigned int)(Level11_7FC04Field(privateRecord17, unsigned int*, 0) -
                                          4) < 2U) {
                    temp_v1_9 = Level11_7FC04Field(privateRecord17, int*, 0x5C);
                    if (temp_v1_9 >= 0) {
                        temp_a1_2 = (Moby*)(((temp_v1_9) * 0x58) + (int)Level11_7FC04_D_8006C550);
                        if (!(temp_a1_2->state & 0x80) &&
                            (Level11_7FC04ApproximatePlanarDistance(temp_s2, &temp_a1_2->position) <
                             0x258)) {
                            ownerRecord16->state = 6;
                            Level11_7FC04RequestMobyAnimation(ownerRecord16, 6);
                            temp_a0_4 =
                                (Moby*)(((Level11_7FC04Field(privateRecord17, int*, 0x5C)) * 0x58) +
                                        (int)Level11_7FC04_D_8006C550);
                            if (temp_a0_4->mobyClass == ownerRecord16->mobyClass) {
                                Level11_7FC04RequestMobyAnimation(temp_a0_4, 6);
                                Level11_7FC04_D_8006C550[Level11_7FC04Field(privateRecord17, int*,
                                                                            0x5C)]
                                    .state = 6;
                            }
                        }
                    }
                }
                ownerRecord16->position.z -= 0x200;
                return;
            }
            break;
        case 5: /* switch 1 */
            temp_v0_5 = (Moby*)(((Level11_7FC04Field(privateRecord17, int*, 0x5C)) * 0x58) +
                                (int)Level11_7FC04_D_8006C550);
            Level11_7FC04TurnMobyTowardHeading(
                ownerRecord16,
                Level11_7FC04PlanarHeadingLookup(temp_v0_5->position.x - ownerRecord16->position.x,
                                                 temp_v0_5->position.y - ownerRecord16->position.y,
                                                 0),
                4, 0, 1, 0);
            temp_s2_2 = &ownerRecord16->position;
            if (Level11_7FC04ApproximatePlanarDistance(
                    temp_s2_2, &Level11_7FC04_D_80070328.position) < 0x1800) {
            block_101:
                ownerRecord16->state = 0xA;
                Level11_7FC04RequestMobyAnimation(ownerRecord16, 0xA);
                return;
            }
            if (Level11_7FC04ApproximatePlanarDistance(
                    temp_s2_2,
                    &Level11_7FC04_D_8006C550[Level11_7FC04Field(privateRecord17, int*, 0x5C)]
                         .position) < 0x1000) {
                Level11_7FC04RequestMobyAnimation(ownerRecord16, 5);
                return;
            }
            if (Level11_7FC04_D_8006C770 != 0) {
                Level11_7FC04RequestMobyAnimation(ownerRecord16, 0);
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(privateRecord17, "memory");
                return;
            }
            break;
        case 50: /* switch 1 */
            if (Level11_7FC04_func_8003BFC0(ownerRecord16,
                                            Level11_7FC04Field(privateRecord17, int*, 0x60)) == 0) {
                Level11_7FC04Field(privateRecord17, int*, 0x60) =
                    Level11_7FC04PlayMobySoundEvent(ownerRecord16, 0, 4);
            }
            temp_v1_10 = Level11_7FC04Field(privateRecord17, int*, 0x5C);
            if ((temp_v1_10 < 0) || (Level11_7FC04_D_8006C550[temp_v1_10].state == 0)) {
                Level11_7FC04TurnMobyTowardPlayer(ownerRecord16, 4, 0, 1);
                if (Level11_7FC04ApproximatePlanarDistance(
                        &ownerRecord16->position, &Level11_7FC04_D_80070328.position) >= 0x1A01) {
                    if (Level11_7FC04_func_8003BFC0(
                            ownerRecord16, Level11_7FC04Field(privateRecord17, int*, 0x60)) != 0) {
                        Level11_7FC04_func_8003BE70(
                            Level11_7FC04Field(privateRecord17, int*, 0x60));
                    }
                    Level11_7FC04Field(privateRecord17, int*, 0x60) = -1;
                    ownerRecord16->state = 4;
                    Level11_7FC04RequestMobyAnimation(ownerRecord16, 4);
                    return;
                }
            }
            break;
        case 7:  /* switch 1 */
        case 10: /* switch 1 */
            if (Level11_7FC04_func_8003BFC0(ownerRecord16,
                                            Level11_7FC04Field(privateRecord17, int*, 0x60)) == 0) {
                Level11_7FC04Field(privateRecord17, int*, 0x60) =
                    Level11_7FC04PlayMobySoundEvent(ownerRecord16, 0, 4);
            }
            Level11_7FC04TurnMobyTowardPlayer(ownerRecord16, 4, 0, 1);
            if (Level11_7FC04ApproximatePlanarDistance(
                    &ownerRecord16->position, &Level11_7FC04_D_80070328.position) >= 0x1A01) {
                if (Level11_7FC04_func_8003BFC0(
                        ownerRecord16, Level11_7FC04Field(privateRecord17, int*, 0x60)) != 0) {
                    Level11_7FC04_func_8003BE70(Level11_7FC04Field(privateRecord17, int*, 0x60));
                }
                stateOwner4 = ownerRecord16;
                var_a1 = 0;
                MATCHING_KEEP2(stateOwner4, var_a1);
                Level11_7FC04Field(privateRecord17, int*, 0x60) = -1;
                goto block_125;
            }
            break;
        case 6: /* switch 1 */
            temp_v0_6 = Level11_7FC04_func_80055E84(ownerRecord16);
            MATCHING_KEEP(temp_v0_6);
            if ((ownerRecord16->animationState.id == 6) &&
                (({
                     register unsigned int difference2 __asm__("2");
                     difference2 = temp_v0_6 - 0x1F;
                     __asm__("" : "=r"(difference2) : "0"(difference2), "r"(temp_v0_6));
                     difference2;
                 }) < 0x18U)) {
                Level11_7FC04_func_80035EE0(ownerRecord16, (ownerRecord16->angle.yaw + 0x80) & 0xFF,
                                            0x14, 0, 0, 0);
            }
            if (Level11_7FC04_D_8006C770 != 0) {
                stateOwner4 = ownerRecord16;
                var_a1 = 0;
                MATCHING_KEEP2(stateOwner4, var_a1);
                Level11_7FC04Field(privateRecord17, void**, 4) = 0;
                Level11_7FC04Field(privateRecord17, void**, 8) = 0;
            block_125:
                stateOwner4->state = 0;
                Level11_7FC04RequestMobyAnimation(stateOwner4, var_a1);
                return;
            }
            break;
        case 8: /* switch 1 */
            if (Level11_7FC04_func_80035194(ownerRecord16, privateRecord17 + 0xC) == 0x100) {
                Level11_7FC04RefreshMobySpatialGridAndBasis(ownerRecord16, 4);
                Level11_7FC04_func_8003BA00(ownerRecord16);
                Level11_7FC04_func_800369B8(ownerRecord16, 0x24);
                Level11_7FC04DeleteMoby(ownerRecord16);
            }
            break;
    }
}
#undef Level11_7FC04Field


typedef struct {
    int reserved[6];
    unsigned char savedState, savedAnimation, emitParticle;
} DecodedDamageDialogueTag;
extern unsigned char DecodedDamageDialogueFlags __asm__("D_8006C7B4");
extern int D_8006E344, D_8006C770;
int rand(void);
int DecodedDamageDialogueStart(Moby*, int) __asm__("func_80037BBC");
void DecodedDamageDialogueCall(Moby*, int, int) __asm__("func_800512E4");
void func_level_11_80080900(Moby* moby) {
    DecodedDamageDialogueTag* tag = moby->mobyTag;
    Vector3D velocity;
    char* particle;
    if (moby->damageFlags) {
        if (moby->damageFlags & 0x10000)
            tag->emitParticle = 1;
        if (moby->state != 3) {
            tag->savedState = moby->state;
            tag->savedAnimation = moby->animationState.nextId;
        }
        moby->state = 3;
    }
    moby->damageFlags = 0;
    switch (moby->state) {
        case 0:
            if (DecodedDamageDialogueStart(moby, 0)) {
                if (!(DecodedDamageDialogueFlags & 2))
                    DecodedDamageDialogueFlags |= 2;
                DecodedDamageDialogueCall(moby, 0, 1);
                moby->state = 2;
            }
            break;
        case 2:
            if (D_8006E344 != 1) {
                func_80034F40(moby, 0);
                moby->state = 0;
            }
            break;
        case 3:
            if (tag->emitParticle) {
                velocity.x = (rand() & 0xF) - 8;
                velocity.y = (rand() & 0xF) - 8;
                velocity.z = (rand() & 0xF) + 8;
                particle = SpawnParticle(1, 0x37, &moby->position, &velocity);
                if (particle)
                    *(short*)(particle + 8) += rand() & 0xFF;
            }
            if (D_8006C770) {
                tag->emitParticle = 0;
                func_80034F40(moby, tag->savedAnimation);
                moby->state = tag->savedState;
            }
            break;
    }
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
void func_level_11_80080AE0(Moby* argument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80080CE0.
* AI generated; not human reviewed. All1043 instructions,51 selectors and
* one zero padding word,1095 owned words, require every native/linked word
* and actual transfer/table destination. Frame70 saves S0..S6/RA,SP20..4F.
* Two original lists process their current masked15-bit record index,
* then test that same entry's signed high bit and advance by2. Example
* [0x0002,0x800B] processes records2 and11,stops before a third read.
* Original429/445/447/448 and the second list preserve this ordering.
* Both checksum producers read unsigned bytes and fold8 times with8005.
* The second code-byte stride is (checksum&3)+1; its complete pointer,
* original end-symbol comparison and counter delay retain exact order.
* main_TEXT_START+2 is a byte address. Constructor results sign-extend
* their low16 bits before storage. Timer10800/7200,callback arguments,
* result stores and linked position/one producers preserve originals.
* Full39/shift6 and25/shift7 samples reuse already matched producer paths.
* Saved pointer/temporary phases are disjoint and fully initialized.
* Empty metadata consumes complete values/addresses or has dead outputs
* before full producers;zero CPU instructions. No partialHI,fixedFP,
* undefined saved inputs,live alias overlap or pipeline/flag changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence: binary identity only
* after every gate. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned data/padding and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 cb2ce04d98c6ce6a14ec26e10f27986b2964602aa876ceb765a6448d30aa9001 */
extern unsigned char Level11_80CE0Datamain_TEXT_STARTView1 __asm__("main_TEXT_START");
extern unsigned char Level11_80CE0Datamain_TEXT_ENDView1 __asm__("main_TEXT_END");
extern unsigned char Level11_80CE0Call751C0View1 __asm__("func_level_11_800751C0");
extern unsigned char Level11_80CE0Call29AA0View1 __asm__("func_80029AA0");
extern unsigned char Level11_80CE0Call27EE4View1 __asm__("func_80027EE4");
extern unsigned char Level11_80CE0Call27A60View1 __asm__("func_80027A60");
#define Level11_80CE0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level11_80CE0DataPlaySoundView1() __asm__("PlaySound");
int Level11_80CE0Call13D44View1() __asm__("func_80013D44");
int Level11_80CE0Call2803CView1() __asm__("func_8002803C");
int Level11_80CE0Call28154View1() __asm__("func_80028154");
void Level11_80CE0RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level11_80CE0CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level11_80CE0Call37BBCView1() __asm__("func_80037BBC");
int Level11_80CE0Call3B74CView1() __asm__("func_8003B74C");
int Level11_80CE0Call3B7B4View1() __asm__("func_8003B7B4");
int Level11_80CE0CopyVectorView1() __asm__("func_8004F178");
int Level11_80CE0AddVectorView1() __asm__("func_8004F194");
int Level11_80CE0ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level11_80CE0Call512E4View1() __asm__("func_800512E4");
int Level11_80CE0DeleteMobyView1() __asm__("func_80055B18");
extern int Level11_80CE0Data658A0View1 __asm__("D_800658A0");
extern int Level11_80CE0Data65920View1 __asm__("D_80065920");
extern int Level11_80CE0Data66BC8View1 __asm__("D_80066BC8");
extern int Level11_80CE0Data6C550View1 __asm__("D_8006C550");
extern int Level11_80CE0Data6C58CView1 __asm__("D_8006C58C");
extern int Level11_80CE0Data6C640View1 __asm__("D_8006C640");
extern int Level11_80CE0Data6C650View1 __asm__("D_8006C650");
extern int Level11_80CE0Data6C654View1 __asm__("D_8006C654");
extern int Level11_80CE0Data6C704View1 __asm__("D_8006C704");
extern unsigned short** Level11_80CE0Data6C730View1 __asm__("D_8006C730");
extern unsigned char Level11_80CE0Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level11_80CE0Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level11_80CE0Data6D088View1 __asm__("D_8006D088");
extern int Level11_80CE0Data6E160View1 __asm__("D_8006E160");
extern int Level11_80CE0Data6E344View1 __asm__("D_8006E344");
extern int Level11_80CE0Data70300View1 __asm__("D_80070300");
extern int Level11_80CE0Data70328View1 __asm__("D_80070328");
extern unsigned char Level11_80CE0Data7159AView1 __asm__("D_8007159A");
extern int Level11_80CE0Data716ACView1 __asm__("D_800716AC");
extern int Level11_80CE0Data718CCView1 __asm__("D_800718CC");
extern short Level11_80CE0Data719DCView1 __asm__("D_800719DC");
extern int Level11_80CE0Data91ED4View1 __asm__("D_level_11_80091ED4");
extern int (*Level11_80CE0DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Level11_80CE0Data74330View1)() __asm__("unk_ovlheader_80074330");
extern int (*Level11_80CE0Data74334View1)() __asm__("unk_ovlheader_80074334");
extern int Level11_80CE0Data74370View1 __asm__("unk_ovlheader_80074370");
extern int (*Level11_80CE0Data74440View1)() __asm__("unk_ovlheader_80074440");
extern int Level11_80CE0Data74448View1 __asm__("unk_ovlheader_80074448");
extern int Level11_80CE0Data7444CView1 __asm__("unk_ovlheader_8007444C");
extern int Level11_80CE0Data74450View1 __asm__("unk_ovlheader_80074450");
extern int (*Level11_80CE0Data7447CView1)() __asm__("unk_ovlheader_8007447C");
void func_level_11_80080CE0(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        retainedOneOrFrameAddress17 __asm__("$17");
    register void* ownerRecord20 __asm__("$20");
    register int privateRecord19 __asm__("$19"), retainedAddressOrRecord16 __asm__("$16"),
        linkedPrivateRecord21 __asm__("$21"), linkedRecord22 __asm__("$22");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
    } originalFrame;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord13;
    int temporaryWord19;
    int temporaryWord9;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord1;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord16;
    int temporaryWord18;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord8;
    int temporaryWord10;
    int temporaryWord17;
    ownerRecord20 = ownerParameter;
    MATCHING_KEEP(ownerRecord20);
    privateRecord19 = Level11_80CE0Field(ownerRecord20, void**, 0);
    rawWord3 = Level11_80CE0Field(privateRecord19, int*, 160);
    rawWord2 = rawWord3 * 88;
    rawWord3 = Level11_80CE0Data6C550View1;
    linkedRecord22 = rawWord3 + rawWord2;
    linkedPrivateRecord21 = Level11_80CE0Field(linkedRecord22, void**, 0);
    if (Level11_80CE0Data6C640View1 == 0) {
        if (Level11_80CE0Data7159AView1 != 0) {
            if ((Level11_80CE0Data6C7B4View1 & 8) ||
                (Level11_80CE0Field((int)&Level11_80CE0Data70300View1, unsigned char*,
                                    Level11_80CE0Data6C58CView1) &
                 8)) {
                Level11_80CE0Field(ownerRecord20, signed char*, 0x41) = 0;
                Level11_80CE0Field(ownerRecord20, unsigned char*, 0x4C) = 0U;
                Level11_80CE0Field(ownerRecord20, signed char*, 0x4D) = 0;
                Level11_80CE0Field(ownerRecord20, int*, 8) = 0;
                Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0x32U;
                goto block_11;
            }
            Level11_80CE0DeleteMobyView1(ownerRecord20);
            return;
        }
        rawWord3 = Level11_80CE0Data6C7B4View1;
        rawWord2 = rawWord3 & 4;
        if (rawWord2 || (Level11_80CE0Field((int)&Level11_80CE0Data70300View1, unsigned char*,
                                            Level11_80CE0Data6C58CView1) &
                         4)) {
            rawWord2 = rawWord3 & 8;
            if (rawWord2 || (Level11_80CE0Field((int)&Level11_80CE0Data70300View1, unsigned char*,
                                                Level11_80CE0Data6C58CView1) &
                             8))
                Level11_80CE0Field(privateRecord19, unsigned char*, 2) = 15;
        }
        goto block_12;
    }
block_11:
block_12:
    rawWord3 = Level11_80CE0Data6C7B4View1;
    rawWord2 = rawWord3 & 4;
    if (rawWord2)
        goto finishOriginalFlagChecks;
    rawWord2 = rawWord3 & 8;
    if (rawWord2)
        goto finishOriginalFlagChecks;
    MATCHING_OBSERVE_VOLATILE(rawWord3);
    rawWord2 = Level11_80CE0Data6C58CView1;
    rawWord2 = Level11_80CE0Field((int)&Level11_80CE0Data70300View1, unsigned char*, rawWord2);
    rawWord2 &= 8;
    if (rawWord2)
        goto finishOriginalFlagChecks;
    {
        if ((Level11_80CE0Data6C640View1 == 0) &&
            (Level11_80CE0Field(privateRecord19, unsigned char*, 2) != 0)) {
            Level11_80CE0Field(privateRecord19, unsigned char*, 2) = 1U;
            Level11_80CE0Field(privateRecord19, signed char*, 5) = 1;
        }
        if ((Level11_80CE0Field(privateRecord19, int*, 0x5C) < 0) &&
            (Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) > 0)) {
            Level11_80CE0Field(privateRecord19, int*, 0x5C) = (short)Level11_80CE0Call2803CView1(
                0x17, 0x6E, &Level11_80CE0Call27EE4View1, &Level11_80CE0Call27A60View1,
                &Level11_80CE0Call29AA0View1, Level11_80CE0Field(privateRecord19, void**, 0x58),
                0xF);
            Level11_80CE0Field(privateRecord19, signed char*, 5) = 0;
            Level11_80CE0Field(privateRecord19, unsigned char*, 2) = 4U;
        } else if (Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) ==
                   0xF) {
            Level11_80CE0Call28154View1(Level11_80CE0Field(privateRecord19, int*, 0x5C));
            Level11_80CE0Field(privateRecord19, int*, 0x5C) = -1;
            Level11_80CE0Call28154View1(Level11_80CE0Field(privateRecord19, int*, 0x64));
            Level11_80CE0Field(privateRecord19, int*, 0x64) = -1;
            Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) = 0;
            Level11_80CE0Field(privateRecord19, int*, 0x68) = 0x3C;
            Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 2U;
        }
    }
finishOriginalFlagChecks:
    retainedAddressOrRecord16 = privateRecord19 + 0x6C;
    if ((unsigned int)Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C) >=
        (unsigned int)&Level11_80CE0Call751C0View1) {
        argumentWord5 = 0;
        argumentWord6 = (int)&Level11_80CE0Data91ED4View1;
    checkFirstOriginalByteBound:
        temporaryWord9 = Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C);
        argumentWord4 = 0;
        if (temporaryWord9 < (unsigned int)argumentWord6) {
            Level11_80CE0Field(privateRecord19, int*, 0x60) =
                (int)(Level11_80CE0Field(privateRecord19, int*, 0x60) ^
                      (Level11_80CE0Field(temporaryWord9, unsigned char*, 0) << 8));
            do {
                rawWord3 = Level11_80CE0Field(privateRecord19, int*, 96);
                rawWord2 = rawWord3 & 0x8000;
                if (rawWord2)
                    rawWord2 = (rawWord3 << 1) ^ 0x8005;
                else
                    rawWord2 = rawWord3 << 1;
                Level11_80CE0Field(privateRecord19, int*, 0x60) = rawWord2;
                argumentWord4 += 1;
            } while (argumentWord4 < 8);
            argumentWord5 += 1;
            Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C) =
                (unsigned int)(Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C) + 1);
            if (argumentWord5 < 0x40) {
                goto checkFirstOriginalByteBound;
            }
        }
        retainedAddressOrRecord16 = privateRecord19 + 0x6C;
    }
    Level11_80CE0Call3B7B4View1(retainedAddressOrRecord16, 4, (int)&Level11_80CE0Data6D088View1);
    Level11_80CE0Call3B7B4View1(retainedAddressOrRecord16, 4, (int)&Level11_80CE0Data6C7F8View1);
    retainedAddressOrRecord16 = privateRecord19 + 0x60;
    Level11_80CE0Call3B7B4View1(retainedAddressOrRecord16, 4, (int)&Level11_80CE0Data6D088View1);
    Level11_80CE0Call3B7B4View1(retainedAddressOrRecord16, 4, (int)&Level11_80CE0Data6C7F8View1);
    temporaryWord12 = Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48);
    switch (temporaryWord12) {
        case 41:
            if (Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x50) == 0x13) {
                temporaryWord13 = Level11_80CE0Data6C58CView1 * 6;
                temporaryWord1 = Level11_80CE0Field((int)&Level11_80CE0Data716ACView1,
                                                    unsigned char*, 3 + temporaryWord13);
                if (temporaryWord1 < 0xFFU) {
                    Level11_80CE0Field((int)&Level11_80CE0Data716ACView1, unsigned char*,
                                       3 + temporaryWord13) = temporaryWord1 + 1;
                }
                {
                    int callbackWord8;
                    argumentWord4 = 18;
                    argumentWord5 = 3;
                    argumentWord6 = 0;
                    argumentWord7 = 0;
                    __asm__(""
                            : "=r"(argumentWord7)
                            : "0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5),
                              "r"(argumentWord6)
                            : "$2", "$3", "memory");
                    rawWord3 = 10800;
                    callbackWord8 = Level11_80CE0Data74370View1;
                    rawWord2 = privateRecord19 + 112;
                    Level11_80CE0Field(privateRecord19, int*, 112) = rawWord3;
                    Level11_80CE0Field(privateRecord19, int*, 100) =
                        (short)Level11_80CE0Call2803CView1(argumentWord4, argumentWord5,
                                                           argumentWord6, argumentWord7,
                                                           callbackWord8, rawWord2, rawWord3);
                }
                Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0x2AU;
                return;
            }
        default:
            return;
        case 42:
            if (Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) == 0xF) {
                Level11_80CE0Call28154View1(Level11_80CE0Field(privateRecord19, int*, 0x5C));
                Level11_80CE0Field(privateRecord19, int*, 0x5C) = -1;
                Level11_80CE0Call28154View1(Level11_80CE0Field(privateRecord19, int*, 0x64));
                Level11_80CE0Field(privateRecord19, int*, 0x64) = -1;
                Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) = 0;
                Level11_80CE0Field(privateRecord19, int*, 0x68) = 0x3C;
                Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 2U;
                return;
            }
            if (Level11_80CE0CountTimerDownView1(privateRecord19 + 0x70, 4) == 0) {
                if (Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x50) != 0x13) {
                    Level11_80CE0Field(privateRecord19, int*, 0x68) = 0x3C;
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0x2BU;
                    return;
                }
            } else {
                goto callSharedOriginalStatusHelper;
            }
            break;
        case 43:
            Level11_80CE0CountTimerDownView1(privateRecord19 + 0x70, 4);
            if (Level11_80CE0CountTimerDownView1(privateRecord19 + 0x68, 4) != 0) {
            callSharedOriginalStatusHelper:
                Level11_80CE0Field(privateRecord19, signed char*, 5) = 1;
                retainedAddressOrRecord16 = privateRecord19 + 5;
                Level11_80CE0Call3B7B4View1(retainedAddressOrRecord16, 1,
                                            (int)&Level11_80CE0Data6D088View1);
                Level11_80CE0Call3B7B4View1(retainedAddressOrRecord16, 1,
                                            (int)&Level11_80CE0Data6C7F8View1);
                Level11_80CE0Call3B74CView1((int)&Level11_80CE0Data6D088View1);
                return;
            }
            break;
        case 0:
            if ((Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x50) != 0x13) &&
                (Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x50) != 7)) {
                temporaryWord14 = Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C);
                if (temporaryWord14 < (unsigned int)&Level11_80CE0Datamain_TEXT_ENDView1) {
                    argumentWord5 = 0;
                    if (temporaryWord14 <= 0x7FFFU) {
                        Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C) =
                            (unsigned int)(Level11_80CE0Data6C58CView1 +
                                           (&Level11_80CE0Datamain_TEXT_STARTView1 + 2));
                    }
                    do {
                        argumentWord4 = 0;
                        Level11_80CE0Field(privateRecord19, int*, 0x60) =
                            (int)(Level11_80CE0Field(privateRecord19, int*, 0x60) ^
                                  (Level11_80CE0Field(
                                       Level11_80CE0Field(privateRecord19, unsigned int*, 108),
                                       unsigned char*, 0)
                                   << 8));
                    foldSecondOriginalByte:
                        rawWord3 = Level11_80CE0Field(privateRecord19, int*, 96);
                        rawWord2 = rawWord3 & 0x8000;
                        if (rawWord2)
                            rawWord2 = (rawWord3 << 1) ^ 0x8005;
                        else
                            rawWord2 = rawWord3 << 1;
                        Level11_80CE0Field(privateRecord19, int*, 0x60) = rawWord2;
                        argumentWord4 += 1;
                        if (argumentWord4 < 8) {
                            goto foldSecondOriginalByte;
                        }
                        MATCHING_BARRIER("memory");
                        rawWord2 = Level11_80CE0Field(privateRecord19, int*, 96);
                        rawWord3 = Level11_80CE0Field(privateRecord19, int*, 108);
                        rawWord2 = (rawWord2 & 3) + 1;
                        rawWord3 += rawWord2;
                        MATCHING_KEEP(rawWord3);
                        Level11_80CE0Field(privateRecord19, int*, 108) = rawWord3;
                        temporaryWord15 = rawWord3;
                        rawWord3 = (unsigned int)rawWord3 <
                                   (unsigned int)&Level11_80CE0Datamain_TEXT_ENDView1;
                        MATCHING_KEEP(rawWord3);
                        __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(rawWord3));
                        argumentWord5 += 1;
                        if (!rawWord3) {
                            Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C) =
                                (unsigned int)&Level11_80CE0Call751C0View1;
                            argumentWord5 = 64;
                            MATCHING_KEEP(argumentWord5);
                            argumentWord5 += 1;
                        }
                    } while (argumentWord5 < 0x40);
                }
                if (Level11_80CE0Call37BBCView1(ownerRecord20, 0) != 0) {
                    Level11_80CE0Call512E4View1(ownerRecord20, 0, 1);
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 1U;
                }
                rawWord2 = Level11_80CE0Data6C7B4View1;
                rawWord2 &= 8;
                if (rawWord2) {
                    rawWord2 = 50;
                    goto clearSharedOriginalStateByte;
                }
                rawWord2 = Level11_80CE0Data6C58CView1;
                rawWord2 =
                    Level11_80CE0Field((int)&Level11_80CE0Data70300View1, unsigned char*, rawWord2);
                rawWord2 &= 8;
                if (rawWord2) {
                    rawWord2 = 50;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "memory");
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 73) = 0;
                    goto writeSharedOriginalState;
                }
                rawWord2 = 50;
            }
            break;
        case 1:
            if (Level11_80CE0Data6E344View1 != 1) {
                temporaryWord16 = Level11_80CE0Field(privateRecord19, unsigned char*, 4);
                if (temporaryWord16 == 2) {
                    argumentWord4 = *Level11_80CE0Data6C730View1;
                    do {
                        temporaryWord17 =
                            ((Level11_80CE0Field(argumentWord4, unsigned short*, 0) & 0x7FFF) *
                             0x58) +
                            Level11_80CE0Data6C550View1;
                        if (Level11_80CE0Field(temporaryWord17, unsigned char*, 0x49) == 0xFF) {
                            Level11_80CE0Field(temporaryWord17, unsigned char*, 0x49) = 1U;
                        }
                        rawWord2 = Level11_80CE0Field(argumentWord4, short*, 0);
                        argumentWord4 += 2;
                    } while (rawWord2 >= 0);
                    Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) = 0;
                    Level11_80CE0Field(privateRecord19, int*, 0x5C) =
                        (short)Level11_80CE0Call2803CView1(
                            0x17, 0x6E, &Level11_80CE0Call27EE4View1, &Level11_80CE0Call27A60View1,
                            &Level11_80CE0Call29AA0View1,
                            Level11_80CE0Field(privateRecord19, void**, 0x58), 0xF);
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0x28U;
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 0U;
                } else if (temporaryWord16 == 0xB) {
                    argumentWord4 = *Level11_80CE0Data6C730View1;
                    do {
                        temporaryWord10 =
                            ((Level11_80CE0Field(argumentWord4, unsigned short*, 0) & 0x7FFF) *
                             0x58) +
                            Level11_80CE0Data6C550View1;
                        if (Level11_80CE0Field(temporaryWord10, unsigned char*, 0x49) == 0xFF) {
                            Level11_80CE0Field(temporaryWord10, unsigned char*, 0x49) = 1U;
                        }
                        rawWord2 = Level11_80CE0Field(argumentWord4, short*, 0);
                        argumentWord4 += 2;
                    } while (rawWord2 >= 0);
                    Level11_80CE0Field(Level11_80CE0Field(privateRecord19, int*, 88), int*, 0) = 0;
                    if ((Level11_80CE0Field(privateRecord19, unsigned int*, 0x6C) ==
                         (int)&Level11_80CE0Data91ED4View1) &&
                        (Level11_80CE0Field(privateRecord19, int*, 0x60) != 0)) {
                        argumentWord5 = Level11_80CE0Data6C550View1;
                        rawWord2 = Level11_80CE0Data6C704View1;
                        rawWord2 = (unsigned int)argumentWord5 < (unsigned int)rawWord2;
                        argumentWord6 = 6;
                        if (rawWord2) {
                            argumentWord4 = argumentWord5 + 72;
                            do {
                                rawWord3 = Level11_80CE0Field(privateRecord19, int*, 84);
                                rawWord2 = rawWord3 * 88;
                                rawWord3 = Level11_80CE0Data6C550View1;
                                rawWord2 += rawWord3;
                                rawWord3 = Level11_80CE0Field(argumentWord4, short*, -18);
                                rawWord2 = Level11_80CE0Field(rawWord2, short*, 54);
                                if (rawWord3 == rawWord2) {
                                    rawWord2 = Level11_80CE0Field(argumentWord4, unsigned char*, 5);
                                    if (!rawWord2)
                                        Level11_80CE0Field(argumentWord4, unsigned char*, 0) =
                                            argumentWord6;
                                }
                                rawWord2 = Level11_80CE0Data6C704View1;
                                argumentWord5 += 88;
                                argumentWord4 += 88;
                            } while ((unsigned int)argumentWord5 < (unsigned int)rawWord2);
                        }
                        MATCHING_OBSERVE_VOLATILE(argumentWord6);
                        Level11_80CE0Field(privateRecord19, int*, 0x60) = 0;
                    }
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0x28U;
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 0x29U;
                } else {
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0U;
                }
                rawWord2 = Level11_80CE0Data6C7B4View1;
                rawWord2 &= 8;
                if (!rawWord2) {
                    rawWord2 = 50;
                    MATCHING_OBSERVE_VOLATILE(rawWord2);
                    Level11_80CE0RequestMobyAnimationView1(ownerRecord20, 0);
                    return;
                }
                rawWord2 = 50;
            clearSharedOriginalStateByte:
                Level11_80CE0Field(ownerRecord20, unsigned char*, 73) = 0;
            writeSharedOriginalState:
                Level11_80CE0Field(ownerRecord20, unsigned char*, 72) = rawWord2;
                return;
            }
            break;
        case 2:
            if (Level11_80CE0CountTimerDownView1(privateRecord19 + 0x68, 4) != 0) {
                if (Level11_80CE0Field(privateRecord19, unsigned char*, 4) == 0xB) {
                    temporaryWord18 = Level11_80CE0Data6C7B4View1 | 8;
                } else {
                    temporaryWord18 = Level11_80CE0Data6C7B4View1 | 4;
                }
                Level11_80CE0Data6C7B4View1 = temporaryWord18;
                Level11_80CE0Field(Level11_80CE0Field(ownerRecord20, void**, 0), signed char*, 5) =
                    2;
                rawWord2 = Level11_80CE0Field(ownerRecord20, unsigned char*, 70);
                rawWord2 *= 2;
                rawWord3 = Level11_80CE0Field((int)&Level11_80CE0Data65920View1, short*, rawWord2);
                argumentWord4 = (int)&originalFrame.sp20;
                rawWord2 = (rawWord3 * 39) >> 6;
                originalFrame.sp20 = rawWord2;
                rawWord2 = Level11_80CE0Field(ownerRecord20, unsigned char*, 70);
                argumentWord5 = argumentWord4;
                rawWord2 *= 2;
                rawWord3 = Level11_80CE0Field((int)&Level11_80CE0Data658A0View1, short*, rawWord2);
                MATCHING_KEEP_CLOBBER(rawWord3, "memory");
                rawWord2 = Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 68);
                argumentWord6 = (int)ownerRecord20 + 12;
                originalFrame.sp28 = 0;
                MATCHING_BARRIER_VOLATILE("memory");
                originalFrame.sp28 = rawWord2;
                rawWord2 = (rawWord3 * 39) >> 6;
                originalFrame.sp24 = rawWord2;
                Level11_80CE0AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                Level11_80CE0Call13D44View1(
                    &originalFrame.sp20,
                    (Level11_80CE0Field(ownerRecord20, unsigned char*, 0x46) + 0x80) & 0xFF, 0, 0);
                if (Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x280) < 0) {
                    Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x280) = 0;
                }
                Level11_80CE0Field(ownerRecord20, unsigned char*, 0x48) = 0U;
                return;
            }
            break;
        case 40:
            temporaryWord2 = (Level11_80CE0Field(privateRecord19, int*, 0x54) * 0x58) +
                             Level11_80CE0Data6C550View1;
            if (Level11_80CE0Field(temporaryWord2, unsigned char*, 0x48) == 0) {
                if (Level11_80CE0ApproximatePlanarDistanceView1(
                        temporaryWord2 + 0xC, (int)&Level11_80CE0Data70328View1) < 0xC00) {
                    temporaryWord19 = Level11_80CE0Data74334View1(
                        Level11_80CE0Data6C550View1 +
                        (Level11_80CE0Field(privateRecord19, int*, 0x54) * 0x58) + 0xC);
                } else {
                    temporaryWord3 = Level11_80CE0Data6C550View1 +
                                     (Level11_80CE0Field(privateRecord19, int*, 0x54) * 0x58);
                    temporaryWord19 = Level11_80CE0Data74330View1(
                        temporaryWord3 + 0xC,
                        Level11_80CE0Field(temporaryWord3, unsigned char*, 0x46), 0);
                }
                if (temporaryWord19 != 0) {
                    goto createOriginalHandle;
                }
            } else {
            createOriginalHandle:
                Level11_80CE0Field(privateRecord19, int*, 0x5C) =
                    (short)Level11_80CE0Call2803CView1(
                        0x17, 0x6E, &Level11_80CE0Call27EE4View1, &Level11_80CE0Call27A60View1,
                        &Level11_80CE0Call29AA0View1,
                        Level11_80CE0Field(privateRecord19, void**, 0x58), 0xF);
                rawWord2 = Level11_80CE0Field(ownerRecord20, unsigned char*, 73);
                Level11_80CE0Field(ownerRecord20, unsigned char*, 73) = 0;
                Level11_80CE0Field(ownerRecord20, unsigned char*, 72) = rawWord2;
                return;
            }
            break;
        case 50:
            temporaryWord11 = Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49);
            switch (temporaryWord11) {
                case 0:
                    rawWord3 = (int)&Level11_80CE0Data718CCView1;
                    rawWord2 = Level11_80CE0Field(rawWord3, int*, 0);
                    if (rawWord2 < 3200) {
                        rawWord2 = 3200;
                        Level11_80CE0Field(rawWord3, int*, 0) = rawWord2;
                    }
                    Level11_80CE0Field(ownerRecord20, unsigned char*, 0x4A) = 0xFF;
                    if ((Level11_80CE0Field(ownerRecord20, unsigned char*, 0x4C) != 0) &&
                        (Level11_80CE0Call37BBCView1(ownerRecord20, 0) != 0)) {
                        Level11_80CE0Call512E4View1(ownerRecord20, 0, 1);
                        Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 1U;
                    }
                    if ((Level11_80CE0Data6E160View1 == 0) &&
                        (Level11_80CE0Field((int)&Level11_80CE0Data70328View1, int*, 0x50) ==
                         0x13)) {
                        {
                            int callbackWord8;
                            argumentWord4 = 50;
                            argumentWord5 = 3;
                            argumentWord6 = 0;
                            argumentWord7 = 0;
                            __asm__(""
                                    : "=r"(argumentWord7)
                                    : "0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5),
                                      "r"(argumentWord6)
                                    : "$2", "$3", "memory");
                            rawWord3 = 7200;
                            callbackWord8 = Level11_80CE0Data74370View1;
                            rawWord2 = privateRecord19 + 144;
                            Level11_80CE0Field(privateRecord19, int*, 144) = rawWord3;
                            rawWord2 = Level11_80CE0Call2803CView1(
                                argumentWord4, argumentWord5, argumentWord6, argumentWord7,
                                callbackWord8, rawWord2, rawWord3);
                        }
                        retainedAddressOrRecord16 = linkedPrivateRecord21 + 100;
                        argumentWord4 = retainedAddressOrRecord16;
                        rawWord2 = (short)rawWord2;
                        Level11_80CE0Field(privateRecord19, int*, 152) = rawWord2;
                        rawWord2 = (int)Level11_80CE0Data74440View1;
                        __asm__("" : "=r"(retainedOneOrFrameAddress17)::"memory");
                        retainedOneOrFrameAddress17 = 1;
                        Level11_80CE0Field(linkedPrivateRecord21, int*, 140) =
                            retainedOneOrFrameAddress17;
                        ((int (*)())rawWord2)(argumentWord4);
                        Level11_80CE0Field(privateRecord19, int*, 0x94) =
                            (short)Level11_80CE0Call2803CView1(
                                0x15, 0xDD, Level11_80CE0Data74448View1,
                                Level11_80CE0Data74450View1, Level11_80CE0Data7444CView1,
                                retainedAddressOrRecord16, 0xEA60);
                        Level11_80CE0Data6C650View1 = retainedOneOrFrameAddress17;
                        Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 2U;
                        return;
                    }
                    break;
                case 1:
                    if (Level11_80CE0Data6E344View1 != temporaryWord11) {
                        Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 0U;
                        return;
                    }
                    break;
                case 2:
                    if (Level11_80CE0CountTimerDownView1(privateRecord19 + 0x90, 4) != 0) {
                        temporaryWord4 = Level11_80CE0Field(privateRecord19, int*, 0x98);
                        if (temporaryWord4 != -1) {
                            Level11_80CE0Call28154View1(temporaryWord4);
                        }
                        temporaryWord5 = Level11_80CE0Field(privateRecord19, int*, 0x94);
                        Level11_80CE0Field(privateRecord19, int*, 0x98) = -1;
                        if (temporaryWord5 != -1) {
                            Level11_80CE0Call28154View1(temporaryWord5);
                        }
                        Level11_80CE0Field(privateRecord19, int*, 0x94) = -1;
                        if (!(Level11_80CE0Field((int)&Level11_80CE0Data66BC8View1, unsigned char*,
                                                 1) &
                              1)) {
                            retainedOneOrFrameAddress17 = (int)&originalFrame.sp30;
                            MATCHING_KEEP(retainedOneOrFrameAddress17);
                            if (Level11_80CE0Field(linkedPrivateRecord21, int*, 0xE4) >= 0xC80) {
                                Level11_80CE0Field((int)&Level11_80CE0Data66BC8View1,
                                                   unsigned char*, 1) = 3U;
                                Level11_80CE0Data719DCView1 = 1;
                                Level11_80CE0DataPlaySoundView1(
                                    Level11_80CE0Field(Level11_80CE0Data6C654View1, unsigned char*,
                                                       0x23),
                                    ownerRecord20, 0xA1);
                                temporaryWord8 =
                                    Level11_80CE0DataSpawnMobyView1(0xD3, ownerRecord20);
                                if (temporaryWord8 != 0) {
                                    Level11_80CE0CopyVectorView1(temporaryWord8 + 0xC,
                                                                 (int)&Level11_80CE0Data70328View1);
                                    rawWord2 = Level11_80CE0Field((int)&Level11_80CE0Data70328View1,
                                                                  unsigned char*, 14);
                                    rawWord2 *= 2;
                                    rawWord3 = Level11_80CE0Field((int)&Level11_80CE0Data65920View1,
                                                                  short*, rawWord2);
                                    rawWord2 = rawWord3 * 25;
                                    rawWord3 = Level11_80CE0Field(temporaryWord8, int*, 12);
                                    rawWord2 >>= 7;
                                    rawWord3 += rawWord2;
                                    Level11_80CE0Field(temporaryWord8, int*, 12) = rawWord3;
                                    rawWord2 = Level11_80CE0Field((int)&Level11_80CE0Data70328View1,
                                                                  unsigned char*, 14);
                                    rawWord3 = Level11_80CE0Field(temporaryWord8, int*, 20);
                                    rawWord2 *= 2;
                                    argumentWord4 = Level11_80CE0Field(
                                        (int)&Level11_80CE0Data658A0View1, short*, rawWord2);
                                    rawWord3 += 500;
                                    Level11_80CE0Field(temporaryWord8, int*, 20) = rawWord3;
                                    rawWord3 = Level11_80CE0Field(temporaryWord8, int*, 16);
                                    rawWord2 = (argumentWord4 * 25) >> 7;
                                    rawWord3 += rawWord2;
                                    Level11_80CE0Field(temporaryWord8, int*, 16) = rawWord3;
                                }
                                goto block_128;
                            }
                        } else {
                        block_128:
                            retainedOneOrFrameAddress17 = (int)&originalFrame.sp30;
                            MATCHING_KEEP(retainedOneOrFrameAddress17);
                        }
                        rawWord3 = Level11_80CE0Field(privateRecord19, int*, 156);
                        rawWord2 = rawWord3 * 88;
                        retainedAddressOrRecord16 = Level11_80CE0Data6C550View1;
                        retainedAddressOrRecord16 += rawWord2;
                        Level11_80CE0Field(retainedAddressOrRecord16, signed char*, 0x49) = 0;
                        Level11_80CE0CopyVectorView1(retainedOneOrFrameAddress17,
                                                     retainedAddressOrRecord16 + 0xC);
                        originalFrame.sp30 +=
                            (int)-(Level11_80CE0Field((int)&Level11_80CE0Data65920View1, short*,
                                                      (Level11_80CE0Field(retainedAddressOrRecord16,
                                                                          unsigned char*, 0x46) *
                                                       2)) *
                                   0x5DC) >>
                            0xC;
                        originalFrame.sp34 +=
                            (int)-(Level11_80CE0Field((int)&Level11_80CE0Data658A0View1, short*,
                                                      (Level11_80CE0Field(retainedAddressOrRecord16,
                                                                          unsigned char*, 0x46) *
                                                       2)) *
                                   0x5DC) >>
                            0xC;
                        Level11_80CE0Call13D44View1(
                            retainedOneOrFrameAddress17,
                            Level11_80CE0Field(retainedAddressOrRecord16, unsigned char*, 0x46), 0,
                            0);
                        Level11_80CE0Field(linkedRecord22, signed char*, 0x48) = 0;
                        Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 0U;
                        Level11_80CE0Data7447CView1(
                            Level11_80CE0Field(linkedPrivateRecord21, int*, 0xE4));
                        Level11_80CE0Data6C650View1 = 0;
                    }
                    if (Level11_80CE0Data6C650View1 == 2) {
                        temporaryWord6 = Level11_80CE0Field(privateRecord19, int*, 0x98);
                        Level11_80CE0Data6C650View1 = 0;
                        if (temporaryWord6 != -1) {
                            Level11_80CE0Call28154View1(temporaryWord6);
                        }
                        temporaryWord7 = Level11_80CE0Field(privateRecord19, int*, 0x94);
                        Level11_80CE0Field(privateRecord19, int*, 0x98) = -1;
                        if (temporaryWord7 != -1) {
                            Level11_80CE0Call28154View1(temporaryWord7);
                        }
                        Level11_80CE0Field(privateRecord19, int*, 0x94) = -1;
                        rawWord3 = Level11_80CE0Field(privateRecord19, int*, 156);
                        rawWord2 = rawWord3 * 88;
                        retainedAddressOrRecord16 = Level11_80CE0Data6C550View1;
                        retainedAddressOrRecord16 += rawWord2;
                        Level11_80CE0Field(retainedAddressOrRecord16, signed char*, 0x49) = 0;
                        Level11_80CE0CopyVectorView1(&originalFrame.sp40,
                                                     retainedAddressOrRecord16 + 0xC);
                        originalFrame.sp40 +=
                            (int)-(Level11_80CE0Field((int)&Level11_80CE0Data65920View1, short*,
                                                      (Level11_80CE0Field(retainedAddressOrRecord16,
                                                                          unsigned char*, 0x46) *
                                                       2)) *
                                   0x5DC) >>
                            0xC;
                        originalFrame.sp44 +=
                            (int)-(Level11_80CE0Field((int)&Level11_80CE0Data658A0View1, short*,
                                                      (Level11_80CE0Field(retainedAddressOrRecord16,
                                                                          unsigned char*, 0x46) *
                                                       2)) *
                                   0x5DC) >>
                            0xC;
                        Level11_80CE0Call13D44View1(
                            &originalFrame.sp40,
                            Level11_80CE0Field(retainedAddressOrRecord16, unsigned char*, 0x46), 0,
                            0);
                        Level11_80CE0Field(linkedRecord22, signed char*, 0x48) = 0;
                        Level11_80CE0Field(ownerRecord20, unsigned char*, 0x49) = 0U;
                    }
                    break;
            }
            break;
    }
}
#undef Level11_80CE0Field

typedef struct {
    unsigned char reserved00[0x44];
    unsigned char* firstAnimation;
} DecodedAnimationHeader;

extern int D_8006C770;
extern Savepoint D_8006C7F8;
void func_8003B7B4(void*, int, Savepoint*);
void func_level_11_80081D2C(Moby* moby) {
    switch (moby->state) {
        case 3: {
            register unsigned int count __asm__("$2");
            register int multipleFrames __asm__("$2");
            moby->state = 2;
            count = *((DecodedAnimationHeader*)D_8006EE2C[moby->mobyClass])->firstAnimation;
            moby->animationState.id = 2;
            moby->animationState.nextId = 2;
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = 1;
            multipleFrames = count >= 2;
            MATCHING_KEEP(multipleFrames);
            moby->animationProgress = -multipleFrames & 0x30;
            break;
        }
        case 0:
            if (moby->substate) {
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            break;
        case 1:
            if (D_8006C770) {
                moby->state = 3;
                func_8003B7B4(&moby->state, 1, &D_8006C7F8);
                moby->state = 2;
                func_80034F40(moby, 2);
            }
            break;
        case 2:
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0: func_level_11_80081E44, original 176-byte frame.
 * AI generated reconstruction; not human reviewed. Unknown retail meanings
 *remain numeric. Word suffixes identify original MIPS register phases.
 * Every empty template observes a complete initialized original value or an
 *exact original dominating selector/threshold; it emits no CPU instruction.
 * A named clobber retires only an old dead register phase before its next
 *original definition. No outgoing stack home or incoming saved value is read.
 * SP20/24/28/30/6C/70 are closest-point scalar outputs, including the original
 * zero-count index producer. Local vectors occupy SP38..40,48..50,58..60 and
 * 78..80; SP88/8C are scalar outputs. No count minimum or fallback is invented.
 * Raw decoder aliases were split at original540 after35A80 and original1817
 * after1A358; those height reads remain after the actual calls. Original byte,
 * signed/unsigned halfword and full word fields retain their own widths.
 * The three unsigned-count shifts preserve low32 before signed16 projection.
 * Descriptor masks retain LBU,SLTIU2,XOR1,negation andAND30. Trig products use
 * signed16 samples and the original factor5/shift1 or signed-high shift25.
 * Three dynamic signed DIV/MFHI sequences retain the original zero/overflow
 *traps. Every native word, actual transfer, table destination and numeric
 *projection is independently gated in actor2128_25308.provenance.json.
 * Units,cadence,full external helper/caller/asset/heap ownership,portable C
 * arithmetic domains,Rev1 mapping,retail captures and human review remain open.
 */
#define Level11_81E44Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level11_81E44Test2(v)           \
    ({                                  \
        retailWord2 = (v);              \
        Level11_81E44Keep(retailWord2); \
        retailWord2;                    \
    })
#define Level11_81E44Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level11_81E44_func_80013E38(void*, void*, int) __asm__("func_80013E38");
int Level11_81E44_func_8001A358(void*, int) __asm__("func_8001A358");
void Level11_81E44RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Level11_81E44_func_80035194(void*, void*) __asm__("func_80035194");
int Level11_81E44TurnMobyTowardPlayer(void*, int, int, int) __asm__("func_8003573C");
void Level11_81E44TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Level11_81E44CountTimerDown(void*, int) __asm__("func_800359A4");
int Level11_81E44_func_80035A80(void*, void*, int, int, int, int, int,
                                int) __asm__("func_80035A80");
int Level11_81E44ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
void Level11_81E44_func_80035DDC(void*, int, int, int, int) __asm__("func_80035DDC");
int Level11_81E44SubAngle8(int, int) __asm__("func_8003613C");
void Level11_81E44GetClosestPathNode(void*, void*, int*) __asm__("func_8003645C");
void Level11_81E44_func_800369B8(void*, int) __asm__("func_800369B8");
void Level11_81E44_func_80038BF8(void*, void*, int, int) __asm__("func_80038BF8");
void Level11_81E44_func_800391E8(int, int, void*, int, int, int, int) __asm__("func_800391E8");
void Level11_81E44_func_8003B7B4(void*, int, void*) __asm__("func_8003B7B4");
void Level11_81E44PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Level11_81E44PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Level11_81E44MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
void Level11_81E44CopyVector(void*, void*) __asm__("func_8004F178");
void Level11_81E44AddVector(void*, void*, void*) __asm__("func_8004F194");
int Level11_81E44AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level11_81E44ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
void Level11_81E44DeleteMoby(void*) __asm__("func_80055B18");
void Level11_81E44RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
extern short Level11_81E44_D_800658A0[] __asm__("D_800658A0");
extern short Level11_81E44_D_80065920[] __asm__("D_80065920");
extern int Level11_81E44_D_8006C640 __asm__("D_8006C640");
extern int Level11_81E44_D_8006C648 __asm__("D_8006C648");
extern int Level11_81E44_D_8006C770 __asm__("D_8006C770");
extern int Level11_81E44_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level11_81E44_D_8006D088 __asm__("D_8006D088");
extern int Level11_81E44_D_8006EE2C[] __asm__("D_8006EE2C");
extern unsigned char Level11_81E44_D_80070328[] __asm__("D_80070328");
extern int Level11_81E44_D_80071918 __asm__("D_80071918");
extern int Level11_81E44_D_8007191C __asm__("D_8007191C");
extern int Level11_81E44_D_80071920 __asm__("D_80071920");
extern int (*Level11_81E44_SpawnMoby)(int, void*) __asm__("SpawnMoby");
void func_level_11_80081E44(void* input) {
    register int retailWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    register int ownerRecord18 __asm__("$18"), privateRecord19 __asm__("$19"),
        retainedValueOrVector16 __asm__("$16"), headingCountOrVector17 __asm__("$17"),
        distance20 __asm__("$20"), constantOne21 __asm__("$21");
    struct {
        int sp20;
        int sp24;
        int sp28;
        int sp2C;
        int sp30;
        int sp34;
        int sp38;
        int sp3C;
        int sp40;
        int sp44;
        int sp48;
        int sp4C;
        int sp50;
        int sp54;
        int sp58;
        int sp5C;
        int sp60;
        int sp64;
        int sp68;
        int sp6C;
        int sp70;
        int sp74;
        int sp78;
        int sp7C;
        int sp80;
        int sp84;
        int sp88;
        int sp8C;
    } originalFrame;
    int originalTimerResult;
    int temporaryValue6;
    int temporaryValue43;
    int temporaryValue4;
    int temporaryValue5;
    int temporaryValue14;
    int temporaryValue15;
    int temporaryValue16;
    int temporaryValue22;
    int temporaryValue23;
    int temporaryValue24;
    int temporaryValue47;
    int temporaryValue48;
    int temporaryValue58;
    int temporaryValue60;
    int temporaryValue61;
    int temporaryValue62;
    int temporaryValue63;
    int temporaryValue18;
    int temporaryValue28;
    int temporaryValue30;
    int temporaryValue33;
    int temporaryValue44;
    int temporaryValue49;
    int temporaryValue53;
    int temporaryValue65;
    register int retailWord2 __asm__("$2");
    int temporaryValue1;
    int temporaryValue2;
    int temporaryValue3;
    int temporaryValue7;
    int temporaryValue8;
    int temporaryValue9;
    int temporaryValue11;
    int temporaryValue12;
    int temporaryValue19;
    int temporaryValue20;
    int temporaryValue26;
    int temporaryValue27;
    int temporaryValue31;
    int temporaryValue34;
    int temporaryValue35;
    int temporaryValue36;
    int temporaryValue37;
    int temporaryValue38;
    int temporaryValue41;
    int temporaryValue42;
    int temporaryValue45;
    int temporaryValue50;
    int temporaryValue52;
    int temporaryValue55;
    int temporaryValue56;
    int temporaryValue59;
    int temporaryValue64;
    ownerRecord18 = (int)input;
    Level11_81E44Keep(ownerRecord18);
    privateRecord19 = Level11_81E44Field(ownerRecord18, int*, 0);
    distance20 = Level11_81E44ApproximatePlanarDistance((void*)(ownerRecord18 + 0xC),
                                                        (void*)((int)&Level11_81E44_D_80070328));
    if (Level11_81E44Field(ownerRecord18, int*, 0x18) == 0) {
        goto originalBlock8;
    }
    temporaryValue33 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x48);
    if (temporaryValue33 >= 0x5AU) {
        goto originalBlock8;
    }
    if ((unsigned int)(temporaryValue33 - 5) < 2U) {
        goto originalBlock8;
    }
    temporaryValue43 = Level11_81E44Field(privateRecord19, int*, 0x24);
    Level11_81E44Field(temporaryValue43, int*, 0) += 1;
    temporaryValue1 = Level11_81E44Field(privateRecord19, int*, 0x40);
    if (temporaryValue1 == 0) {
        goto originalBlock6;
    }
    if (Level11_81E44Field(temporaryValue1, short*, 0x36) != 0x167) {
        goto originalBlock6;
    }
    Level11_81E44Field(temporaryValue1, int*, 0x14) =
        (int)(Level11_81E44Field(temporaryValue1, int*, 0x14) + 0x500);
    Level11_81E44PlayMobySoundEvent((void*)(Level11_81E44Field(privateRecord19, int*, 0x40)), 0, 0);
    Level11_81E44_func_800391E8(
        0xC, 0x167, (void*)(Level11_81E44Field(privateRecord19, int*, 0x40)), 1, 3, 0x40, 0x100);
    Level11_81E44DeleteMoby((void*)(Level11_81E44Field(privateRecord19, int*, 0x40)));
    Level11_81E44_func_80038BF8((void*)(ownerRecord18), (void*)(privateRecord19 + 0x28), 2, 7);
    temporaryValue65 = 0x5C;
    goto originalBlock7;
originalBlock6:
    Level11_81E44_func_80038BF8((void*)(ownerRecord18), (void*)(privateRecord19 + 0x28), 2, 7);
    temporaryValue65 = 0x5A;
originalBlock7:
    Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = temporaryValue65;
originalBlock8:
    MATCHING_BARRIER_VOLATILE("memory");
    temporaryValue53 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x48);
    Level11_81E44Field(ownerRecord18, int*, 0x18) = 0;
    if (temporaryValue53 >= 0x62U) {
        goto originalBlock303;
    }
    switch (temporaryValue53) {
        case 0x15:
            Level11_81E44GetClosestPathNode(
                (void*)(ownerRecord18 + 0xC),
                (void*)(Level11_81E44Field(privateRecord19, int*, 0x1C)),
                (int*)(&originalFrame.sp20));
            retainedValueOrVector16 = privateRecord19 + 0xE;
            argumentWord4 = retainedValueOrVector16;
            argumentWord5 = 2;
            Level11_81E44Keep(argumentWord4);
            Level11_81E44Keep(argumentWord5);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            retailWord2 = originalFrame.sp20;
            argumentWord6 = (int)&Level11_81E44_D_8006D088;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(retailWord3, short*, 2) = (short)retailWord2;
            Level11_81E44Field(privateRecord19, short*, 0xE) = (short)retailWord2;
            Level11_81E44_func_8003B7B4((void*)(argumentWord4), argumentWord5,
                                        (void*)(argumentWord6));
            Level11_81E44_func_8003B7B4((void*)(retainedValueOrVector16), 2,
                                        (void*)((int)&Level11_81E44_D_8006C7F8));
            retailWord2 = 0x5D;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            __asm__ volatile("" ::"i"(0x5D) : "memory");
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            goto originalBlock302;
        case 0x14:
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            retailWord3 = 1;
            retailWord2 = 0x40;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = retailWord3;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = retailWord2;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = retailWord3;
            retailWord2 = Level11_81E44ProbeGroundFromRaisedMoby((void*)(argumentWord4)) +
                          Level11_81E44Field(privateRecord19, int*, 0x44);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord2;
            Level11_81E44Field(privateRecord19, int*, 0x44) = retailWord2;
            retailWord2 = 0x5F;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            __asm__ volatile("" ::"i"(0x5F) : "memory");
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            goto originalBlock302;
        case 0xC:
            retailWord2 = Level11_81E44AbsoluteByteAngleDelta(
                Level11_81E44Field(ownerRecord18, unsigned char*, 0x46),
                Level11_81E44PlanarHeadingLookup(
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0) -
                        Level11_81E44Field(ownerRecord18, int*, 0xC),
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4) -
                        Level11_81E44Field(ownerRecord18, int*, 0x10),
                    0));
            Level11_81E44Field(ownerRecord18, int*, 0x18) =
                (int)(Level11_81E44Field(ownerRecord18, int*, 0x18) |
                      Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x40), int*,
                                         0x18));
            retailWord3 = Level11_81E44Field(
                (int)&Level11_81E44_D_800658A0 +
                    (Level11_81E44Field(privateRecord19, unsigned char*, 0x10) * 2),
                unsigned short*, 0);
            MATCHING_BARRIER_VOLATILE("memory");
            argumentWord4 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord3, "memory");
            argumentWord4 += ((int)((unsigned int)retailWord3 << 16) >> 25);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = argumentWord4;
            argumentWord4 = Level11_81E44_D_8006C648;
            retailWord3 = Level11_81E44Field(privateRecord19, unsigned short*, 0x10);
            __asm__ volatile("" ::"r"(retailWord2) : "$16", "memory");
            retainedValueOrVector16 = retailWord2;
            Level11_81E44Keep(retainedValueOrVector16);
            retailWord3 += argumentWord4;
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) =
                (unsigned short)retailWord3;
            temporaryValue60 = Level11_81E44Field(privateRecord19, int*, 0x44) - 0x200;
            if (Level11_81E44Field(ownerRecord18, int*, 0x14) >= temporaryValue60) {
                goto originalBlock14;
            }
            Level11_81E44Field(ownerRecord18, int*, 0x14) = temporaryValue60;
        originalBlock14:
            temporaryValue61 = Level11_81E44Field(privateRecord19, int*, 0x44) + 0x200;
            if (temporaryValue61 >= Level11_81E44Field(ownerRecord18, int*, 0x14)) {
                goto originalBlock16;
            }
            Level11_81E44Field(ownerRecord18, int*, 0x14) = temporaryValue61;
        originalBlock16:
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x40), int*, 0x14) =
                (int)(Level11_81E44Field(ownerRecord18, int*, 0x14) + 0x300);
            if (Level11_81E44CountTimerDown((void*)(privateRecord19 + 0x10), 2) == 0) {
                goto originalBlock20;
            }
            if (retainedValueOrVector16 < 0x61 ? (retailWord2 = distance20 < 0x1800, 1)
                                               : (retailWord2 = distance20 < 0x1800, 0)) {
                goto originalBlock21;
            }
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock20;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0xDU;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0xD);
            return;
        originalBlock20:
            retailWord2 = distance20 < 0x1800;
        originalBlock21:
            if (retailWord2 != 0) {
                goto originalBlock23;
            }
            retailWord2 = retainedValueOrVector16 < 0x30;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock303;
            }
        originalBlock23:
            Level11_81E44TurnMobyTowardHeading(
                (void*)(ownerRecord18),
                Level11_81E44PlanarHeadingLookup(
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0) -
                        Level11_81E44Field(ownerRecord18, int*, 0xC),
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4) -
                        Level11_81E44Field(ownerRecord18, int*, 0x10),
                    0),
                3, 0, 1, 0);
            return;
        case 0xD:
            Level11_81E44Field(ownerRecord18, int*, 0x18) =
                (int)(Level11_81E44Field(ownerRecord18, int*, 0x18) |
                      Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x40), int*,
                                         0x18));
            retailWord2 = Level11_81E44Field(
                (int)&Level11_81E44_D_800658A0 +
                    (Level11_81E44Field(privateRecord19, unsigned char*, 0x10) * 2),
                unsigned short*, 0);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord3 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            retailWord3 += ((int)((unsigned int)retailWord2 << 16) >> 25);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord3;
            retailWord3 = Level11_81E44_D_8006C648;
            retailWord2 = Level11_81E44Field(privateRecord19, unsigned short*, 0x10);
            Level11_81E44Keep(retailWord3);
            retailWord2 += retailWord3;
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) =
                (unsigned short)retailWord2;
            temporaryValue62 = Level11_81E44Field(privateRecord19, int*, 0x44) - 0x100;
            if (Level11_81E44Field(ownerRecord18, int*, 0x14) >= temporaryValue62) {
                goto originalBlock26;
            }
            Level11_81E44Field(ownerRecord18, int*, 0x14) = temporaryValue62;
        originalBlock26:
            temporaryValue63 = Level11_81E44Field(privateRecord19, int*, 0x44) + 0x100;
            if (temporaryValue63 >= Level11_81E44Field(ownerRecord18, int*, 0x14)) {
                goto originalBlock28;
            }
            Level11_81E44Field(ownerRecord18, int*, 0x14) = temporaryValue63;
        originalBlock28:
            Level11_81E44TurnMobyTowardHeading(
                (void*)(ownerRecord18),
                Level11_81E44PlanarHeadingLookup(
                    Level11_81E44Field(ownerRecord18, int*, 0xC) -
                        Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0),
                    Level11_81E44Field(ownerRecord18, int*, 0x10) -
                        Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4),
                    0),
                3, 0, 1, 0);
            argumentWord4 = Level11_81E44Field(privateRecord19, int*, 0x40);
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            retailWord3 = Level11_81E44_D_8006C770;
            retailWord2 += 0x300;
            Level11_81E44Keep(argumentWord4);
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(argumentWord4, int*, 0x14) = retailWord2;
            if (retailWord3 == 0) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0xCU;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0xC);
            return;
        case 0x0:
            retailWord2 = Level11_81E44_D_8006C640;
            if (retailWord2 != 0 ? (retailWord2 = 0x5D, 1) : (retailWord2 = 0x5D, 0)) {
                goto originalBlock32;
            }
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            goto originalBlock302;
        originalBlock32:
            Level11_81E44Keep(retailWord2);
            if (Level11_81E44Field(ownerRecord18, int*, 0x14) >= 0x2800) {
                goto originalBlock36;
            }
            temporaryValue64 = Level11_81E44Field(privateRecord19, int*, 0x40);
            if (temporaryValue64 == 0) {
                goto originalBlock35;
            }
            Level11_81E44Field(temporaryValue64, signed char*, 0x49) = 1;
        originalBlock35:
            Level11_81E44Field(privateRecord19, int*, 0x40) = 0;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = 0U;
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(privateRecord19));
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            retailWord2 = 0xE;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            __asm__ volatile("" ::"i"(0xE) : "memory");
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            goto originalBlock302;
        originalBlock36:
            Level11_81E44TurnMobyTowardPlayer((void*)(ownerRecord18), 4, 0, 1);
            retailWord3 = Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50);
            if ((unsigned int)(retailWord3 - 7) < 2U ? (retailWord2 = distance20 < 0x2C01, 1)
                                                     : (retailWord2 = distance20 < 0x2C01, 0)) {
                goto originalBlock40;
            }
            if (retailWord3 == 0x13 ? (retailWord2 = distance20 < 0x2C00, 1)
                                    : (retailWord2 = distance20 < 0x2C00, 0)) {
                goto originalBlock39;
            }
            if (retailWord2 != 0) {
                goto originalBlock233;
            }
        originalBlock39:
            retailWord2 = distance20 < 0x2C01;
        originalBlock40:
            if (retailWord2 != 0 ? (retailWord2 = distance20 < 0x2000, 1)
                                 : (retailWord2 = distance20 < 0x2000, 0)) {
                goto originalBlock42;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 1;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 1);
            return;
        originalBlock42:
            if (retailWord2 == 0) {
                goto originalBlock303;
            }
            temporaryValue7 = Level11_81E44Field(privateRecord19, int*, 0x18);
            if (temporaryValue7 == 0) {
                goto originalBlock48;
            }
            retailWord3 = Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            Level11_81E44Keep(retailWord3);
            retailWord2 = retailWord2 < retailWord3;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock303;
            }
            Level11_81E44GetClosestPathNode((void*)(ownerRecord18 + 0xC), (void*)(temporaryValue7),
                                            (int*)(&originalFrame.sp24));
            if (originalFrame.sp24 >=
                (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0) -
                 1)) {
                goto originalBlock47;
            }
            originalFrame.sp24 += 1;
        originalBlock47:
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), unsigned short*,
                               2) = (unsigned short)originalFrame.sp24;
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0xA) = 1;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0xF) : "memory");
            retailWord2 = 0xF;
            goto originalBlock302;
        originalBlock48:
            temporaryValue8 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            argumentWord4 = ownerRecord18;
            if (temporaryValue8 == 0) {
                goto originalBlock58;
            }
            if (Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8) >=
                (Level11_81E44Field(ownerRecord18, int*, 0x14) + 0x800)) {
                goto originalBlock303;
            }
            retainedValueOrVector16 =
                (int)((unsigned int)Level11_81E44Field(temporaryValue8, unsigned short*, 0) << 16);
            Level11_81E44GetClosestPathNode((void*)(((int)&Level11_81E44_D_80070328 + 8) - 8),
                                            (void*)(temporaryValue8), (int*)(&originalFrame.sp28));
            retailWord2 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            headingCountOrVector17 = retainedValueOrVector16 >> 16;
            retailWord3 = Level11_81E44Field(retailWord2, short*, 2);
            retailWord2 = originalFrame.sp28;
            retainedValueOrVector16 = retainedValueOrVector16 >> 17;
            retailWord3 = retailWord2 - retailWord3;
            retainedValueOrVector16 = retainedValueOrVector16 < retailWord3;
            Level11_81E44Keep(retainedValueOrVector16);
            originalFrame.sp28 = retailWord3;
            if (retainedValueOrVector16 == 0) {
                goto originalBlock52;
            }
            retailWord2 = retailWord3 - headingCountOrVector17;
            goto originalBlock53;
        originalBlock52:
            retailWord2 = -headingCountOrVector17;
            Level11_81E44Keep(retailWord2);
            retailWord2 = retailWord2 >> 1;
            Level11_81E44Keep(retailWord2);
            retailWord2 = retailWord3 < retailWord2;
            if (retailWord2 == 0 ? (retailWord2 = retailWord3 + headingCountOrVector17, 1)
                                 : (retailWord2 = retailWord3 + headingCountOrVector17, 0)) {
                goto originalBlock54;
            }
        originalBlock53:
            Level11_81E44Keep(retailWord2);
            originalFrame.sp28 = retailWord2;
        originalBlock54:
            if (originalFrame.sp28 <= 0) {
                goto originalBlock56;
            }
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::"i"(-1) : "memory");
            retailWord2 = -1;
            goto originalBlock57;
        originalBlock56:
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::"i"(1) : "memory");
            retailWord2 = 1;
        originalBlock57:
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(retailWord3, short*, 0xA) = (short)retailWord2;
            temporaryValue34 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            temporaryValue14 =
                (int)(Level11_81E44Field(temporaryValue34, short*, 2) + headingCountOrVector17 +
                      Level11_81E44Field(temporaryValue34, short*, 0xA)) %
                headingCountOrVector17;
            Level11_81E44Field(temporaryValue34, short*, 2) = (short)temporaryValue14;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0x10) : "memory");
            retailWord2 = 0x10;
            goto originalBlock302;
        originalBlock58:
            argumentWord5 = 4;
            retailWord2 = 4;
            Level11_81E44Field(argumentWord4, unsigned char*, 0x49) = 0U;
            goto originalBlock280;
        case 0x10:
            retainedValueOrVector16 = Level11_81E44_func_80035A80(
                (void*)(ownerRecord18), (void*)(Level11_81E44Field(privateRecord19, int*, 0x1C)),
                0x100, 0x96, 0xFA, 6, 0x30, 0x26);
            if (Level11_81E44Field(ownerRecord18, int*, 0x14) >= 0x2800) {
                goto originalBlock63;
            }
            temporaryValue35 = Level11_81E44Field(privateRecord19, int*, 0x40);
            if (temporaryValue35 == 0) {
                goto originalBlock62;
            }
            Level11_81E44Field(temporaryValue35, signed char*, 0x49) = 1;
        originalBlock62:
            Level11_81E44Field(privateRecord19, int*, 0x40) = 0;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = 0U;
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(privateRecord19));
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            retailWord2 = 0xE;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            __asm__ volatile("" ::"i"(0xE) : "memory");
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            goto originalBlock302;
        originalBlock63:
            retailWord3 = Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50);
            if ((unsigned int)(retailWord3 - 7) < 2U
                    ? (retailWord2 = retainedValueOrVector16 & 1, 1)
                    : (retailWord2 = retainedValueOrVector16 & 1, 0)) {
                goto originalBlock69;
            }
            if (retailWord3 == 0x13 ? (retailWord2 = distance20 < 0x2C00, 1)
                                    : (retailWord2 = distance20 < 0x2C00, 0)) {
                goto originalBlock68;
            }
            if (retailWord2 == 0) {
                goto originalBlock68;
            }
            temporaryValue26 = Level11_81E44_SpawnMoby(0x164, (void*)(ownerRecord18));
            Level11_81E44Field(privateRecord19, int*, 0x40) = temporaryValue26;
            if (temporaryValue26 == 0) {
                goto originalBlock68;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 5U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 5);
        originalBlock68:
            retailWord2 = retainedValueOrVector16 & 1;
        originalBlock69:
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock303;
            }
            if (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x1C), short*, 2) !=
                Level11_81E44Field(privateRecord19, short*, 0xE)) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0U;
            return;
        case 0xF:
            retailWord2 = Level11_81E44_func_80035A80(
                (void*)(ownerRecord18), (void*)(Level11_81E44Field(privateRecord19, int*, 0x18)),
                0x100, 0x96, 0xFA, 6, 0x30, 0x22);
            argumentWord4 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            __asm__ volatile("" ::"r"(retailWord2) : "$3", "memory");
            retailWord3 = retailWord2;
            Level11_81E44Keep(retailWord3);
            if (argumentWord4 >= 0x2800) {
                goto originalBlock76;
            }
            temporaryValue36 = Level11_81E44Field(privateRecord19, int*, 0x40);
            if (temporaryValue36 == 0) {
                goto originalBlock75;
            }
            Level11_81E44Field(temporaryValue36, signed char*, 0x49) = 1;
        originalBlock75:
            Level11_81E44Field(privateRecord19, int*, 0x40) = 0;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = 0U;
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(privateRecord19));
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            retailWord2 = 0xE;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            __asm__ volatile("" ::"i"(0xE) : "memory");
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            goto originalBlock302;
        originalBlock76:
            if (Level11_81E44Test2(retailWord3 & 2)) {
                goto originalBlock79;
            }
            if (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0xA) !=
                1) {
                goto originalBlock81;
            }
            if ((Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8) + 0x800) >=
                argumentWord4) {
                goto originalBlock81;
            }
        originalBlock79:
            temporaryValue2 = Level11_81E44Field(privateRecord19, int*, 0x18);
            if (Level11_81E44Field(temporaryValue2, short*, 0xA) == -1) {
                goto originalBlock284;
            }
            Level11_81E44Field(temporaryValue2, short*, 0xA) = -1;
            temporaryValue37 = Level11_81E44Field(privateRecord19, int*, 0x18);
            Level11_81E44Field(temporaryValue37, unsigned short*, 2) =
                (unsigned short)((unsigned short)Level11_81E44Field(temporaryValue37, short*, 0) -
                                 2);
            return;
        originalBlock81:
            temporaryValue3 = Level11_81E44Field(privateRecord19, int*, 0x18);
            if (Level11_81E44Field(temporaryValue3, short*, 0xA) != -1) {
                goto originalBlock85;
            }
            if (!Level11_81E44Test2(distance20 < 0x2000)) {
                goto originalBlock85;
            }
            retailWord3 = Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            Level11_81E44Keep(retailWord3);
            retailWord2 = retailWord2 < retailWord3;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock85;
            }
            Level11_81E44Field(temporaryValue3, short*, 0xA) = 1;
            temporaryValue38 = Level11_81E44Field(privateRecord19, int*, 0x18);
            Level11_81E44Field(temporaryValue38, unsigned short*, 2) =
                (unsigned short)(Level11_81E44Field(temporaryValue38, unsigned short*, 2) + 1);
            return;
        originalBlock85:
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x18);
            argumentWord4 = Level11_81E44Field(ownerRecord18, short*, 0x38);
            retailWord2 = Level11_81E44Field(retailWord3, short*, 2);
            retailWord3 = Level11_81E44Field(retailWord3, int*, 0xC);
            retailWord2 = retailWord2 * 16;
            retailWord2 += retailWord3;
            retailWord3 = Level11_81E44Field(retailWord2, int*, 8);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            Level11_81E44Keep(retailWord3);
            retailWord3 += argumentWord4;
            retailWord2 -= retailWord3;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 >= 0) {
                goto originalBlock87;
            }
            retailWord2 = -retailWord2;
        originalBlock87:
            if (retailWord2 < 0x101) {
                goto originalBlock89;
            }
            argumentWord4 = ownerRecord18;
            argumentWord5 = 8;
            Level11_81E44Field(privateRecord19, short*, 0xC) = 0xAF;
            retailWord2 = 8;
            goto originalBlock280;
        originalBlock89:
            if ((unsigned int)(Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) - 7) <
                2U) {
                goto originalBlock303;
            }
            if (Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) == 0x13) {
                goto originalBlock303;
            }
            if (!Level11_81E44Test2(distance20 < 0x2C00)) {
                goto originalBlock303;
            }
            goto originalBlock233;
        case 0x1:
            Level11_81E44TurnMobyTowardPlayer((void*)(ownerRecord18), 4, 0, 1);
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 2U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 2);
            return;
        case 0x2:
            Level11_81E44TurnMobyTowardPlayer((void*)(ownerRecord18), 4, 0, 1);
            if (!Level11_81E44Test2(distance20 < 0x2800)) {
                goto originalBlock303;
            }
            if (Level11_81E44AbsoluteByteAngleDelta(
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, unsigned char*, 0xE),
                    Level11_81E44PlanarHeadingLookup(
                        Level11_81E44Field(ownerRecord18, int*, 0xC) -
                            Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0),
                        Level11_81E44Field(ownerRecord18, int*, 0x10) -
                            Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4),
                        0)) >= 0x18) {
                goto originalBlock113;
            }
            if (Level11_81E44Field(privateRecord19, int*, 0x18) == 0) {
                goto originalBlock102;
            }
            retailWord3 = Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            Level11_81E44Keep(retailWord3);
            retailWord2 = retailWord2 < retailWord3;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x46) =
                (unsigned char)(Level11_81E44Field(ownerRecord18, unsigned char*, 0x46) + 0x80);
            Level11_81E44GetClosestPathNode(
                (void*)(ownerRecord18 + 0xC),
                (void*)(Level11_81E44Field(privateRecord19, int*, 0x18)),
                (int*)(&originalFrame.sp2C));
            if (originalFrame.sp2C >=
                (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0) -
                 1)) {
                goto originalBlock101;
            }
            originalFrame.sp2C += 1;
        originalBlock101:
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), unsigned short*,
                               2) = (unsigned short)originalFrame.sp2C;
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0xA) = 1;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0xF) : "memory");
            retailWord2 = 0xF;
            goto originalBlock302;
        originalBlock102:
            retainedValueOrVector16 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            if (retainedValueOrVector16 == 0) {
                goto originalBlock112;
            }
            if (Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8) >=
                (Level11_81E44Field(ownerRecord18, int*, 0x14) + 0x800)) {
                goto originalBlock303;
            }
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            retainedValueOrVector16 =
                Level11_81E44Field(retainedValueOrVector16, unsigned short*, 0);
            retailWord2 += 0x80;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x46) = retailWord2;
            retainedValueOrVector16 = (int)((unsigned int)retainedValueOrVector16 << 16);
            Level11_81E44GetClosestPathNode(
                (void*)((int)&Level11_81E44_D_80070328),
                (void*)(Level11_81E44Field(privateRecord19, int*, 0x1C)),
                (int*)(&originalFrame.sp30));
            retailWord2 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            headingCountOrVector17 = retainedValueOrVector16 >> 16;
            retailWord3 = Level11_81E44Field(retailWord2, short*, 2);
            retailWord2 = originalFrame.sp30;
            retainedValueOrVector16 = retainedValueOrVector16 >> 17;
            retailWord3 = retailWord2 - retailWord3;
            retainedValueOrVector16 = retainedValueOrVector16 < retailWord3;
            Level11_81E44Keep(retainedValueOrVector16);
            originalFrame.sp30 = retailWord3;
            if (retainedValueOrVector16 == 0) {
                goto originalBlock106;
            }
            retailWord2 = retailWord3 - headingCountOrVector17;
            goto originalBlock107;
        originalBlock106:
            retailWord2 = -headingCountOrVector17;
            Level11_81E44Keep(retailWord2);
            retailWord2 = retailWord2 >> 1;
            Level11_81E44Keep(retailWord2);
            retailWord2 = retailWord3 < retailWord2;
            if (retailWord2 == 0 ? (retailWord2 = retailWord3 + headingCountOrVector17, 1)
                                 : (retailWord2 = retailWord3 + headingCountOrVector17, 0)) {
                goto originalBlock108;
            }
        originalBlock107:
            Level11_81E44Keep(retailWord2);
            originalFrame.sp30 = retailWord2;
        originalBlock108:
            if (originalFrame.sp30 <= 0) {
                goto originalBlock110;
            }
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::"i"(-1) : "memory");
            retailWord2 = -1;
            goto originalBlock111;
        originalBlock110:
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::"i"(1) : "memory");
            retailWord2 = 1;
        originalBlock111:
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(retailWord3, short*, 0xA) = (short)retailWord2;
            temporaryValue41 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            temporaryValue15 =
                (int)(Level11_81E44Field(temporaryValue41, short*, 2) + headingCountOrVector17 +
                      Level11_81E44Field(temporaryValue41, short*, 0xA)) %
                headingCountOrVector17;
            Level11_81E44Field(temporaryValue41, short*, 2) = (short)temporaryValue15;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0x10) : "memory");
            retailWord2 = 0x10;
            goto originalBlock302;
        originalBlock112:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = 0U;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 4U;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x46) =
                (unsigned char)(Level11_81E44Field(ownerRecord18, unsigned char*, 0x46) + 0x80);
            retailWord2 = Level11_81E44Field(
                Level11_81E44Field(
                    Level11_81E44Field((int)&Level11_81E44_D_8006EE2C +
                                           (Level11_81E44Field(ownerRecord18, short*, 0x36) * 4),
                                       int*, 0),
                    int*, 0x4C),
                unsigned char*, 0);
            Level11_81E44Field(ownerRecord18, signed char*, 0x3C) = 4;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3D) = 4;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3E) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3F) = 1;
            goto originalBlock294;
        originalBlock113:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 3U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 3);
            return;
        case 0x4:
            if (Level11_81E44Field(ownerRecord18, int*, 0x14) >= 0x2800) {
                goto originalBlock118;
            }
            temporaryValue42 = Level11_81E44Field(privateRecord19, int*, 0x40);
            if (temporaryValue42 == 0) {
                goto originalBlock117;
            }
            Level11_81E44Field(temporaryValue42, signed char*, 0x49) = 1;
        originalBlock117:
            Level11_81E44Field(privateRecord19, int*, 0x40) = 0;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = 0U;
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(privateRecord19));
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            retailWord2 = 0xE;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            __asm__ volatile("" ::"i"(0xE) : "memory");
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            goto originalBlock302;
        originalBlock118:
            if ((unsigned int)(Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) - 7) <
                2U) {
                goto originalBlock122;
            }
            if (Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) == 0x13) {
                goto originalBlock122;
            }
            if (Level11_81E44Test2(distance20 < 0x2C00) ? (argumentWord4 = 0x164, 1)
                                                        : (argumentWord4 = 0x164, 0)) {
                goto originalBlock233;
            }
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "memory");
        originalBlock122:
            argumentWord4 = privateRecord19 + 0x10;
            originalTimerResult = Level11_81E44CountTimerDown((void*)(argumentWord4), 2);
            constantOne21 = 1;
            if (originalTimerResult != 0) {
                goto originalBlock124;
            }
            Level11_81E44Keep(constantOne21);
            Level11_81E44TurnMobyTowardHeading(
                (void*)(ownerRecord18), Level11_81E44Field(privateRecord19, unsigned char*, 0x12),
                6, 0, 1, 0);
            headingCountOrVector17 = Level11_81E44Field(privateRecord19, unsigned char*, 0x12);
            goto originalBlock155;
        originalBlock124:
            Level11_81E44Keep(constantOne21);
            temporaryValue44 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x49);
            if (temporaryValue44 != constantOne21) {
                goto originalBlock132;
            }
            if (distance20 >= 0x1E00) {
                goto originalBlock129;
            }
            if (Level11_81E44Field(privateRecord19, int*, 0x14) == 0) {
                goto originalBlock128;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = 0U;
            retailWord2 = Level11_81E44PlanarHeadingLookup(
                Level11_81E44Field(ownerRecord18, int*, 0xC) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0),
                Level11_81E44Field(ownerRecord18, int*, 0x10) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4),
                0);
            __asm__ volatile("" ::"i"(1) : "memory");
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            argumentWord5 = retailWord2;
            goto originalBlock150;
        originalBlock128:
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0);
            __asm__ volatile("" ::"i"(0xB) : "memory");
            retailWord2 = 0xB;
            goto originalBlock302;
        originalBlock129:
            Level11_81E44TurnMobyTowardHeading(
                (void*)(ownerRecord18),
                Level11_81E44PlanarHeadingLookup(Level11_81E44Field(privateRecord19, int*, 0) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0xC),
                                                 Level11_81E44Field(privateRecord19, int*, 4) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0x10),
                                                 0),
                6, 0, constantOne21, 0);
            if (Level11_81E44ApproximatePlanarDistance((void*)(ownerRecord18 + 0xC),
                                                       (void*)(privateRecord19)) < 0x100) {
                goto originalBlock284;
            }
            headingCountOrVector17 =
                Level11_81E44PlanarHeadingLookup(Level11_81E44Field(privateRecord19, int*, 0) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0xC),
                                                 Level11_81E44Field(privateRecord19, int*, 4) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0x10),
                                                 0);
            if (Level11_81E44AbsoluteByteAngleDelta(
                    headingCountOrVector17,
                    Level11_81E44Field(ownerRecord18, unsigned char*, 0x46)) >= 0x19) {
                goto originalBlock303;
            }
            goto originalBlock155;
        originalBlock132:
            if (temporaryValue44 != 0) {
                goto originalBlock139;
            }
            headingCountOrVector17 = (int)&originalFrame.sp58;
            Level11_81E44CopyVector((void*)(headingCountOrVector17), (void*)(ownerRecord18 + 0xC));
            originalFrame.sp60 += 0x280;
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            __asm__ volatile("" ::: "$16", "memory");
            retainedValueOrVector16 = (int)&originalFrame.sp38;
            retailWord2 *= 2;
            retailWord3 =
                Level11_81E44Field((int)&Level11_81E44_D_80065920 + retailWord2, short*, 0);
            __asm__ volatile("" ::: "$4", "memory");
            argumentWord4 = retainedValueOrVector16;
            Level11_81E44Keep(retailWord3);
            retailWord2 = (retailWord3 * 5) >> 1;
            originalFrame.sp38 = retailWord2;
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = headingCountOrVector17;
            retailWord2 *= 2;
            retailWord3 =
                Level11_81E44Field((int)&Level11_81E44_D_800658A0 + retailWord2, short*, 0);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedValueOrVector16;
            originalFrame.sp40 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord3, "memory");
            retailWord2 = (retailWord3 * 5) >> 1;
            originalFrame.sp3C = retailWord2;
            Level11_81E44AddVector((void*)(argumentWord4), (void*)(argumentWord5),
                                   (void*)(argumentWord6));
            if (Level11_81E44_func_80013E38((void*)(&originalFrame.sp58),
                                            (void*)(&originalFrame.sp38), 0) != 0) {
                goto originalBlock138;
            }
            retainedValueOrVector16 = (int)&Level11_81E44_D_80071918;
            Level11_81E44Keep(retainedValueOrVector16);
            if (Level11_81E44PlanarHeadingLookup(
                    Level11_81E44MeasureVectorLength((void*)(retainedValueOrVector16), 0),
                    Level11_81E44_D_80071920, 0) >= 0x10) {
                goto originalBlock138;
            }
            retailWord2 =
                Level11_81E44SubAngle8(Level11_81E44PlanarHeadingLookup(
                                           Level11_81E44Field(retainedValueOrVector16, int*, 0),
                                           Level11_81E44_D_8007191C, 0),
                                       Level11_81E44Field(ownerRecord18, unsigned char*, 0x46));
            if (retailWord2 >= 0 ? (retailWord2 = 4, 1) : (retailWord2 = 4, 0)) {
                goto originalBlock137;
            }
            retailWord2 = 3;
        originalBlock137:
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = retailWord2;
        originalBlock138:
            retailWord2 = Level11_81E44PlanarHeadingLookup(
                Level11_81E44Field(ownerRecord18, int*, 0xC) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0),
                Level11_81E44Field(ownerRecord18, int*, 0x10) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4),
                0);
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            argumentWord5 = retailWord2;
        originalBlock151:
            Level11_81E44TurnMobyTowardHeading((void*)(argumentWord4), argumentWord5, 4, 0, 1, 0);
            headingCountOrVector17 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            goto originalBlock155;
        originalBlock139:
            if (temporaryValue44 != 3) {
                goto originalBlock144;
            }
            headingCountOrVector17 = (int)&originalFrame.sp58;
            Level11_81E44CopyVector((void*)(headingCountOrVector17), (void*)(ownerRecord18 + 0xC));
            originalFrame.sp60 += 0x280;
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            __asm__ volatile("" ::: "$16", "memory");
            retainedValueOrVector16 = (int)&originalFrame.sp38;
            retailWord2 *= 2;
            retailWord3 =
                Level11_81E44Field((int)&Level11_81E44_D_80065920 + retailWord2, short*, 0);
            __asm__ volatile("" ::: "$4", "memory");
            argumentWord4 = retainedValueOrVector16;
            Level11_81E44Keep(retailWord3);
            retailWord2 = (retailWord3 * 5) >> 1;
            originalFrame.sp38 = retailWord2;
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = headingCountOrVector17;
            retailWord2 *= 2;
            retailWord3 =
                Level11_81E44Field((int)&Level11_81E44_D_800658A0 + retailWord2, short*, 0);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedValueOrVector16;
            originalFrame.sp40 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord3, "memory");
            retailWord2 = (retailWord3 * 5) >> 1;
            originalFrame.sp3C = retailWord2;
            Level11_81E44AddVector((void*)(argumentWord4), (void*)(argumentWord5),
                                   (void*)(argumentWord6));
            if (Level11_81E44_func_80013E38((void*)(&originalFrame.sp58),
                                            (void*)(&originalFrame.sp38), 0) != 0) {
                goto originalBlock142;
            }
            retainedValueOrVector16 = (int)&Level11_81E44_D_80071918;
            Level11_81E44Keep(retainedValueOrVector16);
            if (Level11_81E44PlanarHeadingLookup(
                    Level11_81E44MeasureVectorLength((void*)(retainedValueOrVector16), 0),
                    Level11_81E44_D_80071920, 0) < 0x15) {
                goto originalBlock143;
            }
        originalBlock142:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = 0U;
            retailWord2 = Level11_81E44PlanarHeadingLookup(
                Level11_81E44Field(ownerRecord18, int*, 0xC) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0),
                Level11_81E44Field(ownerRecord18, int*, 0x10) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4),
                0);
            __asm__ volatile("" ::"i"(3) : "memory");
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            argumentWord5 = retailWord2;
            goto originalBlock150;
        originalBlock143:
            retailWord2 = Level11_81E44PlanarHeadingLookup(
                Level11_81E44Field(retainedValueOrVector16, int*, 0), Level11_81E44_D_8007191C, 0);
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            retailWord2 += 0xB8;
            goto originalBlock149;
        originalBlock144:
            if (temporaryValue44 != 4) {
                goto originalBlock152;
            }
            headingCountOrVector17 = (int)&originalFrame.sp58;
            Level11_81E44CopyVector((void*)(headingCountOrVector17), (void*)(ownerRecord18 + 0xC));
            originalFrame.sp60 += 0x280;
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            __asm__ volatile("" ::: "$16", "memory");
            retainedValueOrVector16 = (int)&originalFrame.sp38;
            retailWord2 *= 2;
            retailWord3 =
                Level11_81E44Field((int)&Level11_81E44_D_80065920 + retailWord2, short*, 0);
            __asm__ volatile("" ::: "$4", "memory");
            argumentWord4 = retainedValueOrVector16;
            Level11_81E44Keep(retailWord3);
            retailWord2 = (retailWord3 * 5) >> 1;
            originalFrame.sp38 = retailWord2;
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = headingCountOrVector17;
            retailWord2 *= 2;
            retailWord3 =
                Level11_81E44Field((int)&Level11_81E44_D_800658A0 + retailWord2, short*, 0);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedValueOrVector16;
            originalFrame.sp40 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord3, "memory");
            retailWord2 = (retailWord3 * 5) >> 1;
            originalFrame.sp3C = retailWord2;
            Level11_81E44AddVector((void*)(argumentWord4), (void*)(argumentWord5),
                                   (void*)(argumentWord6));
            if (Level11_81E44_func_80013E38((void*)(&originalFrame.sp58),
                                            (void*)(&originalFrame.sp38), 0) != 0) {
                goto originalBlock147;
            }
            retainedValueOrVector16 = (int)&Level11_81E44_D_80071918;
            Level11_81E44Keep(retainedValueOrVector16);
            if (Level11_81E44PlanarHeadingLookup(
                    Level11_81E44MeasureVectorLength((void*)(retainedValueOrVector16), 0),
                    Level11_81E44_D_80071920, 0) < 0x15) {
                goto originalBlock148;
            }
        originalBlock147:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = 0U;
            retailWord2 = Level11_81E44PlanarHeadingLookup(
                Level11_81E44Field(ownerRecord18, int*, 0xC) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0),
                Level11_81E44Field(ownerRecord18, int*, 0x10) -
                    Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 4),
                0);
            __asm__ volatile("" ::"i"(4) : "memory");
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            argumentWord5 = retailWord2;
            goto originalBlock150;
        originalBlock148:
            retailWord2 = Level11_81E44PlanarHeadingLookup(
                Level11_81E44Field(retainedValueOrVector16, int*, 0), Level11_81E44_D_8007191C, 0);
            argumentWord4 = ownerRecord18;
            Level11_81E44Keep(argumentWord4);
            retailWord2 += 0x52;
        originalBlock149:
            argumentWord5 = retailWord2 & 0xFF;
        originalBlock150:
            Level11_81E44TurnMobyTowardHeading((void*)(argumentWord4), argumentWord5, 4, 0,
                                               constantOne21, 0);
            headingCountOrVector17 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            goto originalBlock155;
        originalBlock152:
            if (distance20 >= 0x1E00) {
                goto originalBlock154;
            }
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0);
            __asm__ volatile("" ::"i"(0xB) : "memory");
            retailWord2 = 0xB;
            goto originalBlock302;
        originalBlock154:
            temporaryValue45 = Level11_81E44Field(privateRecord19, int*, 0x14);
            temporaryValue27 = (Level11_81E44Field(temporaryValue45, short*, 2) * 0x10) +
                               Level11_81E44Field(temporaryValue45, int*, 0xC);
            headingCountOrVector17 =
                Level11_81E44PlanarHeadingLookup(Level11_81E44Field(temporaryValue27, int*, 0) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0xC),
                                                 Level11_81E44Field(temporaryValue27, int*, 4) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0x10),
                                                 0);
        originalBlock155:
            retainedValueOrVector16 = (int)&originalFrame.sp38;
            argumentWord4 = retainedValueOrVector16;
            argumentWord5 = ownerRecord18 + 0xC;
            Level11_81E44Keep(argumentWord4);
            Level11_81E44Keep(argumentWord5);
            retailWord3 = headingCountOrVector17 * 2;
            Level11_81E44Keep(retailWord3);
            retailWord2 =
                Level11_81E44Field((int)&Level11_81E44_D_80065920 + retailWord3, short*, 0);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedValueOrVector16;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            originalFrame.sp38 = retailWord2 >> 1;
            retailWord2 =
                Level11_81E44Field((int)&Level11_81E44_D_800658A0 + retailWord3, short*, 0);
            retailWord3 = 0x800;
            Level11_81E44Keep(retailWord3);
            originalFrame.sp40 = retailWord3;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            originalFrame.sp3C = retailWord2 >> 1;
            Level11_81E44AddVector((void*)(argumentWord4), (void*)(argumentWord5),
                                   (void*)(argumentWord6));
            temporaryValue4 = Level11_81E44_func_8001A358((void*)(&originalFrame.sp38), 0x3000) +
                              Level11_81E44Field(ownerRecord18, short*, 0x38);
            originalFrame.sp40 = temporaryValue4;
            if (temporaryValue4 < 0x400) {
                goto originalBlock160;
            }
            if (Level11_81E44Field(privateRecord19, int*, 0x14) != 0) {
                goto originalBlock162;
            }
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) == 1) {
                goto originalBlock162;
            }
            temporaryValue47 = Level11_81E44Field(privateRecord19, int*, 8);
            if ((temporaryValue47 + 0x600) < temporaryValue4) {
                goto originalBlock160;
            }
            if (temporaryValue4 >=
                (temporaryValue47 - Level11_81E44Field(ownerRecord18, short*, 0x38))) {
                goto originalBlock162;
            }
        originalBlock160:
            temporaryValue28 = Level11_81E44Field(privateRecord19, unsigned char*, 0x13) + 1;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = temporaryValue28;
            if ((unsigned int)(temporaryValue28 & 0xFF) >= 0x78U) {
                goto originalBlock232;
            }
            retailWord2 = headingCountOrVector17 + 0x10;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned char*, 0x12) = retailWord2;
            retailWord2 = 0xA;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            return;
        originalBlock162:
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord3 = originalFrame.sp40;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            retailWord2 -= retailWord3;
            if (retailWord2 >= 0 ? (retailWord3 = retailWord2, 1)
                                 : (retailWord3 = retailWord2, 0)) {
                goto originalBlock164;
            }
            Level11_81E44Keep(retailWord3);
            retailWord3 = -retailWord3;
        originalBlock164:
            if (retailWord3 < 0x101) {
                goto originalBlock172;
            }
            if (!(Level11_81E44Field(privateRecord19, int*, 0x48) & 1)) {
                goto originalBlock169;
            }
            if ((unsigned int)(Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) - 1) < 2U) {
                goto originalBlock169;
            }
            if (Level11_81E44Test2(retailWord3 < 0x141)) {
                goto originalBlock172;
            }
            goto originalBlock225;
        originalBlock169:
            retailWord2 =
                (Level11_81E44Field(ownerRecord18, int*, 0x14) + 0x800) < originalFrame.sp40;
            if (retailWord2 != 0 ? (retailWord2 = 0x64, 1) : (retailWord2 = 0x64, 0)) {
                goto originalBlock171;
            }
            retailWord2 = 0x96;
        originalBlock171:
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, short*, 0xC) = retailWord2;
            retailWord2 = 8;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = retailWord2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(retailWord2, "memory");
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 8);
        originalBlock172:
            Level11_81E44CopyVector((void*)(&originalFrame.sp48), (void*)(ownerRecord18 + 0xC));
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) != 2) {
                goto originalBlock175;
            }
            if (!(Level11_81E44_func_80035A80(
                      (void*)(ownerRecord18),
                      (void*)(Level11_81E44Field(privateRecord19, int*, 0x14)), 0x100, 0x96, 0xFA,
                      6, 0x30, 0x22) &
                  2)) {
                goto originalBlock176;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0);
            goto originalBlock176;
        originalBlock175:
            Level11_81E44_func_80035DDC((void*)(ownerRecord18), 0x96, 0xFA, 0xFA, 0x22);
        originalBlock176:
            temporaryValue5 = Level11_81E44ProbeGroundFromRaisedMoby((void*)(ownerRecord18)) +
                              Level11_81E44Field(ownerRecord18, short*, 0x38);
            originalFrame.sp40 = temporaryValue5;
            if (temporaryValue5 < 0x400) {
                goto originalBlock181;
            }
            if (Level11_81E44Field(privateRecord19, int*, 0x14) != 0) {
                goto originalBlock185;
            }
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) == 1) {
                goto originalBlock185;
            }
            temporaryValue48 = Level11_81E44Field(privateRecord19, int*, 8);
            if ((temporaryValue48 + 0x600) < temporaryValue5) {
                goto originalBlock181;
            }
            if (temporaryValue5 >=
                (temporaryValue48 - Level11_81E44Field(ownerRecord18, short*, 0x38))) {
                goto originalBlock185;
            }
        originalBlock181:
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(&originalFrame.sp48));
            temporaryValue30 = Level11_81E44Field(privateRecord19, unsigned char*, 0x13) + 1;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = temporaryValue30;
            if ((unsigned int)(temporaryValue30 & 0xFF) < 0x78U) {
                goto originalBlock184;
            }
            temporaryValue31 = Level11_81E44_SpawnMoby(0x164, (void*)(ownerRecord18));
            Level11_81E44Field(privateRecord19, int*, 0x40) = temporaryValue31;
            if (temporaryValue31 == 0) {
                goto originalBlock197;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 5U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 5);
            goto originalBlock197;
        originalBlock184:
            retailWord2 = headingCountOrVector17 + 0x10;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned char*, 0x12) = retailWord2;
            retailWord2 = 0xA;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            goto originalBlock197;
        originalBlock185:
            temporaryValue49 = Level11_81E44Field(privateRecord19, unsigned char*, 0x13);
            if (temporaryValue49 < 7U) {
                goto originalBlock187;
            }
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) =
                (unsigned char)(temporaryValue49 - 6);
            goto originalBlock188;
        originalBlock187:
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = 0U;
        originalBlock188:
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord3 = originalFrame.sp40;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            retailWord2 -= retailWord3;
            if (retailWord2 >= 0 ? (argumentWord4 = retailWord2, 1)
                                 : (argumentWord4 = retailWord2, 0)) {
                goto originalBlock190;
            }
            Level11_81E44Keep(argumentWord4);
            argumentWord4 = -argumentWord4;
        originalBlock190:
            if (argumentWord4 < 0x101) {
                goto originalBlock196;
            }
            if (!(Level11_81E44Field(privateRecord19, int*, 0x48) & 1)) {
                goto originalBlock195;
            }
            if ((unsigned int)(Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) - 1) < 2U) {
                goto originalBlock195;
            }
            if (!Level11_81E44Test2(argumentWord4 < 0x141)) {
                goto originalBlock225;
            }
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord3;
            goto originalBlock197;
        originalBlock195:
            Level11_81E44Field(privateRecord19, short*, 0xC) = 0x96;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 8U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 8);
            goto originalBlock197;
        originalBlock196:
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord3;
        originalBlock197:
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) != 0) {
                goto originalBlock303;
            }
            if (Level11_81E44Test2(distance20 < 0x2801)) {
                goto originalBlock303;
            }
            goto originalBlock225;
        case 0x5:
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) != 0) {
                goto originalBlock206;
            }
            if (Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) == 0x13) {
                goto originalBlock204;
            }
            if (Level11_81E44Test2(distance20 < 0x3001)) {
                goto originalBlock303;
            }
            Level11_81E44RefreshMobySpatialGridAndBasis((void*)(ownerRecord18), 1);
            argumentWord4 = 1;
            retailWord2 = 0x40;
            Level11_81E44Keep(argumentWord4);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = retailWord2;
            retailWord2 = Level11_81E44Field(ownerRecord18, short*, 0x36);
            __asm__ volatile("" ::: "$3", "memory");
            retailWord3 = 6;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = argumentWord4;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = argumentWord4;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = retailWord3;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            retailWord2 =
                Level11_81E44Field((int)&Level11_81E44_D_8006EE2C + retailWord2 * 4, int*, 0);
            retailWord2 = Level11_81E44Field(retailWord2, int*, 0x54);
            retailWord2 = Level11_81E44Field(retailWord2, unsigned char*, 0);
            Level11_81E44Field(ownerRecord18, signed char*, 0x3C) = retailWord3;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3D) = retailWord3;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3E) = 0;
            __asm__ volatile("" ::"i"(0x3001) : "memory");
            Level11_81E44Field(ownerRecord18, signed char*, 0x3F) = argumentWord4;
            goto originalBlock294;
        originalBlock204:
            if (Level11_81E44Test2(distance20 < 0x1801)) {
                goto originalBlock303;
            }
            Level11_81E44RefreshMobySpatialGridAndBasis((void*)(ownerRecord18), 1);
            argumentWord4 = 1;
            retailWord2 = 0x40;
            Level11_81E44Keep(argumentWord4);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = retailWord2;
            retailWord2 = Level11_81E44Field(ownerRecord18, short*, 0x36);
            __asm__ volatile("" ::: "$3", "memory");
            retailWord3 = 6;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = argumentWord4;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = argumentWord4;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = retailWord3;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            retailWord2 =
                Level11_81E44Field((int)&Level11_81E44_D_8006EE2C + retailWord2 * 4, int*, 0);
            retailWord2 = Level11_81E44Field(retailWord2, int*, 0x54);
            retailWord2 = Level11_81E44Field(retailWord2, unsigned char*, 0);
            Level11_81E44Field(ownerRecord18, signed char*, 0x3C) = retailWord3;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3D) = retailWord3;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3E) = 0;
            __asm__ volatile("" ::"i"(0x1801) : "memory");
            Level11_81E44Field(ownerRecord18, signed char*, 0x3F) = argumentWord4;
            goto originalBlock294;
        originalBlock206:
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            if ((unsigned char)Level11_81E44Field(privateRecord19, unsigned char*, 0x13) < 0x78U) {
                goto originalBlock211;
            }
            argumentWord4 = ownerRecord18 + 0xC;
            argumentWord5 = privateRecord19;
            Level11_81E44Keep(argumentWord4);
            Level11_81E44Keep(argumentWord5);
            retailWord2 = Level11_81E44Field(privateRecord19, int*, 0x40);
            __asm__ volatile("" ::: "$3", "memory");
            retailWord3 = 1;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Keep(retailWord3);
            Level11_81E44Field(retailWord2, signed char*, 0x49) = retailWord3;
            Level11_81E44Field(privateRecord19, int*, 0x40) = 0;
            Level11_81E44CopyVector((void*)(argumentWord4), (void*)(argumentWord5));
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::: "$2", "memory");
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            if (retailWord3 == 0) {
                goto originalBlock210;
            }
            Level11_81E44Field(retailWord3, short*, 2) =
                (short)(unsigned short)Level11_81E44Field(privateRecord19, short*, 0xE);
        originalBlock210:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0xEU;
        originalBlock211:
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = 0U;
            return;
        case 0xE:
            temporaryValue6 = privateRecord19 + 0x10;
            if (Level11_81E44Field(privateRecord19, int*, 0x40) == 0) {
                goto originalBlock217;
            }
            temporaryValue50 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            if (temporaryValue50 == 0) {
                goto originalBlock215;
            }
            Level11_81E44Field(temporaryValue50, short*, 2) =
                (short)(unsigned short)Level11_81E44Field(privateRecord19, short*, 0xE);
        originalBlock215:
            if (Level11_81E44CountTimerDown((void*)(temporaryValue6), 2) == 0) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 5U;
            return;
        originalBlock217:
            if (Level11_81E44CountTimerDown((void*)(temporaryValue6), 2) == 0) {
                goto originalBlock303;
            }
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            Level11_81E44Keep(retailWord3);
            argumentWord4 = 0x164;
            if (retailWord3 == 0) {
                goto originalBlock220;
            }
            Level11_81E44Field(retailWord3, short*, 2) =
                (short)(unsigned short)Level11_81E44Field(privateRecord19, short*, 0xE);
        originalBlock220:
            Level11_81E44Keep(argumentWord4);
            argumentWord5 = ownerRecord18;
            retailWord3 = (int)Level11_81E44_SpawnMoby;
            __asm__ volatile("" ::: "$2", "memory");
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            retailWord2 = ((int (*)(int, void*))retailWord3)(argumentWord4, (void*)argumentWord5);
            Level11_81E44Field(privateRecord19, int*, 0x40) = retailWord2;
            return;
        case 0x6:
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock303;
            }
            temporaryValue52 = Level11_81E44Field(privateRecord19, int*, 0x40);
            if (temporaryValue52 == 0) {
                goto originalBlock224;
            }
            Level11_81E44Field(temporaryValue52, signed char*, 0x49) = 1;
            Level11_81E44Field(privateRecord19, int*, 0x40) = 0;
        originalBlock224:
        originalBlock225:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0xBU;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0xB);
            return;
        case 0xB:
            retailWord2 = distance20 < 0x1000;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = 0;
            if (retailWord2 == 0) {
                goto originalBlock230;
            }
            if ((unsigned int)(Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) - 7) <
                2U) {
                goto originalBlock303;
            }
            if (Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 0x50) == 0x13) {
                goto originalBlock303;
            }
            goto originalBlock233;
        originalBlock230:
            __asm__ volatile("" ::"r"(distance20) : "$2", "memory");
            if (Level11_81E44Test2(distance20 < 0x2001)) {
                goto originalBlock303;
            }
            temporaryValue18 = Level11_81E44Field(privateRecord19, unsigned char*, 0x13) + 6;
            Level11_81E44Field(privateRecord19, unsigned char*, 0x13) = temporaryValue18;
            if ((unsigned int)(temporaryValue18 & 0xFF) < 0x78U) {
                goto originalBlock235;
            }
        originalBlock232:
        originalBlock233:
            temporaryValue19 = Level11_81E44_SpawnMoby(0x164, (void*)(ownerRecord18));
            Level11_81E44Field(privateRecord19, int*, 0x40) = temporaryValue19;
            if (temporaryValue19 == 0) {
                goto originalBlock303;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 5U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 5);
            return;
        originalBlock235:
            temporaryValue9 = Level11_81E44Field(privateRecord19, int*, 0x18);
            if (temporaryValue9 == 0) {
                goto originalBlock240;
            }
            retailWord3 = Level11_81E44Field((int)&Level11_81E44_D_80070328, int*, 8);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            Level11_81E44Keep(retailWord3);
            retailWord2 = retailWord2 < retailWord3;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock284;
            }
            Level11_81E44GetClosestPathNode((void*)(ownerRecord18 + 0xC), (void*)(temporaryValue9),
                                            (int*)(&originalFrame.sp68));
            if (originalFrame.sp68 >=
                (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0) -
                 1)) {
                goto originalBlock239;
            }
            originalFrame.sp68 += 1;
        originalBlock239:
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), unsigned short*,
                               2) = (unsigned short)originalFrame.sp68;
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0xA) = 1;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0xF) : "memory");
            retailWord2 = 0xF;
            goto originalBlock302;
        originalBlock240:
            retainedValueOrVector16 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            if (retainedValueOrVector16 == 0) {
                goto originalBlock249;
            }
            retailWord2 = Level11_81E44Field(ownerRecord18, unsigned char*, 0x46);
            retainedValueOrVector16 =
                Level11_81E44Field(retainedValueOrVector16, unsigned short*, 0);
            retailWord2 += 0x80;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x46) = retailWord2;
            retainedValueOrVector16 = (int)((unsigned int)retainedValueOrVector16 << 16);
            Level11_81E44GetClosestPathNode(
                (void*)((int)&Level11_81E44_D_80070328),
                (void*)(Level11_81E44Field(privateRecord19, int*, 0x1C)),
                (int*)(&originalFrame.sp6C));
            retailWord2 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            headingCountOrVector17 = retainedValueOrVector16 >> 16;
            retailWord3 = Level11_81E44Field(retailWord2, short*, 2);
            retailWord2 = originalFrame.sp6C;
            retainedValueOrVector16 = retainedValueOrVector16 >> 17;
            retailWord3 = retailWord2 - retailWord3;
            retainedValueOrVector16 = retainedValueOrVector16 < retailWord3;
            Level11_81E44Keep(retainedValueOrVector16);
            originalFrame.sp6C = retailWord3;
            if (retainedValueOrVector16 == 0) {
                goto originalBlock243;
            }
            retailWord2 = retailWord3 - headingCountOrVector17;
            goto originalBlock244;
        originalBlock243:
            retailWord2 = -headingCountOrVector17;
            Level11_81E44Keep(retailWord2);
            retailWord2 = retailWord2 >> 1;
            Level11_81E44Keep(retailWord2);
            retailWord2 = retailWord3 < retailWord2;
            if (retailWord2 == 0 ? (retailWord2 = retailWord3 + headingCountOrVector17, 1)
                                 : (retailWord2 = retailWord3 + headingCountOrVector17, 0)) {
                goto originalBlock245;
            }
        originalBlock244:
            Level11_81E44Keep(retailWord2);
            originalFrame.sp6C = retailWord2;
        originalBlock245:
            if (originalFrame.sp6C <= 0) {
                goto originalBlock247;
            }
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::"i"(-1) : "memory");
            retailWord2 = -1;
            goto originalBlock248;
        originalBlock247:
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            __asm__ volatile("" ::"i"(1) : "memory");
            retailWord2 = 1;
        originalBlock248:
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(retailWord3, short*, 0xA) = (short)retailWord2;
            temporaryValue55 = Level11_81E44Field(privateRecord19, int*, 0x1C);
            temporaryValue16 =
                (int)(Level11_81E44Field(temporaryValue55, short*, 2) + headingCountOrVector17 +
                      Level11_81E44Field(temporaryValue55, short*, 0xA)) %
                headingCountOrVector17;
            Level11_81E44Field(temporaryValue55, short*, 2) = (short)temporaryValue16;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0x10) : "memory");
            retailWord2 = 0x10;
            goto originalBlock302;
        originalBlock249:
            argumentWord5 = Level11_81E44Field(privateRecord19, int*, 0x14);
            retailWord2 = 1;
            if (argumentWord5 == 0) {
                goto originalBlock255;
            }
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 8);
            Level11_81E44Keep(retailWord3);
            retailWord2 = (int)((unsigned int)retailWord2 - (unsigned int)retailWord3);
            retailWord2 = retailWord2 < -0x100;
            Level11_81E44Keep(retailWord2);
            __asm__ volatile("" ::"r"(retailWord2) : "$4", "memory");
            argumentWord4 = ownerRecord18 + 0xC;
            if (retailWord2 == 0) {
                goto originalBlock254;
            }
            Level11_81E44GetClosestPathNode((void*)(argumentWord4), (void*)(argumentWord5),
                                            (int*)(&originalFrame.sp70));
            retailWord2 = Level11_81E44Field(privateRecord19, int*, 0x14);
            retailWord2 = Level11_81E44Field(retailWord2, short*, 0);
            MATCHING_BARRIER_VOLATILE("memory");
            retailWord3 = originalFrame.sp70;
            Level11_81E44Keep(retailWord3);
            retailWord2 -= 1;
            retailWord2 = retailWord3 < retailWord2;
            Level11_81E44Keep(retailWord2);
            if (retailWord2 == 0) {
                goto originalBlock253;
            }
            MATCHING_OBSERVE_VOLATILE_CLOBBER(retailWord3, "memory");
            retailWord2 = retailWord3 + 1;
            originalFrame.sp70 = retailWord2;
        originalBlock253:
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x14);
            retailWord2 = originalFrame.sp70;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(retailWord3, short*, 2) = retailWord2;
            retailWord3 = Level11_81E44Field(privateRecord19, int*, 0x14);
            __asm__ volatile("" ::: "$2", "memory");
            retailWord2 = 1;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(retailWord3, short*, 0xA) = retailWord2;
            retailWord2 = 2;
            goto originalBlock255;
        originalBlock254:
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "memory");
            retailWord2 = 1;
        originalBlock255:
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = retailWord2;
            goto originalBlock281;
        case 0x8:
            temporaryValue56 = Level11_81E44Field(privateRecord19, int*, 0x18);
            if (temporaryValue56 == 0) {
                goto originalBlock258;
            }
            temporaryValue20 =
                ((short)Level11_81E44Field(temporaryValue56, unsigned short*, 2) * 0x10) +
                Level11_81E44Field(temporaryValue56, int*, 0xC);
            Level11_81E44TurnMobyTowardHeading(
                (void*)(ownerRecord18),
                Level11_81E44PlanarHeadingLookup(Level11_81E44Field(temporaryValue20, int*, 0) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0xC),
                                                 Level11_81E44Field(temporaryValue20, int*, 4) -
                                                     Level11_81E44Field(ownerRecord18, int*, 0x10),
                                                 0),
                6, 0, 1, 0);
        originalBlock258:
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock260;
            }
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 9);
        originalBlock260:
            headingCountOrVector17 = (int)&originalFrame.sp78;
            argumentWord4 = headingCountOrVector17;
            __asm__ volatile("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$16", "memory");
            retainedValueOrVector16 = ownerRecord18 + 0xC;
            Level11_81E44CopyVector((void*)(argumentWord4), (void*)(retainedValueOrVector16));
            retailWord3 = Level11_81E44Field(privateRecord19, short*, 0xC);
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            Level11_81E44Keep(retailWord3);
            retailWord2 += retailWord3;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord2;
            retailWord2 = Level11_81E44Field(privateRecord19, unsigned short*, 0xC);
            retailWord2 -= 0xA;
            Level11_81E44Field(privateRecord19, short*, 0xC) = retailWord2;
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            retailWord2 = (int)((unsigned int)retailWord2 << 16) >> 16;
            retailWord2 = retailWord2 < -0x12C;
            if (retailWord2 == 0 ? (retailWord2 = -0x12C, 1) : (retailWord2 = -0x12C, 0)) {
                goto originalBlock262;
            }
            Level11_81E44Field(privateRecord19, short*, 0xC) = retailWord2;
        originalBlock262:
            Level11_81E44_func_80035DDC((void*)(ownerRecord18), 0x64, 0xFA, 0x96, 0x22);
            argumentWord4 = retainedValueOrVector16;
            argumentWord5 = 0x2800;
            retailWord2 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            retailWord2 += 0x200;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord2;
            retailWord2 = Level11_81E44_func_8001A358((void*)(argumentWord4), argumentWord5);
            retailWord3 = Level11_81E44Field(ownerRecord18, int*, 0x14);
            argumentWord4 = Level11_81E44Field(ownerRecord18, short*, 0x38);
            retailWord3 -= 0x200;
            argumentWord6 = retailWord2 + argumentWord4;
            Level11_81E44Keep(argumentWord6);
            Level11_81E44Keep(retailWord3);
            retailWord2 = argumentWord6 < 0x400;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord3;
            if (retailWord2 == 0) {
                goto originalBlock264;
            }
            Level11_81E44CopyVector((void*)(retainedValueOrVector16),
                                    (void*)(headingCountOrVector17));
            temporaryValue22 = Level11_81E44ProbeGroundFromRaisedMoby((void*)(ownerRecord18));
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0xAU;
            Level11_81E44Field(ownerRecord18, int*, 0x14) =
                (int)(temporaryValue22 + Level11_81E44Field(ownerRecord18, short*, 0x38));
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0xA);
            return;
        originalBlock264:
            if (Level11_81E44Test2(argumentWord6 < retailWord3)) {
                goto originalBlock303;
            }
            argumentWord4 = ownerRecord18;
            argumentWord5 = 0xA;
            retailWord2 = 0xA;
            Level11_81E44Field(ownerRecord18, int*, 0x14) = argumentWord6;
            goto originalBlock280;
        case 0xA:
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock303;
            }
            temporaryValue11 = Level11_81E44Field(privateRecord19, int*, 0x18);
            if (temporaryValue11 == 0) {
                goto originalBlock273;
            }
            Level11_81E44GetClosestPathNode((void*)(ownerRecord18 + 0xC), (void*)(temporaryValue11),
                                            (int*)(&originalFrame.sp88));
            temporaryValue23 =
                originalFrame.sp88 +
                Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0xA);
            originalFrame.sp88 = temporaryValue23;
            if (temporaryValue23 >= 0) {
                goto originalBlock270;
            }
            originalFrame.sp88 = 0;
        originalBlock270:
            temporaryValue58 =
                Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), short*, 0) - 1;
            if (temporaryValue58 >= originalFrame.sp88) {
                goto originalBlock272;
            }
            originalFrame.sp88 = temporaryValue58;
        originalBlock272:
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x18), unsigned short*,
                               2) = (unsigned short)originalFrame.sp88;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            __asm__ volatile("" ::"i"(0xF) : "memory");
            retailWord2 = 0xF;
            goto originalBlock302;
        originalBlock273:
            temporaryValue12 = Level11_81E44Field(privateRecord19, int*, 0x14);
            if (temporaryValue12 == 0) {
                goto originalBlock281;
            }
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) == 2) {
                goto originalBlock276;
            }
            if ((Level11_81E44Field(ownerRecord18, int*, 0x14) -
                 Level11_81E44Field(privateRecord19, int*, 8)) >= -0x100) {
                goto originalBlock282;
            }
        originalBlock276:
            Level11_81E44GetClosestPathNode((void*)(ownerRecord18 + 0xC), (void*)(temporaryValue12),
                                            (int*)(&originalFrame.sp8C));
            if (originalFrame.sp8C >=
                (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x14), short*, 0) -
                 1)) {
                goto originalBlock278;
            }
            originalFrame.sp8C += 1;
        originalBlock278:
            Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x14), short*, 2) =
                (short)originalFrame.sp8C;
            if (Level11_81E44_func_80035A80(
                    (void*)(ownerRecord18),
                    (void*)(Level11_81E44Field(privateRecord19, int*, 0x14)), 0x100, 0x64, 0xFA, 6,
                    0x30, 0x26) &
                2) {
                goto originalBlock284;
            }
            argumentWord4 = ownerRecord18;
            argumentWord5 = 4;
            retailWord2 = 2;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(argumentWord4, unsigned char*, 0x49) = retailWord2;
            retailWord2 = 4;
        originalBlock280:
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(argumentWord4, signed char*, 0x48) = retailWord2;
            Level11_81E44RequestMobyAnimation((void*)(argumentWord4), argumentWord5);
            return;
        originalBlock281:
        originalBlock282:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 4U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 4);
            return;
        case 0x3:
            Level11_81E44TurnMobyTowardPlayer((void*)(ownerRecord18), 4, 0, 1);
            if (Level11_81E44_D_8006C770 == 0) {
                goto originalBlock303;
            }
        originalBlock284:
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0U;
            Level11_81E44RequestMobyAnimation((void*)(ownerRecord18), 0);
            return;
        case 0x5C:
            if (Level11_81E44_func_80035194((void*)(ownerRecord18),
                                            (void*)(privateRecord19 + 0x28)) != 0x100) {
                goto originalBlock303;
            }
            Level11_81E44RefreshMobySpatialGridAndBasis((void*)(ownerRecord18), 4);
            Level11_81E44_func_800369B8((void*)(ownerRecord18), 0x18);
            retailWord2 = 0xFF;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = retailWord2;
            retailWord2 = 0x61;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            __asm__ volatile("" ::"i"(0x61) : "memory");
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            goto originalBlock302;
        case 0x5F:
            argumentWord4 = ownerRecord18;
            __asm__ volatile("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$2", "memory");
            retailWord2 = 0xFF;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = retailWord2;
            temporaryValue24 = Level11_81E44ProbeGroundFromRaisedMoby((void*)(argumentWord4)) +
                               Level11_81E44Field(privateRecord19, int*, 0x44);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = temporaryValue24;
            Level11_81E44Field(privateRecord19, int*, 0x44) = temporaryValue24;
            __asm__ volatile("" ::"i"(0x5E) : "memory");
            retailWord2 = 0x5E;
            goto originalBlock302;
        case 0x61:
            retainedValueOrVector16 = ownerRecord18 + 0x48;
            if (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x24), int*, 0) != 0) {
                goto originalBlock290;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0x5FU;
            Level11_81E44_func_8003B7B4((void*)(retainedValueOrVector16), 1,
                                        (void*)((int)&Level11_81E44_D_8006D088));
            Level11_81E44_func_8003B7B4((void*)(retainedValueOrVector16), 1,
                                        (void*)((int)&Level11_81E44_D_8006C7F8));
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0x5EU;
        case 0x5E:
        originalBlock290:
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) != 1) {
                goto originalBlock303;
            }
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(privateRecord19));
            argumentWord4 = 0x167;
            Level11_81E44Keep(argumentWord4);
            retainedValueOrVector16 = 1;
            headingCountOrVector17 = 0x40;
            Level11_81E44Keep(retainedValueOrVector16);
            Level11_81E44Keep(headingCountOrVector17);
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = retainedValueOrVector16;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = headingCountOrVector17;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = retainedValueOrVector16;
            retailWord2 = Level11_81E44Field(privateRecord19, int*, 0x44);
            retailWord3 = (int)Level11_81E44_SpawnMoby;
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = ownerRecord18;
            Level11_81E44Keep(retailWord3);
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, int*, 0x14) = retailWord2;
            retailWord2 = ((int (*)(int, void*))retailWord3)(argumentWord4, (void*)argumentWord5);
            Level11_81E44Field(privateRecord19, int*, 0x40) = retailWord2;
            if (retailWord2 == 0) {
                goto originalBlock293;
            }
            Level11_81E44Field(retailWord2, signed char*, 0x4C) = headingCountOrVector17;
            temporaryValue59 = Level11_81E44Field(privateRecord19, int*, 0x40);
            Level11_81E44Field(temporaryValue59, int*, 0x14) =
                (int)(Level11_81E44Field(temporaryValue59, int*, 0x14) + 0x300);
        originalBlock293:
            Level11_81E44RefreshMobySpatialGridAndBasis((void*)(ownerRecord18), 3);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0xCU;
            retailWord2 = Level11_81E44Field(
                Level11_81E44Field(
                    Level11_81E44Field((int)&Level11_81E44_D_8006EE2C +
                                           (Level11_81E44Field(ownerRecord18, short*, 0x36) * 4),
                                       int*, 0),
                    int*, 0x6C),
                unsigned char*, 0);
            Level11_81E44Field(ownerRecord18, signed char*, 0x3C) = 0xC;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3D) = 0xC;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3E) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x3F) = retainedValueOrVector16;
        originalBlock294:
            MATCHING_KEEP_VOLATILE_CLOBBER(retailWord2, "memory");
            retailWord2 = (unsigned int)retailWord2 < 2U;
            Level11_81E44Keep(retailWord2);
            retailWord2 ^= 1;
            Level11_81E44Keep(retailWord2);
            retailWord2 = -retailWord2;
            Level11_81E44Keep(retailWord2);
            retailWord2 &= 0x30;
            Level11_81E44Field(ownerRecord18, signed char*, 0x40) = retailWord2;
            return;
        case 0x5A:
            if (Level11_81E44_func_80035194((void*)(ownerRecord18),
                                            (void*)(privateRecord19 + 0x28)) != 0x100) {
                goto originalBlock303;
            }
            Level11_81E44RefreshMobySpatialGridAndBasis((void*)(ownerRecord18), 4);
            Level11_81E44_func_800369B8((void*)(ownerRecord18), 0x18);
            retailWord2 = 0xFF;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = retailWord2;
            retailWord2 = 0x60;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            __asm__ volatile("" ::"i"(0x60) : "memory");
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            goto originalBlock302;
        case 0x5D:
            retailWord2 = 0xFF;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) = retailWord2;
            retailWord2 = 0x5B;
            Level11_81E44Field(ownerRecord18, signed char*, 0x41) = 0;
            Level11_81E44Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x4D) = 0U;
            __asm__ volatile("" ::"i"(0x5B) : "memory");
            Level11_81E44Field(ownerRecord18, int*, 8) = 0;
            goto originalBlock302;
        case 0x60:
            retainedValueOrVector16 = ownerRecord18 + 0x48;
            if (Level11_81E44Field(Level11_81E44Field(privateRecord19, int*, 0x24), int*, 0) != 0) {
                goto originalBlock300;
            }
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0x5DU;
            Level11_81E44_func_8003B7B4((void*)(retainedValueOrVector16), 1,
                                        (void*)((int)&Level11_81E44_D_8006D088));
            Level11_81E44_func_8003B7B4((void*)(retainedValueOrVector16), 1,
                                        (void*)((int)&Level11_81E44_D_8006C7F8));
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = 0x5BU;
        case 0x5B:
        originalBlock300:
            if (Level11_81E44Field(ownerRecord18, unsigned char*, 0x49) != 1) {
                goto originalBlock303;
            }
            Level11_81E44CopyVector((void*)(ownerRecord18 + 0xC), (void*)(privateRecord19));
            retailWord2 = 0x3C;
            Level11_81E44Keep(retailWord2);
            Level11_81E44Field(privateRecord19, unsigned short*, 0x10) = retailWord2;
            retailWord2 = 0xE;
        originalBlock302:
            MATCHING_OBSERVE_VOLATILE_CLOBBER(retailWord2, "memory");
            Level11_81E44Field(ownerRecord18, unsigned char*, 0x48) = retailWord2;
        originalBlock303:
            return;
    }
}
#undef Level11_81E44Field
#undef Level11_81E44Keep

void func_80055B18(Moby*);
void func_level_11_80083F84(Moby* moby) {
    switch (moby->state) {
        case 0:
            moby->size -= 8;
            if (moby->size <= 0x20) {
                moby->size = 0;
                moby->state = 1;
            }
            break;
        case 1:
            if (moby->substate) {
                moby->size = 0x21;
                moby->state = 2;
            }
            break;
        case 2:
            moby->size += 8;
            if (moby->size >= 0x7F)
                func_80055B18(moby);
            break;
    }
}

void func_80039714(Moby*);
void func_level_11_8008404C(Moby* moby) {
    if (moby->animationState.id != 0)
        func_80039714(moby);
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level11 0x8008407C..0x800843C4: 210 original instructions.
 * Original 56-byte frame, 88-byte pool stride, nested word pointers, helper
 * arguments, state byte rereads, 16-call spawn loop and shared delete tail
 * preserved. Offset names describe storage; helper contracts, physical
 * units and caller cadence remain unresolved. Empty compiler constraints
 * emit no CPU instructions. Acceptance requires original linked words and
 * every EXE/overlay retail hash.
 */
#define P8407CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int D_8006E048;
extern Spyro P8407CPlayer __asm__("D_80070328");
void func_level_11_8008407C(Moby* argument) {
    register Moby* owner __asm__("$17") = argument;
    register int value19 __asm__("$19"), value20 __asm__("$20");
    Moby* child;
    register Vector3D* ownerPosition __asm__("$16");
    register int spawnIndex __asm__("$16");
    unsigned char substateByte;
    register int stateByte __asm__("$3"), index __asm__("$3");
    register Moby *pool __asm__("$4"), *spawnOwner __asm__("$5");
    register int spawnClass __asm__("$4");
    register void* privateState16 __asm__("$16");
    register void* privateState18 __asm__("$18");

    MATCHING_KEEP(owner);
    privateState16 = owner->mobyTag;
    MATCHING_KEEP_CLOBBER(privateState16, "$19");
    value19 = 1;
    MATCHING_KEEP(value19);
    index = P8407CField(privateState16, int*, 4);
    MATCHING_KEEP_CLOBBER(index, "$4");
    pool = D_8006C550;
    __asm__("" : "=r"(pool) : "0"(pool), "r"(index));
    privateState18 = pool[index].mobyTag;
    stateByte = owner->state;
    if (stateByte == value19)
        goto state1;
    if (stateByte < 2) {
        if (!stateByte)
            goto state0;
        goto finished;
    }
    if (stateByte == 2)
        goto state2;
    goto finished;
    {
    state0:
        if (!(pool[P8407CField(privateState16, int*, 8)].state & 0x80) && !(D_8006C7B4 & 1) &&
            (ownerPosition = &owner->position, ((D_80070300[D_8006C58C] & 1) == 0))) {
            if (func_8004F334(ownerPosition, &P8407CPlayer.position) < 0x2800) {
                func_80013AE4(
                    P8407CField(P8407CField(privateState18, void**, 0xC), Vector3D**, 0xC),
                    ownerPosition);
                owner->substate = 1;
                if (D_8006E048 == value19) {
                    P8407CPlayer.unk17a = 0x10000002;
                    P8407CPlayer.unk20[1] = 0;
                    owner->state = 1;
                    func_80034F40(owner, 1);
                    return;
                }
            }
        } else {
            goto deleteOwner;
        }
        goto finished;
    state1:
        func_80013AE4(P8407CField(P8407CField(privateState18, void**, 0xC), Vector3D**, 0xC),
                      &owner->position);
        P8407CPlayer.unk17a = 0x10000002;
        P8407CPlayer.unk20[1] = 0;
        if (D_8006C770 != 0) {
            D_8006C550[P8407CField(privateState16, int*, 4)].state = 1;
            func_80034F40(&D_8006C550[P8407CField(privateState16, int*, 4)], 1);
            owner->state = 2;
            func_80034F40(owner, 2);
            return;
        }
        goto finished;
    state2:
        substateByte = owner->substate;
        if (substateByte == value19) {
            func_80013AE4(P8407CField(P8407CField(privateState18, void**, 0xC), Vector3D**, 0xC),
                          &owner->position);
            P8407CPlayer.unk17a = 0x10000002;
            P8407CPlayer.unk20[1] = 0;
            if (func_80035A80(owner, P8407CField(privateState16, int*, 0), 0x100, 0x15E, 0, 6, 0x40,
                              0x20004) &
                2) {
                spawnIndex = 0;
                value20 = 0xFF;
                value19 = 0x3F;
                do {
                    spawnClass = 0xF5;
                    spawnOwner = owner;
                    MATCHING_OBSERVE2(spawnClass, spawnOwner);
                    spawnIndex += 1;
                    child = SpawnMoby(spawnClass, spawnOwner);
                    child->updateDistance = value20;
                    child->highDrawDistance = value19;
                } while (spawnIndex < 0x10);
                func_8003BABC(owner, 0, 1);
                owner->substate = 2;
                P8407CField(privateState18, int*, 0x10) = 0x78;
                return;
            }
        } else if ((substateByte == stateByte) && (func_800359A4(privateState18 + 0x10, 4) != 0)) {
            func_80013B7C(1);
            goto deleteOwner;
        }
        goto finished;
    }
finished:
    return;
deleteOwner:
    func_80055B18(owner);
}

#undef P8407CField


/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level11 0x800843C4..0x800846B8: 189 original instructions.
 * Field offsets, signed load widths, wrapping shifts and post-call rereads
 * are preserved. Helper contracts, physical units and caller cadence remain
 * unresolved. Empty constraints emit no CPU instructions; compilerFrameSlot
 * retains the original 40-byte frame and is never accessed by generated code.
 * Acceptance requires original linked words and full EXE/all-overlay hashes.
 */
#define P843C4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Spyro P843C4_D_80070328 __asm__("D_80070328");
extern int P843C4_D_8006C648 __asm__("D_8006C648");
int P843C4CountTimerDown(void* pTimer, int pTimerType) __asm__("func_800359A4");
int P843C4SubAngle8(int owner, int arg1) __asm__("func_8003613C");
int P843C4PlayMobySoundEvent(Moby* owner, int index, int selector) __asm__("func_8003BABC");
void P843C4_func_8003BE70(int index) __asm__("func_8003BE70");
int P843C4_func_8003BFC0(Moby* soundPtr, int index) __asm__("func_8003BFC0");
void P843C4_func_8003C140(int index, int value) __asm__("func_8003C140");
void func_level_11_800843C4(Moby* argument) {
    register Moby* owner __asm__("$18") = argument;
    short handle;
    register int counter16 __asm__("$2");
    register int counterWork __asm__("$2");
    int compilerFrameSlot;
    register int packedCounter __asm__("$3");
    register int magnitude __asm__("$5");
    register int helperResult __asm__("$17");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    unsigned short stored14;
    unsigned short adjusted14;
    register void* privateState __asm__("$16");
    void* samplePointer;

    MATCHING_KEEP(owner);
    __asm__("" : : "m"(compilerFrameSlot));
    privateState = owner->mobyTag;
    if (owner->damageFlags & 0x20000) {
        if ((P843C4_D_80070328.animationState == 0xE) ||
            (P843C4_D_80070328.animationState == 0x15)) {
            P843C4Field(privateState, short*, 0) = 0;
            P843C4Field(privateState, short*, 2) = 1;
            P843C4Field(privateState, int*, 4) = (int)owner->angle.roll;
            P843C4Field(privateState, int*, 8) = (int)owner->angle.pitch;
            P843C4Field(privateState, int*, 0xC) = (int)owner->position.z;
        } else {
            helperResult =
                P843C4SubAngle8(func_8004E880(owner->position.x - P843C4_D_80070328.position.x,
                                              owner->position.y - P843C4_D_80070328.position.y, 0),
                                (int)P843C4_D_80070328.bodyRotation.yaw);
            owner->updateDistance = 0x40;
            P843C4Field(privateState, short*, 0) = 0x78;
            P843C4Field(privateState, short*, 2) = 0;
            if (P843C4Field(privateState, short*, 0x16) == -1) {
                P843C4Field(privateState, short*, 0x16) = P843C4PlayMobySoundEvent(owner, 0, 4);
            }
            if (helperResult < 0) {
                adjusted14 = P843C4Field(privateState, unsigned short*, 0x14) + 0x80;
            } else {
                adjusted14 = P843C4Field(privateState, unsigned short*, 0x14) - 0x80;
            }
            P843C4Field(privateState, unsigned short*, 0x14) = adjusted14;
        }
    }
    owner->damageFlags = 0;
    if (P843C4CountTimerDown(privateState, 2) == 0) {
        if (P843C4_func_8003BFC0(owner, (int)P843C4Field(privateState, short*, 0x16)) == 0) {
            P843C4Field(privateState, short*, 0x16) = P843C4PlayMobySoundEvent(owner, 0, 4);
        }
        handle = P843C4Field(privateState, short*, 0x16);
        if (handle >= 0) {
            magnitude = (short)P843C4Field(privateState, unsigned short*, 0x14);
            if (magnitude < 0) {
                magnitude = -magnitude;
            }
            P843C4_func_8003C140((int)handle, (int)(magnitude << 0xC) >> 8);
            owner->angle.yaw +=
                (int)(P843C4Field(privateState, unsigned short*, 0x14) << 0x10) >> 0x14;
            stored14 = P843C4Field(privateState, unsigned short*, 0x14);
            P843C4Field(privateState, unsigned short*, 0x14) =
                (unsigned short)(stored14 - ((int)(stored14 << 0x10) >> 0x14));
        }
    } else {
        if (P843C4_func_8003BFC0(owner, (int)P843C4Field(privateState, short*, 0x16)) != 0) {
            P843C4_func_8003BE70((int)P843C4Field(privateState, short*, 0x16));
        }
        P843C4Field(privateState, short*, 0x16) = -1;
        P843C4Field(privateState, unsigned short*, 0x14) = 0U;
    }
    counter16 = P843C4Field(privateState, short*, 2);
    if (counter16 != 0) {
        packedCounter = counter16;
        MATCHING_KEEP(packedCounter);
        counterWork = packedCounter + P843C4_D_8006C648;
        packedCounter = counterWork << 16;
        __asm__("" : "=r"(packedCounter) : "0"(packedCounter), "r"(counterWork));
        P843C4Field(privateState, short*, 2) = counterWork;
        if ((packedCounter >> 16) < 0x40) {
            counterWork = packedCounter >> 17;
            MATCHING_KEEP(counterWork);
            owner->angle.roll =
                *(unsigned char*)((counterWork * 2) + P843C4Field(privateState, int*, 0x18)) +
                P843C4Field(privateState, int*, 4);
            owner->angle.pitch =
                (*(unsigned char*)((unsigned char*)((
                                       (((int)((unsigned short)P843C4Field(privateState, short*, 2)
                                               << 0x10) >>
                                         0x11) *
                                        2) +
                                       P843C4Field(privateState, int*, 0x18))) +
                                   1)) +
                P843C4Field(privateState, int*, 8);
            samplePointer =
                (((int)((unsigned short)P843C4Field(privateState, short*, 2) << 0x10) >> 0x11) *
                 2) +
                P843C4Field(privateState, int*, 0x18);
            work3 = (*(signed char*)((unsigned char*)(samplePointer) + 0));
            work2 = (*(signed char*)((unsigned char*)(samplePointer) + 1));
            if (work3 < 0) {
                work3 = -work3;
            }
            if (work2 < 0) {
                work2 = -work2;
            }
            work3 += work2;
            MATCHING_KEEP(work3);
            work2 = work3 * 3;
            MATCHING_KEEP(work2);
            work3 = P843C4Field(privateState, int*, 0xC) + (work2 << 1);
            owner->position.z = work3;
            return;
        }
        P843C4Field(privateState, short*, 2) = 0;
        owner->angle.roll = (unsigned char)P843C4Field(privateState, int*, 4);
        owner->angle.pitch = (unsigned char)P843C4Field(privateState, int*, 8);
        owner->position.z = P843C4Field(privateState, int*, 0xC);
    }
}

#undef P843C4Field


extern Moby* D_8006C550;
extern unsigned char D_8006C7B4, D_80070300[];
extern int D_8006C58C;
int func_80035A80(Moby*, int, int, int, int, int, int, int);
void func_level_11_800846B8(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if ((D_8006C550[tag[2]].state & 0x80) || (D_8006C7B4 & 1) ||
                (D_80070300[D_8006C58C] & 1))
                func_80055B18(moby);
            break;
        case 1:
            if (func_80035A80(moby, tag[0], 0x100, 0x177, 0, 6, 0x40, 0x20004) & 2)
                func_80055B18(moby);
            break;
    }
}

typedef struct {
    int reserved00[6];
    int minimumHeight, maximumHeight;
    Vector3D restorePosition;
    int reserved2C[3];
    int maximumDistance;
} DecodedRangeTag;
extern unsigned char DecodedRangePlayer[] __asm__("D_80070328");
extern int DecodedRangeOverride __asm__("D_8006E160");
extern Moby* DecodedRangeOwner __asm__("D_8006E164");
int DecodedRangeDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
/* SCUS-94467 USA Rev 0: level 11, 0x800847B0..0x8008490C.
 * Signed word bounds, signed ground-distance halfword and original thresholds.
 * Raw position units and invoking cadence remain unresolved.
 * Empty constraints retain original argument scheduling; no instructions added.
 * AI generated; not yet human reviewed.
 */
void func_level_11_800847B0(Moby* argument) {
    register Moby* moby __asm__("$17") = argument;
    register DecodedRangeTag* tag __asm__("$16") = moby->mobyTag;
    register Vector3D* position __asm__("$4");
    register Vector3D* restore __asm__("$5");
    if (!moby->state) {
        register int height __asm__("$4") = *(int*)(DecodedRangePlayer + 8);
        register int delta __asm__("$3");
        if (tag->minimumHeight >= height)
            return;
        if (height >= tag->maximumHeight)
            return;
        delta =
            moby->position.z - moby->distanceToGround - height + *(int*)(DecodedRangePlayer + 0x44);
        if (delta < 0)
            delta = -delta;
        if (delta >= 1536)
            return;
        if (DecodedRangeOverride)
            return;
        func_80013ACC(moby, 12);
        moby->state = 1;
    } else {
        if (DecodedRangeOwner != moby) {
            position = &moby->position;
            restore = &tag->restorePosition;
            goto reset;
        }
        {
            int height = *(int*)(DecodedRangePlayer + 8);
            if (height < tag->minimumHeight - 512 || height > tag->maximumHeight + 512 ||
                DecodedRangeDistance(&moby->position, (Vector3D*)DecodedRangePlayer) >
                    tag->maximumDistance + 512) {
                position = &moby->position;
                restore = &tag->restorePosition;
                MATCHING_OBSERVE2(position, restore);
                DecodedRangeOverride = 0;
                DecodedRangeOwner = 0;
            } else {
                return;
            }
        }
    reset:
        func_8004F178(position, restore);
        moby->state = 0;
    }
}

typedef struct {
    unsigned char reserved00[0x18];
    int counter;
} DecodedVectorForceTag;
extern short D_800658A0[], D_80065920[];
void func_level_11_80084910(Moby* moby) {
    DecodedVectorForceTag* tag = moby->mobyTag;
    int movement;
    if (func_80036220(&spyro.position, tag, 0, 0x300) &&
        ((movement = spyro.movementState) == 0xA || (unsigned int)movement < 2 || movement == 3)) {
        if (tag->counter < 0x78)
            tag->counter += 3;
        spyro.unk17a = 0x10000408;
        spyro.unk17e.x = (D_80065920[moby->angle.yaw] * tag->counter) >> 12;
        spyro.unk17e.y = (D_800658A0[moby->angle.yaw] * tag->counter) >> 12;
        spyro.unk17e.z = 0;
        spyro.unk18.yaw = 0;
    } else
        tag->counter = 0;
}

extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_11_80084A30(Moby* moby) {
    if (D_8006C770 != 0)
        func_80055B18(moby);
}
