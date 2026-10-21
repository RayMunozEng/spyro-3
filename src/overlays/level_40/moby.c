#include "matching.h"
#include "common.h"
#include "camera.h"
#include "savepoint.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "mobyutil.h"
#include "spyro.h"
extern void func_80039714(Moby*);

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
void func_level_40_800749B0(void* input) {
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
void func_level_40_8007560C(Moby* argument) {
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
void func_level_40_80075C98(void* input) {
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
void func_level_40_800771E8(Moby* moby) {
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
void func_level_40_800774A8(Moby* argument) {
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
void func_level_40_800779C8(Moby* moby) {
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
extern unsigned char Controller78288D_80066FD3[] __asm__("D_80066FCC+7");
extern unsigned char Controller78288D_80070300[] __asm__("D_80070300");
extern unsigned char Controller78288D_80071598 __asm__("D_80071598");
extern int Controller78288D_8006C5BC __asm__("D_8006C5BC");
extern int Controller78288D_8006C73C __asm__("D_8006C73C");
int Controller78288ActivateSparxPowers() __asm__("ActivateSparxPowers");
int Controller78288Helper584BC() __asm__("func_800584BC");
extern unsigned char Controller78288D_80071FB0[] __asm__("D_80071FB0");
extern int Controller78288D_8006C660 __asm__("D_8006C660");
extern int Controller78288D_8006C71C __asm__("D_8006C71C");
extern int Controller78288D_80065820 __asm__("D_80065820");
void func_level_40_80077CCC(void* input) {
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
        int originalExtra58[2];
    } frame;
    register int kind __asm__("$3");
    register int prefixKind3 __asm__("$3");
    register int three2 __asm__("$2");
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
    register int tagKind __asm__("$3");
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
                                three2 = 3;
                                MATCHING_KEEP_CLOBBER(three2, "$3");
                                prefixKind3 = Controller78288Field(prefixTag, unsigned char*, 0);
                                if (prefixKind3 == three2)
                                    goto checkPrefixFlags;
                                three2 = 12;
                                MATCHING_KEEP2(three2, prefixKind3);
                                if (prefixKind3 == three2) {
                                    three2 = 3;
                                    goto compareOriginalPrefix;
                                }

                    Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                        prefixKind3 = Controller78288Field(prefixTag, unsigned char*, 0);
                        three2 = 3;
                    compareOriginalPrefix:
                        if (prefixKind3 == three2) {
                        checkPrefixFlags:
                            {
                                register int raw3 __asm__("$3");
                                register int raw4 __asm__("$4");
                                register int raw2 __asm__("$2");
                                raw4 = Controller78288D_8006C5BC;
                                raw2 = Controller78288D_80070300[Controller78288D_80066FD3[raw4]];
                                MATCHING_KEEP2_CLOBBER(raw2, raw4, "$3");
                                raw3 = (int)Controller78288D_80066FD3;
                                MATCHING_KEEP2(raw3, raw4);
                                raw2 &= 1;
                                if (raw2 == 0)
                                    goto removeController;
                                raw2 = raw3 + raw4;
                                MATCHING_KEEP(raw2);
                                raw2 = Controller78288D_80070300[Controller78288Field(
                                           (void*)raw2, unsigned char*, -9)] &
                                       1;
                                if (raw2 == 0)
                                    goto removeController;
                            }
                        } else if (prefixKind3 == 12) {
                            if (Controller78288D_80071FB0[Controller78288D_80066FD3[0x2B]] != 0)
                                goto removeController;
                            if (!(Controller78288D_80070300[Controller78288D_80066FD3[0x28]] & 1))
                                goto removeController;
                            if ((Controller78288D_8006C660 >= 149) &&
                                (Controller78288D_8006C71C >= 15000))
                                goto removeController;
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            {
                                register int rawOne4 __asm__("$4") = 1;
                                register int rawKind3 __asm__("$3");
                                register int nine2 __asm__("$2");
                                MATCHING_KEEP_CLOBBER(rawOne4, "$3");
                                rawKind3 = Controller78288Field(prefixTag, unsigned char*, 0);
                                MATCHING_KEEP_CLOBBER(rawKind3, "$2");
                                nine2 = 3;
                                MATCHING_KEEP3(rawOne4, rawKind3, nine2);
                                Controller78288Field(prefixTag, unsigned char*, 5) = rawOne4;
                                if (rawKind3 == nine2) {
                                    if ((Controller78288D_8006C73C == 48) &&
                                        (Controller78288D_80071598 == 0))
                                        goto storeOriginalLowering;
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
                                        if (address)
                                            Controller78288Field(prefixTag, unsigned char*, 5) = 0;
                                    }
                                    goto storeOriginalLowering;
                                } else {
                                    nine2 = 12;
                                    MATCHING_KEEP2(nine2, rawKind3);
                                    if (rawKind3 == nine2)
                                        Controller78288Field(prefixTag, unsigned char*, 5) =
                                            rawOne4;
                                }
                            }
                        storeOriginalLowering:
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
                        removeController:
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
                            if ((Controller78288Field(prefixTag, unsigned char*, 0) == 12) &&
                                (Controller78288D_8006C71C >= 15000) &&
                                (Controller78288D_8006C660 >= 149)) {
                                Controller78288Field(tag, unsigned char*, 2) = 0;
                            }
                            if (Controller78288Helper37BBC(owner, 0xC) != 0) {
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 3) {
                                    if (Controller78288D_80070300[Controller78288D_80066FD3[0x29]] &
                                        1) {
                                        register unsigned char* flag3 __asm__("$3") =
                                            &Controller78288D_80071598;
                                        if (*flag3)
                                            Controller78288Field(prefixTag, unsigned char*, 2) = 1;
                                        else {
                                            Controller78288Field(prefixTag, unsigned char*, 2) = 2;
                                            *flag3 = 1;
                                            Controller78288ActivateSparxPowers();
                                        }
                                    } else
                                        Controller78288Field(prefixTag, unsigned char*, 2) = 0;
                                }
                                Controller78288Helper512E4(owner, 0, 0);
                                {
                                    register int diff __asm__("$4") = Controller78288D_8006C550;
                                    register int product __asm__("$3");
                                    register int bank __asm__("$2");
                                    register int address5 __asm__("$5");
                                    MATCHING_KEEP(diff);
                                    diff = (int)owner - diff;
                                    product = -(diff * 0x45D1745D);
                                    product >>= 3;
                                    MATCHING_KEEP_CLOBBER(product, "$2");
                                    bank = Controller78288D_8006C79C;
                                    MATCHING_KEEP_CLOBBER(bank, "$4");
                                    diff = (int)Controller78288D_80071AB0;
                                    product += bank;
                                    address5 = (product >> 5) * 4;
                                    MATCHING_KEEP3_CLOBBER(address5, product, diff, "$2");
                                    bank = Controller78288D_8006C58C;
                                    product &= 31;
                                    bank <<= 5;
                                    bank += diff;
                                    address5 += bank;
                                    bank = 1;
                                    diff = *(int*)address5;
                                    bank <<= product;
                                    diff |= bank;
                                    *(int*)address5 = diff;
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
                    if (Controller78288D_8006E344 == 1)
                        goto clearExtraHandle;
                    prefixKind3 = Controller78288Field(prefixTag, unsigned char*, 0);
                    if (prefixKind3 == 3) {
                        three2 = Controller78288Field(prefixTag, unsigned char*, 2);
                        if (three2 == prefixKind3)
                            Controller78288Helper584BC(4, Controller78288D_8006C5BC + 8);
                        goto storeOriginalTagOne;
                    }
                    if (prefixKind3 != 12)
                        goto setSubstateFour;
                    if ((Controller78288Field(prefixTag, unsigned char*, 4) == 0) &&
                        (Controller78288D_8006C71C < 15000)) {
                        if (Controller78288D_80065820 != 0) {
                            Controller78288Field(prefixTag, unsigned char*, 2) = 1;
                            goto storeOriginalTagOne;
                        }
                        Controller78288Field(prefixTag, unsigned char*, 2) = 2;
                    } else {
                        Controller78288Field(prefixTag, unsigned char*, 2) = 0;
                    }
                storeOriginalTagOne:
                    Controller78288Field(tag, unsigned char*, 2) = 1;
                    goto setSubstateFour;

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
void func_level_40_80078B20(Moby* moby) {
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
void func_level_40_80078F50(Moby* moby) {
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
void func_level_40_800792B8(Moby* owner) {
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
    unsigned char reserved00, gateIndex, phase, reserved03[2], active;
    unsigned char reserved06[0x22];
    int linkedIndex, tollIndex, targetIndex;
} DecodedDialogueGateTag;
extern short DecodedDialogueGateThreshold[] __asm__("D_80066EAC");
extern short DecodedDialogueGatePaid[] __asm__("D_80066EAE");
extern unsigned char DecodedDialogueGateLevel __asm__("D_80066FCC + 0x2F");
extern unsigned char DecodedDialogueGateLevelFlags[] __asm__("D_80070300");
extern int D_8006C71C, D_8006C640, D_8006E344;
extern unsigned char D_80071584;
extern Moby* D_8006C550;
void DecodedDialogueGateTarget(int, int, int) __asm__("func_80021ED8");
int DecodedDialogueGateQuery(Moby*, int) __asm__("func_80037BBC");
void DecodedDialogueGateBegin(Moby*, int, int) __asm__("func_800512E4");
void func_level_40_80079444(Moby* moby) {
    DecodedDialogueGateTag* tag = moby->mobyTag;
    int gate, targetIndex;
    switch (moby->state) {
        case 0:
            gate = tag->gateIndex & 0x7F;
            if (gate != 0x7F && D_8006C71C >= DecodedDialogueGateThreshold[gate * 2] &&
                !DecodedDialogueGatePaid[gate * 2]) {
                tag->active = 1;
                tag->gateIndex = 0xFF;
            }
            if (tag->tollIndex != -1 && D_8006C640 < 10) {
                if (DecodedDialogueGatePaid[tag->tollIndex * 2] ||
                    (DecodedDialogueGateLevelFlags[DecodedDialogueGateLevel] & 1)) {
                    if (tag->linkedIndex != -1)
                        ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))
                            ->state = 9;
                    if (tag->targetIndex != -1)
                        DecodedDialogueGateTarget(tag->targetIndex, 0xFC, 0);
                    func_80055B18(moby);
                    break;
                }
            }
            if ((tag->linkedIndex != -1 || tag->targetIndex != -1) && tag->phase == 4) {
                if (tag->linkedIndex != -1)
                    ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))->state =
                        9;
                targetIndex = tag->targetIndex;
                tag->linkedIndex = -1;
                if (targetIndex != -1)
                    DecodedDialogueGateTarget(targetIndex, 0xFC, 0);
                tag->targetIndex = -1;
            }
            if (DecodedDialogueGateQuery(moby, 0)) {
                DecodedDialogueGateBegin(moby, 0, 1);
                moby->state = 1;
            }
            break;
        case 1:
            D_80071584 = 1;
            if (D_8006E344 != 1) {
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
    }
}

typedef struct {
    unsigned char reserved00[2], mode, reserved03[2], disabled, reserved06, status;
    unsigned char reserved08[0x18];
    int pendingState, actorIndex;
} DecodedInteractionGate;
extern Moby* D_8006C550;
extern int D_8006E53C, D_8006E344;
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
void func_level_40_80079684(Moby* actor) {
    DecodedInteractionGate* tag = actor->mobyTag;
    unsigned short actorClass;
    if (actor->mobyClass == 0x145 && tag->actorIndex != -1 &&
        D_8006C550[tag->actorIndex].state < 0x80)
        tag->disabled = 0xFF;
    actorClass = actor->mobyClass;
    if ((unsigned int)(actorClass - 0x2AB) < 2 || (short)actorClass == 0x198 ||
        (short)actorClass == 0x2AD)
        tag->disabled = 0xFF;
    switch (actor->state) {
        case 0:
            if (tag->mode == 2)
                tag->disabled = 0;
            if (!tag->disabled) {
                if (D_8006E53C & 0x10) {
                    if (func_80037BBC(actor, 0))
                        goto activate;
                    tag->status = 0;
                }
            }
            if (tag->disabled) {
                if (func_80037BBC(actor, 0)) {
                activate:
                    func_800512E4(actor, 0, 0);
                    actor->state = 1;
                } else
                    tag->status = 0;
            }
            break;
        case 1:
            if (D_8006E344 != actor->state) {
                tag->pendingState = actor->state;
                actor->state = 0;
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80079810.
 * AI generated; not human reviewed. All906 native and linked words,9 actual
 * selectors,one zero pad,every transfer/data target,EXE/every overlay hash
 * must match:916 owned words. Original frame80hex=128 bytes saves S0..S7/
 * FP/RA at SP58..7C. Vector homes18..20,28..30,38..40,48..50 retain widths;
 * unwritten frame gaps are not read. Natural S0 and FP retain original roles.
 * The ordinary current history address starts after its byte offset's last
 * use. No fixed FP/SP,undefined saved input or overlapping live aliases.
 * Verified852-family reuse keeps only independently present instructions.
 * Level40 private route/timer/vector offsets28/30/34/40,angle table60,
 * descriptors64/70,resources6C/78,history7C,geometry1FC,color4FC and topology
 * 57C are original. They are raw byte addresses,not inferred domain scales.
 * Mode field24 selects completion bytes71594/7159B. Original private58
 * indexes an88-byte actor record and writes byte48=9 only when nonnegative.
 * Original6C660 threshold100 and distinct initial-mode entries are retained.
 * Original state2/state3 omit852's C74C=1 stores and use the exact history7C
 * reset. State3 S1=0 stays in the original conditional delay slot; its later
 * initialized identity prevents substituting that known zero for retailZERO.
 * Six MULT sites use complete signed64 C products. /6 uses2AAAAAAB high/sign;
 * /30 uses88888889 high+numerator,SRA4/sign. Trig uses original LH,SRA4 before
 * MULT,and narrowed low32 SRA12 afterward. Vectors:11%6=5;30<<8=7680,/30=256;
 * (-32768>>4)*32767=-67106816 and signed low32 SRA12=-16384.
 * No incoming A2 is read: original4F178 consumes onlyA0/A1. All metadata
 * inputs are complete initialized values/addresses/products or words already
 * written by the preceding original helper;dead clobbers precede fresh values.
 * Empty metadata emits zero CPU instructions. No opcode asm or partial HILO.
 * Confidence is binary identity after all gates. Units/fixed point,full
 * helper/caller/consumer chains,cadence beyond invocation and synchronized
 * retail runtime remain open. Compiler/filter/flags and engine/browser stay
 * unchanged. Next evidence:human review and synchronized retail captures.
 */
/* Original assembly SHA256 ca3f21b4a135a5457f94fb9f885401785f9141d1e7fb2f88ec99df695c3211dc */
#define Level40_79810Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level40_79810MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level40_79810CaptureHigh(dst)                                       \
    do {                                                                    \
        int wholeCapturedHigh;                                              \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedHigh;                                          \
        Level40_79810Keep(dst);                                             \
    } while (0)
#define Level40_79810CaptureLow(dst)                                       \
    do {                                                                   \
        int wholeCapturedLow;                                              \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedLow;                                          \
        Level40_79810Keep(dst);                                            \
    } while (0)
#define Level40_79810Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level40_79810Call136F0View1(void*, int, int) __asm__("func_800136F0");
int Level40_79810CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level40_79810Call36220View1(void*, void*, int, int) __asm__("func_80036220");
void Level40_79810Call37014View1(void*) __asm__("func_80037014");
int Level40_79810Call37BBCView1(void*, int) __asm__("func_80037BBC");
int Level40_79810PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
void Level40_79810Call492DCView1(void*) __asm__("func_800492DC");
int Level40_79810PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level40_79810TransformVectorByBasisView1(void*, int, int) __asm__("func_8004ED6C");
void Level40_79810ClearVectorView1(void*) __asm__("func_8004F168");
void Level40_79810CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level40_79810AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level40_79810SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level40_79810AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
void* Level40_79810Call50B00View1(int, int, int, int, int) __asm__("func_80050B00");
void Level40_79810Call50B88View1(void*) __asm__("func_80050B88");
void Level40_79810Call512E4View1(void*, int, int) __asm__("func_800512E4");
void Level40_79810DeleteMobyView1(void*) __asm__("func_80055B18");
void Level40_79810RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
extern unsigned char Level40_79810Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level40_79810Data65920View1[] __asm__("D_80065920");
extern int Level40_79810Data6C574View1 __asm__("D_8006C574");
extern int Level40_79810Data6C578View1 __asm__("D_8006C578");
extern int Level40_79810Data6C74CView1 __asm__("D_8006C74C");
extern int Level40_79810Data6C7C0View1 __asm__("D_8006C7C0");
extern int Level40_79810Data6E020View1 __asm__("D_8006E020");
extern int Level40_79810Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level40_79810Data6E040View1 __asm__("D_8006E040");
extern int Level40_79810Data6E160View1 __asm__("D_8006E160");
extern int Level40_79810Data6E174View1 __asm__("D_8006E174");
extern int Level40_79810Data6E178View1 __asm__("D_8006E178");
extern int Level40_79810Data6E17CView1 __asm__("D_8006E17C");
extern int Level40_79810Data6E344View1 __asm__("D_8006E344");
extern int Level40_79810Data70328View1 __asm__("D_80070328");
extern unsigned char Level40_79810Data7157FView1 __asm__("D_8007157F");
extern int (*Level40_79810DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Level40_79810Data74330View1)() __asm__("unk_ovlheader_80074330");
extern int (*Level40_79810Data743ECView1)() __asm__("unk_ovlheader_800743EC");
extern int Level40_79810Data6C550View1 __asm__("D_8006C550");
extern int Level40_79810Data6C660View1 __asm__("D_8006C660");
extern unsigned char Level40_79810Data71594View1 __asm__("D_80071594");
extern unsigned char Level40_79810Data7159BView1 __asm__("D_8007159B");
void func_level_40_80079810(unsigned char* ownerParameter) {
    register int naturalCountRecordOrOffset16, angleCreatedOrSourceOffset17 __asm__("$17"),
        recordOrHistoryCount18 __asm__("$18"), privateRecord19 __asm__("$19"),
        ownerThenGeometryOffset20 __asm__("$20"), emittedVertexCount21 __asm__("$21"),
        retainedAngle22 __asm__("$22"), vectorAddress23 __asm__("$23");
    register int resultOrField2 __asm__("$2"), fieldHighOrAddress3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7"),
        capturedHighOrLow8 __asm__("$8");
    int retainedOriginalTableBase;
    int currentHistoryPositionAddress;
    long long completeSignedProduct;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54;
    } originalFrame;
    int temp_a0_6;
    int temp_a0_7;
    int temp_a1_3;
    int temp_v1;
    int temp_v1_10;
    int temp_v0_11;
    int temp_v0_17;
    int temp_v1_6;
    ownerThenGeometryOffset20 = (int)ownerParameter;
    Level40_79810Keep(ownerThenGeometryOffset20);
    temp_v1 = Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    privateRecord19 = Level40_79810Field(ownerThenGeometryOffset20, int*, 0x0);
    switch (temp_v1) {
        case 0:
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x24);
            fieldHighOrAddress3 = 0;
            if (resultOrField2 == 0) {
                resultOrField2 = Level40_79810Data71594View1;
                fieldHighOrAddress3 = 1;
                if (resultOrField2)
                    goto deleteOriginalModeActor;
            } else {
                resultOrField2 = Level40_79810Data7159BView1;
                if (resultOrField2) {
                    fieldHighOrAddress3 = Level40_79810Field(privateRecord19, int*, 0x58);
                    if (fieldHighOrAddress3 >= 0) {
                        resultOrField2 = fieldHighOrAddress3 * 88;
                        fieldHighOrAddress3 = Level40_79810Data6C550View1;
                        resultOrField2 += fieldHighOrAddress3;
                        fieldHighOrAddress3 = 9;
                        Level40_79810Field(resultOrField2, unsigned char*, 0x48) =
                            fieldHighOrAddress3;
                    }
                deleteOriginalModeActor:
                    Level40_79810DeleteMobyView1(ownerThenGeometryOffset20);
                    return;
                }
                resultOrField2 = Level40_79810Data6C660View1;
                resultOrField2 = resultOrField2 < 100;
                if (resultOrField2) {
                    resultOrField2 = 255;
                    goto originalModeFields;
                }
                resultOrField2 = 1;
                Level40_79810Field(privateRecord19, unsigned char*, 2) = resultOrField2;
                fieldHighOrAddress3 = 1;
            }
            MATCHING_BARRIER_VOLATILE("$2");
            resultOrField2 = 255;
        originalModeFields:
            Level40_79810Keep(resultOrField2);
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x41) = 0;
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x4c) = 0;
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x4d) = 0;
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x4a) = resultOrField2;
            if (fieldHighOrAddress3) {
                naturalCountRecordOrOffset16 = 0;
                do {
                    Level40_79810Keep(naturalCountRecordOrOffset16);
                    angleCreatedOrSourceOffset17 = naturalCountRecordOrOffset16 * 2;
                    Level40_79810Keep(angleCreatedOrSourceOffset17);
                    argumentOrField4 = angleCreatedOrSourceOffset17 + naturalCountRecordOrOffset16;
                    argumentOrField4 *= 4;
                    argumentOrField4 += 0x7C;
                    argumentOrField4 = privateRecord19 + argumentOrField4;
                    argumentOrField5 = ownerThenGeometryOffset20 + 12;
                    Level40_79810CopyVectorView1(argumentOrField4, argumentOrField5);
                    resultOrField2 = naturalCountRecordOrOffset16 << 8;
                    resultOrField2 /= 32;
                    fieldHighOrAddress3 = 256;
                    argumentOrField6 = fieldHighOrAddress3 - resultOrField2;
                    resultOrField2 = argumentOrField6 < 256;
                    argumentOrField4 = naturalCountRecordOrOffset16 * 4;
                    if (!resultOrField2)
                        argumentOrField6 = 255;
                    fieldHighOrAddress3 = naturalCountRecordOrOffset16 * 8;
                    argumentOrField5 = naturalCountRecordOrOffset16;
                    Level40_79810Keep(argumentOrField5);
                    resultOrField2 = naturalCountRecordOrOffset16 + 1;
                    __asm__(""
                            : "=r"(resultOrField2)
                            : "0"(resultOrField2), "r"(argumentOrField4), "r"(fieldHighOrAddress3),
                              "r"(argumentOrField5));
                    naturalCountRecordOrOffset16 = resultOrField2;
                    Level40_79810Keep(naturalCountRecordOrOffset16);
                    argumentOrField4 = privateRecord19 + argumentOrField4;
                    fieldHighOrAddress3 = privateRecord19 + fieldHighOrAddress3;
                    resultOrField2 = angleCreatedOrSourceOffset17 + 2;
                    Level40_79810Field(argumentOrField4, unsigned char*, 0x4fc) = argumentOrField6;
                    Level40_79810Field(argumentOrField4, unsigned char*, 0x4fd) = argumentOrField6;
                    Level40_79810Field(argumentOrField4, unsigned char*, 0x4fe) = argumentOrField6;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x57d) = resultOrField2;
                    resultOrField2 = angleCreatedOrSourceOffset17 + 1;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x57e) = resultOrField2;
                    resultOrField2 = angleCreatedOrSourceOffset17 + 3;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x57f) = resultOrField2;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x57c) =
                        angleCreatedOrSourceOffset17;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x580) =
                        argumentOrField5;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x581) =
                        naturalCountRecordOrOffset16;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x582) =
                        argumentOrField5;
                    Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x583) =
                        naturalCountRecordOrOffset16;
                } while (naturalCountRecordOrOffset16 < 32);
                resultOrField2 = naturalCountRecordOrOffset16 * 8;
                resultOrField2 += privateRecord19;
                fieldHighOrAddress3 = -1;
                Level40_79810Field(resultOrField2, int*, 0x574) = fieldHighOrAddress3;
                resultOrField2 = Level40_79810Field(privateRecord19, unsigned short*, 0x76);
                resultOrField2 &= 0xFF9F;
                resultOrField2 |= 0x40;
                Level40_79810Field(privateRecord19, short*, 0x76) = resultOrField2;
                resultOrField2 = 1;
                Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) =
                    resultOrField2;
            }
            goto block_80;
        default:
            goto block_80;
        case 1:
            Level40_79810CopyVectorView1(&originalFrame.sp18, &Level40_79810Data70328View1);
            originalFrame.sp20 -= Level40_79810Field(&Level40_79810Data70328View1, int*, 0x44);
            if (Level40_79810Call36220View1(&originalFrame.sp18, privateRecord19 + 0x40, 0, 0) !=
                0) {
                if (Level40_79810Field(&Level40_79810Data70328View1, int*, 0xb8) == 0) {
                    resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    argumentOrField6 = Level40_79810Field(resultOrField2, short*, 0x0);
                    resultOrField2 = Level40_79810Field(resultOrField2, int*, 0xc);
                    argumentOrField6 *= 16;
                    argumentOrField5 = argumentOrField6 - 16;
                    argumentOrField5 = resultOrField2 + argumentOrField5;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level40_79810SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
                    argumentOrField4 = originalFrame.sp18;
                    argumentOrField5 = originalFrame.sp1C;
                    argumentOrField6 = 0;
                    resultOrField2 = Level40_79810PlanarHeadingLookupView1(
                        argumentOrField4, argumentOrField5, argumentOrField6);
                    naturalCountRecordOrOffset16 = resultOrField2;
                    Level40_79810Keep(naturalCountRecordOrOffset16);
                    argumentOrField4 = naturalCountRecordOrOffset16 * 2;
                    fieldHighOrAddress3 =
                        Level40_79810Field(&Level40_79810Data65920View1, short*, argumentOrField4);
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp18 = resultOrField2;
                    fieldHighOrAddress3 =
                        Level40_79810Field(&Level40_79810Data658A0View1, short*, argumentOrField4);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    originalFrame.sp20 = 0;
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp1C = resultOrField2;
                    resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
                    argumentOrField5 = argumentOrField4;
                    argumentOrField6 = Level40_79810Field(resultOrField2, short*, 0x0);
                    resultOrField2 = Level40_79810Field(resultOrField2, int*, 0xc);
                    argumentOrField6 *= 16;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level40_79810AddVectorView1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    __asm__(""
                            : "=r"(argumentOrField4)
                            : "0"(argumentOrField4), "m"(originalFrame.sp18));
                    argumentOrField5 = naturalCountRecordOrOffset16 + 128;
                    argumentOrField6 = 0;
                    Level40_79810Data74330View1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    Level40_79810Field(privateRecord19, signed char*, 0x5) = 1;
                    Level40_79810Field(Level40_79810Field(privateRecord19, int*, 0x28), short*, 2) =
                        1;
                    Level40_79810CopyVectorView1(
                        &Level40_79810Data6E17CView1,
                        Level40_79810Field(Level40_79810Field(privateRecord19, int*, 0x2c), int*,
                                           0xC) +
                            0x10);
                    temp_a1_3 = Level40_79810Field(Level40_79810Field(privateRecord19, int*, 0x2c),
                                                   int*, 0xC);
                    Level40_79810Call136F0View1((int)&Level40_79810Data6E17CView1 - 0x14, temp_a1_3,
                                                temp_a1_3 + 0x10);
                    Level40_79810Data6E160View1 = 0x11;
                    Level40_79810Data6C74CView1 = 1;
                    Level40_79810Data6E174View1 = 0;
                    Level40_79810Data6E178View1 = 0;
                    Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 2U;
                } else {
                    Level40_79810Field(&Level40_79810Data70328View1, int*, 0x20c) = 0x10000082;
                    Level40_79810Field(&Level40_79810Data70328View1, int*, 0x23c) = 0x12;
                }
            }
            goto block_80;
        case 2:
            if (Level40_79810Call36220View1(&Level40_79810Data70328View1, privateRecord19 + 0x40, 0,
                                            0) != 0) {
                naturalCountRecordOrOffset16 = (int)&originalFrame.sp28;
                resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
                argumentOrField4 = naturalCountRecordOrOffset16;
                argumentOrField6 = Level40_79810Field(resultOrField2, short*, 0x0);
                resultOrField2 = Level40_79810Field(resultOrField2, int*, 0xc);
                argumentOrField6 *= 16;
                argumentOrField5 = argumentOrField6 - 16;
                argumentOrField5 = resultOrField2 + argumentOrField5;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level40_79810SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                 argumentOrField6);
                argumentOrField4 = originalFrame.sp28;
                argumentOrField5 = originalFrame.sp2C;
                argumentOrField6 = 0;
                resultOrField2 = Level40_79810PlanarHeadingLookupView1(
                    argumentOrField4, argumentOrField5, argumentOrField6);
                angleCreatedOrSourceOffset17 = resultOrField2;
                Level40_79810Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
                fieldHighOrAddress3 =
                    Level40_79810Field(&Level40_79810Data65920View1, short*, argumentOrField4);
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp28 = resultOrField2;
                fieldHighOrAddress3 =
                    Level40_79810Field(&Level40_79810Data658A0View1, short*, argumentOrField4);
                argumentOrField5 = naturalCountRecordOrOffset16;
                originalFrame.sp30 = 0;
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp2C = resultOrField2;
                resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
                __asm__(""
                        : "=r"(naturalCountRecordOrOffset16)
                        : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
                argumentOrField4 = naturalCountRecordOrOffset16;
                argumentOrField6 = Level40_79810Field(resultOrField2, short*, 0x0);
                resultOrField2 = Level40_79810Field(resultOrField2, int*, 0xc);
                argumentOrField6 *= 16;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level40_79810AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
                argumentOrField4 = naturalCountRecordOrOffset16;
                __asm__(""
                        : "=r"(argumentOrField4)
                        : "0"(argumentOrField4), "m"(originalFrame.sp28));
                argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
                argumentOrField6 = 0;
                Level40_79810Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
                Level40_79810Field(privateRecord19, signed char*, 0x5) = 1;
                Level40_79810Call492DCView1(ownerThenGeometryOffset20 + 0xC);
                if (Level40_79810AbsoluteByteAngleDeltaView1(
                        (int)(Level40_79810Data6E040View1 << 0x10) >> 0x14,
                        Level40_79810PlanarHeadingLookupView1(
                            Level40_79810Field(ownerThenGeometryOffset20, int*, 0xc) -
                                Level40_79810Data6E020View1,
                            Level40_79810Field(ownerThenGeometryOffset20, int*, 0x10) -
                                Level40_79810Data6E024View1,
                            0)) < 0x18) {
                    Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 3U;
                }
            } else {
                goto restoreOriginalStateOne;
            }
            goto block_80;
        case 4:
            Level40_79810PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x41) = 1;
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x4c) = 0x10;
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x4d) = 1;
            Level40_79810Call37014View1(ownerThenGeometryOffset20);
            argumentOrField6 = 0;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$18");
            recordOrHistoryCount18 = 0;
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x44) = 0U;
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x45) = 0;
            temp_v1_6 = Level40_79810Field(privateRecord19, int*, 0x28);
            temp_v0_11 = (Level40_79810Field(temp_v1_6, short*, 0x2) * 0x10) +
                         Level40_79810Field(temp_v1_6, int*, 0xc);
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x46) =
                Level40_79810PlanarHeadingLookupView1(
                    Level40_79810Field(temp_v0_11, int*, 0x0) -
                        Level40_79810Field(ownerThenGeometryOffset20, int*, 0xc),
                    Level40_79810Field(temp_v0_11, int*, 0x4) -
                        Level40_79810Field(ownerThenGeometryOffset20, int*, 0x10),
                    argumentOrField6);
        emitOriginalFirstSix:
            resultOrField2 = Level40_79810Data6C578View1;
            fieldHighOrAddress3 = Level40_79810Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone4;
            angleCreatedOrSourceOffset17 =
                Level40_79810DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalFirstSix;
        originalSixDone4:
            recordOrHistoryCount18 = 0;
        emitOriginalFirstTwelve:
            resultOrField2 = Level40_79810Data6C578View1;
            fieldHighOrAddress3 = Level40_79810Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone4;
            angleCreatedOrSourceOffset17 =
                Level40_79810DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level40_79810Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext4;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x60);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level40_79810Field(resultOrField2, unsigned char*, 0x0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x60);
            naturalCountRecordOrOffset16 =
                Level40_79810Field(angleCreatedOrSourceOffset17, int*, 0x0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x1);
            argumentOrField5 = 4;
            Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level40_79810RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level40_79810Field(naturalCountRecordOrOffset16, int*, 0xc) = resultOrField2;
            Level40_79810Field(naturalCountRecordOrOffset16, int*, 0x10) = 0;
            Level40_79810Field(naturalCountRecordOrOffset16, int*, 0x14) = 0;
            Level40_79810TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level40_79810Keep(resultOrField2);
            Level40_79810MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level40_79810Field(angleCreatedOrSourceOffset17, int*, 0x14);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level40_79810Field(angleCreatedOrSourceOffset17, int*, 0x14) = resultOrField2;
            Level40_79810CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext4:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalFirstTwelve;
        originalTwelveDone4:
            Level40_79810Field(privateRecord19, int*, 0x30) = 0x1E;
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 5U;
        case 5:
            if (Level40_79810CountTimerDownView1(privateRecord19 + 0x30, 4) != 0) {
                Level40_79810Data6E160View1 = 0;
                Level40_79810Field(privateRecord19, signed char*, 0x5) = 2;
                Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 6U;
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x30);
            resultOrField2 <<= 8;
            Level40_79810Keep(resultOrField2);
            Level40_79810MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level40_79810CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level40_79810Data6C7C0View1 = fieldHighOrAddress3;
        case 3:
            resultOrField2 = Level40_79810Call36220View1(&Level40_79810Data70328View1,
                                                         privateRecord19 + 0x40, 0, 0);
            angleCreatedOrSourceOffset17 = 0;
            if (resultOrField2 == 0) {
                Level40_79810Keep(angleCreatedOrSourceOffset17);
                resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
                __asm__ volatile("" ::: "$4", "memory");
                argumentOrField4 = ownerThenGeometryOffset20 + 12;
                MATCHING_OBSERVE_VOLATILE(argumentOrField4);
                Level40_79810Field(resultOrField2, short*, 0x2) = 0;
                resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
                argumentOrField5 = Level40_79810Field(resultOrField2, int*, 0xc);
                naturalCountRecordOrOffset16 = 124;
                Level40_79810CopyVectorView1(argumentOrField4, argumentOrField5);
                Level40_79810ClearVectorView1(privateRecord19 + 0x34);
                Level40_79810Field(privateRecord19, int*, 0x30) = 0;
                do {
                    Level40_79810CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                                 ownerThenGeometryOffset20 + 0xC);
                    angleCreatedOrSourceOffset17 += 1;
                    naturalCountRecordOrOffset16 += 0xC;
                } while (angleCreatedOrSourceOffset17 < 0x20);
            restoreOriginalStateOne:
                resultOrField2 = 1;
                Level40_79810Data6E160View1 = 0;
                Level40_79810Data6C74CView1 = 0;
                Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) =
                    resultOrField2;
                goto block_80;
            }
            naturalCountRecordOrOffset16 = (int)&originalFrame.sp38;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
            argumentOrField4 = naturalCountRecordOrOffset16;
            argumentOrField6 = Level40_79810Field(resultOrField2, short*, 0x0);
            resultOrField2 = Level40_79810Field(resultOrField2, int*, 0xc);
            argumentOrField6 *= 16;
            argumentOrField5 = argumentOrField6 - 16;
            argumentOrField5 = resultOrField2 + argumentOrField5;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level40_79810SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = originalFrame.sp38;
            argumentOrField5 = originalFrame.sp3C;
            argumentOrField6 = 0;
            resultOrField2 = Level40_79810PlanarHeadingLookupView1(
                argumentOrField4, argumentOrField5, argumentOrField6);
            angleCreatedOrSourceOffset17 = resultOrField2;
            Level40_79810Keep(angleCreatedOrSourceOffset17);
            argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
            fieldHighOrAddress3 =
                Level40_79810Field(&Level40_79810Data65920View1, short*, argumentOrField4);
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp38 = resultOrField2;
            fieldHighOrAddress3 =
                Level40_79810Field(&Level40_79810Data658A0View1, short*, argumentOrField4);
            argumentOrField5 = naturalCountRecordOrOffset16;
            originalFrame.sp40 = 0;
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp3C = resultOrField2;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x28);
            __asm__(""
                    : "=r"(naturalCountRecordOrOffset16)
                    : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
            argumentOrField4 = naturalCountRecordOrOffset16;
            argumentOrField6 = Level40_79810Field(resultOrField2, short*, 0x0);
            resultOrField2 = Level40_79810Field(resultOrField2, int*, 0xc);
            argumentOrField6 *= 16;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level40_79810AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = naturalCountRecordOrOffset16;
            __asm__("" : "=r"(argumentOrField4) : "0"(argumentOrField4), "m"(originalFrame.sp38));
            argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
            argumentOrField6 = 0;
            Level40_79810Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level40_79810Call492DCView1(ownerThenGeometryOffset20 + 0xC);
            if (Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) == 3) {
                temp_v0_17 = Level40_79810Field(privateRecord19, int*, 0x28);
                if (Level40_79810Field(temp_v0_17, short*, 0x2) ==
                    (Level40_79810Field(temp_v0_17, short*, 0x0) - 1)) {
                    Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 4U;
                } else {
                    Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x44) =
                        (unsigned char)(Level40_79810Field(ownerThenGeometryOffset20,
                                                           unsigned char*, 0x44) +
                                        4);
                    naturalCountRecordOrOffset16 = Level40_79810Field(
                        Level40_79810Field(privateRecord19, int*, 0x28), short*, 2);
                    Level40_79810Keep(naturalCountRecordOrOffset16);
                    Level40_79810Data743ECView1(
                        ownerThenGeometryOffset20, Level40_79810Field(privateRecord19, int*, 0x28),
                        privateRecord19 + 0x34, privateRecord19 + 0x30, 8, 0);
                    fieldHighOrAddress3 = Level40_79810Field(privateRecord19, int*, 0x28);
                    Level40_79810Keep(fieldHighOrAddress3);
                    if (Level40_79810Field(fieldHighOrAddress3, short*, 0x2) !=
                        naturalCountRecordOrOffset16) {
                        resultOrField2 = Level40_79810Field(fieldHighOrAddress3, int*, 0xc);
                        fieldHighOrAddress3 = naturalCountRecordOrOffset16 * 16;
                        Level40_79810Keep(fieldHighOrAddress3);
                        fieldHighOrAddress3 += resultOrField2;
                        resultOrField2 = Level40_79810Field(fieldHighOrAddress3, int*, 0xc);
                        if (resultOrField2) {
                            Level40_79810PlayMobySoundEventView1(ownerThenGeometryOffset20, 1, 0);
                        }
                    }
                }
            }
            goto block_80;
        case 6:
            temp_v1_10 = Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x48);
            switch (temp_v1_10) {
                case 0:
                    if (Level40_79810Call37BBCView1(ownerThenGeometryOffset20, 0) != 0) {
                        resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x24);
                        if (resultOrField2 == 0) {
                            Level40_79810Data71594View1 = 1;
                        } else {
                            Level40_79810Data7159BView1 = 1;
                        }
                        Level40_79810Call512E4View1(ownerThenGeometryOffset20, 0, 1);
                        Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x48) = 1U;
                    }
                    break;
                case 1:
                    if (Level40_79810Data6E344View1 != temp_v1_10) {
                        fieldHighOrAddress3 = Level40_79810Field(privateRecord19, int*, 0x58);
                        if (fieldHighOrAddress3 >= 0) {
                            resultOrField2 = fieldHighOrAddress3 * 88;
                            fieldHighOrAddress3 = Level40_79810Data6C550View1;
                            resultOrField2 += fieldHighOrAddress3;
                            fieldHighOrAddress3 = 9;
                            Level40_79810Field(resultOrField2, unsigned char*, 0x48) =
                                fieldHighOrAddress3;
                        }
                        Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 7U;
                    }
                    break;
            }
            goto block_80;
        case 7:
            Level40_79810PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            recordOrHistoryCount18 = 0;
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x41) = 0;
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x4c) = 0;
            Level40_79810Field(ownerThenGeometryOffset20, signed char*, 0x4d) = 0;
        emitOriginalSecondSix:
            resultOrField2 = Level40_79810Data6C578View1;
            fieldHighOrAddress3 = Level40_79810Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone7;
            angleCreatedOrSourceOffset17 =
                Level40_79810DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalSecondSix;
        originalSixDone7:
            recordOrHistoryCount18 = 0;
        emitOriginalSecondTwelve:
            resultOrField2 = Level40_79810Data6C578View1;
            fieldHighOrAddress3 = Level40_79810Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone7;
            angleCreatedOrSourceOffset17 =
                Level40_79810DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level40_79810Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext7;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x60);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level40_79810Field(resultOrField2, unsigned char*, 0x0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x60);
            naturalCountRecordOrOffset16 =
                Level40_79810Field(angleCreatedOrSourceOffset17, int*, 0x0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level40_79810Field(fieldHighOrAddress3, unsigned char*, 0x1);
            argumentOrField5 = 4;
            Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level40_79810RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level40_79810Field(naturalCountRecordOrOffset16, int*, 0xc) = resultOrField2;
            Level40_79810Field(naturalCountRecordOrOffset16, int*, 0x10) = 0;
            Level40_79810Field(naturalCountRecordOrOffset16, int*, 0x14) = 0;
            Level40_79810TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level40_79810Keep(resultOrField2);
            Level40_79810MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level40_79810Field(angleCreatedOrSourceOffset17, int*, 0x14);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level40_79810Field(angleCreatedOrSourceOffset17, int*, 0x14) = resultOrField2;
            Level40_79810CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level40_79810Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext7:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalSecondTwelve;
        originalTwelveDone7:
            temp_a0_6 = Level40_79810Field(privateRecord19, int*, 0x6c);
            if (temp_a0_6 != 0) {
                Level40_79810Call50B88View1(temp_a0_6);
            }
            temp_a0_7 = Level40_79810Field(privateRecord19, int*, 0x78);
            if (temp_a0_7 != 0) {
                Level40_79810Call50B88View1(temp_a0_7);
            }
            Level40_79810Field(privateRecord19, int*, 0x30) = 0x1E;
            Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 8U;
        case 8:
            if (Level40_79810CountTimerDownView1(privateRecord19 + 0x30, 4) != 0) {
                Level40_79810DeleteMobyView1(ownerThenGeometryOffset20);
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x30);
            resultOrField2 <<= 8;
            Level40_79810Keep(resultOrField2);
            Level40_79810MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level40_79810CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level40_79810Data6C7C0View1 = fieldHighOrAddress3;
            goto block_80;
    }
