#include "matching.h"
#include "common.h"
#include "savepoint.h"
#include "camera.h"
#include "spu.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
#include "ovl_header.h"
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
void func_level_30_8007521C(void* input) {
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
void func_level_30_80075E78(Moby* argument) {
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
void func_level_30_80076504(void* input) {
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
void func_level_30_80077A54(Moby* argument) {
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

typedef struct {
    short timer;
    unsigned char selector, reserved03[17];
    Moby* selected;
} DecodedContainerLink;
extern int D_8006581C, D_80065810, D_80065818;
extern int D_8006C578, D_8006C574, D_8006C644;
extern Moby* D_8006C65C;
extern int DecodedContainerPlayerZ __asm__("D_80070328 + 8");
extern Vector3D DecodedContainerPlayer __asm__("D_80070328");
extern unsigned short DecodedContainerCos[] __asm__("D_80065920");
extern unsigned short DecodedContainerSin[] __asm__("D_800658A0");
int rand(void);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003BFC0(Moby*, int);
int func_8003BABC(Moby*, int, int);
void func_80036A68(Moby*, int, int, int);
void func_80055B18(Moby*);
/* Original selection gates and flag-triggered child/particle emission. */
void func_level_30_80077F74(Moby* moby) {
    Vector3D position, velocity;
    register DecodedContainerLink* link __asm__("$16");
    int distance, noise;
    register int index __asm__("$16");
    register int heightDifference __asm__("$3");
    register int raisedZ __asm__("$2");
    register int heightLimit __asm__("$2");
    register int childMode __asm__("$18");
    register int childAnimation __asm__("$19");
    if (!moby->substate)
        moby->substate = rand();
    if (D_8006581C >= 2) {
        distance = func_8004F334(&moby->position, &DecodedContainerPlayer);
        if (distance < D_80065810) {
            raisedZ = moby->position.z;
            heightDifference = DecodedContainerPlayerZ;
            raisedZ += 356;
            MATCHING_KEEP2(raisedZ, heightDifference);
            heightDifference -= raisedZ;
            heightLimit = D_80065818;
            MATCHING_BARRIER_VOLATILE("memory");
            if (heightDifference < 0)
                heightDifference = -heightDifference;
            MATCHING_KEEP(heightLimit);
            heightDifference = heightDifference < heightLimit;
            MATCHING_KEEP(heightDifference);
            if (heightDifference && D_8006C65C &&
                func_80013E38(&D_8006C65C->position, &moby->position, 0)) {
                link = D_8006C65C->mobyTag;
                MATCHING_KEEP(link);
                if (link->selected) {
                    if (link->selected != moby && link->timer > 0)
                        link->timer = 0;
                } else {
                    D_8006C65C->substate = 9;
                    link->selected = moby;
                    link->timer = 0;
                    if (!func_8003BFC0(D_8006C65C, link->selector))
                        link->selector = func_8003BABC(D_8006C65C, 0, 0);
                }
            }
        }
    }
    if (*(unsigned int*)((char*)moby + 24) & 0x101B0000) {
        func_8003BABC(moby, 0, 0);
        moby->substate = 100;
        index = 0;
        /* Empty constraints retain original constants and register lifetimes. */
        __asm__ volatile("" : : "r"(index) : "$18", "$19");
        childAnimation = 1;
        childMode = 9;
        MATCHING_KEEP2(childAnimation, childMode);
        for (; index < 12; index++) {
            Moby* child;
            if (D_8006C578 - D_8006C574 < 21)
                break;
            child = SpawnMoby(0x136, moby);
            if (child) {
                if (index < 6)
                    child->substate = childMode;
                else {
                    child->animationState.id = childAnimation;
                    child->substate = 0;
                }
            }
        }
        for (index = 0; index < 8; index++) {
            func_8004F178(&position, &moby->position);
            position.x += 128 - (rand() & 255);
            position.y += 128 - (rand() & 255);
            position.z += rand() & 511;
            velocity.x = 64 - (rand() & 127);
            velocity.y = 64 - (rand() & 127);
            velocity.z = 16 - (rand() & 31);
            SpawnParticle(1, 39, &position, &velocity);
            SpawnParticle(2, 70, &position, (Vector3D*)24);
        }
        func_80036A68(moby, 0, 0, 0);
        func_80055B18(moby);
    } else {
        moby->angle.roll =
            (int)(DecodedContainerCos[(D_8006C644 * 2 + moby->substate) & 255] << 16) >> 25;
        moby->angle.pitch =
            (int)(DecodedContainerSin[(D_8006C644 * 2 + moby->substate) & 255] << 16) >> 25;
    }
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
void func_level_30_800782F4(Moby* moby) {
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
extern unsigned char Controller78288D_80071597 __asm__("D_80071597");
extern int Controller78288D_8006C5BC __asm__("D_8006C5BC");
extern int Controller78288D_8006C73C __asm__("D_8006C73C");
int Controller78288ActivateSparxPowers() __asm__("ActivateSparxPowers");
int Controller78288Helper584BC() __asm__("func_800584BC");
void func_level_30_800785F8(void* input) {
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
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 11)
                                    goto checkPrefixFlags;
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                        if (Controller78288Field(prefixTag, unsigned char*, 0) == 11) {
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
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            {
                                register int rawOne4 __asm__("$4") = 1;
                                register int rawKind3 __asm__("$3");
                                register int nine2 __asm__("$2");
                                MATCHING_KEEP_CLOBBER(rawOne4, "$3");
                                rawKind3 = Controller78288Field(prefixTag, unsigned char*, 0);
                                MATCHING_KEEP_CLOBBER(rawKind3, "$2");
                                nine2 = 11;
                                MATCHING_KEEP3(rawOne4, rawKind3, nine2);
                                Controller78288Field(prefixTag, unsigned char*, 5) = rawOne4;
                                if (rawKind3 == nine2) {
                                    if ((Controller78288D_8006C73C == 38) &&
                                        (Controller78288D_80071597 == 0))
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
                                        if (address) {
                                            Controller78288Field(prefixTag, unsigned char*, 5) = 0;
                                            __asm__ volatile("" ::: "$2", "memory");
                                        }
                                    }
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
                            if (Controller78288Helper37BBC(owner, 0xC) != 0) {
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 11) {
                                    if (Controller78288D_80070300[Controller78288D_80066FD3[0x1F]] &
                                        1) {
                                        register unsigned char* flag3 __asm__("$3") =
                                            &Controller78288D_80071597;
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
                    if (Controller78288Field(prefixTag, unsigned char*, 0) != 11)
                        goto setSubstateFour;
                    {
                        register int prefix2 __asm__("$3") =
                            Controller78288Field(prefixTag, unsigned char*, 2);
                        register int three2 __asm__("$2") = 3;
                        register int one2 __asm__("$2");
                        register int arg5 __asm__("$5");
                        register int arg4 __asm__("$4");
                        MATCHING_KEEP2(prefix2, three2);
                        if (prefix2 != three2) {
                            one2 = 1;
                            goto storePrefixKind;
                        }
                        one2 = 1;
                        MATCHING_KEEP_CLOBBER(one2, "$5");
                        arg5 = Controller78288D_8006C5BC;
                        MATCHING_KEEP_CLOBBER(arg5, "$4");
                        arg4 = 4;
                        Controller78288Helper584BC(arg4, arg5 + 8);
                    storePrefixKind:;
                    }
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
void func_level_30_80079308(Moby* moby) {
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
void func_level_30_80079738(Moby* moby) {
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
void func_level_30_80079AA0(Moby* owner) {
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
void func_level_30_80079C2C(Moby* moby) {
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
void func_level_30_80079D80(Moby* moby) {
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
void func_level_30_80079FC0(Moby* actor) {
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

extern int deltaTime;
void func_80055B18(Moby*);
void func_level_30_8007A14C(Moby* moby) {
    int* countdown = moby->mobyTag;
    if (*countdown > 0)
        *countdown -= deltaTime * 2;
    else
        moby->size += deltaTime * 2;
    moby->position.z += deltaTime * 32;
    moby->angle.yaw += deltaTime * 8;
    if (moby->size >= 0x7C) {
        moby->position.z += 0x60;
        SpawnParticle(8, 0x47, &moby->position, 0);
        func_80055B18(moby);
    }
}

extern unsigned char Controller7C02CFlagPlayer[] __asm__("D_80070328");
#define Controller7C02CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller7C02Cfunc_8002803C(int, int, int, int, int, void*, int) __asm__("func_8002803C");
void* Controller7C02Cfunc_8002F540(int, int, int) __asm__("func_8002F540");
int Controller7C02CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller7C02Cfunc_8003BFC0(void*, int) __asm__("func_8003BFC0");
int Controller7C02CTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller7C02CCopyVector(void*, void*) __asm__("func_8004F178");
int Controller7C02CAddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller7C02CApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller7C02Crand(void) __asm__("rand");
extern unsigned char Controller7C02CD_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller7C02CD_80065920[] __asm__("D_80065920");
extern unsigned char Controller7C02CD_80067648[] __asm__("D_80067648");
extern unsigned char Controller7C02CD_80070328[] __asm__("D_80070328");
extern unsigned char Controller7C02Cg_CheatFlags[] __asm__("g_CheatFlags");
extern int Controller7C02CD_8006C58C __asm__("D_8006C58C");
extern int Controller7C02CD_8006C5BC __asm__("D_8006C5BC");
extern int Controller7C02CD_8006C640 __asm__("D_8006C640");
extern int Controller7C02CD_8006C648 __asm__("D_8006C648");
extern int Controller7C02Cunk_ovlheader_800743B8 __asm__("unk_ovlheader_800743B8");
extern int Controller7C02Cunk_ovlheader_800743BC __asm__("unk_ovlheader_800743BC");
extern int Controller7C02Cunk_ovlheader_800743C0 __asm__("unk_ovlheader_800743C0");
extern void* (*Controller7C02CSpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int (*Controller7C02CSpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original controller instructions and twelve-entry dispatch table are the
 * authority. Access widths, byte offsets, integer shifts and branch conditions
 * retain the disc representation. Physical units, helper meanings and caller
 * cadence are unresolved. Empty constraints only preserve compiler allocation;
 * they emit no instructions. The linked word audit and full hashes are the
 * falsifiable acceptance vectors; no semantic runtime parity is claimed here.
 */
void func_level_30_8007A224(void* input) {
    register unsigned char* owner __asm__("$18") = input;
    struct {
        int sp20, sp24, sp28, pad2C, sp30, sp34, sp38, pad3C;
    } frame;
    short childClass;
    unsigned char* attachedChild;
    unsigned char* temp_a0_5;
    unsigned char* temp_a0_6;
    unsigned char* temp_a1;
    register unsigned char* spawnedChild __asm__("$16");
    unsigned char* temp_v0_3;
    unsigned char* temp_v0_6;
    unsigned char* temp_v0_7;
    register unsigned char* temp_v1_11 __asm__("$3");
    unsigned char* temp_v1_3;
    register unsigned char* eventDestination __asm__("$21");
    register unsigned char* spawnedRecord __asm__("$17");
    register unsigned char* controller __asm__("$19");
    register unsigned char* childSlot __asm__("$16");
    register int temp_a0 __asm__("$4");
    int temp_a0_4;
    int temp_a3;
    int temp_hi;
    int distance;
    int nextTimer;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_8;
    int temp_v1;
    int timer;
    int temp_v1_6;
    int temp_v1_7;
    int temp_v1_8;
    int temp_v1_9;
    register int eventSelector __asm__("$16");
    register int childIndex __asm__("$17");
    register int childExtent __asm__("$20");
    register int crossedSide __asm__("$22");
    unsigned int temp_v1_10;
    unsigned char temp_a0_2;
    int state;
    MATCHING_KEEP_CLOBBER(owner, "$22");
    crossedSide = 0;
    controller = Controller7C02CField(owner, void**, 0);
    distance = Controller7C02CApproximatePlanarDistance(owner + 0xC, Controller7C02CD_80070328);
    Controller7C02CField(controller, int*, 0x14) = distance;
    if (distance < 0x1000) {
        {
            register int index __asm__("$3") = Controller7C02CField(owner, unsigned char*, 70);
            register int component __asm__("$2") =
                Controller7C02CField(Controller7C02CD_80070328, int*, 4);
            register int ownerComponent __asm__("$4") = Controller7C02CField(owner, int*, 16);
            register int firstProduct __asm__("$5");
            MATCHING_KEEP3(index, component, ownerComponent);
            index <<= 1;
            firstProduct = *(short*)(Controller7C02CD_800658A0 + index);
            component -= ownerComponent;
            firstProduct *= component;
            index = *(short*)(Controller7C02CD_80065920 + index);
            ownerComponent = Controller7C02CField(owner, int*, 12);
            component = Controller7C02CField(Controller7C02CD_80070328, int*, 0);
            MATCHING_KEEP4(firstProduct, index, ownerComponent, component);
            index = -index;
            component -= ownerComponent;
            index *= component;
            component = Controller7C02CField(controller, int*, 24);
            component >>= 31;
            temp_a0 = firstProduct - index;
            index = temp_a0 >> 31;
            index ^= component;
            MATCHING_KEEP(index);
            crossedSide = (unsigned int)index != 0;
            Controller7C02CField(controller, int*, 24) = temp_a0;
        }
    }
    timer = Controller7C02CField(controller, int*, 4);
    if (timer != 0) {
        nextTimer = timer - Controller7C02CD_8006C648;
        Controller7C02CField(controller, int*, 4) = nextTimer;
        if (nextTimer < 0) {
            Controller7C02CField(controller, int*, 4) = 0;
        }
        crossedSide = 0;
    }
    temp_a0_2 = Controller7C02CField(owner, unsigned char*, 0x50);
    if (temp_a0_2 != 0xFF) {
        temp_v0_3 = Controller7C02CSpawnMoby(temp_a0_2, owner);
        Controller7C02CField(controller, void**, 0x24) = temp_v0_3;
        if (temp_v0_3 != 0) {
            Controller7C02CCopyVector(temp_v0_3 + 0xC, owner + 0xC);
            temp_v1_3 = Controller7C02CField(controller, void**, 0x24);
            Controller7C02CField(temp_v1_3, int*, 0x14) =
                (int)(Controller7C02CField(temp_v1_3, int*, 0x14) + 0x580);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x46) =
                (unsigned char)Controller7C02CField(owner, unsigned char*, 0x46);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x4C) =
                (unsigned char)Controller7C02CField(owner, unsigned char*, 0x4C);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x52) =
                (unsigned char)Controller7C02CField(owner, unsigned char*, 0x52);
            if (Controller7C02CField(owner, unsigned char*, 0x50) == 0x21) {
                Controller7C02CField(Controller7C02CField(controller, void**, 0x24), int*, 0x54) =
                    0x2A606060;
            }
            Controller7C02CField(owner, unsigned char*, 0x50) = 0xFFU;
            goto updateAttachedChild;
        }
    } else {
    updateAttachedChild:
        attachedChild = Controller7C02CField(controller, void**, 0x24);
        if (attachedChild != 0) {
            childClass = Controller7C02CField(attachedChild, short*, 0x36);
            if (childClass == 0x21) {
                Controller7C02CField(attachedChild, unsigned char*, 0x46) =
                    (unsigned char)(Controller7C02CField(attachedChild, unsigned char*, 0x46) +
                                    (Controller7C02CD_8006C648 * 2));
            } else if (childClass == 0x22) {
                Controller7C02CField(attachedChild, unsigned char*, 0x44) =
                    (unsigned char)(Controller7C02CField(attachedChild, unsigned char*, 0x44) +
                                    (Controller7C02CD_8006C648 * 4));
            }
        }
    }
    state = Controller7C02CField(owner, unsigned char*, 72);
    if (!state) {
        Controller7C02CField(owner, unsigned char*, 72) = 1;
        return;
    }
    switch (state) {
        case 1:
            break;
        default:
            return;
    }
    if ((Controller7C02CField(owner, unsigned char*, 0x4D) != 0) &&
        (Controller7C02CField(controller, int*, 0x14) < 0x4000) &&
        !(Controller7C02Crand() & 0x3F)) {
        spawnedChild = Controller7C02CSpawnMoby(0x1CBU, owner);
        spawnedRecord = Controller7C02CField(spawnedChild, void**, 0);
        {
            register int factor __asm__("$2") = Controller7C02Crand();
            register int trig __asm__("$3") = Controller7C02CField(owner, unsigned char*, 70);
            int product;
            MATCHING_KEEP2(factor, trig);
            factor &= 2;
            trig <<= 1;
            trig = *(unsigned short*)(Controller7C02CD_800658A0 + trig);
            factor -= 1;
            trig = (trig << 16) >> 18;
            product = trig * factor;
            trig = Controller7C02CField(spawnedChild, int*, 12);
            trig += product;
            Controller7C02CField(spawnedChild, int*, 12) = trig;
            trig = Controller7C02CField(owner, unsigned char*, 70);
            trig <<= 1;
            trig = *(short*)(Controller7C02CD_80065920 + trig);
            trig = -trig;
            trig >>= 2;
            MATCHING_KEEP2_CLOBBER(trig, factor, "memory");
            product = trig * factor;
            factor = 32;
            Controller7C02CField(spawnedChild, unsigned char*, 79) = factor;
            factor = Controller7C02CField(spawnedChild, int*, 16);
            trig = 5;
            Controller7C02CField(spawnedChild, unsigned char*, 71) = trig;
            factor += product;
            Controller7C02CField(spawnedChild, int*, 16) = factor;
        }
        *(int*)spawnedRecord = 0xE;
    }
    if (Controller7C02Cfunc_8003BFC0(owner, Controller7C02CField(controller, int*, 0x20)) == 0) {
        Controller7C02CField(controller, int*, 0x20) =
            Controller7C02CPlayMobySoundEvent(owner, 0, 4);
    }
    if (Controller7C02CField(owner, unsigned char*, 0x4D) != 0) {
        temp_a0_4 = Controller7C02CField(controller, int*, 0x14);
        if ((temp_a0_4 <= 0x9FFF) && (!(Controller7C02CD_8006C640 & 3) ||
                                      (!(Controller7C02CD_8006C640 & 1) && (temp_a0_4 < 0x5000)))) {
            frame.sp20 = 0;
            frame.sp24 = 0x352 - (Controller7C02Crand() % 1700);
            frame.sp28 = 0;
            Controller7C02CTransformVectorByBasis(owner + 32, &frame.sp20, &frame.sp20);
            Controller7C02CAddVector(&frame.sp20, &frame.sp20, owner + 0xC);
            Controller7C02CSpawnParticle(1, 4, &frame.sp20,
                                         Controller7C02CField(owner, int*, 0x14) + 0x640);
        }
    }
    temp_v1_7 = Controller7C02CField(controller, int*, 0x28);
    if (temp_v1_7 != 0) {
        Controller7C02CField(controller, int*, 0x28) = (int)(temp_v1_7 - 1);
        if (Controller7C02CField(controller, int*, 0x14) >= 0x601) {
            Controller7C02CField(controller, int*, 0x28) = 0;
        }
        {
            register void* vector __asm__("$16") = &frame.sp30;
            register int arg4 __asm__("$4");
            register int arg5 __asm__("$5");
            register void* arg6 __asm__("$6");
            register int arg7 __asm__("$7");
            Controller7C02CCopyVector(vector, Controller7C02CD_80070328);
            arg4 = 4;
            arg5 = 71;
            arg6 = vector;
            arg7 = 0;
            __asm__(""
                    : "=r"(arg4), "=r"(arg5), "=r"(arg6), "=r"(arg7)
                    : "0"(arg4), "1"(arg5), "2"(arg6), "3"(arg7)
                    : "$17", "$20", "memory");
            childIndex = 0;
            childExtent = 1740;
            childSlot = controller;
            frame.sp38 -= 64;
            Controller7C02CSpawnParticle(arg4, arg5, arg6, arg7);
        }
        do {
            if (Controller7C02CField(controller, int*, 0x28) == 0) {
                temp_v0_6 = Controller7C02CField(childSlot, void**, 0x2C);
                if (temp_v0_6 != 0) {
                    Controller7C02CField(temp_v0_6, signed char*, 0x1C) = 0;
                    Controller7C02CField(childSlot, void**, 0x2C) = 0;
                }
            } else if (Controller7C02CField(childSlot, void**, 0x2C) == 0) {
                temp_v0_7 = Controller7C02Cfunc_8002F540(4, 1, 0x608080);
                Controller7C02CField(childSlot, void**, 0x2C) = temp_v0_7;
                if (temp_v0_7 != 0) {
                    goto initializeChildSlot;
                }
            } else {
            initializeChildSlot:
                Controller7C02CField(Controller7C02CField(childSlot, void**, 0x2C), void**, 0) = 0;
                if (childIndex == 0) {
                    Controller7C02CField(Controller7C02CField(controller, void**, 0x2C), int*, 4) =
                        0x400;
                    Controller7C02CField(Controller7C02CField(controller, void**, 0x2C), int*, 8) =
                        childExtent;
                } else {
                    Controller7C02CField(Controller7C02CField(childSlot, void**, 0x2C), int*, 4) =
                        -0x400;
                    Controller7C02CField(Controller7C02CField(childSlot, void**, 0x2C), int*, 8) =
                        childExtent;
                }
                temp_a1 = Controller7C02CField(childSlot, void**, 0x2C);
                Controller7C02CTransformVectorByBasis(owner + 0x20, temp_a1, temp_a1);
                temp_a0_5 = Controller7C02CField(childSlot, void**, 0x2C);
                Controller7C02CAddVector(temp_a0_5, temp_a0_5, owner + 0xC);
                Controller7C02CCopyVector(Controller7C02CField(childSlot, void**, 0x2C) + 0xC,
                                          &frame.sp30);
            }
            childIndex += 1;
            childSlot += 4;
        } while (childIndex < 2);
    }
    Controller7C02CField(owner, int*, 0x54) = 0x30C0C0C0;
    Controller7C02CField(owner, unsigned char*, 0x57) =
        (unsigned char)(Controller7C02CField(owner, unsigned char*, 0x57) +
                        (Controller7C02Crand() & 3));
    temp_v1_8 = Controller7C02CField(controller, int*, 0x14);
    if ((temp_v1_8 < 0x1000) && (crossedSide != 0) && (temp_v1_8 < 0x380)) {
        temp_v1_9 =
            Controller7C02CField(owner, int*, 0x14) - Controller7C02CField(owner, short*, 0x38);
        temp_v0_8 = temp_v1_9 - Controller7C02CField(Controller7C02CD_80070328, int*, 8);
        if (temp_v0_8 >= 0) {
            if (temp_v0_8 < 0x680) {
                goto checkPlayerState;
            }
        } else if ((Controller7C02CField(Controller7C02CD_80070328, int*, 8) - temp_v1_9) < 0x680) {
        checkPlayerState:
            if (Controller7C02CField(Controller7C02CD_80070328, int*, 0x280) >= 0) {
                temp_v1_10 = Controller7C02CField(controller, unsigned int*, 8);
                Controller7C02CField(controller, int*, 0x28) = 8;
                eventSelector = 0;
                switch (temp_v1_10) {
                    /* switch 2 */
                    case 0: /* switch 2 */
                    {
                        register unsigned char* base __asm__("$2") =
                            Controller7C02CD_80070328 + 0x1CC;
                        MATCHING_KEEP(base);
                        eventDestination = base;
                    }
                        eventSelector = 8;
                        *(int*)eventDestination = (int)Controller7C02CField(controller, int*, 0);
                        break;
                    case 1: /* switch 2 */
                        Controller7C02CField(Controller7C02CD_80070328, int*, 0x1C4) = 1;
                        Controller7C02CField(Controller7C02CD_80070328, int*, 0x1C8) = 1;
                        Controller7C02CField(controller, int*, 4) = 0x3C;
                        if (Controller7C02CField(Controller7C02CD_80070328, int*, 0x50) == 9) {
                            Controller7C02CField(controller, int*, 0) += 1;
                        } else {
                            Controller7C02CField(controller, int*, 0) = 0;
                        }
                        break;
                    case 3: /* switch 2 */
                    {
                        register unsigned char* base __asm__("$2") =
                            Controller7C02CD_80070328 + 0x1D0;
                        MATCHING_KEEP(base);
                        eventDestination = base;
                    }
                        eventSelector = 9;
                        *(int*)eventDestination = (int)Controller7C02CField(controller, int*, 0);
                        break;
                    case 2: {
                        register unsigned char* base __asm__("$2") =
                            Controller7C02CD_80070328 + 0x1BC;
                        register int word __asm__("$4");
                        register int level __asm__("$3");
                        register int one __asm__("$2");
                        MATCHING_KEEP(base);
                        eventDestination = base;
                        word = Controller7C02CField(controller, int*, 0);
                        level = Controller7C02CD_8006C58C;
                        MATCHING_KEEP2(word, level);
                        one = 1;
                        Controller7C02CField(Controller7C02CFlagPlayer, int*, 0x1C0) = one;
                        MATCHING_KEEP_CLOBBER(level, "memory");
                        level <<= 2;
                        *(int*)eventDestination = word;
                        one = *(int*)(Controller7C02CD_80067648 + level);
                        Controller7C02CField(Controller7C02CD_80070328, int*, 0xF8) = one;
                        eventSelector = 10;
                    } break;
                    case 11: {
                        register int word __asm__("$4") = Controller7C02CField(controller, int*, 0);
                        register int value __asm__("$2");
                        register unsigned char* base __asm__("$3");
                        MATCHING_KEEP(word);
                        value = 1;
                        Controller7C02CField(Controller7C02CFlagPlayer, int*, 0x1C0) = value;
                        value = Controller7C02CD_8006C58C;
                        __asm__("" : "=r"(value) : "0"(value) : "$3", "memory");
                        base = Controller7C02CD_80070328 + 0x1BC;
                        MATCHING_KEEP2(value, base);
                        value <<= 2;
                        *(int*)base = word;
                        value = *(int*)(Controller7C02CD_80067648 + value);
                        Controller7C02CField(Controller7C02CD_80070328, int*, 0xF8) = value;
                        value = Controller7C02CField(controller, int*, 0);
                        eventDestination = base + 20;
                        Controller7C02CField(base, int*, 20) = value;
                        if (Controller7C02CD_8006C5BC == 50)
                            eventSelector = 10;
                    } break;
                    case 10: /* switch 2 */
                        Controller7C02CField(Controller7C02Cg_CheatFlags, signed char*, 3) = 1;
                        break;
                }
                temp_a0_6 = Controller7C02CField(controller, void**, 0x24);
                if (temp_a0_6 != 0) {
                    Controller7C02CPlayMobySoundEvent(temp_a0_6, 0, 0);
                }
                if (eventSelector != 0) {
                    Controller7C02Cfunc_8002803C(4, eventSelector,
                                                 Controller7C02Cunk_ovlheader_800743B8,
                                                 Controller7C02Cunk_ovlheader_800743C0,
                                                 Controller7C02Cunk_ovlheader_800743BC,
                                                 eventDestination, *(int*)eventDestination);
                }
            }
        }
    }
    return;
}
#undef Controller7C02CField


/* This caller only reads the signed halfword at tag +0xC. */
typedef struct {
    unsigned char reserved00[0xC];
    short unkC;
} DecodedCloneTag;
extern int D_8006C578, D_8006C574;
void func_level_30_8007A9EC(Moby* moby) {
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

typedef struct {
    Moby* parent;
    unsigned char unk4, unk5;
} DecodedYawTag;
extern int D_8006C644;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_level_30_8007AAC4(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007AB74.
* AI generated; not human reviewed. All821 original instructions and8
* selector words must match, including every actual native/linked target.
* FrameF0 saves S0..S7/FP/RA and retains all SP10..C7 original locals.
* Heading difference occupies FP naturally; no fixedFP or invented input.
* Word vectors and the final SP80..82 packed-byte views retain original
* widths. All LH table samples remain full signed words before SRA1/5.
* Independent readonly table views use distinct spellings of zero addends
* to retain each original address producer without persistent base spills;
* every view resolves to the unchanged original65920/658A0 address.
* Original retained distance in A1 reaches F08C unchanged while A2 uses
* signed truncating division and the native0..128 clamp. Render byte stores,
* control words, all vector load delays and both particle counter lifetimes
* retain the original ordering. Helper arities reuse existing verified
* mobyutil/stdutil/ovl_header and original zero-input rand evidence.
* Empty metadata reads only full initialized values or clobbers dead
* registers before new producers. It emits zero CPU instructions. No
* opcode assembly, partialHI, overlapping live aliases or pipeline changes.
* Original units/fixed point, complete helper/caller meanings and cadence
* beyond invocation remain unresolved. Confidence is binary identity only
* after all gates; next evidence is human review and retail runtime capture.
* Falsification: all native/linked words, actual branch/call/table targets,
* owned data and full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 d09ebe009cd36f8e4cf2b694a441f6f1aa42b5da7b5ca209a49c002dd6e89717 */
#define Level30_7AB74Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level30_7AB74Call136F0View1() __asm__("func_800136F0");
int Level30_7AB74Call13AE4View1() __asm__("func_80013AE4");
int Level30_7AB74Call13B7CView1() __asm__("func_80013B7C");
int Level30_7AB74Call13D44View1() __asm__("func_80013D44");
void Level30_7AB74RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level30_7AB74CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level30_7AB74Call36220View1() __asm__("func_80036220");
int Level30_7AB74Call3B7B4View1() __asm__("func_8003B7B4");
int Level30_7AB74PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level30_7AB74PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level30_7AB74BuildPackedAngleBasisMatrixView1() __asm__("func_8004EA90");
int Level30_7AB74TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level30_7AB74MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level30_7AB74ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level30_7AB74CopyVectorView1() __asm__("func_8004F178");
int Level30_7AB74AddVectorView1() __asm__("func_8004F194");
int Level30_7AB74SubtractVectorView1() __asm__("func_8004F1C8");
int Level30_7AB74AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level30_7AB74ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level30_7AB74RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level30_7AB74Call55E84View1() __asm__("func_80055E84");
int Level30_7AB74DatarandView1(void) __asm__("rand");
extern int Level30_7AB74Data658A0View1 __asm__("D_800658A0");
extern int Level30_7AB74Data65920View1 __asm__("D_80065920");
extern int Level30_7AB74Data6C58CView1 __asm__("D_8006C58C");
extern int Level30_7AB74Data6C65CView1 __asm__("D_8006C65C");
extern int Level30_7AB74Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level30_7AB74Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level30_7AB74Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level30_7AB74Data6E048View1 __asm__("D_8006E048");
extern int Level30_7AB74Data6E160View1 __asm__("D_8006E160");
extern int Level30_7AB74Data6E17CView1 __asm__("D_8006E17C");
extern int Level30_7AB74Data70300View1 __asm__("D_80070300");
extern int Level30_7AB74Data70328View1 __asm__("D_80070328");
extern void* (*Level30_7AB74DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
extern int (*Level30_7AB74Data74398View1)() __asm__("unk_ovlheader_80074398");
extern short Level30_7AB74Data65920View2 __asm__("D_80065920 + 0x0");
extern short Level30_7AB74Data658A0View2 __asm__("D_800658A0 + 0x00");
extern short Level30_7AB74Data65920View3 __asm__("D_80065920 + 0x000");
extern short Level30_7AB74Data658A0View3 __asm__("D_800658A0 + 0x0000");
extern short Level30_7AB74Data65920View4 __asm__("D_80065920 + 0x00000");
extern short Level30_7AB74Data658A0View4 __asm__("D_800658A0 + 0x000000");
extern short Level30_7AB74Data65920View5 __asm__("D_80065920 + 0x0000000");
extern short Level30_7AB74Data658A0View5 __asm__("D_800658A0 + 0x00000000");
extern short Level30_7AB74Data65920View6 __asm__("D_80065920 + 0x000000000");
extern short Level30_7AB74Data658A0View6 __asm__("D_800658A0 + 0x0000000000");
extern short Level30_7AB74Data65920View7 __asm__("D_80065920 + 0x00000000000");
extern short Level30_7AB74Data658A0View7 __asm__("D_800658A0 + 0x000000000000");
extern short Level30_7AB74Data65920View8 __asm__("D_80065920 + 0x0000000000000");
extern short Level30_7AB74Data658A0View8 __asm__("D_800658A0 + 0x00000000000000");
extern short Level30_7AB74Data65920View9 __asm__("D_80065920 + 0x000000000000000");
extern short Level30_7AB74Data658A0View9 __asm__("D_800658A0 + 0x0000000000000000");
void func_level_30_8007AB74(void* input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord19 __asm__("$19");
    register int privateRecord20 __asm__("$20"), retainedAddressOrCounter16 __asm__("$16"),
        retainedAddressOrConstant17 __asm__("$17"), retainedVectorAddress18 __asm__("$18"),
        retainedOwnerVector21 __asm__("$21"), retainedDistance22 __asm__("$22"),
        retainedAbsoluteHeight23 __asm__("$23");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4,
            spB8, spBC, spC0, spC4;
    } originalFrame;
    int retainedHeadingDifference;
    ownerRecord19 = input;
    MATCHING_KEEP(ownerRecord19);
    argumentWord6 = 0;
    MATCHING_KEEP(argumentWord6);
    retainedAddressOrCounter16 = (int)&Level30_7AB74Data70328View1;
    rawWord3 = Level30_7AB74Field(retainedAddressOrCounter16, int*, 0);
    argumentWord4 = Level30_7AB74Field(ownerRecord19, int*, 12);
    rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 4);
    argumentWord5 = Level30_7AB74Field(ownerRecord19, int*, 16);
    privateRecord20 = Level30_7AB74Field(ownerRecord19, int*, 0);
    rawWord2 = Level30_7AB74PlanarHeadingLookupView1(rawWord3 - argumentWord4,
                                                     rawWord2 - argumentWord5, argumentWord6);
    argumentWord4 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
    retainedHeadingDifference = Level30_7AB74AbsoluteByteAngleDeltaView1(argumentWord4, rawWord2);
    rawWord2 = Level30_7AB74ApproximatePlanarDistanceView1((int)ownerRecord19 + 12,
                                                           retainedAddressOrCounter16);
    argumentWord4 = Level30_7AB74Field(ownerRecord19, short*, 0x38);
    rawWord3 = Level30_7AB74Field(ownerRecord19, int*, 20);
    argumentWord5 = Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 8);
    rawWord3 -= argumentWord4;
    retainedAbsoluteHeight23 = rawWord3 - argumentWord5;
    retainedDistance22 = rawWord2;
    if (retainedAbsoluteHeight23 < 0)
        retainedAbsoluteHeight23 = argumentWord5 - rawWord3;
    rawWord3 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49);
    switch (rawWord3) {
        case 0:
            if ((({
                    rawWord2 = retainedHeadingDifference < 0x18;
                    MATCHING_KEEP(rawWord2);
                    rawWord2;
                })) &&
                (({
                    rawWord2 = retainedDistance22 < 0x2000;
                    MATCHING_KEEP(rawWord2);
                    rawWord2;
                })) &&
                (({
                    rawWord2 = retainedAbsoluteHeight23 < 0x800;
                    MATCHING_KEEP(rawWord2);
                    rawWord2;
                })) &&
                !(Level30_7AB74Data6C7B4View1 & 8) && ({
                    rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data70300View1, unsigned char*,
                                                  Level30_7AB74Data6C58CView1);
                    rawWord2 &= 8;
                    !rawWord2;
                })) {
                rawWord2 = (retainedDistance22 - 4096) / 64;
                Level30_7AB74Field(privateRecord20, int*, 0) = rawWord2;
                if (rawWord2 < 0) {
                    Level30_7AB74Field(privateRecord20, int*, 0) = 0;
                }
                if (({
                        rawWord2 = retainedDistance22 < 0x1000;
                        MATCHING_KEEP(rawWord2);
                        rawWord2;
                    })) {
                    Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                }
            } else {
                Level30_7AB74Field(privateRecord20, int*, 0) =
                    (int)(Level30_7AB74Field(privateRecord20, int*, 0) + 4);
            }
            if (Level30_7AB74Field(privateRecord20, int*, 0) >= 0x41) {
                Level30_7AB74Field(privateRecord20, int*, 0) = 0x40;
            }
            argumentWord4 = (int)ownerRecord19;
            argumentWord6 = privateRecord20;
            argumentWord5 = Level30_7AB74Field(privateRecord20, int*, 0x24);
            rawWord3 = (int)Level30_7AB74Data74398View1;
            rawWord2 = 128;
            Level30_7AB74Field(privateRecord20, int*, 0x1C) = rawWord2;
            rawWord2 = 256;
            Level30_7AB74Field(privateRecord20, int*, 0x20) = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 = Level30_7AB74Field(privateRecord20, int*, 4);
            __asm__("" ::: "$4", "memory");
            argumentWord4 = (int)ownerRecord19;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
            rawWord2 &= 15;
            Level30_7AB74Field(ownerRecord19, unsigned char*, 0x54) = rawWord2;
            rawWord2 = Level30_7AB74Field(privateRecord20, int*, 8);
            __asm__("" ::: "$5", "memory");
            argumentWord5 = 4;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
            rawWord2 &= 15;
            Level30_7AB74Field(ownerRecord19, unsigned char*, 0x55) = rawWord2;
            rawWord2 = Level30_7AB74Field(privateRecord20, int*, 12);
            __asm__("" ::: "$3", "memory");
            rawWord3 = 64;
            Level30_7AB74Field(ownerRecord19, unsigned char*, 0x57) = rawWord3;
            __asm__(""
                    : "=r"(rawWord2)
                    : "0"(rawWord2), "m"(Level30_7AB74Field(ownerRecord19, unsigned char*, 0x57)));
            rawWord2 &= 15;
            Level30_7AB74Field(ownerRecord19, unsigned char*, 0x56) = rawWord2;
            Level30_7AB74RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
            break;
        case 1:
            if (Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48) != 1) {
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 0U;
            } else {
                argumentWord4 = (int)&originalFrame.sp10;
                rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                __asm__("" ::: "$5", "memory");
                argumentWord5 = argumentWord4;
                rawWord2 *= 2;
                rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View2, short*, rawWord2);
                __asm__("" ::: "$21", "memory");
                retainedOwnerVector21 = (int)ownerRecord19 + 12;
                __asm__(""
                        : "=r"(rawWord2), "=&r"(retainedOwnerVector21)
                        : "0"(rawWord2), "1"(retainedOwnerVector21),
                          "r"(retainedHeadingDifference));
                rawWord2 >>= 1;
                originalFrame.sp10 = rawWord2;
                rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                __asm__("" ::: "$6", "memory");
                argumentWord6 = retainedOwnerVector21;
                rawWord2 *= 2;
                rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View2, short*, rawWord2);
                __asm__("" ::: "$3", "memory");
                rawWord3 = 1024;
                originalFrame.sp18 = rawWord3;
                __asm__(""
                        : "=r"(rawWord2)
                        : "0"(rawWord2), "r"(rawWord3), "m"(originalFrame.sp18));
                rawWord2 >>= 1;
                originalFrame.sp14 = rawWord2;
                Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                retainedVectorAddress18 = (int)&Level30_7AB74Data70328View1 + 0x21C;
                Level30_7AB74SubtractVectorView1(retainedVectorAddress18, &originalFrame.sp10,
                                                 retainedVectorAddress18 - 0x21C);
                rawWord2 = Level30_7AB74MeasureVectorLengthView1(retainedVectorAddress18, 1);
                retainedAddressOrCounter16 = (int)&Level30_7AB74Data65920View3;
                retainedAddressOrConstant17 = (int)&Level30_7AB74Data658A0View3;
                argumentWord5 = rawWord2;
                rawWord2 = argumentWord5 < 513;
                argumentWord6 = retainedOwnerVector21;
                if (rawWord2) {
                    rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                    MATCHING_KEEP(rawWord2);
                    rawWord2 *= 2;
                    rawWord2 += retainedAddressOrCounter16;
                    rawWord2 = Level30_7AB74Field(rawWord2, short*, 0);
                    __asm__("" ::: "$16", "memory");
                    retainedAddressOrCounter16 = (int)&originalFrame.sp20;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(retainedAddressOrCounter16));
                    rawWord2 >>= 1;
                    originalFrame.sp20 = rawWord2;
                    rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                    __asm__("" ::: "$4", "memory");
                    argumentWord4 = retainedAddressOrCounter16;
                    rawWord2 *= 2;
                    rawWord2 += retainedAddressOrConstant17;
                    rawWord2 = Level30_7AB74Field(rawWord2, short*, 0);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = retainedAddressOrCounter16;
                    originalFrame.sp28 = 0;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(argumentWord5), "m"(originalFrame.sp28));
                    rawWord2 >>= 1;
                    originalFrame.sp24 = rawWord2;
                    Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x20C) = 0x1001A000;
                    originalFrame.sp28 += 0x400;
                    Level30_7AB74CopyVectorView1(retainedVectorAddress18 + 0x10,
                                                 &originalFrame.sp20);
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x23C) = 0x28;
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x228) = 0;
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x229) = 0;
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 0x22A) =
                        (unsigned char)Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                    if (Level30_7AB74Data6C65CView1 != 0) {
                        Level30_7AB74Field(Level30_7AB74Data6C65CView1, signed char*, 0x4C) = 0;
                        Level30_7AB74Field(Level30_7AB74Data6C65CView1, signed char*, 0x4D) = 0;
                    }
                    Level30_7AB74Field(privateRecord20, int*, 0x48) = 0x3C;
                    Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 2U;
                    Level30_7AB74PlayMobySoundEventView1(ownerRecord19, 0, 0);
                    Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    Level30_7AB74RequestMobyAnimationView1(ownerRecord19, 0);
                } else {
                    MATCHING_BARRIER("$2");
                    argumentWord6 = (8192 - argumentWord5) / 64;
                    if (({
                            rawWord2 = argumentWord6 < 129;
                            MATCHING_KEEP(rawWord2);
                            !rawWord2;
                        })) {
                        argumentWord6 = 0x80;
                    }
                    if (argumentWord6 < 0) {
                        argumentWord6 = 0;
                    }
                    MATCHING_BARRIER("$4");
                    argumentWord4 = retainedVectorAddress18;
                    Level30_7AB74ScaleVectorRatioQ15View1(argumentWord4, argumentWord5,
                                                          argumentWord6);
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x20C) = 0x10000008;
                    Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 0x22A) =
                        0U;
                }
            }
            break;
        case 2:
            retainedVectorAddress18 = (int)&originalFrame.sp30;
            rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            __asm__("" ::: "$4", "memory");
            argumentWord4 = retainedVectorAddress18;
            rawWord2 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View4, short*, rawWord2);
            __asm__("" ::: "$5", "memory");
            argumentWord5 = retainedVectorAddress18;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
            rawWord2 >>= 1;
            originalFrame.sp30 = rawWord2;
            rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            __asm__("" ::: "$17", "memory");
            retainedAddressOrConstant17 = (int)ownerRecord19 + 12;
            rawWord2 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View4, short*, rawWord2);
            __asm__("" ::: "$6", "memory");
            argumentWord6 = retainedAddressOrConstant17;
            originalFrame.sp38 = 0;
            __asm__(""
                    : "=r"(rawWord2)
                    : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp38));
            rawWord2 >>= 1;
            originalFrame.sp34 = rawWord2;
            Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            rawWord3 = 0x1001A000;
            retainedAddressOrCounter16 = (int)&Level30_7AB74Data70328View1 + 0x20C;
            MATCHING_KEEP(retainedAddressOrCounter16);
            argumentWord4 = retainedAddressOrCounter16 + 32;
            rawWord2 = originalFrame.sp38;
            Level30_7AB74Field(retainedAddressOrCounter16, int*, 0) = rawWord3;
            rawWord2 += 1024;
            originalFrame.sp38 = rawWord2;
            Level30_7AB74CopyVectorView1(argumentWord4, &originalFrame.sp30);
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x23C) = 0x28;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x228) = 0;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x229) = 0;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 0x22A) =
                (unsigned char)Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            MATCHING_KEEP(rawWord2);
            rawWord2 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View5, short*, rawWord2);
            __asm__("" ::: "$4", "memory");
            argumentWord4 = retainedVectorAddress18;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
            originalFrame.sp30 = rawWord2;
            rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            __asm__("" ::: "$5", "memory");
            argumentWord5 = retainedVectorAddress18;
            rawWord2 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View5, short*, rawWord2);
            __asm__("" ::: "$6", "memory");
            argumentWord6 = retainedAddressOrConstant17;
            originalFrame.sp38 = 0;
            __asm__(""
                    : "=r"(rawWord2)
                    : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp38));
            originalFrame.sp34 = rawWord2;
            Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            retainedAddressOrConstant17 = (int)&Level30_7AB74Data6E17CView1;
            argumentWord4 = retainedAddressOrConstant17;
            MATCHING_KEEP(argumentWord4);
            retainedAddressOrCounter16 -= 524;
            MATCHING_KEEP(retainedAddressOrCounter16);
            rawWord2 = originalFrame.sp38;
            __asm__("" ::: "$5", "memory");
            argumentWord5 = retainedAddressOrCounter16;
            rawWord2 += 1024;
            originalFrame.sp38 = rawWord2;
            Level30_7AB74CopyVectorView1(argumentWord4, argumentWord5);
            Level30_7AB74Call136F0View1(retainedAddressOrConstant17 - 20, &originalFrame.sp30,
                                        retainedAddressOrCounter16);
            Level30_7AB74Data6E160View1 = 0x11;
            if (Level30_7AB74CountTimerDownView1(privateRecord20 + 0x48, 4) != 0) {
                rawWord2 = Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x28),
                                              void**, 0xC);
                argumentWord7 = Level30_7AB74Field(rawWord2, int*, 0x10);
                Level30_7AB74Call13D44View1(
                    Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x28), void**,
                                       0xC),
                    Level30_7AB74PlanarHeadingLookupView1(argumentWord7 -
                                                              Level30_7AB74Field(rawWord2, int*, 0),
                                                          Level30_7AB74Field(rawWord2, int*, 0x14) -
                                                              Level30_7AB74Field(rawWord2, int*, 4),
                                                          0),
                    0, 0x29);
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 3U;
            }
            break;
        case 3:
            if (Level30_7AB74Data6E048View1 == 1) {
                if (Level30_7AB74Data6C65CView1 != 0) {
                    Level30_7AB74Field(Level30_7AB74Data6C65CView1, signed char*, 0x4C) = 0x10;
                }
                Level30_7AB74CopyVectorView1(
                    ownerRecord19 + 0xC,
                    Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x24), void**,
                                       0xC));
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x52) = 0xFE;
                argumentWord6 = Level30_7AB74Field(
                    Level30_7AB74Field(privateRecord20, void**, 0x24), void**, 0xC);
                Level30_7AB74SubtractVectorView1(&originalFrame.sp40, argumentWord6 + 0x10,
                                                 argumentWord6);
                Level30_7AB74Field(privateRecord20, int*, 4) = 0;
                Level30_7AB74Field(privateRecord20, int*, 8) = 0;
                Level30_7AB74Field(privateRecord20, int*, 0xC) =
                    Level30_7AB74PlanarHeadingLookupView1(originalFrame.sp40, originalFrame.sp44,
                                                          1);
                Level30_7AB74Field(ownerRecord19, signed char*, 0x44) =
                    (signed char)((int)Level30_7AB74Field(privateRecord20, int*, 4) >> 2);
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x45) =
                    (unsigned char)((int)Level30_7AB74Field(privateRecord20, int*, 8) >> 2);
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46) =
                    (unsigned char)((int)Level30_7AB74Field(privateRecord20, int*, 0xC) >> 2);
                rawWord2 = Level30_7AB74Field(privateRecord20, int*, 4);
                __asm__("" ::: "$4", "memory");
                argumentWord4 = (int)ownerRecord19;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                rawWord2 &= 15;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x54) = rawWord2;
                rawWord2 = Level30_7AB74Field(privateRecord20, int*, 8);
                __asm__("" ::: "$5", "memory");
                argumentWord5 = 6;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
                rawWord2 &= 15;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x55) = rawWord2;
                rawWord2 = Level30_7AB74Field(privateRecord20, int*, 12);
                __asm__("" ::: "$3", "memory");
                rawWord3 = 64;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x57) = rawWord3;
                __asm__(""
                        : "=r"(rawWord2)
                        : "0"(rawWord2),
                          "m"(Level30_7AB74Field(ownerRecord19, unsigned char*, 0x57)));
                rawWord2 &= 15;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x56) = rawWord2;
                Level30_7AB74RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
                Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x24), short*, 2) =
                    1;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 4U;
                Level30_7AB74Call3B7B4View1(ownerRecord19 + 0x49, 1,
                                            (int)&Level30_7AB74Data6C7F8View1);
            }
            break;
        case 4:
            if (Level30_7AB74Call36220View1((int)&Level30_7AB74Data70328View1,
                                            privateRecord20 + 0x2C, 0, 0) != 0) {
                retainedAddressOrCounter16 = (int)&originalFrame.sp50;
                rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                MATCHING_KEEP(rawWord2);
                rawWord2 *= 2;
                rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View6, short*, rawWord2);
                __asm__("" ::: "$4", "memory");
                argumentWord4 = retainedAddressOrCounter16;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                rawWord2 >>= 1;
                originalFrame.sp50 = rawWord2;
                rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                __asm__("" ::: "$5", "memory");
                argumentWord5 = retainedAddressOrCounter16;
                rawWord2 *= 2;
                rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View6, short*, rawWord2);
                __asm__("" ::: "$6", "memory");
                argumentWord6 = (int)ownerRecord19 + 12;
                originalFrame.sp58 = 0;
                __asm__(""
                        : "=r"(rawWord2)
                        : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp58));
                rawWord2 >>= 1;
                originalFrame.sp54 = rawWord2;
                Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                originalFrame.sp58 += 0x400;
                Level30_7AB74Call13D44View1(
                    &originalFrame.sp50,
                    (int)Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46),
                    Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x44), int*,
                                       0xC),
                    0x28);
                Level30_7AB74Field(privateRecord20, int*, 0x48) = 0;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 5U;
            }
            break;
        case 5:
            if (Level30_7AB74Field(privateRecord20, int*, 0x48) != 0) {
                Level30_7AB74Call13AE4View1(
                    Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x44), int*,
                                       0xC),
                    (int)&Level30_7AB74Data70328View1);
                rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                __asm__("" ::: "$16", "memory");
                retainedAddressOrCounter16 = (int)&originalFrame.sp60;
                rawWord2 *= 2;
                rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View7, short*, rawWord2);
                __asm__("" ::: "$4", "memory");
                argumentWord4 = retainedAddressOrCounter16;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                rawWord2 >>= 1;
                originalFrame.sp60 = rawWord2;
                rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                __asm__("" ::: "$5", "memory");
                argumentWord5 = retainedAddressOrCounter16;
                rawWord2 *= 2;
                rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View7, short*, rawWord2);
                __asm__("" ::: "$6", "memory");
                argumentWord6 = (int)ownerRecord19 + 12;
                originalFrame.sp68 = 0;
                __asm__(""
                        : "=r"(rawWord2)
                        : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp68));
                rawWord2 >>= 1;
                originalFrame.sp64 = rawWord2;
                Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x20C) = 0x1001A000;
                originalFrame.sp68 += 0x400;
                Level30_7AB74CopyVectorView1((int)&Level30_7AB74Data70328View1 + 0x22C,
                                             &originalFrame.sp60);
                Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x23C) = 0x28;
                Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x228) = 0;
                Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x229) = 0;
                Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
                if (Level30_7AB74Data6C65CView1 != 0) {
                    Level30_7AB74Field(Level30_7AB74Data6C65CView1, signed char*, 0x4C) = 0;
                    Level30_7AB74Field(Level30_7AB74Data6C65CView1, signed char*, 0x4D) = 0;
                }
                if (Level30_7AB74CountTimerDownView1(privateRecord20 + 0x48, 4) != 0) {
                    Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 6U;
                    Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                    Level30_7AB74RequestMobyAnimationView1(ownerRecord19, 2);
                }
            } else if (Level30_7AB74Data6E048View1 == 1) {
                Level30_7AB74Call13AE4View1(
                    Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x44), int*,
                                       0xC),
                    (int)&Level30_7AB74Data70328View1);
                Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x20C) = 0x10012000;
                Level30_7AB74Field(privateRecord20, int*, 0x48) = 0x3C;
            }
            break;
        case 6:
            Level30_7AB74Call13AE4View1(
                Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x44), int*, 0xC),
                (int)&Level30_7AB74Data70328View1);
            rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            __asm__("" ::: "$16", "memory");
            retainedAddressOrCounter16 = (int)&originalFrame.sp70;
            rawWord2 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View8, short*, rawWord2);
            __asm__("" ::: "$4", "memory");
            argumentWord4 = retainedAddressOrCounter16;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
            rawWord2 >>= 1;
            originalFrame.sp70 = rawWord2;
            rawWord2 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            __asm__("" ::: "$5", "memory");
            argumentWord5 = retainedAddressOrCounter16;
            rawWord2 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View8, short*, rawWord2);
            __asm__("" ::: "$6", "memory");
            argumentWord6 = (int)ownerRecord19 + 12;
            originalFrame.sp78 = 0;
            __asm__(""
                    : "=r"(rawWord2)
                    : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp78));
            rawWord2 >>= 1;
            originalFrame.sp74 = rawWord2;
            Level30_7AB74AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x20C) = 0x1001A000;
            originalFrame.sp78 += 0x400;
            Level30_7AB74CopyVectorView1((int)&Level30_7AB74Data70328View1 + 0x22C,
                                         &originalFrame.sp70);
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x23C) = 0x28;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x228) = 0;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, signed char*, 0x229) = 0;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 0x22A) =
                (unsigned char)Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            if (Level30_7AB74Field(ownerRecord19, unsigned char*, 0x3C) == 2) {
                rawWord2 = Level30_7AB74Call55E84View1(ownerRecord19);
                rawWord2 = rawWord2 < 32;
                MATCHING_KEEP_CLOBBER(rawWord2, "$16");
                retainedAddressOrCounter16 = 0;
                if (!rawWord2) {
                    retainedAddressOrConstant17 = 1024;
                    MATCHING_KEEP(retainedAddressOrConstant17);
                    do {
                        originalFrame.sp80 = retainedAddressOrConstant17;
                        originalFrame.sp84 = (Level30_7AB74DatarandView1() & 0x1FE) - 0xFF;
                        rawWord2 = Level30_7AB74DatarandView1();
                        MATCHING_KEEP(retainedAddressOrCounter16);
                        argumentWord4 = 1;
                        argumentWord5 = 44;
                        argumentWord6 = (int)&originalFrame.sp80;
                        argumentWord7 = 0;
                        __asm__(""
                                : "=r"(argumentWord7)
                                : "0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5),
                                  "r"(argumentWord6));
                        retainedAddressOrCounter16 += 1;
                        rawWord2 &= 510;
                        rawWord3 = (int)Level30_7AB74DataSpawnParticleView1;
                        rawWord2 -= 255;
                        originalFrame.sp88 = rawWord2;
                        ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6,
                                              argumentWord7);
                    } while (retainedAddressOrCounter16 < 0xC);
                    if (Level30_7AB74Data6C65CView1 != 0) {
                        Level30_7AB74Field(Level30_7AB74Data6C65CView1, signed char*, 0x4C) = 0x10;
                    }
                    Level30_7AB74Field(privateRecord20, int*, 0x48) = 0x5A;
                    Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 7U;
                }
            }
            break;
        case 7:
            Level30_7AB74Call13AE4View1(
                Level30_7AB74Field(Level30_7AB74Field(privateRecord20, void**, 0x44), int*, 0xC),
                (int)&Level30_7AB74Data70328View1);
            rawWord2 = 0x10000088;
            rawWord3 = Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 14);
            __asm__("" ::: "$4", "memory");
            argumentWord4 = privateRecord20 + 72;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x20C) = rawWord2;
            rawWord3 *= 2;
            rawWord2 = Level30_7AB74Field((int)&Level30_7AB74Data65920View9, short*, rawWord3);
            MATCHING_KEEP(rawWord2);
            rawWord2 >>= 5;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x21C) = rawWord2;
            rawWord3 = Level30_7AB74Field((int)&Level30_7AB74Data658A0View9, short*, rawWord3);
            __asm__("" ::: "$2", "memory");
            rawWord2 = 40;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x224) = 0;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, unsigned char*, 0x22A) = 0;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x23C) = rawWord2;
            MATCHING_KEEP_CLOBBER(rawWord3, "memory");
            rawWord3 >>= 5;
            Level30_7AB74Field((int)&Level30_7AB74Data70328View1, int*, 0x220) = rawWord3;
            __asm__("" ::: "$5", "memory");
            if (Level30_7AB74CountTimerDownView1(argumentWord4, 4) != 0) {
                Level30_7AB74Call13B7CView1(0);
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49) = 0U;
            }
            originalFrame.sp80 = -0x190;
            originalFrame.sp84 = 0x40 - (Level30_7AB74DatarandView1() & 0x7F);
            originalFrame.sp88 = -0x12C;
            Level30_7AB74DataSpawnParticleView1(1, 0x2C, &originalFrame.sp80, 0);
            break;
    }
    rawWord3 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48);
    switch (rawWord3) {
        case 0:
            rawWord3 = Level30_7AB74Field(ownerRecord19, unsigned char*, 0x49);
            MATCHING_KEEP(rawWord3);
            if (((unsigned int)(rawWord3 - 2) >= 2U) && ((unsigned int)(rawWord3 - 5) >= 2U) &&
                ((rawWord3 & 0xFF) != 7) && (({
                    rawWord2 = retainedHeadingDifference < 0x18;
                    MATCHING_KEEP(rawWord2);
                    rawWord2;
                })) &&
                (({
                    rawWord2 = retainedDistance22 < 0x2000;
                    MATCHING_KEEP(rawWord2);
                    rawWord2;
                })) &&
                (({
                    rawWord2 = retainedAbsoluteHeight23 < 0x800;
                    MATCHING_KEEP(rawWord2);
                    rawWord2;
                })) &&
                !(Level30_7AB74Data6C7B4View1 & 8) &&
                !(Level30_7AB74Field((int)&Level30_7AB74Data70300View1, unsigned char*,
                                     Level30_7AB74Data6C58CView1) &
                  8)) {
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48) = 1U;
                Level30_7AB74RequestMobyAnimationView1(ownerRecord19, 1);
                Level30_7AB74Field(ownerRecord19, signed char*, 0x41) = 1;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x40) = 0xF2;
                return;
            }
            return;
        case 1:
            if (!(({
                      rawWord2 = retainedHeadingDifference < 33;
                      MATCHING_KEEP(rawWord2);
                      rawWord2;
                  }) &&
                  ({
                      rawWord2 = retainedDistance22 < 9217;
                      MATCHING_KEEP(rawWord2);
                      rawWord2;
                  }) &&
                  ({
                      rawWord2 = retainedAbsoluteHeight23 < 3073;
                      MATCHING_KEEP(rawWord2);
                      rawWord2;
                  }))) {
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                Level30_7AB74RequestMobyAnimationView1(ownerRecord19, 0);
                Level30_7AB74Field(ownerRecord19, signed char*, 0x41) = 1;
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x40) = 0xF2;
                return;
            }
            Level30_7AB74Field(&originalFrame.sp80, unsigned char*, 0) =
                Level30_7AB74DatarandView1();
            Level30_7AB74Field(&originalFrame.sp80, unsigned char*, 1) =
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x45);
            Level30_7AB74Field(&originalFrame.sp80, unsigned char*, 2) =
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x46);
            Level30_7AB74BuildPackedAngleBasisMatrixView1(&originalFrame.sp80, &originalFrame.sp90,
                                                          0);
            originalFrame.sp40 = 0x1000;
            originalFrame.sp44 = 0x800;
            originalFrame.sp48 = 0;
            Level30_7AB74TransformVectorByBasisView1(&originalFrame.sp90, &originalFrame.sp40,
                                                     &originalFrame.sp40);
            Level30_7AB74AddVectorView1(&originalFrame.sp40, &originalFrame.sp40,
                                        ownerRecord19 + 0xC);
            Level30_7AB74DataSpawnParticleView1(1, 0x1E, &originalFrame.sp40, ownerRecord19);
            return;
        case 2:
            if (Level30_7AB74Data6C770View1 != 0) {
                Level30_7AB74Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                Level30_7AB74RequestMobyAnimationView1(ownerRecord19, 0);
            }
            break;
    }
}
#undef Level30_7AB74Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007B848.
 * AI generated; not human reviewed. 852 native words,9 actual selectors
 * and one zero pad must match:862 owned words. Frame80 (128 bytes) saves
 * S0..S7/FP/RA at SP58..7C. Four original vector homes occupy SP18..20,
 * SP28..30,SP38..40 and SP48..50;unwritten reserves are never read.
 * S0 allocates naturally. The ordinary history-position address starts after
 * the byte offset's last use;these distinct ordinary objects have disjoint
 * lifetimes. Natural FP retains D658A0. S4 retains owner until its final byte
 * read,then holds the geometry offset. No fixed FP/SP or live fixed aliases.
 * Every MULT uses both complete signed32 operands in a signed64 product.
 * Complete high/low captures narrow before original signed shifts. Original
 * /6 uses2AAAAAAB high and sign correction; /30 uses88888889 high plus its
 * initialized numerator,SRA4 and sign correction. Both trig products retain
 * original LH widths,SRA4 before MULT,and low32 signed SRA12 afterward.
 * Raw vectors:11%6=5;30<<8=7680,/30=256;(-32768>>4)*32767=-67106816,
 * low32 signed SRA12=-16384. Physical units/fixed-point domains remain open.
 * States0..8 retain original32-record history,6/12-record spawn loops,field
 * widths,literals,callbacks and invocation order. Completion byte is80071593.
 * Level20/30 use helper A3=0 and retain blocked-state modal writes.
 * Original scalar pointer expressions add bytes before their final cast.
 * Frame vector metadata observes complete words written by preceding4F194;
 * no padding is consumed. No incoming A2 is read:original4F178 uses A0/A1,
 * and the first actual A2 producer follows the initialized counter division.
 * Empty metadata observes complete initialized values/addresses or clobbers
 * dead registers before fresh producers;zero CPU words. No partial HILO input.
 * Every actual transfer/data/selector target and full EXE/every-overlay retail
 * hash is mandatory. Production compiler,filter and flags remain unchanged.
 * Confidence is binary identity after every gate. Complete helper/caller
 * chains,units,cadence beyond invocation,Rev1 mapping and retail runtime stay
 * open. Next evidence:human review and synchronized retail capture checks.
 */
