#include "matching.h"
#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "camera.h"
#include "savepoint.h"
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
void func_level_23_80075578(void* input) {
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
void func_level_23_800761D4(Moby* argument) {
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
void func_level_23_80076860(void* input) {
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
void func_level_23_80077DB0(Moby* moby) {
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
void func_level_23_80078070(Moby* argument) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0.
 * Original func_level_13_800781D0 and siblings:668 instructions,5 dispatch
 * targets and one alignment word; evidence4913. Raw field widths/offsets,
 * helper addresses and integer expressions follow original instructions.
 * Units, helper meanings, cadence and retail runtime parity unresolved.
 * Uninstalled candidate: every native/internal-target/table word and all
 * executable/overlay hashes required before acceptance. */
#define A4914F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define A4914W(p, o) A4914F(p, int*, o)
#define A4914B(p, o) A4914F(p, unsigned char*, o)
extern unsigned char A4914Player[] __asm__("D_80070328");
extern int A4914PX __asm__("D_80070328"), A4914PY __asm__("D_80070328 + 4");
extern int A4914PZ __asm__("D_80070328 + 8"), A4914P44 __asm__("D_80070328 + 0x44");
extern int A4914PB8 __asm__("D_80070328 + 0xB8");
extern int A4914P20C __asm__("D_80070328 + 0x20C");
extern unsigned char* A4914Models __asm__("D_8006C550");
extern int A4914Delta __asm__("D_8006C648"), A4914C590 __asm__("D_8006C590");
extern int A4914C74C __asm__("D_8006C74C"), A4914C578 __asm__("D_8006C578"),
    A4914C574 __asm__("D_8006C574");
extern int A4914NewButtons __asm__("D_8006E53C");
extern short A4914Cos[] __asm__("D_80065920"), A4914Sin[] __asm__("D_800658A0");
extern int (*A4914Callback)() __asm__("unk_ovlheader_80074330");
extern unsigned char* (*A4914Spawn)() __asm__("SpawnMoby");
extern int (*A4914Particle)() __asm__("SpawnParticle");
int A4914ApproximatePlanarDistance() __asm__("func_8004F334");
int A4914H37014() __asm__("func_80037014");
int A4914H2803C() __asm__("func_8002803C");
int A4914H27D60() __asm__("func_80027D60");
int A4914H2982C() __asm__("func_8002982C");
int A4914PlanarHeadingLookup() __asm__("func_8004E880");
int A4914AbsoluteByteAngleDelta() __asm__("func_8004F264");
int A4914CopyVector() __asm__("func_8004F178");
int A4914H527C4() __asm__("func_800527C4");
int A4914PlayMobySoundEvent() __asm__("func_8003BABC");
int A4914SubtractVector() __asm__("func_8004F1C8");
int A4914ShiftVectorRightTowardZero() __asm__("func_8004F110");
int A4914MultiplyVectorGpfSf0() __asm__("func_8004F1FC");
int A4914DivideVector() __asm__("func_8004F228");
int A4914AddVector() __asm__("func_8004F194");
int A4914TurnMobyTowardHeading() __asm__("func_8003585C");
int A4914H492DC() __asm__("func_800492DC");
int A4914RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int A4914DeleteMoby() __asm__("func_80055B18");
int A4914H28154() __asm__("func_80028154");
int A4914H368A4() __asm__("func_800368A4");
int A4914Rand() __asm__("rand");
void func_level_23_80078590(unsigned char* input) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int arg4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    register int counter16 __asm__("$16");
    register int* vector17 __asm__("$17");
    register unsigned char* private18 __asm__("$18");
    register unsigned char* owner19 __asm__("$19");
    register int saved20 __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int saved23 __asm__("$23");
    struct {
        int first[4], second[4], third[4], fourth[4];
    } frame;
    owner19 = input;
    private18 = A4914F(owner19, unsigned char**, 0);
    counter16 = A4914ApproximatePlanarDistance(owner19 + 12, A4914Player);
    if (A4914W(private18, 16))
        A4914H37014(owner19);
    work3 = A4914W(private18, 28);
    work2 = work3 * 88;
    work3 = (int)A4914Models;
    work2 += work3;
    if (A4914B((void*)work2, 72) >= 128 && A4914W(private18, 32) == -1)
        A4914W(private18, 32) = (short)A4914H2803C(6, 4000, A4914H27D60, 0, A4914H2982C, 0, 0);
    work3 = A4914B(owner19, 72);
    work2 = 1;
    if (work3 == work2)
        goto state1;
    if (work3 < 2) {
        if (!work3)
            goto state0;
        goto common;
    }
    if (work3 == 2)
        goto state2;
    goto common;
state0:
    A4914B(owner19, 87) = 41;
    A4914B(owner19, 84) = 128;
    A4914B(owner19, 85) = 128;
    A4914B(owner19, 86) = 144;
    A4914B(owner19, 72) = 1;
    goto update;
state1:
    work3 = A4914W(private18, 0);
    if (work3) {
        work3 += A4914Delta;
        A4914W(private18, 0) = work3;
        if (work3 < 64) {
            work2 = work3 >> 1;
            work3 = A4914W(private18, 24);
            work2 <<= 1;
            work2 += work3;
            work3 = A4914W(private18, 4);
            work2 = A4914B((void*)work2, 0) + work3;
            A4914B(owner19, 68) = work2;
            work2 = A4914W(private18, 0);
            work3 = A4914W(private18, 24);
            work2 = ((work2 >> 1) << 1) + work3;
            work3 = A4914W(private18, 8);
            work2 = A4914B((void*)work2, 1) + work3;
            A4914B(owner19, 69) = work2;
            work2 = A4914W(private18, 0);
            work3 = A4914W(private18, 24);
            work2 = ((work2 >> 1) << 1) + work3;
            work3 = A4914F((void*)work2, signed char*, 0);
            work2 = A4914F((void*)work2, signed char*, 1);
            if (work3 < 0)
                work3 = -work3;
            if (work2 < 0)
                work2 = -work2;
            MATCHING_KEEP(work3);
            work3 += work2;
            MATCHING_KEEP(work3);
            work2 = work3 * 6;
            work3 = A4914W(private18, 12);
            work3 += work2;
            A4914W(owner19, 20) = work3;
        } else {
            work2 = A4914W(private18, 4);
            A4914W(private18, 0) = 0;
            A4914B(owner19, 68) = work2;
            work2 = A4914W(private18, 8);
            A4914B(owner19, 69) = work2;
            work2 = A4914W(private18, 12);
            A4914W(owner19, 20) = work2;
        }
    }
    if (counter16 > 20480)
        goto done;
    work3 = A4914W(private18, 28);
    work2 = work3 * 88;
    work3 = (int)A4914Models;
    work2 += work3;
    if (A4914B((void*)work2, 72) < 128)
        goto common;
    work2 =
        A4914PlanarHeadingLookup(A4914PX - A4914W(owner19, 12), A4914PY - A4914W(owner19, 16), 0);
    work2 = A4914AbsoluteByteAngleDelta(A4914B(owner19, 70), work2);
    if (work2 >= 32)
        goto update;
    work2 = counter16 < 2700;
    if (!work2)
        goto common;
    if (A4914PB8)
        goto common;
    work3 = A4914F(owner19, short*, 56);
    work2 = A4914W(owner19, 20) - work3;
    work3 = A4914PZ;
    arg4 = A4914P44;
    work2 -= work3;
    work2 += arg4;
    if (work2 < 0)
        work2 = -work2;
    if (work2 >= 900)
        goto update;
    A4914B(owner19, 73) = 0;
    A4914B(owner19, 72) = 2;
    goto done;
state2:
    switch (A4914B(owner19, 73)) {
        case 0:
            A4914CopyVector(frame.first, owner19 + 12);
            work2 = A4914B(owner19, 70);
            work3 = A4914Cos[work2];
            work2 = (work3 * 125) >> 8;
            work3 = frame.first[0];
            work3 += work2;
            frame.first[0] = work3;
            work2 = A4914B(owner19, 70);
            work3 = A4914Sin[work2];
            work2 = (work3 * 125) >> 8;
            work3 = frame.first[1];
            work3 += work2;
            frame.first[1] = work3;
            work2 = A4914Callback(frame.first, (A4914B(owner19, 70) + 128) & 255, owner19);
            if (!work2)
                goto common;
            goto increment;
        case 1:
            A4914H527C4(owner19, -1);
            A4914C590 = A4914W(private18, 44);
            work2 = (int)A4914Spawn(212, owner19);
            A4914W(private18, 36) = work2;
            if (work2)
                A4914PlayMobySoundEvent((void*)work2, 0, 0);
        case 2:
            if (A4914NewButtons & 2048)
                goto increment;
            if (!A4914W(private18, 36))
                goto increment;
            vector17 = frame.second;
            MATCHING_KEEP(vector17);
            A4914CopyVector(vector17, owner19 + 12);
            arg4 = 0x10000002;
            work2 = A4914B(owner19, 70);
            work3 = A4914Cos[work2];
            arg6 = (int)&A4914P20C;
            work2 = (work3 * 175) >> 10;
            work3 = frame.second[0];
            work3 += work2;
            frame.second[0] = work3;
            work3 = A4914B(owner19, 70);
            work2 = frame.second[2];
            work3 = A4914Sin[work3];
            work2 += 350;
            frame.second[2] = work2;
            A4914W((void*)arg6, 0) = arg4;
            work2 = (work3 * 175) >> 10;
            work3 = frame.second[1];
            work3 += work2;
            frame.second[1] = work3;
            work3 = A4914W(private18, 36);
            A4914B((void*)work3, 76) = 24;
            work3 = A4914W(private18, 40);
            arg4 = A4914Delta;
            work3 += arg4;
            A4914W(private18, 40) = work3;
            saved20 = (int)A4914Sin;
            MATCHING_BARRIER_VOLATILE("memory");
            work3 = A4914W(private18, 40);
            work2 = 1;
            A4914C74C = work2;
            if (work3 < 192) {
                counter16 = (int)frame.third;
                arg4 = counter16;
                arg5 = (int)vector17;
                MATCHING_KEEP2(arg4, arg5);
                vector17 = (int*)(arg6 - 524);
                A4914SubtractVector((void*)arg4, (void*)arg5, vector17);
                frame.third[2] -= 256;
                A4914ShiftVectorRightTowardZero((void*)counter16, 5);
                A4914MultiplyVectorGpfSf0((void*)counter16, (void*)counter16,
                                          A4914W(private18, 40));
                A4914DivideVector((void*)counter16, (void*)counter16, 6);
                A4914AddVector((void*)counter16, (void*)counter16, vector17);
                arg4 = frame.third[2] + 256;
                frame.third[2] = arg4;
                work3 = A4914W(private18, 40) << 7;
                work2 = work3 / 192;
                work2 = A4914F((void*)(saved20 + (work2 << 1)), unsigned short*, 0);
                work2 = (short)work2;
                work2 >>= 3;
                arg4 += work2;
                frame.third[2] = arg4;
                A4914CopyVector((void*)(A4914W(private18, 36) + 12), (void*)counter16);
                arg4 = A4914W(private18, 40);
                if (arg4 < 32) {
                    work2 = -arg4;
                    work3 = A4914W(private18, 36);
                    A4914B((void*)work3, 69) = work2;
                    goto angle;
                }
                work2 = arg4 < 128;
                if (!work2)
                    goto lateAngle;
                work2 = 224;
                work3 = A4914W(private18, 36);
                A4914B((void*)work3, 69) = work2;
            angle:
                work2 = A4914W(private18, 40);
                work3 = A4914W(private18, 36);
                A4914B((void*)work3, 70) = (work2 << 2) - 128;
                goto reloadSubtract64;
            lateAngle:
                work3 = A4914W(private18, 36);
                work2 = arg4 + 96;
                A4914B((void*)work3, 69) = work2;
                work3 = A4914W(private18, 36);
                if (A4914B((void*)work3, 69) >= 127)
                    goto subtract64;
                A4914B((void*)work3, 69) = 0;
                goto call3585C;
            }
            work2 = work3 < 208;
            if (!work2)
                goto launch;
            work3 = A4914W(private18, 36);
            if (A4914B((void*)work3, 79) < 32)
                A4914B((void*)work3, 79) = 32;
            work2 = A4914W(private18, 36);
            work3 = A4914B((void*)work2, 79);
            A4914B((void*)work2, 79) = work3 + 8;
        call3585C:
            A4914TurnMobyTowardHeading((void*)A4914W(private18, 36), A4914B(owner19, 70), 3, 0, 0,
                                       0);
            goto reloadSubtract64;
            goto childStep;
        launch:
            work2 = A4914B(owner19, 73);
            A4914B(owner19, 73) = work2 + 1;
        reloadSubtract64:
            work3 = A4914W(private18, 36);
        subtract64:
            work2 = A4914B((void*)work3, 69);
            work2 -= 64;
            A4914B((void*)work3, 69) = work2;
        childStep:
            A4914H492DC((void*)(A4914W(private18, 36) + 12));
            work3 = A4914B(owner19, 73);
            work2 = 1;
            if (work3 == work2) {
                work3 = A4914W(private18, 36);
                A4914B((void*)work3, 72) = 99;
                work3 = A4914W(private18, 36);
                A4914B((void*)work3, 87) = 41;
                work2 = A4914W(private18, 36);
                A4914B((void*)work2, 84) = 128;
                work2 = A4914W(private18, 36);
                A4914B((void*)work2, 85) = 128;
                work2 = A4914W(private18, 36);
                MATCHING_KEEP_VOLATILE_CLOBBER(work2, "$16");
                counter16 = 0;
                A4914B((void*)work2, 86) = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(work2, "$5");
                arg5 = 4;
                do {
                    arg4 = A4914W(private18, 36);
                    MATCHING_KEEP2(arg4, arg5);
                    counter16++;
                    A4914RefreshMobySpatialGridAndBasis((void*)arg4, arg5);
                    A4914Particle(4, 12, (void*)A4914W(private18, 36), 3);
                    work2 = counter16 < 2;
                    arg5 = 4;
                } while (work2);
                MATCHING_BARRIER_VOLATILE("memory");
                goto increment;
            }
            A4914RefreshMobySpatialGridAndBasis((void*)A4914W(private18, 36), 4);
            A4914Particle(1, 12, (void*)A4914W(private18, 36), 3);
            goto common;
        dispose:
            A4914C74C = 0;
            counter16 = 0;
            arg5 = 4;
            do {
                arg4 = A4914W(private18, 36);
                MATCHING_KEEP2(arg4, arg5);
                counter16++;
                A4914RefreshMobySpatialGridAndBasis((void*)arg4, arg5);
                A4914Particle(4, 12, (void*)A4914W(private18, 36), 3);
                work2 = counter16 < 3;
                arg5 = 4;
            } while (work2);
            MATCHING_BARRIER_VOLATILE("memory");
            arg4 = A4914W(private18, 36);
            if (arg4)
                A4914DeleteMoby((void*)arg4);
            goto increment;
        case 3:
            goto dispose;
        increment:
            work2 = A4914B(owner19, 73);
            A4914B(owner19, 73) = work2 + 1;
            goto update;
        case 4:
            A4914PlayMobySoundEvent(owner19, 0, 0);
            saved23 = 16;
            saved22 = 8;
            saved21 = 308;
            A4914B(owner19, 73) = 144;
            counter16 = 0;
            saved20 = 5;
            vector17 = (int*)1;
            do {
                work2 = A4914C578;
                work3 = A4914C574;
                work2 -= work3;
                if (work2 < 21)
                    goto dust;
                arg4 = (int)A4914Spawn(saved21, owner19);
                if (counter16 < saved22)
                    A4914B((void*)arg4, 73) = saved20;
                else {
                    A4914B((void*)arg4, 60) = (int)vector17;
                    work2 = 4;
                    A4914B((void*)arg4, 73) = work2;
                }
                work3 = A4914F(owner19, short*, 54);
                work2 = 201;
                MATCHING_KEEP2(work2, work3);
                if (work3 != work2)
                    A4914B((void*)arg4, 84) = (int)vector17;
                counter16++;
            } while (counter16 < saved23);
        dust:
            counter16 = 0;
            vector17 = frame.fourth;
            do {
                A4914CopyVector(vector17, owner19 + 12);
                counter16++;
                work2 = A4914Rand();
                work3 = frame.fourth[0];
                work3 += 128;
                work3 -= work2 & 255;
                frame.fourth[0] = work3;
                work2 = A4914Rand();
                work3 = frame.fourth[1];
                work3 += 128;
                work3 -= work2 & 255;
                frame.fourth[1] = work3;
                work2 = A4914Rand();
                work3 = frame.fourth[2];
                work3 += work2 & 511;
                frame.fourth[2] = work3;
                A4914Particle(1, 2, vector17, 0);
                A4914Particle(4, 70, vector17, 24);
            } while (counter16 < 8);
            arg4 = A4914W(private18, 32);
            counter16 = -1;
            if (arg4 != counter16)
                A4914H28154(arg4);
            A4914W(private18, 32) = counter16;
            A4914DeleteMoby(owner19);
            goto done;
    }
    goto update;
update:
common:
    A4914W(private18, 20) =
        A4914H368A4(owner19, A4914W(private18, 20), A4914F(owner19, short*, 54) != 201);
    if ((A4914W(owner19, 24) & 0x30000) && !A4914W(private18, 0)) {
        A4914W(private18, 0) = 1;
        work2 = A4914B(owner19, 68);
        A4914W(private18, 4) = work2;
        work2 = A4914B(owner19, 69);
        A4914W(private18, 8) = work2;
        work2 = A4914W(owner19, 20);
        A4914W(private18, 12) = work2;
        A4914PlayMobySoundEvent(owner19, 1, 0);
    }
    A4914W(owner19, 24) = 0;
done:
    return;
}
#undef A4914F
#undef A4914W
#undef A4914B


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
void func_level_23_80079000(Moby* moby) {
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


/* Private words: wrapped table phase, timer helper input, indexed actor gate. */
typedef struct {
    int phase;
    int timer;
    int gateIndex;
} DecodedTimedVectorTag;
extern Moby* D_8006C550;
extern int D_8006C648, D_8006C640;
extern Vector3D DecodedTimedVectorPlayer __asm__("D_80070328");
extern int DecodedTimedVectorPlayerZ __asm__("D_80070328 + 8");
extern unsigned short DecodedTimedVectorCos[] __asm__("D_80065920");
extern unsigned short DecodedTimedVectorSin[] __asm__("D_800658A0");
Vector3D* DecodedTimedVectorAllocate(char) __asm__("func_8002F040");
void func_80055B18(Moby*);
void func_80055D24(Moby*, int);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003BABC(Moby*, int, int);
int func_800359A4(void*, int);
int func_8003636C(int, int);
int rand(void);
void func_level_23_80079304(Moby* moby) {
    DecodedTimedVectorTag* tag = moby->mobyTag;
    Vector3D* vector;
    int baseZ, playerZ, difference, index;
    register int angle __asm__("$16");
    register int minimum __asm__("$4");
    register int maximum __asm__("$5");
    register int z __asm__("$2");
    register int sine __asm__("$3");
    unsigned char* stateAddress;
    switch (moby->state) {
        case 0:
            if (tag->gateIndex != -1 && D_8006C550[tag->gateIndex].state >= 128)
                goto retire;
            ((unsigned char*)&moby->colour)[3] = 41;
            ((unsigned char*)&moby->colour)[0] = 128;
            ((unsigned char*)&moby->colour)[1] = 128;
            ((unsigned char*)&moby->colour)[2] = 0;
            moby->state = 1;
            break;
        case 1:
            moby->angle.roll = DecodedTimedVectorCos[tag->phase] >> 7;
            moby->angle.pitch = DecodedTimedVectorSin[tag->phase] >> 7;
            tag->phase = (tag->phase + D_8006C648 * 2) & 255;
            func_80055D24(moby, 4);
            if (func_8004F334(&moby->position, &DecodedTimedVectorPlayer) >= 512)
                goto idle;
            baseZ = moby->position.z - moby->distanceToGround;
            playerZ = DecodedTimedVectorPlayerZ;
            difference = baseZ - playerZ;
            if (difference >= 0) {
                /* Keep the separate positive/negative retail comparison routes. */
                if (difference < 512)
                    goto collect;
                MATCHING_BARRIER_VOLATILE("memory");
                goto idle;
            }
            if (playerZ - baseZ >= 512)
                goto idle;
        collect:
            func_8003BABC(moby, 0, 0);
            for (index = 0; index < 3; index++)
                SpawnParticle(4, 12, (Vector3D*)moby, (Vector3D*)3);
            moby->state = 2;
            stateAddress = &moby->state;
            func_8003B7B4(stateAddress, 1, &savedData);
            func_8003B7B4(stateAddress, 1, &unsavedData);
            goto retire;
        idle:
            if (!(D_8006C640 & 3))
                SpawnParticle(1, 12, (Vector3D*)moby, (Vector3D*)3);
            if (!func_800359A4(&tag->timer, 4))
                break;
            vector = DecodedTimedVectorAllocate(3);
            if (!vector)
                break;
            {
                int rawAngle = rand();
                register Vector3D* destination __asm__("$4") = vector;
                register Vector3D* sourcePosition __asm__("$5") = &moby->position;
                MATCHING_OBSERVE2_VOLATILE(destination, sourcePosition);
                angle = rawAngle;
                func_8004F178(destination, sourcePosition);
            }
            minimum = 120;
            maximum = 200;
            angle &= 255;
            vector->x += (int)(DecodedTimedVectorCos[angle] << 16) >> 20;
            /* Retail publishes X before loading Z and the second table value. */
            MATCHING_BARRIER_VOLATILE("memory");
            z = vector->z;
            sine = DecodedTimedVectorSin[angle];
            z += 200;
            sine <<= 16;
            vector->z = z;
            MATCHING_BARRIER_VOLATILE("memory");
            MATCHING_OBSERVE2_VOLATILE(minimum, maximum);
            vector->y += sine >> 20;
            tag->timer = func_8003636C(minimum, maximum);
            break;
        case 2:
        retire:
            func_80055B18(moby);
            break;
    }
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
void func_level_23_8007960C(void* input) {
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
void func_level_23_8007A180(Moby* moby) {
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
void func_level_23_8007A5B0(Moby* owner) {
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

extern char* (*SpawnParticle)(int, int, Vector3D*, Vector3D*);
int rand(void);
void func_level_23_8007A73C(Moby* moby) {
    if (*(int*)moby->mobyTag == 0 || moby->substate != 0)
        SpawnParticle((rand() & 1) + 1, 0x45, 0, 0);
}

/* Source-local raw129 route; the indexed list includes its negative terminator. */
typedef struct {
    Vector3D* fragmentOffsets;
} DecodedSingleActiveTag;
extern unsigned short** DecodedSingleActiveLists __asm__("D_8006C730");
extern Moby* DecodedSingleActivePool __asm__("D_8006C550");
extern unsigned char DecodedSingleActiveGlobalByte __asm__("D_80066BC8 + 7");
extern short DecodedSingleActiveGlobalHalf __asm__("D_800719DC");
extern unsigned char* DecodedSingleActiveSoundDescriptor __asm__("D_8006C654");
extern Vector3D DecodedSingleActivePlayer __asm__("D_80070328");
extern unsigned char DecodedSingleActiveHeading __asm__("D_80070328 + 0xE");
extern short DecodedSingleActiveCos[] __asm__("D_80065920");
extern short DecodedSingleActiveSin[] __asm__("D_800658A0");
extern void (*DecodedSingleActiveCallback)(Vector3D*, int, int, int,
                                           int) __asm__("unk_ovlheader_80074410");
void DecodedSingleActiveOwner(Moby*, int, int) __asm__("func_8003BB10");
void DecodedSingleActiveRelease(Moby*) __asm__("func_80055B18");
void func_level_23_8007A7A4(Moby* moby) {
    DecodedSingleActiveTag* tag = moby->mobyTag;
    Vector3D position;
    unsigned short* list;
    unsigned short selector;
    int count;
    Moby* child;
    int sine;
    if (!moby->damageFlags)
        return;
    DecodedSingleActiveOwner(moby, 9, 0);
    SpawnFragments(3, 741, moby, tag->fragmentOffsets, 0, 256);
    if (moby->damageFlags & 0x10000) {
        func_8004F178(&position, &moby->position);
        position.z += 1200;
        DecodedSingleActiveCallback(&position, 55, 16, 28, 38);
    }
    count = 0;
    if (moby->unknown3[2] == 255)
        goto release;
    list = DecodedSingleActiveLists[moby->unknown3[2]];
    do {
        /* Retail masks and visits the terminator before testing its sign. */
        selector = *list;
        if (DecodedSingleActivePool[selector & 32767].state < 128)
            count++;
    } while (list++, (short)selector >= 0);
    if (count != 1)
        goto release;
    DecodedSingleActiveGlobalByte = 3;
    DecodedSingleActiveGlobalHalf = 1;
    PlaySound(DecodedSingleActiveSoundDescriptor[0x23], moby, 161);
    child = SpawnMoby(211, moby);
    if (child) {
        func_8004F178(&child->position, &DecodedSingleActivePlayer);
        child->position.x += (DecodedSingleActiveCos[DecodedSingleActiveHeading] * 25) >> 7;
        MATCHING_BARRIER_VOLATILE("memory");
        sine = DecodedSingleActiveSin[DecodedSingleActiveHeading];
        child->position.z += 500;
        child->position.y += (sine * 25) >> 7;
    }
release:
    DecodedSingleActiveRelease(moby);
}

int rand(void);
int func_80039714(Moby*);
extern int D_8006C640;
void func_level_23_8007A9CC(Moby* moby) {
    Vector3D offset;
    if (moby->mobyClass == 0x2E5 && D_8006C640 % 3 == 0) {
        offset.x = rand() & 3;
        offset.y = rand() & 3;
        offset.z = 0x14;
        SpawnParticle(1, 1, &moby->position, &offset);
    }
    func_80039714(moby);
}

extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_8007158A;
void func_level_23_8007AA78(Moby* moby) {
    SpeechProps* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->mobyClass == 0x2ab) {
                if (!D_8007158A)
                    tag->nextMsg = 0;
                else {
                    if (D_80070300[D_80066FCC[0x10]] & 1)
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
void func_level_23_8007ABC8(Moby* actor) {
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
extern unsigned char D_80071578;
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
void func_level_23_8007AE74(Moby* input) {
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
                D_80071578 = 1;
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
void func_level_23_8007B2A8(Moby* input) {
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
void func_level_23_8007B6B4(Moby* moby) {
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
void func_level_23_8007B720(Moby* moby) {
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
void func_level_23_8007BA50(Moby* actor) {
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
void func_level_23_8007BC5C(Moby* argument) {
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

#define Controller7CFCCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Controller7CFCCD_800658A0[] __asm__("D_800658A0");
extern short Controller7CFCCD_80065920[] __asm__("D_80065920");
extern int Controller7CFCCD_8006C574 __asm__("D_8006C574");
extern int Controller7CFCCD_8006C578 __asm__("D_8006C578");
extern int Controller7CFCCD_80071918 __asm__("D_80071918");
extern int Controller7CFCCD_8007191C __asm__("D_8007191C");
extern int Controller7CFCCD_80071920 __asm__("D_80071920");
extern void* (*Controller7CFCCSpawnMoby)(int, void*)__asm__("SpawnMoby");
int Controller7CFCCHelper19138(void*, int, int, int, int, int) __asm__("func_80019138");
int Controller7CFCCCountTimerDown(void*, int) __asm__("func_800359A4");
int Controller7CFCCHelper369B8(void*, int) __asm__("func_800369B8");
int Controller7CFCCMeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Controller7CFCCNormalizeVectorToLength(void*, int) __asm__("func_8004EF04");
int Controller7CFCCScaleVectorRatioQ15() __asm__("func_8004F08C");
int Controller7CFCCCopyVector(void*, void*) __asm__("func_8004F178");
int Controller7CFCCAddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller7CFCCDeleteMoby(void*) __asm__("func_80055B18");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level16/8007CFCC, level23/8007C184 and level24/8007EA58.
 * Independent original comparison: 312 instructions each, identical helper
 * and global symbols, no owned table rows. Stack vectors remain at 0x18/0x28.
 * Preserve signed short inputs, low-word products, shifts 11/13/12, three
 * child iterations, original helper arguments, clamp branches and byte stores.
 * Units, coordinate domains, helper semantics and caller cadence remain
 * unresolved; updates are once per invocation. Confidence is exact original
 * native/linked words and EXE/all-overlay hashes, not semantic runtime review.
 * Falsifiable vectors: all 936 original words and complete retail SHA set.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_23_8007C184(void* input) {
    struct {
        int x, y, z, pad;
        int x2, y2, z2, pad2, pad3, pad4;
    } frame;
    register unsigned char* owner __asm__("$20") = input;
    register short* tableOrVector __asm__("$4");
    register short* cosineEntry __asm__("$5");
    short decrementedZ;
    register int parentZ __asm__("$3");
    register int childZ __asm__("$2");
    register int tableByteOffset __asm__("$4");
    int projection11;
    register int zeroArgument __asm__("$5");
    register int dotProduct __asm__("$2");
    register int queryThreshold __asm__("$16");
    register int childIndex __asm__("$18");
    int childOffsetY;
    register int childMode __asm__("$2");
    register int* secondVector __asm__("$21");
    register int one __asm__("$23");
    register int twenty __asm__("$22");
    register int* collision __asm__("$16");
    void* ownerPosition;
    register void* childTag __asm__("$16");
    register void* tag __asm__("$19");
    register void* child __asm__("$17");
    register void* preparedArgument __asm__("$4");
    void* childPosition;

    MATCHING_KEEP_VOLATILE_CLOBBER(owner, "$4");
    tag = Controller7CFCCField(owner, void**, 0);
    MATCHING_KEEP(owner);
    queryThreshold = 0x100;
    if (Controller7CFCCField(tag, short*, 0x12) == 1) {
        queryThreshold = 0x80;
    }
    if (Controller7CFCCHelper19138(owner + 0xC, queryThreshold, 1, 0, 0, 0) != 0) {
        if ((queryThreshold == 0x100) ||
            ((Controller7CFCCD_80071918 < 0x64) && (Controller7CFCCD_8007191C < 0x64))) {
            Controller7CFCCField(tag, short*, 0xC) = 0;
        }
        collision = &Controller7CFCCD_80071918;
        Controller7CFCCNormalizeVectorToLength(collision, 0x1000);
        {
            register int value __asm__("$3");
            register int operand __asm__("$2");
            register int first __asm__("$5"), second __asm__("$4"), third __asm__("$3");
            value = Controller7CFCCField(tag, short*, 0);
            operand = *collision;
            first = value * operand;
            MATCHING_KEEP(first);
            value = Controller7CFCCField(tag, short*, 2);
            operand = Controller7CFCCD_8007191C;
            second = value * operand;
            MATCHING_KEEP(second);
            value = Controller7CFCCField(tag, short*, 4);
            operand = Controller7CFCCD_80071920;
            third = value * operand;
            dotProduct = first + second;
            MATCHING_KEEP2(third, dotProduct);
            dotProduct += third;
        }
        projection11 = dotProduct >> 0xB;
        __asm__("" : "=r"(projection11) : "0"(projection11) : "$4", "$5");
        preparedArgument = tag + 0xC;
        if (projection11 < 0) {
            {
                register int correction __asm__("$6");
                register void* prepared __asm__("$4") = collision;
                register int scale __asm__("$5") = 4096;
                MATCHING_KEEP2(prepared, scale);
                correction = dotProduct >> 13;
                Controller7CFCCScaleVectorRatioQ15(prepared, scale, correction - projection11,
                                                   projection11);
            }
            Controller7CFCCField(tag, short*, 0) =
                (short)((unsigned short)Controller7CFCCField(tag, short*, 0) + *collision);
            Controller7CFCCField(tag, short*, 2) =
                (short)((unsigned short)Controller7CFCCField(tag, short*, 2) +
                        Controller7CFCCD_8007191C);
            Controller7CFCCField(tag, short*, 4) =
                (short)((unsigned short)Controller7CFCCField(tag, short*, 4) +
                        Controller7CFCCD_80071920);
            goto prepareCountdown;
        }
    } else {
    prepareCountdown:
        preparedArgument = tag + 0xC;
    }
    if (Controller7CFCCCountTimerDown(preparedArgument, 2) != 0) {
        if (Controller7CFCCField(tag, short*, 0x12) != 0) {
            preparedArgument = owner;
            goto removeCalls;
        }
        {
            Controller7CFCCCopyVector(&frame.x, &Controller7CFCCD_80071918);
            Controller7CFCCScaleVectorRatioQ15(
                &frame.x, Controller7CFCCMeasureVectorLength(&frame.x, 1), 0x82);
            ownerPosition = owner + 0xC;
            Controller7CFCCAddVector(ownerPosition, ownerPosition, &frame.x);
            childIndex = 0;
            secondVector = &frame.x2;
            one = 1;
            twenty = 20;
            MATCHING_KEEP3(secondVector, one, twenty);
        spawnChildLoop:
            if ((Controller7CFCCD_8006C578 - Controller7CFCCD_8006C574) >= 0x15) {
                child = Controller7CFCCSpawnMoby(8, owner);
                if (child != 0) {
                    MATCHING_KEEP(child);
                    childTag = Controller7CFCCField(child, void**, 0);
                    Controller7CFCCField(childTag, short*, 0x12) = one;
                    {
                        register int value __asm__("$2");
                        value = Controller7CFCCField(tag, short*, 0);
                        frame.x = value;
                        MATCHING_BARRIER_VOLATILE("memory");
                        value = Controller7CFCCField(tag, short*, 2);
                        frame.y = value;
                        MATCHING_BARRIER_VOLATILE("memory");
                    }
                    {
                        register int index __asm__("$2") = (childIndex - 1) << 5;
                        MATCHING_KEEP(index);
                        parentZ = Controller7CFCCField(tag, short*, 4);
                        MATCHING_KEEP(parentZ);
                        tableByteOffset = index & 255;
                        MATCHING_KEEP2(tableByteOffset, parentZ);
                    }
                    MATCHING_KEEP2(tableByteOffset, parentZ);
                    childZ = parentZ;
                    MATCHING_KEEP2(childZ, parentZ);
                    if (parentZ < 0x32) {
                        childZ = 0x32;
                    }
                    Controller7CFCCField(childTag, short*, 4) = childZ;
                    MATCHING_BARRIER_VOLATILE("memory");
                    cosineEntry = Controller7CFCCD_80065920;
                    MATCHING_KEEP2(cosineEntry, tableByteOffset);
                    tableByteOffset *= 2;
                    cosineEntry = (short*)(tableByteOffset + (int)cosineEntry);
                    MATCHING_KEEP(cosineEntry);
                    tableOrVector =
                        (short*)((unsigned char*)Controller7CFCCD_800658A0 + tableByteOffset);
                    {
                        register int value __asm__("$2"), sample __asm__("$3");
                        register int firstProduct __asm__("$6"), secondProduct __asm__("$3");
                        sample = *cosineEntry;
                        value = frame.x;
                        firstProduct = value * sample;
                        MATCHING_KEEP(firstProduct);
                        sample = *tableOrVector;
                        value = frame.y;
                        secondProduct = value * sample;
                        MATCHING_KEEP(secondProduct);
                        value = (firstProduct - secondProduct) >> 12;
                        Controller7CFCCField(childTag, short*, 0) = value;
                        sample = *tableOrVector;
                        value = frame.x;
                        firstProduct = value * sample;
                        MATCHING_KEEP(firstProduct);
                        sample = *cosineEntry;
                        value = frame.y;
                        secondProduct = value * sample;
                        {
                            register void* prepared __asm__("$4") = secondVector;
                            MATCHING_KEEP(prepared);
                            tableOrVector = prepared;
                        }
                        MATCHING_KEEP(secondProduct);
                        value = firstProduct + secondProduct;
                        sample = Controller7CFCCField(childTag, short*, 0);
                        MATCHING_KEEP2(value, sample);
                        value >>= 12;
                        Controller7CFCCField(childTag, short*, 2) = value;
                        frame.x2 = sample;
                        value = Controller7CFCCField(childTag, short*, 2);
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "$5");
                        zeroArgument = 0;
                        MATCHING_KEEP(zeroArgument);
                        frame.z2 = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
                        frame.y2 = value;
                    }
                    {
                        register int callResult __asm__("$2") =
                            Controller7CFCCMeasureVectorLength((void*)tableOrVector, zeroArgument);
                        register int byteValue __asm__("$2");
                        MATCHING_KEEP(callResult);
                        if (callResult >= 0xC9) {
                            Controller7CFCCScaleVectorRatioQ15(
                                secondVector, Controller7CFCCMeasureVectorLength(secondVector, 0),
                                0xC8);
                            Controller7CFCCField(childTag, short*, 0) = (short)frame.x2;
                            Controller7CFCCField(childTag, short*, 2) = (short)frame.y2;
                        }
                        byteValue = 180;
                        Controller7CFCCField(child, unsigned char*, 0x4F) = byteValue;
                    }
                    Controller7CFCCField(child, signed char*, 0x4C) = 0x3F;
                    Controller7CFCCField(child, unsigned char*, 0x4A) = 0xFF;
                    MATCHING_KEEP(childIndex);
                    if (childIndex == one)
                        goto childOne;
                    if (childIndex < 2) {
                        if (childIndex == 0)
                            goto childZero;
                        goto copyChild;
                    }
                    if (childIndex == 2)
                        goto childTwo;
                    goto copyChild;
                childZero:
                    frame.x = 411;
                    childOffsetY = 25;
                    goto childOuterY;
                childOne:
                    {
                        register int value __asm__("$2") = -300;
                        frame.y = value;
                        __asm__ volatile("" : : : "memory", "$2");
                    }
                    childMode = 2;
                    frame.x = 0;
                    goto childComplete;
                childTwo:
                    frame.x = -500;
                    childOffsetY = 364;
                childOuterY:
                    frame.y = childOffsetY;
                    childMode = 1;
                childComplete:
                    frame.z = twenty;
                    Controller7CFCCField(child, unsigned char*, 0x3C) = childMode;
                copyChild:
                    childPosition = child + 0xC;
                    Controller7CFCCAddVector(childPosition, childPosition, &frame.x);
                }
                childIndex += 1;
                if (childIndex < 3) {
                    goto spawnChildLoop;
                }
            }
        }
        MATCHING_BARRIER_VOLATILE("$4");
        preparedArgument = owner;
    removeCalls:
        Controller7CFCCHelper369B8(preparedArgument, 0x28);
        Controller7CFCCDeleteMoby(owner);
        return;
    }
    Controller7CFCCField(owner, int*, 0xC) =
        (int)(Controller7CFCCField(owner, int*, 0xC) + Controller7CFCCField(tag, short*, 0));
    Controller7CFCCField(owner, int*, 0x10) =
        (int)(Controller7CFCCField(owner, int*, 0x10) + Controller7CFCCField(tag, short*, 2));
    decrementedZ = (unsigned short)Controller7CFCCField(tag, short*, 4) - 0xA;
    Controller7CFCCField(tag, short*, 4) = decrementedZ;
    if (decrementedZ < -0xC8) {
        Controller7CFCCField(tag, short*, 4) = -0xC8;
    }
    Controller7CFCCField(owner, int*, 0x14) =
        (int)(Controller7CFCCField(owner, int*, 0x14) + Controller7CFCCField(tag, short*, 4));
    Controller7CFCCField(owner, unsigned char*, 0x44) =
        (unsigned char)(Controller7CFCCField(owner, unsigned char*, 0x44) +
                        Controller7CFCCField(tag, unsigned char*, 6));
    Controller7CFCCField(owner, unsigned char*, 0x45) =
        (unsigned char)(Controller7CFCCField(owner, unsigned char*, 0x45) +
                        Controller7CFCCField(tag, unsigned char*, 8));
    Controller7CFCCField(owner, unsigned char*, 0x46) =
        (unsigned char)(Controller7CFCCField(owner, unsigned char*, 0x46) +
                        Controller7CFCCField(tag, unsigned char*, 0xA));
}

#undef Controller7CFCCField

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
void func_level_23_8007C664(void* input) {
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

void func_level_23_8007D7B8(Moby* moby) {
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
void func_level_23_8007D7D8(Moby* argument) {
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
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_23/moby/func_level_23_8007D9D8.s SHA256 7fad08a73d1c93e3827730082550db853798706715ea11b8d0f5680028a06d6f. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level23_7D9D8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level23_7D9D8_D_8006C550 __asm__("D_8006C550");
extern Spyro Level23_7D9D8_D_80070328 __asm__("D_80070328");
extern int Level23_7D9D8_func_8002EC50(char, char, int) __asm__("func_8002EC50");
void Level23_7D9D8RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level23_7D9D8_func_80035194(Moby*, void*) __asm__("func_80035194");
int Level23_7D9D8TurnMobyTowardPlayer(Moby* ownerRecord18, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level23_7D9D8TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
int Level23_7D9D8CountTimerDown(void*, int) __asm__("func_800359A4");
int Level23_7D9D8ProbeGroundFromRaisedMoby(Moby* moby) __asm__("func_80035D38");
int Level23_7D9D8_func_80035DDC(Moby* ownerRecord18, int arg1, int arg2, int arg3,
                                int arg4) __asm__("func_80035DDC");
void Level23_7D9D8_func_800369B8() __asm__("func_800369B8");
void Level23_7D9D8_func_80038F14(Moby*, void*, unsigned int, int) __asm__("func_80038F14");
void Level23_7D9D8_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
extern int Level23_7D9D8PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level23_7D9D8ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level23_7D9D8CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level23_7D9D8AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level23_7D9D8AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level23_7D9D8ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level23_7D9D8DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level23_7D9D8RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level23_7D9D8_func_80055E84(Moby*) __asm__("func_80055E84");
extern int Level23_7D9D8_rand() __asm__("rand");

int Level23_7D9D8_func_80035A80() __asm__("func_80035A80");
/* extern */
unsigned int Level23_7D9D8_func_80036A68() __asm__("func_80036A68");
/* extern */
unsigned int Level23_7D9D8InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern int Level23_7D9D8_D_8006C770 __asm__("D_8006C770");
extern int Level23_7D9D8_D_8006E020 __asm__("D_8006E020");
extern int Level23_7D9D8_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level23_7D9D8_D_8006E040 __asm__("D_8006E040");
extern int Level23_7D9D8_D_8006E344 __asm__("D_8006E344");

void func_level_23_8007D9D8(Moby* ownerRecord18) {
    /* Original0x58-byte frame;
     scratch triples atSP+0x20 andSP+0x30.
     * Raw field and vector pointer adjustments retain byte offsets.
     * The timer helper receives private+0xC;
      its following state helper
     * receives the original owner. The rand call has no explicit argument.
     * Shared copy/reset/state24/state2 tails retain original instruction
     * joins and initialized caller4/5/state2 producers on every input path.
     * Post-call halfword reads and known-zero caller arguments preserve
     * the original order. Saved global/difference register roles emerge
     * after the raw state word is produced at its original branch point.
     * All empty register constraints have initialized inputs;
      no opcode asm.
     * Units, helper meanings and frame cadence remain unresolved. */
    struct {
        Vector3D sp20;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[4];
    } originalFrame;

    Moby* var_a0;
    register Moby* sharedCaller4 __asm__("4");
    Moby* selectedRecord17;
    Vector3D* temp_s0_2;
    Vector3D* privateVector19;
    int temp_s0;
    int differenceWord20;
    int temp_v0_2;
    int temp_v0_3;
    register int sharedParameter5 __asm__("5");
    register int resetParameter5 __asm__("5");
    int var_v0;
    int var_v0_4;
    unsigned int rawState3;
    register unsigned int nextRawState2 __asm__("2");
    register unsigned int sharedRawState2 __asm__("2");
    void* temp_a0;
    void* temp_s0_3;
    void* temp_v0;
    void* temp_v0_4;

    privateVector19 = ownerRecord18->mobyTag;
    if (ownerRecord18->substate == 0) {
        ownerRecord18->substate = 1;
        temp_a0 = Level23_7D9D8Field(privateVector19, void**, 0x14);
        Level23_7D9D8Field(privateVector19, short*, 0xC) = 0x64;
        if (temp_a0 != 0) {
            Level23_7D9D8Field(temp_a0, short*, 0xA) = 1;
            Level23_7D9D8Field(Level23_7D9D8Field(privateVector19, void**, 0x14), short*, 2) = 1;
        }
    }
    if ((ownerRecord18->state != 5) && (ownerRecord18->damageFlags & 0x10000)) {
        Level23_7D9D8_func_80036A68(ownerRecord18, 1, 0, 0);
        Level23_7D9D8_func_80038F14(ownerRecord18,
                                    ((void*)((unsigned char*)privateVector19 + 0x20)), 2U, 5);
        Level23_7D9D8Field(privateVector19, short*, 0x24) = 0xC8;
        Level23_7D9D8Field(privateVector19, short*, 0xE) = Level23_7D9D8ApproximatePlanarDistance(
            &ownerRecord18->position, &Level23_7D9D8_D_80070328.position);
        ownerRecord18->unknownCollision = 0;
    }
    if (ownerRecord18->drawn == 0) {
        temp_v0 = Level23_7D9D8Field(privateVector19, void**, 0x1C);
        if (temp_v0 != 0) {
            Level23_7D9D8Field(temp_v0, signed char*, 0x10) = 0;
            Level23_7D9D8Field(privateVector19, void**, 0x1C) = 0;
            goto block_11;
        }
    } else if (Level23_7D9D8Field(privateVector19, void**, 0x1C) == 0) {
        Level23_7D9D8Field(privateVector19, void**, 0x1C) =
            Level23_7D9D8_func_8002EC50(1, 0x80, 0x489090);
    block_11:
        if (Level23_7D9D8Field(privateVector19, void**, 0x1C) != 0) {
            goto block_12;
        }
    } else {
    block_12:
        Level23_7D9D8RefreshMobySpatialGridAndBasis(ownerRecord18, 5);
        Level23_7D9D8InterpolateMobyVertex(ownerRecord18, 0,
                                           Level23_7D9D8Field(privateVector19, void**, 0x1C));
        Level23_7D9D8Field(Level23_7D9D8Field(privateVector19, void**, 0x1C), signed char*, 0x13) =
            8;
    }
    rawState3 = ownerRecord18->state;
    switch (rawState3) {
        case 0:
            if (Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                       &Level23_7D9D8_D_80070328.position) <
                Level23_7D9D8Field(privateVector19, short*, 0xE)) {
                ownerRecord18->state = 7;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 7);
            }
            var_a0 = ((void*)((unsigned char*)privateVector19 + 0xC));
            if (ownerRecord18->substate != 2) {
                if (Level23_7D9D8CountTimerDown(var_a0, 2) != 0) {
                    Level23_7D9D8RequestMobyAnimation(ownerRecord18, 1);
                    Level23_7D9D8Field(privateVector19, short*, 0xC) = 0x1F4;
                    return;
                }
            }
            if (Level23_7D9D8_D_8006C770 != 0) {
                ownerRecord18->substate = 1;
                Level23_7D9D8Field(privateVector19, short*, 0xC) =
                    (short)(((Level23_7D9D8_rand() & 3) * 0x3C) + 0x64);
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 0);
                return;
            }
        default:
            return;
        case 22:
            if (Level23_7D9D8TurnMobyTowardPlayer(ownerRecord18, 6, 6, 0) == 0) {
                Level23_7D9D8_func_80035DDC(ownerRecord18, 0x32, 0, 0, 4);
                if (Level23_7D9D8ApproximatePlanarDistance(&Level23_7D9D8_D_80070328.position,
                                                           privateVector19) <
                    ((Level23_7D9D8Field(privateVector19, short*, 0x12) +
                      Level23_7D9D8Field(privateVector19, short*, 0x10)) -
                     0x400)) {
                    {
                        register int word2 __asm__("2");
                        register int word3 __asm__("3");
                        word2 = Level23_7D9D8_D_80070328.position.z;
                        word3 = ownerRecord18->position.z;
                        MATCHING_KEEP2(word2, word3);
                        var_v0 = word2 - word3;
                    }
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    if (var_v0 >= 0x400) {
                        goto block_27;
                    }
                    nextRawState2 = 2;
                    goto block_74;
                }
            block_27:
                if (Level23_7D9D8CountTimerDown(((void*)((unsigned char*)privateVector19 + 0xC)),
                                                2) != 0) {
                    goto block_28;
                }
            } else {
            block_28:
                ownerRecord18->state = 0;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 0);
                Level23_7D9D8Field(privateVector19, short*, 0xC) = 0x64;
                return;
            }
            break;
        case 2:
            Level23_7D9D8CopyVector(&originalFrame.sp20, &Level23_7D9D8_D_80070328.unk7a[3]);
            originalFrame.sp20.x = (int)originalFrame.sp20.x << 5;
            originalFrame.sp20.y <<= 5;
            originalFrame.sp20.z <<= 5;
            Level23_7D9D8ShiftVectorRightTowardZero(&originalFrame.sp20, 6);
            Level23_7D9D8AddVector(
                &originalFrame.sp20, &originalFrame.sp20,
                (Vector3D*)((unsigned char*)&Level23_7D9D8_D_80070328.unk7a[3] - 0x98));
            if ((Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                        &originalFrame.sp20) <
                 Level23_7D9D8Field(privateVector19, short*, 0x10)) &&
                (Level23_7D9D8AbsoluteByteAngleDelta(
                     (int)(Level23_7D9D8_D_8006E040 << 0x10) >> 0x14,
                     Level23_7D9D8PlanarHeadingLookup(
                         ownerRecord18->position.x - Level23_7D9D8_D_8006E020,
                         ownerRecord18->position.y - Level23_7D9D8_D_8006E024, 0)) < 0x18) &&
                (Level23_7D9D8_D_8006E344 != 1)) {
                ownerRecord18->state = 3;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 3);
                return;
            }
            {
                register int returned2 __asm__("2");
                register int field3 __asm__("3");
                returned2 = Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                                   privateVector19);
                MATCHING_KEEP_CLOBBER(returned2, "memory");
                field3 = Level23_7D9D8Field(privateVector19, short*, 0x12);
                field3 = field3 < returned2;
                if (field3) {
                    Level23_7D9D8Field(privateVector19, short*, 0xC) = 0x78;
                    ownerRecord18->state = 0x15;
                    return;
                }
                MATCHING_KEEP(field3);
            }
            Level23_7D9D8TurnMobyTowardPlayer(ownerRecord18, 4, 2, 0);
            Level23_7D9D8_func_80035DDC(ownerRecord18, 0x50, 0, 0, 0);
            ownerRecord18->position.z = Level23_7D9D8ProbeGroundFromRaisedMoby(ownerRecord18);
            return;
        case 21:
            if (Level23_7D9D8Field(privateVector19, short*, 0xC) != 0) {
                if (Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                           &Level23_7D9D8_D_80070328.position) <
                    Level23_7D9D8Field(privateVector19, short*, 0x10)) {
                    ownerRecord18->state = 2;
                }
            } else {
                Level23_7D9D8CountTimerDown(((void*)((unsigned char*)privateVector19 + 0xC)), 2);
            }
            Level23_7D9D8TurnMobyTowardHeading(
                ownerRecord18,
                Level23_7D9D8PlanarHeadingLookup(privateVector19->x - ownerRecord18->position.x,
                                                 privateVector19->y - ownerRecord18->position.y, 0),
                5, 5, 0, 0);
            Level23_7D9D8_func_80035DDC(ownerRecord18, 0x50, 0, 0, 0);
            ownerRecord18->position.z = Level23_7D9D8ProbeGroundFromRaisedMoby(ownerRecord18);
            if (Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position, privateVector19) <
                0x200) {
                Level23_7D9D8Field(privateVector19, short*, 0xC) = 0x3C;
                ownerRecord18->state = 0x16;
                return;
            }
            break;
        case 7:
            Level23_7D9D8TurnMobyTowardPlayer(ownerRecord18, 6, 6, 0);
            if (Level23_7D9D8_D_8006C770 != 0) {
                ownerRecord18->state = 6;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 6);
                return;
            }
            break;
        case 6:
            Level23_7D9D8TurnMobyTowardPlayer(ownerRecord18, 6, 6, 0);
            Level23_7D9D8CopyVector(&originalFrame.sp30, &Level23_7D9D8_D_80070328.unk7a[3]);
            originalFrame.sp30.x = (int)originalFrame.sp30.x * 0xF;
            originalFrame.sp30.y *= 0xF;
            originalFrame.sp30.z *= 0xF;
            Level23_7D9D8ShiftVectorRightTowardZero(&originalFrame.sp30, 6);
            Level23_7D9D8AddVector(
                &originalFrame.sp30, &originalFrame.sp30,
                (Vector3D*)((unsigned char*)&Level23_7D9D8_D_80070328.unk7a[3] - 0x98));
            temp_v0_2 = Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                               &originalFrame.sp30);
            if ((temp_v0_2 < Level23_7D9D8Field(privateVector19, short*, 0x10)) &&
                (Level23_7D9D8AbsoluteByteAngleDelta(
                     (int)(Level23_7D9D8_D_8006E040 << 0x10) >> 0x14,
                     Level23_7D9D8PlanarHeadingLookup(
                         ownerRecord18->position.x - Level23_7D9D8_D_8006E020,
                         ownerRecord18->position.y - Level23_7D9D8_D_8006E024, 0)) < 0x18) &&
                (Level23_7D9D8_D_8006E344 != 1)) {
                ownerRecord18->state = 3;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 3);
            }
            if (Level23_7D9D8Field(privateVector19, short*, 0xE) < temp_v0_2) {
                ownerRecord18->state = 0;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 0);
                ownerRecord18->animationProgress = 0xA0;
                return;
            }
            break;
        case 3:
            temp_s0 = Level23_7D9D8_func_80055E84(ownerRecord18);
            Level23_7D9D8TurnMobyTowardPlayer(ownerRecord18, 6, 2, 0);
            differenceWord20 = (ownerRecord18->position.z - ownerRecord18->distanceToGround) -
                               Level23_7D9D8_D_80070328.position.z;
            if ((ownerRecord18->substate != 0x14) && (ownerRecord18->animationState.id == 3) &&
                ((unsigned int)(temp_s0 - 0xF) < 3U) && (Level23_7D9D8_D_80070328.unk20[2] == 0) &&
                (Level23_7D9D8AbsoluteByteAngleDelta(
                     (int)ownerRecord18->angle.yaw,
                     Level23_7D9D8PlanarHeadingLookup(
                         Level23_7D9D8_D_80070328.position.x - ownerRecord18->position.x,
                         Level23_7D9D8_D_80070328.position.y - ownerRecord18->position.y, 0)) <
                 8) &&
                (Level23_7D9D8ApproximatePlanarDistance(
                     &ownerRecord18->position,
                     (Vector3D*)((unsigned char*)&Level23_7D9D8_D_80070328.position.z - 8)) <
                 Level23_7D9D8Field(privateVector19, short*, 0x10)) &&
                ((unsigned int)(differenceWord20 + 0xFFF) < 0x107FU)) {
                Level23_7D9D8_D_80070328.unk22[5] = (int)ownerRecord18->angle.yaw;
                Level23_7D9D8_D_80070328.damageFlags |= 7;
                ownerRecord18->substate = 0x14;
            }
            if (Level23_7D9D8_D_8006C770 != 0) {
                if (ownerRecord18->substate == 0x14) {
                    sharedCaller4 = ownerRecord18;
                    MATCHING_KEEP(sharedCaller4);
                    sharedParameter5 = 4;
                    sharedCaller4->substate = 1;
                    sharedRawState2 = 4;
                    goto block_83;
                }
                sharedCaller4 = ownerRecord18;
                MATCHING_KEEP(sharedCaller4);
                resetParameter5 = 1;
                sharedCaller4->substate = 2;
                Level23_7D9D8Field(privateVector19, short*, 0xC) = 0x1F4;
                goto block_72;
            }
            break;
        case 4:
            var_v0_4 = Level23_7D9D8_D_8006C770;
            goto block_86;
        case 23:
            Level23_7D9D8RequestMobyAnimation(ownerRecord18, 2);
            Level23_7D9D8Field(Level23_7D9D8Field(privateVector19, void**, 0x14), short*, 0xA) = 1;
            Level23_7D9D8Field(Level23_7D9D8Field(privateVector19, void**, 0x14), short*, 2) = 1;
            goto block_81;
        case 24:
            selectedRecord17 =
                &Level23_7D9D8_D_8006C550[Level23_7D9D8Field(privateVector19, int*, 0x18)];
            if (!(selectedRecord17->state & 0x80)) {
                temp_s0_2 = &ownerRecord18->position;
                if (Level23_7D9D8ApproximatePlanarDistance(temp_s0_2,
                                                           &Level23_7D9D8_D_80070328.position) >=
                    Level23_7D9D8Field(privateVector19, short*, 0xE)) {
                    if ((unsigned int)(selectedRecord17->state - 5) >= 3U) {
                        Level23_7D9D8RequestMobyAnimation(selectedRecord17, 1);
                        if (Level23_7D9D8ApproximatePlanarDistance(
                                temp_s0_2, &selectedRecord17->position) < 0x6A4) {
                            Level23_7D9D8RequestMobyAnimation(ownerRecord18, 3);
                            ownerRecord18->state = 0x19;
                            ownerRecord18->substate = 1;
                            return;
                        }
                        Level23_7D9D8_func_80035A80(
                            ownerRecord18, Level23_7D9D8Field(privateVector19, void**, 0x14), 0x78,
                            0x5A, 0, 3, 0x80, 0x20000);
                        return;
                    }
                    nextRawState2 = 0x1A;
                    goto block_74;
                }
                goto block_71;
            }
            nextRawState2 = 0x1A;
            goto block_74;
        case 25:
            selectedRecord17 =
                &Level23_7D9D8_D_8006C550[Level23_7D9D8Field(privateVector19, int*, 0x18)];
            if (Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                       &Level23_7D9D8_D_80070328.position) <
                Level23_7D9D8Field(privateVector19, short*, 0xE)) {
            block_71:
                temp_s0_3 = selectedRecord17->mobyTag;
                ownerRecord18->state = 0x1A;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 2);
                Level23_7D9D8CopyVector(
                    (Vector3D*)temp_s0_3,
                    ((void*)((unsigned char*)Level23_7D9D8Field(
                                 Level23_7D9D8Field(privateVector19, void**, 0x14), Vector3D**,
                                 0xC) +
                             0x50)));
                sharedCaller4 = selectedRecord17;
                resetParameter5 = 0;
            block_72:
                sharedCaller4->state = 0;
                Level23_7D9D8RequestMobyAnimation(sharedCaller4, resetParameter5);
                return;
            }
            if ((unsigned int)(selectedRecord17->state - 5) < 3U) {
                nextRawState2 = 0x1A;
            block_74:
                ownerRecord18->state = nextRawState2;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 2);
                return;
            }
            Level23_7D9D8TurnMobyTowardHeading(
                ownerRecord18,
                Level23_7D9D8PlanarHeadingLookup(
                    selectedRecord17->position.x - ownerRecord18->position.x,
                    selectedRecord17->position.y - ownerRecord18->position.y, 0),
                0xA, 0, 0, 0);
            if ((ownerRecord18->substate == 1) && (ownerRecord18->animationState.id == 3) &&
                (Level23_7D9D8_func_80055E84(ownerRecord18) >= 0x12)) {
                Level23_7D9D8RequestMobyAnimation(selectedRecord17, 4);
                selectedRecord17->state = 0x1A;
                ownerRecord18->substate = 0x15;
            }
            if (Level23_7D9D8_D_8006C770 != 0) {
                {
                    register Moby* caller4 __asm__("4");
                    register int caller5 __asm__("5");
                    caller4 = ownerRecord18;
                    caller5 = 2;
                    MATCHING_KEEP2(caller4, caller5);
                    ownerRecord18->substate = 1;
                    Level23_7D9D8RequestMobyAnimation(caller4, caller5);
                }
            block_81:
                ownerRecord18->state = 0x18;
                return;
            }
            break;
        case 26:
            Level23_7D9D8CopyVector(
                privateVector19,
                Level23_7D9D8Field(Level23_7D9D8Field(privateVector19, void**, 0x14), Vector3D**,
                                   0xC));
            sharedCaller4 = ownerRecord18;
            sharedParameter5 = 2;
            MATCHING_KEEP2(sharedCaller4, sharedParameter5);
            {
                register int tag2 __asm__("2");
                tag2 = 0x3C;
                MATCHING_KEEP(tag2);
                Level23_7D9D8Field(privateVector19, short*, 0xC) = tag2;
                __asm__ volatile(""
                                 :
                                 : "m"(Level23_7D9D8Field(privateVector19, short*, 0xC))
                                 : "2");
            }
            sharedRawState2 = 0x15;
        block_83:
            MATCHING_KEEP3(sharedCaller4, sharedParameter5, sharedRawState2);
            sharedCaller4->state = sharedRawState2;
            Level23_7D9D8RequestMobyAnimation(sharedCaller4, sharedParameter5);
            return;
        case 27:
            Level23_7D9D8RequestMobyAnimation(ownerRecord18, 2);
            temp_v0_3 = Level23_7D9D8ApproximatePlanarDistance(&ownerRecord18->position,
                                                               &Level23_7D9D8_D_80070328.position);
            if (temp_v0_3 < 0x4A38) {
                if (!(Level23_7D9D8_func_80035A80(ownerRecord18,
                                                  Level23_7D9D8Field(privateVector19, void**, 0x14),
                                                  0x8C, 0x78, 0, 6, 0x80, 4) &
                      2)) {
                    var_v0_4 = temp_v0_3 < 0x2000;
                    goto block_86;
                }
                goto block_87;
            }
            return;
        block_86:
            if (var_v0_4 != 0) {
            block_87:
                ownerRecord18->state = 0;
                Level23_7D9D8RequestMobyAnimation(ownerRecord18, 0);
                return;
            }
            break;

        case 5:
            if (Level23_7D9D8_func_80035194(
                    ownerRecord18, ((void*)((unsigned char*)privateVector19 + 0x20))) == 0x100) {
                temp_v0_4 = Level23_7D9D8Field(privateVector19, void**, 0x1C);
                if (temp_v0_4 != 0) {
                    Level23_7D9D8Field(temp_v0_4, signed char*, 0x10) = 0;
                    Level23_7D9D8Field(privateVector19, void**, 0x1C) = 0;
                }
                Level23_7D9D8RefreshMobySpatialGridAndBasis(ownerRecord18, 4);
                Level23_7D9D8_func_8003BA00(ownerRecord18);
                Level23_7D9D8_func_800369B8(ownerRecord18, 0x19);
                Level23_7D9D8DeleteMoby(ownerRecord18);
                return;
            }
            ownerRecord18->unknownCollision = 0;
            break;
    }
}
#undef Level23_7D9D8Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_23/moby/func_level_23_8007E570.s SHA256 b1b6db02e35f309b46f81a03a9bd6b4e164c8a833e56ae17347135860caadbbc. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
int Controller7E570_CallRequestMobyAnimation() __asm__("func_80034F40");
int Controller7E570_Call_func_80035194() __asm__("func_80035194");
int Controller7E570_CallTurnMobyTowardPlayer() __asm__("func_8003573C");
int Controller7E570_CallTurnMobyTowardHeading() __asm__("func_8003585C");
int Controller7E570_CallCountTimerDown() __asm__("func_800359A4");
int Controller7E570_Call_func_800369B8() __asm__("func_800369B8");
int Controller7E570_Call_func_80038BF8() __asm__("func_80038BF8");
int Controller7E570_Call_func_8003BA00() __asm__("func_8003BA00");
int Controller7E570_CallPlanarHeadingLookup() __asm__("func_8004E880");
int Controller7E570_CallCopyVector() __asm__("func_8004F178");
int Controller7E570_CallAbsoluteByteAngleDelta() __asm__("func_8004F264");
#define Controller7E570Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller7E570_func_8001A358() __asm__("func_8001A358");                 /* extern */
int Controller7E570SetMobyAnimation() __asm__("func_80034F80");               /* extern */
int Controller7E570_func_80036A68() __asm__("func_80036A68");                 /* extern */
int Controller7E570ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller7E570DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7E570RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7E570_func_80055E84() __asm__("func_80055E84");                 /* extern */
int Controller7E570InterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
int Controller7E570_rand() __asm__("rand");                                   /* extern */
extern int Controller7E570_D_8006C550 __asm__("D_8006C550");
extern int Controller7E570_D_8006C770 __asm__("D_8006C770");
extern int Controller7E570_D_8006E020 __asm__("D_8006E020");
extern int Controller7E570_D_8006E024 __asm__("D_8006E024");
extern unsigned short Controller7E570_D_8006E040 __asm__("D_8006E040");
extern int Controller7E570_D_8006E344 __asm__("D_8006E344");
extern Vector3D Controller7E570_D_80070328 __asm__("D_80070328");
extern int Controller7E570_D_80071908 __asm__("D_80071908");
extern int Controller7E570_D_80071934 __asm__("D_80071934");

void func_level_23_8007E570(Moby* inputOwner) {
    register Moby* owner __asm__("$16") = inputOwner;
    /* Original scratch vector is SP+0x18..0x20; saves begin at SP+0x28.
     * Private fields and helper arguments retain their disc widths/offsets.
     * Empty constraints emit no instruction; they preserve proven producers.
     * Helpers, physical units and cadence still require a complete source chain.
     */
    struct {
        Vector3D sp18;
        unsigned char pad24[4];
    } originalFrame;

    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int angle4 __asm__("$4");
    register int angle5 __asm__("$5");
    register int word7 __asm__("$7");
    register void* call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int call6 __asm__("$6");
    register int damageArgument5 __asm__("$5");
    Moby* spawnedChild;
    register Vector3D* childPosition __asm__("$18");
    register int distanceWordState01 __asm__("$17");
    register int indexWordState6 __asm__("$17");
    register int distanceWordState6 __asm__("$18");
    register int angleWordState6 __asm__("$20");
    register int returnWord2 __asm__("$2");
    register int damageWord3 __asm__("$3");
    int indexWordState2;
    int indexWordChild;
    int var_a0;
    int var_a0_2;
    int absoluteZWordState01;
    int absoluteZWordState20;
    int var_v0_3;
    int var_v0_4;
    register void* poolRecord __asm__("$18");
    register void* privateData __asm__("$19");
    void* poolRecordState24;
    void* poolRecordState2;
    register void* packedReference14 __asm__("$3");
    register void* packedPosition __asm__("$3");

    privateData = owner->mobyTag;
    if (owner->substate == 0) {
        owner->substate = 1;
    }
    if (owner->state != 4) {
        damageWord3 = owner->damageFlags;
        if (damageWord3 != 0) {
            word2 = damageWord3 & 0x10000;
            MATCHING_KEEP_CLOBBER(word2, "$4");
            call4 = owner;
            if (word2) {
                MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "$2");
                damageArgument5 = 1;
            } else {
                __asm__ volatile("" : : "r"(call4) : "$2", "memory");
                damageArgument5 = 0;
            }
            Controller7E570_func_80036A68(call4, damageArgument5, 0, 0);
            Controller7E570_Call_func_80038BF8(owner, privateData + 0xC, 5, 4);
        }
    }
    switch (owner->state) {
        case 0:
        case 1:
            word2 = Controller7E570_D_80070328.z;
            MATCHING_KEEP(word2);
            word3 = owner->position.z;
            absoluteZWordState01 = word2 - word3;
            if (absoluteZWordState01 < 0) {
                absoluteZWordState01 = -absoluteZWordState01;
            }
            call4 = &owner->position;
            if (absoluteZWordState01 < 0x1000) {
                returnWord2 = Controller7E570ApproximatePlanarDistance(
                    call4, (void*)((unsigned char*)&Controller7E570_D_80070328.z - 8));
                call6 = 0;
                __asm__("" : "=r"(call6) : "0"(call6), "r"(returnWord2));
                distanceWordState01 = returnWord2;
                word7 = owner->position.x;
                angle4 = Controller7E570_D_8006E020;
                __asm__("" : "=r"(angle4) : "0"(angle4), "r"(word7));
                word3 = owner->position.y;
                angle5 = Controller7E570_D_8006E024;
                angle4 = word7 - angle4;
                returnWord2 = Controller7E570_CallAbsoluteByteAngleDelta(
                    (int)(Controller7E570_D_8006E040 << 0x10) >> 0x14,
                    Controller7E570_CallPlanarHeadingLookup(angle4, word3 - angle5, call6));
                if ((distanceWordState01 < Controller7E570Field(privateData, short*, 6)) &&
                    (returnWord2 < 0x18) && (Controller7E570_D_8006E344 != 1)) {
                    owner->state = 5;
                    Controller7E570_CallRequestMobyAnimation(owner, 5);
                    return;
                }
                if (distanceWordState01 < Controller7E570Field(privateData, short*, 4)) {
                    owner->state = 5;
                    Controller7E570_CallRequestMobyAnimation(owner, 5);
                }
                MATCHING_OBSERVE(distanceWordState01);
                goto state01Selector;
            }
        state01Selector:
            returnWord2 = Controller7E570_CallCountTimerDown(privateData, 4);
            call4 = owner;
            if (returnWord2) {
                call5 = 1;
                goto sharedCallMode1;
            }
            call5 = 3;
            if (Controller7E570Field(&Controller7E570_D_80070328, int*, 0x50) != 7) {
                if (Controller7E570_D_8006C770 != 0) {
                    Controller7E570Field(privateData, int*, 0) =
                        (int)(((Controller7E570_rand() & 3) * 0x3C) + 0x64);
                    goto sharedCallMode0;
                }
                default:
                    return;
            }
            goto sharedWriteState3;
        case 21:
            returnWord2 = Controller7E570ApproximatePlanarDistance(&owner->position,
                                                                   &Controller7E570_D_80070328);
            call4 = owner;
            if (returnWord2 < 0x1000) {
                call5 = 0;
                __asm__("" : "=r"(call5) : "0"(call5), "r"(call4) : "$2");
                Controller7E570Field(privateData, int*, 8) = -1;
                goto sharedClearState;
            }
            break;
        case 20:
            word2 = Controller7E570_D_80070328.z;
            MATCHING_KEEP(word2);
            word3 = owner->position.z;
            absoluteZWordState20 = word2 - word3;
            if (absoluteZWordState20 < 0) {
                absoluteZWordState20 = -absoluteZWordState20;
            }
            call4 = owner;
            if (absoluteZWordState20 < 0x1000) {
                Controller7E570_CallTurnMobyTowardPlayer(call4, 6, 6, 0);
            }
            returnWord2 = Controller7E570_CallCountTimerDown(privateData, 4);
            call4 = owner;
            if (returnWord2) {
                call5 = 1;
                __asm__("" : "=r"(call5) : "0"(call5), "r"(call4) : "$2");
                word2 = 1;
                ((Moby*)call4)->state = word2;
            sharedCallMode1:
                Controller7E570_CallRequestMobyAnimation(call4, call5);
                Controller7E570Field(privateData, int*, 0) = 0x1F4;
                return;
            }
            call5 = 3;
            if (Controller7E570Field(&Controller7E570_D_80070328, int*, 0x50) == 7) {
            sharedWriteState3:
                ((Moby*)call4)->state = 3;
                Controller7E570_CallRequestMobyAnimation(call4, call5);
                Controller7E570Field(privateData, int*, 0) =
                    (int)(((Controller7E570_rand() & 3) * 0x3C) + 0x64);
                return;
            }
            break;
        case 24:
            poolRecordState24 =
                Controller7E570_D_8006C550 + (Controller7E570Field(privateData, int*, 8) * 0x58);
            Controller7E570_CallTurnMobyTowardHeading(
                owner,
                Controller7E570_CallPlanarHeadingLookup(
                    Controller7E570Field(poolRecordState24, int*, 0xC) - owner->position.x,
                    Controller7E570Field(poolRecordState24, int*, 0x10) - owner->position.y, 0),
                8, 0, 0, 0);
            if (Controller7E570_D_8006C770 != 0) {
                owner->state = 2;
                Controller7E570_CallRequestMobyAnimation(owner, 2);
                return;
            }
            break;
        case 2:
            indexWordState2 = Controller7E570Field(privateData, int*, 8);
            if (indexWordState2 == -1) {
                Controller7E570_CallTurnMobyTowardPlayer(owner, 6, 6, 0);
            } else {
                poolRecordState2 = Controller7E570_D_8006C550 + (indexWordState2 * 0x58);
                Controller7E570_CallTurnMobyTowardHeading(
                    owner,
                    Controller7E570_CallPlanarHeadingLookup(
                        Controller7E570Field(poolRecordState2, int*, 0xC) - owner->position.x,
                        Controller7E570Field(poolRecordState2, int*, 0x10) - owner->position.y, 0),
                    8, 0, 0, 0);
            }
            if ((owner->animationState.id == 2) && (Controller7E570_func_80055E84(owner) >= 0x22) &&
                (owner->substate == 1)) {
                spawnedChild = SpawnMoby(0x17, owner);
                if (spawnedChild != 0) {
                    owner->substate = 2;
                    spawnedChild->updateDistance = 0xFF;
                    spawnedChild->angle.roll = owner->angle.roll;
                    Controller7E570RefreshMobySpatialGridAndBasis(owner, 5);
                    call4 = owner;
                    call5 = 0;
                    __asm__("" : "=r"(call5) : "0"(call5), "r"(call4));
                    childPosition = &spawnedChild->position;
                    Controller7E570InterpolateMobyVertex(call4, call5, childPosition);
                    indexWordChild = Controller7E570Field(privateData, int*, 8);
                    if (indexWordChild == -1) {
                        Controller7E570_CallTurnMobyTowardPlayer(spawnedChild, 0x80, 0, 0);
                        Controller7E570_CallCopyVector(&originalFrame.sp18,
                                                       &Controller7E570_D_80070328);
                        originalFrame.sp18.z += 0x400;
                        if ((Controller7E570_func_8001A358(&originalFrame.sp18, 0x1000) != 0) &&
                            (Controller7E570_D_80071934 == 0)) {
                            originalFrame.sp18.z = Controller7E570_D_80071908 + 0x80;
                            angle4 = Controller7E570ApproximatePlanarDistance(childPosition,
                                                                              &originalFrame.sp18);
                            angle5 = spawnedChild->position.z;
                            word2 = originalFrame.sp18.z;
                            __asm__("" : "=r"(word2) : "0"(word2), "r"(angle4), "r"(angle5));
                            call6 = 0;
                            goto sharedChildPitchWord;
                        }
                    } else {
                        word2 = indexWordChild * 11;
                        word3 = Controller7E570_D_8006C550;
                        __asm__("" : "=r"(word3) : "0"(word3), "r"(word2));
                        word2 <<= 3;
                        poolRecord = (void*)(word3 + word2);
                        __asm__("" : "=r"(poolRecord) : "0"(poolRecord), "r"(word2), "r"(word3));
                        if (Controller7E570Field(poolRecord, short*, 0x36) == 0x1A) {
                            call6 = 0;
                            word2 = Controller7E570Field(poolRecord, int*, 0);
                            angle4 = spawnedChild->position.x;
                            __asm__("" : "=r"(angle4) : "0"(angle4), "r"(word2));
                            packedReference14 = Controller7E570Field((void*)word2, void**, 0x14);
                            MATCHING_KEEP_CLOBBER(packedReference14, "memory");
                            angle5 = spawnedChild->position.y;
                            __asm__("" : "=r"(angle5) : "0"(angle5), "r"(packedReference14));
                            word2 = Controller7E570Field(packedReference14, short*, 2);
                            packedPosition =
                                (void*)Controller7E570Field(packedReference14, int*, 0xC);
                            word2 <<= 4;
                            packedPosition = (unsigned char*)packedPosition + word2;
                            MATCHING_KEEP(packedPosition);
                            word7 = Controller7E570Field(packedPosition, int*, 0);
                            word2 = Controller7E570Field(packedPosition, int*, 4);
                            angle4 = word7 - angle4;
                        } else {
                            call6 = 0;
                            word3 = Controller7E570Field(poolRecord, int*, 0xC);
                            angle4 = spawnedChild->position.x;
                            word2 = Controller7E570Field(poolRecord, int*, 0x10);
                            angle5 = spawnedChild->position.y;
                            __asm__(""
                                    : "=r"(angle5)
                                    : "0"(angle5), "r"(word2), "r"(word3), "r"(angle4));
                            angle4 = word3 - angle4;
                        }
                        Controller7E570_CallTurnMobyTowardHeading(
                            spawnedChild,
                            Controller7E570_CallPlanarHeadingLookup(angle4, word2 - angle5, call6),
                            0x80, 0, 0, 0);
                        angle4 = Controller7E570ApproximatePlanarDistance(&spawnedChild->position,
                                                                          poolRecord + 0xC);
                        call6 = 0;
                        __asm__("" : "=r"(call6) : "0"(call6), "r"(angle4));
                        angle5 = spawnedChild->position.z;
                        word2 = Controller7E570Field(poolRecord, int*, 0x14);
                    sharedChildPitchWord:
                        MATCHING_OBSERVE4_VOLATILE(angle4, angle5, word2, call6);
                        angle5 -= 0x180;
                        __asm__("" : "=r"(angle5) : "0"(angle5), "r"(word2));
                        spawnedChild->angle.pitch =
                            Controller7E570_CallPlanarHeadingLookup(angle4, word2 - angle5, call6);
                    }
                    Controller7E570Field(spawnedChild->mobyTag, int*, 0) = 0x78;
                }
            }
            if (Controller7E570_D_8006C770 != 0) {
                owner->substate = 1;
                if (Controller7E570Field(privateData, int*, 8) == -1) {
                    owner->state = 0x14;
                    Controller7E570_CallRequestMobyAnimation(owner, 0);
                } else {
                    owner->state = 3;
                    Controller7E570SetMobyAnimation(owner, 3);
                }
                Controller7E570Field(privateData, int*, 0) = 0x3C;
                return;
            }
            break;
        case 3:
            if (Controller7E570Field(privateData, int*, 8) != -1) {
                returnWord2 = Controller7E570ApproximatePlanarDistance(&owner->position,
                                                                       &Controller7E570_D_80070328);
                call4 = owner;
                if (returnWord2 >= 0x1000)
                    goto original_case3_not_near;
                call5 = 0;
                __asm__("" : "=r"(call5) : "0"(call5), "r"(call4));
                Controller7E570Field(privateData, int*, 8) = -1;
            sharedClearState:
                ((Moby*)call4)->state = 0;
                Controller7E570_CallRequestMobyAnimation(call4, call5);
                MATCHING_BARRIER_VOLATILE("$3");
                return;
            }
        original_case3_not_near:
            if (Controller7E570_D_8006C770 != 0) {
                Controller7E570_CallRequestMobyAnimation(owner, 0);
                if (Controller7E570Field(privateData, int*, 8) == -1) {
                    owner->state = 0;
                    return;
                }
                owner->state = 0x15;
                return;
            }
            break;
        case 5:
            Controller7E570_CallTurnMobyTowardPlayer(owner, 6, 6, 0);
            if (Controller7E570_D_8006C770 != 0) {
                owner->state = 6;
                Controller7E570_CallRequestMobyAnimation(owner, 6);
                return;
            }
            break;
        case 6:
            Controller7E570_CallTurnMobyTowardPlayer(owner, 6, 6, 0);
            returnWord2 = Controller7E570ApproximatePlanarDistance(&owner->position,
                                                                   &Controller7E570_D_80070328);
            call6 = 0;
            __asm__("" : "=r"(call6) : "0"(call6), "r"(returnWord2));
            distanceWordState6 = returnWord2;
            word7 = owner->position.x;
            angle4 = Controller7E570_D_8006E020;
            __asm__("" : "=r"(angle4) : "0"(angle4), "r"(word7));
            word3 = owner->position.y;
            angle5 = Controller7E570_D_8006E024;
            angle4 = word7 - angle4;
            returnWord2 = Controller7E570_CallAbsoluteByteAngleDelta(
                (int)(Controller7E570_D_8006E040 << 0x10) >> 0x14,
                Controller7E570_CallPlanarHeadingLookup(angle4, word3 - angle5, call6));
            word3 = Controller7E570Field(privateData, short*, 6);
            word3 = distanceWordState6 < word3;
            MATCHING_KEEP2(word3, returnWord2);
            angleWordState6 = returnWord2;
            if (word3 && (Controller7E570_D_8006E344 != 1) &&
                ((indexWordState6 = Controller7E570Field(privateData, int*, 8),
                  (indexWordState6 != -1)) ||
                 ((Controller7E570_CallAbsoluteByteAngleDelta(
                       Controller7E570_CallPlanarHeadingLookup(
                           Controller7E570_D_80070328.x - owner->position.x,
                           Controller7E570_D_80070328.y - owner->position.y, 0),
                       (int)owner->angle.yaw) < 0xA) &&
                  ((Controller7E570Field(privateData, int*, 8) != indexWordState6) ||
                   (angleWordState6 < 0x14))))) {
                owner->state = 2;
                Controller7E570SetMobyAnimation(owner, 2);
                return;
            }
            MATCHING_OBSERVE(angleWordState6);
            if (Controller7E570Field(privateData, short*, 4) < distanceWordState6) {
                owner->state = 7;
                Controller7E570_CallRequestMobyAnimation(owner, 7);
                return;
            }
            break;
        case 7:
            if (Controller7E570_D_8006C770 != 0) {
                owner->state = 0;
            sharedCallMode0:
                Controller7E570_CallRequestMobyAnimation(owner, 0);
                return;
            }
            break;
        case 4:
            if (Controller7E570_Call_func_80035194(owner, privateData + 0xC) == 0x100) {
                Controller7E570RefreshMobySpatialGridAndBasis(owner, 4);
                Controller7E570_Call_func_8003BA00(owner);
                Controller7E570_Call_func_800369B8(owner, 0x1C);
                Controller7E570DeleteMoby(owner);
            }
            break;
    }
}
#undef Controller7E570Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007EE44.
* AI generated; not human reviewed. All804 original instructions,35 selectors,
* one zero pad and every actual destination must match:840 owned words.
* Frame70 (112 bytes) saves S0..S4/RA and retains SP20..57 workspace. S1 private
* and scan-cursor phases are disjoint:the scan path removes the owner and
* returns before the private-field common chain. S0 record/path and S3/S4
* class,scalar,vector and path-index phases retain complete original values.
* Original private0 mask consumes a WORD,not a BYTE. Falsification:0x00010003
* &0x00FF00FF differs from3;replacing the word with its low byte falsely makes
* that test equal. The full original load and flag branch are preserved.
* Original type branches212/216 enter state clear740 on their failure paths.
* Calls234/570/572,selected-state writer499,state26 writer620,height store748
* and common749 keep physical order. Branch632 enters epilogue795 directly:
* nonzero private short36 must skip the entire common749 update chain.
* List records retain original stride88 and complete index/base/target words.
* Path short2 plus1 remains a full signed numerator/remainder with original
* divide-zero/overflow guards and widths. Count5,index4 yields remainder0.
* Full owner+12 arguments are produced after their helper or remainder phase;
* no cached overlapping alias or extra S5/frame storage is introduced.
* Fresh zero A1 in case28 and the original fallback238 entry are retained.
* Empty metadata consumes complete initialized words/addresses or clobbers
* dead values before fresh complete producers;zero CPU instructions. Known
* void34F40, timer,angle and callback views reuse matched EXE/headers.
* Compiler/filter/flags unchanged;no opcode asm,partialHI,fixedFP,undefined
* saved inputs or overlapping live aliases. Raw units/fixed point,complete
* helper/caller chains,cadence beyond invocation,Rev1 mapping and synchronized
* retail runtime remain open. Confidence is binary identity after all gates.
* Next:human review and retail captures. Every native/linked word,target,
* selector/padding byte and full EXE/every-overlay hash must remain identical.
*/
/* Original assembly SHA256 ef5761306b46e45af9c39133abbe24aced80559909dcc45f4c3bc768e69f56d6 */
#define Level23_7EE44Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level23_7EE44Call1A358View1() __asm__("func_8001A358");
int Level23_7EE44Call21ED8View1() __asm__("func_80021ED8");
int Level23_7EE44Call21F3CView1() __asm__("func_80021F3C");
int Level23_7EE44Call21F8CView1() __asm__("func_80021F8C");
int Level23_7EE44Call2EC50View1() __asm__("func_8002EC50");
void Level23_7EE44RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level23_7EE44SetMobyAnimationView1() __asm__("func_80034F80");
int Level23_7EE44TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level23_7EE44CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level23_7EE44Call35A80View1() __asm__("func_80035A80");
int Level23_7EE44Call35DDCView1() __asm__("func_80035DDC");
int Level23_7EE44Call36A68View1() __asm__("func_80036A68");
int Level23_7EE44Call37BBCView1() __asm__("func_80037BBC");
int Level23_7EE44Call3B7B4View1() __asm__("func_8003B7B4");
int Level23_7EE44PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level23_7EE44MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level23_7EE44ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level23_7EE44ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Level23_7EE44CopyVectorView1() __asm__("func_8004F178");
int Level23_7EE44AddVectorView1() __asm__("func_8004F194");
int Level23_7EE44SubtractVectorView1() __asm__("func_8004F1C8");
int Level23_7EE44AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level23_7EE44Call512E4View1() __asm__("func_800512E4");
int Level23_7EE44DeleteMobyView1() __asm__("func_80055B18");
int Level23_7EE44RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level23_7EE44InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Level23_7EE44Data6C550View1 __asm__("D_8006C550");
extern int Level23_7EE44Data6C58CView1 __asm__("D_8006C58C");
extern int Level23_7EE44Data6C640View1 __asm__("D_8006C640");
extern int Level23_7EE44Data6C648View1 __asm__("D_8006C648");
extern int Level23_7EE44Data6C704View1 __asm__("D_8006C704");
extern int Level23_7EE44Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level23_7EE44Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level23_7EE44Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level23_7EE44Data6D088View1 __asm__("D_8006D088");
extern int Level23_7EE44Data6E344View1 __asm__("D_8006E344");
extern int Level23_7EE44Data70300View1 __asm__("D_80070300");
extern int Level23_7EE44Data71908View1 __asm__("D_80071908");
void func_level_23_8007EE44(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord18 __asm__("$18");
    register int privateRecordOrScanCursor17 __asm__("$17"),
        retainedScanRecordSpawnOrPath16 __asm__("$16"),
        retainedOriginalValueOrVector19 __asm__("$19"),
        retainedClassOrSignedPathIndex20 __asm__("$20");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54;
    } originalFrame;
    int temporaryWord17;
    int temporaryWord1;
    int temporaryWord5;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord9;
    int temporaryWord16;
    int temporaryWord10;
    int temporaryWord2;
    int temporaryWord7;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord15;
    int temporaryWord8;
    int temporaryWord14;
    ownerRecord18 = ownerParameter;
    MATCHING_KEEP(ownerRecord18);
    temporaryWord12 = Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48);
    privateRecordOrScanCursor17 = Level23_7EE44Field(ownerRecord18, void**, 0);
    switch (temporaryWord12) {
        case 34:
            if (Level23_7EE44Field(ownerRecord18, int*, 0x18) != 0) {
                Level23_7EE44Field(ownerRecord18, int*, 0x18) = 0;
                Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 4);
            }
            if (!Level23_7EE44Data6C770View1)
                goto updateOriginalCommon749;
            rawWord3 = Level23_7EE44Field(ownerRecord18, unsigned char*, 60);
            rawWord2 = 4;
            argumentWord4 = (int)ownerRecord18;
            if (rawWord3 != rawWord2)
                goto updateOriginalCommon749;
            MATCHING_OBSERVE_VOLATILE(ownerRecord18);
            goto notifyOriginalZeroMode234;
        default:
            goto updateOriginalCommon749;
        case 0:
            if (Level23_7EE44Data6C640View1 == 0) {
                if ((Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 0) == 5) &&
                    ((Level23_7EE44Data6C7B4View1 & 0x20) ||
                     (Level23_7EE44Field((int)&Level23_7EE44Data70300View1, unsigned char*,
                                         Level23_7EE44Data6C58CView1) &
                      0x20))) {
                    temporaryWord6 = Level23_7EE44Call21F3CView1(1);
                    if (!((temporaryWord6 >> 8) & 0xFF) && (temporaryWord6 & 0xF)) {
                        Level23_7EE44Call21ED8View1(1, 0xFC, 0);
                        Level23_7EE44Call21F8CView1(1, 0x3A, 0);
                        privateRecordOrScanCursor17 = Level23_7EE44Data6C550View1;
                        if (privateRecordOrScanCursor17 <
                            (unsigned int)Level23_7EE44Data6C704View1) {
                            retainedClassOrSignedPathIndex20 = 105;
                            retainedOriginalValueOrVector19 = 2;
                            __asm__(""
                                    : "=r"(retainedOriginalValueOrVector19)
                                    : "0"(retainedOriginalValueOrVector19),
                                      "r"(retainedClassOrSignedPathIndex20)
                                    : "$16");
                            retainedScanRecordSpawnOrPath16 = privateRecordOrScanCursor17 + 72;
                            do {
                                if (Level23_7EE44Field(retainedScanRecordSpawnOrPath16, short*,
                                                       -18) == retainedClassOrSignedPathIndex20) {
                                    temporaryWord7 = Level23_7EE44Field(
                                        retainedScanRecordSpawnOrPath16, unsigned char*, 0);
                                    if (temporaryWord7 == 0) {
                                        Level23_7EE44Field(retainedScanRecordSpawnOrPath16,
                                                           unsigned char*, 0) =
                                            retainedOriginalValueOrVector19;
                                        Level23_7EE44Field(retainedScanRecordSpawnOrPath16,
                                                           unsigned char*, 1) =
                                            retainedOriginalValueOrVector19;
                                        Level23_7EE44Field(retainedScanRecordSpawnOrPath16,
                                                           unsigned char*, 2) = 255;
                                        Level23_7EE44SetMobyAnimationView1(
                                            (void*)privateRecordOrScanCursor17,
                                            Level23_7EE44Field(retainedScanRecordSpawnOrPath16,
                                                               unsigned char*, 0));
                                    } else if (temporaryWord7 >= 0x1EU) {
                                        Level23_7EE44DeleteMobyView1(
                                            (void*)privateRecordOrScanCursor17);
                                    }
                                }
                                rawWord2 = Level23_7EE44Data6C704View1;
                                MATCHING_KEEP_CLOBBER(privateRecordOrScanCursor17, "memory");
                                privateRecordOrScanCursor17 += 88;
                                rawWord2 = (unsigned int)privateRecordOrScanCursor17 <
                                           (unsigned int)rawWord2;
                                retainedScanRecordSpawnOrPath16 += 88;
                            } while (rawWord2);
                        }
                    }
                    goto removeOriginalOwner572;
                }
                if ((Level23_7EE44Data6C640View1 != 0) ||
                    (!(Level23_7EE44Data6C7B4View1 & 1) &&
                     !(Level23_7EE44Field((int)&Level23_7EE44Data70300View1, unsigned char*,
                                          Level23_7EE44Data6C58CView1) &
                       1)) ||
                    (Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 0) == 5)) {
                    goto checkOriginalOwnerFlags140;
                }
                goto removeOriginalOwner572;
            }
        checkOriginalOwnerFlags140:
            if (Level23_7EE44Field(ownerRecord18, int*, 0x18) != 0) {
                Level23_7EE44Field(ownerRecord18, int*, 0x18) = 0;
                Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 4);
            }
            if ((Level23_7EE44Data6C770View1 != 0) &&
                (Level23_7EE44Field(ownerRecord18, unsigned char*, 0x3C) == 4)) {
                Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 0);
            }
            temporaryWord2 = Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 0);
            if (((temporaryWord2 != 0) ||
                 (Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 4) != 3)) &&
                ((temporaryWord2 != 3) ||
                 (Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 4) != 4)) &&
                (Level23_7EE44Call37BBCView1(ownerRecord18, 0) != 0)) {
                if (((int)Level23_7EE44Field(privateRecordOrScanCursor17, int*, 0) & 0xFF00FF) ==
                    3) {
                    Level23_7EE44Data6C7B4View1 |= 1;
                }
                Level23_7EE44Call512E4View1(ownerRecord18, 0, 1);
                Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48) = 1U;
                Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 1);
            }
            goto updateOriginalCommon749;
        case 1:
            rawWord3 = Level23_7EE44Data6E344View1;
            rawWord2 = 1;
            argumentWord4 = 3;
            if (rawWord3 == rawWord2)
                goto updateOriginalCommon749;
            rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 0);
            rawWord2 = 5;
            if (rawWord3 != argumentWord4)
                goto checkOriginalTypeFive212;
            rawWord2 = 60;
            Level23_7EE44Field(privateRecordOrScanCursor17, short*, 50) = rawWord2;
            rawWord2 = 29;
            Level23_7EE44Field(ownerRecord18, unsigned char*, 72) = rawWord2;
            goto updateOriginalCommon749;
        checkOriginalTypeFive212:
            if (rawWord3 != rawWord2)
                goto enterOriginalTypeFallback238;
            rawWord2 = Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 4);
            if (rawWord2 != argumentWord4)
                goto enterOriginalTypeFallback238;
            retainedScanRecordSpawnOrPath16 = privateRecordOrScanCursor17 + 2;
            Level23_7EE44Field(ownerRecord18, unsigned char*, 72) = 34;
            Level23_7EE44Field(privateRecordOrScanCursor17, unsigned char*, 2) = 1;
            Level23_7EE44Call3B7B4View1(retainedScanRecordSpawnOrPath16, 1,
                                        (int)&Level23_7EE44Data6D088View1);
            Level23_7EE44Call3B7B4View1(retainedScanRecordSpawnOrPath16, 1,
                                        (int)&Level23_7EE44Data6C7F8View1);
            argumentWord4 = (int)ownerRecord18;
        notifyOriginalZeroMode234:
            Level23_7EE44RequestMobyAnimationView1(argumentWord4, 0);
            goto updateOriginalCommon749;
        enterOriginalTypeFallback238:
            argumentWord4 = (int)ownerRecord18;
            MATCHING_OBSERVE_VOLATILE(ownerRecord18);
            argumentWord5 = 0;
            goto clearOriginalState740;
        case 29:
            if (Level23_7EE44CountTimerDownView1(privateRecordOrScanCursor17 + 0x32, 2) != 0) {
                Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48) = 0x1EU;
                Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 2);
                Level23_7EE44Field(ownerRecord18, unsigned char*, 64) = 240;
            }
            goto updateOriginalCommon749;
        case 30:
            temporaryWord8 = (Level23_7EE44Field(privateRecordOrScanCursor17, int*, 0x40) * 0x58) +
                             Level23_7EE44Data6C550View1;
            temporaryWord9 = Level23_7EE44PlanarHeadingLookupView1(
                Level23_7EE44Field(temporaryWord8, int*, 0xC) -
                    Level23_7EE44Field(ownerRecord18, int*, 0xC),
                Level23_7EE44Field(temporaryWord8, int*, 0x10) -
                    Level23_7EE44Field(ownerRecord18, int*, 0x10),
                0);
            retainedOriginalValueOrVector19 =
                Level23_7EE44AbsoluteByteAngleDeltaView1(
                    Level23_7EE44Field(ownerRecord18, unsigned char*, 0x46), temporaryWord9) >=
                0x41;
            if ((Level23_7EE44Field(ownerRecord18, unsigned char*, 0x49) != 1) ||
                (retainedOriginalValueOrVector19 == 0)) {
                if (Level23_7EE44TurnMobyTowardHeadingView1(ownerRecord18, temporaryWord9, 4, 2, 1,
                                                            1) != 0) {
                    Level23_7EE44Field(ownerRecord18, unsigned char*, 0x49) = 1U;
                }
            }
            temporaryWord17 = 0x32;
            if (Level23_7EE44Field(ownerRecord18, unsigned char*, 0x49) == 1) {
                temporaryWord17 = 0x46;
            }
            Level23_7EE44Call35DDCView1(ownerRecord18, temporaryWord17, 0, 0, 4);
            if ((Level23_7EE44Field(ownerRecord18, unsigned char*, 0x49) == 1) &&
                (retainedOriginalValueOrVector19 != 0)) {
                Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x30) = 6;
                Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48) = 0x1FU;
            }
            goto updateOriginalCommon749;
        case 31:
            Level23_7EE44Call35DDCView1(ownerRecord18, 0x46, 0, 0, 4);
            if (Level23_7EE44CountTimerDownView1(privateRecordOrScanCursor17 + 0x30, 2) != 0) {
                goto removeOriginalOwner572;
            }
            goto updateOriginalCommon749;
        case 20:
            if ((Level23_7EE44Data6C640View1 == 0) &&
                ((Level23_7EE44Data6C7B4View1 & 1) ||
                 (Level23_7EE44Field((int)&Level23_7EE44Data70300View1, unsigned char*,
                                     Level23_7EE44Data6C58CView1) &
                  1))) {
                rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, int*, 44);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level23_7EE44Data6C550View1;
                argumentWord4 = rawWord3 + rawWord2;
                if (Level23_7EE44Field(argumentWord4, unsigned char*, 0x48) & 0x80) {
                } else {
                    goto removeOriginalChild570;
                }
                goto removeOriginalOwner572;
            }
            Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 3);
            Level23_7EE44Field(Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x28),
                               short*, 0xA) = 1;
            Level23_7EE44Field(Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x28),
                               short*, 2) = 0;
            Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48) = 0x15U;
            goto updateOriginalCommon749;
        case 21:
            Level23_7EE44Call35A80View1(
                ownerRecord18, Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x28), 0x78,
                0x5A, 0, 4, 0x80, 4);
            rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, int*, 44);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level23_7EE44Data6C550View1;
            rawWord3 += rawWord2;
            rawWord3 = Level23_7EE44Field(rawWord3, unsigned char*, 72);
            temporaryWord13 = rawWord3;
            if (((unsigned int)(temporaryWord13 - 4) < 3U) || (temporaryWord13 & 0x80)) {
                Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48) = 0x16U;
            }
            goto updateOriginalCommon749;
        case 22:
            temporaryWord14 = Level23_7EE44Field(
                Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x28), void**, 0xC);
            temporaryWord3 = Level23_7EE44Field(temporaryWord14, int*, 0x10) -
                             Level23_7EE44Field(ownerRecord18, int*, 0xC);
            originalFrame.sp20 = temporaryWord3;
            temporaryWord4 = Level23_7EE44Field(temporaryWord14, int*, 0x14) -
                             Level23_7EE44Field(ownerRecord18, int*, 0x10);
            originalFrame.sp24 = temporaryWord4;
            Level23_7EE44TurnMobyTowardHeadingView1(
                ownerRecord18,
                Level23_7EE44PlanarHeadingLookupView1(temporaryWord3, temporaryWord4, 0), 8, 4, 0,
                0);
            Level23_7EE44Call35DDCView1(ownerRecord18, 0x64, 0, 0, 0);
            if (Level23_7EE44MeasureVectorLengthView1(&originalFrame.sp20, 0) < 0x3D) {
                rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, int*, 44);
                retainedScanRecordSpawnOrPath16 = Level23_7EE44Data6C550View1;
                rawWord2 = rawWord3 * 88;
                retainedScanRecordSpawnOrPath16 += rawWord2;
                Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 2);
                rawWord3 = Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*, 72);
                rawWord2 = rawWord3 - 4;
                rawWord2 = (unsigned int)rawWord2 < 3U;
                if (rawWord2)
                    goto selectOriginalState28;
                rawWord2 = (unsigned int)rawWord3 < 251U;
                if (rawWord2)
                    goto selectOriginalState23;
            selectOriginalState28:
                rawWord2 = 28;
                goto writeOriginalSelectedState499;
            selectOriginalState23:
                rawWord2 = 23;
                goto writeOriginalSelectedState499;
            }
            goto updateOriginalCommon749;
        case 28:
            rawWord2 = Level23_7EE44TurnMobyTowardHeadingView1(ownerRecord18, 190, 4, 0, 0, 0);
            argumentWord4 = (int)ownerRecord18;
            if (!rawWord2)
                goto updateOriginalCommon749;
            MATCHING_BARRIER_VOLATILE("$5");
            argumentWord5 = 0;
            goto clearOriginalState740;
        case 23:
            rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, short*, 48);
            if (rawWord3 != 0) {
                rawWord2 = rawWord3;
                MATCHING_KEEP(rawWord2);
                rawWord2 -= 1;
                Level23_7EE44Field(privateRecordOrScanCursor17, short*, 48) = rawWord2;
                if (rawWord3 > 0) {
                    Level23_7EE44Field(ownerRecord18, int*, 0x14) =
                        (int)(Level23_7EE44Field(ownerRecord18, int*, 0x14) + 0x32);
                }
            }
            if (Level23_7EE44TurnMobyTowardHeadingView1(ownerRecord18, 0xBE, 4, 0, 0, 0) != 0) {
                if (Level23_7EE44Field(privateRecordOrScanCursor17, short*, 48) > 0)
                    goto updateOriginalCommon749;
                rawWord2 = 27;
            writeOriginalSelectedState499:
                Level23_7EE44Field(ownerRecord18, unsigned char*, 72) = rawWord2;
                rawWord2 = 16;
                Level23_7EE44Field(privateRecordOrScanCursor17, short*, 48) = rawWord2;
            }
            goto updateOriginalCommon749;
        case 27:
            rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, int*, 44);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level23_7EE44Data6C550View1;
            rawWord3 += rawWord2;
            rawWord3 = Level23_7EE44Field(rawWord3, unsigned char*, 72);
            temporaryWord15 = rawWord3;
            if (((unsigned int)(temporaryWord15 - 4) < 3U) || (temporaryWord15 >= 0xFBU)) {
                temporaryWord10 =
                    (unsigned short)Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x30);
                Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x30) =
                    (short)(temporaryWord10 - 1);
                if ((temporaryWord10 << 0x10) > 0) {
                    rawWord2 = Level23_7EE44Field(ownerRecord18, int*, 0x14) - 0x32;
                    goto storeOriginalHeight748;
                } else {
                    argumentWord4 = (int)ownerRecord18;
                    argumentWord5 = 0;
                    goto clearOriginalState740;
                }
            }
            goto updateOriginalCommon749;
        case 24:
            if ((Level23_7EE44Data6C640View1 == 0) &&
                ((Level23_7EE44Data6C7B4View1 & 1) ||
                 (Level23_7EE44Field((int)&Level23_7EE44Data70300View1, unsigned char*,
                                     Level23_7EE44Data6C58CView1) &
                  1))) {
                rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, int*, 44);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level23_7EE44Data6C550View1;
                retainedScanRecordSpawnOrPath16 = rawWord3 + rawWord2;
                if (!(Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*, 0x48) &
                      0x80)) {
                    Level23_7EE44Call36A68View1(retainedScanRecordSpawnOrPath16, 1, 0, 0);
                    argumentWord4 = retainedScanRecordSpawnOrPath16;
                removeOriginalChild570:
                    Level23_7EE44DeleteMobyView1(argumentWord4);
                }
            removeOriginalOwner572:
                Level23_7EE44DeleteMobyView1(ownerRecord18);
                return;
            }
            Level23_7EE44RequestMobyAnimationView1(ownerRecord18, 2);
            Level23_7EE44Field(ownerRecord18, unsigned char*, 0x48) = 0x19U;
            Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x30) = 0x50;
            Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x32) = 0xA;
            Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x34) = 0;
            Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x36) = 0;
            Level23_7EE44Field(Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x28),
                               short*, 2) = 1;
            Level23_7EE44CopyVectorView1(
                ownerRecord18 + 0xC,
                Level23_7EE44Field(Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x28),
                                   void**, 0xC));
            goto updateOriginalCommon749;
        case 25:
            rawWord3 = Level23_7EE44Field(privateRecordOrScanCursor17, int*, 44);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level23_7EE44Data6C550View1;
            retainedScanRecordSpawnOrPath16 = rawWord3 + rawWord2;
            temporaryWord11 =
                Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*, 0x48);
            temporaryWord16 = temporaryWord11 & 0xFF;
            if (temporaryWord11 & 128)
                goto writeOriginalState26At620;
            rawWord2 = Level23_7EE44Field(retainedScanRecordSpawnOrPath16, int*, 24);
            if (rawWord2)
                goto writeOriginalState26At620;
            rawWord2 = 4;
            if (temporaryWord16 != rawWord2)
                goto continueOriginalActiveRecord622;
        writeOriginalState26At620:
            Level23_7EE44Field(ownerRecord18, unsigned char*, 72) = 26;
            goto updateOriginalCommon749;
        continueOriginalActiveRecord622:
            if ((temporaryWord16 != 0x18) && ((unsigned int)(temporaryWord16 - 2) >= 2U) &&
                (temporaryWord16 != 0x15)) {
                Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x36) = 1;
            }
            if (Level23_7EE44Field(privateRecordOrScanCursor17, short*, 54) != 0)
                return;
            {
                if (Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x34) != 0) {
                    if ((Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*,
                                            0x3C) == 2) ||
                        ((Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*,
                                             0x3D) != 2) &&
                         (temporaryWord16 != 0x18))) {
                        Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x34) = 0;
                    }
                } else if (Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x30) != 0) {
                    retainedOriginalValueOrVector19 = (int)&originalFrame.sp30;
                    argumentWord4 = retainedOriginalValueOrVector19;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$16", "memory");
                    retainedScanRecordSpawnOrPath16 =
                        Level23_7EE44Field(privateRecordOrScanCursor17, int*, 40);
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$6", "memory");
                    argumentWord6 = (int)ownerRecord18 + 12;
                    retainedClassOrSignedPathIndex20 =
                        Level23_7EE44Field(retainedScanRecordSpawnOrPath16, short*, 2);
                    rawWord2 = Level23_7EE44Field(retainedScanRecordSpawnOrPath16, int*, 12);
                    argumentWord5 = retainedClassOrSignedPathIndex20 * 16;
                    argumentWord5 = rawWord2 + argumentWord5;
                    Level23_7EE44SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6);
                    argumentWord5 =
                        Level23_7EE44MeasureVectorLengthView1(retainedOriginalValueOrVector19, 1);
                    if (argumentWord5 >= 101) {
                        Level23_7EE44ScaleVectorRatioQ15View1(retainedOriginalValueOrVector19,
                                                              argumentWord5, 100);
                        MATCHING_KEEP_CLOBBER(ownerRecord18, "memory");
                        argumentWord4 = (int)ownerRecord18 + 12;
                    } else {
                        rawWord2 = retainedClassOrSignedPathIndex20 + 1;
                        Level23_7EE44Field(privateRecordOrScanCursor17, short*, 48) = 0;
                        rawWord3 = Level23_7EE44Field(retainedScanRecordSpawnOrPath16, short*, 0);
                        rawWord3 = rawWord2 % rawWord3;
                        Level23_7EE44Field(retainedScanRecordSpawnOrPath16, short*, 2) = rawWord3;
                        MATCHING_KEEP_CLOBBER(ownerRecord18, "memory");
                        argumentWord4 = (int)ownerRecord18 + 12;
                    }
                    MATCHING_BARRIER_VOLATILE("$19");
                    argumentWord5 = argumentWord4;
                    Level23_7EE44AddVectorView1(argumentWord4, argumentWord5, &originalFrame.sp30);
                } else if ((Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*,
                                               0x3D) != 3) &&
                           (Level23_7EE44CountTimerDownView1(privateRecordOrScanCursor17 + 0x32,
                                                             2) != 0)) {
                    Level23_7EE44Field(retainedScanRecordSpawnOrPath16, unsigned char*, 0x48) =
                        0x18U;
                    Level23_7EE44RequestMobyAnimationView1(retainedScanRecordSpawnOrPath16, 5);
                    Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x34) = 1;
                    Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x30) = 0x50;
                    Level23_7EE44Field(privateRecordOrScanCursor17, short*, 0x32) = 0xA;
                }
                goto updateOriginalCommon749;
            }
            goto updateOriginalCommon749;
        case 26:
            Level23_7EE44Field(ownerRecord18, int*, 20) =
                Level23_7EE44Field(ownerRecord18, int*, 20) - Level23_7EE44Data6C648View1 * 46 +
                1024;
            rawWord2 = Level23_7EE44Call1A358View1(ownerRecord18 + 12, 2048);
            if (!rawWord2)
                goto subtractOriginalHeight745;
            rawWord2 = Level23_7EE44Field(ownerRecord18, int*, 20);
            rawWord3 = Level23_7EE44Data71908View1;
            rawWord2 -= 1074;
            rawWord2 = rawWord2 < rawWord3;
            argumentWord4 = (int)ownerRecord18;
            if (!rawWord2)
                goto subtractOriginalHeight745;
            argumentWord5 = 0;
            Level23_7EE44Field(ownerRecord18, int*, 20) = rawWord3;
        clearOriginalState740:
            Level23_7EE44Field(ownerRecord18, int*, 24) = 0;
            Level23_7EE44Field(ownerRecord18, unsigned char*, 72) = 0;
            Level23_7EE44RequestMobyAnimationView1(argumentWord4, argumentWord5);
            goto updateOriginalCommon749;
        subtractOriginalHeight745:
            rawWord2 = Level23_7EE44Field(ownerRecord18, int*, 20);
            rawWord2 -= 1024;
        storeOriginalHeight748:
            Level23_7EE44Field(ownerRecord18, int*, 20) = rawWord2;
            goto updateOriginalCommon749;
    }
updateOriginalCommon749:
    if (Level23_7EE44Field(ownerRecord18, unsigned char*, 0x4D) == 0) {
        temporaryWord5 = Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38);
        if (temporaryWord5 != 0) {
            Level23_7EE44Field(temporaryWord5, signed char*, 0x10) = 0;
            Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38) = 0;
            goto checkOriginalPrivateObject;
        }
    } else if (Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38) == 0) {
        Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38) =
            Level23_7EE44Call2EC50View1(1, 0xFE, 0x489090);
    checkOriginalPrivateObject:
        if (Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38) != 0) {
            goto updateOriginalPrivateObject;
        }
    } else {
    updateOriginalPrivateObject:
        Level23_7EE44RefreshMobySpatialGridAndBasisView1(ownerRecord18, 5);
        Level23_7EE44InterpolateMobyVertexView1(
            ownerRecord18, 0, Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38));
        Level23_7EE44InterpolateMobyVertexView1(ownerRecord18, 1, &originalFrame.sp40);
        temporaryWord1 = Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38);
        Level23_7EE44AddVectorView1(temporaryWord1, temporaryWord1, &originalFrame.sp40);
        Level23_7EE44ShiftVectorRightTowardZeroView1(
            Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38), 1);
        Level23_7EE44Field(Level23_7EE44Field(privateRecordOrScanCursor17, void**, 0x38),
                           signed char*, 0x13) = 8;
    }
    return;
}
#undef Level23_7EE44Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007FAD4.
* AI generated; not human reviewed. All801 original instructions,26 selectors
* and every actual destination must match:827 owned words,no selector pad.
* Frame68 (104 bytes) saves S0..S4/RA and retains SP20..4F workspace. Saved
* position,player-state base,path count and height-update roles are disjoint.
* Common height chain759 follows all states and loads private8 after1A358.
* With private8=1000,helper result1200,owner20=1150,the original +100 path
* reaches1250 then clamps to1200. Units/fixed point remain unresolved.
* Shared mode calls305/590/676 and early state2 call408 retain their original
* physical entries. Literal state22/23 paths retain independent stores.
* S0 player-state base remains complete across calls. Independently relocated
* word80070330 preserves the original absolute height loads;the later player
* X read still uses original S0-80. No coordinate conversion is inferred.
* Dot-product terms are complete ordinary C products;A0/V1 retain full terms
* before the original signed sum. No synthetic HI/LO fragments are used.
* Random path advancement reloads descriptor14 after the helper,then reads
* short2 and computes the complete signed sum/remainder against retained
* count. Count5,post-call short2=3,RNG result2 yields remainder0. Original
* divide-zero and signed-overflow guards and all consumer widths remain.
* Fresh zero caller producers and owner addresses retain original branches.
* Empty metadata consumes complete initialized scalars/addresses or clobbers
* dead values before fresh complete producers;zero CPU instructions. Known
* timer,angle,void3BE70 and three-pointer4F1C8 views reuse matched source.
* Compiler/filter/flags unchanged;no opcode asm,fixedFP,undefined saved inputs
* or overlapping live aliases. Complete helper/caller chains,cadence beyond
* invocation,Rev1 correspondence and synchronized retail runtime remain open.
* Confidence is binary identity after all gates. Next:human review and retail
* captures. Every native/linked word,target,owned selector/data byte and full
* EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 3712ce3ebd54c31fb7bf8f9103a4b3d2b26a2f6970253b7cdc619a75947341fe */
#define Level23_7FAD4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level23_7FAD4Call13ACCView1() __asm__("func_80013ACC");
int Level23_7FAD4Call1A358View1() __asm__("func_8001A358");
int Level23_7FAD4Call1BA30View1() __asm__("func_8001BA30");
int Level23_7FAD4RequestMobyAnimationView1() __asm__("func_80034F40");
int Level23_7FAD4Call35030View1() __asm__("func_80035030");
int Level23_7FAD4TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level23_7FAD4TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level23_7FAD4CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level23_7FAD4Call35DDCView1() __asm__("func_80035DDC");
int Level23_7FAD4Call35EE0View1() __asm__("func_80035EE0");
int Level23_7FAD4Call360F8View1() __asm__("func_800360F8");
int Level23_7FAD4Call36220View1() __asm__("func_80036220");
int Level23_7FAD4RandBetweenView1() __asm__("func_8003636C");
int Level23_7FAD4Call369B8View1() __asm__("func_800369B8");
int Level23_7FAD4Call36A68View1() __asm__("func_80036A68");
int Level23_7FAD4Call3BA00View1() __asm__("func_8003BA00");
int Level23_7FAD4PlayMobySoundEventView1() __asm__("func_8003BABC");
void Level23_7FAD4Call3BE70View1(int) __asm__("func_8003BE70");
int Level23_7FAD4Call3BFC0View1() __asm__("func_8003BFC0");
int Level23_7FAD4PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level23_7FAD4TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level23_7FAD4CopyVectorView1() __asm__("func_8004F178");
void Level23_7FAD4SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level23_7FAD4AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level23_7FAD4ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level23_7FAD4DeleteMobyView1() __asm__("func_80055B18");
int Level23_7FAD4RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level23_7FAD4DatarandView1(void) __asm__("rand");
extern int Level23_7FAD4Data6C770View1 __asm__("D_8006C770");
extern int Level23_7FAD4Data6E020View1 __asm__("D_8006E020");
extern int Level23_7FAD4Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level23_7FAD4Data6E040View1 __asm__("D_8006E040");
extern int Level23_7FAD4Data6E160View1 __asm__("D_8006E160");
extern int Level23_7FAD4Data6E164View1 __asm__("D_8006E164");
extern int Level23_7FAD4Data70328View1 __asm__("D_80070328");
extern int Level23_7FAD4Data71934View1 __asm__("D_80071934");
extern int Level23_7FAD4OriginalPlayerHeight __asm__("D_80070328 + 8");
void func_level_23_8007FAD4(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord19 __asm__("$19"),
        retainedPositionPlayerBaseOrPathCount16 __asm__("$16"),
        retainedOwnerPosition18 __asm__("$18"), retainedOriginalHeightUpdateFlag20 __asm__("$20");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
    } originalFrame;
    int temporaryWord2;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord3;
    int temporaryWord6;
    int temporaryWord1;
    int temporaryWord4;
    int temporaryWord5;
    ownerRecord17 = ownerParameter;
    MATCHING_KEEP(ownerRecord17);
    privateRecord19 = Level23_7FAD4Field(ownerRecord17, void**, 0);
    retainedOriginalHeightUpdateFlag20 = 0;
    if (Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x49) == 0) {
        Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x49) = 1U;
        temporaryWord1 = Level23_7FAD4Field(privateRecord19, void**, 0x14);
        Level23_7FAD4Field(privateRecord19, short*, 0xC) = 0x64;
        if (temporaryWord1 != 0) {
            Level23_7FAD4Field(temporaryWord1, short*, 0xA) = 1;
            Level23_7FAD4Field(Level23_7FAD4Field(privateRecord19, void**, 0x14), short*, 2) = 1;
        }
        temporaryWord2 = Level23_7FAD4Call1A358View1(ownerRecord17 + 0xC, 0x800);
        if (temporaryWord2 != 0) {
            Level23_7FAD4Field(privateRecord19, int*, 8) = temporaryWord2;
            Level23_7FAD4Field(ownerRecord17, int*, 0x14) = temporaryWord2;
        }
    }
    if (Level23_7FAD4Call3BFC0View1(ownerRecord17,
                                    Level23_7FAD4Field(privateRecord19, int*, 0x24)) == 0) {
        Level23_7FAD4Field(privateRecord19, int*, 0x24) =
            Level23_7FAD4PlayMobySoundEventView1(ownerRecord17, 0, 4);
    }
    if (Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) != 7) {
        if (Level23_7FAD4Field(ownerRecord17, int*, 0x18) != 0) {
            Level23_7FAD4Data6E160View1 = 0;
            Level23_7FAD4Data6E164View1 = 0;
            rawWord2 = Level23_7FAD4Call1A358View1(ownerRecord17 + 12, 4096);
            if (!rawWord2)
                goto readOriginalFlagMode62;
            rawWord2 = Level23_7FAD4Data71934View1;
            argumentWord4 = (int)ownerRecord17;
            if (!rawWord2)
                goto readOriginalFlagMode62;
            argumentWord5 = 16;
            goto notifyOriginalMode70;
        readOriginalFlagMode62:
            rawWord2 = Level23_7FAD4Field(ownerRecord17, int*, 24);
            rawWord3 = 65536;
            rawWord2 &= rawWord3;
            __asm__ volatile("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2) : "$4");
            argumentWord4 = (int)ownerRecord17;
            if (!rawWord2)
                goto produceOriginalZeroMode69;
            MATCHING_OBSERVE_VOLATILE(ownerRecord17);
            argumentWord5 = 1;
            goto notifyOriginalMode70;
        produceOriginalZeroMode69:
            __asm__ volatile("" ::: "$2", "$5");
            argumentWord5 = 0;
        notifyOriginalMode70:
            argumentWord6 = 0;
            Level23_7FAD4Call36A68View1(argumentWord4, argumentWord5, argumentWord6, 0);
            Level23_7FAD4TurnMobyTowardPlayerView1(ownerRecord17, 0x80, 0, 0);
            Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x4A) = 0xFF;
            Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 7U;
            Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 7);
            Level23_7FAD4Field(privateRecord19, int*, 0x20) = 0xFA;
            Level23_7FAD4Field(privateRecord19, int*, 0x1C) = 0xC8;
            temporaryWord6 = Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x51);
            if (temporaryWord6 == 0) {
                temporaryWord6 = Level23_7FAD4Call360F8View1(
                    Level23_7FAD4PlanarHeadingLookupView1(
                        Level23_7FAD4Field(ownerRecord17, int*, 0xC) -
                            Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, int*, 0),
                        Level23_7FAD4Field(ownerRecord17, int*, 0x10) -
                            Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, int*, 4),
                        0),
                    Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, unsigned char*, 0xE),
                    0x20, 0x40);
            }
            Level23_7FAD4Field(privateRecord19, int*, 0x18) = (int)temporaryWord6;
            return;
        }
        if ((Level23_7FAD4Call36220View1((int)&Level23_7FAD4Data70328View1, privateRecord19 + 0x28,
                                         0, 0x2800) != 0) &&
            (Level23_7FAD4Field(privateRecord19, int*, 0x30) <
             Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, int*, 8))) {
            Level23_7FAD4Call13ACCView1(ownerRecord17, 0xD);
        } else {
            Level23_7FAD4Data6E160View1 = 0;
            Level23_7FAD4Data6E164View1 = 0;
        }
        goto continueOriginalStateDispatch;
    }
continueOriginalStateDispatch:
    Level23_7FAD4RefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
    temporaryWord3 = Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord3) {
        case 0:
        case 1:
            if (Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x49) == 2) {
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0x19U;
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x49) = 1U;
            } else if (Level23_7FAD4ApproximatePlanarDistanceView1(
                           ownerRecord17 + 0xC, (int)&Level23_7FAD4Data70328View1) <
                       Level23_7FAD4Field(privateRecord19, short*, 0xE)) {
                rawWord2 = Level23_7FAD4OriginalPlayerHeight;
                rawWord3 = Level23_7FAD4Field(ownerRecord17, int*, 20);
                rawWord2 -= rawWord3;
                temporaryWord7 = rawWord2;
                if (temporaryWord7 < 0) {
                    temporaryWord7 = -temporaryWord7;
                }
                if (temporaryWord7 >= 0x1000) {
                    goto checkOriginalIdleCountdown175;
                }
                goto notifyOriginalCloseTarget305;
            } else {
            checkOriginalIdleCountdown175:
                if (Level23_7FAD4CountTimerDownView1(privateRecord19 + 0xC, 2) != 0) {
                    Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 1);
                    Level23_7FAD4Field(privateRecord19, short*, 0xC) = 0x1F4;
                } else if (Level23_7FAD4Data6C770View1 != 0) {
                    Level23_7FAD4Field(privateRecord19, short*, 0xC) =
                        (short)(((Level23_7FAD4DatarandView1() & 3) * 0x3C) + 0x64);
                    goto notifyOriginalZeroMode590;
                }
            }
            goto updateOriginalCommonHeight759;
        default:
            goto updateOriginalCommonHeight759;
        case 20:
            if (Level23_7FAD4TurnMobyTowardPlayerView1(ownerRecord17, 4, 8, 0) != 0) {
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 3U;
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 3);
            }
            Level23_7FAD4Call35DDCView1(ownerRecord17, 0xA, 0, 0, 0);
            retainedOriginalHeightUpdateFlag20 = 1;
            goto updateOriginalCommonHeight759;
        case 22:
            Level23_7FAD4Call35EE0View1(
                ownerRecord17,
                (Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x46) + 0x80) & 0xFF, 0x32, 0, 0,
                0x400);
            if (Level23_7FAD4Data6C770View1 != 0) {
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 0);
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0x17U;
            }
            goto updateOriginalCommonHeight759;
        case 23:
            if (Level23_7FAD4TurnMobyTowardHeadingView1(
                    ownerRecord17,
                    Level23_7FAD4PlanarHeadingLookupView1(
                        Level23_7FAD4Field(privateRecord19, int*, 0) -
                            Level23_7FAD4Field(ownerRecord17, int*, 0xC),
                        Level23_7FAD4Field(privateRecord19, int*, 4) -
                            Level23_7FAD4Field(ownerRecord17, int*, 0x10),
                        0),
                    8, 0x14, 0, 0) != 0) {
                Level23_7FAD4Call35DDCView1(ownerRecord17, 0x3C, 0, 0, 0);
            }
            retainedPositionPlayerBaseOrPathCount16 = ownerRecord17 + 0xC;
            if (Level23_7FAD4ApproximatePlanarDistanceView1(retainedPositionPlayerBaseOrPathCount16,
                                                            privateRecord19) < 0x200) {
                Level23_7FAD4Field(privateRecord19, short*, 0xC) =
                    (short)(((Level23_7FAD4DatarandView1() & 3) * 0x32) + 0x3C);
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 0);
            }
            retainedOriginalHeightUpdateFlag20 = 1;
            if (Level23_7FAD4Field(privateRecord19, short*, 0xC) == 0) {
                if (Level23_7FAD4ApproximatePlanarDistanceView1(
                        retainedPositionPlayerBaseOrPathCount16,
                        (int)&Level23_7FAD4Data70328View1) <
                    Level23_7FAD4Field(privateRecord19, short*, 0xE)) {
                    rawWord2 = Level23_7FAD4OriginalPlayerHeight;
                    rawWord3 = Level23_7FAD4Field(ownerRecord17, int*, 20);
                    rawWord2 -= rawWord3;
                    temporaryWord8 = rawWord2;
                    if (temporaryWord8 < 0) {
                        temporaryWord8 = -temporaryWord8;
                    }
                    if (temporaryWord8 < 4096) {
                    notifyOriginalCloseTarget305:
                        Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 0);
                        Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = 20;
                    }
                }
            } else {
                Level23_7FAD4CountTimerDownView1(privateRecord19 + 0xC, 2);
            }
            goto updateOriginalCommonHeight759;
        case 3:
            Level23_7FAD4TurnMobyTowardPlayerView1(ownerRecord17, 3, 3, 0);
            if (Level23_7FAD4Data6C770View1 != 0) {
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 5;
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$2");
                rawWord2 = 5;
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = rawWord2;
                Level23_7FAD4RequestMobyAnimationView1(argumentWord4, argumentWord5);
                rawWord2 = 160;
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 64) = rawWord2;
            }
            goto updateOriginalCommonHeight759;
        case 5:
            Level23_7FAD4TurnMobyTowardPlayerView1(ownerRecord17, 6, 6, 0);
            argumentWord4 = Level23_7FAD4ApproximatePlanarDistanceView1(
                ownerRecord17 + 12, (int)&Level23_7FAD4Data70328View1);
            rawWord3 = Level23_7FAD4Field(privateRecord19, short*, 14);
            rawWord3 = rawWord3 < argumentWord4;
            if (rawWord3)
                goto enterOriginalModeFailure354;
            rawWord2 = Level23_7FAD4OriginalPlayerHeight;
            rawWord3 = Level23_7FAD4Field(ownerRecord17, int*, 20);
            rawWord2 -= rawWord3;
            if (rawWord2 < 0)
                rawWord2 = -rawWord2;
            rawWord2 = rawWord2 < 3073;
            if (rawWord2)
                goto checkOriginalCloseTarget362;
        enterOriginalModeFailure354:
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 0;
            Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = 0;
            Level23_7FAD4RequestMobyAnimationView1(argumentWord4, argumentWord5);
            rawWord2 = 160;
            Level23_7FAD4Field(ownerRecord17, unsigned char*, 64) = rawWord2;
            goto updateOriginalCommonHeight759;
        checkOriginalCloseTarget362:
            rawWord2 = Level23_7FAD4Field(privateRecord19, short*, 16);
            rawWord2 = argumentWord4 < rawWord2;
            if (!rawWord2)
                goto updateOriginalCommonHeight759;
            rawWord2 = 4;
            Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = rawWord2;
            Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 4);
            goto updateOriginalCommonHeight759;
        case 4:
            if (Level23_7FAD4Data6C770View1 != 0) {
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 2U;
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 2);
            }
            goto updateOriginalCommonHeight759;
        case 2:
            Level23_7FAD4TurnMobyTowardPlayerView1(ownerRecord17, 1, 2, 0);
            Level23_7FAD4Field(ownerRecord17, int*, 0x14) =
                (int)(Level23_7FAD4Field(ownerRecord17, int*, 0x14) + 0x200);
            rawWord2 = Level23_7FAD4Call35DDCView1(ownerRecord17, 300, 0, 0, 1024);
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2)
                goto notifyOriginalModeSix408;
            retainedPositionPlayerBaseOrPathCount16 = (int)&Level23_7FAD4Data70328View1 + 80;
            rawWord3 = Level23_7FAD4Field(retainedPositionPlayerBaseOrPathCount16, int*, 0);
            rawWord2 = 7;
            argumentWord4 = (int)&originalFrame.sp30;
            if (rawWord3 != rawWord2)
                goto continueOriginalStateTwo416;
            argumentWord4 = (int)ownerRecord17;
        notifyOriginalModeSix408:
            Level23_7FAD4RequestMobyAnimationView1(argumentWord4, 6);
            rawWord2 = Level23_7FAD4Field(ownerRecord17, int*, 20);
            rawWord3 = 22;
            Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = rawWord3;
            rawWord2 -= 512;
            Level23_7FAD4Field(ownerRecord17, int*, 20) = rawWord2;
            goto updateOriginalCommonHeight759;
        continueOriginalStateTwo416:
            retainedOriginalHeightUpdateFlag20 = 1;
            Level23_7FAD4Field(ownerRecord17, int*, 0x14) =
                (int)(Level23_7FAD4Field(ownerRecord17, int*, 0x14) - 0x200);
            Level23_7FAD4Call1BA30View1(&originalFrame.sp30, 0x514, 1, 0, 0x10000, ownerRecord17);
            if (Level23_7FAD4Field(retainedPositionPlayerBaseOrPathCount16, int*, 0) != 9) {
                temporaryWord5 = ownerRecord17 + 0x20;
                if (Level23_7FAD4Field(retainedPositionPlayerBaseOrPathCount16, int*, 0) != 4) {
                    rawWord2 = Level23_7FAD4OriginalPlayerHeight;
                    rawWord3 = Level23_7FAD4Field(ownerRecord17, int*, 20);
                    rawWord2 -= rawWord3;
                    temporaryWord9 = rawWord2;
                    if (temporaryWord9 < 0) {
                        temporaryWord9 = -temporaryWord9;
                    }
                    if ((temporaryWord9 < 0x400) &&
                        (({
                             rawWord2 = Level23_7FAD4ApproximatePlanarDistanceView1(
                                 retainedPositionPlayerBaseOrPathCount16 - 80, ownerRecord17 + 12);
                             MATCHING_KEEP(retainedPositionPlayerBaseOrPathCount16);
                             rawWord2;
                         }) < 1300) &&
                        (Level23_7FAD4AbsoluteByteAngleDeltaView1(
                             Level23_7FAD4PlanarHeadingLookupView1(
                                 Level23_7FAD4Field(retainedPositionPlayerBaseOrPathCount16, int*,
                                                    -0x50) -
                                     Level23_7FAD4Field(ownerRecord17, int*, 0xC),
                                 Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, int*, 4) -
                                     Level23_7FAD4Field(ownerRecord17, int*, 0x10),
                                 0),
                             Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x46)) < 8) &&
                        (Level23_7FAD4AbsoluteByteAngleDeltaView1(
                             (int)(Level23_7FAD4Data6E040View1 << 0x10) >> 0x14,
                             Level23_7FAD4PlanarHeadingLookupView1(
                                 Level23_7FAD4Field(ownerRecord17, int*, 0xC) -
                                     Level23_7FAD4Data6E020View1,
                                 Level23_7FAD4Field(ownerRecord17, int*, 0x10) -
                                     Level23_7FAD4Data6E024View1,
                                 0)) < 0x1C)) {
                        Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, int*, 0x24) = 1;
                        Level23_7FAD4Field((int)&Level23_7FAD4Data70328View1, int*, 0x298) =
                            (int)Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x46);
                        Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 6);
                        Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = 22;
                        Level23_7FAD4Field(privateRecord19, short*, 12) = 200;
                    } else {
                        goto block_75;
                    }
                } else {
                    goto block_76;
                }
            } else {
            block_75:
                temporaryWord5 = ownerRecord17 + 0x20;
            block_76:
                originalFrame.sp30 = 0x12C;
                originalFrame.sp34 = 0;
                originalFrame.sp38 = 0;
                Level23_7FAD4TransformVectorByBasisView1(temporaryWord5, &originalFrame.sp30,
                                                         &originalFrame.sp40);
                Level23_7FAD4SubtractVectorView1(
                    &originalFrame.sp20, (int)&Level23_7FAD4Data70328View1, ownerRecord17 + 0xC);
                if (({
                        rawWord3 = originalFrame.sp20;
                        rawWord2 = originalFrame.sp40;
                        argumentWord4 = rawWord3 * rawWord2;
                        rawWord3 = originalFrame.sp24;
                        __asm__(""
                                : "=r"(argumentWord4)
                                : "0"(argumentWord4), "r"(rawWord3)
                                : "memory");
                        rawWord2 = originalFrame.sp44;
                        rawWord3 = rawWord3 * rawWord2;
                        MATCHING_KEEP(rawWord3);
                        rawWord2 = argumentWord4 + rawWord3;
                        rawWord2;
                    }) < 0) {
                    Level23_7FAD4Field(privateRecord19, short*, 0xC) = 0x78;
                    Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0x15U;
                }
            }
            goto updateOriginalCommonHeight759;
        case 21:
            retainedOriginalHeightUpdateFlag20 = 1;
            Level23_7FAD4Field(ownerRecord17, int*, 0x14) =
                (int)(Level23_7FAD4Field(ownerRecord17, int*, 0x14) + 0x64);
            Level23_7FAD4TurnMobyTowardHeadingView1(
                ownerRecord17,
                Level23_7FAD4PlanarHeadingLookupView1(
                    Level23_7FAD4Field(privateRecord19, int*, 0) -
                        Level23_7FAD4Field(ownerRecord17, int*, 0xC),
                    Level23_7FAD4Field(privateRecord19, int*, 4) -
                        Level23_7FAD4Field(ownerRecord17, int*, 0x10),
                    0),
                8, 8, 0, 0);
            Level23_7FAD4Call35DDCView1(ownerRecord17, 0x12C, 0, 0, 0x400);
            if ((Level23_7FAD4ApproximatePlanarDistanceView1(ownerRecord17 + 0xC, privateRecord19) <
                 0x800) ||
                (Level23_7FAD4CountTimerDownView1(privateRecord19 + 0xC, 2) != 0)) {
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 6U;
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 6);
            } else {
                Level23_7FAD4Field(ownerRecord17, int*, 0x14) =
                    (int)(Level23_7FAD4Field(ownerRecord17, int*, 0x14) - 0x64);
            }
            goto updateOriginalCommonHeight759;
        case 6:
            if (Level23_7FAD4Data6C770View1 != 0) {
                rawWord2 = Level23_7FAD4ApproximatePlanarDistanceView1(ownerRecord17 + 12,
                                                                       privateRecord19);
                rawWord3 = Level23_7FAD4Field(privateRecord19, short*, 18);
                rawWord3 = rawWord3 < rawWord2;
                MATCHING_KEEP(rawWord3);
                if (rawWord3) {
                    Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 0);
                    Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = 23;
                    Level23_7FAD4Field(privateRecord19, short*, 12) = 200;
                    goto updateOriginalCommonHeight759;
                }
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0U;
            notifyOriginalZeroMode590:
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 0);
                goto updateOriginalCommonHeight759;
            }
            goto updateOriginalCommonHeight759;
        case 24:
            temporaryWord4 = Level23_7FAD4Field(privateRecord19, void**, 0x14);
            retainedPositionPlayerBaseOrPathCount16 =
                Level23_7FAD4Field(temporaryWord4, int*, 0xC) +
                (Level23_7FAD4Field(temporaryWord4, short*, 2) * 0x10);
            Level23_7FAD4TurnMobyTowardHeadingView1(
                ownerRecord17,
                Level23_7FAD4PlanarHeadingLookupView1(
                    Level23_7FAD4Field(retainedPositionPlayerBaseOrPathCount16, int*, 0) -
                        Level23_7FAD4Field(ownerRecord17, int*, 0xC),
                    Level23_7FAD4Field(retainedPositionPlayerBaseOrPathCount16, int*, 4) -
                        Level23_7FAD4Field(ownerRecord17, int*, 0x10),
                    0),
                4, 4, 0, 0);
            Level23_7FAD4Call35DDCView1(ownerRecord17, 0x3C, 0, 0, 0);
            retainedOwnerPosition18 = ownerRecord17 + 0xC;
            if (Level23_7FAD4ApproximatePlanarDistanceView1(
                    retainedOwnerPosition18, retainedPositionPlayerBaseOrPathCount16) < 0x200) {
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0x19U;
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 1);
            } else if (Level23_7FAD4ApproximatePlanarDistanceView1(
                           retainedOwnerPosition18, (int)&Level23_7FAD4Data70328View1) <
                       Level23_7FAD4Field(privateRecord19, short*, 0xE)) {
                rawWord2 = Level23_7FAD4OriginalPlayerHeight;
                rawWord3 = Level23_7FAD4Field(ownerRecord17, int*, 20);
                rawWord2 -= rawWord3;
                temporaryWord10 = rawWord2;
                if (temporaryWord10 < 0) {
                    temporaryWord10 = -temporaryWord10;
                }
                argumentWord4 = (int)ownerRecord17;
                if (temporaryWord10 >= 4096)
                    goto updateOriginalCommonHeight759;
                MATCHING_OBSERVE_VOLATILE(ownerRecord17);
                goto notifyOriginalSharedCloseTarget676;
            }
            goto updateOriginalCommonHeight759;
        case 25:
            if (Level23_7FAD4ApproximatePlanarDistanceView1(ownerRecord17 + 0xC,
                                                            (int)&Level23_7FAD4Data70328View1) <
                Level23_7FAD4Field(privateRecord19, short*, 0xE)) {
                rawWord2 = Level23_7FAD4OriginalPlayerHeight;
                rawWord3 = Level23_7FAD4Field(ownerRecord17, int*, 20);
                rawWord2 -= rawWord3;
                temporaryWord11 = rawWord2;
                if (temporaryWord11 < 0) {
                    temporaryWord11 = -temporaryWord11;
                }
                argumentWord4 = (int)ownerRecord17;
                if (temporaryWord11 < 4096) {
                notifyOriginalSharedCloseTarget676:
                    Level23_7FAD4RequestMobyAnimationView1(argumentWord4, 0);
                    Level23_7FAD4Field(ownerRecord17, unsigned char*, 72) = 20;
                    Level23_7FAD4Field(ownerRecord17, unsigned char*, 73) = 2;
                    goto updateOriginalCommonHeight759;
                }
                goto checkOriginalPathAdvance683;
            }
        checkOriginalPathAdvance683:
            if (Level23_7FAD4Data6C770View1 != 0) {
                rawWord2 = Level23_7FAD4Field(privateRecord19, int*, 20);
                retainedPositionPlayerBaseOrPathCount16 = Level23_7FAD4Field(rawWord2, short*, 0);
                rawWord2 =
                    Level23_7FAD4RandBetweenView1(1, retainedPositionPlayerBaseOrPathCount16 - 1);
                argumentWord6 = Level23_7FAD4Field(privateRecord19, int*, 20);
                rawWord3 = Level23_7FAD4Field(argumentWord6, short*, 2);
                rawWord3 += rawWord2;
                rawWord2 = rawWord3 % retainedPositionPlayerBaseOrPathCount16;
                Level23_7FAD4Field(argumentWord6, short*, 2) = rawWord2;
                Level23_7FAD4RequestMobyAnimationView1(ownerRecord17, 0);
                Level23_7FAD4Field(ownerRecord17, unsigned char*, 0x48) = 0x18U;
            }
            goto updateOriginalCommonHeight759;
        case 7:
            if ((Level23_7FAD4Call35030View1(ownerRecord17, privateRecord19 + 0x20,
                                             Level23_7FAD4Field(privateRecord19, int*, 0x18),
                                             privateRecord19 + 0x1C, 8, 0x10, 0x200, 0x23) == 3) ||
                (Level23_7FAD4Data6C770View1 != 0)) {
                if (Level23_7FAD4Call3BFC0View1(
                        ownerRecord17, Level23_7FAD4Field(privateRecord19, int*, 0x24)) != 0) {
                    Level23_7FAD4Call3BE70View1(Level23_7FAD4Field(privateRecord19, int*, 0x24));
                }
                Level23_7FAD4Field(privateRecord19, int*, 0x24) = -1;
                Level23_7FAD4RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Level23_7FAD4Call3BA00View1(ownerRecord17);
                Level23_7FAD4Call369B8View1(ownerRecord17, 0x28);
                Level23_7FAD4DeleteMobyView1(ownerRecord17);
                return;
            }
            goto updateOriginalCommonHeight759;
    }
    goto updateOriginalCommonHeight759;
updateOriginalCommonHeight759:
    retainedPositionPlayerBaseOrPathCount16 = (int)&originalFrame.sp40;
    if (retainedOriginalHeightUpdateFlag20) {
        Level23_7FAD4CopyVectorView1(retainedPositionPlayerBaseOrPathCount16, ownerRecord17 + 12);
        argumentWord4 = retainedPositionPlayerBaseOrPathCount16;
        rawWord2 = originalFrame.sp48;
        argumentWord5 = 5000;
        rawWord2 += 2048;
        originalFrame.sp48 = rawWord2;
        rawWord2 = Level23_7FAD4Call1A358View1(argumentWord4, argumentWord5);
        argumentWord4 = Level23_7FAD4Field(privateRecord19, int*, 8);
        rawWord3 = rawWord2;
        rawWord2 = argumentWord4 < rawWord3;
        if (rawWord2) {
            rawWord2 = Level23_7FAD4Field(ownerRecord17, int*, 20);
            rawWord2 += 100;
            Level23_7FAD4Field(ownerRecord17, int*, 20) = rawWord2;
            rawWord2 = rawWord3 < rawWord2;
            goto clampOriginalHeight789;
        }
        rawWord2 = Level23_7FAD4Field(ownerRecord17, int*, 20);
        if (rawWord2 == argumentWord4)
            return;
        rawWord2 -= 100;
        Level23_7FAD4Field(ownerRecord17, int*, 20) = rawWord2;
        rawWord3 = Level23_7FAD4Field(privateRecord19, int*, 8);
        rawWord2 = rawWord2 < rawWord3;
    clampOriginalHeight789:
        if (rawWord2)
            Level23_7FAD4Field(ownerRecord17, int*, 20) = rawWord3;
    }
    return;
}
#undef Level23_7FAD4Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned low;
#else
        unsigned low;
        int high;
#endif
    } words;
} Level23_80758Product;
/* SCUS-94467 USA Rev0. AI generated; not human reviewed. UNINSTALLED conditional original1395 C.
 * Selector6<=8 and16<=7 lifecycle remains unproved. No acceptance. */
#define Level23_80758Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level23_80758Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level23_80758_func_8001830C() __asm__("func_8001830C");
int Level23_80758_func_8001A358() __asm__("func_8001A358");
int Level23_80758SetMobyAnimation() __asm__("func_80034F80");
int Level23_80758TurnMobyTowardPlayer() __asm__("func_8003573C");
int Level23_80758TurnMobyTowardHeading() __asm__("func_8003585C");
int Level23_80758CountTimerDown() __asm__("func_800359A4");
int Level23_80758_func_80035DDC() __asm__("func_80035DDC");
int Level23_80758PlayMobySoundEvent() __asm__("func_8003BABC");
int Level23_80758PlanarHeadingLookup() __asm__("func_8004E880");
int Level23_80758TransformVectorByBasis() __asm__("func_8004ED6C");
int Level23_80758ShiftVectorRightTowardZero() __asm__("func_8004F110");
int Level23_80758CopyVector() __asm__("func_8004F178");
int Level23_80758AddVector() __asm__("func_8004F194");
int Level23_80758SubtractVector() __asm__("func_8004F1C8");
int Level23_80758ApproximatePlanarDistance() __asm__("func_8004F334");
int Level23_80758DeleteMoby() __asm__("func_80055B18");
int Level23_80758RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level23_80758_func_80055E84() __asm__("func_80055E84");
int Level23_80758_rand() __asm__("rand");
extern int Level23_80758_D_8006C550 __asm__("D_8006C550");
extern int Level23_80758_D_8006C574 __asm__("D_8006C574");
extern int Level23_80758_D_8006C578 __asm__("D_8006C578");
extern int Level23_80758_D_8006C58C __asm__("D_8006C58C");
extern int Level23_80758_D_8006C76C __asm__("D_8006C76C");
extern int Level23_80758_D_8006C770 __asm__("D_8006C770");
extern int Level23_80758_D_8006EE2C __asm__("D_8006EE2C");
extern int Level23_80758_D_80070328 __asm__("D_80070328");
extern signed char Level23_80758_D_80071573 __asm__("D_80071573");
extern int Level23_80758_D_80071908 __asm__("D_80071908");
extern int Level23_80758_D_80071934 __asm__("D_80071934");
extern int Level23_80758_D_level_23_800963E4 __asm__("D_level_23_800963E4");
extern int (*Level23_80758SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level23_80758SpawnParticle)() __asm__("SpawnParticle");
extern int Level23_80758_func_level_23_80075578 __asm__("func_level_23_80075578");
extern int Level23_80758_main_TEXT_END __asm__("main_TEXT_END");
extern int Level23_80758_main_TEXT_START __asm__("main_TEXT_START");
void func_level_23_80080758(void* input) {
    register int saved16 __asm__("$16"), saved17 __asm__("$17"), saved18 __asm__("$18"),
        privateState __asm__("$19"), owner __asm__("$20"), saved21 __asm__("$21"),
        saved22 __asm__("$22"), saved23 __asm__("$23");
    register int temporary10 __asm__("$10"), temporary9 __asm__("$9"), temporary8 __asm__("$8"),
        result __asm__("$2"), scratch __asm__("$3"), argument0 __asm__("$4"),
        argument1 __asm__("$5"), argument2 __asm__("$6"), argument3 __asm__("$7");
    Level23_80758Product quotientProduct;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84,
            sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC,
            spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4;
    } locals;

    int temp_a1;

    int temp_v1_2;

    int temp_v1_4;

    int temp_a2;

    int temp_v0;

    int temp_v0_7;

    int temp_v1_13;

    int var_v0;

    int var_v0_3;

    int var_v0_4;

    int var_v0_9;

    int temp_v0_2;

    int temp_v0_8;

    int temp_v1_3;

    int temp_a0;

    int temp_a0_2;

    int temp_a0_3;

    int temp_v1;

    int temp_v1_11;

    int temp_v1_12;

    int temp_v1_14;

    int temp_v1_5;

    int var_a0;

    int var_a0_2;

    /* Explicit original inherited memory; not an ordinary C initializer. */
    __asm__("" : "=m"(locals.sp98), "=m"(locals.sp9C), "=m"(locals.spA0));
    owner = (int)input;
    Level23_80758Keep(owner);
    saved17 = 2;
    Level23_80758Keep(saved17);
    temp_v1 = Level23_80758Field(owner, unsigned char*, 0x48);
    privateState = Level23_80758Field(owner, int*, 0);
    if (temp_v1 == saved17) {
        goto block_112;
    }
    if ((int)temp_v1 >= 3) {
        goto block_4;
    }
    argument0 = (int)&locals.sp18;
    if (temp_v1 == 1) {
        goto block_7;
    }
    goto block_204;
block_4:
    if (temp_v1 == 0x14) {
        goto block_118;
    }
    if (temp_v1 == 0x15) {
        goto block_48;
    }
    goto block_204;
block_7:
    saved16 = (int)&Level23_80758_D_80070328 + 0x98;
    Level23_80758Keep(saved16);
    scratch = Level23_80758Field(privateState, int*, 0);
    result = (unsigned int)scratch * 88U;
    scratch = Level23_80758_D_8006C550;
    scratch += result;
    Level23_80758Keep(scratch);
    saved21 = Level23_80758Field(scratch, int*, 0);
    __asm__("" : "=r"(saved16) : "0"(saved16), "r"(saved21));
    Level23_80758CopyVector(argument0, saved16);
    temp_a2 = locals.sp1C;
    locals.sp18 *= 0x23;
    locals.sp1C = temp_a2 * 0x23;
    locals.sp20 *= 0x23;
    Level23_80758ShiftVectorRightTowardZero(&locals.sp18, 6);
    argument0 = (int)&locals.sp18;
    argument1 = argument0;
    __asm__("" : "=r"(saved16) : "0"(saved16), "r"(argument1));
    saved16 -= 0x98;
    Level23_80758AddVector(argument0, argument1, saved16);
    Level23_80758TurnMobyTowardHeading(
        owner,
        Level23_80758PlanarHeadingLookup(locals.sp18 - Level23_80758Field(owner, int*, 0xC),
                                         locals.sp1C - Level23_80758Field(owner, int*, 0x10), 0),
        0xA, 2, 0, 0);
    saved18 = owner + 0xC;
    temp_v0 = Level23_80758ApproximatePlanarDistance(saved18, saved16);
    if (temp_v0 < 0x201) {
        goto block_22;
    }
    if (Level23_80758Field(owner, unsigned char*, 0x49) != saved17) {
        goto block_15;
    }
    Level23_80758RefreshMobySpatialGridAndBasis(owner, 4);
    saved17 = owner + 0x20;
    locals.sp28 = 0x200;
    locals.sp2C = 0;
    locals.sp30 = 0;
    Level23_80758TransformVectorByBasis(saved17, &locals.sp28, &locals.sp28);
    Level23_80758AddVector(&locals.sp28, saved18, &locals.sp28);
    locals.sp38 = 0;
    locals.sp3C = 0x100;
    locals.sp40 = 0;
    Level23_80758TransformVectorByBasis(saved17, &locals.sp38, &locals.sp38);
    Level23_80758AddVector(&locals.sp48, saved18, &locals.sp38);
    Level23_80758SubtractVector(&locals.sp38, saved18, &locals.sp38);
    if (Level23_80758_func_8001830C(saved18, &locals.sp28, 7, 0, 0) != 0) {
        goto block_11;
    }
    if (Level23_80758_func_8001830C(&locals.sp38, &locals.sp48, 7, 0, 0) == 0) {
        goto block_21;
    }
block_11:
    if (Level23_80758Field(saved21, short*, 0xE) < 0) {
        goto block_33;
    }
    if (temp_v0 < 0x1001) {
        goto block_14;
    }
    Level23_80758Field(owner, int*, 0xC) =
        (int)Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0);
    Level23_80758Field(owner, int*, 0x10) =
        (int)Level23_80758Field((int)&Level23_80758_D_80070328, int*, 4);
block_14:
    Level23_80758Field(owner, int*, 0x14) = (int)(Level23_80758Field(saved21, short*, 0xE) - 0x100);
    goto block_30;
block_15:
    temp_v1_2 = Level23_80758Field(saved21, short*, 0xE);
    if (temp_v1_2 <= 0) {
        goto block_30;
    }
    var_v0 = Level23_80758Field((int)&Level23_80758_D_80070328, int*, 8) - temp_v1_2;
    if (var_v0 >= 0) {
        goto block_18;
    }
    var_v0 = -var_v0;
block_18:
    if (var_v0 >= 0x578) {
        goto block_30;
    }
    Level23_80758RefreshMobySpatialGridAndBasis(owner, 4);
    saved17 = owner + 0x20;
    locals.sp58 = 0x200;
    locals.sp5C = 0;
    locals.sp60 = 0;
    Level23_80758TransformVectorByBasis(saved17, &locals.sp58, &locals.sp58);
    Level23_80758AddVector(&locals.sp58, saved18, &locals.sp58);
    locals.sp68 = 0;
    locals.sp6C = 0x100;
    locals.sp70 = 0;
    Level23_80758TransformVectorByBasis(saved17, &locals.sp68, &locals.sp68);
    Level23_80758AddVector(&locals.sp78, saved18, &locals.sp68);
    Level23_80758SubtractVector(&locals.sp68, saved18, &locals.sp68);
    if (Level23_80758_func_8001830C(saved18, &locals.sp58, 7, 0, 0) != 0) {
        goto block_30;
    }
    if (Level23_80758_func_8001830C(&locals.sp68, &locals.sp78, 7, 0, 0) != 0) {
        goto block_30;
    }
block_21:
    Level23_80758_func_80035DDC(owner, 0xC8, 0, 0, 0x400);
    goto block_30;
block_22:
    result = Level23_80758Field(owner, int*, 0x14);
    scratch = Level23_80758Field((int)&Level23_80758_D_80070328, int*, 8);
    result -= scratch;
    if (result >= 0) {
        goto block_24;
    }
    result = -result;
block_24:
    if (result >= 0x400) {
        goto block_30;
    }
    if (Level23_80758Field(saved21, unsigned char*, 0x12) != 0) {
        goto block_28;
    }
    if (Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0x50) != 0xA) {
        goto block_28;
    }
    Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0x24) =
        (int)(Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0x24) | 0x200);
    Level23_80758PlayMobySoundEvent(owner, 0, 0);
    Level23_80758Field(saved21, unsigned char*, 0x12) = 0x1EU;
    goto block_29;
block_28:
    if (Level23_80758Field(owner, unsigned char*, 0x49) == 2) {
        goto block_204;
    }
block_29:
    Level23_80758SetMobyAnimation(owner, 2);
    Level23_80758Field(owner, unsigned char*, 0x48) = 2U;
    goto block_204;
block_30:
    if (Level23_80758Field(saved21, short*, 0xE) < 0) {
        goto block_33;
    }
    Level23_80758Field(owner, signed char*, 0x57) = 0x30;
    Level23_80758Field(privateState, short*, 0xA) = 0;
    Level23_80758SetMobyAnimation(owner, 1);
    if (Level23_80758Field(privateState, short*, 8) >= 0x1E) {
        goto block_204;
    }
    Level23_80758Field(privateState, short*, 8) = 0x1E;
    goto block_204;
block_33:
    temp_a0 = Level23_80758Field(owner, unsigned char*, 0x49);
    if (temp_a0 != 2) {
        goto block_38;
    }
    temp_v1_3 = Level23_80758Field(saved21, signed char*, 5);
    if (temp_v1_3 < 2) {
        goto block_38;
    }
    if (temp_v1_3 != temp_a0) {
        goto block_37;
    }
    if (!(Level23_80758Field(saved21, unsigned short*, 0xC) & 0x200)) {
        goto block_38;
    }
block_37:
    Level23_80758Field(privateState, short*, 8) = 0x64;
    goto block_204;
block_38:
    var_a0 = privateState + 8;
    if (Level23_80758Field(privateState, short*, 0xA) != 0) {
        goto block_41;
    }
    if ((unsigned int)((unsigned short)Level23_80758Field(privateState, short*, 8) - 5) >= 0x1BU) {
        goto block_41;
    }
    Level23_80758Field(privateState, short*, 0xA) = 0x1E;
    Level23_80758Field(privateState, unsigned char*, 0x11) = 2U;
    var_a0 = privateState + 8;
block_41:
    if (Level23_80758CountTimerDown(({
                                        argument0 = privateState + 8;
                                        Level23_80758Keep(argument0);
                                        argument0;
                                    }),
                                    2) == 0) {
        goto block_204;
    }
    result = Level23_80758Field(saved21, unsigned char*, 5);
    result--;
    Level23_80758Field(saved21, unsigned char*, 5) = result;
    __asm__ volatile("" ::"m"(Level23_80758Field(saved21, unsigned char*, 5)));
    scratch = (signed char)result;
    if (scratch <= 0) {
        goto block_45;
    }
    if (scratch != 1) {
        goto block_111;
    }
    if (Level23_80758Field(saved21, unsigned short*, 0xC) & 0x200) {
        goto block_111;
    }
block_45:
    if (scratch >= 0) {
        goto block_47;
    }
    Level23_80758Field(saved21, signed char*, 5) = 0;
block_47:
    Level23_80758Field(saved21, signed char*, 6) = 0;
    Level23_80758Field(saved21, unsigned short*, 0xC) =
        (unsigned short)(Level23_80758Field(saved21, unsigned short*, 0xC) | 0x1FF);
    goto block_111;
block_48:
    argument0 = 1;
    scratch = Level23_80758Field(privateState, int*, 0);
    result = (unsigned int)scratch * 88U;
    scratch = Level23_80758_D_8006C550;
    scratch += result;
    Level23_80758Keep(scratch);
    result = Level23_80758Field(privateState, unsigned char*, 4);
    saved22 = Level23_80758Field(scratch, int*, 0);
    __asm__("" : "=r"(argument0) : "0"(argument0), "r"(result));
    if (result != argument0) {
        goto block_52;
    }
    Level23_80758Field(privateState, unsigned char*, 4) = 2U;
    Level23_80758CopyVector(&locals.sp78, owner + 0xC);
    locals.sp80 += 0x400;
    if (Level23_80758_func_8001A358(&locals.sp78, 0xC00) == 0) {
        goto block_52;
    }
    if (Level23_80758_D_80071934 == 0) {
        goto block_109;
    }
    Level23_80758Field(owner, int*, 0x14) = (int)(Level23_80758_D_80071908 - 0x100);
block_52:
    temp_v1_4 = Level23_80758Field(saved22, short*, 0xE);
    if (temp_v1_4 <= 0) {
        goto block_63;
    }
    var_v0_3 = Level23_80758Field((int)&Level23_80758_D_80070328, int*, 8) - temp_v1_4;
    if (var_v0_3 >= 0) {
        goto block_55;
    }
    var_v0_3 = -var_v0_3;
block_55:
    if (var_v0_3 >= 0x400) {
        goto block_63;
    }
    if (Level23_80758Field(privateState, unsigned char*, 7) != 0) {
        goto block_62;
    }
    if (Level23_80758Field(owner, unsigned char*, 0x3D) != 2) {
        goto block_62;
    }
    if (Level23_80758_func_80055E84(owner) < 5) {
        goto block_62;
    }
    if (Level23_80758_func_80055E84(owner) >= 0x17) {
        goto block_61;
    }
    Level23_80758Field(privateState, unsigned char*, 7) = 1U;
block_61:
block_62:
    Level23_80758SetMobyAnimation(owner, 1);
    Level23_80758Field(saved22, unsigned short*, 0xC) =
        (unsigned short)(Level23_80758Field(saved22, unsigned short*, 0xC) | 0x200);
    Level23_80758Field(privateState, short*, 8) = 0xC8;
    Level23_80758Field(privateState, short*, 0xA) = 0;
    Level23_80758Field(owner, signed char*, 0x57) = 0x30;
    Level23_80758Field(owner, unsigned char*, 0x48) = 1U;
    result = Level23_80758Field(privateState, int*, 0x14);
    Level23_80758Field(owner, unsigned char*, 0x49) = 0;
    Level23_80758Field(owner, int*, 0x14) = result;
    goto block_204;
block_63:
    if (Level23_80758Field(privateState, short*, 8) >= 0xC8) {
        goto block_80;
    }
    if (Level23_80758Field(owner, unsigned char*, 0x3D) != 2) {
        goto block_67;
    }
    if (Level23_80758_func_80055E84(owner) < 3) {
        goto block_67;
    }
    if (Level23_80758_func_80055E84(owner) < 0x18) {
        goto block_80;
    }
block_67:
    if (Level23_80758Field(privateState, unsigned char*, 7) != 0) {
        goto block_72;
    }
    if (Level23_80758Field(owner, unsigned char*, 0x3D) != 2) {
        goto block_72;
    }
    if (Level23_80758_func_80055E84(owner) < 5) {
        goto block_72;
    }
    if (Level23_80758_func_80055E84(owner) >= 0x17) {
        goto block_72;
    }
    Level23_80758Field(privateState, unsigned char*, 7) = 1U;
block_72:
    if (Level23_80758Field(privateState, short*, 8) < 0x23) {
        goto block_74;
    }
    Level23_80758SetMobyAnimation(owner, 1);
block_74:
    Level23_80758Field(owner, int*, 0x14) = (int)Level23_80758Field(privateState, int*, 0x14);
    Level23_80758TurnMobyTowardHeading(
        owner,
        (Level23_80758PlanarHeadingLookup(
             Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0) -
                 Level23_80758Field(owner, int*, 0xC),
             Level23_80758Field((int)&Level23_80758_D_80070328, int*, 4) -
                 Level23_80758Field(owner, int*, 0x10),
             0) +
         0x80) &
            0xFF,
        6, 6, 0, 0);
    Level23_80758RefreshMobySpatialGridAndBasis(owner, 4);
    saved18 = owner + 0x20;
    locals.sp48 = 0x200;
    locals.sp4C = 0;
    locals.sp50 = 0;
    Level23_80758TransformVectorByBasis(saved18, &locals.sp48, &locals.sp48);
    argument0 = (int)&locals.sp48;
    Level23_80758Keep(argument0);
    saved16 = owner + 12;
    Level23_80758AddVector(argument0, saved16, &locals.sp48);
    locals.sp88 = 0;
    locals.sp8C = 0x100;
    locals.sp90 = 0;
    Level23_80758TransformVectorByBasis(saved18, &locals.sp88, &locals.sp88);
    Level23_80758AddVector(&locals.sp98, saved16, &locals.sp88);
    Level23_80758SubtractVector(&locals.sp88, saved16, &locals.sp88);
    if (Level23_80758_func_8001830C(saved16, &locals.sp48, 7, 0, 0) != 0) {
        goto block_77;
    }
    if (Level23_80758_func_8001830C(&locals.sp88, &locals.sp98, 7, 0, 0) != 0) {
        goto block_77;
    }
    Level23_80758_func_80035DDC(owner, 0x3C, 0, 0, 0);
block_77:
    var_a0_2 = privateState + 8;
    if ((unsigned int)((unsigned short)Level23_80758Field(privateState, short*, 8) - 5) >= 0x1BU) {
        goto block_108;
    }
    if (Level23_80758Field(privateState, short*, 0xA) != 0) {
        goto block_108;
    }
    Level23_80758Field(privateState, short*, 0xA) = 0x1E;
    Level23_80758Field(privateState, unsigned char*, 0x11) = 2U;
    goto block_108;
block_80:
    Level23_80758TurnMobyTowardPlayer(owner, 0xA, 2, 0);
    Level23_80758Keep(owner);
    saved18 = owner + 12;
    if (Level23_80758Field(owner, unsigned char*, 0x3D) != 2) {
        goto block_89;
    }
    if (Level23_80758Field(owner, unsigned char*, 0x49) != 0) {
        goto block_85;
    }
    if (Level23_80758_func_80055E84(owner) < 3) {
        goto block_85;
    }
    if (Level23_80758_func_80055E84(owner) >= 9) {
        goto block_85;
    }
    scratch = 1;
    result = Level23_80758Field(owner, int*, 0x14);
    Level23_80758Field(owner, unsigned char*, 0x49) = scratch;
    result += 200;
    var_v0_4 = result;
    goto block_88;
block_85:
    Level23_80758Keep(owner);
    saved18 = owner + 12;
    if (Level23_80758Field(owner, unsigned char*, 0x49) != 1) {
        goto block_89;
    }
    result = Level23_80758_func_80055E84(owner);
    Level23_80758Keep(owner);
    saved18 = owner + 12;
    if (result < 0x16) {
        goto block_89;
    }
    Level23_80758Field(owner, unsigned char*, 0x49) = 0U;
    var_v0_4 = Level23_80758Field(owner, int*, 0x14) - 0xC8;
block_88:
    Level23_80758Field(owner, int*, 0x14) = var_v0_4;
    Level23_80758Keep(owner);
    saved18 = owner + 12;
block_89:
    if (Level23_80758ApproximatePlanarDistance(saved18, (int)&Level23_80758_D_80070328) < 0x5DD) {
        goto block_101;
    }
    if (Level23_80758Field(privateState, unsigned char*, 0x13) == 0) {
        goto block_92;
    }
    Level23_80758CountTimerDown(({
                                    argument0 = privateState + 8;
                                    Level23_80758Keep(argument0);
                                    argument0;
                                }),
                                2);
    goto block_204;
block_92:
    Level23_80758RefreshMobySpatialGridAndBasis(owner, 4);
    saved17 = owner + 0x20;
    locals.spA8 = 0x200;
    locals.spAC = 0;
    locals.spB0 = 0;
    Level23_80758TransformVectorByBasis(saved17, &locals.spA8, &locals.spA8);
    Level23_80758AddVector(&locals.spA8, saved18, &locals.spA8);
    locals.spB8 = 0;
    locals.spBC = 0x100;
    locals.spC0 = 0;
    Level23_80758TransformVectorByBasis(saved17, &locals.spB8, &locals.spB8);
    Level23_80758AddVector(&locals.spC8, saved18, &locals.spB8);
    Level23_80758SubtractVector(&locals.spB8, saved18, &locals.spB8);
    if (Level23_80758_func_8001830C(saved18, &locals.spA8, 7, 0, 0) != 0) {
        goto block_95;
    }
    if (Level23_80758_func_8001830C(&locals.spB8, &locals.spC8, 7, 0, 0) != 0) {
        goto block_95;
    }
    Level23_80758_func_80035DDC(owner, 0x3C, 0, 0, 0);
    Level23_80758SetMobyAnimation(owner, 1);
    var_a0_2 = privateState + 8;
    goto block_108;
block_95:
    if (Level23_80758Field(privateState, unsigned char*, 4) != 0) {
        goto block_97;
    }
    Level23_80758Field(privateState, unsigned char*, 4) = 1U;
block_97:
    Level23_80758Field(privateState, unsigned char*, 0x13) = 1U;
    Level23_80758SetMobyAnimation(owner, 2);
    var_a0_2 = privateState + 8;
    if (Level23_80758Field(privateState, unsigned char*, 7) != 0) {
        goto block_108;
    }
    var_a0_2 = privateState + 8;
    if (Level23_80758_func_80055E84(owner) < 0x16) {
        goto block_108;
    }
    var_a0_2 = privateState + 8;
    if (Level23_80758_func_80055E84(owner) >= 0x1B) {
        goto block_108;
    }
    Level23_80758Field(privateState, unsigned char*, 7) = 1U;
    goto block_108;
block_101:
    if (Level23_80758Field(privateState, unsigned char*, 4) != 0) {
        goto block_103;
    }
    Level23_80758Field(privateState, unsigned char*, 4) = 1U;
block_103:
    Level23_80758SetMobyAnimation(owner, 2);
    var_a0_2 = privateState + 8;
    if (Level23_80758Field(privateState, unsigned char*, 7) != 0) {
        goto block_108;
    }
    var_a0_2 = privateState + 8;
    if (Level23_80758_func_80055E84(owner) < 0x16) {
        goto block_108;
    }
    if (Level23_80758_func_80055E84(owner) >= 0x1B) {
        goto block_107;
    }
    Level23_80758Field(privateState, unsigned char*, 7) = 1U;
block_107:
    var_a0_2 = privateState + 8;
block_108:
    if (Level23_80758CountTimerDown(({
                                        argument0 = privateState + 8;
                                        Level23_80758Keep(argument0);
                                        argument0;
                                    }),
                                    2) == 0) {
        goto block_204;
    }
block_109:
    result = Level23_80758Field(saved22, unsigned short*, 0xC);
    scratch = Level23_80758Field(saved22, unsigned char*, 5);
    result |= 512;
    scratch--;
    Level23_80758Field(saved22, unsigned char*, 5) = scratch;
    scratch = (unsigned int)scratch << 24;
    Level23_80758Field(saved22, unsigned short*, 0xC) = result;
    if (scratch >= 0)
        goto block_111;
    Level23_80758Field(saved22, unsigned char*, 5) = 0;
block_111:
    Level23_80758DeleteMoby(owner);
    return;
block_112:
    if (Level23_80758Field(privateState, unsigned char*, 7) != 0) {
        goto block_116;
    }
    if (Level23_80758_func_80055E84(owner) < 0x15) {
        goto block_116;
    }
    if (Level23_80758_func_80055E84(owner) >= 0x1B) {
        goto block_116;
    }
    Level23_80758Field(privateState, unsigned char*, 7) = 1U;
block_116:
    if (Level23_80758_D_8006C770 == 0) {
        goto block_204;
    }
    Level23_80758SetMobyAnimation(owner, 1);
    Level23_80758Field(owner, unsigned char*, 0x48) = 1U;
    Level23_80758Field(privateState, unsigned char*, 7) = 0U;
    goto block_204;
block_118:
    argument0 = privateState + 24;
    Level23_80758Keep(argument0);
    saved16 = owner + 12;
    Level23_80758Field(owner, signed char*, 0x41) = 0;
    Level23_80758Field(owner, signed char*, 0x4C) = 0;
    Level23_80758Field(owner, signed char*, 0x4D) = 0;
    Level23_80758CopyVector(argument0, saved16);
    Level23_80758CopyVector(saved16, (int)&Level23_80758_D_80070328);
    if ((unsigned int)Level23_80758Field(privateState, volatile unsigned int*, 0x28) <
        (unsigned int)(int)&Level23_80758_func_level_23_80075578) {
        goto block_126;
    }
    argument1 = 0;
    argument2 = (int)&Level23_80758_D_level_23_800963E4;
    Level23_80758Keep(argument2);
loop_120:
    scratch = Level23_80758Field(privateState, volatile unsigned int*, 0x28);
    if ((unsigned int)scratch >= (unsigned int)argument2) {
        goto block_126;
    }
    argument0 = 0;
    Level23_80758Field(privateState, volatile int*, 0x24) =
        (int)(Level23_80758Field(privateState, volatile int*, 0x24) ^
              (Level23_80758Field(scratch, unsigned char*, 0) << 8));
loop_122:
    scratch = Level23_80758Field(privateState, volatile int*, 0x24);
    if (scratch & 0x8000)
        result = ((unsigned int)scratch << 1) ^ 0x8005U;
    else
        result = (unsigned int)scratch << 1;
block_124:
    Level23_80758Field(privateState, volatile int*, 0x24) = result;
    argument0 += 1;
    if (argument0 < 8) {
        goto loop_122;
    }
    argument1 += 1;
    Level23_80758Field(privateState, volatile unsigned int*, 0x28) =
        (unsigned int)(Level23_80758Field(privateState, volatile unsigned int*, 0x28) + 1);
    if (argument1 < 0x40) {
        goto loop_120;
    }
block_126:
    if (Level23_80758Field(privateState, unsigned char*, 0x12) == 0) {
        goto block_129;
    }
    if (Level23_80758CountTimerDown(privateState + 0x12, 1) == 0) {
        goto block_129;
    }
    Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0x284) = 0;
block_129:
    if (Level23_80758Field(privateState, signed char*, 5) <= 0) {
        goto block_134;
    }
    if (Level23_80758_func_8001A358((int)&Level23_80758_D_80070328, 0x2800) == 0) {
        goto block_133;
    }
    if (Level23_80758_D_80071934 == 0) {
        goto block_133;
    }
    Level23_80758Field(privateState, short*, 0xE) = (short)Level23_80758_D_80071908;
    goto block_134;
block_133:
    Level23_80758Field(privateState, short*, 0xE) = -1;
block_134:
    result = Level23_80758Field(privateState, volatile unsigned int*, 0x28);
    if (result != 0) {
        goto block_136;
    }
    Level23_80758Field(privateState, volatile unsigned int*, 0x28) =
        (unsigned int)(Level23_80758_D_8006C58C + ((int)&Level23_80758_main_TEXT_START + 2));
    result = Level23_80758Field(privateState, volatile unsigned int*, 0x28);
block_136:
    scratch = (int)&Level23_80758_main_TEXT_END;
    Level23_80758Keep(scratch);
    if ((unsigned int)result >= (unsigned int)scratch) {
        goto block_146;
    }
    argument1 = 0;
    argument2 = scratch;
    Level23_80758Keep(argument2);
loop_138:
    scratch = Level23_80758Field(privateState, volatile unsigned int*, 0x28);
    if ((unsigned int)scratch >= (unsigned int)argument2) {
        goto block_145;
    }
    argument0 = 0;
    Level23_80758Field(privateState, volatile int*, 0x24) =
        (int)(Level23_80758Field(privateState, volatile int*, 0x24) ^
              (Level23_80758Field(scratch, unsigned char*, 0) << 8));
loop_140:
    scratch = Level23_80758Field(privateState, volatile int*, 0x24);
    if (scratch & 0x8000)
        result = ((unsigned int)scratch << 1) ^ 0x8005U;
    else
        result = (unsigned int)scratch << 1;
block_142:
    Level23_80758Field(privateState, volatile int*, 0x24) = result;
    argument0 += 1;
    if (argument0 < 8) {
        goto loop_140;
    }
    argument1 += 1;
    result = Level23_80758Field(privateState, volatile int*, 0x24);
    scratch = Level23_80758Field(privateState, volatile unsigned int*, 0x28);
    result &= 3;
    result++;
    scratch = (unsigned int)scratch + (unsigned int)result;
    Level23_80758Field(privateState, unsigned int*, 0x28) = scratch;
    if (argument1 < 0x40) {
        goto loop_138;
    }
    result = (int)&Level23_80758_main_TEXT_END;
    result = (unsigned int)scratch < (unsigned int)result;
    if (result) {
        goto block_146;
    }
block_145:
    Level23_80758Field(privateState, volatile unsigned int*, 0x28) =
        (unsigned int)(int)&Level23_80758_func_level_23_80075578;
block_146:
    if (Level23_80758Field(privateState, signed char*, 5) >= 5) {
        goto block_201;
    }
    if ((unsigned int)(Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0x50) - 2) < 2U) {
        goto block_149;
    }
    if (Level23_80758Field((int)&Level23_80758_D_80070328, int*, 0x50) != 5) {
        goto block_180;
    }
block_149:
    Level23_80758CopyVector(&locals.spC8, ((int)&Level23_80758_D_80070328 + 0x50) - 0x50);
    locals.spD0 += 0x200;
    saved16 = Level23_80758_func_8001A358(&locals.spC8, 0x2800);
    if (saved16 <= 0) {
        goto block_201;
    }
    saved21 = 1;
    if (Level23_80758_D_80071934 == 0) {
        goto block_201;
    }
    result = saved16 - 0x100;
    __asm__("" : "=r"(result) : "0"(result), "r"(saved16));
    locals.spD0 = result;
    temp_v1_11 = Level23_80758Field(privateState, unsigned char*, 6);
    saved22 = 0;
    if (temp_v1_11 >= 9U) {
        goto block_165;
    }
    switch (temp_v1_11) {
        case 0:
            saved21 = 0;
            goto block_165;
        case 1:
            locals.sp98 = 0x1000;
            __asm__ volatile("" ::"m"(locals.sp98));
            locals.sp9C = 0;
            goto block_164;
        case 2:
            result = 0x1000;
            goto block_162;
        case 3:
            locals.sp98 = 0x1000;
            result = -0x1000;
            goto block_163;
        case 4:
            result = -0x1000;
            locals.sp98 = 0;
            goto block_163;
        case 5:
            result = 0x1000;
            locals.sp98 = 0;
            goto block_163;
        case 6:
            locals.sp98 = -0x1000;
            result = 0x1000;
            goto block_163;
        case 7:
            locals.sp98 = -0x1000;
            locals.sp9C = 0;
            goto block_164;
        case 8:
            result = -0x1000;
        block_162:
            locals.sp98 = result;
        block_163:
            locals.sp9C = result;
        block_164:
            locals.spA0 = 0;
    }
block_165:
    if (saved21 == 0) {
        goto block_169;
    }
    Level23_80758TransformVectorByBasis((int)&Level23_80758_D_80070328 + 0x30, &locals.sp98,
                                        &locals.sp98);
    locals.spA0 = 0;
    Level23_80758AddVector(&locals.spD8, &locals.spC8, &locals.sp98);
    if (Level23_80758_func_8001830C(&locals.spC8, &locals.spD8, 7, 0, 0) == 0) {
        goto block_168;
    }
    saved22 = 1;
    goto block_169;
block_168:
    Level23_80758CopyVector(&locals.spC8, &locals.spD8);
block_169:
    argument2 = 0;
    if (saved22 != 0) {
        goto block_176;
    }
    result = Level23_80758SpawnMoby(0x16, owner, 0);
    saved17 = result;
    Level23_80758Keep(saved17);
    saved18 = 1;
    if (saved17 == 0) {
        goto block_204;
    }
    Level23_80758Keep(saved18);
    MATCHING_BARRIER("$22");
    argument0 = Level23_80758_D_8006C550;
    saved16 = Level23_80758Field(saved17, int*, 0);
    argument0 = owner - argument0;
    result = 0U - (unsigned int)argument0 * 0x45D1745DU;
    result >>= 3;
    Level23_80758Field(saved16, int*, 0) = result;
    Level23_80758Field(saved16, short*, 8) = 0x64;
    Level23_80758Field(saved16, signed char*, 4) = 0;
    Level23_80758Field(saved16, short*, 0xA) = 0x1E;
    Level23_80758Field(saved16, signed char*, 0x11) = saved18;
    if (locals.spD0 < 0x1CE9) {
        goto block_173;
    }
    Level23_80758Field(saved16, int*, 0x14) = locals.spD0;
block_173:
    Level23_80758CopyVector(saved17 + 0xC, &locals.spC8);
    Level23_80758TurnMobyTowardPlayer(saved17, 0x80, 2, 0);
    Level23_80758SetMobyAnimation(saved17, 1);
    Level23_80758Field(saved17, signed char*, 0x48) = saved18;
    Level23_80758Field(saved17, unsigned char*, 0x4A) = 255;
    Level23_80758Field(saved17, signed char*, 0x47) = 0;
    if (saved21 != 0) {
        goto block_175;
    }
    Level23_80758Field(saved17, signed char*, 0x49) = 2;
block_175:
    result = 1;
    scratch = Level23_80758Field(privateState, unsigned char*, 5);
    argument0 = Level23_80758Field(privateState, unsigned char*, 6);
    scratch++;
    argument1 = (unsigned int)result << argument0;
    Level23_80758Field(privateState, unsigned char*, 5) = scratch;
    Level23_80758Field(saved16, unsigned short*, 0xC) = argument1;
    result = Level23_80758Field(privateState, unsigned short*, 0xC);
    scratch = ~argument1;
    result &= scratch;
    Level23_80758Field(privateState, unsigned short*, 0xC) = result;
    __asm__ volatile("" ::"m"(Level23_80758Field(privateState, unsigned short*, 0xC)) : "$6");
    argument2 = 0;
block_176:
    temporary8 = 0x38E38E39;
    Level23_80758Keep(temporary8);
    temporary9 = 1;
    Level23_80758Keep(temporary9);
    argument3 = Level23_80758Field(privateState, short*, 0xC);
loop_177:
    argument0 = Level23_80758Field(privateState, unsigned char*, 6);
    argument0++;
    Level23_80758Keep(argument0);
    quotientProduct.full = (long long)(int)argument0 * (long long)(int)temporary8;
    __asm__("" : "=x"(quotientProduct.full) : "0"(quotientProduct.full));
    argument2++;
    result = argument0 >> 31;
    __asm__("" : "=x"(quotientProduct.full) : "0"(quotientProduct.full), "r"(result));
    temporary10 = quotientProduct.words.high;
    Level23_80758Keep(temporary10);
    scratch = temporary10 >> 1;
    scratch -= result;
    result = (unsigned int)scratch << 3;
    result += scratch;
    argument0 -= result;
    argument1 = (unsigned int)temporary9 << argument0;
    result = argument3 & argument1;
    Level23_80758Field(privateState, unsigned char*, 6) = argument0;
    if (result)
        goto block_201;
    result = argument2 < 10;
    Level23_80758Keep(result);
    if (result == 0)
        goto block_201;
    goto loop_177;
block_180:
    if (!(Level23_80758Field(privateState, unsigned short*, 0xC) & 0x200)) {
        goto block_201;
    }
    temp_v1_12 = Level23_80758Field(privateState, unsigned char*, 0x10);
    if (temp_v1_12 >= 8U) {
        goto block_194;
    }
    switch (temp_v1_12) {
        case 0:
            result = 0x1800;
            locals.sp98 = result;
            __asm__ volatile("" ::"m"(locals.sp98));
            result = 512;
            Level23_80758Keep(result);
            locals.sp9C = 0;
            goto actor1395FinalVector;
        case 1:
            result = 0x1800;
            goto actor1395BothVector;
        case 2:
            result = 0x1800;
            locals.sp98 = result;
            __asm__ volatile("" ::"m"(locals.sp98));
            result = -0x1800;
            goto actor1395VectorY;
        case 3:
            result = -0x1800;
            locals.sp9C = result;
            __asm__ volatile("" ::"m"(locals.sp9C));
            result = 512;
            Level23_80758Keep(result);
            locals.sp98 = 0;
            goto actor1395FinalVector;
        case 4:
            result = 0x1800;
            locals.sp9C = result;
            __asm__ volatile("" ::"m"(locals.sp9C));
            result = 512;
            Level23_80758Keep(result);
            locals.sp98 = 0;
            goto actor1395FinalVector;
        case 5:
            result = -0x1800;
            locals.sp98 = result;
            __asm__ volatile("" ::"m"(locals.sp98));
            result = 0x1800;
            goto actor1395VectorY;
        case 6:
            result = -0x1800;
            locals.sp98 = result;
            __asm__ volatile("" ::"m"(locals.sp98));
            result = 512;
            Level23_80758Keep(result);
            locals.sp9C = 0;
            goto actor1395FinalVector;
        case 7:
            result = -0x1800;
        actor1395BothVector:
            locals.sp98 = result;
        actor1395VectorY:
            locals.sp9C = result;
            __asm__ volatile("" ::"m"(locals.sp9C));
            result = 512;
            Level23_80758Keep(result);
        actor1395FinalVector:
            locals.spA0 = result;
    }
block_194:
    saved17 = (int)&Level23_80758_D_80070328 + 0x30;
    Level23_80758TransformVectorByBasis(saved17, &locals.sp98, &locals.sp98);
    saved18 = (int)&locals.spC8;
    Level23_80758Keep(saved18);
    Level23_80758AddVector(saved18, saved17 - 0x30, &locals.sp98);
    result = Level23_80758_func_8001A358(saved18, 0x2800);
    saved16 = result;
    Level23_80758Keep(saved16);
    if (saved16 == 0) {
        goto block_198;
    }
    if (Level23_80758_D_80071934 == 0) {
        goto block_198;
    }
    result = Level23_80758SpawnMoby(0x16, owner);
    saved17 = result;
    Level23_80758Keep(saved17);
    argument0 = saved17 + 12;
    if (saved17 == 0) {
        goto block_204;
    }
    argument1 = Level23_80758_D_8006C550;
    __asm__("" : "=r"(saved16) : "0"(saved16), "r"(argument1));
    result = saved16 - 0x100;
    Level23_80758Keep(result);
    locals.spD0 = result;
    saved16 = Level23_80758Field(saved17, int*, 0);
    argument1 = owner - argument1;
    result = 0U - (unsigned int)argument1 * 0x45D1745DU;
    result >>= 3;
    Level23_80758Field(saved16, int*, 0) = result;
    Level23_80758Field(saved16, short*, 8) = 0x258;
    Level23_80758Field(saved16, short*, 0xA) = 0x1E;
    Level23_80758Field(saved16, signed char*, 4) = 0;
    Level23_80758Field(saved16, signed char*, 0x11) = 1;
    result = locals.spD0;
    argument1 = saved18;
    Level23_80758Field(saved16, short*, 0xC) = 0;
    Level23_80758Field(saved16, signed char*, 0x13) = 0;
    Level23_80758Field(saved16, int*, 0x14) = result;
    Level23_80758CopyVector(argument0, argument1);
    Level23_80758TurnMobyTowardPlayer(saved17, 0x80, 2, 0);
    Level23_80758Field(saved17, unsigned char*, 0x4A) = 255;
    Level23_80758Field(saved17, signed char*, 0x47) = 0;
    Level23_80758SetMobyAnimation(saved17, 1);
    Level23_80758Field(saved17, signed char*, 0x48) = 0x15;
    Level23_80758Field(privateState, signed char*, 5) =
        (signed char)((unsigned char)Level23_80758Field(privateState, signed char*, 5) + 1);
    Level23_80758Field(privateState, unsigned short*, 0xC) =
        (unsigned short)(Level23_80758Field(privateState, unsigned short*, 0xC) & 0xFDFF);
block_198:
    temp_a0_3 = Level23_80758Field(privateState, unsigned char*, 0x10);
    temp_v1_13 = temp_a0_3 + 1;
    var_v0_9 = temp_v1_13;
    if (temp_v1_13 >= 0) {
        goto block_200;
    }
    var_v0_9 = temp_a0_3 + 8;
block_200:
    Level23_80758Field(privateState, unsigned char*, 0x10) =
        (unsigned char)(temp_v1_13 - (var_v0_9 & 0x1F8));
block_201:
    if (Level23_80758Field(privateState, unsigned int*, 0x28) !=
        (int)&Level23_80758_D_level_23_800963E4) {
        goto block_204;
    }
    if (Level23_80758Field(privateState, int*, 0x24) == 0) {
        goto block_204;
    }
    Level23_80758_rand();
    Level23_80758_D_8006C76C = 0;
    Level23_80758_D_80071573 = 1;
    Level23_80758Field(privateState, int*, 0x24) = 0;
block_204:
    if (Level23_80758Field(privateState, short*, 0xA) == 0) {
        goto block_214;
    }
    if (Level23_80758Field(privateState, unsigned char*, 0x11) != 1) {
        goto block_208;
    }
    Level23_80758SetMobyAnimation(owner, 0);
    Level23_80758Field(owner, signed char*, 0x57) =
        (signed char)(((int)((unsigned short)Level23_80758Field(privateState, short*, 0xA)
                             << 0x10) >>
                       0x11) +
                      0x30);
    if (Level23_80758CountTimerDown(privateState + 0xA, 2) == 0) {
        goto block_214;
    }
    Level23_80758Field(owner, signed char*, 0x57) = 0x30;
    Level23_80758SetMobyAnimation(owner, 1);
    goto block_214;
block_208:
    if (Level23_80758Field(owner, unsigned char*, 0x3C) == 0) {
        goto block_210;
    }
    result = Level23_80758Field(owner, short*, 0x36);
    Level23_80758Field(owner, signed char*, 0x42) = 0;
    result = (unsigned int)result << 2;
    result = Level23_80758Field((int)&Level23_80758_D_8006EE2C, int*, result);
    result = Level23_80758Field(result, int*, 0x3C);
    result = Level23_80758Field(result, unsigned char*, 0);
    Level23_80758Field(owner, unsigned char*, 0x3C) = 0;
    Level23_80758Field(owner, unsigned char*, 0x3D) = 0;
    result = (unsigned int)result < 2;
    result ^= 1;
    result = -result;
    result &= 48;
    Level23_80758Field(owner, unsigned char*, 0x40) = result;
block_210:
    temp_v0_8 = ((int)(0x1E - Level23_80758Field(privateState, short*, 0xA)) >> 1) + 0x30;
    Level23_80758Field(owner, signed char*, 0x57) = temp_v0_8;
    if ((unsigned int)(temp_v0_8 & 0xFF) >= 0x38U) {
        goto block_212;
    }
    Level23_80758Field(owner, signed char*, 0x57) = 0x38;
block_212:
    if (Level23_80758CountTimerDown(privateState + 0xA, 2) == 0) {
        goto block_214;
    }
    Level23_80758Field(owner, signed char*, 0x57) = 0x3F;
block_214:
    temp_v1_14 = Level23_80758Field(privateState, unsigned char*, 7);
    if (temp_v1_14 == 0) {
        goto block_221;
    }
    if (temp_v1_14 != 1) {
        goto block_219;
    }
    if ((Level23_80758_D_8006C578 - Level23_80758_D_8006C574) < 0x15) {
        goto block_219;
    }
    result = Level23_80758SpawnMoby(0x19C, owner);
    temporary8 = result;
    Level23_80758Keep(temporary8);
    argument0 = 1;
    if (temporary8 == 0)
        goto block_219;
    argument1 = 43;
    argument2 = temporary8 + 12;
    argument3 = 1;
    MATCHING_OBSERVE4_VOLATILE(argument0, argument1, argument2, argument3);
    scratch = Level23_80758Field(owner, int*, 0x14);
    result = 1;
    Level23_80758Field(temporary8, unsigned char*, 0x47) = result;
    result = (int)Level23_80758SpawnParticle;
    __asm__("" : "=r"(scratch) : "0"(scratch), "r"(result));
    scratch += 256;
    Level23_80758Field(temporary8, int*, 0x14) = scratch;
    ((int (*)())result)(argument0, argument1, argument2, argument3);
    Level23_80758Field(privateState, unsigned char*, 7) = 2U;
block_219:
    if (Level23_80758_D_8006C770 == 0) {
        goto block_221;
    }
    Level23_80758Field(privateState, unsigned char*, 7) = 0U;
block_221:
    return;
}

#undef Level23_80758Field
#undef Level23_80758Keep

/* Reuses uninstalled probe660 and verified bounce-projectile interfaces.
 * Original Rev0 8007C8BC..8007CB70,173 words. Correct the earlier candidate:
 * class26/state<25 takes the damage flag write; only state>=25 animates.
 * Tag words0/4/8, raw matrix/vector calls, fresh mode/player gate reads and
 * flags0x10030000 follow original instructions. Word names are inherited
 * provisional labels, not a claim about physical units or helper semantics.
 * SFX selector/payload/playback timing, table producers and caller cadence
 * remain unresolved. Empty constraints emit no instructions and preserve
 * GCC2.7.2 lifetimes. AI-generated reconstruction; not yet human reviewed. */
typedef struct {
    int timer, gravity, speed;
} DecodedGroundProjectileTag;
extern int D_8006E044;
extern int DecodedGroundProjectilePlayerGate __asm__("D_80070328+0x240");
extern int DecodedGroundProjectilePlayerHeading __asm__("D_80070328+0x298");
extern Moby* D_8006C550;
int DecodedGroundProjectileHeight(Vector3D*, int, int, Moby*) __asm__("func_8001A310");
int DecodedGroundProjectileSweep(Vector3D*, Vector3D*, int, int, int) __asm__("func_8001830C");
int DecodedGroundProjectilePlayer(Vector3D*, int, int) __asm__("func_8001C288");
Moby* DecodedGroundProjectileActor(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
void DecodedGroundProjectileSound(Moby*, int, int) __asm__("func_8003BABC");
void DecodedGroundProjectileDraw(Moby*, int) __asm__("func_80055D24");
void DecodedGroundProjectileTransform(void*, void*, void*) __asm__("func_8004ED6C");
void DecodedGroundProjectileAdd(void*, void*, void*) __asm__("func_8004F194");
void func_level_23_80081D24(Moby* argument) {
    register Moby* moby __asm__("$17") = argument;
    register DecodedGroundProjectileTag* tag __asm__("$19") = moby->mobyTag;
    register int height __asm__("$16") = 0;
    register int hit __asm__("$20") = 0;
    Vector3D velocity;
    int pad24;
    Vector3D previous;
    int pad34;
    register Moby* actor __asm__("$16");
    register Vector3D* movingPosition __asm__("$16");
    register Vector3D* position __asm__("$18") = &moby->position;
    velocity.x = 0;
    velocity.y = 0;
    velocity.z = 6;
    SpawnParticle(1, 0, position, &velocity);
    if (func_800359A4(&tag->timer, 4) ||
        (height = DecodedGroundProjectileHeight(position, 200, 3, moby))) {
        if (height)
            moby->position.z = height;
        goto remove;
    }
    {
        DecodedGroundProjectileDraw(moby, 4);
        func_8004F178(&previous, position);
        if (moby->state == 1)
            velocity.x = tag->speed;
        else
            velocity.x = 200;
        velocity.y = 0;
        velocity.z = 0;
        DecodedGroundProjectileTransform(&moby->rotationMatrix, &velocity, &velocity);
        movingPosition = &moby->position;
        DecodedGroundProjectileAdd(movingPosition, movingPosition, &velocity);
        if (moby->state == 1) {
            moby->position.z -= tag->gravity;
            tag->gravity += 16;
            return;
        }
        if (DecodedGroundProjectileSweep(&previous, movingPosition, 3, 0, 0)) {
            DecodedGroundProjectileSound(moby, 1, 0);
            hit = 1;
        }
        MATCHING_KEEP(moby);
        if (D_8006E044 != 9 && D_8006E044 != 11 && !DecodedGroundProjectilePlayerGate &&
            DecodedGroundProjectilePlayer(movingPosition, 128, 7)) {
            DecodedGroundProjectileSound(moby, 0, 0);
            DecodedGroundProjectilePlayerHeading = moby->angle.yaw;
            hit = 1;
        } else {
            actor = DecodedGroundProjectileActor(&moby->position, 256, 2, 0, 0,
                                                 &D_8006C550[moby->linkedMoby]);
            if (actor) {
                DecodedGroundProjectileSound(moby, 0, 0);
                if (actor->mobyClass == 0x1A && actor->state >= 25) {
                    func_80034F40(actor, 4);
                    actor->state = 4;
                    hit = 1;
                } else {
                    hit = 1;
                    actor->damageFlags |= 0x10030000;
                }
            }
        }
        if (hit) {
        remove:
            func_800369B8(moby, 25);
            func_80055B18(moby);
        }
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * level23:80081FD8, complete original243 instructions in sibling4402.
 * Raw offsets and helper argument shapes follow original callers. Units,
 * meanings and update cadence remain unresolved. Native words, internal
 * targets and all retail hashes are required before installation. */
extern int Actor23D8PlayerX __asm__("D_80070328");
extern int Actor23D8PlayerY __asm__("D_80070328 + 4");
extern unsigned char Actor23D8PlayerAngle __asm__("D_80070328 + 0xE");
extern int Actor23D8Mode __asm__("D_8006C54C");
extern char Actor23D8Identity[] __asm__("D_level_23_800963E4");
extern int Actor23D8Gate __asm__("D_8006C774");
extern int Actor23D8Words[] __asm__("VSync");
extern int Actor23D8Contact __asm__("D_8006C770");
int Actor23D8Helper35DDC() __asm__("func_80035DDC");
void func_level_23_80081FD8(Moby* argument) {
    register Moby* owner __asm__("$16") = argument;
    register int* state __asm__("$17");
    register int* fresh __asm__("$18");
    int value;
    MATCHING_KEEP(owner);
    state = owner->mobyTag;
    if (!*((unsigned char*)owner + 0x49))
        *((unsigned char*)owner + 0x49) = 1;
    if (owner->state != 2 && *(int*)((char*)owner + 0x18)) {
        fresh = owner->mobyTag;
        SpawnMoby(16, owner);
        fresh[5] = 300;
        fresh[4] = 200;
        value = *((unsigned char*)owner + 0x51);
        if (!value)
            value = func_800360F8(func_8004E880(owner->position.x - Actor23D8PlayerX,
                                                owner->position.y - Actor23D8PlayerY, 0),
                                  Actor23D8PlayerAngle, 32, 64);
        fresh[3] = value;
        *((unsigned char*)owner + 0x4A) = 255;
        owner->state = 2;
        func_80034F40(owner, 2);
    }
    switch (owner->state) {
        case 0:
            if (func_800359A4(state + 3, 4)) {
                state[3] = (rand() & 3) * 50 + 60;
                state[4] = func_8003636C(0, 2);
                owner->state = 1;
                func_80034F40(owner, 1);
            }
            if (Actor23D8Mode - 1 == (int)Actor23D8Identity && Actor23D8Gate) {
                register int index __asm__("$16") = 0;
                register int* words __asm__("$17") = Actor23D8Words;
                do {
                    int slot = rand() & 63;
                    index++;
                    words[slot] = 0;
                } while (index < 6);
            }
            break;
        case 1:
            if (state[4] == 0)
                *((unsigned char*)owner + 0x46) += 1;
            else if (state[4] == 1)
                *((unsigned char*)owner + 0x46) -= 1;
            {
                register int selector __asm__("$18") = 3;
                if (state[4] == selector) {
                    value = func_8004E880(state[0] - owner->position.x,
                                          state[1] - owner->position.y, 0);
                    func_8003585C(owner, value, 2, 12, 0, 0);
                    if (func_8004F334(&owner->position, (Vector3D*)state) < 512) {
                        state[3] = (rand() & 3) * 50 + 60;
                        owner->state = 0;
                        func_80034F40(owner, 0);
                    }
                } else if (func_8004F334(&owner->position, (Vector3D*)state) > state[5]) {
                    state[4] = selector;
                    state[3] = 5000;
                }
            }
            Actor23D8Helper35DDC(owner, 15, 0, 0, 0x414);
            if (func_800359A4(state + 3, 4)) {
                state[3] = (rand() & 3) * 50 + 60;
                owner->state = 0;
                func_80034F40(owner, 0);
            }
            break;
        case 2: {
            int* current = owner->mobyTag;
            func_80035030(owner, current + 5, current[3], current + 4, 8, 16, 512, 35);
        }
            if (Actor23D8Contact) {
                func_80055D24(owner, 4);
                func_800369B8(owner, 20);
                *((unsigned char*)owner + 0x49) = 0;
                func_80055B18(owner);
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0. AI generated; not human reviewed. */
/* Uninstalled candidate: helper contracts, exact native/locals/alias
 * checks and complete linked retail hashes remain mandatory. */
#define Level23_823A4Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level23_823A4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level23_823A4_func_80034F40() __asm__("func_80034F40");
int Level23_823A4SetMobyAnimation() __asm__("func_80034F80");
int Level23_823A4_func_80035030() __asm__("func_80035030");
int Level23_823A4TurnMobyTowardPlayer() __asm__("func_8003573C");
int Level23_823A4TurnMobyTowardHeading() __asm__("func_8003585C");
int Level23_823A4CountTimerDown() __asm__("func_800359A4");
int Level23_823A4_func_80035A80() __asm__("func_80035A80");
int Level23_823A4_func_80035DDC() __asm__("func_80035DDC");
int Level23_823A4_func_800360F8() __asm__("func_800360F8");
int Level23_823A4_func_800369B8() __asm__("func_800369B8");
int Level23_823A4_func_80036A68() __asm__("func_80036A68");
int Level23_823A4_func_8003BA00() __asm__("func_8003BA00");
int Level23_823A4PlanarHeadingLookup() __asm__("func_8004E880");
int Level23_823A4MeasureVectorLength() __asm__("func_8004EDE8");
int Level23_823A4ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Level23_823A4ShiftVectorRightTowardZero() __asm__("func_8004F110");
int Level23_823A4CopyVector() __asm__("func_8004F178");
int Level23_823A4AddVector() __asm__("func_8004F194");
int Level23_823A4SubtractVector() __asm__("func_8004F1C8");
int Level23_823A4AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Level23_823A4ApproximatePlanarDistance() __asm__("func_8004F334");
int Level23_823A4DeleteMoby() __asm__("func_80055B18");
int Level23_823A4RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level23_823A4_func_80055E84() __asm__("func_80055E84");
int Level23_823A4InterpolateMobyVertex() __asm__("func_80055F14");
extern int Level23_823A4_D_8006C550 __asm__("D_8006C550");
extern int Level23_823A4_D_8006C770 __asm__("D_8006C770");
extern int Level23_823A4_D_8006E020 __asm__("D_8006E020");
extern int Level23_823A4_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level23_823A4_D_8006E040 __asm__("D_8006E040");
extern int Level23_823A4_D_8006E344 __asm__("D_8006E344");
extern int Level23_823A4_D_80070328 __asm__("D_80070328");
extern int (*Level23_823A4_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level23_823A4_unk_ovlheader_80074414)() __asm__("unk_ovlheader_80074414");
void func_level_23_800823A4(void* ownerInput) {
    int selectedDecay;
    register int saved16 __asm__("$16");
    register int owner __asm__("$17");
    register int privateState __asm__("$18");
    register int saved19 __asm__("$19");
    register int saved20 __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int retainedS7 __asm__("$23");
    register int result2 __asm__("$2");
    register int temporary3 __asm__("$3");
    register int argument0 __asm__("$4");
    register int argument1 __asm__("$5");
    register int argument2 __asm__("$6");
    register int argument3 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C;
    } locals;

    int var_a1;

    int temp_v1_7;

    int temp_a1;

    int temp_a1_2;

    int temp_a1_3;

    int temp_a1_4;

    int temp_a1_5;

    int var_a0;

    int var_a0_3;

    int var_a1_4;

    int var_a1_5;

    int var_a2;

    int temp_a0;

    int temp_a0_3;

    int temp_a0_4;

    int temp_a0_5;

    int temp_a0_6;

    int temp_a0_7;

    int temp_v0;

    int temp_v0_2;

    int temp_v0_5;

    int temp_v0_9;

    int temp_v1;

    int temp_v1_2;

    int temp_v1_5;

    int var_v0_10;

    int var_v0_11;

    int var_v0_12;

    int var_v0_3;

    int var_v0_4;

    int var_v0_5;

    int var_v0_6;

    int var_v0_7;

    int var_v0_9;

    int temp_a0_2;

    int temp_a0_8;

    int temp_v1_12;

    int temp_v1_13;

    int temp_v1_3;

    int temp_v1_4;

    int var_v0_2;

    int temp_a2;

    int temp_v0_10;

    int temp_v0_11;

    int temp_v0_3;

    int temp_v0_4;

    int temp_v0_6;

    int temp_v0_7;

    int temp_v0_8;

    int temp_v1_10;

    int temp_v1_11;

    int temp_v1_14;

    int temp_v1_15;

    int temp_v1_6;

    int temp_v1_8;

    int temp_v1_9;

    /* Proposed full32 incoming S7 ownerInput. This same object is overwritten
     * by the original state2 return from55E84. The original state1 predicate
     * at80082B84 may read its entry bits before that local definition.
     * Empty metadata is only a proposal until exact lowering is certified. */

    owner = (int)ownerInput;
    Level23_823A4Keep(owner);
    __asm__ volatile("" : "=r"(retainedS7));
    privateState = Level23_823A4Field(owner, int*, 0);
    if (Level23_823A4Field(owner, unsigned char*, 0x49) != 0) {
        goto block_2;
    }
    Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
block_2:
    if ((unsigned int)(Level23_823A4Field(owner, unsigned char*, 0x48) - 5) < 3U) {
        goto block_17;
    }
    temporary3 = Level23_823A4Field(owner, int*, 0x18);
    Level23_823A4Keep(temporary3);
    if (temporary3 == 0)
        goto block_17;
    result2 = temporary3 & 0x10000;
    Level23_823A4Keep(result2);
    argument0 = owner;
    if (result2 == 0)
        goto block_6;
    argument1 = 1;
    goto block_7;
block_6:
    MATCHING_KEEP_VOLATILE_CLOBBER(result2, "$5");
    argument1 = 0;
block_7:
    argument2 = 0;
    argument3 = 0;
    Level23_823A4_func_80036A68(argument0, argument1, argument2, argument3);
    Level23_823A4Field(owner, unsigned char*, 0x4A) = 0xFF;
    Level23_823A4Field(owner, unsigned char*, 0x48) = 5U;
    Level23_823A4SetMobyAnimation(owner, 5);
    temp_v1_2 = Level23_823A4Field(privateState, int*, 0x24);
    if (temp_v1_2 < 0) {
        goto block_12;
    }
    result2 = (unsigned int)temp_v1_2 * 11u;
    temporary3 = Level23_823A4_D_8006C550;
    MATCHING_KEEP2(result2, temporary3);
    result2 = (unsigned int)result2 << 3;
    saved16 = temporary3 + result2;
    temp_a2 = Level23_823A4Field(saved16, int*, 0);
    if (Level23_823A4Field(saved16, short*, 0x36) != 0x13) {
        goto block_12;
    }
    temp_v1_3 = Level23_823A4Field(saved16, unsigned char*, 0x48);
    Level23_823A4Keep(temp_v1_3);
    if (temp_v1_3 & 0x80) {
        goto block_12;
    }
    temporary3 = temp_v1_3 & 255;
    Level23_823A4Keep(temporary3);
    if (temporary3 == 4) {
        goto block_12;
    }
    Level23_823A4Field(temp_a2, int*, 8) = -1;
    Level23_823A4_func_80034F40(saved16, 0, temp_a2);
    Level23_823A4Field(saved16, unsigned char*, 0x48) = 0U;
block_12:
    result2 = Level23_823A4Field(owner, int*, 0x18);
    temporary3 = 0x10000;
    result2 &= temporary3;
    Level23_823A4Keep(result2);
    /* GCC merges these observer arms only on the same source line. */
    // clang-format off
    if (result2) {        result2 = 180;        Level23_823A4Keep(result2);    } else {        result2 = 300;        Level23_823A4Keep(result2);    }
    // clang-format on
    Level23_823A4Field(privateState, int*, 0x20) = result2;
    Level23_823A4Field(privateState, int*, 0x1C) = 0x96;
    var_v0_2 = Level23_823A4Field(owner, unsigned char*, 0x51);
    if (var_v0_2 != 0) {
        goto block_16;
    }
    var_v0_2 = Level23_823A4_func_800360F8(
        Level23_823A4PlanarHeadingLookup(
            Level23_823A4Field(owner, int*, 0xC) -
                Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0),
            Level23_823A4Field(owner, int*, 0x10) -
                Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 4),
            0),
        Level23_823A4Field((int)&Level23_823A4_D_80070328, unsigned char*, 0xE), 0x20, 0x40);
block_16:
    Level23_823A4Field(privateState, int*, 0x18) = (int)var_v0_2;
    return;
block_17:
    temp_v1_4 = Level23_823A4Field(owner, unsigned char*, 0x48);
    if (temp_v1_4 >= 0x2BU) {
        goto block_228;
    }
    switch (temp_v1_4) {
        case 0:
            if (Level23_823A4_D_8006E344 == 1) {
                goto block_29;
            }
            if (Level23_823A4AbsoluteByteAngleDelta(
                    (int)(Level23_823A4_D_8006E040 << 0x10) >> 0x14,
                    Level23_823A4PlanarHeadingLookup(
                        Level23_823A4Field(owner, int*, 0xC) - Level23_823A4_D_8006E020,
                        Level23_823A4Field(owner, int*, 0x10) - Level23_823A4_D_8006E024, 0)) >=
                0x18) {
                goto block_29;
            }
            temp_a1 = (int)&Level23_823A4_D_80070328 + 8;
            result2 = Level23_823A4Field(owner, int*, 0x14);
            temporary3 = Level23_823A4Field(temp_a1, int*, 0);
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_3 = result2;
            if (var_v0_3 >= 0) {
                goto block_23;
            }
            var_v0_3 = -var_v0_3;
        block_23:
            if (var_v0_3 >= 0x800) {
                goto block_29;
            }
            temp_a0 = Level23_823A4Field(privateState, int*, 0x2C);
            if (temp_a0 == 0) {
                goto block_26;
            }
            var_v0_4 = Level23_823A4_unk_ovlheader_80074414(temp_a0, temp_a1 - 8);
            goto block_27;
        block_26:
            var_v0_4 = Level23_823A4ApproximatePlanarDistance(owner + 0xC, temp_a1 - 8) <
                       Level23_823A4Field(privateState, short*, 0xC);
        block_27:
            if (var_v0_4 == 0) {
                goto block_29;
            }
            Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 1U;
            Level23_823A4_func_80034F40(owner, 1);
        block_29:
            if (Level23_823A4_D_8006C770 == 0) {
                goto block_228;
            }
            temp_a0_2 = Level23_823A4Field(privateState, unsigned char*, 0x12);
            if (temp_a0_2 == 0) {
                goto block_228;
            }
            if (Level23_823A4_D_8006E344 == 1) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = temp_a0_2;
            Level23_823A4Field(privateState, unsigned char*, 0x12) = 0U;
            return;
        case 42:
            if (Level23_823A4CountTimerDown(privateState + 0x28, 2) == 0) {
                goto block_228;
            }
            if (Level23_823A4_D_8006E344 == 1) {
                goto block_228;
            }
            if (Level23_823A4AbsoluteByteAngleDelta(
                    (int)(Level23_823A4_D_8006E040 << 0x10) >> 0x14,
                    Level23_823A4PlanarHeadingLookup(
                        Level23_823A4Field(owner, int*, 0xC) - Level23_823A4_D_8006E020,
                        Level23_823A4Field(owner, int*, 0x10) - Level23_823A4_D_8006E024, 0)) >=
                0x18) {
                goto block_228;
            }
            temp_a1_2 = (int)&Level23_823A4_D_80070328 + 8;
            result2 = Level23_823A4Field(owner, int*, 0x14);
            temporary3 = Level23_823A4Field(temp_a1_2, int*, 0);
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_5 = result2;
            if (var_v0_5 >= 0) {
                goto block_38;
            }
            var_v0_5 = -var_v0_5;
        block_38:
            if (var_v0_5 >= 0x800) {
                goto block_228;
            }
            temp_a0_3 = Level23_823A4Field(privateState, int*, 0x2C);
            if (temp_a0_3 == 0) {
                goto block_41;
            }
            var_v0_6 = Level23_823A4_unk_ovlheader_80074414(temp_a0_3, temp_a1_2 - 8);
            goto block_42;
        block_41:
            var_v0_6 = Level23_823A4ApproximatePlanarDistance(owner + 0xC, temp_a1_2 - 8) <
                       Level23_823A4Field(privateState, short*, 0xC);
        block_42:
            if (var_v0_6 == 0) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
            Level23_823A4Field(privateState, signed char*, 0x13) = 0xF;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 2U;
            Level23_823A4_func_80034F40(owner, 2);
            Level23_823A4Field(
                Level23_823A4Field((Level23_823A4Field(privateState, int*, 0x24) * 0x58) +
                                       Level23_823A4_D_8006C550,
                                   int*, 0),
                short*, 0x28) = 0x3C;
            return;
        case 2:
            saved20 = 0;
            result2 = Level23_823A4_func_80055E84(owner);
            argument0 = (int)&locals.sp30;
            saved19 = owner + 12;
            argument1 = saved19;
            MATCHING_KEEP3_VOLATILE_CLOBBER(argument0, argument1, result2, "$23");
            retainedS7 = result2;
            Level23_823A4CopyVector(argument0, argument1);
            __asm__("" : "=r"(saved22) : "0"((int)&Level23_823A4_D_80070328));
            temp_v0 = Level23_823A4PlanarHeadingLookup(
                Level23_823A4Field(saved22, int*, 0) - Level23_823A4Field(owner, int*, 0xC),
                Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 4) -
                    Level23_823A4Field(owner, int*, 0x10),
                0);
            Level23_823A4TurnMobyTowardHeading(owner, temp_v0, 4, 2, 1, 0);
            if (Level23_823A4AbsoluteByteAngleDelta(
                    temp_v0, (int)Level23_823A4Field(owner, unsigned char*, 0x46)) >= 0x14) {
                goto block_46;
            }
            Level23_823A4_func_80035DDC(owner, 0x5F, 0, 0, 4);
        block_46:
            temp_a0_4 = Level23_823A4Field(privateState, int*, 0x2C);
            if (temp_a0_4 == 0) {
                goto block_49;
            }
            result2 = Level23_823A4_unk_ovlheader_80074414(temp_a0_4, saved22);
            argument0 = saved19;
            if (result2 != 0) {
                goto block_51;
            }
            Level23_823A4CopyVector(argument0, &locals.sp30);
            saved20 = 1;
            goto block_51;
        block_49:
            result2 = Level23_823A4ApproximatePlanarDistance(saved19, privateState);
            temporary3 = Level23_823A4Field(privateState, short*, 0x10);
            temporary3 = temporary3 < result2;
            Level23_823A4Keep(temporary3);
            if (!temporary3) {
                goto block_51;
            }
            saved20 = 1;
        block_51:
            argument0 = owner;
            if (saved20 != 0) {
                goto block_56;
            }
            saved16 = (int)&Level23_823A4_D_80070328 + 8;
            Level23_823A4Keep(saved16);
            result2 = Level23_823A4Field(owner, int*, 0x14);
            temporary3 = Level23_823A4Field(saved16, int*, 0);
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_7 = result2;
            if (var_v0_7 >= 0) {
                goto block_54;
            }
            var_v0_7 = -var_v0_7;
        block_54:
            if (var_v0_7 >= 0x801) {
                goto block_56;
            }
            temporary3 = Level23_823A4_D_8006E344;
            __asm__ volatile("" : "=r"(argument0) : "0"(argument0) : "$2", "memory");
            result2 = 1;
            if (temporary3 != result2) {
                goto block_57;
            }
        block_56:
            argument1 = 1;
            Level23_823A4Keep(argument1);
            result2 = 80;
            Level23_823A4Keep(result2);
            Level23_823A4Field(privateState, short*, 0x28) = result2;
            result2 = 2;
            Level23_823A4Keep(result2);
            Level23_823A4Field(argument0, unsigned char*, 0x49) = result2;
            __asm__("" : "=r"(argument1) : "0"(argument1), "r"(saved20) : "memory");
            result2 = 1;
            goto block_121;
        block_57:
            Level23_823A4Keep(saved20);
            Level23_823A4RefreshMobySpatialGridAndBasis(argument0, 5);
            Level23_823A4InterpolateMobyVertex(owner, 0, &locals.sp20);
            if (Level23_823A4CountTimerDown(privateState + 0x13, 1) == 0) {
                goto block_68;
            }
            if (Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x50) == 9) {
                goto block_69;
            }
            if (Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x50) == 4) {
                goto block_69;
            }
            saved19 = saved16 - 8;
            if ((unsigned int)(retainedS7 - 5) < 4U) {
                goto block_63;
            }
            result2 = retainedS7 < 0xD;
            Level23_823A4Keep(result2);
            if (result2) {
                goto block_70;
            }
            Level23_823A4Keep(saved16);
            saved19 = saved16 - 8;
            Level23_823A4Keep(saved19);
        block_63:
            if (Level23_823A4ApproximatePlanarDistance(saved19, &locals.sp20) >= 0x190) {
                goto block_68;
            }
            result2 = Level23_823A4Field(saved16, int*, 0);
            temporary3 = locals.sp28;
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_9 = result2;
            if (var_v0_9 >= 0) {
                goto block_66;
            }
            var_v0_9 = -var_v0_9;
        block_66:
            if (var_v0_9 >= 0x400) {
                goto block_68;
            }
            argument3 = 0x10000400;
            Level23_823A4Keep(argument3);
            saved16 += 0x214;
            argument0 = saved16;
            argument1 = saved19;
            MATCHING_KEEP2(argument0, argument1);
            result2 = Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x24);
            result2 |= 1;
            Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x24) = result2;
            MATCHING_KEEP_VOLATILE_CLOBBER(result2, "memory");
            result2 = Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x20C);
            temporary3 = Level23_823A4Field(owner, unsigned char*, 0x46);
            result2 |= argument3;
            Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x20C) = result2;
            Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x298) = temporary3;
            argument2 = owner + 12;
            Level23_823A4SubtractVector(argument0, argument1, argument2, argument3);
            Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x224) = 0;
            Level23_823A4ScaleVectorRatioQ15(saved16, Level23_823A4MeasureVectorLength(saved16, 0),
                                             0x4B);
            Level23_823A4Field(privateState, short*, 0x28) = 0x14;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x28U;
            return;
        block_68:
        block_69:
        block_70:
            if (Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x50) != 7) {
                goto block_228;
            }
            goto block_73;
        case 40:
            if (Level23_823A4CountTimerDown(privateState + 0x28, 2) == 0) {
                goto block_228;
            }
        block_73:
            Level23_823A4Field(owner, unsigned char*, 0x48) = 3U;
            Level23_823A4_func_80034F40(owner, 3);
            return;
        case 1:
            saved21 = 0x14;
            if (Level23_823A4Field(owner, unsigned char*, 0x49) != 2) {
                goto block_76;
            }
            Level23_823A4CopyVector(&locals.sp40, privateState);
            saved21 = 8;
            goto block_77;
        block_76:
            Level23_823A4CopyVector(&locals.sp40, (int)&Level23_823A4_D_80070328);
        block_77:
            temp_v0_2 = Level23_823A4PlanarHeadingLookup(
                locals.sp40 - Level23_823A4Field(owner, int*, 0xC),
                locals.sp44 - Level23_823A4Field(owner, int*, 0x10), 0);
            Level23_823A4TurnMobyTowardHeading(owner, temp_v0_2, 4, 1, 1, 0);
            argument0 = (int)&locals.sp50;
            MATCHING_KEEP_VOLATILE_CLOBBER(argument0, "$19");
            saved19 = owner + 12;
            argument1 = saved19;
            Level23_823A4CopyVector(argument0, argument1);
            if (Level23_823A4AbsoluteByteAngleDelta(
                    temp_v0_2, (int)Level23_823A4Field(owner, unsigned char*, 0x46)) >= saved21) {
                goto block_79;
            }
            Level23_823A4_func_80035DDC(owner, 0x55, 0, 0, 4);
        block_79:
            if (Level23_823A4Field(owner, unsigned char*, 0x49) != 1) {
                goto block_93;
            }
            argument0 = owner;
            if (retainedS7 == 0) {
                goto block_82;
            }
            argument1 = 2;
            result2 = 15;
            __asm__("" : "=r"(result2) : "0"(result2), "r"(retainedS7));
            Level23_823A4Field(privateState, signed char*, 0x13) = result2;
            __asm__("" : "=r"(argument1) : "0"(argument1), "r"(retainedS7));
            result2 = 2;
            goto block_121;
        block_82:
            Level23_823A4Keep(retainedS7);
            temp_a0_5 = Level23_823A4Field(privateState, int*, 0x2C);
            saved16 = 0;
            if (temp_a0_5 == 0) {
                goto block_85;
            }
            result2 =
                Level23_823A4_unk_ovlheader_80074414(temp_a0_5, (int)&Level23_823A4_D_80070328);
            argument0 = saved19;
            if (result2 != 0) {
                goto block_87;
            }
            Level23_823A4CopyVector(argument0, &locals.sp50);
            saved16 = 1;
            goto block_87;
        block_85:
            result2 = Level23_823A4ApproximatePlanarDistance(saved19, privateState);
            temporary3 = Level23_823A4Field(privateState, short*, 0x10);
            temporary3 = temporary3 < result2;
            Level23_823A4Keep(temporary3);
            if (!temporary3) {
                goto block_87;
            }
            saved16 = 1;
        block_87:
            argument0 = (int)&locals.sp40;
            if (saved16 != 0) {
                goto block_91;
            }
            result2 = Level23_823A4Field(owner, int*, 0x14);
            temporary3 = Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 8);
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_10 = result2;
            if (var_v0_10 >= 0) {
                goto block_90;
            }
            var_v0_10 = -var_v0_10;
        block_90:
            if (var_v0_10 < 0x801) {
                goto block_92;
            }
        block_91:
            Level23_823A4Field(privateState, short*, 0x28) = 0x50;
            Level23_823A4Field(owner, unsigned char*, 0x49) = 2U;
            Level23_823A4CopyVector(argument0, privateState);
            return;
        block_92:
            Level23_823A4CopyVector(argument0, ((int)&Level23_823A4_D_80070328 + 8) - 8);
            return;
        block_93:
            if (Level23_823A4Field(privateState, short*, 0x28) != 0) {
                goto block_99;
            }
            temp_a0_6 = Level23_823A4Field(privateState, int*, 0x2C);
            if (temp_a0_6 == 0) {
                goto block_97;
            }
            if (Level23_823A4_unk_ovlheader_80074414(temp_a0_6, (int)&Level23_823A4_D_80070328) ==
                0) {
                goto block_100;
            }
            Level23_823A4Field(privateState, signed char*, 0x13) = 0xF;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 2U;
            Level23_823A4_func_80034F40(owner, 2);
            MATCHING_KEEP_VOLATILE_CLOBBER(owner, "memory");
            var_a0 = owner + 12;
            goto block_101;
        block_97:
            if (Level23_823A4ApproximatePlanarDistance(saved19, (int)&Level23_823A4_D_80070328) >=
                Level23_823A4Field(privateState, short*, 0xE)) {
                goto block_100;
            }
            argument0 = owner;
            argument1 = 2;
            Level23_823A4Field(privateState, signed char*, 0x13) = 0xF;
            result2 = 2;
            goto block_121;
        block_99:
            Level23_823A4CountTimerDown(privateState + 0x28, 2);
        block_100:
            var_a0 = owner + 0xC;
        block_101:
            if (Level23_823A4ApproximatePlanarDistance(var_a0, &locals.sp40) >= 0x400) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x20U;
            return;
        case 32:
            if (Level23_823A4TurnMobyTowardPlayer(owner, 8, 4, 1) == 0) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0U;
            Level23_823A4_func_80034F40(owner, 0);
            return;
        case 3:
            if (Level23_823A4_D_8006C770 == 0) {
                goto block_228;
            }
            argument0 = owner;
            argument1 = 1;
            Level23_823A4Keep(argument1);
            result2 = 80;
            Level23_823A4Keep(result2);
            Level23_823A4Field(privateState, short*, 0x28) = result2;
            result2 = 2;
            Level23_823A4Keep(result2);
            Level23_823A4Field(argument0, unsigned char*, 0x49) = result2;
            result2 = 1;
            goto block_121;
        case 4:
            if (Level23_823A4Field(owner, unsigned char*, 0x49) != 3) {
                goto block_111;
            }
            Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
            temp_v0_3 = Level23_823A4Field(privateState, int*, 0x14);
            temp_v1_5 = Level23_823A4Field(temp_v0_3, short*, 2) * 0x10;
            Level23_823A4Field(owner, int*, 0xC) = (int)Level23_823A4Field(
                temp_v1_5 + Level23_823A4Field(temp_v0_3, int*, 0xC), int*, 0);
            Level23_823A4Field(owner, int*, 0x10) = (int)Level23_823A4Field(
                (temp_v1_5 +
                 Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), int*, 0xC)),
                int*, 4);
            temporary3 = Level23_823A4Field(privateState, int*, 0x14);
            __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$4", "memory");
            argument0 = (int)&locals.sp60;
            MATCHING_KEEP2(argument0, temporary3);
            result2 = Level23_823A4Field(temporary3, int*, 12);
            temporary3 = Level23_823A4Field(temporary3, short*, 2);
            argument2 = result2;
            result2 = (unsigned int)temporary3 << 4;
            Level23_823A4Keep(result2);
            argument1 = argument2 + result2;
            if (temporary3 != 0)
                goto block_110;
            argument2 += 16;
        block_110:
            Level23_823A4SubtractVector(argument0, argument1, argument2);
            Level23_823A4Field(owner, unsigned char*, 0x46) =
                Level23_823A4PlanarHeadingLookup(locals.sp60, locals.sp64, 0);
        block_111:
            result2 = Level23_823A4_D_8006C770;
            MATCHING_KEEP_VOLATILE_CLOBBER(result2, "$4");
            argument0 = owner;
            if (result2 == 0) {
                goto block_228;
            }
            temp_v1_8 = Level23_823A4Field(privateState, int*, 0x14);
            Level23_823A4Field(temp_v1_8, unsigned short*, 0xA) =
                (unsigned short)-(int)Level23_823A4Field(temp_v1_8, unsigned short*, 0xA);
            temporary3 = Level23_823A4Field(privateState, int*, 0x14);
            result2 = Level23_823A4Field(temporary3, short*, 2);
            __asm__ volatile("" : "=r"(privateState) : "0"(privateState) : "$5", "memory");
            argument1 = 1;
            result2 = (result2 == 0);
            Level23_823A4Field(temporary3, short*, 2) = result2;
            temporary3 = Level23_823A4Field(privateState, unsigned char*, 0x12);
            Level23_823A4Field(privateState, short*, 0x2A) = 0;
            Level23_823A4Field(privateState, short*, 0x28) = 0xC8;
            goto block_131;
        case 5:
            if (Level23_823A4_func_80035030(owner, privateState + 0x20,
                                            Level23_823A4Field(privateState, int*, 0x18),
                                            privateState + 0x1C, 8, 0x10, 0x200, 0x23) == 3) {
                goto block_117;
            }
            if (Level23_823A4_D_8006C770 == 0) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = 6U;
            Level23_823A4_func_80034F40(owner, 6);
            return;
        case 6:
            if (Level23_823A4_func_80035030(owner, privateState + 0x20,
                                            Level23_823A4Field(privateState, int*, 0x18),
                                            privateState + 0x1C, 8, 0x16, 0x200, 0x23) != 3) {
                goto block_228;
            }
        block_117:
            Level23_823A4Field(owner, unsigned char*, 0x48) = 7U;
            Level23_823A4_func_80034F40(owner, 7);
            return;
        case 7:
            if (Level23_823A4_D_8006C770 == 0) {
                goto block_228;
            }
            Level23_823A4RefreshMobySpatialGridAndBasis(owner, 4);
            Level23_823A4_func_8003BA00(owner);
            Level23_823A4_func_800369B8(owner, 0x28);
            Level23_823A4DeleteMoby(owner);
            return;
        case 20:
            argument0 = owner;
            result2 = Level23_823A4Field(privateState, int*, 0x14);
            __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$3", "memory");
            temporary3 = 1;
            MATCHING_KEEP3(result2, temporary3, argument0);
            Level23_823A4Field(result2, unsigned short*, 0xA) = temporary3;
            result2 = Level23_823A4Field(privateState, int*, 0x14);
            argument1 = 1;
            Level23_823A4Field(result2, short*, 2) = temporary3;
            result2 = 21;
        block_121:
            MATCHING_KEEP3(argument0, argument1, result2);
            Level23_823A4Field(argument0, unsigned char*, 0x48) = result2;
            Level23_823A4_func_80034F40(argument0, argument1);
            return;
        case 21:
            Level23_823A4_func_80034F40(owner, 1);
            if (!(Level23_823A4_func_80035A80(owner, Level23_823A4Field(privateState, int*, 0x14),
                                              0x78, 0x32, 0, 6, 2, 4) &
                  2)) {
                goto block_124;
            }
            temp_v0_4 = Level23_823A4Field(privateState, int*, 0x14);
            Level23_823A4Field(temp_v0_4, unsigned short*, 0xA) =
                (unsigned short)-(int)Level23_823A4Field(temp_v0_4, unsigned short*, 0xA);
            Level23_823A4Field(privateState, unsigned char*, 0x12) = 0x15U;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0U;
            Level23_823A4_func_80034F40(owner, 0);
        block_124:
            if (Level23_823A4_D_8006E344 == 1) {
                goto block_228;
            }
            if (Level23_823A4AbsoluteByteAngleDelta(
                    (int)(Level23_823A4_D_8006E040 << 0x10) >> 0x14,
                    Level23_823A4PlanarHeadingLookup(
                        Level23_823A4Field(owner, int*, 0xC) - Level23_823A4_D_8006E020,
                        Level23_823A4Field(owner, int*, 0x10) - Level23_823A4_D_8006E024, 0)) >=
                0x18) {
                goto block_228;
            }
            if (Level23_823A4ApproximatePlanarDistance(owner + 0xC,
                                                       (int)&Level23_823A4_D_80070328) >=
                Level23_823A4Field(privateState, short*, 0xC)) {
                goto block_228;
            }
            result2 = Level23_823A4Field(owner, int*, 0x14);
            temporary3 = Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 8);
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_11 = result2;
            if (var_v0_11 >= 0) {
                goto block_129;
            }
            var_v0_11 = -var_v0_11;
        block_129:
            if (var_v0_11 >= 0x400) {
                goto block_228;
            }
            argument0 = owner;
            argument1 = 1;
            temporary3 = 1;
            result2 = 21;
            __asm__(""
                    : "=r"(temporary3), "=r"(result2)
                    : "0"(temporary3), "1"(result2), "r"(argument0), "r"(argument1));
            Level23_823A4Field(argument0, unsigned char*, 0x49) = temporary3;
            Level23_823A4Field(privateState, unsigned char*, 0x12) = result2;
        block_131:
            MATCHING_KEEP3(argument0, argument1, temporary3);
            Level23_823A4Field(argument0, unsigned char*, 0x48) = temporary3;
            Level23_823A4_func_80034F40(argument0, argument1);
            return;
        case 22:
            Level23_823A4_func_80034F40(owner, 2);
            temporary3 = Level23_823A4Field(privateState, int*, 0x14);
            __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$2", "memory");
            result2 = 1;
            MATCHING_KEEP2(temporary3, result2);
            Level23_823A4Field(temporary3, unsigned short*, 0xA) = result2;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), short*, 2) = 0;
            goto block_160;
        case 23:
            result2 = Level23_823A4_func_80055E84(owner);
            argument0 = Level23_823A4Field(privateState, int*, 0x24);
            __asm__ volatile("" : "=r"(result2) : "0"(result2) : "$16", "memory");
            saved16 = 90;
            MATCHING_KEEP2(argument0, saved16);
            temporary3 = (unsigned int)argument0 * 11u;
            argument0 = Level23_823A4_D_8006C550;
            MATCHING_KEEP3(temporary3, argument0, result2);
            temporary3 = (unsigned int)temporary3 << 3;
            saved19 = argument0 + temporary3;
            saved21 = result2;
            if (!(Level23_823A4Field(saved19, unsigned char*, 0x48) & 0x80)) {
                goto block_135;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = 1U;
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
            return;
        block_135:
            temp_a0_7 = Level23_823A4ApproximatePlanarDistance(owner + 0xC, saved19 + 0xC);
            if (Level23_823A4Field(saved19, short*, 0x36) != 0x14) {
                goto block_140;
            }
            if (temp_a0_7 >= 0x4B0) {
                goto block_138;
            }
            saved16 = 0x46;
            goto block_144;
        block_138:
            if (temp_a0_7 < 0x709) {
                goto block_145;
            }
            saved16 = 0x6E;
            goto block_145;
        block_140:
            saved16 = 0x46;
            if (temp_a0_7 >= 0x6A4) {
                goto block_142;
            }
            saved16 = 0x5A;
            goto block_144;
        block_142:
            if (temp_a0_7 < 0xC01) {
                goto block_145;
            }
            saved16 = 0x32;
        block_144:
        block_145:
            Level23_823A4_func_80035A80(owner, Level23_823A4Field(privateState, int*, 0x14), 0x78,
                                        saved16, 0, 5, 0x80, 4);
            Level23_823A4RefreshMobySpatialGridAndBasis(owner, 5);
            Level23_823A4InterpolateMobyVertex(owner, 0, &locals.sp70);
            if (Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x50) == 9) {
                goto block_155;
            }
            if (Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x50) == 4) {
                goto block_155;
            }
            if (Level23_823A4Field(owner, unsigned char*, 0x3C) != 2) {
                goto block_155;
            }
            if ((unsigned int)(saved21 - 5) < 4U) {
                goto block_150;
            }
            result2 = saved21 < 0xD;
            Level23_823A4Keep(result2);
            if (result2) {
                goto block_155;
            }
        block_150:
            if (Level23_823A4ApproximatePlanarDistance(
                    ((int)&Level23_823A4_D_80070328 + 0x50) - 0x50, &locals.sp70) >= 0x190) {
                goto block_155;
            }
            result2 = Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 8);
            temporary3 = locals.sp78;
            MATCHING_KEEP2(result2, temporary3);
            result2 -= temporary3;
            var_v0_12 = result2;
            if (var_v0_12 >= 0) {
                goto block_153;
            }
            var_v0_12 = -var_v0_12;
        block_153:
            if (var_v0_12 >= 0x400) {
                goto block_155;
            }
            Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x24) =
                (int)(Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x24) | 1);
            Level23_823A4Field((int)&Level23_823A4_D_80070328, int*, 0x298) =
                (int)Level23_823A4Field(owner, unsigned char*, 0x46);
        block_155:
            if (Level23_823A4ApproximatePlanarDistance(owner + 0xC,
                                                       (int)&Level23_823A4_D_80070328) >=
                Level23_823A4Field(privateState, short*, 0xC)) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = 1U;
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
            if (Level23_823A4Field(saved19, short*, 0x36) != 0x14) {
                goto block_228;
            }
            Level23_823A4Field(saved19, unsigned char*, 0x48) = 0x16U;
            return;
        case 26:
            Level23_823A4_func_80035A80(owner, Level23_823A4Field(privateState, int*, 0x14), 0x78,
                                        0x32, 0, 4, 0x80, 4);
            if (Level23_823A4_D_8006C770 == 0) {
                goto block_228;
            }
            Level23_823A4_func_80034F40(owner, 1);
        block_160:
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x17U;
            return;
        case 24:
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(owner, int*, 0xC) = (int)Level23_823A4Field(
                Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), int*, 0xC), int*,
                0);
            Level23_823A4Field(owner, int*, 0x10) = (int)Level23_823A4Field(
                Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), int*, 0xC), int*,
                4);
            temp_a1_4 = Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), int*, 0xC);
            Level23_823A4SubtractVector(&locals.sp80, temp_a1_4, temp_a1_4 + 0x10);
            Level23_823A4Field(owner, unsigned char*, 0x46) =
                Level23_823A4PlanarHeadingLookup(locals.sp80, locals.sp84, 0);
            Level23_823A4Field(privateState, short*, 0x28) = 0xC8;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), unsigned short*, 0xA) =
                1U;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), short*, 2) = 1;
            Level23_823A4Field(privateState, unsigned char*, 0x12) = 0x19U;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x19U;
            return;
        case 25:
            temporary3 = Level23_823A4Field(privateState, int*, 0x24);
            Level23_823A4Keep(temporary3);
            result2 = (unsigned int)temporary3 * 11u;
            temporary3 = Level23_823A4_D_8006C550;
            MATCHING_KEEP2(result2, temporary3);
            result2 = (unsigned int)result2 << 3;
            saved16 = temporary3 + result2;
            argument0 = Level23_823A4Field(saved16, unsigned char*, 0x48);
            __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$2", "memory");
            result2 = 4;
            MATCHING_KEEP2(argument0, result2);
            temp_a0_8 = argument0;
            temporary3 = argument0 & 255;
            saved19 = 0;
            if (temporary3 == result2) {
                goto block_164;
            }
            if (!(temp_a0_8 & 0x80)) {
                goto block_165;
            }
        block_164:
            saved19 = 1;
        block_165:
            if (Level23_823A4Field(privateState, short*, 0x2A) == 0) {
                goto block_168;
            }
            if (Level23_823A4CountTimerDown(privateState + 0x28, 2) == 0) {
                goto block_228;
            }
            Level23_823A4Field(privateState, short*, 0x2A) = 0;
            Level23_823A4Field(privateState, short*, 0x28) = 0xC8;
            return;
        block_168:
            if (Level23_823A4ApproximatePlanarDistance(owner + 0xC,
                                                       (int)&Level23_823A4_D_80070328) >=
                Level23_823A4Field(privateState, short*, 0xC)) {
                goto block_171;
            }
            saved19 = 1;
            if (Level23_823A4Field(saved16, unsigned char*, 0x48) & 0x80) {
                goto block_171;
            }
            Level23_823A4Field(Level23_823A4Field(saved16, int*, 0), int*, 8) = -1;
            Level23_823A4_func_80034F40(saved16, 0);
            Level23_823A4Field(saved16, unsigned char*, 0x48) = 0U;
            Level23_823A4Field(saved16, signed char*, 0x49) = 1;
        block_171:
            if (saved19 == 0) {
                goto block_173;
            }
            temp_a1_5 = Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), int*, 0xC);
            Level23_823A4AddVector(&locals.sp90, temp_a1_5, temp_a1_5 + 0x10);
            Level23_823A4ShiftVectorRightTowardZero(&locals.sp90, 1);
            Level23_823A4CopyVector(privateState, &locals.sp90);
            Level23_823A4Field(owner, unsigned char*, 0x48) = 1U;
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(privateState, short*, 0x28) = 0x3C;
            Level23_823A4Field(owner, unsigned char*, 0x49) = 2U;
            Level23_823A4Field(privateState, unsigned char*, 0x12) = 0U;
            return;
        block_173:
            Level23_823A4Keep(saved19);
            result2 = Level23_823A4_func_80035A80(
                owner, Level23_823A4Field(privateState, int*, 0x14), 0x78, 0x32, 0, 6, 2, 4);
            result2 &= 3;
            argument0 = owner;
            if (!result2) {
                goto block_175;
            }
            temp_v1_10 = Level23_823A4Field(privateState, int*, 0x14);
            Level23_823A4Field(temp_v1_10, short*, 2) =
                (short)(Level23_823A4Field(temp_v1_10, short*, 2) == 0);
            temporary3 = Level23_823A4Field(privateState, int*, 0x14);
            result2 = Level23_823A4Field(temporary3, unsigned short*, 0xA);
            __asm__ volatile("" : "=r"(argument0) : "0"(argument0) : "$5", "memory");
            argument1 = 0;
            result2 = -result2;
            Level23_823A4Field(temporary3, unsigned short*, 0xA) = result2;
            Level23_823A4Field(privateState, short*, 0x2A) = 1;
            Level23_823A4Field(privateState, short*, 0x28) = 0x78;
            goto block_176;
        block_175:
            argument1 = 1;
        block_176:
            Level23_823A4_func_80034F40(argument0, argument1);
            temporary3 = Level23_823A4Field(owner, unsigned char*, 0x49);
            result2 = 1;
            MATCHING_KEEP2_VOLATILE_CLOBBER(temporary3, result2, "$4");
            argument0 = privateState + 0x28;
            if (temporary3 != result2) {
                goto block_180;
            }
            if (Level23_823A4Field(privateState, short*, 0x28) >= 0x41) {
                goto block_179;
            }
            Level23_823A4Field(saved16, unsigned char*, 0x48) = 0x18U;
            Level23_823A4_func_80034F40(saved16, 5);
            Level23_823A4Field(owner, unsigned char*, 0x49) = 3U;
        block_179:
            Level23_823A4Keep(privateState);
            argument0 = privateState + 0x28;
            Level23_823A4Keep(argument0);
        block_180:
            if (Level23_823A4CountTimerDown(argument0, 2) == 0) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x49) = 1U;
            Level23_823A4Field(privateState, short*, 0x28) = 0xC8;
            return;
        case 27:
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(privateState, short*, 0x28) = 0;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), unsigned short*, 0xA) =
                1U;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), short*, 2) = 0;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x1CU;
            return;
        case 30:
            Level23_823A4_func_80034F40(owner, 2);
            Level23_823A4Field(privateState, short*, 0x28) = 0;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), unsigned short*, 0xA) =
                1U;
            Level23_823A4Field(Level23_823A4Field(privateState, int*, 0x14), short*, 2) = 0;
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x1FU;
            return;
        case 28:
            argument2 = 255;
            Level23_823A4Keep(argument2);
            temporary3 = Level23_823A4Field(privateState, int*, 0x24);
            argument0 = Level23_823A4_D_8006C550;
            __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$5", "memory");
            argument1 = 32;
            MATCHING_KEEP3(temporary3, argument0, argument1);
            Level23_823A4Field(owner, unsigned char*, 0x4A) = argument2;
            Level23_823A4Field(owner, unsigned char*, 0x4C) = argument1;
            MATCHING_KEEP4_VOLATILE_CLOBBER(temporary3, argument0, argument1, argument2, "memory");
            result2 = (unsigned int)temporary3 * 88u;
            Level23_823A4Keep(result2);
            saved19 = argument0 + result2;
            argument0 = owner + 12;
            if (Level23_823A4Field(saved19, unsigned char*, 0x48) & 128)
                goto block_186;
            Level23_823A4Field(saved19, unsigned char*, 0x4A) = argument2;
            Level23_823A4Field(saved19, unsigned char*, 0x4C) = argument1;
        block_186:
            temp_v0_5 = Level23_823A4ApproximatePlanarDistance(
                argument0, (int)&Level23_823A4_D_80070328, argument2);
            if (temp_v0_5 < 0x6979) {
                goto block_188;
            }
            if (Level23_823A4ApproximatePlanarDistance(saved19 + 0xC,
                                                       (int)&Level23_823A4_D_80070328) >= 0x6979) {
                goto block_201;
            }
        block_188:
            saved16 = 0x4B;
            if (Level23_823A4Field(privateState, short*, 0x28) == 0) {
                goto block_190;
            }
            Level23_823A4CountTimerDown(privateState + 0x28, 2);
            goto block_191;
        block_190:
            saved16 = 0x32;
        block_191:
            Level23_823A4_func_80035A80(owner, Level23_823A4Field(privateState, int*, 0x14), 0x78,
                                        saved16, 0, 6, 2, 4);
            temp_v1_12 = Level23_823A4Field(saved19, unsigned char*, 0x48);
            if (temp_v1_12 & 0x80) {
                goto block_196;
            }
            if (temp_v0_5 >= Level23_823A4Field(privateState, short*, 0xC)) {
                goto block_195;
            }
            temp_v0_6 = Level23_823A4Field(privateState, int*, 0x14);
            saved16 = Level23_823A4Field(saved19, int*, 0);
            Level23_823A4CopyVector(privateState,
                                    Level23_823A4Field(temp_v0_6, int*, 0xC) +
                                        (Level23_823A4Field(temp_v0_6, short*, 2) * 0x10));
            temp_v0_7 = Level23_823A4Field(privateState, int*, 0x14);
            var_a1_4 = Level23_823A4Field(temp_v0_7, int*, 0xC);
            var_a0_3 = saved16;
            if (Level23_823A4Field(temp_v0_7, short*, 2) != 0) {
                goto block_208;
            }
            var_a1_4 += 0x10;
            goto block_208;
        block_195:
            if ((unsigned int)(temp_v1_12 - 5) >= 3U) {
                goto block_228;
            }
        block_196:
            temp_v0_8 = Level23_823A4Field(privateState, int*, 0x14);
            Level23_823A4CopyVector(privateState,
                                    Level23_823A4Field(temp_v0_8, int*, 0xC) +
                                        (Level23_823A4Field(temp_v0_8, short*, 2) * 0x10));
            goto block_227;
        case 31:
            argument2 = 255;
            Level23_823A4Keep(argument2);
            temporary3 = Level23_823A4Field(privateState, int*, 0x24);
            argument0 = Level23_823A4_D_8006C550;
            __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$5", "memory");
            argument1 = 32;
            MATCHING_KEEP3(temporary3, argument0, argument1);
            Level23_823A4Field(owner, unsigned char*, 0x4A) = argument2;
            Level23_823A4Field(owner, unsigned char*, 0x4C) = argument1;
            MATCHING_KEEP4_VOLATILE_CLOBBER(temporary3, argument0, argument1, argument2, "memory");
            result2 = (unsigned int)temporary3 * 88u;
            Level23_823A4Keep(result2);
            saved19 = argument0 + result2;
            argument0 = owner + 12;
            if (Level23_823A4Field(saved19, unsigned char*, 0x48) & 128)
                goto block_199;
            Level23_823A4Field(saved19, unsigned char*, 0x4A) = argument2;
            Level23_823A4Field(saved19, unsigned char*, 0x4C) = argument1;
        block_199:
            temp_v0_9 = Level23_823A4ApproximatePlanarDistance(
                argument0, (int)&Level23_823A4_D_80070328, argument2);
            if (temp_v0_9 < 0x6979) {
                goto block_203;
            }
            if (Level23_823A4ApproximatePlanarDistance(saved19 + 0xC,
                                                       (int)&Level23_823A4_D_80070328) < 0x6979) {
                goto block_203;
            }
        block_201:
            Level23_823A4Field(owner, signed char*, 0x4A) = 0x18;
            Level23_823A4Field(owner, signed char*, 0x4C) = 0x18;
            if (Level23_823A4Field(saved19, unsigned char*, 0x48) & 0x80) {
                goto block_228;
            }
            Level23_823A4Field(saved19, signed char*, 0x4A) = 0x18;
            Level23_823A4Field(saved19, signed char*, 0x4C) = 0x18;
            return;
        block_203:
            temp_v1_13 = Level23_823A4Field(saved19, unsigned char*, 0x48);
            if (temp_v1_13 & 0x80) {
                goto block_196;
            }
            if (temp_v0_9 >= Level23_823A4Field(privateState, short*, 0xC)) {
                goto block_211;
            }
            result2 = Level23_823A4Field(privateState, int*, 0x14);
            argument1 = Level23_823A4Field(result2, int*, 12);
            result2 = Level23_823A4Field(result2, short*, 2);
            MATCHING_KEEP_VOLATILE_CLOBBER(argument1, "memory");
            saved16 = Level23_823A4Field(saved19, int*, 0);
            Level23_823A4Keep(result2);
            if (result2 != 0)
                goto block_207;
            argument1 += 16;
        block_207:
            Level23_823A4CopyVector(privateState, argument1);
            result2 = Level23_823A4Field(privateState, int*, 0x14);
            argument0 = saved16;
            argument1 = Level23_823A4Field(result2, short*, 2);
            Level23_823A4Keep(argument1);
            result2 = Level23_823A4Field(result2, int*, 12);
            argument1 = (unsigned int)argument1 << 4;
            argument1 = (unsigned int)result2 + (unsigned int)argument1;
            var_a0_3 = argument0;
            var_a1_4 = argument1;
        block_208:
            Level23_823A4CopyVector(var_a0_3, var_a1_4);
            Level23_823A4Field(owner, unsigned char*, 0x48) = 1U;
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(privateState, short*, 0x28) = 0x3C;
            Level23_823A4Field(owner, unsigned char*, 0x49) = 2U;
            Level23_823A4Field(saved19, signed char*, 0x48) = 1;
            Level23_823A4_func_80034F40(saved19, 1);
            if (Level23_823A4Field(saved19, short*, 0x36) != 0x1A) {
                goto block_210;
            }
            Level23_823A4Field(privateState, short*, 0x28) = 0x3C;
        block_210:
            Level23_823A4Field(saved19, signed char*, 0x49) = 2;
            return;
        block_211:
            if ((unsigned int)(temp_v1_13 - 5) < 3U) {
                goto block_196;
            }
            saved16 = 0x32;
            if (Level23_823A4Field(privateState, short*, 0x28) == 0) {
                goto block_214;
            }
            Level23_823A4CountTimerDown(privateState + 0x28, 2);
            goto block_215;
        block_214:
            saved16 = 0x4B;
        block_215:
            Level23_823A4_func_80035A80(owner, Level23_823A4Field(privateState, int*, 0x14), 0x78,
                                        saved16, 0, 6, 2, 4);
            if (Level23_823A4Field(privateState, short*, 0x28) != 0) {
                goto block_228;
            }
            if (Level23_823A4ApproximatePlanarDistance(owner + 0xC, saved19 + 0xC) >= 0x564) {
                goto block_228;
            }
            Level23_823A4Field(saved19, unsigned char*, 0x48) = 0x1DU;
            Level23_823A4_func_80034F40(saved19, 4);
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x1CU;
            Level23_823A4_func_80034F40(owner, 1);
            temp_v1_14 = Level23_823A4Field(privateState, int*, 0x14);
            Level23_823A4Field(privateState, short*, 0x28) = 0x50;
            Level23_823A4Field(temp_v1_14, short*, 2) =
                (short)(Level23_823A4Field(temp_v1_14, short*, 2) == 0);
            return;
        case 29:
            if (Level23_823A4_D_8006C770 == 0) {
                goto block_228;
            }
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x1FU;
            Level23_823A4_func_80034F40(owner, 2);
            temp_v1_15 = Level23_823A4Field(privateState, int*, 0x14);
            Level23_823A4Field(temp_v1_15, short*, 2) =
                (short)(Level23_823A4Field(temp_v1_15, short*, 2) == 0);
            Level23_823A4Field(privateState, short*, 0x28) = 0x50;
            return;
        case 33:
            Level23_823A4_func_80034F40(owner, 0);
            if (Level23_823A4ApproximatePlanarDistance(owner + 0xC,
                                                       (int)&Level23_823A4_D_80070328) >= 0x2800) {
                goto block_228;
            }
            Level23_823A4_func_80034F40(owner, 2);
            Level23_823A4Field(owner, unsigned char*, 0x48) = 0x22U;
            return;
        case 34:
            argument2 = 0;
            temporary3 = Level23_823A4Field(privateState, int*, 0x24);
            argument0 = Level23_823A4Field(owner, int*, 12);
            argument1 = Level23_823A4Field(owner, int*, 16);
            MATCHING_KEEP4_VOLATILE(argument2, temporary3, argument0, argument1);
            result2 = (unsigned int)temporary3 * 11u;
            temporary3 = Level23_823A4_D_8006C550;
            MATCHING_KEEP2(result2, temporary3);
            result2 = (unsigned int)result2 << 3;
            saved16 = temporary3 + result2;
            temporary3 = Level23_823A4Field(saved16, int*, 12);
            result2 = Level23_823A4Field(saved16, int*, 16);
            argument0 = temporary3 - argument0;
            argument1 = result2 - argument1;
            result2 = Level23_823A4PlanarHeadingLookup(argument0, argument1, argument2);
            Level23_823A4TurnMobyTowardHeading(owner, result2, 8, 0, 0, 0);
            Level23_823A4_func_80035DDC(owner, 0x32, 0, 0, 0x604);
            if (Level23_823A4ApproximatePlanarDistance(owner + 0xC, saved16 + 0xC) < 0x400) {
                goto block_224;
            }
            if (Level23_823A4Field(saved16, int*, 0x18) == 0) {
                goto block_228;
            }
        block_224:
            if (Level23_823A4Field(saved16, int*, 0x18) != 0) {
                goto block_226;
            }
            Level23_823A4_SpawnMoby(0x10, saved16);
            Level23_823A4_func_800369B8(saved16, 0x18);
            Level23_823A4DeleteMoby(saved16);
        block_226:
        block_227:
            Level23_823A4Field(owner, unsigned char*, 0x48) = 1U;
            Level23_823A4_func_80034F40(owner, 1);
            Level23_823A4Field(privateState, short*, 0x28) = 0x3C;
            Level23_823A4Field(owner, unsigned char*, 0x49) = 2U;
        block_228:
            return;
        default:
            goto block_228;
    }
}

#undef Level23_823A4Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80083BFC.
 * AI generated; not human reviewed. Acceptance requires1295 native
 * instructions,all32 selectors,every actual target and full retail hashes.
 * Original frameC0 (192 bytes),saves S0..S6/RA at SPA0..BC;
 * home/outgoing SP00..1B;explicit vector homes SP20..8B. Remaining
 * local reserve bytes are never read. All vector reads have original
 * copy,subtract,explicit component or55F14 output producers.
 * Owner S2/private S5 start from the parameter/owner0 producers.
 * Saved roles change only after their previous values die. The original
 * angular return in S1 lives only on its own branch;the other branch
 * uses S1 as SP60. S0's player base survives both original byte/word
 * consumers and the distance helper before its next address producer.
 * No fixed FP/SP,undefined incoming saved role,overlapping live fixed
 * alias,manual outgoing stack write or reserve-content read is used.
 * All10 native MULT sites use DISTINCT fully initialized signed64
 * product unions with compiler-correct local MIPSEB/MIPSEL word order.
 * No union address escapes. Six vector products and the later scalar
 * product narrow complete low words;three ordinary C high projections
 * retain two /58 corrections and one /6 correction. There is no partial
 * HI/LO input. The C90E strength chain explicitly wraps each original
 * 32-bit shift/add/subtract before the original signed shift13.
 * The signed dynamic divisions retain original zero/overflow traps.
 * Complete initialized value/address identities preserve original
 * scalar captures,argument edges,byte reloads,redundant literals and
 * distinct store paths. Metadata observes only initialized whole values
 * or original written fields;dead GP clobbers precede fresh producers.
 * Metadata emits zero CPU instructions. There is no opcode asm.
 * Known helper views retain the original physical caller words.
 * 4F110 has two formal arguments;its original A2/A3 complete low values
 * remain explicitly observed before the final delay store.55D24 also
 * has two formal arguments;the original complete A2 counter remains.
 * 2803C's caller narrows its result to signed16 after original A0/A1
 * staging.369B8's two physical input words are a forwarding ABI view;
 * its complete2E2D0 formal/semantic contract remains unresolved.
 * Compiler/filter/flags,native and linked targets,all selector bytes
 * and full EXE/every-overlay hashes remain frozen and mandatory.
 * Confidence after gates is binary identity. Allocation/caller/writer
 * closure,helper semantic contracts,units/fixed-point domains,cadence
 * beyond invocation,Rev1 mapping and synchronized captures remain open.
 * Next:human review and those exact evidence chains,without guesses.
 */
/* Original assembly SHA256 607172a3482e0d315cc573d73deac5eefea2d544308e828474138243011673b8 */
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned low;
#else
        unsigned low;
        int high;
#endif
    } words;
} Level23_83BFCCompleteProduct;
#define Level23_83BFCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level23_83BFCKeep(x) __asm__ volatile("" ::"r"(x))
void Level23_83BFCCall13ACCView1(void*, int) __asm__("func_80013ACC");
void Level23_83BFCCall13D44View1(void*, int, void*, int) __asm__("func_80013D44");
void Level23_83BFCCall1BA30View1(void*, int, int, int, int, void*) __asm__("func_8001BA30");
int Level23_83BFCCall2803CView1(int, int, void*, void*, void*, int*, int) __asm__("func_8002803C");
int Level23_83BFCCall28154View1(int) __asm__("func_80028154");
void Level23_83BFCRequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
void Level23_83BFCSetMobyAnimationView1(void*, int) __asm__("func_80034F80");
int Level23_83BFCTurnMobyTowardPlayerView1(void*, int, int, int) __asm__("func_8003573C");
int Level23_83BFCCountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level23_83BFCCall35EE0View1(void*, int, int, int, int, int) __asm__("func_80035EE0");
int Level23_83BFCRandBetweenView1(int, int) __asm__("func_8003636C");
void Level23_83BFCCall369B8View1(int, int) __asm__("func_800369B8");
void Level23_83BFCCall3B7B4View1(void*, int, void*) __asm__("func_8003B7B4");
int Level23_83BFCPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level23_83BFCMeasureVectorLengthView1(void*, int) __asm__("func_8004EDE8");
void Level23_83BFCScaleVectorRatioQ15View1(void*, int, int) __asm__("func_8004F08C");
void Level23_83BFCShiftVectorRightTowardZeroView1(void*, int) __asm__("func_8004F110");
void Level23_83BFCCopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level23_83BFCAddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level23_83BFCSubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level23_83BFCAbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level23_83BFCApproximatePlanarDistanceView1(void*, void*) __asm__("func_8004F334");
void Level23_83BFCDeleteMobyView1(void*) __asm__("func_80055B18");
void Level23_83BFCRefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
int Level23_83BFCCall55E84View1(void*) __asm__("func_80055E84");
void Level23_83BFCInterpolateMobyVertexView1(void*, int, void*) __asm__("func_80055F14");
extern unsigned char Level23_83BFCData658A0View1 __asm__("D_800658A0");
extern unsigned char Level23_83BFCData65920View1 __asm__("D_80065920");
extern int Level23_83BFCData6C550View1 __asm__("D_8006C550");
extern int Level23_83BFCData6C58CView1 __asm__("D_8006C58C");
extern int Level23_83BFCData6C770View1 __asm__("D_8006C770");
extern unsigned char Level23_83BFCData6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Level23_83BFCData6C7F8View1 __asm__("D_8006C7F8");
extern unsigned char Level23_83BFCData6D088View1 __asm__("D_8006D088");
extern int Level23_83BFCData6E044View1 __asm__("D_8006E044");
extern unsigned char Level23_83BFCData70300View1 __asm__("D_80070300");
extern int Level23_83BFCData70328View1 __asm__("D_80070328");
extern void* (*Level23_83BFCDataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level23_83BFCDataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
extern int Level23_83BFCData74364View1 __asm__("unk_ovlheader_80074364");
extern int Level23_83BFCData74368View1 __asm__("unk_ovlheader_80074368");
extern int Level23_83BFCData7436CView1 __asm__("unk_ovlheader_8007436C");
void func_level_23_80083BFC(void* ownerParameter) {
    register int framePrivateOrPlayerBase16 __asm__("$16"),
        actorHeadingConstantOrFrame17 __asm__("$17"), owner18 __asm__("$18"),
        spawnOrScalar19 __asm__("$19"), linkedActor20 __asm__("$20"),
        privateRecord21 __asm__("$21"), spawnPrivate22 __asm__("$22");
    register int resultOrIntermediate2 __asm__("$2"), fieldOrIntermediate3 __asm__("$3"),
        argumentOrIntermediate4 __asm__("$4"), argumentOrIntermediate5 __asm__("$5"),
        argumentOrCapture6 __asm__("$6"), argumentOrCapture7 __asm__("$7"),
        constantOrLowCapture8 __asm__("$8"), classConstant9 __asm__("$9"),
        classConstant10 __asm__("$10"), highCapture11 __asm__("$11");
    Level23_83BFCCompleteProduct predictX, predictY, predictZ, aimX, aimY, aimZ, aimDistance,
        retailDistance, retailSix, retailLow;
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C;
    } originalFrame;
    int var_a1;
    int temp_a0_2;
    int temp_a2;
    int temp_v1_12;
    int temp_v1_13;
    int var_v0;
    int var_v1;
    int var_v0_6;
    int temp_a0;
    int temp_v0_10;
    int temp_v0_6;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_5;
    int var_v0_2;
    int var_v0_8;
    int temp_v0_2;
    int var_a0_2;
    owner18 = (int)ownerParameter;
    fieldOrIntermediate3 = 32;
    MATCHING_OBSERVE2_VOLATILE(owner18, fieldOrIntermediate3);
    privateRecord21 = Level23_83BFCField(owner18, int*, 0);
    if (Level23_83BFCField(owner18, unsigned char*, 72) != fieldOrIntermediate3) {
        goto block_3;
    }
    Level23_83BFCField(owner18, signed char*, 0x41) = 0;
    Level23_83BFCField(owner18, signed char*, 0x4C) = 0;
    Level23_83BFCField(owner18, signed char*, 0x4D) = 0;
    Level23_83BFCField(owner18, int*, 8) = 0;
    if (Level23_83BFCApproximatePlanarDistanceView1(owner18 + 0xC,
                                                    (int)&Level23_83BFCData70328View1) >= 0x800) {
        goto block_177;
    }
    var_v1 = Level23_83BFCField(privateRecord21, int*, 0x10);
    var_v0 = var_v1 * 2;
    goto block_166;
block_3:
    if (!(Level23_83BFCField(owner18, int*, 0x18) & 0x40000)) {
        goto block_12;
    }
    Level23_83BFCField(owner18, int*, 0x18) = 0;
    Level23_83BFCField(owner18, unsigned char*, 0x49) = 0U;
    Level23_83BFCField(privateRecord21, int*, 4) = 0;
    if (Level23_83BFCField(privateRecord21, int*, 0xC) >= 2) {
        goto block_10;
    }
    spawnOrScalar19 = 0;
    fieldOrIntermediate3 = Level23_83BFCField(privateRecord21, int*, 40);
    argumentOrIntermediate4 = Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 640);
    resultOrIntermediate2 = fieldOrIntermediate3 * 88;
    fieldOrIntermediate3 = Level23_83BFCData6C550View1;
    linkedActor20 = fieldOrIntermediate3 + resultOrIntermediate2;
    if (argumentOrIntermediate4 < 0) {
        goto block_7;
    }
    spawnOrScalar19 = Level23_83BFCDataSpawnMobyView1(0x1E, owner18);
block_7:
    argumentOrCapture6 = 0;
    if (spawnOrScalar19 == 0) {
        goto block_9;
    }
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrCapture6, "$17");
    actorHeadingConstantOrFrame17 = 180;
    Level23_83BFCKeep(actorHeadingConstantOrFrame17);
    framePrivateOrPlayerBase16 = Level23_83BFCField(spawnOrScalar19, int*, 0);
    Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 644) =
        actorHeadingConstantOrFrame17;
    Level23_83BFCField(spawnOrScalar19, signed char*, 0x48) = 0x1E;
    Level23_83BFCField(spawnOrScalar19, int*, 8) = 0;
    Level23_83BFCField(spawnOrScalar19, unsigned char*, 0x46) =
        Level23_83BFCPlanarHeadingLookupView1(
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0) -
                Level23_83BFCField(owner18, int*, 0xC),
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 4) -
                Level23_83BFCField(owner18, int*, 16),
            argumentOrCapture6);
    Level23_83BFCField(spawnOrScalar19, signed char*, 0x41) = 0;
    Level23_83BFCField(spawnOrScalar19, signed char*, 0x4C) = 0;
    Level23_83BFCField(spawnOrScalar19, signed char*, 0x4D) = 0;
    Level23_83BFCCall35EE0View1(
        spawnOrScalar19, (Level23_83BFCField(spawnOrScalar19, unsigned char*, 0x46) + 0x80) & 0xFF,
        0x2BC, 0, 0, 0);
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0) = actorHeadingConstantOrFrame17;
    resultOrIntermediate2 = 300;
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4) = resultOrIntermediate2;
    fieldOrIntermediate3 = Level23_83BFCField(owner18, int*, 20);
    resultOrIntermediate2 = 3;
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 8) = resultOrIntermediate2;
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 16) = linkedActor20;
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 12) = fieldOrIntermediate3;
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x14) =
        (int)Level23_83BFCField(privateRecord21, int*, 0x10);
block_9:
    Level23_83BFCCall1BA30View1(owner18 + 0xC, 0x4000, 1, 0, 0x10000, owner18);
    Level23_83BFCCall28154View1(Level23_83BFCField(privateRecord21, int*, 0x24));
    argumentOrIntermediate4 = owner18;
    argumentOrIntermediate5 = 7;
    MATCHING_OBSERVE2_VOLATILE(argumentOrIntermediate4, argumentOrIntermediate5);
    var_a1 = argumentOrIntermediate5;
    var_v0_2 = 7;
    goto block_11;
block_10:
    MATCHING_BARRIER_VOLATILE("$4");
    argumentOrIntermediate4 = owner18;
    argumentOrIntermediate5 = 3;
    MATCHING_OBSERVE2_VOLATILE(argumentOrIntermediate4, argumentOrIntermediate5);
    var_a1 = argumentOrIntermediate5;
    Level23_83BFCField(privateRecord21, unsigned char*, 8) = 1U;
    var_v0_2 = 3;
block_11:
    Level23_83BFCField(owner18, unsigned char*, 0x48) = var_v0_2;
    Level23_83BFCRequestMobyAnimationView1(argumentOrIntermediate4, argumentOrIntermediate5);
block_12:
    temp_v1 = Level23_83BFCField(owner18, unsigned char*, 0x48);
    if (temp_v1 >= 0x1EU) {
        goto block_31;
    }
    if (temp_v1 == 7) {
        goto block_16;
    }
    if (Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x50) != 7) {
        goto block_16;
    }
    Level23_83BFCField(privateRecord21, short*, 0xA) = 2;
block_16:
    MATCHING_BARRIER_VOLATILE("memory");
    fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 72);
    MATCHING_KEEP(fieldOrIntermediate3);
    temp_v1_2 = fieldOrIntermediate3;
    temp_a0 = temp_v1_2 & 0xFF;
    if (temp_a0 >= 0x1EU) {
        goto block_30;
    }
    if ((unsigned int)(temp_v1_2 - 6) < 2U) {
        goto block_30;
    }
    if (temp_a0 == 3) {
        goto block_30;
    }
    framePrivateOrPlayerBase16 = (int)&Level23_83BFCData70328View1 + 0x98;
    Level23_83BFCCopyVectorView1(&originalFrame.sp20, framePrivateOrPlayerBase16);
    resultOrIntermediate2 = originalFrame.sp20;
    Level23_83BFCKeep(resultOrIntermediate2);
    fieldOrIntermediate3 = 26;
    Level23_83BFCKeep(fieldOrIntermediate3);
    predictX.full = (long long)resultOrIntermediate2 * (long long)fieldOrIntermediate3;
    __asm__("" : "=x"(predictX.full) : "0"(predictX.full));
    argumentOrCapture7 = (int)predictX.words.low;
    resultOrIntermediate2 = originalFrame.sp24;
    __asm__("" : "=r"(resultOrIntermediate2) : "0"(resultOrIntermediate2), "r"(argumentOrCapture7));
    predictY.full = (long long)resultOrIntermediate2 * (long long)fieldOrIntermediate3;
    __asm__("" : "=x"(predictY.full) : "0"(predictY.full));
    argumentOrCapture6 = (int)predictY.words.low;
    resultOrIntermediate2 = originalFrame.sp28;
    __asm__("" : "=r"(resultOrIntermediate2) : "0"(resultOrIntermediate2), "r"(argumentOrCapture6));
    predictZ.full = (long long)resultOrIntermediate2 * (long long)fieldOrIntermediate3;
    __asm__("" : "=x"(predictZ.full) : "0"(predictZ.full));
    argumentOrIntermediate4 = (int)&originalFrame.sp20;
    argumentOrIntermediate5 = 6;
    originalFrame.sp20 = argumentOrCapture7;
    originalFrame.sp24 = argumentOrCapture6;
    __asm__(""
            : "=x"(predictZ.full)
            : "0"(predictZ.full), "r"(argumentOrIntermediate4), "r"(argumentOrIntermediate5),
              "m"(originalFrame.sp20), "m"(originalFrame.sp24));
    fieldOrIntermediate3 = (int)predictZ.words.low;
    Level23_83BFCKeep(fieldOrIntermediate3);
    Level23_83BFCKeep(argumentOrCapture6);
    Level23_83BFCKeep(argumentOrCapture7);
    originalFrame.sp28 = fieldOrIntermediate3;
    Level23_83BFCShiftVectorRightTowardZeroView1(argumentOrIntermediate4, argumentOrIntermediate5);
    Level23_83BFCAddVectorView1(&originalFrame.sp20, &originalFrame.sp20,
                                framePrivateOrPlayerBase16 - 0x98);
    if (Level23_83BFCApproximatePlanarDistanceView1(owner18 + 0xC, &originalFrame.sp20) >= 0x672) {
        goto block_30;
    }
    fieldOrIntermediate3 = Level23_83BFCField(owner18, int*, 20);
    Level23_83BFCKeep(fieldOrIntermediate3);
    if (Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 8) < fieldOrIntermediate3) {
        goto block_30;
    }
    if (Level23_83BFCField(owner18, unsigned char*, 0x49) != 1) {
        goto block_24;
    }
    actorHeadingConstantOrFrame17 = Level23_83BFCField(privateRecord21, int*, 4);
    if (actorHeadingConstantOrFrame17 == 0) {
        goto block_24;
    }
    framePrivateOrPlayerBase16 = Level23_83BFCField(actorHeadingConstantOrFrame17, int*, 0);
    Level23_83BFCRefreshMobySpatialGridAndBasisView1(owner18, 5);
    Level23_83BFCInterpolateMobyVertexView1(owner18, 0,
                                            Level23_83BFCField(privateRecord21, int*, 4) + 0xC);
    Level23_83BFCField(actorHeadingConstantOrFrame17, signed char*, 0x48) = 1;
    Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x44) =
        (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x44);
    resultOrIntermediate2 = Level23_83BFCRandBetweenView1(0, 155);
    argumentOrIntermediate4 = actorHeadingConstantOrFrame17;
    argumentOrIntermediate5 = 128;
    fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 69);
    argumentOrCapture6 = 0;
    fieldOrIntermediate3 -= 35;
    Level23_83BFCKeep(fieldOrIntermediate3);
    fieldOrIntermediate3 += resultOrIntermediate2;
    Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 69) = fieldOrIntermediate3;
    Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x46) =
        (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x46);
    Level23_83BFCTurnMobyTowardPlayerView1(argumentOrIntermediate4, argumentOrIntermediate5,
                                           argumentOrCapture6, 0);
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 8) = 0xFA;
    Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4) = 0xC8;
    Level23_83BFCField(framePrivateOrPlayerBase16, short*, 2) =
        (short)Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x46);
    Level23_83BFCField(owner18, unsigned char*, 0x49) = 2U;
block_24:
    temp_v1_3 = Level23_83BFCField(owner18, unsigned char*, 0x48);
    if (temp_v1_3 != 4) {
        goto block_26;
    }
    Level23_83BFCField(privateRecord21, unsigned char*, 8) = 0U;
    goto block_28;
block_26:
    if (temp_v1_3 != 5) {
        goto block_29;
    }
    Level23_83BFCField(privateRecord21, unsigned char*, 8) = 1U;
block_28:
block_29:
    Level23_83BFCField(owner18, unsigned char*, 0x48) = 6U;
    argumentOrIntermediate4 = owner18;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrIntermediate4, "$5");
    argumentOrIntermediate5 = 6;
    goto block_176;
block_30:
block_31:
    if (Level23_83BFCField(owner18, unsigned char*, 0x48) >= 0x20U) {
        goto block_177;
    }
    switch (Level23_83BFCField(owner18, unsigned char*, 0x48)) {
        case 0:
            resultOrIntermediate2 = Level23_83BFCCall55E84View1(owner18);
            fieldOrIntermediate3 = Level23_83BFCField(privateRecord21, short*, 10);
            framePrivateOrPlayerBase16 = resultOrIntermediate2;
            Level23_83BFCKeep(framePrivateOrPlayerBase16);
            if (fieldOrIntermediate3 <= 0)
                goto block_35;
            resultOrIntermediate2 = fieldOrIntermediate3;
            Level23_83BFCKeep(resultOrIntermediate2);
            Level23_83BFCField(owner18, unsigned char*, 72) = resultOrIntermediate2;
            __asm__(""
                    : "=r"(owner18)
                    : "0"(owner18), "m"(Level23_83BFCField(owner18, unsigned char*, 72))
                    : "memory");
            argumentOrIntermediate5 = Level23_83BFCField(privateRecord21, short*, 10);
            MATCHING_OBSERVE_VOLATILE(framePrivateOrPlayerBase16);
            argumentOrIntermediate4 = owner18;
            goto block_176;
        block_35:
            Level23_83BFCTurnMobyTowardPlayerView1(owner18, 4, 4, 1);
            if (Level23_83BFCCountTimerDownView1(privateRecord21, 4) != 0) {
                goto block_40;
            }
            if (Level23_83BFCField(privateRecord21, unsigned char*, 8) != 0) {
                goto block_38;
            }
            if (Level23_83BFCData6C770View1 != 0) {
                goto block_40;
            }
        block_38:
            if (Level23_83BFCField(owner18, unsigned char*, 0x49) != 0xA) {
                goto block_44;
            }
            if ((unsigned int)(framePrivateOrPlayerBase16 - 0x45) >= 5U) {
                goto block_44;
            }
        block_40:
            resultOrIntermediate2 = Level23_83BFCField(privateRecord21, unsigned char*, 8);
            argumentOrIntermediate4 = owner18;
            if (resultOrIntermediate2)
                goto block_42;
            resultOrIntermediate2 = 8;
            Level23_83BFCField(owner18, unsigned char*, 72) = resultOrIntermediate2;
            argumentOrIntermediate5 = 8;
            goto block_43;
        block_42:
            argumentOrIntermediate5 = 4;
            resultOrIntermediate2 = 4;
            Level23_83BFCField(owner18, unsigned char*, 73) = 0;
            Level23_83BFCField(owner18, unsigned char*, 72) = resultOrIntermediate2;
        block_43:
            MATCHING_OBSERVE2_VOLATILE(argumentOrIntermediate4, argumentOrIntermediate5);
            Level23_83BFCRequestMobyAnimationView1(argumentOrIntermediate4,
                                                   argumentOrIntermediate5);
        block_44:
            if (Level23_83BFCField(owner18, unsigned char*, 0x49) != 0) {
                goto block_177;
            }
            if (Level23_83BFCField(privateRecord21, int*, 0) < 0x65) {
                goto block_177;
            }
            resultOrIntermediate2 = framePrivateOrPlayerBase16 < 73;
            Level23_83BFCKeep(resultOrIntermediate2);
            if (!resultOrIntermediate2) {
                goto block_177;
            }
            if (Level23_83BFCRandBetweenView1(0, 0x96) != 0) {
                goto block_177;
            }
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 1U;
            argumentOrIntermediate4 = owner18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrIntermediate4, "$5");
            argumentOrIntermediate5 = 1;
            goto block_176;
        case 1:
            resultOrIntermediate2 = Level23_83BFCField(privateRecord21, short*, 10);
            if (resultOrIntermediate2 <= 0)
                goto block_51;
            fieldOrIntermediate3 = resultOrIntermediate2;
            Level23_83BFCKeep(fieldOrIntermediate3);
            Level23_83BFCField(owner18, unsigned char*, 72) = fieldOrIntermediate3;
            __asm__(""
                    : "=r"(owner18)
                    : "0"(owner18), "m"(Level23_83BFCField(owner18, unsigned char*, 72))
                    : "memory");
            argumentOrIntermediate5 = Level23_83BFCField(privateRecord21, short*, 10);
            MATCHING_OBSERVE_VOLATILE(privateRecord21);
            argumentOrIntermediate4 = owner18;
            goto block_176;
        block_51:
            if (!Level23_83BFCData6C770View1)
                goto block_177;
            resultOrIntermediate2 = 8;
            fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 73);
            argumentOrIntermediate4 = owner18;
            if (fieldOrIntermediate3 != resultOrIntermediate2)
                goto block_54;
            MATCHING_KEEP2_VOLATILE_CLOBBER(resultOrIntermediate2, fieldOrIntermediate3, "$5");
            argumentOrIntermediate5 = 8;
            MATCHING_KEEP_VOLATILE(argumentOrIntermediate5);
            resultOrIntermediate2 = 9;
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 73) = resultOrIntermediate2;
            resultOrIntermediate2 = 8;
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 72) = resultOrIntermediate2;
            goto block_176;
        block_54:
            MATCHING_BARRIER_VOLATILE("$5");
            argumentOrIntermediate5 = 0;
            resultOrIntermediate2 = 10;
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 73) = resultOrIntermediate2;
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 72) = 0;
            goto block_176;
        case 2:
            if (!Level23_83BFCData6C770View1)
                goto block_177;
            argumentOrIntermediate4 = owner18;
            argumentOrIntermediate5 = 0;
            Level23_83BFCField(privateRecord21, short*, 10) = 0;
            resultOrIntermediate2 = 150;
            Level23_83BFCField(privateRecord21, int*, 0) = resultOrIntermediate2;
            __asm__ volatile(""
                             : "=r"(argumentOrIntermediate4)
                             : "0"(argumentOrIntermediate4), "r"(privateRecord21));
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 72) = 0;
            goto block_176;
        case 3:
            if (!Level23_83BFCData6C770View1)
                goto block_177;
            argumentOrIntermediate4 = owner18;
            argumentOrIntermediate5 = 0;
            Level23_83BFCField(privateRecord21, short*, 10) = 0;
            resultOrIntermediate2 = Level23_83BFCField(privateRecord21, int*, 12);
            fieldOrIntermediate3 = 150;
            Level23_83BFCField(privateRecord21, int*, 0) = fieldOrIntermediate3;
            resultOrIntermediate2--;
            Level23_83BFCField(privateRecord21, int*, 12) = resultOrIntermediate2;
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 72) = 0;
            goto block_176;
        block_59:
            MATCHING_KEEP_VOLATILE(argumentOrIntermediate5);
            argumentOrIntermediate5++;
            goto block_66;
        case 4:
            resultOrIntermediate2 = Level23_83BFCCall55E84View1(owner18);
            argumentOrIntermediate4 = owner18;
            argumentOrIntermediate5 = 4;
            argumentOrCapture6 = 4;
            argumentOrCapture7 = 1;
            MATCHING_OBSERVE4_VOLATILE(argumentOrIntermediate4, argumentOrIntermediate5,
                                       argumentOrCapture6, argumentOrCapture7);
            spawnOrScalar19 = resultOrIntermediate2;
            Level23_83BFCTurnMobyTowardPlayerView1(argumentOrIntermediate4, argumentOrIntermediate5,
                                                   argumentOrCapture6, argumentOrCapture7);
            resultOrIntermediate2 = Level23_83BFCField(owner18, unsigned char*, 73);
            if (resultOrIntermediate2)
                goto actor1295PriorPredicate;
            resultOrIntermediate2 = spawnOrScalar19 < 10;
            goto actor1295ScanBegin;
        actor1295PriorPredicate:
            resultOrIntermediate2 = spawnOrScalar19 < 10;
            goto block_69;
        actor1295ScanBegin:
            argumentOrCapture6 = Level23_83BFCData6C550View1;
            argumentOrIntermediate4 = Level23_83BFCField(argumentOrCapture6, unsigned char*, 72);
            __asm__("" : "=r"(argumentOrIntermediate4) : "0"(argumentOrIntermediate4) : "$2", "$5");
            resultOrIntermediate2 = 255;
            fieldOrIntermediate3 = argumentOrIntermediate4 & 255;
            argumentOrIntermediate5 = 0;
            if (fieldOrIntermediate3 == resultOrIntermediate2)
                goto block_66;
            constantOrLowCapture8 = 404;
            argumentOrCapture7 = 255;
            fieldOrIntermediate3 = argumentOrCapture6 + 72;
        loop_63:
            resultOrIntermediate2 = Level23_83BFCField(fieldOrIntermediate3, short*, -18);
            if (resultOrIntermediate2 != constantOrLowCapture8)
                goto block_65;
            resultOrIntermediate2 = argumentOrIntermediate4 & 128;
            if (!resultOrIntermediate2)
                goto block_59;
        block_65:
            fieldOrIntermediate3 += 88;
            argumentOrIntermediate4 = Level23_83BFCField(fieldOrIntermediate3, unsigned char*, 0);
            if (argumentOrIntermediate4 != argumentOrCapture7)
                goto loop_63;
        block_66:
            resultOrIntermediate2 = 2;
            if (argumentOrIntermediate5)
                goto block_68;
            resultOrIntermediate2 = 1;
        block_68:
            Level23_83BFCField(privateRecord21, unsigned char*, 9) = resultOrIntermediate2;
            resultOrIntermediate2 = 3;
            Level23_83BFCField(owner18, unsigned char*, 73) = resultOrIntermediate2;
            resultOrIntermediate2 = spawnOrScalar19 < 10;
        block_69:
            if (!resultOrIntermediate2)
                goto block_73;
            resultOrIntermediate2 = 4;
            Level23_83BFCKeep(resultOrIntermediate2);
            fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 60);
            if (fieldOrIntermediate3 != resultOrIntermediate2) {
                resultOrIntermediate2 = spawnOrScalar19 < 43;
                goto block_74;
            }
            Level23_83BFCRefreshMobySpatialGridAndBasisView1(owner18, 5);
            Level23_83BFCInterpolateMobyVertexView1(owner18, 0, &originalFrame.sp30);
            Level23_83BFCInterpolateMobyVertexView1(owner18, 1, &originalFrame.sp40);
            Level23_83BFCAddVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                        &originalFrame.sp40);
            Level23_83BFCShiftVectorRightTowardZeroView1(&originalFrame.sp30, 1);
            originalFrame.sp50 = 0;
            originalFrame.sp54 = 0;
            originalFrame.sp58 = (int)Level23_83BFCField(privateRecord21, unsigned char*, 9);
            var_a0_2 = Level23_83BFCDataSpawnParticleView1(1, 0x3C, &originalFrame.sp30,
                                                           &originalFrame.sp50);
            if (var_a0_2 == 0) {
                goto block_80;
            }
            var_v0_6 = (Level23_83BFCField(owner18, unsigned char*, 0x3E) * 0x1F) + 0x1E;
            goto block_79;
        block_73:
            resultOrIntermediate2 = spawnOrScalar19 < 43;
        block_74:
            if (!resultOrIntermediate2)
                goto block_80;
            resultOrIntermediate2 = 4;
            Level23_83BFCKeep(resultOrIntermediate2);
            fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 60);
            if (fieldOrIntermediate3 != resultOrIntermediate2)
                goto block_80;
            Level23_83BFCRefreshMobySpatialGridAndBasisView1(owner18, 5);
            Level23_83BFCInterpolateMobyVertexView1(owner18, 0, &originalFrame.sp30);
            Level23_83BFCInterpolateMobyVertexView1(owner18, 1, &originalFrame.sp40);
            originalFrame.sp50 = 0;
            originalFrame.sp54 = 0;
            originalFrame.sp58 = (int)Level23_83BFCField(privateRecord21, unsigned char*, 9);
            resultOrIntermediate2 = Level23_83BFCDataSpawnParticleView1(1, 60, &originalFrame.sp30,
                                                                        &originalFrame.sp50);
            argumentOrIntermediate4 = resultOrIntermediate2;
            MATCHING_KEEP(argumentOrIntermediate4);
            temp_v0_2 = argumentOrIntermediate4;
            resultOrIntermediate2 = 70;
            if (argumentOrIntermediate4 == 0)
                goto block_78;
            Level23_83BFCField(argumentOrIntermediate4, signed char*, 10) = resultOrIntermediate2;
        block_78:
            argumentOrIntermediate4 = Level23_83BFCDataSpawnParticleView1(
                1, 0x3C, &originalFrame.sp40, &originalFrame.sp50);
            Level23_83BFCKeep(argumentOrIntermediate4);
            var_a0_2 = argumentOrIntermediate4;
            var_v0_6 = 0x46;
            if (var_a0_2 == 0) {
                goto block_80;
            }
        block_79:
            Level23_83BFCField(var_a0_2, signed char*, 0xA) = var_v0_6;
        block_80:
            temp_v1_5 = Level23_83BFCField(owner18, unsigned char*, 0x49);
            if (temp_v1_5 != 3) {
                goto block_82;
            }
            if ((unsigned int)(spawnOrScalar19 - 0x1A) < 0xAU) {
                goto block_87;
            }
        block_82:
            if (temp_v1_5 != 4) {
                goto block_84;
            }
            if ((unsigned int)(spawnOrScalar19 - 0x27) < 6U) {
                goto block_87;
            }
        block_84:
            if (temp_v1_5 != 5) {
                goto block_130;
            }
            resultOrIntermediate2 = spawnOrScalar19 < 49;
            Level23_83BFCKeep(resultOrIntermediate2);
            if (resultOrIntermediate2) {
                goto block_130;
            }
            if ((unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x3E) >= 0x3BU) {
                goto block_130;
            }
        block_87:
            if (Level23_83BFCField(owner18, unsigned char*, 0x3C) != 4) {
                goto block_130;
            }
            resultOrIntermediate2 = Level23_83BFCDataSpawnMobyView1(0x53, owner18);
            linkedActor20 = resultOrIntermediate2;
            MATCHING_KEEP(linkedActor20);
            if (linkedActor20 == 0) {
                goto block_130;
            }
            fieldOrIntermediate3 = Level23_83BFCField(privateRecord21, unsigned char*, 9);
            spawnPrivate22 = Level23_83BFCField(linkedActor20, int*, 0);
            argumentOrCapture6 = 0;
            if (!fieldOrIntermediate3)
                goto block_92;
            resultOrIntermediate2 = 1;
            argumentOrIntermediate4 = owner18;
            if (fieldOrIntermediate3 != resultOrIntermediate2)
                goto block_103;
            MATCHING_KEEP_VOLATILE(resultOrIntermediate2);
            resultOrIntermediate2 = 1;
            goto block_101;
        block_92:
            argumentOrIntermediate4 = Level23_83BFCData6C550View1;
            argumentOrIntermediate5 =
                Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 72);
            MATCHING_KEEP_CLOBBER(argumentOrIntermediate5, "$2");
            resultOrIntermediate2 = 255;
            Level23_83BFCKeep(resultOrIntermediate2);
            MATCHING_KEEP(argumentOrCapture6);
            fieldOrIntermediate3 = argumentOrIntermediate5 & 255;
            if (fieldOrIntermediate3 == resultOrIntermediate2) {
                resultOrIntermediate2 = argumentOrCapture6 < 3;
                goto block_100;
            }
            resultOrIntermediate2 = argumentOrCapture6 < 3;
            MATCHING_BARRIER_VOLATILE("$7");
            classConstant10 = 404;
            classConstant9 = 83;
            constantOrLowCapture8 = 1;
            argumentOrCapture7 = 255;
            argumentOrIntermediate4 += 72;
        loop_94:
            fieldOrIntermediate3 = Level23_83BFCField(argumentOrIntermediate4, short*, -18);
            if (fieldOrIntermediate3 != classConstant10)
                goto block_96;
            resultOrIntermediate2 = argumentOrIntermediate5 & 128;
            if (!resultOrIntermediate2)
                goto block_98;
        block_96:
            if (fieldOrIntermediate3 != classConstant9)
                goto block_99;
            resultOrIntermediate2 = Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 0);
            if (resultOrIntermediate2 != constantOrLowCapture8)
                goto block_99;
        block_98:
            argumentOrCapture6++;
            resultOrIntermediate2 = argumentOrCapture6 < 3;
            if (!resultOrIntermediate2)
                goto block_102;
        block_99:
            argumentOrIntermediate4 += 88;
            argumentOrIntermediate5 =
                Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 0);
            resultOrIntermediate2 = argumentOrCapture6 < 3;
            if (argumentOrIntermediate5 != argumentOrCapture7)
                goto loop_94;
        block_100:
            if (!resultOrIntermediate2)
                goto block_102;
            resultOrIntermediate2 = 1;
        block_101:
            Level23_83BFCField(linkedActor20, unsigned char*, 72) = resultOrIntermediate2;
        block_102:
            argumentOrIntermediate4 = owner18;
        block_103:
            Level23_83BFCField(spawnPrivate22, int*, 0x14) = owner18;
            Level23_83BFCKeep(argumentOrCapture6);
            Level23_83BFCField(spawnPrivate22, int*, 16) =
                Level23_83BFCField(privateRecord21, int*, 24);
            Level23_83BFCRefreshMobySpatialGridAndBasisView1(argumentOrIntermediate4, 5);
            fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 73);
            resultOrIntermediate2 = 4;
            if (fieldOrIntermediate3 != resultOrIntermediate2)
                goto block_105;
            argumentOrIntermediate4 = owner18;
            MATCHING_KEEP(argumentOrIntermediate4);
            argumentOrIntermediate5 = 1;
            goto block_106;
        block_105:
            argumentOrIntermediate4 = owner18;
            argumentOrIntermediate5 = 0;
        block_106:
            Level23_83BFCInterpolateMobyVertexView1(argumentOrIntermediate4,
                                                    argumentOrIntermediate5, linkedActor20 + 12);
            argumentOrCapture6 = 0;
            resultOrIntermediate2 = 255;
            framePrivateOrPlayerBase16 = (int)&Level23_83BFCData70328View1;
            Level23_83BFCKeep(framePrivateOrPlayerBase16);
            Level23_83BFCField(linkedActor20, unsigned char*, 74) = resultOrIntermediate2;
            fieldOrIntermediate3 = Level23_83BFCField(owner18, int*, 12);
            argumentOrIntermediate4 = Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0);
            resultOrIntermediate2 = Level23_83BFCField(owner18, int*, 16);
            argumentOrIntermediate5 =
                Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 4);
            argumentOrIntermediate4 = fieldOrIntermediate3 - argumentOrIntermediate4;
            argumentOrIntermediate5 = resultOrIntermediate2 - argumentOrIntermediate5;
            resultOrIntermediate2 = Level23_83BFCPlanarHeadingLookupView1(
                argumentOrIntermediate4, argumentOrIntermediate5, argumentOrCapture6);
            actorHeadingConstantOrFrame17 = resultOrIntermediate2;
            MATCHING_KEEP(framePrivateOrPlayerBase16);
            argumentOrIntermediate5 =
                Level23_83BFCField(framePrivateOrPlayerBase16, unsigned char*, 14);
            temp_a0_2 = Level23_83BFCAbsoluteByteAngleDeltaView1(actorHeadingConstantOrFrame17,
                                                                 argumentOrIntermediate5);
            argumentOrIntermediate4 = temp_a0_2;
            fieldOrIntermediate3 = Level23_83BFCField(linkedActor20, unsigned char*, 72);
            if (fieldOrIntermediate3 != 1) {
                resultOrIntermediate2 = argumentOrIntermediate4 - 32;
                goto block_111;
            }
            resultOrIntermediate2 = 50;
            Level23_83BFCField(spawnPrivate22, int*, 8) = resultOrIntermediate2;
            fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 73);
            resultOrIntermediate2 = 3;
            if (fieldOrIntermediate3 == resultOrIntermediate2)
                goto block_116;
            resultOrIntermediate2 = 4;
            Level23_83BFCKeep(resultOrIntermediate2);
            if (fieldOrIntermediate3 != resultOrIntermediate2)
                goto block_110;
            var_v0_8 = Level23_83BFCField(owner18, unsigned char*, 70) + 224;
            goto block_124;
        block_110:
            var_v0_8 = Level23_83BFCField(owner18, unsigned char*, 70) + 32;
            goto block_124;
        block_111:
            if ((unsigned int)resultOrIntermediate2 < 65)
                goto block_117;
            resultOrIntermediate2 = argumentOrIntermediate4 < 16;
            if (resultOrIntermediate2)
                goto block_114;
            resultOrIntermediate2 = argumentOrIntermediate4 < 32;
            Level23_83BFCKeep(resultOrIntermediate2);
            spawnOrScalar19 = 90;
            if (!resultOrIntermediate2)
                goto block_115;
        block_114:
            spawnOrScalar19 = 0x50;
        block_115:
            actorHeadingConstantOrFrame17 = (int)&originalFrame.sp60;
            argumentOrIntermediate4 = actorHeadingConstantOrFrame17;
            Level23_83BFCKeep(argumentOrIntermediate4);
            framePrivateOrPlayerBase16 = (int)&Level23_83BFCData70328View1 + 152;
            Level23_83BFCCopyVectorView1(argumentOrIntermediate4, framePrivateOrPlayerBase16);
            resultOrIntermediate2 = originalFrame.sp60;
            Level23_83BFCKeep(resultOrIntermediate2);
            aimX.full = (long long)resultOrIntermediate2 * (long long)spawnOrScalar19;
            __asm__("" : "=x"(aimX.full) : "0"(aimX.full));
            argumentOrCapture6 = (int)aimX.words.low;
            resultOrIntermediate2 = originalFrame.sp64;
            __asm__(""
                    : "=r"(resultOrIntermediate2)
                    : "0"(resultOrIntermediate2), "r"(argumentOrCapture6));
            aimY.full = (long long)resultOrIntermediate2 * (long long)spawnOrScalar19;
            __asm__("" : "=x"(aimY.full) : "0"(aimY.full));
            fieldOrIntermediate3 = (int)aimY.words.low;
            resultOrIntermediate2 = originalFrame.sp68;
            __asm__(""
                    : "=r"(resultOrIntermediate2)
                    : "0"(resultOrIntermediate2), "r"(fieldOrIntermediate3));
            aimZ.full = (long long)resultOrIntermediate2 * (long long)spawnOrScalar19;
            __asm__("" : "=x"(aimZ.full) : "0"(aimZ.full));
            argumentOrIntermediate4 = actorHeadingConstantOrFrame17;
            argumentOrIntermediate5 = 6;
            originalFrame.sp60 = argumentOrCapture6;
            originalFrame.sp64 = fieldOrIntermediate3;
            __asm__(""
                    : "=x"(aimZ.full)
                    : "0"(aimZ.full), "r"(argumentOrIntermediate4), "r"(argumentOrIntermediate5),
                      "m"(originalFrame.sp60), "m"(originalFrame.sp64));
            constantOrLowCapture8 = (int)aimZ.words.low;
            Level23_83BFCKeep(constantOrLowCapture8);
            Level23_83BFCKeep(argumentOrCapture6);
            originalFrame.sp68 = constantOrLowCapture8;
            Level23_83BFCShiftVectorRightTowardZeroView1(argumentOrIntermediate4,
                                                         argumentOrIntermediate5);
            Level23_83BFCAddVectorView1(actorHeadingConstantOrFrame17,
                                        actorHeadingConstantOrFrame17,
                                        framePrivateOrPlayerBase16 - 152);
            resultOrIntermediate2 = Level23_83BFCApproximatePlanarDistanceView1(
                owner18 + 12, actorHeadingConstantOrFrame17);
            fieldOrIntermediate3 = (int)0x8D3DCB09;
            Level23_83BFCKeep(fieldOrIntermediate3);
            resultOrIntermediate2 -= 3660;
            aimDistance.full = (long long)resultOrIntermediate2 * (long long)fieldOrIntermediate3;
            __asm__("" : "=x"(aimDistance.full) : "0"(aimDistance.full));
            framePrivateOrPlayerBase16 = (int)&originalFrame.sp70;
            argumentOrIntermediate4 = framePrivateOrPlayerBase16;
            argumentOrIntermediate5 = actorHeadingConstantOrFrame17;
            argumentOrCapture6 = linkedActor20 + 12;
            __asm__(""
                    : "=x"(aimDistance.full)
                    : "0"(aimDistance.full), "r"(argumentOrIntermediate4),
                      "r"(argumentOrIntermediate5), "r"(argumentOrCapture6));
            highCapture11 = aimDistance.words.high;
            Level23_83BFCKeep(highCapture11);
            fieldOrIntermediate3 = highCapture11 + resultOrIntermediate2;
            fieldOrIntermediate3 >>= 5;
            resultOrIntermediate2 >>= 31;
            fieldOrIntermediate3 -= resultOrIntermediate2;
            fieldOrIntermediate3 += 50;
            Level23_83BFCField(spawnPrivate22, int*, 8) = fieldOrIntermediate3;
            Level23_83BFCSubtractVectorView1(argumentOrIntermediate4, argumentOrIntermediate5,
                                             argumentOrCapture6);
            Level23_83BFCScaleVectorRatioQ15View1(
                framePrivateOrPlayerBase16,
                Level23_83BFCMeasureVectorLengthView1(framePrivateOrPlayerBase16, 1), 300);
            resultOrIntermediate2 =
                Level23_83BFCPlanarHeadingLookupView1(originalFrame.sp70, originalFrame.sp74, 0);
            temp_v0_6 = resultOrIntermediate2;
            Level23_83BFCField(linkedActor20, unsigned char*, 0x46) = temp_v0_6;
            if (Level23_83BFCAbsoluteByteAngleDeltaView1(
                    temp_v0_6 & 0xFF, Level23_83BFCField(owner18, unsigned char*, 0x46)) < 0x41) {
                goto block_126;
            }
        block_116:
            Level23_83BFCField(linkedActor20, unsigned char*, 0x46) =
                (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x46);
            goto block_125;
        block_117:
            resultOrIntermediate2 = Level23_83BFCApproximatePlanarDistanceView1(
                owner18 + 12, framePrivateOrPlayerBase16);
            fieldOrIntermediate3 = (int)0x8D3DCB09;
            Level23_83BFCKeep(fieldOrIntermediate3);
            argumentOrIntermediate4 = resultOrIntermediate2 - 3660;
            retailDistance.full =
                (long long)argumentOrIntermediate4 * (long long)fieldOrIntermediate3;
            __asm__("" : "=x"(retailDistance.full) : "0"(retailDistance.full));
            argumentOrIntermediate5 = 0x2AAAAAAB;
            __asm__(""
                    : "=x"(retailDistance.full)
                    : "0"(retailDistance.full), "r"(argumentOrIntermediate5));
            highCapture11 = retailDistance.words.high;
            Level23_83BFCKeep(highCapture11);
            fieldOrIntermediate3 = highCapture11 + argumentOrIntermediate4;
            fieldOrIntermediate3 >>= 5;
            argumentOrIntermediate4 >>= 31;
            fieldOrIntermediate3 -= argumentOrIntermediate4;
            fieldOrIntermediate3 += 50;
            retailSix.full = (long long)fieldOrIntermediate3 * (long long)argumentOrIntermediate5;
            __asm__("" : "=x"(retailSix.full) : "0"(retailSix.full));
            argumentOrIntermediate4 =
                Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 180);
            Level23_83BFCField(spawnPrivate22, int*, 8) = fieldOrIntermediate3;
            fieldOrIntermediate3 >>= 31;
            argumentOrCapture6 = argumentOrIntermediate4 >> 5;
            __asm__(""
                    : "=x"(retailSix.full)
                    : "0"(retailSix.full), "r"(argumentOrCapture6),
                      "m"(Level23_83BFCField(spawnPrivate22, int*, 8)));
            highCapture11 = retailSix.words.high;
            Level23_83BFCKeep(highCapture11);
            argumentOrIntermediate4 = argumentOrCapture6 << 1;
            fieldOrIntermediate3 = highCapture11 - fieldOrIntermediate3;
            retailLow.full = (long long)argumentOrIntermediate4 * (long long)fieldOrIntermediate3;
            __asm__("" : "=x"(retailLow.full) : "0"(retailLow.full));
            __asm__(""
                    : "=r"(resultOrIntermediate2)
                    : "0"(resultOrIntermediate2), "x"(retailLow.full));
            fieldOrIntermediate3 = (int)((unsigned int)resultOrIntermediate2 << 1);
            Level23_83BFCKeep(fieldOrIntermediate3);
            fieldOrIntermediate3 =
                (int)((unsigned int)fieldOrIntermediate3 + (unsigned int)resultOrIntermediate2);
            fieldOrIntermediate3 = (int)((unsigned int)fieldOrIntermediate3 << 3);
            fieldOrIntermediate3 =
                (int)((unsigned int)fieldOrIntermediate3 + (unsigned int)resultOrIntermediate2);
            fieldOrIntermediate3 = (int)((unsigned int)fieldOrIntermediate3 << 3);
            fieldOrIntermediate3 =
                (int)((unsigned int)fieldOrIntermediate3 + (unsigned int)resultOrIntermediate2);
            fieldOrIntermediate3 = (int)((unsigned int)fieldOrIntermediate3 << 4);
            fieldOrIntermediate3 =
                (int)((unsigned int)fieldOrIntermediate3 + (unsigned int)resultOrIntermediate2);
            fieldOrIntermediate3 = (int)((unsigned int)fieldOrIntermediate3 << 3);
            fieldOrIntermediate3 =
                (int)((unsigned int)fieldOrIntermediate3 - (unsigned int)resultOrIntermediate2);
            fieldOrIntermediate3 = (int)((unsigned int)fieldOrIntermediate3 << 1);
            Level23_83BFCKeep(fieldOrIntermediate3);
            argumentOrIntermediate5 = fieldOrIntermediate3 >> 13;
            __asm__("" : "=x"(retailLow.full) : "0"(retailLow.full), "r"(argumentOrIntermediate5));
            argumentOrCapture6 = (int)retailLow.words.low;
            if (argumentOrIntermediate5 == 0) {
                goto block_123;
            }
            resultOrIntermediate2 =
                Level23_83BFCField((int)&Level23_83BFCData70328View1, unsigned char*, 14);
            Level23_83BFCKeep(resultOrIntermediate2);
            argumentOrIntermediate4 = actorHeadingConstantOrFrame17 - resultOrIntermediate2;
            if (argumentOrIntermediate4 < 0x81) {
                goto block_120;
            }
            argumentOrIntermediate4 -= 0x100;
        block_120:
            fieldOrIntermediate3 = argumentOrCapture6 << 8;
            if (argumentOrIntermediate4 <= 0) {
                goto block_122;
            }
            var_v0_8 = (Level23_83BFCField(owner18, unsigned char*, 0x46) +
                        (fieldOrIntermediate3 / argumentOrIntermediate5)) &
                       0xFF;
            goto block_124;
        block_122:
            var_v0_8 = (Level23_83BFCField(owner18, unsigned char*, 0x46) -
                        (fieldOrIntermediate3 / argumentOrIntermediate5)) &
                       0xFF;
            goto block_124;
        block_123:
            var_v0_8 = Level23_83BFCField(owner18, unsigned char*, 0x46);
        block_124:
            Level23_83BFCField(linkedActor20, unsigned char*, 0x46) = var_v0_8;
        block_125:
        block_126:
            Level23_83BFCField(spawnPrivate22, int*, 0) = 0xC8;
            if (Level23_83BFCField(linkedActor20, unsigned char*, 0x48) != 1) {
                goto block_128;
            }
            Level23_83BFCField(linkedActor20, signed char*, 0x54) = 0;
            Level23_83BFCField(linkedActor20, unsigned char*, 0x55) = 0xFF;
            goto block_129;
        block_128:
            Level23_83BFCField(linkedActor20, unsigned char*, 0x54) = 0xFF;
            Level23_83BFCField(linkedActor20, signed char*, 0x55) = 0;
        block_129:
            Level23_83BFCField(linkedActor20, signed char*, 86) = 0;
            __asm__ volatile("" ::"m"(Level23_83BFCField(linkedActor20, signed char*, 86)) : "$2");
            resultOrIntermediate2 = 58;
            Level23_83BFCKeep(resultOrIntermediate2);
            Level23_83BFCField(linkedActor20, signed char*, 87) = resultOrIntermediate2;
            Level23_83BFCField(owner18, unsigned char*, 0x49) =
                (unsigned char)(Level23_83BFCField(owner18, unsigned char*, 0x49) + 1);
        block_130:
            if (Level23_83BFCData6C770View1 == 0) {
                goto block_177;
            }
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 0U;
            Level23_83BFCField(privateRecord21, unsigned char*, 8) = 0U;
            Level23_83BFCField(privateRecord21, int*, 0) = 0x96;
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 0U;
            Level23_83BFCSetMobyAnimationView1(owner18, 0);
            Level23_83BFCField(owner18, unsigned char*, 0x3E) = 0x25U;
            Level23_83BFCField(owner18, signed char*, 0x3F) = 0x26;
            Level23_83BFCField(owner18, signed char*, 0x40) = 0x30;
            return;
        case 5:
            resultOrIntermediate2 = Level23_83BFCCall55E84View1(owner18);
            argumentOrIntermediate4 = owner18;
            argumentOrIntermediate5 = 4;
            argumentOrCapture6 = 4;
            argumentOrCapture7 = 1;
            MATCHING_OBSERVE4_VOLATILE(argumentOrIntermediate4, argumentOrIntermediate5,
                                       argumentOrCapture6, argumentOrCapture7);
            framePrivateOrPlayerBase16 = resultOrIntermediate2;
            Level23_83BFCTurnMobyTowardPlayerView1(argumentOrIntermediate4, argumentOrIntermediate5,
                                                   argumentOrCapture6, argumentOrCapture7);
            if (Level23_83BFCField(owner18, unsigned char*, 0x49) != 0) {
                goto block_136;
            }
            if ((unsigned int)(framePrivateOrPlayerBase16 - 6) >= 9U) {
                goto block_136;
            }
            resultOrIntermediate2 = Level23_83BFCDataSpawnMobyView1(0x50, owner18);
            actorHeadingConstantOrFrame17 = resultOrIntermediate2;
            MATCHING_KEEP(actorHeadingConstantOrFrame17);
            if (actorHeadingConstantOrFrame17 == 0) {
                goto block_136;
            }
            Level23_83BFCField(Level23_83BFCField(actorHeadingConstantOrFrame17, int*, 0), int*,
                               0x14) = (int)Level23_83BFCField(privateRecord21, int*, 0x14);
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 1U;
            Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x4A) = 0xFF;
            Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x46) =
                (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x46);
            Level23_83BFCField(privateRecord21, int*, 4) = actorHeadingConstantOrFrame17;
            return;
        block_136:
            if (Level23_83BFCField(owner18, unsigned char*, 0x49) != 1) {
                goto block_141;
            }
            if (Level23_83BFCField(privateRecord21, int*, 4) == 0) {
                goto block_140;
            }
            Level23_83BFCRefreshMobySpatialGridAndBasisView1(owner18, 5);
            Level23_83BFCInterpolateMobyVertexView1(
                owner18, 0, Level23_83BFCField(privateRecord21, int*, 4) + 0xC);
            resultOrIntermediate2 = framePrivateOrPlayerBase16 - 12;
            Level23_83BFCKeep(resultOrIntermediate2);
            if ((unsigned int)resultOrIntermediate2 >= 5U) {
                goto block_141;
            }
            resultOrIntermediate2 = Level23_83BFCField(privateRecord21, int*, 4);
            argumentOrIntermediate4 = 0;
            Level23_83BFCKeep(argumentOrIntermediate4);
            actorHeadingConstantOrFrame17 = resultOrIntermediate2;
            MATCHING_KEEP(actorHeadingConstantOrFrame17);
            framePrivateOrPlayerBase16 = Level23_83BFCField(actorHeadingConstantOrFrame17, int*, 0);
            Level23_83BFCField(actorHeadingConstantOrFrame17, signed char*, 0x48) = 1;
            Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x44) =
                (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x44);
            resultOrIntermediate2 = Level23_83BFCRandBetweenView1(0, 155);
            argumentOrIntermediate4 = actorHeadingConstantOrFrame17;
            argumentOrIntermediate5 = 128;
            fieldOrIntermediate3 = Level23_83BFCField(owner18, unsigned char*, 69);
            argumentOrCapture6 = 0;
            fieldOrIntermediate3 -= 35;
            Level23_83BFCKeep(fieldOrIntermediate3);
            fieldOrIntermediate3 += resultOrIntermediate2;
            Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 69) =
                fieldOrIntermediate3;
            Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x46) =
                (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x46);
            Level23_83BFCTurnMobyTowardPlayerView1(argumentOrIntermediate4, argumentOrIntermediate5,
                                                   argumentOrCapture6, 0);
            Level23_83BFCField(framePrivateOrPlayerBase16, int*, 8) = 0xFA;
            Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4) = 0xC8;
            Level23_83BFCField(framePrivateOrPlayerBase16, short*, 2) =
                (short)Level23_83BFCField(actorHeadingConstantOrFrame17, unsigned char*, 0x46);
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 2U;
            goto block_141;
        block_140:
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 0U;
        block_141:
            if (!Level23_83BFCData6C770View1)
                goto block_177;
            argumentOrIntermediate4 = owner18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrIntermediate4, "$5");
            argumentOrIntermediate5 = 0;
            resultOrIntermediate2 = 1;
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 73) = 0;
            Level23_83BFCField(privateRecord21, unsigned char*, 8) = resultOrIntermediate2;
            resultOrIntermediate2 = 350;
            Level23_83BFCField(privateRecord21, int*, 4) = 0;
            Level23_83BFCField(privateRecord21, int*, 0) = resultOrIntermediate2;
            __asm__ volatile(""
                             : "=r"(argumentOrIntermediate4)
                             : "0"(argumentOrIntermediate4), "r"(privateRecord21));
            Level23_83BFCField(argumentOrIntermediate4, unsigned char*, 72) = 0;
            goto block_176;
        case 6:
            resultOrIntermediate2 = Level23_83BFCCall55E84View1(owner18);
            argumentOrIntermediate4 = owner18;
            argumentOrIntermediate5 = 4;
            argumentOrCapture6 = 4;
            argumentOrCapture7 = 1;
            MATCHING_OBSERVE4_VOLATILE(argumentOrIntermediate4, argumentOrIntermediate5,
                                       argumentOrCapture6, argumentOrCapture7);
            framePrivateOrPlayerBase16 = resultOrIntermediate2;
            Level23_83BFCTurnMobyTowardPlayerView1(argumentOrIntermediate4, argumentOrIntermediate5,
                                                   argumentOrCapture6, argumentOrCapture7);
            if (Level23_83BFCApproximatePlanarDistanceView1(
                    owner18 + 0xC, (int)&Level23_83BFCData70328View1) >= 0x6A4) {
                goto block_149;
            }
            resultOrIntermediate2 = framePrivateOrPlayerBase16 - 11;
            Level23_83BFCKeep(resultOrIntermediate2);
            if ((unsigned int)resultOrIntermediate2 >= 12U) {
                goto block_149;
            }
            if ((unsigned int)(Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x50) -
                               2) < 2U) {
                goto block_148;
            }
            if (Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x50) == 5) {
                goto block_148;
            }
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 8) =
                (int)(Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 8) + 0x100);
        block_148:
            resultOrIntermediate2 = 0x10000400;
            fieldOrIntermediate3 = (int)&Level23_83BFCData70328View1 + 524;
            framePrivateOrPlayerBase16 = fieldOrIntermediate3 + 16;
            Level23_83BFCKeep(fieldOrIntermediate3);
            Level23_83BFCField(fieldOrIntermediate3, int*, 0) = resultOrIntermediate2;
            Level23_83BFCSubtractVectorView1(framePrivateOrPlayerBase16, fieldOrIntermediate3 - 524,
                                             owner18 + 12);
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 548) = 0;
            Level23_83BFCScaleVectorRatioQ15View1(
                framePrivateOrPlayerBase16,
                Level23_83BFCMeasureVectorLengthView1(framePrivateOrPlayerBase16, 0), 200);
        block_149:
            if (Level23_83BFCData6C770View1 == 0) {
                goto block_177;
            }
            argumentOrIntermediate4 = owner18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrIntermediate4, "$5");
            argumentOrIntermediate5 = 0;
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 0U;
            Level23_83BFCField(privateRecord21, int*, 4) = 0;
            Level23_83BFCField(privateRecord21, int*, 0) = 0x96;
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 0U;
            argumentOrIntermediate4 = owner18;
            goto block_176;
        case 7:
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x20C) = 0x10000002;
            if (Level23_83BFCData6C770View1 == 0) {
                goto block_177;
            }
            Level23_83BFCRefreshMobySpatialGridAndBasisView1(owner18, 4);
            Level23_83BFCCall369B8View1(owner18, 0x32);
            Level23_83BFCField(owner18, signed char*, 0x41) = 0;
            Level23_83BFCField(owner18, signed char*, 0x4C) = 0;
            Level23_83BFCField(owner18, signed char*, 0x4D) = 0;
            Level23_83BFCField(owner18, int*, 8) = 0;
            framePrivateOrPlayerBase16 = owner18 + 0x48;
            if (Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x280) < 0) {
                goto block_156;
            }
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 0x20U;
            Level23_83BFCCall3B7B4View1(framePrivateOrPlayerBase16, 1,
                                        (int)&Level23_83BFCData6D088View1);
            Level23_83BFCCall3B7B4View1(framePrivateOrPlayerBase16, 1,
                                        (int)&Level23_83BFCData6C7F8View1);
            if (Level23_83BFCData6C7B4View1 & 0x20) {
                goto block_155;
            }
            if (!(Level23_83BFCField((int)&Level23_83BFCData70300View1, unsigned char*,
                                     Level23_83BFCData6C58CView1) &
                  0x20)) {
                goto block_156;
            }
        block_155:
            Level23_83BFCField(((Level23_83BFCField(privateRecord21, int*, 0x10) * 0x58) +
                                Level23_83BFCData6C550View1),
                               signed char*, 0x48) = 3;
        block_156:
            Level23_83BFCDeleteMobyView1(owner18);
            return;
        case 30:
            framePrivateOrPlayerBase16 = Level23_83BFCField(owner18, int*, 0);
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x20C) = 0x10000002;
            spawnOrScalar19 = owner18 + 0xC;
            Level23_83BFCField(owner18, int*, 0x14) =
                (int)(Level23_83BFCField(owner18, int*, 0x14) +
                      Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4));
            Level23_83BFCCopyVectorView1(
                Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x10) + 0xC, spawnOrScalar19);
            Level23_83BFCField(Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x10),
                               unsigned char*, 0x46) =
                (unsigned char)Level23_83BFCField(owner18, unsigned char*, 0x46);
            Level23_83BFCDataSpawnParticleView1(
                1, 0xC, Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x10), (int*)5);
            temp_v1_12 = Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0xC);
            Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4) =
                (int)(Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4) - 0x10);
            if (Level23_83BFCField(owner18, int*, 0x14) >= temp_v1_12) {
                goto block_177;
            }
            Level23_83BFCField(owner18, int*, 0x14) = temp_v1_12;
            temp_v1_13 = Level23_83BFCField(framePrivateOrPlayerBase16, int*, 8) - 1;
            Level23_83BFCField(framePrivateOrPlayerBase16, int*, 8) = temp_v1_13;
            if (temp_v1_13 <= 0) {
                goto block_160;
            }
            Level23_83BFCField(framePrivateOrPlayerBase16, int*, 4) = (int)(temp_v1_13 * 0x32);
            return;
        block_160:
            temp_v0_10 = Level23_83BFCPlanarHeadingLookupView1(
                Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0) -
                    Level23_83BFCField(owner18, int*, 0xC),
                Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 4) -
                    Level23_83BFCField(owner18, int*, 0x10),
                0);
            temp_a2 = temp_v0_10 * 2;
            originalFrame.sp80 =
                (int)(Level23_83BFCField((int)&Level23_83BFCData65920View1, short*, temp_a2) *
                      0x177) >>
                0xA;
            originalFrame.sp84 =
                (int)(Level23_83BFCField((int)&Level23_83BFCData658A0View1, short*, temp_a2) *
                      0x177) >>
                0xA;
            originalFrame.sp88 = 0;
            Level23_83BFCAddVectorView1(&originalFrame.sp80, spawnOrScalar19, &originalFrame.sp80);
            Level23_83BFCCall13D44View1(&originalFrame.sp80, (temp_v0_10 + 0x80) & 0xFF, 0, 0);
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 0x1FU;
            return;
        case 31:
            framePrivateOrPlayerBase16 = Level23_83BFCField(owner18, int*, 0);
            Level23_83BFCField((int)&Level23_83BFCData70328View1, int*, 0x20C) = 0x10000002;
            if (Level23_83BFCData6E044View1 == 0xB) {
                goto block_177;
            }
            if (!(Level23_83BFCField(Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x10),
                                     unsigned char*, 0x48) &
                  0x80)) {
                goto block_177;
            }
            if (Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x14) < 0) {
                goto block_177;
            }
            if (Level23_83BFCCountTimerDownView1(framePrivateOrPlayerBase16, 4) == 0) {
                goto block_177;
            }
            var_v1 = Level23_83BFCField(framePrivateOrPlayerBase16, int*, 0x14);
            var_v0 = var_v1 * 2;
        block_166:
            Level23_83BFCField(
                (((((var_v0 + var_v1) * 4) - var_v1) * 8) + Level23_83BFCData6C550View1),
                signed char*, 0x48) = 3;
            return;
        case 8:
            Level23_83BFCTurnMobyTowardPlayerView1(owner18, 4, 4, 1);
            if (Level23_83BFCData6C770View1 == 0) {
                goto block_177;
            }
            if (Level23_83BFCField(owner18, unsigned char*, 0x49) != 9) {
                goto block_170;
            }
            Level23_83BFCField(privateRecord21, int*, 4) = 0;
        block_170:
            argumentOrIntermediate4 = owner18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrIntermediate4, "$5");
            argumentOrIntermediate5 = 5;
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 0U;
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 5U;
            argumentOrIntermediate4 = owner18;
            goto block_176;
        case 9:
            if (Level23_83BFCField(owner18, unsigned char*, 0x49) == 7) {
                goto block_174;
            }
            Level23_83BFCField(owner18, signed char*, 0x40) = 0x72;
            Level23_83BFCField(owner18, unsigned char*, 0x3C) = 9U;
            Level23_83BFCField(owner18, signed char*, 0x3D) = 9;
            Level23_83BFCField(owner18, unsigned char*, 0x3E) = 0U;
            Level23_83BFCField(owner18, signed char*, 0x3F) = 0;
            if (Level23_83BFCCountTimerDownView1(privateRecord21, 4) == 0) {
                goto block_174;
            }
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 7U;
        block_174:
            if (Level23_83BFCData6C770View1 == 0) {
                goto block_177;
            }
            Level23_83BFCCall13ACCView1(owner18, 0xD);
            resultOrIntermediate2 = Level23_83BFCCall2803CView1(
                0x17, 0xE7, Level23_83BFCData74368View1, Level23_83BFCData7436CView1,
                Level23_83BFCData74364View1, privateRecord21 + 12,
                Level23_83BFCField(privateRecord21, int*, 12));
            argumentOrIntermediate4 = owner18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrIntermediate4, "$5");
            argumentOrIntermediate5 = 1;
            resultOrIntermediate2 = (short)resultOrIntermediate2;
            Level23_83BFCField(privateRecord21, int*, 36) = resultOrIntermediate2;
            argumentOrIntermediate5 = 1;
            Level23_83BFCField(owner18, unsigned char*, 0x49) = 8U;
            Level23_83BFCField(privateRecord21, int*, 4) = 0;
            Level23_83BFCField(privateRecord21, unsigned char*, 8) = 1U;
            Level23_83BFCField(privateRecord21, int*, 0) = 0x12C;
            Level23_83BFCField(owner18, unsigned char*, 0x48) = 1U;
            argumentOrIntermediate4 = owner18;
        block_176:
            Level23_83BFCRequestMobyAnimationView1(argumentOrIntermediate4,
                                                   argumentOrIntermediate5);
        block_177:
            return;
        default:
            goto block_177;
    }
}
#undef Level23_83BFCField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80085038.
* AI generated; not human reviewed. All773 original instructions,81 selectors,
* one pad and3 table words require exact native/linked words and targets:858
* recorded words. Original16-byte selection object at80074920 is separately
* audited:0a000000060000000200000000000000. Its first4 asciz/alignment bytes
* are additional;the other12 bytes overlap the3 recorded table words.
* Frame80 (128 bytes) retains S0..S6/RA and SP20..5F storage. Saved S0/S2 scan,position,
* target and particle roles occupy disjoint phases. Initial S4 player and S5
* complete frame-selection pointer are initialized only on their own paths.
* Both heading3585C calls pass all6 original words,including stack1 and0;
* branch-local literal calls retain original outgoing stores before indexing.
* Signed complete /30 and /3 use ordinary C operations and only whole magic
* scalar inputs. No synthetic partialHI/LO. Signed halfword vector samples,
* byte predicates,helper reloads and random-coordinate additions remain exact.
* State2 preserves the shared byte reload287 and full zero predicate289.
* Original branch446 must enter401,not the equivalent later flag writer462.
* Its empty full-owner input retains the original shared entry without CPU
* words. Shared removal704 and vector614/624/633/634 entries retain order.
* Falsification:timer30 division uses the full signed old short;short60 yields
* target3. The record+12 A0 address and complete target remain distinct.
* Empty metadata consumes complete initialized words/addresses or clobbers
* dead words before fresh complete producers;zero CPU instructions. Known
* six-word3585C and void3BE70 views reuse matched EXE/header contracts.
* Compiler/filter/flags unchanged;no opcode asm,fixedFP,undefined saved inputs
* or overlapping live aliases. Physical units/fixed point,complete helper and
* caller chains,cadence beyond invocation,Rev1 mapping and synchronized runtime
* remain open. Confidence is binary identity after all gates. Next:human review
* and retail captures. Every native/linked word,target,data byte and full EXE/
* every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 16f642272a99e7e690ecd450dd5be52dc9045e3d3c89d52c56b46890158c8668 */
#define Level23_85038Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level23_85038Call1BA30View1() __asm__("func_8001BA30");
int Level23_85038Call35030View1() __asm__("func_80035030");
int Level23_85038TurnMobyTowardHeadingView1(void*, int, int, int, int,
                                            int) __asm__("func_8003585C");
int Level23_85038CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level23_85038Call35DDCView1() __asm__("func_80035DDC");
int Level23_85038Call35EE0View1() __asm__("func_80035EE0");
int Level23_85038RandBetweenView1() __asm__("func_8003636C");
int Level23_85038PlayMobySoundEventView1() __asm__("func_8003BABC");
void Level23_85038Call3BE70View1(int) __asm__("func_8003BE70");
int Level23_85038Call3BFC0View1() __asm__("func_8003BFC0");
int Level23_85038PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level23_85038CopyVectorView1() __asm__("func_8004F178");
int Level23_85038AddVectorView1() __asm__("func_8004F194");
int Level23_85038AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level23_85038DeleteMobyView1() __asm__("func_80055B18");
int Level23_85038RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level23_85038InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Level23_85038Data658A0View1 __asm__("D_800658A0");
extern int Level23_85038Data65920View1 __asm__("D_80065920");
extern int Level23_85038Data6C550View1 __asm__("D_8006C550");
extern int Level23_85038Data6C574View1 __asm__("D_8006C574");
extern int Level23_85038Data6C578View1 __asm__("D_8006C578");
extern int Level23_85038Data6C5C8View1 __asm__("D_8006C5C8");
extern int Level23_85038Data6C704View1 __asm__("D_8006C704");
extern int Level23_85038Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level23_85038Data6E020View1 __asm__("D_8006E020");
extern unsigned short Level23_85038Data6E040View1 __asm__("D_8006E040");
extern int Level23_85038Data6E1D4View1 __asm__("D_8006E1D4");
extern int Level23_85038Data6E1D8View1 __asm__("D_8006E1D8");
extern int Level23_85038Data70328View1 __asm__("D_80070328");
extern void* (*Level23_85038DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level23_85038DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
const int Level23_85038OriginalSelection[4] __asm__("D_level_23_80074920") = {10, 6, 2, 0};
void func_level_23_80085038(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        retainedInitialPlayerBase20 __asm__("$20");
    register int* retainedOriginalSelectionBase21 __asm__("$21");
    int temporaryWord14;
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord19 __asm__("$19"),
        retainedHeadingScanPositionOrTarget16 __asm__("$16"),
        retainedScanRecordOrParticleIndex18 __asm__("$18"),
        retainedOriginalRemovalFlag22 __asm__("$22");
    struct {
        int words[16];
    } originalFrame;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord15;
    register int temporaryWord7 __asm__("$2");
    int temporaryWord9;
    int temporaryWord1;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord8;
    int temporaryWord10;
    int temp_s3_2;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord6;
    ownerRecord17 = ownerParameter;
    MATCHING_KEEP(ownerRecord17);
    temporaryWord1 = Level23_85038Field(ownerRecord17, unsigned char*, 0x48);
    privateRecord19 = Level23_85038Field(ownerRecord17, void**, 0);
    retainedOriginalRemovalFlag22 = 0;
    if ((temporaryWord1 != 0) && ((unsigned int)(temporaryWord1 - 4) >= 2U) &&
        (Level23_85038Field(ownerRecord17, int*, 0x18) & 0x20000)) {
        Level23_85038Field(ownerRecord17, int*, 0x18) = 0;
        Level23_85038Field(privateRecord19, int*, 8) = 0x15E;
        rawWord3 = Level23_85038Field(ownerRecord17, unsigned char*, 72);
        MATCHING_KEEP(rawWord3);
        rawWord2 = rawWord3 - 2;
        rawWord2 = (unsigned int)rawWord2 < 2U;
        if (rawWord2)
            goto selectOriginalTimer200;
        rawWord3 &= 255;
        rawWord2 = 1;
        if (rawWord3 != rawWord2)
            goto selectOriginalTimer150;
        rawWord2 = Level23_85038Field(privateRecord19, unsigned char*, 13);
        rawWord2 = (unsigned int)rawWord2 < 3U;
        if (rawWord2)
            goto selectOriginalTimer150;
    selectOriginalTimer200:
        rawWord2 = 200;
        goto storeOriginalTimer41;
    selectOriginalTimer150:
        rawWord2 = 150;
    storeOriginalTimer41:
        Level23_85038Field(privateRecord19, int*, 4) = rawWord2;
        __asm__ volatile("" ::: "$6", "memory");
        argumentWord6 = 0;
        Level23_85038Field(ownerRecord17, unsigned char*, 0x48) = 4U;
        retainedInitialPlayerBase20 = (int)&Level23_85038Data70328View1;
        temporaryWord3 = Level23_85038PlanarHeadingLookupView1(
            Level23_85038Field(ownerRecord17, int*, 0xC) -
                Level23_85038Field(retainedInitialPlayerBase20, int*, 0),
            Level23_85038Field(ownerRecord17, int*, 0x10) -
                Level23_85038Field(retainedInitialPlayerBase20, int*, 4),
            argumentWord6);
        if (({
                rawWord2 = Level23_85038AbsoluteByteAngleDeltaView1(
                    temporaryWord3,
                    Level23_85038Field(retainedInitialPlayerBase20, unsigned char*, 14));
                argumentWord6 = 6;
                rawWord2;
            }) < 24) {
            Level23_85038Field(ownerRecord17, unsigned char*, 0x46) =
                (unsigned char)Level23_85038Field(retainedInitialPlayerBase20, unsigned char*, 0xE);
            if (Level23_85038Data6C5C8View1 == 1) {
                retainedScanRecordOrParticleIndex18 = Level23_85038Data6C550View1;
                rawWord2 = Level23_85038Data6C704View1;
                __asm__ volatile("" ::: "$6", "memory");
                argumentWord6 = (int)&Level23_85038OriginalSelection[0];
                MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                rawWord3 = Level23_85038Field(argumentWord6, int*, 0);
                argumentWord4 = Level23_85038Field(argumentWord6, int*, 4);
                argumentWord5 = Level23_85038Field(argumentWord6, int*, 8);
                originalFrame.words[0] = rawWord3;
                __asm__(""
                        : "=r"(argumentWord5)
                        : "0"(argumentWord5), "r"(rawWord3), "r"(argumentWord4)
                        : "memory");
                originalFrame.words[1] = argumentWord4;
                originalFrame.words[2] = argumentWord5;
                __asm__ volatile("" ::: "$21", "memory");
                retainedOriginalSelectionBase21 = &originalFrame.words[0];
                if ((unsigned int)retainedScanRecordOrParticleIndex18 < (unsigned int)rawWord2) {
                    retainedHeadingScanPositionOrTarget16 =
                        retainedScanRecordOrParticleIndex18 + 0x10;
                loop_11:
                    if ((Level23_85038Field(retainedHeadingScanPositionOrTarget16, short*, 0x26) !=
                         0x1E) ||
                        (Level23_85038Field(retainedHeadingScanPositionOrTarget16, unsigned char*,
                                            0x3C) == 0) ||
                        (Level23_85038Field(retainedHeadingScanPositionOrTarget16, unsigned char*,
                                            0x38) &
                         0x80) ||
                        (Level23_85038AbsoluteByteAngleDeltaView1(
                             Level23_85038PlanarHeadingLookupView1(
                                 Level23_85038Field(retainedHeadingScanPositionOrTarget16, int*,
                                                    -4) -
                                     Level23_85038Field(retainedInitialPlayerBase20, int*, 0),
                                 Level23_85038Field(retainedHeadingScanPositionOrTarget16, int*,
                                                    0) -
                                     Level23_85038Field(retainedInitialPlayerBase20, int*, 4),
                                 0),
                             Level23_85038Field(retainedInitialPlayerBase20, unsigned char*,
                                                0xE)) >=
                         retainedOriginalSelectionBase21[Level23_85038Data6C7C4View1])) {
                        rawWord2 = Level23_85038Data6C704View1;
                        MATCHING_KEEP_CLOBBER(retainedScanRecordOrParticleIndex18, "memory");
                        retainedScanRecordOrParticleIndex18 += 88;
                        rawWord2 = (unsigned int)retainedScanRecordOrParticleIndex18 <
                                   (unsigned int)rawWord2;
                        retainedHeadingScanPositionOrTarget16 += 88;
                        if (!rawWord2) {
                        } else {
                            goto loop_11;
                        }
                    } else {
                        rawWord2 = Level23_85038PlanarHeadingLookupView1(
                            Level23_85038Field(retainedScanRecordOrParticleIndex18, int*, 12) -
                                Level23_85038Field(ownerRecord17, int*, 12),
                            Level23_85038Field(retainedScanRecordOrParticleIndex18, int*, 16) -
                                Level23_85038Field(ownerRecord17, int*, 16),
                            0);
                        Level23_85038TurnMobyTowardHeadingView1(
                            (int)ownerRecord17, rawWord2,
                            retainedOriginalSelectionBase21[Level23_85038Data6C7C4View1], 0, 1, 0);
                        goto continueOriginalHeading158;
                    }
                }
            }
        } else {
            argumentWord4 = (int)ownerRecord17;
            argumentWord7 = 0;
            __asm__("" : "=r"(argumentWord7) : "0"(argumentWord7), "r"(argumentWord4) : "memory");
            Level23_85038Field(ownerRecord17, unsigned char*, 70) = temporaryWord3;
            argumentWord5 = Level23_85038Field(retainedInitialPlayerBase20, unsigned char*, 14);
            Level23_85038TurnMobyTowardHeadingView1(argumentWord4, argumentWord5, argumentWord6,
                                                    argumentWord7, 1, 0);
        }
    continueOriginalHeading158:
        argumentWord4 = (int)ownerRecord17;
        argumentWord5 = 3;
        argumentWord6 = 0;
        rawWord3 = Level23_85038Field(ownerRecord17, unsigned char*, 70);
        __asm__(""
                : "=r"(argumentWord6)
                : "0"(argumentWord6), "r"(argumentWord4), "r"(argumentWord5)
                : "memory");
        rawWord2 = 300;
        Level23_85038Field(privateRecord19, short*, 0) = rawWord2;
        Level23_85038Field(privateRecord19, short*, 2) = rawWord3;
        Level23_85038PlayMobySoundEventView1(argumentWord4, argumentWord5, argumentWord6);
    }
    temporaryWord8 = Level23_85038Field(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord8) {
        case 0x1:
            Level23_85038Field(ownerRecord17, unsigned char*, 0x45) =
                (unsigned char)(Level23_85038Field(ownerRecord17, unsigned char*, 0x45) -
                                ((4 - Level23_85038Field(privateRecord19, unsigned char*, 0xD)) *
                                 2));
            Level23_85038Field(ownerRecord17, int*, 0x14) =
                (int)(Level23_85038Field(ownerRecord17, int*, 0x14) - 0xE1);
            temporaryWord15 = 1;
            if (Level23_85038Field(privateRecord19, unsigned char*, 0xD) == 0) {
                temporaryWord15 = 4;
            }
            if (Level23_85038Call35030View1(ownerRecord17, privateRecord19 + 8,
                                            Level23_85038Field(privateRecord19, short*, 2),
                                            privateRecord19 + 4, temporaryWord15, 0xC, 0x200,
                                            0x23) == 3) {
                Level23_85038PlayMobySoundEventView1(ownerRecord17, 3, 0);
                temporaryWord4 = Level23_85038Field(privateRecord19, unsigned char*, 0xD) + 1;
                temporaryWord9 = temporaryWord4 & 0xFF;
                Level23_85038Field(privateRecord19, unsigned char*, 0xD) = temporaryWord4;
                if (temporaryWord9 >= 4U) {
                    Level23_85038Field(ownerRecord17, unsigned char*, 0x48) = 2U;
                    Level23_85038Field(ownerRecord17, int*, 0x14) =
                        (int)(Level23_85038Field(ownerRecord17, int*, 0x14) + 0xE1);
                    Level23_85038Field(privateRecord19, short*, 0) = 0x4B;
                    Level23_85038Field(privateRecord19, unsigned char*, 0xE) = 0U;
                } else {
                    if (temporaryWord9 == 1) {
                        Level23_85038Field(privateRecord19, int*, 8) =
                            (int)(Level23_85038Field(privateRecord19, int*, 8) - 0xA);
                    }
                    Level23_85038Field(privateRecord19, int*, 4) =
                        (int)((4 - Level23_85038Field(privateRecord19, unsigned char*, 0xD)) *
                              0x32);
                    goto block_32;
                }
            } else {
            block_32:
                Level23_85038Field(ownerRecord17, int*, 0x14) =
                    (int)(Level23_85038Field(ownerRecord17, int*, 0x14) + 0xE1);
            }
            goto checkOriginalCommonRemoval527;
        case 0x2:
            temporaryWord11 = Level23_85038Field(privateRecord19, short*, 0);
            if (temporaryWord11 < 30) {
                temporaryWord14 = Level23_85038Field(privateRecord19, unsigned char*, 14);
                if (temporaryWord14 == 0) {
                    Level23_85038Field(ownerRecord17, unsigned char*, 69) += 1;
                    Level23_85038Call35EE0View1(
                        ownerRecord17,
                        (Level23_85038Field(ownerRecord17, unsigned char*, 70) + 128) & 255, 10, 0,
                        0, 1024);
                    goto reloadOriginalStateByte287;
                }
                goto convertOriginalStateByte289;
            }
            if (temporaryWord11 < 45) {
                temporaryWord14 = Level23_85038Field(privateRecord19, unsigned char*, 14);
                if (temporaryWord14 == 0) {
                    Level23_85038Field(ownerRecord17, unsigned char*, 69) -= 1;
                    Level23_85038Call35DDCView1(ownerRecord17, 10, 0, 0, 1024);
                reloadOriginalStateByte287:
                    temporaryWord14 = Level23_85038Field(privateRecord19, unsigned char*, 14);
                }
            convertOriginalStateByte289:
                temporaryWord14 = temporaryWord14 == 0;
                Level23_85038Field(privateRecord19, unsigned char*, 14) = temporaryWord14;
            } else {
                argumentWord4 = (int)ownerRecord17;
                if (temporaryWord11 < 60) {
                    argumentWord5 = 10;
                    argumentWord6 = 0;
                    rawWord2 = Level23_85038Field(ownerRecord17, unsigned char*, 69);
                    argumentWord7 = 0;
                    rawWord2 -= 1;
                } else {
                    argumentWord5 = 20;
                    argumentWord6 = 0;
                    rawWord2 = Level23_85038Field(ownerRecord17, unsigned char*, 69);
                    argumentWord7 = 0;
                    rawWord2 -= 2;
                }
                Level23_85038Field(ownerRecord17, unsigned char*, 69) = rawWord2;
                Level23_85038Call35DDCView1(argumentWord4, argumentWord5, argumentWord6,
                                            argumentWord7, 1024);
            }
            if ((Level23_85038CountTimerDownView1(privateRecord19, 2) != 0) ||
                ((unsigned char)Level23_85038Field(ownerRecord17, unsigned char*, 0x45) < 4U)) {
                Level23_85038Field(ownerRecord17, unsigned char*, 0x48) = 3U;
                Level23_85038Field(privateRecord19, short*, 0) = 0x96;
            }
            goto checkOriginalCommonRemoval527;
        case 0x3: {
            int signedDivision30Magic = (int)0x88888889;
            rawWord3 = Level23_85038Field(privateRecord19, unsigned short*, 0);
            __asm__("" : "=r"(privateRecord19) : "0"(privateRecord19), "r"(signedDivision30Magic));
            rawWord3 = (unsigned int)rawWord3 << 16;
            rawWord2 = rawWord3 >> 16;
            rawWord2 = rawWord2 / 30;
            MATCHING_KEEP(rawWord2);
            retainedHeadingScanPositionOrTarget16 = (short)rawWord2 + 1;
        }
            if (retainedHeadingScanPositionOrTarget16 !=
                Level23_85038Field(privateRecord19, unsigned char*, 0xC)) {
                Level23_85038PlayMobySoundEventView1(ownerRecord17, 2, 0);
                Level23_85038Field(privateRecord19, unsigned char*, 0xC) =
                    retainedHeadingScanPositionOrTarget16;
            }
            argumentWord5 = Level23_85038DataSpawnMobyView1(0x104, ownerRecord17);
            if (argumentWord5 != 0) {
                Level23_85038Field(argumentWord5, signed char*, 0x49) = 1;
                Level23_85038Field(argumentWord5, signed char*, 0x4F) = 0x1A;
                Level23_85038Field(argumentWord5, unsigned char*, 0x4A) = 0xFF;
                Level23_85038Field(argumentWord5, unsigned char*, 0x3C) =
                    retainedHeadingScanPositionOrTarget16;
                Level23_85038Field(argumentWord5, signed char*, 0x4C) = 0x3F;
                Level23_85038Field(argumentWord5, int*, 0x14) =
                    (int)(Level23_85038Field(argumentWord5, int*, 0x14) + 0x64);
                temporaryWord7 = (unsigned short)Level23_85038Data6E040View1 >> 4;
                Level23_85038Field(argumentWord5, unsigned char*, 0x46) =
                    (unsigned char)temporaryWord7;
                rawWord2 = (temporaryWord7 & 255) * 2;
                rawWord2 = Level23_85038Field((int)&Level23_85038Data65920View1, short*, rawWord2);
                __asm__ volatile("" ::: "$4", "memory");
                argumentWord4 = argumentWord5 + 12;
                originalFrame.words[0] = (rawWord2 * 75) >> 10;
                rawWord2 = Level23_85038Field(argumentWord5, unsigned char*, 70);
                MATCHING_KEEP_CLOBBER(argumentWord4, "$6");
                argumentWord6 = argumentWord4;
                rawWord2 *= 2;
                rawWord2 = Level23_85038Field((int)&Level23_85038Data658A0View1, short*, rawWord2);
                __asm__(""
                        : "=r"(argumentWord6)
                        : "0"(argumentWord6), "r"(argumentWord4)
                        : "$5", "memory");
                argumentWord5 = (int)&originalFrame.words[0];
                originalFrame.words[2] = 0;
                originalFrame.words[1] = (rawWord2 * 75) >> 10;
                Level23_85038AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            }
            if (Level23_85038CountTimerDownView1(privateRecord19, 2) != 0) {
                case 0x6:
                enterOriginalRemovalFlag401:
                    MATCHING_OBSERVE_VOLATILE(ownerRecord17);
                    retainedOriginalRemovalFlag22 = 1;
            }
            goto checkOriginalCommonRemoval527;
        case 0x4:
            retainedHeadingScanPositionOrTarget16 = 0;
            Level23_85038Field(ownerRecord17, unsigned char*, 0x45) =
                (unsigned char)(Level23_85038Field(ownerRecord17, unsigned char*, 0x45) - 8);
            if ((Level23_85038CountTimerDownView1(privateRecord19, 2) != 0) ||
                (Level23_85038Call35030View1(ownerRecord17, privateRecord19 + 8,
                                             Level23_85038Field(privateRecord19, short*, 2),
                                             privateRecord19 + 4, 0, 0xA, 0x200, 0x23) == 3) ||
                (retainedHeadingScanPositionOrTarget16 = Level23_85038Call1BA30View1(
                     ownerRecord17 + 0xC, 0x100, 1, 0, 0x40000, ownerRecord17),
                 (retainedHeadingScanPositionOrTarget16 != 0))) {
                retainedOriginalRemovalFlag22 = 1;
                if (retainedHeadingScanPositionOrTarget16 != 0) {
                    retainedOriginalRemovalFlag22 = 2;
                }
            }
            goto checkOriginalCommonRemoval527;
        case 0x7:
            Level23_85038Field(ownerRecord17, unsigned char*, 0x45) =
                (unsigned char)(Level23_85038Field(ownerRecord17, unsigned char*, 0x45) - 8);
            if (Level23_85038CountTimerDownView1(privateRecord19, 2) == 0) {
                if (Level23_85038Call35030View1(ownerRecord17, privateRecord19 + 8,
                                                Level23_85038Field(privateRecord19, short*, 2),
                                                privateRecord19 + 4, 0, 0xA, 0x200, 0x23) == 3) {
                    retainedOriginalRemovalFlag22 = 1;
                }
            } else {
                goto enterOriginalRemovalFlag401;
            }
            goto checkOriginalCommonRemoval527;
        case 0x5:
            retainedScanRecordOrParticleIndex18 = Level23_85038Field(ownerRecord17, void**, 0);
            Level23_85038Field(ownerRecord17, signed char*, 0x41) = 0;
            Level23_85038Field(ownerRecord17, signed char*, 0x4C) = 0;
            Level23_85038Field(ownerRecord17, signed char*, 0x4D) = 0;
            rawWord2 = Level23_85038RandBetweenView1(0, 3072);
            argumentWord4 = 0;
            rawWord3 = Level23_85038Field(ownerRecord17, int*, 12);
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$5", "memory");
            argumentWord5 = 3072;
            rawWord3 -= 1536;
            rawWord3 += rawWord2;
            originalFrame.words[0] = rawWord3;
            rawWord2 = Level23_85038RandBetweenView1(argumentWord4, argumentWord5);
            argumentWord4 = 100;
            rawWord3 = Level23_85038Field(ownerRecord17, int*, 16);
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$5", "memory");
            argumentWord5 = 1024;
            rawWord3 -= 1536;
            rawWord3 += rawWord2;
            originalFrame.words[1] = rawWord3;
            originalFrame.words[2] = Level23_85038Field(ownerRecord17, int*, 0x14) +
                                     Level23_85038RandBetweenView1(argumentWord4, argumentWord5);
            Level23_85038DataSpawnParticleView1(2, 0x42, &originalFrame.words[0], (int*)1);
            argumentWord4 = 1;
            argumentWord5 = 13;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$16");
            retainedHeadingScanPositionOrTarget16 = (int)ownerRecord17 + 12;
            originalFrame.words[0] = 0;
            originalFrame.words[1] = 0;
            originalFrame.words[2] = 0;
            temporaryWord2 = Level23_85038DataSpawnParticleView1(
                argumentWord4, argumentWord5, retainedHeadingScanPositionOrTarget16,
                &originalFrame.words[0]);
            if (temporaryWord2 != 0) {
                Level23_85038Field(temporaryWord2, signed char*, 0xA) = 0x32;
            }
            Level23_85038AddVectorView1(retainedHeadingScanPositionOrTarget16,
                                        retainedHeadingScanPositionOrTarget16,
                                        retainedScanRecordOrParticleIndex18 + 4);
            temporaryWord12 =
                Level23_85038Field(retainedScanRecordOrParticleIndex18, int*, 0x10) + 0x14;
            Level23_85038Field(retainedScanRecordOrParticleIndex18, int*, 0x10) = temporaryWord12;
            Level23_85038Field(ownerRecord17, int*, 0x14) =
                (int)(Level23_85038Field(ownerRecord17, int*, 0x14) - temporaryWord12);
            if (Level23_85038CountTimerDownView1(retainedScanRecordOrParticleIndex18, 4) != 0) {
                goto removeOriginalOwner704;
            }
            return;
        case 0:
        default:
            goto checkOriginalCommonRemoval527;
        case 0x50:
            goto removeOriginalOwner704;
    }
checkOriginalCommonRemoval527:
    if (retainedOriginalRemovalFlag22 != 0) {
        if (Level23_85038Call3BFC0View1(ownerRecord17,
                                        Level23_85038Field(privateRecord19, int*, 0x10)) != 0) {
            Level23_85038Call3BE70View1(Level23_85038Field(privateRecord19, int*, 0x10));
        }
        Level23_85038Field(privateRecord19, int*, 0x10) = -1;
        Level23_85038PlayMobySoundEventView1(ownerRecord17, 1, 0);
        if (Level23_85038AbsoluteByteAngleDeltaView1(
                (int)(Level23_85038Data6E040View1 << 16) >> 20,
                Level23_85038PlanarHeadingLookupView1(
                    Level23_85038Field(ownerRecord17, int*, 0xC) -
                        Level23_85038Field((int)&Level23_85038Data6E020View1, int*, 0),
                    Level23_85038Field(ownerRecord17, int*, 0x10) -
                        Level23_85038Field((int)&Level23_85038Data6E020View1, int*, 4),
                    0)) < 0xA) {
            Level23_85038Data6E1D8View1 = 0x14;
            Level23_85038Data6E1D4View1 = 0x1000;
        }
        argumentWord6 = 0;
        MATCHING_KEEP_CLOBBER(argumentWord6, "$18");
        retainedScanRecordOrParticleIndex18 = 0;
        __asm__(""
                : "=r"(retainedScanRecordOrParticleIndex18)
                : "0"(retainedScanRecordOrParticleIndex18), "r"(argumentWord6));
        Level23_85038Field(ownerRecord17, unsigned char*, 0x46) =
            Level23_85038PlanarHeadingLookupView1(
                Level23_85038Field((int)&Level23_85038Data6E020View1, int*, 0) -
                    Level23_85038Field(ownerRecord17, int*, 0xC),
                Level23_85038Field((int)&Level23_85038Data6E020View1, int*, 4) -
                    Level23_85038Field(ownerRecord17, int*, 0x10),
                argumentWord6);
        Level23_85038Field(ownerRecord17, signed char*, 0x49) = 2;
        Level23_85038DataSpawnMobyView1(0x3F7, ownerRecord17);
    loop_72:
        if ((Level23_85038Data6C578View1 - Level23_85038Data6C574View1) >= 0x15) {
            temporaryWord5 = Level23_85038DataSpawnMobyView1(0x50, ownerRecord17);
            if (temporaryWord5 != 0) {
                temp_s3_2 = Level23_85038Field(temporaryWord5, void**, 0);
                Level23_85038Field(temporaryWord5, signed char*, 0x48) = 5;
                Level23_85038Field(temporaryWord5, signed char*, 0x41) = 0;
                Level23_85038Field(temporaryWord5, signed char*, 0x4C) = 0;
                Level23_85038Field(temporaryWord5, signed char*, 0x4D) = 0;
                Level23_85038Field(temporaryWord5, int*, 8) = 0;
                if (!retainedScanRecordOrParticleIndex18)
                    goto produceOriginalFirstVector614;
                argumentWord4 = 0;
                if (retainedScanRecordOrParticleIndex18 == 1)
                    goto produceOriginalSecondVector624;
                temporaryWord13 = temp_s3_2 + 4;
                goto updateOriginalSpawnedPosition634;
            produceOriginalFirstVector614:
                MATCHING_KEEP_CLOBBER(retainedScanRecordOrParticleIndex18, "$4");
                originalFrame.words[4] = Level23_85038RandBetweenView1(0, 100) - 50;
                originalFrame.words[5] = Level23_85038RandBetweenView1(90, 150);
                goto produceOriginalVectorAddress633;
            produceOriginalSecondVector624:
                originalFrame.words[4] = Level23_85038RandBetweenView1(argumentWord4, 100) - 50;
                originalFrame.words[5] = -Level23_85038RandBetweenView1(90, 150);
            produceOriginalVectorAddress633:
                temporaryWord13 = temp_s3_2 + 4;
            updateOriginalSpawnedPosition634:
                originalFrame.words[6] = 0x190;
                Level23_85038Field(temporaryWord5, int*, 0xC) =
                    (int)(Level23_85038Field(temporaryWord5, int*, 0xC) +
                          (originalFrame.words[4] * 3));
                Level23_85038Field(temporaryWord5, int*, 0x10) =
                    (int)(Level23_85038Field(temporaryWord5, int*, 0x10) +
                          (originalFrame.words[5] * 3));
                Level23_85038CopyVectorView1(temporaryWord13, &originalFrame.words[4]);
                Level23_85038Field(temp_s3_2, int*, 0x10) = 0;
                Level23_85038Field(temp_s3_2, int*, 0) = 0xC8;
            }
            retainedScanRecordOrParticleIndex18 += 1;
            if (retainedScanRecordOrParticleIndex18 < 2) {
                goto loop_72;
            }
        }
        retainedHeadingScanPositionOrTarget16 =
            Level23_85038Field(ownerRecord17, unsigned char*, 0x46);
        retainedScanRecordOrParticleIndex18 = 0;
        Level23_85038Field(ownerRecord17, unsigned char*, 0x46) = 0U;
    loop_83:
        if ((Level23_85038Data6C578View1 - Level23_85038Data6C574View1) >= 0x15) {
            temporaryWord6 = Level23_85038DataSpawnMobyView1(0x54, ownerRecord17);
            if (temporaryWord6 != 0) {
                Level23_85038Field(temporaryWord6, signed char*, 0x4F) = 0x20;
                Level23_85038Field(temporaryWord6, signed char*, 0x4C) = 0x3F;
                Level23_85038Field(temporaryWord6, unsigned char*, 0x4A) = 0xFF;
                Level23_85038Field(temporaryWord6, signed char*, 0x3C) =
                    (signed char)(retainedScanRecordOrParticleIndex18 % 3);
                Level23_85038Field(Level23_85038Field(temporaryWord6, void**, 0), short*, 0xC) =
                    0xC8;
            }
            retainedScanRecordOrParticleIndex18 += 1;
            Level23_85038Field(ownerRecord17, unsigned char*, 0x46) =
                (unsigned char)(Level23_85038Field(ownerRecord17, unsigned char*, 0x46) + 0x40);
            if (retainedScanRecordOrParticleIndex18 < 4) {
                goto loop_83;
            }
        }
        Level23_85038Field(ownerRecord17, unsigned char*, 0x46) =
            retainedHeadingScanPositionOrTarget16;
    removeOriginalOwner704:
        Level23_85038DeleteMobyView1(ownerRecord17);
        return;
    }
    MATCHING_BARRIER_VOLATILE("$22");
    if (Level23_85038Call3BFC0View1(ownerRecord17,
                                    Level23_85038Field(privateRecord19, int*, 0x10)) == 0) {
        argumentWord4 = (int)ownerRecord17;
        __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$2", "$5");
        Level23_85038Field(privateRecord19, int*, 0x10) =
            Level23_85038PlayMobySoundEventView1(argumentWord4, 0, 4);
    }
    if (Level23_85038Field(privateRecord19, unsigned char*, 0xF) == 0) {
        temporaryWord10 = Level23_85038Field(ownerRecord17, unsigned char*, 0x48);
        retainedScanRecordOrParticleIndex18 = 0;
        if ((temporaryWord10 == 4) || (temporaryWord10 == 1)) {
            retainedScanRecordOrParticleIndex18 = 1;
        }
        if ((retainedScanRecordOrParticleIndex18 == 0) ||
            ((unsigned int)(Level23_85038Field(ownerRecord17, unsigned char*, 0x45) - 0x65) >=
             0x4FU)) {
            Level23_85038RefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
            Level23_85038InterpolateMobyVertexView1(ownerRecord17, 0, &originalFrame.words[8]);
            originalFrame.words[12] = 0;
            originalFrame.words[13] = 0;
            originalFrame.words[14] = 0x32;
            Level23_85038DataSpawnParticleView1(1, 0xD, &originalFrame.words[8],
                                                &originalFrame.words[12]);
            if (retainedScanRecordOrParticleIndex18 != 0) {
                Level23_85038Field(privateRecord19, unsigned char*, 0xF) = 0U;
                return;
            }
            Level23_85038Field(privateRecord19, unsigned char*, 0xF) = 3U;
            return;
        }
    } else {
        Level23_85038CountTimerDownView1(privateRecord19 + 0xF, 1);
        return;
    }
    return;
}
#undef Level23_85038Field

/* AI-generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 80085C4C..80085EEC,169 words. Rev1 raw83 provides source-local routes;
 * every Rev0 access width, callback order and post-callee read is retained.
 * Raw units, private/linked producers, helper outputs and cadence open.
 * Test: independent original words and every complete retail hash. */
extern Moby* func_80019138(Vector3D*, int, int, int, int, int);
extern int func_8001C288(Vector3D*, int, int);
extern int func_8001A310(Vector3D*, int, int, int);
extern int func_8003BABC(Moby*, int, int);
extern void func_80034F40(Moby*, int);
void func_level_23_80085C4C(Moby* argument) {
    Vector3D oldPosition;
    int reserved24;
    register Moby* moby __asm__("$17") = argument;
    register int* tag __asm__("$19");
    register Moby* candidate __asm__("$16");
    register Vector3D* position __asm__("$18");
    unsigned char* particle;
    tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
        case 1:
            oldPosition.x = 0;
            oldPosition.y = 0;
            oldPosition.z = 2;
            if (moby->state == 1)
                oldPosition.z = 1;
            /* Computed-value ties emit no code; they preserve original argument
         * preparation and the order of independent fresh reads. */
            {
                register int kind __asm__("$4") = 1;
                MATCHING_KEEP(kind);
                {
                    register int selector __asm__("$5") = 60;
                    MATCHING_KEEP(selector);
                    position = &moby->position;
                    particle =
                        (unsigned char*)SpawnParticle(kind, selector, position, &oldPosition);
                }
            }
            if (particle)
                particle[10] = 155;
            func_8004F178(&oldPosition, position);
            func_80035DDC(moby, 300, 0, 0, 1024);
            moby->position.z += tag[2];
            candidate = 0;
            tag[2] -= 12;
            tag[0] -= 1;
            if (tag[0] > 0) {
                if (moby->state == 0 && func_8001C288(position, 512, 7))
                    goto impact;
                candidate = func_80019138(position, 300, 1, 0, 0, 0);
                if (!candidate)
                    goto fallback;
            }
        impact:
            func_8003BABC(moby, 0, 0);
            if (moby->state == 1) {
                register int height __asm__("$18") = func_8001A310(&moby->position, 2048, 1, 0);
                if (!height)
                    goto cleanup;
                candidate = SpawnMoby(404, moby);
                MATCHING_KEEP(candidate);
                if (!candidate)
                    goto cleanup;
                {
                    register Moby* animationOwner __asm__("$4") = candidate;
                    register int animationId __asm__("$5") = 4;
                    MATCHING_KEEP2(animationOwner, animationId);
                    candidate->lowDrawDistance = 32;
                    ((unsigned char*)candidate)[0x4A] = 255;
                    candidate->position.z = height;
                    {
                        register int* childTag __asm__("$18");
                        register int lane __asm__("$3") = ((unsigned char*)moby)[0x46];
                        MATCHING_KEEP(lane);
                        childTag = candidate->mobyTag;
                        candidate->state = 4;
                        ((unsigned char*)candidate)[0x46] = lane;
                        func_80034F40(animationOwner, animationId);
                        candidate->size = 96;
                        if (tag[5]) {
                            int* linked = *(int**)tag[5];
                            childTag[3] = linked[7];
                            childTag[2] = linked[8];
                        }
                    }
                }
            } else if (candidate) {
                int height = func_8001A310(&moby->position, 2048, 1, 0);
                if (height)
                    moby->position.z = height;
                candidate = SpawnMoby(1000, moby);
                MATCHING_KEEP(candidate);
                if (candidate) {
                    unsigned char* childTag = candidate->mobyTag;
                    candidate->state = 1;
                    *(short*)(childTag + 2) = 400;
                    *(short*)(childTag + 20) = 30;
                    *(short*)(childTag + 22) = 80;
                }
            }
        cleanup:
            func_80055B18(moby);
            break;
        fallback:
            {
                int distance;
                /* Retain the dead null candidate while forgetting its compile-time
             * constant, so retail passes an independent zero argument. */
                MATCHING_KEEP(candidate);
                distance = func_8004F334(&oldPosition, position);
                ((unsigned char*)moby)[0x45] =
                    func_8004E880(distance, moby->position.z - oldPosition.z, 0);
            }
            break;
    }
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
void func_level_23_80085EF0(Moby* argument) {
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

extern int D_8006C770;
void func_level_23_8008628C(Moby* moby) {
    if (moby->damageFlags & 0x160000) {
        moby->damageFlags = 0;
        if ((moby->state != 1) || ((unsigned char)moby->animationState.frame >= 4U)) {
            moby->state = 1;
            D_8006C770 = 0;
            moby->animationProgress = 0x72;
            moby->animationState.nextId = 1;
            moby->animationState.nextFrame = 0;
            func_80035734(moby);
        }
    } else if ((moby->state == 1) && (D_8006C770 != 0)) {
        moby->state = 0;
        func_80034F40(moby, 0);
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/level_23/moby/func_level_23_80086338.s SHA256 daa7bb8cca440ad24f1ab681bd044142181ac9f8f6927c8f510352ec4ac92d9f. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level23_86338Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level23_86338_D_8006C550 __asm__("D_8006C550");
extern unsigned char Level23_86338_D_80070300[40] __asm__("D_80070300");
extern Spyro Level23_86338_D_80070328 __asm__("D_80070328");
void Level23_86338_func_80013AE4(Vector3D*, Vector3D*) __asm__("func_80013AE4");
void Level23_86338_func_80013B7C(int) __asm__("func_80013B7C");
extern void Level23_86338_func_80021ED8(int, int, int) __asm__("func_80021ED8");
extern int Level23_86338_func_80021F3C(int) __asm__("func_80021F3C");
extern void Level23_86338_func_80021F8C(int, char, int) __asm__("func_80021F8C");
void Level23_86338_func_80027A60(HudEntry*) __asm__("func_80027A60");
void Level23_86338_func_80027EE4(HudEntry*) __asm__("func_80027EE4");
int Level23_86338_func_8002803C(int, int, void*, void*, void*, int*, int) __asm__("func_8002803C");
int Level23_86338_func_80029AA0(HudEntry*) __asm__("func_80029AA0");
void Level23_86338RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level23_86338CountTimerDown(void*, int) __asm__("func_800359A4");
void Level23_86338_func_8003B7B4(void* addr, int len, Savepoint* save) __asm__("func_8003B7B4");
int Level23_86338_func_8003BB10(Moby*, int, int) __asm__("func_8003BB10");

unsigned char Level23_86338SetMobyAnimation(Moby*, unsigned char) __asm__("func_80034F80");
/* extern */
extern int Level23_86338_D_8006C58C __asm__("D_8006C58C");
extern int Level23_86338_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level23_86338_D_8006C7B4 __asm__("D_8006C7B4");
extern Savepoint Level23_86338_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level23_86338_D_8006E048 __asm__("D_8006E048");

void func_level_23_80086338(Moby* inputOwner) {
    /* Original 0x30 frame, 37-entry selector bounds and shared state-36
     * destination are retained. The constructor uses all seven original
     * arguments, including callbackC, private+4 BYTES and maximum 4;
      its
     * returned handle is narrowed by the original SLL/SRA16 sequence.
     * The four state comparisons share the original cached Moby pool;
     * state35 retains its separate helper result and pool reloads.
     * The second 13AE4 vector argument is +16 BYTES, not vector stride16.
     * Empty constraints retain raw register producers without instructions.
     * Helper meanings, field units/fixed point, cadence and synchronized
     * runtime validation remain unresolved. AI generated;
      not human reviewed. */
    register Moby* owner18 __asm__("$18") = inputOwner;
    Moby* spawned;
    register void* callback7 __asm__("$7");
    register int raw2 __asm__("$2");
    register int raw3 __asm__("$3");
    register int count4 __asm__("$4");
    register int count5 __asm__("$5");
    register int count6 __asm__("$6");
    register Moby* pool7 __asm__("$7");
    Vector3D* helperVector;
    register int completedCount4 __asm__("$4");
    register int helperFlags7 __asm__("$7");
    register int helperFlags3 __asm__("$3");
    register int state3 __asm__("$3");
    unsigned char temp_v1_4;
    register void* anchorPrivate5 __asm__("$5");
    register void* private16 __asm__("$16");
    void* parentPrivate;

    MATCHING_KEEP(owner18);
    private16 = owner18->mobyTag;
    if ((owner18->state == 0) && (owner18->damageFlags & 0x10000)) {
        owner18->state = 1;
        Level23_86338SetMobyAnimation(inputOwner, 1);
        owner18->animationProgress = 0xA0;
        Level23_86338_func_80021ED8((int)Level23_86338Field(private16, short*, 0xC), 252, 0);
        return;
    }
    state3 = owner18->state;
    switch (state3) { /* switch 1 */
        case 30:      /* switch 1 */
            if (!(Level23_86338_D_8006C7B4 & 0x20) &&
                !(Level23_86338_D_80070300[Level23_86338_D_8006C58C] & 0x20)) {
                count4 = 7;
                count5 = 230;
                count6 = (int)Level23_86338_func_80027EE4;
                MATCHING_KEEP3(count4, count5, count6);
                raw2 = 255;
                MATCHING_KEEP(raw2);
                owner18->updateDistance = raw2;
                raw2 = 31;
                MATCHING_KEEP(raw2);
                owner18->state = raw2;
                raw2 = (int)Level23_86338_func_80029AA0;
                MATCHING_KEEP(raw2);
                owner18->unknown3[0] = 0;
                owner18->lowDrawDistance = 0;
                owner18->drawn = 0;
                owner18->unknownCollision = 0;
                Level23_86338Field(private16, int*, 8) = (short)Level23_86338_func_8002803C(
                    count4, count5, (void*)count6, Level23_86338_func_80027A60, (void*)raw2, ({
                        register void* display2 __asm__("$2") = private16 + 4;
                        MATCHING_KEEP(display2);
                        display2;
                    }),
                    ({
                        register int finalCount2 __asm__("$2") = 4;
                        MATCHING_KEEP(finalCount2);
                        finalCount2;
                    }));
                return;
            }
        default: /* switch 1 */
            return;
        case 31: /* switch 1 */
            raw3 = Level23_86338Field(private16, int*, 16);
            pool7 = Level23_86338_D_8006C550;
            raw2 = raw3 * 88;
            raw2 += (int)pool7;
            count4 = Level23_86338Field((void*)raw2, unsigned char*, 72);
            MATCHING_BARRIER_VOLATILE("memory");
            raw3 = Level23_86338Field(private16, int*, 20);
            count4 ^= 2;
            MATCHING_KEEP(count4);
            raw2 = raw3 * 88;
            raw2 += (int)pool7;
            count4 = (unsigned int)count4 < 1;
            count5 = Level23_86338Field((void*)raw2, unsigned char*, 72);
            raw3 = Level23_86338Field(private16, int*, 24);
            count5 ^= 2;
            count5 = (unsigned int)count5 < 1;
            raw2 = raw3 * 88;
            raw2 += (int)pool7;
            count4 += count5;
            count6 = Level23_86338Field((void*)raw2, unsigned char*, 72);
            raw3 = Level23_86338Field(private16, int*, 28);
            count6 ^= 2;
            count6 = (unsigned int)count6 < 1;
            raw2 = raw3 * 88;
            raw2 += (int)pool7;
            raw2 = Level23_86338Field((void*)raw2, unsigned char*, 72);
            count4 += count6;
            raw2 ^= 2;
            raw2 = (unsigned int)raw2 < 1;
            count4 += raw2;
            completedCount4 = count4;
            Level23_86338Field(private16, int*, 4) = completedCount4;
            if (completedCount4 == 4) {
                parentPrivate = pool7[Level23_86338Field(private16, int*, 32)].mobyTag;
                if (Level23_86338Field(parentPrivate, unsigned char*, 2) == 0) {
                    Level23_86338Field(parentPrivate, unsigned char*, 2) = 1U;
                    Level23_86338Field(
                        Level23_86338_D_8006C550[Level23_86338Field(private16, int*, 0x20)].mobyTag,
                        signed char*, 5) = 1;
                }
                helperFlags3 =
                    Level23_86338_func_80021F3C(Level23_86338Field(private16, short*, 14));
                raw2 = (helperFlags3 >> 8) & 255;
                if (raw2)
                    goto returnWithoutUpdate;
                raw2 = helperFlags3 & 15;
                if (raw2) {
                    Level23_86338_D_80070328.unk17a = 0x10000002;
                    Level23_86338_func_80021ED8((int)Level23_86338Field(private16, short*, 0xE),
                                                252, 0);
                    helperVector = Level23_86338Field(Level23_86338Field(private16, void**, 0x24),
                                                      Vector3D**, 0xC);
                    Level23_86338_func_80013AE4(helperVector,
                                                (Vector3D*)((unsigned char*)helperVector + 16));
                    owner18->state = 0x20;
                    Level23_86338Field(private16, int*, 0) = 0xC8;
                    return;
                }
            }
            break;
        case 32: /* switch 1 */
            if (Level23_86338_D_8006E048 == 2) {
                Level23_86338_D_80070328.unk17a = 0x10000002;
                owner18->state = 0x21;
                Level23_86338_func_8003BB10(owner18, 3, 0);
                return;
            }
            break;
        case 33: /* switch 1 */
            if (Level23_86338CountTimerDown(private16, 4) != 0) {
                Level23_86338_D_80070328.unk17a = 0x10000002;
                Level23_86338_func_80013B7C(1);
                owner18->state = 0x22;
                Level23_86338Field(private16, int*, 0) = 0x1E;
                return;
            }
            break;
        case 34: /* switch 1 */
            if (Level23_86338CountTimerDown(private16, 4) != 0) {
                owner18->state = 0x23;
                Level23_86338_func_8003B7B4(&owner18->state, 1, &Level23_86338_D_8006C7F8);
                spawned = SpawnMoby(0x110, owner18);
                if (spawned != 0) {
                    Level23_86338Field(spawned->mobyTag, signed char*, 2) = 2;
                }
                goto resetState36;
            }
            break;
        case 35: /* switch 1 */
            owner18->unknown3[0] = 0;
            owner18->lowDrawDistance = 0;
            owner18->drawn = 0;
            owner18->unknownCollision = 0;
            owner18->updateDistance = 0xFF;
            helperFlags7 = Level23_86338_func_80021F3C(Level23_86338Field(private16, short*, 14));
            raw3 = Level23_86338Field(private16, int*, 32);
            raw2 = raw3 * 88;
            raw3 = (int)Level23_86338_D_8006C550;
            raw2 += raw3;
            anchorPrivate5 = Level23_86338Field((void*)raw2, void**, 0);
            raw2 = helperFlags7 >> 8;
            count6 = raw2 & 255;
            if (Level23_86338Field(anchorPrivate5, unsigned char*, 2) == 0) {
                count4 = 1;
                MATCHING_KEEP(count4);
                Level23_86338Field(anchorPrivate5, unsigned char*, 2) = count4;
                Level23_86338Field(
                    Level23_86338_D_8006C550[Level23_86338Field(private16, int*, 32)].mobyTag,
                    signed char*, 5) = count4;
            }
            if (!count6) {
                raw2 = helperFlags7 & 15;
                count5 = 252;
                if (raw2) {
                    __asm__ volatile("" : "=r"(count6));
                    Level23_86338_func_80021ED8(Level23_86338Field(private16, short*, 14), count5,
                                                0);
                    Level23_86338_func_80021F8C((int)Level23_86338Field(private16, short*, 0xE),
                                                0x3B, 0);
                }
            }
        resetState36:
            owner18->state = 36;
            goto returnWithoutUpdate;
        case 2:
            raw3 = owner18->substate;
            count5 = 252;
            if (raw3 == 2) {
                Level23_86338_func_80021ED8(Level23_86338Field(private16, short*, 12), count5, 0);
                Level23_86338SetMobyAnimation(owner18, 2);
                owner18->substate = 0;
                owner18->updateDistance = 255;
                goto returnWithoutUpdate;
            }
            if (raw3)
                goto returnWithoutUpdate;
            raw2 = Level23_86338_func_80021F3C(Level23_86338Field(private16, short*, 12));
            raw2 &= 15;
            if (!raw2)
                goto returnWithoutUpdate;
            Level23_86338_func_80021ED8(Level23_86338Field(private16, short*, 12), 252, 0);
            owner18->updateDistance = 32;
            goto returnWithoutUpdate;
        case 1: /* switch 1 */
            if (Level23_86338_D_8006C770 != 0) {
                owner18->substate = 2;
                Level23_86338_func_8003B7B4(&owner18->substate, 1, &Level23_86338_D_8006C7F8);
                owner18->state = 2;
                Level23_86338_func_8003B7B4(&owner18->state, 1, &Level23_86338_D_8006C7F8);
                owner18->substate = 0;
                owner18->state = 2;
                Level23_86338RequestMobyAnimation(owner18, 2);
            }
        case 0:
        case 36:
            __asm__ volatile("# original-zero-and-terminal-selector");
    }
returnWithoutUpdate:;
}
#undef Level23_86338Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Native modulo32 word arithmetic; signed conversions/right shifts use the frozen MIPS ABI. */
#define Actor1937Add(a, b) ((int)((unsigned int)(a) + (unsigned int)(b)))
#define Actor1937Sub(a, b) ((int)((unsigned int)(a) - (unsigned int)(b)))
/* AI generated, not human reviewed. Uninstalled original C with approved original LW boundaries. All gates pending. */
#define Actor1937Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Actor1937Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor1937_func_80013AE4() __asm__("func_80013AE4");
int Actor1937_func_80013D44() __asm__("func_80013D44");
int Actor1937_func_8001830C() __asm__("func_8001830C");
int Actor1937_func_8001A358() __asm__("func_8001A358");
int Actor1937_func_8001BA30() __asm__("func_8001BA30");
int Actor1937_func_8002EC50() __asm__("func_8002EC50");
int Actor1937RequestMobyAnimation() __asm__("func_80034F40");
int Actor1937SetMobyAnimation() __asm__("func_80034F80");
int Actor1937TurnMobyTowardHeading() __asm__("func_8003585C");
int Actor1937CountTimerDown() __asm__("func_800359A4");
int Actor1937_func_80035A80() __asm__("func_80035A80");
int Actor1937_func_800365E4() __asm__("func_800365E4");
int Actor1937_func_80037BBC() __asm__("func_80037BBC");
int Actor1937_func_8003B7B4() __asm__("func_8003B7B4");
int Actor1937PlanarHeadingLookup() __asm__("func_8004E880");
int Actor1937TransformVectorByBasis() __asm__("func_8004ED6C");
int Actor1937MeasureVectorLength() __asm__("func_8004EDE8");
int Actor1937ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Actor1937ShiftVectorRightTowardZero() __asm__("func_8004F110");
int Actor1937CopyVector() __asm__("func_8004F178");
int Actor1937AddVector() __asm__("func_8004F194");
int Actor1937SubtractVector() __asm__("func_8004F1C8");
int Actor1937ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor1937_func_800512E4() __asm__("func_800512E4");
int Actor1937DeleteMoby() __asm__("func_80055B18");
int Actor1937RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor1937_func_80055E84() __asm__("func_80055E84");
int Actor1937InterpolateMobyVertex() __asm__("func_80055F14");
extern int Actor1937_D_800658A0 __asm__("D_800658A0");
extern int Actor1937_D_80065920 __asm__("D_80065920");
extern int Actor1937_D_8006C550 __asm__("D_8006C550");
extern int Actor1937_D_8006C58C __asm__("D_8006C58C");
extern int Actor1937_D_8006C770 __asm__("D_8006C770");
extern int Actor1937_D_8006C7B4 __asm__("D_8006C7B4");
extern int Actor1937_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor1937_D_8006C7F8 __asm__("D_8006C7F8");
extern int Actor1937_D_8006D088 __asm__("D_8006D088");
extern int Actor1937_D_8006E048 __asm__("D_8006E048");
extern int Actor1937_D_8006E160 __asm__("D_8006E160");
extern int Actor1937_D_8006E168 __asm__("D_8006E168");
extern int Actor1937_D_8006E344 __asm__("D_8006E344");
extern int Actor1937_D_8006EE2C __asm__("D_8006EE2C");
extern int Actor1937_D_80070300 __asm__("D_80070300");
extern int Actor1937_D_80070328 __asm__("D_80070328");
extern int Actor1937_D_800716AC __asm__("D_800716AC");
extern int Actor1937_D_800716B0 __asm__("D_800716B0");
extern int Actor1937_D_80071908 __asm__("D_80071908");
const unsigned int Actor1937_D_level_23_80074B0C[3] __asm__("D_level_23_80074B0C") = {90, 100, 110};
const unsigned int Actor1937_D_level_23_80074B18[4] __asm__("D_level_23_80074B18") = {120, 130, 140,
                                                                                      0};
extern int Actor1937_SpawnMoby __asm__("SpawnMoby");
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Actor1937Product;
static __inline__ int Actor1937ForwardFields(int half, int base, int out, int a, int c, int d) {
    return Actor1937_func_800365E4(a, (int)((unsigned int)base + ((unsigned int)half << 4)), c, d,
                                   out);
}
void func_level_23_800868A0(void* input) {
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
    register int valueS3 __asm__("$19");
    register int valueS4 __asm__("$20");
    register int valueS5 __asm__("$21");
    register int privateData __asm__("$22");
    register int actor __asm__("$23");
    register int word24 __asm__("$24");
    register int word25 __asm__("$25");
    register int savedWord30;
    int stackArgument4, stackArgument5, stackArgument6, stackArgument7;
    union {
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
            int spE0;
            int spE4;
            int spE8;
            int spEC;
            int spF0;
            int spF4;
            int spF8;
            int spFC;
            int sp100;
            int sp104;
            int sp108;
            int sp10C;
            int sp110;
            int sp114;
            int sp118;
            int sp11C;
            int sp120;
            int sp124;
            int sp128;
            int sp12C;
            int sp130;
            int sp134;
            int sp138;
            int sp13C;
        } fields;
    } frame;
    long long completeSignedProduct;
    actor = (int)input;
    Actor1937Keep(actor);
    argument0 = (int)input;
    privateData = Actor1937Field(actor, int*, 0);
    Actor1937Keep(privateData);
    argument1 = (int)&Actor1937_D_level_23_80074B0C;
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(argument1, int*, 0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(argument1, int*, 4);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Field(argument1, int*, 8);
    Actor1937Keep(argument0);
    Actor1937Field((int)&frame, int*, 0) = valueV0;
    Actor1937Field((int)&frame, int*, 4) = valueV1;
    Actor1937Field((int)&frame, int*, 8) = argument0;
    __asm__ volatile("" ::"r"(argument1), "m"(frame.fields.sp20), "m"(frame.fields.sp24),
                     "m"(frame.fields.sp28));
    argument1 = (int)&Actor1937_D_level_23_80074B18;
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(argument1, int*, 0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(argument1, int*, 4);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Field(argument1, int*, 8);
    Actor1937Keep(argument0);
    Actor1937Field((int)&frame, int*, 16) = valueV0;
    Actor1937Field((int)&frame, int*, 20) = valueV1;
    Actor1937Field((int)&frame, int*, 24) = argument0;
    valueV0 = Actor1937Field(actor, unsigned char*, 77);
    Actor1937Keep(valueV0);
    if (valueV0 != 0)
        goto original1937_40;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_75;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(valueV0, unsigned char*, 16) = 0;
    Actor1937Field(privateData, int*, 92) = 0;
    goto original1937_50;
original1937_40:
    valueV0 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 != 0)
        goto original1937_54;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument0 = Actor1937Add(0, 1);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 254);
    Actor1937Keep(argument1);
    argument2 = (int)0x00480000U;
    Actor1937Keep(argument2);
    argument2 = argument2 | 37008;
    valueV0 = Actor1937_func_8002EC50(argument0, argument1, argument2);
    Actor1937Field(privateData, int*, 92) = valueV0;
original1937_50:
    valueV0 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937_75;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_54:
    argument1 = Actor1937Add(0, 7);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 2);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 3);
    Actor1937Keep(argument1);
    valueS0 = (int)&frame.fields.sp40;
    Actor1937Keep(valueS0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(argument0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937ShiftVectorRightTowardZero(argument0, argument1);
    valueV1 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 8);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, unsigned char*, 19) = valueV0;
original1937_75:
    valueV1 = Actor1937Field(actor, unsigned char*, 72);
    Actor1937Keep(valueV1);
    switch ((unsigned int)valueV1) {
        case 0:
            goto original1937_148;
        case 1:
            goto original1937_194;
        case 2:
            goto original1937_343;
        case 3:
            goto original1937_486;
        case 4:
            goto original1937_1261;
        case 5:
            goto original1937_1817;
        case 6:
            goto original1937Return;
        case 7:
            goto original1937Return;
        case 8:
            goto original1937Return;
        case 9:
            goto original1937Return;
        case 10:
            goto original1937Return;
        case 11:
            goto original1937Return;
        case 12:
            goto original1937Return;
        case 13:
            goto original1937Return;
        case 14:
            goto original1937Return;
        case 15:
            goto original1937Return;
        case 16:
            goto original1937Return;
        case 17:
            goto original1937Return;
        case 18:
            goto original1937Return;
        case 19:
            goto original1937Return;
        case 20:
            MATCHING_OBSERVE_VOLATILE(valueV1);
            goto original1937_86;
        case 21:
            goto original1937_1320;
        case 22:
            goto original1937_1403;
        case 23:
            goto original1937_1410;
        case 24:
            goto original1937_423;
        case 25:
            goto original1937_1693;
        case 26:
            goto original1937_486;
        case 27:
            goto original1937_486;
        case 28:
            goto original1937_1536;
        case 29:
            goto original1937_1675;
        case 30:
            goto original1937_1428;
        case 31:
            goto original1937_1461;
        case 32:
            goto original1937Return;
        case 33:
            goto original1937_1768;
        case 34:
            goto original1937_1775;
        case 35:
            goto original1937_1785;
        case 36:
            goto original1937_993;
        case 37:
            goto original1937_851;
        case 38:
            goto original1937_1632;
        case 39:
            goto original1937Return;
        case 40:
            goto original1937Return;
        case 41:
            goto original1937Return;
        case 42:
            goto original1937Return;
        case 43:
            goto original1937Return;
        case 44:
            goto original1937Return;
        case 45:
            goto original1937Return;
        case 46:
            goto original1937Return;
        case 47:
            goto original1937Return;
        case 48:
            goto original1937Return;
        case 49:
            goto original1937Return;
        case 50:
            goto original1937_1869;
        case 51:
            goto original1937Return;
        case 52:
            goto original1937_1100;
        case 53:
            goto original1937Return;
        case 54:
            goto original1937_1807;
        default:
            goto original1937Return;
    }
original1937_86:
    valueV0 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(0, 1);
    Actor1937Keep(valueV1);
    Actor1937Field(privateData, int*, 48) = 0;
    Actor1937Field(valueV0, short*, 10) = valueV1;
    valueV0 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV0, short*, 2) = valueV1;
    valueV0 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1937Keep(argument1);
    argument1 = Actor1937Field(argument1, int*, -15024);
    Actor1937Keep(argument1);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(argument0);
    argument0 = Actor1937Add(argument0, valueV0);
    Actor1937Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor1937Keep(argument0);
    argument0 = Actor1937Sub(argument0, valueV0);
    Actor1937Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor1937Keep(argument0);
    argument0 = Actor1937Add(argument0, argument1);
    Actor1937Keep(argument0);
    argument1 = Actor1937Sub(actor, argument1);
    Actor1937Keep(argument1);
    valueV0 = (int)((unsigned int)argument1 << 5);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, argument1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 5);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument1);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 15);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Sub(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, argument1);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Field(argument0, int*, 0);
    Actor1937Keep(argument0);
    valueV1 = Actor1937Sub(0, valueV1);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(argument0, int*, 4);
    Actor1937Keep(valueV0);
    valueV1 = (valueV1 >> 3);
    Actor1937Keep(valueV1);
    if (valueV0 != valueV1)
        goto original1937_122;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Field(argument0, int*, 12);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    goto original1937_125;
original1937_122:
    valueV0 = Actor1937Field(argument0, int*, 16);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
original1937_125:
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field(actor, unsigned char*, 72) = 0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Field(privateData, unsigned char*, 56);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(actor, short*, 54);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(((int)((unsigned int)&Actor1937_D_8006EE2C + (unsigned int)valueV0)),
                             int*, 0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 60);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, unsigned char*, 0);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 >> 1);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 62) = valueV0;
    valueV0 = Actor1937Add(valueV0, 1);
    goto original1937_1923;
original1937_148:
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 6);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueS0);
    valueV1 = Actor1937Field(actor, unsigned char*, 61);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 6);
    Actor1937Keep(valueV0);
    if (valueV1 == valueV0)
        goto original1937_1789;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Field(actor, int*, 24);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937_171;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 6);
    Actor1937SetMobyAnimation(argument0, argument1);
original1937_171:
    if (valueS0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueS0);
    valueV1 = Actor1937Field(valueS0, unsigned char*, 72);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 38);
    if (valueV1 == 0)
        goto original1937_179;
    MATCHING_KEEP_VOLATILE(valueV1);
    if (valueV1 != valueV0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
original1937_179:
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    valueV0 = Actor1937_func_80037BBC(argument0, argument1);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 1);
    Actor1937_func_800512E4(argument0, argument1, argument2);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937RequestMobyAnimation(argument0, argument1);
    goto original1937Return;
original1937_194:
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -7356);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    if (valueV1 == valueV0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    Actor1937Field(actor, int*, 24) = 0;
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Field(privateData, unsigned char*, 2);
    Actor1937Keep(argument0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(argument1);
    if (argument0 == valueV0 ? (valueV0 = Actor1937Add(0, 4), 1)
                             : (valueV0 = Actor1937Add(0, 4), 0))
        goto original1937_216;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(argument0);
    if (argument0 != valueV0)
        goto original1937_226;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(argument0);
original1937_216:
    valueV0 = Actor1937Add(0, 4);
    Actor1937Keep(valueV0);
    if (argument0 != valueV0)
        goto original1937_224;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(argument0);
    valueV0 = Actor1937Field(argument1, unsigned char*, 2);
    Actor1937Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 2;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 ^ 1;
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
original1937_224:
    Actor1937Field(actor, unsigned char*, 72) = 0;
    goto original1937_1794;
original1937_226:
    /* Original CLOSED226..286 (61 words),80086C28..80086D18.
    * Actual initialized A1/GP5 supplies the first LBU address. GP2 is fully
    * defined on every exit by that load and subsequent original operations.
    * GP3/GP4 are dead scratch until original287 LW /299 LH; neither is an
    * invented incoming value or output. All targets are internal. Original
    * actual indexed LBU/SB byte widths, modulo32 address arithmetic and load/
    * branch delays remain; no table/range/default assumption is introduced. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "lbu        $v0, 2($a1)\n\t"
                     "nop\n\t"
                     "sltiu      $v0, $v0, 2\n\t"
                     "beqz       $v0, 2f\n\t"
                     "nop\n\t"
                     "lui        $v0, %%hi(D_8006C7B4)\n\t"
                     "lbu        $v0, %%lo(D_8006C7B4)($v0)\n\t"
                     "nop\n\t"
                     "andi       $v0, $v0, 8\n\t"
                     "bnez       $v0, 9f\n\t"
                     "nop\n\t"
                     "lui        $v1, %%hi(D_8006C58C)\n\t"
                     "lw         $v1, %%lo(D_8006C58C)($v1)\n\t"
                     "lui        $at, %%hi(D_80070300)\n\t"
                     "addu       $at, $at, $v1\n\t"
                     "lbu        $v0, %%lo(D_80070300)($at)\n\t"
                     "nop\n\t"
                     "andi       $v0, $v0, 8\n\t"
                     "bnez       $v0, 9f\n\t"
                     "sll       $v0, $v1, 1\n\t"
                     "addu       $v0, $v0, $v1\n\t"
                     "sll        $a0, $v0, 1\n\t"
                     "lui        $at, %%hi(D_800716AC + 3)\n\t"
                     "addu       $at, $at, $a0\n\t"
                     "lbu        $v1, %%lo(D_800716AC + 3)($at)\n\t"
                     "nop\n\t"
                     "sltiu      $v0, $v1, 255\n\t"
                     "beqz       $v0, 9f\n\t"
                     "addiu     $v0, $v1, 1\n\t"
                     "lui        $at, %%hi(D_800716AC + 3)\n\t"
                     "addu       $at, $at, $a0\n\t"
                     "sb         $v0, %%lo(D_800716AC + 3)($at)\n\t"
                     "j          9f\n\t"
                     "nop\n\t"
                     "2:\n\t"
                     "lui        $v0, %%hi(D_8006C7B4)\n\t"
                     "lbu        $v0, %%lo(D_8006C7B4)($v0)\n\t"
                     "nop\n\t"
                     "andi       $v0, $v0, 16\n\t"
                     "bnez       $v0, 9f\n\t"
                     "nop\n\t"
                     "lui        $v1, %%hi(D_8006C58C)\n\t"
                     "lw         $v1, %%lo(D_8006C58C)($v1)\n\t"
                     "lui        $at, %%hi(D_80070300)\n\t"
                     "addu       $at, $at, $v1\n\t"
                     "lbu        $v0, %%lo(D_80070300)($at)\n\t"
                     "nop\n\t"
                     "andi       $v0, $v0, 16\n\t"
                     "bnez       $v0, 9f\n\t"
                     "sll       $v0, $v1, 1\n\t"
                     "addu       $v0, $v0, $v1\n\t"
                     "sll        $a0, $v0, 1\n\t"
                     "lui        $at, %%hi(D_800716B0)\n\t"
                     "addu       $at, $at, $a0\n\t"
                     "lbu        $v1, %%lo(D_800716B0)($at)\n\t"
                     "nop\n\t"
                     "sltiu      $v0, $v1, 255\n\t"
                     "beqz       $v0, 9f\n\t"
                     "addiu     $v0, $v1, 1\n\t"
                     "lui        $at, %%hi(D_800716B0)\n\t"
                     "addu       $at, $at, $a0\n\t"
                     "sb         $v0, %%lo(D_800716B0)($at)\n\t"
                     "9:\n\t"
                     ".set\treorder"
                     : "=r"(valueV0)
                     : "r"(argument1)
                     : "$1", "$3", "$4", "memory");
Actor1937FirstThreeEntry:
    MATCHING_OBSERVE_VOLATILE(valueV0);
Actor1937LastIncrementEntry:
    __asm__ volatile("" ::"r"(valueV0), "i"(0x80086D08U));
original1937_287:
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Add(0, 1);
    if (argument0 != 0)
        goto original1937_307;
    MATCHING_KEEP_VOLATILE(argument0);
    valueV1 = Actor1937Field(privateData, unsigned char*, 56);
    Actor1937Keep(valueV1);
    if (valueV1 == valueV0)
        goto original1937_313;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
original1937_307:
    if (argument0 != valueV0)
        goto original1937_317;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(argument0);
    valueV0 = Actor1937Field(privateData, unsigned char*, 56);
    Actor1937Keep(valueV0);
    if (valueV0 != 0)
        goto original1937_317;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_313:
    MATCHING_BARRIER_VOLATILE("$2");
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 57) = valueV0;
    Actor1937Field(argument1, unsigned char*, 57) = valueV0;
    goto original1937_319;
original1937_317:
    Actor1937Field(privateData, unsigned char*, 57) = 0;
    Actor1937Field(argument1, unsigned char*, 57) = 0;
original1937_319:
    valueV0 = Actor1937Add(0, 33);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_8006E160, int*, 0) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 1);
    Actor1937Keep(argument2);
    argument3 = Actor1937Field(valueV0, int*, 16);
    Actor1937Keep(argument3);
    argument0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(argument0);
    valueV1 = Actor1937Field(valueV0, int*, 20);
    Actor1937Keep(valueV1);
    argument1 = Actor1937Field(valueV0, int*, 4);
    Actor1937Keep(argument1);
    argument0 = Actor1937Sub(argument3, argument0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Sub(valueV1, argument1);
    valueV0 = Actor1937PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 2);
    Actor1937Keep(argument1);
    Actor1937Field((int)&Actor1937_D_8006E168, int*, 0) = valueV0;
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Add(0, 255);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 74) = valueV0;
    goto original1937Return;
original1937_343:
    valueV0 = Actor1937Field(actor, unsigned char*, 73);
    Actor1937Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = Actor1937Add(0, 2), 1) : (valueV0 = Actor1937Add(0, 2), 0))
        goto original1937_379;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(actor, unsigned char*, 60);
    Actor1937Keep(valueV1);
    if (valueV1 != valueV0)
        goto original1937_379;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument0 = Actor1937Add(actor, 0);
    valueV0 = Actor1937_func_80055E84(argument0);
    valueV0 = valueV0 < 21;
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(0, 80);
    if (valueV0 != 0)
        goto original1937_379;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 17120);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(actor, 0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    argument0 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument0);
    if (argument0 == 0)
        goto original1937_379;
    MATCHING_KEEP_VOLATILE(argument0);
    valueV1 = Actor1937Field(argument0, int*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(privateData, int*, 72);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, int*, 20) = valueV0;
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 73) = valueV0;
    valueV0 = Actor1937Add(0, 255);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, unsigned char*, 74) = valueV0;
    valueV0 = Actor1937Field(actor, unsigned char*, 76);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, unsigned char*, 76) = valueV0;
    valueV0 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, unsigned char*, 70) = valueV0;
    Actor1937Field(privateData, int*, 48) = argument0;
original1937_379:
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_407;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument0 = Actor1937Add(actor, 0);
    valueV0 = Actor1937_func_80055E84(argument0);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 5);
    Actor1937Keep(argument1);
    valueS0 = Actor1937Add(valueV0, 0);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    valueV0 = valueS0 < 30;
    Actor1937Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = Actor1937Add(0, 127), 1) : (valueV0 = Actor1937Add(0, 127), 0))
        goto original1937_400;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV1);
    Actor1937Field(valueV1, unsigned char*, 79) = valueV0;
    goto original1937_407;
original1937_400:
    valueV0 = Actor1937Add(0, 41);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueS0);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 4);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, 40);
    Actor1937Keep(valueV1);
    Actor1937Field(valueV0, unsigned char*, 79) = valueV1;
original1937_407:
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14480);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 3);
    Actor1937Keep(argument1);
    valueV1 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 40);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, unsigned char*, 79) = valueV0;
    Actor1937Field(actor, unsigned char*, 73) = 0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Add(0, 24);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV0, short*, 2) = 0;
    goto original1937Return;
original1937_423:
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937_434;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 5);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
original1937_434:
    valueV0 = Actor1937Field(privateData, unsigned char*, 57);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_453;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Field(valueV0, int*, 60);
    Actor1937Keep(argument0);
    goto original1937_454;
original1937_453:
    argument0 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(argument0);
original1937_454:
    valueV1 = Actor1937Field(argument0, int*, 12);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(actor, int*, 12);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(argument0);
    argument0 = Actor1937Sub(argument0, valueV0);
    Actor1937Keep(argument0);
    Actor1937Field((int)&frame, int*, 48) = argument0;
    argument1 = Actor1937Field(valueV1, int*, 4);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(actor, int*, 16);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    argument1 = Actor1937Sub(argument1, valueV0);
    Actor1937Keep(argument1);
    Actor1937Field((int)&frame, int*, 52) = argument1;
    valueV0 = Actor1937PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 8);
    Actor1937Keep(argument2);
    argument3 = Actor1937Add(0, 1);
    Actor1937Keep(argument3);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    stackArgument4 = valueV0;
    stackArgument5 = 0;
    Actor1937TurnMobyTowardHeading(argument0, argument1, argument2, argument3, stackArgument4,
                                   stackArgument5);
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14480);
    Actor1937Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = Actor1937Add(0, 3), 1) : (valueV0 = Actor1937Add(0, 3), 0))
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 3);
    Actor1937RequestMobyAnimation(argument0, argument1);
    goto original1937Return;
original1937_486:
    argument0 = Actor1937Add(actor, 0);
    valueV0 = Actor1937_func_80055E84(argument0);
    valueS1 = (int)0x00010000U;
    Actor1937Keep(valueS1);
    valueS1 = valueS1 | 34464;
    Actor1937Keep(valueS1);
    valueS2 = Actor1937Add(0, 0);
    Actor1937Keep(valueS2);
    argument1 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(argument1);
    valueS0 = Actor1937Add(0, 0);
    Actor1937Keep(valueS0);
    valueV1 = Actor1937Field(argument1, short*, 0);
    Actor1937Keep(valueV1);
    valueS3 = Actor1937Add(valueV0, 0);
    if (valueV1 <= 0)
        goto original1937_516;
    MATCHING_KEEP_VOLATILE(valueV1);
original1937_497:
    argument0 = (int)&Actor1937_D_80070328;
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field(argument1, int*, 12);
    Actor1937Keep(valueV0);
    argument1 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(argument1);
    argument1 = Actor1937Add(valueV0, argument1);
    valueV0 = Actor1937ApproximatePlanarDistance(argument0, argument1);
    valueV1 = Actor1937Add(valueV0, 0);
    Actor1937Keep(valueV1);
    valueV0 = valueV1 < valueS1;
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_509;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS1 = Actor1937Add(valueV1, 0);
    Actor1937Keep(valueS1);
    valueS2 = Actor1937Add(valueS0, 0);
    Actor1937Keep(valueS2);
original1937_509:
    argument1 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(argument1, short*, 0);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(valueS0, 2);
    Actor1937Keep(valueS0);
    valueV0 = valueS0 < valueV0;
    Actor1937Keep(valueV0);
    if (valueV0 != 0)
        goto original1937_497;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_516:
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 1);
    Actor1937Keep(argument2);
    valueV1 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueS2 << 4);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    argument3 = Actor1937Field(valueV0, int*, 16);
    Actor1937Keep(argument3);
    argument0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(argument0);
    valueV1 = Actor1937Field(valueV0, int*, 20);
    Actor1937Keep(valueV1);
    argument1 = Actor1937Field(valueV0, int*, 4);
    Actor1937Keep(argument1);
    argument0 = Actor1937Sub(argument3, argument0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Sub(valueV1, argument1);
    valueV0 = Actor1937PlanarHeadingLookup(argument0, argument1, argument2);
    valueV1 = Actor1937Add(0, 33);
    Actor1937Keep(valueV1);
    Actor1937Field((int)&Actor1937_D_8006E160, int*, 0) = valueV1;
    Actor1937Field((int)&Actor1937_D_8006E168, int*, 0) = valueV0;
    valueV0 = Actor1937Field(privateData, unsigned char*, 57);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_552;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Sub(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -15024);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 << 3);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueS0);
    valueS4 = Actor1937Field(valueS0, int*, 60);
    Actor1937Keep(valueS4);
    goto original1937_553;
original1937_552:
    valueS4 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueS4);
original1937_553:
    valueV1 = Actor1937Field(actor, unsigned char*, 60);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(valueS3, -11), 1)
                           : (valueV0 = Actor1937Add(valueS3, -11), 0))
        goto original1937_560;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = (unsigned int)valueV0 < 5;
    Actor1937Keep(valueV0);
    valueS1 = Actor1937Add(0, 30);
    if (valueV0 != 0)
        goto original1937_590;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_560:
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1937_584;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14396);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)&frame + (unsigned int)valueV0 - 32U);
    Actor1937Keep(valueV0);
    __asm__ volatile("lw %0,48(%1)" : "=r"(valueS1) : "r"(valueV0) : "memory");
    goto original1937_590;
original1937_584:
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14396);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)&frame + (unsigned int)valueV0 - 32U);
    Actor1937Keep(valueV0);
    __asm__ volatile("lw %0,32(%1)" : "=r"(valueS1) : "r"(valueV0) : "memory");
original1937_590:
    valueV1 = Actor1937Field(actor, unsigned char*, 72);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 26);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(0, 27), 1)
                           : (valueV0 = Actor1937Add(0, 27), 0))
        goto original1937_634;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Add(valueS3, -10);
    Actor1937Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 10;
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 12);
    if (valueV0 == 0)
        goto original1937_633;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument2 = Actor1937Add(0, 60);
    Actor1937Keep(argument2);
    argument3 = Actor1937Add(0, -10);
    Actor1937Keep(argument3);
    valueV0 = Actor1937Add(0, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, short*, 66) = valueV0;
    valueV0 = Actor1937ForwardFields(
        Actor1937Field(valueS4, short*, 2), (valueV1 = Actor1937Field(valueS4, int*, 12)),
        (stackArgument4 = (int)&frame.fields.sp70), argument0, argument2, argument3);
    argument0 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument0);
    Actor1937Field(privateData, short*, 64) = argument0;
    valueV0 = Actor1937Field(valueS4, short*, 2);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueS4, int*, 12);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(actor, int*, 20);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV0, int*, 8);
    Actor1937Keep(valueV0);
    valueV0 = valueV0 < valueV1;
    Actor1937Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = Actor1937Add(0, 90), 1) : (valueV0 = Actor1937Add(0, 90), 0))
        goto original1937_629;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = (int)0x55550000U;
    Actor1937Keep(valueV1);
    valueV1 = valueV1 | 21846;
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)argument0 << 16);
    Actor1937Keep(valueV0);
    valueV0 = (valueV0 >> 15);
    Actor1937Keep(valueV0);
    Actor1937Keep(valueV0);
    Actor1937Keep(valueV1);
    completeSignedProduct = (long long)valueV0 * (long long)valueV1;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    valueV0 = (valueV0 >> 31);
    Actor1937Keep(valueV0);
    {
        int capturedWholeProjection;
        __asm__("" : "=h"(capturedWholeProjection) : "x"(completeSignedProduct));
        valueT0 = capturedWholeProjection;
        Actor1937Keep(valueT0);
    }
    valueV0 = Actor1937Sub(valueT0, valueV0);
    Actor1937Keep(valueV0);
original1937_629:
    Actor1937Field(privateData, short*, 64) = valueV0;
    valueV0 = Actor1937Add(0, 27);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    MATCHING_BARRIER_VOLATILE("memory");
    valueV1 = Actor1937Field(actor, unsigned char*, 72);
    Actor1937Keep(valueV1);
original1937_633:
    valueV0 = Actor1937Add(0, 27);
    Actor1937Keep(valueV0);
original1937_634:
    argument0 = Actor1937Add(actor, 0);
    if (valueV1 != valueV0)
        goto original1937_680;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV1 = Actor1937Field(privateData, short*, 64);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(actor, int*, 20);
    Actor1937Keep(valueV0);
    valueS1 = Actor1937Field(privateData, short*, 66);
    Actor1937Keep(valueS1);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, int*, 20) = valueV0;
    valueV0 = Actor1937Field(privateData, unsigned short*, 64);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, -10);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, short*, 64) = valueV0;
    valueV0 = Actor1937Field(actor, unsigned char*, 62);
    Actor1937Keep(valueV0);
    valueS3 = Actor1937Add(0, 0);
    if (valueV0 != 0)
        goto original1937_653;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 63) = valueV0;
    valueV0 = Actor1937Add(0, 32);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 64) = valueV0;
original1937_653:
    valueV0 = Actor1937Field(privateData, short*, 64);
    Actor1937Keep(valueV0);
    __asm__ volatile("" ::: "$4", "memory");
    if (valueV0 >= 0 ? (argument0 = Actor1937Add(actor, 0), 1)
                     : (argument0 = Actor1937Add(actor, 0), 0))
        goto original1937_682;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_OBSERVE_VOLATILE(argument0);
    valueS0 = (int)&frame.fields.sp78;
    Actor1937Keep(valueS0);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(actor, 12);
    Actor1937CopyVector(argument0, argument1);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field((int)&frame, volatile int*, 96);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(0, 2048);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(valueV0, 1024);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 96) = valueV0;
    valueV0 = Actor1937_func_8001A358(argument0, argument1);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937_682;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, 6408);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(actor, int*, 20);
    Actor1937Keep(valueV0);
    valueV0 = valueV1 < valueV0;
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(valueS4, 0);
    if (valueV0 != 0)
        goto original1937_683;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, int*, 20) = valueV1;
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937_683;
original1937_680:
    valueS3 = (int)0x00020000U;
    Actor1937Keep(valueS3);
    valueS3 = valueS3 | 4;
    Actor1937Keep(valueS3);
original1937_682:
    MATCHING_BARRIER_VOLATILE("$5");
    argument1 = Actor1937Add(valueS4, 0);
    Actor1937Keep(argument1);
original1937_683:
    argument2 = Actor1937Add(0, 120);
    Actor1937Keep(argument2);
    argument3 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument3);
    valueS0 = Actor1937Add(0, 3);
    Actor1937Keep(valueS0);
    valueS2 = Actor1937Field(valueS4, short*, 2);
    Actor1937Keep(valueS2);
    valueV0 = Actor1937Add(0, 128);
    Actor1937Keep(valueV0);
    stackArgument4 = 0;
    stackArgument5 = valueS0;
    stackArgument6 = valueV0;
    stackArgument7 = valueS3;
    valueV0 = Actor1937_func_80035A80(argument0, argument1, argument2, argument3, stackArgument4,
                                      stackArgument5, stackArgument6, stackArgument7);
    valueV1 = Actor1937Add(valueV0, 0);
    Actor1937Keep(valueV1);
    valueV0 = valueV1 & 2;
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(0, 0);
    if (valueV0 == 0)
        goto original1937_710;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    argument0 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(argument0);
    argument3 = Actor1937Add(0, 65);
    Actor1937_func_80013D44(argument0, argument1, argument2, argument3);
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Add(0, 52);
    goto original1937_1257;
original1937_710:
    valueV0 = Actor1937Field(actor, unsigned char*, 72);
    Actor1937Keep(valueV0);
    if (valueV0 != valueS0 ? (valueV0 = valueV1 & 1, 1) : (valueV0 = valueV1 & 1, 0))
        goto original1937_732;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueS0);
    valueV1 = (int)((unsigned int)valueS2 << 4);
    if (valueV0 == 0)
        goto original1937_732;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(valueS4, short*, 2);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Field(valueS4, int*, 12);
    Actor1937Keep(argument0);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, argument0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV0, int*, 8);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV1, int*, 8);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    if (valueV0 >= 0)
        goto original1937_728;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Sub(0, valueV0);
    Actor1937Keep(valueV0);
original1937_728:
    valueV0 = valueV0 < 129;
    Actor1937Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = Actor1937Add(0, 26), 1) : (valueV0 = Actor1937Add(0, 26), 0))
        goto original1937_732;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
original1937_732:
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 5);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    valueS0 = (int)&frame.fields.sp60;
    Actor1937Keep(valueS0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(argument0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937ShiftVectorRightTowardZero(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 12);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 512);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 3);
    Actor1937Keep(argument2);
    valueS5 = Actor1937Field(valueV0, int*, 8);
    Actor1937Keep(valueS5);
    argument3 = Actor1937Add(0, 0);
    Actor1937Keep(argument3);
    Actor1937Field(valueV0, int*, 8) = 0;
    stackArgument4 = 0;
    stackArgument5 = actor;
    valueV0 = Actor1937_func_8001BA30(argument0, argument1, argument2, argument3, stackArgument4,
                                      stackArgument5);
    argument2 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument2);
    valueV0 = Actor1937Add(0, 2);
    if (argument2 == 0)
        goto original1937_848;
    MATCHING_KEEP_VOLATILE(argument2);
    valueV1 = Actor1937Field(argument2, unsigned char*, 73);
    Actor1937Keep(valueV1);
    valueS2 = Actor1937Add(0, 10);
    if (valueV1 != valueV0)
        goto original1937_848;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueS3 = (int)0x00010000U;
    Actor1937Keep(valueS3);
    valueS3 = valueS3 | 34464;
    Actor1937Keep(valueS3);
    valueS0 = Actor1937Add(0, 0);
    Actor1937Keep(valueS0);
    valueV0 = Actor1937Add(0, 10);
    Actor1937Keep(valueV0);
    Actor1937Field(argument2, unsigned char*, 73) = valueV0;
    __asm__ volatile("" ::"m"(Actor1937Field(argument2, unsigned char*, 73)));
    argument0 = (int)0x80070000U;
    Actor1937Keep(argument0);
    argument0 = Actor1937Field(argument0, int*, -15024);
    Actor1937Keep(argument0);
    argument1 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(argument1);
    argument0 = Actor1937Sub(argument2, argument0);
    Actor1937Keep(argument0);
    valueV1 = (int)((unsigned int)argument0 << 5);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Sub(valueV1, argument0);
    Actor1937Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 5);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, argument0);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 15);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(0, valueV0);
    Actor1937Keep(valueV0);
    valueV0 = (valueV0 >> 3);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, int*, 88) = valueV0;
    valueV0 = Actor1937Field(argument1, short*, 0);
    Actor1937Keep(valueV0);
    valueS1 = Actor1937Add(0, 0);
    if (valueV0 <= 0)
        goto original1937_818;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 12);
    Actor1937Keep(argument0);
original1937_801:
    valueV0 = Actor1937Field(argument1, int*, 12);
    Actor1937Keep(valueV0);
    argument1 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(argument1);
    argument1 = Actor1937Add(valueV0, argument1);
    valueV0 = Actor1937ApproximatePlanarDistance(argument0, argument1);
    valueV1 = Actor1937Add(valueV0, 0);
    Actor1937Keep(valueV1);
    valueV0 = valueV1 < valueS3;
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_811;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS3 = Actor1937Add(valueV1, 0);
    Actor1937Keep(valueS3);
    valueS1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(valueS1);
original1937_811:
    argument1 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(argument1, short*, 0);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(valueS0, 2);
    Actor1937Keep(valueS0);
    valueV0 = valueS0 < valueV0;
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 12);
    if (valueV0 != 0)
        goto original1937_801;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_818:
    Actor1937Field(privateData, short*, 78) = valueS1;
    valueV0 = Actor1937Field(valueS4, short*, 2);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(valueV0, -1);
    if (valueS2 == 0)
        goto original1937_835;
    MATCHING_KEEP_VOLATILE(valueS2);
    argument0 = Actor1937Add(actor, 12);
    if (valueS0 < 0)
        goto original1937_835;
    MATCHING_KEEP_VOLATILE(valueS0);
original1937_824:
    argument1 = Actor1937Field(valueS4, int*, 12);
    Actor1937Keep(argument1);
    valueV0 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(argument1, valueV0);
    valueV0 = Actor1937ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 3072;
    Actor1937Keep(valueV0);
    valueS2 = Actor1937Add(valueS2, -1);
    if (valueV0 == 0)
        goto original1937_835;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS0 = Actor1937Add(valueS0, -1);
    if (valueS2 == 0)
        goto original1937_835;
    MATCHING_KEEP_VOLATILE(valueS2);
    argument0 = Actor1937Add(actor, 12);
    if (valueS0 >= 0)
        goto original1937_824;
    MATCHING_KEEP_VOLATILE(valueS0);
original1937_835:
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field(valueS4, short*, 2) = valueS0;
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    argument0 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(argument0);
    argument3 = Actor1937Add(0, 65);
    Actor1937_func_80013D44(argument0, argument1, argument2, argument3);
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Add(0, 37);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
original1937_848:
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV0, int*, 8) = valueS5;
    goto original1937Return;
original1937_851:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV1 = Actor1937Field(actor, unsigned char*, 73);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = Actor1937Add(0, 1), 1) : (valueV0 = Actor1937Add(0, 1), 0))
        goto original1937_986;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -8120);
    Actor1937Keep(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(0, 2), 1) : (valueV0 = Actor1937Add(0, 2), 0))
        goto original1937_989;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    valueS3 = (int)&frame.fields.sp88;
    Actor1937Keep(valueS3);
    argument0 = Actor1937Add(valueS3, 0);
    Actor1937Keep(argument0);
    Actor1937Field(actor, unsigned char*, 73) = valueV0;
    valueV1 = Actor1937Field(privateData, int*, 88);
    Actor1937Keep(valueV1);
    valueS2 = (int)0x80070000U;
    Actor1937Keep(valueS2);
    valueS2 = Actor1937Field(valueS2, int*, -15024);
    Actor1937Keep(valueS2);
    valueS0 = Actor1937Field(privateData, short*, 78);
    Actor1937Keep(valueS0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueS2 = Actor1937Add(valueS2, valueV0);
    Actor1937Keep(valueS2);
    valueS2 = Actor1937Add(valueS2, 12);
    Actor1937Keep(valueS2);
    argument1 = Actor1937Add(valueS2, 0);
    Actor1937CopyVector(argument0, argument1);
    valueV0 = Actor1937Field((int)&frame, volatile int*, 112);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, 500);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 112) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(valueV1);
    valueS0 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(valueS0);
    valueV1 = Actor1937Add(valueS0, valueV1);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV1, int*, 16);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 120) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    valueS1 = (int)&frame.fields.sp98;
    Actor1937Keep(valueS1);
    valueV0 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    valueS0 = Actor1937Add(valueS0, valueV0);
    Actor1937Keep(valueS0);
    valueV0 = Actor1937Field(valueS0, int*, 20);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueS0, int*, 4);
    Actor1937Keep(valueV1);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field((int)&frame, int*, 128) = 0;
    __asm__ volatile("" ::"m"(Actor1937Field((int)&frame, int*, 128)));
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 124) = valueV0;
    valueV0 = Actor1937MeasureVectorLength(argument0, argument1);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 6144);
    Actor1937ScaleVectorRatioQ15(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS2, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS1, 0);
    Actor1937SubtractVector(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field((int)&frame, volatile int*, 128);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(valueS3, 0);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(valueV0, 4096);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 128) = valueV0;
    Actor1937_func_80013AE4(argument0, argument1);
    argument0 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(argument0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)argument0 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument0);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, argument0);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(privateData, unsigned char*, 57);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueV1);
    if (valueV0 == 0)
        goto original1937_939;
    MATCHING_KEEP_VOLATILE(valueV0);
    if (argument0 < 0 ? (argument0 = Actor1937Add(actor, 12), 1)
                      : (argument0 = Actor1937Add(actor, 12), 0))
        goto original1937_939;
    MATCHING_KEEP_VOLATILE(argument0);
    valueS1 = Actor1937Field(valueV1, int*, 60);
    Actor1937Keep(valueS1);
    goto original1937_941;
original1937_939:
    valueS1 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueS1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 12);
    Actor1937Keep(argument0);
original1937_941:
    valueS0 = Actor1937Field(valueS1, short*, 2);
    Actor1937Keep(valueS0);
    argument1 = Actor1937Field(valueS1, int*, 12);
    Actor1937Keep(argument1);
    valueS0 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(valueS0);
    argument1 = Actor1937Add(argument1, valueS0);
    Actor1937CopyVector(argument0, argument1);
    valueV0 = Actor1937Field(valueS1, int*, 12);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    valueS0 = Actor1937Add(valueS0, valueV0);
    Actor1937Keep(valueS0);
    valueV1 = Actor1937Field(valueS0, int*, 16);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Field(valueS0, int*, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field(valueS0, int*, 20);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Field(valueS0, int*, 4);
    Actor1937Keep(argument1);
    argument0 = Actor1937Sub(valueV1, argument0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Sub(valueV0, argument1);
    valueV0 = Actor1937PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 3);
    Actor1937Keep(argument1);
    Actor1937Field(actor, unsigned char*, 70) = valueV0;
    Actor1937SetMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_986;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 5);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    valueS0 = (int)&frame.fields.spA8;
    Actor1937Keep(valueS0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(argument0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937ShiftVectorRightTowardZero(argument0, argument1);
original1937_986:
    MATCHING_BARRIER_VOLATILE("$3");
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -8120);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
original1937_989:
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(0, 36), 1)
                           : (valueV0 = Actor1937Add(0, 36), 0))
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_993:
    argument0 = Actor1937Add(actor, 0);
    valueV0 = Actor1937_func_80055E84(argument0);
    argument0 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(argument0);
    argument1 = (int)0x10000000U;
    Actor1937Keep(argument1);
    valueV1 = (int)((unsigned int)argument0 << 1);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, argument0);
    Actor1937Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Sub(valueV1, argument0);
    Actor1937Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1937Keep(argument0);
    argument0 = Actor1937Field(argument0, int*, -15024);
    Actor1937Keep(argument0);
    valueV1 = (int)((unsigned int)valueV1 << 3);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Add(argument0, valueV1);
    Actor1937Keep(argument0);
    argument3 = Actor1937Field(argument0, int*, 0);
    Actor1937Keep(argument3);
    argument1 = argument1 | 2;
    Actor1937Keep(argument1);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = argument1;
    valueV1 = Actor1937Field(privateData, unsigned char*, 57);
    Actor1937Keep(valueV1);
    argument2 = Actor1937Add(valueV0, 0);
    if (valueV1 == 0)
        goto original1937_1020;
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV0);
    if (valueV0 < 0)
        goto original1937_1020;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Field(argument3, int*, 60);
    Actor1937Keep(argument1);
    goto original1937_1021;
original1937_1020:
    argument1 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(argument1);
original1937_1021:
    valueV1 = Actor1937Field(actor, unsigned char*, 60);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(argument2, -11), 1)
                           : (valueV0 = Actor1937Add(argument2, -11), 0))
        goto original1937_1030;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = (unsigned int)valueV0 < 5;
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_1030;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument3 = Actor1937Add(0, 30);
    goto original1937_1041;
original1937_1030:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = Actor1937Add(0, 3);
    if (argument0 == 0)
        goto original1937_1040;
    MATCHING_KEEP_VOLATILE(argument0);
    valueV1 = Actor1937Field(argument3, unsigned char*, 2);
    Actor1937Keep(valueV1);
    if (valueV1 == valueV0 ? (valueV0 = Actor1937Add(0, 5), 1) : (valueV0 = Actor1937Add(0, 5), 0))
        goto original1937_1038;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument3 = Actor1937Add(0, 100);
    if (valueV1 != valueV0)
        goto original1937_1041;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
original1937_1038:
    argument3 = Actor1937Add(0, 130);
    goto original1937_1041;
original1937_1040:
    argument3 = Actor1937Add(0, 100);
    Actor1937Keep(argument3);
original1937_1041:
    valueV0 = Actor1937_func_80035A80((argument0 = actor), argument1, (argument2 = 120), argument3,
                                      (stackArgument4 = 0), (stackArgument5 = 6),
                                      (stackArgument6 = 128), (stackArgument7 = 4));
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 5);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    valueS0 = (int)&frame.fields.spA8;
    Actor1937Keep(valueS0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(argument0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937ShiftVectorRightTowardZero(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 12);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 900);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 3);
    Actor1937Keep(argument2);
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument3 = Actor1937Add(0, 0);
    Actor1937Keep(argument3);
    Actor1937Field(valueV0, int*, 8) = 0;
    stackArgument4 = 0;
    stackArgument5 = actor;
    valueV0 = Actor1937_func_8001BA30(argument0, argument1, argument2, argument3, stackArgument4,
                                      stackArgument5);
    argument2 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument2);
    valueV0 = Actor1937Add(0, 10);
    if (argument2 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(argument2);
    valueV1 = Actor1937Field(argument2, unsigned char*, 73);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Add(actor, 0);
    if (valueV1 != valueV0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument1 = Actor1937Add(0, 5);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    Actor1937Field(argument2, unsigned char*, 73) = valueV0;
    valueV1 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 6);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Add(0, 5);
    goto original1937_1257;
original1937_1100:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_1130;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 5);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    valueS0 = (int)&frame.fields.spB8;
    Actor1937Keep(valueS0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(argument0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument0 = Actor1937Add(argument0, 12);
    Actor1937ShiftVectorRightTowardZero(argument0, argument1);
original1937_1130:
    valueV1 = Actor1937Field(actor, unsigned char*, 73);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = Actor1937Add(0, 1), 1) : (valueV0 = Actor1937Add(0, 1), 0))
        goto original1937_1249;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -8120);
    Actor1937Keep(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(0, 2), 1) : (valueV0 = Actor1937Add(0, 2), 0))
        goto original1937_1252;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Add(0, 3);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 73) = valueV0;
    valueV0 = Actor1937Field(privateData, unsigned char*, 57);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_1161;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    if (valueV1 < 0)
        goto original1937_1161;
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV0, int*, 60);
    Actor1937Keep(valueV1);
    argument2 = Actor1937Add(0, 0);
    goto original1937_1163;
original1937_1161:
    valueV1 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueV1);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
original1937_1163:
    valueV0 = Actor1937Field(valueV1, short*, 0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV1, int*, 12);
    Actor1937Keep(valueV1);
    valueS0 = Actor1937Add(valueV0, -2);
    Actor1937Keep(valueS0);
    valueV0 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    argument3 = Actor1937Field(valueV0, int*, 16);
    Actor1937Keep(argument3);
    argument0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(argument0);
    valueV1 = Actor1937Field(valueV0, int*, 20);
    Actor1937Keep(valueV1);
    argument1 = Actor1937Field(valueV0, int*, 4);
    Actor1937Keep(argument1);
    argument0 = Actor1937Sub(argument3, argument0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Sub(valueV1, argument1);
    valueV0 = Actor1937PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1937Field(actor, unsigned char*, 70) = valueV0;
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    argument1 = (int)0x80070000U;
    Actor1937Keep(argument1);
    argument1 = Actor1937Field(argument1, int*, -15024);
    Actor1937Keep(argument1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument1);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(valueV1, short*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(valueV1, -1);
    if (valueV0 != 0)
        goto original1937_1195;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 80);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    goto original1937_1198;
original1937_1195:
    valueV1 = Actor1937Field(privateData, int*, 84);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
original1937_1198:
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(argument1, valueV0);
    Actor1937Keep(argument1);
    valueS1 = (int)&frame.fields.spC8;
    Actor1937Keep(valueS1);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(argument1, 12);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(actor, 12);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937ShiftVectorRightTowardZero(argument0, argument1);
    valueV0 = Actor1937Field((int)&frame, volatile int*, 176);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, 500);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 176) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    argument1 = (int)((unsigned int)valueS0 << 4);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field((int)&frame, volatile int*, 168);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(argument1, valueV0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueV0);
    valueS0 = (int)&frame.fields.spD8;
    Actor1937Keep(valueS0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 184) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 68);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field(valueV0, int*, 12);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field((int)&frame, volatile int*, 172);
    Actor1937Keep(valueV1);
    argument1 = Actor1937Add(argument1, valueV0);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(argument1, int*, 4);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field((int)&frame, int*, 192) = 0;
    __asm__ volatile("" ::"m"(Actor1937Field((int)&frame, int*, 192)));
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 188) = valueV0;
    valueV0 = Actor1937MeasureVectorLength(argument0, argument1);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueV0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 6144);
    Actor1937ScaleVectorRatioQ15(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field((int)&frame, volatile int*, 192);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(valueV0, 4096);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 192) = valueV0;
    Actor1937_func_80013AE4(argument0, argument1);
original1937_1249:
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -8120);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
original1937_1252:
    argument0 = Actor1937Add(actor, 0);
    if (valueV1 != valueV0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument1 = Actor1937Add(0, 4);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(0, 4);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, unsigned char*, 73) = 0;
original1937_1257:
    Actor1937Field(argument0, unsigned char*, 72) = valueV0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    goto original1937Return;
original1937_1261:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_1309;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(actor, unsigned char*, 73);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 != 0)
        goto original1937_1309;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 5);
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(argument2);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(argument2, 12);
    Actor1937InterpolateMobyVertex(argument0, argument1, argument2);
    valueV1 = Actor1937Field(actor, unsigned char*, 60);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 4);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1937_1309;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument0 = Actor1937Add(actor, 0);
    valueV0 = Actor1937_func_80055E84(argument0);
    valueV0 = valueV0 < 24;
    Actor1937Keep(valueV0);
    if (valueV0 != 0)
        goto original1937_1309;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 73) = valueV0;
    valueV1 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, unsigned char*, 70) = valueV0;
    valueV1 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 7);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Add(0, 200);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, short*, 0) = valueV0;
    valueV0 = Actor1937Add(0, 150);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, int*, 8) = valueV0;
    Actor1937Field(argument0, int*, 4) = valueV0;
    valueV0 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(valueV0);
    Actor1937Field(argument0, short*, 2) = valueV0;
original1937_1309:
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14480);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field(actor, unsigned char*, 73) = 0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Add(0, 21);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1320:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 48);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 != 0)
        goto original1937_1335;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 3);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Field(privateData, unsigned char*, 56);
    Actor1937Keep(valueV0);
    goto original1937_1395;
original1937_1335:
    valueV0 = Actor1937Field(valueV0, unsigned char*, 72);
    Actor1937Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 251;
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(0, 3);
    if (valueV0 != 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(privateData, int*, 48) = 0;
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    valueS0 = (int)0x80070000U;
    Actor1937Keep(valueS0);
    valueS0 = Actor1937Field(valueS0, int*, -15024);
    Actor1937Keep(valueS0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueS0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(valueV0);
    if (valueV0 != 0)
        goto original1937_1360;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 80);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    goto original1937_1363;
original1937_1360:
    valueV1 = Actor1937Field(privateData, int*, 84);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
original1937_1363:
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(valueS0, valueV0);
    Actor1937Keep(valueS0);
    valueS1 = (int)&frame.fields.spE8;
    Actor1937Keep(valueS1);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    valueS0 = Actor1937Add(valueS0, 12);
    Actor1937Keep(valueS0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937CopyVector(argument0, argument1);
    argument0 = Actor1937Add(valueS1, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    valueV0 = Actor1937Field((int)&frame, volatile int*, 208);
    Actor1937Keep(valueV0);
    argument3 = (int)0x00040000U;
    Actor1937Keep(argument3);
    valueV0 = Actor1937Add(valueV0, 2048);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 208) = valueV0;
    stackArgument4 = 0;
    Actor1937_func_8001830C(argument0, argument1, argument2, argument3, stackArgument4);
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(valueV0);
original1937_1395:
    if (valueV0 != 0 ? (valueV0 = Actor1937Add(0, 23), 1) : (valueV0 = Actor1937Add(0, 23), 0))
        goto original1937_1401;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Add(0, 22);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1401:
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1403:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, -3);
    goto original1937_1417;
original1937_1410:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, 3);
    Actor1937Keep(valueV0);
original1937_1417:
    Actor1937Field(actor, unsigned char*, 70) = valueV0;
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14480);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 0);
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Add(0, 30);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1428:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 4);
    Actor1937Keep(argument1);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Add(0, 3328);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 216) = valueV0;
    Actor1937Field((int)&frame, int*, 220) = 0;
    Actor1937Field((int)&frame, int*, 224) = 0;
    Actor1937RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = Actor1937Add(actor, 32);
    Actor1937Keep(argument0);
    valueS0 = (int)&frame.fields.spF8;
    Actor1937Keep(valueS0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(actor, 12);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    Actor1937Field((int)&Actor1937_D_8006E160, int*, 0) = 0;
    argument1 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(argument1);
    argument3 = Actor1937Add(0, 65);
    Actor1937Keep(argument3);
    argument1 = Actor1937Add(argument1, 128);
    Actor1937Keep(argument1);
    argument1 = argument1 & 255;
    Actor1937_func_80013D44(argument0, argument1, argument2, argument3);
    valueV0 = Actor1937Add(0, 31);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    Actor1937Field(actor, int*, 24) = 0;
    goto original1937Return;
original1937_1461:
    valueV0 = (int)0x10000000U;
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -8120);
    Actor1937Keep(valueV1);
    valueV0 = valueV0 | 2;
    Actor1937Keep(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 524, int*, 0) = valueV0;
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(valueV0);
    if (valueV0 != 0)
        goto original1937_1489;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor1937Field(privateData, int*, 80);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    goto original1937_1492;
original1937_1489:
    valueV1 = Actor1937Field(privateData, int*, 84);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
original1937_1492:
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueS1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueS1);
    valueV0 = Actor1937Field(valueS1, unsigned char*, 72);
    Actor1937Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor1937Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = Actor1937Add(0, 28), 1) : (valueV0 = Actor1937Add(0, 28), 0))
        goto original1937_1511;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 5) = valueV0;
    valueV0 = Actor1937Add(0, 5);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    Actor1937Field(privateData, short*, 76) = 0;
    goto original1937Return;
original1937_1511:
    argument0 = Actor1937Add(actor, 32);
    Actor1937Keep(argument0);
    valueS0 = (int)&frame.fields.sp108;
    Actor1937Keep(valueS0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Field(actor, unsigned char*, 70);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument2);
    Actor1937Field(valueS1, unsigned char*, 70) = valueV0;
    valueV0 = Actor1937Add(0, 1664);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 232) = valueV0;
    Actor1937Field((int)&frame, int*, 236) = 0;
    Actor1937Field((int)&frame, int*, 240) = 0;
    Actor1937TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS1, 12);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(actor, 12);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS0, 0);
    Actor1937AddVector(argument0, argument1, argument2);
    valueV1 = Actor1937Add(0, 1);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 28);
    Actor1937Keep(valueV0);
    Actor1937Field(valueS1, unsigned char*, 72) = valueV1;
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Add(0, 5);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    valueV0 = Actor1937Add(0, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 5) = valueV1;
    Actor1937Field(privateData, short*, 76) = valueV0;
    goto original1937Return;
original1937_1536:
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -7356);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 15);
    Actor1937Keep(valueV0);
    valueS0 = (int)0x10000000U;
    if (valueV1 == valueV0)
        goto original1937Return;
    MATCHING_OBSERVE_VOLATILE(valueS0);
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueS1 = (int)&Actor1937_D_80070328 + 524;
    Actor1937Keep(valueS1);
    valueV0 = Actor1937Field(valueS1, int*, 0);
    Actor1937Keep(valueV0);
    valueS0 = valueS0 | 2;
    Actor1937Keep(valueS0);
    valueV0 = valueV0 & valueS0;
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(privateData, 76);
    if (valueV0 == valueS0)
        goto original1937_1552;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueS0);
    argument1 = Actor1937Add(0, 2);
    valueV0 = Actor1937CountTimerDown(argument0, argument1);
    if (valueV0 != 0)
        goto original1937_1554;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_1552:
    Actor1937Field(valueS1, int*, 0) = valueS0;
    goto original1937Return;
original1937_1554:
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    argument1 = (int)0x80070000U;
    Actor1937Keep(argument1);
    argument1 = Actor1937Field(argument1, int*, -15024);
    Actor1937Keep(argument1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    savedWord30 = Actor1937Add(argument1, valueV0);
    Actor1937Keep(savedWord30);
    valueV1 = Actor1937Field(privateData, int*, 120);
    Actor1937Keep(valueV1);
    valueS5 = Actor1937Field(savedWord30, int*, 0);
    Actor1937Keep(valueS5);
    argument0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(argument0);
    argument0 = Actor1937Add(argument0, valueV1);
    Actor1937Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor1937Keep(argument0);
    argument0 = Actor1937Sub(argument0, valueV1);
    Actor1937Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor1937Keep(argument0);
    argument0 = Actor1937Add(argument0, argument1);
    Actor1937Keep(argument0);
    argument1 = Actor1937Sub(actor, argument1);
    Actor1937Keep(argument1);
    valueV0 = (int)((unsigned int)argument1 << 5);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, argument1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 5);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument1);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 15);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Sub(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, argument1);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Sub(0, valueV1);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(argument0, int*, 0);
    Actor1937Keep(valueV0);
    valueV1 = (valueV1 >> 3);
    Actor1937Keep(valueV1);
    Actor1937Field(valueV0, unsigned char*, 3) = valueV1;
    valueV1 = Actor1937Field(valueV0, short*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV1 != valueV0)
        goto original1937_1627;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueS0 = Actor1937Add(actor, 72);
    Actor1937Keep(valueS0);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    valueS3 = (int)&Actor1937_D_8006D088;
    Actor1937Keep(valueS3);
    argument2 = Actor1937Add(valueS3, 0);
    Actor1937Keep(argument2);
    valueT0 = Actor1937Add(0, 1);
    Actor1937Keep(valueT0);
    valueS4 = Actor1937Add(0, 2);
    Actor1937Keep(valueS4);
    valueS2 = Actor1937Add(0, 54);
    Actor1937Keep(valueS2);
    Actor1937Field(privateData, unsigned char*, 5) = valueT0;
    Actor1937Field(privateData, unsigned char*, 2) = valueS4;
    Actor1937Field(actor, unsigned char*, 72) = valueS2;
    Actor1937_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    valueS1 = (int)&Actor1937_D_8006C7F8;
    Actor1937Keep(valueS1);
    argument2 = Actor1937Add(valueS1, 0);
    Actor1937_func_8003B7B4(argument0, argument1, argument2);
    valueS0 = Actor1937Add(savedWord30, 72);
    Actor1937Keep(valueS0);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS3, 0);
    Actor1937Keep(argument2);
    valueV0 = Actor1937Add(0, 33);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    __asm__ volatile("" ::"m"(Actor1937Field(actor, unsigned char*, 72)));
    valueT0 = Actor1937Add(0, 1);
    Actor1937Keep(valueT0);
    Actor1937Field(valueS5, unsigned char*, 5) = valueT0;
    Actor1937Field(valueS5, unsigned char*, 2) = valueS4;
    Actor1937Field(savedWord30, unsigned char*, 72) = valueS2;
    Actor1937_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 1);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(valueS1, 0);
    Actor1937_func_8003B7B4(argument0, argument1, argument2);
    valueV0 = Actor1937Add(0, 35);
    Actor1937Keep(valueV0);
    Actor1937Field(savedWord30, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1627:
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 1);
    Actor1937Keep(argument2);
    valueV0 = Actor1937Add(0, 38);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937_1670;
original1937_1632:
    valueV1 = Actor1937Field(actor, unsigned char*, 61);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 6);
    Actor1937Keep(valueV0);
    valueS0 = Actor1937Add(0, 0);
    if (valueV1 == valueV0)
        goto original1937_1789;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Field(actor, int*, 24);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937_1642;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 6);
    Actor1937SetMobyAnimation(argument0, argument1);
original1937_1642:
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    if (valueV1 < 0)
        goto original1937_1654;
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueS0 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueS0);
original1937_1654:
    valueV0 = Actor1937Add(0, 5);
    if (valueS0 == 0)
        goto original1937_1662;
    MATCHING_KEEP_VOLATILE(valueS0);
    valueV0 = Actor1937Field(valueS0, unsigned char*, 2);
    Actor1937Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 2;
    Actor1937Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = Actor1937Add(0, 5), 1) : (valueV0 = Actor1937Add(0, 5), 0))
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_1662:
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    valueV0 = Actor1937_func_80037BBC(argument0, argument1);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 1);
    Actor1937Keep(argument2);
original1937_1670:
    Actor1937_func_800512E4(argument0, argument1, argument2);
    valueV0 = Actor1937Add(0, 29);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1675:
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -7356);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = Actor1937Add(0, 3), 1) : (valueV0 = Actor1937Add(0, 3), 0))
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    Actor1937Field(actor, int*, 24) = 0;
    valueV1 = Actor1937Field(privateData, unsigned char*, 2);
    Actor1937Keep(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = Actor1937Add(0, 38), 1)
                           : (valueV0 = Actor1937Add(0, 38), 0))
        goto original1937_1688;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor1937Add(0, 25);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1688:
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Add(0, 5);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    Actor1937Field(privateData, unsigned char*, 5) = 0;
    goto original1937Return;
original1937_1693:
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueS1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueS1);
    valueV1 = Actor1937Field(valueS1, int*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Field(valueV1, unsigned char*, 2);
    Actor1937Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 2;
    Actor1937Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = Actor1937Add(0, 1), 1) : (valueV0 = Actor1937Add(0, 1), 0))
        goto original1937_1762;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(valueV1, unsigned char*, 2) = valueV0;
    Actor1937Field(valueV1, unsigned char*, 5) = valueV0;
    Actor1937Field((int)&Actor1937_D_8006E160, int*, 0) = 0;
    valueV1 = Actor1937Field(valueS1, int*, 0);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV1, unsigned char*, 5) = valueV0;
    valueV0 = Actor1937Field(valueS1, unsigned char*, 70);
    Actor1937Keep(valueV0);
    valueS0 = (int)&frame.fields.sp118;
    Actor1937Keep(valueS0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(((int)((unsigned int)&Actor1937_D_80065920 + (unsigned int)valueV0)),
                             short*, 0);
    Actor1937Keep(valueV1);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (valueV0 >> 5);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 248) = valueV0;
    valueV0 = Actor1937Field(valueS1, unsigned char*, 70);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Field(((int)((unsigned int)&Actor1937_D_800658A0 + (unsigned int)valueV0)),
                             short*, 0);
    Actor1937Keep(valueV1);
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 876);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(valueS1, 12);
    Actor1937Keep(argument2);
    Actor1937Field((int)&frame, int*, 256) = 0;
    __asm__ volatile("" ::"m"(Actor1937Field((int)&frame, int*, 256)));
    Actor1937Field((int)&frame, int*, 256) = valueV0;
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (valueV0 >> 5);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 252) = valueV0;
    Actor1937AddVector(argument0, argument1, argument2);
    argument0 = Actor1937Add(valueS0, 0);
    Actor1937Keep(argument0);
    argument2 = Actor1937Add(0, 0);
    Actor1937Keep(argument2);
    argument1 = Actor1937Field(valueS1, unsigned char*, 70);
    Actor1937Keep(argument1);
    argument3 = Actor1937Add(0, 65);
    Actor1937Keep(argument3);
    argument1 = Actor1937Add(argument1, 128);
    Actor1937Keep(argument1);
    argument1 = argument1 & 255;
    Actor1937_func_80013D44(argument0, argument1, argument2, argument3);
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 1448);
    Actor1937Keep(valueV0);
    if (valueV0 >= 0 ? (valueV0 = Actor1937Add(0, 38), 1) : (valueV0 = Actor1937Add(0, 38), 0))
        goto original1937_1763;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field((int)&Actor1937_D_80070328 + 640, int*, 0) = 0;
original1937_1762:
    valueV0 = Actor1937Add(0, 38);
    Actor1937Keep(valueV0);
original1937_1763:
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1937Add(0, 5);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 5) = 0;
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    goto original1937Return;
original1937_1768:
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    argument2 = Actor1937Add(0, 1);
    Actor1937_func_800512E4(argument0, argument1, argument2);
    valueV0 = Actor1937Add(0, 34);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1775:
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -7356);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV1 == valueV0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument1 = Actor1937Add(0, 0);
    Actor1937RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor1937Add(0, 35);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 72) = valueV0;
    goto original1937Return;
original1937_1785:
    valueV1 = Actor1937Field(actor, unsigned char*, 61);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 6);
    Actor1937Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1937_1799;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
original1937_1789:
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14480);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, int*, 24) = 0;
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
original1937_1794:
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    argument1 = Actor1937Add(0, 0);
    Actor1937RequestMobyAnimation(argument0, argument1);
    goto original1937Return;
original1937_1799:
    valueV0 = Actor1937Field(actor, int*, 24);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor1937Add(0, 6);
    Actor1937SetMobyAnimation(argument0, argument1);
    goto original1937Return;
original1937_1807:
    valueV0 = Actor1937Field(privateData, int*, 92);
    Actor1937Keep(valueV0);
    if (valueV0 == 0)
        goto original1937_1813;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1937Field(valueV0, unsigned char*, 16) = 0;
    Actor1937Field(privateData, int*, 92) = 0;
original1937_1813:
    argument0 = Actor1937Add(actor, 0);
    Actor1937DeleteMoby(argument0);
    goto original1937Return;
original1937_1817:
    valueV0 = (int)0x80070000U;
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, -14480);
    Actor1937Keep(valueV0);
    argument2 = Actor1937Add(0, 0);
    if (valueV0 == 0)
        goto original1937Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor1937Field(privateData, int*, 116);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(((int)((unsigned int)&Actor1937_D_80065920 + (unsigned int)valueV0)),
                             short*, 0);
    Actor1937Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueV1 = (valueV1 >> 5);
    Actor1937Keep(valueV1);
    Actor1937Field((int)&frame, int*, 264) = valueV1;
    valueV0 = Actor1937Field(privateData, int*, 116);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Field(((int)((unsigned int)&Actor1937_D_800658A0 + (unsigned int)valueV0)),
                               short*, 0);
    Actor1937Keep(argument0);
    valueV0 = (int)((unsigned int)argument0 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument0);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, argument0);
    Actor1937Keep(valueV0);
    valueV0 = (valueV0 >> 5);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 268) = valueV0;
    argument1 = Actor1937Field(privateData, int*, 96);
    Actor1937Keep(argument1);
    valueV1 = Actor1937Add(valueV1, argument1);
    Actor1937Keep(valueV1);
    Actor1937Field((int)&frame, int*, 264) = valueV1;
    valueV1 = Actor1937Field(privateData, int*, 100);
    Actor1937Keep(valueV1);
    argument3 = Actor1937Add(0, 65);
    Actor1937Keep(argument3);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    Actor1937Field((int)&frame, int*, 268) = valueV0;
    valueV0 = Actor1937Field(privateData, int*, 104);
    Actor1937Keep(valueV0);
    argument0 = (int)&frame.fields.sp128;
    Actor1937Keep(argument0);
    Actor1937Field((int)&frame, int*, 272) = valueV0;
    argument1 = Actor1937Field(privateData, int*, 116);
    Actor1937Keep(argument1);
    valueV0 = Actor1937Add(0, 2);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 5) = valueV0;
    __asm__ volatile("" ::"m"(Actor1937Field(privateData, unsigned char*, 5)));
    argument1 = Actor1937Add(argument1, 128);
    Actor1937Keep(argument1);
    argument1 = argument1 & 255;
    Actor1937_func_80013D44(argument0, argument1, argument2, argument3);
    valueV0 = Actor1937Field(actor, short*, 54);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(0, 50);
    Actor1937Keep(valueV1);
    Actor1937Field(actor, unsigned char*, 72) = valueV1;
    goto original1937_1911;
original1937_1869:
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -8120);
    Actor1937Keep(valueV1);
    valueV0 = Actor1937Add(0, 1);
    Actor1937Keep(valueV0);
    argument0 = Actor1937Add(actor, 12);
    if (valueV1 != valueV0)
        goto original1937_1910;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV1 = Actor1937Field(privateData, int*, 52);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Sub(valueV0, valueV1);
    Actor1937Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1937Keep(valueV1);
    valueV1 = Actor1937Field(valueV1, int*, -15024);
    Actor1937Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(valueV1, valueV0);
    Actor1937Keep(valueV1);
    valueS0 = Actor1937Field(valueV1, int*, 0);
    Actor1937Keep(valueS0);
    argument1 = Actor1937Add(privateData, 96);
    Actor1937CopyVector(argument0, argument1);
    Actor1937Keep(actor);
    argument0 = Actor1937Add(actor, 0);
    Actor1937Keep(argument0);
    valueV0 = Actor1937Field(privateData, int*, 116);
    Actor1937Keep(valueV0);
    argument1 = Actor1937Add(0, 0);
    Actor1937Keep(argument1);
    Actor1937Field(actor, unsigned char*, 70) = valueV0;
    valueV0 = Actor1937Add(0, 6);
    Actor1937Keep(valueV0);
    Actor1937Field(privateData, unsigned char*, 2) = valueV0;
    Actor1937SetMobyAnimation(argument0, argument1);
    Actor1937Field(actor, unsigned char*, 72) = 0;
    Actor1937Field(actor, unsigned char*, 73) = 0;
    Actor1937Field(actor, int*, 24) = 0;
    valueV0 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueV0);
    valueV1 = Actor1937Add(0, 1);
    Actor1937Keep(valueV1);
    Actor1937Field(privateData, int*, 48) = 0;
    Actor1937Field(valueV0, short*, 10) = valueV1;
    valueV0 = Actor1937Field(privateData, int*, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV0, short*, 2) = valueV1;
    valueV0 = Actor1937Field(valueS0, int*, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(valueS0, int*, 48) = 0;
    Actor1937Field(valueV0, short*, 10) = valueV1;
    valueV0 = Actor1937Field(valueS0, int*, 60);
    Actor1937Keep(valueV0);
    Actor1937Field(valueV0, short*, 2) = valueV1;
    goto original1937Return;
original1937_1910:
    valueV0 = Actor1937Field(actor, short*, 54);
    Actor1937Keep(valueV0);
original1937_1911:
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(((int)((unsigned int)&Actor1937_D_8006EE2C + (unsigned int)valueV0)),
                             int*, 0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, int*, 80);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Field(valueV0, unsigned char*, 0);
    Actor1937Keep(valueV0);
    valueV0 = Actor1937Add(valueV0, -1);
    Actor1937Keep(valueV0);
    Actor1937Field(actor, unsigned char*, 62) = valueV0;
original1937_1923:
    Actor1937Field(actor, unsigned char*, 63) = valueV0;
original1937Return:
    return;
}
#undef Actor1937Field
#undef Actor1937Keep
#undef Actor1937Add
#undef Actor1937Sub

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 800886E4..80088A34. Original damage word is owner+24; no new
 * interpretation of factory results, global producers or cadence. */
extern unsigned char DecodedSpooky110Player[] __asm__("D_80070328");
extern int D_8006C578, D_8006C574, D_8006C7C4;
extern int D_8006E020, D_8006E024, D_8006E1D8, D_8006E1D4;
extern unsigned short DecodedSpooky110Angle __asm__("D_8006E040");
void func_level_23_800886E4(Moby* argument) {
    register Moby* moby __asm__("$17") = argument;
    register unsigned char* tag __asm__("$19") = moby->mobyTag;
    register Moby* child __asm__("$16");
    register int index __asm__("$18"), one __asm__("$20"), two __asm__("$21");
    Vector3D offset;
    if (moby->substate == 10)
        moby->damageFlags = 0;
    else
        moby->substate = 2;
    child = 0;
    if (moby->damageFlags) {
        {
            register Moby* callOwner __asm__("$4") = moby;
            register int modelMode __asm__("$5") = 4;
            register unsigned int yaw __asm__("$2");
            MATCHING_KEEP2(callOwner, modelMode);
            index = 0;
            one = 1;
            yaw = DecodedSpooky110Player[14];
            two = 2;
            moby->angle.yaw = yaw;
            func_80055D24(callOwner, modelMode);
        }
        MATCHING_KEEP3(index, one, two);
        do {
            if (D_8006C578 - D_8006C574 < 21)
                goto last_child;
            child = SpawnMoby(8, moby);
            if (child) {
                register int value __asm__("$2");
                child->size = 44;
                child->lowDrawDistance = 63;
                child->updateDistance = 255;
                child->angle.yaw = DecodedSpooky110Player[14];
                if (index == one)
                    goto second;
                if (index < 2) {
                    if (index == 0)
                        goto first;
                    else
                        goto translate;
                } else {
                    if (index == two)
                        goto third;
                    else
                        goto translate;
                }
            first:
                value = 422;
                offset.x = value;
                value = 50;
                offset.y = value;
                value = 384;
                goto common;
            second:
                value = -140;
                offset.y = value;
                value = 1024;
                offset.x = 0;
                offset.z = value;
                child->animationState.id = two;
                goto translate;
            third:
                value = 10;
                offset.x = value;
                value = -328;
                offset.y = value;
                value = 512;
            common:
                offset.z = value;
                child->animationState.id = one;
            translate:
                func_8004F194(&child->position, &child->position, &offset);
            }
            index++;
        } while (index < 3);
    last_child:
        if (child)
            func_8003BABC(child, 0, 0);
        func_800369B8(moby, 100);
        if (!*(short*)(tag + 18))
            goto remove;
        moby->updateDistance = 255;
        moby->damageFlags = 0;
        *(short*)(tag + 16) = 0;
        *(int*)(tag + 12) = 500;
        moby->lowDrawDistance = 0;
        moby->position.z += 16384;
        if (D_8006C7C4 == 2)
            goto resume;
    remove:
        func_80055B18(moby);
        return;
    resume:
        moby->state = 2;
    }
    if (moby->state == 2) {
        if (func_800359A4(tag + 12, 4)) {
            moby->state = 1;
            moby->lowDrawDistance = 32;
        }
    } else if (moby->state == 1) {
        moby->position.z -= *(short*)(tag + 16);
        if (*(short*)(tag + 16) < 650)
            *(short*)(tag + 16) += 16;
        if (moby->position.z <= *(int*)(tag + 8)) {
            if (func_8004F264((int)(DecodedSpooky110Angle << 16) >> 20,
                              func_8004E880(moby->position.x - D_8006E020,
                                            moby->position.y - D_8006E024, 0)) < 16 &&
                func_8004F334(&moby->position, (Vector3D*)DecodedSpooky110Player) < 10240) {
                D_8006E1D8 = 20;
                D_8006E1D4 = 4096;
            }
            func_8003BABC(moby, 0, 0);
            func_800369B8(moby, 40);
            {
                register int z __asm__("$3") = *(int*)(tag + 8);
                MATCHING_KEEP(z);
                moby->state = 0;
                moby->updateDistance = 32;
                moby->position.z = z;
            }
        }
        func_80055D24(moby, 4);
    }
}

void func_80034F80(Moby*, int);
void func_level_23_80088A34(Moby* moby) {
    if (moby->substate == 0) {
        int animation = moby->state;
        moby->substate = 1;
        moby->unknown4 = 1;
        func_80034F80(moby, animation);
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level23 0x80088A6C..0x80088DAC: 208 instructions and seven owned
 * switch words at 0x80074C08. Original signed-byte products, byte masks,
 * 32-bit sums, post-call rereads and shared helper tail preserved.
 * Field offsets describe storage; units, helper contracts and caller cadence
 * remain unresolved. Empty constraints emit no CPU instructions.
 * Acceptance requires original linked code/table words and all retail hashes.
 */
#define P88A6CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Spyro P88A6C_D_80070328 __asm__("D_80070328");
void P88A6CRefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
int P88A6CCountTimerDown(void* pTimer, int pTimerType) __asm__("func_800359A4");
int P88A6CPlayMobySoundEvent(Moby* owner, int index, int selector) __asm__("func_8003BABC");
void func_level_23_80088A6C(Moby* argument) {
    register Moby* owner __asm__("$16") = argument;
    register int maskedState __asm__("$3");
    int difference12;
    register int initialFlags __asm__("$5"), remaining __asm__("$2"), stateThree __asm__("$2");
    int word14;
    register int updated14 __asm__("$2");
    register int stateWork __asm__("$4");
    unsigned char byte0;
    unsigned char byte2;
    register int dispatchState __asm__("$3");
    register int nextSubstate __asm__("$2");
    register void* privateState __asm__("$17");

    MATCHING_KEEP(owner);
    privateState = owner->mobyTag;
    if (owner->substate == 0) {
        initialFlags = 0x80000800;
        MATCHING_KEEP(initialFlags);
        owner->substate = 1;
        owner->unknown4 = 0;
        *(int*)((unsigned char*)owner + 0x54) = owner->position.z + initialFlags;
        P88A6CField(privateState, int*, 4) = (int)owner->position.z;
        owner->position.z += 0x12C;
        P88A6CRefreshMobySpatialGridAndBasis(argument, 4);
    }
    if (owner->substate == 0xA) {
        owner->damageFlags = 0;
    }
    stateWork = owner->state;
    stateThree = 3;
    __asm__("" : "=r"(stateWork) : "0"(stateWork), "r"(stateThree));
    maskedState = stateWork & 0xFF;
    if ((maskedState == 3) || (maskedState == 0) || ((unsigned int)(stateWork - 5) < 2U)) {
        MATCHING_OBSERVE(stateWork);
        if (owner->damageFlags & 0x20000) {
            P88A6CPlayMobySoundEvent(owner, 0, 0);
            owner->state = 5;
            byte2 = P88A6CField(privateState, unsigned char*, 2);
            P88A6CField(privateState, signed char*, 3) = 1;
            P88A6CField(privateState, unsigned char*, 0) = 0x8CU;
            if (byte2 != 0) {
                P88A6CField(privateState, unsigned char*, 2) = (unsigned char)(byte2 - 1);
            }
            owner->position.z = P88A6CField(privateState, int*, 4) +
                                (P88A6CField(privateState, unsigned char*, 2) << 0xA) + 0x12C;
            P88A6CRefreshMobySpatialGridAndBasis(owner, 4);
        }
    }
    dispatchState = owner->state;
    owner->damageFlags = 0;
    switch (dispatchState) {
        case 0:
        case 1:
        case 2:
            if ((P88A6CField(privateState, unsigned char*, 0) != 0) && (D_8006C7C4 != 0) &&
                (P88A6CCountTimerDown(privateState, 1) != 0)) {
                P88A6CPlayMobySoundEvent(owner, 1, 0);
                owner->state = 6;
                P88A6CField(privateState, unsigned char*, 0) = 0x80U;
            }
            break;
        case 5:
            if (P88A6CCountTimerDown(privateState, 1) != 0) {
                P88A6CField(privateState, unsigned char*, 0) = 0xFAU;
                owner->state = 0;
            }
            break;
        case 6:
            owner->position.z += P88A6CField(privateState, signed char*, 3) * 0x1E;
            P88A6CField(privateState, signed char*, 3) = (signed char)-(
                signed char)(unsigned char)P88A6CField(privateState, signed char*, 3);
            if (P88A6CCountTimerDown(privateState, 1) != 0) {
                difference12 = P88A6CField(privateState, unsigned char*, 1) -
                               P88A6CField(privateState, unsigned char*, 2);
                if ((*(Moby**)((unsigned char*)(&P88A6C_D_80070328) + 0x13C)) == owner) {
                    (*(int*)((unsigned char*)(&P88A6C_D_80070328) + 0x20C)) = 0x10000080;
                    (*(int*)((unsigned char*)(&P88A6C_D_80070328) + 0x23C)) = 0x49;
                }
                P88A6CField(privateState, unsigned char*, 2) =
                    (unsigned char)(P88A6CField(privateState, unsigned char*, 2) + difference12);
                owner->state = difference12 + 2;
                P88A6CField(privateState, unsigned char*, 0) = 4U;
                P88A6CField(privateState, signed char*, 3) = 1;
            }
            goto refreshOwner;
        case 3:
        case 4:
            if (owner->state == 3) {
                updated14 = owner->position.z + 0x100;
            } else {
                updated14 = owner->position.z + 0x1B5;
            }
            owner->position.z = updated14;
            __asm__("" : : : "$2", "memory");
            if ((*(Moby**)((unsigned char*)(&P88A6C_D_80070328) + 0x13C)) == owner) {
                (*(int*)((unsigned char*)(&P88A6C_D_80070328) + 0x20C)) = 0x10000080;
                (*(int*)((unsigned char*)(&P88A6C_D_80070328) + 0x23C)) = 0x49;
            }
            byte0 = P88A6CField(privateState, unsigned char*, 0) - 1;
            P88A6CField(privateState, unsigned char*, 0) = byte0;
            if (!(byte0 & 0xFF)) {
                word14 = P88A6CField(privateState, int*, 4) +
                         (P88A6CField(privateState, unsigned char*, 2) << 0xA);
                if (P88A6CField(privateState, unsigned char*, 1) == 1) {
                    word14 += 0x12C;
                }
                owner->position.z = word14;
                owner->state = 0;
                P88A6CField(privateState, unsigned char*, 0) = 0U;
            }
        refreshOwner:
            P88A6CRefreshMobySpatialGridAndBasis(owner, 4);
            break;
    }
    if (owner->substate == 0xA) {
        owner->damageFlags = 0;
        return;
    }
    remaining = P88A6CField(privateState, unsigned char*, 2);
    MATCHING_KEEP(remaining);
    if (remaining != 0)
        nextSubstate = 2;
    else
        nextSubstate = 3;
    owner->substate = nextSubstate;
}
#undef P88A6CField


extern Moby* D_8006C550;
void func_80055B18(Moby*);
void func_level_23_80088DAC(Moby* moby) {
    int* tag = moby->mobyTag;
    if (moby->state == 2) {
        if (*tag >= 0)
            func_80055B18(&D_8006C550[*tag]);
        func_80055B18(moby);
    } else if (moby->state == 0) {
        func_80039714(moby);
    } else if (moby->damageFlags & 0x40000) {
        unsigned char* state = &moby->state;
        moby->state = 2;
        func_8003B7B4(state, 1, &savedData);
        func_8003B7B4(state, 1, &unsavedData);
        func_800391E8(4, 0xB1, moby, 1, 4, 0xC8, 0x100);
        func_80055D24(moby, 4);
        func_8003BA00(moby);
        func_800369B8(moby, 0x28);
        func_80055B18(moby);
    }
}

typedef struct {
    unsigned char reserved00[0xC];
    Vector3D* position;
} DecodedDialogueCameraRecord;
typedef struct {
    unsigned char reserved00, gateIndex, phase, reserved03, response, active;
    unsigned char reserved06[0x26];
    DecodedDialogueCameraRecord* camera;
    int targetIndex;
} DecodedDialogueCameraTag;
extern short DecodedDialogueCameraThreshold[] __asm__("D_80066EAC");
extern short DecodedDialogueCameraPaid[] __asm__("D_80066EAE");
extern unsigned char DecodedDialogueCameraLevel __asm__("D_80066FCC + 0x2F");
extern unsigned char DecodedDialogueCameraLevelFlags[] __asm__("D_80070300");
extern int DecodedDialogueCameraPlayerGate __asm__("D_80070328 + 0x240");
extern int D_8006C640, D_8006C71C, D_8006E344, D_8006E048;
extern unsigned char D_80071584;
int DecodedDialogueCameraQuery(Moby*, int) __asm__("func_80037BBC");
void DecodedDialogueCameraBegin(Moby*, int, int) __asm__("func_800512E4");
void DecodedDialogueCameraTarget(int, int, int) __asm__("func_80021ED8");
int DecodedDialogueCameraTargetState(int) __asm__("func_80021F3C");
int DecodedDialogueCameraSound(Moby*, int, int) __asm__("func_8003BB10");
extern Vector3D DialogueTarget __asm__("D_8006E17C");
extern int DialogueOverride __asm__("D_8006E160");
void DialogueUpdateTarget(int, int, int) __asm__("func_80021F8C");
void DialogueCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DialogueSetup(void*, Vector3D*, Vector3D*) __asm__("func_800136F0");
/* SCUS-94467 USA Rev0 80088ED4..80089174, 169 original words.
 * Reuses verified func_level_34_80080384. Original differences include
 * paid-table index2, ordered target/update helpers before removal, direct
 * camera-record dereference, E17C vector copy/E168 setup and override17,
 * unconditional state90 calls and state91 override clear.
 * Raw widths, numeric selectors and post-helper reads remain retail.
 * Units, complete producer/helper semantics and caller cadence remain open.
 * Empty constraints preserve compiler allocation and emit no instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1705.
 */
void func_level_23_80088ED4(Moby* moby) {
    register DecodedDialogueCameraTag* tag __asm__("$18") = moby->mobyTag;
    register Moby* callMoby __asm__("$4");
    register int animation __asm__("$5");
    int gate;
    if (D_8006C640 < 10 && (DecodedDialogueCameraPaid[2] ||
                            (DecodedDialogueCameraLevelFlags[DecodedDialogueCameraLevel] & 1))) {
        DecodedDialogueCameraTarget(tag->targetIndex, 0xFC, 0);
        DialogueUpdateTarget(tag->targetIndex, 0x3A, 0);
        moby->substate = 1;
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
        case 0:
            gate = tag->gateIndex & 0x7F;
            if (gate != 0x7F && D_8006C71C >= DecodedDialogueCameraThreshold[gate * 2] &&
                !DecodedDialogueCameraPaid[gate * 2]) {
                tag->active = 1;
                tag->gateIndex = 0xFF;
            }
            if (!DecodedDialogueCameraPlayerGate && D_8006E344 != 1 &&
                DecodedDialogueCameraQuery(moby, 0)) {
                DecodedDialogueCameraBegin(moby, 0, 1);
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            break;
        case 1:
            D_80071584 = 1;
            if (D_8006E344 != 1) {
                if (tag->response == 1) {
                    func_80034F40(moby, 0);
                    {
                        register Vector3D* target __asm__("$16") = &DialogueTarget;
                        DialogueCopy(target, (Vector3D*)((char*)tag->camera->position + 0x10));
                        DialogueSetup((char*)target - 0x14, tag->camera->position,
                                      (Vector3D*)((char*)tag->camera->position + 0x10));
                        DialogueOverride = 17;
                        moby->state = 90;
                        break;
                    }
                }
                callMoby = moby;
                __asm__("" : "=r"(moby) : "0"(moby), "r"(callMoby));
                moby->state = 0;
                __asm__ volatile("" : :);
                animation = 0;
                goto animateZero;
            }
            break;
        case 90:
            DecodedDialogueCameraTarget(tag->targetIndex, 0xFC, 0);
            DecodedDialogueCameraSound(moby, 2, 0);
            moby->substate = 1;
            moby->state = 91;
            break;
        case 91:
            if (DecodedDialogueCameraTargetState(tag->targetIndex) & 2) {
                callMoby = moby;
                animation = 0;
                MATCHING_KEEP2(callMoby, animation);
                DialogueOverride = 0;
                callMoby->state = 0;
            animateZero:
                func_80034F40(callMoby, animation);
            }
            break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_23/moby", D_level_23_80074C24);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80089178.
* Assembly SHA256 aec3cabf6913d26f4661c1163a608b98e07011989b8188c808b7b18f336eae59.
* AI generated;not human reviewed. All746 instructions,23 selectors,one
* zero padding word and every actual native/linked target must match.
* FrameC8 preserves S0..S4/RA and the full SP20..AF local extent. Original
* unowned table4C24 remains unchanged:12000/11000/10000. Its SP20/24/28
* copy and owned table4C30's SP30/34/38 copy retain all original producers.
* Owned4C30 is exactly16 bytes:500000005F0000007800000000000000,including
* the original fourth zero word. Both indexed consumers add original byte
* offsets. The decoder omitted these initial copies;C restores them.
* All three full signed low-product paths retain original MULT/MFLO words,
* vector stores,raw sums,conditional targets and64/192 masked consumers.
* No partial product or HI/LO constraint is used. Independent state22
* metadata prevents the compiler merging its original product branch.
* State1's V0=2/A1=2 J enters state2's shared state2/3 store. Callback-zero
* path produces V0=1 in its branch delay and skips the later producer;
* the original store remains after its J with an original NOP delay.
* Returned S0 values,A0 preparations,post-E84 pointer read and state4's
* single byte32/A1-zero producer order remain exact. Empty initialized
* identities,late inputs and dead clobbers emit zero instructions. No
* opcode assembly,fixedFP or overlapping live fixed aliases. Confidence
* is binary identity after all gates. Raw units/fixed point,full helper
* contracts,caller cadence and synchronized runtime remain open. Cadence
* recorded here is per invocation. Falsification:every native/linked word,
* actual transfer/table target,both original data sources,full EXE and
* every overlay retail hash. */
#define Actor23_89178Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int Actor23_89178ExistingTableWords __asm__("D_level_23_80074C24");
const int Actor23_89178OriginalTableWords[4] __asm__("D_level_23_80074C30") = {80, 95, 120, 0};
int Actor23_89178Call1BA30View1() __asm__("func_8001BA30");
int Actor23_89178RequestMobyAnimationView1() __asm__("func_80034F40");
int Actor23_89178SetMobyAnimationView1() __asm__("func_80034F80");
int Actor23_89178Call35030View1() __asm__("func_80035030");
int Actor23_89178TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Actor23_89178TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor23_89178CountTimerDownView1() __asm__("func_800359A4");
int Actor23_89178Call35DDCView1() __asm__("func_80035DDC");
int Actor23_89178Call360F8View1() __asm__("func_800360F8");
int Actor23_89178RandBetweenView1() __asm__("func_8003636C");
int Actor23_89178Call369B8View1() __asm__("func_800369B8");
int Actor23_89178PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor23_89178TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Actor23_89178MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Actor23_89178ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Actor23_89178CopyVectorView1() __asm__("func_8004F178");
int Actor23_89178AddVectorView1() __asm__("func_8004F194");
int Actor23_89178AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor23_89178ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor23_89178DeleteMobyView1() __asm__("func_80055B18");
int Actor23_89178RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor23_89178Call55E84View1() __asm__("func_80055E84");
int Actor23_89178InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Actor23_89178Data6C770View1 __asm__("D_8006C770");
extern int Actor23_89178Data6C7C4View1 __asm__("D_8006C7C4");
extern int Actor23_89178Data70328View1 __asm__("D_80070328");
extern int Actor23_89178Data7190CView1 __asm__("D_8007190C");
extern int Actor23_89178Data71910View1 __asm__("D_80071910");
extern int (*Actor23_89178Data74414View1)() __asm__("unk_ovlheader_80074414");
void func_level_23_80089178(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int addressOrResult16 __asm__("$16"), privateRecord18 __asm__("$18"),
        retainedAddressOrBase19 __asm__("$19"), retainedResult20 __asm__("$20");
    register int argumentWord6 __asm__("$6"), firstLowProduct7 __asm__("$7"),
        secondLowProduct9 __asm__("$9");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC;
    } originalFrame;
    int temporaryWord5;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord6;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    privateRecord18 = Actor23_89178Field(ownerRecord17, int*, 0);
    MATCHING_KEEP_CLOBBER(privateRecord18, "$5");
    argumentWord5 = (int)&Actor23_89178ExistingTableWords;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Actor23_89178Field(argumentWord5, volatile int*, 0);
    rawWord3 = Actor23_89178Field(argumentWord5, volatile int*, 4);
    argumentWord4 = Actor23_89178Field(argumentWord5, volatile int*, 8);
    originalFrame.sp20 = rawWord2;
    originalFrame.sp24 = rawWord3;
    originalFrame.sp28 = argumentWord4;
    __asm__ __volatile__("" ::: "$5", "memory");
    argumentWord5 = (int)Actor23_89178OriginalTableWords;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Actor23_89178Field(argumentWord5, volatile int*, 0);
    rawWord3 = Actor23_89178Field(argumentWord5, volatile int*, 4);
    argumentWord4 = Actor23_89178Field(argumentWord5, volatile int*, 8);
    originalFrame.sp30 = rawWord2;
    originalFrame.sp34 = rawWord3;
    originalFrame.sp38 = argumentWord4;
    temporaryWord6 = ownerRecord17 + 0xC;
    if ((unsigned int)(Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) - 5) >= 3U) {
        if (Actor23_89178Field(ownerRecord17, int*, 0x18) != 0) {
            addressOrResult16 = Actor23_89178Field(ownerRecord17, void**, 0);
            Actor23_89178Field(ownerRecord17, unsigned char*, 0x4A) = 255;
            Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 5U;
            Actor23_89178SetMobyAnimationView1(ownerRecord17, 5);
            rawWord2 = Actor23_89178Field(ownerRecord17, int*, 0x18);
            rawWord3 = 0x10000;
            rawWord2 &= rawWord3;
            if (!rawWord2) {
                rawWord2 = 300;
            } else {
                rawWord2 = 180;
            }
            Actor23_89178Field(addressOrResult16, int*, 8) = rawWord2;
            Actor23_89178Field(addressOrResult16, int*, 0) = 0x96;
            rawWord2 = Actor23_89178Field(ownerRecord17, unsigned char*, 0x51);
            argumentWord6 = 0;
            if (rawWord2 == 0) {
                MATCHING_BARRIER_GNU_VOLATILE("$2");
                rawWord2 = Actor23_89178Call360F8View1(
                    Actor23_89178PlanarHeadingLookupView1(
                        Actor23_89178Field(ownerRecord17, int*, 0xC) -
                            Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0),
                        Actor23_89178Field(ownerRecord17, int*, 0x10) -
                            Actor23_89178Field(&Actor23_89178Data70328View1, int*, 4),
                        argumentWord6),
                    Actor23_89178Field(&Actor23_89178Data70328View1, unsigned char*, 0xE), 0x20,
                    0x40);
            }
            Actor23_89178Field(addressOrResult16, int*, 4) = (int)rawWord2;
            return;
        }
        MATCHING_KEEP(ownerRecord17);
        temporaryWord6 = ownerRecord17 + 12;
        goto checkOwnerPosition;
    }
checkOwnerPosition:
    if (Actor23_89178Call1BA30View1(temporaryWord6, 0x1F4, 0, 0, 0, ownerRecord17) != 0) {
        Actor23_89178Field(ownerRecord17, int*, 0xC) = (int)Actor23_89178Data7190CView1;
        Actor23_89178Field(ownerRecord17, int*, 0x10) = (int)Actor23_89178Data71910View1;
    }
    temporaryWord5 = Actor23_89178Field(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord5) {
        case 0:
            rawWord2 = Actor23_89178TurnMobyTowardPlayerView1(ownerRecord17, 4, 1, 0);
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2)
                goto prepareOriginalZeroArgument;
            MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord2, "$5");
            argumentWord5 = 1;
            goto callOriginalState0Helper;
        prepareOriginalZeroArgument:
            argumentWord5 = 0;
        callOriginalState0Helper:
            Actor23_89178RequestMobyAnimationView1(argumentWord4, argumentWord5);
            if (Actor23_89178CountTimerDownView1(privateRecord18, 2) != 0) {
                temporaryWord1 = Actor23_89178Field(privateRecord18, void**, 8);
                if ((temporaryWord1 == 0) ||
                    (Actor23_89178Data74414View1(temporaryWord1, &Actor23_89178Data70328View1) !=
                     0)) {
                    argumentWord4 = Actor23_89178Field(privateRecord18, int*, 12);
                    if (!argumentWord4)
                        return;
                    rawWord2 =
                        Actor23_89178Data74414View1(argumentWord4, &Actor23_89178Data70328View1);
                    if (rawWord2)
                        return;
                    rawWord2 = 1;
                    MATCHING_OBSERVE_GNU_VOLATILE(ownerRecord17);
                    goto storeOriginalState1AndCall;
                } else {
                    goto produceState22Distance;
                }
            } else {
                default:
                    return;
            }
            break;
        case 20:
            Actor23_89178RequestMobyAnimationView1(ownerRecord17, 1);
            if (Actor23_89178TurnMobyTowardHeadingView1(
                    ownerRecord17, Actor23_89178Field(privateRecord18, short*, 4), 4, 1, 0, 0) !=
                0) {
                Actor23_89178Call35DDCView1(ownerRecord17, 0x50, 0, 0, 4);
            }
            if (Actor23_89178CountTimerDownView1(privateRecord18, 2) != 0) {
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                return;
            }
            break;
        case 22:
            if (Actor23_89178Field(privateRecord18, void**, 0xC) != 0) {
                Actor23_89178RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                retainedAddressOrBase19 = ownerRecord17 + 0x20;
                originalFrame.sp50 = 0x5DC;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = 0;
                Actor23_89178TransformVectorByBasisView1(retainedAddressOrBase19,
                                                         &originalFrame.sp50, &originalFrame.sp50);
                Actor23_89178AddVectorView1(&originalFrame.sp50, ownerRecord17 + 0xC,
                                            &originalFrame.sp50);
                if (Actor23_89178Data74414View1(Actor23_89178Field(privateRecord18, void**, 0xC),
                                                &originalFrame.sp50) != 0) {
                    originalFrame.sp50 = 0;
                    originalFrame.sp54 = 0x100;
                    originalFrame.sp58 = 0;
                    Actor23_89178TransformVectorByBasisView1(
                        retainedAddressOrBase19, &originalFrame.sp50, &originalFrame.sp50);
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    rawWord3 = Actor23_89178Field(ownerRecord17, int*, 12);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 4);
                    argumentWord4 = originalFrame.sp50;
                    rawWord2 -= rawWord3;
                    argumentWord5 = argumentWord4 * rawWord2;
                    originalFrame.sp60 = rawWord2;
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    rawWord3 = Actor23_89178Field(ownerRecord17, int*, 16);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 8);
                    argumentWord4 = originalFrame.sp54;
                    rawWord2 -= rawWord3;
                    rawWord3 = argumentWord4 * rawWord2;
                    originalFrame.sp64 = rawWord2;
                    rawWord2 = argumentWord5 + rawWord3;
                    if (rawWord2 >= 0)
                        goto loadOriginalOwnerByte;
                    MATCHING_OBSERVE_GNU_VOLATILE(rawWord2);
                    rawWord2 = Actor23_89178Field(ownerRecord17, unsigned char*, 0x46);
                    MATCHING_KEEP(rawWord2);
                    rawWord2 += 64;
                    goto storeOriginalTurnAndState20;
                }
            }
            addressOrResult16 = (int)&originalFrame.sp40;
            rawWord3 = Actor23_89178Field(privateRecord18, int*, 8);
            rawWord2 = Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0);
            rawWord3 = Actor23_89178Field(rawWord3, int*, 4);
            argumentWord4 = addressOrResult16;
            rawWord2 -= rawWord3;
            originalFrame.sp40 = rawWord2;
            rawWord3 = Actor23_89178Field(privateRecord18, int*, 8);
            rawWord2 = Actor23_89178Field(&Actor23_89178Data70328View1, int*, 4);
            rawWord3 = Actor23_89178Field(rawWord3, int*, 8);
            argumentWord5 = 0;
            originalFrame.sp48 = 0;
            rawWord2 -= rawWord3;
            originalFrame.sp44 = rawWord2;
            rawWord2 = Actor23_89178MeasureVectorLengthView1(argumentWord4, argumentWord5);
            argumentWord4 = addressOrResult16;
            argumentWord6 = Actor23_89178Field(privateRecord18, short*, 6);
            Actor23_89178ScaleVectorRatioQ15View1(argumentWord4, rawWord2, argumentWord6);
            rawWord2 = Actor23_89178Field(privateRecord18, int*, 8);
            rawWord3 = originalFrame.sp40;
            rawWord2 = Actor23_89178Field(rawWord2, int*, 4);
            rawWord2 += rawWord3;
            originalFrame.sp40 = rawWord2;
            rawWord2 = Actor23_89178Field(privateRecord18, int*, 8);
            rawWord3 = originalFrame.sp44;
            rawWord2 = Actor23_89178Field(rawWord2, int*, 8);
            argumentWord4 = (int)ownerRecord17 + 12;
            rawWord2 += rawWord3;
            originalFrame.sp44 = rawWord2;
            originalFrame.sp48 = Actor23_89178Field(ownerRecord17, int*, 20);
            if (Actor23_89178ApproximatePlanarDistanceView1(ownerRecord17 + 0xC,
                                                            &originalFrame.sp40) >= 0x1401) {
                rawWord2 = Actor23_89178PlanarHeadingLookupView1(
                    originalFrame.sp40 - Actor23_89178Field(ownerRecord17, int*, 12),
                    originalFrame.sp44 - Actor23_89178Field(ownerRecord17, int*, 16), 0);
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 1;
                MATCHING_OBSERVE2_CLOBBER(argumentWord4, argumentWord5, "$16");
                addressOrResult16 = rawWord2;
                Actor23_89178RequestMobyAnimationView1(argumentWord4, argumentWord5);
                if (Actor23_89178TurnMobyTowardHeadingView1(ownerRecord17, addressOrResult16, 4, 1,
                                                            0, 0) != 0) {
                    Actor23_89178Call35DDCView1(ownerRecord17, 0x50, 0, 0, 4);
                }
            } else {
                Actor23_89178RequestMobyAnimationView1(ownerRecord17, 0);
            }
            if (Actor23_89178Data74414View1(Actor23_89178Field(privateRecord18, void**, 8),
                                            &Actor23_89178Data70328View1) != 0) {
                Actor23_89178Field(privateRecord18, short*, 0) = 0x1E;
                Actor23_89178Field(ownerRecord17, signed char*, 0x48) = 0;
                Actor23_89178RequestMobyAnimationView1(ownerRecord17, 0);
                return;
            }
            break;
        case 1:
            rawWord2 = Actor23_89178ApproximatePlanarDistanceView1(ownerRecord17 + 12,
                                                                   &Actor23_89178Data70328View1);
            rawWord2 = rawWord2 < 5120;
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2) {
                argumentWord5 = 2;
                rawWord2 = 15;
                Actor23_89178Field(privateRecord18, short*, 2) = rawWord2;
                rawWord2 = 2;
                goto storeState2Or3AndCall;
            }
            temporaryWord2 = Actor23_89178Field(privateRecord18, void**, 8);
            if ((temporaryWord2 != 0) &&
                (Actor23_89178Data74414View1(temporaryWord2, &Actor23_89178Data70328View1) == 0)) {
            produceState22Distance:
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 0x16U;
                Actor23_89178Field(privateRecord18, short*, 6) = (short)Actor23_89178Field(
                    &originalFrame.sp20, int*, Actor23_89178RandBetweenView1(0, 2) * 4);
                return;
            }
            if (Actor23_89178Field(privateRecord18, void**, 0xC) != 0) {
                Actor23_89178RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                retainedAddressOrBase19 = ownerRecord17 + 0x20;
                originalFrame.sp70 = 0x5DC;
                originalFrame.sp74 = 0;
                originalFrame.sp78 = 0;
                Actor23_89178TransformVectorByBasisView1(retainedAddressOrBase19,
                                                         &originalFrame.sp70, &originalFrame.sp70);
                Actor23_89178AddVectorView1(&originalFrame.sp70, ownerRecord17 + 0xC,
                                            &originalFrame.sp70);
                if (Actor23_89178Data74414View1(Actor23_89178Field(privateRecord18, void**, 0xC),
                                                &originalFrame.sp70) != 0) {
                    originalFrame.sp70 = 0;
                    originalFrame.sp74 = 0x100;
                    originalFrame.sp78 = 0;
                    Actor23_89178TransformVectorByBasisView1(
                        retainedAddressOrBase19, &originalFrame.sp70, &originalFrame.sp70);
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    rawWord3 = Actor23_89178Field(ownerRecord17, int*, 12);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 4);
                    argumentWord4 = originalFrame.sp70;
                    rawWord2 -= rawWord3;
                    firstLowProduct7 = argumentWord4 * rawWord2;
                    originalFrame.sp80 = rawWord2;
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    rawWord3 = Actor23_89178Field(ownerRecord17, int*, 16);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 8);
                    argumentWord4 = originalFrame.sp74;
                    rawWord2 -= rawWord3;
                    secondLowProduct9 = argumentWord4 * rawWord2;
                    originalFrame.sp84 = rawWord2;
                    argumentWord6 = 0;
                    argumentWord5 = Actor23_89178Field(ownerRecord17, int*, 16);
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    argumentWord4 = Actor23_89178Field(ownerRecord17, int*, 12);
                    rawWord3 = Actor23_89178Field(rawWord2, int*, 4);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 8);
                    argumentWord4 = rawWord3 - argumentWord4;
                    argumentWord5 = rawWord2 - argumentWord5;
                    addressOrResult16 = firstLowProduct7 + secondLowProduct9;
                    rawWord2 = Actor23_89178PlanarHeadingLookupView1(
                        argumentWord4, argumentWord5, argumentWord6, firstLowProduct7);
                    if (addressOrResult16 >= 0)
                        goto addOriginal192;
                    rawWord2 += 64;
                    goto storeOriginalTurnAndState20;
                }
            }
            Actor23_89178CopyVectorView1(&originalFrame.sp60, &Actor23_89178Data70328View1);
            rawWord2 = Actor23_89178PlanarHeadingLookupView1(
                originalFrame.sp60 - Actor23_89178Field(ownerRecord17, int*, 0xC),
                originalFrame.sp64 - Actor23_89178Field(ownerRecord17, int*, 0x10), 0);
            argumentWord4 = (int)ownerRecord17;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord2) : "$16");
            addressOrResult16 = rawWord2;
            Actor23_89178TurnMobyTowardHeadingView1(argumentWord4, addressOrResult16, 4, 12, 0, 0);
            if (Actor23_89178AbsoluteByteAngleDeltaView1(
                    addressOrResult16, Actor23_89178Field(ownerRecord17, unsigned char*, 0x46)) <
                0x14) {
                Actor23_89178Call35DDCView1(
                    ownerRecord17,
                    Actor23_89178Field(&originalFrame.sp30, int*, Actor23_89178Data6C7C4View1 * 4),
                    0, 0, 4);
                return;
            }
            break;
        case 2:
            rawWord2 = Actor23_89178Call55E84View1(ownerRecord17);
            argumentWord4 = Actor23_89178Field(privateRecord18, int*, 8);
            retainedResult20 = rawWord2;
            if ((argumentWord4 != 0) &&
                (Actor23_89178Data74414View1(argumentWord4, &Actor23_89178Data70328View1) == 0)) {
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 0x16U;
                Actor23_89178Field(privateRecord18, short*, 6) = (short)Actor23_89178Field(
                    &originalFrame.sp20, int*, Actor23_89178RandBetweenView1(0, 2) * 4);
                goto continueOriginalState2;
            }
            if (Actor23_89178Field(privateRecord18, void**, 0xC) != 0) {
                Actor23_89178RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                retainedAddressOrBase19 = ownerRecord17 + 0x20;
                originalFrame.sp90 = 0x5DC;
                originalFrame.sp94 = 0;
                originalFrame.sp98 = 0;
                Actor23_89178TransformVectorByBasisView1(retainedAddressOrBase19,
                                                         &originalFrame.sp90, &originalFrame.sp90);
                Actor23_89178AddVectorView1(&originalFrame.sp90, ownerRecord17 + 0xC,
                                            &originalFrame.sp90);
                if (Actor23_89178Data74414View1(Actor23_89178Field(privateRecord18, void**, 0xC),
                                                &originalFrame.sp90) != 0) {
                    originalFrame.sp90 = 0;
                    originalFrame.sp94 = 0x100;
                    originalFrame.sp98 = 0;
                    Actor23_89178TransformVectorByBasisView1(
                        retainedAddressOrBase19, &originalFrame.sp90, &originalFrame.sp90);
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    rawWord3 = Actor23_89178Field(ownerRecord17, int*, 12);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 4);
                    argumentWord4 = originalFrame.sp90;
                    rawWord2 -= rawWord3;
                    argumentWord5 = argumentWord4 * rawWord2;
                    originalFrame.spA0 = rawWord2;
                    rawWord2 = Actor23_89178Field(privateRecord18, int*, 12);
                    rawWord3 = Actor23_89178Field(ownerRecord17, int*, 16);
                    rawWord2 = Actor23_89178Field(rawWord2, int*, 8);
                    argumentWord4 = originalFrame.sp94;
                    rawWord2 -= rawWord3;
                    rawWord3 = argumentWord4 * rawWord2;
                    originalFrame.spA4 = rawWord2;
                    rawWord2 = argumentWord5 + rawWord3;
                    if (rawWord2 >= 0)
                        goto loadOriginalOwnerByte;
                    rawWord2 = Actor23_89178Field(ownerRecord17, unsigned char*, 0x46);
                    rawWord2 += 64;
                    goto storeOriginalTurnAndState20;
                loadOriginalOwnerByte:
                    rawWord2 = Actor23_89178Field(ownerRecord17, unsigned char*, 0x46);
                addOriginal192:
                    rawWord2 += 192;
                storeOriginalTurnAndState20:
                    rawWord2 &= 255;
                    Actor23_89178Field(privateRecord18, short*, 4) = rawWord2;
                    rawWord2 = 20;
                    Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = 120;
                    Actor23_89178Field(privateRecord18, short*, 0) = rawWord2;
                    return;
                }
            }
        continueOriginalState2:
            rawWord2 = Actor23_89178PlanarHeadingLookupView1(
                Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0) -
                    Actor23_89178Field(ownerRecord17, int*, 0xC),
                Actor23_89178Field(&Actor23_89178Data70328View1, int*, 4) -
                    Actor23_89178Field(ownerRecord17, int*, 0x10),
                0);
            argumentWord4 = (int)ownerRecord17;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord2) : "$16");
            addressOrResult16 = rawWord2;
            Actor23_89178TurnMobyTowardHeadingView1(argumentWord4, addressOrResult16, 4, 12, 0, 0);
            if (Actor23_89178AbsoluteByteAngleDeltaView1(
                    addressOrResult16, Actor23_89178Field(ownerRecord17, unsigned char*, 0x46)) <
                0x14) {
                Actor23_89178Call35DDCView1(
                    ownerRecord17,
                    Actor23_89178Field(&originalFrame.sp30, int*, Actor23_89178Data6C7C4View1 * 4),
                    0, 0, 4);
            }
            Actor23_89178RefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
            Actor23_89178InterpolateMobyVertexView1(ownerRecord17, 0, &originalFrame.sp80);
            if ((Actor23_89178CountTimerDownView1(privateRecord18 + 2, 2) != 0) &&
                (Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0x50) != 9) &&
                (Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0x50) != 4) &&
                (((unsigned int)(retainedResult20 - 5) < 4U) ||
                 (rawWord2 = retainedResult20 < 13, !rawWord2)) &&
                (Actor23_89178ApproximatePlanarDistanceView1(&Actor23_89178Data70328View1,
                                                             &originalFrame.sp80) < 0x190)) {
                rawWord2 = Actor23_89178Field(&Actor23_89178Data70328View1, int*, 8);
                rawWord3 = originalFrame.sp88;
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if (rawWord2 < 0x400) {
                    argumentWord4 = (int)ownerRecord17;
                    rawWord2 = Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0x24);
                    rawWord2 |= 1;
                    Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0x24) = rawWord2;
                    argumentWord5 = 3;
                    rawWord2 = Actor23_89178Field(argumentWord4, unsigned char*, 0x46);
                    Actor23_89178Field(&Actor23_89178Data70328View1, int*, 0x298) = rawWord2;
                    rawWord2 = 3;
                storeState2Or3AndCall:
                    Actor23_89178Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                    Actor23_89178RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    return;
                }
                goto checkOriginalState1Range;
            }
        checkOriginalState1Range:
            if (Actor23_89178ApproximatePlanarDistanceView1(
                    ownerRecord17 + 0xC, &Actor23_89178Data70328View1) >= 0x1401) {
                rawWord2 = 1;
            storeOriginalState1AndCall:
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                Actor23_89178RequestMobyAnimationView1(ownerRecord17, 1);
                return;
            }
            break;
        case 3:
            if (Actor23_89178Data6C770View1 != 0) {
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Actor23_89178RequestMobyAnimationView1(ownerRecord17, 0);
                return;
            }
            break;
        case 4:
            rawWord3 = Actor23_89178Field(ownerRecord17, unsigned char*, 0x4F);
            if (rawWord3 >= 0x21U) {
                rawWord2 = rawWord3 - 12;
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x4F) = rawWord2;
            }
            if ((unsigned char)Actor23_89178Field(ownerRecord17, unsigned char*, 0x4F) < 0x20U) {
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x4F) = 0x20U;
            }
            if (Actor23_89178Data6C770View1 != 0) {
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 0;
                MATCHING_KEEP_CLOBBER(argumentWord5, "$2");
                rawWord2 = 32;
                Actor23_89178Field(argumentWord4, unsigned char*, 0x4F) = rawWord2;
                Actor23_89178Field(argumentWord4, unsigned char*, 0x48) = 0;
                Actor23_89178RequestMobyAnimationView1(argumentWord4, argumentWord5);
                return;
            }
            break;
        case 5:
            temporaryWord3 = Actor23_89178Field(ownerRecord17, void**, 0);
            if (Actor23_89178Call35030View1(ownerRecord17, temporaryWord3 + 8,
                                            Actor23_89178Field(temporaryWord3, int*, 4),
                                            temporaryWord3, 8, 0x10, 0x200, 0x23) != 3) {
                if (Actor23_89178Data6C770View1 != 0) {
                    Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 6U;
                    Actor23_89178RequestMobyAnimationView1(ownerRecord17, 6);
                    return;
                }
            } else {
                goto storeOriginalState7AndCall;
            }
            break;
        case 6:
            temporaryWord4 = Actor23_89178Field(ownerRecord17, void**, 0);
            if (Actor23_89178Call35030View1(ownerRecord17, temporaryWord4 + 8,
                                            Actor23_89178Field(temporaryWord4, int*, 4),
                                            temporaryWord4, 8, 0x16, 0x200, 0x23) == 3) {
            storeOriginalState7AndCall:
                Actor23_89178Field(ownerRecord17, unsigned char*, 0x48) = 7U;
                Actor23_89178RequestMobyAnimationView1(ownerRecord17, 7);
                return;
            }
            break;
        case 7:
            if (Actor23_89178Data6C770View1 != 0) {
                Actor23_89178RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Actor23_89178Call369B8View1(ownerRecord17, 0x28);
                Actor23_89178DeleteMobyView1(ownerRecord17);
            }
            break;
    }
}
#undef Actor23_89178Field


extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_23_80089D20(Moby* moby) {
    if (D_8006C770 != 0)
        func_80055B18(moby);
}

extern Moby* Actor23_D_8006C550 __asm__("D_8006C550");
void Actor23DeleteMoby(Moby*) __asm__("func_80055B18");
extern Savepoint Actor23_D_8006C7F8 __asm__("D_8006C7F8");
extern Savepoint Actor23_D_8006D088 __asm__("D_8006D088");

extern Savepoint Late23A __asm__("D_8006D088");
extern Savepoint Late23B __asm__("D_8006C7F8");
void func_level_23_80089D4C(Moby* arg0) {
    register void* fieldPointer __asm__("$16");
    Moby* selectedActor;
    register int width __asm__("$5");
    register Savepoint* lateA __asm__("$18");
    register Savepoint* lateB __asm__("$17");
    int iteration;
    register int indexOrBase __asm__("$2");
    register int byteOffset __asm__("$3");
    unsigned char savedState;
    register int state __asm__("$3");
    unsigned char selectedIndex;
    register void* actorBytes __asm__("$17");
    void* privateData;
    register void* target __asm__("$4");

    state = arg0->state;
    privateData = arg0->mobyTag;
    arg0->updateDistance = 0xFF;
    switch (state) {
        case 0:
            iteration = 0;
            do {
                if (iteration == 0) {
                    indexOrBase = (*(int*)((unsigned char*)(privateData) + 4));
                    byteOffset = indexOrBase * 2;
                } else {
                    indexOrBase = (*(int*)((unsigned char*)(privateData) + 8));
                    byteOffset = indexOrBase * 2;
                }
                byteOffset = (byteOffset + indexOrBase) * 4 - indexOrBase;
                indexOrBase = (int)Actor23_D_8006C550;
                MATCHING_KEEP2(indexOrBase, byteOffset);
                byteOffset *= 8;
                actorBytes = (void*)(indexOrBase + byteOffset);
                (*(signed char*)((unsigned char*)(actorBytes) + 0x48)) = 0x14;
                __asm__ __volatile__("" : : : "$5", "$6", "memory");
                fieldPointer = actorBytes + 0x48;
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
                fieldPointer = actorBytes + 0xC;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = actorBytes + 0x10;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = actorBytes + 0x14;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = actorBytes + 0x46;
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(iteration, "memory");
                iteration += 1;
                fieldPointer = (unsigned char*)arg0 + 0x48;
            } while (iteration < 2);
            arg0->state = 1;
            (*(unsigned char*)((unsigned char*)(privateData) + 3)) = 0xFFU;
            (*(short*)((unsigned char*)(privateData) + 0)) = 0;
            (*(int*)((unsigned char*)(privateData) + 0xC)) = 0;
            (*(int*)((unsigned char*)(privateData) + 0x10)) = 0;
            func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
            func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
            fieldPointer = privateData + 3;
            func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
            func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
            func_8003B7B4(privateData, 2, &Actor23_D_8006D088);
            func_8003B7B4(privateData, 2, &Actor23_D_8006C7F8);
            fieldPointer = privateData + 0xC;
            func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
            func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
            fieldPointer = privateData + 0x10;
            func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
            target = fieldPointer;
            width = 4;
            goto block_13;
        case 1:
            selectedIndex = (*(unsigned char*)((unsigned char*)(privateData) + 3));
            if (selectedIndex != 0xFF) {
                selectedActor = &Actor23_D_8006C550[selectedIndex];
                fieldPointer = &selectedActor->state;
                savedState = selectedActor->state;
                selectedActor->state = 0x26;
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
                selectedActor->state = savedState;
                if ((*(unsigned char*)((unsigned char*)(privateData) + 3)) ==
                    (*(int*)((unsigned char*)(privateData) + 4))) {
                    (*(int*)((unsigned char*)(privateData) + 0xC)) = 5;
                    (*(int*)((unsigned char*)(privateData) + 0x10)) = 1;
                } else {
                    (*(int*)((unsigned char*)(privateData) + 0x10)) = 5;
                    (*(int*)((unsigned char*)(privateData) + 0xC)) = 1;
                }
                fieldPointer = privateData + 0xC;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = privateData + 0x10;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = &selectedActor->position;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = &selectedActor->position.y;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = &selectedActor->position.z;
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 4, &Actor23_D_8006C7F8);
                fieldPointer = &selectedActor->angle.yaw;
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
                fieldPointer = (unsigned char*)arg0 + 0x48;
                arg0->state = 2;
                (*(short*)((unsigned char*)(privateData) + 0)) = 1;
                (*(unsigned char*)((unsigned char*)(privateData) + 3)) = 0xFFU;
                lateA = &Late23A;
                func_8003B7B4(fieldPointer, 1, lateA);
                target = fieldPointer;
                width = 1;
                MATCHING_KEEP2(target, width);
                lateB = &Late23B;
                func_8003B7B4(target, width, lateB);
                func_8003B7B4(privateData, 2, lateA);
                func_8003B7B4(privateData, 2, lateB);
                fieldPointer = privateData + 3;
                func_8003B7B4(fieldPointer, 1, lateA);
                target = fieldPointer;
                width = 1;
            block_13:
                func_8003B7B4(target, width, &Actor23_D_8006C7F8);
                return;
            }
        default:
            return;
        case 2:
            fieldPointer = (unsigned char*)arg0 + 0x48;
            if ((*(unsigned char*)((unsigned char*)(privateData) + 3)) != 0xFF) {
                arg0->state = 4;
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006D088);
                func_8003B7B4(fieldPointer, 1, &Actor23_D_8006C7F8);
                arg0->state = 3;
                return;
            }
            break;
        case 3:
            break;
        case 4:
            Actor23DeleteMoby(arg0);
            break;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; original 8008A228.
* Original assembly SHA256 c7cbafad67cfd03c1fb7776f675ccca0d78aa7574a1872885b086dbebd86b716.
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
#define Level23_8A228CompleteSignedProductLow(a, b)                                  \
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
#define Level23_8A228Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level23_8A228Word(p, o) Level23_8A228Field(p, int*, o)
#define Level23_8A228Pointer(p, o) Level23_8A228Field(p, unsigned char**, o)
#define Level23_8A228Byte(p, o) Level23_8A228Field(p, unsigned char*, o)
#define Level23_8A228SignedHalfword(p, o) Level23_8A228Field(p, short*, o)
#define Level23_8A228UnsignedHalfword(p, o) Level23_8A228Field(p, unsigned short*, o)
#define Level23_8A228KeepCompleteWord(v) __asm__("" : "=r"(v) : "0"(v))
extern short Level23_8A228Table65920[] __asm__("D_80065920"), Level23_8A228Table658A0[] __asm__(
                                                                  "D_800658A0");
extern unsigned char Level23_8A228Data70328View1[] __asm__("D_80070328");
extern int Level23_8A228Data6C640View1 __asm__("D_8006C640");
extern int (*Level23_8A228DataSpawnParticleView1)() __asm__("SpawnParticle");
int Level23_8A228Call1C288View1() __asm__("func_8001C288");
int Level23_8A228SubtractVectorView1() __asm__("func_8004F1C8");
int Level23_8A228PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level23_8A228Call1BA30View1() __asm__("func_8001BA30");
void Level23_8A228AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void* Level23_8A228Call50B00View1(int, int, int, int, int) __asm__("func_80050B00");
void Level23_8A228AddVectorView2(void*, void*, void*) __asm__("func_8004F194");
void* Level23_8A228Call50B00View2(int, int, int, int, int) __asm__("func_80050B00");
void Level23_8A228Call50B88View1(void*) __asm__("func_80050B88");
void Level23_8A228Call50B88View2(void*) __asm__("func_80050B88");
void Level23_8A228DeleteMobyView1(void*) __asm__("func_80055B18");
void func_level_23_8008A228(unsigned char* ownerParameter) {
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
    Level23_8A228KeepCompleteWord(owner23);
    rawAddressOrWord25 = Level23_8A228Pointer(owner23, 0);
    originalFrame.privateRecord38 = rawAddressOrWord25;
    originalFrame.linkedOwner40 =
        Level23_8A228Pointer(Level23_8A228Pointer(rawAddressOrWord25, 16), 0);
    rawWord3 = Level23_8A228Byte(owner23, 0x48);
    Level23_8A228Byte(owner23, 0x41) = 0;
    Level23_8A228Byte(owner23, 0x4C) = 0;
    Level23_8A228Byte(owner23, 0x4D) = 0;
    if (rawWord3 == 1) {
        twelveByteRecord16 = owner23 + 12;
        rawWord2 = Level23_8A228UnsignedHalfword(rawAddressOrWord25, 0) + 200;
        Level23_8A228UnsignedHalfword(rawAddressOrWord25, 0) = rawWord2;
        rawWord2 = Level23_8A228Call1C288View1(twelveByteRecord16, (short)rawWord2, 0);
        if (rawWord2) {
            rawWord2 = Level23_8A228Word(owner23, 20);
            Level23_8A228KeepCompleteWord(rawWord2);
            rawWord3 = Level23_8A228Word(Level23_8A228Data70328View1, 8);
            rawWord2 -= rawWord3;
            if (rawWord2 < 0)
                rawWord2 = -rawWord2;
            if (rawWord2 < 512) {
                Level23_8A228Word(Level23_8A228Data70328View1, 0x24) |= 7;
                Level23_8A228SubtractVectorView1(originalFrame.vectorWork18,
                                                 Level23_8A228Data70328View1, twelveByteRecord16);
                Level23_8A228Word(Level23_8A228Data70328View1, 0x298) =
                    Level23_8A228PlanarHeadingLookupView1(originalFrame.vectorWork18[0],
                                                          originalFrame.vectorWork18[1], 0);
            }
        }
        rawAddressOrWord25 = originalFrame.privateRecord38;
        Level23_8A228Call1BA30View1(owner23 + 12,
                                    Level23_8A228SignedHalfword(rawAddressOrWord25, 0) + 200, 1, 0,
                                    0x10000, owner23);
        rawAddressOrWord25 = originalFrame.privateRecord38;
        if (Level23_8A228SignedHalfword(rawAddressOrWord25, 0) <= 3072)
            goto Level23_8A228UseHeldPrivateRecord;
        Level23_8A228SignedHalfword(rawAddressOrWord25, 0) = 3072;
        Level23_8A228Byte(owner23, 0x48) = 2;
    }
    rawAddressOrWord25 = originalFrame.privateRecord38;
Level23_8A228UseHeldPrivateRecord:
    originalFrame.phaseWord78 = 0;
    originalFrame.pointArray50 = ({
        rawAddressOrWord25 = Level23_8A228Pointer(rawAddressOrWord25, 4);
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        rawAddressOrWord25;
    });
    rawAddressOrWord25 = originalFrame.privateRecord38;
    originalFrame.signedHalfword48 = ({
        rawAddressOrWord25 =
            (unsigned char*)(int)Level23_8A228SignedHalfword(rawAddressOrWord25, 0);
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        (int)rawAddressOrWord25;
    });
    rawAddressOrWord25 = originalFrame.pointArray50;
    outerIndex21 = 0;
    originalFrame.header58 = rawAddressOrWord25 + 0x43C;
    rawAddressOrWord25 = originalFrame.pointArray50;
    baseIndexOrHalfword20 = 0;
    originalFrame.indexArray60 = rawAddressOrWord25 + 0x47C;
    do {
        argumentWord4 = Level23_8A228Byte(owner23, 0x46);
        Level23_8A228KeepCompleteWord(argumentWord4);
        rawAddressOrWord25 =
            (unsigned char*)Level23_8A228Field(&originalFrame.phaseWord78, volatile int*, 0);
        argumentWord4 += (int)rawAddressOrWord25;
        rawWord3 = (argumentWord4 & 255) << 1;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord3, "$25");
        rawAddressOrWord25 = (unsigned char*)Level23_8A228Table65920;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        rawWord2 = rawWord3 + (int)rawAddressOrWord25;
        Level23_8A228KeepCompleteWord(rawWord2);
        rawWord2 = *(short*)rawWord2;
        rawAddressOrWord25 = (unsigned char*)originalFrame.signedHalfword48;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        innerIndex17 = 0;
        angleOrTableAddress18 = 0;
        rawAddressOrWord25 = (unsigned char*)Level23_8A228Table658A0;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        rawWord3 = rawWord3 + (int)rawAddressOrWord25;
        Level23_8A228KeepCompleteWord(rawWord3);
        rawWord2 = *(short*)rawWord3;
        __asm__("" : "=l"(completeProductLow) : "x"(completeSignedProduct), "r"(rawWord2));
        argumentWord5 = completeProductLow;
        Level23_8A228KeepCompleteWord(argumentWord5);
        rawAddressOrWord25 = (unsigned char*)originalFrame.signedHalfword48;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
        argumentWord4 += 64;
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        argumentWord4 &= 255;
        argumentWord4 <<= 1;
        retainedOffset = argumentWord5 >> 12;
        rawAddressOrWord25 = originalFrame.privateRecord38;
        halfwordOrTableAddress19 = Level23_8A228SignedHalfword(rawAddressOrWord25, 2);
        rawAddressOrWord25 = (unsigned char*)Level23_8A228Table658A0;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        rawAddressOrWord25 = (unsigned char*)(argumentWord4 + (int)rawAddressOrWord25);
        originalFrame.table658A0_68 = (short*)rawAddressOrWord25;
        rawAddressOrWord25 = (unsigned char*)Level23_8A228Table65920;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        rawAddressOrWord25 = (unsigned char*)(argumentWord4 + (int)rawAddressOrWord25);
        originalFrame.table65920_70 = (short*)rawAddressOrWord25;
        __asm__(""
                : "=l"(completeProductLow)
                : "x"(completeSignedProduct), "m"(originalFrame.table65920_70));
        rawWord3 = completeProductLow;
        Level23_8A228KeepCompleteWord(rawWord3);
        retainedOffset22 = rawWord3 >> 12;
        do {
            rawWord3 = (angleOrTableAddress18 & 255) << 1;
            rawAddressOrWord25 = (unsigned char*)Level23_8A228Table65920;
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = rawWord3 + (int)rawAddressOrWord25;
            originalFrame.vectorWork18[0] = 0;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "m"(originalFrame.vectorWork18[0]));
            rawWord2 = *(short*)rawWord2;
            rawAddressOrWord25 = (unsigned char*)Level23_8A228CompleteSignedProductLow(
                rawWord2, halfwordOrTableAddress19);
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            argumentWord4 = (int)rawAddressOrWord25 >> 12;
            originalFrame.vectorWork18[1] = argumentWord4;
            rawAddressOrWord25 = (unsigned char*)Level23_8A228Table658A0;
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord3 = rawWord3 + (int)rawAddressOrWord25;
            Level23_8A228KeepCompleteWord(rawWord3);
            rawWord2 = *(short*)rawWord3;
            rawAddressOrWord25 = (unsigned char*)Level23_8A228CompleteSignedProductLow(
                rawWord2, halfwordOrTableAddress19);
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
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
            Level23_8A228KeepCompleteWord(rawWord2);
            twelveByteRecord16 = rawAddressOrWord25 + rawWord2;
            Level23_8A228KeepCompleteWord(twelveByteRecord16);
            __asm__(""
                    : "=l"(completeProductLow)
                    : "x"(completeSignedProduct), "r"(twelveByteRecord16));
            rawAddressOrWord25 = (unsigned char*)completeProductLow;
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = -(int)rawAddressOrWord25;
            rawWord2 >>= 12;
            Level23_8A228Word(twelveByteRecord16, 0) = rawWord2;
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
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            Level23_8A228Word(twelveByteRecord16, 4) = rawWord2;
            rawWord2 = originalFrame.vectorWork18[2];
            argumentWord6 = (int)twelveByteRecord16;
            Level23_8A228Word(twelveByteRecord16, 8) = rawWord2;
            Level23_8A228AddVectorView1((void*)argumentWord4, (void*)argumentWord5,
                                        (void*)argumentWord6);
            rawWord2 = Level23_8A228Word(twelveByteRecord16, 0);
            rawWord3 = Level23_8A228Word(twelveByteRecord16, 4);
            rawWord2 += retainedOffset;
            rawWord3 += retainedOffset22;
            Level23_8A228Word(twelveByteRecord16, 0) = rawWord2;
            Level23_8A228Word(twelveByteRecord16, 4) = rawWord3;
            if (Level23_8A228Byte(owner23, 0x48) == 1 && !innerIndex17) {
                argumentWord4 = 1;
                Level23_8A228KeepCompleteWord(argumentWord4);
                Level23_8A228KeepCompleteWord(innerIndex17);
                argumentWord5 = 60;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
                argumentWord6 = (int)twelveByteRecord16;
                argumentWord7 = (int)originalFrame.particleWords28;
                MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentWord6, argumentWord7, "$3");
                rawWord3 = (int)Level23_8A228DataSpawnParticleView1;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord3, "$2");
                rawWord2 = 2;
                originalFrame.particleWords28[0] = 0;
                originalFrame.particleWords28[1] = 0;
                originalFrame.particleWords28[2] = rawWord2;
                rawWord3 = ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6,
                                                 argumentWord7);
                Level23_8A228KeepCompleteWord(rawWord3);
                if (rawWord3) {
                    rawWord2 = 40;
                    Level23_8A228Byte(rawWord3, 10) = rawWord2;
                }
            }
            innerIndex17++;
            angleOrTableAddress18 += 42;
        } while (innerIndex17 < 6);
        baseIndexOrHalfword20 += 6;
        outerIndex21++;
        rawAddressOrWord25 =
            (unsigned char*)Level23_8A228Field(&originalFrame.phaseWord78, volatile int*, 0);
        rawAddressOrWord25 += 17;
        originalFrame.phaseWord78 = (int)rawAddressOrWord25;
    } while (outerIndex21 < 16);
    outerIndex21 = 0;
    rawWord9 = 0x2AAAAAAB;
    Level23_8A228KeepCompleteWord(rawWord9);
    rawWord8 = (int)0xB60B60B7;
    Level23_8A228KeepCompleteWord(rawWord8);
    argumentWord7 = 0;
    rawAddressOrWord25 = originalFrame.pointArray50;
    Level23_8A228Word(rawAddressOrWord25, 0x438) = -1;
    rawAddressOrWord25 = originalFrame.header58;
    Level23_8A228Byte(rawAddressOrWord25, 0) = 25;
    Level23_8A228Byte(rawAddressOrWord25, 1) = 25;
    Level23_8A228Byte(rawAddressOrWord25, 2) = 50;
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
            Level23_8A228KeepCompleteWord(rawWord10);
            Level23_8A228Byte(argumentWord5, 0) = rawWord3;
            Level23_8A228Byte(argumentWord5, 4) = 0;
            __asm__(""
                    : "=r"(argumentWord6)
                    : "0"(argumentWord6), "r"(rawWord10), "m"(Level23_8A228Byte(argumentWord5, 4)));
            completeSignedProduct = (long long)argumentWord6 * (long long)rawWord8;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            Level23_8A228Byte(argumentWord5, 5) = 0;
            Level23_8A228Byte(argumentWord5, 6) = 0;
            Level23_8A228Byte(argumentWord5, 7) = 0;
            __asm__ volatile(""
                             : "=r"(rawWord2)
                             : "0"(rawWord2), "m"(Level23_8A228Byte(argumentWord5, 5)),
                               "m"(Level23_8A228Byte(argumentWord5, 6)),
                               "m"(Level23_8A228Byte(argumentWord5, 7)));
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
            Level23_8A228KeepCompleteWord(rawWord3);
            Level23_8A228Byte(argumentWord5, 1) = rawWord2;
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
            Level23_8A228Byte(argumentWord5, 2) = argumentWord6;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "m"(Level23_8A228Byte(argumentWord5, 2)));
            rawWord10 = completeProductHigh;
            Level23_8A228KeepCompleteWord(rawWord10);
            rawWord2 = rawWord10 + argumentWord4;
            rawWord2 >>= 6;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord4 -= rawWord2;
            Level23_8A228Byte(argumentWord5, 3) = argumentWord4;
        } while (innerIndex17 < 6);
        outerIndex21++;
        argumentWord7 += 6;
    } while (outerIndex21 < 15);
    Level23_8A228Word(rawAddressOrWord25, 0x2D0) = -1;
    rawAddressOrWord25 = originalFrame.privateRecord38;
    if (!Level23_8A228Word(rawAddressOrWord25, 8)) {
        argumentWord4 = (int)originalFrame.pointArray50;
        argumentWord5 = (int)originalFrame.header58;
        argumentWord6 = (int)originalFrame.indexArray60;
        rawAddressOrWord25 = originalFrame.linkedOwner40;
        rawWord2 = (int)Level23_8A228Call50B00View1(argumentWord4, argumentWord5, argumentWord6,
                                                    (int)rawAddressOrWord25 + 12, 1);
        rawAddressOrWord25 = originalFrame.privateRecord38;
        Level23_8A228Word(rawAddressOrWord25, 8) = rawWord2;
    }
    outerIndex21 = 0;
    table658A0OrMagic13 = Level23_8A228Table658A0;
    table65920Address14 = Level23_8A228Table65920;
    rawAddressOrWord25 = originalFrame.privateRecord38;
    retainedOffset22 = 0;
    rawWord2 = Level23_8A228Word(rawAddressOrWord25, 4);
    rawWord11 = 0;
    recordArrayAddress15 = (unsigned char*)rawWord2 + 0x758;
    headerAddress12 = (unsigned char*)rawWord2 + 0xB94;
    indexArrayAddress24 = (unsigned char*)rawWord2 + 0xBD4;
    Level23_8A228KeepCompleteWord(indexArrayAddress24);
    do {
        rawWord3 = Level23_8A228Data6C640View1;
        rawAddressOrWord25 = originalFrame.privateRecord38;
        rawWord2 = rawWord3 * 20;
        rawWord2 = rawWord11 + rawWord2;
        rawWord2 = (rawWord2 & 255) << 1;
        rawWord2 += (int)table658A0OrMagic13;
        rawWord3 = *(short*)rawWord2;
        rawWord2 = Level23_8A228SignedHalfword(rawAddressOrWord25, 0x16);
        completeSignedProduct = (long long)rawWord3 * (long long)rawWord2;
        __asm__ volatile("" ::"x"(completeSignedProduct));
        argumentWord4 = Level23_8A228Byte(owner23, 0x46);
        Level23_8A228KeepCompleteWord(argumentWord4);
        rawAddressOrWord25 = (unsigned char*)originalFrame.signedHalfword48;
        Level23_8A228KeepCompleteWord(rawAddressOrWord25);
        rawWord2 = outerIndex21 * 17;
        Level23_8A228KeepCompleteWord(rawWord2);
        argumentWord4 += rawWord2;
        rawWord3 = (argumentWord4 & 255) << 1;
        rawWord2 = rawWord3 + (int)table658A0OrMagic13;
        Level23_8A228KeepCompleteWord(rawWord2);
        __asm__("" : "=l"(completeProductLow) : "x"(completeSignedProduct), "r"(rawWord2));
        argumentWord6 = completeProductLow;
        Level23_8A228KeepCompleteWord(argumentWord6);
        rawWord2 = *(short*)rawWord2;
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
        completeSignedProduct = (long long)rawWord2 * (long long)(int)rawAddressOrWord25;
        rawWord3 = rawWord3 + (int)table65920Address14;
        Level23_8A228KeepCompleteWord(rawWord3);
        __asm__("" : "=l"(completeProductLow) : "x"(completeSignedProduct), "r"(rawWord3));
        argumentWord5 = completeProductLow;
        Level23_8A228KeepCompleteWord(argumentWord5);
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
        baseIndexOrHalfword20 = Level23_8A228SignedHalfword(rawAddressOrWord25, 0x14);
        __asm__(""
                : "=l"(completeProductLow)
                : "x"(completeSignedProduct), "r"(baseIndexOrHalfword20));
        rawWord3 = completeProductLow;
        Level23_8A228KeepCompleteWord(rawWord3);
        retainedOffset = rawWord3 >> 12;
        do {
            originalFrame.vectorWork18[0] = 0;
            rawWord2 = *(short*)angleOrTableAddress18;
            rawAddressOrWord25 = (unsigned char*)Level23_8A228CompleteSignedProductLow(
                rawWord2, baseIndexOrHalfword20);
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord3 = (int)rawAddressOrWord25 >> 12;
            originalFrame.vectorWork18[1] = rawWord3;
            rawWord2 = *(short*)halfwordOrTableAddress19;
            rawAddressOrWord25 = (unsigned char*)Level23_8A228CompleteSignedProductLow(
                rawWord2, baseIndexOrHalfword20);
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            originalFrame.vectorWork18[2] = rawWord2;
            rawWord2 = *(short*)rawWord10;
            completeSignedProduct = (long long)rawWord3 * (long long)rawWord2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 = retainedOffset22 + innerIndex17;
            Level23_8A228KeepCompleteWord(rawWord2);
            twelveByteRecord16 = recordArrayAddress15 + rawWord2 * 12;
            Level23_8A228KeepCompleteWord(twelveByteRecord16);
            __asm__(""
                    : "=l"(completeProductLow)
                    : "x"(completeSignedProduct), "r"(twelveByteRecord16));
            rawAddressOrWord25 = (unsigned char*)completeProductLow;
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = -(int)rawAddressOrWord25;
            rawWord2 >>= 12;
            Level23_8A228Word(twelveByteRecord16, 0) = rawWord2;
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
            Level23_8A228KeepCompleteWord(rawAddressOrWord25);
            rawWord2 = (int)rawAddressOrWord25 >> 12;
            Level23_8A228Word(twelveByteRecord16, 4) = rawWord2;
            rawWord2 = originalFrame.vectorWork18[2];
            __asm__ volatile(""
                             : "=r"(innerIndex17)
                             : "0"(innerIndex17), "m"(originalFrame.vectorWork18[2]));
            innerIndex17++;
            MATCHING_OBSERVE_VOLATILE(innerIndex17);
            Level23_8A228Word(twelveByteRecord16, 8) = rawWord2;
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
            Level23_8A228AddVectorView2((void*)argumentWord4, (void*)argumentWord5,
                                        (void*)argumentWord6);
            rawWord2 = Level23_8A228Word(twelveByteRecord16, 0);
            rawWord2 += retainedOffset;
            Level23_8A228Word(twelveByteRecord16, 0) = rawWord2;
            rawWord2 = Level23_8A228Word(twelveByteRecord16, 4);
            argumentWord7 =
                Level23_8A228Field(&originalFrame.savedCallerWords80[0], volatile int*, 0);
            rawWord3 = Level23_8A228Word(twelveByteRecord16, 8);
            rawWord2 += argumentWord7;
            Level23_8A228Word(twelveByteRecord16, 4) = rawWord2;
            rawWord8 = Level23_8A228Field(&originalFrame.savedCallerWords80[1], volatile int*, 0);
            __asm__ volatile("" ::"m"(originalFrame.savedCallerWords80[1]) : "$2");
            rawWord2 = innerIndex17 < 6;
            Level23_8A228KeepCompleteWord(rawWord2);
            rawWord3 += rawWord8;
            Level23_8A228Word(twelveByteRecord16, 8) = rawWord3;
            rawWord9 = Level23_8A228Field(&originalFrame.savedCallerWords80[2], volatile int*, 0);
            rawWord10 = Level23_8A228Field(&originalFrame.savedCallerWords80[3], volatile int*, 0);
            rawWord11 = Level23_8A228Field(&originalFrame.savedCallerWords80[4], volatile int*, 0);
            headerAddress12 = (unsigned char*)Level23_8A228Field(
                &originalFrame.savedCallerWords80[5], volatile int*, 0);
            table658A0OrMagic13 =
                (short*)Level23_8A228Field(&originalFrame.savedCallerWords80[6], volatile int*, 0);
            table65920Address14 =
                (short*)Level23_8A228Field(&originalFrame.savedCallerWords80[7], volatile int*, 0);
            recordArrayAddress15 = (unsigned char*)Level23_8A228Field(
                &originalFrame.savedCallerWords80[8], volatile int*, 0);
            indexArrayAddress24 = (unsigned char*)Level23_8A228Field(
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
        Level23_8A228KeepCompleteWord(rawWord2);
        rawWord11 += 80;
    } while (rawWord2);
    MATCHING_BARRIER_VOLATILE("$2");
    outerIndex21 = 0;
    table658A0OrMagic13 = (short*)(int)0xB60B60B7;
    Level23_8A228KeepCompleteWord(table658A0OrMagic13);
    rawWord11 = 2;
    rawWord10 = 0;
    Level23_8A228Word(recordArrayAddress15, 0x438) = -1;
    Level23_8A228Byte(headerAddress12, 0) = 150;
    Level23_8A228Byte(headerAddress12, 1) = 150;
    Level23_8A228Byte(headerAddress12, 2) = 150;
    Level23_8A228Byte(headerAddress12, 4) = 70;
    Level23_8A228Byte(headerAddress12, 5) = 70;
    Level23_8A228Byte(headerAddress12, 6) = 70;
    Level23_8A228Byte(headerAddress12, 8) = 20;
    Level23_8A228Byte(headerAddress12, 9) = 20;
    Level23_8A228Byte(headerAddress12, 10) = 20;
    do {
        innerIndex17 = 0;
        do {
            rawWord2 = 0x55555556;
            completeSignedProduct = (long long)innerIndex17 * (long long)rawWord2;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 = 0x2AAA0000;
            __asm__("" : "=h"(completeProductHigh) : "x"(completeSignedProduct));
            rawWord8 = completeProductHigh;
            Level23_8A228KeepCompleteWord(rawWord8);
            Level23_8A228KeepCompleteWord(rawWord2);
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
            Level23_8A228KeepCompleteWord(rawWord9);
            rawWord2 = argumentWord7 * 3;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(rawWord9));
            completeSignedProduct = (long long)argumentWord5 * (long long)(int)table658A0OrMagic13;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            argumentWord7 = innerIndex17 - rawWord2;
            Level23_8A228Byte(argumentWord6, 0) = rawWord3;
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
            Level23_8A228KeepCompleteWord(rawWord8);
            rawWord3 = argumentWord5 >> 31;
            Level23_8A228Byte(argumentWord6, 1) = rawWord2;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord8));
            completeSignedProduct = (long long)argumentWord4 * (long long)(int)table658A0OrMagic13;
            __asm__ volatile("" ::"x"(completeSignedProduct));
            rawWord2 = rawWord8 + argumentWord5;
            rawWord2 >>= 6;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord5 -= rawWord2;
            rawWord3 = argumentWord4 >> 31;
            Level23_8A228Byte(argumentWord6, 2) = argumentWord5;
            __asm__(""
                    : "=h"(completeProductHigh)
                    : "x"(completeSignedProduct), "m"(Level23_8A228Byte(argumentWord6, 2)));
            rawWord9 = completeProductHigh;
            Level23_8A228KeepCompleteWord(rawWord9);
            rawWord2 = rawWord9 + argumentWord4;
            rawWord2 >>= 6;
            rawWord2 -= rawWord3;
            rawWord2 *= 90;
            argumentWord4 -= rawWord2;
            Level23_8A228Byte(argumentWord6, 3) = argumentWord4;
            if (!argumentWord7) {
                Level23_8A228Byte(argumentWord6, 4) = 0;
                Level23_8A228Byte(argumentWord6, 5) = rawWord11;
                Level23_8A228Byte(argumentWord6, 6) = 0;
                Level23_8A228Byte(argumentWord6, 7) = rawWord11;
            } else if (argumentWord7 == 1) {
                Level23_8A228Byte(argumentWord6, 4) = rawWord11;
                Level23_8A228Byte(argumentWord6, 5) = rawWord11;
                Level23_8A228Byte(argumentWord6, 6) = rawWord11;
                Level23_8A228Byte(argumentWord6, 7) = rawWord11;
            } else if (argumentWord7 == rawWord11) {
                Level23_8A228Byte(argumentWord6, 4) = rawWord11;
                Level23_8A228Byte(argumentWord6, 5) = 0;
                Level23_8A228Byte(argumentWord6, 6) = rawWord11;
                Level23_8A228Byte(argumentWord6, 7) = 0;
            }
            innerIndex17++;
        } while (innerIndex17 < 6);
        outerIndex21++;
        rawWord10 += 6;
    } while (outerIndex21 < 15);
    Level23_8A228Word(indexArrayAddress24, 0x2D0) = -1;
    rawAddressOrWord25 = originalFrame.privateRecord38;
    if (!Level23_8A228Word(rawAddressOrWord25, 12)) {
        argumentWord4 = (int)recordArrayAddress15;
        argumentWord5 = (int)headerAddress12;
        argumentWord6 = (int)indexArrayAddress24;
        rawAddressOrWord25 = originalFrame.linkedOwner40;
        rawWord2 = (int)Level23_8A228Call50B00View2(argumentWord4, argumentWord5, argumentWord6,
                                                    (int)rawAddressOrWord25 + 12, 1);
        rawAddressOrWord25 = originalFrame.privateRecord38;
        Level23_8A228Word(rawAddressOrWord25, 12) = rawWord2;
    }
    if (Level23_8A228Byte(owner23, 0x48) == 2) {
        rawAddressOrWord25 = originalFrame.privateRecord38;
        argumentWord4 = Level23_8A228Word(rawAddressOrWord25, 8);
        if (argumentWord4) {
            Level23_8A228Call50B88View1((void*)argumentWord4);
            rawAddressOrWord25 = originalFrame.privateRecord38;
        }
        argumentWord4 = Level23_8A228Word(rawAddressOrWord25, 12);
        if (argumentWord4)
            Level23_8A228Call50B88View2((void*)argumentWord4);
        Level23_8A228DeleteMobyView1(owner23);
    }
}
#undef Level23_8A228Field
#undef Level23_8A228Word
#undef Level23_8A228Pointer
#undef Level23_8A228Byte
#undef Level23_8A228SignedHalfword
#undef Level23_8A228UnsignedHalfword
#undef Level23_8A228KeepCompleteWord
#undef Level23_8A228CompleteSignedProductLow

typedef struct {
    int linkIndex, selector, spacingY, spacingZ;
} DecodedSixSpawnTag;
extern int D_8006C578, D_8006C574;
extern int** DecodedActorLinks __asm__("D_8006D048 + 0x14");
extern void DecodedSixSpawnSelectorUpdate(int, int, int) __asm__("func_80021ED8");
int rand(void);
void func_level_23_8008ABAC(Moby* moby) {
    DecodedSixSpawnTag* tag = moby->mobyTag;
    int* link = DecodedActorLinks[tag->linkIndex];
    Moby* spawned;
    int index;
    register int adjusted __asm__("$2");
    register int twiceHalf __asm__("$3");
    Vector3D offset;
    if (link[1]) {
        spawned = 0;
        link[1] = 0;
        DecodedSixSpawnSelectorUpdate(tag->selector, 0xFC, 0);
        index = 0;
    spawnNext:
        if (D_8006C578 - D_8006C574 < 21)
            goto finished;
        spawned = SpawnMoby(8, moby);
        if (spawned) {
            *(short*)((char*)spawned->mobyTag + 0x12) = 0;
            spawned->size = 0x2C;
            spawned->lowDrawDistance = 0x3F;
            spawned->updateDistance = 0xFF;
            spawned->angle.yaw = moby->angle.yaw;
            offset.x = 0;
            offset.z = (index >> 1) * (tag->spacingZ / 3);
            adjusted = index + ((unsigned int)index >> 31);
            MATCHING_KEEP(adjusted);
            twiceHalf = adjusted >> 1;
            MATCHING_KEEP(twiceHalf);
            twiceHalf *= 2;
            MATCHING_KEEP(twiceHalf);
            offset.y = (index - twiceHalf) * tag->spacingY - (tag->spacingY >> 1);
            spawned->animationState.id = (rand() & 1) + 1;
            func_8004F194(&spawned->position, &spawned->position, &offset);
        }
        index++;
        if (index < 6)
            goto spawnNext;
    finished:
        if (spawned)
            func_8003BABC(spawned, 0, 0);
        func_80055B18(moby);
    }
}

typedef struct {
    Vector3D vector;
    int timer;
} DecodedVectorTimer;
extern unsigned short D_8006E040;
int func_8004F334(Vector3D*, Vector3D*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
void func_level_23_8008AD4C(Moby* moby) {
    DecodedVectorTimer* tag = moby->mobyTag;
    Vector3D vector;
    if (moby->substate == 0) {
        moby->substate = 1;
        func_80055D24(moby, 4);
    }
    if (tag->timer == 0) {
        if (spyro.animationState == 7 &&
            func_8004F334(&moby->position, (Vector3D*)&spyro) < 0x400) {
            register int playerZ __asm__("$3") = spyro.position.z;
            MATCHING_KEEP(playerZ);
            if (moby->position.z < playerZ) {
                register unsigned int yaw __asm__("$4") = D_8006E040;
                register int actorYaw __asm__("$5") = moby->angle.yaw;
                MATCHING_KEEP2(yaw, actorYaw);
                if (func_8004F264((short)yaw >> 4, actorYaw) < 0x40) {
                    tag->timer = 0x12C;
                    vector.x = tag->vector.x;
                    vector.y = tag->vector.y;
                    vector.z = tag->vector.z;
                    func_8004ED6C(&moby->rotationMatrix, &vector, &vector);
                    spyro.unk17a |= 0x10000400;
                    *((int*)((char*)&spyro + 0x21C)) = vector.x;
                    *((int*)((char*)&spyro + 0x220)) = vector.y;
                    *((int*)((char*)&spyro + 0x224)) = vector.z;
                }
            }
        }
    }
    if (tag->timer)
        func_800359A4(&tag->timer, 4);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_23/moby/func_level_23_8008AE94.s SHA256 bf58ffac00493b7b1e9f1829ee14b7a4149e0e4ddefd40bbbbcefc2043523140. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int SharedRecord583_func_8001BA30() __asm__("func_8001BA30");
/* extern */
int SharedRecord583_func_8001C288() __asm__("func_8001C288");
/* extern */
int SharedRecord583TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
signed char* SharedRecord583_func_80050B00() __asm__("func_80050B00");
/* extern */
int SharedRecord583_func_80050B88() __asm__("func_80050B88");
/* extern */
int SharedRecord583DeleteMoby() __asm__("func_80055B18");
/* extern */
int SharedRecord583RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
extern unsigned char SharedRecord583_D_800658A0 __asm__("D_800658A0");
extern unsigned char SharedRecord583_D_80065920 __asm__("D_80065920");
extern int SharedRecord583_D_8006C550 __asm__("D_8006C550");
extern int SharedRecord583_D_8006C5BC __asm__("D_8006C5BC");
extern int SharedRecord583_D_8006C5C8 __asm__("D_8006C5C8");
extern unsigned char SharedRecord583_D_80070328 __asm__("D_80070328");

extern volatile int FamilyWord21C __asm__("D_80070328+0x21C");
extern volatile int FamilyWord220 __asm__("D_80070328+0x220");
extern volatile int FamilyWord20C __asm__("D_80070328+0x20C");
extern volatile int FamilyWord298 __asm__("D_80070328+0x298");
extern volatile int FamilyWord224 __asm__("D_80070328+0x224");
extern volatile int FamilyWord008 __asm__("D_80070328+8");
/* Existing verified level11 parts-update high-word capture pattern. */
#define SharedRecord583High(a, b)                                               \
    ({                                                                          \
        int high;                                                               \
        int low = (int)(a) * (int)(b);                                          \
        __asm__ __volatile__("" : "=h"(high), "=l"(low) : "1"(low) : "memory"); \
        high;                                                                   \
    })
#define SharedRecord583Low(a, b)            \
    ({                                      \
        register int low __asm__("lo");     \
        low = (int)(a) * (int)(b);          \
        __asm__("" : "=l"(low) : "0"(low)); \
        low;                                \
    })
/* Original frame is 0xB8 bytes. Scratch offsets are named by their
 * original SP-relative addresses. Raw multiply results use the original
 * HI/LO words;
  shifts and table byte addressing retain original widths.
 * Empty constraints preserve producer registers and load-delay ordering.
 * Physical units, helper contracts, and caller cadence are unresolved. */
void func_level_23_8008AE94(Moby* inputOwner) {
    Moby* owner = inputOwner;
    struct {
        volatile int sp18;
        volatile int sp1C;
        volatile int sp20;
        char pad_24[4];
        int sp28;
        int sp2C;
        int sp30;
        int pad34;
        void* volatile sp38;
        int pad3C;
        int sp40;
        int pad44;
        void* volatile sp48;
        int pad4C;
        int sp50;
        char pad_54[4];
        int sp58;
        char pad_5c[4];
        int pad60[6];
        short* volatile sp78;
        short* volatile sp7C;
        unsigned char* volatile sp80;
        unsigned char* volatile sp84;
        void* sp88;
        int pad8C;
    } scratch;

    register short* tableBase12 __asm__("$12");
    register short* tableBase13 __asm__("$13");
    register Vector3D* vertex17 __asm__("$17");
    register short* sampleAddress10 __asm__("$10");
    register short* sampleAddress11 __asm__("$11");
    register int sample4 __asm__("$4");
    int temp_a0_7;
    int temp_v0_3;
    int temp_v0_8;
    int temp_v0_9;
    int temp_v1_3;
    int temp_v1_4;
    int temp_a0;
    int temp_a0_2;
    int temp_a0_5;
    int temp_hi;
    register int high9 __asm__("$9");
    register void* caller4 __asm__("$4");
    register void* caller5 __asm__("$5");
    register void* caller6 __asm__("$6");
    register int low8 __asm__("$8");
    register int low24 __asm__("$24");
    register int next7 __asm__("$7");
    int temp_lo;
    int temp_t2;
    register int temp_v0 __asm__("$5");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int initialWord15 __asm__("$15");
    int temp_v0_2;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_7;
    int temp_v1;
    register int product3 __asm__("$3");
    register int var_a0 __asm__("$4");
    register int vertexIndex16 __asm__("$16");
    register int cycle10Index18 __asm__("$18");
    int cycle3Index19;
    register int tableByteOffset20 __asm__("$20");
    register int vertexCount21 __asm__("$21");
    register int packetGroup21 __asm__("$21");
    register int rowIndex22 __asm__("$22");
    register int packetCount22 __asm__("$22");
    int var_v0;
    int var_v0_5;
    signed char* temp_a0_6;
    signed char* temp_a0_8;
    signed char* temp_a0_9;
    int temp_a0_4;
    int temp_a2;
    int temp_v0_6;
    register int packetIndex16 __asm__("$16");
    int var_v0_2;
    int var_v0_4;
    unsigned int var_v0_3;
    register void* colorRecord23 __asm__("$23");
    register void* loadedAddress15 __asm__("$15");
    void* var_a3;
    register void* vertexTable14 __asm__("$14");

    MATCHING_KEEP(owner);
    loadedAddress15 = owner->mobyTag;
    scratch.sp38 = loadedAddress15;
    scratch.sp40 = *M2C_FIELD(loadedAddress15, int**, 0x10);
    owner->unknown3[0] = 0;
    owner->lowDrawDistance = 0;
    owner->drawn = 0;
    vertexCount21 = 0;
    if (M2C_FIELD(loadedAddress15, short*, 0x14) == 0) {
        if (SharedRecord583_func_8001C288(&owner->position, 0x400, 7) != 0) {
            temp_v0 = func_8004E880(
                M2C_FIELD(&SharedRecord583_D_80070328, int*, 0) - owner->position.x,
                M2C_FIELD(&SharedRecord583_D_80070328, int*, 4) - owner->position.y, 0);
            M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x298) = temp_v0;
            if (owner->state == 0x14) {
                if ((SharedRecord583_D_8006C5BC == 0x2C) && (SharedRecord583_D_8006C5C8 == 2)) {
                    argument4 = 0x10000480;
                    word2 = M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x20C);
                    word3 = 57;
                    M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x23C) = word3;
                    word2 |= argument4;
                    argument4 = temp_v0 * 2;
                    M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x20C) = word2;
                    word3 = M2C_FIELD(&SharedRecord583_D_80065920, short*, argument4);
                    word3 = word3 * 75 >> 12;
                    scratch.sp18 = word3;
                    argument4 = M2C_FIELD(&SharedRecord583_D_800658A0, short*, argument4);
                    word2 = 50;
                    scratch.sp20 = 0;
                    M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x21C) = word3;
                    M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x224) = word2;
                    word2 = argument4 * 75 >> 12;
                    scratch.sp1C = word2;
                    M2C_FIELD(&SharedRecord583_D_80070328, int*, 0x220) = word2;
                } else {
                    argument4 = FamilyWord298;
                    word2 = 0x10000000;
                    MATCHING_KEEP2(argument4, word2);
                    word2 |= 1024;
                    FamilyWord20C = word2;
                    MATCHING_KEEP_CLOBBER(argument4, "memory");
                    argument4 *= 2;
                    word2 = M2C_FIELD(&SharedRecord583_D_80065920, short*, argument4);
                    MATCHING_KEEP(word2);
                    word3 = word2 * 5;
                    MATCHING_KEEP(word3);
                    word2 = (word3 << 4) - word3;
                    word2 >>= 12;
                    FamilyWord21C = word2;
                    word2 = M2C_FIELD(&SharedRecord583_D_800658A0, short*, argument4);
                    MATCHING_KEEP(word2);
                    FamilyWord224 = 0;
                    MATCHING_KEEP_CLOBBER(word2, "memory");
                    word3 = word2 * 5;
                    MATCHING_KEEP(word3);
                    word2 = (word3 << 4) - word3;
                    word3 = FamilyWord008;
                    word2 >>= 12;
                    FamilyWord220 = word2;
                    word2 = owner->position.z;
                    word2 = word2 < word3;
                    if (word2)
                        word2 = -50;
                    else
                        word2 = 50;
                    FamilyWord224 = word2;
                }
            }
        }
        if (SharedRecord583_func_8001BA30(&owner->position, 0x5DC, 1, 0, 0x40000, owner) != 0) {
            owner->unkb = func_8004E880(0, 0, 0);
        }
        vertexCount21 = 0;
    }
    cycle3Index19 = 0;
    cycle10Index18 = 1;
    MATCHING_KEEP2_CLOBBER(cycle3Index19, cycle10Index18, "memory");
    loadedAddress15 = scratch.sp38;
    MATCHING_KEEP_CLOBBER(loadedAddress15, "$4");
    argument4 = 20;
    MATCHING_KEEP_CLOBBER(argument4, "memory");
    vertexTable14 = M2C_FIELD(loadedAddress15, void**, 4);
    initialWord15 = M2C_FIELD(loadedAddress15, short*, 2);
    colorRecord23 = vertexTable14 + 0x604;
    MATCHING_KEEP2_CLOBBER(colorRecord23, initialWord15, "memory");
    scratch.sp58 = initialWord15;
    word3 = M2C_FIELD(&scratch.sp58, unsigned short*, 0);
    loadedAddress15 = vertexTable14 + 0x644;
    scratch.sp48 = loadedAddress15;
    loadedAddress15 = scratch.sp38;
    word2 = owner->state;
    initialWord15 = M2C_FIELD(loadedAddress15, short*, 0);
    scratch.sp50 = initialWord15;
    if (word2 == argument4)
        goto resetOuter;
    loadedAddress15 = scratch.sp38;
    word2 = word3 + 350;
    M2C_FIELD(loadedAddress15, short*, 2) = word2;
    word2 = owner->state;
    rowIndex22 = 0;
    if (word2 == argument4)
        goto trigBases;
    word2 = M2C_FIELD(loadedAddress15, short*, 0x16);
    word3 = word2;
    MATCHING_KEEP(word2);
    if (word2 >= 1850)
        goto trigBases;
    word2 = word3 + 250;
    M2C_FIELD(loadedAddress15, short*, 0x16) = word2;
resetOuter:
    rowIndex22 = 0;
trigBases:
    tableBase13 = (short*)&SharedRecord583_D_80065920;
    tableBase12 = (short*)&SharedRecord583_D_800658A0;
    do {
        vertexIndex16 = 0;
        tableByteOffset20 = 0x80;
        word2 = vertexCount21 * 12;
        vertex17 = (Vector3D*)(word2 + (int)vertexTable14);
        word2 = owner->angle.yaw;
        word3 = rowIndex22 * 8;
        word2 = (word2 + word3) & 255;
        word2 *= 2;
        temp_v0_4 = word2;
        sampleAddress11 = (short*)(word2 + (int)tableBase13);
        sampleAddress10 = (short*)(word2 + (int)tableBase12);
    loop_20:
        var_a0 = scratch.sp50;
        if (cycle3Index19 == 0) {
            var_a0 = scratch.sp58;
        }
        word2 = 0x55555556;
        word3 = cycle3Index19 + 1;
        loadedAddress15 = (void*)SharedRecord583High(word3, word2);
        word2 = word3 >> 31;
        cycle3Index19 = (int)loadedAddress15 - word2;
        word2 = cycle3Index19 * 3;
        cycle3Index19 = word3 - word2;
        if (cycle10Index18 == 0) {
            loadedAddress15 = scratch.sp38;
            var_a0 = M2C_FIELD(loadedAddress15, short*, 0x16);
        }
        word2 = tableByteOffset20 + (int)tableBase13;
        scratch.sp18 = 0;
        word2 = M2C_FIELD(word2, short*, 0);
        product3 = SharedRecord583Low(word2, var_a0);
        word2 = tableByteOffset20 + (int)tableBase12;
        MATCHING_KEEP2(product3, word2);
        product3 >>= 12;
        scratch.sp1C = product3;
        word2 = M2C_FIELD(word2, short*, 0);
        low8 = SharedRecord583Low(word2, var_a0);
        MATCHING_KEEP(low8);
        word2 = low8 >> 12;
        scratch.sp20 = word2;
        sample4 = *sampleAddress10;
        product3 = SharedRecord583Low(product3, sample4);
        next7 = cycle10Index18 + 1;
        MATCHING_KEEP2_CLOBBER(product3, next7, "$2");
        word2 = 0x66666667;
        high9 = SharedRecord583High(next7, word2);
        low8 = product3 >> 12;
        word3 = *sampleAddress11;
        word2 = -low8;
        vertex17->x = word2;
        MATCHING_KEEP(high9);
        word2 = scratch.sp1C;
        low8 = SharedRecord583Low(word2, word3);
        MATCHING_KEEP3(low8, vertexCount21, vertexIndex16);
        word2 = scratch.sp18;
        __asm__("" : "=r"(word2) : "0"(word2) : "$5", "$6");
        {
            register int heldLow __asm__("lo");
            heldLow = word2 * sample4;
            __asm__("" : "=l"(heldLow) : "0"(heldLow) : "$5", "$6");
            caller5 = &owner->position;
            caller6 = vertex17;
            __asm__ volatile(""
                             : "=l"(heldLow), "=r"(vertexCount21), "=r"(vertexIndex16),
                               "=r"(tableByteOffset20)
                             : "0"(heldLow), "1"(vertexCount21), "2"(vertexIndex16),
                               "3"(tableByteOffset20), "r"(caller5), "r"(caller6));
            low24 = heldLow;
        }
        vertexCount21 += 1;
        vertexIndex16 += 1;
        tableByteOffset20 += 32;
        word3 = high9 >> 2;
        caller4 = vertex17;
        word2 = next7 >> 31;
        cycle10Index18 = word3 - word2;
        __asm__(""
                : "=r"(cycle10Index18), "=r"(low8)
                : "0"(cycle10Index18), "1"(low8), "r"(caller4));
        low8 >>= 12;
        __asm__("" : "=r"(low24) : "0"(low24), "r"(caller4), "r"(caller5), "r"(caller6));
        word2 = low24 >> 12;
        word2 += low8;
        vertex17->y = word2;
        word2 = cycle10Index18 * 10;
        word3 = scratch.sp20;
        MATCHING_KEEP_VOLATILE_CLOBBER(cycle10Index18, "memory");
        cycle10Index18 = next7 - word2;
        MATCHING_KEEP_VOLATILE(cycle10Index18);
        vertex17->z = word3;
        scratch.sp78 = sampleAddress10;
        scratch.sp7C = sampleAddress11;
        scratch.sp80 = tableBase12;
        scratch.sp84 = tableBase13;
        scratch.sp88 = vertexTable14;
        func_8004F194(caller4, caller5, caller6);
        MATCHING_BARRIER_VOLATILE("memory");
        word2 = vertexIndex16 < 8;
        MATCHING_KEEP(word2);
        sampleAddress10 = scratch.sp78;
        sampleAddress11 = scratch.sp7C;
        tableBase12 = (short*)scratch.sp80;
        tableBase13 = (short*)scratch.sp84;
        MATCHING_BARRIER_VOLATILE("memory");
        vertexTable14 = scratch.sp88;
        __asm__("" : "=r"(vertex17) : "0"(vertex17), "r"(vertexTable14));
        vertex17 = (Vector3D*)((char*)vertex17 + 12);
        if (word2) {
            goto loop_20;
        }
        rowIndex22 += 1;
        word2 = rowIndex22 < 16;
        MATCHING_KEEP(word2);
    } while (word2);
    word2 = -1;
    M2C_FIELD(vertexTable14, int*, 0x600) = word2;
    loadedAddress15 = scratch.sp38;
    word3 = M2C_FIELD(loadedAddress15, short*, 0x14);
    if (word3 >= 7) {
        word2 = word3 - 6;
        MATCHING_KEEP(word2);
        word3 = word2 * 10;
        word2 = 64 - word3;
        if (word2 < 0)
            word2 = 0;
        M2C_FIELD(colorRecord23, signed char*, 0) = word2;
        word2 >>= 1;
        M2C_FIELD(colorRecord23, signed char*, 1) = word2;
        word2 = (unsigned)(word2 & 255) >> 1;
        goto colorThird;
    }
    if (word3 >= 4) {
        word2 = word3 - 3;
        word2 <<= 4;
        word3 = 128;
        word2 = word3 - word2;
        M2C_FIELD(colorRecord23, signed char*, 0) = word2;
        M2C_FIELD(colorRecord23, signed char*, 1) = word2;
        M2C_FIELD(colorRecord23, signed char*, 2) = 0;
    } else {
        word2 = 128;
        M2C_FIELD(colorRecord23, signed char*, 0) = word2;
        M2C_FIELD(colorRecord23, signed char*, 1) = word2;
        loadedAddress15 = scratch.sp38;
        word2 = M2C_FIELD(loadedAddress15, short*, 0x14);
        word3 = 128;
        word2 <<= 5;
        word2 = word3 - word2;
        if (word2 < 0)
            word2 = 0;
    colorThird:
        M2C_FIELD(colorRecord23, signed char*, 2) = word2;
    }
    loadedAddress15 = scratch.sp38;
    word3 = M2C_FIELD(loadedAddress15, short*, 0x14);
    MATCHING_BARRIER_VOLATILE("$4");
    {
        int alpha;
        if (word3 < 6)
            alpha = 255;
        else
            alpha = (16 - word3) << 3;
        M2C_FIELD(colorRecord23, signed char*, 4) = alpha;
        M2C_FIELD(colorRecord23, signed char*, 5) = alpha;
        M2C_FIELD(colorRecord23, signed char*, 6) = 0;
    }
    __asm__ volatile("" ::: "$16", "$21", "$22", "$8", "memory");
    {
        register int magic8 __asm__("$8");
        register int high11 __asm__("$11");
        register int high10 __asm__("$10");
        register int packet9 __asm__("$9");
        register int next6 __asm__("$6");
        register int raw4 __asm__("$4");
        register int raw5 __asm__("$5");
        register unsigned char* packet7 __asm__("$7");
        packetIndex16 = 0;
        packetGroup21 = 0;
        packetCount22 = 0;
        magic8 = 0x55555556;
        packet7 = scratch.sp48;
        do {
            high11 = SharedRecord583High(packetIndex16, magic8);
            next6 = packetIndex16 + 1;
            high10 = SharedRecord583High(next6, magic8);
            packetGroup21++;
            raw4 = packetIndex16 + 9;
            raw5 = packetIndex16 + 8;
            word3 = packetIndex16 >> 31;
            packet7[0] = packetIndex16;
            packet7[1] = next6;
            packet9 = SharedRecord583High(raw4, magic8);
            packet7[2] = raw4;
            packet7[3] = raw5;
            MATCHING_KEEP_CLOBBER(word3, "memory");
            word3 = high11 - word3;
            word2 = word3 * 3;
            word2 = packetIndex16 - word2;
            packetIndex16 = next6;
            word2 = (unsigned)word2 < 1;
            word3 = packetIndex16 >> 31;
            packet7[4] = word2;
            MATCHING_KEEP_CLOBBER(word3, "memory");
            word3 = high10 - word3;
            __asm__("" : "=r"(packet9) : "0"(packet9), "r"(word3));
            word2 = word3 * 3;
            high10 = SharedRecord583High(raw5, magic8);
            word2 = packetIndex16 - word2;
            word2 = (unsigned)word2 < 1;
            word3 = raw4 >> 31;
            packet7[5] = word2;
            MATCHING_KEEP_CLOBBER(word3, "memory");
            word3 = packet9 - word3;
            word2 = word3 * 3;
            raw4 = raw4 - word2;
            MATCHING_KEEP(raw4);
            raw4 = (unsigned)raw4 < 1;
            word3 = raw5 >> 31;
            packet7[6] = raw4;
            MATCHING_KEEP_CLOBBER(word3, "memory");
            word3 = high10 - word3;
            word2 = word3 * 3;
            raw5 = raw5 - word2;
            MATCHING_KEEP(raw5);
            raw5 = (unsigned)raw5 < 1;
            packet7[7] = raw5;
            if (packetGroup21 >= 7) {
                packetIndex16++;
                packetGroup21 = 0;
            }
            packetCount22++;
            packet7 += 8;
        } while (packetCount22 < 105);
    }
    loadedAddress15 = scratch.sp48;
    word2 = -1;
    M2C_FIELD(loadedAddress15, int*, 0x348) = word2;
    loadedAddress15 = scratch.sp38;
    word2 = M2C_FIELD(loadedAddress15, int*, 8);
    if (!word2) {
        caller4 = vertexTable14;
        caller5 = colorRecord23;
        caller6 = scratch.sp48;
        loadedAddress15 = (void*)scratch.sp40;
        word2 = (int)SharedRecord583_func_80050B00(caller4, caller5, caller6,
                                                   (unsigned char*)loadedAddress15 + 12, 1);
        loadedAddress15 = scratch.sp38;
        M2C_FIELD(loadedAddress15, int*, 8) = word2;
    }
    word3 = owner->state;
    word2 = 20;
    if (word3 == word2)
        goto advanceRaw;
    loadedAddress15 = scratch.sp38;
    word2 = M2C_FIELD(loadedAddress15, short*, 0x14);
    word3 = word2 * 4;
    argument4 = word3 + word2;
    word2 = word2 < 7;
    word3 = 80;
    if (!word2) {
        MATCHING_BARRIER("$2");
        M2C_FIELD(loadedAddress15, int*, 12) = 0;
        goto advanceRaw;
    }
    argument4 <<= 3;
    scratch.sp18 = 0;
    scratch.sp1C = 0;
    scratch.sp20 = word3;
    word2 = M2C_FIELD(&SharedRecord583_D_800658A0, short*, argument4);
    low8 = SharedRecord583Low(word2, word3);
    word2 = M2C_FIELD(&SharedRecord583_D_80065920, short*, argument4);
    {
        register int cosLow __asm__("lo");
        cosLow = word2 * word3;
        __asm__("" : "=l"(cosLow) : "0"(cosLow));
        caller5 = (void*)4;
        caller4 = owner;
        scratch.sp2C = 0;
        word3 = low8 >> 12;
        word2 = -word3;
        scratch.sp28 = word2;
        __asm__ volatile("" : "=l"(cosLow) : "0"(cosLow) : "memory");
        caller6 = (void*)cosLow;
    }
    word3 = (int)caller6 >> 12;
    scratch.sp30 = word3;
    SharedRecord583RefreshMobySpatialGridAndBasis(caller4, caller5, caller6);
    SharedRecord583TransformVectorByBasis(&owner->rotationMatrix, &scratch.sp28, &scratch.sp28);
    word2 = (int)SpawnParticle(1, 13, &owner->position, (Vector3D*)&scratch.sp28);
    loadedAddress15 = scratch.sp38;
    word3 = M2C_FIELD(loadedAddress15, int*, 12);
    caller4 = (void*)word2;
    if (word3) {
        word2 = 255;
        MATCHING_KEEP(word2);
        M2C_FIELD(caller4, unsigned char*, 12) = word2;
        M2C_FIELD(caller4, unsigned char*, 13) = word2;
        M2C_FIELD(caller4, unsigned char*, 14) = word2;
    }
    word2 = 190;
    if (caller4) {
        loadedAddress15 = scratch.sp38;
        M2C_FIELD(loadedAddress15, void**, 12) = caller4;
        M2C_FIELD(caller4, unsigned char*, 10) = word2;
        word2 = 255;
        MATCHING_KEEP(word2);
        M2C_FIELD(caller4, unsigned char*, 14) = word2;
    }
advanceRaw:
    loadedAddress15 = scratch.sp38;
    word2 = M2C_FIELD(loadedAddress15, unsigned short*, 20);
    word2++;
    M2C_FIELD(loadedAddress15, short*, 20) = word2;
    word3 = owner->state;
    word2 = 20;
    if (word3 != word2) {
        word2 = M2C_FIELD(loadedAddress15, short*, 0);
        word3 = word2;
        word2 = word2 < 600;
        if (word2) {
            word2 = word3 + 100;
            M2C_FIELD(loadedAddress15, short*, 0) = word2;
        }
    }
    loadedAddress15 = scratch.sp38;
    argument4 = M2C_FIELD(loadedAddress15, short*, 20);
    word2 = argument4 < 11;
    if (word2)
        goto test16Raw;
    word3 = owner->state;
    word2 = 20;
    if (word3 == word2)
        goto linkedRaw;
test16Raw:
    word2 = argument4 < 16;
    if (word2)
        goto zeroRaw;
    word3 = owner->state;
    word2 = 20;
    MATCHING_BARRIER("$15");
    if (word3 != word2)
        goto cleanupRaw;
zeroRaw:
    MATCHING_BARRIER_VOLATILE("$15");
    loadedAddress15 = 0;
    MATCHING_KEEP(loadedAddress15);
    if (!loadedAddress15)
        goto doneRaw;
    word3 = owner->state;
    word2 = 20;
    if (word3 != word2)
        goto cleanupRaw;
linkedRaw:
    word3 = owner->linkedMoby;
    word2 = word3 * 11;
    word3 = SharedRecord583_D_8006C550;
    word2 *= 8;
    word2 += word3;
    word3 = 10;
    M2C_FIELD(word2, unsigned char*, 73) = word3;
cleanupRaw:
    loadedAddress15 = scratch.sp38;
    caller4 = M2C_FIELD(loadedAddress15, void**, 8);
    if (caller4) {
        SharedRecord583_func_80050B88(caller4);
        loadedAddress15 = scratch.sp38;
    }
    caller4 = M2C_FIELD(loadedAddress15, void**, 12);
    if (caller4)
        SharedRecord583_func_80050B88(caller4);
    SharedRecord583DeleteMoby(owner);
doneRaw:;
}
#undef SharedRecord583Low
#undef SharedRecord583High
#undef M2C_FIELD