block_80:
    resultOrField2 = Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 -= 3;
    recordOrHistoryCount18 = 31;
    if ((unsigned int)resultOrField2 >= 4U)
        return;
    angleCreatedOrSourceOffset17 = 0x1E4;
    naturalCountRecordOrOffset16 = 0x1F0;
    do {
        Level40_79810CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                     privateRecord19 + angleCreatedOrSourceOffset17);
        angleCreatedOrSourceOffset17 -= 12;
        recordOrHistoryCount18--;
        naturalCountRecordOrOffset16 -= 12;
    } while (recordOrHistoryCount18 > 0);
    Level40_79810CopyVectorView1(privateRecord19 + 0x7c, ownerThenGeometryOffset20 + 12);
    fieldHighOrAddress3 = Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 = 3;
    if (fieldHighOrAddress3 != resultOrField2) {
        resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x84);
        resultOrField2 -= 1024;
        Level40_79810Field(privateRecord19, int*, 0x84) = resultOrField2;
    }
    resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x78);
    argumentOrField4 = privateRecord19 + 0x1fc;
    if (!resultOrField2) {
        resultOrField2 =
            Level40_79810Call50B00View1(argumentOrField4, privateRecord19 + 0x4fc,
                                        privateRecord19 + 0x57c, privateRecord19 + 0x70, 1);
        Level40_79810Field(privateRecord19, int*, 0x78) = resultOrField2;
        __asm__("" : "=r"(privateRecord19) : "0"(privateRecord19), "r"(resultOrField2));
    }
    resultOrField2 = Level40_79810Field(privateRecord19, int*, 0x6c);
    emittedVertexCount21 = 0;
    if (!resultOrField2) {
        Level40_79810Keep(emittedVertexCount21);
        resultOrField2 =
            Level40_79810Call50B00View1(privateRecord19 + 0x1fc, privateRecord19 + 0x4fc,
                                        privateRecord19 + 0x57c, privateRecord19 + 0x64, 1);
        Level40_79810Field(privateRecord19, int*, 0x6c) = resultOrField2;
        __asm__ volatile(""
                         : "=r"(emittedVertexCount21)
                         : "0"(emittedVertexCount21), "r"(resultOrField2));
        emittedVertexCount21 = 0;
    }
    recordOrHistoryCount18 = 0;
    retainedOriginalTableBase = (int)&Level40_79810Data658A0View1;
    vectorAddress23 = (int)&originalFrame.sp48;
    resultOrField2 = Level40_79810Field(ownerThenGeometryOffset20, unsigned char*, 0x44);
    ownerThenGeometryOffset20 = 0x1FC;
    resultOrField2 += 64;
    retainedAngle22 = resultOrField2 & 255;
    do {
        argumentOrField6 = 0;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$16");
        naturalCountRecordOrOffset16 = recordOrHistoryCount18 * 2;
        Level40_79810Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 += recordOrHistoryCount18;
        Level40_79810Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 *= 4;
        fieldHighOrAddress3 = privateRecord19 + naturalCountRecordOrOffset16;
        angleCreatedOrSourceOffset17 = recordOrHistoryCount18 + 1;
        resultOrField2 = angleCreatedOrSourceOffset17 * 12;
        resultOrField2 = privateRecord19 + resultOrField2;
        argumentOrField7 = Level40_79810Field(fieldHighOrAddress3, int*, 0x7c);
        argumentOrField4 = Level40_79810Field(resultOrField2, int*, 0x7c);
        fieldHighOrAddress3 = Level40_79810Field(fieldHighOrAddress3, int*, 0x80);
        argumentOrField5 = Level40_79810Field(resultOrField2, int*, 0x80);
        argumentOrField4 = argumentOrField7 - argumentOrField4;
        argumentOrField5 = fieldHighOrAddress3 - argumentOrField5;
        resultOrField2 = Level40_79810PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        resultOrField2 += 64;
        resultOrField2 &= 255;
        resultOrField2 *= 2;
        capturedHighOrLow8 = (int)&Level40_79810Data65920View1;
        Level40_79810Keep(capturedHighOrLow8);
        fieldHighOrAddress3 = resultOrField2 + capturedHighOrLow8;
        MATCHING_KEEP_VOLATILE_CLOBBER(fieldHighOrAddress3, "$7");
        argumentOrField7 = retainedAngle22 * 2;
        argumentOrField5 = argumentOrField7 + capturedHighOrLow8;
        fieldHighOrAddress3 = Level40_79810Field(fieldHighOrAddress3, short*, 0x0);
        argumentOrField4 = Level40_79810Field(argumentOrField5, short*, 0x0);
        MATCHING_KEEP2(fieldHighOrAddress3, argumentOrField4);
        fieldHighOrAddress3 >>= 4;
        Level40_79810MultiplyComplete(fieldHighOrAddress3, argumentOrField4);
        resultOrField2 += retainedOriginalTableBase;
        Level40_79810CaptureLow(capturedHighOrLow8);
        fieldHighOrAddress3 = capturedHighOrLow8 >> 12;
        originalFrame.sp48 = fieldHighOrAddress3;
        resultOrField2 = Level40_79810Field(resultOrField2, short*, 0x0);
        fieldHighOrAddress3 = Level40_79810Field(argumentOrField5, short*, 0x0);
        MATCHING_KEEP2(resultOrField2, fieldHighOrAddress3);
        resultOrField2 >>= 4;
        Level40_79810MultiplyComplete(resultOrField2, fieldHighOrAddress3);
        __asm__(""
                : "=r"(emittedVertexCount21)
                : "0"(emittedVertexCount21), "x"(completeSignedProduct));
        emittedVertexCount21++;
        Level40_79810Keep(emittedVertexCount21);
        emittedVertexCount21++;
        recordOrHistoryCount18 = angleCreatedOrSourceOffset17;
        naturalCountRecordOrOffset16 += 0x7C;
        currentHistoryPositionAddress = privateRecord19 + naturalCountRecordOrOffset16;
        Level40_79810Keep(currentHistoryPositionAddress);
        argumentOrField6 = vectorAddress23;
        argumentOrField7 += retainedOriginalTableBase;
        MATCHING_KEEP_VOLATILE_CLOBBER(argumentOrField7, "$4");
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        ownerThenGeometryOffset20 += 12;
        Level40_79810CaptureLow(capturedHighOrLow8);
        resultOrField2 = capturedHighOrLow8 >> 12;
        originalFrame.sp4C = resultOrField2;
        resultOrField2 = Level40_79810Field(argumentOrField7, short*, 0x0);
        __asm__(""
                : "=r"(currentHistoryPositionAddress)
                : "0"(currentHistoryPositionAddress), "r"(resultOrField2));
        argumentOrField5 = currentHistoryPositionAddress;
        Level40_79810Keep(resultOrField2);
        resultOrField2 >>= 4;
        originalFrame.sp50 = resultOrField2;
        Level40_79810AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        argumentOrField5 = currentHistoryPositionAddress;
        argumentOrField6 = vectorAddress23;
        Level40_79810SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        resultOrField2 = retainedAngle22 - 4;
        retainedAngle22 = resultOrField2 & 255;
        ownerThenGeometryOffset20 += 12;
    } while (recordOrHistoryCount18 < 32);
    resultOrField2 = emittedVertexCount21 * 12;
    resultOrField2 = privateRecord19 + resultOrField2;
    fieldHighOrAddress3 = -1;
    Level40_79810Field(resultOrField2, int*, 0x1fc) = fieldHighOrAddress3;
    Level40_79810Field(resultOrField2, int*, 0x200) = fieldHighOrAddress3;
    Level40_79810Field(resultOrField2, int*, 0x204) = fieldHighOrAddress3;
    return;
}
#undef Level40_79810Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007A638.
* AI generated; not human reviewed. All794 original instructions,5 selectors,
* one zero pad and every actual destination must match:800 owned words.
* Frame88 saves S0..S4/RA and retains original SP20..6F workspace. Saved S0
* vector,distance,path remainder and sampled-record phases remain disjoint;
* S1 player/position/angle roles remain disjoint. Complete signed remainders
* retain original divide-by-zero and signed-overflow guards. No partialHI/LO.
* Descriptor short2/shortA/short0,vector wordC and original signed table reads
* retain their independent complete producers. Table66980 consumes a BYTE
* at the old index before decrement;the index is restored before its selected
* byte read. Falsification:old index3 samples byte3,then decrements to2;on loop
* exit the final selected index is3. It must never sample byte2 first.
* Both final35A80 calls pass all8 original words:owner,descriptor,512,192,
* 0,signed private44>>4,24,and flag5 or1. Branch-local literal calls preserve
* both original outgoing zero/24 stores and the common later flag store.
* Shared removal735,flag check739,state clear781 and notification783 retain
* their original entry points. False countdown at275 bypasses state-timer
* store392. Original unsignedFE store and all byte/short/word widths remain.
* Empty metadata consumes complete initialized values/addresses or clobbers
* dead values before fresh complete producers;zero CPU instructions. Known
* helper views use matched EXE/headers. Compiler/filter/flags unchanged;
* no opcode asm,fixedFP,undefined saved inputs or overlapping live aliases.
* Physical units/fixed point,complete helper/caller chains,cadence beyond
* invocation,Rev1 correspondence and synchronized retail runtime remain open.
* Confidence is binary identity after all gates. Next:human review and retail
* captures. Falsification:every native/linked word,actual target,owned data and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 d037c924f72728b08b82191690356a7452d27a52a3c59553d56c3bd9f028893d */
#define Level40_7A638Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level40_7A638Call13D44View1() __asm__("func_80013D44");
int Level40_7A638Call1A358View1() __asm__("func_8001A358");
int Level40_7A638RequestMobyAnimationView1() __asm__("func_80034F40");
int Level40_7A638CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level40_7A638Call35A80View1(void*, int, int, int, int, int, int, int) __asm__("func_80035A80");
int Level40_7A638RandBetweenView1() __asm__("func_8003636C");
int Level40_7A638Call36A68View1() __asm__("func_80036A68");
int Level40_7A638Call37014View1() __asm__("func_80037014");
int Level40_7A638Call37BBCView1() __asm__("func_80037BBC");
int Level40_7A638PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level40_7A638PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level40_7A638ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Level40_7A638CopyVectorView1() __asm__("func_8004F178");
int Level40_7A638AddVectorView1() __asm__("func_8004F194");
int Level40_7A638SubtractVectorView1() __asm__("func_8004F1C8");
int Level40_7A638AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level40_7A638ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level40_7A638Call512E4View1() __asm__("func_800512E4");
int Level40_7A638DeleteMobyView1() __asm__("func_80055B18");
int Level40_7A638RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level40_7A638InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Level40_7A638Data66980View1 __asm__("D_80066980");
extern int Level40_7A638Data66EACView1 __asm__("D_80066EAC");
extern int Level40_7A638Data66EAEView1 __asm__("D_80066EAE");
extern int Level40_7A638Data66FCCView1 __asm__("D_80066FCC");
extern int Level40_7A638Data6C550View1 __asm__("D_8006C550");
extern int Level40_7A638Data6C58CView1 __asm__("D_8006C58C");
extern unsigned char Level40_7A638Data6C62CView1 __asm__("D_8006C62C");
extern int Level40_7A638Data6C71CView1 __asm__("D_8006C71C");
extern int Level40_7A638Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level40_7A638Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level40_7A638Data6E048View1 __asm__("D_8006E048");
extern int Level40_7A638Data6E344View1 __asm__("D_8006E344");
extern int Level40_7A638Data70300View1 __asm__("D_80070300");
extern int Level40_7A638Data70328View1 __asm__("D_80070328");
extern int Level40_7A638Data71AACView1 __asm__("D_80071AAC");
extern void* (*Level40_7A638DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_40_8007A638(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        retainedGlobalCounterAddress8 __asm__("$8");
    register void* ownerRecord19 __asm__("$19");
    register int privateRecord18 __asm__("$18"), retainedVectorDistanceOrPathIndex16 __asm__("$16"),
        retainedPlayerBasePositionOrAngle17 __asm__("$17"), retainedPlayerBase20 __asm__("$20");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C;
    } originalFrame;
    int temporaryWord12;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord13;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord10;
    int temporaryWord14;
    int temporaryWord16;
    int temporaryWord1;
    int temporaryWord11;
    int temporaryWord15;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    privateRecord18 = Level40_7A638Field(ownerRecord19, void**, 0);
    if (((unsigned int)(Level40_7A638Field(ownerRecord19, unsigned char*, 0x48) - 3) >= 2U) &&
        (Level40_7A638Field(ownerRecord19, unsigned char*, 0x49) == 3) &&
        (Level40_7A638Field(ownerRecord19, int*, 0x18) != 0)) {
        Level40_7A638PlayMobySoundEventView1(ownerRecord19, Level40_7A638RandBetweenView1(0, 2), 0);
        Level40_7A638Field(privateRecord18, int*, 0x48) = 0xA0;
        Level40_7A638Field(privateRecord18, int*, 0x3C) = 0;
        Level40_7A638Field(ownerRecord19, unsigned char*, 0x49) = 4U;
        Level40_7A638Field(ownerRecord19, unsigned char*, 0x48) = 3U;
        Level40_7A638RequestMobyAnimationView1(ownerRecord19, 3);
    }
    temporaryWord10 = Level40_7A638Field(ownerRecord19, unsigned char*, 0x48);
    Level40_7A638Field(ownerRecord19, int*, 24) = 0;
    switch (temporaryWord10) {
        case 0:
            temporaryWord14 = Level40_7A638Field(ownerRecord19, unsigned char*, 73);
            switch (temporaryWord14) {
                case 0:
                    if (!(Level40_7A638Data6C7B4View1 & 0x20) &&
                        !(Level40_7A638Field((int)&Level40_7A638Data70300View1, unsigned char*,
                                             Level40_7A638Data6C58CView1) &
                          0x20) &&
                        (Level40_7A638Field((int)&Level40_7A638Data70300View1, unsigned char*,
                                            Level40_7A638Field((int)&Level40_7A638Data66FCCView1,
                                                               unsigned char*, 0x2F)) &
                         1)) {
                        Level40_7A638Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                        return;
                    }
                    goto removeOriginalOwner735;
                case 1:
                    if ((Level40_7A638Call37BBCView1(ownerRecord19, 0) != 0) ||
                        ((Level40_7A638Data6C7B4View1 & 0x20) &&
                         !(Level40_7A638Data6C62CView1 & 0x20))) {
                        Level40_7A638Call512E4View1(ownerRecord19, 0, 1);
                        Level40_7A638Field(ownerRecord19, unsigned char*, 0x48) = 1U;
                        return;
                    }
                default:
                    return;
                case 3:
                    argumentWord4 = (int)&originalFrame.sp20;
                    MATCHING_KEEP_CLOBBER(argumentWord4, "$16");
                    retainedVectorDistanceOrPathIndex16 = (int)&Level40_7A638Data70328View1 + 152;
                    Level40_7A638CopyVectorView1(argumentWord4,
                                                 retainedVectorDistanceOrPathIndex16);
                    originalFrame.sp20 *= 0x14;
                    originalFrame.sp24 *= 0x14;
                    originalFrame.sp28 *= 0x14;
                    Level40_7A638ShiftVectorRightTowardZeroView1(&originalFrame.sp20, 6);
                    argumentWord4 = (int)&originalFrame.sp20;
                    argumentWord5 = argumentWord4;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4),
                              "r"(retainedVectorDistanceOrPathIndex16)
                            : "$17", "memory");
                    retainedPlayerBasePositionOrAngle17 = retainedVectorDistanceOrPathIndex16 - 152;
                    Level40_7A638AddVectorView1(argumentWord4, argumentWord5,
                                                retainedPlayerBasePositionOrAngle17);
                    if (({
                            rawWord2 = Level40_7A638ApproximatePlanarDistanceView1(
                                ownerRecord19 + 12, &originalFrame.sp20);
                            argumentWord4 = (int)&originalFrame.sp30;
                            rawWord2;
                        }) < 6144) {
                        __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$7", "memory");
                        argumentWord7 = Level40_7A638Field(privateRecord18, int*, 52);
                        argumentWord6 = Level40_7A638Field(argumentWord7, short*, 2);
                        MATCHING_KEEP_CLOBBER(argumentWord7, "memory");
                        rawWord2 = Level40_7A638Field(argumentWord7, short*, 10);
                        rawWord3 = Level40_7A638Field(argumentWord7, short*, 0);
                        rawWord2 = argumentWord6 + rawWord2;
                        rawWord2 += rawWord3;
                        retainedVectorDistanceOrPathIndex16 = rawWord2 % rawWord3;
                        __asm__(""
                                : "=r"(retainedVectorDistanceOrPathIndex16)
                                : "0"(retainedVectorDistanceOrPathIndex16)
                                : "$5", "memory");
                        argumentWord5 = retainedPlayerBasePositionOrAngle17;
                        MATCHING_KEEP_CLOBBER(argumentWord5, "memory");
                        rawWord2 = Level40_7A638Field(argumentWord7, int*, 12);
                        MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                        argumentWord6 *= 16;
                        argumentWord6 = rawWord2 + argumentWord6;
                        Level40_7A638SubtractVectorView1(argumentWord4, argumentWord5,
                                                         argumentWord6, argumentWord7);
                        retainedPlayerBasePositionOrAngle17 = Level40_7A638PlanarHeadingLookupView1(
                            originalFrame.sp30, originalFrame.sp34, 0);
                        rawWord2 = Level40_7A638Field(privateRecord18, int*, 52);
                        rawWord3 = Level40_7A638Field(rawWord2, int*, 12);
                        rawWord2 = Level40_7A638Field(rawWord2, short*, 2);
                        __asm__ volatile("" ::: "$6", "memory");
                        argumentWord6 = 0;
                        rawWord2 *= 16;
                        rawWord2 += rawWord3;
                        argumentWord4 = Level40_7A638Field(rawWord2, int*, 0);
                        argumentWord5 = Level40_7A638Field(rawWord2, int*, 4);
                        __asm__(""
                                : "=r"(retainedVectorDistanceOrPathIndex16)
                                : "0"(retainedVectorDistanceOrPathIndex16), "r"(argumentWord4),
                                  "r"(rawWord3)
                                : "memory");
                        retainedVectorDistanceOrPathIndex16 =
                            retainedVectorDistanceOrPathIndex16 * 16 + rawWord3;
                        MATCHING_KEEP(retainedVectorDistanceOrPathIndex16);
                        argumentWord7 =
                            Level40_7A638Field(retainedVectorDistanceOrPathIndex16, int*, 0);
                        rawWord3 = Level40_7A638Field(retainedVectorDistanceOrPathIndex16, int*, 4);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Level40_7A638PlanarHeadingLookupView1(
                            argumentWord4, argumentWord5, argumentWord6);
                        retainedPlayerBasePositionOrAngle17 =
                            Level40_7A638AbsoluteByteAngleDeltaView1(
                                retainedPlayerBasePositionOrAngle17, rawWord2);
                        if (({
                                rawWord2 = retainedPlayerBasePositionOrAngle17 < 32;
                                rawWord2;
                            }) == 0) {
                            if (({
                                    rawWord2 = retainedPlayerBasePositionOrAngle17 < 96;
                                    rawWord2;
                                }) != 0) {
                                if (({
                                        rawWord2 = Level40_7A638PlanarHeadingLookupView1(
                                            -originalFrame.sp30, -originalFrame.sp34, 0);
                                        rawWord3 = Level40_7A638Field(
                                            (int)&Level40_7A638Data70328View1, unsigned char*, 14);
                                        rawWord2 -= rawWord3;
                                        retainedPlayerBasePositionOrAngle17 = rawWord2 & 255;
                                        rawWord2 = retainedPlayerBasePositionOrAngle17 < 128;
                                        rawWord2;
                                    }) != 0) {
                                    goto reverseOriginalPathDirection216;
                                }
                            }
                        } else {
                        reverseOriginalPathDirection216:
                            temporaryWord15 = Level40_7A638Field(privateRecord18, void**, 0x34);
                            Level40_7A638Field(temporaryWord15, short*, 0xA) =
                                (short)-(short)(unsigned short)Level40_7A638Field(temporaryWord15,
                                                                                  short*, 0xA);
                            argumentWord5 = Level40_7A638Field(privateRecord18, int*, 52);
                            argumentWord4 = Level40_7A638Field(argumentWord5, short*, 10);
                            __asm__ volatile("" ::: "$2", "memory");
                            rawWord2 = Level40_7A638Field(argumentWord5, short*, 2);
                            rawWord3 = Level40_7A638Field(argumentWord5, short*, 0);
                            argumentWord4 *= 2;
                            rawWord2 += argumentWord4;
                            rawWord2 += rawWord3;
                            rawWord3 = rawWord2 % rawWord3;
                            Level40_7A638Field(argumentWord5, short*, 2) = rawWord3;
                            Level40_7A638Field(privateRecord18, int*, 0x40) = 0x1E;
                        }
                        argumentWord4 = (int)ownerRecord19;
                        MATCHING_BARRIER_VOLATILE("$5");
                        argumentWord5 = 2;
                        rawWord2 = 256;
                        Level40_7A638Field(privateRecord18, int*, 68) = rawWord2;
                        rawWord2 = 2;
                        Level40_7A638Field(argumentWord4, unsigned char*, 72) = rawWord2;
                        __asm__(""
                                : "=r"(argumentWord5)
                                : "0"(argumentWord5), "r"(privateRecord18));
                        goto notifyOriginalOwnerState783;
                    }
                    return;
                case 5:
                    argumentWord4 = (int)ownerRecord19;
                    MATCHING_BARRIER_VOLATILE("$5");
                    argumentWord5 = 2;
                    rawWord2 = 256;
                    Level40_7A638Field(privateRecord18, int*, 68) = rawWord2;
                    rawWord2 = 2;
                    Level40_7A638Field(argumentWord4, unsigned char*, 72) = rawWord2;
                    __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(ownerRecord19));
                    goto notifyOriginalOwnerState783;
            }
            return;
        case 1:
            rawWord2 = Level40_7A638Data6E344View1;
            rawWord3 = 1;
            if (rawWord2 == rawWord3)
                return;
            rawWord2 = Level40_7A638Field(privateRecord18, unsigned char*, 4);
            Level40_7A638Field(privateRecord18, int*, 72) = 0;
            if (rawWord2 != rawWord3)
                goto selectOriginalModeThree267;
            rawWord2 = 5;
            goto storeOriginalSelectedMode269;
        selectOriginalModeThree267:
            rawWord2 = 3;
        storeOriginalSelectedMode269:
            Level40_7A638Field(ownerRecord19, unsigned char*, 73) = rawWord2;
            Level40_7A638Field(ownerRecord19, unsigned char*, 72) = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 0;
            goto notifyOriginalOwnerState783;
        case 3:
            if (({
                    rawWord2 = Level40_7A638CountTimerDownView1(privateRecord18 + 60, 4);
                    retainedVectorDistanceOrPathIndex16 = 0;
                    rawWord2;
                }) != 0) {
                temporaryWord18 = 0;
                do {
                    if (Level40_7A638Field((int)&Level40_7A638Data66EAEView1, short*,
                                           temporaryWord18) != 0) {
                        retainedVectorDistanceOrPathIndex16 += Level40_7A638Field(
                            (int)&Level40_7A638Data66EACView1, short*, temporaryWord18);
                    }
                    temporaryWord18 += 4;
                } while (temporaryWord18 < 0x30);
                retainedVectorDistanceOrPathIndex16 =
                    retainedVectorDistanceOrPathIndex16 - Level40_7A638Data71AACView1;
                if (retainedVectorDistanceOrPathIndex16 > 0) {
                    rawWord2 = retainedVectorDistanceOrPathIndex16 < 100;
                    MATCHING_KEEP(rawWord2);
                    argumentWord4 = 0;
                    if (!rawWord2) {
                        argumentWord4 = 3;
                        MATCHING_KEEP(argumentWord4);
                    }
                    rawWord3 = Level40_7A638RandBetweenView1(argumentWord4, 4);
                    do {
                        rawWord2 = Level40_7A638Field((int)&Level40_7A638Data66980View1,
                                                      unsigned char*, rawWord3);
                        rawWord2 = retainedVectorDistanceOrPathIndex16 < rawWord2;
                        rawWord3 -= 1;
                    } while (rawWord2);
                    rawWord3 += 1;
                    argumentWord4 = (int)ownerRecord19;
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(argumentWord4) : "memory");
                    Level40_7A638Field(ownerRecord19, unsigned char*, 0x50) =
                        (unsigned char)Level40_7A638Field((int)&Level40_7A638Data66980View1,
                                                          unsigned char*, rawWord3);
                    Level40_7A638RefreshMobySpatialGridAndBasisView1(argumentWord4, 4);
                    Level40_7A638InterpolateMobyVertexView1(ownerRecord19, 0, &originalFrame.sp30);
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 16;
                    argumentWord6 = (int)&originalFrame.sp30;
                    rawWord3 = Level40_7A638Field(ownerRecord19, unsigned char*, 80);
                    rawWord2 = Level40_7A638Data6C71CView1;
                    __asm__(""
                            : "=r"(argumentWord6)
                            : "0"(argumentWord6), "r"(argumentWord4), "r"(argumentWord5)
                            : "$8", "memory");
                    retainedGlobalCounterAddress8 = (int)&Level40_7A638Data71AACView1;
                    rawWord2 += rawWord3;
                    Level40_7A638Data6C71CView1 = rawWord2;
                    rawWord3 = Level40_7A638Field(ownerRecord19, unsigned char*, 80);
                    rawWord2 = Level40_7A638Field(retainedGlobalCounterAddress8, int*, 0);
                    argumentWord7 = 0;
                    rawWord2 += rawWord3;
                    Level40_7A638Field(retainedGlobalCounterAddress8, int*, 0) = rawWord2;
                    Level40_7A638Call36A68View1(argumentWord4, argumentWord5, argumentWord6,
                                                argumentWord7);
                    rawWord2 = 2;
                    goto storeOriginalStateTimer392;
                }
                rawWord2 = 0x10000002;
                retainedVectorDistanceOrPathIndex16 = (int)&originalFrame.sp40;
                argumentWord4 = retainedVectorDistanceOrPathIndex16;
                Level40_7A638Field((int)&Level40_7A638Data70328View1, int*, 524) = rawWord2;
                rawWord3 = Level40_7A638Field(privateRecord18, int*, 52);
                rawWord2 = Level40_7A638Data6C7B4View1;
                argumentWord5 = Level40_7A638Field(rawWord3, int*, 12);
                rawWord2 |= 32;
                Level40_7A638Data6C7B4View1 = rawWord2;
                argumentWord5 += 16;
                Level40_7A638CopyVectorView1(argumentWord4, argumentWord5);
                originalFrame.sp48 +=
                    Level40_7A638Field((int)&Level40_7A638Data70328View1, int*, 0x44);
                temporaryWord7 = Level40_7A638Field(
                    Level40_7A638Field(privateRecord18, void**, 0x34), void**, 0xC);
                temporaryWord2 = Level40_7A638Field(temporaryWord7, int*, 0);
                Level40_7A638Call13D44View1(
                    &originalFrame.sp40,
                    Level40_7A638PlanarHeadingLookupView1(
                        temporaryWord2 - Level40_7A638Field(temporaryWord7, int*, 0x10),
                        Level40_7A638Field(temporaryWord7, int*, 4) -
                            Level40_7A638Field(temporaryWord7, int*, 0x14),
                        0),
                    0, 0);
                if (Level40_7A638Field((int)&Level40_7A638Data70328View1, int*, 0x280) < 0) {
                    Level40_7A638Field((int)&Level40_7A638Data70328View1, int*, 0x280) = 0;
                }
                Level40_7A638Field(ownerRecord19, unsigned char*, 0x48) = 4U;
                return;
            }
            goto checkOriginalTransition393;
        storeOriginalStateTimer392:
            Level40_7A638Field(privateRecord18, int*, 60) = rawWord2;
        checkOriginalTransition393:
            if (Level40_7A638Data6C770View1 != 0) {
                Level40_7A638Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                Level40_7A638RequestMobyAnimationView1(ownerRecord19, 2);
            }
        case 2:
            temporaryWord16 = Level40_7A638Field(ownerRecord19, unsigned char*, 0x49);
            switch (temporaryWord16) {
                case 3:
                    retainedVectorDistanceOrPathIndex16 = (int)&originalFrame.sp30;
                    argumentWord4 = retainedVectorDistanceOrPathIndex16;
                    MATCHING_KEEP_CLOBBER(argumentWord4, "$17");
                    retainedPlayerBasePositionOrAngle17 = (int)&Level40_7A638Data70328View1 + 152;
                    Level40_7A638Field(privateRecord18, int*, 72) = 0;
                    Level40_7A638CopyVectorView1(argumentWord4,
                                                 retainedPlayerBasePositionOrAngle17);
                    originalFrame.sp30 *= 0x14;
                    originalFrame.sp34 *= 0x14;
                    originalFrame.sp38 *= 0x14;
                    Level40_7A638ShiftVectorRightTowardZeroView1(&originalFrame.sp30, 6);
                    retainedPlayerBase20 = retainedPlayerBasePositionOrAngle17 - 0x98;
                    Level40_7A638AddVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                                retainedPlayerBase20);
                    retainedPlayerBasePositionOrAngle17 = ownerRecord19 + 0xC;
                    retainedVectorDistanceOrPathIndex16 =
                        Level40_7A638ApproximatePlanarDistanceView1(
                            retainedPlayerBasePositionOrAngle17, &originalFrame.sp30);
                    temporaryWord17 = Level40_7A638Field(privateRecord18, int*, 0x44) + 8;
                    Level40_7A638Field(privateRecord18, int*, 0x44) = temporaryWord17;
                    if (temporaryWord17 >= 0x101) {
                        Level40_7A638Field(privateRecord18, int*, 0x44) = 0x100;
                    }
                    if (!(Level40_7A638Call35A80View1(
                              ownerRecord19, Level40_7A638Field(privateRecord18, void**, 0x34),
                              0x200, 0xC0, 0,
                              (int)Level40_7A638Field(privateRecord18, int*, 0x44) >> 4, 0x18, 5) &
                          4)) {
                        Level40_7A638Field(privateRecord18, int*, 0x44) = 0;
                    }
                    rawWord2 = retainedVectorDistanceOrPathIndex16 < 10241;
                    MATCHING_KEEP(privateRecord18);
                    argumentWord4 = privateRecord18 + 64;
                    if (rawWord2)
                        goto callOriginalCountdown489;
                    rawWord2 = Level40_7A638ApproximatePlanarDistanceView1(
                        retainedPlayerBasePositionOrAngle17, retainedPlayerBase20);
                    MATCHING_KEEP(privateRecord18);
                    argumentWord4 = privateRecord18 + 64;
                    if (rawWord2 < 10241)
                        goto callOriginalCountdown489;
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 0;
                    rawWord2 = 2;
                    Level40_7A638Field(privateRecord18, int*, 64) = rawWord2;
                    goto clearOriginalOwnerState781;
                callOriginalCountdown489:
                    Level40_7A638CountTimerDownView1(argumentWord4, 4);
                    argumentWord7 = Level40_7A638Field(privateRecord18, int*, 52);
                    argumentWord6 = Level40_7A638Field(argumentWord7, short*, 2);
                    MATCHING_KEEP_CLOBBER(argumentWord7, "memory");
                    rawWord2 = Level40_7A638Field(argumentWord7, short*, 10);
                    rawWord3 = Level40_7A638Field(argumentWord7, short*, 0);
                    rawWord2 = argumentWord6 + rawWord2;
                    rawWord2 += rawWord3;
                    retainedVectorDistanceOrPathIndex16 = rawWord2 % rawWord3;
                    __asm__(""
                            : "=r"(retainedVectorDistanceOrPathIndex16)
                            : "0"(retainedVectorDistanceOrPathIndex16)
                            : "$4", "$5", "memory");
                    argumentWord4 = (int)&originalFrame.sp50;
                    argumentWord5 = (int)&Level40_7A638Data70328View1;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4)
                            : "memory");
                    rawWord2 = Level40_7A638Field(argumentWord7, int*, 12);
                    MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                    argumentWord6 *= 16;
                    argumentWord6 = rawWord2 + argumentWord6;
                    Level40_7A638SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6,
                                                     argumentWord7);
                    retainedPlayerBasePositionOrAngle17 = Level40_7A638PlanarHeadingLookupView1(
                        originalFrame.sp50, originalFrame.sp54, 0);
                    rawWord2 = Level40_7A638Field(privateRecord18, int*, 52);
                    rawWord3 = Level40_7A638Field(rawWord2, int*, 12);
                    rawWord2 = Level40_7A638Field(rawWord2, short*, 2);
                    __asm__ volatile("" ::: "$6", "memory");
                    argumentWord6 = 0;
                    rawWord2 *= 16;
                    rawWord2 += rawWord3;
                    argumentWord4 = Level40_7A638Field(rawWord2, int*, 0);
                    argumentWord5 = Level40_7A638Field(rawWord2, int*, 4);
                    __asm__(""
                            : "=r"(retainedVectorDistanceOrPathIndex16)
                            : "0"(retainedVectorDistanceOrPathIndex16), "r"(argumentWord4),
                              "r"(rawWord3)
                            : "memory");
                    retainedVectorDistanceOrPathIndex16 =
                        retainedVectorDistanceOrPathIndex16 * 16 + rawWord3;
                    MATCHING_KEEP(retainedVectorDistanceOrPathIndex16);
                    argumentWord7 =
                        Level40_7A638Field(retainedVectorDistanceOrPathIndex16, int*, 0);
                    rawWord3 = Level40_7A638Field(retainedVectorDistanceOrPathIndex16, int*, 4);
                    argumentWord4 = argumentWord7 - argumentWord4;
                    argumentWord5 = rawWord3 - argumentWord5;
                    rawWord2 = Level40_7A638PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                     argumentWord6);
                    rawWord2 = retainedPlayerBasePositionOrAngle17 - rawWord2;
                    argumentWord4 = rawWord2 & 255;
                    if (argumentWord4 >= 0x81) {
                        argumentWord4 -= 0x100;
                    }
                    rawWord3 = argumentWord4;
                    if (argumentWord4 < 0) {
                        rawWord3 = -rawWord3;
                    }
                    if (rawWord3 >= 0x20) {
                        if (({
                                rawWord2 = rawWord3 < 80;
                                rawWord2;
                            }) &&
                            (Level40_7A638Field(privateRecord18, int*, 0x40) == 0)) {
                            rawWord2 = Level40_7A638Field((int)&Level40_7A638Data70328View1,
                                                          unsigned char*, 14);
                            rawWord2 = retainedPlayerBasePositionOrAngle17 - rawWord2;
                            MATCHING_KEEP(rawWord2);
                            retainedPlayerBasePositionOrAngle17 = rawWord2 & 255;
                            if (retainedPlayerBasePositionOrAngle17 >= 0x81) {
                                retainedPlayerBasePositionOrAngle17 -= 0x100;
                            }
                            if (((argumentWord4 > 0) &&
                                 (retainedPlayerBasePositionOrAngle17 > 0)) ||
                                ((argumentWord4 < 0) &&
                                 (retainedPlayerBasePositionOrAngle17 < 0))) {
                                goto reverseOriginalFollowingPath568;
                            }
                        }
                    } else {
                    reverseOriginalFollowingPath568:
                        temporaryWord11 = Level40_7A638Field(privateRecord18, void**, 0x34);
                        Level40_7A638Field(temporaryWord11, short*, 0xA) = (short)-(
                            short)(unsigned short)Level40_7A638Field(temporaryWord11, short*, 0xA);
                        temporaryWord1 = Level40_7A638Field(privateRecord18, void**, 0x34);
                        temporaryWord12 = Level40_7A638Field(temporaryWord1, short*, 0);
                        Level40_7A638Field(temporaryWord1, short*, 2) =
                            (short)((int)(Level40_7A638Field(temporaryWord1, short*, 2) +
                                          (Level40_7A638Field(temporaryWord1, short*, 0xA) * 2) +
                                          temporaryWord12) %
                                    temporaryWord12);
                        Level40_7A638Field(privateRecord18, int*, 0x40) = 0x1E;
                        Level40_7A638Field(privateRecord18, int*, 0x44) = 0x100;
                        return;
                    }
                    return;
                case 4:
                    temporaryWord8 = Level40_7A638Field(privateRecord18, int*, 0x48) - 0xC;
                    Level40_7A638Field(privateRecord18, int*, 0x48) = temporaryWord8;
                    Level40_7A638Field(ownerRecord19, int*, 0x14) =
                        (int)(Level40_7A638Field(ownerRecord19, int*, 0x14) + temporaryWord8);
                    temporaryWord9 = Level40_7A638Field(privateRecord18, int*, 0x44) + 8;
                    Level40_7A638Field(privateRecord18, int*, 0x44) = temporaryWord9;
                    if (temporaryWord9 >= 0x101) {
                        Level40_7A638Field(privateRecord18, int*, 0x44) = 0x100;
                    }
                    if (!(Level40_7A638Call35A80View1(
                              ownerRecord19, Level40_7A638Field(privateRecord18, void**, 0x34),
                              0x200, 0xC0, 0,
                              (int)Level40_7A638Field(privateRecord18, int*, 0x44) >> 4, 0x18, 1) &
                          4)) {
                        Level40_7A638Field(privateRecord18, int*, 0x44) = 0;
                    }
                    if (Level40_7A638Field(privateRecord18, int*, 0x48) > 0) {
                        originalFrame.sp68 = 0;
                        return;
                    }
                    Level40_7A638CopyVectorView1(&originalFrame.sp60, ownerRecord19 + 0xC);
                    originalFrame.sp68 += 0x200;
                    temporaryWord4 = Level40_7A638Call1A358View1(&originalFrame.sp60, 0x200);
                    originalFrame.sp68 = temporaryWord4;
                    if (temporaryWord4 != 0) {
                        Level40_7A638Field(privateRecord18, int*, 0x48) = 0;
                        rawWord3 = originalFrame.sp68;
                        rawWord2 = 3;
                        Level40_7A638Field(ownerRecord19, unsigned char*, 73) = rawWord2;
                        Level40_7A638Field(ownerRecord19, int*, 20) = rawWord3;
                        return;
                    }
                    return;
                case 5:
                    temporaryWord13 = Level40_7A638Field(privateRecord18, int*, 0x28);
                    if ((temporaryWord13 >= 0) &&
                        (Level40_7A638ApproximatePlanarDistanceView1(
                             ownerRecord19 + 0xC, Level40_7A638Data6C550View1 +
                                                      (temporaryWord13 * 0x58) + 0xC) < 0x200)) {
                        Level40_7A638DataSpawnParticleView1(
                            2, 0xC,
                            Level40_7A638Data6C550View1 +
                                (Level40_7A638Field(privateRecord18, int*, 0x28) * 0x58),
                            5);
                    }
                    temporaryWord5 = Level40_7A638Field(privateRecord18, int*, 0x44) + 8;
                    Level40_7A638Field(privateRecord18, int*, 0x44) = temporaryWord5;
                    if (temporaryWord5 >= 0x101) {
                        Level40_7A638Field(privateRecord18, int*, 0x44) = 0x100;
                    }
                    if (Level40_7A638Field(Level40_7A638Field(privateRecord18, int*, 56), short*,
                                           2) <
                        Level40_7A638Field(Level40_7A638Field(privateRecord18, int*, 56), short*,
                                           0) -
                            1) {
                        rawWord3 = Level40_7A638Call35A80View1(
                            ownerRecord19, Level40_7A638Field(privateRecord18, int*, 56), 512, 192,
                            0, Level40_7A638Field(privateRecord18, int*, 68) >> 4, 24, 5);
                    } else {
                        rawWord3 = Level40_7A638Call35A80View1(
                            ownerRecord19, Level40_7A638Field(privateRecord18, int*, 56), 512, 192,
                            0, Level40_7A638Field(privateRecord18, int*, 68) >> 4, 24, 1);
                    }
                    rawWord2 = rawWord3 & 1;
                    if (!rawWord2)
                        goto checkOriginalMovementFlags739;
                    rawWord2 = Level40_7A638Field(privateRecord18, int*, 56);
                    rawWord2 = Level40_7A638Field(rawWord2, short*, 2);
                    if (rawWord2)
                        goto checkOriginalMovementFlags739;
                removeOriginalOwner735:
                    Level40_7A638DeleteMobyView1(ownerRecord19);
                    return;
                checkOriginalMovementFlags739:
                    rawWord2 = rawWord3 & 4;
                    if (!rawWord2) {
                        __asm__ volatile("" ::: "$2", "memory");
                        Level40_7A638Field(privateRecord18, int*, 68) = 0;
                    }
                    return;
            }
            return;
        case 4:
            if (Level40_7A638Data6E048View1 & 1) {
                Level40_7A638CopyVectorView1(
                    &originalFrame.sp40,
                    Level40_7A638Field(Level40_7A638Field(privateRecord18, void**, 0x34), void**,
                                       0xC));
                Level40_7A638CopyVectorView1(ownerRecord19 + 0xC, &originalFrame.sp40);
                Level40_7A638Call37014View1(ownerRecord19);
                Level40_7A638Field(ownerRecord19, unsigned char*, 82) = 254;
                Level40_7A638RefreshMobySpatialGridAndBasisView1(ownerRecord19, 2);
                Level40_7A638Field(ownerRecord19, signed char*, 0x44) = 0;
                Level40_7A638Field(ownerRecord19, signed char*, 0x45) = 0;
                temporaryWord6 = Level40_7A638Field(
                    Level40_7A638Field(privateRecord18, void**, 0x34), void**, 0xC);
                temporaryWord3 = Level40_7A638Field(temporaryWord6, int*, 0x10);
                rawWord2 = Level40_7A638PlanarHeadingLookupView1(
                    temporaryWord3 - Level40_7A638Field(temporaryWord6, int*, 0),
                    Level40_7A638Field(temporaryWord6, int*, 20) -
                        Level40_7A638Field(temporaryWord6, int*, 4),
                    0);
                argumentWord4 = (int)ownerRecord19;
                argumentWord5 = 0;
                Level40_7A638Field(argumentWord4, unsigned char*, 70) = rawWord2;
                rawWord2 = 1;
                Level40_7A638Field(argumentWord4, unsigned char*, 73) = rawWord2;
                goto clearOriginalOwnerState781;
            }
            return;
    }
    return;
