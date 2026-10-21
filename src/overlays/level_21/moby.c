#include "matching.h"
#include "common.h"
#include "savepoint.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
extern void func_80039714(Moby*);

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
extern void* Controller74C50D_8006C550 __asm__("D_8006C550");
int Controller74C50Helper399E8(void*, void*) __asm__("func_800399E8");
int Controller74C50Helper39B6C(void*, void*) __asm__("func_80039B6C");
void func_level_21_80075060(void* input) {
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
    register int thirty __asm__("$23");
    register int timer __asm__("$4");
    register int timerCondition __asm__("$3");
    register void* selectorOwner __asm__("$4");
    register int selectorMode __asm__("$5");
    register int ten __asm__("$20");
    register int five __asm__("$22");
    register void* savedPlayer __asm__("$21");
    register void* stateThreeVector __asm__("$17");
    register void* stateThreeDelta __asm__("$16");
    register void* stateTwoNormal __asm__("$21");
    register int temp_v0 __asm__("$2");
    register int temp_v0_4 __asm__("$2");
    register unsigned char* resourceRecord __asm__("$16");
    register unsigned char* workingPosition __asm__("$17");
    register unsigned char* ownerPosition __asm__("$20");
    register unsigned char* selectedResource __asm__("$16");
    register int originalDistanceLimit6 __asm__("$6");
    register int originalHeightLimit5 __asm__("$5");
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    register int sampledHeight __asm__("$16");
    register int distanceResult;
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
    register unsigned char* tag __asm__("$19");
    register unsigned char* callbackTag __asm__("$17");
    register void* originalCallback6 __asm__("$6");
    register int originalInitialDistance2 __asm__("$2");
    void* callbackOwnerReference;
    void* temp_v1_6;

    workingPosition = owner + 0xC;
    tag = Controller74C50Field(owner, void**, 0);
    originalInitialDistance2 =
        Controller74C50ApproximatePlanarDistance(workingPosition, Controller74C50D_80070328);
    MATCHING_KEEP(originalInitialDistance2);
    thirty = 30;
    MATCHING_KEEP(thirty);
    temp_v1_2 = Controller74C50Field(tag, short*, 0xA);
    MATCHING_KEEP(temp_v1_2);
    timer = temp_v1_2;
    __asm__("" : "=r"(timer) : "0"(timer), "r"(temp_v1_2));
    timerCondition = temp_v1_2 < 0x218;
    __asm__ volatile(""
                     : "=r"(timerCondition)
                     : "0"(timerCondition), "r"(originalInitialDistance2)
                     : "$30");
    if (timerCondition) {
        distanceResult = originalInitialDistance2;
        MATCHING_KEEP(thirty);
        temp_v0 = Controller74C50D_8006C648;
        MATCHING_KEEP(temp_v0);
        temp_v0 = timer + temp_v0;
        Controller74C50Field(tag, short*, 0xA) = temp_v0;
    } else {
        distanceResult = originalInitialDistance2;
        MATCHING_KEEP(thirty);
        __asm__ volatile("" ::: "$2", "$3");
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
        if (Controller74C50Field(owner, unsigned char*, 0x48) == 125)
            return;
        if (Controller74C50Field(tag, int*, 0) == 0)
            Controller74C50Helper399E8(owner, tag);
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
                    MATCHING_KEEP_CLOBBER(first, "$21");
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
            case 3:
                ten = 10;
                {
                    register int poolIndex __asm__("$3") =
                        Controller74C50Field(owner, unsigned char*, 0x3A);
                    register int sentinel __asm__("$2");
                    register unsigned char* poolEntry __asm__("$2");
                    register void* poolBase __asm__("$3");
                    register int poolType __asm__("$3");
                    register int expected __asm__("$2");
                    MATCHING_KEEP_CLOBBER(poolIndex, "$2");
                    sentinel = 255;
                    MATCHING_KEEP2(poolIndex, sentinel);
                    five = 5;
                    if (poolIndex != sentinel) {
                        poolEntry = (unsigned char*)(poolIndex * 11);
                        MATCHING_KEEP_CLOBBER(poolEntry, "$3");
                        poolBase = Controller74C50D_8006C550;
                        MATCHING_KEEP2(poolEntry, poolBase);
                        poolEntry = (unsigned char*)(((int)poolEntry << 3) + (int)poolBase);
                        poolType = Controller74C50Field(poolEntry, short*, 0x36);
                        MATCHING_KEEP_CLOBBER(poolType, "$2");
                        expected = 0x2DC;
                        MATCHING_KEEP(expected);
                        if (poolType == expected) {
                            thirty = 120;
                            ten = 2;
                            five = 1;
                        }
                    }
                }
                stateThreeVector = &frame.eighth.x;
                MATCHING_KEEP(stateThreeVector);
                Controller74C50Helper4F52C(stateThreeVector, tag + 4);
                stateThreeDelta = &frame.seventh.x;
                if (Controller74C50Field(tag, short*, 0xA) >= thirty) {
                    MATCHING_KEEP(five);
                    Controller74C50CopyVector(owner + 0xC, Controller74C50D_80070328);
                } else {
                    MATCHING_KEEP(five);
                    MATCHING_KEEP_CLOBBER(stateThreeDelta, "$21");
                    {
                        register void* first __asm__("$4") = stateThreeDelta;
                        MATCHING_KEEP_CLOBBER(first, "$21");
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
            originalDistanceLimit6 = Controller74C50D_80065810;
            {
                register int state __asm__("$3") =
                    Controller74C50Field(Controller74C50D_80070328, int*, 0x50);
                if (state == 6)
                    goto commonIncreasedThreshold;
                {
                    register unsigned int index __asm__("$2") = state - 11;
                    MATCHING_KEEP(index);
                    if (index < 2) {
                        register int source __asm__("$3");
                        register int product __asm__("$2");
                        product = (originalDistanceLimit6 << 1) + originalDistanceLimit6;
                        MATCHING_KEEP(product);
                        originalDistanceLimit6 = product >> 1;
                        MATCHING_KEEP(originalDistanceLimit6);
                        source = Controller74C50D_80065818;
                        MATCHING_KEEP(source);
                        originalHeightLimit5 = source + 512;
                        if (Controller74C50Field(owner, int*, 0x14) >
                            Controller74C50Field(Controller74C50D_80070328, int*, 8)) {
                            originalDistanceLimit6 = 2000;
                            originalHeightLimit5 = 600;
                        }
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
                originalHeightLimit5 = source + 512;
                goto commonThresholdReady;
            }
        commonNormalThreshold:
            originalHeightLimit5 = Controller74C50D_80065818;
        commonThresholdReady:
            if (({
                    register int inRange __asm__("$2") = distanceResult < originalDistanceLimit6;
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
                if ((var_v0 < originalHeightLimit5) && ({
                        originalCallback6 = Controller74C50D_8006C65C;
                        MATCHING_KEEP(originalCallback6);
                        originalCallback6 != 0;
                    }) &&
                    ((Controller74C50Field(owner, unsigned char*, 0x48) != 2) ||
                     ((unsigned char)Controller74C50Field(tag, unsigned char*, 0x12) < 3U)) &&
                    (callbackTag = Controller74C50Field(originalCallback6, void**, 0),
                     Controller74C50CopyVector(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64,
                     (Controller74C50Helper13E38(Controller74C50D_8006C65C + 0xC, &frame.ninth.x,
                                                 0) != 0))) {
                    callbackOwnerReference = Controller74C50Field(callbackTag, void**, 0x14);
                    if (callbackOwnerReference != 0) {
                        if ((callbackOwnerReference != owner) &&
                            (Controller74C50Field(callbackTag, short*, 0) > 0)) {
                            Controller74C50Field(callbackTag, short*, 0) = 0;
                            goto originalActorTail;
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
    originalActorTail:
        if (Controller74C50Field(tag, int*, 0) != 0)
            Controller74C50Helper39B6C(owner, tag);
    }
}

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
void func_level_21_80075D68(Moby* argument) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
int Controller75F38Helper399E8(void*, void*) __asm__("func_800399E8");
int Controller75F38Helper39B6C(void*, void*) __asm__("func_80039B6C");
void func_level_21_800763F4(void* input) {
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
        int siblingPadding[4];
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

    {
        register int gateValue __asm__("$3") = 125;
        MATCHING_KEEP(gateValue);
        tag = Controller75F38Field(owner, void**, 0);
        __asm__("" : "=r"(tag) : "0"(tag) : "$2", "memory");
        {
            register int gate __asm__("$2") = Controller75F38Field(owner, unsigned char*, 0x48);
            MATCHING_KEEP(gate);
            originalAngle = Controller75F38Field(owner, unsigned char*, 0x46);
            if (gate == gateValue)
                return;
        }
    }
    if (Controller75F38Field(tag, void**, 0x18) == 0)
        Controller75F38Helper399E8(owner, (unsigned char*)tag + 0x18);
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
            register void* particleVector __asm__("$17") = &frame.second.x;
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
            MATCHING_KEEP_CLOBBER(second, "$16");
            angleIndex = ((angleIndex + 64) & 255) * 2;
            sample = *(short*)(Controller75F38D_80065920 + angleIndex);
            MATCHING_KEEP_CLOBBER(sample, "$16");
            temp_s0_2 = owner + 12;
            value = (sample * 25) >> 10;
            frame.first.x = value;
            otherSample = *(short*)(Controller75F38D_800658A0 + angleIndex);
            MATCHING_KEEP_CLOBBER(otherSample, "$6");
            third = temp_s0_2;
            frame.first.z = 0;
            __asm__ volatile("" ::: "$2", "memory");
            value = (otherSample * 25) >> 10;
            frame.first.y = value;
            Controller75F38AddVector(first, second, third);
            Controller75F38SpawnParticle(2, 0x42, particleVector, 0);
            Controller75F38SubtractVector(particleVector, temp_s0_2, &frame.first.x);
            Controller75F38SpawnParticle(2, 0x42, particleVector, 0);
            {
                register unsigned char* firstTable __asm__("$16") = Controller75F38D_80065920;
                register unsigned char* secondTable __asm__("$18");
                register unsigned char* child __asm__("$2");
                register int childAngle __asm__("$3");
                register int childSample __asm__("$4");
                register int childOther __asm__("$3");
                register int childValue __asm__("$2");
                register unsigned char* childFirstAddress __asm__("$2");
                register unsigned char* childSecondAddress __asm__("$3");
                register void* childSecond __asm__("$5");
                __asm__("" : "=r"(firstTable) : "0"(firstTable) : "$2", "$18");
                child = Controller75F38Field(tag, unsigned char**, 0x18);
                MATCHING_KEEP_CLOBBER(child, "$18");
                secondTable = Controller75F38D_800658A0;
                MATCHING_KEEP2_CLOBBER(child, secondTable, "$5");
                childSecond = &frame.first.x;
                if (child != 0) {
                    childAngle = Controller75F38Field(child, unsigned char*, 0x46);
                    childAngle = ((childAngle + 64) & 255) * 2;
                    childFirstAddress = (unsigned char*)(childAngle + (int)firstTable);
                    MATCHING_KEEP(childFirstAddress);
                    childSample = *(short*)childFirstAddress;
                    __asm__ volatile(""
                                     : "=r"(childSample)
                                     : "0"(childSample), "r"(childAngle)
                                     : "memory");
                    childSecondAddress = (unsigned char*)(childAngle + (int)secondTable);
                    MATCHING_KEEP2_CLOBBER(childSample, childSecondAddress, "$2");
                    childValue = (childSample * 25) >> 10;
                    frame.first.x = childValue;
                    childOther = *(short*)childSecondAddress;
                    frame.first.z = 0;
                    __asm__ volatile("" ::: "$2", "memory");
                    childValue = (childOther * 25) >> 10;
                    frame.first.y = childValue;
                    Controller75F38AddVector(particleVector, childSecond,
                                             Controller75F38Field(tag, unsigned char**, 0x18) + 12);
                    Controller75F38SpawnParticle(2, 0x42, particleVector, 0);
                    Controller75F38SubtractVector(
                        particleVector, Controller75F38Field(tag, unsigned char**, 0x18) + 12,
                        &frame.first.x);
                    Controller75F38SpawnParticle(2, 0x42, particleVector, 0);
                }
            }
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
        temp_a0 = Controller75F38Field(tag, void**, 0x18);
        if (temp_a0 != 0)
            Controller75F38DeleteMoby(temp_a0);
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
    temp_v0 = Controller75F38Field(tag, void**, 0x18);
    if (temp_v0 != 0) {
        Controller75F38Helper39B6C(owner, (unsigned char*)tag + 0x18);
        temp_a0 = Controller75F38Field(tag, void**, 0x18);
        if (temp_a0 != 0)
            Controller75F38Field(temp_a0, int*, 0x54) = Controller75F38Field(owner, int*, 0x54);
    }
}

typedef struct {
    short counter;
    unsigned char unk2, unk3;
} DecodedColourTag;
void func_80055B18(Moby*);
void func_level_21_80077A94(Moby* moby) {
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
void func_level_21_80077BD0(Moby* moby) {
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
void func_level_21_80077E90(Moby* argument) {
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

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Three originals contain the same 404 instructions and no owned rodata.
 * Preserve the 0x98-byte frame, byte offsets, signed word arithmetic,
 * helper order, post-callback rereads, and phase boundaries 60/180/181.
 * Named stack vectors describe word layout, not verified physical units.
 * Empty compiler constraints emit no opcodes; they preserve original
 * argument producers and saved-register lifetimes. Full helper semantics,
 * vector units, caller cadence and synchronized retail runtime parity
 * remain unresolved. Verify all linked words and every retail binary hash.
 */
#define Actor783B0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor783B0func_8001A358() __asm__("func_8001A358");
int Actor783B0PlayMobySoundEvent() __asm__("func_8003BABC");
int Actor783B0func_8003BE70() __asm__("func_8003BE70");
int Actor783B0func_8003BFC0() __asm__("func_8003BFC0");
int Actor783B0func_8003C014() __asm__("func_8003C014");
int Actor783B0PlanarHeadingLookup() __asm__("func_8004E880");
int Actor783B0TransformVectorByBasis() __asm__("func_8004ED6C");
int Actor783B0ShiftVectorLeft() __asm__("func_8004F0E8");
int Actor783B0ClearVector() __asm__("func_8004F168");
int Actor783B0CopyVector() __asm__("func_8004F178");
int Actor783B0AddVector() __asm__("func_8004F194");
int Actor783B0SubtractVector() __asm__("func_8004F1C8");
int Actor783B0func_80050844() __asm__("func_80050844");
int Actor783B0func_800509E8() __asm__("func_800509E8");
int Actor783B0DeleteMoby() __asm__("func_80055B18");
int Actor783B0RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor783B0func_8005629C() __asm__("func_8005629C");
extern int Actor783B0D_8006C550 __asm__("D_8006C550");
extern int Actor783B0D_8006C640 __asm__("D_8006C640");
extern int Actor783B0D_8006C648 __asm__("D_8006C648");
extern int (*Actor783B0SpawnParticle)() __asm__("SpawnParticle");
extern int (*Actor783B0unk_ovlheader_800743EC)() __asm__("unk_ovlheader_800743EC");
int Actor783B0rand() __asm__("rand");
void func_level_21_800783B0(unsigned char* owner) {
    struct {
        int referenceDelta[3];
        int reserved24;
        int emissionPosition[3];
        int reserved34;
        int emissionVelocity[3];
        int reserved44;
        int burstPosition[3];
        int reserved54;
        int burstVelocity[3];
        int reserved64;
        int clearedVector[3];
        int reserved74;
    } frame;

    int* ownerVector;
    register int work2 __asm__("2");
    register int work3 __asm__("3");
    register int arg4 __asm__("4");
    register int arg5 __asm__("5");
    register void* arg6 __asm__("6");
    register void* arg7 __asm__("7");
    register void* matrix4 __asm__("4");
    register void* matrix5 __asm__("5");
    int handle;
    int referenceWord0C;
    int nextPhase;
    int linkedIndex;
    int phase;
    int phaseAfterCallbacks;
    int linkedIndexAfterHeader;
    int particleCount;
    unsigned char stateByte49;
    void* firstMatrix;
    register void* secondMatrixOrVelocity __asm__("16");
    register void* emissionPosition __asm__("17");
    void* stateVector;
    unsigned char* state;
    void* linkedActor;

    state = Actor783B0Field(owner, void**, 0);
    if (Actor783B0Field(state, int*, 0x1C) == 1) {
        referenceWord0C = Actor783B0Field(Actor783B0Field(state, void**, 4), int*, 0xC);
        Actor783B0SubtractVector(&frame.referenceDelta[0], referenceWord0C + 0x10, referenceWord0C);
        Actor783B0Field(owner, unsigned char*, 0x45) = 0x20U;
        Actor783B0Field(owner, signed char*, 0x46) =
            (signed char)(Actor783B0PlanarHeadingLookup(frame.referenceDelta[0],
                                                        frame.referenceDelta[1], 0) -
                          0x80);
        Actor783B0Field(owner, int*, 0x14) = (int)(Actor783B0Field(owner, int*, 0x14) + 0x40);
        Actor783B0RefreshMobySpatialGridAndBasis(owner, 4);
        Actor783B0Field(state, int*, 0x1C) = 2;
    }
    stateByte49 = Actor783B0Field(owner, unsigned char*, 0x49);
    switch (stateByte49) {
        case 0:
            linkedIndex = Actor783B0Field(state, int*, 0);
            if ((linkedIndex >= 0) &&
                ((unsigned char)Actor783B0Field(((linkedIndex * 0x58) + Actor783B0D_8006C550),
                                                unsigned char*, 0x48) >= 0x80U)) {
                Actor783B0DeleteMoby(owner);
            }
            if (Actor783B0Field(owner, int*, 0x18) & 0x10000) {
                Actor783B0Field(owner, unsigned char*, 0x49) = 1U;
                Actor783B0Field(owner, unsigned char*, 0x4A) = 0xFF;
                Actor783B0Field(owner, signed char*, 0x4C) = 0x3C;
                return;
            }
            return;
        case 1:
            if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int*, 0x20)) == 0) {
                Actor783B0Field(state, int*, 0x20) = Actor783B0PlayMobySoundEvent(owner, 1, 4);
            }
            phase = Actor783B0Field(state, int*, 0x18) + Actor783B0D_8006C648;
            Actor783B0Field(state, int*, 0x18) = phase;
            if (phase < 0x3C) {
                firstMatrix = owner + 0x20;
                frame.emissionPosition[0] = 0x40;
                frame.emissionPosition[1] = -0xF0;
                frame.emissionPosition[2] = 0x20;
                Actor783B0TransformVectorByBasis(firstMatrix, &frame.emissionPosition[0],
                                                 &frame.emissionPosition[0]);
                Actor783B0AddVector(&frame.emissionPosition[0], &frame.emissionPosition[0],
                                    owner + 0xC);
                frame.emissionVelocity[1] = 6;
                frame.emissionVelocity[0] = 0;
                frame.emissionVelocity[2] = -0xC;
                Actor783B0TransformVectorByBasis(firstMatrix, &frame.emissionVelocity[0],
                                                 &frame.emissionVelocity[0]);
                work2 = Actor783B0rand();
                work3 = frame.emissionVelocity[0];
                work2 &= 15;
                work3 -= 8;
                asm("" : "=r"(work2), "=r"(work3) : "0"(work2), "1"(work3));
                work3 += work2;
                frame.emissionVelocity[0] = work3;
                work2 = Actor783B0rand();
                arg4 = 1;
                arg5 = 74;
                arg6 = &frame.emissionPosition[0];
                arg7 = &frame.emissionVelocity[0];
                asm(""
                    : "=r"(arg4), "=r"(arg5), "=r"(arg6), "=r"(arg7)
                    : "0"(arg4), "1"(arg5), "2"(arg6), "3"(arg7), "r"(work2));
                work3 = frame.emissionVelocity[1];
                work2 &= 15;
                work3 -= 8;
                asm("" : "=r"(work2), "=r"(work3) : "0"(work2), "1"(work3));
                work3 += work2;
                frame.emissionVelocity[1] = work3;
                Actor783B0SpawnParticle(arg4, arg5, arg6, arg7);
                return;
            }
            if (phase < 0xB4) {
                if (Actor783B0D_8006C640 & 1) {
                    emissionPosition = &frame.emissionPosition[0];
                    secondMatrixOrVelocity = owner + 0x20;
                    asm(""
                        : "=r"(emissionPosition), "=r"(secondMatrixOrVelocity)
                        : "0"(emissionPosition), "1"(secondMatrixOrVelocity));
                    frame.emissionPosition[0] = 0;
                    frame.emissionPosition[1] = 0;
                    frame.emissionPosition[2] = 0x20;
                    Actor783B0TransformVectorByBasis(secondMatrixOrVelocity, emissionPosition,
                                                     emissionPosition);
                    Actor783B0AddVector(emissionPosition, emissionPosition, owner + 0xC);
                    matrix4 = secondMatrixOrVelocity;
                    secondMatrixOrVelocity = &frame.emissionVelocity[0];
                    matrix5 = secondMatrixOrVelocity;
                    asm("" : "=r"(matrix4), "=r"(matrix5) : "0"(matrix4), "1"(matrix5) : "memory");
                    work2 = Actor783B0Field(state, int*, 0x18);
                    asm("" : : : "memory");
                    frame.emissionVelocity[1] = 0;
                    frame.emissionVelocity[0] = ((work2 - 0x5A) >> 2) + 0x18;
                    frame.emissionVelocity[2] =
                        -0x18 - ((int)(Actor783B0Field(state, int*, 0x18) - 0x5A) >> 2);
                    Actor783B0TransformVectorByBasis(matrix4, matrix5, secondMatrixOrVelocity);
                    Actor783B0SpawnParticle(1, 3, emissionPosition, secondMatrixOrVelocity);
                }
                phaseAfterCallbacks = Actor783B0Field(state, int*, 0x18);
                if (phaseAfterCallbacks >= 0x5B) {
                    if ((unsigned char)Actor783B0Field(owner, unsigned char*, 0x44) < 0x80U) {
                        work2 = phaseAfterCallbacks - 0x5A;
                        Actor783B0Field(owner, unsigned char*, 0x44) = (unsigned char)-(work2 >> 5);
                        return;
                    }
                    work2 = phaseAfterCallbacks - 0x5A;
                    Actor783B0Field(owner, unsigned char*, 0x44) = (unsigned char)(work2 >> 5);
                    return;
                }
            } else if (phase >= 0xB5) {
                Actor783B0Field(owner, unsigned char*, 0x49) = 0U;
                Actor783B0Field(state, int*, 0x18) = 0;
                Actor783B0Field(owner, int*, 0x18) = 0;
                Actor783B0Field(owner, unsigned char*, 0x49) = 2U;
                Actor783B0Field(Actor783B0Field(state, void**, 4), short*, 2) = 1;
                Actor783B0Field(state, int*, 0x18) = 0;
                Actor783B0ClearVector(state + 0xC);
                Actor783B0Field(state, int*, 8) =
                    Actor783B0func_80050844(owner + 0xC, 3, 6, 0x4080E0);
                Actor783B0Field(owner, unsigned char*, 0x52) = 0xFF;
                if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int*, 0x20)) != 0) {
                    if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int*, 0x20)) != 0) {
                        Actor783B0func_8003BE70(Actor783B0Field(state, int*, 0x20));
                    }
                    Actor783B0Field(state, int*, 0x20) = -1;
                    return;
                }
            }
            break;
        case 2:
            stateVector = state + 0xC;
            if (Actor783B0unk_ovlheader_800743EC(owner, Actor783B0Field(state, void**, 4),
                                                 stateVector, state + 0x18, 4, 0) &
                2) {
                linkedIndexAfterHeader = Actor783B0Field(state, int*, 0);
                if (linkedIndexAfterHeader > 0) {
                    linkedActor = (linkedIndexAfterHeader * 0x58) + Actor783B0D_8006C550;
                    Actor783B0Field(linkedActor, int*, 0x18) =
                        (int)(Actor783B0Field(linkedActor, int*, 0x18) | 0x60000);
                    Actor783B0Field(
                        ((Actor783B0Field(state, int*, 0) * 0x58) + Actor783B0D_8006C550),
                        unsigned char*, 0x4A) = 0xFF;
                }
                particleCount = 0;
                do {
                    particleCount += 1;
                    frame.burstVelocity[0] = 0x80 - (Actor783B0rand() & 0xFF);
                    frame.burstVelocity[1] = 0x80 - (Actor783B0rand() & 0xFF);
                    frame.burstVelocity[2] = Actor783B0rand() & 0x7F;
                    Actor783B0AddVector(&frame.burstPosition[0], owner + 0xC,
                                        &frame.burstVelocity[0]);
                    Actor783B0SpawnParticle(1, 3, &frame.burstPosition[0], &frame.burstVelocity[0]);
                } while (particleCount < 8);
                Actor783B0Field(owner, unsigned char*, 0x49) = 3U;
                Actor783B0Field(state, int*, 0x18) = 0;
                Actor783B0Field(owner, signed char*, 0x4C) = 0;
                Actor783B0Field(owner, signed char*, 0x4D) = 0;
            } else if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int*, 0x20)) == 0) {
                Actor783B0Field(state, int*, 0x20) = Actor783B0PlayMobySoundEvent(owner, 0, 4);
            } else {
                Actor783B0CopyVector(&frame.burstPosition[0], stateVector);
                Actor783B0ShiftVectorLeft(&frame.burstPosition[0], 2);
                Actor783B0func_8003C014(Actor783B0Field(state, int*, 0x20),
                                        &frame.burstPosition[0]);
            }
            ownerVector = (int*)(owner + 0xC);
            Actor783B0Field(owner, unsigned char*, 0x45) =
                (unsigned char)(Actor783B0Field(owner, unsigned char*, 0x45) - 0x40);
            Actor783B0func_8001A358(ownerVector, 0x8000);
            Actor783B0func_8005629C(owner);
            if (Actor783B0D_8006C640 & 1) {
                Actor783B0ClearVector(&frame.clearedVector[0]);
                Actor783B0SpawnParticle(1, 3, ownerVector, &frame.clearedVector[0]);
                return;
            }
            break;
        case 3:
            nextPhase = Actor783B0Field(state, int*, 0x18) + 1;
            Actor783B0Field(state, int*, 0x18) = nextPhase;
            if (nextPhase >= 6) {
                handle = Actor783B0Field(state, int*, 8);
                if (handle != 0) {
                    Actor783B0func_800509E8(handle);
                }
                if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int*, 0x20)) != 0) {
                    Actor783B0func_8003BE70(Actor783B0Field(state, int*, 0x20));
                }
                Actor783B0DeleteMoby(owner);
            }
            break;
    }
}

#undef Actor783B0Field

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
void func_level_21_80078A00(Moby* moby) {
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
void func_level_21_80078D04(void* input) {
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
void func_level_21_80079878(Moby* moby) {
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
void func_level_21_80079CA8(Moby* moby) {
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
void func_level_21_8007A010(Moby* owner) {
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

void func_level_21_8007A19C(Moby* moby) {
    int animation = spyro.animationState;
    if (animation == 0x28 || animation == 0x29 || animation == 0x2A)
        return;
    if (!moby->substate) {
        SpawnParticle(0x40, 0xE, (Vector3D*)1, 0);
        moby->substate = 1;
    } else {
        SpawnParticle(1, 0xE, 0, 0);
    }
}

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
void func_level_21_8007A238(Moby* moby) {
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
    unsigned char reserved00[0x18];
    EnemyTag enemy;
    int timer, count;
} DecodedEnemyDelay;
extern int D_8006C770;
int func_8003636C(int, int);
void func_80037168(Moby*, void*, int);
void func_level_21_8007A554(Moby* actor) {
    DecodedEnemyDelay* tag = actor->mobyTag;
    if (actor->state != 3 && actor->damageFlags) {
        if (actor->mobyClass == 0x2E) {
            func_80038BF8(actor, &tag->enemy, 8, 3);
            tag->enemy.unk6 = 0xC8;
            tag->enemy.unk4 += 0x64;
        } else {
            func_80038BF8(actor, &tag->enemy, 0, 3);
            tag->enemy.unk6 = 0x96;
        }
        SpawnMoby(0x10, actor);
        actor->unknownCollision = 0;
    }
    switch (actor->state) {
        case 0:
        case 1:
            if (D_8006C770) {
                tag->timer = func_8003636C(0x5A, 0x12C);
                actor->state = 2;
                func_80034F40(actor, 2);
            }
            break;
        case 2:
            func_80037168(actor, tag, 0x57);
            if (func_800359A4(&tag->timer, 4)) {
                if (tag->count) {
                    tag->count--;
                    actor->state = 0;
                    func_80034F40(actor, 0);
                } else {
                    tag->count = func_8003636C(2, 4);
                    actor->state = 1;
                    func_80034F40(actor, 1);
                }
            }
            break;
        case 3:
            if (func_80035194(actor, &tag->enemy) == 0x100) {
                func_80055D24(actor, 4);
                func_8003BA00(actor);
                func_800369B8(actor, 0x20);
                func_80055B18(actor);
            }
            break;
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
void func_level_21_8007A720(Moby* moby) {
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
    unsigned char reserved00, toll, mode, reserved03[2], enabled, reserved06[0x22];
    int actorIndex, tollIndex, selector;
} DecodedTollInteraction;
extern GemToll DecodedGateTolls[] __asm__("D_80066EAC");
extern unsigned char DecodedGateHeader[] __asm__("D_80066FCC");
extern unsigned char D_80070300[];
extern unsigned char DecodedGateStatus __asm__("D_80071584");
extern int D_8006C71C, D_8006C640, D_8006E344;
extern Moby* D_8006C550;
void DecodedGateDispatch(int, int, int) __asm__("func_80021ED8");
void func_level_21_8007A874(Moby* actor) {
    DecodedTollInteraction* tag = actor->mobyTag;
    int toll, selector;
    int state = actor->state;
    switch (state) {
        case 0:
            toll = tag->toll & 0x7F;
            if (toll != 0x7F && D_8006C71C >= DecodedGateTolls[toll].value &&
                !DecodedGateTolls[toll].paid) {
                tag->enabled = 1;
                tag->toll = 0xFF;
            }
            if (tag->tollIndex != -1 && D_8006C640 < 0xA &&
                (DecodedGateTolls[tag->tollIndex].paid ||
                 (D_80070300[DecodedGateHeader[0x2F]] & 1))) {
                if (tag->actorIndex != -1)
                    D_8006C550[tag->actorIndex].substate = 1;
                if (tag->selector != -1)
                    DecodedGateDispatch(tag->selector, 0xFC, 0);
                func_80055B18(actor);
                break;
            }
            if ((tag->actorIndex != -1 || tag->selector != -1) && tag->mode == 4) {
                if (tag->actorIndex != -1)
                    D_8006C550[tag->actorIndex].substate = 1;
                selector = tag->selector;
                tag->actorIndex = -1;
                if (selector != -1)
                    DecodedGateDispatch(selector, 0xFC, 0);
                tag->selector = -1;
            }
            if (func_80037BBC(actor, 0)) {
                func_800512E4(actor, 0, 1);
                actor->state = 1;
            }
            break;
        case 1:
            DecodedGateStatus = 1;
            if (D_8006E344 != state) {
                actor->state = 0;
                func_80034F40(actor, 0);
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_21/moby/func_level_21_8007AAB4.s SHA256 80e748f93dda829768923b2ab63e48b69486786c176e1fc272972b8b05b94c05. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level21_7AAB4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level21_7AAB4_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level21_7AAB4_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level21_7AAB4_D_8006C550 __asm__("D_8006C550");
extern int Level21_7AAB4_D_8006C648 __asm__("D_8006C648");
extern unsigned char Level21_7AAB4_D_80070300[40] __asm__("D_80070300");
extern Spyro Level21_7AAB4_D_80070328 __asm__("D_80070328");
void Level21_7AAB4_func_80013D44() __asm__("func_80013D44");
void Level21_7AAB4RequestMobyAnimation() __asm__("func_80034F40");
int Level21_7AAB4_func_80035194() __asm__("func_80035194");
int Level21_7AAB4TurnMobyTowardPlayer() __asm__("func_8003573C");
int Level21_7AAB4ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Level21_7AAB4RandBetween() __asm__("func_8003636C");
int Level21_7AAB4RandSignedBetween() __asm__("func_800363DC");
void Level21_7AAB4_func_800369B8() __asm__("func_800369B8");
void Level21_7AAB4_func_80037014() __asm__("func_80037014");
void Level21_7AAB4_func_80038BF8() __asm__("func_80038BF8");
void Level21_7AAB4_func_8003BA00() __asm__("func_8003BA00");
int Level21_7AAB4PlayMobySoundEvent() __asm__("func_8003BABC");
extern int Level21_7AAB4PlanarHeadingLookup() __asm__("func_8004E880");
extern void Level21_7AAB4ShiftVectorRightTowardZero() __asm__("func_8004F110");
extern void Level21_7AAB4CopyVector() __asm__("func_8004F178");
extern void Level21_7AAB4AddVector() __asm__("func_8004F194");
extern int Level21_7AAB4AbsoluteByteAngleDelta() __asm__("func_8004F264");
extern int Level21_7AAB4ApproximatePlanarDistance() __asm__("func_8004F334");
extern void Level21_7AAB4DeleteMoby() __asm__("func_80055B18");
extern void Level21_7AAB4RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern int Level21_7AAB4_func_80055E84() __asm__("func_80055E84");
extern int Level21_7AAB4_rand() __asm__("rand");

int Level21_7AAB4_func_80035A80() __asm__("func_80035A80");
/* extern */
short Level21_7AAB4_func_800365E4() __asm__("func_800365E4");
/* extern */
unsigned char Level21_7AAB4_func_80037A60() __asm__("func_80037A60");
/* extern */
unsigned char Level21_7AAB4InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern int Level21_7AAB4_D_8006C58C __asm__("D_8006C58C");
extern int Level21_7AAB4_D_8006C640 __asm__("D_8006C640");
extern int Level21_7AAB4_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level21_7AAB4_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level21_7AAB4_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level21_7AAB4_D_8006E048 __asm__("D_8006E048");

void func_level_21_8007AAB4(Moby* ownerArgument) {
    /* SCUS-94467 original function8007AAB4, SHA256 above.
     * Original 0x90-byte frame: scratch atSP+0x20..0x60;
      owner18,
     * private19, pool22, parameter23 and literal30 are saved registers.
     * RA atSP+0x8C and saved30 atSP+0x88. All record offsets are bytes.
     * Pool records use the original 88-byte stride. Table offsets use
     * byte arithmetic;
      signed halfwords retain original LH producers.
     * State4/mask3/range2 are the distinct original110..116 producers.
     * The HI producer at542 is the original signed MULT2,3;
      sign2,
     * high8 and quotient3 feed SUB4 at546. Empty constraints contain
     * no CPU instructions and their inputs are initialized.
     * Particle yaw5/table4 at627..634 and zeroSP48 at663 retain native
     * ordering. The angle comparison is shared by the original branches.
     * Physical units/fixed point, helper semantics and caller cadence
     * remain unresolved. Cadence per invocation;
      frame rate unknown.
     * Falsification: all984 native instructions, all32 owned selectors,
     * native/linked targets and full EXE/every-overlay original hashes.
     * AI generated;
      not human reviewed. No runtime parity claim. */
    register Moby* ownerRecord __asm__("18") = ownerArgument;
    struct {
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[4];
        int sp40;
        int sp44;
        int sp48;
        unsigned char pad4C[4];
        unsigned char sp50;
        unsigned char pad51[7];
        Vector3D sp58;
        unsigned char pad64[4];
    } scratch;

    register EnemyTag* privateRecord19 __asm__("19");
    register Moby* poolRecord22 __asm__("22");
    Vector3D* temp_v0_10;
    Vector3D* temp_v0_9;
    short* tablePointer4;
    short* tablePointer5;
    int privateHeightWord3;
    int lowerLimitWord2;
    register int temp_v1_14 __asm__("3");
    int temp_v1_9;
    int adjustmentWord20;
    int* temp_v1_2;
    int* temp_v1_4;
    int temp_a0;
    int temp_a0_5;
    register int tableIndex5 __asm__("5");
    register int previousIndex17 __asm__("17");
    int shiftedGlobalWord16;
    int randomResult16;
    int helperResult16;
    register int tableOffset16 __asm__("16");
    register int distanceWord17 __asm__("17");
    int temp_v0_2;
    register int angleWord21 __asm__("21");
    int temp_v0_4;
    register int angleResult3 __asm__("3");
    int temp_v0_6;
    int temp_v0_8;
    int temp_v1;
    int temp_v1_13;
    int temp_v1_16;
    register int temp_v1_18 __asm__("3");
    int temp_v1_8;
    int literalOne30;
    register int divideMagic3 __asm__("3");
    int scaledParameter4;
    register int particleIndex17 __asm__("17");
    register int parameterWord23 __asm__("23");
    int var_v0_2;
    int var_v0_3;
    register int numeratorWord2 __asm__("2");
    int var_v0_5;
    int updatedHalfword3;
    register unsigned int poolStateWord4 __asm__("4");
    unsigned char temp_a0_3;
    unsigned char temp_v0_11;
    unsigned char temp_v1_3;
    unsigned char temp_v1_5;
    unsigned char temp_v1_6;
    unsigned char var_v0;
    register void* temp_a1_3 __asm__("5");
    void* temp_a1_4;
    void* temp_a3;
    void* temp_s1_2;
    void* temp_v0;
    void* temp_v0_7;
    void* temp_v1_15;
    void* temp_v1_17;
    void* temp_v1_19;
    void* temp_v1_7;

    privateRecord19 = ownerRecord->mobyTag;
    {
        register int index3 __asm__("3");
        register int stride2 __asm__("2");
        register Moby* base3 __asm__("3");
        index3 = Level21_7AAB4Field(privateRecord19, int*, 0x28);
        stride2 = index3 * 88;
        base3 = Level21_7AAB4_D_8006C550;
        poolRecord22 = (Moby*)((int)base3 + stride2);
    }
    distanceWord17 = Level21_7AAB4ApproximatePlanarDistance(
        ((void*)((unsigned char*)((unsigned char*)ownerRecord + 0xC))),
        &Level21_7AAB4_D_80070328.position);
    if ((unsigned char)poolRecord22->state >= 0x80U) {
        poolRecord22 = 0;
    }
    if (Level21_7AAB4_D_8006C640 == 0) {
        temp_a0 = Level21_7AAB4Field(privateRecord19, int*, 0x38);
        temp_v1 = temp_a0 + 2;
        if ((((int)Level21_7AAB4_D_8006C7B4 >> temp_v1) & 1) ||
            (((int)Level21_7AAB4_D_80070300[Level21_7AAB4_D_8006C58C] >> temp_v1) & 1)) {
            if (temp_a0 == 0) {
                temp_v1_2 = Level21_7AAB4Field(privateRecord19, int**, 0x3C);
                *temp_v1_2 += 1;
            }
            if (poolRecord22 != 0) {
                Level21_7AAB4DeleteMoby(poolRecord22);
            }
            goto block_134;
        }
        if (poolRecord22 != 0) {
            poolRecord22->state = 6;
            poolRecord22->unknown &= 0x7FFFFFFF;
        }
        ownerRecord->colour.a = 0;
        {
            register unsigned int colour2 __asm__("2");
            if (Level21_7AAB4Field(privateRecord19, int*, 0x38) == 0) {
                colour2 = 0xC0;
                MATCHING_KEEP(colour2);
                ownerRecord->colour.r = colour2;
                colour2 = 0xD0;
                MATCHING_KEEP(colour2);
                ownerRecord->colour.g = colour2;
                colour2 = 0x40;
                goto writeBlueByte;
            }
            colour2 = 0xD0;
            MATCHING_KEEP(colour2);
            ownerRecord->colour.r = colour2;
            colour2 = 0x30;
            MATCHING_KEEP(colour2);
            ownerRecord->colour.g = colour2;
        writeBlueByte:
            MATCHING_KEEP(colour2);
            ownerRecord->colour.b = colour2;
        }
        goto block_15;
    }
block_15:
    if ((ownerRecord->damageFlags != 0) &&
        ((Level21_7AAB4Field(privateRecord19, int*, 0x38) != 0) ||
         ((({
              register int index3 __asm__("3");
              register int stride2 __asm__("2");
              register Moby* base3 __asm__("3");
              register int three2 __asm__("2");
              register unsigned int mask3 __asm__("3");
              index3 = Level21_7AAB4Field(privateRecord19, int*, 0x48);
              stride2 = index3 * 88;
              base3 = Level21_7AAB4_D_8006C550;
              poolStateWord4 = ((Moby*)(stride2 + (int)base3))->state;
              MATCHING_KEEP_VOLATILE_CLOBBER(poolStateWord4, "2");
              three2 = 3;
              MATCHING_KEEP(three2);
              mask3 = poolStateWord4 & 0xFF;
              mask3 != three2;
          })) &&
          (({
               register unsigned int range2 __asm__("2");
               range2 = poolStateWord4 - 0x14;
               MATCHING_KEEP(range2);
               range2;
           }) >= 2U))) &&
        ((temp_v1_3 = ownerRecord->state, ((temp_v1_3 < 3U) != 0)) || (temp_v1_3 == 0xA))) {
        MATCHING_BARRIER_VOLATILE("4");
        Level21_7AAB4_func_80038BF8(ownerRecord, privateRecord19, 1, 3);
        privateRecord19->unk13 = 0;
        if (Level21_7AAB4Field(privateRecord19, int*, 0x38) == 0) {
            temp_v1_4 = Level21_7AAB4Field(privateRecord19, int**, 0x3C);
            *temp_v1_4 += 1;
        }
        if (poolRecord22 != 0) {
            Level21_7AAB4RefreshMobySpatialGridAndBasis(poolRecord22, 2);
        }
    }
    ownerRecord->damageFlags = 0;
    if (Level21_7AAB4Field(privateRecord19, int*, 0x38) == 0) {
        temp_a0_3 = ownerRecord->state;
        if (temp_a0_3 < 3U) {
            temp_v1_5 =
                Level21_7AAB4_D_8006C550[Level21_7AAB4Field(privateRecord19, int*, 0x48)].state;
            if ((temp_v1_5 >= 3U) && (temp_v1_5 != 0xA) && (Level21_7AAB4_D_8006E048 & 1) &&
                (temp_a0_3 < 0x80U) && (temp_a0_3 != 0) && (temp_a0_3 != 0x1E)) {
                ownerRecord->state = 0x1E;
            }
        }
    }
    temp_v1_6 = ownerRecord->state;
    switch (temp_v1_6) {
        case 30:
            Level21_7AAB4CopyVector(
                &ownerRecord->position,
                Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x20), void**, 0xC) +
                    0x10);
            Level21_7AAB4_func_80037014(ownerRecord);
            ownerRecord->subtype = 0xFE;
            Level21_7AAB4RefreshMobySpatialGridAndBasis(ownerRecord, 2);
            temp_v0 =
                Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x20), void**, 0xC);
            ownerRecord->angle.yaw = Level21_7AAB4PlanarHeadingLookup(
                Level21_7AAB4Field(temp_v0, int*, 0) - Level21_7AAB4Field(temp_v0, int*, 0x10),
                Level21_7AAB4Field(temp_v0, int*, 4) - Level21_7AAB4Field(temp_v0, int*, 0x14), 0);
            temp_v1_7 = Level21_7AAB4Field(privateRecord19, void**, 0x20);
            Level21_7AAB4Field(privateRecord19, void**, 0x18) = temp_v1_7;
            Level21_7AAB4Field(temp_v1_7, short*, 2) = 2;
            ownerRecord->state = 0;
            Level21_7AAB4RequestMobyAnimation(ownerRecord, 0);
            goto block_135;
        case 10:
            Level21_7AAB4TurnMobyTowardPlayer(ownerRecord, 5, 0, 0);
            if (Level21_7AAB4_D_8006C770 != 0) {
                if (Level21_7AAB4Field(privateRecord19, short*, 0x36) == 0) {
                    Level21_7AAB4RequestMobyAnimation(ownerRecord, 1);
                    Level21_7AAB4Field(privateRecord19, short*, 0x36) =
                        Level21_7AAB4RandBetween(1, 2);
                } else {
                    Level21_7AAB4RequestMobyAnimation(ownerRecord, 0);
                    Level21_7AAB4Field(privateRecord19, short*, 0x36) =
                        (short)((unsigned short)Level21_7AAB4Field(privateRecord19, short*, 0x36) -
                                1);
                }
            }
            if (Level21_7AAB4Field(privateRecord19, int*, 0x38) ==
                *Level21_7AAB4Field(privateRecord19, int**, 0x3C)) {
                Level21_7AAB4CopyVector(
                    &ownerRecord->position,
                    Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x18), int*,
                                       0xC) +
                        0x20);
                Level21_7AAB4_func_80037014(ownerRecord);
                ownerRecord->subtype = 0xFE;
                Level21_7AAB4RefreshMobySpatialGridAndBasis(ownerRecord, 2);
                Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x18), short*, 2) =
                    3;
                ownerRecord->state = 0;
            }
            goto block_135;
        case 0:
            Level21_7AAB4TurnMobyTowardPlayer(ownerRecord, 5, 0, 0);
            if (Level21_7AAB4_D_8006C770 != 0) {
                if (Level21_7AAB4Field(privateRecord19, short*, 0x36) == 0) {
                    Level21_7AAB4RequestMobyAnimation(ownerRecord, 1);
                    Level21_7AAB4Field(privateRecord19, short*, 0x36) =
                        Level21_7AAB4RandBetween(1, 2);
                } else {
                    Level21_7AAB4RequestMobyAnimation(ownerRecord, 0);
                    Level21_7AAB4Field(privateRecord19, short*, 0x36) =
                        (short)((unsigned short)Level21_7AAB4Field(privateRecord19, short*, 0x36) -
                                1);
                }
            }
            Level21_7AAB4CopyVector((Vector3D*)&scratch.sp20, &Level21_7AAB4_D_80070328.unk7a[3]);
            scratch.sp20 *= 0x1E;
            scratch.sp24 *= 0x1E;
            scratch.sp28 *= 0x1E;
            Level21_7AAB4ShiftVectorRightTowardZero((Vector3D*)&scratch.sp20, 6);
            Level21_7AAB4AddVector(
                (Vector3D*)&scratch.sp20, (Vector3D*)&scratch.sp20,
                (Vector3D*)((unsigned char*)&Level21_7AAB4_D_80070328.unk7a[3] - 0x98));
            if (Level21_7AAB4ApproximatePlanarDistance(&ownerRecord->position,
                                                       (Vector3D*)&scratch.sp20) < 0x1F40) {
                {
                    register int ground3 __asm__("3");
                    register int word2 __asm__("2");
                    register int global4 __asm__("4");
                    ground3 = ownerRecord->distanceToGround;
                    word2 = ownerRecord->position.z;
                    global4 = Level21_7AAB4_D_80070328.position.z;
                    ground3 = word2 - ground3;
                    word2 = ground3 - global4;
                    if (word2 < 0) {
                        var_v0_2 = (global4 - ground3) < 0x9C4;
                    } else {
                        var_v0_2 = word2 < 0x9C4;
                    }
                }
                if (var_v0_2 == 0) {
                    goto block_52;
                }
                goto block_54;
            }
        block_52:
            if ((Level21_7AAB4Field(privateRecord19, int*, 0x38) == 0) &&
                (Level21_7AAB4_D_8006C550[Level21_7AAB4Field(privateRecord19, int*, 0x48)].state ==
                 3)) {
            block_54:
                temp_a3 = Level21_7AAB4Field(privateRecord19, void**, 0x18);
                Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2C) = 0U;
                Level21_7AAB4Field(privateRecord19, short*, 0x30) = 0x1F40;
                Level21_7AAB4Field(privateRecord19, short*, 0x34) = 0;
                {
                    register int count3 __asm__("3");
                    register int numerator2 __asm__("2");
                    register int step4 __asm__("4");
                    register int zero5 __asm__("5");
                    register int zero6 __asm__("6");
                    count3 = Level21_7AAB4Field(temp_a3, short*, 0);
                    numerator2 = Level21_7AAB4Field(temp_a3, short*, 2);
                    step4 = count3 + 1;
                    numerator2 += step4;
                    count3 = numerator2 % count3;
                    __asm__ volatile("" : : "r"(count3) : "5", "6", "memory");
                    zero5 = 0;
                    zero6 = 0;
                    MATCHING_KEEP3(count3, zero5, zero6);
                    Level21_7AAB4Field(temp_a3, short*, 2) = count3;
                    Level21_7AAB4PlayMobySoundEvent(ownerRecord, zero5, zero6);
                }
                ownerRecord->state = 2;
                Level21_7AAB4RequestMobyAnimation(ownerRecord, 2);
            }
            goto block_135;
        case 2:
            shiftedGlobalWord16 = (int)Level21_7AAB4_D_80070328.unk8[1] >> 5;
            {
                register int angle2 __asm__("2");
                angle2 = Level21_7AAB4AbsoluteByteAngleDelta(
                    (int)ownerRecord->angle.yaw,
                    Level21_7AAB4PlanarHeadingLookup(
                        Level21_7AAB4_D_80070328.position.x - ownerRecord->position.x,
                        Level21_7AAB4_D_80070328.position.y - ownerRecord->position.y, 0));
                __asm__ volatile("" : : "r"(angle2) : "30", "memory");
                angleWord21 = angle2;
            }
            parameterWord23 = 9;
            literalOne30 = 1;
            MATCHING_KEEP(literalOne30);
            updatedHalfword3 = Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) + 0x1E;
            Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) = updatedHalfword3;
            if (shiftedGlobalWord16 < (short)updatedHalfword3) {
                Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) =
                    (unsigned short)shiftedGlobalWord16;
            }
            if ((short)Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) < 0x14A) {
                Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) = 0x14AU;
            }
            adjustmentWord20 = 0x1F4;
            if (ownerRecord->position.z == Level21_7AAB4ProbeGroundFromRaisedMoby(ownerRecord)) {
                privateHeightWord3 = Level21_7AAB4Field(privateRecord19, short*, 0x30);
                adjustmentWord20 =
                    (short)Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E);
                if (distanceWord17 < (privateHeightWord3 - 0x7D0)) {
                    adjustmentWord20 += 0x82;
                    goto block_68;
                }
                if (distanceWord17 < (privateHeightWord3 - 0x3E8)) {
                    adjustmentWord20 += 0x50;
                    goto block_68;
                }
                if ((privateHeightWord3 + 0x7D0) < distanceWord17) {
                    adjustmentWord20 -= 0x82;
                    goto block_68;
                }
                if ((privateHeightWord3 + 0x3E8) < distanceWord17) {
                    adjustmentWord20 -= 0x50;
                }
            block_68:
                if (angleWord21 < 0x46) {
                    lowerLimitWord2 =
                        (short)Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) + 0x28;
                    if (adjustmentWord20 < lowerLimitWord2) {
                        adjustmentWord20 = lowerLimitWord2;
                    }
                }
            }
            if ((ownerRecord->drawn != 0) &&
                (Level21_7AAB4AbsoluteByteAngleDelta(
                     (int)Level21_7AAB4_D_80070328.bodyRotation.yaw,
                     Level21_7AAB4PlanarHeadingLookup(
                         ownerRecord->position.x - Level21_7AAB4_D_80070328.position.x,
                         ownerRecord->position.y - Level21_7AAB4_D_80070328.position.y, 0)) <
                 0x28) &&
                (distanceWord17 < 0x3000)) {
                temp_v1_13 = ownerRecord->position.z - ownerRecord->distanceToGround;
                temp_v0_4 = temp_v1_13 - Level21_7AAB4_D_80070328.position.z;
                if (temp_v0_4 >= 0) {
                    if (temp_v0_4 < 0x1000) {
                        goto block_79;
                    }
                } else if ((Level21_7AAB4_D_80070328.position.z - temp_v1_13) < 0x1000) {
                block_79:
                    Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2C) =
                        (unsigned short)(Level21_7AAB4Field(privateRecord19, unsigned short*,
                                                            0x2C) +
                                         Level21_7AAB4_D_8006C648);
                }
            }
            scaledParameter4 = 0x1F40;
            if (Level21_7AAB4Field(privateRecord19, int*, 0x38) != 0) {
                scaledParameter4 = 0x2740;
            }
            if (Level21_7AAB4_D_8006C7C4 == 2) {
                numeratorWord2 = scaledParameter4 << 3;
                divideMagic3 = 0x51EB851F;
                MATCHING_OBSERVE2(numeratorWord2, divideMagic3);
                numeratorWord2 -= scaledParameter4;
                numeratorWord2 = ((numeratorWord2 << 2) + scaledParameter4) << 2;
                numeratorWord2 -= scaledParameter4;
                goto block_86;
            }
            if (Level21_7AAB4_D_8006C7C4 == 0) {
                divideMagic3 = 0x51EB851F;
                MATCHING_OBSERVE(divideMagic3);
                numeratorWord2 = scaledParameter4 * 0x50;
            block_86:
                {
                    int nativeHigh;
                    int highValue;
                    register int sign2 __asm__("2");
                    register int quotient3 __asm__("3");
                    __asm__ volatile(""
                                     : "=h"(nativeHigh)
                                     : "l"(numeratorWord2 * divideMagic3)
                                     : "memory");
                    sign2 = numeratorWord2 >> 31;
                    highValue = nativeHigh;
                    quotient3 = highValue >> 5;
                    scaledParameter4 = quotient3 - sign2;
                }
            }
            if (Level21_7AAB4Field(privateRecord19, int*, 0x38) == 0) {
                var_v0_5 = (short)Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2C) * 3;
            } else {
                var_v0_5 = (short)Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2C) * 2;
            }
            Level21_7AAB4Field(privateRecord19, short*, 0x30) =
                (short)(scaledParameter4 - var_v0_5);
            MATCHING_BARRIER_VOLATILE("memory");
            {
                register int reloaded2 __asm__("2");
                reloaded2 = Level21_7AAB4Field(privateRecord19, short*, 0x30);
                MATCHING_KEEP(reloaded2);
                if (reloaded2 < -0x3E8)
                    Level21_7AAB4Field(privateRecord19, short*, 0x30) = -0x3E8;
            }
            angleResult3 = Level21_7AAB4AbsoluteByteAngleDelta(
                (int)Level21_7AAB4_D_80070328.bodyRotation.yaw,
                Level21_7AAB4PlanarHeadingLookup(
                    ownerRecord->position.x - Level21_7AAB4_D_80070328.position.x,
                    ownerRecord->position.y - Level21_7AAB4_D_80070328.position.y, 0));
            MATCHING_KEEP(angleResult3);
            if ((angleWord21 < 0x28) && (({
                    register int predicate2 __asm__("2");
                    predicate2 = angleResult3 < 0x20;
                    MATCHING_KEEP(predicate2);
                    predicate2;
                })) &&
                (distanceWord17 < 0x1B58) &&
                (Level21_7AAB4Field(privateRecord19, short*, 0x32) < 0)) {
                Level21_7AAB4PlayMobySoundEvent(ownerRecord, 0, 0);
                if (Level21_7AAB4Field(privateRecord19, short*, 0x32) < 0x140) {
                    Level21_7AAB4Field(privateRecord19, short*, 0x32) = 0x140;
                }
                if ((short)Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) >= 0xA1) {
                    Level21_7AAB4Field(privateRecord19, unsigned short*, 0x2E) = 0xA0U;
                }
            }
            MATCHING_OBSERVE2_VOLATILE(angleWord21, distanceWord17);
            if (Level21_7AAB4Field(privateRecord19, short*, 0x34) != 0) {
                parameterWord23 = 3;
                MATCHING_KEEP(parameterWord23);
                particleIndex17 = 0;
                do {
                    randomResult16 = Level21_7AAB4RandBetween(0x78, 0x12C);
                    Level21_7AAB4CopyVector(&scratch.sp30, &ownerRecord->position);
                    scratch.sp30.z = ownerRecord->position.z;
                    {
                        register int random2 __asm__("2");
                        register short* base4 __asm__("4");
                        random2 = Level21_7AAB4RandSignedBetween(0, 0x14);
                        tableIndex5 = ownerRecord->angle.yaw;
                        base4 = Level21_7AAB4_D_80065920;
                        tableIndex5 += 0x80;
                        __asm__("" : "=r"(tableIndex5) : "0"(tableIndex5), "r"(base4));
                        tableIndex5 += random2;
                        MATCHING_KEEP(tableIndex5);
                        tableIndex5 &= 0xFF;
                        tablePointer4 = &base4[tableIndex5];
                    }
                    scratch.sp30.x =
                        (int)scratch.sp30.x + ((int)(*tablePointer4 * randomResult16) >> 0xC);
                    tablePointer5 = &Level21_7AAB4_D_800658A0[tableIndex5];
                    particleIndex17 += 1;
                    scratch.sp30.y += (int)(*tablePointer5 * randomResult16) >> 0xC;
                    scratch.sp40 = (int)(*tablePointer4 * 5) >> 0xA;
                    scratch.sp44 = (int)(*tablePointer5 * 5) >> 0xA;
                    scratch.sp48 = 0;
                    scratch.sp48 = Level21_7AAB4RandBetween(7, 0xC);
                    SpawnParticle(1, 0, &scratch.sp30, (Vector3D*)&scratch.sp40);
                } while (particleIndex17 < parameterWord23);
                parameterWord23 = 5;
            }
            helperResult16 = Level21_7AAB4_func_80035A80(
                ownerRecord, Level21_7AAB4Field(privateRecord19, void**, 0x18), 0x1F4,
                adjustmentWord20, 0, parameterWord23, 0x1E, literalOne30);
            Level21_7AAB4_func_80037A60(ownerRecord, ((unsigned char*)privateRecord19 + 0x32), 2,
                                        0x10, -0xC8);
            if (helperResult16 & 1) {
                temp_a1_3 = Level21_7AAB4Field(privateRecord19, void**, 0x18);
                {
                    register int numerator2 __asm__("2");
                    register int previous4 __asm__("4");
                    temp_v1_14 = Level21_7AAB4Field(temp_a1_3, short*, 0);
                    numerator2 = Level21_7AAB4Field(temp_a1_3, short*, 2);
                    previous4 = temp_v1_14 - 1;
                    numerator2 += previous4;
                    previousIndex17 = numerator2 % temp_v1_14;
                }
                temp_a0_5 = Level21_7AAB4Field(
                    ((previousIndex17 * 0x10) + Level21_7AAB4Field(temp_a1_3, int*, 0xC)), int*, 8);
                if ((ownerRecord->position.z < (temp_a0_5 - 0x200)) &&
                    (Level21_7AAB4Field(privateRecord19, short*, 0x32) < 0)) {
                    ownerRecord->position.z = temp_a0_5;
                    Level21_7AAB4_func_80037014(ownerRecord);
                }
                temp_v1_15 = Level21_7AAB4Field(privateRecord19, void**, 0x18);
                if (Level21_7AAB4Field(((Level21_7AAB4Field(temp_v1_15, short*, 2) * 0x10) +
                                        Level21_7AAB4Field(temp_v1_15, int*, 0xC)),
                                       int*, 0xC) == 0x1000) {
                    if (Level21_7AAB4ApproximatePlanarDistance(
                            &ownerRecord->position, &Level21_7AAB4_D_80070328.position) < 0x3001) {
                        temp_v1_16 = ownerRecord->position.z - ownerRecord->distanceToGround;
                        temp_v0_6 = temp_v1_16 - Level21_7AAB4_D_80070328.position.z;
                        if (temp_v0_6 >= 0) {
                            if (temp_v0_6 >= 0x1001)
                                goto block_114;
                            MATCHING_BARRIER_VOLATILE("memory");
                            goto block_115;
                        }
                        if ((Level21_7AAB4_D_80070328.position.z - temp_v1_16) >= 0x1001) {
                            goto block_114;
                        }
                        goto block_115;
                    }
                block_114:
                    ownerRecord->state = 0;
                    return;
                }
            block_115:
                temp_v1_17 = Level21_7AAB4Field(privateRecord19, void**, 0x18);
                Level21_7AAB4Field(privateRecord19, short*, 0x34) = 1;
                tableOffset16 = previousIndex17 * 0x10;
                if ((Level21_7AAB4Field((tableOffset16 + Level21_7AAB4Field(temp_v1_17, int*, 0xC)),
                                        int*, 0xC) &
                     0x300) &&
                    ((previousIndex17 == (Level21_7AAB4Field(temp_v1_17, short*, 0) - 1)) ||
                     ((Level21_7AAB4_rand() & 0xFF) >= 0x80))) {
                    temp_v1_18 = Level21_7AAB4Field(
                        (tableOffset16 +
                         Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x18), int*,
                                            0xC)),
                        int*, 0xC);
                    {
                        register int selector2 __asm__("2");
                        selector2 = temp_v1_18 >> 8;
                        MATCHING_KEEP(selector2);
                        selector2 = (selector2 - 1) * 4;
                        temp_v0_7 =
                            Level21_7AAB4Field((selector2 + (int)privateRecord19), void**, 0x1C);
                    }
                    Level21_7AAB4Field(privateRecord19, void**, 0x18) = temp_v0_7;
                    Level21_7AAB4Field(temp_v0_7, short*, 2) = (short)(temp_v1_18 & 0xFF);
                }
                MATCHING_OBSERVE_VOLATILE(tableOffset16);
                temp_v1_19 = Level21_7AAB4Field(privateRecord19, void**, 0x18);
                temp_a1_4 = (Level21_7AAB4Field(temp_v1_19, short*, 2) * 0x10) +
                            Level21_7AAB4Field(temp_v1_19, int*, 0xC);
                if (Level21_7AAB4Field(temp_a1_4, int*, 0xC) == 1) {
                    Level21_7AAB4Field(privateRecord19, short*, 0x32) = Level21_7AAB4_func_800365E4(
                        &ownerRecord->position, temp_a1_4, 0x1F4, -0x10, &scratch.sp50);
                }
                goto block_135;
            }
            goto block_135;
        case 3:
        case 20:
        case 21:
            temp_v0_8 = Level21_7AAB4_func_80055E84(ownerRecord);
            if ((temp_v0_8 >= 0x29) ||
                ((temp_v0_8 >= 9) &&
                 (Level21_7AAB4_D_80070328.movementState == MOVEMENT_STATE_FALL))) {
                if (ownerRecord->state == 3) {
                    ownerRecord->state = 0x14;
                    if (poolRecord22 != 0) {
                        Level21_7AAB4CopyVector(
                            &scratch.sp30,
                            Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x44),
                                               Vector3D**, 0xC));
                        scratch.sp30.z += 0x164;
                        temp_v0_9 = Level21_7AAB4Field(
                            Level21_7AAB4Field(privateRecord19, void**, 0x44), Vector3D**, 0xC);
                        Level21_7AAB4_func_80013D44(
                            &scratch.sp30,
                            Level21_7AAB4PlanarHeadingLookup(
                                Level21_7AAB4Field(temp_v0_9, int*, 0x10) - temp_v0_9->x,
                                Level21_7AAB4Field(temp_v0_9, int*, 0x14) - temp_v0_9->y, 0),
                            0, 0);
                        if (Level21_7AAB4_D_80070328.currentHealth < 0) {
                            Level21_7AAB4_D_80070328.currentHealth = 0;
                        }
                    }
                }
            }
            if ((ownerRecord->state == 0x14) && (Level21_7AAB4_D_8006E048 & 1)) {
                temp_s1_2 = poolRecord22->mobyTag;
                Level21_7AAB4CopyVector(
                    &scratch.sp58, ((void*)((unsigned char*)Level21_7AAB4Field(
                                                Level21_7AAB4Field(privateRecord19, void**, 0x44),
                                                Vector3D**, 0xC) +
                                            0x10)));
                Level21_7AAB4CopyVector(&poolRecord22->position, &scratch.sp58);
                Level21_7AAB4_func_80037014(poolRecord22);
                poolRecord22->subtype = 0xFE;
                Level21_7AAB4RefreshMobySpatialGridAndBasis(poolRecord22, 2);
                poolRecord22->state = 0;
                temp_v0_10 = Level21_7AAB4Field(Level21_7AAB4Field(privateRecord19, void**, 0x44),
                                                Vector3D**, 0xC);
                temp_v0_11 = Level21_7AAB4PlanarHeadingLookup(
                    temp_v0_10->x - Level21_7AAB4Field(temp_v0_10, int*, 0x10),
                    temp_v0_10->y - Level21_7AAB4Field(temp_v0_10, int*, 0x14), 0);
                poolRecord22->angle.yaw = temp_v0_11;
                Level21_7AAB4Field(temp_s1_2, short*, 6) =
                    (short)(((temp_v0_11 & 0xFF) + 0x80) & 0xFF);
                ownerRecord->state = 0x15;
            }
            Level21_7AAB4_func_80037A60(poolRecord22, ((unsigned char*)privateRecord19 + 0x40), 4,
                                        0xE, -0xC8);
            if (Level21_7AAB4_func_80035194(ownerRecord, privateRecord19) == 0x100) {
                Level21_7AAB4RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level21_7AAB4_func_8003BA00(ownerRecord);
                Level21_7AAB4_func_800369B8(ownerRecord, 0x20);
            block_134:
                Level21_7AAB4DeleteMoby(ownerRecord);
                return;
            }
        block_135:
        default:
            if (((ownerRecord->state == 0x1E) || (ownerRecord->state == 0xA) ||
                 (ownerRecord->state < 3U)) &&
                (poolRecord22 != 0)) {
                poolRecord22->subtype = 0xFE;
                Level21_7AAB4RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level21_7AAB4InterpolateMobyVertex(ownerRecord, 0, &poolRecord22->position);
                poolRecord22->position.z -= 0xFA;
                poolRecord22->angle.yaw = ownerRecord->angle.yaw;
            }
            return;
    }
}
#undef Level21_7AAB4Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define ControllerBA14Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int ControllerBA14_func_80021ED8() __asm__("func_80021ED8");                 /* extern */
int ControllerBA14_func_80035A80() __asm__("func_80035A80");                 /* extern */
int ControllerBA14_func_800399E8() __asm__("func_800399E8");                 /* extern */
int ControllerBA14_func_80039B6C() __asm__("func_80039B6C");                 /* extern */
int ControllerBA14ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int ControllerBA14RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int ControllerBA14_func_80055E84() __asm__("func_80055E84");                 /* extern */
extern int ControllerBA14_D_8006C550 __asm__("D_8006C550");
extern int ControllerBA14_D_8006C770 __asm__("D_8006C770");
extern int ControllerBA14_D_8006C7C4 __asm__("D_8006C7C4");

void func_level_21_8007BA14(Moby* incomingMoby) {
    register Moby* moby __asm__("$16") = incomingMoby;

    register Vector3D* position19 __asm__("$19");
    register int duration2 __asm__("$2");
    register int linkedIndex17 __asm__("$17");
    register int helperResult19 __asm__("$19");
    register int predicate2 __asm__("$2");
    register int state2 __asm__("$2");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int call6 __asm__("$6");
    register int call7 __asm__("$7");
    register void* linkedMoby17 __asm__("$17");
    register void* linkedMoby17Alias __asm__("$17");
    register void* tag18 __asm__("$18");
    void* temporaryPointer;
    register void* pointer4 __asm__("$4");

    MATCHING_KEEP(moby);
    tag18 = moby->mobyTag;
    value3 = ControllerBA14Field(tag18, int*, 0x2C);
    value2 = value3 * 11;
    value3 = ControllerBA14_D_8006C550;
    value2 <<= 3;
    linkedMoby17 = (void*)(value3 + value2);
    MATCHING_KEEP(linkedMoby17);
    if (moby->state != 0x7D) {
        if (ControllerBA14Field(tag18, int*, 0x34) == 0) {
            ControllerBA14_func_800399E8(incomingMoby, tag18 + 0x34);
        }
        if (moby->damageFlags & 0x90000) {
            if (moby->state != 5) {
                func_80038F14(moby, tag18, 0U, 5);
                ControllerBA14Field(tag18, short*, 4) = 0xAA;
                ControllerBA14Field(tag18, signed char*, 0xE) = 2;
            }
        }
        switch (moby->state) {
            case 0:
                if (moby->substate != 0) {
                    moby->substate = 0;
                    ControllerBA14Field(tag18, short*, 0x38) = 0;
                    if (moby->animationState.nextId != 1) {
                        ControllerBA14_D_8006C770 = 0;
                        moby->animationProgress = 0x72;
                        moby->animationState.nextId = 1;
                        moby->animationState.nextFrame = 0;
                        func_80035734(moby);
                    }
                    state2 = 0x14;
                    goto block_50;
                }
                goto block_52;
            case 1:
                func_8003585C(
                    moby,
                    func_8004E880(ControllerBA14Field(linkedMoby17, int*, 0xC) - moby->position.x,
                                  ControllerBA14Field(linkedMoby17, int*, 0x10) - moby->position.y,
                                  0),
                    7, 0, 0, 0);
                func_80035DDC(moby, 0x78, 0, 0, 5);
                if (*ControllerBA14Field(tag18, int**, 0x30) != 0) {
                    moby->state = 0x15;
                }
                if (ControllerBA14ApproximatePlanarDistance(&moby->position, linkedMoby17 + 0xC) <
                    0x10CC) {
                    value3 = ControllerBA14_D_8006C7C4;
                    switch (value3) {
                        case 0:
                            value2 = 40;
                            goto durationStore;
                        case 1:
                            value2 = 20;
                            goto durationStore;
                        case 2:
                            value2 = 10;
                            goto durationStore;
                        default:
                            goto state2;
                    }
                durationStore:
                    ControllerBA14Field(tag18, short*, 0x3A) = value2;
                state2:
                    /* End the prior value in register 2; the state store produces 2 anew. */
                    __asm__("" : "=r"(value2));
                    moby->state = 2;
                    func_80034F40(moby, 2);
                }
                goto block_52;
            case 21:
                if (moby->animationState.nextId != 4) {
                    ControllerBA14_D_8006C770 = 0;
                    moby->animationProgress = 0x72;
                    moby->animationState.nextId = 4;
                    moby->animationState.nextFrame = 0;
                    func_80035734(moby);
                }
                goto block_52;
            case 2:
                func_8003585C(
                    moby,
                    func_8004E880(ControllerBA14Field(linkedMoby17, int*, 0xC) - moby->position.x,
                                  ControllerBA14Field(linkedMoby17, int*, 0x10) - moby->position.y,
                                  0),
                    7, 0, 0, 0);
                if (ControllerBA14ApproximatePlanarDistance(&moby->position, linkedMoby17 + 0xC) >=
                    0x709) {
                    func_80035DDC(moby, 0x78, 0, 0, 5);
                }
                if (ControllerBA14_D_8006C770 != 0) {
                    moby->state = 6;
                    func_80034F40(moby, 6);
                }
                goto block_52;
            case 6:
                func_8003585C(
                    moby,
                    func_8004E880(ControllerBA14Field(linkedMoby17, int*, 0xC) - moby->position.x,
                                  ControllerBA14Field(linkedMoby17, int*, 0x10) - moby->position.y,
                                  0),
                    7, 0, 0, 0);
                position19 = &moby->position;
                pointer4 = position19;
                MATCHING_KEEP(pointer4);
                linkedMoby17Alias = linkedMoby17 + 0xC;
                if (ControllerBA14ApproximatePlanarDistance(pointer4, linkedMoby17Alias) >= 0x709) {
                    func_80035DDC(moby, 0x78, 0, 0, 5);
                    MATCHING_KEEP(tag18);
                }
                pointer4 = tag18 + 0x3A;
                if ((func_800359A4(pointer4, 2) != 0) &&
                    (ControllerBA14ApproximatePlanarDistance(position19, linkedMoby17Alias) <
                     0x9C4)) {
                    moby->state = 3;
                    func_80034F40(moby, 3);
                }
                goto block_52;
            case 3:
                value2 = ControllerBA14_func_80055E84(moby);
                call6 = 0;
                __asm__("" : "=r"(call6) : "0"(call6), "r"(value2));
                helperResult19 = value2;
                call7 = ControllerBA14Field(linkedMoby17, int*, 12);
                call4 = moby->position.x;
                value3 = ControllerBA14Field(linkedMoby17, int*, 16);
                call5 = moby->position.y;
                call4 = call7 - call4;
                call5 = value3 - call5;
                value2 = func_8004E880(call4, call5, call6);
                func_8003585C(moby, value2, 7, 0, 0, 0);
                value2 =
                    ControllerBA14ApproximatePlanarDistance(&moby->position, linkedMoby17 + 12);
                value2 = value2 < 0x709;
                if (value2) {
                    predicate2 = helperResult19 < 6;
                } else {
                    predicate2 = helperResult19 < 6;
                    MATCHING_KEEP(predicate2);
                    value2 = 5;
                    func_80035DDC(moby, 120, 0, 0, value2);
                    predicate2 = helperResult19 < 6;
                }
                if (!predicate2) {
                    value3 = 1;
                    value2 = moby->angle.yaw;
                    ControllerBA14Field(linkedMoby17, signed char*, 0x49) = value3;
                    value2 += 52;
                    ControllerBA14Field(linkedMoby17, signed char*, 0x51) = value2;
                    value3 = ControllerBA14Field(tag18, int*, 0x30);
                    value2 = 1;
                    *(int*)value3 = value2;
                }
                if (ControllerBA14_D_8006C770 != 0) {
                    moby->state = 4;
                    func_80034F40(moby, 4);
                }
                goto block_52;
            case 4:
                func_8003585C(
                    moby,
                    func_8004E880(ControllerBA14Field(linkedMoby17, int*, 0xC) - moby->position.x,
                                  ControllerBA14Field(linkedMoby17, int*, 0x10) - moby->position.y,
                                  0),
                    7, 0, 0, 0);
                goto block_52;
            case 5:
                if (func_80035194(moby, tag18) == 0x100) {
                    ControllerBA14RefreshMobySpatialGridAndBasis(moby, 4);
                    func_800369B8(moby, 0x30);
                    moby->damageFlags = 0;
                    func_8004F178(&moby->position, tag18 + 0x18);
                    func_80037014(moby);
                    moby->subtype = 0xFE;
                    ControllerBA14RefreshMobySpatialGridAndBasis(moby, 2);
                    moby->state = 0;
                    func_80034F40(moby, 0);
                    return;
                }
                goto block_52;
            case 20:
                linkedIndex17 = ControllerBA14_func_80035A80(
                    moby, ControllerBA14Field(tag18, void**, 0x24), 0x100, 0x78, 0, 6, 0x14, 5);
                if (ControllerBA14Field(tag18, short*, 0x38) == 0) {
                    temporaryPointer = ControllerBA14Field(tag18, void**, 0x24);
                    if (ControllerBA14ApproximatePlanarDistance(
                            &moby->position, ControllerBA14Field(temporaryPointer, int*, 0xC) +
                                                 (ControllerBA14Field(temporaryPointer, short*, 2) *
                                                  0x10)) < 0xFA0) {
                        func_8003BB10(moby, 5, 0);
                        ControllerBA14_func_80021ED8(ControllerBA14Field(tag18, int*, 0x28) + 0xD,
                                                     0xFC, 0);
                        ControllerBA14Field(tag18, short*, 0x38) = 1;
                    }
                }
                if ((value2 = linkedIndex17 & 1)) {
                    ControllerBA14_func_80021ED8(ControllerBA14Field(tag18, int*, 0x28) + 0xD, 0xFC,
                                                 0);
                    state2 = 1;
                    goto block_50;
                }
                goto block_51;
            block_50:
                moby->state = state2;
            default:
            block_51:
            block_52:
                ControllerBA14RefreshMobySpatialGridAndBasis(moby, 4);
                if (ControllerBA14Field(tag18, int*, 0x34) != 0) {
                    ControllerBA14_func_80039B6C(moby, tag18 + 0x34);
                }
                break;
        }
    }
}
#undef ControllerBA14Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_21/moby/func_level_21_8007C03C.s SHA256 18eba18b74236a838343d1627b73e05283f6ed42d687a3b99aa71e524344edd7. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level21_7C03CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level21_7C03C_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level21_7C03C_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level21_7C03C_D_8006C550 __asm__("D_8006C550");
extern Spyro Level21_7C03C_D_80070328 __asm__("D_80070328");
void Level21_7C03C_func_80013ACC(Moby*, int) __asm__("func_80013ACC");
extern int Level21_7C03C_func_8001A358(Vector3D*, int) __asm__("func_8001A358");
void Level21_7C03CRequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level21_7C03C_func_80035194(Moby*, void*) __asm__("func_80035194");
void Level21_7C03CEmptyAnimationTransitionHook(Moby* moby) __asm__("func_80035734");
int Level21_7C03CTurnMobyTowardPlayer(Moby* owner18, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level21_7C03CCountTimerDown(void*, int) __asm__("func_800359A4");
int Level21_7C03CProbeGroundFromRaisedMoby(Moby* moby) __asm__("func_80035D38");
void Level21_7C03C_func_800369B8() __asm__("func_800369B8");
void Level21_7C03C_func_80038BF8(Moby*, EnemyTag*, int, int) __asm__("func_80038BF8");
void Level21_7C03C_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
int Level21_7C03CPlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
extern int Level21_7C03CPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern int Level21_7C03CMeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
extern void Level21_7C03CShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level21_7C03CCopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level21_7C03CAddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level21_7C03CSubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
extern int Level21_7C03CAbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level21_7C03CApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level21_7C03CDeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level21_7C03CRefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level21_7C03C_func_80055E84(Moby*) __asm__("func_80055E84");
extern int Level21_7C03C_rand() __asm__("rand");

int Level21_7C03C_func_80035A80() __asm__("func_80035A80");
/* extern */
int Level21_7C03C_func_80036220() __asm__("func_80036220");
/* extern */
int Level21_7C03C_func_800368A4() __asm__("func_800368A4");
/* extern */
unsigned char Level21_7C03C_func_80036A68() __asm__("func_80036A68");
/* extern */
unsigned char Level21_7C03CScaleVectorRatioQ15() __asm__("func_8004F08C");
/* extern */
unsigned char Level21_7C03CInterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern int Level21_7C03C_D_8006C770 __asm__("D_8006C770");
extern int Level21_7C03C_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level21_7C03C_D_8006E020 __asm__("D_8006E020");
extern int Level21_7C03C_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level21_7C03C_D_8006E040 __asm__("D_8006E040");
extern int Level21_7C03C_D_8006E160 __asm__("D_8006E160");
extern int Level21_7C03C_D_8006E164 __asm__("D_8006E164");
extern int Level21_7C03C_D_8006E344 __asm__("D_8006E344");

void func_level_21_8007C03C(Moby* inputOwner) {
    /* Original frame0x90 and scratch SP20/30/40/50/60 retained.
     * Private arithmetic uses raw byte offsets, matching the disc producers.
     * The first helper receives owner/A1 private1C/A2=2 as originally encoded.
     * Repeated movement loads and the state reload remain separate producers.
     * States5/6 share the original forward reset callback at original word670.
     * Empty constraints and comment-only markers emit no instructions.
     * Helper semantics, units/fixed point, cadence and runtime captures unresolved.
     * AI generated;
      not human reviewed. */
    register Moby* owner18 __asm__("$18") = inputOwner;
    register int value2 __asm__("$2");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int* globalPointer3 __asm__("$3");
    register int* movementPointer4 __asm__("$4");
    struct {
        Vector3D sp20;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[4];
        Vector3D sp40;
        unsigned char pad4C[4];
        Vector3D sp50;
        unsigned char pad5C[4];
        Vector3D sp60;
        unsigned char pad6C[4];
    } scratch;

    register unsigned char* private19 __asm__("$19");
    register Moby* child20 __asm__("$20");
    register Vector3D* childPosition16 __asm__("$16");
    register int var_v0_2 __asm__("$2");
    int temp_a0;
    int temp_a1;
    register int helperResult16 __asm__("$16");
    register int temp_v0 __asm__("$2");
    register int temp_v0_3 __asm__("$3");
    register int temp_v0_4 __asm__("$2");
    int temp_v0_6;
    register int temp_v1_2 __asm__("$3");
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_6;
    register int temp_v1_7 __asm__("$3");
    register int var_v0 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    unsigned short temp_v0_5;
    register int temp_v1 __asm__("$3");
    unsigned char temp_v1_3;
    register void* childPrivate21 __asm__("$21");
    void* var_a0;

    private19 = (void*)owner18->mobyTag;
    Level21_7C03CField(private19, int*, 0x1C) =
        Level21_7C03C_func_800368A4(owner18, Level21_7C03CField(private19, int*, 0x1C), 2);
    if ((owner18->damageFlags & 0x8A0000) && (owner18->state != 7)) {
        Level21_7C03C_func_80036A68(owner18, 0, 0, 0);
        Level21_7C03C_func_80038BF8(owner18, private19, 1, 7);
        globalPointer3 = &Level21_7C03C_D_8006E164;
        Level21_7C03CField(private19, short*, 6) =
            (short)Level21_7C03CField(private19, unsigned short*, 0x6A);
        owner18->unknown4 = 1;
        if (*globalPointer3 == (int)owner18) {
            Level21_7C03C_D_8006E160 = 0;
            *globalPointer3 = 0;
        }
    }
    MATCHING_BARRIER_VOLATILE("memory");
    temp_v1 = owner18->state;
    MATCHING_KEEP(temp_v1);
    owner18->damageFlags = 0;
    if ((((unsigned int)(temp_v1 - 2) < 2U) || ((temp_v1 & 0xFF) == 4)) &&
        (Level21_7C03CApproximatePlanarDistance(&owner18->position,
                                                &Level21_7C03C_D_80070328.position) < 0x2400)) {
        temp_v1_2 = owner18->distanceToGround;
        value2 = owner18->position.z;
        temp_v1_2 = value2 - temp_v1_2;
        temp_v0 = temp_v1_2 - Level21_7C03C_D_80070328.position.z;
        if (temp_v0 >= 0) {
            if (temp_v0 < 0x5DC) {
                goto block_11;
            }
            goto block_13;
        }
        temp_v0 = Level21_7C03C_D_80070328.position.z - temp_v1_2;
        if (temp_v0 < 0x5DC) {
        block_11:
            if (Level21_7C03C_D_8006E160 == 0) {
                Level21_7C03C_func_80013ACC(owner18, 0xC);
            }
        } else {
            goto block_13;
        }
    } else {
    block_13:
        globalPointer3 = &Level21_7C03C_D_8006E164;
        if (*globalPointer3 == (int)owner18) {
            Level21_7C03C_D_8006E160 = 0;
            *globalPointer3 = 0;
        }
    }
    value2 = Level21_7C03CField(private19, short*, 0x6E);
    if (value2) {
        value2 = 4;
        MATCHING_KEEP(value2);
        movementPointer4 = (int*)((unsigned char*)&Level21_7C03C_D_80070328 + 0x50);
        temp_v1_2 = *(volatile int*)movementPointer4;
        if (temp_v1_2 != value2)
            goto afterCharge;
        Level21_7C03CField(private19, short*, 0x6E) = 0;
        if (*(volatile int*)movementPointer4 == temp_v1_2) {
            Level21_7C03C_D_80070328.union144.a.unk13cb = (int)owner18;
            Level21_7C03C_D_80070328.animationStateFrames = 0;
        }
    }
afterCharge:
    temp_v1_3 = owner18->state;
    switch (temp_v1_3) {
        case 0:
            Level21_7C03CTurnMobyTowardPlayer(owner18, 6, 0, 0);
            if (Level21_7C03CField(private19, int*, 0x34) != 0) {
                temp_v1_4 = Level21_7C03CField(private19, int*, 0x70);
                if ((temp_v1_4 == -1) ||
                    (var_a0 = private19 + 0x2C,
                     (((unsigned char)Level21_7C03C_D_8006C550[temp_v1_4].state < 0x80U) == 0))) {
                    if ((Level21_7C03C_func_80036220(&Level21_7C03C_D_80070328, private19 + 0x38, 0,
                                                     0) != 0) ||
                        (Level21_7C03C_func_80036220(&Level21_7C03C_D_80070328, private19 + 0x50, 0,
                                                     0) != 0)) {
                        Level21_7C03CField(private19, int*, 0x34) = 0;
                        owner18->state = 1;
                        return;
                    }
                    goto block_27;
                }
                goto block_28;
            }
        block_27:
            var_a0 = private19 + 0x2C;
        block_28:
            if ((Level21_7C03CCountTimerDown(var_a0, 4) != 0) &&
                ((temp_v1_5 = Level21_7C03CField(private19, int*, 0x70), (temp_v1_5 == -1)) ||
                 ((unsigned char)Level21_7C03C_D_8006C550[temp_v1_5].state >= 0x80U)) &&
                (Level21_7C03CField(private19, short*, 0x6C) == 0) &&
                (Level21_7C03CAbsoluteByteAngleDelta(
                     (int)owner18->angle.yaw,
                     Level21_7C03CPlanarHeadingLookup(
                         Level21_7C03C_D_80070328.position.x - owner18->position.x,
                         Level21_7C03C_D_80070328.position.y - owner18->position.y, 0)) < 0x14) &&
                (Level21_7C03CAbsoluteByteAngleDelta(
                     (int)(Level21_7C03C_D_8006E040 << 0x10) >> 0x14,
                     Level21_7C03CPlanarHeadingLookup(
                         owner18->position.x - Level21_7C03C_D_8006E020,
                         owner18->position.y - Level21_7C03C_D_8006E024, 0)) < 0x18) &&
                (Level21_7C03CApproximatePlanarDistance(&owner18->position,
                                                        &Level21_7C03C_D_80070328.position) <
                 Level21_7C03CField(private19, int*, 0x20))) {
                temp_a1 = owner18->position.z - owner18->distanceToGround;
                temp_v1_6 = temp_a1 - Level21_7C03C_D_80070328.position.z;
                if (temp_v1_6 < 0x190) {
                    temp_a0 = Level21_7C03CField(private19, int*, 0x24);
                    if (temp_v1_6 >= 0) {
                        if (temp_v1_6 < temp_a0)
                            goto block_40;
                        __asm__ volatile("# original positive cutoff" ::: "memory");
                        goto block_41;
                    }
                    if ((Level21_7C03C_D_80070328.position.z - temp_a1) < temp_a0) {
                    block_40:
                        argument4 = (int)owner18;
                        value2 = Level21_7C03C_D_8006C7C4;
                        argument5 = 2;
                        Level21_7C03CField(private19, int*, 0x28) = 0;
                        value2 += 2;
                        Level21_7C03CField(private19, unsigned short*, 0x30) = value2;
                        goto setState2;
                    }
                    goto block_41;
                }
            }
        block_41:
            if (owner18->animationState.nextId != 0) {
                Level21_7C03C_D_8006C770 = 0;
                owner18->animationProgress = 0x72;
                owner18->animationState.nextId = 0;
                owner18->animationState.nextFrame = 0;
                Level21_7C03CEmptyAnimationTransitionHook(owner18);
                return;
            }
        default:
            return;
        case 1:
            if (Level21_7C03CCountTimerDown(private19 + 0x74, 4) != 0) {
                helperResult16 = Level21_7C03C_func_80035A80(
                    owner18, Level21_7C03CField(private19, int*, 0x18), 0x100, 0xA0, 0, 7, 0x28, 5);
                if (owner18->animationState.nextId != 1) {
                    Level21_7C03C_D_8006C770 = 0;
                    owner18->animationProgress = 0x72;
                    owner18->animationState.nextId = 1;
                    owner18->animationState.nextFrame = 0;
                    Level21_7C03CEmptyAnimationTransitionHook(owner18);
                }
                value2 = Level21_7C03CField(private19, short*, 0x6C);
                if (value2 == 0) {
                    if (Level21_7C03CApproximatePlanarDistance(
                            &owner18->position, &Level21_7C03C_D_80070328.position) < 0xDAC) {
                        argument4 = (int)owner18;
                        argument5 = 2;
                        value2 = 1;
                        Level21_7C03CField(private19, short*, 0x6E) = value2;
                    setState2:
                        value2 = 2;
                        Level21_7C03CField((void*)argument4, unsigned char*, 0x48) = value2;
                        Level21_7C03CRequestMobyAnimation((void*)argument4, argument5);
                        return;
                    }
                    goto block_51;
                }
            block_51:
                var_v0 = helperResult16 & 2;
                if (var_v0 != 0) {
                    Level21_7C03CField(private19, short*, 0x6C) = 0;
                    owner18->state = 0;
                    return;
                }
            }
            break;
        case 2:
            Level21_7C03CTurnMobyTowardPlayer(owner18, 6, 0, 0);
            if (Level21_7C03C_D_8006C770 != 0) {
                owner18->substate = 0;
                temp_v1_2 = Level21_7C03C_D_8006C7C4;
                value2 = 1;
                if (temp_v1_2 == value2)
                    goto modeOne;
                value2 = temp_v1_2 < 2;
                if (!value2)
                    goto modeAtLeastTwo;
                value2 = 50;
                if (!temp_v1_2)
                    goto storeMode;
                goto afterMode;
            modeAtLeastTwo:
                value2 = 2;
                if (temp_v1_2 == value2)
                    goto modeTwo;
                value2 = 10;
                __asm__ volatile("# original nonselected mode" ::: "memory");
                goto afterMode;
            modeTwo:
                value2 = 10;
                goto storeMode;
            modeOne:
                value2 = 30;
            storeMode:
                Level21_7C03CField(private19, short*, 0x32) = value2;
            afterMode:
                owner18->state = 3;
                Level21_7C03CRequestMobyAnimation(owner18, 3);
                return;
            }
            break;
        case 3:
            Level21_7C03CTurnMobyTowardPlayer(owner18, 7, 0, 0);
            if (Level21_7C03CCountTimerDown(private19 + 0x32, 2) != 0) {
                Level21_7C03CField(private19, short*, 0x6E) = 0;
                owner18->state = 4;
                Level21_7C03CRequestMobyAnimation(owner18, 4);
            }
            if ((Level21_7C03C_D_8006E344 != 0) ||
                (Level21_7C03CAbsoluteByteAngleDelta(
                     (int)(Level21_7C03C_D_8006E040 << 0x10) >> 0x14,
                     Level21_7C03CPlanarHeadingLookup(
                         owner18->position.x - Level21_7C03C_D_8006E020,
                         owner18->position.y - Level21_7C03C_D_8006E024, 0)) >= 0x1F)) {
                Level21_7C03CField(private19, int*, 0x2C) = 0x78;
                owner18->state = 0;
                Level21_7C03CRequestMobyAnimation(owner18, 0);
                return;
            }
            break;
        case 4:
            Level21_7C03CTurnMobyTowardPlayer(owner18, 8, 0, 0);
            if ((unsigned int)(Level21_7C03C_D_80070328.movementState - 7) < 2U) {
                Level21_7C03CField(private19, int*, 0x28) = 1;
            }
            if ((Level21_7C03C_D_8006E344 != 0) ||
                (Level21_7C03CAbsoluteByteAngleDelta(
                     (int)(Level21_7C03C_D_8006E040 << 0x10) >> 0x14,
                     Level21_7C03CPlanarHeadingLookup(
                         owner18->position.x - Level21_7C03C_D_8006E020,
                         owner18->position.y - Level21_7C03C_D_8006E024, 0)) >= 0x1F)) {
                Level21_7C03CField(private19, int*, 0x2C) = 0x78;
                owner18->state = 0;
                Level21_7C03CRequestMobyAnimation(owner18, 0);
            }
            if ((owner18->substate == 0) && (Level21_7C03C_func_80055E84(owner18) >= 0)) {
                child20 = SpawnMoby(0x130, owner18);
                MATCHING_KEEP(child20);
                if (child20 != 0) {
                    childPrivate21 = child20->mobyTag;
                    owner18->substate = 1;
                    child20->unknown |= 0x80000000;
                    child20->angle.yaw = owner18->angle.yaw;
                    Level21_7C03CRefreshMobySpatialGridAndBasis(owner18, 4);
                    Level21_7C03CInterpolateMobyVertex(owner18, 0, &scratch.sp20);
                    Level21_7C03CInterpolateMobyVertex(owner18, 1, &scratch.sp30);
                    childPosition16 = &child20->position;
                    Level21_7C03CAddVector(childPosition16, &scratch.sp20, &scratch.sp30);
                    Level21_7C03CShiftVectorRightTowardZero(childPosition16, 1);
                    Level21_7C03CCopyVector(&scratch.sp40, &Level21_7C03C_D_80070328.position);
                    temp_v0_3 = Level21_7C03C_func_8001A358(&scratch.sp40, 0x1000);
                    argument4 = scratch.sp40.z;
                    value2 = argument4 - temp_v0_3;
                    if (value2 < 0)
                        goto negativeHeight;
                    if (value2 < 1800)
                        goto adjustHeight;
                    goto keepHeight;
                negativeHeight:
                    value2 = temp_v0_3 - argument4;
                    if (value2 < 1800)
                        goto adjustHeight;
                    goto keepHeight;
                adjustHeight:
                    value2 = temp_v0_3 + 300;
                    scratch.sp40.z = value2;
                keepHeight:
                    Level21_7C03CSubtractVector((Vector3D*)childPrivate21, &scratch.sp40,
                                                &child20->position);
                    Level21_7C03CScaleVectorRatioQ15(
                        childPrivate21,
                        Level21_7C03CMeasureVectorLength((Vector3D*)childPrivate21, 1), 0x118);
                    Level21_7C03CField(childPrivate21, short*, 0xC) = 0xB4;
                    Level21_7C03CField(childPrivate21, int*, 0x10) = 0;
                    Level21_7C03CField(childPrivate21, short*, 0xE) = 0xA;
                }
            }
            if (Level21_7C03C_D_8006C770 != 0) {
                owner18->substate = 0;
                temp_v0_5 = Level21_7C03CField(private19, unsigned short*, 0x30) - 1;
                Level21_7C03CField(private19, unsigned short*, 0x30) = temp_v0_5;
                if ((temp_v0_5 << 0x10) <= 0) {
                    owner18->state = 5;
                    Level21_7C03CRequestMobyAnimation(owner18, 5);
                    return;
                }
            }
            break;
        case 5:
            Level21_7C03CTurnMobyTowardPlayer(owner18, 6, 0, 0);
            if ((unsigned int)(Level21_7C03C_D_80070328.movementState - 7) < 2U) {
                Level21_7C03CField(private19, int*, 0x28) = 1;
            }
            if (Level21_7C03C_D_8006C770 != 0) {
                Level21_7C03CField(private19, int*, 0x2C) = 0x1E;
                if (Level21_7C03CField(private19, int*, 0x28) != 0) {
                    owner18->state = 6;
                    Level21_7C03CRequestMobyAnimation(owner18, 6);
                    return;
                }
                goto resetStateFrom5Or6;
            }
            break;
        case 6:
            temp_v0_6 = Level21_7C03C_func_80055E84(owner18);
            if ((unsigned int)(temp_v0_6 - 0x11) < 0x3DU) {
                Level21_7C03CRefreshMobySpatialGridAndBasis(owner18, 4);
                Level21_7C03CInterpolateMobyVertex(owner18, 0, &scratch.sp50);
                Level21_7C03CInterpolateMobyVertex(owner18, 1, &scratch.sp60);
                Level21_7C03CAddVector(&scratch.sp20, &scratch.sp50, &scratch.sp60);
                Level21_7C03CShiftVectorRightTowardZero(&scratch.sp20, 1);
                if (temp_v0_6 < 0x44) {
                    scratch.sp30.x = Level21_7C03C_rand() & 0xF;
                    scratch.sp30.y = Level21_7C03C_rand() & 0xF;
                    MATCHING_BARRIER_VOLATILE("memory");
                    scratch.sp30.z = 0x1C;
                } else {
                    temp_v1_7 = (owner18->angle.yaw - 0x40) & 255;
                    temp_v1_7 <<= 1;
                    argument4 = *(short*)((unsigned char*)Level21_7C03C_D_80065920 + temp_v1_7);
                    MATCHING_KEEP(argument4);
                    value2 = argument4 * 25;
                    scratch.sp30.x = value2 >> 11;
                    temp_v1_7 = *(short*)((unsigned char*)Level21_7C03C_D_800658A0 + temp_v1_7);
                    value2 = 28;
                    scratch.sp30.z = value2;
                    value2 = temp_v1_7 * 25;
                    scratch.sp30.y = value2 >> 11;
                }
                Level21_7C03CField(SpawnParticle(1, 0, &scratch.sp20, (Vector3D*)&scratch.sp30),
                                   signed char*, 2) = 2;
            }
            Level21_7C03CTurnMobyTowardPlayer(owner18, 6, 0, 0);
            if (Level21_7C03C_D_8006C770 != 0) {
            resetStateFrom5Or6:
                owner18->state = 0;
                Level21_7C03CRequestMobyAnimation(owner18, 0);
                return;
            }
            break;
        case 7:
            if (Level21_7C03CField(private19, short*, 6) < -0x64) {
                if ((Level21_7C03CField(private19, int*, 0x78) == -1) &&
                    (((owner18->position.z - owner18->distanceToGround) -
                      Level21_7C03CProbeGroundFromRaisedMoby(owner18)) >= 0xFA1)) {
                    Level21_7C03CField(private19, int*, 0x78) =
                        Level21_7C03CPlayMobySoundEvent(owner18, 0, 0);
                }
            }
            if (Level21_7C03C_func_80035194(owner18, private19) == 0x100) {
                Level21_7C03CRefreshMobySpatialGridAndBasis(owner18, 4);
                Level21_7C03C_func_8003BA00(owner18);
                Level21_7C03C_func_800369B8(owner18, 0x20);
                Level21_7C03CDeleteMoby(owner18);
            }
            break;
    }
}
#undef Level21_7C03CField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_21/moby/func_level_21_8007CB8C.s SHA256 42c2f5149e2459cd588658f2f7531d655927137cb14fe9e7b12abfee01e96c48. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Record369Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Record369_func_80018368(int*, int*) __asm__("func_80018368");
/* extern */
int Record369_func_80019194(void*, int) __asm__("func_80019194");
/* extern */
int Record369_func_8001BA30(int*, int, int, int, int, void*) __asm__("func_8001BA30");
/* extern */
int Record369_func_8001C288(int*, int, int) __asm__("func_8001C288");
/* extern */
int Record369CountTimerDown(void*, int) __asm__("func_800359A4");
/* extern */
unsigned char Record369ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
/* extern */
int Record369RandBetween(int, int) __asm__("func_8003636C");
/* extern */
int Record369RandSignedBetween(int, int) __asm__("func_800363DC");
/* extern */
unsigned char Record369PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
/* extern */
int Record369PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
/* extern */
int Record369_func_8004EF74(void*, int*, void*) __asm__("func_8004EF74");
/* extern */
unsigned char Record369CopyVector(int*, int*) __asm__("func_8004F178");
/* extern */
unsigned char Record369AddVector(int*, int*, void*) __asm__("func_8004F194");
/* extern */
unsigned char Record369DeleteMoby(void*) __asm__("func_80055B18");
/* extern */
unsigned char Record369_func_8005629C(void*) __asm__("func_8005629C");
/* extern */
extern unsigned char Record369_D_800658A0 __asm__("D_800658A0");
extern unsigned char Record369_D_80065920 __asm__("D_80065920");
extern int Record369_D_8006C574 __asm__("D_8006C574");
extern int Record369_D_8006C578 __asm__("D_8006C578");
extern unsigned char Record369_D_80070328 __asm__("D_80070328");
extern int Record369_D_80071918 __asm__("D_80071918");
extern int Record369_D_8007191C __asm__("D_8007191C");
extern int Record369_D_80071920 __asm__("D_80071920");
extern void* (*Record369_SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern unsigned char (*Record369_SpawnParticle)(int, int, int*, int) __asm__("SpawnParticle");

#define Record369Low(a, b)                  \
    ({                                      \
        register int low __asm__("lo");     \
        low = (int)(a) * (int)(b);          \
        __asm__("" : "=l"(low) : "0"(low)); \
        low;                                \
    })
/* Original 369 instructions. Scratch vectors occupy SP+0x18, +0x28
 * and +0x38. Raw product words, signed shifts and byte table addressing
 * retain the identified original producer/consumer instructions.
 * Empty constraints retain register producers and load-delay scheduling.
 * Physical units, helper contracts and caller cadence remain unresolved. */
void func_level_21_8007CB8C(void* input) {
    register void* owner21 __asm__("$21") = input;
    struct {
        Vector3D scratch18;
        int pad24;
        Vector3D scratch28;
        int pad34;
        Vector3D scratch38;
        int pad44;
    } frame;
    short* temp_a0;
    register int temp_s1 __asm__("$17");
    register int temp_s2 __asm__("$18");
    register int* temp_s0 __asm__("$16");
    register int* temp_s0_2 __asm__("$16");
    register int* temp_s3 __asm__("$19");
    int* var_a0;
    register int temp_s0_3 __asm__("$16");
    register int temp_s0_4 __asm__("$16");
    register int temp_s0_5 __asm__("$16");
    int temp_s1_2;
    int temp_v0_2;
    register int var_s7 __asm__("$23");
    register int var_s7_2 __asm__("$23");
    register int temp_v1 __asm__("$3");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    unsigned char* tableBase30;
    register unsigned char* tableBase9 __asm__("$9");
    register int product9 __asm__("$9");
    register int* sampleAddress4 __asm__("$4");
    register int* normalPointer5 __asm__("$5");
    register int product6 __asm__("$6");
    register int product4 __asm__("$4");
    register int* copyPointer4 __asm__("$4");
    register int callArgument4 __asm__("$4");
    register int callArgument5 __asm__("$5");
    register void* temp_s6 __asm__("$22");
    register void* temp_v0 __asm__("$20");

    word2 = 1;
    MATCHING_KEEP2_CLOBBER(owner21, word2, "memory");
    temp_v1 = Record369Field(owner21, unsigned char*, 0x48);
    temp_s6 = Record369Field(owner21, void**, 0);
    MATCHING_KEEP2(temp_s6, temp_v1);
    if (temp_v1 == word2)
        goto state1;
    if (temp_v1 >= 2)
        goto testState10;
    if (!temp_v1)
        goto state0;
    goto done;
testState10:
    word2 = 10;
    if (temp_v1 == word2)
        goto state10;
    goto done;
state0:
    if ((Record369Field(owner21, int*, 0xC) >= 0x400) &&
        (Record369Field(owner21, int*, 0x10) >= 0x400) &&
        (Record369Field(owner21, int*, 0x14) >= 0x400)) {
        copyPointer4 = &frame.scratch18.x;
        MATCHING_KEEP_CLOBBER(copyPointer4, "$16");
        temp_s0 = owner21 + 12;
        Record369CopyVector(copyPointer4, temp_s0);
        Record369AddVector(temp_s0, temp_s0, temp_s6);
        if (Record369_func_8001C288(temp_s0, 0x96, 7) != 0) {
            Record369Field(&Record369_D_80070328, int*, 0x20C) = 0x10000400;
            Record369Field(&Record369_D_80070328, int*, 0x21C) =
                (int)((int)(Record369Field(&Record369_D_80065920 +
                                               (Record369Field(owner21, unsigned char*, 0x46) * 2),
                                           short*, 0) *
                            0x19) >>
                      0xA);
            Record369Field(&Record369_D_80070328, int*, 0x220) =
                (int)((int)(Record369Field(&Record369_D_800658A0 +
                                               (Record369Field(owner21, unsigned char*, 0x46) * 2),
                                           short*, 0) *
                            0x19) >>
                      0xA);
            Record369Field(&Record369_D_80070328, int*, 0x224) = 0x14;
            Record369Field(owner21, unsigned char*, 0x48) = 1U;
        }
        if ((Record369CountTimerDown(temp_s6 + 0xE, 2) != 0) &&
            (Record369_func_8001BA30(temp_s0, 0x96, 0, 0, 0x10000000, owner21) != 0)) {
            Record369Field(owner21, unsigned char*, 0x48) = 1U;
        }
        if (Record369CountTimerDown(temp_s6 + 0xC, 2) == 0) {
            copyPointer4 = &frame.scratch18.x;
            MATCHING_KEEP_CLOBBER(copyPointer4, "$16");
            temp_s0_2 = owner21 + 12;
            if (Record369_func_80018368(copyPointer4, temp_s0_2) != 0) {
                Record369Field(owner21, unsigned char*, 0x48) = 1U;
            }
            Record369_SpawnParticle(1, 5, temp_s0_2, 0);
            Record369ProbeGroundFromRaisedMoby(owner21);
            Record369_func_8005629C(owner21);
            return;
        }
        goto block_36;
    }
    goto block_36;
state1:
    var_s7 = 0;
    do {
        Record369CopyVector(&frame.scratch28.x, owner21 + 0xC);
        word2 = Record369RandSignedBetween(0, 300);
        callArgument4 = 0;
        callArgument5 = 300;
        MATCHING_KEEP2_CLOBBER(callArgument4, callArgument5, "memory");
        word3 = frame.scratch28.x;
        MATCHING_KEEP_CLOBBER(var_s7, "memory");
        var_s7 += 1;
        word3 += word2;
        frame.scratch28.x = word3;
        frame.scratch28.y += Record369RandSignedBetween(callArgument4, callArgument5);
        frame.scratch28.z += Record369RandSignedBetween(0, 0x12C);
        Record369_SpawnParticle(1, 0xF, &frame.scratch28.x, 0);
    } while (var_s7 < 0x18);
    var_s7_2 = 0;
    tableBase30 = &Record369_D_800658A0;
    MATCHING_KEEP(tableBase30);
loop_21:
    if ((Record369_D_8006C578 - Record369_D_8006C574) >= 0x15) {
        temp_v0 = Record369_SpawnMoby(Record369Field(owner21, short*, 0x36), owner21);
        MATCHING_KEEP(temp_v0);
        if (temp_v0 != 0) {
            temp_s3 = Record369Field(temp_v0, int**, 0);
            MATCHING_KEEP(temp_s3);
            word2 = Record369PlanarHeadingLookup(Record369Field(temp_s6, int*, 0),
                                                 Record369Field(temp_s6, int*, 4), 0);
            callArgument4 = -38;
            callArgument5 = 38;
            MATCHING_KEEP2_CLOBBER(callArgument4, callArgument5, "$16");
            temp_s0_3 = word2;
            word2 = Record369RandSignedBetween(callArgument4, callArgument5);
            temp_s0_4 = temp_s0_3 - 128;
            temp_s0_4 += word2;
            word2 = Record369RandBetween(-40, 40);
            callArgument4 = 80;
            callArgument5 = 140;
            MATCHING_KEEP2_CLOBBER(callArgument4, callArgument5, "$17");
            temp_s1 = word2;
            temp_s2 = Record369RandBetween(callArgument4, callArgument5);
            Record369Field(temp_v0, int*, 8) = 0;
            Record369Field(temp_v0, int*, 0x1C) = -1;
            Record369CopyVector(temp_v0 + 0xC, owner21 + 0xC);
            temp_s0_5 = temp_s0_4 & 255;
            temp_s0_5 *= 2;
            tableBase9 = &Record369_D_80065920;
            MATCHING_KEEP(tableBase9);
            word2 = Record369Field((void*)(temp_s0_5 + (int)tableBase9), short*, 0);
            MATCHING_KEEP2(temp_s1, word2);
            {
                register int pendingProduct __asm__("lo");
                pendingProduct = word2 * temp_s2;
                __asm__(""
                        : "=l"(pendingProduct), "=r"(temp_s1)
                        : "0"(pendingProduct), "1"(temp_s1));
                temp_s1 &= 255;
                temp_s1 *= 2;
                sampleAddress4 = (int*)(temp_s1 + (int)tableBase9);
                product9 = pendingProduct;
                MATCHING_KEEP_CLOBBER(product9, "memory");
            }
            word3 = Record369Field(sampleAddress4, short*, 0);
            word2 = product9 >> 12;
            product9 = Record369Low(word2, word3);
            MATCHING_KEEP_CLOBBER(product9, "memory");
            temp_s0_5 += (int)tableBase30;
            word2 = product9 >> 12;
            frame.scratch38.x = word2;
            word2 = Record369Field((void*)temp_s0_5, short*, 0);
            product9 = Record369Low(word2, temp_s2);
            MATCHING_KEEP_CLOBBER(product9, "memory");
            word3 = Record369Field(sampleAddress4, short*, 0);
            word2 = product9 >> 12;
            product9 = Record369Low(word2, word3);
            MATCHING_KEEP_CLOBBER(product9, "memory");
            temp_s1 += (int)tableBase30;
            word2 = product9 >> 12;
            frame.scratch38.y = word2;
            word2 = Record369Field((void*)temp_s1, short*, 0);
            product9 = Record369Low(word2, temp_s2);
            MATCHING_KEEP_CLOBBER(product9, "memory");
            word2 = product9 >> 12;
            frame.scratch38.z = word2;
            Record369CopyVector(temp_s3, &frame.scratch38.x);
            Record369Field(temp_s3, short*, 0xC) = Record369RandBetween(0x1E, 0x46);
            Record369Field(temp_v0, signed char*, 0x48) = 0xA;
            Record369Field(temp_v0, signed char*, 0x4F) = Record369RandBetween(0x46, 0x5A);
            Record369Field(temp_v0, signed char*, 0x4C) = 0x50;
            Record369Field(temp_v0, signed char*, 0x4E) = 0x50;
        }
        var_s7_2 += 1;
        if (var_s7_2 < 8) {
            goto loop_21;
        }
    }
    Record369PlayMobySoundEvent(owner21, 0, 0);
    goto block_36;
state10:
    if ((Record369Field(owner21, int*, 0xC) >= 0x400) &&
        (Record369Field(owner21, int*, 0x10) >= 0x400) &&
        (Record369Field(owner21, int*, 0x14) >= 0x400)) {
        word2 = Record369_func_80019194(owner21 + 12, 80);
        MATCHING_KEEP_CLOBBER(owner21, "$4");
        var_a0 = owner21 + 12;
        if (!word2)
            goto applyMotion;
        normalPointer5 = &Record369_D_80071918;
        word3 = Record369Field(temp_s6, int*, 0);
        word2 = *normalPointer5;
        product6 = Record369Low(word3, word2);
        MATCHING_KEEP(product6);
        word3 = Record369Field(temp_s6, int*, 4);
        word2 = Record369_D_8007191C;
        product4 = Record369Low(word3, word2);
        MATCHING_KEEP(product4);
        word3 = Record369Field(temp_s6, int*, 8);
        word2 = Record369_D_80071920;
        {
            register int lastLow __asm__("lo");
            lastLow = word3 * word2;
            __asm__("" : "=l"(lastLow) : "0"(lastLow));
            word2 = product6 + product4;
            __asm__("" : "=l"(lastLow) : "0"(lastLow), "r"(word2));
            word3 = lastLow;
            __asm__("" : "=r"(word3) : "0"(word3), "r"(word2));
            word2 += word3;
        }
        MATCHING_KEEP_CLOBBER(owner21, "$4");
        var_a0 = owner21 + 12;
        if (word2 >= 0)
            goto applyMotion;
        word2 = Record369_func_8004EF74(temp_s6, normalPointer5, temp_s6);
        MATCHING_KEEP_CLOBBER(owner21, "$4");
        var_a0 = owner21 + 12;
        if (!word2)
            goto applyMotion;
        Record369Field(temp_s6, int*, 0) = Record369Field(temp_s6, int*, 0) * 6 >> 3;
        Record369Field(temp_s6, int*, 4) = Record369Field(temp_s6, int*, 4) * 6 >> 3;
        Record369Field(temp_s6, int*, 8) = Record369Field(temp_s6, int*, 8) * 6 >> 3;
    applyMotion:
        Record369AddVector(var_a0, var_a0, temp_s6);
        temp_v0_2 = Record369Field(temp_s6, int*, 8) - 8;
        Record369Field(temp_s6, int*, 8) = temp_v0_2;
        if (temp_v0_2 < -0x80) {
            Record369Field(temp_s6, int*, 8) = -0x80;
        }
        if (Record369CountTimerDown(temp_s6 + 0xC, 2) != 0) {
            goto block_36;
        }
    } else {
        goto block_36;
    }
    goto done;
block_36:
    Record369DeleteMoby(owner21);
done:
    return;
}
#undef Record369Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level21
 * 8007D150: original362 instructions in sibling4450; verified37 spawn,
 * angle and model-selector C reused with original21 differences.
 * Raw widths, helper arguments and branch routes only. Meanings, units,
 * cadence unresolved; acceptance requires native, linked and all hashes. */
#define Actor21Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Actor21Player[] __asm__("D_80070328");
extern unsigned char* Actor21Models[] __asm__("D_8006EE2C");
extern unsigned char* Actor21Active __asm__("D_8006E164");
extern int Actor21Type __asm__("D_8006E160");
extern int Actor21Gate __asm__("D_8006C770");
extern int Actor21X __asm__("D_8006E020"), Actor21Y __asm__("D_8006E024");
extern unsigned short Actor21Heading __asm__("D_8006E040");
extern int Actor21Result __asm__("D_80071924");
extern unsigned char* (*Actor21Spawn)(int, void*)__asm__("SpawnMoby");
int Actor21H399E8() __asm__("func_800399E8");
int Actor21ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor21PlanarHeadingLookup() __asm__("func_8004E880");
int Actor21H360F8() __asm__("func_800360F8");
int Actor21H38BF8() __asm__("func_80038BF8");
int Actor21H36A68() __asm__("func_80036A68");
int Actor21TurnMobyTowardPlayer() __asm__("func_8003573C");
int Actor21AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Actor21H13ACC() __asm__("func_80013ACC");
int Actor21RequestMobyAnimation() __asm__("func_80034F40");
int Actor21H55E84() __asm__("func_80055E84");
int Actor21H35DDC() __asm__("func_80035DDC");
int Actor21CopyVector() __asm__("func_8004F178");
int Actor21H1A310() __asm__("func_8001A310");
int Actor21H40954() __asm__("func_80040954");
int Actor21H35194() __asm__("func_80035194");
int Actor21RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor21H3BA00() __asm__("func_8003BA00");
int Actor21H369B8() __asm__("func_800369B8");
int Actor21DeleteMoby() __asm__("func_80055B18");
int Actor21H39B6C() __asm__("func_80039B6C");
void func_level_21_8007D150(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$18");
    register unsigned char* saved __asm__("$16");
    register unsigned char* position __asm__("$19");
    register int valid __asm__("$20");
    register unsigned char* call4 __asm__("$4");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register unsigned char* call5 __asm__("$5");
    register int arg6 __asm__("$6");
    register int arg7 __asm__("$7");
    register unsigned char** activeAddress __asm__("$3");
    int vector[4];
    work2 = Actor21Field(owner, unsigned char*, 0x48);
    tag = Actor21Field(owner, unsigned char**, 0);
    if (work2 == 125)
        return;
    work2 = Actor21Field(tag, int*, 0x28);
    if (!work2)
        Actor21H399E8(owner, tag + 0x28);
    call5 = Actor21Player + 0x50;
    work3 = Actor21Field(call5, int*, 0);
    work2 = 11;
    if (work3 == work2) {
        work2 = Actor21ApproximatePlanarDistance(owner + 12, call5 - 0x50) < 0x7000;
        MATCHING_KEEP(work2);
        if (work2) {
            work2 = 255;
            Actor21Field(owner, unsigned char*, 0x52) = work2;
        }
    } else {
        work3 = owner[0x52];
        work2 = 255;
        if (work3 == work2) {
            work2 = 254;
            owner[0x52] = work2;
        }
    }
    work2 = Actor21Field(owner, int*, 0x18);
    MATCHING_KEEP(work2);
    if (work2) {
        work2 = 2;
        MATCHING_KEEP(work2);
        work3 = owner[0x48];
        if (work3 == work2)
            goto dispatchCompare;
        call4 = Actor21Spawn(334, owner);
        MATCHING_KEEP(call4);
        if (call4) {
            int angle;
            saved = Actor21Field(call4, unsigned char**, 0);
            if (Actor21Field(owner, int*, 0x18) & 0x20000)
                Actor21Field(call4, unsigned char*, 0x48) = 1;
            else
                Actor21Field(call4, unsigned char*, 0x48) = 10;
            Actor21Field(call4, unsigned char*, 0x49) = 8;
            Actor21Field(saved, short*, 4) = 120;
            Actor21Field(saved, short*, 2) = 200;
            angle = Actor21Field(owner, unsigned char*, 0x51);
            if (!angle)
                angle = Actor21H360F8(
                    Actor21PlanarHeadingLookup(
                        Actor21Field(owner, int*, 12) - Actor21Field(Actor21Player, int*, 0),
                        Actor21Field(owner, int*, 16) - Actor21Field(Actor21Player, int*, 4), 0),
                    Actor21Player[14], 32, 0);
            saved[1] = angle;
            Actor21Field(saved, int*, 16) = -1;
        }
        activeAddress = &Actor21Active;
        if (*activeAddress == owner) {
            Actor21Type = 0;
            *activeAddress = 0;
        }
        Actor21H38BF8(owner, tag, 7, 2);
        call4 = owner;
        call5 = 0;
        arg6 = 0;
        MATCHING_KEEP3(call4, call5, arg6);
        saved = (void*)1;
        tag[22] = 70;
        tag[21] = (int)saved;
        tag[14] = 8;
        Actor21Field(tag, short*, 10) = 0;
        Actor21Field(tag, short*, 6) += 30;
        Actor21Field(owner, int*, 8) = 0;
        Actor21Field(owner, int*, 20) += 400;
        Actor21H36A68(call4, call5, arg6, 0);
        work3 = 2;
        Actor21Field(owner, unsigned char*, 0x48) = work3;
        {
            register unsigned int count __asm__("$2") =
                **(unsigned char**)(Actor21Models[Actor21Field(owner, short*, 0x36)] + 0x44);
            register int multiple __asm__("$2");
            owner[0x3C] = work3;
            owner[0x3D] = work3;
            owner[0x3E] = 0;
            owner[0x3F] = (int)saved;
            multiple = count >= 2;
            MATCHING_KEEP(multiple);
            work2 = -multiple;
            work2 &= 48;
            MATCHING_KEEP(work2);
            owner[0x40] = work2;
        }
    }
dispatch:
    work3 = owner[0x48];
    work2 = 2;
dispatchCompare:
    MATCHING_KEEP2(work2, work3);
    if (work3 == work2)
        goto state2;
    work2 = work3 < 3;
    MATCHING_KEEP(work2);
    if (!work2)
        goto highState;
    if (!work3)
        goto state0;
    goto finish;
highState:
    work2 = work3 < 5;
    MATCHING_KEEP(work2);
    call4 = owner;
    if (!work2)
        goto prepared;
    MATCHING_KEEP(call4);
    valid = 1;
    goto state34;
state0:
    MATCHING_KEEP(work3);
    Actor21TurnMobyTowardPlayer(owner, 4, 0, 0);
    if (Actor21ApproximatePlanarDistance(owner + 12, Actor21Player) >= Actor21Field(tag, int*, 24))
        goto finish;
    call4 = owner;
    MATCHING_KEEP(call4);
    work3 = Actor21Field(owner, short*, 0x38);
    work2 = Actor21Field(owner, int*, 20);
    call4 = (void*)Actor21Field(Actor21Player, int*, 8);
    work3 = work2 - work3;
    work2 = work3 - (int)call4;
    if (work2 < 0)
        goto negativeHeight;
    if (work2 < 1000)
        goto heightAccepted;
    goto finish;
negativeHeight:
    work2 = (int)call4 - work3;
    if (work2 >= 1000)
        goto finish;
heightAccepted:
    call4 = owner;
    MATCHING_KEEP2(call4, work2);
    work2 = Actor21Field(owner, short*, 0x38);
    work3 = Actor21Field(owner, int*, 20);
    call4 = (void*)Actor21Field(Actor21Player, int*, 8);
    work3 = work3 - work2;
    work3 = work3 - (int)call4;
    if (work3 >= 200)
        goto finish;
    work3 = Actor21Field(Actor21Player, int*, 0x50);
    work2 = 16;
    if (work3 != work2)
        goto finish;
    work2 = Actor21AbsoluteByteAngleDelta(
                (short)Actor21Heading >> 4,
                Actor21PlanarHeadingLookup(Actor21Field(owner, int*, 12) - Actor21X,
                                           Actor21Field(owner, int*, 16) - Actor21Y, 0)) < 28;
    MATCHING_KEEP(work2);
    if (!work2)
        goto finish;
    {
        if (!Actor21Type)
            Actor21H13ACC(owner, 12);
        Actor21Field(tag, int*, 32) = 50;
        owner[0x48] = 4;
        Actor21RequestMobyAnimation(owner, 4);
        goto finish;
    }
    goto finish;
state34:
    MATCHING_OBSERVE_VOLATILE(call4);
    call4 = owner;
    saved = (void*)Actor21H55E84(call4);
    if (owner[0x48] == 4) {
        if (Actor21Gate) {
            owner[0x48] = 3;
            Actor21RequestMobyAnimation(owner, 3);
        }
        work2 = (int)saved < 18;
        MATCHING_KEEP(work2);
        if (work2)
            goto finish;
    }
    Actor21TurnMobyTowardPlayer(owner, 7, 0, 0);
    Actor21Field(tag, int*, 32) += 20;
    if (Actor21Field(tag, int*, 32) >= 121)
        Actor21Field(tag, int*, 32) = 120;
    if (Actor21H35DDC(owner, Actor21Field(tag, int*, 32), 300, 0, 5)) {
        Actor21Field(owner, int*, 24) |= 0x20000;
        owner[0x51] = owner[0x46] + 128;
    }
    position = owner + 12;
    Actor21CopyVector(vector, position);
    call4 = (unsigned char*)vector;
    call5 = (void*)2000;
    arg6 = 0;
    arg7 = (int)owner;
    MATCHING_KEEP4(call4, call5, arg6, arg7);
    saved = (unsigned char*)&Actor21Result;
    work2 = vector[2];
    work3 = 255;
    Actor21Field(saved, int*, 0) = work3;
    vector[2] = work2 + 300;
    Actor21H1A310(call4, call5, arg6, arg7);
    if (Actor21H40954(Actor21Field(saved, int*, 0)) != 4)
        valid = 0;
    work2 = 0x20000;
    if (valid) {
        MATCHING_OBSERVE_VOLATILE(work2);
        if (Actor21ApproximatePlanarDistance(position, Actor21Player) >= 700) {
            work2 = 0x20000;
            goto draw;
        }
    }
    work2 = 0x20000;
    Actor21Field(owner, int*, 24) |= work2;
    owner[0x51] = owner[0x46] + 128;
    work2 = 0x20000;
    goto draw;
state2:
    work2 = tag[22] < 61;
    if (work2)
        goto lowTimer;
    Actor21Field(tag, short*, 10) = 0;
    goto timerReady;
lowTimer:
    Actor21Field(tag, short*, 10) = 300;
timerReady:
    if (Actor21H35194(owner, tag) == 256) {
        Actor21RefreshMobySpatialGridAndBasis(owner, 4);
        Actor21H3BA00(owner);
        Actor21H369B8(owner, 32);
        Actor21DeleteMoby(owner);
        goto cleanup;
    }
    goto finish;
draw:
    MATCHING_OBSERVE_VOLATILE(work2);
finish:
    call4 = owner;
prepared:
    Actor21RefreshMobySpatialGridAndBasis(call4, 4);
cleanup:
    if (Actor21Field(tag, int*, 0x28))
        Actor21H39B6C(owner, tag + 0x28);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007D6F8.
* Assembly SHA256 33703a0f8d8d8bfad53aa8fcadf34fdcfc01c7c2cf43badc2712c259e88bb301.
* AI generated; not human reviewed. All620 original instructions and
* both original selector tables (32+8 words) are required, including
* every actual branch/call/internal/table target. Frame0x48 retains
* SP0x20..0x2F local extent and S0/S1/S2/S3/S4/RA saves/restores.
* Shared increment,reset,delete and final-store blocks retain their
* original physical joins. The first helper preserves incoming A0 and
* supplies original A1=2. GlobalC640 reads remain independent. Helper
* 8003636C returns its full original32-bit result; halfword stores retain
* low16 bits while original word stores/shifts retain full results.
* Original byte0xFE store,unsigned halfword increment,32-bit table and
* private field loads,late V0-to-S0 copy,and stack word+0x200 remain exact.
* Initialized empty dependencies and dead-before-producer clobbers emit
* no CPU instructions. No partial HI,FP shortcut or opcode assembly.
* Raw units/fixed point,complete helper contracts,caller cadence and
* synchronized retail runtime remain open. Cadence is per invocation;
* confidence is binary identity only after every acceptance gate.
* Falsification: every native/linked word,actual transfer/table target,
* selector/padding byte,full EXE and every overlay hash must match. */
#define Actor21Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Actor21Call34F40View1() __asm__("func_80034F40");
unsigned char Actor21EmptyAnimationTransitionHookView1() __asm__("func_80035734");
int Actor21TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor21CountTimerDownView1() __asm__("func_800359A4");
int Actor21Call35A80View1() __asm__("func_80035A80");
unsigned char Actor21Call35EE0View1() __asm__("func_80035EE0");
int Actor21RandBetweenView1() __asm__("func_8003636C");
int Actor21Call365E4View1() __asm__("func_800365E4");
unsigned char Actor21Call37014View1() __asm__("func_80037014");
int Actor21Call37A60View1() __asm__("func_80037A60");
int Actor21Call37BBCView1() __asm__("func_80037BBC");
unsigned char Actor21Call3B7B4View1() __asm__("func_8003B7B4");
unsigned char Actor21Call492DCView1() __asm__("func_800492DC");
int Actor21PlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor21CopyVectorView1() __asm__("func_8004F178");
int Actor21AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor21ApproximatePlanarDistanceView1() __asm__("func_8004F334");
unsigned char Actor21Call512E4View1() __asm__("func_800512E4");
unsigned char Actor21DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor21RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Actor21Data6C550View1 __asm__("D_8006C550");
extern int Actor21Data6C58CView1 __asm__("D_8006C58C");
extern volatile int Actor21Data6C640View1 __asm__("D_8006C640");
extern int Actor21Data6C770View1 __asm__("D_8006C770");
extern unsigned char Actor21Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Actor21Data6C7F8View1 __asm__("D_8006C7F8");
extern unsigned char Actor21Data6D088View1 __asm__("D_8006D088");
extern int Actor21Data6E344View1 __asm__("D_8006E344");
extern unsigned char Actor21Data70300View1 __asm__("D_80070300");
extern unsigned char Actor21Data70328View1 __asm__("D_80070328");
void func_level_21_8007D6F8(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int addressOrResult16 __asm__("$16"), privateRecord18 __asm__("$18"),
        addressWord19 __asm__("$19"), retainedSignedHalfword20 __asm__("$20");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    struct {
        int sp20, sp24, sp28, sp2C;
    } originalFrame;
    short temporaryWord3;
    short temporaryWord4;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord22;
    int temporaryWord23;
    register int temporaryWord11 __asm__("$3");
    unsigned char temporaryWord15;
    unsigned char temporaryWord20;
    unsigned char temporaryWord21;
    void* firstPackedSource5;
    void* secondPackedSource5;
    void* temporaryPointer5;
    void* temporaryPointer6;
    void* temporaryPointer7;
    void* temporaryPointer8;
    void* temporaryPointer9;
    void* temporaryPointer10;
    void* temporaryPointer14;
    void* temporaryPointer16;
    void* temporaryPointer17;
    void* temporaryPointer18;
    void* temporaryPointer19;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    privateRecord18 = (int)Actor21Field(ownerRecord17, void**, 0);
    if ((Actor21Field(ownerRecord17, int*, 0x18) != 0) &&
        (Actor21Field(ownerRecord17, unsigned char*, 0x48) == 0)) {
        Actor21Field(ownerRecord17, unsigned char*, 0x48) = 2U;
        Actor21Call34F40View1(input, 2);
    }
    temporaryWord11 = Actor21Field(ownerRecord17, unsigned char*, 0x48);
    Actor21Field(ownerRecord17, int*, 0x18) = 0;
    switch (temporaryWord11) {
        case 0:
            if ((Actor21Data6C640View1 != 0) ||
                (!(Actor21Data6C7B4View1 & 1) &&
                 !(*(&Actor21Data70300View1 + Actor21Data6C58CView1) & 1))) {
                if (Actor21Field(privateRecord18, unsigned char*, 0) == 0) {
                    if (Actor21Field(privateRecord18, int*, 0x30) == 0) {
                        Actor21Field(privateRecord18, int*, 0x30) = 1;
                        Actor21Call37014View1(ownerRecord17);
                        addressOrResult16 = privateRecord18 + 0x30;
                        Actor21Call3B7B4View1(addressOrResult16, 4, &Actor21Data6D088View1);
                        Actor21Call3B7B4View1(addressOrResult16, 4, &Actor21Data6C7F8View1);
                        Actor21Field(ownerRecord17, unsigned char*, 0x48) = 0xAU;
                    } else if (Actor21Data6C640View1 == 0) {
                        temporaryPointer5 = Actor21Field(privateRecord18, void**, 0x2C);
                        rawWord2 = (int)temporaryPointer5;
                        argumentWord5 = Actor21Field(rawWord2, short*, 0);
                        rawWord2 = Actor21Field(rawWord2, int*, 0xC);
                        argumentWord5 <<= 4;
                        argumentWord5 -= 16;
                        Actor21CopyVectorView1(ownerRecord17 + 0xC, rawWord2 + argumentWord5);
                        Actor21Call37014View1(ownerRecord17);
                        Actor21Field(ownerRecord17, unsigned char*, 0x52) = 0xFE;
                        Actor21RefreshMobySpatialGridAndBasisView1(ownerRecord17, 2);
                        temporaryPointer14 = Actor21Field(privateRecord18, void**, 0x2C);
                        temporaryPointer6 = (Actor21Field(temporaryPointer14, short*, 0) * 0x10) +
                                            Actor21Field(temporaryPointer14, int*, 0xC);
                        Actor21Field(ownerRecord17, unsigned char*, 0x46) =
                            Actor21PlanarHeadingLookupView1(
                                Actor21Field(temporaryPointer6, int*, -0x20) -
                                    Actor21Field(ownerRecord17, int*, 0xC),
                                Actor21Field(temporaryPointer6, int*, -0x1C) -
                                    Actor21Field(ownerRecord17, int*, 0x10),
                                0);
                        if ((unsigned char)Actor21Field(privateRecord18, unsigned char*, 2) < 2U) {
                            Actor21Field(privateRecord18, unsigned char*, 2) = 2U;
                        }
                    }
                }
                if (Actor21Call37BBCView1(ownerRecord17, 0) != 0) {
                    if ((Actor21Field(privateRecord18, unsigned char*, 0) == 0) &&
                        (Actor21Field(privateRecord18, unsigned char*, 2) == 2) &&
                        ((unsigned char)Actor21Field(
                             ((Actor21Field(privateRecord18, int*, 0x44) * 0x58) +
                              Actor21Data6C550View1),
                             unsigned char*, 0x48) >= 0x80U)) {
                        Actor21Field(privateRecord18, unsigned char*, 2) = 3U;
                    }
                    if (Actor21Field(privateRecord18, unsigned char*, 0) == 1) {
                        Actor21Data6C7B4View1 |= 1;
                    }
                    Actor21Call512E4View1(ownerRecord17, 0, 1);
                    Actor21Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                    return;
                }
                return;
            }
            goto deleteOwner;
        case 10:
            temporaryWord15 = Actor21Field(ownerRecord17, unsigned char*, 0x49);
            switch (temporaryWord15) {
                case 0:
                    rawWord2 = Actor21Field(privateRecord18, int*, 0x28);
                    rawWord3 = rawWord2 * 0x58;
                    rawWord2 = Actor21Data6C550View1;
                    addressOrResult16 = rawWord2 + rawWord3;
                    addressWord19 = Actor21Field(addressOrResult16, void**, 0);
                    if ((Actor21CountTimerDownView1(privateRecord18 + 0x34, 2) != 0) &&
                        (Actor21Field(addressOrResult16, unsigned char*, 0x46) ==
                         Actor21Field(privateRecord18, int*, 0x38)) &&
                        (Actor21Field(addressOrResult16, unsigned char*, 0x40) ==
                         ((int)Actor21Field(privateRecord18, int*, 0x3C) >> 3))) {
                        Actor21Field(privateRecord18, short*, 0x34) =
                            Actor21RandBetweenView1(0x5A, 0xB4);
                        Actor21Field(privateRecord18, unsigned short*, 0x36) =
                            (unsigned short)(Actor21Field(privateRecord18, unsigned short*, 0x36) -
                                             1);
                        Actor21Field(privateRecord18, int*, 0x38) =
                            Actor21RandBetweenView1(0xBC, 0xF0);
                        Actor21Field(privateRecord18, int*, 0x3C) =
                            (int)(Actor21RandBetweenView1(0, 0xD) * 8);
                        if (Actor21AbsoluteByteAngleDeltaView1(
                                Actor21Field(privateRecord18, int*, 0x38), 0xD4) < 0xA) {
                            if (Actor21Field(privateRecord18, int*, 0x3C) < 0x68) {
                                Actor21Field(privateRecord18, int*, 0x3C) = 0x68;
                            }
                        }
                        Actor21Field(addressWord19, int*, 0x28) = 1;
                    }
                    if (Actor21Field(privateRecord18, short*, 0x34) < 0x3C) {
                        Actor21Field(addressWord19, int*, 0x20) =
                            (int)Actor21Field(privateRecord18, int*, 0x38);
                        Actor21Field(addressWord19, int*, 0x24) =
                            (int)Actor21Field(privateRecord18, int*, 0x3C);
                    }
                    Actor21TurnMobyTowardHeadingView1(
                        ownerRecord17, Actor21Field(addressOrResult16, unsigned char*, 0x46), 5, 0,
                        0, 0);
                    if ((short)Actor21Field(privateRecord18, unsigned short*, 0x36) > 0) {
                        temporaryWord22 = Actor21ApproximatePlanarDistanceView1(
                                              ownerRecord17 + 0xC, &Actor21Data70328View1) < 0x1194;
                        goto testIncrementPredicate;
                    } else {
                        goto incrementSubstate;
                    }
                    break;
                case 1:
                    temporaryPointer16 = Actor21Field(privateRecord18, void**, 0x2C);
                    temporaryPointer7 = (Actor21Field(temporaryPointer16, short*, 2) * 0x10) +
                                        Actor21Field(temporaryPointer16, int*, 0xC);
                    temporaryWord22 = Actor21TurnMobyTowardHeadingView1(
                        ownerRecord17,
                        Actor21PlanarHeadingLookupView1(Actor21Field(temporaryPointer7, int*, 0) -
                                                            Actor21Field(ownerRecord17, int*, 0xC),
                                                        Actor21Field(temporaryPointer7, int*, 4) -
                                                            Actor21Field(ownerRecord17, int*, 0x10),
                                                        0),
                        9, 0x1E, 1, 0);
                    goto testIncrementPredicate;
                case 2:
                    Actor21Field(privateRecord18, int*, 0x40) = 0x64;
                    goto incrementSubstate;
                case 3:
                    temporaryPointer17 = Actor21Field(privateRecord18, void**, 0x2C);
                    temporaryPointer8 = (Actor21Field(temporaryPointer17, short*, 2) * 0x10) +
                                        Actor21Field(temporaryPointer17, int*, 0xC);
                    Actor21TurnMobyTowardHeadingView1(
                        ownerRecord17,
                        Actor21PlanarHeadingLookupView1(Actor21Field(temporaryPointer8, int*, 0) -
                                                            Actor21Field(ownerRecord17, int*, 0xC),
                                                        Actor21Field(temporaryPointer8, int*, 4) -
                                                            Actor21Field(ownerRecord17, int*, 0x10),
                                                        0),
                        9, 0x1E, 1, 0);
                    temporaryPointer18 = Actor21Field(privateRecord18, void**, 0x2C);
                    temporaryPointer9 = (Actor21Field(temporaryPointer18, short*, 2) * 0x10) +
                                        Actor21Field(temporaryPointer18, int*, 0xC);
                    Actor21Call35EE0View1(
                        ownerRecord17,
                        Actor21PlanarHeadingLookupView1(Actor21Field(temporaryPointer9, int*, 0) -
                                                            Actor21Field(ownerRecord17, int*, 0xC),
                                                        Actor21Field(temporaryPointer9, int*, 4) -
                                                            Actor21Field(ownerRecord17, int*, 0x10),
                                                        0),
                        0x5A, 0, 0, 1);
                    if (Actor21Call37A60View1(ownerRecord17, privateRecord18 + 0x40, 4, 0x10,
                                              -0xC8) != 0) {
                        rawWord2 = Actor21Field(privateRecord18, int*, 0x2C);
                        rawWord3 = Actor21Field(rawWord2, unsigned short*, 2);
                        rawWord3++;
                        Actor21Field(rawWord2, short*, 2) = rawWord3;
                        goto incrementSubstate;
                    }
                    break;
                case 4:
                    if (((unsigned char)Actor21Field(
                             ((Actor21Field(privateRecord18, int*, 0x44) * 0x58) +
                              Actor21Data6C550View1),
                             unsigned char*, 0x48) >= 0x80U) ||
                        (Actor21Field(((Actor21Field(privateRecord18, int*, 0x28) * 0x58) +
                                       Actor21Data6C550View1),
                                      unsigned char*, 0x49) == 1)) {
                        Actor21Field(privateRecord18, unsigned char*, 2) = 3U;
                        Actor21Field(ownerRecord17, unsigned char*, 0x49) = 6U;
                        return;
                    }
                    if (Actor21Field(ownerRecord17, unsigned char*, 0x3D) != 0) {
                        Actor21Data6C770View1 = 0;
                        Actor21Field(ownerRecord17, signed char*, 0x40) = 0x72;
                        Actor21Field(ownerRecord17, unsigned char*, 0x3D) = 0U;
                        Actor21Field(ownerRecord17, signed char*, 0x3F) = 0;
                        Actor21EmptyAnimationTransitionHookView1(ownerRecord17);
                    }
                    if (Actor21Call37BBCView1(ownerRecord17, 0) != 0) {
                        Actor21Field(ownerRecord17, unsigned char*, 0x49) =
                            (unsigned char)(Actor21Field(ownerRecord17, unsigned char*, 0x49) + 1);
                        Actor21Call512E4View1(ownerRecord17, 0, 1);
                        return;
                    }
                    break;
                case 5:
                    if (Actor21Data6E344View1 != 1) {
                        if (Actor21Field(ownerRecord17, unsigned char*, 0x3D) != 0) {
                            Actor21Data6C770View1 = 0;
                            Actor21Field(ownerRecord17, signed char*, 0x40) = 0x72;
                            Actor21Field(ownerRecord17, unsigned char*, 0x3D) = 0U;
                            Actor21Field(ownerRecord17, signed char*, 0x3F) = 0;
                            Actor21EmptyAnimationTransitionHookView1(ownerRecord17);
                        }
                        goto incrementSubstate;
                    }
                    break;
                case 6:
                    addressOrResult16 = Actor21Call35A80View1(
                        ownerRecord17, Actor21Field(privateRecord18, void**, 0x2C), 0x100, 0x5A, 0,
                        6, 0x28, 5);
                    if (Actor21Field(ownerRecord17, unsigned char*, 0x3D) != 3) {
                        Actor21Data6C770View1 = 0;
                        Actor21Field(ownerRecord17, signed char*, 0x40) = 0x72;
                        Actor21Field(ownerRecord17, unsigned char*, 0x3D) = 3U;
                        Actor21Field(ownerRecord17, signed char*, 0x3F) = 0;
                        Actor21EmptyAnimationTransitionHookView1(ownerRecord17);
                    }
                    temporaryWord22 = addressOrResult16 & 2;
                testIncrementPredicate:
                    if (temporaryWord22 == 0)
                        return;
                incrementSubstate:
                    Actor21Field(ownerRecord17, unsigned char*, 0x49) =
                        (unsigned char)(Actor21Field(ownerRecord17, unsigned char*, 0x49) + 1);
                    return;
                case 7:
                    temporaryPointer19 = Actor21Field(privateRecord18, void**, 0x2C);
                    temporaryPointer10 = (Actor21Field(temporaryPointer19, short*, 0) * 0x10) +
                                         Actor21Field(temporaryPointer19, int*, 0xC);
                    temporaryWord23 = Actor21TurnMobyTowardHeadingView1(
                        ownerRecord17,
                        Actor21PlanarHeadingLookupView1(
                            Actor21Field(temporaryPointer10, int*, -0x20) -
                                Actor21Field(ownerRecord17, int*, 0xC),
                            Actor21Field(temporaryPointer10, int*, -0x1C) -
                                Actor21Field(ownerRecord17, int*, 0x10),
                            0),
                        9, 0, 0, 0);
                    goto testStateResetPredicate;
                    break;
                default:
                    return;
            }
            break;
        case 1:
            if (Actor21Data6E344View1 != 1) {
                temporaryWord20 = Actor21Field(privateRecord18, unsigned char*, 0);
                if ((temporaryWord20 == 1) &&
                    (Actor21Field(privateRecord18, unsigned char*, 4) == temporaryWord20)) {
                    Actor21Call34F40View1(ownerRecord17, 0);
                    Actor21Field(privateRecord18, int*, 0x40) = 0x3C;
                    Actor21Field(ownerRecord17, unsigned char*, 0x48) = 0x1EU;
                    return;
                }
                goto resetOwnerState;
            }
            break;
        case 2:
            temporaryWord23 = Actor21Data6C770View1;
        testStateResetPredicate:
            if (temporaryWord23 != 0) {
            resetOwnerState:
                Actor21Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Actor21Call34F40View1(ownerRecord17, 0);
                return;
            }
            break;
        case 30:
            if (Actor21CountTimerDownView1(privateRecord18 + 0x40, 4) != 0) {
                Actor21Call34F40View1(ownerRecord17, 3);
                Actor21Field(ownerRecord17, unsigned char*, 0x48) = 0x1FU;
            }
            goto updateFinalSharedWord;
        case 31:
            temporaryWord21 = Actor21Field(ownerRecord17, unsigned char*, 0x49);
            retainedSignedHalfword20 =
                Actor21Field(Actor21Field(privateRecord18, void**, 0x2C), short*, 2);
            switch (temporaryWord21) {
                case 0:
                    if (Actor21Call35A80View1(ownerRecord17,
                                              Actor21Field(privateRecord18, void**, 0x2C), 0x200,
                                              0x80, 0, 8, 0xC, 5) &
                        1) {
                        firstPackedSource5 = Actor21Field(privateRecord18, void**, 0x2C);
                        temporaryWord3 = Actor21Field(firstPackedSource5, short*, 2);
                        if (temporaryWord3 != 0) {
                            temporaryWord12 = Actor21Field(firstPackedSource5, int*, 0xC);
                            if (Actor21Field(((retainedSignedHalfword20 * 0x10) + temporaryWord12),
                                             int*, 0xC) &
                                1) {
                                Actor21Field(privateRecord18, int*, 0x40) = Actor21Call365E4View1(
                                    ownerRecord17 + 0xC, temporaryWord12 + (temporaryWord3 * 0x10),
                                    0x80, -0xC, 0);
                                Actor21Field(ownerRecord17, unsigned char*, 0x49) = 1U;
                            }
                            goto updateFinalSharedWord;
                        }
                        goto deleteOwner;
                    }
                    goto updateFinalSharedWord;
                case 1:
                    rawWord2 = Actor21Call35A80View1(ownerRecord17,
                                                     Actor21Field(privateRecord18, void**, 0x2C),
                                                     0x200, 0x80, 0, 8, 0xC, 0);
                    argumentWord4 = (int)&originalFrame.sp20;
                    MATCHING_KEEP(argumentWord4);
                    addressWord19 = (int)ownerRecord17 + 0xC;
                    MATCHING_KEEP(addressWord19);
                    argumentWord6 = Actor21Field(privateRecord18, int*, 0x40);
                    argumentWord5 = addressWord19;
                    argumentWord6 -= 12;
                    Actor21Field(privateRecord18, int*, 0x40) = argumentWord6;
                    rawWord3 = Actor21Field(ownerRecord17, int*, 0x14);
                    addressOrResult16 = rawWord2;
                    rawWord3 += argumentWord6;
                    Actor21Field(ownerRecord17, int*, 0x14) = rawWord3;
                    Actor21CopyVectorView1(argumentWord4, argumentWord5, argumentWord6);
                    rawWord2 = originalFrame.sp28;
                    rawWord2 += 0x200;
                    originalFrame.sp28 = rawWord2;
                    __asm__ __volatile__("" ::: "$2", "memory");
                    rawWord2 = addressOrResult16 & 1;
                    if (rawWord2) {
                        secondPackedSource5 = Actor21Field(privateRecord18, void**, 0x2C);
                        temporaryWord4 = Actor21Field(secondPackedSource5, short*, 2);
                        if (temporaryWord4 == 0) {
                        deleteOwner:
                            Actor21DeleteMobyView1(ownerRecord17);
                            return;
                        }
                        temporaryWord13 = Actor21Field(secondPackedSource5, int*, 0xC);
                        if (Actor21Field(((retainedSignedHalfword20 * 0x10) + temporaryWord13),
                                         int*, 0xC) &
                            1) {
                            Actor21Field(privateRecord18, int*, 0x40) = Actor21Call365E4View1(
                                addressWord19, temporaryWord13 + (temporaryWord4 * 0x10), 0x80,
                                -0xC, 0);
                        }
                        goto updateFinalSharedWord;
                    }
                    goto updateFinalSharedWord;
                default:
                    goto updateFinalSharedWord;
            }
        updateFinalSharedWord:
            Actor21Field(&Actor21Data70328View1, int*, 0x20C) = 0x10000002;
            Actor21Call492DCView1(ownerRecord17 + 0xC);
            break;
        default:
            return;
    }
}
#undef Actor21Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007E0A8.
* AI generated; not human reviewed. All1252 original instructions,30 switch
* selectors and every actual destination must match:1282 recorded words.
* Frame80hex=128 bytes saves S0..S4/RA;SP20..67 retains original local storage.
* The original timer2 result,selector-dependent140/200 values and22/27/23
* halfword deltas retain their original producers.140 is produced at its
* conditional entry;the earlier -200 comes from the shared movement target.
* Original479 enters525,skipping the later524 reload,with full V0=-200 from
* its delay slot. No target address or compiler/filter setting is patched.
* Original inner default467 enters shared status tail1234,not epilogue1243.
* Both nested dispatches and all increment/test/default entries remain exact.
* Original399E8 receives both owner and private+98. The post35A80 flag is
* reloaded after that call. SP30/31/32 have separate signed byte views and
* stores;other SP30/34 vector phases retain their complete original words.
* Original B4 uses LW at598 and LH in its separate original branch. Vector
* signed halfwords,39>>6 trig products,independent byte flags,index/descriptor
* reloads and complete callback/list pointers retain original widths/order.
* Known timer,angle,delta,spawn and399E8 views reuse existing matched source
* or header contracts. Raw fields have no invented gameplay interpretation.
* Empty metadata consumes complete initialized values or written fields,
* or clobbers dead values before fresh full producers;zero CPU instructions.
* No opcode asm,partial HI/LO,fixed FP,undefined incoming saved input or
* overlapping live fixed aliases. Compiler/filter/flags remain unchanged.
* Confidence is binary identity after all gates. Units/fixed point,complete
* helper/caller chains,cadence beyond invocation,Rev1 mapping and synchronized
* runtime remain open. Next:human review and retail captures. Every native/
* linked word,actual destination,owned selector and full EXE/every-overlay
* retail hash must remain identical.
*/
/* Original assembly SHA256 bb7ed5f9e59600a26c333fe454ea5a547689bcbcbdde68779846e366bdcf9b17 */
#define Level21_7E0A8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level21_7E0A8Call13D44View1() __asm__("func_80013D44");
int Level21_7E0A8RequestMobyAnimationView1() __asm__("func_80034F40");
int Level21_7E0A8Call35194View1() __asm__("func_80035194");
int Level21_7E0A8EmptyAnimationTransitionHookView1() __asm__("func_80035734");
int Level21_7E0A8TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level21_7E0A8TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level21_7E0A8CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level21_7E0A8Call35A80View1() __asm__("func_80035A80");
int Level21_7E0A8ProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Level21_7E0A8Call35DDCView1() __asm__("func_80035DDC");
int Level21_7E0A8SubAngle8View1() __asm__("func_8003613C");
int Level21_7E0A8SubAngle12View1() __asm__("func_8003615C");
int Level21_7E0A8RandBetweenView1() __asm__("func_8003636C");
int Level21_7E0A8RandSignedBetweenView1() __asm__("func_800363DC");
int Level21_7E0A8Call37014View1() __asm__("func_80037014");
int Level21_7E0A8Call37A60View1() __asm__("func_80037A60");
int Level21_7E0A8Call37BBCView1() __asm__("func_80037BBC");
int Level21_7E0A8Call38BF8View1() __asm__("func_80038BF8");
int Level21_7E0A8Call399E8View1(void*, void*) __asm__("func_800399E8");
int Level21_7E0A8Call39B6CView1() __asm__("func_80039B6C");
int Level21_7E0A8Call3B634View1() __asm__("func_8003B634");
int Level21_7E0A8Call3B74CView1() __asm__("func_8003B74C");
int Level21_7E0A8Call3B7B4View1() __asm__("func_8003B7B4");
int Level21_7E0A8PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level21_7E0A8Call3BB10View1() __asm__("func_8003BB10");
int Level21_7E0A8Call3BE70View1() __asm__("func_8003BE70");
int Level21_7E0A8Call3BFC0View1() __asm__("func_8003BFC0");
int Level21_7E0A8Call3C140View1() __asm__("func_8003C140");
int Level21_7E0A8PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level21_7E0A8MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level21_7E0A8ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level21_7E0A8ClearVectorView1() __asm__("func_8004F168");
int Level21_7E0A8CopyVectorView1() __asm__("func_8004F178");
int Level21_7E0A8AddVectorView1() __asm__("func_8004F194");
int Level21_7E0A8AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level21_7E0A8ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level21_7E0A8Call4F984View1() __asm__("func_8004F984");
int Level21_7E0A8Call512E4View1() __asm__("func_800512E4");
int Level21_7E0A8DeleteMobyView1() __asm__("func_80055B18");
int Level21_7E0A8RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level21_7E0A8DatarandView1(void) __asm__("rand");
extern int Level21_7E0A8Data652B0View1 __asm__("D_800652B0");
extern int Level21_7E0A8Data652B4View1 __asm__("D_800652B4");
extern int Level21_7E0A8Data652B6View1 __asm__("D_800652B6");
extern int Level21_7E0A8Data658A0View1 __asm__("D_800658A0");
extern int Level21_7E0A8Data65920View1 __asm__("D_80065920");
extern int Level21_7E0A8Data6C3F4View1 __asm__("D_8006C3F4");
extern int Level21_7E0A8Data6C550View1 __asm__("D_8006C550");
extern int Level21_7E0A8Data6C58CView1 __asm__("D_8006C58C");
extern int Level21_7E0A8Data6C640View1 __asm__("D_8006C640");
extern int Level21_7E0A8Data6C648View1 __asm__("D_8006C648");
extern int Level21_7E0A8Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level21_7E0A8Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level21_7E0A8Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level21_7E0A8Data6D088View1 __asm__("D_8006D088");
extern int Level21_7E0A8Data6E048View1 __asm__("D_8006E048");
extern int Level21_7E0A8Data6E160View1 __asm__("D_8006E160");
extern int Level21_7E0A8Data6E168View1 __asm__("D_8006E168");
extern int Level21_7E0A8Data6E344View1 __asm__("D_8006E344");
extern int Level21_7E0A8Data6E788View1 __asm__("D_8006E788");
extern int Level21_7E0A8Data70328View1 __asm__("D_80070328");
extern int Level21_7E0A8Data716ACView1 __asm__("D_800716AC");
extern void* (*Level21_7E0A8DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
void func_level_21_8007E0A8(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int privateRecord20 __asm__("$20"), retainedTimerHeadingVectorOrList16 __asm__("$16"),
        retainedOwnerPositionOrTarget17 __asm__("$17"),
        retainedScalarMatrixOrGlobal18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64;
    } originalFrame;
    int temporaryWord11;
    int temporaryWord20;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord16;
    int temporaryWord21;
    int temporaryWord23;
    int temporaryWord14;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord19;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord15;
    int temporaryWord22;
    argumentWord4 = (int)ownerParameter;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    privateRecord20 = Level21_7E0A8Field(ownerRecord19, void**, 0);
    if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) != 0x7D) {
        if (Level21_7E0A8Field(privateRecord20, void**, 0x98) == 0) {
            Level21_7E0A8Call399E8View1(argumentWord4, privateRecord20 + 0x98);
        }
        if ((Level21_7E0A8Data6C640View1 >= 2) &&
            (Level21_7E0A8Field(privateRecord20, int*, 0xBC) == 0)) {
            temporaryWord1 = Level21_7E0A8Data6C3F4View1 +
                             Level21_7E0A8Field((int)&Level21_7E0A8Data652B0View1, int*, 0x58);
            Level21_7E0A8Call4F984View1(
                temporaryWord1,
                temporaryWord1 +
                    Level21_7E0A8Field((int)&Level21_7E0A8Data652B4View1, unsigned short*, 0x58),
                Level21_7E0A8Field((int)&Level21_7E0A8Data652B6View1, unsigned short*, 0x58));
            Level21_7E0A8Field(privateRecord20, int*, 0xBC) = 1;
        }
        temporaryWord14 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48);
        switch (temporaryWord14) {
            case 0:
                if (Level21_7E0A8Call37BBCView1(ownerRecord19, 0) != 0) {
                    if (Level21_7E0A8Data6C640View1 < 0x3C) {
                        Level21_7E0A8Call512E4View1(ownerRecord19, 0, 1);
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 1U;
                        return;
                    }
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49) = 0U;
                    Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x20C) = 0x10000002;
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 0x14U;
                    return;
                }
                if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) != 0) {
                    Level21_7E0A8Data6C770View1 = 0;
                    Level21_7E0A8Field(ownerRecord19, signed char*, 0x40) = 0x72;
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) = 0U;
                    Level21_7E0A8Field(ownerRecord19, signed char*, 0x3F) = 0;
                    Level21_7E0A8EmptyAnimationTransitionHookView1(ownerRecord19);
                }
                goto sharedOriginalStatus1234;
            case 20:
                Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x20C) = 0x10000002;
                rawWord3 = Level21_7E0A8SubAngle12View1(
                    Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x64),
                    Level21_7E0A8PlanarHeadingLookupView1(
                        Level21_7E0A8Field(ownerRecord19, int*, 0xC) -
                            Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0),
                        Level21_7E0A8Field(ownerRecord19, int*, 0x10) -
                            Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 4),
                        0) *
                        0x10);
                MATCHING_KEEP(rawWord3);
                rawWord2 = rawWord3;
                if (rawWord3 < 0)
                    rawWord2 = -rawWord2;
                if (rawWord2 >= 49) {
                    rawWord2 = rawWord3 < 81;
                    if (!rawWord2) {
                        rawWord3 = 80;
                        MATCHING_KEEP(rawWord3);
                    }
                    rawWord2 = rawWord3 < -80;
                    if (rawWord2)
                        rawWord3 = -80;
                    rawWord2 = Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 100);
                    rawWord2 = (rawWord2 + rawWord3) & 4095;
                    Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 100) = rawWord2;
                }
                temporaryWord18 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49);
                rawWord3 = temporaryWord18;
                rawWord2 = 2;
                if (rawWord3 == rawWord2)
                    goto originalTargetState2;
                rawWord2 = rawWord3 < 3;
                if (!rawWord2) {
                    rawWord2 = 3;
                    if (rawWord3 == rawWord2)
                        goto originalTargetState3;
                    goto sharedOriginalStatus1234;
                }
                if (rawWord3 < 0)
                    goto sharedOriginalStatus1234;
                {
                    retainedOwnerPositionOrTarget17 = (int)&Level21_7E0A8Data70328View1 + 0x8C;
                    rawWord2 =
                        Level21_7E0A8MeasureVectorLengthView1(retainedOwnerPositionOrTarget17, 0);
                    argumentWord4 = (int)&originalFrame.sp20;
                    argumentWord5 = retainedOwnerPositionOrTarget17;
                    MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                    retainedTimerHeadingVectorOrList16 = rawWord2;
                    Level21_7E0A8CopyVectorView1(argumentWord4, argumentWord5);
                    argumentWord4 = (int)&originalFrame.sp20;
                    MATCHING_OBSERVE_VOLATILE(argumentWord4);
                    argumentWord5 = retainedTimerHeadingVectorOrList16;
                    retainedTimerHeadingVectorOrList16 = argumentWord5 - 280;
                    argumentWord6 = retainedTimerHeadingVectorOrList16;
                    originalFrame.sp28 = 0;
                    Level21_7E0A8ScaleVectorRatioQ15View1(argumentWord4, argumentWord5,
                                                          argumentWord6);
                    rawWord2 = originalFrame.sp20;
                    rawWord3 = originalFrame.sp24;
                    retainedTimerHeadingVectorOrList16 = retainedTimerHeadingVectorOrList16 < 1800;
                    Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 0) = rawWord2;
                    Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x90) = rawWord3;
                    if (retainedTimerHeadingVectorOrList16) {
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 73);
                        if ((short)rawWord2 == 0) {
                            rawWord2++;
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 73) = rawWord2;
                        }
                    }
                    retainedOwnerPositionOrTarget17 =
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49);
                    if (retainedOwnerPositionOrTarget17 == 1) {
                        Level21_7E0A8CopyVectorView1(&originalFrame.sp30,
                                                     (int)&Level21_7E0A8Data70328View1);
                        temporaryWord3 = Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1,
                                                            unsigned char*, 0xE) *
                                         2;
                        originalFrame.sp30 +=
                            (int)(Level21_7E0A8Field((int)&Level21_7E0A8Data65920View1, short*,
                                                     temporaryWord3) *
                                  0x177) >>
                            0xA;
                        originalFrame.sp34 +=
                            (int)(Level21_7E0A8Field((int)&Level21_7E0A8Data658A0View1, short*,
                                                     temporaryWord3) *
                                  0x177) >>
                            0xA;
                        if (Level21_7E0A8ApproximatePlanarDistanceView1(
                                ownerRecord19 + 0xC, &originalFrame.sp30) < 0x1F4) {
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49) =
                                (unsigned char)(Level21_7E0A8Field(ownerRecord19, unsigned char*,
                                                                   0x49) +
                                                1);
                            return;
                        }
                        if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) != 7) {
                            Level21_7E0A8Data6C770View1 = 0;
                            Level21_7E0A8Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) = 7U;
                            Level21_7E0A8Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Level21_7E0A8EmptyAnimationTransitionHookView1(ownerRecord19);
                        }
                        if (Level21_7E0A8TurnMobyTowardHeadingView1(
                                ownerRecord19,
                                Level21_7E0A8PlanarHeadingLookupView1(
                                    originalFrame.sp30 -
                                        Level21_7E0A8Field(ownerRecord19, int*, 0xC),
                                    originalFrame.sp34 -
                                        Level21_7E0A8Field(ownerRecord19, int*, 0x10),
                                    0),
                                7, 0x14, (int)retainedOwnerPositionOrTarget17, 0) != 0) {
                            Level21_7E0A8Call35DDCView1(ownerRecord19, 0x8C, 0, 0, 5);
                        }
                        rawWord2 = Level21_7E0A8PlanarHeadingLookupView1(
                            originalFrame.sp30 - Level21_7E0A8Field(ownerRecord19, int*, 12),
                            originalFrame.sp34 - Level21_7E0A8Field(ownerRecord19, int*, 16), 0);
                        rawWord2 = rawWord2 < 81;
                        if (!rawWord2)
                            goto originalIncrement982;
                        goto sharedOriginalStatus1234;
                    }
                    goto sharedOriginalStatus1234;
                }
            originalTargetState2:
                rawWord2 = Level21_7E0A8TurnMobyTowardPlayerView1(ownerRecord19, 5, 4, 1);
                goto originalTest980;
            originalTargetState3:
                Level21_7E0A8Call512E4View1(ownerRecord19, 0, 1);
                Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 1U;
                goto sharedOriginalStatus1234;
            case 1:
                if (Level21_7E0A8Data6E344View1 != 1) {
                    if (Level21_7E0A8Field(privateRecord20, unsigned char*, 4) == 1) {
                        Level21_7E0A8Field(privateRecord20, int*, 0x80) = 0;
                        Level21_7E0A8Field(privateRecord20, int*, 0x84) = 0;
                        Level21_7E0A8Field(privateRecord20, int*, 0x88) = 0;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49) = 0U;
                        Level21_7E0A8Field(Level21_7E0A8Field(privateRecord20, void**, 0x4C),
                                           short*, 2) =
                            (short)Level21_7E0A8Field(
                                ((Level21_7E0A8Field(privateRecord20, int*, 0x84) * 0xC) +
                                 Level21_7E0A8Field(privateRecord20, int*, 0x90)),
                                int*, 0);
                        Level21_7E0A8Field(privateRecord20, signed char*, 5) = 1;
                        Level21_7E0A8Call3B7B4View1(privateRecord20 + 5, 1,
                                                    (int)&Level21_7E0A8Data6C7F8View1);
                        temporaryWord8 = Level21_7E0A8Field(
                            Level21_7E0A8Field(privateRecord20, void**, 0x50), void**, 0xC);
                        temporaryWord5 = Level21_7E0A8Field(temporaryWord8, int*, 0x10);
                        Level21_7E0A8Call3B634View1(
                            (int)&Level21_7E0A8Data6D088View1,
                            Level21_7E0A8Field(Level21_7E0A8Field(privateRecord20, void**, 0x50),
                                               void**, 0xC),
                            Level21_7E0A8PlanarHeadingLookupView1(
                                temporaryWord5 - Level21_7E0A8Field(temporaryWord8, int*, 0),
                                Level21_7E0A8Field(temporaryWord8, int*, 0x14) -
                                    Level21_7E0A8Field(temporaryWord8, int*, 4),
                                0));
                        temporaryWord2 = Level21_7E0A8Data6C58CView1 * 6;
                        temporaryWord19 = Level21_7E0A8Field((int)&Level21_7E0A8Data716ACView1,
                                                             unsigned char*, 1 + temporaryWord2);
                        if (temporaryWord19 < 0xFFU) {
                            Level21_7E0A8Field((int)&Level21_7E0A8Data716ACView1, unsigned char*,
                                               1 + temporaryWord2) = temporaryWord19 + 1;
                        }
                        Level21_7E0A8Data6E160View1 = 0x21;
                        Level21_7E0A8Data6E168View1 =
                            Level21_7E0A8PlanarHeadingLookupView1(
                                Level21_7E0A8Field(ownerRecord19, int*, 0xC) -
                                    Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0),
                                Level21_7E0A8Field(ownerRecord19, int*, 0x10) -
                                    Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 4),
                                0) *
                            0x10;
                        Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) = 0x5FU;
                        Level21_7E0A8Field(privateRecord20, short*, 0xAE) = 1;
                        Level21_7E0A8Field(privateRecord20, short*, 0xB6) = 0;
                        Level21_7E0A8Field(privateRecord20, short*, 0xB4) = 0;
                        Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA6) = 0U;
                        Level21_7E0A8Field(privateRecord20, int*, 0xB8) = 0;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 7U;
                        Level21_7E0A8RequestMobyAnimationView1(ownerRecord19, 7);
                        return;
                    }
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    Level21_7E0A8RequestMobyAnimationView1(ownerRecord19, 0);
                    goto sharedOriginalStatus1234;
                }
                goto sharedOriginalStatus1234;
            case 7:
                retainedOwnerPositionOrTarget17 = (int)&Level21_7E0A8Data6E168View1;
                retainedTimerHeadingVectorOrList16 =
                    Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 0);
                rawWord3 = Level21_7E0A8SubAngle12View1(retainedTimerHeadingVectorOrList16, 0);
                rawWord2 = rawWord3 < 39;
                if (!rawWord2) {
                    rawWord3 = 38;
                    MATCHING_KEEP(rawWord3);
                }
                rawWord2 = rawWord3 < -38;
                if (rawWord2)
                    rawWord3 = -38;
                rawWord2 = retainedTimerHeadingVectorOrList16 + rawWord3;
                retainedTimerHeadingVectorOrList16 = rawWord2 & 4095;
                Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 0) =
                    retainedTimerHeadingVectorOrList16;
                if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49) != 0) {
                    Level21_7E0A8Call38BF8View1(ownerRecord19, privateRecord20 + 0x34, 7, 2);
                    Level21_7E0A8Field(privateRecord20, short*, 0x38) = 0x172;
                    Level21_7E0A8Field(privateRecord20, signed char*, 0x42) = 3;
                    Level21_7E0A8Field(privateRecord20, unsigned char*, 0x4A) = 0xFFU;
                    if (Level21_7E0A8Call3BFC0View1(
                            ownerRecord19, Level21_7E0A8Field(privateRecord20, int*, 0x9C)) != 0) {
                        Level21_7E0A8Call3BE70View1(
                            Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                    }
                    Level21_7E0A8Field(privateRecord20, int*, 0x9C) = -1;
                    return;
                }
                temporaryWord4 = Level21_7E0A8Field(privateRecord20, int*, 0x88);
                Level21_7E0A8Field(privateRecord20, int*, 0x80) =
                    (int)(Level21_7E0A8Field(privateRecord20, int*, 0x80) +
                          Level21_7E0A8Data6C648View1);
                if ((temporaryWord4 < 0xB) &&
                    (Level21_7E0A8CountTimerDownView1(
                         Level21_7E0A8Field(privateRecord20, int*, 0x94) + (temporaryWord4 * 8) + 4,
                         4) != 0)) {
                    rawWord2 = Level21_7E0A8Field(privateRecord20, int*, 0x88) * 8 +
                               Level21_7E0A8Field(privateRecord20, int*, 0x94);
                    rawWord2 = Level21_7E0A8Field(rawWord2, int*, 0) * 4 + privateRecord20;
                    rawWord3 = Level21_7E0A8Field(rawWord2, int*, 0x54);
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = rawWord3 * 88;
                    rawWord3 = Level21_7E0A8Data6C550View1;
                    rawWord3 += rawWord2;
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = 1;
                    Level21_7E0A8Field(rawWord3, unsigned char*, 73) = rawWord2;
                    Level21_7E0A8Field(privateRecord20, int*, 0x88) =
                        (int)(Level21_7E0A8Field(privateRecord20, int*, 0x88) + 1);
                }
                temporaryWord20 = Level21_7E0A8Field(privateRecord20, short*, 0x8C);
                switch (temporaryWord20) {
                    case 0:
                        rawWord2 = Level21_7E0A8Data6C648View1;
                        rawWord3 = Level21_7E0A8Field(privateRecord20, unsigned short*, 0xA4);
                        rawWord3 += rawWord2;
                        Level21_7E0A8Field(privateRecord20, unsigned short*, 0xA4) = rawWord3;
                        retainedTimerHeadingVectorOrList16 =
                            Level21_7E0A8CountTimerDownView1(privateRecord20 + 0xA8, 2);
                        rawWord2 = 2;
                        MATCHING_KEEP(rawWord2);
                        if (retainedTimerHeadingVectorOrList16 == rawWord2) {
                            Level21_7E0A8PlayMobySoundEventView1(ownerRecord19, 2, 0);
                            rawWord3 = Level21_7E0A8Field(privateRecord20, short*, 0xAC);
                            if (rawWord3 == retainedTimerHeadingVectorOrList16)
                                goto writeOriginalTimerValue504;
                            rawWord2 = rawWord3 < 3;
                            if (!rawWord2)
                                goto testOriginalTimerSelector496;
                            rawWord2 = 1;
                            if (rawWord3 == rawWord2)
                                goto writeOriginalTimerValue501;
                            rawWord2 = -200;
                            goto callOriginalMovement525;
                        testOriginalTimerSelector496:
                            rawWord2 = 3;
                            if (rawWord3 == rawWord2)
                                goto writeOriginalTimerValue507;
                            rawWord2 = -200;
                            goto callOriginalMovement525;
                        writeOriginalTimerValue501:
                            rawWord2 = 140;
                            Level21_7E0A8Field(privateRecord20, short*, 0xB0) = rawWord2;
                            rawWord2 = 22;
                            goto writeOriginalTimerDelta509;
                        writeOriginalTimerValue504:
                            rawWord2 = 140;
                            Level21_7E0A8Field(privateRecord20, short*, 0xB0) = rawWord2;
                            rawWord2 = 27;
                            goto writeOriginalTimerDelta509;
                        writeOriginalTimerValue507:
                            rawWord2 = 200;
                            Level21_7E0A8Field(privateRecord20, short*, 0xB0) = rawWord2;
                            rawWord2 = 23;
                        writeOriginalTimerDelta509:
                            Level21_7E0A8Field(privateRecord20, short*, 0xB2) = rawWord2;
                            Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) = 0x6EU;
                            if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) != 4) {
                                Level21_7E0A8Data6C770View1 = 0;
                                Level21_7E0A8Field(ownerRecord19, signed char*, 0x40) = 0x72;
                                Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) = 4U;
                                Level21_7E0A8Field(ownerRecord19, signed char*, 0x3F) = 0;
                                Level21_7E0A8EmptyAnimationTransitionHookView1(ownerRecord19);
                            }
                            rawWord2 = -200;
                        } else
                            rawWord2 = -200;
                    callOriginalMovement525:
                        if (Level21_7E0A8Call37A60View1(ownerRecord19, privateRecord20 + 0xB0, 2,
                                                        12, -200) == 0) {
                            Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA6) =
                                (unsigned char)(Level21_7E0A8Field(privateRecord20, unsigned char*,
                                                                   0xA6) +
                                                (unsigned char)Level21_7E0A8Field(privateRecord20,
                                                                                  short*, 0xB2));
                        } else if ((Level21_7E0A8Field(privateRecord20, short*, 0xA8) == 0) &&
                                   (Level21_7E0A8Field(privateRecord20, short*, 0xAC) != 0)) {
                            Level21_7E0A8Field(privateRecord20, short*, 0xAC) = 0;
                            if (Level21_7E0A8Call3BFC0View1(
                                    ownerRecord19,
                                    Level21_7E0A8Field(privateRecord20, int*, 0x9C)) == 0) {
                                Level21_7E0A8Field(privateRecord20, int*, 0x9C) =
                                    Level21_7E0A8PlayMobySoundEventView1(ownerRecord19, 1, 4);
                            }
                            if (Level21_7E0A8AbsoluteByteAngleDeltaView1(
                                    Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA6),
                                    0x80) < 0x40) {
                                Level21_7E0A8Field(privateRecord20, short*, 0xB6) = 1;
                            } else {
                                Level21_7E0A8Field(privateRecord20, short*, 0xB4) = 1;
                            }
                        }
                        temporaryWord21 = Level21_7E0A8Field(privateRecord20, int*, 0xB8);
                        if (temporaryWord21 != 0) {
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) =
                                (unsigned char)(Level21_7E0A8Field(ownerRecord19, unsigned char*,
                                                                   0x46) -
                                                temporaryWord21);
                        }
                        rawWord2 = Level21_7E0A8Call35A80View1(
                            ownerRecord19, Level21_7E0A8Field(privateRecord20, void**, 0x4C), 256,
                            Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7), 0, 6, 40, 1);
                        rawWord3 = Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA6);
                        retainedTimerHeadingVectorOrList16 = rawWord2;
                        if (rawWord3)
                            Level21_7E0A8Field(privateRecord20, int*, 0xB8) = rawWord3;
                        if (Level21_7E0A8Field(privateRecord20, int*, 0xB8) != 0) {
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) =
                                (unsigned char)(Level21_7E0A8Field(ownerRecord19, unsigned char*,
                                                                   0x46) +
                                                Level21_7E0A8Field(privateRecord20, unsigned char*,
                                                                   0xA6));
                        }
                        if (((int)Level21_7E0A8Field(privateRecord20, int*, 0xB4) != 0) &&
                            (Level21_7E0A8Call3BFC0View1(
                                 ownerRecord19, Level21_7E0A8Field(privateRecord20, int*, 0x9C)) !=
                             0)) {
                            Level21_7E0A8Call3C140View1(
                                Level21_7E0A8Field(privateRecord20, int*, 0x9C),
                                (Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) - 0x14) *
                                    0x2D);
                        }
                        rawWord2 = Level21_7E0A8Field(privateRecord20, short*, 0xB6);
                        if (!rawWord2)
                            goto originalSecondTurn629;
                        rawWord2 = 6;
                        rawWord3 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 61);
                        argumentWord4 = (int)ownerRecord19;
                        if (rawWord3 == rawWord2)
                            goto block_99;
                        rawWord2 = 114;
                        Level21_7E0A8Data6C770View1 = 0;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 64) = rawWord2;
                        __asm__ volatile(
                            "" ::"m"(Level21_7E0A8Field(ownerRecord19, unsigned char*, 64)),
                            "i"(0x8007EA70)
                            : "memory");
                        rawWord2 = 6;
                        goto block_98;
                    originalSecondTurn629:
                        rawWord2 = Level21_7E0A8Field(privateRecord20, short*, 0xB4);
                        if (!rawWord2)
                            goto originalNoTurn655;
                        rawWord2 = 5;
                        rawWord3 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 61);
                        argumentWord4 = (int)ownerRecord19;
                        if (rawWord3 == rawWord2)
                            goto block_99;
                        rawWord2 = 114;
                        Level21_7E0A8Data6C770View1 = 0;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 64) = rawWord2;
                        __asm__ volatile(
                            "" ::"m"(Level21_7E0A8Field(ownerRecord19, unsigned char*, 64)),
                            "i"(0x8007EAA8)
                            : "memory");
                        rawWord2 = 5;
                    block_98:
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 61) = rawWord2;
                        Level21_7E0A8Field(ownerRecord19, signed char*, 63) = 0;
                        Level21_7E0A8EmptyAnimationTransitionHookView1(argumentWord4);
                    block_99:
                        rawWord2 = Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) - 2;
                        Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) = rawWord2;
                        rawWord2 &= 255;
                        if ((unsigned)rawWord2 < 50)
                            Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) = 50;
                        goto originalTurnDone667;
                    originalNoTurn655:
                        rawWord3 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 61);
                        rawWord2 = 7;
                        argumentWord4 = (int)ownerRecord19;
                        if (rawWord3 != rawWord2) {
                            rawWord2 = 114;
                            Level21_7E0A8Data6C770View1 = 0;
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 64) = rawWord2;
                            rawWord2 = 7;
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 61) = rawWord2;
                            Level21_7E0A8Field(ownerRecord19, signed char*, 63) = 0;
                            Level21_7E0A8EmptyAnimationTransitionHookView1(argumentWord4);
                        }
                    originalTurnDone667:
                        if ((rawWord2 = retainedTimerHeadingVectorOrList16 & 1)) {
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x84);
                            MATCHING_KEEP(rawWord3);
                            rawWord2 = rawWord3 * 3;
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x90);
                            rawWord2 = rawWord2 * 4 + rawWord3;
                            rawWord2 = Level21_7E0A8Field(rawWord2, int*, 8);
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x84);
                            Level21_7E0A8Field(privateRecord20, short*, 0x8E) = rawWord2;
                            __asm__ volatile(
                                "" ::"m"(Level21_7E0A8Field(privateRecord20, short*, 0x8E))
                                : "memory");
                            MATCHING_KEEP(rawWord3);
                            rawWord2 = rawWord3 * 3;
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x90);
                            rawWord2 = rawWord2 * 4 + rawWord3;
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x84);
                            rawWord2 = Level21_7E0A8Field(rawWord2, int*, 4);
                            rawWord3++;
                            Level21_7E0A8Field(privateRecord20, short*, 0x8C) = rawWord2;
                            __asm__ volatile(
                                "" ::"m"(Level21_7E0A8Field(privateRecord20, short*, 0x8C))
                                : "memory");
                            rawWord2 = rawWord3 * 3;
                            Level21_7E0A8Field(privateRecord20, int*, 0x84) = rawWord3;
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x90);
                            rawWord2 = rawWord2 * 4 + rawWord3;
                            rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x4C);
                            rawWord2 = Level21_7E0A8Field(rawWord2, int*, 0);
                            Level21_7E0A8Field(rawWord3, short*, 2) = rawWord2;
                            Level21_7E0A8Field(privateRecord20, unsigned short*, 0xA4) = 0;
                        }
                        goto sharedOriginalStatus1234;
                    case 1:
                        rawWord2 = Level21_7E0A8Call3BFC0View1(
                            ownerRecord19, Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                        retainedOwnerPositionOrTarget17 = -1;
                        if (rawWord2) {
                            Level21_7E0A8Call3BE70View1(
                                Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                        }
                        Level21_7E0A8Field(privateRecord20, int*, 0x9C) =
                            retainedOwnerPositionOrTarget17;
                        if (Level21_7E0A8Call3BFC0View1(ownerRecord19, -1) == 0) {
                            Level21_7E0A8Field(privateRecord20, int*, 0x9C) =
                                Level21_7E0A8PlayMobySoundEventView1(ownerRecord19, 0, 4);
                        }
                        if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) != 4) {
                            Level21_7E0A8Data6C770View1 = 0;
                            Level21_7E0A8Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) = 4U;
                            Level21_7E0A8Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Level21_7E0A8EmptyAnimationTransitionHookView1(ownerRecord19);
                        }
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) =
                            (unsigned char)(Level21_7E0A8Field(ownerRecord19, unsigned char*,
                                                               0x46) +
                                            (Level21_7E0A8Field(privateRecord20, short*, 0xAE) *
                                             8));
                        temporaryWord22 = Level21_7E0A8Field(privateRecord20, void**, 0x4C);
                        temporaryWord9 = (Level21_7E0A8Field(temporaryWord22, short*, 2) * 0x10) +
                                         Level21_7E0A8Field(temporaryWord22, int*, 0xC);
                        retainedTimerHeadingVectorOrList16 = Level21_7E0A8SubAngle8View1(
                            Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46),
                            Level21_7E0A8PlanarHeadingLookupView1(
                                Level21_7E0A8Field(temporaryWord9, int*, 0) -
                                    Level21_7E0A8Field(ownerRecord19, int*, 0xC),
                                Level21_7E0A8Field(temporaryWord9, int*, 4) -
                                    Level21_7E0A8Field(ownerRecord19, int*, 0x10),
                                0));
                        if (Level21_7E0A8Field(privateRecord20, short*, 0xB6) != 0) {
                            temporaryWord15 = Level21_7E0A8Field(privateRecord20, void**, 0x4C);
                            temporaryWord10 =
                                (Level21_7E0A8Field(temporaryWord15, short*, 2) * 0x10) +
                                Level21_7E0A8Field(temporaryWord15, int*, 0xC);
                            retainedTimerHeadingVectorOrList16 = Level21_7E0A8SubAngle8View1(
                                (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) + 0x80) &
                                    0xFF,
                                Level21_7E0A8PlanarHeadingLookupView1(
                                    Level21_7E0A8Field(temporaryWord10, int*, 0) -
                                        Level21_7E0A8Field(ownerRecord19, int*, 0xC),
                                    Level21_7E0A8Field(temporaryWord10, int*, 4) -
                                        Level21_7E0A8Field(ownerRecord19, int*, 0x10),
                                    0));
                        }
                        if ((Level21_7E0A8CountTimerDownView1(privateRecord20 + 0x8E, 2) != 0) &&
                            (retainedTimerHeadingVectorOrList16 < 0)) {
                            MATCHING_KEEP(retainedTimerHeadingVectorOrList16);
                            rawWord2 = retainedTimerHeadingVectorOrList16;
                            if (retainedTimerHeadingVectorOrList16 < 0)
                                rawWord2 = -rawWord2;
                            if (rawWord2 < 20) {
                                rawWord2 = Level21_7E0A8Call3BFC0View1(
                                    ownerRecord19, Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                                if (rawWord2)
                                    Level21_7E0A8Call3BE70View1(
                                        Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                                rawWord2 = 95;
                                Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA7) =
                                    rawWord2;
                                rawWord2 = Level21_7E0A8Field(privateRecord20, short*, 0xAE);
                                rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 0x84);
                                Level21_7E0A8Field(privateRecord20, int*, 0x9C) =
                                    retainedOwnerPositionOrTarget17;
                                Level21_7E0A8Field(privateRecord20, short*, 0x8C) = 0;
                                Level21_7E0A8Field(privateRecord20, short*, 0xAA) = 0;
                                Level21_7E0A8Field(privateRecord20, unsigned char*, 0xA6) = 0;
                                Level21_7E0A8Field(privateRecord20, int*, 0xB8) = 0;
                                Level21_7E0A8Field(privateRecord20, short*, 0xB6) = 0;
                                Level21_7E0A8Field(privateRecord20, short*, 0xB4) = 0;
                                __asm__ volatile(
                                    "" ::"m"(Level21_7E0A8Field(privateRecord20, short*, 0xB4)),
                                    "r"(rawWord2), "r"(rawWord3)
                                    : "memory");
                                rawWord2 = -rawWord2;
                                rawWord3--;
                                Level21_7E0A8Field(privateRecord20, short*, 0xAE) = rawWord2;
                                temporaryWord16 = rawWord3 + 1;
                                switch (temporaryWord16) {
                                    case 1:
                                        rawWord2 = 60;
                                        Level21_7E0A8Field(privateRecord20, short*, 0xA8) =
                                            rawWord2;
                                        __asm__ volatile("" ::"m"(Level21_7E0A8Field(
                                                             privateRecord20, short*, 0xA8)),
                                                         "i"(0x8007ED78)
                                                         : "memory");
                                        rawWord2 = 1;
                                        goto writeOriginalTimerSelector;
                                    case 2:
                                        rawWord2 = 120;
                                        Level21_7E0A8Field(privateRecord20, short*, 0xA8) =
                                            rawWord2;
                                        __asm__ volatile("" ::"m"(Level21_7E0A8Field(
                                                             privateRecord20, short*, 0xA8)),
                                                         "i"(0x8007ED88)
                                                         : "memory");
                                        rawWord2 = 2;
                                        goto writeOriginalTimerSelector;
                                    case 4:
                                        rawWord2 = 120;
                                        Level21_7E0A8Field(privateRecord20, short*, 0xA8) =
                                            rawWord2;
                                        __asm__ volatile("" ::"m"(Level21_7E0A8Field(
                                                             privateRecord20, short*, 0xA8)),
                                                         "i"(0x8007ED98)
                                                         : "memory");
                                        rawWord2 = 2;
                                        goto writeOriginalTimerSelector;
                                    case 5:
                                        rawWord2 = 120;
                                        Level21_7E0A8Field(privateRecord20, short*, 0xA8) =
                                            rawWord2;
                                        __asm__ volatile("" ::"m"(Level21_7E0A8Field(
                                                             privateRecord20, short*, 0xA8)),
                                                         "i"(0x8007EDA8)
                                                         : "memory");
                                        rawWord2 = 1;
                                        goto writeOriginalTimerSelector;
                                    case 6:
                                        rawWord2 = 30;
                                        Level21_7E0A8Field(privateRecord20, short*, 0xA8) =
                                            rawWord2;
                                        rawWord2 = 3;
                                        break;
                                    default:
                                        goto advanceOriginalTarget839;
                                }
                            writeOriginalTimerSelector:
                                Level21_7E0A8Field(privateRecord20, short*, 0xAC) = rawWord2;
                            advanceOriginalTarget839:
                                if (Level21_7E0A8Field(privateRecord20, int*, 0x84) >= 7) {
                                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 0x15U;
                                    return;
                                }
                                goto sharedOriginalStatus1234;
                            }
                            goto sharedOriginalStatus1234;
                        }
                        goto sharedOriginalStatus1234;
                    default:
                        goto sharedOriginalStatus1234;
                }
                break;
            case 21:
                if (Level21_7E0A8Call3BFC0View1(
                        ownerRecord19, Level21_7E0A8Field(privateRecord20, int*, 0x9C)) != 0) {
                    Level21_7E0A8Call3BE70View1(Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                }
                Level21_7E0A8Field(privateRecord20, int*, 0x9C) = -1;
                if (Level21_7E0A8Call3BFC0View1(ownerRecord19, -1) == 0) {
                    Level21_7E0A8Field(privateRecord20, int*, 0x9C) =
                        Level21_7E0A8Call3BB10View1(ownerRecord19, 6, 4);
                }
                Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49) = 0U;
                Level21_7E0A8Field(privateRecord20, short*, 0x8E) = 0x1C2;
                Level21_7E0A8Field(privateRecord20, short*, 0xA0) = 0;
                Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 0x16U;
                goto sharedOriginalStatus1234;
            case 22:
                temporaryWord17 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x49);
                switch (temporaryWord17) {
                    case 0:
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 61);
                        retainedTimerHeadingVectorOrList16 = 8;
                        argumentWord4 = privateRecord20 + 0xA2;
                        if (rawWord2 != retainedTimerHeadingVectorOrList16)
                            goto originalTurn901;
                        rawWord2 = Level21_7E0A8Data6C770View1;
                        if (!rawWord2)
                            goto block_146;
                        rawWord2 = 20;
                        Level21_7E0A8Field(privateRecord20, short*, 0xA2) = rawWord2;
                        rawWord3 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 61);
                        __asm__ volatile("" ::: "$2", "memory");
                        rawWord2 = 4;
                        argumentWord4 = (int)ownerRecord19;
                        if (rawWord3 == rawWord2)
                            goto block_146;
                        rawWord2 = 114;
                        Level21_7E0A8Data6C770View1 = 0;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 64) = rawWord2;
                        __asm__ volatile(
                            "" ::"m"(Level21_7E0A8Field(ownerRecord19, unsigned char*, 64)),
                            "i"(0x8007EEB0)
                            : "memory");
                        rawWord2 = 4;
                        goto block_145;
                    originalTurn901:
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 70) + 5;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 70) = rawWord2;
                        rawWord2 = Level21_7E0A8CountTimerDownView1(argumentWord4, 2);
                        argumentWord4 = privateRecord20 + 0xA0;
                        if (!rawWord2)
                            goto originalTimer921;
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 61);
                        if (rawWord2 == retainedTimerHeadingVectorOrList16)
                            goto block_146;
                        argumentWord4 = (int)ownerRecord19;
                        rawWord2 = 114;
                        Level21_7E0A8Data6C770View1 = 0;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 64) = rawWord2;
                        __asm__ volatile(
                            "" ::"m"(Level21_7E0A8Field(ownerRecord19, unsigned char*, 64)),
                            "i"(0x8007EEF4)
                            : "memory");
                        rawWord2 = 8;
                    block_145:
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 61) = rawWord2;
                        Level21_7E0A8Field(ownerRecord19, signed char*, 63) = 0;
                        Level21_7E0A8EmptyAnimationTransitionHookView1(argumentWord4);
                    block_146:
                        argumentWord4 = privateRecord20 + 0xA0;
                    originalTimer921:
                        if (Level21_7E0A8CountTimerDownView1(argumentWord4, 2) != 0) {
                            retainedOwnerPositionOrTarget17 =
                                Level21_7E0A8DataSpawnMobyView1(0x14F, ownerRecord19);
                            retainedScalarMatrixOrGlobal18 =
                                Level21_7E0A8Field(retainedOwnerPositionOrTarget17, void**, 0);
                            rawWord2 = Level21_7E0A8DatarandView1();
                            argumentWord4 = 1200;
                            argumentWord5 = 4500;
                            MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                            retainedTimerHeadingVectorOrList16 = rawWord2;
                            temporaryWord11 =
                                Level21_7E0A8RandBetweenView1(argumentWord4, argumentWord5);
                            retainedTimerHeadingVectorOrList16 =
                                (retainedTimerHeadingVectorOrList16 & 0xFF) * 2;
                            Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 0xC) =
                                (int)(Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*,
                                                         0xC) +
                                      ((int)(Level21_7E0A8Field(
                                                 (int)&Level21_7E0A8Data65920View1, short*,
                                                 retainedTimerHeadingVectorOrList16) *
                                             temporaryWord11) >>
                                       0xC));
                            Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 0x10) =
                                (int)(Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*,
                                                         0x10) +
                                      ((int)(Level21_7E0A8Field(
                                                 (int)&Level21_7E0A8Data658A0View1, short*,
                                                 retainedTimerHeadingVectorOrList16) *
                                             temporaryWord11) >>
                                       0xC));
                            Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 20) =
                                Level21_7E0A8Field(retainedOwnerPositionOrTarget17, int*, 20) +
                                6144;
                            Level21_7E0A8Field(privateRecord20, short*, 160) =
                                Level21_7E0A8RandBetweenView1(4, 8);
                            Level21_7E0A8Field(retainedOwnerPositionOrTarget17, unsigned char*,
                                               0x4A) = 0xFF;
                            Level21_7E0A8Field(retainedScalarMatrixOrGlobal18, short*, 2) =
                                Level21_7E0A8RandSignedBetweenView1(3, 5);
                            Level21_7E0A8Field(retainedScalarMatrixOrGlobal18, short*, 0) =
                                Level21_7E0A8RandSignedBetweenView1(5, 9);
                        }
                        rawWord2 = Level21_7E0A8CountTimerDownView1(privateRecord20 + 0x8E, 2);
                    originalTest980:
                        if (!rawWord2)
                            goto sharedOriginalStatus1234;
                    originalIncrement982:
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 73);
                        rawWord2++;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 73) = rawWord2;
                        goto sharedOriginalStatus1234;
                    case 1:
                        argumentWord4 = (int)&originalFrame.sp20;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
                        retainedOwnerPositionOrTarget17 = (int)ownerRecord19 + 12;
                        Level21_7E0A8CopyVectorView1(argumentWord4,
                                                     retainedOwnerPositionOrTarget17);
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, signed char*, 68);
                        rawWord3 = Level21_7E0A8Field(ownerRecord19, signed char*, 69);
                        argumentWord4 = Level21_7E0A8Field(ownerRecord19, signed char*, 70);
                        MATCHING_OBSERVE3_VOLATILE(rawWord2, rawWord3, argumentWord4);
                        Level21_7E0A8Field(&originalFrame.sp30, signed char*, 0) = rawWord2;
                        Level21_7E0A8Field(&originalFrame.sp30, signed char*, 1) = rawWord3;
                        Level21_7E0A8Field(&originalFrame.sp30, signed char*, 2) = argumentWord4;
                        Level21_7E0A8CopyVectorView1(
                            retainedOwnerPositionOrTarget17,
                            Level21_7E0A8Field(Level21_7E0A8Field(privateRecord20, void**, 0x50),
                                               void**, 0xC) +
                                0x10);
                        temporaryWord12 = Level21_7E0A8Field(
                            Level21_7E0A8Field(privateRecord20, void**, 0x50), void**, 0xC);
                        temporaryWord6 = Level21_7E0A8Field(temporaryWord12, int*, 0);
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) =
                            Level21_7E0A8PlanarHeadingLookupView1(
                                temporaryWord6 - Level21_7E0A8Field(temporaryWord12, int*, 0x10),
                                Level21_7E0A8Field(temporaryWord12, int*, 4) -
                                    Level21_7E0A8Field(temporaryWord12, int*, 0x14),
                                0);
                        Level21_7E0A8Field(Level21_7E0A8Field(ownerRecord19, void**, 0),
                                           signed char*, 5) = 2;
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 70);
                        __asm__ volatile("" ::: "$16", "memory");
                        retainedTimerHeadingVectorOrList16 = (int)&originalFrame.sp40;
                        rawWord2 *= 2;
                        rawWord3 =
                            Level21_7E0A8Field((int)&Level21_7E0A8Data65920View1, short*, rawWord2);
                        argumentWord4 = retainedTimerHeadingVectorOrList16;
                        rawWord2 = (rawWord3 * 39) >> 6;
                        originalFrame.sp40 = rawWord2;
                        __asm__ volatile("" ::"m"(originalFrame.sp40) : "memory");
                        rawWord2 = Level21_7E0A8Field(ownerRecord19, unsigned char*, 70);
                        __asm__ volatile("" ::: "$5", "memory");
                        argumentWord5 = retainedTimerHeadingVectorOrList16;
                        rawWord2 *= 2;
                        rawWord3 =
                            Level21_7E0A8Field((int)&Level21_7E0A8Data658A0View1, short*, rawWord2);
                        __asm__ volatile("" ::: "$2", "memory");
                        rawWord2 =
                            Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x44);
                        argumentWord6 = retainedOwnerPositionOrTarget17;
                        Level21_7E0A8Field(&originalFrame.sp48, volatile int*, 0) = 0;
                        originalFrame.sp48 = rawWord2;
                        rawWord2 = (rawWord3 * 39) >> 6;
                        originalFrame.sp44 = rawWord2;
                        Level21_7E0A8AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                        Level21_7E0A8Call13D44View1(
                            &originalFrame.sp40,
                            (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) + 0x80) & 0xFF,
                            0, 0);
                        rawWord2 =
                            Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x280);
                        if (rawWord2 < 0)
                            Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0x280) = 0;
                        rawWord2 = 23;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 72) = rawWord2;
                        __asm__ volatile(
                            "" ::"m"(Level21_7E0A8Field(ownerRecord19, unsigned char*, 72))
                            : "$4", "memory");
                        argumentWord4 = retainedOwnerPositionOrTarget17;
                        Level21_7E0A8CopyVectorView1(argumentWord4, &originalFrame.sp20);
                        rawWord2 = Level21_7E0A8Field(&originalFrame.sp30, signed char*, 0);
                        rawWord3 = Level21_7E0A8Field(&originalFrame.sp30, signed char*, 1);
                        argumentWord4 = Level21_7E0A8Field(&originalFrame.sp30, signed char*, 2);
                        MATCHING_OBSERVE3_VOLATILE(rawWord2, rawWord3, argumentWord4);
                        Level21_7E0A8Field(ownerRecord19, signed char*, 68) = rawWord2;
                        Level21_7E0A8Field(ownerRecord19, signed char*, 69) = rawWord3;
                        Level21_7E0A8Field(ownerRecord19, volatile signed char*, 70) =
                            argumentWord4;
                        __asm__ volatile(
                            "" ::"m"(Level21_7E0A8Field(ownerRecord19, signed char*, 70))
                            : "memory");
                        break;
                }
                goto sharedOriginalStatus1234;
            case 23:
                if (Level21_7E0A8Data6E048View1 & 1) {
                    if (Level21_7E0A8Call3BFC0View1(
                            ownerRecord19, Level21_7E0A8Field(privateRecord20, int*, 0x9C)) != 0) {
                        Level21_7E0A8Call3BE70View1(
                            Level21_7E0A8Field(privateRecord20, int*, 0x9C));
                    }
                    retainedTimerHeadingVectorOrList16 = (int)&Level21_7E0A8Data6E788View1;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(retainedTimerHeadingVectorOrList16, "$2");
                    rawWord2 = -1;
                    Level21_7E0A8Field(privateRecord20, int*, 0x9C) = rawWord2;
                    argumentWord4 = Level21_7E0A8Field(retainedTimerHeadingVectorOrList16, int*, 0);
                    retainedTimerHeadingVectorOrList16 += 4;
                    if (argumentWord4) {
                        retainedOwnerPositionOrTarget17 = 335;
                        do {
                            rawWord2 = Level21_7E0A8Field(argumentWord4, short*, 54);
                            if (rawWord2 == retainedOwnerPositionOrTarget17)
                                Level21_7E0A8DeleteMobyView1(argumentWord4);
                            argumentWord4 =
                                Level21_7E0A8Field(retainedTimerHeadingVectorOrList16, int*, 0);
                            retainedTimerHeadingVectorOrList16 += 4;
                        } while (argumentWord4);
                    }
                    Level21_7E0A8ClearVectorView1((int)&Level21_7E0A8Data70328View1 + 0x8C);
                    argumentWord4 = (int)ownerRecord19 + 12;
                    rawWord3 = Level21_7E0A8Field(privateRecord20, int*, 80);
                    rawWord2 = Level21_7E0A8Data6C7B4View1;
                    argumentWord5 = Level21_7E0A8Field(rawWord3, int*, 12);
                    rawWord2 |= 2;
                    Level21_7E0A8Data6C7B4View1 = rawWord2;
                    Level21_7E0A8CopyVectorView1(argumentWord4, argumentWord5 + 16);
                    Level21_7E0A8Call37014View1(ownerRecord19);
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x52) = 0xFE;
                    Level21_7E0A8RefreshMobySpatialGridAndBasisView1(ownerRecord19, 2);
                    temporaryWord13 = Level21_7E0A8Field(
                        Level21_7E0A8Field(privateRecord20, void**, 0x50), void**, 0xC);
                    temporaryWord7 = Level21_7E0A8Field(temporaryWord13, int*, 0);
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x46) =
                        Level21_7E0A8PlanarHeadingLookupView1(
                            temporaryWord7 - Level21_7E0A8Field(temporaryWord13, int*, 0x10),
                            Level21_7E0A8Field(temporaryWord13, int*, 4) -
                                Level21_7E0A8Field(temporaryWord13, int*, 0x14),
                            0);
                    Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                }
                goto sharedOriginalStatus1234;
            case 2:
                MATCHING_KEEP(ownerRecord19);
                argumentWord4 = (int)ownerRecord19 + 12;
                if (Level21_7E0A8Data6C770View1 != 0) {
                    if (Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) != 0) {
                        Level21_7E0A8Data6C770View1 = 0;
                        Level21_7E0A8Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Level21_7E0A8Field(ownerRecord19, unsigned char*, 0x3D) = 0U;
                        Level21_7E0A8Field(ownerRecord19, signed char*, 0x3F) = 0;
                        Level21_7E0A8EmptyAnimationTransitionHookView1(ownerRecord19);
                    }
                    MATCHING_KEEP(ownerRecord19);
                    argumentWord4 = (int)ownerRecord19 + 12;
                }
                if (Level21_7E0A8ApproximatePlanarDistanceView1(
                        argumentWord4, (int)&Level21_7E0A8Data70328View1) >= 0x9C5) {
                    argumentWord6 = 0;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord6, "$18");
                    retainedScalarMatrixOrGlobal18 = (int)&Level21_7E0A8Data6E168View1;
                    retainedTimerHeadingVectorOrList16 =
                        Level21_7E0A8Field(retainedScalarMatrixOrGlobal18, int*, 0);
                    rawWord3 = Level21_7E0A8SubAngle12View1(
                        retainedTimerHeadingVectorOrList16,
                        Level21_7E0A8PlanarHeadingLookupView1(
                            Level21_7E0A8Field(ownerRecord19, int*, 0xC) -
                                Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 0),
                            Level21_7E0A8Field(ownerRecord19, int*, 0x10) -
                                Level21_7E0A8Field((int)&Level21_7E0A8Data70328View1, int*, 4),
                            argumentWord6) *
                            0x10);
                    rawWord2 = rawWord3 < 81;
                    if (!rawWord2) {
                        rawWord3 = 80;
                        MATCHING_KEEP(rawWord3);
                    }
                    rawWord2 = rawWord3 < -80;
                    if (rawWord2)
                        rawWord3 = -80;
                    rawWord2 = retainedTimerHeadingVectorOrList16 + rawWord3;
                    retainedTimerHeadingVectorOrList16 = rawWord2 & 4095;
                    Level21_7E0A8Field(retainedScalarMatrixOrGlobal18, int*, 0) =
                        retainedTimerHeadingVectorOrList16;
                }
                Level21_7E0A8Call35194View1(ownerRecord19, privateRecord20 + 0x34);
                if (Level21_7E0A8Field(ownerRecord19, int*, 0x14) ==
                    (Level21_7E0A8ProbeGroundFromRaisedMobyView1(ownerRecord19) +
                     Level21_7E0A8Field(ownerRecord19, short*, 0x38))) {
                    temporaryWord23 = Level21_7E0A8SubAngle8View1(
                        (unsigned char)Level21_7E0A8Field(ownerRecord19, signed char*, 0x45),
                        -0x40);
                    Level21_7E0A8Field(privateRecord20, unsigned char*, 0x4B) =
                        (unsigned char)(Level21_7E0A8Field(privateRecord20, unsigned char*, 0x4B) &
                                        0xF);
                    if (temporaryWord23 >= 6) {
                        temporaryWord23 = 5;
                    }
                    if (temporaryWord23 < -5) {
                        temporaryWord23 = -5;
                    }
                    Level21_7E0A8Field(ownerRecord19, signed char*, 0x45) =
                        (signed char)((unsigned char)Level21_7E0A8Field(ownerRecord19, signed char*,
                                                                        0x45) +
                                      temporaryWord23);
                }
                if (((unsigned char)Level21_7E0A8Field(privateRecord20, unsigned char*, 0x4A) <
                     0x14U) ||
                    (Level21_7E0A8Field(privateRecord20, short*, 0x38) == 0)) {
                    Level21_7E0A8Call3B74CView1((int)&Level21_7E0A8Data6D088View1);
                }
                goto sharedOriginalStatus1234;
            default:
            sharedOriginalStatus1234:
                if (Level21_7E0A8Field(privateRecord20, void**, 0x98) != 0) {
                    Level21_7E0A8Call39B6CView1(ownerRecord19, privateRecord20 + 0x98);
                }
                Level21_7E0A8Field(Level21_7E0A8Field(privateRecord20, void**, 0x98),
                                   unsigned char*, 0x47) = 0xFA;
                break;
        }
    }
}
#undef Level21_7E0A8Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-derived C. Original source asm/nonmatchings/overlays/level_21/moby/func_level_21_8007F438.s SHA256 763bf3b2b638a0f3a7f772daf74d15595aec91087ec0bcd1f31484ca64d2414e. Reuses native-exact Scorch raw334 C, whose Rev1 source-local decoder is recorded in batch6017. Original6076 proves this controller instead loads private word+8 into spawned private+12; source/helper semantic equivalence is not inferred. Cadence per invocation only. Raw units/fixed point, helper and producer/consumer chains and synchronized runtime checks remain unresolved. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define ControllerField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int ControllerF438_func_8001830C() __asm__("func_8001830C");      /* extern */
int ControllerF438_func_80036220() __asm__("func_80036220");      /* extern */
int ControllerF438_func_80036A68() __asm__("func_80036A68");      /* extern */
int ControllerF438_func_80037A60() __asm__("func_80037A60");      /* extern */
int ControllerF438_func_800399E8() __asm__("func_800399E8");      /* extern */
int ControllerF438_func_80039B6C() __asm__("func_80039B6C");      /* extern */
int ControllerF438_func_80040954() __asm__("func_80040954");      /* extern */
int ControllerF438MeasureVectorLength() __asm__("func_8004EDE8"); /* extern */
int ControllerF438SubtractVector() __asm__("func_8004F1C8");      /* extern */
int ControllerF438DeleteMoby() __asm__("func_80055B18");          /* extern */
int ControllerF438_rand() __asm__("rand");                        /* extern */
extern unsigned char ControllerF438_D_800658A0 __asm__("D_800658A0");
extern unsigned char ControllerF438_D_80065920 __asm__("D_80065920");
extern void** ControllerF438_D_8006C550 __asm__("D_8006C550");
extern unsigned short ControllerF438_D_8006E040 __asm__("D_8006E040");
extern unsigned char* (*CrystalParticle)() __asm__("SpawnParticle");
extern unsigned char ControllerInitialPlayer __asm__("D_80070328");
extern unsigned char ControllerF438_D_80070328 __asm__("D_80070328");
extern int ControllerF438_D_80071918 __asm__("D_80071918");
extern int ControllerF438_D_8007191C __asm__("D_8007191C");
extern int ControllerF438_D_80071924 __asm__("D_80071924");

void func_level_21_8007F438(Moby* inputOwner) {
    struct {
        unsigned char sp18;
        char pad_19[15];
        Vector3D sp28;
        char pad_34[4];
        Vector3D sp38;
        char pad_44[4];
        int sp48;
        int sp4C;
        int sp50;
        char pad_54[20];
    } frame;

    register Moby* owner __asm__("$19") = inputOwner;

    register Moby* spawned4 __asm__("$4");
    register Vector3D* position16 __asm__("$16");
    register int signedTurn4 __asm__("$4");
    register int signedSpeed4 __asm__("$4");
    register int magnitude2 __asm__("$2");
    register int turnResult2 __asm__("$2");
    register int speedMagnitude2 __asm__("$2");
    register int rawDistance21 __asm__("$21");
    register int rawMotion21 __asm__("$21");
    register int heightDifference2 __asm__("$2");
    register int contactHeight2 __asm__("$2");
    register int rawAngle17 __asm__("$17");
    register int randomX2 __asm__("$2");
    register int randomY2 __asm__("$2");
    register int groundZ3 __asm__("$3");
    register int damage3 __asm__("$3");
    register int contactGroundZ3 __asm__("$3");
    register int activate16 __asm__("$16");
    register int rawAngle16 __asm__("$16");
    register int decay17 __asm__("$17");
    register int decay20 __asm__("$20");
    register int speedResult2 __asm__("$2");
    register int state3 __asm__("$3");
    register int yaw2 __asm__("$2");
    register int nextYaw2 __asm__("$2");
    register void* privateData __asm__("$18");
    register void* attachment3 __asm__("$3");
    register void* timer5 __asm__("$5");

    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    int product;
    register unsigned char* (*callback8)() __asm__("$8");
    register void* vector17 __asm__("$17");
    register void* global16 __asm__("$16");
    register void* vector16 __asm__("$16");
    MATCHING_KEEP(owner);
    value3 = 125;
    value2 = owner->state;
    privateData = owner->mobyTag;
    if (value2 != value3) {
        if (ControllerField(privateData, void**, 0xC) == 0) {
            ControllerF438_func_800399E8(inputOwner, privateData + 0xC);
        }
        argument4 = (int)&frame.sp18;
        argument5 = (int)&owner->position;
        MATCHING_KEEP2(argument4, argument5);
        global16 = &ControllerInitialPlayer;
        ControllerF438SubtractVector(argument4, argument5, global16);
        value2 = ControllerF438MeasureVectorLength(&frame.sp18, 0);
        argument4 = (int)&owner->substate;
        argument5 = 1;
        MATCHING_KEEP2(argument4, argument5);
        rawDistance21 = value2;
        func_800359A4(argument4, argument5);
        state3 = owner->state;
        switch (state3) { /* irregular */
            case 0:
                value2 = ControllerField(&ControllerF438_D_80070328, int*, 0x138);
                value3 = owner->substate;
                activate16 = value2 == (int)owner;
                if ((value3 == 0) && ((value2 = rawDistance21 < 800))) {
                    value3 = owner->distanceToGround;
                    value2 = owner->position.z;
                    argument4 = ControllerField(&ControllerF438_D_80070328, int*, 8);
                    groundZ3 = value2 - value3;
                    heightDifference2 = groundZ3 - argument4;
                    if (heightDifference2 >= 0) {
                        if (heightDifference2 < 0x258) {
                            MATCHING_KEEP_VOLATILE(activate16);
                            activate16 = 1;
                        }
                    } else if ((heightDifference2 = argument4 - groundZ3) < 600) {
                        activate16 = 1;
                    }
                }
                damage3 = owner->damageFlags;
                if (damage3 & 0x120000) {
                    activate16 = 1;
                }
                if ((value2 = damage3 & 0x10000)) {
                    func_8003BABC(owner, 0, 0);
                    owner->state = 0xA;
                }
                if (activate16 == 0)
                    goto afterState;
                value2 = 1;
                MATCHING_KEEP(value2);
                goto activateState;
                break;
            case 10:
                ControllerField(privateData, signed char*, 0) = 0x64;
                if (ControllerField(privateData, short*, 2) == 0) {
                    ControllerField(privateData, short*, 2) = 0xF0;
                }
                if (ControllerField(privateData, unsigned char*, 1) == 0) {
                    yaw2 = owner->unkb;
                    if (yaw2 == 0) {
                        MATCHING_KEEP(yaw2);
                        yaw2 = func_800360F8(
                            func_8004E880(owner->position.x - ControllerField(global16, int*, 0),
                                          owner->position.y -
                                              ControllerField(&ControllerF438_D_80070328, int*, 4),
                                          0),
                            (int)ControllerField(&ControllerF438_D_80070328, unsigned char*, 0xE),
                            0x20, 0x40U);
                    }
                    ControllerField(privateData, unsigned char*, 1) = yaw2;
                }
                ControllerField(privateData, short*, 6) = (short)(func_800363DC(5, 0xB) * 0x10);
                if (ControllerField(privateData, short*, 4) == 0) {
                    ControllerField(privateData, short*, 4) = 0x32;
                }
                owner->state = 3;
                /* fallthrough */
            case 3:
                decay20 = 3;
                decay17 = 4;
                if (owner->damageFlags & 0x10000) {
                    if (ControllerField(privateData, short*, 2) < 0xC8) {
                        ControllerField(privateData, short*, 2) = 0xC8;
                    }
                    nextYaw2 = owner->unkb;
                    if (nextYaw2 == 0) {
                        MATCHING_KEEP(nextYaw2);
                        nextYaw2 = func_800360F8(
                            func_8004E880(owner->position.x -
                                              ControllerField(&ControllerF438_D_80070328, int*, 0),
                                          owner->position.y -
                                              ControllerField(&ControllerF438_D_80070328, int*, 4),
                                          0),
                            (int)ControllerField(&ControllerF438_D_80070328, unsigned char*, 0xE),
                            0x20, 0x40U);
                    }
                    ControllerField(privateData, unsigned char*, 1) = nextYaw2;
                }
                value2 = func_8003BFC0(owner, ControllerField(privateData, int*, 16));
                argument4 = (int)owner;
                if (value2 == 0) {
                    ControllerField(privateData, int*, 16) = func_8003BABC(argument4, 1, 4);
                }
                value2 = owner->substate;
                argument4 = (int)owner;
                if (value2 != 0)
                    goto contactArg5Ready;
                value2 = rawDistance21 < 800;
                timer5 = privateData + 4;
                if (!value2)
                    goto contactArgsReady;
                value3 = owner->distanceToGround;
                value2 = owner->position.z;
                argument4 = ControllerField(&ControllerF438_D_80070328, int*, 8);
                contactGroundZ3 = value2 - value3;
                contactHeight2 = contactGroundZ3 - argument4;
                if (contactHeight2 >= 0) {
                    if (contactHeight2 < 600)
                        goto setContactState;
                    argument4 = (int)owner;
                    goto contactArgsReady;
                }
                contactHeight2 = argument4 - contactGroundZ3;
                if (contactHeight2 < 600) {
                setContactState:
                    owner->state = 1;
                }
            contactArgs:
                argument4 = (int)owner;
            contactArg5Ready:
                timer5 = privateData + 4;
            contactArgsReady:
                argument6 = 2;
                argument7 = 14;
                MATCHING_KEEP4(argument4, timer5, argument6, argument7);
                vector16 = &ControllerF438_D_80071924;
                ControllerField(vector16, int*, 0) = 255;
                ControllerF438_func_80037A60(argument4, timer5, argument6, argument7, -200);
                if (ControllerF438_func_80040954(ControllerField(vector16, int*, 0)) != 4) {
                    attachment3 = ControllerField(privateData, void**, 0xC);
                    value2 = 248;
                    if (attachment3 != 0) {
                        ControllerField(attachment3, unsigned char*, 71) = value2;
                        MATCHING_KEEP_CLOBBER(value2, "memory");
                    }
                    MATCHING_BARRIER_VOLATILE("memory");
                    decay20 = 0xE;
                    decay17 = 0x18;
                }
                signedTurn4 = ControllerField(privateData, short*, 6);
                magnitude2 = signedTurn4;
                if (signedTurn4 < 0) {
                    magnitude2 = -magnitude2;
                }
                if (magnitude2 < decay17) {
                    ControllerField(privateData, short*, 6) = 0;
                } else {
                    value3 = signedTurn4;
                    MATCHING_KEEP(value3);
                    turnResult2 = value3 - decay17;
                    if (signedTurn4 < 0) {
                        turnResult2 = value3 + decay17;
                    }
                    ControllerField(privateData, short*, 6) = turnResult2;
                }
                owner->angle.yaw +=
                    (int)((unsigned short)ControllerField(privateData, short*, 6) << 0x10) >> 0x14;
                value2 =
                    func_80035EE0(owner, (int)ControllerField(privateData, unsigned char*, 1),
                                  (int)ControllerField(privateData, short*, 2), 0x1F4, 0xC8, 0x21);
                vector17 = &frame.sp28;
                argument4 = (int)vector17;
                MATCHING_KEEP(argument4);
                position16 = &owner->position;
                argument5 = (int)position16;
                MATCHING_KEEP(argument5);
                rawMotion21 = value2;
                func_8004F178(argument4, argument5);
                frame.sp28.z += 0x96;
                frame.sp28.x =
                    frame.sp28.x +
                    ((int)(ControllerField(&ControllerF438_D_80065920, short*,
                                           (ControllerField(privateData, unsigned char*, 1) * 2)) *
                           (ControllerField(privateData, short*, 2) + 0x96)) >>
                     0xC);
                frame.sp28.y +=
                    (int)(ControllerField(&ControllerF438_D_800658A0, short*,
                                          (ControllerField(privateData, unsigned char*, 1) * 2)) *
                          (ControllerField(privateData, short*, 2) + 0x96)) >>
                    0xC;
                value2 = ControllerF438_func_8001830C(position16, &frame.sp28, 0, 0, owner);
                if (value2 != 0) {
                    rawAngle17 =
                        func_8004E880(ControllerF438_D_80071918, ControllerF438_D_8007191C, 0);
                    rawAngle16 = rawAngle17 + 0x40;
                    if (func_8004F264(rawAngle16 & 0xFF,
                                      (int)ControllerField(privateData, unsigned char*, 1)) >=
                        0x41) {
                        rawAngle16 = rawAngle17 - 0x40;
                    }
                    value2 = func_8003613C(ControllerField(privateData, unsigned char*, 1),
                                           rawAngle16 & 255);
                    value3 = ControllerField(privateData, unsigned char*, 1);
                    value2 *= 2;
                    value3 += value2;
                    value2 = ControllerField(privateData, short*, 6);
                    ControllerField(privateData, unsigned char*, 1) = value3;
                    value3 = ControllerField(privateData, short*, 2);
                    value2 = -value2;
                    ControllerField(privateData, short*, 6) = value2;
                    MATCHING_KEEP_CLOBBER(value3, "memory");
                    speedResult2 = (value3 * 3) >> 2;
                    goto storeSpeed;
                }
                if ((value2 = rawMotion21 & 32)) {
                    ControllerField(privateData, signed char*, 0) = 0;
                } else {
                    signedSpeed4 = ControllerField(privateData, short*, 2);
                    speedMagnitude2 = signedSpeed4;
                    if (signedSpeed4 < 0) {
                        speedMagnitude2 = -speedMagnitude2;
                    }
                    if (speedMagnitude2 < decay20) {
                        ControllerField(privateData, short*, 2) = 0;
                    } else {
                        value3 = signedSpeed4;
                        MATCHING_KEEP(value3);
                        speedResult2 = value3 - decay20;
                        if (signedSpeed4 < 0) {
                            speedResult2 = value3 + decay20;
                        }
                    storeSpeed:
                        ControllerField(privateData, short*, 2) = (short)speedResult2;
                    }
                }
                func_8004F178(&frame.sp38, &owner->position);
                value2 = func_800363DC(0, 50);
                argument4 = 0;
                value3 = frame.sp38.z;
                __asm__("" : "=r"(value3) : "0"(value3), "r"(argument4) : "$5");
                argument5 = 250;
                __asm__(""
                        : "=r"(argument4), "=r"(argument5)
                        : "0"(argument4), "1"(argument5), "r"(value3));
                value3 += 675;
                value3 += value2;
                frame.sp38.z = value3;
                frame.sp38.x = frame.sp38.x + func_8003636C(argument4, argument5);
                frame.sp38.y += func_8003636C(0, 0xFA);
                randomX2 = (ControllerF438_rand() & 0x1F) - 0x10;
                frame.sp48 = randomX2;
                value2 = ControllerF438_rand();
                argument4 = 25;
                argument5 = 35;
                MATCHING_KEEP3(argument4, argument5, value2);
                randomY2 = (value2 & 31) - 16;
                frame.sp4C = randomY2;
                frame.sp50 = func_8003636C(argument4, argument5);

                value2 = ControllerField(privateData, unsigned short*, 2);
                value2 <<= 16;
                MATCHING_KEEP_CLOBBER(value2, "memory");
                value3 = value2 >> 16;
                value2 = (short)(value3 / 3);
                value3 = ControllerField(&ControllerF438_D_80065920, short*,
                                         ControllerField(privateData, unsigned char*, 1) * 2);
                product = value3 * value2;
                value2 = frame.sp48;
                value3 = product >> 12;
                value2 += value3;
                frame.sp48 = value2;
                value2 = ControllerField(privateData, unsigned short*, 2);
                value2 <<= 16;
                MATCHING_KEEP_CLOBBER(value2, "memory");
                value3 = value2 >> 16;
                value2 = (short)(value3 / 3);
                value3 = ControllerField(&ControllerF438_D_800658A0, short*,
                                         ControllerField(privateData, unsigned char*, 1) * 2);
                product = value3 * value2;
                argument5 = 13;
                MATCHING_KEEP(argument5);
                argument6 = (int)&frame.sp38;
                argument7 = (int)&frame.sp48;
                callback8 = CrystalParticle;
                __asm__(""
                        : "=r"(callback8)
                        : "0"(callback8), "r"(argument5), "r"(argument6), "r"(argument7)
                        : "$4");
                argument4 = 1;
                value2 = frame.sp4C;
                value3 = product >> 12;
                value2 += value3;
                frame.sp4C = value2;
                ControllerField(callback8(argument4, argument5, argument6, argument7), signed char*,
                                2) = 4;
                value2 = func_800359A4(privateData, 1);
                if (value2 == 0)
                    goto afterState;
                value2 = 1;
                MATCHING_KEEP(value2);
            activateState:
                MATCHING_BARRIER_VOLATILE("memory");
                owner->state = value2;
                break;
        }
    afterState:
        owner->damageFlags = 0;
        if (owner->state == 1) {
            spawned4 = SpawnMoby(0x169, owner);
            MATCHING_KEEP(spawned4);
            if (spawned4 != 0) {
                ControllerField(spawned4->mobyTag, int*, 0xC) =
                    (int)ControllerField(privateData, int*, 8);
                spawned4->angle.yaw = ((int)(ControllerF438_D_8006E040 << 0x10) >> 0x14) - 0x40;
            }
            if (owner->gemValue != 0xFF) {
                ControllerF438_func_80036A68(owner, 0, 0, 0);
                func_8003BA00(owner);
            }
            if ((ControllerField(privateData, int*, 0x14) != 0) &&
                (ControllerF438_func_80036220(&owner->position, privateData + 0x18, 0, 0) != 0)) {
                ControllerField(((ControllerField(privateData, int*, 0x30) * 0x58) +
                                 (int)ControllerF438_D_8006C550),
                                signed char*, 0x49) = 1;
            }
            if (func_8003BFC0(owner, ControllerField(privateData, int*, 0x10)) != 0) {
                func_8003BE70(ControllerField(privateData, int*, 0x10));
            }
            ControllerField(privateData, int*, 0x10) = -1;
            ControllerF438DeleteMoby(owner);
        }
        if (ControllerField(privateData, void**, 0xC) != 0) {
            ControllerF438_func_80039B6C(owner, privateData + 0xC);
        }
    }
}
#undef ControllerField

typedef struct {
    unsigned char pitch, reserved01, yaw, reserved03;
    int value;
} DecodedTurnStepTag;
int func_8003613C(int, int);
int DecodedStepAdvance(Moby*, int*, int, int, int) __asm__("func_80037A60");
void func_level_21_8007FC58(Moby* moby) {
    DecodedTurnStepTag* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            moby->angle.yaw += tag->yaw;
            moby->angle.pitch += tag->pitch;
            if (DecodedStepAdvance(moby, &tag->value, 4, 5, -0xC8))
                moby->state = 1;
            if (tag->value < -0xC8)
                tag->value = -0xC8;
            break;
        case 1: {
            register int first __asm__("$2");
            register int target __asm__("$5");
            int turn, opposite;
            first = func_8003613C(moby->angle.pitch, 0);
            target = 0x80;
            __asm__("" : "=r"(target) : "0"(target), "r"(first));
            turn = first;
            opposite = func_8003613C(moby->angle.pitch, target);
            if (ABS(turn) > ABS(opposite))
                turn = opposite;
            if (turn > 14)
                turn = 14;
            if (turn < -14)
                turn = -14;
            moby->angle.pitch += turn;
            if (turn == 0)
                moby->state = 2;
        } break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original6145 complete instructions.
 * Accepted level32 controller reused only where original21 proves identity.
 * Rev1 raw270 is structural support for the baseline only; target-specific
 * Rev1 crosswalk not established. Incoming physical register21 is read by
 * original21 without a local assignment; its producer remains unresolved.
 * Units/helper chains/cadence/runtime parity unresolved. Exact native/linked
 * words, conditional targets, owned data and complete retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int ControllerFD94_func_800410F8() __asm__("func_800410F8");
int ControllerFD94ClearVector() __asm__("func_8004F168");
int ControllerFD94ApproximatePlanarDistance() __asm__("func_8004F334");
int ControllerFD94RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern signed short ControllerFD94_D_800658A0 __asm__("D_800658A0");
extern signed short ControllerFD94_D_80065920 __asm__("D_80065920");
extern int ControllerFD94_D_80069020 __asm__("D_80069020");
extern int ControllerFD94_D_80069024 __asm__("D_80069024");
extern int ControllerFD94_D_80069028 __asm__("D_80069028");
extern int ControllerFD94_D_8006C58C __asm__("D_8006C58C");
extern int ControllerFD94_D_8006E160 __asm__("D_8006E160");
extern int ControllerFD94_D_8006E53C __asm__("D_8006E53C");
extern unsigned char ControllerFD94_D_80070328 __asm__("D_80070328");
extern signed char ControllerFD94_D_80071573 __asm__("D_80071573");
extern unsigned char ControllerFD94_D_level_21_8008F6A0 __asm__("D_level_21_8008F6A0");
extern unsigned char ControllerFD94_StreamBegin __asm__("func_level_21_80075060");
extern unsigned char main_TEXT_END;
extern unsigned char main_TEXT_START;

extern int ControllerFD94_D_8006C640 __asm__("D_8006C640");
extern int ControllerFD94_D_8006763C __asm__("D_8006763C");
extern int ControllerFD94_D_80067640 __asm__("D_80067640");
extern int ControllerFD94_D_80067644 __asm__("D_80067644");
void func_level_21_8007FD94(Moby* inputMoby) {
    /* Member names retain original stack offsets and raw retail units. */
    struct {
        int sp10;
        int sp14;
    } originalStack;

    register Moby* moby __asm__("$17") = inputMoby;

    register unsigned char* inherited21 __asm__("$21");
    register int previousValue18 __asm__("$18");
    register int* limitAddress5 __asm__("$5");
    register int limitValue4 __asm__("$4");
    register int previousValue20 __asm__("$20");
    register int tableIndex3 __asm__("$3");
    register int firstAccumulator3 __asm__("$3");
    register int currentValue3 __asm__("$3");
    register int secondAccumulator3 __asm__("$3");
    register int firstBitCount4 __asm__("$4");
    register int secondBitCount4 __asm__("$4");
    register int firstByteCount5 __asm__("$5");
    register int secondByteCount5 __asm__("$5");
    register int angle2 __asm__("$2");
    register int firstWord2 __asm__("$2");
    register int secondWord2 __asm__("$2");
    register unsigned int initialStreamPointer3 __asm__("$3");
    register unsigned int nextStreamPointer3 __asm__("$3");
    register unsigned int secondStreamPointer3 __asm__("$3");
    register int frameByte2 __asm__("$2");
    register int phase3 __asm__("$3");
    register int state3 __asm__("$3");
    register void* privateData __asm__("$16");
    register void* playerLink18 __asm__("$18");
    register void* eventAddress4 __asm__("$4");
    register unsigned int streamEnd4 __asm__("$4");
    register unsigned int streamEnd7 __asm__("$7");
    register unsigned int streamBegin6 __asm__("$6");
    register unsigned int secondEnd6 __asm__("$6");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register unsigned char* playerLink19 __asm__("$19");
    register int* event18 __asm__("$18");

    MATCHING_KEEP(moby);
    phase3 = moby->substate;
    privateData = moby->mobyTag;

    switch (phase3) {
        case 0:
            if (ControllerFD94_D_8006C640 == 0) {
                moby->animationProgress = 5;
                M2C_FIELD(privateData, int*, 0x10) = 40;
            }
            ControllerFD94ClearVector(privateData);
            if ((unsigned int)M2C_FIELD(privateData, unsigned int*, 0x1C) >=
                (unsigned int)&ControllerFD94_StreamBegin) {
                secondByteCount5 = 0;
                secondEnd6 = (unsigned int)&ControllerFD94_D_level_21_8008F6A0;
            secondStreamByte:
                secondStreamPointer3 = M2C_FIELD(privateData, unsigned int*, 0x1C);
                if (secondStreamPointer3 < secondEnd6) {
                    secondBitCount4 = 0;
                    M2C_FIELD(privateData, int*, 0x2C) =
                        (int)(M2C_FIELD(privateData, int*, 0x2C) ^
                              (M2C_FIELD(secondStreamPointer3, unsigned char*, 0) << 8));
                    do {
                        secondAccumulator3 = M2C_FIELD(privateData, int*, 0x2C);
                        secondWord2 = secondAccumulator3 & 0x8000;
                        if (secondWord2)
                            secondWord2 = (secondAccumulator3 * 2) ^ 0x8005;
                        else
                            secondWord2 = secondAccumulator3 * 2;
                        M2C_FIELD(privateData, int*, 0x2C) = secondWord2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        secondBitCount4 += 1;
                    } while (secondBitCount4 < 8);
                    secondByteCount5 += 1;
                    M2C_FIELD(privateData, unsigned int*, 0x1C) =
                        (unsigned int)(M2C_FIELD(privateData, unsigned int*, 0x1C) + 1);
                    if (secondByteCount5 < 0x40) {
                        goto secondStreamByte;
                    }
                }
            }

            playerLink18 = &ControllerFD94_D_80070328 + 0x13C;
            MATCHING_KEEP(playerLink18);
            if (M2C_FIELD(playerLink18, Moby**, 0) == moby) {
                if (ControllerFD94ApproximatePlanarDistance(&moby->position, playerLink18 - 0x13C) <
                    0x300) {
                    moby->substate = 1;
                    ControllerFD94_D_80069020 = 0x136;
                    ControllerFD94_D_80069024 = 0x7D0;
                    ControllerFD94_D_80069028 = -0xC4;
                } else {
                    if (func_8004F264(
                            (int)moby->angle.yaw,
                            func_8004E880(M2C_FIELD(playerLink18, int*, -0x13C) - moby->position.x,
                                          M2C_FIELD(&ControllerFD94_D_80070328, int*, 4) -
                                              moby->position.y,
                                          0)) < 0x80) {
                        angle2 = moby->angle.yaw + 0x40;
                    } else {
                        angle2 = moby->angle.yaw + 0xC0;
                    }
                    tableIndex3 = angle2 & 255;
                    MATCHING_KEEP(tableIndex3);
                    value2 = 0x10000480;
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x20C) = value2;
                    value2 = 7;
                    tableIndex3 *= 2;
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x23C) = value2;
                    value2 = M2C_FIELD(&ControllerFD94_D_80065920, signed short*, tableIndex3);
                    MATCHING_KEEP(value2);
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x21C) = value2 >> 6;
                    value2 = M2C_FIELD(&ControllerFD94_D_800658A0, signed short*, tableIndex3);
                    MATCHING_KEEP(value2);
                    value3 = 16;
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x224) = value3;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x220) = value2 >> 6;
                }
            }
            break;
        case 1:
            if (ControllerFD94_D_8006E53C & 0x40)
                goto cancelPhase1;
            playerLink19 = &ControllerFD94_D_80070328 + 0x13C;
            if (M2C_FIELD(playerLink19, Moby**, 0) != moby) {
            cancelPhase1:
                eventAddress4 = &ControllerFD94_D_8006E160;
                MATCHING_KEEP(eventAddress4);
                moby->substate = 0;
                value3 = M2C_FIELD(eventAddress4, int*, 0);
                if (value3 == 14)
                    M2C_FIELD(eventAddress4, int*, 0) = 0;
            } else {
                event18 = &ControllerFD94_D_8006E160;
                if (*event18 == 0) {
                    func_80013ACC(moby, 0xE);
                }
                if (*event18 == 0xE) {
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x20C) = 0x10000040;
                    M2C_FIELD(&ControllerFD94_D_80070328, Moby**, 0x218) = moby;
                    func_8004F178(playerLink19 + 0xF0, &moby->position);
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x238) = (int)moby->angle.yaw;
                    if (M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x214) == 2) {
                        M2C_FIELD(privateData, int*, 0xC) = 0;
                        moby->substate = 2;
                    }
                }
            }
            break;
        case 2:
            if (ControllerFD94_D_8006E53C & 0x40)
                goto cancelPhase2;
            playerLink19 = &ControllerFD94_D_80070328 + 0x13C;
            if (M2C_FIELD(playerLink19, Moby**, 0) != moby) {
            cancelPhase2:
                eventAddress4 = &ControllerFD94_D_8006E160;
                MATCHING_KEEP(eventAddress4);
                moby->substate = 0;
                value3 = M2C_FIELD(eventAddress4, int*, 0);
                if (value3 == 14)
                    M2C_FIELD(eventAddress4, int*, 0) = 0;
            } else {
                event18 = &ControllerFD94_D_8006E160;
                previousValue20 = M2C_FIELD(privateData, int*, 0x10);
                if (*event18 == 0) {
                    func_80013ACC(moby, 0xE);
                }
                if (*event18 == 0xE) {
                    ControllerFD94_func_800410F8(&originalStack.sp10, privateData, 1);
                    moby->angle.yaw += (int)(originalStack.sp10 + 0xA) >> 5;
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x20C) = 0x10018000;
                    func_8004F178(playerLink19 + 0xF0, &moby->position);
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x234) =
                        (int)(M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x234) + 0x283);
                    M2C_FIELD(&ControllerFD94_D_80070328, unsigned char*, 0x228) =
                        (unsigned char)moby->angle.roll;
                    M2C_FIELD(&ControllerFD94_D_80070328, unsigned char*, 0x229) =
                        (unsigned char)moby->angle.pitch;
                    MATCHING_BARRIER_VOLATILE("memory");
                    value2 = moby->angle.yaw;
                    M2C_FIELD(&ControllerFD94_D_80070328, int*, 0x23C) = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                    M2C_FIELD(&ControllerFD94_D_80070328, unsigned char*, 0x22A) = value2;
                    MATCHING_BARRIER_VOLATILE("memory");
                    value2 = originalStack.sp14;
                    currentValue3 = M2C_FIELD(privateData, int*, 0x10);
                    value2 >>= 5;
                    currentValue3 -= value2;
                    M2C_FIELD(privateData, int*, 0x10) = currentValue3;
                    if (currentValue3 < 0) {
                        M2C_FIELD(privateData, int*, 0x10) = 0;
                    }
                    if (M2C_FIELD(privateData, int*, 0x10) >= 0x79) {
                        M2C_FIELD(privateData, int*, 0x10) = 0x78;
                    }
                }
                value2 = -8;
                currentValue3 = M2C_FIELD(privateData, int*, 0x10);
                firstBitCount4 = previousValue20 & value2;
                currentValue3 &= value2;
                if (firstBitCount4 != currentValue3) {
                    if (func_8003BFC0(moby, M2C_FIELD(privateData, int*, 0x14)) != 0) {
                        func_8003BE70(M2C_FIELD(privateData, int*, 0x14));
                    }
                    M2C_FIELD(privateData, int*, 0x14) = func_8003BABC(moby, 0, 0);
                    MATCHING_KEEP_VOLATILE(privateData);
                }
                if ((func_800359A4(privateData + 12, 4) != 0) &&
                    (ControllerFD94_D_8006E53C & 0x20)) {
                    moby->state = 1;
                }
            }
            ControllerFD94RefreshMobySpatialGridAndBasis(moby, 4);
            break;
    }
    if (moby->position.z < 0x2800) {
        initialStreamPointer3 = M2C_FIELD(privateData, unsigned int*, 0x1C);
        streamEnd4 = (unsigned int)&main_TEXT_END;
        if (initialStreamPointer3 < streamEnd4) {
            firstByteCount5 = 0;
            if (initialStreamPointer3 <= 0x7FFFU) {
                M2C_FIELD(privateData, unsigned int*, 0x1C) =
                    (unsigned int)(ControllerFD94_D_8006C58C + (&main_TEXT_START + 2));
            }
            streamEnd7 = streamEnd4;
            streamBegin6 = (unsigned int)&ControllerFD94_StreamBegin;
        firstStreamByte:
            firstBitCount4 = 0;
            M2C_FIELD(privateData, int*, 0x2C) =
                (int)(M2C_FIELD(privateData, int*, 0x2C) ^
                      (M2C_FIELD(M2C_FIELD(privateData, unsigned int*, 0x1C), unsigned char*, 0)
                       << 8));
            do {
                firstAccumulator3 = M2C_FIELD(privateData, int*, 0x2C);
                firstWord2 = firstAccumulator3 & 0x8000;
                if (firstWord2) {
                    firstWord2 = (firstAccumulator3 * 2) ^ 0x8005;
                } else {
                    firstWord2 = firstAccumulator3 * 2;
                }
                M2C_FIELD(privateData, int*, 0x2C) = firstWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                firstBitCount4 += 1;
            } while (firstBitCount4 < 8);
            firstWord2 = M2C_FIELD(privateData, int*, 0x2C);
            nextStreamPointer3 = M2C_FIELD(privateData, unsigned int*, 0x1C);
            firstWord2 &= 3;
            firstWord2 += 1;
            nextStreamPointer3 += firstWord2;
            M2C_FIELD(privateData, unsigned int*, 0x1C) = nextStreamPointer3;
            firstByteCount5 += 1;
            if (nextStreamPointer3 >= streamEnd7) {
                M2C_FIELD(privateData, unsigned int*, 0x1C) = streamBegin6;
                firstByteCount5 = 0x40;
                MATCHING_KEEP(firstByteCount5);
                firstByteCount5++;
            }
            if (firstByteCount5 < 0x40) {
                goto firstStreamByte;
            }
        }
    }
    state3 = moby->state;
    switch (state3) {
        case 0:
            moby->animationState.id = 0;
            moby->animationState.nextId = 2;
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = 0;
            moby->animationProgress = M2C_FIELD(privateData, int*, 0x10) >> 3;
            if (M2C_FIELD(privateData, unsigned int*, 0x1C) ==
                    (unsigned int)&ControllerFD94_D_level_21_8008F6A0 &&
                M2C_FIELD(privateData, int*, 0x2C) != 0) {
                limitAddress5 = &ControllerFD94_D_8006763C;
                value3 = *limitAddress5;
                limitValue4 = ControllerFD94_D_80067644;
                if (limitValue4 < value3) {
                    value2 = value3 - 16;
                    *limitAddress5 = value2;
                }
                value3 = ControllerFD94_D_80067640;
                if (limitValue4 < value3) {
                    value2 = value3 - 16;
                    MATCHING_OBSERVE(limitValue4);
                    ControllerFD94_D_80067640 = value2;
                }
            }
            break;
        case 1:
            MATCHING_KEEP(state3);
            SpawnMoby(0x165, moby);
            __asm__("" : "=r"(inherited21));
            if (inherited21 && M2C_FIELD(privateData, int*, 0x28))
                inherited21[0x49] = 1;
            func_8003BABC(moby, 1, 0);
            ControllerFD94RefreshMobySpatialGridAndBasis(moby, 4);
            M2C_FIELD(privateData, int*, 12) = 30;
            moby->animationState.id = 1;
            moby->animationState.nextId = 3;
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = 0;
            value2 = M2C_FIELD(privateData, int*, 0x10);
            value3 = 2;
            moby->state = value3;
            moby->animationProgress = value2 >> 3;
            M2C_FIELD(privateData, int*, 0x28) = 0;
            break;
        case 2:
            moby->animationState.id = 1;
            moby->animationState.nextId = 3;
            frameByte2 = moby->animationState.frame + 1;
            moby->animationState.frame = frameByte2;
            if ((unsigned int)(frameByte2 & 255) >= 14U) {
                moby->animationState.frame = 14;
                moby->state = 0;
            }
            moby->animationState.nextFrame = moby->animationState.frame;
            moby->animationProgress = M2C_FIELD(privateData, int*, 0x10) >> 3;
            break;
    }
    if (M2C_FIELD(privateData, int*, 0x20) != -1) {
        value3 = func_8003613C(moby->angle.yaw, M2C_FIELD(privateData, int*, 0x20));
        if (value3 > 3)
            value3 = 3;
        if (value3 < -3)
            value3 = -3;
        moby->angle.yaw += value3;
    }
    if (M2C_FIELD(privateData, int*, 0x24) != -1) {
        previousValue18 = M2C_FIELD(privateData, int*, 0x10);
        value3 = func_8003613C(previousValue18, M2C_FIELD(privateData, int*, 0x24));
        if (value3 > 4)
            value3 = 4;
        if (value3 < -4)
            value3 = -4;
        value2 = M2C_FIELD(privateData, int*, 0x10) + value3;
        M2C_FIELD(privateData, int*, 0x10) = value2;
        if (value2 < 0)
            M2C_FIELD(privateData, int*, 0x10) = 0;
        if (M2C_FIELD(privateData, int*, 0x10) > 120)
            M2C_FIELD(privateData, int*, 0x10) = 120;
        value2 = -8;
        value3 = M2C_FIELD(privateData, int*, 0x10);
        firstBitCount4 = previousValue18 & value2;
        value3 &= value2;
        if (firstBitCount4 != value3) {
            if (func_8003BFC0(moby, M2C_FIELD(privateData, int*, 0x14)))
                func_8003BE70(M2C_FIELD(privateData, int*, 0x14));
            M2C_FIELD(privateData, int*, 0x14) = func_8003BABC(moby, 0, 0);
        }
    }
    if (M2C_FIELD(privateData, int*, 0x28) && moby->state != 1)
        moby->state = 1;
    M2C_FIELD(privateData, int*, 0x20) = -1;
    M2C_FIELD(privateData, int*, 0x24) = -1;
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80080660.
 * AI generated; not human reviewed. All656 native words and actual targets
 * must match. This function owns no selector, padding or packed data words.
 * FrameE0 (224 bytes) saves S0..S7/FP/RA at SPB8..DC. The explicit local
 * frame occupies SP18..B7; unwritten reserve contents are never read.
 * SP18 is the copied vector; SP28/38/48 hold original vector words. SP58
 * contains three angle bytes; SP60..70 is the matrix output from4EA90.
 * Original4EAA8 retains destination A1 in T7;4ECDC writes its entire first
 * word. The empty phase identity consumes that initialized SP60 word after
 * the call, preserving original instruction lifetime without a padding read.
 * Natural FP retains the row phase; no fixed FP/SP or live GP aliases.
 * Every MULT has complete signed64 inputs from original signed32 operands.
 * Distinct whole high/low captures narrow before original signed shifts.
 * /10 uses66666667 high then SRA2 and sign correction; /5 uses SRA1.
 * Fade byte products are0..65025; /20 uses high then SRA3 as on disc.
 * Raw vectors:32767*250=8191750,SRA12=1999;230/10=23;255*255=65025.
 * Numeric physical units and fixed-point domains remain open. SIN words
 * retain original signed LH width and original signed SRA12 consumers.
 * States0/1/2 precede the common phase. Original history10,geometry10x5,
 * color10 and topology9x5 loops retain widths,literals,helpers and order.
 * Empty metadata consumes complete initialized values/addresses or written
 * fields,or clobbers dead registers before fresh producers;zero CPU words.
 * All actual transfers/data targets and full EXE/every-overlay retail hashes
 * are mandatory. Compiler,filter and flags remain unchanged.
 * Confidence is binary identity after every gate. Complete helper/caller
 * chains,physical units,cadence beyond invocation,Rev1 mapping and retail
 * runtime verification remain open. Next:human review and capture evidence.
 */
/* Original assembly SHA256 b887ff40e75e1a68a462ab165bc7fe64418d169e34b5ff7c800f9f2717ebc586 */
#define Level21_80660Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level21_80660MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level21_80660CaptureHigh(dst)                                       \
    do {                                                                    \
        int wholeCapturedHigh;                                              \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedHigh;                                          \
        Level21_80660Keep(dst);                                             \
    } while (0)
#define Level21_80660CaptureLow(dst)                                       \
    do {                                                                   \
        int wholeCapturedLow;                                              \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedLow;                                          \
        Level21_80660Keep(dst);                                            \
    } while (0)
#define Level21_80660Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level21_80660Call1830CView1() __asm__("func_8001830C");
int Level21_80660Call19138View1() __asm__("func_80019138");
int Level21_80660Call1BA30View1() __asm__("func_8001BA30");
int Level21_80660CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level21_80660PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
int Level21_80660Call40954View1(int) __asm__("func_80040954");
int Level21_80660PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level21_80660BuildPackedAngleBasisMatrixView1(void*, void*, int) __asm__("func_8004EA90");
void Level21_80660TransformVectorByBasisView1(void*, void*, void*) __asm__("func_8004ED6C");
int Level21_80660MeasureVectorLengthView1(void*, int) __asm__("func_8004EDE8");
void Level21_80660CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level21_80660AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level21_80660SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level21_80660AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
void* Level21_80660Call50844View1(void*, int, int, int) __asm__("func_80050844");
void* Level21_80660Call50B00View1(int, int, int, int, int) __asm__("func_80050B00");
void Level21_80660Call50B88View1(void*) __asm__("func_80050B88");
void Level21_80660DeleteMobyView1(void*) __asm__("func_80055B18");
void Level21_80660RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
int Level21_80660DatarandView1(void) __asm__("rand");
extern unsigned char Level21_80660Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level21_80660Data65920View1[] __asm__("D_80065920");
extern int Level21_80660Data6C648View1 __asm__("D_8006C648");
extern unsigned char Level21_80660Data6D048View1[] __asm__("D_8006D048");
extern unsigned char Level21_80660Data6EE2CView1[] __asm__("D_8006EE2C");
extern int Level21_80660Data71924View1 __asm__("D_80071924");
extern int (*Level21_80660DataSpawnMobyView1)() __asm__("SpawnMoby");
void func_level_21_80080660(unsigned char* ownerParameter) {
    register int resultOrField2 __asm__("$2"), fieldOrCapturedHigh3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7");
    register int topologyRowBase8 __asm__("$8"), topologyRowOffset9 __asm__("$9"),
        topologyNextRow10 __asm__("$10"), topologyDivisionMagic11 __asm__("$11"),
        privateOrCapturedWord12 __asm__("$12");
    long long completeSignedProduct;
    register unsigned char* ownerRecord21 __asm__("$21");
    register int createdRecordOrInnerCount16 __asm__("$16"),
        positionOrPrivateOrRow17 __asm__("$17"), eventOffsetOrRingIndex18 __asm__("$18"),
        eventCountOrRadius19 __asm__("$19"), descriptorOrRingRecord20 __asm__("$20"),
        literalTwoOrVectorAddress22 __asm__("$22"), signedDivisionMagic23 __asm__("$23");
    int retainedRowPhase;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84,
            sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4;
    } originalFrame;
    ownerRecord21 = ownerParameter;
    Level21_80660Keep(ownerRecord21);
    fieldOrCapturedHigh3 = Level21_80660Field(ownerRecord21, unsigned char*, 0x48);
    privateOrCapturedWord12 = Level21_80660Field(ownerRecord21, int*, 0);
    resultOrField2 = 1;
    originalFrame.sp78 = privateOrCapturedWord12;
    if (fieldOrCapturedHigh3 == resultOrField2)
        goto updateOriginalStateOne;
    if (fieldOrCapturedHigh3 >= 2)
        goto dispatchOriginalOtherState;
    argumentOrField4 = (int)&originalFrame.sp18;
    if (!fieldOrCapturedHigh3)
        goto updateOriginalStateZero;
    goto renderOriginalCommonPhase;
dispatchOriginalOtherState:
    resultOrField2 = 2;
    if (fieldOrCapturedHigh3 == resultOrField2)
        goto updateOriginalStateTwo;
    goto renderOriginalCommonPhase;
updateOriginalStateZero:
    positionOrPrivateOrRow17 = (int)ownerRecord21 + 12;
    Level21_80660CopyVectorView1(argumentOrField4, positionOrPrivateOrRow17);
    privateOrCapturedWord12 = originalFrame.sp78;
    resultOrField2 = Level21_80660Field(ownerRecord21, int*, 12);
    fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, short*, 0);
    resultOrField2 += fieldOrCapturedHigh3;
    Level21_80660Field(ownerRecord21, int*, 12) = resultOrField2;
    fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, short*, 2);
    resultOrField2 = Level21_80660Field(ownerRecord21, int*, 16);
    resultOrField2 += fieldOrCapturedHigh3;
    Level21_80660Field(ownerRecord21, int*, 16) = resultOrField2;
    fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, short*, 4);
    resultOrField2 = Level21_80660Field(ownerRecord21, int*, 20);
    argumentOrField6 = Level21_80660Field(ownerRecord21, int*, 12);
    argumentOrField4 = resultOrField2 + fieldOrCapturedHigh3;
    resultOrField2 = argumentOrField6 < 4000;
    Level21_80660Field(ownerRecord21, int*, 20) = argumentOrField4;
    if (resultOrField2)
        goto deleteOriginalOwner;
    argumentOrField5 = Level21_80660Field(ownerRecord21, int*, 16);
    if (argumentOrField5 < 4000)
        goto deleteOriginalOwner;
    if (argumentOrField4 < 3500)
        goto deleteOriginalOwner;
    fieldOrCapturedHigh3 = 0x3D400;
    resultOrField2 = fieldOrCapturedHigh3 < argumentOrField6;
    Level21_80660Keep(resultOrField2);
    if (resultOrField2)
        goto deleteOriginalOwner;
    resultOrField2 = fieldOrCapturedHigh3 < argumentOrField5;
    Level21_80660Keep(resultOrField2);
    if (resultOrField2)
        goto deleteOriginalOwner;
    resultOrField2 = 122880;
    if (argumentOrField4 > resultOrField2)
        goto deleteOriginalOwner;
    argumentOrField4 = positionOrPrivateOrRow17;
    argumentOrField5 = 512;
    argumentOrField6 = 1;
    argumentOrField7 = 0;
    resultOrField2 =
        Level21_80660Call1BA30View1(argumentOrField4, argumentOrField5, argumentOrField6,
                                    argumentOrField7, 0x10170000, ownerRecord21);
    createdRecordOrInnerCount16 = resultOrField2;
    Level21_80660Keep(createdRecordOrInnerCount16);
    if (createdRecordOrInnerCount16) {
        privateOrCapturedWord12 = originalFrame.sp78;
        Level21_80660Keep(privateOrCapturedWord12);
        argumentOrField4 = Level21_80660Field(privateOrCapturedWord12, short*, 0);
        argumentOrField5 = Level21_80660Field(privateOrCapturedWord12, short*, 2);
        argumentOrField6 = 0;
        resultOrField2 = Level21_80660PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x51) = resultOrField2;
    }
    privateOrCapturedWord12 = originalFrame.sp78;
    resultOrField2 = Level21_80660Data6C648View1;
    fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8);
    fieldOrCapturedHigh3 += resultOrField2;
    Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8) = fieldOrCapturedHigh3;
    fieldOrCapturedHigh3 &= 255;
    if ((unsigned int)fieldOrCapturedHigh3 < 3U)
        goto originalAngleByte;
    resultOrField2 = (unsigned int)fieldOrCapturedHigh3 < 111U;
    Level21_80660Keep(resultOrField2);
    if (!resultOrField2)
        goto originalStateOneStore;
    if (createdRecordOrInnerCount16)
        goto originalStateOneStore;
    Level21_80660Keep(createdRecordOrInnerCount16);
    argumentOrField4 = (int)&originalFrame.sp18;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField4, "$5");
    argumentOrField5 = positionOrPrivateOrRow17;
    argumentOrField6 = 0;
    resultOrField2 = Level21_80660Field(privateOrCapturedWord12, int*, 20);
    argumentOrField7 = 0;
    resultOrField2 = Level21_80660Call1830CView1(
        argumentOrField4, argumentOrField5, argumentOrField6, argumentOrField7, resultOrField2);
    if (resultOrField2)
        goto originalStateOneStore;
    Level21_80660Keep(resultOrField2);
    argumentOrField4 = positionOrPrivateOrRow17;
    argumentOrField5 = 128;
    privateOrCapturedWord12 = originalFrame.sp78;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(privateOrCapturedWord12, "$6");
    argumentOrField6 = 0;
    Level21_80660Keep(argumentOrField6);
    argumentOrField7 = 0;
    resultOrField2 = Level21_80660Call19138View1(
        argumentOrField4, argumentOrField5, argumentOrField6, argumentOrField7, 0,
        Level21_80660Field(privateOrCapturedWord12, int*, 20));
    if (!resultOrField2)
        goto originalAngleByte;
originalStateOneStore:
    resultOrField2 = 1;
    Level21_80660Field(ownerRecord21, unsigned char*, 0x48) = resultOrField2;
    createdRecordOrInnerCount16 = (int)&Level21_80660Data71924View1;
    Level21_80660Keep(createdRecordOrInnerCount16);
    argumentOrField4 = Level21_80660Field(createdRecordOrInnerCount16, int*, 0);
    resultOrField2 = Level21_80660Call40954View1(argumentOrField4);
    fieldOrCapturedHigh3 = 3;
    if (resultOrField2 != fieldOrCapturedHigh3)
        goto originalAngleByte;
    resultOrField2 = Level21_80660Field(ownerRecord21, unsigned char*, 0x49);
    if (resultOrField2)
        goto originalClearStateZero;
    resultOrField2 = Level21_80660Field(createdRecordOrInnerCount16, int*, 0);
    fieldOrCapturedHigh3 = Level21_80660Field(&Level21_80660Data6D048View1, int*, 20);
    resultOrField2 = (resultOrField2 & 63) * 4;
    resultOrField2 += fieldOrCapturedHigh3;
    fieldOrCapturedHigh3 = Level21_80660Field(resultOrField2, int*, 0);
    resultOrField2 = Level21_80660Field(fieldOrCapturedHigh3, int*, 4);
    resultOrField2 |= 1;
    Level21_80660Field(fieldOrCapturedHigh3, int*, 4) = resultOrField2;
    goto originalAngleByte;
originalClearStateZero:
    Level21_80660Field(ownerRecord21, unsigned char*, 0x48) = 0;
originalAngleByte:
    privateOrCapturedWord12 = originalFrame.sp78;
    resultOrField2 = Level21_80660Field(ownerRecord21, unsigned char*, 0x44);
    fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 9);
    resultOrField2 += fieldOrCapturedHigh3;
    Level21_80660Field(ownerRecord21, unsigned char*, 0x44) = resultOrField2;
    goto renderOriginalCommonPhase;
updateOriginalStateOne:
    MATCHING_BARRIER_VOLATILE("$12");
    resultOrField2 = Level21_80660Field(ownerRecord21, int*, 12);
    argumentOrField4 = (int)ownerRecord21;
    if (resultOrField2 < 5501)
        goto originalStateOneEnd;
    resultOrField2 = Level21_80660Field(ownerRecord21, int*, 16);
    argumentOrField5 = 0;
    if (resultOrField2 < 5501)
        goto originalStateOneEndCall;
    resultOrField2 = Level21_80660Field(ownerRecord21, int*, 20);
    if (resultOrField2 < 5501)
        goto originalStateOneEndCall;
    privateOrCapturedWord12 = originalFrame.sp78;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(privateOrCapturedWord12, "$19");
    eventCountOrRadius19 = 0;
    Level21_80660Keep(eventCountOrRadius19);
    resultOrField2 = Level21_80660Field(privateOrCapturedWord12, int*, 20);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(resultOrField2, "$22");
    literalTwoOrVectorAddress22 = 2;
    descriptorOrRingRecord20 = Level21_80660Field(resultOrField2, int*, 0);
    __asm__(""
            : "=r"(eventCountOrRadius19)
            : "0"(eventCountOrRadius19), "r"(descriptorOrRingRecord20));
    eventOffsetOrRingIndex18 = eventCountOrRadius19 << 1;
    do {
        resultOrField2 = Level21_80660Field(descriptorOrRingRecord20, int*, 56);
        argumentOrField5 = Level21_80660Field(ownerRecord21, unsigned char*, 0x46);
        resultOrField2 = eventOffsetOrRingIndex18 + resultOrField2;
        argumentOrField4 = Level21_80660Field(resultOrField2, unsigned char*, 0);
        resultOrField2 =
            Level21_80660AbsoluteByteAngleDeltaView1(argumentOrField4, argumentOrField5);
        argumentOrField4 = 361;
        if (resultOrField2 >= 60)
            goto originalNextCreated;
        resultOrField2 = Level21_80660DataSpawnMobyView1(argumentOrField4, ownerRecord21);
        createdRecordOrInnerCount16 = resultOrField2;
        Level21_80660Keep(createdRecordOrInnerCount16);
        if (!createdRecordOrInnerCount16)
            goto originalNextCreated;
        resultOrField2 = Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x3C);
        positionOrPrivateOrRow17 = Level21_80660Field(createdRecordOrInnerCount16, int*, 0);
        fieldOrCapturedHigh3 = 1;
        if (resultOrField2 != literalTwoOrVectorAddress22) {
            resultOrField2 = Level21_80660Field(createdRecordOrInnerCount16, short*, 0x36);
            Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x42) = 0;
            resultOrField2 *= 4;
            resultOrField2 = Level21_80660Field(&Level21_80660Data6EE2CView1, int*, resultOrField2);
            resultOrField2 = Level21_80660Field(resultOrField2, int*, 0x44);
            resultOrField2 = Level21_80660Field(resultOrField2, unsigned char*, 0);
            Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x3C) =
                literalTwoOrVectorAddress22;
            Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x3D) =
                literalTwoOrVectorAddress22;
            Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x3E) = 0;
            Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x3F) =
                fieldOrCapturedHigh3;
            resultOrField2 = ((unsigned int)resultOrField2 < 2U) ^ 1;
            resultOrField2 = -resultOrField2;
            resultOrField2 &= 48;
            Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x40) = resultOrField2;
        }
        argumentOrField4 = createdRecordOrInnerCount16 + 12;
        argumentOrField5 = 7;
        argumentOrField6 = 10;
        argumentOrField7 = 0x40E080;
        resultOrField2 = Level21_80660Call50844View1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6, argumentOrField7);
        Level21_80660Field(positionOrPrivateOrRow17, int*, 8) = resultOrField2;
        resultOrField2 = Level21_80660Field(descriptorOrRingRecord20, int*, 56);
        resultOrField2 = eventOffsetOrRingIndex18 + resultOrField2;
        resultOrField2 = Level21_80660Field(resultOrField2, unsigned char*, 0);
        Level21_80660Keep(resultOrField2);
        resultOrField2 += 128;
        Level21_80660Field(positionOrPrivateOrRow17, unsigned char*, 1) = resultOrField2;
        resultOrField2 = Level21_80660Field(descriptorOrRingRecord20, int*, 56);
        resultOrField2 = eventOffsetOrRingIndex18 + resultOrField2;
        fieldOrCapturedHigh3 = Level21_80660Field(resultOrField2, unsigned char*, 1);
        resultOrField2 = 50;
        Level21_80660Field(positionOrPrivateOrRow17, int*, 4) = resultOrField2;
        resultOrField2 = 300;
        Level21_80660Field(positionOrPrivateOrRow17, short*, 2) = resultOrField2;
        Level21_80660Field(positionOrPrivateOrRow17, unsigned char*, 0) = fieldOrCapturedHigh3;
        resultOrField2 = Level21_80660DatarandView1();
        Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x44) = resultOrField2;
        Level21_80660Field(createdRecordOrInnerCount16, unsigned char*, 0x48) =
            literalTwoOrVectorAddress22;
    originalNextCreated:
        eventCountOrRadius19++;
        eventOffsetOrRingIndex18 = eventCountOrRadius19 << 1;
    } while (eventCountOrRadius19 < 32);
    argumentOrField4 = (int)ownerRecord21;
originalStateOneEnd:
    argumentOrField5 = 0;
originalStateOneEndCall:
    Level21_80660PlayMobySoundEventView1(argumentOrField4, argumentOrField5, 0);
    Level21_80660Field(ownerRecord21, unsigned char*, 0x41) = 0;
    Level21_80660Field(ownerRecord21, unsigned char*, 0x4C) = 0;
    Level21_80660Field(ownerRecord21, unsigned char*, 0x4D) = 0;
    privateOrCapturedWord12 = originalFrame.sp78;
    resultOrField2 = 20;
    Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8) = resultOrField2;
    resultOrField2 = 2;
    Level21_80660Field(ownerRecord21, unsigned char*, 0x48) = resultOrField2;
updateOriginalStateTwo:
    privateOrCapturedWord12 = originalFrame.sp78;
    argumentOrField5 = 1;
    argumentOrField4 = privateOrCapturedWord12 + 8;
    resultOrField2 = Level21_80660CountTimerDownView1(argumentOrField4, argumentOrField5);
    if (!resultOrField2)
        goto renderOriginalCommonPhase;
deleteOriginalOwner:
    privateOrCapturedWord12 = originalFrame.sp78;
    Level21_80660Keep(privateOrCapturedWord12);
    argumentOrField4 = Level21_80660Field(privateOrCapturedWord12, int*, 16);
    if (argumentOrField4)
        Level21_80660Call50B88View1(argumentOrField4);
    Level21_80660DeleteMobyView1(ownerRecord21);
    goto originalRenderDone;
renderOriginalCommonPhase:
    privateOrCapturedWord12 = originalFrame.sp78;
    Level21_80660Keep(privateOrCapturedWord12);
    resultOrField2 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8);
    if ((unsigned int)resultOrField2 >= 80U)
        goto originalDisposeRender;
    argumentOrField4 = (int)ownerRecord21;
    argumentOrField5 = 4;
    descriptorOrRingRecord20 = Level21_80660Field(privateOrCapturedWord12, int*, 12);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(descriptorOrRingRecord20, "$2");
    resultOrField2 = -100;
    originalFrame.sp28 = resultOrField2;
    originalFrame.sp2C = 0;
    originalFrame.sp30 = 0;
    Level21_80660RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
    argumentOrField4 = (int)ownerRecord21 + 32;
    createdRecordOrInnerCount16 = (int)&originalFrame.sp28;
    argumentOrField5 = createdRecordOrInnerCount16;
    argumentOrField6 = createdRecordOrInnerCount16;
    Level21_80660TransformVectorByBasisView1(argumentOrField4, argumentOrField5, argumentOrField6);
    Level21_80660AddVectorView1(createdRecordOrInnerCount16, createdRecordOrInnerCount16,
                                (int)ownerRecord21 + 12);
    resultOrField2 = Level21_80660Field(descriptorOrRingRecord20, short*, 0);
    argumentOrField5 = createdRecordOrInnerCount16;
    argumentOrField4 = resultOrField2 * 12;
    argumentOrField4 += 4;
    argumentOrField4 = descriptorOrRingRecord20 + argumentOrField4;
    Level21_80660CopyVectorView1(argumentOrField4, argumentOrField5);
    resultOrField2 = 0x66666667;
    argumentOrField5 = Level21_80660Field(descriptorOrRingRecord20, short*, 0);
    argumentOrField5++;
    Level21_80660Keep(argumentOrField5);
    Level21_80660MultiplyComplete(argumentOrField5, resultOrField2);
    argumentOrField4 = Level21_80660Field(descriptorOrRingRecord20, unsigned short*, 2);
    Level21_80660Keep(argumentOrField4);
    argumentOrField4++;
    resultOrField2 = argumentOrField5 >> 31;
    Level21_80660Field(descriptorOrRingRecord20, short*, 2) = argumentOrField4;
    argumentOrField4 = (short)argumentOrField4;
    argumentOrField4 = argumentOrField4 < 11;
    Level21_80660CaptureHigh(privateOrCapturedWord12);
    fieldOrCapturedHigh3 = privateOrCapturedWord12 >> 2;
    fieldOrCapturedHigh3 -= resultOrField2;
    resultOrField2 = fieldOrCapturedHigh3 * 10;
    argumentOrField5 -= resultOrField2;
    privateOrCapturedWord12 = descriptorOrRingRecord20 + 124;
    Level21_80660Field(descriptorOrRingRecord20, short*, 0) = argumentOrField5;
    originalFrame.sp80 = privateOrCapturedWord12;
    privateOrCapturedWord12 = descriptorOrRingRecord20 + 728;
    originalFrame.sp88 = privateOrCapturedWord12;
    privateOrCapturedWord12 = descriptorOrRingRecord20 + 772;
    originalFrame.sp90 = privateOrCapturedWord12;
    if (!argumentOrField4) {
        resultOrField2 = 10;
        Level21_80660Field(descriptorOrRingRecord20, short*, 2) = resultOrField2;
    }
    positionOrPrivateOrRow17 = 0;
    signedDivisionMagic23 = 0x66666667;
    Level21_80660Keep(signedDivisionMagic23);
    privateOrCapturedWord12 = (int)&originalFrame.sp48;
    originalFrame.sp98 = privateOrCapturedWord12;
    literalTwoOrVectorAddress22 = (int)&originalFrame.sp38;
    retainedRowPhase = 0;
    do {
        argumentOrField4 = Level21_80660Field(descriptorOrRingRecord20, short*, 0);
        Level21_80660Keep(argumentOrField4);
        argumentOrField4 -= positionOrPrivateOrRow17;
        argumentOrField5 = argumentOrField4 + 19;
        Level21_80660MultiplyComplete(argumentOrField5, signedDivisionMagic23);
        Level21_80660CaptureHigh(fieldOrCapturedHigh3);
        argumentOrField4 += 18;
        Level21_80660Keep(argumentOrField4);
        Level21_80660MultiplyComplete(argumentOrField4, signedDivisionMagic23);
        resultOrField2 = argumentOrField5 >> 31;
        fieldOrCapturedHigh3 >>= 2;
        eventOffsetOrRingIndex18 = fieldOrCapturedHigh3 - resultOrField2;
        Level21_80660Keep(eventOffsetOrRingIndex18);
        resultOrField2 = eventOffsetOrRingIndex18 * 10;
        eventOffsetOrRingIndex18 = argumentOrField5 - resultOrField2;
        resultOrField2 = argumentOrField4 >> 31;
        argumentOrField5 = Level21_80660Field(descriptorOrRingRecord20, short*, 2);
        Level21_80660CaptureHigh(argumentOrField6);
        fieldOrCapturedHigh3 = argumentOrField6 >> 2;
        fieldOrCapturedHigh3 -= resultOrField2;
        resultOrField2 = fieldOrCapturedHigh3 * 10;
        fieldOrCapturedHigh3 = argumentOrField4 - resultOrField2;
        if (argumentOrField5 < 10) {
            resultOrField2 = argumentOrField5 - 1;
            resultOrField2 = resultOrField2 < positionOrPrivateOrRow17;
            fieldOrCapturedHigh3 = 0;
            if (resultOrField2)
                eventOffsetOrRingIndex18 = 0;
        }
        argumentOrField5 = eventOffsetOrRingIndex18 * 12;
        argumentOrField5 += 4;
        argumentOrField5 = descriptorOrRingRecord20 + argumentOrField5;
        argumentOrField6 = fieldOrCapturedHigh3 * 12;
        argumentOrField6 += 4;
        argumentOrField4 = originalFrame.sp98;
        Level21_80660SubtractVectorView1(argumentOrField4, argumentOrField5,
                                         descriptorOrRingRecord20 + argumentOrField6);
        argumentOrField4 = originalFrame.sp98;
        argumentOrField5 = 0;
        Level21_80660Field(&originalFrame.sp58, unsigned char*, 0) = 0;
        resultOrField2 = Level21_80660MeasureVectorLengthView1(argumentOrField4, argumentOrField5);
        argumentOrField4 = resultOrField2;
        argumentOrField5 = originalFrame.sp50;
        argumentOrField6 = 0;
        resultOrField2 = Level21_80660PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        argumentOrField4 = originalFrame.sp48;
        argumentOrField5 = originalFrame.sp4C;
        argumentOrField6 = 0;
        Level21_80660Field(&originalFrame.sp58, unsigned char*, 1) = resultOrField2;
        resultOrField2 = Level21_80660PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        argumentOrField4 = (int)&originalFrame.sp58;
        argumentOrField5 = (int)&originalFrame.sp60;
        argumentOrField6 = 0;
        Level21_80660Field(&originalFrame.sp58, unsigned char*, 2) = resultOrField2;
        Level21_80660BuildPackedAngleBasisMatrixView1(argumentOrField4, argumentOrField5,
                                                      argumentOrField6);
        __asm__("" : "=r"(retainedRowPhase) : "0"(retainedRowPhase), "m"(originalFrame.sp60));
        Level21_80660MultiplyComplete(retainedRowPhase, signedDivisionMagic23);
        createdRecordOrInnerCount16 = 0;
        Level21_80660Keep(createdRecordOrInnerCount16);
        fieldOrCapturedHigh3 = retainedRowPhase >> 31;
        Level21_80660CaptureHigh(privateOrCapturedWord12);
        resultOrField2 = privateOrCapturedWord12 >> 2;
        resultOrField2 -= fieldOrCapturedHigh3;
        eventCountOrRadius19 = resultOrField2 + 250;
        resultOrField2 = createdRecordOrInnerCount16 << 8;
        do {
            Level21_80660MultiplyComplete(resultOrField2, signedDivisionMagic23);
            resultOrField2 >>= 31;
            originalFrame.sp38 = 0;
            Level21_80660CaptureHigh(privateOrCapturedWord12);
            fieldOrCapturedHigh3 = privateOrCapturedWord12 >> 1;
            fieldOrCapturedHigh3 -= resultOrField2;
            Level21_80660Keep(fieldOrCapturedHigh3);
            fieldOrCapturedHigh3 *= 2;
            resultOrField2 =
                Level21_80660Field(&Level21_80660Data65920View1, short*, fieldOrCapturedHigh3);
            Level21_80660Keep(resultOrField2);
            Level21_80660MultiplyComplete(resultOrField2, eventCountOrRadius19);
            Level21_80660CaptureLow(privateOrCapturedWord12);
            resultOrField2 = privateOrCapturedWord12 >> 12;
            originalFrame.sp3C = resultOrField2;
            resultOrField2 =
                Level21_80660Field(&Level21_80660Data658A0View1, short*, fieldOrCapturedHigh3);
            Level21_80660Keep(resultOrField2);
            Level21_80660MultiplyComplete(resultOrField2, eventCountOrRadius19);
            argumentOrField4 = (int)ownerRecord21 + 32;
            argumentOrField5 = literalTwoOrVectorAddress22;
            argumentOrField6 = literalTwoOrVectorAddress22;
            Level21_80660CaptureLow(privateOrCapturedWord12);
            resultOrField2 = privateOrCapturedWord12 >> 12;
            originalFrame.sp40 = resultOrField2;
            Level21_80660TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = positionOrPrivateOrRow17 * 5;
            resultOrField2 += createdRecordOrInnerCount16;
            argumentOrField4 = resultOrField2 * 12;
            argumentOrField5 = eventOffsetOrRingIndex18 * 12;
            argumentOrField5 += 4;
            argumentOrField5 = descriptorOrRingRecord20 + argumentOrField5;
            privateOrCapturedWord12 = originalFrame.sp80;
            argumentOrField6 = literalTwoOrVectorAddress22;
            argumentOrField4 = privateOrCapturedWord12 + argumentOrField4;
            Level21_80660AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            createdRecordOrInnerCount16++;
            resultOrField2 = createdRecordOrInnerCount16 < 5;
        } while (resultOrField2 && (resultOrField2 = createdRecordOrInnerCount16 << 8, 1));
        positionOrPrivateOrRow17++;
        retainedRowPhase -= 230;
    } while (positionOrPrivateOrRow17 < 10);
    createdRecordOrInnerCount16 = 1;
    argumentOrField7 = 9;
    argumentOrField6 = 0x66660000;
    privateOrCapturedWord12 = originalFrame.sp88;
    __asm__("" : "=r"(argumentOrField6) : "0"(argumentOrField6), "r"(privateOrCapturedWord12));
    argumentOrField6 |= 0x6667;
    argumentOrField5 = privateOrCapturedWord12 + 4;
    privateOrCapturedWord12 = originalFrame.sp80;
    resultOrField2 = -1;
    Level21_80660Field(privateOrCapturedWord12, int*, 600) = resultOrField2;
    privateOrCapturedWord12 = originalFrame.sp88;
    resultOrField2 = 80;
    Level21_80660Field(privateOrCapturedWord12, unsigned char*, 0) = resultOrField2;
    resultOrField2 = 140;
    Level21_80660Field(privateOrCapturedWord12, unsigned char*, 1) = resultOrField2;
    resultOrField2 = 40;
    Level21_80660Field(privateOrCapturedWord12, unsigned char*, 2) = resultOrField2;
    do {
        privateOrCapturedWord12 = originalFrame.sp88;
        Level21_80660Keep(privateOrCapturedWord12);
        fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 0);
        MATCHING_OBSERVE_VOLATILE_CLOBBER(fieldOrCapturedHigh3, "$4");
        argumentOrField4 = argumentOrField7 - createdRecordOrInnerCount16;
        Level21_80660Keep(fieldOrCapturedHigh3);
        Level21_80660MultiplyComplete(fieldOrCapturedHigh3, argumentOrField4);
        Level21_80660CaptureLow(fieldOrCapturedHigh3);
        Level21_80660MultiplyComplete(fieldOrCapturedHigh3, argumentOrField6);
        fieldOrCapturedHigh3 >>= 31;
        Level21_80660CaptureHigh(privateOrCapturedWord12);
        resultOrField2 = privateOrCapturedWord12 >> 2;
        resultOrField2 -= fieldOrCapturedHigh3;
        Level21_80660Field(argumentOrField5, unsigned char*, 0) = resultOrField2;
        privateOrCapturedWord12 = originalFrame.sp88;
        Level21_80660Keep(privateOrCapturedWord12);
        resultOrField2 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 1);
        Level21_80660Keep(resultOrField2);
        Level21_80660MultiplyComplete(resultOrField2, argumentOrField4);
        Level21_80660CaptureLow(resultOrField2);
        Level21_80660MultiplyComplete(resultOrField2, argumentOrField6);
        resultOrField2 >>= 31;
        Level21_80660CaptureHigh(privateOrCapturedWord12);
        fieldOrCapturedHigh3 = privateOrCapturedWord12 >> 2;
        fieldOrCapturedHigh3 -= resultOrField2;
        Level21_80660Field(argumentOrField5, unsigned char*, 1) = fieldOrCapturedHigh3;
        privateOrCapturedWord12 = originalFrame.sp88;
        Level21_80660Keep(privateOrCapturedWord12);
        fieldOrCapturedHigh3 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 2);
        Level21_80660Keep(fieldOrCapturedHigh3);
        Level21_80660MultiplyComplete(fieldOrCapturedHigh3, argumentOrField4);
        Level21_80660CaptureLow(fieldOrCapturedHigh3);
        Level21_80660MultiplyComplete(fieldOrCapturedHigh3, argumentOrField6);
        createdRecordOrInnerCount16++;
        __asm__(""
                : "=r"(fieldOrCapturedHigh3)
                : "0"(fieldOrCapturedHigh3), "r"(createdRecordOrInnerCount16));
        fieldOrCapturedHigh3 >>= 31;
        Level21_80660CaptureHigh(privateOrCapturedWord12);
        resultOrField2 = privateOrCapturedWord12 >> 2;
        resultOrField2 -= fieldOrCapturedHigh3;
        Level21_80660Field(argumentOrField5, unsigned char*, 2) = resultOrField2;
        argumentOrField5 += 4;
    } while (createdRecordOrInnerCount16 < 10);
    createdRecordOrInnerCount16 = 0;
    fieldOrCapturedHigh3 = Level21_80660Field(ownerRecord21, unsigned char*, 0x48);
    resultOrField2 = 2;
    if (fieldOrCapturedHigh3 == resultOrField2) {
        argumentOrField5 = 0x66666667;
        Level21_80660Keep(argumentOrField5);
        argumentOrField4 = originalFrame.sp88;
        do {
            privateOrCapturedWord12 = originalFrame.sp78;
            fieldOrCapturedHigh3 = Level21_80660Field(argumentOrField4, unsigned char*, 0);
            resultOrField2 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8);
            Level21_80660Keep(resultOrField2);
            Level21_80660Keep(fieldOrCapturedHigh3);
            Level21_80660MultiplyComplete(fieldOrCapturedHigh3, resultOrField2);
            Level21_80660CaptureLow(resultOrField2);
            Level21_80660MultiplyComplete(resultOrField2, argumentOrField5);
            Level21_80660CaptureHigh(privateOrCapturedWord12);
            resultOrField2 = privateOrCapturedWord12 >> 3;
            Level21_80660Field(argumentOrField4, unsigned char*, 0) = resultOrField2;
            privateOrCapturedWord12 = originalFrame.sp78;
            fieldOrCapturedHigh3 = Level21_80660Field(argumentOrField4, unsigned char*, 1);
            resultOrField2 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8);
            Level21_80660Keep(resultOrField2);
            Level21_80660Keep(fieldOrCapturedHigh3);
            Level21_80660MultiplyComplete(fieldOrCapturedHigh3, resultOrField2);
            Level21_80660CaptureLow(resultOrField2);
            Level21_80660MultiplyComplete(resultOrField2, argumentOrField5);
            Level21_80660CaptureHigh(privateOrCapturedWord12);
            resultOrField2 = privateOrCapturedWord12 >> 3;
            Level21_80660Field(argumentOrField4, unsigned char*, 1) = resultOrField2;
            privateOrCapturedWord12 = originalFrame.sp78;
            fieldOrCapturedHigh3 = Level21_80660Field(argumentOrField4, unsigned char*, 2);
            resultOrField2 = Level21_80660Field(privateOrCapturedWord12, unsigned char*, 8);
            Level21_80660Keep(resultOrField2);
            Level21_80660Keep(fieldOrCapturedHigh3);
            Level21_80660MultiplyComplete(fieldOrCapturedHigh3, resultOrField2);
            Level21_80660CaptureLow(resultOrField2);
            Level21_80660MultiplyComplete(resultOrField2, argumentOrField5);
            createdRecordOrInnerCount16++;
            Level21_80660CaptureHigh(privateOrCapturedWord12);
            resultOrField2 = privateOrCapturedWord12 >> 3;
            Level21_80660Field(argumentOrField4, unsigned char*, 2) = resultOrField2;
            argumentOrField4 += 4;
        } while (createdRecordOrInnerCount16 < 10);
    }
    positionOrPrivateOrRow17 = 0;
    topologyDivisionMagic11 = 0x66666667;
    Level21_80660Keep(topologyDivisionMagic11);
    topologyNextRow10 = 5;
    topologyRowOffset9 = 0;
    do {
        createdRecordOrInnerCount16 = 0;
        topologyRowBase8 = topologyRowOffset9;
        argumentOrField7 = positionOrPrivateOrRow17 + 1;
        argumentOrField6 = topologyNextRow10;
        do {
            resultOrField2 = createdRecordOrInnerCount16 + 1;
            fieldOrCapturedHigh3 = topologyRowBase8 + createdRecordOrInnerCount16;
            Level21_80660Keep(fieldOrCapturedHigh3);
            argumentOrField5 = argumentOrField6 + createdRecordOrInnerCount16;
            Level21_80660MultiplyComplete(resultOrField2, topologyDivisionMagic11);
            createdRecordOrInnerCount16 = resultOrField2;
            argumentOrField4 = fieldOrCapturedHigh3 * 8;
            privateOrCapturedWord12 = originalFrame.sp90;
            resultOrField2 = createdRecordOrInnerCount16 >> 31;
            argumentOrField4 += privateOrCapturedWord12;
            Level21_80660Field(argumentOrField4, unsigned char*, 0) = fieldOrCapturedHigh3;
            Level21_80660Field(argumentOrField4, unsigned char*, 2) = argumentOrField5;
            Level21_80660Field(argumentOrField4, unsigned char*, 4) = positionOrPrivateOrRow17;
            Level21_80660Field(argumentOrField4, unsigned char*, 5) = positionOrPrivateOrRow17;
            Level21_80660Field(argumentOrField4, unsigned char*, 6) = argumentOrField7;
            Level21_80660Field(argumentOrField4, unsigned char*, 7) = argumentOrField7;
            Level21_80660CaptureHigh(privateOrCapturedWord12);
            fieldOrCapturedHigh3 = privateOrCapturedWord12 >> 1;
            fieldOrCapturedHigh3 -= resultOrField2;
            resultOrField2 = fieldOrCapturedHigh3 * 5;
            resultOrField2 = createdRecordOrInnerCount16 - resultOrField2;
            fieldOrCapturedHigh3 = topologyRowBase8 + resultOrField2;
            resultOrField2 = argumentOrField6 + resultOrField2;
            Level21_80660Field(argumentOrField4, unsigned char*, 1) = fieldOrCapturedHigh3;
            Level21_80660Field(argumentOrField4, unsigned char*, 3) = resultOrField2;
        } while (createdRecordOrInnerCount16 < 5);
        topologyNextRow10 += 5;
        positionOrPrivateOrRow17++;
        topologyRowOffset9 += 5;
    } while (positionOrPrivateOrRow17 < 9);
    privateOrCapturedWord12 = originalFrame.sp90;
    resultOrField2 = -1;
    Level21_80660Field(privateOrCapturedWord12, int*, 360) = resultOrField2;
    privateOrCapturedWord12 = originalFrame.sp78;
    Level21_80660Keep(privateOrCapturedWord12);
    resultOrField2 = Level21_80660Field(privateOrCapturedWord12, int*, 16);
    if (!resultOrField2) {
        argumentOrField4 = originalFrame.sp80;
        argumentOrField5 = originalFrame.sp88;
        argumentOrField6 = originalFrame.sp90;
        resultOrField2 = Level21_80660Field(privateOrCapturedWord12, int*, 20);
        argumentOrField7 = Level21_80660Field(resultOrField2, int*, 0);
        resultOrField2 = Level21_80660Call50B00View1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6, argumentOrField7 + 48, 1);
        privateOrCapturedWord12 = originalFrame.sp78;
        Level21_80660Field(privateOrCapturedWord12, int*, 16) = resultOrField2;
    }
    goto originalRenderDone;
originalDisposeRender:
    argumentOrField4 = Level21_80660Field(privateOrCapturedWord12, int*, 16);
    if (argumentOrField4) {
        Level21_80660Call50B88View1(argumentOrField4);
        privateOrCapturedWord12 = originalFrame.sp78;
        Level21_80660Field(privateOrCapturedWord12, int*, 16) = 0;
    }
originalRenderDone:;
    return;
}
#undef Level21_80660Field
#undef Level21_80660Keep
#undef Level21_80660MultiplyComplete
#undef Level21_80660CaptureHigh
#undef Level21_80660CaptureLow

#define Controller810A0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller810A0Sin[] __asm__("D_800658A0");
extern unsigned char Controller810A0Cos[] __asm__("D_80065920");
extern unsigned short Controller810A0Angle0 __asm__("D_8006E03E"), Controller810A0Angle1
    __asm__("D_8006E040");
extern unsigned char Controller810A0Player[] __asm__("D_80070328");
extern void* Controller810A0Models[] __asm__("D_8006EE2C");
extern int D_8006C770;
extern void* (*Controller810A0Spawn)(int, void*)__asm__("SpawnMoby");
int Controller810A0Helper18368(void*, void*) __asm__("func_80018368");
void* Controller810A0Helper1BA30(void*, int, int, int, int, int) __asm__("func_8001BA30");
int Controller810A0Helper1C288(void*, int, int) __asm__("func_8001C288");
int Controller810A0CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller810A0PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller810A0PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller810A0CopyVector(void*, void*) __asm__("func_8004F178");
int Controller810A0AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller810A0Helper50844(void*, int, int, int) __asm__("func_80050844");
int Controller810A0Helper509E8(int) __asm__("func_800509E8");
int Controller810A0DeleteMoby(void*) __asm__("func_80055B18");
int Controller810A0Random(void) __asm__("rand");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level21/800810A0, level24/8007B948, level33/8007B48C and
 * level37/8007B4CC in original moby assembly. Each copy has 303 instructions;
 * all original helper/global symbols and relative branches checked separately.
 * Retain the 32-entry loop, per-entry byte reads and pointer rereads, class/model
 * selector chain, state 0/2/10 paths, six-argument helper stack layout, signed
 * table products and shifts, halfword decrement by 30 with signed clamp, and
 * original conditional handle cleanup followed by owner removal.
 * Constants, original access widths and compiler register lifetimes are exact.
 * Coordinate units, fixed-point domain meanings, semantic helper contracts and
 * caller cadence remain unresolved; the body executes once per invocation.
 * Confidence: exact original native/linked words and complete retail SHA set.
 * Falsify by comparing every original word or any full executable/overlay hash.
 * Empty constraints preserve original producer order without opcode patches.
 */
void func_level_21_800810A0(void* input) {
    register unsigned char* owner __asm__("$19") = input;
    struct {
        Vector3D previous;
        int unused[1];
    } frame;
    short decrementedHalfword;
    int handle;
    register int entryOffset __asm__("$20");
    int playerAngle;
    int tableOffset;
    int countdown;
    register int entryIndex __asm__("$21");
    register int state __asm__("$3");
    register unsigned char* position __asm__("$16");
    register unsigned char* spawnTag __asm__("$17");
    register unsigned char* tag __asm__("$18");
    register unsigned char* spawned __asm__("$16");
    register unsigned char* nearby __asm__("$16");
    register unsigned char* idlePosition __asm__("$17");

    {
        register int stateTwo __asm__("$2");
        MATCHING_KEEP_CLOBBER(owner, "$2");
        stateTwo = 2;
        MATCHING_KEEP_CLOBBER(stateTwo, "$3");
        state = Controller810A0Field(owner, unsigned char*, 0x48);
        tag = Controller810A0Field(owner, void**, 0);
        MATCHING_KEEP2(state, tag);
        if (state == stateTwo)
            goto moving;
    }
    if (state < 3) {
        entryIndex = 0;
        if (state == 0)
            goto initialize;
        goto finished;
    }
    idlePosition = owner + 0xC;
    if (state == 10)
        goto idle;
    goto finished;
initialize:
    {
        register int two __asm__("$22") = 2;
        MATCHING_KEEP(two);
        do {
            entryOffset = entryIndex * 2;
            if (Controller810A0AbsoluteByteAngleDelta(
                    Controller810A0Field((entryOffset + Controller810A0Field(tag, int*, 0xC)),
                                         unsigned char*, 1),
                    0x40) < 0x3C) {
                spawned = Controller810A0Spawn(Controller810A0Field(owner, short*, 0x36), owner);
                MATCHING_KEEP(spawned);
                if (spawned != 0) {
                    spawnTag = Controller810A0Field(spawned, void**, 0);
                    if (Controller810A0Field(spawned, unsigned char*, 0x3C) != two) {
                        register int one __asm__("$3") = 1;
                        register int classIndex __asm__("$2") =
                            Controller810A0Field(spawned, short*, 0x36);
                        register void* model __asm__("$2");
                        register int selector __asm__("$2");
                        Controller810A0Field(spawned, unsigned char*, 0x42) = 0;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(one, classIndex, "memory");
                        model = Controller810A0Models[classIndex];
                        model = Controller810A0Field(model, void**, 0x44);
                        selector = Controller810A0Field(model, unsigned char*, 0);
                        Controller810A0Field(spawned, unsigned char*, 0x3C) = two;
                        Controller810A0Field(spawned, unsigned char*, 0x3D) = two;
                        Controller810A0Field(spawned, unsigned char*, 0x3E) = 0;
                        Controller810A0Field(spawned, unsigned char*, 0x3F) = one;
                        selector = selector < 2U;
                        MATCHING_KEEP(selector);
                        selector ^= 1;
                        selector = -selector;
                        Controller810A0Field(spawned, unsigned char*, 0x40) = selector & 0x30;
                    }
                    Controller810A0Field(spawnTag, int*, 8) =
                        Controller810A0Helper50844(spawned + 0xC, 7, 0xA, 0x4080E0);
                    {
                        register int address __asm__("$2") = Controller810A0Field(tag, int*, 0xC);
                        register int angle __asm__("$3") = Controller810A0Angle1;
                        register int firstByte __asm__("$2");
                        register int secondByte __asm__("$3");
                        register int word __asm__("$2");
                        address = entryOffset + address;
                        MATCHING_KEEP2(address, angle);
                        angle <<= 16;
                        firstByte = Controller810A0Field(address, unsigned char*, 0);
                        angle >>= 20;
                        firstByte += angle;
                        firstByte += 64;
                        MATCHING_KEEP(firstByte);
                        Controller810A0Field(spawnTag, unsigned char*, 1) = firstByte;
                        address = Controller810A0Field(tag, int*, 0xC);
                        MATCHING_KEEP(address);
                        address = entryOffset + address;
                        secondByte = Controller810A0Field(address, unsigned char*, 1);
                        MATCHING_KEEP_CLOBBER(secondByte, "$2");
                        word = 50;
                        Controller810A0Field(spawnTag, int*, 4) = word;
                        word = 450;
                        Controller810A0Field(spawnTag, short*, 2) = word;
                        Controller810A0Field(spawnTag, unsigned char*, 0) = secondByte;
                    }
                    Controller810A0Field(spawned, unsigned char*, 0x44) = Controller810A0Random();
                    Controller810A0Field(spawned, signed char*, 0x48) = two;
                }
            }
            entryIndex += 1;
        } while (entryIndex < 0x20);
    }
    Controller810A0PlayMobySoundEvent(owner, 0, 0);
    Controller810A0Field(owner, unsigned char*, 0x48) = 0xAU;
    idlePosition = owner + 0xC;
idle:
    nearby = Controller810A0Helper1BA30(idlePosition, 0x7D0, 0, 0, 0x30000, 0);
    if (nearby != 0) {
        Controller810A0Field(nearby, signed char*, 0x51) = Controller810A0PlanarHeadingLookup(
            Controller810A0Field(nearby, int*, 0xC) - Controller810A0Field(owner, int*, 0xC),
            Controller810A0Field(nearby, int*, 0x10) - Controller810A0Field(owner, int*, 0x10), 0);
    }
    if (Controller810A0Helper1C288(idlePosition, 0x4B0, 7) != 0) {
        playerAngle = Controller810A0PlanarHeadingLookup(
                          Controller810A0Field(&Controller810A0Player, int*, 0) -
                              Controller810A0Field(owner, int*, 0xC),
                          Controller810A0Field(&Controller810A0Player, int*, 4) -
                              Controller810A0Field(owner, int*, 0x10),
                          0) &
                      0xFF;
        Controller810A0Field(&Controller810A0Player, int*, 0x298) = playerAngle;
        tableOffset = playerAngle * 2;
        Controller810A0Field(&Controller810A0Player, int*, 0x20C) = 0x10000400;
        Controller810A0Field(&Controller810A0Player, int*, 0x21C) =
            (int)((int)(*(short*)(Controller810A0Cos + tableOffset) * 0x23) >> 0xA);
        {
            register int sample __asm__("$3") = *(short*)(Controller810A0Sin + tableOffset);
            MATCHING_KEEP_CLOBBER(sample, "$2");
            Controller810A0Field(Controller810A0Player, int*, 0x224) = 40;
            Controller810A0Field(Controller810A0Player, int*, 0x220) = (sample * 35) >> 10;
        }
    }
    if (D_8006C770 != 0) {
        goto removeOwner;
    }
    goto finished;
moving:
    {
        register void* preparedVector __asm__("$4") = &frame.previous;
        register int angle __asm__("$2");
        __asm__("" : "=r"(preparedVector) : "0"(preparedVector) : "$2", "$16");
        angle = Controller810A0Angle1;
        MATCHING_KEEP_CLOBBER(angle, "$16");
        position = owner + 0xC;
        MATCHING_KEEP2(angle, position);
        Controller810A0Field(owner, signed char*, 0x46) = ((angle << 16) >> 20) - 128;
        Controller810A0Field(owner, signed char*, 0x45) =
            (signed char)((unsigned short)Controller810A0Angle0 >> 4);
        Controller810A0CopyVector(preparedVector, position);
    }
    Controller810A0Field(owner, int*, 0xC) =
        (int)(Controller810A0Field(owner, int*, 0xC) +
              ((int)(((int)(*(short*)(Controller810A0Cos +
                                      (Controller810A0Field(tag, unsigned char*, 1) * 2)) *
                            Controller810A0Field(tag, short*, 2)) >>
                      0xC) *
                     *(short*)(Controller810A0Cos +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2))) >>
               0xC));
    Controller810A0Field(owner, int*, 0x10) =
        (int)(Controller810A0Field(owner, int*, 0x10) +
              ((int)(((int)(*(short*)(Controller810A0Sin +
                                      (Controller810A0Field(tag, unsigned char*, 1) * 2)) *
                            Controller810A0Field(tag, short*, 2)) >>
                      0xC) *
                     *(short*)(Controller810A0Cos +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2))) >>
               0xC));
    Controller810A0Field(owner, int*, 0x14) =
        (int)(Controller810A0Field(owner, int*, 0x14) +
              ((int)(*(short*)(Controller810A0Sin +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2)) *
                     Controller810A0Field(tag, short*, 2)) >>
               0xC));
    if (Controller810A0Helper18368(&frame.previous, position) != 0) {
        Controller810A0Field(tag, int*, 4) = 0;
    }
    decrementedHalfword = (unsigned short)Controller810A0Field(tag, short*, 2) - 0x1E;
    Controller810A0Field(tag, short*, 2) = decrementedHalfword;
    if (decrementedHalfword < 0) {
        Controller810A0Field(tag, short*, 2) = 0;
    }
    countdown = Controller810A0Field(tag, int*, 4);
    if (countdown < 0x20) {
        Controller810A0Field(owner, signed char*, 0x57) = (signed char)(0x3F - (countdown >> 1));
        Controller810A0Field(owner, signed char*, 0x54) = 0;
        Controller810A0Field(owner, signed char*, 0x55) = 0;
        Controller810A0Field(owner, signed char*, 0x56) = 0;
    }
    if (Controller810A0CountTimerDown(tag + 4, 4) != 0) {
        handle = Controller810A0Field(tag, int*, 8);
        if (handle != 0) {
            Controller810A0Helper509E8(handle);
        }
        goto removeOwner;
    }
    goto finished;
removeOwner:
    Controller810A0DeleteMoby(owner);
finished:;
}

#undef Controller810A0Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008155C.
 * Original281 words: sibling4727.func_level_21_8008155C.json.
 * Units, helper contracts, cadence and runtime parity unresolved. */
#define F21Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int F21H4F334() __asm__("func_8004F334");
int F21H13AE4() __asm__("func_80013AE4");
int F21SubtractVector() __asm__("func_8004F1C8");
int F21ClearVector() __asm__("func_8004F168");
int F21H3BFC0() __asm__("func_8003BFC0");
int F21PlayMobySoundEvent() __asm__("func_8003BABC");
int F21AddVector() __asm__("func_8004F194");
int F21H3BE70() __asm__("func_8003BE70");
int F21H13B7C() __asm__("func_80013B7C");
extern unsigned char F21Flags __asm__("D_8006C7B4");
extern int F21Index __asm__("D_8006C58C");
extern unsigned char F21Table[] __asm__("D_80070300");
extern unsigned char F21Player[] __asm__("D_80070328");
extern unsigned char F21Position[] __asm__("D_80070328");
extern unsigned char F21Angles[] __asm__("D_80070328");
extern int F21State __asm__("D_8006E048");
extern int (*F21Route)() __asm__("unk_ovlheader_800743EC");
void func_level_21_8008155C(void* input) {
    signed char angles[8];
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$18");
    register int flag19 __asm__("$19");
    register int one20 __asm__("$20") = 1;
    register int distance20 __asm__("$20");
    register int height16 __asm__("$16");
    register int substate16 __asm__("$16");
    register unsigned char* player16 __asm__("$16");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register void* arg6 __asm__("$6");
    MATCHING_KEEP(owner);
    MATCHING_KEEP(one20);
    other = owner[72];
    tag = F21Field(owner, unsigned char**, 0);
    if (other == one20)
        goto state1;
    if (other < 2) {
        if (!other)
            goto state0;
        goto done;
    }
    if (other == 2)
        goto state2;
    goto done;
state0:
    MATCHING_BARRIER("$3");
    value = F21Flags & 1;
    flag19 = 0;
    if (value)
        goto height_check;
    value = F21Index;
    value = F21Table[value] & 1;
    if (!value)
        goto done;
height_check:
    other = F21Field(owner, short*, 56);
    value = F21Field(owner, int*, 20);
    arg5 = (int)(F21Player + 8);
    value -= other;
    other = *(int*)arg5;
    call4 = (void*)F21Field(F21Player, int*, 184);
    height16 = value - other;
    if (call4)
        goto flag_check;
    value = F21H4F334(owner + 12, (unsigned char*)arg5 - 8);
    if (value >= 700)
        goto flag_check;
    value = height16 - 1651;
    value = (unsigned)value < 99;
    if (value)
        owner[73] = 1;
flag_check:
    substate16 = owner[73];
    call4 = owner + 12;
    if (substate16 != 1)
        goto distance_owner;
    value = F21Field(tag, int*, 40);
    call4 = F21Field((void*)value, void**, 12);
    F21H13AE4(call4, F21Player);
    __asm__ volatile("" : "=r"(owner) : "0"(owner) : "$2", "memory");
    value = 0x10000002;
    other = F21State;
    F21Field(F21Player, int*, 524) = value;
    F21Field(F21Player, int*, 572) = 0;
    if (other == substate16) {
        MATCHING_BARRIER("$4");
        __asm__("" : "=r"(flag19) : "0"(1));
        F21Field(tag, int*, 32) = flag19;
    }
    call4 = owner + 12;
distance_owner:
    player16 = F21Player;
    value = F21H4F334(call4, player16);
    call4 = (void*)9999999;
    other = F21Field(tag, int*, 0);
    arg5 = F21Field((void*)other, short*, 2);
    distance20 = value;
    if (arg5 >= 3)
        goto secondary_distance;
    {
        arg5 = F21Field((void*)other, int*, 12);
        call4 = player16;
        arg5 += 192;
        goto measure_target;
    }
secondary_distance:
    MATCHING_BARRIER("$2");
    MATCHING_KEEP(call4);
    value = arg5 < 11;
    if (value)
        goto distance_skip;
    arg5 = F21Field((void*)other, int*, 12);
    call4 = player16;
    arg5 += 16;
measure_target:
    value = F21H4F334(call4, (void*)arg5);
    call4 = (void*)value;
distance_skip:
    value = (int)call4 + 1000;
distance_ready:
    value = value < distance20;
    if (value)
        flag19 = 1;
    if (!flag19)
        goto done;
    other = F21Field(tag, int*, 0);
    value = F21Field((void*)other, short*, 2);
    call4 = tag + 20;
    if (!value)
        F21Field((void*)other, short*, 2) = 1;
    F21SubtractVector(call4, F21Player, owner + 12);
    F21ClearVector(tag + 4);
    owner[72] = 1;
    goto done;
state1:
    value = F21Field(owner, signed char*, 68);
    other = F21Field(owner, signed char*, 69);
    call4 = (void*)(int)F21Field(owner, signed char*, 70);
    angles[0] = value;
    angles[1] = other;
    angles[2] = (int)call4;
    __asm__("" ::: "$4", "$6", "$7", "memory");
    call4 = owner;
    arg6 = tag + 4;
    MATCHING_KEEP2(call4, arg6);
    value = F21Route(call4, F21Field(tag, void**, 0), arg6, tag + 16, 22, 0);
    call4 = owner;
    arg5 = F21Field(tag, int*, 36);
    MATCHING_KEEP2(call4, arg5);
    flag19 = value;
    value = F21H3BFC0(call4, arg5);
    call4 = owner;
    if (!value) {
        MATCHING_BARRIER("$2");
        F21Field(tag, int*, 36) = F21PlayMobySoundEvent(call4, 0, 4);
    }
    value = F21Field(tag, int*, 32);
    if (!value)
        goto events;
    value = F21Field(tag, int*, 40);
    player16 = F21Player;
    call4 = F21Field((void*)value, void**, 12);
    F21H13AE4(call4, player16);
    value = 0x10008000;
    call4 = player16 + 556;
    MATCHING_OBSERVE_VOLATILE(call4);
    arg5 = (int)(owner + 12);
    F21Field(F21Player, int*, 524) = value;
    F21AddVector(call4, (void*)arg5, tag + 20);
    arg5 = (int)(F21Position + 12);
    MATCHING_KEEP(arg5);
    call4 = F21Angles + 552;
    MATCHING_KEEP(call4);
    value = *(signed char*)arg5;
    other = *((signed char*)arg5 + 1);
    ((signed char*)call4)[0] = value;
    ((signed char*)call4)[1] = other;
    value = *((signed char*)arg5 + 2);
    ((signed char*)call4)[2] = value;
    F21Field(F21Player, int*, 572) = 0;
events:
    value = flag19 & 1;
    if (!value)
        goto restore;
    value = F21H3BFC0(owner, F21Field(tag, int*, 36));
    if (value)
        F21H3BE70(F21Field(tag, int*, 36));
    other = F21Field(tag, int*, 0);
    F21Field(tag, int*, 36) = -1;
    other = F21Field((void*)other, short*, 2);
    if (other != one20 && other != 12)
        goto restore;
    value = F21Field(tag, int*, 32);
    if (!value)
        goto reset_state;
    F21H13B7C(1);
    owner[72] = 2;
    goto restore;
reset_state:
    owner[72] = 0;
restore:
    value = angles[0];
    other = angles[1];
    call4 = (void*)(int)angles[2];
    owner[68] = value;
    owner[69] = other;
    owner[70] = (int)call4;
    MATCHING_BARRIER_VOLATILE("memory");
    goto done;
state2:
    call4 = (void*)owner[73];
    if ((int)call4 != one20)
        goto flag2;
    value = 0x10000002;
    other = F21State;
    F21Field(F21Player, int*, 524) = value;
    F21Field(F21Player, int*, 572) = 0;
    if (other == (int)call4) {
        owner[73] = 2;
        goto flag2;
    }
    if (!other)
        owner[73] = 0;
flag2:
    other = owner[73];
    if (other != 2)
        goto retreat;
    value = 0x10000002;
    other = F21State;
    F21Field(F21Player, int*, 524) = value;
    F21Field(F21Player, int*, 572) = 0;
    if (other == 1)
        goto done;
    owner[73] = 0;
    goto done;
retreat:
    value = F21H4F334(owner + 12, F21Player);
    if (value < 1401)
        goto done;
    F21Field(tag, int*, 32) = 0;
    owner[72] = 0;
done:;
}
#undef F21Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_21/moby/func_level_21_800819C0.s SHA256 7ce90da4d10532508b1e7b896e27b76ed7611034eccc2c55c9ec9adf354edb84. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char Controller819C0_func_80034F40() __asm__("func_80034F40");                 /* extern */
int Controller819C0_func_80035194() __asm__("func_80035194");                           /* extern */
unsigned char Controller819C0TurnMobyTowardPlayer() __asm__("func_8003573C");           /* extern */
unsigned char Controller819C0CountTimerDown() __asm__("func_800359A4");                 /* extern */
int Controller819C0_func_80035A80() __asm__("func_80035A80");                           /* extern */
int Controller819C0ProbeGroundFromRaisedMoby() __asm__("func_80035D38");                /* extern */
int Controller819C0RandBetween() __asm__("func_8003636C");                              /* extern */
unsigned char Controller819C0_func_800369B8() __asm__("func_800369B8");                 /* extern */
unsigned char Controller819C0_func_80036A68() __asm__("func_80036A68");                 /* extern */
unsigned char Controller819C0_func_80038F14() __asm__("func_80038F14");                 /* extern */
unsigned char Controller819C0_func_800399E8() __asm__("func_800399E8");                 /* extern */
unsigned char Controller819C0_func_80039B6C() __asm__("func_80039B6C");                 /* extern */
unsigned char Controller819C0_func_8003BA00() __asm__("func_8003BA00");                 /* extern */
int Controller819C0PlayMobySoundEvent() __asm__("func_8003BABC");                       /* extern */
int Controller819C0PlanarHeadingLookup() __asm__("func_8004E880");                      /* extern */
unsigned char Controller819C0ShiftVectorRightTowardZero() __asm__("func_8004F110");     /* extern */
unsigned char Controller819C0CopyVector() __asm__("func_8004F178");                     /* extern */
unsigned char Controller819C0AddVector() __asm__("func_8004F194");                      /* extern */
int Controller819C0AbsoluteByteAngleDelta() __asm__("func_8004F264");                   /* extern */
int Controller819C0ApproximatePlanarDistance() __asm__("func_8004F334");                /* extern */
unsigned char Controller819C0DeleteMoby() __asm__("func_80055B18");                     /* extern */
unsigned char Controller819C0RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
extern int Controller819C0_D_8006C550 __asm__("D_8006C550");
extern int Controller819C0_D_8006C640 __asm__("D_8006C640");
extern int Controller819C0_D_8006C770 __asm__("D_8006C770");
extern int Controller819C0_D_80070328 __asm__("D_80070328");

void func_level_21_800819C0(void* input_arg0) {
    register void* owner __asm__("$18") = input_arg0;
    register int value2 __asm__("$2");
    register void* call4 __asm__("$4");
    /* Original vector at0x20 and its padding; saved registers begin at0x30. */
    struct {
        int sp20, sp24, sp28, pad2C;
    } originalFrame;

    unsigned char sharedHelperArg5;
    register void* globalBasePointer __asm__("$17");
    register void* globalField50Pointer __asm__("$21");
    register int firstProduct __asm__("$6");
    register int helperResult35A80 __asm__("$16");
    register int vectorMultiplier __asm__("$16");
    register int helperResultF334State0 __asm__("$17");
    register int helperResultF334State6 __asm__("$20");
    int signedFieldDifferenceState6;
    register int ownerFieldDifference __asm__("$3");
    register int ownerField38 __asm__("$4");
    register int globalField8 __asm__("$5");
    register void* call5 __asm__("$5");
    int linkedIndex;
    int ownerFieldDifferenceState6;
    register int absoluteFieldDifference __asm__("$16");
    unsigned char ownerState;
    register void* ownerVector __asm__("$16");
    register void* ownerData __asm__("$19");

    MATCHING_KEEP(owner);
    ownerData = M2C_FIELD(owner, void**, 0);
    if ((M2C_FIELD(ownerData, int*, 0x34) != 0) && (Controller819C0_D_8006C640 == 0) &&
        (Controller819C0ApproximatePlanarDistance(owner + 0xC, &Controller819C0_D_80070328) <
         M2C_FIELD(ownerData, int*, 0x34))) {
        Controller819C0_func_80036A68(owner, 1, 0, 0);
        Controller819C0DeleteMoby(owner);
        return;
    }
    if (M2C_FIELD(owner, unsigned char*, 0x48) != 0x7D) {
        if (M2C_FIELD(ownerData, int*, 0x24) == 0) {
            Controller819C0_func_800399E8(owner, ownerData + 0x24);
        }
        if (M2C_FIELD(&Controller819C0_D_80070328, int*, 0x50) == 0xB) {
            if (Controller819C0ApproximatePlanarDistance(
                    owner + 0xC, (&Controller819C0_D_80070328 + 0x50) - 0x50) < 0x7000) {
                M2C_FIELD(owner, unsigned char*, 0x52) = 0xFFU;
            }
        } else if (M2C_FIELD(owner, unsigned char*, 0x52) == 0xFF) {
            M2C_FIELD(owner, unsigned char*, 0x52) = 0xFEU;
        }
        if ((M2C_FIELD(owner, int*, 0x18) & 0x90000) &&
            (M2C_FIELD(owner, unsigned char*, 0x48) != 8)) {
            Controller819C0_func_80036A68(owner, 1, 0, 0);
            Controller819C0_func_80038F14(owner, ownerData, 1, 8);
        }
        Controller819C0CountTimerDown(ownerData + 0x18, 4);
        ownerState = M2C_FIELD(owner, unsigned char*, 0x48);
        switch (ownerState) {
            case 0:
                value2 = Controller819C0ApproximatePlanarDistance(owner + 0xC,
                                                                  &Controller819C0_D_80070328);
                ownerField38 = M2C_FIELD(owner, short*, 0x38);
                ownerFieldDifference = M2C_FIELD(owner, int*, 0x14);
                globalField8 = M2C_FIELD(&Controller819C0_D_80070328, int*, 8);
                ownerFieldDifference -= ownerField38;
                absoluteFieldDifference = ownerFieldDifference - globalField8;
                helperResultF334State0 = value2;
                if (absoluteFieldDifference < 0) {
                    absoluteFieldDifference = globalField8 - ownerFieldDifference;
                }
                if ((M2C_FIELD(ownerData, void**, 0x28) != 0) &&
                    (((linkedIndex = M2C_FIELD(ownerData, int*, 0x30), (linkedIndex != -1)) &&
                      ((unsigned char)M2C_FIELD(((linkedIndex * 0x58) + Controller819C0_D_8006C550),
                                                unsigned char*, 0x48) >= 0x80U)) ||
                     ((helperResultF334State0 < M2C_FIELD(ownerData, int*, 0x2C)) &&
                      (absoluteFieldDifference < 0xFA0)))) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 2U;
                    Controller819C0_func_80034F40(owner, 2);
                    return;
                }
                Controller819C0TurnMobyTowardPlayer(owner, 5, 0, 0);
                if ((M2C_FIELD(ownerData, int*, 0x18) == 0) && (absoluteFieldDifference < 0x3E8) &&
                    (((M2C_FIELD(owner, int*, 0x14) - M2C_FIELD(owner, short*, 0x38)) -
                      M2C_FIELD(&Controller819C0_D_80070328, int*, 8)) < 0xC8) &&
                    (helperResultF334State0 < 0x251C)) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 3U;
                    MATCHING_OBSERVE2(absoluteFieldDifference, helperResultF334State0);
                    Controller819C0_func_80034F40(owner, 3);
                    return;
                }
                if (Controller819C0_D_8006C770 != 0) {
                    if (M2C_FIELD(ownerData, int*, 0x1C) == 0) {
                        Controller819C0_func_80034F40(owner, 1);
                        M2C_FIELD(ownerData, int*, 0x1C) = Controller819C0RandBetween(1, 3);
                    } else {
                        Controller819C0_func_80034F40(owner, 0);
                        M2C_FIELD(ownerData, int*, 0x1C) =
                            (int)(M2C_FIELD(ownerData, int*, 0x1C) - 1);
                    }
                }
            default:
                goto testOwnerData24;
            case 2:
                value2 = Controller819C0_func_80035A80(owner, M2C_FIELD(ownerData, void**, 0x28),
                                                       0x100, 0xAA, 0, 6, 0x28, 5);
                call4 = owner + 0xC;
                MATCHING_KEEP(call4);
                helperResult35A80 = value2;
                if (Controller819C0ApproximatePlanarDistance(call4, &Controller819C0_D_80070328) <
                    0xBB8) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 3U;
                    Controller819C0_func_80034F40(owner, 3);
                }
                if ((helperResult35A80 & 1) &&
                    (M2C_FIELD(M2C_FIELD(ownerData, void**, 0x28), short*, 2) == 0)) {
                    MATCHING_OBSERVE(helperResult35A80);
                    M2C_FIELD(ownerData, void**, 0x28) = 0;
                    M2C_FIELD(owner, unsigned char*, 0x48) = 0U;
                    return;
                }
                goto testOwnerData24;
            case 3:
                Controller819C0TurnMobyTowardPlayer(owner, 4, 0, 0);
                if (Controller819C0_D_8006C770 != 0) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 6U;
                    Controller819C0_func_80034F40(owner, 6);
                }
                goto testOwnerData24;
            case 6:
                call4 = &originalFrame.sp20;
                MATCHING_KEEP(call4);
                /* Pointer arithmetic here uses original byte offsets. */
                globalField50Pointer = (void*)&Controller819C0_D_80070328 + 0x50;
                MATCHING_KEEP(globalField50Pointer);
                vectorMultiplier = -(M2C_FIELD(globalField50Pointer, int*, 0) == 4) & 0xA;
                Controller819C0CopyVector(call4, globalField50Pointer + 0x48);
                value2 = originalFrame.sp20;
                MATCHING_KEEP(value2);
                firstProduct = value2 * vectorMultiplier;
                originalFrame.sp20 = firstProduct;
                originalFrame.sp24 *= vectorMultiplier;
                originalFrame.sp28 *= vectorMultiplier;
                Controller819C0ShiftVectorRightTowardZero(&originalFrame.sp20, 6, firstProduct);
                call4 = &originalFrame.sp20;
                call5 = call4;
                MATCHING_KEEP2(call4, call5);
                globalBasePointer = globalField50Pointer - 0x50;
                Controller819C0AddVector(call4, call5, globalBasePointer);
                ownerVector = owner + 0xC;
                helperResultF334State6 =
                    Controller819C0ApproximatePlanarDistance(ownerVector, &originalFrame.sp20);
                Controller819C0TurnMobyTowardPlayer(owner, 4, 0, 0);
                if (Controller819C0ApproximatePlanarDistance(ownerVector, globalBasePointer) >=
                    0x2AF9) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 5U;
                    Controller819C0_func_80034F40(owner, 5);
                }
                if ((M2C_FIELD(ownerData, int*, 0x18) == 0) && (helperResultF334State6 < 0xC1C) &&
                    (Controller819C0AbsoluteByteAngleDelta(
                         M2C_FIELD(&Controller819C0_D_80070328, unsigned char*, 0xE),
                         Controller819C0PlanarHeadingLookup(
                             M2C_FIELD(owner, int*, 0xC) -
                                 M2C_FIELD(globalField50Pointer, int*, -0x50),
                             M2C_FIELD(owner, int*, 0x10) -
                                 M2C_FIELD(&Controller819C0_D_80070328, int*, 4),
                             0)) < 0x32)) {
                    MATCHING_OBSERVE(helperResultF334State6);
                    ownerFieldDifferenceState6 =
                        M2C_FIELD(owner, int*, 0x14) - M2C_FIELD(owner, short*, 0x38);
                    signedFieldDifferenceState6 = ownerFieldDifferenceState6 -
                                                  M2C_FIELD(&Controller819C0_D_80070328, int*, 8);
                    if (signedFieldDifferenceState6 >= 0) {
                        if (signedFieldDifferenceState6 >= 0x4B0) {

                        } else {
                            goto enterState4;
                        }
                    } else if ((M2C_FIELD(&Controller819C0_D_80070328, int*, 8) -
                                ownerFieldDifferenceState6) < 0x4B0) {
                    enterState4:
                        M2C_FIELD(owner, unsigned char*, 0x48) = 4U;
                        Controller819C0_func_80034F40(owner, 4);
                    }
                }
                goto testOwnerData24;
            case 5:
                Controller819C0TurnMobyTowardPlayer(owner, 4, 0, 0);
                if (Controller819C0_D_8006C770 != 0) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 0U;
                    Controller819C0_func_80034F40(owner, 0);
                }
                goto testOwnerData24;
            case 4:
                Controller819C0TurnMobyTowardPlayer(owner, 4, 0, 0);
                if ((unsigned int)(M2C_FIELD(&Controller819C0_D_80070328, int*, 0x50) - 7) < 2U) {
                    M2C_FIELD(ownerData, int*, 0x20) = 1;
                }
                if (Controller819C0_D_8006C770 != 0) {
                    M2C_FIELD(ownerData, int*, 0x18) = 0xB4;
                    if (M2C_FIELD(ownerData, int*, 0x20) != 0) {
                        M2C_FIELD(owner, unsigned char*, 0x48) = 7U;
                        call4 = owner;
                        sharedHelperArg5 = 7;
                    } else {
                        M2C_FIELD(owner, unsigned char*, 0x48) = 6U;
                        call4 = owner;
                        sharedHelperArg5 = 6;
                    }
                    Controller819C0_func_80034F40(call4, sharedHelperArg5);
                }
                goto call55D24;
            case 7:
                if (Controller819C0_D_8006C770 != 0) {
                    M2C_FIELD(ownerData, int*, 0x20) = 0;
                    M2C_FIELD(owner, unsigned char*, 0x48) = 6U;
                    Controller819C0_func_80034F40(owner, 6);
                }
                goto testOwnerData24;
            case 8:
                if (M2C_FIELD(ownerData, short*, 6) < -0x64) {
                    if ((M2C_FIELD(ownerData, int*, 0x38) == -1) &&
                        (((M2C_FIELD(owner, int*, 0x14) - M2C_FIELD(owner, short*, 0x38)) -
                          Controller819C0ProbeGroundFromRaisedMoby(owner)) >= 0xFA1)) {
                        M2C_FIELD(ownerData, int*, 0x38) =
                            Controller819C0PlayMobySoundEvent(owner, 0, 0);
                    }
                }
                if (Controller819C0_func_80035194(owner, ownerData) == 0x100) {
                    Controller819C0RefreshMobySpatialGridAndBasis(owner, 4);
                    Controller819C0_func_8003BA00(owner);
                    Controller819C0_func_800369B8(owner, 0x40);
                    Controller819C0DeleteMoby(owner);
                } else {
                    goto call55D24;
                }
                goto testOwnerData24;
        }
    call55D24:
        Controller819C0RefreshMobySpatialGridAndBasis(owner, 1);
    testOwnerData24:
        if (M2C_FIELD(ownerData, int*, 0x24) != 0)
            Controller819C0_func_80039B6C(owner, ownerData + 0x24);
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80082100.
 * AI generated; not human reviewed. All387 original native/linked words and
 * actual branch,call and internal destinations must match. No owned selector
 * or padding words occur. Frame48 (72 bytes) retains SP10..1F reserve and
 * S0..S7/FP/RA saves at SP20..44. Reserved contents are never read. Natural FP
 * holds the original table address; no fixedFP or SP binding is present.
 * Ten complete signed64 C products contain both original signed32 operands.
 * Empty metadata names their signed low32 words from the complete HILO pair.
 * Narrowing precedes each original signedSRA12 and subsequent signed product.
 * Six complete signed64 products reproduce original /3 high-word corrections
 * using55555556 and the original doubled-numerator sign. No low-only product
 * is supplied to a high-word consumer and no incoming hardware value is read.
 * Original last low word is captured before each division; its signed shift
 * and Z store retain143/145 and326/328 relative to the numerator sign shift.
 * Full initialized operand/argument identities prevent independent complete
 * products from overlapping in HILO. Every template emits zero CPU words.
 * S0/S1 angle,address and timer phases and A0 sample,address,magic and argument
 * phases are sequential. Separate created/private aliases and A5 views have
 * disjoint live ranges. No live fixed-register aliases overlap.
 * Original state1/80 words,spawn-null A0zero delay slots,signed LH tables,
 * RNG predicate/literals,packed field words and callback target are retained.
 * Original callback247 SH18 remains in the original indirect-call delay slot.
 * Raw vectors:32767*900=29490300,whose signedSRA12 is7199;7199*(-32768)
 * has signedSRA12=-57592. Doubled numerator-10 divided by3 yields-3.
 * These assert instruction arithmetic. Physical units,table interpretation,
 * full helper/caller chains,cadence beyond invocation,Rev1 mapping and retail
 * runtime are open. Confidence is binary identity after all source/data/hash
 * gates. Next:human review and synchronized retail captures. Every original
 * native/linked word,actual transfer,owned byte and complete EXE/every-overlay
 * retail hash must remain identical. Compiler,filter,flags and gates unchanged.
 */
/* Original assembly SHA256 9f1bc45752025f12e1369a53b2b501e019325fbdb7aa07edded8490ffd20f696 */
#define Level21_82100SignedThirdWithMagic(a, m)                                                 \
    ({                                                                                          \
        long long completeProduct;                                                              \
        int completeHigh;                                                                       \
        rawResultSpeedSignOrQuotient2 = (int)(a);                                               \
        completeProduct = (long long)rawResultSpeedSignOrQuotient2 * (long long)(int)(m);       \
        rawResultSpeedSignOrQuotient2 >>= 31;                                                   \
        __asm__("" : "=h"(completeHigh) : "x"(completeProduct));                                \
        tableAddressOrCapturedHigh8 = completeHigh;                                             \
        __asm__("" : "=r"(tableAddressOrCapturedHigh8) : "0"(tableAddressOrCapturedHigh8));     \
        rawResultSpeedSignOrQuotient2 =                                                         \
            tableAddressOrCapturedHigh8 - rawResultSpeedSignOrQuotient2;                        \
        __asm__("" : "=r"(rawResultSpeedSignOrQuotient2) : "0"(rawResultSpeedSignOrQuotient2)); \
        rawResultSpeedSignOrQuotient2;                                                          \
    })
#define Level21_82100SignedThird(a)                                                             \
    ({                                                                                          \
        long long completeProduct;                                                              \
        int completeHigh;                                                                       \
        rawResultSpeedSignOrQuotient2 = (int)(a);                                               \
        completeProduct = (long long)rawResultSpeedSignOrQuotient2 * 0x55555556LL;              \
        rawResultSpeedSignOrQuotient2 >>= 31;                                                   \
        __asm__("" : "=h"(completeHigh) : "x"(completeProduct));                                \
        tableAddressOrCapturedHigh8 = completeHigh;                                             \
        __asm__("" : "=r"(tableAddressOrCapturedHigh8) : "0"(tableAddressOrCapturedHigh8));     \
        rawResultSpeedSignOrQuotient2 =                                                         \
            tableAddressOrCapturedHigh8 - rawResultSpeedSignOrQuotient2;                        \
        __asm__("" : "=r"(rawResultSpeedSignOrQuotient2) : "0"(rawResultSpeedSignOrQuotient2)); \
        rawResultSpeedSignOrQuotient2;                                                          \
    })
/* AI generated; not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_21/moby/func_level_21_80082100.s SHA256 9f1bc45752025f12e1369a53b2b501e019325fbdb7aa07edded8490ffd20f696. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level21_82100Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level21_82100Call35194View1(void*, void*) __asm__("func_80035194");
/* extern */
int Level21_82100Call36220View1(int*, int, int, int) __asm__("func_80036220");
/* extern */
int Level21_82100RandBetweenView1(int, int) __asm__("func_8003636C");
/* extern */
int Level21_82100RandSignedBetweenView1(int, int) __asm__("func_800363DC");
/* extern */
int Level21_82100Call369B8View1(void*, int) __asm__("func_800369B8");
/* extern */
int Level21_82100Call36A68View1(void*, int, int, int) __asm__("func_80036A68");
/* extern */
int Level21_82100Call38BF8View1(void*, void*, int, int) __asm__("func_80038BF8");
/* extern */
int Level21_82100Call3B7B4View1(int, int, int*) __asm__("func_8003B7B4");
/* extern */
int Level21_82100Call3BA00View1(void*) __asm__("func_8003BA00");
/* extern */
int Level21_82100PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
/* extern */
void Level21_82100AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
/* extern */
int Level21_82100DeleteMobyView1(void*) __asm__("func_80055B18");
/* extern */
void Level21_82100RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
/* extern */
int Level21_82100DatarandView1(void) __asm__("rand");
/* extern */
extern int Level21_82100Data6580CView1 __asm__("D_8006580C");
extern int Level21_82100Data65834View1 __asm__("D_80065834");
extern unsigned char Level21_82100Data658A0View1 __asm__("D_800658A0");
extern unsigned char Level21_82100Data65920View1 __asm__("D_80065920");
extern int Level21_82100Data6C54CView1 __asm__("D_8006C54C");
extern int Level21_82100Data6C574View1 __asm__("D_8006C574");
extern int Level21_82100Data6C578View1 __asm__("D_8006C578");
extern int Level21_82100Data6C640View1 __asm__("D_8006C640");
extern int Level21_82100Data6C774View1 __asm__("D_8006C774");
extern unsigned char Level21_82100Data6C7F8View1 __asm__("D_8006C7F8");
extern unsigned char Level21_82100Data6D088View1 __asm__("D_8006D088");
extern unsigned char Level21_82100Data70328View1 __asm__("D_80070328");
extern signed char Level21_82100Data71597View1 __asm__("D_80071597");
extern unsigned char Level21_82100Data8F6A0View1 __asm__("D_level_21_8008F6A0");
extern void* (*Level21_82100DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern int (*Level21_82100Data743E8View1)(void*, int, void*) __asm__("unk_ovlheader_800743E8");
void func_level_21_80082100(void* ownerParameter) {
    struct {
        unsigned char reserved[16];
    } originalFrameReserve;
    int retainedSignedTableBase;
    int completeSignedLowWord;
    register int initialArgumentWord5 __asm__("$5");
    register int argumentSampleAddressOrMagic4 __asm__("$4");
    register int retainedAngleOrAddress17 __asm__("$17");
    register int retainedTimerAngleOrAddress16 __asm__("$16");
    register int rawResultSpeedSignOrQuotient2 __asm__("$2");
    register int rawSampleProductOrField3 __asm__("$3");
    register int tableAddressOrCapturedHigh8 __asm__("$8");
    register void* ownerRecord20 __asm__("$20") = ownerParameter;
    register int firstCreatedIndex23 __asm__("$23");
    int temp_v1_2;
    register void* firstCreatedPrivate18 __asm__("$18");
    register void* secondCreatedPrivate18 __asm__("$18");
    register void* privateRecord21 __asm__("$21");
    register void* firstCreatedRecord19 __asm__("$19");
    register void* secondCreatedRecord19 __asm__("$19");
    privateRecord21 = Level21_82100Field(ownerRecord20, void**, 0);
    if (Level21_82100Field(ownerRecord20, unsigned char*, 0x48) != 0xA) {
        goto block_4;
    }
    if (Level21_82100Call36220View1(&Level21_82100Data70328View1, privateRecord21 + 0x40, 0, 0) !=
        0) {
        goto block_3;
    }
    if (Level21_82100Call36220View1(&Level21_82100Data70328View1, privateRecord21 + 0x58, 0, 0) ==
        0) {
        goto block_32;
    }
block_3:
    argumentSampleAddressOrMagic4 = (int)ownerRecord20;
    initialArgumentWord5 = 1;
    rawSampleProductOrField3 = 1;
    rawResultSpeedSignOrQuotient2 = 80;
    __asm__(""
            : "=r"(rawSampleProductOrField3)
            : "0"(rawSampleProductOrField3), "r"(rawResultSpeedSignOrQuotient2),
              "r"(argumentSampleAddressOrMagic4), "r"(initialArgumentWord5));
    Level21_82100Field(ownerRecord20, signed char*, 65) = rawSampleProductOrField3;
    Level21_82100Field(ownerRecord20, signed char*, 76) = rawResultSpeedSignOrQuotient2;
    Level21_82100Field(ownerRecord20, signed char*, 77) = rawSampleProductOrField3;
    Level21_82100RefreshMobySpatialGridAndBasisView1(argumentSampleAddressOrMagic4,
                                                     initialArgumentWord5);
    retainedTimerAngleOrAddress16 = privateRecord21 + 0x3C;
    Level21_82100Field(ownerRecord20, signed char*, 0x4A) = 0x46;
    Level21_82100Field(privateRecord21, int*, 0x3C) = 0;
    Level21_82100Call3B7B4View1(retainedTimerAngleOrAddress16, 4, &Level21_82100Data6D088View1);
    Level21_82100Call3B7B4View1(retainedTimerAngleOrAddress16, 4, &Level21_82100Data6C7F8View1);
    Level21_82100Field(ownerRecord20, unsigned char*, 0x48) = 0U;
block_4:
    if (!(Level21_82100Field(ownerRecord20, int*, 0x18) & 0x30000)) {
        goto block_14;
    }
    if (Level21_82100Field(ownerRecord20, unsigned char*, 0x48) != 0) {
        goto block_14;
    }
    Level21_82100PlayMobySoundEventView1(ownerRecord20, 0, 1);
    Level21_82100RefreshMobySpatialGridAndBasisView1(ownerRecord20, 4);
    Level21_82100Field(ownerRecord20, signed char*, 0x4E) = 0x30;
    firstCreatedIndex23 = 0;
    retainedSignedTableBase = (int)&Level21_82100Data658A0View1;
    MATCHING_KEEP(retainedSignedTableBase);
    do {
        if ((Level21_82100Data6C578View1 - Level21_82100Data6C574View1) < 0x15) {
            goto block_13;
        }
        firstCreatedRecord19 = Level21_82100DataSpawnMobyView1(0x2DD, ownerRecord20);
        if (firstCreatedRecord19 == 0) {
            goto block_12;
        }
        argumentSampleAddressOrMagic4 = 0;
        MATCHING_KEEP(argumentSampleAddressOrMagic4);
        MATCHING_KEEP(firstCreatedRecord19);
        firstCreatedPrivate18 = Level21_82100Field(firstCreatedRecord19, void**, 0);
        Level21_82100Field(firstCreatedRecord19, signed char*, 0x4C) = 0x50;
        Level21_82100Field(firstCreatedRecord19, signed char*, 0x4E) = 0x50;
        retainedTimerAngleOrAddress16 =
            Level21_82100RandBetweenView1(argumentSampleAddressOrMagic4, 0xFF);
        retainedAngleOrAddress17 = Level21_82100RandBetweenView1(0, 0xFF);
        rawResultSpeedSignOrQuotient2 = Level21_82100RandBetweenView1(0, 0x384);
        {
            register short* firstSampleAddress5 __asm__("$5");
            retainedTimerAngleOrAddress16 = retainedTimerAngleOrAddress16 * 2;
            MATCHING_KEEP_CLOBBER(retainedTimerAngleOrAddress16, "$8");
            tableAddressOrCapturedHigh8 = (int)&Level21_82100Data65920View1;
            MATCHING_KEEP(tableAddressOrCapturedHigh8);
            rawSampleProductOrField3 = retainedTimerAngleOrAddress16 + tableAddressOrCapturedHigh8;
            rawSampleProductOrField3 = *(short*)rawSampleProductOrField3;
            {
                long long originalCompleteProduct0 =
                    (long long)rawSampleProductOrField3 * (long long)rawResultSpeedSignOrQuotient2;
                __asm__("" : "=l"(completeSignedLowWord) : "x"(originalCompleteProduct0));
            }
            retainedAngleOrAddress17 = retainedAngleOrAddress17 * 2;
            firstSampleAddress5 = (short*)(retainedAngleOrAddress17 + tableAddressOrCapturedHigh8);
            MATCHING_KEEP(firstSampleAddress5);
            rawSampleProductOrField3 = completeSignedLowWord;
            MATCHING_KEEP_CLOBBER(rawSampleProductOrField3, "memory");
            argumentSampleAddressOrMagic4 = *firstSampleAddress5;
            rawSampleProductOrField3 >>= 12;
            {
                long long originalCompleteProduct1 =
                    (long long)rawSampleProductOrField3 * (long long)argumentSampleAddressOrMagic4;
                __asm__("" : "=l"(completeSignedLowWord) : "x"(originalCompleteProduct1));
            }
            retainedTimerAngleOrAddress16 += retainedSignedTableBase;
            rawSampleProductOrField3 = completeSignedLowWord;
            MATCHING_KEEP_CLOBBER(rawSampleProductOrField3, "memory");
            rawSampleProductOrField3 >>= 12;
            Level21_82100Field(firstCreatedRecord19, int*, 0xC) = rawSampleProductOrField3;
            rawSampleProductOrField3 = *(short*)retainedTimerAngleOrAddress16;
            {
                long long originalCompleteProduct2 =
                    (long long)rawSampleProductOrField3 * (long long)rawResultSpeedSignOrQuotient2;
                __asm__("" : "=l"(completeSignedLowWord) : "x"(originalCompleteProduct2));
            }
            rawSampleProductOrField3 = completeSignedLowWord;
            MATCHING_KEEP_CLOBBER(rawSampleProductOrField3, "memory");
            argumentSampleAddressOrMagic4 = *firstSampleAddress5;
            rawSampleProductOrField3 >>= 12;
            {
                long long originalCompleteProduct3 =
                    (long long)rawSampleProductOrField3 * (long long)argumentSampleAddressOrMagic4;
                __asm__("" : "=l"(completeSignedLowWord) : "x"(originalCompleteProduct3));
            }
            retainedAngleOrAddress17 += retainedSignedTableBase;
            rawSampleProductOrField3 = completeSignedLowWord;
            MATCHING_KEEP_CLOBBER(rawSampleProductOrField3, "memory");
            rawSampleProductOrField3 >>= 12;
            Level21_82100Field(firstCreatedRecord19, int*, 0x10) = rawSampleProductOrField3;
            rawSampleProductOrField3 = *(short*)retainedAngleOrAddress17;
            {
                long long originalCompleteProduct4 =
                    (long long)rawSampleProductOrField3 * (long long)rawResultSpeedSignOrQuotient2;
                __asm__("" : "=l"(completeSignedLowWord) : "x"(originalCompleteProduct4));
                rawSampleProductOrField3 = completeSignedLowWord;
                MATCHING_KEEP(rawSampleProductOrField3);
            }
        }
        {
            long long completeOriginalDivision;
            int capturedCompleteHigh;
            rawResultSpeedSignOrQuotient2 = Level21_82100Field(firstCreatedRecord19, int*, 12) * 2;
            completeOriginalDivision =
                (long long)rawResultSpeedSignOrQuotient2 * (long long)(0x55555556);
            rawSampleProductOrField3 >>= 12;
            rawResultSpeedSignOrQuotient2 >>= 31;
            __asm__(""
                    : "=r"(rawResultSpeedSignOrQuotient2)
                    : "0"(rawResultSpeedSignOrQuotient2), "r"(rawSampleProductOrField3)
                    : "memory");
            Level21_82100Field(firstCreatedRecord19, int*, 20) = rawSampleProductOrField3;
            __asm__(""
                    : "=h"(capturedCompleteHigh)
                    : "x"(completeOriginalDivision),
                      "m"(Level21_82100Field(firstCreatedRecord19, int*, 20)));
            tableAddressOrCapturedHigh8 = capturedCompleteHigh;
            MATCHING_KEEP(tableAddressOrCapturedHigh8);
            rawResultSpeedSignOrQuotient2 =
                tableAddressOrCapturedHigh8 - rawResultSpeedSignOrQuotient2;
            MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
            Level21_82100Field(firstCreatedPrivate18, int*, 4) = rawResultSpeedSignOrQuotient2;
        }
        Level21_82100Field(firstCreatedPrivate18, int*, 8) =
            (int)Level21_82100SignedThird(Level21_82100Field(firstCreatedRecord19, int*, 0x10) * 2);
        argumentSampleAddressOrMagic4 = firstCreatedRecord19 + 0xC;
        MATCHING_KEEP(argumentSampleAddressOrMagic4);
        Level21_82100Field(firstCreatedPrivate18, int*, 0xC) =
            (int)Level21_82100SignedThird(Level21_82100Field(firstCreatedRecord19, int*, 0x14) * 2);
        Level21_82100AddVectorView1(argumentSampleAddressOrMagic4, argumentSampleAddressOrMagic4,
                                    ownerRecord20 + 0xC);
        rawResultSpeedSignOrQuotient2 = Level21_82100DatarandView1() & 1;
        MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
        if (rawResultSpeedSignOrQuotient2 != 0)
            rawResultSpeedSignOrQuotient2 = 0x3AF80000;
        else
            rawResultSpeedSignOrQuotient2 = 0x3C5F0000;
        MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
    block_11:
        Level21_82100Field(firstCreatedRecord19, int*, 0x54) = rawResultSpeedSignOrQuotient2;
    block_12:
        firstCreatedIndex23 += 1;
    } while (firstCreatedIndex23 < 0x10);
block_13:
    Level21_82100Call36A68View1(ownerRecord20, 0x10, 0, 0);
    Level21_82100Call38BF8View1(ownerRecord20, privateRecord21 + 0x24, 7, 1);
    rawResultSpeedSignOrQuotient2 = Level21_82100RandSignedBetweenView1(12, 15);
    rawSampleProductOrField3 = (unsigned int)rawResultSpeedSignOrQuotient2 >> 31;
    rawSampleProductOrField3 += rawResultSpeedSignOrQuotient2;
    rawSampleProductOrField3 >>= 1;
    rawSampleProductOrField3 &= 15;
    MATCHING_KEEP(rawSampleProductOrField3);
    rawResultSpeedSignOrQuotient2 = 50;
    Level21_82100Field(privateRecord21, short*, 42) = rawResultSpeedSignOrQuotient2;
    rawResultSpeedSignOrQuotient2 = 240;
    Level21_82100Field(privateRecord21, signed char*, 59) = rawSampleProductOrField3;
    Level21_82100Field(privateRecord21, unsigned char*, 58) = rawResultSpeedSignOrQuotient2;
block_14:
    if ((Level21_82100Data6C54CView1 - 1) != &Level21_82100Data8F6A0View1) {
        goto block_17;
    }
    if (Level21_82100Data6C774View1 == 0) {
        goto block_17;
    }
    Level21_82100Data6580CView1 = 2;
    Level21_82100Data65834View1 = 2;
    Level21_82100Data71597View1 = 0;
block_17:
    temp_v1_2 = Level21_82100Field(ownerRecord20, unsigned char*, 0x48);
    if (temp_v1_2 == 0) {
        goto block_20;
    }
    if (temp_v1_2 == 1) {
        goto block_23;
    }
    return;
block_20:
    if (Level21_82100Field(privateRecord21, int*, 0x3C) == 0) {
        goto block_22;
    }
    Level21_82100Field(ownerRecord20, unsigned char*, 0x4A) = 0xFF;
    Level21_82100Field(ownerRecord20, signed char*, 0x41) = 0;
    Level21_82100Field(ownerRecord20, signed char*, 0x4C) = 0;
    Level21_82100Field(ownerRecord20, signed char*, 0x4D) = 0;
    Level21_82100Field(ownerRecord20, int*, 8) = 0;
    Level21_82100Field(ownerRecord20, unsigned char*, 0x48) = 0xAU;
    return;
block_22:
    {
        register int callbackArgumentWord5 __asm__("$5"), callbackArgumentWord6 __asm__("$6");
        argumentSampleAddressOrMagic4 = (int)ownerRecord20;
        callbackArgumentWord6 = (int)privateRecord21 + 20;
        callbackArgumentWord5 = Level21_82100Field(privateRecord21, int*, 0);
        rawSampleProductOrField3 = (int)Level21_82100Data743E8View1;
        __asm__(""
                : "=r"(rawSampleProductOrField3)
                : "0"(rawSampleProductOrField3), "r"(argumentSampleAddressOrMagic4),
                  "r"(callbackArgumentWord5), "r"(callbackArgumentWord6));
        rawResultSpeedSignOrQuotient2 = 230;
        Level21_82100Field(privateRecord21, short*, 24) = rawResultSpeedSignOrQuotient2;
        ((int (*)(void*, int, void*))rawSampleProductOrField3)(
            argumentSampleAddressOrMagic4, callbackArgumentWord5, callbackArgumentWord6);
    }
    Level21_82100RefreshMobySpatialGridAndBasisView1(ownerRecord20, 6);
    return;
block_23:
    if (Level21_82100Field(privateRecord21, short*, 0x2A) >= 0) {
        goto block_30;
    }
    if (Level21_82100Data6C640View1 & 3) {
        goto block_30;
    }
    secondCreatedRecord19 = Level21_82100DataSpawnMobyView1(0x2DD, ownerRecord20);
    if (secondCreatedRecord19 == 0) {
        goto block_29;
    }
    argumentSampleAddressOrMagic4 = 0;
    MATCHING_KEEP(argumentSampleAddressOrMagic4);
    MATCHING_KEEP(secondCreatedRecord19);
    secondCreatedPrivate18 = Level21_82100Field(secondCreatedRecord19, void**, 0);
    Level21_82100Field(secondCreatedRecord19, signed char*, 0x4C) = 0x50;
    Level21_82100Field(secondCreatedRecord19, signed char*, 0x4E) = 0x50;
    retainedTimerAngleOrAddress16 =
        Level21_82100RandBetweenView1(argumentSampleAddressOrMagic4, 0xFF);
    retainedAngleOrAddress17 = Level21_82100RandBetweenView1(0, 0xFF);
    rawResultSpeedSignOrQuotient2 = Level21_82100RandBetweenView1(0, 0x384);
    {
        register int secondSampleOrArgument5 __asm__("$5");
        long long completeProduct;
        retainedTimerAngleOrAddress16 = retainedTimerAngleOrAddress16 * 2;
        rawSampleProductOrField3 =
            *(short*)(&Level21_82100Data65920View1 + retainedTimerAngleOrAddress16);
        MATCHING_KEEP(rawSampleProductOrField3);
        completeProduct =
            (long long)rawSampleProductOrField3 * (long long)rawResultSpeedSignOrQuotient2;
        __asm__("" : "=l"(completeSignedLowWord) : "x"(completeProduct));
        argumentSampleAddressOrMagic4 = (int)&Level21_82100Data65920View1;
        retainedAngleOrAddress17 = retainedAngleOrAddress17 * 2;
        argumentSampleAddressOrMagic4 += retainedAngleOrAddress17;
        MATCHING_KEEP(argumentSampleAddressOrMagic4);
        rawSampleProductOrField3 = completeSignedLowWord;
        MATCHING_KEEP(rawSampleProductOrField3);
        secondSampleOrArgument5 = *(short*)argumentSampleAddressOrMagic4;
        rawSampleProductOrField3 >>= 12;
        completeProduct = (long long)rawSampleProductOrField3 * (long long)secondSampleOrArgument5;
        __asm__("" : "=l"(completeSignedLowWord) : "x"(completeProduct));
        rawSampleProductOrField3 = completeSignedLowWord;
        MATCHING_KEEP(rawSampleProductOrField3);
        rawSampleProductOrField3 >>= 12;
        Level21_82100Field(secondCreatedRecord19, int*, 12) = rawSampleProductOrField3;
        rawSampleProductOrField3 =
            *(short*)(&Level21_82100Data658A0View1 + retainedTimerAngleOrAddress16);
        MATCHING_KEEP(rawSampleProductOrField3);
        completeProduct =
            (long long)rawSampleProductOrField3 * (long long)rawResultSpeedSignOrQuotient2;
        __asm__("" : "=l"(completeSignedLowWord) : "x"(completeProduct));
        rawSampleProductOrField3 = completeSignedLowWord;
        MATCHING_KEEP(rawSampleProductOrField3);
        argumentSampleAddressOrMagic4 = *(short*)argumentSampleAddressOrMagic4;
        rawSampleProductOrField3 >>= 12;
        completeProduct =
            (long long)rawSampleProductOrField3 * (long long)argumentSampleAddressOrMagic4;
        __asm__("" : "=l"(completeSignedLowWord) : "x"(completeProduct));
        rawSampleProductOrField3 = completeSignedLowWord;
        MATCHING_KEEP(rawSampleProductOrField3);
        rawSampleProductOrField3 >>= 12;
        Level21_82100Field(secondCreatedRecord19, int*, 16) = rawSampleProductOrField3;
        rawSampleProductOrField3 =
            *(short*)(&Level21_82100Data658A0View1 + retainedAngleOrAddress17);
        MATCHING_KEEP(rawSampleProductOrField3);
        completeProduct =
            (long long)rawSampleProductOrField3 * (long long)rawResultSpeedSignOrQuotient2;
        __asm__("" : "=l"(completeSignedLowWord) : "x"(completeProduct));
        argumentSampleAddressOrMagic4 = 0x55550000;
        MATCHING_KEEP(argumentSampleAddressOrMagic4);
        rawSampleProductOrField3 = completeSignedLowWord;
        MATCHING_KEEP(rawSampleProductOrField3);
        argumentSampleAddressOrMagic4 |= 0x5556;
        {
            long long completeOriginalDivision;
            int capturedCompleteHigh;
            rawResultSpeedSignOrQuotient2 = Level21_82100Field(secondCreatedRecord19, int*, 12) * 2;
            completeOriginalDivision = (long long)rawResultSpeedSignOrQuotient2 *
                                       (long long)(argumentSampleAddressOrMagic4);
            rawSampleProductOrField3 >>= 12;
            rawResultSpeedSignOrQuotient2 >>= 31;
            __asm__(""
                    : "=r"(rawResultSpeedSignOrQuotient2)
                    : "0"(rawResultSpeedSignOrQuotient2), "r"(rawSampleProductOrField3)
                    : "memory");
            Level21_82100Field(secondCreatedRecord19, int*, 20) = rawSampleProductOrField3;
            __asm__(""
                    : "=h"(capturedCompleteHigh)
                    : "x"(completeOriginalDivision),
                      "m"(Level21_82100Field(secondCreatedRecord19, int*, 20)));
            tableAddressOrCapturedHigh8 = capturedCompleteHigh;
            MATCHING_KEEP(tableAddressOrCapturedHigh8);
            rawResultSpeedSignOrQuotient2 =
                tableAddressOrCapturedHigh8 - rawResultSpeedSignOrQuotient2;
            MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
            Level21_82100Field(secondCreatedPrivate18, int*, 4) = rawResultSpeedSignOrQuotient2;
        }
        Level21_82100Field(secondCreatedPrivate18, int*, 8) = Level21_82100SignedThirdWithMagic(
            Level21_82100Field(secondCreatedRecord19, int*, 16) * 2, argumentSampleAddressOrMagic4);
        {
            long long finalCompleteProduct;
            int finalCompleteHigh;
            rawResultSpeedSignOrQuotient2 = Level21_82100Field(secondCreatedRecord19, int*, 20) * 2;
            finalCompleteProduct =
                (long long)rawResultSpeedSignOrQuotient2 * (long long)argumentSampleAddressOrMagic4;
            argumentSampleAddressOrMagic4 = (int)secondCreatedRecord19 + 12;
            MATCHING_KEEP(argumentSampleAddressOrMagic4);
            secondSampleOrArgument5 = argumentSampleAddressOrMagic4;
            rawResultSpeedSignOrQuotient2 >>= 31;
            __asm__("" : "=h"(finalCompleteHigh) : "x"(finalCompleteProduct));
            tableAddressOrCapturedHigh8 = finalCompleteHigh;
            MATCHING_KEEP(tableAddressOrCapturedHigh8);
            rawResultSpeedSignOrQuotient2 =
                tableAddressOrCapturedHigh8 - rawResultSpeedSignOrQuotient2;
            MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
            Level21_82100Field(secondCreatedPrivate18, int*, 12) = rawResultSpeedSignOrQuotient2;
        }
        Level21_82100AddVectorView1(argumentSampleAddressOrMagic4, secondSampleOrArgument5,
                                    ownerRecord20 + 12);
    }
    rawResultSpeedSignOrQuotient2 = Level21_82100DatarandView1() & 1;
    MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
    if (rawResultSpeedSignOrQuotient2 != 0)
        rawResultSpeedSignOrQuotient2 = 0x3AF80000;
    else
        rawResultSpeedSignOrQuotient2 = 0x3C5F0000;
    MATCHING_KEEP(rawResultSpeedSignOrQuotient2);
block_28:
    Level21_82100Field(secondCreatedRecord19, int*, 0x54) = rawResultSpeedSignOrQuotient2;
block_29:
block_30:
    if (Level21_82100Call35194View1(ownerRecord20, privateRecord21 + 0x24) != 0x100) {
        goto block_32;
    }
    Level21_82100RefreshMobySpatialGridAndBasisView1(ownerRecord20, 4);
    Level21_82100Call3BA00View1(ownerRecord20);
    Level21_82100Call369B8View1(ownerRecord20, 0x30);
    Level21_82100DeleteMobyView1(ownerRecord20);
block_32:
    return;
}
#undef Level21_82100Field
#undef Level21_82100SignedThird
#undef Level21_82100SignedThirdWithMagic

typedef struct {
    int timer;
    Vector3D velocity;
} DecodedWobbleTag;
extern unsigned short DecodedWobbleSin[] __asm__("D_800658A0");
extern unsigned short DecodedWobbleCos[] __asm__("D_80065920");
void func_level_21_8008270C(Moby* moby) {
    DecodedWobbleTag* tag = moby->mobyTag;
    Vector3D offset;
    int pitch, radius, fall;
    if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400 ||
        func_800359A4(&tag->timer, 4)) {
        func_80055B18(moby);
        return;
    }
    pitch = (short)DecodedWobbleSin[(tag->timer * 4) & 0xFC] >> 7;
    moby->angle.pitch = pitch;
    if (moby->mobyClass != 0x2DA)
        moby->angle.pitch = pitch + 0x40;
    radius = (short)DecodedWobbleSin[(tag->timer * 4) & 0xFC] >> 8;
    offset.x = (short)DecodedWobbleCos[moby->angle.yaw] * radius >> 12;
    offset.y = (short)DecodedWobbleSin[moby->angle.yaw] * radius >> 12;
    offset.z = 0;
    fall = (short)DecodedWobbleCos[(tag->timer * 4) & 0xFC] >> 8;
    offset.z = -ABS(fall);
    func_8004F194(&moby->position, &moby->position, &offset);
    func_8004F194(&moby->position, &moby->position, &tag->velocity);
    func_8004F1FC(&tag->velocity, &tag->velocity, 0xC0);
    func_8004F110(&tag->velocity, 8);
}

extern unsigned char D_80066BC8[];
extern short D_800719DC;
extern short D_80065920[], D_800658A0[];
int func_80036220(Vector3D*, void*, int, int);
void func_80055B18(Moby*);
/* Rev0 800828BC..80082A6C: level34 flag/height trigger baseline,
 * with this overlay's radius600, global byte5 and Z-before-Y store order.
 * Raw offsets and arithmetic are instruction-backed; units, caller cadence,
 * bounds-helper meaning and complete sound descriptor chain remain open. */
void func_level_21_800828BC(Moby* moby) {
    register void* privateData __asm__("$16") = moby->mobyTag;
    register int* playerFlag __asm__("$18");
    register Vector3D* player __asm__("$19");
    register int playerZ __asm__("$3");
    register int threshold __asm__("$2");
    if (moby->state == 0) {
        playerFlag = (int*)((char*)&spyro + 0xB8);
        player = (Vector3D*)((char*)playerFlag - 0xB8);
        if (*playerFlag)
            return;
        if (!func_80036220(player, privateData, 0, 600))
            return;
        playerZ = spyro.position.z;
        MATCHING_KEEP_CLOBBER(playerZ, "memory");
        threshold = ((int*)privateData)[2];
        if (threshold >= playerZ)
            return;
        D_80066BC8[5] = 3;
        D_800719DC = 1;
        PlaySound(((unsigned char*)D_8006C654)[0x23], moby, 0xA1);
        privateData = SpawnMoby(0xD3, moby);
        if (privateData) {
            Moby* child = privateData;
            int sine;
            func_8004F178(&child->position, player);
            MATCHING_KEEP_CLOBBER(playerFlag, "memory");
            child->position.x += (D_80065920[*((unsigned char*)playerFlag - 0xAA)] * 25) >> 7;
            MATCHING_BARRIER("memory");
            sine = D_800658A0[*((unsigned char*)playerFlag - 0xAA)];
            child->position.z += 500;
            child->position.y += (sine * 25) >> 7;
        }
        moby->state = 1;
    } else {
        privateData = &moby->state;
        func_8003B7B4(privateData, 1, &savedData);
        func_8003B7B4(privateData, 1, &unsavedData);
        func_80055B18(moby);
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
void func_level_21_80082A6C(Moby* actor) {
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
void func_level_21_80082D18(Moby* input) {
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
extern void (*EventVectorRequest)(int, Vector3D*) __asm__("unk_ovlheader_800743F4");
extern unsigned char EventPlayer[] __asm__("D_80070328");
extern int EventQueryWord __asm__("D_80071924");
extern int EventPlayerZ __asm__("D_80070328 + 8");
extern int EventPlayerVelocityZ __asm__("D_80070328 + 0x94");
extern int EventPlayerRequest __asm__("D_80070328 + 0x20C");
extern int EventPlayerMode __asm__("D_80070328 + 0x23C");
int EventQuery(Vector3D*, int) __asm__("func_8001A358");
void EventZero(Vector3D*) __asm__("func_8004F168");
/* SCUS-94467 USA Rev0 80083124..800836C0, 360 original words.
 * Reuses verified func_level_13_80082590. Raw tag+18==1 adds the
 * original player+50==15, query result/Z/velocity and word-mask gates,
 * vector callback, request0x10000080/mode7 and ordered zeroing.
 * Nonzero Moby substate reaches the original standard timer branch.
 * The finish path retains the original vector callback and target9 call.
 * Widths, constants and post-helper reads remain retail. Units, complete
 * producer/helper semantics and caller cadence remain open.
 * Empty constraints preserve compiler allocation and emit no instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1708.
 */
void func_level_21_80083124(Moby* argument) {
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
            if (tag->reserved18 == 1) {
                register int* playerMode __asm__("$16");
                register int* queryWord __asm__("$17");
                int result;
                MATCHING_KEEP(state);
                if (!DecodedEventTick) {
                    offset.x = 0;
                    offset.y = 0;
                    offset.z = 0;
                    EventVectorRequest(0, &offset);
                }
                playerMode = (int*)(EventPlayer + 0x50);
                if (*playerMode != 15)
                    return;
                queryWord = &EventQueryWord;
                *queryWord = 255;
                result = EventQuery((Vector3D*)((char*)playerMode - 0x50), 2000);
                if (!result || EventPlayerZ - result >= 1100 || EventPlayerVelocityZ >= 0 ||
                    (*queryWord & 63) != 10)
                    return;
                moby->state = 1;
                DecodedEventTimer(&moby->state, 1, DecodedEventTimerData);
                EventPlayerRequest = 0x10000080;
                EventPlayerMode = 7;
                EventZero((Vector3D*)((char*)playerMode + 0x3C));
                return;
            }
            if (moby->substate) {
                moby->state = 1;
                goto standardTimer;
            }
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
            standardTimer:
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
            if (tag->reserved18 == 1) {
                offset.x = 0;
                offset.y = 0;
                offset.z = 0x2000;
                EventVectorRequest(0, &offset);
                DecodedEventTarget(9, 0xFC, 0);
                EventZero((Vector3D*)(EventPlayer + 0x8C));
            }
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
void func_level_21_800836C4(Moby* moby) {
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
void func_level_21_800839F4(Moby* actor) {
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
void func_level_21_80083C00(Moby* argument) {
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
void func_level_21_80084128(void* input) {
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

void func_level_21_8008527C(Moby* moby) {
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
void func_level_21_8008529C(Moby* argument) {
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
