#include "matching.h"
#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "spu.h"
#include "savepoint.h"
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
void func_level_46_80074E40(void* input) {
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
void func_level_46_80075A9C(Moby* argument) {
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
void func_level_46_80076128(void* input) {
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
void func_level_46_80077678(Moby* moby) {
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
void func_level_46_80077938(Moby* argument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev 0 source asm/nonmatchings/overlays/level_46/moby/func_level_46_80077E58.s; SHA256 faba8fa3b7de5c8ad37b93b04c22b045011f881674a2353aba8678c945afa258. */
/* AI generated;
 not human reviewed. SCUS-94467 USA Rev0 original417
 * instructions: sibling4768/4767. Units/helper meanings/cadence unresolved. */
#define SharedBurst417Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int SharedBurst417Delta __asm__("D_8006C648");
extern int SharedBurst417Count0 __asm__("D_8006C578"), SharedBurst417Count1 __asm__("D_8006C574");
extern short SharedBurst417Cos[] __asm__("D_80065920"), SharedBurst417Sin[] __asm__("D_800658A0");
extern unsigned char* SharedBurst417Models[] __asm__("D_8006EE2C");
extern unsigned char* (*SharedBurst417Spawn)() __asm__("SpawnMoby");
extern int (*SharedBurst417Particle)() __asm__("SpawnParticle");
int SharedBurst417Rand() __asm__("rand");
int SharedBurst417RandBetween() __asm__("func_8003636C");
int SharedBurst417H37A60() __asm__("func_80037A60");
int SharedBurst417CopyVector() __asm__("func_8004F178");
int SharedBurst417AddVector() __asm__("func_8004F194");
int SharedBurst417H36A68() __asm__("func_80036A68");
int SharedBurst417PlayMobySoundEvent() __asm__("func_8003BABC");
int SharedBurst417DeleteMoby() __asm__("func_80055B18");
#define SharedBurst417High(a, b)                                                     \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
#define SharedBurst417Low(a, b)             \
    ({                                      \
        register int low __asm__("lo");     \
        low = (int)(a) * (int)(b);          \
        __asm__("" : "=l"(low) : "0"(low)); \
        low;                                \
    })
/* Original 417-word function and 0x70-byte frame. Raw table indices,
 * signed HI/LO products and register-width remainders retain the original
 * producer instructions. Empty constraints preserve their scheduling.
 * Physical units, helper meanings and frame cadence remain unresolved. */
void func_level_46_80077E58(void* input) {
    struct {
        int first[4], second[4], third[4];
    } frame;
    register unsigned char* owner __asm__("$21") = input;
    unsigned char* tag;
    register int index17 __asm__("$17");
    register int five18 __asm__("$18");
    register unsigned char* small16 __asm__("$16");
    register int angle0 __asm__("$16");
    register int angle1 __asm__("$17");
    register unsigned char* child20 __asm__("$20");
    register unsigned char* nested22 __asm__("$22");
    register int count23 __asm__("$23");
    register short* cosine0 __asm__("$19");
    register short* cosine1 __asm__("$18");
    register short* sine22 __asm__("$22");
    register int* vector20 __asm__("$20");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register void* arg6 __asm__("$6");
    register void* arg7 __asm__("$7");
    MATCHING_KEEP(owner);
    value = owner[72];
    tag = SharedBurst417Field(owner, unsigned char**, 0);
    if (!value) {
        value = SharedBurst417Field(owner, int*, 24);
        if (value)
            owner[72] = 2;
    }
    other = owner[72];
    value = 1;
    SharedBurst417Field(owner, int*, 24) = 0;
    if (other == value)
        goto state1;
    if (other < 2) {
        if (!other)
            goto state0;
        goto done;
    }
    value = 2;
    call4 = owner;
    if (other == value)
        goto state2;
    goto done;
state0:
    value = tag[0];
    if (!value) {
        tag[0] = 1;
        value = SharedBurst417Field(owner, int*, 20);
        SharedBurst417Field(tag, int*, 4) = value;
    }
    other = SharedBurst417Delta;
    value = tag[1];
    value += other;
    tag[1] = value;
    value &= 255;
    value <<= 1;
    other = *(short*)((unsigned char*)SharedBurst417Sin + value);
    MATCHING_KEEP(other);
    value = other * 5;
    other = (value << 4) - value;
    value = SharedBurst417Field(tag, int*, 4);
    other >>= 10;
    value += other;
    SharedBurst417Field(owner, int*, 20) = value;
    goto done;
state1:
    value = SharedBurst417H37A60(owner, tag + 2, 2, 16, -200);
    if (!value)
        goto done;
    owner[73] = 112;
    index17 = 0;
    five18 = 5;
small_loop:
    value = SharedBurst417Count0;
    other = SharedBurst417Count1;
    value -= other;
    call4 = (void*)631;
    if (value < 21)
        goto small_done;
    small16 = SharedBurst417Spawn(call4, owner);
    call4 = 0;
    if (small16) {
        value = SharedBurst417RandBetween(call4, 300);
        other = SharedBurst417Field(small16, int*, 20);
        other += value;
        value = index17 < 6;
        SharedBurst417Field(small16, int*, 20) = other;
        if (value)
            small16[73] = five18;
    }
    index17++;
    if (index17 < 16)
        goto small_loop;
small_done:
    index17 = 0;
    call4 = frame.first;
first_particles:
    SharedBurst417CopyVector(call4, owner + 12);
    index17++;
    value = SharedBurst417Rand();
    other = frame.first[0];
    value &= 255;
    other += 128;
    other -= value;
    frame.first[0] = other;
    value = SharedBurst417Rand();
    other = frame.first[1];
    value &= 255;
    other += 128;
    other -= value;
    frame.first[1] = other;
    value = SharedBurst417Rand();
    call4 = (void*)1;
    arg5 = 2;
    arg6 = frame.first;
    arg7 = 0;
    MATCHING_KEEP5(call4, arg5, arg6, arg7, value);
    value &= 511;
    other = frame.first[2];
    other += value;
    frame.first[2] = other;
    SharedBurst417Particle(call4, arg5, arg6, arg7);
    SharedBurst417Particle(4, 70, frame.first, 24);
    value = index17 < 4;
    call4 = frame.first;
    if (value)
        goto first_particles;
    SharedBurst417H36A68(owner, 0, 0, 0);
    SharedBurst417PlayMobySoundEvent(owner, 1, 0);
    SharedBurst417DeleteMoby(owner);
    goto done;
state2:
    SharedBurst417PlayMobySoundEvent(call4, 0, 0);
    count23 = 0;
child_loop:
    value = SharedBurst417Count0;
    other = SharedBurst417Count1;
    value -= other;
    call4 = (void*)630;
    if (value < 21)
        goto child_done;
    child20 = SharedBurst417Spawn(call4, owner);
    nested22 = SharedBurst417Field(child20, unsigned char**, 0);
    MATCHING_KEEP2(child20, nested22);
    if (!child20)
        goto child_next;
    angle0 = SharedBurst417Rand();
    angle1 = SharedBurst417Rand();
    value = SharedBurst417Rand();
    other = 0x55555556;
    MATCHING_KEEP(other);
    {
        register int quotient9 __asm__("$9");
        quotient9 = SharedBurst417High(value, other);
        call4 = (void*)(value >> 31);
        angle0 = (angle0 & 255) << 1;
        angle1 = (angle1 & 255) << 1;
        __asm__("" : "=r"(quotient9) : "0"(quotient9), "r"(angle1));
        call4 = (void*)(quotient9 - (int)call4);
    }
    value -= (int)call4 * 3;
    {
        register short* table9 __asm__("$9");
        register int product9 __asm__("$9");
        __asm__ volatile("" : : "r"(value) : "memory", "$9");
        table9 = SharedBurst417Cos;
        cosine0 = (short*)(angle0 + (int)table9);
        child20[60] = value;
        other = *cosine0;
        cosine1 = (short*)(angle1 + (int)table9);
        value = other * 25;
        other = *cosine1;
        value >>= 7;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        value = product9 >> 12;
        table9 = SharedBurst417Sin;
        angle0 += (int)table9;
        SharedBurst417Field(child20, int*, 12) = value;
        other = *(short*)angle0;
        value = other * 25;
        other = *cosine1;
        value >>= 7;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        arg6 = owner + 12;
        call4 = child20 + 12;
        value = product9 >> 12;
        table9 = SharedBurst417Sin;
        angle1 += (int)table9;
        SharedBurst417Field(child20, int*, 16) = value;
        other = *(short*)angle1;
        arg5 = (int)call4;
        value = other * 25;
        value >>= 7;
        SharedBurst417Field(child20, int*, 20) = value;
        SharedBurst417AddVector(call4, (void*)arg5, arg6);
        value = SharedBurst417Field(child20, int*, 20);
        value += 2000;
        SharedBurst417Field(child20, int*, 20) = value;
        other = *cosine0;
        value = other * 25;
        other = *cosine1;
        value >>= 10;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        value = product9 >> 12;
        SharedBurst417Field(nested22, short*, 0) = value;
        other = *(short*)angle0;
        value = other * 25;
        other = *cosine1;
        value >>= 10;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)30;
        value = product9 >> 12;
        SharedBurst417Field(nested22, short*, 2) = value;
        other = *(short*)angle1;
        arg5 = 60;
        value = other * 25;
        value >>= 10;
        SharedBurst417Field(nested22, short*, 4) = value;
        value = SharedBurst417RandBetween(call4, arg5);
        SharedBurst417Field(nested22, int*, 12) = value;
    }
child_next:
    count23++;
    if (count23 < 16)
        goto child_loop;
child_done:
    count23 = 0;
    sine22 = SharedBurst417Sin;
    vector20 = frame.second;
particle_loop:
    count23++;
    angle0 = SharedBurst417Rand();
    value = SharedBurst417Rand();
    call4 = (void*)200;
    arg5 = 1100;
    MATCHING_KEEP2(call4, arg5);
    angle1 = value;
    value = SharedBurst417RandBetween(call4, arg5);
    {
        register short* table9 __asm__("$9");
        register int product9 __asm__("$9");
        angle0 = (angle0 & 255) << 1;
        table9 = SharedBurst417Cos;
        cosine0 = (short*)(angle0 + (int)table9);
        other = *cosine0;
        MATCHING_KEEP(other);
        value &= 255;
        {
            register int heldLow __asm__("lo");
            heldLow = other * value;
            __asm__("" : "=l"(heldLow), "=r"(angle1) : "0"(heldLow), "1"(angle1));
            angle1 = (angle1 & 255) << 1;
            cosine1 = (short*)(angle1 + (int)table9);
            product9 = heldLow;
            MATCHING_KEEP_CLOBBER(product9, "memory");
        }
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        angle0 += (int)sine22;
        other = product9 >> 12;
        frame.second[0] = other;
        other = *(short*)angle0;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        angle1 += (int)sine22;
        other = product9 >> 12;
        frame.second[1] = other;
        other = *(short*)angle1;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        arg5 = (int)vector20;
        MATCHING_KEEP(arg5);
        arg6 = owner + 12;
        call4 = vector20;
        value = product9 >> 12;
        frame.second[2] = value;
        SharedBurst417AddVector(call4, (void*)arg5, arg6);
        call4 = (void*)40;
        value = frame.second[2];
        arg5 = 70;
        value += 2000;
        frame.second[2] = value;
        value = SharedBurst417RandBetween(call4, arg5);
        other = *cosine0;
        value &= 255;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        other = product9 >> 12;
        frame.third[0] = other;
        other = *(short*)angle0;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        other = product9 >> 12;
        frame.third[1] = other;
        other = *(short*)angle1;
        product9 = SharedBurst417Low(other, value);
        arg5 = 0;
        MATCHING_KEEP_CLOBBER(arg5, "$6");
        arg6 = vector20;
        arg7 = frame.third;
        call4 = (void*)1;
        {
            register int (*route3)() __asm__("$3") = SharedBurst417Particle;
            __asm__("" : "=r"(product9) : "0"(product9), "r"(route3));
            value = product9 >> 12;
            frame.third[2] = value;
            route3(call4, arg5, arg6, arg7);
        }
    }
    value = count23 < 20;
    other = 1;
    if (value)
        goto particle_loop;
    SharedBurst417Field(tag, short*, 2) = 0;
    value = SharedBurst417Field(owner, short*, 54);
    owner[72] = other;
    value = **(unsigned char**)(SharedBurst417Models[value] + 64);
    owner[60] = other;
    owner[61] = other;
    owner[62] = 0;
    owner[63] = other;
    value = (unsigned)value >= 2;
    MATCHING_KEEP(value);
    value = -value & 48;
    owner[64] = value;
done:;
}
#undef SharedBurst417Field


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
void func_level_46_800784DC(Moby* moby) {
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
void func_level_46_800787E0(void* input) {
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
void func_level_46_80079354(Moby* moby) {
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
void func_level_46_80079784(Moby* owner) {
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

extern int D_8006C770;
void func_level_46_80079910(Moby* moby) {
    if ((moby->damageFlags & 0x2020000) && moby->state != 1) {
        moby->state = 1;
        func_80034F40(moby, 1);
    }
    moby->damageFlags = 0;
    switch (moby->state) {
        case 0:
            break;
        case 1:
            if (D_8006C770) {
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
    }
}

extern int (*Controller780F0Spawn)(int, int, void*, void*) __asm__("SpawnParticle");
extern int (*Controller780F0Header)(void*, int) __asm__("unk_ovlheader_80074324");
#define Controller780F0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller780F0Sin[] __asm__("D_800658A0");
extern unsigned char Controller780F0Cos[] __asm__("D_80065920");
extern unsigned short Controller780F0Angle0 __asm__("D_8006E03E"), Controller780F0Angle1
    __asm__("D_8006E040");
int Controller780F0Helper18368(void*, void*) __asm__("func_80018368");
int Controller780F0CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller780F0CopyVector(void*, void*) __asm__("func_8004F178");
int Controller780F0AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller780F0DeleteMoby() __asm__("func_80055B18");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level25/800780F0, level32/8008A7EC, level35/800787C8,
 * level45/8007884C, level46/800799A0 and level50/80085A60, moby text.
 * Every copy has 292 original instructions and six dispatch entries with
 * relative targets 364, 400, 540, 608, 908 and 1004 bytes. Helper and global
 * symbols were compared separately before reusing this body.
 * Preserve byte colour loads, packed word store, signed decrement/clamp -64,
 * table byte offsets and signed shifts, branch-specific countdown rereads,
 * six state paths and callback arguments. The initial removal path supplies
 * the original incoming argument register implicitly; later removal explicitly
 * prepares owner and still reaches the shared final stores.
 * Units, fixed-point meanings, helper contracts and caller cadence remain
 * unresolved; updates below are once per invocation. No runtime semantics inferred.
 * Confidence: exact native and linked instructions/data. Falsifiable vectors:
 * every original word and complete retail executable/overlay SHA checks.
 * Empty constraints preserve compiler scheduling and distinct original calls;
 * they contain no opcode patches.
 */
void func_level_46_800799A0(void* input) {
    register unsigned char* owner __asm__("$16") = input;
    Vector3D previous;
    unsigned char color[4];
    int pad20;
    unsigned char first[3];
    int pad28;
    unsigned char second[3];
    int nextVerticalWord;
    int initialCountdown;
    register int firstWeight __asm__("$3");
    register int secondWeight __asm__("$4");
    int helperResult;
    register int blendLimit __asm__("$2");
    register int belowBlendLimit __asm__("$2");
    unsigned char decrementedByte;
    unsigned int state;
    unsigned char nextByte;
    register unsigned char* tag __asm__("$17");
    register unsigned char* position __asm__("$18");
    register unsigned char* countdownArgument __asm__("$4");

    MATCHING_KEEP(owner);
    tag = Controller780F0Field(owner, void**, 0);
    color[0] = Controller780F0Field(tag, unsigned char*, 0xC);
    color[1] = Controller780F0Field(tag, unsigned char*, 0xD);
    color[2] = Controller780F0Field(tag, unsigned char*, 0xE);
    color[3] = Controller780F0Field(tag, unsigned char*, 0xF);
    state = Controller780F0Field(owner, unsigned char*, 0x48);

    if (state != 5) {
        position = owner + 0xC;
        if (Controller780F0Field(owner, unsigned char*, 0x4D) == 0) {
            Controller780F0DeleteMoby();
            return;
        }
        Controller780F0CopyVector(&previous, position);
        nextVerticalWord = Controller780F0Field(tag, int*, 8) - 2;
        Controller780F0Field(tag, int*, 8) = nextVerticalWord;
        if (nextVerticalWord < -0x40) {
            Controller780F0Field(tag, int*, 8) = -0x40;
        }
        Controller780F0AddVector(position, position, tag);
        Controller780F0Spawn(4, 0x54, position, tag + 0xC);
        initialCountdown = Controller780F0Field(tag, int*, 0x10);
        if (initialCountdown < 0x20) {
            {
                register int left __asm__("$3") = initialCountdown;
                register int right __asm__("$2") = Controller780F0Field(tag, unsigned char*, 0xC);
                register int product __asm__("$8");
                register int shifted __asm__("$2");
                MATCHING_KEEP2(left, right);
                product = left * right;
                MATCHING_KEEP_CLOBBER(product, "$2");
                shifted = product >> 5;
                MATCHING_KEEP(shifted);
                color[0] = shifted;
            }
            {
                register int right __asm__("$3") = Controller780F0Field(tag, unsigned char*, 0xD);
                register int left __asm__("$2") = Controller780F0Field(tag, int*, 0x10);
                register int product __asm__("$8");
                register int shifted __asm__("$2");
                MATCHING_KEEP2(left, right);
                product = left * right;
                MATCHING_KEEP_CLOBBER(product, "$2");
                shifted = product >> 5;
                MATCHING_KEEP(shifted);
                color[1] = shifted;
            }
            {
                register int right __asm__("$3") = Controller780F0Field(tag, unsigned char*, 0xE);
                register int left __asm__("$2") = Controller780F0Field(tag, int*, 0x10);
                register int product __asm__("$8");
                register int shifted __asm__("$2");
                MATCHING_KEEP2(left, right);
                product = left * right;
                MATCHING_KEEP_CLOBBER(product, "$2");
                shifted = product >> 5;
                MATCHING_KEEP(shifted);
                color[2] = shifted;
            }
        }
        state = Controller780F0Field(owner, unsigned char*, 0x48);

        goto dispatch;
    }
dispatch:
    {
        switch (state) {
            case 0:
                helperResult = Controller780F0CountTimerDown(tag + 0x10, 4);
                MATCHING_BARRIER_VOLATILE("$8");
                if (helperResult)
                    goto removeOwner;
                helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                MATCHING_BARRIER_VOLATILE("$12");
                goto testResult;
            case 1:
                Controller780F0Field(owner, int*, 0xC) =
                    (int)(Controller780F0Field(owner, int*, 0xC) +
                          ((int)(*(unsigned short*)(Controller780F0Cos +
                                                    (((Controller780F0Field(tag, int*, 0x10) +
                                                       Controller780F0Field(owner, unsigned char*,
                                                                            0x49))
                                                      << 5) &
                                                     0x1E0))
                                 << 0x10) >>
                           0x16));
                Controller780F0Field(owner, int*, 0x10) =
                    (int)(Controller780F0Field(owner, int*, 0x10) +
                          ((int)(*(unsigned short*)(Controller780F0Sin +
                                                    (((Controller780F0Field(tag, int*, 0x10) +
                                                       Controller780F0Field(owner, unsigned char*,
                                                                            0x49))
                                                      << 5) &
                                                     0x1E0))
                                 << 0x10) >>
                           0x16));
                helperResult = Controller780F0CountTimerDown(tag + 0x10, 4);
                MATCHING_BARRIER_VOLATILE("$9");
                if (helperResult == 0) {
                    helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                    MATCHING_BARRIER_VOLATILE("$13");
                    goto testResult;
                }
                goto removeOwner;
            case 2:
                if (Controller780F0Helper18368(&previous, owner + 0xC) == 0) {
                    if (Controller780F0CountTimerDown(tag + 0x10, 4) != 0) {
                        Controller780F0Header(owner, -1);
                        goto removeOwner;
                    }
                } else {
                    goto removeOwner;
                }
                break;
            case 3:
                if (Controller780F0Field(tag, int*, 0x10) < 0x20) {
                    {
                        register int full __asm__("$3") = 255;
                        register int byteWord __asm__("$2") = 32;
                        MATCHING_KEEP2(full, byteWord);
                        second[0] = byteWord;
                        byteWord = 64;
                        first[0] = 0;
                        first[1] = full;
                        first[2] = 0;
                        second[1] = byteWord;
                        second[2] = full;
                    }
                    firstWeight = Controller780F0Field(tag, int*, 0x10);
                    MATCHING_KEEP_CLOBBER(firstWeight, "$2");
                    blendLimit = 0x20;
                } else {
                    {
                        register int full __asm__("$2") = 255;
                        MATCHING_KEEP(full);
                        first[0] = full;
                        first[1] = 0;
                        first[2] = 0;
                        second[0] = 0;
                        second[1] = full;
                        second[2] = 0;
                    }
                    firstWeight = Controller780F0Field(tag, int*, 0x10);
                    MATCHING_KEEP_CLOBBER(firstWeight, "$2");
                    blendLimit = 0x38;
                }
                secondWeight = blendLimit - firstWeight;
                belowBlendLimit = secondWeight < 9;
                if (secondWeight < 0) {
                    secondWeight = 0;
                    MATCHING_KEEP(secondWeight);
                    belowBlendLimit = secondWeight < 9;
                    MATCHING_KEEP(belowBlendLimit);
                }
                if (belowBlendLimit == 0) {
                    secondWeight = 8;
                }
                firstWeight = 8;
                {
                    register int firstByte __asm__("$2") = first[0];
                    register int firstProduct __asm__("$5");
                    register int secondByte __asm__("$2");
                    register int secondProduct __asm__("$9");
                    register int sum __asm__("$2");
                    MATCHING_KEEP2(firstByte, firstWeight);
                    firstWeight -= secondWeight;
                    MATCHING_KEEP2(firstByte, firstWeight);
                    firstProduct = firstWeight * firstByte;
                    MATCHING_KEEP_CLOBBER(firstProduct, "$2");
                    secondByte = second[0];
                    MATCHING_KEEP(secondByte);
                    secondProduct = secondWeight * secondByte;
                    MATCHING_KEEP_CLOBBER(secondProduct, "$2");
                    sum = (firstProduct + secondProduct) >> 3;
                    MATCHING_KEEP(sum);
                    Controller780F0Field(tag, unsigned char*, 0xC) = sum;
                }
                {
                    register int firstByte __asm__("$2") = first[1];
                    register int firstProduct __asm__("$5");
                    register int secondByte __asm__("$2");
                    register int secondProduct __asm__("$9");
                    register int sum __asm__("$2");
                    MATCHING_KEEP(firstByte);
                    firstProduct = firstWeight * firstByte;
                    MATCHING_KEEP_CLOBBER(firstProduct, "$2");
                    secondByte = second[1];
                    MATCHING_KEEP(secondByte);
                    secondProduct = secondWeight * secondByte;
                    MATCHING_KEEP_CLOBBER(secondProduct, "$2");
                    sum = (firstProduct + secondProduct) >> 3;
                    MATCHING_KEEP(sum);
                    Controller780F0Field(tag, unsigned char*, 0xD) = sum;
                }
                {
                    register int firstByte __asm__("$2") = first[2];
                    register int firstProduct __asm__("$3");
                    register int secondByte __asm__("$2");
                    register int secondProduct __asm__("$9");
                    register int sum __asm__("$2");
                    MATCHING_KEEP(firstByte);
                    firstProduct = firstWeight * firstByte;
                    MATCHING_KEEP_CLOBBER(firstProduct, "$2");
                    secondByte = second[2];
                    MATCHING_KEEP(secondByte);
                    secondProduct = secondWeight * secondByte;
                    MATCHING_KEEP_CLOBBER(secondProduct, "$2");
                    sum = (firstProduct + secondProduct) >> 3;
                    MATCHING_KEEP(sum);
                    Controller780F0Field(tag, unsigned char*, 0xE) = sum;
                }
                helperResult = Controller780F0CountTimerDown(tag + 0x10, 4);
                MATCHING_BARRIER_VOLATILE("$10");
                if (helperResult == 0) {
                    helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                    MATCHING_BARRIER_VOLATILE("$14");
                    goto testResult;
                }
                goto removeOwner;
            case 4:
                decrementedByte = Controller780F0Field(owner, unsigned char*, 0x49) - 1;
                Controller780F0Field(owner, unsigned char*, 0x49) = decrementedByte;
                MATCHING_BARRIER_VOLATILE("$4");
                countdownArgument = tag + 0x10;

            if (!(decrementedByte & 0xFF)) {
                    Controller780F0Header(owner, -1);
                    MATCHING_KEEP_VOLATILE(tag);
                    Controller780F0Field(owner, unsigned char*, 0x49) = 4U;
                    MATCHING_BARRIER_VOLATILE("$4");
                    countdownArgument = tag + 0x10;

            }
                helperResult = Controller780F0CountTimerDown(countdownArgument, 4);
                MATCHING_BARRIER_VOLATILE("$11");
                if (helperResult == 0) {
                    helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                    MATCHING_BARRIER_VOLATILE("$15");
                    MATCHING_KEEP_VOLATILE(tag);
                    goto testResult;
                }
                goto removeOwner;
            case 5:
                if (Controller780F0Field(owner, unsigned char*, 0x49) == 0) {
                    Controller780F0Field(owner, signed char*, 0x4C) = 0x7F;
                    nextByte = 4;
                } else {
                    Controller780F0Field(owner, signed char*, 0x4C) = 0;
                    Controller780F0Field(owner, unsigned char*, 0x4D) = 0U;
                    nextByte = Controller780F0Field(owner, unsigned char*, 0x49) - 1;
                }
                Controller780F0Field(owner, unsigned char*, 0x49) = nextByte;
                helperResult = Controller780F0CountTimerDown(tag + 0x10, 4);
                goto testResult;
        }
    }
    goto finalTail;
testResult:
    if (helperResult == 0)
        goto finalTail;
removeOwner:
    Controller780F0DeleteMoby(owner);
finalTail:
    Controller780F0Field(owner, signed char*, 0x46) =
        (signed char)(((int)(Controller780F0Angle1 << 0x10) >> 0x14) - 0x80);
    Controller780F0Field(owner, signed char*, 0x45) =
        (signed char)((unsigned short)Controller780F0Angle0 >> 4);
    Controller780F0Field(owner, int*, 0x54) = *(int*)color;
}

#undef Controller780F0Field


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
extern unsigned char P7A6B4D_80071591 __asm__("D_80071591");
extern void* (*P7A6B4SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7A6B4unk_ovlheader_80074318)() __asm__("unk_ovlheader_80074318");
extern int (*P7A6B4unk_ovlheader_80074320)() __asm__("unk_ovlheader_80074320");
extern int (*P7A6B4unk_ovlheader_8007432C)() __asm__("unk_ovlheader_8007432C");
extern unsigned char P7A6B4D_800715B2 __asm__("D_800715B2");
extern unsigned char P7A6B4D_8006C7B4 __asm__("D_8006C7B4");
extern int P7A6B4D_8006C58C __asm__("D_8006C58C");
extern unsigned char P7A6B4D_80070300[] __asm__("D_80070300");
extern unsigned char* P7A6B4D_8006C550 __asm__("D_8006C550");
int P7A6B4func_80053F50(int) __asm__("func_80053F50");
int P7A6B4func_8003B634(void*, void*, int) __asm__("func_8003B634");
/* AI generated; not human reviewed. Original3932 actor46 instructions.
 * Baseline actor44; preserves original byte2/4 selectors and table stride88.
 * Units, helper meanings and caller cadence unresolved. Empty constraints
 * emit no opcodes. Acceptance requires original linked words and all hashes. */
void func_level_46_80079E30(void* input) {
    register void* owner __asm__("$19") = input;
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
    register void* privateState __asm__("$18");
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
            if (P7A6B4Field(privateState, unsigned char*, 2) == 0 && P7A6B4D_800715B2 != 0) {
                P7A6B4Field(privateState, unsigned char*, 2) = 4;
            } else if (P7A6B4Field(privateState, unsigned char*, 2) == 1 &&
                       !(P7A6B4D_8006C7B4 & 1) && !(P7A6B4D_80070300[P7A6B4D_8006C58C] & 1)) {
                P7A6B4Field(privateState, unsigned char*, 2) = 5;
            }
            P7A6B4Field(owner, short*, 0x38) = 0;
            P7A6B4Field(privateState, unsigned char*, 5) = 1;
            if ((P7A6B4D_8006C598 == 0) && (P7A6B4func_80037BBC(owner, 0) != 0)) {
                P7A6B4func_800512E4(owner, 0, 0x12);
                P7A6B4Field(owner, unsigned char*, 0x48) = 0x12;
            }
            break;
        case 18:
            if (P7A6B4D_8006E344 != 1) {
                P7A6B4Field(P7A6B4D_80070328, int*, 0x20C) = 0x10000002;
                if (P7A6B4Field(privateState, unsigned char*, 4) == 2) {
                    P7A6B4func_80053F50(-1);
                    break;
                }
                {
                    register void* originalArg4 __asm__("$4") = P7A6B4D_8006D088;
                    register int originalIndex3 __asm__("$3") =
                        P7A6B4Field(privateState, int*, 0x44);
                    register unsigned char* originalEntry5 __asm__("$5") = P7A6B4D_8006C550;
                    originalEntry5 += originalIndex3 * 88;
                    P7A6B4func_8003B634(originalArg4, originalEntry5 + 12,
                                        P7A6B4Field(originalEntry5, unsigned char*, 0x46));
                }
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
void func_level_46_8007A5F8(Moby* input) {
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
void func_level_46_8007AA04(Moby* moby) {
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

typedef struct {
    unsigned char reserved00[0x34];
    int angle;
    Vector3D point;
} DecodedCheckpointPositionTag;
extern short D_800658A0[], D_80065920[];
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
void func_level_46_8007AAC0(Moby* moby) {
    Vector3D position;
    register void* bounds __asm__("$5") = moby->mobyTag;
    /* Empty constraint retains the retail tag load before argument setup. */
    MATCHING_KEEP(bounds);
    if (func_80036220(&spyro.position, bounds, 0, 0x400)) {
        DecodedCheckpointPositionTag* tag = spyro.critterMobyPtr->mobyTag;
        register int angle __asm__("$17") = tag->angle;
        int state;
        position.x = (D_80065920[angle] * 13) >> 5;
        position.y = (D_800658A0[tag->angle] * 13) >> 5;
        position.z = 0;
        angle -= 0x80;
        MATCHING_KEEP(angle);
        func_8004F194(&position, &position, &tag->point);
        state = spyro.critterMobyPtr->state;
        spyro.critterMobyPtr->state = 0;
        func_8003B7B4(&spyro.critterMobyPtr->state, 1, &unsavedData);
        spyro.critterMobyPtr->state = state;
        func_8003B634(&savedData, &position, angle & 0xFF);
        func_8003B74C(&savedData);
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
void func_level_46_8007ABF0(Moby* moby) {
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
void func_level_46_8007AF20(void* input) {
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

void func_level_46_8007C074(Moby* moby) {
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
void func_level_46_8007C094(Moby* argument) {
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
void func_level_46_8007C294(Moby* argument) {
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
void func_level_46_8007C630(void* input) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * sibling4797:307 instructions. Units/helper meanings/cadence unresolved. */
#define CarrierField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int CarrierPlayer24C __asm__("D_80070328 + 0x24C");
extern int CarrierE020 __asm__("D_8006E020"), CarrierE024 __asm__("D_8006E024"),
    CarrierE044 __asm__("D_8006E044");
extern unsigned short CarrierE040 __asm__("D_8006E040");
extern short CarrierCos[] __asm__("D_80065920"), CarrierSin[] __asm__("D_800658A0");
extern unsigned char* (*CarrierSpawn)() __asm__("SpawnMoby");
int CarrierPlanarHeadingLookup() __asm__("func_8004E880");
int CarrierAbsoluteByteAngleDelta() __asm__("func_8004F264");
int CarrierRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int CarrierTransformVectorByBasis() __asm__("func_8004ED6C");
int CarrierAddVector() __asm__("func_8004F194");
int CarrierSetMobyAnimation() __asm__("func_80034F80");
int CarrierCopyVector() __asm__("func_8004F178");
int CarrierH39714() __asm__("func_80039714");
int CarrierSubtractVector() __asm__("func_8004F1C8");
int CarrierMeasureVectorLength() __asm__("func_8004EDE8");
unsigned char* CarrierH391E8() __asm__("func_800391E8");
int CarrierPlayMobySoundEvent() __asm__("func_8003BABC");
int CarrierH36A68() __asm__("func_80036A68");
int CarrierRequestMobyAnimation() __asm__("func_80034F40");
int CarrierH3BA00() __asm__("func_8003BA00");
int CarrierH369B8() __asm__("func_800369B8");
int CarrierDeleteMoby() __asm__("func_80055B18");
void func_level_46_8007CAA4(void* input) {
    struct {
        int first[4], second[4], third[4];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$19");
    register unsigned char* child __asm__("$18");
    register unsigned char* nested __asm__("$16");
    register int count __asm__("$16");
    register int one __asm__("$21");
    register int twoHundred __asm__("$20");
    register int scale __asm__("$19");
    register int sixtyFour __asm__("$18");
    register int magnitude __asm__("$16");
    register int* vector __asm__("$16");
    register int difference __asm__("$16");
    register int value __asm__("$2"), other __asm__("$3");
    register int call4 __asm__("$4"), arg5 __asm__("$5"), arg6 __asm__("$6");
    MATCHING_KEEP(owner);
    value = owner[76];
    tag = CarrierField(owner, unsigned char**, 0);
    if (!value)
        goto dispatch;
    value = owner[72];
    value = (unsigned)(value - 1) < 2;
    if (!value)
        goto dispatch;
    value = 4;
    other = CarrierPlayer24C;
    if (other != value)
        goto dispatch;
    arg6 = 0;
    other = CarrierField(owner, int*, 12);
    call4 = CarrierE020;
    value = CarrierField(owner, int*, 16);
    arg5 = CarrierE024;
    call4 = other - call4;
    arg5 = value - arg5;
    value = CarrierPlanarHeadingLookup(call4, arg5, arg6);
    call4 = CarrierE040;
    arg5 = value;
    call4 = (short)call4;
    call4 >>= 4;
    value = CarrierAbsoluteByteAngleDelta(call4, arg5);
    value = value < 24;
    if (!value)
        goto contact16;
    value = 31;
    other = CarrierE044;
    if (other != value)
        goto contact16;
    value = owner[76];
    owner[78] = value;
    goto dispatch;
contact16:
    value = 16;
    owner[78] = value;
dispatch:
    other = owner[72];
    value = 2;
    if (other == value)
        goto state2;
    value = other < 3;
    if (!value)
        goto high_state;
    if (!other)
        goto state0;
    value = 3;
    goto check_refresh;
high_state:
    value = 3;
    if (other == value)
        goto state3;
    value = 7;
    if (other == value)
        goto state7;
    goto refresh;
state0:
    child = CarrierSpawn(174, owner);
    call4 = (int)owner;
    if (!child)
        goto set_state2;
    MATCHING_KEEP(child);
    nested = CarrierField(child, unsigned char**, 0);
    CarrierRefreshMobySpatialGridAndBasis(call4, 4);
    frame.first[0] = -100;
    frame.first[1] = 0;
    frame.first[2] = 0;
    CarrierTransformVectorByBasis(owner + 32, frame.first, frame.first);
    CarrierAddVector(child + 12, child + 12, frame.first);
    call4 = (int)child;
    value = 2;
    child[71] = value;
    value = CarrierField(owner, int*, 20);
    arg5 = 1;
    value += 500;
    CarrierField(owner, int*, 20) = value;
    CarrierField(tag, unsigned char**, 16) = child;
    CarrierSetMobyAnimation(call4, arg5);
    CarrierCopyVector(nested, owner + 12);
    value = CarrierField(nested, int*, 8);
    CarrierField(nested, unsigned char**, 12) = owner;
    value += 2048;
    CarrierField(nested, int*, 8) = value;
    value = 3;
    child[72] = value;
set_state2:
    value = 2;
    owner[72] = value;
    goto refresh;
state7:
    CarrierH39714(owner);
    goto done;
state3:
    value = CarrierField(owner, int*, 24);
    child = CarrierField(owner, unsigned char**, 0);
    if (!value)
        goto done;
    CarrierField(owner, int*, 24) = 0;
    call4 = CarrierField(child, int*, 12);
    if (call4) {
        value = CarrierField((void*)call4, int*, 24);
        other = 65536;
        value |= other;
        CarrierField((void*)call4, int*, 24) = value;
        CarrierField(child, int*, 12) = 0;
        goto done;
    }
    value = owner[81];
    value = (value + 128) & 255;
    value <<= 1;
    other = *(short*)((unsigned char*)CarrierCos + value);
    magnitude = 320;
    frame.third[0] = (other * magnitude) >> 12;
    value = *(short*)((unsigned char*)CarrierSin + value);
    call4 = (int)child;
    arg5 = (int)child;
    arg6 = (int)frame.third;
    frame.third[2] = 0;
    frame.third[1] = (value * magnitude) >> 12;
    CarrierAddVector(call4, arg5, arg6);
    vector = frame.second;
    CarrierSubtractVector(vector, child, owner + 12);
    value = CarrierMeasureVectorLength(vector, 0);
    value = value < 961;
    call4 = (int)owner;
    if (value)
        goto nearby;
    MATCHING_KEEP_CLOBBER(value, "$16");
    count = 0;
    one = 1;
    twoHundred = 200;
    scale = 256;
    sixtyFour = 64;
burst_loop:
    value = (int)CarrierH391E8(1, 174, owner, 1, one, twoHundred, scale);
    other = value;
    value = 7;
    if (other) {
        CarrierField((void*)other, unsigned char*, 79) = sixtyFour;
        CarrierField((void*)other, unsigned char*, 72) = value;
    }
    count++;
    value = count < 3;
    call4 = 1;
    if (value)
        goto burst_loop;
    CarrierPlayMobySoundEvent(owner, 2, 0);
    goto destroy;
nearby:
    CarrierPlayMobySoundEvent(call4, 1, 0);
    call4 = 2048;
    arg6 = 0;
    other = CarrierField(child, int*, 0);
    arg5 = CarrierField(owner, int*, 12);
    difference = CarrierField(child, int*, 4);
    value = CarrierField(owner, int*, 16);
    arg5 = other - arg5;
    difference -= value;
    value = CarrierPlanarHeadingLookup(call4, arg5, arg6);
    owner[69] = value;
    value = CarrierPlanarHeadingLookup(2048, difference, 0);
    owner[68] = value;
    goto done;
state2:
    other = CarrierField(tag, int*, 16);
    if (!other)
        goto refresh;
    value = CarrierField(owner, int*, 20);
    value -= 500;
    CarrierField((void*)other, int*, 20) = value;
    value = CarrierField(owner, int*, 24);
    call4 = (int)owner;
    if (!value)
        goto refresh;
    value = CarrierField(tag, int*, 16);
    value = CarrierField((void*)value, int*, 0);
    CarrierField((void*)value, int*, 12) = 0;
    CarrierH36A68(call4, 1, 0, 0);
    goto refresh;
refresh:
    other = owner[72];
    value = 3;
check_refresh:
    if (other == value)
        goto done;
after_refresh:
    value = CarrierField(owner, int*, 24);
    if (!value)
        goto done;
    value = CarrierField(tag, int*, 8);
    if (value) {
        CarrierField(owner, int*, 24) = 0;
        goto done;
    }
    value = CarrierField(tag, int*, 4);
    call4 = 4;
    if (!value)
        goto effects;
    value = CarrierField((void*)value, int*, 0);
    CarrierField((void*)value, int*, 0) = 0;
    other = CarrierField(tag, int*, 4);
    value = 5;
    CarrierField((void*)other, unsigned char*, 73) = value;
    call4 = CarrierField(tag, int*, 4);
    CarrierRequestMobyAnimation(call4, 4);
    call4 = CarrierField(tag, int*, 4);
    other = CarrierField((void*)call4, unsigned char*, 72);
    value = 29;
    if (other != value) {
        value = 4;
        CarrierField((void*)call4, unsigned char*, 72) = value;
    }
effects:
    CarrierH391E8(4, 219, owner, 0, 0, 200, 256);
    CarrierPlayMobySoundEvent(owner, 0, 0);
    CarrierRefreshMobySpatialGridAndBasis(owner, 4);
    other = owner[58];
    value = 255;
    if (other == value)
        CarrierH3BA00(owner);
    CarrierH369B8(owner, 40);
destroy:
    CarrierDeleteMoby(owner);
done:;
}
#undef CarrierField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007CF70.
 * AI generated; not human reviewed. All2030 native instructions,58 absolute
 * selectors,actual control/data targets and symbol addends remain mandatory.
 * Parent acceptance also requires every linked EXE and overlay hash.
 * Original C0 frame saves S0..S7/FP/RA at SP98..BC. Outgoing stack arguments
 * use SP10..1C. Addressable local scalar/vector homes occupy SP20..94.
 * Reserved unused contents are never read. No initializer was invented.
 * Primary original EXE4F178/4F1C8/55F14 and4ED6C produce all three output
 * words on their actual paths; the matrix NULL path retains GTE state.
 * OwnerS2 is the parameter. Private/cursor/player,S0/S1 and other saved
 * roles have separate initialized original phases,not live fixed aliases.
 * FP is the naturally allocated initialized slotBound,originally4 and only
 * set3 on the identified private+1C path. No fixed FP/SP or incoming saved
 * value is used. No outgoing argument home is manually written.
 * Available-slot stores at SP50/54/58/5C precede count increments. The scan
 * examines exactly3 or4 slots. Only count>=2 calls original3636C(0,count-1).
 * Primary3636C and rand5C644 prove inclusive indices0..count-1 and32767 mask.
 * The full native list proof checks every slot category and random result.
 * F334 is read-only original code and cannot overwrite the local list.
 * Temporary owner+14 elevation spans the actual13E38 call; restoration is
 * afterwards. Path-index snapshots are restored after the actual35A80.
 * The forward shared matrix call and state-byte producer/store entries
 * preserve original graph ownership. Every actual transfer is audited.
 * This function contains no original MULT instructions. Signed halfword
 * narrowing,byte wrapping,full32-bit address/scalar values and update order
 * retain their original domains under the frozen original compiler.
 * Empty metadata templates emit zero CPU instructions and consume complete
 * initialized values/addresses. Distinct player+4/+8 linker views refer to
 * the same identified original data bytes,not distinct runtime objects.
 * Helper declarations are32-bit ABI views. F334 has2 known formal words and
 * 55B18 has1; variadic caller views preserve original incidental A2/A1
 * staging without claiming those helpers consume it. Address-valued returns
 * and function pointers retain the original four-byte register bit pattern.
 * External actor/private/path allocation,caller/writer closure,global linked
 * list termination,units/cadence beyond invocation,Rev1 correspondence,
 * synchronized retail runtime captures and human review remain unresolved.
 * This establishes original-compiler identity for this slice,not complete
 * game behavior or portable language-level numeric semantics.
 */
#define Level46_CF70Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level46_CF70CompleteValue(v) __asm__("" : "=r"(v) : "0"(v))
int Level46_CF70_func_80013E38(void*, void*, int) __asm__("func_80013E38");
int Level46_CF70_func_8001A358(void*, int) __asm__("func_8001A358");
int Level46_CF70_func_8001BA30(void*, int, int, int, int, void*) __asm__("func_8001BA30");
void Level46_CF70_func_80021ED8(int, int, int) __asm__("func_80021ED8");
int Level46_CF70_func_80021F3C(int) __asm__("func_80021F3C");
void Level46_CF70_func_80021F8C(int, int, int) __asm__("func_80021F8C");
void Level46_CF70RequestMobyAnimation(void*, int) __asm__("func_80034F40");
void Level46_CF70SetMobyAnimation(void*, int) __asm__("func_80034F80");
int Level46_CF70_func_80035194(void*, void*) __asm__("func_80035194");
int Level46_CF70TurnMobyTowardPlayer(void*, int, int, int) __asm__("func_8003573C");
int Level46_CF70CountTimerDown(void*, int) __asm__("func_800359A4");
int Level46_CF70_func_80035A80(void*, void*, int, int, int, int, int, int) __asm__("func_80035A80");
int Level46_CF70RandBetween(int, int) __asm__("func_8003636C");
void Level46_CF70_func_800369B8(void*, int) __asm__("func_800369B8");
void Level46_CF70_func_80036A68(void*, int, int, int) __asm__("func_80036A68");
void Level46_CF70_func_80038BF8(void*, void*, int, int) __asm__("func_80038BF8");
void Level46_CF70_func_800391E8(int, int, void*, int, int, int, int) __asm__("func_800391E8");
void Level46_CF70_func_8003BA00(void*) __asm__("func_8003BA00");
void Level46_CF70PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
void Level46_CF70_func_8003BB10(void*, int, int) __asm__("func_8003BB10");
void Level46_CF70_func_8004E790(void*, int, int) __asm__("func_8004E790");
int Level46_CF70PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Level46_CF70TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level46_CF70MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
void Level46_CF70ScaleVectorRatioQ15(void*, int, int) __asm__("func_8004F08C");
void Level46_CF70CopyVector(void*, void*) __asm__("func_8004F178");
void Level46_CF70SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Level46_CF70AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level46_CF70ApproximatePlanarDistance(void*, void*, ...) __asm__("func_8004F334");
void Level46_CF70DeleteMoby(void*, ...) __asm__("func_80055B18");
void Level46_CF70RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Level46_CF70_func_80055E84(void*) __asm__("func_80055E84");
void Level46_CF70InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
int Level46_CF70_rand() __asm__("rand");
extern int Level46_CF70_D_8006C550 __asm__("D_8006C550");
extern int Level46_CF70_D_8006C648 __asm__("D_8006C648");
extern int Level46_CF70_D_8006C770 __asm__("D_8006C770");
extern int Level46_CF70_D_8006E020 __asm__("D_8006E020");
extern int Level46_CF70_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level46_CF70_D_8006E040 __asm__("D_8006E040");
extern int Level46_CF70_D_8006E044 __asm__("D_8006E044");
extern int Level46_CF70_D_8006E344 __asm__("D_8006E344");
extern int Level46_CF70_D_8006E788 __asm__("D_8006E788");
extern int Level46_CF70_D_80070328 __asm__("D_80070328");
extern int (*Level46_CF70_SpawnMoby)() __asm__("SpawnMoby");
extern int Level46_CF70PlayerY __asm__("D_80070328 + 4");
extern int Level46_CF70PlayerHeight __asm__("D_80070328 + 8");
void func_level_46_8007CF70(void* ownerParameter) {
    register int distancePointerOrPrivate16 __asm__("$16"), spawnedOwnerOrDistance17 __asm__("$17"),
        owner18 __asm__("$18"), privateCursorOrPlayer19 __asm__("$19"),
        privateOrPlayer20 __asm__("$20"), eventOrPosition21 __asm__("$21"),
        privateOrSelectedSlot22 __asm__("$22"), nearestDistance23 __asm__("$23");
    register int originalFrameSnapshot8 __asm__("$8");
    register int resultOrArithmetic2 __asm__("$2"), fieldOrAddress3 __asm__("$3"),
        argumentOrAddress4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
        int availableSlots50[4];
        int sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94;
    } originalFrame;
    short temp_v1_10;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_5;
    int temp_a0_6;
    int temp_a1;
    int temp_a1_6;
    int state36HeightReturn;
    int temp_v0_17;
    int temp_v0_21;
    int temp_v0_4;
    int idlePlayerDistance;
    int state6PlayerDistance;
    int state9HeightReturn;
    int temp_v1_13;
    int temp_v1_17;
    int var_a0_5;
    int slotBound;
    int temp_v1_11;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_6;
    int temp_a0;
    int temp_a0_10;
    int temp_a0_8;
    int temp_a0_9;
    int temp_a1_10;
    int temp_a1_8;
    int temp_a1_9;
    int temp_v0;
    int temp_v0_13;
    int state36SpawnedOwner;
    int queriedOwner;
    int temp_v0_2;
    int temp_v0_3;
    int state9SpawnedOwner;
    int temp_v1_14;
    int temp_v1_3;
    int temp_v1_9;
    int var_a0_8;
    owner18 = (int)ownerParameter;
    Level46_CF70CompleteValue(owner18);
    privateCursorOrPlayer19 = Level46_CF70Field(owner18, int*, 0);
    if ((Level46_CF70Field(owner18, unsigned char*, 0x4C) != 0) &&
        (Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0x24C) == 4) &&
        ((unsigned char)Level46_CF70Field(owner18, unsigned char*, 0x48) < 0x1EU)) {
        if (Level46_CF70AbsoluteByteAngleDelta(
                (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                Level46_CF70PlanarHeadingLookup(
                    Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                    Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) < 0x18) {
            if (Level46_CF70_D_8006E044 == 0x1F) {
                Level46_CF70Field(owner18, unsigned char*, 0x4E) =
                    (unsigned char)Level46_CF70Field(owner18, unsigned char*, 0x4C);
            } else {
                goto block_7;
            }
        } else {
        block_7:
            Level46_CF70Field(owner18, unsigned char*, 0x4E) = 0x10U;
        }
    }
    if (Level46_CF70Field(owner18, int*, 0x14) < 0x36B0) {
        temp_a0 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
        if (temp_a0 != 0) {
            Level46_CF70DeleteMoby((void*)(temp_a0));
            Level46_CF70Field(privateCursorOrPlayer19, int*, 0) = 0;
        }
        Level46_CF70Field(owner18, int*, 0x18) = 0x10000;
    }
    if (Level46_CF70Field(owner18, int*, 0x18) != 0) {
        fieldOrAddress3 = Level46_CF70Field(owner18, unsigned char*, 0x48);
        Level46_CF70CompleteValue(fieldOrAddress3);
        resultOrArithmetic2 = fieldOrAddress3 - 34;
        if ((unsigned)resultOrArithmetic2 >= 2 && ((fieldOrAddress3 &= 255) != 33) &&
            fieldOrAddress3 != 40 && fieldOrAddress3 != 10) {
            Level46_CF70Field(owner18, int*, 0x18) = 0;
            if (Level46_CF70Field(privateCursorOrPlayer19, int*, 0) != 0) {
                Level46_CF70_func_800391E8(
                    4, 0xDB, (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 0)), 0, 0,
                    0xC8, 0x100);
                Level46_CF70PlayMobySoundEvent(
                    (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 0)), 0, 0);
                Level46_CF70RefreshMobySpatialGridAndBasis(
                    (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 0)), 4);
                Level46_CF70_func_800369B8(
                    (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 0)), 0x28);
                Level46_CF70DeleteMoby(
                    (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 0)));
                Level46_CF70Field(privateCursorOrPlayer19, int*, 0) = 0;
                Level46_CF70RequestMobyAnimation((void*)(owner18), 4);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                argumentOrAddress4 = Level46_CF70Field(owner18, unsigned char*, 0x48);
                Level46_CF70CompleteValue(argumentOrAddress4);
                resultOrArithmetic2 = 36;
                fieldOrAddress3 = argumentOrAddress4 & 255;
                if (fieldOrAddress3 == resultOrArithmetic2 ||
                    (resultOrArithmetic2 = argumentOrAddress4 - 41,
                     (unsigned)resultOrArithmetic2 < 2)) {
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x26U;
                } else {
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 4U;
                }
            } else {
                fieldOrAddress3 = 255;
                resultOrArithmetic2 = Level46_CF70Field(owner18, unsigned char*, 58);
                distancePointerOrPrivate16 = Level46_CF70Field(owner18, int*, 0);
                if (resultOrArithmetic2 == fieldOrAddress3) {
                    if ((Level46_CF70Field(privateCursorOrPlayer19, int*, 8) >= 0) &&
                        ((unsigned int)(Level46_CF70Field(owner18, unsigned char*, 0x48) - 0x32) <
                         8U)) {
                        fieldOrAddress3 = Level46_CF70Field(distancePointerOrPrivate16, int*, 8);
                        argumentOrField5 = Level46_CF70_D_8006C550;
                        Level46_CF70CompleteValue(argumentOrField5);
                        resultOrArithmetic2 = fieldOrAddress3 * 88;
                        Level46_CF70CompleteValue(resultOrArithmetic2);
                        resultOrArithmetic2 = argumentOrField5 + resultOrArithmetic2;
                        temp_v0 = Level46_CF70Field(resultOrArithmetic2, int*, 0);
                        temp_a0_3 = Level46_CF70Field(temp_v0, int*, 8);
                        Level46_CF70Field(temp_v0, int*, 0) = 0;
                        Level46_CF70Field(temp_v0, int*, 4) = 0x3C;
                        if (temp_a0_3 >= 0) {
                            temp_v1_3 =
                                Level46_CF70Field((temp_a0_3 * 0x58) + argumentOrField5, int*, 0);
                            Level46_CF70Field(temp_v1_3, int*, 0x64) =
                                (int)(Level46_CF70Field(temp_v1_3, int*, 0x64) + 1);
                        }
                    }
                }
                Level46_CF70_func_8004E790((void*)(distancePointerOrPrivate16), 0, 0x18);
                Level46_CF70_func_80036A68((void*)(owner18), 0, 0, 0);
                Level46_CF70_func_80038BF8((void*)(owner18), (void*)(distancePointerOrPrivate16), 1,
                                           0xA);
                Level46_CF70Field(distancePointerOrPrivate16, short*, 0xA) = 0x190;
                Level46_CF70Field(distancePointerOrPrivate16, unsigned char*, 0xF) = 0x10;
            }
        }
    }
    temp_v1_4 = Level46_CF70Field(owner18, unsigned char*, 0x48);
    switch (temp_v1_4) {
        case 0x1E:
            Level46_CF70Field(privateCursorOrPlayer19, short*, 4) =
                (short)(((Level46_CF70_rand() & 1) * 0x3C) + 0x3C);
            Level46_CF70Field(privateCursorOrPlayer19, short*, 0xC) = 0x4000;
            Level46_CF70Field(owner18, unsigned char*, 0x48) = 0U;
            argumentOrAddress4 = 174;
            Level46_CF70CompleteValue(argumentOrAddress4);
            resultOrArithmetic2 = (int)Level46_CF70_SpawnMoby;
            argumentOrField5 = owner18;
            Level46_CF70Field(privateCursorOrPlayer19, int*, 0) = 0;
            temp_v0_2 =
                ((int (*)(int, int))resultOrArithmetic2)(argumentOrAddress4, argumentOrField5);
            if (temp_v0_2 != 0) {
                Level46_CF70Field(privateCursorOrPlayer19, int*, 0) = temp_v0_2;
                Level46_CF70Field(temp_v0_2, unsigned char*, 0x48) = 1;
                Level46_CF70Field(temp_v0_2, unsigned char*, 0x47) = 5;
                temp_v0_3 = Level46_CF70Field(temp_v0_2, int*, 0);
                Level46_CF70Field(temp_v0_2, unsigned char*, 0x4C) =
                    (unsigned char)Level46_CF70Field(owner18, unsigned char*, 0x4C);
                Level46_CF70Field(temp_v0_3, int*, 4) = owner18;
                Level46_CF70Field(temp_v0_3, int*, 0) = 0;
                Level46_CF70Field(temp_v0_3, int*, 8) = 0;
            }
            goto block_301;
        default:
            goto block_301;
        case 0x0:
            privateOrPlayer20 = owner18 + 0xC;
            idlePlayerDistance = Level46_CF70ApproximatePlanarDistance(
                (void*)(privateOrPlayer20), (void*)((int)&Level46_CF70_D_80070328));
            if (idlePlayerDistance < Level46_CF70Field(privateCursorOrPlayer19, short*, 0xE)) {
                Level46_CF70TurnMobyTowardPlayer((void*)(owner18), 6, 0, 0);
            }
            if (Level46_CF70CountTimerDown((void*)(privateCursorOrPlayer19 + 4), 2) != 0) {
                if ((idlePlayerDistance <
                     Level46_CF70Field(privateCursorOrPlayer19, short*, 0xC)) &&
                    (Level46_CF70_D_8006E344 != 1) &&
                    (Level46_CF70AbsoluteByteAngleDelta(
                         (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                         Level46_CF70PlanarHeadingLookup(
                             Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                             Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) <
                     0x18) &&
                    (Level46_CF70AbsoluteByteAngleDelta(
                         Level46_CF70PlanarHeadingLookup(
                             Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0) -
                                 Level46_CF70Field(owner18, int*, 0xC),
                             Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 4) -
                                 Level46_CF70Field(owner18, int*, 0x10),
                             0),
                         Level46_CF70Field(owner18, unsigned char*, 0x46)) < 8)) {
                    Level46_CF70CopyVector((void*)(&originalFrame.sp20),
                                           (void*)((int)&Level46_CF70_D_80070328));
                    argumentOrAddress4 = privateOrPlayer20;
                    resultOrArithmetic2 = originalFrame.sp28;
                    argumentOrField5 = (int)&originalFrame.sp20;
                    resultOrArithmetic2 += 512;
                    originalFrame.sp28 = resultOrArithmetic2;
                    argumentOrField6 = 0;
                    resultOrArithmetic2 = Level46_CF70Field(owner18, volatile int*, 20) + 512;
                    Level46_CF70Field(owner18, int*, 20) = resultOrArithmetic2;
                    resultOrArithmetic2 = Level46_CF70_func_80013E38(
                        (void*)(argumentOrAddress4), (void*)(argumentOrField5), argumentOrField6);
                    fieldOrAddress3 = Level46_CF70Field(owner18, volatile int*, 0x14) - 512;
                    Level46_CF70Field(owner18, int*, 0x14) = fieldOrAddress3;
                    if (resultOrArithmetic2 != 0) {
                        Level46_CF70RequestMobyAnimation((void*)(owner18), 5);
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                        Level46_CF70Field(owner18, unsigned char*, 0x48) = 5U;
                    }
                } else if (idlePlayerDistance <
                           Level46_CF70Field(privateCursorOrPlayer19, short*, 0xE)) {
                    Level46_CF70RequestMobyAnimation((void*)(owner18), 1);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 1U;
                }
            }
            goto block_301;
        case 0x6:
            privateOrPlayer20 = owner18 + 0xC;
            state6PlayerDistance = Level46_CF70ApproximatePlanarDistance(
                (void*)(privateOrPlayer20), (void*)((int)&Level46_CF70_D_80070328));
            if (state6PlayerDistance < Level46_CF70Field(privateCursorOrPlayer19, short*, 0xE)) {
                Level46_CF70TurnMobyTowardPlayer((void*)(owner18), 6, 0, 0);
            }
            if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70Field(privateCursorOrPlayer19, short*, 4) = 0;
            }
            if ((Level46_CF70Field(privateCursorOrPlayer19, short*, 4) == 0) &&
                (state6PlayerDistance < Level46_CF70Field(privateCursorOrPlayer19, short*, 0xC)) &&
                (Level46_CF70_D_8006E344 != 1) &&
                (Level46_CF70AbsoluteByteAngleDelta(
                     (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                     Level46_CF70PlanarHeadingLookup(
                         Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                         Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) <
                 0x18) &&
                (Level46_CF70AbsoluteByteAngleDelta(
                     Level46_CF70PlanarHeadingLookup(
                         Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0) -
                             Level46_CF70Field(owner18, int*, 0xC),
                         Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 4) -
                             Level46_CF70Field(owner18, int*, 0x10),
                         0),
                     Level46_CF70Field(owner18, unsigned char*, 0x46)) < 8)) {
                Level46_CF70CopyVector((void*)(&originalFrame.sp20),
                                       (void*)((int)&Level46_CF70_D_80070328));
                argumentOrAddress4 = privateOrPlayer20;
                resultOrArithmetic2 = originalFrame.sp28;
                argumentOrField5 = (int)&originalFrame.sp20;
                resultOrArithmetic2 += 512;
                originalFrame.sp28 = resultOrArithmetic2;
                argumentOrField6 = 0;
                resultOrArithmetic2 = Level46_CF70Field(owner18, volatile int*, 20) + 512;
                Level46_CF70Field(owner18, int*, 20) = resultOrArithmetic2;
                resultOrArithmetic2 = Level46_CF70_func_80013E38(
                    (void*)(argumentOrAddress4), (void*)(argumentOrField5), argumentOrField6);
                fieldOrAddress3 = Level46_CF70Field(owner18, volatile int*, 0x14) - 512;
                Level46_CF70Field(owner18, int*, 0x14) = fieldOrAddress3;
                if (resultOrArithmetic2 != 0) {
                    Level46_CF70Field(privateCursorOrPlayer19, short*, 4) = 0x1E;
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 7U;
                    Level46_CF70RequestMobyAnimation((void*)(owner18), 7);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                }
            }
            goto block_301;
        case 0x1:
            if (Level46_CF70ApproximatePlanarDistance((void*)(owner18 + 0xC),
                                                      (void*)((int)&Level46_CF70_D_80070328)) <
                Level46_CF70Field(privateCursorOrPlayer19, short*, 0xE)) {
                Level46_CF70TurnMobyTowardPlayer((void*)(owner18), 6, 0, 0);
            }
            if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70Field(privateCursorOrPlayer19, short*, 4) =
                    (short)(((Level46_CF70_rand() & 1) * 0x3C) + 0x3C);
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 0U;
                Level46_CF70RequestMobyAnimation((void*)(owner18), 0);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
            }
            goto block_301;
        case 0x4:
            if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70RequestMobyAnimation((void*)(owner18), 6);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 6U;
            }
            goto block_301;
        case 0x7:
            if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 8U;
                Level46_CF70RequestMobyAnimation((void*)(owner18), 8);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
            }
            goto block_301;
        case 0x8:
            Level46_CF70TurnMobyTowardPlayer((void*)(owner18), 4, 0, 0);
            if ((Level46_CF70_D_8006E344 == 1) ||
                (Level46_CF70AbsoluteByteAngleDelta(
                     (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                     Level46_CF70PlanarHeadingLookup(
                         Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                         Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) >=
                 0x18)) {
                Level46_CF70Field(privateCursorOrPlayer19, short*, 4) = 1;
                Level46_CF70RequestMobyAnimation((void*)(owner18), 6);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                Level46_CF70Field(owner18, unsigned char*, 0x40) = 0xA0;
                resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, short*, 22);
                if (resultOrArithmetic2)
                    resultOrArithmetic2 = 42;
                else
                    resultOrArithmetic2 = 6;
                Level46_CF70CompleteValue(resultOrArithmetic2);
                Level46_CF70Field(owner18, unsigned char*, 0x48) = resultOrArithmetic2;
                goto block_120;
            }
            if (Level46_CF70CountTimerDown((void*)(privateCursorOrPlayer19 + 4), 2) != 0) {
                Level46_CF70SetMobyAnimation((void*)(owner18), 9);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 9U;
                if (Level46_CF70Field(owner18, unsigned char*, 0x49) != 0) {
                    resultOrArithmetic2 = 2;
                    goto block_121;
                }
            }
            goto block_301;
        case 0x9:
            temp_a0_5 = Level46_CF70_func_80055E84((void*)(owner18));
            if ((Level46_CF70_D_8006E344 != 1) &&
                ((temp_v1_5 = Level46_CF70Field(owner18, unsigned char*, 0x49), (temp_v1_5 == 2)) ||
                 (temp_v1_5 == 0)) &&
                (Level46_CF70Field(owner18, unsigned char*, 0x3C) == 9) &&
                ((unsigned int)(temp_a0_5 - 0x13) < 7U) &&
                (Level46_CF70AbsoluteByteAngleDelta(
                     (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                     Level46_CF70PlanarHeadingLookup(
                         Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                         Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) <
                 0x18)) {
                state9SpawnedOwner = Level46_CF70_SpawnMoby(0xC5, owner18);
                if (state9SpawnedOwner != 0) {
                    argumentOrAddress4 = state9SpawnedOwner;
                    argumentOrField5 = 2;
                    argumentOrField6 = 0;
                    resultOrArithmetic2 = Level46_CF70Field(owner18, unsigned char*, 70);
                    eventOrPosition21 = Level46_CF70Field(state9SpawnedOwner, int*, 0);
                    argumentOrField7 = 0;
                    Level46_CF70Field(state9SpawnedOwner, unsigned char*, 70) = resultOrArithmetic2;
                    Level46_CF70TurnMobyTowardPlayer((void*)(argumentOrAddress4), argumentOrField5,
                                                     argumentOrField6, argumentOrField7);
                    state9HeightReturn =
                        Level46_CF70_func_8001A358((void*)((int)&Level46_CF70_D_80070328), 0x1000);
                    if (state9HeightReturn != 0) {
                        Level46_CF70CopyVector((void*)(&originalFrame.sp20),
                                               (void*)((int)&Level46_CF70_D_80070328));
                        originalFrame.sp28 = state9HeightReturn + 0x190;
                        argumentOrAddress4 = Level46_CF70ApproximatePlanarDistance(
                            (void*)(state9SpawnedOwner + 0xC), (void*)(&originalFrame.sp20));
                        resultOrArithmetic2 = originalFrame.sp28;
                    } else {
                        argumentOrAddress4 = Level46_CF70ApproximatePlanarDistance(
                            (void*)(state9SpawnedOwner + 0xC),
                            (void*)((int)&Level46_CF70_D_80070328));
                        resultOrArithmetic2 =
                            Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 8);
                    }
                    Level46_CF70Field(state9SpawnedOwner, unsigned char*, 0x45) =
                        Level46_CF70PlanarHeadingLookup(
                            argumentOrAddress4,
                            resultOrArithmetic2 - Level46_CF70Field(state9SpawnedOwner, int*, 0x14),
                            0);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(state9SpawnedOwner, "memory");
                    Level46_CF70Field(eventOrPosition21, short*, 0xC) = 0x12C;
                    Level46_CF70RefreshMobySpatialGridAndBasis((void*)(state9SpawnedOwner), 4);
                    argumentOrAddress4 = state9SpawnedOwner + 32;
                    argumentOrField5 = (int)&originalFrame.sp20;
                    MATCHING_OBSERVE2(argumentOrAddress4, argumentOrField5);
                    resultOrArithmetic2 = Level46_CF70Field(eventOrPosition21, short*, 12);
                    Level46_CF70CompleteValue(eventOrPosition21);
                    argumentOrField6 = eventOrPosition21;
                    originalFrame.sp24 = 0;
                    originalFrame.sp28 = 0;
                    originalFrame.sp20 = resultOrArithmetic2;
                    goto block_102;
                }
                goto block_103;
            } else if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70Field(privateCursorOrPlayer19, short*, 4) = 1;
                Level46_CF70RequestMobyAnimation((void*)(owner18), 6);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                Level46_CF70Field(owner18, unsigned char*, 0x40) = 0xA0;
                resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, short*, 22);
                if (resultOrArithmetic2)
                    resultOrArithmetic2 = 42;
                else
                    resultOrArithmetic2 = 6;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(privateCursorOrPlayer19, "memory");
                Level46_CF70Field(owner18, unsigned char*, 72) = resultOrArithmetic2;
                goto block_120;
            }
            goto block_301;
        case 0x5:
            temp_a0_6 = Level46_CF70_func_80055E84((void*)(owner18));
            if ((Level46_CF70_D_8006E344 != 1) &&
                ((temp_v1_6 = Level46_CF70Field(owner18, unsigned char*, 0x49), (temp_v1_6 == 2)) ||
                 (temp_v1_6 == 0)) &&
                (Level46_CF70Field(owner18, unsigned char*, 0x3C) == 5) &&
                ((unsigned int)(temp_a0_6 - 0x12) < 0xFU) &&
                (Level46_CF70AbsoluteByteAngleDelta(
                     (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                     Level46_CF70PlanarHeadingLookup(
                         Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                         Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) <
                 0x18)) {
                spawnedOwnerOrDistance17 = Level46_CF70_SpawnMoby(197, owner18);
                Level46_CF70CompleteValue(spawnedOwnerOrDistance17);
                if (spawnedOwnerOrDistance17 != 0) {
                    argumentOrAddress4 = spawnedOwnerOrDistance17;
                    argumentOrField5 = 2;
                    argumentOrField6 = 0;
                    resultOrArithmetic2 = Level46_CF70Field(owner18, unsigned char*, 70);
                    privateOrSelectedSlot22 = Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0);
                    argumentOrField7 = 0;
                    Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 70) =
                        resultOrArithmetic2;
                    Level46_CF70TurnMobyTowardPlayer((void*)(argumentOrAddress4), argumentOrField5,
                                                     argumentOrField6, argumentOrField7);
                    if (Level46_CF70Field(owner18, unsigned char*, 0x49) == 0) {
                        distancePointerOrPrivate16 = Level46_CF70RandBetween(4, 0xA);
                        if (Level46_CF70_rand() & 1) {
                            distancePointerOrPrivate16 = -distancePointerOrPrivate16;
                        }
                        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x46) =
                            (unsigned char)(Level46_CF70Field(spawnedOwnerOrDistance17,
                                                              unsigned char*, 0x46) +
                                            distancePointerOrPrivate16);
                    }
                    privateOrPlayer20 = (int)&Level46_CF70_D_80070328;
                    Level46_CF70CompleteValue(privateOrPlayer20);
                    eventOrPosition21 =
                        Level46_CF70_func_8001A358((void*)(privateOrPlayer20), 0x1000);
                    if (eventOrPosition21 != 0) {
                        Level46_CF70CopyVector((void*)(&originalFrame.sp30),
                                               (void*)(privateOrPlayer20));
                        argumentOrAddress4 = spawnedOwnerOrDistance17 + 12;
                        argumentOrField5 = (int)&originalFrame.sp30;
                        MATCHING_OBSERVE2(argumentOrAddress4, argumentOrField5);
                        resultOrArithmetic2 = eventOrPosition21 + 400;
                        originalFrame.sp38 = resultOrArithmetic2;
                        Level46_CF70CompleteValue(eventOrPosition21);
                        argumentOrAddress4 = Level46_CF70ApproximatePlanarDistance(
                            (void*)(argumentOrAddress4), (void*)(argumentOrField5));
                        resultOrArithmetic2 = originalFrame.sp38;
                    } else {
                        argumentOrAddress4 = Level46_CF70ApproximatePlanarDistance(
                            (void*)(spawnedOwnerOrDistance17 + 0xC), (void*)(privateOrPlayer20));
                        resultOrArithmetic2 = Level46_CF70PlayerHeight;
                    }
                    Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x45) =
                        Level46_CF70PlanarHeadingLookup(
                            argumentOrAddress4,
                            resultOrArithmetic2 -
                                Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0x14),
                            0);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(spawnedOwnerOrDistance17, "memory");
                    Level46_CF70Field(privateOrSelectedSlot22, short*, 0xC) = 0x12C;
                    Level46_CF70RefreshMobySpatialGridAndBasis((void*)(spawnedOwnerOrDistance17),
                                                               4);
                    argumentOrAddress4 = spawnedOwnerOrDistance17 + 32;
                    argumentOrField5 = (int)&originalFrame.sp30;
                    MATCHING_OBSERVE2(argumentOrAddress4, argumentOrField5);
                    resultOrArithmetic2 = Level46_CF70Field(privateOrSelectedSlot22, short*, 12);
                    Level46_CF70CompleteValue(privateOrSelectedSlot22);
                    argumentOrField6 = privateOrSelectedSlot22;
                    originalFrame.sp34 = 0;
                    originalFrame.sp38 = 0;
                    originalFrame.sp30 = resultOrArithmetic2;
                block_102:
                    /* Original forward shared matrix call at DB3C; each incoming path has all arguments and its own complete local vector. */
                    Level46_CF70TransformVectorByBasis((void*)(argumentOrAddress4),
                                                       (void*)(argumentOrField5),
                                                       (void*)(argumentOrField6));
                block_103:
                    /* Original shared state-byte1 producer, also reached when either spawn returns NULL. */
                    Level46_CF70Field(owner18, unsigned char*, 0x49) = 1;
                    goto block_301;
                }
                goto block_103;
            }
            if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70RequestMobyAnimation((void*)(owner18), 0);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                if (Level46_CF70Field(privateCursorOrPlayer19, short*, 0x16) == 0) {
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 0U;
                } else {
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x2AU;
                }
                Level46_CF70Field(privateCursorOrPlayer19, short*, 4) =
                    (short)(((Level46_CF70_rand() & 1) * 0x3C) + 0x3C);
                Level46_CF70Field(owner18, unsigned char*, 0x49) = 2U;
            }
            goto block_301;
        case 0x24:
            Level46_CF70Field(Level46_CF70Field(privateCursorOrPlayer19, int*, 0x10),
                              unsigned short*, 2) =
                (unsigned short)Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
            resultOrArithmetic2 = Level46_CF70_func_80035A80(
                (void*)(owner18), (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 16)),
                120, 80, 0, 6, 2, 4);
            fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
            fieldOrAddress3 = Level46_CF70Field(fieldOrAddress3, unsigned short*, 2);
            Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) = fieldOrAddress3;
            if (!(resultOrArithmetic2 & 2))
                goto block_301;
            resultOrArithmetic2 = 37;
            goto block_169;
        case 0x2A:
            eventOrPosition21 = owner18 + 0xC;
            argumentOrAddress4 = eventOrPosition21;
            Level46_CF70CompleteValue(argumentOrAddress4);
            privateOrPlayer20 = (int)&Level46_CF70_D_80070328;
            Level46_CF70CompleteValue(privateOrPlayer20);
            spawnedOwnerOrDistance17 = Level46_CF70ApproximatePlanarDistance(
                (void*)(argumentOrAddress4), (void*)(privateOrPlayer20));
            Level46_CF70CompleteValue(spawnedOwnerOrDistance17);
            if (spawnedOwnerOrDistance17 < 0x2328) {
                Level46_CF70TurnMobyTowardPlayer((void*)(owner18), 6, 0, 0);
                if ((Level46_CF70CountTimerDown((void*)(privateCursorOrPlayer19 + 4), 2) != 0) &&
                    (Level46_CF70_D_8006E344 != 1) &&
                    (Level46_CF70AbsoluteByteAngleDelta(
                         (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                         Level46_CF70PlanarHeadingLookup(
                             Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                             Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) <
                     0x18) &&
                    (Level46_CF70AbsoluteByteAngleDelta(
                         Level46_CF70PlanarHeadingLookup(
                             Level46_CF70Field(privateOrPlayer20, int*, 0) -
                                 Level46_CF70Field(owner18, int*, 0xC),
                             Level46_CF70PlayerY - Level46_CF70Field(owner18, int*, 0x10), 0),
                         Level46_CF70Field(owner18, unsigned char*, 0x46)) < 8)) {
                    Level46_CF70CopyVector((void*)(&originalFrame.sp40),
                                           (void*)(privateOrPlayer20));
                    argumentOrAddress4 = eventOrPosition21;
                    resultOrArithmetic2 = originalFrame.sp48;
                    argumentOrField5 = (int)&originalFrame.sp40;
                    resultOrArithmetic2 += 512;
                    originalFrame.sp48 = resultOrArithmetic2;
                    argumentOrField6 = 0;
                    resultOrArithmetic2 = Level46_CF70Field(owner18, volatile int*, 20) + 512;
                    Level46_CF70Field(owner18, int*, 20) = resultOrArithmetic2;
                    resultOrArithmetic2 = Level46_CF70_func_80013E38(
                        (void*)(argumentOrAddress4), (void*)(argumentOrField5), argumentOrField6);
                    fieldOrAddress3 = Level46_CF70Field(owner18, volatile int*, 0x14) - 512;
                    Level46_CF70Field(owner18, int*, 0x14) = fieldOrAddress3;
                    if (resultOrArithmetic2 != 0) {
                        if (Level46_CF70Field(privateCursorOrPlayer19, int*, 0) != 0) {
                            Level46_CF70RequestMobyAnimation((void*)(owner18), 5);
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(privateOrPlayer20, "memory");
                            Level46_CF70Field(owner18, unsigned char*, 72) = 5;
                        } else {
                            Level46_CF70Field(privateCursorOrPlayer19, short*, 4) = 0x1E;
                            Level46_CF70Field(owner18, unsigned char*, 0x48) = 7U;
                            Level46_CF70RequestMobyAnimation((void*)(owner18), 7);
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                        }
                        goto block_120;
                    }
                }
                goto block_301;
            block_120:
                /* Original DD74 shared producer; forward callers may enter the following store with an already produced value. */
                resultOrArithmetic2 = 2;
            block_121:
                /* Original DD78 state-byte store and return to the shared child update. */
                Level46_CF70Field(owner18, unsigned char*, 73) = resultOrArithmetic2;
                goto block_301;
            } else {
                argumentOrField5 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
                resultOrArithmetic2 = (unsigned)argumentOrField5 < 2;
                if (resultOrArithmetic2)
                    distancePointerOrPrivate16 = 999999;
                else {
                    argumentOrAddress4 = privateOrPlayer20;
                    resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
                    argumentOrField5 *= 16;
                    resultOrArithmetic2 = Level46_CF70Field(resultOrArithmetic2, int*, 12);
                    argumentOrField5 -= 16;
                    distancePointerOrPrivate16 = Level46_CF70ApproximatePlanarDistance(
                        (void*)(argumentOrAddress4),
                        (void*)(resultOrArithmetic2 + argumentOrField5));
                    Level46_CF70CompleteValue(distancePointerOrPrivate16);
                }
                argumentOrField6 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
                argumentOrField5 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
                fieldOrAddress3 = Level46_CF70Field(argumentOrField6, short*, 0);
                resultOrArithmetic2 = argumentOrField5 + 1;
                resultOrArithmetic2 = resultOrArithmetic2 < fieldOrAddress3;
                if (!resultOrArithmetic2) {
                    fieldOrAddress3 = 999999;
                } else {
                    argumentOrAddress4 = (int)&Level46_CF70_D_80070328;
                    MATCHING_OBSERVE_CLOBBER(argumentOrAddress4, "memory");
                    argumentOrField5 *= 16;
                    resultOrArithmetic2 = Level46_CF70Field(argumentOrField6, int*, 12);
                    argumentOrField5 += 16;
                    resultOrArithmetic2 = Level46_CF70ApproximatePlanarDistance(
                        (void*)(argumentOrAddress4),
                        (void*)(resultOrArithmetic2 + argumentOrField5), argumentOrField6);
                    fieldOrAddress3 = resultOrArithmetic2;
                }
                MATCHING_KEEP_CLOBBER(fieldOrAddress3, "memory");
                resultOrArithmetic2 = distancePointerOrPrivate16 < spawnedOwnerOrDistance17;
                if (!resultOrArithmetic2)
                    goto actor2030Case2ANext;
                resultOrArithmetic2 = distancePointerOrPrivate16 < fieldOrAddress3;
                if (!resultOrArithmetic2)
                    goto actor2030Case2ANextReady;
                resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
                fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
                resultOrArithmetic2--;
                Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) = resultOrArithmetic2;
                if (!fieldOrAddress3)
                    goto actor2030Case2AAnimation2;
                argumentOrAddress4 = owner18;
                MATCHING_KEEP_VOLATILE(argumentOrAddress4);
                argumentOrField5 = 3;
                goto actor2030Case2AAnimation;
            actor2030Case2ANext:
            actor2030Case2ANextReady:
                resultOrArithmetic2 = fieldOrAddress3 < spawnedOwnerOrDistance17;
                if (!resultOrArithmetic2)
                    goto block_301;
                resultOrArithmetic2 = fieldOrAddress3 < distancePointerOrPrivate16;
                if (!resultOrArithmetic2)
                    goto block_301;
                resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
                fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
                resultOrArithmetic2++;
                Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) = resultOrArithmetic2;
                if (!fieldOrAddress3)
                    goto actor2030Case2AAnimation2;
                MATCHING_OBSERVE_VOLATILE(owner18);
                argumentOrAddress4 = owner18;
                argumentOrField5 = 3;
                goto actor2030Case2AAnimation;
            actor2030Case2AAnimation2:
                MATCHING_OBSERVE_VOLATILE(privateCursorOrPlayer19);
                argumentOrAddress4 = owner18;
                argumentOrField5 = 2;
            actor2030Case2AAnimation:
                /* Original shared animation call, entered with initialized owner and selector values. */
                Level46_CF70RequestMobyAnimation((void*)(argumentOrAddress4), argumentOrField5);
                Level46_CF70Field(owner18, unsigned char*, 72) = 41;
                Level46_CF70Field(privateCursorOrPlayer19, unsigned short*, 20) = 41;
            }
            goto block_301;
        case 0x29:
            argumentOrAddress4 = owner18;
            fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
            resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
            Level46_CF70Field(fieldOrAddress3, unsigned short*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_CF70_func_80035A80(
                (void*)(argumentOrAddress4),
                (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 16)), 120, 80, 0, 6, 2, 4);
            distancePointerOrPrivate16 = owner18 + 12;
            argumentOrAddress4 = distancePointerOrPrivate16;
            fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
            argumentOrField5 = (int)&Level46_CF70_D_80070328;
            fieldOrAddress3 = Level46_CF70Field(fieldOrAddress3, unsigned short*, 2);
            MATCHING_KEEP_CLOBBER(resultOrArithmetic2, "memory");
            privateOrPlayer20 = resultOrArithmetic2;
            Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) = fieldOrAddress3;
            resultOrArithmetic2 = Level46_CF70ApproximatePlanarDistance((void*)(argumentOrAddress4),
                                                                        (void*)(argumentOrField5));
            fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
            argumentOrAddress4 = distancePointerOrPrivate16;
            argumentOrField5 = Level46_CF70Field(fieldOrAddress3, int*, 12);
            __asm__(""
                    : "=r"(resultOrArithmetic2)
                    : "0"(resultOrArithmetic2), "r"(argumentOrAddress4), "r"(argumentOrField5)
                    : "memory");
            spawnedOwnerOrDistance17 = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_CF70ApproximatePlanarDistance((void*)(argumentOrAddress4),
                                                                        (void*)(argumentOrField5));
            distancePointerOrPrivate16 = resultOrArithmetic2;
            Level46_CF70CompleteValue(distancePointerOrPrivate16);
            Level46_CF70CompleteValue(spawnedOwnerOrDistance17);
            resultOrArithmetic2 = distancePointerOrPrivate16 < 5501;
            if (resultOrArithmetic2)
                goto actor2030Case29FlagsReady;
            resultOrArithmetic2 = spawnedOwnerOrDistance17 < 8192;
            if (resultOrArithmetic2) {
                fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
                Level46_CF70Field(privateCursorOrPlayer19, unsigned short*, 20) = 42;
                if (fieldOrAddress3) {
                    MATCHING_OBSERVE_VOLATILE(owner18);
                    argumentOrAddress4 = owner18;
                    argumentOrField5 = 0;
                } else {
                    MATCHING_OBSERVE_VOLATILE(privateCursorOrPlayer19);
                    argumentOrAddress4 = owner18;
                    argumentOrField5 = 6;
                }
                Level46_CF70RequestMobyAnimation((void*)(argumentOrAddress4), argumentOrField5);
                Level46_CF70Field(owner18, unsigned char*, 72) = 42;
                Level46_CF70Field(privateCursorOrPlayer19, short*, 4) = 0;
            }
            resultOrArithmetic2 = distancePointerOrPrivate16 < 5501;
            if (resultOrArithmetic2)
                goto actor2030Case29FlagsReady;
            resultOrArithmetic2 = privateOrPlayer20 & 1;
            if (!resultOrArithmetic2)
                goto actor2030Case29FlagsReady;
            argumentOrField5 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
            resultOrArithmetic2 = (unsigned)argumentOrField5 < 2;
            if (resultOrArithmetic2)
                distancePointerOrPrivate16 = 999999;
            else {
                argumentOrAddress4 = (int)&Level46_CF70_D_80070328;
                resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
                __asm__ volatile(""
                                 : "=r"(argumentOrField5)
                                 : "0"(argumentOrField5), "r"(argumentOrAddress4)
                                 : "memory");
                argumentOrField5 = argumentOrField5 * 16;
                resultOrArithmetic2 = Level46_CF70Field(resultOrArithmetic2, int*, 12);
                argumentOrField5 -= 32;
                distancePointerOrPrivate16 = Level46_CF70ApproximatePlanarDistance(
                    (void*)(argumentOrAddress4), (void*)(resultOrArithmetic2 + argumentOrField5));
                Level46_CF70CompleteValue(distancePointerOrPrivate16);
            }
            fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
            argumentOrField5 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
            resultOrArithmetic2 = Level46_CF70Field(fieldOrAddress3, short*, 0);
            if (argumentOrField5 == resultOrArithmetic2) {
                fieldOrAddress3 = 999999;
            } else {
                argumentOrAddress4 = (int)&Level46_CF70_D_80070328;
                MATCHING_OBSERVE_CLOBBER(argumentOrAddress4, "memory");
                resultOrArithmetic2 = Level46_CF70Field(fieldOrAddress3, int*, 12);
                argumentOrField5 *= 16;
                resultOrArithmetic2 = Level46_CF70ApproximatePlanarDistance(
                    (void*)(argumentOrAddress4), (void*)(resultOrArithmetic2 + argumentOrField5));
                fieldOrAddress3 = resultOrArithmetic2;
            }
            MATCHING_KEEP_CLOBBER(fieldOrAddress3, "memory");
            resultOrArithmetic2 = spawnedOwnerOrDistance17 < distancePointerOrPrivate16;
            if (resultOrArithmetic2) {
                resultOrArithmetic2 = spawnedOwnerOrDistance17 < fieldOrAddress3;
                if (resultOrArithmetic2) {
                    fieldOrAddress3 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
                    Level46_CF70Field(privateCursorOrPlayer19, unsigned short*, 20) = 42;
                    if (fieldOrAddress3) {
                        MATCHING_OBSERVE_VOLATILE(owner18);
                        argumentOrAddress4 = owner18;
                        argumentOrField5 = 0;
                    } else {
                        MATCHING_OBSERVE_VOLATILE(privateCursorOrPlayer19);
                        argumentOrAddress4 = owner18;
                        argumentOrField5 = 6;
                    }
                    Level46_CF70RequestMobyAnimation((void*)(argumentOrAddress4), argumentOrField5);
                    Level46_CF70Field(owner18, unsigned char*, 72) = 42;
                    goto actor2030Case29Flags;
                }
            }
            resultOrArithmetic2 = distancePointerOrPrivate16 < spawnedOwnerOrDistance17;
            if (!resultOrArithmetic2)
                goto actor2030Case29Flags;
            resultOrArithmetic2 = distancePointerOrPrivate16 < fieldOrAddress3;
            if (!resultOrArithmetic2)
                goto actor2030Case29FlagsReady;
            resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) - 2;
            Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) = resultOrArithmetic2;
        actor2030Case29Flags:
        actor2030Case29FlagsReady:
            resultOrArithmetic2 = privateOrPlayer20 & 2;
            if (!resultOrArithmetic2)
                goto block_301;
            Level46_CF70Field(privateCursorOrPlayer19, unsigned short*, 20) = 42;
            Level46_CF70Field(owner18, unsigned char*, 72) = 42;
            resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
            argumentOrAddress4 = owner18;
            if (resultOrArithmetic2) {
                MATCHING_OBSERVE_VOLATILE(owner18);
                argumentOrField5 = 0;
            } else {
                MATCHING_OBSERVE_VOLATILE(privateCursorOrPlayer19);
                argumentOrField5 = 6;
            }
            Level46_CF70RequestMobyAnimation((void*)(argumentOrAddress4), argumentOrField5);
            resultOrArithmetic2 = Level46_CF70Field(privateCursorOrPlayer19, int*, 16);
            resultOrArithmetic2 = Level46_CF70Field(resultOrArithmetic2, unsigned char*, 0) - 1;
            Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) = resultOrArithmetic2;
            goto block_301;
        case 0x2C:
            Level46_CF70Field(Level46_CF70Field(privateCursorOrPlayer19, int*, 0x10),
                              unsigned short*, 2) =
                (unsigned short)Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6);
            Level46_CF70_func_80035A80(
                (void*)(owner18), (void*)(Level46_CF70Field(privateCursorOrPlayer19, int*, 0x10)),
                0x78, 0x50, 0, 6, 2, 4);
            Level46_CF70Field(privateCursorOrPlayer19, unsigned char*, 6) =
                (unsigned char)Level46_CF70Field(
                    Level46_CF70Field(privateCursorOrPlayer19, int*, 0x10), unsigned short*, 2);
            resultOrArithmetic2 = Level46_CF70ApproximatePlanarDistance(
                (void*)(owner18 + 12),
                (void*)(Level46_CF70Field(Level46_CF70Field(privateCursorOrPlayer19, int*, 16),
                                          int*, 12)));
            resultOrArithmetic2 = resultOrArithmetic2 < 5501;
            if (resultOrArithmetic2)
                goto block_301;
            resultOrArithmetic2 = 37;
        block_169:
            /* Original E11C shared state37 store, reached by case24 and case2C through their actual entries. */
            Level46_CF70Field(owner18, unsigned char*, 72) = resultOrArithmetic2;
            goto block_301;
        case 0x26:
            if (Level46_CF70_D_8006C770 != 0) {
                Level46_CF70RequestMobyAnimation((void*)(owner18), 2);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                Level46_CF70Field(owner18, unsigned char*, 0x48) = (unsigned char)Level46_CF70Field(
                    privateCursorOrPlayer19, unsigned short*, 0x14);
            }
            goto block_301;
        case 0x25:
            if (Level46_CF70TurnMobyTowardPlayer((void*)(owner18), 6, 0, 0) != 0) {
                if (Level46_CF70Field(privateCursorOrPlayer19, int*, 0) != 0) {
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 0U;
                    Level46_CF70RequestMobyAnimation((void*)(owner18), 0);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                } else {
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 6U;
                    Level46_CF70RequestMobyAnimation((void*)(owner18), 6);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                }
            }
            goto block_301;
        case 0xA:
            if (Level46_CF70_func_80035194((void*)(owner18),
                                           (void*)(Level46_CF70Field(owner18, int*, 0))) == 0x100) {
                fieldOrAddress3 = Level46_CF70Field(owner18, unsigned char*, 58);
                Level46_CF70CompleteValue(fieldOrAddress3);
                argumentOrAddress4 = 0;
                if (fieldOrAddress3 < 0xFFU) {
                    resultOrArithmetic2 = fieldOrAddress3 * 88;
                    fieldOrAddress3 = Level46_CF70_D_8006C550;
                    fieldOrAddress3 = fieldOrAddress3 + resultOrArithmetic2;
                    Level46_CF70CompleteValue(fieldOrAddress3);
                    fieldOrAddress3 = Level46_CF70Field(fieldOrAddress3, int*, 0);
                    do {
                        Level46_CF70CompleteValue(fieldOrAddress3);
                        if (Level46_CF70Field(fieldOrAddress3, int*, 0x20) == owner18) {
                            Level46_CF70Field(fieldOrAddress3, int*, 0x20) = 0;
                        }
                        argumentOrAddress4 += 1;
                        fieldOrAddress3 += 4;
                    } while (argumentOrAddress4 < 4);
                    Level46_CF70RefreshMobySpatialGridAndBasis((void*)(owner18), 4);
                    Level46_CF70_func_800369B8((void*)(owner18), 0x28);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                    goto actor2030Delete;
                } else {
                    Level46_CF70RefreshMobySpatialGridAndBasis((void*)(owner18), 4);
                    Level46_CF70_func_8003BA00((void*)(owner18));
                    Level46_CF70_func_800369B8((void*)(owner18), 0x28);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                    goto actor2030Delete;
                }
            }
            break;
        case 0x32:
            temp_v0_13 = Level46_CF70Field(owner18, int*, 0);
            Level46_CF70Field(temp_v0_13, int*, 0) = 1;
            Level46_CF70Field(temp_v0_13, int*, 4) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x41) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x4C) = 0U;
            Level46_CF70Field(owner18, unsigned char*, 0x4D) = 0;
            Level46_CF70Field(owner18, int*, 8) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x33U;
            return;
        case 0x33:
            Level46_CF70CountTimerDown((void*)(Level46_CF70Field(owner18, int*, 0) + 4), 4);
            return;
        case 0x39:
            temp_v1_9 = Level46_CF70Field(owner18, int*, 0);
            Level46_CF70Field(owner18, unsigned char*, 0x41) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x4C) = 0U;
            Level46_CF70Field(owner18, unsigned char*, 0x4D) = 0;
            Level46_CF70Field(owner18, int*, 0x14) =
                (int)(Level46_CF70Field(owner18, int*, 0x14) - 0x6A4);
            Level46_CF70Field(temp_v1_9, int*, 0) = 0;
            Level46_CF70Field(temp_v1_9, int*, 0x14) = (int)Level46_CF70Field(owner18, int*, 0x14);
            Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x37U;
            Level46_CF70RequestMobyAnimation((void*)(owner18), 8);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
            Level46_CF70Field(owner18, unsigned char*, 0x49) = 2U;
            return;
        case 0x37:
            distancePointerOrPrivate16 = Level46_CF70Field(owner18, int*, 0);
            fieldOrAddress3 = Level46_CF70Field(distancePointerOrPrivate16, int*, 8);
            resultOrArithmetic2 = fieldOrAddress3 * 88;
            fieldOrAddress3 = Level46_CF70_D_8006C550;
            fieldOrAddress3 = fieldOrAddress3 + resultOrArithmetic2;
            Level46_CF70CompleteValue(fieldOrAddress3);
            spawnedOwnerOrDistance17 = Level46_CF70Field(fieldOrAddress3, int*, 0);
            Level46_CF70Field(owner18, unsigned char*, 0x41) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x4C) = 0U;
            Level46_CF70Field(owner18, unsigned char*, 0x4D) = 0;
            privateCursorOrPlayer19 = 0x1A;
            if ((Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0) == 0) &&
                (Level46_CF70Field(spawnedOwnerOrDistance17, int*, 4) == 0)) {
                temp_a1_6 = Level46_CF70AbsoluteByteAngleDelta(
                    (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                    Level46_CF70PlanarHeadingLookup(
                        Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                        Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0));
                temp_v1_10 =
                    (unsigned short)Level46_CF70Field(distancePointerOrPrivate16, short*, 4) + 1;
                Level46_CF70Field(distancePointerOrPrivate16, short*, 4) = temp_v1_10;
                if (temp_v1_10 >= 0x1F) {
                    var_a0_5 = 0;
                    privateCursorOrPlayer19 = 0x80;
                } else {
                    var_a0_5 = 0x14;
                    if (temp_v1_10 >= 0x10) {
                        var_a0_5 = 0xA;
                    }
                }
                Level46_CF70CompleteValue(privateCursorOrPlayer19);
                resultOrArithmetic2 = var_a0_5 < temp_a1_6;
                if (resultOrArithmetic2 &&
                    (resultOrArithmetic2 = temp_a1_6 < privateCursorOrPlayer19,
                     resultOrArithmetic2)) {
                    fieldOrAddress3 = 1;
                    resultOrArithmetic2 = 16;
                    Level46_CF70CompleteValue(resultOrArithmetic2);
                    Level46_CF70Field(owner18, unsigned char*, 76) = resultOrArithmetic2;
                    fieldOrAddress3 = 1;
                    Level46_CF70Field(owner18, unsigned char*, 65) = fieldOrAddress3;
                    Level46_CF70Field(owner18, unsigned char*, 77) = fieldOrAddress3;
                    resultOrArithmetic2 = 1;
                    Level46_CF70CompleteValue(resultOrArithmetic2);
                    Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0) = resultOrArithmetic2;
                    Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x34U;
                    Level46_CF70Field(distancePointerOrPrivate16, short*, 4) = 0x1E;
                    return;
                }
            } else {
                Level46_CF70Field(distancePointerOrPrivate16, short*, 4) = 0;
                return;
            }
            break;
        case 0x36:
            distancePointerOrPrivate16 = Level46_CF70Field(owner18, int*, 0);
            spawnedOwnerOrDistance17 = Level46_CF70_func_80055E84((void*)(owner18));
            if (Level46_CF70Field(owner18, unsigned char*, 0x49) == 2) {
                if ((Level46_CF70CountTimerDown((void*)(distancePointerOrPrivate16 + 4), 2) != 0) &&
                    (Level46_CF70AbsoluteByteAngleDelta(
                         (int)(Level46_CF70_D_8006E040 << 0x10) >> 0x14,
                         Level46_CF70PlanarHeadingLookup(
                             Level46_CF70Field(owner18, int*, 0xC) - Level46_CF70_D_8006E020,
                             Level46_CF70Field(owner18, int*, 0x10) - Level46_CF70_D_8006E024, 0)) <
                     0x16)) {
                    Level46_CF70Field(owner18, unsigned char*, 0x49) = 3U;
                    Level46_CF70RequestMobyAnimation((void*)(owner18), 9);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                }
            }
            if ((Level46_CF70Field(owner18, unsigned char*, 0x49) == 3) && ({
                    resultOrArithmetic2 = (unsigned)(spawnedOwnerOrDistance17 - 19) < 7;
                    Level46_CF70CompleteValue(spawnedOwnerOrDistance17);
                    resultOrArithmetic2;
                }) &&
                (Level46_CF70Field(owner18, unsigned char*, 0x3C) == 9)) {
                state36SpawnedOwner = Level46_CF70_SpawnMoby(0xC5, owner18);
                if (state36SpawnedOwner != 0) {
                    privateOrPlayer20 = Level46_CF70Field(state36SpawnedOwner, int*, 0);
                    Level46_CF70Field(owner18, unsigned char*, 0x49) = 1U;
                    Level46_CF70TurnMobyTowardPlayer((void*)(state36SpawnedOwner), 0x80, 0, 0);
                    state36HeightReturn =
                        Level46_CF70_func_8001A358((void*)((int)&Level46_CF70_D_80070328), 0x1000);
                    if (state36HeightReturn != 0) {
                        Level46_CF70CopyVector((void*)(&originalFrame.sp40),
                                               (void*)((int)&Level46_CF70_D_80070328));
                        originalFrame.sp48 = state36HeightReturn + 0x190;
                        argumentOrAddress4 = Level46_CF70ApproximatePlanarDistance(
                            (void*)(state36SpawnedOwner + 0xC), (void*)(&originalFrame.sp40));
                        resultOrArithmetic2 = originalFrame.sp48;
                    } else {
                        argumentOrAddress4 = Level46_CF70ApproximatePlanarDistance(
                            (void*)(state36SpawnedOwner + 0xC),
                            (void*)((int)&Level46_CF70_D_80070328));
                        resultOrArithmetic2 =
                            Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 8);
                    }
                    Level46_CF70Field(state36SpawnedOwner, unsigned char*, 0x45) =
                        Level46_CF70PlanarHeadingLookup(
                            argumentOrAddress4,
                            resultOrArithmetic2 -
                                Level46_CF70Field(state36SpawnedOwner, int*, 0x14),
                            0);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(state36SpawnedOwner, "memory");
                    Level46_CF70Field(privateOrPlayer20, short*, 0xC) = 0x12C;
                    Level46_CF70RefreshMobySpatialGridAndBasis((void*)(state36SpawnedOwner), 4);
                    argumentOrAddress4 = state36SpawnedOwner + 32;
                    argumentOrField5 = (int)&originalFrame.sp40;
                    MATCHING_OBSERVE2(argumentOrAddress4, argumentOrField5);
                    resultOrArithmetic2 = Level46_CF70Field(privateOrPlayer20, short*, 12);
                    Level46_CF70CompleteValue(privateOrPlayer20);
                    argumentOrField6 = privateOrPlayer20;
                    originalFrame.sp44 = 0;
                    originalFrame.sp48 = 0;
                    originalFrame.sp40 = resultOrArithmetic2;
                    Level46_CF70TransformVectorByBasis((void*)(argumentOrAddress4),
                                                       (void*)(argumentOrField5),
                                                       (void*)(argumentOrField6));
                    return;
                }
            } else {
                temp_v1_11 = Level46_CF70Field(owner18, unsigned char*, 0x49);
                if ((((temp_v1_11 == 1) || (temp_v1_11 == 3)) && (Level46_CF70_D_8006C770 != 0)) ||
                    ((Level46_CF70Field(distancePointerOrPrivate16, short*, 4) == 0) &&
                     (Level46_CF70Field(owner18, unsigned char*, 0x49) == 2))) {
                    Level46_CF70Field(distancePointerOrPrivate16, short*, 4) = 0x1D;
                    argumentOrAddress4 = owner18;
                    Level46_CF70Field(argumentOrAddress4, unsigned char*, 72) = 53;
                    Level46_CF70Field(argumentOrAddress4, unsigned char*, 73) = 2;
                    Level46_CF70RequestMobyAnimation((void*)(argumentOrAddress4), 8);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                    return;
                }
            }
            break;
        case 0x35:
            argumentOrField5 = Level46_CF70Field(owner18, int*, 0);
            fieldOrAddress3 = Level46_CF70Field(argumentOrField5, int*, 8);
            argumentOrAddress4 = Level46_CF70_D_8006C550;
            resultOrArithmetic2 = fieldOrAddress3 * 88;
            argumentOrAddress4 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_CF70CompleteValue(argumentOrAddress4);
            fieldOrAddress3 = Level46_CF70_D_8006C648;
            argumentOrAddress4 = Level46_CF70Field(argumentOrAddress4, int*, 0);
            resultOrArithmetic2 = fieldOrAddress3 * 68;
            fieldOrAddress3 = Level46_CF70Field(owner18, int*, 20) - resultOrArithmetic2;
            Level46_CF70Field(owner18, int*, 20) = fieldOrAddress3;
            resultOrArithmetic2 = Level46_CF70Field(argumentOrField5, int*, 20);
            fieldOrAddress3 = fieldOrAddress3 < resultOrArithmetic2;
            if (!fieldOrAddress3)
                goto actor2030Done;
            Level46_CF70Field(owner18, int*, 20) = resultOrArithmetic2;
            Level46_CF70Field(argumentOrField5, short*, 4) = 0;
            Level46_CF70Field(owner18, unsigned char*, 72) = 55;
            Level46_CF70Field(argumentOrAddress4, int*, 0) = 0;
            Level46_CF70Field(argumentOrAddress4, int*, 4) = 60;
            goto actor2030Done;
        case 0x34:
            temp_a0_8 = Level46_CF70Field(owner18, int*, 0);
            temp_v1_13 = Level46_CF70Field(owner18, int*, 0x14) + (Level46_CF70_D_8006C648 * 0x44);
            Level46_CF70Field(owner18, int*, 0x14) = temp_v1_13;
            temp_v0_17 = Level46_CF70Field(temp_a0_8, int*, 0x14) + 0x800;
            if (temp_v0_17 < temp_v1_13) {
                Level46_CF70Field(owner18, int*, 0x14) = temp_v0_17;
                Level46_CF70Field(temp_a0_8, short*, 4) = 2;
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x38U;
                return;
            }
            break;
        case 0x38:
            distancePointerOrPrivate16 = Level46_CF70Field(owner18, int*, 0);
            Level46_CF70Field(owner18, int*, 0x14) =
                (int)(Level46_CF70Field(owner18, int*, 0x14) - (Level46_CF70_D_8006C648 * 0x22));
            if (Level46_CF70CountTimerDown((void*)(distancePointerOrPrivate16 + 4), 2) != 0) {
                Level46_CF70Field(distancePointerOrPrivate16, short*, 4) = 0xB4;
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x36U;
                return;
            }
            break;
        case 0x20:
            temp_v1_14 = Level46_CF70Field(owner18, int*, 0);
            Level46_CF70Field(owner18, unsigned char*, 0x41) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x4C) = 0U;
            Level46_CF70Field(owner18, unsigned char*, 0x4D) = 0;
            Level46_CF70Field(owner18, int*, 8) = 0;
            Level46_CF70Field(owner18, unsigned char*, 0x4A) = 0x40;
            if (Level46_CF70Field(temp_v1_14, short*, 0xC) == 0) {
                Level46_CF70Field(temp_v1_14, unsigned char*, 6) = 3U;
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x21U;
                return;
            }
            Level46_CF70Field(temp_v1_14, unsigned char*, 6) = 4U;
            Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x28U;
            return;
        case 0x22:
            privateOrSelectedSlot22 = Level46_CF70Field(owner18, int*, 0);
            resultOrArithmetic2 = Level46_CF70Field(privateOrSelectedSlot22, short*, 12);
            Level46_CF70CompleteValue(resultOrArithmetic2);
            privateOrPlayer20 = resultOrArithmetic2 + 3;
            eventOrPosition21 = Level46_CF70_func_80021F3C(privateOrPlayer20);
            resultOrArithmetic2 = eventOrPosition21 >> 8;
            Level46_CF70CompleteValue(resultOrArithmetic2);
            privateCursorOrPlayer19 = resultOrArithmetic2 & 255;
            queriedOwner = Level46_CF70_func_8001BA30((void*)(owner18 + 0xC), 0x9C4, 3, 0, 0,
                                                      (void*)(owner18));
            if (queriedOwner != 0) {
                if (Level46_CF70Field(queriedOwner, short*, 0x36) == 0xAE) {
                    if (Level46_CF70Field(queriedOwner, unsigned char*, 0x48) == 1) {
                        temp_a1_8 = Level46_CF70Field(queriedOwner, int*, 0);
                        temp_a0_9 = Level46_CF70Field(temp_a1_8, int*, 4);
                        if ((temp_a0_9 != 0) &&
                            (Level46_CF70Field(temp_a0_9, unsigned char*, 0x48) != 0xA)) {
                            Level46_CF70Field(Level46_CF70Field(temp_a0_9, int*, 0), int*, 0) = 0;
                            temp_a1_9 = Level46_CF70Field(temp_a1_8, int*, 4);
                            Level46_CF70Field(temp_a1_9, int*, 0x18) =
                                (int)(Level46_CF70Field(temp_a1_9, int*, 0x18) | 0x10000);
                            Level46_CF70DeleteMoby((void*)(queriedOwner), temp_a1_9);
                        }
                    } else {
                        goto block_232;
                    }
                } else {
                block_232:
                    if ((Level46_CF70Field(queriedOwner, short*, 0x36) == 0xAF) &&
                        (Level46_CF70Field(queriedOwner, unsigned char*, 0x48) != 0xA)) {
                        spawnedOwnerOrDistance17 = Level46_CF70Field(queriedOwner, int*, 0);
                        temp_a0_10 = Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0);
                        if (temp_a0_10 != 0) {
                            Level46_CF70DeleteMoby((void*)(temp_a0_10));
                            Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0) = 0;
                        }
                        Level46_CF70Field(queriedOwner, int*, 0x18) =
                            (int)(Level46_CF70Field(queriedOwner, int*, 0x18) | 0x10000);
                    }
                }
            }
            if (privateCursorOrPlayer19 != 0) {
                resultOrArithmetic2 = eventOrPosition21 & 15;
                Level46_CF70CompleteValue(eventOrPosition21);
                if (resultOrArithmetic2) {
                    Level46_CF70_func_80021ED8(privateOrPlayer20, 0xFC, 0);
                }
                privateCursorOrPlayer19 = privateCursorOrPlayer19 - 2;
                if (privateCursorOrPlayer19 <= 0) {
                    Level46_CF70_func_80021F8C(privateOrPlayer20, 0, 0);
                    Level46_CF70_func_80021ED8(privateOrPlayer20, 0xFC, 2);
                    return;
                }
                Level46_CF70_func_80021F8C(privateOrPlayer20, privateCursorOrPlayer19, 0);
                return;
            }
            argumentOrAddress4 = (int)&Level46_CF70_D_8006E788;
            fieldOrAddress3 = Level46_CF70Field(argumentOrAddress4, int*, 0);
            argumentOrAddress4 += 4;
            if (!fieldOrAddress3)
                goto actor2030ListFinished;
            argumentOrField6 = 175;
            argumentOrField5 = 255;
            do {
                resultOrArithmetic2 = Level46_CF70Field(fieldOrAddress3, short*, 54);
                if (resultOrArithmetic2 == argumentOrField6) {
                    resultOrArithmetic2 = Level46_CF70Field(fieldOrAddress3, unsigned char*, 58);
                    if (resultOrArithmetic2 != argumentOrField5)
                        goto actor2030Done;
                }
                fieldOrAddress3 = Level46_CF70Field(argumentOrAddress4, int*, 0);
                argumentOrAddress4 += 4;
            } while (fieldOrAddress3);
        actor2030ListFinished:
            /* The original linked actor scan ended at its NULL entry; no fabricated termination bound is used. */
            fieldOrAddress3 = Level46_CF70Field(privateOrSelectedSlot22, int*, 8);
            if (fieldOrAddress3 >= 0) {
                resultOrArithmetic2 = fieldOrAddress3 * 88;
                fieldOrAddress3 = Level46_CF70_D_8006C550;
                fieldOrAddress3 += resultOrArithmetic2;
                Level46_CF70CompleteValue(fieldOrAddress3);
                fieldOrAddress3 = Level46_CF70Field(fieldOrAddress3, int*, 0);
                resultOrArithmetic2 = Level46_CF70Field(fieldOrAddress3, int*, 100) + 1;
                Level46_CF70Field(fieldOrAddress3, int*, 100) = resultOrArithmetic2;
            }
            Level46_CF70Field(owner18, unsigned char*, 72) = 35;
            goto actor2030Done;
        case 0x23:
            if (Level46_CF70Field(owner18, unsigned char*, 0x49) == 0xA) {
                Level46_CF70_func_8003BA00((void*)(owner18));
            actor2030Delete:
                Level46_CF70DeleteMoby((void*)(owner18));
                goto actor2030Done;
            }
            break;
        case 0x21:
        case 0x28:
            privateOrSelectedSlot22 = -1;
            slotBound = 4;
            privateOrPlayer20 = Level46_CF70Field(owner18, int*, 0);
            originalFrameSnapshot8 = Level46_CF70Field(privateOrPlayer20, short*, 12);
            nearestDistance23 = 100000;
            originalFrame.sp70 = originalFrameSnapshot8;
            originalFrameSnapshot8 += 3;
            originalFrame.sp88 = originalFrameSnapshot8;
            argumentOrAddress4 = Level46_CF70Field(&originalFrame.sp88, volatile int*, 0);
            eventOrPosition21 = 0;
            resultOrArithmetic2 = Level46_CF70_func_80021F3C(argumentOrAddress4);
            distancePointerOrPrivate16 = owner18 + 12;
            argumentOrAddress4 = distancePointerOrPrivate16;
            privateCursorOrPlayer19 = (int)&Level46_CF70_D_80070328;
            argumentOrField5 = privateCursorOrPlayer19;
            Level46_CF70CompleteValue(privateCursorOrPlayer19);
            originalFrame.sp78 = resultOrArithmetic2;
            resultOrArithmetic2 = (resultOrArithmetic2 >> 8) & 255;
            originalFrame.sp80 = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_CF70ApproximatePlanarDistance((void*)(argumentOrAddress4),
                                                                        (void*)(argumentOrField5));
            fieldOrAddress3 = resultOrArithmetic2;
            Level46_CF70CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 < 3400;
            spawnedOwnerOrDistance17 = (int)&originalFrame.sp60;
            if (resultOrArithmetic2) {
                argumentOrAddress4 = spawnedOwnerOrDistance17;
                argumentOrField5 = privateCursorOrPlayer19;
                argumentOrField6 = distancePointerOrPrivate16;
                __asm__(""
                        : "=r"(argumentOrField6)
                        : "0"(argumentOrField6), "r"(argumentOrAddress4), "r"(argumentOrField5));
                distancePointerOrPrivate16 = 3400 - fieldOrAddress3;
                Level46_CF70SubtractVector((void*)(argumentOrAddress4), (void*)(argumentOrField5),
                                           (void*)(argumentOrField6));
                originalFrame.sp68 = 0;
                resultOrArithmetic2 =
                    Level46_CF70MeasureVectorLength((void*)(spawnedOwnerOrDistance17), 1);
                Level46_CF70ScaleVectorRatioQ15((void*)(spawnedOwnerOrDistance17),
                                                resultOrArithmetic2, distancePointerOrPrivate16);
                Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0x20C) = 0x10000008;
                Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0x224) = 0;
                Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0x21C) = originalFrame.sp60;
                Level46_CF70Field((int)&Level46_CF70_D_80070328, int*, 0x220) = originalFrame.sp64;
            }
            temp_v1_17 = Level46_CF70Field(privateOrPlayer20, int*, 0);
            if ((temp_v1_17 >= 0) &&
                (Level46_CF70Field(((temp_v1_17 * 0x58) + Level46_CF70_D_8006C550), unsigned char*,
                                   0x48) == 2)) {
                if ((originalFrameSnapshot8 =
                         Level46_CF70Field(&originalFrame.sp80, volatile int*, 0),
                     originalFrameSnapshot8 != 0)) {
                    originalFrameSnapshot8 =
                        Level46_CF70Field(&originalFrame.sp78, volatile int*, 0);
                    resultOrArithmetic2 = originalFrameSnapshot8 & 15;
                    Level46_CF70CompleteValue(originalFrameSnapshot8);
                    if (resultOrArithmetic2) {
                        Level46_CF70_func_80021ED8(originalFrame.sp88, 0xFC, 0);
                    }
                }
                Level46_CF70Field(owner18, unsigned char*, 0x48) = 0x22U;
                return;
            }
            if (Level46_CF70Field(privateOrPlayer20, unsigned char*, 7) == 0) {
                if (Level46_CF70Field(privateOrPlayer20, int*, 0x1C) == 0) {
                    slotBound = 3;
                }
                spawnedOwnerOrDistance17 = 0;
                if (slotBound != 0) {
                    privateCursorOrPlayer19 = privateOrPlayer20;
                    Level46_CF70CompleteValue(eventOrPosition21);
                    fieldOrAddress3 = (int)&originalFrame;
                    resultOrArithmetic2 = eventOrPosition21 * 4;
                    distancePointerOrPrivate16 = resultOrArithmetic2 + fieldOrAddress3;
                    do {
                        temp_a1_10 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0x20);
                        if (temp_a1_10 != 0) {
                            if (Level46_CF70Field(temp_a1_10, unsigned char*, 0x48) != 0xA) {
                                temp_v0_21 = Level46_CF70ApproximatePlanarDistance(
                                    (void*)(owner18 + 0xC), (void*)(temp_a1_10 + 0xC));
                                if (temp_v0_21 < nearestDistance23) {
                                    nearestDistance23 = temp_v0_21;
                                }
                            }
                        } else {
                            if (privateOrSelectedSlot22 == -1) {
                                privateOrSelectedSlot22 = spawnedOwnerOrDistance17;
                                Level46_CF70CompleteValue(privateOrSelectedSlot22);
                                Level46_CF70Field(distancePointerOrPrivate16, int*, 0x30) =
                                    privateOrSelectedSlot22;
                            } else {
                                Level46_CF70Field(distancePointerOrPrivate16, int*, 0x30) =
                                    spawnedOwnerOrDistance17;
                            }
                            distancePointerOrPrivate16 += 4;
                            eventOrPosition21 += 1;
                        }
                        spawnedOwnerOrDistance17 += 1;
                        privateCursorOrPlayer19 += 4;
                    } while (spawnedOwnerOrDistance17 < slotBound);
                }
                resultOrArithmetic2 = eventOrPosition21 < 2;
                if (resultOrArithmetic2)
                    goto actor2030MinimumReady;
                privateOrSelectedSlot22 =
                    originalFrame
                        .availableSlots50[Level46_CF70RandBetween(0, eventOrPosition21 - 1)];
            actor2030MinimumReady:
                /* Original packed-list count/random branch joins this complete minimum-distance predicate. */
                resultOrArithmetic2 = nearestDistance23 < 5122;
                Level46_CF70CompleteValue(nearestDistance23);
                if (!resultOrArithmetic2)
                    goto actor2030FarStatus;
                originalFrameSnapshot8 = Level46_CF70Field(&originalFrame.sp80, volatile int*, 0);
                if (originalFrameSnapshot8)
                    goto actor2030StatusDone;
                argumentOrField5 = 252;
                MATCHING_OBSERVE_CLOBBER(argumentOrField5, "memory");
                originalFrameSnapshot8 = Level46_CF70Field(&originalFrame.sp70, volatile int*, 0);
                argumentOrField6 = 0;
                argumentOrAddress4 = originalFrameSnapshot8 + 3;
                Level46_CF70_func_80021ED8(argumentOrAddress4, argumentOrField5, argumentOrField6);
                argumentOrAddress4 = owner18;
                argumentOrField5 = 4;
                goto actor2030StatusRespond;
            actor2030FarStatus:
                /* Original separate far-status handler; every T0 frame snapshot is freshly initialized. */
                originalFrameSnapshot8 = Level46_CF70Field(&originalFrame.sp80, volatile int*, 0);
                resultOrArithmetic2 = 10;
                if (originalFrameSnapshot8 != resultOrArithmetic2)
                    goto actor2030StatusDone;
                argumentOrField5 = 252;
                MATCHING_OBSERVE_CLOBBER(argumentOrField5, "memory");
                originalFrameSnapshot8 = Level46_CF70Field(&originalFrame.sp70, volatile int*, 0);
                argumentOrField6 = 0;
                argumentOrAddress4 = originalFrameSnapshot8 + 3;
                Level46_CF70_func_80021ED8(argumentOrAddress4, argumentOrField5, argumentOrField6);
                argumentOrAddress4 = owner18;
                argumentOrField5 = 5;
            actor2030StatusRespond:
                /* Original shared 3BB10 response with complete A0/A1 argument producers. */
                Level46_CF70_func_8003BB10((void*)(argumentOrAddress4), argumentOrField5, 0);
            actor2030StatusDone:
                if (privateOrSelectedSlot22 >= 0) {
                    var_a0_8 = privateOrPlayer20 + 4;
                    if (((short)Level46_CF70Field(privateOrPlayer20, short*, 4) < 0x3C) &&
                        ((originalFrameSnapshot8 =
                              Level46_CF70Field(&originalFrame.sp80, volatile int*, 0),
                          originalFrameSnapshot8 != 0)) &&
                        (Level46_CF70Field(privateOrPlayer20, unsigned char*, 6) == 0)) {
                        Level46_CF70Field(privateOrPlayer20, short*, 4) = 0x3C;
                        Level46_CF70CompleteValue(privateOrPlayer20);
                        var_a0_8 = privateOrPlayer20 + 4;
                        Level46_CF70CompleteValue(var_a0_8);
                    }
                    if (!Level46_CF70CountTimerDown((void*)(var_a0_8), 2))
                        goto actor2030Done;
                    resultOrArithmetic2 = Level46_CF70Field(privateOrPlayer20, unsigned char*, 6);
                    argumentOrAddress4 = 175;
                    if (!resultOrArithmetic2) {
                        originalFrameSnapshot8 =
                            Level46_CF70Field(&originalFrame.sp80, volatile int*, 0);
                        if (originalFrameSnapshot8)
                            goto actor2030Done;
                    }
                    argumentOrField5 = owner18;
                    fieldOrAddress3 = (int)Level46_CF70_SpawnMoby;
                    resultOrArithmetic2 = 210;
                    Level46_CF70Field(privateOrPlayer20, short*, 4) = resultOrArithmetic2;
                    spawnedOwnerOrDistance17 =
                        ((int (*)(int, int))fieldOrAddress3)(argumentOrAddress4, argumentOrField5);
                    Level46_CF70CompleteValue(spawnedOwnerOrDistance17);
                    if (spawnedOwnerOrDistance17) {
                        if (Level46_CF70Field(privateOrPlayer20, unsigned char*, 6) != 0) {
                            Level46_CF70Field(privateOrPlayer20, short*, 4) = 0x1E;
                            Level46_CF70Field(privateOrPlayer20, unsigned char*, 6) =
                                (unsigned char)(Level46_CF70Field(privateOrPlayer20, unsigned char*,
                                                                  6) -
                                                1);
                        }
                        fieldOrAddress3 = privateOrSelectedSlot22 * 4 + privateOrPlayer20;
                        Level46_CF70CompleteValue(privateOrSelectedSlot22);
                        Level46_CF70Field(fieldOrAddress3, int*, 32) = spawnedOwnerOrDistance17;
                        argumentOrAddress4 = Level46_CF70Field(owner18, unsigned char*, 70);
                        distancePointerOrPrivate16 =
                            Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0);
                        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x4C) = 0x20U;
                        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x4A) = 0x40;
                        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x50) = 0xFF;
                        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 70) =
                            argumentOrAddress4;
                        fieldOrAddress3 = Level46_CF70Field(fieldOrAddress3, int*, 16);
                        Level46_CF70Field(distancePointerOrPrivate16, int*, 8) = -1;
                        Level46_CF70Field(distancePointerOrPrivate16, short*, 0xC) = 0x4000;
                        Level46_CF70Field(distancePointerOrPrivate16, short*, 0xE) = 0x4800;
                        Level46_CF70Field(distancePointerOrPrivate16, int*, 16) = fieldOrAddress3;
                        Level46_CF70Field(distancePointerOrPrivate16, unsigned char*, 6) = 0;
                        Level46_CF70Field(distancePointerOrPrivate16, int*, 0) = 0;
                        Level46_CF70Field(Level46_CF70Field(distancePointerOrPrivate16, int*, 0x10),
                                          short*, 0xA) = 1;
                        Level46_CF70CopyVector(
                            (void*)(spawnedOwnerOrDistance17 + 0xC),
                            (void*)(Level46_CF70Field(
                                Level46_CF70Field(distancePointerOrPrivate16, int*, 0x10), int*,
                                0xC)));
                        if (Level46_CF70Field(owner18, unsigned char*, 0x48) == 0x21) {
                            Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x48) =
                                0x24;
                            Level46_CF70Field(distancePointerOrPrivate16, short*, 0x14) = 0x24;
                            Level46_CF70Field(distancePointerOrPrivate16, short*, 0x16) = 0;
                        } else {
                            Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x48) =
                                0x29;
                            Level46_CF70Field(distancePointerOrPrivate16, short*, 0x14) = 0x29;
                            Level46_CF70Field(distancePointerOrPrivate16, short*, 0x16) = 0x2A;
                        }
                        Level46_CF70RequestMobyAnimation((void*)(spawnedOwnerOrDistance17), 3);
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                        resultOrArithmetic2 = Level46_CF70_SpawnMoby(174, spawnedOwnerOrDistance17);
                        argumentOrField5 = resultOrArithmetic2;
                        Level46_CF70CompleteValue(argumentOrField5);
                        if (argumentOrField5) {
                            Level46_CF70Field(distancePointerOrPrivate16, int*, 0) =
                                argumentOrField5;
                            Level46_CF70Field(argumentOrField5, unsigned char*, 72) = 1;
                            Level46_CF70Field(argumentOrField5, unsigned char*, 71) = 5;
                            argumentOrAddress4 =
                                Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 76);
                            fieldOrAddress3 = Level46_CF70Field(argumentOrField5, int*, 0);
                            Level46_CF70Field(argumentOrField5, unsigned char*, 74) = 255;
                            Level46_CF70Field(argumentOrField5, unsigned char*, 76) =
                                argumentOrAddress4;
                            Level46_CF70Field(fieldOrAddress3, int*, 4) = spawnedOwnerOrDistance17;
                            Level46_CF70Field(fieldOrAddress3, int*, 0) = 0;
                            Level46_CF70Field(fieldOrAddress3, int*, 8) = 0;
                            goto actor2030Done;
                        }
                    }
                }
            }
            break;
    }
    goto actor2030Done;
block_301:
    /* Original EE38 shared child update; every incoming path retains the actual private S3 role. */
    spawnedOwnerOrDistance17 = Level46_CF70Field(privateCursorOrPlayer19, int*, 0);
    if (spawnedOwnerOrDistance17 != 0) {
        Level46_CF70RefreshMobySpatialGridAndBasis((void*)(owner18), 5);
        argumentOrAddress4 = owner18;
        argumentOrField5 = 1;
        MATCHING_OBSERVE2(argumentOrAddress4, argumentOrField5);
        distancePointerOrPrivate16 = spawnedOwnerOrDistance17 + 12;
        Level46_CF70InterpolateMobyVertex((void*)(argumentOrAddress4), argumentOrField5,
                                          (void*)(distancePointerOrPrivate16));
        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x46) =
            (unsigned char)Level46_CF70Field(owner18, unsigned char*, 0x46);
        Level46_CF70InterpolateMobyVertex((void*)(owner18), 3, (void*)(&originalFrame.sp20));
        originalFrame.sp38 =
            originalFrame.sp28 - Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0x14);
        temp_v0_4 = Level46_CF70ApproximatePlanarDistance((void*)(&originalFrame.sp20),
                                                          (void*)(distancePointerOrPrivate16));
        originalFrame.sp30 = temp_v0_4;
        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x45) =
            (signed char)(Level46_CF70PlanarHeadingLookup(temp_v0_4, originalFrame.sp38, 0) - 0x40);
        Level46_CF70InterpolateMobyVertex((void*)(owner18), 2, (void*)(&originalFrame.sp20));
        temp_a0_4 = originalFrame.sp20 - Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0xC);
        originalFrame.sp30 = temp_a0_4;
        temp_a1 = originalFrame.sp24 - Level46_CF70Field(spawnedOwnerOrDistance17, int*, 0x10);
        originalFrame.sp34 = temp_a1;
        Level46_CF70Field(spawnedOwnerOrDistance17, unsigned char*, 0x46) =
            (unsigned char)(Level46_CF70PlanarHeadingLookup(temp_a0_4, temp_a1, 0) - 0x40);
    }
    return;
actor2030Done:
    return;
}
#undef Level46_CF70Field
#undef Level46_CF70CompleteValue

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level46 0x8007EF28..0x8007F248: 200 original instructions.
 * Original helper arguments, signed table products (sample*25)>>7,
 * halfword counter, byte accesses and post-call rereads preserved.
 * Helper contracts, physical units and caller cadence remain unresolved.
 * Empty compiler constraints emit no CPU instructions. Acceptance requires
 * every original linked word and full EXE/all-overlay hashes.
 */
extern unsigned char P7EF28Player[] __asm__("D_80070328");
extern unsigned char P7EF28Flags[] __asm__("D_80066BC8");
extern short D_800719DC;
extern int D_8006C648;
extern short P7EF28Cos[] __asm__("D_80065920");
extern short P7EF28Sin[] __asm__("D_800658A0");
int func_800369D8(int);
void func_level_46_8007EF28(Moby* argument) {
    register Moby* owner __asm__("$18") = argument;
    register unsigned char* privateState __asm__("$17");
    register Moby* child __asm__("$16");
    register int value100 __asm__("$16");
    register int value1 __asm__("$19");
    register int valueC8 __asm__("$17");
    register int fragmentCount __asm__("$4"), fragmentClass __asm__("$5");
    MATCHING_KEEP(owner);
    privateState = owner->mobyTag;
    if (owner->damageFlags & 0x40000) {
        if (owner->animationRun) {
            int helperResult = func_800369D8(owner->animationRun);

            if (helperResult == 1) {
                P7EF28Flags[19] = 3;
                D_800719DC = 1;
                PlaySound(((unsigned char*)D_8006C654)[35], owner, 161);
                child = SpawnMoby(211, owner);

                if (child) {
                    func_8004F178(&child->position, (Vector3D*)P7EF28Player);
                    child->position.x += (P7EF28Cos[P7EF28Player[14]] * 25) >> 7;
                    MATCHING_BARRIER("memory");
                    {
                        register int z __asm__("$3") = child->position.z;
                        register int sample __asm__("$4") = P7EF28Sin[P7EF28Player[14]];
                        __asm__("" : "=r"(sample) : "0"(sample), "r"(z));
                        child->position.z = z + 500;
                        MATCHING_BARRIER("memory");
                        {
                            register int y __asm__("$3") = child->position.y;
                            __asm__("" : "=r"(y) : "0"(y), "r"(sample));
                            child->position.y = y + ((sample * 25) >> 7);
                        }
                    }
                }
            }
        }
        fragmentCount = 4;
        fragmentClass = 191;
        __asm__("" : "=r"(fragmentClass) : "0"(fragmentClass), "r"(fragmentCount) : "$16");
        value100 = 256;
        SpawnFragments(fragmentCount, fragmentClass, owner, (Vector3D*)*(int*)(privateState + 12),
                       0, value100);
        {
            register int a4 __asm__("$4") = 1;
            register int a5 __asm__("$5") = 191;
            register Moby* a6 __asm__("$6") = owner;
            register int a7 __asm__("$7") = 1;
            __asm__("" : : "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "$19", "$17");
        }
        value1 = 1;
        valueC8 = 200;
        {
            register Moby* fragment __asm__("$3") =
                func_800391E8(1, 191, owner, 1, value1, valueC8, value100);
            if (fragment)
                fragment->position.z += 4096;
            fragment = func_800391E8(1, 191, owner, 1, value1, valueC8, value100);
            if (fragment)
                fragment->position.z += 4096;
        }
        func_80055D24(owner, 4);
        func_8003BA00(owner);
        func_800369B8(owner, 56);
        func_80055B18(owner);
    } else {
        if (owner->damageFlags & 0x10000) {
            if (*(short*)(privateState + 4) == 0) {
                *(short*)(privateState + 6) = owner->angle.roll;
                *(short*)(privateState + 8) = owner->angle.pitch;
            }
            *(short*)(privateState + 4) = 1;
            MATCHING_BARRIER("$4");
            func_8003BABC(owner, 0, 0);
        }
        owner->damageFlags = 0;
        if (*(short*)(privateState + 4)) {
            *(short*)(privateState + 4) += D_8006C648;
            if (*(short*)(privateState + 4) < 64) {
                owner->angle.roll =
                    ((unsigned char*)*(int*)privateState)[(*(short*)(privateState + 4) >> 1) * 2] +
                    privateState[6];
                owner->angle.pitch =
                    ((unsigned char*)*(
                        int*)privateState)[(*(short*)(privateState + 4) >> 1) * 2 + 1] +
                    privateState[8];
            } else {
                *(short*)(privateState + 4) = 0;
                owner->angle.roll = *(short*)(privateState + 6);
                owner->angle.pitch = *(short*)(privateState + 8);
            }
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007F248.
 * AI generated; not human reviewed. All2510 native instructions,83 absolute
 * selectors,one original zero padding word,actual transfers/data addends and
 * every parent linked EXE/overlay hash remain mandatory. Pipeline unchanged.
 * Original118 frame saves S0..S4/RA at SP100..114. Complete local scalar and
 * vector homes span SP20..FC; outgoing homes use SP10..18. Unused reserved
 * frame contents are never read. No initializer or index bound was invented.
 * OwnerS3 is the parameter;privateS4 is owner+0. S0/frame/path and S1 selector
 * roles have separate actual initialized phases,not simultaneous aliases.
 * There is no fixed FP/SP,incoming saved C value or manual outgoing home.
 * Primary EXE4ED6C/4F178/4F194/13AE4 output contracts and the original finite
 * GP/local/call proof establish every actual local consumer's producer.
 * Packed actor-list loops read the current complete tag before their original
 * always-executed pointer increment. No fabricated list termination is used.
 * The shared increment label starts after its original predecessor loads.
 * All sixteen LH capture/clamp phases preserve signed16 comparisons and
 * original32-bit constant shift/add domains. Trig signed16*39>>6 and*13>>5
 * products fit signed32. Original2803C returns narrow low16 by SLL/SRA.
 * Original redundant zero/SW vector stores are explicit volatile C accesses.
 * Every empty metadata template emits zero CPU instructions. Inputs are whole
 * initialized values/addresses; phase clobbers retire dead old GP roles only,
 * immediately before actual fresh producers. They never read incoming values.
 * Full owner identities carry only the actual dominating owner49 state byte
 * 2/17/78/38/38 as readonly immediate context. No arbitrary compiler IDs occur.
 * These identities follow the original SB49 and precede fresh LI60, preserving
 * original separate tails while allowing the actual J delay producer.
 * Helper types are four-byte ABI views. External allocation,actor/private/tag
 * writer closure,full helper semantics,global list termination,coordinate
 * domains,cadence beyond invocation,Rev1 correspondence,retail runtime captures
 * and human review remain unresolved. This establishes original-compiler
 * identity for this slice,not completed game behavior or portable C numerics.
 */
/* SCUS-94467 USA Rev0 original2510native+84selectors. AI generated; not human reviewed. Uninstalled original-backed probe. */
#define Level46_F248Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level46_F248CompleteValue(v) __asm__("" : "=r"(v) : "0"(v))
void Level46_F248_func_80013AE4(void*, void*) __asm__("func_80013AE4");
void Level46_F248_func_80013B7C(int) __asm__("func_80013B7C");
void Level46_F248_func_80013D44(void*, int, void*, int) __asm__("func_80013D44");
void Level46_F248_func_80021ED8(int, int, int) __asm__("func_80021ED8");
int Level46_F248_func_80021F3C(int) __asm__("func_80021F3C");
int Level46_F248_func_8002803C(int, int, void*, void*, void*, void*, int) __asm__("func_8002803C");
void Level46_F248_func_80028154(int) __asm__("func_80028154");
void Level46_F248RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Level46_F248CountTimerDown(void*, int) __asm__("func_800359A4");
int Level46_F248RandBetween(int, int) __asm__("func_8003636C");
int Level46_F248_func_800369D8(int) __asm__("func_800369D8");
int Level46_F248_func_80037BBC(void*, int) __asm__("func_80037BBC");
void Level46_F248_func_8003B634(void*, void*, int) __asm__("func_8003B634");
void Level46_F248_func_8003B74C(void*) __asm__("func_8003B74C");
void Level46_F248_func_8003B7B4(void*, int, void*) __asm__("func_8003B7B4");
void Level46_F248PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
void Level46_F248_func_8003BB10(void*, int, int) __asm__("func_8003BB10");
int Level46_F248PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Level46_F248TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
void Level46_F248CopyVector(void*, void*) __asm__("func_8004F178");
void Level46_F248AddVector(void*, void*, void*) __asm__("func_8004F194");
void Level46_F248_func_800512E4(void*, int, int) __asm__("func_800512E4");
void Level46_F248RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
extern int Level46_F248_D_800658A0 __asm__("D_800658A0");
extern int Level46_F248_D_80065920 __asm__("D_80065920");
extern int Level46_F248_D_8006C550 __asm__("D_8006C550");
extern int Level46_F248_D_8006C58C __asm__("D_8006C58C");
extern int Level46_F248_D_8006C598 __asm__("D_8006C598");
extern int Level46_F248_D_8006C648 __asm__("D_8006C648");
extern int Level46_F248_D_8006C730 __asm__("D_8006C730");
extern int Level46_F248_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level46_F248_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level46_F248_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level46_F248_D_8006D088 __asm__("D_8006D088");
extern int Level46_F248_D_8006E044 __asm__("D_8006E044");
extern int Level46_F248_D_8006E048 __asm__("D_8006E048");
extern int Level46_F248_D_8006E344 __asm__("D_8006E344");
extern int Level46_F248_D_8006E53C __asm__("D_8006E53C");
extern int Level46_F248_D_80070300 __asm__("D_80070300");
extern int Level46_F248_D_80070328 __asm__("D_80070328");
extern int Level46_F248_D_level_46_80091B40 __asm__("D_level_46_80091B40");
extern int (*Level46_F248_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level46_F248_SpawnParticle)() __asm__("SpawnParticle");
extern int Level46_F248_func_80027A60 __asm__("func_80027A60");
extern int Level46_F248_func_80027EE4 __asm__("func_80027EE4");
extern int Level46_F248_func_80029AA0 __asm__("func_80029AA0");
extern int Level46_F248_func_level_46_80074E40 __asm__("func_level_46_80074E40");
extern int Level46_F248_main_TEXT_END __asm__("main_TEXT_END");
extern int Level46_F248_main_TEXT_START __asm__("main_TEXT_START");
void func_level_46_8007F248(void* ownerParameter) {
    register int frameOrPath16 __asm__("$16"), retainedSelector17 __asm__("$17"),
        vectorOrPosition18 __asm__("$18"), owner19 __asm__("$19"), private20 __asm__("$20"),
        checksumOrField21 __asm__("$21"), checksumOrField22 __asm__("$22"),
        checksumOrField23 __asm__("$23");
    register int resultOrArithmetic2 __asm__("$2"), fieldOrAddress3 __asm__("$3"),
        argumentOrAddress4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC, spF0, spF4, spF8, spFC;
    } originalFrame;
    int countedState42;
    int captured_a0_10;
    int captured_a0_14;
    int captured_a0_6;
    int captured_a3;
    int captured_v0_19;
    int captured_v0_21;
    int captured_v0_32;
    int captured_v0_8;
    int captured_v1_12;
    int captured_v1_14;
    int captured_v1_15;
    int captured_v1_8;
    int working_v0_10;
    int working_v0_5;
    int working_v0_8;
    int working_v0_9;
    int working_v1;
    int captured_v0_6;
    int captured_v0_7;
    int captured_v1_6;
    int working_v0_7;
    int captured_a0_11;
    int captured_a0_13;
    int captured_a0_15;
    int captured_a0_17;
    int captured_a1_2;
    int captured_a1_3;
    int captured_v0;
    int captured_v0_22;
    int captured_v0_3;
    int captured_v0_5;
    int captured_v0_9;
    int captured_v1_17;
    int captured_v1_20;
    int captured_a0;
    int captured_a0_16;
    int captured_a0_3;
    int captured_a0_4;
    int captured_a0_5;
    int captured_a0_7;
    int captured_a0_9;
    int captured_a2;
    int captured_a2_3;
    int captured_v0_20;
    int captured_v0_2;
    int captured_v0_4;
    int captured_v1_10;
    int captured_v1_11;
    int captured_v1_16;
    int captured_v1_18;
    int captured_v1_19;
    int captured_v1_9;
    owner19 = (int)ownerParameter;
    Level46_F248CompleteValue(owner19);
    private20 = Level46_F248Field(owner19, int*, 0);
    resultOrArithmetic2 = Level46_F248Field(private20, int*, 0xC0);
    fieldOrAddress3 = (int)&Level46_F248_func_level_46_80074E40;
    if ((unsigned int)resultOrArithmetic2 >= (unsigned int)fieldOrAddress3) {
        argumentOrField5 = 0;
        argumentOrField6 = (int)&Level46_F248_D_level_46_80091B40;
        Level46_F248CompleteValue(argumentOrField6);
    actor2510OverlayCrcByte:
        fieldOrAddress3 = Level46_F248Field(private20, int*, 0xC0);
        if ((unsigned int)fieldOrAddress3 < (unsigned int)argumentOrField6) {
            argumentOrAddress4 = 0;
            resultOrArithmetic2 = Level46_F248Field(fieldOrAddress3, unsigned char*, 0);
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0xBC);
            resultOrArithmetic2 <<= 8;
            fieldOrAddress3 ^= resultOrArithmetic2;
            Level46_F248Field(private20, int*, 0xBC) = fieldOrAddress3;
            do {
                fieldOrAddress3 = Level46_F248Field(private20, int*, 0xBC);
                resultOrArithmetic2 = fieldOrAddress3 & 0x8000;
                if (fieldOrAddress3 & 0x8000)
                    resultOrArithmetic2 = (unsigned int)fieldOrAddress3 * 2U ^ 0x8005;
                else
                    resultOrArithmetic2 = (unsigned int)fieldOrAddress3 * 2U;
                Level46_F248Field(private20, int*, 0xBC) = resultOrArithmetic2;
                argumentOrAddress4++;
                resultOrArithmetic2 = argumentOrAddress4 < 8;
            } while (resultOrArithmetic2);
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0xC0);
            argumentOrField5++;
            resultOrArithmetic2++;
            Level46_F248Field(private20, int*, 0xC0) = resultOrArithmetic2;
            resultOrArithmetic2 = argumentOrField5 < 64;
            if (resultOrArithmetic2)
                goto actor2510OverlayCrcByte;
        }
    }
    resultOrArithmetic2 = Level46_F248Field(private20, int*, 0xC0);
    if (!resultOrArithmetic2) {
        resultOrArithmetic2 = Level46_F248_D_8006C58C;
        fieldOrAddress3 = (int)&Level46_F248_main_TEXT_START + 2;
        resultOrArithmetic2 += fieldOrAddress3;
        Level46_F248Field(private20, int*, 0xC0) = resultOrArithmetic2;
        resultOrArithmetic2 = Level46_F248Field(private20, volatile int*, 0xC0);
    }
    fieldOrAddress3 = (int)&Level46_F248_main_TEXT_END;
    if ((unsigned int)resultOrArithmetic2 < (unsigned int)fieldOrAddress3) {
        argumentOrField5 = 0;
        argumentOrField6 = fieldOrAddress3;
        Level46_F248CompleteValue(argumentOrField6);
    actor2510MainCrcByte:
        /* Original CRC byte/bit loop; unsigned32 shifts retain the original low32 domain. */
        fieldOrAddress3 = Level46_F248Field(private20, int*, 0xC0);
        if ((unsigned int)fieldOrAddress3 < (unsigned int)argumentOrField6) {
            argumentOrAddress4 = 0;
            resultOrArithmetic2 = Level46_F248Field(fieldOrAddress3, unsigned char*, 0);
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0xBC);
            resultOrArithmetic2 <<= 8;
            fieldOrAddress3 ^= resultOrArithmetic2;
            Level46_F248Field(private20, int*, 0xBC) = fieldOrAddress3;
            do {
                fieldOrAddress3 = Level46_F248Field(private20, int*, 0xBC);
                resultOrArithmetic2 = fieldOrAddress3 & 0x8000;
                if (fieldOrAddress3 & 0x8000)
                    resultOrArithmetic2 = (unsigned int)fieldOrAddress3 * 2U ^ 0x8005;
                else
                    resultOrArithmetic2 = (unsigned int)fieldOrAddress3 * 2U;
                Level46_F248Field(private20, int*, 0xBC) = resultOrArithmetic2;
                argumentOrAddress4++;
                resultOrArithmetic2 = argumentOrAddress4 < 8;
            } while (resultOrArithmetic2);
            argumentOrField5++;
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0xBC);
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0xC0);
            resultOrArithmetic2 &= 3;
            resultOrArithmetic2++;
            fieldOrAddress3 += resultOrArithmetic2;
            Level46_F248Field(private20, int*, 0xC0) = fieldOrAddress3;
            resultOrArithmetic2 = argumentOrField5 < 64;
            if (resultOrArithmetic2)
                goto actor2510MainCrcByte;
            resultOrArithmetic2 = (int)&Level46_F248_main_TEXT_END;
            if ((unsigned int)fieldOrAddress3 < (unsigned int)resultOrArithmetic2)
                goto actor2510ChecksumDone;
        }
        resultOrArithmetic2 = (int)&Level46_F248_func_level_46_80074E40;
        Level46_F248Field(private20, int*, 0xC0) = resultOrArithmetic2;
    }
actor2510ChecksumDone:
    if ((Level46_F248Field(private20, unsigned int*, 0xC0) ==
         (int)&Level46_F248_D_level_46_80091B40) &&
        (Level46_F248Field(private20, int*, 0xBC) != 0)) {
        Level46_F248Field((int)&Level46_F248_D_80070300, signed char*, 6) = 0;
        Level46_F248Field((int)&Level46_F248_D_80070300, signed char*, 0xF) = 0;
        Level46_F248Field((int)&Level46_F248_D_80070300, signed char*, 0x18) = 0;
        Level46_F248Field((int)&Level46_F248_D_80070300, signed char*, 0x21) = 0;
        Level46_F248Field(private20, int*, 0xBC) = 0;
    }
block_23:
    captured_v1_6 = Level46_F248Field(owner19, unsigned char*, 0x48);
    if (captured_v1_6 >= 0x53U) {
        goto block_309;
    }
    switch (captured_v1_6) {
        default:
            goto block_309;
        case 0x0:
            if (Level46_F248_func_800369D8(0x14) != 0) {
                goto block_27;
            }
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x60);
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = 2U;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 1;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, signed char*, 5) = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_F248Field(fieldOrAddress3, unsigned short*, 2);
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2++;
            Level46_F248Field(fieldOrAddress3, unsigned short*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 5;
            goto block_308;
        block_27:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248Field(private20, unsigned char*, 2) = 0U;
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            resultOrArithmetic2 = 2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = 1;
            Level46_F248CompleteValue(fieldOrAddress3);
            Level46_F248Field(owner19, volatile unsigned char*, 0x49) = resultOrArithmetic2;
            Level46_F248Field(owner19, unsigned char*, 0x48) = fieldOrAddress3;
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
            goto block_205;
        case 0x1:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0x60);
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(resultOrArithmetic2, unsigned short*, 2) = 0;
            resultOrArithmetic2 = 2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(2));
            resultOrArithmetic2 = 0x3C;
            goto block_308;
        case 0x2:
            if (Level46_F248_func_800369D8(0x14) != 0) {
                goto block_33;
            }
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            fieldOrAddress3 = 1;
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
            resultOrArithmetic2++;
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 5;
            goto block_308;
        block_33:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 4U;
            resultOrArithmetic2 = 3;
            goto block_203;
        case 0x3:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 4U;
            goto block_224;
        case 0x4:
            if (Level46_F248_func_800369D8(0x14) != 0) {
                goto block_309;
            }
        case 0x5:
            Level46_F248Field(
                ((Level46_F248Field(private20, int*, 0xB4) * 0x58) + Level46_F248_D_8006C550),
                signed char*, 0x49) = 1;
            Level46_F248Field(
                ((Level46_F248Field(private20, int*, 0xB8) * 0x58) + Level46_F248_D_8006C550),
                signed char*, 0x49) = 1;
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3CU;
            Level46_F248Field(owner19, unsigned char*, 0x49) = 6U;
            return;
        case 0x4C:
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            resultOrArithmetic2 = 2U;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 1;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, signed char*, 5) = resultOrArithmetic2;
            resultOrArithmetic2 = 6;
            goto block_308;
        case 0x6:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x4CU;
            Level46_F248_func_8003B7B4((void*)(private20 + 5), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0xC), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B634(
                (void*)((int)&Level46_F248_D_8006D088), (void*)((int)&Level46_F248_D_80070328),
                Level46_F248Field((int)&Level46_F248_D_80070328, unsigned char*, 0xE));
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            resultOrArithmetic2 = 8U;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
            resultOrArithmetic2 = 7;
            goto block_203;
        case 0x7:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            argumentOrAddress4 = owner19;
            Level46_F248CompleteValue(argumentOrAddress4);
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x78);
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x58;
            fieldOrAddress3 = Level46_F248_D_8006C550 + resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = Level46_F248Field(fieldOrAddress3, int*, 0);
            Level46_F248Field(resultOrArithmetic2, signed char*, 7) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 8U;
            Level46_F248RequestMobyAnimation((void*)(argumentOrAddress4), 3);
            argumentOrAddress4 = 0x110;
            argumentOrField5 = owner19;
            Level46_F248CompleteValue(argumentOrAddress4);
            Level46_F248CompleteValue(argumentOrField5);
            fieldOrAddress3 = (int)Level46_F248_SpawnMoby;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = 0x6E;
            Level46_F248Field(private20, int*, 0x68) = resultOrArithmetic2;
            captured_v0 = ((int (*)())fieldOrAddress3)(argumentOrAddress4, argumentOrField5);
            if (captured_v0 == 0) {
                goto block_309;
            }
            Level46_F248Field(Level46_F248Field(captured_v0, int*, 0), signed char*, 2) = 2;
            return;
        case 0x8:
            if (Level46_F248Field(owner19, unsigned char*, 0x3D) != 3) {
                goto block_47;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 6);
        block_47:
            if (Level46_F248Field(owner19, unsigned char*, 0x3C) != 6) {
                goto block_309;
            }
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            captured_v1_8 = Level46_F248Field(private20, int*, 0x74);
            if (captured_v1_8 < 0) {
                goto block_309;
            }
            captured_a0 = Level46_F248_D_8006C550 + (captured_v1_8 * 0x58);
            if (Level46_F248Field(captured_a0, unsigned char*, 0x48) == 4) {
                goto block_52;
            }
            Level46_F248Field(captured_a0, unsigned char*, 0x48) = 4U;
        block_52:
            Level46_F248RequestMobyAnimation((void*)(owner19), 0);
            Level46_F248Field(private20, signed char*, 5) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 9U;
            working_v1 = Level46_F248Field(private20, int*, 0xB4);
            working_v0_5 = working_v1 * 2;
            goto block_62;
        case 0x9:
            if (Level46_F248Field(private20, int*, 0x64) <= 0) {
                goto block_55;
            }
            resultOrArithmetic2 = 1;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, signed char*, 5) = resultOrArithmetic2;
            resultOrArithmetic2 = 0xC;
            goto block_308;
        block_55:
            if (Level46_F248Field(owner19, unsigned char*, 0x3C) != 0) {
                goto block_309;
            }
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            goto block_225;
        case 0xA:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0xBU;
            goto block_224;
        case 0xB:
            if (Level46_F248Field(private20, int*, 0x64) <= 0) {
                goto block_309;
            }
        case 0xC:
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x7C);
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x58;
            fieldOrAddress3 = Level46_F248_D_8006C550 + resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = Level46_F248Field(fieldOrAddress3, int*, 0);
            Level46_F248Field(resultOrArithmetic2, signed char*, 7) = 0;
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3CU;
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0xDU;
            working_v1 = Level46_F248Field(private20, int*, 0xB8);
            working_v0_5 = working_v1 * 2;
        block_62:
            Level46_F248Field(
                (((((working_v0_5 + working_v1) * 4) - working_v1) * 8) + Level46_F248_D_8006C550),
                signed char*, 0x49) = 0;
            return;
        case 0x52:
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0xDU;
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0xC), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
        case 0xD:
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0x64);
            fieldOrAddress3 = 1;
            if (resultOrArithmetic2 <= 0) {
                goto block_66;
            }
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
            resultOrArithmetic2++;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            __asm__ volatile("" ::"r"(owner19) : "memory", "$2");
            resultOrArithmetic2 = 0x10;
            goto block_308;
        block_66:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0xFU;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0xEU;
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            Level46_F248Field(private20, unsigned char*, 5) = 0;
            goto block_205;
        case 0xE:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x50U;
            goto block_224;
        case 0x50:
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0x64);
            fieldOrAddress3 = 1;
            if (resultOrArithmetic2 <= 0) {
                goto block_72;
            }
            Level46_F248CompleteValue(owner19);
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
            resultOrArithmetic2++;
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x10;
            goto block_308;
        block_72:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            resultOrArithmetic2 = 0x51;
            goto block_203;
        case 0x51:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0xFU;
            goto block_224;
        case 0xF:
            if (Level46_F248Field(private20, int*, 0x64) <= 0) {
                goto block_309;
            }
        case 0x10:
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x13U;
            captured_v1_9 = Level46_F248Field(private20, int*, 0x60);
            Level46_F248Field(captured_v1_9, unsigned short*, 2) =
                (unsigned short)(Level46_F248Field(captured_v1_9, unsigned short*, 2) + 2);
            Level46_F248Field(private20, unsigned char*, 2) = 5U;
            goto block_155;
        case 0x11:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x13U;
            resultOrArithmetic2 = 0x12;
            goto block_203;
        case 0x12:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            captured_v1_10 =
                Level46_F248_D_8006C550 + (Level46_F248Field(private20, int*, 0x74) * 0x58);
            if (Level46_F248Field(captured_v1_10, unsigned char*, 0x48) == 7) {
                goto block_83;
            }
            Level46_F248Field(captured_v1_10, unsigned char*, 0x48) = 7U;
        block_83:
            captured_v1_11 =
                Level46_F248_D_8006C550 + (Level46_F248Field(private20, int*, 0x80) * 0x58);
            if (Level46_F248Field(captured_v1_11, unsigned char*, 0x48) == 7) {
                goto block_85;
            }
            Level46_F248Field(captured_v1_11, unsigned char*, 0x48) = 7U;
        block_85:
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0xB4);
            argumentOrAddress4 = 2;
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            fieldOrAddress3 = Level46_F248_D_8006C550;
            resultOrArithmetic2 *= 8;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(resultOrArithmetic2, signed char*, 0x49) = argumentOrAddress4;
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0xB8);
            argumentOrField6 = 10;
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            fieldOrAddress3 = Level46_F248_D_8006C550;
            resultOrArithmetic2 *= 8;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(resultOrArithmetic2, signed char*, 0x49) = argumentOrAddress4;
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x78);
            argumentOrField5 = 3;
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            fieldOrAddress3 = Level46_F248_D_8006C550;
            resultOrArithmetic2 *= 8;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(resultOrArithmetic2, signed char*, 0x49) = argumentOrField6;
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x7C);
            argumentOrAddress4 = owner19;
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            fieldOrAddress3 = Level46_F248_D_8006C550;
            resultOrArithmetic2 *= 8;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(resultOrArithmetic2, signed char*, 0x49) = argumentOrField6;
            resultOrArithmetic2 = 0x14;
            goto block_234;
        case 0x13:
            argumentOrAddress4 = Level46_F248Field(private20, int*, 0x80);
            if (argumentOrAddress4 < 0) {
                goto block_309;
            }
            captured_a0_3 = Level46_F248_D_8006C550 + (argumentOrAddress4 * 0x58);
            if (Level46_F248Field(captured_a0_3, unsigned char*, 0x48) == 4) {
                goto block_89;
            }
            Level46_F248Field(captured_a0_3, unsigned char*, 0x48) = 4U;
        block_89:
            Level46_F248Field(owner19, volatile unsigned char*, 0x49) = 0x11U;
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(17));
            resultOrArithmetic2 = 0x3C;
            goto block_308;
        case 0x14:
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x17U;
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x17U;
            Level46_F248Field(private20, signed char*, 5) = 1;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x15U;
            Level46_F248_func_8003B7B4((void*)(private20 + 5), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            vectorOrPosition18 = owner19 + 0xC;
            Level46_F248_func_8003B7B4((void*)(vectorOrPosition18), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248Field(private20, unsigned char*, 2) =
                (unsigned char)(Level46_F248Field(private20, unsigned char*, 2) + 1);
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 4);
            originalFrame.sp20 = 0x800;
            originalFrame.sp24 = 0;
            originalFrame.sp28 = 0;
            Level46_F248TransformVectorByBasis((void*)(owner19 + 0x20),
                                               (void*)(&originalFrame.sp20),
                                               (void*)(&originalFrame.sp20));
            Level46_F248AddVector((void*)(&originalFrame.sp20), (void*)(vectorOrPosition18),
                                  (void*)(&originalFrame.sp20));
            Level46_F248_func_8003B634(
                (void*)((int)&Level46_F248_D_8006D088), (void*)(&originalFrame.sp20),
                (Level46_F248Field(owner19, unsigned char*, 0x46) + 0x80) & 0xFF);
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248RequestMobyAnimation((void*)(owner19), 6);
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x17U;
            return;
        case 0x15:
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(private20, signed char*, 5) = 2;
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x16U;
            Level46_F248Field(private20, int*, 0x68) = 0x20;
            goto block_204;
        case 0x16:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            argumentOrAddress4 = owner19;
            Level46_F248CompleteValue(argumentOrAddress4);
            argumentOrField5 = 6;
            resultOrArithmetic2 = 0x17;
            Level46_F248Field(private20, int*, 0x64) = 0;
            goto block_234;
        case 0x17:
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 0);
            Level46_F248CopyVector(
                (void*)(&originalFrame.sp30),
                (void*)(Level46_F248Field(Level46_F248Field(private20, int*, 0x9C), int*, 0xC)));
            originalFrame.sp38 -= 0x800;
            captured_v0_2 = Level46_F248Field(Level46_F248Field(private20, int*, 0x9C), int*, 0xC);
            captured_a3 = Level46_F248Field(captured_v0_2, int*, 0x10);
            Level46_F248_func_80013D44((void*)(&originalFrame.sp30),
                                       Level46_F248PlanarHeadingLookup(
                                           captured_a3 - Level46_F248Field(captured_v0_2, int*, 0),
                                           Level46_F248Field(captured_v0_2, int*, 0x14) -
                                               Level46_F248Field(captured_v0_2, int*, 4),
                                           0),
                                       (void*)(0), 0x73);
            resultOrArithmetic2 = 0x10000002;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x20C) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x18;
            goto block_308;
        case 0x18:
            resultOrArithmetic2 = 0x10000000;
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248_D_8006E044;
            resultOrArithmetic2 |= 2;
            Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x20C) = resultOrArithmetic2;
            if (fieldOrAddress3 == 0xB) {
                goto block_309;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            captured_v1_12 = Level46_F248Field(private20, int*, 0x84);
            if (captured_v1_12 < 0) {
                goto block_100;
            }
            Level46_F248Field(
                Level46_F248Field((captured_v1_12 * 0x58) + Level46_F248_D_8006C550, int*, 0), int*,
                0) = 0;
        block_100:
            Level46_F248Field(private20, int*, 0x68) = 0x3C;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x19U;
            resultOrArithmetic2 = Level46_F248_func_8002803C(
                0x17, 0x1CD, (void*)((int)&Level46_F248_func_80027EE4),
                (void*)((int)&Level46_F248_func_80027A60),
                (void*)((int)&Level46_F248_func_80029AA0), (void*)(private20 + 0x64), 6);
            argumentOrAddress4 = owner19;
            argumentOrField5 = 7;
            argumentOrField6 = 0;
            Level46_F248CompleteValue(argumentOrAddress4);
            Level46_F248CompleteValue(argumentOrField5);
            Level46_F248CompleteValue(argumentOrField6);
            resultOrArithmetic2 = (short)resultOrArithmetic2;
            Level46_F248Field(private20, int*, 0xA8) = resultOrArithmetic2;
            Level46_F248_func_8003BB10((void*)(argumentOrAddress4), argumentOrField5,
                                       argumentOrField6);
            Level46_F248_func_80021ED8(2, 0xFC, 0);
            Level46_F248Field(private20, int*, 0xA0) =
                (int)(Level46_F248Field(owner19, int*, 0x14) + 0x708);
            return;
        case 0x19:
            if (Level46_F248Field(private20, int*, 0x64) < 6) {
                goto block_104;
            }
            if (Level46_F248CountTimerDown((void*)(private20 + 0x68), 4) == 0) {
                goto block_104;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 4);
            originalFrame.sp40 = 0x800;
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0;
            Level46_F248TransformVectorByBasis((void*)(owner19 + 0x20),
                                               (void*)(&originalFrame.sp40),
                                               (void*)(&originalFrame.sp40));
            Level46_F248AddVector((void*)(&originalFrame.sp40), (void*)(owner19 + 0xC),
                                  (void*)(&originalFrame.sp40));
            Level46_F248_func_80013D44(
                (void*)(&originalFrame.sp40),
                (Level46_F248Field(owner19, unsigned char*, 0x46) + 0x80) & 0xFF, (void*)(0), 0x73);
            Level46_F248_func_80028154(Level46_F248Field(private20, int*, 0xA8));
            resultOrArithmetic2 = 0x1A;
            goto block_308;
        block_104:
            if (((Level46_F248_func_80021F3C(2) >> 8) & 0xFF) != 0x20) {
                goto block_309;
            }
            if (Level46_F248Field((int)&Level46_F248_D_80070328, int*, 8) >=
                Level46_F248Field(private20, int*, 0xA0)) {
                goto block_309;
            }
            if (Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x280) < 0) {
                goto block_309;
            }
            Level46_F248_func_8003B74C((void*)((int)&Level46_F248_D_8006D088));
            return;
        case 0x1A:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            resultOrArithmetic2 = 0x1B;
            goto block_203;
        case 0x1B:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(Level46_F248Field((Level46_F248Field(private20, int*, 0xAC) * 0x58) +
                                                    Level46_F248_D_8006C550,
                                                int*, 0),
                              short*, 2) = 1;
            Level46_F248Field(Level46_F248Field((Level46_F248Field(private20, int*, 0xB0) * 0x58) +
                                                    Level46_F248_D_8006C550,
                                                int*, 0),
                              short*, 2) = 1;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x40U;
            Level46_F248_func_8003B7B4((void*)(private20 + 5), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0xC), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B634(
                (void*)((int)&Level46_F248_D_8006D088), (void*)((int)&Level46_F248_D_80070328),
                Level46_F248Field((int)&Level46_F248_D_80070328, unsigned char*, 0xE));
            captured_v0_3 = Level46_F248_SpawnMoby(0x110, owner19);
            if (captured_v0_3 == 0) {
                goto block_113;
            }
            Level46_F248Field(Level46_F248Field(captured_v0_3, int*, 0), signed char*, 2) = 2;
        block_113:
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3CU;
            Level46_F248_func_8003BB10((void*)(owner19), 8, 0);
            Level46_F248_func_80021ED8(1, 0xFC, 0);
            goto block_115;
        case 0x40:
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            argumentOrAddress4 = owner19;
            argumentOrField5 = 8;
            argumentOrField6 = 0;
            Level46_F248CompleteValue(argumentOrAddress4);
            Level46_F248CompleteValue(argumentOrField5);
            Level46_F248CompleteValue(argumentOrField6);
            resultOrArithmetic2 = 1;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, signed char*, 5) = resultOrArithmetic2;
            Level46_F248Field(private20, unsigned char*, 2) = 8U;
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3CU;
            Level46_F248_func_8003BB10((void*)(argumentOrAddress4), argumentOrField5,
                                       argumentOrField6);
        block_115:
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x1CU;
            return;
        case 0x1C:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x1EU;
            resultOrArithmetic2 = 0x1D;
            goto block_203;
        case 0x1D:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x1EU;
            goto block_224;
        case 0x1E:
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x88);
            if (fieldOrAddress3 < 0) {
                goto block_309;
            }
            captured_a0_4 = Level46_F248_D_8006C550 + (fieldOrAddress3 * 0x58);
            if (Level46_F248Field(captured_a0_4, unsigned char*, 0x48) == 4) {
                goto block_123;
            }
            __asm__ volatile("" ::"r"(owner19) : "memory", "$2");
            resultOrArithmetic2 = 4;
            Level46_F248Field(captured_a0_4, unsigned char*, 0x48) = resultOrArithmetic2;
        block_123:
            resultOrArithmetic2 = (int)(short)Level46_F248_func_8002803C(
                0x17, 0x1CF, (void*)((int)&Level46_F248_func_80027EE4),
                (void*)((int)&Level46_F248_func_80027A60),
                (void*)((int)&Level46_F248_func_80029AA0), (void*)(private20 + 0x64), 6);
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, int*, 0xA8) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x4EU;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(78));
            resultOrArithmetic2 = 0x3C;
            goto block_308;
        case 0x4E:
            Level46_F248Field(private20, int*, 0x68) = 0x3C;
            resultOrArithmetic2 = 0x1F;
            goto block_308;
        case 0x1F:
            argumentOrField6 = 0;
            Level46_F248CompleteValue(argumentOrField6);
            countedState42 = 42;
            Level46_F248CompleteValue(countedState42);
            resultOrArithmetic2 = Level46_F248_D_8006C730;
            argumentOrField7 = Level46_F248_D_8006C550;
            Level46_F248CompleteValue(argumentOrField7);
            argumentOrAddress4 = Level46_F248Field(resultOrArithmetic2, int*, 0x54);
        loop_126:
            /* Original packed-tag scan: increment A0 occurs after reading/testing the current tag. */
            argumentOrField5 = Level46_F248Field(argumentOrAddress4, unsigned short*, 0);
            Level46_F248CompleteValue(argumentOrField5);
            resultOrArithmetic2 = argumentOrField5 & 0x7FFF;
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = resultOrArithmetic2 * 0x58 + argumentOrField7;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = Level46_F248Field(fieldOrAddress3, unsigned char*, 0x48);
            if (resultOrArithmetic2 == countedState42)
                argumentOrField6++;
            resultOrArithmetic2 = argumentOrField5 << 16;
            argumentOrAddress4 += 2;
            if (resultOrArithmetic2 >= 0)
                goto loop_126;
            resultOrArithmetic2 = argumentOrField6 < 6;
            Level46_F248CompleteValue(resultOrArithmetic2);
            if (resultOrArithmetic2)
                goto block_309;
            if (Level46_F248CountTimerDown((void*)(private20 + 0x68), 4) == 0) {
                goto block_309;
            }
            fieldOrAddress3 = Level46_F248Field(private20, int*, 0x88);
            Level46_F248CompleteValue(fieldOrAddress3);
            captured_a0_5 = Level46_F248_D_8006C550 + fieldOrAddress3 * 0x58;
            if (Level46_F248Field(captured_a0_5, unsigned char*, 0x48) == 7) {
                goto block_133;
            }
            Level46_F248Field(captured_a0_5, unsigned char*, 0x48) = 7U;
        block_133:
            resultOrArithmetic2 = Level46_F248_D_8006C730;
            __asm__ volatile("" ::"r"(owner19) : "memory", "$5");
            argumentOrField5 = 0x2C;
            argumentOrAddress4 = Level46_F248Field(resultOrArithmetic2, int*, 0x54);
        loop_134:
            /* Original current signed tag reload precedes the always-executed A0 increment. */
            fieldOrAddress3 = Level46_F248Field(argumentOrAddress4, unsigned short*, 0);
            fieldOrAddress3 &= 0x7FFF;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x58;
            fieldOrAddress3 = Level46_F248_D_8006C550;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(resultOrArithmetic2, signed char*, 0x48) = argumentOrField5;
            resultOrArithmetic2 = Level46_F248Field(argumentOrAddress4, short*, 0);
            argumentOrAddress4 += 2;
            if (resultOrArithmetic2 >= 0)
                goto loop_134;
            resultOrArithmetic2 = Level46_F248_D_8006C7B4;
            fieldOrAddress3 = Level46_F248Field(owner19, int*, 0);
            resultOrArithmetic2 |= 4;
            Level46_F248_D_8006C7B4 = resultOrArithmetic2;
            resultOrArithmetic2 = 2;
            Level46_F248Field(fieldOrAddress3, signed char*, 5) = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_F248Field(owner19, unsigned char*, 0x46);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$16");
            frameOrPath16 = (int)&originalFrame.sp50;
            resultOrArithmetic2 *= 2;
            fieldOrAddress3 =
                Level46_F248Field((int)&Level46_F248_D_80065920, short*, resultOrArithmetic2);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$4");
            argumentOrAddress4 = frameOrPath16;
            resultOrArithmetic2 = (fieldOrAddress3 * 0x27) >> 6;
            originalFrame.sp50 = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_F248Field(owner19, unsigned char*, 0x46);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$5");
            argumentOrField5 = frameOrPath16;
            resultOrArithmetic2 *= 2;
            fieldOrAddress3 =
                Level46_F248Field((int)&Level46_F248_D_800658A0, short*, resultOrArithmetic2);
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x44);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$6");
            argumentOrField6 = owner19 + 0xC;
            *(volatile int*)&originalFrame.sp58 = 0;
            originalFrame.sp58 = resultOrArithmetic2;
            resultOrArithmetic2 = (fieldOrAddress3 * 0x27) >> 6;
            originalFrame.sp54 = resultOrArithmetic2;
            Level46_F248AddVector((void*)(argumentOrAddress4), (void*)(argumentOrField5),
                                  (void*)(argumentOrField6));
            Level46_F248_func_80013D44(
                (void*)(frameOrPath16),
                (Level46_F248Field(owner19, unsigned char*, 0x46) + 0x80) & 0xFF, (void*)(0), 0x73);
            if (Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x280) >= 0) {
                goto block_137;
            }
            Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x280) = 0;
        block_137:
            Level46_F248_func_80028154(Level46_F248Field(private20, int*, 0xA8));
            resultOrArithmetic2 = 0x20;
            Level46_F248Field(private20, int*, 0x64) = 0;
            goto block_308;
        case 0x20:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x22U;
            working_v0_7 = 0x21;
            goto block_154;
        case 0x21:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x48U;
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0xC), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B634(
                (void*)((int)&Level46_F248_D_8006D088), (void*)((int)&Level46_F248_D_80070328),
                Level46_F248Field((int)&Level46_F248_D_80070328, unsigned char*, 0xE));
            return;
        case 0x48:
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            if (Level46_F248_D_8006C598 == 0) {
                goto block_144;
            }
            Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x20C) =
                (int)(Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x20C) | 0x10000002);
            return;
        block_144:
            resultOrArithmetic2 = Level46_F248Field(owner19, int*, 0xC);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0);
            Level46_F248CompleteValue(fieldOrAddress3);
            working_v0_8 = resultOrArithmetic2 - fieldOrAddress3;
            if (working_v0_8 >= 0) {
                goto block_146;
            }
            working_v0_8 = -working_v0_8;
        block_146:
            if (working_v0_8 >= 0x2000) {
                goto block_309;
            }
            resultOrArithmetic2 = Level46_F248Field(owner19, int*, 0x10);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248Field((int)&Level46_F248_D_80070328, int*, 4);
            Level46_F248CompleteValue(fieldOrAddress3);
            working_v0_9 = resultOrArithmetic2 - fieldOrAddress3;
            if (working_v0_9 >= 0) {
                goto block_149;
            }
            working_v0_9 = -working_v0_9;
        block_149:
            if (working_v0_9 >= 0x2000) {
                goto block_309;
            }
            resultOrArithmetic2 = Level46_F248Field(owner19, int*, 0x14);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248Field((int)&Level46_F248_D_80070328, int*, 8);
            Level46_F248CompleteValue(fieldOrAddress3);
            working_v0_10 = resultOrArithmetic2 - fieldOrAddress3;
            if (working_v0_10 >= 0) {
                goto block_152;
            }
            working_v0_10 = -working_v0_10;
        block_152:
            if (working_v0_10 >= 0x800) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x22U;
            working_v0_7 = 0x4A;
        block_154:
            Level46_F248Field(owner19, unsigned char*, 0x48) = working_v0_7;
        block_155:
            resultOrArithmetic2 = 1;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, signed char*, 5) = resultOrArithmetic2;
            return;
        case 0x4A:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            if (Level46_F248Field(owner19, unsigned char*, 0x3D) != 3) {
                goto block_159;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 6);
        block_159:
            if (Level46_F248Field(owner19, unsigned char*, 0x3C) != 6) {
                goto block_309;
            }
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            captured_a0_6 = Level46_F248Field(Level46_F248Field(private20, int*, 0x98), int*, 0xC);
            Level46_F248_func_80013AE4((void*)(captured_a0_6), (void*)(captured_a0_6 + 0x10));
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x22U;
            Level46_F248RequestMobyAnimation((void*)(owner19), 0);
            resultOrArithmetic2 = 0x10000002;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x20C) = resultOrArithmetic2;
            return;
        case 0x22:
            resultOrArithmetic2 = 0x10000000;
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248_D_8006E048;
            resultOrArithmetic2 |= 2;
            Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x20C) = resultOrArithmetic2;
            if (fieldOrAddress3 != 2) {
                goto block_309;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            captured_v1_14 = Level46_F248Field(private20, int*, 0x8C);
            if (captured_v1_14 < 0) {
                goto block_309;
            }
            captured_v0_4 =
                Level46_F248Field((captured_v1_14 * 0x58) + Level46_F248_D_8006C550, int*, 0);
            Level46_F248Field(captured_v0_4, short*, 0) = 0;
            if (Level46_F248Field(captured_v0_4, int*, 0x1C) == 0) {
                goto block_166;
            }
            if (!(Level46_F248_D_8006E53C & 0x800)) {
                goto block_309;
            }
        block_166:
            resultOrArithmetic2 = Level46_F248_func_8002803C(
                0x17, 0x1CF, (void*)((int)&Level46_F248_func_80027EE4),
                (void*)((int)&Level46_F248_func_80027A60),
                (void*)((int)&Level46_F248_func_80029AA0), (void*)(private20 + 0x64), 0xC);
            argumentOrAddress4 = 1;
            Level46_F248CompleteValue(argumentOrAddress4);
            resultOrArithmetic2 = (short)resultOrArithmetic2;
            Level46_F248Field(private20, int*, 0xA8) = resultOrArithmetic2;
            Level46_F248Field(private20, int*, 0x68) = 0x3C;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x23U;
            Level46_F248_func_80013B7C(argumentOrAddress4);
            return;
        case 0x23:
            if (Level46_F248Field(private20, int*, 0x64) < 0xC) {
                goto block_309;
            }
            if (Level46_F248CountTimerDown((void*)(private20 + 0x68), 4) == 0) {
                goto block_309;
            }
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 4);
            originalFrame.sp60 = 0x800;
            originalFrame.sp64 = 0;
            originalFrame.sp68 = 0;
            Level46_F248TransformVectorByBasis((void*)(owner19 + 0x20),
                                               (void*)(&originalFrame.sp60),
                                               (void*)(&originalFrame.sp60));
            Level46_F248AddVector((void*)(&originalFrame.sp60), (void*)(owner19 + 0xC),
                                  (void*)(&originalFrame.sp60));
            Level46_F248_func_80013D44(
                (void*)(&originalFrame.sp60),
                (Level46_F248Field(owner19, unsigned char*, 0x46) + 0x80) & 0xFF, (void*)(0), 0x73);
            Level46_F248_func_80028154(Level46_F248Field(private20, int*, 0xA8));
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x24U;
            Level46_F248Field(private20, unsigned char*, 2) = 0xAU;
            return;
        case 0x24:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            resultOrArithmetic2 = 0x25;
            goto block_203;
        case 0x25:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            captured_v1_15 = Level46_F248Field(private20, int*, 0x90);
            if (captured_v1_15 < 0) {
                goto block_309;
            }
            captured_a0_7 = Level46_F248_D_8006C550 + (captured_v1_15 * 0x58);
            if (Level46_F248Field(captured_a0_7, unsigned char*, 0x48) == 2) {
                goto block_176;
            }
            Level46_F248Field(captured_a0_7, unsigned char*, 0x48) = 2U;
        block_176:
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x41U;
            Level46_F248_func_8003B7B4((void*)(private20 + 5), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0xC), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B634(
                (void*)((int)&Level46_F248_D_8006D088), (void*)((int)&Level46_F248_D_80070328),
                Level46_F248Field((int)&Level46_F248_D_80070328, unsigned char*, 0xE));
            captured_v0_5 = Level46_F248_SpawnMoby(0x110, owner19);
            if (captured_v0_5 == 0) {
                goto block_178;
            }
            Level46_F248Field(Level46_F248Field(captured_v0_5, int*, 0), signed char*, 2) = 2;
        block_178:
            resultOrArithmetic2 = 0x26U;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(38));
            resultOrArithmetic2 = 0x3C;
            goto block_308;
        case 0x41:
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            resultOrArithmetic2 = 1;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(private20, signed char*, 5) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x26U;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(38));
            resultOrArithmetic2 = 0x3C;
            goto block_308;
        case 0x26:
            if (Level46_F248_func_800369D8(0x16) != 0) {
                goto block_182;
            }
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            fieldOrAddress3 = 1;
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
            resultOrArithmetic2++;
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x2A;
            goto block_308;
        block_182:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x28U;
            resultOrArithmetic2 = 0x27;
            goto block_308;
        case 0x27:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x26U;
            goto block_224;
        case 0x28:
            if (Level46_F248_func_800369D8(0x16) != 0) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x2AU;
            return;
        case 0x29:
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3CU;
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x2BU;
            return;
        case 0x2A:
            if (Level46_F248Field(owner19, unsigned char*, 0x3D) != 3) {
                goto block_191;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 6);
        block_191:
            if (Level46_F248Field(owner19, unsigned char*, 0x3C) != 6) {
                goto block_309;
            }
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            argumentOrAddress4 = Level46_F248Field(private20, int*, 0x94);
            if (argumentOrAddress4 < 0) {
                goto block_309;
            }
            captured_a0_9 = Level46_F248_D_8006C550 + (argumentOrAddress4 * 0x58);
            if (Level46_F248Field(captured_a0_9, unsigned char*, 0x48) == 2) {
                goto block_196;
            }
            Level46_F248Field(captured_a0_9, unsigned char*, 0x48) = 2U;
        block_196:
            Level46_F248RequestMobyAnimation((void*)(owner19), 0);
            resultOrArithmetic2 = 0x29;
            goto block_308;
        case 0x2B:
            if (Level46_F248_func_800369D8(0x17) != 0) {
                goto block_199;
            }
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            fieldOrAddress3 = 1;
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
            resultOrArithmetic2++;
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x2E;
            goto block_308;
        block_199:
            if (Level46_F248_D_8006C770 == 0) {
                goto block_201;
            }
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
        block_201:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x2DU;
            resultOrArithmetic2 = 0x2C;
        block_203:
            /* Original shared state-byte store. Every incoming path supplies a complete V0 producer. */
            Level46_F248Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
        block_204:
            resultOrArithmetic2 = Level46_F248Field(private20, unsigned char*, 2);
            fieldOrAddress3 = 1;
            Level46_F248Field(private20, unsigned char*, 5) = fieldOrAddress3;
        block_205:
            /* Original shared increment starts at1699; predecessors own their actual LBU producers. */
            resultOrArithmetic2++;
            Level46_F248Field(private20, unsigned char*, 2) = resultOrArithmetic2;
            return;
        case 0x2C:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x2DU;
            goto block_224;
        case 0x2D:
            if (Level46_F248_func_800369D8(0x17) != 0) {
                goto block_309;
            }
        case 0x2E:
            Level46_F248Field(private20, int*, 0x64) = 0;
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3CU;
            Level46_F248Field(owner19, unsigned char*, 0x49) = 0x46U;
            return;
        case 0x46:
            Level46_F248Field(Level46_F248Field(owner19, int*, 0), signed char*, 5) = 2;
            resultOrArithmetic2 = Level46_F248Field(owner19, unsigned char*, 0x46);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$16");
            frameOrPath16 = (int)&originalFrame.sp70;
            resultOrArithmetic2 *= 2;
            fieldOrAddress3 =
                Level46_F248Field((int)&Level46_F248_D_80065920, short*, resultOrArithmetic2);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$4");
            argumentOrAddress4 = frameOrPath16;
            resultOrArithmetic2 = (fieldOrAddress3 * 0xD) >> 5;
            originalFrame.sp70 = resultOrArithmetic2;
            resultOrArithmetic2 = Level46_F248Field(owner19, unsigned char*, 0x46);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$5");
            argumentOrField5 = frameOrPath16;
            resultOrArithmetic2 *= 2;
            fieldOrAddress3 =
                Level46_F248Field((int)&Level46_F248_D_800658A0, short*, resultOrArithmetic2);
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x44);
            __asm__ volatile("" ::"r"(owner19) : "memory", "$6");
            argumentOrField6 = owner19 + 0xC;
            *(volatile int*)&originalFrame.sp78 = 0;
            originalFrame.sp78 = resultOrArithmetic2;
            resultOrArithmetic2 = (fieldOrAddress3 * 0xD) >> 5;
            originalFrame.sp74 = resultOrArithmetic2;
            Level46_F248AddVector((void*)(argumentOrAddress4), (void*)(argumentOrField5),
                                  (void*)(argumentOrField6));
            Level46_F248_func_80013D44(
                (void*)(frameOrPath16),
                (Level46_F248Field(owner19, unsigned char*, 0x46) + 0x80) & 0xFF, (void*)(0), 0);
            resultOrArithmetic2 = Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x280);
            Level46_F248CompleteValue(resultOrArithmetic2);
            if (resultOrArithmetic2 < 0) {
                Level46_F248Field((int)&Level46_F248_D_80070328, int*, 0x280) = 0;
            }
            resultOrArithmetic2 = 0x47;
            Level46_F248Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            return;
        case 0x47:
            if (Level46_F248_D_8006E044 == 0xB) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x2FU;
        case 0x2F:
            if (Level46_F248_func_80037BBC((void*)(owner19), 0) == 0) {
                goto block_309;
            }
            Level46_F248_D_8006C7B4 |= 1;
            Level46_F248_func_800512E4((void*)(owner19), 3, 5);
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x30U;
            Level46_F248Field(private20, signed char*, 5) = 0;
            return;
        case 0x30:
            if (Level46_F248_D_8006E344 == 1) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x31U;
            Level46_F248_func_8003B7B4((void*)(private20 + 5), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x48), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(Level46_F248Field(private20, int*, 0x60) + 2), 2,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(private20 + 2), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0xC), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x10), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x14), 4,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B7B4((void*)(owner19 + 0x46), 1,
                                       (void*)((int)&Level46_F248_D_8006C7F8));
            Level46_F248_func_8003B634(
                (void*)((int)&Level46_F248_D_8006D088), (void*)((int)&Level46_F248_D_80070328),
                Level46_F248Field((int)&Level46_F248_D_80070328, unsigned char*, 0xE));
            goto block_231;
        case 0x31:
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            captured_v0_6 = Level46_F248Field(private20, unsigned short*, 0xA4) - 1;
            Level46_F248Field(private20, unsigned short*, 0xA4) = captured_v0_6;
            if ((captured_v0_6 << 0x10) > 0) {
                goto block_221;
            }
            resultOrArithmetic2 = Level46_F248RandBetween(2, 4);
            argumentOrAddress4 = owner19;
            argumentOrField5 = 2;
            Level46_F248CompleteValue(argumentOrAddress4);
            Level46_F248CompleteValue(argumentOrField5);
            Level46_F248Field(private20, unsigned short*, 0xA4) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x33;
            goto block_234;
        block_221:
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x32U;
            Level46_F248RequestMobyAnimation((void*)(owner19), 1);
            return;
        case 0x33:
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x34U;
        block_224:
        block_225:
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            return;
        case 0x34:
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            captured_v0_7 = Level46_F248Field(private20, unsigned short*, 0xA6) - 1;
            Level46_F248Field(private20, unsigned short*, 0xA6) = captured_v0_7;
            if ((captured_v0_7 << 0x10) > 0) {
                goto block_309;
            }
            resultOrArithmetic2 = Level46_F248RandBetween(3, 5);
            argumentOrAddress4 = owner19;
            argumentOrField5 = 4;
            Level46_F248CompleteValue(argumentOrAddress4);
            Level46_F248CompleteValue(argumentOrField5);
            Level46_F248Field(private20, unsigned short*, 0xA6) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x35;
            goto block_234;
        case 0x32:
        case 0x35:
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x31U;
        block_231:
            Level46_F248RequestMobyAnimation((void*)(owner19), 0);
            return;
        case 0x3C:
            Level46_F248RequestMobyAnimation((void*)(owner19), 6);
            if (Level46_F248_D_8006C770 == 0) {
                goto block_309;
            }
            argumentOrAddress4 = owner19;
            Level46_F248CompleteValue(argumentOrAddress4);
            argumentOrField5 = 0;
            resultOrArithmetic2 = 0x3D;
            Level46_F248Field(private20, int*, 0x68) = 0;
        block_234:
            Level46_F248Field(argumentOrAddress4, signed char*, 0x48) = resultOrArithmetic2;
            Level46_F248RequestMobyAnimation((void*)(argumentOrAddress4), argumentOrField5);
            return;
        case 0x3D:
            captured_v0_8 = Level46_F248Field(private20, int*, 0x68);
            if (captured_v0_8 != 0) {
                goto block_239;
            }
            captured_v0_9 = Level46_F248_SpawnMoby(0x3E8, owner19);
            Level46_F248Field(private20, int*, 0x6C) = captured_v0_9;
            if (captured_v0_9 == 0) {
                goto block_238;
            }
            Level46_F248Field(captured_v0_9, int*, 0x14) =
                (int)(Level46_F248Field(captured_v0_9, int*, 0x14) - 0xC8);
            captured_v1_16 = Level46_F248Field(captured_v0_9, int*, 0);
            Level46_F248Field(private20, int*, 0x68) = 1;
            Level46_F248Field(captured_v1_16, short*, 2) = 0x19;
            Level46_F248Field(captured_v1_16, short*, 0x14) = 0xF;
            Level46_F248Field(captured_v1_16, short*, 0x16) = 0x1E;
        block_238:
            Level46_F248PlayMobySoundEvent((void*)(owner19), 0, 0);
            return;
        block_239:
            if (captured_v0_8 >= 0x1F4) {
                goto block_255;
            }
            captured_v1_17 = Level46_F248Field(private20, int*, 0x6C);
            captured_a0_10 = Level46_F248Field(captured_v1_17, int*, 0x14);
            captured_a2 = Level46_F248Field(captured_v1_17, int*, 0);
            if (Level46_F248Field(owner19, int*, 0x14) >= captured_a0_10) {
                goto block_242;
            }
            Level46_F248Field(owner19, int*, 0x54) = (int)(captured_a0_10 - 0x80000000);
        block_242:
            resultOrArithmetic2 = Level46_F248Field(captured_a2, short*, 0);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 >= 0x200) {
                goto block_244;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x2B;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2, short*, 0) = (short)resultOrArithmetic2;
            goto block_245;
        block_244:
            captured_a1_2 = Level46_F248Field(private20, int*, 0x6C);
            Level46_F248Field(captured_a1_2, int*, 0x14) =
                (int)(Level46_F248Field(captured_a1_2, int*, 0x14) +
                      (Level46_F248_D_8006C648 * 0x23));
        block_245:
            if (Level46_F248Field(captured_a2, short*, 0) < 0x101) {
                goto block_254;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a2, short*, 2);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 >= 0xC8) {
                goto block_248;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x1A;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2, short*, 2) = (short)resultOrArithmetic2;
        block_248:
            if (Level46_F248Field(captured_a2, short*, 0) < 0x101) {
                goto block_254;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a2, short*, 0x14);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            if (resultOrArithmetic2 >= 0x1E) {
                goto block_251;
            }
            resultOrArithmetic2 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = resultOrArithmetic2 * 2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = fieldOrAddress3 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2, short*, 0x14) = (short)resultOrArithmetic2;
        block_251:
            if (Level46_F248Field(captured_a2, short*, 0) < 0x101) {
                goto block_254;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a2, short*, 0x16);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 >= 0x50) {
                goto block_254;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 5;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2, short*, 0x16) = (short)resultOrArithmetic2;
        block_254:
            captured_a0_11 = Level46_F248Field(private20, int*, 0x6C);
            Level46_F248Field(captured_a0_11, unsigned char*, 0x46) =
                (unsigned char)(Level46_F248Field(captured_a0_11, unsigned char*, 0x46) +
                                (Level46_F248_D_8006C648 * 0x14));
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0x68);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248_D_8006C648;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(private20, int*, 0x68) = resultOrArithmetic2;
            resultOrArithmetic2 = resultOrArithmetic2 < 0x26;
            goto block_291;
        block_255:
            /* Original separate shrink phase: A1 timing is retained until its first complete constant product. */
            argumentOrField5 = Level46_F248_D_8006C648;
            argumentOrAddress4 = Level46_F248Field(private20, int*, 0x6C);
            fieldOrAddress3 = argumentOrField5 * 0x12;
            resultOrArithmetic2 = Level46_F248Field(argumentOrAddress4, int*, 0x14);
            argumentOrField6 = Level46_F248Field(argumentOrAddress4, int*, 0);
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(argumentOrAddress4, int*, 0x14) = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrField5);
            resultOrArithmetic2 = Level46_F248Field(argumentOrField6, short*, 0);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            if (resultOrArithmetic2 < 0x2C) {
                goto block_257;
            }
            resultOrArithmetic2 = argumentOrField5 * 0x2B;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = fieldOrAddress3 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(argumentOrField6, short*, 0) = (short)resultOrArithmetic2;
        block_257:
            if (Level46_F248Field(argumentOrField6, short*, 0) >= 0x17C) {
                goto block_260;
            }
            resultOrArithmetic2 = Level46_F248Field(argumentOrField6, short*, 2);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 < 0x15) {
                goto block_260;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x1A;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(argumentOrField6, short*, 2) = (short)resultOrArithmetic2;
        block_260:
            if (Level46_F248Field(argumentOrField6, short*, 2) >= 0x14) {
                goto block_262;
            }
            Level46_F248Field(argumentOrField6, short*, 2) =
                (short)(Level46_F248_D_8006C648 * 0x14);
        block_262:
            if (Level46_F248Field(argumentOrField6, short*, 0) >= 0x17C) {
                goto block_268;
            }
            resultOrArithmetic2 = Level46_F248Field(argumentOrField6, short*, 0x14);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            if (resultOrArithmetic2 < 0x10) {
                goto block_265;
            }
            resultOrArithmetic2 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = resultOrArithmetic2 * 2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = fieldOrAddress3 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(argumentOrField6, short*, 0x14) = (short)resultOrArithmetic2;
        block_265:
            if (Level46_F248Field(argumentOrField6, short*, 0) >= 0x17C) {
                goto block_268;
            }
            resultOrArithmetic2 = Level46_F248Field(argumentOrField6, short*, 0x16);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 < 0x1F) {
                goto block_268;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 5;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(argumentOrField6, short*, 0x16) = (short)resultOrArithmetic2;
        block_268:
            captured_a0_13 = Level46_F248Field(private20, int*, 0x6C);
            Level46_F248Field(captured_a0_13, unsigned char*, 0x46) =
                (unsigned char)(Level46_F248Field(captured_a0_13, unsigned char*, 0x46) +
                                (Level46_F248_D_8006C648 * 0x14));
            captured_v0_19 = Level46_F248Field(private20, int*, 0x68) + Level46_F248_D_8006C648;
            Level46_F248Field(private20, int*, 0x68) = captured_v0_19;
            if (captured_v0_19 < 0x264) {
                goto block_309;
            }
            Level46_F248_SpawnParticle(3, 0xC, Level46_F248Field(private20, int*, 0x6C), 5);
            Level46_F248Field(Level46_F248Field(private20, int*, 0x6C), signed char*, 0x48) = 2;
            frameOrPath16 = Level46_F248Field(private20, int*, 0x60);
            Level46_F248Field(private20, int*, 0x6C) = 0;
            Level46_F248CopyVector(
                (void*)(owner19 + 0xC),
                (void*)(Level46_F248Field(frameOrPath16, int*, 0xC) +
                        ((short)Level46_F248Field(frameOrPath16, unsigned short*, 2) * 0x10)));
            captured_v0_20 = ((short)Level46_F248Field(frameOrPath16, unsigned short*, 2) * 0x10) +
                             Level46_F248Field(frameOrPath16, int*, 0xC);
            Level46_F248Field(owner19, unsigned char*, 0x46) =
                Level46_F248PlanarHeadingLookup(Level46_F248Field(captured_v0_20, int*, 0x10) -
                                                    Level46_F248Field(owner19, int*, 0xC),
                                                Level46_F248Field(captured_v0_20, int*, 0x14) -
                                                    Level46_F248Field(owner19, int*, 0x10),
                                                0);
            captured_v1_18 = Level46_F248Field(private20, int*, 0x60);
            Level46_F248Field(captured_v1_18, unsigned short*, 2) =
                (unsigned short)(Level46_F248Field(captured_v1_18, unsigned short*, 2) + 2);
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3FU;
            Level46_F248RefreshMobySpatialGridAndBasis((void*)(owner19), 7);
            Level46_F248Field(owner19, int*, 0x54) =
                (int)(Level46_F248Field(owner19, int*, 0x14) + 0x800003E8);
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            Level46_F248Field(private20, int*, 0x68) = 0x28;
            return;
        case 0x3F:
            if (Level46_F248CountTimerDown((void*)(private20 + 0x68), 4) == 0) {
                goto block_309;
            }
            Level46_F248Field(owner19, unsigned char*, 0x48) = 0x3EU;
            Level46_F248Field(private20, int*, 0x68) = 0;
            return;
        case 0x3E:
            captured_v0_21 = Level46_F248Field(private20, int*, 0x68);
            if (captured_v0_21 != 0) {
                goto block_275;
            }
            captured_v0_22 = Level46_F248_SpawnMoby(0x3E8, owner19);
            Level46_F248Field(private20, int*, 0x6C) = captured_v0_22;
            if (captured_v0_22 == 0) {
                goto block_309;
            }
            Level46_F248Field(captured_v0_22, int*, 0x14) =
                (int)(Level46_F248Field(owner19, int*, 0x14) + 0x3A4);
            captured_v1_19 = Level46_F248Field(captured_v0_22, int*, 0);
            Level46_F248Field(private20, int*, 0x68) = 1;
            Level46_F248Field(captured_v1_19, short*, 2) = 0x19;
            Level46_F248Field(captured_v1_19, short*, 0x14) = 0xF;
            Level46_F248Field(captured_v1_19, short*, 0x16) = 0x1E;
            return;
        block_275:
            if (captured_v0_21 >= 0x1F4) {
                goto block_293;
            }
            captured_v1_20 = Level46_F248Field(private20, int*, 0x6C);
            captured_a0_14 = Level46_F248Field(captured_v1_20, int*, 0x14);
            captured_a2_3 = Level46_F248Field(captured_v1_20, int*, 0);
            if (Level46_F248Field(owner19, int*, 0x14) >= captured_a0_14) {
                goto block_278;
            }
            Level46_F248Field(owner19, int*, 0x54) = (int)(captured_a0_14 - 0x80000000);
        block_278:
            resultOrArithmetic2 = Level46_F248Field(captured_a2_3, short*, 0);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 >= 0x200) {
                goto block_280;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x2B;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2_3, short*, 0) = (short)resultOrArithmetic2;
            goto block_281;
        block_280:
            captured_a1_3 = Level46_F248Field(private20, int*, 0x6C);
            Level46_F248Field(captured_a1_3, int*, 0x14) =
                (int)(Level46_F248Field(captured_a1_3, int*, 0x14) -
                      (Level46_F248_D_8006C648 * 0x23));
        block_281:
            if (Level46_F248Field(captured_a2_3, short*, 0) < 0x101) {
                goto block_290;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a2_3, short*, 2);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 >= 0xC8) {
                goto block_284;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x1A;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2_3, short*, 2) = (short)resultOrArithmetic2;
        block_284:
            if (Level46_F248Field(captured_a2_3, short*, 0) < 0x101) {
                goto block_290;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a2_3, short*, 0x14);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            if (resultOrArithmetic2 >= 0x1E) {
                goto block_287;
            }
            resultOrArithmetic2 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = resultOrArithmetic2 * 2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = fieldOrAddress3 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2_3, short*, 0x14) = (short)resultOrArithmetic2;
        block_287:
            if (Level46_F248Field(captured_a2_3, short*, 0) < 0x101) {
                goto block_290;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a2_3, short*, 0x16);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrAddress4 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrAddress4);
            if (resultOrArithmetic2 >= 0x50) {
                goto block_290;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 5;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrAddress4 + resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a2_3, short*, 0x16) = (short)resultOrArithmetic2;
        block_290:
            captured_a0_15 = Level46_F248Field(private20, int*, 0x6C);
            Level46_F248Field(captured_a0_15, unsigned char*, 0x46) =
                (unsigned char)(Level46_F248Field(captured_a0_15, unsigned char*, 0x46) +
                                (Level46_F248_D_8006C648 * 0x14));
            resultOrArithmetic2 = Level46_F248Field(private20, int*, 0x68);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level46_F248_D_8006C648;
            resultOrArithmetic2 += fieldOrAddress3;
            Level46_F248Field(private20, int*, 0x68) = resultOrArithmetic2;
            resultOrArithmetic2 = resultOrArithmetic2 < 0x29;
        block_291:
            if (resultOrArithmetic2 != 0) {
                goto block_309;
            }
            Level46_F248Field(private20, int*, 0x68) = 0x258;
            return;
        block_293:
            captured_a0_16 = Level46_F248Field(Level46_F248Field(private20, int*, 0x6C), int*, 0);
            resultOrArithmetic2 = Level46_F248Field(captured_a0_16, short*, 0);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrField5 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrField5);
            if (resultOrArithmetic2 < 0x2C) {
                goto block_295;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x2B;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrField5 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a0_16, short*, 0) = (short)resultOrArithmetic2;
        block_295:
            if (Level46_F248Field(captured_a0_16, short*, 0) >= 0x17C) {
                goto block_298;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a0_16, short*, 2);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrField5 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrField5);
            if (resultOrArithmetic2 < 0x15) {
                goto block_298;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 0x1A;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrField5 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a0_16, short*, 2) = (short)resultOrArithmetic2;
        block_298:
            if (Level46_F248Field(captured_a0_16, short*, 2) >= 0x14) {
                goto block_300;
            }
            Level46_F248Field(captured_a0_16, short*, 2) = 0x14;
        block_300:
            if (Level46_F248Field(captured_a0_16, short*, 0) >= 0x17C) {
                goto block_306;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a0_16, short*, 0x14);
            Level46_F248CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = resultOrArithmetic2;
            Level46_F248CompleteValue(fieldOrAddress3);
            if (resultOrArithmetic2 < 0x10) {
                goto block_303;
            }
            resultOrArithmetic2 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = resultOrArithmetic2 * 2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = fieldOrAddress3 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a0_16, short*, 0x14) = (short)resultOrArithmetic2;
        block_303:
            if (Level46_F248Field(captured_a0_16, short*, 0) >= 0x17C) {
                goto block_306;
            }
            resultOrArithmetic2 = Level46_F248Field(captured_a0_16, short*, 0x16);
            Level46_F248CompleteValue(resultOrArithmetic2);
            argumentOrField5 = resultOrArithmetic2;
            Level46_F248CompleteValue(argumentOrField5);
            if (resultOrArithmetic2 < 0x1F) {
                goto block_306;
            }
            fieldOrAddress3 = Level46_F248_D_8006C648;
            Level46_F248CompleteValue(fieldOrAddress3);
            resultOrArithmetic2 = fieldOrAddress3 * 5;
            Level46_F248CompleteValue(resultOrArithmetic2);
            resultOrArithmetic2 = argumentOrField5 - resultOrArithmetic2;
            Level46_F248CompleteValue(resultOrArithmetic2);
            Level46_F248Field(captured_a0_16, short*, 0x16) = (short)resultOrArithmetic2;
        block_306:
            captured_a0_17 = Level46_F248Field(private20, int*, 0x6C);
            Level46_F248Field(captured_a0_17, unsigned char*, 0x46) =
                (unsigned char)(Level46_F248Field(captured_a0_17, unsigned char*, 0x46) +
                                (Level46_F248_D_8006C648 * 0x14));
            captured_v0_32 = Level46_F248Field(private20, int*, 0x68) + Level46_F248_D_8006C648;
            Level46_F248Field(private20, int*, 0x68) = captured_v0_32;
            if (captured_v0_32 < 0x264) {
                goto block_309;
            }
            Level46_F248_SpawnParticle(3, 0xC, Level46_F248Field(private20, int*, 0x6C), 5);
            Level46_F248Field(Level46_F248Field(private20, int*, 0x6C), signed char*, 0x48) = 2;
            Level46_F248Field(private20, int*, 0x6C) = 0;
            Level46_F248RequestMobyAnimation((void*)(owner19), 3);
            resultOrArithmetic2 = Level46_F248Field(owner19, unsigned char*, 0x49);
            Level46_F248Field(owner19, int*, 0x54) = 0;
        block_308:
            /* Original shared final state-byte store, reached through actual native control targets. */
            Level46_F248Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
        block_309:
            return;
    }
}
#undef Level46_F248Field
#undef Level46_F248CompleteValue

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level46
 * original80081980 complete259 instructions,11 dispatch entries and zero
 * padding in sibling4540 and original assembly. Verified vector/state C
 * forms reused; original46 controls every field/helper/branch/constant.
 * Units/helper semantics/cadence unresolved. Every native/linked word and
 * all retail EXE/overlay hashes required. */
#define A46F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char A46Player[] __asm__("D_80070328");
extern void* (*A46Spawn)() __asm__("SpawnMoby");
int A46TurnMobyTowardPlayer() __asm__("func_8003573C");
int A46H38BF8() __asm__("func_80038BF8");
int A46ApproximatePlanarDistance() __asm__("func_8004F334");
int A46RequestMobyAnimation() __asm__("func_80034F40");
int A46H55E84() __asm__("func_80055E84");
int A46H382F4() __asm__("func_800382F4");
int A46TransformVectorByBasis() __asm__("func_8004ED6C");
int A46H4EF74() __asm__("func_8004EF74");
int A46PlanarHeadingLookup() __asm__("func_8004E880");
int A46TurnMobyTowardHeading() __asm__("func_8003585C");
int A46SubtractVector() __asm__("func_8004F1C8");
int A46H35DDC() __asm__("func_80035DDC");
int A46CountTimerDown() __asm__("func_800359A4");
int A46H35194() __asm__("func_80035194");
int A46RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int A46H369B8() __asm__("func_800369B8");
int A46DeleteMoby() __asm__("func_80055B18");
void func_level_46_80081980(void* input) {
    struct {
        int first[4], second[4], third[4], fourth[4], fifth[4];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$18");
    register void* saved16 __asm__("$16");
    register int distance16 __asm__("$16");
    register int side16 __asm__("$16");
    register int result16 __asm__("$16");
    register unsigned char* position19 __asm__("$19");
    register int result19 __asm__("$19");
    register int result20 __asm__("$20");
    register unsigned char* player21 __asm__("$21");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register int product9 __asm__("$9");
    register void* call4 __asm__("$4") = input;
    register int arg6 __asm__("$6");
    register int arg7 __asm__("$7");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    MATCHING_KEEP2(owner, call4);
    work2 = owner[0x48];
    tag = A46F(owner, unsigned char**, 0);
    if (work2 != 3 && A46F(owner, int*, 24)) {
        A46TurnMobyTowardPlayer(call4, 128, 0, 0);
        A46H38BF8(owner, tag + 24, 5, 3);
        A46F(tag, short*, 30) = 120;
        A46F(tag, short*, 28) = 200;
    }
    switch (owner[0x48]) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return;
        case 0:
            work2 = A46ApproximatePlanarDistance(owner + 12, A46Player);
            work3 = A46F(tag, short*, 12);
            if (work2 >= work3)
                return;
            work2 = 1;
            MATCHING_KEEP_VOLATILE_CLOBBER(work2, "memory");
            goto set1;
        case 1:
            work2 = A46ApproximatePlanarDistance(owner + 12, A46Player);
            call4 = owner;
            work5 = 2;
            arg6 = 0;
            arg7 = 0;
            __asm__(""
                    : "=r"(call4), "=r"(work5), "=r"(arg6), "=r"(arg7)
                    : "0"(call4), "1"(work5), "2"(arg6), "3"(arg7), "r"(work2)
                    : "$16");
            distance16 = work2;
            A46TurnMobyTowardPlayer(call4, work5, arg6, arg7);
            work2 = A46F(tag, short*, 14);
            if (distance16 < work2) {
                A46F(tag, short*, 16) = 0;
                owner[0x48] = 2;
                A46RequestMobyAnimation(owner, 2);
                return;
            }
            work2 = A46F(tag, short*, 12);
            if (work2 < distance16) {
                owner[0x48] = 0;
                A46RequestMobyAnimation(owner, 0);
            }
            return;
        case 2:
            result20 = A46H55E84(owner);
            work3 = A46F(tag, int*, 20);
            if (work3) {
                A46F((void*)work3, unsigned char*, 0) = 1;
                work3 = A46H382F4(owner + 12, tag + 20, 1);
                if (work3) {
                    call4 = owner + 32;
                    saved16 = frame.fourth;
                    frame.third[0] = A46F((void*)work3, int*, 16);
                    frame.third[1] = A46F((void*)work3, int*, 20);
                    frame.third[2] = 0;
                    frame.fourth[0] = 100;
                    frame.fourth[1] = 0;
                    frame.fourth[2] = 0;
                    A46TransformVectorByBasis(call4, saved16, saved16);
                    frame.fourth[2] = 0;
                    A46H4EF74(saved16, frame.third, frame.fifth);
                    work2 = A46PlanarHeadingLookup(frame.fifth[0], frame.fifth[1], 0);
                    A46F(tag, short*, 18) = work2;
                    A46F(tag, short*, 16) = 30;
                    owner[0x48] = 10;
                    A46TurnMobyTowardHeading(owner, A46F(tag, short*, 18), 8, 1, 0, 0);
                    return;
                }
            }
            saved16 = A46Player + 48;
            frame.first[0] = 0;
            frame.first[1] = 256;
            frame.first[2] = 0;
            A46TransformVectorByBasis(saved16, frame.first, frame.first);
            call4 = frame.second;
            MATCHING_KEEP_CLOBBER(call4, "$19");
            position19 = owner + 12;
            player21 = (unsigned char*)saved16 - 48;
            A46SubtractVector(call4, position19, player21);
            work2 = frame.first[0];
            work4 = frame.second[0];
            work3 = work2 * work4;
            work5 = frame.second[1];
            work2 = frame.first[1];
            product9 = work2 * work5;
            MATCHING_KEEP(product9);
            work2 = work3 + product9;
            MATCHING_KEEP_CLOBBER(work2, "$16");
            side16 = -64;
            if (work2 > 0)
                side16 = 64;
            work2 = A46PlanarHeadingLookup(work4, work5, 0);
            A46TurnMobyTowardHeading(owner, (work2 + side16) & 255, 8, 12, 0, 0);
            work2 = result20 - 4;
            MATCHING_KEEP(work2);
            if ((unsigned int)work2 < 13)
                A46H35DDC(owner, 120, 300, 1000, 50);
            work2 = A46ApproximatePlanarDistance(position19, player21);
            work3 = A46F(tag, short*, 14);
            work3 = work3 < work2;
            MATCHING_KEEP(work3);
            if (!work3)
                return;
            work2 = 1;
        set1:
            MATCHING_KEEP_VOLATILE_CLOBBER(work2, "memory");
            owner[0x48] = work2;
            A46RequestMobyAnimation(owner, 1);
            return;
        case 10:
            work2 = A46H55E84(owner);
            call4 = owner;
            arg6 = 8;
            arg7 = 1;
            work5 = A46F(tag, short*, 18);
            __asm__(""
                    : "=r"(call4), "=r"(arg6), "=r"(arg7), "=r"(work5)
                    : "0"(call4), "1"(arg6), "2"(arg7), "3"(work5), "r"(work2)
                    : "$16");
            result16 = work2;
            work2 = A46TurnMobyTowardHeading(call4, work5, arg6, arg7, 0, 0);
            result16 -= 4;
            result16 = (unsigned int)result16 < 13;
            MATCHING_KEEP2_CLOBBER(result16, work2, "$19");
            result19 = work2;
            if (result16)
                A46H35DDC(owner, 120, 300, 1000, 50);
            if (A46CountTimerDown(tag + 16, 2) && result19 == 1)
                owner[0x48] = 2;
            return;
        case 3:
            if (A46H35194(owner, tag + 24) == 256) {
                A46Spawn(16, owner);
                A46RefreshMobySpatialGridAndBasis(owner, 4);
                A46H369B8(owner, 20);
                owner[0x49] = 0;
                A46DeleteMoby(owner);
            }
    }
}
#undef A46F

int func_8003636C(int, int);
int func_80039714(Moby*);
void func_level_46_80081D8C(Moby* moby) {
    Vector3D16* tag = moby->mobyTag;
    Vector3D velocity;
    char* particle;
    if (moby->state == 0x32) {
        func_80055B18(moby);
        return;
    }
    if (moby->state == 0) {
        tag->z = func_8003636C(0x96, 0x12C);
        tag->x = func_8003636C(0, 0x12C) - 0x96;
        tag->y = func_8003636C(0, 0x12C) - 0x96;
        moby->state = 1;
    }
    velocity.x = func_8003636C(0, 0xA0) - 0x50;
    velocity.y = func_8003636C(0, 0xA0) - 0x50;
    velocity.z = func_8003636C(0, 0x64);
    particle = SpawnParticle(1, 0, &moby->position, &velocity);
    if (particle)
        particle[0xA] = func_8003636C(0x78, 0xAA);
    if (func_80039714(moby))
        SpawnParticle(0x10, 0x46, &moby->position, (Vector3D*)0x20);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original46 80081EC8.
* Assembly SHA256 0b2ae8628a10150e4cd3efb15d16bdab56b6c4959026881cf411c0e89699c169.
* AI generated; not human reviewed. Exactly1086 native instructions plus
* eight selectors=1094 owned words. Every native/linked word, actual
* conditional/internal-J/call/JALR register and selector destination,
* data symbol/addend and full retail EXE/every-overlay hash must pass.
* Verified1031/1064 siblings supply the common source. Original46 uses
* private-record S4/index S5 roles and an A8hex frame; SP18..77 locals
* retain their offsets, SP78..7F is untouched padding before saved S0.
* Initial class99/341 and unsigned16(class-184)<2 exclusions retain
* their original order. A complete initialized zero-extended16 word is
* observed before its unsigned branch, retaining the original ANDI.
* Both absolute-angle bounds are8. For class174, byte48==3 adds256 to
* the first integer component BEFORE its original *8 and second-component
* addition. Complete V0 XOR/A1 boolean and S0 stages preserve disc words.
* Selected class174 copies its position into the existing private vector
* before the original subtraction. The extra mode2 1BA30 query uses450
* and runs only for nonzero search flag. Target/child initialization and
* later S2 target roles retain the verified1064 native path and join.
* Both MULTs initialize whole signed64 products; the first complete x
* input supplies its signed low32, the second multiplies that signed word
* by0x1B4E81B5 before complete x-input/high capture, >>6 and sign correction.
* Empty metadata uses complete initialized words/addresses/products or
* original memory boundaries and emits no CPU opcode. On a skipped query,
* the observed S2 word is the previously initialized owner-position address;
* on a null query it is the complete returned zero. No incoming value is used.
* No partial HI/LO input, fixed FP, unwritten local read or overlapping live
* GP aliases. Existing known helper returns and typed word ABI persist.
* Native identity confirms the raw arithmetic, widths and control words;
* physical units, full helper/caller chains, cadence, Rev1 mapping, human
* review and synchronized runtime captures remain open. Frozen compiler,
* filters and acceptance flags remain unchanged.
*/
void* Level46_81EC8Call1BA30(void*, int, int, int, int, void*) __asm__("func_8001BA30");
#define Level46_81EC8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level46_81EC8Call13E38() __asm__("func_80013E38");
int Level46_81EC8Call1830C() __asm__("func_8001830C");
int Level46_81EC8Call19138() __asm__("func_80019138");
void* Level46_81EC8Call1AD60() __asm__("func_8001AD60");
int Level46_81EC8Call1C288() __asm__("func_8001C288");
int Level46_81EC8SetMobyAnimation() __asm__("func_80034F80");
int Level46_81EC8TurnMobyTowardPlayer() __asm__("func_8003573C");
int Level46_81EC8CountTimerDown(void*, int) __asm__("func_800359A4");
int Level46_81EC8RandBetween() __asm__("func_8003636C");
int Level46_81EC8PlayMobySoundEvent() __asm__("func_8003BABC");
int Level46_81EC8Call40954() __asm__("func_80040954");
int Level46_81EC8PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Level46_81EC8TransformVectorByBasis() __asm__("func_8004ED6C");
int Level46_81EC8MeasureVectorLength() __asm__("func_8004EDE8");
int Level46_81EC8Call4EF74() __asm__("func_8004EF74");
int Level46_81EC8ScaleVectorRatioQ15() __asm__("func_8004F08C");
void Level46_81EC8CopyVector() __asm__("func_8004F178");
void Level46_81EC8AddVector() __asm__("func_8004F194");
void Level46_81EC8SubtractVector() __asm__("func_8004F1C8");
int Level46_81EC8ApproximatePlanarDistance() __asm__("func_8004F334");
int Level46_81EC8DeleteMoby() __asm__("func_80055B18");
int Level46_81EC8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level46_81EC8Datarand(void) __asm__("rand");
extern int Level46_81EC8Data658A0 __asm__("D_800658A0");
extern int Level46_81EC8Data65920 __asm__("D_80065920");
extern int Level46_81EC8Data6C550 __asm__("D_8006C550");
extern int Level46_81EC8Data6D048 __asm__("D_8006D048");
extern int Level46_81EC8Data6E020 __asm__("D_8006E020");
extern int Level46_81EC8Data6E024 __asm__("D_8006E024");
extern int Level46_81EC8Data6E028 __asm__("D_8006E028");
extern unsigned short Level46_81EC8Data6E03E __asm__("D_8006E03E");
extern unsigned short Level46_81EC8Data6E040 __asm__("D_8006E040");
extern void* Level46_81EC8Data6E788 __asm__("D_8006E788");
extern int Level46_81EC8Data70328 __asm__("D_80070328");
extern int Level46_81EC8Data71900 __asm__("D_80071900");
extern int Level46_81EC8Data71918 __asm__("D_80071918");
extern int Level46_81EC8Data71924 __asm__("D_80071924");
extern void* (*Level46_81EC8DataSpawnMoby)() __asm__("SpawnMoby");
extern void* (*Level46_81EC8DataSpawnParticle)() __asm__("SpawnParticle");
extern int (*Level46_81EC8Data74424)() __asm__("unk_ovlheader_80074424");
extern void* (*Level46_81EC8Data74428)() __asm__("unk_ovlheader_80074428");
void func_level_46_80081EC8(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int retainedAngleOrRecord16 __asm__("$16"), retainedRecordOrVector17 __asm__("$17"),
        retainedAngleOrAddress18 __asm__("$18"), retainedRecordOrDataAddress21 __asm__("$21"),
        privateRecord20 __asm__("$20"), searchPositionOrFlag22 __asm__("$22"),
        retainedSelectedRecord23 __asm__("$23");
    register int rangeBoundOrProductHigh10 __asm__("$10");
    register int rawWord2 __asm__("$2"), rawWord3, argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        nearestDifference8 __asm__("$8"), directionSign9 __asm__("$9");
    int retainedMinimumScoreOrDataAddress;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, padding78, padding7C;
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
    privateRecord20 = (int)Level46_81EC8Field(ownerRecord19, void**, 0);
    Level46_81EC8RefreshMobySpatialGridAndBasis(ownerParameter, 6);
    rawWord3 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48);
    searchPositionOrFlag22 = 0;
    switch (rawWord3) {
        case 5:
            retainedMinimumScoreOrDataAddress = 0x1869F;
            retainedSelectedRecord23 = 0;
            retainedRecordOrDataAddress21 = (int)&Level46_81EC8Data6E788;
            retainedRecordOrVector17 = Level46_81EC8Field(retainedRecordOrDataAddress21, int*, 0);
            retainedRecordOrDataAddress21 += 4;
            if (retainedRecordOrVector17 != 0) {
                searchPositionOrFlag22 = ownerRecord19 + 0xC;
                do {
                    argumentWord4 = Level46_81EC8Field(retainedRecordOrVector17, short*, 0x36);
                    rawWord3 = argumentWord4;
                    if ((argumentWord4 != 0x63) &&
                        !(Level46_81EC8Field(retainedRecordOrVector17, unsigned char*, 0x48) &
                          0x80) &&
                        (Level46_81EC8Field(retainedRecordOrVector17, int*, 8) != 0) &&
                        (Level46_81EC8Field(ownerRecord19, unsigned char*, 0x4D) != 0) &&
                        (argumentWord4 != 0x155) && ((unsigned int)({
                                                         rawWord2 =
                                                             (unsigned short)(rawWord3 - 0xB8);
                                                         MATCHING_KEEP(rawWord2);
                                                         rawWord2;
                                                     }) >= 2)) {
                        rangeBoundOrProductHigh10 = 0x8000;
                        __asm__(""
                                : "=r"(rangeBoundOrProductHigh10)
                                : "0"(rangeBoundOrProductHigh10)
                                : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9");
                        rawWord3 = Level46_81EC8Field(retainedRecordOrVector17, int*, 0xC);
                        rawWord2 = Level46_81EC8Field(ownerRecord19, int*, 0xC);
                        argumentWord4 = rawWord3 - rawWord2;
                        rawWord2 = argumentWord4;
                        if (argumentWord4 < 0) {
                            MATCHING_KEEP(rawWord2);
                            rawWord2 = -rawWord2;
                        }
                        if (rawWord2 <= rangeBoundOrProductHigh10) {
                            rawWord3 = Level46_81EC8Field(retainedRecordOrVector17, int*, 0x10);
                            rawWord2 = Level46_81EC8Field(ownerRecord19, int*, 0x10);
                            argumentWord5 = rawWord3 - rawWord2;
                            rawWord2 = argumentWord5;
                            if (argumentWord5 < 0) {
                                MATCHING_KEEP(rawWord2);
                                rawWord2 = -rawWord2;
                            }
                            if (rawWord2 <= rangeBoundOrProductHigh10) {
                                retainedAngleOrRecord16 =
                                    (Level46_81EC8PlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                      0) -
                                     Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46)) &
                                    0xFF;
                                __asm__(""
                                        : "=r"(searchPositionOrFlag22)
                                        : "0"(searchPositionOrFlag22),
                                          "r"(retainedAngleOrRecord16));
                                argumentWord4 = searchPositionOrFlag22;
                                if (retainedAngleOrRecord16 >= 0x81) {
                                    retainedAngleOrRecord16 -= 0x100;
                                }
                                MATCHING_BARRIER_GNU_VOLATILE("$18");
                                retainedAngleOrAddress18 = retainedRecordOrVector17 + 0xC;
                                argumentWord4 =
                                    (Level46_81EC8PlanarHeadingLookup(
                                         Level46_81EC8ApproximatePlanarDistance(
                                             argumentWord4, retainedAngleOrAddress18),
                                         Level46_81EC8Field(retainedRecordOrVector17, int*, 0x14) -
                                             Level46_81EC8Field(ownerRecord19, int*, 0x14),
                                         0) -
                                     Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45)) &
                                    0xFF;
                                if (argumentWord4 >= 0x81) {
                                    argumentWord4 -= 0x100;
                                }
                                if (retainedAngleOrRecord16 < 0) {
                                    retainedAngleOrRecord16 = -retainedAngleOrRecord16;
                                }
                                if (argumentWord4 < 0) {
                                    MATCHING_KEEP(argumentWord4);
                                    argumentWord4 = -argumentWord4;
                                }
                                __asm__(""
                                        : "=r"(retainedAngleOrRecord16)
                                        : "0"(retainedAngleOrRecord16), "r"(argumentWord4));
                                if ((retainedAngleOrRecord16 < 8) && (argumentWord4 < 8)) {
                                    argumentWord5 = 0;
                                    if (Level46_81EC8Field(retainedRecordOrVector17, short*,
                                                           0x36) == 0xAE) {
                                        rawWord2 = Level46_81EC8Field(retainedRecordOrVector17,
                                                                      unsigned char*, 0x48);
                                        rawWord2 ^= 3;
                                        MATCHING_KEEP(rawWord2);
                                        argumentWord5 = (unsigned int)rawWord2 < 1;
                                    }
                                    rawWord2 = argumentWord5 << 8;
                                    retainedAngleOrRecord16 += rawWord2;
                                    MATCHING_KEEP(retainedAngleOrRecord16);
                                    retainedAngleOrRecord16 *= 8;
                                    MATCHING_KEEP(retainedAngleOrRecord16);
                                    retainedAngleOrRecord16 += argumentWord4;
                                    MATCHING_KEEP(retainedAngleOrRecord16);
                                    retainedAngleOrRecord16 +=
                                        Level46_81EC8ApproximatePlanarDistance(
                                            searchPositionOrFlag22, retainedAngleOrAddress18) >>
                                        10;
                                    if ((retainedAngleOrRecord16 <
                                         retainedMinimumScoreOrDataAddress) &&
                                        (Level46_81EC8Call13E38(searchPositionOrFlag22,
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
                        Level46_81EC8Field(retainedRecordOrDataAddress21, void**, 0);
                    retainedRecordOrDataAddress21 += 4;
                } while (retainedRecordOrVector17 != 0);
            }
            argumentWord4 = privateRecord20;
            if (retainedSelectedRecord23 != 0) {
                argumentWord5 = retainedSelectedRecord23 + 12;
                argumentWord6 = Level46_81EC8Data6C550;
                rawWord2 = 7;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
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
                rawWord2 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46);
                rawWord3 >>= 3;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x49) = rawWord3;
                Level46_81EC8Field(argumentWord4, unsigned char*, 0xF) = rawWord2;
                Level46_81EC8CopyVector(argumentWord4, argumentWord5, argumentWord6);
                return;
            }
            Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) = 0U;
            searchPositionOrFlag22 = 1;
        case 6:
            if (Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) == 6) {
                Level46_81EC8TurnMobyTowardPlayer(ownerRecord19, 0x80, 0, 0);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45) =
                    Level46_81EC8PlanarHeadingLookup(
                        Level46_81EC8ApproximatePlanarDistance(ownerRecord19 + 0xC,
                                                               ((void*)&Level46_81EC8Data70328)),
                        Level46_81EC8Field(((void*)&Level46_81EC8Data70328), int*, 8) -
                            Level46_81EC8Field(ownerRecord19, int*, 0x14),
                        0);
                Level46_81EC8RefreshMobySpatialGridAndBasis(ownerRecord19, 4);
                argumentWord4 = (int)ownerRecord19 + 0x20;
                argumentWord5 = (int)&originalFrame.sp18;
                rawWord2 = Level46_81EC8Field(privateRecord20, short*, 0xC);
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord5);
                argumentWord6 = privateRecord20;
                originalFrame.sp1C = 0;
                originalFrame.sp20 = 0;
                originalFrame.sp18 = rawWord2;
                Level46_81EC8TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                case 7:
            }
            retainedAngleOrAddress18 = 0;
            if (Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) == 7) {
                rawWord3 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x49);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level46_81EC8Data6C550;
                retainedRecordOrDataAddress21 = rawWord3 + rawWord2;
                if (Level46_81EC8Field(retainedRecordOrDataAddress21, short*, 0x36) == 0xAE)
                    Level46_81EC8CopyVector(privateRecord20, retainedRecordOrDataAddress21 + 12);
                argumentWord4 = (int)&originalFrame.sp18;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                argumentWord5 = (int)ownerRecord19 + 12;
                retainedAngleOrRecord16 = retainedRecordOrDataAddress21 + 12;
                MATCHING_KEEP(retainedAngleOrRecord16);
                Level46_81EC8SubtractVector(argumentWord4, argumentWord5, retainedAngleOrRecord16);
                rawWord2 =
                    Level46_81EC8PlanarHeadingLookup(originalFrame.sp18, originalFrame.sp1C, 0);
                retainedRecordOrVector17 = (int)&originalFrame.sp28;
                argumentWord4 = retainedRecordOrVector17;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                argumentWord5 = retainedAngleOrRecord16;
                rawWord3 = rawWord2 - 128;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46) = rawWord3;
                retainedAngleOrRecord16 =
                    Level46_81EC8Field(retainedRecordOrDataAddress21, unsigned char*, 0x46);
                MATCHING_OBSERVE_GNU_VOLATILE(retainedAngleOrRecord16);
                argumentWord6 = privateRecord20;
                retainedAngleOrRecord16 -= rawWord2;
                retainedAngleOrRecord16 &= 255;
                Level46_81EC8SubtractVector(argumentWord4, argumentWord5, argumentWord6);
                rawWord2 = Level46_81EC8MeasureVectorLength(retainedRecordOrVector17, 0);
                retainedAngleOrRecord16 += 64;
                retainedAngleOrRecord16 &= 255;
                retainedAngleOrRecord16 <<= 1;
                rawWord3 =
                    Level46_81EC8Field(&Level46_81EC8Data65920, short*, retainedAngleOrRecord16);
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
                    rawWord3 = (int)&Level46_81EC8Data658A0;
                    argumentWord5 = rawWord2 + rawWord3;
                    do {
                        rawWord2 = Level46_81EC8Field(argumentWord5, short*, 0) - argumentWord6;
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
                Level46_81EC8CopyVector(retainedAngleOrRecord16, retainedRecordOrDataAddress21 + 12,
                                        argumentWord6, argumentWord7);
                argumentWord4 = (int)ownerRecord19 + 12;
                rawWord2 = originalFrame.sp30;
                argumentWord5 = retainedAngleOrRecord16;
                rawWord2 += 500;
                originalFrame.sp30 = rawWord2;
                rawWord2 = Level46_81EC8ApproximatePlanarDistance(argumentWord4, argumentWord5);
                argumentWord4 = rawWord2;
                rawWord2 = originalFrame.sp30;
                argumentWord5 = Level46_81EC8Field(ownerRecord19, int*, 0x14);
                argumentWord6 = 0;
                argumentWord5 = rawWord2 - argumentWord5;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45) =
                    Level46_81EC8PlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46) =
                    (unsigned char)(Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46) +
                                    retainedAngleOrAddress18);
                originalFrame.sp28 = 0x258;
                originalFrame.sp2C = 0;
                originalFrame.sp30 = 0;
                Level46_81EC8RefreshMobySpatialGridAndBasis(ownerRecord19, 4);
                Level46_81EC8TransformVectorByBasis(ownerRecord19 + 0x20, retainedAngleOrRecord16,
                                                    privateRecord20);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45) =
                    Level46_81EC8PlanarHeadingLookup(
                        Level46_81EC8MeasureVectorLength(privateRecord20, 1),
                        Level46_81EC8Field(privateRecord20, int*, 8), 0);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46) =
                    Level46_81EC8PlanarHeadingLookup(Level46_81EC8Field(privateRecord20, int*, 0),
                                                     Level46_81EC8Field(privateRecord20, int*, 4),
                                                     0);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) = 0U;
            }
        case 0:
            retainedAngleOrRecord16 = 0;
            rawWord3 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x3A);
            MATCHING_KEEP(rawWord3);
            retainedRecordOrVector17 = 0;
            if (rawWord3 < 0xFFU) {
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level46_81EC8Data6C550;
                retainedAngleOrRecord16 = rawWord3 + rawWord2;
            }
            if ((searchPositionOrFlag22 != 0) && (retainedAngleOrRecord16 != 0)) {
                Level46_81EC8CopyVector(&originalFrame.sp48, retainedAngleOrRecord16 + 0xC);
                originalFrame.sp50 += 0x200;
            } else {
                Level46_81EC8CopyVector(&originalFrame.sp48, ownerRecord19 + 0xC);
            }
            argumentWord4 = (int)&originalFrame.sp38;
            MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
            retainedAngleOrAddress18 = (int)ownerRecord19 + 12;
            Level46_81EC8AddVector(argumentWord4, retainedAngleOrAddress18, privateRecord20);
            if ((originalFrame.sp38 < 0x1068) || (originalFrame.sp3C < 0x1068) ||
                (originalFrame.sp40 < 0x1068) || (originalFrame.sp38 > 0x3E738) ||
                (originalFrame.sp3C > 0x3E738) || (originalFrame.sp40 > 0x3E738)) {
                temp_a0_2 = Level46_81EC8Field(privateRecord20, void**, 0x14);
                if (temp_a0_2 != 0) {
                    Level46_81EC8DeleteMoby(temp_a0_2);
                    __asm__ __volatile__("" ::"i"(103111) : "memory");
                    Level46_81EC8Field(privateRecord20, void**, 0x14) = 0;
                }
                goto block_134;
            }
            if ((retainedAngleOrRecord16 != 0) &&
                (Level46_81EC8Field(retainedAngleOrRecord16, short*, 0x36) != 0x63) &&
                (Level46_81EC8Call1C288(retainedAngleOrAddress18, 0xC8, 1) != 0)) {
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord5, "memory");
                rawWord2 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46);
                rawWord3 = (int)Level46_81EC8DataSpawnMoby;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(rawWord2, rawWord3, "$17");
                retainedRecordOrVector17 = (int)&Level46_81EC8Data70328 + 0x298;
                Level46_81EC8Field(retainedRecordOrVector17, int*, 0) = rawWord2;
                retainedAngleOrRecord16 = ((void* (*)())rawWord3)(argumentWord4, argumentWord5);
                MATCHING_KEEP(retainedAngleOrRecord16);
                if (retainedAngleOrRecord16 != 0) {
                    rawWord3 = Level46_81EC8Field(retainedAngleOrRecord16, void**, 0);
                    Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x48) = 4;
                    Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x41) = 0;
                    Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x4C) = 0;
                    Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x4D) = 0;
                    Level46_81EC8Field(rawWord3, short*, 0x10) = 0xF;
                    Level46_81EC8Field(rawWord3, short*, 0x12) = 1;
                    Level46_81EC8CopyVector(retainedAngleOrRecord16 + 0xC,
                                            retainedRecordOrVector17 - 0x298);
                    Level46_81EC8Field(retainedAngleOrRecord16, int*, 0x14) =
                        (int)Level46_81EC8Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            if (searchPositionOrFlag22 != 0) {
                retainedAngleOrAddress18 = (int)Level46_81EC8Call1BA30(
                    (void*)(ownerRecord19 + 12), 450, 2, 0, 0, (void*)ownerRecord19);
                MATCHING_KEEP(retainedAngleOrAddress18);
                if (retainedAngleOrAddress18 != 0) {
                    rawWord2 = Level46_81EC8PlanarHeadingLookup(
                        Level46_81EC8Field(privateRecord20, int*, 0),
                        Level46_81EC8Field(privateRecord20, int*, 4), 0);
                    argumentWord4 = 197;
                    argumentWord5 = 0;
                    MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
                    Level46_81EC8Field(retainedAngleOrAddress18, unsigned char*, 0x51) = rawWord2;
                    rawWord2 = 0x10000;
                    rawWord3 = Level46_81EC8Field(retainedAngleOrAddress18, int*, 0x18);
                    argumentWord6 = (int)Level46_81EC8DataSpawnMoby;
                    rawWord3 |= rawWord2;
                    Level46_81EC8Field(retainedAngleOrAddress18, int*, 0x18) = rawWord3;
                    retainedAngleOrRecord16 =
                        ((void* (*)())argumentWord6)(argumentWord4, argumentWord5, argumentWord6);
                    MATCHING_KEEP(retainedAngleOrRecord16);
                    if (retainedAngleOrRecord16 != 0) {
                        rawWord3 = Level46_81EC8Field(retainedAngleOrRecord16, void**, 0);
                        Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x48) = 4;
                        Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x41) = 0;
                        Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x4C) = 0;
                        Level46_81EC8Field(retainedAngleOrRecord16, signed char*, 0x4D) = 0;
                        Level46_81EC8Field(rawWord3, short*, 0x10) = 15;
                        Level46_81EC8Field(rawWord3, short*, 0x12) = 1;
                        Level46_81EC8CopyVector(retainedAngleOrRecord16 + 12,
                                                retainedAngleOrAddress18 + 12);
                        Level46_81EC8Field(retainedAngleOrRecord16, int*, 0x14) =
                            Level46_81EC8Field(ownerRecord19, int*, 0x14);
                    }
                    goto block_94;
                }
            }
            MATCHING_KEEP_VOLATILE(retainedAngleOrAddress18);
            if (Level46_81EC8Field(privateRecord20, short*, 0xC) >= 0xFA1) {
                rawWord2 =
                    Level46_81EC8Data74424(&originalFrame.sp48, &originalFrame.sp38, 0, 1) == 0;
            } else {
                rawWord2 =
                    Level46_81EC8Call1830C(&originalFrame.sp48, &originalFrame.sp38, 2, 1, 0);
            }
            if (rawWord2 == 0) {
                rawWord2 = Level46_81EC8Field(privateRecord20, short*, 0xC);
                if (rawWord2 >= 4001) {
                    argumentWord4 = (int)&originalFrame.sp48;
                    argumentWord5 = (int)&originalFrame.sp38;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord5, "memory");
                    rawWord2 = (int)Level46_81EC8Data74428;
                    argumentWord6 = 0;
                    retainedAngleOrAddress18 =
                        ((void* (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6);
                } else {
                    argumentWord4 = (int)&originalFrame.sp48;
                    argumentWord5 = (int)&originalFrame.sp38;
                    argumentWord6 = 0;
                    argumentWord7 = 0;
                    retainedAngleOrAddress18 = Level46_81EC8Call1AD60(
                        argumentWord4, argumentWord5, argumentWord6, argumentWord7, ownerRecord19);
                }
                if (retainedAngleOrAddress18 != 0) {
                    goto block_89;
                }
                goto block_120;
            }
            if (Level46_81EC8Field(privateRecord20, short*, 0xC) >= 0xFA1) {
                retainedAngleOrAddress18 = Level46_81EC8Data74428(
                    &originalFrame.sp48, ((void*)&Level46_81EC8Data71900), 0);
            } else {
                retainedAngleOrAddress18 = Level46_81EC8Call1AD60(
                    &originalFrame.sp48, ((void*)&Level46_81EC8Data71900), 0, 0, ownerRecord19);
            }
            if (retainedAngleOrAddress18 != 0) {
            block_89:
                rawWord2 = Level46_81EC8PlanarHeadingLookup(
                    Level46_81EC8Field(privateRecord20, int*, 0),
                    Level46_81EC8Field(privateRecord20, int*, 4), 0);
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
                Level46_81EC8Field(retainedAngleOrAddress18, unsigned char*, 0x51) = rawWord2;
                rawWord2 = 0x10000;
                rawWord3 = Level46_81EC8Field(retainedAngleOrAddress18, int*, 0x18);
                argumentWord6 = (int)Level46_81EC8DataSpawnMoby;
                rawWord3 |= rawWord2;
                Level46_81EC8Field(retainedAngleOrAddress18, int*, 0x18) = rawWord3;
                retainedRecordOrVector17 =
                    ((void* (*)())argumentWord6)(argumentWord4, argumentWord5, argumentWord6);
                MATCHING_KEEP(retainedRecordOrVector17);
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level46_81EC8Field(retainedRecordOrVector17, void**, 0);
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                    Level46_81EC8Field(rawWord3, short*, 0x10) = 0xF;
                    Level46_81EC8Field(rawWord3, short*, 0x12) = 1;
                    Level46_81EC8CopyVector(retainedRecordOrVector17 + 0xC,
                                            retainedAngleOrAddress18 + 0xC);
                    Level46_81EC8Field(retainedRecordOrVector17, int*, 0x14) =
                        (int)Level46_81EC8Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            if (Level46_81EC8Field(privateRecord20, unsigned char*, 0xE) != 0) {
                MATCHING_KEEP(retainedAngleOrAddress18);
                retainedRecordOrVector17 = Level46_81EC8DataSpawnMoby(0xC5, 0);
                MATCHING_KEEP(retainedRecordOrVector17);
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level46_81EC8Field(retainedRecordOrVector17, void**, 0);
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                    Level46_81EC8Field(rawWord3, short*, 0x10) = 0x1E;
                    Level46_81EC8Field(rawWord3, short*, 0x12) = 0xF;
                    Level46_81EC8CopyVector(retainedRecordOrVector17 + 0xC,
                                            ((void*)&Level46_81EC8Data71900));
                }
            block_94:
                retainedRecordOrVector17 = 1;
                goto block_120;
            } else {
                MATCHING_KEEP(retainedAngleOrAddress18);
                retainedAngleOrAddress18 = (int)&Level46_81EC8Data71924;
                if (Level46_81EC8Call40954(Level46_81EC8Field(retainedAngleOrAddress18, int*, 0)) ==
                    3) {
                    temp_a0_5 = Level46_81EC8Field(
                        Level46_81EC8Field(((void*)&Level46_81EC8Data6D048), int*, 0x14), void**,
                        (Level46_81EC8Field(retainedAngleOrAddress18, int*, 0) & 0x3F) * 4);
                    Level46_81EC8Field(temp_a0_5, int*, 4) =
                        (int)(Level46_81EC8Field(temp_a0_5, int*, 4) | 0x10000);
                }
                Level46_81EC8Field(privateRecord20, unsigned char*, 0xE) =
                    (unsigned char)(Level46_81EC8Field(privateRecord20, unsigned char*, 0xE) + 1);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                retainedRecordOrVector17 = Level46_81EC8DataSpawnMoby(0xC5, 0);
                MATCHING_KEEP(retainedRecordOrVector17);
                retainedAngleOrRecord16 = retainedRecordOrVector17 + 0xC;
                if (retainedRecordOrVector17 != 0) {
                    argumentWord4 = retainedAngleOrRecord16;
                    __asm__(""
                            : "=r"(retainedAngleOrAddress18)
                            : "0"(retainedAngleOrAddress18), "r"(argumentWord4));
                    retainedMinimumScoreOrDataAddress = retainedAngleOrAddress18 - 0x24;
                    Level46_81EC8Field(Level46_81EC8Field(retainedRecordOrVector17, void**, 0),
                                       short*, 0x10) = 2;
                    Level46_81EC8CopyVector(retainedAngleOrRecord16,
                                            retainedMinimumScoreOrDataAddress);
                    rawWord2 = Level46_81EC8RandBetween(0, 0xFF);
                    argumentWord4 = retainedAngleOrRecord16;
                    retainedAngleOrRecord16 = (int)&Level46_81EC8Data6E020;
                    argumentWord5 = retainedAngleOrRecord16;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
                    searchPositionOrFlag22 = rawWord2;
                    Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x44) =
                        searchPositionOrFlag22;
                    rawWord2 = Level46_81EC8ApproximatePlanarDistance(argumentWord4, argumentWord5);
                    argumentWord4 = rawWord2;
                    rawWord2 = Level46_81EC8Data6E028;
                    argumentWord5 = Level46_81EC8Field(retainedRecordOrVector17, int*, 0x14);
                    argumentWord6 = 0;
                    argumentWord5 = rawWord2 - argumentWord5;
                    rawWord2 = Level46_81EC8PlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                argumentWord6);
                    argumentWord6 = 0;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
                    retainedRecordOrDataAddress21 = rawWord2;
                    Level46_81EC8Field(retainedRecordOrVector17, unsigned char*, 0x45) =
                        retainedRecordOrDataAddress21;
                    rawWord2 = Level46_81EC8PlanarHeadingLookup(
                        Level46_81EC8Field(retainedAngleOrRecord16, int*, 0) -
                            Level46_81EC8Field(retainedRecordOrVector17, int*, 0xC),
                        Level46_81EC8Data6E024 -
                            Level46_81EC8Field(retainedRecordOrVector17, int*, 0x10),
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
                    Level46_81EC8Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = 13;
                    Level46_81EC8Field(argumentWord4, unsigned char*, 0x46) =
                        retainedAngleOrAddress18;
                    Level46_81EC8Field(argumentWord4, unsigned char*, 0x54) =
                        retainedAngleOrRecord16;
                    Level46_81EC8Field(argumentWord4, unsigned char*, 0x55) = 0;
                    Level46_81EC8Field(argumentWord4, unsigned char*, 0x56) = 0;
                    Level46_81EC8Field(argumentWord4, unsigned char*, 0x57) = rawWord2;
                    Level46_81EC8SetMobyAnimation(argumentWord4, argumentWord5);
                    retainedRecordOrVector17 = Level46_81EC8DataSpawnMoby(0xC5, 0);
                    MATCHING_KEEP(retainedRecordOrVector17);
                    if (retainedRecordOrVector17 != 0) {
                        Level46_81EC8Field(Level46_81EC8Field(retainedRecordOrVector17, void**, 0),
                                           short*, 0x10) = 2;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x57) = 0xF;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x44) =
                            searchPositionOrFlag22;
                        Level46_81EC8Field(retainedRecordOrVector17, unsigned char*, 0x45) =
                            retainedRecordOrDataAddress21;
                        Level46_81EC8Field(retainedRecordOrVector17, unsigned char*, 0x46) =
                            retainedAngleOrAddress18;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x54) =
                            retainedAngleOrRecord16;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x55) =
                            retainedAngleOrRecord16;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x56) =
                            retainedAngleOrRecord16;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x48) = 3;
                        Level46_81EC8CopyVector(retainedRecordOrVector17 + 0xC,
                                                retainedMinimumScoreOrDataAddress);
                        Level46_81EC8SetMobyAnimation(retainedRecordOrVector17, 3);
                    }
                }
                Level46_81EC8CopyVector(ownerRecord19 + 0xC, ((void*)&Level46_81EC8Data71900));
                Level46_81EC8CopyVector(&originalFrame.sp38,
                                        ((void*)&Level46_81EC8Data71900) + 0x18);
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
                argumentWord4 = privateRecord20;
                if (rawWord2)
                    goto integrateOriginalVector;
            clearOriginalVerticalComponent:
                originalFrame.sp40 = 0;
                argumentWord4 = privateRecord20;
            integrateOriginalVector:
                MATCHING_BARRIER_GNU_VOLATILE("$17");
                retainedRecordOrVector17 = (int)&originalFrame.sp38;
                Level46_81EC8Call4EF74(argumentWord4, retainedRecordOrVector17, privateRecord20);
                if (Level46_81EC8Field(privateRecord20, short*, 0xC) >= 0xFA1) {
                    Level46_81EC8Field(privateRecord20, short*, 0xC) = 0x258;
                }
                Level46_81EC8ScaleVectorRatioQ15(
                    privateRecord20, Level46_81EC8MeasureVectorLength(privateRecord20, 1),
                    Level46_81EC8Field(privateRecord20, short*, 0xC));
                Level46_81EC8CopyVector(retainedRecordOrVector17, privateRecord20);
                Level46_81EC8ScaleVectorRatioQ15(
                    retainedRecordOrVector17,
                    Level46_81EC8MeasureVectorLength(retainedRecordOrVector17, 1), 0x320);
                argumentWord4 = retainedRecordOrVector17;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                retainedAngleOrAddress18 = (int)ownerRecord19 + 12;
                Level46_81EC8AddVector(argumentWord4, retainedAngleOrAddress18,
                                       retainedRecordOrVector17);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45) =
                    Level46_81EC8PlanarHeadingLookup(
                        Level46_81EC8MeasureVectorLength(privateRecord20, 1),
                        Level46_81EC8Field(privateRecord20, int*, 8), 0);
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46) =
                    Level46_81EC8PlanarHeadingLookup(Level46_81EC8Field(privateRecord20, int*, 0),
                                                     Level46_81EC8Field(privateRecord20, int*, 4),
                                                     0);
                Level46_81EC8PlayMobySoundEvent(ownerRecord19, 1, 0);
                retainedAngleOrRecord16 = (int)&originalFrame.sp58;
                argumentWord4 = retainedAngleOrRecord16;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$21");
                retainedRecordOrDataAddress21 = (int)&Level46_81EC8Data71918;
                Level46_81EC8CopyVector(argumentWord4, retainedRecordOrDataAddress21);
                Level46_81EC8ScaleVectorRatioQ15(
                    &originalFrame.sp58, Level46_81EC8MeasureVectorLength(&originalFrame.sp58, 1),
                    0x37);
                Level46_81EC8AddVector(&originalFrame.sp58, retainedAngleOrAddress18,
                                       &originalFrame.sp58);
                if ((Level46_81EC8Call19138(&originalFrame.sp58, 0x32, 1, 0, 0, 0) != 0) ||
                    (Level46_81EC8Call1830C(retainedRecordOrVector17, &originalFrame.sp58, 3, 0,
                                            0) != 0)) {
                    if (Level46_81EC8Call40954(Level46_81EC8Data71924) == 3) {
                        temp_a0_6 = Level46_81EC8Field(
                            Level46_81EC8Field(((void*)&Level46_81EC8Data6D048), int*, 0x14),
                            void**, (Level46_81EC8Data71924 & 0x3F) * 4);
                        Level46_81EC8Field(temp_a0_6, int*, 4) =
                            (int)(Level46_81EC8Field(temp_a0_6, int*, 4) | 0x10000);
                    }
                    retainedRecordOrVector17 = Level46_81EC8DataSpawnMoby(0xC5, 0);
                    MATCHING_KEEP(retainedRecordOrVector17);
                    if (retainedRecordOrVector17 != 0) {
                        rawWord3 = Level46_81EC8Field(retainedRecordOrVector17, void**, 0);
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                        Level46_81EC8Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                        Level46_81EC8Field(rawWord3, short*, 0x10) = 0x1E;
                        Level46_81EC8Field(rawWord3, short*, 0x12) = 0xF;
                        Level46_81EC8CopyVector(retainedRecordOrVector17 + 0xC,
                                                retainedRecordOrDataAddress21 - 0x18);
                    }
                    temp_a0_7 = Level46_81EC8Field(privateRecord20, void**, 0x14);
                    if (temp_a0_7 != 0) {
                        Level46_81EC8DeleteMoby(temp_a0_7);
                        __asm__ __volatile__("" ::"i"(103113) : "memory");
                        Level46_81EC8Field(privateRecord20, void**, 0x14) = 0;
                    }
                    goto block_134;
                }
                Level46_81EC8CopyVector(retainedAngleOrAddress18, retainedRecordOrVector17);
                rawWord3 = Level46_81EC8Field(privateRecord20, void**, 0x14);
                if (rawWord3 != 0) {
                    Level46_81EC8Field(rawWord3, unsigned char*, 0x45) =
                        (unsigned char)Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45);
                    Level46_81EC8Field(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                       unsigned char*, 0x46) =
                        (unsigned char)Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46);
                    Level46_81EC8CopyVector(Level46_81EC8Field(privateRecord20, void**, 0x14) + 0xC,
                                            retainedAngleOrAddress18);
                    rawWord3 = Level46_81EC8Field(privateRecord20, int*, 0x14);
                    rawWord2 = 255;
                    Level46_81EC8Field(rawWord3, unsigned char*, 0x54) = rawWord2;
                    Level46_81EC8Field(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                       signed char*, 0x55) = 0;
                    Level46_81EC8Field(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                       signed char*, 0x56) = 0;
                    Level46_81EC8Field(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                       signed char*, 0x57) = 0x38;
                    Level46_81EC8SetMobyAnimation(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                                  4);
                    return;
                }
                default:
                    return;
            }
        block_120:
            if ((retainedRecordOrVector17 != 0) ||
                (Level46_81EC8CountTimerDown(privateRecord20 + 0x10, 2) != 0)) {
                temp_a0_3 = Level46_81EC8Field(privateRecord20, void**, 0x14);
                if (temp_a0_3 != 0) {
                    Level46_81EC8DeleteMoby(temp_a0_3);
                    __asm__ __volatile__("" ::"i"(103112) : "memory");
                    Level46_81EC8Field(privateRecord20, void**, 0x14) = 0;
                }
                goto block_134;
            }
            Level46_81EC8CopyVector(ownerRecord19 + 0xC, &originalFrame.sp38);
            temp_a0_4 = Level46_81EC8Field(privateRecord20, void**, 0x14);
            if (temp_a0_4 != 0) {
                Level46_81EC8CopyVector(temp_a0_4 + 0xC, &originalFrame.sp38);
                Level46_81EC8Field(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                   unsigned char*, 0x45) =
                    (unsigned char)Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45);
                Level46_81EC8Field(Level46_81EC8Field(privateRecord20, void**, 0x14),
                                   unsigned char*, 0x46) =
                    (unsigned char)Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46);
                return;
            }
            break;
        case 4:
            Level46_81EC8Field(ownerRecord19, signed char*, 0x41) = 0;
            Level46_81EC8Field(ownerRecord19, signed char*, 0x4C) = 0;
            Level46_81EC8Field(ownerRecord19, unsigned char*, 0x4D) = 0U;
            if (Level46_81EC8Field(privateRecord20, short*, 0x10) != 0) {
                originalFrame.sp68 = (Level46_81EC8Datarand() & 0xF) - 7;
                originalFrame.sp6C = (Level46_81EC8Datarand() & 0xF) - 7;
                originalFrame.sp70 = Level46_81EC8Datarand() & 0x3F;
                Level46_81EC8DataSpawnParticle(1, 0, ownerRecord19 + 0xC, &originalFrame.sp68);
            }
            if (Level46_81EC8Field(privateRecord20, short*, 0x12) != 0) {
                Level46_81EC8CountTimerDown(privateRecord20 + 0x12, 2);
                temp_v0_12 =
                    Level46_81EC8DataSpawnParticle(1, 0x3D, ownerRecord19 + 0xC, (int*)0x808080);
                if (temp_v0_12 != 0) {
                    Level46_81EC8Field(temp_v0_12, signed char*, 0xA) = 0x32;
                }
            }
            if (Level46_81EC8CountTimerDown(privateRecord20 + 0x10, 2) != 0) {
                goto block_134;
            }
            break;
        case 1:
        case 3:
            if (Level46_81EC8Field(privateRecord20, short*, 0x10) != 0)
                goto continueOriginalStatesOneOrThree;
        block_134:
            Level46_81EC8DeleteMoby(ownerRecord19);
            return;
        continueOriginalStatesOneOrThree:
            if (Level46_81EC8CountTimerDown(privateRecord20 + 0x10, 2) != 0) {
                rawWord2 = 48;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x4F) = rawWord2;
                rawWord2 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x54);
                rawWord3 = 13;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x57) = rawWord3;
                rawWord3 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x56);
                rawWord2 >>= 3;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x54) = rawWord2;
                rawWord2 = Level46_81EC8Field(ownerRecord19, unsigned char*, 0x55);
                rawWord3 = (unsigned int)rawWord3 >> 3;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x56) = rawWord3;
                rawWord2 >>= 3;
                Level46_81EC8Field(ownerRecord19, unsigned char*, 0x55) = rawWord2;
            }
            Level46_81EC8Field(ownerRecord19, unsigned char*, 0x46) =
                (unsigned char)(((int)(Level46_81EC8Data6E040 << 0x10) >> 0x14) - 0x80);
            Level46_81EC8Field(ownerRecord19, unsigned char*, 0x45) =
                (unsigned char)((unsigned short)Level46_81EC8Data6E03E >> 4);
            break;
    }
}
#undef Level46_81EC8Field

void func_level_46_80082FC0(Moby* moby) {
    func_80039714(moby);
}

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
void func_level_46_80082FE0(Moby* argument) {
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
void func_level_46_800833C0(Moby* moby) {
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

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8008343C..80083760. One checksum byte is processed per invocation.
 * Source RAM, tracked pointer producers and runtime cadence unresolved. */
extern unsigned char DecodedAgent227Player[] __asm__("D_80070328");
extern unsigned char DecodedAgent227Flags[] __asm__("D_80070300");
extern unsigned int D_800722B8;
extern unsigned int DecodedAgent227Comparison __asm__("unk_ovlheader_8007439C");
extern int D_8006C770;
int func_80055E84(Moby*);
void func_8002CA50(void);
void func_8002D044(void);
void func_level_46_8008343C(Moby* argument) {
    register Moby* moby __asm__("$17") = argument;
    register int mode __asm__("$2");
    register int* tag __asm__("$16");
    register Moby* child __asm__("$18");
    register int state __asm__("$16");
    Vector3D selectedPosition;
    int pad1;
    Vector3D local;
    int pad2;
    MATCHING_KEEP(moby);
    mode = *(int*)(DecodedAgent227Player + 0x24C);
    tag = moby->mobyTag;
    if (mode == 4) {
        unsigned char* tracked = **(unsigned char***)(DecodedAgent227Player + 0x250);
        tag[1] = *(short*)(tracked + 0x76);
        if (*(int*)(tracked + 0x78))
            tag[1]++;
        if (tag[1] > 0) {
            if (!tag[0]) {
                tag[0] = (short)func_8002803C(21, 460, func_80027E40, func_80027A60, func_80029904,
                                              tag + 1, 10);
                moby->updateDistance = 255;
            }
        } else if (tag[0]) {
            func_80028154(tag[0]);
            tag[0] = 0;
            moby->updateDistance = 16;
        }
    }
    if (!tag[3])
        tag[3] = (int)func_8002CA50 + 3 - 0x80AD;
    if ((unsigned int)tag[3] < (unsigned int)func_8002D044 + 3 - 0x80AD) {
        register int index __asm__("$4") = 0;
        register unsigned int polynomial __asm__("$5") = 0x80050000;
        tag[2] ^= (unsigned int)*(unsigned char*)(tag[3] + 0x80AD) << 24;
        do {
            if (tag[2] < 0)
                tag[2] = ((unsigned int)tag[2] << 1) ^ polynomial;
            else
                tag[2] = (unsigned int)tag[2] << 1;
            index++;
        } while (index < 8);
        tag[3]++;
    } else {
        if ((((unsigned int)(tag[2] >> 12) & 0xFFFF0) | (D_800722B8 & 0xFFF0000F)) !=
            DecodedAgent227Comparison) {
            DecodedAgent227Flags[7] = 0;
            DecodedAgent227Flags[16] = 0;
            DecodedAgent227Flags[25] = 0;
            DecodedAgent227Flags[34] = 0;
            tag[2] = 0;
        }
    }
    state = moby->state;
    switch (state) {
        case 0:
            if (moby->substate != 1) {
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            moby->substate = 0;
            break;
        case 1: {
            int value = func_80055E84(moby);
            if (!moby->substate && moby->animationState.id == state &&
                (unsigned int)(value - 41) < 5) {
                func_80055D24(moby, 5);
                child = SpawnMoby(102, moby);
                MATCHING_KEEP(child);
                if (child) {
                    tag = child->mobyTag;
                    moby->substate = 1;
                    local.x = 60;
                    local.y = 0;
                    local.z = 0;
                    func_8004ED6C(&moby->rotationMatrix, &local, (Vector3D*)tag);
                    tag[2] = 80;
                    func_80055F14(moby, 0, &selectedPosition);
                    {
                        register int z __asm__("$3") = selectedPosition.z;
                        MATCHING_KEEP(z);
                        child->state = 3;
                        child->position.z = z;
                    }
                }
            }
            if (D_8006C770) {
                moby->substate = 0;
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80083760.
* AI generated; not human reviewed. All1536 original instructions,41 selectors,
* one zero pad and every actual destination must match:1578 recorded words.
* FrameE8hex=232 bytes saves S0..S5/RA;SP20..C7 preserves original storage.
* Complete original constant0x3C000000 precedes the color ring. Capacity,
* callback,random sample,field stores and loop-back targets remain ordered.
* Shared countdown1110,height868,record1321/found1395 and removal1524 entries
* retain their physical positions and complete arguments from every caller.
* Ordered state2 helper calls preserve fresh full player pointers and LHU
* angle words before SLL16/SRA20. Absolute word aliases preserve original
* reads/stores;no coordinate or semantic conversion is inferred.
* Original state36 writes SH at private+0;state37 reads LH at private+0.
* Original list selectors remain LBU. Original SH+4 precedes signed low-half
* correction and the following bound check. Independent node pointer reads,
* byte flags and spawn-word producers retain exact widths and timing.
* Original1395..1411 address difference uses complete 32-bit C shift/add/sub
* values,followed by unsigned negation and signed SRA3;no partial hardware
* result exists. For owner=base,base+88,base-88,the final words are0,1,-1.
* These are raw byte-address vectors;the valid retail record domain remains
* subject to the full caller/table chain and runtime verification.
* The complete final48 byte survives its helper calls in original S5.
* Independent full V1 address and V0 byte identities retain interleaved
* indexed loads without extra instructions. All metadata templates are empty;
* they consume initialized complete values or written fields,or clobber dead
* values before fresh complete producers. No opcode asm,fixed FP,undefined
* saved input or overlapping live fixed aliases. Compiler/filter/flags frozen.
* Units/fixed point,full helper/caller chains,cadence beyond invocation,Rev1
* mapping and synchronized runtime remain open. Binary identity only after
* all gates. Next:human review and retail captures. Every native/linked word,
* actual destination,owned selector/padding and full EXE/every-overlay retail
* hash must remain identical.
*/
/* Original assembly SHA256 9c014607fc22f4fd7ffee61ff3e4159d7955b3af582d141c758ab5d6ac91db20 */
#define Level46_83760Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level46_83760Call13E38View1() __asm__("func_80013E38");
int Level46_83760Call19194View1() __asm__("func_80019194");
int Level46_83760Call1A358View1() __asm__("func_8001A358");
int Level46_83760RequestMobyAnimationView1() __asm__("func_80034F40");
int Level46_83760SetMobyAnimationView1() __asm__("func_80034F80");
int Level46_83760TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level46_83760TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level46_83760CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level46_83760Call35A80View1() __asm__("func_80035A80");
int Level46_83760Call35DDCView1() __asm__("func_80035DDC");
int Level46_83760Call35EE0View1() __asm__("func_80035EE0");
int Level46_83760RandBetweenView1() __asm__("func_8003636C");
int Level46_83760Call369B8View1() __asm__("func_800369B8");
int Level46_83760Call3B7B4View1() __asm__("func_8003B7B4");
int Level46_83760PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level46_83760Call3BE70View1() __asm__("func_8003BE70");
int Level46_83760Call3BFC0View1() __asm__("func_8003BFC0");
int Level46_83760PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level46_83760TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level46_83760CopyVectorView1() __asm__("func_8004F178");
int Level46_83760AddVectorView1() __asm__("func_8004F194");
int Level46_83760AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level46_83760ApproachByteAngleView1() __asm__("func_8004F2EC");
int Level46_83760ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level46_83760DeleteMobyView1() __asm__("func_80055B18");
int Level46_83760RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level46_83760Data6C550View1 __asm__("D_8006C550");
extern int Level46_83760Data6C574View1 __asm__("D_8006C574");
extern int Level46_83760Data6C578View1 __asm__("D_8006C578");
extern int Level46_83760Data6C770View1 __asm__("D_8006C770");
extern int Level46_83760Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level46_83760Data6E020View1 __asm__("D_8006E020");
extern int Level46_83760Data6E024View1 __asm__("D_8006E024");
extern int Level46_83760Data6E028View1 __asm__("D_8006E028");
extern unsigned short Level46_83760Data6E03EView1 __asm__("D_8006E03E");
extern unsigned short Level46_83760Data6E040View1 __asm__("D_8006E040");
extern int Level46_83760Data6E044View1 __asm__("D_8006E044");
extern int Level46_83760Data6E344View1 __asm__("D_8006E344");
extern int Level46_83760Data70328View1 __asm__("D_80070328");
extern int Level46_83760Data7190CView1 __asm__("D_8007190C");
extern void* (*Level46_83760DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern int (*Level46_83760Data74414View1)() __asm__("unk_ovlheader_80074414");
extern int Level46_83760Data70328View2 __asm__("D_80070328 + 8");
extern int Level46_83760Data70328View3 __asm__("D_80070328 + 0x298");
void func_level_46_80083760(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int privateThenOwnerPosition20 __asm__("$20"),
        retainedRecordVectorOrPlayerView16 __asm__("$16"),
        retainedCounterPrivateVectorOrSpeed17 __asm__("$17"),
        retainedColorResultDistanceOrPlayerView18 __asm__("$18");
    register int retainedOriginalSpawnByte48 __asm__("$21");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        recordStateSelector8 __asm__("$8"), recordClassSelector9 __asm__("$9");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4;
    } originalFrame;
    int temporaryWord14;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord24;
    int temporaryWord1;
    int temporaryWord6;
    int temporaryWord9;
    int temporaryWord21;
    int temporaryWord26;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord15;
    int temporaryWord23;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord7;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord19;
    int temporaryWord20;
    int temporaryWord22;
    int temporaryWord25;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    privateThenOwnerPosition20 = Level46_83760Field(ownerRecord19, void**, 0);
    if ((Level46_83760Field(ownerRecord19, unsigned char*, 0x4C) != 0) &&
        (Level46_83760Field((int)&Level46_83760Data70328View1, int*, 0x24C) == 4) &&
        ((unsigned char)Level46_83760Field(ownerRecord19, unsigned char*, 0x3D) < 4U)) {
        if (Level46_83760AbsoluteByteAngleDeltaView1(
                (int)(Level46_83760Data6E040View1 << 0x10) >> 0x14,
                Level46_83760PlanarHeadingLookupView1(
                    Level46_83760Field(ownerRecord19, int*, 0xC) - Level46_83760Data6E020View1,
                    Level46_83760Field(ownerRecord19, int*, 0x10) - Level46_83760Data6E024View1,
                    0)) < 0x18) {
            if (Level46_83760Data6E044View1 == 0x1F) {
                Level46_83760Field(ownerRecord19, unsigned char*, 0x4E) =
                    (unsigned char)Level46_83760Field(ownerRecord19, unsigned char*, 0x4C);
            } else {
                goto writeOriginalStatusByte53;
            }
        } else {
        writeOriginalStatusByte53:
            Level46_83760Field(ownerRecord19, unsigned char*, 0x4E) = 0x10U;
        }
    }
    temporaryWord15 = Level46_83760Field(ownerRecord19, unsigned char*, 0x48);
    temporaryWord1 = temporaryWord15 & 0xFF;
    if (temporaryWord1 == 0x2C) {
        Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x28U;
        Level46_83760Call3B7B4View1(ownerRecord19 + 0x48, 1, (int)&Level46_83760Data6C7F8View1);
        goto removeOriginalOwner1524;
    }
    if (temporaryWord1 != 0x2A) {
        if (((unsigned int)(temporaryWord15 - 5) >= 2U) &&
            ((unsigned int)(temporaryWord15 - 0x24) >= 2U) && (temporaryWord1 != 0x1E)) {
            retainedCounterPrivateVectorOrSpeed17 = 0;
            if (Level46_83760Field(ownerRecord19, int*, 0x18) != 0) {
                retainedColorResultDistanceOrPlayerView18 = 0x3C000000;
                MATCHING_OBSERVE_VOLATILE(retainedColorResultDistanceOrPlayerView18);
            spawnOriginalColorRing80:
                rawWord2 = Level46_83760Data6C578View1;
                rawWord3 = Level46_83760Data6C574View1;
                rawWord2 -= rawWord3;
                rawWord2 = rawWord2 < 21;
                argumentWord4 = 245;
                if (!rawWord2) {
                    temporaryWord4 = Level46_83760DataSpawnMobyView1(argumentWord4, ownerRecord19);
                    if (temporaryWord4 != 0) {
                        Level46_83760Field(temporaryWord4, int*, 0x54) =
                            (int)((Level46_83760RandBetweenView1(0x10, 0xA0) << 8) |
                                  retainedColorResultDistanceOrPlayerView18);
                    }
                    retainedCounterPrivateVectorOrSpeed17 += 1;
                    if (retainedCounterPrivateVectorOrSpeed17 < 0xC) {
                        goto spawnOriginalColorRing80;
                    }
                }
                MATCHING_BARRIER_VOLATILE("$4");
                argumentWord4 = 297;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$5");
                rawWord2 = (int)Level46_83760DataSpawnMobyView1;
                argumentWord5 = (int)ownerRecord19;
                Level46_83760Field(ownerRecord19, int*, 24) = 0;
                temporaryWord10 = ((int (*)())rawWord2)(argumentWord4, argumentWord5);
                if (temporaryWord10 != 0) {
                    temporaryWord21 = Level46_83760Field(privateThenOwnerPosition20, int*, 8);
                    retainedCounterPrivateVectorOrSpeed17 =
                        Level46_83760Field(temporaryWord10, void**, 0);
                    if (temporaryWord21 >= 0) {
                        temporaryWord22 = Level46_83760Field(
                            ((temporaryWord21 * 0x58) + Level46_83760Data6C550View1), int*, 0);
                        Level46_83760Field(temporaryWord22, int*, 0x64) =
                            (int)(Level46_83760Field(temporaryWord22, int*, 0x64) + 1);
                    }
                    Level46_83760PlayMobySoundEventView1(temporaryWord10, 1, 0);
                    argumentWord4 = temporaryWord10;
                    argumentWord5 = 6;
                    MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                    rawWord3 = Level46_83760Field(ownerRecord19, unsigned char*, 70);
                    rawWord2 = 32;
                    Level46_83760Field(argumentWord4, unsigned char*, 76) = rawWord2;
                    rawWord2 = 255;
                    Level46_83760Field(argumentWord4, unsigned char*, 74) = rawWord2;
                    rawWord2 = 6;
                    Level46_83760Field(argumentWord4, unsigned char*, 72) = rawWord2;
                    Level46_83760Field(argumentWord4, unsigned char*, 70) = rawWord3;
                    Level46_83760SetMobyAnimationView1(argumentWord4, argumentWord5);
                    rawWord3 = Level46_83760Field(privateThenOwnerPosition20, int*, 8);
                    rawWord2 = 200;
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, int*, 20) = rawWord2;
                    rawWord2 = 180;
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 2) = rawWord2;
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, int*, 8) = rawWord3;
                }
                rawWord3 = Level46_83760Field(ownerRecord19, unsigned char*, 58);
                rawWord2 = 255;
                argumentWord4 = (int)ownerRecord19;
                if (rawWord3 == rawWord2) {
                    Level46_83760RefreshMobySpatialGridAndBasisView1(argumentWord4, 4);
                    Level46_83760Call369B8View1(ownerRecord19, 0x28);
                    Level46_83760Field(ownerRecord19, signed char*, 0x41) = 0;
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x4C) = 0U;
                    Level46_83760Field(ownerRecord19, signed char*, 0x4D) = 0;
                    Level46_83760Field(ownerRecord19, int*, 8) = 0;
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x2AU;
                    return;
                }
                Level46_83760RefreshMobySpatialGridAndBasisView1(argumentWord4, 4);
                Level46_83760Call369B8View1(ownerRecord19, 0x28);
                __asm__ volatile("" ::"r"(ownerRecord19), "i"(0x80083A18));
                goto removeOriginalOwner1524;
            }
        }
        temporaryWord23 = Level46_83760Field(ownerRecord19, unsigned char*, 0x48);
        switch (temporaryWord23) {
            case 0:
                rawWord2 = Level46_83760TurnMobyTowardPlayerView1(ownerRecord19, 6, 4, 0);
                argumentWord4 = privateThenOwnerPosition20 + 2;
                argumentWord5 = 2;
                MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                retainedRecordVectorOrPlayerView16 = rawWord2;
                if ((Level46_83760CountTimerDownView1(argumentWord4, argumentWord5) != 0) &&
                    (retainedRecordVectorOrPlayerView16 == 1) &&
                    (Level46_83760ApproximatePlanarDistanceView1(
                         ownerRecord19 + 0xC, (int)&Level46_83760Data70328View1) < 0x3000)) {
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 2;
                    rawWord2 = 2;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
                    Level46_83760Field(argumentWord4, unsigned char*, 72) = rawWord2;
                    Level46_83760RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    argumentWord4 = 60;
                    argumentWord5 = 100;
                    goto sampleOriginalCountdown1110;
                }
                break;
            case 2:
                rawWord2 = Level46_83760TurnMobyTowardPlayerView1(ownerRecord19, 6, 4, 0);
                argumentWord4 = (int)ownerRecord19;
                argumentWord5 = 7;
                MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                retainedColorResultDistanceOrPlayerView18 = rawWord2;
                Level46_83760RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
                argumentWord4 = (int)&originalFrame.sp20;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
                retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                Level46_83760CopyVectorView1(argumentWord4, retainedCounterPrivateVectorOrSpeed17);
                originalFrame.sp28 += 0x1F4;
                rawWord3 = Level46_83760Field(privateThenOwnerPosition20, int*, 4);
                retainedRecordVectorOrPlayerView16 = 0;
                if (rawWord3 >= 0) {
                    rawWord2 = rawWord3 * 88;
                    rawWord3 = Level46_83760Data6C550View1;
                    rawWord3 += rawWord2;
                    MATCHING_OBSERVE_VOLATILE(rawWord3);
                    rawWord2 = Level46_83760Field(rawWord3, int*, 0);
                    retainedRecordVectorOrPlayerView16 = Level46_83760Field(rawWord2, int*, 28);
                }
                rawWord2 = 1;
                if (retainedColorResultDistanceOrPlayerView18 != rawWord2)
                    goto originalState2Done326;
                rawWord2 = Level46_83760Data6E344View1;
                if (rawWord2 == retainedColorResultDistanceOrPlayerView18)
                    goto originalState2Done326;
                argumentWord4 = retainedCounterPrivateVectorOrSpeed17;
                if (!retainedRecordVectorOrPlayerView16)
                    goto originalState2Distance264;
                rawWord2 = (int)Level46_83760Data74414View1;
                argumentWord5 = (int)&Level46_83760Data70328View1;
                argumentWord4 = retainedRecordVectorOrPlayerView16;
                rawWord2 = ((int (*)())rawWord2)(argumentWord4, argumentWord5);
                argumentWord4 = retainedCounterPrivateVectorOrSpeed17;
                if (!rawWord2)
                    goto originalState2Done326;
            originalState2Distance264:
                retainedColorResultDistanceOrPlayerView18 = (int)&Level46_83760Data70328View1;
                rawWord2 = Level46_83760ApproximatePlanarDistanceView1(
                    argumentWord4, retainedColorResultDistanceOrPlayerView18);
                rawWord2 = rawWord2 < 8001;
                argumentWord6 = 0;
                if (rawWord2)
                    goto originalState2Done326;
                retainedRecordVectorOrPlayerView16 = (int)&Level46_83760Data6E020View1;
                rawWord3 = Level46_83760Field(ownerRecord19, int*, 12);
                argumentWord4 = Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 0);
                rawWord2 = Level46_83760Field(ownerRecord19, int*, 16);
                argumentWord5 = Level46_83760Data6E024View1;
                argumentWord4 = rawWord3 - argumentWord4;
                argumentWord5 = rawWord2 - argumentWord5;
                rawWord2 = Level46_83760PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                 argumentWord6);
                argumentWord4 = Level46_83760Data6E040View1;
                argumentWord5 = rawWord2;
                argumentWord4 = (argumentWord4 << 16) >> 20;
                rawWord2 = Level46_83760AbsoluteByteAngleDeltaView1(argumentWord4, argumentWord5);
                rawWord2 = rawWord2 < 24;
                argumentWord4 = (int)&originalFrame.sp20;
                if (!rawWord2)
                    goto originalState2Done326;
                rawWord2 = Level46_83760Call13E38View1(
                    argumentWord4, retainedColorResultDistanceOrPlayerView18, 0);
                argumentWord4 = retainedRecordVectorOrPlayerView16;
                if (!rawWord2)
                    goto originalState2Done326;
                rawWord2 = Level46_83760ApproximatePlanarDistanceView1(
                    argumentWord4, retainedCounterPrivateVectorOrSpeed17);
                argumentWord4 = rawWord2;
                rawWord2 = Level46_83760Data6E028View1;
                argumentWord5 = Level46_83760Field(ownerRecord19, int*, 20);
                argumentWord5 = rawWord2 - argumentWord5;
                rawWord2 = Level46_83760PlanarHeadingLookupView1(argumentWord4, argumentWord5, 0);
                argumentWord4 = Level46_83760Data6E03EView1;
                argumentWord5 = rawWord2;
                argumentWord4 = (argumentWord4 << 16) >> 20;
                rawWord2 = Level46_83760AbsoluteByteAngleDeltaView1(argumentWord4, argumentWord5);
                rawWord2--;
                rawWord2 = rawWord2 < 13;
                if (!rawWord2)
                    goto originalState2Done326;
                {
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 1);
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x15U;
                    Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1) = 0U;
                    Level46_83760Field(privateThenOwnerPosition20, short*, 2) = 0x19;
                    Level46_83760Field(ownerRecord19, int*, 0x14) =
                        (int)(Level46_83760Field(ownerRecord19, int*, 0x14) + 0x100);
                    return;
                }
            originalState2Done326:
                if (Level46_83760Data6C770View1 != 0) {
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 0);
                    return;
                }
                break;
            case 21:
                Level46_83760TurnMobyTowardPlayerView1(ownerRecord19, 6, 0, 0);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                if (Level46_83760CountTimerDownView1(privateThenOwnerPosition20 + 2, 2) != 0) {
                    Level46_83760Call35DDCView1(ownerRecord19, 0x4B, 0, 0, 0);
                    argumentWord4 =
                        Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1);
                    rawWord2 = Level46_83760Field(ownerRecord19, int*, 20);
                    rawWord3 = 255;
                    Level46_83760Field(ownerRecord19, unsigned char*, 84) = rawWord3;
                    rawWord2 += argumentWord4;
                    Level46_83760Field(ownerRecord19, int*, 20) = rawWord2;
                    temporaryWord11 =
                        Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1) - 5;
                    Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1) =
                        temporaryWord11;
                    if ((unsigned int)(temporaryWord11 & 0xFF) >= 0xF6U) {
                        Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1) = 0U;
                    }
                    rawWord3 = Level46_83760Field(privateThenOwnerPosition20, int*, 4);
                    if (rawWord3 >= 0) {
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = Level46_83760Data6C550View1;
                        rawWord3 += rawWord2;
                        MATCHING_KEEP_VOLATILE(rawWord3);
                        rawWord2 =
                            Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 0);
                        rawWord3 = Level46_83760Field(rawWord3, int*, 0);
                        MATCHING_KEEP(rawWord2);
                        rawWord2 *= 4;
                        rawWord2 += rawWord3;
                        argumentWord4 = Level46_83760Field(rawWord2, int*, 12);
                        if (Level46_83760Data74414View1(argumentWord4, ownerRecord19 + 12) == 0) {
                            Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x16U;
                            Level46_83760Field(privateThenOwnerPosition20, short*, 2) = 0xD2;
                            return;
                        }
                    } else {
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x16U;
                        Level46_83760Field(privateThenOwnerPosition20, short*, 2) = 0xB4;
                        return;
                    }
                } else {
                    Level46_83760Call35DDCView1(ownerRecord19, 0x32, 0, 0, 0);
                    Level46_83760Field(ownerRecord19, int*, 0x14) =
                        (int)(Level46_83760Field(ownerRecord19, int*, 0x14) +
                              Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1));
                    Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 1) =
                        (unsigned char)(Level46_83760Field(privateThenOwnerPosition20,
                                                           unsigned char*, 1) +
                                        5);
                    return;
                }
                break;
            case 22:
                if ((unsigned int)(Level46_83760Field(ownerRecord19, unsigned char*, 0x3C) - 3) <
                    2U) {
                    retainedRecordVectorOrPlayerView16 =
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x54);
                    if (retainedRecordVectorOrPlayerView16 == 0xFF) {
                        retainedRecordVectorOrPlayerView16 = -1U;
                    }
                    if (Level46_83760Call3BFC0View1(ownerRecord19,
                                                    retainedRecordVectorOrPlayerView16) == 0) {
                        retainedRecordVectorOrPlayerView16 =
                            Level46_83760PlayMobySoundEventView1(ownerRecord19, 0, 4);
                    }
                    if (retainedRecordVectorOrPlayerView16 == -1U) {
                        retainedRecordVectorOrPlayerView16 = 0xFF;
                    }
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x54) =
                        retainedRecordVectorOrPlayerView16;
                }
                Level46_83760TurnMobyTowardPlayerView1(ownerRecord19, 6, 2, 1);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                Level46_83760Call35DDCView1(ownerRecord19, 0x64, 0, 0, 0);
                MATCHING_KEEP(ownerRecord19);
                retainedColorResultDistanceOrPlayerView18 = (int)ownerRecord19 + 12;
                if (Level46_83760Call19194View1(retainedColorResultDistanceOrPlayerView18, 0x200) !=
                    0) {
                    Level46_83760CopyVectorView1(retainedColorResultDistanceOrPlayerView18,
                                                 (int)&Level46_83760Data7190CView1);
                }
                Level46_83760CopyVectorView1(&originalFrame.sp40,
                                             (int)&Level46_83760Data70328View1);
                originalFrame.sp48 =
                    Level46_83760Call1A358View1(&originalFrame.sp40, 0x1000) + 0x1F4;
                retainedColorResultDistanceOrPlayerView18 =
                    Level46_83760ApproximatePlanarDistanceView1(
                        retainedColorResultDistanceOrPlayerView18,
                        (int)&Level46_83760Data70328View1);
                if ((originalFrame.sp48 + 0x190) < Level46_83760Field(ownerRecord19, int*, 0x14)) {
                    originalFrame.sp48 -= 0x32C8;
                    goto refreshOriginalOwnerPosition502;
                }
                originalFrame.sp48 += 0x12C;
                MATCHING_KEEP(ownerRecord19);
                retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                if ((Level46_83760Field(ownerRecord19, unsigned char*, 0x49) == 1) &&
                    (Level46_83760Field(ownerRecord19, unsigned char*, 0x3D) != 3)) {
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 3);
                    Level46_83760Field(ownerRecord19, signed char*, 0x4F) = 0x2D;
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x40) = 0xF0;
                refreshOriginalOwnerPosition502:
                    MATCHING_KEEP(ownerRecord19);
                    retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                }
                Level46_83760Field(ownerRecord19, unsigned char*, 0x45) =
                    Level46_83760ApproachByteAngleView1(
                        Level46_83760PlanarHeadingLookupView1(
                            Level46_83760ApproximatePlanarDistanceView1(
                                retainedCounterPrivateVectorOrSpeed17, &originalFrame.sp40),
                            originalFrame.sp48 - Level46_83760Field(ownerRecord19, int*, 0x14), 0),
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x45), 6, 4);
                originalFrame.sp30 = 0x64;
                originalFrame.sp34 = 0;
                originalFrame.sp38 = 0;
                Level46_83760TransformVectorByBasisView1(ownerRecord19 + 0x20, &originalFrame.sp30,
                                                         &originalFrame.sp30);
                Level46_83760AddVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                            &originalFrame.sp30,
                                            retainedCounterPrivateVectorOrSpeed17);
                if (retainedColorResultDistanceOrPlayerView18 < 0x1770) {
                    if (Level46_83760Field(ownerRecord19, unsigned char*, 0x49) == 1) {
                        argumentWord4 = (int)ownerRecord19;
                        MATCHING_KEEP(argumentWord4);
                        argumentWord5 = 4;
                        rawWord2 = 45;
                        __asm__(""
                                : "=r"(rawWord2)
                                : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
                        Level46_83760Field(ownerRecord19, unsigned char*, 79) = rawWord2;
                        Level46_83760RequestMobyAnimationView1(argumentWord4, argumentWord5);
                        rawWord2 = 2;
                        goto writeOriginalContactState611;
                    }
                    goto checkOriginalContactState545;
                }
            checkOriginalContactState545:
                if ((Level46_83760Field(ownerRecord19, unsigned char*, 0x49) == 2) && ({
                        rawWord2 = retainedColorResultDistanceOrPlayerView18 < 1800;
                        MATCHING_OBSERVE_VOLATILE(retainedColorResultDistanceOrPlayerView18);
                        rawWord2;
                    })) {
                    rawWord2 = Level46_83760Field(ownerRecord19, int*, 20);
                    rawWord3 = Level46_83760Data70328View2;
                    rawWord2 -= rawWord3;
                    if (rawWord2 < 0)
                        rawWord2 = -rawWord2;
                    if ((rawWord2 < 1024) &&
                        (Level46_83760AbsoluteByteAngleDeltaView1(
                             (int)(Level46_83760Data6E040View1 << 0x10) >> 0x14,
                             Level46_83760PlanarHeadingLookupView1(
                                 Level46_83760Field(ownerRecord19, int*, 0xC) -
                                     Level46_83760Data6E020View1,
                                 Level46_83760Field(ownerRecord19, int*, 0x10) -
                                     Level46_83760Data6E024View1,
                                 0)) < 0x14) &&
                        (Level46_83760AbsoluteByteAngleDeltaView1(
                             Level46_83760PlanarHeadingLookupView1(
                                 Level46_83760Field((int)&Level46_83760Data70328View1, int*, 0) -
                                     Level46_83760Field(ownerRecord19, int*, 0xC),
                                 Level46_83760Field((int)&Level46_83760Data70328View1, int*, 4) -
                                     Level46_83760Field(ownerRecord19, int*, 0x10),
                                 0),
                             Level46_83760Field(ownerRecord19, unsigned char*, 0x46)) < 8) &&
                        (Level46_83760Data6E344View1 != 1)) {
                        Level46_83760Field((int)&Level46_83760Data70328View1, int*, 0x24) =
                            (int)(Level46_83760Field((int)&Level46_83760Data70328View1, int*,
                                                     0x24) |
                                  1);
                        {
                            int originalHeadingWord =
                                Level46_83760Field(ownerRecord19, unsigned char*, 70);
                            Level46_83760Field((int)&Level46_83760Data70328View1, int*, 0x298) =
                                originalHeadingWord;
                        }
                        __asm__ volatile("" ::: "$2", "memory");
                        rawWord2 = 3;
                    writeOriginalContactState611:
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x49) = rawWord2;
                    }
                }
                if ((Level46_83760Data6C770View1 == 0) ||
                    (Level46_83760Field(ownerRecord19, unsigned char*, 0x3C) != 4)) {
                    Level46_83760CountTimerDownView1(privateThenOwnerPosition20 + 2, 2);
                    if (Level46_83760Field(privateThenOwnerPosition20, short*, 2) < 0xA5) {
                        rawWord3 = Level46_83760Field(privateThenOwnerPosition20, int*, 4);
                        retainedRecordVectorOrPlayerView16 = 0;
                        if (rawWord3 >= 0) {
                            rawWord2 = rawWord3 * 88;
                            rawWord3 = Level46_83760Data6C550View1;
                            rawWord3 += rawWord2;
                            MATCHING_OBSERVE_VOLATILE(rawWord3);
                            rawWord2 = Level46_83760Field(rawWord3, int*, 0);
                            retainedRecordVectorOrPlayerView16 =
                                Level46_83760Field(rawWord2, int*, 28);
                        }
                        retainedColorResultDistanceOrPlayerView18 =
                            (int)&Level46_83760Data6E020View1;
                        argumentWord4 = retainedColorResultDistanceOrPlayerView18;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
                        retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                        if (((Level46_83760AbsoluteByteAngleDeltaView1(
                                  (int)(Level46_83760Data6E03EView1 << 0x10) >> 0x14,
                                  Level46_83760PlanarHeadingLookupView1(
                                      Level46_83760ApproximatePlanarDistanceView1(
                                          argumentWord4, retainedCounterPrivateVectorOrSpeed17),
                                      Level46_83760Data6E028View1 -
                                          Level46_83760Field(ownerRecord19, int*, 0x14),
                                      0)) -
                              1) >= 0x12) ||
                            (Level46_83760Field(privateThenOwnerPosition20, short*, 2) == 0) ||
                            (Level46_83760AbsoluteByteAngleDeltaView1(
                                 (int)(Level46_83760Data6E040View1 << 0x10) >> 0x14,
                                 Level46_83760PlanarHeadingLookupView1(
                                     Level46_83760Field(ownerRecord19, int*, 12) -
                                         Level46_83760Field(
                                             retainedColorResultDistanceOrPlayerView18, int*, 0),
                                     Level46_83760Field(ownerRecord19, int*, 0x10) -
                                         Level46_83760Data6E024View1,
                                     0)) >= 0x19) ||
                            ((retainedRecordVectorOrPlayerView16 != 0) &&
                             (Level46_83760Data74414View1(retainedRecordVectorOrPlayerView16,
                                                          (int)&Level46_83760Data70328View1) ==
                              0)) ||
                            (Level46_83760Call13E38View1(retainedCounterPrivateVectorOrSpeed17,
                                                         (int)&Level46_83760Data70328View1,
                                                         0) == 0)) {
                            goto resetOriginalContactState709;
                        }
                    }
                } else {
                resetOriginalContactState709:
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x1AU;
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 1);
                    retainedRecordVectorOrPlayerView16 =
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x54);
                    if (retainedRecordVectorOrPlayerView16 == 0xFF) {
                        retainedRecordVectorOrPlayerView16 = -1U;
                    }
                    if (Level46_83760Call3BFC0View1(ownerRecord19,
                                                    retainedRecordVectorOrPlayerView16) != 0) {
                        Level46_83760Call3BE70View1(retainedRecordVectorOrPlayerView16);
                    }
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x54) = 0xFFU;
                    return;
                }
                break;
            case 26:
                rawWord2 = Level46_83760Field(ownerRecord19, unsigned char*, 69);
                if (rawWord2) {
                    rawWord3 = rawWord2;
                    MATCHING_KEEP(rawWord3);
                    if (rawWord3 >= 129) {
                        if (rawWord3 < 252) {
                            rawWord3 += 4;
                            Level46_83760Field(ownerRecord19, unsigned char*, 69) = rawWord3;
                        } else
                            goto originalTurnClear725;
                    } else {
                        rawWord2 = rawWord3 < 5;
                        rawWord3 -= 4;
                        if (rawWord2) {
                        originalTurnClear725:
                            rawWord3 = 0;
                        }
                        Level46_83760Field(ownerRecord19, unsigned char*, 69) = rawWord3;
                    }
                }
                Level46_83760Field(ownerRecord19, signed char*, 0x4F) = 0x20;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                argumentWord6 = 0;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord6, "$17");
                retainedCounterPrivateVectorOrSpeed17 = 75;
                retainedRecordVectorOrPlayerView16 = Level46_83760PlanarHeadingLookupView1(
                    Level46_83760Field(privateThenOwnerPosition20, int*, 0xC) -
                        Level46_83760Field(ownerRecord19, int*, 0xC),
                    Level46_83760Field(privateThenOwnerPosition20, int*, 0x10) -
                        Level46_83760Field(ownerRecord19, int*, 0x10),
                    argumentWord6);
                if (Level46_83760Field(ownerRecord19, unsigned char*, 0x3D) == 3) {
                    retainedCounterPrivateVectorOrSpeed17 = 0x64;
                }
                if (Level46_83760Field(privateThenOwnerPosition20, int*, 4) >= 0) {
                    Level46_83760TurnMobyTowardHeadingView1(
                        ownerRecord19, retainedRecordVectorOrPlayerView16, 6, 1, 1, 0);
                    Level46_83760Call35DDCView1(ownerRecord19,
                                                retainedCounterPrivateVectorOrSpeed17, 0, 0, 0);
                }
                if (Level46_83760AbsoluteByteAngleDeltaView1(
                        (int)retainedRecordVectorOrPlayerView16,
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x46)) < 2) {
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x19U;
                }
                MATCHING_KEEP(ownerRecord19);
                retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                goto prepareOriginalHeightTest867;
            case 25:
                Level46_83760TurnMobyTowardHeadingView1(
                    ownerRecord19,
                    Level46_83760PlanarHeadingLookupView1(
                        Level46_83760Field(privateThenOwnerPosition20, int*, 0xC) -
                            Level46_83760Field(ownerRecord19, int*, 0xC),
                        Level46_83760Field(privateThenOwnerPosition20, int*, 0x10) -
                            Level46_83760Field(ownerRecord19, int*, 0x10),
                        0),
                    6, 1, 1, 0);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                Level46_83760CopyVectorView1(&originalFrame.sp60, privateThenOwnerPosition20 + 0xC);
                originalFrame.sp68 += 0x2710;
                retainedRecordVectorOrPlayerView16 =
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x45);
                if ((int)retainedRecordVectorOrPlayerView16 >= 0x81) {
                    retainedRecordVectorOrPlayerView16 -= 0x100;
                }
                temporaryWord26 =
                    Level46_83760PlanarHeadingLookupView1(
                        Level46_83760ApproximatePlanarDistanceView1(ownerRecord19 + 0xC,
                                                                    &originalFrame.sp60),
                        originalFrame.sp68 - Level46_83760Field(ownerRecord19, int*, 0x14), 0) -
                    retainedRecordVectorOrPlayerView16;
                if (temporaryWord26 < -4) {
                    temporaryWord26 = -4;
                    goto block_121;
                }
                temporaryWord25 = ownerRecord19 + 0x20;
                if (temporaryWord26 >= 5) {
                    temporaryWord26 = 4;
                block_121:
                    temporaryWord25 = ownerRecord19 + 0x20;
                }
                Level46_83760Field(ownerRecord19, unsigned char*, 0x45) =
                    (unsigned char)(Level46_83760Field(ownerRecord19, unsigned char*, 0x45) +
                                    temporaryWord26);
                originalFrame.sp50 = 0x96;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = 0;
                Level46_83760TransformVectorByBasisView1(temporaryWord25, &originalFrame.sp50,
                                                         &originalFrame.sp50);
                MATCHING_KEEP(ownerRecord19);
                retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                Level46_83760AddVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                            &originalFrame.sp50,
                                            retainedCounterPrivateVectorOrSpeed17);
                temporaryWord24 = retainedCounterPrivateVectorOrSpeed17;
                if (Level46_83760Field(ownerRecord19, int*, 0x14) >=
                    (Level46_83760Field(privateThenOwnerPosition20, int*, 0x14) + 0x400)) {
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 1);
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x17U;
                    goto prepareOriginalHeightTest867;
                }
            prepareOriginalHeightTest867:
                temporaryWord24 = retainedCounterPrivateVectorOrSpeed17;
            testOriginalHeight868:
                if (Level46_83760Call19194View1(temporaryWord24, 0x200) != 0) {
                    Level46_83760CopyVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                                 (int)&Level46_83760Data7190CView1);
                    return;
                }
                break;
            case 23:
                Level46_83760TurnMobyTowardHeadingView1(
                    ownerRecord19,
                    Level46_83760PlanarHeadingLookupView1(
                        Level46_83760Field(privateThenOwnerPosition20, int*, 0xC) -
                            Level46_83760Field(ownerRecord19, int*, 0xC),
                        Level46_83760Field(privateThenOwnerPosition20, int*, 0x10) -
                            Level46_83760Field(ownerRecord19, int*, 0x10),
                        0),
                    8, 0, 0, 0);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                argumentWord4 = (int)&originalFrame.sp80;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
                retainedColorResultDistanceOrPlayerView18 = privateThenOwnerPosition20 + 12;
                Level46_83760CopyVectorView1(argumentWord4,
                                             retainedColorResultDistanceOrPlayerView18);
                MATCHING_KEEP(ownerRecord19);
                retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                originalFrame.sp88 += 0x400;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x45) =
                    Level46_83760ApproachByteAngleView1(
                        Level46_83760PlanarHeadingLookupView1(
                            Level46_83760ApproximatePlanarDistanceView1(
                                retainedCounterPrivateVectorOrSpeed17, &originalFrame.sp80),
                            originalFrame.sp88 - Level46_83760Field(ownerRecord19, int*, 0x14), 0),
                        Level46_83760Field(ownerRecord19, unsigned char*, 0x45), 6, 4);
                originalFrame.sp70 = 0x64;
                originalFrame.sp74 = 0;
                originalFrame.sp78 = 0;
                Level46_83760TransformVectorByBasisView1(ownerRecord19 + 0x20, &originalFrame.sp70,
                                                         &originalFrame.sp70);
                Level46_83760AddVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                            &originalFrame.sp70,
                                            retainedCounterPrivateVectorOrSpeed17);
                if (Level46_83760ApproximatePlanarDistanceView1(
                        retainedCounterPrivateVectorOrSpeed17,
                        retainedColorResultDistanceOrPlayerView18) < 0x3E8) {
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x18U;
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x45) = 0U;
                    return;
                }
                break;
            case 24:
                Level46_83760TurnMobyTowardHeadingView1(
                    ownerRecord19,
                    Level46_83760PlanarHeadingLookupView1(
                        Level46_83760Field(privateThenOwnerPosition20, int*, 0xC) -
                            Level46_83760Field(ownerRecord19, int*, 0xC),
                        Level46_83760Field(privateThenOwnerPosition20, int*, 0x10) -
                            Level46_83760Field(ownerRecord19, int*, 0x10),
                        0),
                    8, 0, 0, 0);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                Level46_83760Call35DDCView1(ownerRecord19, 0x32, 0, 0, 0);
                argumentWord4 = Level46_83760Field(privateThenOwnerPosition20, int*, 20);
                rawWord3 = Level46_83760Field(ownerRecord19, int*, 20);
                rawWord2 = argumentWord4 + 200;
                rawWord2 = rawWord2 < rawWord3;
                if (rawWord2) {
                    rawWord2 = rawWord3 - 75;
                    goto originalStoreHeight977;
                }
                rawWord2 = argumentWord4 + 50;
                rawWord2 = rawWord2 < rawWord3;
                if (!rawWord2)
                    goto originalAfterHeight978;
                rawWord2 = rawWord3 - 50;
            originalStoreHeight977:
                Level46_83760Field(ownerRecord19, int*, 20) = rawWord2;
            originalAfterHeight978:
                MATCHING_KEEP(ownerRecord19);
                retainedCounterPrivateVectorOrSpeed17 = (int)ownerRecord19 + 12;
                argumentWord4 = retainedCounterPrivateVectorOrSpeed17;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$16");
                retainedRecordVectorOrPlayerView16 = privateThenOwnerPosition20 + 12;
                if (Level46_83760ApproximatePlanarDistanceView1(
                        argumentWord4, retainedRecordVectorOrPlayerView16) < 0x80) {
                    Level46_83760CopyVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                                 retainedRecordVectorOrPlayerView16);
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                    Level46_83760Field(ownerRecord19, int*, 0x14) =
                        (int)(Level46_83760Field(ownerRecord19, int*, 0x14) + 0x32);
                    Level46_83760Field(privateThenOwnerPosition20, short*, 2) =
                        Level46_83760RandBetweenView1(0x3C, 0x64);
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 0);
                    return;
                }
                break;
            case 6:
                Level46_83760Field(ownerRecord19, int*, 0x14) =
                    (int)(Level46_83760Field(ownerRecord19, int*, 0x14) +
                          Level46_83760Field(privateThenOwnerPosition20, int*, 0x14));
                Level46_83760Field(privateThenOwnerPosition20, int*, 0x14) =
                    (int)(Level46_83760Field(privateThenOwnerPosition20, int*, 0x14) - 0xC);
                Level46_83760Call35EE0View1(
                    ownerRecord19,
                    (Level46_83760Field(ownerRecord19, unsigned char*, 0x46) + 0x80) & 0xFF, 0x32,
                    0, 0, 0);
                if ((Level46_83760CountTimerDownView1(privateThenOwnerPosition20 + 2, 2) != 0) ||
                    ((Level46_83760Field(privateThenOwnerPosition20, int*, 0x14) < 0) &&
                     (Level46_83760Call19194View1(ownerRecord19 + 0xC, 0x1F4) != 0))) {
                    Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                    Level46_83760Call369B8View1(ownerRecord19, 0x28);
                    goto removeOriginalOwner1524;
                }
                break;
            case 5:
                retainedRecordVectorOrPlayerView16 = Level46_83760Field(ownerRecord19, void**, 0);
                if (Level46_83760Field(ownerRecord19, unsigned char*, 0x49) == 0) {
                    Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                    Level46_83760SetMobyAnimationView1(ownerRecord19, 5);
                }
                rawWord3 = Level46_83760Field(retainedRecordVectorOrPlayerView16, short*, 2);
                MATCHING_KEEP(rawWord3);
                if (rawWord3) {
                    rawWord2 = rawWord3 * 88;
                    rawWord3 = Level46_83760Data6C550View1;
                    rawWord3 += rawWord2;
                    MATCHING_OBSERVE_VOLATILE(rawWord3);
                    rawWord2 = Level46_83760Field(rawWord3, unsigned char*, 72);
                    if (rawWord2 & 128) {
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, short*, 2) = 0;
                        return;
                    }
                }
                break;
            case 20:
                retainedCounterPrivateVectorOrSpeed17 = privateThenOwnerPosition20 + 0xC;
                Level46_83760CopyVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                             ownerRecord19 + 0xC);
                argumentWord4 = 297;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$5");
                rawWord2 = (int)Level46_83760DataSpawnMobyView1;
                argumentWord5 = (int)ownerRecord19;
                Level46_83760Field(privateThenOwnerPosition20, short*, 2) = 0;
                temporaryWord12 = ((int (*)())rawWord2)(argumentWord4, argumentWord5);
                if (temporaryWord12 != 0) {
                    temporaryWord16 = Level46_83760Field(temporaryWord12, void**, 0);
                    Level46_83760Field(temporaryWord16, short*, 0) =
                        (short)Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 0);
                    rawWord2 = Level46_83760Field(privateThenOwnerPosition20, int*, 4);
                    Level46_83760Field(temporaryWord16, short*, 2) = 0;
                    Level46_83760Field(temporaryWord16, int*, 4) = rawWord2;
                    Level46_83760Field(temporaryWord16, int*, 8) =
                        (int)Level46_83760Field(privateThenOwnerPosition20, int*, 8);
                    Level46_83760CopyVectorView1(temporaryWord16 + 0xC,
                                                 retainedCounterPrivateVectorOrSpeed17);
                    Level46_83760Field(temporaryWord12, signed char*, 0x48) = 5;
                    Level46_83760Field(temporaryWord12, signed char*, 0x49) = 0;
                    Level46_83760Field(temporaryWord12, signed char*, 0x4C) = 0x18;
                    Level46_83760SetMobyAnimationView1(temporaryWord12, 5);
                }
                Level46_83760Field(ownerRecord19, unsigned char*, 0x4C) = 0x18U;
                Level46_83760Field(ownerRecord19, signed char*, 0x47) = 0;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                Level46_83760Field(ownerRecord19, int*, 0x14) =
                    (int)(Level46_83760Field(ownerRecord19, int*, 0x14) + 0x32);
                argumentWord4 = 60;
                argumentWord5 = 100;
            sampleOriginalCountdown1110:
                rawWord2 = Level46_83760RandBetweenView1(argumentWord4, argumentWord5);
                Level46_83760Field(privateThenOwnerPosition20, short*, 2) = rawWord2;
                return;
            case 40:
                retainedCounterPrivateVectorOrSpeed17 = privateThenOwnerPosition20 + 0xC;
                Level46_83760CopyVectorView1(retainedCounterPrivateVectorOrSpeed17,
                                             ownerRecord19 + 0xC);
                argumentWord4 = 297;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$5");
                rawWord2 = (int)Level46_83760DataSpawnMobyView1;
                argumentWord5 = (int)ownerRecord19;
                Level46_83760Field(privateThenOwnerPosition20, short*, 2) = 0;
                temporaryWord13 = ((int (*)())rawWord2)(argumentWord4, argumentWord5);
                if (temporaryWord13 != 0) {
                    temporaryWord17 = Level46_83760Field(temporaryWord13, void**, 0);
                    Level46_83760Field(temporaryWord17, short*, 0) =
                        (short)Level46_83760Field(privateThenOwnerPosition20, unsigned char*, 0);
                    rawWord2 = Level46_83760Field(privateThenOwnerPosition20, int*, 4);
                    Level46_83760Field(temporaryWord17, short*, 2) = 0;
                    Level46_83760Field(temporaryWord17, int*, 4) = rawWord2;
                    Level46_83760Field(temporaryWord17, int*, 8) =
                        (int)Level46_83760Field(privateThenOwnerPosition20, int*, 8);
                    Level46_83760CopyVectorView1(temporaryWord17 + 0xC,
                                                 retainedCounterPrivateVectorOrSpeed17);
                    Level46_83760Field(temporaryWord13, signed char*, 0x48) = 5;
                    Level46_83760Field(temporaryWord13, signed char*, 0x49) = 0;
                    Level46_83760Field(temporaryWord13, signed char*, 0x4C) = 0x18;
                    Level46_83760SetMobyAnimationView1(temporaryWord13, 5);
                }
                goto removeOriginalOwner1524;
            case 30:
                Level46_83760Field(ownerRecord19, signed char*, 0x41) = 0;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x4C) = 0U;
                Level46_83760Field(ownerRecord19, signed char*, 0x4D) = 0;
                Level46_83760Field(ownerRecord19, int*, 8) = 0;
                return;
            case 31:
                retainedCounterPrivateVectorOrSpeed17 =
                    Level46_83760Field(ownerRecord19, void**, 0);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                rawWord2 = Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4);
                originalFrame.sp90 = rawWord2;
                originalFrame.sp94 = 0;
                originalFrame.sp98 = 0;
                Level46_83760TransformVectorByBasisView1(ownerRecord19 + 0x20, &originalFrame.sp90,
                                                         &originalFrame.sp90);
                temporaryWord2 = ownerRecord19 + 0xC;
                Level46_83760AddVectorView1(temporaryWord2, temporaryWord2, &originalFrame.sp90);
                temporaryWord14 = (unsigned short)Level46_83760Field(
                                      retainedCounterPrivateVectorOrSpeed17, short*, 4) -
                                  0x10;
                Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4) =
                    temporaryWord14;
                if ((temporaryWord14 << 0x10) <= 0) {
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x20U;
                    Level46_83760RequestMobyAnimationView1(ownerRecord19, 1);
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4) = 0x28;
                    return;
                }
                break;
            case 32:
                retainedCounterPrivateVectorOrSpeed17 =
                    Level46_83760Field(ownerRecord19, void**, 0);
                Level46_83760RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                rawWord2 = Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 2);
                originalFrame.spA0 = rawWord2;
                originalFrame.spA4 = 0;
                originalFrame.spA8 = 0;
                Level46_83760TransformVectorByBasisView1(ownerRecord19 + 0x20, &originalFrame.spA0,
                                                         &originalFrame.spA0);
                temporaryWord3 = ownerRecord19 + 0xC;
                Level46_83760AddVectorView1(temporaryWord3, temporaryWord3, &originalFrame.spA0);
                rawWord2 = Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4);
                MATCHING_KEEP(rawWord2);
                rawWord3 = rawWord2;
                rawWord2 = rawWord2 < 100;
                if (rawWord2) {
                    rawWord2 = rawWord3 + 20;
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4) = rawWord2;
                    __asm__ volatile(
                        ""
                        : "=r"(rawWord2)
                        : "0"(rawWord2),
                          "m"(Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4))
                        : "memory");
                    rawWord2 = (rawWord2 << 16) >> 16;
                    if (rawWord2 >= 101)
                        Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 4) = 100;
                }
                retainedColorResultDistanceOrPlayerView18 =
                    Level46_83760Field(ownerRecord19, unsigned char*, 0x45);
                if ((int)retainedColorResultDistanceOrPlayerView18 >= 0x81) {
                    retainedColorResultDistanceOrPlayerView18 -= 0x100;
                }
                Level46_83760CopyVectorView1(
                    &originalFrame.spB0,
                    Level46_83760Field(
                        Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, void**, 0xC),
                        int*, 0xC) +
                        (Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, unsigned char*,
                                            6) *
                         0x10));
                privateThenOwnerPosition20 = ownerRecord19 + 0xC;
                originalFrame.spB8 -=
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, short*, 0);
                rawWord3 =
                    Level46_83760PlanarHeadingLookupView1(
                        Level46_83760ApproximatePlanarDistanceView1(privateThenOwnerPosition20,
                                                                    &originalFrame.spB0),
                        originalFrame.spB8 - Level46_83760Field(ownerRecord19, int*, 0x14), 0) -
                    retainedColorResultDistanceOrPlayerView18;
                rawWord2 = rawWord3 < 129;
                if (!rawWord2) {
                    rawWord3 -= 256;
                    MATCHING_KEEP(rawWord3);
                }
                rawWord2 = rawWord3 < 9;
                if (!rawWord2) {
                    rawWord3 = 8;
                    MATCHING_KEEP(rawWord3);
                }
                rawWord2 = rawWord3 < -8;
                if (rawWord2)
                    rawWord3 = -8;
                rawWord2 = Level46_83760Field(ownerRecord19, unsigned char*, 69);
                rawWord2 += rawWord3;
                Level46_83760Field(ownerRecord19, unsigned char*, 69) = rawWord2;
                Level46_83760Field(
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, void**, 0xC), short*,
                    2) = (short)Level46_83760Field(retainedCounterPrivateVectorOrSpeed17,
                                                   unsigned char*, 6);
                Level46_83760Field(
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, void**, 0xC), short*,
                    0xA) =
                    (short)(signed char)Level46_83760Field(retainedCounterPrivateVectorOrSpeed17,
                                                           unsigned char*, 7);
                temporaryWord18 =
                    Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, void**, 0xC);
                temporaryWord5 = (Level46_83760Field(temporaryWord18, short*, 2) * 0x10) +
                                 Level46_83760Field(temporaryWord18, int*, 0xC);
                Level46_83760TurnMobyTowardHeadingView1(
                    ownerRecord19,
                    Level46_83760PlanarHeadingLookupView1(
                        Level46_83760Field(temporaryWord5, int*, 0) -
                            Level46_83760Field(ownerRecord19, int*, 0xC),
                        Level46_83760Field(temporaryWord5, int*, 4) -
                            Level46_83760Field(ownerRecord19, int*, 0x10),
                        0),
                    4, 1, 0, 0);
                rawWord2 = Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, int*, 12);
                rawWord3 = Level46_83760Field(rawWord2, unsigned short*, 2);
                MATCHING_KEEP(retainedCounterPrivateVectorOrSpeed17);
                rawWord2 = Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, int*, 12);
                MATCHING_OBSERVE_VOLATILE(rawWord3);
                Level46_83760Field(retainedCounterPrivateVectorOrSpeed17, unsigned char*, 6) =
                    rawWord3;
                argumentWord4 = privateThenOwnerPosition20;
                argumentWord5 = Level46_83760Field(rawWord2, short*, 2);
                rawWord2 = Level46_83760Field(rawWord2, int*, 12);
                argumentWord5 *= 16;
                argumentWord5 = rawWord2 + argumentWord5;
                if (Level46_83760ApproximatePlanarDistanceView1(argumentWord4, argumentWord5) <
                    128) {
                    Level46_83760Field(ownerRecord19, unsigned char*, 72) = 33;
                    return;
                }
                break;
            case 33:
                retainedRecordVectorOrPlayerView16 = Level46_83760Field(ownerRecord19, void**, 0);
                temporaryWord6 =
                    Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 0x10) - 1;
                Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 0x10) = temporaryWord6;
                if (temporaryWord6 <= 0) {
                    argumentWord5 = Level46_83760Data6C550View1;
                    argumentWord4 = Level46_83760Field(argumentWord5, unsigned char*, 72);
                    __asm__ volatile("" ::: "$2", "memory");
                    rawWord2 = 255;
                    MATCHING_KEEP(argumentWord4);
                    rawWord3 = argumentWord4 & 255;
                    if (rawWord3 == rawWord2) {
                        rawWord2 = 12;
                        goto resetOriginalRecordCounter1339;
                    }
                    recordClassSelector9 = 297;
                    recordStateSelector8 = 5;
                    argumentWord7 = 255;
                    rawWord3 = argumentWord5 + 72;
                searchOriginalRecord1321:
                    rawWord2 = Level46_83760Field(rawWord3, short*, -18);
                    if (rawWord2 != recordClassSelector9)
                        goto originalNextRecord1333;
                    if (argumentWord4 != recordStateSelector8)
                        goto originalNextRecord1333;
                    argumentWord6 = Level46_83760Field(argumentWord5, int*, 0);
                    rawWord2 = Level46_83760Field(argumentWord6, short*, 2);
                    if (!rawWord2)
                        goto originalFoundRecord1395;
                originalNextRecord1333:
                    rawWord3 += 88;
                    argumentWord4 = Level46_83760Field(rawWord3, unsigned char*, 0);
                    argumentWord5 += 88;
                    if (argumentWord4 != argumentWord7)
                        goto searchOriginalRecord1321;
                    rawWord2 = 12;
                resetOriginalRecordCounter1339:
                    Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 16) = rawWord2;
                }
            updateOriginalRecordTurn1340:
                rawWord2 = Level46_83760Field(ownerRecord19, unsigned char*, 69);
                if (rawWord2) {
                    rawWord3 = rawWord2;
                    MATCHING_KEEP(rawWord3);
                    if (rawWord3 >= 129) {
                        if (rawWord3 < 252) {
                            rawWord3 += 4;
                            Level46_83760Field(ownerRecord19, unsigned char*, 69) = rawWord3;
                        } else
                            goto originalTurnClear1340;
                    } else {
                        rawWord2 = rawWord3 < 5;
                        rawWord3 -= 4;
                        if (rawWord2) {
                        originalTurnClear1340:
                            rawWord3 = 0;
                        }
                        Level46_83760Field(ownerRecord19, unsigned char*, 69) = rawWord3;
                    }
                }
                Level46_83760Field(
                    Level46_83760Field(retainedRecordVectorOrPlayerView16, void**, 0xC),
                    unsigned short*, 2) =
                    (unsigned short)Level46_83760Field(retainedRecordVectorOrPlayerView16,
                                                       unsigned char*, 6);
                Level46_83760Field(
                    Level46_83760Field(retainedRecordVectorOrPlayerView16, void**, 0xC), short*,
                    0xA) =
                    (short)(signed char)Level46_83760Field(retainedRecordVectorOrPlayerView16,
                                                           unsigned char*, 7);
                Level46_83760Call35A80View1(
                    ownerRecord19,
                    Level46_83760Field(retainedRecordVectorOrPlayerView16, void**, 0xC), 0x78,
                    Level46_83760Field(retainedRecordVectorOrPlayerView16, short*, 2), 0, 5, 0x40,
                    0);
                Level46_83760Field(retainedRecordVectorOrPlayerView16, unsigned char*, 6) =
                    (unsigned char)Level46_83760Field(
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, void**, 0xC),
                        unsigned short*, 2);
                return;
            case 36:
                temporaryWord19 = Level46_83760Field(ownerRecord19, void**, 0);
                Level46_83760Field(temporaryWord19, short*, 0) = 1;
                Level46_83760Field(temporaryWord19, int*, 0x1C) = 0xC;
                Level46_83760Field(temporaryWord19, short*, 2) = 0;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x4A) = 0xFF;
                Level46_83760Field(ownerRecord19, signed char*, 0x41) = 0;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x4C) = 0U;
                Level46_83760Field(ownerRecord19, signed char*, 0x4D) = 0;
                Level46_83760Field(ownerRecord19, unsigned char*, 0x48) = 0x25U;
                Level46_83760Field(ownerRecord19, int*, 8) = 0;
                return;
            originalFoundRecord1395:
                argumentWord4 = Level46_83760Data6C550View1;
                MATCHING_KEEP(argumentWord4);
                argumentWord4 = (int)ownerRecord19 - argumentWord4;
                rawWord3 = (unsigned)argumentWord4 << 5;
                rawWord3 -= argumentWord4;
                rawWord3 = (unsigned)rawWord3 << 5;
                rawWord3 += argumentWord4;
                rawWord2 = (unsigned)rawWord3 << 3;
                rawWord3 += rawWord2;
                rawWord2 = (unsigned)rawWord3 << 15;
                rawWord2 -= rawWord3;
                rawWord2 = (unsigned)rawWord2 << 2;
                rawWord2 += argumentWord4;
                rawWord2 = 0u - rawWord2;
                rawWord2 >>= 3;
                Level46_83760Field(argumentWord6, short*, 2) = rawWord2;
                rawWord3 = Level46_83760Field(ownerRecord19, int*, 0);
                rawWord2 = 23;
                Level46_83760Field(ownerRecord19, unsigned char*, 72) = rawWord2;
                rawWord2 = Level46_83760Field(argumentWord6, unsigned short*, 0);
                Level46_83760Field(rawWord3, unsigned char*, 0) = rawWord2;
                Level46_83760Field(rawWord3, unsigned char*, 1) = 0;
                Level46_83760Field(rawWord3, short*, 2) = 0;
                rawWord2 = Level46_83760Field(argumentWord6, int*, 4);
                argumentWord5 = argumentWord6 + 12;
                Level46_83760Field(rawWord3, int*, 4) = rawWord2;
                rawWord2 = Level46_83760Field(argumentWord6, int*, 8);
                argumentWord4 = rawWord3 + 12;
                Level46_83760Field(rawWord3, int*, 8) = rawWord2;
                Level46_83760CopyVectorView1(argumentWord4, argumentWord5);
                return;
            case 37:
                retainedColorResultDistanceOrPlayerView18 =
                    Level46_83760Field(ownerRecord19, void**, 0);
                if ((Level46_83760Field(retainedColorResultDistanceOrPlayerView18, short*, 0) ==
                     0) &&
                    (Level46_83760CountTimerDownView1(retainedColorResultDistanceOrPlayerView18 + 2,
                                                      2) != 0)) {
                    temporaryWord7 = Level46_83760DataSpawnMobyView1(0x129, ownerRecord19);
                    if (temporaryWord7 != 0) {
                        retainedRecordVectorOrPlayerView16 =
                            Level46_83760Field(temporaryWord7, void**, 0);
                        Level46_83760PlayMobySoundEventView1(ownerRecord19, 2, 0);
                        Level46_83760Field(temporaryWord7, signed char*, 0x48) = 0x1F;
                        Level46_83760Field(temporaryWord7, signed char*, 0x4C) = 0x20;
                        retainedOriginalSpawnByte48 = 48;
                        Level46_83760Field(temporaryWord7, unsigned char*, 0x4A) =
                            retainedOriginalSpawnByte48;
                        Level46_83760Field(temporaryWord7, signed char*, 0x47) = 0;
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, signed char*, 6) = 1;
                        rawWord3 = Level46_83760Field(privateThenOwnerPosition20, int*, 8);
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, signed char*, 7) = 1;
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 8) = rawWord3;
                        rawWord3 =
                            Level46_83760Field(retainedColorResultDistanceOrPlayerView18, int*, 32);
                        rawWord2 = 400;
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, short*, 4) =
                            rawWord2;
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 12) = rawWord3;
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, short*, 2) =
                            (short)((Level46_83760Field(retainedColorResultDistanceOrPlayerView18,
                                                        int*, 0x1C) *
                                     0xA) +
                                    0x32);
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, short*, 0) =
                            (short)((0xC -
                                     Level46_83760Field(retainedColorResultDistanceOrPlayerView18,
                                                        int*, 0x1C)) *
                                    0x12C);
                        Level46_83760Field(retainedRecordVectorOrPlayerView16, int*, 0x10) =
                            (int)(0x18 -
                                  Level46_83760Field(retainedColorResultDistanceOrPlayerView18,
                                                     int*, 0x1C));
                        if (!(Level46_83760Field(retainedColorResultDistanceOrPlayerView18, int*,
                                                 0x1C) &
                              1)) {
                            temporaryWord20 =
                                Level46_83760Field(retainedRecordVectorOrPlayerView16, void**, 0xC);
                            temporaryWord8 =
                                Level46_83760Field(temporaryWord20, unsigned char*, 0) - 1;
                            Level46_83760Field(retainedRecordVectorOrPlayerView16, signed char*,
                                               6) = temporaryWord8;
                            Level46_83760Field(temporaryWord20, short*, 2) =
                                (short)(temporaryWord8 & 0xFF);
                            Level46_83760Field(retainedRecordVectorOrPlayerView16, signed char*,
                                               7) = -1;
                            Level46_83760Field(
                                Level46_83760Field(retainedRecordVectorOrPlayerView16, void**, 0xC),
                                short*, 0xA) = -1;
                        }
                        Level46_83760RequestMobyAnimationView1(temporaryWord7, 3);
                        Level46_83760Field(temporaryWord7, unsigned char*, 0x45) =
                            retainedOriginalSpawnByte48;
                        rawWord2 = Level46_83760RandBetweenView1(0, 32);
                        rawWord3 = Level46_83760Field(ownerRecord19, unsigned char*, 70);
                        rawWord2 -= 16;
                        rawWord3 += rawWord2;
                        Level46_83760Field(temporaryWord7, unsigned char*, 70) = rawWord3;
                        Level46_83760Field(temporaryWord7, unsigned char*, 0x44) =
                            (unsigned char)Level46_83760Field(ownerRecord19, unsigned char*, 0x44);
                        Level46_83760Field(retainedColorResultDistanceOrPlayerView18, short*, 2) =
                            0x1E;
                        temporaryWord9 =
                            Level46_83760Field(retainedColorResultDistanceOrPlayerView18, int*,
                                               0x1C) -
                            1;
                        Level46_83760Field(retainedColorResultDistanceOrPlayerView18, int*, 0x1C) =
                            temporaryWord9;
                        if (temporaryWord9 <= 0) {
                            goto removeOriginalOwner1524;
                        }
                    }
                }
                break;
        }
    } else {
        return;
    }
    return;
removeOriginalOwner1524:
    Level46_83760DeleteMobyView1(ownerRecord19);
    return;
}
#undef Level46_83760Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level46:
 * 80084F60 complete323 instructions and7 plus padding original dispatch words, sibling4507.
 * Verified23 C supplies the identical raw player/table/spawn call chain.
 * Offsets and original integer arithmetic only; units, sound meanings and
 * cadence unresolved. Require every native/linked word and retail hash. */
#define Actor46Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char* Actor46Pool __asm__("D_8006C550");
extern unsigned char* Actor46Descriptor __asm__("D_8006C654");
extern unsigned char Actor46Global11 __asm__("D_80066BC8 + 11");
extern short Actor46GlobalHalf __asm__("D_800719DC");
extern unsigned char Actor46Player[] __asm__("D_80070328");
extern unsigned char Actor46Heading __asm__("D_80070328 + 0xE");
extern short Actor46Cos[] __asm__("D_80065920");
extern short Actor46Sin[] __asm__("D_800658A0");
extern unsigned char Actor46Table[] __asm__("D_8006C7F8");
int Actor46RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor46CopyVector() __asm__("func_8004F178");
int Actor46Helper35DDC() __asm__("func_80035DDC");
int Actor46SetMobyAnimation() __asm__("func_80034F80");
int Actor46Helper3B7B4() __asm__("func_8003B7B4");
int Actor46RandBetween() __asm__("func_8003636C");
int Actor46CountTimerDown() __asm__("func_800359A4");
int Actor46DeleteMoby() __asm__("func_80055B18");
int Actor46PlaySound() __asm__("PlaySound");
extern unsigned char* (*Actor46SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern unsigned char* (*Actor46SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
extern int (*Actor46Callback)() __asm__("unk_ovlheader_80074324");
extern unsigned char Actor46TableD[] __asm__("D_8006D088");
int Actor46Helper35EE0() __asm__("func_80035EE0");
int Actor46Helper3BB10() __asm__("func_8003BB10");
void func_level_46_80084F60(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    int position[4];
    int velocity[4];
    int extraVelocity[4];
    register int* tag __asm__("$18");
    register unsigned char* ownerPosition __asm__("$20");
    register int heading __asm__("$19");
    register unsigned char* child __asm__("$16");
    register unsigned char* spawn __asm__("$4");
    register int sample __asm__("$4");
    register int selector __asm__("$2");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register int work2 __asm__("$2");
    register int timerMode __asm__("$5");
    MATCHING_KEEP(owner);
    tag = Actor46Field(owner, int**, 0);
    Actor46Field(owner, unsigned char*, 0x4F) = 45;
    if (Actor46Field(owner, unsigned char*, 0x48) < 2 && Actor46Field(owner, int*, 0x18)) {
        if (Actor46Field(owner, unsigned char*, 0x49) == 1) {
            Actor46Field(owner, int*, 0x18) = 0;
            return;
        }
        {
            register int index __asm__("$3") = tag[1];
            MATCHING_KEEP(index);
            if (index >= 0) {
                register void* target __asm__("$3");
                register int offset __asm__("$2") = index * 11;
                MATCHING_KEEP(offset);
                target = Actor46Pool;
                MATCHING_KEEP(target);
                call4 = target + offset * 8;
                MATCHING_KEEP(call4);
                if (Actor46Field(call4, unsigned char*, 0x48) != 2)
                    Actor46Field(call4, unsigned char*, 0x48) = 2;
            }
        }
        Actor46RefreshMobySpatialGridAndBasis(owner, 4);
        ownerPosition = owner + 12;
        Actor46CopyVector(position, ownerPosition);
        Actor46Helper35DDC(owner, 400, 0, 0, 0);
        {
            register unsigned char* (*producer)(int, void*)__asm__("$3");
            call4 = (void*)341;
            call5 = owner;
            MATCHING_KEEP2(call4, call5);
            work2 = Actor46Field(owner, int*, 20);
            MATCHING_KEEP(work2);
            producer = Actor46SpawnMoby;
            MATCHING_KEEP(producer);
            Actor46Field(owner, int*, 20) = work2 + 500;
            child = producer((int)call4, call5);
        }
        MATCHING_KEEP(child);
        if (child) {
            *Actor46Field(child, int**, 0) = 15;
            Actor46Field(child, unsigned char*, 0x48) = 3;
            Actor46Field(child, unsigned char*, 0x41) = 0;
            Actor46Field(child, unsigned char*, 0x4C) = 0;
            Actor46Field(child, unsigned char*, 0x4D) = 0;
        }
        child = Actor46SpawnMoby(341, owner);
        MATCHING_KEEP(child);
        if (child) {
            *Actor46Field(child, int**, 0) = 30;
            Actor46Field(child, unsigned char*, 0x48) = 4;
            Actor46Field(child, unsigned char*, 0x41) = 0;
            Actor46Field(child, unsigned char*, 0x4C) = 0;
            Actor46Field(child, unsigned char*, 0x4D) = 0;
        }
        Actor46Callback(owner, 6);
        {
            register int work3 __asm__("$3") = Actor46Field(owner, unsigned char*, 0x46);
            MATCHING_KEEP(work3);
            heading = work3 & 255;
            if (!Actor46Field(owner, unsigned char*, 0x48)) {
                work2 = work3 + 224;
                MATCHING_KEEP(work2);
                Actor46Field(owner, unsigned char*, 0x46) = work2;
            }
        }
        child = Actor46SpawnMoby(84, owner);
        if (child) {
            Actor46Field(child, unsigned char*, 0x4F) = 45;
            Actor46Field(child, unsigned char*, 0x4C) = 63;
            Actor46Field(child, unsigned char*, 0x4A) = 255;
            Actor46SetMobyAnimation(child, Actor46RandBetween(0, 2));
        }
        Actor46Field(owner, unsigned char*, 0x46) = heading;
        Actor46Helper35EE0(owner, (Actor46Field(owner, unsigned char*, 0x45) + 128) & 255, 450, 0,
                           0, 0);
        child = Actor46SpawnMoby(341, owner);
        MATCHING_KEEP(child);
        if (child) {
            *Actor46Field(child, int**, 0) = 45;
            Actor46Field(child, unsigned char*, 0x48) = 5;
            Actor46Field(child, unsigned char*, 0x41) = 0;
            Actor46Field(child, unsigned char*, 0x4C) = 0;
            Actor46Field(child, unsigned char*, 0x4D) = 0;
        }
        if (Actor46Field(owner, unsigned char*, 0x48) == 1) {
            Actor46Field(owner, unsigned char*, 0x48) = 6;
            Actor46Helper3B7B4(owner + 0x48, 1, Actor46Table);
        }
        Actor46Helper3BB10(owner, 6, 0);
        Actor46Field(owner, unsigned char*, 0x48) = 2;
        Actor46CopyVector(ownerPosition, position);
        Actor46Field(owner, int*, 24) = 0;
        Actor46SetMobyAnimation(owner, 1);
    }
    switch (Actor46Field(owner, unsigned char*, 0x48)) {
        case 0:
        case 1:
            break;
        case 6:
            Actor46Field(owner, unsigned char*, 0x48) = 6;
            Actor46Helper3B7B4(owner + 0x48, 1, Actor46Table);
            Actor46Field(owner, unsigned char*, 0x48) = 2;
            Actor46SetMobyAnimation(owner, 1);
            break;
        case 2:
            if (Actor46Field(owner, unsigned char*, 0x49) == 2) {
                child = owner + 0x48;
                Actor46Field(owner, unsigned char*, 0x48) = 6;
                Actor46Helper3B7B4(child, 1, Actor46TableD);
                Actor46Helper3B7B4(child, 1, Actor46Table);
                Actor46Field(owner, unsigned char*, 0x49) = 0;
                Actor46Field(owner, unsigned char*, 0x48) = 2;
            }
            break;
        case 3:
            Actor46SpawnParticle(2, 71, owner + 12, 0);
            Actor46Field(owner, int*, 12) += 3 - Actor46RandBetween(0, 6);
            work2 = Actor46RandBetween(0, 6);
            call4 = tag;
            MATCHING_KEEP(call4);
            {
                register int word __asm__("$3") = Actor46Field(owner, int*, 16);
                MATCHING_KEEP_CLOBBER(word, "$5");
                timerMode = 4;
                MATCHING_KEEP(timerMode);
                word += 3;
                MATCHING_KEEP(word);
                word -= work2;
                MATCHING_KEEP(word);
                Actor46Field(owner, int*, 16) = word;
            }
            goto callTimer;
        case 4:
            velocity[0] = Actor46RandBetween(0, 20) - 10;
            velocity[1] = Actor46RandBetween(0, 20) - 10;
            velocity[2] = 20;
            spawn = Actor46SpawnParticle(1, 0, owner + 12, velocity);
            {
                if (!spawn)
                    goto calculateByte;
                work2 = tag[0];
                MATCHING_KEEP(work2);
                if (work2 >= 16) {
                    selector = 155;
                    goto assignByte;
                }
            calculateByte:
                MATCHING_BARRIER_VOLATILE("memory");
                {
                    register int product __asm__("$3");
                    work2 = tag[0];
                    MATCHING_KEEP(work2);
                    product = work2 * 10;
                    MATCHING_KEEP(product);
                    selector = -101 - product;
                }
            assignByte:
                Actor46Field(spawn, unsigned char*, 10) = selector;
            }
            goto timer;
        case 5:
            if (tag[0] < 30) {
                register unsigned char* particle3 __asm__("$3");
                extraVelocity[0] = Actor46RandBetween(0, 20) - 10;
                extraVelocity[1] = Actor46RandBetween(0, 20) - 10;
                extraVelocity[2] = 30;
                particle3 = Actor46SpawnParticle(1, 13, owner + 12, extraVelocity);
                MATCHING_KEEP(particle3);
                if (particle3)
                    Actor46Field(particle3, unsigned char*, 10) = 100;
            }

        timer:
            call4 = tag;
            timerMode = 4;
            MATCHING_KEEP2(call4, timerMode);
        callTimer:
            if (Actor46CountTimerDown(call4, timerMode))
                Actor46DeleteMoby(owner);
            break;
    }
}
#undef Actor46Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8008546C:295 instructions and six dispatch words, original4667.
 * Verified13/11/43 helper shapes reused only where original agrees. Raw fields;
 * units, helper contracts, cadence and runtime parity unresolved. */
#define B46Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* B46Active __asm__("D_8006E164");
extern int B46Type __asm__("D_8006E160");
extern unsigned char* B46Pool __asm__("D_8006C550");
extern unsigned char B46Player[] __asm__("D_80070328");
extern int B46Contact __asm__("D_8006C770");
int B46Helper36A68() __asm__("func_80036A68");
int B46CountTimerDown() __asm__("func_800359A4");
int B46RequestMobyAnimation() __asm__("func_80034F40");
int B46Helper55E84() __asm__("func_80055E84");
int B46Helper35194() __asm__("func_80035194");
int B46RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int B46Helper3BA00() __asm__("func_8003BA00");
int B46Helper369B8() __asm__("func_800369B8");
int B46DeleteMoby() __asm__("func_80055B18");
extern void* (*B46SpawnMoby)(int, void*)__asm__("SpawnMoby");
int B46TurnMobyTowardPlayer() __asm__("func_8003573C");
int B46ApproximatePlanarDistance() __asm__("func_8004F334");
int B46H38BF8() __asm__("func_80038BF8");
int B46H368A4() __asm__("func_800368A4");
int B46RandBetween() __asm__("func_8003636C");
int B46PlanarHeadingLookup() __asm__("func_8004E880");
int B46AbsoluteByteAngleDelta() __asm__("func_8004F264");
int B46H13E38() __asm__("func_80013E38");
int B46H1A358() __asm__("func_8001A358");
int B46CopyVector() __asm__("func_8004F178");
int B46TransformVectorByBasis() __asm__("func_8004ED6C");
extern unsigned char B46Position[] __asm__("D_8006E020");
extern int B46Y __asm__("D_8006E024");
extern unsigned short B46Heading __asm__("D_8006E040");
extern int B46Mode __asm__("D_8006E344");
void func_level_46_8008546C(void* input) {
    int vector[4];
    register unsigned char* owner __asm__("$16") = input;
    register unsigned char* tag __asm__("$17");
    register unsigned char* child17 __asm__("$17");
    register unsigned char* position18 __asm__("$18");
    register unsigned char* childTag20 __asm__("$20");
    register int result19 __asm__("$19");
    register int value __asm__("$2");
    register int other __asm__("$3") = 5;
    register void* call4 __asm__("$4");
    register int heading4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    MATCHING_KEEP(owner);
    value = owner[72];
    tag = B46Field(owner, unsigned char**, 0);
    if (value != other && (B46Field(owner, int*, 24) & 0x60000)) {
        B46Helper36A68(input, 0, 0, 0);
        B46H38BF8(owner, tag + 12, 1, 5);
    }
    B46Field(tag, int*, 8) = B46H368A4(owner, B46Field(tag, int*, 8), 2);
    other = owner[72];
    B46Field(owner, int*, 24) = 0;
    switch (other) {
        case 0:
            if (!B46CountTimerDown(tag + 4, 4))
                goto done;
            value = B46ApproximatePlanarDistance(owner + 12, B46Player);
            call4 = 0;
            if (value >= 12288)
                goto done;
            value = B46RandBetween(call4, 60);
            call4 = owner;
            arg5 = 2;
            B46Field(tag, int*, 4) = value + 90;
            ((unsigned char*)call4)[72] = 2;
            B46RequestMobyAnimation(call4, arg5);
            break;
        case 2:
            if (B46Contact) {
                owner[72] = 3;
                B46RequestMobyAnimation(owner, 3);
            }
            break;
        case 3:
            B46TurnMobyTowardPlayer(owner, 2, 0, 0);
            if (!B46CountTimerDown(tag + 4, 4))
                goto done;
            position18 = B46Position;
            value =
                B46PlanarHeadingLookup(B46Field(owner, int*, 12) - B46Field(position18, int*, 0),
                                       B46Field(owner, int*, 16) - B46Y, 0);
            heading4 = B46Heading;
            MATCHING_KEEP(heading4);
            arg5 = value;
            heading4 = (heading4 << 16) >> 20;
            if (B46AbsoluteByteAngleDelta(heading4, arg5) >= 21)
                goto reset3;
            value =
                B46PlanarHeadingLookup(B46Field(B46Player, int*, 0) - B46Field(owner, int*, 12),
                                       B46Field(B46Player, int*, 4) - B46Field(owner, int*, 16), 0);
            value = B46AbsoluteByteAngleDelta(value, owner[70]);
            call4 = owner + 12;
            if (value >= 11)
                goto reset3;
            value = B46H13E38(call4, position18, 0);
            call4 = owner;
            if (value)
                goto success3;
        reset3:
            owner[72] = 0;
            B46RequestMobyAnimation(owner, 0);
            B46Field(tag, int*, 4) = B46RandBetween(0, 80) + 120;
            owner[64] = 240;
            goto done;
        success3:
            B46RequestMobyAnimation(call4, 4);
            owner[64] = 160;
            owner[72] = 4;
            goto done;
        case 4:
            call4 = (void*)B46Helper55E84(owner);
            if (B46Mode == 1)
                goto contact4;
            if (owner[73])
                goto contact4;
            if (owner[60] != 4)
                goto contact4;
            value = (int)call4 - 10;
            MATCHING_KEEP(value);
            if ((unsigned int)value >= 7)
                goto contact4;
            value =
                B46PlanarHeadingLookup(B46Field(owner, int*, 12) - B46Field(B46Position, int*, 0),
                                       B46Field(owner, int*, 16) - B46Y, 0);
            heading4 = B46Heading;
            MATCHING_KEEP(heading4);
            arg5 = value;
            heading4 = (heading4 << 16) >> 20;
            value = B46AbsoluteByteAngleDelta(heading4, arg5);
            call4 = (void*)197;
            if (value >= 20)
                goto contact4;
            child17 = B46SpawnMoby((int)call4, owner);
            MATCHING_KEEP(child17);
            call4 = child17;
            if (child17) {
                value = owner[70];
                childTag20 = B46Field(child17, unsigned char**, 0);
                child17[70] = value;
                B46TurnMobyTowardPlayer(call4, 2, 0, 0);
                position18 = B46Player;
                result19 = B46H1A358(position18, 4096);
                call4 = vector;
                if (result19) {
                    B46CopyVector(call4, position18);
                    call4 = child17 + 12;
                    arg5 = (int)vector;
                    MATCHING_KEEP(arg5);
                    value = result19 + 400;
                    MATCHING_KEEP(value);
                    vector[2] = value;
                    value = B46ApproximatePlanarDistance(call4, (void*)arg5);
                    call4 = (void*)value;
                    value = vector[2];
                } else {
                    value = B46ApproximatePlanarDistance(child17 + 12, position18);
                    call4 = (void*)value;
                    value = B46Field(B46Player, int*, 8);
                }
                value = B46PlanarHeadingLookup((int)call4, value - B46Field(child17, int*, 20), 0);
                B46Field(child17, volatile unsigned char*, 69) = value;
                __asm__ volatile("" ::: "$4", "memory");
                call4 = child17;
                arg5 = 4;
                MATCHING_KEEP(arg5);
                value = 300;
                B46Field(childTag20, short*, 12) = value;
                B46RefreshMobySpatialGridAndBasis(call4, arg5);
                vector[0] = B46Field(childTag20, short*, 12);
                vector[1] = 0;
                vector[2] = 0;
                B46TransformVectorByBasis(child17 + 32, vector, childTag20);
            }
            owner[73] = 1;
            goto done;
        contact4:
            if (!B46Contact)
                goto done;
            if (B46ApproximatePlanarDistance(owner + 12, B46Player) < 12288) {
                owner[72] = 3;
                call4 = owner;
                arg5 = 3;
            } else {
                owner[72] = 0;
                call4 = owner;
                arg5 = 0;
            }
            MATCHING_OBSERVE2(call4, arg5);
            B46RequestMobyAnimation(call4, arg5);
            B46Field(tag, int*, 4) = B46RandBetween(0, 80) + 120;
            owner[73] = 0;
            break;
        case 5:
            value = B46Helper35194(owner, tag + 12);
            call4 = owner;
            if (value != 256)
                goto done;
            B46RefreshMobySpatialGridAndBasis(call4, 4);
            B46Helper3BA00(owner);
            B46Helper369B8(owner, 40);
            B46DeleteMoby(owner);
            break;
    }
done:;
}
#undef B46Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Level46_85908Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level46_85908MUL(a, b)                                       \
    do {                                                             \
        completeProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeProduct));                 \
    } while (0)
#define Level46_85908HI(dst)                                          \
    do {                                                              \
        int wholeCapturedHigh;                                        \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeProduct)); \
        (dst) = wholeCapturedHigh;                                    \
        Level46_85908Keep(dst);                                       \
    } while (0)
#define Level46_85908LO(dst)                                         \
    do {                                                             \
        int wholeCapturedLow;                                        \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeProduct)); \
        (dst) = wholeCapturedLow;                                    \
        Level46_85908Keep(dst);                                      \
    } while (0)
/* SCUS-94467 USA Rev0 original1280. AI generated; not human reviewed. Uninstalled,all original
 * words/targets/full hashes mandatory. */
#define Level46_85908Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level46_85908_func_80013AE4(void*, void*) __asm__("func_80013AE4");
void Level46_85908_func_80013D44(void*, int, void*, int) __asm__("func_80013D44");
int Level46_85908_func_8001830C(void*, void*, int, int, int) __asm__("func_8001830C");
int Level46_85908_func_8001A358(void*, int) __asm__("func_8001A358");
void Level46_85908RequestMobyAnimation(void*, int) __asm__("func_80034F40");
void Level46_85908SetMobyAnimation(void*, int) __asm__("func_80034F80");
int Level46_85908TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Level46_85908CountTimerDown(void*, int) __asm__("func_800359A4");
int Level46_85908_func_80035DDC(void*, int, int, int, int) __asm__("func_80035DDC");
int Level46_85908_func_80035EE0(void*, int, int, int, int, int) __asm__("func_80035EE0");
int Level46_85908RandBetween(int, int) __asm__("func_8003636C");
void Level46_85908_func_800369B8(int, int) __asm__("func_800369B8");
void Level46_85908_func_8003BA00(void*) __asm__("func_8003BA00");
int Level46_85908PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
void Level46_85908_func_8003BE70(int) __asm__("func_8003BE70");
int Level46_85908_func_8003BFC0(void*, int) __asm__("func_8003BFC0");
int Level46_85908PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Level46_85908TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
void Level46_85908CopyVector(void*, void*) __asm__("func_8004F178");
void Level46_85908AddVector(void*, void*, void*) __asm__("func_8004F194");
int Level46_85908AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level46_85908ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
void Level46_85908DeleteMoby(void*) __asm__("func_80055B18");
void Level46_85908RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
extern unsigned char Level46_85908_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level46_85908_D_80065920 __asm__("D_80065920");
extern int Level46_85908_D_8006C550 __asm__("D_8006C550");
extern int Level46_85908_D_8006C58C __asm__("D_8006C58C");
extern unsigned char Level46_85908_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level46_85908_D_8006E020 __asm__("D_8006E020");
extern int Level46_85908_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level46_85908_D_8006E040 __asm__("D_8006E040");
extern int Level46_85908_D_8006E044 __asm__("D_8006E044");
extern int Level46_85908_D_8006E048 __asm__("D_8006E048");
extern unsigned char Level46_85908_D_80070300 __asm__("D_80070300");
extern unsigned char Level46_85908_D_80070328 __asm__("D_80070328");
extern int Level46_85908_D_80071908 __asm__("D_80071908");
extern void* (*Level46_85908SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern void* (*Level46_85908SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_46_80085908(void* input) {
    register int saved16 __asm__("$16"), saved17 __asm__("$17"), owner __asm__("$18"),
        privateState __asm__("$19"), saved20 __asm__("$20"), saved21 __asm__("$21"),
        saved22 __asm__("$22"), saved23 __asm__("$23");
    register int result __asm__("$2"), scratch __asm__("$3"), argument0 __asm__("$4"),
        argument1 __asm__("$5"), argument2 __asm__("$6"), argument3 __asm__("$7"),
        temporary8 __asm__("$8"), temporary9 __asm__("$9"), temporary10 __asm__("$10");
    int angleFirst, angleSecond;
    int retainedPitch;
    long long completeProduct;
    int wrappedFirst, wrappedSecond;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84;
    } locals;

    int var_a1;

    int temp_a1;

    int temp_a1_10;

    int temp_a1_2;

    int temp_a1_4;

    int temp_a1_8;

    int temp_v0_14;

    int temp_v0_5;

    int temp_v1_10;

    int temp_v1_12;

    int temp_v1_14;

    int temp_v1_8;

    int temp_v1_2;

    int temp_v0;

    int temp_v0_17;

    int temp_v0_18;

    int temp_v0_19;

    int temp_v0_23;

    int temp_v0_2;

    int temp_v1_16;

    int temp_v1_18;

    int temp_v1_21;

    int temp_v1_4;

    int temp_v1_5;

    int temp_a0;

    int temp_a0_9;

    int temp_a1_12;

    int temp_a1_13;

    int temp_a1_14;

    int temp_a1_6;

    int temp_a1_7;

    int temp_v0_10;

    int temp_v0_9;

    int temp_v1_13;

    int temp_v1_17;

    int temp_v1_9;

    int var_v1;

    int var_v1_2;

    int var_v1_3;

    int var_v1_4;

    int var_v1_5;

    int var_v1_6;

    int var_v0_2;

    int var_v0_4;

    int temp_a0_2;

    int temp_a0_3;

    int temp_a0_4;

    int temp_a0_5;

    int temp_a0_6;

    int temp_a0_7;

    int temp_v0_3;

    int temp_v1;

    int temp_v1_19;

    int var_v0_3;

    int var_v0_5;

    int temp_a0_8;

    int temp_a1_11;

    int temp_a1_3;

    int temp_a1_5;

    int temp_a1_9;

    int temp_a3;

    int temp_a3_2;

    int temp_a3_3;

    int temp_a3_4;

    int temp_a3_5;

    int temp_v0_11;

    int temp_v0_12;

    int temp_v0_13;

    int temp_v0_15;

    int temp_v0_16;

    int temp_v0_20;

    int temp_v0_21;

    int temp_v0_6;

    int temp_v0_7;

    int temp_v0_8;

    int temp_v1_11;

    int temp_v1_15;

    int temp_v1_3;

    int temp_v1_6;

    /* Proposed inherited machine input, not an invented default:
     * existing locals.sp18 maps to original entrySP-160+24. Native state3/mode1
     * forwards these prior bytes to type13 before writing this word locally.
     * UNINSTALLED: per-site machine-input certificate and all gates required. */
    __asm__("" : "=m"(locals.sp18));
    owner = (int)input;
    Level46_85908Keep(owner);
    privateState = Level46_85908Field(owner, int*, 0);
    if (Level46_85908Field(owner, unsigned char*, 0x4C) == 0) {
        goto block_7;
    }
    if (Level46_85908Field((int)&Level46_85908_D_80070328, int*, 0x24C) != 4) {
        goto block_7;
    }
    if (Level46_85908AbsoluteByteAngleDelta(
            (int)(Level46_85908_D_8006E040 << 0x10) >> 0x14,
            Level46_85908PlanarHeadingLookup(
                Level46_85908Field(owner, int*, 0xC) - Level46_85908_D_8006E020,
                Level46_85908Field(owner, int*, 0x10) - Level46_85908_D_8006E024, 0)) >= 0x18) {
        goto block_5;
    }
    if (Level46_85908_D_8006E044 != 0x1F) {
        goto block_6;
    }
    Level46_85908Field(owner, unsigned char*, 0x4E) =
        (unsigned char)Level46_85908Field(owner, unsigned char*, 0x4C);
    goto block_7;
block_5:
block_6:
    Level46_85908Field(owner, unsigned char*, 0x4E) = 0x10U;
block_7:
    temp_v1 = Level46_85908Field(owner, unsigned char*, 0x48);
    if (temp_v1 == 1) {
        goto block_26;
    }
    if (temp_v1 == 0x1F) {
        goto block_26;
    }
    if (temp_v1 >= 0x1FU) {
        goto block_26;
    }
    temp_a0 = Level46_85908Field(owner, int*, 0x18);
    if (temp_a0 == 0) {
        goto block_26;
    }
    if (temp_v1 != 3) {
        goto block_15;
    }
    temp_v1_2 = Level46_85908Field(owner, int*, 0);
    temp_v0 = Level46_85908Field(temp_v1_2, int*, 0);
    if (temp_v0 == 0) {
        goto block_14;
    }
    Level46_85908Field(temp_v0, int*, 0x18) = temp_a0;
    Level46_85908Field(Level46_85908Field(temp_v1_2, int*, 0), unsigned char*, 0x51) =
        (unsigned char)Level46_85908Field(owner, unsigned char*, 0x51);
block_14:
    Level46_85908Field(owner, int*, 0x18) = 0;
    goto block_25;
block_15:
    if (Level46_85908_func_8003BFC0(owner, Level46_85908Field(privateState, int*, 0x20)) == 0) {
        goto block_17;
    }
    Level46_85908_func_8003BE70(Level46_85908Field(privateState, int*, 0x20));
    Level46_85908Field(privateState, int*, 0x20) = -1;
block_17:
    temp_v1_3 = (Level46_85908Field(privateState, int*, 0x18) * 0x58) + Level46_85908_D_8006C550;
    if (Level46_85908Field(temp_v1_3, unsigned char*, 0x48) & 0x80) {
        goto block_20;
    }
    argument0 = owner;
    if (Level46_85908Field(Level46_85908Field(temp_v1_3, int*, 0), int*, 0x1C) < 5) {
        goto block_23;
    }
block_20:
    Level46_85908Field(owner, unsigned char*, 0x48) = 0x22U;
    temp_v1_4 = Level46_85908Field(privateState, int*, 0);
    Level46_85908Field(privateState, short*, 8) = 0x3C;
    Level46_85908Field(privateState, unsigned short*, 0xE) = 0U;
    if (temp_v1_4 == 0) {
        goto block_22;
    }
    Level46_85908Field(temp_v1_4, signed char*, 0x49) = 1;
block_22:
    Level46_85908Field((int)&Level46_85908_D_80070328, int*, 0x20C) = 0x10000002;
    return;
block_23:
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argument0, "$5");
    argument1 = 1;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argument1, "$2");
    result = 350;
    Level46_85908Field(privateState, short*, 12) = result;
    result = Level46_85908Field(owner, unsigned char*, 81);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(result, "$16");
    saved16 = 180;
    Level46_85908Field(privateState, short*, 8) = saved16;
    __asm__("" : "=r"(result) : "0"(result), "m"(Level46_85908Field(privateState, short*, 8)));
    Level46_85908Field(privateState, short*, 10) = result;
    result = 1;
    Level46_85908Field(owner, unsigned char*, 68) = 0;
    Level46_85908Field(owner, unsigned char*, 69) = 0;
    Level46_85908Field(owner, int*, 84) = 0;
    Level46_85908Field(owner, unsigned char*, 72) = result;
    Level46_85908RequestMobyAnimation(argument0, argument1);
    scratch = Level46_85908Field(privateState, int*, 0);
    result = 300;
    if (!scratch)
        goto block_25;
    scratch = Level46_85908Field(scratch, int*, 0);
    Level46_85908Field(scratch, short*, 12) = result;
    result = Level46_85908Field(owner, unsigned char*, 81);
    Level46_85908Field(scratch, short*, 8) = saved16;
    result = (result + 128) & 255;
    Level46_85908Field(scratch, short*, 10) = result;
    result = Level46_85908Field(privateState, int*, 0);
    Level46_85908Field(result, unsigned char*, 68) = 0;
    result = Level46_85908Field(privateState, int*, 0);
    Level46_85908Field(result, unsigned char*, 69) = 0;
    scratch = Level46_85908Field(privateState, int*, 0);
    result = 31;
    Level46_85908Field(scratch, unsigned char*, 72) = result;
block_25:
block_26:
    scratch = Level46_85908Field(owner, unsigned char*, 72);
    Level46_85908Keep(scratch);
    if ((unsigned int)scratch >= 36)
        goto block_171;
    switch (scratch) {
        case 30:
            temp_v0_2 = Level46_85908SpawnMoby(0x27D, owner);
            if (temp_v0_2 == 0) {
                goto block_30;
            }
            Level46_85908Field(Level46_85908Field(temp_v0_2, int*, 0), int*, 0) = owner;
            Level46_85908Field(privateState, int*, 0) = temp_v0_2;
            Level46_85908Field(temp_v0_2, signed char*, 0x48) = 3;
            Level46_85908SetMobyAnimation(temp_v0_2, 3);
            Level46_85908Field(temp_v0_2, int*, 0x14) =
                (int)(Level46_85908Field(temp_v0_2, int*, 0x14) - 0x12C);
            Level46_85908Field(temp_v0_2, unsigned char*, 0x46) =
                (unsigned char)Level46_85908Field(owner, unsigned char*, 0x46);
        block_30:
            argument0 = owner;
            result = Level46_85908Field(argument0, int*, 20);
            argument2 = 2;
            Level46_85908Field(argument0, unsigned char*, 71) = argument2;
            result -= 200;
            Level46_85908Field(argument0, int*, 20) = result;
            scratch = Level46_85908Field(privateState, int*, 4);
            result = Level46_85908Field(privateState, unsigned short*, 14);
            argument1 = 2;
            Level46_85908Field(scratch, short*, 2) = result;
            scratch = Level46_85908Field(privateState, int*, 4);
            result = 1;
            Level46_85908Field(scratch, short*, 10) = result;
            Level46_85908Field(privateState, short*, 12) = 0;
            Level46_85908Field(argument0, unsigned char*, 72) = argument2;
            Level46_85908RequestMobyAnimation(argument0, argument1);
            return;
        case 1:
        case 31:
            Level46_85908Field(owner, int*, 0x14) =
                (int)(Level46_85908Field(owner, int*, 0x14) +
                      Level46_85908Field(privateState, short*, 0xC));
            Level46_85908Field(privateState, short*, 0xC) =
                (short)((unsigned short)Level46_85908Field(privateState, short*, 0xC) - 0x10);
            Level46_85908_func_80035EE0(owner, Level46_85908Field(privateState, short*, 0xA), 0x64,
                                        0, 0, 0);
            if (Level46_85908CountTimerDown(privateState + 8, 2) != 0) {
                goto block_34;
            }
            if (Level46_85908Field(privateState, short*, 0xC) >= 0) {
                goto block_38;
            }
            if (Level46_85908_func_8001A358(owner + 0xC, 0x258) == 0) {
                goto block_38;
            }
        block_34:
            if (Level46_85908Field(owner, unsigned char*, 0x48) != 0x1F) {
                goto block_37;
            }
            Level46_85908PlayMobySoundEvent(owner, 0, 0);
        block_36:
            Level46_85908_func_800369B8(owner, 0x28);
            goto block_147;
        block_37:
            Level46_85908RefreshMobySpatialGridAndBasis(owner, 4);
            Level46_85908_func_8003BA00(owner);
            goto block_36;
        block_38:
            if (Level46_85908Field(owner, unsigned char*, 0x48) == 1) {
                goto block_171;
            }
            Level46_85908Field(owner, unsigned char*, 0x45) =
                (unsigned char)(Level46_85908Field(owner, unsigned char*, 0x45) + 6);
            Level46_85908Field(owner, unsigned char*, 0x44) =
                (unsigned char)(Level46_85908Field(owner, unsigned char*, 0x44) + 1);
            return;
        case 20:
            temp_a1 = Level46_85908Field(privateState, short*, 0xC);
            if (temp_a1 <= 0) {
                goto block_42;
            }
            Level46_85908_func_80035DDC(owner, temp_a1, 0, 0, 0);
            Level46_85908Field(privateState, short*, 0xC) =
                (short)((unsigned short)Level46_85908Field(privateState, short*, 0xC) - 0x10);
        block_42:
            temp_v0_3 = Level46_85908Field(owner, unsigned char*, 0x45);
            if (temp_v0_3 == 0) {
                goto block_44;
            }
            Level46_85908Field(owner, unsigned char*, 0x45) = (unsigned char)(temp_v0_3 - 1);
        block_44:
            scratch = Level46_85908Field(owner, unsigned char*, 68);
            MATCHING_KEEP(scratch);
            result = scratch & 255;
            if (!result)
                goto block_46;
            if ((unsigned int)result < 128) {
                result = scratch - 1;
                goto block_48;
            }
        block_46:
            if ((unsigned int)scratch < 129) {
                argument0 = privateState + 8;
                goto block_49;
            }
            result = scratch + 1;
        block_48:
            Level46_85908Field(owner, unsigned char*, 68) = result;
            argument0 = privateState + 8;
        block_49:
            if (Level46_85908CountTimerDown(argument0, 2) == 0) {
                goto block_169;
            }
            Level46_85908Field(owner, unsigned char*, 0x48) = 2U;
            Level46_85908Field(privateState, short*, 0xC) = 0;
            goto block_169;
        case 2:
            saved17 = Level46_85908Field(privateState, int*, 4);
            Level46_85908Field(owner, int*, 0x54) =
                (int)(Level46_85908Field(owner, int*, 0x14) + 0x80000064);
            result = Level46_85908Field(privateState, short*, 12);
            scratch = result;
            MATCHING_KEEP2(result, scratch);
            temp_v0_5 = result;
            if (result >= 0x64) {
                goto block_53;
            }
            result = scratch + 10;
            Level46_85908Keep(result);
            Level46_85908Field(privateState, short*, 12) = result;
        block_53:
            temp_v0_6 = ((short)Level46_85908Field(saved17, unsigned short*, 2) * 0x10) +
                        Level46_85908Field(saved17, int*, 0xC);
            Level46_85908AbsoluteByteAngleDelta(
                (int)Level46_85908Field(owner, unsigned char*, 0x46),
                Level46_85908PlanarHeadingLookup(
                    Level46_85908Field(temp_v0_6, int*, 0) - Level46_85908Field(owner, int*, 0xC),
                    Level46_85908Field(temp_v0_6, int*, 4) - Level46_85908Field(owner, int*, 0x10),
                    0));
            result = Level46_85908ApproximatePlanarDistance(
                owner + 12, Level46_85908Field(saved17, int*, 12) +
                                (Level46_85908Field(saved17, short*, 2) * 16));
            argument2 = 0;
            if (result < 120) {
                goto block_55;
            }
            temp_v0_7 = ((short)Level46_85908Field(saved17, unsigned short*, 2) * 0x10) +
                        Level46_85908Field(saved17, int*, 0xC);
            result = Level46_85908AbsoluteByteAngleDelta(
                (int)Level46_85908Field(owner, unsigned char*, 70),
                Level46_85908PlanarHeadingLookup(
                    Level46_85908Field(temp_v0_7, int*, 0) - Level46_85908Field(owner, int*, 12),
                    Level46_85908Field(temp_v0_7, int*, 4) - Level46_85908Field(owner, int*, 16),
                    0));
            argument2 = 0;
            if (result < 65) {
                goto block_63;
            }
        block_55:
            temp_v1_8 = (short)Level46_85908Field(saved17, unsigned short*, 2);
            temp_v1_9 = Level46_85908Field(
                ((temp_v1_8 * 0x10) + Level46_85908Field(saved17, int*, 0xC)), int*, 0xC);
            Level46_85908Field(saved17, unsigned short*, 2) =
                (unsigned short)((int)(temp_v1_8 + 1) %
                                 (short)Level46_85908Field(saved17, short*, 0));
            if (temp_v1_9 != 1) {
                goto block_57;
            }
            Level46_85908RequestMobyAnimation(owner, 0);
            MATCHING_OBSERVE_VOLATILE(owner);
            argument2 = 0;
            goto block_63;
        block_57:
            if (temp_v1_9 != 2) {
                goto block_59;
            }
            Level46_85908RequestMobyAnimation(owner, 2);
            MATCHING_OBSERVE_VOLATILE(privateState);
            argument2 = 0;
            goto block_63;
        block_59:
            argument2 = 0;
            if (temp_v1_9 != 3) {
                goto block_63;
            }
            if (Level46_85908_func_8003BFC0(owner, Level46_85908Field(privateState, int*, 32)) ==
                0) {
                goto block_62;
            }
            Level46_85908_func_8003BE70(Level46_85908Field(privateState, int*, 0x20));
            Level46_85908Field(privateState, int*, 0x20) = -1;
        block_62:
            Level46_85908Field(owner, unsigned char*, 0x48) = 0x14U;
            Level46_85908Field(privateState, short*, 0xC) = 0x4B;
            Level46_85908Field(privateState, short*, 8) =
                (short)(Level46_85908RandBetween(0, 0x50) + 0x96);
            return;
        block_63:
            MATCHING_OBSERVE_VOLATILE(argument2);
            temp_v0_8 = ((short)Level46_85908Field(saved17, unsigned short*, 2) * 0x10) +
                        Level46_85908Field(saved17, int*, 0xC);
            Level46_85908TurnMobyTowardHeading(
                owner,
                Level46_85908PlanarHeadingLookup(
                    Level46_85908Field(temp_v0_8, int*, 0) - Level46_85908Field(owner, int*, 0xC),
                    Level46_85908Field(temp_v0_8, int*, 4) - Level46_85908Field(owner, int*, 16),
                    argument2),
                2, 0x40, 1, 0);
            Level46_85908_func_80035DDC(owner, Level46_85908Field(privateState, short*, 0xC), 0, 0,
                                        0);
            locals.sp18 =
                (int)(Level46_85908Field(
                          (int)&Level46_85908_D_80065920, short*,
                          (((Level46_85908Field(owner, unsigned char*, 0x46) + 0x80) & 0xFF) * 2)) *
                      0x7D) >>
                0xA;
            locals.sp1C =
                (int)(Level46_85908Field(
                          (int)&Level46_85908_D_800658A0, short*,
                          (((Level46_85908Field(owner, unsigned char*, 0x46) + 0x80) & 0xFF) * 2)) *
                      0x7D) >>
                0xA;
            locals.sp20 = 0;
            Level46_85908AddVector(&locals.sp28, owner + 0xC, &locals.sp18);
            Level46_85908SpawnParticle(1, 0x2E, &locals.sp28, (int*)0x32);
            if (Level46_85908_func_8003BFC0(owner, Level46_85908Field(privateState, int*, 0x20)) !=
                0) {
                goto block_65;
            }
            Level46_85908Field(privateState, int*, 0x20) =
                Level46_85908PlayMobySoundEvent(owner, 1, 4);
        block_65:
            scratch = Level46_85908Field(saved17, short*, 0);
            argument1 = Level46_85908Field(saved17, short*, 2);
            result = scratch - 1;
            result = argument1 + result;
            scratch = result % scratch;
            argument2 = 0;
            result = Level46_85908Field(saved17, int*, 12);
            argument1 <<= 4;
            argument1 += result;
            argument3 = Level46_85908Field(argument1, int*, 0);
            scratch <<= 4;
            scratch += result;
            argument0 = Level46_85908Field(scratch, int*, 0);
            result = Level46_85908Field(argument1, int*, 4);
            argument1 = Level46_85908Field(scratch, int*, 4);
            argument0 = argument3 - argument0;
            argument1 = result - argument1;
            result = Level46_85908PlanarHeadingLookup(argument0, argument1, argument2);
            argument1 = Level46_85908Field(saved17, short*, 2);
            argument0 = Level46_85908Field(saved17, short*, 0);
            scratch = argument1 + 1;
            argument3 = scratch % argument0;
            saved16 = result;
            argument2 = 0;
            result = Level46_85908Field(saved17, int*, 12);
            argument1 <<= 4;
            argument1 += result;
            argument0 = Level46_85908Field(argument1, int*, 0);
            argument1 = Level46_85908Field(argument1, int*, 4);
            argument3 <<= 4;
            argument3 += result;
            Level46_85908Keep(argument3);
            scratch = Level46_85908Field(argument3, int*, 0);
            result = Level46_85908Field(argument3, int*, 4);
            argument0 = scratch - argument0;
            argument1 = result - argument1;
            result = Level46_85908PlanarHeadingLookup(argument0, argument1, argument2);
            angleFirst = result;
            if (angleFirst < 0x81) {
                goto block_67;
            }
            angleFirst -= 0x100;
        block_67:
            if (saved16 < 0x81) {
                goto block_69;
            }
            saved16 -= 0x100;
        block_69:
            angleFirst = saved16 - angleFirst;
            result = angleFirst - 17;
            if (angleFirst >= 0)
                goto block_73;
            do {
                angleFirst += 256;
            } while (angleFirst < 0);
            result = angleFirst - 17;
        block_73:
            if ((unsigned int)result >= 0x6FU) {
                goto block_75;
            }
            angleFirst = 0x10;
            goto block_77;
        block_75:
            if ((unsigned int)(angleFirst - 0x81) >= 0x6FU) {
                goto block_77;
            }
            angleFirst = 0xF0;
        block_77:
            scratch = angleFirst;
            Level46_85908Keep(scratch);
            argument0 = Level46_85908Field(owner, unsigned char*, 68);
            result = (unsigned int)argument0 < 128;
            if (!result)
                goto block_79;
            result = scratch < 129;
            if (!result)
                goto block_81;
        block_79:
            result = (unsigned int)argument0 < 129;
            if (result)
                goto block_84;
            result = scratch < 128;
            if (!result)
                goto block_84;
        block_81:
            MATCHING_BARRIER_VOLATILE("memory");
            argument0 = Level46_85908Field(owner, unsigned char*, 68);
            MATCHING_KEEP(argument0);
            argument1 = argument0 & 255;
            result = argument1 < scratch;
            if (result) {
                result = argument0 - 1;
                goto block_86;
            }
            result = scratch < argument1;
            if (!result)
                goto block_87;
            result = argument0 + 1;
            MATCHING_OBSERVE_VOLATILE(argument0);
            Level46_85908Field(owner, unsigned char*, 68) = result;
            goto block_87;
        block_84:
            argument0 = Level46_85908Field(owner, unsigned char*, 68);
            MATCHING_KEEP(argument0);
            argument1 = argument0 & 255;
            result = argument1 < scratch;
            if (result) {
                result = argument0 + 1;
                goto block_86;
            }
            result = scratch < argument1;
            if (!result)
                goto block_87;
            result = argument0 - 1;
        block_86:
            Level46_85908Field(owner, unsigned char*, 68) = result;
        block_87:
            Level46_85908Field(owner, unsigned char*, 0x45) = 8U;
            goto block_169;
        case 3:
            if (Level46_85908Field(owner, unsigned char*, 0x49) != 1) {
                goto block_95;
            }
            locals.sp20 = Level46_85908RandBetween(0, 10) - 10;
            locals.sp1C = Level46_85908RandBetween(0, 10) - 10;
            argument0 = 1;
            argument1 = 13;
            MATCHING_KEEP2(argument0, argument1);
            saved16 = owner + 12;
            locals.sp20 = 0x1E;
            temp_v0_11 = Level46_85908SpawnParticle(argument0, argument1, saved16, &locals.sp18);
            if (temp_v0_11 == 0) {
                goto block_91;
            }
            Level46_85908Field(temp_v0_11, signed char*, 0xA) = 0x64;
        block_91:
            locals.sp18 = Level46_85908RandBetween(0, 0xA) - 0xA;
            locals.sp1C = Level46_85908RandBetween(0, 0xA) - 0xA;
            locals.sp20 = 0x2D;
            temp_v0_12 = Level46_85908SpawnParticle(1, 0xD, saved16, &locals.sp18);
            if (temp_v0_12 == 0) {
                goto block_93;
            }
            Level46_85908Field(temp_v0_12, signed char*, 0xA) = 0x78;
        block_93:
            locals.sp20 = Level46_85908RandBetween(0, 0xA) - 0xA;
            locals.sp1C = Level46_85908RandBetween(0, 0xA) - 0xA;
            locals.sp20 = 0x3C;
            temp_v0_13 = Level46_85908SpawnParticle(1, 0xD, saved16, &locals.sp18);
            if (temp_v0_13 == 0) {
                goto block_171;
            }
            Level46_85908Field(temp_v0_13, unsigned char*, 0xA) = 0x96;
            return;
        block_95:
            Level46_85908Field(owner, int*, 0x54) =
                (int)(Level46_85908Field(owner, int*, 0x14) - 0x80000000);
            return;
        case 32:
            saved17 = Level46_85908_D_8006E048;
            Level46_85908Field((int)&Level46_85908_D_80070328, int*, 0x20C) = 0x10000002;
            if (saved17 != 2) {
                goto block_171;
            }
            saved16 = Level46_85908Field(privateState, int*, 0x14);
            Level46_85908Field(owner, int*, 0x54) =
                (int)(Level46_85908Field(owner, int*, 0x14) + 0x80000064);
            result = Level46_85908Field(privateState, short*, 12);
            scratch = result;
            MATCHING_KEEP2(result, scratch);
            temp_v0_14 = result;
            if (result >= 0xC8) {
                goto block_99;
            }
            result = scratch + 20;
            Level46_85908Keep(result);
            Level46_85908Field(privateState, short*, 12) = result;
        block_99:
            temp_v0_15 = (Level46_85908Field(saved16, short*, 2) * 0x10) +
                         Level46_85908Field(saved16, int*, 0xC);
            Level46_85908AbsoluteByteAngleDelta(
                (int)Level46_85908Field(owner, unsigned char*, 0x46),
                Level46_85908PlanarHeadingLookup(
                    Level46_85908Field(temp_v0_15, int*, 0) - Level46_85908Field(owner, int*, 0xC),
                    Level46_85908Field(temp_v0_15, int*, 4) - Level46_85908Field(owner, int*, 0x10),
                    0));
            result = Level46_85908ApproximatePlanarDistance(
                owner + 12, Level46_85908Field(saved16, int*, 12) +
                                (Level46_85908Field(saved16, short*, 2) * 16));
            argument2 = 0;
            if (result >= 320) {
                goto block_105;
            }
            temp_v1_12 = Level46_85908Field(saved16, short*, 2);
            temp_v1_13 = Level46_85908Field(
                ((temp_v1_12 * 0x10) + Level46_85908Field(saved16, int*, 0xC)), int*, 0xC);
            Level46_85908Field(saved16, short*, 2) =
                (short)((int)(temp_v1_12 + 1) % (short)Level46_85908Field(saved16, short*, 0));
            if (temp_v1_13 != 1)
                goto block_102;
            argument0 = owner;
            Level46_85908Keep(argument0);
            argument1 = 0;
            goto block_104;
        block_102:
            MATCHING_KEEP(argument2);
            if (temp_v1_13 != saved17) {
                argument2 = 0;
                goto block_105;
            }
            argument0 = owner;
            argument1 = 2;
        block_104:
            MATCHING_OBSERVE2_VOLATILE(argument0, argument1);
            Level46_85908RequestMobyAnimation(argument0, argument1);
            argument2 = 0;
        block_105:
            temp_v0_16 = (Level46_85908Field(saved16, short*, 2) * 0x10) +
                         Level46_85908Field(saved16, int*, 0xC);
            Level46_85908TurnMobyTowardHeading(
                owner,
                Level46_85908PlanarHeadingLookup(
                    Level46_85908Field(temp_v0_16, int*, 0) - Level46_85908Field(owner, int*, 0xC),
                    Level46_85908Field(temp_v0_16, int*, 4) - Level46_85908Field(owner, int*, 16),
                    argument2),
                8, 0x40, 1, 0);
            Level46_85908_func_80035DDC(owner, Level46_85908Field(privateState, short*, 0xC), 0, 0,
                                        0);
            scratch = Level46_85908Field(saved16, short*, 0);
            argument1 = Level46_85908Field(saved16, short*, 2);
            result = scratch - 1;
            result = argument1 + result;
            scratch = result % scratch;
            argument2 = 0;
            result = Level46_85908Field(saved16, int*, 12);
            argument1 <<= 4;
            argument1 += result;
            argument3 = Level46_85908Field(argument1, int*, 0);
            scratch <<= 4;
            scratch += result;
            argument0 = Level46_85908Field(scratch, int*, 0);
            result = Level46_85908Field(argument1, int*, 4);
            argument1 = Level46_85908Field(scratch, int*, 4);
            argument0 = argument3 - argument0;
            argument1 = result - argument1;
            result = Level46_85908PlanarHeadingLookup(argument0, argument1, argument2);
            argument1 = Level46_85908Field(saved16, short*, 2);
            argument0 = Level46_85908Field(saved16, short*, 0);
            scratch = argument1 + 1;
            argument3 = scratch % argument0;
            saved17 = result;
            argument2 = 0;
            result = Level46_85908Field(saved16, int*, 12);
            argument1 <<= 4;
            argument1 += result;
            argument0 = Level46_85908Field(argument1, int*, 0);
            argument1 = Level46_85908Field(argument1, int*, 4);
            argument3 <<= 4;
            argument3 += result;
            Level46_85908Keep(argument3);
            scratch = Level46_85908Field(argument3, int*, 0);
            result = Level46_85908Field(argument3, int*, 4);
            argument0 = scratch - argument0;
            argument1 = result - argument1;
            result = Level46_85908PlanarHeadingLookup(argument0, argument1, argument2);
            angleSecond = result;
            if (angleSecond < 0x81) {
                goto block_107;
            }
            angleSecond -= 0x100;
        block_107:
            if (saved17 < 0x81) {
                goto block_109;
            }
            saved17 -= 0x100;
        block_109:
            angleSecond = saved17 - angleSecond;
            result = angleSecond - 17;
            if (angleSecond >= 0)
                goto block_113;
            do {
                angleSecond += 256;
            } while (angleSecond < 0);
            result = angleSecond - 17;
        block_113:
            if ((unsigned int)result >= 0x6FU) {
                goto block_115;
            }
            angleSecond = 0x10;
            goto block_117;
        block_115:
            if ((unsigned int)(angleSecond - 0x81) >= 0x6FU) {
                goto block_117;
            }
            angleSecond = 0xF0;
        block_117:
            scratch = angleSecond;
            Level46_85908Keep(scratch);
            argument0 = Level46_85908Field(owner, unsigned char*, 68);
            result = (unsigned int)argument0 < 128;
            if (!result)
                goto block_119;
            result = scratch < 129;
            if (!result)
                goto block_121;
        block_119:
            result = (unsigned int)argument0 < 129;
            if (result)
                goto block_124;
            result = scratch < 128;
            if (!result)
                goto block_124;
        block_121:
            MATCHING_BARRIER_VOLATILE("memory");
            argument0 = Level46_85908Field(owner, unsigned char*, 68);
            MATCHING_KEEP(argument0);
            argument1 = argument0 & 255;
            result = argument1 < scratch;
            if (result) {
                result = argument0 - 1;
                goto block_126;
            }
            result = scratch < argument1;
            if (!result)
                goto block_127;
            result = argument0 + 1;
            MATCHING_OBSERVE_VOLATILE(argument0);
            Level46_85908Field(owner, unsigned char*, 68) = result;
            goto block_127;
        block_124:
            argument0 = Level46_85908Field(owner, unsigned char*, 68);
            MATCHING_KEEP(argument0);
            argument1 = argument0 & 255;
            result = argument1 < scratch;
            if (result) {
                result = argument0 + 1;
                goto block_126;
            }
            result = scratch < argument1;
            if (!result)
                goto block_127;
            result = argument0 - 1;
        block_126:
            Level46_85908Field(owner, unsigned char*, 68) = result;
        block_127:
            Level46_85908CopyVector(&locals.sp38, owner + 0xC);
            locals.sp40 += 0x12C;
            Level46_85908RefreshMobySpatialGridAndBasis(owner, 6);
            locals.sp48 = 0x1F4;
            locals.sp4C = 0;
            locals.sp50 = 0;
            Level46_85908TransformVectorByBasis(owner + 0x20, &locals.sp48, &locals.sp48);
            locals.sp50 = 0;
            Level46_85908AddVector(&locals.sp48, &locals.sp38, &locals.sp48);
            if (Level46_85908_func_8001830C(&locals.sp38, &locals.sp48, 7, 0, 0) == 0) {
                goto block_135;
            }
            argument0 = owner;
            result = Level46_85908Field(owner, unsigned char*, 70);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(result, "$5");
            argument1 = 1;
            __asm__("" : "=r"(result) : "0"(result), "r"(argument1));
            result += 64;
            Level46_85908Field(owner, unsigned char*, 81) = result;
            result = 350;
            Level46_85908Field(privateState, short*, 12) = result;
            result = Level46_85908Field(owner, unsigned char*, 81);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(result, "$16");
            saved16 = 180;
            Level46_85908Field(privateState, short*, 8) = saved16;
            __asm__(""
                    : "=r"(result)
                    : "0"(result), "m"(Level46_85908Field(privateState, short*, 8)));
            Level46_85908Field(privateState, short*, 10) = result;
            result = 1;
            Level46_85908Field(owner, unsigned char*, 68) = 0;
            Level46_85908Field(owner, unsigned char*, 69) = 0;
            Level46_85908Field(owner, int*, 84) = 0;
            Level46_85908Field(owner, unsigned char*, 72) = result;
            Level46_85908RequestMobyAnimation(argument0, argument1);
            scratch = Level46_85908Field(privateState, int*, 0);
            result = 300;
            if (!scratch)
                goto block_130;
            Level46_85908Field(scratch, int*, 84) = 0;
            scratch = Level46_85908Field(scratch, int*, 0);
            Level46_85908Field(scratch, short*, 12) = result;
            result = Level46_85908Field(owner, unsigned char*, 81);
            Level46_85908Field(scratch, short*, 8) = saved16;
            result = (result + 128) & 255;
            Level46_85908Field(scratch, short*, 10) = result;
            result = Level46_85908Field(privateState, int*, 0);
            Level46_85908Field(result, unsigned char*, 68) = 0;
            result = Level46_85908Field(privateState, int*, 0);
            Level46_85908Field(result, unsigned char*, 69) = 0;
            scratch = Level46_85908Field(privateState, int*, 0);
            result = 31;
            Level46_85908Field(scratch, unsigned char*, 72) = result;
        block_130:
            result = Level46_85908SpawnMoby(0x27D, owner);
            scratch = result;
            Level46_85908Keep(scratch);
            temp_v0_19 = scratch;
            if (scratch == 0) {
                goto block_171;
            }
            result = 33;
            argument1 = Level46_85908Field(scratch, int*, 0);
            Level46_85908Keep(argument1);
            Level46_85908Field(scratch, unsigned char*, 72) = result;
            result = 300;
            Level46_85908Field(argument1, short*, 12) = result;
            result = Level46_85908Field(owner, unsigned char*, 70);
            Level46_85908Field(argument1, short*, 8) = saved16;
            Level46_85908Field(argument1, short*, 10) = result;
            Level46_85908Field(scratch, unsigned char*, 65) = 0;
            Level46_85908Field(scratch, unsigned char*, 76) = 0;
            Level46_85908Field(scratch, unsigned char*, 77) = 0;
            scratch = Level46_85908Field(privateState, int*, 28);
            argument0 = Level46_85908_D_8006C550;
            result = scratch * 88;
            scratch = Level46_85908_D_8006C7B4;
            argument0 += result;
            Level46_85908Field(argument1, int*, 0) = argument0;
            if (scratch & 2)
                goto block_134;
            if (Level46_85908Field((int)&Level46_85908_D_80070300, unsigned char*,
                                   Level46_85908_D_8006C58C) &
                2)
                goto block_134;
            if (!(Level46_85908Field(argument0, unsigned char*, 72) & 128))
                goto block_171;
        block_134:
            Level46_85908Field(argument1, int*, 0) = 0;
            return;
        block_135:
            Level46_85908Field(owner, unsigned char*, 0x45) = 0xCU;
            goto block_169;
        case 33:
            Level46_85908Field((int)&Level46_85908_D_80070328, int*, 0x20C) = 0x10000002;
            Level46_85908Field(owner, int*, 0x14) =
                (int)(Level46_85908Field(owner, int*, 0x14) +
                      Level46_85908Field(privateState, short*, 0xC));
            Level46_85908Field(privateState, short*, 0xC) =
                (short)((unsigned short)Level46_85908Field(privateState, short*, 0xC) - 0x10);
            Level46_85908_func_80035EE0(owner, Level46_85908Field(privateState, short*, 0xA), 0x64,
                                        0, 0, 0);
            saved17 = Level46_85908Field(privateState, int*, 0);
            if (saved17 == 0) {
                goto block_138;
            }
            Level46_85908CopyVector(saved17 + 0xC, owner + 0xC);
            Level46_85908SpawnParticle(1, 0xC, saved17, (int*)5);
        block_138:
            if (Level46_85908CountTimerDown(privateState + 8, 2) != 0) {
                goto block_141;
            }
            if (Level46_85908Field(privateState, short*, 0xC) >= 0) {
                goto block_171;
            }
            if (Level46_85908_func_8001A358(owner + 0xC, 0x190) == 0) {
                goto block_171;
            }
        block_141:
            Level46_85908Field(owner, unsigned char*, 0x48) = 0x23U;
            if (saved17 == 0) {
                goto block_143;
            }
            Level46_85908Field(saved17, int*, 20) = Level46_85908_D_80071908;
            Level46_85908Field(saved17, unsigned char*, 72) = 0;
            Level46_85908RefreshMobySpatialGridAndBasis(saved17, 7);
            locals.sp58 = 0x800;
            locals.sp5C = 0;
            locals.sp60 = 0;
            Level46_85908TransformVectorByBasis(owner + 0x20, &locals.sp58, &locals.sp58);
            Level46_85908AddVector(&locals.sp58, saved17 + 0xC, &locals.sp58);
            Level46_85908_func_80013D44(
                &locals.sp58, (Level46_85908Field(saved17, unsigned char*, 0x46) + 0x80) & 0xFF, 0,
                0);
            return;
        block_143:
            MATCHING_KEEP(saved17);
            argument2 = 0;
            Level46_85908_func_80013D44(owner + 12, Level46_85908Field(owner, unsigned char*, 70),
                                        argument2, 0);
            return;
        case 35:
            if (Level46_85908_D_8006E048 != 1) {
                goto block_171;
            }
            scratch = Level46_85908Field(privateState, int*, 0);
            Level46_85908Keep(scratch);
            temp_v1_18 = scratch;
            if (temp_v1_18 == 0) {
                goto block_147;
            }
            Level46_85908Field(temp_v1_18, signed char*, 0x48) = 1;
        block_147:
            Level46_85908DeleteMoby(owner);
            return;
        case 34:
            result = 0x10000002;
            Level46_85908Keep(result);
            argument0 = 1;
            argument1 = 13;
            MATCHING_KEEP2(argument0, argument1);
            saved17 = owner + 12;
            saved20 = (short)Level46_85908Field(privateState, unsigned short*, 0xE);
            Level46_85908Field((int)&Level46_85908_D_80070328, int*, 0x20C) = result;
            locals.sp68 = 0;
            locals.sp6C = 0;
            locals.sp70 = 0x96;
            temp_v0_20 = Level46_85908SpawnParticle(argument0, argument1, saved17, &locals.sp68);
            if (temp_v0_20 == 0) {
                goto block_150;
            }
            Level46_85908Field(temp_v0_20, unsigned char*, 0xA) = 0xFA;
        block_150:
            locals.sp68 = 0;
            locals.sp6C = 0;
            locals.sp70 = 0xFA;
            temp_v0_21 = Level46_85908SpawnParticle(1, 0xD, saved17, &locals.sp68);
            if (temp_v0_21 == 0) {
                goto block_152;
            }
            Level46_85908Field(temp_v0_21, unsigned char*, 0xA) = 0xFA;
        block_152:
            Level46_85908_func_80035DDC(owner, 0xC8, 0, 0, 0);
            temp_v1_19 = Level46_85908Field(owner, unsigned char*, 0x45);
            if (temp_v1_19 >= 0x1AU) {
                goto block_154;
            }
            Level46_85908Field(owner, unsigned char*, 0x45) = (unsigned char)(temp_v1_19 + 1);
        block_154:
            if (saved20 < 0) {
                goto block_158;
            }
            if (Level46_85908RandBetween(0, 3) == 0) {
                goto block_157;
            }
            Level46_85908Field(owner, unsigned char*, 0x46) =
                (unsigned char)(Level46_85908Field(owner, unsigned char*, 0x46) + 8);
            goto block_162;
        block_157:
            result = Level46_85908Field(owner, unsigned char*, 70);
            result += -8;
            Level46_85908Field(owner, unsigned char*, 70) = result;
            __asm__ volatile(""
                             : "=r"(result)
                             : "0"(result), "m"(Level46_85908Field(owner, unsigned char*, 70)));
            result = -1;
            goto block_161;
        block_158:
            if (Level46_85908RandBetween(0, 3) == 0) {
                goto block_160;
            }
            Level46_85908Field(owner, unsigned char*, 0x46) =
                (unsigned char)(Level46_85908Field(owner, unsigned char*, 0x46) - 8);
            goto block_162;
        block_160:
            result = Level46_85908Field(owner, unsigned char*, 70);
            result += 8;
            Level46_85908Field(owner, unsigned char*, 70) = result;
            __asm__ volatile(""
                             : "=r"(result)
                             : "0"(result), "m"(Level46_85908Field(owner, unsigned char*, 70)));
            result = 1;
        block_161:
            Level46_85908Field(privateState, unsigned short*, 0xE) = result;
        block_162:
            scratch = Level46_85908Field(owner, unsigned char*, 68);
            MATCHING_KEEP(scratch);
            result = scratch & 255;
            if (!result)
                goto block_164;
            if ((unsigned int)result < 128) {
                result = scratch - 1;
                goto block_166;
            }
        block_164:
            if ((unsigned int)scratch < 129) {
                argument0 = privateState + 8;
                goto block_167;
            }
            result = scratch + 1;
        block_166:
            Level46_85908Field(owner, unsigned char*, 68) = result;
            argument0 = privateState + 8;
        block_167:
            if (Level46_85908CountTimerDown(argument0, 2) == 0) {
                goto block_169;
            }
            Level46_85908Field(owner, unsigned char*, 0x48) = 0x20U;
            Level46_85908Field(owner, unsigned char*, 0x44) = 0U;
            Level46_85908Field(owner, unsigned char*, 0x45) = 0U;
            temp_v0_23 =
                Level46_85908Field(Level46_85908Field(privateState, int*, 0x14), int*, 0xC);
            temp_a3_5 = Level46_85908Field(temp_v0_23, int*, 0x10);
            Level46_85908Field(owner, unsigned char*, 0x46) = Level46_85908PlanarHeadingLookup(
                temp_a3_5 - Level46_85908Field(temp_v0_23, int*, 0),
                Level46_85908Field(temp_v0_23, int*, 20) - Level46_85908Field(temp_v0_23, int*, 4),
                0);
            Level46_85908Field(owner, int*, 0xC) = (int)Level46_85908Field(
                Level46_85908Field(Level46_85908Field(privateState, int*, 0x14), int*, 0xC), int*,
                0);
            Level46_85908Field(owner, int*, 0x10) = (int)Level46_85908Field(
                Level46_85908Field(Level46_85908Field(privateState, int*, 0x14), int*, 0xC), int*,
                4);
            Level46_85908Field(privateState, unsigned short*, 0xE) = 0U;
            Level46_85908Field(Level46_85908Field(privateState, int*, 0x14), short*, 2) = 0;
            temp_a0_9 = Level46_85908Field(Level46_85908Field(privateState, int*, 0x10), int*, 0xC);
            Level46_85908_func_80013AE4(temp_a0_9, temp_a0_9 + 0x10);
        block_169:
            scratch = Level46_85908Field(privateState, int*, 0);
            Level46_85908Keep(scratch);
            if (scratch == 0) {
                goto block_171;
            }
            Level46_85908Field(scratch, int*, 0xC) = (int)Level46_85908Field(owner, int*, 0xC);
            scratch = Level46_85908Field(privateState, int*, 0);
            Level46_85908Keep(scratch);
            Level46_85908Field(scratch, int*, 16) = Level46_85908Field(owner, int*, 16);
            scratch = Level46_85908Field(privateState, int*, 0);
            Level46_85908Keep(scratch);
            Level46_85908Field(scratch, unsigned char*, 68) =
                Level46_85908Field(owner, unsigned char*, 68);
            scratch = Level46_85908Field(privateState, int*, 0);
            Level46_85908Keep(scratch);
            Level46_85908Field(scratch, unsigned char*, 69) =
                Level46_85908Field(owner, unsigned char*, 69);
            scratch = Level46_85908Field(privateState, int*, 0);
            Level46_85908Keep(scratch);
            Level46_85908Field(scratch, unsigned char*, 70) =
                Level46_85908Field(owner, unsigned char*, 70);
        case 0:
            MATCHING_OBSERVE_VOLATILE(scratch);
        block_171:
            return;
        default:
            goto block_171;
    }
}

#undef Level46_85908Field

typedef struct {
    short selector, enabled;
} DecodedSelectorTag;
int DecodedSelectorRead(int) __asm__("func_80021F3C");
void DecodedSelectorSend(int, int, int) __asm__("func_80021ED8");
void func_80055B18(Moby*);
void func_level_46_80086D08(Moby* moby) {
    DecodedSelectorTag* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (tag->enabled) {
                unsigned char* state;
                moby->state = 1;
                state = &moby->state;
                func_8003B7B4(state, 1, &savedData);
                func_8003B7B4(state, 1, &unsavedData);
                func_80055B18(moby);
            }
            break;
        case 1: {
            int result = DecodedSelectorRead(tag->selector);
            if (((result >> 8) & 255) == 0 && (result & 15)) {
                DecodedSelectorSend(tag->selector, 0xFC, 0);
                func_80055B18(moby);
            }
        } break;
    }
}

/* SCUS-94467 USA Rev 0, 0x80086DD8: 227 original instructions.
 * Three loops consume six 32-bit Moby indices with an 88-byte record stride.
 * Linked byte stores follow the two original pointer loads at offset zero.
 * Signed modulo 27 is expressed as quotient and remainder; no CPU opcode asm.
 * HUD creation results are explicitly narrowed to signed 16 bits as in retail.
 * Helper semantics, position units and caller cadence remain unresolved.
 * Empty constraints preserve compiler allocation/order and emit no instructions.
 * AI generated; not human reviewed. */
#define P86DD8_FIELD(type, base, offset) (*(type*)((unsigned char*)(base) + (offset)))
extern unsigned char* P86DD8End __asm__("D_8006C54C");
extern int P86DD8Table[] __asm__("D_80071A10");
extern unsigned char D_level_46_80091B40[];
extern int D_8006C774;
extern struct {
    Vector3D position;
} D_80070328;
void func_level_46_80086DD8(Moby* input) {
    register Moby* owner __asm__("$18") = input;
    register Moby* initialMoby __asm__("$3");
    register Moby* activeMoby __asm__("$3");
    register Moby* resetMoby __asm__("$3");
    register int* tableEntry4 __asm__("$4");
    register int index3 __asm__("$3"), offset2 __asm__("$2");
    register void* tag2 __asm__("$2");
    register int one4 __asm__("$4"), one9 __asm__("$9"), maximum8 __asm__("$8"),
        value7 __asm__("$7");
    register int remainder4 __asm__("$4");
    register int* privateState __asm__("$16");
    register int* initialIndices __asm__("$5");
    register int* activeIndices __asm__("$5");
    register int* resetIndices __asm__("$5");
    int hudHandle;
    int resetHudHandle;
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int* table3 __asm__("$3");
    register int initialCount __asm__("$6");
    register int activeCount __asm__("$6");
    register int resetCount __asm__("$6");
    register int state4 __asm__("$4");
    unsigned char state;

    state = owner->state;
    privateState = owner->mobyTag;
    if (state == 0) {
        owner->state = 1;
        return;
    }
    initialCount = 0;
    if (state == 1) {
        one4 = 1;
        MATCHING_KEEP(one4);
        initialIndices = privateState;
        do {
            index3 = *initialIndices;
            MATCHING_KEEP(index3);
            offset2 = index3 * 11;
            initialMoby = D_8006C550;
            __asm__("" : "=r"(initialMoby) : "0"(initialMoby), "r"(offset2));
            initialMoby = (Moby*)((unsigned char*)initialMoby + (offset2 << 3));
            MATCHING_KEEP(initialMoby);
            if (!(initialMoby->state & 0x80)) {
                tag2 = initialMoby->mobyTag;
                MATCHING_KEEP(tag2);
                initialMoby->updateDistance = one4;
                initialMoby->lowDrawDistance = one4;
                P86DD8_FIELD(unsigned char, *(void**)tag2, 0x4A) = one4;
                P86DD8_FIELD(unsigned char, *(void**)initialMoby->mobyTag, 0x4C) = one4;
            }
            initialCount += 1;
            initialIndices += 1;
        } while (initialCount < 6);
        owner->updateDistance = 0x10;
        owner->state = 2;
        return;
    }
    if (((P86DD8End - 1) == D_level_46_80091B40) && (D_8006C774 != 0)) {
        work2 = rand();
        MATCHING_KEEP_CLOBBER(work2, "$12");
        remainder4 = work2 / 27;
        __asm__("" : "=r"(remainder4) : "0"(remainder4), "r"(work2));
        work3 = remainder4 * 27;
        remainder4 = work2 - work3;
        MATCHING_KEEP(remainder4);
        table3 = P86DD8Table;
        __asm__("" : "=r"(table3) : "0"(table3), "r"(remainder4));
        work2 = remainder4 * 4;
        tableEntry4 = (int*)(work2 + (int)table3);
        MATCHING_KEEP(tableEntry4);
        work3 = *tableEntry4;
        if (work2 + 0x49 < work3) {
            work2 = work3 - 1;
            MATCHING_KEEP(work2);
            *tableEntry4 = work2;
        }
    }
    if ((func_80036220(&D_80070328.position, (unsigned char*)privateState + 0x20, 0, 0x2800) !=
         0) &&
        (func_80036220(&D_80070328.position, (unsigned char*)privateState + 0x38, 0, 0x2800) ==
         0)) {
        activeCount = 0;
        MATCHING_KEEP_CLOBBER(activeCount, "$9");
        P86DD8_FIELD(int, privateState, 0x1C) = 0;
        one9 = 1;
        maximum8 = 0xFF;
        MATCHING_OBSERVE2_CLOBBER(one9, maximum8, "$7");
        value7 = 0x30;
        MATCHING_OBSERVE3(one9, maximum8, value7);
        activeIndices = privateState;
        do {
            index3 = *activeIndices;
            MATCHING_KEEP(index3);
            offset2 = index3 * 11;
            activeMoby = D_8006C550;
            __asm__("" : "=r"(activeMoby) : "0"(activeMoby), "r"(offset2));
            activeMoby = (Moby*)((unsigned char*)activeMoby + (offset2 << 3));
            MATCHING_KEEP(activeMoby);
            state4 = activeMoby->state;
            if ((state4 & 0x80) || (state4 == one9)) {
                P86DD8_FIELD(int, privateState, 0x1C) =
                    (int)(P86DD8_FIELD(int, privateState, 0x1C) + 1);
            } else {
                tag2 = activeMoby->mobyTag;
                MATCHING_KEEP(tag2);
                activeMoby->updateDistance = maximum8;
                activeMoby->lowDrawDistance = value7;
                P86DD8_FIELD(unsigned char, *(void**)tag2, 0x4A) = maximum8;
                P86DD8_FIELD(unsigned char, *(void**)activeMoby->mobyTag, 0x4C) = value7;
            }
            activeCount += 1;
            activeIndices += 1;
        } while (activeCount < 6);
        if (P86DD8_FIELD(int, privateState, 0x1C) == 6) {
            hudHandle = P86DD8_FIELD(int, privateState, 0x18);
            if (hudHandle != 0) {
                func_80028154(hudHandle);
                P86DD8_FIELD(int, privateState, 0x18) = 0;
                func_80055B18(owner);
            }
        } else if (P86DD8_FIELD(int, privateState, 0x18) == 0) {
            P86DD8_FIELD(int, privateState, 0x18) =
                (short)func_8002803C(0x17, 0x1CE, func_80027EE4, func_80027A60, func_80029AA0,
                                     (int*)((unsigned char*)privateState + 0x1C), 6);
        }
    } else {
        resetHudHandle = P86DD8_FIELD(int, privateState, 0x18);
        if (resetHudHandle != 0) {
            func_80028154(resetHudHandle);
            P86DD8_FIELD(int, privateState, 0x18) = 0;
            resetCount = 0;
            one4 = 1;
            MATCHING_KEEP(one4);
            resetIndices = privateState;
            do {
                index3 = *resetIndices;
                MATCHING_KEEP(index3);
                offset2 = index3 * 11;
                resetMoby = D_8006C550;
                __asm__("" : "=r"(resetMoby) : "0"(resetMoby), "r"(offset2));
                resetMoby = (Moby*)((unsigned char*)resetMoby + (offset2 << 3));
                MATCHING_KEEP(resetMoby);
                if (!(resetMoby->state & 0x80)) {
                    tag2 = resetMoby->mobyTag;
                    MATCHING_KEEP(tag2);
                    resetMoby->updateDistance = one4;
                    resetMoby->lowDrawDistance = one4;
                    P86DD8_FIELD(unsigned char, *(void**)tag2, 0x4A) = one4;
                    P86DD8_FIELD(unsigned char, *(void**)resetMoby->mobyTag, 0x4C) = one4;
                }
                resetCount += 1;
                resetIndices += 1;
            } while (resetCount < 6);
        }
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; original 80087164.
* Original assembly SHA256 fb9f001d239b0c9812e16e0a4d88a5b4df4b2507e680a37965bc2513ce665086.
* AI generated; not human reviewed. Exactly 609 original instructions,
* all actual branch/J/call targets and data symbols must match; no selectors.
* The original D0hex frame saves S0..S7/FP/RA, with local SP18..A7 storage.
* Original loops produce two 16*6 twelve-byte record sets and two 15*6
* eight-byte index/byte sets. Physical units and consumer meanings remain open.
* All 20 MULT sites initialize full signed64 C products before 13 LO and
* seven HI captures. Producer/capture lifetimes are disjoint and retain the
* original signed shifts, low32 truncation, /3,/6,/90 correction sequences,
* byte widths, halfwords, loads, stores and ten explicit caller saves.
* Whole metadata consumes initialized complete values or already-written
* fields, or clobbers dead registers before fresh complete producers.
* It emits no CPU instructions; no opcode asm, partial HI/LO, fixed FP,
* undefined saved input or overlapping live fixed aliases is used.
* Ordinary fifth literal one and inline fourth parent+12 retain the original
* SW fifth word before JAL and fourth-argument ADDIU in its delay slot.
* Original skip edges retain the initialized private pointer, reloading only
* after the exact original state write or callback. Actual destinations count.
* Existing stdutil.h/moby260.h/tracers.h contracts provide helper ABI views;
* address-only field names do not claim semantic meanings. Rev1 raw1000 is
* a structural search lead, not evidence that these Rev0 branches are Rev1.
* Confidence requires native/linked words, actual transfers and full retail
* EXE/every-overlay hashes. Helper/caller chains, physical units/fixed point,
* cadence beyond this invocation, human review and synchronized retail
* runtime verification remain open. Compiler/filter/flags are unchanged.
*/
#define Level46_87164CompleteSignedProductLow(a, b)                                  \
    ({                                                                               \
        long long completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        int productLowWord;                                                          \
        __asm__("" : "=l"(productLowWord) : "x"(completeSignedProduct));             \
        productLowWord;                                                              \
    })
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original609
* words: sibling4945. Rev1 raw1000 source-lock F6D91C229C57786B2D7125DB
* 0625A6B406DC9C5BCE6D9267EB3FC72B89E28971 is a structural search lead.
* Raw fields only; units, helper meanings, fixed point domains and cadence
* unresolved. Uninstalled until strict native/linked words and hashes pass. */
#define Level46_87164Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level46_87164Word(p, o) Level46_87164Field(p, int*, o)
#define Level46_87164Pointer(p, o) Level46_87164Field(p, unsigned char**, o)
#define Level46_87164Byte(p, o) Level46_87164Field(p, unsigned char*, o)
#define Level46_87164SignedHalfword(p, o) Level46_87164Field(p, short*, o)
#define Level46_87164UnsignedHalfword(p, o) Level46_87164Field(p, unsigned short*, o)
#define Level46_87164KeepCompleteWord(v) __asm__("" : "=r"(v) : "0"(v))
extern short Level46_87164Table65920[] __asm__("D_80065920"), Level46_87164Table658A0[] __asm__(
                                                                  "D_800658A0");
extern unsigned char Level46_87164Data70328View1[] __asm__("D_80070328");
extern int Level46_87164Data6C640View1 __asm__("D_8006C640");
extern int (*Level46_87164DataSpawnParticleView1)() __asm__("SpawnParticle");
int Level46_87164Call1C288View1() __asm__("func_8001C288");
int Level46_87164SubtractVectorView1() __asm__("func_8004F1C8");
int Level46_87164PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level46_87164Call1BA30View1() __asm__("func_8001BA30");
void Level46_87164AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void* Level46_87164Call50B00View1(int, int, int, int, int) __asm__("func_80050B00");
void Level46_87164AddVectorView2(void*, void*, void*) __asm__("func_8004F194");
void* Level46_87164Call50B00View2(int, int, int, int, int) __asm__("func_80050B00");
void Level46_87164Call50B88View1(void*) __asm__("func_80050B88");
void Level46_87164Call50B88View2(void*) __asm__("func_80050B88");
void Level46_87164DeleteMobyView1(void*) __asm__("func_80055B18");
void func_level_46_80087164(unsigned char* ownerParameter) {
    struct {
        volatile int vectorWork18[4];
        int particleWords28[4];
        unsigned char* volatile privateRecord38;
        int pad3C;
        unsigned char* volatile linkedOwner40;
        int pad44;
        volatile int signedHalfword48;
        int pad4C;
        unsigned char* volatile pointArray50;
        int pad54;
        unsigned char* volatile header58;
        int pad5C;
        unsigned char* volatile indexArray60;
        int pad64;
        short* volatile table658A0_68;
        int pad6C;
        short* volatile table65920_70;
        int pad74;
        int phaseWord78, pad7C;
        int savedCallerWords80[10];
    } originalFrame;
    register unsigned char* owner23 __asm__("$23") = ownerParameter;
    register unsigned char* rawAddressOrWord25 __asm__("$25");
    register unsigned char* twelveByteRecord16 __asm__("$16");
    register int innerIndex17 __asm__("$17");
    register int angleOrTableAddress18 __asm__("$18");
    register int halfwordOrTableAddress19 __asm__("$19");
    register int baseIndexOrHalfword20 __asm__("$20");
    register int outerIndex21 __asm__("$21");
    register int retainedOffset22 __asm__("$22");
    int retainedOffset;
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"),
        argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int rawWord8 __asm__("$8"), rawWord9 __asm__("$9"), rawWord10 __asm__("$10"),
        rawWord11 __asm__("$11");
    register unsigned char* headerAddress12 __asm__("$12");
    register short *table658A0OrMagic13 __asm__("$13"), *table65920Address14 __asm__("$14");
    register unsigned char* recordArrayAddress15 __asm__("$15");
    register unsigned char* indexArrayAddress24 __asm__("$24");
    long long completeSignedProduct;
    int completeProductHigh, completeProductLow;
    Level46_87164KeepCompleteWord(owner23);
    rawAddressOrWord25 = Level46_87164Pointer(owner23, 0);
    originalFrame.privateRecord38 = rawAddressOrWord25;
    originalFrame.linkedOwner40 =
        Level46_87164Pointer(Level46_87164Pointer(rawAddressOrWord25, 16), 0);
    rawWord3 = Level46_87164Byte(owner23, 0x48);
    Level46_87164Byte(owner23, 0x41) = 0;
    Level46_87164Byte(owner23, 0x4C) = 0;
    Level46_87164Byte(owner23, 0x4D) = 0;
    if (rawWord3 == 1) {
        twelveByteRecord16 = owner23 + 12;
        rawWord2 = Level46_87164UnsignedHalfword(rawAddressOrWord25, 0) + 200;
        Level46_87164UnsignedHalfword(rawAddressOrWord25, 0) = rawWord2;
        rawWord2 = Level46_87164Call1C288View1(twelveByteRecord16, (short)rawWord2, 0);
        if (rawWord2) {
            rawWord2 = Level46_87164Word(owner23, 20);
            Level46_87164KeepCompleteWord(rawWord2);
            rawWord3 = Level46_87164Word(Level46_87164Data70328View1, 8);
            rawWord2 -= rawWord3;
            if (rawWord2 < 0)
                rawWord2 = -rawWord2;
            if (rawWord2 < 512) {
                Level46_87164Word(Level46_87164Data70328View1, 0x24) |= 7;
                Level46_87164SubtractVectorView1(originalFrame.vectorWork18,
                                                 Level46_87164Data70328View1, twelveByteRecord16);
                Level46_87164Word(Level46_87164Data70328View1, 0x298) =
                    Level46_87164PlanarHeadingLookupView1(originalFrame.vectorWork18[0],
                                                          originalFrame.vectorWork18[1], 0);
            }
        }
        rawAddressOrWord25 = originalFrame.privateRecord38;
        Level46_87164Call1BA30View1(owner23 + 12,
                                    Level46_87164SignedHalfword(rawAddressOrWord25, 0) + 200, 1, 0,
                                    0x10000, owner23);
        rawAddressOrWord25 = originalFrame.privateRecord38;
        if (Level46_87164SignedHalfword(rawAddressOrWord25, 0) <= 3072)
            goto Level46_87164UseHeldPrivateRecord;
        Level46_87164SignedHalfword(rawAddressOrWord25, 0) = 3072;
        Level46_87164Byte(owner23, 0x48) = 2;
    }
    rawAddressOrWord25 = originalFrame.privateRecord38;
Level46_87164UseHeldPrivateRecord:
    originalFrame.phaseWord78 = 0;
    originalFrame.pointArray50 = ({
        rawAddressOrWord25 = Level46_87164Pointer(rawAddressOrWord25, 4);
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        rawAddressOrWord25;
    });
    rawAddressOrWord25 = originalFrame.privateRecord38;
    originalFrame.signedHalfword48 = ({
        rawAddressOrWord25 =
            (unsigned char*)(int)Level46_87164SignedHalfword(rawAddressOrWord25, 0);
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        (int)rawAddressOrWord25;
    });
    rawAddressOrWord25 = originalFrame.pointArray50;
    outerIndex21 = 0;
    originalFrame.header58 = rawAddressOrWord25 + 0x43C;
    rawAddressOrWord25 = originalFrame.pointArray50;
    baseIndexOrHalfword20 = 0;
    originalFrame.indexArray60 = rawAddressOrWord25 + 0x47C;
    do {
        argumentWord4 = Level46_87164Byte(owner23, 0x46);
        Level46_87164KeepCompleteWord(argumentWord4);
        rawAddressOrWord25 =
            (unsigned char*)Level46_87164Field(&originalFrame.phaseWord78, volatile int*, 0);
        argumentWord4 += (int)rawAddressOrWord25;
        rawWord3 = (argumentWord4 & 255) << 1;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord3, "$25");
        rawAddressOrWord25 = (unsigned char*)Level46_87164Table65920;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        rawWord2 = rawWord3 + (int)rawAddressOrWord25;
        Level46_87164KeepCompleteWord(rawWord2);
        rawWord2 = *(short*)rawWord2;
        rawAddressOrWord25 = (unsigned char*)originalFrame.signedHalfword48;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        innerIndex17 = 0;
        angleOrTableAddress18 = 0;
        rawAddressOrWord25 = (unsigned char*)Level46_87164Table658A0;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        rawWord3 = rawWord3 + (int)rawAddressOrWord25;
        Level46_87164KeepCompleteWord(rawWord3);
        rawWord2 = *(short*)rawWord3;
        __asm__("" : "=l"(completeProductLow) : "x"(completeSignedProduct), "r"(rawWord2));
        argumentWord5 = completeProductLow;
        Level46_87164KeepCompleteWord(argumentWord5);
        rawAddressOrWord25 = (unsigned char*)originalFrame.signedHalfword48;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
        argumentWord4 += 64;
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        argumentWord4 &= 255;
        argumentWord4 <<= 1;
        retainedOffset = argumentWord5 >> 12;
        rawAddressOrWord25 = originalFrame.privateRecord38;
        halfwordOrTableAddress19 = Level46_87164SignedHalfword(rawAddressOrWord25, 2);
        rawAddressOrWord25 = (unsigned char*)Level46_87164Table658A0;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        rawAddressOrWord25 = (unsigned char*)(argumentWord4 + (int)rawAddressOrWord25);
        originalFrame.table658A0_68 = (short*)rawAddressOrWord25;
        rawAddressOrWord25 = (unsigned char*)Level46_87164Table65920;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        rawAddressOrWord25 = (unsigned char*)(argumentWord4 + (int)rawAddressOrWord25);
        originalFrame.table65920_70 = (short*)rawAddressOrWord25;
        __asm__(""
                : "=l"(completeProductLow)
                : "x"(completeSignedProduct), "m"(originalFrame.table65920_70));
        rawWord3 = completeProductLow;
        Level46_87164KeepCompleteWord(rawWord3);
        retainedOffset22 = rawWord3 >> 12;
        do {
            rawWord3 = (angleOrTableAddress18 & 255) << 1;
            rawAddressOrWord25 = (unsigned char*)Level46_87164Table65920;
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = rawWord3 + (int)rawAddressOrWord25;
            originalFrame.vectorWork18[0] = 0;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "m"(originalFrame.vectorWork18[0]));
            rawWord2 = *(short*)rawWord2;
            rawAddressOrWord25 = (unsigned char*)Level46_87164CompleteSignedProductLow(
                rawWord2, halfwordOrTableAddress19);
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            argumentWord4 = (int)rawAddressOrWord25 >> 12;
            originalFrame.vectorWork18[1] = argumentWord4;
            rawAddressOrWord25 = (unsigned char*)Level46_87164Table658A0;
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord3 = rawWord3 + (int)rawAddressOrWord25;
            Level46_87164KeepCompleteWord(rawWord3);
            rawWord2 = *(short*)rawWord3;
            rawAddressOrWord25 = (unsigned char*)Level46_87164CompleteSignedProductLow(
                rawWord2, halfwordOrTableAddress19);
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            rawAddressOrWord25 = (unsigned char*)originalFrame.table658A0_68;
            originalFrame.vectorWork18[2] = rawWord2;
            rawWord2 = *(short*)rawAddressOrWord25;
            completeSignedProduct = (long long)argumentWord4 * (long long)rawWord2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord3 = baseIndexOrHalfword20 + innerIndex17;
            rawAddressOrWord25 = originalFrame.pointArray50;
            __asm__ volatile("" : "=r"(rawWord3) : "0"(rawWord3), "m"(originalFrame.pointArray50));
            rawWord2 = rawWord3 * 12;
            Level46_87164KeepCompleteWord(rawWord2);
            twelveByteRecord16 = rawAddressOrWord25 + rawWord2;
            Level46_87164KeepCompleteWord(twelveByteRecord16);
            __asm__(""
                    : "=l"(completeProductLow)
                    : "x"(completeSignedProduct), "r"(twelveByteRecord16));
            rawAddressOrWord25 = (unsigned char*)completeProductLow;
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = -(int)rawAddressOrWord25;
            rawWord2 >>= 12;
            Level46_87164Word(twelveByteRecord16, 0) = rawWord2;
            rawAddressOrWord25 = (unsigned char*)originalFrame.table65920_70;
            rawWord2 = originalFrame.vectorWork18[1];
            rawWord3 = *(short*)rawAddressOrWord25;
            completeSignedProduct = (long long)rawWord2 * (long long)rawWord3;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            argumentWord5 = (int)owner23 + 12;
            argumentWord4 = (int)twelveByteRecord16;
            __asm__(""
                    : "=l"(completeProductLow)
                    : "x"(completeSignedProduct), "r"(argumentWord4), "r"(argumentWord5));
            rawAddressOrWord25 = (unsigned char*)completeProductLow;
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            Level46_87164Word(twelveByteRecord16, 4) = rawWord2;
            rawWord2 = originalFrame.vectorWork18[2];
            argumentWord6 = (int)twelveByteRecord16;
            Level46_87164Word(twelveByteRecord16, 8) = rawWord2;
            Level46_87164AddVectorView1((void*)argumentWord4, (void*)argumentWord5,
                                        (void*)argumentWord6);
            rawWord2 = Level46_87164Word(twelveByteRecord16, 0);
            rawWord3 = Level46_87164Word(twelveByteRecord16, 4);
            rawWord2 += retainedOffset;
            rawWord3 += retainedOffset22;
            Level46_87164Word(twelveByteRecord16, 0) = rawWord2;
            Level46_87164Word(twelveByteRecord16, 4) = rawWord3;
            if (Level46_87164Byte(owner23, 0x48) == 1 && !innerIndex17) {
                argumentWord4 = 1;
                Level46_87164KeepCompleteWord(argumentWord4);
                Level46_87164KeepCompleteWord(innerIndex17);
                argumentWord5 = 60;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
                argumentWord6 = (int)twelveByteRecord16;
                argumentWord7 = (int)originalFrame.particleWords28;
                MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentWord6, argumentWord7, "$3");
                rawWord3 = (int)Level46_87164DataSpawnParticleView1;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord3, "$2");
                rawWord2 = 2;
                originalFrame.particleWords28[0] = 0;
                originalFrame.particleWords28[1] = 0;
                originalFrame.particleWords28[2] = rawWord2;
                rawWord3 = ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6,
                                                 argumentWord7);
                Level46_87164KeepCompleteWord(rawWord3);
                if (rawWord3) {
                    rawWord2 = 40;
                    Level46_87164Byte(rawWord3, 10) = rawWord2;
                }
            }
            innerIndex17++;
            angleOrTableAddress18 += 42;
        } while (innerIndex17 < 6);
        baseIndexOrHalfword20 += 6;
        outerIndex21++;
        rawAddressOrWord25 =
            (unsigned char*)Level46_87164Field(&originalFrame.phaseWord78, volatile int*, 0);
        rawAddressOrWord25 += 17;
        originalFrame.phaseWord78 = (int)rawAddressOrWord25;
    } while (outerIndex21 < 16);
    outerIndex21 = 0;
    rawWord9 = 0x2AAAAAAB;
    Level46_87164KeepCompleteWord(rawWord9);
    rawWord8 = (int)0xB60B60B7;
    Level46_87164KeepCompleteWord(rawWord8);
    argumentWord7 = 0;
    rawAddressOrWord25 = originalFrame.pointArray50;
    Level46_87164Word(rawAddressOrWord25, 0x438) = -1;
    rawAddressOrWord25 = originalFrame.header58;
    Level46_87164Byte(rawAddressOrWord25, 0) = 25;
    Level46_87164Byte(rawAddressOrWord25, 1) = 25;
    Level46_87164Byte(rawAddressOrWord25, 2) = 50;
    do {
        innerIndex17 = 0;
        do {
            rawWord2 = innerIndex17 + 1;
            completeSignedProduct = (long long)rawWord2 * (long long)rawWord9;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord3 = argumentWord7 + innerIndex17;
            argumentWord6 = innerIndex17 + 6;
            innerIndex17 = rawWord2;
            argumentWord5 = rawWord3 * 8;
            argumentWord6 = argumentWord7 + argumentWord6;
            rawAddressOrWord25 = originalFrame.indexArray60;
            rawWord2 = innerIndex17 >> 31;
            argumentWord5 = (int)rawAddressOrWord25 + argumentWord5;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "r"(argumentWord5));
            rawWord10 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord10);
            Level46_87164Byte(argumentWord5, 0) = rawWord3;
            Level46_87164Byte(argumentWord5, 4) = 0;
            __asm__(""
                    : "=r"(argumentWord6)
                    : "0"(argumentWord6), "r"(rawWord10), "m"(Level46_87164Byte(argumentWord5, 4)));
            completeSignedProduct = (long long)argumentWord6 * (long long)rawWord8;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            Level46_87164Byte(argumentWord5, 5) = 0;
            Level46_87164Byte(argumentWord5, 6) = 0;
            Level46_87164Byte(argumentWord5, 7) = 0;
            __asm__ volatile(""
                             : "=r"(rawWord2)
                             : "0"(rawWord2), "m"(Level46_87164Byte(argumentWord5, 5)),
                               "m"(Level46_87164Byte(argumentWord5, 6)),
                               "m"(Level46_87164Byte(argumentWord5, 7)));
            rawWord2 = rawWord10 - rawWord2;
            argumentWord4 = rawWord2 * 6;
            argumentWord4 = innerIndex17 - argumentWord4;
            rawWord2 = argumentWord7 + argumentWord4;
            argumentWord4 += 6;
            argumentWord4 = argumentWord7 + argumentWord4;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "r"(argumentWord4));
            rawWord3 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord3);
            Level46_87164Byte(argumentWord5, 1) = rawWord2;
            rawWord2 = rawWord3 + argumentWord6;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord3));
            completeSignedProduct = (long long)argumentWord4 * (long long)rawWord8;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 >>= 6;
            rawWord3 = argumentWord6 >> 31;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord6 -= rawWord2;
            rawWord3 = argumentWord4 >> 31;
            Level46_87164Byte(argumentWord5, 2) = argumentWord6;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "m"(Level46_87164Byte(argumentWord5, 2)));
            rawWord10 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord10);
            rawWord2 = rawWord10 + argumentWord4;
            rawWord2 >>= 6;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord4 -= rawWord2;
            Level46_87164Byte(argumentWord5, 3) = argumentWord4;
        } while (innerIndex17 < 6);
        outerIndex21++;
        argumentWord7 += 6;
    } while (outerIndex21 < 15);
    Level46_87164Word(rawAddressOrWord25, 0x2D0) = -1;
    rawAddressOrWord25 = originalFrame.privateRecord38;
    if (!Level46_87164Word(rawAddressOrWord25, 8)) {
        argumentWord4 = (int)originalFrame.pointArray50;
        argumentWord5 = (int)originalFrame.header58;
        argumentWord6 = (int)originalFrame.indexArray60;
        rawAddressOrWord25 = originalFrame.linkedOwner40;
        rawWord2 = (int)Level46_87164Call50B00View1(argumentWord4, argumentWord5, argumentWord6,
                                                    (int)rawAddressOrWord25 + 12, 1);
        rawAddressOrWord25 = originalFrame.privateRecord38;
        Level46_87164Word(rawAddressOrWord25, 8) = rawWord2;
    }
    outerIndex21 = 0;
    table658A0OrMagic13 = Level46_87164Table658A0;
    table65920Address14 = Level46_87164Table65920;
    rawAddressOrWord25 = originalFrame.privateRecord38;
    retainedOffset22 = 0;
    rawWord2 = Level46_87164Word(rawAddressOrWord25, 4);
    rawWord11 = 0;
    recordArrayAddress15 = (unsigned char*)rawWord2 + 0x758;
    headerAddress12 = (unsigned char*)rawWord2 + 0xB94;
    indexArrayAddress24 = (unsigned char*)rawWord2 + 0xBD4;
    Level46_87164KeepCompleteWord(indexArrayAddress24);
    do {
        rawWord3 = Level46_87164Data6C640View1;
        rawAddressOrWord25 = originalFrame.privateRecord38;
        rawWord2 = rawWord3 * 20;
        rawWord2 = rawWord11 + rawWord2;
        rawWord2 = (rawWord2 & 255) << 1;
        rawWord2 += (int)table658A0OrMagic13;
        rawWord3 = *(short*)rawWord2;
        rawWord2 = Level46_87164SignedHalfword(rawAddressOrWord25, 0x16);
        completeSignedProduct = (long long)rawWord3 * (long long)rawWord2;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        argumentWord4 = Level46_87164Byte(owner23, 0x46);
        Level46_87164KeepCompleteWord(argumentWord4);
        rawAddressOrWord25 = (unsigned char*)originalFrame.signedHalfword48;
        Level46_87164KeepCompleteWord(rawAddressOrWord25);
        rawWord2 = outerIndex21 * 17;
        Level46_87164KeepCompleteWord(rawWord2);
        argumentWord4 += rawWord2;
        rawWord3 = (argumentWord4 & 255) << 1;
        rawWord2 = rawWord3 + (int)table658A0OrMagic13;
        Level46_87164KeepCompleteWord(rawWord2);
        __asm__("" : "=l"(completeProductLow) : "x"(completeSignedProduct), "r"(rawWord2));
        argumentWord6 = completeProductLow;
        Level46_87164KeepCompleteWord(argumentWord6);
        rawWord2 = *(short*)rawWord2;
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        rawWord3 = rawWord3 + (int)table65920Address14;
        Level46_87164KeepCompleteWord(rawWord3);
        __asm__("" : "=l"(completeProductLow) : "x"(completeSignedProduct), "r"(rawWord3));
        argumentWord5 = completeProductLow;
        Level46_87164KeepCompleteWord(argumentWord5);
        rawWord2 = *(short*)rawWord3;
        __asm__ volatile("" ::: "$17", "memory");
        innerIndex17 = 0;
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        halfwordOrTableAddress19 = (int)table658A0OrMagic13;
        angleOrTableAddress18 = (int)table65920Address14;
        argumentWord4 = ((argumentWord4 + 64) & 255) << 1;
        rawWord10 = argumentWord4 + (int)table658A0OrMagic13;
        rawWord9 = argumentWord4 + (int)table65920Address14;
        rawWord8 = argumentWord6 >> 12;
        rawAddressOrWord25 = originalFrame.privateRecord38;
        argumentWord7 = argumentWord5 >> 12;
        baseIndexOrHalfword20 = Level46_87164SignedHalfword(rawAddressOrWord25, 0x14);
        __asm__(""
                : "=l"(completeProductLow)
                : "x"(completeSignedProduct), "r"(baseIndexOrHalfword20));
        rawWord3 = completeProductLow;
        Level46_87164KeepCompleteWord(rawWord3);
        retainedOffset = rawWord3 >> 12;
        do {
            originalFrame.vectorWork18[0] = 0;
            rawWord2 = *(short*)angleOrTableAddress18;
            rawAddressOrWord25 = (unsigned char*)Level46_87164CompleteSignedProductLow(
                rawWord2, baseIndexOrHalfword20);
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord3 = (int)rawAddressOrWord25 >> 12;
            originalFrame.vectorWork18[1] = rawWord3;
            rawWord2 = *(short*)halfwordOrTableAddress19;
            rawAddressOrWord25 = (unsigned char*)Level46_87164CompleteSignedProductLow(
                rawWord2, baseIndexOrHalfword20);
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            originalFrame.vectorWork18[2] = rawWord2;
            rawWord2 = *(short*)rawWord10;
            completeSignedProduct = (long long)rawWord3 * (long long)rawWord2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 = retainedOffset22 + innerIndex17;
            Level46_87164KeepCompleteWord(rawWord2);
            twelveByteRecord16 = recordArrayAddress15 + rawWord2 * 12;
            Level46_87164KeepCompleteWord(twelveByteRecord16);
            __asm__(""
                    : "=l"(completeProductLow)
                    : "x"(completeSignedProduct), "r"(twelveByteRecord16));
            rawAddressOrWord25 = (unsigned char*)completeProductLow;
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = -(int)rawAddressOrWord25;
            rawWord2 >>= 12;
            Level46_87164Word(twelveByteRecord16, 0) = rawWord2;
            rawWord3 = *(short*)rawWord9;
            rawWord2 = originalFrame.vectorWork18[1];
            completeSignedProduct = (long long)rawWord2 * (long long)rawWord3;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            __asm__ volatile("" ::"x"(completeSignedProduct) : "$5");
            argumentWord5 = (int)owner23 + 12;
            MATCHING_OBSERVE_VOLATILE(argumentWord5);
            angleOrTableAddress18 += 84;
            argumentWord4 = (int)twelveByteRecord16;
            argumentWord6 = (int)twelveByteRecord16;
            __asm__(""
                    : "=l"(completeProductLow)
                    : "x"(completeSignedProduct), "r"(argumentWord4), "r"(argumentWord6),
                      "r"(angleOrTableAddress18));
            rawAddressOrWord25 = (unsigned char*)completeProductLow;
            Level46_87164KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            Level46_87164Word(twelveByteRecord16, 4) = rawWord2;
            rawWord2 = originalFrame.vectorWork18[2];
            __asm__ volatile(""
                             : "=r"(innerIndex17)
                             : "0"(innerIndex17), "m"(originalFrame.vectorWork18[2]));
            innerIndex17++;
            MATCHING_OBSERVE_VOLATILE(innerIndex17);
            Level46_87164Word(twelveByteRecord16, 8) = rawWord2;
            originalFrame.savedCallerWords80[0] = argumentWord7;
            originalFrame.savedCallerWords80[1] = rawWord8;
            originalFrame.savedCallerWords80[2] = rawWord9;
            originalFrame.savedCallerWords80[3] = rawWord10;
            originalFrame.savedCallerWords80[4] = rawWord11;
            originalFrame.savedCallerWords80[5] = (int)headerAddress12;
            originalFrame.savedCallerWords80[6] = (int)table658A0OrMagic13;
            originalFrame.savedCallerWords80[7] = (int)table65920Address14;
            originalFrame.savedCallerWords80[8] = (int)recordArrayAddress15;
            originalFrame.savedCallerWords80[9] = (int)indexArrayAddress24;
            Level46_87164AddVectorView2((void*)argumentWord4, (void*)argumentWord5,
                                        (void*)argumentWord6);
            rawWord2 = Level46_87164Word(twelveByteRecord16, 0);
            rawWord2 += retainedOffset;
            Level46_87164Word(twelveByteRecord16, 0) = rawWord2;
            rawWord2 = Level46_87164Word(twelveByteRecord16, 4);
            argumentWord7 =
                Level46_87164Field(&originalFrame.savedCallerWords80[0], volatile int*, 0);
            rawWord3 = Level46_87164Word(twelveByteRecord16, 8);
            rawWord2 += argumentWord7;
            Level46_87164Word(twelveByteRecord16, 4) = rawWord2;
            rawWord8 = Level46_87164Field(&originalFrame.savedCallerWords80[1], volatile int*, 0);
            __asm__ volatile("" ::"m"(originalFrame.savedCallerWords80[1]) : "$2");
            rawWord2 = innerIndex17 < 6;
            Level46_87164KeepCompleteWord(rawWord2);
            rawWord3 += rawWord8;
            Level46_87164Word(twelveByteRecord16, 8) = rawWord3;
            rawWord9 = Level46_87164Field(&originalFrame.savedCallerWords80[2], volatile int*, 0);
            rawWord10 = Level46_87164Field(&originalFrame.savedCallerWords80[3], volatile int*, 0);
            rawWord11 = Level46_87164Field(&originalFrame.savedCallerWords80[4], volatile int*, 0);
            headerAddress12 = (unsigned char*)Level46_87164Field(
                &originalFrame.savedCallerWords80[5], volatile int*, 0);
            table658A0OrMagic13 =
                (short*)Level46_87164Field(&originalFrame.savedCallerWords80[6], volatile int*, 0);
            table65920Address14 =
                (short*)Level46_87164Field(&originalFrame.savedCallerWords80[7], volatile int*, 0);
            recordArrayAddress15 = (unsigned char*)Level46_87164Field(
                &originalFrame.savedCallerWords80[8], volatile int*, 0);
            indexArrayAddress24 = (unsigned char*)Level46_87164Field(
                &originalFrame.savedCallerWords80[9], volatile int*, 0);
            __asm__(""
                    : "=r"(halfwordOrTableAddress19)
                    : "0"(halfwordOrTableAddress19), "r"(indexArrayAddress24));
            halfwordOrTableAddress19 += 84;
        } while (rawWord2);
        MATCHING_BARRIER_VOLATILE("$2");
        retainedOffset22 += 6;
        outerIndex21++;
        rawWord2 = outerIndex21 < 16;
        Level46_87164KeepCompleteWord(rawWord2);
        rawWord11 += 80;
    } while (rawWord2);
    MATCHING_BARRIER_VOLATILE("$2");
    outerIndex21 = 0;
    table658A0OrMagic13 = (short*)(int)0xB60B60B7;
    Level46_87164KeepCompleteWord(table658A0OrMagic13);
    rawWord11 = 2;
    rawWord10 = 0;
    Level46_87164Word(recordArrayAddress15, 0x438) = -1;
    Level46_87164Byte(headerAddress12, 0) = 150;
    Level46_87164Byte(headerAddress12, 1) = 150;
    Level46_87164Byte(headerAddress12, 2) = 150;
    Level46_87164Byte(headerAddress12, 4) = 70;
    Level46_87164Byte(headerAddress12, 5) = 70;
    Level46_87164Byte(headerAddress12, 6) = 70;
    Level46_87164Byte(headerAddress12, 8) = 20;
    Level46_87164Byte(headerAddress12, 9) = 20;
    Level46_87164Byte(headerAddress12, 10) = 20;
    do {
        innerIndex17 = 0;
        do {
            rawWord2 = 0x55555556;
            completeSignedProduct = (long long)innerIndex17 * (long long)rawWord2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 = 0x2AAA0000;
            __asm__("" : "=h"(completeProductHigh) : "x"(completeSignedProduct));
            rawWord8 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord8);
            Level46_87164KeepCompleteWord(rawWord2);
            rawWord2 |= 0xAAAB;
            argumentWord4 = innerIndex17 + 1;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord8));
            completeSignedProduct = (long long)argumentWord4 * (long long)rawWord2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord3 = rawWord10 + innerIndex17;
            argumentWord5 = innerIndex17 + 6;
            argumentWord5 = rawWord10 + argumentWord5;
            rawWord2 = rawWord3 * 8;
            argumentWord6 = (int)indexArrayAddress24 + rawWord2;
            rawWord2 = innerIndex17 >> 31;
            argumentWord7 = rawWord8 - rawWord2;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "r"(argumentWord7));
            rawWord9 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord9);
            rawWord2 = argumentWord7 * 3;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(rawWord9));
            completeSignedProduct = (long long)argumentWord5 * (long long)(int)table658A0OrMagic13;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            argumentWord7 = innerIndex17 - rawWord2;
            Level46_87164Byte(argumentWord6, 0) = rawWord3;
            rawWord3 = argumentWord4 >> 31;
            rawWord3 = rawWord9 - rawWord3;
            rawWord2 = rawWord3 * 6;
            argumentWord4 -= rawWord2;
            rawWord2 = rawWord10 + argumentWord4;
            argumentWord4 += 6;
            argumentWord4 = rawWord10 + argumentWord4;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "r"(argumentWord4));
            rawWord8 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord8);
            rawWord3 = argumentWord5 >> 31;
            Level46_87164Byte(argumentWord6, 1) = rawWord2;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord8));
            completeSignedProduct = (long long)argumentWord4 * (long long)(int)table658A0OrMagic13;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 = rawWord8 + argumentWord5;
            rawWord2 >>= 6;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord5 -= rawWord2;
            rawWord3 = argumentWord4 >> 31;
            Level46_87164Byte(argumentWord6, 2) = argumentWord5;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "m"(Level46_87164Byte(argumentWord6, 2)));
            rawWord9 = completeProductHigh;
            Level46_87164KeepCompleteWord(rawWord9);
            rawWord2 = rawWord9 + argumentWord4;
            rawWord2 >>= 6;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord4 -= rawWord2;
            Level46_87164Byte(argumentWord6, 3) = argumentWord4;
            if (!argumentWord7) {
                Level46_87164Byte(argumentWord6, 4) = 0;
                Level46_87164Byte(argumentWord6, 5) = rawWord11;
                Level46_87164Byte(argumentWord6, 6) = 0;
                Level46_87164Byte(argumentWord6, 7) = rawWord11;
            } else if (argumentWord7 == 1) {
                Level46_87164Byte(argumentWord6, 4) = rawWord11;
                Level46_87164Byte(argumentWord6, 5) = rawWord11;
                Level46_87164Byte(argumentWord6, 6) = rawWord11;
                Level46_87164Byte(argumentWord6, 7) = rawWord11;
            } else if (argumentWord7 == rawWord11) {
                Level46_87164Byte(argumentWord6, 4) = rawWord11;
                Level46_87164Byte(argumentWord6, 5) = 0;
                Level46_87164Byte(argumentWord6, 6) = rawWord11;
                Level46_87164Byte(argumentWord6, 7) = 0;
            }
            innerIndex17++;
        } while (innerIndex17 < 6);
        outerIndex21++;
        rawWord10 += 6;
    } while (outerIndex21 < 15);
    Level46_87164Word(indexArrayAddress24, 0x2D0) = -1;
    rawAddressOrWord25 = originalFrame.privateRecord38;
    if (!Level46_87164Word(rawAddressOrWord25, 12)) {
        argumentWord4 = (int)recordArrayAddress15;
        argumentWord5 = (int)headerAddress12;
        argumentWord6 = (int)indexArrayAddress24;
        rawAddressOrWord25 = originalFrame.linkedOwner40;
        rawWord2 = (int)Level46_87164Call50B00View2(argumentWord4, argumentWord5, argumentWord6,
                                                    (int)rawAddressOrWord25 + 12, 1);
        rawAddressOrWord25 = originalFrame.privateRecord38;
        Level46_87164Word(rawAddressOrWord25, 12) = rawWord2;
    }
    if (Level46_87164Byte(owner23, 0x48) == 2) {
        rawAddressOrWord25 = originalFrame.privateRecord38;
        argumentWord4 = Level46_87164Word(rawAddressOrWord25, 8);
        if (argumentWord4) {
            Level46_87164Call50B88View1((void*)argumentWord4);
            rawAddressOrWord25 = originalFrame.privateRecord38;
        }
        argumentWord4 = Level46_87164Word(rawAddressOrWord25, 12);
        if (argumentWord4)
            Level46_87164Call50B88View2((void*)argumentWord4);
        Level46_87164DeleteMobyView1(owner23);
    }
}
#undef Level46_87164Field
#undef Level46_87164Word
#undef Level46_87164Pointer
#undef Level46_87164Byte
#undef Level46_87164SignedHalfword
#undef Level46_87164UnsignedHalfword
#undef Level46_87164KeepCompleteWord
#undef Level46_87164CompleteSignedProductLow

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * The original 401 instructions in each copy are the acceptance authority.
 * Preserve the 0x90-byte frame, signed table loads, byte offsets, wrapped
 * 32-bit products, arithmetic shifts, helper order and descriptor updates.
 * Empty constraints emit no opcodes and preserve original allocation/order.
 * Table meanings, physical units, full helper contracts and caller cadence
 * remain unresolved. No retail runtime completeness is claimed.
 * Falsifiable check: original linked words and every full retail binary hash.
 */
#define Actor84070Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor84070func_8001BA30() __asm__("func_8001BA30");
int Actor84070RandBetween() __asm__("func_8003636C");
int Actor84070AddVector() __asm__("func_8004F194");
int Actor84070func_80050B00() __asm__("func_80050B00");
int Actor84070func_80050B88() __asm__("func_80050B88");
int Actor84070DeleteMoby() __asm__("func_80055B18");
extern short Actor84070D_80065920[] __asm__("D_80065920");
extern short Actor84070D_800658A0[] __asm__("D_800658A0");
extern void* (*Actor84070SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_46_80087AE8(void* input) {
    register unsigned char* owner __asm__("$23") = input;
    struct {
        int sp18, sp1C, sp20, pad24, sp28, sp2C, sp30, pad34, sp38, pad3C;
        void* sp40;
        int pad44, sp48, pad4C;
        volatile short* volatile sp50;
        void* volatile sp54;
        volatile int sp58;
        short* volatile sp5C;
        void* sp60;
        int pad64;
    } frame;
    register short* table659 __asm__("$7");
    register short* table659Cursor __asm__("$21");
    register short* table658Cursor __asm__("$22");
    register short* shiftedTable659 __asm__("$10");
    register int value6 __asm__("$6");
    register int temp_a2_2 __asm__("$6");
    register int initialCondition __asm__("$2");
    int temp_v0_2;
    register int value3 __asm__("$3");
    register int temp_v1_3 __asm__("$3");
    register int temp_v1_4 __asm__("$3");
    register int* ownerWord0C __asm__("$16");
    register int value4 __asm__("$4");
    int temp_a0_3;
    register int value5 __asm__("$5");
    register int randomResult __asm__("$2");
    register int temp_v0_5 __asm__("$2");
    int temp_v0_6;
    register int scaledTable659 __asm__("$3");
    register int nextIndex8 __asm__("$3");
    register int nextIndex9 __asm__("$3");
    register int radiusWord __asm__("$4");
    register int innerIndex __asm__("$17");
    register int pointIndex __asm__("$18");
    register int columnCounter __asm__("$18");
    register int outerIndex __asm__("$19");
    register int descriptorCount __asm__("$19");
    register int tableByteOffset __asm__("$9");
    int var_v0;
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    register int nextDescriptorIndex __asm__("$5");
    register int descriptorFlag __asm__("$3");
    register int descriptorIndex __asm__("$17");
    register int headerValue __asm__("$3");
    register int temp_v0_3 __asm__("$2");
    void* createdPart;
    register void* state __asm__("$20");
    void* previousPart;
    register void* descriptorCursor __asm__("$4");
    short* table658;
    register int work2 __asm__("$2");
    int work12;
    int initialWord;
    register int work3 __asm__("$3");
    register short* raw2 __asm__("$2");
    register int product13 __asm__("$13");
    register int value12 __asm__("$12");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    register void* pointCursor __asm__("$16");
    register void* headerBytes __asm__("$8");
    register void* pointRecords __asm__("$11");

    MATCHING_KEEP(owner);
    state = Actor84070Field(owner, void**, 0);
    frame.sp38 = *Actor84070Field(state, int**, 0x10);
    Actor84070Field(owner, unsigned char*, 0x41) = 0;
    Actor84070Field(owner, unsigned char*, 0x4C) = 0;
    Actor84070Field(owner, unsigned char*, 0x4D) = 0;
    initialCondition = Actor84070Field(state, short*, 2);
    if (initialCondition != 0) {
        initialCondition = initialCondition < 10;
        goto initialBound;
    }
    initialCondition = initialCondition < 10;
    MATCHING_KEEP(initialCondition);
    ownerWord0C = owner + 12;
    Actor84070func_8001BA30(ownerWord0C, 1000, 1, 0, 0x40000, owner);
    initialCondition = Actor84070Field(state, short*, 2);
    if (initialCondition != 0) {
        initialCondition = initialCondition < 10;
        goto initialBound;
    }
    initialCondition = initialCondition < 10;
    MATCHING_KEEP(initialCondition);
    Actor84070SpawnParticle(10, 70, ownerWord0C, (void*)30);
    initialCondition = Actor84070Field(state, short*, 2) < 10;
initialBound:
    if (initialCondition) {
        randomResult = Actor84070RandBetween(0, 0x400);
        value3 = Actor84070Field(owner, int*, 0xC) - 0x200;
        MATCHING_KEEP(value3);
        value3 += randomResult;
        MATCHING_KEEP(value3);
        frame.sp18 = value3;
        randomResult = Actor84070RandBetween(0, 0x400);
        value3 = Actor84070Field(owner, int*, 0x10) - 0x200;
        MATCHING_KEEP(value3);
        value3 += randomResult;
        MATCHING_KEEP(value3);
        frame.sp1C = value3;
        randomResult = Actor84070RandBetween(0, 0x100);
        value3 = Actor84070Field(owner, int*, 0x14);
        value3 += randomResult;
        frame.sp20 = value3;
        Actor84070SpawnParticle(2, 0x42, &frame.sp18, (int*)1);
    }
    pointIndex = 0;
    outerIndex = 0;
    table659 = &Actor84070D_80065920;
    table658 = Actor84070D_800658A0;
    MATCHING_KEEP(table658);
    pointRecords = Actor84070Field(state, void**, 4);
    __asm__(""
            : "=r"(work2), "=r"(work3), "=r"(value4), "=r"(value5), "=r"(value6),
              "=r"(tableByteOffset), "=r"(shiftedTable659));
    initialWord = Actor84070Field(state, short*, 0);
    headerBytes = pointRecords + 0x604;
    __asm__(""
            : "=r"(initialWord)
            : "0"(initialWord), "r"(work2), "r"(work3), "r"(value4), "r"(value5), "r"(value6),
              "r"(tableByteOffset), "r"(shiftedTable659), "r"(headerBytes));
    frame.sp48 = initialWord;
    initialWord = (int)pointRecords + 0x644;
    __asm__(""
            : "=r"(initialWord)
            : "0"(initialWord), "r"(work2), "r"(work3), "r"(value4), "r"(value5), "r"(value6),
              "r"(tableByteOffset), "r"(shiftedTable659), "r"(headerBytes));
    frame.sp40 = (void*)initialWord;
    do {
        innerIndex = 0;
        work2 = outerIndex << 5;
        MATCHING_KEEP(work2);
        tableByteOffset = work2 & 0x1E0;
        shiftedTable659 = (short*)(tableByteOffset + (int)table659);
        table658Cursor = table658;
        table659Cursor = table659;
        work2 = pointIndex * 12;
        MATCHING_KEEP(work2);
        pointCursor = (void*)(work2 + (int)pointRecords);
    loop_7:
        value3 = Actor84070Field(state, short*, 2);
        if (value3 != 0) {
            if (value3 == 1) {
                radiusWord = 0x190;
                goto block_14;
            }
            if (!(innerIndex & 1))
                goto frameRadius;
            work2 = value3 < 4;
            MATCHING_KEEP(work2);
            if (!work2) {
                radiusWord = 0x1F4;
                goto block_14;
            }
        frameRadius:
            radiusWord = frame.sp48;
            frame.sp28 = 0;
        } else {
            radiusWord = 0x1F4;
        block_14:
            frame.sp28 = 0;
        }
        work2 = *table659Cursor;
        MATCHING_KEEP(work2);
        value12 = work2 * radiusWord;
        MATCHING_KEEP(value12);
        scaledTable659 = value12 >> 12;
        frame.sp2C = scaledTable659;
        work2 = *table658Cursor;
        MATCHING_KEEP(work2);
        value12 = work2 * radiusWord;
        MATCHING_KEEP(value12);
        work2 = value12 >> 12;
        MATCHING_KEEP(work2);
        frame.sp30 = work2;
        raw2 = (short*)(tableByteOffset + (int)table658);
        MATCHING_KEEP(raw2);
        work2 = *raw2;
        MATCHING_KEEP(work2);
        value12 = scaledTable659 * work2;
        MATCHING_KEEP(value12);
        work2 = (-value12) >> 12;
        MATCHING_KEEP(work2);
        Actor84070Field(pointCursor, int*, 0) = work2;
        temp_v1_3 = *shiftedTable659;
        work2 = frame.sp2C;
        MATCHING_KEEP2(temp_v1_3, work2);
        value12 = work2 * temp_v1_3;
        MATCHING_KEEP(value12);
        work2 = value12 >> 12;
        MATCHING_KEEP(work2);
        Actor84070Field(pointCursor, int*, 4) = work2;
        value4 = frame.sp30;
        Actor84070Field(pointCursor, int*, 8) = value4;
        if (Actor84070Field(owner, int*, 0x44) & 0xFF00FF) {
            work2 = Actor84070Field(owner, unsigned char*, 0x44);
            MATCHING_KEEP(work2);
            work3 = work2 << 1;
            MATCHING_KEEP(work3);
            raw2 = (short*)(work3 + (int)table659);
            value6 = *raw2;
            MATCHING_KEEP(value6);
            work2 = Actor84070Field(pointCursor, int*, 0);
            MATCHING_KEEP(work2);
            work2 = work2 * value6;
            work3 = work3 + (int)table658;
            MATCHING_KEEP2(work2, work3);
            temp_v1_3 = *(short*)work3;
            MATCHING_KEEP(temp_v1_3);
            product13 = value4 * temp_v1_3;
            MATCHING_KEEP(product13);
            value4 = work2 - product13;
            MATCHING_KEEP(value4);
            value4 >>= 12;
            frame.sp28 = value4;
            value5 = Actor84070Field(pointCursor, int*, 4);
            frame.sp2C = value5;
            work2 = Actor84070Field(pointCursor, int*, 0);
            MATCHING_KEEP(work2);
            work3 = work2 * temp_v1_3;
            MATCHING_KEEP(work3);
            work2 = Actor84070Field(pointCursor, int*, 8);
            MATCHING_KEEP(work2);
            product13 = work2 * value6;
            MATCHING_KEEP(product13);
            work2 = (work3 + product13) >> 12;
            frame.sp30 = work2;
            work2 = (Actor84070Field(owner, unsigned char*, 0x46) + 128) & 255;
            MATCHING_KEEP(work2);
            work3 = work2 << 1;
            MATCHING_KEEP(work3);
            raw2 = (short*)(work3 + (int)table659);
            value6 = *raw2;
            MATCHING_KEEP(value6);
            work2 = value4 * value6;
            work3 = work3 + (int)table658;
            MATCHING_KEEP2(work2, work3);
            temp_v1_3 = *(short*)work3;
            MATCHING_KEEP(temp_v1_3);
            product13 = value5 * temp_v1_3;
            MATCHING_KEEP(product13);
            work2 = (work2 - product13) >> 12;
            Actor84070Field(pointCursor, int*, 0) = work2;
            work2 = frame.sp28;
            MATCHING_KEEP(work2);
            work3 = work2 * temp_v1_3;
            MATCHING_KEEP(work3);
            work2 = frame.sp2C;
            MATCHING_KEEP(work2);
            product13 = work2 * value6;
            MATCHING_KEEP(product13);
            work2 = (work3 + product13) >> 12;
            Actor84070Field(pointCursor, int*, 4) = work2;
            MATCHING_BARRIER_GNU_VOLATILE("memory");
            work2 = frame.sp30;
            MATCHING_KEEP(work2);
            Actor84070Field(pointCursor, int*, 8) = work2;
        }
        call4 = pointCursor;
        call5 = owner + 12;
        call6 = pointCursor;
        MATCHING_KEEP3(call4, call5, call6);
        frame.sp50 = table659;
        frame.sp54 = headerBytes;
        frame.sp58 = tableByteOffset;
        frame.sp5C = shiftedTable659;
        frame.sp60 = pointRecords;
        Actor84070AddVector(call4, call5, call6);
        pointCursor += 0xC;
        pointIndex += 1;
        table658Cursor += 0x10;
        innerIndex += 1;
        work2 = innerIndex < 8;
        MATCHING_KEEP(work2);
        table659 = (short*)frame.sp50;
        headerBytes = frame.sp54;
        tableByteOffset = frame.sp58;
        shiftedTable659 = frame.sp5C;
        pointRecords = *(void* volatile*)&frame.sp60;
        __asm__("" : "=r"(table659Cursor) : "0"(table659Cursor), "r"(pointRecords));
        table659Cursor += 0x10;
        if (work2) {
            goto loop_7;
        }
        outerIndex += 1;
    } while (outerIndex < 0x10);
    Actor84070Field(pointRecords, int*, 0x600) = -1;
    value3 = Actor84070Field(state, short*, 2);
    MATCHING_KEEP(value3);
    work2 = (value3 << 1) + value3;
    MATCHING_KEEP(work2);
    work2 = (work2 << 2) + value3;
    value3 = 255;
    MATCHING_KEEP2(work2, value3);
    headerValue = value3 - work2;
    MATCHING_KEEP(headerValue);
    work2 = 8;
    MATCHING_KEEP(work2);
    if (headerValue != work2) {
        work2 = headerValue < 5;
        goto descriptorBound;
    }
    work2 = headerValue < 5;
    MATCHING_KEEP(work2);
    headerValue = 15;
    MATCHING_KEEP(headerValue);
    work2 = headerValue < 5;
descriptorBound:
    descriptorIndex = 0;
    if (work2)
        headerValue = 5;
    columnCounter = 0;
    descriptorCount = 0;
    descriptorCursor = frame.sp40;
    Actor84070Field(headerBytes, unsigned char*, 0) = headerValue;
    Actor84070Field(headerBytes, unsigned char*, 1) = headerValue;
    Actor84070Field(headerBytes, unsigned char*, 2) = 0;
    Actor84070Field(headerBytes, unsigned char*, 4) = 0xFF;
    Actor84070Field(headerBytes, unsigned char*, 5) = 0xFF;
    Actor84070Field(headerBytes, unsigned char*, 6) = 0xFF;
    do {
        nextIndex8 = descriptorIndex + 8;
        var_v0_3 = nextIndex8;
        nextDescriptorIndex = descriptorIndex + 1;
        Actor84070Field(descriptorCursor, unsigned char*, 0) = descriptorIndex;
        Actor84070Field(descriptorCursor, unsigned char*, 1) = nextDescriptorIndex;
        if (nextIndex8 < 0) {
            var_v0_3 = descriptorIndex + 0x87;
        }
        work2 = nextIndex8 - ((var_v0_3 >> 7) << 7);
        MATCHING_KEEP(work2);
        Actor84070Field(descriptorCursor, unsigned char*, 2) = work2;
        nextIndex9 = descriptorIndex + 9;
        var_v0_4 = nextIndex9;
        if (nextIndex9 < 0) {
            var_v0_4 = descriptorIndex + 0x88;
        }
        descriptorIndex = nextDescriptorIndex;
        MATCHING_KEEP(descriptorIndex);
        work2 = nextIndex9 - ((var_v0_4 >> 7) << 7);
        MATCHING_KEEP(work2);
        Actor84070Field(descriptorCursor, unsigned char*, 3) = work2;
        work2 = Actor84070Field(state, short*, 2);
        __asm__("" : "=r"(columnCounter) : "0"(columnCounter), "r"(work2));
        columnCounter += 1;
        descriptorFlag = work2 < 4;
        MATCHING_KEEP(descriptorFlag);
        Actor84070Field(descriptorCursor, unsigned char*, 4) = descriptorFlag;
        Actor84070Field(descriptorCursor, unsigned char*, 5) = descriptorFlag;
        Actor84070Field(descriptorCursor, unsigned char*, 6) = descriptorFlag;
        Actor84070Field(descriptorCursor, unsigned char*, 7) = descriptorFlag;
        if (columnCounter >= 7) {
            descriptorIndex += 1;
            columnCounter = 0;
        }
        descriptorCount += 1;
        descriptorCursor += 8;
    } while (descriptorCount < 0x70);
    value12 = (int)frame.sp40;
    Actor84070Field((void*)value12, int*, 0x380) = -1;
    if (Actor84070Field(state, int*, 8) == 0) {
        call4 = pointRecords;
        call5 = headerBytes;
        call6 = frame.sp40;
        value12 = frame.sp38;
        Actor84070Field(state, int*, 8) =
            Actor84070func_80050B00(call4, call5, call6, value12 + 12, 1);
    }
    if (Actor84070Field(state, short*, 2) >= 7) {
        Actor84070Field(state, void**, 0xC) = 0;
    } else {
        frame.sp28 = 0;
        frame.sp2C = 0x28;
        frame.sp30 = 0;
        temp_v0_6 = Actor84070RandBetween(0, 0x14) + 0x36;
        frame.sp2C = (int)(Actor84070D_80065920[temp_v0_6] * 5) >> 9;
        frame.sp30 = (int)(Actor84070D_800658A0[temp_v0_6] * 5) >> 9;
        createdPart = Actor84070SpawnParticle(1, 0xD, owner + 0xC, &frame.sp28);
        previousPart = Actor84070Field(state, void**, 0xC);
        if (previousPart != 0) {
            Actor84070Field(previousPart, unsigned char*, 0xC) = 0xFF;
            Actor84070Field(previousPart, unsigned char*, 0xD) = 0xFF;
            Actor84070Field(previousPart, unsigned char*, 0xE) = 0xFF;
        }
        if (createdPart != 0) {
            Actor84070Field(state, void**, 0xC) = createdPart;
            Actor84070Field(createdPart, unsigned char*, 0xA) = 0xBE;
            Actor84070Field(createdPart, unsigned char*, 0xE) = 0xFF;
        }
    }
    Actor84070Field(state, short*, 2) =
        (short)((unsigned short)Actor84070Field(state, short*, 2) + 1);
    Actor84070Field(state, short*, 0) =
        (short)((unsigned short)Actor84070Field(state, short*, 0) + 0x50);
    if (Actor84070Field(state, short*, 2) < 21) {
        value12 = 0;
        MATCHING_KEEP(value12);
        if (!value12)
            goto done;
    }
    {
        temp_a0_3 = Actor84070Field(state, int*, 8);
        if (temp_a0_3 != 0) {
            Actor84070func_80050B88(temp_a0_3);
        }
        Actor84070DeleteMoby(owner);
    }
done:;
}

#undef Actor84070Field