clearOriginalOwnerState781:
    Level40_7A638Field(argumentWord4, unsigned char*, 72) = 0;
notifyOriginalOwnerState783:
    Level40_7A638RequestMobyAnimationView1(argumentWord4, argumentWord5);
    return;
}
#undef Level40_7A638Field


/* This caller only reads the signed halfword at tag +0xC. */
typedef struct {
    unsigned char reserved00[0xC];
    short unkC;
} DecodedCloneTag;
extern int D_8006C578, D_8006C574;
void func_level_40_8007B2A0(Moby* moby) {
    DecodedCloneTag* tag = moby->mobyTag;
    if (moby->substate == 0 && tag->unkC <= 0) {
        int index;
        moby->substate = 0x70;
        for (index = 0; index < 4; index++) {
            Moby* spawned;
            if (D_8006C578 - D_8006C574 < 0x15)
                break;
            spawned = func_800391E8(1, moby->mobyClass, moby, 0, 2, 0x40, 0x100);
            if (spawned) {
                spawned->substate = 1;
                spawned->size = 0x7F;
            }
        }
    }
    func_80039714(moby);
}

/* AI-generated reconstruction; not human reviewed. Rev0 original181 words
 * 8007B378..8007B64C. Reuses Rev1 raw264 controller source-local routes and
 * upstream Moby/helper interfaces. Raw tag offsets and access widths remain
 * explicit; target is an absolute coordinate, not a displacement. Signed
 * Y clamp is [-256,256] around anchor. Empty constraints preserve original
 * fresh read order and A2 scheduling; they emit no instructions. Physical
 * units, tag producer, helper/callback effects and cadence remain open. */