/* Original assembly SHA256 38a83fd9b5b1c651cd646ca388a36f850f0ab57f2785e02e8e6dc38e17454e8c */
#define Level30_7B848Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level30_7B848MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level30_7B848CaptureHigh(dst)                                       \
    do {                                                                    \
        int wholeCapturedHigh;                                              \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedHigh;                                          \
        Level30_7B848Keep(dst);                                             \
    } while (0)
#define Level30_7B848CaptureLow(dst)                                       \
    do {                                                                   \
        int wholeCapturedLow;                                              \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedLow;                                          \
        Level30_7B848Keep(dst);                                            \
    } while (0)
#define Level30_7B848Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level30_7B848Call136F0View1(void*, int, int) __asm__("func_800136F0");
int Level30_7B848CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level30_7B848Call36220View1(void*, void*, int, int) __asm__("func_80036220");
void Level30_7B848Call37014View1(void*) __asm__("func_80037014");
int Level30_7B848Call37BBCView1(void*, int) __asm__("func_80037BBC");
int Level30_7B848PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
void Level30_7B848Call492DCView1(void*) __asm__("func_800492DC");
int Level30_7B848PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level30_7B848TransformVectorByBasisView1(void*, int, int) __asm__("func_8004ED6C");
void Level30_7B848ClearVectorView1(void*) __asm__("func_8004F168");
void Level30_7B848CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level30_7B848AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level30_7B848SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level30_7B848AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
void* Level30_7B848Call50B00View1(int, int, int, int, int) __asm__("func_80050B00");
void Level30_7B848Call50B88View1(void*) __asm__("func_80050B88");
void Level30_7B848Call512E4View1(void*, int, int) __asm__("func_800512E4");
void Level30_7B848DeleteMobyView1(void*) __asm__("func_80055B18");
void Level30_7B848RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
extern unsigned char Level30_7B848Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level30_7B848Data65920View1[] __asm__("D_80065920");
extern int Level30_7B848Data6C574View1 __asm__("D_8006C574");
extern int Level30_7B848Data6C578View1 __asm__("D_8006C578");
extern int Level30_7B848Data6C74CView1 __asm__("D_8006C74C");
extern int Level30_7B848Data6C7C0View1 __asm__("D_8006C7C0");
extern int Level30_7B848Data6E020View1 __asm__("D_8006E020");
extern int Level30_7B848Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level30_7B848Data6E040View1 __asm__("D_8006E040");
extern int Level30_7B848Data6E160View1 __asm__("D_8006E160");
extern int Level30_7B848Data6E174View1 __asm__("D_8006E174");
extern int Level30_7B848Data6E178View1 __asm__("D_8006E178");
extern int Level30_7B848Data6E17CView1 __asm__("D_8006E17C");
extern int Level30_7B848Data6E344View1 __asm__("D_8006E344");
extern int Level30_7B848Data70328View1 __asm__("D_80070328");
extern unsigned char Level30_7B848Data71593View1 __asm__("D_80071593");
extern int (*Level30_7B848DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Level30_7B848Data74330View1)() __asm__("unk_ovlheader_80074330");
extern int (*Level30_7B848Data743ECView1)() __asm__("unk_ovlheader_800743EC");
void func_level_30_8007B848(unsigned char* ownerParameter) {
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
    Level30_7B848Keep(ownerThenGeometryOffset20);
    temp_v1 = Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    privateRecord19 = Level30_7B848Field(ownerThenGeometryOffset20, int*, 0);
    switch (temp_v1) {
        case 0:
            resultOrField2 = Level30_7B848Data71593View1;
            naturalCountRecordOrOffset16 = 0;
            if (resultOrField2) {
                Level30_7B848DeleteMobyView1(ownerThenGeometryOffset20);
                return;
            }
            resultOrField2 = 255;
            Level30_7B848Keep(resultOrField2);
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x41) = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x4C) = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x4D) = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x4A) = resultOrField2;
            do {
                Level30_7B848Keep(naturalCountRecordOrOffset16);
                angleCreatedOrSourceOffset17 = naturalCountRecordOrOffset16 * 2;
                Level30_7B848Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 + naturalCountRecordOrOffset16;
                argumentOrField4 *= 4;
                argumentOrField4 += 0x74;
                argumentOrField4 = privateRecord19 + argumentOrField4;
                argumentOrField5 = ownerThenGeometryOffset20 + 12;
                Level30_7B848CopyVectorView1(argumentOrField4, argumentOrField5);
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
                Level30_7B848Keep(argumentOrField5);
                resultOrField2 = naturalCountRecordOrOffset16 + 1;
                __asm__(""
                        : "=r"(resultOrField2)
                        : "0"(resultOrField2), "r"(argumentOrField4), "r"(fieldHighOrAddress3),
                          "r"(argumentOrField5));
                naturalCountRecordOrOffset16 = resultOrField2;
                Level30_7B848Keep(naturalCountRecordOrOffset16);
                argumentOrField4 = privateRecord19 + argumentOrField4;
                fieldHighOrAddress3 = privateRecord19 + fieldHighOrAddress3;
                resultOrField2 = angleCreatedOrSourceOffset17 + 2;
                Level30_7B848Field(argumentOrField4, unsigned char*, 0x4F4) = argumentOrField6;
                Level30_7B848Field(argumentOrField4, unsigned char*, 0x4F5) = argumentOrField6;
                Level30_7B848Field(argumentOrField4, unsigned char*, 0x4F6) = argumentOrField6;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x575) = resultOrField2;
                resultOrField2 = angleCreatedOrSourceOffset17 + 1;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x576) = resultOrField2;
                resultOrField2 = angleCreatedOrSourceOffset17 + 3;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x577) = resultOrField2;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x574) =
                    angleCreatedOrSourceOffset17;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x578) = argumentOrField5;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x579) =
                    naturalCountRecordOrOffset16;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x57A) = argumentOrField5;
                Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 0x57B) =
                    naturalCountRecordOrOffset16;
            } while (naturalCountRecordOrOffset16 < 32);
            resultOrField2 = naturalCountRecordOrOffset16 * 8;
            resultOrField2 += privateRecord19;
            fieldHighOrAddress3 = -1;
            Level30_7B848Field(resultOrField2, int*, 0x56C) = fieldHighOrAddress3;
            resultOrField2 = Level30_7B848Field(privateRecord19, unsigned short*, 0x6E);
            resultOrField2 &= 0xFF9F;
            resultOrField2 |= 0x40;
            Level30_7B848Field(privateRecord19, short*, 0x6E) = resultOrField2;
            resultOrField2 = 1;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = resultOrField2;
            goto renderOriginalCommonPhase;
        default:
            goto renderOriginalCommonPhase;
        case 1:
            Level30_7B848CopyVectorView1(&originalFrame.sp18, &Level30_7B848Data70328View1);
            originalFrame.sp20 -= Level30_7B848Field(&Level30_7B848Data70328View1, int*, 0x44);
            if (Level30_7B848Call36220View1(&originalFrame.sp18, privateRecord19 + 0x3C, 0, 0) !=
                0) {
                if (Level30_7B848Field(&Level30_7B848Data70328View1, int*, 0xB8) == 0) {
                    resultOrField2 = Level30_7B848Field(privateRecord19, int*, 36);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    argumentOrField6 = Level30_7B848Field(resultOrField2, short*, 0);
                    resultOrField2 = Level30_7B848Field(resultOrField2, int*, 12);
                    argumentOrField6 *= 16;
                    argumentOrField5 = argumentOrField6 - 16;
                    argumentOrField5 = resultOrField2 + argumentOrField5;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level30_7B848SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
                    argumentOrField4 = originalFrame.sp18;
                    argumentOrField5 = originalFrame.sp1C;
                    argumentOrField6 = 0;
                    resultOrField2 = Level30_7B848PlanarHeadingLookupView1(
                        argumentOrField4, argumentOrField5, argumentOrField6);
                    naturalCountRecordOrOffset16 = resultOrField2;
                    Level30_7B848Keep(naturalCountRecordOrOffset16);
                    argumentOrField4 = naturalCountRecordOrOffset16 * 2;
                    fieldHighOrAddress3 =
                        Level30_7B848Field(&Level30_7B848Data65920View1, short*, argumentOrField4);
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp18 = resultOrField2;
                    fieldHighOrAddress3 =
                        Level30_7B848Field(&Level30_7B848Data658A0View1, short*, argumentOrField4);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    originalFrame.sp20 = 0;
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp1C = resultOrField2;
                    resultOrField2 = Level30_7B848Field(privateRecord19, int*, 36);
                    argumentOrField5 = argumentOrField4;
                    argumentOrField6 = Level30_7B848Field(resultOrField2, short*, 0);
                    resultOrField2 = Level30_7B848Field(resultOrField2, int*, 12);
                    argumentOrField6 *= 16;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level30_7B848AddVectorView1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    __asm__(""
                            : "=r"(argumentOrField4)
                            : "0"(argumentOrField4), "m"(originalFrame.sp18));
                    argumentOrField5 = naturalCountRecordOrOffset16 + 128;
                    argumentOrField6 = 0;
                    Level30_7B848Data74330View1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    Level30_7B848Field(privateRecord19, signed char*, 5) = 1;
                    Level30_7B848Field(Level30_7B848Field(privateRecord19, int*, 0x24), short*, 2) =
                        1;
                    Level30_7B848CopyVectorView1(
                        &Level30_7B848Data6E17CView1,
                        Level30_7B848Field(Level30_7B848Field(privateRecord19, int*, 0x28), int*,
                                           0xC) +
                            0x10);
                    temp_a1_3 = Level30_7B848Field(Level30_7B848Field(privateRecord19, int*, 0x28),
                                                   int*, 0xC);
                    Level30_7B848Call136F0View1((int)&Level30_7B848Data6E17CView1 - 0x14, temp_a1_3,
                                                temp_a1_3 + 0x10);
                    Level30_7B848Data6E160View1 = 0x11;
                    Level30_7B848Data6C74CView1 = 1;
                    Level30_7B848Data6E174View1 = 0;
                    Level30_7B848Data6E178View1 = 0;
                    Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 2U;
                } else {
                    Level30_7B848Field(&Level30_7B848Data70328View1, int*, 0x20C) = 0x10000082;
                    Level30_7B848Field(&Level30_7B848Data70328View1, int*, 0x23C) = 0x12;
                }
            }
            goto renderOriginalCommonPhase;
        case 2:
            if (Level30_7B848Call36220View1(&Level30_7B848Data70328View1, privateRecord19 + 0x3C, 0,
                                            0) != 0) {
                naturalCountRecordOrOffset16 = (int)&originalFrame.sp28;
                argumentOrField4 = naturalCountRecordOrOffset16;
                fieldHighOrAddress3 = Level30_7B848Field(privateRecord19, int*, 36);
                Level30_7B848Data6C74CView1 = 1;
                argumentOrField6 = Level30_7B848Field(fieldHighOrAddress3, short*, 0);
                resultOrField2 = Level30_7B848Field(fieldHighOrAddress3, int*, 12);
                argumentOrField6 *= 16;
                argumentOrField5 = argumentOrField6 - 16;
                argumentOrField5 = resultOrField2 + argumentOrField5;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level30_7B848SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                 argumentOrField6);
                argumentOrField4 = originalFrame.sp28;
                argumentOrField5 = originalFrame.sp2C;
                argumentOrField6 = 0;
                resultOrField2 = Level30_7B848PlanarHeadingLookupView1(
                    argumentOrField4, argumentOrField5, argumentOrField6);
                angleCreatedOrSourceOffset17 = resultOrField2;
                Level30_7B848Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
                fieldHighOrAddress3 =
                    Level30_7B848Field(&Level30_7B848Data65920View1, short*, argumentOrField4);
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp28 = resultOrField2;
                fieldHighOrAddress3 =
                    Level30_7B848Field(&Level30_7B848Data658A0View1, short*, argumentOrField4);
                argumentOrField5 = naturalCountRecordOrOffset16;
                originalFrame.sp30 = 0;
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp2C = resultOrField2;
                resultOrField2 = Level30_7B848Field(privateRecord19, int*, 36);
                __asm__(""
                        : "=r"(naturalCountRecordOrOffset16)
                        : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
                argumentOrField4 = naturalCountRecordOrOffset16;
                argumentOrField6 = Level30_7B848Field(resultOrField2, short*, 0);
                resultOrField2 = Level30_7B848Field(resultOrField2, int*, 12);
                argumentOrField6 *= 16;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level30_7B848AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
                argumentOrField4 = naturalCountRecordOrOffset16;
                __asm__(""
                        : "=r"(argumentOrField4)
                        : "0"(argumentOrField4), "m"(originalFrame.sp28));
                argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
                argumentOrField6 = 0;
                Level30_7B848Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
                Level30_7B848Field(privateRecord19, signed char*, 5) = 1;
                Level30_7B848Call492DCView1(ownerThenGeometryOffset20 + 0xC);
                if (Level30_7B848AbsoluteByteAngleDeltaView1(
                        (int)(Level30_7B848Data6E040View1 << 0x10) >> 0x14,
                        Level30_7B848PlanarHeadingLookupView1(
                            Level30_7B848Field(ownerThenGeometryOffset20, int*, 0xC) -
                                Level30_7B848Data6E020View1,
                            Level30_7B848Field(ownerThenGeometryOffset20, int*, 0x10) -
                                Level30_7B848Data6E024View1,
                            0)) < 0x18) {
                    Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 3U;
                }
            } else {
                goto restoreOriginalStateOne;
            }
            goto renderOriginalCommonPhase;
        case 4:
            Level30_7B848PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x41) = 1;
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x4C) = 0x10;
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x4D) = 1;
            Level30_7B848Call37014View1(ownerThenGeometryOffset20);
            argumentOrField6 = 0;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$18");
            recordOrHistoryCount18 = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x44) = 0U;
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x45) = 0;
            temp_v1_6 = Level30_7B848Field(privateRecord19, int*, 0x24);
            temp_v0_11 = (Level30_7B848Field(temp_v1_6, short*, 2) * 0x10) +
                         Level30_7B848Field(temp_v1_6, int*, 0xC);
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x46) =
                Level30_7B848PlanarHeadingLookupView1(
                    Level30_7B848Field(temp_v0_11, int*, 0) -
                        Level30_7B848Field(ownerThenGeometryOffset20, int*, 0xC),
                    Level30_7B848Field(temp_v0_11, int*, 4) -
                        Level30_7B848Field(ownerThenGeometryOffset20, int*, 0x10),
                    argumentOrField6);
        emitOriginalFirstSix:
            resultOrField2 = Level30_7B848Data6C578View1;
            fieldHighOrAddress3 = Level30_7B848Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone4;
            angleCreatedOrSourceOffset17 =
                Level30_7B848DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalFirstSix;
        originalSixDone4:
            recordOrHistoryCount18 = 0;
        emitOriginalFirstTwelve:
            resultOrField2 = Level30_7B848Data6C578View1;
            fieldHighOrAddress3 = Level30_7B848Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone4;
            angleCreatedOrSourceOffset17 =
                Level30_7B848DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level30_7B848Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext4;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x58);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level30_7B848Field(resultOrField2, unsigned char*, 0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x58);
            naturalCountRecordOrOffset16 =
                Level30_7B848Field(angleCreatedOrSourceOffset17, int*, 0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 1);
            argumentOrField5 = 4;
            Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level30_7B848RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level30_7B848Field(naturalCountRecordOrOffset16, int*, 12) = resultOrField2;
            Level30_7B848Field(naturalCountRecordOrOffset16, int*, 16) = 0;
            Level30_7B848Field(naturalCountRecordOrOffset16, int*, 20) = 0;
            Level30_7B848TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level30_7B848Keep(resultOrField2);
            Level30_7B848MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level30_7B848Field(angleCreatedOrSourceOffset17, int*, 20);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level30_7B848Field(angleCreatedOrSourceOffset17, int*, 20) = resultOrField2;
            Level30_7B848CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext4:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalFirstTwelve;
        originalTwelveDone4:
            Level30_7B848Field(privateRecord19, int*, 0x2C) = 0x1E;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 5U;
        case 5:
            if (Level30_7B848CountTimerDownView1(privateRecord19 + 0x2C, 4) != 0) {
                Level30_7B848Data6E160View1 = 0;
                Level30_7B848Field(privateRecord19, signed char*, 5) = 2;
                Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 6U;
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 44);
            resultOrField2 <<= 8;
            Level30_7B848Keep(resultOrField2);
            Level30_7B848MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level30_7B848CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level30_7B848Data6C7C0View1 = fieldHighOrAddress3;
        case 3:
            if (Level30_7B848Call36220View1(&Level30_7B848Data70328View1, privateRecord19 + 0x3C, 0,
                                            0) == 0) {
                resultOrField2 = Level30_7B848Field(privateRecord19, int*, 36);
                argumentOrField4 = ownerThenGeometryOffset20 + 12;
                Level30_7B848Field(resultOrField2, short*, 2) = 0;
                resultOrField2 = Level30_7B848Field(privateRecord19, int*, 36);
                angleCreatedOrSourceOffset17 = 0;
                argumentOrField5 = Level30_7B848Field(resultOrField2, int*, 12);
                naturalCountRecordOrOffset16 = 116;
                Level30_7B848CopyVectorView1(argumentOrField4, argumentOrField5);
                Level30_7B848ClearVectorView1(privateRecord19 + 0x30);
                Level30_7B848Field(privateRecord19, int*, 0x2C) = 0;
                do {
                    Level30_7B848CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                                 ownerThenGeometryOffset20 + 0xC);
                    angleCreatedOrSourceOffset17 += 1;
                    naturalCountRecordOrOffset16 += 0xC;
                } while (angleCreatedOrSourceOffset17 < 0x20);
            restoreOriginalStateOne:
                resultOrField2 = 1;
                Level30_7B848Data6E160View1 = 0;
                Level30_7B848Data6C74CView1 = 0;
                Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) =
                    resultOrField2;
                goto renderOriginalCommonPhase;
            }
            naturalCountRecordOrOffset16 = (int)&originalFrame.sp38;
            argumentOrField4 = naturalCountRecordOrOffset16;
            fieldHighOrAddress3 = Level30_7B848Field(privateRecord19, int*, 36);
            Level30_7B848Data6C74CView1 = 1;
            argumentOrField6 = Level30_7B848Field(fieldHighOrAddress3, short*, 0);
            resultOrField2 = Level30_7B848Field(fieldHighOrAddress3, int*, 12);
            argumentOrField6 *= 16;
            argumentOrField5 = argumentOrField6 - 16;
            argumentOrField5 = resultOrField2 + argumentOrField5;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level30_7B848SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = originalFrame.sp38;
            argumentOrField5 = originalFrame.sp3C;
            argumentOrField6 = 0;
            resultOrField2 = Level30_7B848PlanarHeadingLookupView1(
                argumentOrField4, argumentOrField5, argumentOrField6);
            angleCreatedOrSourceOffset17 = resultOrField2;
            Level30_7B848Keep(angleCreatedOrSourceOffset17);
            argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
            fieldHighOrAddress3 =
                Level30_7B848Field(&Level30_7B848Data65920View1, short*, argumentOrField4);
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp38 = resultOrField2;
            fieldHighOrAddress3 =
                Level30_7B848Field(&Level30_7B848Data658A0View1, short*, argumentOrField4);
            argumentOrField5 = naturalCountRecordOrOffset16;
            originalFrame.sp40 = 0;
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp3C = resultOrField2;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 36);
            __asm__(""
                    : "=r"(naturalCountRecordOrOffset16)
                    : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
            argumentOrField4 = naturalCountRecordOrOffset16;
            argumentOrField6 = Level30_7B848Field(resultOrField2, short*, 0);
            resultOrField2 = Level30_7B848Field(resultOrField2, int*, 12);
            argumentOrField6 *= 16;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level30_7B848AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = naturalCountRecordOrOffset16;
            __asm__("" : "=r"(argumentOrField4) : "0"(argumentOrField4), "m"(originalFrame.sp38));
            argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
            argumentOrField6 = 0;
            Level30_7B848Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level30_7B848Call492DCView1(ownerThenGeometryOffset20 + 0xC);
            if (Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) == 3) {
                temp_v0_17 = Level30_7B848Field(privateRecord19, int*, 0x24);
                if (Level30_7B848Field(temp_v0_17, short*, 2) ==
                    (Level30_7B848Field(temp_v0_17, short*, 0) - 1)) {
                    Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 4U;
                } else {
                    Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x44) =
                        (unsigned char)(Level30_7B848Field(ownerThenGeometryOffset20,
                                                           unsigned char*, 0x44) +
                                        4);
                    naturalCountRecordOrOffset16 = Level30_7B848Field(
                        Level30_7B848Field(privateRecord19, int*, 0x24), short*, 2);
                    Level30_7B848Keep(naturalCountRecordOrOffset16);
                    Level30_7B848Data743ECView1(
                        ownerThenGeometryOffset20, Level30_7B848Field(privateRecord19, int*, 0x24),
                        privateRecord19 + 0x30, privateRecord19 + 0x2C, 8, 0);
                    fieldHighOrAddress3 = Level30_7B848Field(privateRecord19, int*, 36);
                    Level30_7B848Keep(fieldHighOrAddress3);
                    if (Level30_7B848Field(fieldHighOrAddress3, short*, 2) !=
                        naturalCountRecordOrOffset16) {
                        resultOrField2 = Level30_7B848Field(fieldHighOrAddress3, int*, 12);
                        fieldHighOrAddress3 = naturalCountRecordOrOffset16 * 16;
                        Level30_7B848Keep(fieldHighOrAddress3);
                        fieldHighOrAddress3 += resultOrField2;
                        resultOrField2 = Level30_7B848Field(fieldHighOrAddress3, int*, 12);
                        if (resultOrField2) {
                            Level30_7B848PlayMobySoundEventView1(ownerThenGeometryOffset20, 1, 0);
                        }
                    }
                }
            }
            goto renderOriginalCommonPhase;
        case 6:
            temp_v1_10 = Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x48);
            switch (temp_v1_10) {
                case 0:
                    if (Level30_7B848Call37BBCView1(ownerThenGeometryOffset20, 0) != 0) {
                        Level30_7B848Data71593View1 = 1;
                        Level30_7B848Call512E4View1(ownerThenGeometryOffset20, 0, 1);
                        Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x48) = 1U;
                    }
                    break;
                case 1:
                    if (Level30_7B848Data6E344View1 != temp_v1_10) {
                        Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 7U;
                    }
                    break;
            }
            goto renderOriginalCommonPhase;
        case 7:
            Level30_7B848PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            recordOrHistoryCount18 = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x41) = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x4C) = 0;
            Level30_7B848Field(ownerThenGeometryOffset20, signed char*, 0x4D) = 0;
        emitOriginalSecondSix:
            resultOrField2 = Level30_7B848Data6C578View1;
            fieldHighOrAddress3 = Level30_7B848Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone7;
            angleCreatedOrSourceOffset17 =
                Level30_7B848DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalSecondSix;
        originalSixDone7:
            recordOrHistoryCount18 = 0;
        emitOriginalSecondTwelve:
            resultOrField2 = Level30_7B848Data6C578View1;
            fieldHighOrAddress3 = Level30_7B848Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone7;
            angleCreatedOrSourceOffset17 =
                Level30_7B848DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level30_7B848Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext7;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x58);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level30_7B848Field(resultOrField2, unsigned char*, 0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x58);
            naturalCountRecordOrOffset16 =
                Level30_7B848Field(angleCreatedOrSourceOffset17, int*, 0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level30_7B848Field(fieldHighOrAddress3, unsigned char*, 1);
            argumentOrField5 = 4;
            Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level30_7B848RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level30_7B848Field(naturalCountRecordOrOffset16, int*, 12) = resultOrField2;
            Level30_7B848Field(naturalCountRecordOrOffset16, int*, 16) = 0;
            Level30_7B848Field(naturalCountRecordOrOffset16, int*, 20) = 0;
            Level30_7B848TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level30_7B848Keep(resultOrField2);
            Level30_7B848MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level30_7B848Field(angleCreatedOrSourceOffset17, int*, 20);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level30_7B848Field(angleCreatedOrSourceOffset17, int*, 20) = resultOrField2;
            Level30_7B848CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level30_7B848Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext7:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalSecondTwelve;
        originalTwelveDone7:
            temp_a0_6 = Level30_7B848Field(privateRecord19, int*, 0x64);
            if (temp_a0_6 != 0) {
                Level30_7B848Call50B88View1(temp_a0_6);
            }
            temp_a0_7 = Level30_7B848Field(privateRecord19, int*, 0x70);
            if (temp_a0_7 != 0) {
                Level30_7B848Call50B88View1(temp_a0_7);
            }
            Level30_7B848Field(privateRecord19, int*, 0x2C) = 0x1E;
            Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 8U;
        case 8:
            if (Level30_7B848CountTimerDownView1(privateRecord19 + 0x2C, 4) != 0) {
                Level30_7B848DeleteMobyView1(ownerThenGeometryOffset20);
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level30_7B848Field(privateRecord19, int*, 44);
            resultOrField2 <<= 8;
            Level30_7B848Keep(resultOrField2);
            Level30_7B848MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level30_7B848CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level30_7B848Data6C7C0View1 = fieldHighOrAddress3;
            goto renderOriginalCommonPhase;
    }
renderOriginalCommonPhase:
    resultOrField2 = Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 -= 3;
    recordOrHistoryCount18 = 31;
    if ((unsigned int)resultOrField2 >= 4U)
        return;
    angleCreatedOrSourceOffset17 = 0x1DC;
    naturalCountRecordOrOffset16 = 0x1E8;
    do {
        Level30_7B848CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                     privateRecord19 + angleCreatedOrSourceOffset17);
        angleCreatedOrSourceOffset17 -= 12;
        recordOrHistoryCount18--;
        naturalCountRecordOrOffset16 -= 12;
    } while (recordOrHistoryCount18 > 0);
    Level30_7B848CopyVectorView1(privateRecord19 + 0x74, ownerThenGeometryOffset20 + 12);
    fieldHighOrAddress3 = Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 = 3;
    if (fieldHighOrAddress3 != resultOrField2) {
        resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x7C);
        resultOrField2 -= 1024;
        Level30_7B848Field(privateRecord19, int*, 0x7C) = resultOrField2;
    }
    resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x70);
    argumentOrField4 = privateRecord19 + 0x1F4;
    if (!resultOrField2) {
        resultOrField2 =
            Level30_7B848Call50B00View1(argumentOrField4, privateRecord19 + 0x4F4,
                                        privateRecord19 + 0x574, privateRecord19 + 0x68, 1);
        Level30_7B848Field(privateRecord19, int*, 0x70) = resultOrField2;
        __asm__("" : "=r"(privateRecord19) : "0"(privateRecord19), "r"(resultOrField2));
    }
    resultOrField2 = Level30_7B848Field(privateRecord19, int*, 0x64);
    emittedVertexCount21 = 0;
    if (!resultOrField2) {
        Level30_7B848Keep(emittedVertexCount21);
        resultOrField2 =
            Level30_7B848Call50B00View1(privateRecord19 + 0x1F4, privateRecord19 + 0x4F4,
                                        privateRecord19 + 0x574, privateRecord19 + 0x5C, 1);
        Level30_7B848Field(privateRecord19, int*, 0x64) = resultOrField2;
        __asm__ volatile(""
                         : "=r"(emittedVertexCount21)
                         : "0"(emittedVertexCount21), "r"(resultOrField2));
        emittedVertexCount21 = 0;
    }
    recordOrHistoryCount18 = 0;
    retainedOriginalTableBase = (int)&Level30_7B848Data658A0View1;
    vectorAddress23 = (int)&originalFrame.sp48;
    resultOrField2 = Level30_7B848Field(ownerThenGeometryOffset20, unsigned char*, 0x44);
    ownerThenGeometryOffset20 = 0x1F4;
    resultOrField2 += 64;
    retainedAngle22 = resultOrField2 & 255;
    do {
        argumentOrField6 = 0;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$16");
        naturalCountRecordOrOffset16 = recordOrHistoryCount18 * 2;
        Level30_7B848Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 += recordOrHistoryCount18;
        Level30_7B848Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 *= 4;
        fieldHighOrAddress3 = privateRecord19 + naturalCountRecordOrOffset16;
        angleCreatedOrSourceOffset17 = recordOrHistoryCount18 + 1;
        resultOrField2 = angleCreatedOrSourceOffset17 * 12;
        resultOrField2 = privateRecord19 + resultOrField2;
        argumentOrField7 = Level30_7B848Field(fieldHighOrAddress3, int*, 0x74);
        argumentOrField4 = Level30_7B848Field(resultOrField2, int*, 0x74);
        fieldHighOrAddress3 = Level30_7B848Field(fieldHighOrAddress3, int*, 0x78);
        argumentOrField5 = Level30_7B848Field(resultOrField2, int*, 0x78);
        argumentOrField4 = argumentOrField7 - argumentOrField4;
        argumentOrField5 = fieldHighOrAddress3 - argumentOrField5;
        resultOrField2 = Level30_7B848PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        resultOrField2 += 64;
        resultOrField2 &= 255;
        resultOrField2 *= 2;
        capturedHighOrLow8 = (int)&Level30_7B848Data65920View1;
        Level30_7B848Keep(capturedHighOrLow8);
        fieldHighOrAddress3 = resultOrField2 + capturedHighOrLow8;
        MATCHING_KEEP_VOLATILE_CLOBBER(fieldHighOrAddress3, "$7");
        argumentOrField7 = retainedAngle22 * 2;
        argumentOrField5 = argumentOrField7 + capturedHighOrLow8;
        fieldHighOrAddress3 = Level30_7B848Field(fieldHighOrAddress3, short*, 0);
        argumentOrField4 = Level30_7B848Field(argumentOrField5, short*, 0);
        MATCHING_KEEP2(fieldHighOrAddress3, argumentOrField4);
        fieldHighOrAddress3 >>= 4;
        Level30_7B848MultiplyComplete(fieldHighOrAddress3, argumentOrField4);
        resultOrField2 += retainedOriginalTableBase;
        Level30_7B848CaptureLow(capturedHighOrLow8);
        fieldHighOrAddress3 = capturedHighOrLow8 >> 12;
        originalFrame.sp48 = fieldHighOrAddress3;
        resultOrField2 = Level30_7B848Field(resultOrField2, short*, 0);
        fieldHighOrAddress3 = Level30_7B848Field(argumentOrField5, short*, 0);
        MATCHING_KEEP2(resultOrField2, fieldHighOrAddress3);
        resultOrField2 >>= 4;
        Level30_7B848MultiplyComplete(resultOrField2, fieldHighOrAddress3);
        __asm__(""
                : "=r"(emittedVertexCount21)
                : "0"(emittedVertexCount21), "x"(completeSignedProduct));
        emittedVertexCount21++;
        Level30_7B848Keep(emittedVertexCount21);
        emittedVertexCount21++;
        recordOrHistoryCount18 = angleCreatedOrSourceOffset17;
        naturalCountRecordOrOffset16 += 0x74;
        currentHistoryPositionAddress = privateRecord19 + naturalCountRecordOrOffset16;
        Level30_7B848Keep(currentHistoryPositionAddress);
        argumentOrField6 = vectorAddress23;
        argumentOrField7 += retainedOriginalTableBase;
        MATCHING_KEEP_VOLATILE_CLOBBER(argumentOrField7, "$4");
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        ownerThenGeometryOffset20 += 12;
        Level30_7B848CaptureLow(capturedHighOrLow8);
        resultOrField2 = capturedHighOrLow8 >> 12;
        originalFrame.sp4C = resultOrField2;
        resultOrField2 = Level30_7B848Field(argumentOrField7, short*, 0);
        __asm__(""
                : "=r"(currentHistoryPositionAddress)
                : "0"(currentHistoryPositionAddress), "r"(resultOrField2));
        argumentOrField5 = currentHistoryPositionAddress;
        Level30_7B848Keep(resultOrField2);
        resultOrField2 >>= 4;
        originalFrame.sp50 = resultOrField2;
        Level30_7B848AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        argumentOrField5 = currentHistoryPositionAddress;
        argumentOrField6 = vectorAddress23;
        Level30_7B848SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        resultOrField2 = retainedAngle22 - 4;
        retainedAngle22 = resultOrField2 & 255;
        ownerThenGeometryOffset20 += 12;
    } while (recordOrHistoryCount18 < 32);
    resultOrField2 = emittedVertexCount21 * 12;
    resultOrField2 = privateRecord19 + resultOrField2;
    fieldHighOrAddress3 = -1;
    Level30_7B848Field(resultOrField2, int*, 0x1F4) = fieldHighOrAddress3;
    Level30_7B848Field(resultOrField2, int*, 0x1F8) = fieldHighOrAddress3;
    Level30_7B848Field(resultOrField2, int*, 0x1FC) = fieldHighOrAddress3;
    return;
}
#undef Level30_7B848Field


