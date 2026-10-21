#include "matching.h"
#include "common.h"
#include "spu.h"
#include "spyro.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "mobyutil.h"
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
void func_level_35_80074EE0(void* input) {
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
void func_level_35_80075B3C(void* input) {
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
void func_level_35_8007708C(Moby* moby) {
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
void func_level_35_800771C8(Moby* moby) {
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
void func_level_35_80077284(Moby* moby) {
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
void func_level_35_80077338(Moby* moby) {
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
void func_level_35_8007763C(void* input) {
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
void func_level_35_800781B0(Moby* moby) {
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
void func_level_35_800784CC(Moby* moby) {
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

typedef struct {
    unsigned char reserved00[0x18];
    int threshold;
} DecodedSpawnThreshold;
extern int D_8006C578, D_8006C574, D_8006C770, D_8006C640;
int rand(void);
void func_80055B18(Moby*);
int func_80055E84(Moby*);
void func_level_35_8007860C(Moby* actor) {
    DecodedSpawnThreshold* tag = actor->mobyTag;
    Vector3D velocity, position;
    int count;
    switch (actor->state) {
        case 0:
            actor->lowDrawDistance = 0;
            actor->drawn = 0;
            actor->state = 1;
            break;
        case 1:
            if (D_8006C578 - D_8006C574 >= 0x15 && (rand() & 0x3FF) < tag->threshold)
                SpawnMoby(actor->mobyClass, actor);
            break;
        case 2:
            if (D_8006C770) {
                func_80055B18(actor);
                break;
            }
            count = func_80055E84(actor);
            if (!actor->substate && count >= 0xA) {
                func_8003BABC(actor, 0, 0);
                actor->substate = 1;
            }
            if (!(D_8006C640 & 3) && count >= 0x16) {
                func_8004F178(&position, &actor->position);
                position.z += 0x80;
                velocity.x = (rand() & 6) - 3;
                velocity.y = (rand() & 6) - 3;
                velocity.z = 0x20;
                SpawnParticle(1, 0, &position, &velocity);
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
void func_level_35_800787C8(void* input) {
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
void func_level_35_80078C58(void* input) {
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
void func_level_35_80079128(Moby* moby) {
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

void func_level_35_80079408(Moby* moby) {
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
void func_level_35_80079428(Moby* argument) {
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
void func_level_35_80079758(Moby* moby) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 family:
 * level25 8007ACBC, level35 80079A70, level45 80079BE0.692 original
 * instructions and7 state targets plus padding per member. Evidence4863/64.
 * Raw widths/units/helper meanings/cadence unresolved; original linked words
 * and full retail hashes required before acceptance. Verified34 C reused. */
extern int F4865Gate __asm__("D_8006FA3C"),
    F4865Position __asm__("D_8006FA80"), F4865Mode __asm__("D_8006E044");
extern unsigned short F4865E040 __asm__("D_8006E040"), F4865E03E __asm__("D_8006E03E");
extern unsigned char F4865PlayerE __asm__("D_80070328 + 0xE"),
    F4865Player12 __asm__("D_80070328 + 0x12"), F4865PlayerD __asm__("D_80070328 + 0xD");
extern unsigned char F4865Player[] __asm__("D_80070328");
extern unsigned char *F4865Array __asm__("D_8006C550"), *F4865ArrayEnd __asm__("D_8006C704");
extern int F4865W20C __asm__("D_80070328 + 0x20C"), F4865W170 __asm__("D_80070328 + 0x170");
extern void* F4865W218 __asm__("D_80070328 + 0x218");
extern int (*F4865CallbackA0)() __asm__("unk_ovlheader_800743A0");
extern int (*F4865Callback24)() __asm__("unk_ovlheader_80074324");
int F4865func_80049484() __asm__("func_80049484");
void* F4865func_8002F540() __asm__("func_8002F540");
int F4865rand() __asm__("rand");
#define F4865Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int F4865func_80013E38() __asm__("func_80013E38");
int F4865func_8001830C() __asm__("func_8001830C");
int F4865func_80018368() __asm__("func_80018368");
void* F4865func_8001BA30() __asm__("func_8001BA30");
int F4865CountTimerDown() __asm__("func_800359A4");
int F4865PlayMobySoundEvent() __asm__("func_8003BABC");
int F4865func_8003BE70() __asm__("func_8003BE70");
int F4865func_8003BFC0() __asm__("func_8003BFC0");
int F4865func_8003C0B0() __asm__("func_8003C0B0");
int F4865PlanarHeadingLookup() __asm__("func_8004E880");
int F4865TransformVectorByBasis() __asm__("func_8004ED6C");
int F4865MeasureVectorLength() __asm__("func_8004EDE8");
int F4865ShiftVectorRightTowardZero() __asm__("func_8004F110");
int F4865CopyVector() __asm__("func_8004F178");
int F4865AddVector() __asm__("func_8004F194");
int F4865SubtractVector() __asm__("func_8004F1C8");
int F4865ApproximatePlanarDistance() __asm__("func_8004F334");
int F4865DeleteMoby() __asm__("func_80055B18");
int F4865RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern unsigned char F4865D_800658A0[] __asm__("D_800658A0");
extern unsigned char F4865D_80065920[] __asm__("D_80065920");
extern int F4865D_8006C574 __asm__("D_8006C574");
extern int F4865D_8006C578 __asm__("D_8006C578");
extern unsigned char F4865D_8006D048[] __asm__("D_8006D048");
extern void* F4865D_8006E788 __asm__("D_8006E788");
extern int F4865D_80071924 __asm__("D_80071924");
extern void* (*F4865SpawnMoby)() __asm__("SpawnMoby");
extern int (*F4865SpawnParticle)() __asm__("SpawnParticle");
void func_level_35_80079A70(void* arg0) {
    register void* owner __asm__("$19");
    register short* signedTable65920 __asm__("$23");
    register short* signedTable658A0 __asm__("$22");
    register short* temp_a2 __asm__("$6");
    register int tableIndex4 __asm__("$4");
    register int tableIndex5 __asm__("$5");
    register short* tablePointer2 __asm__("$2");
    register short* tablePointer4 __asm__("$4");
    register short* tablePointer5 __asm__("$5");
    int tableProduct2;
    int signedDivision180Magic;
    register int tableHalfword3 __asm__("$3");
    int temp_v0_4;
    register int previousHalfword08 __asm__("$7");
    register void* stackArg4 __asm__("$4");
    register int phaseByte3 __asm__("$3");
    register int initWord2 __asm__("$2");
    register int halfword3 __asm__("$3");
    register int result2 __asm__("$2");
    register int work3 __asm__("$3");
    register int* vector38 __asm__("$18");
    register int* savedVector28 __asm__("$16");
    register int* globalWordAddress16 __asm__("$16");
    register int previousHalfword06 __asm__("$3");
    register int updatedHalfword06 __asm__("$2");
    register int* savedOwnerVector0C __asm__("$17");
    register int* temp_s1_3 __asm__("$17");
    register int* ownerVectorArgument __asm__("$18");
    int ownerWord10;
    int temp_a0_3;
    int ownerWord0C;
    int temp_a1_3;
    register int combinedScore __asm__("$17");
    int temp_v0_5;
    int distanceScore;
    int ownerWord14;
    register int wrappedDifference08 __asm__("$6");
    register int wrappedDifference06 __asm__("$6");
    int bestScore;
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
    } frame;
    register int wrappedDifference45 __asm__("$16");
    register int upperStep __asm__("$16");
    register int scaledWord16 __asm__("$16");
    register int absoluteDistanceScore __asm__("$17");
    register int lowerStep __asm__("$17");
    register int var_s1_3 __asm__("$17");
    register int wrappedDifference46 __asm__("$18");
    register int var_s2_2 __asm__("$18");
    register int absoluteDifference08 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int absoluteDifference06 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    unsigned char ownerState48;
    register unsigned char* scanPosition __asm__("$21");
    void* temp_a0_2;
    void* linkedObject00;
    register void* privateState __asm__("$20");
    register void* ownerVector0C __asm__("$23");
    register void* queriedObject __asm__("$17");
    register void* temp_v0_2 __asm__("$16");
    register void* temp_v0_3 __asm__("$16");
    void* temp_v1_6;
    register void* scannedObject __asm__("$22");

    owner = arg0;
    ownerState48 = F4865Field(owner, unsigned char*, 0x48);
    privateState = F4865Field(owner, void**, 0);
    switch (ownerState48) {

        case 0:
            if (F4865Gate != 2)
                goto removeOwner;
            temp_v0_2 = F4865Field(owner, void**, 0);
            result2 = F4865Field(temp_v0_2, short*, 0x14);
            if (result2) {
                tableIndex4 = F4865Field(temp_v0_2, short*, 0x16);
                if (tableIndex4) {
                    work3 = F4865Position;
                    if (result2 >= work3)
                        goto outside0;
                    result2 = work3 < tableIndex4;
                    work3 = 1;
                    if (!result2)
                        goto outside0;
                    {
                        F4865Field(owner, unsigned char*, 0x41) = 0;
                        F4865Field(owner, unsigned char*, 0x4C) = 0;
                        F4865Field(owner, unsigned char*, 0x4D) = 0;
                    }
                    goto afterFlags0;
                outside0:
                    work3 = 1;
                    result2 = 63;
                    {
                        F4865Field(owner, unsigned char*, 0x41) = work3;
                        F4865Field(owner, unsigned char*, 0x4C) = result2;
                        F4865Field(owner, unsigned char*, 0x4D) = work3;
                    }
                afterFlags0:;
                }
            }
            result2 = F4865E040;
            result2 = ((int)((unsigned)result2 << 16) >> 20) - 128;
            F4865Field(owner, unsigned char*, 0x46) = result2;
            result2 = F4865E03E;
            F4865Field(owner, unsigned char*, 0x45) = (unsigned)result2 >> 4;
            {
                register unsigned char* child4 __asm__("$4");
                child4 = F4865Field(temp_v0_2, unsigned char**, 0);
                if (!child4) {
                    F4865Field(temp_v0_2, void**, 0) = F4865SpawnMoby(364, owner);
                    return;
                }
                if (child4[72] != 4) {
                    F4865Field(temp_v0_2, int*, 16) = 30;
                    F4865Field(temp_v0_2, void**, 0) = 0;
                    F4865Field(owner, unsigned char*, 72) = 6;
                    return;
                }
                child4[70] = F4865Field(owner, unsigned char*, 70) + 128;
                result2 = F4865Field(owner, unsigned char*, 69);
                work3 = (int)F4865Field(temp_v0_2, void**, 0);
                F4865Field((void*)work3, unsigned char*, 69) = -result2;
                return;
            }
        case 1:
            F4865Field(owner, unsigned char*, 76) = 0;
            F4865Field(owner, unsigned char*, 77) = 0;
            F4865CopyVector(owner + 12, F4865Player);
            return;
        case 2:
            F4865Field(owner, unsigned char*, 76) = 63;
            F4865func_80049484(owner + 12);
            result2 = F4865PlayerE;
            work3 = F4865Player12;
            F4865Field(owner, unsigned char*, 70) = result2 + work3;
            if (F4865Mode == 7) {
                result2 = F4865E03E;
                result2 = -((int)((unsigned)result2 << 16) >> 20);
                F4865Field(owner, unsigned char*, 69) = result2;
                result2 = F4865E040;
                F4865Field(owner, unsigned char*, 70) = (unsigned)result2 >> 4;
            } else
                F4865Field(owner, unsigned char*, 69) = F4865PlayerD;
            bestScore = 0x10000;
            MATCHING_KEEP(bestScore);
            scannedObject = F4865Array;
            result2 = (unsigned)scannedObject < (unsigned)F4865ArrayEnd;
            MATCHING_BARRIER("memory");
            bestScore |= 0x869F;
            F4865Field(privateState, void**, 0) = 0;
            if (result2) {
                ownerVector0C = owner + 0xC;
                scanPosition = scannedObject + 12;
                do {
                    if (!(F4865Field(scanPosition, unsigned char*, 0x3C) & 0x80) &&
                        (F4865Field(scanPosition, int*, -4) != 0)) {
                        F4865CopyVector(&frame.sp18, scanPosition);
                        frame.sp20 += 0x80;
                        wrappedDifference46 = (F4865PlanarHeadingLookup(
                                                   frame.sp18 - F4865Field(owner, int*, 0xC),
                                                   frame.sp1C - F4865Field(owner, int*, 0x10), 0) -
                                               F4865Field(owner, unsigned char*, 0x46)) &
                                              0xFF;
                        if (wrappedDifference46 >= 0x81) {
                            wrappedDifference46 -= 0x100;
                        }
                        wrappedDifference45 =
                            (F4865PlanarHeadingLookup(
                                 F4865ApproximatePlanarDistance(ownerVector0C, &frame.sp18),
                                 frame.sp20 - F4865Field(owner, int*, 0x14), 0) -
                             F4865Field(owner, unsigned char*, 0x45)) &
                            0xFF;
                        if (wrappedDifference45 >= 0x81) {
                            wrappedDifference45 -= 0x100;
                        }
                        if (wrappedDifference46 < 0) {
                            wrappedDifference46 = -wrappedDifference46;
                        }
                        if (wrappedDifference45 < 0) {
                            wrappedDifference45 = -wrappedDifference45;
                        }
                        MATCHING_KEEP(wrappedDifference46);
                        if ((wrappedDifference46 < 0x30) && (wrappedDifference45 < 0x30)) {
                            distanceScore =
                                0x2800 - F4865ApproximatePlanarDistance(ownerVector0C, &frame.sp18);
                            absoluteDistanceScore = distanceScore;
                            if (distanceScore < 0) {
                                absoluteDistanceScore = -absoluteDistanceScore;
                            }
                            result2 = (wrappedDifference46 + wrappedDifference45) << 10;
                            MATCHING_KEEP(result2);
                            combinedScore = absoluteDistanceScore + result2;
                            if ((combinedScore < bestScore) &&
                                (F4865func_80013E38(ownerVector0C, &frame.sp18, 4) != 0)) {
                                F4865Field(privateState, void**, 0) = scannedObject;
                                bestScore = combinedScore;
                            }
                        }
                    }
                    result2 = (int)F4865ArrayEnd;
                    scannedObject += 88;
                    result2 = (unsigned)scannedObject < (unsigned)result2;
                    scanPosition += 88;
                } while (result2);
            }
            if (bestScore == 0x1869F) {
                F4865Field(privateState, void**, 0) = 0;
            }
            initWord2 = F4865Field(owner, unsigned char*, 0x44) << 4;
            MATCHING_KEEP(initWord2);
            F4865Field(privateState, short*, 4) = initWord2;
            initWord2 = F4865Field(owner, unsigned char*, 0x45) << 4;
            MATCHING_KEEP(initWord2);
            F4865Field(privateState, short*, 6) = initWord2;
            phaseByte3 = F4865Field(owner, unsigned char*, 0x46);
            initWord2 = 0xB4;
            F4865Field(privateState, short*, 0xE) = initWord2;
            initWord2 = -1;
            F4865Field(privateState, int*, 0x10) = initWord2;
            MATCHING_BARRIER("memory");
            initWord2 = 3;
            F4865Field(privateState, short*, 0xA) = 0;
            F4865Field(privateState, short*, 0xC) = 0;
            F4865Field(privateState, short*, 8) = phaseByte3 << 4;
            F4865Field(owner, unsigned char*, 0x48) = initWord2;
        case 3:
            if (F4865Field(owner, int*, 12) < 1024 || F4865Field(owner, int*, 16) < 1024 ||
                F4865Field(owner, int*, 20) < 1024 ||
                ((result2 = F4865CountTimerDown(privateState + 14, 2)), (stackArg4 = &frame.sp28),
                 result2)) {
                if (F4865func_8003BFC0(owner, F4865Field(privateState, int*, 0x10)) != 0) {
                    F4865func_8003BE70(F4865Field(privateState, int*, 0x10));
                }
                goto block_93;
            }
            MATCHING_KEEP(owner);
            savedOwnerVector0C = owner + 0xC;
            F4865CopyVector(stackArg4, savedOwnerVector0C);
            if (F4865Field(F4865Field(privateState, void**, 0), unsigned char*, 0x48) & 0x80) {
                F4865Field(privateState, void**, 0) = 0;
            }
            linkedObject00 = F4865Field(privateState, void**, 0);
            if (linkedObject00 != 0) {
                F4865CopyVector(&frame.sp48, linkedObject00 + 0xC);
                frame.sp50 += 0x80;
                vector38 = &frame.sp38;
                F4865SubtractVector(vector38, &frame.sp48, savedOwnerVector0C);
                frame.sp40 += 0x100;
                F4865PlanarHeadingLookup(frame.sp38, frame.sp3C, 1);
                result2 = F4865PlanarHeadingLookup(frame.sp38, frame.sp3C, 1);
                halfword3 = F4865Field(privateState, short*, 8);
                wrappedDifference08 = (result2 - halfword3) & 0xFFF;
                previousHalfword08 = halfword3;
                if (wrappedDifference08 >= 0x801) {
                    wrappedDifference08 -= 0x1000;
                }
                absoluteDifference08 = wrappedDifference08;
                if (wrappedDifference08 < 0) {
                    absoluteDifference08 = -absoluteDifference08;
                }
                if (absoluteDifference08 < 0x400) {
                    work3 = 0xBE;
                    result2 = F4865Field(privateState, short*, 0xE);
                    upperStep = work3 - result2;
                    lowerStep = -upperStep;
                    if (upperStep >= 65) {
                        upperStep = 64;
                        MATCHING_KEEP(upperStep);
                        lowerStep = -upperStep;
                    }
                    if (wrappedDifference08 < lowerStep)
                        wrappedDifference08 = lowerStep;
                    if (upperStep < wrappedDifference08)
                        wrappedDifference08 = upperStep;
                    F4865Field(privateState, short*, 8) =
                        (short)(previousHalfword08 + wrappedDifference08);
                    result2 = F4865MeasureVectorLength(vector38, 0, wrappedDifference08,
                                                       previousHalfword08);
                    result2 = F4865PlanarHeadingLookup(result2, frame.sp40, 1);
                    previousHalfword06 = F4865Field(privateState, short*, 6);
                    wrappedDifference06 = (result2 - previousHalfword06) & 0xFFF;
                    if (wrappedDifference06 >= 0x801) {
                        wrappedDifference06 -= 0x1000;
                    }
                    absoluteDifference06 = wrappedDifference06;
                    if (wrappedDifference06 < 0) {
                        absoluteDifference06 = -absoluteDifference06;
                    }
                    if (absoluteDifference06 < 0x400) {
                        if (wrappedDifference06 < lowerStep)
                            wrappedDifference06 = lowerStep;
                        if (upperStep < wrappedDifference06)
                            wrappedDifference06 = upperStep;
                        updatedHalfword06 = previousHalfword06 + wrappedDifference06;
                        F4865Field(privateState, short*, 6) = updatedHalfword06;
                    } else {
                        goto block_63;
                    }
                } else {
                block_63:
                    F4865Field(privateState, void**, 0) = 0;
                }
            }
            F4865Field(owner, unsigned char*, 0x44) =
                (unsigned char)((unsigned short)F4865Field(privateState, unsigned short*, 4) >> 4);
            F4865Field(owner, unsigned char*, 0x45) =
                (unsigned char)((unsigned short)F4865Field(privateState, short*, 6) >> 4);
            F4865Field(owner, unsigned char*, 0x46) =
                (unsigned char)((unsigned short)F4865Field(privateState, short*, 8) >> 4);
            F4865RefreshMobySpatialGridAndBasis(owner, 4);
            frame.sp38 = 0x300;
            frame.sp3C = 0;
            frame.sp40 = 0;
            F4865TransformVectorByBasis(owner + 0x20, &frame.sp38, &frame.sp38);
            ownerVectorArgument = owner + 0xC;
            F4865AddVector(ownerVectorArgument, ownerVectorArgument, &frame.sp38);
            savedVector28 = &frame.sp28;
            if (F4865func_8001830C(savedVector28, ownerVectorArgument, 0, 0x10000, owner) != 0) {
                F4865CopyVector(ownerVectorArgument, savedVector28);
                goto block_71;
            }
            queriedObject = F4865func_8001BA30(ownerVectorArgument, 0x200, 1, 0, 0, owner);
            if (queriedObject != 0) {
                F4865CopyVector(&frame.sp58, queriedObject + 0xC);
                frame.sp60 += 0x80;
                if (F4865func_80018368(ownerVectorArgument, &frame.sp58) == 0) {
                    F4865Field(queriedObject, int*, 0x18) =
                        (int)(F4865Field(queriedObject, int*, 0x18) | 0x10000);
                block_71:
                    F4865Field(owner, unsigned char*, 0x48) = 5U;
                }
            }
            if (F4865func_8003BFC0(owner, F4865Field(privateState, int*, 0x10)) == 0) {
                F4865Field(privateState, int*, 0x10) = F4865PlayMobySoundEvent(owner, 0, 4);
            } else {
                /* Keep the original division constant before the signed load. */
                signedDivision180Magic = (int)0xB60B60B7;
                __asm__("" : "=r"(privateState) : "0"(privateState), "r"(signedDivision180Magic));
                halfword3 = F4865Field(privateState, short*, 0xE);
                result2 = (int)((unsigned int)(0xB4 - halfword3) << 13);
                work3 = result2 / 180;
                MATCHING_KEEP(work3);
                result2 = 0x1000;
                MATCHING_KEEP(result2);
                scaledWord16 = result2 - work3;
                if (scaledWord16 < 0xA00) {
                    scaledWord16 = 0xA00;
                }
                F4865func_8003C0B0(F4865Field(privateState, int*, 0x10), scaledWord16);
            }
            F4865ShiftVectorRightTowardZero(&frame.sp38, 2);
            F4865SpawnParticle(1, 0x37, owner + 0xC, &frame.sp38);
            return;

        case 4:
            result2 = F4865Field(owner, unsigned char*, 58);
            work3 = result2 * 88;
            result2 = (int)F4865Array;
            result2 += work3;
            MATCHING_KEEP(result2);
            result2 = F4865Field((void*)result2, unsigned char*, 76);
            globalWordAddress16 = &frame.sp68;
            if (result2) {
                stackArg4 = globalWordAddress16;
                MATCHING_KEEP(stackArg4);
                temp_s1_3 = (int*)F4865Player;
                F4865Field(owner, unsigned char*, 76) = result2;
                F4865SubtractVector(stackArg4, temp_s1_3, owner + 12);
                F4865MeasureVectorLength(globalWordAddress16, 1);
                if (F4865W20C & 0x10000000)
                    return;
                if (F4865W170)
                    return;
                if (!F4865CallbackA0(owner, temp_s1_3, 1536))
                    return;
                F4865PlayMobySoundEvent(owner, 2, 0);
                result2 = 0x10001000;
                F4865W20C = result2;
                result2 = 1;
                F4865W218 = owner;
                F4865Field(owner, unsigned char*, 72) = result2;
                return;
            }
        idle6:
            MATCHING_BARRIER_VOLATILE("memory");
            F4865Field(owner, unsigned char*, 65) = 0;
            F4865Field(owner, unsigned char*, 76) = 0;
            F4865Field(owner, unsigned char*, 77) = 0;
            return;
        case 5:
            temp_s1_3 = owner + 12;
            temp_v0_2 = F4865func_8001BA30(temp_s1_3, 1024, 1, 0, 0, owner);
            if (temp_v0_2 && !F4865func_80018368(temp_s1_3, temp_v0_2 + 12))
                F4865Field(temp_v0_2, int*, 24) |= 0x10000;
            if (F4865func_8003BFC0(owner, F4865Field(privateState, int*, 16)))
                F4865func_8003BE70(F4865Field(privateState, int*, 16));
            F4865PlayMobySoundEvent(owner, 1, 0);
            F4865Callback24(owner, -1);
        removeOwner:
            F4865DeleteMoby(owner);
            return;
        case 6:
            temp_v0_2 = F4865Field(owner, void**, 0);
            result2 = F4865E040;
            result2 = ((int)((unsigned)result2 << 16) >> 20) - 128;
            F4865Field(owner, unsigned char*, 70) = result2;
            result2 = F4865E03E;
            F4865Field(owner, unsigned char*, 69) = (unsigned)result2 >> 4;
            if (F4865CountTimerDown(temp_v0_2 + 16, 4)) {
                var_s1_3 = 0;
                stackArg4 = temp_v0_2;
                MATCHING_KEEP(stackArg4);
                do {
                    F4865Field(F4865Field(stackArg4, void**, 4), unsigned char*, 28) = 0;
                    F4865Field(stackArg4, void**, 4) = 0;
                    var_s1_3++;
                    stackArg4 += 4;
                } while (var_s1_3 < 3);
                F4865Field(owner, unsigned char*, 72) = 0;
                return;
            }
            var_s2_2 = F4865rand() & 255;
            privateState = F4865D_80065920;
            var_s1_3 = 0;
            do {
                if (!F4865Field(temp_v0_2, void**, 4)) {
                    result2 = (int)F4865func_8002F540(4, 1, 0x608080);
                    MATCHING_KEEP(result2);
                    F4865Field(temp_v0_2, void**, 4) = (void*)result2;
                    if (!result2)
                        goto angleIncrement;
                    {
                        F4865Field((void*)result2, int*, 0) = 0;
                        tableIndex4 = var_s2_2 * 2;
                        tablePointer2 = (short*)((long)tableIndex4 + (long)privateState);
                        tableHalfword3 = *tablePointer2;
                        MATCHING_KEEP(tableHalfword3);
                        result2 = tableHalfword3 * 3;
                        MATCHING_KEEP(result2);
                        work3 = (int)F4865Field(temp_v0_2, void**, 4);
                        result2 >>= 3;
                        F4865Field((void*)work3, int*, 4) = result2;
                        tableHalfword3 = F4865Field(F4865D_800658A0 + tableIndex4, short*, 0);
                        MATCHING_KEEP(tableHalfword3);
                        result2 = tableHalfword3 * 3;
                        MATCHING_KEEP(result2);
                        work3 = (int)F4865Field(temp_v0_2, void**, 4);
                        result2 >>= 3;
                        F4865Field((void*)work3, int*, 8) = result2;
                        linkedObject00 = F4865Field(temp_v0_2, void**, 4);
                        F4865TransformVectorByBasis(owner + 32, linkedObject00, linkedObject00);
                        stackArg4 = F4865Field(temp_v0_2, void**, 4);
                        F4865AddVector(stackArg4, stackArg4, owner + 12);
                    }
                }
                if (F4865Field(temp_v0_2, void**, 4))
                    F4865CopyVector(F4865Field(temp_v0_2, unsigned char**, 4) + 12, F4865Player);
            angleIncrement:
                result2 = var_s2_2 + 85;
                MATCHING_KEEP(result2);
                var_s2_2 = result2 & 255;
                var_s1_3++;
                temp_v0_2 += 4;
            } while (var_s1_3 < 3);
    }
    return;
block_93:
    goto removeOwner;
}
#undef F4865Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
INCLUDE_RODATA("asm/nonmatchings/overlays/level_35/moby", D_level_35_800745C4);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original-derived C.
 * Source: asm/nonmatchings/overlays/level_35/moby/func_level_35_8007A540.s; SHA256 eb66ef406e8adcc92050bce78051bf123661ae515e959f67efbfd64c9cfc859c.
 * Complete original trace/table: build/sibling6098.func_level_35_8007A540.json.
 * Reuses accepted controller45 C; every changed raw offset, selector, signed
 * trig operation, helper/callback call and global/field producer is separately
 * established by original35 instructions. Only empty compiler constraints.
 * Units/fixed-point meanings and helper/global consumer chains remain
 * unresolved; invocation cadence only, frame rate/runtime parity unproven.
 * Early55B18 call preserves the inherited original argument4 producer.
 * Falsification: native/linked instruction and selector words, every branch
 * target and full original executable/all overlay hashes.
 */
#define ControllerField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int ControllerA540_func_800135A4() __asm__("func_800135A4");
int ControllerA540_func_80013D44() __asm__("func_80013D44");
int ControllerA540_func_8001A358() __asm__("func_8001A358");
int ControllerA540SetMobyAnimation() __asm__("func_80034F80");
int ControllerA540_func_80037BBC() __asm__("func_80037BBC");
int ControllerA540_func_8003B74C() __asm__("func_8003B74C");
int ControllerA540_func_8003B7B4() __asm__("func_8003B7B4");
int ControllerA540_func_800498C0() __asm__("func_800498C0");
int ControllerA540SubtractVector() __asm__("func_8004F1C8");
int ControllerA540_func_800512E4() __asm__("func_800512E4");
int ControllerA540RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int ControllerA540_func_80056270() __asm__("func_80056270");
int ControllerA540_func_8005629C() __asm__("func_8005629C");
extern unsigned char ControllerA540_D_800658A0 __asm__("D_800658A0");
extern unsigned char ControllerA540_D_80065920 __asm__("D_80065920");
extern unsigned char ControllerA540_D_80068F7C __asm__("D_80068F7C");
extern unsigned char ControllerA540_D_80068F90 __asm__("D_80068F90");
extern int ControllerA540_D_8006C598 __asm__("D_8006C598");
extern int ControllerA540_D_8006C6D0 __asm__("D_8006C6D0");
extern unsigned char ControllerA540_D_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char ControllerA540_D_8006C7F8 __asm__("D_8006C7F8");
extern unsigned char ControllerA540_D_8006D088 __asm__("D_8006D088");
extern int ControllerA540_D_8006E344 __asm__("D_8006E344");
extern int ControllerA540_D_8006FA40 __asm__("D_8006FA40");
extern int ControllerA540_D_8006FA50 __asm__("D_8006FA50");
extern int ControllerA540_D_8006FA54 __asm__("D_8006FA54");
extern unsigned char ControllerA540_D_80070328 __asm__("D_80070328");
extern unsigned char ControllerA540_D_800719A8 __asm__("D_800719A8");
extern unsigned char ControllerA540_D_800719F0 __asm__("D_800719F0");

extern unsigned char ReloadA540D088 __asm__("D_8006D088");
extern unsigned char ControllerA540_D_8007159A __asm__("D_8007159A");
extern int ControllerA540_D_8006E048 __asm__("D_8006E048");
extern char ControllerA540Message[] __asm__("D_level_35_800745C4");
int ControllerA540_func_8005F5FC() __asm__("func_8005F5FC");
int ControllerA540DeleteMoby() __asm__("func_80055B18");
extern Moby* (*ControllerA540Spawn)() __asm__("SpawnMoby");
void func_level_35_8007A540(Moby* input_arg0) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        char pad_1c[4];
        int sp20;
        int sp24;
        int sp28;
        char pad_2c[4];
    } originalStack;

    register Moby* owner __asm__("$20") = input_arg0;

    register Vector3D* temp_a2 __asm__("$6");
    register int* global19 __asm__("$19");
    register int* global17 __asm__("$17");
    register unsigned char* table18 __asm__("$18");
    register unsigned char* table17 __asm__("$17");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int call7 __asm__("$7");
    register Vector3D* positionField16 __asm__("$16");
    register Vector3D* yField16 __asm__("$16");
    register Vector3D* zField16 __asm__("$16");
    register Vector3D* angleField16 __asm__("$16");
    int animationArgument;
    register unsigned char* stateField16a __asm__("$16");
    register unsigned char* stateField16b __asm__("$16");
    register unsigned char* stateField16c __asm__("$16");
    register unsigned int state3 __asm__("$3");
    register int substate3 __asm__("$3");
    unsigned char animationByte;
    register void* privateData __asm__("$21");

    value2 = ControllerA540_D_8007159A;
    privateData = owner->mobyTag;
    if (value2) {
        ControllerA540DeleteMoby();
        goto returned;
    }
    owner->updateDistance = 0xFF;
    if (ControllerField(privateData, int*, 0x44) == -1) {
        ControllerA540_func_8005F5FC(ControllerA540Message);
        ControllerA540DeleteMoby(owner);
    }
    ControllerA540_func_8001A358(&owner->position, 0x2710);
    ControllerA540_func_80056270(owner);
    ControllerA540_func_8005629C(owner);
    ControllerA540RefreshMobySpatialGridAndBasis(owner, 6);
    state3 = owner->state;
    switch (state3) {
        case 0:
            owner->distanceToGround = 0;
            ControllerField(privateData, signed char*, 5) = 1;
            if ((ControllerA540_D_8006C598 == 0) && (ControllerA540_func_80037BBC(owner, 0) != 0)) {
                ControllerA540_func_800512E4(owner, 0, 1);
                owner->state = 1;
            }
            goto finished;
        case 1:
            if (ControllerA540_D_8006E344 != 1) {
                if (ControllerField(privateData, unsigned char*, 4) == 2) {
                    value2 = 0x10000002;
                    MATCHING_KEEP(value2);
                    positionField16 = privateData + 0x38;
                    ControllerField(&ControllerA540_D_80070328, int*, 0x20C) = value2;
                    global19 = &ControllerA540_D_8006FA40;
                    *global19 = 3;
                    owner->state = 2;
                    func_8004F178(positionField16, &owner->position);
                    ControllerField(privateData, int*, 0x34) = (int)owner->angle.yaw;
                    ControllerA540_func_8003B7B4(positionField16, 4, &ControllerA540_D_8006D088);
                    ControllerA540_func_8003B7B4(positionField16, 4, &ControllerA540_D_8006C7F8);
                    yField16 = privateData + 0x3C;
                    ControllerA540_func_8003B7B4(yField16, 4, &ControllerA540_D_8006D088);
                    ControllerA540_func_8003B7B4(yField16, 4, &ControllerA540_D_8006C7F8);
                    zField16 = privateData + 0x40;
                    ControllerA540_func_8003B7B4(zField16, 4, &ControllerA540_D_8006D088);
                    ControllerA540_func_8003B7B4(zField16, 4, &ControllerA540_D_8006C7F8);
                    angleField16 = privateData + 0x34;
                    ControllerA540_func_8003B7B4(angleField16, 4, &ControllerA540_D_8006D088);
                    ControllerA540_func_8003B7B4(angleField16, 4, &ControllerA540_D_8006C7F8);
                    func_8004F178((Vector3D*)((unsigned char*)global19 + 8),
                                  ControllerField(ControllerField(privateData, void**, 0x24),
                                                  Vector3D**, 0xC));
                    ControllerA540_D_8006FA50 += 512;
                    temp_a2 = ControllerField(ControllerField(privateData, void**, 0x24),
                                              Vector3D**, 0xC);
                    ControllerA540SubtractVector(
                        &originalStack.sp10, (Vector3D*)((unsigned char*)temp_a2 + 0x10), temp_a2);
                    value2 = func_8004E880(originalStack.sp10, originalStack.sp14, 0);
                    ControllerA540_D_8006FA54 = value2;
                    ControllerField(ControllerField(privateData, void**, 0x24), short*, 2) = 1;
                    ControllerA540_func_8003B7B4(ControllerField(privateData, void**, 0x24) + 2, 2,
                                                 &ControllerA540_D_8006D088);
                    ControllerA540_func_8003B7B4(ControllerField(privateData, void**, 0x24) + 2, 2,
                                                 &ControllerA540_D_8006C7F8);
                    stateField16a = &owner->state;
                    ControllerA540_func_8003B7B4((Vector3D*)stateField16a, 1,
                                                 &ControllerA540_D_8006D088);
                    ControllerA540_func_8003B7B4((Vector3D*)stateField16a, 1,
                                                 &ControllerA540_D_8006C7F8);
                }
                call4 = (int)&ReloadA540D088;
                MATCHING_KEEP(call4);
                goto block_24;
            }
            goto finished;
        case 2:
            substate3 = ControllerField(owner, volatile unsigned char*, 0x49);
            value2 = 1;
            if (substate3 == value2)
                goto substate1;
            if (substate3 < 2) {
                stateField16b = &owner->state;
                if (substate3 == 0)
                    goto substate0;
                goto finished;
            }
            if (substate3 == 2)
                goto substate2;
            goto finished;
        substate0:
            owner->state = 0;
            ControllerA540_func_8003B7B4((Vector3D*)stateField16b, 1, &ControllerA540_D_8006D088);
            ControllerA540_func_8003B7B4((Vector3D*)stateField16b, 1, &ControllerA540_D_8006C7F8);
            owner->state = 2;
            owner->substate = 1;

            goto finished;
        substate1:
            value2 = ControllerField(privateData, int*, 0x28);
            if (value2 == 0) {
                value2 = (int)ControllerA540Spawn(0x143, owner);
                ControllerField(privateData, int*, 0x28) = value2;
            }
        sharedHeader:
            owner->unknownCollision = 0;
            owner->distanceToGround = 0x200;
            ((void (*)(Moby*, int))unk_ovlheader_80074318)(owner, 0xA5);
            ControllerA540_D_8006C6D0 = 0;
            ControllerA540_func_800135A4(&ControllerA540_D_800719A8, &ControllerA540_D_80068F7C, 0);
            ControllerA540_func_800135A4(&ControllerA540_D_800719F0, &ControllerA540_D_80068F90, 0);
            if (ControllerField(&ControllerA540_D_80070328, int*, 0x24C) == 9) {
                animationByte = owner->animationState.nextId;
                animationArgument = ControllerField(&ControllerA540_D_80070328, int*, 0x48) - 0xA3;
                if (animationArgument != animationByte) {
                    if (animationByte < 2U) {
                        goto syncImmediate;
                    } else {
                        goto syncDeferred;
                    }
                }
            }
            goto finished;

        substate2:
            ControllerField(&ControllerA540_D_80070328, int*, 0x20C) = 0x10000002;
            owner->state = 5;
            originalStack.sp10 =
                (int)(ControllerField(&ControllerA540_D_80065920, short*,
                                      (ControllerField(privateData, int*, 0x34) * 2)) *
                      0x27) >>
                6;

            originalStack.sp14 =
                (int)(ControllerField(&ControllerA540_D_800658A0, short*,
                                      (ControllerField(privateData, int*, 0x34) * 2)) *
                      0x27) >>
                6;
            originalStack.sp18 = 0;
            func_8004F194((Vector3D*)&originalStack.sp10, (Vector3D*)&originalStack.sp10,
                          privateData + 0x38);
            ControllerA540_func_80013D44(&originalStack.sp10,
                                         (ControllerField(privateData, int*, 0x34) + 0x80) & 0xFF,
                                         0, 0);
            goto finished;

            goto finished;
        case 3:
            ControllerField(&ControllerA540_D_80070328, int*, 0x20C) = 0x10000002;
            goto finished;
        case 4:
            substate3 = owner->substate;
            if (substate3 == 0)
                goto sharedHeader;
            if (substate3 != 1)
                goto state4Camera;
            owner->unknownCollision = 0;
            owner->distanceToGround = 512;
            ((void (*)(Moby*, int))unk_ovlheader_80074318)(owner, 165);
            if (ControllerField(&ControllerA540_D_80070328, int*, 0x24C) == 9) {
                animationByte = owner->animationState.nextId;
                animationArgument = ControllerField(&ControllerA540_D_80070328, int*, 0x48) - 163;
                if (animationArgument != animationByte) {
                    if (animationByte < 2) {
                    syncImmediate:
                        ControllerA540SetMobyAnimation(owner, animationArgument);
                        goto finished;
                    }
                syncDeferred:
                    func_80034F40(owner, animationArgument);
                    goto finished;
                }
            }
            goto finished;
        state4Camera:
            value2 = 0x10000002;
            MATCHING_KEEP(value2);
            stateField16c = &owner->state;
            call4 = (int)stateField16c;
            call5 = 1;
            table18 = &ControllerA540_D_8006D088;
            temp_a2 = (Vector3D*)table18;
            MATCHING_KEEP4(call4, call5, temp_a2, table18);
            global17 = &ControllerA540_D_8006FA40;
            __asm__("" : "=r"(global17) : "0"(global17), "r"(value2));
            ControllerField(&ControllerA540_D_80070328, int*, 0x20C) = value2;
            value2 = 1;
            MATCHING_KEEP(value2);
            *global17 = value2;
            owner->state = 0;
            ControllerA540_func_8003B7B4(call4, call5, temp_a2);
            ControllerA540_func_8003B7B4((Vector3D*)stateField16c, 1, &ControllerA540_D_8006C7F8);
            originalStack.sp20 =
                (int)(ControllerField(&ControllerA540_D_80065920, short*,
                                      (ControllerField(privateData, int*, 0x34) * 2)) *
                      0xD) >>
                5;

            originalStack.sp24 =
                (int)(ControllerField(&ControllerA540_D_800658A0, short*,
                                      (ControllerField(privateData, int*, 0x34) * 2)) *
                      0xD) >>
                5;
            originalStack.sp28 = 0;
            func_8004F194((Vector3D*)((unsigned char*)global17 + 8), (Vector3D*)&originalStack.sp20,
                          privateData + 0x38);
            ControllerA540_D_8006FA50 += 0x100;
            value2 = ControllerField(privateData, int*, 0x34);
            call4 = (int)table18;
            ControllerA540_D_8006FA54 = (value2 + 0x80) & 0xFF;
        block_24:
            ControllerA540_func_8003B74C(call4);
            owner->state = 3;
            goto finished;

        case 5:
            if (owner->animationState.nextId >= 2 && ControllerA540_D_8006E048 == 1) {
                ControllerA540SetMobyAnimation(owner, 0);
            }
            func_8004F178(&owner->position, privateData + 0x38);
            owner->angle.roll = 0;
            owner->angle.pitch = 0;
            value2 = ControllerField(privateData, int*, 0x34);
            owner->distanceToGround = 0;
            owner->angle.yaw = value2;
            ControllerField(privateData, signed char*, 5) = 1;
            if ((ControllerA540_D_8006C598 == 0) && (ControllerA540_func_80037BBC(owner, 0) != 0)) {
                ControllerField(privateData, signed char*, 2) = 4;
                ControllerA540_D_8006C7B4 |= 4;
                ControllerA540_func_800512E4(owner, 0, 1);
                owner->state = 6;
            }
            goto finished;
        case 6:
            if (ControllerA540_D_8006E344 == 1)
                goto finished;
            ControllerA540_func_800498C0();
            break;
    }
finished:
    func_80035D38(owner);
    ControllerA540_func_8005629C(owner);
returned:;
}
#undef ControllerField

extern int D_8006FA3C, D_8006FA78, D_8006C640;
void func_level_35_8007ACA4(Moby* actor) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 func_level_35_8007AE8C; original assembly SHA256
 * c407916f06c9f5b8623fb5df8c3e99e83645899a2e838d0e9efbb11a5632fff6. AI generated; not human
 * reviewed. Reuses the independently matched1182 family source, with target-specific native
 * branches, field widths, stack homes, helper arguments and table entries separately verified. 1242
 * native instructions; 6 selectors; 0 zero padding words. Frame 128 bytes. Descriptor
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
int Family1242H35194() __asm__("func_80035194");
int Family1242TurnMobyTowardPlayer() __asm__("func_8003573C");
int Family1242H369B8() __asm__("func_800369B8");
int Family1242H38F14() __asm__("func_80038F14");
int Family1242H3BA00() __asm__("func_8003BA00");
extern int Family1242Tick __asm__("D_8006C640");
int Family1242TestSlot(void*, int) __asm__("func_8003BFC0");
void Family1242ClearSlot(int) __asm__("func_8003BE70");
extern int (*Family1242SpawnMoby)() __asm__("SpawnMoby");
#define Family1242Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Family1242_func_80019194() __asm__("func_80019194");
int Family1242CountTimerDown(void*, int) __asm__("func_800359A4");
int Family1242GetClosestPathNodeByVectorLength(void*, void*, void*) __asm__("func_80036518");
int Family1242_func_80036A68() __asm__("func_80036A68");
int Family1242PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Family1242_func_8004E4E4(int) __asm__("func_8004E4E4");
int Family1242TransformVectorByBasis() __asm__("func_8004ED6C");
int Family1242ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Family1242DeleteMoby() __asm__("func_80055B18");
int Family1242RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Family1242InterpolateMobyVertex() __asm__("func_80055F14");
int Family1242_rand() __asm__("rand");
extern int Family1242_D_80065920 __asm__("D_80065920");
extern int Family1242_D_8006C550 __asm__("D_8006C550");
extern int Family1242_D_8006C648 __asm__("D_8006C648");
extern int Family1242_D_8006C730 __asm__("D_8006C730");
extern int Family1242_D_8006C770 __asm__("D_8006C770");
extern int Family1242_D_8006C7C4 __asm__("D_8006C7C4");
extern int Family1242_D_8006E020 __asm__("D_8006E020");
extern int Family1242_D_8006FA3C __asm__("D_8006FA3C");
extern int Family1242_D_8006FA78 __asm__("D_8006FA78");
extern int Family1242_D_8006FA7C __asm__("D_8006FA7C");
extern int Family1242_D_8006FA80 __asm__("D_8006FA80");
extern int Family1242_D_80070328 __asm__("D_80070328");
extern int (*Family1242_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Family1242_unk_ovlheader_80074384)() __asm__("unk_ovlheader_80074384");
extern int (*Family1242_unk_ovlheader_80074398)() __asm__("unk_ovlheader_80074398");
extern int (*Family1242_unk_ovlheader_8007439C)() __asm__("unk_ovlheader_8007439C");
extern int (*Family1242_unk_ovlheader_800743A0)() __asm__("unk_ovlheader_800743A0");
extern int (*Family1242_unk_ovlheader_800743A4)() __asm__("unk_ovlheader_800743A4");
extern int (*Family1242_unk_ovlheader_800743EC)() __asm__("unk_ovlheader_800743EC");
void func_level_35_8007AE8C(void* input) {
    register int ownerRecord20 __asm__("$20"), privateRecord18 __asm__("$18"),
        retainedFactorCounterOrVector16 __asm__("$16"), retainedPathOrAngle17 __asm__("$17"),
        retainedVectorOrAngle19 __asm__("$19"), retainedRemainderMinimum21 __asm__("$21"),
        retainedRemainderMinimum22 __asm__("$22");
    int finalProductLow;
    long long completeFinalProduct, completeSpeedProduct, completeDivisionProduct;
    int speedProductLow, divisionProductHigh;
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        rawWord8 __asm__("$8"), rawWord9 __asm__("$9");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C;
    } originalFrame;
    int signedRemainder;
    ownerRecord20 = (int)input;
    MATCHING_KEEP(ownerRecord20);
    privateRecord18 = Family1242Field(ownerRecord20, void**, 0);
    __asm__(""
            : "=r"(retainedRemainderMinimum21), "=r"(retainedRemainderMinimum22),
              "=m"(originalFrame.sp18));

    if (Family1242Field(privateRecord18, int*, 0) != 0) {
        if (Family1242_D_8006C7C4 == 2) {
            retainedFactorCounterOrVector16 = 0x9E8;
        } else {
            retainedFactorCounterOrVector16 = 0x380;
            if (Family1242_D_8006C7C4 == 1) {
                retainedFactorCounterOrVector16 = 0x600;
            }
        }
        if ((Family1242Field(ownerRecord20, int*, 0x18) != 0) &&
            (Family1242Field(ownerRecord20, unsigned char*, 0x48) != 5)) {
            if (Family1242TestSlot(ownerRecord20, Family1242Field(privateRecord18, int*, 4)))
                Family1242ClearSlot(Family1242Field(privateRecord18, int*, 4));
            Family1242Field(privateRecord18, int*, 4) = -1;
            Family1242PlayMobySoundEvent(ownerRecord20, 1, 0);
            Family1242Field(privateRecord18, short*, 0x40) = 0xF0;
            Family1242Field(ownerRecord20, unsigned char*, 0x48) = 5U;
        }
        argumentWord5 = Family1242Field(privateRecord18, short**, 0x14);
        if (argumentWord5 != 0) {
            retainedRemainderMinimum22 = 5;
            rawWord8 = Family1242_D_8006C550;
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
            rawWord2 = Family1242Field(argumentWord5, short*, 2);
            rawWord9 = rawWord3 >> 3;
            originalFrame.sp18 = rawWord2;
            rawWord2 = Family1242Field(ownerRecord20, unsigned char*, 0x43);
            rawWord3 = Family1242_D_8006C730;
            argumentWord7 = Family1242Field(rawWord3, int*, rawWord2 * 4);
            do {
                rawWord2 = Family1242Field(argumentWord7, unsigned short*, 0);
                rawWord3 = rawWord2 & 0x7fff;
                MATCHING_KEEP(rawWord3);
                if (rawWord9 != rawWord3) {
                    rawWord2 = rawWord3 * 88;
                    rawWord2 = rawWord2 + rawWord8;
                    argumentWord6 = Family1242Field(rawWord2, int*, 0);
                    argumentWord4 = Family1242Field(privateRecord18, int*, 0x14);
                    rawWord3 = Family1242Field(argumentWord6, int*, 0x14);
                    rawWord2 = Family1242Field(argumentWord4, short*, 2);
                    rawWord3 = Family1242Field(rawWord3, short*, 2);
                    argumentWord5 = Family1242Field(argumentWord4, short*, 0);
                    rawWord2 = rawWord2 - rawWord3;
                    rawWord2 = rawWord2 + argumentWord5;
                    argumentWord4 = rawWord2 % argumentWord5;
                    if (argumentWord4 == 0) {
                        rawWord3 = Family1242Field(argumentWord6, int*, 0x58);
                        rawWord2 = Family1242Field(privateRecord18, int*, 0x58);
                        if (rawWord2 < rawWord3) {
                            argumentWord4 = argumentWord5;
                            MATCHING_KEEP(argumentWord4);
                        }
                    }
                    rawWord2 = argumentWord4 < retainedRemainderMinimum22;
                    if (rawWord2)
                        retainedRemainderMinimum22 = argumentWord4;
                    rawWord2 = Family1242Field(privateRecord18, int*, 0x14);
                    rawWord2 = Family1242Field(rawWord2, short*, 0);
                    argumentWord4 = rawWord2 - argumentWord4;
                    if (argumentWord4 < retainedRemainderMinimum21)
                        retainedRemainderMinimum21 = argumentWord4;
                }
                rawWord2 = Family1242Field(argumentWord7, short*, 0);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord7, "memory");
                argumentWord7 += 2;
            } while (rawWord2 >= 0);
        }
        switch (Family1242Field(ownerRecord20, unsigned char*, 0x48)) {
            case 0:
                if (Family1242Field(privateRecord18, int*, 0x0) != 0) {
                    if (Family1242_D_8006FA3C == 2) {
                        rawWord3 = Family1242Field(privateRecord18, void***, 0x8);
                        if ((*(int*)rawWord3) == 0) {
                            (*(int*)rawWord3) = ownerRecord20;
                            Family1242GetClosestPathNodeByVectorLength(
                                Family1242_D_8006C550 +
                                    (Family1242Field(privateRecord18, int*, 0x50) * 0x58) + 0xC,
                                Family1242Field(privateRecord18, short**, 0xC),
                                Family1242Field(privateRecord18, int**, 0x54));
                            Family1242_D_8006FA80 = -2;
                        }
                        rawWord2 = Family1242Field(ownerRecord20, unsigned char*, 0x44);
                        rawWord2 *= 16;
                        Family1242Field(privateRecord18, int*, 0x20) = rawWord2;
                        __asm__ volatile("" ::"m"(Family1242Field(privateRecord18, int*, 0x20))
                                         : "memory");
                        rawWord2 = Family1242Field(ownerRecord20, unsigned char*, 0x45);
                        argumentWord4 = Family1242Field(privateRecord18, int*, 0xC);
                        rawWord2 *= 16;
                        Family1242Field(privateRecord18, int*, 0x24) = rawWord2;
                        rawWord3 = Family1242Field(ownerRecord20, unsigned char*, 0x46);
                        __asm__ volatile("" ::: "$2", "memory");
                        rawWord2 = Family1242Field(privateRecord18, int*, 0x58);
                        Family1242Field(privateRecord18, int*, 0x14) = argumentWord4;
                        rawWord2 = rawWord2 * 32 + 128;
                        rawWord3 *= 16;
                        Family1242Field(privateRecord18, int*, 0x18) = rawWord2;
                        Family1242Field(privateRecord18, int*, 0x28) = rawWord3;
                        goto initializeOriginalPath;
                    }
                    goto deleteOriginalActor;
                }
                if ((unsigned int)(Family1242_D_8006FA3C - 2) >= 2U) {
                initializeOriginalPath:
                    Family1242Field(Family1242Field(privateRecord18, short**, 0x14), short*, 0xA) =
                        1;
                    Family1242GetClosestPathNodeByVectorLength(
                        ownerRecord20 + 0xC, Family1242Field(privateRecord18, short**, 0x14),
                        &originalFrame.sp18);
                    Family1242Field(Family1242Field(privateRecord18, short**, 0x14), short*, 2) =
                        (short)originalFrame.sp18;
                    argumentWord4 = Family1242Field(privateRecord18, short**, 0x14);
                    rawWord3 = Family1242Field(argumentWord4, short*, 0);
                    Family1242Field(argumentWord4, short*, 2) =
                        (short)((int)(Family1242Field(argumentWord4, short*, 2) +
                                      Family1242Field(argumentWord4, short*, 0xA) + rawWord3) %
                                rawWord3);
                    argumentWord5 = 0x7fffffff;
                    rawWord3 = Family1242Field(privateRecord18, int*, 0x58);
                    rawWord2 = Family1242Field(privateRecord18, int*, 0x5C);
                    rawWord3 = rawWord3 * 4 + rawWord2;
                    rawWord2 = Family1242Field(ownerRecord20, int*, 0x1C);
                    rawWord3 = Family1242Field(rawWord3, int*, 0);
                    rawWord2 &= argumentWord5;
                    Family1242Field(ownerRecord20, int*, 0x1C) = rawWord2;
                    rawWord2 = 1;
                    Family1242Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
                    Family1242Field(ownerRecord20, int*, 0x54) = rawWord3;
                    Family1242Field(ownerRecord20, signed char*, 0x57) = 0;
                } else
                    goto deleteOriginalActor;
            default:
                goto processOriginalCommonPath;
            case 1:
                if (!Family1242TestSlot(ownerRecord20, Family1242Field(privateRecord18, int*, 4)))
                    Family1242Field(privateRecord18, int*, 4) =
                        Family1242PlayMobySoundEvent(ownerRecord20, 0, 4);
                if (Family1242Field(privateRecord18, int*, 0x0) != 0) {
                    Family1242Field(privateRecord18, int*, 0x1C) = Family1242_func_8004E4E4(
                        Family1242Field(ownerRecord20, int*, 0x14) -
                        ((int)((retainedFactorCounterOrVector16 *
                                (Family1242Field(privateRecord18, int*, 0x58) + 2))
                               << 0xE) >>
                         0x10) +
                        3584);
                    rawWord2 = Family1242ApproximatePlanarDistance(ownerRecord20 + 12,
                                                                   (int)&Family1242_D_8006E020);
                    rawWord2 = rawWord2 < 2048;
                    if (rawWord2) {
                        rawWord2 = Family1242Field(privateRecord18, int*, 0x1C);
                        rawWord2 -= 2048;
                        Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                    }
                    rawWord2 = retainedRemainderMinimum21 < 5;
                    if (rawWord2) {
                        rawWord2 = Family1242Field(privateRecord18, int*, 0x1C);
                        rawWord2 -= 1024;
                        Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                    }
                    rawWord3 = Family1242Field(privateRecord18, int*, 0x1C);
                    rawWord2 = Family1242_D_8006C648;
                    completeSpeedProduct = (long long)(int)rawWord3 * (int)rawWord2;
                    argumentWord4 = ownerRecord20;
                    argumentWord6 = privateRecord18 + 0x1C;
                    argumentWord5 = Family1242Field(privateRecord18, int*, 0x14);
                    rawWord3 = (int)Family1242_unk_ovlheader_80074398;
                    __asm__(""
                            : "=l"(speedProductLow)
                            : "x"(completeSpeedProduct), "r"(rawWord3), "r"(argumentWord6));
                    rawWord2 = speedProductLow >> 6;
                    Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                    ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6);
                    rawWord2 = Family1242_D_8006C730;
                    __asm__ volatile("" ::: "$19", "memory");
                    retainedVectorOrAngle19 = (int)&originalFrame.sp20;
                    retainedPathOrAngle17 = Family1242Field(rawWord2, int*, 4);
                scanOriginalLinkedEntry:
                    rawWord3 = Family1242Field(retainedPathOrAngle17, unsigned short*, 0);
                    rawWord3 &= 0x7fff;
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = rawWord3 * 88;
                    rawWord3 = Family1242_D_8006C550;
                    retainedFactorCounterOrVector16 = rawWord3 + rawWord2;
                    if (Family1242_unk_ovlheader_800743A0(retainedFactorCounterOrVector16,
                                                          ownerRecord20 + 0xC, 0x400) != 0) {
                        Family1242PlayMobySoundEvent(retainedFactorCounterOrVector16, 1, 0);
                        retainedFactorCounterOrVector16 = 0;
                        argumentWord4 = ownerRecord20 + 0x20;
                        do {
                            argumentWord5 = retainedVectorOrAngle19;
                            rawWord2 = Family1242Field(privateRecord18, int*, 0x1C);
                            __asm__ volatile("" ::: "$6", "memory");
                            argumentWord6 = retainedVectorOrAngle19;
                            MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5,
                                                               argumentWord6, "memory");
                            originalFrame.sp24 = 0;
                            originalFrame.sp28 = 0;
                            originalFrame.sp20 = rawWord2;
                            Family1242TransformVectorByBasis(argumentWord4, argumentWord5,
                                                             argumentWord6);
                            retainedFactorCounterOrVector16 += 1;
                            rawWord2 = Family1242_rand();
                            rawWord3 = originalFrame.sp20;
                            rawWord2 &= 0xFE;
                            rawWord3 -= 127;
                            rawWord3 += rawWord2;
                            originalFrame.sp20 = rawWord3;
                            rawWord2 = Family1242_rand();
                            rawWord3 = originalFrame.sp24;
                            rawWord2 &= 0xFE;
                            rawWord3 -= 127;
                            rawWord3 += rawWord2;
                            originalFrame.sp24 = rawWord3;
                            rawWord2 = Family1242_rand();
                            argumentWord4 = 1;
                            argumentWord5 = 23;
                            argumentWord6 = ownerRecord20 + 12;
                            argumentWord7 = (int)retainedVectorOrAngle19;
                            MATCHING_OBSERVE4_VOLATILE(argumentWord4, argumentWord5, argumentWord6,
                                                       argumentWord7);
                            rawWord2 &= 254;
                            rawWord3 = originalFrame.sp28;
                            rawWord3 -= 127;
                            rawWord3 += rawWord2;
                            originalFrame.sp28 = rawWord3;
                            Family1242_SpawnParticle(argumentWord4, argumentWord5, argumentWord6,
                                                     argumentWord7);
                            argumentWord4 = ownerRecord20 + 0x20;
                        } while (retainedFactorCounterOrVector16 < 8);
                        rawWord3 = Family1242Field(privateRecord18, int*, 0x34);
                        __asm__ volatile("" ::: "$2", "memory");
                        rawWord2 = 48;
                        Family1242Field(privateRecord18, short*, 0x40) = rawWord2;
                        if (rawWord3 >= 0) {
                            rawWord2 = -1;
                        } else {
                            MATCHING_BARRIER_VOLATILE("$2");
                            rawWord2 = 1;
                        }
                        Family1242Field(privateRecord18, short*, 0x42) = rawWord2;
                        rawWord2 = 2;
                    writeOriginalTransitionState:
                        Family1242Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
                    } else {
                        rawWord2 = Family1242Field(retainedPathOrAngle17, short*, 0);
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(retainedPathOrAngle17, "memory");
                        retainedPathOrAngle17 += 2;
                        if (rawWord2 < 0) {
                        } else {
                            goto scanOriginalLinkedEntry;
                        }
                    }
                    goto processOriginalCommonPath;
                }
                if (Family1242_D_8006FA3C == 2) {
                    goto deleteOriginalActor;
                }
                retainedFactorCounterOrVector16 =
                    Family1242Field(ownerRecord20, unsigned char*, 0x46);
                Family1242_unk_ovlheader_800743EC(
                    ownerRecord20, Family1242Field(privateRecord18, short**, 0x14),
                    privateRecord18 + 0x2C, privateRecord18 + 0x48, 0x12, 0);
                rawWord2 = Family1242Field(ownerRecord20, unsigned char*, 0x46);
                rawWord2 = retainedFactorCounterOrVector16 - rawWord2;
                retainedFactorCounterOrVector16 = rawWord2 & 255;
                if (retainedFactorCounterOrVector16 >= 0x81) {
                    retainedFactorCounterOrVector16 -= 0x100;
                }
                rawWord2 = Family1242Field(ownerRecord20, unsigned char*, 0x44);
                rawWord3 = (unsigned)retainedFactorCounterOrVector16 << 6;
                rawWord3 -= rawWord2;
                retainedFactorCounterOrVector16 = rawWord3 & 255;
                if (retainedFactorCounterOrVector16 >= 0x81) {
                    retainedFactorCounterOrVector16 -= 0x100;
                }
                argumentWord4 = Family1242Field(privateRecord18, int*, 0x38);
                rawWord3 = (unsigned)retainedFactorCounterOrVector16 << 3;
                rawWord2 = argumentWord4 * 12;
                rawWord3 = rawWord3 - rawWord2;
                MATCHING_OBSERVE_VOLATILE(rawWord3);
                rawWord3 >>= 6;
                __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(retainedFactorCounterOrVector16));
                rawWord2 = Family1242Field(privateRecord18, int*, 0x20);
                argumentWord4 += rawWord3;
                Family1242Field(privateRecord18, int*, 0x38) = argumentWord4;
                rawWord2 += argumentWord4;
                rawWord3 = rawWord2 & 4095;
                Family1242Field(privateRecord18, int*, 0x20) = rawWord3;
                if (rawWord3 >= 0x801) {
                    rawWord2 = rawWord3 - 4096;
                    Family1242Field(privateRecord18, int*, 0x20) = rawWord2;
                    MATCHING_OBSERVE2_VOLATILE(rawWord2, rawWord3);
                }
                rawWord2 = Family1242Field(privateRecord18, int*, 0x20);
                __asm__ volatile("" ::: "$3", "memory");
                rawWord3 = Family1242Field(privateRecord18, int*, 0x3C);
                if (rawWord3 < rawWord2) {
                    Family1242Field(privateRecord18, int*, 0x20) = rawWord3;
                }
                rawWord3 = -Family1242Field(privateRecord18, int*, 0x3C);
                if (Family1242Field(privateRecord18, int*, 0x20) < rawWord3) {
                    Family1242Field(privateRecord18, int*, 0x20) = rawWord3;
                }
                Family1242Field(ownerRecord20, unsigned char*, 0x44) =
                    (unsigned char)((int)Family1242Field(privateRecord18, int*, 0x20) >> 4);
                Family1242RefreshMobySpatialGridAndBasis(ownerRecord20, 4);
                goto processOriginalCommonPath;
            case 2:
                if (!Family1242TestSlot(ownerRecord20, Family1242Field(privateRecord18, int*, 4)))
                    Family1242Field(privateRecord18, int*, 4) =
                        Family1242PlayMobySoundEvent(ownerRecord20, 0, 4);
                rawWord2 = Family1242Field(privateRecord18, int*, 0x58) + 2;
                argumentWord4 = Family1242Field(ownerRecord20, int*, 0x14);
                retainedFactorCounterOrVector16 =
                    (int)(retainedFactorCounterOrVector16 * rawWord2) >> 2;
                __asm__(""
                        : "=r"(retainedFactorCounterOrVector16)
                        : "0"(retainedFactorCounterOrVector16), "r"(argumentWord4));
                rawWord3 = Family1242_func_8004E4E4(argumentWord4 -
                                                    retainedFactorCounterOrVector16 + 3584);
                MATCHING_KEEP(rawWord3);
                Family1242Field(privateRecord18, int*, 0x1C) = rawWord3;
                if (retainedRemainderMinimum21 < 5) {
                    rawWord2 = rawWord3 - 1024;
                } else
                    rawWord2 = rawWord3 + 8192;
                Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord2, rawWord3, "memory");
                rawWord3 = Family1242Field(privateRecord18, int*, 0x1C);
                rawWord2 = Family1242_D_8006C648;
                rawWord2 = (int)(rawWord3 * rawWord2) >> 6;
                Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                retainedFactorCounterOrVector16 = Family1242Field(privateRecord18, int*, 0x20);
                Family1242_unk_ovlheader_80074398(ownerRecord20,
                                                  Family1242Field(privateRecord18, short**, 0x14),
                                                  privateRecord18 + 0x1C);
                rawWord2 = Family1242Field(privateRecord18, short*, 0x42) << 7;
                retainedFactorCounterOrVector16 =
                    (retainedFactorCounterOrVector16 + rawWord2) & 0xFFF;
                Family1242Field(privateRecord18, int*, 0x20) = retainedFactorCounterOrVector16;
                Family1242Field(privateRecord18, int*, 0x2C) = rawWord2;
                Family1242Field(ownerRecord20, unsigned char*, 0x44) =
                    (unsigned char)(retainedFactorCounterOrVector16 >> 4);
                if (Family1242CountTimerDown(privateRecord18 + 0x40, 2) != 0) {
                    Family1242Field(ownerRecord20, unsigned char*, 0x48) = 3U;
                }
                retainedFactorCounterOrVector16 = 0;
                retainedPathOrAngle17 = (int)&originalFrame.sp20;
                argumentWord4 = ownerRecord20 + 32;
                do {
                    argumentWord5 = retainedPathOrAngle17;
                    rawWord2 = Family1242Field(privateRecord18, int*, 0x1C);
                    __asm__ volatile("" ::: "$6", "memory");
                    argumentWord6 = retainedPathOrAngle17;
                    MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                                       "memory");
                    originalFrame.sp24 = 0;
                    originalFrame.sp28 = 0;
                    rawWord2 >>= 2;
                    originalFrame.sp20 = rawWord2;
                    Family1242TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
                    retainedFactorCounterOrVector16 += 1;
                    rawWord2 = Family1242_rand();
                    rawWord3 = originalFrame.sp20;
                    rawWord2 &= 0xFE;
                    rawWord3 -= 127;
                    rawWord3 += rawWord2;
                    originalFrame.sp20 = rawWord3;
                    rawWord2 = Family1242_rand();
                    rawWord3 = originalFrame.sp24;
                    rawWord2 &= 0xFE;
                    rawWord3 -= 127;
                    rawWord3 += rawWord2;
                    originalFrame.sp24 = rawWord3;
                    rawWord2 = Family1242_rand();
                    argumentWord4 = 1;
                    argumentWord5 = 23;
                    argumentWord6 = ownerRecord20 + 12;
                    argumentWord7 = retainedPathOrAngle17;
                    MATCHING_OBSERVE4_VOLATILE(argumentWord4, argumentWord5, argumentWord6,
                                               argumentWord7);
                    rawWord2 &= 254;
                    rawWord3 = originalFrame.sp28;
                    rawWord3 -= 127;
                    rawWord3 += rawWord2;
                    originalFrame.sp28 = rawWord3;
                    Family1242_SpawnParticle(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
                    argumentWord4 = ownerRecord20 + 0x20;
                } while (retainedFactorCounterOrVector16 < 2);
                goto processOriginalCommonPath;
            case 3:
                if (!Family1242TestSlot(ownerRecord20, Family1242Field(privateRecord18, int*, 4)))
                    Family1242Field(privateRecord18, int*, 4) =
                        Family1242PlayMobySoundEvent(ownerRecord20, 0, 4);
                rawWord2 = Family1242Field(privateRecord18, int*, 0x58) + 2;
                argumentWord4 = Family1242Field(ownerRecord20, int*, 0x14);
                retainedPathOrAngle17 = (int)(retainedFactorCounterOrVector16 * rawWord2) >> 2;
                __asm__(""
                        : "=r"(retainedPathOrAngle17)
                        : "0"(retainedPathOrAngle17), "r"(argumentWord4));
                retainedPathOrAngle17 =
                    Family1242_func_8004E4E4(argumentWord4 - retainedPathOrAngle17 + 3584);
                if (retainedRemainderMinimum21 < 5) {
                    Family1242Field(privateRecord18, int*, 0x1C) =
                        (int)(Family1242Field(privateRecord18, int*, 0x1C) - 0x400);
                }
                argumentWord4 = Family1242Field(privateRecord18, int*, 0x1C);
                retainedPathOrAngle17 = (int)(retainedPathOrAngle17 * Family1242_D_8006C648) >> 6;
                if ((argumentWord4 - retainedPathOrAngle17) >= 4) {
                    rawWord2 = argumentWord4 - (Family1242_D_8006C648 * 3);
                    Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                } else {
                    Family1242Field(privateRecord18, int*, 0x1C) = retainedPathOrAngle17;
                    Family1242Field(ownerRecord20, unsigned char*, 0x48) = 1U;
                }
                retainedVectorOrAngle19 = Family1242Field(privateRecord18, int*, 0x20);
                retainedPathOrAngle17 = Family1242Field(privateRecord18, int*, 0x2C);
                Family1242_unk_ovlheader_80074398(ownerRecord20,
                                                  Family1242Field(privateRecord18, short**, 0x14),
                                                  privateRecord18 + 0x1C);
                rawWord2 = -retainedVectorOrAngle19;
                retainedVectorOrAngle19 = rawWord2 & 0xFFF;
                Family1242Field(privateRecord18, int*, 0x2C) = retainedPathOrAngle17;
                if (retainedVectorOrAngle19 >= 0x801) {
                    retainedVectorOrAngle19 -= 0x1000;
                }
                argumentWord4 = ownerRecord20 + 32;
                retainedFactorCounterOrVector16 = (int)&originalFrame.sp30;
                argumentWord5 = retainedFactorCounterOrVector16;
                MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                rawWord2 = retainedPathOrAngle17 +
                           ((int)(retainedVectorOrAngle19 - (retainedPathOrAngle17 * 0x18)) >> 6);
                Family1242Field(privateRecord18, int*, 0x2C) = rawWord2;
                rawWord3 = (Family1242Field(privateRecord18, int*, 0x20) + rawWord2) & 0xFFF;
                Family1242Field(privateRecord18, int*, 0x20) = rawWord3;
                Family1242Field(ownerRecord20, unsigned char*, 0x44) =
                    (unsigned char)(rawWord3 >> 4);
                rawWord2 = Family1242Field(privateRecord18, int*, 0x1C);
                __asm__ volatile("" ::: "$6", "memory");
                argumentWord6 = retainedFactorCounterOrVector16;
                MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                                   "memory");
                originalFrame.sp34 = 0;
                originalFrame.sp38 = 0;
                rawWord2 >>= 2;
                originalFrame.sp30 = rawWord2;
                Family1242TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
                rawWord2 = Family1242_rand();
                rawWord3 = originalFrame.sp30;
                rawWord2 &= 0xFE;
                rawWord3 -= 127;
                rawWord3 += rawWord2;
                originalFrame.sp30 = rawWord3;
                rawWord2 = Family1242_rand();
                rawWord3 = originalFrame.sp34;
                rawWord2 &= 0xFE;
                rawWord3 -= 127;
                rawWord3 += rawWord2;
                originalFrame.sp34 = rawWord3;
                rawWord2 = Family1242_rand();
                argumentWord4 = 1;
                argumentWord5 = 23;
                argumentWord6 = ownerRecord20 + 12;
                argumentWord7 = (int)&originalFrame.sp30;
                MATCHING_OBSERVE4_VOLATILE(argumentWord4, argumentWord5, argumentWord6,
                                           argumentWord7);
                rawWord2 &= 254;
                rawWord3 = originalFrame.sp38;
                rawWord3 -= 127;
                rawWord3 += rawWord2;
                originalFrame.sp38 = rawWord3;
                Family1242_SpawnParticle(argumentWord4, argumentWord5, argumentWord6,
                                         argumentWord7);
                goto processOriginalCommonPath;
            case 5:
                rawWord2 = Family1242Field(privateRecord18, int*, 0x58) + 2;
                argumentWord4 = Family1242Field(ownerRecord20, int*, 0x14);
                retainedFactorCounterOrVector16 =
                    (int)(retainedFactorCounterOrVector16 * rawWord2) >> 2;
                __asm__(""
                        : "=r"(retainedFactorCounterOrVector16)
                        : "0"(retainedFactorCounterOrVector16), "r"(argumentWord4));
                rawWord3 = Family1242_func_8004E4E4(argumentWord4 -
                                                    retainedFactorCounterOrVector16 + 3584);
                MATCHING_KEEP(rawWord3);
                Family1242Field(privateRecord18, int*, 0x1C) = rawWord3;
                if (retainedRemainderMinimum22 >= 5) {
                    rawWord2 = rawWord3 - 0x1000;
                    Family1242Field(privateRecord18, int*, 0x1C) = rawWord2;
                    MATCHING_OBSERVE2_VOLATILE(rawWord2, rawWord3);
                }
                if (Family1242Field(privateRecord18, int*, 0x1C) < 0x800) {
                    Family1242Field(privateRecord18, int*, 0x1C) = 0x800;
                }
                retainedPathOrAngle17 = Family1242Field(privateRecord18, int*, 0x20);
                Family1242Field(privateRecord18, int*, 0x1C) =
                    (int)((int)(Family1242Field(privateRecord18, int*, 0x1C) *
                                Family1242_D_8006C648) >>
                          6);
                retainedFactorCounterOrVector16 = Family1242Field(privateRecord18, int*, 0x2C);
                Family1242_unk_ovlheader_80074398(ownerRecord20,
                                                  Family1242Field(privateRecord18, short**, 0x14),
                                                  privateRecord18 + 0x1C);
                Family1242Field(privateRecord18, int*, 0x2C) = retainedFactorCounterOrVector16;
                Family1242Field(privateRecord18, int*, 0x20) = retainedPathOrAngle17;
                rawWord3 = Family1242Field(privateRecord18, short*, 0x40);
                rawWord2 = 240 - rawWord3;
                retainedFactorCounterOrVector16 = (unsigned)rawWord2 << 3;
                MATCHING_KEEP(retainedFactorCounterOrVector16);
                rawWord2 = retainedFactorCounterOrVector16 & 0x1f8;
                rawWord2 = Family1242Field((int)&Family1242_D_80065920, unsigned short*, rawWord2);
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
                argumentWord4 = Family1242Field(privateRecord18, int*, 0x2C);
                rawWord3 = retainedPathOrAngle17 * 2;
                rawWord2 = argumentWord4 * 24;
                rawWord3 -= rawWord2;
                rawWord3 >>= 6;
                __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(retainedPathOrAngle17));
                argumentWord4 += rawWord3;
                Family1242Field(privateRecord18, int*, 0x2C) = argumentWord4;
                rawWord2 = (Family1242Field(privateRecord18, int*, 0x20) + argumentWord4) & 0xFFF;
                Family1242Field(privateRecord18, int*, 0x20) = rawWord2;
                Family1242Field(ownerRecord20, unsigned char*, 0x44) =
                    (unsigned char)(rawWord2 >> 4);
                rawWord3 = Family1242Field(privateRecord18, short*, 0x40);
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
                        argumentWord4 = privateRecord18 + 0x40;
                        rawWord2;
                    })) {
                    Family1242InterpolateMobyVertex(ownerRecord20, 0, &originalFrame.sp50);
                    retainedFactorCounterOrVector16 = 0;
                    do {
                        retainedFactorCounterOrVector16 += 1;
                        originalFrame.sp40 = (Family1242_rand() & 0x3E) - 0x1F;
                        originalFrame.sp44 = (Family1242_rand() & 0x3E) - 0x1F;
                        originalFrame.sp48 = (Family1242_rand() & 0x3E) - 0x1F;
                        Family1242_SpawnParticle(1, 1, &originalFrame.sp50, &originalFrame.sp40);
                        argumentWord4 = privateRecord18 + 0x40;
                    } while (retainedFactorCounterOrVector16 < 2);
                }
                if (Family1242CountTimerDown(argumentWord4, 2) != 0) {
                    Family1242Field(ownerRecord20, int*, 0x18) = 0;
                    rawWord2 = 1;
                    Family1242Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
                }
                goto processOriginalCommonPath;
        }
    processOriginalCommonPath:
        argumentWord4 = Family1242Field(privateRecord18, int*, 0x14);
        rawWord3 = Family1242Field(argumentWord4, short*, 2);
        if (rawWord3 != originalFrame.sp18) {
            rawWord3 = rawWord3 * 16 + Family1242Field(argumentWord4, int*, 12);
            argumentWord4 = Family1242Field(rawWord3, int*, 12);
            if (argumentWord4 == 1) {
                rawWord2 = retainedRemainderMinimum22 < 5;
                if (rawWord2)
                    originalFrame.sp18 = argumentWord4;
                else {
                    rawWord2 = retainedRemainderMinimum21 < 5;
                    if (!rawWord2) {
                        rawWord2 = Family1242Field(privateRecord18, int*, 0x58);
                        rawWord3 = Family1242Field(privateRecord18, int*, 0x18);
                        rawWord2 = rawWord2 * 8 + 128;
                        rawWord3 += rawWord2;
                        MATCHING_KEEP(rawWord3);
                        Family1242Field(privateRecord18, int*, 0x18) = rawWord3;
                        rawWord3 = rawWord3 < 345;
                        if (!rawWord3) {
                            MATCHING_BARRIER_VOLATILE("memory");
                            rawWord2 = Family1242Field(privateRecord18, int*, 0x18);
                            originalFrame.sp18 = argumentWord4;
                            rawWord2 -= 345;
                            Family1242Field(privateRecord18, int*, 0x18) = rawWord2;
                            goto family1242Selected;
                        }
                    }
                    originalFrame.sp18 = 0;
                }
            family1242Selected:
                rawWord2 = originalFrame.sp18;
                rawWord3 = Family1242Field(privateRecord18, int*, 0x14);
                rawWord2 = rawWord2 * 4 + privateRecord18;
                argumentWord5 = Family1242Field(rawWord2, int*, 12);
                argumentWord4 = ownerRecord20 + 12;
                if (rawWord3 != argumentWord5) {
                    argumentWord6 = Family1242Field(rawWord3, short*, 2);
                    rawWord2 = (int)Family1242_unk_ovlheader_800743A4;
                    rawWord2 =
                        ((int (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, 3);
                    rawWord3 = originalFrame.sp18 * 4 + privateRecord18;
                    argumentWord4 = Family1242Field(rawWord3, int*, 12);
                    Family1242Field(argumentWord4, short*, 2) = rawWord2;
                    rawWord3 = Family1242Field(rawWord3, int*, 12);
                    rawWord2 = 1;
                    Family1242Field(privateRecord18, int*, 0x14) = rawWord3;
                    Family1242Field(rawWord3, short*, 0xA) = rawWord2;
                    argumentWord5 = Family1242Field(privateRecord18, int*, 0x14);
                    rawWord3 = Family1242Field(argumentWord5, short*, 0);
                    rawWord2 = Family1242Field(argumentWord5, short*, 2);
                    argumentWord4 = rawWord3 + 2;
                    rawWord2 = rawWord2 + argumentWord4;
                    rawWord3 = rawWord2 % rawWord3;
                    Family1242Field(argumentWord5, short*, 2) = rawWord3;
                }
            }
            argumentWord4 = Family1242Field(privateRecord18, int*, 0x14);
            rawWord2 = Family1242Field(argumentWord4, short*, 2);
            rawWord3 = Family1242Field(argumentWord4, int*, 12);
            rawWord2 = rawWord2 * 16 + rawWord3;
            rawWord3 = Family1242Field(rawWord2, int*, 12);
            if (rawWord3 == 2) {
                rawWord2 = Family1242Field(privateRecord18, int*, 12);
                if (argumentWord4 == rawWord2)
                    originalFrame.sp18 = 1;
                else
                    originalFrame.sp18 = 0;
                argumentWord4 = ownerRecord20 + 12;
                rawWord2 = originalFrame.sp18;
                rawWord3 = Family1242Field(privateRecord18, int*, 0x14);
                rawWord2 = rawWord2 * 4 + privateRecord18;
                argumentWord5 = Family1242Field(rawWord2, int*, 12);
                argumentWord6 = Family1242Field(rawWord3, short*, 2);
                rawWord2 = (int)Family1242_unk_ovlheader_800743A4;
                rawWord2 = ((int (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, 3);
                rawWord3 = originalFrame.sp18 * 4 + privateRecord18;
                argumentWord4 = Family1242Field(rawWord3, int*, 12);
                Family1242Field(argumentWord4, short*, 2) = rawWord2;
                rawWord3 = Family1242Field(rawWord3, int*, 12);
                rawWord2 = 1;
                Family1242Field(privateRecord18, int*, 0x14) = rawWord3;
                Family1242Field(rawWord3, short*, 0xA) = rawWord2;
                argumentWord5 = Family1242Field(privateRecord18, int*, 0x14);
                rawWord3 = Family1242Field(argumentWord5, short*, 0);
                rawWord2 = Family1242Field(argumentWord5, short*, 2);
                argumentWord4 = rawWord3 + 2;
                rawWord2 = rawWord2 + argumentWord4;
                rawWord3 = rawWord2 % rawWord3;
                Family1242Field(argumentWord5, short*, 2) = rawWord3;
            }
        }
        argumentWord4 = privateRecord18 + 0x48;
        if (*Family1242Field(privateRecord18, void***, 0x8) == ownerRecord20) {
            Family1242Field((int)&Family1242_D_8006FA7C, int*, 0) = 0;
            if (Family1242Field((int)&Family1242_D_8006FA7C, int*, 4) == -1) {
                Family1242GetClosestPathNodeByVectorLength(
                    (int)&Family1242_D_80070328, Family1242Field(privateRecord18, short**, 0xC),
                    (int)&Family1242_D_8006FA7C + 4);
            } else if (Family1242Field((int)&Family1242_D_8006FA7C, int*, 4) == -2) {
                Family1242Field((int)&Family1242_D_8006FA7C, int*, 4) = -1;
            }
            retainedPathOrAngle17 = (int)&Family1242_D_8006FA80;
            retainedFactorCounterOrVector16 = Family1242Field(retainedPathOrAngle17, int*, 0);
            if (retainedFactorCounterOrVector16 >= 0) {
                argumentWord6 = retainedFactorCounterOrVector16;
                rawWord3 = Family1242_unk_ovlheader_800743A4(
                    (int)&Family1242_D_80070328, Family1242Field(privateRecord18, int*, 0xC),
                    argumentWord6, 10);
                Family1242Field(retainedPathOrAngle17, int*, 0) = rawWord3;
                rawWord2 = retainedFactorCounterOrVector16 < 10;
                if (rawWord2) {
                    rawWord2 = Family1242Field(privateRecord18, int*, 0xC);
                    rawWord2 = Family1242Field(rawWord2, short*, 0);
                    rawWord2 -= 11;
                    if (rawWord2 < rawWord3) {
                        rawWord2 = 10;
                        Family1242Field(retainedPathOrAngle17, int*, 0) = rawWord2;
                    }
                }
            }
            argumentWord4 = privateRecord18 + 0x48;
        }
        if ((Family1242CountTimerDown(argumentWord4, 4) != 0) &&
            (Family1242_unk_ovlheader_8007439C(
                 Family1242_D_8006C550 + (Family1242Field(privateRecord18, int*, 0x50) * 0x58),
                 ownerRecord20 + 0xC, 0x1000, 0) != 0)) {
            Family1242Field(privateRecord18, int*, 0x48) = 0x78;
            Family1242Field(privateRecord18, int*, 0x44) =
                (int)(Family1242Field(privateRecord18, int*, 0x44) + 1);
        }
        argumentWord4 = *Family1242Field(privateRecord18, short**, 0xC);
        retainedFactorCounterOrVector16 = (int)((Family1242_D_8006FA80 + argumentWord4) -
                                                *Family1242Field(privateRecord18, int**, 0x54)) %
                                          argumentWord4;
        if ((Family1242Field(
                 ((Family1242Field(privateRecord18, int*, 0x50) * 0x58) + Family1242_D_8006C550),
                 unsigned char*, 0x48) == 3) &&
            (retainedFactorCounterOrVector16 == 0)) {
            retainedFactorCounterOrVector16 = (int)argumentWord4;
        }
        argumentWord5 = Family1242Field(privateRecord18, short**, 0xC);
        retainedFactorCounterOrVector16 =
            retainedFactorCounterOrVector16 + ((*((short*)argumentWord5)) * Family1242_D_8006FA78);
        rawWord2 = Family1242_unk_ovlheader_800743A4(
            ownerRecord20 + 0xC, argumentWord5,
            Family1242Field(Family1242Field(privateRecord18, short**, 0x14), short*, 2), 3);
        originalFrame.sp18 = rawWord2;
        rawWord3 = *Family1242Field(privateRecord18, short**, 0xC);
        signedRemainder =
            (int)((rawWord2 + rawWord3) - *Family1242Field(privateRecord18, int**, 0x54)) %
            rawWord3;
        originalFrame.sp18 = signedRemainder;
        if ((signedRemainder == 0) && (Family1242Field(privateRecord18, int*, 0x48) == 0)) {
            originalFrame.sp18 = (int)*Family1242Field(privateRecord18, short**, 0xC);
        }
        rawWord2 = Family1242Field(privateRecord18, int*, 0xC);
        rawWord3 = Family1242Field(rawWord2, short*, 0);
        rawWord2 = Family1242Field(privateRecord18, int*, 0x44);
        completeFinalProduct = (long long)(int)rawWord3 * (int)rawWord2;
        rawWord2 = originalFrame.sp18;
        __asm__("" : "=l"(finalProductLow) : "x"(completeFinalProduct), "r"(rawWord2));
        rawWord3 = rawWord2 + finalProductLow;
        originalFrame.sp18 = rawWord3;
        argumentWord4 = Family1242Field(privateRecord18, int*, 0x4C);
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
            rawWord2 = (int)&Family1242_D_8006FA7C;
            rawWord3 = Family1242Field(rawWord2, int*, 0);
            rawWord3++;
            Family1242Field(rawWord2, int*, 0) = rawWord3;
            rawWord2 = 1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "memory");
            Family1242Field(privateRecord18, int*, 0x4C) = rawWord2;
        } else {
            rawWord2 = 2;
            Family1242Field(privateRecord18, int*, 0x4C) = rawWord2;
        }
        return;
    } else {
        if (Family1242Field(ownerRecord20, int*, 0x18) &&
            Family1242Field(ownerRecord20, unsigned char*, 0x48) != 1) {
            if (Family1242TestSlot(ownerRecord20, Family1242Field(privateRecord18, int*, 4)))
                Family1242ClearSlot(Family1242Field(privateRecord18, int*, 4));
            Family1242Field(privateRecord18, int*, 4) = -1;
            Family1242PlayMobySoundEvent(ownerRecord20, 1, 0);
            Family1242_func_80036A68(ownerRecord20, 16, 0, 0);
            Family1242_unk_ovlheader_80074384(ownerRecord20);
            Family1242H38F14(ownerRecord20, privateRecord18 + 0x60, 6, 1);
            rawWord3 = Family1242Field((int)&Family1242_D_80070328, int*, 0xB4);
            __asm__ volatile("" ::: "$2", "memory");
            rawWord2 = 6;
            MATCHING_OBSERVE_VOLATILE(rawWord2);
            Family1242Field(privateRecord18, unsigned char*, 0x6E) = rawWord2;
            rawWord2 = 120;
            MATCHING_OBSERVE_VOLATILE(rawWord2);
            Family1242Field(privateRecord18, unsigned char*, 0x76) = rawWord2;
            rawWord2 = Family1242Field(privateRecord18, unsigned short*, 0x64);
            rawWord3 >>= 5;
            rawWord2 += rawWord3;
            Family1242Field(privateRecord18, short*, 0x64) = rawWord2;
            Family1242Field(ownerRecord20, int*, 8) = 0;
        }
        switch (Family1242Field(ownerRecord20, unsigned char*, 0x48)) {
            case 0:
                if (!Family1242TestSlot(ownerRecord20, Family1242Field(privateRecord18, int*, 4)))
                    Family1242Field(privateRecord18, int*, 4) =
                        Family1242PlayMobySoundEvent(ownerRecord20, 0, 4);
                rawWord2 = Family1242Field(privateRecord18, int*, 0x58);
                rawWord3 = Family1242Field(privateRecord18, int*, 0x5C);
                rawWord2 = rawWord2 * 4 + rawWord3;
                rawWord2 = Family1242Field(rawWord2, int*, 0);
                Family1242Field(ownerRecord20, int*, 0x54) = rawWord2;
                Family1242Field(ownerRecord20, signed char*, 0x57) = 0;
                rawWord2 = Family1242Tick;
                rawWord3 = Family1242Field(privateRecord18, int*, 0x78);
                rawWord2 = rawWord2 * 2 + rawWord3;
                rawWord2 &= 0x1FE;
                rawWord2 = Family1242Field((int)&Family1242_D_80065920, unsigned short*, rawWord2);
                __asm__ volatile("" ::: "$3", "memory");
                rawWord3 = Family1242Field(privateRecord18, int*, 0x7C);
                MATCHING_KEEP_VOLATILE_CLOBBER(rawWord2, "memory");
                rawWord2 = (unsigned)rawWord2 << 16;
                rawWord2 >>= 17;
                rawWord8 = rawWord2 + 2048;
                rawWord8 = (int)(rawWord3 * rawWord8) >> 12;
                argumentWord4 = ownerRecord20;
                argumentWord5 = 4;
                argumentWord6 = 0;
                argumentWord7 = 0;
                rawWord2 = Family1242Field(privateRecord18, int*, 0x88);
                rawWord2 += rawWord8;
                Family1242Field(ownerRecord20, int*, 0x14) = rawWord2;
                Family1242TurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                               argumentWord7);
                if (Family1242_D_8006FA3C == 2)
                    goto deleteOriginalActor;
                return;
            case 1:
                if (Family1242H35194(ownerRecord20, privateRecord18 + 0x60) == 256) {
                    Family1242RefreshMobySpatialGridAndBasis(ownerRecord20, 4);
                    Family1242H3BA00(ownerRecord20);
                    Family1242H369B8(ownerRecord20, 48);
                deleteOriginalActor:
                    Family1242DeleteMoby(ownerRecord20);
                }
                return;
        }
    }
}
#undef Family1242Field

typedef struct {
    int reserved00;
    Moby* spawned;
    int phase, fragmentKind;
} DecodedFragmentGemTag;
extern unsigned char D_80066964[], D_80066988[], D_80066990[];
extern unsigned short DecodedSpawnedGemCos[] __asm__("D_80065920");
extern int D_8006C648;
extern Spyro spyro;
extern int (*DecodedSpawnedGemQuery)(Moby*, void*, int, int) __asm__("unk_ovlheader_8007439C");
extern void (*DecodedSpawnedGemFinish)(Moby*) __asm__("unk_ovlheader_80074384");
void DecodedSpawnedGemTarget(int, int, int) __asm__("func_80021ED8");
int DecodedSpawnedGemPlaying(Moby*, int) __asm__("func_8003BFC0");
int DecodedSpawnedGemEvent(Moby*, int, int) __asm__("func_8003BB10");
int rand(void);
extern int DecodedSpawnedGemMode __asm__("D_8006FA3C");
void DecodedSpawnedGemSound(Moby*, int, int) __asm__("func_8003BABC");
void func_level_35_8007C1F4(Moby* moby) {
    DecodedFragmentGemTag* tag = moby->mobyTag;
    unsigned char* spawnedTag;
    int fragmentMode = 1;
    switch (moby->state) {
        case 0:
            if ((unsigned int)(DecodedSpawnedGemMode - 2) < 2)
                goto remove;
            if (moby->gemValue != 0xFF) {
                tag->spawned = SpawnMoby(1, moby);
                if (tag->spawned) {
                    spawnedTag = tag->spawned->mobyTag;
                    func_8004F178(&tag->spawned->position, &moby->position);
                    tag->spawned->state = 5;
                    tag->spawned->substate = D_80066964[moby->gemValue];
                    tag->spawned->animationState.id = D_80066988[tag->spawned->substate];
                    tag->spawned->colour.r = D_80066990[tag->spawned->substate];
                    tag->spawned->lowDrawDistance = moby->lowDrawDistance;
                    tag->spawned->highDrawDistance = moby->highDrawDistance;
                    spawnedTag[0x13] = 0xFF;
                    tag->phase = rand() & 0xFF;
                }
            }
            moby->state = 1;
            break;
        case 1:
            if (tag->spawned) {
                tag->phase += D_8006C648;
                tag->spawned->angle.pitch = DecodedSpawnedGemCos[(tag->phase * 4) & 0xFC] >> 8;
                tag->spawned->angle.yaw += 4;
                tag->spawned->position.z =
                    moby->position.z + ((short)DecodedSpawnedGemCos[(tag->phase * 2) & 0xFE] >> 4);
            }
            if (DecodedSpawnedGemQuery(moby, &spyro, 0x800, 0))
                moby->state = 2;
            break;
        case 2:
            DecodedSpawnedGemFinish(moby);
            DecodedSpawnedGemSound(moby, 0, 0);
            SpawnFragments(6, moby->mobyClass, moby, tag->fragmentKind, fragmentMode, 0x200);
            if (tag->spawned)
                tag->spawned->state = 4;
        remove:
            func_80055B18(moby);
            break;
        case 3:
            func_80039714(moby);
            break;
    }
}

typedef struct {
    int kind;
    Vector3D vector;
    int phase;
    Vector3D* fragments;
    int sound;
} DecodedSoundFragmentTag;
extern int D_8006FA3C;
extern void (*DecodedFragmentDamage)(Moby*) __asm__("unk_ovlheader_80074384");
extern void (*DecodedFragmentMotion)(Moby*, int, Vector3D*, int*, int,
                                     int) __asm__("unk_ovlheader_800743EC");
int DecodedFragmentPositionQuery(Vector3D*, int) __asm__("func_8001A358");
void func_level_35_8007C4B0(Moby* moby) {
    Vector3D position;
    Angle savedAngle;
    DecodedSoundFragmentTag* tag = moby->mobyTag;
    if (moby->damageFlags) {
        if (func_8003BFC0(moby, tag->sound))
            func_8003BE70(tag->sound);
        tag->sound = -1;
        func_8003BABC(moby, 1, 0);
        func_80036A68(moby, 0x10, 0, 0);
        DecodedFragmentDamage(moby);
        SpawnFragments(5, 0x212, moby, tag->fragments, 0, 0x200);
        func_80055B18(moby);
    } else if ((unsigned int)(D_8006FA3C - 2) < 2)
        func_80055B18(moby);
    else {
        if (!moby->substate) {
            savedAngle.roll = moby->angle.roll;
            savedAngle.pitch = moby->angle.pitch;
            savedAngle.yaw = moby->angle.yaw;
            moby->angle.roll = 0;
            moby->angle.pitch = 0;
            moby->angle.yaw = 0;
            func_80055D24(moby, 4);
            moby->angle.roll = savedAngle.roll;
            moby->angle.pitch = savedAngle.pitch;
            moby->angle.yaw = savedAngle.yaw;
            moby->substate = 1;
        }
        if (!func_8003BFC0(moby, tag->sound))
            tag->sound = func_8003BABC(moby, 0, 4);
        DecodedFragmentMotion(moby, tag->kind, &tag->vector, &tag->phase, 6, 0);
        func_8004F178(&position, &moby->position);
        position.z += 0x200;
        position.z = DecodedFragmentPositionQuery(&position, 0x800);
        if (position.z)
            *(unsigned int*)&moby->colour = (position.z & 0xFFFFFF) | 0x80000000;
        else
            *(unsigned int*)&moby->colour = 0;
    }
}

typedef struct {
    Moby* spawned;
    int phase, sound, targetIndex;
} DecodedSpawnedGemTag;
extern unsigned char D_80066964[], D_80066988[], D_80066990[];
extern unsigned short DecodedSpawnedGemCos[] __asm__("D_80065920");
extern int D_8006C648;
extern Spyro spyro;
extern int (*DecodedSpawnedGemQuery)(Moby*, void*, int, int) __asm__("unk_ovlheader_8007439C");
extern void (*DecodedSpawnedGemFinish)(Moby*) __asm__("unk_ovlheader_80074384");
void DecodedSpawnedGemTarget(int, int, int) __asm__("func_80021ED8");
int DecodedSpawnedGemPlaying(Moby*, int) __asm__("func_8003BFC0");
int DecodedSpawnedGemEvent(Moby*, int, int) __asm__("func_8003BB10");
int rand(void);
void func_level_35_8007C6B8(Moby* moby) {
    DecodedSpawnedGemTag* tag = moby->mobyTag;
    unsigned char* spawnedTag;
    int heightOffset;
    switch (moby->state) {
        case 0:
            if (moby->gemValue != 0xFF) {
                tag->spawned = SpawnMoby(1, moby);
                if (tag->spawned) {
                    spawnedTag = tag->spawned->mobyTag;
                    func_8004F178(&tag->spawned->position, &moby->position);
                    tag->spawned->state = 5;
                    tag->spawned->substate = D_80066964[moby->gemValue];
                    tag->spawned->animationState.id = D_80066988[tag->spawned->substate];
                    tag->spawned->colour.r = D_80066990[tag->spawned->substate];
                    tag->spawned->lowDrawDistance = 0x3F;
                    tag->spawned->highDrawDistance = 0x3F;
                    spawnedTag[0x13] = 0xFF;
                    tag->phase = rand() & 0xFF;
                }
            }
            moby->state = 1;
            break;
        case 1:
            if (tag->spawned) {
                tag->phase += D_8006C648;
                tag->spawned->angle.pitch = DecodedSpawnedGemCos[(tag->phase * 4) & 0xFC] >> 8;
                tag->spawned->angle.yaw += 4;
                heightOffset = ((short)DecodedSpawnedGemCos[(tag->phase * 2) & 0xFE] >> 4) + 0x400;
                MATCHING_KEEP(heightOffset);
                tag->spawned->position.z = moby->position.z + heightOffset;
            }
            if (DecodedSpawnedGemQuery(moby, &spyro, 0xC00, 0))
                moby->state = 2;
            break;
        case 2:
            if (tag->targetIndex >= 0)
                DecodedSpawnedGemTarget(tag->targetIndex, 0xFC, 0);
            DecodedSpawnedGemFinish(moby);
            if (tag->spawned)
                tag->spawned->state = 4;
            moby->state = 3;
            break;
        case 3:
            if (!DecodedSpawnedGemPlaying(moby, tag->sound))
                tag->sound = DecodedSpawnedGemEvent(moby, 8, 4);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * asm/nonmatchings/overlays/level_35/moby/func_level_35_8007C948.s
 * SHA256 4634e5e9387ce2849de92954fe09fbe6cdc446d2667cc61e9f65031efc45e41e.
 * 510 instructions and 8 original selector words. Original native/linked
 * words and full disc hashes are required; no semantic/runtime parity claim.
 * Raw units, helper contracts, producer chains and cadence remain unresolved. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))
struct _m2c_stack_func_level_35_8007C948 {
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

void func_level_35_8007C948(void* input_arg0) {
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
            initial4 = 0x16FAE;
            initial3 = 0x16948;
            initial5 = 0x14948;
            MATCHING_KEEP3(initial4, initial3, initial5);
            M2C_FIELD(&SpeedwayController_D_8006FA68, int*, 0) = -1;
            SpeedwayController_D_8006FA6C = -1;
            SpeedwayController_D_8006FA84 = -1;
            SpeedwayController_D_8006FA88 = -1;
            SpeedwayController_D_8006FA86 = -1;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x254) = 5;
            M2C_FIELD(&SpeedwayController_D_80070328, int*, 0x260) = 0x2000;
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
void func_level_35_8007D140(Moby* actor) {
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
void func_level_35_8007D34C(void* input) {
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

void func_level_35_8007E4A0(Moby* moby) {
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
void func_level_35_8007E4C0(Moby* argument) {
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

INCLUDE_RODATA("asm/nonmatchings/overlays/level_35/moby", D_level_35_80074674);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007E6C0.
 * AI generated; not human reviewed. Acceptance requires1107 native
 * instructions and all six selectors. Original frameE8 (232 bytes),
 * saves S0..S6/RA at SPC8..E4,home/outgoing area SP00..0F;original
 * addressable vector/matrix/angle homes span SP10..AB. Remaining local
 * reserve bytes are never read. No FP/SP binding,undefined incoming
 * saved role,overlapping live fixed alias or manual stack write exists.
 * Owner S3/private S5 have the identified parameter/owner0 producers.
 * Saved roles change between constant,byte,index,address,spawn return,
 * private record,frame base and scalar only after each old value dies.
 * The linked actor in S1 survives BOTH original3617C calls. It becomes
 * actor+C only after the second call,then supplies the vector helpers.
 * A decoder-created overlapping actor/point lifetime is not inherited.
 * S0 is the sole original SP90 base through its final helper;it becomes
 * the first rand return only after that frame address is dead. S2's
 * SPA0 base starts at the original producer and survives the loop.
 * Every local read follows an identified component producer:vector
 * copy/subtract helpers,3 assigned angle bytes,the matrix helper,
 * scalar function returns or explicit original component writes.
 * Native byte and signed16 widths remain explicit,including LH SP38.
 * All13 variable MULT sites use DISTINCT fully initialized signed64
 * product unions with compiler-correct MIPSEB/MIPSEL local word order.
 * No union address escapes. Two high projections use10624DD3,>>9 and
 * ONE sign correction for /8000. Eleven low projections narrow to
 * signed32 before original signed>>6/10/12. No partial HI/LO input or
 * invented scale is used. Original constant strength reductions remain.
 * The final three products execute X thenY thenZ. Only their captured
 * scalar low words remain live when a later full product starts. Fresh
 * initialized operands consume prior scalar captures to preserve this
 * order. Later jitter reloads the original written frame components;
 * it does not retain a fabricated result across rand calls.
 * Dynamic signed remainders retain original zero/overflow trap paths.
 * Sum averaging uses original logical sign extraction then signed>>1.
 * Complete owner/frame/value identities preserve original reloading,
 * argument staging,store/capture order and distinct actual jump targets.
 * Metadata reads only initialized complete values/addresses or freshly
 * written fields. Dead caller A0/A1 clobbers precede fresh producers.
 * Metadata emits zero CPU instructions;there is no opcode asm.
 * Known helper views preserve native argument words.360A0's last word
 * stays0x31/0x40/0x80;its callee consumes the low byte. Rand has no formal
 * arguments;its original low-product A0 is retained as a whole value.
 * 4E4E4,56504 and the header callback retain original caller ABI views;
 * their complete semantic contracts remain explicitly unresolved.
 * Compiler,filter,flags,actual transfers/data targets,selector bytes
 * and full EXE/every-overlay hashes remain frozen and mandatory.
 * Confidence after gates is binary identity. Allocation/caller/helper
 * closure,units/fixed-point source domains,cadence beyond invocation,
 * Rev1 mapping and synchronized retail captures remain open. Next:
 * human review and those exact evidence chains,without semantic guesses.
 */
/* Original assembly SHA256 8412f810beba352d3259c79f8611b6fc450d2adfe369c6d6296ae94262ddc9ec */
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
} Level35_7E6C0CompleteProduct;
#define Level35_7E6C0Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level35_7E6C0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level35_7E6C0Call13AE4View1(void*, void*) __asm__("func_80013AE4");
int Level35_7E6C0Call18368View1(void*, void*) __asm__("func_80018368");
int Level35_7E6C0Call19194View1(void*, int) __asm__("func_80019194");
int Level35_7E6C0Call1A358View1(void*, int) __asm__("func_8001A358");
int Level35_7E6C0CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level35_7E6C0Call360A0View1(int, int, int) __asm__("func_800360A0");
int Level35_7E6C0AddAngle8View1(int, int) __asm__("func_8003617C");
int Level35_7E6C0Call36220View1(void*, void*, int, int) __asm__("func_80036220");
int Level35_7E6C0PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
void Level35_7E6C0Call3BE70View1(int) __asm__("func_8003BE70");
int Level35_7E6C0Call3BFC0View1(void*, int) __asm__("func_8003BFC0");
int Level35_7E6C0Call4E4E4View1() __asm__("func_8004E4E4");
int Level35_7E6C0PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level35_7E6C0BuildPackedAngleBasisMatrixView1(void*, void*, int) __asm__("func_8004EA90");
void Level35_7E6C0TransformVectorByBasisView1(void*, void*, void*) __asm__("func_8004ED6C");
int Level35_7E6C0MeasureVectorLengthView1(void*, int) __asm__("func_8004EDE8");
void Level35_7E6C0NormalizeVectorToLengthView1(void*, int) __asm__("func_8004EF04");
void Level35_7E6C0ScaleVectorRatioQ15View1(void*, int, int) __asm__("func_8004F08C");
void Level35_7E6C0ShiftVectorLeftView1(void*, int) __asm__("func_8004F0E8");
void Level35_7E6C0CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level35_7E6C0AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level35_7E6C0SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
void Level35_7E6C0PackVectorShiftRight2View1(void*, void*) __asm__("func_8004F504");
void Level35_7E6C0DeleteMobyView1(void*) __asm__("func_80055B18");
void Level35_7E6C0RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
int Level35_7E6C0Call56504View1() __asm__("func_80056504");
int Level35_7E6C0CallrandView1(void) __asm__("rand");
extern unsigned char Level35_7E6C0Data658A0View1 __asm__("D_800658A0");
extern unsigned char Level35_7E6C0Data65920View1 __asm__("D_80065920");
extern int Level35_7E6C0Data6C574View1 __asm__("D_8006C574");
extern int Level35_7E6C0Data6C578View1 __asm__("D_8006C578");
extern int Level35_7E6C0Data6C640View1 __asm__("D_8006C640");
extern int Level35_7E6C0Data6C648View1 __asm__("D_8006C648");
extern int Level35_7E6C0Data6C7E8View1 __asm__("D_8006C7E8");
extern unsigned char Level35_7E6C0Data6E020View1 __asm__("D_8006E020");
extern int Level35_7E6C0Data6FA3CView1 __asm__("D_8006FA3C");
extern int Level35_7E6C0Data70328View1 __asm__("D_80070328 + 0x250");
extern int Level35_7E6C0Data70328View2 __asm__("D_80070328");
extern unsigned char Level35_7E6C0Data74674View1 __asm__("D_level_35_80074674");
extern void* (*Level35_7E6C0DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level35_7E6C0DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
extern int (*Level35_7E6C0Data74398View1)() __asm__("unk_ovlheader_80074398");
void func_level_35_8007E6C0(void* ownerParameter) {
    register int framePrivateOrScalar16 __asm__("$16"), constantActorOrPoint17 __asm__("$17"),
        constantFrameOrIndex18 __asm__("$18"), owner19 __asm__("$19"),
        indexAddressOrRadius20 __asm__("$20"), privateRecord21 __asm__("$21"),
        indexAddressOrCounter22 __asm__("$22");
    register int resultOrField2 __asm__("$2"), fieldOrIntermediate3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7"), capturedHalf8 __asm__("$8"),
        capturedLow9 __asm__("$9");
    Level35_7E6C0CompleteProduct firstComplete, secondComplete, scaleXComplete, scaleYComplete,
        scaleZComplete, jitterXComplete, jitterYComplete, radius1XComplete, radius1YComplete,
        radius2XComplete, radius2YComplete, callback1Complete, callback2Complete;
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74;
        signed char sp78, sp79, sp7A;
        unsigned char reserved7B;
        int sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0,
            spB4, spB8, spBC, spC0, spC4;
    } originalFrame;
    int temp_v1_2;
    int var_v0;
    int temp_a0_2;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0;
    int temp_v1;
    int temp_v1_3;
    int temp_a0;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_6;
    int temp_a0_7;
    int temp_v0_3;
    int temp_v0_7;
    int temp_v0_9;
    owner19 = (int)ownerParameter;
    Level35_7E6C0Keep(owner19);
    resultOrField2 = Level35_7E6C0Data6FA3CView1;
    Level35_7E6C0Keep(resultOrField2);
    fieldOrIntermediate3 = 3;
    Level35_7E6C0Keep(fieldOrIntermediate3);
    privateRecord21 = Level35_7E6C0Field(owner19, int*, 0);
    argumentOrField5 = privateRecord21 + 52;
    if (resultOrField2 == fieldOrIntermediate3) {
        goto block_4;
    }
    temp_a0 = Level35_7E6C0Field(privateRecord21, int*, 0x50);
    if (temp_a0 == 0) {
        goto block_3;
    }
    Level35_7E6C0Call56504View1(temp_a0, argumentOrField5);
    Level35_7E6C0Field(privateRecord21, int*, 0x50) = 0;
block_3:
    MATCHING_KEEP(owner19);
    argumentOrField4 = owner19;
    goto block_110;
block_4:
    if (Level35_7E6C0Call36220View1((int)&Level35_7E6C0Data70328View2, argumentOrField5, 0, 0) ==
        0) {
        goto block_8;
    }
    temp_v0 = Level35_7E6C0Field(privateRecord21, unsigned short*, 2) | 1;
    Level35_7E6C0Field(privateRecord21, unsigned short*, 2) = temp_v0;
    if (!(temp_v0 & 2)) {
        goto block_10;
    }
    if (Level35_7E6C0Field(owner19, unsigned char*, 0x48) != 1) {
        goto block_11;
    }
    Level35_7E6C0Field(owner19, unsigned char*, 0x48) = 2U;
    goto block_11;
block_8:
    resultOrField2 = Level35_7E6C0Field(privateRecord21, short*, 2);
    Level35_7E6C0Keep(resultOrField2);
    fieldOrIntermediate3 = resultOrField2;
    if (!resultOrField2)
        goto block_10;
    Level35_7E6C0Keep(fieldOrIntermediate3);
    resultOrField2 = fieldOrIntermediate3 | 2;
    Level35_7E6C0Field(privateRecord21, unsigned short*, 2) = resultOrField2;
block_10:
block_11:
    Level35_7E6C0RefreshMobySpatialGridAndBasisView1(owner19, 5);
    if (Level35_7E6C0Field(privateRecord21, int*, 0x50) != 0) {
        goto block_16;
    }
    if ((unsigned int)(Level35_7E6C0Field(owner19, unsigned char*, 0x48) - 2) < 2U) {
        goto block_14;
    }
    Level35_7E6C0Field(privateRecord21, int*, 0x50) =
        Level35_7E6C0DataSpawnParticleView1(1, 0x32, owner19 + 0xC, 0);
block_14:
    if (Level35_7E6C0Field(privateRecord21, int*, 0x50) == 0) {
        goto block_17;
    }
block_16:
    Level35_7E6C0Field(Level35_7E6C0Field(privateRecord21, int*, 80), unsigned char*, 10) = 255;
    Level35_7E6C0CopyVectorView1(&originalFrame.sp10, owner19 + 0xC);
    originalFrame.sp18 = Level35_7E6C0Call1A358View1(&originalFrame.sp10, 0x3A98);
    Level35_7E6C0Field(Level35_7E6C0Field(privateRecord21, int*, 0x50), signed char*, 0x11) = 0xA;
    Level35_7E6C0PackVectorShiftRight2View1(Level35_7E6C0Field(privateRecord21, int*, 0x50) + 4,
                                            &originalFrame.sp10);
block_17:
    temp_v1 = Level35_7E6C0Field(owner19, unsigned char*, 0x48);
    if (temp_v1 >= 6U) {
        goto block_111;
    }
    switch (temp_v1) {
        case 0:
            temp_v0_3 = Level35_7E6C0Field(privateRecord21, int*, 4);
            if (temp_v0_3 == 0) {
                goto block_21;
            }
            Level35_7E6C0Field(temp_v0_3, short*, 2) = 0;
            Level35_7E6C0Field(privateRecord21, short*, 0) = 0x32C8;
        block_21:
            Level35_7E6C0Field(owner19, unsigned char*, 0x48) = 1U;
            return;
        case 1:
            temp_v1_2 = Level35_7E6C0Field(privateRecord21, short*, 0);
            if (temp_v1_2 >= 0x1389) {
                goto block_24;
            }
            resultOrField2 = 4;
            Level35_7E6C0Keep(resultOrField2);
            Level35_7E6C0Field(owner19, unsigned char*, 72) = resultOrField2;
            fieldOrIntermediate3 = Level35_7E6C0Data70328View1;
            Level35_7E6C0Field(fieldOrIntermediate3, unsigned char*, 72) = resultOrField2;
            Level35_7E6C0Field(Level35_7E6C0Data70328View1, signed char*, 0x49) = 0;
            return;
        block_24:
            if (Level35_7E6C0Field(privateRecord21, int*, 4) == 0) {
                goto block_111;
            }
            constantActorOrPoint17 = 0x10624DD3;
            constantFrameOrIndex18 = 13000;
            fieldOrIntermediate3 = constantFrameOrIndex18 - temp_v1_2;
            resultOrField2 = fieldOrIntermediate3 * 1500;
            firstComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)constantActorOrPoint17;
            __asm__("" : "=x"(firstComplete.full) : "0"(firstComplete.full));
            argumentOrField4 = Level35_7E6C0Field(owner19, int*, 20);
            __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(argumentOrField4));
            resultOrField2 >>= 31;
            argumentOrField4 -= 2500;
            __asm__(""
                    : "=x"(firstComplete.full), "=r"(argumentOrField4)
                    : "0"(firstComplete.full), "1"(argumentOrField4));
            capturedHalf8 = firstComplete.words.high;
            Level35_7E6C0Keep(capturedHalf8);
            fieldOrIntermediate3 = capturedHalf8 >> 9;
            fieldOrIntermediate3 -= resultOrField2;
            argumentOrField4 -= fieldOrIntermediate3;
            Level35_7E6C0Field(owner19, int*, 20) = argumentOrField4;
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) != 0) {
                goto block_27;
            }
            Level35_7E6C0Field(privateRecord21, int*, 0x58) =
                Level35_7E6C0PlayMobySoundEventView1(owner19, 0, 4);
        block_27:
            Level35_7E6C0SubtractVectorView1(&originalFrame.sp20, owner19 + 0xC,
                                             (int)&Level35_7E6C0Data70328View2);
            temp_v0_4 = Level35_7E6C0Call4E4E4View1(
                Level35_7E6C0Field(owner19, int*, 0x14) -
                ((Level35_7E6C0MeasureVectorLengthView1(&originalFrame.sp20, 1) -
                  Level35_7E6C0Field(privateRecord21, short*, 0)) *
                 0x14));
            resultOrField2 = temp_v0_4;
            fieldOrIntermediate3 = Level35_7E6C0Data6C648View1;
            callback1Complete.full =
                (long long)(int)resultOrField2 * (long long)(int)fieldOrIntermediate3;
            __asm__("" : "=x"(callback1Complete.full) : "0"(callback1Complete.full));
            argumentOrField4 = owner19;
            argumentOrField5 = Level35_7E6C0Field(privateRecord21, int*, 4);
            argumentOrField6 = privateRecord21 + 8;
            Level35_7E6C0Field(privateRecord21, int*, 8) = resultOrField2;
            fieldOrIntermediate3 = (int)Level35_7E6C0Data74398View1;
            __asm__(""
                    : "=x"(callback1Complete.full)
                    : "0"(callback1Complete.full), "r"(fieldOrIntermediate3));
            capturedHalf8 = (int)callback1Complete.words.low;
            Level35_7E6C0Keep(capturedHalf8);
            resultOrField2 = capturedHalf8 >> 6;
            Level35_7E6C0Field(privateRecord21, int*, 8) = resultOrField2;
            ((void (*)())fieldOrIntermediate3)(argumentOrField4, argumentOrField5,
                                               argumentOrField6);
            fieldOrIntermediate3 = Level35_7E6C0Field(privateRecord21, short*, 0);
            fieldOrIntermediate3 = constantFrameOrIndex18 - fieldOrIntermediate3;
            resultOrField2 = fieldOrIntermediate3 * 1500;
            secondComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)constantActorOrPoint17;
            __asm__("" : "=x"(secondComplete.full) : "0"(secondComplete.full));
            argumentOrField4 = Level35_7E6C0Field(owner19, int*, 20);
            argumentOrField4 += 2500;
            __asm__(""
                    : "=x"(secondComplete.full), "=r"(argumentOrField4)
                    : "0"(secondComplete.full), "1"(argumentOrField4));
            resultOrField2 >>= 31;
            capturedHalf8 = secondComplete.words.high;
            Level35_7E6C0Keep(capturedHalf8);
            fieldOrIntermediate3 = capturedHalf8 >> 9;
            fieldOrIntermediate3 -= resultOrField2;
            argumentOrField4 += fieldOrIntermediate3;
            Level35_7E6C0Field(owner19, int*, 20) = argumentOrField4;
            return;
        case 2:
            if (Level35_7E6C0Field(privateRecord21, int*, 0x2C) == 0) {
                goto block_111;
            }
            argumentOrField5 = (int)&Level35_7E6C0Data74674View1;
            MATCHING_KEEP(argumentOrField5);
            resultOrField2 = Level35_7E6C0Field(argumentOrField5, int*, 0);
            fieldOrIntermediate3 = Level35_7E6C0Field(argumentOrField5, int*, 4);
            argumentOrField4 = Level35_7E6C0Field(argumentOrField5, int*, 8);
            originalFrame.sp40 = resultOrField2;
            originalFrame.sp44 = fieldOrIntermediate3;
            originalFrame.sp48 = argumentOrField4;
            temp_v0_5 = Level35_7E6C0Call4E4E4View1(
                Level35_7E6C0Field(owner19, int*, 0x14) + 0x2710, argumentOrField5);
            framePrivateOrScalar16 = owner19 + 0xC;
            resultOrField2 = temp_v0_5;
            fieldOrIntermediate3 = Level35_7E6C0Data6C648View1;
            callback2Complete.full =
                (long long)(int)resultOrField2 * (long long)(int)fieldOrIntermediate3;
            __asm__(""
                    : "=x"(callback2Complete.full), "=r"(owner19)
                    : "0"(callback2Complete.full), "1"(owner19));
            constantActorOrPoint17 = (int)&originalFrame.sp30;
            argumentOrField4 = constantActorOrPoint17;
            framePrivateOrScalar16 = owner19 + 12;
            argumentOrField5 = framePrivateOrScalar16;
            __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(argumentOrField5));
            Level35_7E6C0Field(privateRecord21, int*, 8) = resultOrField2;
            __asm__(""
                    : "=x"(callback2Complete.full)
                    : "0"(callback2Complete.full), "r"(argumentOrField4), "r"(argumentOrField5),
                      "m"(Level35_7E6C0Field(privateRecord21, int*, 8))
                    : "memory");
            capturedHalf8 = (int)callback2Complete.words.low;
            Level35_7E6C0Keep(capturedHalf8);
            resultOrField2 = capturedHalf8 >> 6;
            Level35_7E6C0Field(privateRecord21, int*, 8) = resultOrField2;
            Level35_7E6C0CopyVectorView1(argumentOrField4, argumentOrField5);
            Level35_7E6C0Data74398View1(owner19, Level35_7E6C0Field(privateRecord21, int*, 0x2C),
                                        privateRecord21 + 8);
            Level35_7E6C0DataSpawnParticleView1(1, 0x3A, constantActorOrPoint17,
                                                &originalFrame.sp40);
            if (Level35_7E6C0Call18368View1(constantActorOrPoint17, framePrivateOrScalar16) != 0) {
                goto block_31;
            }
            if (Level35_7E6C0Call19194View1(framePrivateOrScalar16, 0x400) == 0) {
                goto block_52;
            }
        block_31:
            Level35_7E6C0CopyVectorView1(framePrivateOrScalar16, constantActorOrPoint17);
            MATCHING_KEEP_VOLATILE(constantActorOrPoint17);
            indexAddressOrRadius20 = 0;
            Level35_7E6C0Keep(indexAddressOrRadius20);
            constantFrameOrIndex18 = constantActorOrPoint17;
            Level35_7E6C0Keep(constantFrameOrIndex18);
            indexAddressOrCounter22 = 0;
        loop_32:
            if ((Level35_7E6C0Data6C578View1 - Level35_7E6C0Data6C574View1) < 0x15) {
                goto block_42;
            }
            constantActorOrPoint17 = Level35_7E6C0DataSpawnMobyView1(715, owner19);
            Level35_7E6C0Keep(constantActorOrPoint17);
            if (constantActorOrPoint17 == 0) {
                goto block_37;
            }
            resultOrField2 = 63;
            Level35_7E6C0Keep(resultOrField2);
            Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 76) = resultOrField2;
            resultOrField2 = 255;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(resultOrField2, "$4");
            argumentOrField4 = constantFrameOrIndex18;
            Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 60) = indexAddressOrRadius20;
            Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 74) = resultOrField2;
            framePrivateOrScalar16 = Level35_7E6C0Field(constantActorOrPoint17, int*, 0);
            Level35_7E6C0CopyVectorView1(argumentOrField4,
                                         Level35_7E6C0Field(privateRecord21, int*, 0x30) +
                                             indexAddressOrCounter22);
            Level35_7E6C0TransformVectorByBasisView1(owner19 + 0x20, constantFrameOrIndex18,
                                                     constantFrameOrIndex18);
            temp_a0_2 = constantActorOrPoint17 + 0xC;
            Level35_7E6C0AddVectorView1(temp_a0_2, temp_a0_2, constantFrameOrIndex18);
            Level35_7E6C0ScaleVectorRatioQ15View1(
                constantFrameOrIndex18,
                Level35_7E6C0MeasureVectorLengthView1(constantFrameOrIndex18, 1),
                Level35_7E6C0Field(privateRecord21, int*, 8));
            Level35_7E6C0Field(framePrivateOrScalar16, short*, 0) = (short)originalFrame.sp30;
            Level35_7E6C0Field(framePrivateOrScalar16, short*, 2) = (short)originalFrame.sp34;
            var_v0 = Level35_7E6C0Field((int)&originalFrame.sp38, short*, 0);
            if (var_v0 >= 0) {
                goto block_36;
            }
            var_v0 = -var_v0;
        block_36:
            Level35_7E6C0Field(framePrivateOrScalar16, short*, 4) = var_v0;
        block_37:
            indexAddressOrRadius20 += 1;
            indexAddressOrCounter22 += 0xC;
            if (indexAddressOrRadius20 < 3) {
                goto loop_32;
            }
            if ((Level35_7E6C0Data6C578View1 - Level35_7E6C0Data6C574View1) < 0x15) {
                goto block_42;
            }
            if (Level35_7E6C0Data6C7E8View1 < 0x7531) {
                goto block_42;
            }
            temp_v0_7 = Level35_7E6C0DataSpawnMobyView1(0x146, owner19);
            if (temp_v0_7 == 0) {
                goto block_42;
            }
            Level35_7E6C0Field(temp_v0_7, signed char*, 0x47) = 7;
        block_42:
            indexAddressOrRadius20 = 0;
            if ((Level35_7E6C0Data6C578View1 - Level35_7E6C0Data6C574View1) < 0x15) {
                goto block_49;
            }
            indexAddressOrCounter22 = (int)&Level35_7E6C0Data6E020View1;
            Level35_7E6C0Keep(indexAddressOrCounter22);
            constantFrameOrIndex18 = 0;
        loop_44:
            if (Level35_7E6C0Data6C7E8View1 < 0x7531) {
                goto block_49;
            }
            constantActorOrPoint17 = Level35_7E6C0DataSpawnMobyView1(0x21D, owner19);
            if (constantActorOrPoint17 == 0) {
                goto block_47;
            }
            framePrivateOrScalar16 = Level35_7E6C0PlanarHeadingLookupView1(
                Level35_7E6C0Field(owner19, int*, 0xC) -
                    Level35_7E6C0Field(indexAddressOrCounter22, int*, 0),
                Level35_7E6C0Field(owner19, int*, 0x10) -
                    Level35_7E6C0Field(indexAddressOrCounter22, int*, 4),
                0);
            Level35_7E6C0Field(constantActorOrPoint17, signed char*, 0x46) =
                (signed char)((framePrivateOrScalar16 += 64) +
                              (Level35_7E6C0CallrandView1() & 0x1F));
            Level35_7E6C0Field(constantActorOrPoint17, signed char*, 0x45) =
                (signed char)((constantFrameOrIndex18 + (Level35_7E6C0CallrandView1() & 0x1E)) -
                              0xF);
            Level35_7E6C0Field(constantActorOrPoint17, signed char*, 0x47) = 8;
            Level35_7E6C0Field(constantActorOrPoint17, signed char*, 0x4C) = 0x2A;
        block_47:
            indexAddressOrRadius20 += 1;
            constantFrameOrIndex18 += 0x33;
            if (indexAddressOrRadius20 >= 5) {
                goto block_49;
            }
            if ((Level35_7E6C0Data6C578View1 - Level35_7E6C0Data6C574View1) >= 0x15) {
                goto loop_44;
            }
        block_49:
            temp_a0_3 = Level35_7E6C0Field(privateRecord21, int*, 0x50);
            if (temp_a0_3 == 0) {
                goto block_51;
            }
            Level35_7E6C0Call56504View1(temp_a0_3);
            Level35_7E6C0Field(privateRecord21, int*, 0x50) = 0;
        block_51:
            Level35_7E6C0PlayMobySoundEventView1(owner19, 1, 1);
            Level35_7E6C0Field(owner19, signed char*, 0x41) = 0;
            Level35_7E6C0Field(owner19, signed char*, 0x4C) = 0;
            Level35_7E6C0Field(owner19, signed char*, 0x4D) = 0;
            Level35_7E6C0Field(privateRecord21, short*, 0) = 0x78;
            Level35_7E6C0Field(owner19, unsigned char*, 0x48) = 3U;
            return;
        block_52:
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) != 0) {
                goto block_111;
            }
            Level35_7E6C0Field(privateRecord21, int*, 0x58) =
                Level35_7E6C0PlayMobySoundEventView1(owner19, 0, 4);
            return;
        case 3:
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) == 0) {
                goto block_58;
            }
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) == 0) {
                goto block_57;
            }
            Level35_7E6C0Call3BE70View1(Level35_7E6C0Field(privateRecord21, int*, 0x58));
        block_57:
            Level35_7E6C0Field(privateRecord21, int*, 0x58) = -1;
        block_58:
            if (Level35_7E6C0Field(privateRecord21, short*, 0) < 0x51) {
                goto block_67;
            }
            constantFrameOrIndex18 = 0;
            indexAddressOrRadius20 = (int)&originalFrame.sp60;
            constantActorOrPoint17 = (int)&originalFrame.sp40;
            framePrivateOrScalar16 = (int)&originalFrame.sp50;
            Level35_7E6C0Keep(indexAddressOrRadius20);
            Level35_7E6C0Keep(constantActorOrPoint17);
            Level35_7E6C0Keep(framePrivateOrScalar16);
        loop_60:
            originalFrame.sp78 = 0;
            originalFrame.sp79 = Level35_7E6C0CallrandView1();
            originalFrame.sp7A = Level35_7E6C0CallrandView1();
            Level35_7E6C0BuildPackedAngleBasisMatrixView1(&originalFrame.sp78,
                                                          indexAddressOrRadius20, 0);
            constantFrameOrIndex18 += 1;
            originalFrame.sp40 = (Level35_7E6C0CallrandView1() & 0x1F) + 0x64;
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0;
            Level35_7E6C0TransformVectorByBasisView1(indexAddressOrRadius20, constantActorOrPoint17,
                                                     constantActorOrPoint17);
            Level35_7E6C0CopyVectorView1(framePrivateOrScalar16, constantActorOrPoint17);
            Level35_7E6C0ShiftVectorLeftView1(framePrivateOrScalar16, 2);
            Level35_7E6C0AddVectorView1(framePrivateOrScalar16, framePrivateOrScalar16,
                                        owner19 + 0xC);
            Level35_7E6C0DataSpawnParticleView1(1, 0x3A, framePrivateOrScalar16,
                                                constantActorOrPoint17);
            if (constantFrameOrIndex18 < 4) {
                goto loop_60;
            }
            if (Level35_7E6C0Data6C640View1 & 1) {
                goto block_67;
            }
            if ((Level35_7E6C0Data6C578View1 - Level35_7E6C0Data6C574View1) < 0x15) {
                goto block_67;
            }
            if (Level35_7E6C0Data6C7E8View1 < 0x7531) {
                goto block_67;
            }
            temp_v0_9 = Level35_7E6C0DataSpawnMobyView1(0x1E2, owner19);
            if (temp_v0_9 == 0) {
                goto block_66;
            }
            Level35_7E6C0Field(temp_v0_9, signed char*, 0x4C) = 0x2A;
            Level35_7E6C0Field(temp_v0_9, signed char*, 0x47) = 0xA;
        block_66:
        block_67:
            if (Level35_7E6C0CountTimerDownView1(privateRecord21, 2) == 0) {
                goto block_111;
            }
            Level35_7E6C0Field(privateRecord21, short*, 0) = 0x2D;
            Level35_7E6C0Field(owner19, unsigned char*, 0x48) = 5U;
            return;
        case 4:
            resultOrField2 = Level35_7E6C0Data70328View1;
            Level35_7E6C0Keep(resultOrField2);
            indexAddressOrRadius20 = (int)&Level35_7E6C0Data70328View1;
            MATCHING_KEEP(indexAddressOrRadius20);
            resultOrField2 = Level35_7E6C0Field(resultOrField2, int*, 0);
            fieldOrIntermediate3 = Level35_7E6C0Field(indexAddressOrRadius20, int*, 0);
            constantActorOrPoint17 = Level35_7E6C0Field(resultOrField2, int*, 40);
            if (fieldOrIntermediate3 == 0) {
                goto block_111;
            }
            temp_v1_3 = Level35_7E6C0Field(owner19, unsigned char*, 0x49);
            if (temp_v1_3 == 1) {
                goto block_83;
            }
            if ((int)temp_v1_3 >= 2) {
                goto block_74;
            }
            if (temp_v1_3 == 0) {
                goto block_77;
            }
            return;
        block_74:
            if (temp_v1_3 == 2) {
                goto block_90;
            }
            if (temp_v1_3 == 3) {
                goto block_100;
            }
            return;
        block_77:
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) != 0) {
                goto block_79;
            }
            Level35_7E6C0Field(privateRecord21, int*, 0x58) =
                Level35_7E6C0PlayMobySoundEventView1(owner19, 0, 4);
        block_79:
            framePrivateOrScalar16 = (int)&originalFrame.sp80;
            Level35_7E6C0CopyVectorView1(framePrivateOrScalar16, indexAddressOrRadius20 - 592);
            constantActorOrPoint17 = (int)&originalFrame.sp90;
            Level35_7E6C0Keep(constantActorOrPoint17);
            argumentOrField4 = constantActorOrPoint17;
            Level35_7E6C0Keep(argumentOrField4);
            constantFrameOrIndex18 = owner19 + 12;
            originalFrame.sp88 += 0xBB8;
            Level35_7E6C0SubtractVectorView1(argumentOrField4, constantFrameOrIndex18,
                                             framePrivateOrScalar16);
            indexAddressOrRadius20 =
                Level35_7E6C0MeasureVectorLengthView1(constantActorOrPoint17, 1);
            if (indexAddressOrRadius20 < 1000) {
                resultOrField2 = 1;
                goto block_99;
            }
            resultOrField2 = indexAddressOrRadius20 + 1000;
            indexAddressOrRadius20 = resultOrField2 >> 3;
            resultOrField2 = Level35_7E6C0PlanarHeadingLookupView1(
                originalFrame.sp80 - Level35_7E6C0Field(owner19, int*, 12),
                originalFrame.sp84 - Level35_7E6C0Field(owner19, int*, 16), 0);
            resultOrField2 *= 2;
            resultOrField2 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data65920View1, short*, resultOrField2);
            Level35_7E6C0Keep(resultOrField2);
            radius1XComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)indexAddressOrRadius20;
            __asm__("" : "=x"(radius1XComplete.full) : "0"(radius1XComplete.full));
            argumentOrField6 = 0;
            fieldOrIntermediate3 = originalFrame.sp80;
            __asm__(""
                    : "=x"(radius1XComplete.full)
                    : "0"(radius1XComplete.full), "r"(argumentOrField6), "r"(fieldOrIntermediate3));
            capturedHalf8 = (int)radius1XComplete.words.low;
            Level35_7E6C0Keep(capturedHalf8);
            resultOrField2 = capturedHalf8 >> 12;
            originalFrame.sp90 = resultOrField2;
            resultOrField2 = Level35_7E6C0PlanarHeadingLookupView1(
                fieldOrIntermediate3 - Level35_7E6C0Field(owner19, int*, 12),
                originalFrame.sp84 - Level35_7E6C0Field(owner19, int*, 16), argumentOrField6);
            resultOrField2 *= 2;
            resultOrField2 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data658A0View1, short*, resultOrField2);
            Level35_7E6C0Keep(resultOrField2);
            radius1YComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)indexAddressOrRadius20;
            __asm__("" : "=x"(radius1YComplete.full) : "0"(radius1YComplete.full));
            argumentOrField4 = constantFrameOrIndex18;
            argumentOrField5 = argumentOrField4;
            argumentOrField6 = constantActorOrPoint17;
            originalFrame.sp98 = 0;
            __asm__(""
                    : "=x"(radius1YComplete.full)
                    : "0"(radius1YComplete.full), "m"(originalFrame.sp98)
                    : "memory");
            capturedHalf8 = (int)radius1YComplete.words.low;
            Level35_7E6C0Keep(capturedHalf8);
            resultOrField2 = capturedHalf8 >> 12;
            originalFrame.sp94 = resultOrField2;
            Level35_7E6C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = 0;
            argumentOrField6 = 49;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentOrField4, argumentOrField6, "memory");
            resultOrField2 = originalFrame.sp88;
            MATCHING_KEEP(resultOrField2);
            fieldOrIntermediate3 = Level35_7E6C0Field(owner19, int*, 20);
            resultOrField2 -= fieldOrIntermediate3;
            resultOrField2 >>= 3;
            fieldOrIntermediate3 += resultOrField2;
            Level35_7E6C0Field(owner19, int*, 20) = fieldOrIntermediate3;
            Level35_7E6C0Field(owner19, unsigned char*, 0x44) = Level35_7E6C0Call360A0View1(
                argumentOrField4, Level35_7E6C0Field(owner19, unsigned char*, 68),
                argumentOrField6);
            Level35_7E6C0Field(owner19, unsigned char*, 0x45) = Level35_7E6C0Call360A0View1(
                0, Level35_7E6C0Field(owner19, unsigned char*, 0x45), 0x31);
            resultOrField2 = indexAddressOrRadius20 < 1001;
            if (resultOrField2) {
                goto block_82;
            }
            Level35_7E6C0Field(owner19, unsigned char*, 0x46) =
                Level35_7E6C0PlanarHeadingLookupView1(
                    originalFrame.sp80 - Level35_7E6C0Field(owner19, int*, 0xC),
                    originalFrame.sp84 - Level35_7E6C0Field(owner19, int*, 0x10), 0);
        block_82:
            Level35_7E6C0RefreshMobySpatialGridAndBasisView1(owner19, 4);
            return;
        block_83:
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) != 0) {
                goto block_85;
            }
            Level35_7E6C0Field(privateRecord21, int*, 0x58) =
                Level35_7E6C0PlayMobySoundEventView1(owner19, 0, 4);
        block_85:
            resultOrField2 = Level35_7E6C0AddAngle8View1(
                Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 70), 16);
            resultOrField2 *= 2;
            argumentOrField4 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data65920View1, short*, resultOrField2);
            resultOrField2 = (argumentOrField4 * 2375) >> 10;
            originalFrame.sp90 = resultOrField2;
            resultOrField2 = Level35_7E6C0AddAngle8View1(
                Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 70), 16);
            framePrivateOrScalar16 = (int)&originalFrame.sp90;
            argumentOrField4 = framePrivateOrScalar16;
            Level35_7E6C0Keep(argumentOrField4);
            argumentOrField5 = framePrivateOrScalar16;
            Level35_7E6C0Keep(argumentOrField5);
            constantActorOrPoint17 += 12;
            argumentOrField6 = constantActorOrPoint17;
            resultOrField2 *= 2;
            argumentOrField7 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data658A0View1, short*, resultOrField2);
            resultOrField2 = 7000;
            originalFrame.sp98 = resultOrField2;
            resultOrField2 = (argumentOrField7 * 2375) >> 10;
            originalFrame.sp94 = resultOrField2;
            Level35_7E6C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level35_7E6C0Call13AE4View1(framePrivateOrScalar16, constantActorOrPoint17);
            if (Level35_7E6C0CountTimerDownView1(privateRecord21, 2) == 0) {
                goto block_88;
            }
            if (Level35_7E6C0Field((int)&Level35_7E6C0Data70328View2, int*, 0xB8) != 0) {
                goto block_89;
            }
            Level35_7E6C0Field(Level35_7E6C0Data70328View1, signed char*, 0x49) = 1;
            Level35_7E6C0Field(owner19, unsigned char*, 0x49) = 2U;
            Level35_7E6C0Field(privateRecord21, int*, 0x54) =
                Level35_7E6C0DataSpawnMobyView1(0x203, owner19);
        block_88:
        block_89:
            framePrivateOrScalar16 = (int)&originalFrame.sp80;
            Level35_7E6C0CopyVectorView1(framePrivateOrScalar16, (int)&Level35_7E6C0Data70328View2);
            constantActorOrPoint17 = (int)&originalFrame.sp90;
            Level35_7E6C0Keep(constantActorOrPoint17);
            argumentOrField4 = constantActorOrPoint17;
            Level35_7E6C0Keep(argumentOrField4);
            constantFrameOrIndex18 = owner19 + 12;
            originalFrame.sp88 += 0xDAC;
            Level35_7E6C0SubtractVectorView1(argumentOrField4, constantFrameOrIndex18,
                                             framePrivateOrScalar16);
            resultOrField2 = Level35_7E6C0MeasureVectorLengthView1(constantActorOrPoint17, 1);
            resultOrField2 += 1000;
            indexAddressOrRadius20 = resultOrField2 >> 3;
            resultOrField2 = Level35_7E6C0PlanarHeadingLookupView1(
                originalFrame.sp80 - Level35_7E6C0Field(owner19, int*, 12),
                originalFrame.sp84 - Level35_7E6C0Field(owner19, int*, 16), 0);
            resultOrField2 *= 2;
            resultOrField2 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data65920View1, short*, resultOrField2);
            Level35_7E6C0Keep(resultOrField2);
            radius2XComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)indexAddressOrRadius20;
            __asm__("" : "=x"(radius2XComplete.full) : "0"(radius2XComplete.full));
            argumentOrField6 = 0;
            fieldOrIntermediate3 = originalFrame.sp80;
            __asm__(""
                    : "=x"(radius2XComplete.full)
                    : "0"(radius2XComplete.full), "r"(argumentOrField6), "r"(fieldOrIntermediate3));
            capturedHalf8 = (int)radius2XComplete.words.low;
            Level35_7E6C0Keep(capturedHalf8);
            resultOrField2 = capturedHalf8 >> 12;
            originalFrame.sp90 = resultOrField2;
            resultOrField2 = Level35_7E6C0PlanarHeadingLookupView1(
                fieldOrIntermediate3 - Level35_7E6C0Field(owner19, int*, 12),
                originalFrame.sp84 - Level35_7E6C0Field(owner19, int*, 16), argumentOrField6);
            resultOrField2 *= 2;
            resultOrField2 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data658A0View1, short*, resultOrField2);
            Level35_7E6C0Keep(resultOrField2);
            radius2YComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)indexAddressOrRadius20;
            __asm__("" : "=x"(radius2YComplete.full) : "0"(radius2YComplete.full));
            argumentOrField4 = constantFrameOrIndex18;
            argumentOrField5 = argumentOrField4;
            argumentOrField6 = constantActorOrPoint17;
            originalFrame.sp98 = 0;
            __asm__(""
                    : "=x"(radius2YComplete.full)
                    : "0"(radius2YComplete.full), "m"(originalFrame.sp98)
                    : "memory");
            capturedHalf8 = (int)radius2YComplete.words.low;
            Level35_7E6C0Keep(capturedHalf8);
            resultOrField2 = capturedHalf8 >> 12;
            originalFrame.sp94 = resultOrField2;
            Level35_7E6C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = 0;
            argumentOrField6 = 64;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentOrField4, argumentOrField6, "memory");
            resultOrField2 = originalFrame.sp88;
            MATCHING_KEEP(resultOrField2);
            fieldOrIntermediate3 = Level35_7E6C0Field(owner19, int*, 20);
            resultOrField2 -= fieldOrIntermediate3;
            resultOrField2 >>= 3;
            fieldOrIntermediate3 += resultOrField2;
            Level35_7E6C0Field(owner19, int*, 20) = fieldOrIntermediate3;
            Level35_7E6C0Field(owner19, unsigned char*, 0x44) = Level35_7E6C0Call360A0View1(
                argumentOrField4, Level35_7E6C0Field(owner19, unsigned char*, 68),
                argumentOrField6);
            Level35_7E6C0Field(owner19, unsigned char*, 0x45) = Level35_7E6C0Call360A0View1(
                0, Level35_7E6C0Field(owner19, unsigned char*, 0x45), 0x40);
            Level35_7E6C0RefreshMobySpatialGridAndBasisView1(owner19, 4);
            return;
        block_90:
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) != 0) {
                goto block_92;
            }
            Level35_7E6C0Field(privateRecord21, int*, 0x58) =
                Level35_7E6C0PlayMobySoundEventView1(owner19, 0, 4);
        block_92:
            temp_a0_4 = Level35_7E6C0Field(privateRecord21, int*, 0x54);
            if (temp_a0_4 == 0) {
                goto block_94;
            }
            Level35_7E6C0PlayMobySoundEventView1(temp_a0_4, 0, 0);
        block_94:
            resultOrField2 = Level35_7E6C0AddAngle8View1(
                Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 70), 16);
            resultOrField2 *= 2;
            argumentOrField4 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data65920View1, short*, resultOrField2);
            indexAddressOrCounter22 = 0;
            resultOrField2 = (argumentOrField4 * 2375) >> 10;
            originalFrame.sp90 = resultOrField2;
            resultOrField2 = Level35_7E6C0AddAngle8View1(
                Level35_7E6C0Field(constantActorOrPoint17, unsigned char*, 70), 16);
            framePrivateOrScalar16 = (int)&originalFrame.sp90;
            argumentOrField4 = framePrivateOrScalar16;
            Level35_7E6C0Keep(argumentOrField4);
            argumentOrField5 = framePrivateOrScalar16;
            Level35_7E6C0Keep(argumentOrField5);
            constantActorOrPoint17 += 12;
            argumentOrField6 = constantActorOrPoint17;
            resultOrField2 *= 2;
            argumentOrField7 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data658A0View1, short*, resultOrField2);
            resultOrField2 = 7000;
            originalFrame.sp98 = resultOrField2;
            resultOrField2 = (argumentOrField7 * 2375) >> 10;
            originalFrame.sp94 = resultOrField2;
            Level35_7E6C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level35_7E6C0Call13AE4View1(framePrivateOrScalar16, constantActorOrPoint17);
            constantFrameOrIndex18 = (int)&originalFrame.spA0;
            MATCHING_KEEP_VOLATILE(constantFrameOrIndex18);
            resultOrField2 = Level35_7E6C0Field(owner19, unsigned char*, 70);
            MATCHING_KEEP2(owner19, resultOrField2);
            constantActorOrPoint17 = owner19 + 12;
            Level35_7E6C0Keep(constantActorOrPoint17);
            resultOrField2 *= 2;
            fieldOrIntermediate3 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data65920View1, short*, resultOrField2);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(fieldOrIntermediate3, "$4");
            argumentOrField4 = constantActorOrPoint17;
            Level35_7E6C0Keep(argumentOrField4);
            resultOrField2 = (fieldOrIntermediate3 * 25) >> 10;
            originalFrame.sp90 = resultOrField2;
            resultOrField2 = Level35_7E6C0Field(owner19, unsigned char*, 70);
            MATCHING_KEEP_VOLATILE_CLOBBER(resultOrField2, "$5");
            argumentOrField5 = framePrivateOrScalar16;
            Level35_7E6C0Keep(argumentOrField5);
            resultOrField2 *= 2;
            fieldOrIntermediate3 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data658A0View1, short*, resultOrField2);
            argumentOrField6 = constantActorOrPoint17;
            originalFrame.sp98 = 0;
            __asm__ volatile("" ::"m"(originalFrame.sp98) : "memory");
            resultOrField2 = (fieldOrIntermediate3 * 25) >> 10;
            originalFrame.sp94 = resultOrField2;
            Level35_7E6C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level35_7E6C0Field(owner19, int*, 0x14) =
                (int)(Level35_7E6C0Field(owner19, int*, 0x14) + 0x64);
            Level35_7E6C0Field(owner19, unsigned char*, 0x44) = Level35_7E6C0Call360A0View1(
                0, Level35_7E6C0Field(owner19, unsigned char*, 0x44), 0x80);
            Level35_7E6C0Field(owner19, unsigned char*, 0x45) = Level35_7E6C0Call360A0View1(
                0, Level35_7E6C0Field(owner19, unsigned char*, 0x45), 0x80);
            Level35_7E6C0RefreshMobySpatialGridAndBasisView1(owner19, 4);
            Level35_7E6C0SubtractVectorView1(framePrivateOrScalar16, indexAddressOrRadius20 - 0x250,
                                             constantActorOrPoint17);
            indexAddressOrRadius20 =
                Level35_7E6C0MeasureVectorLengthView1(framePrivateOrScalar16, 1);
            Level35_7E6C0NormalizeVectorToLengthView1(framePrivateOrScalar16, 0x400);
            MATCHING_KEEP(owner19);
        loop_95:
            indexAddressOrCounter22 += 1;
            framePrivateOrScalar16 = Level35_7E6C0CallrandView1();
            resultOrField2 = Level35_7E6C0CallrandView1();
            argumentOrField4 = framePrivateOrScalar16 % indexAddressOrRadius20;
            fieldOrIntermediate3 = resultOrField2 % indexAddressOrRadius20;
            argumentOrField4 += fieldOrIntermediate3;
            resultOrField2 = (unsigned int)argumentOrField4 >> 31;
            argumentOrField4 += resultOrField2;
            resultOrField2 = originalFrame.sp90;
            framePrivateOrScalar16 = argumentOrField4 >> 1;
            scaleXComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)framePrivateOrScalar16;
            __asm__("" : "=x"(scaleXComplete.full) : "0"(scaleXComplete.full));
            capturedLow9 = (int)scaleXComplete.words.low;
            resultOrField2 = originalFrame.sp94;
            __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(capturedLow9));
            scaleYComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)framePrivateOrScalar16;
            __asm__("" : "=x"(scaleYComplete.full) : "0"(scaleYComplete.full));
            fieldOrIntermediate3 = (int)scaleYComplete.words.low;
            resultOrField2 = originalFrame.sp98;
            __asm__("" : "=r"(resultOrField2) : "0"(resultOrField2), "r"(fieldOrIntermediate3));
            scaleZComplete.full =
                (long long)(int)resultOrField2 * (long long)(int)framePrivateOrScalar16;
            __asm__("" : "=x"(scaleZComplete.full) : "0"(scaleZComplete.full));
            resultOrField2 = capturedLow9 >> 10;
            originalFrame.spA0 = resultOrField2;
            resultOrField2 = fieldOrIntermediate3 >> 10;
            originalFrame.spA4 = resultOrField2;
            __asm__(""
                    : "=x"(scaleZComplete.full)
                    : "0"(scaleZComplete.full), "m"(originalFrame.spA4)
                    : "memory");
            argumentOrField4 = (int)scaleZComplete.words.low;
            Level35_7E6C0Keep(argumentOrField4);
            resultOrField2 = argumentOrField4 >> 10;
            originalFrame.spA8 = resultOrField2;
            resultOrField2 = Level35_7E6C0CallrandView1();
            framePrivateOrScalar16 = resultOrField2 & 63;
            resultOrField2 = Level35_7E6C0CallrandView1();
            resultOrField2 &= 255;
            resultOrField2 *= 2;
            fieldOrIntermediate3 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data65920View1, short*, resultOrField2);
            Level35_7E6C0Keep(fieldOrIntermediate3);
            jitterXComplete.full =
                (long long)(int)framePrivateOrScalar16 * (long long)(int)fieldOrIntermediate3;
            __asm__("" : "=x"(jitterXComplete.full) : "0"(jitterXComplete.full));
            fieldOrIntermediate3 = originalFrame.spA0;
            __asm__(""
                    : "=x"(jitterXComplete.full)
                    : "0"(jitterXComplete.full), "r"(fieldOrIntermediate3));
            capturedLow9 = (int)jitterXComplete.words.low;
            Level35_7E6C0Keep(capturedLow9);
            argumentOrField4 = capturedLow9 >> 12;
            fieldOrIntermediate3 += argumentOrField4;
            originalFrame.spA0 = fieldOrIntermediate3;
            resultOrField2 =
                Level35_7E6C0Field((int)&Level35_7E6C0Data658A0View1, short*, resultOrField2);
            Level35_7E6C0Keep(resultOrField2);
            jitterYComplete.full =
                (long long)(int)framePrivateOrScalar16 * (long long)(int)resultOrField2;
            __asm__("" : "=x"(jitterYComplete.full) : "0"(jitterYComplete.full));
            argumentOrField5 = constantFrameOrIndex18;
            MATCHING_KEEP(owner19);
            argumentOrField6 = owner19 + 12;
            argumentOrField4 = constantFrameOrIndex18;
            resultOrField2 = originalFrame.spA4;
            __asm__(""
                    : "=x"(jitterYComplete.full)
                    : "0"(jitterYComplete.full), "r"(argumentOrField4), "r"(argumentOrField5),
                      "r"(argumentOrField6), "r"(resultOrField2));
            fieldOrIntermediate3 = (int)jitterYComplete.words.low;
            Level35_7E6C0Keep(fieldOrIntermediate3);
            fieldOrIntermediate3 >>= 12;
            resultOrField2 += fieldOrIntermediate3;
            originalFrame.spA4 = resultOrField2;
            Level35_7E6C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level35_7E6C0DataSpawnParticleView1(1, 0x42, constantFrameOrIndex18, 1);
            if (indexAddressOrCounter22 < 0xA) {
                goto loop_95;
            }
            MATCHING_KEEP(owner19);
            temp_a0_6 = Level35_7E6C0Field(privateRecord21, int*, 84);
            if (temp_a0_6 == 0) {
                goto block_98;
            }
            Level35_7E6C0CopyVectorView1(temp_a0_6 + 12, owner19 + 12);
        block_98:
            resultOrField2 = Level35_7E6C0Data70328View1;
            resultOrField2 = Level35_7E6C0Field(resultOrField2, unsigned char*, 77);
            if (resultOrField2 != 0) {
                goto block_111;
            }
            resultOrField2 = 3;
        block_99:
            Level35_7E6C0Field(owner19, unsigned char*, 73) = resultOrField2;
            Level35_7E6C0Field(privateRecord21, short*, 0) = 0x2D;
            return;
        block_100:
            if (Level35_7E6C0CountTimerDownView1(privateRecord21, 2) == 0) {
                goto block_111;
            }
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) == 0) {
                goto block_105;
            }
            if (Level35_7E6C0Call3BFC0View1(owner19,
                                            Level35_7E6C0Field(privateRecord21, int*, 0x58)) == 0) {
                goto block_104;
            }
            Level35_7E6C0Call3BE70View1(Level35_7E6C0Field(privateRecord21, int*, 0x58));
        block_104:
            Level35_7E6C0Field(privateRecord21, int*, 0x58) = -1;
        block_105:
            Level35_7E6C0Field(Level35_7E6C0Data70328View1, signed char*, 0x49) = 2;
            temp_a0_7 = Level35_7E6C0Field(privateRecord21, int*, 0x54);
            if (temp_a0_7 == 0) {
                goto block_107;
            }
            Level35_7E6C0DeleteMobyView1(temp_a0_7);
        block_107:
            __asm__ volatile("" : "=r"(owner19) : "0"(owner19), "r"(privateRecord21));
            argumentOrField4 = owner19;
            goto block_110;
        case 5:
            resultOrField2 = Level35_7E6C0CountTimerDownView1(privateRecord21, 2);
            argumentOrField4 = owner19;
            if (!resultOrField2) {
                goto block_111;
            }
            fieldOrIntermediate3 = Level35_7E6C0Data70328View1;
            resultOrField2 = 2;
            Level35_7E6C0Field(fieldOrIntermediate3, unsigned char*, 73) = resultOrField2;
        block_110:
            Level35_7E6C0DeleteMobyView1(argumentOrField4);
        block_111:
            return;
        default:
            goto block_111;
    }
}
#undef Level35_7E6C0Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Controller7F80CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))