typedef struct {
    Vector3D anchor;
    unsigned short reserved0C;
    unsigned char initialized, duration, reserved10[2], step, heading, minDuration, maxDuration,
        reserved16[2];
    int timer, reserved1C[3], mode;
    unsigned int reserved2C;
    short force, scale;
    unsigned char reserved34[9], direction;
} DecodedRaw264Tag;
extern int D_8006C770;
extern int Raw264PlayerX __asm__("D_80070328");
extern int Raw264PlayerY __asm__("D_80070328+4");
extern unsigned char Raw264PlayerHeading __asm__("D_80070328+0xE");
int Raw264Angle(int, int, int) __asm__("func_8004E880");
int Raw264Direction(int, int, int, int) __asm__("func_800360F8");
int Raw264Random(int, int) __asm__("func_8003636C");
void Raw264Move(Moby*, void*, int) __asm__("func_80037168");
void func_level_40_8007B378(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    register DecodedRaw264Tag* tag __asm__("$17") = moby->mobyTag;
    Vector3D target;
    if (moby->state < 2) {
        if (moby->damageFlags & 0x20000)
            tag->force = 600;
        else if (moby->damageFlags)
            tag->force = 350;
        else
            goto dispatch;
        {
            int direction = moby->unkb;
            if (!direction)
                direction = Raw264Direction(Raw264Angle(moby->position.x - Raw264PlayerX,
                                                        moby->position.y - Raw264PlayerY, 0),
                                            Raw264PlayerHeading, 32, 64);
            tag->direction = direction;
        }
        tag->scale = 256;
        SpawnMoby(16, moby);
        moby->unknownCollision = 0;
        moby->state = 2;
        func_80034F40(moby, 2);
    }
dispatch:
    switch (moby->state) {
        case 0:
            if (D_8006C770) {
                tag->timer = Raw264Random(90, 300);
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            break;
        case 1:
            if (tag->mode) {
                if (!tag->initialized) {
                    {
                        int ownerX = moby->position.x;
                        MATCHING_OBSERVE_CLOBBER(ownerX, "memory");
                        if (tag->anchor.x < ownerX)
                            target.x = tag->anchor.x - (tag->step << 4);
                        else
                            target.x = tag->anchor.x + (tag->step << 4);
                    }
                    target.y = tag->anchor.y;
                    target.z = tag->anchor.z;
                    __asm__("" : : "m"(target) : "memory", "$6");
                    tag->heading =
                        Raw264Angle(target.x - moby->position.x, target.y - moby->position.y, 0);
                    tag->duration = Raw264Random(tag->minDuration, tag->maxDuration);
                    tag->initialized = 1;
                }
                Raw264Move(moby, tag, 87);
                {
                    int delta = moby->position.y - tag->anchor.y;
                    if (delta > 256)
                        moby->position.y = tag->anchor.y + 256;
                    else if (delta < -256)
                        moby->position.y = tag->anchor.y - 256;
                }
                func_80055D24(moby, 4);
            } else
                Raw264Move(moby, tag, 87);
            if (func_800359A4(&tag->timer, 4)) {
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        case 2:
            func_80035194(moby, &tag->reserved2C);
            if (D_8006C770) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 24);
                func_80055B18(moby);
            }
            break;
    }
}