typedef struct {
    int timer;
    Colour* colours;
} DecodedColourFadeTag;
extern int D_8006C648;
void func_80055B18(Moby*);
void func_level_30_8007C598(Moby* moby) {
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
void func_level_30_8007C6D4(Moby* moby) {
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

/* SCUS-94467 USA Rev 0, 0x8007C864..0x8007CB40, 183 instructions.
 * AI generated; not yet human reviewed. Original signed halfword tables
 * shift by 3 in state zero and multiply by 3 then shift by 6 in state one.
 * State-one random terms retain (rand() & 14) - 7 on each component.
 * Original scratch offsets, matrix transforms, strict bounds and two player
 * word stores remain unchanged. Once per invocation; caller cadence, units,
 * helper meanings and table/SFX/particle producers remain unresolved.
 * Empty compiler constraints preserve original argument and pointer
 * lifetimes without instructions. Rev1 correspondence is discovery only.
 * Evidence: level_30/moby/func_level_30_8007C864.s.
 * Falsifiable vector: every original linked word and all retail hashes.
 */
extern short D_80065920[], D_800658A0[];
extern unsigned char DecodedEveningPlayer[] __asm__("D_80070328");
extern Vector3D DecodedEveningCollision[] __asm__("D_80071900");
extern int D_8007191C, D_80071920;
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_80018368(Vector3D*, Vector3D*);
int func_8004EDE8(Vector3D*, int);
void func_80055F14(Moby*, int, Vector3D*);
void func_8004ECF4(SHORTMATRIX*, SHORTMATRIX*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
void func_level_30_8007C864(Moby* argument) {
    Vector3D endpoint;
    int reserved1C;
    Vector3D direction;
    int reserved2C;
    Vector3D particlePosition;
    int reserved3C;
    Vector3D difference;
    int reserved4C;
    SHORTMATRIX matrix;
    register Moby* moby __asm__("$18") = argument;
    register int* tag __asm__("$16") = moby->mobyTag;
    register Vector3D* retained __asm__("$17");
    register Vector3D* scratch __asm__("$16");
    int value;
    switch (moby->state) {
        case 0: {
            register Vector3D* prepared __asm__("$4") = &endpoint;
            register Vector3D* preparedPosition __asm__("$5");
            register Vector3D* preparedDirection __asm__("$6");
            register int sample __asm__("$2");
            __asm__("" : "=r"(prepared) : "0"(prepared) : "$17", "$16", "$5", "$6");
            sample = moby->angle.yaw;
            MATCHING_KEEP_CLOBBER(sample, "$17");
            retained = &moby->position;
            MATCHING_BARRIER("$5");
            sample = D_80065920[sample];
            __asm__(""
                    : "=r"(sample), "=r"(retained)
                    : "0"(sample), "1"(retained)
                    : "$16", "$6", "$5");
            preparedPosition = retained;
            direction.x = sample >> 3;
            sample = moby->angle.yaw;
            MATCHING_KEEP_CLOBBER(sample, "$16");
            scratch = &direction;
            MATCHING_BARRIER("$6");
            sample = D_800658A0[sample];
            MATCHING_KEEP2_CLOBBER(sample, scratch, "$6");
            preparedDirection = scratch;
            direction.z = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            direction.y = sample >> 3;
            func_8004F194(prepared, preparedPosition, preparedDirection);
        }
            func_8004F1C8(scratch, retained, scratch);
            {
                register int hit __asm__("$2") = func_80018368(&endpoint, scratch);
                register Vector3D* destination __asm__("$4");
                MATCHING_KEEP2_CLOBBER(hit, retained, "$4");
                destination = retained;
                if (hit) {
                    MATCHING_BARRIER("$2");
                    scratch = DecodedEveningCollision;
                    MATCHING_KEEP(scratch);
                    func_8004F178(destination, scratch);
                    moby->angle.yaw = func_8004E880(*(int*)((char*)scratch + 24), D_8007191C, 0);
                    scratch = (Vector3D*)((char*)scratch + 24);
                    MATCHING_KEEP(scratch);
                    value = func_8004EDE8(scratch, 0);
                    moby->angle.pitch = func_8004E880(value, D_80071920, 0);
                    func_80055D24(moby, 4);
                }
            }
            moby->state = 1;
            break;
        case 1:
            MATCHING_BARRIER("$4");
            if (!func_8003BFC0(moby, tag[0])) {
                tag[0] = func_8003BABC(moby, 0, 4);
            }
            {
                register Moby* drawMoby __asm__("$4") = moby;
                register int zero __asm__("$5") = 0;
                MATCHING_KEEP2_CLOBBER(drawMoby, zero, "$16");
                scratch = &particlePosition;
                func_80055F14(drawMoby, zero, scratch);
            }
            difference.x = (D_80065920[moby->angle.yaw] * 3) >> 6;
            difference.y = (D_800658A0[moby->angle.yaw] * 3) >> 6;
            difference.z = 0;
            difference.x += (rand() & 14) - 7;
            difference.y += (rand() & 14) - 7;
            difference.z += (rand() & 14) - 7;
            SpawnParticle(1, 19, scratch, &difference);
            break;
    }
    retained = &difference;
    func_8004F1C8(retained, (Vector3D*)DecodedEveningPlayer, &moby->position);
    {
        register SHORTMATRIX* transpose __asm__("$16") = &matrix;
        func_8004ECF4(transpose, &moby->rotationMatrix);
        func_8004ED6C(transpose, retained, retained);
    }
    value = difference.x;
    if (value <= 0)
        goto done;
    if (value >= 6144)
        goto done;
    {
        value = difference.y;
        if (value < 0)
            value = -value;
        if (value < 512) {
            value = difference.z;
            if (value < 0)
                value = -value;
            if (value < 512) {
                *(int*)(DecodedEveningPlayer + 36) |= 14;
                *(int*)(DecodedEveningPlayer + 664) = moby->angle.yaw;
            }
        }
    }
done:;
}

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
void func_level_30_8007CB40(Moby* arg0) {
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

/* AI generated adaptation; not human reviewed. Original SCUS-94467 level30 8007D3C8. */
typedef struct {
    int unk0;
    PathTag* path;
    int timer;
} Vehicle692Tag;
extern Moby* Vehicle692Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*, int);
void func_level_30_8007D3C8(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3, count;
    Vehicle692Tag* mobyTag;

    mobyTag = (Vehicle692Tag*)arg0->mobyTag;
    switch (arg0->state) {

        case 0:
            switch (arg0->substate) {
                case 0:
                    if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                        func_80055B18(arg0);
                        return;
                    } else {
                        arg0->state = 1;
                        count = eggsCollectedArray[lvlIdToIndex[31]] & 1;
                        if (eggsCollectedArray[lvlIdToIndex[32]] & 1)
                            count++;
                        if (eggsCollectedArray[lvlIdToIndex[33]] & 1)
                            count++;
                        if (eggsCollectedArray[lvlIdToIndex[34]] & 1)
                            count++;
                        if (eggsCollectedArray[lvlIdToIndex[36]] & 1)
                            count++;
                        if (count == 5) {
                            func_80034F80(arg0, 0);
                            progressFlags.lvl30_RocketUsable = 1;
                            arg0->state = 1;
                        } else {
                            func_80034F80(arg0, 2);
                            arg0->state = 99;
                        }
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
                if (Vehicle692Moby != 0) {
                    *((unsigned char*)Vehicle692Moby + 0x4C) = 0;
                    *((unsigned char*)Vehicle692Moby + 0x4D) = 0;
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007DE98,592 native instructions in sibling4533 and original assembly.
 * Verified20 sibling C reused only where original agrees; raw units,
 * helper/asset meanings and cadence unresolved; uninstalled until exact. */
#define R30Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char R30Flags __asm__("D_8006C7B4");
extern unsigned char R30Levels[] __asm__("D_80070300");
extern int R30Level __asm__("D_8006C58C");
extern int R30Mode __asm__("D_8006E344");
extern unsigned char* R30Pool __asm__("D_8006C550");
extern int R30PlayerFlags __asm__("D_80070328 + 0x20C");
int R30Helper37BBC() __asm__("func_80037BBC");
int R30Helper512E4() __asm__("func_800512E4");
int R30Helper35A80() __asm__("func_80035A80");
int R30ApproximatePlanarDistance() __asm__("func_8004F334");
int R30RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int R30RequestMobyAnimation() __asm__("func_80034F40");
int R30DeleteMoby() __asm__("func_80055B18");
int R30Helper492DC() __asm__("func_800492DC");
extern void* (*R30SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
extern unsigned char R30LevelByte __asm__("D_80066FCC + 0x2F");
extern unsigned char R30Table[] __asm__("D_80071570");
extern unsigned char R30Camera[] __asm__("D_8006E17C");
extern int R30CameraMode __asm__("D_8006E160");
int R30CopyVector() __asm__("func_8004F178");
int R30Helper136F0() __asm__("func_800136F0");
extern int R30Gate __asm__("D_8006C770");
int R30Helper365E4() __asm__("func_800365E4");
int R30Helper1A358() __asm__("func_8001A358");
extern unsigned char R30Map[] __asm__("D_80066FCC");
extern unsigned char R30GateTable[] __asm__("D_80071FB0");
extern short R30Cos[] __asm__("D_80065920");
extern short R30Sin[] __asm__("D_800658A0");
int R30AddVector() __asm__("func_8004F194");
int R30Helper37014() __asm__("func_80037014");
void func_level_30_8007DE98(void* input) {
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
    register int old20 __asm__("$20");
    register int result16 __asm__("$16");
    register int old16 __asm__("$16");
    register unsigned char* position19 __asm__("$19");
    register int new6 __asm__("$6");
    register int index4 __asm__("$4");
    register unsigned char* pool7 __asm__("$7");
    register int* counter20 __asm__("$20");
    register int count19 __asm__("$19");
    register int heading16 __asm__("$16");
    register void* call6 __asm__("$6");
    int vector[4];
    register int multiplier4 __asm__("$4");
    __asm__("" : "=r"(owner), "=r"(linked5) : "0"(owner));
    tag = R30Field(owner, unsigned char**, 0);
    work2 = R30Field(tag, unsigned char*, 0);
    one4 = 1;
    if (work2 != one4)
        goto normal;
    work3 = R30Field(tag, int*, 40);
    pool7 = R30Pool;
    work2 = work3 * 11;
    MATCHING_KEEP(work2);
    work2 <<= 3;
    MATCHING_KEEP(work2);
    work2 += (int)pool7;
    counter20 = R30Field((void*)work2, int**, 0);
    work3 = owner[72];
    if (work3 == 0)
        goto special_zero;
    if (work3 == one4)
        goto special_one;
    goto done;
special_zero:
    work2 = owner[73];
    if (work2 == 0)
        goto special_begin;
    if (work2 == one4) {
        call4 = owner;
        goto special_wait;
    }
    MATCHING_BARRIER_VOLATILE("memory");
    goto done;
special_begin:
    work2 = R30Field(tag, int*, 36);
    work2 = R30Map[work2];
    if (!(R30Levels[work2] & 1))
        goto remove;
    if (R30GateTable[R30Map[37]])
        goto remove;
    index4 = R30Levels[R30Map[31]];
    MATCHING_KEEP_CLOBBER(index4, "$2");
    work2 = R30Levels[R30Map[32]];
    MATCHING_KEEP(work2);
    work2 &= 1;
    MATCHING_KEEP_CLOBBER(work2, "$19");
    count19 = index4 & 1;
    if (work2)
        count19++;
    if (R30Levels[R30Map[33]] & 1)
        count19++;
    if (R30Levels[R30Map[34]] & 1)
        count19++;
    work2 = R30Levels[R30Map[36]] & 1;
    multiplier4 = 0x66660000;
    if (work2)
        count19++;
    {
        register int high8 __asm__("$8");
        register int product __asm__("lo");
        MATCHING_KEEP(multiplier4);
        work3 = *counter20;
        multiplier4 |= 0x6667;
        work2 = work3 << 8;
        product = work2 * multiplier4;
        work2 >>= 31;
        R30Field(tag, int*, 44) = work3;
        __asm__("" : "=h"(high8) : "l"(product));
        work3 = high8 >> 1;
        heading16 = work3 - work2;
    }
    call4 = owner + 12;
    if (count19 == 5) {
        work2 = pool7[R30Field(tag, int*, 40) * 88 + 70];
        MATCHING_KEEP_CLOBBER(work2, "$16");
        heading16 += 25;
        MATCHING_KEEP2(heading16, work2);
        work2 = heading16 + work2;
        heading16 = work2 & 255;
        work3 = heading16 << 1;
        work2 = *(short*)((unsigned char*)R30Cos + work3);
        MATCHING_KEEP(work2);
        R30Field(owner, int*, 12) = work2 >> 1;
        work2 = *(short*)((unsigned char*)R30Sin + work3);
        R30Field(owner, int*, 20) = 0;
        MATCHING_KEEP_VOLATILE_CLOBBER(work2, "memory");
        R30Field(owner, int*, 16) = work2 >> 1;
        work2 = R30Field(tag, int*, 40);
        MATCHING_KEEP_CLOBBER(work2, "$5");
        call5 = (int)call4;
        call6 = (void*)(work2 * 88);
        call6 = pool7 + (int)call6 + 12;
        R30AddVector(call4, (void*)call5, call6);
        MATCHING_OBSERVE2_VOLATILE_CLOBBER(heading16, pool7, "memory");
        owner[70] = heading16;
        goto special_feedback;
    } else {
        __asm__ volatile("" : "=r"(heading16) : "0"(heading16) : "$2", "$3", "$6", "memory");
        work3 = R30Field(tag, int*, 40);
        call6 = R30Pool;
        work2 = ((unsigned char*)call6)[work3 * 88 + 70];
        MATCHING_KEEP(work2);
        work2 = heading16 + work2;
        heading16 = work2 & 255;
        work3 = heading16 << 1;
        work2 = *(short*)((unsigned char*)R30Cos + work3);
        MATCHING_KEEP(work2);
        R30Field(owner, int*, 12) = work2 >> 1;
        work2 = *(short*)((unsigned char*)R30Sin + work3);
        R30Field(owner, int*, 20) = 0;
        MATCHING_KEEP_VOLATILE_CLOBBER(work2, "memory");
        R30Field(owner, int*, 16) = work2 >> 1;
        work3 = R30Field(tag, int*, 40);
        MATCHING_KEEP_CLOBBER(work3, "$5");
        call5 = (int)call4;
        call6 = (unsigned char*)call6 + work3 * 88 + 12;
        R30AddVector(call4, (void*)call5, call6);
        MATCHING_OBSERVE2_VOLATILE_CLOBBER(heading16, call6, "memory");
    }
    owner[70] = heading16;
    work2 = R30Field(tag, int*, 44);
    if (work2) {
        work2 = heading16 + 128;
        owner[70] = work2;
    }
special_feedback:
    R30Helper37014(owner);
    owner[82] = 254;
    R30RefreshMobySpatialGridAndBasis(owner, 6);
    if (count19 == 5) {
        work2 = 1;
        R30Field(tag, unsigned char*, 2) = work2;
        R30Field(tag, unsigned char*, 5) = 0;
    } else {
        work2 = R30Field(tag, int*, 44);
        MATCHING_KEEP(work2);
        if (!work2)
            work2 = 1;
        else
            work2 = 99;
    }
    owner[73] = work2;
    (*counter20)++;
    goto done;
special_wait:
    if (!R30Helper37BBC(call4, 0))
        goto done;
    R30Helper512E4(owner, 0, 1);
    owner[72] = 1;
    goto done;
special_one:
    if (R30Mode == one4)
        goto done;
    R30Field(owner, int*, 24) = 0;
    owner[72] = 0;
    goto done;
normal:
    work3 = R30Field(tag, int*, 0x30);
    MATCHING_KEEP(work3);
    if (work3 >= 0)
        linked5 = R30Field(R30Pool + work3 * 88, unsigned char**, 0);
    work3 = R30Field(owner, unsigned char*, 0x48);
    if (work3 == one4)
        goto state1;
    if (work3 < 2) {
        if (!work3)
            goto state0;
        goto tail;
    }
    if (work3 == 2)
        goto state2;
    if (work3 == 3)
        goto state3;
    goto tail;
state0:
    work3 = R30Field(owner, unsigned char*, 0x49);
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
    work2 = R30Field(linked5, int*, 12);
    if (work2 >= 0 && R30Table[work2])
        goto remove;
    R30Field(owner, unsigned char*, 0x49) = 4;
    goto tail;
sub1:
    R30PlayerFlags = 0x10000002;
    if (R30Helper37BBC(owner, 0)) {
        R30Helper512E4(owner, 0, 1);
        owner[72] = 1;
    }
    goto tail;
sub4:
    if (!R30Table[R30Field(linked5, int*, 12)])
        goto tail;
    work2 = R30Field(tag, int*, 0x38);
    playerFlags6 = 0x10000000;
    if (work2) {
        camera = R30Camera;
        linked5 = R30Field((void*)work2, unsigned char**, 12);
        R30CopyVector(camera, linked5 + 16);
        linked5 = R30Field(R30Field(tag, void**, 0x38), unsigned char**, 12);
        R30Helper136F0(camera - 20, linked5, linked5 + 16);
        R30CameraMode = 17;
        MATCHING_BARRIER_VOLATILE("memory");
        playerFlags6 = 0x10000000;
    }
    playerFlags6 |= 2;
    work2 = R30Field(tag, int*, 0x34);
    __asm__("" : "=r"(work2) : "0"(work2) : "$4", "$5");
    call4 = owner;
    R30Field((void*)work2, short*, 2) = 0;
    work3 = R30Field(tag, int*, 0x34);
    R30Field((void*)work3, short*, 10) = 1;
    work2 = R30Field(owner, int*, 20);
    MATCHING_KEEP_CLOBBER(work2, "$5");
    call5 = 2;
    work2 -= 128;
    MATCHING_KEEP(work2);
    R30Field(owner, int*, 20) = work2;
    R30PlayerFlags = playerFlags6;
    work2 = 2;
    goto set3Call;
    goto tail;
state1:
    if (R30Mode == one4)
        goto tail;
    if (R30Field(tag, void**, 0x34)) {
        work2 = R30Field(tag, int*, 0x38);
        call4 = owner;
        MATCHING_KEEP(call4);
        if (work2) {
            camera = R30Camera;
            linked5 = R30Field((void*)work2, unsigned char**, 12);
            R30CopyVector(camera, linked5 + 16);
            linked5 = R30Field(R30Field(tag, void**, 0x38), unsigned char**, 12);
            R30Helper136F0(camera - 20, linked5, linked5 + 16);
            R30CameraMode = 17;
        }
        call4 = owner;
        call5 = 2;
        MATCHING_KEEP2(call4, call5);
        R30Field(owner, unsigned char*, 0x49) = 1;
        work2 = 2;
    set3Call:
        R30Field(owner, unsigned char*, 0x48) = work2;
        R30RequestMobyAnimation(call4, call5);
        goto tail;
    }
reset:
    R30Field(owner, unsigned char*, 0x48) = 0;
    R30Field(tag, int*, 0x3C) = 3;
    goto tail;
state2:
    work3 = R30Field(owner, unsigned char*, 0x49);
    if (work3 == one4)
        goto first;
    if (work3 == 4)
        goto fourth;
    goto tail;
first:
    old16 = R30Field(R30Field(tag, void**, 0x34), short*, 2);
    if (!(R30Helper35A80(owner, R30Field(tag, void**, 0x34), 512, 128, 0, 8, 12, 5) & 1))
        goto player;
    linked5 = R30Field(tag, unsigned char**, 0x34);
    new6 = R30Field(linked5, short*, 2);
    if (!new6)
        goto clearCamera;
    work3 = R30Field(linked5, int*, 12);
    if (!(R30Field((void*)(work3 + old16 * 16), int*, 12) & 1))
        goto player;
    work2 = R30Helper365E4(owner + 12, (void*)(work3 + new6 * 16), 128, -8, 0);
    call4 = owner;
    call5 = 3;
    R30Field(tag, int*, 0x40) = work2;
    goto set4Call;
fourth:
    R30PlayerFlags = 0x10000002;
    if (R30Helper35A80(owner, R30Field(tag, void**, 0x34), 512, 128, 0, 8, 12, 5) & 1) {
        R30Field(owner, unsigned char*, 0x49) = 1;
        R30Field(owner, unsigned char*, 0x48) = 0;
        R30RequestMobyAnimation(owner, 0);
    }
    goto tail;
state3:
    old20 = R30Field(R30Field(tag, void**, 0x34), short*, 2);
    work2 = R30Helper35A80(owner, R30Field(tag, void**, 0x34), 512, 128, 0, 8, 12, 0);
    call4 = vector;
    position19 = owner + 12;
    __asm__("" : "=r"(call4), "=r"(position19) : "0"(call4), "1"(position19) : "$6", "$16");
    new6 = R30Field(tag, int*, 0x40);
    MATCHING_KEEP_CLOBBER(new6, "$5");
    call5 = (int)position19;
    new6 -= 8;
    R30Field(tag, int*, 0x40) = new6;
    work3 = R30Field(owner, int*, 20);
    MATCHING_KEEP2_CLOBBER(work3, work2, "$16");
    result16 = work2;
    work3 += new6;
    R30Field(owner, int*, 20) = work3;
    R30CopyVector(call4, call5);
    vector[2] += 512;
    if (R30Helper1A358(vector, 512)) {
        R30Field(owner, unsigned char*, 0x48) = 2;
        R30RequestMobyAnimation(owner, 2);
    }
    work2 = result16 & 1;
    MATCHING_KEEP(work2);
    if (!work2)
        goto player;
    linked5 = R30Field(tag, unsigned char**, 0x34);
    new6 = R30Field(linked5, short*, 2);
    if (!new6) {
    clearCamera:
        if (R30Field(tag, void**, 0x38))
            R30CameraMode = 0;
    remove:
        R30DeleteMoby(owner);
        return;
    }
    work3 = R30Field(linked5, int*, 12);
    if (!(R30Field((void*)(work3 + old20 * 16), int*, 12) & 1))
        goto player;
    work2 = R30Helper365E4(position19, (void*)(work3 + new6 * 16), 128, -8, 0);
    call4 = owner;
    call5 = 3;
    R30Field(tag, int*, 0x40) = work2;
    R30Field(owner, unsigned char*, 0x3D) = 2;
set4Call:
    R30Field(owner, unsigned char*, 0x48) = 3;
    R30RequestMobyAnimation(call4, call5);
player:
    MATCHING_BARRIER("$2");
    R30PlayerFlags = 0x10000002;
    R30Helper492DC(owner + 12);
tail:
    work3 = R30Field(tag, int*, 0x30);
    if (work3 < 0)
        return;
    if (R30Field(owner, unsigned char*, 0x48) < 2)
        return;
    if (R30ApproximatePlanarDistance(owner + 12, R30Pool + work3 * 88 + 12) < 512)
        R30SpawnParticle(2, 12, R30Pool + R30Field(tag, int*, 0x30) * 88, (void*)5);
done:
    MATCHING_BARRIER_VOLATILE("memory");
}
#undef R30Field

extern Moby* D_8006C550;
extern unsigned char D_80071570[];
typedef struct {
    unsigned char reserved00[0x30];
    int poolIndex;
} DecodedPoolSelector;
typedef struct {
    unsigned char reserved00[0x0C];
    int flagOffset;
} DecodedPoolFlagSelector;
void func_800584BC(int, int);
void func_80055B18(Moby*);
void func_level_30_8007E7D8(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (D_80071570[((DecodedPoolFlagSelector*)D_8006C550
                                [((DecodedPoolSelector*)D_8006C550[*tag].mobyTag)->poolIndex]
                                    .mobyTag)
                               ->flagOffset])
                goto release;
            func_8004F178(&D_8006C550[*tag].position, &moby->position);
            D_8006C550[*tag].position.z += 256;
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
            func_800584BC(6, 79);
        release:
            func_80055B18(moby);
            break;
    }
}

typedef struct {
    int counter;
    unsigned int* effect;
} DecodedPulsingParticleTag;
extern int D_8006C648, D_8006C640;
extern short D_80065920[];
int rand(void);
void* func_8002EC50(int, int, int);
void func_80055F14(Moby*, int, Vector3D*);
void func_level_30_8007E9D8(Moby* moby) {
    DecodedPulsingParticleTag* tag = moby->mobyTag;
    Vector3D position, offset;
    Colour colour;
    register int wave __asm__("$2");
    register int brightness __asm__("$4");
    register int red __asm__("$3");
    register int blue __asm__("$2");
    tag->counter += D_8006C648;
    tag->counter += rand() & 7;
    func_80055F14(moby, 0, &position);
    if (!tag->effect) {
        tag->effect = func_8002EC50(1, 0xC0, 0x64C7C7);
        if (!tag->effect)
            goto particles;
    }
    wave = D_80065920[(tag->counter * 4) & 0xFC];
    MATCHING_KEEP(wave);
    brightness = ABS(wave);
    MATCHING_KEEP(brightness);
    brightness = (brightness * 3 >> 2) + 0x400;
    MATCHING_KEEP(brightness);
    red = (brightness * 199) >> 12;
    blue = (brightness * 100) >> 12;
    MATCHING_KEEP2(red, blue);
    colour.r = red;
    colour.g = red;
    colour.b = blue;
    tag->effect[3] = colour.r | (colour.g << 8) | (colour.b << 16);
    func_8004F178((Vector3D*)tag->effect, &position);
particles:
    if (!(D_8006C640 & 3)) {
        offset.x = (rand() & 0x1E) - 0xF;
        offset.y = (rand() & 0x1E) - 0xF;
        offset.z = rand() & 7;
        SpawnParticle(1, 0x27, &position, &offset);
    }
    colour.r = 0x90;
    colour.g = 0x90;
    colour.b = 0x48;
    SpawnParticle(3, 0x56, &position, (Vector3D*)&colour);
}

extern ProgressFlags progressFlags;

extern int D_8006C598, D_8006C73C, D_8006C528, currentLevel;
extern short D_800658A0[256], D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
/* AI generated adaptation of upstream func_level_17_8007D19C; not human reviewed.
 * Original SCUS-94467 level30 8007EB98 instruction route; units/cadence open. */
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
void func_level_30_8007EB98(Moby* moby) {
    Vector3D vector1;
    Vector3D vector2;
    Vector3D vector3;
    Vector3D vector4;
    int remainder;
    int count;
    Vehicle506Tag* mobyTag;

    mobyTag = (Vehicle506Tag*)moby->mobyTag;
    switch (moby->state) {

        case 0:
            switch (moby->substate) {
                case 0:
                    if (progressFlags.lvl30_RocketUsable ||
                        ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable) ||
                        ((count = eggsCollectedArray[lvlIdToIndex[31]] & 1),
                         (eggsCollectedArray[lvlIdToIndex[32]] & 1 ? count++ : 0),
                         (eggsCollectedArray[lvlIdToIndex[33]] & 1 ? count++ : 0),
                         (eggsCollectedArray[lvlIdToIndex[34]] & 1 ? count++ : 0),
                         (eggsCollectedArray[lvlIdToIndex[36]] & 1 ? count++ : 0), count == 5)) {
                        func_80055B18(moby);
                        return;
                    } else {
                        moby->state = 1;
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Controller7F440Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller7F440_func_80037BBC() __asm__("func_80037BBC");                 /* extern */
int Controller7F440_func_800512E4() __asm__("func_800512E4");                 /* extern */
int Controller7F440DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7F440RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7F440_rand() __asm__("rand");                                   /* extern */
extern unsigned char Controller7F440_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller7F440_D_80065920 __asm__("D_80065920");
extern unsigned char Controller7F440_D_80066FCC __asm__("D_80066FCC");
extern int Controller7F440_D_8006C550 __asm__("D_8006C550");
extern int Controller7F440_D_8006C640 __asm__("D_8006C640");
extern int Controller7F440_D_8006C770 __asm__("D_8006C770");
extern int Controller7F440_D_8006E344 __asm__("D_8006E344");
extern unsigned char Controller7F440_D_80070300 __asm__("D_80070300");
extern unsigned char Controller7F440_D_80071FB0 __asm__("D_80071FB0");

void func_level_30_8007F440(Moby* incomingMoby) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        char pad_1c[4];
    } frame;

    register Moby* moby __asm__("$16") = incomingMoby;

    register Vector3D* position4 __asm__("$4");
    register int quotient3 __asm__("$3");
    register int recordBase6 __asm__("$6");
    register Moby* initialArgument4 __asm__("$4") = incomingMoby;
    register int value3 __asm__("$3");
    register int value4 __asm__("$4");
    register int* counter20 __asm__("$20");
    register int angle17 __asm__("$17");
    register int counterValue3 __asm__("$3");
    int tableOffset3;
    int tableOffset3Again;
    register int flagCount18 __asm__("$18");
    register signed char* particle16 __asm__("$16");
    register int value2 __asm__("$2");
    register int angle17Adjusted __asm__("$17");
    register int angle17Again __asm__("$17");
    unsigned char substate;
    unsigned char state;
    register int nextSubstate2 __asm__("$2");
    register void* tag19 __asm__("$19");

    MATCHING_KEEP(moby);
    tag19 = moby->mobyTag;
    counter20 = Controller7F440Field(
        (Controller7F440Field(tag19, int*, 0x2C) * 0x58) + Controller7F440_D_8006C550, int**, 0);
    if ((Controller7F440Field(tag19, int*, 0x24) != 0) && ((unsigned int)(moby->state - 1) >= 2U) &&
        (moby->damageFlags != 0)) {
        moby->state = 2;
        func_80034F40(initialArgument4, 2);
    }
    state = moby->state;
    switch (state) {
        case 0:
            substate = moby->substate;
            switch (substate) {
                case 0:
                    if (!(*(&Controller7F440_D_80070300 +
                            *(&Controller7F440_D_80066FCC +
                              Controller7F440Field(tag19, int*, 0x28))) &
                          1) ||
                        (*(&Controller7F440_D_80071FB0 +
                           Controller7F440Field(&Controller7F440_D_80066FCC, unsigned char*,
                                                0x25)) != 0)) {
                        Controller7F440DeleteMoby(moby);
                        return;
                    }
                    value2 =
                        Controller7F440Field(&Controller7F440_D_80066FCC, unsigned char*, 0x1F);
                    value3 =
                        Controller7F440Field(&Controller7F440_D_80066FCC, unsigned char*, 0x20);
                    MATCHING_KEEP2(value2, value3);
                    value4 = *(&Controller7F440_D_80070300 + value2);
                    MATCHING_KEEP(value4);
                    flagCount18 = value4 & 1;
                    if (*(&Controller7F440_D_80070300 + value3) & 1) {
                        flagCount18 += 1;
                    }
                    if (*(&Controller7F440_D_80070300 +
                          Controller7F440Field(&Controller7F440_D_80066FCC, unsigned char*, 0x21)) &
                        1) {
                        flagCount18 += 1;
                    }
                    if (*(&Controller7F440_D_80070300 +
                          Controller7F440Field(&Controller7F440_D_80066FCC, unsigned char*, 0x22)) &
                        1) {
                        flagCount18 += 1;
                    }
                    if (*(&Controller7F440_D_80070300 +
                          Controller7F440Field(&Controller7F440_D_80066FCC, unsigned char*, 0x24)) &
                        1) {
                        flagCount18 += 1;
                    }
                    counterValue3 = *counter20;
                    value2 = counterValue3 << 8;
                    MATCHING_KEEP(value2);
                    Controller7F440Field(tag19, int*, 0x30) = counterValue3;
                    /* Separate the signed division correction to retain the original
             * high-product result in register3 before the subtraction into17. */
                    quotient3 = (value2 / 5) + (value2 >> 31);
                    angle17 = quotient3 - (value2 >> 31);
                    if (flagCount18 == 5) {
                        position4 = &moby->position;
                        MATCHING_KEEP(position4);
                        value3 = Controller7F440Field(tag19, int*, 0x2C);
                        MATCHING_KEEP(value3);
                        recordBase6 = Controller7F440_D_8006C550;
                        MATCHING_KEEP(recordBase6);
                        value2 = Controller7F440Field((value3 * 0x58) + recordBase6, unsigned char*,
                                                      0x46);
                        MATCHING_KEEP(value2);
                        angle17 += 25;
                        MATCHING_KEEP(angle17);
                        value2 = angle17 + value2;
                        MATCHING_KEEP(value2);
                        angle17Adjusted = value2 & 255;
                        tableOffset3 = angle17Adjusted * 2;
                        value2 =
                            Controller7F440Field(&Controller7F440_D_80065920, short*, tableOffset3);
                        MATCHING_KEEP(value2);
                        moby->position.x = value2 >> 1;
                        value2 =
                            Controller7F440Field(&Controller7F440_D_800658A0, short*, tableOffset3);
                        MATCHING_KEEP(value2);
                        moby->position.z = 0;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        moby->position.y = value2 >> 1;
                        func_8004F194(position4, position4,
                                      recordBase6 +
                                          (Controller7F440Field(tag19, int*, 0x2C) * 0x58) + 0xC);
                        moby->angle.yaw = angle17Adjusted;
                    } else {
                        position4 = &moby->position;
                        MATCHING_KEEP(position4);
                        value3 = Controller7F440Field(tag19, int*, 0x2C);
                        MATCHING_KEEP(value3);
                        recordBase6 = Controller7F440_D_8006C550;
                        MATCHING_KEEP(recordBase6);
                        value2 = Controller7F440Field((value3 * 0x58) + recordBase6, unsigned char*,
                                                      0x46);
                        value2 = angle17 + value2;
                        MATCHING_KEEP(value2);
                        angle17Again = value2 & 255;
                        tableOffset3Again = angle17Again * 2;
                        value2 = Controller7F440Field(&Controller7F440_D_80065920, short*,
                                                      tableOffset3Again);
                        MATCHING_KEEP(value2);
                        moby->position.x = value2 >> 1;
                        value2 = Controller7F440Field(&Controller7F440_D_800658A0, short*,
                                                      tableOffset3Again);
                        MATCHING_KEEP(value2);
                        moby->position.z = 0;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        moby->position.y = value2 >> 1;
                        func_8004F194(position4, position4,
                                      recordBase6 +
                                          (Controller7F440Field(tag19, int*, 0x2C) * 0x58) + 0xC);
                        moby->angle.yaw = angle17Again;
                        if (Controller7F440Field(tag19, int*, 0x30) != 0) {
                            value2 = angle17Again + 128;
                            MATCHING_KEEP(value2);
                            moby->angle.yaw = value2;
                        }
                    }
                    func_80037014(moby);
                    moby->subtype = 0xFE;
                    Controller7F440RefreshMobySpatialGridAndBasis(moby, 6);
                    value2 = 5;
                    MATCHING_KEEP(value2);
                    if (flagCount18 == value2) {
                        nextSubstate2 = 1;
                        Controller7F440Field(tag19, signed char*, 2) = nextSubstate2;
                        Controller7F440Field(tag19, signed char*, 5) = 0;
                    } else {
                        value2 = Controller7F440Field(tag19, int*, 0x30);
                        MATCHING_KEEP(value2);
                        if (value2 == 0) {
                            nextSubstate2 = 1;
                        } else {
                            nextSubstate2 = 99;
                        }
                    }
                    moby->substate = nextSubstate2;
                    *counter20 += 1;
                    return;
                case 1:
                    if (Controller7F440_func_80037BBC(moby, 0) != 0) {
                        Controller7F440_func_800512E4(moby, 0, 1);
                        moby->state = 1;
                        return;
                    }
                    return;
            }
            break;
        case 1:
            if (Controller7F440_D_8006E344 != state) {
                moby->damageFlags = 0;
                moby->state = 0;
                return;
            }
            break;
        case 2:
            if (Controller7F440_D_8006C770 != 0) {
                moby->damageFlags = 0;
                moby->state = 0;
                func_80034F40(moby, 0);
                return;
            }
            if ((moby->damageFlags & 0x10000) && (Controller7F440_D_8006C640 & 1)) {
                frame.sp10 = (Controller7F440_rand() & 0xF) - 8;
                frame.sp14 = (Controller7F440_rand() & 0xF) - 8;
                frame.sp18 = (Controller7F440_rand() & 0xF) + 8;
                particle16 = SpawnParticle(1, 0x37, &moby->position, (Vector3D*)&frame.sp10);
                if (particle16 != 0) {
                    Controller7F440Field(particle16, unsigned short*, 8) =
                        (unsigned short)(Controller7F440Field(particle16, unsigned short*, 8) +
                                         (Controller7F440_rand() & 0xFF));
                }
            }
            break;
    }
}
#undef Controller7F440Field

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007F94C..8007FD3C. Original instructions define numeric branches.
 * Verified Cloud214 C; original Evening252 differences is discovery only; indirect extra arguments remain unknown. */
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern int D_8006C770;
int func_80055E84(Moby*);
void DecodedEveningTransfer(Vector3D*, void*, int*) __asm__("func_8003645C");
extern unsigned char* DecodedEveningModels[] __asm__("D_8006EE2C");
extern void (*DecodedEveningFollow)(Moby*, void*, int*, int*, int,
                                    int) __asm__("unk_ovlheader_800743EC");
void func_level_30_8007F94C(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    register int* tag __asm__("$17") = moby->mobyTag;
    int angle;
    int transferValue;
    if (moby->substate == 50) {
        if (moby->state == 4)
            goto dispatch;
        if (tag[11]) {
            DecodedEveningTransfer(&moby->position, (void*)tag[11], &transferValue);
            *(short*)((unsigned char*)tag[11] + 2) = transferValue;
            *((unsigned char*)tag + 0x4B) = 4;
        } else
            *((unsigned char*)tag + 0x4B) = 16;
        moby->substate = 0;
    }
    if (moby->state != 4) {
        register int amount __asm__("$2");
        if (moby->damageFlags & 0x10000)
            amount = 250;
        else if (moby->damageFlags)
            amount = 400;
        else
            goto dispatch;
        *(short*)((unsigned char*)tag + 0x40) = amount;
        angle = moby->unkb;
        if (!angle)
            angle = func_800360F8(
                func_8004E880(moby->position.x - *(int*)DecodedCrystalPlayer,
                              moby->position.y - *(int*)(DecodedCrystalPlayer + 4), 0),
                DecodedCrystalPlayer[14], 32, 64);
        *((unsigned char*)tag + 0x4D) = angle;
        if (moby->state != 5)
            *(short*)((unsigned char*)tag + 0x42) = 200;
        moby->unknownCollision = 0;
        SpawnMoby(16, moby);
        moby->state = 4;
        func_80034F40(moby, 4);
    }
dispatch:
    switch (moby->state) {
        case 0:
            if (tag[11]) {
                register unsigned int count __asm__("$2");
                register int multipleFrames __asm__("$2");
                moby->subtype = 255;
                *((unsigned char*)tag + 0x4B) = 4;
                moby->state = 5;
                count = **(unsigned char**)(DecodedEveningModels[moby->mobyClass] + 0x50);
                moby->animationState.id = 5;
                moby->animationState.nextId = 5;
                moby->animationState.frame = 0;
                moby->animationState.nextFrame = 1;
                multipleFrames = count >= 2;
                MATCHING_KEEP(multipleFrames);
                moby->animationProgress = -multipleFrames & 48;
                break;
            }
            if (*((unsigned char*)moby + 0x4D) &&
                func_8004F334(&moby->position, (Vector3D*)DecodedCrystalPlayer) < 16384) {
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
            func_80035194(moby, (unsigned char*)tag + 0x3C);
            if (D_8006C770) {
                moby->substate = 50;
                func_80055D24(moby, 4);
                func_800369B8(moby, 24);
                func_80055B18(moby);
            }
            break;
        case 5:
            DecodedEveningFollow(moby, (void*)tag[11], tag + 12, tag + 6, 16, 0);
            func_80035D38(moby);
            func_8005629C(moby);
            break;
    }
}

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
void func_level_30_8007FD3C(unsigned char* input) {
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
void func_level_30_8008095C(Moby* argument) {
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
void func_level_30_80080D94(Moby* moby) {
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
void func_level_30_800810C4(void* input) {
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

void func_level_30_80082218(Moby* moby) {
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
void func_level_30_80082238(Moby* argument) {
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
void func_level_30_80082438(Moby* moby) {
    if (D_8006C770 != 0)
        func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_30/moby/func_level_30_80082464.s SHA256 b11cdc1b1495e9000d2bfb0e56932406841b807c3e1cf44e2a6d3986ac73c76d. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level30_82464Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char Level30_82464_func_80013AE4() __asm__("func_80013AE4");
/* extern */
unsigned char Level30_82464_func_80013B7C() __asm__("func_80013B7C");
/* extern */
unsigned char Level30_82464_func_80021ED8() __asm__("func_80021ED8");
/* extern */
unsigned char Level30_82464RequestMobyAnimation() __asm__("func_80034F40");
/* extern */
int Level30_82464CountTimerDown() __asm__("func_800359A4");
/* extern */
unsigned char Level30_82464PlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned char Level30_82464_func_8003BB10() __asm__("func_8003BB10");
/* extern */
unsigned char Level30_82464AddVector() __asm__("func_8004F194");
/* extern */
int Level30_82464_func_8004F388() __asm__("func_8004F388");
/* extern */
unsigned char Level30_82464DeleteMoby() __asm__("func_80055B18");
/* extern */
int Level30_82464_func_80055E84() __asm__("func_80055E84");
/* extern */
extern unsigned char Level30_82464_D_80066FCC __asm__("D_80066FCC");
extern unsigned int Level30_82464_D_8006C550 __asm__("D_8006C550");
extern unsigned int Level30_82464_D_8006C704 __asm__("D_8006C704");
extern int Level30_82464_D_8006C770 __asm__("D_8006C770");
extern int Level30_82464_D_8006D058 __asm__("D_8006D058");
extern int Level30_82464_D_8006E048 __asm__("D_8006E048");
extern int Level30_82464_D_8006E53C __asm__("D_8006E53C");
extern unsigned char Level30_82464_D_80070300 __asm__("D_80070300");
extern unsigned char Level30_82464_D_8007158E __asm__("D_8007158E");
extern unsigned char Level30_82464_D_8007159A __asm__("D_8007159A");
extern int (*Level30_82464_unk_ovlheader_800743EC)() __asm__("unk_ovlheader_800743EC");

void func_level_30_80082464(void* ownerRecord) {
    /* Original 0x40-byte frame: scratch words at SP+0x18/+0x1C/+0x20;
     * saved registers begin at SP+0x28. The pool record stride is 88 bytes.
     * The vector table index uses SLL4 byte addressing, not pointer scaling.
     * The callback precedes its dependent pointer loads. Empty constraints
     * retain original producers and load-delay scheduling without opcodes.
     * Physical units, helper semantics and caller cadence remain unresolved. */
    struct {
        int sp18;
        int sp1C;
        int sp20;
        unsigned char pad24[4];
    } scratch;

    short temp_v1_2;
    register int loadedWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register void* ownerArgument4 __asm__("$4");
    register int selectorArgument5 __asm__("$5");
    register unsigned int poolEnd2 __asm__("$2");
    register int recordCode20 __asm__("$20");
    register void* sharedAddress3 __asm__("$3");
    void* vectorBase7;
    int temp_a0;
    int temp_a0_2;
    int callbackPointer4;
    int temp_a1;
    int temp_a1_2;
    int temp_a1_3;
    int temp_a1_4;
    int temp_a1_5;
    int temp_a1_6;
    int temp_s0;
    int callbackResult16;
    int temp_v0_2;
    int temp_v0_3;
    int var_a0;
    unsigned int poolCursor17;
    unsigned char temp_v1;
    void* temp_a0_4;
    void* temp_a0_5;
    void* vectorRecord6;
    void* privateRecord;
    void* temp_v0;
    void* var_a0_2;
    void* poolStateCursor16;

    privateRecord = Level30_82464Field(ownerRecord, void**, 0);
    if (Level30_82464Field(ownerRecord, unsigned char*, 0x49) == 0) {
        Level30_82464Field(ownerRecord, signed char*, 0x41) = 0;
        Level30_82464Field(ownerRecord, signed char*, 0x4C) = 0;
        Level30_82464Field(ownerRecord, signed char*, 0x4D) = 0;
        Level30_82464Field(ownerRecord, int*, 8) = 0;
        if ((((*(&Level30_82464_D_80070300 +
                 Level30_82464Field(&Level30_82464_D_80066FCC, unsigned char*, 0x1F)) &
               1) +
              (*(&Level30_82464_D_80070300 +
                 Level30_82464Field(&Level30_82464_D_80066FCC, unsigned char*, 0x20)) &
               1) +
              (*(&Level30_82464_D_80070300 +
                 Level30_82464Field(&Level30_82464_D_80066FCC, unsigned char*, 0x21)) &
               1) +
              (*(&Level30_82464_D_80070300 +
                 Level30_82464Field(&Level30_82464_D_80066FCC, unsigned char*, 0x22)) &
               1) +
              (*(&Level30_82464_D_80070300 +
                 Level30_82464Field(&Level30_82464_D_80066FCC, unsigned char*, 0x24)) &
               1)) >= 3) &&
            ((sharedAddress3 = &Level30_82464_D_8007159A, __extension__({
                  MATCHING_KEEP(sharedAddress3);
                  *(unsigned char*)sharedAddress3;
              })) == 0) &&
            (Level30_82464_D_8007158E == 0)) {
            Level30_82464Field(ownerRecord, unsigned char*, 0x49) = 1U;
            *(unsigned char*)sharedAddress3 = 1;
        }
    } else {
        if (Level30_82464_D_8006E53C & 0x800) {
            Level30_82464Field(ownerRecord, unsigned char*, 0x48) = 6U;
            Level30_82464_func_80013B7C(1);
            Level30_82464Field(ownerRecord, signed char*, 0x41) = 0;
        }
        temp_v1 = Level30_82464Field(ownerRecord, unsigned char*, 0x48);
        switch (temp_v1) {
            case 0:
                if (Level30_82464Field(ownerRecord, unsigned char*, 0x49) == 1) {
                    poolCursor17 = Level30_82464_D_8006C550;
                    if (poolCursor17 < (unsigned int)Level30_82464_D_8006C704) {
                        recordCode20 = 719;
                        MATCHING_KEEP(recordCode20);
                        poolStateCursor16 = poolCursor17 + 0x48;
                        do {
                            if ((Level30_82464Field(poolStateCursor16, short*, -0x12) ==
                                 recordCode20) &&
                                !(Level30_82464Field(poolStateCursor16, unsigned char*, 0) &
                                  0x80)) {
                                Level30_82464DeleteMoby((void*)poolCursor17);
                            }
                            poolEnd2 = Level30_82464_D_8006C704;
                            MATCHING_KEEP(poolEnd2);
                            poolCursor17 += 0x58;
                            poolStateCursor16 += 0x58;
                        } while (poolCursor17 < poolEnd2);
                    }
                    Level30_82464Field(ownerRecord, signed char*, 0x41) = 1;
                    Level30_82464Field(ownerRecord, signed char*, 0x4C) = 0x20;
                    Level30_82464Field(ownerRecord, signed char*, 0x4D) = 1;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x48) = 1;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x41) = 1;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x4C) = 0x7F;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x4D) = 1;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       unsigned char*, 0x54) = 0xFF;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x55) = 0;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x56) = 0;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x57) = 0x38;
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x4A) = 0x7F;
                    Level30_82464Field(ownerRecord, unsigned char*, 0x49) = 2U;
                    __asm__ volatile("" : : : "$2", "$3");
                    loadedWord2 = 10;
                    MATCHING_KEEP_VOLATILE(loadedWord2);
                    sharedAddress3 = &Level30_82464_D_8006D058;
                    __asm__("" : "=r"(sharedAddress3) : "0"(sharedAddress3), "r"(loadedWord2));
                    Level30_82464Field(ownerRecord, signed char*, 0x47) = loadedWord2;
                    Level30_82464Field(privateRecord, int*, 0x1C) = *(int*)sharedAddress3;
                    *(int*)sharedAddress3 = 0;
                    temp_a0 = Level30_82464Field(Level30_82464Field(privateRecord, void**, 0x18),
                                                 int*, 0xC);
                    Level30_82464_func_80013AE4(temp_a0, temp_a0 + 0x10);
                }
                if (Level30_82464_D_8006E048 & 1) {
                    if (Level30_82464Field(ownerRecord, unsigned char*, 0x49) == 2) {
                        temp_a0_2 = Level30_82464Field(
                            Level30_82464Field(privateRecord, void**, 0x18), int*, 0xC);
                        Level30_82464_func_80013AE4(temp_a0_2, temp_a0_2 + 0x10);
                        Level30_82464Field(ownerRecord, unsigned char*, 0x48) = 1U;
                        Level30_82464RequestMobyAnimation(ownerRecord, 1);
                    }
                }
                if (Level30_82464Field(ownerRecord, unsigned char*, 0x49) == 3) {
                    temp_a1 = Level30_82464Field(Level30_82464Field(privateRecord, void**, 0xC),
                                                 int*, 0xC);
                    temp_s0 = Level30_82464Field(privateRecord, int*, 0x20);
                    Level30_82464_func_80013AE4(temp_a1 + 0x10, temp_a1);
                    if (Level30_82464CountTimerDown(privateRecord + 0x20, 4) != 0) {
                        Level30_82464Field(ownerRecord, unsigned char*, 0x48) = 2U;
                        Level30_82464RequestMobyAnimation(ownerRecord, 2);
                        return;
                    }
                    if ((Level30_82464Field(privateRecord, int*, 0x20) < 0x29) &&
                        (temp_s0 >= 0x28)) {
                        Level30_82464PlayMobySoundEvent(ownerRecord, 0, 0);
                        return;
                    }
                } else {
                    default:
                        return;
                }
                break;
            case 1:
                callbackResult16 = Level30_82464_unk_ovlheader_800743EC(
                    ownerRecord, Level30_82464Field(privateRecord, void**, 0x14),
                    privateRecord + 0x24, privateRecord + 0x20, 0xA, 5);
                callbackPointer4 =
                    Level30_82464Field(Level30_82464Field(privateRecord, void**, 0x18), int*, 0xC);
                Level30_82464_func_80013AE4(callbackPointer4, callbackPointer4 + 0x10);
                if ((callbackResult16 & 2) &&
                    ((temp_v0 = Level30_82464Field(privateRecord, void**, 0x14),
                      temp_v1_2 = Level30_82464Field(temp_v0, short*, 2), (temp_v1_2 == 0)) ||
                     (temp_v1_2 == (Level30_82464Field(temp_v0, short*, 0) - 1)))) {
                    Level30_82464Field(ownerRecord, unsigned char*, 0x49) = 3U;
                    Level30_82464Field(privateRecord, int*, 0x20) = 0x2D;
                    Level30_82464Field(ownerRecord, unsigned char*, 0x48) = 0U;
                    Level30_82464RequestMobyAnimation(ownerRecord, 0);
                    return;
                }
                break;
            case 2:
                temp_a1_2 =
                    Level30_82464Field(Level30_82464Field(privateRecord, void**, 0xC), int*, 0xC);
                Level30_82464_func_80013AE4(temp_a1_2 + 0x10, temp_a1_2);
                if (Level30_82464_func_80055E84(ownerRecord) >= 0x16) {
                    temp_a0_4 = (Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                Level30_82464_D_8006C550;
                    if (Level30_82464Field(temp_a0_4, unsigned char*, 0x48) != 2) {
                        Level30_82464PlayMobySoundEvent(temp_a0_4, 0, 0);
                        Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                            Level30_82464_D_8006C550),
                                           signed char*, 0x48) = 2;
                        return;
                    }
                }
                if (Level30_82464_D_8006C770 != 0) {
                    Level30_82464Field(ownerRecord, unsigned char*, 0x48) = 3U;
                    Level30_82464RequestMobyAnimation(ownerRecord, 3);
                    scratch.sp18 = *Level30_82464Field(Level30_82464Field(privateRecord, void**, 8),
                                                       int**, 0xC) -
                                   Level30_82464Field(ownerRecord, int*, 0xC);
                    scratch.sp1C =
                        Level30_82464Field(
                            Level30_82464Field(Level30_82464Field(privateRecord, void**, 8), int**,
                                               0xC),
                            int*, 4) -
                        Level30_82464Field(ownerRecord, int*, 0x10);
                    temp_v0_2 = Level30_82464Field(
                                    Level30_82464Field(Level30_82464Field(privateRecord, void**, 8),
                                                       int**, 0xC),
                                    int*, 8) -
                                Level30_82464Field(ownerRecord, int*, 0x14);
                    var_a0 = temp_v0_2 * 2;
                    scratch.sp20 = temp_v0_2;
                    if (var_a0 < 0) {
                        var_a0 += 7;
                    }
                    temp_v0_3 = Level30_82464_func_8004F388(-(var_a0 >> 3)) + 1;
                    Level30_82464Field(privateRecord, int*, 0x24) = (int)(scratch.sp18 / temp_v0_3);
                    Level30_82464Field(privateRecord, int*, 0x28) = (int)(scratch.sp1C / temp_v0_3);
                    Level30_82464Field(privateRecord, int*, 0x2C) = 0;
                    Level30_82464_func_80021ED8(5, 0xFC, 0);
                    Level30_82464Field(ownerRecord, unsigned char*, 0x49) = 4U;
                    Level30_82464PlayMobySoundEvent(ownerRecord, 2, 0);
                    return;
                }
                break;
            case 3:
                temp_a1_3 =
                    Level30_82464Field(Level30_82464Field(privateRecord, void**, 0xC), int*, 0xC);
                Level30_82464_func_80013AE4(temp_a1_3 + 0x10, temp_a1_3);
                temp_a0_5 = ownerRecord + 0xC;
                Level30_82464Field(privateRecord, int*, 0x2C) =
                    (int)(Level30_82464Field(privateRecord, int*, 0x2C) - 8);
                Level30_82464AddVector(temp_a0_5, temp_a0_5, privateRecord + 0x24);
                if (Level30_82464_D_8006C770 != 0) {
                    Level30_82464Field(privateRecord, int*, 0x20) = 0x3C;
                    Level30_82464Field(ownerRecord, unsigned char*, 0x48) = 4U;
                    Level30_82464RequestMobyAnimation(ownerRecord, 4);
                    return;
                }
                break;
            case 4:
                if (Level30_82464CountTimerDown(privateRecord + 0x20, 4) != 0) {
                    temp_a1_4 = Level30_82464Field(Level30_82464Field(privateRecord, void**, 0x10),
                                                   int*, 0xC);
                    Level30_82464_func_80013AE4(temp_a1_4 + 0x10, temp_a1_4);
                    Level30_82464_D_8006D058 = Level30_82464Field(privateRecord, int*, 0x1C);
                    var_a0_2 = ownerRecord + 0xC;
                } else {
                    temp_a1_5 = Level30_82464Field(Level30_82464Field(privateRecord, void**, 0xC),
                                                   int*, 0xC);
                    Level30_82464_func_80013AE4(temp_a1_5 + 0x10, temp_a1_5);
                    var_a0_2 = ownerRecord + 0xC;
                }
                Level30_82464Field(privateRecord, int*, 0x2C) =
                    (int)(Level30_82464Field(privateRecord, int*, 0x2C) - 8);
                Level30_82464AddVector(var_a0_2, var_a0_2, privateRecord + 0x24);
                vectorRecord6 = Level30_82464Field(privateRecord, void**, 8);
                vectorBase7 = Level30_82464Field(vectorRecord6, int**, 0xC);
                if ((Level30_82464Field(ownerRecord, int*, 0x14) + 0x200) <
                    Level30_82464Field(vectorBase7, int*, 8)) {
                    ownerArgument4 = ownerRecord;
                    loadedWord2 = Level30_82464Field(vectorRecord6, short*, 0);
                    MATCHING_KEEP_CLOBBER(loadedWord2, "$5");
                    selectorArgument5 = 5;
                    loadedWord2 *= 16;
                    loadedWord2 += (int)vectorBase7;
                    loadedWord2 = Level30_82464Field(loadedWord2, int*, -8);
                    MATCHING_KEEP_CLOBBER(loadedWord2, "$3");
                    stateWord3 = 5;
                    Level30_82464Field(ownerRecord, unsigned char*, 0x48) = stateWord3;
                    MATCHING_KEEP_VOLATILE_CLOBBER(loadedWord2, "memory");
                    Level30_82464Field(ownerRecord, int*, 0x14) = loadedWord2 + 512;
                    Level30_82464RequestMobyAnimation(ownerArgument4, selectorArgument5,
                                                      vectorRecord6, vectorBase7);
                    Level30_82464_func_8003BB10(ownerRecord, 7, 1);
                    return;
                }
                break;
            case 5:
                if (Level30_82464_func_80055E84(ownerRecord) == 0x15) {
                    Level30_82464_func_8003BB10(ownerRecord, 6, 1);
                }
                if (Level30_82464_func_80055E84(ownerRecord) < 0x45) {
                    temp_a1_6 = Level30_82464Field(Level30_82464Field(privateRecord, void**, 0x10),
                                                   int*, 0xC);
                    Level30_82464_func_80013AE4(temp_a1_6 + 0x10, temp_a1_6);
                } else if (Level30_82464_func_80055E84(ownerRecord) == 0x45) {
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x48) = 0;
                    Level30_82464_func_80021ED8(5, 0xFC, 0);
                    Level30_82464RequestMobyAnimation(
                        Level30_82464_D_8006C550 +
                            (Level30_82464Field(privateRecord, int*, 4) * 0x58),
                        1);
                    Level30_82464Field(privateRecord, int*, 0x20) = 0x3C;
                    Level30_82464Field(ownerRecord, unsigned char*, 0x49) = 5U;
                    Level30_82464_func_8003BB10(ownerRecord, 5, 1);
                }
                if ((Level30_82464Field(ownerRecord, unsigned char*, 0x49) == 5) &&
                    (Level30_82464CountTimerDown(privateRecord + 0x20, 4) != 0)) {
                    Level30_82464_func_80013B7C(1);
                    goto terminalOwnerCall;
                }
                break;
            case 6:
                if (Level30_82464_D_8006E048 & 1) {
                    Level30_82464Field(((Level30_82464Field(privateRecord, int*, 0) * 0x58) +
                                        Level30_82464_D_8006C550),
                                       signed char*, 0x48) = 0;
                    if (Level30_82464Field(ownerRecord, unsigned char*, 0x49) == 4) {
                        Level30_82464_func_80021ED8(5, 0xFC, 0);
                    }
                    sharedAddress3 = &Level30_82464_D_8006D058;
                    MATCHING_KEEP(sharedAddress3);
                    if (*(int*)sharedAddress3 == 0) {
                        *(int*)sharedAddress3 = Level30_82464Field(privateRecord, int*, 0x1C);
                    }
                    goto terminalOwnerCall;
                }
                break;
        }
    }
    return;
terminalOwnerCall:
    Level30_82464DeleteMoby(ownerRecord);
}
#undef Level30_82464Field

void func_level_30_80082E74(Moby* moby) {
    moby->unknownCollision = 0;
    switch (moby->state) {
        case 0:
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            break;
        case 1:
            moby->colour.r = 0xFF;
            moby->colour.g = 0;
            moby->colour.b = 0;
            moby->colour.a = 0x38;
            break;
        case 2:
            moby->colour.g = 0xFF;
            moby->colour.r = 0;
            moby->colour.b = 0;
            moby->colour.a = 0x38;
            break;
    }
}