int Controller7F80C_func_80018368() __asm__("func_80018368");                 /* extern */
int Controller7F80C_func_80019194() __asm__("func_80019194");                 /* extern */
int Controller7F80C_func_8003BA00() __asm__("func_8003BA00");                 /* extern */
int Controller7F80CNormalizeVectorToLength() __asm__("func_8004EF04");        /* extern */
int Controller7F80CSubtractVector() __asm__("func_8004F1C8");                 /* extern */
int Controller7F80CDeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7F80CRefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7F80CInterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
int Controller7F80C_rand() __asm__("rand");                                   /* extern */
extern short Controller7F80C_D_800658A0 __asm__("D_800658A0");
extern short Controller7F80C_D_80065920 __asm__("D_80065920");
extern int Controller7F80C_D_8006C550 __asm__("D_8006C550");
extern int Controller7F80C_D_8006C640 __asm__("D_8006C640");
extern int Controller7F80C_D_8006E524 __asm__("D_8006E524");
extern int Controller7F80C_D_8006FA3C __asm__("D_8006FA3C");
extern Moby* Target70328 __asm__("D_80070328+0x250");
extern unsigned char Controller7F80C_D_80070328 __asm__("D_80070328");

void func_level_35_8007F80C(Moby* incomingMoby) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        char pad_1c[4];
        int sp20;
        int sp24;
        int sp28;
        char pad_2c[4];
        int sp30;
        int sp34;
        int sp38;
        char pad_3c[4];
        Vector3D sp40;
        char pad_4c[4];
        int sp50;
        int sp54;
        int sp58;
        char pad_5c[4];
    } frame;

    register Moby* moby __asm__("$17") = incomingMoby;

    register Moby* child18 __asm__("$18");
    register Vector3D* vector22 __asm__("$22");
    register Vector3D* vector21 __asm__("$21");
    register Vector3D* ownerPosition16 __asm__("$16");
    register Vector3D* ownerPosition16Again __asm__("$16");
    register Vector3D* position19 __asm__("$19");
    register int angle16 __asm__("$16");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int value4 __asm__("$4");
    register int value5 __asm__("$5");
    register Vector3D* call4 __asm__("$4");
    register Vector3D* call5 __asm__("$5");
    register Vector3D* vector20 __asm__("$20");
    register int tableByteOffset3 __asm__("$3");
    register int attempt20 __asm__("$20");
    unsigned short* recordTag7;
    unsigned char state4;
    register void* childTag16 __asm__("$16");
    register void* tag18 __asm__("$18");
    void* record;

    MATCHING_KEEP(moby);
    tag18 = moby->mobyTag;
    value2 = Controller7F80C_D_8006FA3C;
    MATCHING_KEEP(value2);
    if (value2 != 3) {
        Controller7F80CDeleteMoby();
    }
    state4 = moby->state;
    switch (state4) {
        case 0:
            if (Controller7F80CField(&Controller7F80C_D_80070328, int*, 0x138) == moby) {
                moby->state = 1;
                return;
            }
            return;
        case 1:
            record = (Controller7F80CField(tag18, int*, 0) * 0x58) + Controller7F80C_D_8006C550;
            recordTag7 = Controller7F80CField(record, unsigned short**, 0);
            attempt20 = 0;
            if (Controller7F80CField(record, unsigned char*, 0x48) == state4) {
                *recordTag7 -= 0x5DC;
                Controller7F80C_D_8006E524 = 0xF;
                Controller7F80CField(&Controller7F80C_D_80070328, int*, 0x24) =
                    (int)(Controller7F80CField(&Controller7F80C_D_80070328, int*, 0x24) | 1);
                func_8003BABC(moby, 0, 0);
                __asm__ __volatile__("" : "=r"(attempt20));
                attempt20 = 0;
                MATCHING_KEEP_GNU_VOLATILE(attempt20);
            }
            vector22 = (Vector3D*)&frame.sp20;
            vector21 = (Vector3D*)&frame.sp30;
        spawnLoop:
            angle16 =
                func_8004E880(moby->position.x - Controller7F80CField(Target70328, int*, 0xC),
                              moby->position.y - Controller7F80CField(Target70328, int*, 0x10), 0);
            child18 = SpawnMoby(0x80, moby);
            MATCHING_KEEP(child18);
            tableByteOffset3 = angle16 * 2;
            if (child18 != 0) {
                value2 =
                    Controller7F80CField(&Controller7F80C_D_80065920, short*, tableByteOffset3);
                MATCHING_KEEP(value2);
                childTag16 = child18->mobyTag;
                frame.sp10 = value2 >> 4;
                value2 =
                    Controller7F80CField(&Controller7F80C_D_800658A0, short*, tableByteOffset3);
                MATCHING_KEEP(value2);
                frame.sp18 = 0;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                frame.sp14 = value2 >> 4;
                frame.sp20 = (Controller7F80C_rand() & 0x7F) - 0x40;
                frame.sp24 = (Controller7F80C_rand() & 0x7F) - 0x40;
                frame.sp28 = Controller7F80C_rand() & 0x7F;
                func_8004F194((Vector3D*)&frame.sp10, (Vector3D*)&frame.sp10, vector22);
                Controller7F80CInterpolateMobyVertex(moby, attempt20, vector22);
                position19 = &child18->position;
                func_8004F194(position19, (Vector3D*)&frame.sp10, vector22);
                child18->size = 0xC8;
                child18->unknownCollision = 0;
                Controller7F80CSubtractVector(vector21, position19, &Controller7F80C_D_80070328);
                Controller7F80CNormalizeVectorToLength(vector21, 0x400);
                Controller7F80CNormalizeVectorToLength(&frame.sp10, 0x400);
                value2 = frame.sp30;
                value4 = frame.sp10;
                MATCHING_KEEP2(value2, value4);
                value3 = (value2 * 200) >> 10;
                value2 = (value4 * 200) >> 10;
                value3 = value3 + value2;
                MATCHING_KEEP(value3);
                Controller7F80CField(childTag16, short*, 6) = value3;
                value2 = frame.sp34;
                value4 = frame.sp14;
                MATCHING_KEEP2(value2, value4);
                value3 = (value2 * 200) >> 10;
                value2 = (value4 * 200) >> 10;
                value3 = value3 + value2;
                MATCHING_KEEP(value3);
                Controller7F80CField(childTag16, short*, 8) = value3;
                value4 = frame.sp38;
                value5 = frame.sp18;
                MATCHING_KEEP2(value4, value5);
                value2 = 60;
                Controller7F80CField(childTag16, short*, 4) = value2;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                value3 = (value4 * 200) >> 10;
                value2 = (value5 * 200) >> 10;
                value3 = value3 + value2;
                MATCHING_KEEP(value3);
                value3 = value3 + 50;
                MATCHING_KEEP(value3);
                Controller7F80CField(childTag16, short*, 10) = value3;
                child18->state = 2;
                child18->angle.roll = Controller7F80C_rand();
                child18->angle.pitch = Controller7F80C_rand();
                child18->angle.yaw = Controller7F80C_rand();
                frame.sp30 = (int)Controller7F80CField(childTag16, short*, 6);
                frame.sp34 = (int)Controller7F80CField(childTag16, short*, 8);
                frame.sp38 = (int)Controller7F80CField(childTag16, short*, 0xA);
                func_8004F194(position19, position19, vector21);
                ownerPosition16 = &moby->position;
                if (Controller7F80C_func_80019194(ownerPosition16, 0x80) != 0)
                    goto deleteOwner;
                if (Controller7F80C_func_80018368(position19, ownerPosition16) != 0)
                    goto deleteChild;
            }
        nextAttempt:
            attempt20 += 1;
            if (attempt20 >= 7) {
                Controller7F80CRefreshMobySpatialGridAndBasis(moby, 4);
                Controller7F80C_func_8003BA00(moby);
                func_800369B8(moby, 0x30);
                goto deleteOwner;
            }
            goto spawnLoop;
        case 2:
            vector20 = &frame.sp40;
            MATCHING_KEEP(vector20);
            call4 = vector20;
            MATCHING_KEEP(call4);
            ownerPosition16Again = &moby->position;
            call5 = ownerPosition16Again;
            MATCHING_KEEP(call5);
            MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(ownerPosition16Again, vector20, "memory");
            value2 = moby->angle.roll;
            value3 = moby->angle.yaw;
            MATCHING_KEEP2(value2, value3);
            value2 = value2 + 7;
            MATCHING_KEEP(value2);
            moby->angle.roll = value2;
            MATCHING_BARRIER_GNU_VOLATILE("memory");
            value2 = moby->angle.pitch;
            moby->angle.yaw = value3 + 3;
            moby->angle.pitch = value2 + 1;
            func_8004F178(call4, call5);
            frame.sp50 = (int)Controller7F80CField(tag18, short*, 6);
            frame.sp54 = (int)Controller7F80CField(tag18, short*, 8);
            frame.sp58 = (int)Controller7F80CField(tag18, short*, 0xA);
            func_8004F194(ownerPosition16Again, ownerPosition16Again, (Vector3D*)&frame.sp50);
            Controller7F80CRefreshMobySpatialGridAndBasis(moby, 4);
            if ((Controller7F80C_func_80018368(ownerPosition16Again, vector20) != 0) ||
                (func_800359A4(tag18 + 4, 2) != 0) ||
                (Controller7F80C_func_80019194(ownerPosition16Again, 0x80) != 0) ||
                (moby->drawn == 0)) {
                goto deleteOwner;
            }
            goto particle;
    }
    return;
