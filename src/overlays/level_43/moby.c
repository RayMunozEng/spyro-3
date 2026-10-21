#include "matching.h"
#include "common.h"
#include "drawutil.h"
#include "savepoint.h"
#include "hud.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
extern int func_80039714(Moby*);

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
void func_level_43_8007584C(void* input) {
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
void func_level_43_800764A8(Moby* argument) {
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
void func_level_43_80076B34(void* input) {
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
void func_level_43_80078084(Moby* moby) {
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
void func_level_43_800781C0(Moby* moby) {
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
void func_level_43_80078480(Moby* argument) {
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
/* Existing Camera member at camera+0x28; no new storage definition. */
extern Vector3D Raw260CameraPosition __asm__("camera+40");
void func_level_43_800789A0(Moby* moby) {
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
void func_level_43_80078CA4(void* input) {
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
void func_level_43_80079818(Moby* moby) {
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
void func_level_43_80079C48(Moby* moby) {
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
void func_level_43_80079FB0(Moby* owner) {
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

extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_8007157E;
void func_level_43_8007A13C(Moby* moby) {
    SpeechProps* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->mobyClass == 0x2ad) {
                if (!D_8007157E)
                    tag->nextMsg = 0;
                else {
                    if (D_80070300[D_80066FCC[0x2e]] & 1)
                        tag->nextMsg = 2;
                    else
                        tag->nextMsg = 1;
                }
            }
            if (tag->nextMsg == 2)
                tag->autoTalk = 0;
            if (!tag->autoTalk) {
                if (D_8006E53C & 0x10) {
                    if (func_80037BBC(moby, 0))
                        goto start;
                    tag->talkable = 0;
                    /* Preserve the original store-before-load ordering. */
                    MATCHING_BARRIER_VOLATILE("memory");
                }
                if (!tag->autoTalk)
                    return;
            }
            if (func_80037BBC(moby, 0)) {
            start:
                func_800512E4(moby, 0, 0);
                moby->state = 1;
            } else
                tag->talkable = 0;
            break;
        case 1:
            if (D_8006E344 != 1) {
                *(int*)((char*)tag + 0x20) = 1;
                moby->state = 0;
            }
            break;
    }
}

/* Shared raw129 child offsets; raw947 adds a bounds gate and state-byte saves. */
extern Vector3D DecodedBoundsChildPlayer __asm__("D_80070328");
extern unsigned char DecodedBoundsChildHeading __asm__("D_80070328 + 0xE");
extern unsigned char* DecodedBoundsChildSoundDescriptor __asm__("D_8006C654");
extern unsigned char DecodedBoundsChildGlobalByte __asm__("D_80066BC8 + 16");
extern short DecodedBoundsChildGlobalHalf __asm__("D_800719DC");
extern short DecodedBoundsChildCos[] __asm__("D_80065920");
extern short DecodedBoundsChildSin[] __asm__("D_800658A0");
int DecodedBoundsChildBounds(Vector3D*, void*, int, int) __asm__("func_80036220");
void DecodedBoundsChildRelease(Moby*) __asm__("func_80055B18");
void func_level_43_8007A28C(Moby* moby) {
    void* tag = moby->mobyTag;
    Vector3D* player;
    unsigned char* stateAddress;
    Moby* child;
    int sine;
    if (!moby->state) {
        player = &DecodedBoundsChildPlayer;
        if (!DecodedBoundsChildBounds(player, tag, 0, 512))
            return;
        DecodedBoundsChildGlobalByte = 3;
        DecodedBoundsChildGlobalHalf = 1;
        PlaySound(DecodedBoundsChildSoundDescriptor[0x23], moby, 161);
        child = SpawnMoby(211, moby);
        if (child) {
            func_8004F178(&child->position, player);
            child->position.x += (DecodedBoundsChildCos[DecodedBoundsChildHeading] * 25) >> 7;
            MATCHING_BARRIER_VOLATILE("memory");
            sine = DecodedBoundsChildSin[DecodedBoundsChildHeading];
            child->position.z += 500;
            child->position.y += (sine * 25) >> 7;
        }
        moby->state = 1;
    } else {
        /* This pointer is produced on the nonzero-state route. */
        stateAddress = &moby->state;
        func_8003B7B4(stateAddress, 1, &savedData);
        func_8003B7B4(stateAddress, 1, &unsavedData);
        DecodedBoundsChildRelease(moby);
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
void func_level_43_8007A408(Moby* actor) {
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

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level43 8007A6B4 / level44 8007A6C0, 514 original instructions each.
 * Their original flag stores select D_8007158B / D_80071591 respectively.
 * Offset names identify storage, not decoded semantics. Helper contracts,
 * physical units and caller cadence remain unresolved. Preserve 32-bit
 * shift wrapping, signed /2048 truncation, byte/halfword widths, pointer
 * rereads and distinct selector branches. Empty constraints emit no CPU
 * instructions. Acceptance requires linked original words and all hashes.
 */
#define P7A6B4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int P7A6B4func_800135A4() __asm__("func_800135A4");
int P7A6B4func_8001A358() __asm__("func_8001A358");
int P7A6B4RequestMobyAnimation() __asm__("func_80034F40");
int P7A6B4TurnMobyTowardHeading() __asm__("func_8003585C");
int P7A6B4CountTimerDown() __asm__("func_800359A4");
int P7A6B4ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int P7A6B4func_80035DDC() __asm__("func_80035DDC");
int P7A6B4func_80037BBC() __asm__("func_80037BBC");
int P7A6B4func_8003B74C() __asm__("func_8003B74C");
int P7A6B4func_8003B7B4() __asm__("func_8003B7B4");
int P7A6B4TransformVectorByBasis() __asm__("func_8004ED6C");
int P7A6B4CopyVector() __asm__("func_8004F178");
int P7A6B4AddVector() __asm__("func_8004F194");
int P7A6B4func_8004F984() __asm__("func_8004F984");
int P7A6B4func_800512E4() __asm__("func_800512E4");
int P7A6B4func_80055E84() __asm__("func_80055E84");
int P7A6B4func_8005629C() __asm__("func_8005629C");
extern unsigned char P7A6B4D_800652B0[] __asm__("D_800652B0");
extern unsigned char P7A6B4D_800652B4[] __asm__("D_800652B4");
extern unsigned char P7A6B4D_800652B6[] __asm__("D_800652B6");
extern unsigned char P7A6B4D_800658A0[] __asm__("D_800658A0");
extern unsigned char P7A6B4D_80065920[] __asm__("D_80065920");
extern unsigned char P7A6B4D_80068F7C[] __asm__("D_80068F7C");
extern unsigned char P7A6B4D_80068F90[] __asm__("D_80068F90");
extern unsigned char P7A6B4D_8006C7F8[] __asm__("D_8006C7F8");
extern unsigned char P7A6B4D_8006D088[] __asm__("D_8006D088");
extern unsigned char P7A6B4D_80070328[] __asm__("D_80070328");
extern unsigned char P7A6B4D_800719A8[] __asm__("D_800719A8");
extern unsigned char P7A6B4D_800719F0[] __asm__("D_800719F0");
extern int P7A6B4D_8006C3F4 __asm__("D_8006C3F4");
extern int P7A6B4D_8006C4F8 __asm__("D_8006C4F8");
extern int P7A6B4D_8006C598 __asm__("D_8006C598");
extern int P7A6B4D_8006C640 __asm__("D_8006C640");
extern int P7A6B4D_8006C648 __asm__("D_8006C648");
extern int P7A6B4D_8006C6D0 __asm__("D_8006C6D0");
extern int P7A6B4D_8006C6E0 __asm__("D_8006C6E0");
extern int P7A6B4D_8006E044 __asm__("D_8006E044");
extern int P7A6B4D_8006E344 __asm__("D_8006E344");
extern int P7A6B4D_8006E538 __asm__("D_8006E538");
extern int P7A6B4D_8006E53C __asm__("D_8006E53C");
extern int P7A6B4D_800719BC __asm__("D_800719BC");
extern int P7A6B4D_800719C0 __asm__("D_800719C0");
extern int P7A6B4D_800719C4 __asm__("D_800719C4");
extern void* P7A6B4D_8006C65C __asm__("D_8006C65C");
extern unsigned char P7A6B4D_8007158B __asm__("D_8007158B");
extern void* (*P7A6B4SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7A6B4unk_ovlheader_80074318)() __asm__("unk_ovlheader_80074318");
extern int (*P7A6B4unk_ovlheader_80074320)() __asm__("unk_ovlheader_80074320");
extern int (*P7A6B4unk_ovlheader_8007432C)() __asm__("unk_ovlheader_8007432C");
void func_level_43_8007A6B4(void* owner) {
    struct {
        int sp18;
        int sp1C;
        int sp20;
        int pad24;
    } frame;
    register int* privateVector64 __asm__("$16");
    register int tableWord3 __asm__("$3");
    register void* tableArg4 __asm__("$4");
    register void* tableArg5 __asm__("$5");
    register void* callback17 __asm__("$17");
    int temp_a0;
    int temp_a0_4;
    register int helperSelector5 __asm__("$5");
    int wrappedShiftedWordB4;
    int quotientArgument;
    int var_v0;
    int var_v1;
    unsigned char temp_a0_2;
    unsigned char temp_a0_3;
    unsigned char ownerState;
    register int ownerSelector3D __asm__("$3");
    register int selector4 __asm__("$4");
    register int compare2 __asm__("$2");
    register int timerResult2 __asm__("$2");
    void* stateByteAddress;
    register void* savedStateByteAddress __asm__("$16");
    register void* playerVector30 __asm__("$17");
    void* privateState;
    void* linkedObject78;
    void* spawnedObject;

    P7A6B4Field(owner, unsigned char*, 0x4A) = 0xFF;
    privateState = P7A6B4Field(owner, void**, 0);
    if ((P7A6B4D_8006C640 > 0) && (P7A6B4Field(privateState, int*, 0x480) == 0)) {
        temp_a0 = P7A6B4D_8006C3F4 + P7A6B4Field(P7A6B4D_800652B0, int*, 0xB0);
        P7A6B4func_8004F984(temp_a0, temp_a0 + P7A6B4Field(P7A6B4D_800652B4, unsigned short*, 0xB0),
                            P7A6B4Field(P7A6B4D_800652B6, unsigned short*, 0xB0));
        P7A6B4Field(privateState, int*, 0x480) = 1;
    }
    ownerState = P7A6B4Field(owner, unsigned char*, 0x48);
    switch (ownerState) { /* irregular */
        case 0:
            if ((P7A6B4D_8006E344 == 0xD) && (P7A6B4Field(owner, unsigned char*, 0x49) == 0)) {
                if (P7A6B4D_8006C4F8 != 1) {
                    P7A6B4Field(owner, unsigned char*, 0x48) = 3U;
                    stateByteAddress = owner + 0x48;
                    P7A6B4func_8003B7B4(stateByteAddress, 1, P7A6B4D_8006D088);
                    P7A6B4func_8003B7B4(stateByteAddress, 1, P7A6B4D_8006C7F8);
                } else {
                    tableWord3 =
                        ((short*)P7A6B4D_80065920)[P7A6B4Field(owner, unsigned char*, 0x46)];
                    tableArg4 = &P7A6B4D_800719BC;
                    *(int*)tableArg4 = (tableWord3 * 13) >> 5;
                    tableArg5 = tableArg4;
                    tableWord3 =
                        ((short*)P7A6B4D_800658A0)[P7A6B4Field(owner, unsigned char*, 0x46)];
                    P7A6B4D_800719C4 = 0;
                    P7A6B4D_800719C0 = (tableWord3 * 13) >> 5;
                    P7A6B4AddVector(tableArg4, tableArg5, owner + 0xC);
                    P7A6B4D_8006C6E0 =
                        ((P7A6B4Field(owner, unsigned char*, 0x46) + 0x80) * 0x10) & 0xFFF;
                    goto initializeState0;
                }
            } else {
            initializeState0:
                P7A6B4Field(owner, short*, 0x38) = 0;
                P7A6B4Field(privateState, unsigned char*, 5) = 1;
                if ((P7A6B4D_8006C598 == 0) && (P7A6B4func_80037BBC(owner, 0) != 0)) {
                    P7A6B4func_800512E4(owner, 0, 0x12);
                    P7A6B4Field(owner, unsigned char*, 0x48) = 0x12U;
                }
            }
            break;
        case 18:
            if (P7A6B4D_8006E344 != 1) {
                P7A6B4Field(P7A6B4D_80070328, int*, 0x20C) = 0x10000002;
                P7A6B4D_8007158B = 1;
                P7A6B4Field(privateState, int*, 0x7C) = 0x3C;
                P7A6B4Field(owner, unsigned char*, 0x48) = 1U;
                P7A6B4RequestMobyAnimation(owner, 1);
            }
            break;
        case 1:
            P7A6B4Field(P7A6B4D_80070328, int*, 0x20C) = 0x10000002;
            if (P7A6B4TurnMobyTowardHeading(owner, P7A6B4Field(privateState, int*, 0x34) + 0x80, 8,
                                            0x10, (int)ownerState, 0) != 0) {
                P7A6B4func_80035DDC(owner, 0x80, 0, 0, 0);
            }
            timerResult2 = P7A6B4CountTimerDown(privateState + 0x7C, 4);
            MATCHING_KEEP2(owner, timerResult2);
            savedStateByteAddress = owner + 0x48;
            if (timerResult2 == 2) {
                P7A6B4Field(owner, unsigned char*, 0x48) = 3U;
                tableArg4 = savedStateByteAddress;
                helperSelector5 = 1;
                MATCHING_KEEP2(tableArg4, helperSelector5);
                callback17 = P7A6B4D_8006D088;
                P7A6B4func_8003B7B4(tableArg4, helperSelector5, callback17);
                P7A6B4func_8003B7B4(savedStateByteAddress, 1, P7A6B4D_8006C7F8);
                P7A6B4func_8003B74C(callback17);
                P7A6B4Field(owner, unsigned char*, 0x48) = 1U;
            }
            break;
        case 3:
            P7A6B4unk_ovlheader_80074318(owner, 0x73);
            P7A6B4D_8006C6D0 = 0;
            P7A6B4func_800135A4(P7A6B4D_800719A8, P7A6B4D_80068F7C, 0);
            P7A6B4func_800135A4(P7A6B4D_800719F0, P7A6B4D_80068F90, 0);
            if ((P7A6B4D_8006E044 == 0x1F) || (P7A6B4D_8006E044 == 0x28)) {
                P7A6B4Field(owner, unsigned char*, 0x4C) = 0;
                P7A6B4Field(owner, unsigned char*, 0x4D) = 0;
                if (P7A6B4D_8006C65C != 0) {
                    P7A6B4Field(P7A6B4D_8006C65C, unsigned char*, 0x4C) = 0;
                    P7A6B4Field(P7A6B4D_8006C65C, unsigned char*, 0x4D) = 0;
                }
            } else {
                P7A6B4Field(owner, unsigned char*, 0x4C) = 0x10;
                if (P7A6B4D_8006C65C != 0) {
                    P7A6B4Field(P7A6B4D_8006C65C, unsigned char*, 0x4C) = 0x10;
                }
            }
            if (P7A6B4Field(P7A6B4D_80070328, int*, 0x24C) == 4) {
                selector4 = P7A6B4Field(P7A6B4D_80070328, int*, 0x48);
                ownerSelector3D = P7A6B4Field(owner, unsigned char*, 0x3D);
                helperSelector5 = selector4 - 0x73;
                if (helperSelector5 != ownerSelector3D) {
                    if (selector4 == 0x83) {
                        selector4 = P7A6B4Field(owner, unsigned char*, 0x3C);
                        compare2 = 17;
                        if (selector4 == compare2)
                            goto selectorTwo13;
                        if (ownerSelector3D != compare2)
                            goto selectorOther13;
                    selectorTwo13:
                        selector4 = (int)owner;
                        MATCHING_OBSERVE(selector4);
                        helperSelector5 = 2;
                        goto callSelectorHelper;
                    selectorOther13:
                        compare2 = 2;
                        if (ownerSelector3D != compare2)
                            goto selectorSixteen13;
                        if (selector4 != ownerSelector3D)
                            goto clearPrivateWord48;
                        selector4 = (int)owner;
                        MATCHING_OBSERVE(selector4);
                        helperSelector5 = 16;
                        goto callSelectorHelper;
                    selectorSixteen13:
                        selector4 = (int)owner;
                        helperSelector5 = 16;
                        goto callSelectorHelper;
                    } else if (selector4 == 0x84) {
                        selector4 = P7A6B4Field(owner, unsigned char*, 0x3C);
                        compare2 = 16;
                        if (selector4 == compare2)
                            goto selectorTwo14;
                        if (ownerSelector3D != compare2)
                            goto selectorOther14;
                    selectorTwo14:
                        selector4 = (int)owner;
                        MATCHING_OBSERVE(selector4);
                        helperSelector5 = 2;
                        goto callSelectorHelper;
                    selectorOther14:
                        compare2 = 2;
                        helperSelector5 = 17;
                        if (ownerSelector3D != compare2)
                            goto selectorSeventeen14;
                        if (selector4 != ownerSelector3D)
                            goto clearPrivateWord48;
                        selector4 = (int)owner;
                        MATCHING_OBSERVE(selector4);
                        goto callSelectorHelper;
                    selectorSeventeen14:
                        selector4 = (int)owner;
                    } else {
                        selector4 = (int)owner;
                    }
                callSelectorHelper:
                    P7A6B4RequestMobyAnimation(selector4, helperSelector5);
                clearPrivateWord48:
                    P7A6B4Field(privateState, int*, 0x48) = 0;
                } else {
                    goto updateSelector1;
                }
            } else {
            updateSelector1:
                if (P7A6B4Field(owner, unsigned char*, 0x3D) == 1) {
                    if (P7A6B4Field(P7A6B4D_80070328, int*, 0xB4) != 0) {
                        wrappedShiftedWordB4 =
                            (int)((unsigned int)P7A6B4Field(P7A6B4D_80070328, int*, 0xB4) << 4);
                        quotientArgument = wrappedShiftedWordB4 / 2048;
                    } else {
                        quotientArgument = 8;
                    }
                    P7A6B4unk_ovlheader_80074320(owner, quotientArgument, privateState + 0x48);
                }
            }
            if (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) == 0x81) {
                var_v1 = P7A6B4Field(P7A6B4D_80070328, int*, 0xF4);
                if (var_v1 != 0) {
                    var_v0 = 0xFFFFFF;
                } else {
                    P7A6B4CopyVector(&frame.sp18, owner + 0xC);
                    frame.sp20 += 0x400;
                    var_v0 = P7A6B4func_8001A358(&frame.sp18, 0x800);
                    var_v1 = 0xFFFFFF;
                    frame.sp20 = var_v0;
                }
                P7A6B4Field(owner, int*, 0x54) = (int)((var_v0 & var_v1) | 0x80000000);
            } else {
                P7A6B4Field(owner, int*, 0x54) = 0;
            }
            if ((P7A6B4CountTimerDown(privateState + 0x4C, 4) != 0) && (P7A6B4D_8006E538 & 0x20) &&
                ((P7A6B4D_8006E044 == 0x1F) ||
                 ((P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x7E) &&
                  (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x79) &&
                  (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x80) &&
                  ((unsigned int)(P7A6B4Field(P7A6B4D_80070328, int*, 0x48) - 0x7A) >= 2U) &&
                  (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x7C) &&
                  (P7A6B4Field(P7A6B4D_80070328, int*, 0x240) == 0))) &&
                (P7A6B4SpawnMoby(0xC5, owner) != 0)) {
                P7A6B4Field(privateState, int*, 0x4C) = 0x19;
            }
            linkedObject78 = P7A6B4Field(privateState, void**, 0x78);
            if (linkedObject78 != 0) {
                if (P7A6B4Field(linkedObject78, unsigned char*, 0x48) != 0) {
                    P7A6B4Field(privateState, void**, 0x78) = 0;
                    P7A6B4Field(privateState, int*, 0x7C) = 0x3C;
                } else {
                    temp_a0_4 = P7A6B4Field(privateState, int*, 0x7C);
                    if (temp_a0_4 != 0) {
                        if (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) == 0x82) {
                            if (P7A6B4func_80055E84(owner) >= 7) {
                                if (P7A6B4Field(privateState, short*, 0x74) == 0x22A) {
                                    P7A6B4Field(P7A6B4Field(privateState, void**, 0x78),
                                                unsigned char*, 0x48) = 0x50U;
                                } else {
                                    P7A6B4Field(P7A6B4Field(privateState, void**, 0x78),
                                                unsigned char*, 0x48) = 1U;
                                }
                            }
                        } else {
                            P7A6B4Field(privateState, int*, 0x7C) =
                                (int)(temp_a0_4 + P7A6B4D_8006C648);
                        }
                    } else if (P7A6B4D_8006E53C & 0x80) {
                        privateVector64 = privateState + 0x64;
                        if (P7A6B4D_8006E344 == 0) {
                            playerVector30 = P7A6B4D_80070328 + 0x30;
                            P7A6B4Field(privateState, int*, 0x5C) = 0x180;
                            P7A6B4Field(privateState, int*, 0x64) = 0x1800;
                            P7A6B4Field(privateState, int*, 0x68) = 0;
                            P7A6B4Field(privateState, int*, 0x6C) = 0;
                            P7A6B4TransformVectorByBasis(playerVector30, privateVector64,
                                                         privateVector64);
                            P7A6B4AddVector(privateVector64, privateVector64,
                                            playerVector30 - 0x30);
                            P7A6B4unk_ovlheader_8007432C(
                                P7A6B4Field(P7A6B4D_80070328, int*, 0x250));
                            P7A6B4Field(privateState, int*, 0x7C) =
                                (int)(P7A6B4Field(privateState, int*, 0x7C) + P7A6B4D_8006C648);
                        }
                    }
                }
            } else if ((P7A6B4Field(privateState, short*, 0x76) != 0) &&
                       (P7A6B4CountTimerDown(privateState + 0x7C, 4) != 0) &&
                       (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x79) &&
                       (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x82) &&
                       (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x80) &&
                       (P7A6B4Field(P7A6B4D_80070328, int*, 0x48) != 0x7C)) {
                spawnedObject = P7A6B4SpawnMoby(P7A6B4Field(privateState, short*, 0x74), owner);
                P7A6B4Field(privateState, void**, 0x78) = spawnedObject;
                if (spawnedObject != 0) {
                    P7A6B4Field(privateState, int*, 0x7C) = 0;
                    P7A6B4Field(privateState, short*, 0x76) =
                        (short)((unsigned short)P7A6B4Field(privateState, short*, 0x76) - 1);
                }
            }
            break;
    }
    P7A6B4ProbeGroundFromRaisedMoby(owner);
    P7A6B4func_8005629C(owner);
}

#undef P7A6B4Field


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
void func_level_43_8007AEBC(Moby* input) {
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

extern unsigned char D_80066FCC[], D_80070300[];
void func_80021ED8(void*, int, int);
void func_80055B18(Moby*);
void func_level_43_8007B2C8(Moby* moby) {
    int* tag = moby->mobyTag;
    if (D_80070300[D_80066FCC[tag[0]]] & 1) {
        func_80021ED8((void*)tag[1], 0xFC, 0);
    }
    func_80055B18(moby);
}

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
void func_level_43_8007B334(void* input) {
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
                    if (Controller821F8Field(tag, short*, 0) == 0) {
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

void func_level_43_8007C4C0(Moby* moby) {
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
void func_level_43_8007C4E0(Moby* argument) {
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

/* SCUS-94467 USA Rev 0: original instructions at 0x8007D730.
 * Signed halfword motion and timers; angles consume the low unsigned byte.
 * One update per invocation; caller cadence and particle semantics unresolved.
 * Empty asm constraints emit no instructions and preserve retail scheduling.
 */
typedef struct {
    short velocityX, velocityY, velocityZ;
    short rollDelta, pitchDelta, yawDelta;
    short lifetime, reserved0E;
    int reserved10;
    short bounceCount, particleTimer;
} DecodedBounceTag;
extern int DecodedBounceFloor __asm__("D_80071908");
int DecodedBounceContact(Vector3D*, int, int, Moby*) __asm__("func_8001A310");
int DecodedBounceFragments(Moby*) __asm__("func_80039714");
int DecodedBounceRandom(int, int) __asm__("func_8003636C");
int DecodedBounceCountdown(void*, int) __asm__("func_800359A4");
void DecodedBounceDelete(Moby*) __asm__("func_80055B18");
void func_level_43_8007C6E0(Moby* argument) {
    Vector3D velocity;
    int reserved1C;
    Vector3D position;
    int reserved2C;
    register Moby* moby __asm__("$16") = argument;
    register DecodedBounceTag* tag __asm__("$17") = moby->mobyTag;
    register unsigned char* particle __asm__("$3");
    int index;
    if (!moby->state && DecodedBounceContact(&moby->position, 150, 3, moby)) {
        if (tag->bounceCount < 3) {
            register int coefficient __asm__("$3") = 3 - tag->bounceCount;
            MATCHING_KEEP(coefficient);
            {
                register int vertical __asm__("$2") = coefficient * 50;
                tag->velocityZ = vertical;
            }
            {
                register unsigned int count __asm__("$3") = (unsigned short)tag->bounceCount;
                count++;
                MATCHING_KEEP(count);
                tag->bounceCount = count;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            {
                register int floor __asm__("$2") = DecodedBounceFloor;
                moby->position.z = floor + 155;
            }
            tag->velocityX = tag->velocityX * 2 / 3;
            tag->velocityY = tag->velocityY * 2 / 3;
            tag->lifetime = 150;
        } else {
            moby->state = 1;
            moby->position.z = DecodedBounceFloor;
            tag->lifetime = 100;
        }
    }
    switch (moby->state) {
        case 3:
            if (DecodedBounceFragments(moby)) {
                for (index = 0; index < 3; index++) {
                    {
                        int sample = DecodedBounceRandom(0, 2048);
                        register int coordinate __asm__("$3") = moby->position.x - 1024;
                        MATCHING_KEEP(coordinate);
                        coordinate += sample;
                        MATCHING_KEEP(coordinate);
                        position.x = coordinate;
                    }
                    {
                        int sample = DecodedBounceRandom(0, 2048);
                        register int coordinate __asm__("$3") = moby->position.y - 1024;
                        MATCHING_KEEP(coordinate);
                        coordinate += sample;
                        MATCHING_KEEP(coordinate);
                        position.y = coordinate;
                    }
                    {
                        int sample = DecodedBounceRandom(0, 2048);
                        int coordinate;
                        register char* (*spawn)(int, int, Vector3D*, Vector3D*)__asm__("$3");
                        register int kind __asm__("$4") = 1;
                        register int selector __asm__("$5") = 1;
                        register Vector3D* positionArgument __asm__("$6") = &position;
                        register Vector3D* velocityArgument __asm__("$7");
                        MATCHING_OBSERVE3(kind, selector, positionArgument);
                        coordinate = moby->position.z;
                        velocity.z = -30;
                        MATCHING_BARRIER_VOLATILE("memory");
                        spawn = SpawnParticle;
                        MATCHING_OBSERVE_CLOBBER(spawn, "$7");
                        velocityArgument = &velocity;
                        MATCHING_OBSERVE2(spawn, velocityArgument);
                        velocity.x = 0;
                        velocity.y = 0;
                        coordinate -= 1024;
                        coordinate += sample;
                        MATCHING_KEEP(coordinate);
                        position.z = coordinate;
                        particle = spawn(kind, selector, positionArgument, velocityArgument);
                    }
                    MATCHING_KEEP(particle);
                    if (particle) {
                        particle[10] = 180;
                    }
                }
            }
            break;
        case 2:
            DecodedBounceFragments(moby);
            break;
        case 0:
            velocity.x = 0;
            velocity.y = 0;
            velocity.z = 30;
            SpawnParticle(1, 1, &moby->position, &velocity);
            moby->position.x += tag->velocityX;
            moby->position.y += tag->velocityY;
            tag->velocityZ -= 10;
            if (tag->velocityZ < -200) {
                tag->velocityZ = -200;
            }
            moby->position.z += tag->velocityZ;
            moby->angle.roll += *(unsigned char*)&tag->rollDelta;
            moby->angle.pitch += *(unsigned char*)&tag->pitchDelta;
            moby->angle.yaw += *(unsigned char*)&tag->yawDelta;
            if (DecodedBounceCountdown(&tag->lifetime, 2)) {
                DecodedBounceDelete(moby);
            }
            break;
        case 1:
            if (!tag->particleTimer) {
                velocity.x = DecodedBounceRandom(0, 20) - 10;
                velocity.y = DecodedBounceRandom(0, 20) - 10;
                velocity.z = 20;
                moby->position.z += 50;
                {
                    unsigned char* result = SpawnParticle(1, 0, &moby->position, &velocity);
                    register int restoredZ __asm__("$3") = moby->position.z;
                    MATCHING_KEEP(restoredZ);
                    restoredZ -= 50;
                    moby->position.z = restoredZ;
                    MATCHING_OBSERVE(restoredZ);
                    particle = result;
                    MATCHING_KEEP(particle);
                }
                if (particle) {
                    particle[10] = 50;
                }
                tag->particleTimer = 5;
            } else {
                DecodedBounceCountdown(&tag->particleTimer, 2);
            }
            if (DecodedBounceCountdown(&tag->lifetime, 2)) {
                DecodedBounceDelete(moby);
            }
            break;
    }
}

#define ControllerCA7CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* ControllerCA7CLinked0 __asm__("D_80070328 + 0x250");
extern void* ControllerCA7CLinked1 __asm__("D_80070328 + 0x250");
extern void* ControllerCA7CLinked2 __asm__("D_80070328 + 0x250");
extern unsigned char ControllerCA7CPlayer[] __asm__("D_80070328");
extern int ControllerCA7CMobyBase __asm__("D_8006C550");
extern int D_80071908;
extern Vector3D ControllerCA7CCollision __asm__("D_80071900");
int ControllerCA7CHelper18368(void*, void*) __asm__("func_80018368");
void* ControllerCA7CHelper1AD60(void*, void*, int, int, void*) __asm__("func_8001AD60");
int ControllerCA7CHelper1C288(void*, int, int) __asm__("func_8001C288");
int ControllerCA7CCountTimerDown(void*, int) __asm__("func_800359A4");
int ControllerCA7CProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
int ControllerCA7CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int ControllerCA7CPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int ControllerCA7CTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int ControllerCA7CMeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int ControllerCA7CScaleVectorRatioQ15(void*, int, int) __asm__("func_8004F08C");
int ControllerCA7CCopyVector(void*, void*) __asm__("func_8004F178");
int ControllerCA7CAddVector(void*, void*, void*) __asm__("func_8004F194");
int ControllerCA7CApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int ControllerCA7CDeleteMoby(void*) __asm__("func_80055B18");
int ControllerCA7CRefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int ControllerCA7CInterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level43/moby/8007CA7C and level46/moby/8007C630.
 * Both285 original instructions, global/helper symbols and six owned table/pad
 * words checked separately. Five dispatch entries retain state0/end and state1
 * fallthrough2. Original vector atsp18, fifth call argument atsp10 retained.
 * Exact signed decrements/clamps(-512/-400), thresholds and88-byte record stride
 * retained. Original helper rereads, player-pointer phases and separate calls
 * are preserved; no inferred runtime producer semantics are claimed.
 * Numeric units, fixed-point interpretation, helper contracts and caller cadence
 * remain open; once per invocation. Confidence: exact native/linked words.
 * Falsifiable vectors: every original word and complete retail EXE/overlay SHAs.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_43_8007CA7C(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    register int* player __asm__("$16");
    register void* preparedPosition __asm__("$4");
    register void* preparedPlayer __asm__("$5");
    Vector3D previous;
    register int terminalWord __asm__("$16");
    register int selectedWord __asm__("$2");
    int* destination;
    register int* position __asm__("$16");
    register int* tag __asm__("$18");
    int nextWord;
    int nextWord3;
    int helperResult;
    register int belowBound __asm__("$2");
    unsigned char index1;
    unsigned char state;
    unsigned char index0;
    register unsigned char* privateRecord __asm__("$16");
    register unsigned char* linkedRecord __asm__("$18");
    register unsigned char* other __asm__("$18");

    state = ControllerCA7CField(owner, unsigned char*, 0x48);
    tag = ControllerCA7CField(owner, int**, 0);
    switch (state) {
        case 0:
            goto finished;
        case 1: {
            register void* linked __asm__("$2") = ControllerCA7CLinked0;
            register int angle __asm__("$3") = ControllerCA7CField(linked, unsigned char*, 0x44);
            privateRecord = ControllerCA7CField(linked, void**, 0);
            ControllerCA7CField(owner, unsigned char*, 0x44) = angle;
            ControllerCA7CField(owner, unsigned char*, 0x45) =
                ControllerCA7CField(privateRecord, int*, 0x5C) >> 4;
            linked = ControllerCA7CLinked1;
            {
                register int yaw __asm__("$2") = ControllerCA7CField(linked, unsigned char*, 0x46);
                register int one __asm__("$5");
                MATCHING_KEEP_CLOBBER(yaw, "$5");
                one = 1;
                MATCHING_KEEP2(yaw, one);
                ControllerCA7CField(owner, unsigned char*, 0x46) = yaw;
                ControllerCA7CInterpolateMobyVertex(ControllerCA7CLinked2, one, owner + 0xC);
            }
        }
            ControllerCA7CRefreshMobySpatialGridAndBasis(owner, 4);
            {
                register void* first __asm__("$4") = owner + 0x20;
                register int* second __asm__("$5") = tag;
                register int word __asm__("$2") = ControllerCA7CField(privateRecord, int*, 0x60);
                register int* third __asm__("$6");
                MATCHING_KEEP_CLOBBER(word, "$6");
                third = tag;
                MATCHING_KEEP4(first, second, word, third);
                ControllerCA7CField(tag, int*, 4) = 0;
                ControllerCA7CField(tag, int*, 8) = 0;
                ControllerCA7CField(tag, int*, 0) = word;
                ControllerCA7CTransformVectorByBasis(first, second, third);
            }
            ControllerCA7CField(tag, int*, 0xC) = 0xB4;
            ControllerCA7CField(owner, unsigned char*, 0x48) = 2U;
            /* fallthrough */
        case 2:
            if ((ControllerCA7CField(owner, int*, 0xC) >= 0x400) &&
                (ControllerCA7CField(owner, int*, 0x10) >= 0x400) &&
                (ControllerCA7CField(owner, int*, 0x14) >= 0x400) &&
                (ControllerCA7CCountTimerDown((int*)((unsigned char*)tag + 0xC), 4) == 0)) {
                {
                    register void* prepared __asm__("$4") = &previous;
                    MATCHING_KEEP_CLOBBER(prepared, "$16");
                    position = (int*)(owner + 0xC);
                    ControllerCA7CCopyVector(prepared, position);
                }
                ControllerCA7CAddVector(position, position, tag);
                ControllerCA7CField(owner, unsigned char*, 0x45) =
                    ControllerCA7CPlanarHeadingLookup(
                        ControllerCA7CApproximatePlanarDistance(position, &previous),
                        ControllerCA7CField(owner, int*, 0x14) - previous.z, 0);
                nextWord = ControllerCA7CField(tag, int*, 8) - 8;
                ControllerCA7CField(tag, int*, 8) = nextWord;
                if (nextWord < -0x200) {
                    ControllerCA7CField(tag, int*, 8) = -0x200;
                }
                ControllerCA7CRefreshMobySpatialGridAndBasis(owner, 6);
                if (ControllerCA7CHelper18368(&previous, position) != 0) {
                    ControllerCA7CCopyVector(position, &ControllerCA7CCollision);
                    preparedPosition = position;
                    MATCHING_KEEP_CLOBBER(preparedPosition, "$16");
                    player = (int*)ControllerCA7CPlayer;
                    preparedPlayer = player;
                    goto sharedDistance;
                }
                other = ControllerCA7CHelper1AD60(&previous, position, 0, 0, owner);
                if (!other)
                    goto finished;
                if (ControllerCA7CHelper18368(position, other + 0xC))
                    goto finished;
                preparedPosition = position;
                MATCHING_KEEP_CLOBBER(preparedPosition, "$16");
                player = (int*)ControllerCA7CPlayer;
                preparedPlayer = player;
                ControllerCA7CField(other, int*, 0x18) |= 0x10000;
            sharedDistance:
                {
                    register int first __asm__("$4") =
                        ControllerCA7CApproximatePlanarDistance(preparedPosition, preparedPlayer);
                    register int third __asm__("$6") = 0;
                    register int second __asm__("$5") = ControllerCA7CField(owner, int*, 0x14);
                    register int word __asm__("$2") =
                        ControllerCA7CField(ControllerCA7CPlayer, int*, 8);
                    second -= 200;
                    MATCHING_KEEP2(second, word);
                    second = word - second;
                    ControllerCA7CField(owner, unsigned char*, 0x44) =
                        64 - ControllerCA7CPlanarHeadingLookup(first, second, third);
                }
                ControllerCA7CField(owner, unsigned char*, 0x46) =
                    ControllerCA7CPlanarHeadingLookup(
                        player[0] - ControllerCA7CField(owner, int*, 0xC),
                        ControllerCA7CField(ControllerCA7CPlayer, int*, 4) -
                            ControllerCA7CField(owner, int*, 0x10),
                        0);
                ControllerCA7CPlayMobySoundEvent(owner, 1, 0);
                SpawnMoby(0x3ED, owner);
            }
        removeOwner:
            ControllerCA7CDeleteMoby(owner);
            return;
        case 3:
            index0 = ControllerCA7CField(owner, unsigned char*, 0x3A);
            if (index0 != 0xFF) {
                {
                    register int offset __asm__("$2") = index0 * 11;
                    register int address __asm__("$3") = ControllerCA7CMobyBase;
                    register int one __asm__("$2");
                    MATCHING_KEEP2(offset, address);
                    offset *= 8;
                    address += offset;
                    one = 1;
                    MATCHING_KEEP2(address, one);
                    ControllerCA7CField(address, unsigned char*, 0x49) = one;
                }
            }
            destination = (int*)(owner + 0xC);
            ControllerCA7CAddVector(destination, tag, destination);
            nextWord3 = ControllerCA7CField(tag, int*, 8) - 8;
            ControllerCA7CField(tag, int*, 8) = nextWord3;
            if (nextWord3 < -0x190) {
                ControllerCA7CField(tag, int*, 8) = -0x190;
            }
            helperResult = ControllerCA7CProbeGroundFromRaisedMoby(owner);
            if ((helperResult != 0) &&
                ((ControllerCA7CField(owner, int*, 0x14) - helperResult) < 0x50)) {
                ControllerCA7CPlayMobySoundEvent(owner, 0, 0);
                if (ControllerCA7CField(tag, int*, 0x10) == 0) {
                    ControllerCA7CPlayMobySoundEvent(owner, 0, 0);
                    ControllerCA7CScaleVectorRatioQ15(
                        tag, ControllerCA7CMeasureVectorLength(tag, 1), 0x28);
                    ControllerCA7CField(owner, int*, 0x14) = (int)(D_80071908 + 0x40);
                    ControllerCA7CField(tag, int*, 8) = 0x32;
                    ControllerCA7CField(tag, int*, 0x10) = 1;
                    return;
                }
                {
                    register int state __asm__("$3") = 4;
                    register int height __asm__("$2") = D_80071908;
                    MATCHING_KEEP_VOLATILE_CLOBBER(state, "memory");
                    ControllerCA7CField(owner, unsigned char*, 0x48) = state;
                    ControllerCA7CField(owner, int*, 0x14) = height + 64;
                }
                return;
            }
            break;
        case 4: {
            register int sentinel __asm__("$3") = 255;
            register void* linked __asm__("$2");
            register int index __asm__("$4");
            __asm__("" : "=r"(sentinel) : "0"(sentinel) : "$2", "$4", "$18");
            linked = ControllerCA7CLinked0;
            index = ControllerCA7CField(owner, unsigned char*, 0x3A);
            linkedRecord = ControllerCA7CField(linked, void**, 0);
            MATCHING_KEEP3(sentinel, index, linkedRecord);
            if (index != sentinel) {
                register int offset __asm__("$2") = index * 11;
                register int address __asm__("$3") = ControllerCA7CMobyBase;
                register int one __asm__("$2");
                MATCHING_KEEP2(offset, address);
                offset *= 8;
                address += offset;
                one = 1;
                MATCHING_KEEP2(address, one);
                ControllerCA7CField(address, unsigned char*, 0x49) = one;
            }
        }
            {
                register int flags __asm__("$2") = ControllerCA7CField(linkedRecord, int*, 0x78);
                terminalWord = ControllerCA7CField(linkedRecord, short*, 0x76);
                if (flags != 0) {
                    terminalWord += 1;
                }
            }
            belowBound = terminalWord < 10;
            if ((belowBound != 0) && (ControllerCA7CHelper1C288(owner + 0xC, 0x200, 0) != 0)) {
                ControllerCA7CDeleteMoby(owner);
                ControllerCA7CField(linkedRecord, int*, 0x7C) = 0;
                if (terminalWord == 0) {
                    selectedWord = 0xA;
                } else {
                    MATCHING_BARRIER_VOLATILE("$2");
                    selectedWord = 9;
                }
                ControllerCA7CField(linkedRecord, short*, 0x76) = selectedWord;
                ControllerCA7CField(linkedRecord, short*, 0x74) = 0x66;
            }
            break;
    }
finished:;
}
#undef ControllerCA7CField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original43 8007CEF0.
* Assembly SHA256 48156a88fbee719961f766819f053064757d842efb46032120dc34e57a9b132a.
* AI generated; not human reviewed. Exactly1064 native instruction words
* plus eight selector words=1072 owned words. Every actual conditional,
* internal-J/JAL/JALR register, selector offset, data symbol/addend and full
* linked retail EXE/every-overlay hash is required. No extra packed data.
* Verified1031 actor sibling supplies the common source: this original
* adds late class exclusions0x1DE/0x1EE, changes the two absolute-angle
* limits to16/32 while retaining score*8, and adds a300-radius, mode2
* 1BA30 target query before existing callbacks. Its target receives byte51
* and flags18|0x10000; a fresh class197 child uses the existing initialized
* child-store sequence. Ordinary C tail merging reproduces the original
* shared initialization destination without an opcode or manual jump.
* Later query targets use S2; child pointers and earlier records retain
* their original separate S0 roles. An identity of the complete initialized
* null query result ends its known-zero phase before later literalZERO
* callback words. All physical GP roles have disjoint live ranges.
* Original A0hex frame saves S0..S7/FP/RA; locals occupy SP18..77. Both
* MULT sites initialize complete signed64 products. First x-input/l-output
* captures its complete producer's low32 signed word; the next signed64
* multiply consumes that signed low32 and0x1B4E81B5, then x-input/h-output
* captures the initialized high word before >>6 and signed correction.
* No partial HI/LO input, CPU opcode asm, fixed FP, unwritten local,
* undefined incoming saved value or overlapping live fixed aliases.
* Existing known helper returns/word ABI and typed359A4/4E880 calls persist;
* vector copy/add/subtract views have known void returns and retain the
* original extra argument words when the old-style view is necessary.
* Native identity confirms these raw arithmetic, field widths, addresses
* and control words. Physical units/fixed point beyond the words, helper
* caller chains, cadence, Rev1 mapping, human review and synchronized retail
* captures remain unresolved. Compiler, filters and flags are unchanged.
*/
void* Level43_7CEF0Call1BA30(void*, int, int, int, int, void*) __asm__("func_8001BA30");
#define Level43_7CEF0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level43_7CEF0Call13E38() __asm__("func_80013E38");
int Level43_7CEF0Call1830C() __asm__("func_8001830C");
int Level43_7CEF0Call19138() __asm__("func_80019138");
void* Level43_7CEF0Call1AD60() __asm__("func_8001AD60");
int Level43_7CEF0Call1C288() __asm__("func_8001C288");
int Level43_7CEF0SetMobyAnimation() __asm__("func_80034F80");
int Level43_7CEF0TurnMobyTowardPlayer() __asm__("func_8003573C");
int Level43_7CEF0CountTimerDown(void*, int) __asm__("func_800359A4");
int Level43_7CEF0RandBetween() __asm__("func_8003636C");
int Level43_7CEF0PlayMobySoundEvent() __asm__("func_8003BABC");
int Level43_7CEF0Call40954() __asm__("func_80040954");
int Level43_7CEF0PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Level43_7CEF0TransformVectorByBasis() __asm__("func_8004ED6C");
int Level43_7CEF0MeasureVectorLength() __asm__("func_8004EDE8");
int Level43_7CEF0Call4EF74() __asm__("func_8004EF74");
int Level43_7CEF0ScaleVectorRatioQ15() __asm__("func_8004F08C");
void Level43_7CEF0CopyVector() __asm__("func_8004F178");
void Level43_7CEF0AddVector() __asm__("func_8004F194");
void Level43_7CEF0SubtractVector() __asm__("func_8004F1C8");
int Level43_7CEF0ApproximatePlanarDistance() __asm__("func_8004F334");
int Level43_7CEF0DeleteMoby() __asm__("func_80055B18");
int Level43_7CEF0RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level43_7CEF0Datarand(void) __asm__("rand");
extern int Level43_7CEF0Data658A0 __asm__("D_800658A0");
extern int Level43_7CEF0Data65920 __asm__("D_80065920");
extern int Level43_7CEF0Data6C550 __asm__("D_8006C550");
extern int Level43_7CEF0Data6D048 __asm__("D_8006D048");
extern int Level43_7CEF0Data6E020 __asm__("D_8006E020");
extern int Level43_7CEF0Data6E024 __asm__("D_8006E024");
extern int Level43_7CEF0Data6E028 __asm__("D_8006E028");
extern unsigned short Level43_7CEF0Data6E03E __asm__("D_8006E03E");
extern unsigned short Level43_7CEF0Data6E040 __asm__("D_8006E040");
extern void* Level43_7CEF0Data6E788 __asm__("D_8006E788");
extern int Level43_7CEF0Data70328 __asm__("D_80070328");
extern int Level43_7CEF0Data71900 __asm__("D_80071900");
extern int Level43_7CEF0Data71918 __asm__("D_80071918");
extern int Level43_7CEF0Data71924 __asm__("D_80071924");
extern void* (*Level43_7CEF0DataSpawnMoby)() __asm__("SpawnMoby");
extern void* (*Level43_7CEF0DataSpawnParticle)() __asm__("SpawnParticle");
extern int (*Level43_7CEF0Data74424)() __asm__("unk_ovlheader_80074424");
extern void* (*Level43_7CEF0Data74428)() __asm__("unk_ovlheader_80074428");
void func_level_43_8007CEF0(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int retainedAngleOrRecord16 __asm__("$16"), retainedRecordOrVector17 __asm__("$17"),
        retainedAngleOrAddress18 __asm__("$18"), retainedRecordOrDataAddress20 __asm__("$20"),
        privateRecord21 __asm__("$21"), retainedSearchPosition22 __asm__("$22"),
        retainedSelectedRecord23 __asm__("$23");
    register int rangeBoundOrProductHigh10 __asm__("$10");
    register int rawWord2 __asm__("$2"), rawWord3, argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        nearestDifference8 __asm__("$8"), directionSign9 __asm__("$9");
    int retainedMinimumScoreOrDataAddress;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74;
    } originalFrame;
    void* temp_a0_2;
    void* temp_a0_3;
    void* temp_a0_4;
    void* temp_a0_5;
    void* temp_a0_6;
    void* temp_a0_7;
    void* temp_v0_12;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    privateRecord21 = (int)Level43_7CEF0Field(ownerRecord19, void**, 0);
    Level43_7CEF0RefreshMobySpatialGridAndBasis(ownerParameter, 6);
    rawWord3 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48);
    retainedSearchPosition22 = 0;
    switch (rawWord3) {
        case 5:
            retainedMinimumScoreOrDataAddress = 0x1869F;
            retainedSelectedRecord23 = 0;
            retainedRecordOrDataAddress20 = (int)&Level43_7CEF0Data6E788;
            retainedRecordOrVector17 = Level43_7CEF0Field(retainedRecordOrDataAddress20, int*, 0);
            retainedRecordOrDataAddress20 += 4;
            if (retainedRecordOrVector17 != 0) {
                retainedSearchPosition22 = ownerRecord19 + 0xC;
                do {
                    if ((Level43_7CEF0Field(retainedRecordOrVector17, short*, 0x36) != 0x63) &&
                        !(Level43_7CEF0Field(retainedRecordOrVector17, unsigned char*, 0x48) &
                          0x80) &&
                        (Level43_7CEF0Field(retainedRecordOrVector17, int*, 8) != 0) &&
                        (Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x4D) != 0) &&
                        (Level43_7CEF0Field(retainedRecordOrVector17, short*, 0x36) != 0x1DE) &&
                        (Level43_7CEF0Field(retainedRecordOrVector17, short*, 0x36) != 0x1EE)) {
                        rangeBoundOrProductHigh10 = 0x8000;
                        __asm__(""
                                : "=r"(rangeBoundOrProductHigh10)
                                : "0"(rangeBoundOrProductHigh10)
                                : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9");
                        rawWord3 = Level43_7CEF0Field(retainedRecordOrVector17, int*, 0xC);
                        rawWord2 = Level43_7CEF0Field(ownerRecord19, int*, 0xC);
                        argumentWord4 = rawWord3 - rawWord2;
                        rawWord2 = argumentWord4;
                        if (argumentWord4 < 0) {
                            MATCHING_KEEP(rawWord2);
                            rawWord2 = -rawWord2;
                        }
                        if (rawWord2 <= rangeBoundOrProductHigh10) {
                            rawWord3 = Level43_7CEF0Field(retainedRecordOrVector17, int*, 0x10);
                            rawWord2 = Level43_7CEF0Field(ownerRecord19, int*, 0x10);
                            argumentWord5 = rawWord3 - rawWord2;
                            rawWord2 = argumentWord5;
                            if (argumentWord5 < 0) {
                                MATCHING_KEEP(rawWord2);
                                rawWord2 = -rawWord2;
                            }
                            if (rawWord2 <= rangeBoundOrProductHigh10) {
                                retainedAngleOrRecord16 =
                                    (Level43_7CEF0PlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                      0) -
                                     Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46)) &
                                    0xFF;
                                __asm__(""
                                        : "=r"(retainedSearchPosition22)
                                        : "0"(retainedSearchPosition22),
                                          "r"(retainedAngleOrRecord16));
                                argumentWord4 = retainedSearchPosition22;
                                if (retainedAngleOrRecord16 >= 0x81) {
                                    retainedAngleOrRecord16 -= 0x100;
                                }
                                MATCHING_BARRIER_GNU_VOLATILE("$18");
                                retainedAngleOrAddress18 = retainedRecordOrVector17 + 0xC;
                                rawWord3 =
                                    (Level43_7CEF0PlanarHeadingLookup(
                                         Level43_7CEF0ApproximatePlanarDistance(
                                             argumentWord4, retainedAngleOrAddress18),
                                         Level43_7CEF0Field(retainedRecordOrVector17, int*, 0x14) -
                                             Level43_7CEF0Field(ownerRecord19, int*, 0x14),
                                         0) -
                                     Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45)) &
                                    0xFF;
                                if (rawWord3 >= 0x81) {
                                    rawWord3 -= 0x100;
                                }
                                if (retainedAngleOrRecord16 < 0) {
                                    retainedAngleOrRecord16 = -retainedAngleOrRecord16;
                                }
                                if (rawWord3 < 0) {
                                    MATCHING_KEEP(rawWord3);
                                    rawWord3 = -rawWord3;
                                }
                                __asm__(""
                                        : "=r"(retainedAngleOrRecord16)
                                        : "0"(retainedAngleOrRecord16), "r"(rawWord3));
                                if ((retainedAngleOrRecord16 < 16) && (rawWord3 < 32)) {
                                    retainedAngleOrRecord16 =
                                        (retainedAngleOrRecord16 * 8) + rawWord3;
                                    MATCHING_KEEP(retainedAngleOrRecord16);
                                    retainedAngleOrRecord16 +=
                                        Level43_7CEF0ApproximatePlanarDistance(
                                            retainedSearchPosition22, retainedAngleOrAddress18) >>
                                        10;
                                    if ((retainedAngleOrRecord16 <
                                         retainedMinimumScoreOrDataAddress) &&
                                        (Level43_7CEF0Call13E38(retainedSearchPosition22,
                                                                retainedAngleOrAddress18,
                                                                4) != 0)) {
                                        retainedSelectedRecord23 = retainedRecordOrVector17;
                                        retainedMinimumScoreOrDataAddress = retainedAngleOrRecord16;
                                    }
                                }
                            }
                        }
                    }
                    retainedRecordOrVector17 =
                        Level43_7CEF0Field(retainedRecordOrDataAddress20, void**, 0);
                    retainedRecordOrDataAddress20 += 4;
                } while (retainedRecordOrVector17 != 0);
            }
            argumentWord4 = privateRecord21;
            if (retainedSelectedRecord23 != 0) {
                argumentWord5 = retainedSelectedRecord23 + 12;
                argumentWord6 = Level43_7CEF0Data6C550;
                rawWord2 = 7;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
                argumentWord6 = retainedSelectedRecord23 - argumentWord6;
                rawWord2 = argumentWord6 << 5;
                rawWord2 -= argumentWord6;
                rawWord2 <<= 5;
                rawWord2 += argumentWord6;
                rawWord3 = rawWord2 << 3;
                rawWord2 += rawWord3;
                rawWord3 = rawWord2 << 15;
                rawWord3 -= rawWord2;
                rawWord3 <<= 2;
                rawWord3 += argumentWord6;
                rawWord3 = -rawWord3;
                rawWord2 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46);
                rawWord3 >>= 3;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x49) = rawWord3;
                Level43_7CEF0Field(argumentWord4, unsigned char*, 0xF) = rawWord2;
                Level43_7CEF0CopyVector(argumentWord4, argumentWord5, argumentWord6);
                return;
            }
            Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) = 0U;
            retainedSearchPosition22 = 1;
        case 6:
            if (Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) == 6) {
                Level43_7CEF0TurnMobyTowardPlayer(ownerRecord19, 0x80, 0, 0);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45) =
                    Level43_7CEF0PlanarHeadingLookup(
                        Level43_7CEF0ApproximatePlanarDistance(ownerRecord19 + 0xC,
                                                               ((void*)&Level43_7CEF0Data70328)),
                        Level43_7CEF0Field(((void*)&Level43_7CEF0Data70328), int*, 8) -
                            Level43_7CEF0Field(ownerRecord19, int*, 0x14),
                        0);
                Level43_7CEF0RefreshMobySpatialGridAndBasis(ownerRecord19, 4);
                argumentWord4 = (int)ownerRecord19 + 0x20;
                argumentWord5 = (int)&originalFrame.sp18;
                rawWord2 = Level43_7CEF0Field(privateRecord21, short*, 0xC);
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord5);
                argumentWord6 = privateRecord21;
                originalFrame.sp1C = 0;
                originalFrame.sp20 = 0;
                originalFrame.sp18 = rawWord2;
                Level43_7CEF0TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                case 7:
            }
            retainedAngleOrAddress18 = 0;
            if (Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) == 7) {
                argumentWord4 = (int)&originalFrame.sp18;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                rawWord3 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x49);
                argumentWord5 = (int)ownerRecord19 + 12;
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level43_7CEF0Data6C550;
                retainedRecordOrDataAddress20 = rawWord3 + rawWord2;
                retainedAngleOrRecord16 = retainedRecordOrDataAddress20 + 12;
                MATCHING_KEEP(retainedAngleOrRecord16);
                Level43_7CEF0SubtractVector(argumentWord4, argumentWord5, retainedAngleOrRecord16);
                rawWord2 =
                    Level43_7CEF0PlanarHeadingLookup(originalFrame.sp18, originalFrame.sp1C, 0);
                retainedRecordOrVector17 = (int)&originalFrame.sp28;
                argumentWord4 = retainedRecordOrVector17;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                argumentWord5 = retainedAngleOrRecord16;
                rawWord3 = rawWord2 - 128;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46) = rawWord3;
                retainedAngleOrRecord16 =
                    Level43_7CEF0Field(retainedRecordOrDataAddress20, unsigned char*, 0x46);
                MATCHING_OBSERVE_GNU_VOLATILE(retainedAngleOrRecord16);
                argumentWord6 = privateRecord21;
                retainedAngleOrRecord16 -= rawWord2;
                retainedAngleOrRecord16 &= 255;
                Level43_7CEF0SubtractVector(argumentWord4, argumentWord5, argumentWord6);
                rawWord2 = Level43_7CEF0MeasureVectorLength(retainedRecordOrVector17, 0);
                retainedAngleOrRecord16 += 64;
                retainedAngleOrRecord16 &= 255;
                retainedAngleOrRecord16 <<= 1;
                rawWord3 =
                    Level43_7CEF0Field(&Level43_7CEF0Data65920, short*, retainedAngleOrRecord16);
                {
                    long long completeFirstSignedProduct;
                    int firstProductLowWord;
                    completeFirstSignedProduct = (long long)rawWord2 * (long long)rawWord3;
                    __asm__("" : "=l"(firstProductLowWord) : "x"(completeFirstSignedProduct));
                    rawWord2 = firstProductLowWord;
                }
                {
                    long long completeSecondSignedProduct;
                    int secondProductHighWord;
                    rawWord3 = 0x1B4E81B5;
                    completeSecondSignedProduct = (long long)rawWord2 * (long long)rawWord3;
                    directionSign9 = 1;
                    rawWord2 >>= 31;
                    __asm__("" : "=h"(secondProductHighWord) : "x"(completeSecondSignedProduct));
                    rangeBoundOrProductHigh10 = secondProductHighWord;
                    MATCHING_KEEP(rangeBoundOrProductHigh10);
                    rawWord3 = rangeBoundOrProductHigh10 >> 6;
                    argumentWord6 = rawWord3 - rawWord2;
                }
                MATCHING_KEEP_CLOBBER(argumentWord6, "$8");
                nearestDifference8 = 0x2710;
                if (argumentWord6 < 0) {
                    directionSign9 = -1;
                }
                argumentWord6 = argumentWord6 & 0xFFF;
                MATCHING_KEEP(argumentWord6);
                rawWord2 = argumentWord6 >> 6;
                argumentWord4 = rawWord2 - 2;
                MATCHING_KEEP(argumentWord4);
                argumentWord7 = argumentWord4 + 4;
                if (argumentWord4 < 0) {
                    argumentWord4 = 0;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord7 = argumentWord4 + 4;
                }
                if (argumentWord4 < argumentWord7) {
                    rawWord2 = argumentWord4 * 2;
                    rawWord3 = (int)&Level43_7CEF0Data658A0;
                    argumentWord5 = rawWord2 + rawWord3;
                    do {
                        rawWord2 = Level43_7CEF0Field(argumentWord5, short*, 0) - argumentWord6;
                        rawWord3 = rawWord2;
                        if (rawWord2 < 0) {
                            rawWord3 = -rawWord3;
                        }
                        if (rawWord3 < nearestDifference8) {
                            retainedAngleOrAddress18 = argumentWord4;
                            nearestDifference8 = rawWord3;
                        }
                        argumentWord4 += 1;
                        argumentWord5 += 2;
                    } while (argumentWord4 < argumentWord7);
                }
                rawWord2 = nearestDifference8 < 0x79;
                MATCHING_OBSERVE_GNU_VOLATILE(nearestDifference8);
                if (!rawWord2) {
                    retainedAngleOrAddress18 = 0;
                    goto block_50;
                }
                rawWord2 = retainedAngleOrAddress18 < 0xB;
                if (directionSign9 < 0) {
                    rawWord2 = retainedAngleOrAddress18 + 0x80;
                    retainedAngleOrAddress18 = rawWord2 & 0xFF;
                block_50:
                    rawWord2 = retainedAngleOrAddress18 < 0xB;
                }
                if (rawWord2 == 0) {
                    MATCHING_BARRIER_GNU_VOLATILE("$2");
                    retainedAngleOrAddress18 = 0xA;
                } else if (retainedAngleOrAddress18 < -0xA) {
                    retainedAngleOrAddress18 = -0xA;
                }
                retainedAngleOrRecord16 = (int)&originalFrame.sp28;
                MATCHING_KEEP(retainedAngleOrRecord16);
                Level43_7CEF0CopyVector(retainedAngleOrRecord16, retainedRecordOrDataAddress20 + 12,
                                        argumentWord6, argumentWord7);
                argumentWord4 = (int)ownerRecord19 + 12;
                rawWord2 = originalFrame.sp30;
                argumentWord5 = retainedAngleOrRecord16;
                rawWord2 += 500;
                originalFrame.sp30 = rawWord2;
                rawWord2 = Level43_7CEF0ApproximatePlanarDistance(argumentWord4, argumentWord5);
                argumentWord4 = rawWord2;
                rawWord2 = originalFrame.sp30;
                argumentWord5 = Level43_7CEF0Field(ownerRecord19, int*, 0x14);
                argumentWord6 = 0;
                argumentWord5 = rawWord2 - argumentWord5;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45) =
                    Level43_7CEF0PlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46) =
                    (unsigned char)(Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46) +
                                    retainedAngleOrAddress18);
                originalFrame.sp28 = 0x258;
                originalFrame.sp2C = 0;
                originalFrame.sp30 = 0;
                Level43_7CEF0RefreshMobySpatialGridAndBasis(ownerRecord19, 4);
                Level43_7CEF0TransformVectorByBasis(ownerRecord19 + 0x20, retainedAngleOrRecord16,
                                                    privateRecord21);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45) =
                    Level43_7CEF0PlanarHeadingLookup(
                        Level43_7CEF0MeasureVectorLength(privateRecord21, 1),
                        Level43_7CEF0Field(privateRecord21, int*, 8), 0);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46) =
                    Level43_7CEF0PlanarHeadingLookup(Level43_7CEF0Field(privateRecord21, int*, 0),
                                                     Level43_7CEF0Field(privateRecord21, int*, 4),
                                                     0);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) = 0U;
            }
        case 0:
            retainedAngleOrRecord16 = 0;
            rawWord3 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x3A);
            MATCHING_KEEP(rawWord3);
            retainedRecordOrVector17 = 0;
            if (rawWord3 < 0xFFU) {
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level43_7CEF0Data6C550;
                retainedAngleOrRecord16 = rawWord3 + rawWord2;
            }
            if ((retainedSearchPosition22 != 0) && (retainedAngleOrRecord16 != 0)) {
                Level43_7CEF0CopyVector(&originalFrame.sp48, retainedAngleOrRecord16 + 0xC);
                originalFrame.sp50 += 0x200;
            } else {
                Level43_7CEF0CopyVector(&originalFrame.sp48, ownerRecord19 + 0xC);
            }
            argumentWord4 = (int)&originalFrame.sp38;
            MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
            retainedAngleOrAddress18 = (int)ownerRecord19 + 12;
            Level43_7CEF0AddVector(argumentWord4, retainedAngleOrAddress18, privateRecord21);
            if ((originalFrame.sp38 < 0x1068) || (originalFrame.sp3C < 0x1068) ||
                (originalFrame.sp40 < 0x1068) || (originalFrame.sp38 > 0x3E738) ||
                (originalFrame.sp3C > 0x3E738) || (originalFrame.sp40 > 0x3E738)) {
                temp_a0_2 = Level43_7CEF0Field(privateRecord21, void**, 0x14);
                if (temp_a0_2 != 0) {
                    Level43_7CEF0DeleteMoby(temp_a0_2);
                    __asm__ __volatile__("" ::"i"(103111) : "memory");
                    Level43_7CEF0Field(privateRecord21, void**, 0x14) = 0;
                }
                goto block_134;
            }
            if ((retainedAngleOrRecord16 != 0) &&
                (Level43_7CEF0Field(retainedAngleOrRecord16, short*, 0x36) != 0x63) &&
                (Level43_7CEF0Call1C288(retainedAngleOrAddress18, 0xC8, 1) != 0)) {
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord5, "memory");
                rawWord2 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46);
                rawWord3 = (int)Level43_7CEF0DataSpawnMoby;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(rawWord2, rawWord3, "$17");
                retainedRecordOrVector17 = (int)&Level43_7CEF0Data70328 + 0x298;
                Level43_7CEF0Field(retainedRecordOrVector17, int*, 0) = rawWord2;
                retainedAngleOrRecord16 = ((void* (*)())rawWord3)(argumentWord4, argumentWord5);
                MATCHING_KEEP(retainedAngleOrRecord16);
                if (retainedAngleOrRecord16 != 0) {
                    rawWord3 = Level43_7CEF0Field(retainedAngleOrRecord16, void**, 0);
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x48) = 4;
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x41) = 0;
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x4C) = 0;
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x4D) = 0;
                    Level43_7CEF0Field(rawWord3, short*, 0x10) = 0xF;
                    Level43_7CEF0Field(rawWord3, short*, 0x12) = 1;
                    Level43_7CEF0CopyVector(retainedAngleOrRecord16 + 0xC,
                                            retainedRecordOrVector17 - 0x298);
                    Level43_7CEF0Field(retainedAngleOrRecord16, int*, 0x14) =
                        (int)Level43_7CEF0Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            retainedAngleOrAddress18 = (int)Level43_7CEF0Call1BA30((void*)(ownerRecord19 + 12), 300,
                                                                   2, 0, 0, (void*)ownerRecord19);
            MATCHING_KEEP(retainedAngleOrAddress18);
            if (retainedAngleOrAddress18 != 0) {
                rawWord2 = Level43_7CEF0PlanarHeadingLookup(
                    Level43_7CEF0Field(privateRecord21, int*, 0),
                    Level43_7CEF0Field(privateRecord21, int*, 4), 0);
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
                Level43_7CEF0Field(retainedAngleOrAddress18, unsigned char*, 0x51) = rawWord2;
                rawWord2 = 0x10000;
                rawWord3 = Level43_7CEF0Field(retainedAngleOrAddress18, int*, 0x18);
                argumentWord6 = (int)Level43_7CEF0DataSpawnMoby;
                rawWord3 |= rawWord2;
                Level43_7CEF0Field(retainedAngleOrAddress18, int*, 0x18) = rawWord3;
                retainedAngleOrRecord16 =
                    ((void* (*)())argumentWord6)(argumentWord4, argumentWord5, argumentWord6);
                MATCHING_KEEP(retainedAngleOrRecord16);
                if (retainedAngleOrRecord16 != 0) {
                    rawWord3 = Level43_7CEF0Field(retainedAngleOrRecord16, void**, 0);
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x48) = 4;
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x41) = 0;
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x4C) = 0;
                    Level43_7CEF0Field(retainedAngleOrRecord16, signed char*, 0x4D) = 0;
                    Level43_7CEF0Field(rawWord3, short*, 0x10) = 15;
                    Level43_7CEF0Field(rawWord3, short*, 0x12) = 1;
                    Level43_7CEF0CopyVector(retainedAngleOrRecord16 + 12,
                                            retainedAngleOrAddress18 + 12);
                    Level43_7CEF0Field(retainedAngleOrRecord16, int*, 0x14) =
                        Level43_7CEF0Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            MATCHING_KEEP_VOLATILE(retainedAngleOrAddress18);
            if (Level43_7CEF0Field(privateRecord21, short*, 0xC) >= 0xFA1) {
                rawWord2 =
                    Level43_7CEF0Data74424(&originalFrame.sp48, &originalFrame.sp38, 0, 1) == 0;
            } else {
                rawWord2 =
                    Level43_7CEF0Call1830C(&originalFrame.sp48, &originalFrame.sp38, 2, 1, 0);
            }
            if (rawWord2 == 0) {
                rawWord2 = Level43_7CEF0Field(privateRecord21, short*, 0xC);
                if (rawWord2 >= 4001) {
                    argumentWord4 = (int)&originalFrame.sp48;
                    argumentWord5 = (int)&originalFrame.sp38;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord5, "memory");
                    rawWord2 = (int)Level43_7CEF0Data74428;
                    argumentWord6 = 0;
                    retainedAngleOrAddress18 =
                        ((void* (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6);
                } else {
                    argumentWord4 = (int)&originalFrame.sp48;
                    argumentWord5 = (int)&originalFrame.sp38;
                    argumentWord6 = 0;
                    argumentWord7 = 0;
                    retainedAngleOrAddress18 = Level43_7CEF0Call1AD60(
                        argumentWord4, argumentWord5, argumentWord6, argumentWord7, ownerRecord19);
                }
                if (retainedAngleOrAddress18 != 0) {
                    goto block_89;
                }
                goto block_120;
            }
            if (Level43_7CEF0Field(privateRecord21, short*, 0xC) >= 0xFA1) {
                retainedAngleOrAddress18 = Level43_7CEF0Data74428(
                    &originalFrame.sp48, ((void*)&Level43_7CEF0Data71900), 0);
            } else {
                retainedAngleOrAddress18 = Level43_7CEF0Call1AD60(
                    &originalFrame.sp48, ((void*)&Level43_7CEF0Data71900), 0, 0, ownerRecord19);
            }
            if (retainedAngleOrAddress18 != 0) {
            block_89:
                rawWord2 = Level43_7CEF0PlanarHeadingLookup(
                    Level43_7CEF0Field(privateRecord21, int*, 0),
                    Level43_7CEF0Field(privateRecord21, int*, 4), 0);
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
                Level43_7CEF0Field(retainedAngleOrAddress18, unsigned char*, 0x51) = rawWord2;
                rawWord2 = 0x10000;
                rawWord3 = Level43_7CEF0Field(retainedAngleOrAddress18, int*, 0x18);
                argumentWord6 = (int)Level43_7CEF0DataSpawnMoby;
                rawWord3 |= rawWord2;
                Level43_7CEF0Field(retainedAngleOrAddress18, int*, 0x18) = rawWord3;
                retainedRecordOrVector17 =
                    ((void* (*)())argumentWord6)(argumentWord4, argumentWord5, argumentWord6);
                MATCHING_KEEP(retainedRecordOrVector17);
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level43_7CEF0Field(retainedRecordOrVector17, void**, 0);
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                    Level43_7CEF0Field(rawWord3, short*, 0x10) = 0xF;
                    Level43_7CEF0Field(rawWord3, short*, 0x12) = 1;
                    Level43_7CEF0CopyVector(retainedRecordOrVector17 + 0xC,
                                            retainedAngleOrAddress18 + 0xC);
                    Level43_7CEF0Field(retainedRecordOrVector17, int*, 0x14) =
                        (int)Level43_7CEF0Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            if (Level43_7CEF0Field(privateRecord21, unsigned char*, 0xE) != 0) {
                MATCHING_KEEP(retainedAngleOrAddress18);
                retainedRecordOrVector17 = Level43_7CEF0DataSpawnMoby(0xC5, 0);
                MATCHING_KEEP(retainedRecordOrVector17);
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level43_7CEF0Field(retainedRecordOrVector17, void**, 0);
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                    Level43_7CEF0Field(rawWord3, short*, 0x10) = 0x1E;
                    Level43_7CEF0Field(rawWord3, short*, 0x12) = 0xF;
                    Level43_7CEF0CopyVector(retainedRecordOrVector17 + 0xC,
                                            ((void*)&Level43_7CEF0Data71900));
                }
            block_94:
                retainedRecordOrVector17 = 1;
                goto block_120;
            } else {
                MATCHING_KEEP(retainedAngleOrAddress18);
                retainedAngleOrAddress18 = (int)&Level43_7CEF0Data71924;
                if (Level43_7CEF0Call40954(Level43_7CEF0Field(retainedAngleOrAddress18, int*, 0)) ==
                    3) {
                    temp_a0_5 = Level43_7CEF0Field(
                        Level43_7CEF0Field(((void*)&Level43_7CEF0Data6D048), int*, 0x14), void**,
                        (Level43_7CEF0Field(retainedAngleOrAddress18, int*, 0) & 0x3F) * 4);
                    Level43_7CEF0Field(temp_a0_5, int*, 4) =
                        (int)(Level43_7CEF0Field(temp_a0_5, int*, 4) | 0x10000);
                }
                Level43_7CEF0Field(privateRecord21, unsigned char*, 0xE) =
                    (unsigned char)(Level43_7CEF0Field(privateRecord21, unsigned char*, 0xE) + 1);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                retainedRecordOrVector17 = Level43_7CEF0DataSpawnMoby(0xC5, 0);
                MATCHING_KEEP(retainedRecordOrVector17);
                retainedAngleOrRecord16 = retainedRecordOrVector17 + 0xC;
                if (retainedRecordOrVector17 != 0) {
                    argumentWord4 = retainedAngleOrRecord16;
                    __asm__(""
                            : "=r"(retainedAngleOrAddress18)
                            : "0"(retainedAngleOrAddress18), "r"(argumentWord4));
                    retainedMinimumScoreOrDataAddress = retainedAngleOrAddress18 - 0x24;
                    Level43_7CEF0Field(Level43_7CEF0Field(retainedRecordOrVector17, void**, 0),
                                       short*, 0x10) = 2;
                    Level43_7CEF0CopyVector(retainedAngleOrRecord16,
                                            retainedMinimumScoreOrDataAddress);
                    rawWord2 = Level43_7CEF0RandBetween(0, 0xFF);
                    argumentWord4 = retainedAngleOrRecord16;
                    retainedAngleOrRecord16 = (int)&Level43_7CEF0Data6E020;
                    argumentWord5 = retainedAngleOrRecord16;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
                    retainedSearchPosition22 = rawWord2;
                    Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x44) =
                        retainedSearchPosition22;
                    rawWord2 = Level43_7CEF0ApproximatePlanarDistance(argumentWord4, argumentWord5);
                    argumentWord4 = rawWord2;
                    rawWord2 = Level43_7CEF0Data6E028;
                    argumentWord5 = Level43_7CEF0Field(retainedRecordOrVector17, int*, 0x14);
                    argumentWord6 = 0;
                    argumentWord5 = rawWord2 - argumentWord5;
                    rawWord2 = Level43_7CEF0PlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                argumentWord6);
                    argumentWord6 = 0;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
                    retainedRecordOrDataAddress20 = rawWord2;
                    Level43_7CEF0Field(retainedRecordOrVector17, unsigned char*, 0x45) =
                        retainedRecordOrDataAddress20;
                    rawWord2 = Level43_7CEF0PlanarHeadingLookup(
                        Level43_7CEF0Field(retainedAngleOrRecord16, int*, 0) -
                            Level43_7CEF0Field(retainedRecordOrVector17, int*, 0xC),
                        Level43_7CEF0Data6E024 -
                            Level43_7CEF0Field(retainedRecordOrVector17, int*, 0x10),
                        argumentWord6);
                    argumentWord4 = retainedRecordOrVector17;
                    argumentWord5 = 1;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
                    retainedAngleOrAddress18 = rawWord2;
                    rawWord2 = 1;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord2, "$16");
                    retainedAngleOrRecord16 = 255;
                    Level43_7CEF0Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = 13;
                    Level43_7CEF0Field(argumentWord4, unsigned char*, 0x46) =
                        retainedAngleOrAddress18;
                    Level43_7CEF0Field(argumentWord4, unsigned char*, 0x54) =
                        retainedAngleOrRecord16;
                    Level43_7CEF0Field(argumentWord4, unsigned char*, 0x55) = 0;
                    Level43_7CEF0Field(argumentWord4, unsigned char*, 0x56) = 0;
                    Level43_7CEF0Field(argumentWord4, unsigned char*, 0x57) = rawWord2;
                    Level43_7CEF0SetMobyAnimation(argumentWord4, argumentWord5);
                    retainedRecordOrVector17 = Level43_7CEF0DataSpawnMoby(0xC5, 0);
                    MATCHING_KEEP(retainedRecordOrVector17);
                    if (retainedRecordOrVector17 != 0) {
                        Level43_7CEF0Field(Level43_7CEF0Field(retainedRecordOrVector17, void**, 0),
                                           short*, 0x10) = 2;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x57) = 0xF;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x44) =
                            retainedSearchPosition22;
                        Level43_7CEF0Field(retainedRecordOrVector17, unsigned char*, 0x45) =
                            retainedRecordOrDataAddress20;
                        Level43_7CEF0Field(retainedRecordOrVector17, unsigned char*, 0x46) =
                            retainedAngleOrAddress18;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x54) =
                            retainedAngleOrRecord16;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x55) =
                            retainedAngleOrRecord16;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x56) =
                            retainedAngleOrRecord16;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x48) = 3;
                        Level43_7CEF0CopyVector(retainedRecordOrVector17 + 0xC,
                                                retainedMinimumScoreOrDataAddress);
                        Level43_7CEF0SetMobyAnimation(retainedRecordOrVector17, 3);
                    }
                }
                Level43_7CEF0CopyVector(ownerRecord19 + 0xC, ((void*)&Level43_7CEF0Data71900));
                Level43_7CEF0CopyVector(&originalFrame.sp38,
                                        ((void*)&Level43_7CEF0Data71900) + 0x18);
                argumentWord4 = originalFrame.sp40;
                if (argumentWord4 == 0)
                    goto clearOriginalVerticalComponent;
                rawWord3 = originalFrame.sp38;
                rawWord2 = rawWord3 * 100;
                rawWord2 /= argumentWord4;
                if (rawWord2 < 0)
                    rawWord2 = -rawWord2;
                if (rawWord2 >= 6)
                    goto clearOriginalVerticalComponent;
                rawWord3 = originalFrame.sp3C;
                rawWord2 = rawWord3 * 100;
                rawWord2 /= argumentWord4;
                if (rawWord2 < 0)
                    rawWord2 = -rawWord2;
                rawWord2 = rawWord2 < 6;
                argumentWord4 = privateRecord21;
                if (rawWord2)
                    goto integrateOriginalVector;
            clearOriginalVerticalComponent:
                originalFrame.sp40 = 0;
                argumentWord4 = privateRecord21;
            integrateOriginalVector:
                MATCHING_BARRIER_GNU_VOLATILE("$17");
                retainedRecordOrVector17 = (int)&originalFrame.sp38;
                Level43_7CEF0Call4EF74(argumentWord4, retainedRecordOrVector17, privateRecord21);
                if (Level43_7CEF0Field(privateRecord21, short*, 0xC) >= 0xFA1) {
                    Level43_7CEF0Field(privateRecord21, short*, 0xC) = 0x258;
                }
                Level43_7CEF0ScaleVectorRatioQ15(
                    privateRecord21, Level43_7CEF0MeasureVectorLength(privateRecord21, 1),
                    Level43_7CEF0Field(privateRecord21, short*, 0xC));
                Level43_7CEF0CopyVector(retainedRecordOrVector17, privateRecord21);
                Level43_7CEF0ScaleVectorRatioQ15(
                    retainedRecordOrVector17,
                    Level43_7CEF0MeasureVectorLength(retainedRecordOrVector17, 1), 0x320);
                argumentWord4 = retainedRecordOrVector17;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                retainedAngleOrAddress18 = (int)ownerRecord19 + 12;
                Level43_7CEF0AddVector(argumentWord4, retainedAngleOrAddress18,
                                       retainedRecordOrVector17);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45) =
                    Level43_7CEF0PlanarHeadingLookup(
                        Level43_7CEF0MeasureVectorLength(privateRecord21, 1),
                        Level43_7CEF0Field(privateRecord21, int*, 8), 0);
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46) =
                    Level43_7CEF0PlanarHeadingLookup(Level43_7CEF0Field(privateRecord21, int*, 0),
                                                     Level43_7CEF0Field(privateRecord21, int*, 4),
                                                     0);
                Level43_7CEF0PlayMobySoundEvent(ownerRecord19, 1, 0);
                retainedAngleOrRecord16 = (int)&originalFrame.sp58;
                argumentWord4 = retainedAngleOrRecord16;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$20");
                retainedRecordOrDataAddress20 = (int)&Level43_7CEF0Data71918;
                Level43_7CEF0CopyVector(argumentWord4, retainedRecordOrDataAddress20);
                Level43_7CEF0ScaleVectorRatioQ15(
                    &originalFrame.sp58, Level43_7CEF0MeasureVectorLength(&originalFrame.sp58, 1),
                    0x37);
                Level43_7CEF0AddVector(&originalFrame.sp58, retainedAngleOrAddress18,
                                       &originalFrame.sp58);
                if ((Level43_7CEF0Call19138(&originalFrame.sp58, 0x32, 1, 0, 0, 0) != 0) ||
                    (Level43_7CEF0Call1830C(retainedRecordOrVector17, &originalFrame.sp58, 3, 0,
                                            0) != 0)) {
                    if (Level43_7CEF0Call40954(Level43_7CEF0Data71924) == 3) {
                        temp_a0_6 = Level43_7CEF0Field(
                            Level43_7CEF0Field(((void*)&Level43_7CEF0Data6D048), int*, 0x14),
                            void**, (Level43_7CEF0Data71924 & 0x3F) * 4);
                        Level43_7CEF0Field(temp_a0_6, int*, 4) =
                            (int)(Level43_7CEF0Field(temp_a0_6, int*, 4) | 0x10000);
                    }
                    retainedRecordOrVector17 = Level43_7CEF0DataSpawnMoby(0xC5, 0);
                    MATCHING_KEEP(retainedRecordOrVector17);
                    if (retainedRecordOrVector17 != 0) {
                        rawWord3 = Level43_7CEF0Field(retainedRecordOrVector17, void**, 0);
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                        Level43_7CEF0Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                        Level43_7CEF0Field(rawWord3, short*, 0x10) = 0x1E;
                        Level43_7CEF0Field(rawWord3, short*, 0x12) = 0xF;
                        Level43_7CEF0CopyVector(retainedRecordOrVector17 + 0xC,
                                                retainedRecordOrDataAddress20 - 0x18);
                    }
                    temp_a0_7 = Level43_7CEF0Field(privateRecord21, void**, 0x14);
                    if (temp_a0_7 != 0) {
                        Level43_7CEF0DeleteMoby(temp_a0_7);
                        __asm__ __volatile__("" ::"i"(103113) : "memory");
                        Level43_7CEF0Field(privateRecord21, void**, 0x14) = 0;
                    }
                    goto block_134;
                }
                Level43_7CEF0CopyVector(retainedAngleOrAddress18, retainedRecordOrVector17);
                rawWord3 = Level43_7CEF0Field(privateRecord21, void**, 0x14);
                if (rawWord3 != 0) {
                    Level43_7CEF0Field(rawWord3, unsigned char*, 0x45) =
                        (unsigned char)Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45);
                    Level43_7CEF0Field(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                       unsigned char*, 0x46) =
                        (unsigned char)Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46);
                    Level43_7CEF0CopyVector(Level43_7CEF0Field(privateRecord21, void**, 0x14) + 0xC,
                                            retainedAngleOrAddress18);
                    rawWord3 = Level43_7CEF0Field(privateRecord21, int*, 0x14);
                    rawWord2 = 255;
                    Level43_7CEF0Field(rawWord3, unsigned char*, 0x54) = rawWord2;
                    Level43_7CEF0Field(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                       signed char*, 0x55) = 0;
                    Level43_7CEF0Field(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                       signed char*, 0x56) = 0;
                    Level43_7CEF0Field(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                       signed char*, 0x57) = 0x38;
                    Level43_7CEF0SetMobyAnimation(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                                  4);
                    return;
                }
                default:
                    return;
            }
        block_120:
            if ((retainedRecordOrVector17 != 0) ||
                (Level43_7CEF0CountTimerDown(privateRecord21 + 0x10, 2) != 0)) {
                temp_a0_3 = Level43_7CEF0Field(privateRecord21, void**, 0x14);
                if (temp_a0_3 != 0) {
                    Level43_7CEF0DeleteMoby(temp_a0_3);
                    __asm__ __volatile__("" ::"i"(103112) : "memory");
                    Level43_7CEF0Field(privateRecord21, void**, 0x14) = 0;
                }
                goto block_134;
            }
            Level43_7CEF0CopyVector(ownerRecord19 + 0xC, &originalFrame.sp38);
            temp_a0_4 = Level43_7CEF0Field(privateRecord21, void**, 0x14);
            if (temp_a0_4 != 0) {
                Level43_7CEF0CopyVector(temp_a0_4 + 0xC, &originalFrame.sp38);
                Level43_7CEF0Field(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                   unsigned char*, 0x45) =
                    (unsigned char)Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45);
                Level43_7CEF0Field(Level43_7CEF0Field(privateRecord21, void**, 0x14),
                                   unsigned char*, 0x46) =
                    (unsigned char)Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46);
                return;
            }
            break;
        case 4:
            Level43_7CEF0Field(ownerRecord19, signed char*, 0x41) = 0;
            Level43_7CEF0Field(ownerRecord19, signed char*, 0x4C) = 0;
            Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x4D) = 0U;
            if (Level43_7CEF0Field(privateRecord21, short*, 0x10) != 0) {
                originalFrame.sp68 = (Level43_7CEF0Datarand() & 0xF) - 7;
                originalFrame.sp6C = (Level43_7CEF0Datarand() & 0xF) - 7;
                originalFrame.sp70 = Level43_7CEF0Datarand() & 0x3F;
                Level43_7CEF0DataSpawnParticle(1, 0, ownerRecord19 + 0xC, &originalFrame.sp68);
            }
            if (Level43_7CEF0Field(privateRecord21, short*, 0x12) != 0) {
                Level43_7CEF0CountTimerDown(privateRecord21 + 0x12, 2);
                temp_v0_12 =
                    Level43_7CEF0DataSpawnParticle(1, 0x3D, ownerRecord19 + 0xC, (int*)0x808080);
                if (temp_v0_12 != 0) {
                    Level43_7CEF0Field(temp_v0_12, signed char*, 0xA) = 0x32;
                }
            }
            if (Level43_7CEF0CountTimerDown(privateRecord21 + 0x10, 2) != 0) {
                goto block_134;
            }
            break;
        case 1:
        case 3:
            if (Level43_7CEF0Field(privateRecord21, short*, 0x10) != 0)
                goto continueOriginalStatesOneOrThree;
        block_134:
            Level43_7CEF0DeleteMoby(ownerRecord19);
            return;
        continueOriginalStatesOneOrThree:
            if (Level43_7CEF0CountTimerDown(privateRecord21 + 0x10, 2) != 0) {
                rawWord2 = 48;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x4F) = rawWord2;
                rawWord2 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x54);
                rawWord3 = 13;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x57) = rawWord3;
                rawWord3 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x56);
                rawWord2 >>= 3;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x54) = rawWord2;
                rawWord2 = Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x55);
                rawWord3 = (unsigned int)rawWord3 >> 3;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x56) = rawWord3;
                rawWord2 >>= 3;
                Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x55) = rawWord2;
            }
            Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x46) =
                (unsigned char)(((int)(Level43_7CEF0Data6E040 << 0x10) >> 0x14) - 0x80);
            Level43_7CEF0Field(ownerRecord19, unsigned char*, 0x45) =
                (unsigned char)((unsigned short)Level43_7CEF0Data6E03E >> 4);
            break;
    }
}
#undef Level43_7CEF0Field

/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level_43/moby/func_level_43_8007DF90.s and
 * level_46/moby/func_level_46_80082FE0.s: all 248 instructions read per copy.
 * Four word-sized child slots at tag+0..12 advance by four bytes. Signed
 * halfwords at tag+16/+18 and a word at +20 retain their original widths.
 * Child pointer rereads after helpers and byte stores are intentional.
 * Existing field/helper names do not establish semantics. Helper contracts,
 * selector producers, coordinate units and caller cadence remain unresolved.
 * Once per invocation. Confidence: exact compiled words. Falsifiable vectors:
 * every original linked word at the listed addresses and all retail hashes.
 * Empty compiler constraints preserve lifetimes without opcode patches.
 */
void ControllerDF90Update(int, int, int) __asm__("func_80021ED8");
int ControllerDF90Read(int) __asm__("func_80021F3C");
#define ControllerDF90Field(base, type, offset) (*(type)((unsigned char*)(base) + (offset)))
extern int D_8006C640;
void func_level_43_8007DF90(Moby* argument) {
    register Moby* moby __asm__("$19") = argument;
    short readSelector;
    short resetSelector;
    register int selectorBits __asm__("$2");
    register int highByte __asm__("$3");
    register int spawnIndex __asm__("$17");
    register int animationIndex __asm__("$17");
    register int removeIndex __asm__("$17");
    register int resetIndex __asm__("$17");
    register int frameStep __asm__("$21");
    register int updateByte __asm__("$2");
    register int framePhase __asm__("$20");
    register int animationOne __asm__("$20");
    register int animationSpeed __asm__("$21");
    unsigned char initialState;
    unsigned char currentState;
    register Moby** tag __asm__("$18");
    register Moby** spawnSlot __asm__("$16");
    register Moby** animationSlot __asm__("$16");
    register Moby** removeSlot __asm__("$16");
    register Moby** resetSlot __asm__("$16");
    void* removeChild;
    void* resetChild;
    register void* stateAddress __asm__("$16");
    void* spawnedChild;
    void* positionChild;
    void* animationChild;
    void* previousAnimationChild;
    void* previousFrameChild;
    void* stateArgument;

    initialState = moby->state;
    tag = (Moby**)moby->mobyTag;
    if (initialState == 5)
        goto done;
    if (initialState == 6)
        goto resetState;
    if (initialState != 7)
        goto normalState;
    moby->state = 2;
    stateAddress = &moby->state;
    func_8003B7B4(stateAddress, 1, &savedData);
    stateArgument = stateAddress;
    goto writeUnsavedState;
resetState:
    moby->state = 0;
    ControllerDF90Read(ControllerDF90Field(tag, short*, 0x12));
    ControllerDF90Update(ControllerDF90Field(tag, short*, 0x12), 0xFC, 0);
normalState:
    if (ControllerDF90Field(tag, void**, 0) == 0) {
        spawnIndex = 0;
        spawnSlot = tag;
        frameStep = 1;
        do {
            spawnedChild = SpawnMoby(0xDD, moby);
            framePhase = spawnIndex * 4;
            MATCHING_KEEP(framePhase);
            *spawnSlot = spawnedChild;
            if (spawnedChild != 0) {
                func_8004F178((Vector3D*)((unsigned char*)spawnedChild + 0xC), &moby->position);
                ControllerDF90Field(*spawnSlot, unsigned char*, 0x46) =
                    (unsigned char)ControllerDF90Field(moby, unsigned char*, 0x46);
                positionChild = *spawnSlot;
                ControllerDF90Field(positionChild, int*, 0x14) =
                    (int)(ControllerDF90Field(positionChild, int*, 0x14) +
                          (spawnIndex * ControllerDF90Field(tag, short*, 0x10)));
                ControllerDF90Field(*spawnSlot, unsigned char*, 0x4C) = 0x28;
                ControllerDF90Field(*spawnSlot, unsigned char*, 0x47) = 0xFF;
                ControllerDF90Field(*spawnSlot, unsigned char*, 0x3E) = framePhase;
                ControllerDF90Field(*spawnSlot, unsigned char*, 0x3F) = frameStep;
                ControllerDF90Field(*spawnSlot, unsigned char*, 0x40) = 0x30;
            }
            spawnSlot++;
            spawnIndex += 1;
            frameStep += 4;
        } while (spawnIndex < 4);
    }
    currentState = moby->state;
    if (currentState == 1) {
        animationIndex = 0;
        animationOne = 1;
        animationSpeed = 0x72;
        MATCHING_KEEP2_CLOBBER(animationOne, animationSpeed, "$16");
        animationSlot = tag;
        do {
            animationChild = *animationSlot;
            if (ControllerDF90Field(animationChild, unsigned char*, 0x3D) != animationOne) {
                ControllerDF90Field(animationChild, unsigned char*, 0x40) = animationSpeed;
                previousAnimationChild = *animationSlot;
                ControllerDF90Field(previousAnimationChild, unsigned char*, 0x3C) =
                    (unsigned char)ControllerDF90Field(previousAnimationChild, unsigned char*,
                                                       0x3D);
                ControllerDF90Field(*animationSlot, unsigned char*, 0x3D) = animationOne;
                previousFrameChild = *animationSlot;
                ControllerDF90Field(previousFrameChild, unsigned char*, 0x3E) =
                    (unsigned char)ControllerDF90Field(previousFrameChild, unsigned char*, 0x3F);
                ControllerDF90Field(*animationSlot, unsigned char*, 0x3F) = 0U;
                func_80035734(*animationSlot);
            }
            animationIndex += 1;
            animationSlot++;
        } while (animationIndex < 4);
        goto removeParent;
    }
    if (currentState == 2) {
        removeIndex = 0;
        removeSlot = tag;
        do {
            removeChild = *removeSlot;
            if (removeChild != 0) {
                func_80055B18(removeChild);
                *removeSlot = 0;
            }
            removeIndex += 1;
            removeSlot++;
        } while (removeIndex < 4);
        readSelector = ControllerDF90Field(tag, short*, 0x12);
        if (readSelector >= 0) {
            selectorBits = ControllerDF90Read(readSelector);
            highByte = selectorBits >> 8;
            MATCHING_KEEP2(highByte, selectorBits);
            if ((selectorBits & 0xF) && !(highByte & 0xFF)) {
                ControllerDF90Update(ControllerDF90Field(tag, short*, 0x12), 0xFC, 0);
            }
        }
        if (func_8003BFC0(moby, ControllerDF90Field(tag, int*, 0x14)) != 0) {
            func_8003BE70(ControllerDF90Field(tag, int*, 0x14));
        }
        ControllerDF90Field(tag, int*, 0x14) = -1;
        func_8003BB10(moby, 2, 0);
        stateArgument = &moby->state;
        goto writeUnsavedState;
    writeUnsavedState:
        func_8003B7B4(stateArgument, 1, &unsavedData);
    removeParent:
        func_80055B18(moby);
        goto done;
    }
    resetIndex = 0;
    if (currentState == 4) {
        resetSlot = tag;
        do {
            resetChild = *resetSlot;
            if (resetChild != 0) {
                func_80055B18(resetChild);
                *resetSlot = 0;
            }
            resetIndex += 1;
            resetSlot++;
        } while (resetIndex < 4);
        resetSelector = ControllerDF90Field(tag, short*, 0x12);
        if (resetSelector >= 0) {
            ControllerDF90Read(resetSelector);
            ControllerDF90Update(ControllerDF90Field(tag, short*, 0x12), 0xFC, 0);
        }
        if (func_8003BFC0(moby, ControllerDF90Field(tag, int*, 0x14)) != 0) {
            func_8003BE70(ControllerDF90Field(tag, int*, 0x14));
        }
        ControllerDF90Field(tag, int*, 0x14) = -1;
        func_8003BB10(moby, 2, 0);
        updateByte = 5;
        MATCHING_KEEP(updateByte);
        moby->state = updateByte;
        MATCHING_BARRIER_VOLATILE("memory");
        updateByte = 0xFF;
        goto storeUpdateByte;
    }
    if (func_8003BFC0(moby, ControllerDF90Field(tag, int*, 0x14)) == 0) {
        ControllerDF90Field(tag, int*, 0x14) = func_8003BB10(moby, 1, 4);
    }
    {
        register int skip __asm__("$2") = D_8006C640 < 9;
        MATCHING_KEEP(skip);
        if (skip)
            goto done;
    }
    updateByte = 12;
    {
    storeUpdateByte:
        ControllerDF90Field(moby, unsigned char*, 0x4A) = updateByte;
    }
done:
    return;
}

#undef ControllerDF90Field

extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_43_8007E370(Moby* moby) {
    if (moby->state == 0) {
        if (D_8006C770 && moby->animationState.id == 1)
            func_80055B18(moby);
    } else {
        int expired = func_800359A4(moby->mobyTag, 4);
        register Moby* argument __asm__("$4") = moby;
        if (expired) {
            func_80055B18(argument);
        } else {
            /* Non-emitting constraint preserves the retail branch delay slot. */
            MATCHING_KEEP(argument);
        }
    }
}

int func_80039714(Moby*);
void func_80055D24(Moby*, int);
void func_800369B8(Moby*, int);
void func_80055B18(Moby*);
void func_level_43_8007E3EC(Moby* moby) {
    register Moby* argument __asm__("$4") = moby;
    if (moby->state != 0x32) {
        int fragments;
        /* Empty constraints retain retail argument moves and emit no instructions. */
        MATCHING_BARRIER_VOLATILE("$4");
        fragments = func_80039714(moby);
        if (!fragments)
            return;
        func_80055D24(moby, 4);
        func_800369B8(moby, 0x20);
        SpawnParticle(8, 0x46, &moby->position, (Vector3D*)0x10);
        argument = moby;
        MATCHING_KEEP(argument);
    }
    func_80055B18(argument);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_43/moby/func_level_43_8007E46C.s SHA256 f7d5c2ffc1eb5b6d6fd7999f9c94c3e4c583187f403c11bb2987d65ddbe8cbbf. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level43_7E46CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level43_7E46C_D_8006C550 __asm__("D_8006C550");
extern Spyro Level43_7E46C_D_80070328 __asm__("D_80070328");
extern int Level43_7E46C_func_8001A358(Vector3D*, int) __asm__("func_8001A358");
void Level43_7E46CRequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level43_7E46CCountTimerDown(void*, int) __asm__("func_800359A4");
int Level43_7E46CRandBetween(int low, int high) __asm__("func_8003636C");
void Level43_7E46C_func_800369B8() __asm__("func_800369B8");
void Level43_7E46C_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
int Level43_7E46CPlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
extern void Level43_7E46CShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level43_7E46CCopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level43_7E46CAddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level43_7E46CApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level43_7E46CDeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level43_7E46CRefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level43_7E46C_func_80055E84(Moby*) __asm__("func_80055E84");

unsigned char Level43_7E46CSetMobyAnimation() __asm__("func_80034F80");
/* extern */
int Level43_7E46C_func_80035A80() __asm__("func_80035A80");
/* extern */
int Level43_7E46C_func_80036220() __asm__("func_80036220");
/* extern */
unsigned char Level43_7E46C_func_80036A68() __asm__("func_80036A68");
/* extern */
extern int Level43_7E46C_D_8006C54C __asm__("D_8006C54C");
extern int Level43_7E46C_D_8006C770 __asm__("D_8006C770");
extern int Level43_7E46C_D_8006C774 __asm__("D_8006C774");
extern unsigned char Level43_7E46C_D_level_43_80096464 __asm__("D_level_43_80096464");
extern unsigned char Level43_7E46C_func_800512E4 __asm__("func_800512E4");

void func_level_43_8007E46C(Moby* owner) {
    /* Original frame 0x58: scratch vectors SP+0x20 and SP+0x30.
     * E64C-E670 preserves the retail executable-word update.
     * E678 dispatch retains all 25 selectors plus the original padding word.
     * E7A8-E7B8 loads the related index and table before private halfword 30.
     * EA74/EAF8/EB3C each retains its original state-byte store;
      empty captures
     * of architectural register zero keep separate original reset blocks.
     * These constraints emit no instructions. The hardware zero register is
     * always zero;
      no unknown or uninitialized C value supplies these stores.
     * Private offsets and widths are raw instruction evidence. Physical units,
     * fixed-point domains, cadence, helper meanings and runtime chains remain
     * unresolved;
      native/linked/full hashes establish machine identity only. */
    struct {
        Vector3D sp20;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[4];
    } scratch;

    Moby* relatedMoby;
    register Vector3D* ownerPosition17 __asm__("$17");
    Vector3D* relatedPosition;
    int savedHelperResult;
    register int state3Zero0 __asm__("$0");
    register unsigned char state2Zero0 __asm__("$0");
    register int word2 __asm__("$2");
    register int predicate2 __asm__("$2");
    register Moby* argument4 __asm__("$4");
    int damageOrIndex3;
    register int animationArgument5 __asm__("$5");
    register int rawArgument5 __asm__("$5");
    register int damageState3 __asm__("$3");
    register int globalState3 __asm__("$3");
    register int dispatchState3 __asm__("$3");
    register int relatedState3 __asm__("$3");
    void* ownerPrivate;
    register void* relatedPrivate2 __asm__("$2");
    register int callbackFlags3 __asm__("$3");

    damageOrIndex3 = owner->damageFlags;
    ownerPrivate = owner->mobyTag;
    if (damageOrIndex3 & 0x140000) {
        Level43_7E46C_func_80036A68(owner, 0, 0, 0);
        Level43_7E46CPlayMobySoundEvent(owner, 2, 0);
        SpawnFragments(5, 0x1DC, owner, Level43_7E46CField(ownerPrivate, Vector3D**, 0x2C), 0,
                       0x100);
        Level43_7E46CRefreshMobySpatialGridAndBasis(owner, 4);
        Level43_7E46C_func_8003BA00(owner);
        Level43_7E46C_func_800369B8(owner, 0x38);
        Level43_7E46CDeleteMoby(owner);
        return;
    }
    if (damageOrIndex3 & 0x20000) {
        damageState3 = owner->state;
        owner->damageFlags = 0;
        if (!damageState3)
            goto animation2;
        predicate2 = (unsigned int)(damageState3 - 21) < 2U;
        argument4 = owner;
        if (predicate2)
            goto animation2Ready;
        predicate2 = (unsigned int)(damageState3 - 23) < 2U;
        if (!predicate2)
            goto afterDamageAnimation;
    animation2:
        argument4 = owner;
    animation2Ready:
        animationArgument5 = 2;
        goto damageAnimationCall;
    }
    if ((Level43_7E46CField(owner, unsigned short*, 0x3C) == 0x202) && Level43_7E46C_D_8006C770) {
        globalState3 = owner->state;
        if (!globalState3)
            goto animation0;
        predicate2 = (unsigned int)(globalState3 - 21) < 2U;
        argument4 = owner;
        if (predicate2)
            goto animation0Ready;
        predicate2 = (unsigned int)(globalState3 - 23) < 2U;
        if (!predicate2)
            goto afterDamageAnimation;
    animation0:
        argument4 = owner;
    animation0Ready:
        animationArgument5 = 0;
    damageAnimationCall:
        Level43_7E46CRequestMobyAnimation(argument4, animationArgument5);
    }
afterDamageAnimation:
    MATCHING_BARRIER("$2");
    if ((owner->state != 0x18) &&
        (Level43_7E46C_D_8006C550[Level43_7E46CField(ownerPrivate, int*, 0x10)].state & 0x80)) {
        Level43_7E46CRequestMobyAnimation(owner, 0);
        owner->animationProgress = 0xF0;
        owner->state = 0x18;
    }
    if (((Level43_7E46C_D_8006C54C - 1) == &Level43_7E46C_D_level_43_80096464) &&
        (Level43_7E46C_D_8006C774 != 0)) {
        Level43_7E46CField(&Level43_7E46C_func_800512E4, int*, 0) = 0x03E00008;
        Level43_7E46CField(&Level43_7E46C_func_800512E4, int*, 4) = 0;
    }
    dispatchState3 = owner->state;
    switch (dispatchState3) {
        case 0:
            if ((Level43_7E46CCountTimerDown(ownerPrivate + 2, 2) != 0) &&
                (Level43_7E46C_D_8006C550[Level43_7E46CField(ownerPrivate, int*, 0x10)].state ==
                 0x50)) {
                Level43_7E46CCopyVector(&scratch.sp20, &Level43_7E46C_D_80070328.unk7a[3]);
                scratch.sp20.x = (int)scratch.sp20.x * 0x19;
                scratch.sp20.y *= 0x19;
                scratch.sp20.z *= 0x19;
                Level43_7E46CShiftVectorRightTowardZero(&scratch.sp20, 6);
                Level43_7E46CAddVector(
                    &scratch.sp20, &scratch.sp20,
                    (Vector3D*)((unsigned char*)&Level43_7E46C_D_80070328.unk7a[3] - 0x98));
                ownerPosition17 = &owner->position;
                savedHelperResult =
                    Level43_7E46CApproximatePlanarDistance(ownerPosition17, &scratch.sp20);
                if (savedHelperResult < 0x2800) {
                    owner->state = 1;
                    Level43_7E46CRequestMobyAnimation(owner, 1);
                    Level43_7E46CPlayMobySoundEvent(owner, 0, 0);
                    rawArgument5 = (int)ownerPosition17;
                    MATCHING_OBSERVE(rawArgument5);
                    owner->animationProgress = 0xF0;
                    damageOrIndex3 = Level43_7E46CField(ownerPrivate, int*, 0x10);
                    relatedMoby = Level43_7E46C_D_8006C550;
                    __asm__("" : "=r"(relatedMoby) : "0"(relatedMoby), "r"(damageOrIndex3) : "$2");
                    word2 = 0x1E;
                    Level43_7E46CField(ownerPrivate, short*, 2) = word2;
                    relatedMoby = (Moby*)((unsigned char*)relatedMoby + damageOrIndex3 * 88);
                    relatedPosition = &relatedMoby->position;
                    Level43_7E46CCopyVector(relatedPosition, (Vector3D*)rawArgument5);
                    relatedMoby->unknown3[0] = 1;
                    relatedMoby->lowDrawDistance = 0x20;
                    relatedMoby->drawn = 1;
                    Level43_7E46CRefreshMobySpatialGridAndBasis(relatedMoby, 7);
                    relatedMoby->angle.yaw = owner->angle.yaw;
                    relatedMoby->position.z += 0x100;
                    relatedMoby->position.z = Level43_7E46C_func_8001A358(relatedPosition, 0x400);
                    relatedMoby->state = 5;
                    Level43_7E46CSetMobyAnimation(relatedMoby, 5);
                    Level43_7E46CField(ownerPrivate, Moby**, 0xC) = relatedMoby;
                    Level43_7E46CField(Level43_7E46CField(ownerPrivate, void**, 8), short*, 2) = 0;
                    Level43_7E46CField(Level43_7E46CField(ownerPrivate, void**, 8), short*, 0xA) =
                        1;
                    Level43_7E46CField(relatedMoby->mobyTag, void**, 8) =
                        (void*)Level43_7E46CField(ownerPrivate, void**, 8);
                    return;
                }
                if ((Level43_7E46CCountTimerDown(ownerPrivate, 2) != 0) &&
                    (savedHelperResult < 0x3000)) {
                    owner->state = 2;
                    argument4 = owner;
                    rawArgument5 = 2;
                    goto finalAnimationCall;
                }
            } else {
                default:
                    return;
            }
            break;
        case 1:
            if (Level43_7E46CCountTimerDown(ownerPrivate + 2, 2) != 0) {
                Level43_7E46CRequestMobyAnimation(owner, 0);
                owner->animationProgress = 0xF0;
                owner->state = 0x15;
                return;
            }
            break;
        case 21:
            relatedState3 = Level43_7E46CField(ownerPrivate, Moby**, 0xC)->state;
            if (relatedState3 == 0x52) {
                owner->state = 0x16;
                Level43_7E46CRequestMobyAnimation(owner, 1);
                owner->animationProgress = 0xF0;
                Level43_7E46CPlayMobySoundEvent(owner, 0, 0);
                return;
            }
            goto checkRelatedState50;
        case 22:
            if (Level43_7E46CApproximatePlanarDistance(
                    &owner->position, &Level43_7E46CField(ownerPrivate, Moby**, 0xC)->position) <
                0x1F4) {
                Level43_7E46CRequestMobyAnimation(owner, 0);
                Level43_7E46CPlayMobySoundEvent(owner, 1, 0);
                owner->animationProgress = 0xF0;
                owner->state = 0x17;
                return;
            }
            relatedState3 = Level43_7E46CField(ownerPrivate, Moby**, 0xC)->state;
        checkRelatedState50:
            if (relatedState3 == 0x50) {
                Level43_7E46CField(ownerPrivate, Moby**, 0xC) = 0;
                owner->state = 0;
                Level43_7E46CRequestMobyAnimation(owner, 0);
                Level43_7E46CField(ownerPrivate, short*, 2) = 5;
                return;
            }
            break;
        case 24:
            return;
        case 23:
            if (Level43_7E46CField(ownerPrivate, Moby**, 0xC)->lowDrawDistance == 0) {
                Level43_7E46CField(ownerPrivate, Moby**, 0xC) = 0;
                owner->state = 0;
                Level43_7E46CRequestMobyAnimation(owner, 0);
                Level43_7E46CField(ownerPrivate, short*, 2) = 0x3C;
                return;
            }
            break;
        case 2:
            Level43_7E46CCopyVector(&scratch.sp30, &Level43_7E46C_D_80070328.unk7a[3]);
            scratch.sp30.x = (int)scratch.sp30.x * 0x19;
            scratch.sp30.y *= 0x19;
            scratch.sp30.z *= 0x19;
            Level43_7E46CShiftVectorRightTowardZero(&scratch.sp30, 6);
            Level43_7E46CAddVector(
                &scratch.sp30, &scratch.sp30,
                (Vector3D*)((unsigned char*)&Level43_7E46C_D_80070328.unk7a[3] - 0x98));
            word2 = Level43_7E46CApproximatePlanarDistance(&owner->position, &scratch.sp30);
            predicate2 = word2 < 0x2800;
            argument4 = (Moby*)0x3C;
            if (predicate2)
                goto state2Reset;
            word2 = Level43_7E46C_D_8006C770;
            if (!word2)
                return;
        state2Reset:
            word2 = Level43_7E46CRandBetween(argument4, 0x78);
            argument4 = owner;
            rawArgument5 = 0;
            __asm__(""
                    : "=r"(argument4), "=r"(rawArgument5)
                    : "0"(argument4), "1"(rawArgument5), "r"(word2));
            Level43_7E46CField(ownerPrivate, short*, 0) = word2;
            __asm__ volatile("" : "=r"(state2Zero0));
            argument4->state = state2Zero0;
            goto finalAnimationCall;
        case 3:
            word2 = Level43_7E46C_func_80055E84(owner);
            word2 = (unsigned int)(word2 - 4) < 11U;
            if (!word2)
                return;
            word2 = Level43_7E46CApproximatePlanarDistance(&owner->position,
                                                           &Level43_7E46C_D_80070328.position);
            predicate2 = word2 < 0x1000;
            argument4 = owner;
            if (predicate2)
                goto state3Reset;
            MATCHING_BARRIER("$2");
            callbackFlags3 = 0x20004;
            MATCHING_OBSERVE(callbackFlags3);
            word2 =
                Level43_7E46C_func_80035A80(argument4, Level43_7E46CField(ownerPrivate, void**, 4),
                                            0x78, 0x5A, 0, 4, 0x20, callbackFlags3);
            predicate2 = word2 & 2;
            argument4 = owner;
            if (!predicate2)
                return;
        state3Reset:
            rawArgument5 = 0;
            word2 = 0x3C;
            __asm__(""
                    : "=r"(argument4), "=r"(rawArgument5)
                    : "0"(argument4), "1"(rawArgument5), "r"(ownerPrivate));
            MATCHING_KEEP(word2);
            Level43_7E46CField(ownerPrivate, short*, 0) = word2;
            __asm__ volatile("" : "=r"(state3Zero0));
            argument4->state = state3Zero0;
            goto finalAnimationCall;
        case 20:
            word2 = Level43_7E46C_func_80036220(&Level43_7E46C_D_80070328, ownerPrivate + 0x14, 0,
                                                0x2800);
            if (!word2)
                return;
            relatedPrivate2 = Level43_7E46CField(ownerPrivate, void**, 4);
            argument4 = owner;
            if (relatedPrivate2)
                goto state20Set3;
            MATCHING_BARRIER("$2");
            rawArgument5 = 0;
            word2 = 0x3C;
            __asm__(""
                    : "=r"(argument4), "=r"(rawArgument5)
                    : "0"(argument4), "1"(rawArgument5), "r"(relatedPrivate2));
            MATCHING_KEEP(word2);
            Level43_7E46CField(ownerPrivate, short*, 0) = word2;
            argument4->state = 0;
            goto finalAnimationCall;
        state20Set3:
            rawArgument5 = 3;
            Level43_7E46CField(relatedPrivate2, short*, 2) = 0;
            Level43_7E46CField(Level43_7E46CField(ownerPrivate, void**, 4), short*, 0xA) = 1;
            argument4->state = 3;
            goto finalAnimationCall;
    }
    return;
finalAnimationCall:
    Level43_7E46CRequestMobyAnimation(argument4, rawArgument5);
}
#undef Level43_7E46CField

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007EB88:324 instructions, seven dispatch words and padding, original4662.
 * Verified13/11/36 helper shapes reused only where original agrees. Raw fields;
 * units, helper contracts, cadence and runtime parity unresolved. */
#define A43Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* A43Active __asm__("D_8006E164");
extern int A43Type __asm__("D_8006E160");
extern unsigned char* A43Pool __asm__("D_8006C550");
extern unsigned char A43Player[] __asm__("D_80070328");
extern int A43Contact __asm__("D_8006C770");
int A43CountTimerDown() __asm__("func_800359A4");
int A43RequestMobyAnimation() __asm__("func_80034F40");
int A43Helper55E84() __asm__("func_80055E84");
int A43Helper35194() __asm__("func_80035194");
int A43RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int A43Helper3BA00() __asm__("func_8003BA00");
int A43Helper369B8() __asm__("func_800369B8");
int A43DeleteMoby() __asm__("func_80055B18");
extern void* (*A43SpawnMoby)(int, void*)__asm__("SpawnMoby");
int A43TurnMobyTowardPlayer() __asm__("func_8003573C");
int A43ApproximatePlanarDistance() __asm__("func_8004F334");
int A43H38BF8() __asm__("func_80038BF8");
int A43PlanarHeadingLookup() __asm__("func_8004E880");
int A43AbsoluteByteAngleDelta() __asm__("func_8004F264");
int A43H4E790() __asm__("func_8004E790");
int A43H1BA30() __asm__("func_8001BA30");
int A43CopyVector() __asm__("func_8004F178");
int A43H35DDC() __asm__("func_80035DDC");
extern unsigned char A43Vector[] __asm__("D_8007190C");
void func_level_43_8007EB88(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$19");
    register unsigned char* temporary16 __asm__("$16");
    register unsigned char* player18 __asm__("$18");
    register int distance16 __asm__("$16");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    MATCHING_KEEP(owner);
    value = owner[73];
    tag = A43Field(owner, unsigned char**, 0);
    if (!value) {
        A43RequestMobyAnimation(input, 2);
        if (!(A43Pool + A43Field(tag, int*, 4) * 88)[73])
            goto done;
        owner[72] = 2;
        A43Field(owner, int*, 24) = 0;
        owner[73] = 1;
    }
    if (owner[72] != 6 && (A43Field(owner, int*, 24) & 0x8B0000)) {
        unsigned char* linkedTag;
        linkedTag = A43Field(A43Pool + A43Field(tag, int*, 4) * 88, unsigned char**, 0);
        temporary16 = A43Field(owner, unsigned char**, 0);
        A43Field(linkedTag, int*, 0)++;
        A43H4E790(temporary16, 0, 24);
        A43H38BF8(owner, temporary16, 1, 6);
        A43Field(temporary16, short*, 10) = 300;
        A43Field(temporary16, short*, 12) = 1;
        temporary16[14] = 12;
        temporary16[15] = 16;
    }
    if ((unsigned int)(owner[72] - 5) >= 2) {
        temporary16 = owner + 12;
        if (A43H1BA30(temporary16, 800, 0, 0, 0, owner))
            A43CopyVector(temporary16, A43Vector);
    }
    switch (owner[72]) {
        case 0:
            value = A43TurnMobyTowardPlayer(owner, 4, 1, 1);
            call4 = owner;
            if (value)
                A43H35DDC(call4, 70, 0, 0, 0);
            if (A43ApproximatePlanarDistance(owner + 12, A43Player) < 3100) {
                owner[72] = 1;
                A43RequestMobyAnimation(owner, 1);
            }
            break;
        case 1:
            A43TurnMobyTowardPlayer(owner, 4, 1, 1);
            call4 = owner;
            if (A43Contact) {
                owner[72] = 2;
                A43RequestMobyAnimation(call4, 2);
                A43Field(tag, short*, 0) = 30;
            }
            call4 = owner + 12;
            MATCHING_KEEP(call4);
            temporary16 = A43Player;
            if (A43ApproximatePlanarDistance(call4, temporary16) >= 3100)
                goto done;
            arg6 = 0;
            other = A43Field(temporary16, int*, 0);
            goto angle;
        case 2:
            A43TurnMobyTowardPlayer(owner, 4, 1, 1);
            call4 = owner + 12;
            MATCHING_KEEP(call4);
            player18 = A43Player;
            value = A43ApproximatePlanarDistance(call4, player18);
            call4 = tag + 2;
            arg5 = 2;
            MATCHING_KEEP(arg5);
            distance16 = value;
            value = A43CountTimerDown(call4, arg5);
            if (!value)
                goto done;
            value = distance16 < 3100;
            MATCHING_KEEP(value);
            if (!value)
                goto done;
            arg6 = 0;
            other = A43Field(player18, int*, 0);
        angle:
            value = A43PlanarHeadingLookup(other - A43Field(owner, int*, 12),
                                           A43Field(A43Player, int*, 4) - A43Field(owner, int*, 16),
                                           arg6);
            if (A43AbsoluteByteAngleDelta(value, owner[70]) < 10) {
                owner[72] = 3;
                A43RequestMobyAnimation(owner, 3);
            }
            break;
        case 3:
            A43TurnMobyTowardPlayer(owner, 4, 1, 1);
            if (owner[73] == 2)
                goto contact3;
            if (owner[60] != 3)
                goto contact3;
            if (A43Helper55E84(owner) < 21)
                goto contact3;
            if (A43Helper55E84(owner) >= 23)
                goto contact3;
            temporary16 = A43Player + 576;
            MATCHING_KEEP(temporary16);
            if (A43Field(temporary16, int*, 0))
                goto contact3;
            value = A43PlanarHeadingLookup(
                A43Field(temporary16, int*, -576) - A43Field(owner, int*, 12),
                A43Field(A43Player, int*, 4) - A43Field(owner, int*, 16), 0);
            value = A43AbsoluteByteAngleDelta(owner[70], value);
            player18 = temporary16 - 576;
            if (value >= 8)
                goto contact3;
            if (A43ApproximatePlanarDistance(owner + 12, player18) >= 3100)
                goto contact3;
            other = A43Field(temporary16, int*, -540);
            value = owner[70];
            other |= 7;
            A43Field(temporary16, int*, 88) = value;
            A43Field(temporary16, int*, -540) = other;
            owner[73] = 2;
        contact3:
            if (!A43Contact)
                goto done;
            other = owner[73];
            call4 = owner;
            if (other == 2)
                A43Field(tag, short*, 2) = 50;
            arg5 = 2;
            ((unsigned char*)call4)[73] = 1;
            ((unsigned char*)call4)[72] = 2;
            A43RequestMobyAnimation(call4, arg5);
            break;
        case 4:
            call4 = owner;
            if (A43Contact) {
                owner[72] = 0;
                A43RequestMobyAnimation(call4, 0);
            }
            break;
        case 5:
            value = A43Helper55E84(owner);
            call4 = owner;
            if ((unsigned int)(value - 4) < 15)
                A43H35DDC(call4, 100, 0, 0, 0);
            if (A43Contact) {
                owner[72] = 2;
                A43RequestMobyAnimation(owner, 2);
            }
            break;
        case 6:
            value = A43Helper35194(owner, A43Field(owner, void**, 0));
            call4 = owner;
            if (value != 256)
                goto done;
            A43RefreshMobySpatialGridAndBasis(call4, 4);
            if (owner[58] == 255)
                A43Helper3BA00(owner);
            A43Helper369B8(owner, 32);
            A43DeleteMoby(owner);
            break;
    }
done:;
}
#undef A43Field

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007F098..8007F374. Rev1 raw478 discovery; original access widths,
 * fresh pool/private reloads and numeric call order control the port.
 * Pool/child validity, helper contracts and live cadence remain open. */
typedef struct {
    int timer, index, fragmentArgument;
    Moby* child;
} DecodedHaunted478Tag;
extern Moby* D_8006C550;
void func_80034F80(Moby*, int);
void func_8003BA00(Moby*);
#define SELECTED478()                                    \
    ({                                                   \
        register int index __asm__("$3") = tag->index;   \
        register int offset __asm__("$2") = index * 11;  \
        register Moby* pool __asm__("$3");               \
        register Moby* selected __asm__("$2");           \
        __asm__("" : "=r"(offset) : "0"(offset));        \
        pool = D_8006C550;                               \
        offset <<= 3;                                    \
        selected = (Moby*)(offset + (unsigned int)pool); \
        __asm__("" : "=r"(selected) : "0"(selected));    \
        selected;                                        \
    })
void func_level_43_8007F098(Moby* argument) {
    register Moby* moby __asm__("$18") = argument;
    register DecodedHaunted478Tag* tag __asm__("$19") = moby->mobyTag;
    register Moby* child __asm__("$17");
    register int one __asm__("$16");
    register int* nested __asm__("$3");
    if (!moby->substate) {
        if (!SELECTED478()->substate)
            return;
        moby->substate = 1;
        moby->damageFlags = 0;
        tag->timer = 120;
    }
    /* Retail reloads the owner argument after the activation gate. */
    MATCHING_BARRIER("$4");
    if (moby->damageFlags) {
        register Moby* prepared __asm__("$4") = moby;
        nested = SELECTED478()->mobyTag;
        (*nested)++;
        func_8003BABC(prepared, 2, 0);
        SpawnFragments(5, 476, moby, tag->fragmentArgument, 0, 256);
        func_80055D24(moby, 4);
        func_8003BA00(moby);
        func_800369B8(moby, 56);
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
        case 0:
            if (tag->child && !(tag->child->state & 128))
                return;
            if (!func_800359A4(tag, 4))
                return;
            {
                register int* counter __asm__("$2") = SELECTED478()->mobyTag;
                if (*counter <= 0)
                    return;
            }
            child = SpawnMoby(477, moby);
            MATCHING_KEEP(child);
            one = 1;
            if (!child)
                return;
            nested = SELECTED478()->mobyTag;
            (*nested)--;
            /* Keep counter publication before child initialization. */
            __asm__ volatile("" : : : "memory", "$2");
            {
                register int heading __asm__("$3") = *(volatile unsigned char*)&moby->angle.yaw;
                register int state __asm__("$2") = 5;
                MATCHING_KEEP2(heading, state);
                child->state = state;
                MATCHING_BARRIER_VOLATILE("memory");
                child->substate = one;
                MATCHING_BARRIER_VOLATILE("memory");
                child->angle.yaw = heading;
            }
            ((DecodedHaunted478Tag*)child->mobyTag)->index = tag->index;
            func_80034F80(child, child->state);
            moby->state = one;
            func_80034F40(moby, 1);
            func_8003BABC(moby, 0, 0);
            moby->animationProgress = 240;
            tag->child = child;
            tag->timer = 30;
            break;
        case 1:
            if (func_800359A4(tag, 4)) {
                tag->timer = func_8003636C(100, 200);
                moby->state = 0;
                func_80034F40(moby, 0);
                func_8003BABC(moby, 1, 0);
                moby->animationProgress = 240;
            }
            break;
    }
}
#undef SELECTED478

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original1626 words. AI generated, not human reviewed; uninstalled. */
#define Level43_7F378Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level43_7F378Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level43_7F378_func_80013D44() __asm__("func_80013D44");
int Level43_7F378_func_80021ED8() __asm__("func_80021ED8");
int Level43_7F378_func_80021F3C() __asm__("func_80021F3C");
int Level43_7F378_func_8002803C() __asm__("func_8002803C");
int Level43_7F378_func_80028154() __asm__("func_80028154");
int Level43_7F378RequestMobyAnimation() __asm__("func_80034F40");
int Level43_7F378TurnMobyTowardHeading() __asm__("func_8003585C");
int Level43_7F378CountTimerDown() __asm__("func_800359A4");
int Level43_7F378_func_80035A80() __asm__("func_80035A80");
int Level43_7F378_func_80036220() __asm__("func_80036220");
int Level43_7F378_func_80037BBC() __asm__("func_80037BBC");
int Level43_7F378_func_8003B7B4() __asm__("func_8003B7B4");
int Level43_7F378_func_8003BA00() __asm__("func_8003BA00");
int Level43_7F378PlanarHeadingLookup() __asm__("func_8004E880");
int Level43_7F378CopyVector() __asm__("func_8004F178");
int Level43_7F378AddVector() __asm__("func_8004F194");
int Level43_7F378AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Level43_7F378ApproximatePlanarDistance() __asm__("func_8004F334");
int Level43_7F378_func_800512E4() __asm__("func_800512E4");
int Level43_7F378DeleteMoby() __asm__("func_80055B18");
extern int Level43_7F378_D_800658A0 __asm__("D_800658A0");
extern int Level43_7F378_D_80065920 __asm__("D_80065920");
extern int Level43_7F378_D_8006C550 __asm__("D_8006C550");
extern int Level43_7F378_D_8006C58C __asm__("D_8006C58C");
extern int Level43_7F378_D_8006C598 __asm__("D_8006C598");
extern int Level43_7F378_D_8006C640 __asm__("D_8006C640");
extern int Level43_7F378_D_8006C730 __asm__("D_8006C730");
extern int Level43_7F378_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level43_7F378_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level43_7F378_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level43_7F378_D_8006D088 __asm__("D_8006D088");
extern int Level43_7F378_D_8006E044 __asm__("D_8006E044");
extern int Level43_7F378_D_8006E048 __asm__("D_8006E048");
extern int Level43_7F378_D_8006E160 __asm__("D_8006E160");
extern int Level43_7F378_D_8006E168 __asm__("D_8006E168");
extern int Level43_7F378_D_8006E344 __asm__("D_8006E344");
extern int Level43_7F378_D_80070300 __asm__("D_80070300");
extern int Level43_7F378_D_80070328 __asm__("D_80070328");
extern int Level43_7F378_D_800716B0 __asm__("D_800716B0");
extern int Level43_7F378_func_80027A60 __asm__("func_80027A60");
extern int Level43_7F378_func_80027EE4 __asm__("func_80027EE4");
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Level43_7F378Product;
#define Level43_7F378Low(a, b)                    \
    ({                                            \
        int x = (a), y = (b);                     \
        Level43_7F378Product p;                   \
        p.full = (long long)x * (long long)y;     \
        __asm__("" : "=x"(p.full) : "0"(p.full)); \
        (int)p.words.low;                         \
    })
extern int Level43_7F378_func_80029AA0 __asm__("func_80029AA0");
void func_level_43_8007F378(void* ownerInput) {
    register int temporary2 __asm__("$2");
    register int temporary3 __asm__("$3");
    register int argument0 __asm__("$4");
    register int argument1 __asm__("$5");
    register int argument2 __asm__("$6");
    register int argument3 __asm__("$7");
    register int temporary8 __asm__("$8");
    register int temporary9 __asm__("$9");
    register int temporary10 __asm__("$10");
    register int temporary11 __asm__("$11");
    register int temporary12 __asm__("$12");
    register int temporary13 __asm__("$13");
    register int temporary14 __asm__("$14");
    register int temporary15 __asm__("$15");
    register int saved16 __asm__("$16");
    register int saved17 __asm__("$17");
    register int privateState __asm__("$18");
    register int owner __asm__("$19");
    register int selectedPoint __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int saved23 __asm__("$23");
    register int temporary24 __asm__("$24");
    register int temporary25 __asm__("$25");
    int nearestDistance, stackArgument4, stackArgument5, stackArgument6, stackArgument7;
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
    } locals;
    owner = (int)ownerInput;
    Level43_7F378Keep(owner);
    argument0 = (int)ownerInput;
    temporary2 = Level43_7F378Field(owner, int*, 24);
    Level43_7F378Keep(temporary2);
    privateState = Level43_7F378Field(owner, int*, 0);
    Level43_7F378Keep(privateState);
    if (temporary2 == 0 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original1626_30;
    argument1 = Level43_7F378Field(owner, unsigned char*, 72);
    Level43_7F378Keep(argument1);

    temporary3 = argument1 & 255;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 1, 1) : (temporary2 = 0 + 1, 0))
        goto original1626_30;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 25, 1) : (temporary2 = 0 + 25, 0))
        goto original1626_30;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 29, 1) : (temporary2 = 0 + 29, 0))
        goto original1626_30;
    if (temporary3 == temporary2)
        goto original1626_30;
    Level43_7F378Field(privateState, unsigned char*, 82) = argument1;
    temporary2 = Level43_7F378Field(owner, unsigned char*, 61);
    Level43_7F378Keep(temporary2);
    argument1 = 0 + 3;
    Level43_7F378Keep(argument1);
    Level43_7F378Field(privateState, unsigned char*, 83) = temporary2;
    temporary2 = 0 + 3;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    Level43_7F378RequestMobyAnimation(argument0, argument1);
original1626_30:
    temporary3 = Level43_7F378Field(owner, unsigned char*, 72);
    Level43_7F378Keep(temporary3);

    switch ((unsigned int)temporary3) {
        case 0:
            goto original1626_78;
        case 1:
            goto original1626_255;
        case 2:
            goto original1626_521;
        case 3:
            goto original1626_537;
        case 4:
            goto original1626Return;
        case 5:
            goto original1626Return;
        case 6:
            goto original1626Return;
        case 7:
            goto original1626Return;
        case 8:
            goto original1626Return;
        case 9:
            goto original1626Return;
        case 10:
            goto original1626Return;
        case 11:
            goto original1626Return;
        case 12:
            goto original1626Return;
        case 13:
            goto original1626Return;
        case 14:
            goto original1626Return;
        case 15:
            goto original1626Return;
        case 16:
            goto original1626Return;
        case 17:
            goto original1626Return;
        case 18:
            goto original1626Return;
        case 19:
            goto original1626Return;
        case 20:
            goto original1626_1499;
        case 21:
            goto original1626_1566;
        case 22:
            goto original1626_1615;
        case 23:
            goto original1626_783;
        case 24:
            goto original1626_721;
        case 25:
            goto original1626_891;
        case 26:
            goto original1626_1101;
        case 27:
            goto original1626_1244;
        case 28:
            goto original1626_1441;
        case 29:
            goto original1626_1481;
        case 30:
            goto original1626Return;
        case 31:
            goto original1626_73;
        case 32:
            goto original1626_1013;
        case 33:
            goto original1626_1017;
        case 34:
            goto original1626_1070;
        case 35:
            goto original1626Return;
        case 36:
            goto original1626_491;
        case 37:
            goto original1626Return;
        case 38:
            goto original1626Return;
        case 39:
            goto original1626Return;
        case 40:
            goto original1626_41;
        case 41:
            goto original1626Return;
        case 42:
            goto original1626_661;
        case 43:
            goto original1626Return;
        case 44:
            goto original1626_1381;
        case 45:
            goto original1626Return;
        case 46:
            goto original1626Return;
        case 47:
            goto original1626Return;
        case 48:
            goto original1626Return;
        case 49:
            goto original1626Return;
        case 50:
            goto original1626Return;
        case 51:
            goto original1626Return;
        case 52:
            goto original1626Return;
        case 53:
            goto original1626Return;
        case 54:
            goto original1626Return;
        case 55:
            goto original1626Return;
        case 56:
            goto original1626Return;
        case 57:
            goto original1626Return;
        case 58:
            goto original1626Return;
        case 59:
            goto original1626Return;
        case 60:
            goto original1626Return;
        case 61:
            goto original1626Return;
        case 62:
            goto original1626Return;
        case 63:
            goto original1626Return;
        case 64:
            goto original1626Return;
        case 65:
            goto original1626Return;
        case 66:
            goto original1626Return;
        case 67:
            goto original1626Return;
        case 68:
            goto original1626Return;
        case 69:
            goto original1626Return;
        case 70:
            goto original1626Return;
        case 71:
            goto original1626Return;
        case 72:
            goto original1626Return;
        case 73:
            goto original1626Return;
        case 74:
            goto original1626Return;
        case 75:
            goto original1626Return;
        case 76:
            goto original1626Return;
        case 77:
            goto original1626Return;
        case 78:
            goto original1626Return;
        case 79:
            goto original1626Return;
        case 80:
            goto original1626_550;
        case 81:
            goto original1626Return;
        case 82:
            goto original1626_1268;
        default:
            goto original1626Return;
    }
original1626_41:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 & 16;
    if (temporary2 != 0 ? (temporary2 = 0 + 1, 1) : (temporary2 = 0 + 1, 0))
        goto original1626_70;
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006C58C, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 =
        Level43_7F378Field(((int)&Level43_7F378_D_80070300 + temporary3), unsigned char*, 0);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 & 16;
    if (temporary2 != 0 ? (temporary2 = 0 + 1, 1) : (temporary2 = 0 + 1, 0))
        goto original1626_70;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    argument0 = (int)((unsigned int)temporary2 << 1);

    temporary3 =
        Level43_7F378Field(((int)&Level43_7F378_D_800716B0 + argument0), unsigned char*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = (unsigned int)temporary3 < 255;
    if (temporary2 == 0 ? (temporary2 = temporary3 + 1, 1) : (temporary2 = temporary3 + 1, 0))
        goto original1626_69;

    Level43_7F378Field(((int)&Level43_7F378_D_800716B0 + argument0), unsigned char*, 0) =
        temporary2;
original1626_69:
    temporary2 = 0 + 1;
original1626_70:
    Level43_7F378Field(owner, unsigned char*, 72) = 0;
    Level43_7F378Field(privateState, unsigned char*, 5) = temporary2;
    goto original1626Return;
original1626_73:
    temporary2 = 0 + 7;
    Level43_7F378Field(owner, unsigned char*, 72) = 0;
    Level43_7F378Field(privateState, unsigned char*, 2) = temporary2;
    temporary2 = 0 + 1;
    Level43_7F378Field(privateState, unsigned char*, 5) = temporary2;
original1626_78:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C640, int*, 0);
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(temporary3));

    selectedPoint = 0 + 0;
    if (temporary2 != 0)
        goto original1626_118;
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = 0 + 3;
    if (temporary3 == 0)
        goto original1626_89;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1626_120;
original1626_89:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 & 1;
    if (temporary2 != 0)
        goto original1626_104;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C58C, int*, 0);
    Level43_7F378Keep(temporary2);

    temporary2 =
        Level43_7F378Field(((int)&Level43_7F378_D_80070300 + temporary2), unsigned char*, 0);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 & 1;
    if (temporary2 == 0)
        goto original1626_118;
original1626_104:
    argument0 = 0 + 3;
    temporary2 = Level43_7F378_func_80021F3C(argument0);
    temporary3 = temporary2 + 0;
    temporary2 = (temporary3 >> 8);
    temporary2 = temporary2 & 255;
    if (temporary2 != 0 ? (temporary2 = temporary3 & 15, 1) : (temporary2 = temporary3 & 15, 0))
        goto original1626_1615;
    argument0 = 0 + 3;
    if (temporary2 == 0)
        goto original1626_1615;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);

    goto original1626_1615;
original1626_118:
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 2;
original1626_120:
    if (temporary3 != temporary2)
        goto original1626_216;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C598, int*, 0);
    Level43_7F378Keep(temporary2);

    if (temporary2 != 0)
        goto original1626_216;
    saved17 = (int)&Level43_7F378_D_80070328;
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_136;
    temporary2 = 0 - temporary2;
original1626_136:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_216;
    temporary2 = Level43_7F378Field(owner, int*, 16);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_147;
    temporary2 = 0 - temporary2;
original1626_147:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_216;
    temporary2 = Level43_7F378Field(owner, int*, 20);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 8);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_158;
    temporary2 = 0 - temporary2;
original1626_158:
    temporary2 = temporary2 < 3072;
    argument0 = saved17 + 0;
    if (temporary2 == 0)
        goto original1626_216;
    saved16 = privateState + 92;
    argument1 = saved16 + 0;
    argument2 = 0 + 0;
    argument3 = 0 + 10240;
    temporary2 = Level43_7F378_func_80036220(argument0, argument1, argument2, argument3);
    if (temporary2 != 0)
        goto original1626_216;
    argument3 = Level43_7F378Field(privateState, int*, 92);
    Level43_7F378Keep(argument3);
    argument2 = Level43_7F378Field(privateState, int*, 104);
    Level43_7F378Keep(argument2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);
    argument0 = argument3 + argument2;
    temporary2 = argument0 < temporary3;
    argument1 = saved16 + 0;
    if (temporary2 != 0)
        goto original1626_179;
    argument0 = argument3 - argument2;
    temporary2 = temporary3 < argument0;
    if (temporary2 == 0)
        goto original1626_182;
original1626_179:
    temporary2 = argument0 - temporary3;
    Level43_7F378Field(&locals.sp20, int*, 0) = temporary2;
    goto original1626_183;
original1626_182:
    Level43_7F378Field(&locals.sp20, int*, 0) = 0;
original1626_183:
    argument2 = Level43_7F378Field(argument1, int*, 4);
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(argument1, int*, 16);
    Level43_7F378Keep(argument1);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);
    argument0 = argument2 + argument1;
    temporary2 = argument0 < temporary3;
    if (temporary2 == 0 ? (temporary2 = argument0 - temporary3, 1)
                        : (temporary2 = argument0 - temporary3, 0))
        goto original1626_193;
    Level43_7F378Field(&locals.sp20, int*, 4) = temporary2;
    goto original1626_200;
original1626_193:
    argument1 = argument2 - argument1;
    temporary2 = temporary3 < argument1;
    if (temporary2 == 0 ? (temporary2 = argument1 - temporary3, 1)
                        : (temporary2 = argument1 - temporary3, 0))
        goto original1626_199;
    Level43_7F378Field(&locals.sp20, int*, 4) = temporary2;
    goto original1626_200;
original1626_199:
    Level43_7F378Field(&locals.sp20, int*, 4) = 0;
original1626_200:
    argument2 = (int)0x10000000U;
    argument2 = argument2 | 8;
    selectedPoint = 0 + 1;
    temporary3 = (int)&Level43_7F378_D_80070328 + 524;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 548, int*, 0) = 0;
    temporary2 = Level43_7F378Field(temporary3, int*, 0);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field(&locals.sp20, int*, 0);
    Level43_7F378Keep(argument0);
    argument1 = Level43_7F378Field(&locals.sp20, int*, 4);
    Level43_7F378Keep(argument1);
    temporary2 = temporary2 | argument2;
    Level43_7F378Field(temporary3, int*, 0) = temporary2;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 540, int*, 0) = argument0;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 544, int*, 0) = argument1;
original1626_216:
    argument0 = (int)0x00FF0000U;
    if (selectedPoint != 0)
        goto original1626_223;
    Level43_7F378Keep(selectedPoint);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = Level43_7F378_func_80037BBC(argument0, argument1);
    argument0 = (int)0x00FF0000U;
    if (temporary2 == 0)
        goto original1626Return;
original1626_223:
    argument0 = argument0 | 255;
    temporary3 = (int)0x00020000U;
    Level43_7F378Keep(temporary3);
    temporary2 = Level43_7F378Field(privateState, int*, 0);
    Level43_7F378Keep(temporary2);
    temporary3 = temporary3 | 3;
    temporary2 = temporary2 & argument0;
    argument0 = owner + 0;
    if (temporary2 != temporary3)
        goto original1626_249;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 | 1;

    Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0) = temporary2;
    argument0 = 0 + 3;
    temporary2 = Level43_7F378_func_80021F3C(argument0);
    temporary3 = temporary2 + 0;
    temporary2 = (temporary3 >> 8);
    temporary2 = temporary2 & 255;
    if (temporary2 != 0 ? (temporary2 = temporary3 & 15, 1) : (temporary2 = temporary3 & 15, 0))
        goto original1626_248;
    argument0 = 0 + 3;
    if (temporary2 == 0)
        goto original1626_248;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
original1626_248:
    argument0 = owner + 0;
original1626_249:
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level43_7F378_func_800512E4(argument0, argument1, argument2);
    temporary2 = 0 + 1;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_255:
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 2;
    if (temporary3 != temporary2)
        goto original1626_352;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C598, int*, 0);
    Level43_7F378Keep(temporary2);

    if (temporary2 != 0)
        goto original1626_352;
    saved17 = (int)&Level43_7F378_D_80070328;
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_273;
    temporary2 = 0 - temporary2;
original1626_273:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_352;
    temporary2 = Level43_7F378Field(owner, int*, 16);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_284;
    temporary2 = 0 - temporary2;
original1626_284:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_352;
    temporary2 = Level43_7F378Field(owner, int*, 20);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 8);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_295;
    temporary2 = 0 - temporary2;
original1626_295:
    temporary2 = temporary2 < 3072;
    argument0 = saved17 + 0;
    if (temporary2 == 0)
        goto original1626_352;
    saved16 = privateState + 92;
    argument1 = saved16 + 0;
    argument2 = 0 + 0;
    argument3 = 0 + 10240;
    temporary2 = Level43_7F378_func_80036220(argument0, argument1, argument2, argument3);
    if (temporary2 != 0)
        goto original1626_352;
    argument3 = Level43_7F378Field(privateState, int*, 92);
    Level43_7F378Keep(argument3);
    argument2 = Level43_7F378Field(privateState, int*, 104);
    Level43_7F378Keep(argument2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);
    argument0 = argument3 + argument2;
    temporary2 = argument0 < temporary3;
    argument1 = saved16 + 0;
    if (temporary2 != 0)
        goto original1626_316;
    argument0 = argument3 - argument2;
    temporary2 = temporary3 < argument0;
    if (temporary2 == 0)
        goto original1626_319;
original1626_316:
    temporary2 = argument0 - temporary3;
    Level43_7F378Field(&locals.sp20, int*, 0) = temporary2;
    goto original1626_320;
original1626_319:
    Level43_7F378Field(&locals.sp20, int*, 0) = 0;
original1626_320:
    argument2 = Level43_7F378Field(argument1, int*, 4);
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(argument1, int*, 16);
    Level43_7F378Keep(argument1);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);
    argument0 = argument2 + argument1;
    temporary2 = argument0 < temporary3;
    if (temporary2 == 0 ? (temporary2 = argument0 - temporary3, 1)
                        : (temporary2 = argument0 - temporary3, 0))
        goto original1626_330;
    Level43_7F378Field(&locals.sp20, int*, 4) = temporary2;
    goto original1626_337;
original1626_330:
    argument1 = argument2 - argument1;
    temporary2 = temporary3 < argument1;
    if (temporary2 == 0 ? (temporary2 = argument1 - temporary3, 1)
                        : (temporary2 = argument1 - temporary3, 0))
        goto original1626_336;
    Level43_7F378Field(&locals.sp20, int*, 4) = temporary2;
    goto original1626_337;
original1626_336:
    Level43_7F378Field(&locals.sp20, int*, 4) = 0;
original1626_337:
    argument2 = (int)0x10000000U;
    argument2 = argument2 | 8;
    temporary3 = (int)&Level43_7F378_D_80070328 + 524;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 548, int*, 0) = 0;
    temporary2 = Level43_7F378Field(temporary3, int*, 0);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field(&locals.sp20, int*, 0);
    Level43_7F378Keep(argument0);
    argument1 = Level43_7F378Field(&locals.sp20, int*, 4);
    Level43_7F378Keep(argument1);
    temporary2 = temporary2 | argument2;
    Level43_7F378Field(temporary3, int*, 0) = temporary2;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 540, int*, 0) = argument0;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 544, int*, 0) = argument1;
original1626_352:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006E344, int*, 0);
    Level43_7F378Keep(temporary2);
    saved16 = 0 + 1;
    argument0 = owner + 0;
    if (temporary2 == saved16)
        goto original1626Return;
    argument1 = 0 + 0;
    Level43_7F378Field(owner, int*, 24) = 0;
    Level43_7F378Field(owner, unsigned char*, 72) = 0;
    Level43_7F378RequestMobyAnimation(argument0, argument1);
    argument1 = Level43_7F378Field(privateState, unsigned char*, 0);
    Level43_7F378Keep(argument1);
    temporary2 = 0 + 3;
    if (argument1 != temporary2 ? (temporary2 = 0 + 5, 1) : (temporary2 = 0 + 5, 0))
        goto original1626_393;
    argument0 = Level43_7F378Field(privateState, unsigned char*, 4);
    Level43_7F378Keep(argument0);

    temporary3 = argument0 & 15;
    if (temporary3 == temporary2 ? (temporary3 = argument0 & 255, 1)
                                 : (temporary3 = argument0 & 255, 0))
        goto original1626_372;
    if (temporary3 != saved16)
        goto original1626_378;
original1626_372:
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = 0 + 2;
    Level43_7F378Field(privateState, unsigned char*, 5) = temporary2;
    Level43_7F378Field(privateState, unsigned char*, 2) = temporary2;
    goto original1626_445;
original1626_378:
    temporary2 = 0 + 2;
    if (temporary3 == argument1)
        goto original1626_401;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1626_389;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(temporary2, "$3");
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = 0 + 2;
    Level43_7F378Field(privateState, unsigned char*, 5) = temporary2;
    temporary2 = 0 + 4;
    Level43_7F378Field(privateState, unsigned char*, 2) = temporary2;
    goto original1626_445;
original1626_389:
    if (temporary3 != temporary2 ? (temporary2 = 0 + 36, 1) : (temporary2 = 0 + 36, 0))
        goto original1626_393;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_393:
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1626_436;
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 4);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 3;
    saved16 = owner + 72;
    if (temporary3 != temporary2)
        goto original1626_407;
original1626_401:
    Level43_7F378Field(owner, unsigned char*, 72) = 0;
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level43_7F378RequestMobyAnimation(argument0, argument1);

    goto original1626Return;
original1626_407:
    argument0 = saved16 + 0;
    Level43_7F378Keep(argument0);
    argument1 = 0 + 1;
    Level43_7F378Keep(argument1);
    argument2 = (int)&Level43_7F378_D_8006D088;
    Level43_7F378Keep(argument2);
    temporary2 = 0 + 40;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    argument2 = (int)&Level43_7F378_D_8006C7F8;
    argument1 = 0 + 1;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    temporary2 = 0 + 255;
    Level43_7F378Field(owner, unsigned char*, 74) = temporary2;
    temporary2 = 0 + 20;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    temporary3 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 4;
    Level43_7F378Field(temporary2, unsigned char*, 72) = temporary3;
    goto original1626Return;
original1626_436:
    if (temporary3 != temporary2 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original1626Return;
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 4);
    Level43_7F378Keep(temporary3);

    argument0 = (int)&locals.sp20;
    if (temporary3 != temporary2)
        goto original1626_449;
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level43_7F378Field(privateState, unsigned char*, 5) = 0;
original1626_445:
    Level43_7F378Field(argument0, unsigned char*, 72) = 0;
    Level43_7F378RequestMobyAnimation(argument0, argument1);

    goto original1626Return;
original1626_449:
    temporary3 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary3);
    saved16 = (int)0x80070000U;
    Level43_7F378Keep(saved16);
    saved16 = Level43_7F378Field(saved16, int*, -15024);
    Level43_7F378Keep(saved16);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = saved16 + temporary2;
    argument1 = saved16 + 12;
    Level43_7F378CopyVector(argument0, argument1);
    argument0 = (int)&locals.sp20;
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(&locals.sp20, int*, 8);
    Level43_7F378Keep(temporary2);
    argument2 = 0 + 0;
    Level43_7F378Keep(argument2);
    temporary2 = temporary2 + 400;
    Level43_7F378Field(&locals.sp20, int*, 8) = temporary2;
    argument1 = Level43_7F378Field(saved16, unsigned char*, 70);
    Level43_7F378Keep(argument1);
    argument3 = 0 + 0;
    Level43_7F378_func_80013D44(argument0, argument1, argument2, argument3);
    temporary3 = (int)0x10000000U;
    temporary3 = temporary3 | 2;
    argument0 = 0 + 23;
    Level43_7F378Keep(argument0);
    argument2 = (int)&Level43_7F378_func_80027EE4;
    Level43_7F378Keep(argument2);
    temporary2 = 0 + 2;
    Level43_7F378Field(saved16, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 255;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 524, int*, 0) = temporary3;
    Level43_7F378Field(owner, unsigned char*, 74) = temporary2;
    temporary2 = 0 + 60;
    Level43_7F378Field(privateState, short*, 80) = temporary2;
    temporary2 = 0 + 80;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;

    argument1 = 0 + 430;
    argument3 = (int)&Level43_7F378_func_80027A60;
    temporary2 = Level43_7F378_func_8002803C(argument0, argument1, argument2, argument3,
                                             (int)&Level43_7F378_func_80029AA0, privateState + 72,
                                             (int)Level43_7F378Field(privateState, short*, 76));
    temporary2 = (int)((unsigned int)temporary2 << 16);
    temporary2 = (temporary2 >> 16);
    Level43_7F378Field(privateState, int*, 116) = temporary2;
    goto original1626Return;
original1626_491:
    temporary2 = Level43_7F378Field(privateState, int*, 88);
    Level43_7F378Keep(temporary2);

    temporary3 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary3);
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field(temporary3, int*, 0);
    Level43_7F378Keep(argument0);

    argument0 = argument0 - temporary2;
    Level43_7F378Field(&locals.sp20, int*, 0) = argument0;
    argument1 = Level43_7F378Field(temporary3, int*, 4);
    Level43_7F378Keep(argument1);
    temporary2 = Level43_7F378Field(owner, int*, 16);
    __asm__ volatile("" : "=r"(argument1) : "0"(argument1) : "$6", "memory");
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level43_7F378Field(&locals.sp20, int*, 4) = argument1;
    temporary2 = Level43_7F378PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 2;
    Level43_7F378Keep(argument1);
    saved16 = temporary2 + 0;
    Level43_7F378RequestMobyAnimation(argument0, argument1);
    argument0 = owner + 0;
    argument1 = saved16 + 0;
    argument2 = 0 + 6;
    Level43_7F378Keep(argument2);
    argument3 = 0 + 3;
    Level43_7F378Keep(argument3);
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level43_7F378TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    if (temporary2 == 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1626Return;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_521:
    argument0 = owner + 0;
    argument2 = 0 + 120;

    argument3 = 0 + 80;
    temporary2 = Level43_7F378_func_80035A80(argument0, Level43_7F378Field(privateState, int*, 88),
                                             argument2, argument3, 0, 6, 2, 0);
    temporary2 = temporary2 & 2;
    if (temporary2 == 0)
        goto original1626Return;

    goto original1626_1615;
original1626_537:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C770, int*, 0);
    Level43_7F378Keep(temporary2);

    if (temporary2 == 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field(privateState, unsigned char*, 82);
    Level43_7F378Keep(temporary2);

    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    argument1 = Level43_7F378Field(privateState, unsigned char*, 83);
    Level43_7F378Keep(argument1);
    argument0 = owner + 0;
    Level43_7F378RequestMobyAnimation(argument0, argument1);
    Level43_7F378Field(owner, int*, 24) = 0;
    goto original1626Return;
original1626_550:
    argument0 = 0 + 16;
    temporary2 = Level43_7F378_func_80021F3C(argument0);
    temporary3 = temporary2 + 0;
    temporary2 = (temporary3 >> 8);
    temporary2 = temporary2 & 255;
    if (temporary2 != 0 ? (temporary2 = temporary3 & 15, 1) : (temporary2 = temporary3 & 15, 0))
        goto original1626_586;
    if (temporary2 == 0)
        goto original1626_586;
    temporary2 = Level43_7F378Field(privateState, int*, 88);
    Level43_7F378Keep(temporary2);

    temporary2 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary2);

    temporary3 = Level43_7F378Field(temporary2, int*, 32);
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2) : "$6", "memory");
    argument2 = 0 + 0;
    Level43_7F378Field(&locals.sp20, int*, 16) = temporary3;
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2) : "$4", "$5", "memory");
    temporary2 = Level43_7F378Field(privateState, int*, 88);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 0);
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary2);
    argument1 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(argument1);
    temporary2 = Level43_7F378Field(temporary2, int*, 36);
    Level43_7F378Keep(temporary2);
    argument0 = argument0 - temporary3;
    argument1 = argument1 - temporary2;
    Level43_7F378Field(&locals.sp20, int*, 20) = temporary2;
    temporary2 = Level43_7F378PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Level43_7F378Field(owner, unsigned char*, 70);
    Level43_7F378Keep(argument1);
    argument0 = temporary2 + 0;
    temporary2 = Level43_7F378AbsoluteByteAngleDelta(argument0, argument1);
    temporary2 = temporary2 < 65;
    argument0 = 0 + 16;
    if (temporary2 != 0)
        goto original1626_586;
    Level43_7F378Keep(temporary2);
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
original1626_586:
    temporary3 = Level43_7F378Field(privateState, short*, 76);
    Level43_7F378Keep(temporary3);
    temporary2 = Level43_7F378Field(privateState, int*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 < temporary3;
    if (temporary2 != 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 640);
    Level43_7F378Keep(temporary2);

    if (temporary2 < 0)
        goto original1626_605;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 644);
    Level43_7F378Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 120, 1) : (temporary2 = 0 + 120, 0))
        goto original1626_605;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 644, int*, 0) = temporary2;
    temporary3 = Level43_7F378Field(privateState, short*, 76);
    Level43_7F378Keep(temporary3);
original1626_605:
    temporary2 = Level43_7F378Field(privateState, int*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 < temporary3;
    argument0 = privateState + 80;
    if (temporary2 != 0)
        goto original1626Return;
    argument1 = 0 + 2;
    temporary2 = Level43_7F378CountTimerDown(argument0, argument1);
    if (temporary2 == 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 640);
    Level43_7F378Keep(temporary2);

    if (temporary2 < 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C730, int*, 0);
    Level43_7F378Keep(temporary2);

    saved16 = Level43_7F378Field(temporary2, int*, 20);
    Level43_7F378Keep(saved16);
original1626_623:

    temporary3 = Level43_7F378Field(saved16, unsigned short*, 0);
    Level43_7F378Keep(temporary3);

    temporary3 = temporary3 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    saved17 = (int)((unsigned int)temporary2 << 3);
    argument0 = saved17 + temporary3;
    temporary3 = Level43_7F378Field(argument0, short*, 54);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 523;
    if (temporary3 != temporary2)
        goto original1626_650;
    temporary2 = Level43_7F378Field(argument0, unsigned char*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = (unsigned int)temporary2 < 128;
    if (temporary2 == 0)
        goto original1626_650;

    Level43_7F378_func_8003BA00(argument0);
    argument0 = (int)0x80070000U;
    Level43_7F378Keep(argument0);
    argument0 = Level43_7F378Field(argument0, int*, -15024);
    Level43_7F378Keep(argument0);
    argument0 = argument0 + saved17;
    Level43_7F378DeleteMoby(argument0);
original1626_650:
    temporary2 = Level43_7F378Field(saved16, short*, 0);
    Level43_7F378Keep(temporary2);

    saved16 = saved16 + 2;
    if (temporary2 >= 0)
        goto original1626_623;
    argument0 = Level43_7F378Field(privateState, int*, 116);
    Level43_7F378Keep(argument0);
    temporary2 = 0 + 30;
    Level43_7F378Field(privateState, short*, 80) = temporary2;
    Level43_7F378_func_80028154(argument0);
    temporary2 = 0 + 42;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_661:
    argument0 = privateState + 80;
    argument1 = 0 + 2;
    temporary2 = Level43_7F378CountTimerDown(argument0, argument1);
    saved16 = (int)&locals.sp30;
    if (temporary2 == 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(owner, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = temporary2 | 4;

    Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0) = temporary2;
    temporary2 = 0 + 2;
    Level43_7F378Field(temporary3, unsigned char*, 5) = temporary2;
    temporary2 = Level43_7F378Field(owner, unsigned char*, 70);
    Level43_7F378Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level43_7F378Field(((int)&Level43_7F378_D_80065920 + temporary2), short*, 0);
    Level43_7F378Keep(temporary3);
    argument0 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level43_7F378Field(&locals.sp20, int*, 16) = temporary2;
    temporary2 = Level43_7F378Field(owner, unsigned char*, 70);
    Level43_7F378Keep(temporary2);
    argument1 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level43_7F378Field(((int)&Level43_7F378_D_800658A0 + temporary2), short*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 68);
    Level43_7F378Keep(temporary2);
    argument2 = owner + 12;
    Level43_7F378Field(&locals.sp20, int*, 24) = 0;
    __asm__ volatile("" ::"m"(locals.sp38));
    Level43_7F378Field(&locals.sp20, int*, 24) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level43_7F378Field(&locals.sp20, int*, 20) = temporary2;
    Level43_7F378AddVector(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level43_7F378Keep(argument0);
    argument2 = 0 + 0;
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(owner, unsigned char*, 70);
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2) : "$7", "memory");
    argument3 = 0 + 0;
    argument1 = argument1 + 128;
    argument1 = argument1 & 255;
    Level43_7F378_func_80013D44(argument0, argument1, argument2, argument3);
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 640);
    Level43_7F378Keep(temporary2);

    if (temporary2 >= 0 ? (temporary2 = 0 + 24, 1) : (temporary2 = 0 + 24, 0))
        goto original1626_719;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 640, int*, 0) = 0;
original1626_719:
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_721:
    temporary2 = Level43_7F378Field(owner, unsigned char*, 73);
    Level43_7F378Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original1626_757;
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006E048, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1626_757;
    argument0 = 0 + 16;
    temporary2 = Level43_7F378_func_80021F3C(argument0);
    temporary3 = temporary2 + 0;
    temporary2 = (temporary3 >> 8);
    temporary2 = temporary2 & 255;
    if (temporary2 == 0 ? (temporary2 = temporary3 & 15, 1) : (temporary2 = temporary3 & 15, 0))
        goto original1626_742;
    argument0 = 0 + 16;
    if (temporary2 == 0)
        goto original1626_742;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
original1626_742:
    temporary3 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 5;
    Level43_7F378Field(temporary2, unsigned char*, 72) = temporary3;
    temporary2 = 0 + 2;
    Level43_7F378Field(owner, unsigned char*, 73) = temporary2;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2) : "$4", "memory");
    argument0 = owner + 0;
original1626_757:
    argument1 = 0 + 0;
    temporary2 = Level43_7F378_func_80037BBC(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1626Return;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level43_7F378_func_800512E4(argument0, argument1, argument2);
    argument0 = privateState + 2;
    argument1 = 0 + 1;
    Level43_7F378Keep(argument1);
    saved16 = (int)&Level43_7F378_D_8006C7F8;
    argument2 = saved16 + 0;
    Level43_7F378Keep(argument2);
    temporary2 = 0 + 32;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 6;
    Level43_7F378Field(privateState, unsigned char*, 2) = temporary2;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    argument0 = owner + 72;
    argument1 = 0 + 1;
    argument2 = saved16 + 0;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    temporary2 = 0 + 25;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 30;
    Level43_7F378Field(privateState, short*, 80) = temporary2;
    goto original1626Return;
original1626_783:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C598, int*, 0);
    Level43_7F378Keep(temporary2);

    selectedPoint = 0 + 0;
    if (temporary2 != 0)
        goto original1626_879;
    Level43_7F378Keep(selectedPoint);
    saved17 = (int)&Level43_7F378_D_80070328;
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_797;
    temporary2 = 0 - temporary2;
original1626_797:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_879;
    temporary2 = Level43_7F378Field(owner, int*, 16);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_808;
    temporary2 = 0 - temporary2;
original1626_808:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_879;
    temporary2 = Level43_7F378Field(owner, int*, 20);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 8);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_819;
    temporary2 = 0 - temporary2;
original1626_819:
    temporary2 = temporary2 < 3072;
    argument0 = saved17 + 0;
    if (temporary2 == 0)
        goto original1626_879;
    saved16 = privateState + 92;
    argument1 = saved16 + 0;
    argument2 = 0 + 0;
    argument3 = 0 + 10240;
    temporary2 = Level43_7F378_func_80036220(argument0, argument1, argument2, argument3);
    if (temporary2 != 0)
        goto original1626_879;
    argument3 = Level43_7F378Field(privateState, int*, 92);
    Level43_7F378Keep(argument3);
    argument0 = Level43_7F378Field(privateState, int*, 104);
    Level43_7F378Keep(argument0);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);
    argument2 = argument3 + argument0;
    temporary2 = argument2 < temporary3;
    argument1 = saved16 + 0;
    if (temporary2 == 0)
        goto original1626_839;
    temporary2 = argument2 - temporary3;
    Level43_7F378Field(&locals.sp20, int*, 32) = temporary2;
    goto original1626_846;
original1626_839:
    argument0 = argument3 - argument0;
    temporary2 = temporary3 < argument0;
    if (temporary2 == 0 ? (temporary2 = argument0 - temporary3, 1)
                        : (temporary2 = argument0 - temporary3, 0))
        goto original1626_845;
    Level43_7F378Field(&locals.sp20, int*, 32) = temporary2;
    goto original1626_846;
original1626_845:
    Level43_7F378Field(&locals.sp20, int*, 32) = 0;
original1626_846:
    argument2 = Level43_7F378Field(argument1, int*, 4);
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(argument1, int*, 16);
    Level43_7F378Keep(argument1);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);
    argument0 = argument2 + argument1;
    temporary2 = argument0 < temporary3;
    if (temporary2 == 0 ? (temporary2 = argument0 - temporary3, 1)
                        : (temporary2 = argument0 - temporary3, 0))
        goto original1626_856;
    Level43_7F378Field(&locals.sp20, int*, 36) = temporary2;
    goto original1626_863;
original1626_856:
    argument1 = argument2 - argument1;
    temporary2 = temporary3 < argument1;
    if (temporary2 == 0 ? (temporary2 = argument1 - temporary3, 1)
                        : (temporary2 = argument1 - temporary3, 0))
        goto original1626_862;
    Level43_7F378Field(&locals.sp20, int*, 36) = temporary2;
    goto original1626_863;
original1626_862:
    Level43_7F378Field(&locals.sp20, int*, 36) = 0;
original1626_863:
    argument2 = (int)0x10000000U;
    argument2 = argument2 | 8;
    selectedPoint = 0 + 1;
    temporary3 = (int)&Level43_7F378_D_80070328 + 524;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 548, int*, 0) = 0;
    temporary2 = Level43_7F378Field(temporary3, int*, 0);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field(&locals.sp20, int*, 32);
    Level43_7F378Keep(argument0);
    argument1 = Level43_7F378Field(&locals.sp20, int*, 36);
    Level43_7F378Keep(argument1);
    temporary2 = temporary2 | argument2;
    Level43_7F378Field(temporary3, int*, 0) = temporary2;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 540, int*, 0) = argument0;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 544, int*, 0) = argument1;
original1626_879:
    argument0 = owner + 0;
    if (selectedPoint != 0)
        goto original1626_885;
    Level43_7F378Keep(selectedPoint);
    argument1 = 0 + 0;
    temporary2 = Level43_7F378_func_80037BBC(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1626Return;
original1626_885:
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level43_7F378_func_800512E4(argument0, argument1, argument2);
    temporary2 = 0 + 26;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_891:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C598, int*, 0);
    Level43_7F378Keep(temporary2);

    if (temporary2 != 0)
        goto original1626_984;
    saved17 = (int)&Level43_7F378_D_80070328;
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_905;
    temporary2 = 0 - temporary2;
original1626_905:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_984;
    temporary2 = Level43_7F378Field(owner, int*, 16);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_916;
    temporary2 = 0 - temporary2;
original1626_916:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_984;
    temporary2 = Level43_7F378Field(owner, int*, 20);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 8);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_927;
    temporary2 = 0 - temporary2;
original1626_927:
    temporary2 = temporary2 < 3072;
    argument0 = saved17 + 0;
    if (temporary2 == 0)
        goto original1626_984;
    saved16 = privateState + 92;
    argument1 = saved16 + 0;
    argument2 = 0 + 0;
    argument3 = 0 + 10240;
    temporary2 = Level43_7F378_func_80036220(argument0, argument1, argument2, argument3);
    if (temporary2 != 0)
        goto original1626_984;
    argument3 = Level43_7F378Field(privateState, int*, 92);
    Level43_7F378Keep(argument3);
    argument2 = Level43_7F378Field(privateState, int*, 104);
    Level43_7F378Keep(argument2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);
    argument0 = argument3 + argument2;
    temporary2 = argument0 < temporary3;
    argument1 = saved16 + 0;
    if (temporary2 != 0)
        goto original1626_948;
    argument0 = argument3 - argument2;
    temporary2 = temporary3 < argument0;
    if (temporary2 == 0)
        goto original1626_951;
original1626_948:
    temporary2 = argument0 - temporary3;
    Level43_7F378Field(&locals.sp20, int*, 32) = temporary2;
    goto original1626_952;
original1626_951:
    Level43_7F378Field(&locals.sp20, int*, 32) = 0;
original1626_952:
    argument2 = Level43_7F378Field(argument1, int*, 4);
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(argument1, int*, 16);
    Level43_7F378Keep(argument1);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);
    argument0 = argument2 + argument1;
    temporary2 = argument0 < temporary3;
    if (temporary2 == 0 ? (temporary2 = argument0 - temporary3, 1)
                        : (temporary2 = argument0 - temporary3, 0))
        goto original1626_962;
    Level43_7F378Field(&locals.sp20, int*, 36) = temporary2;
    goto original1626_969;
original1626_962:
    argument1 = argument2 - argument1;
    temporary2 = temporary3 < argument1;
    if (temporary2 == 0 ? (temporary2 = argument1 - temporary3, 1)
                        : (temporary2 = argument1 - temporary3, 0))
        goto original1626_968;
    Level43_7F378Field(&locals.sp20, int*, 36) = temporary2;
    goto original1626_969;
original1626_968:
    Level43_7F378Field(&locals.sp20, int*, 36) = 0;
original1626_969:
    argument2 = (int)0x10000000U;
    argument2 = argument2 | 8;
    temporary3 = (int)&Level43_7F378_D_80070328 + 524;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 548, int*, 0) = 0;
    temporary2 = Level43_7F378Field(temporary3, int*, 0);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field(&locals.sp20, int*, 32);
    Level43_7F378Keep(argument0);
    argument1 = Level43_7F378Field(&locals.sp20, int*, 36);
    Level43_7F378Keep(argument1);
    temporary2 = temporary2 | argument2;
    Level43_7F378Field(temporary3, int*, 0) = temporary2;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 540, int*, 0) = argument0;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 544, int*, 0) = argument1;
original1626_984:
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006E344, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 1;
    argument2 = (int)0x10000000U;
    if (temporary3 == temporary2)
        goto original1626Return;
    argument2 = argument2 | 2;
    argument0 = privateState + 80;
    temporary3 = (int)&Level43_7F378_D_80070328 + 524;
    temporary2 = Level43_7F378Field(temporary3, int*, 0);
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3) : "$5", "memory");
    argument1 = 0 + 2;
    temporary2 = temporary2 | argument2;
    Level43_7F378Field(temporary3, int*, 0) = temporary2;
    temporary2 = Level43_7F378CountTimerDown(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1626Return;
    argument1 = 0 + 0;
    Level43_7F378Keep(argument1);
    argument2 = 0 + 1;
    Level43_7F378Keep(argument2);
    temporary2 = 0 + 2;
    Level43_7F378Field(privateState, unsigned char*, 5) = temporary2;
    temporary2 = 0 + 6;
    Level43_7F378Field(privateState, unsigned char*, 2) = temporary2;
    Level43_7F378_func_800512E4(argument0, argument1, argument2);
    argument0 = 0 + 7;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    temporary2 = 0 + 26;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626_1058;
original1626_1013:
    temporary2 = 0 + 33;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 1;
    Level43_7F378Field(privateState, unsigned char*, 5) = temporary2;
original1626_1017:
    argument0 = (int)&Level43_7F378_D_80070328;
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(argument0, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_1026;
    temporary2 = 0 - temporary2;
original1626_1026:
    temporary2 = temporary2 < 7168;
    argument1 = 0 + 0;
    if (temporary2 == 0)
        goto original1626_1044;
    temporary2 = Level43_7F378Field(owner, int*, 16);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_1037;
    temporary2 = 0 - temporary2;
original1626_1037:
    temporary2 = temporary2 < 7168;
    argument2 = 0 + 0;
    if (temporary2 == 0)
        goto original1626_1044;
    argument1 = privateState + 92;
    argument3 = 0 + 10240;
    temporary2 = Level43_7F378_func_80036220(argument0, argument1, argument2, argument3);
    argument1 = (unsigned int)temporary2 < 1;
original1626_1044:
    argument0 = owner + 0;
    if (argument1 != 0)
        goto original1626_1050;
    Level43_7F378Keep(argument1);
    argument1 = 0 + 0;
    temporary2 = Level43_7F378_func_80037BBC(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1626Return;
original1626_1050:
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level43_7F378_func_800512E4(argument0, argument1, argument2);
    temporary2 = 0 + 26;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    argument0 = 0 + 7;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
original1626_1058:

    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
    argument0 = 0 + 8;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
    argument0 = 0 + 9;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);

    goto original1626Return;
original1626_1070:
    argument0 = 0 + 7;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
    argument0 = 0 + 8;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
    argument0 = 0 + 9;
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
    temporary3 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    argument0 = temporary2 + temporary3;
    temporary2 = Level43_7F378Field(argument0, unsigned char*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 & 128;
    if (temporary2 != 0)
        goto original1626_1615;

    Level43_7F378DeleteMoby(argument0);

    goto original1626_1615;
original1626_1101:
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C598, int*, 0);
    Level43_7F378Keep(temporary2);

    if (temporary2 != 0)
        goto original1626_1194;
    saved17 = (int)&Level43_7F378_D_80070328;
    temporary2 = Level43_7F378Field(owner, int*, 12);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_1115;
    temporary2 = 0 - temporary2;
original1626_1115:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_1194;
    temporary2 = Level43_7F378Field(owner, int*, 16);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_1126;
    temporary2 = 0 - temporary2;
original1626_1126:
    temporary2 = temporary2 < 7168;
    if (temporary2 == 0)
        goto original1626_1194;
    temporary2 = Level43_7F378Field(owner, int*, 20);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 8);
    Level43_7F378Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    if (temporary2 >= 0)
        goto original1626_1137;
    temporary2 = 0 - temporary2;
original1626_1137:
    temporary2 = temporary2 < 3072;
    argument0 = saved17 + 0;
    if (temporary2 == 0)
        goto original1626_1194;
    saved16 = privateState + 92;
    argument1 = saved16 + 0;
    argument2 = 0 + 0;
    argument3 = 0 + 10240;
    temporary2 = Level43_7F378_func_80036220(argument0, argument1, argument2, argument3);
    if (temporary2 != 0)
        goto original1626_1194;
    argument3 = Level43_7F378Field(privateState, int*, 92);
    Level43_7F378Keep(argument3);
    argument2 = Level43_7F378Field(privateState, int*, 104);
    Level43_7F378Keep(argument2);
    temporary3 = Level43_7F378Field(saved17, int*, 0);
    Level43_7F378Keep(temporary3);
    argument0 = argument3 + argument2;
    temporary2 = argument0 < temporary3;
    argument1 = saved16 + 0;
    if (temporary2 != 0)
        goto original1626_1158;
    argument0 = argument3 - argument2;
    temporary2 = temporary3 < argument0;
    if (temporary2 == 0)
        goto original1626_1161;
original1626_1158:
    temporary2 = argument0 - temporary3;
    Level43_7F378Field(&locals.sp20, int*, 32) = temporary2;
    goto original1626_1162;
original1626_1161:
    Level43_7F378Field(&locals.sp20, int*, 32) = 0;
original1626_1162:
    argument2 = Level43_7F378Field(argument1, int*, 4);
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(argument1, int*, 16);
    Level43_7F378Keep(argument1);
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(temporary3);
    argument0 = argument2 + argument1;
    temporary2 = argument0 < temporary3;
    if (temporary2 == 0 ? (temporary2 = argument0 - temporary3, 1)
                        : (temporary2 = argument0 - temporary3, 0))
        goto original1626_1172;
    Level43_7F378Field(&locals.sp20, int*, 36) = temporary2;
    goto original1626_1179;
original1626_1172:
    argument1 = argument2 - argument1;
    temporary2 = temporary3 < argument1;
    if (temporary2 == 0 ? (temporary2 = argument1 - temporary3, 1)
                        : (temporary2 = argument1 - temporary3, 0))
        goto original1626_1178;
    Level43_7F378Field(&locals.sp20, int*, 36) = temporary2;
    goto original1626_1179;
original1626_1178:
    Level43_7F378Field(&locals.sp20, int*, 36) = 0;
original1626_1179:
    argument2 = (int)0x10000000U;
    argument2 = argument2 | 8;
    temporary3 = (int)&Level43_7F378_D_80070328 + 524;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 548, int*, 0) = 0;
    temporary2 = Level43_7F378Field(temporary3, int*, 0);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field(&locals.sp20, int*, 32);
    Level43_7F378Keep(argument0);
    argument1 = Level43_7F378Field(&locals.sp20, int*, 36);
    Level43_7F378Keep(argument1);
    temporary2 = temporary2 | argument2;
    Level43_7F378Field(temporary3, int*, 0) = temporary2;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 540, int*, 0) = argument0;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 544, int*, 0) = argument1;
original1626_1194:
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006E344, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 8, 1) : (temporary2 = 0 + 8, 0))
        goto original1626Return;
    temporary3 = Level43_7F378Field(privateState, unsigned char*, 4);
    Level43_7F378Keep(temporary3);

    saved17 = (int)&locals.sp40;
    if (temporary3 != temporary2)
        goto original1626_1210;
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level43_7F378RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 23;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    Level43_7F378Field(privateState, unsigned char*, 5) = 0;
    goto original1626Return;
original1626_1210:
    argument0 = saved17 + 0;
    Level43_7F378Keep(argument0);
    temporary3 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary3);
    saved16 = (int)0x80070000U;
    Level43_7F378Keep(saved16);
    saved16 = Level43_7F378Field(saved16, int*, -15024);
    Level43_7F378Keep(saved16);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = saved16 + temporary2;
    argument1 = saved16 + 12;
    Level43_7F378CopyVector(argument0, argument1);
    argument0 = saved17 + 0;
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(&locals.sp20, int*, 40);
    Level43_7F378Keep(temporary2);
    argument2 = 0 + 0;
    Level43_7F378Keep(argument2);
    temporary2 = temporary2 + 400;
    Level43_7F378Field(&locals.sp20, int*, 40) = temporary2;
    argument1 = Level43_7F378Field(saved16, unsigned char*, 70);
    Level43_7F378Keep(argument1);
    argument3 = 0 + 0;
    Level43_7F378_func_80013D44(argument0, argument1, argument2, argument3);
    temporary3 = (int)0x10000000U;
    temporary3 = temporary3 | 2;
    temporary2 = 0 + 2;
    Level43_7F378Field(saved16, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 255;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 524, int*, 0) = temporary3;
    Level43_7F378Field(owner, unsigned char*, 74) = temporary2;
    temporary2 = 0 + 60;
    Level43_7F378Field(privateState, short*, 80) = temporary2;
    temporary2 = 0 + 27;
    Level43_7F378Field(privateState, int*, 72) = 0;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_1244:
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006E044, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 11;
    argument0 = 0 + 23;
    if (temporary3 == temporary2)
        goto original1626Return;
    argument1 = 0 + 430;
    Level43_7F378Keep(argument1);
    argument2 = (int)&Level43_7F378_func_80027EE4;
    Level43_7F378Keep(argument2);
    temporary2 = 0 + 82;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;

    argument3 = (int)&Level43_7F378_func_80027A60;
    temporary2 = Level43_7F378_func_8002803C(argument0, argument1, argument2, argument3,
                                             (int)&Level43_7F378_func_80029AA0, privateState + 72,
                                             (int)Level43_7F378Field(privateState, short*, 78));
    temporary2 = (int)((unsigned int)temporary2 << 16);
    temporary2 = (temporary2 >> 16);
    Level43_7F378Field(privateState, int*, 116) = temporary2;
    goto original1626Return;
original1626_1268:
    argument0 = 0 + 16;
    temporary2 = Level43_7F378_func_80021F3C(argument0);
    temporary3 = temporary2 + 0;
    temporary2 = (temporary3 >> 8);
    temporary2 = temporary2 & 255;
    if (temporary2 != 0 ? (temporary2 = temporary3 & 15, 1) : (temporary2 = temporary3 & 15, 0))
        goto original1626_1304;
    if (temporary2 == 0)
        goto original1626_1304;
    temporary2 = Level43_7F378Field(privateState, int*, 88);
    Level43_7F378Keep(temporary2);

    temporary2 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary2);

    temporary3 = Level43_7F378Field(temporary2, int*, 32);
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2) : "$6", "memory");
    argument2 = 0 + 0;
    Level43_7F378Field(&locals.sp20, int*, 48) = temporary3;
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2) : "$4", "$5", "memory");
    temporary2 = Level43_7F378Field(privateState, int*, 88);
    Level43_7F378Keep(temporary2);
    argument0 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 0);
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary2);
    argument1 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 4);
    Level43_7F378Keep(argument1);
    temporary2 = Level43_7F378Field(temporary2, int*, 36);
    Level43_7F378Keep(temporary2);
    argument0 = argument0 - temporary3;
    argument1 = argument1 - temporary2;
    Level43_7F378Field(&locals.sp20, int*, 52) = temporary2;
    temporary2 = Level43_7F378PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Level43_7F378Field(owner, unsigned char*, 70);
    Level43_7F378Keep(argument1);
    argument0 = temporary2 + 0;
    temporary2 = Level43_7F378AbsoluteByteAngleDelta(argument0, argument1);
    temporary2 = temporary2 < 65;
    argument0 = 0 + 16;
    if (temporary2 != 0)
        goto original1626_1304;
    Level43_7F378Keep(temporary2);
    argument1 = 0 + 252;
    argument2 = 0 + 0;
    Level43_7F378_func_80021ED8(argument0, argument1, argument2);
original1626_1304:
    temporary3 = Level43_7F378Field(privateState, short*, 78);
    Level43_7F378Keep(temporary3);
    temporary2 = Level43_7F378Field(privateState, int*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 < temporary3;
    if (temporary2 != 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 640);
    Level43_7F378Keep(temporary2);

    if (temporary2 < 0)
        goto original1626_1323;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 644);
    Level43_7F378Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 120, 1) : (temporary2 = 0 + 120, 0))
        goto original1626_1323;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 644, int*, 0) = temporary2;
    temporary3 = Level43_7F378Field(privateState, short*, 78);
    Level43_7F378Keep(temporary3);
original1626_1323:
    temporary2 = Level43_7F378Field(privateState, int*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = temporary2 < temporary3;
    argument0 = privateState + 80;
    if (temporary2 != 0)
        goto original1626Return;
    argument1 = 0 + 2;
    temporary2 = Level43_7F378CountTimerDown(argument0, argument1);
    if (temporary2 == 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 640);
    Level43_7F378Keep(temporary2);

    if (temporary2 < 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C730, int*, 0);
    Level43_7F378Keep(temporary2);

    saved16 = Level43_7F378Field(temporary2, int*, 24);
    Level43_7F378Keep(saved16);
original1626_1341:

    temporary3 = Level43_7F378Field(saved16, unsigned short*, 0);
    Level43_7F378Keep(temporary3);

    temporary3 = temporary3 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    saved17 = (int)((unsigned int)temporary2 << 3);
    argument0 = saved17 + temporary3;
    temporary3 = Level43_7F378Field(argument0, short*, 54);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 523;
    if (temporary3 != temporary2)
        goto original1626_1368;
    temporary2 = Level43_7F378Field(argument0, unsigned char*, 72);
    Level43_7F378Keep(temporary2);

    temporary2 = (unsigned int)temporary2 < 128;
    if (temporary2 == 0)
        goto original1626_1368;

    Level43_7F378_func_8003BA00(argument0);
    argument0 = (int)0x80070000U;
    Level43_7F378Keep(argument0);
    argument0 = Level43_7F378Field(argument0, int*, -15024);
    Level43_7F378Keep(argument0);
    argument0 = argument0 + saved17;
    Level43_7F378DeleteMoby(argument0);
original1626_1368:
    temporary2 = Level43_7F378Field(saved16, short*, 0);
    Level43_7F378Keep(temporary2);

    saved16 = saved16 + 2;
    if (temporary2 >= 0)
        goto original1626_1341;
    argument0 = Level43_7F378Field(privateState, int*, 116);
    Level43_7F378Keep(argument0);

    Level43_7F378_func_80028154(argument0);
    temporary2 = 0 + 30;
    Level43_7F378Field(privateState, short*, 80) = temporary2;
    temporary2 = 0 + 44;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    Level43_7F378Field(owner, unsigned char*, 73) = 0;
    goto original1626Return;
original1626_1381:
    argument0 = privateState + 80;
    argument1 = 0 + 2;
    temporary2 = Level43_7F378CountTimerDown(argument0, argument1);
    saved16 = (int)&locals.sp50;
    if (temporary2 == 0)
        goto original1626Return;
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0);
    Level43_7F378Keep(temporary2);
    temporary3 = Level43_7F378Field(owner, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = temporary2 | 8;

    Level43_7F378Field((int)&Level43_7F378_D_8006C7B4, unsigned char*, 0) = temporary2;
    temporary2 = 0 + 2;
    Level43_7F378Field(temporary3, unsigned char*, 5) = temporary2;
    temporary2 = Level43_7F378Field(owner, unsigned char*, 70);
    Level43_7F378Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level43_7F378Field(((int)&Level43_7F378_D_80065920 + temporary2), short*, 0);
    Level43_7F378Keep(temporary3);
    argument0 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level43_7F378Field(&locals.sp20, int*, 48) = temporary2;
    temporary2 = Level43_7F378Field(owner, unsigned char*, 70);
    Level43_7F378Keep(temporary2);
    argument1 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level43_7F378Field(((int)&Level43_7F378_D_800658A0 + temporary2), short*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 68);
    Level43_7F378Keep(temporary2);
    argument2 = owner + 12;
    Level43_7F378Field(&locals.sp20, int*, 56) = 0;
    __asm__ volatile("" ::"m"(locals.sp58));
    Level43_7F378Field(&locals.sp20, int*, 56) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level43_7F378Field(&locals.sp20, int*, 52) = temporary2;
    Level43_7F378AddVector(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level43_7F378Keep(argument0);
    argument2 = 0 + 0;
    Level43_7F378Keep(argument2);
    argument1 = Level43_7F378Field(owner, unsigned char*, 70);
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2) : "$7", "memory");
    argument3 = 0 + 0;
    argument1 = argument1 + 128;
    argument1 = argument1 & 255;
    Level43_7F378_func_80013D44(argument0, argument1, argument2, argument3);
    temporary2 = Level43_7F378Field((int)&Level43_7F378_D_80070328, int*, 640);
    Level43_7F378Keep(temporary2);

    if (temporary2 >= 0 ? (temporary2 = 0 + 28, 1) : (temporary2 = 0 + 28, 0))
        goto original1626_1439;

    Level43_7F378Field((int)&Level43_7F378_D_80070328 + 640, int*, 0) = 0;
original1626_1439:
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_1441:
    temporary2 = Level43_7F378Field(owner, unsigned char*, 73);
    Level43_7F378Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original1626_1464;
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006E048, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1626_1464;
    temporary3 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 5;
    Level43_7F378Field(temporary2, unsigned char*, 72) = temporary3;
    temporary2 = 0 + 2;
    Level43_7F378Field(owner, unsigned char*, 73) = temporary2;
original1626_1464:
    argument1 = 0 + 0;
    temporary2 = Level43_7F378_func_80037BBC(argument0, argument1);
    argument0 = owner + 72;
    if (temporary2 == 0)
        goto original1626Return;
    argument1 = 0 + 1;
    Level43_7F378Keep(argument1);
    argument2 = (int)&Level43_7F378_D_8006C7F8;
    Level43_7F378Keep(argument2);
    temporary2 = 0 + 34;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level43_7F378_func_800512E4(argument0, argument1, argument2);
    temporary2 = 0 + 29;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_1481:
    temporary3 = Level43_7F378Field((int)&Level43_7F378_D_8006E344, int*, 0);
    Level43_7F378Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 == temporary2)
        goto original1626Return;
    temporary2 = Level43_7F378Field(privateState, int*, 68);
    Level43_7F378Keep(temporary2);

    argument0 = (int)((unsigned int)temporary2 << 1);
    argument0 = argument0 + temporary2;
    argument0 = (int)((unsigned int)argument0 << 2);
    argument0 = argument0 - temporary2;
    temporary2 = (int)0x80070000U;
    Level43_7F378Keep(temporary2);
    temporary2 = Level43_7F378Field(temporary2, int*, -15024);
    Level43_7F378Keep(temporary2);
    argument0 = (int)((unsigned int)argument0 << 3);
    argument0 = temporary2 + argument0;
    Level43_7F378DeleteMoby(argument0);
    temporary2 = 0 + 30;
    goto original1626_1613;
original1626_1499:
    __asm__("" : "=r"(selectedPoint));
    saved17 = (int)0x00010000U;
    Level43_7F378Keep(saved17);
    temporary3 = Level43_7F378Field(privateState, int*, 64);
    Level43_7F378Keep(temporary3);
    saved17 = saved17 | 34464;
    temporary2 = Level43_7F378Field(temporary3, short*, 0);
    Level43_7F378Keep(temporary2);

    saved16 = 0 + 0;
    if (temporary2 <= 0)
        goto original1626_1525;
original1626_1506:
    argument0 = (int)&Level43_7F378_D_80070328;
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(temporary3, int*, 12);
    Level43_7F378Keep(temporary2);
    argument1 = (int)((unsigned int)saved16 << 4);
    argument1 = temporary2 + argument1;
    temporary2 = Level43_7F378ApproximatePlanarDistance(argument0, argument1);
    temporary3 = temporary2 + 0;
    temporary2 = temporary3 < saved17;
    if (temporary2 == 0)
        goto original1626_1518;
    saved17 = temporary3 + 0;
    selectedPoint = saved16 + 0;
original1626_1518:
    temporary3 = Level43_7F378Field(privateState, int*, 64);
    Level43_7F378Keep(temporary3);

    temporary2 = Level43_7F378Field(temporary3, short*, 0);
    Level43_7F378Keep(temporary2);
    saved16 = saved16 + 2;
    temporary2 = saved16 < temporary2;
    if (temporary2 != 0)
        goto original1626_1506;
original1626_1525:
    temporary2 = Level43_7F378Field(privateState, int*, 64);
    Level43_7F378Keep(temporary2);

    temporary3 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)selectedPoint << 4);
    argument1 = temporary2 + temporary3;
    Level43_7F378Keep(argument1);
    temporary2 = Level43_7F378Field(argument1, int*, 12);
    Level43_7F378Keep(temporary2);

    saved16 = owner + 72;
    if (temporary2 == 0)
        goto original1626_1551;
    argument0 = saved16 + 0;
    argument1 = 0 + 1;
    argument2 = (int)&Level43_7F378_D_8006D088;
    Level43_7F378Field(owner, unsigned char*, 72) = 0;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    argument2 = (int)&Level43_7F378_D_8006C7F8;
    argument1 = 0 + 1;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    temporary2 = 0 + 21;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;

    Level43_7F378Field((int)&Level43_7F378_D_8006E160, int*, 0) = 0;

    goto original1626Return;
original1626_1551:
    argument2 = 0 + 1;
    Level43_7F378Keep(argument2);
    temporary3 = Level43_7F378Field(argument1, int*, 16);
    Level43_7F378Keep(temporary3);
    argument0 = Level43_7F378Field(argument1, int*, 0);
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(argument1, int*, 20);
    Level43_7F378Keep(temporary2);
    argument1 = Level43_7F378Field(argument1, int*, 4);
    Level43_7F378Keep(argument1);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level43_7F378PlanarHeadingLookup(argument0, argument1, argument2);
    temporary3 = 0 + 33;

    Level43_7F378Field((int)&Level43_7F378_D_8006E160, int*, 0) = temporary3;

    Level43_7F378Field((int)&Level43_7F378_D_8006E168, int*, 0) = temporary2;

    goto original1626Return;
original1626_1566:
    temporary2 = Level43_7F378Field(privateState, int*, 64);
    Level43_7F378Keep(temporary2);
    argument1 = (int)&Level43_7F378_D_80070328;
    Level43_7F378Keep(argument1);
    argument0 = Level43_7F378Field(temporary2, short*, 0);
    Level43_7F378Keep(argument0);
    temporary2 = Level43_7F378Field(temporary2, int*, 12);
    Level43_7F378Keep(temporary2);
    argument0 = (int)((unsigned int)argument0 << 4);
    argument0 = argument0 + -16;
    argument0 = temporary2 + argument0;
    temporary2 = Level43_7F378ApproximatePlanarDistance(argument0, argument1);
    temporary2 = temporary2 < 2000;
    saved16 = owner + 72;
    if (temporary2 == 0)
        goto original1626Return;
    argument0 = saved16 + 0;
    temporary3 = Level43_7F378Field(privateState, int*, 84);
    Level43_7F378Keep(temporary3);
    argument1 = 0 + 1;
    Level43_7F378Keep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 3;
    Level43_7F378Field(temporary2, unsigned char*, 72) = temporary3;
    temporary3 = Level43_7F378Field(privateState, int*, 84);
    Level43_7F378Keep(temporary3);
    argument2 = (int)&Level43_7F378_D_8006D088;
    Level43_7F378Keep(argument2);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = (int)0x80070000U;
    Level43_7F378Keep(temporary3);
    temporary3 = Level43_7F378Field(temporary3, int*, -15024);
    Level43_7F378Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 255;
    Level43_7F378Field(temporary2, unsigned char*, 74) = temporary3;
    temporary2 = 0 + 22;
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    argument2 = (int)&Level43_7F378_D_8006C7F8;
    argument1 = 0 + 1;
    Level43_7F378_func_8003B7B4(argument0, argument1, argument2);
    temporary2 = 0 + 30;
original1626_1613:
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(owner));
    Level43_7F378Field(owner, unsigned char*, 72) = temporary2;
    goto original1626Return;
original1626_1615:
    argument0 = owner + 0;
    Level43_7F378DeleteMoby(argument0);
original1626Return:
    return;
}
#undef Level43_7F378Field
#undef Level43_7F378Keep
#undef Level43_7F378Low

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80080CE0.
* Assembly SHA256 1839d2914ea6959541802d7f78d48ec848920391e5fdef3100d81c15e37edb5f.
* AI generated; not human reviewed. All519 original instructions and27
* selector words, one zero padding word and actual targets are required. Frame0x70 retains every
* S0..S7/FP/RA save and original SP18..47 local extent. The first helper
* receives original incoming A0 plus the private word and literal2.
* Shared mode3/mode2/route/removal helper blocks retain physical order,
* arguments, returns and all actual destinations. Player-address views,
* byte/halfword loads, original flags/store order and loop reloads remain
* exact. The loop stride updates after its original count comparison.
* Selected entry has an ordinary C scalar, naturally allocated to FP;
* there is no fixed FP declaration or undefined saved-register input.
* Selection is consumed only when a successful update made maximum
* distance nonzero. Empty initialized identities, late consumers and dead
* clobbers emit0 CPU instructions; no opcode assembly or live-alias overlap.
* Confidence is binary identity after all gates. Raw units/fixed point,
* full helper contracts, caller cadence and synchronized runtime remain
* open. Cadence is per invocation. Falsification: every native/linked word,
* actual transfer/table target, original data byte, full EXE and every
* overlay retail hash must remain identical. */
#define Actor43_80CE0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor43_80CE0Call34F40View1() __asm__("func_80034F40");
int Actor43_80CE0SetMobyAnimationView1() __asm__("func_80034F80");
int Actor43_80CE0TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Actor43_80CE0TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor43_80CE0CountTimerDownView1() __asm__("func_800359A4");
int Actor43_80CE0Call368A4View1() __asm__("func_800368A4");
int Actor43_80CE0Call369B8View1() __asm__("func_800369B8");
int Actor43_80CE0Call36A68View1() __asm__("func_80036A68");
int Actor43_80CE0Call3BA00View1() __asm__("func_8003BA00");
int Actor43_80CE0PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor43_80CE0PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor43_80CE0TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Actor43_80CE0AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor43_80CE0ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor43_80CE0DeleteMobyView1() __asm__("func_80055B18");
int Actor43_80CE0RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Actor43_80CE0Data6C550View1 __asm__("D_8006C550");
extern int Actor43_80CE0Data6C770View1 __asm__("D_8006C770");
extern int Actor43_80CE0Data6E020View1 __asm__("D_8006E020");
extern int Actor43_80CE0Data6E024View1 __asm__("D_8006E024");
extern unsigned short Actor43_80CE0Data6E040View1 __asm__("D_8006E040");
extern int Actor43_80CE0Data6E344View1 __asm__("D_8006E344");
extern int Actor43_80CE0Data70328View1 __asm__("D_80070328");
extern int (*Actor43_80CE0DataSpawnFragmentsView1)() __asm__("SpawnFragments");
extern int (*Actor43_80CE0Data74414View1)() __asm__("unk_ovlheader_80074414");
extern int (*Actor43_80CE0Data74418View1)() __asm__("unk_ovlheader_80074418");
extern int (*Actor43_80CE0Data74420View1)() __asm__("unk_ovlheader_80074420");
void func_level_43_80080CE0(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int retainedAddressOrAngle16 __asm__("$16"), entryOffset18 __asm__("$18"),
        entryIndex19 __asm__("$19"), candidateDistance20 __asm__("$20"),
        privateRecord21 __asm__("$21"), maximumDistance22 __asm__("$22"),
        playerPositionAddress23 __asm__("$23");
    int selectedEntryIndex;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    } originalFrame;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    privateRecord21 = (int)Actor43_80CE0Field(ownerRecord17, void**, 0);
    Actor43_80CE0Field(privateRecord21, int*, 0x1C) =
        Actor43_80CE0Call368A4View1(input, Actor43_80CE0Field(privateRecord21, int*, 0x1C), 2);
    if (Actor43_80CE0Field(ownerRecord17, int*, 0x18) & 0x9E0000) {
        Actor43_80CE0PlayMobySoundEventView1(ownerRecord17, 0, 0);
        Actor43_80CE0RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
        Actor43_80CE0DataSpawnFragmentsView1(
            5, 0x1E1, ownerRecord17, Actor43_80CE0Field(privateRecord21, int*, 0x18), 0, 0x100);
        Actor43_80CE0Call36A68View1(ownerRecord17, 0, 0, 0);
        Actor43_80CE0RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
        Actor43_80CE0Call3BA00View1(ownerRecord17);
        argumentWord4 = (int)ownerRecord17;
        argumentWord5 = 32;
        goto callSharedRemovalTail;
    }
    rawWord3 = Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48);
    Actor43_80CE0Field(ownerRecord17, int*, 0x18) = 0;
    switch (rawWord3) {
        case 0:
            if ((Actor43_80CE0CountTimerDownView1(privateRecord21 + 0x10, 2) != 0) &&
                (Actor43_80CE0Data6E344View1 != 1) && (Actor43_80CE0Data6E344View1 != 0xF)) {
                retainedAddressOrAngle16 = (int)((unsigned char*)&Actor43_80CE0Data70328View1 + 8);
                MATCHING_KEEP(retainedAddressOrAngle16);
                rawWord2 = Actor43_80CE0Field(retainedAddressOrAngle16, int*, 0);
                rawWord3 = Actor43_80CE0Field(ownerRecord17, int*, 20);
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if ((rawWord2 < 0x200) &&
                    (Actor43_80CE0AbsoluteByteAngleDeltaView1(
                         (int)(Actor43_80CE0Data6E040View1 << 0x10) >> 0x14,
                         Actor43_80CE0PlanarHeadingLookupView1(
                             Actor43_80CE0Field(ownerRecord17, int*, 0xC) -
                                 Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, int*, 0),
                             Actor43_80CE0Field(ownerRecord17, int*, 0x10) -
                                 Actor43_80CE0Data6E024View1,
                             0)) < 0x16) &&
                    (Actor43_80CE0Data74414View1(Actor43_80CE0Field(privateRecord21, void**, 0xC),
                                                 retainedAddressOrAngle16 - 8) != 0)) {
                    rawWord3 = Actor43_80CE0Field(privateRecord21, int*, 0x14);
                    if (rawWord3 >= 0) {
                        rawWord3 = (rawWord3 * 0x58) + Actor43_80CE0Data6C550View1;
                        if (Actor43_80CE0Field(rawWord3, unsigned char*, 0x48) == 0) {
                            Actor43_80CE0Field(Actor43_80CE0Field(rawWord3, void**, 0), short*,
                                               0x10) = 0x3C;
                        }
                    }
                    Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                    Actor43_80CE0Call34F40View1(ownerRecord17, 1);
                    return;
                }
            } else {
                return;
            }
            break;
        case 1:
            if (Actor43_80CE0Data6C770View1 != 0) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 2U;
                goto callSharedMode2Helper;
                return;
            }
            break;
        case 2:
            Actor43_80CE0TurnMobyTowardPlayerView1(ownerRecord17, 4, 4, 1);
            if ((Actor43_80CE0Data74420View1(ownerRecord17, 0x96,
                                             Actor43_80CE0Field(privateRecord21, void**, 0xC),
                                             0x2BC) == 0) ||
                (Actor43_80CE0Data6E344View1 == 1) || (Actor43_80CE0Data6E344View1 == 0xF) ||
                (Actor43_80CE0AbsoluteByteAngleDeltaView1(
                     (int)Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x46),
                     Actor43_80CE0PlanarHeadingLookupView1(
                         Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0) -
                             Actor43_80CE0Field(ownerRecord17, int*, 0xC),
                         Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 4) -
                             Actor43_80CE0Field(ownerRecord17, int*, 0x10),
                         0)) >= 0x41) ||
                (Actor43_80CE0AbsoluteByteAngleDeltaView1(
                     (int)(Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, unsigned short*, 0x20)
                           << 0x10) >>
                         0x14,
                     Actor43_80CE0PlanarHeadingLookupView1(
                         Actor43_80CE0Field(ownerRecord17, int*, 0xC) -
                             Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, int*, 0),
                         Actor43_80CE0Field(ownerRecord17, int*, 0x10) -
                             Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, int*, 4),
                         0)) >= 0x18) ||
                (Actor43_80CE0Data74418View1(Actor43_80CE0Field(privateRecord21, void**, 0xC),
                                             &Actor43_80CE0Data70328View1, &originalFrame.sp18,
                                             &originalFrame.sp1C, -1) == 0)) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                return;
            }
            originalFrame.sp18 = (Actor43_80CE0Field(ownerRecord17, int*, 0x14) -
                                  Actor43_80CE0Field(ownerRecord17, short*, 0x38)) -
                                 Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 8);
            if ((Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x3C) == 2) &&
                (Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x50) != 9) &&
                (Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x50) != 4) &&
                (Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x240) == 0) &&
                (Actor43_80CE0AbsoluteByteAngleDeltaView1(
                     (int)(Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, unsigned short*, 0x20)
                           << 0x10) >>
                         0x14,
                     Actor43_80CE0PlanarHeadingLookupView1(
                         Actor43_80CE0Field(ownerRecord17, int*, 0xC) -
                             Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, int*, 0),
                         Actor43_80CE0Field(ownerRecord17, int*, 0x10) -
                             Actor43_80CE0Field(&Actor43_80CE0Data6E020View1, int*, 4),
                         0)) < 0x18) &&
                (Actor43_80CE0AbsoluteByteAngleDeltaView1(
                     (int)Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x46),
                     Actor43_80CE0PlanarHeadingLookupView1(
                         Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0) -
                             Actor43_80CE0Field(ownerRecord17, int*, 0xC),
                         Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 4) -
                             Actor43_80CE0Field(ownerRecord17, int*, 0x10),
                         0)) < 8) &&
                (Actor43_80CE0ApproximatePlanarDistanceView1(
                     ownerRecord17 + 0xC, &Actor43_80CE0Data70328View1) < 0x708) &&
                ((unsigned int)(originalFrame.sp18 + 0x1FF) < 0x27FU)) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 5U;
                Actor43_80CE0SetMobyAnimationView1(ownerRecord17, 5);
                rawWord3 = 0x10000400;
                argumentWord4 = (int)ownerRecord17;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, rawWord3, "$2");
                Actor43_80CE0Field(privateRecord21, short*, 0x10) = 30;
                argumentWord6 = Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x46);
                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x20C) = rawWord3;
                rawWord3 = Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x24);
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord3, "$2");
                rawWord2 = 75;
                originalFrame.sp20 = rawWord2;
                originalFrame.sp24 = 0;
                originalFrame.sp28 = 0;
                __asm__ __volatile__(""
                                     : "=r"(rawWord3)
                                     : "0"(rawWord3), "m"(originalFrame.sp28)
                                     : "memory");
                rawWord3 |= 0x86;
                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x298) = argumentWord6;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x24) = rawWord3;
                Actor43_80CE0RefreshMobySpatialGridAndBasisView1(argumentWord4, 4, argumentWord6);
                Actor43_80CE0TransformVectorByBasisView1(ownerRecord17 + 0x20, &originalFrame.sp20,
                                                         &originalFrame.sp20);
                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x224) = 0x32;
                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x21C) = originalFrame.sp20;
                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 0x220) = originalFrame.sp24;
                return;
            }
            break;
        case 5:
            if ((Actor43_80CE0Data6C770View1 != 0) &&
                (Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 0x18U,
                 Actor43_80CE0Call34F40View1(ownerRecord17, 0),
                 rawWord3 = Actor43_80CE0Field(privateRecord21, void**, 0xC),
                 Actor43_80CE0Field(privateRecord21, short*, 0x12) = 0x2D, (rawWord3 != 0))) {
                entryIndex19 = 0;
                rawWord2 = Actor43_80CE0Field(rawWord3, unsigned char*, 1);
                MATCHING_KEEP(rawWord2);
                maximumDistance22 = 0;
                if (rawWord2 > 0) {
                    playerPositionAddress23 = (int)&Actor43_80CE0Data70328View1;
                    MATCHING_KEEP(playerPositionAddress23);
                    entryOffset18 = 0;
                    do {
                        rawWord2 = rawWord3 + entryOffset18;
                        rawWord2 = Actor43_80CE0Field(rawWord2, int*, 0x14);
                        originalFrame.sp30 = rawWord2;
                        originalFrame.sp34 = Actor43_80CE0Field(
                            (Actor43_80CE0Field(privateRecord21, void**, 0xC) + entryOffset18),
                            int*, 0x18);
                        originalFrame.sp38 = Actor43_80CE0Field(ownerRecord17, int*, 0x14);
                        candidateDistance20 = Actor43_80CE0ApproximatePlanarDistanceView1(
                            &originalFrame.sp30, playerPositionAddress23);
                        if (maximumDistance22 < candidateDistance20) {
                            rawWord2 = Actor43_80CE0PlanarHeadingLookupView1(
                                Actor43_80CE0Field(playerPositionAddress23, int*, 0) -
                                    Actor43_80CE0Field(ownerRecord17, int*, 0xC),
                                Actor43_80CE0Field(&Actor43_80CE0Data70328View1, int*, 4) -
                                    Actor43_80CE0Field(ownerRecord17, int*, 0x10),
                                0);
                            argumentWord6 = 0;
                            MATCHING_OBSERVE_GNU_VOLATILE(argumentWord6);
                            retainedAddressOrAngle16 = rawWord2;
                            argumentWord7 = originalFrame.sp30;
                            argumentWord4 = Actor43_80CE0Field(ownerRecord17, int*, 0xC);
                            rawWord3 = originalFrame.sp34;
                            argumentWord5 = Actor43_80CE0Field(ownerRecord17, int*, 0x10);
                            argumentWord4 = argumentWord7 - argumentWord4;
                            argumentWord5 = rawWord3 - argumentWord5;
                            rawWord2 = Actor43_80CE0PlanarHeadingLookupView1(
                                argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                            if (Actor43_80CE0AbsoluteByteAngleDeltaView1(retainedAddressOrAngle16,
                                                                         rawWord2) >= 0x41) {
                                maximumDistance22 = candidateDistance20;
                                selectedEntryIndex = entryIndex19;
                            }
                        }
                        rawWord3 = Actor43_80CE0Field(privateRecord21, int*, 0xC);
                        rawWord2 = Actor43_80CE0Field(rawWord3, unsigned char*, 1);
                        __asm__("" : "=r"(entryIndex19) : "0"(entryIndex19), "r"(rawWord2));
                        entryIndex19 += 1;
                        rawWord2 = entryIndex19 < rawWord2;
                        __asm__("" : "=r"(entryOffset18) : "0"(entryOffset18), "r"(rawWord2));
                        entryOffset18 += 28;
                    } while (rawWord2);
                }
                if (maximumDistance22 != 0) {
                    rawWord3 = selectedEntryIndex * 0x1C;
                    Actor43_80CE0Field(privateRecord21, int*, 0) = (int)Actor43_80CE0Field(
                        (Actor43_80CE0Field(privateRecord21, void**, 0xC) + rawWord3), int*, 0x14);
                    Actor43_80CE0Field(privateRecord21, int*, 4) = (int)Actor43_80CE0Field(
                        (Actor43_80CE0Field(privateRecord21, void**, 0xC) + rawWord3), int*, 0x18);
                    return;
                }
            }
            break;
        case 24:
            if (Actor43_80CE0CountTimerDownView1(privateRecord21 + 0x12, 2) != 0) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 0x1AU;
                goto callSharedMode3Helper;
                return;
            }
            break;
        case 20:
            Actor43_80CE0TurnMobyTowardHeadingView1(
                ownerRecord17,
                Actor43_80CE0PlanarHeadingLookupView1(
                    Actor43_80CE0Field(privateRecord21, int*, 0) -
                        Actor43_80CE0Field(ownerRecord17, int*, 0xC),
                    Actor43_80CE0Field(privateRecord21, int*, 4) -
                        Actor43_80CE0Field(ownerRecord17, int*, 0x10),
                    0),
                4, 2, 1, 0);
            Actor43_80CE0Data74420View1(ownerRecord17, 0x96,
                                        Actor43_80CE0Field(privateRecord21, void**, 0xC), 0x2BC);
            if (Actor43_80CE0ApproximatePlanarDistanceView1(ownerRecord17 + 0xC, privateRecord21) <
                0x400) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 0x16U;
            callSharedMode3Helper:
                Actor43_80CE0Call34F40View1(ownerRecord17, 3);
            }
            break;
        case 26:
            if (Actor43_80CE0TurnMobyTowardHeadingView1(
                    ownerRecord17,
                    Actor43_80CE0PlanarHeadingLookupView1(
                        Actor43_80CE0Field(privateRecord21, int*, 0) -
                            Actor43_80CE0Field(ownerRecord17, int*, 0xC),
                        Actor43_80CE0Field(privateRecord21, int*, 4) -
                            Actor43_80CE0Field(ownerRecord17, int*, 0x10),
                        0),
                    4, 2, 1, 0) != 0) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 0x14U;
            callSharedMode2Helper:
                Actor43_80CE0Call34F40View1(ownerRecord17, 2);
                return;
            }
            goto callSharedRouteHelper;
        case 22:
            if (Actor43_80CE0TurnMobyTowardPlayerView1(ownerRecord17, 4, 4, 1) != 0) {
                Actor43_80CE0Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Actor43_80CE0Call34F40View1(ownerRecord17, 0);
                return;
            }
        callSharedRouteHelper:
            Actor43_80CE0Data74420View1(ownerRecord17, 0x32,
                                        Actor43_80CE0Field(privateRecord21, void**, 0xC), 0x2BC);
            return;
        case 4:
            if (Actor43_80CE0Data6C770View1 != 0) {
                Actor43_80CE0RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Actor43_80CE0Call3BA00View1(ownerRecord17);
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 30;
            callSharedRemovalTail:
                Actor43_80CE0Call369B8View1(argumentWord4, argumentWord5);
                Actor43_80CE0DeleteMobyView1(ownerRecord17);
            }
            break;
    }
}
#undef Actor43_80CE0Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 800814FC:344 instructions and six dispatch words, original4673.
 * Verified43/46 state and projectile helper shapes reused where original
 * agrees. Units, helper semantics, cadence and runtime parity unresolved. */
#define C43Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* C43Active __asm__("D_8006E164");
extern int C43Type __asm__("D_8006E160");
extern unsigned char* C43Pool __asm__("D_8006C550");
extern unsigned char C43Player[] __asm__("D_80070328");
extern int C43Contact __asm__("D_8006C770");
int C43Helper36A68() __asm__("func_80036A68");
int C43CountTimerDown() __asm__("func_800359A4");
int C43RequestMobyAnimation() __asm__("func_80034F40");
int C43Helper55E84() __asm__("func_80055E84");
int C43RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int C43Helper369B8() __asm__("func_800369B8");
int C43DeleteMoby() __asm__("func_80055B18");
extern void* (*C43SpawnMoby)(int, void*)__asm__("SpawnMoby");
int C43TurnMobyTowardPlayer() __asm__("func_8003573C");
int C43ApproximatePlanarDistance() __asm__("func_8004F334");
int C43PlanarHeadingLookup() __asm__("func_8004E880");
int C43AbsoluteByteAngleDelta() __asm__("func_8004F264");
int C43H13E38() __asm__("func_80013E38");
int C43H1A358() __asm__("func_8001A358");
int C43CopyVector() __asm__("func_8004F178");
extern unsigned char C43Position[] __asm__("D_8006E020");
extern int C43Y __asm__("D_8006E024");
extern unsigned short C43Heading __asm__("D_8006E040");
extern int C43Mode __asm__("D_8006E344");
int C43PlayMobySoundEvent() __asm__("func_8003BABC");
int C43InterpolateMobyVertex() __asm__("func_80055F14");
int C43H365E4() __asm__("func_800365E4");
extern int (*C43Fragments)() __asm__("SpawnFragments");
extern int C43ContactZ __asm__("D_80071908");
extern short C43Cos[] __asm__("D_80065920"), C43Sin[] __asm__("D_800658A0");
void func_level_43_800814FC(void* input) {
    struct {
        int first[4], second[4], third[2];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$22");
    register void* position16 __asm__("$16");
    register int offset16 __asm__("$16");
    register int animation16 __asm__("$16");
    register unsigned char* child16 __asm__("$16");
    register int distance18 __asm__("$18");
    register int* vector18 __asm__("$18");
    register unsigned char* player19 __asm__("$19");
    register unsigned char* childPosition19 __asm__("$19");
    register unsigned char* player20 __asm__("$20");
    register unsigned char* childTag21 __asm__("$21");
    register int value __asm__("$2");
    register int other __asm__("$3") = 0x140000;
    register void* call4 __asm__("$4");
    register int heading4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    register int arg7 __asm__("$7");
    MATCHING_KEEP(owner);
    value = C43Field(owner, int*, 24);
    tag = C43Field(owner, unsigned char**, 0);
    if (value & other) {
        other = C43Field(tag, int*, 8);
        if (other >= 0) {
            unsigned char* linked = C43Field(C43Pool + other * 88, unsigned char**, 0);
            C43Field(linked, int*, 0)++;
        }
        C43Helper36A68(owner, 0, 0, 0);
        C43PlayMobySoundEvent(owner, 0, 0);
        C43RefreshMobySpatialGridAndBasis(owner, 4);
        C43Fragments(5, 474, owner, C43Field(tag, void**, 4), 0, 256);
        C43Helper369B8(owner, 40);
        C43DeleteMoby(owner);
        goto done;
    }
    switch (owner[72]) {
        case 0:
            if (C43ApproximatePlanarDistance(owner + 12, C43Player) < 10240) {
                owner[72] = 1;
                C43RequestMobyAnimation(owner, 1);
            }
            other = C43Field(C43Player, int*, 80);
            call4 = owner;
            if (other != 7)
                goto done;
            arg5 = 5;
            ((unsigned char*)call4)[72] = 5;
            C43RequestMobyAnimation(call4, arg5);
            C43Field(tag, short*, 2) = 0;
            C43Field(tag, short*, 0) = 10;
            break;
        case 1:
            C43TurnMobyTowardPlayer(owner, 4, 1, 1);
            if (!C43Contact)
                goto done;
            owner[72] = 2;
            call4 = owner;
            arg5 = 2;
            goto animate;
        case 2:
            position16 = owner + 12;
            call4 = position16;
            MATCHING_KEEP(call4);
            player19 = C43Player;
            value = C43ApproximatePlanarDistance(call4, player19);
            call4 = owner;
            arg5 = 4;
            arg6 = 1;
            arg7 = 1;
            MATCHING_KEEP4(call4, arg5, arg6, arg7);
            distance18 = value;
            C43TurnMobyTowardPlayer(call4, arg5, arg6, arg7);
            call4 = frame.first;
            arg5 = (int)position16;
            MATCHING_KEEP2(call4, arg5);
            value = C43Field(tag, int*, 8);
            MATCHING_KEEP(value);
            other = -3392;
            offset16 = (~value >> 31) & other;
            C43CopyVector(call4, (void*)arg5);
            call4 = tag;
            arg5 = 2;
            frame.first[2] += 800;
            if (!C43CountTimerDown(call4, arg5))
                goto retreat;
            if (distance18 >= offset16 + 8192)
                goto retreat;
            value =
                C43PlanarHeadingLookup(C43Field(player19, int*, 0) - C43Field(owner, int*, 12),
                                       C43Field(C43Player, int*, 4) - C43Field(owner, int*, 16), 0);
            if (C43AbsoluteByteAngleDelta(value, owner[70]) >= 10)
                goto retreat;
            if (!offset16) {
                __asm__("" : "=r"(arg6) : "0"(0));
                value = C43PlanarHeadingLookup(C43Field(owner, int*, 12) -
                                                   C43Field(C43Position, int*, 0),
                                               C43Field(owner, int*, 16) - C43Y, arg6);
                heading4 = C43Heading;
                MATCHING_KEEP(heading4);
                arg5 = value;
                heading4 = (heading4 << 16) >> 20;
                if (C43AbsoluteByteAngleDelta(heading4, arg5) >= 24) {
                    value = distance18 < 10241;
                    goto retreat_ready;
                }
            }
            if (C43H13E38(frame.first, C43Position, 0)) {
                owner[72] = 3;
                call4 = owner;
                arg5 = 3;
                goto animate;
            }
        retreat:
            value = distance18 < 10241;
        retreat_ready:
            MATCHING_KEEP(value);
            if (value)
                goto done;
            owner[72] = 4;
            call4 = owner;
            arg5 = 4;
            goto animate;
        case 3:
            value = C43Helper55E84(owner);
            call4 = owner;
            arg5 = 4;
            arg6 = 1;
            arg7 = 1;
            MATCHING_KEEP4(call4, arg5, arg6, arg7);
            animation16 = value;
            C43TurnMobyTowardPlayer(call4, arg5, arg6, arg7);
            if (animation16 < 22)
                goto contact3;
            value = owner[73];
            call4 = (void*)554;
            if (value)
                goto contact3;
            child16 = C43SpawnMoby((int)call4, owner);
            MATCHING_KEEP(child16);
            call4 = owner;
            if (!child16)
                goto contact3;
            arg5 = 5;
            childTag21 = C43Field(child16, unsigned char**, 0);
            owner[73] = 1;
            child16[72] = 3;
            C43RefreshMobySpatialGridAndBasis(call4, arg5);
            call4 = owner;
            arg5 = 0;
            MATCHING_KEEP(arg5);
            childPosition19 = child16 + 12;
            C43InterpolateMobyVertex(call4, arg5, childPosition19);
            player20 = C43Player;
            value = C43PlanarHeadingLookup(
                C43Field(player20, int*, 0) - C43Field(child16, int*, 12),
                C43Field(C43Player, int*, 4) - C43Field(child16, int*, 16), 0);
            vector18 = frame.second;
            call4 = vector18;
            arg5 = (int)player20;
            child16[70] = value;
            C43CopyVector(call4, (void*)arg5);
            call4 = vector18;
            arg5 = 10240;
            frame.second[2] += 1024;
            value = C43H1A358(call4, arg5);
            call4 = childPosition19;
            if (value) {
                frame.second[2] = C43ContactZ + 128;
                value = C43ApproximatePlanarDistance(call4, vector18);
                call4 = (void*)value;
                arg6 = 0;
                arg5 = C43Field(child16, int*, 20) - 384;
                value = frame.second[2];
                goto pitch;
            }
            frame.second[2] = C43Field(C43Player, int*, 8);
            value = C43ApproximatePlanarDistance(call4, player20);
            call4 = (void*)value;
            value = C43Field(C43Player, int*, 8);
            arg5 = C43Field(child16, int*, 20);
            MATCHING_KEEP2_CLOBBER(value, arg5, "$6");
            arg6 = 0;
        pitch:
            value = C43PlanarHeadingLookup((int)call4, value - arg5, arg6);
            child16[69] = value;
            C43Field(childTag21, short*, 14) = 0;
            C43Field(childTag21, short*, 12) = 200;
            MATCHING_KEEP_VOLATILE(childPosition19);
            other = C43Cos[child16[70]];
            C43Field(childTag21, int*, 0) = (other * 25) >> 9;
            other = C43Sin[child16[70]];
            C43Field(childTag21, int*, 8) = 0;
            C43Field(childTag21, int*, 4) = (other * 25) >> 9;
            C43Field(childTag21, int*, 8) =
                C43H365E4(child16 + 12, frame.second, 200, -8, frame.third);
        contact3:
            call4 = owner;
            if (!C43Contact)
                goto done;
            arg5 = 0;
            ((unsigned char*)call4)[73] = 0;
            C43Field(tag, short*, 0) = 60;
            ((unsigned char*)call4)[72] = 0;
            goto animate;
        case 4:
        case 5:
            call4 = owner;
            if (!C43Contact)
                goto done;
            owner[72] = 0;
            arg5 = 0;
        animate:
            MATCHING_OBSERVE2(call4, arg5);
            C43RequestMobyAnimation(call4, arg5);
            break;
    }
done:;
}
#undef C43Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80081A5C.
* Assembly SHA256 8d131ac705e958a0c1ad09f3c491df17fe2ea991c08a8484b1179115334a7a32.
* AI generated; not human reviewed. All541 original instructions and
* actual branch/call/internal targets are required. The selector table
* has23 entries bias0 plus one padding word. Frame50 preserves SP18..37
* locals, SP10/SP14 outgoing words and S0/S1/S2/S3/S4/RA saves/restores.
* Original SH80081BD0 writes the packed private field at+4. The initial
* private pointer is copied from S0 to S4; later position/player/raw-word
* lifetimes retain their original S0/S2/S3 ownership. Shared countdown,
* distance and delete calls stay at their original physical joins.
* Signed trig LH words, vector stores, temporary height increments and
* restorations, spawn result/private-word/heading load priority, effect
* tag155 and every original argument/load/branch slot remain exact.
* Empty initialized dependencies, original-address immediate metadata
* and clobbers of dead registers emit no CPU instructions. No partial HI,
* FP shortcut or opcode assembly is used. Raw units/fixed point, complete
* helper contracts, caller cadence and synchronized retail runtime remain
* unresolved. Cadence here is per invocation; confidence is binary identity.
* Falsification: every native/linked word and actual target, all selectors/
* padding, full EXE and every overlay retail hash must remain identical. */
#define Actor43Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor43Call1830CView1() __asm__("func_8001830C");
void* Actor43Call1BA30View1() __asm__("func_8001BA30");
int Actor43Call1C288View1() __asm__("func_8001C288");
unsigned char Actor43RequestMobyAnimationView1() __asm__("func_80034F40");
int Actor43Call35194View1() __asm__("func_80035194");
unsigned char Actor43TurnMobyTowardPlayerView1() __asm__("func_8003573C");
unsigned char Actor43TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor43CountTimerDownView1() __asm__("func_800359A4");
unsigned char Actor43Call35DDCView1() __asm__("func_80035DDC");
int Actor43RandBetweenView1() __asm__("func_8003636C");
unsigned char Actor43Call369B8View1() __asm__("func_800369B8");
unsigned char Actor43Call38BF8View1() __asm__("func_80038BF8");
unsigned char Actor43Call3BA00View1() __asm__("func_8003BA00");
unsigned char Actor43PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor43PlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor43AddVectorView1() __asm__("func_8004F194");
int Actor43AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor43ApproximatePlanarDistanceView1() __asm__("func_8004F334");
unsigned char Actor43DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor43RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor43Call55E84View1() __asm__("func_80055E84");
unsigned char Actor43InterpolateMobyVertexView1() __asm__("func_80055F14");
extern unsigned char Actor43Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor43Data65920View1 __asm__("D_80065920");
extern int Actor43Data6C550View1 __asm__("D_8006C550");
extern int Actor43Data6C770View1 __asm__("D_8006C770");
extern unsigned char Actor43Data70328View1 __asm__("D_80070328");
extern int Actor43Data7190CView1 __asm__("D_8007190C");
extern int Actor43Data71910View1 __asm__("D_80071910");
extern void* (*Actor43DataSpawnMobyView1)() __asm__("SpawnMoby");
extern void* (*Actor43DataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_43_80081A5C(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* (*particleCall3)() __asm__("$3");
    register int positionOrRawWord16 __asm__("$16"), privateRecord20 __asm__("$20"),
        playerPointerOrTag18 __asm__("$18");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34;
    } originalFrame;
    int* temporaryWord5;
    register int retainedDistance19 __asm__("$19");
    unsigned char temporaryWord4;
    void* temporaryPointer2;
    void* temporaryPointer3;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    positionOrRawWord16 = Actor43Field(ownerRecord17, void**, 0);
    temporaryWord4 = Actor43Field(ownerRecord17, unsigned char*, 0x48);
    privateRecord20 = (int)positionOrRawWord16;
    if ((temporaryWord4 != 3) && (temporaryWord4 != 0x14) &&
        (Actor43Field(ownerRecord17, unsigned char*, 0x49) == 0)) {
        if (Actor43Field(
                ((Actor43Field(positionOrRawWord16, int*, 4) * 0x58) + Actor43Data6C550View1),
                unsigned char*, 0x49) != 0) {
            Actor43Field(ownerRecord17, unsigned char*, 0x49) = 1U;
            Actor43Field(ownerRecord17, int*, 0x18) = 0;
            Actor43Field(ownerRecord17, unsigned char*, 0x48) = 0x15U;
            if (Actor43AbsoluteByteAngleDeltaView1(
                    Actor43Field(&Actor43Data70328View1, unsigned char*, 0xE),
                    Actor43PlanarHeadingLookupView1(
                        Actor43Field(ownerRecord17, int*, 0xC) -
                            Actor43Field(&Actor43Data70328View1, int*, 0),
                        Actor43Field(ownerRecord17, int*, 0x10) -
                            Actor43Field(&Actor43Data70328View1, int*, 4),
                        0)) < 0x2D) {
                Actor43Field(positionOrRawWord16, int*, 0) = 0;
            } else {
                Actor43Field(positionOrRawWord16, int*, 0) = Actor43RandBetweenView1(0, 0x12C);
            }
            goto checkOwnerStatus;
        }
    } else {
    checkOwnerStatus:
        if (Actor43Field(ownerRecord17, int*, 0x18) != 0) {
            if (Actor43Field(ownerRecord17, unsigned char*, 0x48) != 3) {
                Actor43PlayMobySoundEventView1(ownerRecord17, 0, 0);
                temporaryWord5 = Actor43Field((Actor43Field(privateRecord20, int*, 4) * 0x58) +
                                                  Actor43Data6C550View1,
                                              int**, 0);
                *temporaryWord5 += 1;
                Actor43Call38BF8View1(ownerRecord17, positionOrRawWord16, 0, 3);
                Actor43Field(positionOrRawWord16, signed char*, 0xF) = 0xC;
                Actor43Field(positionOrRawWord16, short*, 4) = 0x118;
                Actor43Field(positionOrRawWord16, short*, 6) = 0x82;
                Actor43Field(positionOrRawWord16, signed char*, 0xE) = 0xA;
                Actor43Field(positionOrRawWord16, unsigned short*, 0xC) =
                    (unsigned short)(Actor43Field(positionOrRawWord16, unsigned short*, 0xC) |
                                     0x4000);
            }
        }
        switch (Actor43Field(ownerRecord17, unsigned char*, 0x48)) {
            case 21:
                Actor43TurnMobyTowardPlayerView1(ownerRecord17, 4, 1, 1);
                positionOrRawWord16 = ownerRecord17 + 0xC;
                rawWord2 =
                    (int)Actor43Call1BA30View1(positionOrRawWord16, 0x258, 0, 0, 0, ownerRecord17);
                argumentWord4 = privateRecord20;
                if (rawWord2) {
                    Actor43Field(ownerRecord17, int*, 0xC) = (int)Actor43Data7190CView1;
                    Actor43Field(ownerRecord17, int*, 0x10) = (int)Actor43Data71910View1;
                }
                rawWord2 = Actor43CountTimerDownView1(argumentWord4, 4);
                argumentWord4 = positionOrRawWord16;
                if (rawWord2) {
                    positionOrRawWord16 = (int)&Actor43Data70328View1;
                    MATCHING_KEEP(positionOrRawWord16);
                    rawWord2 =
                        Actor43ApproximatePlanarDistanceView1(argumentWord4, positionOrRawWord16);
                    rawWord2 = rawWord2 < 8192;
                    argumentWord4 = 100;
                    if (rawWord2)
                        goto resetSharedCountdown;
                    __asm__ __volatile__("" ::: "$2", "memory");
                    argumentWord6 = 0;
                    rawWord3 = Actor43Field(ownerRecord17, int*, 0xC);
                    argumentWord4 = Actor43Field(positionOrRawWord16, int*, 0);
                    rawWord2 = Actor43Field(ownerRecord17, int*, 0x10);
                    argumentWord5 = Actor43Field(&Actor43Data70328View1, int*, 4);
                    argumentWord4 = rawWord3 - argumentWord4;
                    rawWord2 = Actor43PlanarHeadingLookupView1(
                        argumentWord4, rawWord2 - argumentWord5, argumentWord6);
                    rawWord2 = Actor43AbsoluteByteAngleDeltaView1(
                        Actor43Field(&Actor43Data70328View1, unsigned char*, 0xE), rawWord2);
                    rawWord2 = rawWord2 < 45;
                    argumentWord4 = 100;
                    if (rawWord2)
                        goto resetSharedCountdown;
                }
                __asm__ __volatile__(""
                                     : "=r"(ownerRecord17)
                                     : "0"(ownerRecord17), "i"(0x80081CE4)
                                     : "memory");
                argumentWord4 = (int)ownerRecord17 + 0xC;
                goto checkSharedNearDistance;
            case 0:
                Actor43TurnMobyTowardPlayerView1(ownerRecord17, 4, 1, 1);
                Actor43Call35DDCView1(ownerRecord17, 0x32, 0, 0, 0);
                positionOrRawWord16 = ownerRecord17 + 0xC;
                rawWord2 =
                    (int)Actor43Call1BA30View1(positionOrRawWord16, 0x258, 0, 0, 0, ownerRecord17);
                argumentWord4 = positionOrRawWord16;
                if (rawWord2) {
                    Actor43Field(ownerRecord17, int*, 0xC) = (int)Actor43Data7190CView1;
                    Actor43Field(ownerRecord17, int*, 0x10) = (int)Actor43Data71910View1;
                }
                playerPointerOrTag18 = (int)&Actor43Data70328View1;
                MATCHING_KEEP(playerPointerOrTag18);
                retainedDistance19 =
                    Actor43ApproximatePlanarDistanceView1(argumentWord4, playerPointerOrTag18);
                if (retainedDistance19 < 0x5DC) {
                    Actor43Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                    Actor43RequestMobyAnimationView1(ownerRecord17, 1);
                }
                __asm__ __volatile__("" ::: "$2", "memory");
                argumentWord6 = 0;
                rawWord3 = Actor43Field(ownerRecord17, int*, 0xC);
                argumentWord4 = Actor43Field(playerPointerOrTag18, int*, 0);
                rawWord2 = Actor43Field(ownerRecord17, int*, 0x10);
                argumentWord5 = Actor43Field(playerPointerOrTag18, int*, 4);
                argumentWord4 = rawWord3 - argumentWord4;
                rawWord2 = Actor43PlanarHeadingLookupView1(argumentWord4, rawWord2 - argumentWord5,
                                                           argumentWord6);
                rawWord2 = Actor43AbsoluteByteAngleDeltaView1(
                    Actor43Field(&Actor43Data70328View1, unsigned char*, 0xE), rawWord2);
                argumentWord4 = privateRecord20;
                argumentWord5 = 4;
                __asm__("" ::"r"(argumentWord4), "r"(argumentWord5) : "$16", "memory");
                positionOrRawWord16 = rawWord2;
                rawWord2 = Actor43CountTimerDownView1(argumentWord4, argumentWord5);
                if (!rawWord2) {
                    rawWord2 = retainedDistance19 < 8193;
                    if (rawWord2)
                        return;
                }
                rawWord2 = positionOrRawWord16 < 46;
                if (rawWord2)
                    return;
                rawWord2 = positionOrRawWord16 < 97;
                MATCHING_KEEP(rawWord2);
                if (!rawWord2) {
                    __asm__ __volatile__("" ::: "$2", "memory");
                    argumentWord6 = 0;
                    rawWord3 = Actor43Field(playerPointerOrTag18, int*, 0);
                    argumentWord4 = Actor43Field(ownerRecord17, int*, 0xC);
                    rawWord2 = Actor43Field(playerPointerOrTag18, int*, 4);
                    argumentWord5 = Actor43Field(ownerRecord17, int*, 0x10);
                    argumentWord4 = rawWord3 - argumentWord4;
                    rawWord2 = Actor43PlanarHeadingLookupView1(
                        argumentWord4, rawWord2 - argumentWord5, argumentWord6);
                    argumentWord4 = 0;
                    argumentWord5 = 128;
                    __asm__("" ::"r"(argumentWord4), "r"(argumentWord5) : "$16", "memory");
                    positionOrRawWord16 = rawWord2;
                    rawWord2 = Actor43RandBetweenView1(argumentWord4, argumentWord5);
                    positionOrRawWord16 -= 64;
                    positionOrRawWord16 += rawWord2;
                    Actor43Field(privateRecord20, int*, 8) = positionOrRawWord16;
                    Actor43Field(ownerRecord17, unsigned char*, 0x48) = 22;
                    return;
                }
                argumentWord4 = 30;
                argumentWord5 = 120;
                rawWord2 = 21;
                __asm__ __volatile__("" ::"i"(0x80081E44) : "memory");
                Actor43Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                goto setSharedCountdown;
            case 22:
                Actor43TurnMobyTowardHeadingView1(
                    ownerRecord17, Actor43Field(privateRecord20, int*, 8), 2, 1, 1, 0);
                Actor43Call35DDCView1(ownerRecord17, 0x32, 0, 0, 0);
                temporaryPointer2 =
                    Actor43Call1BA30View1(ownerRecord17 + 0xC, 0x258, 0, 0, 0, ownerRecord17);
                if (temporaryPointer2 != 0) {
                    Actor43Field(ownerRecord17, int*, 0xC) = (int)Actor43Data7190CView1;
                    Actor43Field(ownerRecord17, int*, 0x10) = (int)Actor43Data71910View1;
                    rawWord2 = Actor43AbsoluteByteAngleDeltaView1(
                        Actor43PlanarHeadingLookupView1(
                            Actor43Field(temporaryPointer2, int*, 0xC) -
                                Actor43Field(ownerRecord17, int*, 0xC),
                            Actor43Field(temporaryPointer2, int*, 0x10) - Actor43Data71910View1, 0),
                        Actor43Field(ownerRecord17, unsigned char*, 0x46));
                    rawWord2 = rawWord2 < 3;
                    argumentWord4 = 90;
                    if (rawWord2) {
                        argumentWord5 = 200;
                        rawWord2 = 21;
                        __asm__ __volatile__("" ::"i"(0x80081F00) : "memory");
                        Actor43Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                        goto setSharedCountdown;
                    }
                }
                rawWord2 = Actor43Field(ownerRecord17, unsigned char*, 0x46);
                __asm__ __volatile__("" ::: "$4", "memory");
                argumentWord4 = (int)&originalFrame.sp18;
                MATCHING_KEEP(argumentWord4);
                rawWord2 = Actor43Field(&Actor43Data65920View1, short*, rawWord2 * 2);
                __asm__ __volatile__("" ::: "$16", "memory");
                positionOrRawWord16 = (int)ownerRecord17 + 12;
                MATCHING_KEEP2(rawWord2, positionOrRawWord16);
                rawWord2 >>= 3;
                originalFrame.sp18 = rawWord2;
                rawWord2 = Actor43Field(ownerRecord17, unsigned char*, 0x46);
                __asm__ __volatile__("" ::: "$5", "memory");
                argumentWord5 = positionOrRawWord16;
                rawWord2 = Actor43Field(&Actor43Data658A0View1, short*, rawWord2 * 2);
                __asm__ __volatile__("" ::: "$6", "memory");
                argumentWord6 = argumentWord4;
                originalFrame.sp20 = 0;
                __asm__ __volatile__(""
                                     : "=r"(rawWord2)
                                     : "0"(rawWord2), "m"(originalFrame.sp20)
                                     : "memory");
                rawWord2 >>= 3;
                originalFrame.sp1C = rawWord2;
                Actor43AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                argumentWord4 = positionOrRawWord16;
                argumentWord5 = (int)&originalFrame.sp18;
                argumentWord6 = 3;
                rawWord2 = Actor43Field(ownerRecord17, int*, 0x14);
                argumentWord7 = 0;
                rawWord2 += 128;
                Actor43Field(ownerRecord17, int*, 0x14) = rawWord2;
                rawWord2 = Actor43Call1830CView1(argumentWord4, argumentWord5, argumentWord6,
                                                 argumentWord7, 0);
                argumentWord4 = 90;
                if (rawWord2) {
                    argumentWord5 = 200;
                    rawWord2 = Actor43Field(ownerRecord17, int*, 0x14);
                    rawWord3 = 21;
                    Actor43Field(ownerRecord17, unsigned char*, 0x48) = rawWord3;
                    rawWord2 -= 128;
                    Actor43Field(ownerRecord17, int*, 0x14) = rawWord2;
                setSharedCountdown:
                    Actor43Field(privateRecord20, int*, 0) =
                        Actor43RandBetweenView1(argumentWord4, argumentWord5);
                    return;
                }
                __asm__ __volatile__("" ::: "$2", "memory");
                argumentWord6 = 0;
                __asm__ __volatile__(""
                                     : "=r"(argumentWord6)
                                     : "0"(argumentWord6)
                                     : "$18", "memory");
                playerPointerOrTag18 = (int)&Actor43Data70328View1;
                MATCHING_KEEP(playerPointerOrTag18);
                rawWord2 = Actor43Field(ownerRecord17, int*, 0x14);
                rawWord3 = Actor43Field(ownerRecord17, int*, 0xC);
                rawWord2 -= 128;
                Actor43Field(ownerRecord17, int*, 0x14) = rawWord2;
                argumentWord4 = Actor43Field(playerPointerOrTag18, int*, 0);
                rawWord2 = Actor43Field(ownerRecord17, int*, 0x10);
                argumentWord5 = Actor43Field(&Actor43Data70328View1, int*, 4);
                argumentWord4 = rawWord3 - argumentWord4;
                rawWord2 = Actor43PlanarHeadingLookupView1(argumentWord4, rawWord2 - argumentWord5,
                                                           argumentWord6);
                rawWord2 = Actor43AbsoluteByteAngleDeltaView1(
                    Actor43Field(&Actor43Data70328View1, unsigned char*, 0xE), rawWord2);
                rawWord2 = rawWord2 < 45;
                argumentWord4 = 100;
                if (rawWord2)
                    goto resetSharedCountdown;
                argumentWord4 = positionOrRawWord16;
            checkSharedNearDistance:
                if (Actor43ApproximatePlanarDistanceView1(argumentWord4, &Actor43Data70328View1) <
                    1500) {
                    Actor43Field(ownerRecord17, unsigned char*, 0x48) = 1;
                    Actor43RequestMobyAnimationView1(ownerRecord17, 1);
                }
                return;
            case 1:
                rawWord2 = Actor43Call55E84View1(ownerRecord17);
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 4;
                argumentWord6 = 1;
                argumentWord7 = 1;
                __asm__("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6),
                        "r"(argumentWord7)
                        : "$16", "memory");
                positionOrRawWord16 = rawWord2;
                Actor43TurnMobyTowardPlayerView1(argumentWord4, argumentWord5, argumentWord6,
                                                 argumentWord7);
                if (Actor43Call1BA30View1(ownerRecord17 + 0xC, 0x258, 0, 0, 0, ownerRecord17) !=
                    0) {
                    Actor43Field(ownerRecord17, int*, 0xC) = (int)Actor43Data7190CView1;
                    Actor43Field(ownerRecord17, int*, 0x10) = (int)Actor43Data71910View1;
                }
                rawWord3 = Actor43Field(ownerRecord17, unsigned char*, 0x49);
                rawWord2 = 1;
                if (rawWord3 == rawWord2) {
                    rawWord2 = positionOrRawWord16 - 13;
                    rawWord2 = (unsigned int)rawWord2 < 4;
                    if (rawWord2) {
                        positionOrRawWord16 = (int)Actor43DataSpawnMobyView1(0x1ED, ownerRecord17);
                        MATCHING_KEEP(positionOrRawWord16);
                        if (positionOrRawWord16 != 0) {
                            Actor43Field(ownerRecord17, unsigned char*, 0x49) = 2U;
                            Actor43RefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
                            Actor43InterpolateMobyVertexView1(ownerRecord17, 0,
                                                              positionOrRawWord16 + 0xC);
                            Actor43Field(positionOrRawWord16, signed char*, 0x48) = 0x14;
                            rawWord2 = Actor43Field(ownerRecord17, unsigned char*, 0x46);
                            rawWord3 = Actor43Field(positionOrRawWord16, int*, 0);
                            Actor43Field(positionOrRawWord16, unsigned char*, 0x41) = 0;
                            Actor43Field(positionOrRawWord16, unsigned char*, 0x4C) = 0;
                            Actor43Field(positionOrRawWord16, unsigned char*, 0x4D) = 0;
                            Actor43Field(positionOrRawWord16, int*, 8) = 0;
                            Actor43Field(positionOrRawWord16, unsigned char*, 0x46) = rawWord2;
                            rawWord2 = 15;
                            Actor43Field(rawWord3, int*, 0) = rawWord2;
                        }
                    }
                }
                if (Actor43Data6C770View1 != 0) {
                    Actor43Field(ownerRecord17, unsigned char*, 0x49) = 1U;
                    Actor43RequestMobyAnimationView1(ownerRecord17, 0);
                    Actor43Field(ownerRecord17, unsigned char*, 0x48) = 0x15U;
                    Actor43Field(privateRecord20, int*, 0) = 0x3C;
                    return;
                }
                break;
            case 2:
                if ((unsigned int)(Actor43Call55E84View1(ownerRecord17) - 2) < 0xEU) {
                    Actor43Call35DDCView1(ownerRecord17, 0x64, 0, 0, 4);
                }
                rawWord2 = Actor43Data6C770View1;
                argumentWord4 = 100;
                if (!rawWord2)
                    return;
            resetSharedCountdown:
                Actor43Field(privateRecord20, int*, 0) =
                    Actor43RandBetweenView1(argumentWord4, 300);
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 0;
                Actor43Field(argumentWord4, unsigned char*, 0x48) = 0;
                Actor43RequestMobyAnimationView1(argumentWord4, argumentWord5);
                return;
            case 20:
                playerPointerOrTag18 = 0x14;
                Actor43Call35DDCView1(ownerRecord17, 0x46, 0, 0, 0);
                positionOrRawWord16 = ownerRecord17 + 0xC;
                Actor43Field(ownerRecord17, int*, 8) = 0;
                if (Actor43Call1C288View1(positionOrRawWord16, 0x64, 7) != 0) {
                    playerPointerOrTag18 = 0x9B;
                    Actor43Field(&Actor43Data70328View1, int*, 0x298) =
                        (int)Actor43Field(ownerRecord17, unsigned char*, 0x46);
                    Actor43Field(privateRecord20, int*, 0) = 0;
                }
                originalFrame.sp28 = 0;
                originalFrame.sp2C = 0;
                originalFrame.sp30 = 1;
                temporaryPointer3 = Actor43DataSpawnParticleView1(1, 0x3C, positionOrRawWord16,
                                                                  &originalFrame.sp28);
                if (temporaryPointer3 != 0) {
                    Actor43Field(temporaryPointer3, signed char*, 0xA) = playerPointerOrTag18;
                }
                if (Actor43CountTimerDownView1(privateRecord20, 4) != 0) {
                    goto deleteOwner;
                }
                break;
            case 3:
                if (Actor43Call35194View1(ownerRecord17, positionOrRawWord16) == 0x100) {
                    Actor43RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                    if (Actor43Field(ownerRecord17, unsigned char*, 0x3A) == 0xFF) {
                        Actor43Call3BA00View1(ownerRecord17);
                    }
                    Actor43Call369B8View1(ownerRecord17, 0x20);
                deleteOwner:
                    Actor43DeleteMobyView1(ownerRecord17);
                }
                break;
        }
    }
}
#undef Actor43Field

typedef struct {
    int timer, linkedIndex;
} DecodedLinkedCounterTag;
extern int DecodedFragmentResult(Moby*) __asm__("func_80039714");
extern short DecodedResetCounters[] __asm__("D_80066EAE");
extern Moby* D_8006C550;
extern int D_8006C640, D_8006C54C;
int func_800359A4(void*, int);
int func_8003636C(int, int);
void DecodedCounterFragments(int, int, Moby*, int, int, int, int) __asm__("func_800391E8");
void func_80055D24(Moby*, int);
void func_800369B8(Moby*, int);
void func_8003BA00(Moby*);
void func_80055B18(Moby*);
void func_80034F80(Moby*, int);
int func_8003BABC(Moby*, int, int);
void func_level_43_800822D0(Moby* moby) {
    DecodedLinkedCounterTag* tag = (DecodedLinkedCounterTag*)moby->mobyTag;
    Moby* linked;
    Moby* spawned;
    int offset;
    int yaw;
    int* counter;
    if (moby->linkedMoby != 255) {
        if (DecodedFragmentResult(moby)) {
            func_80055D24(moby, 4);
            func_800369B8(moby, 32);
            SpawnParticle(8, 70, &moby->position, (Vector3D*)16);
        }
        return;
    }
    if (D_8006C640 && !D_8006C54C) {
        for (offset = 44; offset >= 0; offset -= 4)
            *(short*)((char*)DecodedResetCounters + offset) = 0;
    }
    if (!moby->substate) {
        linked = (Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550);
        if (!linked->substate)
            return;
        moby->damageFlags = 0;
        moby->substate = 1;
    }
    if (moby->damageFlags) {
        func_8003BABC(moby, 0, 0);
        DecodedCounterFragments(4, 494, moby, 1, 4, 75, 256);
        linked = (Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550);
        counter = (int*)linked->mobyTag;
        (*counter)++;
        func_80055D24(moby, 4);
        func_8003BA00(moby);
        func_800369B8(moby, 48);
        func_80055B18(moby);
        return;
    }
    if (func_800359A4(tag, 4)) {
        linked = (Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550);
        if (*(int*)linked->mobyTag > 0) {
            spawned = SpawnMoby(493, moby);
            if (spawned) {
                linked = (Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550);
                counter = (int*)linked->mobyTag;
                (*counter)--;
                yaw = moby->angle.yaw;
                spawned->state = 2;
                spawned->substate = 1;
                spawned->angle.yaw = yaw;
                ((int*)spawned->mobyTag)[1] = tag->linkedIndex;
                func_80034F80(spawned, spawned->state);
                tag->timer = func_8003636C(270, 330);
            }
        }
    }
}

typedef struct {
    unsigned char reserved00[0x18];
    int timer;
    unsigned char fragment[0x18];
} DecodedTimedFragmentActorTag;
extern int D_8006C770;
void DecodedTimedFragmentClear(void*, int, int) __asm__("func_8004E790");
void DecodedTimedFragmentStart(Moby*, void*, int, int) __asm__("func_80038BF8");
int DecodedTimedFragmentUpdate(Moby*, void*) __asm__("func_80035194");
int DecodedTimedFragmentDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int DecodedTimedFragmentTimer(void*, int) __asm__("func_800359A4");
void DecodedTimedFragmentMovement(Moby*, void*, int) __asm__("func_80037168");
void func_level_43_80082594(Moby* moby) {
    DecodedTimedFragmentActorTag* tag = moby->mobyTag;
    unsigned char* fragment;
    int magnitude, mode;
    if (moby->state != 2 && moby->damageFlags) {
        func_8003BABC(moby, 0, 0);
        SpawnMoby(0x10, moby);
        fragment = tag->fragment;
        DecodedTimedFragmentClear(fragment, 0, 0x18);
        moby->state = 2;
        DecodedTimedFragmentStart(moby, fragment, 8, 0);
        magnitude = 0xC8;
        MATCHING_KEEP(magnitude);
        *(short*)(tag->fragment + 0xC) = 1;
        tag->fragment[0x16] = 0x78;
        __asm__("" ::: "$2", "memory");
        mode = 0x17;
        *(short*)(tag->fragment + 0xA) = magnitude;
        tag->fragment[0xE] = 2;
        *(short*)(tag->fragment + 6) = magnitude;
        tag->fragment[0xF] = mode;
        moby->state = 2;
        return;
    }
    switch (moby->state) {
        case 0:
            if (moby->drawn &&
                DecodedTimedFragmentDistance(&moby->position, (Vector3D*)&spyro) < 0x4000 &&
                DecodedTimedFragmentTimer(&tag->timer, 4) && D_8006C770) {
                tag->timer = func_8003636C(3, 7);
                moby->state = 1;
                func_80034F40(moby, 1);
                moby->animationProgress = 0xF0;
            }
            break;
        case 1:
            if (moby->animationState.id == 1)
                DecodedTimedFragmentMovement(moby, tag, 1);
            if (D_8006C770 && --tag->timer <= 0) {
                tag->timer = func_8003636C(0x46, 0x78);
                moby->state = 0;
                func_80034F40(moby, 0);
                moby->animationProgress = 0xF0;
            }
            break;
        case 2:
            if (DecodedTimedFragmentUpdate(moby, tag->fragment) == 0x100) {
                func_80055D24(moby, 4);
                func_8003BA00(moby);
                func_800369B8(moby, 0x19);
                func_80055B18(moby);
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_43/moby/func_level_43_800827C4.s SHA256 2d903f76f865b0d660b1e84cdef80eb14f7324fd45792571e338f9c4f2ff945a. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level43_827C4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level43_827C4_D_8006C550 __asm__("D_8006C550");
extern Spyro Level43_827C4_D_80070328 __asm__("D_80070328");
void Level43_827C4RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level43_827C4_func_80035194(Moby*, void*) __asm__("func_80035194");
int Level43_827C4TurnMobyTowardPlayer(Moby* ownerRecord18, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level43_827C4TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
int Level43_827C4CountTimerDown(void*, int) __asm__("func_800359A4");
int Level43_827C4ProbeGroundFromRaisedMoby(Moby* moby) __asm__("func_80035D38");
int Level43_827C4_func_80035DDC(Moby* ownerRecord18, int arg1, int arg2, int arg3,
                                int arg4) __asm__("func_80035DDC");
void Level43_827C4_func_800369B8() __asm__("func_800369B8");
void Level43_827C4_func_80038BF8(Moby*, EnemyTag*, int, int) __asm__("func_80038BF8");
extern int Level43_827C4PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level43_827C4ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level43_827C4CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level43_827C4AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level43_827C4AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level43_827C4ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level43_827C4DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level43_827C4RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level43_827C4_func_80055E84(Moby*) __asm__("func_80055E84");

unsigned int Level43_827C4SetMobyAnimation() __asm__("func_80034F80");
/* extern */
unsigned int Level43_827C4_func_80035A80() __asm__("func_80035A80");
/* extern */
unsigned int Level43_827C4_func_80036A68() __asm__("func_80036A68");
/* extern */
extern int Level43_827C4_D_8006C640 __asm__("D_8006C640");
extern int Level43_827C4_D_8006C770 __asm__("D_8006C770");
extern int Level43_827C4_D_8006E020 __asm__("D_8006E020");
extern int Level43_827C4_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level43_827C4_D_8006E040 __asm__("D_8006E040");

void func_level_43_800827C4(Moby* ownerRecord18) {
    /* Original0x68-byte frame;
     raw scratch vectors atSP+0x20/30/40.
     * All pointer adjustments below preserve original byte offsets.
     * Shared tails retain the original source path and instruction joins:
     * J74 lands at117, skipping store116 on the first draw path.
     * Saved literal17, array pointer16 and caller4/5 retain their original
     * lifetimes;
      the second draw path alone stores returned word2.
     * The state2 call shares its original caller setup, while the earlier
     * state1-to-state2 path keeps its separately emitted helper call.
     * Indexed record arithmetic preserves original0x58-byte stride.
     * Initialized empty constraints contain no instruction assembly.
     * Units, helper semantics and frame cadence remain unresolved. */
    struct {
        Vector3D sp20;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[4];
        Vector3D sp40;
        unsigned char pad4C[4];
    } originalFrame;

    register Vector3D* originalPosition4 __asm__("4");
    register Moby* indexedRecord2 __asm__("2");
    register Moby* selectedRecord16 __asm__("16");
    register int sharedWord2 __asm__("2");
    register Moby* sharedOwner4 __asm__("4");
    register int sharedParameter5 __asm__("5");
    register int drawState17 __asm__("17");
    register unsigned int drawByte3 __asm__("3");
    register Moby* stateOwner4 __asm__("4");
    register int stateParameter5 __asm__("5");
    register unsigned int stateWord2 __asm__("2");
    int temp_s0;
    int differenceWord20;
    int helperWord2;
    unsigned int rawState3;
    register unsigned int nextRawState2 __asm__("2");
    void* privateRecord19;
    void* temp_v0;
    void* temp_v0_4;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_4;

    privateRecord19 = ownerRecord18->mobyTag;
    if ((ownerRecord18->state != 6) && (ownerRecord18->damageFlags & 0x9F0000)) {
        Level43_827C4_func_80036A68(ownerRecord18, 0, 0, 0);
        Level43_827C4_func_80038BF8(ownerRecord18, privateRecord19 + 0xC, 1, 6);
    }
    rawState3 = ownerRecord18->state;
    switch (rawState3) {
        case 0x1E:
            if (Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                0x80) {
                if (Level43_827C4_D_8006C640 != 0) {
                    Level43_827C4RequestMobyAnimation(ownerRecord18, 5);
                    drawState17 = 0x20;
                    MATCHING_KEEP(drawState17);
                    originalPosition4 = &ownerRecord18->position;
                    MATCHING_KEEP(originalPosition4);
                    ownerRecord18->state = drawState17;
                    {
                        register int index3 __asm__("3");
                        index3 = Level43_827C4Field(privateRecord19, int*, 4);
                        selectedRecord16 = Level43_827C4_D_8006C550;
                        MATCHING_KEEP2(index3, selectedRecord16);
                        selectedRecord16 += index3;
                    }
                    Level43_827C4CopyVector(originalPosition4, &selectedRecord16->position);
                    sharedOwner4 = ownerRecord18;
                    MATCHING_KEEP(sharedOwner4);
                    sharedParameter5 = 7;
                    goto block_11;
                }
                goto block_74;
            }
            ownerRecord18->unknown3[0] = 0;
            ownerRecord18->lowDrawDistance = 0;
            ownerRecord18->drawn = 0;
            ownerRecord18->unknownCollision = 0;
            nextRawState2 = 0x50;
            goto block_76;
        case 0x50:
            if (Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                0x80) {
                Level43_827C4RequestMobyAnimation(ownerRecord18, 5);
                drawState17 = 0x20;
                MATCHING_KEEP(drawState17);
                originalPosition4 = &ownerRecord18->position;
                MATCHING_KEEP(originalPosition4);
                ownerRecord18->state = drawState17;
                {
                    register int index3 __asm__("3");
                    index3 = Level43_827C4Field(privateRecord19, int*, 4);
                    selectedRecord16 = Level43_827C4_D_8006C550;
                    MATCHING_KEEP2(index3, selectedRecord16);
                    selectedRecord16 += index3;
                }
                Level43_827C4CopyVector(originalPosition4, &selectedRecord16->position);
                sharedWord2 = Level43_827C4ProbeGroundFromRaisedMoby(ownerRecord18);
                sharedOwner4 = ownerRecord18;
                MATCHING_KEEP(sharedOwner4);
                sharedParameter5 = 7;
                sharedOwner4->position.z = sharedWord2;
            block_11:
                drawByte3 = selectedRecord16->angle.yaw;
                MATCHING_KEEP(drawByte3);
                sharedOwner4->unknown3[0] = 1;
                sharedOwner4->lowDrawDistance = drawState17;
                sharedOwner4->drawn = 1;
                sharedOwner4->angle.yaw = drawByte3;
                Level43_827C4RefreshMobySpatialGridAndBasis(sharedOwner4, sharedParameter5);
                return;
            }
            break;
        case 0x20:
            if (Level43_827C4_D_8006C770 == 0)
                return;
            goto block_29;
        case 0x0:
            Level43_827C4CopyVector(&originalFrame.sp20, &Level43_827C4_D_80070328.unk7a[3]);
            originalFrame.sp20.x = (int)originalFrame.sp20.x * 0xF;
            originalFrame.sp20.y *= 0xF;
            originalFrame.sp20.z *= 0xF;
            Level43_827C4ShiftVectorRightTowardZero(&originalFrame.sp20, 6);
            Level43_827C4AddVector(
                &originalFrame.sp20, &originalFrame.sp20,
                (Vector3D*)((unsigned char*)&Level43_827C4_D_80070328.unk7a[3] - 0x98));
            if (Level43_827C4ApproximatePlanarDistance(&ownerRecord18->position,
                                                       &originalFrame.sp20) >= 0xC1C) {
                Level43_827C4_func_80035A80(ownerRecord18,
                                            Level43_827C4Field(privateRecord19, void**, 8), 0x78,
                                            0x64, 0, 6, 0x20, 0x20004);
                temp_v1_2 = Level43_827C4Field(privateRecord19, void**, 8);
                if (Level43_827C4Field(temp_v1_2, short*, 2) !=
                    (Level43_827C4Field(temp_v1_2, short*, 0) - 1))
                    return;
                goto block_29;
            } else {
                goto block_29;
            }
            break;
        case 0x14:
            if (!(Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                  0x80)) {
                temp_v1_3 = Level43_827C4Field(privateRecord19, void**, 8);
                temp_v0 = (Level43_827C4Field(temp_v1_3, short*, 2) * 0x10) +
                          Level43_827C4Field(temp_v1_3, int*, 0xC);
                if (Level43_827C4TurnMobyTowardHeading(
                        ownerRecord18,
                        Level43_827C4PlanarHeadingLookup(
                            Level43_827C4Field(temp_v0, int*, 0) - ownerRecord18->position.x,
                            Level43_827C4Field(temp_v0, int*, 4) - ownerRecord18->position.y, 0),
                        6, 2, 1, 0) != 0) {
                    Level43_827C4RequestMobyAnimation(ownerRecord18, 0);
                    nextRawState2 = 0x15;
                    goto block_76;
                }
            } else {
                goto block_29;
            }
            break;
        case 0x15:
            Level43_827C4CopyVector(&originalFrame.sp30, &Level43_827C4_D_80070328.unk7a[3]);
            originalFrame.sp30.x = (int)originalFrame.sp30.x * 0x1E;
            originalFrame.sp30.y *= 0x1E;
            originalFrame.sp30.z *= 0x1E;
            Level43_827C4ShiftVectorRightTowardZero(&originalFrame.sp30, 6);
            Level43_827C4AddVector(
                &originalFrame.sp30, &originalFrame.sp30,
                (Vector3D*)((unsigned char*)&Level43_827C4_D_80070328.unk7a[3] - 0x98));
            if ((Level43_827C4ApproximatePlanarDistance(&ownerRecord18->position,
                                                        &originalFrame.sp30) >= 0xC1C) &&
                !(Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                  0x80)) {
                Level43_827C4_func_80035A80(ownerRecord18,
                                            Level43_827C4Field(privateRecord19, void**, 8), 0x78,
                                            0x64, 0, 4, 0x20, 4);
                if (Level43_827C4Field(Level43_827C4Field(privateRecord19, void**, 8), short*, 2) ==
                    0) {
                    ownerRecord18->state = 0x52;
                    return;
                }
            } else {
                goto block_29;
            }
            break;
        case 0x52:
            indexedRecord2 = (Moby*)((Level43_827C4Field(privateRecord19, int*, 4) * 0x58) +
                                     (int)Level43_827C4_D_8006C550);
            MATCHING_KEEP(indexedRecord2);
            helperWord2 = Level43_827C4PlanarHeadingLookup(
                indexedRecord2->position.x - ownerRecord18->position.x,
                indexedRecord2->position.y - ownerRecord18->position.y, 0);
            if (!(Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                  0x80)) {
                Level43_827C4TurnMobyTowardHeading(ownerRecord18, helperWord2, 6, 2, 1, 0);
                Level43_827C4_func_80035DDC(ownerRecord18, 0x64, 0, 0, 4);
                if (Level43_827C4ApproximatePlanarDistance(
                        &ownerRecord18->position,
                        &Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)]
                             .position) < 0x78) {
                    Level43_827C4Field(privateRecord19, short*, 0) = 0xF;
                    ownerRecord18->state = 0x17;
                    Level43_827C4RequestMobyAnimation(ownerRecord18, 5);
                    ownerRecord18->animationProgress = 0xF0;
                    return;
                }
            } else {
            block_28:
                goto block_29;
            }
            break;
        case 0x17:
            if (Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                0x80) {
            block_29:
                ownerRecord18->state = 1;
                Level43_827C4RequestMobyAnimation(ownerRecord18, 1);
                return;
            }
            if (Level43_827C4CountTimerDown(privateRecord19, 2) != 0) {
                Level43_827C4SetMobyAnimation(ownerRecord18, 0);
                nextRawState2 = 0x1E;
                goto block_76;
            }
            break;
        case 0x1:
            Level43_827C4TurnMobyTowardPlayer(ownerRecord18, 4, 1, 1);
            if ((Level43_827C4CountTimerDown(privateRecord19 + 2, 2) != 0) &&
                (Level43_827C4ApproximatePlanarDistance(
                     &ownerRecord18->position, &Level43_827C4_D_80070328.position) < 0xC1C) &&
                (Level43_827C4AbsoluteByteAngleDelta(
                     Level43_827C4PlanarHeadingLookup(
                         Level43_827C4_D_80070328.position.x - ownerRecord18->position.x,
                         Level43_827C4_D_80070328.position.y - ownerRecord18->position.y, 0),
                     (int)ownerRecord18->angle.yaw) < 0xA) &&
                (Level43_827C4AbsoluteByteAngleDelta(
                     (int)(Level43_827C4_D_8006E040 << 0x10) >> 0x14,
                     Level43_827C4PlanarHeadingLookup(
                         ownerRecord18->position.x - Level43_827C4_D_8006E020,
                         ownerRecord18->position.y - Level43_827C4_D_8006E024, 0)) < 0x16)) {
                ownerRecord18->state = 3;
                Level43_827C4RequestMobyAnimation(ownerRecord18, 3);
            }
            if (Level43_827C4_D_8006C770 != 0) {
                ownerRecord18->state = 2;
                Level43_827C4RequestMobyAnimation(ownerRecord18, 2);
                return;
            }
            break;
        case 0x2:
            Level43_827C4TurnMobyTowardPlayer(ownerRecord18, 4, 1, 1);
            Level43_827C4CopyVector(&originalFrame.sp40, &Level43_827C4_D_80070328.unk7a[3]);
            originalFrame.sp40.x = (int)originalFrame.sp40.x * 0x19;
            originalFrame.sp40.y *= 0x19;
            originalFrame.sp40.z *= 0x19;
            Level43_827C4ShiftVectorRightTowardZero(&originalFrame.sp40, 6);
            Level43_827C4AddVector(
                &originalFrame.sp40, &originalFrame.sp40,
                (Vector3D*)((unsigned char*)&Level43_827C4_D_80070328.unk7a[3] - 0x98));
            temp_s0 = Level43_827C4ApproximatePlanarDistance(&ownerRecord18->position,
                                                             &originalFrame.sp40);
            if ((Level43_827C4CountTimerDown(privateRecord19 + 2, 2) != 0) && (temp_s0 < 0xC1C) &&
                (Level43_827C4AbsoluteByteAngleDelta(
                     Level43_827C4PlanarHeadingLookup(
                         Level43_827C4_D_80070328.position.x - ownerRecord18->position.x,
                         Level43_827C4_D_80070328.position.y - ownerRecord18->position.y, 0),
                     (int)ownerRecord18->angle.yaw) < 0xA) &&
                (Level43_827C4AbsoluteByteAngleDelta(
                     (int)(Level43_827C4_D_8006E040 << 0x10) >> 0x14,
                     Level43_827C4PlanarHeadingLookup(
                         ownerRecord18->position.x - Level43_827C4_D_8006E020,
                         ownerRecord18->position.y - Level43_827C4_D_8006E024, 0)) < 0x16)) {
                ownerRecord18->state = 3;
                Level43_827C4RequestMobyAnimation(ownerRecord18, 3);
                return;
            }
            temp_v0_4 = Level43_827C4Field(privateRecord19, void**, 8);
            if ((Level43_827C4Field(temp_v0_4, short*, 2) >=
                 (Level43_827C4Field(temp_v0_4, short*, 0) - 1)) ||
                (temp_s0 < 0xC1D)) {
                if ((temp_s0 >= 0x4001) &&
                    !(Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                      0x80)) {
                    Level43_827C4RequestMobyAnimation(ownerRecord18, 0);
                    ownerRecord18->state = 0x14;
                    temp_v1_4 = Level43_827C4Field(privateRecord19, void**, 8);
                    Level43_827C4Field(temp_v1_4, short*, 2) =
                        (short)((unsigned short)Level43_827C4Field(temp_v1_4, short*, 0) - 2);
                    Level43_827C4Field(Level43_827C4Field(privateRecord19, void**, 8), short*,
                                       0xA) = -1;
                    return;
                }
            } else {
                goto block_69;
            }
            break;
        case 0x3:
            Level43_827C4TurnMobyTowardPlayer(ownerRecord18, 4, 1, 1);
            differenceWord20 = (ownerRecord18->position.z - ownerRecord18->distanceToGround) -
                               Level43_827C4_D_80070328.position.z;
            if ((ownerRecord18->substate != 1) && (ownerRecord18->animationState.id == 3) &&
                (Level43_827C4_func_80055E84(ownerRecord18) >= 0x15) &&
                (Level43_827C4_func_80055E84(ownerRecord18) < 0x17) &&
                (Level43_827C4_D_80070328.unk20[2] == 0) &&
                (Level43_827C4AbsoluteByteAngleDelta(
                     (int)ownerRecord18->angle.yaw,
                     Level43_827C4PlanarHeadingLookup(
                         Level43_827C4_D_80070328.position.x - ownerRecord18->position.x,
                         Level43_827C4_D_80070328.position.y - ownerRecord18->position.y, 0)) <
                 8) &&
                (Level43_827C4AbsoluteByteAngleDelta(
                     (int)(Level43_827C4_D_8006E040 << 0x10) >> 0x14,
                     Level43_827C4PlanarHeadingLookup(
                         ownerRecord18->position.x - Level43_827C4_D_8006E020,
                         ownerRecord18->position.y - Level43_827C4_D_8006E024, 0)) < 0x16) &&
                (Level43_827C4ApproximatePlanarDistance(
                     &ownerRecord18->position,
                     (Vector3D*)((unsigned char*)&Level43_827C4_D_80070328.position.z - 8)) <
                 0xC1C) &&
                ((unsigned int)(differenceWord20 + 0x3FF) < 0x47FU)) {
                Level43_827C4_D_80070328.unk22[5] = (int)ownerRecord18->angle.yaw;
                Level43_827C4_D_80070328.damageFlags |= 7;
                ownerRecord18->substate = 1;
            }
            if (Level43_827C4_D_8006C770 != 0) {
                if (ownerRecord18->substate == 1) {
                    Level43_827C4Field(privateRecord19, short*, 2) = 0x32;
                }
                stateOwner4 = ownerRecord18;
                stateParameter5 = 2;
                stateWord2 = 2;
                MATCHING_KEEP3(stateOwner4, stateParameter5, stateWord2);
                stateOwner4->substate = 0;
                goto block_65;
            }
            break;
        case 0x4:
            Level43_827C4TurnMobyTowardPlayer(ownerRecord18, 4, 1, 1);
            if (Level43_827C4_D_8006C770 != 0) {
                stateOwner4 = ownerRecord18;
                stateParameter5 = 2;
                MATCHING_KEEP2(stateOwner4, stateParameter5);
                Level43_827C4Field(privateRecord19, short*, 2) = 0x1E;
                stateWord2 = 2;
                MATCHING_KEEP(stateWord2);
            block_65:
                stateOwner4->state = stateWord2;
                Level43_827C4RequestMobyAnimation(stateOwner4, stateParameter5);
                return;
            }
            break;
        case 0x5:
            if ((unsigned int)(Level43_827C4_func_80055E84(ownerRecord18) - 4) < 0xFU) {
                Level43_827C4_func_80035DDC(ownerRecord18, 0x64, 0, 0, 4);
            }
            if (Level43_827C4_D_8006C770 != 0) {
            block_69:
                ownerRecord18->state = 0;
                Level43_827C4RequestMobyAnimation(ownerRecord18, 0);
                return;
            }
            break;
        case 0x6:
            if (Level43_827C4_func_80035194(ownerRecord18, privateRecord19 + 0xC) == 0x100) {
                ownerRecord18->state = 0x22;
                Level43_827C4Field(privateRecord19, short*, 0) = 0x190;
                Level43_827C4RefreshMobySpatialGridAndBasis(ownerRecord18, 4);
                Level43_827C4_func_800369B8(ownerRecord18, 0x20);
                ownerRecord18->damageFlags = 0;
                ownerRecord18->unknownCollision = 0;
                ownerRecord18->unknown3[0] = 0;
                ownerRecord18->lowDrawDistance = 0;
                ownerRecord18->drawn = 0;
                if (Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                    0x80) {
                    goto block_74;
                }
            }
            break;
        case 0x22:
            if (Level43_827C4_D_8006C550[Level43_827C4Field(privateRecord19, int*, 4)].state &
                0x80) {
            block_74:
                Level43_827C4DeleteMoby(ownerRecord18);
                return;
            }
            if (Level43_827C4CountTimerDown(privateRecord19, 2) != 0) {
                nextRawState2 = 0x50;
                goto block_76;
            }
            break;
        default:
            return;
    }
    return;
block_76:
    ownerRecord18->state = nextRawState2;
}
#undef Level43_827C4Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_43/moby", D_level_43_80074A04);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
typedef struct {
    int w0, w1, w2;
} Actor1160OriginalTriple;
extern Actor1160OriginalTriple Actor1160OriginalTripleSource __asm__("D_level_43_80074A04");
/* AI generated; not human reviewed. UNINSTALLED original physical C phases. Original rawLW only; all consumed input/source/helper/frame/table/native/linked/image gates pending. */
#define Actor1160Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Actor1160Keep(v) __asm__("" : "=r"(v) : "0"(v))
extern int Actor1160_D_800658A0[] __asm__("D_800658A0");
extern int Actor1160_D_80065920[] __asm__("D_80065920");
extern int Actor1160_D_8006C550[] __asm__("D_8006C550");
extern int Actor1160_D_8006C770[] __asm__("D_8006C770");
extern int Actor1160_D_8006C7C4[] __asm__("D_8006C7C4");
extern int Actor1160_D_8006E020[] __asm__("D_8006E020");
extern int Actor1160_D_8006E024[] __asm__("D_8006E024");
extern int Actor1160_D_8006E040[] __asm__("D_8006E040");
extern int Actor1160_D_80070328[] __asm__("D_80070328");
extern int Actor1160_D_level_43_80074A04[] __asm__("D_level_43_80074A04");
extern int Actor1160_SpawnMoby[] __asm__("SpawnMoby");
extern int Actor1160_unk_ovlheader_80074428[] __asm__("unk_ovlheader_80074428");
extern int Actor1160_func_8001830C() __asm__("func_8001830C");
extern int Actor1160_func_8001A358() __asm__("func_8001A358");
extern int Actor1160_func_8001AD60() __asm__("func_8001AD60");
extern int Actor1160_func_8001BA30() __asm__("func_8001BA30");
extern int Actor1160RequestMobyAnimation() __asm__("func_80034F40");
extern int Actor1160SetMobyAnimation() __asm__("func_80034F80");
extern int Actor1160_func_80035194() __asm__("func_80035194");
extern int Actor1160TurnMobyTowardPlayer() __asm__("func_8003573C");
extern int Actor1160CountTimerDown() __asm__("func_800359A4");
extern int Actor1160ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
extern int Actor1160_func_80035DDC() __asm__("func_80035DDC");
extern int Actor1160_func_80035EE0() __asm__("func_80035EE0");
extern int Actor1160SubAngle8() __asm__("func_8003613C");
extern int Actor1160RandBetween() __asm__("func_8003636C");
extern int Actor1160_func_800369B8() __asm__("func_800369B8");
extern int Actor1160_func_80038BF8() __asm__("func_80038BF8");
extern int Actor1160PlanarHeadingLookup() __asm__("func_8004E880");
extern int Actor1160MeasureVectorLength() __asm__("func_8004EDE8");
extern int Actor1160ScaleVectorRatioQ15() __asm__("func_8004F08C");
extern int Actor1160CopyVector() __asm__("func_8004F178");
extern int Actor1160AddVector() __asm__("func_8004F194");
extern int Actor1160SubtractVector() __asm__("func_8004F1C8");
extern int Actor1160AbsoluteByteAngleDelta() __asm__("func_8004F264");
extern int Actor1160ApproximatePlanarDistance() __asm__("func_8004F334");
extern int Actor1160DeleteMoby() __asm__("func_80055B18");
extern int Actor1160RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern int Actor1160_func_80055E84() __asm__("func_80055E84");
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Actor1160Product;
void func_level_43_8008342C(void* input) {
    register int valueV0 __asm__("$2");
    register int valueV1 __asm__("$3");
    register int argument0 __asm__("$4");
    register int argument1 __asm__("$5");
    register int argument2 __asm__("$6");
    register int argument3 __asm__("$7");
    register int valueT0 __asm__("$8");
    register int valueT1 __asm__("$9");
    register int valueT2 __asm__("$10");
    register int valueT3 __asm__("$11");
    register int valueT4 __asm__("$12");
    register int valueT5 __asm__("$13");
    register int valueT6 __asm__("$14");
    register int valueT7 __asm__("$15");
    register int valueS0 __asm__("$16");
    register int valueS1 __asm__("$17");
    register int valueS2 __asm__("$18");
    register int actor __asm__("$19");
    register int privateData __asm__("$20");
    register int valueS5 __asm__("$21");
    register int valueS6 __asm__("$22");
    register int valueS7 __asm__("$23");
    register int valueT8 __asm__("$24");
    register int valueT9 __asm__("$25");
    int valueFp;
    int outgoingWord5, outgoingWord6, outgoingWord7, outgoingWord8;
    union {
        struct {
            int sp18;
            int sp1C;
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
            int sp90;
            int sp94;
            int sp98;
            int sp9C;
            int spA0;
            int spA4;
            int spA8;
            int spAC;
            int spB0;
            int spB4;
            int spB8;
            int spBC;
            int spC0;
            int spC4;
            int spC8;
            int spCC;
            int spD0;
            int spD4;
            int spD8;
            int spDC;
        } fields;
        Actor1160OriginalTriple initialTable;
    } frame;
    long long completeSignedProduct;
    actor = (int)input;
    Actor1160Keep(actor);
    argument0 = (int)input;
    privateData = Actor1160Field(actor, int*, 0);
    Actor1160Keep(privateData);
    frame.initialTable = Actor1160OriginalTripleSource;
    valueV0 = frame.initialTable.w0;
    valueV1 = frame.initialTable.w1;
    argument0 = frame.initialTable.w2;
    valueV1 = Actor1160Field(actor, unsigned char*, 72);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(31));
    Actor1160Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 0))
        goto original1160Return;
    if (valueV1 == valueV0 ? (valueV0 = (unsigned int)valueV1 < 32, 1)
                           : (valueV0 = (unsigned int)valueV1 < 32, 0))
        goto original1160_67;
    valueV0 = Actor1160Field(privateData, int*, 24);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x00100000U;
    if (valueV0 == 0)
        goto original1160_65;
    valueV0 = Actor1160Field(valueV0, int*, 24);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & valueV1;
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_65;
    argument1 = (int)((unsigned int)privateData + (unsigned int)(28));
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(6));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(3));
    valueV0 = Actor1160_func_80038BF8(argument0, argument1, argument2, argument3);
    valueV1 = Actor1160Field(privateData, int*, 16);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, -15024);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueV0, int*, 0);
    Actor1160Keep(valueV1);
    valueV0 = Actor1160Field(valueV1, int*, 72);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(1));
    Actor1160Keep(valueV0);
    Actor1160Field(valueV1, int*, 72) = valueV0;
    valueV1 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1160Keep(valueV0);
    Actor1160Field(valueV1, unsigned char*, 72) = valueV0;
    Actor1160Field(privateData, int*, 20) = 0;
    Actor1160Field(actor, int*, 8) = 0;
    argument0 = Actor1160Field(privateData, int*, 24);
    Actor1160Keep(argument0);
    valueV0 = Actor1160DeleteMoby(argument0);
    Actor1160Field(privateData, int*, 24) = 0;
original1160_65:
    valueV1 = Actor1160Field(actor, unsigned char*, 72);
    Actor1160Keep(valueV1);
original1160_67:
    switch ((unsigned int)valueV1) {
        case 0:
            goto original1160_380;
        case 1:
            goto original1160_1050;
        case 2:
            goto original1160_974;
        case 3:
            goto original1160_1032;
        case 4:
            goto original1160_1050;
        case 5:
            goto original1160_1050;
        case 6:
            goto original1160_1050;
        case 7:
            goto original1160_1050;
        case 8:
            goto original1160_1050;
        case 9:
            goto original1160_1050;
        case 10:
            goto original1160_1050;
        case 11:
            goto original1160_1050;
        case 12:
            goto original1160_1050;
        case 13:
            goto original1160_1050;
        case 14:
            goto original1160_1050;
        case 15:
            goto original1160_1050;
        case 16:
            goto original1160_1050;
        case 17:
            goto original1160_1050;
        case 18:
            goto original1160_1050;
        case 19:
            goto original1160_1050;
        case 20:
            goto original1160_102;
        case 21:
            goto original1160_205;
        case 22:
            goto original1160_226;
        case 23:
            goto original1160_1050;
        case 24:
            goto original1160_82;
        case 25:
            goto original1160_76;
        case 26:
            goto original1160_1050;
        case 27:
            goto original1160_1050;
        case 28:
            goto original1160_1050;
        case 29:
            goto original1160_1050;
        case 30:
            goto original1160_974;
        case 31:
            goto original1160_1050;
        default:
            goto original1160_1050;
    }
original1160_76:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueV0);
    Actor1160Field(privateData, short*, 2) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(24));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(255));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 74) = valueV0;
original1160_82:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(255));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 65) = 0;
    Actor1160Field(actor, unsigned char*, 76) = 0;
    Actor1160Field(actor, unsigned char*, 77) = 0;
    Actor1160Field(actor, int*, 8) = 0;
    Actor1160Field(actor, unsigned char*, 74) = valueV0;
    valueV1 = Actor1160Field(privateData, int*, 16);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, -15024);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueV0, unsigned char*, 72);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(82));
    Actor1160Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1160_1050;
    Actor1160Keep(valueV0);
    Actor1160Keep(valueV1);
original1160_102:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    argument0 = (int)((unsigned int)0 + (unsigned int)(596));
    Actor1160Keep(argument0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(255));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 74) = valueV0;
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, 17120);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(2));
    if (valueS0 == 0)
        goto original1160_118;
    Actor1160Field(valueS0, unsigned char*, 65) = 0;
    Actor1160Field(valueS0, unsigned char*, 76) = 0;
    Actor1160Field(valueS0, unsigned char*, 77) = 0;
    Actor1160Field(valueS0, unsigned char*, 72) = valueV0;
    Actor1160Field(privateData, int*, 24) = valueS0;
original1160_118:
    argument0 = (int)((unsigned int)0 + (unsigned int)(595));
    Actor1160Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, 17120);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueS0 == 0)
        goto original1160_1050;
    argument1 = (int)0x80070000U;
    Actor1160Keep(argument1);
    argument1 = Actor1160Field(argument1, int*, -15024);
    Actor1160Keep(argument1);
    valueS2 = (int)((unsigned int)0 + (unsigned int)(32));
    Actor1160Keep(valueS2);
    argument1 = (int)((unsigned int)actor - (unsigned int)argument1);
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)argument1 << 5);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 5);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)argument1);
    Actor1160Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 15);
    Actor1160Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 - (unsigned int)valueV0);
    Actor1160Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1160Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)argument1);
    Actor1160Keep(valueV1);
    valueV1 = (int)((unsigned int)0 - (unsigned int)valueV1);
    Actor1160Keep(valueV1);
    valueV0 = Actor1160Field(valueS0, int*, 0);
    Actor1160Keep(valueV0);
    valueV1 = (valueV1 >> 3);
    Actor1160Keep(valueV1);
    Actor1160Field(valueV0, int*, 8) = valueV1;
    Actor1160Field(valueS0, unsigned char*, 76) = valueS2;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueS1 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueS1);
    Actor1160Field(valueS0, unsigned char*, 70) = valueV0;
    valueV0 = Actor1160Field(valueS0, int*, 28);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80000000U;
    Actor1160Keep(valueV1);
    Actor1160Field(valueS0, unsigned char*, 72) = valueS1;
    MATCHING_KEEP_VOLATILE_CLOBBER(valueV0, "memory");
    valueV0 = valueV0 | valueV1;
    Actor1160Keep(valueV0);
    Actor1160Field(valueS0, int*, 28) = valueV0;
    Actor1160Field(privateData, int*, 20) = valueS0;
    valueV0 = Actor1160ProbeGroundFromRaisedMoby(argument0, argument1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(512));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, int*, 20) = valueV0;
    Actor1160Field(valueS0, int*, 20) = valueV0;
    Actor1160Field(valueS0, int*, 8) = 0;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 255;
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(((int)&Actor1160_D_80065920 + valueV0), short*, 0);
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)(12));
    Actor1160Keep(argument0);
    valueV0 = (valueV0 >> 4);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 16) = valueV0;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 255;
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(((int)&Actor1160_D_800658A0 + valueV0), short*, 0);
    Actor1160Keep(valueV0);
    argument2 = (int)&frame.fields.sp28;
    Actor1160Keep(argument2);
    Actor1160Field((int)&frame, int*, 24) = 0;
    MATCHING_KEEP_VOLATILE_CLOBBER(valueV0, "memory");
    valueV0 = (valueV0 >> 4);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 20) = valueV0;
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
    valueV1 = Actor1160Field(actor, unsigned char*, 72);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(24));
    Actor1160Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(21)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(21)), 0))
        goto original1160_203;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(22));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 65) = valueS1;
    Actor1160Field(actor, unsigned char*, 76) = valueS2;
    Actor1160Field(actor, unsigned char*, 77) = valueS1;
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1160RequestMobyAnimation(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(7));
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(90));
    Actor1160Keep(valueV0);
    Actor1160Field(privateData, short*, 0) = valueV0;
    valueV0 = Actor1160RefreshMobySpatialGridAndBasis(argument0, argument1);
    goto original1160_1050;
original1160_203:
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    goto original1160_1050;
original1160_205:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    valueV1 = Actor1160Field(privateData, int*, 16);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, -15024);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueV0, unsigned char*, 72);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(80));
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV1 != valueV0)
        goto original1160_1050;
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(22));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1160RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(90));
    Actor1160Keep(valueV0);
    Actor1160Field(privateData, short*, 0) = valueV0;
    goto original1160_1050;
original1160_226:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    valueV1 = Actor1160Field(actor, unsigned short*, 60);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(514));
    Actor1160Keep(valueV0);
    valueS2 = (int)((unsigned int)0 + (unsigned int)(-1));
    if (valueV1 != valueV0)
        goto original1160_237;
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, -14480);
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_237;
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160RequestMobyAnimation(argument0, argument1);
original1160_237:
    argument0 = (int)((unsigned int)privateData + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1160CountTimerDown(argument0, argument1);
    if (valueV0 == 0)
        goto original1160_271;
    Actor1160Keep(valueV0);
    argument1 = (int)&Actor1160_D_80070328;
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    valueV0 = Actor1160ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 16384;
    Actor1160Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_271;
    valueV1 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, int*, -8160);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1160Keep(argument1);
    argument1 = Actor1160Field(argument1, int*, -8156);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, unsigned short*, -8128);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)argument0 << 16);
    Actor1160Keep(argument0);
    argument0 = (argument0 >> 20);
    valueV0 = Actor1160AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 24;
    Actor1160Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(-1)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(-1)), 0))
        goto original1160_271;
    Actor1160Field(privateData, int*, 52) = valueV0;
    Actor1160Field(privateData, short*, 0) = 0;
    Actor1160Field(actor, unsigned char*, 72) = 0;
    goto original1160_1050;
original1160_271:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV1 = Actor1160Field(privateData, int*, 52);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    if (valueV1 < 0)
        goto original1160_283;
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, -15024);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV0);
    valueS0 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    goto original1160_310;
original1160_283:
    valueS0 = (int)&frame.fields.sp28;
    Actor1160Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)&Actor1160_D_80070328;
    Actor1160Keep(argument1);
    valueS1 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1160Keep(valueS1);
    argument2 = (int)((unsigned int)valueS1 + (unsigned int)0);
    valueV0 = Actor1160SubtractVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1160MeasureVectorLength(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(6144));
    valueV0 = Actor1160ScaleVectorRatioQ15(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument2);
    Actor1160Field((int)&frame, int*, 24) = 0;
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    valueV0 = Actor1160Field(privateData, int*, 24);
    Actor1160Keep(valueV0);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument3);
    outgoingWord5 = valueV0;
    valueV0 = Actor1160_func_8001AD60(argument0, argument1, argument2, argument3, outgoingWord5);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS0);
original1160_310:
    valueV0 = (int)((unsigned int)0 + (unsigned int)(597));
    if (valueS0 == 0)
        goto original1160_347;
    valueV1 = Actor1160Field(valueS0, short*, 54);
    Actor1160Keep(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 0))
        goto original1160_348;
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    valueV1 = Actor1160Field(valueS0, int*, 12);
    Actor1160Keep(valueV1);
    argument0 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(valueS0, int*, 16);
    Actor1160Keep(valueV0);
    argument1 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    valueS1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS1);
    argument3 = (int)0x80070000U;
    Actor1160Keep(argument3);
    argument3 = Actor1160Field(argument3, int*, 808);
    Actor1160Keep(argument3);
    argument0 = Actor1160Field(valueS0, int*, 12);
    Actor1160Keep(argument0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, 812);
    Actor1160Keep(valueV1);
    argument1 = Actor1160Field(valueS0, int*, 16);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)argument3 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV1 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1160AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 6;
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    if (valueV0 != 0)
        goto original1160_1050;
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1160SubAngle8(argument0, argument1);
    valueS2 = (int)((unsigned int)0 + (unsigned int)(1));
    if (valueV0 <= 0)
        goto original1160_347;
    valueS2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(valueS2);
original1160_347:
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueV0);
original1160_348:
    if (valueS2 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(2)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(2)), 0))
        goto original1160_363;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    valueV0 = Actor1160_func_80035EE0(actor, (Actor1160Field(actor, unsigned char*, 70) + 64) & 255,
                                      30, 0, 0, 0);
    goto original1160_1050;
original1160_363:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueS2 != valueV0)
        goto original1160_1050;
    Actor1160Keep(valueS2);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    valueV0 = Actor1160_func_80035EE0(actor, (Actor1160Field(actor, unsigned char*, 70) - 64) & 255,
                                      30, 0, 0, 0);
    goto original1160_1050;
original1160_380:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    valueS7 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(valueS7);
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1160Keep(argument0);
    argument1 = (int)&Actor1160_D_80070328;
    Actor1160Keep(argument1);
    Actor1160Field((int)&frame, int*, 144) = 0;
    Actor1160Field((int)&frame, int*, 152) = 0;
    Actor1160Field((int)&frame, int*, 160) = 0;
    Actor1160Field((int)&frame, int*, 168) = 0;
    Actor1160Field((int)&frame, int*, 176) = 0;
    valueV0 = Actor1160ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 31001;
    Actor1160Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(514)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(514)), 0))
        goto original1160_396;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(22));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    goto original1160_1050;
original1160_396:
    valueV1 = Actor1160Field(actor, unsigned short*, 60);
    Actor1160Keep(valueV1);
    if (valueV1 != valueV0)
        goto original1160_407;
    Actor1160Keep(valueV0);
    Actor1160Keep(valueV1);
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, -14480);
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_407;
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160RequestMobyAnimation(argument0, argument1);
original1160_407:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = Actor1160Field(privateData, short*, 2);
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 != 0)
        goto original1160_475;
    valueV0 = Actor1160Field(privateData, int*, 12);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueV0, int*, 12);
    Actor1160Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, int*, 808);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(valueV1, int*, 0);
    Actor1160Keep(valueV0);
    valueV0 = argument0 < valueV0;
    Actor1160Keep(valueV0);
    valueT0 = (int)((unsigned int)0 + (unsigned int)(1));
    if (valueV0 == 0)
        goto original1160_423;
    __asm__ volatile("" ::"i"(0x80083AC4U));
    Actor1160Field((int)&frame, int*, 144) = valueT0;
    goto original1160_444;
original1160_423:
    valueV0 = Actor1160Field(valueV1, int*, 16);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 < argument0;
    Actor1160Keep(valueV0);
    valueT1 = (int)((unsigned int)0 + (unsigned int)(2));
    if (valueV0 != 0)
        goto original1160_443;
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, int*, 812);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(valueV1, int*, 36);
    Actor1160Keep(valueV0);
    valueV0 = argument0 < valueV0;
    Actor1160Keep(valueV0);
    valueT0 = (int)((unsigned int)0 + (unsigned int)(3));
    if (valueV0 == 0)
        goto original1160_437;
    __asm__ volatile("" ::"i"(0x80083AFCU));
    Actor1160Field((int)&frame, int*, 144) = valueT0;
    goto original1160_444;
original1160_437:
    valueV0 = Actor1160Field(valueV1, int*, 52);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 < argument0;
    Actor1160Keep(valueV0);
    if (valueV0 == 0)
        goto original1160_444;
    Actor1160Keep(valueV0);
    valueT1 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1160Keep(valueT1);
original1160_443:
    __asm__ volatile("" ::"i"(0x80083B18U));
    Actor1160Field((int)&frame, int*, 144) = valueT1;
original1160_444:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = Actor1160Field(privateData, int*, 12);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueV0, int*, 12);
    Actor1160Keep(valueV1);
    argument0 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(valueV1, int*, 0);
    Actor1160Keep(valueV0);
    valueV0 = argument0 < valueV0;
    Actor1160Keep(valueV0);
    valueT0 = (int)((unsigned int)0 + (unsigned int)(1));
    if (valueV0 == 0)
        goto original1160_455;
    __asm__ volatile("" ::"i"(0x80083B44U));
    Actor1160Field((int)&frame, int*, 152) = valueT0;
    goto original1160_474;
original1160_455:
    valueV0 = Actor1160Field(valueV1, int*, 16);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 < argument0;
    Actor1160Keep(valueV0);
    valueT1 = (int)((unsigned int)0 + (unsigned int)(2));
    if (valueV0 != 0)
        goto original1160_473;
    argument0 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(valueV1, int*, 36);
    Actor1160Keep(valueV0);
    valueV0 = argument0 < valueV0;
    Actor1160Keep(valueV0);
    valueT0 = (int)((unsigned int)0 + (unsigned int)(3));
    if (valueV0 == 0)
        goto original1160_468;
    __asm__ volatile("" ::"i"(0x80083B78U));
    Actor1160Field((int)&frame, int*, 152) = valueT0;
    goto original1160_474;
original1160_468:
    valueV0 = Actor1160Field(valueV1, int*, 52);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 < argument0;
    Actor1160Keep(valueV0);
    valueT1 = (int)((unsigned int)0 + (unsigned int)(4));
    if (valueV0 == 0)
        goto original1160_474;
original1160_473:
    __asm__ volatile("" ::"i"(0x80083B90U));
    Actor1160Field((int)&frame, int*, 152) = valueT1;
original1160_474:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1160Keep(argument0);
original1160_475:
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)0 + (unsigned int)(1));
    if (valueV0 == 0)
        goto original1160_1050;
    valueV1 = Actor1160Field(privateData, short*, 6);
    Actor1160Keep(valueV1);
    valueV0 = valueV1 < 2;
    if (valueV1 == argument0)
        goto original1160_570;
    if (valueV0 == 0)
        goto original1160_491;
    Actor1160Keep(valueV0);
    if (valueV1 == 0)
        goto original1160_498;
    Actor1160Keep(valueV1);
    goto original1160_677;
original1160_491:
    valueV0 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 0))
        goto original1160_574;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV1 == valueV0)
        goto original1160_555;
    goto original1160_677;
original1160_498:
    valueT0 = Actor1160Field((int)&frame, int*, 144);
    Actor1160Keep(valueT0);
    valueT1 = Actor1160Field((int)&frame, int*, 152);
    Actor1160Keep(valueT1);
    if (valueT0 != valueT1)
        goto original1160_549;
    Actor1160Keep(valueT0);
    Actor1160Keep(valueT1);
    valueV0 = Actor1160Field(privateData, short*, 2);
    Actor1160Keep(valueV0);
    valueS1 = (int)((unsigned int)actor + (unsigned int)(12));
    if (valueV0 == argument0)
        goto original1160_549;
    argument1 = (int)&Actor1160_D_80070328;
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    valueV0 = Actor1160ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 8193;
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 != 0)
        goto original1160_677;
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(70));
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument3);
    outgoingWord5 = 0;
    valueV0 = Actor1160_func_80035DDC(argument0, argument1, argument2, argument3, outgoingWord5);
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueS0 = (int)&frame.fields.sp48;
    Actor1160Keep(valueS0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(((int)&Actor1160_D_80065920 + valueV0), short*, 0);
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueV0 = (valueV0 >> 3);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 48) = valueV0;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(((int)&Actor1160_D_800658A0 + valueV0), short*, 0);
    Actor1160Keep(valueV0);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument2);
    Actor1160Field((int)&frame, int*, 56) = 0;
    MATCHING_KEEP_VOLATILE_CLOBBER(valueV0, "memory");
    valueV0 = (valueV0 >> 3);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 52) = valueV0;
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
    valueV0 = Actor1160_func_8001BA30(valueS0, 512, 3, 0, 0, Actor1160Field(privateData, int*, 24));
    if (valueV0 == 0)
        goto original1160_677;
    Actor1160Keep(valueV0);
original1160_549:
    argument0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument1);
    Actor1160Field(privateData, short*, 0) = 0;
    valueV0 = Actor1160RandBetween(argument0, argument1);
    Actor1160Field(privateData, short*, 6) = valueV0;
    goto original1160_677;
original1160_555:
    valueV0 = Actor1160_func_80035EE0(
        argument0, (Actor1160Field(actor, unsigned char*, 70) + 128) & 255, 50, 0, 0, 0);
    argument0 = (int)((unsigned int)privateData + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1160CountTimerDown(argument0, argument1);
    if (valueV0 == 0)
        goto original1160_677;
    Actor1160Keep(valueV0);
    Actor1160Field(privateData, short*, 6) = 0;
    goto original1160_677;
original1160_570:
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(64));
    Actor1160Keep(valueV0);
    valueS1 = valueV0 & 255;
    Actor1160Keep(valueS1);
original1160_574:
    argument0 = (int)&frame.fields.sp38;
    Actor1160Keep(argument0);
    valueS2 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1160Keep(valueS2);
    argument1 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1160CopyVector(argument0, argument1);
    valueV1 = Actor1160Field(privateData, short*, 6);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV1 != valueV0)
        goto original1160_586;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(-64));
    Actor1160Keep(valueV0);
    valueS1 = valueV0 & 255;
    Actor1160Keep(valueS1);
original1160_586:
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(50));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument3);
    outgoingWord5 = 0;
    outgoingWord6 = 0;
    valueV0 = Actor1160_func_80035EE0(argument0, argument1, argument2, argument3, outgoingWord5,
                                      outgoingWord6);
    valueS0 = (int)&frame.fields.sp58;
    Actor1160Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueV1 = (int)((unsigned int)valueS1 << 1);
    Actor1160Keep(valueV1);
    valueV0 = Actor1160Field(((int)&Actor1160_D_80065920 + valueV1), short*, 0);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1160Keep(argument1);
    valueV0 = (valueV0 >> 3);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 64) = valueV0;
    valueV0 = Actor1160Field(((int)&Actor1160_D_800658A0 + valueV1), short*, 0);
    Actor1160Keep(valueV0);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument2);
    Actor1160Field((int)&frame, int*, 72) = 0;
    MATCHING_KEEP_VOLATILE_CLOBBER(valueV0, "memory");
    valueV0 = (valueV0 >> 3);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 68) = valueV0;
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)privateData + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1160CountTimerDown(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(512));
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(3));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument3);
    valueS5 = (int)&Actor1160_D_80065920;
    Actor1160Keep(valueS5);
    valueV0 = Actor1160_func_8001BA30(argument0, argument1, argument2, argument3, 0, ({
                                          valueV0 = Actor1160Field(privateData, int*, 24);
                                          Actor1160Keep(valueV0);
                                          valueS6 = (int)&Actor1160_D_800658A0;
                                          Actor1160Keep(valueS6);
                                          valueV0;
                                      }));
    valueS1 = (int)&frame.fields.sp78;
    if (valueV0 != 0)
        goto original1160_676;
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field((int)&frame, int*, 72);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(-384));
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 72) = valueV0;
    valueV0 = Actor1160CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(3));
    Actor1160Keep(argument2);
    valueV0 = Actor1160Field((int)&frame, int*, 72);
    Actor1160Keep(valueV0);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument3);
    Actor1160Field((int)&frame, int*, 104) = valueV0;
    outgoingWord5 = actor;
    valueV0 = Actor1160_func_8001830C(argument0, argument1, argument2, argument3, outgoingWord5);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    if (valueV0 != 0)
        goto original1160_676;
    argument1 = (int)((unsigned int)0 + (unsigned int)(562));
    valueV0 = Actor1160_func_8001A358(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_676;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 255;
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueS5);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, short*, 0);
    Actor1160Keep(valueV0);
    valueV0 = (valueV0 >> 3);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 80) = valueV0;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 255;
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueS6);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, short*, 0);
    Actor1160Keep(valueV0);
    argument2 = (int)&frame.fields.sp68;
    Actor1160Keep(argument2);
    Actor1160Field((int)&frame, int*, 88) = 0;
    MATCHING_KEEP_VOLATILE_CLOBBER(valueV0, "memory");
    valueV0 = (valueV0 >> 3);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 84) = valueV0;
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(3));
    Actor1160Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument3);
    outgoingWord5 = actor;
    valueV0 = Actor1160_func_8001830C(argument0, argument1, argument2, argument3, outgoingWord5);
    if (valueV0 == 0)
        goto original1160_677;
    Actor1160Keep(valueV0);
original1160_676:
    valueS7 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueS7);
original1160_677:
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    if (valueS7 == 0)
        goto original1160_697;
    argument1 = (int)&frame.fields.sp38;
    valueV0 = Actor1160CopyVector(argument0, argument1);
    valueV0 = Actor1160Field(privateData, short*, 0);
    Actor1160Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 0))
        goto original1160_689;
    Actor1160Field(privateData, short*, 6) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(30));
    Actor1160Keep(valueV0);
    Actor1160Field(privateData, short*, 0) = valueV0;
    goto original1160_697;
original1160_689:
    valueV1 = Actor1160Field(privateData, short*, 6);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(6));
    Actor1160Keep(valueV0);
    Actor1160Field(privateData, short*, 0) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(2)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(2)), 0))
        goto original1160_696;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueV0);
original1160_696:
    Actor1160Field(privateData, short*, 6) = valueV0;
original1160_697:
    valueV0 = Actor1160Field(privateData, short*, 4);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 < 30;
    Actor1160Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(3)), 0))
        goto original1160_705;
    valueV1 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueV1);
    Actor1160Field(valueV1, unsigned char*, 73) = valueV0;
    goto original1160_708;
original1160_705:
    valueV0 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueV0);
    Actor1160Field(valueV0, unsigned char*, 73) = 0;
original1160_708:
    argument0 = (int)((unsigned int)privateData + (unsigned int)(4));
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1160CountTimerDown(argument0, argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_1050;
    valueV1 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, int*, -8160);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1160Keep(argument1);
    argument1 = Actor1160Field(argument1, int*, -8156);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, unsigned short*, -8128);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)argument0 << 16);
    Actor1160Keep(argument0);
    argument0 = (argument0 >> 20);
    valueV0 = Actor1160AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 24;
    Actor1160Keep(valueV0);
    valueS6 = (int)&frame.fields.sp68;
    if (valueV0 == 0)
        goto original1160_1050;
    argument0 = (int)((unsigned int)valueS6 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueS7 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1160Keep(valueS7);
    argument1 = (int)((unsigned int)valueS7 + (unsigned int)0);
    valueV0 = Actor1160CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)valueS6 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueS1 = (int)&Actor1160_D_80070328 + 592;
    Actor1160Keep(valueS1);
    valueFp = (int)((unsigned int)valueS1 + (unsigned int)(-592));
    Actor1160Keep(valueFp);
    argument1 = (int)((unsigned int)valueFp + (unsigned int)0);
    Actor1160Keep(argument1);
    valueS0 = Actor1160Field(valueS1, int*, 0);
    Actor1160Keep(valueS0);
    valueV0 = Actor1160Field(privateData, int*, 24);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, 17448);
    Actor1160Keep(valueV1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    Actor1160Field(valueS1, int*, 0) = valueV0;
    valueV0 = ((int (*)())valueV1)(argument0, argument1, argument2);
    valueS5 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS5);
    Actor1160Field(valueS1, int*, 0) = valueS0;
    if (valueS5 == 0)
        goto original1160_919;
    valueT0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueT0);
    Actor1160Field((int)&frame, int*, 168) = valueT0;
    valueV1 = Actor1160Field(valueS5, short*, 54);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(596));
    Actor1160Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(255)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(255)), 0))
        goto original1160_868;
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueS5, unsigned char*, 58);
    Actor1160Keep(valueV1);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)valueV1 << 1), 1)
                           : (valueV0 = (int)((unsigned int)valueV1 << 1), 0))
        goto original1160_868;
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, -15024);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field(valueV0, short*, 54);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(523));
    Actor1160Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV1 == valueV0)
        goto original1160_868;
    valueV1 = Actor1160Field(valueS1, int*, -592);
    Actor1160Keep(valueV1);
    argument0 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, 812);
    Actor1160Keep(valueV0);
    argument1 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    valueS2 = (int)&frame.fields.sp88;
    Actor1160Keep(valueS2);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueFp + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)valueS6 + (unsigned int)0);
    Actor1160Keep(argument2);
    valueS0 = (int)((unsigned int)0 + (unsigned int)(256));
    Actor1160Keep(valueS0);
    valueS0 = (int)((unsigned int)valueS0 - (unsigned int)valueV0);
    valueV0 = Actor1160SubtractVector(argument0, argument1, argument2);
    valueS1 = (int)&Actor1160_D_80065920;
    Actor1160Keep(valueS1);
    valueS0 = (int)((unsigned int)valueS0 << 1);
    Actor1160Keep(valueS0);
    valueS1 = (int)((unsigned int)valueS0 + (unsigned int)valueS1);
    Actor1160Keep(valueS1);
    valueV0 = Actor1160Field(valueS1, short*, 0);
    Actor1160Keep(valueV0);
    argument0 = Actor1160Field((int)&frame, int*, 112);
    Actor1160Keep(argument0);
    completeSignedProduct = (long long)argument0 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    valueV1 = Actor1160Field((int)&frame, int*, 116);
    Actor1160Keep(valueV1);
    valueV0 = (int)&Actor1160_D_800658A0;
    Actor1160Keep(valueV0);
    valueS0 = (int)((unsigned int)valueS0 + (unsigned int)valueV0);
    Actor1160Keep(valueS0);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        argument1 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(argument1);
    valueV0 = Actor1160Field(valueS0, short*, 0);
    Actor1160Keep(valueV0);
    completeSignedProduct = (long long)valueV1 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        valueT2 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(valueT2);
    valueV0 = (int)((unsigned int)argument1 - (unsigned int)valueT2);
    Actor1160Keep(valueV0);
    valueV0 = (valueV0 >> 12);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 80) = valueV0;
    valueV0 = Actor1160Field(valueS0, short*, 0);
    Actor1160Keep(valueV0);
    completeSignedProduct = (long long)argument0 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        argument1 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(argument1);
    valueV0 = Actor1160Field(valueS1, short*, 0);
    Actor1160Keep(valueV0);
    completeSignedProduct = (long long)valueV1 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    argument2 = (int)((unsigned int)valueS7 + (unsigned int)0);
    Actor1160Keep(argument2);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        valueV1 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)argument1 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (valueV0 >> 12);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 84) = valueV0;
    valueV1 = Actor1160Field(valueS5, unsigned char*, 58);
    Actor1160Keep(valueV1);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, -15024);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1160Keep(valueV0);
    valueS2 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1160Keep(valueS2);
    argument1 = (int)((unsigned int)valueS2 + (unsigned int)(12));
    valueV0 = Actor1160SubtractVector(argument0, argument1, argument2);
    valueV0 = Actor1160Field(valueS1, short*, 0);
    Actor1160Keep(valueV0);
    argument0 = Actor1160Field((int)&frame, int*, 112);
    Actor1160Keep(argument0);
    completeSignedProduct = (long long)argument0 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    valueV1 = Actor1160Field((int)&frame, int*, 116);
    Actor1160Keep(valueV1);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        argument1 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(argument1);
    valueV0 = Actor1160Field(valueS0, short*, 0);
    Actor1160Keep(valueV0);
    completeSignedProduct = (long long)valueV1 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        valueT2 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(valueT2);
    valueV0 = (int)((unsigned int)argument1 - (unsigned int)valueT2);
    Actor1160Keep(valueV0);
    valueV0 = (valueV0 >> 12);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 128) = valueV0;
    valueV0 = Actor1160Field(valueS0, short*, 0);
    Actor1160Keep(valueV0);
    completeSignedProduct = (long long)argument0 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        argument0 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(valueS1, short*, 0);
    Actor1160Keep(valueV0);
    completeSignedProduct = (long long)valueV1 * (long long)valueV0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        valueV1 = wholeCapturedProjection;
    } while (0);
    Actor1160Keep(valueV1);
    valueV0 = (int)((unsigned int)argument0 + (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = Actor1160Field((int)&frame, int*, 84);
    Actor1160Keep(valueV1);
    valueV0 = (valueV0 >> 12);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 132) = valueV0;
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    if (valueV0 >= 0)
        goto original1160_859;
    valueV1 = (int)((unsigned int)0 - (unsigned int)valueV1);
    Actor1160Keep(valueV1);
original1160_859:
    valueV0 = valueV1 < 1001;
    Actor1160Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = valueV1 < 400, 1) : (valueV0 = valueV1 < 400, 0))
        goto original1160_864;
    valueS5 = (int)((unsigned int)0 + (unsigned int)0);
    goto original1160_868;
original1160_864:
    valueS5 = (int)((unsigned int)valueS2 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_868;
    valueT0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueT0);
    Actor1160Field((int)&frame, int*, 160) = valueT0;
original1160_868:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(597));
    if (valueS5 == 0)
        goto original1160_919;
    valueV1 = Actor1160Field(valueS5, short*, 54);
    Actor1160Keep(valueV1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV1 != valueV0)
        goto original1160_905;
    valueV1 = (int)0x80070000U;
    Actor1160Keep(valueV1);
    valueV1 = Actor1160Field(valueV1, int*, 808);
    Actor1160Keep(valueV1);
    argument0 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, 812);
    Actor1160Keep(valueV0);
    argument1 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS0);
    argument3 = Actor1160Field(valueS5, int*, 12);
    Actor1160Keep(argument3);
    argument0 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(argument0);
    valueV1 = Actor1160Field(valueS5, int*, 16);
    Actor1160Keep(valueV1);
    argument1 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)argument3 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV1 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1160AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 8;
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    if (valueV0 == 0)
        goto original1160_905;
    argument1 = (int)((unsigned int)valueS5 + (unsigned int)(12));
    valueV0 = Actor1160ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 7000;
    Actor1160Keep(valueV0);
    if (valueV0 == 0)
        goto original1160_905;
    Actor1160Keep(valueV0);
    valueT1 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueT1);
    Actor1160Field((int)&frame, int*, 160) = valueT1;
original1160_905:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    if (valueS5 == 0)
        goto original1160_919;
    Actor1160Keep(valueS5);
    valueV0 = Actor1160Field(privateData, short*, 6);
    Actor1160Keep(valueV0);
    valueT0 = (int)((unsigned int)0 + (unsigned int)(1));
    if (valueV0 != 0)
        goto original1160_917;
    argument0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(argument1);
    Actor1160Field(privateData, short*, 0) = 0;
    valueV0 = Actor1160RandBetween(argument0, argument1);
    Actor1160Field(privateData, short*, 6) = valueV0;
    MATCHING_BARRIER_VOLATILE("memory");
    valueT0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueT0);
original1160_917:
    Actor1160Field((int)&frame, int*, 176) = valueT0;
    goto original1160_937;
original1160_919:
    valueT1 = Actor1160Field((int)&frame, int*, 168);
    Actor1160Keep(valueT1);
    if (valueT1 != 0)
        goto original1160_937;
    Actor1160Keep(valueT1);
    valueV0 = Actor1160Field(privateData, short*, 6);
    Actor1160Keep(valueV0);
    if (valueV0 == 0)
        goto original1160_937;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(privateData, short*, 2);
    Actor1160Keep(valueV0);
    if (valueV0 != 0)
        goto original1160_937;
    Actor1160Keep(valueV0);
    valueT0 = Actor1160Field((int)&frame, int*, 152);
    Actor1160Keep(valueT0);
    valueT1 = Actor1160Field((int)&frame, int*, 144);
    Actor1160Keep(valueT1);
    if (valueT0 != valueT1)
        goto original1160_937;
    Actor1160Keep(valueT0);
    Actor1160Keep(valueT1);
    Actor1160Field(privateData, short*, 6) = 0;
original1160_937:
    valueT0 = Actor1160Field((int)&frame, int*, 176);
    Actor1160Keep(valueT0);
    if (valueT0 == 0)
        goto original1160_948;
    Actor1160Keep(valueT0);
    valueT1 = Actor1160Field((int)&frame, int*, 160);
    Actor1160Keep(valueT1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(4));
    if (valueT1 != 0)
        goto original1160_948;
    valueV1 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueV1);
    Actor1160Field(valueV1, unsigned char*, 73) = valueV0;
original1160_948:
    valueV0 = Actor1160Field(privateData, short*, 4);
    Actor1160Keep(valueV0);
    if (valueV0 != 0)
        goto original1160_1050;
    Actor1160Keep(valueV0);
    valueT0 = Actor1160Field((int)&frame, int*, 176);
    Actor1160Keep(valueT0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueT0 == 0)
        goto original1160_960;
    valueT1 = Actor1160Field((int)&frame, int*, 160);
    Actor1160Keep(valueT1);
    if (valueT1 == 0)
        goto original1160_1050;
    Actor1160Keep(valueT1);
original1160_960:
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1160SetMobyAnimation(argument0, argument1);
    argument0 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160SetMobyAnimation(argument0, argument1);
    valueT0 = Actor1160Field((int)&frame, int*, 160);
    Actor1160Keep(valueT0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(30));
    if (valueT0 == 0)
        goto original1160_971;
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    goto original1160_1050;
original1160_971:
    valueV0 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    goto original1160_1050;
original1160_974:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    valueV0 = Actor1160Field(actor, unsigned char*, 73);
    Actor1160Keep(valueV0);
    valueS0 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueS0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(257)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(257)), 0))
        goto original1160_1007;
    valueV1 = Actor1160Field(valueS0, unsigned short*, 60);
    Actor1160Keep(valueV1);
    if (valueV1 != valueV0)
        goto original1160_1007;
    Actor1160Keep(valueV0);
    Actor1160Keep(valueV1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1160_func_80055E84(argument0);
    valueV0 = valueV0 < 4;
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)0 + (unsigned int)(596));
    if (valueV0 != 0)
        goto original1160_1007;
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, 17120);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(argument1);
    valueV1 = (int)((unsigned int)0 + (unsigned int)(30));
    if (argument1 == 0)
        goto original1160_1007;
    valueV0 = Actor1160Field(actor, unsigned char*, 72);
    Actor1160Keep(valueV0);
    argument0 = Actor1160Field(argument1, int*, 0);
    Actor1160Keep(argument0);
    if (valueV0 != valueV1 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 0))
        goto original1160_1003;
    Actor1160Field(argument0, int*, 8) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(200));
    Actor1160Keep(valueV0);
    Actor1160Field(argument0, int*, 4) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueV0);
original1160_1003:
    Actor1160Field(argument1, int*, 8) = 0;
    Actor1160Field(argument0, int*, 12) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 73) = valueV0;
original1160_1007:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, -14480);
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_1014;
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1160RequestMobyAnimation(argument0, argument1);
original1160_1014:
    valueV0 = Actor1160Field(valueS0, unsigned char*, 66);
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 2;
    Actor1160Keep(valueV0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1160_1050;
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument1);
    Actor1160Field(actor, unsigned char*, 73) = 0;
    valueV0 = Actor1160SetMobyAnimation(argument0, argument1);
    valueV0 = (int)0x80070000U;
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(valueV0, int*, -14396);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)&frame + (unsigned int)valueV0 - 24U);
    Actor1160Keep(valueV0);
    __asm__ volatile("lw %0,24(%0)" : "=r"(valueV0) : "0"(valueV0) : "memory");
    Actor1160Field(privateData, short*, 4) = valueV0;
    Actor1160Field(actor, unsigned char*, 72) = 0;
    goto original1160_1050;
original1160_1032:
    MATCHING_OBSERVE_VOLATILE(valueV1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)privateData + (unsigned int)(28));
    valueV0 = Actor1160_func_80035194(argument0, argument1);
    valueV1 = (int)((unsigned int)0 + (unsigned int)(256));
    Actor1160Keep(valueV1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 != valueV1)
        goto original1160_1050;
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    valueV0 = Actor1160RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(40));
    valueV0 = Actor1160_func_800369B8(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(31));
    Actor1160Keep(valueV0);
    Actor1160Field(actor, unsigned char*, 65) = 0;
    Actor1160Field(actor, unsigned char*, 76) = 0;
    Actor1160Field(actor, unsigned char*, 77) = 0;
    Actor1160Field(actor, int*, 8) = 0;
    Actor1160Field(actor, unsigned char*, 72) = valueV0;
    goto original1160Return;
original1160_1050:
    valueV0 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)(12));
    if (valueV0 == 0)
        goto original1160_1084;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 255;
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(((int)&Actor1160_D_80065920 + valueV0), short*, 0);
    Actor1160Keep(valueV0);
    valueV0 = (valueV0 >> 4);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 48) = valueV0;
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1160Keep(valueV0);
    valueV0 = valueV0 & 255;
    Actor1160Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1160Keep(valueV0);
    valueV0 = Actor1160Field(((int)&Actor1160_D_800658A0 + valueV0), short*, 0);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 56) = 0;
    MATCHING_KEEP_VOLATILE_CLOBBER(valueV0, "memory");
    valueV0 = (valueV0 >> 4);
    Actor1160Keep(valueV0);
    Actor1160Field((int)&frame, int*, 52) = valueV0;
    argument0 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(argument0);
    argument2 = (int)&frame.fields.sp48;
    Actor1160Keep(argument2);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)(12));
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
    valueV1 = Actor1160Field(privateData, int*, 20);
    Actor1160Keep(valueV1);
    valueV0 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(valueV0);
    Actor1160Field(valueV1, unsigned char*, 70) = valueV0;
original1160_1084:
    argument0 = Actor1160Field(privateData, int*, 24);
    Actor1160Keep(argument0);
    valueS2 = (int)((unsigned int)0 + (unsigned int)(1024));
    if (argument0 == 0)
        goto original1160Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)(6));
    valueV0 = Actor1160RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1160Keep(argument2);
    valueV1 = Actor1160Field(actor, int*, 12);
    Actor1160Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1160Keep(argument0);
    argument0 = Actor1160Field(argument0, int*, 808);
    Actor1160Keep(argument0);
    valueV0 = Actor1160Field(actor, int*, 16);
    Actor1160Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1160Keep(argument1);
    argument1 = Actor1160Field(argument1, int*, 812);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1160PlanarHeadingLookup(argument0, argument1, argument2);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueS0);
    argument1 = (int)0x80070000U;
    Actor1160Keep(argument1);
    argument1 = Actor1160Field(argument1, unsigned char*, 822);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1160AbsoluteByteAngleDelta(argument0, argument1);
    valueV1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueV1);
    valueV0 = valueV1 < 64;
    Actor1160Keep(valueV0);
    if (valueV0 == 0)
        goto original1160_1110;
    Actor1160Keep(valueV0);
    valueS2 = (int)((unsigned int)valueV1 << 4);
    Actor1160Keep(valueS2);
original1160_1110:
    argument1 = Actor1160Field(actor, unsigned char*, 70);
    Actor1160Keep(argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)(128));
    Actor1160Keep(argument0);
    argument0 = argument0 & 255;
    valueV0 = Actor1160AbsoluteByteAngleDelta(argument0, argument1);
    valueV1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(valueV1);
    valueV0 = valueV1 < 64;
    Actor1160Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(64)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(64)), 0))
        goto original1160_1127;
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1160Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 2);
    Actor1160Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1160Keep(valueV1);
    valueV0 = valueV1 < 301;
    Actor1160Keep(valueV0);
    if (valueV0 != 0)
        goto original1160_1126;
    Actor1160Keep(valueV0);
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)(-300));
    goto original1160_1127;
original1160_1126:
    valueS2 = (int)((unsigned int)valueS2 - (unsigned int)valueV1);
    Actor1160Keep(valueS2);
original1160_1127:
    valueS0 = (int)&frame.fields.sp78;
    Actor1160Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    valueS1 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1160Keep(valueS1);
    argument2 = (int)&Actor1160_D_80070328;
    Actor1160Keep(argument2);
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    valueV0 = Actor1160SubtractVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1160MeasureVectorLength(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1160Keep(argument1);
    argument2 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1160ScaleVectorRatioQ15(argument0, argument1, argument2);
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1160Keep(argument1);
    Actor1160Field((int)&frame, int*, 104) = 0;
    argument0 = Actor1160Field(privateData, int*, 24);
    Actor1160Keep(argument0);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1160Keep(argument2);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)(12));
    valueV0 = Actor1160AddVector(argument0, argument1, argument2);
original1160Return:
    return;
}
#undef Actor1160Field
#undef Actor1160Keep


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. C derived from original instructions. Original source asm/nonmatchings/overlays/level_43/moby/func_level_43_8008464C.s SHA256 d4c86251af83913f8ee5f79f5392d3c4df08839c2fb70f6b1bcef62bd7feea80. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))


int Haunted8464C_func_80019138() __asm__("func_80019138");
int Haunted8464C_func_8001A358() __asm__("func_8001A358");
int Haunted8464C_func_8001C288() __asm__("func_8001C288");
int Haunted8464CSetMobyAnimation() __asm__("func_80034F80");
int Haunted8464CTransformVectorByBasis() __asm__("func_8004ED6C");
int Haunted8464CNormalizeVectorToLength() __asm__("func_8004EF04");
int Haunted8464CScaleVectorRatioQ15() __asm__("func_8004F08C");
int Haunted8464CDeleteMoby() __asm__("func_80055B18");
int Haunted8464CRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Haunted8464C_func_80056504() __asm__("func_80056504");
int Haunted8464C_rand() __asm__("rand");
extern unsigned char Haunted8464C_D_800658A0 __asm__("D_800658A0");
extern unsigned char Haunted8464C_D_80065920 __asm__("D_80065920");
extern int Haunted8464C_D_8006C574 __asm__("D_8006C574");
extern int Haunted8464C_D_8006C578 __asm__("D_8006C578");
extern Vector3D Haunted8464C_D_80070328 __asm__("D_80070328");
extern Vector3D Haunted8464C_D_80071900 __asm__("D_80071900");
extern int Haunted8464C_D_80071908 __asm__("D_80071908");
extern int Haunted8464C_D_80071918 __asm__("D_80071918");
extern int Haunted8464C_D_8007191C __asm__("D_8007191C");
extern int Haunted8464C_D_80071920 __asm__("D_80071920");

extern signed char* (*HauntedParticleCallback)() __asm__("SpawnParticle");
void func_level_43_8008464C(Moby* inputMoby) {
    /* Raw stack offsets and field widths follow original retail instructions.
     * Empty constraints preserve code generation without added instructions. */
    struct {
        Vector3D sp18;
        char pad_24[4];
        int sp28;
        int sp2C;
        int sp30;
        char pad_34[4];
        Vector3D sp38;
        char pad_44[4];
    } originalStack;

register Moby* moby __asm__("$19") = inputMoby;

    register int releaseCount5 __asm__("$5");
    register Moby* firstChild17 __asm__("$17");
    register Moby* spawnedChild18 __asm__("$18");
    register Vector3D* childPosition4 __asm__("$4");
    register Vector3D* position17 __asm__("$17");
    register Vector3D* copySource5 __asm__("$5");
    register short* cosineCursor4 __asm__("$4");
    register short* sineCursor16 __asm__("$16");
    register int projection7 __asm__("$7");
    register int yawOffset16 __asm__("$16");
    register int fallSpeed2 __asm__("$2");
    register int dotProduct2 __asm__("$2");
    register int nextFallSpeed2 __asm__("$2");
    register int heightDifference3 __asm__("$3");
    register int childIndex21 __asm__("$21");
    register int playerContact22 __asm__("$22");
    register int childHeight2 __asm__("$2");
    register int remainingHeight2 __asm__("$2");
    register int particleFade3 __asm__("$3");
    register signed char* previousParticle4 __asm__("$4");
    register signed char* newParticle2 __asm__("$2");
    register int previousYaw16 __asm__("$16");
    register int remainingBounces2 __asm__("$2");
    register int state3 __asm__("$3");
    register void* firstChildData16 __asm__("$16");
    register void* spawnedData17 __asm__("$17");
    register void* privateData18 __asm__("$18");
    register void* timerAddress4 __asm__("$4");

    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register signed char* (*callback3)() __asm__("$3");
    register int constant120 __asm__("$19");
    register void* vector20 __asm__("$20");
    register int* ground20 __asm__("$20");
    register int* response16 __asm__("$16");
    MATCHING_KEEP(moby);
    value2 = 1;
    state3 = moby->state;
    privateData18 = moby->mobyTag;
    switch (state3) { /* irregular */
        case 0:
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            if ((moby->substate != 0) && (func_800359A4(privateData18 + 4, 4) != 0)) {
                firstChild17 = SpawnMoby(0x210, moby);
                MATCHING_KEEP(firstChild17);
                if (firstChild17 != 0) {
                    firstChildData16 = firstChild17->mobyTag;
                    firstChild17->lowDrawDistance = 0x18;
                    firstChild17->updateDistance = 0xFF;
                    firstChild17->angle.yaw = func_8003636C(0, 0x7F);
                    value2 = 1;
                    firstChild17->state = value2;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                    value2 = 12;
                    MATCHING_KEEP_CLOBBER(value2, "$19");
                    constant120 = 120;
                    firstChild17->size = value2;
                    M2C_FIELD(firstChildData16, int*, 16) = 0;
                    MATCHING_BARRIER_VOLATILE("memory");
                    M2C_FIELD(firstChildData16, int*, 4) = constant120;
                    if (Haunted8464C_rand() & 1) {
                        Haunted8464CSetMobyAnimation(firstChild17, 1);
                    }
                    M2C_FIELD(privateData18, int*, 4) = constant120;
                    return;
                }
            }
            return;
        case 1:
            moby->position.z += M2C_FIELD(privateData18, int*, 0x10);
            fallSpeed2 = M2C_FIELD(privateData18, int*, 0x10) - 0x10;
            M2C_FIELD(privateData18, int*, 0x10) = fallSpeed2;
            playerContact22 = 0;
            if (fallSpeed2 < -0xFA) {
                M2C_FIELD(privateData18, int*, 0x10) = -0xFA;
            }
            position17 = &moby->position;
            moby->position.z += 0x400;
            Haunted8464C_func_8001A358(position17, 0x2000);
            moby->position.z -= 0x400;
            if (Haunted8464C_func_8001C288(position17, 0x1F4, 7) != 0) {
                playerContact22 = 1;
                M2C_FIELD(&Haunted8464C_D_80070328, int*, 0x298) =
                    func_8004E880(Haunted8464C_D_80070328.x - moby->position.x,
                                  Haunted8464C_D_80070328.y - moby->position.y, 0);
            }
            if ((playerContact22 != 0) || (func_800359A4(privateData18 + 4, 4) != 0) ||
                (ground20 = &Haunted8464C_D_80071908, moby->position.z < (*ground20 + 120))) {
                func_8003BABC(moby, 0, 0);
                previousParticle4 = M2C_FIELD(privateData18, signed char**, 0x14);
                if (previousParticle4 != 0) {
                    Haunted8464C_func_80056504(previousParticle4);
                }
                Haunted8464CRefreshMobySpatialGridAndBasis(moby, 4);
                moby->angle.roll = 0;
                moby->angle.pitch = 0;
                value2 = M2C_FIELD(&Haunted8464C_D_80065920, short*, moby->angle.yaw * 2);
                value2 = (value2 * 75) >> 11;
                originalStack.sp18.x = value2;
                value2 = moby->angle.yaw;
                childIndex21 = 0;
                value2 = M2C_FIELD(&Haunted8464C_D_800658A0, short*, value2 * 2);
                MATCHING_KEEP_CLOBBER(value2, "$20");
                vector20 = &originalStack.sp28;
                originalStack.sp18.z = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                originalStack.sp18.y = (value2 * 75) >> 11;
            spawnNextChild:
                if ((Haunted8464C_D_8006C578 - Haunted8464C_D_8006C574) >= 0x15) {
                    spawnedChild18 = SpawnMoby(0x210, moby);
                    MATCHING_KEEP(spawnedChild18);
                    if (spawnedChild18 != 0) {
                        spawnedData17 = spawnedChild18->mobyTag;
                        spawnedChild18->state = 2;
                        previousYaw16 = moby->angle.yaw;
                        value2 = func_8003636C(8, 64);
                        cosineCursor4 = (short*)&Haunted8464C_D_80065920;
                        value2 = previousYaw16 + value2;
                        previousYaw16 <<= 1;
                        cosineCursor4 = (short*)((int)cosineCursor4 + previousYaw16);
                        moby->angle.yaw = value2;
                        sineCursor16 = (short*)(previousYaw16 + (int)&Haunted8464C_D_800658A0);
                        {
                            register int p5 __asm__("$5");
                            value3 = *cosineCursor4;
                            value2 = originalStack.sp18.x;
                            p5 = value2 * value3;
                            value3 = *sineCursor16;
                            value2 = originalStack.sp18.y;
                            value3 = value2 * value3;
                            value2 = p5 - value3;
                            M2C_FIELD(spawnedData17, int*, 8) = value2 >> 12;
                        }
                        {
                            register int p6 __asm__("$6");
                            value3 = *sineCursor16;
                            value2 = originalStack.sp18.x;
                            p6 = value2 * value3;
                            value3 = *cosineCursor4;
                            value2 = originalStack.sp18.y;
                            value3 = value2 * value3;
                            value2 = p6 + value3;
                            M2C_FIELD(spawnedData17, int*, 12) = value2 >> 12;
                        }
                        M2C_FIELD(spawnedData17, int*, 0x10) = func_8003636C(0x4B, 0xC8);
                        M2C_FIELD(spawnedData17, signed char*, 0) =
                            (signed char)(func_8003636C(0, 0xA) - 5);
                        M2C_FIELD(spawnedData17, signed char*, 1) =
                            (signed char)(func_8003636C(0, 0xA) - 5);
                        M2C_FIELD(spawnedData17, signed char*, 2) =
                            (signed char)(func_8003636C(0, 0xA) - 5);
                        M2C_FIELD(spawnedData17, int*, 4) = 0x78;
                        M2C_FIELD(spawnedData17, signed char*, 3) = 3;
                        if (Haunted8464C_rand() & 1) {
                            Haunted8464CSetMobyAnimation(spawnedChild18, 1);
                        }
                        if (playerContact22 != 0) {
                            childHeight2 = spawnedChild18->position.z + 0x96;
                        } else {
                            childHeight2 = Haunted8464C_D_80071908 + 0x96;
                        }
                        spawnedChild18->position.z = childHeight2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        spawnedChild18->size = 0x6A;
                        spawnedChild18->lowDrawDistance = 0x3F;
                        spawnedChild18->updateDistance = 0xFF;
                        originalStack.sp28 = func_8003636C(0, 0x1F4) - 0xFA;
                        originalStack.sp2C = func_8003636C(0, 0x1F4) - 0xFA;
                        originalStack.sp30 = func_8003636C(0, 0xFA);
                        Haunted8464CTransformVectorByBasis(&moby->rotationMatrix, vector20,
                                                           vector20);
                        childPosition4 = &spawnedChild18->position;
                        func_8004F194(childPosition4, childPosition4, vector20);
                    }
                    childIndex21 += 1;
                    if (childIndex21 < 5) {
                        goto spawnNextChild;
                    }
                }
                if (playerContact22) {
                    copySource5 = &Haunted8464C_D_80070328;
                    MATCHING_KEEP_VOLATILE(copySource5);
                    argument4 = (int)&moby->position;
                    goto copyPosition;
                }
                argument4 = (int)&moby->position;
                MATCHING_KEEP(argument4);
                copySource5 = &Haunted8464C_D_80071900;
            copyPosition:
                func_8004F178(argument4, copySource5);
                func_800369B8(moby, 0x1E);
                argument4 = (int)moby;
                releaseCount5 = 30;
                goto releaseMoby;
            }
            func_8004F178(&originalStack.sp18, position17);
            value2 = M2C_FIELD(privateData18, int*, 20);
            argument4 = (int)&originalStack.sp18;
            if (value2 == 0) {
                MATCHING_KEEP(playerContact22);
                func_8004F178(argument4, position17);
                argument4 = 1;
                argument5 = 50;
                argument6 = (int)&originalStack.sp18;
                value2 = *ground20;
                callback3 = HauntedParticleCallback;
                argument7 = 0;
                originalStack.sp18.z = value2;
                value2 = (int)callback3(argument4, argument5, argument6, argument7);
                M2C_FIELD(privateData18, int*, 20) = value2;
                if (value2 == 0)
                    return;
            }
            {
                value2 = moby->position.z;
                value3 = *ground20;
                MATCHING_KEEP2_CLOBBER(value2, value3, "$4");
                argument4 = 12000;
                value3 = value2 - value3;
                MATCHING_KEEP(argument4);
                value2 = argument4 < value3;
                MATCHING_KEEP(value2);
                if (value2) {
                    value3 = 12000;
                    MATCHING_KEEP(value3);
                    remainingHeight2 = argument4 - value3;
                } else
                    remainingHeight2 = argument4 - value3;
                particleFade3 = (remainingHeight2 << 9) / argument4 / 4;
                if (particleFade3 >= 0x100) {
                    particleFade3 = 0xFF;
                }
                M2C_FIELD(M2C_FIELD(privateData18, signed char**, 0x14), signed char*, 0xA) =
                    (signed char)particleFade3;
                func_8004F178(&originalStack.sp38, position17);
                originalStack.sp38.z = *ground20;
                func_8004F504((Vector3D16*)(M2C_FIELD(privateData18, signed char**, 0x14) + 4),
                              (Vector3D16*)&originalStack.sp38);
                return;
            }
            break;
        case 2:
            if (Haunted8464C_func_80019138(&moby->position, 0x80, 1, 0, 0, 0) != 0) {
                if (((Haunted8464C_D_80071918 < 0x64) && (Haunted8464C_D_8007191C < 0x64)) ||
                    (remainingBounces2 = M2C_FIELD(privateData18, unsigned char*, 3) - 1,
                     M2C_FIELD(privateData18, unsigned char*, 3) = remainingBounces2,
                     ((remainingBounces2 & 0xFF) == 0))) {
                    M2C_FIELD(privateData18, int*, 4) = 0;
                }
                response16 = &Haunted8464C_D_80071918;
                Haunted8464CNormalizeVectorToLength(response16, 4096);
                {
                    register int p5 __asm__("$5");
                    register int p4 __asm__("$4");
                    value3 = M2C_FIELD(privateData18, int*, 8);
                    value2 = *response16;
                    p5 = value3 * value2;
                    value3 = M2C_FIELD(privateData18, int*, 12);
                    value2 = Haunted8464C_D_8007191C;
                    p4 = value3 * value2;
                    value3 = M2C_FIELD(privateData18, int*, 16);
                    value2 = Haunted8464C_D_80071920;
                    value3 = value3 * value2;
                    value2 = p5 + p4;
                    value2 += value3;
                    dotProduct2 = value2;
                }
                projection7 = dotProduct2 >> 0xB;
                timerAddress4 = privateData18 + 4;
                MATCHING_KEEP(timerAddress4);
                if (projection7 < 0) {
                    argument4 = (int)response16;
                    argument5 = 4096;
                    MATCHING_KEEP2(argument4, argument5);
                    argument6 = dotProduct2 >> 13;
                    Haunted8464CScaleVectorRatioQ15(argument4, argument5, argument6 - projection7,
                                                    projection7);
                    M2C_FIELD(privateData18, int*, 8) =
                        (int)(M2C_FIELD(privateData18, int*, 8) + *response16);
                    M2C_FIELD(privateData18, int*, 0xC) =
                        (int)(M2C_FIELD(privateData18, int*, 0xC) + Haunted8464C_D_8007191C);
                    M2C_FIELD(privateData18, int*, 0x10) =
                        (int)(M2C_FIELD(privateData18, int*, 0x10) + Haunted8464C_D_80071920);
                    MATCHING_BARRIER_VOLATILE("$4");
                    timerAddress4 = privateData18 + 4;
                }
            }
            timerAddress4 = privateData18 + 4;
            if (func_800359A4(timerAddress4, 4) != 0) {
                argument4 = (int)moby;
                releaseCount5 = 40;
            releaseMoby:
                func_800369B8(argument4, releaseCount5);
                Haunted8464CDeleteMoby(moby);
                return;
            }
            moby->position.x += M2C_FIELD(privateData18, int*, 8);
            moby->position.y += M2C_FIELD(privateData18, int*, 0xC);
            nextFallSpeed2 = M2C_FIELD(privateData18, int*, 0x10) - 0xA;
            M2C_FIELD(privateData18, int*, 0x10) = nextFallSpeed2;
            if (nextFallSpeed2 < -0xC8) {
                M2C_FIELD(privateData18, int*, 0x10) = -0xC8;
            }
            moby->position.z += M2C_FIELD(privateData18, int*, 0x10);
            moby->angle.roll += M2C_FIELD(privateData18, unsigned char*, 0);
            moby->angle.pitch += M2C_FIELD(privateData18, unsigned char*, 1);
            moby->angle.yaw += M2C_FIELD(privateData18, unsigned char*, 2);
            break;
    }
}
#undef M2C_FIELD


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original level43 controller80084E4C.
 * Assembly SHA256 0d629024d5db154452e44cfb3c48f348e0d17b9f3115c1b41bb463822e731496.
 * AI generated; not human reviewed.1118 original native instructions,
 * 83 original selector entries and one zero pad=1202 owned words.
 * Every field width/offset,helper word,constant and control destination
 * comes from this original body; names describe raw storage roles only.
 * Original E8 frame preserves SP18..A3 initialized scalar/vector homes.
 * The candidate minimum and owner are initialized to100000 and0 before
 * every scan. All copied vector components are written by original4F178
 * before local reads; original known vector output helpers retain all3words.
 * The original S0 vector address dies before S0's later Boolean/returned
 * owner roles. The disjoint T0 division,selected-owner and two coordinate
 * captures each consume their own entire initialized signed64 product.
 * Both signed32 operands are staged before casting; /10 first wraps the
 * helper length*9 to its original32-bit word. Each coordinate starts from
 * a signed16 table value*125,arithmetic>>11,then signed16 pitch multiply;
 * only its initialized low32 word is shifted by12. Products never use a
 * partial HI/LO input. The compiler-local union obeys __MIPSEB__ and never
 * escapes to runtime memory. Its signed high and unsigned low are explicit.
 * Original state2 prepares A0=owner+12 in the first branch delay,then
 * independently recomputes it in49484's call delay. Whole initialized
 * owner/A0 identities preserve both phases and the else-path A1 copy.
 * Empty metadata emits zero CPU words and observes complete initialized
 * objects or ends a dead GP phase. No incoming saved value,unwritten local,
 * invented default,CPU opcode asm,fixed FP/SP or live fixed alias overlap.
 * Known views reuse original stdutil/mobyutil ABI; other helpers retain
 * only their original physical word view. Helper/asset/SFX meanings,units,
 * update cadence beyond invocation,Rev1 mapping and captures remain open.
 * Compiler,filter and flags remain frozen. Acceptance requires all native
 * and linked words,actual branch/J/call/selector destinations,symbol/addend,
 * original .rodata+pad and full EXE/every-overlay retail hashes.
 */
#define Actor1118Keep(x) __asm__("" : "=r"(x) : "0"(x))
#define Actor1118Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor1118_func_80013E38() __asm__("func_80013E38");
int Actor1118_func_8001830C() __asm__("func_8001830C");
int Actor1118_func_80019194() __asm__("func_80019194");
int Actor1118_func_8001A358() __asm__("func_8001A358");
int Actor1118_func_8001BA30() __asm__("func_8001BA30");
int Actor1118_func_8001C288() __asm__("func_8001C288");
int Actor1118CountTimerDown(void*, int) __asm__("func_800359A4");
int Actor1118ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Actor1118RandBetween(int, int) __asm__("func_8003636C");
int Actor1118_func_800365E4() __asm__("func_800365E4");
int Actor1118PlayMobySoundEvent() __asm__("func_8003BABC");
int Actor1118_func_80049484() __asm__("func_80049484");
int Actor1118PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Actor1118TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Actor1118MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Actor1118_func_8004EF74(void*, void*, void*) __asm__("func_8004EF74");
int Actor1118ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Actor1118ShiftVectorRightTowardZero() __asm__("func_8004F110");
int Actor1118ClearVector() __asm__("func_8004F168");
void Actor1118CopyVector(void*, void*) __asm__("func_8004F178");
void Actor1118AddVector(void*, void*, void*) __asm__("func_8004F194");
int Actor1118SubtractVector() __asm__("func_8004F1C8");
int Actor1118AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Actor1118ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Actor1118DeleteMoby() __asm__("func_80055B18");
int Actor1118RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor1118InterpolateMobyVertex() __asm__("func_80055F14");
int Actor1118_func_8005629C() __asm__("func_8005629C");
extern int Actor1118_D_800658A0 __asm__("D_800658A0");
extern int Actor1118_D_80065920 __asm__("D_80065920");
extern int Actor1118_D_8006C550 __asm__("D_8006C550");
extern int Actor1118_D_8006C574 __asm__("D_8006C574");
extern int Actor1118_D_8006C578 __asm__("D_8006C578");
extern int Actor1118_D_8006C640 __asm__("D_8006C640");
extern int Actor1118_D_8006C704 __asm__("D_8006C704");
extern int Actor1118_D_8006E020 __asm__("D_8006E020");
extern int Actor1118_D_8006E024 __asm__("D_8006E024");
extern unsigned short Actor1118_D_8006E03E __asm__("D_8006E03E");
extern unsigned short Actor1118_D_8006E040 __asm__("D_8006E040");
extern int Actor1118_D_8006E044 __asm__("D_8006E044");
extern int Actor1118_D_8006E344 __asm__("D_8006E344");
extern int Actor1118_D_80070328 __asm__("D_80070328");
extern int Actor1118_D_80071900 __asm__("D_80071900");
extern int Actor1118_D_80071908 __asm__("D_80071908");
extern int Actor1118_D_80071918 __asm__("D_80071918");
extern int Actor1118_D_8007191C __asm__("D_8007191C");
extern int Actor1118_D_80071920 __asm__("D_80071920");
extern int (*Actor1118_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Actor1118_SpawnParticle)() __asm__("SpawnParticle");
extern int Actor1118CritterPointer __asm__("D_80070328 + 0x250");
extern Spyro Actor1118KnownSpyro __asm__("D_80070328");
union Actor1118Product {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned int low;
#else
        unsigned int low;
        int high;
#endif
    } words;
};
void func_level_43_80084E4C(void* input) {
    register int previousVectorAddress16 __asm__("$16");
    register int owner18 __asm__("$18"), privateRecord19 __asm__("$19"),
        retainedWordOrAddress16 __asm__("$16"), retainedAngleScoreOrAddress17 __asm__("$17"),
        candidateOrOwnerAddress20 __asm__("$20"), incrementOrVectorAddress21 __asm__("$21"),
        candidateCursor22 __asm__("$22"), originalCameraAddress23 __asm__("$23");
    union Actor1118Product divisionProduct, firstCoordinateProduct, secondCoordinateProduct;
    register int divisionHigh8 __asm__("$8"), firstCoordinateLow8 __asm__("$8"),
        secondCoordinateLow8 __asm__("$8");
    register int resultWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), selectedOwner8 __asm__("$8");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84,
            sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4;
    } originalFrame;
    int temporaryWord4;
    int temporaryWord17;
    int temporaryWord3;
    int temporaryWord20;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord14;
    int temporaryWord22;
    int temporaryWord23;
    int temporaryWord25;
    int temporaryWord26;
    int temporaryWord2;
    int temporaryWord7;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord18;
    int temporaryWord19;
    int temporaryWord24;
    int temporaryWord1;
    int ownerPositionAddress;
    int temporaryWord6;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord21;
    int temporaryWord27;
    owner18 = (int)input;
    MATCHING_KEEP(owner18);
    temporaryWord15 = Actor1118Field(owner18, unsigned char*, 0x48);
    privateRecord19 = Actor1118Field(owner18, int**, 0);
    switch (temporaryWord15) {
        case 0x0:
            temporaryWord16 = Actor1118Field(owner18, unsigned char*, 0x3A);
            if ((temporaryWord16 == 0xFF) ||
                (temporaryWord1 = (temporaryWord16 * 0x58) + Actor1118_D_8006C550,
                 (Actor1118Field(temporaryWord1, short*, 0x36) != 0x63)) ||
                (Actor1118Field(Actor1118Field(temporaryWord1, void**, 0), int*, 0x78) !=
                 owner18)) {
                temporaryWord17 = Actor1118Field(privateRecord19, short*, 0xC);
                if (temporaryWord17 < 0x64) {
                    temporaryWord26 = (int)(0x64 - temporaryWord17) >> 2;
                    if (temporaryWord26 >= 0x10) {
                        temporaryWord26 = 0xF;
                        if (Actor1118_D_8006C640 & 1) {
                            temporaryWord23 = Actor1118Field(owner18, int*, 0x14) + 0x14;
                        } else {
                            temporaryWord23 = Actor1118Field(owner18, int*, 0x14) - 0x14;
                        }
                        Actor1118Field(owner18, int*, 0x14) = temporaryWord23;
                    }
                    Actor1118Field(owner18, unsigned char*, 0x54) = 0xFF;
                    Actor1118Field(owner18, signed char*, 0x55) = 0;
                    Actor1118Field(owner18, signed char*, 0x56) = 0;
                    Actor1118Field(owner18, signed char*, 0x57) =
                        (signed char)(temporaryWord26 + 0x30);
                }
                if (Actor1118CountTimerDown(privateRecord19 + 0xC, 2) != 0) {
                    temporaryWord2 = Actor1118Field(owner18, unsigned char*, 0x3A);
                    temporaryWord27 = 0;
                    if (temporaryWord2 != 0xFF) {
                        temporaryWord27 = Actor1118_D_8006C550 + (temporaryWord2 * 0x58);
                    }
                    retainedWordOrAddress16 = owner18 + 0xC;
                    Actor1118_func_8001BA30(retainedWordOrAddress16, 0x5DC, 1, 0, 0x140000,
                                            temporaryWord27);
                    if (Actor1118_func_8001C288(retainedWordOrAddress16, 0x400, 7) != 0) {
                        Actor1118Field((int)&Actor1118_D_80070328, int*, 0x298) =
                            Actor1118PlanarHeadingLookup(
                                Actor1118Field((int)&Actor1118_D_80070328, int*, 0) -
                                    Actor1118Field(owner18, int*, 0xC),
                                Actor1118Field((int)&Actor1118_D_80070328, int*, 4) -
                                    Actor1118Field(owner18, int*, 0x10),
                                0);
                    }
                    temporaryWord24 = 5;
                    goto storeOriginalFinalState;
                }
                if ((Actor1118Field((int)&Actor1118_D_80070328, int*, 0x24C) == 4) &&
                    ((resultWord2 = Actor1118KnownSpyro.critterMobyPtr) != 0)) {
                    MATCHING_KEEP(resultWord2);
                    retainedWordOrAddress16 = Actor1118Field(resultWord2, int*, 0);
                    if ((Actor1118Field(retainedWordOrAddress16, int*, 0x78) == 0) &&
                        (Actor1118Field(retainedWordOrAddress16, short*, 0x76) == 0) &&
                        (Actor1118_func_8001C288(owner18 + 0xC, 0x200, 0) != 0)) {
                        Actor1118DeleteMoby(owner18);
                        Actor1118Field(retainedWordOrAddress16, short*, 0x76) = 1;
                        Actor1118Field(retainedWordOrAddress16, int*, 0x7C) = 0;
                        Actor1118Field(retainedWordOrAddress16, short*, 0x74) = 0x22A;
                        return;
                    }
                } else if ((Actor1118AbsoluteByteAngleDelta(
                                Actor1118Field((int)&Actor1118_D_80070328, unsigned char*, 0xE),
                                Actor1118PlanarHeadingLookup(
                                    Actor1118Field(owner18, int*, 0xC) -
                                        Actor1118Field((int)&Actor1118_D_80070328, int*, 0),
                                    Actor1118Field(owner18, int*, 0x10) -
                                        Actor1118Field((int)&Actor1118_D_80070328, int*, 4),
                                    0)) < 0x10) &&
                           ({
                               resultWord2 = (Actor1118ApproximatePlanarDistance(
                                                  owner18 + 0xC, (int)&Actor1118_D_80070328) -
                                              0x258) < 0xFA;
                               rawWord3 = Actor1118Field(owner18, int*, 0x14);
                               argumentWord4 = Actor1118Field((int)&Actor1118_D_80070328, int*, 8);
                               rawWord3 += 0x164;
                               MATCHING_KEEP3(resultWord2, rawWord3, argumentWord4);
                               if (resultWord2) {
                                   argumentWord4 -= rawWord3;
                                   resultWord2 = argumentWord4 < 0x100;
                               } else
                                   resultWord2 = 0;
                               resultWord2;
                           }) &&
                           (Actor1118_D_8006E344 != 1) && (Actor1118KnownSpyro.unk13f[0] == 0)) {
                    Actor1118KnownSpyro.unk17a = 0x10000001;
                    Actor1118KnownSpyro.m_WhirlwindPointer = owner18;
                    Actor1118Field(owner18, signed char*, 0x4F) = 0x20;
                    return;
                }
            } else {
                default:
                    return;
            }
            break;
        case 0x6:
            retainedWordOrAddress16 = owner18 + 0xC;
            Actor1118AddVector(retainedWordOrAddress16, privateRecord19, retainedWordOrAddress16);
            if (Actor1118CountTimerDown(privateRecord19 + 0xC, 2) != 0) {
                originalFrame.sp18 = 0;
                originalFrame.sp1C = 0;
                originalFrame.sp20 = 6;
                temporaryWord6 =
                    Actor1118_SpawnParticle(1, 0x3C, retainedWordOrAddress16, &originalFrame.sp18);
                if (temporaryWord6 != 0) {
                    Actor1118Field(temporaryWord6, signed char*, 0xA) = 0x28;
                }
                temporaryWord8 =
                    Actor1118_SpawnParticle(1, 0x3C, retainedWordOrAddress16, &originalFrame.sp18);
                if (temporaryWord8 != 0) {
                    Actor1118Field(temporaryWord8, signed char*, 0xA) = 0x28;
                }
                goto callOriginalDelete;
            }
            break;
        case 0x4:
        case 0x5:
            originalFrame.sp28 = 0;
            originalFrame.sp2C = 0;
            originalFrame.sp30 = 0;
            Actor1118PlayMobySoundEvent(owner18, 1, 0);
            argumentWord4 = 1;
            argumentWord5 = 0x3C;
            MATCHING_KEEP2(argumentWord4, argumentWord5);
            retainedWordOrAddress16 = owner18 + 0xC;
            Actor1118Field(owner18, signed char*, 0x41) = 0;
            Actor1118Field(owner18, signed char*, 0x4C) = 0;
            Actor1118Field(owner18, signed char*, 0x4D) = 0;
            resultWord2 = (int)Actor1118_SpawnParticle;
            Actor1118Field(owner18, int*, 8) = 0;
            temporaryWord9 = ((int (*)())resultWord2)(argumentWord4, argumentWord5,
                                                      retainedWordOrAddress16, &originalFrame.sp28);
            if (temporaryWord9 != 0) {
                Actor1118Field(temporaryWord9, signed char*, 0xA) = 0x46;
            }
            temporaryWord10 =
                Actor1118_SpawnParticle(1, 0x3C, retainedWordOrAddress16, &originalFrame.sp28);
            if (temporaryWord10 != 0) {
                Actor1118Field(temporaryWord10, signed char*, 0xA) = 0x46;
            }
            Actor1118_SpawnParticle(0x10, 0x46, retainedWordOrAddress16, (int*)0x10);
            Actor1118Field(owner18, unsigned char*, 0x46) = Actor1118PlanarHeadingLookup(
                Actor1118_D_8006E020 - Actor1118Field(owner18, int*, 0xC),
                Actor1118_D_8006E024 - Actor1118Field(owner18, int*, 0x10), 0);
            incrementOrVectorAddress21 = 0x20;
            if (Actor1118Field(owner18, unsigned char*, 0x48) == 5) {
                incrementOrVectorAddress21 = 0x10;
            }
            candidateOrOwnerAddress20 = 0;
            privateRecord19 = 0;
        spawnOriginalEightChildren:
            if ((Actor1118_D_8006C578 - Actor1118_D_8006C574) >= 0x15) {
                temporaryWord11 = Actor1118_SpawnMoby(0x22A, owner18);
                argumentWord4 = 0;
                if (temporaryWord11 != 0) {
                    Actor1118Field(temporaryWord11, signed char*, 0x4F) = 0x40;
                    resultWord2 = Actor1118Field(owner18, unsigned char*, 0x46);
                    MATCHING_BARRIER_VOLATILE("memory");
                    retainedWordOrAddress16 = Actor1118Field(temporaryWord11, int*, 0);
                    Actor1118Field(temporaryWord11, unsigned char*, 0x46) = resultWord2;
                    resultWord2 = Actor1118RandBetween(argumentWord4, 0xA);
                    argumentWord4 = temporaryWord11;
                    argumentWord5 = 4;
                    MATCHING_KEEP2(argumentWord4, argumentWord5);
                    resultWord2 -= 5;
                    Actor1118Keep(resultWord2);
                    resultWord2 = privateRecord19 + resultWord2;
                    Actor1118Keep(resultWord2);
                    Actor1118Field(temporaryWord11, signed char*, 0x44) = resultWord2;
                    Actor1118Field(temporaryWord11, signed char*, 0x48) = 6;
                    Actor1118Field(temporaryWord11, int*, 8) = 0;
                    originalFrame.sp28 = 0;
                    originalFrame.sp2C = 0xC8;
                    originalFrame.sp30 = 0;
                    Actor1118RefreshMobySpatialGridAndBasis(argumentWord4, argumentWord5);
                    Actor1118TransformVectorByBasis(temporaryWord11 + 0x20, &originalFrame.sp28,
                                                    retainedWordOrAddress16);
                    Actor1118Field(retainedWordOrAddress16, short*, 0xC) =
                        Actor1118RandBetween(7, 0xF);
                }
                candidateOrOwnerAddress20 += 1;
                privateRecord19 += incrementOrVectorAddress21;
                if (candidateOrOwnerAddress20 < 8) {
                    goto spawnOriginalEightChildren;
                }
            }
            MATCHING_BARRIER_VOLATILE("$4");
            retainedAngleScoreOrAddress17 = Actor1118_SpawnMoby(0x146, owner18);
            MATCHING_KEEP(retainedAngleScoreOrAddress17);
            if (retainedAngleScoreOrAddress17 != 0) {
                Actor1118Field(retainedAngleScoreOrAddress17, signed char*, 0x4C) = 0x20;
                Actor1118Field(retainedAngleScoreOrAddress17, unsigned char*, 0x4A) = 0xFF;
                Actor1118Field(retainedAngleScoreOrAddress17, signed char*, 0x47) = 8;
            }
            goto callOriginalDelete;
        case 0x1:
            Actor1118Field(owner18, unsigned char*, 0x4A) = 0xFF;
            Actor1118Field(owner18, int*, 8) = 0;
            Actor1118Field(owner18, signed char*, 0x4C) = 0;
            Actor1118Field(owner18, signed char*, 0x4D) = 0;
            Actor1118Field(owner18, signed char*, 0x54) = 0;
            Actor1118Field(owner18, signed char*, 0x55) = 0;
            Actor1118Field(owner18, signed char*, 0x56) = 0;
            Actor1118Field(owner18, signed char*, 0x57) = 0x30;
            return;
        case 0x52:
            temporaryWord3 = owner18 + 0xC;
            Actor1118AddVector(temporaryWord3, privateRecord19, temporaryWord3);
            temporaryWord12 = Actor1118Field(privateRecord19, int*, 8) - 8;
            Actor1118Field(privateRecord19, int*, 8) = temporaryWord12;
            if (temporaryWord12 < -0x190) {
                Actor1118Field(privateRecord19, int*, 8) = -0x190;
            }
            temporaryWord13 = Actor1118ProbeGroundFromRaisedMoby(owner18);
            if ((temporaryWord13 != 0) &&
                ((Actor1118Field(owner18, int*, 0x14) - temporaryWord13) < 0x50)) {
                Actor1118PlayMobySoundEvent(owner18, 0, 0);
                if (Actor1118Field(privateRecord19, short*, 0x10) == 0) {
                    Actor1118ScaleVectorRatioQ15(
                        privateRecord19, Actor1118MeasureVectorLength(privateRecord19, 1), 0x28);
                    Actor1118Field(owner18, int*, 0x14) = (int)(Actor1118_D_80071908 + 0x80);
                    Actor1118Field(privateRecord19, int*, 8) = 0x32;
                    Actor1118Field(privateRecord19, short*, 0x10) = 1;
                    return;
                }
                resultWord2 = Actor1118_D_80071908;
                Actor1118Field(owner18, unsigned char*, 0x48) = 0;
                Actor1118Field(owner18, unsigned char*, 0x49) = 0;
                Actor1118Field(owner18, int*, 0x14) = resultWord2 + 0x37;
                Actor1118Field(privateRecord19, short*, 0xC) = 0x118;
                Actor1118ClearVector(privateRecord19);
                return;
            }
            break;
        case 0x2:
            originalFrame.sp68 = 0x186A0;
            originalFrame.spA0 = 0;
            Actor1118Field(owner18, signed char*, 0x4F) = 0x20;
            Actor1118Field(owner18, signed char*, 0x4C) = 0x50;
            Actor1118Field(owner18, unsigned char*, 0x45) = 0U;
            Actor1118Field(owner18, signed char*, 0x4D) = 1;
            argumentWord4 = owner18 + 0xC;
            if (Actor1118Field((int)&Actor1118_D_8006E044, int*, 0) == 7) {
                MATCHING_KEEP2_VOLATILE(argumentWord4, owner18);
                Actor1118_func_80049484(owner18 + 0xC);
            } else {
                MATCHING_KEEP(argumentWord4);
                Actor1118Field(owner18, int*, 0xC) =
                    (int)((int)(Actor1118Field((int)&Actor1118_D_80065920, short*,
                                               (Actor1118Field((int)&Actor1118_D_80070328,
                                                               unsigned char*, 0xE) *
                                                2)) *
                                0x4B) >>
                          9);
                temporaryWord4 = Actor1118Field(
                    (int)&Actor1118_D_800658A0, short*,
                    (Actor1118Field((int)&Actor1118_D_80070328, unsigned char*, 0xE) * 2));
                Actor1118Field(owner18, int*, 0x14) = 0xC8;
                Actor1118Field(owner18, int*, 0x10) = (int)((int)(temporaryWord4 * 0x4B) >> 9);
                Actor1118AddVector(argumentWord4, argumentWord4,
                                   ((int)&Actor1118_D_80070328 + 0xE) - 0xE);
            }
            Actor1118CopyVector(&originalFrame.sp48, (int)&Actor1118_D_80070328);
            argumentWord4 = (int)&originalFrame.sp48;
            Actor1118Keep(argumentWord4);
            candidateOrOwnerAddress20 = owner18 + 0xC;
            originalFrame.sp50 += 0xC8;
            if (Actor1118_func_8001830C(argumentWord4, candidateOrOwnerAddress20, 3, 0, 0) != 0) {
                Actor1118SubtractVector(&originalFrame.sp48, (int)&Actor1118_D_80071900,
                                        (int)&Actor1118_D_80070328);
                temporaryWord14 = Actor1118MeasureVectorLength(&originalFrame.sp48, 1);
                rawWord3 = 0x66666667;
                argumentWord6 = (int)((unsigned int)temporaryWord14 * 9U);
                MATCHING_KEEP2(rawWord3, argumentWord6);
                divisionProduct.full = (long long)argumentWord6 * (long long)rawWord3;
                argumentWord4 = (int)&originalFrame.sp48;
                argumentWord5 = temporaryWord14;
                argumentWord6 >>= 31;
                __asm__ volatile(""
                                 : "=x"(divisionProduct.full)
                                 : "0"(divisionProduct.full), "r"(argumentWord4),
                                   "r"(argumentWord5), "r"(argumentWord6));
                divisionHigh8 = (int)divisionProduct.words.high;
                Actor1118Keep(divisionHigh8);
                resultWord2 = divisionHigh8 >> 2;
                Actor1118ScaleVectorRatioQ15(argumentWord4, argumentWord5,
                                             resultWord2 - argumentWord6);
                Actor1118AddVector(candidateOrOwnerAddress20, (int)&Actor1118_D_80070328,
                                   &originalFrame.sp48);
            }
            Actor1118Field(owner18, unsigned char*, 0x46) =
                (unsigned char)(Actor1118Field((int)&Actor1118_D_80070328, unsigned char*, 0xE) +
                                Actor1118Field((int)&Actor1118_D_80070328, unsigned char*, 0x12));
            if (Actor1118Field((int)&Actor1118_D_8006E044, int*, 0) == 7) {
                Actor1118Field(owner18, unsigned char*, 0x45) =
                    (unsigned char)(0xE - ((int)(Actor1118_D_8006E03E << 0x10) >> 0x14));
                Actor1118Field(owner18, unsigned char*, 0x46) =
                    (unsigned char)((unsigned short)Actor1118_D_8006E040 >> 4);
            } else {
                Actor1118Field(owner18, unsigned char*, 0x45) = 0xEU;
            }
            candidateCursor22 = Actor1118_D_8006C550;
            if (candidateCursor22 < (unsigned int)Actor1118_D_8006C704) {
                incrementOrVectorAddress21 = (int)&originalFrame.sp38;
                Actor1118Keep(incrementOrVectorAddress21);
                originalCameraAddress23 = (int)&Actor1118_D_8006E044;
                MATCHING_KEEP(originalCameraAddress23);
                ownerPositionAddress = owner18 + 0xC;
                candidateOrOwnerAddress20 = candidateCursor22;
                do {
                    if (!(Actor1118Field(candidateOrOwnerAddress20, unsigned char*, 0x48) & 0x80) &&
                        (Actor1118Field(candidateOrOwnerAddress20, int*, 8) != 0) &&
                        (Actor1118Field(candidateOrOwnerAddress20, unsigned char*, 0x4D) != 0)) {
                        Actor1118CopyVector(incrementOrVectorAddress21, candidateCursor22 + 0xC);
                        originalFrame.sp40 += 0x258;
                        retainedAngleScoreOrAddress17 =
                            (Actor1118PlanarHeadingLookup(
                                 originalFrame.sp38 - Actor1118Field(owner18, int*, 0xC),
                                 originalFrame.sp3C - Actor1118Field(owner18, int*, 0x10), 0) -
                             Actor1118Field(owner18, unsigned char*, 0x46)) &
                            0xFF;
                        if (retainedAngleScoreOrAddress17 >= 0x81) {
                            retainedAngleScoreOrAddress17 -= 0x100;
                        }
                        if (Actor1118Field(originalCameraAddress23, int*, 0) == 7) {
                            retainedWordOrAddress16 =
                                (Actor1118PlanarHeadingLookup(
                                     Actor1118ApproximatePlanarDistance(originalCameraAddress23 -
                                                                            0x24,
                                                                        incrementOrVectorAddress21),
                                     Actor1118Field(originalCameraAddress23, int*, -0x1C) -
                                         originalFrame.sp40,
                                     1) -
                                 Actor1118Field(originalCameraAddress23, short*, -6)) &
                                0xFFF;
                            if (retainedWordOrAddress16 >= 0x801) {
                                retainedWordOrAddress16 -= 0x1000;
                            }
                            temporaryWord25 = retainedWordOrAddress16;
                            if (retainedWordOrAddress16 < 0) {
                                temporaryWord25 = -temporaryWord25;
                            }
                            resultWord2 = temporaryWord25 < 0x65;
                            resultWord2 ^= 1;
                            resultWord2 = -resultWord2;
                            Actor1118Keep(resultWord2);
                            retainedWordOrAddress16 = resultWord2 & 0x63;
                        } else {
                            retainedWordOrAddress16 =
                                (Actor1118PlanarHeadingLookup(
                                     Actor1118ApproximatePlanarDistance(owner18 + 0xC,
                                                                        incrementOrVectorAddress21),
                                     originalFrame.sp40 - Actor1118Field(owner18, int*, 0x14), 0) -
                                 Actor1118Field(owner18, unsigned char*, 0x45)) &
                                0xFF;
                            if (retainedWordOrAddress16 >= 0x81) {
                                retainedWordOrAddress16 -= 0x100;
                            }
                        }
                        if (retainedAngleScoreOrAddress17 < 0) {
                            retainedAngleScoreOrAddress17 = -retainedAngleScoreOrAddress17;
                        }
                        Actor1118Keep(retainedAngleScoreOrAddress17);
                        if ((retainedAngleScoreOrAddress17 < 0xA) &&
                            (retainedWordOrAddress16 < 0x20)) {
                            rawWord3 = Actor1118ApproximatePlanarDistance(
                                ownerPositionAddress, incrementOrVectorAddress21);
                            resultWord2 = rawWord3 < 0x3000;
                            Actor1118Keep(resultWord2);
                            if (resultWord2 && ({
                                    resultWord2 = rawWord3 < 0x81;
                                    Actor1118Keep(resultWord2);
                                    !resultWord2;
                                })) {
                                retainedAngleScoreOrAddress17 =
                                    (retainedAngleScoreOrAddress17 * 8) + retainedWordOrAddress16;
                                rawWord3 >>= 10;
                                resultWord2 = originalFrame.sp68;
                                retainedAngleScoreOrAddress17 += rawWord3;
                                if ((retainedAngleScoreOrAddress17 < resultWord2) &&
                                    (Actor1118_func_80013E38(ownerPositionAddress,
                                                             incrementOrVectorAddress21, 4) != 0)) {
                                    originalFrame.spA0 = candidateOrOwnerAddress20;
                                    originalFrame.sp68 = retainedAngleScoreOrAddress17;
                                }
                            }
                        }
                    }
                    resultWord2 = Actor1118_D_8006C704;
                    candidateCursor22 += 0x58;
                    Actor1118Keep(resultWord2);
                    candidateOrOwnerAddress20 += 0x58;
                } while ((unsigned int)candidateCursor22 < (unsigned int)resultWord2);
            }
            selectedOwner8 = originalFrame.spA0;
            if (selectedOwner8 != 0) {
                Actor1118CopyVector(&originalFrame.sp58, selectedOwner8 + 0xC);
                originalFrame.sp60 += 0x200;
                temporaryWord7 = Actor1118PlanarHeadingLookup(
                    originalFrame.sp58 - Actor1118Field(owner18, int*, 0xC),
                    originalFrame.sp5C - Actor1118Field(owner18, int*, 0x10), 0);
                Actor1118Field(owner18, unsigned char*, 0x46) = temporaryWord7;
                Actor1118Field(privateRecord19, int*, 0) =
                    (int)(Actor1118Field((int)&Actor1118_D_80065920, short*,
                                         ((temporaryWord7 & 0xFF) * 2)) *
                          0x7D) >>
                    0xB;
                rawWord3 = Actor1118Field((int)&Actor1118_D_800658A0, short*,
                                          Actor1118Field(owner18, unsigned char*, 0x46) * 2);
                Actor1118Field(privateRecord19, int*, 8) = 0;
                Actor1118Field(privateRecord19, int*, 4) = (int)((int)(rawWord3 * 0x7D) >> 0xB);
                Actor1118Field(privateRecord19, int*, 8) = Actor1118_func_800365E4(
                    owner18 + 0xC, &originalFrame.sp58, 0xFA, -8, &originalFrame.sp68);
            } else {
                argumentWord4 = Actor1118Field((int)&Actor1118_D_80065920, short*,
                                               Actor1118Field(owner18, unsigned char*, 0x46) * 2);
                rawWord3 = Actor1118Field((int)&Actor1118_D_80065920, short*,
                                          Actor1118Field(owner18, unsigned char*, 0x45) * 2);
                resultWord2 = (argumentWord4 * 125) >> 11;
                MATCHING_KEEP2(resultWord2, rawWord3);
                firstCoordinateProduct.full = (long long)resultWord2 * (long long)rawWord3;
                __asm__("" : "=x"(firstCoordinateProduct.full) : "0"(firstCoordinateProduct.full));
                firstCoordinateLow8 = (int)firstCoordinateProduct.words.low;
                Actor1118Keep(firstCoordinateLow8);
                resultWord2 = firstCoordinateLow8 >> 12;
                Actor1118Field(privateRecord19, int*, 0) = resultWord2;
                argumentWord4 = Actor1118Field((int)&Actor1118_D_800658A0, short*,
                                               Actor1118Field(owner18, unsigned char*, 0x46) * 2);
                rawWord3 = Actor1118Field((int)&Actor1118_D_80065920, short*,
                                          Actor1118Field(owner18, unsigned char*, 0x45) * 2);
                resultWord2 = (argumentWord4 * 125) >> 11;
                MATCHING_KEEP2(resultWord2, rawWord3);
                secondCoordinateProduct.full = (long long)resultWord2 * (long long)rawWord3;
                __asm__(""
                        : "=x"(secondCoordinateProduct.full)
                        : "0"(secondCoordinateProduct.full));
                secondCoordinateLow8 = (int)secondCoordinateProduct.words.low;
                Actor1118Keep(secondCoordinateLow8);
                resultWord2 = secondCoordinateLow8 >> 12;
                Actor1118Field(privateRecord19, int*, 4) = resultWord2;
                Actor1118Field(privateRecord19, int*, 8) =
                    (int)((int)(Actor1118Field(
                                    (int)&Actor1118_D_800658A0, short*,
                                    (Actor1118Field(owner18, unsigned char*, 0x45) * 2)) *
                                0x7D) >>
                          0xB);
            }
            Actor1118Field(privateRecord19, short*, 0xC) = 0xC8;
            Actor1118Field(privateRecord19, short*, 0x12) = 1;
            Actor1118Field(privateRecord19, short*, 0xE) = 0;
            Actor1118Field(owner18, unsigned char*, 0x48) = 3U;
            return;
        case 0x50:
            resultWord2 = Actor1118CritterPointer;
            rawWord3 = Actor1118Field(resultWord2, unsigned char*, 0x44);
            retainedWordOrAddress16 = Actor1118Field(resultWord2, int*, 0);
            Actor1118Field(owner18, unsigned char*, 0x44) = rawWord3;
            Actor1118Field(owner18, unsigned char*, 0x45) =
                (unsigned char)((int)Actor1118Field(retainedWordOrAddress16, int*, 0x5C) >> 4);
            resultWord2 = Actor1118CritterPointer;
            Actor1118Keep(resultWord2);
            resultWord2 = Actor1118Field(resultWord2, unsigned char*, 0x46);
            argumentWord5 = 1;
            Actor1118Field(owner18, unsigned char*, 0x46) = resultWord2;
            argumentWord4 = Actor1118CritterPointer;
            Actor1118InterpolateMobyVertex(argumentWord4, argumentWord5, owner18 + 0xC);
            Actor1118RefreshMobySpatialGridAndBasis(owner18, 4);
            argumentWord4 = owner18 + 0x20;
            argumentWord5 = privateRecord19;
            resultWord2 = Actor1118Field(retainedWordOrAddress16, int*, 0x60);
            argumentWord6 = privateRecord19;
            Actor1118Field(privateRecord19, int*, 4) = 0;
            Actor1118Field(privateRecord19, int*, 8) = 0;
            Actor1118Field(privateRecord19, int*, 0) = resultWord2;
            Actor1118TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
            Actor1118Field(privateRecord19, short*, 0xC) = 0xB4;
            Actor1118Field(owner18, unsigned char*, 0x48) = 3U;
        case 0x3:
            if ((Actor1118CountTimerDown(privateRecord19 + 0xC, 2) != 0) ||
                (Actor1118Field(owner18, int*, 0xC) < 0x400) ||
                (Actor1118Field(owner18, int*, 0x10) < 0x400) || ({
                    resultWord2 = Actor1118Field(owner18, int*, 0x14) < 0x400;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(resultWord2, "$16");
                    previousVectorAddress16 = (int)&originalFrame.sp70;
                    resultWord2;
                })) {
            callOriginalDelete:
                Actor1118DeleteMoby(owner18);
                return;
            }
            argumentWord4 = previousVectorAddress16;
            Actor1118Keep(argumentWord4);
            retainedAngleScoreOrAddress17 = owner18 + 0xC;
            Actor1118CopyVector(argumentWord4, retainedAngleScoreOrAddress17);
            Actor1118Field(owner18, int*, 0xC) = (int)(Actor1118Field(owner18, int*, 0xC) +
                                                       Actor1118Field(privateRecord19, int*, 0));
            Actor1118Field(owner18, int*, 0x10) = (int)(Actor1118Field(owner18, int*, 0x10) +
                                                        Actor1118Field(privateRecord19, int*, 4));
            Actor1118Field(owner18, int*, 0x14) = (int)(Actor1118Field(owner18, int*, 0x14) +
                                                        Actor1118Field(privateRecord19, int*, 8));
            Actor1118Field(privateRecord19, int*, 8) =
                (int)(Actor1118Field(privateRecord19, int*, 8) - 8);
            if (Actor1118CountTimerDown(privateRecord19 + 0xE, 2) != 0) {
                if ((Actor1118_func_8001830C(previousVectorAddress16, retainedAngleScoreOrAddress17,
                                             3, 0, 0) != 0) ||
                    (Actor1118_func_80019194(retainedAngleScoreOrAddress17, 0x50) != 0)) {
                    Actor1118PlayMobySoundEvent(owner18, 0, 0);
                    Actor1118Field(privateRecord19, short*, 0xC) = 0xC8;
                    argumentWord4 = privateRecord19;
                    Actor1118Keep(argumentWord4);
                    retainedAngleScoreOrAddress17 = (int)&Actor1118_D_80071918;
                    Actor1118Keep(retainedAngleScoreOrAddress17);
                    if (Actor1118_func_8004EF74(argumentWord4, retainedAngleScoreOrAddress17,
                                                privateRecord19) != 0) {
                        Actor1118ShiftVectorRightTowardZero(privateRecord19, 2);
                    }
                    retainedWordOrAddress16 = 0;
                    if (Actor1118_D_80071920 > 0) {
                        resultWord2 =
                            (int)(Actor1118Field(retainedAngleScoreOrAddress17, int*, 0) * 0x64) /
                            (int)Actor1118_D_80071920;
                        Actor1118Keep(resultWord2);
                        if (resultWord2 < 0) {
                            resultWord2 = -resultWord2;
                        }
                        Actor1118Keep(resultWord2);
                        if (resultWord2 < 6) {
                            resultWord2 =
                                (int)(Actor1118_D_8007191C * 0x64) / (int)Actor1118_D_80071920;
                            Actor1118Keep(resultWord2);
                            if (resultWord2 < 0) {
                                resultWord2 = -resultWord2;
                            }
                            Actor1118Keep(resultWord2);
                            retainedWordOrAddress16 = resultWord2 < 6;
                        }
                    }
                    if (retainedWordOrAddress16 != 0) {
                        Actor1118Field(owner18, unsigned char*, 0x49) = 1U;
                    }
                    if (Actor1118MeasureVectorLength(privateRecord19, 1) < 0x10) {
                        if (retainedWordOrAddress16 != 0) {
                            Actor1118Field(privateRecord19, short*, 0xC) = 0xB4;
                            Actor1118Field(privateRecord19, short*, 0x12) = 0;
                            Actor1118Field(owner18, unsigned char*, 0x48) = 0U;
                            Actor1118Field(owner18, unsigned char*, 0x49) = 0U;
                            originalFrame.sp78 = Actor1118_D_80071908 + 0x37;
                            Actor1118ClearVector(privateRecord19);
                            temporaryWord20 = owner18 + 0xC;
                        } else {
                            Actor1118ScaleVectorRatioQ15(
                                privateRecord19, Actor1118MeasureVectorLength(privateRecord19, 1),
                                0x32);
                            retainedWordOrAddress16 = &originalFrame.sp80;
                            argumentWord4 = retainedWordOrAddress16;
                            Actor1118Keep(argumentWord4);
                            retainedAngleScoreOrAddress17 = (int)&Actor1118_D_80071918;
                            MATCHING_KEEP(retainedAngleScoreOrAddress17);
                            Actor1118CopyVector(argumentWord4, retainedAngleScoreOrAddress17);
                            argumentWord4 = retainedWordOrAddress16;
                            resultWord2 = Actor1118MeasureVectorLength(retainedWordOrAddress16, 1);
                            argumentWord4 = retainedWordOrAddress16;
                            argumentWord5 = resultWord2;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            temporaryWord22 = 0x80;
                            goto scaleOriginalSelectedVector;
                        }
                    } else {
                        retainedWordOrAddress16 = &originalFrame.sp90;
                        argumentWord4 = retainedWordOrAddress16;
                        Actor1118Keep(argumentWord4);
                        retainedAngleScoreOrAddress17 = (int)&Actor1118_D_80071918;
                        MATCHING_KEEP(retainedAngleScoreOrAddress17);
                        Actor1118CopyVector(argumentWord4, retainedAngleScoreOrAddress17);
                        argumentWord4 = retainedWordOrAddress16;
                        resultWord2 = Actor1118MeasureVectorLength(retainedWordOrAddress16, 1);
                        argumentWord4 = retainedWordOrAddress16;
                        argumentWord5 = resultWord2;
                        MATCHING_KEEP2(argumentWord4, argumentWord5);
                        temporaryWord22 = 0x55;
                    scaleOriginalSelectedVector:
                        Actor1118ScaleVectorRatioQ15(argumentWord4, argumentWord5, temporaryWord22);
                        Actor1118AddVector(&originalFrame.sp70,
                                           retainedAngleScoreOrAddress17 - 0x18,
                                           retainedWordOrAddress16);
                        temporaryWord20 = owner18 + 0xC;
                    }
                    Actor1118CopyVector(temporaryWord20, &originalFrame.sp70);
                    temporaryWord21 = owner18 + 0xC;
                    goto runOriginalCommonTail;
                }
                retainedWordOrAddress16 =
                    Actor1118_func_8001BA30(retainedAngleScoreOrAddress17, 0x80, 1, 0, 0, owner18);
                if ((retainedWordOrAddress16 != 0) ||
                    ((temporaryWord21 = owner18 + 0xC,
                      (Actor1118Field(privateRecord19, short*, 0x12) == 0)) &&
                     (Actor1118Field(owner18, unsigned char*, 0x49) == 0) &&
                     ((temporaryWord18 = Actor1118Field(owner18, unsigned char*, 0x3A),
                       (temporaryWord18 == 0xFF)) ||
                      (Actor1118Field(((temporaryWord18 * 0x58) + Actor1118_D_8006C550), short*,
                                      0x36) != 0x63)) &&
                     (temporaryWord21 = owner18 + 0xC,
                      (Actor1118_func_8001C288(retainedAngleScoreOrAddress17, 0x100, 7) != 0)))) {
                    temporaryWord19 = Actor1118Field(owner18, unsigned char*, 0x3A);
                    retainedAngleScoreOrAddress17 = 0;
                    if (temporaryWord19 != 0xFF) {
                        resultWord2 = (temporaryWord19 * 12) - temporaryWord19;
                        Actor1118Keep(resultWord2);
                        rawWord3 = Actor1118_D_8006C550;
                        resultWord2 <<= 3;
                        retainedAngleScoreOrAddress17 = rawWord3 + resultWord2;
                    }
                    if (retainedWordOrAddress16 != 0) {
                        Actor1118Field(retainedWordOrAddress16, int*, 0x18) = 0x140000;
                    } else {
                        MATCHING_BARRIER_VOLATILE("$16");
                        argumentWord6 = 0;
                        Actor1118Field((int)&Actor1118_D_80070328, int*, 0x298) =
                            Actor1118PlanarHeadingLookup(
                                Actor1118Field((int)&Actor1118_D_80070328, int*, 0) -
                                    Actor1118Field(owner18, int*, 0xC),
                                Actor1118Field((int)&Actor1118_D_80070328, int*, 4) -
                                    Actor1118Field(owner18, int*, 0x10),
                                argumentWord6);
                    }
                    Actor1118_func_8001BA30(owner18 + 0xC, 0x5DC, 1, 0, 0x140000,
                                            retainedAngleScoreOrAddress17);
                    temporaryWord24 = 4;
                storeOriginalFinalState:
                    Actor1118Field(owner18, unsigned char*, 0x48) = temporaryWord24;
                    Actor1118Field(privateRecord19, short*, 0xC) = 3;
                    return;
                }
                goto runOriginalCommonTail;
            }
            temporaryWord21 = owner18 + 0xC;
        runOriginalCommonTail:
            Actor1118_func_8001A358(owner18 + 0xC, 0x2000);
            Actor1118_func_8005629C(owner18);
            Actor1118RefreshMobySpatialGridAndBasis(owner18, 2);
            break;
    }
}
#undef Actor1118Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80085FC4.
* AI generated; not human reviewed. Acceptance requires all 656 native and
* linked instructions, five original selector targets, one zero padding
* word, every actual transfer/data target, EXE and every overlay hash.
* Original 0x28 frame is 40 bytes, saving S0..S4/RA; no local frame object.
* Addresses are raw 32-bit byte addresses. All original byte, signed and
* unsigned halfword and word accesses retain their original widths. Fields
* +0x40/+0x50 retain original repeated reads; the nonzero cursor edge at
* original292 skips reload300 and enters301. Loop backedges are exact.
* The two original shift/XOR loops retain 0x8000, 0x8005, eight bit steps,
* and 64-byte bounds. These are instruction constants, not tuned values.
* Linked-list termination reads the current signed halfword before the
* two-byte cursor advance. The only nonnull linked-record producer first
* loads its private record, so the shared consumer never needs incoming S3.
* State one and state three share the original timer-store entry; state
* two preserves both physical range-check entries and counter resets.
* Empty metadata carries complete initialized words or clobbers dead
* registers before fresh producers. It emits zero CPU instructions.
* No opcode asm, incoming saved values, partial products, fixed SP/FP,
* overlapping live aliases or unwritten padding reads. Compiler unchanged.
* Helper views expose original outgoing ABI words; +0x40/+0x50 meanings,
* complete helper/caller/consumer contracts, units, cadence beyond one
* invocation and synchronized runtime captures remain explicit open work.
* Existing mobyutil.c/mobyutil.h and spu.h supply pointer helper contracts;
* 21ED8/21F3C/36220 retain raw argument-word views, without semantic claims.
* Falsification vectors: linked entry 0x8001 reads index1 and terminates
* after the current record; original292 nonzero enters301, zero enters294.
* Confidence is binary identity after all gates, not runtime parity.
* Engine/browser unchanged. Next: human review and synchronized retail
* capture with the complete producer-to-consumer and unit evidence chain.
*/
/* Original assembly SHA256 02b5f98c82ba5f9facc14df40983204b335bd380d25c5ea224e6c04549f78da3 */
#define Level43_85FC4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level43_85FC4Call21ED8View1(int, int, int) __asm__("func_80021ED8");
int Level43_85FC4Call21F3CView1(int) __asm__("func_80021F3C");
void Level43_85FC4SetMobyAnimationView1(void*, int) __asm__("func_80034F80");
int Level43_85FC4CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level43_85FC4Call36220View1(int, int, int, int) __asm__("func_80036220");
int Level43_85FC4Call3BB10View1(void*, int, int) __asm__("func_8003BB10");
extern int Level43_85FC4Data6580CView1 __asm__("D_8006580C");
extern int Level43_85FC4Data65834View1 __asm__("D_80065834");
extern int Level43_85FC4Data6C550View1 __asm__("D_8006C550");
extern int Level43_85FC4Data6C58CView1 __asm__("D_8006C58C");
extern int Level43_85FC4Data6C640View1 __asm__("D_8006C640");
extern int Level43_85FC4Data6C730View1 __asm__("D_8006C730");
extern unsigned char Level43_85FC4Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Level43_85FC4Data70300View1 __asm__("D_80070300");
extern unsigned char Level43_85FC4Data70328View1 __asm__("D_80070328");
extern unsigned char Level43_85FC4Data96464View1 __asm__("D_level_43_80096464");
extern unsigned char Level43_85FC4Data7584CView1 __asm__("func_level_43_8007584C");
extern unsigned char Level43_85FC4Datamain_TEXT_ENDView1 __asm__("main_TEXT_END");
extern unsigned char Level43_85FC4Datamain_TEXT_STARTView1 __asm__("main_TEXT_START");
void func_level_43_80085FC4(void* ownerParameter) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int argumentOrCount4 __asm__("$4");
    register int argumentOrByteCount5 __asm__("$5");
    register int argumentOrEndAddress6 __asm__("$6");
    register int comparisonAddress7 __asm__("$7");
    register int linkedRecordAddress8 __asm__("$8");
    register int signedListCursor9 __asm__("$9");
    register int listEntryCount10 __asm__("$10");
    register int mobyArrayBase11 __asm__("$11");
    register void* owner20 __asm__("$20");
    register int recordCursorOrCount16 __asm__("$16");
    register int linkedRecordOrCount17 __asm__("$17");
    register int privateRecord18 __asm__("$18");
    register int linkedPrivateOrCursor19 __asm__("$19");
    owner20 = ownerParameter;
    MATCHING_KEEP(owner20);
    privateRecord18 = Level43_85FC4Field(owner20, int**, 0);
    Level43_85FC4Field(owner20, unsigned char*, 0x4A) = 0xFF;
    linkedRecordOrCount17 = 0;
    if ((unsigned int)Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) >=
        (unsigned int)(int)&Level43_85FC4Data7584CView1) {
        argumentOrByteCount5 = 0;
        argumentOrEndAddress6 = (int)&Level43_85FC4Data96464View1;
        MATCHING_KEEP(argumentOrEndAddress6);
    repeatOriginalOverlayBytes:
        rawWord3 = Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40);
        if ((unsigned)rawWord3 < (unsigned)argumentOrEndAddress6) {
            argumentOrCount4 = 0;
            Level43_85FC4Field(privateRecord18, volatile int*, 0x50) =
                (int)(Level43_85FC4Field(privateRecord18, volatile int*, 0x50) ^
                      (Level43_85FC4Field(rawWord3, unsigned char*, 0) << 8));
            do {
                rawWord3 = Level43_85FC4Field(privateRecord18, volatile int*, 0x50);
                rawWord2 = rawWord3 & 0x8000;
                if (rawWord2) {
                    rawWord2 = rawWord3 << 1;
                    rawWord2 ^= 0x8005;
                } else {
                    rawWord2 = rawWord3 << 1;
                }
                Level43_85FC4Field(privateRecord18, volatile int*, 0x50) = rawWord2;
                argumentOrCount4 += 1;
            } while (argumentOrCount4 < 8);
            argumentOrByteCount5 += 1;
            Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) =
                (unsigned int)(Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) +
                               1);
            if (argumentOrByteCount5 < 0x40) {
                goto repeatOriginalOverlayBytes;
            }
        }
    }
    if ((Level43_85FC4Data6C7B4View1 & 1) ||
        (Level43_85FC4Field((int)&Level43_85FC4Data70300View1 + Level43_85FC4Data6C58CView1,
                            unsigned char*, 0) &
         1)) {
        if (Level43_85FC4Field(owner20, unsigned char*, 0x48) != 2) {
            linkedRecordOrCount17 = 0;
            if (Level43_85FC4Field(owner20, unsigned char*, 0x3D) != 0) {
                Level43_85FC4Call3BB10View1(owner20, 4, 0);
                Level43_85FC4SetMobyAnimationView1(owner20, 0);
            }
            recordCursorOrCount16 = privateRecord18;
            do {
                argumentOrCount4 = Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                if (argumentOrCount4 >= 0) {
                    rawWord3 = Level43_85FC4Call21F3CView1(argumentOrCount4);
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = rawWord3 >> 8;
                    MATCHING_KEEP(rawWord2);
                    argumentOrCount4 = rawWord2 & 255;
                    rawWord2 = rawWord3 & 0xF;
                    if (argumentOrCount4 == 0) {
                        if (rawWord2 != 0) {
                            argumentOrCount4 = Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                            argumentOrByteCount5 = 252;
                            argumentOrEndAddress6 = 0;
                            MATCHING_OBSERVE3_VOLATILE(argumentOrCount4, argumentOrByteCount5,
                                                       argumentOrEndAddress6);
                            linkedRecordOrCount17++;
                            Level43_85FC4Call21ED8View1(argumentOrCount4, argumentOrByteCount5,
                                                        argumentOrEndAddress6);
                        } else {
                            goto checkOriginalFirstStatusByte;
                        }
                    } else if (rawWord2 == 0) {
                    checkOriginalFirstStatusByte:
                        if (({
                                rawWord2 = argumentOrCount4 < 60;
                                MATCHING_KEEP(rawWord2);
                                rawWord2;
                            }) &&
                            !({
                                rawWord2 = rawWord3 & 15;
                                MATCHING_KEEP(rawWord2);
                                rawWord2;
                            })) {
                            goto countOriginalFirstRecord;
                        }
                    } else {
                        goto countOriginalFirstRecord;
                    }
                } else {
                countOriginalFirstRecord:
                    linkedRecordOrCount17 += 1;
                }
                rawWord3 = Level43_85FC4Field(recordCursorOrCount16, int*, 0x44);
                if (rawWord3 >= 0) {
                    Level43_85FC4Field(((rawWord3 * 0x58) + Level43_85FC4Data6C550View1),
                                       signed char*, 0x48) = 1;
                }
                recordCursorOrCount16 += 4;
            } while ((int)recordCursorOrCount16 < (int)(privateRecord18 + 0xC));
            recordCursorOrCount16 = 3;
            MATCHING_KEEP(recordCursorOrCount16);
            if (linkedRecordOrCount17 == recordCursorOrCount16) {
                Level43_85FC4Field(owner20, unsigned char*, 0x48) = 2U;
            }
        }
        if ((Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) ==
             (int)&Level43_85FC4Data96464View1) &&
            (Level43_85FC4Field(privateRecord18, volatile int*, 0x50) != 0)) {
            rawWord2 = 1;
            MATCHING_KEEP(rawWord2);
            Level43_85FC4Data6580CView1 = rawWord2;
            Level43_85FC4Data65834View1 = rawWord2;
            Level43_85FC4Field(privateRecord18, int*, 0x50) = 0;
        }
    } else {
        if (Level43_85FC4Field(&Level43_85FC4Data70328View1, int*, 0x13C) == owner20) {
            if (Level43_85FC4Field(owner20, unsigned char*, 0x48) != 0) {
                Level43_85FC4Call3BB10View1(owner20, 4, 0);
            }
            Level43_85FC4Field(owner20, unsigned char*, 0x48) = 0U;
            Level43_85FC4SetMobyAnimationView1(owner20, 0);
            if (Level43_85FC4Field(owner20, unsigned char*, 0x49) == 0) {
                signedListCursor9 =
                    Level43_85FC4Field((Level43_85FC4Field(owner20, unsigned char*, 0x43) * 4) +
                                           Level43_85FC4Data6C730View1,
                                       int*, 0);
                __asm__ volatile(""
                                 : "=r"(linkedRecordOrCount17)
                                 : "0"(linkedRecordOrCount17)
                                 : "$10", "memory");
                listEntryCount10 = 0;
                if (linkedRecordOrCount17 == 0) {
                    mobyArrayBase11 = Level43_85FC4Data6C550View1;
                    MATCHING_KEEP(mobyArrayBase11);
                repeatOriginalLinkedEntries:
                    rawWord2 = Level43_85FC4Field(signedListCursor9, unsigned short*, 0);
                    rawWord2 &= 0x7fff;
                    MATCHING_KEEP(rawWord2);
                    rawWord3 = rawWord2 * 0x58;
                    linkedRecordAddress8 = mobyArrayBase11 + rawWord3;
                    MATCHING_KEEP(linkedRecordAddress8);
                    if (Level43_85FC4Field(linkedRecordAddress8, unsigned char*, 0x49) != 0) {
                        linkedPrivateOrCursor19 =
                            Level43_85FC4Field(linkedRecordAddress8, int**, 0);
                        recordCursorOrCount16 = 0;
                        if (linkedRecordOrCount17 == 0) {
                            argumentOrEndAddress6 = privateRecord18;
                        repeatOriginalPrivateRecords:
                            if (Level43_85FC4Field(argumentOrEndAddress6, int*, 0) >= 0) {
                                argumentOrByteCount5 = 0;
                                comparisonAddress7 = argumentOrEndAddress6;
                                MATCHING_KEEP(comparisonAddress7);
                                argumentOrCount4 = linkedPrivateOrCursor19;
                            repeatOriginalLinkedRecords:
                                rawWord3 = Level43_85FC4Field(argumentOrCount4, int*, 0);
                                if ((rawWord3 >= 0) &&
                                    (Level43_85FC4Field(comparisonAddress7, int*, 0) == rawWord3)) {
                                    linkedRecordOrCount17 = linkedRecordAddress8;
                                } else {
                                    argumentOrByteCount5 += 1;
                                    argumentOrCount4 += 4;
                                    if (argumentOrByteCount5 < 3) {
                                        goto repeatOriginalLinkedRecords;
                                    }
                                }
                            }
                            recordCursorOrCount16 += 1;
                            argumentOrEndAddress6 += 4;
                            if ((recordCursorOrCount16 < 3) && (linkedRecordOrCount17 == 0)) {
                                goto repeatOriginalPrivateRecords;
                            }
                        }
                    }
                    rawWord2 = Level43_85FC4Field(signedListCursor9, short*, 0);
                    signedListCursor9 += 2;
                    if (rawWord2 >= 0) {
                        listEntryCount10 += 1;
                        if ((listEntryCount10 < 0xA) && (linkedRecordOrCount17 == 0)) {
                            goto repeatOriginalLinkedEntries;
                        }
                    }
                    if (linkedRecordOrCount17 != 0) {
                        goto copyOriginalLinkedState;
                    }
                } else {
                copyOriginalLinkedState:
                    Level43_85FC4Field(owner20, unsigned char*, 0x49) =
                        (unsigned char)Level43_85FC4Field(linkedRecordOrCount17, unsigned char*,
                                                          0x49);
                    Level43_85FC4Field(privateRecord18, unsigned short*, 0xE) =
                        (unsigned short)Level43_85FC4Field(linkedPrivateOrCursor19, unsigned short*,
                                                           0xE);
                    Level43_85FC4Field(linkedPrivateOrCursor19, unsigned short*, 0xE) = 0U;
                    Level43_85FC4Field(linkedRecordOrCount17, unsigned char*, 0x49) = 0U;
                }
            }
        } else {
            if (Level43_85FC4Field(owner20, unsigned char*, 0x48) != 1) {
                if (Level43_85FC4Data6C640View1 > 0) {
                    Level43_85FC4Call3BB10View1(owner20, 5, 0);
                }
            }
            Level43_85FC4Field(owner20, unsigned char*, 0x48) = 1U;
            Level43_85FC4SetMobyAnimationView1(owner20, 1);
        }
        if ((Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) ==
             (int)&Level43_85FC4Data96464View1) &&
            (Level43_85FC4Field(privateRecord18, volatile int*, 0x50) != 0)) {
            Level43_85FC4Field((int)&Level43_85FC4Data70300View1, signed char*, 6) = 0;
            Level43_85FC4Field((int)&Level43_85FC4Data70300View1, signed char*, 0xF) = 0;
            Level43_85FC4Field((int)&Level43_85FC4Data70300View1, signed char*, 0x18) = 0;
            Level43_85FC4Field((int)&Level43_85FC4Data70300View1, signed char*, 0x21) = 0;
            Level43_85FC4Field(privateRecord18, volatile int*, 0x50) = 0;
        }
        rawWord3 = Level43_85FC4Field(owner20, unsigned char*, 0x49);
        switch (rawWord3) {
            case 0:
                if (Level43_85FC4Field(owner20, int*, 0x10) < 0x7530) {
                    rawWord2 = Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40);
                    if (rawWord2 == 0) {
                        Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) =
                            (unsigned int)(Level43_85FC4Data6C58CView1 +
                                           ((int)&Level43_85FC4Datamain_TEXT_STARTView1 + 2));
                        rawWord2 =
                            Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40);
                    }
                    rawWord3 = (int)&Level43_85FC4Datamain_TEXT_ENDView1;
                    if ((unsigned)rawWord2 < (unsigned)rawWord3) {
                        argumentOrByteCount5 = 0;
                        argumentOrEndAddress6 = rawWord3;
                    repeatOriginalExecutableBytes:
                        rawWord3 =
                            Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40);
                        if ((unsigned)rawWord3 < (unsigned)argumentOrEndAddress6) {
                            argumentOrCount4 = 0;
                            Level43_85FC4Field(privateRecord18, volatile int*, 0x50) =
                                (int)(Level43_85FC4Field(privateRecord18, volatile int*, 0x50) ^
                                      (Level43_85FC4Field(rawWord3, unsigned char*, 0) << 8));
                            do {
                                rawWord3 = Level43_85FC4Field(privateRecord18, volatile int*, 0x50);
                                rawWord2 = rawWord3 & 0x8000;
                                if (rawWord2) {
                                    rawWord2 = rawWord3 << 1;
                                    rawWord2 ^= 0x8005;
                                } else {
                                    rawWord2 = rawWord3 << 1;
                                }
                                Level43_85FC4Field(privateRecord18, volatile int*, 0x50) = rawWord2;
                                argumentOrCount4 += 1;
                            } while (argumentOrCount4 < 8);
                            argumentOrByteCount5 += 1;
                            rawWord2 = Level43_85FC4Field(privateRecord18, volatile int*, 0x50);
                            rawWord3 =
                                Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40);
                            rawWord2 &= 3;
                            rawWord2++;
                            rawWord3 += rawWord2;
                            Level43_85FC4Field(privateRecord18, unsigned int*, 0x40) = rawWord3;
                            if (argumentOrByteCount5 >= 0x40) {
                                if (({
                                        rawWord2 =
                                            (unsigned)rawWord3 <
                                            (unsigned)(int)&Level43_85FC4Datamain_TEXT_ENDView1;
                                        MATCHING_KEEP(rawWord2);
                                        !rawWord2;
                                    })) {
                                    goto startOriginalOverlayRange;
                                }
                            } else {
                                goto repeatOriginalExecutableBytes;
                            }
                        } else {
                        startOriginalOverlayRange:
                            Level43_85FC4Field(privateRecord18, volatile unsigned int*, 0x40) =
                                (unsigned int)(int)&Level43_85FC4Data7584CView1;
                        }
                    }
                }
                linkedRecordOrCount17 = 0;
                if (Level43_85FC4Field(owner20, unsigned char*, 0x48) == 0) {
                    recordCursorOrCount16 = privateRecord18;
                    do {
                        argumentOrCount4 = Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                        if (argumentOrCount4 >= 0) {
                            rawWord3 = Level43_85FC4Call21F3CView1(argumentOrCount4);
                            MATCHING_KEEP(rawWord3);
                            rawWord2 = rawWord3 >> 8;
                            MATCHING_KEEP(rawWord2);
                            argumentOrCount4 = rawWord2 & 255;
                            rawWord2 = rawWord3 & 0xF;
                            if (argumentOrCount4 == 0) {
                                if (rawWord2 != 0) {
                                    argumentOrCount4 =
                                        Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                                    argumentOrByteCount5 = 252;
                                    argumentOrEndAddress6 = 0;
                                    MATCHING_OBSERVE3_VOLATILE(argumentOrCount4,
                                                               argumentOrByteCount5,
                                                               argumentOrEndAddress6);
                                    linkedRecordOrCount17++;
                                    Level43_85FC4Call21ED8View1(argumentOrCount4,
                                                                argumentOrByteCount5,
                                                                argumentOrEndAddress6);
                                } else {
                                    goto checkOriginalStateZeroStatusByte;
                                }
                            } else if (rawWord2 == 0) {
                            checkOriginalStateZeroStatusByte:
                                if (({
                                        rawWord2 = argumentOrCount4 < 60;
                                        MATCHING_KEEP(rawWord2);
                                        rawWord2;
                                    }) &&
                                    !({
                                        rawWord2 = rawWord3 & 15;
                                        MATCHING_KEEP(rawWord2);
                                        rawWord2;
                                    })) {
                                    goto countOriginalStateZeroRecord;
                                }
                            } else {
                                goto countOriginalStateZeroRecord;
                            }
                        } else {
                        countOriginalStateZeroRecord:
                            linkedRecordOrCount17 += 1;
                        }
                        rawWord3 = Level43_85FC4Field(recordCursorOrCount16, int*, 0x44);
                        if (rawWord3 >= 0) {
                            Level43_85FC4Field(((rawWord3 * 0x58) + Level43_85FC4Data6C550View1),
                                               signed char*, 0x48) = 1;
                        }
                        recordCursorOrCount16 += 4;
                    } while ((int)recordCursorOrCount16 < (int)(privateRecord18 + 0xC));
                    recordCursorOrCount16 = 3;
                    MATCHING_KEEP(recordCursorOrCount16);
                    if (linkedRecordOrCount17 == recordCursorOrCount16) {
                        Level43_85FC4Field(owner20, unsigned char*, 0x49) = 1U;
                        return;
                    }
                } else {
                    default:
                        return;
                }
                break;
            case 1:
                linkedRecordOrCount17 = 0;
                recordCursorOrCount16 = 0;
                linkedPrivateOrCursor19 = privateRecord18;
                do {
                    argumentOrCount4 = Level43_85FC4Field(linkedPrivateOrCursor19, int*, 0);
                    if (argumentOrCount4 < 0)
                        goto countCaseOne;
                    rawWord3 = Level43_85FC4Call21F3CView1(argumentOrCount4);
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = rawWord3 >> 8;
                    MATCHING_KEEP(rawWord2);
                    argumentOrCount4 = rawWord2 & 255;
                    if (argumentOrCount4 != 0) {
                        rawWord2 = rawWord3 & 15;
                        if (rawWord2) {
                        countCaseOne:
                            linkedRecordOrCount17++;
                        }
                    }
                    recordCursorOrCount16++;
                    linkedPrivateOrCursor19 += 4;
                } while (recordCursorOrCount16 < 3);
                rawWord2 = 3;
                MATCHING_KEEP(rawWord2);
                if (linkedRecordOrCount17 != rawWord2)
                    goto originalFinish;
                rawWord2 = 3;
                Level43_85FC4Field(owner20, unsigned char*, 73) = rawWord2;
                goto originalTimerStore;
            case 3:
                rawWord2 = Level43_85FC4Field(owner20, unsigned char*, 72);
                argumentOrCount4 = privateRecord18 + 14;
                if (rawWord2)
                    goto originalTimerCall;
            originalTimerStore:
                rawWord3 = Level43_85FC4Field(privateRecord18, short*, 12);
                rawWord2 = rawWord3 * 60;
                Level43_85FC4Field(privateRecord18, unsigned short*, 14) = rawWord2;
                goto originalFinish;
            originalTimerCall:
                rawWord2 = Level43_85FC4CountTimerDownView1((void*)argumentOrCount4, 2);
                linkedRecordOrCount17 = 0;
                if (rawWord2 != 0) {
                    recordCursorOrCount16 = privateRecord18;
                    do {
                        argumentOrCount4 = Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                        if (argumentOrCount4 >= 0) {
                            rawWord3 = Level43_85FC4Call21F3CView1(argumentOrCount4);
                            MATCHING_KEEP(rawWord3);
                            rawWord2 = rawWord3 >> 8;
                            MATCHING_KEEP(rawWord2);
                            argumentOrCount4 = rawWord2 & 255;
                            rawWord2 = rawWord3 & 0xF;
                            if (argumentOrCount4 != 0) {
                                if (rawWord2 != 0) {
                                    argumentOrCount4 =
                                        Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                                    argumentOrByteCount5 = 252;
                                    argumentOrEndAddress6 = 0;
                                    MATCHING_OBSERVE3_VOLATILE(argumentOrCount4,
                                                               argumentOrByteCount5,
                                                               argumentOrEndAddress6);
                                    linkedRecordOrCount17++;
                                    Level43_85FC4Call21ED8View1(argumentOrCount4,
                                                                argumentOrByteCount5,
                                                                argumentOrEndAddress6);
                                } else {
                                    goto checkOriginalStateThreeStatusByte;
                                }
                            } else if (rawWord2 == 0) {
                            checkOriginalStateThreeStatusByte:
                                if (({
                                        rawWord2 = argumentOrCount4 < 61;
                                        MATCHING_KEEP(rawWord2);
                                        !rawWord2;
                                    }) &&
                                    !({
                                        rawWord2 = rawWord3 & 15;
                                        MATCHING_KEEP(rawWord2);
                                        rawWord2;
                                    })) {
                                    goto countOriginalStateThreeRecord;
                                }
                            } else {
                                goto countOriginalStateThreeRecord;
                            }
                        } else {
                        countOriginalStateThreeRecord:
                            linkedRecordOrCount17 += 1;
                        }
                        rawWord3 = Level43_85FC4Field(recordCursorOrCount16, int*, 0x44);
                        if (rawWord3 >= 0) {
                            Level43_85FC4Field(((rawWord3 * 0x58) + Level43_85FC4Data6C550View1),
                                               signed char*, 0x48) = 1;
                        }
                        recordCursorOrCount16 += 4;
                    } while ((int)recordCursorOrCount16 < (int)(privateRecord18 + 0xC));
                    recordCursorOrCount16 = 3;
                    MATCHING_KEEP(recordCursorOrCount16);
                    if (linkedRecordOrCount17 == recordCursorOrCount16) {
                        Level43_85FC4Field(owner20, unsigned char*, 0x49) = 2U;
                        return;
                    }
                }
                break;
            case 4:
                if ((Level43_85FC4Call36220View1(&Level43_85FC4Data70328View1,
                                                 privateRecord18 + 0x10, 0, 0x2800) == 0) &&
                    (Level43_85FC4Call36220View1(&Level43_85FC4Data70328View1,
                                                 privateRecord18 + 0x28, 0, 0x2800) == 0)) {
                    Level43_85FC4Field(owner20, unsigned char*, 0x49) = 2U;
                    recordCursorOrCount16 = privateRecord18;
                repeatOriginalStateFourRecords:
                    argumentOrCount4 = Level43_85FC4Field(recordCursorOrCount16, int*, 0);
                    if (argumentOrCount4 >= 0) {
                        rawWord3 = Level43_85FC4Call21F3CView1(argumentOrCount4);
                        MATCHING_KEEP(rawWord3);
                        rawWord2 = rawWord3 >> 8;
                        MATCHING_KEEP(rawWord2);
                        argumentOrCount4 = rawWord2 & 255;
                        rawWord2 = 60;
                        MATCHING_KEEP(rawWord2);
                        if (argumentOrCount4 != rawWord2 && rawWord3 != 0 && ({
                                rawWord2 = rawWord3 & 15;
                                MATCHING_KEEP(rawWord2);
                                rawWord2;
                            })) {
                            Level43_85FC4Call21ED8View1(
                                Level43_85FC4Field(recordCursorOrCount16, int*, 0), 0xFC, 0);
                        }
                    }
                    rawWord3 = Level43_85FC4Field(recordCursorOrCount16, int*, 0x44);
                    if (rawWord3 >= 0) {
                        Level43_85FC4Field(((rawWord3 * 0x58) + Level43_85FC4Data6C550View1),
                                           signed char*, 0x48) = 1;
                    }
                    recordCursorOrCount16 += 4;
                    if ((int)recordCursorOrCount16 < (int)(privateRecord18 + 0xC)) {
                        goto repeatOriginalStateFourRecords;
                    }
                }
                break;
            case 2:
                linkedRecordOrCount17 = 0;
                MATCHING_KEEP(linkedRecordOrCount17);
                recordCursorOrCount16 = (int)&Level43_85FC4Data70328View1;
                MATCHING_KEEP(recordCursorOrCount16);
                rawWord2 = Level43_85FC4Call36220View1(recordCursorOrCount16,
                                                       privateRecord18 + 0x10, 0, 0x2800);
                if (rawWord2)
                    goto activateCaseTwo;
                argumentOrCount4 = recordCursorOrCount16;
                MATCHING_BARRIER_VOLATILE("$2");
                rawWord2 = Level43_85FC4Call36220View1(argumentOrCount4, privateRecord18 + 0x28, 0,
                                                       0x2800);
                recordCursorOrCount16 = 0;
                if (rawWord2 == 0)
                    goto countCaseTwoStart;
                {
                activateCaseTwo:
                    recordCursorOrCount16 = 0;
                    linkedRecordOrCount17 = privateRecord18;
                    do {
                        argumentOrCount4 = Level43_85FC4Field(linkedRecordOrCount17, int*, 0);
                        if ((argumentOrCount4 >= 0) &&
                            !(Level43_85FC4Call21F3CView1(argumentOrCount4) & 0xF)) {
                            Level43_85FC4Call21ED8View1(
                                Level43_85FC4Field(linkedRecordOrCount17, int*, 0), 0xFC, 2);
                        }
                        recordCursorOrCount16 += 1;
                        linkedRecordOrCount17 += 4;
                    } while (recordCursorOrCount16 < 3);
                    recordCursorOrCount16 = 0;
                    argumentOrByteCount5 = 2;
                    MATCHING_KEEP(argumentOrByteCount5);
                    argumentOrCount4 = privateRecord18;
                    do {
                        rawWord3 = Level43_85FC4Field(argumentOrCount4, int*, 0x44);
                        if (rawWord3 >= 0) {
                            Level43_85FC4Field(((rawWord3 * 0x58) + Level43_85FC4Data6C550View1),
                                               signed char*, 0x48) = argumentOrByteCount5;
                        }
                        recordCursorOrCount16 += 1;
                        argumentOrCount4 += 4;
                    } while (recordCursorOrCount16 < 3);
                    Level43_85FC4Field(owner20, unsigned char*, 0x49) = 4U;
                    return;
                }
            countCaseTwoStart:
                __asm__ volatile("" ::: "$19", "memory");
                linkedPrivateOrCursor19 = privateRecord18;
                MATCHING_KEEP(linkedPrivateOrCursor19);
                do {
                    argumentOrCount4 = Level43_85FC4Field(linkedPrivateOrCursor19, int*, 0);
                    if (argumentOrCount4 < 0)
                        goto countCaseTwo;
                    rawWord3 = Level43_85FC4Call21F3CView1(argumentOrCount4);
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = rawWord3 >> 8;
                    MATCHING_KEEP(rawWord2);
                    argumentOrCount4 = rawWord2 & 255;
                    if (argumentOrCount4 == 0) {
                        rawWord2 = rawWord3 & 15;
                        if (rawWord2) {
                        countCaseTwo:
                            linkedRecordOrCount17++;
                        }
                    }
                    recordCursorOrCount16 += 1;
                    linkedPrivateOrCursor19 += 4;
                } while (recordCursorOrCount16 < 3);
                rawWord2 = 3;
                if (linkedRecordOrCount17 == rawWord2) {
                    recordCursorOrCount16 = 0;
                    Level43_85FC4Field(owner20, unsigned char*, 0x49) = 0U;
                    argumentOrByteCount5 = 2;
                    MATCHING_KEEP(argumentOrByteCount5);
                    argumentOrCount4 = privateRecord18;
                    do {
                        rawWord3 = Level43_85FC4Field(argumentOrCount4, int*, 0x44);
                        if (rawWord3 >= 0) {
                            Level43_85FC4Field(((rawWord3 * 0x58) + Level43_85FC4Data6C550View1),
                                               signed char*, 0x48) = argumentOrByteCount5;
                        }
                        recordCursorOrCount16 += 1;
                        argumentOrCount4 += 4;
                    } while (recordCursorOrCount16 < 3);
                }
                break;
        }
    }
originalFinish:;
}
#undef Level43_85FC4Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80086A04.
* Assembly SHA256 99d58f06795c76fd2574e574483d93367dfc97318f632a5e307cfddf06ce5e5b.
* AI generated; not human reviewed. All818 original instructions and six
* original selector words/actual targets are required. Frame0xA0 retains
* original S0/S1/S2/S3/RA saves and SP0x20/30/40 vector addresses, with
* original unused local extent retained without invented memory reads.
* State6 precedes the original0..5 table; shared tail stays at80087170.
* Original LHU at owner+0x3C, signed16 truncations, LH trig selectors,
* raw products75/225, shifts9, color steps25/10, duplicated vector stores
* and all shared clamp/copy joins remain exact. These are raw instruction
* operations, not assertions about semantic units, gain or update timing.
* The terminal nine-iteration loop defines the complete signed64 product
* index*0x55555556. In this exact function, the frozen pipeline selects
* original MFHI from the first union field. Standalone constant/multiply
* probes behave differently: no universal field-layout rule is claimed.
* This context-specific compilation workaround is checked against every
* original/native loop word and13 signed arithmetic/register/stack-argument
* vectors. Pipeline root cause and portability remain open. Both product
* halves are initialized by ordinary C. No
* HI/LO constraint, partial HI, FP shortcut or opcode assembly is used.
* Subtracting index>>31 reconstructs original signed quotient; both call
* arguments retain index-quotient*3+3. Initialized empty dependencies
* emit0 instructions. Late input-only consumers retain original address
* producers in available load slots. Immediate tags are scheduling IDs,
* not retail addresses or semantic evidence. Full helper contracts,
* units/fixed point, caller cadence and synchronized runtime remain open.
* Cadence here is per invocation; confidence is binary identity only
* after all gates. Falsification: every native/linked word, actual target,
* selector/padding byte, full EXE/every-overlay hash and signed-product
* vectors must match. */
#define Actor43_86A04Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor43_86A04Call19138View1() __asm__("func_80019138");
unsigned char Actor43_86A04Call1A310View1() __asm__("func_8001A310");
int Actor43_86A04Call1A358View1() __asm__("func_8001A358");
unsigned char Actor43_86A04RequestMobyAnimationView1() __asm__("func_80034F40");
unsigned char Actor43_86A04SetMobyAnimationView1() __asm__("func_80034F80");
int Actor43_86A04CountTimerDownView1() __asm__("func_800359A4");
unsigned char Actor43_86A04Call35EE0View1() __asm__("func_80035EE0");
unsigned char Actor43_86A04Call369B8View1() __asm__("func_800369B8");
void* Actor43_86A04Call391E8View1() __asm__("func_800391E8");
int Actor43_86A04Call39714View1() __asm__("func_80039714");
int Actor43_86A04PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor43_86A04Call3BFC0View1() __asm__("func_8003BFC0");
unsigned char Actor43_86A04Call3C0B0View1() __asm__("func_8003C0B0");
unsigned char Actor43_86A04Call3C140View1() __asm__("func_8003C140");
int Actor43_86A04PlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor43_86A04CopyVectorView1() __asm__("func_8004F178");
unsigned char Actor43_86A04AddVectorView1() __asm__("func_8004F194");
unsigned char Actor43_86A04DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor43_86A04RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor43_86A04Call55E84View1() __asm__("func_80055E84");
unsigned char Actor43_86A04Call5629CView1() __asm__("func_8005629C");
int Actor43_86A04CallrandView1() __asm__("rand");
extern unsigned char Actor43_86A04Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor43_86A04Data65920View1 __asm__("D_80065920");
extern unsigned char Actor43_86A04Data676E8View1 __asm__("D_800676E8");
extern int Actor43_86A04Data6C58CView1 __asm__("D_8006C58C");
extern int Actor43_86A04Data6C5C8View1 __asm__("D_8006C5C8");
extern int Actor43_86A04Data6C770View1 __asm__("D_8006C770");
extern int Actor43_86A04Data6E020View1 __asm__("D_8006E020");
extern int Actor43_86A04Data6E024View1 __asm__("D_8006E024");
extern int Actor43_86A04Data6E160View1 __asm__("D_8006E160");
extern int Actor43_86A04Data6E538View1 __asm__("D_8006E538");
extern unsigned char Actor43_86A04Data70328View1 __asm__("D_80070328");
extern void* (*Actor43_86A04DataSpawnMobyView1)() __asm__("SpawnMoby");
extern void* (*Actor43_86A04DataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_43_80086A04(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int offsetIndexOrVectorAddress16 __asm__("$16"),
        privateOrDivisionMagic18 __asm__("$18"), heightPrivateOrConstant19 __asm__("$19");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        rawTrigWord8 __asm__("$8"), originalHeightWord9 __asm__("$9");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
        char retained50[56];
    } originalFrame;
    unsigned char temporaryWord11;
    short temporaryWord1;
    short temporaryWord2;
    short temporaryWord3;
    short temporaryWord4;
    short temporaryWord6;
    int temporaryWord7;
    union {
        long long wide;
        struct {
            int high;
            unsigned int low;
        } words;
    } completeSignedProduct;
    int signedQuotient, signedInputCorrection;
    int productHighWord;
    unsigned int productLowWord;
    unsigned short temporaryWord9;
    register int temporaryWord8 __asm__("$3");
    int temporaryWord10;
    void* temporaryPointer5;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    rawWord2 = 6;
    temporaryWord8 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x48);
    privateOrDivisionMagic18 = Actor43_86A04Field(ownerRecord17, void**, 0);
    MATCHING_KEEP(temporaryWord8);
    if (temporaryWord8 != rawWord2)
        goto dispatchStateTable;
    {
        if (Actor43_86A04Call39714View1() != 0) {
            Actor43_86A04RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
            Actor43_86A04Call369B8View1(ownerRecord17, 0x20);
            Actor43_86A04DataSpawnParticleView1(8, 0x46, ownerRecord17 + 0xC, (int*)0x10);
            return;
        }
        return;
    }
dispatchStateTable:
    rawWord2 = (unsigned int)temporaryWord8 < 6;
    if (!rawWord2)
        goto runSharedTail;
    switch (rawWord2 = temporaryWord8) {
        case 0:
            MATCHING_OBSERVE_GNU_VOLATILE(temporaryWord8);
            Actor43_86A04CopyVectorView1(&originalFrame.sp20, ownerRecord17 + 0xC);
            Actor43_86A04Field(ownerRecord17, int*, 0x14) =
                (int)(Actor43_86A04Field(ownerRecord17, int*, 0x14) + 0x400);
            originalFrame.sp28 += 0x384;
            Actor43_86A04Field(ownerRecord17, int*, 0x14) =
                (int)(Actor43_86A04Call1A358View1(&originalFrame.sp20, 0x1000) + 0x200);
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x48) = 1U;
            goto runSharedTail;
        case 5:
            Actor43_86A04CopyVectorView1(ownerRecord17 + 0xC, privateOrDivisionMagic18 + 0x18);
            rawWord2 = Actor43_86A04Field(ownerRecord17, int*, 0x14);
            argumentWord5 = 0;
            rawWord2 += 512;
            Actor43_86A04Field(ownerRecord17, int*, 0x14) = rawWord2;
            rawWord3 = Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x2C);
            rawWord2 = 1;
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x46) = rawWord3;
            Actor43_86A04SetMobyAnimationView1(ownerRecord17, argumentWord5);
            Actor43_86A04RefreshMobySpatialGridAndBasisView1(ownerRecord17, 6);
            goto runSharedTail;
        case 2:
            Actor43_86A04Field(&Actor43_86A04Data70328View1, int*, 0x20C) = 0x10000002;
            if (Actor43_86A04Data6E160View1 == 0) {
                Actor43_86A04Field(&Actor43_86A04Data70328View1, int*, 0x20C) = 0x10000082;
                Actor43_86A04Field(&Actor43_86A04Data70328View1, int*, 0x23C) = 0x3C;
                Actor43_86A04Field(&Actor43_86A04Data70328View1, void**, 0x250) = ownerRecord17;
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x48) = 3U;
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x4A) = 0xFF;
            }
            goto runSharedTail;
        case 3:
            argumentWord4 = (int)&Actor43_86A04Data676E8View1;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = Actor43_86A04Data6C58CView1;
            rawWord2 = Actor43_86A04Data6C5C8View1;
            rawWord3 <<= 4;
            rawWord3 += argumentWord4;
            rawWord2 <<= 2;
            rawWord2 += rawWord3;
            rawWord2 = Actor43_86A04Field(rawWord2, int*, 0);
            rawWord3 = Actor43_86A04Field(&Actor43_86A04Data70328View1, int*, 8);
            rawWord2 += 200;
            rawWord3 = rawWord3 < rawWord2;
            if (rawWord3) {
                if (Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) != 2) {
                    Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) = 2U;
                    Actor43_86A04Field(privateOrDivisionMagic18, short*, 2) = 0xC8;
                }
                Actor43_86A04Data6E160View1 = 0;
                Actor43_86A04Field(ownerRecord17, int*, 8) = 0;
                Actor43_86A04Field(ownerRecord17, int*, 0x14) =
                    (int)(Actor43_86A04Field(ownerRecord17, int*, 0x14) -
                          Actor43_86A04Field(privateOrDivisionMagic18, short*, 2));
                temporaryWord6 =
                    (unsigned short)Actor43_86A04Field(privateOrDivisionMagic18, short*, 2) + 0x10;
                Actor43_86A04Field(privateOrDivisionMagic18, short*, 2) = temporaryWord6;
                if (temporaryWord6 >= 0x1F5) {
                    Actor43_86A04Field(privateOrDivisionMagic18, short*, 2) = 0x1F4;
                    return;
                }
            } else {
                Actor43_86A04RefreshMobySpatialGridAndBasisView1(ownerRecord17, 7);
                if ((Actor43_86A04CountTimerDownView1(privateOrDivisionMagic18, 2) != 0) &&
                    (Actor43_86A04Field(&Actor43_86A04Data70328View1, int*, 0x280) >= 0) &&
                    ((unsigned int)(Actor43_86A04Field(ownerRecord17, unsigned char*, 0x3C) - 1) >=
                     2U) &&
                    (Actor43_86A04Data6E538View1 & 0xA0)) {
                    if (Actor43_86A04Data6E538View1 & 0x80) {
                        Actor43_86A04Field(privateOrDivisionMagic18, int*, 4) = 1;
                        argumentWord4 = (int)ownerRecord17;
                        MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "memory");
                        argumentWord5 = 2;
                        goto callSelectedInputMode;
                    } else {
                        argumentWord4 = (int)ownerRecord17;
                        argumentWord5 = 1;
                    }
                callSelectedInputMode:
                    Actor43_86A04SetMobyAnimationView1(argumentWord4, argumentWord5);
                    Actor43_86A04Field(privateOrDivisionMagic18, short*, 0) = 0x32;
                }
                temporaryWord9 = Actor43_86A04Field(ownerRecord17, unsigned short*, 0x3C);
                if ((temporaryWord9 == 0x101) || (temporaryWord9 == 0x202)) {
                    if (Actor43_86A04Field(ownerRecord17, unsigned char*, 0x3C) == 2) {
                        if (Actor43_86A04Call55E84View1(ownerRecord17) < 0x11) {
                            goto block_27;
                        }
                        goto block_29;
                    }
                block_27:
                    if ((Actor43_86A04Field(ownerRecord17, unsigned char*, 0x3C) == 1) &&
                        (Actor43_86A04Call55E84View1(ownerRecord17) >= 9)) {
                    block_29:
                        if (Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) == 0) {
                            offsetIndexOrVectorAddress16 =
                                Actor43_86A04DataSpawnMobyView1(0x254, ownerRecord17);
                            MATCHING_KEEP(offsetIndexOrVectorAddress16);
                            if (offsetIndexOrVectorAddress16 != 0) {
                                heightPrivateOrConstant19 =
                                    Actor43_86A04Field(offsetIndexOrVectorAddress16, void**, 0);
                                temporaryWord7 =
                                    Actor43_86A04Field(privateOrDivisionMagic18, int*, 4);
                                Actor43_86A04Field(heightPrivateOrConstant19, int*, 8) =
                                    temporaryWord7;
                                if (temporaryWord7 != 0) {
                                    rawWord2 =
                                        Actor43_86A04Field(ownerRecord17, unsigned char*, 0x46);
                                    argumentWord4 = offsetIndexOrVectorAddress16 + 12;
                                    rawWord2 <<= 1;
                                    rawWord3 = Actor43_86A04Field(&Actor43_86A04Data65920View1,
                                                                  short*, rawWord2);
                                    argumentWord5 = (int)ownerRecord17 + 12;
                                    rawWord2 = (rawWord3 * 225) >> 9;
                                    originalFrame.sp30 = rawWord2;
                                    rawWord2 =
                                        Actor43_86A04Field(ownerRecord17, unsigned char*, 0x46);
                                    argumentWord6 = (int)&originalFrame.sp30;
                                    rawWord2 <<= 1;
                                    rawWord3 = Actor43_86A04Field(&Actor43_86A04Data658A0View1,
                                                                  short*, rawWord2);
                                    rawWord2 = 700;
                                    originalFrame.sp38 = rawWord2;
                                    rawWord2 = (rawWord3 * 225) >> 9;
                                    originalFrame.sp34 = rawWord2;
                                    Actor43_86A04AddVectorView1(argumentWord4, argumentWord5,
                                                                argumentWord6);
                                    Actor43_86A04Field(heightPrivateOrConstant19, int*, 4) = 0xC8;
                                }
                                Actor43_86A04Field(offsetIndexOrVectorAddress16, int*, 8) = 0;
                                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) = 1U;
                            }
                        }
                    }
                    if (Actor43_86A04Data6C770View1 != 0) {
                        Actor43_86A04Field(privateOrDivisionMagic18, int*, 4) = 0;
                        Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                        Actor43_86A04RequestMobyAnimationView1(ownerRecord17, 0);
                    }
                }
                if (Actor43_86A04Field(&Actor43_86A04Data70328View1, int*, 0xAC) != 0) {
                    rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x34);
                    rawWord3 = rawWord2;
                    MATCHING_KEEP(rawWord3);
                    if (rawWord2 < 0x1000) {
                        rawWord2 = rawWord3 + 256;
                        Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x34) = rawWord2;
                    }
                    if (Actor43_86A04Call3BFC0View1(
                            ownerRecord17,
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30)) == 0) {
                        Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30) =
                            Actor43_86A04PlayMobySoundEventView1(ownerRecord17, 0, 4);
                    }
                    if (Actor43_86A04Call3BFC0View1(
                            ownerRecord17,
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30)) != 0) {
                        Actor43_86A04Call3C140View1(
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30),
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x34));
                        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36);
                        rawWord3 = rawWord2;
                        MATCHING_KEEP(rawWord3);
                        if (rawWord2 >= 2049) {
                            rawWord2 = rawWord3 - 128;
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36) = rawWord2;
                            rawWord2 = (short)rawWord2;
                            if (rawWord2 < 2048) {
                                rawWord2 = 2048;
                                Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36) =
                                    rawWord2;
                            }
                        }
                        Actor43_86A04Call3C0B0View1(
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30),
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36));
                    }
                } else {
                    if (Actor43_86A04Call3BFC0View1(
                            ownerRecord17,
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30)) == 0) {
                        Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30) =
                            Actor43_86A04PlayMobySoundEventView1(ownerRecord17, 0, 4);
                    }
                    if (Actor43_86A04Call3BFC0View1(
                            ownerRecord17,
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30)) != 0) {
                        argumentWord4 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36);
                        rawWord3 = argumentWord4;
                        if (argumentWord4 < 2048) {
                            rawWord2 = rawWord3 + 128;
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36) = rawWord2;
                            rawWord2 = (short)rawWord2;
                            if (rawWord2 < 2049)
                                goto afterHalfwordClamp;
                            goto clampHalfwordTo2048;
                        } else {
                            rawWord2 = argumentWord4 < 2049;
                            if (rawWord2)
                                goto afterHalfwordClamp;
                            rawWord2 = rawWord3 - 128;
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36) = rawWord2;
                            rawWord2 = (short)rawWord2;
                            if (rawWord2 < 2048) {
                            clampHalfwordTo2048:
                                rawWord2 = 2048;
                                Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36) =
                                    rawWord2;
                            }
                        }
                    afterHalfwordClamp:;
                        Actor43_86A04Call3C0B0View1(
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30),
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x36));
                        temporaryWord4 = (unsigned short)Actor43_86A04Field(
                                             privateOrDivisionMagic18, short*, 0x34) -
                                         0x100;
                        Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x34) = temporaryWord4;
                        if (temporaryWord4 < 0x400) {
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x34) = 0x400;
                        }
                        Actor43_86A04Call3C140View1(
                            Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x30),
                            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x34));
                    }
                }
                goto runSharedTail;
            }
            break;
        case 4:
            if (Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) != 2) {
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49) = 2U;
                rawWord2 = Actor43_86A04CallrandView1();
                offsetIndexOrVectorAddress16 = -0x5A;
                if (rawWord2 & 1) {
                    offsetIndexOrVectorAddress16 = 0x5A;
                }
                rawWord2 = Actor43_86A04PlanarHeadingLookupView1(
                    Actor43_86A04Data6E020View1 - Actor43_86A04Field(ownerRecord17, int*, 0xC),
                    Actor43_86A04Data6E024View1 - Actor43_86A04Field(ownerRecord17, int*, 0x10), 0);
                rawWord3 = 0x7FFFFFFF;
                rawWord2 += offsetIndexOrVectorAddress16;
                rawWord2 &= 255;
                Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x16) = rawWord2;
                Actor43_86A04Field(ownerRecord17, int*, 0x1C) =
                    Actor43_86A04Field(ownerRecord17, int*, 0x1C) & rawWord3;
                Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x14) = 0x12C;
                Actor43_86A04Field(privateOrDivisionMagic18, int*, 0x10) = 0xB4;
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x4A) = 0xFF;
                Actor43_86A04Field(ownerRecord17, signed char*, 0x4C) = 0x20;
                Actor43_86A04Field(ownerRecord17, signed char*, 0x4E) = 0x20;
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x44) = 0U;
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x45) = 0U;
            }
            Actor43_86A04Field(ownerRecord17, int*, 0x14) =
                (int)(Actor43_86A04Field(ownerRecord17, int*, 0x14) +
                      Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x14));
            Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x14) =
                (short)((unsigned short)Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x14) -
                        0x10);
            Actor43_86A04Call35EE0View1(ownerRecord17,
                                        Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x16),
                                        0x64, 0, 0, 0);
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x45) =
                (unsigned char)(Actor43_86A04Field(ownerRecord17, unsigned char*, 0x45) + 6);
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x44) =
                (unsigned char)(Actor43_86A04Field(ownerRecord17, unsigned char*, 0x44) + 1);
            if ((Actor43_86A04CountTimerDownView1(privateOrDivisionMagic18 + 0x10, 4) != 0) ||
                ((Actor43_86A04Field(privateOrDivisionMagic18, short*, 0x14) < 0) &&
                 (offsetIndexOrVectorAddress16 = 0,
                  (Actor43_86A04Call19138View1(ownerRecord17 + 0xC, 0x258, 1, 0, 0, 0) != 0)))) {
                offsetIndexOrVectorAddress16 = 0;
                privateOrDivisionMagic18 = 0x55555556;
                MATCHING_OBSERVE_GNU_VOLATILE(privateOrDivisionMagic18);
                heightPrivateOrConstant19 = 0xC8;
                do {
                    completeSignedProduct.wide =
                        (long long)offsetIndexOrVectorAddress16 * privateOrDivisionMagic18;
                    argumentWord4 = 1;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord5 = 0x253;
                    MATCHING_KEEP(argumentWord5);
                    argumentWord6 = (int)ownerRecord17;
                    signedInputCorrection = offsetIndexOrVectorAddress16 >> 31;
                    rawWord2 = completeSignedProduct.words.high - signedInputCorrection;
                    argumentWord7 = rawWord2 * 3;
                    argumentWord7 = offsetIndexOrVectorAddress16 - argumentWord7;
                    argumentWord7 += 3;
                    temporaryPointer5 = Actor43_86A04Call391E8View1(
                        argumentWord4, argumentWord5, argumentWord6, argumentWord7, argumentWord7,
                        heightPrivateOrConstant19, 256);
                    offsetIndexOrVectorAddress16 += 1;
                    Actor43_86A04Field(temporaryPointer5, signed char*, 0x4F) = 0x14;
                    Actor43_86A04Field(temporaryPointer5, signed char*, 0x48) = 6;
                } while (offsetIndexOrVectorAddress16 < 9);
                Actor43_86A04Call369B8View1(ownerRecord17, 0x28);
                Actor43_86A04DeleteMobyView1(ownerRecord17);
                return;
            }
            break;
        default:
            goto runSharedTail;
    }
    return;
runSharedTail:
    temporaryWord10 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x48);
    if ((temporaryWord10 == 1) || (temporaryWord10 == 3)) {
        originalHeightWord9 = Actor43_86A04Field(ownerRecord17, int*, 0x14);
        Actor43_86A04Field(ownerRecord17, int*, 0x14) = (int)(originalHeightWord9 - 0x100);
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 12);
        offsetIndexOrVectorAddress16 = (int)&originalFrame.sp30;
        rawWord2 <<= 1;
        rawWord3 = Actor43_86A04Field(&Actor43_86A04Data65920View1, short*, rawWord2);
        argumentWord4 = offsetIndexOrVectorAddress16;
        rawTrigWord8 = (rawWord3 * 75) >> 9;
        MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
        originalFrame.sp30 = rawTrigWord8;
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 12);
        argumentWord5 = (int)ownerRecord17 + 12;
        rawWord2 <<= 1;
        rawWord3 = Actor43_86A04Field(&Actor43_86A04Data658A0View1, short*, rawWord2);
        argumentWord6 = offsetIndexOrVectorAddress16;
        originalFrame.sp38 = 0;
        argumentWord7 = (rawWord3 * 75) >> 9;
        MATCHING_OBSERVE2_GNU_VOLATILE(argumentWord5, argumentWord6);
        originalFrame.sp34 = argumentWord7;
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 12);
        rawWord2 = (rawWord2 + 10) & 255;
        rawWord2 <<= 1;
        rawWord3 = Actor43_86A04Field(&Actor43_86A04Data65920View1, short*, rawWord2);
        rawWord3 = (rawWord3 * 75) >> 9;
        originalFrame.sp40 = rawWord3;
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 12);
        heightPrivateOrConstant19 = originalHeightWord9 - 512;
        rawWord2 = (rawWord2 + 10) & 255;
        rawWord2 <<= 1;
        rawWord2 = Actor43_86A04Field(&Actor43_86A04Data658A0View1, short*, rawWord2);
        rawWord3 -= rawTrigWord8;
        originalFrame.sp48 = 0;
        originalFrame.sp40 = rawWord3;
        originalFrame.sp48 = 0;
        originalFrame.sp38 = 0;
        rawWord2 = (rawWord2 * 75) >> 9;
        originalFrame.sp44 = rawWord2;
        __asm__ __volatile__("" ::"m"(originalFrame.sp44));
        rawWord2 -= argumentWord7;
        originalFrame.sp44 = rawWord2;
        Actor43_86A04AddVectorView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
        argumentWord5 =
            Actor43_86A04DataSpawnParticleView1(1, 0x55, &originalFrame.sp30, &originalFrame.sp40);
        if (argumentWord5 != 0) {
            rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49);
            if (rawWord3 == 3) {
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 25) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 25;
                }
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = rawWord2;
                __asm__ __volatile__("" ::"i"(8486913) : "memory");
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
                if ((unsigned int)rawWord3 < 25) {
                    Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55) = 0;
                    goto copyFirstColorBytes;
                }
                rawWord2 = rawWord3 - 25;
                goto storeFirstColorByte55;
            } else if (rawWord3 == 4) {
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 25) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 25;
                }
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = rawWord2;
                __asm__ __volatile__("" ::"i"(8486914) : "memory");
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
                MATCHING_KEEP(rawWord3);
                rawWord2 = 128;
                argumentWord4 = rawWord3 & 255;
                rawWord2 -= argumentWord4;
                if (rawWord2 < 0)
                    rawWord2 = -rawWord2;
                if (rawWord2 < 25) {
                    rawWord2 = 128;
                    goto storeFirstColorByte55;
                }
                rawWord2 = (unsigned int)argumentWord4 < 129;
                if (rawWord2) {
                    rawWord2 = rawWord3 + 25;
                    goto storeFirstColorByte55;
                }
                rawWord2 = rawWord3 - 25;
                goto storeFirstColorByte55;
            } else {
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 25) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 25;
                }
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = rawWord2;
                __asm__ __volatile__("" ::"i"(8486915) : "memory");
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 25) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 25;
                }
            }
        storeFirstColorByte55:
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55) = rawWord2;
        copyFirstColorBytes:
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x10) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x11) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x12) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x56);
            Actor43_86A04Field(argumentWord5, signed char*, 0x14) =
                (signed char)((unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*,
                                                                0x54) >>
                              1);
            Actor43_86A04Field(argumentWord5, signed char*, 0x15) =
                (signed char)((unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*,
                                                                0x55) >>
                              1);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x16) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x56);
        }
        Actor43_86A04Field(ownerRecord17, int*, 0x14) = (int)(heightPrivateOrConstant19 + 0xC0);
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 14);
        rawWord2 <<= 1;
        rawWord3 = Actor43_86A04Field(&Actor43_86A04Data65920View1, short*, rawWord2);
        rawTrigWord8 = (rawWord3 * 75) >> 9;
        originalFrame.sp30 = rawTrigWord8;
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 14);
        rawWord2 <<= 1;
        rawWord3 = Actor43_86A04Field(&Actor43_86A04Data658A0View1, short*, rawWord2);
        offsetIndexOrVectorAddress16 = (int)&originalFrame.sp30;
        originalFrame.sp38 = 0;
        argumentWord7 = (rawWord3 * 75) >> 9;
        originalFrame.sp34 = argumentWord7;
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 14);
        argumentWord4 = offsetIndexOrVectorAddress16;
        rawWord2 = (rawWord2 + 246) & 255;
        rawWord2 <<= 1;
        rawWord3 = Actor43_86A04Field(&Actor43_86A04Data65920View1, short*, rawWord2);
        argumentWord5 = (int)ownerRecord17 + 12;
        rawWord3 = (rawWord3 * 75) >> 9;
        originalFrame.sp40 = rawWord3;
        rawWord2 = Actor43_86A04Field(privateOrDivisionMagic18, short*, 14);
        argumentWord6 = offsetIndexOrVectorAddress16;
        rawWord2 = (rawWord2 + 246) & 255;
        rawWord2 <<= 1;
        rawWord2 = Actor43_86A04Field(&Actor43_86A04Data658A0View1, short*, rawWord2);
        rawWord3 -= rawTrigWord8;
        originalFrame.sp48 = 0;
        originalFrame.sp40 = rawWord3;
        originalFrame.sp48 = 0;
        originalFrame.sp38 = 0;
        rawWord2 = (rawWord2 * 75) >> 9;
        originalFrame.sp44 = rawWord2;
        __asm__ __volatile__("" ::"m"(originalFrame.sp44));
        rawWord2 -= argumentWord7;
        originalFrame.sp44 = rawWord2;
        Actor43_86A04AddVectorView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
        argumentWord5 =
            Actor43_86A04DataSpawnParticleView1(1, 0x55, &originalFrame.sp30, &originalFrame.sp40);
        if (argumentWord5 != 0) {
            rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x49);
            if (rawWord3 == 3) {
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
                rawWord2 = 255 - rawWord3;
                if (rawWord2 < 10) {
                    Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = 255;
                } else {
                    rawWord2 = rawWord3 + 10;
                    Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = rawWord2;
                }
                goto copySecondColorBytes;
            } else if (rawWord3 == 4) {
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 10) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 10;
                }
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = rawWord2;
                __asm__ __volatile__("" ::"i"(8486930) : "memory");
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
                MATCHING_KEEP(rawWord3);
                rawWord2 = 128;
                argumentWord4 = rawWord3 & 255;
                rawWord2 -= argumentWord4;
                if (rawWord2 < 0)
                    rawWord2 = -rawWord2;
                if (rawWord2 < 10) {
                    rawWord2 = 128;
                    goto storeSecondColorByte55;
                }
                rawWord2 = (unsigned int)argumentWord4 < 129;
                if (rawWord2) {
                    rawWord2 = rawWord3 + 10;
                    goto storeSecondColorByte55;
                }
                rawWord2 = rawWord3 - 10;
                goto storeSecondColorByte55;
            } else {
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 10) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 10;
                }
                Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54) = rawWord2;
                __asm__ __volatile__("" ::"i"(8486931) : "memory");
                rawWord3 = Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
                rawWord2 = 255;
                rawWord2 -= rawWord3;
                if (rawWord2 < 10) {
                    rawWord2 = 255;
                } else {
                    rawWord2 = rawWord3 + 10;
                }
            }
        storeSecondColorByte55:
            Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55) = rawWord2;
        copySecondColorBytes:
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x10) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x11) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x55);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x12) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x56);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x14) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x15) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
            Actor43_86A04Field(argumentWord5, unsigned char*, 0x16) =
                (unsigned char)Actor43_86A04Field(ownerRecord17, unsigned char*, 0x54);
        }
        Actor43_86A04Field(ownerRecord17, int*, 0x14) = (int)(heightPrivateOrConstant19 + 0x64);
        Actor43_86A04Call1A310View1(ownerRecord17 + 0xC, 0xC8, 0, ownerRecord17);
        Actor43_86A04Call5629CView1(ownerRecord17);
        rawWord2 = heightPrivateOrConstant19 + 512;
        Actor43_86A04Field(ownerRecord17, int*, 0x14) = rawWord2;
        Actor43_86A04Field(privateOrDivisionMagic18, short*, 0xC) =
            (short)(((unsigned short)Actor43_86A04Field(privateOrDivisionMagic18, short*, 0xC) +
                     0xA) &
                    0xFF);
        Actor43_86A04Field(privateOrDivisionMagic18, short*, 0xE) =
            (short)(((unsigned short)Actor43_86A04Field(privateOrDivisionMagic18, short*, 0xE) +
                     0xF6) &
                    0xFF);
    }
    return;
}
#undef Actor43_86A04Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_43/moby/func_level_43_800876CC.s SHA256 8cfc368847ee3a90f63f0060fabc1ac66e4c013a7ac6ad4a7eb22e6fe238a463. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level43_876CCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level43_876CC_func_80019138() __asm__("func_80019138");
/* extern */
unsigned char Level43_876CC_func_8001A358() __asm__("func_8001A358");
/* extern */
void* Level43_876CC_func_8001BA30() __asm__("func_8001BA30");
/* extern */
int Level43_876CC_func_8001C288() __asm__("func_8001C288");
/* extern */
int Level43_876CCCountTimerDown() __asm__("func_800359A4");
/* extern */
unsigned char Level43_876CC_func_80035DDC() __asm__("func_80035DDC");
/* extern */
int Level43_876CCRandBetween() __asm__("func_8003636C");
/* extern */
int Level43_876CCRandSignedBetween() __asm__("func_800363DC");
/* extern */
void* Level43_876CC_func_800391E8() __asm__("func_800391E8");
/* extern */
unsigned char Level43_876CCPlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
int Level43_876CCPlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned char Level43_876CCTransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
unsigned char Level43_876CCClearVector() __asm__("func_8004F168");
/* extern */
unsigned char Level43_876CCCopyVector() __asm__("func_8004F178");
/* extern */
unsigned char Level43_876CCAddVector() __asm__("func_8004F194");
/* extern */
int Level43_876CCApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned char Level43_876CCDeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned char Level43_876CCRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
unsigned char Level43_876CC_func_8005629C() __asm__("func_8005629C");
/* extern */
extern unsigned char Level43_876CC_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level43_876CC_D_80065920 __asm__("D_80065920");
extern int Level43_876CC_D_8006C550 __asm__("D_8006C550");
extern int Level43_876CC_D_8006C574 __asm__("D_8006C574");
extern int Level43_876CC_D_8006C578 __asm__("D_8006C578");
extern unsigned char Level43_876CC_D_80070328 __asm__("D_80070328");
extern int Level43_876CC_D_80071908 __asm__("D_80071908");
extern int Level43_876CC_D_80071918 __asm__("D_80071918");
extern int Level43_876CC_D_8007191C __asm__("D_8007191C");
extern int Level43_876CC_D_80071920 __asm__("D_80071920");
extern void* (*Level43_876CC_SpawnMoby)() __asm__("SpawnMoby");
extern void* (*Level43_876CC_SpawnParticle)() __asm__("SpawnParticle");

void func_level_43_800876CC(void* inputOwner) {
    /* Original frame0x78, scratch SP20/30/40, signed table reads and
     * the distinct spawn-call sites are retained. Anchor indices use
     * the original 88-byte producer stride and one shared pool read.
     * Empty constraints retain register lifetimes and mandatory branch
     * destinations;
      they emit no opcodes. Rev1 raw596 identifies the
     * overlapping body, but Rev0 instructions are the matching authority.
     * Helper semantics, physical units/fixed point, cadence and synchronized
     * runtime captures remain unresolved. AI generated;
      not human reviewed. */
    register void* owner18 __asm__("$18") = inputOwner;
    register int constant22 __asm__("$22");
    register int constant21 __asm__("$21");
    register int constant19 __asm__("$19");
    register int* scratch17 __asm__("$17");
    register int* scratch16 __asm__("$16");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument6 __asm__("$6");
    register int argument5 __asm__("$5");
    struct {
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        int sp30;
        unsigned char pad34[12];
        int sp40;
        int sp44;
        int sp48;
        unsigned char pad4C[4];
    } scratch;

    register int* temp_s0 __asm__("$16");
    int temp_v0_2;
    int temp_v0_4;
    register int var_a1 __asm__("$5");
    int collisionResult30;
    register int particleIndex16 __asm__("$16");
    register int childIndex16 __asm__("$16");
    register int range17 __asm__("$17");
    register int probeFlag20 __asm__("$20");
    register int spawnSuccess23 __asm__("$23");
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int childAngle17 __asm__("$17");
    register int ownerAnchor4 __asm__("$4");
    unsigned char temp_v1;
    register int candidateAnchor3 __asm__("$3");
    unsigned char temp_v1_3;
    void* candidateAnchorPosition5;
    register void* temp_s0_2 __asm__("$16");
    register void* private19 __asm__("$19");
    void* temp_v0;
    void* temp_v0_3;
    register void* temp_v0_5 __asm__("$2");
    register void* temp_v0_6 __asm__("$4");
    void* temp_v1_4;
    register void* var_a0 __asm__("$4");
    register void* candidate16 __asm__("$16");
    register void* ownerPosition21 __asm__("$21");
    register void* var_v1 __asm__("$3");

    MATCHING_KEEP(owner18);
    collisionResult30 = 0;
    temp_v1 = Level43_876CCField(owner18, unsigned char*, 0x48);
    private19 = Level43_876CCField(owner18, void**, 0);
    probeFlag20 = 0;
    if (temp_v1 != 2) {
        if (temp_v1 == 1) {
            scratch.sp40 = 0;
            scratch.sp44 = 0x96;
            scratch.sp48 = 0;
            value2 = Level43_876CCField(private19, int*, 0);
            MATCHING_KEEP(value2);
            probeFlag20 = 5;
            argument4 = (int)owner18;
            if (value2 == probeFlag20) {
                scratch.sp44 = 0x2BC;
            }
            Level43_876CCRefreshMobySpatialGridAndBasis((void*)argument4, 4);
            MATCHING_KEEP_CLOBBER(owner18, "memory");
            argument4 = (int)owner18 + 32;
            MATCHING_KEEP(argument4);
            scratch17 = &scratch.sp40;
            Level43_876CCTransformVectorByBasis((void*)argument4, scratch17, scratch17);
            temp_s0 = owner18 + 0xC;
            Level43_876CCAddVector(temp_s0, temp_s0, scratch17);
            scratch.sp40 = 0;
            scratch.sp44 = 0;
            value3 = Level43_876CCField(private19, int*, 0);
            value3 = probeFlag20 - value3;
            value2 = value3 * 6;
            scratch.sp48 = -value2;
            temp_v0 = Level43_876CC_SpawnParticle(1, 0xD, temp_s0, scratch17);
            if (temp_v0 != 0) {
                value2 = Level43_876CCField(private19, int*, 0);
                value2 = probeFlag20 - value2;
                value3 = value2 * 22;
                value2 = 120;
                value2 -= value3;
                Level43_876CCField(temp_v0, signed char*, 0xA) = value2;
            }
            temp_v0_2 = Level43_876CCField(private19, int*, 0) - 1;
            Level43_876CCField(private19, int*, 0) = temp_v0_2;
            if (temp_v0_2 > 0)
                goto finishController;
            goto finishSpawnSequence;
        } else {
            __asm__ volatile("" ::: "$4", "memory");
            Level43_876CCCopyVector(&scratch.sp20, owner18 + 12);
            value2 = Level43_876CCRandSignedBetween(0, 100);
            argument4 = 0;
            value3 = scratch.sp20;
            argument5 = 100;
            value3 -= 50;
            value3 += value2;
            scratch.sp20 = value3;
            value2 = Level43_876CCRandSignedBetween(0, 100);
            argument4 = 0;
            value3 = scratch.sp24;
            argument5 = 100;
            value3 -= 50;
            value3 += value2;
            scratch.sp24 = value3;
            value2 = Level43_876CCRandSignedBetween(0, 100);
            argument4 = 0;
            value3 = scratch.sp28;
            argument5 = 100;
            value3 -= 50;
            value3 += value2;
            scratch.sp28 = value3;
            scratch16 = &scratch.sp30;
            Level43_876CCClearVector(scratch16);
            temp_v0_3 = Level43_876CC_SpawnParticle(1, 0xD, &scratch.sp20, scratch16);
            if (temp_v0_3 != 0) {
                Level43_876CCField(temp_v0_3, signed char*, 0xA) = 0xA;
            }
            Level43_876CC_func_80035DDC(owner18, 0x12C, 0, 0, 0);
            MATCHING_KEEP_CLOBBER(owner18, "memory");
            var_a0 = owner18 + 0xC;
            MATCHING_KEEP(var_a0);
            if (Level43_876CCField(private19, int*, 8) != 0) {
                Level43_876CCField(owner18, int*, 0x14) =
                    (int)(Level43_876CCField(owner18, int*, 0x14) +
                          Level43_876CCField(private19, int*, 4));
                temp_v0_4 = Level43_876CCField(private19, int*, 4) - 0x10;
                Level43_876CCField(private19, int*, 4) = temp_v0_4;
                if (temp_v0_4 < -0x190) {
                    Level43_876CCField(private19, int*, 4) = -0x190;
                    MATCHING_KEEP_CLOBBER(owner18, "memory");
                    var_a0 = owner18 + 0xC;
                }
            }
            Level43_876CCField(owner18, int*, 0x1C) =
                (int)(Level43_876CCField(owner18, int*, 0x1C) | 0x80000000);
            var_a0 = owner18 + 12;
            MATCHING_KEEP(var_a0);
            Level43_876CC_func_8001A358(var_a0, 0x2000);
            Level43_876CC_func_8005629C(owner18);
            Level43_876CCRefreshMobySpatialGridAndBasis(owner18, 2);
            MATCHING_KEEP_CLOBBER(owner18, "memory");
            if (Level43_876CCField(owner18, int*, 12) < 1024 ||
                Level43_876CCField(owner18, int*, 16) < 1024 ||
                Level43_876CCField(owner18, int*, 20) < 1024)
                goto setProbeFlag;
            value2 = Level43_876CCCountTimerDown(private19, 4);
            MATCHING_KEEP(owner18);
            ownerPosition21 = owner18 + 12;
            if (value2) {
            setProbeFlag:
                probeFlag20 = 1;
                ownerPosition21 = owner18 + 12;
            }
            candidate16 = Level43_876CC_func_8001BA30(ownerPosition21, 0x64, 3, 0, 0, owner18);
            if ((candidate16 != 0) && (Level43_876CCField(candidate16, short*, 0x36) == 0x254)) {
                value2 = 255;
                candidateAnchor3 = Level43_876CCField(candidate16, unsigned char*, 0x3A);
                __asm__("" : "=r"(candidateAnchor3) : "0"(candidateAnchor3), "r"(value2));
                if (candidateAnchor3 != value2) {
                    ownerAnchor4 = Level43_876CCField(owner18, unsigned char*, 0x3A);
                    MATCHING_KEEP(ownerAnchor4);
                    if (candidateAnchor3 != ownerAnchor4) {
                        candidateAnchorPosition5 =
                            (void*)(Level43_876CC_D_8006C550 + candidateAnchor3 * 88);

                        range17 = 500;
                        if (Level43_876CCField(
                                (void*)(ownerAnchor4 * 88 + Level43_876CC_D_8006C550), short*,
                                0x36) == 0x253) {
                            range17 = 0x384;
                        }
                        if (Level43_876CCField(candidateAnchorPosition5, short*, 0x36) == 0x20B) {
                            value2 = Level43_876CCField(candidateAnchorPosition5, int*, 0x14);
                            value3 = Level43_876CCField(owner18, int*, 0x14);
                            var_v0 = value2 - value3;
                            if (var_v0 < 0) {
                                var_v0 = -var_v0;
                            }
                            if ((var_v0 < 0x1F4) &&
                                (Level43_876CCApproximatePlanarDistance(
                                     ownerPosition21, candidateAnchorPosition5 + 0xC) < range17)) {
                                probeFlag20 = 1;
                                if (Level43_876CCField(private19, int*, 8) != 0) {
                                    probeFlag20 = 2;
                                }
                                Level43_876CCField(candidate16, int*, 0x18) = 0x100000;
                                Level43_876CCField(candidate16, unsigned char*, 0x51) =
                                    (unsigned char)Level43_876CCField(owner18, unsigned char*,
                                                                      0x46);
                            }
                        }
                    }
                }
            }
            if (probeFlag20)
                goto checkPrivateC;
            value2 = 596;
            if (!candidate16)
                goto considerOther;
            value3 = Level43_876CCField(candidate16, short*, 0x36);
            argument4 = (int)owner18 + 12;
            if (value3 != value2)
                goto considerOther;
            MATCHING_KEEP(probeFlag20);
            value2 = (int)Level43_876CC_func_8001BA30((void*)argument4, 100, 3, 0, 0, candidate16);
            if (probeFlag20) {
                candidate16 = (void*)value2;
                goto checkPrivateC;
            }
            candidate16 = (void*)value2;
        considerOther:
            MATCHING_KEEP(candidate16);
            value2 = 596;
            if (!candidate16)
                goto checkPrivateC;
            value3 = Level43_876CCField(candidate16, short*, 0x36);
            if (value3 == value2)
                goto checkPrivateC;
            {
                Level43_876CCField(candidate16, int*, 0x18) = 0x100000;
                probeFlag20 = 1;
                Level43_876CCField(candidate16, unsigned char*, 0x51) =
                    (unsigned char)Level43_876CCField(owner18, unsigned char*, 0x46);
                Level43_876CCField(owner18, int*, 0x14) =
                    (int)Level43_876CCField(candidate16, int*, 0x14);
                goto afterCandidate;
            }
        checkPrivateC:
            if ((Level43_876CCField(private19, int*, 0xC) != 0) &&
                (Level43_876CC_func_8001C288(owner18 + 0xC, 8, 7) != 0)) {
                value2 = 0x10000000;
                value3 = Level43_876CCField(owner18, unsigned char*, 0x46);
                __asm__("" : "=r"(value2) : "0"(value2), "r"(value3));
                value2 |= 0x400;
                Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x20C) = value2;
                Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x298) = value3;
                value2 = Level43_876CCField(owner18, unsigned char*, 0x46) * 2;
                value3 = *(short*)(&Level43_876CC_D_80065920 + value2);
                MATCHING_KEEP(value3);
                value2 = value3 * 25;
                Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x21C) = value2 >> 11;
                value2 = Level43_876CCField(owner18, unsigned char*, 0x46) * 2;
                value3 = *(short*)(&Level43_876CC_D_800658A0 + value2);
                probeFlag20 = 1;
                Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x224) = 0;
                value2 = value3 * 25;
                Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x220) = value2 >> 11;
            }
        afterCandidate:
            argument4 = (int)&scratch.sp20;
            MATCHING_KEEP(argument4);
            temp_s0_2 = owner18 + 0xC;
            Level43_876CCCopyVector((void*)argument4, temp_s0_2);
            scratch.sp28 += 0x80;
            if (probeFlag20)
                goto collide;
            MATCHING_KEEP(probeFlag20);
            collisionResult30 = Level43_876CC_func_80019138(&scratch.sp20, 250, 1, 0, 0, 0);
            if (collisionResult30) {
            collide:
                spawnSuccess23 = 0;
                Level43_876CCPlayMobySoundEvent(owner18, 0, 0);
                if (collisionResult30 != 0) {
                    if (Level43_876CCApproximatePlanarDistance(temp_s0_2,
                                                               &Level43_876CC_D_80070328) < 0x7D0) {
                        value3 = 0x10000000;
                        value2 = 7;
                        Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x24) = value2;
                        value2 = Level43_876CCField(owner18, unsigned char*, 0x46);
                        __asm__("" : "=r"(value3) : "0"(value3), "r"(value2));
                        value3 |= 0x400;
                        Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x20C) = value3;
                        Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x298) = value2;
                        value2 = Level43_876CCField(owner18, unsigned char*, 0x46) * 2;
                        value3 = *(short*)(&Level43_876CC_D_80065920 + value2);
                        MATCHING_KEEP(value3);
                        value2 = value3 * 15;
                        Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x21C) = value2 >> 11;
                        value2 = Level43_876CCField(owner18, unsigned char*, 0x46) * 2;
                        value3 = *(short*)(&Level43_876CC_D_800658A0 + value2);
                        Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x224) = 0;
                        value2 = value3 * 15;
                        Level43_876CCField(&Level43_876CC_D_80070328, int*, 0x220) = value2 >> 11;
                    }
                    temp_v1_3 = Level43_876CCField(owner18, unsigned char*, 0x3A);
                    if ((temp_v1_3 != 0xFF) &&
                        (Level43_876CCField(((temp_v1_3 * 0x58) + Level43_876CC_D_8006C550), short*,
                                            0x36) == 0x253)) {
                        Level43_876CC_func_8001BA30(temp_s0_2, 0x200, 3, 0, 0x100000, owner18);
                    }
                }
                particleIndex16 = 0;
                range17 = 2;
                constant22 = 200;
                constant21 = 256;
                constant19 = 28;
                argument4 = 1;
                do {
                    temp_v0_5 = Level43_876CC_func_800391E8(argument4, 0x54, owner18, 0, range17,
                                                            constant22, constant21);
                    if (temp_v0_5 != 0) {
                        Level43_876CCField(temp_v0_5, signed char*, 0x48) = range17;
                        Level43_876CCField(temp_v0_5, signed char*, 0x4F) = constant19;
                    }
                    particleIndex16 += 1;
                    argument4 = 1;
                } while (particleIndex16 < 5);
                MATCHING_BARRIER_VOLATILE("memory");
                argument4 = 1000;
                if (probeFlag20 == 2) {
                    register void* (*spawn2)() __asm__("$2") = Level43_876CC_SpawnMoby;
                    MATCHING_KEEP(spawn2);
                    value2 = (int)spawn2(argument4, owner18);
                    var_v1 = (void*)value2;
                    goto initializeSpawnedChild;
                }
                if (collisionResult30 != 0) {
                    var_a1 = 0;
                    if (Level43_876CC_D_80071920 > 0) {
                        var_v0_2 =
                            (int)(Level43_876CC_D_80071918 * 0x64) / (int)Level43_876CC_D_80071920;
                        if (var_v0_2 < 0) {
                            var_v0_2 = -var_v0_2;
                        }
                        if (var_v0_2 < 6) {
                            var_v0_3 = (int)(Level43_876CC_D_8007191C * 0x64) /
                                       (int)Level43_876CC_D_80071920;
                            if (var_v0_3 < 0) {
                                var_v0_3 = -var_v0_3;
                            }
                            MATCHING_KEEP(var_v0_3);
                            var_a1 = var_v0_3 < 6;
                        }
                    }
                    if (var_a1 != 0) {
                        register void* (*spawn3)() __asm__("$3");
                        argument4 = 1000;
                        MATCHING_KEEP(argument4);
                        value2 = Level43_876CC_D_80071908;
                        spawn3 = Level43_876CC_SpawnMoby;
                        __asm__("" : "=r"(spawn3) : "0"(spawn3), "r"(value2) : "$5");
                        argument5 = (int)owner18;
                        Level43_876CCField(owner18, int*, 0x14) = value2;
                        var_v1 = spawn3(argument4, (void*)argument5);
                    initializeSpawnedChild:
                        if (var_v1 != 0) {
                            spawnSuccess23 = 1;
                            Level43_876CCField(var_v1, signed char*, 0x48) = 1;
                            temp_v1_4 = Level43_876CCField(var_v1, void**, 0);
                            Level43_876CCField(temp_v1_4, short*, 2) = 0x190;
                            Level43_876CCField(temp_v1_4, short*, 0x14) = 0x1E;
                            Level43_876CCField(temp_v1_4, short*, 0x16) = 0x50;
                        }
                    }
                }
                if (spawnSuccess23 == 0) {
                    MATCHING_KEEP(spawnSuccess23);
                    argument6 = 0;
                    MATCHING_KEEP(argument6);
                    childIndex16 = 0;
                    Level43_876CCField(owner18, unsigned char*, 0x46) =
                        Level43_876CCPlanarHeadingLookup(
                            Level43_876CCField(&Level43_876CC_D_80070328, int*, 0) -
                                Level43_876CCField(owner18, int*, 0xC),
                            Level43_876CCField(&Level43_876CC_D_80070328, int*, 4) -
                                Level43_876CCField(owner18, int*, 0x10),
                            argument6);
                    childAngle17 = Level43_876CCRandBetween(0, 0x7F);
                loop_70:
                    if ((Level43_876CC_D_8006C578 - Level43_876CC_D_8006C574) >= 0x15) {
                        temp_v0_6 = Level43_876CC_SpawnMoby(0x254, owner18);
                        MATCHING_KEEP(temp_v0_6);
                        if (temp_v0_6 != 0) {
                            Level43_876CCField(temp_v0_6, signed char*, 0x41) = 0;
                            Level43_876CCField(temp_v0_6, signed char*, 0x4C) = 0;
                            Level43_876CCField(temp_v0_6, signed char*, 0x4D) = 0;
                            value3 = Level43_876CCField(owner18, unsigned char*, 0x46);
                            value2 = 1;
                            Level43_876CCField(temp_v0_6, signed char*, 0x48) = value2;
                            Level43_876CCField(temp_v0_6, unsigned char*, 0x46) = value3;
                            value3 = Level43_876CCField(temp_v0_6, int*, 0);
                            value2 = 5;
                            Level43_876CCField(temp_v0_6, signed char*, 0x44) = childAngle17;
                            Level43_876CCField(temp_v0_6, int*, 8) = 0;
                            *(int*)value3 = value2;
                        }
                        childIndex16 += 1;
                        childAngle17 += 0x33;
                        if (childIndex16 >= 5) {

                        } else {
                            goto loop_70;
                        }
                    }
                }
                Level43_876CC_SpawnParticle(0xA, 0x46, owner18 + 0xC, (int*)0x10);
            finishSpawnSequence:
                Level43_876CCDeleteMoby(owner18);
            }
        }
    }
finishController:;
}
#undef Level43_876CCField

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level43
 * 80088000: all262 original instructions in sibling4491. Verified31 signed
 * trigonometric products and raw actor helper call forms are reused.
 * Preserve original offsets, signed division guards and branch routes.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
#define Actor43Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Actor43Cos[] __asm__("D_80065920"), Actor43Sin[] __asm__("D_800658A0");
extern unsigned char Actor43Player[] __asm__("D_80070328"), Actor43Position[] __asm__("D_8006E020");
extern int Actor43Tick __asm__("D_8006C648");
extern unsigned char* (*Actor43Spawn)(int, void*)__asm__("SpawnMoby");
extern unsigned char* (*Actor43Particle)(int, int, void*, void*)__asm__("SpawnParticle");
int Actor43H3BFC0() __asm__("func_8003BFC0");
int Actor43H3BE70() __asm__("func_8003BE70");
int Actor43PlayMobySoundEvent() __asm__("func_8003BABC");
int Actor43CopyVector() __asm__("func_8004F178");
int Actor43CountTimerDown() __asm__("func_800359A4");
int Actor43PlanarHeadingLookup() __asm__("func_8004E880");
int Actor43AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Actor43SubtractVector() __asm__("func_8004F1C8");
int Actor43MeasureVectorLength() __asm__("func_8004EDE8");
int Actor43ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Actor43AddVector() __asm__("func_8004F194");
int Actor43ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor43RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor43RandBetween() __asm__("func_8003636C");
void func_level_43_80088000(void* input) {
    int velocity[4];
    int direction[4];
    register unsigned char* owner __asm__("$18") = input;
    register unsigned char* tag __asm__("$19") = Actor43Field(owner, unsigned char**, 0);
    register unsigned char* child __asm__("$16");
    register unsigned char* position __asm__("$17");
    register int amplitude __asm__("$20");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int denominator __asm__("$4");
    register int phase __asm__("$5");
    register int product __asm__("$8");
    register unsigned char* call4 __asm__("$4");
    register unsigned char* particle __asm__("$3");
    if (Actor43Field(owner, int*, 24)) {
        Actor43Field(owner, int*, 24) = 0;
        if (Actor43H3BFC0(owner, Actor43Field(tag, int*, 8)))
            Actor43H3BE70(Actor43Field(tag, int*, 8));
        Actor43Field(tag, int*, 8) = Actor43PlayMobySoundEvent(owner, 0, 0);
        if (owner[0x48] == 2)
            tag[7] = 200;
        else {
            owner[0x48] = 2;
            tag[4] = 0;
            tag[5] = 0;
            work3 = owner[0x46];
            work2 = 200;
            tag[7] = work2;
            tag[6] = work3;
        }
    }
    switch (owner[0x48]) {
        case 0:
            child = Actor43Spawn(596, owner);
            MATCHING_KEEP(child);
            if (!child)
                goto draw;
            child[0x48] = 2;
            child[0x41] = 0;
            child[0x4C] = 0;
            child[0x4D] = 0;
            Actor43Field(tag, void**, 0) = child;
            owner[0x48] = 1;
            Actor43CopyVector(child + 12, owner + 12);
            Actor43Field(child, int*, 20) += 512;
            goto draw;
        case 2:
            phase = 200 - tag[7];
            denominator = phase * 5 + 128;
            work3 = Actor43Cos[tag[6]];
            work3 = work3 / denominator;
            owner[0x44] = tag[4] + work3;
            work3 = Actor43Sin[tag[6]];
            work3 = work3 / denominator;
            owner[0x45] = tag[5] + work3;
            phase >>= 3;
            work2 = Actor43Tick;
            phase += 2;
            product = phase * work2;
            call4 = tag + 7;
            phase = 1;
            MATCHING_KEEP2(call4, phase);
            work2 = tag[6];
            work2 += product;
            tag[6] = work2;
            if (Actor43CountTimerDown(call4, phase)) {
                owner[0x48] = 1;
                owner[0x44] = 0;
                owner[0x45] = 0;
                Actor43Field(tag, int*, 8) = -1;
            }
        case 1:
            call4 = Actor43Field(tag, unsigned char**, 0);
            if (!call4)
                goto draw;
            work2 = Actor43Field(owner, int*, 12);
            work3 = Actor43Field(Actor43Player, int*, 0);
            MATCHING_KEEP2(work2, work3);
            work2 -= work3;
            if (work2 < 0)
                work2 = -work2;
            amplitude = 1000;
            if (work2 > 5120) {
                work2 = Actor43Field(owner, int*, 16);
                work3 = Actor43Field(Actor43Player, int*, 4);
                MATCHING_KEEP2(work2, work3);
                work2 -= work3;
                if (work2 < 0)
                    work2 = -work2;
                if (work2 > 5120) {
                    Actor43CopyVector(call4 + 12, owner + 12);
                    goto draw;
                }
            }
            work3 = Actor43AbsoluteByteAngleDelta(
                Actor43PlanarHeadingLookup(
                    Actor43Field(owner, int*, 12) - Actor43Field(Actor43Player, int*, 0),
                    Actor43Field(owner, int*, 16) - Actor43Field(Actor43Player, int*, 4), 0),
                Actor43Player[14]);
            if (work3 < 64) {
                amplitude = work3 * 8;
                if (amplitude > 500)
                    amplitude = 500;
                amplitude += 500;
            }
            child = (unsigned char*)direction;
            position = owner + 12;
            Actor43SubtractVector(child, position, Actor43Player);
            work2 = Actor43MeasureVectorLength(child, 0);
            Actor43ScaleVectorRatioQ15(child, work2, amplitude);
            direction[2] = 0;
            Actor43AddVector(Actor43Field(tag, unsigned char**, 0) + 12, position, child);
            break;
    }
draw:
    if (Actor43ApproximatePlanarDistance(owner + 12, Actor43Position) < 3001)
        return;
    Actor43RefreshMobySpatialGridAndBasis(owner, 7);
    velocity[0] = Actor43RandBetween(-16, 16);
    velocity[1] = Actor43RandBetween(-16, 16);
    velocity[2] = 32;
    particle = Actor43Particle(1, 37, owner, velocity);
    MATCHING_KEEP(particle);
    if (particle)
        Actor43Field(particle, short*, 8) -= 200;
}

typedef struct {
    unsigned char bounds00[0x18];
    unsigned char bounds18[0x18];
    int linkedIndex;
} DecodedLinkedBoundsTag;
extern int D_8006C5C8;
extern Moby* D_8006C550;
extern unsigned short** DecodedLinkedBoundsLists __asm__("D_8006C730");
int DecodedLinkedBoundsQuery(Vector3D*, void*, int, int) __asm__("func_80036220");
void func_level_43_80088418(Moby* moby) {
    DecodedLinkedBoundsTag* tag = moby->mobyTag;
    Moby* linked;
    register unsigned short* list __asm__("$4");
    Moby* loopLinked;
    if (!D_8006C5C8 && !moby->substate && tag->linkedIndex >= 0 &&
        DecodedLinkedBoundsQuery((Vector3D*)&spyro, tag->bounds18, 0, 0x2800)) {
        linked = (Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550);
        if (!(linked->state & 0x80))
            func_80055B18(linked);
        moby->substate = 1;
    }
    switch (moby->state) {
        case 0:
            if (DecodedLinkedBoundsQuery((Vector3D*)&spyro, tag, 0, 0x2800)) {
                list = DecodedLinkedBoundsLists[moby->animationRun];
                do {
                    loopLinked =
                        (Moby*)((*list & 0x7FFF) * sizeof(Moby) + (unsigned int)D_8006C550);
                    if (loopLinked->state < 0x80)
                        loopLinked->substate = 1;
                } while ((short)*list++ >= 0);
                moby->state = 1;
            }
            break;
        case 1:
            if (!DecodedLinkedBoundsQuery((Vector3D*)&spyro, tag, 0, 0x2800)) {
                list = DecodedLinkedBoundsLists[moby->animationRun];
                do {
                    loopLinked =
                        (Moby*)((*list & 0x7FFF) * sizeof(Moby) + (unsigned int)D_8006C550);
                    if (loopLinked->state < 0x80)
                        loopLinked->substate = 0;
                } while ((short)*list++ >= 0);
                moby->state = 0;
            }
            break;
    }
}

int func_8003BB10(Moby*, int, int);
int func_8003BFC0(Moby*, int);
void func_8003BE70(int);
void func_level_43_8008862C(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            break;
        case 1:
            if (*tag == -1)
                *tag = func_8003BB10(moby, 6, 0);
            else if (!func_8003BFC0(moby, *tag)) {
                *tag = -1;
                moby->state = 0;
            }
            break;
        case 2:
            if (func_8003BFC0(moby, *tag))
                func_8003BE70(*tag);
            *tag = -1;
            moby->state = 0;
            break;
    }
}

typedef struct {
    int timer;
    Moby* actor;
} DecodedLinkedSpawnTag;
int func_800359A4(void*, int);
void func_level_43_800886F4(Moby* moby) {
    DecodedLinkedSpawnTag* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if ((!tag->actor || (tag->actor->state & 0x80)) && func_800359A4(tag, 4)) {
                moby->state = 1;
                tag->actor = 0;
            }
            break;
        case 1: {
            Moby* actor = SpawnMoby(0x22A, moby);
            if (actor) {
                Vector3D zero;
                register Vector3D* zeroPointer __asm__("$5") = &zero;
                register Vector3D* destination __asm__("$4") = actor->mobyTag;
                __asm__("" : "=r"(destination) : "0"(destination), "r"(zeroPointer) : "memory");
                zero.x = 0;
                zero.y = 0;
                zero.z = 0;
                func_8004F178(destination, zeroPointer);
                actor->state = 0x52;
                moby->state = 0;
                tag->timer = 0x14;
                tag->actor = actor;
            }
            break;
        }
    }
}

typedef struct {
    int elapsed, duration, hud, previousIndex, nextIndex;
    int bounds[6];
} DecodedSequenceGate;
extern Moby* D_8006C550;
int func_800369D8(int);
int func_80036220(Vector3D*, void*, int, int);
void func_80055B18(Moby*);
void func_level_43_800887D4(Moby* moby) {
    DecodedSequenceGate* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (func_80036220((Vector3D*)&spyro, tag->bounds, 0, 0x2800)) {
                D_8006C550[tag->nextIndex].state = 6;
                moby->state = 1;
            }
            break;
        case 1:
            if (unk_ovlheader_80074330(&moby->position, moby->angle.yaw, 0)) {
                moby->state = 2;
                moby->substate = 1;
                tag->elapsed = 0;
                tag->duration = func_800369D8(moby->unknown3[2]) - 1;
                tag->hud =
                    (short)func_8002803C(0x17, 0, func_80027EE4, func_80027A60,
                                         unk_ovlheader_8007448C, &tag->elapsed, tag->duration);
            }
            break;
        case 2:
            if (tag->elapsed >= tag->duration) {
                D_8006C550[tag->previousIndex].state = 4;
                func_80028154(tag->hud);
                func_80055B18(moby);
            }
            break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_43/moby", D_level_43_80074C10);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_43/moby", D_level_43_80074C1C);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_43/moby", D_level_43_80074C28);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80088980.
* AI generated; not human reviewed. All816 original instructions,six selector
* words and every actual destination must match:822 recorded owned words.
* FrameB0hex=176 bytes saves S0..S6/RA;SP10..8F retains original word storage.
* Three original12-byte tables copy toSP10/14/18,SP20/24/28 andSP30/34/38.
* All40 separate original rodata bytes are audited,including the final zero
* word outside those copies. The index domain and table units remain open;
* no padding or undefined incoming value is consumed by empty metadata.
* Original negative-index return is compared plus1 before count-2 replaces
* that retained value. Count=-1,index=-1 retains-3 rather than reloading.
* Independent word/byte aliases keep original absolute player reads/stores;
* retained complete pointers preserve the original relative consumers.
* Two repeated flag/trig/vector families retain signed halfword samples,
* whole products and shifts,byte updates and complete signed /126 results.
* The initialized full0x82082083 scalar enables ordinary C division constant
* reuse;no synthetic partialHI exists. Dynamic signed divisions keep all
* original zero and signed-overflow guards. Full products and C quotients
* retain the original low32 arithmetic,sign correction and branch targets.
* Original reset564 and vector-copy609/611 have distinct physical entries.
* Original height helpers observe the+1500 store before each call;the-1500
* store reloads and runs after the helper. Callback-visible ordering remains.
* ABI SP29 is the complete initialized frame address. Saved pointer,index,
* heading,step,height and actor-cursor roles occupy separate live phases.
* Empty metadata consumes initialized complete values/addresses or clobbers
* dead values before fresh complete producers;zero CPU words. No opcode asm,
* fixedFP,partialHI,undefined saved inputs or compiler/filter/flag changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation,
* Rev1 mapping and synchronized runtime remain open. Confidence is binary
* identity after all gates. Next:human review and retail captures. Every
* native/linked instruction,actual destination,selector,table byte and full
* EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 fe967ad75790d10b32e656673b8eb7b432803ff9a11df58493432cff285550e4 */
#define Level43_88980Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level43_88980Call13ACCView1() __asm__("func_80013ACC");
int Level43_88980Call1A358View1() __asm__("func_8001A358");
int Level43_88980Call36018View1() __asm__("func_80036018");
int Level43_88980SubAngle8View1() __asm__("func_8003613C");
int Level43_88980Call3B7B4View1() __asm__("func_8003B7B4");
int Level43_88980Call40F48View1() __asm__("func_80040F48");
int Level43_88980PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level43_88980ClearVectorView1() __asm__("func_8004F168");
int Level43_88980CopyVectorView1() __asm__("func_8004F178");
int Level43_88980AddVectorView1() __asm__("func_8004F194");
int Level43_88980AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level43_88980ApproachByteAngleView1() __asm__("func_8004F2EC");
extern int Level43_88980Data658A0View1 __asm__("D_800658A0");
extern int Level43_88980Data65920View1 __asm__("D_80065920");
extern int Level43_88980Data6C550View1 __asm__("D_8006C550");
extern int Level43_88980Data6C58CView1 __asm__("D_8006C58C");
extern int Level43_88980Data6C704View1 __asm__("D_8006C704");
extern unsigned char Level43_88980Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level43_88980Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level43_88980Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level43_88980Data6D088View1 __asm__("D_8006D088");
extern int Level43_88980Data6E160View1 __asm__("D_8006E160");
extern int Level43_88980Data6E164View1 __asm__("D_8006E164");
extern int Level43_88980Data70300View1 __asm__("D_80070300");
extern int Level43_88980Data70328View1 __asm__("D_80070328");
extern int Level43_88980Data716ACView1 __asm__("D_800716AC");
extern int Level43_88980Data71918View1 __asm__("D_80071918");
extern int Level43_88980Data7191CView1 __asm__("D_8007191C");
extern int Level43_88980Data71920View1 __asm__("D_80071920");
extern int Level43_88980Data71924View1 __asm__("D_80071924");
extern int (*Level43_88980Data743A4View1)() __asm__("unk_ovlheader_800743A4");
extern int Level43_88980Data74C10View1[3] __asm__("D_level_43_80074C10");
extern int Level43_88980Data74C1CView1[3] __asm__("D_level_43_80074C1C");
extern int Level43_88980Data74C28View1[3] __asm__("D_level_43_80074C28");
extern unsigned char Level43_88980Data70328View2 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View3 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View4 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View5 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View6 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View7 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View8 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View9 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View10 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View11 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View12 __asm__("D_80070328 + 14");
extern unsigned char Level43_88980Data70328View13 __asm__("D_80070328 + 14");
extern int Level43_88980Data70328View14 __asm__("D_80070328 + 572");
extern unsigned char Level43_88980Data70328View15 __asm__("D_80070328 + 554");
extern unsigned char Level43_88980Data70328View16 __asm__("D_80070328 + 554");
extern int Level43_88980Data70328View17 __asm__("D_80070328 + 564");
extern int Level43_88980Data70328View18 __asm__("D_80070328 + 564");
void func_level_43_80088980(void* ownerParameter) {
    register void* ownerRecord21 __asm__("$21");
    register int privateThenActorCursor17 __asm__("$17"),
        retainedHeadingVectorOrHeightView16 __asm__("$16"),
        retainedIndexHeadingOrClass18 __asm__("$18"), retainedPlayerPathOrHeading19 __asm__("$19"),
        retainedPathThenStep20 __asm__("$20"), retainedOriginalStep22 __asm__("$22");
    register unsigned char* originalAbiStackAddress29 __asm__("$29");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C;
    } originalFrame;
    int temporaryWord4;
    int temporaryWord14;
    int temporaryWord9;
    int temporaryWord19;
    int temporaryWord1;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord13;
    int temporaryWord18;
    int temporaryWord20;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord21, completeOriginalDivisionScalar;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord15;
    ownerRecord21 = ownerParameter;
    MATCHING_KEEP(ownerRecord21);
    privateThenActorCursor17 = Level43_88980Field(ownerRecord21, void**, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level43_88980Data74C10View1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level43_88980Field(argumentWord5, int*, 0);
    rawWord3 = Level43_88980Field(argumentWord5, int*, 4);
    argumentWord4 = Level43_88980Field(argumentWord5, int*, 8);
    originalFrame.sp10 = rawWord2;
    originalFrame.sp14 = rawWord3;
    originalFrame.sp18 = argumentWord4;
    __asm__ volatile("" ::"m"(originalFrame.sp10), "m"(originalFrame.sp14),
                     "m"(originalFrame.sp18));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level43_88980Data74C1CView1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level43_88980Field(argumentWord5, int*, 0);
    rawWord3 = Level43_88980Field(argumentWord5, int*, 4);
    argumentWord4 = Level43_88980Field(argumentWord5, int*, 8);
    originalFrame.sp20 = rawWord2;
    originalFrame.sp24 = rawWord3;
    originalFrame.sp28 = argumentWord4;
    __asm__ volatile("" ::"m"(originalFrame.sp20), "m"(originalFrame.sp24),
                     "m"(originalFrame.sp28));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level43_88980Data74C28View1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level43_88980Field(argumentWord5, int*, 0);
    rawWord3 = Level43_88980Field(argumentWord5, int*, 4);
    argumentWord4 = Level43_88980Field(argumentWord5, int*, 8);
    originalFrame.sp30 = rawWord2;
    originalFrame.sp34 = rawWord3;
    originalFrame.sp38 = argumentWord4;
    __asm__ volatile("" ::"m"(originalFrame.sp30), "m"(originalFrame.sp34),
                     "m"(originalFrame.sp38));
    temporaryWord16 = Level43_88980Field(ownerRecord21, unsigned char*, 0x48);
    switch (temporaryWord16) {
        case 5:
            if (!(Level43_88980Data6C7B4View1 & 2) &&
                !(Level43_88980Field((int)&Level43_88980Data70300View1, unsigned char*,
                                     Level43_88980Data6C58CView1) &
                  2)) {
                temporaryWord1 = Level43_88980Data6C58CView1 * 6;
                temporaryWord17 = Level43_88980Field((int)&Level43_88980Data716ACView1,
                                                     unsigned char*, 1 + temporaryWord1);
                if (temporaryWord17 < 0xFFU) {
                    Level43_88980Field((int)&Level43_88980Data716ACView1, unsigned char*,
                                       1 + temporaryWord1) = temporaryWord17 + 1;
                }
            }
            Level43_88980Field(ownerRecord21, unsigned char*, 0x48) = 0U;
            return;
        case 0:
            retainedPlayerPathOrHeading19 = (int)&Level43_88980Data70328View1 + 184;
            MATCHING_KEEP(retainedPlayerPathOrHeading19);
            rawWord2 = Level43_88980Field(retainedPlayerPathOrHeading19, int*, 0);
            retainedHeadingVectorOrHeightView16 = (int)&originalFrame.sp40;
            if (rawWord2 == 0) {
                argumentWord4 = retainedHeadingVectorOrHeightView16;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
                retainedIndexHeadingOrClass18 = retainedPlayerPathOrHeading19 - 184;
                Level43_88980CopyVectorView1(argumentWord4, retainedIndexHeadingOrClass18);
                originalFrame.sp48 += 0x200;
                if ((Level43_88980Call1A358View1(&originalFrame.sp40, 0x1000) != 0) &&
                    ((Level43_88980Data71924View1 & 0xF) ==
                     Level43_88980Field(privateThenActorCursor17, int*, 0x1C))) {
                    temporaryWord3 = Level43_88980Field(privateThenActorCursor17, void**, 0);
                    temporaryWord5 =
                        (int)(Level43_88980Field(temporaryWord3, unsigned short*, 0) << 0x10) >>
                        0x11;
                    Level43_88980Field(Level43_88980Field(privateThenActorCursor17, void**, 0),
                                       short*, 2) =
                        Level43_88980Data743A4View1(retainedIndexHeadingOrClass18, temporaryWord3,
                                                    temporaryWord5, temporaryWord5);
                    temporaryWord2 = Level43_88980Field(privateThenActorCursor17, void**, 0);
                    temporaryWord4 = Level43_88980Field(temporaryWord2, short*, 2);
                    if ((temporaryWord4 + 1) <
                        (short)Level43_88980Field(temporaryWord2, unsigned short*, 0)) {
                        temporaryWord10 =
                            (temporaryWord4 * 0x10) + Level43_88980Field(temporaryWord2, int*, 0xC);
                        temporaryWord6 = Level43_88980Field(temporaryWord10, int*, 0x10);
                        Level43_88980Field(privateThenActorCursor17, int*, 0x14) =
                            Level43_88980PlanarHeadingLookupView1(
                                temporaryWord6 - Level43_88980Field(temporaryWord10, int*, 0),
                                Level43_88980Field(temporaryWord10, int*, 0x14) -
                                    Level43_88980Field(temporaryWord10, int*, 4),
                                0);
                        Level43_88980Call13ACCView1(ownerRecord21, 0xD);
                        retainedHeadingVectorOrHeightView16 = ownerRecord21 + 0x4A;
                        Level43_88980Field(ownerRecord21, unsigned char*, 0x4A) = 0xFF;
                        Level43_88980Call3B7B4View1(retainedHeadingVectorOrHeightView16, 1,
                                                    (int)&Level43_88980Data6D088View1);
                        Level43_88980Call3B7B4View1(retainedHeadingVectorOrHeightView16, 1,
                                                    (int)&Level43_88980Data6C7F8View1);
                        Level43_88980Field(ownerRecord21, unsigned char*, 0x48) = 1U;
                        Level43_88980ClearVectorView1(privateThenActorCursor17 + 8);
                        MATCHING_KEEP(retainedPlayerPathOrHeading19);
                        rawWord2 = Level43_88980Field(retainedPlayerPathOrHeading19, int*, -4);
                        rawWord3 = Level43_88980Data6C7C4View1;
                        rawWord2 >>= 5;
                        Level43_88980Field(privateThenActorCursor17, short*, 26) = rawWord2;
                        rawWord3 *= 4;
                        rawWord2 = (int)originalAbiStackAddress29 + rawWord3;
                        MATCHING_KEEP(rawWord2);
                        rawWord2 = Level43_88980Field(rawWord2, int*, 16);
                        Level43_88980Field(privateThenActorCursor17, short*, 24) = rawWord2;
                        return;
                    }
                }
            }
        default:
            return;
        case 1:
            retainedPathThenStep20 = Level43_88980Field(privateThenActorCursor17, void**, 0);
            retainedIndexHeadingOrClass18 = Level43_88980Data743A4View1(
                (int)&Level43_88980Data70328View1, retainedPathThenStep20,
                Level43_88980Field(retainedPathThenStep20, short*, 2), 2);
            rawWord2 = retainedIndexHeadingOrClass18 + 1;
            if (retainedIndexHeadingOrClass18 >= 0) {
                Level43_88980Field(retainedPathThenStep20, short*, 2) =
                    retainedIndexHeadingOrClass18;
                goto readOriginalPathEntry180;
            }
            rawWord3 = Level43_88980Field(retainedPathThenStep20, short*, 0);
            rawWord2 = rawWord2 < rawWord3;
            retainedIndexHeadingOrClass18 = rawWord3 - 2;
            if (rawWord2)
                retainedIndexHeadingOrClass18 =
                    Level43_88980Field(retainedPathThenStep20, short*, 2);
        readOriginalPathEntry180:
            temporaryWord18 =
                Level43_88980Field(((retainedIndexHeadingOrClass18 * 0x10) +
                                    Level43_88980Field(retainedPathThenStep20, int*, 0xC)),
                                   int*, 0xC);
            if (temporaryWord18 == 1) {
                temporaryWord20 =
                    Level43_88980Field(&originalFrame.sp10, int*, Level43_88980Data6C7C4View1 * 4) *
                    2;
                goto writeOriginalPathValue204;
            }
            if (temporaryWord18 == 0) {
                temporaryWord20 =
                    Level43_88980Field(&originalFrame.sp10, int*, Level43_88980Data6C7C4View1 * 4);
            writeOriginalPathValue204:
                Level43_88980Field(privateThenActorCursor17, short*, 0x18) = (short)temporaryWord20;
            }
            argumentWord5 = Level43_88980Field(privateThenActorCursor17, short*, 0x1A);
            rawWord3 = Level43_88980Field(privateThenActorCursor17, short*, 0x18);
            rawWord2 = argumentWord5 < rawWord3;
            argumentWord4 = argumentWord5;
            if (rawWord2) {
                rawWord2 = argumentWord4 + Level43_88980Field(&originalFrame.sp20, int*,
                                                              Level43_88980Data6C7C4View1 * 4);
                goto writeOriginalAdjustedValue230;
            }
            rawWord2 = rawWord3 < argumentWord5;
            if (rawWord2) {
                rawWord2 = argumentWord4 - Level43_88980Field(&originalFrame.sp30, int*,
                                                              Level43_88980Data6C7C4View1 * 4);
            writeOriginalAdjustedValue230:
                Level43_88980Field(privateThenActorCursor17, short*, 0x1A) = rawWord2;
            }
            argumentWord5 = 0x10008000;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$22");
            retainedOriginalStep22 = 3;
            argumentWord6 = 0;
            argumentWord4 = (int)&Level43_88980Data70328View1 + 524;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(argumentWord6));
            retainedPlayerPathOrHeading19 = Level43_88980Data70328View2;
            rawWord2 = Level43_88980Field(argumentWord4, int*, 0);
            rawWord3 = 49;
            Level43_88980Data70328View14 = rawWord3;
            rawWord2 |= argumentWord5;
            Level43_88980Field(argumentWord4, int*, 0) = rawWord2;
            temporaryWord12 = (retainedIndexHeadingOrClass18 * 0x10) +
                              Level43_88980Field(retainedPathThenStep20, int*, 0xC);
            temporaryWord7 = Level43_88980Field(temporaryWord12, int*, 0x10);
            retainedHeadingVectorOrHeightView16 = Level43_88980PlanarHeadingLookupView1(
                temporaryWord7 - Level43_88980Field(temporaryWord12, int*, 0),
                Level43_88980Field(temporaryWord12, int*, 0x14) -
                    Level43_88980Field(temporaryWord12, int*, 4),
                0);
            argumentWord4 = Level43_88980SubAngle8View1(retainedHeadingVectorOrHeightView16,
                                                        Level43_88980Data70328View3);
            rawWord3 = argumentWord4;
            if (argumentWord4 < 0)
                rawWord3 = -rawWord3;
            if (rawWord3 >= 0x51) {
                rawWord2 = retainedHeadingVectorOrHeightView16 + 128;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                retainedPlayerPathOrHeading19 = rawWord2 - argumentWord4;
                if (Level43_88980AbsoluteByteAngleDeltaView1(
                        retainedPlayerPathOrHeading19,
                        Level43_88980Field(privateThenActorCursor17, int*, 0x14)) >= 0x31) {
                    retainedOriginalStep22 = 6;
                }
            } else {
                rawWord2 = rawWord3 < 49;
                if (!rawWord2) {
                    retainedPlayerPathOrHeading19 = Level43_88980Call36018View1(
                        Level43_88980Data70328View4, retainedHeadingVectorOrHeightView16, 0x30);
                }
            }
            argumentWord5 = Level43_88980Field(privateThenActorCursor17, int*, 20);
            rawWord3 = Level43_88980Field(privateThenActorCursor17, short*, 26);
            argumentWord4 = argumentWord5 * 2;
            rawWord2 = Level43_88980Field((int)&Level43_88980Data65920View1, short*, argumentWord4);
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp50 = rawWord2;
            rawWord3 = Level43_88980Field(privateThenActorCursor17, short*, 26);
            rawWord2 = Level43_88980Field((int)&Level43_88980Data658A0View1, short*, argumentWord4);
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord3, rawWord2, "memory");
            argumentWord6 = retainedOriginalStep22;
            argumentWord7 = (argumentWord6 >> 1) + 1;
            argumentWord4 = retainedPlayerPathOrHeading19;
            originalFrame.sp58 = 0;
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp54 = rawWord2;
            rawWord2 = Level43_88980ApproachByteAngleView1(argumentWord4, argumentWord5,
                                                           argumentWord6, argumentWord7);
            retainedHeadingVectorOrHeightView16 = (int)&Level43_88980Data70328View1 + 556;
            __asm__(""
                    : "=r"(retainedHeadingVectorOrHeightView16)
                    : "0"(retainedHeadingVectorOrHeightView16), "r"(rawWord2));
            argumentWord4 = retainedHeadingVectorOrHeightView16;
            argumentWord5 = retainedHeadingVectorOrHeightView16 - 556;
            argumentWord6 = (int)&originalFrame.sp50;
            Level43_88980Field(privateThenActorCursor17, int*, 20) = rawWord2;
            Level43_88980AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 0x228) = 0;
            Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 0x229) = 0;
            Level43_88980Call40F48View1(&originalFrame.sp60, 1);
            if (originalFrame.sp60 >= 0xB) {
                Level43_88980Field(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level43_88980Field(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  4);
            } else if (originalFrame.sp60 < -0xA) {
                Level43_88980Field(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level43_88980Field(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) -
                                  4);
            } else if (originalFrame.sp60 != 0) {
                Level43_88980Field(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level43_88980Field(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  ((originalFrame.sp60 * 8) / 126));
            } else {
                Level43_88980Field((int)&Level43_88980Data70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level43_88980Data70328View5;
            }
            retainedHeadingVectorOrHeightView16 = (int)&Level43_88980Data70328View1 + 0x234;
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
            rawWord2 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0);
            argumentWord5 = 4096;
            rawWord2 += 1500;
            Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
            temporaryWord13 = Level43_88980Call1A358View1(argumentWord4, argumentWord5);
            argumentWord4 = privateThenActorCursor17 + 8;
            if (temporaryWord13 == 0) {
                rawWord2 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0);
                argumentWord5 = (int)&originalFrame.sp50;
                goto resetOriginalState564;
            }
            Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = temporaryWord13;
            Level43_88980Field(privateThenActorCursor17, short*, 4) = 0;
            rawWord3 = Level43_88980Field(retainedPathThenStep20, short*, 0);
            rawWord2 = retainedIndexHeadingOrClass18 + 1;
            rawWord2 = rawWord2 < rawWord3;
            if (!rawWord2)
                Level43_88980Field(ownerRecord21, unsigned char*, 72) = 2;
            rawWord2 = Level43_88980Field(retainedPathThenStep20, short*, 2);
            rawWord3 = Level43_88980Field(retainedPathThenStep20, short*, 0);
            retainedIndexHeadingOrClass18 = rawWord2 + 6;
            argumentWord4 = (int)ownerRecord21 + 12;
            if (retainedIndexHeadingOrClass18 >= rawWord3)
                retainedIndexHeadingOrClass18 = rawWord3 - 1;
            rawWord2 = Level43_88980Field(retainedPathThenStep20, int*, 12);
            argumentWord5 = retainedIndexHeadingOrClass18 * 16;
            goto copyOriginalPathVector611;
        case 2:
            retainedPlayerPathOrHeading19 = Level43_88980Field(privateThenActorCursor17, void**, 0);
            temporaryWord14 =
                (unsigned short)Level43_88980Field(privateThenActorCursor17, short*, 0x1A) - 8;
            Level43_88980Field(privateThenActorCursor17, short*, 0x1A) = temporaryWord14;
            if ((short)temporaryWord14 < 9) {
                temporaryWord19 = (int)&Level43_88980Data70328View1 + 0x20C;
                Level43_88980Field((int)&Level43_88980Data70328View1, int*, 0x23C) = 0;
                Level43_88980Field((int)&Level43_88980Data70328View1, int*, 0x20C) =
                    (int)(Level43_88980Field((int)&Level43_88980Data70328View1, int*, 0x20C) |
                          0x10008000);
                Level43_88980CopyVectorView1(temporaryWord19 + 0x20, temporaryWord19 - 0x20C);
                Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 0x228) = 0;
                Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 0x229) = 0;
                Level43_88980Field((int)&Level43_88980Data70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level43_88980Data70328View6;
                Level43_88980Field(ownerRecord21, unsigned char*, 0x48) = 4U;
                return;
            }
            argumentWord5 = 0x10008000;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$20");
            retainedPathThenStep20 = 3;
            argumentWord6 = 0;
            argumentWord4 = (int)&Level43_88980Data70328View1 + 524;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(argumentWord6));
            retainedIndexHeadingOrClass18 = Level43_88980Data70328View7;
            rawWord2 = Level43_88980Field(argumentWord4, int*, 0);
            rawWord3 = 49;
            Level43_88980Data70328View14 = rawWord3;
            rawWord2 |= argumentWord5;
            Level43_88980Field(argumentWord4, int*, 0) = rawWord2;
            temporaryWord15 =
                ((short)Level43_88980Field(retainedPlayerPathOrHeading19, unsigned short*, 0) *
                 0x10) +
                Level43_88980Field(retainedPlayerPathOrHeading19, int*, 0xC);
            temporaryWord8 = Level43_88980Field(temporaryWord15, int*, -0x10);
            retainedHeadingVectorOrHeightView16 = Level43_88980PlanarHeadingLookupView1(
                temporaryWord8 - Level43_88980Field(temporaryWord15, int*, -0x20),
                Level43_88980Field(temporaryWord15, int*, -0xC) -
                    Level43_88980Field(temporaryWord15, int*, -0x1C),
                0);
            argumentWord4 = Level43_88980SubAngle8View1(retainedHeadingVectorOrHeightView16,
                                                        Level43_88980Data70328View8);
            rawWord3 = argumentWord4;
            if (argumentWord4 < 0)
                rawWord3 = -rawWord3;
            if (rawWord3 >= 0x51) {
                rawWord2 = retainedHeadingVectorOrHeightView16 + 128;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                retainedIndexHeadingOrClass18 = rawWord2 - argumentWord4;
                if (Level43_88980AbsoluteByteAngleDeltaView1(
                        retainedIndexHeadingOrClass18,
                        Level43_88980Field(privateThenActorCursor17, int*, 0x14)) >= 0x31) {
                    retainedPathThenStep20 = 6;
                }
            } else {
                rawWord2 = rawWord3 < 49;
                if (!rawWord2) {
                    retainedIndexHeadingOrClass18 = Level43_88980Call36018View1(
                        Level43_88980Data70328View9, retainedHeadingVectorOrHeightView16, 0x30);
                }
            }
            argumentWord5 = Level43_88980Field(privateThenActorCursor17, int*, 20);
            rawWord3 = Level43_88980Field(privateThenActorCursor17, short*, 26);
            argumentWord4 = argumentWord5 * 2;
            rawWord2 = Level43_88980Field((int)&Level43_88980Data65920View1, short*, argumentWord4);
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp68 = rawWord2;
            rawWord3 = Level43_88980Field(privateThenActorCursor17, short*, 26);
            rawWord2 = Level43_88980Field((int)&Level43_88980Data658A0View1, short*, argumentWord4);
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord3, rawWord2, "memory");
            argumentWord6 = retainedPathThenStep20;
            argumentWord7 = (argumentWord6 >> 1) + 1;
            argumentWord4 = retainedIndexHeadingOrClass18;
            originalFrame.sp70 = 0;
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp6C = rawWord2;
            rawWord2 = Level43_88980ApproachByteAngleView1(argumentWord4, argumentWord5,
                                                           argumentWord6, argumentWord7);
            retainedHeadingVectorOrHeightView16 = (int)&Level43_88980Data70328View1 + 556;
            __asm__(""
                    : "=r"(retainedHeadingVectorOrHeightView16)
                    : "0"(retainedHeadingVectorOrHeightView16), "r"(rawWord2));
            argumentWord4 = retainedHeadingVectorOrHeightView16;
            argumentWord5 = retainedHeadingVectorOrHeightView16 - 556;
            argumentWord6 = (int)&originalFrame.sp68;
            Level43_88980Field(privateThenActorCursor17, int*, 20) = rawWord2;
            Level43_88980AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 0x228) = 0;
            Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 0x229) = 0;
            Level43_88980Call40F48View1(&originalFrame.sp78, 1);
            if (originalFrame.sp78 >= 0xB) {
                Level43_88980Field(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level43_88980Field(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  4);
            } else if (originalFrame.sp78 < -0xA) {
                Level43_88980Field(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level43_88980Field(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) -
                                  4);
            } else if (originalFrame.sp78 != 0) {
                Level43_88980Field(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level43_88980Field(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  ((originalFrame.sp78 * 8) / 126));
            } else {
                Level43_88980Field((int)&Level43_88980Data70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level43_88980Data70328View10;
            }
            retainedHeadingVectorOrHeightView16 = (int)&Level43_88980Data70328View1 + 0x234;
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
            rawWord2 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0);
            argumentWord5 = 4096;
            rawWord2 += 1500;
            Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
            temporaryWord11 = Level43_88980Call1A358View1(argumentWord4, argumentWord5);
            argumentWord4 = privateThenActorCursor17 + 8;
            if (temporaryWord11 == 0) {
                rawWord2 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0);
                argumentWord5 = (int)&originalFrame.sp68;
            resetOriginalState564:
                rawWord2 -= 1500;
                Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
                Level43_88980Field(ownerRecord21, unsigned char*, 72) = 3;
                Level43_88980Field(privateThenActorCursor17, unsigned short*, 6) = 25;
                Level43_88980CopyVectorView1(argumentWord4, argumentWord5);
                return;
            }
            Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = temporaryWord11;
            Level43_88980Field(privateThenActorCursor17, short*, 4) = 0;
            rawWord3 = Level43_88980Field(retainedPlayerPathOrHeading19, short*, 2);
            rawWord2 = Level43_88980Field(retainedPlayerPathOrHeading19, short*, 0);
            rawWord3 += 6;
            argumentWord4 = (int)ownerRecord21 + 12;
            if (rawWord3 < rawWord2)
                goto loadOriginalPathTable609;
            if (Level43_88980Field(ownerRecord21, unsigned char*, 73) == 1)
                return;
            Level43_88980Field(ownerRecord21, unsigned char*, 73) = 1;
            privateThenActorCursor17 = Level43_88980Data6C550View1;
            rawWord2 = Level43_88980Data6C704View1;
            retainedIndexHeadingOrClass18 = 132;
            if ((unsigned int)privateThenActorCursor17 < (unsigned int)rawWord2) {
                retainedHeadingVectorOrHeightView16 = privateThenActorCursor17 + 12;
                do {
                    if (Level43_88980Field(retainedHeadingVectorOrHeightView16, short*, 42) ==
                        retainedIndexHeadingOrClass18)
                        Level43_88980CopyVectorView1(ownerRecord21 + 12,
                                                     retainedHeadingVectorOrHeightView16);
                    rawWord2 = Level43_88980Data6C704View1;
                    MATCHING_KEEP_VOLATILE_CLOBBER(privateThenActorCursor17, "memory");
                    privateThenActorCursor17 += 88;
                    retainedHeadingVectorOrHeightView16 += 88;
                } while ((unsigned int)privateThenActorCursor17 < (unsigned int)rawWord2);
            }
            return;
        loadOriginalPathTable609:
            rawWord2 = Level43_88980Field(retainedPlayerPathOrHeading19, int*, 12);
            argumentWord5 = rawWord3 * 16;
        copyOriginalPathVector611:
            Level43_88980CopyVectorView1(argumentWord4, rawWord2 + argumentWord5);
            return;
        case 4:
            retainedHeadingVectorOrHeightView16 = ownerRecord21 + 0x48;
            Level43_88980Data6E160View1 = 0;
            Level43_88980Data6E164View1 = 0;
            Level43_88980Field(ownerRecord21, unsigned char*, 0x48) = 0U;
            Level43_88980Call3B7B4View1(retainedHeadingVectorOrHeightView16, 1,
                                        (int)&Level43_88980Data6D088View1);
            Level43_88980Call3B7B4View1(retainedHeadingVectorOrHeightView16, 1,
                                        (int)&Level43_88980Data6C7F8View1);
            return;
        case 3:
            temporaryWord9 = (int)&Level43_88980Data70328View1 + 0x20C;
            Level43_88980Field((int)&Level43_88980Data70328View1, int*, 0x23C) = 7;
            Level43_88980Field((int)&Level43_88980Data70328View1, int*, 0x20C) =
                (int)(Level43_88980Field((int)&Level43_88980Data70328View1, int*, 0x20C) |
                      0x10008000);
            Level43_88980AddVectorView1(temporaryWord9 + 0x20, temporaryWord9 - 0x20C,
                                        privateThenActorCursor17 + 8);
            rawWord2 = Level43_88980Data70328View11;
            Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 552) = 0;
            Level43_88980Field((int)&Level43_88980Data70328View1, signed char*, 553) = 0;
            Level43_88980Data70328View15 = rawWord2;
            rawWord3 = Level43_88980Field(privateThenActorCursor17, short*, 4);
            rawWord2 = Level43_88980Field((int)&Level43_88980Data70328View1, int*, 8);
            rawWord2 += rawWord3;
            Level43_88980Field((int)&Level43_88980Data70328View1, int*, 564) = rawWord2;
            rawWord2 = Level43_88980Field(privateThenActorCursor17, unsigned short*, 4) - 12;
            Level43_88980Field(privateThenActorCursor17, short*, 4) = rawWord2;
            __asm__ volatile("" ::"m"(Level43_88980Field(privateThenActorCursor17, short*, 4))
                             : "memory");
            rawWord2 = Level43_88980Field((int)&Level43_88980Data70328View1, int*, 564);
            if (rawWord2 < -560)
                Level43_88980Field((int)&Level43_88980Data70328View1, int*, 564) = -560;
            Level43_88980Call40F48View1(&originalFrame.sp80, 1);
            argumentWord4 = originalFrame.sp80;
            if (argumentWord4) {
                completeOriginalDivisionScalar = 0x82082083;
                MATCHING_OBSERVE_VOLATILE(completeOriginalDivisionScalar);
                argumentWord4 *= 8;
                rawWord3 = argumentWord4 / 126;
                temporaryWord21 = Level43_88980Data70328View12 + rawWord3;
            } else
                temporaryWord21 = Level43_88980Data70328View13;
            Level43_88980Field((int)&Level43_88980Data70328View1, unsigned char*, 554) =
                temporaryWord21;
            rawWord2 = Level43_88980Field(privateThenActorCursor17, unsigned short*, 6) - 1;
            Level43_88980Field(privateThenActorCursor17, unsigned short*, 6) = rawWord2;
            argumentWord5 = 4096;
            if ((rawWord2 << 16) <= 0) {
                retainedHeadingVectorOrHeightView16 = (int)&Level43_88980Data70328View17;
                MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
                argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
                __asm__ volatile("" ::"r"(argumentWord4) : "$2", "memory");
                rawWord2 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) + 1500;
                Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
                rawWord2 = Level43_88980Call1A358View1(argumentWord4, argumentWord5);
                rawWord3 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) - 1500;
                Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord3;
                if (rawWord2) {
                    Level43_88980Data6E160View1 = 0;
                    Level43_88980Data6E164View1 = 0;
                    Level43_88980Field(ownerRecord21, unsigned char*, 72) = 0;
                    Level43_88980Field((int)&Level43_88980Data70328View1, int*, 148) = -8960;
                }
                return;
            }
            retainedHeadingVectorOrHeightView16 = (int)&Level43_88980Data70328View18;
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
            __asm__ volatile("" ::"r"(argumentWord4) : "$2", "memory");
            rawWord2 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) + 1500;
            Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
            rawWord2 = Level43_88980Call1A358View1(argumentWord4, argumentWord5);
            rawWord3 = Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0);
            argumentWord5 = rawWord2;
            rawWord3 -= 1500;
            Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord3;
            if (argumentWord5 &&
                argumentWord5 < Level43_88980Field((int)&Level43_88980Data70328View1, int*, 8) &&
                Level43_88980Data71920View1) {
                rawWord2 = (Level43_88980Data71918View1 * 100) / Level43_88980Data71920View1;
                if (rawWord2 < 0)
                    rawWord2 = -rawWord2;
                MATCHING_KEEP(rawWord2);
                if (rawWord2 < 20) {
                    rawWord2 = (Level43_88980Data7191CView1 * 100) / Level43_88980Data71920View1;
                    if (rawWord2 < 0)
                        rawWord2 = -rawWord2;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 < 20) {
                        Level43_88980Field(ownerRecord21, unsigned char*, 72) = 1;
                        Level43_88980Field(retainedHeadingVectorOrHeightView16, int*, 0) =
                            argumentWord5;
                    }
                }
            }
            return;
    }
}
#undef Level43_88980Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80089640.
 * AI generated; not human reviewed. Every 574 original native/linked word
 * and actual branch,call and internal target must match. No owned selector,
 * padding or packed-data words occur. FrameD0 retains SP18..A7 local extent
 * and S0..S7/FP/RA at SPA8..CC. Unwritten reserve contents are never read.
 * Nine initialized caller slots SP80..A0 retain the original complete values.
 * Natural FP retains the original first COS address and later SIN projection;
 * no fixed FP/SP binding or overlapping live fixed-register aliases occurs.
 * Every signed MULT consumes both complete original signed32 operands in a
 * signed64 C product. Empty metadata observes its complete HILO result's low
 * or high signed32 word; narrowing precedes each original signed shift12.
 * Initialized producer/argument identities preserve original load,product,
 * callback,spill and delay-slot cadence. Every template emits zero CPU words.
 * Geometry loops retain16*6 points; topology loops retain15*6 records and
 * original /3,/6,/90 high-word corrections,signs,byte offsets and sentinels.
 * Original clamp2048 and particle thirdvector2 are distinct target words.
 * Natural literal fifth argument1 preserves each SW/SP10,JAL,ADDIU/A3 delay.
 * Raw arithmetic:32767*900=29490300; signedSRA12 yields7199. Signed -10/3
 * truncates toward zero to-3. Geometry scalar domains,physical units,full
 * helper/caller contracts,cadence beyond invocation,Rev1 mapping and retail
 * runtime remain open. Confidence is binary identity after all source/data
 * and complete EXE/every-overlay hashes. Next:human review and synchronized
 * retail capture. Compiler,filter,flags and acceptance gates are unchanged.
 */
/* Original assembly SHA256 4051a11145c4a6b901ee6c3c58a8fd4a14bc4ef7f564e35054abc5cc7279d7f4 */
#define Level43_89640Low(a, b)                                                       \
    ({                                                                               \
        long long completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        int lowWord;                                                                 \
        __asm__("" : "=l"(lowWord) : "x"(completeSignedProduct));                    \
        lowWord;                                                                     \
    })
#define Level43_89640F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level43_89640W(p, o) Level43_89640F(p, int*, o)
#define Level43_89640P(p, o) Level43_89640F(p, unsigned char**, o)
#define Level43_89640B(p, o) Level43_89640F(p, unsigned char*, o)
#define Level43_89640H(p, o) Level43_89640F(p, short*, o)
#define Level43_89640U(p, o) Level43_89640F(p, unsigned short*, o)
#define Level43_89640Owner()                           \
    ({                                                 \
        phasePointerOrLowWord24 = originalFrame.owner; \
        Level43_89640KEEP(phasePointerOrLowWord24);    \
        phasePointerOrLowWord24;                       \
    })
#define Level43_89640KEEP(v) __asm__("" : "=r"(v) : "0"(v))
extern short Level43_89640Cos[] __asm__("D_80065920"), Level43_89640Sin[] __asm__("D_800658A0");
extern int Level43_89640Counter __asm__("D_8006C640");
extern char* (*Level43_89640Particle)(int, int, void*, void*)__asm__("SpawnParticle");
void Level43_89640AddVector_4(void*, void*, void*) __asm__("func_8004F194");
void* Level43_89640H50B00_5(int, int, int, int, int) __asm__("func_80050B00");
void Level43_89640AddVector_6(void*, void*, void*) __asm__("func_8004F194");
void* Level43_89640H50B00_7(int, int, int, int, int) __asm__("func_80050B00");
void Level43_89640H50B88_8(void*) __asm__("func_80050B88");
void Level43_89640H50B88_9(void*) __asm__("func_80050B88");
void Level43_89640DeleteMoby_10(void*) __asm__("func_80055B18");
void func_level_43_80089640(unsigned char* ownerParameter) {
    struct {
        int first[4], second[4];
        unsigned char* owner;
        int pad3C;
        unsigned char* private;
        int pad44;
        unsigned char* parent;
        int pad4C;
        int size, pad54;
        unsigned char* base;
        int pad5C;
        unsigned char* header;
        int pad64;
        unsigned char* table;
        int pad6C;
        short* sin;
        int pad74;
        int heading, pad7C;
        int spill[9], padA4;
    } originalFrame;
    register int cosOffset23 __asm__("$23");
    register unsigned char* phasePointerOrLowWord24 __asm__("$24");
    register unsigned char* pointRecord16 __asm__("$16");
    register int innerIndex17 __asm__("$17");
    register int angleOrCosAddress18 __asm__("$18");
    register int radiusOrSinAddress19 __asm__("$19");
    register int baseIndexOrRadius20 __asm__("$20");
    register int outerIndex21 __asm__("$21");
    register int sinOffsetOrBaseIndex22 __asm__("$22");
    int cosAddressOrSinOffset;
    register int resultOrField2 __asm__("$2"), sampleOrField3 __asm__("$3");
    register int argumentOrAngle4 __asm__("$4"), argumentOrLowWord5 __asm__("$5"),
        argumentOrLowWord6 __asm__("$6"), argumentOrVerticalOffset7 __asm__("$7");
    register int cosAddressMagicOrHigh8 __asm__("$8"), sinAddressMagicOrHigh9 __asm__("$9"),
        phaseIndexOrHigh10 __asm__("$10"), topologyLiteral11 __asm__("$11");
    register unsigned char* headerRecord12 __asm__("$12");
    register short *sinTable11 __asm__("$11"), *cosTableOrMagic13 __asm__("$13");
    register unsigned char* pointBase14 __asm__("$14");
    register unsigned char* topologyBase15 __asm__("$15");
    long long completeSignedProduct;
    int signedHighWord, signedLowWord;
    originalFrame.owner = ownerParameter;
    phasePointerOrLowWord24 = Level43_89640P(ownerParameter, 0);
    originalFrame.private = phasePointerOrLowWord24;
    resultOrField2 = Level43_89640W(phasePointerOrLowWord24, 16);
    resultOrField2 = Level43_89640W(resultOrField2, 0);
    originalFrame.parent = (unsigned char*)resultOrField2;
    Level43_89640B(ownerParameter, 0x41) = 0;
    phasePointerOrLowWord24 = originalFrame.owner;
    sampleOrField3 = Level43_89640B(phasePointerOrLowWord24, 0x48);
    resultOrField2 = 1;
    Level43_89640B(phasePointerOrLowWord24, 0x4C) = 0;
    Level43_89640B(phasePointerOrLowWord24, 0x4D) = 0;
    if (sampleOrField3 == resultOrField2) {
        phasePointerOrLowWord24 = originalFrame.private;
        resultOrField2 = Level43_89640U(phasePointerOrLowWord24, 0) + 300;
        Level43_89640U(phasePointerOrLowWord24, 0) = resultOrField2;
        resultOrField2 = (short)resultOrField2;
        if (resultOrField2 > 2048) {
            resultOrField2 = 2048;
            Level43_89640U(phasePointerOrLowWord24, 0) = resultOrField2;
            phasePointerOrLowWord24 = originalFrame.owner;
            resultOrField2 = 2;
            Level43_89640B(phasePointerOrLowWord24, 0x48) = resultOrField2;
        }
    }
    phasePointerOrLowWord24 = originalFrame.private;
    originalFrame.heading = 0;
    originalFrame.base = ({
        phasePointerOrLowWord24 = Level43_89640P(phasePointerOrLowWord24, 4);
        Level43_89640KEEP(phasePointerOrLowWord24);
        phasePointerOrLowWord24;
    });
    phasePointerOrLowWord24 = originalFrame.private;
    originalFrame.size = ({
        phasePointerOrLowWord24 = (unsigned char*)(int)Level43_89640H(phasePointerOrLowWord24, 0);
        Level43_89640KEEP(phasePointerOrLowWord24);
        (int)phasePointerOrLowWord24;
    });
    phasePointerOrLowWord24 = originalFrame.base;
    outerIndex21 = 0;
    phasePointerOrLowWord24 += 0x43C;
    originalFrame.header = phasePointerOrLowWord24;
    phasePointerOrLowWord24 = originalFrame.base;
    baseIndexOrRadius20 = 0;
    phasePointerOrLowWord24 += 0x47C;
    originalFrame.table = phasePointerOrLowWord24;
    do {
        argumentOrAngle4 = Level43_89640B(Level43_89640Owner(), 0x46);
        Level43_89640KEEP(argumentOrAngle4);
        phasePointerOrLowWord24 = (unsigned char*)originalFrame.heading;
        argumentOrAngle4 += (int)phasePointerOrLowWord24;
        sampleOrField3 = (argumentOrAngle4 & 255) << 1;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(sampleOrField3, "$24");
        phasePointerOrLowWord24 = (unsigned char*)Level43_89640Cos;
        Level43_89640KEEP(phasePointerOrLowWord24);
        resultOrField2 = sampleOrField3 + (int)phasePointerOrLowWord24;
        Level43_89640KEEP(resultOrField2);
        resultOrField2 = *(short*)resultOrField2;
        phasePointerOrLowWord24 = (unsigned char*)originalFrame.size;
        Level43_89640KEEP(phasePointerOrLowWord24);
        completeSignedProduct = (long long)resultOrField2 * (long long)(int)phasePointerOrLowWord24;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        innerIndex17 = 0;
        MATCHING_KEEP_CLOBBER(innerIndex17, "$24");
        phasePointerOrLowWord24 = (unsigned char*)Level43_89640Sin;
        Level43_89640KEEP(phasePointerOrLowWord24);
        sampleOrField3 = sampleOrField3 + (int)phasePointerOrLowWord24;
        Level43_89640KEEP(sampleOrField3);
        resultOrField2 = *(short*)sampleOrField3;
        __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(resultOrField2));
        argumentOrLowWord5 = signedLowWord;
        Level43_89640KEEP(argumentOrLowWord5);
        phasePointerOrLowWord24 = (unsigned char*)originalFrame.size;
        Level43_89640KEEP(phasePointerOrLowWord24);
        angleOrCosAddress18 = 0;
        __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(argumentOrLowWord5));
        completeSignedProduct = (long long)resultOrField2 * (long long)(int)phasePointerOrLowWord24;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        argumentOrAngle4 = ((argumentOrAngle4 + 64) & 255) << 1;
        phasePointerOrLowWord24 = originalFrame.private;
        cosOffset23 = argumentOrLowWord5 >> 12;
        radiusOrSinAddress19 = Level43_89640H(phasePointerOrLowWord24, 2);
        phasePointerOrLowWord24 = (unsigned char*)Level43_89640Sin;
        Level43_89640KEEP(phasePointerOrLowWord24);
        phasePointerOrLowWord24 = (unsigned char*)(argumentOrAngle4 + (int)phasePointerOrLowWord24);
        originalFrame.sin = (short*)phasePointerOrLowWord24;
        phasePointerOrLowWord24 = (unsigned char*)Level43_89640Cos;
        Level43_89640KEEP(phasePointerOrLowWord24);
        cosAddressOrSinOffset = argumentOrAngle4 + (int)phasePointerOrLowWord24;
        __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(cosAddressOrSinOffset));
        sampleOrField3 = signedLowWord;
        Level43_89640KEEP(sampleOrField3);
        sinOffsetOrBaseIndex22 = sampleOrField3 >> 12;
        do {
            sampleOrField3 = (angleOrCosAddress18 & 255) << 1;
            phasePointerOrLowWord24 = (unsigned char*)Level43_89640Cos;
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = sampleOrField3 + (int)phasePointerOrLowWord24;
            originalFrame.first[0] = 0;
            __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "m"(originalFrame.first[0]));
            resultOrField2 = *(short*)resultOrField2;
            phasePointerOrLowWord24 =
                (unsigned char*)Level43_89640Low(resultOrField2, radiusOrSinAddress19);
            Level43_89640KEEP(phasePointerOrLowWord24);
            argumentOrAngle4 = (int)phasePointerOrLowWord24 >> 12;
            originalFrame.first[1] = argumentOrAngle4;
            phasePointerOrLowWord24 = (unsigned char*)Level43_89640Sin;
            Level43_89640KEEP(phasePointerOrLowWord24);
            sampleOrField3 = sampleOrField3 + (int)phasePointerOrLowWord24;
            Level43_89640KEEP(sampleOrField3);
            resultOrField2 = *(short*)sampleOrField3;
            phasePointerOrLowWord24 =
                (unsigned char*)Level43_89640Low(resultOrField2, radiusOrSinAddress19);
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = (int)phasePointerOrLowWord24 >> 12;
            phasePointerOrLowWord24 = (unsigned char*)originalFrame.sin;
            originalFrame.first[2] = resultOrField2;
            resultOrField2 = *(short*)phasePointerOrLowWord24;
            completeSignedProduct = (long long)argumentOrAngle4 * (long long)resultOrField2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            sampleOrField3 = baseIndexOrRadius20 + innerIndex17;
            phasePointerOrLowWord24 = originalFrame.base;
            __asm__("" : "=r"(sampleOrField3) : "0"(sampleOrField3), "r"(phasePointerOrLowWord24));
            resultOrField2 = sampleOrField3 * 12;
            Level43_89640KEEP(resultOrField2);
            pointRecord16 = phasePointerOrLowWord24 + resultOrField2;
            Level43_89640KEEP(pointRecord16);
            __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(pointRecord16));
            phasePointerOrLowWord24 = (unsigned char*)signedLowWord;
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = -(int)phasePointerOrLowWord24;
            resultOrField2 >>= 12;
            Level43_89640W(pointRecord16, 0) = resultOrField2;
            sampleOrField3 = *(short*)cosAddressOrSinOffset;
            resultOrField2 = originalFrame.first[1];
            completeSignedProduct = (long long)resultOrField2 * (long long)sampleOrField3;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            phasePointerOrLowWord24 = originalFrame.owner;
            argumentOrAngle4 = (int)pointRecord16;
            argumentOrLowWord5 = (int)phasePointerOrLowWord24 + 12;
            __asm__(""
                    : "=l"(signedLowWord)
                    : "x"(completeSignedProduct), "r"(argumentOrAngle4), "r"(argumentOrLowWord5));
            phasePointerOrLowWord24 = (unsigned char*)signedLowWord;
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = (int)phasePointerOrLowWord24 >> 12;
            Level43_89640W(pointRecord16, 4) = resultOrField2;
            resultOrField2 = originalFrame.first[2];
            argumentOrLowWord6 = (int)pointRecord16;
            Level43_89640W(pointRecord16, 8) = resultOrField2;
            Level43_89640AddVector_4(argumentOrAngle4, argumentOrLowWord5, argumentOrLowWord6);
            resultOrField2 = Level43_89640W(pointRecord16, 0);
            sampleOrField3 = Level43_89640W(pointRecord16, 4);
            resultOrField2 += cosOffset23;
            sampleOrField3 += sinOffsetOrBaseIndex22;
            Level43_89640W(pointRecord16, 0) = resultOrField2;
            Level43_89640W(pointRecord16, 4) = sampleOrField3;
            if (Level43_89640B(Level43_89640Owner(), 0x48) == 1 && !innerIndex17) {
                argumentOrAngle4 = 1;
                Level43_89640KEEP(innerIndex17);
                argumentOrLowWord5 = 60;
                argumentOrLowWord6 = (int)pointRecord16;
                argumentOrVerticalOffset7 = (int)originalFrame.second;
                sampleOrField3 = (int)Level43_89640Particle;
                __asm__(""
                        : "=r"(sampleOrField3)
                        : "0"(sampleOrField3), "r"(argumentOrAngle4), "r"(argumentOrLowWord5),
                          "r"(argumentOrLowWord6), "r"(argumentOrVerticalOffset7));
                resultOrField2 = 2;
                originalFrame.second[0] = 0;
                originalFrame.second[1] = 0;
                originalFrame.second[2] = resultOrField2;
                sampleOrField3 = ((char* (*)(int, int, void*, void*))sampleOrField3)(
                    argumentOrAngle4, argumentOrLowWord5, argumentOrLowWord6,
                    argumentOrVerticalOffset7);
                if (sampleOrField3) {
                    resultOrField2 = 40;
                    Level43_89640B(sampleOrField3, 10) = resultOrField2;
                }
            }
            innerIndex17++;
            angleOrCosAddress18 += 42;
        } while (innerIndex17 < 6);
        baseIndexOrRadius20 += 6;
        outerIndex21++;
        phasePointerOrLowWord24 = (unsigned char*)originalFrame.heading;
        resultOrField2 = outerIndex21 < 16;
        phasePointerOrLowWord24 += 17;
        originalFrame.heading = (int)phasePointerOrLowWord24;
    } while (resultOrField2);
    outerIndex21 = 0;
    sinAddressMagicOrHigh9 = 0x2AAAAAAB;
    Level43_89640KEEP(sinAddressMagicOrHigh9);
    cosAddressMagicOrHigh8 = (int)0xB60B60B7;
    Level43_89640KEEP(cosAddressMagicOrHigh8);
    argumentOrVerticalOffset7 = 0;
    phasePointerOrLowWord24 = originalFrame.base;
    Level43_89640W(phasePointerOrLowWord24, 0x438) = -1;
    phasePointerOrLowWord24 = originalFrame.header;
    Level43_89640B(phasePointerOrLowWord24, 0) = 25;
    Level43_89640B(phasePointerOrLowWord24, 1) = 25;
    Level43_89640B(phasePointerOrLowWord24, 2) = 50;
    do {
        innerIndex17 = 0;
        do {
            resultOrField2 = innerIndex17 + 1;
            completeSignedProduct = (long long)resultOrField2 * (long long)sinAddressMagicOrHigh9;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            sampleOrField3 = argumentOrVerticalOffset7 + innerIndex17;
            argumentOrLowWord6 = innerIndex17 + 6;
            innerIndex17 = resultOrField2;
            argumentOrLowWord5 = sampleOrField3 * 8;
            argumentOrLowWord6 = argumentOrVerticalOffset7 + argumentOrLowWord6;
            phasePointerOrLowWord24 = originalFrame.table;
            resultOrField2 = innerIndex17 >> 31;
            argumentOrLowWord5 = (int)phasePointerOrLowWord24 + argumentOrLowWord5;
            __asm__(""
                    : "=h"(signedHighWord)
                    : "x"(completeSignedProduct), "r"(argumentOrLowWord5));
            phaseIndexOrHigh10 = signedHighWord;
            Level43_89640KEEP(phaseIndexOrHigh10);
            Level43_89640B(argumentOrLowWord5, 0) = sampleOrField3;
            Level43_89640B(argumentOrLowWord5, 4) = 0;
            __asm__(""
                    : "=r"(argumentOrLowWord6)
                    : "0"(argumentOrLowWord6), "r"(phaseIndexOrHigh10),
                      "m"(Level43_89640B(argumentOrLowWord5, 4)));
            completeSignedProduct =
                (long long)argumentOrLowWord6 * (long long)cosAddressMagicOrHigh8;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            Level43_89640B(argumentOrLowWord5, 5) = 0;
            Level43_89640B(argumentOrLowWord5, 6) = 0;
            Level43_89640B(argumentOrLowWord5, 7) = 0;
            __asm__ volatile(""
                             : "=r"(resultOrField2)
                             : "0"(resultOrField2), "m"(Level43_89640B(argumentOrLowWord5, 5)),
                               "m"(Level43_89640B(argumentOrLowWord5, 6)),
                               "m"(Level43_89640B(argumentOrLowWord5, 7)));
            resultOrField2 = phaseIndexOrHigh10 - resultOrField2;
            argumentOrAngle4 = resultOrField2 * 6;
            argumentOrAngle4 = innerIndex17 - argumentOrAngle4;
            resultOrField2 = argumentOrVerticalOffset7 + argumentOrAngle4;
            argumentOrAngle4 += 6;
            argumentOrAngle4 = argumentOrVerticalOffset7 + argumentOrAngle4;
            __asm__("" : "=h"(signedHighWord) : "x"(completeSignedProduct), "r"(argumentOrAngle4));
            sampleOrField3 = signedHighWord;
            Level43_89640KEEP(sampleOrField3);
            Level43_89640B(argumentOrLowWord5, 1) = resultOrField2;
            resultOrField2 = sampleOrField3 + argumentOrLowWord6;
            __asm__("" : "=r"(argumentOrAngle4) : "0"(argumentOrAngle4), "r"(sampleOrField3));
            completeSignedProduct = (long long)argumentOrAngle4 * (long long)cosAddressMagicOrHigh8;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            resultOrField2 >>= 6;
            sampleOrField3 = argumentOrLowWord6 >> 31;
            resultOrField2 -= sampleOrField3;
            resultOrField2 *= 90;
            argumentOrLowWord6 -= resultOrField2;
            sampleOrField3 = argumentOrAngle4 >> 31;
            Level43_89640B(argumentOrLowWord5, 2) = argumentOrLowWord6;
            __asm__(""
                    : "=h"(signedHighWord)
                    : "x"(completeSignedProduct), "m"(Level43_89640B(argumentOrLowWord5, 2)));
            phaseIndexOrHigh10 = signedHighWord;
            Level43_89640KEEP(phaseIndexOrHigh10);
            resultOrField2 = phaseIndexOrHigh10 + argumentOrAngle4;
            resultOrField2 >>= 6;
            resultOrField2 -= sampleOrField3;
            resultOrField2 *= 90;
            argumentOrAngle4 -= resultOrField2;
            Level43_89640B(argumentOrLowWord5, 3) = argumentOrAngle4;
        } while (innerIndex17 < 6);
        outerIndex21++;
        argumentOrVerticalOffset7 += 6;
    } while (outerIndex21 < 15);
    Level43_89640W(phasePointerOrLowWord24, 0x2D0) = -1;
    phasePointerOrLowWord24 = originalFrame.private;
    if (!Level43_89640W(phasePointerOrLowWord24, 8)) {
        argumentOrAngle4 = (int)originalFrame.base;
        argumentOrLowWord5 = (int)originalFrame.header;
        argumentOrLowWord6 = (int)originalFrame.table;
        phasePointerOrLowWord24 = originalFrame.parent;
        resultOrField2 =
            Level43_89640H50B00_5(argumentOrAngle4, argumentOrLowWord5, argumentOrLowWord6,
                                  (int)phasePointerOrLowWord24 + 12, 1);
        phasePointerOrLowWord24 = originalFrame.private;
        Level43_89640W(phasePointerOrLowWord24, 8) = resultOrField2;
    }
    outerIndex21 = 0;
    sinTable11 = Level43_89640Sin;
    cosTableOrMagic13 = Level43_89640Cos;
    phasePointerOrLowWord24 = originalFrame.private;
    sinOffsetOrBaseIndex22 = 0;
    resultOrField2 = Level43_89640W(phasePointerOrLowWord24, 4);
    phaseIndexOrHigh10 = 0;
    pointBase14 = (unsigned char*)resultOrField2 + 0x758;
    headerRecord12 = (unsigned char*)resultOrField2 + 0xB94;
    topologyBase15 = (unsigned char*)resultOrField2 + 0xBD4;
    Level43_89640KEEP(topologyBase15);
    do {
        sampleOrField3 = Level43_89640Counter;
        phasePointerOrLowWord24 = originalFrame.private;
        resultOrField2 = sampleOrField3 * 20;
        resultOrField2 = phaseIndexOrHigh10 + resultOrField2;
        resultOrField2 = (resultOrField2 & 255) << 1;
        resultOrField2 += (int)sinTable11;
        sampleOrField3 = *(short*)resultOrField2;
        resultOrField2 = Level43_89640H(phasePointerOrLowWord24, 0x16);
        completeSignedProduct = (long long)sampleOrField3 * (long long)resultOrField2;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        phasePointerOrLowWord24 = originalFrame.owner;
        __asm__("" : "=r"(outerIndex21) : "0"(outerIndex21), "r"(phasePointerOrLowWord24));
        resultOrField2 = outerIndex21 * 17;
        Level43_89640KEEP(resultOrField2);
        argumentOrAngle4 = Level43_89640B(phasePointerOrLowWord24, 0x46);
        phasePointerOrLowWord24 = (unsigned char*)originalFrame.size;
        Level43_89640KEEP(phasePointerOrLowWord24);
        argumentOrAngle4 += resultOrField2;
        sampleOrField3 = (argumentOrAngle4 & 255) << 1;
        resultOrField2 = sampleOrField3 + (int)sinTable11;
        Level43_89640KEEP(resultOrField2);
        __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(resultOrField2));
        argumentOrLowWord6 = signedLowWord;
        Level43_89640KEEP(argumentOrLowWord6);
        resultOrField2 = *(short*)resultOrField2;
        __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(argumentOrLowWord6));
        completeSignedProduct = (long long)resultOrField2 * (long long)(int)phasePointerOrLowWord24;
        sampleOrField3 = sampleOrField3 + (int)cosTableOrMagic13;
        Level43_89640KEEP(sampleOrField3);
        __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(sampleOrField3));
        argumentOrLowWord5 = signedLowWord;
        Level43_89640KEEP(argumentOrLowWord5);
        resultOrField2 = *(short*)sampleOrField3;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(resultOrField2, "$17");
        innerIndex17 = 0;
        __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(argumentOrLowWord5));
        completeSignedProduct = (long long)resultOrField2 * (long long)(int)phasePointerOrLowWord24;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        radiusOrSinAddress19 = (int)sinTable11;
        angleOrCosAddress18 = (int)cosTableOrMagic13;
        argumentOrAngle4 = ((argumentOrAngle4 + 64) & 255) << 1;
        sinAddressMagicOrHigh9 = argumentOrAngle4 + (int)sinTable11;
        cosAddressMagicOrHigh8 = argumentOrAngle4 + (int)cosTableOrMagic13;
        argumentOrVerticalOffset7 = argumentOrLowWord6 >> 12;
        phasePointerOrLowWord24 = originalFrame.private;
        cosAddressOrSinOffset = argumentOrLowWord5 >> 12;
        baseIndexOrRadius20 = Level43_89640H(phasePointerOrLowWord24, 0x14);
        __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(baseIndexOrRadius20));
        sampleOrField3 = signedLowWord;
        Level43_89640KEEP(sampleOrField3);
        cosOffset23 = sampleOrField3 >> 12;
        do {
            originalFrame.first[0] = 0;
            resultOrField2 = *(short*)angleOrCosAddress18;
            phasePointerOrLowWord24 =
                (unsigned char*)Level43_89640Low(resultOrField2, baseIndexOrRadius20);
            Level43_89640KEEP(phasePointerOrLowWord24);
            sampleOrField3 = (int)phasePointerOrLowWord24 >> 12;
            originalFrame.first[1] = sampleOrField3;
            resultOrField2 = *(short*)radiusOrSinAddress19;
            phasePointerOrLowWord24 =
                (unsigned char*)Level43_89640Low(resultOrField2, baseIndexOrRadius20);
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = (int)phasePointerOrLowWord24 >> 12;
            originalFrame.first[2] = resultOrField2;
            resultOrField2 = *(short*)sinAddressMagicOrHigh9;
            completeSignedProduct = (long long)sampleOrField3 * (long long)resultOrField2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            resultOrField2 = sinOffsetOrBaseIndex22 + innerIndex17;
            Level43_89640KEEP(resultOrField2);
            pointRecord16 = pointBase14 + resultOrField2 * 12;
            Level43_89640KEEP(pointRecord16);
            __asm__("" : "=l"(signedLowWord) : "x"(completeSignedProduct), "r"(pointRecord16));
            phasePointerOrLowWord24 = (unsigned char*)signedLowWord;
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = -(int)phasePointerOrLowWord24;
            resultOrField2 >>= 12;
            Level43_89640W(pointRecord16, 0) = resultOrField2;
            sampleOrField3 = *(short*)cosAddressMagicOrHigh8;
            resultOrField2 = originalFrame.first[1];
            completeSignedProduct = (long long)resultOrField2 * (long long)sampleOrField3;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            angleOrCosAddress18 += 84;
            argumentOrAngle4 = (int)pointRecord16;
            phasePointerOrLowWord24 = originalFrame.owner;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(phasePointerOrLowWord24, "$6");
            argumentOrLowWord6 = (int)pointRecord16;
            argumentOrLowWord5 = (int)phasePointerOrLowWord24 + 12;
            __asm__(""
                    : "=l"(signedLowWord)
                    : "x"(completeSignedProduct), "r"(argumentOrAngle4), "r"(argumentOrLowWord6),
                      "r"(angleOrCosAddress18));
            phasePointerOrLowWord24 = (unsigned char*)signedLowWord;
            Level43_89640KEEP(phasePointerOrLowWord24);
            resultOrField2 = (int)phasePointerOrLowWord24 >> 12;
            Level43_89640W(pointRecord16, 4) = resultOrField2;
            resultOrField2 = originalFrame.first[2];
            innerIndex17++;
            Level43_89640W(pointRecord16, 8) = resultOrField2;
            originalFrame.spill[0] = argumentOrVerticalOffset7;
            originalFrame.spill[1] = cosAddressMagicOrHigh8;
            originalFrame.spill[2] = sinAddressMagicOrHigh9;
            originalFrame.spill[3] = phaseIndexOrHigh10;
            originalFrame.spill[4] = (int)sinTable11;
            originalFrame.spill[5] = (int)headerRecord12;
            originalFrame.spill[6] = (int)cosTableOrMagic13;
            originalFrame.spill[7] = (int)pointBase14;
            originalFrame.spill[8] = (int)topologyBase15;
            Level43_89640AddVector_6(argumentOrAngle4, argumentOrLowWord5, argumentOrLowWord6);
            resultOrField2 = Level43_89640W(pointRecord16, 0);
            Level43_89640KEEP(resultOrField2);
            resultOrField2 += cosOffset23;
            Level43_89640W(pointRecord16, 0) = resultOrField2;
            resultOrField2 = Level43_89640W(pointRecord16, 4);
            sampleOrField3 = Level43_89640W(pointRecord16, 8);
            resultOrField2 += cosAddressOrSinOffset;
            Level43_89640W(pointRecord16, 4) = resultOrField2;
            argumentOrVerticalOffset7 = originalFrame.spill[0];
            resultOrField2 = innerIndex17 < 6;
            sampleOrField3 += argumentOrVerticalOffset7;
            Level43_89640W(pointRecord16, 8) = sampleOrField3;
            cosAddressMagicOrHigh8 = originalFrame.spill[1];
            sinAddressMagicOrHigh9 = originalFrame.spill[2];
            phaseIndexOrHigh10 = originalFrame.spill[3];
            sinTable11 = (short*)originalFrame.spill[4];
            headerRecord12 = (unsigned char*)originalFrame.spill[5];
            cosTableOrMagic13 = (short*)originalFrame.spill[6];
            pointBase14 = (unsigned char*)originalFrame.spill[7];
            topologyBase15 = (unsigned char*)originalFrame.spill[8];
            __asm__(""
                    : "=r"(radiusOrSinAddress19)
                    : "0"(radiusOrSinAddress19), "r"(cosAddressMagicOrHigh8),
                      "r"(sinAddressMagicOrHigh9), "r"(phaseIndexOrHigh10), "r"(sinTable11),
                      "r"(headerRecord12), "r"(cosTableOrMagic13), "r"(pointBase14),
                      "r"(topologyBase15));
            radiusOrSinAddress19 += 84;
        } while (resultOrField2);
        sinOffsetOrBaseIndex22 += 6;
        outerIndex21++;
        phaseIndexOrHigh10 += 80;
    } while (outerIndex21 < 16);
    outerIndex21 = 0;
    cosTableOrMagic13 = (short*)(int)0xB60B60B7;
    Level43_89640KEEP(cosTableOrMagic13);
    topologyLiteral11 = 2;
    phaseIndexOrHigh10 = 0;
    Level43_89640W(pointBase14, 0x438) = -1;
    Level43_89640B(headerRecord12, 0) = 150;
    Level43_89640B(headerRecord12, 1) = 150;
    Level43_89640B(headerRecord12, 2) = 150;
    Level43_89640B(headerRecord12, 4) = 70;
    Level43_89640B(headerRecord12, 5) = 70;
    Level43_89640B(headerRecord12, 6) = 70;
    Level43_89640B(headerRecord12, 8) = 20;
    Level43_89640B(headerRecord12, 9) = 20;
    Level43_89640B(headerRecord12, 10) = 20;
    do {
        innerIndex17 = 0;
        do {
            resultOrField2 = 0x55555556;
            completeSignedProduct = (long long)innerIndex17 * (long long)resultOrField2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            resultOrField2 = 0x2AAA0000;
            Level43_89640KEEP(resultOrField2);
            __asm__("" : "=h"(signedHighWord) : "x"(completeSignedProduct), "r"(resultOrField2));
            cosAddressMagicOrHigh8 = signedHighWord;
            Level43_89640KEEP(cosAddressMagicOrHigh8);
            __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(cosAddressMagicOrHigh8));
            resultOrField2 |= 0xAAAB;
            argumentOrAngle4 = innerIndex17 + 1;
            __asm__(""
                    : "=r"(argumentOrAngle4)
                    : "0"(argumentOrAngle4), "r"(cosAddressMagicOrHigh8));
            completeSignedProduct = (long long)argumentOrAngle4 * (long long)resultOrField2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            sampleOrField3 = phaseIndexOrHigh10 + innerIndex17;
            argumentOrLowWord5 = innerIndex17 + 6;
            argumentOrLowWord5 = phaseIndexOrHigh10 + argumentOrLowWord5;
            resultOrField2 = sampleOrField3 * 8;
            argumentOrLowWord6 = (int)topologyBase15 + resultOrField2;
            resultOrField2 = innerIndex17 >> 31;
            argumentOrVerticalOffset7 = cosAddressMagicOrHigh8 - resultOrField2;
            __asm__(""
                    : "=h"(signedHighWord)
                    : "x"(completeSignedProduct), "r"(argumentOrVerticalOffset7));
            sinAddressMagicOrHigh9 = signedHighWord;
            Level43_89640KEEP(sinAddressMagicOrHigh9);
            resultOrField2 = argumentOrVerticalOffset7 * 3;
            __asm__(""
                    : "=r"(argumentOrLowWord5)
                    : "0"(argumentOrLowWord5), "r"(sinAddressMagicOrHigh9));
            completeSignedProduct =
                (long long)argumentOrLowWord5 * (long long)(int)cosTableOrMagic13;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            argumentOrVerticalOffset7 = innerIndex17 - resultOrField2;
            Level43_89640B(argumentOrLowWord6, 0) = sampleOrField3;
            sampleOrField3 = argumentOrAngle4 >> 31;
            sampleOrField3 = sinAddressMagicOrHigh9 - sampleOrField3;
            resultOrField2 = sampleOrField3 * 6;
            argumentOrAngle4 -= resultOrField2;
            resultOrField2 = phaseIndexOrHigh10 + argumentOrAngle4;
            argumentOrAngle4 += 6;
            argumentOrAngle4 = phaseIndexOrHigh10 + argumentOrAngle4;
            __asm__("" : "=h"(signedHighWord) : "x"(completeSignedProduct), "r"(argumentOrAngle4));
            cosAddressMagicOrHigh8 = signedHighWord;
            Level43_89640KEEP(cosAddressMagicOrHigh8);
            sampleOrField3 = argumentOrLowWord5 >> 31;
            Level43_89640B(argumentOrLowWord6, 1) = resultOrField2;
            __asm__(""
                    : "=r"(argumentOrAngle4)
                    : "0"(argumentOrAngle4), "r"(cosAddressMagicOrHigh8));
            completeSignedProduct = (long long)argumentOrAngle4 * (long long)(int)cosTableOrMagic13;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            resultOrField2 = cosAddressMagicOrHigh8 + argumentOrLowWord5;
            resultOrField2 >>= 6;
            resultOrField2 -= sampleOrField3;
            resultOrField2 *= 90;
            argumentOrLowWord5 -= resultOrField2;
            sampleOrField3 = argumentOrAngle4 >> 31;
            Level43_89640B(argumentOrLowWord6, 2) = argumentOrLowWord5;
            __asm__(""
                    : "=h"(signedHighWord)
                    : "x"(completeSignedProduct), "m"(Level43_89640B(argumentOrLowWord6, 2)));
            sinAddressMagicOrHigh9 = signedHighWord;
            Level43_89640KEEP(sinAddressMagicOrHigh9);
            resultOrField2 = sinAddressMagicOrHigh9 + argumentOrAngle4;
            resultOrField2 >>= 6;
            resultOrField2 -= sampleOrField3;
            resultOrField2 *= 90;
            argumentOrAngle4 -= resultOrField2;
            Level43_89640B(argumentOrLowWord6, 3) = argumentOrAngle4;
            if (!argumentOrVerticalOffset7) {
                Level43_89640B(argumentOrLowWord6, 4) = 0;
                Level43_89640B(argumentOrLowWord6, 5) = topologyLiteral11;
                Level43_89640B(argumentOrLowWord6, 6) = 0;
                Level43_89640B(argumentOrLowWord6, 7) = topologyLiteral11;
            } else if (argumentOrVerticalOffset7 == 1) {
                Level43_89640B(argumentOrLowWord6, 4) = topologyLiteral11;
                Level43_89640B(argumentOrLowWord6, 5) = topologyLiteral11;
                Level43_89640B(argumentOrLowWord6, 6) = topologyLiteral11;
                Level43_89640B(argumentOrLowWord6, 7) = topologyLiteral11;
            } else if (argumentOrVerticalOffset7 == topologyLiteral11) {
                Level43_89640B(argumentOrLowWord6, 4) = topologyLiteral11;
                Level43_89640B(argumentOrLowWord6, 5) = 0;
                Level43_89640B(argumentOrLowWord6, 6) = topologyLiteral11;
                Level43_89640B(argumentOrLowWord6, 7) = 0;
            }
            innerIndex17++;
        } while (innerIndex17 < 6);
        outerIndex21++;
        phaseIndexOrHigh10 += 6;
    } while (outerIndex21 < 15);
    Level43_89640W(topologyBase15, 0x2D0) = -1;
    phasePointerOrLowWord24 = originalFrame.private;
    if (!Level43_89640W(phasePointerOrLowWord24, 12)) {
        argumentOrAngle4 = (int)pointBase14;
        argumentOrLowWord5 = (int)headerRecord12;
        argumentOrLowWord6 = (int)topologyBase15;
        phasePointerOrLowWord24 = originalFrame.parent;
        resultOrField2 =
            Level43_89640H50B00_7(argumentOrAngle4, argumentOrLowWord5, argumentOrLowWord6,
                                  (int)phasePointerOrLowWord24 + 12, 1);
        phasePointerOrLowWord24 = originalFrame.private;
        Level43_89640W(phasePointerOrLowWord24, 12) = resultOrField2;
    }
    if (Level43_89640B(Level43_89640Owner(), 0x48) == 2) {
        phasePointerOrLowWord24 = originalFrame.private;
        argumentOrAngle4 = Level43_89640W(phasePointerOrLowWord24, 8);
        if (argumentOrAngle4)
            Level43_89640H50B88_8(argumentOrAngle4);
        phasePointerOrLowWord24 = originalFrame.private;
        argumentOrAngle4 = Level43_89640W(phasePointerOrLowWord24, 12);
        if (argumentOrAngle4)
            Level43_89640H50B88_9(argumentOrAngle4);
        Level43_89640DeleteMoby_10(originalFrame.owner);
    }
}
#undef Level43_89640F
#undef Level43_89640W
#undef Level43_89640P
#undef Level43_89640B
#undef Level43_89640H
#undef Level43_89640U
#undef Level43_89640Owner
#undef Level43_89640KEEP
#undef Level43_89640Low