typedef struct {
    Moby* parent;
    unsigned char unk4, unk5;
} DecodedYawTag;
extern int D_8006C644;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_level_40_8007B64C(Moby* moby) {
    DecodedYawTag* tag = moby->mobyTag;
    if (moby->state != tag->parent->state)
        func_80055B18(moby);
    else if (moby->animationState.id == 0)
        moby->angle.yaw += 6;
    else {
        int byteOffset = ((tag->unk5 + D_8006C644) << 3) & 0x1F8;
        int wave = *(short*)((char*)D_80065920 + byteOffset);
        moby->angle.yaw = tag->unk4 + ((wave * 3) >> 9);
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level40,
 * original8007B6FC, complete382 instructions in sibling4515 and original
 * assembly. Verified48 C reused with original40 as authority for differences.
 * Raw fields/units/helper meanings and cadence unresolved; native, linked
 * and every original retail hash required. */
#define Actor40B6FCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor40B6FCHelper13E38(void*, void*, int) __asm__("func_80013E38");
int Actor40B6FCHelper1A358(void*, int) __asm__("func_8001A358");
void* Actor40B6FCHelper2F040(int) __asm__("func_8002F040");
int Actor40B6FCHelper36188(void*) __asm__("func_80036188");
int Actor40B6FCHelper36E60(void*) __asm__("func_80036E60");
int Actor40B6FCPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Actor40B6FCPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Actor40B6FCTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Actor40B6FCMeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Actor40B6FCCopyVector(void*, void*) __asm__("func_8004F178");
int Actor40B6FCAddVector(void*, void*, void*) __asm__("func_8004F194");
int Actor40B6FCSubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Actor40B6FCMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Actor40B6FCDivideVector(void*, void*, int) __asm__("func_8004F228");
int Actor40B6FCAbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Actor40B6FCApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Actor40B6FCHelper4F52C(void*, void*) __asm__("func_8004F52C");
int Actor40B6FCDeleteMoby(void*) __asm__("func_80055B18");
int Actor40B6FCRefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
extern int Actor40B6FCD_80065810 __asm__("D_80065810");
extern int Actor40B6FCD_80065818 __asm__("D_80065818");
extern unsigned char Actor40B6FCD_800658A0[] __asm__("D_800658A0");
extern unsigned char Actor40B6FCD_80065920[] __asm__("D_80065920");
extern unsigned char Actor40B6FCD_80066964[] __asm__("D_80066964");
extern unsigned char Actor40B6FCD_80066988[] __asm__("D_80066988");
extern unsigned char Actor40B6FCD_80066990[] __asm__("D_80066990");
extern unsigned char Actor40B6FCD_80066A48[] __asm__("D_80066A48");
extern int Actor40B6FCD_8006C648 __asm__("D_8006C648");
extern void* Actor40B6FCD_8006C65C __asm__("D_8006C65C");
extern unsigned char Actor40B6FCD_8006DEF8[] __asm__("D_8006DEF8");
extern int Actor40B6FCD_8006E020 __asm__("D_8006E020");
extern int Actor40B6FCD_8006E024 __asm__("D_8006E024");
extern unsigned short Actor40B6FCD_8006E040 __asm__("D_8006E040");
extern unsigned char Actor40B6FCD_80070328[] __asm__("D_80070328");
extern int Actor40B6FCD_80071908 __asm__("D_80071908");
extern unsigned char Actor40B6FCD_80071918[] __asm__("D_80071918");
extern int Actor40B6FCD_8007192C __asm__("D_8007192C");
extern int (*Actor40B6FCSpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
void func_level_40_8007B6FC(void* input) {
    struct {
        struct {
            int x, y, z;
        } first;
        int p1C;
        struct {
            int x, y, z;
        } fifth;
        int p2C;
        struct {
            int x, y, z;
        } eighth;
        int p3C;
        int pad40[2];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    int thirty;
    register int timer __asm__("$3");
    register int timerCondition __asm__("$2");
    register void* selectorOwner __asm__("$4");
    register int selectorMode __asm__("$5");
    register int ten __asm__("$22");
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
    register int distanceResult __asm__("$21");
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
    register unsigned char* tag __asm__("$18");
    register unsigned char* callbackTag __asm__("$17");
    void* callbackOwnerReference;
    void* temp_v1_6;

    workingPosition = owner + 0xC;
    tag = Actor40B6FCField(owner, void**, 0);
    distanceResult = Actor40B6FCApproximatePlanarDistance(workingPosition, Actor40B6FCD_80070328);
    {
        register int old2 __asm__("$2") = Actor40B6FCField(tag, short*, 0xA);
        register int old3 __asm__("$3");
        MATCHING_KEEP(old2);
        old3 = old2;
        old2 = old2 < 0x218;
        __asm__("" : "=r"(old3), "=r"(old2) : "0"(old3), "1"(old2) : "$30", "$16");
        thirty = 30;
        if (old2) {
            temp_v0 = Actor40B6FCD_8006C648;
            temp_v0 = old3 + temp_v0;
            Actor40B6FCField(tag, short*, 0xA) = temp_v0;
        } else {
            MATCHING_BARRIER("$2");
            selectedResource = 0;
            if (Actor40B6FCAbsoluteByteAngleDelta(
                    ((short)Actor40B6FCD_8006E040) >> 4,
                    Actor40B6FCPlanarHeadingLookup(
                        Actor40B6FCField(owner, int*, 12) - Actor40B6FCD_8006E020,
                        Actor40B6FCField(owner, int*, 16) - Actor40B6FCD_8006E024, 0)) < 32)
                selectedResource =
                    Actor40B6FCHelper2F040(Actor40B6FCField(owner, unsigned char*, 0x49));
            if (selectedResource != 0) {
                if (distanceResult < 0x3000) {
                    Actor40B6FCField(tag, unsigned char*, 0x13) =
                        (unsigned char)((int)(selectedResource - Actor40B6FCD_8006DEF8) >> 4);
                    Actor40B6FCField(tag, short*, 0xA) =
                        (short)((unsigned short)Actor40B6FCField(tag, short*, 0xA) - 0x20);
                    Actor40B6FCField(tag, unsigned char*, 0x14) =
                        (unsigned char)((Actor40B6FCField(owner, unsigned char*, 0x49) * 2) +
                                        (rand() & 1));
                } else {
                    Actor40B6FCCopyVector(selectedResource, workingPosition);
                    if (distanceResult <= 0x7FFF) {
                        Actor40B6FCField(tag, short*, 0xA) =
                            (short)((unsigned short)Actor40B6FCField(tag, short*, 0xA) - 0x80);
                        Actor40B6FCField(selectedResource, int*, 8) =
                            (int)(Actor40B6FCField(selectedResource, int*, 8) + 0x80);
                    } else {
                        Actor40B6FCField(tag, short*, 0xA) =
                            (short)((unsigned short)Actor40B6FCField(tag, short*, 0xA) - 0x100);
                    }
                    Actor40B6FCField(tag, unsigned char*, 0x13) = 0xFFU;
                }
                Actor40B6FCField(selectedResource, unsigned char*, 0xD) =
                    (unsigned char)(Actor40B6FCField(selectedResource, unsigned char*, 0xD) +
                                    (rand() & 0x3F));
            } else {
                Actor40B6FCField(tag, short*, 0xA) =
                    (short)((unsigned short)Actor40B6FCField(tag, short*, 0xA) - 0x100);
            }
            Actor40B6FCField(tag, short*, 0xA) =
                (short)((unsigned short)Actor40B6FCField(tag, short*, 0xA) - (rand() & 0xFF));
        }
    }
    temp_s0 = Actor40B6FCField(tag, unsigned char*, 0x13);
    MATCHING_KEEP(temp_s0);
    selectorOwner = owner;
    if (temp_s0 < 0x10U) {
        MATCHING_KEEP(selectorOwner);
        selectorMode = 4;
        MATCHING_KEEP(selectorMode);
        temp_s0 *= 16;
        MATCHING_KEEP_CLOBBER(temp_s0, "$2");
        {
            register unsigned char* base __asm__("$2") = Actor40B6FCD_8006DEF8;
            resourceRecord = (unsigned char*)(temp_s0 + (int)base);
        }
        Actor40B6FCRefreshMobySpatialGridAndBasis(selectorOwner, selectorMode);
        Actor40B6FCCopyVector(resourceRecord, (Actor40B6FCField(tag, unsigned char*, 0x14) * 0xC) +
                                                  (Actor40B6FCD_80066A48 + 0x30));
        Actor40B6FCTransformVectorByBasis(owner + 0x20, resourceRecord, resourceRecord);
        Actor40B6FCAddVector(resourceRecord, resourceRecord, owner + 0xC);
        if ((unsigned char)Actor40B6FCField(resourceRecord, unsigned char*, 0xC) < 4U) {
            Actor40B6FCField(tag, unsigned char*, 0x13) = 0xFFU;
        }
    }
    if ((Actor40B6FCField(owner, unsigned char*, 0x4D) != 0) || (distanceResult < 0x1801) ||
        (Actor40B6FCField(owner, unsigned char*, 0x48) != 1) ||
        (Actor40B6FCField(tag, unsigned char*, 0x11) != 0)) {
        if (Actor40B6FCField(owner, int*, 20) <= 1024)
            Actor40B6FCCopyVector(owner + 12, Actor40B6FCD_80070328);
        temp_v1 = Actor40B6FCField(owner, unsigned char*, 0x48);
        switch (temp_v1) { /* switch 1; irregular */
            case 0:        /* switch 1 */
                Actor40B6FCCopyVector(&frame.first.x, owner + 0xC);
                frame.first.z += 0x400;
                Actor40B6FCHelper1A358(&frame.first.x, 0x10000);
                Actor40B6FCHelper36188(tag + 0xE);
                if (Actor40B6FCField(tag, int*, 0xC) & 0xFFFF0000) {
                    Actor40B6FCField(owner, unsigned char*, 0x46) = 0U;
                }
                Actor40B6FCField(owner, int*, 0x14) = (int)Actor40B6FCD_80071908;
                Actor40B6FCField(tag, short*, 0xA) = (short)((rand() & 0xFF) + 0x100);
                Actor40B6FCField(owner, unsigned char*, 0x48) = 1U;
                temp_v0_2 =
                    *(Actor40B6FCD_80066964 + Actor40B6FCField(owner, unsigned char*, 0x50));
                Actor40B6FCField(owner, unsigned char*, 0x49) = temp_v0_2;
                Actor40B6FCField(owner, unsigned char*, 0x3C) =
                    (unsigned char)*(Actor40B6FCD_80066988 + (temp_v0_2 & 0xFF));
                Actor40B6FCField(owner, unsigned char*, 0x54) = (unsigned char)*(
                    Actor40B6FCD_80066990 + Actor40B6FCField(owner, unsigned char*, 0x49));
                goto block_75;
            case 3: /* switch 1 */
                stateThreeVector = &frame.eighth.x;
                MATCHING_KEEP(stateThreeVector);
                Actor40B6FCHelper4F52C(stateThreeVector, tag + 4);
                ten = 10;
                MATCHING_KEEP(ten);
                temp_v0 = Actor40B6FCField(tag, short*, 0xA);
                temp_v0 = temp_v0 < thirty;
                __asm__("" : "=r"(temp_v0) : "0"(temp_v0) : "$23", "$16");
                five = 5;
                if (!temp_v0) {
                    MATCHING_OBSERVE_CLOBBER(five, "$16");
                    Actor40B6FCCopyVector(owner + 0xC, Actor40B6FCD_80070328);
                } else {
                    MATCHING_OBSERVE_CLOBBER(five, "$16");
                    stateThreeDelta = &frame.fifth.x;
                    MATCHING_KEEP_CLOBBER(stateThreeDelta, "$20");
                    {
                        register void* first __asm__("$4") = stateThreeDelta;
                        MATCHING_KEEP_CLOBBER(first, "$20");
                        savedPlayer = Actor40B6FCD_80070328;
                        Actor40B6FCSubtractVector(first, savedPlayer, stateThreeVector);
                    }
                    Actor40B6FCDivideVector(stateThreeDelta, stateThreeDelta, thirty);
                    if (Actor40B6FCMeasureVectorLength(stateThreeDelta, 1) >= 0x1E1) {
                        Actor40B6FCCopyVector(owner + 12, savedPlayer);
                        Actor40B6FCField(tag, short*, 0xA) = thirty;
                    } else {
                        Actor40B6FCMultiplyVectorGpfSf0(stateThreeDelta, stateThreeDelta,
                                                        Actor40B6FCField(tag, short*, 0xA));
                        Actor40B6FCAddVector(owner + 0xC, stateThreeVector, stateThreeDelta);
                        {
                            register int index2 __asm__("$2") = Actor40B6FCField(tag, short*, 0xA);
                            register int quotient3 __asm__("$3");
                            MATCHING_KEEP(index2);
                            index2 *= five;
                            quotient3 = *(short*)(Actor40B6FCD_800658A0 + index2 * 2);
                            MATCHING_KEEP(quotient3);
                            quotient3 /= ten;
                            Actor40B6FCField(owner, int*, 20) += quotient3;
                        }
                    }
                }
                {
                    register int offset __asm__("$2") = Actor40B6FCField(tag, unsigned char*, 0xE);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = Actor40B6FCField(owner, unsigned char*, 0x44);
                    offset += 249;
                    old += offset;
                    Actor40B6FCField(owner, unsigned char*, 0x44) = old;
                }
                {
                    register int offset __asm__("$2") = Actor40B6FCField(tag, unsigned char*, 0xF);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = Actor40B6FCField(owner, unsigned char*, 0x45);
                    offset += 249;
                    old += offset;
                    Actor40B6FCField(owner, unsigned char*, 0x45) = old;
                }
                {
                    register int offset __asm__("$2") = Actor40B6FCField(tag, unsigned char*, 0x10);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = Actor40B6FCField(owner, unsigned char*, 0x46);
                    offset += 249;
                    old += offset;
                    Actor40B6FCField(owner, unsigned char*, 0x46) = old;
                }
                if ((Actor40B6FCField(tag, short*, 0xA) < 15) ||
                    (temp_a0_3 = Actor40B6FCField(Actor40B6FCD_80070328, int*, 0x44) + 0x80,
                     ((({
                          register int pred __asm__("$2") = distanceResult < temp_a0_3;
                          MATCHING_KEEP(pred);
                          pred;
                      })) == 0)) ||
                    (temp_v1_5 = Actor40B6FCField(Actor40B6FCD_80070328, int*, 8) -
                                 Actor40B6FCField(owner, int*, 0x14),
                     ((temp_v1_5 < temp_a0_3) == 0)) ||
                    (-Actor40B6FCField(Actor40B6FCD_80070328, int*, 0x44) >= temp_v1_5)) {
                    var_v0_2 = thirty < Actor40B6FCField(tag, short*, 0xA);
                    if (var_v0_2)
                        Actor40B6FCField(owner, unsigned char*, 0x48) = 4;
                    goto block_75;
                }
                goto block_70;
            block_70:
                Actor40B6FCField(owner, unsigned char*, 0x48) = 4;
                goto block_75;
            case 4: /* switch 1 */
            {
                register void* pointer2 __asm__("$2") = Actor40B6FCD_8006C65C;
                MATCHING_KEEP(pointer2);
                if (pointer2) {
                    register unsigned char* ref3 __asm__("$3") = *(unsigned char**)pointer2;
                    if (Actor40B6FCField(ref3, void**, 20) == owner)
                        Actor40B6FCField(ref3, void**, 20) = 0;
                }
            }
                Actor40B6FCRefreshMobySpatialGridAndBasis(owner, 4);
                Actor40B6FCSpawnParticle(4, 12, owner,
                                         Actor40B6FCField(owner, unsigned char*, 0x49));
                Actor40B6FCHelper36E60(owner);
                Actor40B6FCPlayMobySoundEvent(owner, 0, 0);
                Actor40B6FCDeleteMoby(owner);
                goto block_75;
        }
    block_75:;
    }
}
#undef Actor40B6FCField


typedef struct {
    int timer;
    Colour* colours;
} DecodedColourFadeTag;
extern int D_8006C648;
void func_80055B18(Moby*);
void func_level_40_8007BCF4(Moby* moby) {
    DecodedColourFadeTag* tag = moby->mobyTag;
    int timer = tag->timer + D_8006C648;
    Colour colour;
    tag->timer = timer;
    if (timer >= 30) {
        func_80055B18(moby);
    } else {
        int factor = ((30 - timer) << 8) / 30;
        colour.r = (factor * tag->colours[moby->substate].r) >> 8;
        colour.g = (factor * tag->colours[moby->substate].g) >> 8;
        colour.b = (factor * tag->colours[moby->substate].b) >> 8;
        moby->size = factor;
        moby->angle.yaw = (moby->substate << 8) / 6;
        moby->colour.r = colour.r;
        moby->colour.g = colour.g;
        moby->colour.b = colour.b;
        moby->colour.a = 0;
        moby->lowDrawDistance = 0x10;
    }
}

typedef struct {
    int timer;
    Colour* colours;
    unsigned char* secondary;
    Vector3D velocity;
} DecodedColourTimer;
extern int D_8006C648;
void func_800509E8(void*);
void func_level_40_8007BE30(Moby* moby) {
    DecodedColourTimer* tag = moby->mobyTag;
    Colour colour;
    int scale;
    tag->timer += D_8006C648;
    if (tag->timer >= 0x3C) {
        if (tag->secondary)
            func_800509E8(tag->secondary);
        func_80055B18(moby);
        return;
    }
    tag->velocity.z -= 8;
    func_8004F194(&moby->position, &moby->position, &tag->velocity);
    scale = ((0x3C - tag->timer) << 8) / 0x3C;
    colour.r = (scale * tag->colours[moby->substate].r) >> 8;
    colour.g = (scale * tag->colours[moby->substate].g) >> 8;
    colour.b = (scale * tag->colours[moby->substate].b) >> 8;
    moby->colour.r = colour.r;
    moby->colour.g = colour.g;
    moby->colour.b = colour.b;
    moby->colour.a = 0;
    if (tag->secondary) {
        tag->secondary[0x68] = colour.r;
        tag->secondary[0x69] = colour.g;
        tag->secondary[0x6A] = colour.b;
    }
}

extern Moby* D_8006C550;
extern unsigned char D_80071570[];
typedef struct {
    unsigned char reserved00[0x2C];
    int poolIndex;
} DecodedPoolSelector;
typedef struct {
    unsigned char reserved00[0x0C];
    int flagOffset;
} DecodedPoolFlagSelector;
void func_800584BC(int, int);
void func_80055B18(Moby*);
void func_level_40_8007BFC0(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (D_80071570[((DecodedPoolFlagSelector*)D_8006C550
                                [((DecodedPoolSelector*)D_8006C550[*tag].mobyTag)->poolIndex]
                                    .mobyTag)
                               ->flagOffset])
                goto release;
            func_8004F178(&D_8006C550[*tag].position, &moby->position);
            D_8006C550[*tag].position.z += 128;
            D_8006C550[*tag].angle.yaw = moby->angle.yaw;
            func_80055D24(&D_8006C550[*tag], 2);
            moby->state = 1;
            break;
        case 1:
            if (D_80071570[((DecodedPoolFlagSelector*)D_8006C550
                                [((DecodedPoolSelector*)D_8006C550[*tag].mobyTag)->poolIndex]
                                    .mobyTag)
                               ->flagOffset])
                moby->state = 2;
            break;
        case 2:
            func_800584BC(6, 80);
        release:
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level40
 * original8007C1C0 complete298 instructions, sibling4516 and original assembly.
 * Verified42 helper-call and pool producer C reused. Original40 controls
 * every raw linked field, branch and helper argument. Units, semantic helper
 * meanings, incoming linked argument on negative index and cadence unresolved.
 * Accept only every original native/linked word and every retail hash. */
#define Actor40C1C0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Actor40C1C0Flags __asm__("D_8006C7B4");
extern unsigned char Actor40C1C0Levels[] __asm__("D_80070300");
extern int Actor40C1C0Level __asm__("D_8006C58C");
extern int Actor40C1C0Mode __asm__("D_8006E344");
extern unsigned char* Actor40C1C0Pool __asm__("D_8006C550");
extern int Actor40C1C0PlayerFlags __asm__("D_80070328 + 0x20C");
int Actor40C1C0Helper37BBC() __asm__("func_80037BBC");
int Actor40C1C0Helper512E4() __asm__("func_800512E4");
int Actor40C1C0Helper35A80() __asm__("func_80035A80");
int Actor40C1C0ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor40C1C0RequestMobyAnimation() __asm__("func_80034F40");
int Actor40C1C0DeleteMoby() __asm__("func_80055B18");
int Actor40C1C0Helper492DC() __asm__("func_800492DC");
extern void* (*Actor40C1C0SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
extern unsigned char Actor40C1C0LevelByte __asm__("D_80066FCC + 0x2F");
extern unsigned char Actor40C1C0Table[] __asm__("D_80071570");
extern unsigned char Actor40C1C0Camera[] __asm__("D_8006E17C");
extern int Actor40C1C0CameraMode __asm__("D_8006E160");
int Actor40C1C0CopyVector() __asm__("func_8004F178");
int Actor40C1C0Helper136F0() __asm__("func_800136F0");
void func_level_40_8007C1C0(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$18");
    register unsigned char* camera __asm__("$16");
    register unsigned char* linked5 __asm__("$5");
    register int one4 __asm__("$4");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int playerFlags6 __asm__("$6");
    register void* call4 __asm__("$4");
    register int call5 __asm__("$5");
    __asm__("" : "=r"(owner), "=r"(linked5) : "0"(owner));
    tag = Actor40C1C0Field(owner, unsigned char**, 0);
    work3 = Actor40C1C0Field(tag, int*, 0x2C);
    MATCHING_KEEP(work3);
    if (work3 >= 0)
        linked5 = Actor40C1C0Field(Actor40C1C0Pool + work3 * 88, unsigned char**, 0);
    work3 = Actor40C1C0Field(owner, unsigned char*, 0x48);
    one4 = 1;
    MATCHING_KEEP2(work3, one4);
    if (work3 == one4)
        goto state1;
    if (work3 < 2) {
        if (!work3)
            goto state0;
        goto tail;
    }
    if (work3 == 2)
        goto state2;
    goto tail;
state0:
    work3 = Actor40C1C0Field(owner, unsigned char*, 0x49);
    MATCHING_KEEP(work3);
    if (work3 == one4)
        goto sub1;
    if (work3 < 2) {
        if (!work3)
            goto sub0;
        goto tail;
    }
    if (work3 == 4)
        goto sub4;
    goto tail;
sub0:
    work2 = Actor40C1C0Field(linked5, int*, 12);
    if (work2 >= 0 && Actor40C1C0Table[work2])
        goto remove;
    Actor40C1C0Field(owner, unsigned char*, 0x49) = 4;
    goto tail;
sub1:
    if (!(Actor40C1C0Levels[Actor40C1C0LevelByte] & 1))
        Actor40C1C0PlayerFlags = 0x10000002;
    if (Actor40C1C0Helper37BBC(owner, 0)) {
        Actor40C1C0Helper512E4(owner, 0, 1);
        Actor40C1C0Field(owner, unsigned char*, 0x48) = 1;
    }
    goto tail;
sub4:
    if (!Actor40C1C0Table[Actor40C1C0Field(linked5, int*, 12)])
        goto tail;
    work2 = Actor40C1C0Levels[Actor40C1C0LevelByte] & 1;
    MATCHING_KEEP_CLOBBER(work2, "$6");
    playerFlags6 = 0x10000000;
    if (work2)
        goto finishFlags;
    {

        work2 = Actor40C1C0Field(tag, int*, 0x38);
        __asm__("" : "=r"(work2) : "0"(work2), "r"(playerFlags6));
        playerFlags6 |= 2;
        if (work2) {
            camera = Actor40C1C0Camera;
            linked5 = Actor40C1C0Field((void*)work2, unsigned char**, 12);
            Actor40C1C0CopyVector(camera, linked5 + 16);
            linked5 = Actor40C1C0Field(Actor40C1C0Field(tag, void**, 0x38), unsigned char**, 12);
            Actor40C1C0Helper136F0(camera - 20, linked5, linked5 + 16);
            Actor40C1C0CameraMode = 17;
            MATCHING_BARRIER_VOLATILE("memory");
            playerFlags6 = 0x10000000;
        finishFlags:
            playerFlags6 |= 2;
        }
    }
    work2 = Actor40C1C0Field(tag, int*, 0x30);
    __asm__("" : "=r"(work2) : "0"(work2) : "$4", "$5");
    call4 = owner;
    Actor40C1C0Field((void*)work2, short*, 2) = 0;
    work3 = Actor40C1C0Field(tag, int*, 0x30);
    Actor40C1C0Field((void*)work3, short*, 10) = 1;
    work2 = Actor40C1C0Field(owner, int*, 20);
    MATCHING_KEEP_CLOBBER(work2, "$5");
    call5 = 2;
    Actor40C1C0Field(owner, int*, 20) = work2 - 128;
    Actor40C1C0PlayerFlags = playerFlags6;
    Actor40C1C0Field(owner, unsigned char*, 0x48) = 2;
    goto call2;
    goto tail;
state1:
    if (Actor40C1C0Mode == one4)
        goto tail;
    if (Actor40C1C0Field(tag, void**, 0x30)) {
        work2 = Actor40C1C0Field(tag, int*, 0x38);
        call4 = owner;
        MATCHING_KEEP(call4);
        if (work2) {
            camera = Actor40C1C0Camera;
            linked5 = Actor40C1C0Field((void*)work2, unsigned char**, 12);
            Actor40C1C0CopyVector(camera, linked5 + 16);
            linked5 = Actor40C1C0Field(Actor40C1C0Field(tag, void**, 0x38), unsigned char**, 12);
            Actor40C1C0Helper136F0(camera - 20, linked5, linked5 + 16);
            Actor40C1C0CameraMode = 17;
        }
        call4 = owner;
        call5 = 2;
        MATCHING_KEEP2(call4, call5);
        Actor40C1C0Field(owner, unsigned char*, 0x49) = 1;
        Actor40C1C0Field(owner, unsigned char*, 0x48) = 2;
        goto call2;
    }
    Actor40C1C0Field(owner, unsigned char*, 0x48) = 0;
    Actor40C1C0Field(tag, int*, 0x28) = 3;
    goto tail;
state2:
    work3 = Actor40C1C0Field(owner, unsigned char*, 0x49);
    MATCHING_KEEP(work3);
    if (work3 == one4)
        goto first;
    if (work3 == 4)
        goto fourth;
    goto tail;
first:
    if (!(Actor40C1C0Helper35A80(owner, Actor40C1C0Field(tag, void**, 0x30), 512, 128, 0, 8, 12,
                                 5) &
          1))
        goto player;
    if (Actor40C1C0Field(Actor40C1C0Field(tag, void**, 0x30), short*, 2))
        goto player;
    if (Actor40C1C0Field(tag, void**, 0x38))
        Actor40C1C0CameraMode = 0;
remove:
    Actor40C1C0DeleteMoby(owner);
    return;
player:
    Actor40C1C0PlayerFlags = 0x10000002;
    Actor40C1C0Helper492DC(owner + 12);
    goto tail;
fourth:
    if (!(Actor40C1C0Levels[Actor40C1C0LevelByte] & 1))
        Actor40C1C0PlayerFlags = 0x10000002;
    if (Actor40C1C0Helper35A80(owner, Actor40C1C0Field(tag, void**, 0x30), 512, 128, 0, 8, 12, 5) &
        1) {
        call4 = owner;
        call5 = 0;
        MATCHING_KEEP2(call4, call5);
        Actor40C1C0Field(owner, unsigned char*, 0x49) = 1;
        Actor40C1C0Field(owner, unsigned char*, 0x48) = 0;
        goto call2;
    }
    goto tail;
    goto tail;
call2:
    Actor40C1C0RequestMobyAnimation(call4, call5);
tail:
    work3 = Actor40C1C0Field(tag, int*, 0x2C);
    if (work3 < 0)
        return;
    if (Actor40C1C0Field(owner, unsigned char*, 0x48) < 2)
        return;
    if (Actor40C1C0ApproximatePlanarDistance(owner + 12, Actor40C1C0Pool + work3 * 88 + 12) < 512)
        Actor40C1C0SpawnParticle(2, 12, Actor40C1C0Pool + Actor40C1C0Field(tag, int*, 0x2C) * 88,
                                 (void*)5);
}
#undef Actor40C1C0Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C668.
* AI generated; not human reviewed. All697 instructions,five selectors and
* one zero pad require every native/linked word and actual target:703 words.
* Frame80 preserves S0..S5/RA and original SP20..5F workspace.
* Original state>=5 enters635 with the byte already loaded;normal cleanup
* reloads634. The byte remains V1 while the full switch index uses V0.
* The signed/360 dividend is the old timer word at317,independent of its
* update323/324. Old359/step1 yields timer360,target236;using new360 would
* give235. The ordinary whole quotient reuses verified715 allocation and
* preserves original V0 intermediates,S4 result and all original words.
* Complete modulo retains every zero/signed overflow check. Descriptor,
* complete remainder,S0 index/address and independent caller-input phases
* remain disjoint. Full phases avoid cached T0 pointers and early load-delay
* consumers. Late shared angle/cleanup/countdown entries retain their exact
* targets. First38BF8 receives the original incoming owner and four arguments.
* Empty metadata consumes complete initialized values or clobbers only dead
* words before new complete producers;zero CPU instructions. No partialHI,
* fixedFP,undefined saved inputs,live alias overlap or pipeline changes.
* Helper views reuse original EXE/headers. Physical units/fixed point,full
* helper/caller chains,cadence beyond invocation and synchronized runtime
* remain open. Confidence is binary identity after all gates. Next:human
* review and retail captures. Falsification:every original native/linked
* word,actual target,owned data and full EXE/every-overlay retail hashes.
*/
/* Original assembly SHA256 5bd481cffdd9b6c0e3cdda4b855b9fd793f55fb36788e6b0d3ff0c3848111f5a */
#define Level40_7C668Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level40_7C668Call13D44View1() __asm__("func_80013D44");
int Level40_7C668RequestMobyAnimationView1() __asm__("func_80034F40");
int Level40_7C668Call35194View1() __asm__("func_80035194");
int Level40_7C668TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level40_7C668CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level40_7C668Call35A80View1() __asm__("func_80035A80");
int Level40_7C668RandBetweenView1() __asm__("func_8003636C");
int Level40_7C668Call369B8View1() __asm__("func_800369B8");
int Level40_7C668Call37014View1() __asm__("func_80037014");
int Level40_7C668Call38BF8View1() __asm__("func_80038BF8");
int Level40_7C668Call3BA00View1() __asm__("func_8003BA00");
int Level40_7C668PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level40_7C668PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level40_7C668ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Level40_7C668CopyVectorView1() __asm__("func_8004F178");
int Level40_7C668AddVectorView1() __asm__("func_8004F194");
int Level40_7C668SubtractVectorView1() __asm__("func_8004F1C8");
int Level40_7C668AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level40_7C668ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level40_7C668DeleteMobyView1() __asm__("func_80055B18");
int Level40_7C668RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level40_7C668InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Level40_7C668Data66FCCView1 __asm__("D_80066FCC");
extern int Level40_7C668Data6C550View1 __asm__("D_8006C550");
extern int Level40_7C668Data6C58CView1 __asm__("D_8006C58C");
extern int Level40_7C668Data6C648View1 __asm__("D_8006C648");
extern int Level40_7C668Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level40_7C668Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level40_7C668Data6E048View1 __asm__("D_8006E048");
extern int Level40_7C668Data70300View1 __asm__("D_80070300");
extern int Level40_7C668Data70328View1 __asm__("D_80070328");
void func_level_40_8007C668(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord19 __asm__("$19");
    register int privateRecord18 __asm__("$18"),
        retainedRemainderAddressOrDistance16 __asm__("$16"),
        retainedPlayerBaseHeadingOrPosition17 __asm__("$17"), retainedOriginalQuotientTarget,
        retainedOriginalPlayerBase21 __asm__("$21");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C;
    } originalFrame;
    int temporaryWord13;
    int temporaryWord15;
    int temporaryWord17;
    int temporaryWord19;
    int temporaryWord9;
    int temporaryWord11;
    int temporaryWord7;
    int temporaryWord18;
    int temporaryWord14;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord8;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord16;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    privateRecord18 = Level40_7C668Field(ownerRecord19, void**, 0);
    if (((unsigned int)(Level40_7C668Field(ownerRecord19, unsigned char*, 0x48) - 3) >= 2U) &&
        (Level40_7C668Field(ownerRecord19, int*, 0x18) != 0)) {
        Level40_7C668Call38BF8View1(ownerParameter, privateRecord18 + 24, 1, 3);
        Level40_7C668Field(privateRecord18, signed char*, 0x2B) = 0;
    }
    rawWord3 = Level40_7C668Field(ownerRecord19, unsigned char*, 72);
    MATCHING_KEEP(rawWord3);
    switch (rawWord3) {
        case 0:
        case 1:
            MATCHING_OBSERVE_VOLATILE(rawWord3);
            temporaryWord14 = Level40_7C668Field(ownerRecord19, unsigned char*, 0x49);
            switch (temporaryWord14) {
                case 0:
                    if ((Level40_7C668Data6C7B4View1 & 4) ||
                        (Level40_7C668Field((int)&Level40_7C668Data70300View1, unsigned char*,
                                            Level40_7C668Data6C58CView1) &
                         4)) {
                        temporaryWord1 = (Level40_7C668Field(privateRecord18, int*, 4) * 0x58) +
                                         Level40_7C668Data6C550View1;
                        if (!(Level40_7C668Field(temporaryWord1, unsigned char*, 0x48) & 0x80)) {
                            Level40_7C668DeleteMobyView1(temporaryWord1);
                        }
                        Level40_7C668DeleteMobyView1(ownerRecord19);
                        return;
                    }
                    if (Level40_7C668Field((int)&Level40_7C668Data70300View1, unsigned char*,
                                           Level40_7C668Field((int)&Level40_7C668Data66FCCView1,
                                                              unsigned char*, 0x2F)) != 0) {
                        rawWord2 = Level40_7C668Field(privateRecord18, int*, 20);
                        rawWord3 = Level40_7C668Field(privateRecord18, int*, 4);
                        retainedRemainderAddressOrDistance16 = Level40_7C668Data6C550View1;
                        argumentWord5 = Level40_7C668Field(rawWord2, int*, 12);
                        rawWord2 = rawWord3 * 88;
                        retainedRemainderAddressOrDistance16 += rawWord2;
                        argumentWord5 += 16;
                        Level40_7C668CopyVectorView1(&originalFrame.sp20, argumentWord5);
                        Level40_7C668CopyVectorView1(retainedRemainderAddressOrDistance16 + 0xC,
                                                     &originalFrame.sp20);
                        Level40_7C668Call37014View1(retainedRemainderAddressOrDistance16);
                        Level40_7C668Field(retainedRemainderAddressOrDistance16, unsigned char*,
                                           0x52) = 0xFE;
                        Level40_7C668RefreshMobySpatialGridAndBasisView1(
                            retainedRemainderAddressOrDistance16, 2);
                        Level40_7C668Field(retainedRemainderAddressOrDistance16, signed char*,
                                           0x48) = 0;
                        temporaryWord8 = Level40_7C668Field(
                            Level40_7C668Field(privateRecord18, void**, 0x14), void**, 0xC);
                        argumentWord7 = Level40_7C668Field(temporaryWord8, int*, 0x10);
                        argumentWord4 = Level40_7C668Field(temporaryWord8, int*, 0);
                        rawWord3 = Level40_7C668Field(temporaryWord8, int*, 0x14);
                        argumentWord5 = Level40_7C668Field(temporaryWord8, int*, 4);
                        argumentWord6 = 0;
                        goto block_58;
                    }
                    Level40_7C668Field(ownerRecord19, unsigned char*, 0x55) = 128;
                    Level40_7C668Field(ownerRecord19, unsigned char*, 0x56) = 192;
                    Level40_7C668Field(ownerRecord19, signed char*, 0x54) = 0;
                    Level40_7C668Field(ownerRecord19, signed char*, 0x57) = 0;
                    Level40_7C668Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                    temporaryWord2 = Level40_7C668Data6C550View1 +
                                     (Level40_7C668Field(privateRecord18, int*, 4) * 0x58);
                    Level40_7C668Field(temporaryWord2, signed char*, 0x48) = 6;
                    Level40_7C668Field(temporaryWord2, int*, 0x1C) =
                        (int)(Level40_7C668Field(temporaryWord2, int*, 0x1C) & 0x7FFFFFFF);
                default:
                    goto callOriginalLateCleanup634;
                case 1:
                    argumentWord4 = (int)&originalFrame.sp30;
                    MATCHING_KEEP_CLOBBER(argumentWord4, "$17");
                    retainedPlayerBaseHeadingOrPosition17 = (int)&Level40_7C668Data70328View1 + 152;
                    Level40_7C668CopyVectorView1(argumentWord4,
                                                 retainedPlayerBaseHeadingOrPosition17);
                    originalFrame.sp30 *= 0x14;
                    originalFrame.sp34 *= 0x14;
                    originalFrame.sp38 *= 0x14;
                    Level40_7C668ShiftVectorRightTowardZeroView1(&originalFrame.sp30, 6);
                    argumentWord4 = (int)&originalFrame.sp30;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord5 = (int)&originalFrame.sp30;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4),
                              "r"(retainedPlayerBaseHeadingOrPosition17));
                    retainedPlayerBaseHeadingOrPosition17 -= 152;
                    Level40_7C668AddVectorView1(argumentWord4, argumentWord5,
                                                retainedPlayerBaseHeadingOrPosition17);
                    if (({
                            rawWord2 = Level40_7C668ApproximatePlanarDistanceView1(
                                (int)ownerRecord19 + 12, &originalFrame.sp30);
                            argumentWord4 = (int)&originalFrame.sp40;
                            rawWord2;
                        }) < 6144) {
                        temporaryWord5 = Level40_7C668Field(privateRecord18, void**, 0);
                        argumentWord6 = Level40_7C668Field(temporaryWord5, short*, 2);
                        MATCHING_KEEP(argumentWord6);
                        temporaryWord15 = Level40_7C668Field(temporaryWord5, short*, 0);
                        retainedRemainderAddressOrDistance16 =
                            (int)(argumentWord6 + Level40_7C668Field(temporaryWord5, short*, 0xA) +
                                  temporaryWord15) %
                            temporaryWord15;
                        __asm__ volatile("" ::: "$5", "memory");
                        argumentWord5 = retainedPlayerBaseHeadingOrPosition17;
                        __asm__(""
                                : "=r"(retainedRemainderAddressOrDistance16)
                                : "0"(retainedRemainderAddressOrDistance16), "r"(argumentWord5));
                        rawWord2 = Level40_7C668Field(temporaryWord5, int*, 12);
                        argumentWord6 *= 16;
                        argumentWord6 = rawWord2 + argumentWord6;
                        Level40_7C668SubtractVectorView1(argumentWord4, argumentWord5,
                                                         argumentWord6, temporaryWord5);
                        retainedPlayerBaseHeadingOrPosition17 =
                            Level40_7C668PlanarHeadingLookupView1(originalFrame.sp40,
                                                                  originalFrame.sp44, 0);
                        rawWord2 = Level40_7C668Field(privateRecord18, int*, 0);
                        rawWord3 = Level40_7C668Field(rawWord2, int*, 12);
                        rawWord2 = Level40_7C668Field(rawWord2, short*, 2);
                        __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
                        argumentWord6 = 0;
                        rawWord2 *= 16;
                        rawWord2 += rawWord3;
                        argumentWord4 = Level40_7C668Field(rawWord2, int*, 0);
                        argumentWord5 = Level40_7C668Field(rawWord2, int*, 4);
                        MATCHING_KEEP_CLOBBER(retainedRemainderAddressOrDistance16, "memory");
                        retainedRemainderAddressOrDistance16 =
                            retainedRemainderAddressOrDistance16 * 16 + rawWord3;
                        MATCHING_KEEP(retainedRemainderAddressOrDistance16);
                        argumentWord7 =
                            Level40_7C668Field(retainedRemainderAddressOrDistance16, int*, 0);
                        rawWord3 =
                            Level40_7C668Field(retainedRemainderAddressOrDistance16, int*, 4);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Level40_7C668PlanarHeadingLookupView1(
                            argumentWord4, argumentWord5, argumentWord6);
                        retainedPlayerBaseHeadingOrPosition17 =
                            Level40_7C668AbsoluteByteAngleDeltaView1(
                                retainedPlayerBaseHeadingOrPosition17, rawWord2);
                        if (retainedPlayerBaseHeadingOrPosition17 >= 0x20) {
                            if (({
                                    rawWord2 = retainedPlayerBaseHeadingOrPosition17 < 96;
                                    MATCHING_KEEP(rawWord2);
                                    rawWord2;
                                }) &&
                                (({
                                     rawWord2 = Level40_7C668PlanarHeadingLookupView1(
                                         -originalFrame.sp40, -originalFrame.sp44, 0);
                                     retainedPlayerBaseHeadingOrPosition17 =
                                         (rawWord2 -
                                          Level40_7C668Field((int)&Level40_7C668Data70328View1,
                                                             unsigned char*, 14)) &
                                         255;
                                     MATCHING_KEEP(retainedPlayerBaseHeadingOrPosition17);
                                     ({
                                         rawWord2 = retainedPlayerBaseHeadingOrPosition17 < 128;
                                         MATCHING_KEEP(rawWord2);
                                         rawWord2;
                                     });
                                 }) != 0)) {
                                Level40_7C668PlayMobySoundEventView1(ownerRecord19, 0, 0);
                                goto reverseOriginalDescriptor256;
                            }
                        } else {
                        reverseOriginalDescriptor256:
                            temporaryWord16 = Level40_7C668Field(privateRecord18, void**, 0);
                            Level40_7C668Field(temporaryWord16, short*, 0xA) =
                                (short)-(short)(unsigned short)Level40_7C668Field(temporaryWord16,
                                                                                  short*, 0xA);
                            temporaryWord3 = Level40_7C668Field(privateRecord18, void**, 0);
                            temporaryWord17 = Level40_7C668Field(temporaryWord3, short*, 0);
                            Level40_7C668Field(temporaryWord3, short*, 2) =
                                (short)((int)(Level40_7C668Field(temporaryWord3, short*, 2) +
                                              (Level40_7C668Field(temporaryWord3, short*, 0xA) *
                                               2) +
                                              temporaryWord17) %
                                        temporaryWord17);
                            Level40_7C668Field(privateRecord18, int*, 8) = 0x1E;
                        }
                        Level40_7C668Field(privateRecord18, int*, 0x10) = 0x100;
                        Level40_7C668Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                        Level40_7C668RequestMobyAnimationView1(ownerRecord19, 2);
                    } else {
                        Level40_7C668TurnMobyTowardPlayerView1(ownerRecord19, 8, 0, 1);
                        if (Level40_7C668Data6C770View1 != 0) {
                            if (Level40_7C668Field(privateRecord18, int*, 8) == 0) {
                                Level40_7C668RequestMobyAnimationView1(ownerRecord19, 1);
                                Level40_7C668Field(privateRecord18, int*, 8) =
                                    Level40_7C668RandBetweenView1(1, 2);
                            } else {
                                Level40_7C668RequestMobyAnimationView1(ownerRecord19, 0);
                                Level40_7C668Field(privateRecord18, int*, 8) =
                                    (int)(Level40_7C668Field(privateRecord18, int*, 8) - 1);
                            }
                        }
                    }
                    goto callOriginalLateCleanup634;
            }
            break;
        case 2:
            if (Level40_7C668Field(ownerRecord19, unsigned char*, 0x49) == 1) {
                rawWord3 = Level40_7C668Field(privateRecord18, int*, 12);
                argumentWord4 = Level40_7C668Data6C648View1;
                argumentWord4 = rawWord3 + argumentWord4;
                Level40_7C668Field(privateRecord18, int*, 12) = argumentWord4;
                argumentWord4 = argumentWord4 < 7201;
                retainedOriginalQuotientTarget = rawWord3 / 360;
                MATCHING_KEEP_CLOBBER(retainedOriginalQuotientTarget, "$2");
                rawWord2 = 236;
                retainedOriginalQuotientTarget = rawWord2 - retainedOriginalQuotientTarget;
                if (!argumentWord4) {
                    Level40_7C668Field(privateRecord18, int*, 0xC) = 0x1C20;
                }
                argumentWord4 = (int)&originalFrame.sp40;
                MATCHING_KEEP_CLOBBER(argumentWord4, "$17");
                retainedPlayerBaseHeadingOrPosition17 = (int)&Level40_7C668Data70328View1 + 152;
                Level40_7C668CopyVectorView1(argumentWord4, retainedPlayerBaseHeadingOrPosition17);
                originalFrame.sp40 *= 0x14;
                originalFrame.sp44 *= 0x14;
                originalFrame.sp48 *= 0x14;
                Level40_7C668ShiftVectorRightTowardZeroView1(&originalFrame.sp40, 6);
                retainedOriginalPlayerBase21 = retainedPlayerBaseHeadingOrPosition17 - 0x98;
                Level40_7C668AddVectorView1(&originalFrame.sp40, &originalFrame.sp40,
                                            retainedOriginalPlayerBase21);
                retainedPlayerBaseHeadingOrPosition17 = ownerRecord19 + 0xC;
                retainedRemainderAddressOrDistance16 = Level40_7C668ApproximatePlanarDistanceView1(
                    retainedPlayerBaseHeadingOrPosition17, &originalFrame.sp40);
                temporaryWord18 = Level40_7C668Field(privateRecord18, int*, 0x10) + 8;
                Level40_7C668Field(privateRecord18, int*, 0x10) = temporaryWord18;
                if (temporaryWord18 >= 0x101) {
                    Level40_7C668Field(privateRecord18, int*, 0x10) = 0x100;
                }
                if (!(Level40_7C668Call35A80View1(
                          ownerRecord19, Level40_7C668Field(privateRecord18, void**, 0), 0x200,
                          retainedOriginalQuotientTarget, 0,
                          (int)Level40_7C668Field(privateRecord18, int*, 0x10) >> 4, 0x18, 5) &
                      4)) {
                    Level40_7C668Field(privateRecord18, int*, 0x10) = 0;
                }
                rawWord2 = retainedRemainderAddressOrDistance16 < 10241;
                argumentWord4 = privateRecord18 + 8;
                if (rawWord2)
                    goto callOriginalCountdown411;
                rawWord2 = Level40_7C668ApproximatePlanarDistanceView1(
                    retainedPlayerBaseHeadingOrPosition17, retainedOriginalPlayerBase21);
                MATCHING_KEEP(privateRecord18);
                argumentWord4 = privateRecord18 + 8;
                if (rawWord2 < 10241)
                    goto callOriginalCountdown411;
                Level40_7C668Field(privateRecord18, int*, 8) = 2;
                Level40_7C668Field(ownerRecord19, unsigned char*, 72) = 0;
                Level40_7C668RequestMobyAnimationView1(ownerRecord19, 0);
                goto callOriginalLateCleanup634;
                {
                callOriginalCountdown411:
                    Level40_7C668CountTimerDownView1(argumentWord4, 4);
                    temporaryWord6 = Level40_7C668Field(privateRecord18, void**, 0);
                    argumentWord6 = Level40_7C668Field(temporaryWord6, short*, 2);
                    MATCHING_KEEP(argumentWord6);
                    temporaryWord19 = Level40_7C668Field(temporaryWord6, short*, 0);
                    retainedRemainderAddressOrDistance16 =
                        (int)(argumentWord6 + Level40_7C668Field(temporaryWord6, short*, 0xA) +
                              temporaryWord19) %
                        temporaryWord19;
                    __asm__ volatile("" ::: "$4", "$5", "memory");
                    argumentWord4 = (int)&originalFrame.sp20;
                    argumentWord5 = (int)&Level40_7C668Data70328View1;
                    __asm__(""
                            : "=r"(retainedRemainderAddressOrDistance16)
                            : "0"(retainedRemainderAddressOrDistance16), "r"(argumentWord4),
                              "r"(argumentWord5));
                    rawWord2 = Level40_7C668Field(temporaryWord6, int*, 12);
                    argumentWord6 *= 16;
                    argumentWord6 = rawWord2 + argumentWord6;
                    Level40_7C668SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6,
                                                     temporaryWord6);
                    retainedPlayerBaseHeadingOrPosition17 = Level40_7C668PlanarHeadingLookupView1(
                        originalFrame.sp20, originalFrame.sp24, 0);
                    rawWord2 = Level40_7C668Field(privateRecord18, int*, 0);
                    rawWord3 = Level40_7C668Field(rawWord2, int*, 12);
                    rawWord2 = Level40_7C668Field(rawWord2, short*, 2);
                    __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
                    argumentWord6 = 0;
                    rawWord2 *= 16;
                    rawWord2 += rawWord3;
                    argumentWord4 = Level40_7C668Field(rawWord2, int*, 0);
                    argumentWord5 = Level40_7C668Field(rawWord2, int*, 4);
                    MATCHING_KEEP_CLOBBER(retainedRemainderAddressOrDistance16, "memory");
                    retainedRemainderAddressOrDistance16 =
                        retainedRemainderAddressOrDistance16 * 16 + rawWord3;
                    MATCHING_KEEP(retainedRemainderAddressOrDistance16);
                    argumentWord7 =
                        Level40_7C668Field(retainedRemainderAddressOrDistance16, int*, 0);
                    rawWord3 = Level40_7C668Field(retainedRemainderAddressOrDistance16, int*, 4);
                    argumentWord4 = argumentWord7 - argumentWord4;
                    argumentWord5 = rawWord3 - argumentWord5;
                    rawWord2 = Level40_7C668PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                     argumentWord6);
                    rawWord2 = retainedPlayerBaseHeadingOrPosition17 - rawWord2;
                    argumentWord4 = rawWord2 & 255;
                    if (argumentWord4 >= 0x81) {
                        argumentWord4 -= 0x100;
                    }
                    rawWord3 = argumentWord4;
                    if (argumentWord4 < 0) {
                        rawWord3 = -rawWord3;
                    }
                    if (rawWord3 >= 0x20) {
                        if (({
                                rawWord2 = rawWord3 < 80;
                                MATCHING_KEEP(rawWord2);
                                rawWord2;
                            }) &&
                            (Level40_7C668Field(privateRecord18, int*, 8) == 0)) {
                            rawWord2 = Level40_7C668Field((int)&Level40_7C668Data70328View1,
                                                          unsigned char*, 14);
                            rawWord2 = retainedPlayerBaseHeadingOrPosition17 - rawWord2;
                            MATCHING_KEEP(rawWord2);
                            retainedPlayerBaseHeadingOrPosition17 = rawWord2 & 255;
                            if (retainedPlayerBaseHeadingOrPosition17 >= 0x81) {
                                retainedPlayerBaseHeadingOrPosition17 -= 0x100;
                            }
                            if (((argumentWord4 > 0) &&
                                 (retainedPlayerBaseHeadingOrPosition17 > 0)) ||
                                ((argumentWord4 < 0) &&
                                 (retainedPlayerBaseHeadingOrPosition17 < 0))) {
                                Level40_7C668PlayMobySoundEventView1(ownerRecord19, 0, 0);
                                goto reverseOriginalDescriptor507;
                            }
                        }
                    } else {
                    reverseOriginalDescriptor507:
                        temporaryWord12 = Level40_7C668Field(privateRecord18, void**, 0);
                        Level40_7C668Field(temporaryWord12, short*, 0xA) = (short)-(
                            short)(unsigned short)Level40_7C668Field(temporaryWord12, short*, 0xA);
                        temporaryWord4 = Level40_7C668Field(privateRecord18, void**, 0);
                        temporaryWord13 = Level40_7C668Field(temporaryWord4, short*, 0);
                        Level40_7C668Field(temporaryWord4, short*, 2) =
                            (short)((int)(Level40_7C668Field(temporaryWord4, short*, 2) +
                                          (Level40_7C668Field(temporaryWord4, short*, 0xA) * 2) +
                                          temporaryWord13) %
                                    temporaryWord13);
                        Level40_7C668Field(privateRecord18, int*, 8) = 0x1E;
                        Level40_7C668Field(privateRecord18, int*, 0x10) = 0x100;
                    }
                }
            }
            goto callOriginalLateCleanup634;
        case 3:
            Level40_7C668Field((int)&Level40_7C668Data70328View1, int*, 0x20C) = 0x10000002;
            if (Level40_7C668Call35194View1(ownerRecord19, privateRecord18 + 0x18) == 0x100) {
                Level40_7C668CopyVectorView1(
                    &originalFrame.sp20,
                    Level40_7C668Field(Level40_7C668Field(privateRecord18, void**, 0), void**,
                                       0xC));
                originalFrame.sp28 +=
                    Level40_7C668Field((int)&Level40_7C668Data70328View1, int*, 0x44);
                temporaryWord11 =
                    Level40_7C668Field(Level40_7C668Field(privateRecord18, void**, 0), void**, 0xC);
                temporaryWord7 = Level40_7C668Field(temporaryWord11, int*, 0x10);
                Level40_7C668Call13D44View1(
                    &originalFrame.sp20,
                    Level40_7C668PlanarHeadingLookupView1(
                        temporaryWord7 - Level40_7C668Field(temporaryWord11, int*, 0),
                        Level40_7C668Field(temporaryWord11, int*, 0x14) -
                            Level40_7C668Field(temporaryWord11, int*, 4),
                        0),
                    0, 0);
                if (Level40_7C668Field((int)&Level40_7C668Data70328View1, int*, 0x280) < 0) {
                    Level40_7C668Field((int)&Level40_7C668Data70328View1, int*, 0x280) = 0;
                }
                Level40_7C668RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                Level40_7C668Call3BA00View1(ownerRecord19);
                Level40_7C668Call369B8View1(ownerRecord19, 0x20);
                Level40_7C668Field(ownerRecord19, signed char*, 0x41) = 0;
                Level40_7C668Field(ownerRecord19, signed char*, 0x4C) = 0;
                Level40_7C668Field(ownerRecord19, signed char*, 0x4D) = 0;
                Level40_7C668Field(ownerRecord19, unsigned char*, 0x48) = 4U;
            }
            goto callOriginalLateCleanup634;
        case 4:
            if (Level40_7C668Data6E048View1 & 1) {
                rawWord2 = Level40_7C668Field(privateRecord18, int*, 0);
                rawWord3 = Level40_7C668Field(privateRecord18, int*, 4);
                retainedRemainderAddressOrDistance16 = Level40_7C668Data6C550View1;
                argumentWord5 = Level40_7C668Field(rawWord2, int*, 12);
                rawWord2 = rawWord3 * 88;
                retainedRemainderAddressOrDistance16 += rawWord2;
                argumentWord5 += 16;
                Level40_7C668CopyVectorView1(&originalFrame.sp50, argumentWord5);
                Level40_7C668CopyVectorView1(retainedRemainderAddressOrDistance16 + 0xC,
                                             &originalFrame.sp50);
                Level40_7C668Call37014View1(retainedRemainderAddressOrDistance16);
                Level40_7C668Field(retainedRemainderAddressOrDistance16, unsigned char*, 0x52) =
                    0xFE;
                Level40_7C668RefreshMobySpatialGridAndBasisView1(
                    retainedRemainderAddressOrDistance16, 2);
                Level40_7C668Field(retainedRemainderAddressOrDistance16, signed char*, 0x48) = 1;
                temporaryWord9 =
                    Level40_7C668Field(Level40_7C668Field(privateRecord18, void**, 0), void**, 0xC);
                argumentWord6 = 0;
                argumentWord7 = Level40_7C668Field(temporaryWord9, int*, 0);
                argumentWord4 = Level40_7C668Field(temporaryWord9, int*, 0x10);
                rawWord3 = Level40_7C668Field(temporaryWord9, int*, 4);
                argumentWord5 = Level40_7C668Field(temporaryWord9, int*, 0x14);
            block_58:
                argumentWord4 = argumentWord7 - argumentWord4;
                argumentWord5 = rawWord3 - argumentWord5;
                rawWord2 = Level40_7C668PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                 argumentWord6);
                argumentWord4 = (int)ownerRecord19;
                Level40_7C668Field(retainedRemainderAddressOrDistance16, signed char*, 70) =
                    rawWord2;
                Level40_7C668DeleteMobyView1(argumentWord4);
                return;
            }
            goto callOriginalLateCleanup634;
        callOriginalLateCleanup634:
            rawWord3 = Level40_7C668Field(ownerRecord19, unsigned char*, 72);
        checkOriginalPreparedDefault635:
            MATCHING_BARRIER_VOLATILE("$2");
            if (rawWord3 != 4) {
                Level40_7C668RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                Level40_7C668InterpolateMobyVertexView1(
                    ownerRecord19, 0,
                    Level40_7C668Data6C550View1 +
                        (Level40_7C668Field(privateRecord18, int*, 4) * 0x58) + 0xC);
                temporaryWord10 = (Level40_7C668Field(privateRecord18, int*, 4) * 0x58) +
                                  Level40_7C668Data6C550View1;
                Level40_7C668Field(temporaryWord10, int*, 0x14) =
                    (int)(Level40_7C668Field(temporaryWord10, int*, 0x14) - 0x80);
                Level40_7C668Field(((Level40_7C668Field(privateRecord18, int*, 4) * 0x58) +
                                    Level40_7C668Data6C550View1),
                                   unsigned char*, 0x52) = 0xFE;
                Level40_7C668Field(((Level40_7C668Field(privateRecord18, int*, 4) * 0x58) +
                                    Level40_7C668Data6C550View1),
                                   unsigned char*, 0x46) =
                    (unsigned char)Level40_7C668Field(ownerRecord19, unsigned char*, 0x46);
            }
            return;
        default:
            goto checkOriginalPreparedDefault635;
    }
}
#undef Level40_7C668Field

