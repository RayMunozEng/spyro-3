#include "matching.h"
#include "common.h"
#include "mobyutil.h"
#include "camera.h"
#include "spu.h"
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
void func_level_14_80075454(void* input) {
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
void func_level_14_800760B0(Moby* argument) {
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
void func_level_14_8007673C(void* input) {
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
void func_level_14_80077C8C(Moby* moby) {
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
void func_level_14_80077F4C(Moby* argument) {
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
void func_level_14_8007846C(Moby* moby) {
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
void func_level_14_800787EC(Moby* moby) {
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
void func_level_14_80078AF0(void* input) {
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
void func_level_14_80079664(Moby* moby) {
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
void func_level_14_80079A94(Moby* moby) {
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
void func_level_14_80079DFC(Moby* owner) {
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
void func_level_14_80079F88(Moby* moby) {
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

extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_8007158A;
void func_level_14_8007A0DC(Moby* moby) {
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
void func_level_14_8007A22C(Moby* actor) {
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
extern unsigned char D_80071579;
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
void func_level_14_8007A4D8(Moby* input) {
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
                D_80071579 = 1;
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
void func_level_14_8007A90C(Moby* input) {
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
void func_level_14_8007AD18(Moby* moby) {
    int* tag = moby->mobyTag;
    if (D_80070300[D_80066FCC[tag[0]]] & 1) {
        func_80021ED8((void*)tag[1], 0xFC, 0);
    }
    func_80055B18(moby);
}

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
void func_level_14_8007AD84(Moby* argument) {
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
void func_level_14_8007B1BC(Moby* moby) {
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

int func_80036220(Vector3D*, char*, int, int);
void func_level_14_8007B4EC(Moby* moby) {
    int* surfaceTicks = &spyro.ticksSinceLastSurfaceTouch;
    char* bounds = moby->mobyTag;
    if (*surfaceTicks && func_80036220((Vector3D*)((char*)surfaceTicks - 0xB8), bounds, 0, 0)) {
        spyro.unk17a = 0x10000082;
        spyro.unk20[1] = 7;
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
void func_level_14_8007B548(void* input) {
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

extern int func_80039714(Moby*);

/**
 * MobyUpdate_501() - func_level_14_8007C69C()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_14_8007C69C(Moby* moby) {
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
void func_level_14_8007C6BC(Moby* argument) {
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
void func_level_14_8007C8BC(Moby* argument) {
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
/* AI generated; not human reviewed. SCUS-94467 USA Rev0.
 * Evidence sibling4961:752 original instructions,37 dispatch targets and
 * one alignment word. Raw offsets, widths and integer expressions only.
 * Helper meanings, physical units, producer chains and cadence unresolved.
 * Uninstalled candidate; exact native/internal-target/data words and full
 * executable/every-overlay retail hashes are mandatory acceptance gates. */
#define A4962F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define A4962W(p, o) A4962F(p, int*, o)
#define A4962P(p, o) A4962F(p, unsigned char**, o)
#define A4962B(p, o) A4962F(p, unsigned char*, o)
#define A4962H(p, o) A4962F(p, short*, o)
#define A4962U(p, o) A4962F(p, unsigned short*, o)
#define A4962KEEP(v) __asm__("" : "=r"(v) : "0"(v))
extern unsigned char* A4962Models __asm__("D_8006C550");
extern unsigned char A4962Player[] __asm__("D_80070328");
extern int A4962PX __asm__("D_80070328"), A4962PY __asm__("D_80070328 + 4"),
    A4962PZ __asm__("D_80070328 + 8");
extern int A4962P24 __asm__("D_80070328 + 0x24"), A4962P298 __asm__("D_80070328 + 0x298");
extern unsigned char A4962PE __asm__("D_80070328 + 0xE");
extern int A4962C770 __asm__("D_8006C770"), A4962C640 __asm__("D_8006C640"),
    A4962Delta __asm__("D_8006C648");
extern unsigned char A4962C7B4 __asm__("D_8006C7B4"), A4962Flags[] __asm__("D_80070300");
extern int A4962C58C __asm__("D_8006C58C");
extern short A4962Cos[] __asm__("D_80065920"), A4962Sin[] __asm__("D_800658A0");
extern int (*A4962Particle)() __asm__("SpawnParticle");
extern int (*A4962Callback)() __asm__("unk_ovlheader_800743E8");
int A4962RequestMobyAnimation_0() __asm__("func_80034F40");
int A4962H3BFC0_1() __asm__("func_8003BFC0");
int A4962H3BE70_2() __asm__("func_8003BE70");
int A4962PlanarHeadingLookup_3() __asm__("func_8004E880");
int A4962RequestMobyAnimation_4() __asm__("func_80034F40");
int A4962H36A68_5() __asm__("func_80036A68");
int A4962TurnMobyTowardPlayer_6() __asm__("func_8003573C");
int A4962CountTimerDown_7() __asm__("func_800359A4");
int A4962CopyVector_8() __asm__("func_8004F178");
int A4962ShiftVectorRightTowardZero_9() __asm__("func_8004F110");
int A4962AddVector_10() __asm__("func_8004F194");
int A4962ApproximatePlanarDistance_11() __asm__("func_8004F334");
int A4962TurnMobyTowardPlayer_12() __asm__("func_8003573C");
int A4962RequestMobyAnimation_13() __asm__("func_80034F40");
int A4962RequestMobyAnimation_14() __asm__("func_80034F40");
int A4962RequestMobyAnimation_15() __asm__("func_80034F40");
int A4962RequestMobyAnimation_16() __asm__("func_80034F40");
int A4962RequestMobyAnimation_17() __asm__("func_80034F40");
int A4962RequestMobyAnimation_18() __asm__("func_80034F40");
int A4962CountTimerDown_19() __asm__("func_800359A4");
int A4962ApproximatePlanarDistance_20() __asm__("func_8004F334");
int A4962RequestMobyAnimation_21() __asm__("func_80034F40");
int A4962RequestMobyAnimation_22() __asm__("func_80034F40");
int A4962RequestMobyAnimation_23() __asm__("func_80034F40");
int A4962H3BFC0_24() __asm__("func_8003BFC0");
int A4962PlayMobySoundEvent_25() __asm__("func_8003BABC");
int A4962RandSignedBetween_26() __asm__("func_800363DC");
int A4962RandSignedBetween_27() __asm__("func_800363DC");
int A4962RandBetween_28() __asm__("func_8003636C");
int A4962ApproximatePlanarDistance_29() __asm__("func_8004F334");
int A4962PlanarHeadingLookup_30() __asm__("func_8004E880");
int A4962CountTimerDown_31() __asm__("func_800359A4");
int A4962H3BFC0_32() __asm__("func_8003BFC0");
int A4962H3BE70_33() __asm__("func_8003BE70");
int A4962RequestMobyAnimation_34() __asm__("func_80034F40");
int A4962PlanarHeadingLookup_35() __asm__("func_8004E880");
int A4962TurnMobyTowardHeading_36() __asm__("func_8003585C");
int A4962RequestMobyAnimation_37() __asm__("func_80034F40");
int A4962CopyVector_38() __asm__("func_8004F178");
int A4962RandSignedBetween_39() __asm__("func_800363DC");
int A4962RandSignedBetween_40() __asm__("func_800363DC");
int A4962RandSignedBetween_41() __asm__("func_800363DC");
int A4962RandSignedBetween_42() __asm__("func_800363DC");
int A4962RandSignedBetween_43() __asm__("func_800363DC");
int A4962RandBetween_44() __asm__("func_8003636C");
int A4962RequestMobyAnimation_45() __asm__("func_80034F40");
int A4962CountTimerDown_46() __asm__("func_800359A4");
int A4962TurnMobyTowardPlayer_47() __asm__("func_8003573C");
int A4962RequestMobyAnimation_48() __asm__("func_80034F40");
int A4962RandSignedBetween_49() __asm__("func_800363DC");
int A4962RandSignedBetween_50() __asm__("func_800363DC");
int A4962RandBetween_51() __asm__("func_8003636C");
int A4962H35EE0_52() __asm__("func_80035EE0");
int A4962CopyVector_53() __asm__("func_8004F178");
int A4962CountTimerDown_54() __asm__("func_800359A4");
int A4962H1A358_55() __asm__("func_8001A358");
int A4962RefreshMobySpatialGridAndBasis_56() __asm__("func_80055D24");
int A4962H3BA00_57() __asm__("func_8003BA00");
int A4962H369B8_58() __asm__("func_800369B8");
int A4962DeleteMoby_59() __asm__("func_80055B18");
void func_level_14_8007CB70(unsigned char* input) {
    struct {
        int v18[4], v28[4], v38[4], v48[2], v50[4], v60[4], v70[4], v80[4];
    } frame;
    register unsigned char* owner17 __asm__("$17");
    register unsigned char* private19 __asm__("$19");
    register unsigned char* peer18 __asm__("$18");
    register unsigned char* ptr16 __asm__("$16");
    register int saved16 __asm__("$16");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int arg4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    register int arg7 __asm__("$7");
    register unsigned char* ptr4 __asm__("$4");
    register unsigned char* ptr5 __asm__("$5");
    owner17 = input;
    arg5 = A4962B(owner17, 0x48);
    private19 = A4962P(owner17, 0);
    MATCHING_KEEP2(arg5, private19);
    if ((unsigned)(arg5 - 5) >= 2 && A4962W(owner17, 0x18) != 0) {
        arg4 = A4962W(private19, 8);
        if (arg4 >= 0) {
            work3 = arg5 & 255;
            A4962KEEP(work3);
            if (work3 == 36)
                goto firstPeer;
            work2 = (unsigned)(arg5 - 2) < 2;
            A4962KEEP(work2);
            if (work2) {
            firstPeer:
                work2 = arg4 * 11;
                A4962KEEP(work2);
                work3 = (int)A4962Models;
                A4962KEEP(work3);
                ptr16 = (unsigned char*)work3 + (work2 << 3);
                work3 = A4962H(ptr16, 0x36);
                if (work3 == 360 && !(A4962B(ptr16, 0x48) & 128)) {
                    A4962RequestMobyAnimation_0(ptr16, 5);
                    A4962B(ptr16, 0x40) = 240;
                    goto peer20;
                }
                if (work3 == 271) {
                peer20:
                    A4962B(ptr16, 0x48) = 20;
                }
            }
        }
        if (A4962H3BFC0_1(owner17, A4962W(private19, 0x20)))
            A4962H3BE70_2(A4962W(private19, 0x20));
        work3 = A4962PX;
        arg4 = A4962W(owner17, 12);
        work2 = A4962PY;
        arg5 = A4962W(owner17, 16);
        work2 = A4962PlanarHeadingLookup_3(work3 - arg4, work2 - arg5, 0);
        arg4 = (int)owner17;
        arg5 = 5;
        MATCHING_OBSERVE2_VOLATILE(arg4, arg5);
        A4962B(owner17, 0x46) = work2;
        work3 = A4962PE;
        A4962KEEP(work3);
        A4962H(private19, 4) = 400;
        A4962H(private19, 2) = 200;
        A4962H(private19, 0) = 180;
        A4962B(private19, 6) = work3;
        A4962B(owner17, 0x48) = 5;
        A4962RequestMobyAnimation_4(owner17, 5);
        A4962B(owner17, 0x4A) = 255;
        A4962H36A68_5(owner17, 0, 0, 0);
    }
    switch (A4962B(owner17, 0x48)) {
        case 0:
            A4962TurnMobyTowardPlayer_6(owner17, 6, 0, 0);
            if (!A4962CountTimerDown_7(private19, 2))
                break;
            ptr16 = A4962Player + 0x98;
            A4962CopyVector_8(frame.v18, ptr16);
            frame.v18[0] *= 30;
            frame.v18[1] *= 30;
            frame.v18[2] *= 30;
            A4962ShiftVectorRightTowardZero_9(frame.v18, 6);
            A4962AddVector_10(frame.v18, frame.v18, ptr16 - 0x98);
            work3 = A4962ApproximatePlanarDistance_11(owner17 + 12, frame.v18);
            A4962KEEP(work3);
            if (work3 < 4096)
                goto enter31;
            if (A4962B(private19, 7)) {
                work2 = work3 < 6144;
                A4962KEEP(work2);
                if (work2) {
                    work2 = 32;
                    goto store32;
                }
            }
            break;
        case 1:
            A4962TurnMobyTowardPlayer_12(owner17, 6, 0, 0);
            if (A4962C770) {
                A4962B(owner17, 0x48) = 0;
                goto reset0;
            }
            break;
        case 36:
            if (A4962C640 == 0) {
                if (A4962C7B4 & 1)
                    goto resetState;
                if (A4962Flags[A4962C58C] & 1)
                    goto resetState;
            }
            arg4 = A4962W(private19, 8);
            if (arg4 == -1) {
            resetState:
                A4962B(owner17, 0x48) = 0;
            reset0:
                A4962RequestMobyAnimation_13(owner17, 0);
                break;
            }
            work2 = arg4 * 11;
            A4962KEEP(work2);
            work3 = (int)A4962Models;
            A4962KEEP(work3);
            ptr5 = (unsigned char*)work3 + (work2 << 3);
            if (A4962H(ptr5, 0x36) == 360) {
                work2 = 9;
                MATCHING_OBSERVE(work2);
                arg4 = A4962B(ptr5, 0x48);
                A4962KEEP(arg4);
                work3 = arg4 & 255;
                if (work3 == work2)
                    goto enter32;
                work2 = arg4 & 128;
                A4962KEEP(work2);
                if (work2)
                    goto enter32;
            }
            work3 = A4962W(owner17, 20) - 50;
            A4962W(owner17, 20) = work3;
            work2 = A4962W(ptr5, 20) + 1300;
            work3 = work3 < work2;
            A4962KEEP(work3);
            if (work3) {
                A4962B(owner17, 0x48) = 2;
                A4962RequestMobyAnimation_14(owner17, 2);
            }
            break;
        case 2:
            work3 = A4962W(private19, 8);
            A4962KEEP(work3);
            work2 = work3 * 11;
            A4962KEEP(work2);
            work3 = (int)A4962Models;
            A4962KEEP(work3);
            ptr4 = (unsigned char*)work3 + (work2 << 3);
            work3 = A4962H(ptr4, 0x36);
            if (work3 != 271) {
                work2 = A4962W(ptr4, 20) + 1000;
                work3 = A4962W(owner17, 20);
                if (work2 < work3) {
                    work2 = work3 - 50;
                    A4962KEEP(work2);
                    A4962W(owner17, 20) = work2;
                }
                work3 = A4962H(ptr4, 0x36);
            }
            if (work3 == 360) {
                work2 = 9;
                MATCHING_OBSERVE(work2);
                arg5 = A4962B(ptr4, 0x48);
                A4962KEEP(arg5);
                work3 = arg5 & 255;
                if (work3 == work2)
                    goto enter32;
                work2 = arg5 & 128;
                A4962KEEP(work2);
                if (work2)
                    goto enter32;
            }
            if (!A4962C770)
                break;
            if (A4962H(ptr4, 0x36) == 271) {
                A4962B(owner17, 0x47) = 6;
                A4962B(ptr4, 0x48) = 2;
                A4962RequestMobyAnimation_15(ptr4, 2);
                A4962H(private19, 0) = 120;
            } else {
                A4962H(private19, 0) = 1200;
                A4962B(ptr4, 0x48) = 7;
                A4962RequestMobyAnimation_16(ptr4, 7);
            }
            A4962B(owner17, 0x48) = 3;
            A4962RequestMobyAnimation_17(owner17, 3);
            break;
        case 3:
            work3 = A4962W(private19, 8);
            A4962KEEP(work3);
            work2 = work3 * 11;
            A4962KEEP(work2);
            work3 = (int)A4962Models;
            A4962KEEP(work3);
            peer18 = (unsigned char*)work3 + (work2 << 3);
            if (A4962H(peer18, 0x36) == 360) {
                work2 = 9;
                MATCHING_OBSERVE(work2);
                arg4 = A4962B(peer18, 0x48);
                A4962KEEP(arg4);
                work3 = arg4 & 255;
                if (work3 == work2)
                    goto enter32;
                work2 = arg4 & 128;
                A4962KEEP(work2);
                if (work2) {
                enter32:
                    A4962RequestMobyAnimation_18(owner17, 4);
                    A4962B(owner17, 0x40) = 240;
                    work2 = 32;
                store32:
                    A4962B(owner17, 0x48) = work2;
                    break;
                }
            }
            work3 = A4962H(private19, 0);
            if (work3) {
                work2 = work3 < 200;
                A4962KEEP(work2);
                arg6 = 20;
                if (work2) {
                    arg6 = 10;
                    goto rise;
                }
                work2 = work3 < 100;
                A4962KEEP(work2);
                if (work2)
                    arg6 = 5;
            rise:
                A4962W(owner17, 20) += arg6;
                A4962W(peer18, 20) += arg6;
                A4962CountTimerDown_19(private19, 2);
            }
            if (A4962H(peer18, 0x36) == 271)
                break;
            if (A4962ApproximatePlanarDistance_20(owner17 + 12, A4962Player) >= 10240)
                break;
            A4962RequestMobyAnimation_21(owner17, 4);
            arg4 = (int)peer18;
            arg5 = 5;
            MATCHING_OBSERVE2_VOLATILE(arg4, arg5);
            saved16 = 240;
            A4962B(owner17, 0x40) = saved16;
            A4962B(owner17, 0x48) = 32;
            A4962RequestMobyAnimation_22(peer18, 5);
            A4962B(peer18, 0x40) = saved16;
            A4962B(peer18, 0x48) = 20;
            break;
        case 30:
            if (!A4962C770)
                break;
        enter31:
            A4962RequestMobyAnimation_23(owner17, 6);
            A4962B(owner17, 0x48) = 31;
            A4962H(private19, 0) = 64;
            break;
        case 31:
            if (!A4962H3BFC0_24(owner17, A4962W(private19, 0x20)))
                A4962W(private19, 0x20) = A4962PlayMobySoundEvent_25(owner17, 0, 4);
            if (A4962H(private19, 0) >= 11) {
                arg4 = 0;
                MATCHING_OBSERVE_VOLATILE(arg4);
                work3 = A4962Cos[A4962B(owner17, 0x46)];
                work2 = work3 * 225;
                A4962KEEP(work2);
                work3 = A4962W(owner17, 12);
                work2 >>= 10;
                work3 += work2;
                A4962KEEP(work3);
                frame.v28[0] = work3;
                work3 = A4962Sin[A4962B(owner17, 0x46)];
                work2 = work3 * 225;
                A4962KEEP(work2);
                work3 = A4962W(owner17, 16);
                work2 >>= 10;
                work3 += work2;
                A4962KEEP(work3);
                frame.v28[1] = work3;
                frame.v28[2] = A4962W(owner17, 20) + 256;
                frame.v38[0] = A4962RandSignedBetween_26(0, 20) - 10;
                frame.v38[1] = A4962RandSignedBetween_27(0, 20) - 10;
                frame.v38[2] = A4962RandBetween_28(5, 8);
                A4962Particle(1, 39, frame.v28, frame.v38);
            }
            if (!A4962B(owner17, 0x49)) {
                ptr16 = A4962Player + 0x50;
                A4962KEEP(ptr16);
                if (A4962W(ptr16, 0) != 12 &&
                    A4962ApproximatePlanarDistance_29(owner17 + 12, ptr16 - 0x50) < 2048) {
                    work3 = A4962PZ - 256;
                    work2 = A4962W(owner17, 20) - work3;
                    if (work2 < 0)
                        work2 = -work2;
                    if (work2 >= 512)
                        goto tickReady;
                    {
                        arg6 = 0;
                        MATCHING_OBSERVE_VOLATILE(arg6);
                        work2 = A4962P24;
                        A4962KEEP(work2);
                        A4962P24 = work2 | 1;
                        MATCHING_BARRIER_VOLATILE("memory");
                        work3 = A4962W(ptr16, -0x50);
                        arg4 = A4962W(owner17, 12);
                        work2 = A4962PY;
                        arg5 = A4962W(owner17, 16);
                        A4962P298 = A4962PlanarHeadingLookup_30(work3 - arg4, work2 - arg5, 0);
                        A4962B(owner17, 0x49) = 1;
                    }
                }
            }
            arg4 = (int)private19;
            MATCHING_OBSERVE(arg4);
        tickReady:
            A4962B(owner17, 0x46) += A4962Delta * 20;
            if (A4962CountTimerDown_31(arg4, 2)) {
                if (A4962H3BFC0_32(owner17, A4962W(private19, 0x20)))
                    A4962H3BE70_33(A4962W(private19, 0x20));
                A4962B(owner17, 0x48) = 1;
                A4962RequestMobyAnimation_34(owner17, 1);
                A4962H(private19, 0) = 60;
                A4962B(owner17, 0x49) = 0;
            }
            break;
        case 32:
            work2 = (int)A4962P(private19, 0x1C);
            work3 = (int)A4962P(work2, 12);
            work2 = A4962W(owner17, 12);
            arg4 = A4962W(work3, 0);
            arg4 -= work2;
            A4962KEEP(arg4);
            frame.v48[0] = arg4;
            arg5 = A4962W(work3, 4);
            work2 = A4962W(owner17, 16);
            arg5 -= work2;
            A4962KEEP(arg5);
            frame.v48[1] = arg5;
            work2 = A4962PlanarHeadingLookup_35(arg4, arg5, 0);
            if (A4962TurnMobyTowardHeading_36(owner17, work2, 8, 1, 0, 0)) {
                A4962RequestMobyAnimation_37(owner17, 4);
                A4962B(owner17, 0x40) = 240;
                A4962B(owner17, 0x48) = 33;
            }
            break;
        case 33:
            ptr16 = (unsigned char*)frame.v50;
            A4962CopyVector_38(ptr16, owner17 + 12);
            frame.v50[0] += A4962RandSignedBetween_39(0, 150);
            frame.v50[1] += A4962RandSignedBetween_40(0, 150);
            frame.v50[2] += A4962RandSignedBetween_41(0, 150);
            frame.v60[0] = A4962RandSignedBetween_42(0, 10);
            frame.v60[1] = A4962RandSignedBetween_43(0, 10);
            frame.v60[2] = A4962RandBetween_44(5, 8);
            A4962Particle(1, 39, ptr16, frame.v60);
            if (A4962Callback(owner17, A4962P(private19, 0x1C), private19 + 12) == 1) {
                work2 = (int)A4962P(private19, 0x1C);
                work3 = A4962H(work2, 0) - 1;
                if (A4962H(work2, 2) == work3) {
                    A4962RequestMobyAnimation_45(owner17, 0);
                    A4962B(owner17, 0x40) = 240;
                    A4962B(owner17, 0x48) = 34;
                    A4962B(private19, 7) = 0;
                    A4962H(private19, 0) = 90;
                }
            }
            break;
        case 34:
            work3 = A4962B(owner17, 0x45);
            A4962KEEP(work3);
            work2 = work3 & 255;
            if (work2) {
                if ((unsigned)work2 < 128)
                    work2 = work3 - 1;
                else
                    work2 = work3 + 1;
                A4962B(owner17, 0x45) = work2;
            }
            if (A4962CountTimerDown_46(private19, 2) ||
                A4962TurnMobyTowardPlayer_47(owner17, 8, 1, 0)) {
                A4962B(owner17, 0x45) = 0;
                A4962B(owner17, 0x48) = 0;
                A4962RequestMobyAnimation_48(owner17, 0);
            }
            break;
        case 5:
        case 6:
            work3 = A4962Cos[A4962B(owner17, 0x46)];
            work2 = work3 * 225;
            A4962KEEP(work2);
            work3 = A4962W(owner17, 12);
            work2 >>= 10;
            work3 += work2;
            A4962KEEP(work3);
            frame.v70[0] = work3;
            work3 = A4962Sin[A4962B(owner17, 0x46)];
            work2 = work3 * 225;
            A4962KEEP(work2);
            work3 = A4962W(owner17, 16);
            work2 >>= 10;
            work3 += work2;
            A4962KEEP(work3);
            frame.v70[1] = work3;
            frame.v70[2] = A4962W(owner17, 20);
            frame.v80[0] = A4962RandSignedBetween_49(0, 20) - 10;
            frame.v80[1] = A4962RandSignedBetween_50(0, 20) - 10;
            work2 = A4962RandBetween_51(5, 8);
            arg4 = 1;
            arg5 = 39;
            MATCHING_OBSERVE2_VOLATILE(arg4, arg5);
            ptr16 = (unsigned char*)frame.v70;
            arg6 = (int)ptr16;
            MATCHING_OBSERVE_VOLATILE(arg6);
            work3 = (int)A4962Particle;
            A4962KEEP(work3);
            frame.v80[2] = work2;
            ((int (*)())work3)(arg4, arg5, ptr16, frame.v80);
            arg4 = (int)owner17;
            MATCHING_OBSERVE(arg4);
            work3 = A4962H(private19, 2);
            work2 = A4962W(owner17, 20);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(work2, "$7");
            arg7 = 0;
            MATCHING_OBSERVE(arg7);
            A4962W(owner17, 20) = work2 + work3;
            arg5 = A4962B(private19, 6);
            A4962KEEP(arg5);
            work3 = A4962U(private19, 4) - 4;
            arg6 = (short)work3;
            work2 = A4962U(private19, 2) - 16;
            A4962H(private19, 2) = work2;
            A4962H(private19, 4) = work3;
            A4962H35EE0_52(owner17, arg5, arg6, 0, 500, 32);
            A4962CopyVector_53(ptr16, owner17 + 12);
            if (A4962CountTimerDown_54(private19, 2) ||
                (A4962H(private19, 0) < 150 && A4962H1A358_55(ptr16, 512))) {
                A4962RefreshMobySpatialGridAndBasis_56(owner17, 4);
                A4962H3BA00_57(owner17);
                A4962H369B8_58(owner17, 40);
                A4962DeleteMoby_59(owner17);
            }
            break;
    }
}
#undef A4962F
#undef A4962W
#undef A4962P
#undef A4962B
#undef A4962H
#undef A4962U
#undef A4962KEEP


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
void func_level_14_8007D730(Moby* argument) {
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

/* AI generated; not human reviewed. Original SCUS-94467 Rev0
 * level14 8007DACC..8007DE20; units, helpers and cadence unresolved. */
extern int Decoded214Gate __asm__("D_8006C7C0");
extern int Decoded214Tick __asm__("D_8006C648");
extern Vector3D Decoded214Camera __asm__("D_8006E020");
extern int Decoded214CameraY __asm__("D_8006E024");
extern int Decoded214CameraZ __asm__("D_8006E028");
int Decoded214Timer(void*, int) __asm__("func_800359A4");
int Decoded214Distance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int Decoded214Angle(int, int, int) __asm__("func_8004E880");
void func_level_14_8007DACC(Moby* argument) {
    Vector3D first;
    int pad;
    Vector3D second;
    int pad2;
    register Moby* moby __asm__("$17") = argument;
    register int* tag __asm__("$16");
    register int one __asm__("$18");
    register Vector3D* position __asm__("$18");
    register Vector3D* camera __asm__("$16");
    register int state __asm__("$3");
    MATCHING_KEEP(moby);
    one = 1;
    MATCHING_KEEP(one);
    Decoded214Gate = 0;
    state = moby->state;
    tag = moby->mobyTag;
    if (state == one)
        goto state1;
    if (state < 2) {
        if (state == 0)
            goto state0;
        goto done;
    }
    if (state == 2)
        goto state2;
    if (state == 3)
        goto state3;
    goto done;
state0:
    if (Decoded214Timer(tag, 4))
        goto release;
    {
        register int mode __asm__("$4") = 1;
        register int kind __asm__("$5") = 13;
        MATCHING_KEEP2(mode, kind);
        position = &moby->position;
        first.x = 0;
        first.y = 0;
        first.z = 0;
        {
            register unsigned char* particle __asm__("$3") =
                SpawnParticle(mode, kind, position, &first);
            if (particle)
                particle[10] = 250;
        }
    }
    if (tag[0] < 10) {
        moby->colour.r = tag[0] * 28;
        moby->colour.g = tag[0] * 56 / 3;
        moby->colour.b = (tag[0] * 25) >> 2;
    }
    {
        register int value __asm__("$2") = tag[0];
        register int size __asm__("$3");
        MATCHING_KEEP(value);
        size = value * 2 + 48;
        *((unsigned char*)moby + 0x4F) = size;
        value = tag[5];
        if (value) {
            value = size - value;
            MATCHING_KEEP(value);
            *((unsigned char*)moby + 0x4F) = value;
        }
    }
    {
        register Vector3D* destination __asm__("$4") = position;
        MATCHING_KEEP(destination);
        camera = &Decoded214Camera;
        {
            int distance = Decoded214Distance(destination, camera);
            moby->angle.pitch =
                Decoded214Angle(distance, Decoded214CameraZ - moby->position.z, 0) - 64;
        }
    }
    moby->angle.yaw =
        Decoded214Angle(camera->x - moby->position.x, Decoded214CameraY - moby->position.y, 0);
    goto done;
state1:
state3:
    *((unsigned char*)moby + 0x41) = 0;
    *((unsigned char*)moby + 0x4C) = 0;
    *((unsigned char*)moby + 0x4D) = 0;
    second.x = 0;
    second.y = 0;
    second.z = 0;
    {
        register unsigned char* particle __asm__("$4") =
            SpawnParticle(1, 13, &moby->position, &second);
        if (moby->state == 3 && particle)
            particle[10] = 220;
    }
    func_8004F194(&moby->position, &moby->position, (Vector3D*)(tag + 1));
    {
        register int speed __asm__("$3") = tag[4] + 5;
        tag[4] = speed;
        moby->position.z -= speed;
    }
    if (Decoded214Timer(tag, 4))
        goto release;
    goto done;
state2:
    if (!Decoded214Timer(tag, 4))
        goto settled;
release:
    func_80055B18(moby);
    goto done;
settled:
    if (moby->animationState.nextId == one) {
        if (tag[0] < 10) {
            func_80034F80(moby, 0);
            *((unsigned char*)moby + 0x4F) = 192;
        }
    }
    if (!moby->animationState.nextId) {
        moby->colour.r = tag[0] * 28;
        moby->colour.g = tag[0] * 56 / 3;
        moby->colour.b = (tag[0] * 25) >> 2;
        *((unsigned char*)moby + 0x4F) = tag[0] * 4 + 96;
    } else
        *((unsigned char*)moby + 0x4F) -= Decoded214Tick * 3;
    goto done;
done:;
}


int func_8003636C(int, int);
int func_80039714(Moby*);
void func_level_14_8007DE24(Moby* moby) {
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
/* SCUS-94467 USA Rev0 original8007DF60. AI generated; not human reviewed.
 * Required1897 original native instructions,38 absolute selectors,actual controls
 * and data addends,plus unchanged parent EXE/every-overlay hashes.
 * Original frame118 saves S0..S7/RA at F8..114; real produced locals20..F4.
 * OwnerS2 is the parameter,privateS4 is owner+0. All saved phases and consumed
 * scalar/vector outputs follow the primary original CFG/helper producer proof.
 * Four complete signed64 products retain their original low32 words before
 * signed shifts12. The compiler-endian union is a register-product view only.
 * Empty metadata observes complete initialized values/actual addresses and
 * retires only dead GP phases; it emits no CPU instructions. No fixed FP/SP,
 * opcode asm,manual outgoing homes or overlapping live fixed aliases.
 * Counter predicate and increment are separate source phases. Fresh tint1 is
 * produced at its actual comparison consumer after the zero guard; the original
 * compiler places it in the zero-guard delay and the counter increment in its
 * original BNEZ delay. Exact words and actual entry targets remain mandatory.
 * Helper types describe four-byte ABI views,not full external semantics.
 * External allocation/writer closure,full helper semantics,coordinate domains,
 * cadence,Rev1 correspondence,runtime captures and human review remain open.
 * This proves original-compiler identity for this slice,not complete game
 * behavior or portable signed-overflow/alias behavior. Pipeline is unchanged.
 */
typedef union {
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
} Level14_7DF60CompleteProduct;
/* SCUS-94467 USA Rev0:1897 original instructions+38 selector/data words=1935 owned words. AI generated,not human reviewed. Uninstalled;all native/control/data/producer/hash gates mandatory. */
#define Level14_7DF60Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level14_7DF60CompleteValue(v) __asm__("" : "=r"(v) : "0"(v))
void Level14_7DF60_func_80013ACC(void*, void*) __asm__("func_80013ACC");
void Level14_7DF60_func_80013D44(void*, int, void*, int) __asm__("func_80013D44");
int Level14_7DF60_func_80018368(void*, void*, int) __asm__("func_80018368");
void Level14_7DF60_func_8001BA30(void*, int, int, int, int, int) __asm__("func_8001BA30");
int Level14_7DF60_func_8001C288(void*, void*, void*) __asm__("func_8001C288");
void Level14_7DF60_func_80021ED8(void*, int, int) __asm__("func_80021ED8");
int Level14_7DF60_func_8002803C(void*, void*, void*, void*, int, int, int) __asm__("func_8002803C");
int Level14_7DF60_func_80028154(void*) __asm__("func_80028154");
void Level14_7DF60RequestMobyAnimation(void*, int) __asm__("func_80034F40");
void Level14_7DF60SetMobyAnimation(void*, int) __asm__("func_80034F80");
int Level14_7DF60TurnMobyTowardPlayer(void*, int, int, int) __asm__("func_8003573C");
int Level14_7DF60TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Level14_7DF60CountTimerDown(void*, int) __asm__("func_800359A4");
int Level14_7DF60ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
int Level14_7DF60_func_80035DDC(void*, int, int, int, int) __asm__("func_80035DDC");
int Level14_7DF60RandBetween(int, int) __asm__("func_8003636C");
int Level14_7DF60_func_800391E8(void*, int, int, int, int, int, int) __asm__("func_800391E8");
void Level14_7DF60_func_8003BA00(void*) __asm__("func_8003BA00");
int Level14_7DF60PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
void Level14_7DF60_func_8003BE70(void*) __asm__("func_8003BE70");
int Level14_7DF60_func_8003BFC0(void*, int) __asm__("func_8003BFC0");
int Level14_7DF60PlanarHeadingLookup(void*, int, int) __asm__("func_8004E880");
void Level14_7DF60TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level14_7DF60MeasureVectorLength(void*, void*) __asm__("func_8004EDE8");
void Level14_7DF60ScaleVectorRatioQ15(void*, int, int) __asm__("func_8004F08C");
void Level14_7DF60CopyVector(void*, void*) __asm__("func_8004F178");
void Level14_7DF60AddVector(void*, void*, void*) __asm__("func_8004F194");
void Level14_7DF60SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Level14_7DF60AbsoluteByteAngleDelta(void*, void*) __asm__("func_8004F264");
int Level14_7DF60ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
void Level14_7DF60DeleteMoby(void*) __asm__("func_80055B18");
void Level14_7DF60RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Level14_7DF60_func_80055E84(void*) __asm__("func_80055E84");
void Level14_7DF60InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern int Level14_7DF60_D_800658A0 __asm__("D_800658A0");
extern int Level14_7DF60_D_80065920 __asm__("D_80065920");
extern unsigned int Level14_7DF60_D_8006C550 __asm__("D_8006C550");
extern volatile int Level14_7DF60_D_8006C574 __asm__("D_8006C574");
extern volatile int Level14_7DF60_D_8006C578 __asm__("D_8006C578");
extern int Level14_7DF60_D_8006C648 __asm__("D_8006C648");
extern unsigned int Level14_7DF60_D_8006C704 __asm__("D_8006C704");
extern int Level14_7DF60_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level14_7DF60_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level14_7DF60_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level14_7DF60_D_8006C7E8 __asm__("D_8006C7E8");
extern int Level14_7DF60_D_8006E020 __asm__("D_8006E020");
extern int Level14_7DF60_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level14_7DF60_D_8006E040 __asm__("D_8006E040");
extern int Level14_7DF60_D_80070328 __asm__("D_80070328");
extern int (*Level14_7DF60SpawnFragments)(void*, int, int, int, int, int) __asm__("SpawnFragments");
extern int (*Level14_7DF60SpawnMoby)(int, int) __asm__("SpawnMoby");
extern int (*Level14_7DF60SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");
extern int Level14_7DF60_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level14_7DF60_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level14_7DF60_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
void func_level_14_8007DF60(void* ownerParameter) {
    Level14_7DF60CompleteProduct completeSignedProduct;
    int counterPredicate;
    register int resultOrArithmetic2 __asm__("$2"), fieldOrAddress3 __asm__("$3"),
        argumentOrValue4 __asm__("$4"), argumentOrValue5 __asm__("$5"),
        argumentOrValue6 __asm__("$6"), argumentOrValue7 __asm__("$7"), productLow8 __asm__("$8");
    register int savedActorOrVector16 __asm__("$16"), savedActorOrTrig17 __asm__("$17"),
        owner18 __asm__("$18"), savedIndexOrAddress19 __asm__("$19"), private20 __asm__("$20"),
        saved21 __asm__("$21"), saved22 __asm__("$22"), saved23 __asm__("$23");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC, spF0, spF4;
    } originalFrame;
    int captured_v0_13;
    short captured_v0_8;
    short captured_v0_9;
    short captured_v1_3;
    short working_v0_2;
    int captured_a0_4;
    int captured_v0_18;
    int captured_v0_19;
    int captured_v0_20;
    int captured_v0_25;
    int captured_v0_3;
    int captured_v1_6;
    int captured_v1_9;
    int working_v0;
    int working_v0_6;
    int working_v0_7;
    unsigned short captured_v0_10;
    unsigned short captured_v0_11;
    unsigned short captured_v0_24;
    unsigned short captured_v1_4;
    unsigned short working_v0_8;
    int captured_a0_3;
    unsigned char captured_v0_12;
    int captured_v0_14;
    int captured_v0_16;
    unsigned char captured_v0_17;
    unsigned char captured_v1;
    unsigned char captured_v1_5;
    unsigned char captured_v1_7;
    unsigned char captured_v1_8;
    unsigned char working_v0_3;
    unsigned char working_v0_4;
    unsigned char working_v0_5;
    int captured_a0;
    int captured_a0_2;
    int captured_a2;
    int captured_v0_21;
    int captured_v0_23;
    int captured_v0_2;
    owner18 = (int)ownerParameter;
    private20 = Level14_7DF60Field(owner18, int*, 0);
    Level14_7DF60RefreshMobySpatialGridAndBasis((void*)(owner18), (int)(7));
    captured_v1 = Level14_7DF60Field(owner18, unsigned char*, 0x48);
    if ((captured_v1 != 0x1E) && (captured_v1 != 0x15)) {
        if (Level14_7DF60Field(owner18, int*, 0x18) & 0x100000) {
            resultOrArithmetic2 = Level14_7DF60_D_8006C7C4;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(resultOrArithmetic2, "$3");
            fieldOrAddress3 = 1;
            Level14_7DF60Field(private20, short*, 30) = fieldOrAddress3;
            Level14_7DF60Field(private20, unsigned short*, 28) = 0;
            Level14_7DF60Field(private20, short*, 32) = fieldOrAddress3;
            if ((resultOrArithmetic2 == 0) && (Level14_7DF60Field(private20, short*, 0x26) == 0)) {
                resultOrArithmetic2 = Level14_7DF60Field(private20, int*, 24);
                Level14_7DF60Field(private20, short*, 38) = fieldOrAddress3;
                resultOrArithmetic2 -= 2;
                working_v0 = resultOrArithmetic2;
            } else {
                resultOrArithmetic2 = Level14_7DF60Field(private20, int*, 24);
                Level14_7DF60Field(private20, short*, 38) = 0;
                resultOrArithmetic2--;
                working_v0 = resultOrArithmetic2;
            }
            Level14_7DF60Field(private20, int*, 0x18) = working_v0;
            Level14_7DF60Field(owner18, unsigned char*, 0x44) =
                (unsigned char)(Level14_7DF60Field(owner18, unsigned char*, 0x44) - 1);
            captured_a0 = Level14_7DF60Field(private20, int*, 0x2C);
            if ((captured_a0 != 0) && (Level14_7DF60Field(owner18, unsigned char*, 0x48) != 0x2A)) {
                Level14_7DF60Field(captured_a0, unsigned char*, 0x48) = 3U;
                Level14_7DF60RequestMobyAnimation(
                    (void*)(Level14_7DF60Field(private20, int*, 0x2C)), (int)(3));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x2AU;
            }
            if (Level14_7DF60Field(private20, int*, 0x18) <= 0) {
                if (Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0x280) < 0) {
                    Level14_7DF60Field(private20, int*, 0x18) = 1;
                }
                if (Level14_7DF60Field(private20, int*, 0x18) <= 0) {
                    Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0x284) = 0x190;
                    captured_a0_2 = Level14_7DF60Field(private20, int*, 0x2C);
                    if (captured_a0_2 != 0) {
                        Level14_7DF60DeleteMoby((void*)(captured_a0_2));
                        Level14_7DF60Field(private20, int*, 0x2C) = 0;
                    }
                    Level14_7DF60PlayMobySoundEvent((void*)(owner18), (int)(1), (int)(0));
                    Level14_7DF60Field(private20, short*, 2) = 0x78;
                    Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x1EU;
                    Level14_7DF60_func_80028154((void*)(Level14_7DF60Field(private20, int*, 0x14)));
                    Level14_7DF60Field(owner18, signed char*, 0x41) = 0;
                    Level14_7DF60Field(owner18, signed char*, 0x4C) = 0;
                    Level14_7DF60Field(owner18, signed char*, 0x4D) = 0;
                    Level14_7DF60RefreshMobySpatialGridAndBasis((void*)(owner18), (int)(4));
                    Level14_7DF60Field(owner18, unsigned char*, 0x51) =
                        Level14_7DF60PlanarHeadingLookup(
                            (void*)(Level14_7DF60Field(owner18, int*, 0xC) -
                                    Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0)),
                            (int)(Level14_7DF60Field(owner18, int*, 0x10) -
                                  Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 4)),
                            (int)(0));
                    Level14_7DF60SpawnFragments((void*)(4), (int)(0x279), (int)(owner18),
                                                (int)(Level14_7DF60Field(private20, int*, 0x34)),
                                                (int)(0), (int)(0x200));
                    argumentOrValue4 = 632;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrValue4, "memory");
                    resultOrArithmetic2 = Level14_7DF60Field(owner18, int*, 20);
                    fieldOrAddress3 = (int)Level14_7DF60SpawnMoby;
                    MATCHING_OBSERVE2_VOLATILE_CLOBBER(resultOrArithmetic2, fieldOrAddress3, "$5");
                    argumentOrValue5 = owner18;
                    Level14_7DF60Field(owner18, int*, 8) = 0;
                    __asm__ volatile("" ::"r"(resultOrArithmetic2),
                                     "m"(Level14_7DF60Field(owner18, int*, 8)));
                    resultOrArithmetic2 += 2200;
                    Level14_7DF60Field(owner18, int*, 20) = resultOrArithmetic2;
                    savedActorOrVector16 =
                        ((int (*)())fieldOrAddress3)(argumentOrValue4, argumentOrValue5);
                    Level14_7DF60CompleteValue(savedActorOrVector16);
                    if (savedActorOrVector16 != 0) {
                        Level14_7DF60Field(savedActorOrVector16, signed char*, 0x4C) = 0x20;
                        Level14_7DF60Field(savedActorOrVector16, signed char*, 0x48) = 0x14;
                        Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x51) =
                            Level14_7DF60PlanarHeadingLookup(
                                (void*)(Level14_7DF60Field(owner18, int*, 0xC) -
                                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*,
                                                           0)),
                                (int)(Level14_7DF60Field(owner18, int*, 0x10) -
                                      Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 4)),
                                (int)(0));
                        Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x46) =
                            (unsigned char)Level14_7DF60Field(owner18, unsigned char*, 0x46);
                        Level14_7DF60Field(Level14_7DF60Field(savedActorOrVector16, int*, 0),
                                           short*, 8) = -1;
                    }
                    savedIndexOrAddress19 = 0;
                    resultOrArithmetic2 = Level14_7DF60_D_8006C578;
                    fieldOrAddress3 = Level14_7DF60_D_8006C574;
                    if (resultOrArithmetic2 - fieldOrAddress3 < 21)
                        goto actor1897FirstNoLoop;
                    savedActorOrVector16 = 2;
                loop_20:
                    resultOrArithmetic2 = Level14_7DF60_D_8006C7E8;
                    argumentOrValue4 = 1;
                    if (resultOrArithmetic2 < 15361)
                        goto actor1897FirstNoLoop;
                    captured_v0_2 = Level14_7DF60_func_800391E8(
                        (void*)(1), (int)(0x54), (int)(owner18), (int)(0),
                        (int)(savedActorOrVector16), (int)(0xC8), (int)(0x100));
                    if (captured_v0_2 != 0) {
                        Level14_7DF60Field(captured_v0_2, signed char*, 0x48) =
                            savedActorOrVector16;
                        Level14_7DF60Field(captured_v0_2, signed char*, 0x4F) = 0x14;
                    }
                    savedIndexOrAddress19++;
                    argumentOrValue6 = 0;
                    if (savedIndexOrAddress19 >= 8)
                        goto actor1897FirstHeading;
                    resultOrArithmetic2 = Level14_7DF60_D_8006C578;
                    fieldOrAddress3 = Level14_7DF60_D_8006C574;
                    if (resultOrArithmetic2 - fieldOrAddress3 >= 21)
                        goto loop_20;
                actor1897FirstNoLoop:
                    argumentOrValue6 = 0;
                actor1897FirstHeading:
                    fieldOrAddress3 = Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0);
                    argumentOrValue4 = Level14_7DF60Field(owner18, int*, 12);
                    resultOrArithmetic2 =
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 4);
                    argumentOrValue5 = Level14_7DF60Field(owner18, int*, 16);
                    argumentOrValue4 = fieldOrAddress3 - argumentOrValue4;
                    argumentOrValue5 = resultOrArithmetic2 - argumentOrValue5;
                    Level14_7DF60Field(owner18, unsigned char*, 70) =
                        Level14_7DF60PlanarHeadingLookup((void*)(argumentOrValue4),
                                                         (int)(argumentOrValue5),
                                                         (int)(argumentOrValue6));
                    captured_v0_3 = Level14_7DF60RandBetween((int)(0), (int)(0x7F));
                    savedIndexOrAddress19 = 0;
                    if ((Level14_7DF60_D_8006C578 - Level14_7DF60_D_8006C574) >= 0x15) {
                        savedActorOrVector16 = captured_v0_3;
                    loop_28:
                        if (Level14_7DF60_D_8006C7E8 >= 0x3C01) {
                            argumentOrValue4 = Level14_7DF60SpawnMoby((int)(0x216), (int)(owner18));
                            Level14_7DF60CompleteValue(argumentOrValue4);
                            if (argumentOrValue4 != 0) {
                                Level14_7DF60Field(argumentOrValue4, signed char*, 0x41) = 0;
                                Level14_7DF60Field(argumentOrValue4, signed char*, 0x4C) = 0;
                                Level14_7DF60Field(argumentOrValue4, signed char*, 0x4D) = 0;
                                fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 70);
                                resultOrArithmetic2 = 1;
                                Level14_7DF60Field(argumentOrValue4, signed char*, 72) =
                                    resultOrArithmetic2;
                                Level14_7DF60Field(argumentOrValue4, unsigned char*, 70) =
                                    fieldOrAddress3;
                                Level14_7DF60Field(argumentOrValue4, signed char*, 0x44) =
                                    (signed char)savedActorOrVector16;
                                Level14_7DF60Field(argumentOrValue4, int*, 8) = 0;
                                Level14_7DF60Field(Level14_7DF60Field(argumentOrValue4, int*, 0),
                                                   int*, 0) = 5;
                            }
                            savedIndexOrAddress19 += 1;
                            savedActorOrVector16 += 0x33;
                            if ((savedIndexOrAddress19 < 5) &&
                                ((Level14_7DF60_D_8006C578 - Level14_7DF60_D_8006C574) >= 0x15)) {
                                goto loop_28;
                            }
                        }
                    }
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "$4");
                    Level14_7DF60SpawnParticle((int)(0x20), (int)(0x46), (void*)(owner18 + 12),
                                               (void*)(16));
                    savedActorOrTrig17 = Level14_7DF60SpawnMoby((int)(0x64), (int)(owner18));
                    Level14_7DF60CompleteValue(savedActorOrTrig17);
                    if (savedActorOrTrig17 != 0) {
                        Level14_7DF60Field(savedActorOrTrig17, signed char*, 0x48) = 0;
                    }
                    resultOrArithmetic2 = Level14_7DF60_D_8006C578;
                    fieldOrAddress3 = Level14_7DF60_D_8006C574;
                    MATCHING_OBSERVE2_VOLATILE(resultOrArithmetic2, fieldOrAddress3);
                    savedIndexOrAddress19 = 0;
                    goto actor1897PoolCheck;
                loop_41:
                    if (Level14_7DF60_D_8006C7E8 >= 15361) {
                        savedActorOrTrig17 = Level14_7DF60SpawnMoby((int)(0x64), (int)(owner18));
                        Level14_7DF60CompleteValue(savedActorOrTrig17);
                        if (savedActorOrTrig17 != 0) {
                            savedActorOrVector16 = Level14_7DF60Field(savedActorOrTrig17, int*, 0);
                            Level14_7DF60Field(savedActorOrTrig17, signed char*, 0x48) = 1;
                            Level14_7DF60Field(savedActorOrTrig17, signed char*, 0x41) = 0;
                            Level14_7DF60Field(savedActorOrTrig17, signed char*, 0x4C) = 0;
                            Level14_7DF60Field(savedActorOrTrig17, signed char*, 0x4D) = 0;
                            originalFrame.sp20 =
                                Level14_7DF60RandBetween((int)(0), (int)(0x50)) - 0x28;
                            originalFrame.sp24 =
                                Level14_7DF60RandBetween((int)(0), (int)(0x50)) - 0x28;
                            originalFrame.sp28 = Level14_7DF60RandBetween((int)(0x50), (int)(0xC8));
                            resultOrArithmetic2 = Level14_7DF60RandBetween((int)(0), (int)(2048));
                            fieldOrAddress3 = Level14_7DF60Field(savedActorOrTrig17, int*, 12);
                            fieldOrAddress3 -= 1024;
                            fieldOrAddress3 += resultOrArithmetic2;
                            Level14_7DF60Field(savedActorOrTrig17, int*, 12) = fieldOrAddress3;
                            resultOrArithmetic2 = Level14_7DF60RandBetween((int)(0), (int)(2048));
                            fieldOrAddress3 = Level14_7DF60Field(savedActorOrTrig17, int*, 16);
                            fieldOrAddress3 -= 1024;
                            fieldOrAddress3 += resultOrArithmetic2;
                            Level14_7DF60Field(savedActorOrTrig17, int*, 16) = fieldOrAddress3;
                            Level14_7DF60CopyVector((void*)(savedActorOrVector16 + 4),
                                                    (void*)(&originalFrame.sp20));
                            Level14_7DF60Field(savedActorOrVector16, int*, 0x10) = 0;
                            Level14_7DF60Field(savedActorOrVector16, int*, 0) = 0xC8;
                        }
                        savedIndexOrAddress19++;
                        if (savedIndexOrAddress19 >= 8)
                            goto actor1897PoolDone;
                        resultOrArithmetic2 = Level14_7DF60_D_8006C578;
                        fieldOrAddress3 = Level14_7DF60_D_8006C574;
                    actor1897PoolCheck:
                        if (resultOrArithmetic2 - fieldOrAddress3 >= 21)
                            goto loop_41;
                    }
                actor1897PoolDone:;
                }
            }
            Level14_7DF60Field(owner18, int*, 0x18) = 0;
        }
        resultOrArithmetic2 = Level14_7DF60Field(private20, short*, 32);
        if (!resultOrArithmetic2)
            goto actor1897TintMode;
        fieldOrAddress3 = resultOrArithmetic2;
        Level14_7DF60CompleteValue(fieldOrAddress3);
        resultOrArithmetic2 = fieldOrAddress3 & 1;
        if (resultOrArithmetic2)
            goto actor1897OddCounter;
        resultOrArithmetic2 = Level14_7DF60Field(owner18, int*, 20);
        fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 68);
        resultOrArithmetic2 += 125;
        fieldOrAddress3 -= 2;
        Level14_7DF60Field(owner18, int*, 20) = resultOrArithmetic2;
        Level14_7DF60Field(owner18, unsigned char*, 68) = fieldOrAddress3;
        resultOrArithmetic2 = Level14_7DF60Field(private20, short*, 32);
        fieldOrAddress3 = resultOrArithmetic2;
        Level14_7DF60CompleteValue(fieldOrAddress3);
        if (resultOrArithmetic2 < 6)
            goto actor1897IncrementEven;
        Level14_7DF60Field(private20, short*, 32) = 0;
        Level14_7DF60Field(owner18, unsigned char*, 68) = 0;
        goto actor1897TintMode;
    actor1897OddCounter:
        resultOrArithmetic2 = Level14_7DF60Field(owner18, int*, 20);
        fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 68);
        resultOrArithmetic2 -= 125;
        fieldOrAddress3 += 2;
        Level14_7DF60Field(owner18, int*, 20) = resultOrArithmetic2;
        Level14_7DF60Field(owner18, unsigned char*, 68) = fieldOrAddress3;
        resultOrArithmetic2 = Level14_7DF60Field(private20, unsigned short*, 32);
        resultOrArithmetic2++;
        goto actor1897StoreCounter;
    actor1897IncrementEven:
        resultOrArithmetic2 = fieldOrAddress3 + 1;
    actor1897StoreCounter:
        Level14_7DF60Field(private20, short*, 32) = resultOrArithmetic2;
    actor1897TintMode:
        fieldOrAddress3 = Level14_7DF60Field(private20, short*, 30);
        if (!fieldOrAddress3)
            goto actor1897Status;
        resultOrArithmetic2 = 1;
        if (fieldOrAddress3 != resultOrArithmetic2)
            goto actor1897TintMode2;
        resultOrArithmetic2 = Level14_7DF60Field(private20, unsigned short*, 28);
        resultOrArithmetic2 += 16;
        Level14_7DF60Field(private20, unsigned short*, 28) = resultOrArithmetic2;
        resultOrArithmetic2 = (short)resultOrArithmetic2;
        if (resultOrArithmetic2 < 63) {
            fieldOrAddress3 = 0x30000000;
            goto block_58;
        }
        resultOrArithmetic2 = 63;
        Level14_7DF60Field(private20, unsigned short*, 28) = resultOrArithmetic2;
        resultOrArithmetic2 = 2;
        Level14_7DF60Field(private20, short*, 30) = resultOrArithmetic2;
        fieldOrAddress3 = 0x30000000;
        goto block_58;
    actor1897TintMode2:
        resultOrArithmetic2 = 2;
        if (fieldOrAddress3 != resultOrArithmetic2) {
            fieldOrAddress3 = 0x30000000;
            goto block_58;
        }
        fieldOrAddress3 = Level14_7DF60Field(private20, unsigned short*, 28);
        resultOrArithmetic2 = fieldOrAddress3 - 1;
        Level14_7DF60Field(private20, unsigned short*, 28) = resultOrArithmetic2;
        resultOrArithmetic2 = (short)resultOrArithmetic2;
        if (resultOrArithmetic2 >= 33) {
            resultOrArithmetic2 = fieldOrAddress3 - 2;
            Level14_7DF60Field(private20, unsigned short*, 28) = resultOrArithmetic2;
        }
        resultOrArithmetic2 = Level14_7DF60Field(private20, short*, 28);
        if (resultOrArithmetic2 <= 0) {
            Level14_7DF60Field(private20, unsigned short*, 28) = 0;
            Level14_7DF60Field(private20, short*, 30) = 0;
        }
        fieldOrAddress3 = 0x30000000;
    block_58:
        resultOrArithmetic2 = Level14_7DF60Field(private20, unsigned short*, 28);
        fieldOrAddress3 |= 128;
        resultOrArithmetic2 <<= 16;
        Level14_7DF60CompleteValue(resultOrArithmetic2);
        resultOrArithmetic2 >>= 18;
        resultOrArithmetic2 <<= 24;
        resultOrArithmetic2 += fieldOrAddress3;
        Level14_7DF60Field(owner18, int*, 84) = resultOrArithmetic2;
    }
actor1897Status:
    argumentOrValue4 = Level14_7DF60Field(owner18, unsigned char*, 72);
    resultOrArithmetic2 = 27;
    __asm__ volatile("" : "=r"(argumentOrValue4) : "0"(argumentOrValue4), "r"(resultOrArithmetic2));
    captured_a0_3 = argumentOrValue4;
    fieldOrAddress3 = argumentOrValue4 & 255;
    if ((fieldOrAddress3 == 0x1B) || ((unsigned int)(captured_a0_3 - 0x17) < 2U)) {
        if (Level14_7DF60_func_8003BFC0((void*)(owner18),
                                        (int)(Level14_7DF60Field(private20, int*, 0x30))) == 0) {
            Level14_7DF60Field(private20, int*, 0x30) =
                Level14_7DF60PlayMobySoundEvent((void*)(owner18), (int)(0), (int)(4));
        }
    } else if (Level14_7DF60_func_8003BFC0((void*)(owner18),
                                           (int)(Level14_7DF60Field(private20, int*, 0x30))) != 0) {
        Level14_7DF60_func_8003BE70((void*)(Level14_7DF60Field(private20, int*, 0x30)));
    }
    captured_v0_12 = Level14_7DF60Field(owner18, unsigned char*, 0x48);
    switch (captured_v0_12) {
        case 20:
            captured_v0_13 = Level14_7DF60ProbeGroundFromRaisedMoby((void*)(owner18));
            Level14_7DF60Field(private20, short*, 0x24) = captured_v0_13;
            Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x15U;
            Level14_7DF60_func_80021ED8((void*)(7), (int)(0xFC), (int)(0));
            Level14_7DF60Field(owner18, signed char*, 0x4E) = 0x20;
            Level14_7DF60Field(private20, int*, 0x10) = (int)(captured_v0_13 - 0x68E);
            Level14_7DF60Field(owner18, int*, 0x14) = (int)(captured_v0_13 - 0xE5E);
            Level14_7DF60Field(private20, int*, 0x18) = 0x10;
            break;
        case 21:
            if (Level14_7DF60ApproximatePlanarDistance(
                    (void*)(owner18 + 0xC), (void*)((int)&Level14_7DF60_D_80070328)) < 0x3DB8) {
                Level14_7DF60_func_80013ACC((void*)(owner18), (void*)(0xD));
                Level14_7DF60_func_80021ED8((void*)(7), (int)(0xFC), (int)(0));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x20U;
                Level14_7DF60Field(private20, int*, 0x14) = (short)Level14_7DF60_func_8002803C(
                    (void*)(0x15), (void*)(0x8C), (void*)(Level14_7DF60_unk_ovlheader_80074368),
                    (void*)(Level14_7DF60_unk_ovlheader_8007436C),
                    (int)(Level14_7DF60_unk_ovlheader_80074364), (int)(private20 + 0x18),
                    (int)(0x10));
                Level14_7DF60Field(owner18, int*, 0x18) = 0;
            }
            break;
        case 32:
            Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(4));
            fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
            resultOrArithmetic2 = (unsigned int)fieldOrAddress3 < 32;
            if (resultOrArithmetic2 ? (resultOrArithmetic2 = fieldOrAddress3 + 2, 1)
                                    : (resultOrArithmetic2 = fieldOrAddress3 + 2, 0))
                goto actor1897ByteReady0;
            resultOrArithmetic2 = 32;
        actor1897ByteReady0:
            MATCHING_OBSERVE2_VOLATILE(resultOrArithmetic2, fieldOrAddress3);
            Level14_7DF60Field(owner18, unsigned char*, 69) = resultOrArithmetic2;
            resultOrArithmetic2 = Level14_7DF60Field(owner18, int*, 20);
            fieldOrAddress3 = Level14_7DF60Field(private20, int*, 16);
            MATCHING_OBSERVE2_VOLATILE(resultOrArithmetic2, fieldOrAddress3);
            captured_v1_6 = fieldOrAddress3;
            if (captured_v1_6 < resultOrArithmetic2) {
                Level14_7DF60Field(owner18, int*, 0x14) = captured_v1_6;
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x21U;
            }
        case 33:
            fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 72);
            Level14_7DF60CompleteValue(owner18);
            savedActorOrTrig17 = owner18 + 32;
            if (fieldOrAddress3 == 33) {
                resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 69);
                fieldOrAddress3 = Level14_7DF60Field(private20, int*, 16);
                resultOrArithmetic2 -= 3;
                Level14_7DF60Field(owner18, unsigned char*, 69) = resultOrArithmetic2;
                Level14_7DF60CompleteValue(resultOrArithmetic2);
                captured_v0_14 = resultOrArithmetic2;
                Level14_7DF60Field(owner18, int*, 20) = fieldOrAddress3;
                if ((unsigned int)(captured_v0_14 & 0xFF) >= 0x81U) {
                    Level14_7DF60Field(owner18, unsigned char*, 0x45) = 0U;
                    Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x16U;
                    Level14_7DF60Field(owner18, unsigned char*, 0x49) = 0U;
                    Level14_7DF60CompleteValue(owner18);
                    savedActorOrTrig17 = owner18 + 32;
                    Level14_7DF60CompleteValue(savedActorOrTrig17);
                }
            }
            originalFrame.sp20 = 0x5A;
            originalFrame.sp24 = 0;
            originalFrame.sp28 = 0;
            Level14_7DF60TransformVectorByBasis((void*)(savedActorOrTrig17),
                                                (void*)(&originalFrame.sp20),
                                                (void*)(&originalFrame.sp20));
            savedActorOrVector16 = owner18 + 0xC;
            Level14_7DF60AddVector((void*)(savedActorOrVector16), (void*)(savedActorOrVector16),
                                   (void*)(&originalFrame.sp20));
            originalFrame.sp20 = -0xE74;
            originalFrame.sp24 = 0;
            originalFrame.sp28 = 0x5DC;
            Level14_7DF60TransformVectorByBasis((void*)(savedActorOrTrig17),
                                                (void*)(&originalFrame.sp20),
                                                (void*)(&originalFrame.sp20));
            Level14_7DF60AddVector((void*)(&originalFrame.sp20), (void*)(savedActorOrVector16),
                                   (void*)(&originalFrame.sp20));
            Level14_7DF60SpawnParticle((int)(1), (int)(0x2E), (void*)(&originalFrame.sp20),
                                       (void*)(0xD2));
            Level14_7DF60CopyVector((void*)(&originalFrame.sp20), (void*)(savedActorOrVector16));
            originalFrame.sp28 += 0xC1C;
            Level14_7DF60SpawnParticle((int)(1), (int)(0x2E), (void*)(&originalFrame.sp20),
                                       (void*)(0xD2));
            break;
        case 22:
            if (Level14_7DF60CountTimerDown((void*)(private20 + 8), (int)(2)) != 0) {
                saved21 = 0x30D40;
                savedActorOrTrig17 = Level14_7DF60_D_8006C550;
                savedIndexOrAddress19 = -1;
                if (savedActorOrTrig17 < (unsigned int)Level14_7DF60_D_8006C704) {
                    savedActorOrVector16 = savedActorOrTrig17 + 0xC;
                    do {
                        if ((Level14_7DF60Field(savedActorOrVector16, short*, 0x2A) == 0x214) &&
                            (Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x40) != 0) &&
                            (Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x3D) !=
                             0xA) &&
                            !(Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x3C) &
                              0x80)) {
                            fieldOrAddress3 = Level14_7DF60ApproximatePlanarDistance(
                                (void*)(owner18 + 12), (void*)(savedActorOrVector16));
                            if (fieldOrAddress3 < saved21) {
                                argumentOrValue4 = Level14_7DF60_D_8006C550;
                                saved21 = fieldOrAddress3;
                                argumentOrValue4 = savedActorOrTrig17 - argumentOrValue4;
                                resultOrArithmetic2 =
                                    (int)((unsigned int)argumentOrValue4 * 0x45D1745DU);
                                resultOrArithmetic2 = -resultOrArithmetic2;
                                savedIndexOrAddress19 = resultOrArithmetic2 >> 3;
                            }
                        }
                        resultOrArithmetic2 = Level14_7DF60_D_8006C704;
                        MATCHING_KEEP_CLOBBER(savedActorOrTrig17, "memory");
                        savedActorOrTrig17 += 88;
                        savedActorOrVector16 += 88;
                    } while ((unsigned int)savedActorOrTrig17 < (unsigned int)resultOrArithmetic2);
                }
                argumentOrValue4 = owner18;
                if (savedIndexOrAddress19 >= 0) {
                    MATCHING_KEEP_CLOBBER(savedIndexOrAddress19, "$5");
                    Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x18U;
                    Level14_7DF60Field(private20, short*, 0xA) = (short)savedIndexOrAddress19;
                    Level14_7DF60Field(private20, short*, 8) = 0x64;
                    Level14_7DF60RequestMobyAnimation((void*)(argumentOrValue4), (int)(4));
                } else {
                    MATCHING_OBSERVE_VOLATILE(argumentOrValue4);
                    MATCHING_KEEP_CLOBBER(private20, "$2");
                    Level14_7DF60Field(private20, short*, 8) = 30;
                    goto block_91;
                }
            } else {
            block_91:
                resultOrArithmetic2 =
                    Level14_7DF60CountTimerDown((void*)(private20 + 34), (int)(2));
                argumentOrValue4 = private20 + 12;
                if (!resultOrArithmetic2)
                    goto actor1897TimerCall;
                {
                    resultOrArithmetic2 = Level14_7DF60Field(private20, int*, 24);
                    argumentOrValue4 = owner18;
                    if (resultOrArithmetic2 < 5) {
                        Level14_7DF60CompleteValue(argumentOrValue4);
                        Level14_7DF60RequestMobyAnimation((void*)(argumentOrValue4), (int)(1));
                        Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x26U;
                        goto actor1897MainDone;
                    } else {
                        goto block_95;
                    }
                }
                {
                block_95:
                    Level14_7DF60CompleteValue(private20);
                    argumentOrValue4 = private20 + 12;
                    Level14_7DF60CompleteValue(argumentOrValue4);
                actor1897TimerCall:
                    Level14_7DF60CompleteValue(argumentOrValue4);
                    if (Level14_7DF60CountTimerDown((void*)(argumentOrValue4), (int)(2)) != 0) {
                        Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(4));
                        Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x1BU;
                        Level14_7DF60Field(owner18, unsigned char*, 0x49) = 1U;
                        Level14_7DF60Field(private20, short*, 0xC) = 0x12C;
                        goto block_141;
                    } else if ((Level14_7DF60CountTimerDown((void*)(private20 + 2), (int)(2)) !=
                                0) &&
                               (Level14_7DF60ApproximatePlanarDistance(
                                    (void*)(owner18 + 0xC),
                                    (void*)((int)&Level14_7DF60_D_80070328)) < 0x2800)) {
                        Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(4));
                        Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x17U;
                        Level14_7DF60Field(private20, short*, 0) = 0x190;
                        Level14_7DF60Field(private20, short*, 2) = 0xC8;
                    } else if ((Level14_7DF60Field(private20, short*, 6) != 0) &&
                               (Level14_7DF60CountTimerDown((void*)(private20 + 4), (int)(2)) !=
                                0)) {
                        Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x1AU;
                    }
                }
            }
            break;
        case 27:
            captured_a0_4 =
                Level14_7DF60TurnMobyTowardPlayer((void*)(owner18), (int)(3), (int)(8), (int)(1));
            captured_v1_7 = Level14_7DF60Field(owner18, unsigned char*, 0x49);
            switch (captured_v1_7) {
                case 1:
                    if ((captured_a0_4 != 0) &&
                        (Level14_7DF60Field(owner18, int*, 0x14) <
                         (Level14_7DF60Field(private20, int*, 0x10) - 0x5DC))) {
                        Level14_7DF60Field(private20, short*, 0) = 0x190;
                        Level14_7DF60Field(owner18, unsigned char*, 0x49) = 2U;
                        Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(4));
                    } else {
                        Level14_7DF60Field(owner18, int*, 0x14) =
                            (int)(Level14_7DF60Field(owner18, int*, 0x14) - 0x32);
                    }
                    break;
                case 3:
                    fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
                    resultOrArithmetic2 = (unsigned int)fieldOrAddress3 < 32;
                    if (resultOrArithmetic2 ? (resultOrArithmetic2 = fieldOrAddress3 + 2, 1)
                                            : (resultOrArithmetic2 = fieldOrAddress3 + 2, 0))
                        goto actor1897ByteReady1;
                    resultOrArithmetic2 = 32;
                actor1897ByteReady1:
                    MATCHING_OBSERVE2_VOLATILE(resultOrArithmetic2, fieldOrAddress3);
                    Level14_7DF60Field(owner18, unsigned char*, 69) = resultOrArithmetic2;
                    resultOrArithmetic2 = Level14_7DF60Field(owner18, int*, 20);
                    fieldOrAddress3 = Level14_7DF60Field(private20, int*, 16);
                    MATCHING_OBSERVE2_VOLATILE(resultOrArithmetic2, fieldOrAddress3);
                    captured_v1_9 = fieldOrAddress3;
                    if (captured_v1_9 < resultOrArithmetic2) {
                        Level14_7DF60Field(owner18, int*, 0x14) = captured_v1_9;
                        Level14_7DF60Field(owner18, unsigned char*, 0x49) = 4U;
                    }
                case 4:
                    if (Level14_7DF60Field(owner18, unsigned char*, 0x49) == 4) {
                        Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(9));
                        resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 69);
                        fieldOrAddress3 = Level14_7DF60Field(private20, int*, 16);
                        resultOrArithmetic2 -= 3;
                        Level14_7DF60Field(owner18, unsigned char*, 69) = resultOrArithmetic2;
                        Level14_7DF60CompleteValue(resultOrArithmetic2);
                        captured_v0_16 = resultOrArithmetic2;
                        Level14_7DF60Field(owner18, int*, 20) = fieldOrAddress3;
                        if ((unsigned int)(captured_v0_16 & 0xFF) >= 0x81U) {
                            working_v0_5 = 0x17;
                            Level14_7DF60Field(owner18, unsigned char*, 0x45) = 0U;
                            goto block_137;
                        } else {
                            case 2:
                                goto block_122;
                        }
                    } else {
                    block_122:
                        Level14_7DF60TurnMobyTowardPlayer((void*)(owner18), (int)(2), (int)(8),
                                                          (int)(1));
                        originalFrame.sp30 = 0x96;
                        originalFrame.sp34 = 0;
                        originalFrame.sp38 = 0;
                        Level14_7DF60TransformVectorByBasis((void*)(owner18 + 0x20),
                                                            (void*)(&originalFrame.sp30),
                                                            (void*)(&originalFrame.sp30));
                        argumentOrValue4 = (int)&originalFrame.sp30;
                        Level14_7DF60CompleteValue(argumentOrValue4);
                        savedActorOrTrig17 = owner18 + 12;
                        Level14_7DF60AddVector((void*)(argumentOrValue4),
                                               (void*)(savedActorOrTrig17),
                                               (void*)(&originalFrame.sp30));
                        savedIndexOrAddress19 = originalFrame.sp38;
                        originalFrame.sp38 = Level14_7DF60Field(private20, int*, 0x10);
                        if ((Level14_7DF60_func_8001C288((void*)(&originalFrame.sp30),
                                                         (void*)(0x7D0), (void*)(0)) != 0) &&
                            (Level14_7DF60SubtractVector((void*)(&originalFrame.sp40),
                                                         (void*)(savedActorOrTrig17),
                                                         (void*)((int)&Level14_7DF60_D_80070328)),
                             ((Level14_7DF60MeasureVectorLength((void*)(&originalFrame.sp40),
                                                                (void*)(0)) < 0x7D0) != 0))) {
                            Level14_7DF60ScaleVectorRatioQ15(
                                (void*)(&originalFrame.sp40),
                                (int)(Level14_7DF60MeasureVectorLength((void*)(&originalFrame.sp40),
                                                                       (void*)(0))),
                                (int)(0x7D0));
                            Level14_7DF60AddVector((void*)(savedActorOrTrig17),
                                                   (void*)((int)&Level14_7DF60_D_80070328),
                                                   (void*)(&originalFrame.sp40));
                            Level14_7DF60Field(owner18, int*, 0x14) = savedIndexOrAddress19;
                        } else {
                            resultOrArithmetic2 = originalFrame.sp30;
                            Level14_7DF60Field(owner18, int*, 12) = resultOrArithmetic2;
                            resultOrArithmetic2 = originalFrame.sp34;
                            MATCHING_KEEP_CLOBBER(savedIndexOrAddress19, "memory");
                            Level14_7DF60Field(owner18, int*, 20) = savedIndexOrAddress19;
                            Level14_7DF60Field(owner18, int*, 16) = resultOrArithmetic2;
                        }
                        Level14_7DF60RefreshMobySpatialGridAndBasis((void*)(owner18), (int)(2));
                        originalFrame.sp30 = -0xE74;
                        originalFrame.sp34 = 0;
                        originalFrame.sp38 = 0x5DC;
                        Level14_7DF60TransformVectorByBasis((void*)(owner18 + 0x20),
                                                            (void*)(&originalFrame.sp30),
                                                            (void*)(&originalFrame.sp30));
                        argumentOrValue4 = (int)&originalFrame.sp30;
                        Level14_7DF60CompleteValue(argumentOrValue4);
                        savedActorOrTrig17 = owner18 + 12;
                        Level14_7DF60AddVector((void*)(argumentOrValue4),
                                               (void*)(savedActorOrTrig17),
                                               (void*)(&originalFrame.sp30));
                        Level14_7DF60SpawnParticle((int)(1), (int)(0x2E),
                                                   (void*)(&originalFrame.sp30), (void*)(0xD2));
                        Level14_7DF60CopyVector((void*)(&originalFrame.sp30),
                                                (void*)(savedActorOrTrig17));
                        originalFrame.sp38 += 0xC1C;
                        Level14_7DF60SpawnParticle((int)(1), (int)(0x2E),
                                                   (void*)(&originalFrame.sp30), (void*)(0xD2));
                        Level14_7DF60_func_8001BA30((void*)(&originalFrame.sp30), (int)(0x8FC),
                                                    (int)(3), (int)(0), (int)(0x110000),
                                                    (int)(owner18));
                        if ((Level14_7DF60Field(owner18, unsigned char*, 0x49) == 2) &&
                            ((Level14_7DF60CountTimerDown((void*)(private20), (int)(2)) != 0) ||
                             (Level14_7DF60ApproximatePlanarDistance(
                                  (void*)(savedActorOrTrig17),
                                  (void*)((int)&Level14_7DF60_D_80070328)) < 0x1000))) {
                            Level14_7DF60Field(owner18, unsigned char*, 0x49) = 3U;
                        }
                    }
                    break;
            }
            break;
        case 24:
            fieldOrAddress3 = Level14_7DF60Field(private20, short*, 10);
            resultOrArithmetic2 = fieldOrAddress3 * 88;
            fieldOrAddress3 = Level14_7DF60_D_8006C550;
            savedIndexOrAddress19 = fieldOrAddress3 + resultOrArithmetic2;
            resultOrArithmetic2 = Level14_7DF60PlanarHeadingLookup(
                (void*)(Level14_7DF60Field(savedIndexOrAddress19, int*, 0xC) -
                        Level14_7DF60Field(owner18, int*, 0xC)),
                (int)(Level14_7DF60Field(savedIndexOrAddress19, int*, 0x10) -
                      Level14_7DF60Field(owner18, int*, 0x10)),
                (int)(0));
            argumentOrValue4 = owner18;
            MATCHING_OBSERVE2_VOLATILE(resultOrArithmetic2, argumentOrValue4);
            savedActorOrVector16 = resultOrArithmetic2;
            captured_v0_18 = Level14_7DF60TurnMobyTowardHeading(
                (void*)(argumentOrValue4), (int)(savedActorOrVector16), (int)(4), (int)(1),
                (int)(1), (int)(0));
            if (captured_v0_18)
                goto actor1897MoveSelected;
            resultOrArithmetic2 = Level14_7DF60AbsoluteByteAngleDelta(
                (void*)(savedActorOrVector16),
                (void*)(Level14_7DF60Field(owner18, unsigned char*, 70)));
            argumentOrValue4 = owner18 + 32;
            if (resultOrArithmetic2 >= 16)
                goto actor1897SelectedVector;
        actor1897MoveSelected:
            Level14_7DF60_func_80035DDC((void*)(owner18), (int)(100), (int)(0), (int)(0), (int)(0));
            argumentOrValue4 = owner18 + 32;
            Level14_7DF60CompleteValue(argumentOrValue4);
        actor1897SelectedVector:
            Level14_7DF60CompleteValue(argumentOrValue4);
            originalFrame.sp50 = -0xE74;
            originalFrame.sp54 = 0;
            originalFrame.sp58 = 0x5DC;
            Level14_7DF60TransformVectorByBasis((void*)(argumentOrValue4),
                                                (void*)(&originalFrame.sp50),
                                                (void*)(&originalFrame.sp50));
            argumentOrValue4 = (int)&originalFrame.sp50;
            Level14_7DF60CompleteValue(argumentOrValue4);
            savedActorOrTrig17 = owner18 + 12;
            Level14_7DF60AddVector((void*)(argumentOrValue4), (void*)(savedActorOrTrig17),
                                   (void*)(&originalFrame.sp50));
            Level14_7DF60SpawnParticle((int)(1), (int)(0x2E), (void*)(&originalFrame.sp50),
                                       (void*)(0xD2));
            if ((Level14_7DF60Field(savedIndexOrAddress19, unsigned char*, 0x4C) == 0) ||
                ((Level14_7DF60ApproximatePlanarDistance(
                      (void*)(savedActorOrTrig17), (void*)(savedIndexOrAddress19 + 0xC)) < 0x960) &&
                 (captured_v0_18 != 0))) {
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(5));
                working_v0_5 = 25;
            block_137:
                Level14_7DF60Field(owner18, unsigned char*, 72) = working_v0_5;
                Level14_7DF60Field(owner18, unsigned char*, 73) = 0;
                goto actor1897MainDone;
            }
            if ((Level14_7DF60CountTimerDown((void*)(private20 + 2), (int)(2)) != 0) &&
                (Level14_7DF60ApproximatePlanarDistance(
                     (void*)(owner18 + 0xC), (void*)((int)&Level14_7DF60_D_80070328)) < 0x1B58)) {
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(4));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x17U;
            block_141:
                Level14_7DF60Field(private20, short*, 0) = 400;
            }
            break;
        case 25:
            resultOrArithmetic2 = Level14_7DF60_func_80055E84((void*)(owner18));
            argumentOrValue4 = owner18 + 12;
            savedActorOrTrig17 = (int)&Level14_7DF60_D_80070328;
            argumentOrValue5 = savedActorOrTrig17;
            __asm__ volatile(""
                             : "=r"(resultOrArithmetic2)
                             : "0"(resultOrArithmetic2), "r"(argumentOrValue4),
                               "r"(argumentOrValue5));
            savedActorOrVector16 = resultOrArithmetic2;
            resultOrArithmetic2 = Level14_7DF60ApproximatePlanarDistance((void*)(argumentOrValue4),
                                                                         (void*)(argumentOrValue5));
            if ((resultOrArithmetic2 < 0x157C) &&
                (Level14_7DF60Field(owner18, unsigned char*, 0x49) == 0) &&
                ((unsigned int)(savedActorOrVector16 - 9) < 4U) &&
                (Level14_7DF60Field(owner18, unsigned char*, 0x3C) == 5) &&
                (Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0x240) == 0) &&
                (Level14_7DF60AbsoluteByteAngleDelta(
                     (void*)(((int)(Level14_7DF60_D_8006E040 << 16) >> 20)),
                     (void*)(Level14_7DF60PlanarHeadingLookup(
                         (void*)(Level14_7DF60Field(owner18, int*, 0xC) - Level14_7DF60_D_8006E020),
                         (int)(Level14_7DF60Field(owner18, int*, 0x10) - Level14_7DF60_D_8006E024),
                         (int)(0)))) < 0x14) &&
                (Level14_7DF60AbsoluteByteAngleDelta(
                     (void*)(Level14_7DF60Field(owner18, unsigned char*, 0x46)),
                     (void*)(Level14_7DF60PlanarHeadingLookup(
                         (void*)(Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0) -
                                 Level14_7DF60Field(owner18, int*, 0xC)),
                         (int)(Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 4) -
                               Level14_7DF60Field(owner18, int*, 0x10)),
                         (int)(0)))) < 0x10)) {
                fieldOrAddress3 = 0x10000000;
                argumentOrValue4 = Level14_7DF60Field(owner18, unsigned char*, 70);
                resultOrArithmetic2 = Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 36);
                __asm__ volatile(""
                                 : "=r"(fieldOrAddress3)
                                 : "0"(fieldOrAddress3), "r"(resultOrArithmetic2),
                                   "r"(argumentOrValue4));
                fieldOrAddress3 |= 1024;
                Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 524) = fieldOrAddress3;
                MATCHING_OBSERVE_VOLATILE(resultOrArithmetic2);
                resultOrArithmetic2 |= 7;
                Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 664) = argumentOrValue4;
                Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 36) = resultOrArithmetic2;
                resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                resultOrArithmetic2 *= 2;
                fieldOrAddress3 =
                    Level14_7DF60Field((int)&Level14_7DF60_D_80065920, short*, resultOrArithmetic2);
                resultOrArithmetic2 = (fieldOrAddress3 * 25) >> 10;
                Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 540) = resultOrArithmetic2;
                resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                resultOrArithmetic2 *= 2;
                fieldOrAddress3 =
                    Level14_7DF60Field((int)&Level14_7DF60_D_800658A0, short*, resultOrArithmetic2);
                MATCHING_KEEP_VOLATILE_CLOBBER(fieldOrAddress3, "memory");
                Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 548) = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(fieldOrAddress3, "memory");
                resultOrArithmetic2 = (fieldOrAddress3 * 25) >> 10;
                Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 544) = resultOrArithmetic2;
                Level14_7DF60Field(owner18, unsigned char*, 0x49) = 5U;
                Level14_7DF60Field(private20, short*, 2) = 0x12C;
                Level14_7DF60Field(private20, short*, 0xC) = 0x12C;
            }
            MATCHING_OBSERVE_VOLATILE(savedActorOrVector16);
            fieldOrAddress3 = Level14_7DF60Field(private20, short*, 10);
            resultOrArithmetic2 = fieldOrAddress3 * 88;
            fieldOrAddress3 = Level14_7DF60_D_8006C550;
            savedActorOrVector16 = fieldOrAddress3 + resultOrArithmetic2;
            Level14_7DF60CompleteValue(savedActorOrVector16);
            if ((Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x4D) != 0) &&
                (Level14_7DF60_func_80055E84((void*)(owner18)) >= 0xB)) {
                Level14_7DF60Field(savedActorOrVector16, signed char*, 0x48) = 1;
                Level14_7DF60Field(savedActorOrVector16, signed char*, 0x41) = 0;
                Level14_7DF60Field(savedActorOrVector16, signed char*, 0x4C) = 0;
                Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x4D) = 0U;
                Level14_7DF60Field(Level14_7DF60Field(savedActorOrVector16, int*, 0), short*, 0) =
                    500;
                Level14_7DF60Field(private20, short*, 6) =
                    (short)((unsigned short)Level14_7DF60Field(private20, short*, 6) + 1);
            }
            resultOrArithmetic2 = Level14_7DF60_D_8006C770;
            argumentOrValue5 = 0;
            if (resultOrArithmetic2) {
                argumentOrValue4 = owner18;
                resultOrArithmetic2 = 22;
                Level14_7DF60Field(owner18, unsigned char*, 73) = 0;
                goto block_214;
            }
            break;
        case 23:
            resultOrArithmetic2 =
                Level14_7DF60TurnMobyTowardPlayer((void*)(owner18), (int)(2), (int)(8), (int)(1));
            argumentOrValue5 = 9;
            if (!resultOrArithmetic2)
                goto actor1897AnimationFour;
            argumentOrValue4 = owner18;
            goto actor1897AnimationCall;
        actor1897AnimationFour:
            argumentOrValue4 = owner18;
            argumentOrValue5 = 4;
        actor1897AnimationCall:
            MATCHING_OBSERVE2_VOLATILE(argumentOrValue4, argumentOrValue5);
            Level14_7DF60RequestMobyAnimation((void*)(argumentOrValue4), (int)(argumentOrValue5));
            captured_v0_19 = Level14_7DF60ApproximatePlanarDistance(
                (void*)(owner18 + 0xC), (void*)((int)&Level14_7DF60_D_80070328));
            argumentOrValue4 = owner18 + 32;
            Level14_7DF60CompleteValue(argumentOrValue4);
            if (captured_v0_19 >= 0xBB9) {
                originalFrame.sp60 =
                    ((int)(Level14_7DF60Field(
                               (int)&Level14_7DF60_D_80065920, short*,
                               (Level14_7DF60Field(owner18, unsigned char*, 0x46) * 2)) *
                           0x19) >>
                     0xA) +
                    Level14_7DF60Field(owner18, int*, 0xC);
                originalFrame.sp64 =
                    ((int)(Level14_7DF60Field(
                               (int)&Level14_7DF60_D_800658A0, short*,
                               (Level14_7DF60Field(owner18, unsigned char*, 0x46) * 2)) *
                           0x19) >>
                     0xA) +
                    Level14_7DF60Field(owner18, int*, 0x10);
                originalFrame.sp68 = Level14_7DF60Field(owner18, int*, 0x14) + 0x44C;
                if (Level14_7DF60_func_8001C288((void*)(&originalFrame.sp60), (void*)(0x5DC),
                                                (void*)(0)) == 0) {
                    Level14_7DF60Field(owner18, int*, 0xC) = originalFrame.sp60;
                    Level14_7DF60Field(owner18, int*, 0x10) = originalFrame.sp64;
                }
            }
            argumentOrValue4 = owner18 + 32;
            Level14_7DF60CompleteValue(argumentOrValue4);
            originalFrame.sp60 = -0xE74;
            originalFrame.sp64 = 0;
            originalFrame.sp68 = 0x5DC;
            Level14_7DF60TransformVectorByBasis((void*)(argumentOrValue4),
                                                (void*)(&originalFrame.sp60),
                                                (void*)(&originalFrame.sp60));
            argumentOrValue4 = (int)&originalFrame.sp60;
            Level14_7DF60CompleteValue(argumentOrValue4);
            savedActorOrTrig17 = owner18 + 12;
            Level14_7DF60AddVector((void*)(argumentOrValue4), (void*)(savedActorOrTrig17),
                                   (void*)(&originalFrame.sp60));
            Level14_7DF60SpawnParticle((int)(1), (int)(0x2E), (void*)(&originalFrame.sp60),
                                       (void*)(0xD2));
            Level14_7DF60CopyVector((void*)(&originalFrame.sp60), (void*)(savedActorOrTrig17));
            originalFrame.sp68 += 0x44C;
            Level14_7DF60_func_8001BA30((void*)(&originalFrame.sp60), (int)(0x8FC), (int)(3),
                                        (int)(0), (int)(0x110000), (int)(owner18));
            if (captured_v0_19 < 0xC80) {
                if ((Level14_7DF60Field(owner18, unsigned char*, 0x3C) == 9) &&
                    (Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0x240) == 0)) {
                    if (Level14_7DF60AbsoluteByteAngleDelta(
                            (void*)(Level14_7DF60Field(owner18, unsigned char*, 0x46)),
                            (void*)(Level14_7DF60PlanarHeadingLookup(
                                (void*)(Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*,
                                                           0) -
                                        Level14_7DF60Field(owner18, int*, 0xC)),
                                (int)(Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 4) -
                                      Level14_7DF60Field(owner18, int*, 0x10)),
                                (int)(0)))) < 8) {
                        fieldOrAddress3 = 0x10000000;
                        argumentOrValue4 = Level14_7DF60Field(owner18, unsigned char*, 70);
                        resultOrArithmetic2 =
                            Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 36);
                        __asm__ volatile(""
                                         : "=r"(fieldOrAddress3)
                                         : "0"(fieldOrAddress3), "r"(resultOrArithmetic2),
                                           "r"(argumentOrValue4));
                        fieldOrAddress3 |= 1024;
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 524) =
                            fieldOrAddress3;
                        MATCHING_OBSERVE_VOLATILE(resultOrArithmetic2);
                        resultOrArithmetic2 |= 7;
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 664) =
                            argumentOrValue4;
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 36) =
                            resultOrArithmetic2;
                        resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                        resultOrArithmetic2 *= 2;
                        fieldOrAddress3 = Level14_7DF60Field((int)&Level14_7DF60_D_80065920, short*,
                                                             resultOrArithmetic2);
                        resultOrArithmetic2 = (fieldOrAddress3 * 25) >> 11;
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 540) =
                            resultOrArithmetic2;
                        resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                        resultOrArithmetic2 *= 2;
                        fieldOrAddress3 = Level14_7DF60Field((int)&Level14_7DF60_D_800658A0, short*,
                                                             resultOrArithmetic2);
                        MATCHING_KEEP_VOLATILE_CLOBBER(fieldOrAddress3, "memory");
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 548) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(fieldOrAddress3, "memory");
                        resultOrArithmetic2 = (fieldOrAddress3 * 25) >> 11;
                        Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 544) =
                            resultOrArithmetic2;
                        Level14_7DF60Field(private20, short*, 0) = 0;
                        Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x1FU;
                    } else {
                        goto block_166;
                    }
                } else {
                    goto block_167;
                }
            } else {
            block_166:
            block_167:
                working_v0_6 = Level14_7DF60CountTimerDown((void*)(private20), (int)(2));
                goto block_178;
            }
            break;
        case 31:
            captured_v0_20 = Level14_7DF60_func_80055E84((void*)(owner18)) < 0xC;
            if ((Level14_7DF60_D_8006C770 != 0) || (captured_v0_20 == 0)) {
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(1));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x22U;
            }
            break;
        case 34:
            if (Level14_7DF60_D_8006C770 != 0) {
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(2));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x23U;
                captured_v0_21 = Level14_7DF60SpawnMoby((int)(0x278), (int)(owner18));
                Level14_7DF60Field(private20, int*, 0x2C) = captured_v0_21;
                if (captured_v0_21 != 0) {
                    Level14_7DF60Field(captured_v0_21, signed char*, 0x4C) = 0x20;
                    Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), unsigned char*,
                                       0x48) = 0x15U;
                    Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), unsigned char*,
                                       0x46) =
                        (unsigned char)Level14_7DF60Field(owner18, unsigned char*, 0x46);
                    Level14_7DF60InterpolateMobyVertex((void*)(owner18), (int)(0),
                                                       (void*)(&originalFrame.sp70));
                    Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), int*, 0x14) =
                        (int)(originalFrame.sp78 + 0x258);
                    Level14_7DF60SetMobyAnimation(
                        (void*)(Level14_7DF60Field(private20, int*, 0x2C)), (int)(0));
                } else {
                    goto block_179;
                }
            }
            break;
        case 35:
            if (Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), unsigned char*,
                                   0x48) &
                0x80) {
                Level14_7DF60Field(private20, int*, 0x2C) = 0;
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(3));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x24U;
            } else {
                Level14_7DF60InterpolateMobyVertex((void*)(owner18), (int)(0),
                                                   (void*)(&originalFrame.sp80));
                working_v0_7 = originalFrame.sp88;
                goto block_210;
            }
            break;
        case 36:
            working_v0_6 = Level14_7DF60_D_8006C770;
        block_178:
            if (working_v0_6 != 0) {
            block_179:
                if (Level14_7DF60Field(private20, short*, 2) < 0x50) {
                    Level14_7DF60Field(private20, short*, 2) = 0x50;
                }
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x16U;
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(0));
            }
            break;
        case 26:
            if (Level14_7DF60TurnMobyTowardPlayer((void*)(owner18), (int)(2), (int)(8), (int)(1)) !=
                0) {
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 6U;
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(6));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 6U;
            }
            break;
        case 6:
            Level14_7DF60TurnMobyTowardPlayer((void*)(owner18), (int)(2), (int)(1), (int)(1));
            if (Level14_7DF60_D_8006C770 != 0) {
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 7U;
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(7));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 7U;
                Level14_7DF60Field(private20, short*, 4) = 0x3C;
            }
            break;
        case 7:
            if ((Level14_7DF60Field(private20, short*, 6) != 0) &&
                (savedActorOrVector16 = Level14_7DF60TurnMobyTowardPlayer(
                     (void*)(owner18), (int)(4), (int)(2), (int)(1)),
                 (Level14_7DF60Field(private20, short*, 6) != 0))) {
                if ((Level14_7DF60CountTimerDown((void*)(private20 + 4), (int)(2)) != 0) &&
                    (({
                         MATCHING_KEEP_CLOBBER(savedActorOrVector16, "$4");
                         savedActorOrVector16;
                     }) != 0)) {
                    savedActorOrVector16 = Level14_7DF60SpawnMoby((int)(0x112), (int)(owner18));
                    Level14_7DF60CompleteValue(savedActorOrVector16);
                    if (savedActorOrVector16 != 0) {
                        argumentOrValue5 = savedActorOrVector16 + 12;
                        Level14_7DF60CompleteValue(argumentOrValue5);
                        captured_a2 = Level14_7DF60Field(savedActorOrVector16, int*, 0);
                        Level14_7DF60Field(private20, short*, 6) =
                            (short)((unsigned short)Level14_7DF60Field(private20, short*, 6) - 1);
                        resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                        fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
                        resultOrArithmetic2 *= 2;
                        fieldOrAddress3 *= 2;
                        argumentOrValue4 = Level14_7DF60Field((int)&Level14_7DF60_D_80065920,
                                                              short*, resultOrArithmetic2);
                        fieldOrAddress3 = Level14_7DF60Field((int)&Level14_7DF60_D_80065920, short*,
                                                             fieldOrAddress3);
                        resultOrArithmetic2 = (argumentOrValue4 * 125) >> 9;
                        completeSignedProduct.full =
                            (long long)resultOrArithmetic2 * (long long)fieldOrAddress3;
                        __asm__ volatile(""
                                         : "=x"(completeSignedProduct.full)
                                         : "0"(completeSignedProduct.full)
                                         : "$2");
                        resultOrArithmetic2 = Level14_7DF60Field(savedActorOrVector16, int*, 12);
                        __asm__ volatile(""
                                         : "=x"(completeSignedProduct.full)
                                         : "0"(completeSignedProduct.full),
                                           "r"(resultOrArithmetic2));
                        productLow8 = completeSignedProduct.words.low;
                        Level14_7DF60CompleteValue(productLow8);
                        fieldOrAddress3 = productLow8 >> 12;
                        resultOrArithmetic2 += fieldOrAddress3;
                        Level14_7DF60Field(savedActorOrVector16, int*, 12) = resultOrArithmetic2;
                        resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                        fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
                        resultOrArithmetic2 *= 2;
                        fieldOrAddress3 *= 2;
                        argumentOrValue4 = Level14_7DF60Field((int)&Level14_7DF60_D_800658A0,
                                                              short*, resultOrArithmetic2);
                        fieldOrAddress3 = Level14_7DF60Field((int)&Level14_7DF60_D_80065920, short*,
                                                             fieldOrAddress3);
                        resultOrArithmetic2 = (argumentOrValue4 * 125) >> 9;
                        completeSignedProduct.full =
                            (long long)resultOrArithmetic2 * (long long)fieldOrAddress3;
                        __asm__ volatile(""
                                         : "=x"(completeSignedProduct.full)
                                         : "0"(completeSignedProduct.full)
                                         : "$2", "$17");
                        savedActorOrTrig17 = (int)&Level14_7DF60_D_80065920;
                        resultOrArithmetic2 = Level14_7DF60Field(savedActorOrVector16, int*, 16);
                        __asm__ volatile(""
                                         : "=x"(completeSignedProduct.full)
                                         : "0"(completeSignedProduct.full),
                                           "r"(resultOrArithmetic2));
                        productLow8 = completeSignedProduct.words.low;
                        Level14_7DF60CompleteValue(productLow8);
                        fieldOrAddress3 = productLow8 >> 12;
                        resultOrArithmetic2 += fieldOrAddress3;
                        Level14_7DF60Field(savedActorOrVector16, int*, 16) = resultOrArithmetic2;
                        Level14_7DF60Field(savedActorOrVector16, int*, 0x14) =
                            (int)(Level14_7DF60Field(savedActorOrVector16, int*, 0x14) +
                                  ((int)(Level14_7DF60Field(
                                             (int)&Level14_7DF60_D_800658A0, short*,
                                             (Level14_7DF60Field(owner18, unsigned char*, 0x45) *
                                              2)) *
                                         0x7D) >>
                                   9) +
                                  0x5DC);
                        resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(resultOrArithmetic2, "$19");
                        /* Original1570/1571 construct resident sine base800658A0. */
                        savedIndexOrAddress19 = (int)0x80060000U;
                        Level14_7DF60CompleteValue(savedIndexOrAddress19);
                        savedIndexOrAddress19 += 0x58A0;
                        Level14_7DF60CompleteValue(savedIndexOrAddress19);
                        Level14_7DF60Field(savedActorOrVector16, unsigned char*, 70) =
                            resultOrArithmetic2;
                        fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
                        resultOrArithmetic2 = 48;
                        Level14_7DF60Field(savedActorOrVector16, signed char*, 76) =
                            resultOrArithmetic2;
                        Level14_7DF60Field(savedActorOrVector16, signed char*, 78) =
                            resultOrArithmetic2;
                        Level14_7DF60Field(savedActorOrVector16, unsigned char*, 69) =
                            fieldOrAddress3;
                        Level14_7DF60Field(captured_a2, int*, 4) = 0x12C;
                        Level14_7DF60Field(captured_a2, int*, 0) = 0x12C;
                        resultOrArithmetic2 =
                            Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 592);
                        __asm__("" : "=r"(captured_a2) : "0"(captured_a2) : "$4", "memory");
                        argumentOrValue4 = owner18 + 12;
                        Level14_7DF60Field(captured_a2, int*, 8) = resultOrArithmetic2;
                        if (Level14_7DF60_func_80018368((void*)(argumentOrValue4),
                                                        (void*)(argumentOrValue5),
                                                        (int)(captured_a2)) != 0) {
                            Level14_7DF60Field(savedActorOrVector16, signed char*, 0x48) = 1;
                            resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                            resultOrArithmetic2 *= 2;
                            fieldOrAddress3 =
                                Level14_7DF60Field(savedActorOrTrig17, short*, resultOrArithmetic2);
                            resultOrArithmetic2 = fieldOrAddress3 * 500;
                            fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
                            resultOrArithmetic2 = -resultOrArithmetic2;
                            fieldOrAddress3 *= 2;
                            fieldOrAddress3 =
                                Level14_7DF60Field(savedActorOrTrig17, short*, fieldOrAddress3);
                            resultOrArithmetic2 >>= 12;
                            completeSignedProduct.full =
                                (long long)resultOrArithmetic2 * (long long)fieldOrAddress3;
                            __asm__ volatile(""
                                             : "=x"(completeSignedProduct.full)
                                             : "0"(completeSignedProduct.full)
                                             : "$2");
                            resultOrArithmetic2 =
                                Level14_7DF60Field(savedActorOrVector16, int*, 12);
                            __asm__ volatile(""
                                             : "=x"(completeSignedProduct.full)
                                             : "0"(completeSignedProduct.full),
                                               "r"(resultOrArithmetic2));
                            productLow8 = completeSignedProduct.words.low;
                            Level14_7DF60CompleteValue(productLow8);
                            fieldOrAddress3 = productLow8 >> 12;
                            resultOrArithmetic2 += fieldOrAddress3;
                            Level14_7DF60Field(savedActorOrVector16, int*, 12) =
                                resultOrArithmetic2;
                            resultOrArithmetic2 = Level14_7DF60Field(owner18, unsigned char*, 70);
                            resultOrArithmetic2 *= 2;
                            resultOrArithmetic2 += savedIndexOrAddress19;
                            fieldOrAddress3 = Level14_7DF60Field(resultOrArithmetic2, short*, 0);
                            resultOrArithmetic2 = fieldOrAddress3 * 500;
                            fieldOrAddress3 = Level14_7DF60Field(owner18, unsigned char*, 69);
                            resultOrArithmetic2 = -resultOrArithmetic2;
                            fieldOrAddress3 *= 2;
                            fieldOrAddress3 =
                                Level14_7DF60Field(savedActorOrTrig17, short*, fieldOrAddress3);
                            resultOrArithmetic2 >>= 12;
                            completeSignedProduct.full =
                                (long long)resultOrArithmetic2 * (long long)fieldOrAddress3;
                            __asm__ volatile(""
                                             : "=x"(completeSignedProduct.full)
                                             : "0"(completeSignedProduct.full)
                                             : "$2");
                            resultOrArithmetic2 =
                                Level14_7DF60Field(savedActorOrVector16, int*, 16);
                            __asm__ volatile(""
                                             : "=x"(completeSignedProduct.full)
                                             : "0"(completeSignedProduct.full),
                                               "r"(resultOrArithmetic2));
                            productLow8 = completeSignedProduct.words.low;
                            Level14_7DF60CompleteValue(productLow8);
                            fieldOrAddress3 = productLow8 >> 12;
                            resultOrArithmetic2 += fieldOrAddress3;
                            Level14_7DF60Field(savedActorOrVector16, int*, 16) =
                                resultOrArithmetic2;
                            Level14_7DF60Field(savedActorOrVector16, int*, 0x14) =
                                (int)(Level14_7DF60Field(savedActorOrVector16, int*, 0x14) +
                                      ((int)-(
                                           Level14_7DF60Field(
                                               (Level14_7DF60Field(owner18, unsigned char*, 0x45) *
                                                2) +
                                                   savedIndexOrAddress19,
                                               short*, 0) *
                                           0x1F4) >>
                                       0xC));
                        }
                        Level14_7DF60Field(private20, short*, 4) = 0x3C;
                    }
                }
                if (Level14_7DF60Field(private20, short*, 6) == 0) {
                    goto block_195;
                }
            } else {
            block_195:
                if (Level14_7DF60CountTimerDown((void*)(private20 + 4), (int)(2)) != 0) {
                    Level14_7DF60Field(owner18, unsigned char*, 0x48) = 8U;
                    Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(8));
                }
            }
            break;
        case 8:
            if (Level14_7DF60_D_8006C770 != 0) {
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(0));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x16U;
                Level14_7DF60Field(private20, short*, 4) = 0xC8;
            }
            break;
        case 38:
            if (Level14_7DF60_D_8006C770 != 0) {
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(2));
                argumentOrValue4 = 632;
                MATCHING_OBSERVE_VOLATILE(argumentOrValue4);
                savedActorOrTrig17 = 39;
                Level14_7DF60Field(owner18, unsigned char*, 72) = savedActorOrTrig17;
                resultOrArithmetic2 = (int)Level14_7DF60SpawnMoby;
                __asm__ volatile("" ::"r"(resultOrArithmetic2) : "$5", "memory");
                argumentOrValue5 = owner18;
                Level14_7DF60Field(private20, unsigned short*, 34) = 0;
                captured_v0_23 =
                    ((int (*)())resultOrArithmetic2)(argumentOrValue4, argumentOrValue5);
                Level14_7DF60Field(private20, int*, 0x2C) = captured_v0_23;
                if (captured_v0_23 == 0) {
                    argumentOrValue4 = owner18;
                    argumentOrValue5 = 0;
                    resultOrArithmetic2 = 300;
                    goto block_213;
                }
                Level14_7DF60Field(captured_v0_23, signed char*, 0x4C) = 0x20;
                Level14_7DF60Field(captured_v0_23, signed char*, 0x48) = 0;
                Level14_7DF60SetMobyAnimation((void*)(captured_v0_23), (int)(0));
                Level14_7DF60Field(captured_v0_23, unsigned char*, 0x46) =
                    (unsigned char)Level14_7DF60Field(owner18, unsigned char*, 0x46);
                Level14_7DF60InterpolateMobyVertex((void*)(owner18), (int)(0),
                                                   (void*)(&originalFrame.sp90));
                Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), int*, 0x14) =
                    (int)(originalFrame.sp98 + 0x258);
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(2));
                Level14_7DF60Field(owner18, unsigned char*, 72) = savedActorOrTrig17;
            }
            break;
        case 39:
            Level14_7DF60InterpolateMobyVertex((void*)(owner18), (int)(0),
                                               (void*)(&originalFrame.sp90));
            Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), int*, 0x14) =
                (int)(originalFrame.sp98 + 0x258);
            captured_v0_24 =
                Level14_7DF60Field(private20, unsigned short*, 0x22) + Level14_7DF60_D_8006C648;
            Level14_7DF60Field(private20, unsigned short*, 0x22) = captured_v0_24;
            if ((short)captured_v0_24 >= 0x3D) {
                captured_v0_25 = Level14_7DF60Field(private20, int*, 0x18) + 1;
                Level14_7DF60Field(private20, int*, 0x18) = captured_v0_25;
                if (captured_v0_25 >= 8) {
                    Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), unsigned char*,
                                       0x48) = 7U;
                    Level14_7DF60SetMobyAnimation(
                        (void*)(Level14_7DF60Field(private20, int*, 0x2C)), (int)(7));
                    Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x2AU;
                } else {
                    Level14_7DF60Field(private20, unsigned short*, 0x22) = 0U;
                }
            }
            break;
        case 42:
            if (Level14_7DF60Field(Level14_7DF60Field(private20, int*, 0x2C), unsigned char*,
                                   0x48) &
                0x80) {
                Level14_7DF60Field(private20, int*, 0x2C) = 0;
                Level14_7DF60RequestMobyAnimation((void*)(owner18), (int)(3));
                Level14_7DF60Field(owner18, unsigned char*, 0x48) = 0x2BU;
            } else {
                Level14_7DF60InterpolateMobyVertex((void*)(owner18), (int)(0),
                                                   (void*)(&originalFrame.spA0));
                working_v0_7 = originalFrame.spA8;
            block_210:
                resultOrArithmetic2 = working_v0_7;
                fieldOrAddress3 = Level14_7DF60Field(private20, int*, 44);
                resultOrArithmetic2 += 600;
                Level14_7DF60Field(fieldOrAddress3, int*, 20) = resultOrArithmetic2;
            }
            break;
        case 40:
        case 43:
            resultOrArithmetic2 = Level14_7DF60_D_8006C770;
            argumentOrValue5 = 0;
            if (resultOrArithmetic2) {
                argumentOrValue4 = owner18;
                resultOrArithmetic2 = 200;
            block_213:
                Level14_7DF60Field(private20, unsigned short*, 34) = resultOrArithmetic2;
                resultOrArithmetic2 = 22;
            block_214:
                Level14_7DF60CompleteValue(argumentOrValue4);
                Level14_7DF60Field(owner18, unsigned char*, 72) = resultOrArithmetic2;
                Level14_7DF60RequestMobyAnimation((void*)(argumentOrValue4),
                                                  (int)(argumentOrValue5));
            }
            break;
        case 30:
            resultOrArithmetic2 = Level14_7DF60CountTimerDown((void*)(private20 + 2), (int)(2));
            savedActorOrTrig17 = (int)&originalFrame.spB0;
            if (resultOrArithmetic2) {
                Level14_7DF60CompleteValue(savedActorOrTrig17);
                savedActorOrVector16 =
                    Level14_7DF60_D_8006C550 + (Level14_7DF60Field(private20, int*, 0x28) * 0x58);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(savedActorOrVector16, "$2");
                fieldOrAddress3 = Level14_7DF60Field(savedActorOrVector16, int*, 0);
                resultOrArithmetic2 = 38;
                Level14_7DF60Field(savedActorOrVector16, signed char*, 72) = resultOrArithmetic2;
                resultOrArithmetic2 = 4;
                Level14_7DF60Field(fieldOrAddress3, signed char*, 2) = resultOrArithmetic2;
                resultOrArithmetic2 = Level14_7DF60_D_8006C7B4;
                fieldOrAddress3 = Level14_7DF60Field(savedActorOrVector16, int*, 0);
                resultOrArithmetic2 |= 8;
                Level14_7DF60_D_8006C7B4 = resultOrArithmetic2;
                resultOrArithmetic2 = 2;
                Level14_7DF60Field(fieldOrAddress3, signed char*, 5) = resultOrArithmetic2;
                resultOrArithmetic2 = Level14_7DF60Field(savedActorOrVector16, unsigned char*, 70);
                resultOrArithmetic2 *= 2;
                fieldOrAddress3 =
                    Level14_7DF60Field((int)&Level14_7DF60_D_80065920, short*, resultOrArithmetic2);
                __asm__ volatile(""
                                 : "=r"(resultOrArithmetic2)
                                 : "0"(resultOrArithmetic2)
                                 : "$4", "memory");
                argumentOrValue4 = savedActorOrTrig17;
                MATCHING_OBSERVE2_VOLATILE(argumentOrValue4, fieldOrAddress3);
                resultOrArithmetic2 = (fieldOrAddress3 * 39) >> 6;
                originalFrame.spB0 = resultOrArithmetic2;
                __asm__("" : "=r"(argumentOrValue4) : "0"(argumentOrValue4) : "$5", "memory");
                resultOrArithmetic2 = Level14_7DF60Field(savedActorOrVector16, unsigned char*, 70);
                argumentOrValue5 = savedActorOrTrig17;
                resultOrArithmetic2 *= 2;
                fieldOrAddress3 =
                    Level14_7DF60Field((int)&Level14_7DF60_D_800658A0, short*, resultOrArithmetic2);
                resultOrArithmetic2 = Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 68);
                __asm__("" : "=r"(fieldOrAddress3) : "0"(fieldOrAddress3) : "$6", "memory");
                argumentOrValue6 = savedActorOrVector16 + 12;
                MATCHING_OBSERVE4_VOLATILE_CLOBBER(resultOrArithmetic2, fieldOrAddress3,
                                                   argumentOrValue5, argumentOrValue6, "memory");
                originalFrame.spB8 = 0;
                __asm__ volatile("" ::"m"(originalFrame.spB8));
                originalFrame.spB8 = resultOrArithmetic2;
                resultOrArithmetic2 = (fieldOrAddress3 * 39) >> 6;
                originalFrame.spB4 = resultOrArithmetic2;
                Level14_7DF60AddVector((void*)(argumentOrValue4), (void*)(argumentOrValue5),
                                       (void*)(argumentOrValue6));
                Level14_7DF60_func_80013D44(
                    (void*)(savedActorOrTrig17),
                    (int)((Level14_7DF60Field(savedActorOrVector16, unsigned char*, 0x46) + 0x80) &
                          0xFF),
                    (void*)(0), (int)(0));
                if (Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0x280) < 0) {
                    Level14_7DF60Field((int)&Level14_7DF60_D_80070328, int*, 0x280) = 0;
                }
                Level14_7DF60_func_8003BA00((void*)(owner18));
                Level14_7DF60DeleteMoby((void*)(owner18));
            }
            break;
    }
actor1897MainDone:
    if ((Level14_7DF60Field(owner18, unsigned char*, 0x48) != 0x1E) &&
        (Level14_7DF60Field(private20, short*, 0x1E) == 0)) {
        Level14_7DF60Field(owner18, int*, 0x54) =
            (int)((-Level14_7DF60Field(private20, short*, 0x24) & 0xFFFFFF) | 0x80000000);
    }
    return;
}
#undef Level14_7DF60Field
#undef Level14_7DF60CompleteValue

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8007FD04.
 * Original308 words: sibling4717.func_level_14_8007FD04.json.
 * Units, helper contracts, cadence and runtime parity unresolved. */
#define D14Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int D14H36A68() __asm__("func_80036A68");
int D14H38F14() __asm__("func_80038F14");
int D14RequestMobyAnimation() __asm__("func_80034F40");
int D14ApproximatePlanarDistance() __asm__("func_8004F334");
int D14H55E84() __asm__("func_80055E84");
int D14RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int D14TransformVectorByBasis() __asm__("func_8004ED6C");
int D14H35194() __asm__("func_80035194");
int D14H3BA00() __asm__("func_8003BA00");
int D14H369B8() __asm__("func_800369B8");
int D14DeleteMoby() __asm__("func_80055B18");
int D14InterpolateMobyVertex() __asm__("func_80055F14");
int D14PlanarHeadingLookup() __asm__("func_8004E880");
int D14AddVector() __asm__("func_8004F194");
int D14ShiftVectorRightTowardZero() __asm__("func_8004F110");
extern unsigned char D14Player[] __asm__("D_80070328");
extern int D14Contact __asm__("D_8006C770");
extern void* (*D14Spawn)(int, void*)__asm__("SpawnMoby");
void func_level_14_8007FD04(void* input) {
    struct {
        int first[4];
        int second[4];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$18");
    register int update19 __asm__("$19");
    register void* temporary16 __asm__("$16");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    MATCHING_KEEP_CLOBBER(owner, "$19");
    other = 3;
    value = owner[72];
    tag = D14Field(owner, unsigned char**, 0);
    update19 = 0;
    if (value == other)
        goto dispatch;
    value = D14Field(owner, int*, 24);
    other = 0x150000;
    value &= other;
    if (value)
        goto damage;
    call4 = D14Field(tag, void**, 0);
    if (!call4)
        goto dispatch;
    other = 0x160000;
    value = D14Field(call4, int*, 24);
    value &= other;
    if (value)
        goto damage;
    value = ((unsigned char*)call4)[72] & 128;
    if (!value)
        goto dispatch;
damage:
    other = D14Field(tag, int*, 0);
    if (other) {
        ((unsigned char*)other)[72] = 1;
        other = D14Field((void*)other, int*, 0);
        call4 = D14Field(tag, void**, 0);
        ((unsigned char*)call4)[79] = 32;
        D14Field((void*)other, int*, 0) = 0;
        D14Field((void*)other, int*, 4) = 0;
        D14Field((void*)other, int*, 8) = 0;
        D14Field((void*)other, short*, 14) = 16;
        D14Field(tag, int*, 0) = 0;
    }
    D14H36A68(owner, 1, 0, 0);
    D14H38F14(owner, tag + 4, 1, 3);
    D14Field(tag, short*, 14) = 700;
dispatch:
    temporary16 = (void*)owner[72];
    if ((int)temporary16 == 1)
        goto state1;
    if ((int)temporary16 < 2) {
        if (!temporary16)
            goto state0;
        goto update;
    }
    if ((int)temporary16 == 2)
        goto state2;
    call4 = owner;
    if ((int)temporary16 == 3)
        goto state3;
    goto update;
state0:
    value = D14Field(tag, int*, 0);
    if (!value) {
        owner[72] = 2;
        D14RequestMobyAnimation(owner, 2);
    }
    value = D14ApproximatePlanarDistance(owner + 12, D14Player);
    other = D14Field(tag, int*, 28);
    if (value < other) {
        owner[72] = 1;
        D14RequestMobyAnimation(owner, 1);
    }
    update19 = 1;
    goto update;
state1:
    value = owner[60];
    if (value != (int)temporary16)
        goto attach1;
    value = D14H55E84(owner);
    if (value < 13)
        goto attach1;
    temporary16 = D14Field(tag, void**, 0);
    if (!temporary16)
        goto attach1;
    value = owner[73];
    call4 = owner;
    if (value)
        goto contact1;
    arg5 = 4;
    temporary16 = D14Field(temporary16, void**, 0);
    owner[73] = 2;
    D14RefreshMobySpatialGridAndBasis(call4, arg5);
    call4 = owner + 32;
    arg5 = (int)frame.first;
    frame.first[0] = 200;
    frame.first[1] = 0;
    frame.first[2] = 0;
    D14TransformVectorByBasis(call4, (void*)arg5, temporary16);
    D14Field(temporary16, short*, 14) = 18;
    other = D14Field(tag, int*, 0);
    ((unsigned char*)other)[72] = 1;
    other = D14Field(tag, int*, 0);
    ((unsigned char*)other)[68] = 64;
    value = owner[70];
    other = D14Field(tag, int*, 0);
    value += 128;
    ((unsigned char*)other)[70] = value;
    value = D14Field(tag, int*, 0);
    other = D14Field((void*)value, int*, 0);
    D14Field((void*)other, short*, 12) = 300;
    D14Field(tag, int*, 0) = 0;
    goto contact1;
attach1:
    update19 = 1;
contact1:
    value = D14Contact;
    call4 = owner;
    if (!value)
        goto update;
    arg5 = 2;
    owner[73] = 0;
    owner[72] = 2;
    D14RequestMobyAnimation(call4, arg5);
    goto update;
state2:
    value = D14H55E84(owner);
    update19 = 1;
    other = owner[60];
    call4 = (void*)value;
    if (other != (int)temporary16)
        goto contact2;
    if ((int)call4 >= 34)
        goto stage46;
    other = D14Field(tag, int*, 0);
    if (!other)
        goto stage46;
    ((unsigned char*)other)[79] = 70;
    goto contact2;
stage46:
    if ((int)call4 < 46)
        goto stage34;
    other = D14Field(tag, int*, 0);
    if (!other)
        goto stage34;
    ((unsigned char*)other)[79] = 26;
    goto contact2;
stage34:
    if ((int)call4 < 34)
        goto stage30;
    arg5 = D14Field(tag, int*, 0);
    if (!arg5)
        goto stage30;
    other = 45 - (int)call4;
    value = other * 3 + 26;
    ((unsigned char*)arg5)[79] = value;
    goto contact2;
stage30:
    value = (int)call4 < 30;
    if (value)
        goto contact2;
    value = owner[73];
    call4 = (void*)358;
    if (value)
        goto contact2;
    value = (int)D14Spawn((int)call4, owner);
    other = value;
    if (!other)
        goto contact2;
    value = 32;
    ((unsigned char*)other)[76] = value;
    value = 16;
    ((unsigned char*)other)[78] = value;
    value = 80;
    ((unsigned char*)other)[79] = value;
    value = 47;
    ((unsigned char*)other)[87] = value;
    value = 1;
    D14Field(tag, int*, 0) = other;
    owner[73] = value;
contact2:
    value = D14Contact;
    call4 = owner;
    if (!value)
        goto update;
    arg5 = 0;
    owner[73] = 0;
    owner[72] = 0;
    D14RequestMobyAnimation(call4, arg5);
    goto update;
state3:
    value = D14H35194(call4, tag + 4);
    call4 = owner;
    if (value != 256)
        goto update;
    D14RefreshMobySpatialGridAndBasis(call4, 4);
    D14H3BA00(owner);
    D14H369B8(owner, 64);
    D14DeleteMoby(owner);
    goto done;
update:
    if (!update19)
        goto done;
    tag = D14Field(tag, unsigned char**, 0);
    call4 = owner;
    if (!tag)
        goto done;
    D14RefreshMobySpatialGridAndBasis(call4, 5);
    call4 = owner;
    arg5 = 0;
    MATCHING_KEEP(arg5);
    temporary16 = tag + 12;
    D14InterpolateMobyVertex(call4, arg5, temporary16);
    D14InterpolateMobyVertex(owner, 1, frame.first);
    call4 = frame.first;
    MATCHING_KEEP(call4);
    value = frame.first[2];
    MATCHING_KEEP(value);
    other = D14Field(tag, int*, 20);
    MATCHING_KEEP(other);
    arg5 = (int)temporary16;
    frame.second[2] = value - other;
    value = D14ApproximatePlanarDistance(call4, (void*)arg5);
    call4 = (void*)value;
    arg5 = frame.second[2];
    arg6 = 0;
    frame.second[0] = (int)call4;
    value = D14PlanarHeadingLookup((int)call4, arg5, arg6);
    tag[68] = value + 64;
    call4 = (void*)frame.first[0];
    value = D14Field(tag, int*, 12);
    arg5 = frame.first[1];
    call4 = (void*)((int)call4 - value);
    frame.second[0] = (int)call4;
    value = D14Field(tag, int*, 16);
    arg6 = 0;
    arg5 -= value;
    frame.second[1] = arg5;
    value = D14PlanarHeadingLookup((int)call4, arg5, arg6);
    call4 = temporary16;
    arg5 = (int)frame.first;
    MATCHING_KEEP(arg5);
    arg6 = (int)temporary16;
    tag[70] = value + 64;
    D14AddVector(call4, (void*)arg5, (void*)arg6);
    D14ShiftVectorRightTowardZero(temporary16, 1);
done:;
}
#undef D14Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_14/moby", D_level_14_800746F0);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Native modulo32 word arithmetic; signed conversions/right shifts use the frozen MIPS ABI. */
#define Actor952Add(a, b) ((int)((unsigned int)(a) + (unsigned int)(b)))
#define Actor952Sub(a, b) ((int)((unsigned int)(a) - (unsigned int)(b)))
/* AI generated, not human reviewed. Uninstalled original C with approved original LW boundaries. All gates pending. */
#define Actor952Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Actor952Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor952_func_80013AE4() __asm__("func_80013AE4");
int Actor952_func_80013D44() __asm__("func_80013D44");
int Actor952_func_80021ED8() __asm__("func_80021ED8");
int Actor952_func_80021F3C() __asm__("func_80021F3C");
int Actor952_func_80021F8C() __asm__("func_80021F8C");
int Actor952_func_8002803C() __asm__("func_8002803C");
int Actor952_func_80028154() __asm__("func_80028154");
int Actor952RequestMobyAnimation() __asm__("func_80034F40");
int Actor952SetMobyAnimation() __asm__("func_80034F80");
int Actor952CountTimerDown() __asm__("func_800359A4");
int Actor952_func_80035A80() __asm__("func_80035A80");
int Actor952ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Actor952RandBetween() __asm__("func_8003636C");
int Actor952_func_80036A68() __asm__("func_80036A68");
int Actor952_func_80037BBC() __asm__("func_80037BBC");
int Actor952_func_8003B634() __asm__("func_8003B634");
int Actor952_func_8003B74C() __asm__("func_8003B74C");
int Actor952_func_8003B7B4() __asm__("func_8003B7B4");
int Actor952_func_8003BA00() __asm__("func_8003BA00");
int Actor952PlanarHeadingLookup() __asm__("func_8004E880");
int Actor952TransformVectorByBasis() __asm__("func_8004ED6C");
int Actor952CopyVector() __asm__("func_8004F178");
int Actor952AddVector() __asm__("func_8004F194");
int Actor952AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Actor952ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor952_func_800512E4() __asm__("func_800512E4");
int Actor952DeleteMoby() __asm__("func_80055B18");
int Actor952RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern int Actor952_D_800658A0 __asm__("D_800658A0");
extern int Actor952_D_80065920 __asm__("D_80065920");
extern int Actor952_D_8006C550 __asm__("D_8006C550");
extern int Actor952_D_8006C65C __asm__("D_8006C65C");
extern int Actor952_D_8006C704 __asm__("D_8006C704");
extern int Actor952_D_8006C770 __asm__("D_8006C770");
extern int Actor952_D_8006C7B4 __asm__("D_8006C7B4");
extern int Actor952_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor952_D_8006C7F8 __asm__("D_8006C7F8");
extern int Actor952_D_8006D088 __asm__("D_8006D088");
extern int Actor952_D_8006E048 __asm__("D_8006E048");
extern int Actor952_D_8006E344 __asm__("D_8006E344");
extern int Actor952_D_8006EE2C __asm__("D_8006EE2C");
extern int Actor952_D_80070328 __asm__("D_80070328");
extern int Actor952_D_level_14_800746F0 __asm__("D_level_14_800746F0");
extern int Actor952_SpawnMoby __asm__("SpawnMoby");
extern int Actor952_unk_ovlheader_80074330 __asm__("unk_ovlheader_80074330");
extern int Actor952_unk_ovlheader_80074370 __asm__("unk_ovlheader_80074370");
static __inline__ int Actor952ForwardOriginal(int owner, int actualPrivate) {
    return Actor952_func_80035A80(owner, Actor952Field(actualPrivate, int*, 52), 120, 100, 0, 4, 32,
                                  0);
}
void func_level_14_800801D4(void* input) {
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
    register int valueS6 __asm__("$22");
    register int privateData __asm__("$23");
    register int word24 __asm__("$24");
    register int word25 __asm__("$25");
    register int actor;
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
        } fields;
    } frame;
    actor = (int)input;
    Actor952Keep(actor);
    argument0 = (int)input;
    privateData = Actor952Field(actor, int*, 0);
    Actor952Keep(privateData);
    argument1 = (int)&Actor952_D_level_14_800746F0;
    Actor952Keep(argument1);
    valueV0 = Actor952Field(argument1, int*, 0);
    Actor952Keep(valueV0);
    valueV1 = Actor952Field(argument1, int*, 4);
    Actor952Keep(valueV1);
    argument0 = Actor952Field(argument1, int*, 8);
    Actor952Keep(argument0);
    Actor952Field((int)&frame, int*, 0) = valueV0;
    Actor952Field((int)&frame, int*, 4) = valueV1;
    Actor952Field((int)&frame, int*, 8) = argument0;
    valueV1 = Actor952Field(actor, unsigned char*, 72);
    Actor952Keep(valueV1);
    switch ((unsigned int)valueV1) {
        case 0:
            goto original952_219;
        case 1:
            goto original952_304;
        case 2:
            goto original952Return;
        case 3:
            goto original952Return;
        case 4:
            goto original952Return;
        case 5:
            goto original952Return;
        case 6:
            goto original952Return;
        case 7:
            goto original952Return;
        case 8:
            goto original952Return;
        case 9:
            goto original952Return;
        case 10:
            goto original952Return;
        case 11:
            goto original952Return;
        case 12:
            goto original952Return;
        case 13:
            goto original952Return;
        case 14:
            goto original952Return;
        case 15:
            goto original952Return;
        case 16:
            goto original952Return;
        case 17:
            goto original952Return;
        case 18:
            goto original952Return;
        case 19:
            goto original952Return;
        case 20:
            goto original952Return;
        case 21:
            goto original952Return;
        case 22:
            goto original952Return;
        case 23:
            goto original952Return;
        case 24:
            goto original952Return;
        case 25:
            goto original952Return;
        case 26:
            goto original952Return;
        case 27:
            goto original952Return;
        case 28:
            goto original952Return;
        case 29:
            goto original952Return;
        case 30:
            goto original952_40;
        case 31:
            goto original952_645;
        case 32:
            goto original952_689;
        case 33:
            goto original952_751;
        case 34:
            goto original952_788;
        case 35:
            goto original952_878;
        case 36:
            goto original952_917;
        case 37:
            goto original952_868;
        case 38:
            goto original952_368;
        case 39:
            goto original952Return;
        case 40:
            goto original952_605;
        case 41:
            goto original952Return;
        case 42:
            MATCHING_OBSERVE_VOLATILE(valueV1);
            goto original952_32;
        case 43:
            goto original952_210;
        case 44:
            goto original952_518;
        case 45:
            goto original952_576;
        case 46:
            goto original952_56;
        case 47:
            goto original952_206;
        case 48:
            goto original952_510;
        default:
            goto original952Return;
    }
original952_32:
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 5);
    Actor952RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 6);
    Actor952SetMobyAnimation(argument0, argument1);
    valueV0 = Actor952Add(0, 30);
    goto original952_938;
original952_40:
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 5);
    Actor952RefreshMobySpatialGridAndBasis(argument0, argument1);
    valueV1 = Actor952Field(actor, unsigned char*, 60);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 4);
    Actor952Keep(valueV0);
    if (valueV1 != valueV0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14480);
    Actor952Keep(valueV0);
    argument0 = Actor952Add(actor, 0);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 0);
    Actor952SetMobyAnimation(argument0, argument1);
    goto original952Return;
original952_56:
    valueV1 = Actor952Field(actor, unsigned char*, 73);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 5);
    Actor952Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = Actor952Add(0, 5), 1) : (valueV0 = Actor952Add(0, 5), 0))
        goto original952_155;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    Actor952Field(actor, unsigned char*, 73) = valueV0;
    valueS3 = Actor952Add(0, 0);
    Actor952Keep(valueS3);
    valueS0 = Actor952Add(privateData, 0);
    Actor952Keep(valueS0);
original952_63:
    valueS2 = Actor952Add(0, 0);
    Actor952Keep(valueS2);
    valueS1 = Actor952Add(valueS0, 56);
    Actor952Keep(valueS1);
original952_65:
    valueV1 = Actor952Field(valueS1, int*, 0);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, -1);
    Actor952Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)valueV1 << 1), 1)
                           : (valueV0 = (int)((unsigned int)valueV1 << 1), 0))
        goto original952_111;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Sub(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor952Keep(valueV1);
    valueV1 = Actor952Field(valueV1, int*, -15024);
    Actor952Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor952Keep(valueV0);
    argument0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(argument0);
    valueV0 = Actor952Field(argument0, unsigned char*, 72);
    Actor952Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor952Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = Actor952Add(0, 255), 1) : (valueV0 = Actor952Add(0, 255), 0))
        goto original952_111;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor952Field(argument0, unsigned char*, 58);
    Actor952Keep(valueV1);
    argument1 = Actor952Add(0, 1);
    if (valueV1 != valueV0)
        goto original952_109;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument2 = Actor952Add(0, 0);
    Actor952Keep(argument2);
    argument3 = Actor952Add(0, 0);
    Actor952_func_80036A68(argument0, argument1, argument2, argument3);
    valueV0 = Actor952Field(valueS1, int*, 0);
    Actor952Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor952Keep(argument0);
    argument0 = Actor952Add(argument0, valueV0);
    Actor952Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor952Keep(argument0);
    argument0 = Actor952Sub(argument0, valueV0);
    Actor952Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -15024);
    Actor952Keep(valueV0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor952Keep(argument0);
    argument0 = Actor952Add(valueV0, argument0);
    Actor952_func_8003BA00(argument0);
    valueV0 = Actor952Field(valueS1, int*, 0);
    Actor952Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor952Keep(argument0);
    argument0 = Actor952Add(argument0, valueV0);
    Actor952Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor952Keep(argument0);
    argument0 = Actor952Sub(argument0, valueV0);
    Actor952Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -15024);
    Actor952Keep(valueV0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor952Keep(argument0);
    argument0 = Actor952Add(valueV0, argument0);
    Actor952Keep(argument0);
original952_109:
    Actor952DeleteMoby(argument0);
original952_111:
    valueS2 = Actor952Add(valueS2, 1);
    Actor952Keep(valueS2);
    valueV0 = valueS2 < 24;
    Actor952Keep(valueV0);
    valueS1 = Actor952Add(valueS1, 4);
    if (valueV0 != 0)
        goto original952_65;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS3 = Actor952Add(valueS3, 1);
    Actor952Keep(valueS3);
    valueV0 = valueS3 < 3;
    Actor952Keep(valueV0);
    valueS0 = Actor952Add(valueS0, 96);
    if (valueV0 != 0)
        goto original952_63;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS0 = (int)0x80070000U;
    Actor952Keep(valueS0);
    valueS0 = Actor952Field(valueS0, int*, -15024);
    Actor952Keep(valueS0);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14588);
    Actor952Keep(valueV0);
    valueV0 = (unsigned int)valueS0 < (unsigned int)valueV0;
    Actor952Keep(valueV0);
    valueS1 = Actor952Add(valueS0, 58);
    if (valueV0 == 0)
        goto original952_155;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS2 = Actor952Add(0, 450);
    Actor952Keep(valueS2);
original952_128:
    valueV0 = Actor952Field(valueS1, short*, -4);
    Actor952Keep(valueV0);
    if (valueV0 != valueS2)
        goto original952_149;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueS2);
    valueV0 = Actor952Field(valueS1, unsigned char*, 14);
    Actor952Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor952Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = Actor952Add(0, 255), 1) : (valueV0 = Actor952Add(0, 255), 0))
        goto original952_149;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor952Field(valueS1, unsigned char*, 0);
    Actor952Keep(valueV1);
    argument0 = Actor952Add(valueS0, 0);
    if (valueV1 != valueV0)
        goto original952_147;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = Actor952Add(0, 0);
    Actor952Keep(argument2);
    argument3 = Actor952Add(0, 0);
    Actor952_func_80036A68(argument0, argument1, argument2, argument3);
    argument0 = Actor952Add(valueS0, 0);
    Actor952_func_8003BA00(argument0);
original952_147:
    argument0 = Actor952Add(valueS0, 0);
    Actor952DeleteMoby(argument0);
original952_149:
    MATCHING_BARRIER_VOLATILE("$2");
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14588);
    Actor952Keep(valueV0);
    valueS0 = Actor952Add(valueS0, 88);
    Actor952Keep(valueS0);
    valueV0 = (unsigned int)valueS0 < (unsigned int)valueV0;
    Actor952Keep(valueV0);
    valueS1 = Actor952Add(valueS1, 88);
    if (valueV0 != 0)
        goto original952_128;
    MATCHING_KEEP_VOLATILE(valueV0);
original952_155:
    MATCHING_OBSERVE_VOLATILE_CLOBBER(valueV0, "$4");
    argument0 = Actor952Add(0, 9);
    Actor952Keep(argument0);
    valueV0 = Actor952Add(0, 255);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 74) = valueV0;
    Actor952Field(actor, unsigned char*, 65) = 0;
    Actor952Field(actor, unsigned char*, 76) = 0;
    Actor952Field(actor, unsigned char*, 77) = 0;
    Actor952Field(actor, int*, 8) = 0;
    valueV0 = Actor952_func_80021F3C(argument0);
    valueS1 = Actor952Add(valueV0, 0);
    Actor952Keep(valueS1);
    valueV0 = (valueS1 >> 8);
    Actor952Keep(valueV0);
    valueS0 = valueV0 & 255;
    Actor952Keep(valueS0);
    valueV0 = valueS1 & 15;
    if (valueS0 != 0)
        goto original952_173;
    MATCHING_KEEP_VOLATILE(valueS0);
    argument0 = Actor952Add(0, 9);
    if (valueV0 == 0)
        goto original952_173;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 252);
    Actor952Keep(argument1);
    argument2 = Actor952Add(0, 0);
    Actor952_func_80021ED8(argument0, argument1, argument2);
original952_173:
    argument0 = Actor952Add(0, 10);
    valueV0 = Actor952_func_80021F3C(argument0);
    valueS1 = Actor952Add(valueV0, 0);
    Actor952Keep(valueS1);
    valueV0 = (valueS1 >> 8);
    Actor952Keep(valueV0);
    valueS0 = valueV0 & 255;
    Actor952Keep(valueS0);
    valueV0 = Actor952Add(0, 60);
    Actor952Keep(valueV0);
    valueS2 = valueS1 & 15;
    if (valueS0 == valueV0)
        goto original952_206;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueS0);
    argument0 = Actor952Add(0, 10);
    if (valueS2 == 0)
        goto original952_186;
    MATCHING_KEEP_VOLATILE(valueS2);
    argument1 = Actor952Add(0, 252);
    Actor952Keep(argument1);
    argument2 = Actor952Add(0, 0);
    Actor952_func_80021ED8(argument0, argument1, argument2);
original952_186:
    valueV0 = Actor952Add(valueS0, -2);
    Actor952Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 16;
    Actor952Keep(valueV0);
    if (valueV0 == 0)
        goto original952_195;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = Actor952Add(valueS0, -20);
    if (valueS2 != 0)
        goto original952_196;
    MATCHING_KEEP_VOLATILE(valueS2);
    argument0 = Actor952Add(0, 10);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 18);
    goto original952_202;
original952_195:
    valueV0 = Actor952Add(valueS0, -20);
    Actor952Keep(valueV0);
original952_196:
    valueV0 = (unsigned int)valueV0 < 39;
    Actor952Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = valueS1 & 15, 1) : (valueV0 = valueS1 & 15, 0))
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument0 = Actor952Add(0, 10);
    if (valueV0 != 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 59);
    Actor952Keep(argument1);
original952_202:
    argument2 = Actor952Add(0, 0);
    Actor952_func_80021F8C(argument0, argument1, argument2);
    goto original952Return;
original952_206:
    argument0 = Actor952Add(actor, 0);
    Actor952DeleteMoby(argument0);
    goto original952Return;
original952_210:
    valueV0 = Actor952Field(privateData, int*, 40);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, 1);
    Actor952Keep(valueV0);
    Actor952Field(privateData, int*, 40) = valueV0;
    valueV0 = valueV0 < 30;
    Actor952Keep(valueV0);
    if (valueV0 != 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor952Field(actor, unsigned char*, 72) = 0;
    goto original952Return;
original952_219:
    argument0 = Actor952Add(actor, 12);
    Actor952Keep(argument0);
    valueS1 = (int)&Actor952_D_80070328;
    Actor952Keep(valueS1);
    argument1 = Actor952Add(valueS1, 0);
    valueV0 = Actor952ApproximatePlanarDistance(argument0, argument1);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 0);
    Actor952Keep(argument1);
    valueS0 = Actor952Add(valueV0, 0);
    valueV0 = Actor952_func_80037BBC(argument0, argument1);
    if (valueV0 != 0)
        goto original952_250;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = valueS0 < 3072;
    Actor952Keep(valueV0);
    if (valueV0 != 0)
        goto original952_250;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV0 = valueS0 < 6144;
    Actor952Keep(valueV0);
    argument2 = Actor952Add(0, 0);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor952Field(valueS1, int*, 0);
    Actor952Keep(valueV1);
    argument0 = Actor952Field(actor, int*, 12);
    Actor952Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 812);
    Actor952Keep(valueV0);
    argument1 = Actor952Field(actor, int*, 16);
    Actor952Keep(argument1);
    argument0 = Actor952Sub(valueV1, argument0);
    Actor952Keep(argument0);
    argument1 = Actor952Sub(valueV0, argument1);
    valueV0 = Actor952PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(argument1);
    argument0 = Actor952Add(valueV0, 0);
    valueV0 = Actor952AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 65;
    Actor952Keep(valueV0);
    if (valueV0 != 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
original952_250:
    valueS0 = Actor952Add(actor, 72);
    Actor952Keep(valueS0);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    valueS1 = (int)&Actor952_D_8006D088;
    Actor952Keep(valueS1);
    argument2 = Actor952Add(valueS1, 0);
    Actor952Keep(argument2);
    valueV0 = Actor952Add(0, 43);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(argument2);
    argument1 = Actor952Add(0, 1);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
    valueS0 = (int)&frame.fields.sp30;
    Actor952Keep(valueS0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor952Keep(valueV0);
    valueV1 = Actor952Field(((int)&Actor952_D_80065920 + valueV0), short*, 0);
    Actor952Keep(valueV1);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (valueV0 >> 5);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 16) = valueV0;
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
    argument1 = Actor952Add(actor, 12);
    Actor952Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor952Keep(valueV0);
    valueV1 = Actor952Field(((int)&Actor952_D_800658A0 + valueV0), short*, 0);
    Actor952Keep(valueV1);
    argument2 = Actor952Add(valueS0, 0);
    Actor952Keep(argument2);
    Actor952Field((int)&frame, int*, 24) = 0;
    __asm__ volatile("" ::"m"(Actor952Field((int)&frame, int*, 24)));
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (valueV0 >> 5);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 20) = valueV0;
    Actor952AddVector(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument2 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(argument2);
    argument1 = Actor952Add(valueS0, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(argument2, 128);
    Actor952Keep(argument2);
    argument2 = argument2 & 255;
    Actor952_func_8003B634(argument0, argument1, argument2);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(0, 1);
    Actor952_func_800512E4(argument0, argument1, argument2);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(actor, "memory");
    valueV0 = Actor952Add(0, 1);
    goto original952_938;
original952_304:
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -7356);
    Actor952Keep(valueV0);
    valueS0 = Actor952Add(0, 1);
    Actor952Keep(valueS0);
    argument0 = Actor952Add(actor, 0);
    if (valueV0 == valueS0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueS0);
    argument1 = Actor952Add(0, 0);
    Actor952RequestMobyAnimation(argument0, argument1);
    valueV0 = Actor952Field(privateData, unsigned char*, 0);
    Actor952Keep(valueV0);
    if (valueV0 != valueS0)
        goto original952_937;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueS0);
    valueV1 = Actor952Field(privateData, unsigned char*, 4);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 3);
    if (valueV1 == 0)
        goto original952_321;
    MATCHING_KEEP_VOLATILE(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = Actor952Add(0, 4), 1) : (valueV0 = Actor952Add(0, 4), 0))
        goto original952_364;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
original952_321:
    valueS0 = Actor952Add(privateData, 2);
    Actor952Keep(valueS0);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = (int)&Actor952_D_8006D088;
    Actor952Keep(argument2);
    valueV0 = Actor952Add(0, 2);
    Actor952Keep(valueV0);
    Actor952Field(privateData, unsigned char*, 2) = valueV0;
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(argument2);
    argument1 = Actor952Add(0, 1);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    valueV0 = Actor952Add(0, 255);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 74) = valueV0;
    valueV0 = Actor952Add(0, 38);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor952Field(privateData, int*, 344);
    Actor952Keep(valueV0);
    argument0 = Actor952Add(0, 18);
    if (valueV0 != 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 3);
    Actor952Keep(argument1);
    argument2 = Actor952Add(0, 0);
    Actor952Keep(argument2);
    argument3 = Actor952Add(0, 0);
    Actor952Keep(argument3);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14396);
    Actor952Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor952Keep(valueV1);
    valueV1 = Actor952Field(valueV1, int*, 17264);
    Actor952Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)&frame + (unsigned int)valueV0 - 32U);
    Actor952Keep(valueV0);
    __asm__ volatile("lw %0,32(%1)" : "=r"(valueV0) : "r"(valueV0) : "memory");
    valueT0 = Actor952Add(0, 5400);
    Actor952Keep(valueT0);
    Actor952Field(privateData, int*, 348) = valueT0;
    __asm__ volatile("" ::"m"(Actor952Field(privateData, int*, 348)));
    Actor952Field(privateData, int*, 40) = valueV0;
    valueV0 = Actor952Add(privateData, 348);
    Actor952Keep(valueV0);
    stackArgument4 = valueV1;
    stackArgument5 = valueV0;
    stackArgument6 = valueT0;
    valueV0 = Actor952_func_8002803C(argument0, argument1, argument2, argument3, stackArgument4,
                                     stackArgument5, stackArgument6);
    valueV0 = (int)((unsigned int)valueV0 << 16);
    Actor952Keep(valueV0);
    valueV0 = (valueV0 >> 16);
    Actor952Keep(valueV0);
    Actor952Field(privateData, int*, 344) = valueV0;
    goto original952Return;
original952_364:
    if (valueV1 != valueV0 ? (valueV0 = Actor952Add(0, 30), 1) : (valueV0 = Actor952Add(0, 30), 0))
        goto original952_938;
    valueV0 = Actor952Add(0, 40);
    goto original952_938;
original952_368:
    argument0 = Actor952Add(privateData, 40);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    valueV0 = Actor952CountTimerDown(argument0, argument1);
    if (valueV0 == 0)
        goto original952_483;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument0 = Actor952Field(privateData, int*, 344);
    Actor952Keep(argument0);
    valueS6 = Actor952Add(actor, 12);
    Actor952_func_80028154(argument0);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    Actor952Field(privateData, int*, 344) = 0;
    Actor952RefreshMobySpatialGridAndBasis(argument0, argument1);
    valueT1 = Actor952Add(actor, 32);
    Actor952Keep(valueT1);
    valueS2 = (int)&frame.fields.sp40;
    Actor952Keep(valueS2);
    argument1 = Actor952Add(valueS2, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS2, 0);
    Actor952Keep(argument2);
    Actor952Field((int)&frame, int*, 104) = valueT1;
    argument0 = Actor952Field((int)&frame, volatile int*, 104);
    Actor952Keep(argument0);
    valueV0 = Actor952Add(0, 2048);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 32) = valueV0;
    valueV0 = Actor952Add(0, 512);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 36) = 0;
    Actor952Field((int)&frame, int*, 40) = valueV0;
    Actor952TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS2, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS6, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS2, 0);
    Actor952AddVector(argument0, argument1, argument2);
    valueS5 = (int)&frame.fields.sp50;
    Actor952Keep(valueS5);
    argument0 = Actor952Add(valueS5, 0);
    Actor952Keep(argument0);
    valueS0 = (int)&Actor952_D_80070328;
    Actor952Keep(valueS0);
    argument1 = Actor952Add(valueS0, 0);
    Actor952CopyVector(argument0, argument1);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    valueT1 = Actor952Field(valueS0, unsigned char*, 14);
    Actor952Keep(valueT1);
    argument1 = Actor952Add(valueS2, 0);
    Actor952Keep(argument1);
    Actor952Field((int)&frame, int*, 96) = valueT1;
    Actor952CopyVector(argument0, argument1);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    valueS4 = (int)&Actor952_D_8006D088;
    Actor952Keep(valueS4);
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
    argument2 = Actor952Add(valueS4, 0);
    Actor952Keep(argument2);
    valueV0 = Actor952Add(valueV0, 128);
    Actor952Keep(valueV0);
    Actor952Field(valueS0, unsigned char*, 14) = valueV0;
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    valueS3 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(valueS3);
    argument2 = Actor952Add(valueS3, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    valueS1 = Actor952Add(valueS0, 4);
    Actor952Keep(valueS1);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS4, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS3, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    valueS1 = Actor952Add(valueS0, 8);
    Actor952Keep(valueS1);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS4, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS3, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    valueS1 = Actor952Add(valueS0, 14);
    Actor952Keep(valueS1);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS4, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS1, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS3, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS5, 0);
    Actor952CopyVector(argument0, argument1);
    argument1 = Actor952Add(valueS2, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS2, 0);
    Actor952Keep(argument2);
    argument0 = Actor952Field((int)&frame, volatile int*, 104);
    Actor952Keep(argument0);
    valueT1 = Actor952Field((int)&frame, volatile unsigned char*, 96);
    MATCHING_OBSERVE_VOLATILE(valueT1);
    valueV0 = Actor952Add(0, 5120);
    Actor952Keep(valueV0);
    Actor952Field(valueS0, unsigned char*, 14) = valueT1;
    Actor952Field((int)&frame, int*, 32) = valueV0;
    valueV0 = Actor952Add(0, 4092);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 36) = 0;
    Actor952Field((int)&frame, int*, 40) = valueV0;
    Actor952TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS2, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS6, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS2, 0);
    Actor952AddVector(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS5, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS6, 0);
    Actor952CopyVector(argument0, argument1);
    argument0 = Actor952Add(valueS2, 0);
    Actor952Keep(argument0);
    valueV0 = Actor952Field((int)&frame, volatile int*, 56);
    Actor952Keep(valueV0);
    argument1 = Actor952Add(valueS5, 0);
    Actor952Keep(argument1);
    valueV0 = Actor952Add(valueV0, 300);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 56) = valueV0;
    Actor952_func_80013AE4(argument0, argument1);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 6);
    Actor952SetMobyAnimation(argument0, argument1);
    valueV0 = Actor952Add(0, 60);
    Actor952Keep(valueV0);
    Actor952Field(privateData, int*, 40) = valueV0;
    valueV0 = Actor952Add(0, 44);
    goto original952_938;
original952_483:
    valueV1 = Actor952Field(privateData, int*, 40);
    Actor952Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 4);
    Actor952Keep(argument0);
    argument0 = Actor952Sub(argument0, valueV0);
    Actor952Keep(argument0);
    valueV0 = (int)((unsigned int)argument0 << 4);
    Actor952Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor952Keep(valueV1);
    valueV1 = Actor952Field(valueV1, int*, -14396);
    Actor952Keep(valueV1);
    valueV0 = Actor952Sub(valueV0, argument0);
    Actor952Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor952Keep(valueV1);
    valueV1 = (int)((unsigned int)&frame + (unsigned int)valueV1 - 32U);
    Actor952Keep(valueV1);
    __asm__ volatile("lw %0,32(%1)" : "=r"(valueV1) : "r"(valueV1) : "memory");
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor952Keep(valueV0);
    valueV0 = valueV0 / valueV1;
    Actor952Keep(valueV0);
    Actor952Field(privateData, int*, 348) = valueV0;
    goto original952Return;
original952_510:
    argument0 = Actor952Field(privateData, int*, 344);
    Actor952Keep(argument0);
    if (argument0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(argument0);
    Actor952_func_80028154(argument0);
    Actor952Field(privateData, int*, 344) = 0;
    goto original952Return;
original952_518:
    argument0 = Actor952Add(privateData, 40);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    valueV0 = Actor952CountTimerDown(argument0, argument1);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS0 = (int)0x80070000U;
    Actor952Keep(valueS0);
    valueS0 = Actor952Field(valueS0, int*, -15024);
    Actor952Keep(valueS0);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14588);
    Actor952Keep(valueV0);
    valueV0 = (unsigned int)valueS0 < (unsigned int)valueV0;
    Actor952Keep(valueV0);
    valueS4 = Actor952Add(0, 300);
    if (valueV0 == 0)
        goto original952_572;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS3 = (int)&frame.fields.sp60;
    Actor952Keep(valueS3);
    valueS2 = Actor952Add(valueS0, 70);
    Actor952Keep(valueS2);
original952_533:
    valueV1 = Actor952Field(valueS2, short*, -16);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 258);
    Actor952Keep(valueV0);
    argument0 = Actor952Add(0, 411);
    if (valueV1 != valueV0)
        goto original952_566;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 17120);
    Actor952Keep(valueV0);
    argument1 = Actor952Add(actor, 0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS1 = Actor952Add(valueV0, 0);
    Actor952Keep(valueS1);
    argument0 = Actor952Add(valueS0, 0);
    if (valueS1 == 0)
        goto original952_563;
    MATCHING_KEEP_VOLATILE(valueS1);
    valueV0 = Actor952Field(valueS1, int*, 0);
    Actor952Keep(valueV0);
    argument1 = Actor952Add(0, 4);
    Actor952Keep(argument1);
    Actor952Field(valueV0, int*, 0) = 0;
    Actor952RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = Actor952Add(valueS0, 32);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS3, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS3, 0);
    Actor952Keep(argument2);
    Actor952Field((int)&frame, int*, 64) = valueS4;
    Actor952Field((int)&frame, int*, 68) = 0;
    Actor952Field((int)&frame, int*, 72) = valueS4;
    Actor952TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS1, 12);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS0, 12);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS3, 0);
    Actor952AddVector(argument0, argument1, argument2);
    valueV0 = Actor952Field(valueS2, unsigned char*, 0);
    Actor952Keep(valueV0);
    Actor952Field(valueS1, unsigned char*, 70) = valueV0;
original952_563:
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952SetMobyAnimation(argument0, argument1);
original952_566:
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14588);
    Actor952Keep(valueV0);
    valueS0 = Actor952Add(valueS0, 88);
    Actor952Keep(valueS0);
    valueV0 = (unsigned int)valueS0 < (unsigned int)valueV0;
    Actor952Keep(valueV0);
    valueS2 = Actor952Add(valueS2, 88);
    if (valueV0 != 0)
        goto original952_533;
    MATCHING_KEEP_VOLATILE(valueV0);
original952_572:
    valueV0 = Actor952Add(0, 90);
    Actor952Keep(valueV0);
    Actor952Field(privateData, int*, 40) = valueV0;
    valueV0 = Actor952Add(0, 45);
    goto original952_938;
original952_576:
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, -14480);
    Actor952Keep(valueV0);
    argument0 = Actor952Add(actor, 0);
    if (valueV0 == 0)
        goto original952_583;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 0);
    Actor952RequestMobyAnimation(argument0, argument1);
original952_583:
    argument0 = Actor952Add(privateData, 40);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    valueV0 = Actor952CountTimerDown(argument0, argument1);
    if (valueV0 == 0 ? (valueV0 = Actor952Add(0, 5), 1) : (valueV0 = Actor952Add(0, 5), 0))
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor952Field(privateData, unsigned char*, 2) = valueV0;
    valueS0 = Actor952Add(privateData, 2);
    Actor952Keep(valueS0);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    valueS1 = (int)&Actor952_D_8006D088;
    Actor952Keep(valueS1);
    argument2 = Actor952Add(valueS1, 0);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(argument2);
    argument1 = Actor952Add(0, 1);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS1, 0);
    Actor952_func_8003B74C(argument0);
    goto original952Return;
original952_605:
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 4);
    Actor952RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = Actor952Add(actor, 32);
    Actor952Keep(argument0);
    valueS0 = (int)&frame.fields.sp60;
    Actor952Keep(valueS0);
    argument1 = Actor952Add(valueS0, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS0, 0);
    Actor952Keep(argument2);
    valueV0 = Actor952Add(0, 5120);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 64) = valueV0;
    Actor952Field((int)&frame, int*, 68) = 0;
    Actor952Field((int)&frame, int*, 72) = 0;
    Actor952TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(actor, 12);
    Actor952Keep(argument1);
    argument2 = Actor952Add(valueS0, 0);
    Actor952AddVector(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(argument1);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 17200);
    Actor952Keep(valueV0);
    argument2 = Actor952Add(0, 0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1, argument2);
    valueS0 = Actor952Add(privateData, 2);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = (int)&Actor952_D_8006D088;
    Actor952Keep(argument2);
    Actor952Field(privateData, unsigned char*, 2) = 0;
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(argument2);
    argument1 = Actor952Add(0, 1);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    valueV0 = Actor952Add(0, 2);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = 0;
    Actor952Field(privateData, unsigned char*, 2) = valueV0;
    goto original952Return;
original952_645:
    argument0 = Actor952Field(privateData, int*, 344);
    Actor952Keep(argument0);
    if (argument0 == 0)
        goto original952_651;
    MATCHING_KEEP_VOLATILE(argument0);
    Actor952_func_80028154(argument0);
original952_651:
    valueV0 = Actor952Field(privateData, int*, 52);
    Actor952Keep(valueV0);
    valueS0 = Actor952Field(valueV0, int*, 12);
    Actor952Keep(valueS0);
    argument0 = Actor952Add(actor, 12);
    Actor952Keep(argument0);
    argument1 = Actor952Add(valueS0, 0);
    Actor952CopyVector(argument0, argument1);
    argument2 = Actor952Add(0, 0);
    Actor952Keep(argument2);
    valueV0 = Actor952Field(privateData, int*, 52);
    Actor952Keep(valueV0);
    argument0 = Actor952Field(valueS0, int*, 0);
    Actor952Keep(argument0);
    valueV0 = Actor952Field(valueV0, int*, 12);
    Actor952Keep(valueV0);
    argument1 = Actor952Field(valueS0, int*, 4);
    Actor952Keep(argument1);
    valueV1 = Actor952Field(valueV0, int*, 16);
    Actor952Keep(valueV1);
    valueV0 = Actor952Field(valueV0, int*, 20);
    Actor952Keep(valueV0);
    argument0 = Actor952Sub(valueV1, argument0);
    Actor952Keep(argument0);
    argument1 = Actor952Sub(valueV0, argument1);
    valueV0 = Actor952PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 5);
    Actor952Keep(argument1);
    Actor952Field(actor, unsigned char*, 70) = valueV0;
    Actor952SetMobyAnimation(argument0, argument1);
    valueV0 = Actor952Field(actor, short*, 54);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(((int)&Actor952_D_8006EE2C + valueV0), int*, 0);
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 80);
    Actor952Keep(valueV0);
    argument1 = Actor952Field(valueV0, unsigned char*, 0);
    Actor952Keep(argument1);
    argument0 = Actor952Add(0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(argument1, -2);
    valueV0 = Actor952RandBetween(argument0, argument1);
    Actor952Field(actor, unsigned char*, 62) = valueV0;
    valueV0 = Actor952Add(valueV0, 1);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 63) = valueV0;
    valueV0 = Actor952Add(0, 32);
    goto original952_938;
original952_689:
    valueV0 = Actor952ForwardOriginal(actor, privateData);
    valueV0 = valueV0 & 2;
    Actor952Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = Actor952Add(0, 3), 1) : (valueV0 = Actor952Add(0, 3), 0))
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor952Field(actor, unsigned char*, 73);
    Actor952Keep(valueV1);
    argument0 = Actor952Add(actor, 0);
    if (valueV1 != valueV0)
        goto original952_721;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    MATCHING_BARRIER_VOLATILE("$4");
    argument0 = Actor952Add(actor, 0);
    valueV0 = Actor952ProbeGroundFromRaisedMoby(argument0);
    argument0 = Actor952Add(actor, 0);
    if (valueV0 == 0)
        goto original952_712;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor952Field(actor, int*, 20) = valueV0;
original952_712:
    argument1 = Actor952Add(0, 0);
    Actor952SetMobyAnimation(argument0, argument1);
    valueV0 = Actor952Add(0, 60);
    Actor952Keep(valueV0);
    Actor952Field(privateData, int*, 40) = valueV0;
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
    valueV1 = Actor952Add(0, 34);
    Actor952Keep(valueV1);
    Actor952Field(actor, unsigned char*, 73) = 0;
    Actor952Field(actor, unsigned char*, 72) = valueV1;
    goto original952_784;
original952_721:
    argument1 = Actor952Add(0, 3);
    Actor952SetMobyAnimation(argument0, argument1);
    valueV0 = Actor952Field(actor, short*, 54);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(((int)&Actor952_D_8006EE2C + valueV0), int*, 0);
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 72);
    Actor952Keep(valueV0);
    argument1 = Actor952Field(valueV0, unsigned char*, 0);
    Actor952Keep(argument1);
    argument0 = Actor952Add(0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(argument1, -2);
    valueV0 = Actor952RandBetween(argument0, argument1);
    Actor952Field(actor, unsigned char*, 62) = valueV0;
    valueV0 = Actor952Add(valueV0, 1);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 63) = valueV0;
    valueV0 = Actor952Add(0, 33);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    valueV1 = Actor952Field(privateData, int*, 52);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, -1);
    Actor952Keep(valueV0);
    Actor952Field(valueV1, short*, 10) = valueV0;
    valueV1 = Actor952Field(privateData, int*, 52);
    Actor952Keep(valueV1);
    valueV0 = Actor952Field(valueV1, unsigned short*, 0);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, -1);
    Actor952Keep(valueV0);
    Actor952Field(valueV1, short*, 2) = valueV0;
    goto original952Return;
original952_751:
    valueV0 = Actor952ForwardOriginal(actor, privateData);
    valueV0 = valueV0 & 2;
    Actor952Keep(valueV0);
    valueS0 = Actor952Add(actor, 72);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = (int)&Actor952_D_8006D088;
    Actor952Keep(argument2);
    valueV0 = Actor952Add(0, 47);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(argument2);
    argument1 = Actor952Add(0, 1);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 0);
    Actor952Keep(argument1);
    valueV0 = Actor952Add(0, 37);
    Actor952Keep(valueV0);
    Actor952Field(privateData, unsigned char*, 5) = 0;
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    Actor952SetMobyAnimation(argument0, argument1);
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
original952_784:
    valueV0 = Actor952Add(valueV0, 128);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 70) = valueV0;
    goto original952Return;
original952_788:
    argument0 = (int)0x10000000U;
    Actor952Keep(argument0);
    valueV1 = (int)&Actor952_D_80070328 + 524;
    Actor952Keep(valueV1);
    valueV0 = Actor952Field(valueV1, int*, 0);
    Actor952Keep(valueV0);
    argument0 = argument0 | 8192;
    Actor952Keep(argument0);
    valueV0 = valueV0 | argument0;
    Actor952Keep(valueV0);
    Actor952Field(valueV1, int*, 0) = valueV0;
    valueV1 = Actor952Field(actor, unsigned char*, 73);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 4);
    Actor952Keep(valueV0);
    if (valueV1 == valueV0)
        goto original952_806;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument0 = Actor952Add(0, 6);
    valueV0 = Actor952_func_80021F3C(argument0);
    valueV0 = valueV0 & 15;
    Actor952Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = Actor952Add(0, 4), 1) : (valueV0 = Actor952Add(0, 4), 0))
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor952Field(actor, unsigned char*, 73) = valueV0;
    goto original952Return;
original952_806:
    argument0 = Actor952Add(0, 6);
    valueV0 = Actor952_func_80021F3C(argument0);
    valueV0 = valueV0 & 15;
    Actor952Keep(valueV0);
    argument0 = Actor952Add(privateData, 40);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 4);
    valueV0 = Actor952CountTimerDown(argument0, argument1);
    if (valueV0 == 0 ? (valueV0 = Actor952Add(0, 6), 1) : (valueV0 = Actor952Add(0, 6), 0))
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueV1 = Actor952Field(actor, int*, 0);
    Actor952Keep(valueV1);
    Actor952Field(actor, unsigned char*, 73) = valueV0;
    valueV0 = Actor952Add(0, 35);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor952Add(0, 2);
    Actor952Keep(valueV0);
    Actor952Field(valueV1, unsigned char*, 5) = valueV0;
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
    valueS0 = (int)&frame.fields.sp70;
    Actor952Keep(valueS0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor952Keep(valueV0);
    valueV1 = Actor952Field(((int)&Actor952_D_80065920 + valueV0), short*, 0);
    Actor952Keep(valueV1);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    valueV0 = (int)((unsigned int)valueV1 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor952Keep(valueV0);
    valueV0 = Actor952Sub(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (valueV0 >> 6);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 80) = valueV0;
    valueV0 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(valueV0);
    argument1 = Actor952Add(valueS0, 0);
    Actor952Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor952Keep(valueV0);
    valueV1 = Actor952Field(((int)&Actor952_D_800658A0 + valueV0), short*, 0);
    Actor952Keep(valueV1);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 876);
    Actor952Keep(valueV0);
    argument2 = Actor952Add(actor, 12);
    Actor952Keep(argument2);
    Actor952Field((int)&frame, int*, 88) = 0;
    __asm__ volatile("" ::"m"(Actor952Field((int)&frame, int*, 88)));
    Actor952Field((int)&frame, int*, 88) = valueV0;
    valueV0 = (int)((unsigned int)valueV1 << 2);
    Actor952Keep(valueV0);
    valueV0 = Actor952Add(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor952Keep(valueV0);
    valueV0 = Actor952Sub(valueV0, valueV1);
    Actor952Keep(valueV0);
    valueV0 = (valueV0 >> 6);
    Actor952Keep(valueV0);
    Actor952Field((int)&frame, int*, 84) = valueV0;
    Actor952AddVector(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = Actor952Add(0, 0);
    Actor952Keep(argument2);
    argument1 = Actor952Field(actor, unsigned char*, 70);
    Actor952Keep(argument1);
    argument3 = Actor952Add(0, 0);
    Actor952Keep(argument3);
    argument1 = Actor952Add(argument1, 128);
    Actor952Keep(argument1);
    argument1 = argument1 & 255;
    Actor952_func_80013D44(argument0, argument1, argument2, argument3);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, int*, 1448);
    Actor952Keep(valueV0);
    if (valueV0 >= 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor952Field((int)&Actor952_D_80070328 + 640, int*, 0) = 0;
    goto original952Return;
original952_868:
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 0);
    valueV0 = Actor952_func_80037BBC(argument0, argument1);
    argument0 = Actor952Add(actor, 0);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 0);
    Actor952Keep(argument1);
    argument2 = Actor952Add(0, 1);
    Actor952_func_800512E4(argument0, argument1, argument2);
    __asm__ volatile("" ::"i"(0x80080F7CU));
    valueV0 = Actor952Add(0, 36);
    goto original952_938;
original952_878:
    valueV1 = Actor952Field(actor, unsigned char*, 73);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 6);
    Actor952Keep(valueV0);
    argument0 = Actor952Add(actor, 0);
    if (valueV1 != valueV0)
        goto original952_902;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument0 = (int)0x10000000U;
    Actor952Keep(argument0);
    valueV1 = (int)&Actor952_D_80070328 + 524;
    Actor952Keep(valueV1);
    valueV0 = Actor952Field(valueV1, int*, 0);
    Actor952Keep(valueV0);
    argument0 = argument0 | 8192;
    Actor952Keep(argument0);
    valueV0 = valueV0 | argument0;
    Actor952Keep(valueV0);
    Actor952Field(valueV1, int*, 0) = valueV0;
    valueV1 = (int)0x80070000U;
    Actor952Keep(valueV1);
    valueV1 = Actor952Field(valueV1, int*, -8120);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 1);
    Actor952Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = Actor952Add(0, 7), 1) : (valueV0 = Actor952Add(0, 7), 0))
        goto original952_901;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    Actor952Field(actor, unsigned char*, 73) = valueV0;
    __asm__ volatile("" ::"m"(Actor952Field(actor, unsigned char*, 73)));
    valueV1 = (int)0x80070000U;
    Actor952Keep(valueV1);
    valueV1 = Actor952Field(valueV1, int*, -14756);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 16);
    if (valueV1 == 0)
        goto original952_901;
    MATCHING_KEEP_VOLATILE(valueV1);
    Actor952Field(valueV1, unsigned char*, 76) = valueV0;
original952_901:
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
original952_902:
    argument1 = Actor952Add(0, 0);
    valueV0 = Actor952_func_80037BBC(argument0, argument1);
    argument0 = Actor952Add(actor, 0);
    if (valueV0 == 0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    argument1 = Actor952Add(0, 0);
    Actor952Keep(argument1);
    valueV0 = (int)0x80070000U;
    Actor952Keep(valueV0);
    valueV0 = Actor952Field(valueV0, unsigned char*, -14412);
    Actor952Keep(valueV0);
    argument2 = Actor952Add(0, 1);
    Actor952Keep(argument2);
    valueV0 = valueV0 | 4;
    Actor952Keep(valueV0);
    Actor952Field((int)&Actor952_D_8006C7B4, unsigned char*, 0) = valueV0;
    Actor952Field(actor, unsigned char*, 73) = 0;
    Actor952_func_800512E4(argument0, argument1, argument2);
    valueV0 = Actor952Add(0, 36);
    goto original952_938;
original952_917:
    valueV1 = (int)0x80070000U;
    Actor952Keep(valueV1);
    valueV1 = Actor952Field(valueV1, int*, -7356);
    Actor952Keep(valueV1);
    valueV0 = Actor952Add(0, 1);
    Actor952Keep(valueV0);
    valueS0 = Actor952Add(actor, 72);
    if (valueV1 == valueV0)
        goto original952Return;
    MATCHING_KEEP_VOLATILE(valueV0);
    MATCHING_KEEP_VOLATILE(valueV1);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 1);
    Actor952Keep(argument1);
    argument2 = (int)&Actor952_D_8006D088;
    Actor952Keep(argument2);
    valueV0 = Actor952Add(0, 46);
    Actor952Keep(valueV0);
    Actor952Field(actor, unsigned char*, 72) = valueV0;
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(valueS0, 0);
    Actor952Keep(argument0);
    argument2 = (int)&Actor952_D_8006C7F8;
    Actor952Keep(argument2);
    argument1 = Actor952Add(0, 1);
    Actor952_func_8003B7B4(argument0, argument1, argument2);
    argument0 = Actor952Add(actor, 0);
    Actor952Keep(argument0);
    argument1 = Actor952Add(0, 0);
    Actor952RequestMobyAnimation(argument0, argument1);
original952_937:
    valueV0 = Actor952Add(0, 30);
    Actor952Keep(valueV0);
original952_938:
    Actor952Field(actor, unsigned char*, 72) = valueV0;
original952Return:
    return;
}
#undef Actor952Field
#undef Actor952Keep
#undef Actor952Add
#undef Actor952Sub


INCLUDE_RODATA("asm/nonmatchings/overlays/level_14/moby", D_level_14_800747C4);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800810B4.
* AI generated; not human reviewed. All1552 original instructions,55 switch
* selectors,one zero pad and every actual destination must match:1608 words.
* Frame1B0hex=432 bytes saves S0..S6/RA;SP20..18F preserves original storage.
* The separate original800747C4 initializer contains complete words360,380,
* 400;all12 bytes require audit independently of the owned switch words.
* Original handwritten21F3C reads A0 only and produces V0;the existing void
* header is insufficient. Its complete caller/table and no-scan result
* domains remain open. Every literal,argument and result here matches disc.
* Three complete trig/height vectors retain original signed table widths,
* factors13/39,shifts5/6 and the distinct sample/argument/store ordering.
* Packed bytesB8/B9/BA and148/149/14A,descriptor halfwords134/136 and the
* complete SP84/SP88 phases retain their original widths and positions.
* Four particle loops preserve both RNG calls,late counters,table samples,
* original zero-height writes and complete callback argument producers.
* The signed halfword check followsSH134 and clamps against a fresh node
* count. Full initialized word identities preserve that signed conversion.
* Original node-search loop and shared timer/state/return entries retain
* every actual branch destination. The state2 comparison branches to the
* original final store with state30 produced in its delay slot. S1 holds the
* owner first,then the node byte offset,then SP138 after its owner is dead.
* Independent same-address scalar views retain original player loads and
* stores;raw sixteen-byte node indexing is not a coordinate conversion.
* Empty metadata consumes complete initialized values or written fields,
* or clobbers dead values before fresh complete producers;zero CPU words.
* No opcode asm,partial HI/LO,fixed FP,undefined incoming saved register or
* overlapping live fixed aliases. Compiler/filter/flags remain frozen.
* Confidence is binary identity after all gates. Units/fixed point,complete
* helper/caller chains,cadence beyond invocation,Rev1 mapping and synchronized
* runtime remain open. Next:human review and retail captures. Every native/
* linked word,actual destination,owned selector/pad,separate initializer and
* full EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 0f07082e848fd36e3f603a3df41810924bc10f3ae0193c9b8a6731ddbae8e906 */
#define Level14_810B4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level14_810B4Call13ACCView1() __asm__("func_80013ACC");
int Level14_810B4Call13AE4View1() __asm__("func_80013AE4");
int Level14_810B4Call13B7CView1() __asm__("func_80013B7C");
int Level14_810B4Call13D44View1() __asm__("func_80013D44");
int Level14_810B4Call13E38View1() __asm__("func_80013E38");
int Level14_810B4Call1A358View1() __asm__("func_8001A358");
int Level14_810B4Call21ED8View1() __asm__("func_80021ED8");
int Level14_810B4Call21F3CView1() __asm__("func_80021F3C");
int Level14_810B4RequestMobyAnimationView1() __asm__("func_80034F40");
int Level14_810B4SetMobyAnimationView1() __asm__("func_80034F80");
int Level14_810B4CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level14_810B4Call35A80View1() __asm__("func_80035A80");
int Level14_810B4ProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Level14_810B4RandBetweenView1() __asm__("func_8003636C");
int Level14_810B4RandSignedBetweenView1() __asm__("func_800363DC");
int Level14_810B4Call37BBCView1() __asm__("func_80037BBC");
int Level14_810B4Call3B7B4View1() __asm__("func_8003B7B4");
int Level14_810B4Call3BB10View1() __asm__("func_8003BB10");
int Level14_810B4PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level14_810B4BuildPackedAngleBasisMatrixView1() __asm__("func_8004EA90");
int Level14_810B4TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level14_810B4MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level14_810B4ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level14_810B4CopyVectorView1() __asm__("func_8004F178");
int Level14_810B4AddVectorView1() __asm__("func_8004F194");
int Level14_810B4SubtractVectorView1() __asm__("func_8004F1C8");
int Level14_810B4AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level14_810B4ApproachByteAngleView1() __asm__("func_8004F2EC");
int Level14_810B4ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level14_810B4Call512E4View1() __asm__("func_800512E4");
int Level14_810B4DeleteMobyView1() __asm__("func_80055B18");
int Level14_810B4RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level14_810B4Data658A0View1 __asm__("D_800658A0");
extern int Level14_810B4Data65920View1 __asm__("D_80065920");
extern int Level14_810B4Data6C550View1 __asm__("D_8006C550");
extern int Level14_810B4Data6C58CView1 __asm__("D_8006C58C");
extern int Level14_810B4Data6C640View1 __asm__("D_8006C640");
extern int Level14_810B4Data6C65CView1 __asm__("D_8006C65C");
extern unsigned char Level14_810B4Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level14_810B4Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level14_810B4Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level14_810B4Data6D088View1 __asm__("D_8006D088");
extern int Level14_810B4Data6E020View1 __asm__("D_8006E020");
extern unsigned short Level14_810B4Data6E040View1 __asm__("D_8006E040");
extern int Level14_810B4Data6E048View1 __asm__("D_8006E048");
extern int Level14_810B4Data6E160View1 __asm__("D_8006E160");
extern int Level14_810B4Data6E164View1 __asm__("D_8006E164");
extern int Level14_810B4Data6E344View1 __asm__("D_8006E344");
extern int Level14_810B4Data6EE2CView1 __asm__("D_8006EE2C");
extern int Level14_810B4Data70300View1 __asm__("D_80070300");
extern int Level14_810B4Data70328View1 __asm__("D_80070328");
extern int Level14_810B4Data70328View2 __asm__("D_80070328 + 0x48");
extern int Level14_810B4Data70328View3 __asm__("D_80070328 + 0x20C");
extern int Level14_810B4Data71908View1 __asm__("D_80071908");
extern int Level14_810B4Data747C4View1 __asm__("D_level_14_800747C4");
extern void* (*Level14_810B4DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_14_800810B4(void* ownerParameter) {
    register void* ownerThenNodeOffsetOrVector17 __asm__("$17");
    register int privateRecord19 __asm__("$19"),
        retainedHeadingCounterRecordOrVector16 __asm__("$16"),
        retainedCounterBoundOrMatrix18 __asm__("$18"),
        retainedMatrixPlayerTableOrDistance20 __asm__("$20"),
        retainedPackedFlagsNodeIndexOrTable21 __asm__("$21"),
        retainedPackedHighByte22 __asm__("$22");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC, spF0, spF4, spF8, spFC,
            sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C, sp120, sp124, sp128, sp12C,
            sp130, sp134, sp138, sp13C, sp140, sp144, sp148, sp14C, sp150, sp154, sp158, sp15C,
            sp160, sp164, sp168, sp16C, sp170, sp174, sp178, sp17C, sp180, sp184, sp188, sp18C;
    } originalFrame;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord5;
    int temporaryWord7;
    int temporaryWord12;
    int temporaryWord16;
    int temporaryWord13;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord14;
    int temporaryWord1;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord15;
    ownerThenNodeOffsetOrVector17 = ownerParameter;
    MATCHING_KEEP(ownerThenNodeOffsetOrVector17);
    privateRecord19 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, void**, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)&Level14_810B4Data747C4View1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level14_810B4Field(argumentWord5, volatile int*, 0);
    rawWord3 = Level14_810B4Field(argumentWord5, volatile int*, 4);
    argumentWord4 = Level14_810B4Field(argumentWord5, volatile int*, 8);
    Level14_810B4Field(&originalFrame.sp20, volatile int*, 0) = rawWord2;
    Level14_810B4Field(&originalFrame.sp24, volatile int*, 0) = rawWord3;
    Level14_810B4Field(&originalFrame.sp28, volatile int*, 0) = argumentWord4;
    temporaryWord14 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48);
    if (temporaryWord14 >= 0x37U) {
        goto returnOriginal1541;
    }
    switch (temporaryWord14) {
        case 0x1E:
            if (Level14_810B4Field(privateRecord19, unsigned char*, 0) != 0) {
                goto returnOriginal1541;
            }
            temporaryWord16 = Level14_810B4Data6C7B4View1 & 1;
            goto block_65;
        case 0x0:
            if (Level14_810B4Data6C640View1 != 0) {
                goto block_9;
            }
            if (Level14_810B4Data6C7B4View1 & 1) {
                goto block_7;
            }
            if (!(Level14_810B4Field((int)&Level14_810B4Data70300View1, unsigned char*,
                                     Level14_810B4Data6C58CView1) &
                  1)) {
                goto block_9;
            }
        block_7:
            if (Level14_810B4Field(privateRecord19, unsigned char*, 0) != 0) {
                goto block_66;
            }
            Level14_810B4Call21ED8View1(1, 0xFC, 0);
            Level14_810B4Call21ED8View1(2, 0xFC, 0);
            Level14_810B4Call21ED8View1(3, 0xFC, 0);
            Level14_810B4Call21ED8View1(4, 0xFC, 0);
            Level14_810B4Call21ED8View1(5, 0xFC, 0);
            goto block_66;
        block_9:
            if (Level14_810B4Field(privateRecord19, unsigned char*, 0) != 0) {
                goto block_11;
            }
            if (Level14_810B4Data6C7B4View1 & 1) {
                goto block_66;
            }
        block_11:
            if (Level14_810B4Call37BBCView1(ownerThenNodeOffsetOrVector17, 0) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Call512E4View1(ownerThenNodeOffsetOrVector17, 0, 1);
            rawWord2 = 1;
            goto writeOriginalState1540;
        case 0x1:
            if (Level14_810B4Data6E344View1 == 1) {
                goto returnOriginal1541;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0U;
            Level14_810B4RequestMobyAnimationView1(ownerThenNodeOffsetOrVector17, 0);
            temporaryWord4 = Level14_810B4Field(privateRecord19, unsigned char*, 0);
            if (temporaryWord4 == 0) {
                goto writeOriginalState30;
            }
            if ((unsigned int)(temporaryWord4 - 4) >= 3U) {
                goto returnOriginal1541;
            }
        writeOriginalState30:
            rawWord2 = 0x1E;
            goto writeOriginalState1540;
        case 0x2:
            argumentWord4 = privateRecord19 + 40;
            if (Level14_810B4Data6C640View1 != 0) {
                goto testOriginalTimer139;
            }
            if (Level14_810B4Data6C7B4View1 & 1) {
                goto block_66;
            }
            if (Level14_810B4Field((int)&Level14_810B4Data70300View1, unsigned char*,
                                   Level14_810B4Data6C58CView1) &
                1) {
                goto block_66;
            }
        testOriginalTimer139:
            if (Level14_810B4CountTimerDownView1(argumentWord4, 4) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4CopyVectorView1(&originalFrame.sp30, ownerThenNodeOffsetOrVector17 + 0xC);
            originalFrame.sp38 += 0x100;
            originalFrame.sp30 += Level14_810B4RandSignedBetweenView1(0, 0x96);
            originalFrame.sp34 += Level14_810B4RandSignedBetweenView1(0, 0x96);
            originalFrame.sp38 += Level14_810B4RandSignedBetweenView1(0, 0x96);
            originalFrame.sp40 = Level14_810B4RandSignedBetweenView1(0, 0xA);
            originalFrame.sp44 = Level14_810B4RandSignedBetweenView1(0, 0xA);
            originalFrame.sp48 = Level14_810B4RandBetweenView1(5, 8);
            temporaryWord8 = Level14_810B4DataSpawnParticleView1(1, 0x27, &originalFrame.sp30,
                                                                 &originalFrame.sp40);
            if (temporaryWord8 == 0) {
                goto block_23;
            }
            Level14_810B4Field(temporaryWord8, signed char*, 0xA) =
                Level14_810B4RandBetweenView1(8, 0x10);
        block_23:
            Level14_810B4Field(privateRecord19, int*, 0x28) = 3;
            return;
        case 0x14:
            Level14_810B4CopyVectorView1(&originalFrame.sp50, ownerThenNodeOffsetOrVector17 + 0xC);
            originalFrame.sp58 += 0x64;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) =
                (int)(Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) - 0x32);
            if (Level14_810B4Call1A358View1(&originalFrame.sp50, 0xC8) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Field(privateRecord19, unsigned char*, 2) = 0U;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) =
                (int)Level14_810B4Data71908View1;
            Level14_810B4RequestMobyAnimationView1(ownerThenNodeOffsetOrVector17, 0);
            rawWord2 = 0x15;
            goto writeOriginalState1540;
        case 0x1A:
            if (Level14_810B4Data6C640View1 != 0) {
                goto block_29;
            }
            if (Level14_810B4Data6C7B4View1 & 1) {
                goto block_66;
            }
            if (Level14_810B4Field((int)&Level14_810B4Data70300View1, unsigned char*,
                                   Level14_810B4Data6C58CView1) &
                1) {
                goto block_66;
            }
        block_29:
            if (Level14_810B4Field(((Level14_810B4Field(privateRecord19, int*, 0x2C) * 0x58) +
                                    Level14_810B4Data6C550View1),
                                   unsigned char*, 0x48) != 0x18) {
                goto returnOriginal1541;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x4A) = 0xFF;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x1BU;
            Level14_810B4RequestMobyAnimationView1(ownerThenNodeOffsetOrVector17, 3);
            Level14_810B4CopyVectorView1(
                ownerThenNodeOffsetOrVector17 + 0xC,
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x34), void**, 0xC));
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0;
            return;
        case 0x1B:
            if (({
                    MATCHING_KEEP(privateRecord19);
                    Level14_810B4CountTimerDownView1(privateRecord19 + 40, 4);
                }) == 0) {
                goto block_35;
            }
            Level14_810B4CopyVectorView1(&originalFrame.sp60, ownerThenNodeOffsetOrVector17 + 0xC);
            originalFrame.sp60 += Level14_810B4RandSignedBetweenView1(0, 0x96);
            originalFrame.sp64 += Level14_810B4RandSignedBetweenView1(0, 0x96);
            originalFrame.sp68 += Level14_810B4RandSignedBetweenView1(0, 0x96);
            originalFrame.sp70 = Level14_810B4RandSignedBetweenView1(0, 0xA);
            originalFrame.sp74 = Level14_810B4RandSignedBetweenView1(0, 0xA);
            originalFrame.sp78 = Level14_810B4RandBetweenView1(2, 5);
            temporaryWord9 = Level14_810B4DataSpawnParticleView1(1, 0x27, &originalFrame.sp60,
                                                                 &originalFrame.sp70);
            if (temporaryWord9 == 0) {
                goto block_34;
            }
            Level14_810B4Field(temporaryWord9, signed char*, 0xA) =
                Level14_810B4RandBetweenView1(8, 0x10);
        block_34:
            Level14_810B4Field(privateRecord19, int*, 0x28) = 3;
        block_35:
            if (!(Level14_810B4Call35A80View1(ownerThenNodeOffsetOrVector17,
                                              Level14_810B4Field(privateRecord19, void**, 0x34),
                                              0x78, 0x64, 0, 4, 0x20, 0) &
                  2)) {
                goto returnOriginal1541;
            }
            temporaryWord10 =
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), void**, 0xC);
            temporaryWord3 = Level14_810B4Field(temporaryWord10, int*, 0x10);
            rawWord2 = Level14_810B4PlanarHeadingLookupView1(
                temporaryWord3 - Level14_810B4Field(temporaryWord10, int*, 0),
                Level14_810B4Field(temporaryWord10, int*, 20) -
                    Level14_810B4Field(temporaryWord10, int*, 4),
                0);
            rawWord3 = Level14_810B4Field(privateRecord19, int*, 48);
            argumentWord4 = (int)ownerThenNodeOffsetOrVector17 + 12;
            argumentWord5 = Level14_810B4Field(rawWord3, int*, 12);
            retainedHeadingCounterRecordOrVector16 = rawWord2;
            Level14_810B4CopyVectorView1(argumentWord4, argumentWord5);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x46) =
                retainedHeadingCounterRecordOrVector16;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0U;
            Level14_810B4RequestMobyAnimationView1(ownerThenNodeOffsetOrVector17, 0);
            Level14_810B4RefreshMobySpatialGridAndBasisView1(ownerThenNodeOffsetOrVector17, 7);
            return;
        case 0x15:
            Level14_810B4Field(Level14_810B4Field(ownerThenNodeOffsetOrVector17, void**, 0),
                               signed char*, 5) = 2;
            rawWord2 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            __asm__ volatile("" ::: "$16", "memory");
            retainedHeadingCounterRecordOrVector16 = (int)&originalFrame.sp70;
            rawWord2 *= 2;
            rawWord3 = Level14_810B4Field((int)&Level14_810B4Data65920View1, short*, rawWord2);
            argumentWord4 = retainedHeadingCounterRecordOrVector16;
            rawWord2 = (rawWord3 * 13) >> 5;
            originalFrame.sp70 = rawWord2;
            __asm__ volatile("" ::"m"(originalFrame.sp70) : "memory");
            rawWord2 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = retainedHeadingCounterRecordOrVector16;
            rawWord2 *= 2;
            rawWord3 = Level14_810B4Field((int)&Level14_810B4Data658A0View1, short*, rawWord2);
            __asm__ volatile("" ::: "$2", "memory");
            rawWord2 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x44);
            argumentWord6 = (int)ownerThenNodeOffsetOrVector17 + 12;
            Level14_810B4Field(&originalFrame.sp78, volatile int*, 0) = 0;
            originalFrame.sp78 = rawWord2;
            rawWord2 = (rawWord3 * 13) >> 5;
            originalFrame.sp74 = rawWord2;
            Level14_810B4AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            Level14_810B4Call13D44View1(
                &originalFrame.sp70,
                (Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x46) + 0x80) &
                    0xFF,
                0, 0x29);
            rawWord2 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x280);
            if (rawWord2 >= 0) {
                rawWord2 = 22;
                goto writeOriginalState1540;
            }
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x280) = 0;
            rawWord2 = 22;
            goto writeOriginalState1540;
        case 0x16:
            if (Level14_810B4Call37BBCView1(ownerThenNodeOffsetOrVector17, 0) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Call512E4View1(ownerThenNodeOffsetOrVector17, 0, 1);
            rawWord2 = 0x17;
            goto writeOriginalState1540;
        case 0x17:
            if (Level14_810B4Data6E344View1 == 1) {
                goto returnOriginal1541;
            }
            Level14_810B4RequestMobyAnimationView1(ownerThenNodeOffsetOrVector17, 0);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x18U;
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0xC8;
            temporaryWord1 =
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x34), void**, 0xC);
            Level14_810B4Call13AE4View1(temporaryWord1, temporaryWord1 + 0x10);
            return;
        case 0x18:
            MATCHING_KEEP(privateRecord19);
            argumentWord4 = privateRecord19 + 40;
            if (Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) != 0) {
                goto testOriginalTimer458;
            }
            if (Level14_810B4Data6E048View1 != 2) {
                goto returnOriginal1541;
            }
            Level14_810B4Call3BB10View1(ownerThenNodeOffsetOrVector17, 7, 0);
            Level14_810B4Call21ED8View1(4, 0xFC, 0);
            Level14_810B4Call21ED8View1(5, 0xFC, 0);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) = 1U;
            MATCHING_KEEP(privateRecord19);
            argumentWord4 = privateRecord19 + 40;
        testOriginalTimer458:
            if (Level14_810B4CountTimerDownView1(argumentWord4, 4) == 0) {
                goto returnOriginal1541;
            }
            if (Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) != 1) {
                goto block_51;
            }
            Level14_810B4Call13B7CView1(1);
            Level14_810B4Field(Level14_810B4Field(ownerThenNodeOffsetOrVector17, void**, 0),
                               signed char*, 5) = 2;
            rawWord2 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            __asm__ volatile("" ::: "$16", "memory");
            retainedHeadingCounterRecordOrVector16 = (int)&originalFrame.sp80;
            rawWord2 *= 2;
            rawWord3 = Level14_810B4Field((int)&Level14_810B4Data65920View1, short*, rawWord2);
            argumentWord4 = retainedHeadingCounterRecordOrVector16;
            rawWord2 = (rawWord3 * 13) >> 5;
            originalFrame.sp80 = rawWord2;
            __asm__ volatile("" ::"m"(originalFrame.sp80) : "memory");
            rawWord2 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = retainedHeadingCounterRecordOrVector16;
            rawWord2 *= 2;
            rawWord3 = Level14_810B4Field((int)&Level14_810B4Data658A0View1, short*, rawWord2);
            __asm__ volatile("" ::: "$2", "memory");
            rawWord2 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x44);
            argumentWord6 = (int)ownerThenNodeOffsetOrVector17 + 12;
            Level14_810B4Field(&originalFrame.sp88, volatile int*, 0) = 0;
            originalFrame.sp88 = rawWord2;
            rawWord2 = (rawWord3 * 13) >> 5;
            originalFrame.sp84 = rawWord2;
            Level14_810B4AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            Level14_810B4Call13D44View1(
                &originalFrame.sp80,
                (Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x46) + 0x80) &
                    0xFF,
                0, 0x29);
            if (Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x280) >= 0) {
                goto block_50;
            }
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x280) = 0;
        block_50:
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) = 2U;
            Level14_810B4Data6C7B4View1 |= 1;
        block_51:
            if (Level14_810B4Call37BBCView1(ownerThenNodeOffsetOrVector17, 0) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Call512E4View1(ownerThenNodeOffsetOrVector17, 0, 1);
            rawWord2 = 0x19;
            goto writeOriginalState1540;
        case 0x19:
            if (Level14_810B4Data6E344View1 == 1) {
                goto returnOriginal1541;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x36U;
            Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 2) = 0;
            Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 0xA) = 1;
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0x3C;
            return;
        case 0x36:
            if (({
                    MATCHING_KEEP(privateRecord19);
                    Level14_810B4CountTimerDownView1(privateRecord19 + 40, 4);
                }) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0x18;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x34U;
            Level14_810B4RequestMobyAnimationView1(ownerThenNodeOffsetOrVector17, 3);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x40) = 0xF0;
            return;
        case 0x34:
            if (Level14_810B4Field(privateRecord19, int*, 0x28) == 0) {
                goto block_59;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) =
                (int)(Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) + 0x19);
            Level14_810B4Field(privateRecord19, int*, 0x28) =
                (int)(Level14_810B4Field(privateRecord19, int*, 0x28) - 1);
        block_59:
            rawWord2 = 0x35;
            goto writeOriginalState1540;
        case 0x35:
            argumentWord6 = 0;
            if (Level14_810B4Field(privateRecord19, int*, 0x28) == 0) {
                goto readOriginalNode588;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) =
                (int)(Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) + 0x19);
            Level14_810B4Field(privateRecord19, int*, 0x28) =
                (int)(Level14_810B4Field(privateRecord19, int*, 0x28) - 1);
        readOriginalNode588:
            rawWord3 = Level14_810B4Field(privateRecord19, int*, 48);
            argumentWord4 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 12);
            argumentWord5 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 16);
            rawWord2 = Level14_810B4Field(rawWord3, short*, 2);
            rawWord3 = Level14_810B4Field(rawWord3, int*, 12);
            rawWord2 *= 16;
            rawWord2 += rawWord3;
            rawWord3 = Level14_810B4Field(rawWord2, int*, 0);
            rawWord2 = Level14_810B4Field(rawWord2, int*, 4);
            argumentWord4 = rawWord3 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level14_810B4PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 = Level14_810B4AbsoluteByteAngleDeltaView1(
                Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70), rawWord2);
            argumentWord7 = 50;
            if (rawWord2 >= 4)
                goto callOriginalMovement607;
            argumentWord7 = 100;
        callOriginalMovement607:
            temporaryWord16 =
                Level14_810B4Call35A80View1(ownerThenNodeOffsetOrVector17,
                                            Level14_810B4Field(privateRecord19, int*, 48), 120,
                                            argumentWord7, 0, 4, 32, 0) &
                2;
        block_65:
            if (temporaryWord16 == 0) {
                goto returnOriginal1541;
            }
        block_66:
            Level14_810B4DeleteMobyView1(ownerThenNodeOffsetOrVector17);
            return;
        case 0x1F:
            retainedHeadingCounterRecordOrVector16 =
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x34), void**, 0xC);
            Level14_810B4CopyVectorView1(ownerThenNodeOffsetOrVector17 + 0xC,
                                         retainedHeadingCounterRecordOrVector16);
            temporaryWord11 =
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x34), void**, 0xC);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x46) =
                Level14_810B4PlanarHeadingLookupView1(
                    Level14_810B4Field(temporaryWord11, int*, 0x10) -
                        Level14_810B4Field(retainedHeadingCounterRecordOrVector16, int*, 0),
                    Level14_810B4Field(temporaryWord11, int*, 0x14) -
                        Level14_810B4Field(retainedHeadingCounterRecordOrVector16, int*, 4),
                    0);
            Level14_810B4SetMobyAnimationView1(ownerThenNodeOffsetOrVector17, 5);
            rawWord2 = Level14_810B4RandBetweenView1(
                0, Level14_810B4Field(
                       Level14_810B4Field(
                           Level14_810B4Field(
                               (int)&Level14_810B4Data6EE2CView1, int*,
                               Level14_810B4Field(ownerThenNodeOffsetOrVector17, short*, 54) * 4),
                           int*, 0x50),
                       unsigned char*, 0) -
                       2);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 62) = rawWord2;
            rawWord2++;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 63) = rawWord2;
            rawWord2 = 0x20;
            goto writeOriginalState1540;
        case 0x20:
            if (!(Level14_810B4Call35A80View1(ownerThenNodeOffsetOrVector17,
                                              Level14_810B4Field(privateRecord19, void**, 0x34),
                                              0x78, 0x64, 0, 4, 0x20, 0) &
                  2)) {
                goto returnOriginal1541;
            }
            if (Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) != 3) {
                goto block_73;
            }
            temporaryWord12 =
                Level14_810B4ProbeGroundFromRaisedMobyView1(ownerThenNodeOffsetOrVector17);
            if (temporaryWord12 == 0) {
                goto block_72;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0x14) = temporaryWord12;
        block_72:
            Level14_810B4SetMobyAnimationView1(ownerThenNodeOffsetOrVector17, 0);
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0x3C;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) = 0U;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x22U;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x46) =
                (unsigned char)(Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*,
                                                   0x46) +
                                0x80);
            return;
        block_73:
            Level14_810B4SetMobyAnimationView1(ownerThenNodeOffsetOrVector17, 3);
            temporaryWord13 = Level14_810B4RandBetweenView1(
                0, Level14_810B4Field(
                       Level14_810B4Field(
                           Level14_810B4Field(
                               (int)&Level14_810B4Data6EE2CView1, int*,
                               Level14_810B4Field(ownerThenNodeOffsetOrVector17, short*, 54) * 4),
                           int*, 0x48),
                       unsigned char*, 0) -
                       2);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 0x3E) = temporaryWord13;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 0x3F) =
                (signed char)(temporaryWord13 + 1);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x21U;
            Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x34), short*, 0xA) = -1;
            temporaryWord15 = Level14_810B4Field(privateRecord19, void**, 0x34);
            Level14_810B4Field(temporaryWord15, short*, 2) =
                (short)(Level14_810B4Field(temporaryWord15, unsigned short*, 0) - 1);
            return;
        case 0x30:
            Level14_810B4Field(privateRecord19, unsigned char*, 2) = 3U;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x2DU;
            rawWord2 = Level14_810B4Call21F3CView1(8);
            rawWord3 = rawWord2 >> 8;
            rawWord2 &= 15;
            if (!rawWord2) {
                goto updateOriginalPlayerHeight741;
            }
            argumentWord4 = 8;
            if (rawWord3 & 255) {
                goto updateOriginalPlayerHeight741;
            }
            Level14_810B4Call21ED8View1(argumentWord4, 252, 0);
        updateOriginalPlayerHeight741:
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 8) =
                (int)(Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 8) + 0x800);
            argumentWord4 = (int)ownerThenNodeOffsetOrVector17;
            if ((unsigned char)Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*,
                                                  0x49) >= 0xAU) {
                goto testOriginalOwnerState772;
            }
            if (Level14_810B4Data6C65CView1 == 0) {
                goto block_80;
            }
            Level14_810B4Field(Level14_810B4Data6C65CView1, signed char*, 0x4C) = 0x10;
        block_80:
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x49) = 0xAU;
            retainedHeadingCounterRecordOrVector16 = ownerThenNodeOffsetOrVector17 + 0x49;
            Level14_810B4Call3B7B4View1(retainedHeadingCounterRecordOrVector16, 1,
                                        (int)&Level14_810B4Data6D088View1);
            Level14_810B4Call3B7B4View1(retainedHeadingCounterRecordOrVector16, 1,
                                        (int)&Level14_810B4Data6C7F8View1);
        case 0x2D:
            argumentWord4 = (int)ownerThenNodeOffsetOrVector17;
        testOriginalOwnerState772:
            rawWord2 = Level14_810B4Call37BBCView1(argumentWord4, 0);
            retainedHeadingCounterRecordOrVector16 = (int)ownerThenNodeOffsetOrVector17 + 72;
            if (rawWord2 == 0) {
                goto block_84;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x30U;
            Level14_810B4Call3B7B4View1(retainedHeadingCounterRecordOrVector16, 1,
                                        (int)&Level14_810B4Data6D088View1);
            Level14_810B4Call3B7B4View1(retainedHeadingCounterRecordOrVector16, 1,
                                        (int)&Level14_810B4Data6C7F8View1);
            Level14_810B4Call512E4View1(ownerThenNodeOffsetOrVector17, 0, 1);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x2EU;
        block_84:
            retainedPackedFlagsNodeIndexOrTable21 = Level14_810B4Call21F3CView1(8);
            rawWord2 = retainedPackedFlagsNodeIndexOrTable21 >> 8;
            retainedPackedHighByte22 = rawWord2 & 255;
            MATCHING_OBSERVE_VOLATILE(rawWord2);
            rawWord2 = retainedPackedFlagsNodeIndexOrTable21 & 15;
            retainedCounterBoundOrMatrix18 = 0;
            if (!rawWord2) {
                goto prepareOriginalParticleLoop804;
            }
            if (retainedPackedHighByte22 == 0) {
                goto readOriginalPlayer850;
            }
        prepareOriginalParticleLoop804:
            retainedMatrixPlayerTableOrDistance20 = (int)&originalFrame.sp90;
            retainedHeadingCounterRecordOrVector16 = (int)&originalFrame.spA8;
            argumentWord4 = 0;
        emitOriginalParticle807:
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, 255);
            argumentWord4 = 0;
            argumentWord5 = 1024;
            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
            retainedCounterBoundOrMatrix18++;
            Level14_810B4Field(&originalFrame.spB8, signed char*, 0) = rawWord2;
            Level14_810B4Field(&originalFrame.spB8, signed char*, 1) = 0;
            rawWord3 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            rawWord2 = 4096;
            originalFrame.spA8 = rawWord2;
            Level14_810B4Field(&originalFrame.spB8, unsigned char*, 2) = rawWord3;
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, argumentWord5);
            argumentWord4 = (int)&originalFrame.spB8;
            argumentWord5 = retainedMatrixPlayerTableOrDistance20;
            argumentWord6 = 0;
            MATCHING_OBSERVE3_VOLATILE(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 += 3584;
            originalFrame.spAC = rawWord2;
            originalFrame.spB0 = 0;
            Level14_810B4BuildPackedAngleBasisMatrixView1(argumentWord4, argumentWord5,
                                                          argumentWord6);
            Level14_810B4TransformVectorByBasisView1(retainedMatrixPlayerTableOrDistance20,
                                                     retainedHeadingCounterRecordOrVector16,
                                                     retainedHeadingCounterRecordOrVector16);
            Level14_810B4AddVectorView1(retainedHeadingCounterRecordOrVector16,
                                        (int)ownerThenNodeOffsetOrVector17 + 12,
                                        retainedHeadingCounterRecordOrVector16);
            argumentWord4 = 1;
            argumentWord5 = 62;
            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
            argumentWord6 = retainedHeadingCounterRecordOrVector16;
            rawWord2 = originalFrame.spB0;
            rawWord3 = (int)Level14_810B4DataSpawnParticleView1;
            rawWord2 += 4096;
            originalFrame.spB0 = rawWord2;
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            argumentWord7 = (int)&originalFrame.sp80;
            Level14_810B4Field(&originalFrame.sp84, short*, 0) = 0;
            Level14_810B4Field(&originalFrame.sp84, short*, 2) = 0;
            originalFrame.sp80 = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            argumentWord4 = 0;
            if (retainedCounterBoundOrMatrix18 <= 0) {
                goto emitOriginalParticle807;
            }
        readOriginalPlayer850:
            argumentWord6 = 0;
            MATCHING_OBSERVE_VOLATILE(argumentWord6);
            retainedMatrixPlayerTableOrDistance20 = (int)&Level14_810B4Data70328View1;
            rawWord3 = Level14_810B4Field(privateRecord19, int*, 44);
            argumentWord4 = Level14_810B4Field(retainedMatrixPlayerTableOrDistance20, int*, 0);
            argumentWord5 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 4);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level14_810B4Data6C550View1;
            retainedHeadingCounterRecordOrVector16 = rawWord3 + rawWord2;
            rawWord3 = Level14_810B4Field(retainedHeadingCounterRecordOrVector16, int*, 12);
            rawWord2 = Level14_810B4Field(retainedHeadingCounterRecordOrVector16, int*, 16);
            argumentWord4 = rawWord3 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level14_810B4PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord4 = rawWord2;
            rawWord2 = retainedPackedFlagsNodeIndexOrTable21 & 15;
            if (!rawWord2) {
                goto returnOriginal1541;
            }
            if (retainedPackedHighByte22 == 0) {
                goto returnOriginal1541;
            }
            if (Level14_810B4AbsoluteByteAngleDeltaView1(
                    argumentWord4, Level14_810B4Field(retainedHeadingCounterRecordOrVector16,
                                                      unsigned char*, 0x46)) < 0x41) {
                goto returnOriginal1541;
            }
            originalFrame.spC0 =
                (int)(Level14_810B4Field((int)&Level14_810B4Data65920View1, short*,
                                         (Level14_810B4Field(retainedHeadingCounterRecordOrVector16,
                                                             unsigned char*, 0x46) *
                                          2)) *
                      0x7D) >>
                8;
            originalFrame.spC4 =
                (int)(Level14_810B4Field((int)&Level14_810B4Data658A0View1, short*,
                                         (Level14_810B4Field(retainedHeadingCounterRecordOrVector16,
                                                             unsigned char*, 0x46) *
                                          2)) *
                      0x7D) >>
                8;
            originalFrame.spC8 = 0;
            Level14_810B4AddVectorView1(&originalFrame.spC0,
                                        retainedHeadingCounterRecordOrVector16 + 0xC,
                                        &originalFrame.spC0);
            if (Level14_810B4Call13E38View1((int)&Level14_810B4Data6E020View1,
                                            (int)&Level14_810B4Data70328View1, 0) == 0) {
                goto returnOriginal1541;
            }
            if (Level14_810B4Call13E38View1((int)&Level14_810B4Data6E020View1, &originalFrame.spC0,
                                            0) == 0) {
                goto returnOriginal1541;
            }
            if (Level14_810B4Call13E38View1((int)&Level14_810B4Data70328View1, &originalFrame.spC0,
                                            0) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Call13ACCView1(
                Level14_810B4Data6C550View1 +
                    (Level14_810B4Field(privateRecord19, int*, 0x2C) * 0x58),
                0xD);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x4A) = 0xFF;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x2FU;
            Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 2) = 0;
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0x2D;
            return;
        case 0x2E:
            if (Level14_810B4Data6E344View1 == 1) {
                goto returnOriginal1541;
            }
            rawWord3 = Level14_810B4Field(privateRecord19, unsigned char*, 2);
            if (rawWord3 == 2)
                goto writeOriginalState30;
            rawWord2 = Level14_810B4Call21F3CView1(8);
            rawWord3 = rawWord2 >> 8;
            rawWord2 &= 15;
            retainedHeadingCounterRecordOrVector16 = rawWord3 & 255;
            if (!rawWord2) {
                goto resetOriginalParticleCounter972;
            }
            retainedCounterBoundOrMatrix18 = 0;
            if (retainedHeadingCounterRecordOrVector16 != 0) {
                goto prepareOriginalParticleLoop973;
            }
            MATCHING_KEEP_VOLATILE(retainedHeadingCounterRecordOrVector16);
            MATCHING_BARRIER_VOLATILE("$6");
            argumentWord6 = 0;
            Level14_810B4Call21ED8View1(8, 252, argumentWord6);
            if (retainedHeadingCounterRecordOrVector16 == 0) {
                goto readOriginalPlayer1019;
            }
        resetOriginalParticleCounter972:
            retainedCounterBoundOrMatrix18 = 0;
        prepareOriginalParticleLoop973:
            retainedMatrixPlayerTableOrDistance20 = (int)&originalFrame.spD0;
            retainedHeadingCounterRecordOrVector16 = (int)&originalFrame.spE8;
        emitOriginalParticle975:
            argumentWord4 = 0;
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, 255);
            argumentWord4 = 0;
            argumentWord5 = 1024;
            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
            retainedCounterBoundOrMatrix18++;
            Level14_810B4Field(&originalFrame.spB8, signed char*, 0) = rawWord2;
            Level14_810B4Field(&originalFrame.spB8, signed char*, 1) = 0;
            rawWord3 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            rawWord2 = 4096;
            originalFrame.spE8 = rawWord2;
            Level14_810B4Field(&originalFrame.spB8, unsigned char*, 2) = rawWord3;
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, argumentWord5);
            argumentWord4 = (int)&originalFrame.spB8;
            argumentWord5 = retainedMatrixPlayerTableOrDistance20;
            argumentWord6 = 0;
            MATCHING_OBSERVE3_VOLATILE(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 += 3584;
            originalFrame.spEC = rawWord2;
            originalFrame.spF0 = 0;
            Level14_810B4BuildPackedAngleBasisMatrixView1(argumentWord4, argumentWord5,
                                                          argumentWord6);
            Level14_810B4TransformVectorByBasisView1(retainedMatrixPlayerTableOrDistance20,
                                                     retainedHeadingCounterRecordOrVector16,
                                                     retainedHeadingCounterRecordOrVector16);
            Level14_810B4AddVectorView1(retainedHeadingCounterRecordOrVector16,
                                        (int)ownerThenNodeOffsetOrVector17 + 12,
                                        retainedHeadingCounterRecordOrVector16);
            argumentWord4 = 1;
            argumentWord5 = 62;
            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
            argumentWord6 = retainedHeadingCounterRecordOrVector16;
            rawWord2 = originalFrame.spF0;
            rawWord3 = (int)Level14_810B4DataSpawnParticleView1;
            rawWord2 += 4096;
            originalFrame.spF0 = rawWord2;
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            argumentWord7 = (int)&originalFrame.sp80;
            Level14_810B4Field(&originalFrame.sp84, short*, 0) = 0;
            Level14_810B4Field(&originalFrame.sp84, short*, 2) = 0;
            originalFrame.sp80 = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if (retainedCounterBoundOrMatrix18 <= 0) {
                goto emitOriginalParticle975;
            }
        readOriginalPlayer1019:
            argumentWord6 = 0;
            MATCHING_OBSERVE_VOLATILE(argumentWord6);
            retainedMatrixPlayerTableOrDistance20 = (int)&Level14_810B4Data70328View1;
            rawWord3 = Level14_810B4Field(privateRecord19, int*, 44);
            argumentWord4 = Level14_810B4Field(retainedMatrixPlayerTableOrDistance20, int*, 0);
            argumentWord5 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 4);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level14_810B4Data6C550View1;
            retainedHeadingCounterRecordOrVector16 = rawWord3 + rawWord2;
            rawWord3 = Level14_810B4Field(retainedHeadingCounterRecordOrVector16, int*, 12);
            rawWord2 = Level14_810B4Field(retainedHeadingCounterRecordOrVector16, int*, 16);
            argumentWord4 = rawWord3 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level14_810B4PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            if (Level14_810B4AbsoluteByteAngleDeltaView1(
                    rawWord2, Level14_810B4Field(retainedHeadingCounterRecordOrVector16,
                                                 unsigned char*, 70)) < 65) {
                goto returnOriginal1541;
            }
            originalFrame.spF8 =
                (int)(Level14_810B4Field((int)&Level14_810B4Data65920View1, short*,
                                         (Level14_810B4Field(retainedHeadingCounterRecordOrVector16,
                                                             unsigned char*, 0x46) *
                                          2)) *
                      0x7D) >>
                8;
            originalFrame.spFC =
                (int)(Level14_810B4Field((int)&Level14_810B4Data658A0View1, short*,
                                         (Level14_810B4Field(retainedHeadingCounterRecordOrVector16,
                                                             unsigned char*, 0x46) *
                                          2)) *
                      0x7D) >>
                8;
            originalFrame.sp100 = 0;
            Level14_810B4AddVectorView1(&originalFrame.spF8,
                                        retainedHeadingCounterRecordOrVector16 + 0xC,
                                        &originalFrame.spF8);
            if (Level14_810B4Call13E38View1((int)&Level14_810B4Data6E020View1,
                                            (int)&Level14_810B4Data70328View1, 0) == 0) {
                goto returnOriginal1541;
            }
            if (Level14_810B4Call13E38View1((int)&Level14_810B4Data6E020View1, &originalFrame.spF8,
                                            0) == 0) {
                goto returnOriginal1541;
            }
            if (Level14_810B4Call13E38View1((int)&Level14_810B4Data70328View1, &originalFrame.spF8,
                                            0) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Call13ACCView1(
                Level14_810B4Data6C550View1 +
                    (Level14_810B4Field(privateRecord19, int*, 0x2C) * 0x58),
                0xD);
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x4A) = 0xFF;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x2FU;
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0x2D;
            Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 2) = 0;
            return;
        case 0x2F:
            retainedMatrixPlayerTableOrDistance20 = 0x186A0;
            retainedPackedFlagsNodeIndexOrTable21 = -1;
            if (({
                    MATCHING_KEEP(privateRecord19);
                    Level14_810B4CountTimerDownView1(privateRecord19 + 40, 4);
                }) == 0) {
                goto readOriginalSearchNode1125;
            }
            if (Level14_810B4Data6C65CView1 == 0) {
                goto readOriginalSearchNode1125;
            }
            Level14_810B4Field(Level14_810B4Data6C65CView1, signed char*, 0x4C) = 0;
        readOriginalSearchNode1125:
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            retainedHeadingCounterRecordOrVector16 = Level14_810B4Field(rawWord2, short*, 2);
            if (retainedHeadingCounterRecordOrVector16 >= 0)
                goto boundOriginalNodeSearch1132;
            retainedHeadingCounterRecordOrVector16 = 0;
        boundOriginalNodeSearch1132:
            rawWord3 = Level14_810B4Field(rawWord2, short*, 0);
            retainedCounterBoundOrMatrix18 = retainedHeadingCounterRecordOrVector16 + 2;
            rawWord2 = rawWord3 < retainedCounterBoundOrMatrix18;
            if (!rawWord2) {
                rawWord2 = retainedHeadingCounterRecordOrVector16 < retainedCounterBoundOrMatrix18;
                goto branchOriginalNodeSearch1154;
            }
            retainedCounterBoundOrMatrix18 = rawWord3;
            goto testOriginalNodeBound1153;
        searchOriginalNode1139:
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            MATCHING_KEEP(rawWord2);
            argumentWord5 = (int)&Level14_810B4Data70328View1;
            MATCHING_OBSERVE_VOLATILE(argumentWord5);
            rawWord2 = Level14_810B4Field(rawWord2, int*, 12);
            argumentWord4 = retainedHeadingCounterRecordOrVector16 * 16;
            argumentWord4 = rawWord2 + argumentWord4;
            rawWord2 = Level14_810B4ApproximatePlanarDistanceView1(argumentWord4, argumentWord5);
            rawWord3 = rawWord2;
            rawWord2 = rawWord3 < retainedMatrixPlayerTableOrDistance20;
            if (!rawWord2)
                goto advanceOriginalNode1152;
            retainedMatrixPlayerTableOrDistance20 = rawWord3;
            retainedPackedFlagsNodeIndexOrTable21 = retainedHeadingCounterRecordOrVector16;
        advanceOriginalNode1152:
            retainedHeadingCounterRecordOrVector16++;
        testOriginalNodeBound1153:
            rawWord2 = retainedHeadingCounterRecordOrVector16 < retainedCounterBoundOrMatrix18;
        branchOriginalNodeSearch1154:
            if (rawWord2)
                goto searchOriginalNode1139;
            if (retainedPackedFlagsNodeIndexOrTable21 < 0) {
                goto block_122;
            }
            Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 2) =
                retainedPackedFlagsNodeIndexOrTable21;
            goto block_123;
        block_122:
            retainedPackedFlagsNodeIndexOrTable21 =
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 2);
        block_123:
            if ((retainedPackedFlagsNodeIndexOrTable21 + 1) <
                Level14_810B4Field(Level14_810B4Field(privateRecord19, void**, 0x30), short*, 0)) {
                goto prepareOriginalPlayerTransition1176;
            }
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x33U;
            Level14_810B4Field(privateRecord19, int*, 0x28) = 0x21;
            return;
        prepareOriginalPlayerTransition1176:
            argumentWord6 = (int)&Level14_810B4Data70328View1 + 0x23C;
            rawWord2 = Level14_810B4Field(argumentWord6, int*, 0);
            if (rawWord2 == 57)
                goto returnOriginal1541;
            rawWord2 = Level14_810B4Data70328View2;
            if (rawWord2 == 57)
                goto returnOriginal1541;
            argumentWord5 = 0x10000088;
            argumentWord4 = (int)&originalFrame.sp80;
            MATCHING_OBSERVE_VOLATILE(argumentWord4);
            rawWord2 = Level14_810B4Data70328View3;
            rawWord3 = 42;
            Level14_810B4Field(argumentWord6, int*, 0) = rawWord3;
            rawWord2 |= argumentWord5;
            Level14_810B4Data70328View3 = rawWord2;
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            argumentWord6 = retainedPackedFlagsNodeIndexOrTable21 * 16;
            rawWord2 = Level14_810B4Field(rawWord2, int*, 12);
            argumentWord5 = argumentWord6 + 16;
            argumentWord5 = rawWord2 + argumentWord5;
            argumentWord6 = rawWord2 + argumentWord6;
            Level14_810B4SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6);
            temporaryWord5 = Level14_810B4AbsoluteByteAngleDeltaView1(
                Level14_810B4PlanarHeadingLookupView1(originalFrame.sp80, (int)originalFrame.sp84,
                                                      0),
                Level14_810B4Field((int)&Level14_810B4Data70328View1, unsigned char*, 0xE));
            retainedHeadingCounterRecordOrVector16 = 0;
            if (temporaryWord5 >= 0x20) {
                goto block_129;
            }
            retainedCounterBoundOrMatrix18 =
                Level14_810B4Field(&originalFrame.sp20, int*, Level14_810B4Data6C7C4View1 * 4);
            goto block_133;
        block_129:
            retainedHeadingCounterRecordOrVector16 = 0xC8;
            if (temporaryWord5 >= 0x40) {
                goto block_131;
            }
            retainedCounterBoundOrMatrix18 = 0xC8;
            goto block_132;
        block_131:
            retainedHeadingCounterRecordOrVector16 = 0x190;
            retainedCounterBoundOrMatrix18 = 0;
        block_132:
        block_133:
            Level14_810B4ScaleVectorRatioQ15View1(
                (int*)&originalFrame.sp80,
                Level14_810B4MeasureVectorLengthView1((int*)&originalFrame.sp80, 1),
                retainedHeadingCounterRecordOrVector16);
            Level14_810B4Field(&originalFrame.spB8, signed char*, 0) = 0;
            Level14_810B4Field(&originalFrame.spB8, signed char*, 1) = 0;
            Level14_810B4Field(&originalFrame.spB8, unsigned char*, 2) =
                Level14_810B4Field((int)&Level14_810B4Data70328View1, unsigned char*, 0xE);
            Level14_810B4BuildPackedAngleBasisMatrixView1(
                &Level14_810B4Field(&originalFrame.spB8, signed char*, 0), &originalFrame.sp108, 0);
            originalFrame.spD0 = retainedCounterBoundOrMatrix18;
            originalFrame.spD4 = 0;
            originalFrame.spD8 = 0;
            Level14_810B4TransformVectorByBasisView1(&originalFrame.sp108, &originalFrame.spD0,
                                                     &originalFrame.spD0);
            Level14_810B4AddVectorView1((int*)&originalFrame.sp80, &originalFrame.spD0,
                                        (int*)&originalFrame.sp80);
            argumentWord4 = (int)&originalFrame.sp120;
            MATCHING_OBSERVE_VOLATILE(argumentWord4);
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            MATCHING_KEEP(rawWord2);
            ownerThenNodeOffsetOrVector17 = (void*)(retainedPackedFlagsNodeIndexOrTable21 * 16);
            argumentWord6 = Level14_810B4Field(rawWord2, int*, 12);
            MATCHING_KEEP(argumentWord6);
            argumentWord5 = (int)ownerThenNodeOffsetOrVector17 + 16;
            argumentWord5 = argumentWord6 + argumentWord5;
            argumentWord6 = argumentWord6 + (int)ownerThenNodeOffsetOrVector17;
            Level14_810B4SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6);
            temporaryWord6 =
                Level14_810B4PlanarHeadingLookupView1(originalFrame.sp120, originalFrame.sp124, 0);
            temporaryWord7 = Level14_810B4AbsoluteByteAngleDeltaView1(
                temporaryWord6,
                Level14_810B4Field((int)&Level14_810B4Data70328View1, unsigned char*, 0xE));
            if (temporaryWord7 < 0x11) {
                goto writeOriginalPlayerVector1293;
            }
            temporaryWord2 = (temporaryWord7 - 0x10) * 3;
            Level14_810B4Field((int)&Level14_810B4Data70328View1, signed char*, 0x22A) =
                (signed char)(Level14_810B4ApproachByteAngleView1(
                                  temporaryWord6,
                                  Level14_810B4Field((int)&Level14_810B4Data70328View1,
                                                     unsigned char*, 0xE),
                                  temporaryWord2, (temporaryWord2 >> 1) + 1) -
                              Level14_810B4Field((int)&Level14_810B4Data70328View1, unsigned char*,
                                                 0xE));
        writeOriginalPlayerVector1293:
            rawWord2 = originalFrame.sp80;
            rawWord3 = originalFrame.sp84;
            argumentWord5 = originalFrame.sp88;
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x21C) = rawWord2;
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x220) = rawWord3;
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x224) = argumentWord5;
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            rawWord2 = Level14_810B4Field(rawWord2, int*, 12);
            rawWord2 = (int)ownerThenNodeOffsetOrVector17 + rawWord2;
            rawWord2 = Level14_810B4Field(rawWord2, int*, 8);
            argumentWord4 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 8);
            rawWord3 = rawWord2 + 0x8D1;
            rawWord2 = argumentWord4 - rawWord3;
            if (rawWord2 >= 0)
                goto testOriginalHeightDifference1315;
            rawWord2 = -rawWord2;
        testOriginalHeightDifference1315:
            if (rawWord2 < 70)
                goto boundOriginalNodeParticle1325;
            rawWord2 = argumentWord4 < rawWord3;
            if (rawWord2) {
                rawWord2 = argumentWord5 + 70;
                goto writeOriginalPlayerHeight1323;
            }
            rawWord2 = rawWord3 < argumentWord4;
            if (!rawWord2) {
                rawWord2 = argumentWord5 - 70;
                goto boundOriginalNodeParticle1325;
            }
            rawWord2 = argumentWord5 - 70;
        writeOriginalPlayerHeight1323:
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x224) = rawWord2;
        boundOriginalNodeParticle1325:
            argumentWord5 = Level14_810B4Field(privateRecord19, int*, 48);
            rawWord2 = Level14_810B4Field(argumentWord5, short*, 2);
            rawWord3 = Level14_810B4Field(argumentWord5, short*, 0);
            retainedPackedFlagsNodeIndexOrTable21 = rawWord2 + 8;
            rawWord2 = retainedPackedFlagsNodeIndexOrTable21 < rawWord3;
            retainedHeadingCounterRecordOrVector16 = 0;
            if (rawWord2)
                goto prepareOriginalNodeParticle1333;
            retainedPackedFlagsNodeIndexOrTable21 = rawWord3 - 1;
        prepareOriginalNodeParticle1333:
            retainedMatrixPlayerTableOrDistance20 = (int)&Level14_810B4Data6E040View1;
            retainedCounterBoundOrMatrix18 = (int)&originalFrame.sp108;
            ownerThenNodeOffsetOrVector17 = (void*)&originalFrame.sp138;
            rawWord3 = Level14_810B4Field(privateRecord19, int*, 44);
            argumentWord4 = Level14_810B4Data6C550View1;
            rawWord2 = rawWord3 * 88;
            argumentWord4 += rawWord2;
            argumentWord4 += 12;
            rawWord2 = Level14_810B4Field(argumentWord5, int*, 12);
            argumentWord5 = retainedPackedFlagsNodeIndexOrTable21 * 16;
            argumentWord5 = rawWord2 + argumentWord5;
            Level14_810B4CopyVectorView1(argumentWord4, argumentWord5);
            argumentWord4 = 0;
        emitOriginalNodeParticle1353:
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, 255);
            argumentWord4 = 0;
            rawWord3 =
                Level14_810B4Field(retainedMatrixPlayerTableOrDistance20, unsigned short*, 0);
            argumentWord5 = 1024;
            Level14_810B4Field(&originalFrame.sp148, signed char*, 0) = rawWord2;
            Level14_810B4Field(&originalFrame.sp148, signed char*, 1) = 0;
            originalFrame.sp138 = 0;
            rawWord3 = (unsigned)rawWord3 >> 4;
            Level14_810B4Field(&originalFrame.sp148, signed char*, 2) = rawWord3;
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, argumentWord5);
            argumentWord4 = (int)&originalFrame.sp148;
            argumentWord5 = retainedCounterBoundOrMatrix18;
            argumentWord6 = 0;
            MATCHING_OBSERVE3_VOLATILE(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 += 1536;
            originalFrame.sp13C = rawWord2;
            originalFrame.sp140 = 0;
            Level14_810B4BuildPackedAngleBasisMatrixView1(argumentWord4, argumentWord5,
                                                          argumentWord6);
            Level14_810B4TransformVectorByBasisView1(retainedCounterBoundOrMatrix18,
                                                     ownerThenNodeOffsetOrVector17,
                                                     ownerThenNodeOffsetOrVector17);
            Level14_810B4AddVectorView1(ownerThenNodeOffsetOrVector17,
                                        retainedMatrixPlayerTableOrDistance20 - 32,
                                        ownerThenNodeOffsetOrVector17);
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            originalFrame.sp130 = rawWord2;
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            rawWord2 = Level14_810B4Field(rawWord2, unsigned short*, 2);
            rawWord2++;
            Level14_810B4Field(&originalFrame.sp134, short*, 0) = rawWord2;
            __asm__ volatile(""
                             : "=r"(rawWord2)
                             : "0"(rawWord2),
                               "m"(Level14_810B4Field(&originalFrame.sp134, short*, 0))
                             : "memory");
            rawWord3 = Level14_810B4Field(privateRecord19, int*, 48);
            rawWord2 = (rawWord2 << 16) >> 16;
            rawWord3 = Level14_810B4Field(rawWord3, short*, 0);
            rawWord2 = rawWord2 < rawWord3;
            argumentWord4 = rawWord3;
            if (rawWord2)
                goto callOriginalNodeParticle1397;
            rawWord2 = argumentWord4 - 1;
            Level14_810B4Field(&originalFrame.sp134, short*, 0) = rawWord2;
        callOriginalNodeParticle1397:
            argumentWord4 = 1;
            argumentWord5 = 62;
            argumentWord6 = (int)ownerThenNodeOffsetOrVector17;
            argumentWord7 = (int)&originalFrame.sp130;
            MATCHING_OBSERVE2_VOLATILE(retainedHeadingCounterRecordOrVector16, argumentWord7);
            rawWord2 = (int)Level14_810B4DataSpawnParticleView1;
            retainedHeadingCounterRecordOrVector16++;
            Level14_810B4Field(&originalFrame.sp134, short*, 2) = 0;
            ((int (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            argumentWord4 = 0;
            if (retainedHeadingCounterRecordOrVector16 < 2)
                goto emitOriginalNodeParticle1353;
            return;
        case 0x33:
            retainedCounterBoundOrMatrix18 = 0;
            retainedPackedFlagsNodeIndexOrTable21 = (int)&Level14_810B4Data6E040View1;
            retainedMatrixPlayerTableOrDistance20 = (int)&originalFrame.sp150;
            retainedHeadingCounterRecordOrVector16 = (int)&originalFrame.sp168;
            argumentWord4 = 0;
        emitOriginalFinalParticle1417:
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, 255);
            argumentWord4 = 0;
            argumentWord5 = 1024;
            rawWord3 =
                Level14_810B4Field(retainedPackedFlagsNodeIndexOrTable21, unsigned short*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(retainedCounterBoundOrMatrix18, "memory");
            retainedCounterBoundOrMatrix18++;
            Level14_810B4Field(&originalFrame.sp148, signed char*, 0) = rawWord2;
            Level14_810B4Field(&originalFrame.sp148, signed char*, 1) = 0;
            originalFrame.sp168 = 0;
            rawWord3 = (unsigned)rawWord3 >> 4;
            Level14_810B4Field(&originalFrame.sp148, signed char*, 2) = rawWord3;
            rawWord2 = Level14_810B4RandBetweenView1(argumentWord4, argumentWord5);
            argumentWord4 = (int)&originalFrame.sp148;
            argumentWord5 = retainedMatrixPlayerTableOrDistance20;
            argumentWord6 = 0;
            MATCHING_OBSERVE3_VOLATILE(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 += 1536;
            originalFrame.sp16C = rawWord2;
            originalFrame.sp170 = 0;
            Level14_810B4BuildPackedAngleBasisMatrixView1(argumentWord4, argumentWord5,
                                                          argumentWord6);
            Level14_810B4TransformVectorByBasisView1(retainedMatrixPlayerTableOrDistance20,
                                                     retainedHeadingCounterRecordOrVector16,
                                                     retainedHeadingCounterRecordOrVector16);
            Level14_810B4AddVectorView1(retainedHeadingCounterRecordOrVector16,
                                        retainedPackedFlagsNodeIndexOrTable21 - 32,
                                        retainedHeadingCounterRecordOrVector16);
            argumentWord4 = 1;
            argumentWord5 = 62;
            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            argumentWord6 = retainedHeadingCounterRecordOrVector16;
            originalFrame.sp130 = rawWord2;
            rawWord2 = Level14_810B4Field(privateRecord19, int*, 48);
            rawWord3 = (int)Level14_810B4DataSpawnParticleView1;
            rawWord2 = Level14_810B4Field(rawWord2, unsigned short*, 0);
            argumentWord7 = (int)&originalFrame.sp130;
            Level14_810B4Field(&originalFrame.sp134, short*, 2) = 0;
            rawWord2--;
            Level14_810B4Field(&originalFrame.sp134, short*, 0) = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            argumentWord4 = 0;
            if (retainedCounterBoundOrMatrix18 < 2)
                goto emitOriginalFinalParticle1417;
            if (({
                    MATCHING_KEEP(privateRecord19);
                    Level14_810B4CountTimerDownView1(privateRecord19 + 40, 4);
                }) == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Data6E160View1 = 0;
            Level14_810B4Data6E164View1 = 0;
            Level14_810B4Call21ED8View1(8, 0xFC, 0);
            argumentWord4 = 2;
            Level14_810B4Field(privateRecord19, unsigned char*, 2) = argumentWord4;
            rawWord2 = Level14_810B4Data6C7B4View1;
            rawWord3 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 0);
            rawWord2 |= 16;
            Level14_810B4Data6C7B4View1 = rawWord2;
            Level14_810B4Field(rawWord3, signed char*, 5) = argumentWord4;
            rawWord2 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            __asm__ volatile("" ::: "$16", "memory");
            retainedHeadingCounterRecordOrVector16 = (int)&originalFrame.sp178;
            rawWord2 *= 2;
            rawWord3 = Level14_810B4Field((int)&Level14_810B4Data65920View1, short*, rawWord2);
            argumentWord5 = retainedHeadingCounterRecordOrVector16;
            rawWord2 = (rawWord3 * 39) >> 6;
            originalFrame.sp178 = rawWord2;
            __asm__ volatile("" ::"m"(originalFrame.sp178) : "memory");
            rawWord2 = Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 70);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = (int)ownerThenNodeOffsetOrVector17 + 12;
            rawWord2 *= 2;
            rawWord3 = Level14_810B4Field((int)&Level14_810B4Data658A0View1, short*, rawWord2);
            __asm__ volatile("" ::: "$2", "memory");
            rawWord2 = Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x44);
            argumentWord4 = retainedHeadingCounterRecordOrVector16;
            Level14_810B4Field(&originalFrame.sp180, volatile int*, 0) = 0;
            originalFrame.sp180 = rawWord2;
            rawWord2 = (rawWord3 * 39) >> 6;
            originalFrame.sp17C = rawWord2;
            Level14_810B4AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            Level14_810B4Call13D44View1(
                &originalFrame.sp178,
                (Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x46) + 0x80) &
                    0xFF,
                0, 0x29);
            if (Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x280) >= 0) {
                goto finishActiveCountdown;
            }
            Level14_810B4Field((int)&Level14_810B4Data70328View1, int*, 0x280) = 0;
        finishActiveCountdown:
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = 0x2DU;
            if (Level14_810B4Data6C65CView1 == 0) {
                goto returnOriginal1541;
            }
            Level14_810B4Field(Level14_810B4Data6C65CView1, signed char*, 0x4C) = 0x10;
            return;
        case 0x31:
            rawWord2 = 0x32;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 0x41) = 0;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 0x4C) = 0;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, signed char*, 0x4D) = 0;
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, int*, 8) = 0;
        writeOriginalState1540:
            Level14_810B4Field(ownerThenNodeOffsetOrVector17, unsigned char*, 0x48) = rawWord2;
        returnOriginal1541:
            return;
        default:
            goto returnOriginal1541;
    }
}
#undef Level14_810B4Field


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level14
 * 800828F4: original277 instructions and45 dispatch words plus padding,
 * sibling4474 and original function assembly. Verified45 pool scan C reused.
 * All raw offsets, state selectors and helper arguments follow original14;
 * meanings, units and cadence unresolved. Every native/linked/hash gate required. */
#define Actor14Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char *Actor14Pool __asm__("D_8006C550"), *Actor14End __asm__("D_8006C704");
extern unsigned char Actor14Player[] __asm__("D_80070328");
extern unsigned char Actor14Table0[] __asm__("D_8006D088"), Actor14Table1[] __asm__("D_8006C7F8");
extern int Actor14Gate __asm__("D_8006E344"), Actor14Index __asm__("D_8006C58C");
extern unsigned char Actor14Entries[] __asm__("D_800716AC");
extern int (*Actor14Indirect)(void*, int, int) __asm__("unk_ovlheader_80074330");
int Actor14DeleteMoby() __asm__("func_80055B18");
int Actor14H36220() __asm__("func_80036220");
int Actor14H37BBC() __asm__("func_80037BBC");
int Actor14H512E4() __asm__("func_800512E4");
int Actor14H3B7B4() __asm__("func_8003B7B4");
void func_level_14_800828F4(void* input) {
    register unsigned char* owner __asm__("$20") = input;
    register unsigned char* tag __asm__("$19") = Actor14Field(owner, unsigned char**, 0);
    register unsigned char* cursor __asm__("$17");
    register unsigned char* statePointer __asm__("$16");
    register int scanClass __asm__("$18");
    register unsigned char* table0 __asm__("$18");
    register unsigned char* table1 __asm__("$17");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register void* call6 __asm__("$6");
    switch (owner[0x48]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 41:
        case 43:
            return;
        case 42:
            work3 = Actor14Field(tag, int*, 0x24);
            work2 = work3 * 11;
            work3 = (int)Actor14Pool;
            work2 <<= 3;
            work3 = work2 + work3;
            if (!(Actor14Field((void*)work3, unsigned char*, 0x48) & 0x80))
                Actor14Field((void*)work3, unsigned char*, 0x48) = 4;
            cursor = Actor14Pool;
            if ((unsigned int)cursor < (unsigned int)Actor14End) {
                scanClass = 532;
                statePointer = cursor + 0x48;
                do {
                    if (Actor14Field(statePointer, short*, -0x12) == scanClass &&
                        !(*statePointer & 0x80))
                        Actor14DeleteMoby(cursor);
                    work2 = (int)Actor14End;
                    __asm__("" : "=r"(work2) : "0"(work2), "r"(cursor));
                    cursor += 88;
                    statePointer += 88;
                } while ((unsigned int)cursor < (unsigned int)work2);
            }
            Actor14DeleteMoby(owner);
            return;
        case 38:
            if (!Actor14H36220(Actor14Player, tag + 0x2C, 0, 1024)) {
                if (!Actor14H37BBC(owner, 0))
                    return;
            }
            Actor14H512E4(owner, 0, 1);
            work2 = 39;
            goto assignState;
        case 44:
            work2 = Actor14Index;
            work3 = work2 * 6;
            call4 = (void*)(int)Actor14Entries[work3 + 3];
            if ((unsigned int)call4 < 255) {
                work2 = (int)call4 + 1;
                Actor14Entries[work3 + 3] = work2;
            }
            work2 = 38;
            goto assignState;
        case 39:
            if (Actor14Gate == 1)
                return;
            work3 = tag[2];
            work2 = 2;
            statePointer = owner + 0x48;
            if (work3 == work2) {
                owner[0x48] = 44;
                Actor14H3B7B4(statePointer, 1, Actor14Table0);
                Actor14H3B7B4(statePointer, 1, Actor14Table1);
                Actor14Field(Actor14Player, int*, 0x214) = 0;
                work3 = Actor14Field(tag, int*, 0x24);
                work2 = work3 * 11;
                work3 = (int)Actor14Pool;
                work2 <<= 3;
                work2 += work3;
                Actor14Field((void*)work2, unsigned char*, 0x48) = 2;
                work2 = 30;
                goto assignState;
            }
            statePointer = tag + 2;
            if (work3 == 3) {
                MATCHING_KEEP(statePointer);
                Actor14Field(Actor14Player, int*, 0x214) = 0;
                work3 = Actor14Field(tag, int*, 0x24);
                work2 = work3 * 11;
                work3 = (int)Actor14Pool;
                work2 <<= 3;
                work2 += work3;
                Actor14Field((void*)work2, unsigned char*, 0x48) = 1;
                tag[2] = 0;
                Actor14H3B7B4(statePointer, 1, Actor14Table0);
                Actor14H3B7B4(statePointer, 1, Actor14Table1);
                work2 = 40;
                goto assignState;
            }
            work3 = tag[4];
            work2 = 4;
            if (work3 != work2) {
                work2 = 30;
                goto assignState;
            }
            work3 = Actor14Field(tag, int*, 0x24);
            work2 = work3 * 11;
            work3 = (int)Actor14Pool;
            work2 <<= 3;
            work2 += work3;
            Actor14Field((void*)work2, unsigned char*, 0x48) = 4;
            work3 = Actor14Field(tag, int*, 0x24);
            work2 = work3 * 11;
            work3 = (int)Actor14Pool;
            work2 <<= 3;
            work2 += work3;
            Actor14Field((void*)work2, unsigned char*, 0x4A) = 255;
            cursor = Actor14Pool;
            if ((unsigned int)cursor < (unsigned int)Actor14End) {
                scanClass = 532;
                statePointer = cursor + 0x48;
                do {
                    if (Actor14Field(statePointer, short*, -0x12) == scanClass &&
                        !(*statePointer & 0x80))
                        Actor14DeleteMoby(cursor);
                    work2 = (int)Actor14End;
                    __asm__("" : "=r"(work2) : "0"(work2), "r"(cursor));
                    cursor += 88;
                    statePointer += 88;
                } while ((unsigned int)cursor < (unsigned int)work2);
            }
            statePointer = owner + 0x48;
            call4 = statePointer;
            arg5 = 1;
            MATCHING_KEEP2(call4, arg5);
            table0 = Actor14Table0;
            owner[0x48] = 42;
            tag[2] = 0;
            Actor14H3B7B4(call4, arg5, table0);
            call4 = statePointer;
            arg5 = 1;
            MATCHING_KEEP2(call4, arg5);
            table1 = Actor14Table1;
            Actor14H3B7B4(call4, arg5, table1);
            statePointer = tag + 2;
            Actor14H3B7B4(statePointer, 1, table0);
            Actor14H3B7B4(statePointer, 1, table1);
            work2 = 30;
            goto assignState;
        case 40:
            work3 = Actor14Field(tag, int*, 0x28);
            call4 = Actor14Pool;
            work2 = work3 * 88;
            call4 = (void*)((int)call4 + work2);
            arg5 = Actor14Field(call4, unsigned char*, 0x46) + 128;
            call4 = (unsigned char*)call4 + 12;
            if (!Actor14Indirect(call4, arg5 & 255, 0))
                return;
            work2 = 38;
        assignState:
            owner[0x48] = work2;
            return;
    }
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Actor14D48func_8001C288() __asm__("func_8001C288");
extern int Actor14D48D_8006C648 __asm__("D_8006C648");
extern void* (*Actor14D48SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int Actor14D48Player20C __asm__("D_80070328 + 0x20C");
extern int Actor14D48Player298 __asm__("D_80070328 + 0x298");
extern int Actor14D48Player21C __asm__("D_80070328 + 0x21C");
extern int Actor14D48Player220 __asm__("D_80070328 + 0x220");
extern int Actor14D48Player224 __asm__("D_80070328 + 0x224");
#define Actor14D48Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor14D48func_80018368() __asm__("func_80018368");
void* Actor14D48func_8001BA30() __asm__("func_8001BA30");
int Actor14D48CountTimerDown() __asm__("func_800359A4");
int Actor14D48SubAngle8() __asm__("func_8003613C");
int Actor14D48PlayMobySoundEvent() __asm__("func_8003BABC");
int Actor14D48PlanarHeadingLookup() __asm__("func_8004E880");
int Actor14D48CopyVector() __asm__("func_8004F178");
int Actor14D48AddVector() __asm__("func_8004F194");
int Actor14D48ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor14D48DeleteMoby() __asm__("func_80055B18");
int Actor14D48rand() __asm__("rand");
extern short Actor14D48D_80065920[] __asm__("D_80065920");
extern short Actor14D48D_800658A0[] __asm__("D_800658A0");
extern int Actor14D48D_8006C550 __asm__("D_8006C550");
extern int (*Actor14D48SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");
void func_level_14_80082D48(void* input) {
    register unsigned char* owner __asm__("$16") = input;
    struct {
        int sp18, pad1C, pad20, pad24;
        int sp28, sp2C, sp30, pad34;
    } frame;
    register int helperMode __asm__("$5");
    register void* call4 __asm__("$4");
    register int work2 __asm__("$2");
    register void* call6 __asm__("$6");
    register void* call5 __asm__("$5");
    register int* ownerPosition __asm__("$17");
    int positionWord14;
    int positionWord10;
    int positionWord0C;
    register int firstTableResult __asm__("$16");
    register int secondTableResult __asm__("$16");
    register int maskedSelector __asm__("$18");
    register int firstFactor __asm__("$19");
    register int secondFactor __asm__("$20");
    register int helperSelector __asm__("$17");
    register int particleIndex __asm__("$23");
    register int firstDifference __asm__("$3");
    register int secondDifference __asm__("$3");
    unsigned char copiedByte;
    unsigned char stateByte;
    register void* state __asm__("$18");
    void* initialTarget;
    void* target;
    void* hitActor;

    MATCHING_KEEP(owner);
    stateByte = Actor14D48Field(owner, unsigned char*, 0x48);
    state = Actor14D48Field(owner, void**, 0);
    switch (stateByte) { /* irregular */
        case 2:
            Actor14D48Field(owner, unsigned char*, 0x46) += Actor14D48D_8006C648 * 4;
            return;
        case 3:
            Actor14D48Field(owner, unsigned char*, 0x41) = 0;
            Actor14D48Field(owner, unsigned char*, 0x4C) = 0;
            Actor14D48Field(owner, unsigned char*, 0x4D) = 0;
            if (Actor14D48CountTimerDown(state + 4, 4)) {
                {
                    register int one __asm__("$2") = 1;
                    register int value32 __asm__("$3") = 32;
                    register int two __asm__("$2");
                    MATCHING_KEEP2(one, value32);
                    Actor14D48Field(owner, volatile unsigned char*, 0x41) = one;
                    Actor14D48Field(owner, volatile unsigned char*, 0x4D) = one;
                    two = 2;
                    MATCHING_KEEP(two);
                    Actor14D48Field(owner, volatile unsigned char*, 0x4C) = value32;
                    Actor14D48Field(owner, unsigned char*, 0x48) = two;
                }
            }
            return;
        case 0:
            if ((Actor14D48Field(owner, int*, 0xC) >= 0x400) &&
                (Actor14D48Field(owner, int*, 0x10) >= 0x400) &&
                (Actor14D48Field(owner, int*, 0x14) >= 0x400)) {
                initialTarget = Actor14D48Field(state, void**, 8);
                if (initialTarget != 0) {
                    if ((unsigned char)Actor14D48Field(initialTarget, unsigned char*, 0x48) >=
                        0x80U) {
                        Actor14D48Field(state, void**, 8) = 0;
                    }
                    target = Actor14D48Field(state, void**, 8);
                    if (target != 0) {
                        firstDifference = Actor14D48SubAngle8(
                            Actor14D48Field(owner, unsigned char*, 0x46),
                            Actor14D48PlanarHeadingLookup(Actor14D48Field(target, int*, 0xC) -
                                                              Actor14D48Field(owner, int*, 0xC),
                                                          Actor14D48Field(target, int*, 0x10) -
                                                              Actor14D48Field(owner, int*, 0x10),
                                                          0));
                        if (firstDifference >= 2) {
                            firstDifference = 1;
                            MATCHING_KEEP(firstDifference);
                        }
                        if (firstDifference < -1)
                            firstDifference = -1;
                        Actor14D48Field(owner, unsigned char*, 0x46) =
                            (unsigned char)(Actor14D48Field(owner, unsigned char*, 0x46) +
                                            firstDifference);
                        secondDifference = Actor14D48SubAngle8(
                            Actor14D48Field(owner, unsigned char*, 0x45),
                            Actor14D48PlanarHeadingLookup(
                                Actor14D48ApproximatePlanarDistance(
                                    owner + 0xC, Actor14D48Field(state, void**, 8) + 0xC),
                                Actor14D48Field(Actor14D48Field(state, void**, 8), int*, 0x14) -
                                    Actor14D48Field(owner, int*, 0x14),
                                0));
                        if (secondDifference >= 2) {
                            secondDifference = 1;
                            MATCHING_KEEP(secondDifference);
                        }
                        if (secondDifference < -1)
                            secondDifference = -1;
                        Actor14D48Field(owner, unsigned char*, 0x45) =
                            (unsigned char)(Actor14D48Field(owner, unsigned char*, 0x45) +
                                            secondDifference);
                    }
                }
                frame.sp28 =
                    (int)(((int)(Actor14D48D_80065920[Actor14D48Field(owner, unsigned char*,
                                                                      0x46)] *
                                 Actor14D48Field(state, int*, 0)) >>
                           0xC) *
                          Actor14D48D_80065920[Actor14D48Field(owner, unsigned char*, 0x45)]) >>
                    0xC;
                frame.sp2C =
                    (int)(((int)(Actor14D48D_800658A0[Actor14D48Field(owner, unsigned char*,
                                                                      0x46)] *
                                 Actor14D48Field(state, int*, 0)) >>
                           0xC) *
                          Actor14D48D_80065920[Actor14D48Field(owner, unsigned char*, 0x45)]) >>
                    0xC;
                call4 = &frame.sp18;
                MATCHING_KEEP(call4);
                ownerPosition = owner + 0xC;
                frame.sp30 =
                    (int)(Actor14D48D_800658A0[Actor14D48Field(owner, unsigned char*, 0x45)] *
                          Actor14D48Field(state, int*, 0)) >>
                    0xC;
                Actor14D48CopyVector(call4, ownerPosition);
                Actor14D48AddVector(ownerPosition, ownerPosition, &frame.sp28);
                positionWord0C = Actor14D48Field(owner, int*, 0xC);
                if (positionWord0C >= 0x400) {
                    positionWord10 = Actor14D48Field(owner, int*, 0x10);
                    if (positionWord10 >= 0x400) {
                        positionWord14 = Actor14D48Field(owner, int*, 0x14);
                        if ((positionWord14 >= 0x400) && (positionWord0C <= 0x3E800) &&
                            (positionWord10 <= 0x3E800) && (positionWord14 <= 0x3E800)) {
                            if (Actor14D48func_80018368(&frame.sp18, ownerPosition,
                                                        positionWord0C) != 0)
                                goto block_30;
                            {
                                {
                                    register unsigned char* hit __asm__("$4") =
                                        Actor14D48func_8001BA30(ownerPosition, 400, 0, 0, 0x30000,
                                                                owner);
                                    if (hit &&
                                        hit != (unsigned char*)(Actor14D48D_8006C550 +
                                                                Actor14D48Field(
                                                                    owner, unsigned char*, 0x3A) *
                                                                    88)) {
                                        copiedByte = Actor14D48Field(owner, unsigned char*, 0x46);
                                        Actor14D48Field(hit, unsigned char*, 0x51) = copiedByte;
                                        if (copiedByte == 0) {
                                            Actor14D48Field(hit, unsigned char*, 0x51) = 1U;
                                        }
                                        goto initializeContact;
                                    }
                                }
                                ownerPosition = owner + 12;
                                if (Actor14D48func_8001C288(ownerPosition, 256, 7)) {
                                    {
                                        register int flags __asm__("$2") = 0x10000000;
                                        register int angle __asm__("$3") =
                                            Actor14D48Field(owner, unsigned char*, 0x46);
                                        MATCHING_KEEP2(flags, angle);
                                        flags |= 1024;
                                        Actor14D48Player20C = flags;
                                        Actor14D48Player298 = angle;
                                    }
                                    MATCHING_BARRIER_VOLATILE("memory");
                                    Actor14D48Player21C = (Actor14D48D_80065920[Actor14D48Field(
                                                               owner, unsigned char*, 0x46)] *
                                                           25) >>
                                                          11;
                                    {
                                        register int sample __asm__("$3") =
                                            Actor14D48D_800658A0[Actor14D48Field(
                                                owner, unsigned char*, 0x46)];
                                        MATCHING_KEEP(sample);
                                        MATCHING_KEEP_VOLATILE_CLOBBER(sample, "memory");
                                        Actor14D48Player224 = 0;
                                        MATCHING_BARRIER_VOLATILE("memory");
                                        Actor14D48Player220 = (sample * 25) >> 11;
                                    }
                                initializeContact:
                                    Actor14D48Field(state, int*, 12) = 1;
                                block_30:
                                    Actor14D48Field(owner, unsigned char*, 0x48) = 1;
                                    return;
                                }
                            noTarget:
                                if (Actor14D48CountTimerDown(state + 4, 4)) {
                                    Actor14D48Field(owner, unsigned char*, 0x48) = 3;
                                    goto block_39;
                                }
                                Actor14D48Field(owner, unsigned char*, 0x44) += 0xF4;
                                Actor14D48SpawnParticle(1, 46, ownerPosition, (void*)50);
                                return;
                            }
                        }
                    }
                }
                goto block_39;
            }
            goto block_39;
        case 1:
            Actor14D48func_8001BA30(owner + 0xC, 0x3E8, 0, 0, 0x130000,
                                    Actor14D48D_8006C550 +
                                        (Actor14D48Field(owner, unsigned char*, 0x3A) * 0x58));
            call4 = owner;
            if (Actor14D48Field(state, int*, 0xC)) {
                MATCHING_BARRIER_VOLATILE("$5");
                helperMode = 1;
            } else {
                MATCHING_BARRIER_VOLATILE("$5");
                helperMode = 0;
            }
            Actor14D48PlayMobySoundEvent(call4, helperMode, 0);
            {
                register unsigned char* child __asm__("$3") = Actor14D48SpawnMoby(100, owner);
                if (child) {
                    Actor14D48Field(child, unsigned char*, 0x48) = 0;
                    Actor14D48Field(child, unsigned char*, 0x47) = 4;
                }
            }
            Actor14D48SpawnParticle(8, 70, owner + 12, (void*)16);
            if (Actor14D48Field(owner, unsigned char*, 0x3A) == 255) {
                Actor14D48Field(owner, unsigned char*, 0x48) = 3;
                Actor14D48Field(state, int*, 4) = 500;
                return;
            }
        block_39:
            Actor14D48DeleteMoby(owner);
            return;
    }
}

#undef Actor14D48Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80083318.
* Assembly SHA256 f2a92333f5b03a2089cb8df45b9a2465811fce45590d2d1e280ac6869338a972.
* AI generated;not human reviewed. All793 instructions,33 selectors,
* original zero padding word and every native/linked target must match.
* Frame80 preserves S0..S5/RA and full SP20..5F local extent. All physical
* state joins,byte stores,callback paths and original shared calls remain
* in their native order. The signed full-word F264 argument retains the
* original LHU/SLL16/SRA20 producer;the decoder's u8 cast was rejected
* because its extra ANDI is absent from the original caller. F110 has
* only A0/A1 inputs:asm/stdutil.s original8004F110..8004F164 overwrites
* A2 before reading it. Its unused decoder argument is removed while
* retaining every original vector producer and call word. Retained S0
* player bases preserve their original byte addends/indexed loads. The
* state30 return uses ordinary C storage across35DDC,producing the native
* V1=6/SP10 store and S0 copy in the call delay without extra bindings.
* Original state30 post-call signed comparison/state11/state12 entries,
* state12 vector/status stores and state11 V1 rand arithmetic remain
* exact. The final volatile byte view preserves original branch688's
* reload target;it introduces no new load or CPU instruction. Initialized
* empty metadata emits zero;no opcode assembly,partialHI,fixedFP,unknown
* saved-register inputs or overlapping live aliases. Raw units/fixed point,
* remaining helper contracts,caller cadence and synchronized retail runtime
* remain open. Cadence is per invocation;confidence is Rev0 binary identity
* after all gates. Falsification:every native/linked word,actual transfers,
* all33 selector targets/padding,full EXE and every overlay retail hash.
*/
#define Level14_83318Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level14_83318Call19194View1() __asm__("func_80019194");
int Level14_83318RequestMobyAnimationView1() __asm__("func_80034F40");
int Level14_83318SetMobyAnimationView1() __asm__("func_80034F80");
int Level14_83318Call35194View1() __asm__("func_80035194");
int Level14_83318TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level14_83318TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level14_83318CountTimerDownView1() __asm__("func_800359A4");
int Level14_83318Call35DDCView1() __asm__("func_80035DDC");
int Level14_83318Call35EE0View1() __asm__("func_80035EE0");
int Level14_83318Call369B8View1() __asm__("func_800369B8");
int Level14_83318Call36A68View1() __asm__("func_80036A68");
int Level14_83318Call38BF8View1() __asm__("func_80038BF8");
int Level14_83318Call391E8View1() __asm__("func_800391E8");
int Level14_83318Call3BA00View1() __asm__("func_8003BA00");
int Level14_83318PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level14_83318PlanarHeadingLookupView1() __asm__("func_8004E880");
int Level14_83318TransformVectorByBasisView1() __asm__("func_8004ED6C");
void Level14_83318ShiftVectorRightTowardZeroView1(void*, int) __asm__("func_8004F110");
int Level14_83318CopyVectorView1() __asm__("func_8004F178");
int Level14_83318AddVectorView1() __asm__("func_8004F194");
int Level14_83318AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level14_83318ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level14_83318DeleteMobyView1() __asm__("func_80055B18");
int Level14_83318RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level14_83318Call55E84View1() __asm__("func_80055E84");
int Level14_83318DatarandView1() __asm__("rand");
extern int Level14_83318Data6C550View1 __asm__("D_8006C550");
extern int Level14_83318Data6C770View1 __asm__("D_8006C770");
extern int Level14_83318Data6E020View1 __asm__("D_8006E020");
extern int Level14_83318Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level14_83318Data6E040View1 __asm__("D_8006E040");
extern int Level14_83318Data6E344View1 __asm__("D_8006E344");
extern int Level14_83318Data70328View1 __asm__("D_80070328");
extern int Level14_83318Data7190CView1 __asm__("D_8007190C");
extern int Level14_83318Data71910View1 __asm__("D_80071910");
extern int (*Level14_83318Data74414View1)() __asm__("unk_ovlheader_80074414");
void func_level_14_80083318(void* input) {
    int retainedState30Result;
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord18 __asm__("$18"), addressOrResult16 __asm__("$16"),
        retainedDistanceOrWord19 __asm__("$19"), retainedVectorOrWord20 __asm__("$20"),
        retainedFlag21 __asm__("$21");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C;
    } originalFrame;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    rawWord3 = Level14_83318Field(ownerRecord17, unsigned char*, 0x48);
    privateRecord18 = Level14_83318Field(ownerRecord17, void**, 0);
    if (rawWord3 != 7) {
        if (rawWord3 < 9U) {
            if (Level14_83318Field(ownerRecord17, int*, 0x18) != 0) {
                if (rawWord3 == 6) {
                    Level14_83318Field(ownerRecord17, int*, 0x18) = 0;
                } else {
                    Level14_83318Call36A68View1(ownerRecord17, 0, 0, 0);
                    Level14_83318Call38BF8View1(ownerRecord17, privateRecord18 + 0x1C, 2, 7);
                    Level14_83318Field(privateRecord18, short*, 0x26) = 0x258;
                    Level14_83318Field(privateRecord18, unsigned short*, 0x28) =
                        (unsigned short)(Level14_83318Field(privateRecord18, unsigned short*,
                                                            0x28) |
                                         0x22);
                }
            }
            goto callOriginalCommonPreparation;
        }
        addressOrResult16 = 0;
        if (Level14_83318Field(ownerRecord17, int*, 0x18) & 0x120000) {
            do {
                rawWord2 = Level14_83318Call391E8View1(1, 0x128, ownerRecord17, addressOrResult16,
                                                       addressOrResult16, 0xC8, 0x100);
                addressOrResult16 += 1;
                Level14_83318Field(rawWord2, signed char*, 0x4F) = 0xC;
            } while (addressOrResult16 < 5);
            Level14_83318PlayMobySoundEventView1(ownerRecord17, 0, 0);
            rawWord3 = Level14_83318Field(ownerRecord17, unsigned char*, 0x48);
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3) : "$4", "$6");
            argumentWord6 = 0;
            if (rawWord3 == 0x20) {
                Level14_83318Call36A68View1(ownerRecord17, 0, argumentWord6, 0);
                Level14_83318RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Level14_83318Call3BA00View1(ownerRecord17);
                argumentWord4 = (int)ownerRecord17;
                MATCHING_KEEP(argumentWord4);
                argumentWord5 = 0x28;
                goto callOriginalFinalHelpers;
            }
            argumentWord4 = (int)ownerRecord17;
            MATCHING_KEEP(argumentWord4);
            Level14_83318Field(ownerRecord17, signed char*, 0x4F) = 0x2D;
            Level14_83318Field(ownerRecord17, int*, 0x18) = 0;
            Level14_83318TurnMobyTowardPlayerView1(argumentWord4, 0x80, argumentWord6, 0);
            Level14_83318Field(privateRecord18, unsigned char*, 0x2D) =
                (unsigned char)Level14_83318Field((int)&Level14_83318Data70328View1, unsigned char*,
                                                  0xE);
            Level14_83318SetMobyAnimationView1(ownerRecord17, 6);
            Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 6U;
            return;
        }
        goto continueOriginalEarlyDispatch;
    }
continueOriginalEarlyDispatch:
callOriginalCommonPreparation:
    Level14_83318RefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
    rawWord3 = Level14_83318Field(ownerRecord17, unsigned char*, 0x48);
    switch (rawWord3) {
        case 0:
            Level14_83318Field(ownerRecord17, signed char*, 0x4F) = 0x2D;
            if (Level14_83318ApproximatePlanarDistanceView1(ownerRecord17 + 0xC,
                                                            (int)&Level14_83318Data70328View1) <
                Level14_83318Field(privateRecord18, short*, 0xC)) {
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 2U;
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 2);
                return;
            }
        default:
            return;
        case 2:
            Level14_83318TurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 0);
            if (Level14_83318Data6C770View1 != 0) {
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 3U;
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 3);
                return;
            }
            break;
        case 3:
            Level14_83318TurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 0);
            argumentWord4 = (int)&originalFrame.sp20;
            MATCHING_KEEP(argumentWord4);
            addressOrResult16 = (int)&Level14_83318Data70328View1 + 0x98;
            MATCHING_KEEP(addressOrResult16);
            Level14_83318CopyVectorView1(argumentWord4, addressOrResult16);
            argumentWord6 = originalFrame.sp24;
            originalFrame.sp20 *= 0xF;
            originalFrame.sp24 = argumentWord6 * 0xF;
            originalFrame.sp28 *= 0xF;
            Level14_83318ShiftVectorRightTowardZeroView1(&originalFrame.sp20, 6);
            Level14_83318AddVectorView1(&originalFrame.sp20, &originalFrame.sp20,
                                        addressOrResult16 - 0x98);
            retainedDistanceOrWord19 = Level14_83318ApproximatePlanarDistanceView1(
                ownerRecord17 + 0xC, &originalFrame.sp20);
            if (({
                    rawWord3 = Level14_83318Field(privateRecord18, short*, 0xE);
                    rawWord3 = retainedDistanceOrWord19 < rawWord3;
                    MATCHING_KEEP(rawWord3);
                    rawWord3;
                }) &&
                (Level14_83318Data6E344View1 != 1) &&
                (Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x240) == 0)) {
                rawWord2 = Level14_83318Field(ownerRecord17, int*, 0x14);
                rawWord3 = Level14_83318Field((int)&Level14_83318Data70328View1, int*, 8);
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if ((rawWord2 < 0x400) &&
                    (Level14_83318AbsoluteByteAngleDeltaView1(
                         Level14_83318Field(ownerRecord17, unsigned char*, 0x46),
                         Level14_83318PlanarHeadingLookupView1(
                             Level14_83318Field(addressOrResult16, int*, -0x98) -
                                 Level14_83318Field(ownerRecord17, int*, 0xC),
                             Level14_83318Field(addressOrResult16, int*, -0x94) -
                                 Level14_83318Field(ownerRecord17, int*, 0x10),
                             0)) < 8) &&
                    (Level14_83318AbsoluteByteAngleDeltaView1(
                         ({
                             argumentWord4 = Level14_83318Data6E040View1;
                             argumentWord4 <<= 16;
                             MATCHING_KEEP(argumentWord4);
                             argumentWord4 >>= 20;
                             argumentWord4;
                         }),
                         Level14_83318PlanarHeadingLookupView1(
                             Level14_83318Field(ownerRecord17, int*, 0xC) -
                                 Level14_83318Data6E020View1,
                             Level14_83318Field(ownerRecord17, int*, 0x10) -
                                 Level14_83318Data6E024View1,
                             0)) < 0x18)) {
                    Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 4U;
                    Level14_83318RequestMobyAnimationView1(ownerRecord17, 4);
                    return;
                }
                goto checkOriginalPrivateThreshold;
            }
        checkOriginalPrivateThreshold:
            if (Level14_83318Field(privateRecord18, short*, 0xC) < retainedDistanceOrWord19) {
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 0);
                Level14_83318Field(ownerRecord17, unsigned char*, 0x40) = 0xF0;
                return;
            }
            break;
        case 4:
            rawWord2 = Level14_83318Call55E84View1(ownerRecord17);
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 4;
            argumentWord6 = 2;
            argumentWord7 = 0;
            __asm__(""
                    : "=r"(argumentWord7)
                    : "0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                    : "$19");
            retainedDistanceOrWord19 = rawWord2;
            Level14_83318TurnMobyTowardPlayerView1(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7);
            rawWord3 = Level14_83318Field(ownerRecord17, short*, 0x38);
            rawWord2 = Level14_83318Field(ownerRecord17, int*, 0x14);
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3) : "$16");
            addressOrResult16 = (int)&Level14_83318Data70328View1 + 8;
            MATCHING_KEEP(addressOrResult16);
            rawWord2 -= rawWord3;
            rawWord3 = Level14_83318Field(addressOrResult16, int*, 0);
            argumentWord4 = Level14_83318Field(ownerRecord17, unsigned char*, 0x49);
            retainedVectorOrWord20 = rawWord2 - rawWord3;
            if ((argumentWord4 == 0) &&
                (Level14_83318Field(ownerRecord17, unsigned char*, 0x3C) == 4) && (({
                    rawWord2 = retainedDistanceOrWord19 - 0x15;
                    MATCHING_KEEP(rawWord2);
                    (unsigned int)rawWord2 < 3U;
                })) &&
                (Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x240) == 0) &&
                (Level14_83318AbsoluteByteAngleDeltaView1(
                     Level14_83318Field(ownerRecord17, unsigned char*, 0x46),
                     Level14_83318PlanarHeadingLookupView1(
                         Level14_83318Field(addressOrResult16, int*, -8) -
                             Level14_83318Field(ownerRecord17, int*, 0xC),
                         Level14_83318Field((int)&Level14_83318Data70328View1, int*, 4) -
                             Level14_83318Field(ownerRecord17, int*, 0x10),
                         0)) < 8) &&
                (Level14_83318ApproximatePlanarDistanceView1(
                     ownerRecord17 + 0xC, ({
                         retainedDistanceOrWord19 = addressOrResult16 - 8;
                         MATCHING_KEEP(retainedDistanceOrWord19);
                         retainedDistanceOrWord19;
                     })) < Level14_83318Field(privateRecord18, short*, 0xE)) &&
                (({
                    rawWord2 = retainedVectorOrWord20 + 0x3FF;
                    MATCHING_KEEP(rawWord2);
                    (unsigned int)rawWord2 < 0x47FU;
                }))) {
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x298) =
                    (int)Level14_83318Field(ownerRecord17, unsigned char*, 0x46);
                if (Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x250) != 0) {
                    rawWord2 = Level14_83318Field(addressOrResult16, int*, 0x1C) | 1;
                } else {
                    rawWord2 = Level14_83318Field(addressOrResult16, int*, 0x1C) | 0x16;
                }
                Level14_83318Field(addressOrResult16, int*, 0x1C) = rawWord2;
                Level14_83318Field(ownerRecord17, unsigned char*, 0x49) = 1U;
                Level14_83318Field(privateRecord18, unsigned char*, 0x10) = 5U;
            }
            if (Level14_83318Data6C770View1 != 0) {
                Level14_83318Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                if (Level14_83318Field(privateRecord18, unsigned char*, 0x10) != 0) {
                    argumentWord4 = (int)ownerRecord17;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord5 = 5;
                    rawWord2 = 5;
                    Level14_83318Field(privateRecord18, unsigned char*, 0x10) = 0;
                    goto storeOriginalStateByteAndCall;
                }
                goto clearOriginalOwnerStateAndCall;
            }
            break;
        case 6:
            if (Level14_83318Call55E84View1(ownerRecord17) < 0x15) {
                Level14_83318Call35EE0View1(
                    ownerRecord17, Level14_83318Field(privateRecord18, unsigned char*, 0x2D), 0x64,
                    0, 0, 0);
            }
            Level14_83318CopyVectorView1(&originalFrame.sp30, ownerRecord17 + 0xC);
            originalFrame.sp38 += 0x28A;
            if (Level14_83318Call19194View1(&originalFrame.sp30, 0x258) != 0) {
                Level14_83318Field(ownerRecord17, int*, 0xC) = (int)Level14_83318Data7190CView1;
                Level14_83318Field(ownerRecord17, int*, 0x10) = (int)Level14_83318Data71910View1;
            }
        case 5:
            if (Level14_83318Data6C770View1 != 0) {
            clearOriginalOwnerStateAndCall:
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 0;
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 0);
                return;
            }
            break;
        case 31:
            Level14_83318SetMobyAnimationView1(ownerRecord17, 9);
            Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 9U;
            return;
        case 9:
            if (Level14_83318CountTimerDownView1(privateRecord18 + 0x12, 2) != 0) {
                if (Level14_83318Field(privateRecord18, int*, 0x18) != 0) {
                    if (!(Level14_83318DatarandView1() & 0x15) &&
                        (Level14_83318Data74414View1(
                             Level14_83318Field(privateRecord18, int*, 0x18),
                             (int)&Level14_83318Data70328View1) != 0) &&
                        (Level14_83318AbsoluteByteAngleDeltaView1(
                             ({
                                 argumentWord4 = Level14_83318Data6E040View1;
                                 argumentWord4 <<= 16;
                                 MATCHING_KEEP(argumentWord4);
                                 argumentWord4 >>= 20;
                                 argumentWord4;
                             }),
                             Level14_83318PlanarHeadingLookupView1(
                                 Level14_83318Field(ownerRecord17, int*, 0xC) -
                                     Level14_83318Data6E020View1,
                                 Level14_83318Field(ownerRecord17, int*, 0x10) -
                                     Level14_83318Data6E024View1,
                                 0)) < 0x16)) {
                        rawWord3 = Level14_83318Field(privateRecord18, int*, 0x14);
                        if (rawWord3 >= 0) {
                            argumentWord4 = (rawWord3 * 0x58) + Level14_83318Data6C550View1;
                            if (Level14_83318Field(argumentWord4, unsigned char*, 0x48) == 9) {
                                Level14_83318Field(Level14_83318Field(argumentWord4, void**, 0),
                                                   short*, 0x12) = 0x3C;
                            }
                        }
                        goto storeOriginalStateThirty;
                    }
                } else if (Level14_83318ApproximatePlanarDistanceView1(
                               ownerRecord17 + 0xC, (int)&Level14_83318Data70328View1) <
                           Level14_83318Field(privateRecord18, short*, 0xC)) {
                    Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 0xAU;
                    Level14_83318RequestMobyAnimationView1(ownerRecord17, 0xA);
                    return;
                }
            }
            break;
        case 10:
            if (Level14_83318Data6C770View1 != 0) {
            storeOriginalStateThirty:
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 8);
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 30;
                Level14_83318Field(privateRecord18, short*, 0x12) = 90;
                return;
            }
            break;
        case 30:
            retainedState30Result = Level14_83318TurnMobyTowardPlayerView1(ownerRecord17, 4, 1, 0);
            Level14_83318Call35DDCView1(ownerRecord17, 20, 700, 0, 6);
            if ((Level14_83318CountTimerDownView1(privateRecord18 + 0x12, 2) != 0) ||
                (retainedState30Result == 1)) {
                if (Level14_83318AbsoluteByteAngleDeltaView1(
                        ({
                            argumentWord4 = Level14_83318Data6E040View1;
                            argumentWord4 <<= 16;
                            MATCHING_KEEP(argumentWord4);
                            argumentWord4 >>= 20;
                            argumentWord4;
                        }),
                        Level14_83318PlanarHeadingLookupView1(
                            Level14_83318Field(ownerRecord17, int*, 0xC) -
                                Level14_83318Data6E020View1,
                            Level14_83318Field(ownerRecord17, int*, 0x10) -
                                Level14_83318Data6E024View1,
                            0)) >= 0x16) {
                    Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = 0xBU;
                    Level14_83318RequestMobyAnimationView1(ownerRecord17, 0xB);
                    return;
                }
                argumentWord4 = Level14_83318Field(privateRecord18, int*, 0x18);
                if (!argumentWord4)
                    goto measureOriginalState30Distance;
                rawWord2 =
                    Level14_83318Data74414View1(argumentWord4, (int)&Level14_83318Data70328View1);
                if (rawWord2) {
                    rawWord2 = 12;
                    goto storeOriginalStateTwelve;
                }
                rawWord2 = 11;
                goto storeOriginalStateEleven;
            measureOriginalState30Distance:
                rawWord2 = Level14_83318ApproximatePlanarDistanceView1(
                    ownerRecord17 + 12, (int)&Level14_83318Data70328View1);
                rawWord3 = Level14_83318Field(privateRecord18, short*, 12);
                rawWord3 = rawWord3 < rawWord2;
                rawWord2 = 11;
                if (!rawWord3)
                    goto loadOriginalStateTwelve;
            storeOriginalStateEleven:
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 11);
            loadOriginalStateTwelve:
                rawWord2 = 12;
            storeOriginalStateTwelve:
                Level14_83318Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                Level14_83318RequestMobyAnimationView1(ownerRecord17, 0xC);
                return;
            }
            break;
        case 12:
            retainedFlag21 = 0;
            retainedDistanceOrWord19 = 0x32;
            if (Level14_83318Field(ownerRecord17, unsigned char*, 0x49) != 3) {
                retainedDistanceOrWord19 = 0x64;
            }
            retainedVectorOrWord20 = (int)&originalFrame.sp40;
            argumentWord4 = retainedVectorOrWord20;
            MATCHING_KEEP(argumentWord4);
            addressOrResult16 = ownerRecord17 + 0xC;
            Level14_83318CopyVectorView1(argumentWord4, addressOrResult16);
            Level14_83318Call35DDCView1(ownerRecord17, retainedDistanceOrWord19, 0x44C, 0, 6);
            argumentWord4 = Level14_83318Field(privateRecord18, int*, 0x18);
            if ((argumentWord4 != 0) &&
                (Level14_83318Data74414View1(argumentWord4, addressOrResult16) == 0)) {
                retainedFlag21 = 1;
                Level14_83318CopyVectorView1(addressOrResult16, retainedVectorOrWord20);
            }
            rawWord2 = Level14_83318Field(ownerRecord17, short*, 0x38);
            rawWord3 = Level14_83318Field(ownerRecord17, int*, 0x14);
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2) : "$16");
            addressOrResult16 = (int)&Level14_83318Data70328View1 + 8;
            MATCHING_KEEP(addressOrResult16);
            rawWord3 -= rawWord2;
            rawWord2 = Level14_83318Field(addressOrResult16, int*, 0);
            argumentWord4 = Level14_83318Field(ownerRecord17, unsigned char*, 0x49);
            retainedDistanceOrWord19 = rawWord3 - rawWord2;
            if (((argumentWord4 == 0) || (argumentWord4 == 2)) &&
                (Level14_83318Field(ownerRecord17, unsigned char*, 0x3C) == 0xC) &&
                (Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x50) != 4) &&
                (Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x240) == 0) &&
                (Level14_83318AbsoluteByteAngleDeltaView1(
                     ({
                         argumentWord4 = Level14_83318Data6E040View1;
                         argumentWord4 <<= 16;
                         MATCHING_KEEP(argumentWord4);
                         argumentWord4 >>= 20;
                         argumentWord4;
                     }),
                     Level14_83318PlanarHeadingLookupView1(
                         Level14_83318Field(ownerRecord17, int*, 0xC) - Level14_83318Data6E020View1,
                         Level14_83318Field(ownerRecord17, int*, 0x10) -
                             Level14_83318Data6E024View1,
                         0)) < 0x16) &&
                (Level14_83318AbsoluteByteAngleDeltaView1(
                     Level14_83318Field(ownerRecord17, unsigned char*, 0x46),
                     Level14_83318PlanarHeadingLookupView1(
                         Level14_83318Field(addressOrResult16, int*, -8) -
                             Level14_83318Field(ownerRecord17, int*, 0xC),
                         Level14_83318Field((int)&Level14_83318Data70328View1, int*, 4) -
                             Level14_83318Field(ownerRecord17, int*, 0x10),
                         0)) < 0x37) &&
                (Level14_83318ApproximatePlanarDistanceView1(ownerRecord17 + 0xC, ({
                                                                 addressOrResult16 -= 8;
                                                                 MATCHING_KEEP(addressOrResult16);
                                                                 addressOrResult16;
                                                             })) < 0x3E8) &&
                (({
                    rawWord2 = retainedDistanceOrWord19 + 0x3FF;
                    MATCHING_KEEP(rawWord2);
                    (unsigned int)rawWord2 < 0x47FU;
                }))) {
                argumentWord4 = (int)ownerRecord17 + 32;
                argumentWord5 = (int)&originalFrame.sp50;
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$2");
                rawWord2 = 1;
                Level14_83318Field(ownerRecord17, unsigned char*, 0x49) = rawWord2;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                rawWord2 = Level14_83318Field(ownerRecord17, unsigned char*, 0x46);
                MATCHING_KEEP_CLOBBER(rawWord2, "$16");
                addressOrResult16 = 150;
                originalFrame.sp50 = addressOrResult16;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = 0;
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x298) = rawWord2;
                Level14_83318TransformVectorByBasisView1(argumentWord4, argumentWord5,
                                                         argumentWord5);
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x20C) = 0x10000400;
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x224) = 0x96;
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x24) =
                    (int)(Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x24) | 0x80);
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x21C) =
                    originalFrame.sp50;
                Level14_83318Field((int)&Level14_83318Data70328View1, int*, 0x220) =
                    originalFrame.sp54;
            }
            if (Level14_83318Field(ownerRecord17, unsigned char*, 0x49) == 1) {
                Level14_83318Field(ownerRecord17, unsigned char*, 0x49) = 2U;
            }
            if ((Level14_83318Field(ownerRecord17, unsigned char*, 0x49) == 0) &&
                ((retainedFlag21 != 0) || (Level14_83318ApproximatePlanarDistanceView1(
                                               ownerRecord17 + 0xC, privateRecord18) >= 0x2001))) {
                Level14_83318Field(ownerRecord17, unsigned char*, 0x49) = 2U;
            }
            if ((unsigned int)(Level14_83318Field(ownerRecord17, volatile unsigned char*, 0x49) -
                               2) < 2U) {
                Level14_83318TurnMobyTowardHeadingView1(
                    ownerRecord17,
                    Level14_83318PlanarHeadingLookupView1(
                        Level14_83318Field(privateRecord18, int*, 0) -
                            Level14_83318Field(ownerRecord17, int*, 0xC),
                        Level14_83318Field(privateRecord18, int*, 4) -
                            Level14_83318Field(ownerRecord17, int*, 0x10),
                        0),
                    5, 0, 0, 0);
                argumentWord4 = ownerRecord17 + 0xC;
                if (Level14_83318Field(ownerRecord17, unsigned char*, 0x49) == 2) {
                    if (Level14_83318ApproximatePlanarDistanceView1(argumentWord4,
                                                                    privateRecord18) < 0x400) {
                        Level14_83318RequestMobyAnimationView1(ownerRecord17, 8);
                        Level14_83318Field(ownerRecord17, unsigned char*, 0x49) = 3U;
                        return;
                    }
                } else if (Level14_83318ApproximatePlanarDistanceView1(argumentWord4,
                                                                       privateRecord18) < 0x80) {
                    argumentWord4 = (int)ownerRecord17;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord5 = 11;
                    rawWord2 = 11;
                    Level14_83318Field(argumentWord4, unsigned char*, 0x49) = 0;
                    goto storeOriginalStateByteAndCall;
                }
            }
            break;
        case 11:
            if (Level14_83318Data6C770View1 != 0) {
                rawWord2 = Level14_83318DatarandView1();
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 9;
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$3");
                rawWord2 &= 1;
                MATCHING_KEEP(rawWord2);
                rawWord3 = rawWord2 * 15;
                rawWord3 *= 2;
                rawWord3 += 90;
                rawWord2 = 9;
                Level14_83318Field(privateRecord18, short*, 0x12) = rawWord3;
            storeOriginalStateByteAndCall:
                Level14_83318Field(argumentWord4, signed char*, 0x48) = rawWord2;
                Level14_83318RequestMobyAnimationView1(argumentWord4, argumentWord5);
                return;
            }
            break;
        case 32:
            Level14_83318SetMobyAnimationView1(ownerRecord17, 9);
            return;
        case 7:
            if (Level14_83318Call35194View1(ownerRecord17, privateRecord18 + 0x1C) == 0x100) {
                Level14_83318RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Level14_83318Call3BA00View1(ownerRecord17);
                argumentWord4 = (int)ownerRecord17;
                MATCHING_KEEP(argumentWord4);
                argumentWord5 = 0x1E;
            callOriginalFinalHelpers:
                Level14_83318Call369B8View1(argumentWord4, argumentWord5);
                Level14_83318DeleteMobyView1(ownerRecord17);
            }
            break;
    }
}
#undef Level14_83318Field

void func_level_14_80083F7C(Moby* moby) {
    func_80039714(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_80083F9C.s SHA256 1ef3f395038116d9b76ee3e8895a874603fa6096d67a5ba9117df2807e85cf2f. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
int Controller83F9C_Call_PlaySound() __asm__("PlaySound");
int Controller83F9C_CallRequestMobyAnimation() __asm__("func_80034F40");
int Controller83F9C_Call_func_80035194() __asm__("func_80035194");
int Controller83F9C_CallTurnMobyTowardHeading() __asm__("func_8003585C");
int Controller83F9C_CallCountTimerDown() __asm__("func_800359A4");
int Controller83F9C_CallSubAngle8() __asm__("func_8003613C");
int Controller83F9C_CallRandBetween() __asm__("func_8003636C");
int Controller83F9C_Call_func_800369B8() __asm__("func_800369B8");
int Controller83F9C_Call_func_80038BF8() __asm__("func_80038BF8");
int Controller83F9C_CallPlanarHeadingLookup() __asm__("func_8004E880");
int Controller83F9C_CallCopyVector() __asm__("func_8004F178");
int Controller83F9C_CallAddVector() __asm__("func_8004F194");
int Controller83F9C_CallAbsoluteByteAngleDelta() __asm__("func_8004F264");
#define Controller83F9CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller83F9C_func_80019194() __asm__("func_80019194");                 /* extern */
int Controller83F9C_func_80035A80() __asm__("func_80035A80");                 /* extern */
int Controller83F9CTransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Controller83F9CMeasureVectorLength() __asm__("func_8004EDE8");            /* extern */
int Controller83F9CSubtractVector() __asm__("func_8004F1C8");                 /* extern */
int Controller83F9CApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller83F9CDeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller83F9CRefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller83F9C_func_80055E84() __asm__("func_80055E84");                 /* extern */
extern unsigned char Controller83F9C_D_80066BC8 __asm__("D_80066BC8");
extern unsigned char Controller83F9C_D_80066EAE __asm__("D_80066EAE");
extern unsigned char Controller83F9C_D_80066FCC __asm__("D_80066FCC");
extern int Controller83F9C_D_8006C58C __asm__("D_8006C58C");
extern int Controller83F9C_D_8006C770 __asm__("D_8006C770");
extern unsigned char Controller83F9C_D_80070300 __asm__("D_80070300");
extern Vector3D Controller83F9C_D_80070328 __asm__("D_80070328");
extern Vector3D Controller83F9C_D_8007190C __asm__("D_8007190C");
extern short Controller83F9C_D_800719DC __asm__("D_800719DC");
extern unsigned char Controller83F9C_D_level_14_800996EC __asm__("D_level_14_800996EC");
extern unsigned char
    Controller83F9C_Address_func_level_14_80075454 __asm__("func_level_14_80075454");
extern unsigned char main_TEXT_END;
extern unsigned char main_TEXT_START;

void func_level_14_80083F9C(Moby* inputOwner) {
    register Moby* owner __asm__("$18") = inputOwner;
    register unsigned char* scanLimit6 __asm__("$6");
    register unsigned char* executableEnd3 __asm__("$3");
    register unsigned char* initialCursor2 __asm__("$2");
    register int rawGlobalZ3 __asm__("$3");
    register int rawHalfword3 __asm__("$3");
    register int rawHalfword2 __asm__("$2");
    register Moby* callOwner4 __asm__("$4");
    register Vector3D* globalPlayer16 __asm__("$16");
    register Vector3D* secondDistancePosition4 __asm__("$4");
    register void* scratchAddress4 __asm__("$4");
    register int sizeWord2 __asm__("$2");
    register unsigned char* globalZAddress5 __asm__("$5");
    /* Original frame0x48: raw scratch vector SP+0x20..0x28,saves from0x30.
     * Private+0x2C word/private+0x30 cursor loops use eight rounds/bound64.
     * Shared branch entries preserve live arguments and skip recomputation.
     * The original uses signed halfword loads and full-word clamp comparisons.
     * Empty constraints emit no instruction. Physical/fixed-point units,
     * helper meanings and caller cadence remain unresolved. */
    struct {
        int sp20, sp24, sp28, pad2C;
    } originalFrame;

    short temp_v1_11;
    short temp_v1_8;
    int firstAngleWord;
    int secondAngleWord;
    register int executablePrivateWord3 __asm__("$3");
    register int overlayPrivateWord3 __asm__("$3");
    int var_a0;
    register int executableBitCount4 __asm__("$4");
    register int overlayBitCount4 __asm__("$4");
    register int pitchStepWord __asm__("$4");
    register int executableByteCount5 __asm__("$5");
    register int overlayByteCount5 __asm__("$5");
    register int nextMode5 __asm__("$5");
    register int yawStepWord __asm__("$19");
    register int executableUpdatedWord2 __asm__("$2");
    register int overlayUpdatedWord2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int var_v0_5 __asm__("$2");
    register int yawComparison2 __asm__("$2");
    register int pitchComparison2 __asm__("$2");
    register int var_v0_8 __asm__("$2");
    register int var_v0_9 __asm__("$2");
    register unsigned char* executableCursor3 __asm__("$3");
    unsigned char* temp_v1_4;
    register unsigned char* overlayCursor3 __asm__("$3");
    unsigned char temp_v1_7;
    register int nextState2 __asm__("$2");
    void* temp_a0;
    register void* childRecord6 __asm__("$6");
    register void* privateData __asm__("$17");
    register void* temp_v0 __asm__("$2");
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v0_4;
    void* temp_v0_5;
    void* temp_v1;
    void* temp_v1_10;
    void* temp_v1_12;
    void* temp_v1_9;

    privateData = owner->mobyTag;
    if (owner->substate == 0) {
        temp_v1 = Controller83F9CField(privateData, void**, 0x10);
        if (temp_v1 != 0) {
            Controller83F9CField(temp_v1, short*, 0xA) = 1;
            Controller83F9CField(Controller83F9CField(privateData, void**, 0x10), short*, 2) = 0;
        }
        owner->substate = 1;
    }
    if ((owner->state != 4) && (owner->damageFlags != 0)) {
        if (Controller83F9CField(privateData, int*, 0x34) != 0) {
            Controller83F9CField(&Controller83F9C_D_80066BC8, signed char*, 4) = 3;
            Controller83F9C_D_800719DC = 1;
            Controller83F9C_Call_PlaySound((int)D_8006C654->skillPoint, owner, 0xA1);
            var_a0 = 0xD3;
        } else {
            var_a0 = 0x10;
        }
        SpawnMoby(var_a0, owner);
        Controller83F9C_Call_func_80038BF8(owner, privateData + 0x14, 0, 4);
        Controller83F9CField(privateData, short*, 0x1E) = 0x190;
    }
    Controller83F9CRefreshMobySpatialGridAndBasis(owner, 7);
    if (owner->updateDistance == 0xFF) {
        if (Controller83F9CField(privateData, unsigned char**, 0x30) == 0) {
            Controller83F9CField(privateData, unsigned char**, 0x30) =
                (unsigned char*)(Controller83F9C_D_8006C58C + (&main_TEXT_START + 2));
        }
        initialCursor2 = Controller83F9CField(privateData, unsigned char**, 0x30);
        executableEnd3 = &main_TEXT_END;
        MATCHING_KEEP(executableEnd3);
        if ((unsigned int)initialCursor2 < (unsigned int)executableEnd3) {
            executableByteCount5 = 0;
            scanLimit6 = executableEnd3;
            MATCHING_KEEP(scanLimit6);
        scanExecutableByte:
            executableCursor3 = Controller83F9CField(privateData, unsigned char**, 0x30);
            if ((unsigned int)executableCursor3 < (unsigned int)scanLimit6) {
                executableBitCount4 = 0;
                Controller83F9CField(privateData, int*, 0x2C) =
                    (int)(Controller83F9CField(privateData, int*, 0x2C) ^
                          (*executableCursor3 << 8));
                do {
                    executablePrivateWord3 = Controller83F9CField(privateData, int*, 0x2C);
                    if (executablePrivateWord3 & 0x8000) {
                        executableUpdatedWord2 = (executablePrivateWord3 * 2) ^ 0x8005;
                    } else {
                        executableUpdatedWord2 = executablePrivateWord3 * 2;
                    }
                    Controller83F9CField(privateData, int*, 0x2C) = executableUpdatedWord2;
                    MATCHING_BARRIER("memory");
                    executableBitCount4 += 1;
                } while (executableBitCount4 < 8);
                executableByteCount5 += 1;
                temp_v1_4 = Controller83F9CField(privateData, unsigned char**, 0x30) +
                            ((Controller83F9CField(privateData, int*, 0x2C) & 3) + 1);
                Controller83F9CField(privateData, unsigned char**, 0x30) = temp_v1_4;
                if (executableByteCount5 >= 0x40) {
                    if ((unsigned int)temp_v1_4 >= (unsigned int)&main_TEXT_END) {
                        goto startOverlayScan;
                    }
                } else {
                    goto scanExecutableByte;
                }
            } else {
            startOverlayScan:
                Controller83F9CField(privateData, unsigned char**, 0x30) =
                    &Controller83F9C_Address_func_level_14_80075454;
            }
        }
    }
    if ((unsigned int)Controller83F9CField(privateData, unsigned char**, 0x30) >=
        (unsigned int)&Controller83F9C_Address_func_level_14_80075454) {
        overlayByteCount5 = 0;
        scanLimit6 = &Controller83F9C_D_level_14_800996EC;
        MATCHING_KEEP(scanLimit6);
    scanOverlayByte:
        overlayCursor3 = Controller83F9CField(privateData, unsigned char**, 0x30);
        if ((unsigned int)overlayCursor3 < (unsigned int)scanLimit6) {
            overlayBitCount4 = 0;
            Controller83F9CField(privateData, int*, 0x2C) =
                (int)(Controller83F9CField(privateData, int*, 0x2C) ^ (*overlayCursor3 << 8));
            do {
                overlayPrivateWord3 = Controller83F9CField(privateData, int*, 0x2C);
                if (overlayPrivateWord3 & 0x8000) {
                    overlayUpdatedWord2 = (overlayPrivateWord3 * 2) ^ 0x8005;
                } else {
                    overlayUpdatedWord2 = overlayPrivateWord3 * 2;
                }
                Controller83F9CField(privateData, int*, 0x2C) = overlayUpdatedWord2;
                MATCHING_BARRIER("memory");
                overlayBitCount4 += 1;
            } while (overlayBitCount4 < 8);
            overlayByteCount5 += 1;
            Controller83F9CField(privateData, unsigned char**, 0x30) =
                (unsigned char*)(Controller83F9CField(privateData, unsigned char**, 0x30) + 1);
            if (overlayByteCount5 >= 0x40) {

            } else {
                goto scanOverlayByte;
            }
        }
    }
    if ((Controller83F9CField(privateData, unsigned char**, 0x30) ==
         &Controller83F9C_D_level_14_800996EC) &&
        (Controller83F9CField(privateData, int*, 0x2C) != 0)) {
        Controller83F9CField(&Controller83F9C_D_80066EAE, short*, 8) = 0;
        *(&Controller83F9C_D_80070300 +
          Controller83F9CField(&Controller83F9C_D_80066FCC, unsigned char*, 0x10)) =
            *(&Controller83F9C_D_80070300 +
              Controller83F9CField(&Controller83F9C_D_80066FCC, unsigned char*, 0x10)) &
            0xFE;
        Controller83F9CField(privateData, int*, 0x2C) = 0;
    }
    temp_v1_7 = owner->state;
    switch (temp_v1_7) {
        case 0:
            sizeWord2 = 0x2D;
            globalZAddress5 = (unsigned char*)&Controller83F9C_D_80070328.z;
            __asm__("" : "=r"(globalZAddress5) : "0"(globalZAddress5), "r"(sizeWord2) : "memory");
            owner->size = sizeWord2;
            var_v0_3 = owner->position.z;
            rawGlobalZ3 = *(int*)globalZAddress5;
            var_v0_3 -= rawGlobalZ3;
            if (var_v0_3 < 0) {
                var_v0_3 = -var_v0_3;
            }
            if ((var_v0_3 < 0x1000) &&
                (Controller83F9CApproximatePlanarDistance(
                     &owner->position, (Vector3D*)(globalZAddress5 - 8)) < 0x2800)) {
                callOwner4 = owner;
                nextMode5 = 3;
                nextState2 = 3;
                Controller83F9CField(privateData, int*, 0xC) = 0;
                goto applySharedState;
            }
            if (Controller83F9C_CallCountTimerDown(privateData + 0xC, 4) != 0) {
                owner->state = 1;
                Controller83F9C_CallRequestMobyAnimation(owner, 1);
                return;
            }
        default:
            return;
        case 1:
            if (Controller83F9C_D_8006C770 != 0) {
                Controller83F9CField(privateData, int*, 0xC) =
                    Controller83F9C_CallRandBetween(0x5A, 0x78);
                owner->state = 0;
                Controller83F9C_CallRequestMobyAnimation(owner, 0);
                return;
            }
            break;
        case 20:
        case 21:
            callOwner4 = owner;
            if (owner->state == 0x15) {
                owner->substate = 0xA;
            }
            temp_v0 = Controller83F9CField(privateData, void**, 0x10);
            rawGlobalZ3 = 1;
            Controller83F9CField(temp_v0, short*, 0xA) = rawGlobalZ3;
            temp_v0 = Controller83F9CField(privateData, void**, 0x10);
            nextMode5 = 2;
            Controller83F9CField(temp_v0, short*, 2) = rawGlobalZ3;
            nextState2 = 2;
            goto applySharedState;
        case 2:
            Controller83F9C_CallCountTimerDown(privateData + 0xC, 4);
            if (owner->substate != 0xA) {
                if (Controller83F9CField(privateData, int*, 0xC) == 0) {
                    if (Controller83F9CApproximatePlanarDistance(
                            &owner->position, &Controller83F9C_D_80070328) < 0x2000) {
                        scratchAddress4 = &originalFrame.sp20;
                        MATCHING_KEEP(scratchAddress4);
                        var_v0_5 = owner->position.z;
                        rawGlobalZ3 = Controller83F9C_D_80070328.z;
                        var_v0_5 -= rawGlobalZ3;
                        if (var_v0_5 < 0) {
                            var_v0_5 = -var_v0_5;
                        }
                        if (var_v0_5 >= 0xC00)
                            goto caseTwoPositionEntry;
                        {
                            if (Controller83F9C_CallPlanarHeadingLookup(
                                    Controller83F9C_D_80070328.x - owner->position.x,
                                    Controller83F9C_D_80070328.y - owner->position.y, 0) < 0x16) {
                                temp_v0 = Controller83F9CField(privateData, void**, 0x10);
                                rawHalfword3 = Controller83F9CField(temp_v0, short*, 0xA);
                                MATCHING_KEEP(rawHalfword3);
                                Controller83F9CField(temp_v0, short*, 0xA) = -rawHalfword3;
                                Controller83F9CField(privateData, int*, 0xC) = 0x3C;
                            }
                        }
                    }
                }
            }
            scratchAddress4 = &originalFrame.sp20;
        caseTwoPositionEntry:
            temp_v0_2 = Controller83F9CField(privateData, void**, 0x10);
            Controller83F9CSubtractVector(scratchAddress4,
                                          Controller83F9CField(temp_v0_2, int*, 0xC) +
                                              (Controller83F9CField(temp_v0_2, short*, 2) * 0x10),
                                          &owner->position);
            temp_v0_3 = Controller83F9CField(privateData, void**, 0x10);
            if (Controller83F9CApproximatePlanarDistance(
                    Controller83F9CField(temp_v0_3, int*, 0xC) +
                        (Controller83F9CField(temp_v0_3, short*, 2) * 0x10),
                    &owner->position) < 0x400) {
                temp_a0 = Controller83F9CField(privateData, void**, 0x10);
                temp_v1_8 = Controller83F9CField(temp_a0, short*, 0);
                Controller83F9CField(temp_a0, short*, 2) =
                    (short)((int)(Controller83F9CField(temp_a0, short*, 2) +
                                  Controller83F9CField(temp_a0, short*, 0xA) + temp_v1_8) %
                            temp_v1_8);
            }
            firstAngleWord =
                Controller83F9C_CallPlanarHeadingLookup(originalFrame.sp20, originalFrame.sp24, 0);
            secondAngleWord = Controller83F9C_CallPlanarHeadingLookup(
                Controller83F9CMeasureVectorLength(&originalFrame.sp20, 0), originalFrame.sp28, 0);
            yawStepWord = Controller83F9C_CallSubAngle8((int)owner->angle.yaw, firstAngleWord);
            pitchStepWord = Controller83F9C_CallSubAngle8((int)owner->angle.pitch, secondAngleWord);
            yawComparison2 = yawStepWord < 6;
            if (!yawComparison2) {
                yawStepWord = 5;
                MATCHING_KEEP(yawStepWord);
            }
            yawComparison2 = yawStepWord < -5;
            if (yawComparison2)
                yawStepWord = -5;
            pitchComparison2 = pitchStepWord < 6;
            if (!pitchComparison2) {
                pitchStepWord = 5;
                MATCHING_KEEP(pitchStepWord);
            }
            pitchComparison2 = pitchStepWord < -5;
            if (pitchComparison2)
                pitchStepWord = -5;
            owner->angle.yaw += yawStepWord;
            owner->angle.pitch += pitchStepWord;
            originalFrame.sp20 = 0x64;
            originalFrame.sp24 = 0;
            originalFrame.sp28 = 0;
            if (Controller83F9CField(privateData, int*, 0x34) != 0) {
                originalFrame.sp20 = 0x8C;
            }
            Controller83F9CTransformVectorByBasis(&owner->rotationMatrix, &originalFrame.sp20,
                                                  &originalFrame.sp20);
            Controller83F9C_CallAddVector(&owner->position, &owner->position,
                                          (Vector3D*)&originalFrame.sp20);
            if ((Controller83F9CField(privateData, int*, 0xC) != 0) &&
                (Controller83F9C_func_80019194(&owner->position, 0x190) != 0)) {
                Controller83F9C_CallCopyVector(&owner->position, &Controller83F9C_D_8007190C);
                return;
            }
            break;
        case 3:
            if (Controller83F9CApproximatePlanarDistance(&owner->position,
                                                         &Controller83F9C_D_80070328) < 0x2801) {
                MATCHING_KEEP(owner);
                var_v0_8 = owner->position.z;
                rawGlobalZ3 = Controller83F9C_D_80070328.z;
                var_v0_8 -= rawGlobalZ3;
                if (var_v0_8 < 0) {
                    var_v0_8 = -var_v0_8;
                }
                secondDistancePosition4 = &owner->position;
                if (var_v0_8 < 0x1001)
                    goto secondDistanceEntry;
            }
        clearStateBeforeSecondDistance:
            owner->state = 0;
            Controller83F9C_CallRequestMobyAnimation(owner, 0);
            MATCHING_KEEP(owner);
            secondDistancePosition4 = &owner->position;
        secondDistanceEntry:
            globalPlayer16 = &Controller83F9C_D_80070328;
            MATCHING_KEEP(globalPlayer16);
            if (Controller83F9CApproximatePlanarDistance(secondDistancePosition4, globalPlayer16) <
                0x1800) {
                var_v0_9 = owner->position.z;
                rawGlobalZ3 = Controller83F9C_D_80070328.z;
                var_v0_9 -= rawGlobalZ3;
                if (var_v0_9 < 0) {
                    var_v0_9 = -var_v0_9;
                }
                if (var_v0_9 < 0xC00) {
                    temp_v1_9 = Controller83F9CField(privateData, void**, 0x10);
                    temp_v0_4 = (Controller83F9CField(temp_v1_9, short*, 2) * 0x10) +
                                Controller83F9CField(temp_v1_9, int*, 0xC);
                    if (Controller83F9C_CallAbsoluteByteAngleDelta(
                            Controller83F9C_CallPlanarHeadingLookup(
                                Controller83F9CField(temp_v0_4, int*, 0) - owner->position.x,
                                Controller83F9CField(temp_v0_4, int*, 4) - owner->position.y, 0),
                            (int)owner->angle.yaw) < 0x20) {
                        if (Controller83F9C_CallAbsoluteByteAngleDelta(
                                Controller83F9C_CallPlanarHeadingLookup(
                                    globalPlayer16->x - owner->position.x,
                                    Controller83F9C_D_80070328.y - owner->position.y, 0),
                                (int)owner->angle.yaw) < 0x20) {
                            nextMode5 = 1;
                            MATCHING_OBSERVE_VOLATILE(nextMode5);
                            temp_v1_10 = Controller83F9CField(privateData, void**, 0x10);
                            rawHalfword2 = Controller83F9CField(temp_v1_10, short*, 0xA);
                            MATCHING_KEEP(rawHalfword2);
                            Controller83F9CField(temp_v1_10, short*, 0xA) = -rawHalfword2;
                            childRecord6 = Controller83F9CField(privateData, void**, 0x10);
                            temp_v1_11 = Controller83F9CField(childRecord6, short*, 0);
                            rawGlobalZ3 = (Controller83F9CField(childRecord6, short*, 2) +
                                           (Controller83F9CField(childRecord6, short*, 0xA) * 2) +
                                           temp_v1_11) %
                                          temp_v1_11;
                            callOwner4 = owner;
                            rawHalfword2 = 0x3C;
                            __asm__(""
                                    : "=r"(rawHalfword2)
                                    : "0"(rawHalfword2), "r"(rawGlobalZ3), "r"(callOwner4));
                            Controller83F9CField(childRecord6, short*, 2) = rawGlobalZ3;
                            Controller83F9CField(privateData, int*, 0xC) = rawHalfword2;
                            MATCHING_BARRIER("memory");
                            nextState2 = 0x16;
                        applySharedState:
                            callOwner4->state = nextState2;
                            Controller83F9C_CallRequestMobyAnimation(callOwner4, nextMode5);
                            return;
                        }
                    }
                }
                goto issueStateThreeHelper;
            }
        issueStateThreeHelper:
            Controller83F9C_func_80035A80(owner, Controller83F9CField(privateData, void**, 0x10),
                                          0x12C, 0x64, 0, 5, 0x40, 0x20004);
            return;
        case 22:
            if ((unsigned int)(Controller83F9C_func_80055E84(owner) - 0x15) < 0x23U) {
                temp_v1_12 = Controller83F9CField(privateData, void**, 0x10);
                temp_v0_5 = (Controller83F9CField(temp_v1_12, short*, 2) * 0x10) +
                            Controller83F9CField(temp_v1_12, int*, 0xC);
                Controller83F9C_CallTurnMobyTowardHeading(
                    owner,
                    Controller83F9C_CallPlanarHeadingLookup(
                        Controller83F9CField(temp_v0_5, int*, 0) - owner->position.x,
                        Controller83F9CField(temp_v0_5, int*, 4) - owner->position.y, 0),
                    8, 1, 1, 0);
            }
            if (Controller83F9C_D_8006C770 != 0) {
                owner->state = 3;
                Controller83F9C_CallRequestMobyAnimation(owner, 3);
                return;
            }
            break;
        case 4:
            if (Controller83F9C_Call_func_80035194(owner, privateData + 0x14) == 0x100) {
                Controller83F9C_Call_func_800369B8(owner, 0x28);
                Controller83F9CDeleteMoby(owner);
            }
            break;
    }
}
#undef Controller83F9CField


/**
 * MobyUpdate_299() - func_level_14_800848EC()
 * https://decomp.me/scratch/YPrYK
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_800848EC.s SHA256 cd4fc54bd62ffc0903d77165ff978bdc86324c477b3166f224602e8aa3275eae. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level14_848ECField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char Level14_848EC_func_8001A358() __asm__("func_8001A358");
/* extern */
int Level14_848EC_func_8001C288() __asm__("func_8001C288");
/* extern */
int Level14_848ECCountTimerDown() __asm__("func_800359A4");
/* extern */
int Level14_848ECRandBetween() __asm__("func_8003636C");
/* extern */
unsigned char Level14_848EC_func_8003B74C() __asm__("func_8003B74C");
/* extern */
unsigned char Level14_848ECPlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned char Level14_848ECPlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned char Level14_848ECTransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
unsigned char Level14_848ECClearVector() __asm__("func_8004F168");
/* extern */
unsigned char Level14_848ECCopyVector() __asm__("func_8004F178");
/* extern */
unsigned char Level14_848ECAddVector() __asm__("func_8004F194");
/* extern */
int Level14_848ECApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned char Level14_848ECRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
unsigned char Level14_848EC_func_8005629C() __asm__("func_8005629C");
/* extern */
extern unsigned char Level14_848EC_D_80065920 __asm__("D_80065920");
extern int Level14_848EC_D_8006C58C __asm__("D_8006C58C");
extern unsigned char Level14_848EC_D_8006D088 __asm__("D_8006D088");
extern int Level14_848EC_D_8006E020 __asm__("D_8006E020");
extern int Level14_848EC_D_8006E024 __asm__("D_8006E024");
extern unsigned char Level14_848EC_D_80070328 __asm__("D_80070328");
extern unsigned char Level14_848EC_D_800716B0 __asm__("D_800716B0");
extern void** (*Level14_848EC_SpawnMoby)() __asm__("SpawnMoby");
extern void* (*Level14_848EC_SpawnParticle)() __asm__("SpawnParticle");

void func_level_14_800848EC(void* incomingOwnerRecord) {
    register void* ownerRecord17 __asm__("$17") = incomingOwnerRecord;
    struct {
        int sp10;
        int sp14;
        int sp18;
        unsigned char pad1C[4];
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        int sp30;
        int sp34;
        int sp38;
        unsigned char pad3C[4];
        int sp40;
        int sp44;
        int sp48;
        unsigned char pad4C[4];
        int sp50;
        int sp54;
        int sp58;
        unsigned char pad5C[4];
    } scratch;

    register int word3 __asm__("$3");
    register int word2 __asm__("$2");
    register void* argument4 __asm__("$4");
    register void* argument5 __asm__("$5");
    register void* pointer6 __asm__("$6");
    register int argument5word __asm__("$5");
    register int argument4word __asm__("$4");
    register int argument7 __asm__("$7");
    register int argument6 __asm__("$6");
    register void* scratchPointer19 __asm__("$19");
    register unsigned int particleSelector5 __asm__("$5");
    int phaseWord2;

    int tableOffset3;
    register int firstCount16 __asm__("$16");
    register int secondCount16 __asm__("$16");
    register int radialCount18 __asm__("$18");
    register void* (*particleCallback3)() __asm__("$3");
    register unsigned char* frameBase29 __asm__("$29");
    unsigned int tableByte4;
    unsigned int ownerByte6;
    int stateWord3;
    register void** spawnedOwner16 __asm__("$16");
    void** spawnedOwner2;
    register void* scratchOrPlayer16 __asm__("$16");
    register void* ownerPosition18 __asm__("$18");
    register void* spawnedPrivate18 __asm__("$18");
    register void* privateRecord20 __asm__("$20");
    register void* spawnedPrivate21 __asm__("$21");
    void* firstParticle2;
    void* secondParticle2;

    privateRecord20 = Level14_848ECField(ownerRecord17, void**, 0);
    if (Level14_848ECField(ownerRecord17, unsigned char*, 0x49) != 0) {
        goto dispatchState;
    }
    Level14_848ECField(ownerRecord17, unsigned char*, 0x49) = 1U;
    Level14_848ECField(privateRecord20, int*, 4) =
        (int)Level14_848ECField(ownerRecord17, int*, 0x14);
dispatchState:
    stateWord3 = Level14_848ECField(ownerRecord17, unsigned char*, 0x48);
    if (stateWord3 == 1) {
        goto state1;
    }
    if ((int)stateWord3 >= 2) {
        goto dispatchStates2And3;
    }
    if (stateWord3 == 0) {
        goto state0;
    }
    return;
dispatchStates2And3:
    if (stateWord3 == 2) {
        goto state2;
    }
    if (stateWord3 == 3) {
        goto state3;
    }
    return;
state0:
    /* The original LHU followed by SLL16/SRA22 preserves signed-halfword
     * interpretation of the table value. Its physical units are unresolved. */
    Level14_848ECField(ownerRecord17, int*, 0x14) =
        (int)(Level14_848ECField(ownerRecord17, int*, 0x14) +
              ((int)(Level14_848ECField(&Level14_848EC_D_80065920, unsigned short*,
                                        Level14_848ECField(privateRecord20, int*, 0) * 2)
                     << 0x10) >>
               0x16));
    phaseWord2 = Level14_848ECField(privateRecord20, int*, 0) + 4;
    Level14_848ECField(privateRecord20, int*, 0) = phaseWord2;
    ownerPosition18 = ownerRecord17 + 0xC;
    if (phaseWord2 < 0x101) {
        goto state0Interaction;
    }
    Level14_848ECField(privateRecord20, int*, 0) = 0;
    Level14_848ECField(ownerRecord17, int*, 0x14) =
        (int)Level14_848ECField(privateRecord20, int*, 4);
state0Interaction:
    if (Level14_848EC_func_8001C288(ownerPosition18, 0x1F4, 0) == 0) {
        goto returnToCaller;
    }
    argument7 = 0x10000480;
    MATCHING_KEEP(argument7);
    argument4 = ownerPosition18;
    scratchOrPlayer16 = &Level14_848EC_D_80070328 + 0x298;
    ownerByte6 = Level14_848ECField(ownerRecord17, unsigned char*, 0x46);
    MATCHING_OBSERVE(ownerByte6);
    word3 = Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x20C);
    __asm__("" : "=r"(word3) : "0"(word3), "r"(ownerByte6), "r"(argument4));
    word2 = 0x39;
    __asm__("" : "=r"(word3) : "0"(word3), "r"(word2));
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x23C) = word2;
    MATCHING_KEEP_CLOBBER(word3, "memory");
    word3 = word3 | argument7;
    MATCHING_KEEP_CLOBBER(word3, "memory");
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x298) = (int)ownerByte6;
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x20C) = word3;
    MATCHING_KEEP(scratchOrPlayer16);
    Level14_848ECField(ownerRecord17, unsigned char*, 0x45) = Level14_848ECPlanarHeadingLookup(
        Level14_848ECApproximatePlanarDistance(argument4, scratchOrPlayer16 - 0x298, ownerByte6,
                                               argument7),
        Level14_848ECField(&Level14_848EC_D_80070328, int*, 8) -
            Level14_848ECField(ownerRecord17, int*, 0x14),
        0);
    MATCHING_KEEP(scratchOrPlayer16);
    Level14_848ECField(ownerRecord17, unsigned char*, 0x46) =
        Level14_848ECPlanarHeadingLookup(Level14_848ECField(scratchOrPlayer16, int*, -0x298) -
                                             Level14_848ECField(ownerRecord17, int*, 0xC),
                                         Level14_848ECField(&Level14_848EC_D_80070328, int*, 4) -
                                             Level14_848ECField(ownerRecord17, int*, 0x10),
                                         0);
    Level14_848ECRefreshMobySpatialGridAndBasis(ownerRecord17, 4);
    scratch.sp10 = 0x64;
    scratch.sp14 = 0;
    scratch.sp18 = 0;
    Level14_848ECTransformVectorByBasis(ownerRecord17 + 0x20, &scratch.sp10, &scratch.sp10);
    argument4 = ownerPosition18;
    MATCHING_KEEP(argument4);
    word2 = scratch.sp10;
    word3 = scratch.sp14;
    argument6 = scratch.sp18;
    MATCHING_KEEP3(word2, word3, argument6);
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x21C) = word2;
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x220) = word3;
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x224) = argument6;
    Level14_848EC_func_8001A358(argument4, 0x2000, argument6);
    Level14_848EC_func_8005629C(ownerRecord17);
    Level14_848ECRefreshMobySpatialGridAndBasis(ownerRecord17, 2);
    Level14_848ECField(ownerRecord17, unsigned char*, 0x48) = 1U;
state1:
    Level14_848ECPlayMobySoundEvent(ownerRecord17, 0, 0);
    Level14_848ECField(ownerRecord17, unsigned char*, 0x49) = 0x14U;
    spawnedOwner2 = Level14_848EC_SpawnMoby(0x3F7, ownerRecord17);
    Level14_848ECField(privateRecord20, void***, 8) = spawnedOwner2;
    if (spawnedOwner2 == 0) {
        goto spawnFailed;
    }
    spawnedPrivate21 = *spawnedOwner2;
    firstCount16 = 0;
firstParticleLoop:
    word2 = Level14_848ECRandBetween(0, 0x400);
    argument4word = 0;
    argument5word = 0x400;
    word3 = Level14_848ECField(ownerRecord17, int*, 0xC);
    __asm__(""
            : "=r"(word3)
            : "0"(word3), "r"(firstCount16), "r"(argument4word), "r"(argument5word));
    firstCount16 += 1;
    word3 = word3 + word2;
    MATCHING_KEEP(word3);
    word3 = word3 - 0x200;
    __asm__("" : "=r"(word3) : "0"(word3), "r"(firstCount16));
    scratch.sp30 = word3;
    scratch.sp34 =
        (Level14_848ECField(ownerRecord17, int*, 0x10) + Level14_848ECRandBetween(0, 0x400)) -
        0x200;
    scratch.sp38 =
        (Level14_848ECField(ownerRecord17, int*, 0x14) + Level14_848ECRandBetween(0, 0x200)) -
        0x100;
    scratch.sp20 = Level14_848ECRandBetween(0, 0xC8) - 0x64;
    scratch.sp24 = Level14_848ECRandBetween(0, 0xC8) - 0x64;
    scratch.sp28 = Level14_848ECRandBetween(0x14, 0x50);
    Level14_848EC_SpawnParticle(1, 0x27, &scratch.sp30, &scratch.sp20);
    if (firstCount16 < 8) {
        goto firstParticleLoop;
    }
    /* Original first-loop branch delay initializes argument6, then the
     * radial counter and SP+0x30/SP+0x20 pointers are produced. */
    argument6 = 0;
    MATCHING_KEEP(argument6);
    radialCount18 = 0;
    /* SP+0x10 is the first scratch word in the original 0x80-byte frame.
     * The initialized SP role keeps these later pointer producers separate
     * from earlier particle arguments. The empty tied constraint emits no
     * instructions;
      every resulting native word and target is checked. */
    frameBase29 = (unsigned char*)&scratch.sp10 - 0x10;
    __asm__("" : "=r"(frameBase29) : "0"(frameBase29), "r"(radialCount18));
    scratchOrPlayer16 = frameBase29 + 0x30;
    scratchPointer19 = frameBase29 + 0x20;
    MATCHING_OBSERVE3(scratchOrPlayer16, scratchPointer19, argument6);

    Level14_848ECField(ownerRecord17, unsigned char*, 0x46) = Level14_848ECPlanarHeadingLookup(
        Level14_848EC_D_8006E020 - Level14_848ECField(ownerRecord17, int*, 0xC),
        Level14_848EC_D_8006E024 - Level14_848ECField(ownerRecord17, int*, 0x10), argument6);
radialParticleLoop:
    Level14_848ECField(ownerRecord17, signed char*, 0x44) = (signed char)(radialCount18 << 5);
    scratch.sp30 = 0;
    scratch.sp34 = 0x4E2;
    scratch.sp38 = 0;
    Level14_848ECRefreshMobySpatialGridAndBasis(ownerRecord17, 4);
    Level14_848ECTransformVectorByBasis(ownerRecord17 + 0x20, scratchOrPlayer16, scratchOrPlayer16);
    argument4 = scratchOrPlayer16;
    MATCHING_KEEP(argument4);
    MATCHING_KEEP(ownerRecord17);
    argument5 = ownerRecord17 + 0xC;
    MATCHING_KEEP(argument5);
    Level14_848ECAddVector(argument4, argument5, scratchOrPlayer16);
    Level14_848ECClearVector(scratchPointer19);
    firstParticle2 = Level14_848EC_SpawnParticle(1, 0xD, scratchOrPlayer16, scratchPointer19);
    if (firstParticle2 == 0) {
        goto radialParticleTail;
    }
    Level14_848ECField(firstParticle2, signed char*, 0xA) = 0x3C;
radialParticleTail:
    radialCount18 += 1;
    if (radialCount18 < 8) {
        goto radialParticleLoop;
    }
    MATCHING_KEEP_CLOBBER(ownerRecord17, "memory");
    argument4word = 0x10;
    argument5word = 0x46;
    pointer6 = ownerRecord17 + 0xC;
    argument7 = 0x20;
    __asm__(""
            : "=r"(pointer6)
            : "0"(pointer6), "r"(argument4word), "r"(argument5word), "r"(argument7));
    Level14_848ECField(spawnedPrivate21, short*, 2) = 0x190;
    Level14_848ECField(ownerRecord17, unsigned char*, 0x48) = 3U;
    particleCallback3 = Level14_848EC_SpawnParticle;
    MATCHING_KEEP_CLOBBER(particleCallback3, "memory");
    Level14_848ECField(ownerRecord17, int*, 8) = 0;
    Level14_848ECField(privateRecord20, int*, 0) = 0x3C;
    particleCallback3(argument4word, argument5word, pointer6, argument7);
    Level14_848ECField(ownerRecord17, signed char*, 0x41) = 0;
    Level14_848ECField(ownerRecord17, signed char*, 0x4C) = 0;
    Level14_848ECField(ownerRecord17, signed char*, 0x4D) = 0;
    return;
spawnFailed:
    Level14_848ECField(ownerRecord17, unsigned char*, 0x48) = 2U;
    Level14_848ECField(privateRecord20, int*, 0) = 0;
    return;
state3:
    spawnedOwner16 = Level14_848ECField(privateRecord20, void***, 8);
    spawnedPrivate18 = Level14_848ECField(spawnedOwner16, void**, 0);
    Level14_848ECCountTimerDown(privateRecord20, 4);
    if (Level14_848ECField(ownerRecord17, unsigned char*, 0x49) != 0xA) {
        goto state3Continue;
    }
    Level14_848ECField(ownerRecord17, unsigned char*, 0x48) = 2U;
    return;
state3Continue:
    Level14_848ECField(spawnedOwner16, unsigned char*, 0x46) = Level14_848ECPlanarHeadingLookup(
        Level14_848EC_D_8006E020 - Level14_848ECField(ownerRecord17, int*, 0xC),
        Level14_848EC_D_8006E024 - Level14_848ECField(ownerRecord17, int*, 0x10), 0);
    if (Level14_848ECField(spawnedPrivate18, short*, 0x14) >= 3) {
        goto state3SecondCounter;
    }
    Level14_848ECField(spawnedPrivate18, unsigned short*, 0) =
        (unsigned short)(Level14_848ECField(spawnedPrivate18, unsigned short*, 0) + 0x32);
state3SecondCounter:
    if (Level14_848ECField(spawnedPrivate18, short*, 0x14) >= 4) {
        goto state3ThirdCounter;
    }
    Level14_848ECField(spawnedPrivate18, unsigned short*, 0x16) =
        (unsigned short)(Level14_848ECField(spawnedPrivate18, unsigned short*, 0x16) + 0x32);
state3ThirdCounter:
    Level14_848ECField(spawnedPrivate18, unsigned short*, 2) =
        (unsigned short)(Level14_848ECField(spawnedPrivate18, unsigned short*, 2) + 0x64);
    if (Level14_848ECField(spawnedPrivate18, short*, 0x14) >= 7) {
        goto returnToCaller;
    }
    secondCount16 = 0;
secondParticleLoop:
    word2 = Level14_848ECRandBetween(0, 0x400);
    argument4word = 0;
    argument5word = 0x400;
    word3 = Level14_848ECField(ownerRecord17, int*, 0xC);
    __asm__(""
            : "=r"(word3)
            : "0"(word3), "r"(secondCount16), "r"(argument4word), "r"(argument5word));
    secondCount16 += 1;
    word3 = word3 + word2;
    MATCHING_KEEP(word3);
    word3 = word3 - 0x200;
    __asm__("" : "=r"(word3) : "0"(word3), "r"(secondCount16));
    scratch.sp40 = word3;
    scratch.sp44 =
        (Level14_848ECField(ownerRecord17, int*, 0x10) + Level14_848ECRandBetween(0, 0x400)) -
        0x200;
    scratch.sp48 =
        (Level14_848ECField(ownerRecord17, int*, 0x14) + Level14_848ECRandBetween(0, 0x200)) -
        0x100;
    scratch.sp50 = Level14_848ECRandBetween(0, 0xC8) - 0x64;
    scratch.sp54 = Level14_848ECRandBetween(0, 0xC8) - 0x64;
    scratch.sp58 = Level14_848ECRandBetween(0x14, 0x50);
    Level14_848EC_SpawnParticle(1, 0x27, &scratch.sp40, &scratch.sp50);
    if (secondCount16 < 2) {
        goto secondParticleLoop;
    }
    frameBase29 = (unsigned char*)&scratch.sp10 - 0x10;
    MATCHING_KEEP(frameBase29);
    scratchOrPlayer16 = frameBase29 + 0x40;
    MATCHING_OBSERVE(scratchOrPlayer16);
    Level14_848ECCopyVector(scratchOrPlayer16, ownerRecord17 + 0xC);
    word2 = Level14_848ECRandBetween(0, 0xC8);
    word3 = scratch.sp40;
    word3 = word3 - 0x64;
    __asm__("" : "=r"(word3) : "0"(word3), "r"(word2));
    word3 = word3 + word2;
    MATCHING_KEEP(word3);
    scratch.sp40 = word3;
    word2 = Level14_848ECRandBetween(0, 0xC8);
    argument4word = 0;
    argument5word = 0xC8;
    MATCHING_KEEP2(argument4word, argument5word);
    word3 = scratch.sp44;
    argument6 = scratch.sp48;
    MATCHING_KEEP2(word3, argument6);
    word3 = word3 - 0x64;
    MATCHING_KEEP(word3);
    word3 = word3 + word2;
    argument6 += 0xC8;
    scratch.sp44 = word3;
    scratch.sp48 = argument6;
    word2 = Level14_848ECRandBetween(argument4word, argument5word, argument6);
    scratch.sp50 = 0;
    scratch.sp54 = 0;
    scratch.sp58 = 0;
    word3 = scratch.sp48;
    MATCHING_KEEP_CLOBBER(word3, "memory");
    word3 = word3 - 0x64;
    MATCHING_KEEP(word3);
    word3 = word3 + word2;
    MATCHING_KEEP(word3);
    scratch.sp48 = word3;
    if (Level14_848ECField(spawnedPrivate18, short*, 0x14) >= 4) {
        goto selector13;
    }
    argument4word = 1;
    MATCHING_KEEP(argument4word);
    particleSelector5 = 0;
    goto spawnSelectedParticle;
selector13:
    argument4word = 1;
    MATCHING_KEEP(argument4word);
    particleSelector5 = 0xD;
    MATCHING_KEEP(particleSelector5);
spawnSelectedParticle:
    secondParticle2 = Level14_848EC_SpawnParticle(argument4word, particleSelector5,
                                                  scratchOrPlayer16, &scratch.sp50);
    if (secondParticle2 == 0) {
        goto returnToCaller;
    }
    Level14_848ECField(secondParticle2, signed char*, 0xA) = 0x64;
    return;
state2:
    argument6 = 0x10000002;
    MATCHING_KEEP(argument6);
    Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x20C) =
        Level14_848ECField(&Level14_848EC_D_80070328, int*, 0x20C) | argument6;
    if (Level14_848ECCountTimerDown(privateRecord20, 4, argument6) == 0) {
        goto returnToCaller;
    }
    tableOffset3 = Level14_848EC_D_8006C58C * 6;
    tableByte4 = *(&Level14_848EC_D_800716B0 + tableOffset3);
    if (tableByte4 >= 0xFFU) {
        goto state2Tail;
    }
    *(&Level14_848EC_D_800716B0 + tableOffset3) = tableByte4 + 1;
state2Tail:
    Level14_848EC_func_8003B74C(&Level14_848EC_D_8006D088);
returnToCaller:
    return;
}
#undef Level14_848ECField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
int State455Helper2803Raw() __asm__("func_8002803C");
extern int State455Global572 __asm__("D_80070328 + 0x23C");
extern int State455Global524 __asm__("D_80070328 + 0x20C");
extern int State455Global540 __asm__("D_80070328 + 0x21C");
extern int State455Global548 __asm__("D_80070328 + 0x224");
extern int State455Global544 __asm__("D_80070328 + 0x220");
extern int State455Global640 __asm__("D_80070328 + 0x280");
extern int State455Global180 __asm__("D_80070328 + 0xB4");
extern int State455Global172 __asm__("D_80070328 + 0xAC");
extern int State455Global244 __asm__("D_80070328 + 0xF4");
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_80084FD0.s SHA256 7cb59eb19122765578ecb043186b877f2efbd6fcfcf1c20b7144ba0adceba249. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define State455Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int State455_func_8001A358() __asm__("func_8001A358");
/* extern */
short** State455_func_8001BA30() __asm__("func_8001BA30");
/* extern */
/* extern */
unsigned char State455_func_80028154() __asm__("func_80028154");
/* extern */
unsigned char State455RequestMobyAnimation() __asm__("func_80034F40");
/* extern */
unsigned char State455SetMobyAnimation() __asm__("func_80034F80");
/* extern */
int State455CountTimerDown() __asm__("func_800359A4");
/* extern */
int State455PlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned char State455_func_8003BE70() __asm__("func_8003BE70");
/* extern */
int State455_func_8003BFC0() __asm__("func_8003BFC0");
/* extern */
unsigned char State455_func_8003C0B0() __asm__("func_8003C0B0");
/* extern */
unsigned char State455_func_8003C140() __asm__("func_8003C140");
/* extern */
unsigned char State455TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
unsigned char State455AddVector() __asm__("func_8004F194");
/* extern */
unsigned char State455DeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned char State455RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int State455_func_80055E84() __asm__("func_80055E84");
/* extern */
extern unsigned char State455_D_800658A0 __asm__("D_800658A0");
extern unsigned char State455_D_80065920 __asm__("D_80065920");
extern int State455_D_8006C550 __asm__("D_8006C550");
extern int State455_D_8006C770 __asm__("D_8006C770");
extern int State455_D_8006E538 __asm__("D_8006E538");
extern unsigned char State455_D_80070328 __asm__("D_80070328");
extern int State455_D_80071934 __asm__("D_80071934");
extern short** (*State455_SpawnMoby)() __asm__("SpawnMoby");
extern unsigned char (*State455_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char State455_func_80027A60 __asm__("func_80027A60");
extern unsigned char State455_func_80027E40 __asm__("func_80027E40");
extern unsigned char State455_func_80029904 __asm__("func_80029904");
extern int (*State455_unk_ovlheader_80074330)() __asm__("unk_ovlheader_80074330");

void func_level_14_80084FD0(void* owner18) {
    /* Original 0x80-byte frame: scratch SP+0x20..0x67,
     * saved registers SP+0x68..0x78;
      final alignment through 0x7F.
     * Owner/storage address additions retain original byte offsets.
     * Samples are signed LH values;
      the product is shifted right by 11.
     * Bounds below operate on signed 16-bit values after each original SH.
     * The raw helper result is narrowed by SLL16/SRA16 after flagsWord5.
     * Spawn symbols are read as pointer data and called with JALR here.
     * Initialized empty constraints preserve producers and reload ordering.
     * Helper meanings, units/fixed-point domains and frame cadence are unknown. */
    struct {
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        unsigned char sp30;
        unsigned char pad31[55];
    } originalFrame;

    short** storageRecord10;
    short** storageRecord14;
    short** childRecord16;
    short** spawnedRecord16;
    short* storage17;
    register int temp_a0 __asm__("$4");
    register int temp_a0_2 __asm__("$4");
    int storageHalf0;
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int flagsWord5 __asm__("$5");
    register int* flagsPointer4 __asm__("$4");
    register int* playerWordB4Address19 __asm__("$19");
    register int rawWord4 __asm__("$4");
    int groundResult;
    int storageWord8;
    register int state3 __asm__("$3");

    state3 = State455Field(owner18, unsigned char*, 0x48);
    storage17 = State455Field(owner18, short**, 0);
    switch (state3) {
        case 0:
            State455Field(storage17, short*, 0x26) = 0x1000;
            State455Field(storage17, short*, 0x24) = 0;
            State455Field(storage17, int*, 0x20) = -1;
            State455_D_80071934 = 0;
            groundResult = State455_func_8001A358(owner18 + 0xC, 0x800);
            State455Field(owner18, int*, 0x14) = groundResult;
            State455Field(owner18, int*, 0x54) = (int)((-groundResult & 0xFFFFFF) | 0x80000000);
            State455Field(owner18, unsigned char*, 0x48) = 1U;
            return;
        case 2:
            if (State455_unk_ovlheader_80074330(
                    owner18 + 0xC, State455Field(owner18, unsigned char*, 0x46), 0) != 0) {
                rawWord2 = State455Helper2803Raw(0x17, 0x8D, &State455_func_80027E40,
                                                 &State455_func_80027A60, &State455_func_80029904,
                                                 (unsigned char*)storage17 + 8, 0x63);
                flagsWord5 = 0x10000080;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(flagsWord5) : "$4");
                rawWord2 = (rawWord2 << 16) >> 16;
                flagsPointer4 = &State455Global524;
                MATCHING_KEEP(flagsPointer4);
                State455Field(storage17, int*, 4) = rawWord2;
                rawWord3 = *flagsPointer4;
                rawWord2 = 0x3C;
                State455Global572 = rawWord2;
                rawWord2 = 3;
                State455Field(&State455_D_80070328, short***, 0x250) = owner18;
                rawWord3 |= flagsWord5;
                *flagsPointer4 = rawWord3;
                State455Field(owner18, unsigned char*, 0x48) = rawWord2;
                rawWord2 = *flagsPointer4;
                rawWord2 |= 0x400;
                *flagsPointer4 = rawWord2;
                State455Global540 =
                    (int)((int)(State455Field(&State455_D_80065920, short*,
                                              State455Field(owner18, unsigned char*, 0x46) * 2) *
                                0x19) >>
                          0xB);
                rawWord3 = State455Field(&State455_D_800658A0, short*,
                                         State455Field(owner18, unsigned char*, 0x46) * 2);
                MATCHING_KEEP_VOLATILE_CLOBBER(rawWord3, "memory");
                State455Global548 = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(rawWord3, "memory");
                State455Global544 = (rawWord3 * 25) >> 11;
                State455Field(storage17, short*, 0xC) = 1;
                return;
            }
        default:
            return;
        case 3:
            childRecord16 = State455_func_8001BA30(owner18 + 0xC, 0x44C, 3, 0, 0, owner18);
            if (childRecord16 != 0) {
                if (State455Field(childRecord16, short*, 0x36) == 0x214) {
                    State455Field(childRecord16, signed char*, 0x48) = 1;
                    State455PlayMobySoundEvent(childRecord16, 0, 0);
                    *State455Field(childRecord16, short**, 0) = 0x1F4;
                    if (State455Field(childRecord16, unsigned char*, 0x49) == 0xA) {
                        storageWord8 = State455Field(storage17, int*, 8) + 5;
                    } else {
                        storageWord8 = State455Field(storage17, int*, 8) + 3;
                    }
                    State455Field(storage17, int*, 8) = storageWord8;
                    MATCHING_BARRIER_VOLATILE("memory");
                    if (State455Field(storage17, int*, 8) >= 0x64) {
                        State455Field(storage17, int*, 8) = 0x63;
                    }
                }
            }
            if ((State455CountTimerDown(storage17, 2) != 0) && (State455Global640 >= 0) &&
                (State455_D_8006E538 & 0x20)) {
                if (State455Field(storage17, int*, 8) == 0) {
                    State455PlayMobySoundEvent(owner18, 1, 0);
                    storageHalf0 = 0x1E;
                } else {
                    State455SetMobyAnimation(owner18, 2);
                    storageHalf0 = 0x32;
                }
                State455Field(storage17, short*, 0) = storageHalf0;
            }
            if (State455Field(owner18, unsigned short*, 0x3C) == 0x202) {
                if ((State455_func_80055E84(owner18) >= 0xD) &&
                    (State455Field(owner18, unsigned char*, 0x49) == 0)) {
                    spawnedRecord16 = State455_SpawnMoby(0x216, owner18);
                    if (spawnedRecord16 != 0) {
                        State455PlayMobySoundEvent(spawnedRecord16, 0, 0);
                        State455Field(*spawnedRecord16, int*, 8) =
                            (int)(State455_D_8006C550 +
                                  (State455Field(storage17, int*, 0x18) * 0x58));
                        State455Field(owner18, unsigned char*, 0x49) = 1U;
                        State455Field(storage17, int*, 8) =
                            (int)(State455Field(storage17, int*, 8) - 1);
                    }
                }
                if (State455_D_8006C770 != 0) {
                    State455Field(owner18, unsigned char*, 0x49) = 0U;
                    State455RequestMobyAnimation(owner18, 0);
                }
            }
            playerWordB4Address19 = &State455Global180;
            MATCHING_KEEP(playerWordB4Address19);
            if (*playerWordB4Address19 != 0) {
                State455RefreshMobySpatialGridAndBasis(owner18, 4);
                originalFrame.sp20 = -0x1F4;
                originalFrame.sp24 = 0;
                originalFrame.sp28 = 0;
                State455TransformVectorByBasis(owner18 + 0x20, &originalFrame.sp20,
                                               &originalFrame.sp20);
                State455AddVector(&originalFrame.sp30, owner18 + 0xC, &originalFrame.sp20);
                State455_SpawnParticle(1, 0x2E, &originalFrame.sp30, 0x32);
            }
            if (State455Global172 != 0) {
                rawWord2 = State455Field(storage17, short*, 0x24);
                MATCHING_KEEP(rawWord2);
                rawWord3 = rawWord2;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                if (rawWord2 < 0x1000) {
                    rawWord2 = rawWord3 + 0x100;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    State455Field(storage17, short*, 0x24) = rawWord2;
                }
                if (State455_func_8003BFC0(owner18, State455Field(storage17, int*, 0x20)) == 0) {
                    State455Field(storage17, int*, 0x20) =
                        State455PlayMobySoundEvent(owner18, 0, 4);
                }
                if (State455_func_8003BFC0(owner18, State455Field(storage17, int*, 0x20)) != 0) {
                    State455_func_8003C140(State455Field(storage17, int*, 0x20),
                                           State455Field(storage17, short*, 0x24));
                    rawWord2 = State455Global172;
                    if (rawWord2 < 0x1389)
                        goto activeLow455;
                    rawWord2 = *playerWordB4Address19;
                    if (rawWord2 >= 0x800)
                        goto activeHigh455;
                    rawWord4 = State455Field(storage17, short*, 0x26);
                    MATCHING_KEEP(rawWord4);
                    rawWord3 = rawWord4;
                    if (rawWord4 >= 0x1000)
                        goto activeOver455;
                    rawWord2 = rawWord3 + 0x80;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    State455Field(storage17, short*, 0x26) = rawWord2;
                    rawWord2 = (rawWord2 << 16) >> 16;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 < 0x1001)
                        goto activeDone455;
                    rawWord2 = 0x1000;
                    goto activeStore455;
                activeOver455:
                    rawWord2 = rawWord4 < 0x1001;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2)
                        goto activeDone455;
                    rawWord2 = rawWord3 - 0x80;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    State455Field(storage17, short*, 0x26) = rawWord2;
                    rawWord2 = (rawWord2 << 16) >> 16;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 >= 0x1000)
                        goto activeDone455;
                    rawWord2 = 0x1000;
                    State455Field(storage17, short*, 0x26) = rawWord2;
                    goto activeDone455;
                activeHigh455:
                    rawWord2 = State455Field(storage17, short*, 0x26);
                    MATCHING_KEEP(rawWord2);
                    rawWord3 = rawWord2;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    if (rawWord2 >= 0x1B58)
                        goto activeDone455;
                    rawWord2 = rawWord3 + 0x100;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    State455Field(storage17, short*, 0x26) = rawWord2;
                    rawWord2 = (rawWord2 << 16) >> 16;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 < 0x1B59)
                        goto activeDone455;
                    rawWord2 = 0x1B58;
                    State455Field(storage17, short*, 0x26) = rawWord2;
                    goto activeDone455;
                activeLow455:
                    rawWord2 = State455Field(storage17, short*, 0x26);
                    MATCHING_KEEP(rawWord2);
                    rawWord3 = rawWord2;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    if (rawWord2 < 0x801)
                        goto activeDone455;
                    rawWord2 = rawWord3 - 0x80;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                    State455Field(storage17, short*, 0x26) = rawWord2;
                    rawWord2 = (rawWord2 << 16) >> 16;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 >= 0x800)
                        goto activeDone455;
                    rawWord2 = 0x800;
                activeStore455:
                    MATCHING_KEEP(rawWord2);
                    State455Field(storage17, short*, 0x26) = rawWord2;
                activeDone455:;
                    State455_func_8003C0B0(State455Field(storage17, int*, 0x20),
                                           State455Field(storage17, short*, 0x26));
                }
            } else if (State455Field(storage17, short*, 0x24) > 0) {
                rawWord4 = State455Field(storage17, short*, 0x26);
                MATCHING_KEEP(rawWord4);
                rawWord3 = rawWord4;
                if (rawWord4 >= 0x1000)
                    goto passiveOver455;
                rawWord2 = rawWord3 + 0x80;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                State455Field(storage17, short*, 0x26) = rawWord2;
                rawWord2 = (rawWord2 << 16) >> 16;
                MATCHING_KEEP(rawWord2);
                if (rawWord2 < 0x1001)
                    goto passiveDone455;
                rawWord2 = 0x1000;
                goto passiveStore455;
            passiveOver455:
                rawWord2 = rawWord4 < 0x1001;
                MATCHING_KEEP(rawWord2);
                if (rawWord2)
                    goto passiveDone455;
                rawWord2 = rawWord3 - 0x80;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3));
                State455Field(storage17, short*, 0x26) = rawWord2;
                rawWord2 = (rawWord2 << 16) >> 16;
                MATCHING_KEEP(rawWord2);
                if (rawWord2 >= 0x1000)
                    goto passiveDone455;
                rawWord2 = 0x1000;
            passiveStore455:
                MATCHING_KEEP(rawWord2);
                State455Field(storage17, short*, 0x26) = rawWord2;
            passiveDone455:;
                State455_func_8003C0B0(State455Field(storage17, int*, 0x20),
                                       State455Field(storage17, short*, 0x26));
                State455_func_8003C140(State455Field(storage17, int*, 0x20),
                                       State455Field(storage17, short*, 0x24));
                rawWord2 = State455Field(storage17, unsigned short*, 0x24);
                rawWord2 -= 0x100;
                State455Field(storage17, short*, 0x24) = rawWord2;
                rawWord2 <<= 16;
                if (rawWord2 < 0) {
                    State455Field(storage17, short*, 0x24) = 0;
                }
            } else if (State455_func_8003BFC0(owner18, State455Field(storage17, int*, 0x20)) != 0) {
                State455_func_8003BE70(State455Field(storage17, int*, 0x20));
                State455Field(storage17, int*, 0x20) = -1;
            }
            if (State455Global244 != 0) {
                State455Field(owner18, int*, 0x54) =
                    (int)((-State455Global244 & 0xFFFFFF) | 0x80000000);
                return;
            }
            break;
        case 4:
            State455_func_80028154(State455Field(storage17, int*, 4));
            storageRecord10 = State455Field(storage17, short***, 0x10);
            if (storageRecord10 != 0) {
                State455DeleteMoby(storageRecord10);
                State455Field(storage17, short***, 0x10) = 0;
            }
            storageRecord14 = State455Field(storage17, short***, 0x14);
            if (storageRecord14 != 0) {
                State455DeleteMoby(storageRecord14);
                State455Field(storage17, short***, 0x14) = 0;
            }
            State455DeleteMoby(owner18);
            break;
        case 1:
            goto rawExit455;
    }
rawExit455:
    MATCHING_BARRIER_VOLATILE("memory");
}
#undef State455Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800856EC.
* Assembly SHA256 12f640aa24e3b7e3e16b7c8211846c3ae5eeb6568e84b95ca6aa1e37c3fc2e10.
* AI generated; not human reviewed. All648 instructions,eight selectors
* and actual targets are required. Frame0x90 retains S0..S5/RA and full
* SP20..6F local extent. Incoming A0 reaches the initial helper unchanged.
* The original state0 selector returns;it does not enter the common tail.
* Early states3/6/0 preserve the incoming state at the original dispatch
* join;the other paths reload it. Shared collision/contact/deletion code
* stays in its original physical position. Returned record addresses remain
* live in their original S0/V1/A0 domains while calls overwrite V0. Original
* signed halfwords,low-word trig products,byte fields,literal5,vector extents,
* both repeated spawn groups and all state/control destinations remain exact.
* Initialized empty identities,late consumers and dead clobbers emit zero
* CPU instructions. No opcode assembly,partialHI,FP shortcut or overlapping
* live aliases. Confidence is binary identity after all gates. Raw units/
* fixed point,full helper contracts,caller cadence and synchronized runtime
* remain open. Cadence is per invocation. Falsification:every native/linked
* word,actual transfer/table target,owned data byte,EXE and all overlay hashes. */
#define Actor14_856ECField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor14_856ECCall19194View1() __asm__("func_80019194");
int Actor14_856ECCall1A310View1() __asm__("func_8001A310");
void* Actor14_856ECCall1BA30View1() __asm__("func_8001BA30");
int Actor14_856ECCall1C288View1() __asm__("func_8001C288");
int Actor14_856ECCountTimerDownView1() __asm__("func_800359A4");
int Actor14_856ECRandBetweenView1() __asm__("func_8003636C");
int Actor14_856ECCall368A4View1() __asm__("func_800368A4");
int Actor14_856ECCall369B8View1() __asm__("func_800369B8");
void* Actor14_856ECCall391E8View1() __asm__("func_800391E8");
int Actor14_856ECCall39714View1() __asm__("func_80039714");
int Actor14_856ECPlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor14_856ECCall3BE70View1() __asm__("func_8003BE70");
int Actor14_856ECCall3BFC0View1() __asm__("func_8003BFC0");
int Actor14_856ECPlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor14_856ECTransformVectorByBasisView1() __asm__("func_8004ED6C");
int Actor14_856ECMeasureVectorLengthView1() __asm__("func_8004EDE8");
int Actor14_856ECScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Actor14_856ECCopyVectorView1() __asm__("func_8004F178");
int Actor14_856ECAddVectorView1() __asm__("func_8004F194");
int Actor14_856ECAbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor14_856ECDeleteMobyView1() __asm__("func_80055B18");
int Actor14_856ECRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Actor14_856ECData658A0View1 __asm__("D_800658A0");
extern int Actor14_856ECData65920View1 __asm__("D_80065920");
extern int Actor14_856ECData6C574View1 __asm__("D_8006C574");
extern int Actor14_856ECData6C578View1 __asm__("D_8006C578");
extern int Actor14_856ECData70328View1 __asm__("D_80070328");
extern int Actor14_856ECData71908View1 __asm__("D_80071908");
extern void* (*Actor14_856ECDataSpawnMobyView1)() __asm__("SpawnMoby");
extern void* (*Actor14_856ECDataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_14_800856EC(void* input) {
    register void* ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int angleCounterOrAddress16 __asm__("$16"), counterLiteralOrAddress17 __asm__("$17"),
        privateAddressOrLiteral200 __asm__("$19"), contactFlagOrLiteral20 __asm__("$20"),
        contactEnabled21 __asm__("$21");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C;
    } originalFrame;
    argumentWord4 = (int)input;
    ownerRecord18 = (void*)argumentWord4;
    MATCHING_KEEP(ownerRecord18);
    contactFlagOrLiteral20 = 0;
    contactEnabled21 = 0;
    privateAddressOrLiteral200 = Actor14_856ECField(ownerRecord18, int**, 0);
    Actor14_856ECRefreshMobySpatialGridAndBasisView1(argumentWord4, 7);
    rawWord3 = Actor14_856ECField(ownerRecord18, unsigned char*, 0x48);
    rawWord2 = 3;
    if (rawWord3 == rawWord2)
        goto dispatchOriginalOrReloadedState;
    rawWord2 = 6;
    if (rawWord3 == rawWord2)
        goto dispatchOriginalOrReloadedState;
    if (!rawWord3)
        goto dispatchOriginalOrReloadedState;
    rawWord2 = 4;
    if (rawWord3 == rawWord2)
        goto updateIncomingContact;
    if ((Actor14_856ECField(ownerRecord18, int*, 0x18) & 0x60000) == 0x20000) {
        argumentWord6 = Actor14_856ECField(&Actor14_856ECData70328View1, unsigned char*, 0xE) * 2;
        originalFrame.sp20 =
            (int)(Actor14_856ECField(&Actor14_856ECData65920View1, short*, argumentWord6) * 0x4B) >>
            0xA;
        argumentWord6 = Actor14_856ECField(&Actor14_856ECData658A0View1, short*, argumentWord6);
        originalFrame.sp28 = 0xC8;
        originalFrame.sp24 = (int)(argumentWord6 * 0x4B) >> 0xA;
        Actor14_856ECCopyVectorView1(privateAddressOrLiteral200, &originalFrame.sp20,
                                     argumentWord6);
        Actor14_856ECField(ownerRecord18, unsigned char*, 0x44) =
            (unsigned char)(Actor14_856ECField(ownerRecord18, unsigned char*, 0x44) +
                            (Actor14_856ECRandBetweenView1(0, 6) - 3));
        Actor14_856ECField(privateAddressOrLiteral200, short*, 0xC) = 0x96;
        Actor14_856ECField(ownerRecord18, unsigned char*, 0x48) = 4U;
    } else {
    updateIncomingContact:
        if (Actor14_856ECField(ownerRecord18, unsigned char*, 0x48) != 0) {
            Actor14_856ECField(ownerRecord18, signed char*, 0x4F) = 0x1A;
        }
        if (Actor14_856ECField(ownerRecord18, int*, 0x18) & 0x40000) {
            contactFlagOrLiteral20 = 1;
        }
        Actor14_856ECField(privateAddressOrLiteral200, int*, 0x10) = Actor14_856ECCall368A4View1(
            ownerRecord18, Actor14_856ECField(privateAddressOrLiteral200, int*, 0x10), 2);
        Actor14_856ECField(ownerRecord18, int*, 0x18) = 0;
    }
    rawWord3 = Actor14_856ECField(ownerRecord18, unsigned char*, 0x48);
dispatchOriginalOrReloadedState:
    switch (rawWord3) {
        case 0:
            return;
        case 1:
            contactEnabled21 = 1;
            if (Actor14_856ECField(ownerRecord18, int*, 12) < 1024 ||
                Actor14_856ECField(ownerRecord18, int*, 16) < 1024 ||
                Actor14_856ECField(ownerRecord18, int*, 20) < 1024)
                goto markState1Contact;
            rawWord2 = Actor14_856ECCountTimerDownView1(privateAddressOrLiteral200 + 12, 2);
            argumentWord4 = (int)ownerRecord18 + 12;
            if (!rawWord2)
                goto integrateState1;
        markState1Contact:
            contactFlagOrLiteral20 = 1;
            argumentWord4 = (int)ownerRecord18 + 12;
        integrateState1:
            Actor14_856ECAddVectorView1(argumentWord4, argumentWord4, privateAddressOrLiteral200);
            rawWord3 = Actor14_856ECField(privateAddressOrLiteral200, short*, 14);
            rawWord2 = Actor14_856ECField(privateAddressOrLiteral200, int*, 8);
            rawWord2 -= rawWord3;
            Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = rawWord2;
            if ((Actor14_856ECField(privateAddressOrLiteral200, int*, 0) != 0) ||
                (Actor14_856ECField(privateAddressOrLiteral200, int*, 4) != 0)) {
                Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) =
                    (unsigned char)(Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) + 4);
            }
            if (Actor14_856ECField(privateAddressOrLiteral200, int*, 8) < -0x1F2) {
                Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = -0x1F2;
            }
            counterLiteralOrAddress17 = ownerRecord18 + 0xC;
            if (Actor14_856ECCall1A310View1(counterLiteralOrAddress17, 0x1F4, 3, 0) != 0) {
                Actor14_856ECScaleVectorRatioQ15View1(
                    privateAddressOrLiteral200,
                    Actor14_856ECMeasureVectorLengthView1(privateAddressOrLiteral200, 0), 0x64);
                argumentWord4 = (int)ownerRecord18;
                argumentWord5 = 1;
                argumentWord6 = 0;
                MATCHING_OBSERVE3_CLOBBER(argumentWord4, argumentWord5, argumentWord6, "$2");
                rawWord2 = 50;
                angleCounterOrAddress16 = (int)&Actor14_856ECData71908View1;
                MATCHING_KEEP(angleCounterOrAddress16);
                Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = rawWord2;
                rawWord2 = Actor14_856ECField(angleCounterOrAddress16, int*, 0);
                rawWord3 = 7;
                Actor14_856ECField(ownerRecord18, unsigned char*, 0x48) = rawWord3;
                rawWord2 += 400;
                Actor14_856ECField(ownerRecord18, int*, 0x14) = rawWord2;
                Actor14_856ECPlayMobySoundEventView1(argumentWord4, argumentWord5, argumentWord6);
                Actor14_856ECCopyVectorView1(&originalFrame.sp20, counterLiteralOrAddress17);
                Actor14_856ECField(ownerRecord18, int*, 0x14) =
                    Actor14_856ECField(angleCounterOrAddress16, int*, 0);
                Actor14_856ECCall369B8View1(ownerRecord18, 0x28);
                Actor14_856ECCall369B8View1(ownerRecord18, 0x28);
                Actor14_856ECCall369B8View1(ownerRecord18, 0x28);
                Actor14_856ECCopyVectorView1(counterLiteralOrAddress17, &originalFrame.sp20);
            }
        default:
            goto runContactAndDeletionTail;
        case 7:
            counterLiteralOrAddress17 = 0;
            contactEnabled21 = 1;
            if (Actor14_856ECField(ownerRecord18, int*, 12) < 1024 ||
                Actor14_856ECField(ownerRecord18, int*, 16) < 1024 ||
                Actor14_856ECField(ownerRecord18, int*, 20) < 1024)
                goto markState7Contact;
            rawWord2 = Actor14_856ECCountTimerDownView1(privateAddressOrLiteral200 + 12, 2);
            argumentWord4 = (int)ownerRecord18 + 12;
            if (!rawWord2)
                goto integrateState7;
        markState7Contact:
            contactFlagOrLiteral20 = 1;
            argumentWord4 = (int)ownerRecord18 + 12;
        integrateState7:
            Actor14_856ECAddVectorView1(argumentWord4, argumentWord4, privateAddressOrLiteral200);
            if (Actor14_856ECField(privateAddressOrLiteral200, int*, 0))
                goto advanceState7Byte;
            rawWord2 = Actor14_856ECField(privateAddressOrLiteral200, int*, 4);
            argumentWord4 = (int)ownerRecord18 + 12;
            if (!rawWord2)
                goto checkState7Surface;
        advanceState7Byte:
            rawWord2 = Actor14_856ECField(ownerRecord18, unsigned char*, 0x45);
            rawWord2 += 4;
            Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) = rawWord2;
            MATCHING_KEEP_GNU_VOLATILE(ownerRecord18);
            argumentWord4 = (int)ownerRecord18 + 12;
        checkState7Surface:
            if ((Actor14_856ECCall1A310View1(argumentWord4, 0xFA, 3, 0) != 0) &&
                (Actor14_856ECField(privateAddressOrLiteral200, int*, 8) < 0)) {
                Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = 0;
                Actor14_856ECField(ownerRecord18, int*, 0x14) =
                    (int)(Actor14_856ECData71908View1 + 0x190);
                Actor14_856ECPlayMobySoundEventView1(ownerRecord18, 1, 0);
                if ((Actor14_856ECField(privateAddressOrLiteral200, int*, 0) != 0) ||
                    (Actor14_856ECField(privateAddressOrLiteral200, int*, 4) != 0) ||
                    (Actor14_856ECField(privateAddressOrLiteral200, int*, 8) != 0)) {
                    Actor14_856ECField(ownerRecord18, unsigned char*, 0x48) = 2U;
                } else {
                    Actor14_856ECField(ownerRecord18, unsigned char*, 0x48) = 0U;
                }
            } else {
                counterLiteralOrAddress17 = 1;
            }
            Actor14_856ECCopyVectorView1(&originalFrame.sp30, ownerRecord18 + 0xC);
            originalFrame.sp38 += 0x258;
            if ((Actor14_856ECCall19194View1(&originalFrame.sp30, 0x1F4) != 0) ||
                (Actor14_856ECCall1BA30View1(&originalFrame.sp30, 0x1F4, 3, 0, 0x40000,
                                             ownerRecord18) != 0)) {
                contactFlagOrLiteral20 = 1;
            }
            if (counterLiteralOrAddress17 != 0) {
                Actor14_856ECField(ownerRecord18, int*, 0x14) =
                    (int)(Actor14_856ECField(ownerRecord18, int*, 0x14) +
                          Actor14_856ECField(privateAddressOrLiteral200, int*, 8));
                rawWord2 = Actor14_856ECField(privateAddressOrLiteral200, int*, 8) - 0xD;
                Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = rawWord2;
                if (rawWord2 < -0xF8) {
                    Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = -0xF8;
                }
            }
            goto runContactAndDeletionTail;
        case 2:
            contactEnabled21 = 1;
            rawWord2 = Actor14_856ECCall3BFC0View1(
                ownerRecord18, Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14));
            angleCounterOrAddress16 = (int)ownerRecord18 + 12;
            if (!rawWord2) {
                MATCHING_BARRIER_GNU_VOLATILE("$2");
                Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14) =
                    Actor14_856ECPlayMobySoundEventView1(ownerRecord18, 0, 4);
                MATCHING_KEEP_GNU_VOLATILE(ownerRecord18);
                angleCounterOrAddress16 = (int)ownerRecord18 + 12;
            }
            Actor14_856ECAddVectorView1(angleCounterOrAddress16, angleCounterOrAddress16,
                                        privateAddressOrLiteral200);
            Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) =
                (unsigned char)(Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) + 4);
            if (Actor14_856ECCall1A310View1(angleCounterOrAddress16, 0x1F4, 3, 0) != 0) {
                Actor14_856ECField(ownerRecord18, int*, 0x14) =
                    (int)(Actor14_856ECData71908View1 + 0x190);
            } else {
                Actor14_856ECField(privateAddressOrLiteral200, int*, 8) = 0;
                Actor14_856ECField(ownerRecord18, unsigned char*, 0x48) = 1U;
                if (Actor14_856ECCall3BFC0View1(
                        ownerRecord18,
                        Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14)) != 0) {
                    Actor14_856ECCall3BE70View1(
                        Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14));
                    Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14) = -1;
                }
            }
            Actor14_856ECCopyVectorView1(&originalFrame.sp40, ownerRecord18 + 0xC);
            originalFrame.sp48 += 0x258;
            if (Actor14_856ECField(ownerRecord18, int*, 12) < 1024 ||
                Actor14_856ECField(ownerRecord18, int*, 16) < 1024 ||
                Actor14_856ECField(ownerRecord18, int*, 20) < 1024 ||
                Actor14_856ECCountTimerDownView1(privateAddressOrLiteral200 + 12, 2))
                goto markContact;
            rawWord2 = Actor14_856ECCall19194View1(&originalFrame.sp40, 500);
            argumentWord4 = (int)&originalFrame.sp40;
            if (rawWord2)
                goto markContact;
            argumentWord5 = 500;
            goto checkSharedCollision;
        case 3:
            MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
            Actor14_856ECField(ownerRecord18, int*, 8) = 0;
            Actor14_856ECCall39714View1(ownerRecord18);
            return;
        case 4:
            if (Actor14_856ECCountTimerDownView1(privateAddressOrLiteral200 + 0xC, 2) != 0) {
                contactFlagOrLiteral20 = 1;
            }
            angleCounterOrAddress16 = (int)ownerRecord18 + 12;
            Actor14_856ECAddVectorView1(angleCounterOrAddress16, angleCounterOrAddress16,
                                        privateAddressOrLiteral200);
            Actor14_856ECField(privateAddressOrLiteral200, int*, 8) =
                (int)(Actor14_856ECField(privateAddressOrLiteral200, int*, 8) - 0x10);
            Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) =
                (unsigned char)(Actor14_856ECField(ownerRecord18, unsigned char*, 0x45) + 4);
            Actor14_856ECCopyVectorView1(&originalFrame.sp50, angleCounterOrAddress16);
            originalFrame.sp58 += 0x15E;
            argumentWord4 = &originalFrame.sp50;
            if (Actor14_856ECCall19194View1(&originalFrame.sp50, 0x1C2) != 0)
                goto markContact;
            argumentWord4 = (int)&originalFrame.sp50;
            argumentWord5 = 0x1F4;
        checkSharedCollision:
            if (Actor14_856ECCall1BA30View1(argumentWord4, argumentWord5, 3, 0, 0x40000,
                                            ownerRecord18) == 0)
                goto runContactAndDeletionTail;
        case 5:
        markContact:
            contactFlagOrLiteral20 = 1;
            goto runContactAndDeletionTail;
        case 6:
            Actor14_856ECField(ownerRecord18, int*, 8) = 0;
            originalFrame.sp60 = 0;
            originalFrame.sp64 = 0x96;
            originalFrame.sp68 = 0;
            contactFlagOrLiteral20 = 5;
            if (Actor14_856ECField(privateAddressOrLiteral200, short*, 12) ==
                contactFlagOrLiteral20) {
                originalFrame.sp64 = 0x2BC;
            }
            Actor14_856ECRefreshMobySpatialGridAndBasisView1(ownerRecord18, 4);
            Actor14_856ECTransformVectorByBasisView1(ownerRecord18 + 0x20, &originalFrame.sp60,
                                                     &originalFrame.sp60);
            angleCounterOrAddress16 = ownerRecord18 + 0xC;
            Actor14_856ECAddVectorView1(angleCounterOrAddress16, angleCounterOrAddress16,
                                        &originalFrame.sp60);
            originalFrame.sp60 = 0;
            originalFrame.sp64 = 0;
            rawWord3 = Actor14_856ECField(privateAddressOrLiteral200, short*, 12);
            rawWord3 = contactFlagOrLiteral20 - rawWord3;
            rawWord2 = -(rawWord3 * 6);
            originalFrame.sp68 = rawWord2;
            rawWord2 = Actor14_856ECDataSpawnParticleView1(1, 13, angleCounterOrAddress16,
                                                           &originalFrame.sp60);
            argumentWord4 = rawWord2;
            if (argumentWord4) {
                rawWord2 = Actor14_856ECField(privateAddressOrLiteral200, short*, 12);
                rawWord2 = contactFlagOrLiteral20 - rawWord2;
                rawWord3 = rawWord2 * 22;
                rawWord2 = 120;
                rawWord2 -= rawWord3;
                Actor14_856ECField(argumentWord4, signed char*, 10) = rawWord2;
            }
            rawWord2 =
                (unsigned short)Actor14_856ECField(privateAddressOrLiteral200, short*, 0xC) - 1;
            Actor14_856ECField(privateAddressOrLiteral200, short*, 0xC) = rawWord2;
            if ((rawWord2 << 0x10) > 0) {
                return;
            }
            goto removeOwner;
    }
runContactAndDeletionTail:
    if ((contactEnabled21 != 0) &&
        (Actor14_856ECCall1C288View1(ownerRecord18 + 0xC, 0x226, 0) != 0)) {
        angleCounterOrAddress16 = Actor14_856ECPlanarHeadingLookupView1(
            Actor14_856ECField(privateAddressOrLiteral200, int*, 0),
            Actor14_856ECField(privateAddressOrLiteral200, int*, 4), 0);
        if ((Actor14_856ECField(&Actor14_856ECData70328View1, int*, 0x50) != 4) &&
            (Actor14_856ECAbsoluteByteAngleDeltaView1(
                 Actor14_856ECPlanarHeadingLookupView1(
                     Actor14_856ECField(&Actor14_856ECData70328View1, int*, 0) -
                         Actor14_856ECField(ownerRecord18, int*, 0xC),
                     Actor14_856ECField(&Actor14_856ECData70328View1, int*, 4) -
                         Actor14_856ECField(ownerRecord18, int*, 0x10),
                     0),
                 angleCounterOrAddress16) < 0x32)) {
            Actor14_856ECField(&Actor14_856ECData70328View1, int*, 0x298) = angleCounterOrAddress16;
            Actor14_856ECField(&Actor14_856ECData70328View1, int*, 0x24) =
                (int)(Actor14_856ECField(&Actor14_856ECData70328View1, int*, 0x24) | 0x10);
        }
    }
    if (contactFlagOrLiteral20 != 0) {
        if (Actor14_856ECCall3BFC0View1(
                ownerRecord18, Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14)) != 0) {
            Actor14_856ECCall3BE70View1(Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14));
            Actor14_856ECField(privateAddressOrLiteral200, int*, 0x14) = -1;
        }
        Actor14_856ECPlayMobySoundEventView1(ownerRecord18, 2, 0);
        angleCounterOrAddress16 =
            Actor14_856ECCall1BA30View1(ownerRecord18 + 0xC, 0x400, 3, 0, 0x30000, ownerRecord18);
        if (angleCounterOrAddress16 != 0) {
            Actor14_856ECField(angleCounterOrAddress16, signed char*, 0x51) =
                Actor14_856ECPlanarHeadingLookupView1(0, 0, 0);
        }
        angleCounterOrAddress16 = 0;
        contactFlagOrLiteral20 = 2;
        privateAddressOrLiteral200 = 200;
        counterLiteralOrAddress17 = 256;
        do {
            rawWord3 =
                Actor14_856ECCall391E8View1(1, 0x166, ownerRecord18, 1, contactFlagOrLiteral20,
                                            privateAddressOrLiteral200, counterLiteralOrAddress17);
            rawWord2 = 3;
            if (rawWord3) {
                Actor14_856ECField(rawWord3, signed char*, 0x48) = rawWord2;
                rawWord2 = 47;
                Actor14_856ECField(rawWord3, signed char*, 0x57) = rawWord2;
                rawWord2 = 28;
                Actor14_856ECField(rawWord3, int*, 8) = 0;
                Actor14_856ECField(rawWord3, signed char*, 0x4F) = rawWord2;
            }
            angleCounterOrAddress16 += 1;
        } while (angleCounterOrAddress16 < 5);
        argumentWord6 = 0;
        __asm__("" ::"r"(argumentWord6) : "$16", "$17");
        angleCounterOrAddress16 = 0;
        counterLiteralOrAddress17 = 0;
        Actor14_856ECField(ownerRecord18, unsigned char*, 0x46) =
            Actor14_856ECPlanarHeadingLookupView1(
                Actor14_856ECField(&Actor14_856ECData70328View1, int*, 0) -
                    Actor14_856ECField(ownerRecord18, int*, 0xC),
                Actor14_856ECField(&Actor14_856ECData70328View1, int*, 4) -
                    Actor14_856ECField(ownerRecord18, int*, 0x10),
                argumentWord6);
    spawnNextGroupMember:
        if ((Actor14_856ECData6C578View1 - Actor14_856ECData6C574View1) >= 0x15) {
            rawWord2 = Actor14_856ECDataSpawnMobyView1(0x166, ownerRecord18);
            argumentWord4 = rawWord2;
            MATCHING_KEEP_GNU_VOLATILE(argumentWord4);
            rawWord2 = 6;
            if (argumentWord4) {
                Actor14_856ECField(argumentWord4, signed char*, 0x41) = 0;
                Actor14_856ECField(argumentWord4, signed char*, 0x4C) = 0;
                Actor14_856ECField(argumentWord4, signed char*, 0x4D) = 0;
                rawWord3 = Actor14_856ECField(ownerRecord18, unsigned char*, 0x46);
                Actor14_856ECField(argumentWord4, signed char*, 0x48) = rawWord2;
                Actor14_856ECField(argumentWord4, unsigned char*, 0x46) = rawWord3;
                rawWord3 = Actor14_856ECField(argumentWord4, void**, 0);
                rawWord2 = 5;
                Actor14_856ECField(argumentWord4, signed char*, 0x44) = counterLiteralOrAddress17;
                Actor14_856ECField(argumentWord4, int*, 8) = 0;
                Actor14_856ECField(rawWord3, short*, 12) = rawWord2;
            }
            angleCounterOrAddress16 += 1;
            counterLiteralOrAddress17 += 0x33;
            if (angleCounterOrAddress16 < 5) {
                goto spawnNextGroupMember;
            }
        }
        MATCHING_BARRIER_GNU_VOLATILE("$4");
        Actor14_856ECDataSpawnParticleView1(0xA, 0x46, ownerRecord18 + 12, (int*)16);
        rawWord2 = Actor14_856ECDataSpawnMobyView1(0x64, ownerRecord18);
        if (rawWord2 != 0) {
            Actor14_856ECField(rawWord2, signed char*, 0x48) = 0;
        }
    removeOwner:
        Actor14_856ECDeleteMobyView1(ownerRecord18);
    }
    return;
}
#undef Actor14_856ECField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008610C.
* Assembly SHA256 9eef86c278997cf423a835ac2a649c81afd303ced8d1f93c1aa9b8c4d83f3e98.
* AI generated; not human reviewed. All705 instructions,26 selector words
* and actual targets are required. Frame0xC0 retains S0..S5/RA and full
* SP18..9F local extent. The incoming byte mask and original literal10
* remain separate producers. State25 uses its original 0/2/3 decision chain.
* The retained player vector is the BYTE address at player+0x98;its -0x98/
* -0x94 consumers and original halfword at8006E040 preserve exact domains.
* Three separate particle-vector workspaces retain original random calls,
* complete low products and helper argument order. Spawned S0 remains live
* across helper calls;the child-private load precedes the original owner
* byte store and complete V0 literal1/200 producers. State24 distances and
* shared removal A0/A1 preserve every original conditional/internal target.
* Initialized empty identities,late consumers and dead clobbers emit zero
* instructions. No opcode assembly,partialHI,FP shortcut or live-alias
* overlap. Confidence is binary identity after all gates. Raw units/fixed
* point,full helper contracts,caller cadence and synchronized runtime remain
* open. Cadence is per invocation. Falsification:every native/linked word,
* actual transfer/table target,owned data byte,EXE and all overlay hashes. */
#define Actor14_8610CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor14_8610CCall1830CView1() __asm__("func_8001830C");
void* Actor14_8610CCall1BA30View1() __asm__("func_8001BA30");
int Actor14_8610CCall1C288View1() __asm__("func_8001C288");
int Actor14_8610CRequestMobyAnimationView1() __asm__("func_80034F40");
int Actor14_8610CSetMobyAnimationView1() __asm__("func_80034F80");
int Actor14_8610CCall35194View1() __asm__("func_80035194");
int Actor14_8610CTurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Actor14_8610CTurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor14_8610CCountTimerDownView1() __asm__("func_800359A4");
int Actor14_8610CCall35DDCView1() __asm__("func_80035DDC");
int Actor14_8610CRandBetweenView1() __asm__("func_8003636C");
int Actor14_8610CRandSignedBetweenView1() __asm__("func_800363DC");
int Actor14_8610CCall369B8View1() __asm__("func_800369B8");
int Actor14_8610CCall36A68View1() __asm__("func_80036A68");
int Actor14_8610CCall38BF8View1() __asm__("func_80038BF8");
int Actor14_8610CCall3B74CView1() __asm__("func_8003B74C");
int Actor14_8610CCall3BA00View1() __asm__("func_8003BA00");
int Actor14_8610CPlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor14_8610CShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Actor14_8610CCopyVectorView1() __asm__("func_8004F178");
int Actor14_8610CAddVectorView1() __asm__("func_8004F194");
int Actor14_8610CAbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor14_8610CApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor14_8610CDeleteMobyView1() __asm__("func_80055B18");
int Actor14_8610CRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor14_8610CCall55E84View1() __asm__("func_80055E84");
int Actor14_8610CInterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Actor14_8610CData6C550View1 __asm__("D_8006C550");
extern int Actor14_8610CData6C770View1 __asm__("D_8006C770");
extern int Actor14_8610CData6D088View1 __asm__("D_8006D088");
extern int Actor14_8610CData6E020View1 __asm__("D_8006E020");
extern int Actor14_8610CData6E024View1 __asm__("D_8006E024");
extern unsigned short Actor14_8610CData6E040View1 __asm__("D_8006E040");
extern int Actor14_8610CData6E344View1 __asm__("D_8006E344");
extern int Actor14_8610CData70328View1 __asm__("D_80070328");
extern void* (*Actor14_8610CDataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor14_8610CDataSpawnParticleView1)() __asm__("SpawnParticle");
extern int (*Actor14_8610CData743E8View1)() __asm__("unk_ovlheader_800743E8");
void func_level_14_8008610C(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int recordAddressOrDistance16 __asm__("$16"), privateRecord18 __asm__("$18"),
        retainedStackAddress19 __asm__("$19"), collisionRecordAddress20 __asm__("$20"),
        ownerPositionAddress21 __asm__("$21");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84,
            sp88, sp8C, sp90, sp94, sp98, sp9C;
    } originalFrame;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    rawWord2 = 10;
    argumentWord4 = Actor14_8610CField(ownerRecord17, unsigned char*, 0x48);
    privateRecord18 = Actor14_8610CField(ownerRecord17, void**, 0);
    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord2), "r"(privateRecord18));
    rawWord3 = argumentWord4 & 255;
    if (rawWord3 == rawWord2)
        goto dispatchAfterIncomingContact;
    rawWord2 = argumentWord4 - 8;
    if ((unsigned int)rawWord2 < 2U)
        goto dispatchAfterIncomingContact;
    if (Actor14_8610CField(ownerRecord17, int*, 0x18)) {
        Actor14_8610CCall36A68View1(ownerRecord17, 0, 0, 0);
        Actor14_8610CCall38BF8View1(ownerRecord17, privateRecord18 + 0x18, 6, 8);
        Actor14_8610CField(privateRecord18, short*, 0x22) = 0x258;
    }
dispatchAfterIncomingContact:
    rawWord3 = Actor14_8610CField(ownerRecord17, unsigned char*, 0x48);
    switch (rawWord3) {
        case 25:
            rawWord3 = Actor14_8610CField(ownerRecord17, unsigned char*, 0x49);
            if (rawWord3)
                goto checkState25Substate2;
            if (Actor14_8610CApproximatePlanarDistanceView1(ownerRecord17 + 12,
                                                            &Actor14_8610CData70328View1) < 0x2000)
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x49) = 2;
            return;
        checkState25Substate2:
            rawWord2 = 2;
            if (rawWord3 != rawWord2)
                goto checkState25Substate3;
            if (Actor14_8610CAbsoluteByteAngleDeltaView1(
                    Actor14_8610CPlanarHeadingLookupView1(
                        Actor14_8610CField(&Actor14_8610CData70328View1, int*, 0) -
                            Actor14_8610CField(ownerRecord17, int*, 12),
                        Actor14_8610CField(&Actor14_8610CData70328View1, int*, 4) -
                            Actor14_8610CField(ownerRecord17, int*, 16),
                        0),
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x46)) >= 65) {
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x4A) = 255;
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x49) = 3;
                Actor14_8610CField(privateRecord18, short*, 0) = 60;
            }
            return;
        checkState25Substate3:
            rawWord2 = 3;
            if (rawWord3 != rawWord2)
                return;
            if (Actor14_8610CCountTimerDownView1(privateRecord18, 2))
                Actor14_8610CCall3B74CView1(&Actor14_8610CData6D088View1);
            return;
        case 0:
            if (Actor14_8610CCountTimerDownView1(privateRecord18, 2) != 0) {
                Actor14_8610CTurnMobyTowardPlayerView1(ownerRecord17, 2, 1, 1);
                argumentWord4 = (int)&originalFrame.sp18;
                MATCHING_OBSERVE_CLOBBER(argumentWord4, "$16");
                recordAddressOrDistance16 = (int)&Actor14_8610CData70328View1 + 0x98;
                MATCHING_KEEP(recordAddressOrDistance16);
                Actor14_8610CCopyVectorView1(argumentWord4, recordAddressOrDistance16);
                originalFrame.sp18 *= 0x1E;
                originalFrame.sp1C *= 0x1E;
                originalFrame.sp20 *= 0x1E;
                Actor14_8610CShiftVectorRightTowardZeroView1(&originalFrame.sp18, 6);
                Actor14_8610CAddVectorView1(&originalFrame.sp18, &originalFrame.sp18,
                                            recordAddressOrDistance16 - 0x98);
                rawWord2 = Actor14_8610CField(ownerRecord17, int*, 20);
                rawWord3 = Actor14_8610CField(&Actor14_8610CData70328View1, int*, 8);
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if ((rawWord2 < 0xC00) &&
                    (Actor14_8610CApproximatePlanarDistanceView1(ownerRecord17 + 0xC,
                                                                 &originalFrame.sp18) < 0x2400) &&
                    (Actor14_8610CData6E344View1 != 1) && (Actor14_8610CData6E344View1 != 0xF) &&
                    (Actor14_8610CAbsoluteByteAngleDeltaView1(
                         Actor14_8610CPlanarHeadingLookupView1(
                             Actor14_8610CField(recordAddressOrDistance16, int*, -0x98) -
                                 Actor14_8610CField(ownerRecord17, int*, 0xC),
                             Actor14_8610CField(recordAddressOrDistance16, int*, -0x94) -
                                 Actor14_8610CField(ownerRecord17, int*, 0x10),
                             0),
                         Actor14_8610CField(ownerRecord17, unsigned char*, 0x46)) < 8) &&
                    (Actor14_8610CAbsoluteByteAngleDeltaView1(
                         (int)(Actor14_8610CData6E040View1 << 0x10) >> 0x14,
                         Actor14_8610CPlanarHeadingLookupView1(
                             Actor14_8610CField(ownerRecord17, int*, 0xC) -
                                 Actor14_8610CData6E020View1,
                             Actor14_8610CField(ownerRecord17, int*, 0x10) -
                                 Actor14_8610CData6E024View1,
                             0)) < 0x12)) {
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 1U;
                    Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 1);
                    return;
                }
            }
            break;
        case 1:
            Actor14_8610CTurnMobyTowardPlayerView1(ownerRecord17, 6, 0, 0);
            if (Actor14_8610CData6C770View1 != 0) {
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 2U;
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 2);
                return;
            }
            break;
        case 2:
            Actor14_8610CTurnMobyTowardPlayerView1(ownerRecord17, 6, 0, 0);
            if ((Actor14_8610CData6E344View1 != 1) && (Actor14_8610CData6E344View1 != 0xF) &&
                (Actor14_8610CAbsoluteByteAngleDeltaView1(
                     Actor14_8610CPlanarHeadingLookupView1(
                         Actor14_8610CField(&Actor14_8610CData70328View1, int*, 0) -
                             Actor14_8610CField(ownerRecord17, int*, 0xC),
                         Actor14_8610CField(&Actor14_8610CData70328View1, int*, 4) -
                             Actor14_8610CField(ownerRecord17, int*, 0x10),
                         0),
                     Actor14_8610CField(ownerRecord17, unsigned char*, 0x46)) < 8) &&
                (Actor14_8610CAbsoluteByteAngleDeltaView1(
                     (int)(Actor14_8610CData6E040View1 << 0x10) >> 0x14,
                     Actor14_8610CPlanarHeadingLookupView1(
                         Actor14_8610CField(ownerRecord17, int*, 0xC) - Actor14_8610CData6E020View1,
                         Actor14_8610CField(ownerRecord17, int*, 0x10) -
                             Actor14_8610CData6E024View1,
                         0)) < 0x12)) {
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 3U;
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 3);
                return;
            }
            Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 0U;
            Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 0);
            Actor14_8610CField(ownerRecord17, unsigned char*, 0x40) = 0xF0;
            return;
        case 3:
            if ((Actor14_8610CField(ownerRecord17, unsigned char*, 0x3C) == 3) &&
                (Actor14_8610CCall55E84View1(ownerRecord17) < 4) &&
                (Actor14_8610CField(ownerRecord17, unsigned char*, 0x49) == 0)) {
                Actor14_8610CRefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
                retainedStackAddress19 = (int)&originalFrame.sp28;
                Actor14_8610CInterpolateMobyVertexView1(ownerRecord17, 0, retainedStackAddress19);
                rawWord2 = Actor14_8610CDataSpawnMobyView1(0x168, ownerRecord17);
                recordAddressOrDistance16 = rawWord2;
                MATCHING_KEEP(recordAddressOrDistance16);
                if (recordAddressOrDistance16 != 0) {
                    argumentWord4 = recordAddressOrDistance16 + 12;
                    argumentWord5 = retainedStackAddress19;
                    rawWord3 = Actor14_8610CField(recordAddressOrDistance16, void**, 0);
                    MATCHING_OBSERVE_CLOBBER(rawWord3, "$2");
                    rawWord2 = 1;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(rawWord3), "r"(argumentWord4), "r"(argumentWord5));
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x49) = rawWord2;
                    rawWord2 = 200;
                    Actor14_8610CField(rawWord3, short*, 0) = rawWord2;
                    Actor14_8610CCopyVectorView1(argumentWord4, argumentWord5);
                    Actor14_8610CSetMobyAnimationView1(recordAddressOrDistance16, 0xA);
                    Actor14_8610CField(recordAddressOrDistance16, signed char*, 0x48) = 0xA;
                    Actor14_8610CField(recordAddressOrDistance16, int*, 8) = 0;
                    Actor14_8610CField(recordAddressOrDistance16, unsigned char*, 0x46) =
                        (unsigned char)Actor14_8610CField(ownerRecord17, unsigned char*, 0x46);
                }
            }
            if (Actor14_8610CData6C770View1 != 0) {
                if (Actor14_8610CField(privateRecord18, unsigned char*, 2) != 0) {
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x49) = 0U;
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) =
                        (unsigned char)Actor14_8610CField(privateRecord18, unsigned char*, 2);
                    return;
                }
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x49) = 0U;
                Actor14_8610CField(privateRecord18, short*, 0) = 0x46;
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 4U;
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 4);
                return;
            }
            break;
        case 4:
            Actor14_8610CTurnMobyTowardPlayerView1(ownerRecord17, 6, 0, 0);
            if (Actor14_8610CData6C770View1 != 0) {
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 0U;
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 0);
                return;
            }
            break;
        case 6:
            Actor14_8610CTurnMobyTowardPlayerView1(ownerRecord17, 4, 1, 1);
            if (Actor14_8610CData6C770View1 != 0) {
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 5);
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x40) = 0xF0;
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                return;
            }
            break;
        case 7:
            Actor14_8610CCopyVectorView1(&originalFrame.sp38, ownerRecord17 + 0xC);
            originalFrame.sp38 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp3C += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp40 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp48 = Actor14_8610CRandSignedBetweenView1(0, 0xA);
            originalFrame.sp4C = Actor14_8610CRandSignedBetweenView1(0, 0xA);
            originalFrame.sp50 = Actor14_8610CRandBetweenView1(5, 8);
            Actor14_8610CDataSpawnParticleView1(1, 0x27, &originalFrame.sp38, &originalFrame.sp48);
            return;
        case 20:
            rawWord3 =
                Actor14_8610CField(Actor14_8610CField(privateRecord18, void**, 4), void**, 0xC);
            rawWord2 = Actor14_8610CField(ownerRecord17, int*, 12);
            argumentWord4 = Actor14_8610CField(rawWord3, int*, 0);
            argumentWord4 -= rawWord2;
            originalFrame.sp58 = argumentWord4;
            argumentWord5 = Actor14_8610CField(rawWord3, int*, 4);
            rawWord2 = Actor14_8610CField(ownerRecord17, int*, 16);
            argumentWord5 -= rawWord2;
            originalFrame.sp5C = argumentWord5;
            if (Actor14_8610CTurnMobyTowardHeadingView1(
                    ownerRecord17,
                    Actor14_8610CPlanarHeadingLookupView1(argumentWord4, argumentWord5, 0), 8, 1, 0,
                    0) != 0) {
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 5);
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x40) = 0xF0;
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 0x15U;
                return;
            }
            break;
        case 21:
            Actor14_8610CCopyVectorView1(&originalFrame.sp60, ownerRecord17 + 0xC);
            originalFrame.sp60 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp64 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp68 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp70 = Actor14_8610CRandSignedBetweenView1(0, 0xA);
            originalFrame.sp74 = Actor14_8610CRandSignedBetweenView1(0, 0xA);
            originalFrame.sp78 = Actor14_8610CRandBetweenView1(5, 8);
            Actor14_8610CDataSpawnParticleView1(1, 0x27, &originalFrame.sp60, &originalFrame.sp70);
            if (Actor14_8610CData743E8View1(ownerRecord17,
                                            Actor14_8610CField(privateRecord18, void**, 4),
                                            privateRecord18 + 8) == 1) {
                rawWord2 = Actor14_8610CField(privateRecord18, void**, 4);
                if (Actor14_8610CField(rawWord2, short*, 2) ==
                    (Actor14_8610CField(rawWord2, short*, 0) - 1)) {
                    Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 0);
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x40) = 0xF0;
                    Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 0x16U;
                    Actor14_8610CField(privateRecord18, unsigned char*, 2) = 0U;
                    Actor14_8610CField(privateRecord18, short*, 0) = 0x5A;
                    return;
                }
            }
            break;
        case 22:
            rawWord3 = Actor14_8610CField(ownerRecord17, unsigned char*, 0x45);
            MATCHING_KEEP(rawWord3);
            rawWord2 = rawWord3 & 255;
            if (rawWord2) {
                rawWord2 = (unsigned int)rawWord2 < 128U;
                if (rawWord2)
                    rawWord2 = rawWord3 - 1;
                else
                    rawWord2 = rawWord3 + 1;
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x45) = rawWord2;
            }
            if ((Actor14_8610CCountTimerDownView1(privateRecord18, 2) != 0) ||
                (Actor14_8610CTurnMobyTowardPlayerView1(ownerRecord17, 8, 1, 0) != 0)) {
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x45) = 0U;
                Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = 0U;
                Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 0);
                return;
            }
            break;
        case 24:
            rawWord2 = Actor14_8610CApproximatePlanarDistanceView1(ownerRecord17 + 12,
                                                                   &Actor14_8610CData70328View1);
            rawWord3 = Actor14_8610CField(ownerRecord17, int*, 20);
            argumentWord4 = Actor14_8610CField(&Actor14_8610CData70328View1, int*, 8);
            rawWord3 -= argumentWord4;
            if (rawWord3 < 0)
                rawWord3 = -rawWord3;
            rawWord3 = rawWord3 < 0xC00;
            argumentWord5 = rawWord2;
            if (rawWord3) {
                rawWord2 = argumentWord5 < 0x3000;
                if (rawWord2)
                    goto storeState24Transition6;
            }
            rawWord2 = argumentWord5 < 0x2000;
            if (!rawWord2)
                return;
        storeState24Transition6:
            rawWord2 = 6;
            Actor14_8610CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
            Actor14_8610CRequestMobyAnimationView1(ownerRecord17, 6);
            return;
        case 8:
        case 9:
            if (Actor14_8610CCall35194View1(ownerRecord17, privateRecord18 + 0x18) == 0x100) {
                Actor14_8610CRefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Actor14_8610CCall3BA00View1(ownerRecord17);
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 40;
                goto callSharedRemovalHelpers;
            }
            break;
        case 10:
            collisionRecordAddress20 = 0;
            ownerPositionAddress21 = ownerRecord17 + 0xC;
            Actor14_8610CCopyVectorView1(&originalFrame.sp80, ownerPositionAddress21);
            originalFrame.sp80 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp84 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp88 += Actor14_8610CRandSignedBetweenView1(0, 0x96);
            originalFrame.sp90 = Actor14_8610CRandSignedBetweenView1(0, 0xA);
            originalFrame.sp94 = Actor14_8610CRandSignedBetweenView1(0, 0xA);
            originalFrame.sp98 = Actor14_8610CRandBetweenView1(5, 8);
            Actor14_8610CDataSpawnParticleView1(1, 0x27, &originalFrame.sp80, &originalFrame.sp90);
            Actor14_8610CCopyVectorView1(&originalFrame.sp80, ownerPositionAddress21);
            Actor14_8610CCall35DDCView1(ownerRecord17, 0x64, 0, 0, 0);
            recordAddressOrDistance16 = 0;
            Actor14_8610CField(ownerRecord17, int*, 8) = 0;
            if ((Actor14_8610CField(ownerRecord17, int*, 0xC) < 0x400) ||
                (Actor14_8610CField(ownerRecord17, int*, 0x10) < 0x400) ||
                (Actor14_8610CField(ownerRecord17, int*, 0x14) < 0x400) ||
                (Actor14_8610CCountTimerDownView1(privateRecord18, 2) != 0) ||
                (Actor14_8610CCall1830CView1(&originalFrame.sp80, ownerPositionAddress21, 3, 0,
                                             0) != 0) ||
                ((collisionRecordAddress20 = Actor14_8610CCall1BA30View1(
                      ownerPositionAddress21, 0x100, 3, 0, 1,
                      Actor14_8610CData6C550View1 +
                          (Actor14_8610CField(ownerRecord17, unsigned char*, 0x3A) * 0x58)),
                  (collisionRecordAddress20 != 0)) &&
                 (Actor14_8610CField(collisionRecordAddress20, short*, 0x36) != 0x168)) ||
                (recordAddressOrDistance16 =
                     Actor14_8610CCall1C288View1(ownerPositionAddress21, 0xC8, 7),
                 (recordAddressOrDistance16 != 0))) {
                if (recordAddressOrDistance16 != 0) {
                    Actor14_8610CField(&Actor14_8610CData70328View1, int*, 0x298) =
                        (int)Actor14_8610CField(ownerRecord17, unsigned char*, 0x46);
                } else if (collisionRecordAddress20 != 0) {
                    Actor14_8610CField(collisionRecordAddress20, unsigned char*, 0x51) =
                        (unsigned char)Actor14_8610CField(ownerRecord17, unsigned char*, 0x46);
                }
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 20;
                goto callSharedRemovalHelpers;
            }
            break;
    }
    return;
callSharedRemovalHelpers:
    Actor14_8610CCall369B8View1(argumentWord4, argumentWord5);
    Actor14_8610CDeleteMobyView1(ownerRecord17);
}
#undef Actor14_8610CField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_80086C10.s SHA256 1d40ee699b2e62fda4c98c11f0993c04c5971093160f8566dcd8e1d0cfe2537e. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller86C10_func_8001830C() __asm__("func_8001830C");                 /* extern */
void* Controller86C10_func_8001BA30() __asm__("func_8001BA30");               /* extern */
int Controller86C10_func_8001C288() __asm__("func_8001C288");                 /* extern */
int Controller86C10CountTimerDown() __asm__("func_800359A4");                 /* extern */
int Controller86C10_func_80035DDC() __asm__("func_80035DDC");                 /* extern */
int Controller86C10RandBetween() __asm__("func_8003636C");                    /* extern */
int Controller86C10RandSignedBetween() __asm__("func_800363DC");              /* extern */
void* Controller86C10_func_800391E8() __asm__("func_800391E8");               /* extern */
int Controller86C10PlayMobySoundEvent() __asm__("func_8003BABC");             /* extern */
int Controller86C10PlanarHeadingLookup() __asm__("func_8004E880");            /* extern */
int Controller86C10TransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Controller86C10CopyVector() __asm__("func_8004F178");                     /* extern */
int Controller86C10AddVector() __asm__("func_8004F194");                      /* extern */
int Controller86C10DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller86C10RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
extern int Controller86C10_D_8006C574 __asm__("D_8006C574");
extern int Controller86C10_D_8006C578 __asm__("D_8006C578");
extern unsigned char Controller86C10_D_80070328 __asm__("D_80070328");
extern void* Controller86C10_D_80071930 __asm__("D_80071930");
extern void* (*Controller86C10_SpawnMoby)() __asm__("SpawnMoby");
extern void* (*Controller86C10_SpawnParticle)() __asm__("SpawnParticle");

void func_level_14_80086C10(void* input_arg0) {
    register void* owner __asm__("$18") = input_arg0;

    /* Original stack vectors at 0x20/0x30/0x40, including their padding. */
    struct {
        int sp20, sp24, sp28, pad2C, sp30, sp34, sp38, pad3C, sp40, sp44, sp48, pad4C;
    } originalFrame;

    register void* globalObject __asm__("$4");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int state17 __asm__("$17");
    register int constant200 __asm__("$21");
    register int constant256 __asm__("$20");
    register int constant28 __asm__("$19");
    register void* result2 __asm__("$2");
    register void* result4 __asm__("$4");
    register int callArg5 __asm__("$5");
    register int callArg6 __asm__("$6");
    register int callArg7 __asm__("$7");
    register int objectType36 __asm__("$3");
    register int* ownerVectorState1 __asm__("$16");
    register int* ownerVectorState0 __asm__("$16");
    register int* ownerVectorAfterLoop __asm__("$16");
    register int* ownerData __asm__("$19");
    int decrementedCount;
    register int particleIndex __asm__("$16");
    register int childIndex __asm__("$16");
    register int helperResult1830C __asm__("$20");
    register signed char childField44 __asm__("$17");
    register void* particle0 __asm__("$4");
    void* particle1;
    register void* particle2 __asm__("$2");
    register void* child __asm__("$4");
    void* lastChild;
    register void* helperObject __asm__("$17");

    MATCHING_KEEP(owner);
    helperObject = 0;
    MATCHING_KEEP(helperObject);
    ownerData = M2C_FIELD(owner, int**, 0);
    helperResult1830C = 0;
    value3 = 1;
    value2 = M2C_FIELD(owner, unsigned char*, 0x48);
    if (value2 == value3) {
        originalFrame.sp40 = 0;
        originalFrame.sp44 = 0x96;
        originalFrame.sp48 = 0;
        /* Preserve the original owner reload in the tag-count branch delay. */
        MATCHING_BARRIER("$4");
        result4 = owner;
        if (*ownerData == 5) {
            originalFrame.sp44 = 0x2BC;
        }
        Controller86C10RefreshMobySpatialGridAndBasis(result4, 4);
        Controller86C10TransformVectorByBasis(owner + 0x20, &originalFrame.sp40,
                                              &originalFrame.sp40);
        ownerVectorState1 = owner + 0xC;
        Controller86C10AddVector(ownerVectorState1, ownerVectorState1, &originalFrame.sp40);
        originalFrame.sp40 = 0;
        originalFrame.sp44 = 0;
        originalFrame.sp48 = -((5 - *ownerData) * 6);
        particle0 = Controller86C10_SpawnParticle(1, 0xD, ownerVectorState1, &originalFrame.sp40);
        if (particle0 != 0) {
            M2C_FIELD(particle0, signed char*, 0xA) =
                (signed char)(0x78 - ((5 - *ownerData) * 0x16));
        }
        decrementedCount = *ownerData - 1;
        *ownerData = decrementedCount;
        if (decrementedCount <= 0) {
            MATCHING_OBSERVE_VOLATILE(ownerData);
            goto destroyOwner;
        }
    } else {
        result4 = &originalFrame.sp20;
        MATCHING_KEEP(result4);
        ownerVectorState0 = owner + 0xC;
        Controller86C10CopyVector(result4, ownerVectorState0);
        originalFrame.sp20 += Controller86C10RandSignedBetween(0, 0x96);
        originalFrame.sp24 += Controller86C10RandSignedBetween(0, 0x96);
        originalFrame.sp28 += Controller86C10RandSignedBetween(0, 0x96);
        originalFrame.sp30 = Controller86C10RandSignedBetween(0, 0xA);
        originalFrame.sp34 = Controller86C10RandSignedBetween(0, 0xA);
        originalFrame.sp38 = Controller86C10RandBetween(5, 8);
        particle1 = Controller86C10_SpawnParticle(1, 0xD, &originalFrame.sp20, &originalFrame.sp30);
        if (particle1 != 0) {
            M2C_FIELD(particle1, signed char*, 0xA) = 0x64;
        }
        Controller86C10CopyVector(&originalFrame.sp20, ownerVectorState0);
        Controller86C10_func_80035DDC(owner, 0xC8, 0, 0, 0);
        if ((M2C_FIELD(owner, int*, 0xC) >= 0x400) && (M2C_FIELD(owner, int*, 0x10) >= 0x400) &&
            (M2C_FIELD(owner, int*, 0x14) >= 0x400) &&
            (Controller86C10CountTimerDown(ownerData, 4) == 0)) {
            helperResult1830C =
                Controller86C10_func_8001830C(&originalFrame.sp20, ownerVectorState0, 3, 0, 0);
            if (helperResult1830C == 0) {
                result4 = ownerVectorState0;
                MATCHING_KEEP(helperResult1830C);
                callArg7 = 0;
                helperObject =
                    Controller86C10_func_8001BA30(result4, 0x100, 3, callArg7, 0x40000, owner);
                if (((helperObject != 0) && (M2C_FIELD(helperObject, short*, 0x36) != 0x1A6)) ||
                    (Controller86C10_func_8001C288(ownerVectorState0, 0x100, 7) != 0)) {
                    goto testHelperResult;
                }
            } else {
                goto testCurrentObject;
            }
        } else {
        testHelperResult:
            if (helperResult1830C != 0) {
            testCurrentObject:
                result2 = Controller86C10_D_80071930;
                if (result2 != 0) {
                    globalObject = result2;
                    objectType36 = M2C_FIELD(globalObject, short*, 0x36);
                    if (objectType36 == 0x1A5) {
                        if ((unsigned char)M2C_FIELD(globalObject, unsigned char*, 0x48) >= 2U) {
                            goto testObjectTypeRanges;
                        }
                        goto writeObjectFlags;
                    }
                testObjectTypeRanges:
                    if (objectType36 != 0x1C2) {
                        if ((unsigned int)(objectType36 - 0x1D6) >= 2U) {
                            value2 = (unsigned int)(objectType36 - 0x1D8) < 2U;
                            MATCHING_OBSERVE(objectType36);
                            particleIndex = 0;
                            if (value2) {
                                goto writeObjectFlagsAlias;
                            }
                        } else {
                            goto writeObjectFlags;
                        }
                    } else {
                    writeObjectFlagsAlias:
                    writeObjectFlags:
                        M2C_FIELD(globalObject, int*, 0x18) = 0xA0000;
                        goto startParticleLoop;
                    }
                } else {
                    goto testHelperObject;
                }
            } else {
            testHelperObject:
                particleIndex = 0;
                if (helperObject != 0) {
                    M2C_FIELD(helperObject, unsigned char*, 0x51) =
                        (unsigned char)M2C_FIELD(owner, unsigned char*, 0x46);
                startParticleLoop:
                    particleIndex = 0;
                }
            }
            state17 = 2;
            constant200 = 200;
            constant256 = 256;
            constant28 = 28;
            MATCHING_KEEP4(state17, constant200, constant256, constant28);
            do {
                result2 = Controller86C10_func_800391E8(1, 0x54, owner, 0, state17, constant200,
                                                        constant256);
                particle2 = result2;
                if (particle2 != 0) {
                    M2C_FIELD(particle2, signed char*, 0x48) = state17;
                    M2C_FIELD(particle2, signed char*, 0x4F) = constant28;
                }
                particleIndex += 1;
            } while (particleIndex < 5);
            callArg6 = 0;
            MATCHING_KEEP(callArg6);
            childIndex = 0;
            childField44 = 0;
            M2C_FIELD(owner, unsigned char*, 0x46) = Controller86C10PlanarHeadingLookup(
                M2C_FIELD(&Controller86C10_D_80070328, int*, 0) - M2C_FIELD(owner, int*, 0xC),
                M2C_FIELD(&Controller86C10_D_80070328, int*, 4) - M2C_FIELD(owner, int*, 0x10),
                callArg6);
        spawnChildLoop:
            if ((Controller86C10_D_8006C578 - Controller86C10_D_8006C574) >= 0x15) {
                result2 = Controller86C10_SpawnMoby(0x19B, owner);
                child = result2;
                MATCHING_KEEP(child);
                if (child != 0) {
                    M2C_FIELD(child, signed char*, 0x41) = 0;
                    M2C_FIELD(child, signed char*, 0x4C) = 0;
                    M2C_FIELD(child, signed char*, 0x4D) = 0;
                    value2 = 1;
                    value3 = M2C_FIELD(owner, unsigned char*, 0x46);
                    M2C_FIELD(child, signed char*, 0x48) = value2;
                    M2C_FIELD(child, unsigned char*, 0x46) = value3;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(child, "memory");
                    value3 = (int)M2C_FIELD(child, void**, 0);
                    value2 = 5;
                    M2C_FIELD(child, signed char*, 0x44) = childField44;
                    M2C_FIELD(child, int*, 8) = 0;
                    M2C_FIELD((void*)value3, int*, 0) = value2;
                }
                childIndex += 1;
                childField44 += 0x33;
                if (childIndex < 5) {
                    goto spawnChildLoop;
                }
            }
            /* Original argument 10 is produced after the child loop. */
            MATCHING_BARRIER_VOLATILE("$4");
            result4 = (void*)10;
            callArg5 = 70;
            MATCHING_KEEP2(result4, callArg5);
            ownerVectorAfterLoop = owner + 0xC;
            Controller86C10_SpawnParticle(result4, callArg5, ownerVectorAfterLoop, (int*)0x10);
            Controller86C10PlayMobySoundEvent(owner, 0, 0);
            Controller86C10_func_8001BA30(ownerVectorAfterLoop, 0x5DC, 1, 0, 0x40000, owner);
            lastChild = Controller86C10_SpawnMoby(0x64, owner);
            if (lastChild != 0) {
                M2C_FIELD(lastChild, signed char*, 0x48) = 0;
            }
        destroyOwner:
            Controller86C10DeleteMoby(owner);
        }
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80087104.
* AI generated; not human reviewed. All944 original instructions and actual
* destinations must match. Frame70 saves S0..S6/RA,SP20..4F retained. The
* original two three-word vector templates at80074AF0/4AFC remain unchanged.
* Original34/33/32/31/30 state comparisons remain ordered, with no invented
* dispatch table. Heading checks retain all original signed remainder8
* producers and guard bypass. Rejection is entered only by its original
* comparison. Both octant chains retain cached player-Y and original widths.
* Three spawn groups and the frame-vector particle loop keep full random
* returns, original offset-before-sum ordering and independent arguments.
* Full saved421/422 and sequential255 constants retain original producers.
* Original actor terminator is LBU, not the parser's pointer-sized read.
* Independent mode reads, original direct symbol writes and caller counter
* phases remain. Shared owner-state byte writer stays at932. The final
* template selector, spawn call-delay halfword, complete private fields and
* low32 selected/fallback root-address chains retain every original word.
* Empty metadata consumes full initialized values or clobbers only before
* their new producers; zero CPU instructions. No opcode assembly,partialHI,
* fixedFP, undefined saved inputs, overlapping aliases or pipeline changes.
* Units/fixed point, full helper/caller chains, cadence beyond invocation
* and synchronized retail runtime remain open. Confidence is binary identity
* after all gates. Next: human review and synchronized retail captures.
* Falsification: all native/linked words, actual destinations, original data,
* full EXE and every overlay retail hash must remain identical.
*/
/* Original assembly SHA256 18b2b86475c404044f5c79b1869d1164a5d681b4726e77362efd73f1dfd49dbd */
#define Level14_87104Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level14_87104Call13ACCView1() __asm__("func_80013ACC");
int Level14_87104Call13AE4View1() __asm__("func_80013AE4");
int Level14_87104Call21ED8View1() __asm__("func_80021ED8");
int Level14_87104Call21F3CView1() __asm__("func_80021F3C");
void Level14_87104RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level14_87104CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level14_87104Call35DDCView1() __asm__("func_80035DDC");
int Level14_87104RandBetweenView1() __asm__("func_8003636C");
int Level14_87104Call369B8View1() __asm__("func_800369B8");
int Level14_87104Call36A68View1() __asm__("func_80036A68");
int Level14_87104Call391E8View1() __asm__("func_800391E8");
int Level14_87104Call3BA00View1() __asm__("func_8003BA00");
int Level14_87104PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level14_87104Call3BB10View1() __asm__("func_8003BB10");
int Level14_87104PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level14_87104CopyVectorView1() __asm__("func_8004F178");
int Level14_87104ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level14_87104DeleteMobyView1() __asm__("func_80055B18");
int Level14_87104RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level14_87104Data6C550View1 __asm__("D_8006C550");
extern int Level14_87104Data6C574View1 __asm__("D_8006C574");
extern int Level14_87104Data6C578View1 __asm__("D_8006C578");
extern int Level14_87104Data6C65CView1 __asm__("D_8006C65C");
extern int Level14_87104Data6C7C0View1 __asm__("D_8006C7C0");
extern int Level14_87104Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level14_87104Data6E048View1 __asm__("D_8006E048");
extern int Level14_87104Data6E160View1 __asm__("D_8006E160");
extern int Level14_87104Data70328View1 __asm__("D_80070328");
extern int Level14_87104Data74AF0View1 __asm__("D_level_14_80074AF0");
extern int Level14_87104Data74AFCView1 __asm__("D_level_14_80074AFC");
extern int (*Level14_87104DataSpawnFragmentsView1)() __asm__("SpawnFragments");
extern void* (*Level14_87104DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level14_87104DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_14_80087104(void* input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    register int originalClass421 __asm__("$22"), originalClass422 __asm__("$21");
    register int argumentWord7 __asm__("$7"), originalByte255 __asm__("$8"),
        originalState31 __asm__("$9");
    register void* ownerRecord19 __asm__("$19");
    register int privateRecord20 __asm__("$20"), retainedPrivateOrModeAddress16 __asm__("$16"),
        retainedSpawnOrRecord17 __asm__("$17"), retainedLoopOrByte18 __asm__("$18");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
    } originalFrame;
    int temporaryWord7;
    int temporaryWord11;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord4;
    int temporaryWord3;
    int temporaryWord5;
    int temporaryWord6;
    ownerRecord19 = input;
    MATCHING_KEEP(ownerRecord19);
    privateRecord20 = Level14_87104Field(ownerRecord19, void**, 0);
    __asm__ volatile(""
                     : "=r"(privateRecord20)
                     : "0"(privateRecord20)
                     : "$2", "$3", "$4", "$5", "memory");
    argumentWord5 = (int)&Level14_87104Data74AF0View1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level14_87104Field(argumentWord5, int*, 0);
    rawWord3 = Level14_87104Field(argumentWord5, int*, 4);
    argumentWord4 = Level14_87104Field(argumentWord5, int*, 8);
    originalFrame.sp20 = rawWord2;
    originalFrame.sp24 = rawWord3;
    originalFrame.sp28 = argumentWord4;
    __asm__("" ::: "$5", "memory");
    argumentWord5 = (int)&Level14_87104Data74AFCView1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level14_87104Field(argumentWord5, int*, 0);
    rawWord3 = Level14_87104Field(argumentWord5, int*, 4);
    argumentWord4 = Level14_87104Field(argumentWord5, int*, 8);
    originalFrame.sp30 = rawWord2;
    originalFrame.sp34 = rawWord3;
    originalFrame.sp38 = argumentWord4;
    if ((unsigned char)Level14_87104Field(ownerRecord19, unsigned char*, 0x48) >= 0x1EU) {
        argumentWord4 =
            Level14_87104Field(Level14_87104Field(privateRecord20, void**, 0x60), void**, 0xC);
        if (Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0) <
            Level14_87104Field(argumentWord4, int*, 0)) {
            if (({
                    rawWord3 = Level14_87104Field((int)&Level14_87104Data70328View1, int*, 4);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = Level14_87104Field(argumentWord4, int*, 4);
                    rawWord2 < rawWord3;
                })) {
                temporaryWord11 = 1;
            } else {
                temporaryWord11 = 3;
                if (({
                        rawWord2 = Level14_87104Field(argumentWord4, int*, 0x24);
                        rawWord2 < rawWord3;
                    })) {
                    temporaryWord11 = 2;
                }
            }
        } else if (Level14_87104Field(argumentWord4, int*, 0x10) <
                   Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0)) {
            if (({
                    rawWord3 = Level14_87104Field((int)&Level14_87104Data70328View1, int*, 4);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = Level14_87104Field(argumentWord4, int*, 0x14);
                    rawWord2 < rawWord3;
                })) {
                temporaryWord11 = 7;
            } else {
                temporaryWord11 = 5;
                if (({
                        rawWord2 = Level14_87104Field(argumentWord4, int*, 0x24);
                        rawWord2 < rawWord3;
                    })) {
                    temporaryWord11 = 6;
                }
            }
        } else {
            temporaryWord11 = 4;
            if (({
                    rawWord3 = Level14_87104Field((int)&Level14_87104Data70328View1, int*, 4);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = Level14_87104Field(argumentWord4, int*, 4);
                    rawWord2 < rawWord3;
                })) {
                temporaryWord11 = 8;
            }
        }
        Level14_87104Field(privateRecord20, short*, 0xC) = temporaryWord11;
        goto checkOriginalOwnerFlags;
    }
    temporaryWord5 =
        Level14_87104Data6C550View1 + (Level14_87104Field(privateRecord20, int*, 0x10) * 0x58);
    if (!(Level14_87104Field(temporaryWord5, unsigned char*, 0x48) & 0x80)) {
        __asm__ volatile("" ::: "$2", "memory");
        argumentWord5 = Level14_87104Field(privateRecord20, short*, 0xE);
        argumentWord4 =
            Level14_87104Field(Level14_87104Field(temporaryWord5, void**, 0), short*, 0xC);
        if (argumentWord5 == argumentWord4)
            goto acceptOriginalHeading;
        rawWord2 = argumentWord4;
        if (argumentWord4 < 0)
            rawWord2 = argumentWord4 + 7;
        rawWord2 = (rawWord2 >> 3) * 8;
        rawWord2 = argumentWord4 - rawWord2;
        rawWord2 += 1;
        if (argumentWord5 == rawWord2)
            goto acceptOriginalHeading;
        rawWord3 = argumentWord4 + 6;
        rawWord2 = rawWord3;
        if (rawWord3 < 0)
            rawWord2 = argumentWord4 + 13;
        rawWord2 = (rawWord2 >> 3) * 8;
        rawWord2 = rawWord3 - rawWord2;
        rawWord2 += 1;
        if (argumentWord5 == rawWord2)
            goto acceptOriginalHeading;
        rawWord3 = argumentWord4 + 1;
        rawWord2 = rawWord3;
        if (rawWord3 < 0)
            rawWord2 = argumentWord4 + 8;
        rawWord2 = (rawWord2 >> 3) * 8;
        rawWord2 = rawWord3 - rawWord2;
        rawWord2 += 1;
        if (argumentWord5 == rawWord2)
            goto acceptOriginalHeading;
        rawWord3 = argumentWord4 + 5;
        rawWord2 = rawWord3;
        if (rawWord3 < 0)
            rawWord2 = argumentWord4 + 12;
        rawWord2 = (rawWord2 >> 3) * 8;
        rawWord2 = rawWord3 - rawWord2;
        rawWord2 += 1;
        if (argumentWord5 != rawWord2)
            goto originalRejectedHeading;
    acceptOriginalHeading:
        Level14_87104Field(ownerRecord19, signed char*, 0x4C) = 0x20;
        Level14_87104Field(ownerRecord19, signed char*, 0x4A) = 0x20;
        goto checkOriginalOwnerFlags;
    }
    goto checkOriginalOwnerFlags;
originalRejectedHeading:
    Level14_87104Field(ownerRecord19, signed char*, 76) = 0;
    Level14_87104Field(ownerRecord19, unsigned char*, 74) = 255;
    return;
checkOriginalOwnerFlags:
    if (((unsigned char)Level14_87104Field(ownerRecord19, unsigned char*, 0x48) < 0x1EU) &&
        (((Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x250) != 0) &&
          (Level14_87104Field(ownerRecord19, int*, 0x18) & 0x20000)) ||
         (Level14_87104Field(ownerRecord19, int*, 0x18) & 0x80000))) {
        Level14_87104PlayMobySoundEventView1(ownerRecord19, 0, 0);
        Level14_87104Call36A68View1(ownerRecord19, 1, 0, 0);
        Level14_87104DataSpawnFragmentsView1(
            4, 0x1C3, ownerRecord19, Level14_87104Field(privateRecord20, int*, 0x64), 0, 0x100);
        Level14_87104RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
        Level14_87104Call3BA00View1(ownerRecord19);
        Level14_87104Call369B8View1(ownerRecord19, 0x1E);
        goto destroyOriginalOwner;
    }
    rawWord3 = Level14_87104Field(ownerRecord19, unsigned char*, 72);
    rawWord2 = 34;
    MATCHING_KEEP(rawWord2);
    if (rawWord3 == rawWord2) {
        Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x20C) =
            (int)(Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x20C) | 0x10002000);
        temporaryWord7 = Level14_87104Field(privateRecord20, short*, 8);
        if (temporaryWord7 != 0) {
            if (temporaryWord7 == 5) {
                Level14_87104Data6C7C0View1 = 0xFF;
                retainedLoopOrByte18 = 0;
            } else {
                Level14_87104Data6C7C0View1 = 0;
                retainedLoopOrByte18 = 0;
            }
        spawnOriginalFirstGroup:
            if ((Level14_87104Data6C578View1 - Level14_87104Data6C574View1) >= 0x15) {
                retainedSpawnOrRecord17 = Level14_87104DataSpawnMobyView1(0x64, ownerRecord19);
                MATCHING_KEEP(retainedSpawnOrRecord17);
                if (retainedSpawnOrRecord17 != 0) {
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x48) = 0;
                    rawWord2 = Level14_87104RandBetweenView1(0, 10240);
                    argumentWord4 = 0;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 12);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = 10240;
                    rawWord3 -= 5120;
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 12) = rawWord3;
                    rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 500;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 16);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = 12288;
                    rawWord3 -= 5120;
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 16) = rawWord3;
                    rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 20);
                    MATCHING_KEEP(rawWord3);
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 20) = rawWord3;
                    Level14_87104Field(Level14_87104Field(retainedSpawnOrRecord17, void**, 0), int*,
                                       0x14) = 0x28;
                }
                retainedLoopOrByte18 += 1;
                if (retainedLoopOrByte18 < 0xA) {
                    goto spawnOriginalFirstGroup;
                }
            }
            retainedLoopOrByte18 = 0;
        spawnOriginalSecondGroup:
            if ((Level14_87104Data6C578View1 - Level14_87104Data6C574View1) >= 0x15) {
                retainedSpawnOrRecord17 = Level14_87104DataSpawnMobyView1(0x64, ownerRecord19);
                MATCHING_KEEP(retainedSpawnOrRecord17);
                if (retainedSpawnOrRecord17 != 0) {
                    retainedPrivateOrModeAddress16 =
                        Level14_87104Field(retainedSpawnOrRecord17, void**, 0);
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x48) = 3;
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x41) = 0;
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x4C) = 0;
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x4D) = 0;
                    Level14_87104Field(retainedPrivateOrModeAddress16, int*, 4) =
                        (int)(Level14_87104RandBetweenView1(0, 0x50) - 0x28);
                    Level14_87104Field(retainedPrivateOrModeAddress16, int*, 8) =
                        (int)(Level14_87104RandBetweenView1(0, 0x50) - 0x28);
                    Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0xC) =
                        Level14_87104RandBetweenView1(0x32, 0xC8);
                    rawWord2 = Level14_87104RandBetweenView1(0, 10240);
                    argumentWord4 = 0;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 12);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = 10240;
                    rawWord3 -= 5120;
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 12) = rawWord3;
                    rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 500;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 16);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = 12288;
                    rawWord3 -= 5120;
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 16) = rawWord3;
                    rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 20);
                    MATCHING_KEEP(rawWord3);
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 20) = rawWord3;
                    Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0x10) = 0;
                    Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0) = 0xC8;
                }
                retainedLoopOrByte18 += 1;
                if (retainedLoopOrByte18 < 8) {
                    goto spawnOriginalSecondGroup;
                }
            }
            retainedLoopOrByte18 = 0;
            do {
                retainedSpawnOrRecord17 =
                    Level14_87104Call391E8View1(1, 0x54, ownerRecord19, 0, 2, 0xC8, 0x100);
                MATCHING_KEEP(retainedSpawnOrRecord17);
                if (retainedSpawnOrRecord17 != 0) {
                    Level14_87104Field(Level14_87104Field(retainedSpawnOrRecord17, void**, 0),
                                       short*, 0xC) = 0x64;
                    rawWord2 = Level14_87104RandBetweenView1(0, 10240);
                    argumentWord4 = 0;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 12);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = 10240;
                    rawWord3 -= 5120;
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 12) = rawWord3;
                    rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 500;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                    rawWord3 = Level14_87104Field(retainedSpawnOrRecord17, int*, 16);
                    __asm__("" ::: "$5", "memory");
                    argumentWord5 = 12288;
                    rawWord3 -= 5120;
                    rawWord3 += rawWord2;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 16) = rawWord3;
                    temporaryWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x48) = 3;
                    Level14_87104Field(retainedSpawnOrRecord17, signed char*, 0x4F) = 0xA;
                    Level14_87104Field(retainedSpawnOrRecord17, int*, 0x14) =
                        (int)(Level14_87104Field(retainedSpawnOrRecord17, int*, 0x14) +
                              temporaryWord2);
                }
                retainedLoopOrByte18 += 1;
            } while (retainedLoopOrByte18 < 5);
            retainedLoopOrByte18 = 0;
            do {
                Level14_87104CopyVectorView1(&originalFrame.sp40, ownerRecord19 + 0xC);
                rawWord2 = Level14_87104RandBetweenView1(0, 10240);
                argumentWord4 = 0;
                argumentWord5 = 10240;
                __asm__(""
                        : "=r"(argumentWord5)
                        : "0"(argumentWord5), "r"(argumentWord4)
                        : "$3", "memory");
                rawWord3 = originalFrame.sp40;
                MATCHING_KEEP_CLOBBER(retainedLoopOrByte18, "memory");
                retainedLoopOrByte18 += 1;
                rawWord3 -= 5120;
                rawWord3 += rawWord2;
                originalFrame.sp40 = rawWord3;
                rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                argumentWord4 = 500;
                __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$3", "memory");
                rawWord3 = originalFrame.sp44;
                __asm__("" ::: "$5", "memory");
                argumentWord5 = 12288;
                rawWord3 -= 5120;
                rawWord3 += rawWord2;
                originalFrame.sp44 = rawWord3;
                rawWord2 = Level14_87104RandBetweenView1(argumentWord4, argumentWord5);
                argumentWord4 = 16;
                argumentWord5 = 70;
                argumentWord6 = (int)&originalFrame.sp40;
                rawWord3 = originalFrame.sp48;
                rawWord3 += rawWord2;
                originalFrame.sp48 = rawWord3;
                Level14_87104DataSpawnParticleView1(argumentWord4, argumentWord5, argumentWord6,
                                                    32);
            } while (retainedLoopOrByte18 < 0xA);
            Level14_87104Field(privateRecord20, short*, 8) =
                (short)((unsigned short)Level14_87104Field(privateRecord20, short*, 8) - 1);
        }
        argumentWord5 = 0x10002000;
        rawWord3 = (int)&Level14_87104Data70328View1 + 524;
        MATCHING_KEEP(rawWord3);
        rawWord2 = Level14_87104Field(rawWord3, int*, 0);
        argumentWord4 = 6;
        rawWord2 |= argumentWord5;
        Level14_87104Field(rawWord3, int*, 0) = rawWord2;
        if (Level14_87104Call21F3CView1(argumentWord4, argumentWord5) & 15) {
            Level14_87104Call3BA00View1(ownerRecord19);
        destroyOriginalOwner:
            Level14_87104DeleteMobyView1(ownerRecord19);
            return;
        }
        return;
        return;
    }
    rawWord2 = 33;
    MATCHING_KEEP(rawWord2);
    if (rawWord3 == rawWord2) {
        Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x20C) =
            (int)(Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x20C) | 0x10002000);
        if (Level14_87104CountTimerDownView1(privateRecord20 + 8, 2) != 0) {
            Level14_87104Call21ED8View1(0xA, 0xFC, 0);
            Level14_87104Call21ED8View1(9, 0xFC, 0);
            Level14_87104Call21ED8View1(6, 0xFC, 0);
            Level14_87104Field(ownerRecord19, unsigned char*, 0x48) = 0x22U;
            Level14_87104Call3BB10View1(ownerRecord19, 6, 0);
            Level14_87104Field(privateRecord20, short*, 8) = 5;
            return;
        }
        return;
    }
    rawWord2 = 32;
    MATCHING_KEEP(rawWord2);
    if (rawWord3 == rawWord2) {
        if ((({
                 argumentWord6 = (int)&Level14_87104Data6E048View1;
                 MATCHING_KEEP(argumentWord6);
                 Level14_87104Field(argumentWord6, int*, 0);
             }) == 128) ||
            (Level14_87104Field(argumentWord6, int*, 0) == 2)) {
            Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x20C) =
                (int)(Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0x20C) |
                      0x10002000);
            if (Level14_87104Data6C65CView1 != 0) {
                Level14_87104Field(Level14_87104Data6C65CView1, signed char*, 0x4C) = 0;
            }
            if (Level14_87104Field(argumentWord6, int*, 0) == 2) {
                Level14_87104Call21ED8View1(0xA, 0xFC, 0);
                argumentWord5 = 0;
                originalState31 = 31;
                originalByte255 = 255;
                __asm__("" ::"r"(originalState31), "r"(originalByte255) : "$6", "$7", "memory");
                argumentWord7 = 1;
                argumentWord6 = 3;
                __asm__("" ::"r"(originalState31), "r"(originalByte255), "r"(argumentWord7),
                        "r"(argumentWord6)
                        : "$4", "memory");
                argumentWord4 = privateRecord20;
                rawWord2 = 33;
                Level14_87104Field(ownerRecord19, unsigned char*, 72) = rawWord2;
                rawWord2 = 800;
                Level14_87104Field(privateRecord20, short*, 8) = rawWord2;
                do {
                    temporaryWord8 = Level14_87104Field(argumentWord4, int*, 0x48);
                    if (temporaryWord8 >= 0) {
                        Level14_87104Field(((temporaryWord8 * 0x58) + Level14_87104Data6C550View1),
                                           unsigned char*, 0x48) = originalState31;
                        Level14_87104Field(((Level14_87104Field(argumentWord4, int*, 0x48) * 0x58) +
                                            Level14_87104Data6C550View1),
                                           unsigned char*, 0x4A) = originalByte255;
                        if (argumentWord5 == argumentWord7) {
                            Level14_87104Field(
                                ((Level14_87104Field(privateRecord20, int*, 0x4C) * 0x58) +
                                 Level14_87104Data6C550View1),
                                signed char*, 0x49) = argumentWord6;
                        }
                    }
                    argumentWord5 += 1;
                    argumentWord4 += 4;
                } while (argumentWord5 < 3);
                return;
            }
        }
        return;
    }
    rawWord2 = 31;
    MATCHING_KEEP(rawWord2);
    if (rawWord3 == rawWord2) {
        retainedPrivateOrModeAddress16 = (int)&Level14_87104Data6E160View1;
        MATCHING_KEEP(retainedPrivateOrModeAddress16);
        if (Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0) == 0) {
            if (Level14_87104ApproximatePlanarDistanceView1(
                    ownerRecord19 + 0xC, (int)&Level14_87104Data70328View1) < 0x55F0) {
                Level14_87104Call13ACCView1(ownerRecord19, 0x13);
                Level14_87104Field(ownerRecord19, signed char*, 0x49) = 1;
            }
            if (Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0) != 0) {
                goto checkOriginalFarDistance31;
            }
        } else {
        checkOriginalFarDistance31:
            if (Level14_87104ApproximatePlanarDistanceView1(
                    ownerRecord19 + 0xC, (int)&Level14_87104Data70328View1) >= 0x5DC1) {
                Level14_87104Data6E160View1 = 0;
                Level14_87104Field(ownerRecord19, signed char*, 0x49) = 0;
            }
        }
        __asm__ volatile("" ::: "$4", "memory");
        rawWord3 = Level14_87104Data6E160View1;
        rawWord2 = 9;
        MATCHING_KEEP(rawWord2);
        if (rawWord3 != rawWord2) {
            argumentWord4 = 0;
            argumentWord6 = Level14_87104Data6C550View1;
            MATCHING_KEEP(argumentWord6);
            argumentWord5 = privateRecord20;
        scanOriginalFirstList:
            temporaryWord9 = Level14_87104Field(argumentWord5, int*, 0x20);
            if ((temporaryWord9 < 0) ||
                (Level14_87104Field(((temporaryWord9 * 0x58) + argumentWord6), unsigned char*,
                                    0x48) &
                 0x80)) {
                argumentWord4 += 1;
                argumentWord5 += 4;
                if (argumentWord4 >= 0xA) {
                    argumentWord4 = 0;
                    argumentWord7 = 38;
                    argumentWord6 = 48;
                    __asm__("" ::"r"(argumentWord7), "r"(argumentWord6) : "$5", "memory");
                    argumentWord5 = privateRecord20;
                    do {
                        temporaryWord10 = Level14_87104Field(argumentWord5, int*, 0x48);
                        if (temporaryWord10 >= 0) {
                            temporaryWord6 = (temporaryWord10 * 0x58) + Level14_87104Data6C550View1;
                            if (Level14_87104Field(temporaryWord6, unsigned char*, 0x48) ==
                                argumentWord7) {
                                Level14_87104Field(temporaryWord6, unsigned char*, 0x48) =
                                    argumentWord6;
                            }
                        }
                        argumentWord4 += 1;
                        argumentWord5 += 4;
                    } while (argumentWord4 < 3);
                    retainedSpawnOrRecord17 = Level14_87104Data6C550View1;
                    originalClass421 = 421;
                    if (Level14_87104Field(retainedSpawnOrRecord17, unsigned char*, 0x48) != 0xFF) {
                        originalClass422 = 422;
                        MATCHING_KEEP(originalClass421);
                        MATCHING_KEEP(originalClass422);
                        retainedLoopOrByte18 = 255;
                        retainedPrivateOrModeAddress16 = retainedSpawnOrRecord17 + 72;
                        do {
                            argumentWord4 =
                                Level14_87104Field(retainedPrivateOrModeAddress16, short*, -0x12);
                            if ((((argumentWord4 == 0x1A4) &&
                                  (retainedSpawnOrRecord17 != ownerRecord19)) ||
                                 (argumentWord4 == originalClass421) ||
                                 ((unsigned int)(argumentWord4 - 0x1D6) < 2U) ||
                                 ((unsigned int)(argumentWord4 - 0x1D8) < 2U) ||
                                 (argumentWord4 == 0x1C2) || (argumentWord4 == 0x1AD) ||
                                 (argumentWord4 == originalClass422)) &&
                                ((argumentWord4 != originalClass422) ||
                                 (Level14_87104Field(
                                      Level14_87104Field(retainedSpawnOrRecord17, int*, 0), int*,
                                      4) != -1))) {
                                Level14_87104Field(retainedPrivateOrModeAddress16, int*, -0x30) =
                                    (int)(Level14_87104Field(retainedPrivateOrModeAddress16, int*,
                                                             -0x30) |
                                          0xA0000);
                                Level14_87104Field(retainedPrivateOrModeAddress16, signed char*,
                                                   9) =
                                    Level14_87104PlanarHeadingLookupView1(
                                        Level14_87104Field(retainedPrivateOrModeAddress16, int*,
                                                           -0x3C) -
                                            Level14_87104Field(ownerRecord19, int*, 0xC),
                                        Level14_87104Field(retainedPrivateOrModeAddress16, int*,
                                                           -0x38) -
                                            Level14_87104Field(ownerRecord19, int*, 0x10),
                                        0);
                                Level14_87104Field(retainedPrivateOrModeAddress16, unsigned char*,
                                                   2) = retainedLoopOrByte18;
                            }
                            retainedPrivateOrModeAddress16 += 0x58;
                            retainedSpawnOrRecord17 += 0x58;
                        } while (Level14_87104Field(retainedPrivateOrModeAddress16, unsigned char*,
                                                    0) != retainedLoopOrByte18);
                    }
                    temporaryWord1 = Level14_87104Field(
                        Level14_87104Field(privateRecord20, void**, 0x5C), int*, 0xC);
                    Level14_87104Call13AE4View1(temporaryWord1, temporaryWord1 + 0x10);
                    rawWord2 = 0x20;
                    goto writeSharedOriginalOwnerState;
                } else {
                    goto scanOriginalFirstList;
                }
            }
        }
        return;
    }
    rawWord2 = 30;
    MATCHING_KEEP(rawWord2);
    if (rawWord3 == rawWord2) {
        Level14_87104Field(ownerRecord19, signed char*, 0x41) = 0;
        Level14_87104Field(ownerRecord19, signed char*, 0x4C) = 0;
        Level14_87104Field(ownerRecord19, signed char*, 0x4D) = 0;
        Level14_87104Field(ownerRecord19, int*, 8) = 0;
        retainedPrivateOrModeAddress16 = (int)&Level14_87104Data6E160View1;
        MATCHING_KEEP(retainedPrivateOrModeAddress16);
        if (Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0) == 0) {
            if (Level14_87104ApproximatePlanarDistanceView1(
                    ownerRecord19 + 0xC, (int)&Level14_87104Data70328View1) < 0x55F0) {
                Level14_87104Call13ACCView1(ownerRecord19, 0x13);
                Level14_87104Field(ownerRecord19, signed char*, 0x49) = 1;
            }
            if (Level14_87104Field(retainedPrivateOrModeAddress16, int*, 0) != 0) {
                goto checkOriginalFarDistance30;
            }
        } else {
        checkOriginalFarDistance30:
            if (Level14_87104ApproximatePlanarDistanceView1(
                    ownerRecord19 + 0xC, (int)&Level14_87104Data70328View1) >= 0x5DC1) {
                Level14_87104Data6E160View1 = 0;
                Level14_87104Field(ownerRecord19, signed char*, 0x49) = 0;
            }
        }
        argumentWord4 = 0;
        argumentWord6 = Level14_87104Data6C550View1;
        MATCHING_KEEP(argumentWord6);
        argumentWord5 = privateRecord20;
    scanOriginalFourRoots:
        rawWord2 = Level14_87104Field(argumentWord5, int*, 16);
        rawWord3 = rawWord2 * 88;
        rawWord3 += argumentWord6;
        rawWord2 = Level14_87104Field(rawWord3, unsigned char*, 72);
        if (rawWord2 & 128) {
            argumentWord4 += 1;
            argumentWord5 += 4;
            if (argumentWord4 < 4)
                goto scanOriginalFourRoots;
        }
        rawWord2 = 4;
        MATCHING_KEEP(rawWord2);
        if (argumentWord4 == rawWord2) {
            rawWord2 = 31;
            goto writeSharedOriginalOwnerState;
        }
        rawWord2 = 31;
        argumentWord4 =
            Level14_87104Field(Level14_87104Field(privateRecord20, void**, 0x54), void**, 0xC);
        if (Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0) <
            Level14_87104Field(argumentWord4, int*, 0)) {
            if (({
                    rawWord3 = Level14_87104Field((int)&Level14_87104Data70328View1, int*, 4);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = Level14_87104Field(argumentWord4, int*, 4);
                    rawWord2 < rawWord3;
                })) {
                retainedSpawnOrRecord17 = 1;
            } else {
                retainedSpawnOrRecord17 = 3;
                if (({
                        rawWord2 = Level14_87104Field(argumentWord4, int*, 0x14);
                        rawWord2 < rawWord3;
                    })) {
                    retainedSpawnOrRecord17 = 2;
                }
            }
        } else if (Level14_87104Field(argumentWord4, int*, 0x30) <
                   Level14_87104Field((int)&Level14_87104Data70328View1, int*, 0)) {
            if (({
                    rawWord3 = Level14_87104Field((int)&Level14_87104Data70328View1, int*, 4);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = Level14_87104Field(argumentWord4, int*, 0x34);
                    rawWord2 < rawWord3;
                })) {
                retainedSpawnOrRecord17 = 7;
            } else {
                retainedSpawnOrRecord17 = 5;
                if (({
                        rawWord2 = Level14_87104Field(argumentWord4, int*, 0x24);
                        rawWord2 < rawWord3;
                    })) {
                    retainedSpawnOrRecord17 = 6;
                }
            }
        } else {
            retainedSpawnOrRecord17 = 4;
            if (({
                    rawWord3 = Level14_87104Field((int)&Level14_87104Data70328View1, int*, 4);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = Level14_87104Field(argumentWord4, int*, 4);
                    rawWord2 < rawWord3;
                })) {
                retainedSpawnOrRecord17 = 8;
            }
        }
        Level14_87104Field(privateRecord20, signed char*, 0xB) = retainedSpawnOrRecord17;
        if (Level14_87104CountTimerDownView1(privateRecord20 + 8, 2) != 0) {
            rawWord3 = (int)&originalFrame.sp20;
            rawWord2 = Level14_87104Data6C7C4View1;
            rawWord2 *= 4;
            argumentWord5 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = Level14_87104Field(privateRecord20, int*, 104);
            rawWord3 = Level14_87104Field(argumentWord5, int*, 16);
            rawWord2 = rawWord2 < rawWord3;
            argumentWord4 = 429;
            if (rawWord2)
                goto originalSpawnAllowed;
            rawWord2 = 180;
            Level14_87104Field(privateRecord20, short*, 8) = rawWord2;
            return;
        originalSpawnAllowed:
            MATCHING_OBSERVE_VOLATILE(argumentWord5);
            rawWord2 = Level14_87104Field(argumentWord5, int*, 0);
            rawWord3 = (int)Level14_87104DataSpawnMobyView1;
            __asm__("" ::: "$5", "memory");
            argumentWord5 = (int)ownerRecord19;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3), "r"(argumentWord5));
            Level14_87104Field(privateRecord20, short*, 8) = rawWord2;
            temporaryWord3 = ((int (*)())rawWord3)(argumentWord4, argumentWord5);
            if (temporaryWord3 != 0) {
                retainedPrivateOrModeAddress16 = Level14_87104Field(temporaryWord3, void**, 0);
                Level14_87104Field(privateRecord20, int*, 0x68) =
                    (int)(Level14_87104Field(privateRecord20, int*, 0x68) + 1);
                Level14_87104RequestMobyAnimationView1(temporaryWord3, 1);
                Level14_87104Field(temporaryWord3, signed char*, 0x48) = 0x1F;
                Level14_87104Field(retainedPrivateOrModeAddress16, short*, 0x10) = 0x64;
                rawWord2 = Level14_87104Field(privateRecord20, int*, 84);
                MATCHING_KEEP(rawWord2);
                Level14_87104Field(retainedPrivateOrModeAddress16, int*, 4) = rawWord2;
                rawWord3 = Level14_87104Field(privateRecord20, int*, 88);
                __asm__("" ::: "$2", "memory");
                rawWord2 = -1;
                Level14_87104Field(retainedPrivateOrModeAddress16, short*, 12) = rawWord2;
                rawWord2 = 1;
                Level14_87104Field(retainedPrivateOrModeAddress16, short*, 14) = rawWord2;
                rawWord2 = retainedSpawnOrRecord17 < 4;
                MATCHING_KEEP_CLOBBER(rawWord2, "memory");
                Level14_87104Field(retainedPrivateOrModeAddress16, int*, 8) = rawWord3;
                if (rawWord2) {
                    argumentWord4 = 0;
                    goto originalSelectedRootIndex;
                }
                rawWord2 = 4;
                MATCHING_KEEP(rawWord2);
                if (retainedSpawnOrRecord17 == rawWord2) {
                    argumentWord4 = 1;
                    goto originalSelectedRootIndex;
                }
                rawWord2 = retainedSpawnOrRecord17 < 8;
                MATCHING_KEEP(rawWord2);
                argumentWord4 = 3;
                if (rawWord2)
                    argumentWord4 = 2;
            originalSelectedRootIndex:
                rawWord2 = argumentWord4 * 4;
                rawWord2 += privateRecord20;
                rawWord3 = Level14_87104Field(rawWord2, int*, 16);
                MATCHING_KEEP(rawWord3);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level14_87104Data6C550View1;
                retainedPrivateOrModeAddress16 = rawWord3 + rawWord2;
                rawWord2 = Level14_87104Field(retainedPrivateOrModeAddress16, unsigned char*, 72);
                if (rawWord2 & 128) {
                    argumentWord4 = 0;
                    argumentWord6 = rawWord3;
                    argumentWord5 = privateRecord20;
                scanOriginalFallbackRoots:
                    rawWord2 = Level14_87104Field(argumentWord5, int*, 16);
                    rawWord3 = rawWord2 * 88;
                    retainedPrivateOrModeAddress16 = argumentWord6 + rawWord3;
                    rawWord2 =
                        Level14_87104Field(retainedPrivateOrModeAddress16, unsigned char*, 72);
                    if (rawWord2 & 128) {
                        argumentWord4 += 1;
                        argumentWord5 += 4;
                        if (argumentWord4 < 4)
                            goto scanOriginalFallbackRoots;
                    }
                }
                if (({
                        rawWord2 = 4;
                        MATCHING_KEEP(rawWord2);
                        argumentWord4 == rawWord2;
                    }) ||
                    (Level14_87104CopyVectorView1(temporaryWord3 + 0xC,
                                                  retainedPrivateOrModeAddress16 + 0xC),
                     Level14_87104Field(temporaryWord3, unsigned char*, 0x46) =
                         (unsigned char)Level14_87104Field(retainedPrivateOrModeAddress16,
                                                           unsigned char*, 0x46),
                     Level14_87104Call35DDCView1(temporaryWord3, 0xC8, 0, 0, 0),
                     temporaryWord4 = Level14_87104Field(privateRecord20, unsigned char*, 0xA) - 1,
                     Level14_87104Field(privateRecord20, unsigned char*, 0xA) = temporaryWord4,
                     ((temporaryWord4 & 0xFF) == 0))) {
                    rawWord2 = 0x1F;
                    goto writeSharedOriginalOwnerState;
                }
            }
        }
        return;
    writeSharedOriginalOwnerState:
        Level14_87104Field(ownerRecord19, unsigned char*, 72) = rawWord2;
        return;
    }
    return;
}
#undef Level14_87104Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_14/moby", D_level_14_80074AF0);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_14/moby", D_level_14_80074AFC);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80087FC4.
* AI generated; not human reviewed. All1002 original instructions,five
* selectors and one zero padding word,1008 owned words, require exact
* native/linked words and every actual transfer/table destination.
* Frame78 saves S0..S7/RA; original SP10..4F local extent remains.
* Ordered signed remainder checks retain their original +0/+6/+1/+5
* producers and signed correction branches. Complete saved1/422/420,
* scan count3 and later heading/count/flag phases remain disjoint.
* Original raw32 scan bounds,record strides,field widths and signed
* deltas preserve both coordinate tests and byte writes. Constructors
* retain initialized full pointers and complete helper-return words
* through independent original argument and coordinate producers.
* Original unsigned particle shifts,zero stores,repeated pointer loads,
* four distinct spawn calls and late shared result/final helper remain.
* Complete T0 record byte offset feeds the complete low32 C product;
* no partialHI. Original retained5 and independent230 preserve final slots.
* Empty metadata reads initialized whole words/addresses or clobbers dead
* caller values before complete new producers; it emits zero CPU words.
* No fixedFP,undefined saved inputs,live alias overlap or pipeline changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence is binary identity
* after all gates. Next: human review and synchronized retail captures.
* Falsification: all native/linked words,actual targets,owned data,padding
* and full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 b28ddd2f2286e0280f9189c8c9e2454a13132fbdb543fda0894b0065377f91c0 */
#define Level14_87FC4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level14_87FC4Call1A310View1() __asm__("func_8001A310");
int Level14_87FC4CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level14_87FC4RandBetweenView1(int, int) __asm__("func_8003636C");
int Level14_87FC4Call3BA00View1() __asm__("func_8003BA00");
int Level14_87FC4Call3BB10View1() __asm__("func_8003BB10");
int Level14_87FC4PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level14_87FC4TransformVectorByBasisView1() __asm__("func_8004ED6C");
void Level14_87FC4CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level14_87FC4AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
int Level14_87FC4DeleteMobyView1() __asm__("func_80055B18");
int Level14_87FC4RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level14_87FC4Data6C550View1 __asm__("D_8006C550");
extern int Level14_87FC4Data6C574View1 __asm__("D_8006C574");
extern int Level14_87FC4Data6C578View1 __asm__("D_8006C578");
extern int Level14_87FC4Data6C704View1 __asm__("D_8006C704");
extern int Level14_87FC4Data6E020View1 __asm__("D_8006E020");
extern int Level14_87FC4Data6E024View1 __asm__("D_8006E024");
extern int Level14_87FC4Data70328View1 __asm__("D_80070328");
extern int Level14_87FC4Data71908View1 __asm__("D_80071908");
extern int Level14_87FC4Data71930View1 __asm__("D_80071930");
extern void* (*Level14_87FC4DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level14_87FC4DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
extern int (*Level14_87FC4Data743ACView1)() __asm__("unk_ovlheader_800743AC");
extern int (*Level14_87FC4Data743B0View1)() __asm__("unk_ovlheader_800743B0");
void func_level_14_80087FC4(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        retainedClass422 __asm__("$23");
    register int completeRecordByteOffset8 __asm__("$8");
    register void* ownerRecord18 __asm__("$18");
    register int privateRecord20 __asm__("$20"), retainedRecordOrVector16 __asm__("$16"),
        retainedRecord17 __asm__("$17"), retainedFlagOrCount19 __asm__("$19"),
        retainedClassOrHeading21 __asm__("$21"), retainedScanAttempts22 __asm__("$22");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C;
    } originalFrame;
    int temporaryWord1;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord7;
    int temporaryWord11;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord19;
    int temporaryWord20;
    int temporaryWord23;
    int temporaryWord24;
    int temporaryWord21;
    int temporaryWord22;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord14;
    ownerRecord18 = ownerParameter;
    MATCHING_KEEP(ownerRecord18);
    privateRecord20 = Level14_87FC4Field(ownerRecord18, void**, 0);
    if ((Level14_87FC4Field(privateRecord20, unsigned char*, 0xC) != 0) ||
        (Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) == 1)) {
        Level14_87FC4Field(ownerRecord18, unsigned char*, 0x4A) = 0xFF;
    }
    argumentWord5 = Level14_87FC4Field(privateRecord20, unsigned char*, 14);
    if (!argumentWord5)
        goto checkOriginalOwnerFlags;
    if ((unsigned char)Level14_87FC4Field(ownerRecord18, unsigned char*, 72) >= 2)
        goto checkOriginalOwnerFlags;
    rawWord3 = Level14_87FC4Field(privateRecord20, int*, 20);
    rawWord2 = rawWord3 * 88;
    rawWord3 = Level14_87FC4Data6C550View1;
    rawWord3 = rawWord3 + rawWord2;
    if (Level14_87FC4Field(rawWord3, unsigned char*, 72) & 128)
        goto checkOriginalOwnerFlags;
    rawWord2 = Level14_87FC4Field(rawWord3, int*, 0);
    argumentWord4 = Level14_87FC4Field(rawWord2, short*, 12);
    if (argumentWord5 == argumentWord4)
        goto writeOriginalDescriptor32;
    rawWord2 = argumentWord4;
    if (argumentWord4 < 0)
        rawWord2 = argumentWord4 + 7;
    rawWord2 = (rawWord2 >> 3) * 8;
    rawWord2 = argumentWord4 - rawWord2 + 1;
    if (argumentWord5 == rawWord2)
        goto writeOriginalDescriptor32;
    rawWord3 = argumentWord4 + 6;
    rawWord2 = rawWord3;
    if (rawWord3 < 0)
        rawWord2 = argumentWord4 + 13;
    rawWord2 = (rawWord2 >> 3) * 8;
    rawWord2 = rawWord3 - rawWord2 + 1;
    if (argumentWord5 == rawWord2)
        goto writeOriginalDescriptor32;
    rawWord3 = argumentWord4 + 1;
    rawWord2 = rawWord3;
    if (rawWord3 < 0)
        rawWord2 = argumentWord4 + 8;
    rawWord2 = (rawWord2 >> 3) * 8;
    rawWord2 = rawWord3 - rawWord2 + 1;
    if (argumentWord5 == rawWord2)
        goto writeOriginalDescriptor32;
    rawWord3 = argumentWord4 + 5;
    rawWord2 = rawWord3;
    if (rawWord3 < 0)
        rawWord2 = argumentWord4 + 12;
    rawWord2 = (rawWord2 >> 3) * 8;
    rawWord2 = rawWord3 - rawWord2 + 1;
    if (argumentWord5 != rawWord2)
        goto clearOriginalDescriptor;
writeOriginalDescriptor32:
    Level14_87FC4Field(ownerRecord18, unsigned char*, 76) = 32;
    goto checkOriginalOwnerFlags;
clearOriginalDescriptor:
    Level14_87FC4Field(ownerRecord18, unsigned char*, 76) = 0;
    if (!Level14_87FC4Field(privateRecord20, unsigned char*, 12) &&
        Level14_87FC4Field(ownerRecord18, unsigned char*, 72) != 1)
        return;
checkOriginalOwnerFlags:;
    {
        if ((Level14_87FC4Field(ownerRecord18, int*, 0x18) & 0x02000000) &&
            (((Level14_87FC4Field((int)&Level14_87FC4Data70328View1, int*, 8) -
               Level14_87FC4Field(ownerRecord18, int*, 0x14)) >= 0x5DD) ||
             (Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) == 5))) {
            Level14_87FC4Field(ownerRecord18, int*, 0x18) = 0;
            goto dispatchOriginalOwnerState;
        }
        if (((unsigned int)(Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) - 2) >= 2U) &&
            (((Level14_87FC4Field((int)&Level14_87FC4Data70328View1, int*, 0x250) != 0) &&
              (Level14_87FC4Field(ownerRecord18, int*, 0x18) & 0x20000)) ||
             (Level14_87FC4Field(ownerRecord18, int*, 0x18) & 0x020C0000))) {
            retainedScanAttempts22 = 3;
            if (Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) == 5) {
                argumentWord4 = Level14_87FC4Field(privateRecord20, int*, 0x10);
                if (argumentWord4 >= 0) {
                    Level14_87FC4Field(((argumentWord4 * 0x58) + Level14_87FC4Data6C550View1), int*,
                                       0x18) = (int)Level14_87FC4Field(ownerRecord18, int*, 0x18);
                }
                Level14_87FC4Call3BA00View1(ownerRecord18, argumentWord5);
                goto callSharedOriginalFinalHelper;
            }
            Level14_87FC4CopyVectorView1(&originalFrame.sp10, ownerRecord18 + 0xC);
            retainedFlagOrCount19 = 1;
            retainedClass422 = 422;
            retainedClassOrHeading21 = 420;
            originalFrame.sp18 += 4096;
        scanOriginalCollisionAttempts:
            if ((Level14_87FC4Call1A310View1(&originalFrame.sp10, 0xC00, 0, ownerRecord18) != 0) &&
                (Level14_87FC4Data71930View1 != 0) && (retainedScanAttempts22 != 0)) {
                temporaryWord18 = Level14_87FC4Field(Level14_87FC4Data71930View1, short*, 0x36);
                if ((temporaryWord18 == 0x1A5) || ((unsigned int)(temporaryWord18 - 0x1D6) < 2U) ||
                    ((unsigned int)(temporaryWord18 - 0x1D8) < 2U) || (temporaryWord18 == 0x1C2)) {
                    retainedRecordOrVector16 = Level14_87FC4Data71930View1;
                    retainedRecord17 = Level14_87FC4Field(retainedRecordOrVector16, void**, 0);
                    Level14_87FC4Field(retainedRecord17, signed char*, 0xC) = retainedFlagOrCount19;
                    if (Level14_87FC4Field(retainedRecord17, int*, 4) >= 0) {
                        temporaryWord8 =
                            Level14_87FC4Data743ACView1(retainedRecordOrVector16, 0, 1);
                        if (temporaryWord8 != 0) {
                            temporaryWord19 = Level14_87FC4Field(temporaryWord8, short*, 0x36);
                            if ((temporaryWord19 != retainedClass422) &&
                                (temporaryWord19 != retainedClassOrHeading21)) {
                                Level14_87FC4Field(Level14_87FC4Field(temporaryWord8, void**, 0),
                                                   signed char*, 0xD) = retainedFlagOrCount19;
                            }
                        }
                        temporaryWord12 =
                            Level14_87FC4Data743ACView1(retainedRecordOrVector16, 0, -1);
                        if (temporaryWord12 != 0) {
                            temporaryWord20 = Level14_87FC4Field(temporaryWord12, short*, 0x36);
                            if (temporaryWord20 != retainedClass422) {
                                if (temporaryWord20 != retainedClassOrHeading21) {
                                    Level14_87FC4Field(
                                        Level14_87FC4Field(temporaryWord12, void**, 0),
                                        signed char*, 0xD) = retainedFlagOrCount19;
                                }
                            }
                        }
                        Level14_87FC4Data743B0View1(retainedRecordOrVector16, 0, 0, -1);
                        Level14_87FC4Field(retainedRecord17, unsigned short*, 2) =
                            (unsigned short)(Level14_87FC4Field(retainedRecord17, unsigned short*,
                                                                2) -
                                             1);
                    }
                }
                retainedScanAttempts22 -= 1;
                originalFrame.sp18 = Level14_87FC4Data71908View1 - 0x64;
                Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) = 2U;
                Level14_87FC4Field(ownerRecord18, signed char*, 0x41) = 0;
                Level14_87FC4Field(ownerRecord18, signed char*, 0x4C) = 0;
                Level14_87FC4Field(ownerRecord18, signed char*, 0x4D) = 0;
                Level14_87FC4Field(privateRecord20, short*, 0xA) = 0x3C;
                goto scanOriginalCollisionAttempts;
            }
            argumentWord5 = Level14_87FC4Data6C550View1;
            rawWord2 = Level14_87FC4Data6C704View1;
            rawWord3 = Level14_87FC4Field(ownerRecord18, int*, 20);
            originalFrame.sp18 = rawWord3;
            if ((unsigned int)argumentWord5 < (unsigned int)rawWord2) {
                argumentWord7 = 429;
                argumentWord6 = 1;
                argumentWord4 = argumentWord5 + 16;
                do {
                    if (Level14_87FC4Field(argumentWord4, short*, 38) == argumentWord7 &&
                        !(Level14_87FC4Field(argumentWord4, unsigned char*, 56) & 128)) {
                        rawWord2 = Level14_87FC4Field(argumentWord4, int*, -4);
                        rawWord3 = Level14_87FC4Field(ownerRecord18, int*, 12);
                        rawWord2 -= rawWord3;
                        if (rawWord2 < 0)
                            rawWord2 = -rawWord2;
                        if (rawWord2 < 512) {
                            rawWord2 = Level14_87FC4Field(argumentWord4, int*, 0);
                            rawWord3 = Level14_87FC4Field(ownerRecord18, int*, 16);
                            rawWord2 -= rawWord3;
                            if (rawWord2 < 0)
                                rawWord2 = -rawWord2;
                            if (rawWord2 < 512) {
                                rawWord2 = Level14_87FC4Field(argumentWord5, int*, 0);
                                Level14_87FC4Field(rawWord2, unsigned char*, 1) = argumentWord6;
                            }
                        }
                    }
                    rawWord2 = Level14_87FC4Data6C704View1;
                    argumentWord5 += 88;
                    argumentWord4 += 88;
                } while ((unsigned int)argumentWord5 < (unsigned int)rawWord2);
            }
            argumentWord6 = 0;
            MATCHING_KEEP(argumentWord6);
            retainedFlagOrCount19 = 0;
            retainedClassOrHeading21 = -64;
            Level14_87FC4Field(ownerRecord18, unsigned char*, 70) =
                Level14_87FC4PlanarHeadingLookupView1(
                    Level14_87FC4Data6E020View1 - Level14_87FC4Field(ownerRecord18, int*, 12),
                    Level14_87FC4Data6E024View1 - Level14_87FC4Field(ownerRecord18, int*, 16),
                    argumentWord6);
        spawnOriginalClass23Sequence:
            if ((Level14_87FC4Data6C578View1 - Level14_87FC4Data6C574View1) >= 0x15) {
                retainedRecord17 = Level14_87FC4DataSpawnMobyView1(0x17, ownerRecord18);
                MATCHING_KEEP(retainedRecord17);
                if (retainedRecord17 != 0) {
                    retainedRecordOrVector16 = Level14_87FC4Field(retainedRecord17, void**, 0);
                    Level14_87FC4Field(retainedRecordOrVector16, int*, 0) = 0x50;
                    Level14_87FC4Field(retainedRecordOrVector16, int*, 4) =
                        (int)-Level14_87FC4RandBetweenView1(0, 0x96);
                    rawWord2 = Level14_87FC4RandBetweenView1(60, 150);
                    argumentWord4 = 100;
                    argumentWord5 = 1000;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4), "r"(rawWord2)
                            : "memory");
                    Level14_87FC4Field(retainedRecordOrVector16, int*, 8) = rawWord2;
                    rawWord3 = Level14_87FC4Field(ownerRecord18, unsigned char*, 70);
                    rawWord2 = 1;
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 72) = rawWord2;
                    rawWord3 -= retainedClassOrHeading21;
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 70) = rawWord3;
                    rawWord2 = Level14_87FC4RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 0;
                    rawWord3 = Level14_87FC4Field(retainedRecord17, int*, 20);
                    argumentWord5 = 1000;
                    rawWord3 += rawWord2;
                    Level14_87FC4Field(retainedRecord17, int*, 20) = rawWord3;
                    rawWord2 = Level14_87FC4RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 0;
                    rawWord3 = Level14_87FC4Field(retainedRecord17, int*, 12);
                    argumentWord5 = 1000;
                    rawWord3 -= 500;
                    rawWord3 += rawWord2;
                    Level14_87FC4Field(retainedRecord17, int*, 12) = rawWord3;
                    rawWord2 = Level14_87FC4RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 100;
                    rawWord3 = Level14_87FC4Field(retainedRecord17, int*, 16);
                    argumentWord5 = 200;
                    rawWord3 -= 500;
                    rawWord3 += rawWord2;
                    Level14_87FC4Field(retainedRecord17, int*, 16) = rawWord3;
                    rawWord2 = Level14_87FC4RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 32;
                    argumentWord5 = 90;
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 84) = rawWord2;
                    rawWord2 = (unsigned int)rawWord2 & 255U;
                    rawWord2 = (unsigned int)rawWord2 >> 1;
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 85) = rawWord2;
                    rawWord2 = (unsigned int)rawWord2 >> 1;
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 86) = rawWord2;
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 87) = 63;
                    Level14_87FC4Field(retainedRecord17, signed char*, 0x4F) =
                        Level14_87FC4RandBetweenView1(0x20, 0x5A);
                }
                retainedFlagOrCount19 += 1;
                retainedClassOrHeading21 += 0x20;
                if (retainedFlagOrCount19 < 5) {
                    goto spawnOriginalClass23Sequence;
                }
            }
            retainedFlagOrCount19 = 0;
        spawnOriginalClass421Sequence:
            if ((Level14_87FC4Data6C578View1 - Level14_87FC4Data6C574View1) >= 0x15) {
                retainedRecord17 = Level14_87FC4DataSpawnMobyView1(0x1A5, ownerRecord18);
                MATCHING_KEEP(retainedRecord17);
                if (retainedRecord17 != 0) {
                    temporaryWord2 = Level14_87FC4Field(retainedRecord17, void**, 0);
                    Level14_87FC4Field(retainedRecord17, signed char*, 0x41) = 0;
                    Level14_87FC4Field(retainedRecord17, signed char*, 0x4C) = 0;
                    Level14_87FC4Field(retainedRecord17, signed char*, 0x4D) = 0;
                    Level14_87FC4Field(retainedRecord17, int*, 0x14) =
                        (int)(Level14_87FC4Field(retainedRecord17, int*, 0x14) + 0x200);
                    temporaryWord21 = Level14_87FC4Field(ownerRecord18, unsigned char*, 0x46);
                    Level14_87FC4Field(retainedRecord17, unsigned char*, 0x46) = temporaryWord21;
                    if (retainedFlagOrCount19 == 8) {
                        Level14_87FC4Field(retainedRecord17, unsigned char*, 0x46) =
                            (unsigned char)(temporaryWord21 + 0x40);
                        Level14_87FC4Field(retainedRecord17, signed char*, 0x49) = 1;
                    }
                    Level14_87FC4Field(retainedRecord17, signed char*, 0x44) =
                        (signed char)(retainedFlagOrCount19 << 5);
                    Level14_87FC4Field(retainedRecord17, signed char*, 0x48) = 3;
                    Level14_87FC4Field(retainedRecord17, int*, 8) = 0;
                    Level14_87FC4Field(temporaryWord2, int*, 4) = -1;
                    Level14_87FC4Field(temporaryWord2, short*, 0xA) = 5;
                }
                retainedFlagOrCount19 += 1;
                if (retainedFlagOrCount19 < 9) {
                    goto spawnOriginalClass421Sequence;
                }
            }
            __asm__("" ::: "$4", "memory");
            Level14_87FC4DataSpawnParticleView1(0xA, 0x46, ownerRecord18 + 0xC, (int*)0x10);
            Level14_87FC4Call3BB10View1(ownerRecord18, 5, 0);
            if (Level14_87FC4Field(privateRecord20, int*, 4) >= 0) {
                temporaryWord13 = Level14_87FC4Data743ACView1(ownerRecord18, 0, 1);
                if (temporaryWord13 != 0) {
                    temporaryWord3 = Level14_87FC4Field(temporaryWord13, short*, 0x36);
                    if ((temporaryWord3 != 0x1A6) && (temporaryWord3 != 0x1A4)) {
                        Level14_87FC4Field(Level14_87FC4Field(temporaryWord13, void**, 0),
                                           signed char*, 0xD) = 1;
                    }
                }
                temporaryWord14 = Level14_87FC4Data743ACView1(ownerRecord18, 0, -1);
                if (temporaryWord14 != 0) {
                    temporaryWord4 = Level14_87FC4Field(temporaryWord14, short*, 0x36);
                    if ((temporaryWord4 != 0x1A6) && (temporaryWord4 != 0x1A4)) {
                        Level14_87FC4Field(Level14_87FC4Field(temporaryWord14, void**, 0),
                                           signed char*, 0xD) = 1;
                    }
                }
                Level14_87FC4Data743B0View1(ownerRecord18, 0, 0, -1);
                Level14_87FC4Field(privateRecord20, int*, 4) = -1;
            }
            if (retainedScanAttempts22 != 3) {
                return;
            }
            goto callSharedOriginalFinalHelper;
        }
    dispatchOriginalOwnerState:
        temporaryWord22 = Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48);
        switch (temporaryWord22) {
            case 4:
                Level14_87FC4Field(ownerRecord18, signed char*, 0x41) = 0;
                Level14_87FC4Field(ownerRecord18, signed char*, 0x4C) = 0;
                Level14_87FC4Field(ownerRecord18, signed char*, 0x4D) = 0;
                Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) = 5U;
                argumentWord4 = Level14_87FC4Field(privateRecord20, int*, 0x10);
                if (argumentWord4 >= 0) {
                    temporaryWord5 = (argumentWord4 * 0x58) + Level14_87FC4Data6C550View1;
                    if (!(Level14_87FC4Field(temporaryWord5, unsigned char*, 0x48) & 0x80)) {
                        Level14_87FC4CopyVectorView1(temporaryWord5 + 0xC, ownerRecord18 + 0xC);
                        return;
                    }
                    goto callSharedOriginalFinalHelper;
                } else {
                    default:
                        return;
                }
                break;
            case 0:
                temporaryWord15 = Level14_87FC4Field(ownerRecord18, short*, 0x36);
                if (Level14_87FC4Field(ownerRecord18, unsigned char*, 0x49) == 0) {
                    if (Level14_87FC4Field(privateRecord20, unsigned char*, 0xC) == 0) {
                        Level14_87FC4Field(ownerRecord18, unsigned char*, 0x49) = 1U;
                        goto checkOriginalPrivateFlag;
                    }
                    goto clearOriginalPrivateFlag;
                }
            checkOriginalPrivateFlag:
                if (Level14_87FC4Field(privateRecord20, unsigned char*, 0xC) != 0) {
                clearOriginalPrivateFlag:
                    Level14_87FC4Field(privateRecord20, unsigned char*, 0xC) = 0U;
                    Level14_87FC4CopyVectorView1(&originalFrame.sp20, ownerRecord18 + 0xC);
                    originalFrame.sp28 += 0x1F4;
                    if (Level14_87FC4Call1A310View1(&originalFrame.sp20, 0x1800, 0, 0) != 0) {
                        temporaryWord23 = 0;
                        if (Level14_87FC4Data71930View1 != 0) {
                            MATCHING_BARRIER("memory");
                            temporaryWord23 =
                                Level14_87FC4Field(Level14_87FC4Data71930View1, short*, 0x36);
                        }
                        if (((Level14_87FC4Field(ownerRecord18, int*, 0x14) -
                              Level14_87FC4Data71908View1) >= 0x1A) ||
                            (((temporaryWord23 == 0x1A5) ||
                              ((unsigned int)(temporaryWord23 - 0x1D6) < 2U) ||
                              ((unsigned int)(temporaryWord23 - 0x1D8) < 2U)) &&
                             (Level14_87FC4Field(Level14_87FC4Data71930View1, unsigned char*,
                                                 0x48) == 2))) {
                            if ((Level14_87FC4Field(ownerRecord18, short*, 0x36) == 0x1C2) ||
                                (Level14_87FC4Field(privateRecord20, unsigned char*, 0xF) != 0)) {
                                Level14_87FC4Field(ownerRecord18, unsigned char*, 0x48) = 1U;
                                Level14_87FC4Field(privateRecord20, short*, 8) = 0;
                                return;
                            }
                            argumentWord4 = Level14_87FC4DataSpawnMobyView1(470, ownerRecord18);
                            MATCHING_KEEP(argumentWord4);
                            argumentWord6 = 1;
                            if (argumentWord4) {
                                rawWord3 = 255;
                                Level14_87FC4Field(argumentWord4, unsigned char*, 72) =
                                    argumentWord6;
                                rawWord2 = Level14_87FC4Field(ownerRecord18, unsigned char*, 58);
                                argumentWord5 = Level14_87FC4Field(argumentWord4, int*, 0);
                                if (rawWord2 == rawWord3)
                                    Level14_87FC4Field(argumentWord4, unsigned char*, 73) = 0;
                                else
                                    Level14_87FC4Field(argumentWord4, unsigned char*, 73) =
                                        argumentWord6;
                                Level14_87FC4Field(argumentWord5, short*, 8) = 0;
                                goto callSharedOriginalFinalHelper;
                            }
                            Level14_87FC4Field(privateRecord20, unsigned char*, 0xC) = 1U;
                            return;
                        }
                    }
                } else if ((Level14_87FC4Field(privateRecord20, unsigned char*, 0xD) != 0) &&
                           ((temporaryWord15 == 0x1A5) ||
                            ((unsigned int)(temporaryWord15 - 0x1D6) < 2U) ||
                            ((unsigned int)(temporaryWord15 - 0x1D8) < 2U)) &&
                           (Level14_87FC4Field(privateRecord20, unsigned char*, 0xF) == 0)) {
                    retainedFlagOrCount19 = 0;
                    if (Level14_87FC4Field(privateRecord20, int*, 4) >= 0) {
                        retainedRecordOrVector16 = 0;
                        MATCHING_KEEP(retainedRecordOrVector16);
                        Level14_87FC4Field(privateRecord20, unsigned char*, 13) = 0;
                        rawWord2 = Level14_87FC4Data743ACView1(ownerRecord18, 0, 1);
                        argumentWord4 = (int)ownerRecord18;
                        argumentWord5 = 0;
                        argumentWord6 = -1;
                        __asm__(""
                                : "=r"(argumentWord6)
                                : "0"(argumentWord6), "r"(argumentWord5), "r"(argumentWord4),
                                  "r"(rawWord2)
                                : "memory");
                        rawWord3 = (int)Level14_87FC4Data743ACView1;
                        __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2));
                        retainedRecord17 = rawWord2;
                        temporaryWord6 =
                            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6);
                        if ((retainedRecord17 != 0) &&
                            ((temporaryWord16 = Level14_87FC4Field(retainedRecord17, short*, 0x36),
                              retainedFlagOrCount19 = retainedRecordOrVector16,
                              (temporaryWord16 == 0x1A5)) ||
                             ((unsigned int)(temporaryWord16 - 0x1D6) < 2U) ||
                             ((unsigned int)(temporaryWord16 - 0x1D8) < 2U))) {
                            retainedFlagOrCount19 = 1;
                        }
                        if ((temporaryWord6 != 0) &&
                            ((temporaryWord17 = Level14_87FC4Field(temporaryWord6, short*, 0x36),
                              retainedRecordOrVector16 = 0, (temporaryWord17 == 0x1A5)) ||
                             ((unsigned int)(temporaryWord17 - 0x1D6) < 2U) ||
                             ((unsigned int)(temporaryWord17 - 0x1D8) < 2U))) {
                            retainedRecordOrVector16 = 1;
                        }
                        if ((retainedFlagOrCount19 != 0) &&
                            (Level14_87FC4Field(retainedRecord17, unsigned char*, 0x48) == 0)) {
                            if (retainedRecordOrVector16 != 0) {
                                if (Level14_87FC4Field(temporaryWord6, unsigned char*, 0x48) == 0) {
                                    rawWord2 =
                                        Level14_87FC4DataSpawnMobyView1(0x1D9, ownerRecord18);
                                    MATCHING_OBSERVE2_VOLATILE(rawWord2, privateRecord20);
                                    goto checkSharedOriginalHelperResult;
                                } else {
                                    goto spawnOriginalClass472;
                                }
                            } else {
                            spawnOriginalClass472:
                                rawWord2 = Level14_87FC4DataSpawnMobyView1(0x1D8, ownerRecord18);
                                MATCHING_OBSERVE2_VOLATILE(rawWord2, retainedFlagOrCount19);
                                goto checkSharedOriginalHelperResult;
                            }
                        } else if (retainedRecordOrVector16 != 0) {
                            if (Level14_87FC4Field(temporaryWord6, unsigned char*, 0x48) == 0) {
                                rawWord2 = Level14_87FC4DataSpawnMobyView1(0x1D7, ownerRecord18);
                                MATCHING_OBSERVE2_VOLATILE(rawWord2, retainedRecordOrVector16);
                                goto checkSharedOriginalHelperResult;
                            } else {
                                goto spawnOriginalClass470;
                            }
                        } else {
                        spawnOriginalClass470:
                            rawWord2 = Level14_87FC4DataSpawnMobyView1(0x1D6, ownerRecord18);
                            MATCHING_OBSERVE2_VOLATILE(rawWord2, ownerRecord18);
                            goto checkSharedOriginalHelperResult;
                        }
                        goto checkSharedOriginalHelperResult;
                    }
                }
                break;
            case 1:
                Level14_87FC4CopyVectorView1(&originalFrame.sp30, ownerRecord18 + 0xC);
                originalFrame.sp38 += 0x64;
                if (Level14_87FC4Call1A310View1(&originalFrame.sp30, 0x1800, 0, 0) != 0) {
                    rawWord2 = Level14_87FC4Data71930View1;
                    rawWord3 = Level14_87FC4Field(ownerRecord18, unsigned char*, 73);
                    argumentWord5 = Level14_87FC4Field(rawWord2, short*, 54);
                    temporaryWord24 = 0;
                    if (rawWord3 == 0) {
                        MATCHING_BARRIER("memory");
                        if ((Level14_87FC4Data71930View1 == 0) || (argumentWord5 == 0x1A6) ||
                            (argumentWord5 == 0x1A4) ||
                            ((argumentWord5 == 0x1A5) &&
                             ((unsigned int)(Level14_87FC4Field(Level14_87FC4Data71930View1,
                                                                unsigned char*, 0x48) -
                                             4) < 2U)) ||
                            ((Level14_87FC4Field(
                                  Level14_87FC4Field(Level14_87FC4Data71930View1, void**, 0),
                                  unsigned char*, 0xC) == 0) &&
                             (Level14_87FC4Field(Level14_87FC4Data71930View1, unsigned char*,
                                                 0x48) == 0))) {
                            temporaryWord24 = 1;
                        }
                    }
                    if (((temporaryWord24 == 1) ||
                         ((Level14_87FC4Field(ownerRecord18, int*, 0x14) -
                           Level14_87FC4Data71908View1) <
                          (Level14_87FC4Field(privateRecord20, short*, 8) + 0x32))) &&
                        ((Level14_87FC4Data71930View1 == 0) ||
                         ((argumentWord5 != 0x1A5) &&
                          ((unsigned int)(argumentWord5 - 0x1D6) >= 2U) &&
                          ((unsigned int)(argumentWord5 - 0x1D8) >= 2U)) ||
                         (Level14_87FC4Field(Level14_87FC4Data71930View1, unsigned char*, 0x48) !=
                          2))) {
                        MATCHING_OBSERVE_VOLATILE(argumentWord5);
                        if (Level14_87FC4Field(privateRecord20, int*, 4) >= 0) {
                            temporaryWord9 = Level14_87FC4Data743ACView1(ownerRecord18, 0, 1);
                            if (temporaryWord9 != 0) {
                                temporaryWord7 = Level14_87FC4Field(temporaryWord9, short*, 0x36);
                                if ((temporaryWord7 != 0x1A6) && (temporaryWord7 != 0x1A4)) {
                                    Level14_87FC4Field(
                                        Level14_87FC4Field(temporaryWord9, void**, 0), signed char*,
                                        0xD) = 1;
                                }
                            }
                            temporaryWord10 = Level14_87FC4Data743ACView1(ownerRecord18, 0, -1);
                            if (temporaryWord10 != 0) {
                                temporaryWord1 = Level14_87FC4Field(temporaryWord10, short*, 0x36);
                                if ((temporaryWord1 != 0x1A6) && (temporaryWord1 != 0x1A4)) {
                                    Level14_87FC4Field(
                                        Level14_87FC4Field(temporaryWord10, void**, 0),
                                        signed char*, 0xD) = 1;
                                }
                            }
                            argumentWord4 = (int)ownerRecord18;
                            argumentWord5 = 0;
                            completeRecordByteOffset8 = Level14_87FC4Data6C550View1;
                            argumentWord6 = 0;
                            completeRecordByteOffset8 =
                                (int)ownerRecord18 - completeRecordByteOffset8;
                            Level14_87FC4Data743B0View1(argumentWord4, argumentWord5, argumentWord6,
                                                        -(completeRecordByteOffset8 * 0x45D1745D) >>
                                                            3);
                        }
                        rawWord2 = 32;
                        Level14_87FC4Field(ownerRecord18, unsigned char*, 74) = rawWord2;
                        rawWord3 = Level14_87FC4Data71908View1;
                        rawWord2 = 1;
                        Level14_87FC4Field(ownerRecord18, unsigned char*, 72) = 0;
                        Level14_87FC4Field(ownerRecord18, unsigned char*, 73) = rawWord2;
                        Level14_87FC4Field(ownerRecord18, int*, 20) = rawWord3;
                        return;
                    }
                    goto updateOriginalSignedCountdown;
                }
            updateOriginalSignedCountdown:
                Level14_87FC4Field(ownerRecord18, int*, 0x14) =
                    (int)(Level14_87FC4Field(ownerRecord18, int*, 0x14) -
                          Level14_87FC4Field(privateRecord20, short*, 8));
                Level14_87FC4Field(privateRecord20, short*, 8) =
                    (short)((unsigned short)Level14_87FC4Field(privateRecord20, short*, 8) + 0xC);
                return;
            case 3:
                originalFrame.sp40 = 0;
                originalFrame.sp44 = 0x96;
                originalFrame.sp48 = 0;
                rawWord2 = Level14_87FC4Field(privateRecord20, short*, 10);
                retainedFlagOrCount19 = 5;
                if (rawWord2 == retainedFlagOrCount19) {
                    originalFrame.sp44 = 0x2BC;
                }
                Level14_87FC4RefreshMobySpatialGridAndBasisView1(ownerRecord18, 4);
                Level14_87FC4TransformVectorByBasisView1(ownerRecord18 + 0x20, &originalFrame.sp40,
                                                         &originalFrame.sp40);
                retainedRecordOrVector16 = ownerRecord18 + 0xC;
                Level14_87FC4AddVectorView1(retainedRecordOrVector16, retainedRecordOrVector16,
                                            &originalFrame.sp40);
                originalFrame.sp40 = 0;
                originalFrame.sp44 = 0;
                originalFrame.sp48 =
                    (retainedFlagOrCount19 - Level14_87FC4Field(privateRecord20, short*, 0xA)) *
                    -0xF;
                argumentWord4 = Level14_87FC4DataSpawnParticleView1(
                    1, 0x3C, retainedRecordOrVector16, &originalFrame.sp40);
                if (argumentWord4) {
                    rawWord2 = 1;
                    rawWord3 = Level14_87FC4Field(ownerRecord18, unsigned char*, 73);
                    if (rawWord3 != rawWord2) {
                        rawWord2 = 230;
                        MATCHING_OBSERVE_VOLATILE(rawWord2);
                        rawWord2 = Level14_87FC4Field(privateRecord20, short*, 10);
                        rawWord2 = retainedFlagOrCount19 - rawWord2;
                        rawWord3 = rawWord2 * 22;
                        rawWord2 = -36;
                        rawWord2 -= rawWord3;
                    } else
                        rawWord2 = 230;
                    Level14_87FC4Field(argumentWord4, unsigned char*, 10) = rawWord2;
                }
                temporaryWord11 =
                    (unsigned short)Level14_87FC4Field(privateRecord20, short*, 0xA) - 1;
                Level14_87FC4Field(privateRecord20, short*, 0xA) = temporaryWord11;
                if ((temporaryWord11 << 0x10) > 0) {
                    return;
                }
                goto callSharedOriginalFinalHelper;
            case 2:
                rawWord2 = Level14_87FC4CountTimerDownView1(privateRecord20 + 10, 2);
            checkSharedOriginalHelperResult:
                if (!rawWord2)
                    return;
            callSharedOriginalFinalHelper:
                Level14_87FC4DeleteMobyView1(ownerRecord18);
                return;
        }
    }
}
#undef Level14_87FC4Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original594. AI generated; not human reviewed.
 * UNINSTALLED proposal: one existing full32 GP20/S4 machine ownerInput at entry,
 * retaining all later conditional S4 producers. This is not an ordinary C
 * initializer or a new ABI argument. Actual frozen RTL/noCPU/source/helper/
 * alias/native/control/originalFrame/fullimage certificates remain mandatory. */
#define Level14_88F6CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level14_88F6CKeep(v) __asm__("" : "=r"(v) : "0"(v))
int Level14_88F6C_func_80034F40() __asm__("func_80034F40");
int Level14_88F6CTurnMobyTowardHeading() __asm__("func_8003585C");
int Level14_88F6CCountTimerDown() __asm__("func_800359A4");
int Level14_88F6C_func_80036A68() __asm__("func_80036A68");
int Level14_88F6C_func_800391E8() __asm__("func_800391E8");
int Level14_88F6C_func_8003BA00() __asm__("func_8003BA00");
int Level14_88F6CPlayMobySoundEvent() __asm__("func_8003BABC");
int Level14_88F6CPlanarHeadingLookup() __asm__("func_8004E880");
int Level14_88F6CTransformVectorByBasis() __asm__("func_8004ED6C");
int Level14_88F6CAddVector() __asm__("func_8004F194");
int Level14_88F6CAbsoluteByteAngleDelta() __asm__("func_8004F264");
int Level14_88F6CApproachByteAngle() __asm__("func_8004F2EC");
int Level14_88F6CApproximatePlanarDistance() __asm__("func_8004F334");
int Level14_88F6CDeleteMoby() __asm__("func_80055B18");
int Level14_88F6CRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level14_88F6C_func_80055E84() __asm__("func_80055E84");
extern int Level14_88F6C_D_8006C550 __asm__("D_8006C550");
extern int Level14_88F6C_D_8006C574 __asm__("D_8006C574");
extern int Level14_88F6C_D_8006C578 __asm__("D_8006C578");
extern int Level14_88F6C_D_8006C648 __asm__("D_8006C648");
extern int Level14_88F6C_D_8006C770 __asm__("D_8006C770");
extern int Level14_88F6C_D_8006E020 __asm__("D_8006E020");
extern int Level14_88F6C_D_8006E024 __asm__("D_8006E024");
extern int Level14_88F6C_D_8006E344 __asm__("D_8006E344");
extern int Level14_88F6C_D_8006E788 __asm__("D_8006E788");
extern unsigned char Level14_88F6C_D_80070328 __asm__("D_80070328");
extern int (*Level14_88F6CSpawnFragments)() __asm__("SpawnFragments");
extern int (*Level14_88F6CSpawnMoby)() __asm__("SpawnMoby");
extern int (*Level14_88F6CSpawnParticle)() __asm__("SpawnParticle");
extern int (*Level14_88F6Cunk_ovlheader_800743AC)() __asm__("unk_ovlheader_800743AC");
void func_level_14_80088F6C(void* ownerInput) {
    register int saved16 __asm__("$16"), owner __asm__("$17"), saved18 __asm__("$18"),
        privateState __asm__("$19"), saved20 __asm__("$20"), saved21 __asm__("$21");
    register int result __asm__("$2"), scratch __asm__("$3"), argument0 __asm__("$4"),
        argument1 __asm__("$5"), argument2 __asm__("$6"), argument3 __asm__("$7");
    int initialFlag;
    struct {
        int sp20, sp24, sp28;
        unsigned char unusedOriginal2C[4];
    } originalFrame;

    int var_v0_2;

    int temp_v0_7;

    int temp_v1_3;

    int temp_v1_4;

    int temp_v1_5;

    int var_v0_3;

    int var_v0_4;

    int var_v0_5;

    int var_v0_6;

    int temp_v0;

    int temp_v0_2;

    int temp_v0_3;

    int temp_v0_5;

    int temp_v0_6;

    int temp_v0_8;

    int temp_v1_2;

    result = Level14_88F6CField((int)&Level14_88F6C_D_80070328, int*, 0x250);
    owner = (int)ownerInput;
    privateState = Level14_88F6CField(owner, int*, 0);
    __asm__("" : "=r"(owner), "=r"(privateState) : "0"(owner), "1"(privateState), "r"(result));
    __asm__("" : "=r"(saved20));
    if (result == 0) {
        goto block_2;
    }
    if (Level14_88F6CField(owner, int*, 0x18) & 0x20000) {
        goto block_3;
    }
block_2:
    if (!(Level14_88F6CField(owner, int*, 0x18) & 0x80000)) {
        goto block_28;
    }
block_3:
    saved18 = (int)&Level14_88F6C_D_8006E788;
    goto loop_15;
block_4:
    scratch = Level14_88F6CField(saved16, short*, 0x36);
    if ((unsigned int)(scratch - 0x1A4) < 2U) {
        goto block_9;
    }
    if ((unsigned int)(scratch - 0x1D6) < 2U) {
        goto block_9;
    }
    if ((unsigned int)(scratch - 0x1D8) < 2U) {
        goto block_9;
    }
    if (scratch == 0x1C2) {
        goto block_9;
    }
    if (scratch != 0x1AD) {
        goto loop_15;
    }
block_9:
    if (Level14_88F6CField(saved16, unsigned char*, 0x48) & 0x80) {
        goto loop_15;
    }
    result = Level14_88F6CField(owner, int*, 0x14);
    scratch = Level14_88F6CField(saved16, int*, 0x14);
    result -= scratch;
    if (result >= 0) {
        goto block_12;
    }
    result = -result;
block_12:
    if (result >= 0x800) {
        goto loop_15;
    }
    if (Level14_88F6CApproximatePlanarDistance(owner + 0xC, saved16 + 0xC) >= 0xC00) {
        goto loop_15;
    }
    Level14_88F6CField(saved16, int*, 0x18) =
        (int)(Level14_88F6CField(saved16, int*, 0x18) | 0x80000);
    Level14_88F6CField(saved16, unsigned char*, 0x51) = Level14_88F6CPlanarHeadingLookup(
        Level14_88F6CField(saved16, int*, 0xC) - Level14_88F6CField(owner, int*, 0xC),
        Level14_88F6CField(saved16, int*, 0x10) - Level14_88F6CField(owner, int*, 0x10), 0);
loop_15:
    saved16 = Level14_88F6CField(saved18, int*, 0);
    saved18 += 4;
    if (saved16 != 0) {
        goto block_4;
    }
    Level14_88F6CKeep(saved16);
    Level14_88F6C_func_80036A68(owner, 1, 0, 0);
    Level14_88F6CPlayMobySoundEvent(owner, 0, 0);
    argument0 = 4;
    argument1 = 0x1A7;
    argument2 = owner;
    Level14_88F6CKeep(argument0);
    Level14_88F6CKeep(argument1);
    Level14_88F6CKeep(argument2);
    saved16 = 0;
    saved18 = 2;
    saved21 = 0xC8;
    MATCHING_OBSERVE_VOLATILE(saved21);
    result = 0x100;
    Level14_88F6CKeep(result);
    saved20 = 0x100;
    Level14_88F6CSpawnFragments(argument0, argument1, argument2,
                                Level14_88F6CField(privateState, int*, 0x18), 0, result);
    result = Level14_88F6CField(owner, int*, 0x14);
    __asm__("" : "=r"(owner) : "0"(owner), "r"(privateState), "r"(result));
    privateState = 0x1C;
    result += 0x400;
    Level14_88F6CField(owner, int*, 0x14) = result;
    __asm__ volatile("" ::"m"(Level14_88F6CField(owner, int*, 0x14)));
    argument0 = 1;
loop_17:
    result = Level14_88F6C_func_800391E8(argument0, 0x54, owner, 0, saved18, saved21, saved20);
    if (!result)
        goto block_19;
    Level14_88F6CField(result, unsigned char*, 0x48) = saved18;
    Level14_88F6CField(result, unsigned char*, 0x4F) = privateState;
block_19:
    saved16++;
    result = saved16 < 5;
    argument0 = 1;
    if (result)
        goto loop_17;
    MATCHING_OBSERVE_VOLATILE(argument0);
    argument2 = 0;
    Level14_88F6CKeep(argument2);
    saved16 = 0;
    saved18 = 0;
    Level14_88F6CField(owner, unsigned char*, 0x46) = Level14_88F6CPlanarHeadingLookup(
        Level14_88F6C_D_8006E020 - Level14_88F6CField(owner, int*, 0xC),
        Level14_88F6C_D_8006E024 - Level14_88F6CField(owner, int*, 0x10), argument2);
loop_21:
    result = Level14_88F6C_D_8006C578;
    scratch = Level14_88F6C_D_8006C574;
    result -= scratch;
    result = result < 0x15;
    argument0 = 0x19B;
    if (result) {
        goto block_25;
    }
    result = Level14_88F6CSpawnMoby(argument0, owner);
    Level14_88F6CKeep(result);
    argument0 = result;
    result = 1;
    if (!argument0)
        goto block_24;
    Level14_88F6CField(argument0, unsigned char*, 0x41) = 0;
    Level14_88F6CField(argument0, unsigned char*, 0x4C) = 0;
    Level14_88F6CField(argument0, unsigned char*, 0x4D) = 0;
    scratch = Level14_88F6CField(owner, unsigned char*, 0x46);
    Level14_88F6CField(argument0, unsigned char*, 0x48) = result;
    Level14_88F6CField(argument0, unsigned char*, 0x46) = scratch;
    scratch = Level14_88F6CField(argument0, int*, 0);
    result = 5;
    Level14_88F6CField(argument0, unsigned char*, 0x44) = saved18;
    Level14_88F6CField(argument0, int*, 8) = 0;
    Level14_88F6CField(scratch, int*, 0) = result;
block_24:
    saved16 += 1;
    saved18 += 0x33;
    if (saved16 < 5) {
        goto loop_21;
    }
block_25:
    Level14_88F6CSpawnParticle(0x10, 0x46, owner + 0xC, 0x10);
    temp_v0_3 = Level14_88F6CSpawnMoby(0x64, owner);
    if (temp_v0_3 == 0) {
        goto block_27;
    }
    Level14_88F6CField(temp_v0_3, signed char*, 0x48) = 0;
block_27:
    Level14_88F6C_func_8003BA00(owner);
    Level14_88F6CDeleteMoby(owner);
    return;
block_28:
    argument1 = Level14_88F6CField(privateState, unsigned char*, 0xF);
    if (argument1 == 0) {
        goto block_45;
    }
    temp_v1_2 = Level14_88F6C_D_8006C550 + (Level14_88F6CField(privateState, int*, 0x14) * 0x58);
    if (Level14_88F6CField(temp_v1_2, unsigned char*, 0x48) & 0x80) {
        goto block_45;
    }
    argument0 = Level14_88F6CField(Level14_88F6CField(temp_v1_2, int*, 0), short*, 0xC);
    if (argument1 == argument0) {
        goto block_43;
    }
    result = argument0;
    if (argument0 >= 0)
        goto modFirst;
    result = argument0 + 7;
modFirst:
    result >>= 3;
    result *= 8;
    result = argument0 - result;
    result++;
    if (argument1 == result)
        goto block_43;
    scratch = argument0 + 6;
    result = scratch;
    if (scratch >= 0)
        goto modSecond;
    result = argument0 + 13;
modSecond:
    result >>= 3;
    result *= 8;
    result = scratch - result;
    result++;
    if (argument1 == result)
        goto block_43;
    scratch = argument0 + 1;
    result = scratch;
    if (scratch >= 0)
        goto modThird;
    result = argument0 + 8;
modThird:
    result >>= 3;
    result *= 8;
    result = scratch - result;
    result++;
    if (argument1 == result)
        goto block_43;
    scratch = argument0 + 5;
    result = scratch;
    if (scratch >= 0)
        goto modFourth;
    result = argument0 + 12;
modFourth:
    result >>= 3;
    result *= 8;
    result = scratch - result;
    result++;
    if (argument1 != result)
        goto block_44;
block_43:
    Level14_88F6CField(owner, signed char*, 0x4C) = 0x20;
    Level14_88F6CField(owner, signed char*, 0x4A) = 0x20;
    goto block_45;
block_44:
    Level14_88F6CField(owner, signed char*, 0x4C) = 0;
    result = 0xFF;
    Level14_88F6CField(owner, unsigned char*, 0x4A) = result;
    return;
block_45:
    saved16 = Level14_88F6CField(owner, unsigned char*, 0x48);
    if (saved16 == 1) {
        goto block_101;
    }
    if ((int)saved16 >= 2) {
        goto block_49;
    }
    if (saved16 == 0) {
        goto block_51;
    }
    return;
block_49:
    if (saved16 != 0x14) {
        goto block_108;
    }
    Level14_88F6CField(privateState, unsigned char*, 0xA) =
        (unsigned char)Level14_88F6CField(owner, unsigned char*, 0x46);
    Level14_88F6CField(owner, unsigned char*, 0x48) = 0U;
    return;
block_51:
    Level14_88F6CRefreshMobySpatialGridAndBasis(owner, 5);
    Level14_88F6CCountTimerDown(privateState + 8, 2);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner, "$16");
    argument2 = 0;
    if (Level14_88F6CField(privateState, unsigned char*, 0xB) == 0) {
        goto block_97;
    }
    saved18 = 1;
    saved16 = Level14_88F6CPlanarHeadingLookup(
        Level14_88F6CField((int)&Level14_88F6C_D_80070328, int*, 0) -
            Level14_88F6CField(owner, int*, 0xC),
        Level14_88F6CField((int)&Level14_88F6C_D_80070328, int*, 4) -
            Level14_88F6CField(owner, int*, 0x10),
        argument2);
    argument0 = Level14_88F6CAbsoluteByteAngleDelta(
        saved16, Level14_88F6CField(owner, unsigned char*, 0x46));
    scratch = Level14_88F6C_D_8006C648;
    result = 3;
    if (scratch == result)
        goto block_55;
    result = 4;
    if (scratch != result)
        goto block_56;
    saved18 = 2;
block_55:
    result = argument0 < saved18;
    goto capReady;
block_56:
    result = argument0 < saved18;
capReady:
    if (!result)
        goto block_58;
    saved18 = argument0;
block_58:
    if (Level14_88F6CField(privateState, unsigned char*, 0xC) == 0) {
        goto block_80;
    }
    if (Level14_88F6Cunk_ovlheader_800743AC(owner, 0, 1) != 0) {
        goto block_67;
    }
    if (Level14_88F6Cunk_ovlheader_800743AC(owner, 1, 1) != 0) {
        goto block_67;
    }
    if (Level14_88F6CCountTimerDown(privateState + 0x12, 2) == 0) {
        goto block_66;
    }
    Level14_88F6CField(privateState, unsigned char*, 0xC) =
        (unsigned char)Level14_88F6CField(privateState, unsigned char*, 0xD);
    temp_v0_5 = Level14_88F6Cunk_ovlheader_800743AC(owner, 0, 2);
    if (temp_v0_5 == 0) {
        goto block_64;
    }
    if (Level14_88F6CField(temp_v0_5, short*, 0x36) == 0x1A6) {
        goto block_65;
    }
block_64:
    if (Level14_88F6CApproximatePlanarDistance(owner + 0xC, (int)&Level14_88F6C_D_80070328) >=
        0xAF0) {
        goto block_67;
    }
block_65:
    Level14_88F6CField(privateState, unsigned char*, 0xC) =
        (unsigned char)(Level14_88F6CField(privateState, unsigned char*, 0xC) - 0x10);
block_66:
block_67:
    if (Level14_88F6Cunk_ovlheader_800743AC(owner, 0, -1) != 0) {
        goto block_74;
    }
    if (Level14_88F6Cunk_ovlheader_800743AC(owner, 1, -1) != 0) {
        goto block_74;
    }
    if (Level14_88F6CCountTimerDown(privateState + 0x10, 2) == 0) {
        goto block_74;
    }
    Level14_88F6CField(privateState, unsigned char*, 0xB) =
        (unsigned char)Level14_88F6CField(privateState, unsigned char*, 0xD);
    temp_v0_6 = Level14_88F6Cunk_ovlheader_800743AC(owner, 0, -2);
    if (temp_v0_6 == 0) {
        goto block_72;
    }
    if (Level14_88F6CField(temp_v0_6, short*, 0x36) == 0x1A6) {
        goto block_73;
    }
block_72:
    if (Level14_88F6CApproximatePlanarDistance(owner + 0xC, (int)&Level14_88F6C_D_80070328) >=
        0xAF0) {
        goto block_74;
    }
block_73:
    Level14_88F6CField(privateState, unsigned char*, 0xB) =
        (unsigned char)(Level14_88F6CField(privateState, unsigned char*, 0xB) - 0x10);
block_74:
    if (Level14_88F6CAbsoluteByteAngleDelta(
            (Level14_88F6CField(privateState, unsigned char*, 0xA) + 0xC4) & 0xFF, saved16) >=
        0x3C) {
        goto block_76;
    }
    argument0 = Level14_88F6CField(privateState, unsigned char*, 0xA);
    argument1 = Level14_88F6CField(owner, unsigned char*, 0x46);
    argument0 += 0x3D;
    goto block_78;
block_76:
    if (Level14_88F6CAbsoluteByteAngleDelta(
            (Level14_88F6CField(privateState, unsigned char*, 0xA) + 0x3C) & 0xFF, saved16) >=
        0x3C) {
        goto block_80;
    }
    argument0 = Level14_88F6CField(privateState, unsigned char*, 0xA);
    argument1 = Level14_88F6CField(owner, unsigned char*, 0x46);
    argument0 += 0xC3;
block_78:
    if (Level14_88F6CAbsoluteByteAngleDelta(argument0 & 0xFF, argument1) >= 0x3C) {
        goto block_80;
    }
    Level14_88F6CField(privateState, unsigned char*, 0xE) = 1U;
block_80:
    if (Level14_88F6CField(privateState, unsigned char*, 0xE) == 0) {
        goto block_83;
    }
    if (Level14_88F6CTurnMobyTowardHeading(
            owner, Level14_88F6CField(privateState, unsigned char*, 0xA), 2, 1, 1, 0) == 0) {
        goto block_108;
    }
    Level14_88F6CField(privateState, unsigned char*, 0xE) = 0U;
    return;
block_83:
    if (Level14_88F6CAbsoluteByteAngleDelta(saved16,
                                            Level14_88F6CField(owner, unsigned char*, 0x46)) < 2) {
        goto block_97;
    }
    saved18 = Level14_88F6CApproachByteAngle(
        saved16, Level14_88F6CField(owner, unsigned char*, 0x46), saved18, (saved18 >> 1) + 1);
    argument0 = Level14_88F6CField(privateState, unsigned char*, 0xC);
    if (argument0 == 0) {
        goto block_93;
    }
    scratch = Level14_88F6CField(owner, unsigned char*, 0x46);
    if ((int)scratch < saved18) {
        goto block_88;
    }
    if (saved18 >= 0x80) {
        goto block_89;
    }
    if ((result = (unsigned int)scratch < 0x81U)) {
        goto block_90;
    }
block_88:
    saved20 = argument0;
    goto block_94;
block_89:
block_90:
    result = saved18 < (int)scratch;
    if (result != 0) {
        goto block_93;
    }
    if (saved18 < 0x81) {
        goto block_94;
    }
    if (!(result = (unsigned int)scratch < 0x80U)) {
        goto block_94;
    }
block_93:
    saved20 = Level14_88F6CField(privateState, unsigned char*, 0xB);
block_94:
    temp_v0_7 = Level14_88F6CAbsoluteByteAngleDelta(
        Level14_88F6CField(privateState, unsigned char*, 0xA), saved18);
    if ((result = temp_v0_7 < saved20)) {
        goto block_96;
    }
    if (temp_v0_7 >=
        Level14_88F6CAbsoluteByteAngleDelta(Level14_88F6CField(privateState, unsigned char*, 0xA),
                                            Level14_88F6CField(owner, unsigned char*, 0x46))) {
        goto block_108;
    }
block_96:
    Level14_88F6CField(owner, unsigned char*, 0x46) = saved18;
    return;
block_97:
    if (Level14_88F6C_D_8006E344 == 1) {
        goto block_108;
    }
    if (Level14_88F6CApproximatePlanarDistance(owner + 0xC, (int)&Level14_88F6C_D_80070328) >=
        0x3E81) {
        goto block_108;
    }
    if (Level14_88F6CField(privateState, short*, 8) != 0) {
        goto block_108;
    }
    Level14_88F6CField(owner, unsigned char*, 0x48) = 1U;
    Level14_88F6C_func_80034F40(owner, 1);
    return;
block_101:
    result = Level14_88F6C_func_80055E84(owner);
    argument0 = owner;
    argument1 = 5;
    Level14_88F6CKeep(argument0);
    Level14_88F6CKeep(argument1);
    saved18 = result;
    Level14_88F6CRefreshMobySpatialGridAndBasis(argument0, argument1);
    if (Level14_88F6CField(owner, unsigned char*, 0x49) != 0) {
        goto block_106;
    }
    if (Level14_88F6CField(owner, unsigned char*, 0x3C) != saved16) {
        goto block_106;
    }
    if ((result = saved18 < 8)) {
        goto block_106;
    }
    temp_v0_8 = Level14_88F6CSpawnMoby(0x19B, owner);
    if (temp_v0_8 == 0) {
        goto block_106;
    }
    Level14_88F6CField(Level14_88F6CField(temp_v0_8, int*, 0), int*, 0) = 0x96;
    originalFrame.sp20 = 0x76C;
    originalFrame.sp24 = 0;
    originalFrame.sp28 = 0x2BC;
    Level14_88F6CTransformVectorByBasis(owner + 0x20, &originalFrame.sp20, &originalFrame.sp20);
    Level14_88F6CAddVector(temp_v0_8 + 0xC, owner + 0xC, &originalFrame.sp20);
    Level14_88F6CField(temp_v0_8, unsigned char*, 0x46) =
        (unsigned char)Level14_88F6CField(owner, unsigned char*, 0x46);
    Level14_88F6CField(owner, unsigned char*, 0x49) = 1U;
    Level14_88F6CField(privateState, short*, 8) = 0xB4;
block_106:
    if (Level14_88F6C_D_8006C770 == 0) {
        goto block_108;
    }
    Level14_88F6CField(owner, unsigned char*, 0x48) = 0U;
    Level14_88F6C_func_80034F40(owner, 0);
    Level14_88F6CField(owner, unsigned char*, 0x49) = 0U;
block_108:
    return;
}

#undef Level14_88F6CField
#undef Level14_88F6CKeep

int func_80039714(Moby*);
void func_80055D24(Moby*, int);
void func_800369B8(Moby*, int);
void func_80055B18(Moby*);
void func_level_14_800898B4(Moby* moby) {
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
/* SCUS-94467 USA Rev0, original80089934.
* AI generated; not human reviewed. All1150 original instructions,32 selector
* words and every actual destination must match:1182 recorded owned words.
* Frame98hex=152 bytes saves S0..S7/RA;SP20..6F retains the original vectors.
* Neighbor arithmetic retains complete signed quotient/remainder corrections
* for current,current+6,current+1,current+5. For-1,the signed%8 remainder is-1;
* the subsequent+1 gives0. No partial hardware result is synthesized.
* Original direction cases2/6/4/8/1/3/5/default retain their physical ordering,
* independent coordinate words and shared vector stores435/436. Full heading,
* path direction,index,height,bound and player-pointer phases remain distinct.
* The original player pointer remains in A0 while a separate global reload
* supplies the class. Named aliases retain the actual original absolute reads.
* Shared clear919,counter942 and final boundary1064 retain their original
* complete arguments and entries. Distinct cases5/6 reload the same original
* counter through independent symbols,keeping their separate native entries.
* Original signed low-half clamp follows its SH. Original LHU source0xFFF0
* becomes full signed-1 through SLL16/SRA20 before the angle-helper call;the
* decoder's byte cast would change that ABI value and is not retained.
* The failure byte store stays on its original route,after complete flag
* producers. Its volatile C view preserves the same one-byte write;all CPU
* instructions remain original. Original F19138 outgoing words,SP58/SP68
* stores,range tests,shared boundary writes and default entries remain exact.
* Empty metadata consumes initialized complete values/addresses or clobbers
* dead values before fresh complete producers;zero CPU words. No opcode asm,
* fixedFP,partialHI,undefined saved inputs or live overlapping register aliases.
* Compiler,filter and flags remain frozen. Units/fixed point,full helper/caller
* chains,cadence beyond invocation,Rev1 mapping and synchronized runtime remain
* open. Confidence is binary identity after all gates. Next:human review and
* retail captures. Every native/linked word,actual target,selector and full
* EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 bc6068ccf7d154d1786e7c6ead310a5ebe53270834ef60a7519a6c94261da0ef */
#define Level14_89934Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level14_89934Call19138View1() __asm__("func_80019138");
int Level14_89934Call1A310View1() __asm__("func_8001A310");
int Level14_89934Call1BA30View1() __asm__("func_8001BA30");
int Level14_89934RequestMobyAnimationView1() __asm__("func_80034F40");
int Level14_89934SetMobyAnimationView1() __asm__("func_80034F80");
int Level14_89934TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level14_89934TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level14_89934CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level14_89934Call35A80View1() __asm__("func_80035A80");
int Level14_89934Call35DDCView1() __asm__("func_80035DDC");
int Level14_89934Call35EE0View1() __asm__("func_80035EE0");
int Level14_89934Call369B8View1() __asm__("func_800369B8");
int Level14_89934Call36A68View1() __asm__("func_80036A68");
int Level14_89934Call38BF8View1() __asm__("func_80038BF8");
int Level14_89934Call3BA00View1() __asm__("func_8003BA00");
int Level14_89934Call4E790View1() __asm__("func_8004E790");
int Level14_89934PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level14_89934TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level14_89934ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Level14_89934CopyVectorView1() __asm__("func_8004F178");
int Level14_89934AddVectorView1() __asm__("func_8004F194");
int Level14_89934AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level14_89934ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level14_89934DeleteMobyView1() __asm__("func_80055B18");
int Level14_89934RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level14_89934Call55E84View1() __asm__("func_80055E84");
extern int Level14_89934Data6C550View1 __asm__("D_8006C550");
extern int Level14_89934Data6C770View1 __asm__("D_8006C770");
extern int Level14_89934Data6E020View1 __asm__("D_8006E020");
extern int Level14_89934Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level14_89934Data6E040View1 __asm__("D_8006E040");
extern int Level14_89934Data6E344View1 __asm__("D_8006E344");
extern int Level14_89934Data70328View1 __asm__("D_80070328");
extern int Level14_89934Data71908View1 __asm__("D_80071908");
extern int Level14_89934Data7190CView1 __asm__("D_8007190C");
extern int Level14_89934Data71910View1 __asm__("D_80071910");
extern int Level14_89934Data71930View1 __asm__("D_80071930");
extern int Level14_89934Data71930View2 __asm__("D_80071930");
extern int Level14_89934Data71930View3 __asm__("D_80071930");
extern int Level14_89934Data71930View4 __asm__("D_80071930");
extern int Level14_89934Data71930View5 __asm__("D_80071930");
extern int Level14_89934Data71930View6 __asm__("D_80071930");
extern int Level14_89934Data71930View7 __asm__("D_80071930");
extern int Level14_89934Data71930View8 __asm__("D_80071930");
extern int Level14_89934Data71930View9 __asm__("D_80071930");
extern int Level14_89934Data71930View10 __asm__("D_80071930");
extern int Level14_89934Data71930View11 __asm__("D_80071930");
extern int Level14_89934Data6C770View2 __asm__("D_8006C770");
extern int Level14_89934Data6C770View3 __asm__("D_8006C770");
void func_level_14_80089934(void* ownerParameter) {
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord19 __asm__("$19"), retainedDirectionVectorOrDistance16 __asm__("$16"),
        retainedStateResultOrPlayerView18 __asm__("$18"),
        retainedDirectionHeightOrBound20 __asm__("$20"),
        retainedOriginalPositionFlag21 __asm__("$21"), retainedOriginalPath22 __asm__("$22"),
        retainedOriginalCollisionFlag23 __asm__("$23");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C;
    } originalFrame;
    int temporaryWord9;
    int temporaryWord23;
    int temporaryWord3;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord20;
    int temporaryWord21;
    int temporaryWord22;
    int temporaryWord17;
    int temporaryWord19;
    int temporaryWord2;
    int temporaryWord1;
    int temporaryWord4;
    int temporaryWord10;
    int temporaryWord16;
    int temporaryWord18;
    ownerRecord17 = ownerParameter;
    MATCHING_KEEP(ownerRecord17);
    privateRecord19 = Level14_89934Field(ownerRecord17, void**, 0);
    retainedOriginalCollisionFlag23 = 0;
    argumentWord5 = Level14_89934Field(privateRecord19, unsigned char*, 0x13);
    retainedOriginalPositionFlag21 = 0;
    if (argumentWord5 != 0) {
        if (Level14_89934Field(ownerRecord17, unsigned char*, 0x48) != 7) {
            temporaryWord10 = Level14_89934Data6C550View1 +
                              (Level14_89934Field(privateRecord19, int*, 0x14) * 0x58);
            if (!(Level14_89934Field(temporaryWord10, unsigned char*, 0x48) & 0x80)) {
                argumentWord4 =
                    Level14_89934Field(Level14_89934Field(temporaryWord10, void**, 0), short*, 0xC);
                if (argumentWord5 == argumentWord4)
                    goto writeOriginalNeighborBytes78;
                rawWord2 = argumentWord4;
                if (argumentWord4 < 0)
                    rawWord2 = argumentWord4 + 7;
                rawWord2 >>= 3;
                rawWord2 *= 8;
                rawWord2 = argumentWord4 - rawWord2;
                rawWord2++;
                if (argumentWord5 == rawWord2)
                    goto writeOriginalNeighborBytes78;
                rawWord3 = argumentWord4 + 6;
                rawWord2 = rawWord3;
                if (rawWord3 < 0)
                    rawWord2 = argumentWord4 + 13;
                rawWord2 >>= 3;
                rawWord2 *= 8;
                rawWord2 = rawWord3 - rawWord2;
                rawWord2++;
                if (argumentWord5 == rawWord2)
                    goto writeOriginalNeighborBytes78;
                rawWord3 = argumentWord4 + 1;
                rawWord2 = rawWord3;
                if (rawWord3 < 0)
                    rawWord2 = argumentWord4 + 8;
                rawWord2 >>= 3;
                rawWord2 *= 8;
                rawWord2 = rawWord3 - rawWord2;
                rawWord2++;
                if (argumentWord5 == rawWord2)
                    goto writeOriginalNeighborBytes78;
                rawWord3 = argumentWord4 + 5;
                rawWord2 = rawWord3;
                if (rawWord3 < 0)
                    rawWord2 = argumentWord4 + 12;
                rawWord2 >>= 3;
                rawWord2 *= 8;
                rawWord2 = rawWord3 - rawWord2;
                rawWord2++;
                if (argumentWord5 != rawWord2)
                    goto writeOriginalMissingNeighbor82;
            writeOriginalNeighborBytes78:
                Level14_89934Field(ownerRecord17, signed char*, 0x4C) = 0x20;
                Level14_89934Field(ownerRecord17, signed char*, 0x4A) = 0x20;
                goto checkOriginalOwnerState85;
            writeOriginalMissingNeighbor82:
                Level14_89934Field(ownerRecord17, signed char*, 76) = 0;
                Level14_89934Field(ownerRecord17, unsigned char*, 74) = 255;
                return;
            }
            goto checkOriginalOwnerState85;
        }
        goto block_45;
    }
checkOriginalOwnerState85:
    if (Level14_89934Field(ownerRecord17, unsigned char*, 0x48) != 7) {
        if (Level14_89934Field(ownerRecord17, int*, 0x18) != 0) {
            temporaryWord17 = Level14_89934Field(ownerRecord17, unsigned char*, 0x3A);
            retainedDirectionVectorOrDistance16 = Level14_89934Field(ownerRecord17, void**, 0);
            if (temporaryWord17 == 0xFF) {
                Level14_89934Call36A68View1(ownerRecord17, 0, 0, 0);
            } else {
                temporaryWord18 = Level14_89934Field(
                    ((temporaryWord17 * 0x58) + Level14_89934Data6C550View1), int*, 0);
                Level14_89934Field(temporaryWord18, int*, 0x68) =
                    (int)(Level14_89934Field(temporaryWord18, int*, 0x68) - 1);
            }
            Level14_89934Call4E790View1(retainedDirectionVectorOrDistance16, 0, 0x18);
            Level14_89934Call38BF8View1(ownerRecord17, retainedDirectionVectorOrDistance16, 6, 7);
            Level14_89934SetMobyAnimationView1(ownerRecord17, 7);
            Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 4) = 0x12C;
            Level14_89934Field(retainedDirectionVectorOrDistance16, unsigned char*, 0x16) = 0xB4;
        }
        if (Level14_89934Field(ownerRecord17, unsigned char*, 0x48) != 7) {
            retainedDirectionVectorOrDistance16 = 0;
            if (Level14_89934Field(privateRecord19, unsigned char*, 1) != 0) {
                Level14_89934CopyVectorView1(&originalFrame.sp20, ownerRecord17 + 0xC);
                originalFrame.sp28 += 0x1F4;
                argumentWord5 = Level14_89934Call1A310View1(&originalFrame.sp20, 0x1800, 0, 0);
                if (Level14_89934Field(privateRecord19, unsigned char*, 1) == 2) {
                    rawWord3 = Level14_89934Data71930View2;
                    argumentWord4 = rawWord3;
                    if (!rawWord3)
                        goto setOriginalContactFlag193;
                    rawWord2 = Level14_89934Data71930View3;
                    rawWord3 = Level14_89934Field(rawWord2, short*, 54);
                    if (rawWord3 == 422 || rawWord3 == 420)
                        goto setOriginalContactFlag193;
                    if (rawWord3 == 421) {
                        rawWord2 = Level14_89934Field(argumentWord4, unsigned char*, 72);
                        if ((unsigned int)(rawWord2 - 4) < 2)
                            goto setOriginalContactFlag193;
                    }
                    rawWord2 = Level14_89934Field(argumentWord4, int*, 0);
                    rawWord2 = Level14_89934Field(rawWord2, unsigned char*, 12);
                    if (rawWord2)
                        goto testOriginalHeightResult194;
                    if (Level14_89934Field(argumentWord4, unsigned char*, 72))
                        goto testOriginalHeightResult194;
                    if (!Level14_89934Field(argumentWord4, unsigned char*, 73))
                        goto testOriginalHeightResult194;
                setOriginalContactFlag193:
                    retainedDirectionVectorOrDistance16 = 1;
                }
            testOriginalHeightResult194:;
                if (argumentWord5) {
                    argumentWord4 = (int)&Level14_89934Data71908View1;
                    MATCHING_KEEP(argumentWord4);
                }
                if ((argumentWord5 != 0) &&
                    (((Level14_89934Field(ownerRecord17, int*, 0x14) -
                       Level14_89934Field(argumentWord4, int*, 0)) < 0x32) ||
                     (retainedDirectionVectorOrDistance16 != 0))) {
                    Level14_89934Field(privateRecord19, unsigned char*, 1) = 0U;
                    Level14_89934Field(ownerRecord17, int*, 0x14) =
                        (int)Level14_89934Field(argumentWord4, int*, 0);
                    Level14_89934Field(privateRecord19, short*, 2) = 0;
                } else {
                    Level14_89934Field(ownerRecord17, int*, 0x14) =
                        (int)(Level14_89934Field(ownerRecord17, int*, 0x14) -
                              Level14_89934Field(privateRecord19, short*, 2));
                    Level14_89934Field(privateRecord19, short*, 2) =
                        (short)((unsigned short)Level14_89934Field(privateRecord19, short*, 2) +
                                0xC);
                }
            }
            if ((Level14_89934Field(ownerRecord17, unsigned char*, 0x48) != 7) &&
                (Level14_89934Field(ownerRecord17, unsigned char*, 0x3A) != 0xFF)) {
                if (Level14_89934Call1BA30View1(ownerRecord17 + 0xC, 0x190, 0, 0, 0,
                                                ownerRecord17) != 0) {
                    Level14_89934Field(ownerRecord17, int*, 0xC) = (int)Level14_89934Data7190CView1;
                    retainedOriginalCollisionFlag23 = 1;
                    Level14_89934Field(ownerRecord17, int*, 0x10) =
                        (int)Level14_89934Data71910View1;
                }
            } else {
            block_45:
            }
        }
    }
    Level14_89934RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
    temporaryWord19 = Level14_89934Field(ownerRecord17, unsigned char*, 0x48);
    Level14_89934Field(ownerRecord17, signed char*, 0x4F) = 0x2D;
    switch (temporaryWord19) {
        case 30:
            Level14_89934Field(privateRecord19, unsigned char*, 0) = 1U;
            Level14_89934CopyVectorView1(&originalFrame.sp30, ownerRecord17 + 0xC);
            originalFrame.sp38 += 0x2800;
            if (Level14_89934Call1A310View1(&originalFrame.sp30, 0x3000, 0, 0) != 0) {
                Level14_89934Field(privateRecord19, unsigned char*, 1) = 2U;
                Level14_89934Field(ownerRecord17, int*, 0x14) =
                    (int)(Level14_89934Data71908View1 + 0x800);
            }
            Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 0U;
            goto updateOriginalBoundary1064;
        case 0:
            Level14_89934Field(ownerRecord17, signed char*, 0x4F) = 0x2D;
            retainedDirectionVectorOrDistance16 = 0x2800;
            if (Level14_89934Field(privateRecord19, unsigned char*, 0) == 0) {
                retainedDirectionVectorOrDistance16 = 0x708;
            }
            if (Level14_89934ApproximatePlanarDistanceView1(ownerRecord17 + 0xC,
                                                            (int)&Level14_89934Data70328View1) <
                retainedDirectionVectorOrDistance16) {
                Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 2U;
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 2);
            } else if (Level14_89934Field(privateRecord19, unsigned char*, 0) == 0) {
                Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 1);
            }
            goto updateOriginalBoundary1064;
        case 1:
            retainedOriginalPath22 = Level14_89934Field(privateRecord19, void**, 4);
            temporaryWord6 = Level14_89934Field(ownerRecord17, int*, 0xC);
            temporaryWord4 = Level14_89934Field(retainedOriginalPath22, void**, 0xC);
            temporaryWord2 = Level14_89934Data6C550View1 +
                             (Level14_89934Field(ownerRecord17, unsigned char*, 0x3A) * 0x58);
            retainedDirectionHeightOrBound20 = Level14_89934Field(
                Level14_89934Field(temporaryWord2, int*, 0), unsigned char*, 0xB);
            if (temporaryWord6 < Level14_89934Field(temporaryWord4, int*, 0)) {
                temporaryWord14 = Level14_89934Field(ownerRecord17, int*, 0x10);
                if (Level14_89934Field(temporaryWord4, int*, 4) < temporaryWord14) {
                    retainedDirectionVectorOrDistance16 = 1;
                } else {
                    retainedDirectionVectorOrDistance16 = 3;
                    if (Level14_89934Field(temporaryWord4, int*, 0x14) < temporaryWord14) {
                        retainedDirectionVectorOrDistance16 = 2;
                    }
                }
            } else if (Level14_89934Field(temporaryWord4, int*, 0x30) < temporaryWord6) {
                temporaryWord15 = Level14_89934Field(ownerRecord17, int*, 0x10);
                if (Level14_89934Field(temporaryWord4, int*, 0x34) < temporaryWord15) {
                    retainedDirectionVectorOrDistance16 = 7;
                } else {
                    retainedDirectionVectorOrDistance16 = 5;
                    if (Level14_89934Field(temporaryWord4, int*, 0x24) < temporaryWord15) {
                        retainedDirectionVectorOrDistance16 = 6;
                    }
                }
            } else {
                retainedDirectionVectorOrDistance16 = 4;
                rawWord3 = Level14_89934Field(ownerRecord17, int*, 16);
                rawWord2 = Level14_89934Field(temporaryWord4, int*, 4);
                if (rawWord2 < rawWord3) {
                    retainedDirectionVectorOrDistance16 = 8;
                }
            }
            retainedStateResultOrPlayerView18 =
                Level14_89934Field(privateRecord19, unsigned char*, 0x12);
            if (retainedStateResultOrPlayerView18 == 4) {
                Level14_89934CopyVectorView1(&originalFrame.sp40, ownerRecord17 + 0xC);
                if (retainedDirectionVectorOrDistance16 == 2) {
                    originalFrame.sp40 -= 4000;
                    goto computeOriginalHeading438;
                }
                if (retainedDirectionVectorOrDistance16 == 6) {
                    originalFrame.sp40 += 4000;
                    goto computeOriginalHeading438;
                }
                if (retainedDirectionVectorOrDistance16 == retainedStateResultOrPlayerView18) {
                    originalFrame.sp44 -= 4000;
                    goto computeOriginalHeading438;
                }
                if (retainedDirectionVectorOrDistance16 == 8) {
                    originalFrame.sp44 += 4000;
                    goto computeOriginalHeading438;
                }
                if (retainedDirectionVectorOrDistance16 == 1) {
                    rawWord2 = originalFrame.sp40;
                    rawWord3 = originalFrame.sp44;
                    rawWord2 -= 4000;
                    goto adjustOriginalVectorY435;
                }
                if (retainedDirectionVectorOrDistance16 == 3) {
                    rawWord2 = originalFrame.sp40;
                    rawWord3 = originalFrame.sp44;
                    rawWord2 -= 4000;
                    rawWord3 -= 4000;
                    goto storeOriginalVector436;
                }
                if (retainedDirectionVectorOrDistance16 == 5) {
                    rawWord2 = originalFrame.sp40;
                    rawWord3 = originalFrame.sp44;
                    rawWord2 += 4000;
                    rawWord3 -= 4000;
                    goto storeOriginalVector436;
                }
                rawWord2 = originalFrame.sp40;
                rawWord3 = originalFrame.sp44;
                rawWord2 += 4000;
            adjustOriginalVectorY435:
                rawWord3 += 4000;
            storeOriginalVector436:
                originalFrame.sp40 = rawWord2;
                originalFrame.sp44 = rawWord3;
            computeOriginalHeading438:
                rawWord2 = Level14_89934PlanarHeadingLookupView1(
                    originalFrame.sp40 - Level14_89934Field(ownerRecord17, int*, 12),
                    originalFrame.sp44 - Level14_89934Field(ownerRecord17, int*, 16), 0);
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 1;
                __asm__(""
                        : "=r"(argumentWord5)
                        : "0"(argumentWord5), "r"(argumentWord4), "r"(rawWord2)
                        : "$16");
                retainedDirectionVectorOrDistance16 = rawWord2;
                Level14_89934RequestMobyAnimationView1(argumentWord4, argumentWord5);
                if (Level14_89934TurnMobyTowardHeadingView1(
                        ownerRecord17, retainedDirectionVectorOrDistance16, 4, 1, 0, 0) != 0) {
                    Level14_89934Call35DDCView1(ownerRecord17, 0x50, 0, 0, 4);
                }
                if (Level14_89934CountTimerDownView1(privateRecord19 + 0x10, 2) != 0) {
                    Level14_89934Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                    Level14_89934Field(privateRecord19, unsigned char*, 0x12) = 0U;
                }
                goto testOriginalDistance699;
            }
            if (retainedDirectionVectorOrDistance16 != retainedDirectionHeightOrBound20) {
                if (retainedStateResultOrPlayerView18 == 3) {
                    Level14_89934Field(privateRecord19, short*, 0x10) = 0x64;
                    Level14_89934Field(privateRecord19, unsigned char*, 0x12) = 4U;
                    return;
                }
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 1);
                if (retainedDirectionVectorOrDistance16 < retainedDirectionHeightOrBound20) {
                    rawWord2 =
                        retainedDirectionHeightOrBound20 - retainedDirectionVectorOrDistance16;
                    if (rawWord2 >= 4)
                        goto selectOriginalNegativeDirection498;
                    Level14_89934Field(privateRecord19, short*, 14) = 1;
                    goto checkOriginalPathIndex500;
                }
                MATCHING_KEEP(retainedDirectionHeightOrBound20);
                rawWord2 = retainedDirectionVectorOrDistance16 - retainedDirectionHeightOrBound20;
                rawWord2 = rawWord2 < 4;
                MATCHING_KEEP(rawWord2);
                if (rawWord2) {
                    rawWord2 = -1;
                    goto writeOriginalDirection499;
                }
                rawWord2 = 1;
                goto writeOriginalDirection499;
            selectOriginalNegativeDirection498:
                rawWord2 = -1;
            writeOriginalDirection499:
                Level14_89934Field(privateRecord19, short*, 14) = rawWord2;
            checkOriginalPathIndex500:
                if (Level14_89934Field(privateRecord19, short*, 0xC) == -1) {
                    rawWord2 = retainedDirectionVectorOrDistance16 - 1;
                    Level14_89934Field(privateRecord19, short*, 12) = rawWord2;
                }
                Level14_89934Field(Level14_89934Field(privateRecord19, void**, 8), unsigned short*,
                                   2) =
                    (unsigned short)Level14_89934Field(privateRecord19, short*, 0xC);
                Level14_89934Field(Level14_89934Field(privateRecord19, void**, 8), unsigned short*,
                                   0xA) =
                    (unsigned short)Level14_89934Field(privateRecord19, unsigned short*, 0xE);
                Level14_89934Call35A80View1(ownerRecord17,
                                            Level14_89934Field(privateRecord19, void**, 8), 0x200,
                                            0x50, 0, 4, 0x20, 4);
                Level14_89934Field(privateRecord19, short*, 0xC) = (short)Level14_89934Field(
                    Level14_89934Field(privateRecord19, void**, 8), unsigned short*, 2);
                retainedOriginalPositionFlag21 = 1;
                Level14_89934Field(privateRecord19, unsigned short*, 0xE) =
                    (unsigned short)Level14_89934Field(
                        Level14_89934Field(privateRecord19, void**, 8), unsigned short*, 0xA);
                goto testOriginalDistance699;
            }
            rawWord2 = Level14_89934Field(ownerRecord17, int*, 20);
            rawWord3 = Level14_89934Field((int)&Level14_89934Data70328View1, int*, 8);
            rawWord2 -= rawWord3;
            if (rawWord2 < 0) {
                rawWord2 = -rawWord2;
            }
            if ((rawWord2 < 0x400) &&
                (Level14_89934ApproximatePlanarDistanceView1(
                     temporaryWord2 + 0xC, ((int)&Level14_89934Data70328View1 + 8) - 8) < 0x3E80)) {
                if (Level14_89934Field(privateRecord19, short*, 0xC) != -1) {
                    Level14_89934Field(privateRecord19, short*, 0xC) = -1;
                    Level14_89934Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                }
                if (retainedOriginalCollisionFlag23 != 0) {
                    if ((short)Level14_89934Field(privateRecord19, unsigned short*, 0xE) == 1) {
                        Level14_89934Field(ownerRecord17, unsigned char*, 0x46) =
                            (unsigned char)(Level14_89934Field(ownerRecord17, unsigned char*,
                                                               0x46) -
                                            4);
                    } else {
                        Level14_89934Field(ownerRecord17, unsigned char*, 0x46) =
                            (unsigned char)(Level14_89934Field(ownerRecord17, unsigned char*,
                                                               0x46) +
                                            4);
                    }
                } else {
                    MATCHING_KEEP_VOLATILE(retainedOriginalCollisionFlag23);
                    Level14_89934TurnMobyTowardPlayerView1(ownerRecord17, 4, 0, 0);
                }
                retainedDirectionVectorOrDistance16 =
                    Level14_89934Field((int)&Level14_89934Data70328View1, int*, 0);
                retainedDirectionHeightOrBound20 =
                    Level14_89934Field((int)&Level14_89934Data70328View1, int*, 4);
                retainedOriginalPositionFlag21 = 1;
                if (((Level14_89934Field(privateRecord19, unsigned char*, 0x12) == 3) ||
                     (Level14_89934Field(ownerRecord17, unsigned char*, 0x49) == 2)) &&
                    (retainedStateResultOrPlayerView18 = ownerRecord17 + 0xC,
                     ((Level14_89934ApproximatePlanarDistanceView1(
                           retainedStateResultOrPlayerView18, (int)&Level14_89934Data70328View1) <
                       0xBB8) != 0))) {
                    temporaryWord16 = Level14_89934Field(retainedOriginalPath22, void**, 0xC);
                    if ((retainedDirectionVectorOrDistance16 <
                         (Level14_89934Field(temporaryWord16, int*, 0x30) + 0xA8C)) &&
                        ((Level14_89934Field(temporaryWord16, int*, 0) - 0xA8C) <
                         retainedDirectionVectorOrDistance16) &&
                        ((Level14_89934Field(temporaryWord16, int*, 0x14) - 0xA8C) <
                         retainedDirectionHeightOrBound20) &&
                        (retainedDirectionHeightOrBound20 <
                         (Level14_89934Field(temporaryWord16, int*, 4) + 0xA8C))) {
                        argumentWord4 = (int)ownerRecord17;
                        argumentWord5 = 4;
                        MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5,
                                                           retainedDirectionHeightOrBound20,
                                                           "memory");
                        originalFrame.sp50 = 256;
                        originalFrame.sp54 = 0;
                        originalFrame.sp58 = 0;
                        Level14_89934RefreshMobySpatialGridAndBasisView1(argumentWord4,
                                                                         argumentWord5);
                        Level14_89934TransformVectorByBasisView1(
                            ownerRecord17 + 0x20, &originalFrame.sp50, &originalFrame.sp50);
                        Level14_89934AddVectorView1(&originalFrame.sp50,
                                                    retainedStateResultOrPlayerView18,
                                                    &originalFrame.sp50);
                        originalFrame.sp58 += 0x200;
                        if (Level14_89934Call19138View1(retainedStateResultOrPlayerView18, 256, 1,
                                                        0, 0, 0) == 0) {
                            rawWord2 = 3;
                            MATCHING_KEEP(rawWord2);
                            rawWord3 = 1;
                            retainedOriginalPositionFlag21 = 0;
                            MATCHING_OBSERVE3_VOLATILE(rawWord2, rawWord3,
                                                       retainedOriginalPositionFlag21);
                            Level14_89934Field(privateRecord19, volatile unsigned char*, 18) =
                                rawWord2;
                            goto testOriginalUpdateFlag673;
                        }
                        rawWord2 = Level14_89934Field(privateRecord19, unsigned char*, 18);
                        rawWord3 = 0;
                        if (rawWord2 == 3)
                            retainedOriginalPositionFlag21 = 0;
                        goto testOriginalUpdateFlag673;
                    } else {
                        rawWord3 = Level14_89934Field(privateRecord19, unsigned char*, 18);
                        rawWord2 = 3;
                        MATCHING_KEEP(rawWord2);
                        if (rawWord3 == rawWord2) {
                            rawWord3 = 0;
                            goto resetOriginalState668;
                        }
                        MATCHING_OBSERVE_VOLATILE(retainedDirectionHeightOrBound20);
                        rawWord3 = 1;
                        goto testOriginalUpdateFlag673;
                    }
                } else {
                    rawWord3 = Level14_89934Field(privateRecord19, unsigned char*, 18);
                    rawWord2 = 3;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord3 != rawWord2) {
                        rawWord3 = 1;
                        goto testOriginalUpdateFlag673;
                    }
                    rawWord3 = 0;
                resetOriginalState668:
                    retainedOriginalPositionFlag21 = 0;
                    Level14_89934Field(privateRecord19, short*, 16) = 100;
                    Level14_89934Field(privateRecord19, unsigned char*, 18) = 4;
                }
            testOriginalUpdateFlag673:
                if (rawWord3 != 0) {
                    Level14_89934RequestMobyAnimationView1(ownerRecord17, 1);
                    Level14_89934Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                    Level14_89934Call35DDCView1(ownerRecord17, 0x50, 0, 0, 4);
                } else {
                    goto clearOriginalAnimation697;
                }
            } else if (Level14_89934Field(privateRecord19, unsigned char*, 0x12) == 3) {
                retainedOriginalPositionFlag21 = 0;
                Level14_89934Field(privateRecord19, short*, 0x10) = 0x64;
                Level14_89934Field(privateRecord19, unsigned char*, 0x12) = 4U;
            } else {
            clearOriginalAnimation697:
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 0);
            }
        testOriginalDistance699:
            rawWord2 = Level14_89934ApproximatePlanarDistanceView1(
                ownerRecord17 + 12, (int)&Level14_89934Data70328View1);
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2 >= 1800)
                goto updateOriginalBoundary1064;
        enterOriginalStateClear706:
            MATCHING_OBSERVE_VOLATILE(argumentWord4);
            goto clearOriginalOwnerState919;
        case 2:
            Level14_89934TurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 0);
            if (Level14_89934Data6C770View1 != 0) {
                Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 3U;
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 3);
            }
            goto updateOriginalBoundary1064;
        case 3:
            retainedDirectionHeightOrBound20 = 0x2800;
            if (Level14_89934Field(privateRecord19, unsigned char*, 0) == 0) {
                retainedDirectionHeightOrBound20 = 0x708;
            }
            Level14_89934TurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 0);
            retainedDirectionVectorOrDistance16 = (int)&originalFrame.sp40;
            argumentWord4 = retainedDirectionVectorOrDistance16;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
            retainedStateResultOrPlayerView18 = (int)&Level14_89934Data70328View1 + 152;
            MATCHING_KEEP(retainedStateResultOrPlayerView18);
            Level14_89934CopyVectorView1(argumentWord4, retainedStateResultOrPlayerView18);
            temporaryWord7 = originalFrame.sp44;
            originalFrame.sp40 *= 0xF;
            originalFrame.sp44 = temporaryWord7 * 0xF;
            originalFrame.sp48 *= 0xF;
            Level14_89934ShiftVectorRightTowardZeroView1(&originalFrame.sp40, 6, temporaryWord7);
            Level14_89934AddVectorView1(&originalFrame.sp40, &originalFrame.sp40,
                                        retainedStateResultOrPlayerView18 - 0x98);
            retainedDirectionVectorOrDistance16 = Level14_89934ApproximatePlanarDistanceView1(
                ownerRecord17 + 0xC, &originalFrame.sp40);
            if (retainedDirectionVectorOrDistance16 < 1800) {
                rawWord2 = 1;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "$3");
                rawWord3 = Level14_89934Data6E344View1;
                MATCHING_KEEP(retainedDirectionHeightOrBound20);
                if (rawWord3 == rawWord2) {
                    rawWord2 =
                        retainedDirectionHeightOrBound20 < retainedDirectionVectorOrDistance16;
                    goto testOriginalDistanceResult825;
                }
                rawWord2 = Level14_89934Field((int)&Level14_89934Data70328View1, int*, 576);
                MATCHING_KEEP(retainedDirectionHeightOrBound20);
                if (rawWord2) {
                    rawWord2 =
                        retainedDirectionHeightOrBound20 < retainedDirectionVectorOrDistance16;
                    goto testOriginalDistanceResult825;
                }
                rawWord2 = Level14_89934Field(ownerRecord17, int*, 20);
                rawWord3 = Level14_89934Field((int)&Level14_89934Data70328View1, int*, 8);
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if ((rawWord2 < 0x400) &&
                    (Level14_89934AbsoluteByteAngleDeltaView1(
                         Level14_89934Field(ownerRecord17, unsigned char*, 0x46),
                         Level14_89934PlanarHeadingLookupView1(
                             Level14_89934Field(retainedStateResultOrPlayerView18, int*, -0x98) -
                                 Level14_89934Field(ownerRecord17, int*, 0xC),
                             Level14_89934Field((int)&Level14_89934Data70328View1, int*, 4) -
                                 Level14_89934Field(ownerRecord17, int*, 0x10),
                             0)) < 8)) {
                    rawWord2 = Level14_89934PlanarHeadingLookupView1(
                        Level14_89934Field(ownerRecord17, int*, 12) - Level14_89934Data6E020View1,
                        Level14_89934Field(ownerRecord17, int*, 16) - Level14_89934Data6E024View1,
                        0);
                    argumentWord4 = Level14_89934Data6E040View1;
                    __asm__ volatile("" ::: "$5", "memory");
                    argumentWord5 = rawWord2;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(argumentWord5));
                    argumentWord4 = (argumentWord4 << 16) >> 20;
                    if (Level14_89934AbsoluteByteAngleDeltaView1(argumentWord4, argumentWord5) <
                        24) {
                        Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 4U;
                        Level14_89934RequestMobyAnimationView1(ownerRecord17, 4);
                        return;
                    }
                }
                goto compareOriginalDistance824;
            }
        compareOriginalDistance824:
            rawWord2 = retainedDirectionHeightOrBound20 < retainedDirectionVectorOrDistance16;
        testOriginalDistanceResult825:
            if (rawWord2 != 0) {
                Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 5U;
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 5);
            }
            goto updateOriginalBoundary1064;
        case 4:
            rawWord2 = Level14_89934Call55E84View1(ownerRecord17);
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 4;
            argumentWord6 = 2;
            argumentWord7 = 0;
            __asm__(""
                    : "=r"(argumentWord7)
                    : "0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5),
                      "r"(argumentWord6), "r"(rawWord2)
                    : "$18");
            retainedStateResultOrPlayerView18 = rawWord2;
            Level14_89934TurnMobyTowardPlayerView1(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7);
            MATCHING_BARRIER_VOLATILE("$16");
            rawWord3 = Level14_89934Field(ownerRecord17, short*, 56);
            rawWord2 = Level14_89934Field(ownerRecord17, int*, 20);
            __asm__ volatile("" ::: "$16", "memory");
            retainedDirectionVectorOrDistance16 = (int)&Level14_89934Data70328View1 + 8;
            __asm__(""
                    : "=r"(retainedDirectionVectorOrDistance16)
                    : "0"(retainedDirectionVectorOrDistance16), "r"(rawWord2), "r"(rawWord3));
            rawWord2 -= rawWord3;
            rawWord3 = Level14_89934Field(retainedDirectionVectorOrDistance16, int*, 0);
            retainedDirectionHeightOrBound20 = rawWord2 - rawWord3;
            if ((Level14_89934Field(ownerRecord17, unsigned char*, 0x49) == 0) &&
                (Level14_89934Field(ownerRecord17, unsigned char*, 0x3C) == 4) &&
                ((rawWord2 = retainedStateResultOrPlayerView18 - 21),
                 (unsigned int)rawWord2 < 3U) &&
                (Level14_89934Field((int)&Level14_89934Data70328View1, int*, 0x240) == 0) &&
                (Level14_89934AbsoluteByteAngleDeltaView1(
                     Level14_89934Field(ownerRecord17, unsigned char*, 0x46),
                     Level14_89934PlanarHeadingLookupView1(
                         Level14_89934Field(retainedDirectionVectorOrDistance16, int*, -8) -
                             Level14_89934Field(ownerRecord17, int*, 0xC),
                         Level14_89934Field((int)&Level14_89934Data70328View1, int*, 4) -
                             Level14_89934Field(ownerRecord17, int*, 0x10),
                         0)) < 8)) {
                retainedStateResultOrPlayerView18 = retainedDirectionVectorOrDistance16 - 8;
                MATCHING_KEEP(retainedStateResultOrPlayerView18);
                if (Level14_89934ApproximatePlanarDistanceView1(
                        ownerRecord17 + 12, retainedStateResultOrPlayerView18) < 1800 &&
                    ((rawWord2 = retainedDirectionHeightOrBound20 + 1023),
                     (unsigned int)rawWord2 < 1151U)) {
                    MATCHING_OBSERVE_VOLATILE(retainedDirectionHeightOrBound20);
                    Level14_89934Field((int)&Level14_89934Data70328View1, int*, 0x298) =
                        (int)Level14_89934Field(ownerRecord17, unsigned char*, 0x46);
                    if (Level14_89934Field((int)&Level14_89934Data70328View1, int*, 0x250) != 0) {
                        temporaryWord21 =
                            Level14_89934Field(retainedDirectionVectorOrDistance16, int*, 0x1C) | 1;
                    } else {
                        temporaryWord21 =
                            Level14_89934Field(retainedDirectionVectorOrDistance16, int*, 0x1C) |
                            0x16;
                    }
                    Level14_89934Field(retainedDirectionVectorOrDistance16, int*, 0x1C) =
                        temporaryWord21;
                    Level14_89934Field(ownerRecord17, unsigned char*, 0x49) = 1U;
                }
            }
            rawWord2 = Level14_89934Data6C770View1;
            if (rawWord2) {
                rawWord2 = 1;
                __asm__ volatile("" ::"r"(rawWord2) : "$3", "memory");
                rawWord3 = Level14_89934Field(ownerRecord17, unsigned char*, 73);
                __asm__ volatile("" ::: "$4", "memory");
                argumentWord4 = (int)ownerRecord17;
                if (rawWord3 == rawWord2) {
                    Level14_89934Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                    Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 6U;
                    Level14_89934RequestMobyAnimationView1(ownerRecord17, 6);
                } else {
                clearOriginalOwnerState919:
                    __asm__ volatile("" ::"r"(argumentWord4) : "$5", "memory");
                    Level14_89934Field(ownerRecord17, unsigned char*, 73) = 0;
                    Level14_89934Field(ownerRecord17, unsigned char*, 72) = 0;
                    Level14_89934RequestMobyAnimationView1(argumentWord4, 0);
                    goto updateOriginalBoundary1064;
                }
            }
            goto updateOriginalBoundary1064;
        case 5:
        loadOriginalCase5Counter925:
            rawWord2 = Level14_89934Data6C770View2;
            goto testOriginalCounter942;
        case 6:
        loadOriginalCase6Counter929:
            rawWord2 = Level14_89934Data6C770View3;
            goto testOriginalCounter942;
        case 31:
            Level14_89934Call35DDCView1(ownerRecord17, 0x50, 0, 0, 0);
            rawWord2 = Level14_89934CountTimerDownView1(privateRecord19 + 0x10, 2);
        testOriginalCounter942:
            if (rawWord2 != 0) {
                Level14_89934Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level14_89934RequestMobyAnimationView1(ownerRecord17, 0);
            }
            goto updateOriginalBoundary1064;
        case 7:
            retainedDirectionVectorOrDistance16 = Level14_89934Field(ownerRecord17, void**, 0);
            retainedStateResultOrPlayerView18 = 0;
            if (Level14_89934Data6C770View1 != 0) {
                if (Level14_89934Field(ownerRecord17, unsigned char*, 0x3D) == 7) {
                    Level14_89934SetMobyAnimationView1(ownerRecord17, 8);
                }
            }
            Level14_89934Field(ownerRecord17, int*, 0x14) =
                (int)(Level14_89934Field(ownerRecord17, int*, 0x14) +
                      Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 6));
            Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 6) =
                (short)((unsigned short)Level14_89934Field(retainedDirectionVectorOrDistance16,
                                                           short*, 6) -
                        0x10);
            Level14_89934Call35EE0View1(
                ownerRecord17,
                Level14_89934Field(retainedDirectionVectorOrDistance16, unsigned char*, 0x11),
                Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 4), 0x1C2, 0, 2);
            temporaryWord9 =
                (unsigned short)Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 4) -
                0xA;
            Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 4) = temporaryWord9;
            if ((short)temporaryWord9 < 0x28) {
                Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 4) = 0x28;
            }
            Level14_89934CopyVectorView1(&originalFrame.sp60, ownerRecord17 + 0xC);
            if (Level14_89934Field(retainedDirectionVectorOrDistance16, short*, 6) < 0) {
                temporaryWord22 = originalFrame.sp68 + 0x190;
            } else {
                temporaryWord22 = originalFrame.sp68 + 0x1E0;
            }
            originalFrame.sp68 = temporaryWord22;
            __asm__ volatile("" ::"m"(originalFrame.sp68));
            if (Level14_89934Call19138View1(&originalFrame.sp60, 0x1C2, 1, 0, 0, 0) != 0) {
                temporaryWord23 = 0;
                if (Level14_89934Data71930View8 != 0) {
                    temporaryWord23 = Level14_89934Field(Level14_89934Data71930View9, short*, 0x36);
                }
                if (((temporaryWord23 == 0x1A5) &&
                     ((unsigned char)Level14_89934Field(Level14_89934Data71930View10,
                                                        unsigned char*, 0x48) < 2U)) ||
                    (temporaryWord23 == 0x1C2) || ((unsigned int)(temporaryWord23 - 0x1D6) < 2U) ||
                    ((unsigned int)(temporaryWord23 - 0x1D8) < 2U)) {
                    Level14_89934Field(Level14_89934Data71930View11, int*, 0x18) = 0xA0000;
                } else {
                    retainedStateResultOrPlayerView18 = 1;
                }
            }
            if ((retainedStateResultOrPlayerView18 != 0) ||
                (Level14_89934CountTimerDownView1(retainedDirectionVectorOrDistance16 + 0x16, 1) !=
                 0)) {
                Level14_89934RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                if (Level14_89934Field(ownerRecord17, unsigned char*, 0x3A) == 0xFF) {
                    Level14_89934Call3BA00View1(ownerRecord17);
                }
                Level14_89934Call369B8View1(ownerRecord17, 0x1E);
                Level14_89934DeleteMobyView1(ownerRecord17);
                return;
            }
            goto updateOriginalBoundary1064;
        default:
        updateOriginalBoundary1064:
            if (retainedOriginalPositionFlag21 != 0) {
                temporaryWord1 =
                    Level14_89934Field(Level14_89934Field(privateRecord19, void**, 4), void**, 0xC);
                temporaryWord5 = Level14_89934Field(ownerRecord17, int*, 0xC);
                temporaryWord8 = Level14_89934Field(temporaryWord1, int*, 0);
                temporaryWord3 = Level14_89934Field(ownerRecord17, int*, 0x10);
                if (temporaryWord5 < temporaryWord8) {
                    if ((temporaryWord3 < Level14_89934Field(temporaryWord1, int*, 4)) &&
                        (Level14_89934Field(temporaryWord1, int*, 0x14) < temporaryWord3) &&
                        ((temporaryWord8 - temporaryWord5) < 0xA8C)) {
                        Level14_89934Field(ownerRecord17, int*, 0xC) =
                            (int)(temporaryWord8 - 0xA8C);
                        goto writeOriginalBoundaryFlag1136;
                    }
                } else {
                    temporaryWord20 = Level14_89934Field(temporaryWord1, int*, 0x30);
                    if (temporaryWord20 < temporaryWord5) {
                        if ((temporaryWord3 < Level14_89934Field(temporaryWord1, int*, 0x34)) &&
                            (Level14_89934Field(temporaryWord1, int*, 0x24) < temporaryWord3)) {
                            temporaryWord11 = Level14_89934Field(temporaryWord1, int*, 0x20);
                            if ((temporaryWord5 - temporaryWord11) < 0xA8C) {
                                Level14_89934Field(ownerRecord17, int*, 0xC) =
                                    (int)(temporaryWord11 + 0xA8C);
                                goto writeOriginalBoundaryFlag1136;
                            }
                        }
                    } else if ((temporaryWord5 < temporaryWord20) &&
                               (temporaryWord8 < temporaryWord5)) {
                        temporaryWord12 = Level14_89934Field(temporaryWord1, int*, 4);
                        if (temporaryWord12 < temporaryWord3) {
                            if ((temporaryWord3 - temporaryWord12) < 0xA8C) {
                                Level14_89934Field(ownerRecord17, int*, 0x10) =
                                    (int)(temporaryWord12 + 0xA8C);
                                goto writeOriginalBoundaryFlag1136;
                            }
                        } else {
                            temporaryWord13 = Level14_89934Field(temporaryWord1, int*, 0x14);
                            if ((temporaryWord3 < temporaryWord13) &&
                                ((temporaryWord13 - temporaryWord3) < 0xA8C)) {
                                Level14_89934Field(ownerRecord17, int*, 0x10) =
                                    (int)(temporaryWord13 - 0xA8C);
                            writeOriginalBoundaryFlag1136:
                                Level14_89934Field(ownerRecord17, unsigned char*, 0x49) = 2U;
                            }
                        }
                    }
                }
            }
            return;
    }
}
#undef Level14_89934Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008AB2C.
 * Assembly SHA256 0cb9160648352cc1b0bccc147172d45171147d067315c934c87472430b5d5dc4.
 * AI generated; not human reviewed. All368 original instructions, eleven
 * selectors bias0 and one owned table-padding word are required.
 * Frame40 retains outgoing argumentsSP10/SP14, scratchSP18..20 and every
 * original S0/S1/S2/S3/RA save and restore. Private0 has distinct original
 * byte index, unsigned-halfword load, signed-halfword load and halfword
 * store operations; its counter is never narrowed to the prior m2c byte.
 * Signed ordinary C (Data6C648*15)/10 retains the complete original magic
 * product and delayed HI consumer while independent table loads execute.
 * The original player250 reload, two gated indirect spawn paths, five-entry
 * loop, six-argument1BA30 call, particle arithmetic and tag stores remain.
 * Initialized empty constraints and dead-before-producer clobbers emit zero
 * CPU instructions and restore original argument and counter-load priority.
 * No partial HI producer, product binding, FP shortcut or opcode patch.
 * Raw units/fixed point and complete helper contracts remain unresolved;
 * cadence is per invocation, with caller rate and runtime completeness open.
 * Falsification: every native/linked instruction, actual call/internal/branch
 * target, selector/padding/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized retail runtime behavior. */
#define Actor14Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int A14Call35D38() __asm__("func_80035D38");
int Actor14CountTimerDownView1() __asm__("func_800359A4");
int Actor14RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
void* Actor14Call1BA30View1() __asm__("func_8001BA30");
int Actor14PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor14PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor14RandBetweenView1() __asm__("func_8003636C");
int Actor14TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Actor14AddVectorView1() __asm__("func_8004F194");
int Actor14DeleteMobyView1() __asm__("func_80055B18");
extern int Actor14Data6C648View1 __asm__("D_8006C648");
extern int Actor14Data6C578View1 __asm__("D_8006C578");
extern int Actor14Data6C574View1 __asm__("D_8006C574");
extern int Actor14Data6C7E8View1 __asm__("D_8006C7E8");
extern int Actor14Data70328View1 __asm__("D_80070328");
extern int Actor14Data70328_4View1 __asm__("D_80070328+4");
extern void* Actor14Data70328_250View1 __asm__("D_80070328+0x250");
extern unsigned short Actor14Data65920View1[] __asm__("D_80065920");
extern void* (*Actor14SpawnMobyView1)() __asm__("SpawnMoby");
extern void* (*Actor14SpawnParticleView1)() __asm__("SpawnParticle");
void func_level_14_8008AB2C(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register void* privateRecord18 __asm__("$18");
    register int loopValue16 __asm__("$16");
    register void* ownerPosition16 __asm__("$16");
    register int counterOrLimit19 __asm__("$19");
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register void* argumentPointer4 __asm__("$4");
    register void* argumentPointer5 __asm__("$5");
    register void* argumentPointer6 __asm__("$6");
    register int argumentWord7 __asm__("$7");
    register void* returnedPointer2 __asm__("$2");
    register void* returnedPointer3 __asm__("$3");
    register void* (*indirectCall2)() __asm__("$2");
    register void* (*indirectParticleCall3)() __asm__("$3");
    struct {
        int sp18, sp1C, sp20;
    } frame;
    int scaledStepQuotient;
    ownerRecord17 = input;
    rawWord2 = Actor14Field(ownerRecord17, unsigned char*, 0x49);
    privateRecord18 = Actor14Field(ownerRecord17, void**, 0);
    if (!rawWord2) {
        rawWord2 = Actor14Field(ownerRecord17, int*, 0x14);
        rawWord2 -= 256;
        Actor14Field(ownerRecord17, int*, 0x14) = rawWord2;
        Actor14Field(privateRecord18, short*, 2) = rawWord2;
        rawWord2 = A14Call35D38();
        Actor14Field(privateRecord18, short*, 4) = rawWord2;
        rawWord2 = 1;
        Actor14Field(ownerRecord17, unsigned char*, 0x49) = rawWord2;
    }
    rawWord2 = Actor14Field(ownerRecord17, int*, 0x18);
    rawWord3 = 0x110000;
    rawWord2 &= rawWord3;
    if (!rawWord2)
        goto loadState;
    rawWord3 = Actor14Field(ownerRecord17, unsigned char*, 0x48);
    if (!rawWord3)
        goto setState2;
    rawWord2 = 4;
    if (rawWord3 != rawWord2)
        goto dispatch;
setState2:
    rawWord2 = 2;
    Actor14Field(ownerRecord17, int*, 0x18) = 0;
    Actor14Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
loadState:
    rawWord3 = Actor14Field(ownerRecord17, unsigned char*, 0x48);
dispatch:
    switch (rawWord3) {
        case 10:
            MATCHING_OBSERVE_VOLATILE(rawWord3);
            rawWord2 = 10;
            Actor14Field(ownerRecord17, unsigned char*, 0x49) = rawWord2;
            Actor14Field(ownerRecord17, unsigned char*, 0x48) = 0;
            goto finalTag;
        case 0:
            argumentWord4 = Actor14Data6C648View1 * 15;
            scaledStepQuotient = argumentWord4 / 10;
            rawWord2 = Actor14Field(privateRecord18, unsigned char*, 0);
            rawWord2 <<= 1;
            rawWord2 = Actor14Data65920View1[rawWord2 / 2];
            rawWord3 = Actor14Field(privateRecord18, short*, 2);
            rawWord2 = (rawWord2 << 16) >> 21;
            rawWord3 += rawWord2;
            Actor14Field(ownerRecord17, int*, 0x14) = rawWord3;
            rawWord2 = Actor14Field(privateRecord18, unsigned short*, 0);
            rawWord3 = scaledStepQuotient;
            rawWord2 += rawWord3;
            Actor14Field(privateRecord18, unsigned short*, 0) = rawWord2;
            goto finalTag;
        case 1:
            rawWord3 = Actor14Field(ownerRecord17, unsigned char*, 0x49);
            rawWord2 = 10;
            argumentPointer4 = privateRecord18;
            if (rawWord3 != rawWord2)
                goto initialize1;
            rawWord2 = (int)Actor14Data70328_250View1;
            if (!rawWord2)
                goto timer30;
            rawWord2 = 300;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "memory");
            argumentPointer4 = Actor14Data70328_250View1;
            MATCHING_KEEP(argumentPointer4);
            rawWord3 = Actor14Field(argumentPointer4, short*, 0x36);
            if (rawWord3 != rawWord2)
                goto timer30;
            rawWord2 = (int)Actor14Field(argumentPointer4, void**, 0);
            rawWord2 = Actor14Field((void*)rawWord2, int*, 8);
            if (rawWord2)
                goto timer30;
            Actor14Field(privateRecord18, short*, 0) = 0;
            goto timerReady;
        timer30:
            rawWord2 = 30;
            Actor14Field(privateRecord18, short*, 0) = rawWord2;
        timerReady:
            argumentPointer4 = privateRecord18;
        initialize1:
            argumentWord5 = 2;
            Actor14Field(ownerRecord17, int*, 8) = 0;
            Actor14Field(ownerRecord17, unsigned char*, 0x41) = 0;
            Actor14Field(ownerRecord17, unsigned char*, 0x4C) = 0;
            Actor14Field(ownerRecord17, unsigned char*, 0x4D) = 0;
            rawWord2 = Actor14CountTimerDownView1(argumentPointer4, argumentWord5);
            argumentPointer4 = ownerRecord17;
            if (!rawWord2)
                goto finalTag;
            Actor14RefreshMobySpatialGridAndBasisView1(argumentPointer4, 7);
            rawWord3 = 1;
            rawWord2 = 32;
            Actor14Field(ownerRecord17, unsigned char*, 0x41) = rawWord3;
            Actor14Field(ownerRecord17, unsigned char*, 0x4C) = rawWord2;
            Actor14Field(ownerRecord17, unsigned char*, 0x4D) = rawWord3;
            rawWord3 = Actor14Field(privateRecord18, short*, 2);
            rawWord2 = 4;
            Actor14Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
            Actor14Field(ownerRecord17, int*, 0x18) = 0;
            rawWord3 -= 2048;
            Actor14Field(ownerRecord17, int*, 0x14) = rawWord3;
            goto finalTag;
        case 4:
        case 5:
            rawWord2 = Actor14Field(privateRecord18, short*, 2);
            rawWord3 = Actor14Field(ownerRecord17, int*, 0x14);
            rawWord2 = rawWord3 < rawWord2;
            argumentPointer4 = ownerRecord17 + 12;
            if (!rawWord2)
                goto rotate4;
            argumentWord5 = 250;
            argumentPointer6 = (void*)3;
            argumentWord7 = 0;
            MATCHING_KEEP3_CLOBBER(argumentWord5, argumentPointer6, argumentWord7, "$2");
            rawWord2 = rawWord3 + 50;
            Actor14Field(ownerRecord17, int*, 0x14) = rawWord2;
            returnedPointer2 = Actor14Call1BA30View1(
                argumentPointer4, argumentWord5, argumentPointer6, argumentWord7, 0, ownerRecord17);
            if (!returnedPointer2)
                goto continue4;
            rawWord3 = Actor14Field(returnedPointer2, short*, 0x36);
            rawWord2 = 254;
            if (rawWord3 != rawWord2)
                goto continue4;
            rawWord2 = 2;
            Actor14Field(ownerRecord17, int*, 0x18) = 0;
            Actor14Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
            goto finalTag;
        continue4:
            rawWord3 = Actor14Field(ownerRecord17, unsigned char*, 0x48);
            rawWord2 = 4;
            if (rawWord3 != rawWord2)
                goto height4;
            rawWord2 = Actor14Field(privateRecord18, short*, 4);
            rawWord3 = Actor14Field(ownerRecord17, int*, 0x14);
            rawWord2 -= 400;
            rawWord3 = rawWord3 < rawWord2;
            if (rawWord3)
                goto height4;
            rawWord2 = 5;
            Actor14Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
            MATCHING_KEEP(rawWord3);
            Actor14PlayMobySoundEventView1(ownerRecord17, 1, 0);
        height4:
            rawWord3 = Actor14Field(privateRecord18, short*, 2);
            rawWord2 = Actor14Field(ownerRecord17, int*, 0x14);
            rawWord2 = rawWord2 < rawWord3;
            if (rawWord2)
                goto rotate4;
            Actor14Field(ownerRecord17, unsigned char*, 0x48) = 0;
            Actor14Field(privateRecord18, short*, 0) = 0;
        rotate4:
            rawWord3 = Actor14Data6C648View1;
            rawWord2 = Actor14Field(ownerRecord17, unsigned char*, 0x46);
            rawWord2 += rawWord3;
            Actor14Field(ownerRecord17, unsigned char*, 0x46) = rawWord2;
            goto finalTag;
        case 2:
            Actor14PlayMobySoundEventView1(ownerRecord17, 2, 0);
            rawWord2 = Actor14Data6C578View1;
            rawWord3 = Actor14Data6C574View1;
            rawWord2 -= rawWord3;
            rawWord2 = rawWord2 < 21;
            if (rawWord2)
                goto particles2;
            rawWord2 = Actor14Data6C7E8View1;
            rawWord2 = rawWord2 < 15361;
            if (rawWord2)
                goto particles2;
            argumentWord4 = 100;
            MATCHING_KEEP_CLOBBER(argumentWord4, "$2");
            indirectCall2 = Actor14SpawnMobyView1;
            returnedPointer3 = indirectCall2(argumentWord4, ownerRecord17);
            rawWord2 = 4;
            if (returnedPointer3) {
                Actor14Field(returnedPointer3, unsigned char*, 0x48) = 0;
                Actor14Field(returnedPointer3, unsigned char*, 0x47) = rawWord2;
            }
        particles2:
            argumentWord4 = 8;
            argumentWord5 = 70;
            MATCHING_KEEP2_CLOBBER(argumentWord4, argumentWord5, "$6");
            argumentPointer6 = ownerRecord17 + 12;
            MATCHING_KEEP_CLOBBER(argumentPointer6, "$2");
            indirectCall2 = Actor14SpawnParticleView1;
            indirectCall2(argumentWord4, argumentWord5, argumentPointer6, 16);
            argumentPointer6 = 0;
            rawWord3 = Actor14Data70328View1;
            argumentWord4 = Actor14Field(ownerRecord17, int*, 12);
            rawWord2 = Actor14Data70328_4View1;
            argumentWord5 = Actor14Field(ownerRecord17, int*, 16);
            argumentWord4 = rawWord3 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Actor14PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentPointer6);
            argumentWord4 = 0;
            argumentWord5 = 127;
            Actor14Field(ownerRecord17, unsigned char*, 0x46) = rawWord2;
            rawWord2 = Actor14RandBetweenView1(argumentWord4, argumentWord5);
            rawWord3 = Actor14Data6C578View1;
            argumentWord4 = Actor14Data6C574View1;
            rawWord3 -= argumentWord4;
            rawWord3 = rawWord3 < 21;
            counterOrLimit19 = 0;
            if (rawWord3)
                goto done2;
            loopValue16 = rawWord2;
        spawnLoop2:
            rawWord2 = Actor14Data6C7E8View1;
            rawWord2 = rawWord2 < 15361;
            argumentWord4 = 532;
            if (rawWord2)
                goto done2;
            indirectCall2 = Actor14SpawnMobyView1;
            returnedPointer2 = indirectCall2(argumentWord4, ownerRecord17);
            MATCHING_KEEP_CLOBBER(returnedPointer2, "$5");
            argumentPointer4 = returnedPointer2;
            MATCHING_KEEP(argumentPointer4);
            rawWord2 = 3;
            if (!argumentPointer4)
                goto next2;
            Actor14Field(argumentPointer4, unsigned char*, 0x41) = 0;
            Actor14Field(argumentPointer4, unsigned char*, 0x4C) = 0;
            Actor14Field(argumentPointer4, unsigned char*, 0x4D) = 0;
            rawWord3 = Actor14Field(ownerRecord17, unsigned char*, 0x46);
            Actor14Field(argumentPointer4, unsigned char*, 0x48) = rawWord2;
            Actor14Field(argumentPointer4, unsigned char*, 0x46) = rawWord3;
            rawWord3 = (int)Actor14Field(argumentPointer4, void**, 0);
            rawWord2 = 5;
            Actor14Field(argumentPointer4, unsigned char*, 0x44) = loopValue16;
            Actor14Field(argumentPointer4, int*, 8) = 0;
            Actor14Field((void*)rawWord3, short*, 0) = rawWord2;
        next2:
            counterOrLimit19 += 1;
            rawWord2 = counterOrLimit19 < 5;
            loopValue16 += 51;
            if (!rawWord2)
                goto done2;
            rawWord2 = Actor14Data6C578View1;
            rawWord3 = Actor14Data6C574View1;
            rawWord2 -= rawWord3;
            rawWord2 = rawWord2 < 21;
            if (!rawWord2)
                goto spawnLoop2;
        done2:
            rawWord2 = 1;
            Actor14Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
            rawWord2 = 500;
            Actor14Field(privateRecord18, short*, 0) = rawWord2;
            return;
        case 3:
            rawWord2 = 150;
            frame.sp18 = 0;
            frame.sp1C = rawWord2;
            frame.sp20 = 0;
            rawWord2 = Actor14Field(privateRecord18, short*, 0);
            __asm__ volatile("" ::: "$19", "memory");
            counterOrLimit19 = 5;
            argumentPointer4 = ownerRecord17;
            if (rawWord2 == counterOrLimit19) {
                rawWord2 = 700;
                frame.sp1C = rawWord2;
            }
            Actor14RefreshMobySpatialGridAndBasisView1(argumentPointer4, 4);
            argumentPointer4 = ownerRecord17 + 32;
            argumentPointer5 = &frame.sp18;
            argumentPointer6 = argumentPointer5;
            Actor14TransformVectorByBasisView1(argumentPointer4, argumentPointer5,
                                               argumentPointer6);
            ownerPosition16 = ownerRecord17 + 12;
            argumentPointer4 = ownerPosition16;
            argumentPointer5 = ownerPosition16;
            argumentPointer6 = &frame.sp18;
            Actor14AddVectorView1(argumentPointer4, argumentPointer5, argumentPointer6);
            argumentWord4 = 1;
            argumentWord5 = 13;
            MATCHING_KEEP2_CLOBBER(argumentWord4, argumentWord5, "$6");
            argumentPointer6 = ownerPosition16;
            frame.sp18 = 0;
            frame.sp1C = 0;
            rawWord3 = Actor14Field(privateRecord18, short*, 0);
            argumentWord7 = (int)&frame.sp18;
            rawWord3 = counterOrLimit19 - rawWord3;
            rawWord2 = rawWord3 * 6;
            indirectParticleCall3 = Actor14SpawnParticleView1;
            rawWord2 = -rawWord2;
            frame.sp20 = rawWord2;
            argumentPointer4 = indirectParticleCall3(argumentWord4, argumentWord5, argumentPointer6,
                                                     argumentWord7);
            if (argumentPointer4) {
                rawWord2 = Actor14Field(privateRecord18, short*, 0);
                rawWord2 = counterOrLimit19 - rawWord2;
                rawWord3 = rawWord2 * 3;
                rawWord3 <<= 2;
                rawWord3 -= rawWord2;
                rawWord3 <<= 1;
                rawWord2 = 120;
                rawWord2 -= rawWord3;
                Actor14Field(argumentPointer4, unsigned char*, 10) = rawWord2;
            }
            rawWord2 = Actor14Field(privateRecord18, unsigned short*, 0);
            rawWord2 -= 1;
            Actor14Field(privateRecord18, short*, 0) = rawWord2;
            rawWord2 <<= 16;
            if (rawWord2 > 0)
                return;
            Actor14DeleteMobyView1(ownerRecord17);
            return;
        default:
            goto finalTag;
    }
finalTag:
    rawWord3 = Actor14Field(privateRecord18, short*, 4);
    if (!rawWord3)
        return;
    argumentWord5 = Actor14Field(ownerRecord17, unsigned char*, 0x48);
    if (!argumentWord5)
        goto tagStore;
    rawWord2 = 4;
    if (argumentWord5 != rawWord2)
        return;
tagStore:
    rawWord2 = 0xFFFFFF;
    rawWord3 = -rawWord3;
    rawWord3 &= rawWord2;
    rawWord2 = 0x80000000;
    rawWord3 |= rawWord2;
    Actor14Field(ownerRecord17, int*, 0x54) = rawWord3;
}
#undef Actor14Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_8008B0EC.s SHA256 7968551160b5939525d6e67fb2b28c055c31d940eb0c4f41b6e478d26d35e3bd. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller8B0EC_func_80019138() __asm__("func_80019138");                 /* extern */
void* Controller8B0EC_func_8001BA30() __asm__("func_8001BA30");               /* extern */
int Controller8B0ECCountTimerDown() __asm__("func_800359A4");                 /* extern */
int Controller8B0EC_func_80035DDC() __asm__("func_80035DDC");                 /* extern */
int Controller8B0EC_func_80036220() __asm__("func_80036220");                 /* extern */
int Controller8B0ECRandBetween() __asm__("func_8003636C");                    /* extern */
int Controller8B0ECRandSignedBetween() __asm__("func_800363DC");              /* extern */
void* Controller8B0EC_func_800391E8() __asm__("func_800391E8");               /* extern */
int Controller8B0ECPlayMobySoundEvent() __asm__("func_8003BABC");             /* extern */
int Controller8B0ECPlanarHeadingLookup() __asm__("func_8004E880");            /* extern */
int Controller8B0ECTransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Controller8B0ECCopyVector() __asm__("func_8004F178");                     /* extern */
int Controller8B0ECAddVector() __asm__("func_8004F194");                      /* extern */
int Controller8B0ECDeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller8B0ECRefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
extern unsigned char Controller8B0EC_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller8B0EC_D_80065920 __asm__("D_80065920");
extern int Controller8B0EC_D_8006C574 __asm__("D_8006C574");
extern int Controller8B0EC_D_8006C578 __asm__("D_8006C578");
extern int Controller8B0EC_D_8006C7E8 __asm__("D_8006C7E8");
extern unsigned char Controller8B0EC_D_80070328 __asm__("D_80070328");
extern void* (*Controller8B0EC_SpawnMoby)() __asm__("SpawnMoby");
extern void* (*Controller8B0EC_SpawnParticle)() __asm__("SpawnParticle");

void func_level_14_8008B0EC(void* input_arg0) {
    register void* owner __asm__("$18") = input_arg0;
    /* Original vectors at 0x20/0x30/0x40/0x50/0x5C/0x68 and padding. */
    struct {
        int sp20, sp24, sp28, pad2C, sp30, sp34, sp38, pad3C, sp40, sp44, sp48, pad4C, sp50, pad54,
            pad58, sp5C, sp60, sp64, sp68, sp6C, sp70, pad74;
    } frame;
    register int call6 __asm__("$6");
    register int sin5 __asm__("$5");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register void* call4 __asm__("$4");
    register int* state1Vector __asm__("$17");

    register int headerArg7 __asm__("$7");
    register int* ownerVectorState1 __asm__("$16");
    register int tableOffsetBytes __asm__("$5");
    int decrementedCount;
    int randomChildField;
    register int particleIndex __asm__("$16");
    register int childIndex __asm__("$16");
    register int helperFlag __asm__("$17");
    register int childField44 __asm__("$17");
    register int helperResult19138 __asm__("$20");
    register unsigned char tableIndexByte __asm__("$16");
    void* linkedObject;
    void* linkedObjectAfterTransform;
    register void* ownerVectorState0 __asm__("$16");
    register void* ownerData __asm__("$19");
    register void* state1Particle __asm__("$4");
    void* state0Particle;
    void* firstHelperObject;
    void* secondHelperObject;
    void* loopParticle;
    register void* child __asm__("$4");
    register void* result2 __asm__("$2");
    register int particleState __asm__("$17");
    void* lastChild;
    register void* headerOwnerVector __asm__("$4");

    MATCHING_KEEP(owner);
    helperResult19138 = 0;
    ownerData = M2C_FIELD(owner, void**, 0);
    helperFlag = 0;
    value3 = 1;
    value2 = M2C_FIELD(owner, unsigned char*, 0x48);
    if (value2 == value3) {
        frame.sp40 = 0;
        frame.sp44 = 0x96;
        frame.sp48 = 0;
        MATCHING_BARRIER("$4");
        call4 = owner;
        if (M2C_FIELD(ownerData, int*, 0) == 5) {
            frame.sp44 = 0x2BC;
        }
        Controller8B0ECRefreshMobySpatialGridAndBasis(call4, 4);
        call4 = owner + 0x20;
        MATCHING_KEEP(call4);
        state1Vector = &frame.sp40;
        Controller8B0ECTransformVectorByBasis(call4, state1Vector, state1Vector);
        ownerVectorState1 = owner + 0xC;
        Controller8B0ECAddVector(ownerVectorState1, ownerVectorState1, state1Vector);
        frame.sp40 = 0;
        frame.sp44 = 0;
        value3 = M2C_FIELD(ownerData, int*, 0);
        value3 = 5 - value3;
        value2 = value3 * 6;
        frame.sp48 = -value2;
        state1Particle = Controller8B0EC_SpawnParticle(1, 0xD, ownerVectorState1, state1Vector);
        if (state1Particle != 0) {
            M2C_FIELD(state1Particle, signed char*, 0xA) =
                (signed char)(0x78 - ((5 - M2C_FIELD(ownerData, int*, 0)) * 0x16));
        }
        decrementedCount = M2C_FIELD(ownerData, int*, 0) - 1;
        M2C_FIELD(ownerData, int*, 0) = decrementedCount;
        if (decrementedCount <= 0) {
            MATCHING_OBSERVE_VOLATILE(ownerData);
            goto destroyOwner;
        }
    } else {
        call4 = &frame.sp20;
        MATCHING_KEEP(call4);
        ownerVectorState0 = owner + 0xC;
        MATCHING_KEEP(ownerVectorState0);
        Controller8B0ECCopyVector(call4, ownerVectorState0);
        frame.sp20 += Controller8B0ECRandSignedBetween(0, 0x32);
        frame.sp24 += Controller8B0ECRandSignedBetween(0, 0x32);
        frame.sp28 += Controller8B0ECRandSignedBetween(0, 0x32);
        frame.sp30 = Controller8B0ECRandSignedBetween(0, 0xA);
        frame.sp34 = Controller8B0ECRandSignedBetween(0, 0xA);
        frame.sp38 = Controller8B0ECRandBetween(5, 8);
        state0Particle = Controller8B0EC_SpawnParticle(1, 0xD, &frame.sp20, &frame.sp30);
        if (state0Particle != 0) {
            M2C_FIELD(state0Particle, signed char*, 0xA) = 0x1E;
        }
        Controller8B0ECCopyVector(&frame.sp20, ownerVectorState0);
        Controller8B0EC_func_80035DDC(owner, 0x12C, 0, 0, 0);
        M2C_FIELD(owner, int*, 0x14) =
            (int)(M2C_FIELD(owner, int*, 0x14) + M2C_FIELD(ownerData, int*, 4));
        M2C_FIELD(ownerData, int*, 4) = (int)(M2C_FIELD(ownerData, int*, 4) - 1);
        if ((M2C_FIELD(owner, int*, 0xC) >= 0x400) && (M2C_FIELD(owner, int*, 0x10) >= 0x400) &&
            (M2C_FIELD(owner, int*, 0x14) >= 0x400)) {
            if (Controller8B0ECCountTimerDown(ownerData, 4) != 0) {
                helperFlag = 1;
            } else {
                linkedObject = M2C_FIELD(ownerData, void**, 8);
                if (linkedObject != 0) {
                    value3 = M2C_FIELD(linkedObject, short*, 0x36);
                    call6 = (int)&frame.sp68;
                    if (value3 == 0xFE) {
                        tableIndexByte = M2C_FIELD(linkedObject, unsigned char*, 0x46);
                        tableOffsetBytes = tableIndexByte * 2;
                        value2 = *(signed short*)(&Controller8B0EC_D_80065920 + tableOffsetBytes);
                        MATCHING_OBSERVE_VOLATILE(value2);
                        call4 = &frame.sp50;
                        MATCHING_KEEP2(call4, value2);
                        frame.sp68 = -(value2 * 300) >> 12;
                        sin5 = *(signed short*)(&Controller8B0EC_D_800658A0 + tableOffsetBytes);
                        MATCHING_KEEP(sin5);
                        frame.sp70 = 1400;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(sin5, "memory");
                        frame.sp6C = -(sin5 * 300) >> 12;
                        Controller8B0ECAddVector(call4, M2C_FIELD(ownerData, void**, 8) + 0xC,
                                                 call6);
                        frame.sp5C = 0xE10;
                        frame.sp60 = 0x384;
                        frame.sp64 = (int)tableIndexByte;
                        linkedObjectAfterTransform = M2C_FIELD(ownerData, void**, 8);
                        headerArg7 = 0xBB8;
                        if (M2C_FIELD(linkedObjectAfterTransform, unsigned char*, 0x48) == 0x1B) {
                            MATCHING_KEEP(owner);
                            headerOwnerVector = owner + 0xC;
                            if ((unsigned int)(M2C_FIELD(linkedObjectAfterTransform, unsigned char*,
                                                         0x49) -
                                               1) < 2U) {
                                headerArg7 = 0x5DC;
                                goto selectHeaderOwnerVector;
                            }
                        } else {
                        selectHeaderOwnerVector:
                            MATCHING_KEEP(owner);
                            headerOwnerVector = owner + 0xC;
                        }
                        if (Controller8B0EC_func_80036220(headerOwnerVector, &frame.sp50, 0,
                                                          headerArg7) != 0) {
                            M2C_FIELD(M2C_FIELD(ownerData, void**, 8), int*, 0x18) = 0x100000;
                            helperFlag = 1;
                            M2C_FIELD(M2C_FIELD(ownerData, void**, 8), unsigned char*, 0x51) =
                                (unsigned char)M2C_FIELD(owner, unsigned char*, 0x46);
                        }
                    }
                }
            }
            MATCHING_KEEP(owner);
            firstHelperObject = Controller8B0EC_func_8001BA30(owner + 0xC, 0xC8, 3, 0, 0, owner);
            if ((firstHelperObject != 0) && (M2C_FIELD(firstHelperObject, short*, 0x36) != 0xFE)) {
                M2C_FIELD(firstHelperObject, int*, 0x18) = 0x100000;
                helperFlag = 1;
                M2C_FIELD(firstHelperObject, unsigned char*, 0x51) =
                    (unsigned char)M2C_FIELD(owner, unsigned char*, 0x46);
            }
            MATCHING_KEEP(owner);
            call4 = owner + 0xC;
            if (helperFlag != 0)
                goto foundHelper;
            MATCHING_KEEP(helperFlag);
            helperResult19138 = Controller8B0EC_func_80019138(call4, 0xFA, 1, 0, 0, 0);
            if (helperResult19138 != 0) {
            foundHelper:
                MATCHING_KEEP(owner);
                if (helperResult19138 != 0) {
                    secondHelperObject =
                        Controller8B0EC_func_8001BA30(owner + 0xC, 0x1F4, 3, 0, 0, owner);
                    if ((secondHelperObject != 0) &&
                        (M2C_FIELD(secondHelperObject, short*, 0x36) != 0xFE)) {
                        M2C_FIELD(secondHelperObject, int*, 0x18) = 0x100000;
                        M2C_FIELD(secondHelperObject, unsigned char*, 0x51) =
                            (unsigned char)M2C_FIELD(owner, unsigned char*, 0x46);
                    }
                }
                particleIndex = 0;
                if ((Controller8B0EC_D_8006C578 - Controller8B0EC_D_8006C574) >= 0x15) {
                    particleState = 2;
                    MATCHING_KEEP_VOLATILE(particleState);
                spawnParticleLoop:
                    if (Controller8B0EC_D_8006C7E8 >= 0x3C01) {
                        loopParticle = Controller8B0EC_func_800391E8(1, 0x54, owner, 0,
                                                                     particleState, 0xC8, 0x100);
                        if (loopParticle != 0) {
                            M2C_FIELD(loopParticle, signed char*, 0x48) = particleState;
                            M2C_FIELD(loopParticle, signed char*, 0x4F) = 0x1C;
                        }
                        particleIndex += 1;
                        call6 = 0;
                        /* This exit bypasses the second zero-argument producer. */
                        if (particleIndex >= 5)
                            goto angleReady;
                        MATCHING_OBSERVE(call6);
                        if ((Controller8B0EC_D_8006C578 - Controller8B0EC_D_8006C574) >= 0x15)
                            goto spawnParticleLoop;
                    }
                }
                MATCHING_BARRIER_VOLATILE("$6");
                call6 = 0;
            angleReady:
                MATCHING_KEEP(call6);
                M2C_FIELD(owner, unsigned char*, 0x46) = Controller8B0ECPlanarHeadingLookup(
                    M2C_FIELD(&Controller8B0EC_D_80070328, int*, 0) - M2C_FIELD(owner, int*, 0xC),
                    M2C_FIELD(&Controller8B0EC_D_80070328, int*, 4) - M2C_FIELD(owner, int*, 0x10),
                    call6);
                randomChildField = Controller8B0ECRandBetween(0, 0x7F);
                childIndex = 0;
                if ((Controller8B0EC_D_8006C578 - Controller8B0EC_D_8006C574) >= 0x15) {
                    childField44 = randomChildField;
                spawnChildLoop:
                    if (Controller8B0EC_D_8006C7E8 >= 0x3C01) {
                        result2 = Controller8B0EC_SpawnMoby(0x216, owner);
                        child = result2;
                        MATCHING_KEEP(child);
                        if (child != 0) {
                            M2C_FIELD(child, signed char*, 0x41) = 0;
                            M2C_FIELD(child, signed char*, 0x4C) = 0;
                            M2C_FIELD(child, signed char*, 0x4D) = 0;
                            value2 = 1;
                            value3 = M2C_FIELD(owner, unsigned char*, 0x46);
                            M2C_FIELD(child, signed char*, 0x48) = value2;
                            M2C_FIELD(child, unsigned char*, 0x46) = value3;
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(child, "memory");
                            value3 = (int)M2C_FIELD(child, void**, 0);
                            value2 = 5;
                            M2C_FIELD(child, signed char*, 0x44) = (signed char)childField44;
                            M2C_FIELD(child, int*, 8) = 0;
                            M2C_FIELD((void*)value3, int*, 0) = value2;
                        }
                        childIndex += 1;
                        childField44 += 0x33;
                        if ((childIndex < 5) &&
                            ((Controller8B0EC_D_8006C578 - Controller8B0EC_D_8006C574) >= 0x15)) {
                            goto spawnChildLoop;
                        }
                    }
                }
                MATCHING_BARRIER_VOLATILE("$4");
                MATCHING_KEEP(owner);
                Controller8B0EC_SpawnParticle(0xA, 0x46, owner + 0xC, (int*)0x10);
                if ((Controller8B0EC_D_8006C578 - Controller8B0EC_D_8006C574) >= 0x15) {
                    if (Controller8B0EC_D_8006C7E8 >= 0x3C01) {
                        lastChild = Controller8B0EC_SpawnMoby(0x64, owner);
                        if (lastChild != 0) {
                            M2C_FIELD(lastChild, signed char*, 0x48) = 0;
                        }
                    }
                }
                Controller8B0ECPlayMobySoundEvent(owner, 1, 0);
                goto destroyOwner;
            }
        } else {
        destroyOwner:
            Controller8B0ECDeleteMoby(owner);
        }
    }
}
#undef M2C_FIELD

void func_80055B18(Moby*);
void func_level_14_8008B798(Moby* moby) {
    if (moby->state == 1)
        func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_8008B7C8.s SHA256 4429422b63fc37948289c4663b21ca3f945baf271e7746bdb1413acff6f3a7a9. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level14_8B7C8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level14_8B7C8_func_80019194() __asm__("func_80019194");
/* extern */
unsigned char Level14_8B7C8_func_8001A358() __asm__("func_8001A358");
/* extern */
unsigned char Level14_8B7C8RequestMobyAnimation() __asm__("func_80034F40");
/* extern */
unsigned char Level14_8B7C8SetMobyAnimation() __asm__("func_80034F80");
/* extern */
unsigned char Level14_8B7C8TurnMobyTowardHeading() __asm__("func_8003585C");
/* extern */
int Level14_8B7C8CountTimerDown() __asm__("func_800359A4");
/* extern */
int Level14_8B7C8RandSignedBetween() __asm__("func_800363DC");
/* extern */
unsigned char Level14_8B7C8_func_800369B8() __asm__("func_800369B8");
/* extern */
unsigned char Level14_8B7C8_func_80036A68() __asm__("func_80036A68");
/* extern */
unsigned char Level14_8B7C8_func_8003B74C() __asm__("func_8003B74C");
/* extern */
unsigned char Level14_8B7C8_func_8003BA00() __asm__("func_8003BA00");
/* extern */
int Level14_8B7C8PlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned char Level14_8B7C8_func_8003BE70() __asm__("func_8003BE70");
/* extern */
int Level14_8B7C8PlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned char Level14_8B7C8TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
unsigned char Level14_8B7C8CopyVector() __asm__("func_8004F178");
/* extern */
unsigned char Level14_8B7C8AddVector() __asm__("func_8004F194");
/* extern */
int Level14_8B7C8AbsoluteByteAngleDelta() __asm__("func_8004F264");
/* extern */
int Level14_8B7C8ApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned char Level14_8B7C8DeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned char Level14_8B7C8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
unsigned char Level14_8B7C8_func_8005629C() __asm__("func_8005629C");
/* extern */
extern int Level14_8B7C8_D_8006C58C __asm__("D_8006C58C");
extern int Level14_8B7C8_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level14_8B7C8_D_8006D088 __asm__("D_8006D088");
extern unsigned char Level14_8B7C8_D_80070328 __asm__("D_80070328");
extern unsigned char Level14_8B7C8_D_800716B0 __asm__("D_800716B0");
extern unsigned char Level14_8B7C8_D_8007190C __asm__("D_8007190C");
extern unsigned char (*Level14_8B7C8_SpawnParticle)() __asm__("SpawnParticle");

void func_level_14_8008B7C8(void* ownerRecord) {
    /* Original 0x90-byte frame, with saved registers beginning at SP+0x78.
     * Every used scratch field retains its original SP offset. The C tail
     * padding accounts for compiler-managed alignment;
      all offsets were
     * checked in the original instruction stream. Raw table stride is16.
     * Helper36A68 retains all four original argument producers. Pointer
     * reuse and empty constraints preserve the original indirect call and
     * counter increment in its delay slot. No instruction assembly added.
     * Helper semantics, physical units and caller cadence remain open. */
    struct {
        void* sp18;
        short sp1C;
        short sp1E;
        void* sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        void* sp30;
        int sp34;
        int sp38;
        unsigned char pad3C[4];
        void* sp40;
        int sp44;
        int sp48;
        unsigned char pad4C[4];
        void* sp50;
        int sp54;
        int sp58;
        unsigned char pad5C[4];
        void* sp60;
        int sp64;
        int sp68;
        unsigned char pad6C[4];
    } scratch;

    register unsigned char* ownerPayload19 __asm__("$19");
    unsigned char* payloadArgument4;
    register void* argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register void* argument6 __asm__("$6");
    register void* argument7 __asm__("$7");
    register unsigned char (*particleFunction2)() __asm__("$2");
    register void* scratchVector18 __asm__("$18");
    short temp_v0;
    short temp_v1_4;
    short temp_v1_5;
    int temp_a0;
    int temp_a0_3;
    int temp_a1;
    int temp_a3;
    int temp_v1_3;
    int temp_v1_6;
    register int packetOrdinal18 __asm__("$18");
    register int branchFlag18 __asm__("$18");
    unsigned char tableCounterByte;
    unsigned char stateByte;
    unsigned char substateByte;
    register void** ownerPayload18 __asm__("$18");
    register void* privateRecord16 __asm__("$16");
    register void* linkedRecord19 __asm__("$19");
    void* tableEntry2;
    void* nextTableEntry2;
    void* var_a0_2;

    privateRecord16 = Level14_8B7C8Field(ownerRecord, void**, 0);
    if ((Level14_8B7C8Field(ownerRecord, unsigned char*, 0x48) == 0) &&
        (Level14_8B7C8Field(ownerRecord, int*, 0x18) != 0)) {
        Level14_8B7C8_func_80036A68(ownerRecord, 1, 0, 0);
        Level14_8B7C8Field(ownerRecord, unsigned char*, 0x48) = 1U;
        Level14_8B7C8SetMobyAnimation(ownerRecord, 1);
        temp_a0 = Level14_8B7C8Field(privateRecord16, int*, 8);
        Level14_8B7C8Field(privateRecord16, short*, 0) = 0x78;
        if (temp_a0 >= 0) {
            Level14_8B7C8_func_8003BE70(temp_a0);
            Level14_8B7C8Field(privateRecord16, int*, 8) = -1;
        }
        Level14_8B7C8PlayMobySoundEvent(ownerRecord, 1, 0);
    }
    stateByte = Level14_8B7C8Field(ownerRecord, unsigned char*, 0x48);
    switch (stateByte) {
        case 22:
            Level14_8B7C8Field(Level14_8B7C8Field(privateRecord16, void**, 4), unsigned short*, 2) =
                (unsigned short)Level14_8B7C8Field(privateRecord16, unsigned short*, 2);
            Level14_8B7C8Field(ownerRecord, unsigned char*, 0x48) = 0U;
            return;
        case 0:
            substateByte = Level14_8B7C8Field(ownerRecord, unsigned char*, 0x49);
            if (substateByte == 0) {
                if (Level14_8B7C8ApproximatePlanarDistance(ownerRecord + 0xC,
                                                           &Level14_8B7C8_D_80070328) < 0x2000) {
                    Level14_8B7C8Field(ownerRecord, unsigned char*, 0x49) = 1U;
                }
                goto block_19;
            }
            if (substateByte == 1) {
                if (Level14_8B7C8AbsoluteByteAngleDelta(
                        Level14_8B7C8PlanarHeadingLookup(
                            Level14_8B7C8Field(&Level14_8B7C8_D_80070328, int*, 0) -
                                Level14_8B7C8Field(ownerRecord, int*, 0xC),
                            Level14_8B7C8Field(&Level14_8B7C8_D_80070328, int*, 4) -
                                Level14_8B7C8Field(ownerRecord, int*, 0x10),
                            0),
                        Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46)) >= 0x41) {
                    Level14_8B7C8Field(privateRecord16, int*, 8) =
                        Level14_8B7C8PlayMobySoundEvent(ownerRecord, 0, 0);
                    Level14_8B7C8Field(ownerRecord, unsigned char*, 0x4A) = 0xFF;
                    Level14_8B7C8Field(ownerRecord, unsigned char*, 0x49) = 2U;
                    Level14_8B7C8Field(privateRecord16, short*, 0) = 0x23;
                block_19:
                }
                goto block_20;
            }
            if ((substateByte == 2) && (Level14_8B7C8CountTimerDown(privateRecord16, 2) != 0)) {
                temp_v1_3 = Level14_8B7C8_D_8006C58C * 6;
                tableCounterByte = *(&Level14_8B7C8_D_800716B0 + temp_v1_3);
                if (tableCounterByte < 0xFFU) {
                    *(&Level14_8B7C8_D_800716B0 + temp_v1_3) = tableCounterByte + 1;
                }
                Level14_8B7C8_func_8003B74C(&Level14_8B7C8_D_8006D088);
                return;
            }
        block_20:
            scratchVector18 = &scratch.sp20;
            MATCHING_KEEP_CLOBBER(scratchVector18, "$19");
            argument4 = scratchVector18;
            MATCHING_KEEP_CLOBBER(argument4, "$19");
            ownerPayload19 = ownerRecord + 0xC;
            Level14_8B7C8CopyVector(argument4, ownerPayload19);
            scratch.sp20 += Level14_8B7C8RandSignedBetween(0, 0x96);
            scratch.sp24 += Level14_8B7C8RandSignedBetween(0, 0x96);
            scratch.sp28 += Level14_8B7C8RandSignedBetween(0, 0x96);
            scratch.sp18 = Level14_8B7C8Field(privateRecord16, void**, 4);
            temp_v0 = Level14_8B7C8Field(Level14_8B7C8Field(privateRecord16, void**, 4),
                                         unsigned short*, 2) +
                      1;
            scratch.sp1C = temp_v0;
            temp_v1_4 =
                Level14_8B7C8Field(Level14_8B7C8Field(privateRecord16, void**, 4), short*, 0);
            if (temp_v0 >= temp_v1_4) {
                scratch.sp1C = temp_v1_4 - 1;
            }
            scratch.sp1E = 0;
            Level14_8B7C8_SpawnParticle(1, 0x3E, scratchVector18, &scratch.sp18);
            payloadArgument4 = ownerPayload19;
            goto finishPayloadUpdate;
        default:
            return;
        case 20:
            Level14_8B7C8Field(ownerRecord, signed char*, 0x41) = 0;
            Level14_8B7C8Field(ownerRecord, signed char*, 0x4C) = 0;
            Level14_8B7C8Field(ownerRecord, signed char*, 0x4D) = 0;
            Level14_8B7C8Field(ownerRecord, int*, 8) = 0;
            Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 4);
            scratch.sp40 = (void*)0x1C2;
            scratch.sp44 = 0;
            scratch.sp48 = 0;
            Level14_8B7C8TransformVectorByBasis(ownerRecord + 0x20, &scratch.sp40, &scratch.sp40);
            packetOrdinal18 = 0;
            do {
                scratch.sp30 = 0;
                scratch.sp34 = 0x800;
                scratch.sp38 = 0;
                Level14_8B7C8TransformVectorByBasis(ownerRecord + 0x20, &scratch.sp30,
                                                    &scratch.sp30);
                Level14_8B7C8AddVector(&scratch.sp30, ownerRecord + 0xC, &scratch.sp30);
                argument4 = (void*)1;
                argument5 = 39;
                argument6 = &scratch.sp30;
                argument7 = &scratch.sp40;
                __asm__(""
                        : "=r"(argument4), "=r"(argument5), "=r"(argument6), "=r"(argument7)
                        : "0"(argument4), "1"(argument5), "2"(argument6), "3"(argument7),
                          "r"(packetOrdinal18));
                particleFunction2 = Level14_8B7C8_SpawnParticle;
                __asm__(""
                        : "=r"(particleFunction2)
                        : "0"(particleFunction2), "r"(packetOrdinal18));
                packetOrdinal18 += 1;
                particleFunction2(argument4, argument5, argument6, argument7);
                Level14_8B7C8Field(ownerRecord, unsigned char*, 0x44) =
                    (unsigned char)(Level14_8B7C8Field(ownerRecord, unsigned char*, 0x44) + 0x10);
                Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 4);
            } while (packetOrdinal18 < 0x10);
            return;
        case 21:
            Level14_8B7C8Field(ownerRecord, signed char*, 0x41) = 0;
            Level14_8B7C8Field(ownerRecord, signed char*, 0x4C) = 0;
            Level14_8B7C8Field(ownerRecord, signed char*, 0x4D) = 0;
            Level14_8B7C8Field(ownerRecord, int*, 8) = 0;
            Level14_8B7C8Field(ownerRecord, signed char*, 0x4A) = 0xC;
            if (Level14_8B7C8Field(ownerRecord, unsigned char*, 0x49) == 0) {
                Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                scratch.sp50 = (void*)0x1C2;
                scratch.sp54 = 0;
                scratch.sp58 = 0;
                Level14_8B7C8TransformVectorByBasis(ownerRecord + 0x20, &scratch.sp50,
                                                    &scratch.sp50);
                Level14_8B7C8_SpawnParticle(1, 0x27, ownerRecord + 0xC, &scratch.sp50);
                Level14_8B7C8Field(ownerRecord, unsigned char*, 0x44) =
                    (unsigned char)(Level14_8B7C8Field(ownerRecord, unsigned char*, 0x44) + 0x10);
                Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 4);
            }
            Level14_8B7C8Field(ownerRecord, unsigned char*, 0x49) =
                (unsigned char)((Level14_8B7C8Field(ownerRecord, unsigned char*, 0x49) + 1) % 5);
            return;
        case 1:
        case 2:
            branchFlag18 = 0;
            if (Level14_8B7C8CountTimerDown(privateRecord16, 2) != 0)
                goto finishRecordExit;
            {
                linkedRecord19 = Level14_8B7C8Field(privateRecord16, void**, 4);
                Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) =
                    (unsigned char)(Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) + 0x80);
                tableEntry2 =
                    ((short)Level14_8B7C8Field(linkedRecord19, unsigned short*, 2) * 0x10) +
                    Level14_8B7C8Field(linkedRecord19, int*, 0xC);
                if (Level14_8B7C8AbsoluteByteAngleDelta(
                        Level14_8B7C8PlanarHeadingLookup(
                            Level14_8B7C8Field(tableEntry2, int*, 0) -
                                Level14_8B7C8Field(ownerRecord, int*, 0xC),
                            Level14_8B7C8Field(tableEntry2, int*, 4) -
                                Level14_8B7C8Field(ownerRecord, int*, 0x10),
                            0),
                        Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46)) >= 0x41) {
                    branchFlag18 = 1;
                }
                Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) =
                    (unsigned char)(Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) + 0x80);
                if (branchFlag18 != 0) {
                    temp_v1_5 = Level14_8B7C8Field(linkedRecord19, short*, 0);
                    temp_a0_3 = (short)Level14_8B7C8Field(linkedRecord19, unsigned short*, 2) + 1;
                    Level14_8B7C8Field(linkedRecord19, unsigned short*, 2) =
                        (unsigned short)((int)(temp_a0_3 + temp_v1_5) % temp_v1_5);
                    if (temp_a0_3 >= Level14_8B7C8Field(linkedRecord19, short*, 0)) {
                    finishRecordExit:
                        Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                        Level14_8B7C8_func_8003BA00(ownerRecord);
                        Level14_8B7C8_func_800369B8(ownerRecord, 0x1E);
                        Level14_8B7C8DeleteMoby(ownerRecord);
                        return;
                    }
                }
                nextTableEntry2 =
                    ((short)Level14_8B7C8Field(linkedRecord19, unsigned short*, 2) * 0x10) +
                    Level14_8B7C8Field(linkedRecord19, int*, 0xC);
                temp_a3 = Level14_8B7C8Field(nextTableEntry2, int*, 0x10);
                temp_a1 = Level14_8B7C8PlanarHeadingLookup(
                    temp_a3 - Level14_8B7C8Field(nextTableEntry2, int*, 0),
                    Level14_8B7C8Field(nextTableEntry2, int*, 0x14) -
                        Level14_8B7C8Field(nextTableEntry2, int*, 4),
                    0, temp_a3);
                Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) =
                    (unsigned char)(Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) + 0x80);
                Level14_8B7C8TurnMobyTowardHeading(ownerRecord, temp_a1, 6, 6, 1, 0);
                Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) =
                    (unsigned char)(Level14_8B7C8Field(ownerRecord, unsigned char*, 0x46) + 0x80);
                scratch.sp60 = (void*)-0x2BC;
                scratch.sp64 = 0;
                scratch.sp68 = 0;
                Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level14_8B7C8TransformVectorByBasis(ownerRecord + 0x20, &scratch.sp60,
                                                    &scratch.sp60);
                ownerPayload18 = ownerRecord + 0xC;
                Level14_8B7C8AddVector(ownerPayload18, &scratch.sp60, ownerPayload18);
                temp_v1_6 = Level14_8B7C8Field(ownerRecord, int*, 0x14);
                if (temp_v1_6 <
                    (Level14_8B7C8Field(
                         (((short)Level14_8B7C8Field(linkedRecord19, unsigned short*, 2) * 0x10) +
                          Level14_8B7C8Field(linkedRecord19, int*, 0xC)),
                         int*, 8) +
                     0xD48)) {
                    Level14_8B7C8Field(ownerRecord, int*, 0x14) = (int)(temp_v1_6 + 0x32);
                }
                if (Level14_8B7C8_func_80019194(ownerPayload18, 0x2BC) != 0) {
                    Level14_8B7C8CopyVector(ownerPayload18, &Level14_8B7C8_D_8007190C);
                }
                if ((Level14_8B7C8_D_8006C770 != 0) &&
                    (Level14_8B7C8Field(ownerRecord, unsigned char*, 0x48) == 1)) {
                    Level14_8B7C8RequestMobyAnimation(ownerRecord, 2);
                    Level14_8B7C8Field(ownerRecord, unsigned char*, 0x48) = 2U;
                }
                payloadArgument4 = ownerRecord + 0xC;
                goto finishPayloadUpdate;
            }
            return;
    }
    return;
finishPayloadUpdate:
    Level14_8B7C8_func_8001A358(payloadArgument4, 0x2000);
    Level14_8B7C8_func_8005629C(ownerRecord);
    Level14_8B7C8RefreshMobySpatialGridAndBasis(ownerRecord, 2);
}
#undef Level14_8B7C8Field

extern int D_8006C770;
void DecodedStateFragmentStart(Moby*, void*, int, int) __asm__("func_80038F14");
int DecodedStateFragmentUpdate(Moby*, void*) __asm__("func_80035194");
void func_level_14_8008BE8C(Moby* moby) {
    unsigned short* tag = moby->mobyTag;
    int result;
    switch (moby->state) {
        case 0:
            if (D_8006C770) {
                moby->state = 5;
                func_80034F40(moby, 5);
            }
            break;
        case 5:
            if (D_8006C770) {
                moby->state = 6;
                func_80034F40(moby, 6);
            }
            break;
        case 3:
        case 7:
            if (D_8006C770) {
                moby->state = 2;
                func_80034F40(moby, 2);
            }
            break;
        case 2:
            if (D_8006C770) {
                MATCHING_KEEP_CLOBBER(tag, "memory");
                goto remove;
            }
            break;
        case 21:
            if (D_8006C770) {
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            break;
        case 1:
            if (D_8006C770) {
                func_80034F40(moby, 2);
                moby->state = 22;
            }
            break;
        case 22:
            if (D_8006C770) {
                MATCHING_KEEP_CLOBBER(moby, "memory");
                goto remove;
            }
            break;
        case 20:
            if (moby->linkedMoby != 0xFF) {
                DecodedStateFragmentStart(moby, tag, 1, 8);
                tag[3] += 0xC8;
                tag[2] += 0x50;
            }
            break;
        case 8:
            result = DecodedStateFragmentUpdate(moby, tag);
            if (result == 0x100 || result == 0x10 || result == 3) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 0x40);
            remove:
                func_80055B18(moby);
            }
            break;
        case 4:
        case 6:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
    }
}

typedef struct {
    int bounds[6];
    int mobyIndex;
    short margin, requiredState;
    int finalState;
} DecodedCameraTriggerTag;
extern Moby* D_8006C550;
extern Moby* D_8006E164;
extern int D_8006E160;
extern int DecodedCameraTriggerBounds(Vector3D*, void*, int, int) __asm__("func_80036220");
void func_level_14_8008C07C(Moby* input) {
    register Moby* moby __asm__("$18") = input;
    register DecodedCameraTriggerTag* tag __asm__("$17");
    Moby* target;
    int requiredState;
    register int targetState __asm__("$3");
    register int finalState __asm__("$2");
    register Moby** camera __asm__("$3");
    MATCHING_KEEP(moby);
    tag = moby->mobyTag;
    target = &D_8006C550[tag->mobyIndex];
    if (DecodedCameraTriggerBounds((Vector3D*)&spyro, tag, 0, tag->margin)) {
        if (moby->state == 0) {
            requiredState = tag->requiredState;
            if (requiredState == 0 || target->state == requiredState) {
                moby->state = 1;
                func_80013ACC(target, 13);
                goto checkDeletion;
            }
        } else
            requiredState = tag->requiredState;
        if (requiredState)
            goto checkRequired;
        goto checkDeletion;
    } else if (moby->state == 1) {
        requiredState = tag->requiredState;
        if (requiredState) {
        checkRequired:
            if (target->state == requiredState)
                goto checkDeletion;
        }
        camera = &D_8006E164;
        MATCHING_KEEP_CLOBBER(camera, "memory");
        moby->state = 0;
        if (*camera == target) {
            D_8006E160 = 0;
            *camera = 0;
        }
    }
checkDeletion:
    targetState = target->state;
    MATCHING_KEEP(targetState);
    if (!(targetState & 0x80)) {
        finalState = tag->finalState;
        MATCHING_KEEP(finalState);
        if (targetState != finalState)
            goto finished;
    }
    if (moby->state == 1) {
        camera = &D_8006E164;
        MATCHING_KEEP_CLOBBER(camera, "memory");
        if (*camera == target) {
            D_8006E160 = 0;
            *camera = 0;
        }
    }
    func_80055B18(moby);
finished:;
}

/**
 * MobyUpdate_1015() - func_level_14_8008C210()
 * https://decomp.me/scratch/VsRCQ
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_14/moby/func_level_14_8008C210.s SHA256 5ca9ad9aaf3b54d34273d17e415b10b68c5e3d2ea6c956999943be9750efe8d1. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
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
void func_level_14_8008C210(Moby* inputOwner) {
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