deleteOwner:
    Controller7F80CDeleteMoby(moby);
    return;
deleteChild:
    Controller7F80CDeleteMoby(child18);
    return;
particle:
    Controller7F80CNormalizeVectorToLength(&frame.sp50, 0xA);
    if (!(Controller7F80C_D_8006C640 & 3)) {
        SpawnParticle(1, 0xD, vector20, (Vector3D*)&frame.sp50);
    }
}
#undef Controller7F80CField

typedef struct {
    int sound, previousGate;
} DecodedContactSoundTag;
extern int DecodedContactPlayerState __asm__("D_80070328 + 0x48");
extern int DecodedContactPlayerGate __asm__("D_80070328 + 0xB8");
extern Moby* DecodedContactPlayerActor __asm__("D_80070328 + 0x250");
Moby* DecodedContactActorQuery(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
void DecodedContactModelPoint(Moby*, int, Vector3D*) __asm__("func_80055F14");
void func_level_35_8007FCF0(Moby* moby) {
    DecodedContactSoundTag* tag = moby->mobyTag;
    Vector3D position, point1, point2;
    Moby* target;
    if ((unsigned int)(DecodedContactPlayerState - 0xA9) < 2)
        moby->unknown4 = DecodedContactPlayerActor->unknown4 + 4;
    else
        moby->unknown4 = DecodedContactPlayerActor->unknown4 - 4;
    if (!DecodedContactPlayerGate && DecodedContactPlayerState == 0xA9)
        func_8003BABC(moby, 0, 0);
    else if (DecodedContactPlayerState == 0xAB && !DecodedContactPlayerGate && tag->previousGate)
        func_8003BABC(moby, 1, 0);
    tag->previousGate = DecodedContactPlayerGate;
    if (!func_8003BFC0(moby, tag->sound))
        tag->sound = func_8003BABC(moby, 2, 4);
    func_80055D24(moby, 5);
    DecodedContactModelPoint(moby, 0, &position);
    position.z += 0x200;
    target = DecodedContactActorQuery(&position, 0x2BC, 1, 0, 0, moby);
    if (!target) {
        DecodedContactModelPoint(moby, 1, &point1);
        DecodedContactModelPoint(moby, 2, &point2);
        position.x = (point1.x + point2.x) >> 1;
        position.y = (point1.y + point2.y) >> 1;
        position.z = ((point1.z + point2.z) >> 1) + 0x200;
        target = DecodedContactActorQuery(&position, 0x384, 1, 0, 0, moby);
    }
    if (target && (target->mobyClass == 0x285 || target->mobyClass == 0x80) && !target->state)
        target->state = 1;
}

typedef struct {
    int current, target, step;
} DecodedColourStepTag;
int rand(void);
int DecodedByteTimer(unsigned char*, int) __asm__("func_800359A4");
void func_level_35_8007FF14(Moby* moby) {
    DecodedColourStepTag* tag = moby->mobyTag;
    moby->angle.pitch = 0xC0;
    if (tag->target == tag->current) {
        if (DecodedByteTimer(&moby->substate, 1)) {
            tag->step = 0;
            tag->target = rand() & 255;
        }
    } else if (tag->step == 0) {
        if (tag->current < tag->target)
            tag->step = 2;
        else
            tag->step = -2;
    } else {
        int step = tag->step;
        if (step > 0)
            step += 2;
        else
            step -= 2;
        tag->step = step;
        tag->current += step;
        if ((tag->step > 0 && tag->current >= tag->target) ||
            (tag->step < 0 && tag->current <= tag->target)) {
            tag->current = tag->target;
            moby->substate = 15;
        }
    }
    moby->colour.r = ~tag->current;
    moby->colour.g = 0;
    moby->colour.b = tag->current;
    moby->colour.a = 0x3F;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Controller80044Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller80044_func_80018368() __asm__("func_80018368");                 /* extern */
int Controller80044_func_80019194() __asm__("func_80019194");                 /* extern */
int Controller80044_func_8003BA00() __asm__("func_8003BA00");                 /* extern */
int Controller80044NormalizeVectorToLength() __asm__("func_8004EF04");        /* extern */
int Controller80044DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller80044RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller80044_rand() __asm__("rand");                                   /* extern */
extern unsigned char Controller80044_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller80044_D_80065920 __asm__("D_80065920");
extern int Controller80044_D_8006C550 __asm__("D_8006C550");
extern int Controller80044_D_8006C640 __asm__("D_8006C640");
extern int Controller80044_D_8006E524 __asm__("D_8006E524");
extern int Controller80044_D_8006FA3C __asm__("D_8006FA3C");
extern Moby* Target70328 __asm__("D_80070328+0x250");
extern unsigned char Controller80044_D_80070328 __asm__("D_80070328");

void func_level_35_80080044(Moby* incomingMoby) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        char pad_1c[4];
        Vector3D sp20;
        char pad_2c[4];
        int sp30;
        int sp34;
        int sp38;
        char pad_3c[4];
        int sp40;
        int sp44;
        int sp48;
        char pad_4c[4];
    } frame;

    register Moby* moby __asm__("$18") = incomingMoby;

    register Moby* child19 __asm__("$19");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int value4 __asm__("$4");
    register Vector3D* vector21 __asm__("$21");
    register Vector3D* vector19 __asm__("$19");
    register Vector3D* call4 __asm__("$4");
    register Vector3D* call5 __asm__("$5");
    register Vector3D* childPosition16 __asm__("$16");
    register Vector3D* ownerPosition16 __asm__("$16");
    register Vector3D* ownerPosition23 __asm__("$23");
    register short* sinPointer4 __asm__("$4");
    register short* cosPointer3 __asm__("$3");
    register int tableOffset4 __asm__("$4");
    register int angle16 __asm__("$16");
    register int attempt22 __asm__("$22");
    unsigned short* recordTag7;
    unsigned char state4;
    register void* childTag17 __asm__("$17");
    register void* tag20 __asm__("$20");
    void* record;

    MATCHING_KEEP(moby);
    tag20 = moby->mobyTag;
    value2 = Controller80044_D_8006FA3C;
    MATCHING_KEEP(value2);
    if (value2 != 3) {
        Controller80044DeleteMoby();
    }
    state4 = moby->state;
    switch (state4) {
        case 0:
            moby->angle.roll = 0;
            moby->angle.pitch = 0;
            moby->angle.yaw = 0;
            if (Controller80044Field(&Controller80044_D_80070328, int*, 0x138) == moby) {
                moby->state = 1;
                return;
            }
            return;
        case 1:
            record = (Controller80044Field(tag20, int*, 0) * 0x58) + Controller80044_D_8006C550;
            recordTag7 = Controller80044Field(record, unsigned short**, 0);
            attempt22 = 0;
            if (Controller80044Field(record, unsigned char*, 0x48) == state4) {
                *recordTag7 -= 0x5DC;
                Controller80044_D_8006E524 = 0xF;
                Controller80044Field(&Controller80044_D_80070328, int*, 0x24) =
                    (int)(Controller80044Field(&Controller80044_D_80070328, int*, 0x24) | 1);
                func_8003BABC(moby, 0, 0);
                __asm__ __volatile__("" : "=r"(attempt22));
                attempt22 = 0;
            }
            ownerPosition23 = &moby->position;
            vector21 = (Vector3D*)&frame.sp30;
        spawnLoop:
            angle16 =
                func_8004E880(moby->position.x - Controller80044Field(Target70328, int*, 0xC),
                              moby->position.y - Controller80044Field(Target70328, int*, 0x10), 0);
            child19 = SpawnMoby(0x285, moby);
            MATCHING_KEEP(child19);
            if (child19 != 0) {
                cosPointer3 = (short*)&Controller80044_D_80065920;
                MATCHING_KEEP(cosPointer3);
                tableOffset4 = angle16 * 2;
                cosPointer3 = (short*)(tableOffset4 + (int)cosPointer3);
                childTag17 = child19->mobyTag;
                value2 = *cosPointer3;
                MATCHING_KEEP(value2);
                frame.sp10 = value2 >> 4;
                sinPointer4 = (short*)(tableOffset4 + (int)&Controller80044_D_800658A0);
                value2 = *sinPointer4;
                MATCHING_KEEP(value2);
                frame.sp18 = 0;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                frame.sp14 = value2 >> 4;
                frame.sp30 = (int)(*cosPointer3 * 0x19) >> 9;
                value3 = *sinPointer4;
                frame.sp38 = 0;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                frame.sp34 = (value3 * 25) >> 9;
                frame.sp20.x = (Controller80044_rand() & 0xFF) - 0x7F;
                frame.sp20.y = (Controller80044_rand() & 0xFF) - 0x7F;
                frame.sp20.z = Controller80044_rand() & 0xFF;
                func_8004F194((Vector3D*)&frame.sp10, (Vector3D*)&frame.sp10, &frame.sp20);
                childPosition16 = &child19->position;
                if (Controller80044Field(tag20, short*, 6) != 0) {
                    frame.sp10 = (int)(frame.sp10 + ((unsigned int)frame.sp10 >> 0x1F)) >> 1;
                    frame.sp14 = (int)(frame.sp14 + ((unsigned int)frame.sp14 >> 0x1F)) >> 1;
                    frame.sp18 *= 2;
                }
                func_8004F194(childPosition16, (Vector3D*)&frame.sp10, ownerPosition23);
                child19->size = 0x80;
                Controller80044NormalizeVectorToLength(&frame.sp10, 0x400);
                Controller80044Field(childTag17, short*, 6) =
                    (short)(frame.sp30 + ((int)(frame.sp10 * 0xC8) >> 0xA));
                value3 = frame.sp14;
                MATCHING_KEEP(value3);
                value2 = value3 * 200;
                value3 = frame.sp34;
                value2 = value2 >> 10;
                value3 = value3 + value2;
                MATCHING_KEEP(value3);
                Controller80044Field(childTag17, short*, 8) = value3;
                value4 = frame.sp38;
                value3 = frame.sp18;
                MATCHING_KEEP2(value4, value3);
                value2 = 60;
                Controller80044Field(childTag17, short*, 4) = value2;
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                value2 = (value3 * 200) >> 10;
                value4 = value4 + value2;
                MATCHING_KEEP(value4);
                value4 = value4 + 50;
                MATCHING_KEEP(value4);
                Controller80044Field(childTag17, short*, 10) = value4;
                child19->state = 2;
                if (Controller80044Field(tag20, short*, 6) != 0) {
                    Controller80044Field(childTag17, short*, 0xA) =
                        (short)((int)(Controller80044Field(childTag17, short*, 0xA) * 3) / 2);
                }
                child19->angle.roll = Controller80044_rand();
                child19->angle.pitch = Controller80044_rand();
                child19->angle.yaw = Controller80044_rand();
                frame.sp30 = (int)Controller80044Field(childTag17, short*, 6);
                frame.sp34 = (int)Controller80044Field(childTag17, short*, 8);
                frame.sp38 = (int)Controller80044Field(childTag17, short*, 0xA);
                func_8004F194(childPosition16, childPosition16, vector21);
                if (Controller80044_func_80019194(childPosition16, 128) != 0)
                    goto deleteOwner;
                if (Controller80044_func_80018368(childPosition16, ownerPosition23) != 0)
                    goto deleteChild;
                func_8004F178(vector21, childPosition16);
                frame.sp38 += 2048;
                if (Controller80044_func_80018368(childPosition16, vector21) == 0)
                    goto nextAttempt;
            deleteChild:
                Controller80044DeleteMoby(child19);
            }
        nextAttempt:
            attempt22++;
            if (attempt22 < 5)
                goto spawnLoop;
            Controller80044RefreshMobySpatialGridAndBasis(moby, 4);
            Controller80044_func_8003BA00(moby);
            func_800369B8(moby, 48);
            goto deleteOwner;
        case 2:
            vector19 = &frame.sp20;
            call4 = vector19;
            MATCHING_KEEP(call4);
            ownerPosition16 = &moby->position;
            call5 = ownerPosition16;
            MATCHING_KEEP(call5);
            value2 = moby->angle.roll;
            value3 = moby->angle.yaw;
            MATCHING_KEEP2(value2, value3);
            value2 += 7;
            MATCHING_KEEP(value2);
            moby->angle.roll = value2;
            MATCHING_BARRIER_GNU_VOLATILE("memory");
            value2 = moby->angle.pitch;
            moby->angle.yaw = value3 + 3;
            moby->angle.pitch = value2 + 1;
            func_8004F178(call4, call5);
            frame.sp40 = (int)Controller80044Field(tag20, short*, 6);
            frame.sp44 = (int)Controller80044Field(tag20, short*, 8);
            frame.sp48 = (int)Controller80044Field(tag20, short*, 0xA);
            func_8004F194(ownerPosition16, ownerPosition16, (Vector3D*)&frame.sp40);
            Controller80044RefreshMobySpatialGridAndBasis(moby, 4);
            if ((Controller80044_func_80018368(ownerPosition16, &frame.sp20) != 0) ||
                (func_800359A4(tag20 + 4, 2) != 0) ||
                (Controller80044_func_80019194(ownerPosition16, 0x80) != 0) || (moby->drawn == 0)) {
                goto deleteOwner;
            }
            goto particle;
    }
    return;
deleteOwner:
    Controller80044DeleteMoby(moby);
    return;
particle:
    Controller80044NormalizeVectorToLength(&frame.sp40, 10);
    if (!(Controller80044_D_8006C640 & 3))
        SpawnParticle(1, 13, vector19, (Vector3D*)&frame.sp40);
}
#undef Controller80044Field