extern ProgressFlags progressFlags;
extern struct {
    int DAT_80070104;      // 80070104
    int DAT_80070108;      // 80070108
    int DAT_8007010c;      // 8007010c
    int DAT_80070110;      // 80070110
    char DAT_80070114;     // 80070114
    char DAT_80070115;     // 80070115
    short DAT_80070116;    // 80070116, maybe char?
    int DAT_80070118;      // 80070118
    int DAT_8007011c;      // 8007011c
    int DAT_80070120;      // 80070120
    Vector3D DAT_80070124; // 80070124, type is a guess
    char DAT_80070130;     // 80070130
    char DAT_80070131;     // 80070131
    char DAT_80070132;     // 80070132
    char DAT_80070133;     // 80070133
    short DAT_80070134;    // 80070134
    short DAT_80070136;    // 80070136
    int DAT_80070138;      // 80070138
    int DAT_8007013c;      // 8007013c
    int DAT_80070140;      // 80070140
    int DAT_80070144;      // 80070144
    int DAT_80070148;      // 80070148
    short DAT_8007014c;    // 8007014c
    char DAT_8007014e;     // 8007014e
    char DAT_8007014f;     // 8007014f
    int DAT_80070150;      // 80070150
    int DAT_80070154;      // 80070154
    short DAT_80070158;    // 80070158
    short loadLevel;       // 8007015a; i.e. to load via vehicle
    int DAT_8007015c;      // 8007015c
} D_80070104;
extern int D_8006C598, D_8006C73C, D_8006C528, currentLevel;
extern short D_800658A0[256], D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
extern int Vehicle506Global __asm__("D_80070148");
void func_8005663C(void);
int func_8001A358(Vector3D*, int);
/* AI generated adaptation; not human reviewed. SCUS-94467 level10 8007F0BC. */
typedef struct {
    int unk0, unk4, unk8;
    PathTag* path;
    int timer;
} Vehicle546Tag;
extern unsigned char Vehicle546Table[] __asm__("D_80071FB0");
void func_level_40_8007D14C(Moby* arg0) {
    Vector3D sp10, sp20, sp30, sp40, sp50;
    int temp_v1_3, count;
    Vehicle546Tag* mobyTag = (Vehicle546Tag*)arg0->mobyTag;
    switch (arg0->state) {
        case 0:
            switch (arg0->substate) {
                case 0:
                    if (progressFlags.lvl20_WhirligigUsable)
                        goto deleteVehicle;
                    if (D_8006C73C != 0 && currentLevel != D_8006C73C &&
                        ((temp_v1_3 = D_8006C73C % 10, temp_v1_3 == 0) ||
                         (temp_v1_3 == 7 && D_8006C73C < 60))) {
                        arg0->position.z += 0xC00;
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &arg0->position);
                        camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        func_8004F178(&spyro.position, &arg0->position);
                        spyro.position.z += spyro.unk4a + 0x280;
                        func_80012BA8(&camera.unk170);
                        func_8004F178(&camera.unk184, &camera.unk60);
                        arg0->substate = 1;
                        arg0->state = 7;
                    } else {
                        count = eggsCollectedArray[lvlIdToIndex[21]] & 1;
                        if (eggsCollectedArray[lvlIdToIndex[22]] & 1)
                            count++;
                        if (eggsCollectedArray[lvlIdToIndex[23]] & 1)
                            count++;
                        if (eggsCollectedArray[lvlIdToIndex[24]] & 1)
                            count++;
                        if (eggsCollectedArray[lvlIdToIndex[26]] & 1)
                            count++;
                        if (count == 5) {
                        deleteVehicle:
                            func_80055B18(arg0);
                            return;
                        }
                        if (currentLevel != 10 || Vehicle546Table[lvlIdToIndex[17]] != 0) {
                            arg0->substate = 1;
                            arg0->state = 3;
                        } else {
                            arg0->substate = 2;
                            arg0->state = 1;
                            arg0->position.z += 0xC00;
                        }
                        func_80055D24(arg0, 2);
                        mobyTag->timer = 0;
                    }
                    break;
                case 1:
                    arg0->state = 3;
                    break;
                case 2:
                    arg0->position.z += 0xC00;
                    func_80055D24(arg0, 2);
                    mobyTag->timer = 0;
                    arg0->state = 1;
                    break;
            }
            func_8003B7B4(&arg0->substate, 1, &unsavedData);
            break;
        case 2:
            arg0->position.z -= 64;
            func_8004F178(&sp10, &arg0->position);
            sp10.z += 512;
            sp10.z = func_8001A358(&sp10, 512);
            if (sp10.z != 0) {
                arg0->position.z = sp10.z;
                arg0->state = 3;
                func_8003B7B4(&arg0->state, 1, &savedData);
                func_8003B7B4(&arg0->state, 1, &unsavedData);
                arg0->substate = 0;
            }
            func_80055D24(arg0, 2);
            break;
        case 3:
            if (spyro.m_StoodOnMoby == arg0) {
                arg0->state = 4;
                case 4:
                    if (spyro.m_StoodOnMoby != arg0) {
                        camera.unk168 = 0;
                        arg0->state = 3;
                    } else {
                        if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                            Vehicle506Global = 1;
                            func_8005663C();
                            arg0->state = 5;
                        }
                        func_8004F178(&camera.unk184, &arg0->position);
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &arg0->position);
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        camera.unk168 = 0x11;
                    }
            }
            break;

        case 5:
            camera.unk168 = 0;
            if (D_80070104.loadLevel != 0) {
                mobyTag->timer = 0x78;
                arg0->state = 6;
            } else {
                arg0->state = 8;
            }
            break;

        case 6:
            arg0->position.z = (int)(arg0->position.z + 0x40);
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x280;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &arg0->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
            camera.unk170.yaw = 0;
            camera.unk170.pitch = 0;
            camera.unk168 = 0x11;
            if (func_800359A4(&mobyTag->timer, 4) != 0) {
                D_8006C598 += 0x10;
                if (D_8006C598 >= 0xFF) {
                    D_8006C598 = 0xFF;
                    if ((D_80070104.loadLevel == 0x14) &&
                        (eggsCollectedArray[lvlIdToIndex[17]] == 0)) {
                        D_80070104.loadLevel = 0x11;
                    }
                    // BUG // Spike Bug
                    // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                    // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                    // This was fixed in all later revisions
                    if ((D_80070104.loadLevel != 0x11) ||
                        (progressFlags.lvl63_BiancaStrikesBack != 0)) {
                        func_80054F94(D_80070104.loadLevel, arg0);
                    } else {
                        progressFlags.lvl63_BiancaStrikesBack = 1;
                        func_800584BC(6, 0x3F);
                    }
                }
            }
            func_80055D24(arg0, 2);
            break;

        case 7:
            arg0->position.z -= 0x40;
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x280;
            spyro.unk18.roll = arg0->angle.roll;
            spyro.unk18.pitch = arg0->angle.pitch;
            spyro.unk18.yaw = arg0->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            func_8004F178(&sp20, &arg0->position);
            sp20.z += 0x200;
            sp20.z = func_8001A358(&sp20, 0x200);
            if (sp20.z != 0) {
                arg0->position.z = sp20.z;
                func_80013B7C(0);
                arg0->state = 8;
            }
            func_80055D24(arg0, 2);
            break;

        case 8:
            sp30.x = D_80065920[arg0->angle.yaw];
            sp30.y = D_800658A0[arg0->angle.yaw];
            sp30.z = 0;
            func_8004F194(&sp30, &sp30, &arg0->position);
            if (ovlHeader.unk2c(&sp30) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp30, arg0->angle.yaw, 0);
                mobyTag->timer = 120;
                arg0->state = 9;
            }
            break;

        case 9:
            sp40.x = D_80065920[arg0->angle.yaw];
            sp40.y = D_800658A0[arg0->angle.yaw];
            sp40.z = 0;
            func_8004F194(&sp40, &sp40, &arg0->position);
            if (ovlHeader.unk2b(&sp40, arg0->angle.yaw, 0) != 0) {
                func_8004F178(&sp50, &spyro.position);
                sp50.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp50, spyro.bodyRotation.yaw);
                arg0->state = 3;
            }
            break;
    }
}

/* AI generated adaptation; not human reviewed. Original SCUS-94467 level10 8007F944. */
typedef struct {
    int unk0;
    PathTag* path;
    int timer;
} Vehicle635Tag;
extern Moby* Vehicle635Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*, int);
void func_level_40_8007D9D4(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3;
    Vehicle635Tag* mobyTag;

    mobyTag = (Vehicle635Tag*)arg0->mobyTag;
    switch (arg0->state) {

        case 0:
            switch (arg0->substate) {
                case 0:
                    if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                        func_80055B18(arg0);
                        return;
                    } else {
                        arg0->state = 1;
                        if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) &&
                            ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) ||
                             ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) &&
                            (arg0->mobyClass == D_8006C528) && D_8006C73C != 47) {
                            func_80034F80(arg0, 2);
                            arg0->position.z += 0xC00;
                            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                          &arg0->position);
                            camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                            camera.unk170.yaw = 0;
                            camera.unk170.pitch = 0;
                            spyro.unk17a = 0x1001A000;
                            spyro.unk20[1] = 0;
                            func_8004F178(&spyro.unk19, &arg0->position);
                            spyro.unk19.z += spyro.unk4a + 0x604;
                            spyro.unk18.roll = arg0->angle.roll;
                            spyro.unk18.pitch = arg0->angle.pitch;
                            spyro.unk18.yaw = arg0->angle.yaw;
                            func_80012BA8(&camera.unk170);
                            func_8004F178(&camera.unk184, &camera.unk60);
                            arg0->state = 8;
                        } else if (arg0->state == 0) {
                            arg0->state = 1;
                        }
                    }
                    break;

                default:
                    break;

                case 1:
                    func_80034F80(arg0, 2);
                    arg0->position.z += 0xF00;
                    func_80055D24(arg0, 2);
                    mobyTag->timer = 0;
                    arg0->state = 10;
                    break;
            }
            break;

        case 1:
            if (spyro.m_StoodOnMoby == arg0) {
                arg0->state = 2;
                case 2:
                    if (spyro.m_StoodOnMoby != arg0) {
                        camera.unk168 = 0;
                        arg0->state = 1;
                    } else {
                        if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                            Vehicle506Global = 1;
                            func_8005663C();
                            arg0->state = 3;
                        }
                        func_8004F178(&camera.unk184, &arg0->position);
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &arg0->position);
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        camera.unk168 = 0x11;
                    }
            }
            break;

        case 3:
            camera.unk168 = 0;
            if (D_80070104.loadLevel != 0) {
                func_80034F40(arg0, 1);
                spyro.unk17a = 0x10018000;
                func_8004F178(&spyro.unk19, &arg0->position);
                spyro.unk19.z += 0x400;
                {
                    int height = func_8001A358(&spyro.unk19, 0x800);
                    spyro.unk20[1] = 0;
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk19.z = height + spyro.unk4a;
                    spyro.unk18.yaw = arg0->angle.yaw;
                }
                arg0->state = 4;
            } else
                arg0->state = 6;
            break;
        case 4:
            spyro.unk17a = 0x10018000;
            spyro.unk19.z += 0x100 - spyro.unk4a;
            {
                int height = func_8001A358(&spyro.unk19, 512);
                spyro.unk20[1] = 0;
                spyro.unk18.roll = 0;
                spyro.unk18.pitch = 0;
                spyro.unk19.z = height + spyro.unk4a;
                spyro.unk18.yaw = arg0->angle.yaw;
            }
            if (D_8006C770 != 0) {
                func_80034F80(arg0, 2);
                spyro.unk17a |= 0x2000;
                if (Vehicle635Moby != 0) {
                    *((unsigned char*)Vehicle635Moby + 0x4C) = 0;
                    *((unsigned char*)Vehicle635Moby + 0x4D) = 0;
                }
                mobyTag->timer = 120;
                arg0->state = 5;
            }
            break;
        case 5:
            arg0->position.z = (int)(arg0->position.z + 0x40);
            spyro.unk17a = 0x1001A000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x604;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &arg0->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
            camera.unk170.yaw = 0;
            camera.unk170.pitch = 0;
            camera.unk168 = 0x11;
            if (func_800359A4(&mobyTag->timer, 4) != 0) {
                D_8006C598 += 0x10;
                if (D_8006C598 >= 0xFF) {
                    D_8006C598 = 0xFF;
                    if ((D_80070104.loadLevel == 0x28) &&
                        (eggsCollectedArray[lvlIdToIndex[37]] == 0)) {
                        D_80070104.loadLevel = 0x25;
                    }
                    // BUG // Spike Bug
                    // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                    // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                    // This was fixed in all later revisions
                    if ((D_80070104.loadLevel != 0x25) ||
                        (progressFlags.lvl67_AMonsterToEndAllMonsters != 0)) {
                        func_80054F94(D_80070104.loadLevel, arg0);
                    } else {
                        progressFlags.lvl67_AMonsterToEndAllMonsters = 1;
                        func_800584BC(6, 0x43);
                    }
                }
            }
            func_80055D24(arg0, 2);
            break;

        case 6:
            sp10.x = D_80065920[arg0->angle.yaw];
            sp10.y = D_800658A0[arg0->angle.yaw];
            sp10.z = 0;
            func_8004F194(&sp10, &sp10, &arg0->position);
            if (ovlHeader.unk2c(&sp10) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp10, arg0->angle.yaw, 0);
                arg0->state = 7;
            }
            break;

        case 7:
            sp20.x = D_80065920[arg0->angle.yaw];
            sp20.y = D_800658A0[arg0->angle.yaw];
            sp20.z = 0;
            func_8004F194(&sp20, &sp20, &arg0->position);
            if (ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0) != 0) {
                func_8004F178(&sp30, &spyro.position);
                sp30.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp30, spyro.bodyRotation.yaw);
                arg0->state = 1;
            }
            break;

        case 8:
            arg0->position.z -= 0x40;
            spyro.unk17a = 0x1001A000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x604;
            spyro.unk18.roll = arg0->angle.roll;
            spyro.unk18.pitch = arg0->angle.pitch;
            spyro.unk18.yaw = arg0->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            func_8004F178(&sp40, &arg0->position);
            arg0->position.z += 0x400;
            sp40.z += 0x200;
            sp40.z = func_8001A358(&sp40, 0x200);
            if (sp40.z != 0) {
                arg0->position.z = sp40.z;
                func_80034F40(arg0, 3);
                spyro.unk17a = 0x10018000;
                func_8004F178(&spyro.unk19, &arg0->position);
                spyro.unk19.z += 0xE00;
                {
                    int height = func_8001A358(&spyro.unk19, 0x800);
                    spyro.unk20[1] = 0;
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk19.z = height + spyro.unk4a;
                    spyro.unk18.yaw = arg0->angle.yaw;
                }
                arg0->state = 9;
            } else {
                arg0->position.z -= 0x400;
            }
            func_80055D24(arg0, 2);
            break;

        case 9:
            spyro.unk17a = 0x10018000;
            spyro.unk19.z += 0x100 - spyro.unk4a;
            {
                int height = func_8001A358(&spyro.unk19, 512);
                spyro.unk20[1] = 0;
                spyro.unk18.roll = 0;
                spyro.unk18.pitch = 0;
                spyro.unk19.z = height + spyro.unk4a;
                spyro.unk18.yaw = arg0->angle.yaw;
            }
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            if (D_8006C770 != 0) {
                func_80034F80(arg0, 0);
                func_80013B7C(0);
                arg0->state = 6;
            }
            break;
    }
    func_80055D24(arg0, 1);
}

extern ProgressFlags progressFlags;

extern int D_8006C598, D_8006C73C, D_8006C528, currentLevel;
extern short D_800658A0[256], D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
/* AI generated adaptation of upstream func_level_17_8007D19C; not human reviewed.
 * Original SCUS-94467 level10 800805A0 instruction route; units/cadence open. */
typedef struct {
    int unk0, unk4;
    PathTag* unk8;
    int unkC, unk10;
} Vehicle506Tag;
extern int Vehicle506Global __asm__("D_80070148");
void func_8005663C(void);
int func_8001A358(Vector3D*, int);
/* AI-generated readability only, not human reviewed. Local names describe
 * typed vectors and the actual remainder; unknown fields/control remain intact.
 * Original instruction/frame/table/helper and complete image gates apply. */
void func_level_40_8007E3C0(Moby* moby) {
    Vector3D vector1;
    Vector3D vector2;
    Vector3D vector3;
    Vector3D vector4;
    int remainder;
    Vehicle506Tag* mobyTag;

    mobyTag = (Vehicle506Tag*)moby->mobyTag;
    switch (moby->state) {

        case 0:
            switch (moby->substate) {
                case 0:
                    if (progressFlags.lvl30_RocketUsable ||
                        ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable)) {
                        func_80055B18(moby);
                        return;
                    } else {
                        if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) &&
                            ((remainder = D_8006C73C % 10, (remainder == 0)) ||
                             ((remainder == 7) && (D_8006C73C < 0x3C))) &&
                            (moby->mobyClass == D_8006C528)) {
                            moby->position.z += 0xC00;
                            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes,
                                          &moby->position);
                            camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                            camera.unk170.yaw = 0;
                            camera.unk170.pitch = 0;
                            spyro.unk17a = 0x10018000;
                            spyro.unk20[1] = 0;
                            func_8004F178(&spyro.unk19, &moby->position);
                            spyro.unk19.z += spyro.unk4a + 0x133;
                            spyro.unk18.roll = moby->angle.roll;
                            spyro.unk18.pitch = moby->angle.pitch;
                            spyro.unk18.yaw = moby->angle.yaw;
                            func_80012BA8(&camera.unk170);
                            func_8004F178(&camera.unk184, &camera.unk60);
                            moby->state = 7;
                        } else if (moby->state == 0) {
                            moby->state = 1;
                        }
                    }
                    break;

                default:
                    break;

                case 1:
                    moby->position.z += 0xF00;
                    func_80055D24(moby, 2);
                    mobyTag->unkC = 0;
                    moby->state = 8;
                    break;
            }
            break;

        case 1:
            if (spyro.m_StoodOnMoby == moby) {
                moby->state = 2;
                case 2:
                    if (spyro.m_StoodOnMoby != moby) {
                        camera.unk168 = 0;
                        moby->state = 1;
                    } else {
                        if (ovlHeader.unk2b(&moby->position, moby->angle.yaw, 0) != 0) {
                            Vehicle506Global = 1;
                            func_8005663C();
                            moby->state = 3;
                        }
                        func_8004F178(&camera.unk184, &moby->position);
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes,
                                      &moby->position);
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        camera.unk168 = 0x11;
                    }
            }
            break;

        case 3:
            camera.unk168 = 0;
            if (D_80070104.loadLevel != 0) {
                mobyTag->unkC = 0x78;
                moby->state = 4;
            } else {
                moby->state = 5;
            }
            break;

        case 4:
            func_80034F40(moby, 1);
            moby->position.z = (int)(moby->position.z + 0x40);
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &moby->position);
            spyro.unk19.z += spyro.unk4a + 0x133;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &moby->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &moby->position);
            camera.unk170.yaw = 0;
            camera.unk170.pitch = 0;
            camera.unk168 = 0x11;
            if (func_800359A4(&mobyTag->unkC, 4) != 0) {
                D_8006C598 += 0x10;
                if (D_8006C598 >= 0xFF) {
                    D_8006C598 = 0xFF;
                    if ((D_80070104.loadLevel == 0x1E) &&
                        (eggsCollectedArray[lvlIdToIndex[27]] == 0)) {
                        D_80070104.loadLevel = 0x1B;
                    }
                    // BUG // Spike Bug
                    // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                    // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                    // This was fixed in all later revisions
                    if ((D_80070104.loadLevel != 0x1B) ||
                        (progressFlags.lvl63_BiancaStrikesBack != 0)) {
                        func_80054F94(D_80070104.loadLevel, moby);
                    } else {
                        progressFlags.lvl65_SpikeIsBorn = 1;
                        func_800584BC(6, 0x41);
                    }
                }
            }
            func_80055D24(moby, 2);
            break;

        case 5:
            vector1.x = D_80065920[moby->angle.yaw];
            vector1.y = D_800658A0[moby->angle.yaw];
            vector1.z = 0;
            func_8004F194(&vector1, &vector1, &moby->position);
            if (ovlHeader.unk2c(&vector1) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&vector1, moby->angle.yaw, 0);
                moby->state = 6U;
            }
            break;

        case 6:
            vector2.x = D_80065920[moby->angle.yaw];
            vector2.y = D_800658A0[moby->angle.yaw];
            vector2.z = 0;
            func_8004F194(&vector2, &vector2, &moby->position);
            if (ovlHeader.unk2b(&vector2, moby->angle.yaw, 0) != 0) {
                func_8004F178(&vector3, &spyro.position);
                vector3.z -= spyro.unk4a;
                func_8003B634(&savedData, &vector3, spyro.bodyRotation.yaw);
                func_80034F40(moby, 0);
                moby->state = 1;
            }
            break;

        case 7:
            func_80034F40(moby, 1);
            moby->position.z -= 0x40;
            spyro.unk17a = 0x10018000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &moby->position);
            spyro.unk19.z += spyro.unk4a + 0x133;
            spyro.unk18.roll = moby->angle.roll;
            spyro.unk18.pitch = moby->angle.pitch;
            spyro.unk18.yaw = moby->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->unk8->nodes, &spyro.position);
            func_8004F178(&vector4, &moby->position);
            moby->position.z += 0x400;
            vector4.z += 0x200;
            vector4.z = func_8001A358(&vector4, 0x200);
            if (vector4.z != 0) {
                moby->position.z = vector4.z;
                func_80013B7C(0);
                moby->state = 5U;
            } else {
                moby->position.z -= 0x400;
            }
            func_80055D24(moby, 2);
            break;
    }

    if ((game.state == 0) && (moby->animationState.nextId == 1)) {
        if (func_8003BFC0(moby, mobyTag->unk10) == 0) {
            mobyTag->unk10 = func_8003BABC(moby, 0, 4);
            return;
        }
    } else {
        if (func_8003BFC0(moby, mobyTag->unk10) != 0) {
            func_8003BE70(mobyTag->unk10);
        }
        mobyTag->unk10 = -1;
        return;
    }
}

int func_80036220(Vector3D*, char*, int, int);
void func_800584BC(int, int);
void func_level_40_8007EBA8(Moby* moby) {
    char* bounds = moby->mobyTag;
    if (func_80036220((Vector3D*)&spyro, bounds, 0, 0))
        func_800584BC(0, 0x2F);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_40/moby/func_level_40_8007EBE8.s SHA256 6ede4cb00a7bd867c32b80eb093892a010af57dffed3f5aaa1d5e345da88bfdb. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define State345HighWord(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
#define State345Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char State345_func_80021ED8(int, unsigned char, unsigned char) __asm__("func_80021ED8");
/* extern */
unsigned char State345_func_8003BB10(void*, int, unsigned char) __asm__("func_8003BB10");
/* extern */
int State345InterpolateSine(int) __asm__("func_8004E9E4");
/* extern */
int State345InterpolateCosine(int) __asm__("func_8004EA2C");
/* extern */
int State345AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
/* extern */
int State345ApproximatePlanarDistance(void*, unsigned char*) __asm__("func_8004F334");
/* extern */
extern unsigned char State345_D_800658A0 __asm__("D_800658A0");
extern unsigned char State345_D_80065920 __asm__("D_80065920");
extern unsigned char State345_D_8006E020 __asm__("D_8006E020");
extern unsigned short State345_D_8006E040 __asm__("D_8006E040");
extern unsigned char State345_D_80070328 __asm__("D_80070328");
extern void* (*State345_SpawnMoby)(int, void*)__asm__("SpawnMoby");

void func_level_40_8007EBE8(void* input) {
    register void* owner20 __asm__("$20") = input;
    /* Original 0x58-byte frame. Scratch begins at SP+0x10;
     * saved registers occupy SP+0x30 through SP+0x54.
     * The 16-bit scratch word is reinterpreted as signed before its helper.
     * Table indices are byte offsets, with the original SLL1 producer.
     * HI words, signed shifts and reload/control ordering are retained.
     * Return expressions retain the original SB in the J delay slot.
     * Empty constraints preserve initialized raw producers, without opcodes.
     * Physical units, helper contracts and frame cadence are unresolved. */
    struct {
        int result;
        int pad14;
        unsigned short phase;
        char pad1a[6];
        volatile int magic;
        int pad24[3];
    } frame;
    register short signedHalf16 __asm__("$16");
    int temp_a0;
    int temp_a0_2;
    int temp_a1;
    int temp_a1_2;
    register int shiftedWord16 __asm__("$16");
    register int fieldWord17 __asm__("$17");
    register int fieldWord18 __asm__("$18");
    int temp_v0;
    int temp_v0_3;
    register int storageWord2 __asm__("$2");
    int temp_v1_2;
    register int storageWord3 __asm__("$3");
    register int operand4 __asm__("$4");
    int var_a1;
    register int loopLimit23 __asm__("$23");
    register int shiftedHigh2 __asm__("$2");
    register int word3 __asm__("$3");
    register int loopIndex21 __asm__("$21");
    int temp_v1;
    register int word7 __asm__("$7");
    register unsigned char byte16 __asm__("$16");
    register int word2 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    void* ownerStorage30;
    void* temp_s0;
    void* ownerField12Case7;
    void* ownerField12Case8;
    register void* childStorage22 __asm__("$22");
    register void* childRecord19 __asm__("$19");

    MATCHING_KEEP(owner20);
    temp_v1 = State345Field(owner20, unsigned char*, 0x48);
    ownerStorage30 = State345Field(owner20, void**, 0);
    MATCHING_KEEP2(ownerStorage30, temp_v1);
    switch (temp_v1) { /* switch 1 */
        case 0:        /* switch 1 */
            __asm__ volatile("" ::: "$4", "memory");
            word2 = 1;
            goto block_51;
        default: /* switch 1 */
            return;
        case 1: /* switch 1 */
            temp_s0 = owner20 + 0xC;
            if ((State345ApproximatePlanarDistance(temp_s0, &State345_D_80070328) < 0x1800) &&
                (State345ApproximatePlanarDistance(temp_s0, &State345_D_8006E020) >= 0x401) &&
                (State345AbsoluteByteAngleDelta(
                     (int)(State345_D_8006E040 << 0x10) >> 0x14,
                     (State345Field(owner20, unsigned char*, 0x46) + 0x80) & 0xFF) < 0x34)) {
                State345Field(owner20, unsigned char*, 0x48) = 4U;
                return;
            }
            break;
        case 4: /* switch 1 */
            word2 = State345AbsoluteByteAngleDelta(
                (int)(State345_D_8006E040 << 16) >> 20,
                (State345Field(owner20, unsigned char*, 0x46) + 128) & 255);
            frame.result = word2;
            MATCHING_KEEP_VOLATILE_CLOBBER(word2, "memory");
            word2 = word2 < 65;
            if (word2)
                word2 = 7;
            else
                word2 = 8;
            State345Field(owner20, unsigned char*, 0x48) = word2;
            temp_v1_2 = State345Field(ownerStorage30, int*, 0);
            if (temp_v1_2 >= 0x64) {
                loopLimit23 = 5;
            } else {
                loopLimit23 = 3;
                if (temp_v1_2 >= 0xA) {
                    loopLimit23 = 4;
                }
            }
            frame.phase = loopLimit23 * -0x13;
            loopIndex21 = 0;
            if (loopLimit23 != 0) {
                register int magic7 __asm__("$7") = 0x66666667;
                MATCHING_KEEP(magic7);
                frame.magic = magic7;
                do {
                    childRecord19 = State345_SpawnMoby(0x109, owner20);
                    MATCHING_KEEP(childRecord19);
                    if (childRecord19 != 0) {
                        word2 = State345Field(owner20, unsigned char*, 0x48);
                        childStorage22 = State345Field(childRecord19, void**, 0);
                        MATCHING_KEEP2(word2, childStorage22);
                        State345Field(childRecord19, unsigned char*, 0x48) = word2;
                        State345Field(childStorage22, void**, 0) = owner20;
                        word7 = frame.result;
                        byte16 = State345Field(owner20, unsigned char*, 0x46);
                        word2 = word7 < 65;
                        var_a1 = byte16 & 255;
                        if (!word2) {
                            byte16 -= 128;
                            var_a1 = byte16 & 255;
                        }
                        temp_a1 = var_a1 * 2;
                        __asm__("" : "=r"(byte16) : "0"(byte16), "r"(temp_a1));
                        shiftedWord16 = (byte16 & 255) << 4;
                        MATCHING_KEEP_CLOBBER(shiftedWord16, "memory");
                        word7 = frame.phase;
                        MATCHING_KEEP_CLOBBER(word7, "memory");
                        word3 = State345Field(&State345_D_80065920, short*, temp_a1);
                        __asm__("" : "=r"(word3) : "0"(word3) : "$17", "$18");
                        fieldWord17 = State345Field(owner20, int*, 12);
                        fieldWord18 = State345Field(owner20, int*, 16);
                        __asm__(""
                                : "=r"(fieldWord17), "=r"(fieldWord18)
                                : "0"(fieldWord17), "1"(fieldWord18), "r"(word3));
                        signedHalf16 = (short)(word7 + shiftedWord16);
                        operand4 = signedHalf16;
                        word2 = word3 * 25;
                        word3 = word2 << 4;
                        word2 += word3;
                        word2 >>= 9;
                        word3 = State345Field(&State345_D_800658A0, short*, temp_a1);
                        fieldWord17 -= word2;
                        word2 = word3 * 25;
                        word3 = word2 << 4;
                        word2 += word3;
                        word2 >>= 9;
                        fieldWord18 -= word2;
                        word2 = State345InterpolateCosine(operand4);
                        State345Field(childRecord19, int*, 12) =
                            fieldWord17 + ((word2 * 3400) >> 12);
                        word2 = State345InterpolateSine(signedHalf16);
                        word3 = (word2 * 3400) >> 12;
                        word7 = frame.phase;
                        MATCHING_KEEP(word7);
                        fieldWord18 += word3;
                        State345Field(childRecord19, int*, 16) = fieldWord18;
                        __asm__("" ::: "$4", "memory");
                        operand4 = (short)word7;
                        word2 = State345InterpolateCosine(operand4);
                        shiftedWord16 = signedHalf16 + 2048;
                        shiftedWord16 >>= 4;
                        word3 = State345Field(owner20, int*, 20);
                        word2 >>= 2;
                        State345Field(childRecord19, unsigned char*, 0x46) = shiftedWord16;
                        word3 += word2;
                        word3 -= 1024;
                        State345Field(childRecord19, int*, 20) = word3;
                        State345Field(childStorage22, unsigned char*, 4) = shiftedWord16;
                        State345Field(childStorage22, unsigned char*, 5) = loopIndex21;
                        if (loopIndex21)
                            goto testOne;
                        State345Field(childRecord19, signed char*, 0x3C) = 0;
                        State345Field(childRecord19, int*, 0x14) -= 0x90;
                        goto finishChild;
                    testOne:
                        if (loopIndex21 != 1)
                            goto testTwo;
                        State345Field(childRecord19, signed char*, 0x3C) = 1;
                        State345Field(childRecord19, int*, 0x14) -= 0x18;
                        goto finishChild;
                    testTwo:
                        word7 = 2;
                        MATCHING_KEEP(word7);
                        if (loopIndex21 != word7)
                            goto testThree;
                        if (loopLimit23 != 5)
                            goto testFour;
                        storageWord3 = State345Field(ownerStorage30, int*, 0);
                        word7 = State345HighWord(storageWord3, 0x51EB851F);
                        word3 = storageWord3 >> 31;
                        shiftedHigh2 = word7 >> 5;
                        goto storeQuotient;
                    testFour:
                        if (loopLimit23 != 4)
                            goto testThree;
                        storageWord3 = State345Field(ownerStorage30, int*, 0);
                        word7 = frame.magic;
                        word7 = State345HighWord(storageWord3, word7);
                        word3 = storageWord3 >> 31;
                        shiftedHigh2 = word7 >> 2;
                    storeQuotient:
                        State345Field(childRecord19, signed char*, 0x3C) =
                            shiftedHigh2 - word3 + 28;
                        goto finishChild;
                    testThree:
                        if (loopIndex21 != 3)
                            goto remainderRaw;
                        if (loopLimit23 != 5)
                            goto remainderRaw;
                        storageWord2 = State345Field(ownerStorage30, int*, 0);
                        word7 = frame.magic;
                        word7 = State345HighWord(storageWord2, word7);
                        word2 = storageWord2 >> 31;
                        operand4 = word7 >> 2;
                        word7 = frame.magic;
                        MATCHING_KEEP_VOLATILE_CLOBBER(operand4, "memory");
                        operand4 -= word2;
                        goto storeRemainder;
                    remainderRaw:
                        operand4 = State345Field(ownerStorage30, int*, 0);
                        word7 = frame.magic;
                    storeRemainder:;
                        word7 = State345HighWord(operand4, word7);
                        word2 = operand4 >> 31;
                        __asm__("" : "=r"(word7) : "0"(word7), "r"(word2));
                        word3 = word7 >> 2;
                        word3 -= word2;
                        word2 = word3 * 10;
                        operand4 -= word2;
                        operand4 += 28;
                        State345Field(childRecord19, signed char*, 0x3C) = operand4;
                    finishChild:
                        MATCHING_BARRIER_VOLATILE("$7");
                        word7 = 2;
                        MATCHING_KEEP(word7);
                        State345Field(childRecord19, signed char*, 0x54) = word7;
                        State345Field(childRecord19, signed char*, 0x47) = word7;
                    }
                    loopIndex21 += 1;
                    word7 = frame.phase;
                    word7 += 0x26;
                    frame.phase = word7;
                } while (loopIndex21 < loopLimit23);
                return;
            }
            break;
        case 7:
            ownerField12Case7 = owner20 + 12;
            word2 = State345ApproximatePlanarDistance(ownerField12Case7, &State345_D_80070328);
            if (word2 >= 8193) {
                word2 = 1;
                goto block_51;
            }
            word2 = State345ApproximatePlanarDistance(ownerField12Case7, &State345_D_8006E020);
            if (word2 < 1024) {
                word2 = 1;
                goto block_51;
            }
            word2 = State345AbsoluteByteAngleDelta(
                (int)(State345_D_8006E040 << 16) >> 20,
                (State345Field(owner20, unsigned char*, 0x46) + 128) & 255);
            if (word2 >= 65)
                return (void)(State345Field(owner20, volatile unsigned char*, 0x48) = (word2 = 1));
            break;
        case 8:
            ownerField12Case8 = owner20 + 12;
            word2 = State345ApproximatePlanarDistance(ownerField12Case8, &State345_D_80070328);
            if (word2 >= 8193) {
                word2 = 1;
                goto block_51;
            }
            word2 = State345ApproximatePlanarDistance(ownerField12Case8, &State345_D_8006E020);
            if (word2 < 1024) {
                word2 = 1;
                goto block_51;
            }
            word2 = State345AbsoluteByteAngleDelta(
                (int)(State345_D_8006E040 << 16) >> 20,
                (State345Field(owner20, unsigned char*, 0x46) + 128) & 255);
            if (word2 < 64)
                return (void)(State345Field(owner20, unsigned char*, 0x48) = (word2 = 1));
            break;
        case 9: /* switch 1 */
            temp_a0 = State345Field(ownerStorage30, int*, 4);
            if (temp_a0 >= 0) {
                State345_func_80021ED8(temp_a0, 0xFC, 0);
            }
            temp_a0_2 = State345Field(ownerStorage30, int*, 8);
            if (temp_a0_2 >= 0) {
                State345_func_80021ED8(temp_a0_2, 0xFC, 0);
            }
            temp_a1_2 = State345Field(ownerStorage30, int*, 0xC);
            if (temp_a1_2 >= 0) {
                State345_func_8003BB10(owner20, temp_a1_2, 0);
            }
            word2 = 2;
        block_51:
            ((Moby*)owner20)->state = word2;
            return;
    }
finish11503:;
}
#undef State345Field

#undef State345HighWord

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_40/moby/func_level_40_8007F14C.s SHA256 19e0d2b991b03b02eb11427a7894385c534d87124a33a2158842f19015f7ef95. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level40_7F14CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level40_7F14C_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level40_7F14C_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level40_7F14C_D_8006C550 __asm__("D_8006C550");
extern Spyro Level40_7F14C_D_80070328 __asm__("D_80070328");
extern int Level40_7F14CAbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level40_7F14CApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");

int Level40_7F14CInterpolateSine() __asm__("func_8004E9E4");
/* extern */
int Level40_7F14CInterpolateCosine() __asm__("func_8004EA2C");
/* extern */
extern int Level40_7F14C_D_8006C660 __asm__("D_8006C660");
extern int Level40_7F14C_D_8006C71C __asm__("D_8006C71C");
extern Vector3D Level40_7F14C_D_8006E020 __asm__("D_8006E020");
extern unsigned short Level40_7F14C_D_8006E040 __asm__("D_8006E040");
extern unsigned char Level40_7F14C_D_80071570 __asm__("D_80071570");

void func_level_40_8007F14C(Moby* inputOwner) {
    /* Original frame 0x40 and private pointer at SP10. Selector cases,
     * 88-byte pool stride, signed angle conversion and raw helper arguments
     * follow SCUS-94467 at 8007F14C. The empty constraints retain the
     * original register producers and jump destinations without emitting
     * instructions. In particular, child index 1 enters the argument6=2
     * reload, and the initial flag branches to the shared state store.
     * Helper meanings, physical units/fixed point and frame cadence need
     * further evidence. AI generated;
      not human reviewed. */
    register Moby* owner21 __asm__("$21") = inputOwner;
    struct {
        int* sp10;
        unsigned char pad14[4];
    } scratch;

    register Moby* child19 __asm__("$19");
    register Vector3D* ownerPosition16 __asm__("$16");
    register Vector3D* ownerPositionAlt16 __asm__("$16");
    register int angle16 __asm__("$16");
    register int offset23 __asm__("$23");
    register int* private6 __asm__("$6");
    register int childYaw16 __asm__("$16");
    register int positionX17 __asm__("$17");
    register int positionY18 __asm__("$18");
    int headingResult30;
    register int result2 __asm__("$2");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int rawArgument6 __asm__("$6");
    register int rawArgument4 __asm__("$4");
    register int rawArgument5 __asm__("$5");
    register int childIndex20 __asm__("$20");
    unsigned char initialState;
    register int ownerYaw16 __asm__("$16");
    register unsigned char nextState2 __asm__("$2");
    register int spawnState2 __asm__("$2");
    void* anchorPrivate;
    register void* childPrivate22 __asm__("$22");

    MATCHING_KEEP(owner21);
    private6 = owner21->mobyTag;
    scratch.sp10 = private6;
    initialState = owner21->state;
    anchorPrivate = Level40_7F14C_D_8006C550[*private6].mobyTag;
    switch (initialState) { /* switch 1 */
        case 0:             /* switch 1 */
            value2 = *(&Level40_7F14C_D_80071570 + Level40_7F14CField(anchorPrivate, int*, 12));
            if (value2) {
                nextState2 = 2;
            } else {
                __asm__ volatile("# initial-clear-flag");
                nextState2 = 1;
            }
            goto storeNextState;
        case 4: /* switch 1 */
            headingResult30 =
                Level40_7F14CAbsoluteByteAngleDelta((int)(Level40_7F14C_D_8006E040 << 0x10) >> 0x14,
                                                    (owner21->angle.yaw + 0x80) & 0xFF);
            value2 = headingResult30 < 65;
            MATCHING_KEEP(value2);
            if (!value2) {
                spawnState2 = 8;
            } else {
                spawnState2 = 7;
            }
            owner21->state = spawnState2;
            offset23 = -0x85;
            childIndex20 = 0;
            do {
                rawArgument4 = 0xC3;
                if (childIndex20 != 0) {
                    rawArgument4 = 0x109;
                }
                child19 = SpawnMoby(rawArgument4, owner21);
                MATCHING_KEEP(child19);
                if (child19 != 0) {
                    MATCHING_KEEP_VOLATILE_CLOBBER(child19, "memory");
                    value2 = owner21->state;
                    childPrivate22 = child19->mobyTag;
                    child19->state = value2;
                    MATCHING_KEEP(headingResult30);
                    Level40_7F14CField(childPrivate22, Moby**, 0) = owner21;
                    value2 = headingResult30 < 65;
                    ownerYaw16 = owner21->angle.yaw;
                    __asm__("" : "=r"(ownerYaw16) : "0"(ownerYaw16), "r"(value2));
                    rawArgument5 = ownerYaw16 & 0xFF;
                    if (!value2) {
                        ownerYaw16 -= 0x80;
                        rawArgument5 = ownerYaw16 & 0xFF;
                    }
                    rawArgument5 <<= 1;
                    MATCHING_KEEP(rawArgument5);
                    angle16 = (short)(offset23 + ((ownerYaw16 & 255) * 16));
                    MATCHING_KEEP(angle16);
                    rawArgument4 = angle16;
                    MATCHING_KEEP_CLOBBER(rawArgument4, "memory");
                    value3 = *(short*)((unsigned char*)Level40_7F14C_D_80065920 + rawArgument5);
                    MATCHING_BARRIER_VOLATILE("memory");
                    positionX17 = owner21->position.x;
                    positionY18 = owner21->position.y;
                    MATCHING_OBSERVE3(positionX17, positionY18, value3);
                    value2 = value3 * 25;
                    value3 = value2 << 4;
                    value2 += value3;
                    value2 >>= 9;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    value3 = *(short*)((unsigned char*)Level40_7F14C_D_800658A0 + rawArgument5);
                    positionX17 -= value2;
                    value2 = value3 * 25;
                    value3 = value2 << 4;
                    value2 += value3;
                    positionY18 -= value2 >> 9;
                    child19->position.x =
                        positionX17 +
                        ((int)(Level40_7F14CInterpolateCosine(rawArgument4, rawArgument5) *
                               0xD48) >>
                         0xC);
                    child19->position.y =
                        positionY18 + ((int)(Level40_7F14CInterpolateSine(angle16) * 0xD48) >> 0xC);
                    value2 = Level40_7F14CInterpolateCosine((short)offset23);
                    MATCHING_KEEP(angle16);
                    childYaw16 = (int)(angle16 + 2048) >> 4;
                    value3 = owner21->position.z;
                    value2 >>= 1;
                    child19->angle.yaw = (unsigned char)childYaw16;
                    value3 -= value2;
                    value3 += 2048;
                    child19->position.z = value3;
                    Level40_7F14CField(childPrivate22, signed char*, 4) = childYaw16;
                    Level40_7F14CField(childPrivate22, signed char*, 5) = childIndex20;
                    if (!childIndex20) {
                        child19->animationState.id = 0;
                        goto setChildFields;
                    }
                    value2 = 1;
                    rawArgument6 = 2;
                    if (childIndex20 == value2) {
                        MATCHING_KEEP(childIndex20);
                        __asm__ volatile("" : "=r"(rawArgument6));
                        value3 = child19->position.z;
                        MATCHING_KEEP_VOLATILE(value2);
                        value2 = 1;
                        child19->animationState.id = value2;
                        value3 -= 24;
                        child19->position.z = value3;
                        goto setChildFields;
                    }
                    if (childIndex20 == rawArgument6) {
                        value2 = 29;
                        child19->animationState.id = value2;
                        goto setChildFields;
                    }
                    value2 = 3;
                    rawArgument6 = 28;
                    if (childIndex20 == value2) {
                        value2 = 33;
                        child19->animationState.id = value2;
                        goto setChildFields;
                    }
                    child19->animationState.id = rawArgument6;
                setChildFields:
                    rawArgument6 = 2;
                    MATCHING_KEEP(rawArgument6);
                    child19->colour.r = rawArgument6;
                    child19->unknown4 = rawArgument6;
                }
                childIndex20 += 1;
                offset23 += 0x26;
            } while (childIndex20 < 7);
            goto afterDispatch;
        case 7:
            value2 = Level40_7F14C_D_8006C71C;
            ownerPosition16 = &owner21->position;
            if (value2 >= 15000) {
                value2 = Level40_7F14C_D_8006C660;
                value3 = Level40_7F14CField(anchorPrivate, int*, 8);
                if (value2 >= value3) {
                    nextState2 = 9;
                    goto storeNextState;
                }
            }
            value2 = Level40_7F14CApproximatePlanarDistance(ownerPosition16,
                                                            &Level40_7F14C_D_80070328.position);
            if (value2 >= 8193) {
                nextState2 = 1;
                goto storeNextState;
            }
            value2 =
                Level40_7F14CApproximatePlanarDistance(ownerPosition16, &Level40_7F14C_D_8006E020);
            if (value2 < 1024) {
                nextState2 = 1;
                goto storeNextState;
            }
            value2 = Level40_7F14CAbsoluteByteAngleDelta(
                (int)(Level40_7F14C_D_8006E040 << 16) >> 20, (owner21->angle.yaw + 128) & 255);
            if (value2 < 65)
                goto afterDispatch;
            {
                register int state7Value2 __asm__("$2") = 1;
                owner21->state = state7Value2;
            }
            goto afterDispatch;
            goto afterDispatch;
        case 8:
            value2 = Level40_7F14C_D_8006C71C;
            ownerPositionAlt16 = &owner21->position;
            if (value2 >= 15000) {
                value2 = Level40_7F14C_D_8006C660;
                value3 = Level40_7F14CField(anchorPrivate, int*, 8);
                if (value2 >= value3) {
                    nextState2 = 9;
                    goto storeNextState;
                }
            }
            value2 = Level40_7F14CApproximatePlanarDistance(ownerPositionAlt16,
                                                            &Level40_7F14C_D_80070328.position);
            if (value2 >= 8193) {
                nextState2 = 1;
                goto storeNextState;
            }
            value2 = Level40_7F14CApproximatePlanarDistance(ownerPositionAlt16,
                                                            &Level40_7F14C_D_8006E020);
            if (value2 < 1024) {
                nextState2 = 1;
                goto storeNextState;
            }
            value2 = Level40_7F14CAbsoluteByteAngleDelta(
                (int)(Level40_7F14C_D_8006E040 << 16) >> 20, (owner21->angle.yaw + 128) & 255);
            if (value2 >= 64)
                goto afterDispatch;
            {
                register unsigned short state8Value2 __asm__("$2") = 1;
                owner21->state = state8Value2;
            }
            goto afterDispatch;
            goto afterDispatch;
        default:
            value2 = Level40_7F14C_D_8006C71C;
            if (value2 >= 15000) {
                value2 = Level40_7F14C_D_8006C660;
                value3 = Level40_7F14CField(anchorPrivate, int*, 8);
                if (value2 >= value3) {
                    nextState2 = 9;
                    goto storeNextState;
                }
            }
        case 2:
        case 3:
        case 5:
        case 6:
            private6 = scratch.sp10;
            MATCHING_KEEP(private6);
            value3 = *private6;
            MATCHING_KEEP(value3);
            nextState2 = Level40_7F14C_D_8006C550[value3].state;
    }
storeNextState:

    owner21->state = nextState2;
afterDispatch:
    if (owner21->state == 9) {
        private6 = scratch.sp10;
        MATCHING_KEEP(private6);
        Level40_7F14C_D_8006C550[*private6].state = 9;
        owner21->state = 2;
    }
}
#undef Level40_7F14CField

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0.
 * Complete original evidence sibling4972:776 instructions,9 dispatch
 * words and one alignment word. Uninstalled candidate. Raw widths and
 * integer operations only; helper meanings, units and cadence unresolved.
 * Exact instructions/targets/data and all retail hashes gate acceptance. */
#define A4973F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define A4973W(p, o) A4973F(p, int*, o)
#define A4973P(p, o) A4973F(p, unsigned char**, o)
#define A4973B(p, o) A4973F(p, unsigned char*, o)
#define A4973KEEP(v) __asm__("" : "=r"(v) : "0"(v))
extern unsigned char A4973Flags[] __asm__("D_80071570"), A4973Select[] __asm__("D_80066FCC");
extern unsigned char A4973Player[] __asm__("D_80070328"), A4973E020[] __asm__("D_8006E020");
extern unsigned short A4973E040 __asm__("D_8006E040");
extern unsigned char* A4973Text[] __asm__("D_80069CF8");
extern int A4973C76C __asm__("D_8006C76C"), A4973C660 __asm__("D_8006C660");
extern int A4973C5E0 __asm__("D_8006C5E0"), A4973C640 __asm__("D_8006C640");
extern unsigned char* A4973C530 __asm__("D_8006C530");
extern short A4973Cos[] __asm__("D_80065920"), A4973Sin[] __asm__("D_800658A0");
extern int (*A4973Spawn)() __asm__("SpawnMoby");
int A4973ApproximatePlanarDistance_0() __asm__("func_8004F334");
int A4973ApproximatePlanarDistance_1() __asm__("func_8004F334");
int A4973AbsoluteByteAngleDelta_2() __asm__("func_8004F264");
int A4973ApproximatePlanarDistance_3() __asm__("func_8004F334");
int A4973ApproximatePlanarDistance_4() __asm__("func_8004F334");
int A4973AbsoluteByteAngleDelta_5() __asm__("func_8004F264");
int A4973AbsoluteByteAngleDelta_6() __asm__("func_8004F264");
int A4973InterpolateCosine_7() __asm__("func_8004EA2C");
int A4973InterpolateSine_8() __asm__("func_8004E9E4");
int A4973InterpolateCosine_9() __asm__("func_8004EA2C");
int A4973AbsoluteByteAngleDelta_10() __asm__("func_8004F264");
int A4973InterpolateCosine_11() __asm__("func_8004EA2C");
int A4973InterpolateSine_12() __asm__("func_8004E9E4");
int A4973InterpolateCosine_13() __asm__("func_8004EA2C");
int A4973ApproximatePlanarDistance_14() __asm__("func_8004F334");
int A4973ApproximatePlanarDistance_15() __asm__("func_8004F334");
int A4973AbsoluteByteAngleDelta_16() __asm__("func_8004F264");
int A4973ApproximatePlanarDistance_17() __asm__("func_8004F334");
int A4973ApproximatePlanarDistance_18() __asm__("func_8004F334");
int A4973AbsoluteByteAngleDelta_19() __asm__("func_8004F264");
int A4973ApproximatePlanarDistance_20() __asm__("func_8004F334");
int A4973ApproximatePlanarDistance_21() __asm__("func_8004F334");
int A4973AbsoluteByteAngleDelta_22() __asm__("func_8004F264");
int A4973ApproximatePlanarDistance_23() __asm__("func_8004F334");
int A4973ApproximatePlanarDistance_24() __asm__("func_8004F334");
int A4973AbsoluteByteAngleDelta_25() __asm__("func_8004F264");
int A4973H21ED8_26() __asm__("func_80021ED8");
void func_level_40_8007F650(unsigned char* input) {
    register unsigned char* owner20 __asm__("$20");
    unsigned char* private30;
    register unsigned char* child19 __asm__("$19");
    register unsigned char* childPrivate21 __asm__("$21");
    register unsigned char* childPrivate22 __asm__("$22");
    register unsigned char* text23 __asm__("$23");
    register unsigned char* position16 __asm__("$16");
    register int phase16 __asm__("$16");
    register int x17 __asm__("$17");
    register int y18 __asm__("$18");
    register int index22 __asm__("$22");
    register int index21 __asm__("$21");
    register int digits23 __asm__("$23");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int arg4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    register unsigned char* ptr4 __asm__("$4");
    register unsigned char* ptr5 __asm__("$5");
    volatile struct {
        int angleFirst, pad14, count, pad1C;
        short baseFirst;
        char pad22[6];
        int angleSecond, pad2C;
        short baseSecond;
        char pad32[6];
        int magic;
        char originalSpillArea[28];
    } frame;
    register int work9 __asm__("$9");
    int product;
    owner20 = input;
    private30 = A4973P(owner20, 0);
    switch (A4973B(owner20, 0x48)) {
        case 0:
            work2 = A4973W(private30, 12);
            if (work2 >= 0) {
                if (!A4973Flags[work2])
                    goto stateOne;
                work2 = 9;
                __asm__ volatile("# initial flag state" : : "r"(work2));
                A4973B(owner20, 0x48) = work2;
                break;
            }
        initialTimer:
            work3 = A4973W(private30, 8);
            if (work3 <= 0) {
                work2 = 2;
                goto storeState;
            }
            work2 = A4973C660;
            work2 = work2 < work3;
            A4973KEEP(work2);
            if (work2) {
                work2 = 1;
                goto storeState;
            }
            work2 = 9;
            goto storeState;
        case 1:
            work3 = A4973W(private30, 8);
            position16 = owner20 + 12;
            if (work3 > 0 && A4973W(private30, 12) < 0 && A4973C660 >= work3) {
                work2 = 9;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_0(position16, A4973Player) >= 6144)
                break;
            if (A4973ApproximatePlanarDistance_1(position16, A4973E020) < 1025)
                break;
            work3 = A4973AbsoluteByteAngleDelta_2((short)A4973E040 >> 4,
                                                  (A4973B(owner20, 0x46) + 128) & 255);
            A4973KEEP(work3);
            if (work3 < 52)
                goto readyFIRST;
            if (!A4973W(private30, 4))
                break;
            work2 = work3 < 77;
            A4973KEEP(work2);
            if (work2)
                break;
        readyFIRST:
            __asm__ volatile("# first threshold site" : : : "memory");
            work2 = A4973C660;
            work3 = A4973W(private30, 8);
            if (work2 < work3)
                goto setFourFIRST;
            work2 = A4973W(private30, 12);
            if (work2 < 0)
                goto enterFIRST;
            if ((work2 = A4973Flags[work2], ({
                     MATCHING_KEEP_CLOBBER(work2, "$8");
                     work2;
                 }))) {
                work2 = 3;
                goto storeState;
            }
        setFourFIRST:
            __asm__ volatile("# remaining state 0" : "=r"(work3) : "0"(work3) : "$8");
            if (work3) {
                work2 = 4;
                A4973KEEP(work2);
                A4973B(owner20, 0x48) = work2;
            }
            break;
        enterFIRST:
            __asm__ volatile("# FIRST site" : : : "$2");
            work2 = 3;
            goto storeState;
        case 2:
            position16 = owner20 + 12;
            if (A4973ApproximatePlanarDistance_3(position16, A4973Player) >= 6144)
                break;
            if (A4973ApproximatePlanarDistance_4(position16, A4973E020) < 1025)
                break;
            work3 = A4973AbsoluteByteAngleDelta_5((short)A4973E040 >> 4,
                                                  (A4973B(owner20, 0x46) + 128) & 255);
            A4973KEEP(work3);
            if (work3 < 52)
                goto readySECOND;
            if (!A4973W(private30, 4))
                break;
            work2 = work3 < 77;
            A4973KEEP(work2);
            if (work2)
                break;
        readySECOND:
            __asm__ volatile("# second threshold site" : : : "memory");
            work2 = A4973C660;
            work3 = A4973W(private30, 8);
            if (work2 < work3)
                goto setFourSECOND;
            work2 = A4973W(private30, 12);
            if (work2 < 0)
                goto enterSECOND;
            if ((work2 = A4973Flags[work2], ({
                     MATCHING_KEEP_CLOBBER(work2, "$10");
                     work2;
                 }))) {
                work2 = 3;
                goto storeState;
            }
        setFourSECOND:
            __asm__ volatile("# remaining state 1" : "=r"(work3) : "0"(work3) : "$10");
            if (work3) {
                work2 = 4;
                A4973KEEP(work2);
                A4973B(owner20, 0x48) = work2;
            }
            break;
        enterSECOND:
            __asm__ volatile("# SECOND site" : : : "$2");
            work2 = 3;
            goto storeState;
        case 3:
            work2 = A4973AbsoluteByteAngleDelta_6((short)A4973E040 >> 4,
                                                  (A4973B(owner20, 0x46) + 128) & 255);
            frame.angleFirst = work2;
            work2 = work2 < 65;
            A4973KEEP(work2);
            if (work2)
                work2 = 5;
            else
                work2 = 6;
            A4973B(owner20, 0x48) = work2;
            MATCHING_BARRIER_VOLATILE("memory");
            work2 = A4973W(private30, 0);
            index22 = A4973Select[work2];
            A4973KEEP(index22);
            arg4 = (int)A4973Text;
            A4973KEEP(arg4);
            work2 = A4973C76C * 160;
            A4973KEEP(work2);
            work2 += arg4;
            work3 = index22 * 4;
            work3 += work2;
            A4973KEEP(work3);
            ptr5 = *(unsigned char**)work3;
            frame.count = 0;
            work3 = 0;
            if (A4973B(ptr5, 0)) {
                ptr4 = ptr5;
                do {
                    work9 = frame.count;
                    ptr4++;
                    work9++;
                    frame.count = work9;
                    work2 = A4973B(ptr4, 0);
                    MATCHING_OBSERVE_VOLATILE(work2);
                    work3++;
                } while (work2);
            }
            work3--;
            A4973KEEP(work3);
            work3 = work3 * -19;
            A4973KEEP(work3);
            work9 = frame.count;
            index22 = 0;
            *(short*)&frame.baseFirst = work3;
            if (work9 <= 0)
                break;
            text23 = ptr5;
            do {
                if (A4973B(text23, 0) != 32) {
                    child19 = (unsigned char*)A4973Spawn(265, owner20);
                    A4973KEEP(child19);
                    if (child19) {
                        work2 = A4973B(owner20, 0x48);
                        childPrivate21 = A4973P(child19, 0);
                        A4973B(child19, 0x48) = work2;
                        A4973P(childPrivate21, 0) = owner20;
                        work9 = frame.angleFirst;
                        phase16 = A4973B(owner20, 0x46);
                        work2 = work9 < 65;
                        MATCHING_KEEP2(phase16, work2);
                        arg5 = phase16 & 255;
                        if (!work2) {
                            phase16 -= 128;
                            arg5 = phase16 & 255;
                        }
                        arg5 <<= 1;
                        A4973KEEP(arg5);
                        phase16 = (phase16 & 255) << 4;
                        work9 = (unsigned short)frame.baseFirst;
                        work3 = *(short*)((unsigned char*)A4973Cos + arg5);
                        MATCHING_OBSERVE_VOLATILE(work3);
                        x17 = A4973W(owner20, 12);
                        y18 = A4973W(owner20, 16);
                        MATCHING_OBSERVE3_VOLATILE(work3, x17, y18);
                        phase16 = work9 + phase16;
                        A4973KEEP(phase16);
                        phase16 = (short)phase16;
                        arg4 = phase16;
                        MATCHING_OBSERVE_VOLATILE(arg4);
                        x17 -= (work3 * 625) >> 10;
                        work3 = *(short*)((unsigned char*)A4973Sin + arg5);
                        y18 -= (work3 * 625) >> 10;
                        work2 = A4973InterpolateCosine_7(phase16);
                        arg4 = phase16;
                        MATCHING_OBSERVE_VOLATILE(arg4);
                        x17 += (work2 * 3400) >> 12;
                        A4973W(child19, 12) = x17;
                        work2 = A4973InterpolateSine_8(phase16);
                        y18 += (work2 * 3400) >> 12;
                        work9 = (unsigned short)frame.baseFirst;
                        MATCHING_OBSERVE_VOLATILE(work9);
                        A4973W(child19, 16) = y18;
                        MATCHING_BARRIER_VOLATILE("memory");
                        work2 = A4973InterpolateCosine_9((short)work9);
                        phase16 = (phase16 + 2048) >> 4;
                        work3 = A4973W(owner20, 20);
                        work2 >>= 2;
                        A4973B(child19, 0x46) = phase16;
                        work3 += work2;
                        A4973KEEP(work3);
                        work3 -= 768;
                        A4973W(child19, 20) = work3;
                        A4973B(childPrivate21, 4) = phase16;
                        A4973B(childPrivate21, 5) = index22;
                        work3 = A4973B(text23, 0);
                        if ((unsigned)(work3 - 48) < 10) {
                            work2 = work3 + 236;
                            A4973KEEP(work2);
                            A4973B(child19, 0x3C) = work2;
                        } else {
                            arg4 = work3 & 255;
                            if ((work2 = (unsigned)arg4 < 97, (
                                                                  {
                                                                      A4973KEEP(work2);
                                                                      !work2;
                                                                  }))) {
                                work2 = work3 + 161;
                                A4973KEEP(work2);
                                A4973B(child19, 0x3C) = work2;
                            } else if ((work2 = (unsigned)arg4 < 65, (
                                                                         {
                                                                             A4973KEEP(work2);
                                                                             !work2;
                                                                         }))) {
                                work2 = work3 + 193;
                                A4973KEEP(work2);
                                A4973B(child19, 0x3C) = work2;
                            } else {
                                A4973B(child19, 0x3C) = 38;
                                A4973W(child19, 20) += 64;
                            }
                        }
                        A4973B(child19, 0x54) = 2;
                        A4973B(child19, 0x47) = 2;
                    }
                }
                work9 = (unsigned short)frame.baseFirst;
                A4973KEEP(work9);
                work9 += 38;
                *(short*)&frame.baseFirst = work9;
                work9 = frame.count;
                MATCHING_OBSERVE_VOLATILE(work9);
                index22++;
                work2 = index22 < work9;
                A4973KEEP(work2);
                text23++;
            } while (work2);
            break;
        case 4:
            work2 = A4973AbsoluteByteAngleDelta_10((short)A4973E040 >> 4,
                                                   (A4973B(owner20, 0x46) + 128) & 255);
            frame.angleSecond = work2;
            work2 = work2 < 65;
            A4973KEEP(work2);
            if (work2)
                work2 = 7;
            else
                work2 = 8;
            A4973B(owner20, 0x48) = work2;
            work3 = A4973W(private30, 8);
            work2 = work3 < 100;
            A4973KEEP(work2);
            if (!work2) {
                digits23 = 5;
                goto digitsReady;
            }
            work2 = work3 < 10;
            A4973KEEP(work2);
            digits23 = 3;
            if (!work2)
                digits23 = 4;
        digitsReady:
            *(short*)&frame.baseSecond = digits23 * -19;
            index21 = 0;
            if (!digits23)
                break;
            work9 = 0x66666667;
            frame.magic = work9;
            do {
                child19 = (unsigned char*)A4973Spawn(265, owner20);
                A4973KEEP(child19);
                if (child19) {
                    work2 = A4973B(owner20, 0x48);
                    childPrivate22 = A4973P(child19, 0);
                    A4973B(child19, 0x48) = work2;
                    A4973P(childPrivate22, 0) = owner20;
                    work9 = frame.angleSecond;
                    phase16 = A4973B(owner20, 0x46);
                    work2 = work9 < 65;
                    MATCHING_KEEP2(phase16, work2);
                    arg5 = phase16 & 255;
                    if (!work2) {
                        phase16 -= 128;
                        arg5 = phase16 & 255;
                    }
                    arg5 <<= 1;
                    A4973KEEP(arg5);
                    phase16 = (phase16 & 255) << 4;
                    work9 = (unsigned short)frame.baseSecond;
                    work3 = *(short*)((unsigned char*)A4973Cos + arg5);
                    MATCHING_OBSERVE_VOLATILE(work3);
                    x17 = A4973W(owner20, 12);
                    y18 = A4973W(owner20, 16);
                    MATCHING_OBSERVE3_VOLATILE(work3, x17, y18);
                    phase16 = work9 + phase16;
                    A4973KEEP(phase16);
                    phase16 = (short)phase16;
                    arg4 = phase16;
                    MATCHING_OBSERVE_VOLATILE(arg4);
                    x17 -= (work3 * 425) >> 9;
                    work3 = *(short*)((unsigned char*)A4973Sin + arg5);
                    y18 -= (work3 * 425) >> 9;
                    work2 = A4973InterpolateCosine_11(phase16);
                    arg4 = phase16;
                    MATCHING_OBSERVE_VOLATILE(arg4);
                    x17 += (work2 * 3400) >> 12;
                    A4973W(child19, 12) = x17;
                    work2 = A4973InterpolateSine_12(phase16);
                    y18 += (work2 * 3400) >> 12;
                    work9 = (unsigned short)frame.baseSecond;
                    MATCHING_OBSERVE_VOLATILE(work9);
                    A4973W(child19, 16) = y18;
                    MATCHING_BARRIER_VOLATILE("memory");
                    work2 = A4973InterpolateCosine_13((short)work9);
                    phase16 = (phase16 + 2048) >> 4;
                    work3 = A4973W(owner20, 20);
                    work2 >>= 2;
                    A4973B(child19, 0x46) = phase16;
                    work3 += work2;
                    A4973KEEP(work3);
                    work3 -= 1024;
                    A4973W(child19, 20) = work3;
                    A4973B(childPrivate22, 4) = phase16;
                    A4973B(childPrivate22, 5) = index21;
                    if (index21 == 0) {
                        A4973B(child19, 0x3C) = 0;
                        A4973W(child19, 20) -= 144;
                    } else if (index21 == 1) {
                        A4973B(child19, 0x3C) = 1;
                        A4973W(child19, 20) -= 24;
                    } else if ((work9 = 2, ({
                                    MATCHING_OBSERVE(work9);
                                    index21 == work9;
                                }))) {
                        if (digits23 == 5)
                            A4973B(child19, 0x3C) = ({
                                work3 = A4973W(private30, 8);
                                work2 = 0x51EB851F;
                                product = work3 * work2;
                                work3 >>= 31;
                                __asm__ volatile("" : "=h"(work9) : "l"(product));
                                work2 = (work9 >> 5) - work3;
                                work2 + 28;
                            });
                        else if (digits23 == 4)
                            A4973B(child19, 0x3C) = ({
                                work3 = A4973W(private30, 8);
                                work9 = frame.magic;
                                product = work3 * work9;
                                work3 >>= 31;
                                __asm__ volatile("" : "=h"(work9) : "l"(product));
                                work2 = (work9 >> 2) - work3;
                                work2 + 28;
                            });

                        else
                            goto remainder;
                    } else {
                    remainder:
                        if (index21 == 3 && digits23 == 5) {
                            work2 = A4973W(private30, 8);
                            work9 = frame.magic;
                            product = work2 * work9;
                            work2 >>= 31;
                            __asm__ volatile("" : "=h"(work9) : "l"(product));
                            arg4 = work9 >> 2;
                            work9 = frame.magic;
                            MATCHING_OBSERVE_VOLATILE(work9);
                            arg4 -= work2;
                        } else {
                            arg4 = A4973W(private30, 8);
                            work9 = frame.magic;
                        }
                        product = arg4 * work9;
                        work2 = arg4 >> 31;
                        __asm__ volatile("" : "=h"(work9) : "l"(product));
                        work3 = work9 >> 2;
                        A4973KEEP(work3);
                        work3 -= work2;
                        A4973KEEP(work3);
                        work2 = work3 * 10;
                        arg4 -= work2;
                        A4973B(child19, 0x3C) = arg4 + 28;
                    }
                    MATCHING_BARRIER_VOLATILE("$9");
                    work9 = 2;
                    A4973B(child19, 0x54) = work9;
                    A4973B(child19, 0x47) = work9;
                }
                MATCHING_OBSERVE_VOLATILE(private30);
                index21++;
                MATCHING_OBSERVE_VOLATILE(index21);
                work9 = (unsigned short)frame.baseSecond;
                MATCHING_OBSERVE_VOLATILE(work9);
                work2 = index21 < digits23;
                work9 += 38;
                *(short*)&frame.baseSecond = work9;
            } while (work2);
            break;
        case 5:
            position16 = owner20 + 12;
            if (A4973ApproximatePlanarDistance_14(position16, A4973Player) >= 8193) {
                work2 = 2;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_15(position16, A4973E020) < 1024) {
                work2 = 2;
                goto storeState;
            }
            if (A4973AbsoluteByteAngleDelta_16((short)A4973E040 >> 4,
                                               (A4973B(owner20, 0x46) + 128) & 255) >= 65)
                A4973B(owner20, 0x48) = 2;
            break;
        case 6:
            position16 = owner20 + 12;
            if (A4973ApproximatePlanarDistance_17(position16, A4973Player) >= 8193) {
                work2 = 2;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_18(position16, A4973E020) < 1024) {
                work2 = 2;
                goto storeState;
            }
            if (A4973AbsoluteByteAngleDelta_19((short)A4973E040 >> 4,
                                               (A4973B(owner20, 0x46) + 128) & 255) < 64)
                A4973B(owner20, 0x48) = 2;
            break;
        case 7:
            work3 = A4973W(private30, 8);
            position16 = owner20 + 12;
            if (work3 > 0 && A4973W(private30, 12) < 0 && A4973C660 >= work3) {
                work2 = 9;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_20(position16, A4973Player) >= 8193) {
                work2 = 1;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_21(position16, A4973E020) < 1024) {
                work2 = 1;
                goto storeState;
            }
            if (A4973AbsoluteByteAngleDelta_22((short)A4973E040 >> 4,
                                               (A4973B(owner20, 0x46) + 128) & 255) >= 65) {
                work2 = 1;
                goto storeState;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            goto flagsCheck;
        case 8:
            work3 = A4973W(private30, 8);
            position16 = owner20 + 12;
            if (work3 > 0 && A4973W(private30, 12) < 0 && A4973C660 >= work3) {
                work2 = 9;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_23(position16, A4973Player) >= 8193) {
                work2 = 1;
                goto storeState;
            }
            if (A4973ApproximatePlanarDistance_24(position16, A4973E020) < 1024) {
                work2 = 1;
                goto storeState;
            }
            if (A4973AbsoluteByteAngleDelta_25((short)A4973E040 >> 4,
                                               (A4973B(owner20, 0x46) + 128) & 255) < 64) {
                work2 = 1;
                goto storeState;
            }
        flagsCheck:
            work2 = A4973W(private30, 12);
            if (work2 >= 0 && A4973Flags[work2]) {
            stateOne:
                MATCHING_BARRIER_VOLATILE("$2");
                work2 = 1;
                A4973B(owner20, 0x48) = work2;
            }
            break;
        storeState:
            A4973B(owner20, 0x48) = work2;
            break;
    }
    if (A4973B(owner20, 0x48) != 9)
        return;
    work3 = A4973W(private30, 12);
    if (work3)
        A4973Flags[work3] = 1;
    arg5 = 0;
    if (A4973C5E0 > 0) {
        register int marker7 __asm__("$7") = 42;
        register int one8 __asm__("$8");
        MATCHING_OBSERVE_VOLATILE(marker7);
        one8 = 1;
        MATCHING_OBSERVE_VOLATILE(one8);
        arg6 = 0;
        do {
            work2 = (int)A4973C530;
            A4973KEEP(work2);
            ptr4 = (unsigned char*)(arg6 + work2);
            work3 = A4973B(ptr4, 0x42);
            work2 = A4973W(private30, 0);
            if (work3 == work2) {
                A4973B(ptr4, 0x40) = marker7;
                if (A4973C640 >= 11) {
                    work2 = (int)A4973C530;
                    A4973KEEP(work2);
                    work2 = arg6 + work2;
                    A4973B(work2, 0x43) = one8;
                }
                break;
            }
            work2 = A4973C5E0;
            MATCHING_OBSERVE_VOLATILE(work2);
            arg5++;
            arg6 += 68;
        } while (arg5 < work2);
    }
    arg4 = A4973W(private30, 16);
    if (arg4 >= 0) {
        A4973H21ED8_26(arg4, 252, 0);
        A4973W(private30, 16) = -1;
    }
    A4973B(owner20, 0x48) = 2;
}
#undef A4973F
#undef A4973W
#undef A4973P
#undef A4973B
#undef A4973KEEP

typedef struct {
    short count;
    unsigned char reserved02[10];
    unsigned char* records;
} DecodedEventRecords;
typedef struct {
    int tableIndex, targetIndex, mask;
    short classOrCount, countOrClass;
    int kind;
    Vector3D* offsets;
    int reserved18;
    DecodedEventRecords* recordList;
    int soundIndex, enabled;
} DecodedEventTag;
extern int DecodedEventTick __asm__("D_8006C640");
extern unsigned char DecodedEventFlags __asm__("D_8006C7B4");
extern int DecodedEventSlot __asm__("D_8006C58C");
extern unsigned char DecodedEventSlots[] __asm__("D_80070300");
extern int** DecodedEventTable __asm__("D_8006D048 + 0x14");
extern int DecodedEventLevel __asm__("D_8006C5BC");
extern int DecodedEventSublevel __asm__("D_8006C5C8");
extern unsigned char DecodedEventTimerData[] __asm__("D_8006C7F8");
extern unsigned char DecodedEventSpecialTimerData[] __asm__("D_8006D088");
extern short DecodedEventCos[] __asm__("D_80065920");
extern short DecodedEventSin[] __asm__("D_800658A0");
void DecodedEventTimer(void*, int, void*) __asm__("func_8003B7B4");
void DecodedEventSound(Moby*, int, int) __asm__("func_8003BB10");
void DecodedEventTarget(int, int, int) __asm__("func_80021ED8");
void DecodedEventPrepare(Moby*, int) __asm__("func_80055D24");
void DecodedEventCopy(Vector3D*, const void*) __asm__("func_8004F178");
void DecodedEventAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedEventSubtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void DecodedEventRotate(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int DecodedEventLength(Vector3D*, int) __asm__("func_8004EDE8");
void DecodedEventScale(Vector3D*, int, int) __asm__("func_8004F08C");
void func_80055B18(Moby*);
/*
 * USA SCUS-94467 Rev 0: representative func_level_13_80082590,
 * 0x80082590..0x800829C8, 270 words. Per-copy source and word digests
 * are recorded in overlay-batch-2026-10-04-1298.md.
 * Empty asm constraints emit no instructions and retain the retail
 * register lifetimes, call arguments, fresh reads and stack layout.
 * Raw table/object fields and helper identities are preserved; caller
 * cadence and browser runtime interpretations remain unresolved.
 * AI-generated reconstruction; not yet human reviewed.
 */
void func_level_40_80080270(Moby* argument) {
    Vector3D offset;
    int reserved24;
    Vector3D direction;
    int reserved34[3];
    register Moby* moby __asm__("$20") = argument;
    register int state __asm__("$16") = moby->state;
    register DecodedEventTag* tag __asm__("$18") = moby->mobyTag;
    register int count __asm__("$17");
    register int kind __asm__("$3");
    register int limit __asm__("$2");
    register int cursor __asm__("$19");
    register Vector3D* directionPointer __asm__("$21");
    MATCHING_KEEP(state);
    switch (state) {
        /* Arm the controller from its enable bits or a masked table entry. */
        case 0: {
            register int* entry __asm__("$4");
            if (tag->enabled && !DecodedEventTick) {
                if ((DecodedEventFlags & 1) || (DecodedEventSlots[DecodedEventSlot] & 1)) {
                    moby->updateDistance = 255;
                    moby->state = 1;
                    DecodedEventTimer(&moby->state, 1, DecodedEventTimerData);
                }
            }
            /* The table stores pointers; the tested word is at entry offset 4. */
            entry = DecodedEventTable[tag->tableIndex];
            if (!DecodedEventTick)
                entry[1] = 0;
            if (!(entry[1] & tag->mask))
                return;
            entry[1] = 0;
            moby->state = 1;
            if ((DecodedEventLevel == 21 && DecodedEventSublevel == 1) || DecodedEventLevel == 26) {
                register unsigned char* statePointer __asm__("$16") = &moby->state;
                DecodedEventTimer(statePointer, 1, DecodedEventSpecialTimerData);
                DecodedEventTimer(statePointer, 1, DecodedEventTimerData);
            } else {
                DecodedEventTimer(&moby->state, 1, DecodedEventTimerData);
            }
            return;
        }
        /* Retain the saved state in the kind-1 comparison, as in retail. */
        case 1:
            MATCHING_OBSERVE_CLOBBER(moby, "$4");
            if (DecodedEventTick < 5)
                goto finish;
            {
                register Moby* soundArgument __asm__("$4") = moby;
                if (tag->soundIndex != -1)
                    DecodedEventSound(soundArgument, tag->soundIndex, 0);
            }
            kind = tag->kind;
            /* The three kinds use distinct original spawn/helper paths. */
            if (kind == 0) {
                MATCHING_KEEP(kind);
                if (tag->classOrCount >= 0)
                    SpawnFragments(tag->countOrClass, tag->classOrCount, moby, tag->offsets, 0,
                                   0x200);
            } else if (kind == state) {
                if (tag->classOrCount < 0 || tag->countOrClass <= 0)
                    goto finish;
                DecodedEventPrepare(moby, 4);
                count = 0;
                if (tag->countOrClass > 0) {
                    cursor = 0;
                    do {
                        register Moby* spawned __asm__("$16") = SpawnMoby(tag->classOrCount, moby);
                        if (spawned) {
                            DecodedEventCopy(&offset, (unsigned char*)tag->offsets + cursor);
                            DecodedEventRotate(&moby->rotationMatrix, &offset, &offset);
                            DecodedEventAdd(&spawned->position, &spawned->position, &offset);
                        }
                        limit = tag->countOrClass;
                        __asm__("" : "=r"(count) : "0"(count), "r"(limit));
                        count++;
                        cursor += 12;
                    } while (count < limit);
                }
            } else if (kind == 2) {
                if (tag->classOrCount < 0 || !tag->recordList)
                    goto finish;
                cursor = 0;
                if (tag->recordList->count <= 0)
                    goto finish;
                directionPointer = &direction;
                do {
                    /* The retail pointer slot holds the Moby, then its tag. */
                    register void* spawnedData __asm__("$16") = SpawnMoby(tag->classOrCount, moby);
                    register Vector3D* position __asm__("$17");
                    MATCHING_KEEP(spawnedData);
                    position = &((Moby*)spawnedData)->position;
                    if (spawnedData) {
                        short* spawnedTag;
                        {
                            register Vector3D* copyArgument __asm__("$4") = position;
                            MATCHING_OBSERVE(copyArgument);
                            {
                                register unsigned char* records __asm__("$2") =
                                    (unsigned char*)tag->recordList;
                                register int recordOffset __asm__("$5");
                                MATCHING_KEEP(records);
                                recordOffset = cursor * 16;
                                records = ((DecodedEventRecords*)records)->records;
                                spawnedData = ((Moby*)spawnedData)->mobyTag;
                                spawnedTag = spawnedData;
                                DecodedEventCopy(copyArgument, records + recordOffset);
                            }
                        }
                        DecodedEventSubtract(directionPointer, position, &moby->position);
                        DecodedEventScale(directionPointer, DecodedEventLength(directionPointer, 1),
                                          90);
                        /* Preserve the original halfword writes and subsequent overwrites. */
                        spawnedTag[0] += (DecodedEventCos[moby->angle.yaw] * 15) >> 9;
                        spawnedTag[1] += (DecodedEventSin[moby->angle.yaw] * 15) >> 9;
                        spawnedTag[0] = direction.x;
                        spawnedTag[1] = direction.y;
                        spawnedTag[2] = direction.z;
                    }
                    cursor++;
                } while (cursor < tag->recordList->count);
            }
        /* Every state-1 path reaches the original target call and removal helper. */
        finish:
            DecodedEventTarget(tag->targetIndex, 0xFC, 0);
            func_80055B18(moby);
            return;
        default:
            return;
    }
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
void func_level_40_800806A8(Moby* moby) {
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
void func_level_40_800809D8(Moby* actor) {
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
void func_level_40_80080BE4(Moby* argument) {
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

/* AI generated; not yet human reviewed. Derived from SCUS-94467 USA Rev 0
 * original controller instructions and its eleven-entry dispatch table.
 * Byte offsets, signed loads, word loads, shifts, and branch conditions
 * preserve the disc representation. Physical units, helper meanings, and
 * caller cadence remain unresolved; this routine describes one invocation.
 * Empty compiler constraints preserve original registers and scheduling;
 * they emit no instructions. Linked instructions and owned table/padding
 * must match every original copy before this source is accepted.
 */
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
void func_level_40_8008110C(void* input) {
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
                    Controller821F8SpawnFragments(0xD, 0x1F5, owner, Controller821F8D_80065398, 0,
                                                  0x100);
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

#undef Controller821F8Field

void func_level_40_80082260(Moby* moby) {
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
void func_level_40_80082280(Moby* argument) {
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

extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_40_80082480(Moby* moby) {
    if (D_8006C770 != 0)
        func_80055B18(moby);
}
