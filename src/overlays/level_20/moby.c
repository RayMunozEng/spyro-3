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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Controller74C50Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller74C50TestSubdividedSegmentPath(void*, void*, int) __asm__("func_80013E38");
int Controller74C50QueryWorldSphere(void*, int) __asm__("func_80019194");
int Controller74C50QueryWorldHeight(void*, int) __asm__("func_8001A358");
void* Controller74C50AllocatePoolRecord16(int) __asm__("func_8002F040");
int Controller74C50WriteGlobalVectorAnglePair(void*) __asm__("func_80036188");
int Controller74C50AwardMobyCollectionValue(void*) __asm__("func_80036E60");
int Controller74C50SetMobyZFromGroundProbe(void*) __asm__("func_80037014");
int Controller74C50PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller74C50SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Controller74C50PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller74C50TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller74C50MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Controller74C50ComputeVectorPlaneResponse(void*, void*, void*) __asm__("func_8004EF74");
int Controller74C50ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller74C50CopyVector(void*, void*) __asm__("func_8004F178");
int Controller74C50AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller74C50SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Controller74C50MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Controller74C50DivideVector(void*, void*, int) __asm__("func_8004F228");
int Controller74C50AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller74C50ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller74C50ExpandUnsignedHalfwordVectorTimes4(void*, void*) __asm__("func_8004F52C");
int Controller74C50DecodePackedTriangleVertices(int, void*) __asm__("func_8004F5DC");
int Controller74C50DeleteMoby(void*) __asm__("func_80055B18");
int Controller74C50RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller74C50RefreshMobyQueryByte52(void*) __asm__("func_80056270");
int Controller74C50RefreshMobyPackedQueryField(void*) __asm__("func_8005629C");
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
int Controller74C50SpawnSurfaceType4LinkedMoby(void*, void*) __asm__("func_800399E8");
int Controller74C50UpdateLinkedMobyReflection(void*, void*) __asm__("func_80039B6C");
void func_level_20_80074E2C(void* input) {
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
    register void* stateThreeVector __asm__("$17");
    register void* stateThreeDelta __asm__("$16");
    register void* stateTwoNormal __asm__("$21");
    register int temp_v0 __asm__("$2");
    register int temp_v0_4 __asm__("$2");
    register unsigned char* resourceRecord __asm__("$16");
    register unsigned char* workingPosition __asm__("$17");
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
    register unsigned char* tag __asm__("$19");
    register unsigned char* callbackTag __asm__("$17");
    register void* originalCallback6 __asm__("$6");
    void* callbackOwnerReference;
    void* temp_v1_6;

    workingPosition = owner + 0xC;
    tag = ((Moby*)owner)->mobyTag;
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
                    ((Moby*)owner)->position.x - Controller74C50D_8006E020,
                    ((Moby*)owner)->position.y - Controller74C50D_8006E024, 0)) < 0x20) {
            selectedResource = Controller74C50AllocatePoolRecord16(((Moby*)owner)->substate);
        }
        if (selectedResource != 0) {
            if (distanceResult < 0x3000) {
                Controller74C50Field(tag, unsigned char*, 0x13) =
                    (unsigned char)((int)(selectedResource - Controller74C50D_8006DEF8) >> 4);
                Controller74C50Field(tag, short*, 0xA) =
                    (short)((unsigned short)Controller74C50Field(tag, short*, 0xA) - 0x20);
                Controller74C50Field(tag, unsigned char*, 0x14) =
                    (unsigned char)((((Moby*)owner)->substate * 2) + (rand() & 1));
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
    if ((((Moby*)owner)->drawn != 0) || (distanceResult < 0x1801) || (((Moby*)owner)->state != 1) ||
        (Controller74C50Field(tag, unsigned char*, 0x11) != 0)) {
        if (((Moby*)owner)->position.z < 0x401) {
            Controller74C50CopyVector(owner + 0xC, Controller74C50D_80070328);
        }
        if (((Moby*)owner)->state == 125)
            return;
        if (Controller74C50Field(tag, int*, 0) == 0)
            Controller74C50SpawnSurfaceType4LinkedMoby(owner, tag);
        temp_v1 = ((Moby*)owner)->state;
        switch (temp_v1) { /* switch 1; irregular */
            case 0:        /* switch 1 */
                Controller74C50CopyVector(&frame.first.x, owner + 0xC);
                frame.first.z += 0x400;
                Controller74C50QueryWorldHeight(&frame.first.x, 0x10000);
                Controller74C50WriteGlobalVectorAnglePair(tag + 0xE);
                if (Controller74C50Field(tag, int*, 0xC) & 0xFFFF0000) {
                    ((Moby*)owner)->angle.yaw = 0U;
                }
                ((Moby*)owner)->position.z = (int)Controller74C50D_80071908;
                Controller74C50Field(tag, short*, 0xA) = (short)((rand() & 0xFF) + 0x100);
                ((Moby*)owner)->state = 1U;
                temp_v0_2 = *(Controller74C50D_80066964 + ((Moby*)owner)->gemValue);
                ((Moby*)owner)->substate = temp_v0_2;
                ((Moby*)owner)->animationState.id =
                    (unsigned char)*(Controller74C50D_80066988 + (temp_v0_2 & 0xFF));
                ((Moby*)owner)->colour.r =
                    (unsigned char)*(Controller74C50D_80066990 + ((Moby*)owner)->substate);
                goto block_75;
            case 1: /* switch 1 */
                temp_v1_2 = Controller74C50Field(tag, unsigned char*, 0x11);
                if (temp_v1_2 == 0)
                    goto stateOneTail;
                if (temp_v1_2 == 1) {
                    Controller74C50SetMobyZFromGroundProbe(owner);
                    Controller74C50WriteGlobalVectorAnglePair(tag + 0xE);
                    goto stateOneTail;
                }
                if (temp_v1_2 == 2) {
                    Controller74C50DecodePackedTriangleVertices(
                        (short)Controller74C50Field(tag, int*, 0xC), &frame.second.x);
                    Controller74C50AddVector(&frame.second.x, &frame.second.x, &frame.third.x);
                    Controller74C50AddVector(&frame.second.x, &frame.second.x, &frame.fourth.x);
                    Controller74C50DivideVector(&frame.second.x, &frame.second.x, 3);
                    Controller74C50RefreshMobySpatialGridAndBasis(owner, 2);
                    Controller74C50SetMobyZFromGroundProbe(owner);
                    goto stateOneTail;
                }
                Controller74C50CopyVector(&frame.fifth.x, owner + 0xC);
                frame.fifth.z += 0x400;
                if (Controller74C50QueryWorldHeight(&frame.fifth.x, 0x1000) > 0) {
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
                                    ((Moby*)owner)->position.z;
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
                    Controller74C50AwardMobyCollectionValue(owner);
                    Controller74C50DeleteMoby(owner);
                    return;
                }
                frame.fifth.z += 0xF0;
                if (Controller74C50QueryWorldSphere(workingPosition, 0xF0) != 0) {
                    stateTwoNormal = &frame.sixth.x;
                    MATCHING_KEEP(stateTwoNormal);
                    Controller74C50CopyVector(stateTwoNormal, Controller74C50D_80071918);
                    Controller74C50CopyVector(ownerPosition, Controller74C50D_80071918 - 0xC);
                    ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z - 0xF0);
                    if (Controller74C50Field(tag, unsigned char*, 0x12) == 0) {
                        {
                            register int height __asm__("$2") =
                                Controller74C50QueryWorldHeight(workingPosition, 0x400);
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
                            ((Moby*)owner)->state = 1U;
                            Controller74C50CopyVector(ownerPosition, workingPosition);
                            ((Moby*)owner)->position.z = sampledHeight;
                            Controller74C50WriteGlobalVectorAnglePair(tag + 0xE);
                            if (Controller74C50Field(tag, int*, 0xC) & 0xFFFF0000) {
                                ((Moby*)owner)->angle.yaw = 0U;
                            }
                            Controller74C50Field(owner, signed char*, 0x52) = 0;
                            Controller74C50RefreshMobyQueryByte52(owner);
                            Controller74C50RefreshMobyPackedQueryField(owner);
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
                        if (Controller74C50ComputeVectorPlaneResponse(
                                &frame.seventh.x, &frame.sixth.x, &frame.seventh.x) != 0) {
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
                    Controller74C50QueryWorldHeight(workingPosition, 0x10000);
                    Controller74C50RefreshMobyPackedQueryField(owner);
                }
                MATCHING_BARRIER_VOLATILE("memory");
                if (Controller74C50Field(tag, short*, 0xA) >= 0x1E) {
                    MATCHING_KEEP_VOLATILE_CLOBBER(distanceResult, "$5");
                    temp_a0_2 = Controller74C50Field(Controller74C50D_80070328, int*, 0x44) + 0x80;
                    if (distanceResult < temp_a0_2) {
                        temp_v1_4 = Controller74C50Field(Controller74C50D_80070328, int*, 8) -
                                    ((Moby*)owner)->position.z;
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
                Controller74C50ExpandUnsignedHalfwordVectorTimes4(stateThreeVector, tag + 4);
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
                        ((Moby*)owner)->position.z =
                            (int)(((Moby*)owner)->position.z +
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
                    old = ((Moby*)owner)->angle.roll;
                    offset += 249;
                    old += offset;
                    ((Moby*)owner)->angle.roll = old;
                }
                {
                    register int offset __asm__("$2") =
                        Controller74C50Field(tag, unsigned char*, 0xF);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = ((Moby*)owner)->angle.pitch;
                    offset += 249;
                    old += offset;
                    ((Moby*)owner)->angle.pitch = old;
                }
                {
                    register int offset __asm__("$2") =
                        Controller74C50Field(tag, unsigned char*, 0x10);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = ((Moby*)owner)->angle.yaw;
                    offset += 249;
                    old += offset;
                    ((Moby*)owner)->angle.yaw = old;
                }
                if ((Controller74C50Field(tag, short*, 0xA) < 0xF) ||
                    (temp_a0_3 = Controller74C50Field(Controller74C50D_80070328, int*, 0x44) + 0x80,
                     ((distanceResult < temp_a0_3) == 0)) ||
                    (temp_v1_5 = Controller74C50Field(Controller74C50D_80070328, int*, 8) -
                                 ((Moby*)owner)->position.z,
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
                ((Moby*)owner)->state = 4;
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
                    selector = ((Moby*)owner)->substate;
                    emit(type, subtype, owner, selector);
                }
                Controller74C50AwardMobyCollectionValue(owner);
                Controller74C50PlayMobySoundEvent(owner, 0, 0);
                Controller74C50DeleteMoby(owner);
                goto block_75;
        }
    block_75:
        if ((unsigned char)((Moby*)owner)->state < 3U) {

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
                ((Moby*)owner)->angle.roll = sample;
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
                ((Moby*)owner)->angle.pitch = sample;
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
                    register int height __asm__("$3") = ((Moby*)owner)->position.z;
                    register int playerZ __asm__("$2") =
                        Controller74C50Field(Controller74C50D_80070328, int*, 8);
                    MATCHING_KEEP2(height, playerZ);
                    height += 356;
                    var_v0 = playerZ - height;
                }
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < var_a0) && ({
                        originalCallback6 = Controller74C50D_8006C65C;
                        MATCHING_KEEP(originalCallback6);
                        originalCallback6 != 0;
                    }) &&
                    ((((Moby*)owner)->state != 2) ||
                     ((unsigned char)Controller74C50Field(tag, unsigned char*, 0x12) < 3U)) &&
                    (callbackTag = Controller74C50Field(originalCallback6, void**, 0),
                     Controller74C50CopyVector(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64,
                     (Controller74C50TestSubdividedSegmentPath(Controller74C50D_8006C65C + 0xC,
                                                               &frame.ninth.x, 0) != 0))) {
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
                            if (Controller74C50SoundHandleMatchesOwnerInStates1Or2(callbackOwner,
                                                                                   selector) == 0) {
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
            Controller74C50UpdateLinkedMobyReflection(owner, tag);
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
void func_level_20_80075ACC(Moby* mobyArgument) {
    Vector3D candidatePosition;
    register Moby* moby __asm__("$17") = mobyArgument;
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
int Controller75F38QueryWorldSphere(void*, int) __asm__("func_80019194");
void* Controller75F38AllocatePoolRecord20(int, int, int) __asm__("func_8002EC50");
int Controller75F38RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller75F38EmptyAnimationTransitionHook(void*, int) __asm__("func_80035734");
int Controller75F38TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Controller75F38CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller75F38ApproachAngle8(int, int, int) __asm__("func_80036018");
unsigned int Controller75F38RandBetween(int, int) __asm__("func_8003636C");
int Controller75F38PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller75F38SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Controller75F38PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller75F38GetLeadingTransitionIndex(int) __asm__("func_8004EA74");
int Controller75F38TransposePackedHalfwordMatrix3x3(void*, void*) __asm__("func_8004ECF4");
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
int Controller75F38ExpandSignedHalfwordVector(void*, void*) __asm__("func_8004F554");
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
int Controller75F38SpawnSurfaceType4LinkedMoby(void*, void*) __asm__("func_800399E8");
int Controller75F38UpdateLinkedMobyReflection(void*, void*) __asm__("func_80039B6C");
void func_level_20_80076158(void* input) {
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
        tag = ((Moby*)owner)->mobyTag;
        __asm__("" : "=r"(tag) : "0"(tag) : "$2", "memory");
        {
            register int gate __asm__("$2") = ((Moby*)owner)->state;
            MATCHING_KEEP(gate);
            originalAngle = ((Moby*)owner)->angle.yaw;
            if (gate == gateValue)
                return;
        }
    }
    if (Controller75F38Field(tag, void**, 0x18) == 0)
        Controller75F38SpawnSurfaceType4LinkedMoby(owner, (unsigned char*)tag + 0x18);
    if (((unsigned int)(Controller75F38Field(Controller75F38D_80070328, int*, 0x50) - 0xB) < 2U) &&
        (Controller75F38Field(tag, unsigned char*, 0xA) == 0) && (((Moby*)owner)->drawn != 0)) {
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
        (((Moby*)owner)->drawn != 0)) {
        {
            register void* particleVector __asm__("$17") = &frame.second.x;
            register void* first __asm__("$4") = particleVector;
            register int angleIndex __asm__("$3") = ((Moby*)owner)->angle.yaw;
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
        (((Moby*)owner)->lowDrawDistance != 0)) {
        if (Controller75F38Field(tag, void**, 0x10) == 0) {
            Controller75F38Field(tag, void**, 0x10) =
                Controller75F38AllocatePoolRecord20(1, 0x40, 0x489090);
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
        temp_v1_6 = ((Moby*)owner)->substate;
        switch (temp_v1_6) { /* switch 1 */
            case 0:          /* switch 1 */
                temp_s1_2 = ((Moby*)owner)->animationState.nextId;
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
                    if ((unsigned char)((Moby*)owner)->animationState.nextFrame >= 7U) {
                        ((Moby*)owner)->substate = (unsigned char)(((Moby*)owner)->substate + 1);
                    }
                    temp_a0_3 = ((Moby*)owner)->angle.pitch;
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
                        ((Moby*)owner)->angle.pitch = var_v0_3;
                    }
                }
                temp_s0_2 = (unsigned char*)&frame.third.x;
                MATCHING_KEEP(temp_s0_2);
                Controller75F38SubtractVector(temp_s0_2, temp_s0_2, owner + 12);
                temp_s0 = Controller75F38MeasureVectorLength(temp_s0_2, 1);
                if ((temp_s1_2 == 0) && (Controller75F38CountTimerDown(tag, 2) != 0)) {
                    MATCHING_KEEP_VOLATILE(temp_s1_2);
                    if (Controller75F38SoundHandleMatchesOwnerInStates1Or2(
                            owner, Controller75F38Field(tag, unsigned char*, 2)) == 0) {
                        Controller75F38Field(tag, unsigned char*, 2) =
                            Controller75F38PlayMobySoundEvent(owner, 0, 0);
                    }
                    if (((Moby*)owner)->animationState.nextId != 1) {
                        Controller75F38D_8006C770 = 0;
                        temp_v1_7 = ((Moby*)owner)->animationState.nextId;
                        temp_a1_2 = ((Moby*)owner)->animationState.nextFrame;
                        Controller75F38Field(owner, signed char*, 0x40) = 0x72;
                        ((Moby*)owner)->animationState.nextId = 1U;
                        ((Moby*)owner)->animationState.nextFrame = 0U;
                        ((Moby*)owner)->animationState.id = temp_v1_7;
                        ((Moby*)owner)->animationState.frame = temp_a1_2;
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
                ((Moby*)owner)->substate = (unsigned char)(((Moby*)owner)->substate + 1);
                Controller75F38DeleteMoby(Controller75F38Field(tag, unsigned char**, 0x14));
                break;
            case 2: /* switch 1 */
                if (Controller75F38D_8006C770 != 0) {
                    register void* callbackOwner __asm__("$4") = owner;
                    if (((Moby*)owner)->animationState.nextId != 0) {
                        MATCHING_KEEP(callbackOwner);
                        Controller75F38D_8006C770 = 0;
                        temp_v0_7 = ((Moby*)owner)->animationState.nextId;
                        temp_a1_3 = ((Moby*)owner)->animationState.nextFrame;
                        {
                            register int value __asm__("$3");
                            MATCHING_KEEP2_CLOBBER(temp_v0_7, temp_a1_3, "$3");
                            value = 114;
                            MATCHING_KEEP(value);
                            ((Moby*)owner)->animationProgress = value;
                            ((Moby*)owner)->animationState.nextId = 0U;
                            ((Moby*)owner)->animationState.nextFrame = 0U;
                            ((Moby*)owner)->animationState.id = temp_v0_7;
                            ((Moby*)owner)->animationState.frame = temp_a1_3;
                            Controller75F38EmptyAnimationTransitionHook(callbackOwner, temp_a1_3);
                        }
                    }
                    ((Moby*)owner)->substate = 0U;
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
                ((Moby*)owner)->angle.pitch = temp_v0_4;
                ((Moby*)owner)->angle.pitch =
                    Controller75F38ApproachAngle8(temp_v0_4 & 0xFF, 0, 0x30);
                break;
            case 9: /* switch 1 */
                Controller75F38Field(tag, short*, 8) = 0x180;
                Controller75F38Field(tag, short*, 4) = 0;
                Controller75F38Field(tag, short*, 6) = 0;
                ((Moby*)owner)->substate = 5U;
                break;
        }
    } else if (Controller75F38Field(Controller75F38D_80065830, void**, 0) != 0) {
        Controller75F38SubtractVector(
            &frame.first.x, Controller75F38Field(Controller75F38D_80065830, void**, 0) + 0xC,
            Controller75F38D_80070328);
        if (Controller75F38D_80065828 >= 0x401) {
            if (Controller75F38D_80065828 >= 0x4001) {
                Controller75F38ShiftVectorRightTowardZero(
                    &frame.first.x,
                    Controller75F38GetLeadingTransitionIndex(Controller75F38D_80065828) - 0xE);
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
        ((Moby*)owner)->angle.pitch = Controller75F38PlanarHeadingLookup(
            Controller75F38MeasureVectorLength(&frame.first.x, 0), frame.first.z, 0);
        ((Moby*)owner)->angle.yaw = Controller75F38PlanarHeadingLookup(
            ((Moby*)owner)->position.x - Controller75F38Field(Controller75F38D_80070328, int*, 0),
            ((Moby*)owner)->position.y - Controller75F38Field(Controller75F38D_80070328, int*, 4),
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
        if (Controller75F38QueryWorldSphere(temp_s0_2, 0x100) != 0) {
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
                        Controller75F38TransposePackedHalfwordMatrix3x3(&frame.matrix[0],
                                                                        Controller75F38D_8006E00C);
                        Controller75F38ExpandSignedHalfwordVector(&frame.first.x, tag + 4);
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
                    if (Controller75F38QueryWorldSphere(temp_s0_5, 0x100) != 0) {
                        Controller75F38CopyVector(temp_s0_5, Controller75F38D_8007190C);
                    }
                    if (frame.first.z >= 0x21) {
                        frame.first.z = 0x20;
                    }
                    if (frame.first.z < -0x20) {
                        frame.first.z = -0x20;
                    }
                    Controller75F38Field(owner, signed char*, 0x44) = 0;
                    ((Moby*)owner)->angle.pitch = (unsigned char)frame.first.z;
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
                    Controller75F38ExpandSignedHalfwordVector(&frame.sixth.x, tag + 4);
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
                        ((Moby*)owner)->position.x = sample;
                        sample = *(short*)(Controller75F38D_800658A0 + temp_a1_4);
                        product = sample * adjustedMagnitude;
                        __asm__(""
                                : "=r"(sample), "=r"(vertical)
                                : "0"(sample), "1"(vertical)
                                : "$4", "$5");
                        vertical += playerZ;
                        movementPosition = ownerPosition;
                        __asm__("" : "=r"(movementPosition) : "0"(movementPosition) : "$2", "$5");
                        sample = ((Moby*)owner)->position.z;
                        MATCHING_KEEP_CLOBBER(sample, "$5");
                        movementRadius = 256;
                        MATCHING_KEEP3(sample, vertical, movementRadius);
                        vertical -= sample;
                        verticalStep = vertical >> 3;
                        sample = ((Moby*)owner)->position.z;
                        vertical = Controller75F38Field(Controller75F38D_80070328, int*, 4);
                        MATCHING_KEEP2(sample, vertical);
                        sample += verticalStep;
                        ((Moby*)owner)->position.z = sample;
                        MATCHING_BARRIER_VOLATILE("memory");
                        sample = (product >> 12) + vertical;
                        ((Moby*)owner)->position.y = sample;
                    }
                    if (Controller75F38QueryWorldSphere(movementPosition, movementRadius) != 0) {
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
                    ((Moby*)owner)->angle.pitch = (unsigned char)verticalStep;
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
                    ((Moby*)owner)->angle.yaw = var_v0_11;
                    break;
                case 3: /* switch 5 */
                {
                    register int angle __asm__("$2") = Controller75F38PlanarHeadingLookup(
                        Controller75F38D_8006E020 - ((Moby*)owner)->position.x,
                        Controller75F38D_8006E024 - ((Moby*)owner)->position.y, 0);
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
                                                ((Moby*)owner)->angle.yaw, 8, 0xA0,
                                                (int)Controller75F38Field(tag, unsigned char*, 0xC),
                                                0x80, 0xFF, 0xFF, 0, 0, 0) < 0) {
                        Controller75F38Field(tag, short*, 0) = 0;
                    }
                    {
                        register int ownerHeight __asm__("$2") = ((Moby*)owner)->position.z;
                        register int playerHeight __asm__("$3") =
                            Controller75F38Field(Controller75F38D_80070328, int*, 8);
                        MATCHING_KEEP2(ownerHeight, playerHeight);
                        ownerHeight -= 300;
                        playerHeight -= ownerHeight;
                        playerHeight >>= 2;
                        frame.first.z = playerHeight;
                        ownerHeight = ((Moby*)owner)->position.z;
                        ((Moby*)owner)->position.z = ownerHeight + playerHeight;
                    }
                    break;
            }
        }
    }
    if ((Controller75F38Field(tag, void**, 0x10) != 0) &&
        (((Moby*)owner)->angle.yaw != originalAngle)) {
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
    if ((((Moby*)owner)->animationState.nextId == 1) && (Controller75F38D_8006C770 != 0)) {
        Controller75F38RequestMobyAnimation(owner, 0);
    }
    temp_v0 = Controller75F38Field(tag, void**, 0x18);
    if (temp_v0 != 0) {
        Controller75F38UpdateLinkedMobyReflection(owner, (unsigned char*)tag + 0x18);
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
void func_level_20_800777F8(Moby* moby) {
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
void func_level_20_80077934(Moby* moby) {
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
void func_level_20_800779F0(Moby* moby) {
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
void func_level_20_80077AA4(Moby* moby) {
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
void func_level_20_80077D64(Moby* mobyArgument) {
    Vector3D particlePosition;
    int reservedStack[2];
    register Moby* moby __asm__("$17") = mobyArgument;
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
void func_level_20_80078284(Moby* moby) {
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
void func_level_20_80078604(Moby* moby) {
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
int Controller78288QueryWorldHeight(void*, int) __asm__("func_8001A358");
void* Controller78288AllocatePoolRecord20(int, int, int) __asm__("func_8002EC50");
void* Controller78288AllocatePoolRecord48(int, int, int) __asm__("func_8002F540");
int Controller78288RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller78288TurnMobyTowardPlayer(void*, int, int, int) __asm__("func_8003573C");
int Controller78288TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Controller78288UpdateMobyInteractionGate(void*, int) __asm__("func_80037BBC");
int Controller78288WriteTrackedSnapshot(void*, void*, int) __asm__("func_8003B634");
int Controller78288PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller78288SetClampedPlayerTargetAngles(void*) __asm__("func_800492DC");
int Controller78288PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller78288ShiftVectorLeft(void*, int) __asm__("func_8004F0E8");
int Controller78288ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller78288CopyVector(void*, void*) __asm__("func_8004F178");
int Controller78288AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller78288SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Controller78288DivideVector(void*, void*, int) __asm__("func_8004F228");
int Controller78288ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller78288StartDialogue(void*, int, int) __asm__("func_800512E4");
int Controller78288DeleteMoby(void*) __asm__("func_80055B18");
int Controller78288RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller78288ReadSelectedFrameScalar(void*) __asm__("func_80055E84");
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
extern unsigned char Controller78288D_80071596 __asm__("D_80071596");
extern int Controller78288D_8006C5BC __asm__("D_8006C5BC");
extern int Controller78288D_8006C73C __asm__("D_8006C73C");
int Controller78288ActivateSparxPowers() __asm__("ActivateSparxPowers");
int Controller78288BeginLevelWarp() __asm__("func_800584BC");
void func_level_20_80078908(void* input) {
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
        tag = ((Moby*)owner)->mobyTag;
        prefixTag = 0;
    } else {
        MATCHING_KEEP(owner);
        prefixTag = ((Moby*)owner)->mobyTag;
        tag = prefixTag + 0x2C;
    }
    ownerPositionWord = (int)(owner + 0xC);
    distanceResult = Controller78288ApproximatePlanarDistance((void*)ownerPositionWord,
                                                              Controller78288D_80070328);
    state = ((Moby*)owner)->state;
    switch (state) {
        case 0:
            substate = ((Moby*)owner)->substate;
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
                                        ((Moby*)owner)->angle.yaw;
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
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 9)
                                    goto checkPrefixFlags;
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                        if (Controller78288Field(prefixTag, unsigned char*, 0) == 9) {
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
                                nine2 = 9;
                                MATCHING_KEEP3(rawOne4, rawKind3, nine2);
                                Controller78288Field(prefixTag, unsigned char*, 5) = rawOne4;
                                if (rawKind3 == nine2) {
                                    if ((Controller78288D_8006C73C == 28) &&
                                        (Controller78288D_80071596 == 0))
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
                            ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z - 0x280);
                        } else {
                            Controller78288Field(prefixTag, unsigned char*, 5) = 0U;
                        }
                        {
                            register int heading __asm__("$2") = ((Moby*)owner)->angle.yaw;
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
                    ((Moby*)owner)->substate = stateValue;
                    Controller78288Field(owner, signed char*, 0x41) = 0;
                    Controller78288Field(owner, signed char*, 0x4C) = 0;
                    ((Moby*)owner)->drawn = 0U;
                    goto clearExtraHandle;
                case 1:
                    if ((distanceResult < 0x2400) ||
                        (Controller78288Field(tag, unsigned char*, 2) == 2)) {
                        {
                            register int one __asm__("$3") = 1;
                            MATCHING_KEEP(one);
                            Controller78288Field(owner, signed char*, 0x4C) = 24;
                            Controller78288Field(owner, signed char*, 0x41) = one;
                            ((Moby*)owner)->drawn = one;
                            ((Moby*)owner)->size = 127;
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            ((Moby*)owner)->angle.yaw =
                                (unsigned char)Controller78288Field(tag, unsigned char*, 3);
                        } else {
                            ((Moby*)owner)->angle.yaw = Controller78288PlanarHeadingLookup(
                                Controller78288Field(Controller78288D_80070328, int*, 0) -
                                    ((Moby*)owner)->position.x,
                                Controller78288Field(Controller78288D_80070328, int*, 4) -
                                    ((Moby*)owner)->position.y,
                                0);
                        }
                        ((Moby*)owner)->substate = 2U;
                        ((Moby*)owner)->angle.yaw =
                            (unsigned char)(((Moby*)owner)->angle.yaw + 0x67);
                    }
                    goto clearExtraHandle;
                case 2:
                    ((Moby*)owner)->angle.yaw = (unsigned char)(((Moby*)owner)->angle.yaw + 8);
                    ((Moby*)owner)->size = (unsigned char)(((Moby*)owner)->size - 5);
                    if ((Controller78288Field(Controller78288D_80070328, int*, 0xB4) >= 0x1400) ||
                        (Controller78288Field(tag, unsigned char*, 2) == 2)) {
                        ((Moby*)owner)->angle.yaw = (unsigned char)(((Moby*)owner)->angle.yaw + 8);
                        ((Moby*)owner)->size = (unsigned char)(((Moby*)owner)->size - 5);
                    }
                    Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
                    Controller78288SpawnParticle(1, 0xC, owner, 5);
                    if ((unsigned char)((Moby*)owner)->size < 0x21U) {
                        ((Moby*)owner)->size = 0x20U;
                        goto setSubstateFour;
                    }
                    goto clearExtraHandle;
                case 3:
                case 5:
                    if (((Moby*)owner)->size == 0) {
                        ((Moby*)owner)->size = 0x20U;
                    }
                    ((Moby*)owner)->angle.yaw = (unsigned char)(((Moby*)owner)->angle.yaw - 8);
                    ((Moby*)owner)->size = (unsigned char)(((Moby*)owner)->size + 5);
                    Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
                    if ((unsigned char)((Moby*)owner)->size >= 0x7FU) {
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
                        ((Moby*)owner)->drawn = 0U;
                        {
                            register int state __asm__("$3") = ((Moby*)owner)->substate;
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
                            if (Controller78288UpdateMobyInteractionGate(owner, 0xC) != 0) {
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 9) {
                                    if (Controller78288D_80070300[Controller78288D_80066FD3[0x15]] &
                                        1) {
                                        register unsigned char* flag3 __asm__("$3") =
                                            &Controller78288D_80071596;
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
                                Controller78288StartDialogue(owner, 0, 0);
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
                                ((Moby*)owner)->substate = 7U;
                            }
                        } else {
                            Controller78288TurnMobyTowardPlayer(owner, 4, 0, 0);
                            Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
                            if (distanceResult >= 0x2801) {
                                ((Moby*)owner)->substate = 3U;
                            } else if (distanceResult < 0x1000) {
                                ownerHeight =
                                    ((Moby*)owner)->position.z - ((Moby*)owner)->distanceToGround;
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
                                    if ((((((Moby*)owner)->position.z -
                                           ((Moby*)owner)->distanceToGround) -
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
                        ((Moby*)owner)->state = 1U;
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
                        ((Moby*)owner)->substate = 1U;
                    }
                    goto clearExtraHandle;
                case 7:
                    if (Controller78288D_8006E344 == 1)
                        goto clearExtraHandle;
                    if (Controller78288Field(prefixTag, unsigned char*, 0) != 9)
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
                        Controller78288BeginLevelWarp(arg4, arg5 + 8);
                    storePrefixKind:;
                    }
                    Controller78288Field(tag, unsigned char*, 2) = 1;
                    goto setSubstateFour;
            }
            goto clearExtraHandle;
        setSubstateFour:
            nextSubstate = 4;
        storeSubstate:
            ((Moby*)owner)->substate = nextSubstate;
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
                Controller78288SetClampedPlayerTargetAngles(ownerPositionWord);
            }
            phaseResult = Controller78288ReadSelectedFrameScalar(owner);
            ownerIndex = Controller78288Field(tag, int*, 0x10);
            if (ownerIndex >= 0) {
                indexedOwner = (ownerIndex * 0x58) + Controller78288D_8006C550;
                Controller78288TurnMobyTowardHeading(
                    owner,
                    Controller78288PlanarHeadingLookup(
                        Controller78288Field(indexedOwner, int*, 0xC) - ((Moby*)owner)->position.x,
                        Controller78288Field(indexedOwner, int*, 0x10) - ((Moby*)owner)->position.y,
                        0),
                    6, 0, 0, 0);
            } else {
                Controller78288TurnMobyTowardPlayer(owner, 6, 0, 0);
            }
            Controller78288RefreshMobySpatialGridAndBasis(owner, 4);
            if (phaseResult < 0x14) {
                if ((Controller78288Field(tag, unsigned char*, 2) != 2) &&
                    (distanceResult >= 0x1001)) {
                    ((Moby*)owner)->state = 0U;
                    Controller78288RequestMobyAnimation(owner, 0);
                }
            } else if (({
                           register int within __asm__("$2") = phaseResult < 0x1F;
                           MATCHING_KEEP_CLOBBER(within, "$3");
                           within;
                       })) {
                if (((Moby*)owner)->substate != 5) {
                    Controller78288CopyVector(&frame.second.x, owner + 0xC);
                    savedSelector = Controller78288Field(tag, unsigned char*, 4);
                    heightResult = Controller78288QueryWorldHeight(&frame.second.x, 0x800);
                    frame.second.z = heightResult;
                    if (heightResult == 0) {
                        frame.second.z = Controller78288Field(Controller78288D_80070328, int*, 8);
                    }
                    Controller78288WriteTrackedSnapshot(Controller78288D_8006D088, &frame.second.x,
                                                        savedSelector);
                    Controller78288PlayMobySoundEvent(owner, 0, 0x80);
                    ((Moby*)owner)->substate = 5U;
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
                                Controller78288AllocatePoolRecord48((int)prepared, 1, 0x608080);
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
                ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z + 0x20);
                Controller78288Field(tag, short*, 6) =
                    (short)((unsigned short)Controller78288Field(tag, short*, 6) + 0x20);
            }
            if (Controller78288D_8006C770 != 0) {
                if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                    ((Moby*)owner)->substate = 4U;
                    if ((Controller78288Field(tag, int*, 0x14) != 0) &&
                        (Controller78288D_8006E044 == 0x11)) {
                        Controller78288D_8006E160 = 0;
                        Controller78288Field(tag, int*, 0x14) = 0;
                    }
                }
                ((Moby*)owner)->state = 0U;
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
            allocatedHandle = Controller78288AllocatePoolRecord20(
                4, 0x40, ({
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
            if (((Moby*)owner)->drawn != 0) {
                Controller78288InterpolateMobyVertex(owner, 0, &frame.first.x);
                {
                    register void* first __asm__("$4") = &frame.first.x;
                    register void* second __asm__("$5") = first;
                    MATCHING_KEEP2_CLOBBER(first, second, "$16");
                    handleOwnerPosition = owner + 12;
                    Controller78288SubtractVector(first, second, handleOwnerPosition);
                }
                Controller78288ShiftVectorLeft(&frame.first.x, 5);
                Controller78288DivideVector(&frame.first.x, &frame.first.x, ((Moby*)owner)->size);
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
void func_level_20_80079618(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; three original899-word actor functions.
* AI generated; not human reviewed. Every native/linked word, actual branch,
* internal-J/call target, original symbol/addend and complete retail EXE and
* every-overlay hash must pass. No selectors or separate owned data.
* Original C8hex frame saves S0..S7/FP/RA; locals occupy SP18..9F, including
* the original three vector triples, two matrices, three-byte angle view,
* vector at SP68 and pointer words SP90/SP98 with original padding.
* Raw private fields and buffer sizes/strides follow original loads/stores:
* signed cursor0, unsigned count2, twelve12-byte positions, ten12-byte
* vertices, eight colour bytes and five8-byte records. No gameplay meaning
* beyond those words is asserted by these local role names.
* Both ring /12 paths initialize the entire signed64 product of a complete
* signed input and 0x2AAAAAAB before projecting its initialized high word.
* The compiler-local union word order is explicit and never escapes or
* represents retail memory. A matching full64 x-input/x-output identity on
* the second complete product preserves its original delayed consumption;
* no isolated HI/LO operand or partial-product assembly is used.
* Original low32 counter*7 is explicit. Five-element vector loops retain
* the original /5, signed halfword products75/25 and shifts11/10; subsequent
* colour /12 and record %5 use ordinary initialized C integer arithmetic.
* Empty metadata observes complete initialized words, addresses, an entire
* product, or written fields; dead-register boundaries precede fresh phases.
* Staged pitch/yaw loads leave the original stores movable into delay slots.
* Initialized S4 offset ownership transfers into an ordinary retained value;
* FP is never bound explicitly. Every fixed GP role has a disjoint live range.
* No CPU opcode asm, fixed FP, undefined incoming saved read or live aliases.
* Typed ABI views follow tracers.h:29/30, spu.h:89 and stdutil.h:20/34/35.
* Source assembly identities and hashes are recorded in the family proof.
* Full helper/caller chains, physical units/fixed-point representations,
* cadence, Rev1 correspondence, human review and synchronized retail captures
* remain open. Compiler, filters and acceptance flags are unchanged.
*/
#include "mobyutil.h"
#include "spyro.h"
#include "camera.h"
extern Vector3D Original899PlayerPositionView __asm__("D_80070328");
extern Vector3D Original899CameraPositionView __asm__("D_8006E020");
/* Local views preserve existing TU declarations. Symbols and word ABI are
* verified against original callers and existing tracers.h/tracers.c. */
void* Original899CreateHandleView(int, int, int, int, int) __asm__("func_80050B00");
void Original899ReleaseHandleView(int*) __asm__("func_80050B88");
#include "ovl_header.h"
extern int D_8006C574, D_8006C578, D_8006C640, D_8006C7E8, D_80071924, D_80071934;
extern unsigned char* Original899ModelTableView[] __asm__("D_8006EE2C");
extern unsigned char D_8006D048[];
extern short D_800658A0[256], D_80065920[256];
int func_8001830C(Vector3D*, Vector3D*, int, int, int);
int func_80019138(Vector3D*, int, int, int, int, Moby*);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
int func_80040954(int);
void func_8004EA90(Angle*, SHORTMATRIX*, int);
void func_8004F0E8(Vector3D*, int);
void Original899MatrixCallView(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int func_8004EDE8(Vector3D*, int);
int Original899PlayMobySoundEventView(Moby*, int, int) __asm__("func_8003BABC");
void func_80055D24(Moby*, int);
int rand(void);
typedef struct {
    unsigned char current0, next1, other2, otherNext3, byte4, byte5, byte6, byte7;
} Original899IndexWords;
typedef struct {
    short cursor0;
    unsigned short count2;
    Vector3D positions4[12];
    Vector3D vertices94[10];
    int sentinel10C;
    unsigned char colours110[8];
    Original899IndexWords indices118[5];
    int sentinel140;
} Original899Buffer;
typedef struct {
    Vector3D16 vector0;
    unsigned char byte6, timer7;
    Original899Buffer* buffer8;
    int* handleC;
    int words10[2];
} Original899PrivateRecord;
typedef struct {
    int word0;
    unsigned int word4;
} Original899FlagWords;
static __inline__ void Original899InitializeChild(Moby* child) {
    unsigned char* descriptor;
    unsigned int first, flag;
    ((volatile Moby*)child)->state = 1;
    child->unknown3[1] = 0;
    descriptor = *(unsigned char**)(Original899ModelTableView[child->mobyClass] + 0x40);
    first = *descriptor;
    child->animationState.id = 1;
    child->animationState.nextId = 1;
    child->animationState.nextFrame = 1;
    child->animationState.frame = 0;
    child->state = 2;
    flag = first < 2;
    flag ^= 1;
    flag = -flag;
    child->animationProgress = flag & 0x30;
}
/* Compiler-local value view, never an addressable retail memory layout.
* Both words are initialized by the signed64 C multiplication. The frozen
* compiler uses MIPSEB word order even though the final image is assembled EL.
* Selecting its high component never reads an undefined or incoming value. */
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
} Original899CompleteProduct;
void func_level_20_80079A48(Moby* moby) {
    Moby* owner = moby;
    int x = owner->position.x;
    register Original899PrivateRecord* tag __asm__("$22") = owner->mobyTag;
    int y;
    struct {
        Vector3D position18;
        int gap24;
        Vector3D vector28;
        int gap34;
        Vector3D vector38;
        int gap44;
        SHORTMATRIX matrix48;
        int gap5C;
        Angle angle60;
        unsigned char gap63[8 - sizeof(Angle)];
        Vector3D vector68;
        int gap74;
        SHORTMATRIX matrix78;
        int gap8C;
    } originalFrame;
    Vector3D* vertices;
    Original899IndexWords* indices;
    if (x < 1024 || (y = owner->position.y) < 1024 || owner->position.z < 1024 || x > 0x3C000 ||
        y > 0x3C000) {
        if (tag->handleC)
            Original899ReleaseHandleView(tag->handleC);
        func_80055B18(owner);
        /* Original continues after this helper; no early return is added. */
    }
    MATCHING_OBSERVE(tag);
    if (owner->state != 2 && owner->substate == 0) {
        Vector3D* position = &owner->position;
        Original899Buffer* buffer = tag->buffer8;
        Moby* target;
        owner->substate = 1;
        func_8004F178(buffer->positions4, position);
        buffer->cursor0 = 1;
        buffer->count2 = 1;
        target = func_8001BA30(position, 600, 0, 0, 0x950000, owner);
        if (target) {
            int angle = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
            target->unkb = angle;
            if (!(angle & 255))
                target->unkb = 1;
            owner->state = 1;
        }
        if (func_8001830C(&owner->position, &Original899PlayerPositionView, 2, 0, 0))
            owner->state = 1;
    }
    switch ((int)owner->state) {
        case 0: {
            Vector3D* position = &owner->position;
            Moby* target;
            func_8004F178(&originalFrame.position18, position);
            owner->position.x += tag->vector0.x;
            owner->position.y += tag->vector0.y;
            owner->position.z += tag->vector0.z;
            MATCHING_BARRIER("memory");
            D_80071934 = 0;
            if (func_8001830C(&originalFrame.position18, position, 2, 0x950000, 0)) {
                func_8004F178(position, &originalFrame.position18);
                owner->state = 1;
            }
            target = func_8001BA30(position, 400, 0, 0, 0x950000, owner);
            if (target) {
                unsigned short targetClass;
                int angle = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                target->unkb = angle;
                if (!(angle & 255))
                    target->unkb = 1;
                targetClass = target->mobyClass;
                if ((unsigned int)(targetClass - 200) >= 2 && (short)targetClass != 209 &&
                    (short)targetClass != 272 && (short)targetClass != 563 &&
                    owner->mobyClass != 208)
                    owner->state = 1;
            }
            func_80019138(&owner->position, 300, 2, 0, 0x950000, owner);
            if (!(D_8006C640 & 3) && D_8006C578 - D_8006C574 >= 21) {
                Moby* child = SpawnMoby(483, owner);
                if (child) {
                    originalFrame.vector28.x = tag->vector0.x;
                    originalFrame.vector28.y = tag->vector0.y;
                    child->angle.pitch =
                        func_8004E880(func_8004EDE8(&originalFrame.vector28, 0), tag->vector0.z, 0);
                    child->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                    Original899InitializeChild(child);
                }
            }
            if (owner->state == 0 && func_800359A4((char*)&tag->timer7, 1)) {
                if (tag->handleC)
                    Original899ReleaseHandleView(tag->handleC);
                tag->handleC = 0;
                owner->state = 1;
            }
            break;
        }
        case 1: {
            register int loopIndex __asm__("$20");
            Original899PlayMobySoundEventView(owner, 1, 0);
            if (D_8006C578 - D_8006C574 >= 21 && D_8006C7E8 >= 30001) {
                Moby* child = SpawnMoby(326, owner);
                if (child) {
                    D_8006C7E8 -= 1500;
                    child->unknown4 = 7;
                }
            }
            loopIndex = 0;
            if (D_8006C578 - D_8006C574 >= 21) {
                register Vector3D* cameraPosition __asm__("$21") = &Original899CameraPositionView;
                register int pitch __asm__("$19") = 0;
                MATCHING_KEEP(cameraPosition);
            spawnNext899:
                if (D_8006C7E8 >= 30001) {
                    Moby* child = SpawnMoby(541, owner);
                    if (child) {
                        int angle;
                        D_8006C7E8 -= 1000;
                        angle = func_8004E880(owner->position.x - cameraPosition->x,
                                              owner->position.y - cameraPosition->y, 0);
                        child->angle.yaw = angle + 64 + (rand() & 31);
                        child->angle.pitch = pitch + (rand() & 30) - 15;
                        child->unknown4 = 8;
                        child->lowDrawDistance = 42;
                    }
                    loopIndex++;
                    pitch += 51;
                    if (loopIndex < 5 && D_8006C578 - D_8006C574 >= 21)
                        goto spawnNext899;
                }
            }
            MATCHING_BARRIER("$4");
            func_80055D24(owner, 2);
            owner->unknown3[0] = 0;
            owner->lowDrawDistance = 0;
            owner->drawn = 0;
            tag->timer7 = 20;
            owner->state = 3;
        }
            /* Original state1 falls through to3. */
        case 3: {
            int radius = 600;
            Moby* target;
            if (tag->timer7 >= 6) {
                int loopIndex = 0;
                do {
                    originalFrame.angle60.roll = 0;
                    originalFrame.angle60.pitch = rand();
                    originalFrame.angle60.yaw = rand();
                    func_8004EA90(&originalFrame.angle60, &originalFrame.matrix48, 0);
                    loopIndex++;
                    originalFrame.vector28.x = (rand() & 31) + 48;
                    originalFrame.vector28.y = 0;
                    originalFrame.vector28.z = 0;
                    Original899MatrixCallView(&originalFrame.matrix48, &originalFrame.vector28,
                                              &originalFrame.vector28);
                    func_8004F178(&originalFrame.vector38, &originalFrame.vector28);
                    func_8004F0E8(&originalFrame.vector38, 2);
                    func_8004F194(&originalFrame.vector38, &originalFrame.vector38,
                                  &owner->position);
                    SpawnParticle(1, 13, &originalFrame.vector38, &originalFrame.vector28);
                } while (loopIndex < 4);
                SpawnParticle(6, 70, &owner->position, (Vector3D*)16);
            }
            if (!(D_8006C640 & 1) && D_8006C578 - D_8006C574 >= 21 && D_8006C7E8 >= 30001) {
                Moby* child = SpawnMoby(482, owner);
                if (child) {
                    D_8006C7E8 -= 1500;
                    child->lowDrawDistance = 42;
                    child->unknown4 = 10;
                }
            }
            if (tag->timer7 >= 11)
                radius = (radius >> 1) + (radius * (20 - tag->timer7)) / 20;
            else
                radius = (radius >> 1) + (radius * tag->timer7) / 20;
            target = func_8001BA30(&owner->position, radius + 1000, 0, 0, 0x950000, owner);
            if (target) {
                int angle = func_8004E880(target->position.x - owner->position.x,
                                          target->position.y - owner->position.y, 0);
                target->unkb = angle;
                if (!(angle & 255))
                    target->unkb = 1;
            }
            if (func_80019138(&owner->position, radius + 700, 2, 0, 0x950000, owner)) {
                int* sourceWord = &D_80071924;
                MATCHING_KEEP(sourceWord);
                if (func_80040954(*sourceWord) == 3) {
                    Original899FlagWords* flags =
                        (*(Original899FlagWords***)(D_8006D048 + 0x14))[*sourceWord & 63];
                    flags->word4 |= 0x950000;
                }
            }
            if (func_800359A4((char*)&tag->timer7, 1)) {
                if (tag->handleC)
                    Original899ReleaseHandleView(tag->handleC);
                func_80055B18(owner);
            }
            break;
        }
        case 2:
            if (func_800359A4((char*)&tag->timer7, 1)) {
                func_80055B18(owner);
                return;
            }
            owner->size = 16384 / (1024 - tag->timer7 * 20);
            if (owner->size >= 128)
                owner->size = 127;
            if (owner->size < 18)
                owner->size = 18;
            owner->colour.r = tag->timer7 * 4;
            owner->colour.g = tag->timer7 * 2;
            break;
    }
    if (owner->state != 2) {
        Original899Buffer* buffer = tag->buffer8;
        register int previousCursor3 __asm__("$3") = buffer->cursor0;
        register int previousPositionByteOffset2 __asm__("$2") = previousCursor3 * 12;
        register int initialPositionByteOffset20 __asm__("$20");
        int retainedPositionByteOffset;
        register int nextCursorInput6 __asm__("$6") = previousCursor3 + 1;
        Original899CompleteProduct completeDivisionProduct;
        register int divisionSign2 __asm__("$2");
        register int divisionHighShift3 __asm__("$3");
        register int previousRingNext23 __asm__("$23");
        register int scaledQuotient2 __asm__("$2");
        register unsigned char* colourWords21 __asm__("$21");
        register Vector3D* currentVertex20 __asm__("$20");
        Vector3D* firstVector68;
        int loopIndex;
        unsigned char originalPitchByte, originalYawByte;
        register unsigned short incrementedCount4 __asm__("$4");
        register int countBelow13_4 __asm__("$4");
        register int newRingCursor5 __asm__("$5");
        register Vector3D* firstPositionArgument4 __asm__("$4");
        register Vector3D* ownerPositionArgument5 __asm__("$5");
        register Angle* angleArgument4 __asm__("$4");
        register SHORTMATRIX* matrixArgument5 __asm__("$5");
        register int matrixZeroArgument6 __asm__("$6");
        __asm__(""
                : "=r"(previousPositionByteOffset2)
                : "0"(previousPositionByteOffset2), "r"(previousCursor3));
        initialPositionByteOffset20 = previousPositionByteOffset2 + 4;
        completeDivisionProduct.full = (long long)nextCursorInput6 * (long long)0x2AAAAAAB;
        firstPositionArgument4 = (Vector3D*)((unsigned char*)buffer + initialPositionByteOffset20);
        ownerPositionArgument5 = &owner->position;
        MATCHING_OBSERVE2_VOLATILE_CLOBBER(firstPositionArgument4, ownerPositionArgument5, "$2");
        divisionSign2 = nextCursorInput6 >> 31;
        divisionHighShift3 = (completeDivisionProduct.words.high) >> 1;
        __asm__("" : "=r"(divisionHighShift3) : "0"(divisionHighShift3), "r"(divisionSign2));
        previousRingNext23 = divisionHighShift3 - divisionSign2;
        __asm__("" : "=r"(previousRingNext23) : "0"(previousRingNext23), "r"(nextCursorInput6));
        scaledQuotient2 = previousRingNext23 * 12;
        __asm__("" : "=r"(scaledQuotient2) : "0"(scaledQuotient2), "r"(previousRingNext23));
        previousRingNext23 = nextCursorInput6 - scaledQuotient2;
        func_8004F178(firstPositionArgument4, ownerPositionArgument5);
        newRingCursor5 = buffer->cursor0;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(newRingCursor5, "memory");
        newRingCursor5 = newRingCursor5 + 1;
        completeDivisionProduct.full = (long long)newRingCursor5 * (long long)0x2AAAAAAB;
        incrementedCount4 = buffer->count2;
        __asm__ volatile("" ::: "$21", "memory");
        colourWords21 = buffer->colours110;
        incrementedCount4 = incrementedCount4 + 1;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(incrementedCount4, "$2");
        divisionSign2 = newRingCursor5 >> 31;
        buffer->count2 = incrementedCount4;
        countBelow13_4 = (short)incrementedCount4 < 13;
        __asm__ volatile(""
                         : "=x"(completeDivisionProduct.full)
                         : "0"(completeDivisionProduct.full), "r"(countBelow13_4)
                         : "memory");
        divisionHighShift3 = completeDivisionProduct.words.high >> 1;
        __asm__("" : "=r"(divisionHighShift3) : "0"(divisionHighShift3), "r"(divisionSign2));
        divisionHighShift3 = divisionHighShift3 - divisionSign2;
        scaledQuotient2 = divisionHighShift3 * 12;
        newRingCursor5 = newRingCursor5 - scaledQuotient2;
        buffer->cursor0 = newRingCursor5;
        vertices = buffer->vertices94;
        indices = buffer->indices118;
        if (!countBelow13_4)
            buffer->count2 = 12;
        if ((short)buffer->count2 < 12)
            previousRingNext23 = 0;
        angleArgument4 = &originalFrame.angle60;
        matrixArgument5 = &originalFrame.matrix78;
        matrixZeroArgument6 = 0;
        MATCHING_OBSERVE3_VOLATILE_CLOBBER(angleArgument4, matrixArgument5, matrixZeroArgument6,
                                           "memory");
        __asm__("" : "=r"(retainedPositionByteOffset) : "0"(initialPositionByteOffset20));
        currentVertex20 = vertices;
        originalFrame.angle60.roll = (unsigned int)D_8006C640 * 7;
        MATCHING_OBSERVE_VOLATILE(currentVertex20);
        originalPitchByte = owner->angle.pitch;
        __asm__ volatile("" ::: "$16", "memory");
        loopIndex = 0;
        originalFrame.angle60.pitch = originalPitchByte;
        originalYawByte = owner->angle.yaw;
        __asm__ volatile("" ::: "$17", "memory");
        firstVector68 = &originalFrame.vector68;
        originalFrame.angle60.yaw = originalYawByte;
        func_8004EA90(angleArgument4, matrixArgument5, matrixZeroArgument6);
        func_80055D24(owner, 4);
        MATCHING_OBSERVE(firstVector68);
        do {
            int angle = (loopIndex << 8) / 5;
            originalFrame.vector68.x = 0;
            originalFrame.vector68.y = (D_80065920[angle] * 75) >> 11;
            originalFrame.vector68.z = (D_800658A0[angle] * 75) >> 11;
            Original899MatrixCallView(&originalFrame.matrix78, firstVector68, firstVector68);
            func_8004F194(currentVertex20,
                          (Vector3D*)((unsigned char*)buffer + retainedPositionByteOffset),
                          firstVector68);
            loopIndex++;
            currentVertex20++;
        } while (loopIndex < 5);
        loopIndex = 0;
        {
            short* table65920 = D_80065920;
            register Vector3D* secondVector18 __asm__("$18");
            register int nextVertexByteOffset17 __asm__("$17");
            int nextPositionByteOffset;
            __asm__("" : "=r"(table65920) : "0"(table65920), "r"(previousRingNext23) : "$20");
            secondVector18 = firstVector68;
            MATCHING_OBSERVE(secondVector18);
            nextPositionByteOffset = previousRingNext23 * 12 + 4;
            nextVertexByteOffset17 = 60;
            __asm__("" : "=r"(table65920) : "0"(table65920), "r"(secondVector18));
            do {
                int angle = (loopIndex << 8) / 5;
                originalFrame.vector68.x = 0;
                originalFrame.vector68.y = (table65920[angle] * 25) >> 10;
                originalFrame.vector68.z = (D_800658A0[angle] * 25) >> 10;
                Original899MatrixCallView(&originalFrame.matrix78, secondVector18, secondVector18);
                func_8004F194((Vector3D*)((unsigned char*)vertices + nextVertexByteOffset17),
                              (Vector3D*)((unsigned char*)buffer + nextPositionByteOffset),
                              secondVector18);
                loopIndex++;
                nextVertexByteOffset17 += 12;
            } while (loopIndex < 5);
        }
        *(int*)((unsigned char*)vertices + 0x78) = -1;
        colourWords21[0] = 140;
        colourWords21[1] = 100;
        colourWords21[2] = 40;
        if ((short)buffer->count2 < 12) {
            colourWords21[4] = (colourWords21[0] * (12 - (short)buffer->count2)) / 12;
            colourWords21[5] = (colourWords21[1] * (12 - (short)buffer->count2)) / 12;
            colourWords21[6] = (colourWords21[2] * (12 - (short)buffer->count2)) / 12;
        } else {
            colourWords21[4] = 0;
            colourWords21[5] = 0;
            colourWords21[6] = 0;
        }
        loopIndex = 0;
        do {
            register int nextIndex __asm__("$3") = loopIndex + 1;
            int remainder = nextIndex % 5;
            Original899IndexWords* item = (Original899IndexWords*)(loopIndex * 8 + (int)indices);
            item->current0 = loopIndex;
            item->other2 = loopIndex + 5;
            loopIndex = nextIndex;
            item->byte4 = 0;
            item->byte5 = 0;
            item->byte6 = 1;
            item->byte7 = 1;
            {
                register int result __asm__("$2") = remainder;
                MATCHING_KEEP(result);
                item->next1 = result;
                item->otherNext3 = result + 5;
            }
        } while (loopIndex < 5);
        *(int*)(indices + 5) = -1;
        if (!tag->handleC) {
            register int callColours __asm__("$5") = (int)colourWords21;
            register int callWords __asm__("$7") = (int)tag->words10;
            register int callVertices __asm__("$4") = (int)vertices;
            register int callIndices __asm__("$6") = (int)indices;
            MATCHING_OBSERVE4_CLOBBER(callColours, callWords, callVertices, callIndices, "memory");
            tag->handleC = (int*)Original899CreateHandleView(callVertices, callColours, callIndices,
                                                             callWords, 1);
        }
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
void func_level_20_8007A854(Moby* owner) {
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
void func_level_20_8007A9E0(Moby* moby) {
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
void DecodedDialogueGateStartDialogue(Moby*, int, int) __asm__("func_800512E4");
void func_level_20_8007AB34(Moby* moby) {
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
                DecodedDialogueGateStartDialogue(moby, 0, 1);
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
void func_level_20_8007AD74(Moby* actor) {
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
void func_level_20_8007AF00(Moby* moby) {
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
/* AI-generated; not human reviewed. Verified C sibling plus only original
 * per-overlay branches read in sibling3791 evidence. Raw units, helper
 * semantics and cadence remain unresolved. */
extern unsigned char Controller7C02CFlags __asm__("D_8006C7B4");
extern unsigned char Controller7C02CSavedFlags[] __asm__("D_80070300");
extern unsigned char Controller7C02CCounters[] __asm__("D_800716AC + 0x3");
#define Controller7C02CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller7C02CConfigureHudEntry(int, int, int, int, int, void*, int) __asm__("func_8002803C");
void* Controller7C02CAllocatePoolRecord48(int, int, int) __asm__("func_8002F540");
int Controller7C02CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller7C02CSoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
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
void func_level_20_8007AFD8(void* input) {
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
    controller = ((Moby*)owner)->mobyTag;
    distance = Controller7C02CApproximatePlanarDistance(owner + 0xC, Controller7C02CD_80070328);
    Controller7C02CField(controller, int*, 0x14) = distance;
    if (distance < 0x1000) {
        {
            register int index __asm__("$3") = ((Moby*)owner)->angle.yaw;
            register int component __asm__("$2") =
                Controller7C02CField(Controller7C02CD_80070328, int*, 4);
            register int ownerComponent __asm__("$4") = ((Moby*)owner)->position.y;
            register int firstProduct __asm__("$5");
            MATCHING_KEEP3(index, component, ownerComponent);
            index <<= 1;
            firstProduct = *(short*)(Controller7C02CD_800658A0 + index);
            component -= ownerComponent;
            firstProduct *= component;
            index = *(short*)(Controller7C02CD_80065920 + index);
            ownerComponent = ((Moby*)owner)->position.x;
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
    temp_a0_2 = ((Moby*)owner)->gemValue;
    if (temp_a0_2 != 0xFF) {
        temp_v0_3 = Controller7C02CSpawnMoby(temp_a0_2, owner);
        Controller7C02CField(controller, void**, 0x24) = temp_v0_3;
        if (temp_v0_3 != 0) {
            Controller7C02CCopyVector(temp_v0_3 + 0xC, owner + 0xC);
            temp_v1_3 = Controller7C02CField(controller, void**, 0x24);
            Controller7C02CField(temp_v1_3, int*, 0x14) =
                (int)(Controller7C02CField(temp_v1_3, int*, 0x14) + 0x580);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x46) = (unsigned char)((Moby*)owner)->angle.yaw;
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x4C) = (unsigned char)((Moby*)owner)->lowDrawDistance;
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x52) = (unsigned char)((Moby*)owner)->subtype;
            if (((Moby*)owner)->gemValue == 0x21) {
                Controller7C02CField(Controller7C02CField(controller, void**, 0x24), int*, 0x54) =
                    0x2A606060;
            }
            ((Moby*)owner)->gemValue = 0xFFU;
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
    state = ((Moby*)owner)->state;
    if (!state) {
        ((Moby*)owner)->state = 1;
        return;
    }
    switch (state) {
        case 1:
            break;
        default:
            return;
    }
    if ((((Moby*)owner)->drawn != 0) && (Controller7C02CField(controller, int*, 0x14) < 0x4000) &&
        !(Controller7C02Crand() & 0x3F)) {
        spawnedChild = Controller7C02CSpawnMoby(0x1CBU, owner);
        spawnedRecord = Controller7C02CField(spawnedChild, void**, 0);
        {
            register int factor __asm__("$2") = Controller7C02Crand();
            register int trig __asm__("$3") = ((Moby*)owner)->angle.yaw;
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
            trig = ((Moby*)owner)->angle.yaw;
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
    if (Controller7C02CSoundHandleMatchesOwnerInStates1Or2(
            owner, Controller7C02CField(controller, int*, 0x20)) == 0) {
        Controller7C02CField(controller, int*, 0x20) =
            Controller7C02CPlayMobySoundEvent(owner, 0, 4);
    }
    if (((Moby*)owner)->drawn != 0) {
        temp_a0_4 = Controller7C02CField(controller, int*, 0x14);
        if ((temp_a0_4 <= 0x9FFF) && (!(Controller7C02CD_8006C640 & 3) ||
                                      (!(Controller7C02CD_8006C640 & 1) && (temp_a0_4 < 0x5000)))) {
            frame.sp20 = 0;
            frame.sp24 = 0x352 - (Controller7C02Crand() % 1700);
            frame.sp28 = 0;
            Controller7C02CTransformVectorByBasis(owner + 32, &frame.sp20, &frame.sp20);
            Controller7C02CAddVector(&frame.sp20, &frame.sp20, owner + 0xC);
            Controller7C02CSpawnParticle(1, 4, &frame.sp20, ((Moby*)owner)->position.z + 0x640);
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
                temp_v0_7 = Controller7C02CAllocatePoolRecord48(4, 1, 0x608080);
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
    ((Moby*)owner)->colour.a =
        (unsigned char)(((Moby*)owner)->colour.a + (Controller7C02Crand() & 3));
    temp_v1_8 = Controller7C02CField(controller, int*, 0x14);
    if ((temp_v1_8 < 0x1000) && (crossedSide != 0) && (temp_v1_8 < 0x380)) {
        temp_v1_9 = ((Moby*)owner)->position.z - ((Moby*)owner)->distanceToGround;
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
                    Controller7C02CConfigureHudEntry(4, eventSelector,
                                                     Controller7C02Cunk_ovlheader_800743B8,
                                                     Controller7C02Cunk_ovlheader_800743C0,
                                                     Controller7C02Cunk_ovlheader_800743BC,
                                                     eventDestination, *(int*)eventDestination);
                }
                if (!(Controller7C02CFlags & 8)) {
                    register int levelIndex __asm__("$3") = Controller7C02CD_8006C58C;
                    if (!(Controller7C02CSavedFlags[levelIndex] & 8)) {
                        register int offsetWord __asm__("$2") = levelIndex * 3;
                        register int byteOffset __asm__("$4");
                        register unsigned int counter __asm__("$3");
                        MATCHING_KEEP(offsetWord);
                        byteOffset = offsetWord << 1;
                        counter = Controller7C02CCounters[byteOffset];
                        if (counter < 255) {
                            register unsigned int nextCount __asm__("$2") = counter + 1;
                            MATCHING_KEEP(nextCount);
                            Controller7C02CCounters[byteOffset] = nextCount;
                        }
                    }
                }
            }
        }
    }
    return;
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level20
 * original8007B80C complete407 instructions and5 dispatch plus zero padding
 * in sibling4529 and original assembly. Verified40 linked actor C reused;
 * original20 controls every difference. Raw units, helper meanings, incoming
 * linked argument on negative index and cadence unresolved. Native/linked
 * words and every original retail hash required before acceptance. */
#define Actor20B80CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Actor20B80CFlags __asm__("D_8006C7B4");
extern unsigned char Actor20B80CLevels[] __asm__("D_80070300");
extern int Actor20B80CLevel __asm__("D_8006C58C");
extern int Actor20B80CMode __asm__("D_8006E344");
extern unsigned char* Actor20B80CPool __asm__("D_8006C550");
extern int Actor20B80CPlayerFlags __asm__("D_80070328 + 0x20C");
int Actor20B80CUpdateMobyInteractionGate() __asm__("func_80037BBC");
int Actor20B80CStartDialogue() __asm__("func_800512E4");
int Actor20B80CUpdateMobyPathMotion() __asm__("func_80035A80");
int Actor20B80CApproximatePlanarDistance() __asm__("func_8004F334");
int Actor20B80CRequestMobyAnimation() __asm__("func_80034F40");
int Actor20B80CDeleteMoby() __asm__("func_80055B18");
int Actor20B80CSetClampedPlayerTargetAngles() __asm__("func_800492DC");
extern void* (*Actor20B80CSpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
extern unsigned char Actor20B80CLevelByte __asm__("D_80066FCC + 0x2F");
extern unsigned char Actor20B80CTable[] __asm__("D_80071570");
extern unsigned char Actor20B80CCamera[] __asm__("D_8006E17C");
extern int Actor20B80CCameraMode __asm__("D_8006E160");
int Actor20B80CCopyVector() __asm__("func_8004F178");
int Actor20B80CBuildCameraVectorOrientation() __asm__("func_800136F0");
extern int Actor20B80CGate __asm__("D_8006C770");
int Actor20B80CRandBetween() __asm__("func_8003636C");
int Actor20B80CComputeArcVerticalVelocity() __asm__("func_800365E4");
int Actor20B80CQueryWorldHeight() __asm__("func_8001A358");
void func_level_20_8007B80C(void* input) {
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
    int vector[4];
    __asm__("" : "=r"(owner), "=r"(linked5) : "0"(owner));
    tag = Actor20B80CField(owner, unsigned char**, 0);
    work3 = Actor20B80CField(tag, int*, 0x2C);
    MATCHING_KEEP(work3);
    if (work3 >= 0)
        linked5 = Actor20B80CField(Actor20B80CPool + work3 * 88, unsigned char**, 0);
    work3 = ((Moby*)owner)->state;
    switch (work3) {
        case 0:
        case 1:
            work3 = ((Moby*)owner)->substate;
            if (work3 == 1)
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
            work2 = Actor20B80CField(linked5, int*, 12);
            if (work2 >= 0 && Actor20B80CTable[work2])
                goto remove;
            ((Moby*)owner)->substate = 4;
            goto tail;
        sub1:
            Actor20B80CPlayerFlags = 0x10000002;
            if (Actor20B80CUpdateMobyInteractionGate(owner, 0)) {
                Actor20B80CStartDialogue(owner, 0, 2);
                ((Moby*)owner)->state = 2;
                goto tail;
            }
            if (!Actor20B80CGate)
                goto tail;
            if (!Actor20B80CField(tag, int*, 0x28)) {
                Actor20B80CRequestMobyAnimation(owner, 1);
                Actor20B80CField(tag, int*, 0x28) = Actor20B80CRandBetween(3, 6);
            } else {
                Actor20B80CRequestMobyAnimation(owner, 0);
                Actor20B80CField(tag, int*, 0x28)--;
            }
            goto tail;
        sub4:
            if (!Actor20B80CTable[Actor20B80CField(linked5, int*, 12)])
                goto tail;
            work2 = Actor20B80CField(tag, int*, 0x38);
            playerFlags6 = 0x10000000;
            if (work2) {
                camera = Actor20B80CCamera;
                linked5 = Actor20B80CField((void*)work2, unsigned char**, 12);
                Actor20B80CCopyVector(camera, linked5 + 16);
                linked5 =
                    Actor20B80CField(Actor20B80CField(tag, void**, 0x38), unsigned char**, 12);
                Actor20B80CBuildCameraVectorOrientation(camera - 20, linked5, linked5 + 16);
                Actor20B80CCameraMode = 17;
                MATCHING_BARRIER_VOLATILE("memory");
                playerFlags6 = 0x10000000;
            }
            playerFlags6 |= 2;
            work2 = Actor20B80CField(tag, int*, 0x30);
            __asm__("" : "=r"(work2) : "0"(work2) : "$4", "$5");
            call4 = owner;
            Actor20B80CField((void*)work2, short*, 2) = 0;
            work3 = Actor20B80CField(tag, int*, 0x30);
            Actor20B80CField((void*)work3, short*, 10) = 1;
            work2 = ((Moby*)owner)->position.z;
            MATCHING_KEEP_CLOBBER(work2, "$5");
            call5 = 3;
            work2 -= 128;
            MATCHING_KEEP(work2);
            ((Moby*)owner)->position.z = work2;
            Actor20B80CPlayerFlags = playerFlags6;
            work2 = 3;
            goto set3Call;
            goto tail;
        case 2:
            if (Actor20B80CMode == 1)
                goto tail;
            if (Actor20B80CField(tag, unsigned char*, 4) != 4)
                goto reset;
            index4 = Actor20B80CField(tag, int*, 0x2C);
            if (index4 >= 0 && ((Moby*)owner)->mobyClass != 70)
                Actor20B80CField(Actor20B80CPool + index4 * 88, unsigned char*, 0x48) = 9;
            if (Actor20B80CField(tag, void**, 0x30)) {
                work2 = Actor20B80CField(tag, int*, 0x38);
                call4 = owner;
                MATCHING_KEEP(call4);
                if (work2) {
                    camera = Actor20B80CCamera;
                    linked5 = Actor20B80CField((void*)work2, unsigned char**, 12);
                    Actor20B80CCopyVector(camera, linked5 + 16);
                    linked5 =
                        Actor20B80CField(Actor20B80CField(tag, void**, 0x38), unsigned char**, 12);
                    Actor20B80CBuildCameraVectorOrientation(camera - 20, linked5, linked5 + 16);
                    Actor20B80CCameraMode = 17;
                }
                call4 = owner;
                call5 = 3;
                MATCHING_KEEP2(call4, call5);
                ((Moby*)owner)->substate = 1;
                work2 = 3;
            set3Call:
                ((Moby*)owner)->state = work2;
                Actor20B80CRequestMobyAnimation(call4, call5);
                goto tail;
            }
        reset:
            ((Moby*)owner)->state = 0;
            Actor20B80CField(tag, int*, 0x28) = 3;
            goto tail;
        case 3:
            work3 = ((Moby*)owner)->substate;
            if (work3 == 1)
                goto first;
            if (work3 == 4)
                goto fourth;
            goto tail;
        first:
            old16 = Actor20B80CField(Actor20B80CField(tag, void**, 0x30), short*, 2);
            if (!(Actor20B80CUpdateMobyPathMotion(owner, Actor20B80CField(tag, void**, 0x30), 512,
                                                  128, 0, 8, 12, 5) &
                  1))
                goto player;
            linked5 = Actor20B80CField(tag, unsigned char**, 0x30);
            new6 = Actor20B80CField(linked5, short*, 2);
            if (!new6)
                goto clearCamera;
            work3 = Actor20B80CField(linked5, int*, 12);
            if (!(Actor20B80CField((void*)(work3 + old16 * 16), int*, 12) & 1))
                goto player;
            work2 = Actor20B80CComputeArcVerticalVelocity(owner + 12, (void*)(work3 + new6 * 16),
                                                          128, -8, 0);
            call4 = owner;
            call5 = 4;
            Actor20B80CField(tag, int*, 0x34) = work2;
            goto set4Call;
        fourth:
            Actor20B80CPlayerFlags = 0x10000002;
            if (Actor20B80CUpdateMobyPathMotion(owner, Actor20B80CField(tag, void**, 0x30), 512,
                                                128, 0, 8, 12, 5) &
                1) {
                Actor20B80CField(tag, unsigned char*, 2) = 4;
                ((Moby*)owner)->substate = 1;
                ((Moby*)owner)->state = 0;
                Actor20B80CRequestMobyAnimation(owner, 0);
            }
            goto tail;
        case 4:
            old20 = Actor20B80CField(Actor20B80CField(tag, void**, 0x30), short*, 2);
            work2 = Actor20B80CUpdateMobyPathMotion(owner, Actor20B80CField(tag, void**, 0x30), 512,
                                                    128, 0, 8, 12, 0);
            call4 = vector;
            position19 = owner + 12;
            __asm__("" : "=r"(call4), "=r"(position19) : "0"(call4), "1"(position19) : "$6", "$16");
            new6 = Actor20B80CField(tag, int*, 0x34);
            MATCHING_KEEP_CLOBBER(new6, "$5");
            call5 = (int)position19;
            new6 -= 8;
            Actor20B80CField(tag, int*, 0x34) = new6;
            work3 = ((Moby*)owner)->position.z;
            MATCHING_KEEP2_CLOBBER(work3, work2, "$16");
            result16 = work2;
            work3 += new6;
            ((Moby*)owner)->position.z = work3;
            Actor20B80CCopyVector(call4, call5);
            vector[2] += 512;
            if (Actor20B80CQueryWorldHeight(vector, 512)) {
                ((Moby*)owner)->state = 3;
                Actor20B80CRequestMobyAnimation(owner, 3);
            }
            work2 = result16 & 1;
            MATCHING_KEEP(work2);
            if (!work2)
                goto player;
            linked5 = Actor20B80CField(tag, unsigned char**, 0x30);
            new6 = Actor20B80CField(linked5, short*, 2);
            if (!new6) {
            clearCamera:
                if (Actor20B80CField(tag, void**, 0x38))
                    Actor20B80CCameraMode = 0;
            remove:
                Actor20B80CDeleteMoby(owner);
                return;
            }
            work3 = Actor20B80CField(linked5, int*, 12);
            if (!(Actor20B80CField((void*)(work3 + old20 * 16), int*, 12) & 1))
                goto player;
            work2 = Actor20B80CComputeArcVerticalVelocity(position19, (void*)(work3 + new6 * 16),
                                                          128, -8, 0);
            call4 = owner;
            call5 = 4;
            Actor20B80CField(tag, int*, 0x34) = work2;
            ((Moby*)owner)->animationState.nextId = 3;
        set4Call:
            ((Moby*)owner)->state = 4;
            Actor20B80CRequestMobyAnimation(call4, call5);
        player:
            MATCHING_BARRIER("$2");
            Actor20B80CPlayerFlags = 0x10000002;
            Actor20B80CSetClampedPlayerTargetAngles(owner + 12);
    }
tail:
    work3 = Actor20B80CField(tag, int*, 0x2C);
    if (work3 < 0)
        return;
    if (((Moby*)owner)->state < 3)
        return;
    if (Actor20B80CApproximatePlanarDistance(owner + 12, Actor20B80CPool + work3 * 88 + 12) < 512)
        Actor20B80CSpawnParticle(2, 12, Actor20B80CPool + Actor20B80CField(tag, int*, 0x2C) * 88,
                                 (void*)5);
}
#undef Actor20B80CField


int DamageTagUpdate(Moby*, void*) __asm__("func_80035194");
int DamageTagTimer(void*, int) __asm__("func_800359A4");
void DamageTagRemove(Moby*) __asm__("func_80055B18");
void DamageTagCleanup(Moby*, int) __asm__("func_800369B8");
void DamageTagDraw(Moby*, int) __asm__("func_80055D24");
void DamageTagAnimate(Moby*, int) __asm__("func_80034F40");
/* AI-generated reconstruction; not human reviewed. Original Rev0 span
 * 8007BE68..8007C158,188 words. Reuses verified raw264 player-angle and
 * movement interfaces; distinct bit17/other-damage branches retain fresh
 * bit20 reads after SpawnMoby. Tag offsets18/28/2C/2E/37/39 and unsigned
 * halfword increments match source. State0/1 and states2..4 keep original
 * helper order and result256 test. Empty constraints preserve native A0/A5
 * and function-pointer lifetimes without extra instructions. Coordinate
 * units, tag producer, helper effects, particle mapping/cadence remain open. */
typedef struct {
    unsigned char reserved00[24];
    int timer;
    unsigned char reserved1C[12];
    int reserved28;
    unsigned short force, scale;
    unsigned char reserved30[7], resetFlag, reserved38, direction;
} DecodedDamageTag;
extern int D_8006C770;
extern int Raw264PlayerX __asm__("D_80070328");
extern int Raw264PlayerY __asm__("D_80070328+4");
extern unsigned char Raw264PlayerHeading __asm__("D_80070328+0xE");
int Raw264Angle(int, int, int) __asm__("func_8004E880");
int Raw264Direction(int, int, int, int) __asm__("func_800360F8");
int Raw264Random(int, int) __asm__("func_8003636C");
void Raw264Move(Moby*, void*, int) __asm__("func_80037168");
void DamageTagPrepare(Moby*, void*, int, int) __asm__("func_80038BF8");
void func_level_20_8007BE68(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
    register DecodedDamageTag* tag __asm__("$17") = moby->mobyTag;
    Vector3D velocity;
    MATCHING_BARRIER("$4");
    if (moby->state < 2) {
        if (moby->substate == 50) {
            tag->resetFlag = 16;
            moby->substate = 0;
        }
        if (moby->damageFlags & 0x20000) {
            DamageTagPrepare(moby, &tag->reserved28, 1, 2);
            tag->force = 600;
            {
                int direction = moby->unkb;
                if (!direction)
                    direction = Raw264Direction(Raw264Angle(moby->position.x - Raw264PlayerX,
                                                            moby->position.y - Raw264PlayerY, 0),
                                                Raw264PlayerHeading, 32, 64);
                {
                    register int spawnClass __asm__("$4") = 16;
                    register Moby* spawnOwner __asm__("$5") = moby;
                    MATCHING_OBSERVE2(spawnClass, spawnOwner);
                    tag->direction = direction;
                    {
                        register Moby* (*spawn)(int, Moby*)__asm__("$2") = SpawnMoby;
                        MATCHING_OBSERVE(spawn);
                        tag->scale = 256;
                        spawn(spawnClass, spawnOwner);
                    }
                }
            }
            goto damaged;
        } else if (moby->damageFlags) {
            DamageTagPrepare(moby, &tag->reserved28, 1, 2);
            tag->force = 200;
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
            if (moby->damageFlags & 0x100000) {
                tag->force += 200;
                tag->scale += 256;
            }
        damaged:
            moby->unknownCollision = 0;
            moby->state = 2;
            DamageTagAnimate(moby, 2);
        }
    } else if (moby->damageFlags & 0x100000) {
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 0;
        SpawnParticle(1, 3, &moby->position, &velocity);
    }
    switch (moby->state) {
        case 0:
            if (D_8006C770) {
                tag->timer = Raw264Random(90, 300);
                moby->state = 1;
                DamageTagAnimate(moby, 1);
            }
            break;
        case 1:
            Raw264Move(moby, tag, 87);
            if (DamageTagTimer(&tag->timer, 4)) {
                moby->state = 0;
                DamageTagAnimate(moby, 0);
            }
            break;
        case 2:
        case 3:
        case 4:
            if (DamageTagUpdate(moby, &tag->reserved28) == 256) {
                DamageTagDraw(moby, 4);
                DamageTagCleanup(moby, 24);
                moby->substate = 50;
                DamageTagRemove(moby);
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
void func_level_20_8007C158(Moby* moby) {
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
/* SCUS-94467 USA Rev0, original8007C208.
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
 * widths,literals,callbacks and invocation order. Completion byte is8007157F.
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
/* Original assembly SHA256 1546c27c3cbd837bb6a40d76322617211db140c926ca6cc3efc674215bdf9e8d */
#define Level20_7C208Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level20_7C208MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level20_7C208CaptureHigh(dst)                                       \
    do {                                                                    \
        int wholeCapturedHigh;                                              \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedHigh;                                          \
        Level20_7C208Keep(dst);                                             \
    } while (0)
#define Level20_7C208CaptureLow(dst)                                       \
    do {                                                                   \
        int wholeCapturedLow;                                              \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedLow;                                          \
        Level20_7C208Keep(dst);                                            \
    } while (0)
#define Level20_7C208Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level20_7C208BuildCameraVectorOrientationView1(void*, int, int) __asm__("func_800136F0");
int Level20_7C208CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level20_7C208TestPaddedRotatedBoxView1(void*, void*, int, int) __asm__("func_80036220");
void Level20_7C208SetMobyZFromGroundProbeView1(void*) __asm__("func_80037014");
int Level20_7C208UpdateMobyInteractionGateView1(void*, int) __asm__("func_80037BBC");
int Level20_7C208PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
void Level20_7C208SetClampedPlayerTargetAnglesView1(void*) __asm__("func_800492DC");
int Level20_7C208PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level20_7C208TransformVectorByBasisView1(void*, int, int) __asm__("func_8004ED6C");
void Level20_7C208ClearVectorView1(void*) __asm__("func_8004F168");
void Level20_7C208CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level20_7C208AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level20_7C208SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level20_7C208AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
void* Level20_7C208AllocateFiveWordSlotView1(int, int, int, int, int) __asm__("func_80050B00");
void Level20_7C208ClearFiveWordSlotMarkerView1(void*) __asm__("func_80050B88");
void Level20_7C208StartDialogueView1(void*, int, int) __asm__("func_800512E4");
void Level20_7C208DeleteMobyView1(void*) __asm__("func_80055B18");
void Level20_7C208RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
extern unsigned char Level20_7C208Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level20_7C208Data65920View1[] __asm__("D_80065920");
extern int Level20_7C208Data6C574View1 __asm__("D_8006C574");
extern int Level20_7C208Data6C578View1 __asm__("D_8006C578");
extern int Level20_7C208Data6C74CView1 __asm__("D_8006C74C");
extern int Level20_7C208Data6C7C0View1 __asm__("D_8006C7C0");
extern int Level20_7C208Data6E020View1 __asm__("D_8006E020");
extern int Level20_7C208Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level20_7C208Data6E040View1 __asm__("D_8006E040");
extern int Level20_7C208Data6E160View1 __asm__("D_8006E160");
extern int Level20_7C208Data6E174View1 __asm__("D_8006E174");
extern int Level20_7C208Data6E178View1 __asm__("D_8006E178");
extern int Level20_7C208Data6E17CView1 __asm__("D_8006E17C");
extern int Level20_7C208Data6E344View1 __asm__("D_8006E344");
extern int Level20_7C208Data70328View1 __asm__("D_80070328");
extern unsigned char Level20_7C208Data7157FView1 __asm__("D_8007157F");
extern int (*Level20_7C208DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Level20_7C208Data74330View1)() __asm__("unk_ovlheader_80074330");
extern int (*Level20_7C208Data743ECView1)() __asm__("unk_ovlheader_800743EC");
void func_level_20_8007C208(unsigned char* ownerParameter) {
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
    Level20_7C208Keep(ownerThenGeometryOffset20);
    temp_v1 = Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    privateRecord19 = Level20_7C208Field(ownerThenGeometryOffset20, int*, 0);
    switch (temp_v1) {
        case 0:
            resultOrField2 = Level20_7C208Data7157FView1;
            naturalCountRecordOrOffset16 = 0;
            if (resultOrField2) {
                Level20_7C208DeleteMobyView1(ownerThenGeometryOffset20);
                return;
            }
            resultOrField2 = 255;
            Level20_7C208Keep(resultOrField2);
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x41) = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x4C) = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x4D) = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x4A) = resultOrField2;
            do {
                Level20_7C208Keep(naturalCountRecordOrOffset16);
                angleCreatedOrSourceOffset17 = naturalCountRecordOrOffset16 * 2;
                Level20_7C208Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 + naturalCountRecordOrOffset16;
                argumentOrField4 *= 4;
                argumentOrField4 += 0x74;
                argumentOrField4 = privateRecord19 + argumentOrField4;
                argumentOrField5 = ownerThenGeometryOffset20 + 12;
                Level20_7C208CopyVectorView1(argumentOrField4, argumentOrField5);
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
                Level20_7C208Keep(argumentOrField5);
                resultOrField2 = naturalCountRecordOrOffset16 + 1;
                __asm__(""
                        : "=r"(resultOrField2)
                        : "0"(resultOrField2), "r"(argumentOrField4), "r"(fieldHighOrAddress3),
                          "r"(argumentOrField5));
                naturalCountRecordOrOffset16 = resultOrField2;
                Level20_7C208Keep(naturalCountRecordOrOffset16);
                argumentOrField4 = privateRecord19 + argumentOrField4;
                fieldHighOrAddress3 = privateRecord19 + fieldHighOrAddress3;
                resultOrField2 = angleCreatedOrSourceOffset17 + 2;
                Level20_7C208Field(argumentOrField4, unsigned char*, 0x4F4) = argumentOrField6;
                Level20_7C208Field(argumentOrField4, unsigned char*, 0x4F5) = argumentOrField6;
                Level20_7C208Field(argumentOrField4, unsigned char*, 0x4F6) = argumentOrField6;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x575) = resultOrField2;
                resultOrField2 = angleCreatedOrSourceOffset17 + 1;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x576) = resultOrField2;
                resultOrField2 = angleCreatedOrSourceOffset17 + 3;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x577) = resultOrField2;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x574) =
                    angleCreatedOrSourceOffset17;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x578) = argumentOrField5;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x579) =
                    naturalCountRecordOrOffset16;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x57A) = argumentOrField5;
                Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 0x57B) =
                    naturalCountRecordOrOffset16;
            } while (naturalCountRecordOrOffset16 < 32);
            resultOrField2 = naturalCountRecordOrOffset16 * 8;
            resultOrField2 += privateRecord19;
            fieldHighOrAddress3 = -1;
            Level20_7C208Field(resultOrField2, int*, 0x56C) = fieldHighOrAddress3;
            resultOrField2 = Level20_7C208Field(privateRecord19, unsigned short*, 0x6E);
            resultOrField2 &= 0xFF9F;
            resultOrField2 |= 0x40;
            Level20_7C208Field(privateRecord19, short*, 0x6E) = resultOrField2;
            resultOrField2 = 1;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = resultOrField2;
            goto renderOriginalCommonPhase;
        default:
            goto renderOriginalCommonPhase;
        case 1:
            Level20_7C208CopyVectorView1(&originalFrame.sp18, &Level20_7C208Data70328View1);
            originalFrame.sp20 -= Level20_7C208Field(&Level20_7C208Data70328View1, int*, 0x44);
            if (Level20_7C208TestPaddedRotatedBoxView1(&originalFrame.sp18, privateRecord19 + 0x3C,
                                                       0, 0) != 0) {
                if (Level20_7C208Field(&Level20_7C208Data70328View1, int*, 0xB8) == 0) {
                    resultOrField2 = Level20_7C208Field(privateRecord19, int*, 36);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    argumentOrField6 = Level20_7C208Field(resultOrField2, short*, 0);
                    resultOrField2 = Level20_7C208Field(resultOrField2, int*, 12);
                    argumentOrField6 *= 16;
                    argumentOrField5 = argumentOrField6 - 16;
                    argumentOrField5 = resultOrField2 + argumentOrField5;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level20_7C208SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
                    argumentOrField4 = originalFrame.sp18;
                    argumentOrField5 = originalFrame.sp1C;
                    argumentOrField6 = 0;
                    resultOrField2 = Level20_7C208PlanarHeadingLookupView1(
                        argumentOrField4, argumentOrField5, argumentOrField6);
                    naturalCountRecordOrOffset16 = resultOrField2;
                    Level20_7C208Keep(naturalCountRecordOrOffset16);
                    argumentOrField4 = naturalCountRecordOrOffset16 * 2;
                    fieldHighOrAddress3 =
                        Level20_7C208Field(&Level20_7C208Data65920View1, short*, argumentOrField4);
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp18 = resultOrField2;
                    fieldHighOrAddress3 =
                        Level20_7C208Field(&Level20_7C208Data658A0View1, short*, argumentOrField4);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    originalFrame.sp20 = 0;
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp1C = resultOrField2;
                    resultOrField2 = Level20_7C208Field(privateRecord19, int*, 36);
                    argumentOrField5 = argumentOrField4;
                    argumentOrField6 = Level20_7C208Field(resultOrField2, short*, 0);
                    resultOrField2 = Level20_7C208Field(resultOrField2, int*, 12);
                    argumentOrField6 *= 16;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level20_7C208AddVectorView1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    __asm__(""
                            : "=r"(argumentOrField4)
                            : "0"(argumentOrField4), "m"(originalFrame.sp18));
                    argumentOrField5 = naturalCountRecordOrOffset16 + 128;
                    argumentOrField6 = 0;
                    Level20_7C208Data74330View1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    Level20_7C208Field(privateRecord19, signed char*, 5) = 1;
                    Level20_7C208Field(Level20_7C208Field(privateRecord19, int*, 0x24), short*, 2) =
                        1;
                    Level20_7C208CopyVectorView1(
                        &Level20_7C208Data6E17CView1,
                        Level20_7C208Field(Level20_7C208Field(privateRecord19, int*, 0x28), int*,
                                           0xC) +
                            0x10);
                    temp_a1_3 = Level20_7C208Field(Level20_7C208Field(privateRecord19, int*, 0x28),
                                                   int*, 0xC);
                    Level20_7C208BuildCameraVectorOrientationView1(
                        (int)&Level20_7C208Data6E17CView1 - 0x14, temp_a1_3, temp_a1_3 + 0x10);
                    Level20_7C208Data6E160View1 = 0x11;
                    Level20_7C208Data6C74CView1 = 1;
                    Level20_7C208Data6E174View1 = 0;
                    Level20_7C208Data6E178View1 = 0;
                    Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 2U;
                } else {
                    Level20_7C208Field(&Level20_7C208Data70328View1, int*, 0x20C) = 0x10000082;
                    Level20_7C208Field(&Level20_7C208Data70328View1, int*, 0x23C) = 0x12;
                }
            }
            goto renderOriginalCommonPhase;
        case 2:
            if (Level20_7C208TestPaddedRotatedBoxView1(&Level20_7C208Data70328View1,
                                                       privateRecord19 + 0x3C, 0, 0) != 0) {
                naturalCountRecordOrOffset16 = (int)&originalFrame.sp28;
                argumentOrField4 = naturalCountRecordOrOffset16;
                fieldHighOrAddress3 = Level20_7C208Field(privateRecord19, int*, 36);
                Level20_7C208Data6C74CView1 = 1;
                argumentOrField6 = Level20_7C208Field(fieldHighOrAddress3, short*, 0);
                resultOrField2 = Level20_7C208Field(fieldHighOrAddress3, int*, 12);
                argumentOrField6 *= 16;
                argumentOrField5 = argumentOrField6 - 16;
                argumentOrField5 = resultOrField2 + argumentOrField5;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level20_7C208SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                 argumentOrField6);
                argumentOrField4 = originalFrame.sp28;
                argumentOrField5 = originalFrame.sp2C;
                argumentOrField6 = 0;
                resultOrField2 = Level20_7C208PlanarHeadingLookupView1(
                    argumentOrField4, argumentOrField5, argumentOrField6);
                angleCreatedOrSourceOffset17 = resultOrField2;
                Level20_7C208Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
                fieldHighOrAddress3 =
                    Level20_7C208Field(&Level20_7C208Data65920View1, short*, argumentOrField4);
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp28 = resultOrField2;
                fieldHighOrAddress3 =
                    Level20_7C208Field(&Level20_7C208Data658A0View1, short*, argumentOrField4);
                argumentOrField5 = naturalCountRecordOrOffset16;
                originalFrame.sp30 = 0;
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp2C = resultOrField2;
                resultOrField2 = Level20_7C208Field(privateRecord19, int*, 36);
                __asm__(""
                        : "=r"(naturalCountRecordOrOffset16)
                        : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
                argumentOrField4 = naturalCountRecordOrOffset16;
                argumentOrField6 = Level20_7C208Field(resultOrField2, short*, 0);
                resultOrField2 = Level20_7C208Field(resultOrField2, int*, 12);
                argumentOrField6 *= 16;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level20_7C208AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
                argumentOrField4 = naturalCountRecordOrOffset16;
                __asm__(""
                        : "=r"(argumentOrField4)
                        : "0"(argumentOrField4), "m"(originalFrame.sp28));
                argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
                argumentOrField6 = 0;
                Level20_7C208Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
                Level20_7C208Field(privateRecord19, signed char*, 5) = 1;
                Level20_7C208SetClampedPlayerTargetAnglesView1(ownerThenGeometryOffset20 + 0xC);
                if (Level20_7C208AbsoluteByteAngleDeltaView1(
                        (int)(Level20_7C208Data6E040View1 << 0x10) >> 0x14,
                        Level20_7C208PlanarHeadingLookupView1(
                            Level20_7C208Field(ownerThenGeometryOffset20, int*, 0xC) -
                                Level20_7C208Data6E020View1,
                            Level20_7C208Field(ownerThenGeometryOffset20, int*, 0x10) -
                                Level20_7C208Data6E024View1,
                            0)) < 0x18) {
                    Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 3U;
                }
            } else {
                goto restoreOriginalStateOne;
            }
            goto renderOriginalCommonPhase;
        case 4:
            Level20_7C208PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x41) = 1;
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x4C) = 0x10;
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x4D) = 1;
            Level20_7C208SetMobyZFromGroundProbeView1(ownerThenGeometryOffset20);
            argumentOrField6 = 0;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$18");
            recordOrHistoryCount18 = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x44) = 0U;
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x45) = 0;
            temp_v1_6 = Level20_7C208Field(privateRecord19, int*, 0x24);
            temp_v0_11 = (Level20_7C208Field(temp_v1_6, short*, 2) * 0x10) +
                         Level20_7C208Field(temp_v1_6, int*, 0xC);
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x46) =
                Level20_7C208PlanarHeadingLookupView1(
                    Level20_7C208Field(temp_v0_11, int*, 0) -
                        Level20_7C208Field(ownerThenGeometryOffset20, int*, 0xC),
                    Level20_7C208Field(temp_v0_11, int*, 4) -
                        Level20_7C208Field(ownerThenGeometryOffset20, int*, 0x10),
                    argumentOrField6);
        emitOriginalFirstSix:
            resultOrField2 = Level20_7C208Data6C578View1;
            fieldHighOrAddress3 = Level20_7C208Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone4;
            angleCreatedOrSourceOffset17 =
                Level20_7C208DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalFirstSix;
        originalSixDone4:
            recordOrHistoryCount18 = 0;
        emitOriginalFirstTwelve:
            resultOrField2 = Level20_7C208Data6C578View1;
            fieldHighOrAddress3 = Level20_7C208Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone4;
            angleCreatedOrSourceOffset17 =
                Level20_7C208DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level20_7C208Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext4;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x58);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level20_7C208Field(resultOrField2, unsigned char*, 0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x58);
            naturalCountRecordOrOffset16 =
                Level20_7C208Field(angleCreatedOrSourceOffset17, int*, 0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 1);
            argumentOrField5 = 4;
            Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level20_7C208RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level20_7C208Field(naturalCountRecordOrOffset16, int*, 12) = resultOrField2;
            Level20_7C208Field(naturalCountRecordOrOffset16, int*, 16) = 0;
            Level20_7C208Field(naturalCountRecordOrOffset16, int*, 20) = 0;
            Level20_7C208TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level20_7C208Keep(resultOrField2);
            Level20_7C208MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level20_7C208Field(angleCreatedOrSourceOffset17, int*, 20);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level20_7C208Field(angleCreatedOrSourceOffset17, int*, 20) = resultOrField2;
            Level20_7C208CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext4:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalFirstTwelve;
        originalTwelveDone4:
            Level20_7C208Field(privateRecord19, int*, 0x2C) = 0x1E;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 5U;
        case 5:
            if (Level20_7C208CountTimerDownView1(privateRecord19 + 0x2C, 4) != 0) {
                Level20_7C208Data6E160View1 = 0;
                Level20_7C208Field(privateRecord19, signed char*, 5) = 2;
                Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 6U;
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 44);
            resultOrField2 <<= 8;
            Level20_7C208Keep(resultOrField2);
            Level20_7C208MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level20_7C208CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level20_7C208Data6C7C0View1 = fieldHighOrAddress3;
        case 3:
            if (Level20_7C208TestPaddedRotatedBoxView1(&Level20_7C208Data70328View1,
                                                       privateRecord19 + 0x3C, 0, 0) == 0) {
                resultOrField2 = Level20_7C208Field(privateRecord19, int*, 36);
                argumentOrField4 = ownerThenGeometryOffset20 + 12;
                Level20_7C208Field(resultOrField2, short*, 2) = 0;
                resultOrField2 = Level20_7C208Field(privateRecord19, int*, 36);
                angleCreatedOrSourceOffset17 = 0;
                argumentOrField5 = Level20_7C208Field(resultOrField2, int*, 12);
                naturalCountRecordOrOffset16 = 116;
                Level20_7C208CopyVectorView1(argumentOrField4, argumentOrField5);
                Level20_7C208ClearVectorView1(privateRecord19 + 0x30);
                Level20_7C208Field(privateRecord19, int*, 0x2C) = 0;
                do {
                    Level20_7C208CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                                 ownerThenGeometryOffset20 + 0xC);
                    angleCreatedOrSourceOffset17 += 1;
                    naturalCountRecordOrOffset16 += 0xC;
                } while (angleCreatedOrSourceOffset17 < 0x20);
            restoreOriginalStateOne:
                resultOrField2 = 1;
                Level20_7C208Data6E160View1 = 0;
                Level20_7C208Data6C74CView1 = 0;
                Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) =
                    resultOrField2;
                goto renderOriginalCommonPhase;
            }
            naturalCountRecordOrOffset16 = (int)&originalFrame.sp38;
            argumentOrField4 = naturalCountRecordOrOffset16;
            fieldHighOrAddress3 = Level20_7C208Field(privateRecord19, int*, 36);
            Level20_7C208Data6C74CView1 = 1;
            argumentOrField6 = Level20_7C208Field(fieldHighOrAddress3, short*, 0);
            resultOrField2 = Level20_7C208Field(fieldHighOrAddress3, int*, 12);
            argumentOrField6 *= 16;
            argumentOrField5 = argumentOrField6 - 16;
            argumentOrField5 = resultOrField2 + argumentOrField5;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level20_7C208SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = originalFrame.sp38;
            argumentOrField5 = originalFrame.sp3C;
            argumentOrField6 = 0;
            resultOrField2 = Level20_7C208PlanarHeadingLookupView1(
                argumentOrField4, argumentOrField5, argumentOrField6);
            angleCreatedOrSourceOffset17 = resultOrField2;
            Level20_7C208Keep(angleCreatedOrSourceOffset17);
            argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
            fieldHighOrAddress3 =
                Level20_7C208Field(&Level20_7C208Data65920View1, short*, argumentOrField4);
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp38 = resultOrField2;
            fieldHighOrAddress3 =
                Level20_7C208Field(&Level20_7C208Data658A0View1, short*, argumentOrField4);
            argumentOrField5 = naturalCountRecordOrOffset16;
            originalFrame.sp40 = 0;
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp3C = resultOrField2;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 36);
            __asm__(""
                    : "=r"(naturalCountRecordOrOffset16)
                    : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
            argumentOrField4 = naturalCountRecordOrOffset16;
            argumentOrField6 = Level20_7C208Field(resultOrField2, short*, 0);
            resultOrField2 = Level20_7C208Field(resultOrField2, int*, 12);
            argumentOrField6 *= 16;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level20_7C208AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = naturalCountRecordOrOffset16;
            __asm__("" : "=r"(argumentOrField4) : "0"(argumentOrField4), "m"(originalFrame.sp38));
            argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
            argumentOrField6 = 0;
            Level20_7C208Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level20_7C208SetClampedPlayerTargetAnglesView1(ownerThenGeometryOffset20 + 0xC);
            if (Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) == 3) {
                temp_v0_17 = Level20_7C208Field(privateRecord19, int*, 0x24);
                if (Level20_7C208Field(temp_v0_17, short*, 2) ==
                    (Level20_7C208Field(temp_v0_17, short*, 0) - 1)) {
                    Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 4U;
                } else {
                    Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x44) =
                        (unsigned char)(Level20_7C208Field(ownerThenGeometryOffset20,
                                                           unsigned char*, 0x44) +
                                        4);
                    naturalCountRecordOrOffset16 = Level20_7C208Field(
                        Level20_7C208Field(privateRecord19, int*, 0x24), short*, 2);
                    Level20_7C208Keep(naturalCountRecordOrOffset16);
                    Level20_7C208Data743ECView1(
                        ownerThenGeometryOffset20, Level20_7C208Field(privateRecord19, int*, 0x24),
                        privateRecord19 + 0x30, privateRecord19 + 0x2C, 8, 0);
                    fieldHighOrAddress3 = Level20_7C208Field(privateRecord19, int*, 36);
                    Level20_7C208Keep(fieldHighOrAddress3);
                    if (Level20_7C208Field(fieldHighOrAddress3, short*, 2) !=
                        naturalCountRecordOrOffset16) {
                        resultOrField2 = Level20_7C208Field(fieldHighOrAddress3, int*, 12);
                        fieldHighOrAddress3 = naturalCountRecordOrOffset16 * 16;
                        Level20_7C208Keep(fieldHighOrAddress3);
                        fieldHighOrAddress3 += resultOrField2;
                        resultOrField2 = Level20_7C208Field(fieldHighOrAddress3, int*, 12);
                        if (resultOrField2) {
                            Level20_7C208PlayMobySoundEventView1(ownerThenGeometryOffset20, 1, 0);
                        }
                    }
                }
            }
            goto renderOriginalCommonPhase;
        case 6:
            temp_v1_10 = Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x48);
            switch (temp_v1_10) {
                case 0:
                    if (Level20_7C208UpdateMobyInteractionGateView1(ownerThenGeometryOffset20, 0) !=
                        0) {
                        Level20_7C208Data7157FView1 = 1;
                        Level20_7C208StartDialogueView1(ownerThenGeometryOffset20, 0, 1);
                        Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x48) = 1U;
                    }
                    break;
                case 1:
                    if (Level20_7C208Data6E344View1 != temp_v1_10) {
                        Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 7U;
                    }
                    break;
            }
            goto renderOriginalCommonPhase;
        case 7:
            Level20_7C208PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            recordOrHistoryCount18 = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x41) = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x4C) = 0;
            Level20_7C208Field(ownerThenGeometryOffset20, signed char*, 0x4D) = 0;
        emitOriginalSecondSix:
            resultOrField2 = Level20_7C208Data6C578View1;
            fieldHighOrAddress3 = Level20_7C208Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone7;
            angleCreatedOrSourceOffset17 =
                Level20_7C208DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalSecondSix;
        originalSixDone7:
            recordOrHistoryCount18 = 0;
        emitOriginalSecondTwelve:
            resultOrField2 = Level20_7C208Data6C578View1;
            fieldHighOrAddress3 = Level20_7C208Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone7;
            angleCreatedOrSourceOffset17 =
                Level20_7C208DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level20_7C208Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext7;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x58);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level20_7C208Field(resultOrField2, unsigned char*, 0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x58);
            naturalCountRecordOrOffset16 =
                Level20_7C208Field(angleCreatedOrSourceOffset17, int*, 0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level20_7C208Field(fieldHighOrAddress3, unsigned char*, 1);
            argumentOrField5 = 4;
            Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level20_7C208RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level20_7C208Field(naturalCountRecordOrOffset16, int*, 12) = resultOrField2;
            Level20_7C208Field(naturalCountRecordOrOffset16, int*, 16) = 0;
            Level20_7C208Field(naturalCountRecordOrOffset16, int*, 20) = 0;
            Level20_7C208TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level20_7C208Keep(resultOrField2);
            Level20_7C208MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level20_7C208Field(angleCreatedOrSourceOffset17, int*, 20);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level20_7C208Field(angleCreatedOrSourceOffset17, int*, 20) = resultOrField2;
            Level20_7C208CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level20_7C208Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext7:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalSecondTwelve;
        originalTwelveDone7:
            temp_a0_6 = Level20_7C208Field(privateRecord19, int*, 0x64);
            if (temp_a0_6 != 0) {
                Level20_7C208ClearFiveWordSlotMarkerView1(temp_a0_6);
            }
            temp_a0_7 = Level20_7C208Field(privateRecord19, int*, 0x70);
            if (temp_a0_7 != 0) {
                Level20_7C208ClearFiveWordSlotMarkerView1(temp_a0_7);
            }
            Level20_7C208Field(privateRecord19, int*, 0x2C) = 0x1E;
            Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 8U;
        case 8:
            if (Level20_7C208CountTimerDownView1(privateRecord19 + 0x2C, 4) != 0) {
                Level20_7C208DeleteMobyView1(ownerThenGeometryOffset20);
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level20_7C208Field(privateRecord19, int*, 44);
            resultOrField2 <<= 8;
            Level20_7C208Keep(resultOrField2);
            Level20_7C208MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level20_7C208CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level20_7C208Data6C7C0View1 = fieldHighOrAddress3;
            goto renderOriginalCommonPhase;
    }
renderOriginalCommonPhase:
    resultOrField2 = Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 -= 3;
    recordOrHistoryCount18 = 31;
    if ((unsigned int)resultOrField2 >= 4U)
        return;
    angleCreatedOrSourceOffset17 = 0x1DC;
    naturalCountRecordOrOffset16 = 0x1E8;
    do {
        Level20_7C208CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                     privateRecord19 + angleCreatedOrSourceOffset17);
        angleCreatedOrSourceOffset17 -= 12;
        recordOrHistoryCount18--;
        naturalCountRecordOrOffset16 -= 12;
    } while (recordOrHistoryCount18 > 0);
    Level20_7C208CopyVectorView1(privateRecord19 + 0x74, ownerThenGeometryOffset20 + 12);
    fieldHighOrAddress3 = Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 = 3;
    if (fieldHighOrAddress3 != resultOrField2) {
        resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x7C);
        resultOrField2 -= 1024;
        Level20_7C208Field(privateRecord19, int*, 0x7C) = resultOrField2;
    }
    resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x70);
    argumentOrField4 = privateRecord19 + 0x1F4;
    if (!resultOrField2) {
        resultOrField2 = Level20_7C208AllocateFiveWordSlotView1(
            argumentOrField4, privateRecord19 + 0x4F4, privateRecord19 + 0x574,
            privateRecord19 + 0x68, 1);
        Level20_7C208Field(privateRecord19, int*, 0x70) = resultOrField2;
        __asm__("" : "=r"(privateRecord19) : "0"(privateRecord19), "r"(resultOrField2));
    }
    resultOrField2 = Level20_7C208Field(privateRecord19, int*, 0x64);
    emittedVertexCount21 = 0;
    if (!resultOrField2) {
        Level20_7C208Keep(emittedVertexCount21);
        resultOrField2 = Level20_7C208AllocateFiveWordSlotView1(
            privateRecord19 + 0x1F4, privateRecord19 + 0x4F4, privateRecord19 + 0x574,
            privateRecord19 + 0x5C, 1);
        Level20_7C208Field(privateRecord19, int*, 0x64) = resultOrField2;
        __asm__ volatile(""
                         : "=r"(emittedVertexCount21)
                         : "0"(emittedVertexCount21), "r"(resultOrField2));
        emittedVertexCount21 = 0;
    }
    recordOrHistoryCount18 = 0;
    retainedOriginalTableBase = (int)&Level20_7C208Data658A0View1;
    vectorAddress23 = (int)&originalFrame.sp48;
    resultOrField2 = Level20_7C208Field(ownerThenGeometryOffset20, unsigned char*, 0x44);
    ownerThenGeometryOffset20 = 0x1F4;
    resultOrField2 += 64;
    retainedAngle22 = resultOrField2 & 255;
    do {
        argumentOrField6 = 0;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$16");
        naturalCountRecordOrOffset16 = recordOrHistoryCount18 * 2;
        Level20_7C208Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 += recordOrHistoryCount18;
        Level20_7C208Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 *= 4;
        fieldHighOrAddress3 = privateRecord19 + naturalCountRecordOrOffset16;
        angleCreatedOrSourceOffset17 = recordOrHistoryCount18 + 1;
        resultOrField2 = angleCreatedOrSourceOffset17 * 12;
        resultOrField2 = privateRecord19 + resultOrField2;
        argumentOrField7 = Level20_7C208Field(fieldHighOrAddress3, int*, 0x74);
        argumentOrField4 = Level20_7C208Field(resultOrField2, int*, 0x74);
        fieldHighOrAddress3 = Level20_7C208Field(fieldHighOrAddress3, int*, 0x78);
        argumentOrField5 = Level20_7C208Field(resultOrField2, int*, 0x78);
        argumentOrField4 = argumentOrField7 - argumentOrField4;
        argumentOrField5 = fieldHighOrAddress3 - argumentOrField5;
        resultOrField2 = Level20_7C208PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        resultOrField2 += 64;
        resultOrField2 &= 255;
        resultOrField2 *= 2;
        capturedHighOrLow8 = (int)&Level20_7C208Data65920View1;
        Level20_7C208Keep(capturedHighOrLow8);
        fieldHighOrAddress3 = resultOrField2 + capturedHighOrLow8;
        MATCHING_KEEP_VOLATILE_CLOBBER(fieldHighOrAddress3, "$7");
        argumentOrField7 = retainedAngle22 * 2;
        argumentOrField5 = argumentOrField7 + capturedHighOrLow8;
        fieldHighOrAddress3 = Level20_7C208Field(fieldHighOrAddress3, short*, 0);
        argumentOrField4 = Level20_7C208Field(argumentOrField5, short*, 0);
        MATCHING_KEEP2(fieldHighOrAddress3, argumentOrField4);
        fieldHighOrAddress3 >>= 4;
        Level20_7C208MultiplyComplete(fieldHighOrAddress3, argumentOrField4);
        resultOrField2 += retainedOriginalTableBase;
        Level20_7C208CaptureLow(capturedHighOrLow8);
        fieldHighOrAddress3 = capturedHighOrLow8 >> 12;
        originalFrame.sp48 = fieldHighOrAddress3;
        resultOrField2 = Level20_7C208Field(resultOrField2, short*, 0);
        fieldHighOrAddress3 = Level20_7C208Field(argumentOrField5, short*, 0);
        MATCHING_KEEP2(resultOrField2, fieldHighOrAddress3);
        resultOrField2 >>= 4;
        Level20_7C208MultiplyComplete(resultOrField2, fieldHighOrAddress3);
        __asm__(""
                : "=r"(emittedVertexCount21)
                : "0"(emittedVertexCount21), "x"(completeSignedProduct));
        emittedVertexCount21++;
        Level20_7C208Keep(emittedVertexCount21);
        emittedVertexCount21++;
        recordOrHistoryCount18 = angleCreatedOrSourceOffset17;
        naturalCountRecordOrOffset16 += 0x74;
        currentHistoryPositionAddress = privateRecord19 + naturalCountRecordOrOffset16;
        Level20_7C208Keep(currentHistoryPositionAddress);
        argumentOrField6 = vectorAddress23;
        argumentOrField7 += retainedOriginalTableBase;
        MATCHING_KEEP_VOLATILE_CLOBBER(argumentOrField7, "$4");
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        ownerThenGeometryOffset20 += 12;
        Level20_7C208CaptureLow(capturedHighOrLow8);
        resultOrField2 = capturedHighOrLow8 >> 12;
        originalFrame.sp4C = resultOrField2;
        resultOrField2 = Level20_7C208Field(argumentOrField7, short*, 0);
        __asm__(""
                : "=r"(currentHistoryPositionAddress)
                : "0"(currentHistoryPositionAddress), "r"(resultOrField2));
        argumentOrField5 = currentHistoryPositionAddress;
        Level20_7C208Keep(resultOrField2);
        resultOrField2 >>= 4;
        originalFrame.sp50 = resultOrField2;
        Level20_7C208AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        argumentOrField5 = currentHistoryPositionAddress;
        argumentOrField6 = vectorAddress23;
        Level20_7C208SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        resultOrField2 = retainedAngle22 - 4;
        retainedAngle22 = resultOrField2 & 255;
        ownerThenGeometryOffset20 += 12;
    } while (recordOrHistoryCount18 < 32);
    resultOrField2 = emittedVertexCount21 * 12;
    resultOrField2 = privateRecord19 + resultOrField2;
    fieldHighOrAddress3 = -1;
    Level20_7C208Field(resultOrField2, int*, 0x1F4) = fieldHighOrAddress3;
    Level20_7C208Field(resultOrField2, int*, 0x1F8) = fieldHighOrAddress3;
    Level20_7C208Field(resultOrField2, int*, 0x1FC) = fieldHighOrAddress3;
    return;
}
#undef Level20_7C208Field


typedef struct {
    int timer;
    Colour* colours;
} DecodedColourFadeTag;
extern int D_8006C648;
void func_80055B18(Moby*);
void func_level_20_8007CF58(Moby* moby) {
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
void func_level_20_8007D094(Moby* moby) {
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
void ChainWarp(int, int) __asm__("func_800584BC");
/* Rev0 0x8007D224..0x8007D420: 128 original words.
 * Linked indices, private offsets 44/12, byte gate and fresh reloads follow
 * retail. Producers and semantic interpretation remain unresolved.
 * AI generated; not yet human reviewed. See batch 2026-10-05-1593.
 */
void func_level_20_8007D224(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
    register int* tag __asm__("$17") = moby->mobyTag;
    switch (moby->state) {
        case 0: {
            Moby* base = D_8006C550;
            Moby* owner = (Moby*)(tag[0] * sizeof(Moby) + (unsigned int)base);
            int next = *(int*)((unsigned char*)owner->mobyTag + 44);
            if (D_80071570[*(int*)((unsigned char*)base[next].mobyTag + 12)])
                goto remove;
            func_8004F178(&owner->position, &moby->position);
            base = D_8006C550;
            base[tag[0]].position.z += 128;
            base[tag[0]].angle.yaw = moby->angle.yaw;
            func_80055D24(&D_8006C550[tag[0]], 2);
            moby->state = 1;
            break;
        }
        case 1: {
            Moby* base = D_8006C550;
            int next = *(int*)((unsigned char*)base[tag[0]].mobyTag + 44);
            if (D_80071570[*(int*)((unsigned char*)base[next].mobyTag + 12)])
                moby->state = 2;
            break;
        }
        case 2:
            ChainWarp(6, 78);
        remove:
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8007D424.
 * Source: sibling4723.func_level_20_8007D424.json,271 original instructions.
 * Raw units, helper contracts, cadence and runtime parity unresolved. */
#define E20Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int E20DeleteMoby() __asm__("func_80055B18");
int E20CopyVector() __asm__("func_8004F178");
int E20BuildCameraVectorOrientation() __asm__("func_800136F0");
int E20UpdateMobyInteractionGate() __asm__("func_80037BBC");
int E20StartDialogue() __asm__("func_800512E4");
int E20RequestMobyAnimation() __asm__("func_80034F40");
int E20ReadSelectedFrameScalar() __asm__("func_80055E84");
int E20SetClampedPlayerTargetAngles() __asm__("func_800492DC");
int E20CountTimerDown() __asm__("func_800359A4");
extern unsigned char* E20Pool __asm__("D_8006C550");
extern unsigned char E20Flag __asm__("D_80071585");
extern unsigned char E20Progress[] __asm__("D_80066FCC");
extern unsigned char E20Table[] __asm__("D_80071FB0");
extern unsigned char E20Player[] __asm__("D_80070328");
extern int E20Vector[] __asm__("D_8006E17C");
extern int E20Mode __asm__("D_8006E344");
extern int E20SharedGate __asm__("D_8006E160");
extern int E20Contact __asm__("D_8006C770");
extern void* (*E20Spawn)(int, void*)__asm__("SpawnMoby");
void func_level_20_8007D424(void* input) {
    register unsigned char* owner __asm__("$18") = input;
    register unsigned char* tag __asm__("$17");
    register int* vector16 __asm__("$16");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    int state;
    MATCHING_KEEP(owner);
    other = owner[72];
    tag = E20Field(owner, unsigned char**, 0);
    state = other;
    switch (state) {
        case 0:
            value = owner[73];
            if (value)
                goto active0;
            other = tag[0];
            if (other != 1)
                goto initial_table;
            value = E20Flag;
            if (!value)
                goto initial_ready;
            value = E20Field(tag, int*, 40);
            call4 = (void*)(value * 11);
            MATCHING_KEEP(call4);
            value = (int)E20Pool;
            call4 = (void*)((int)call4 << 3);
            E20DeleteMoby((unsigned char*)value + (int)call4);
            goto delete;
        initial_table:
            value = E20Progress[23];
            value = E20Table[value];
            if (!value)
                goto initial_ready;
        delete:
            E20DeleteMoby(owner);
            break;
        initial_ready:
            owner[73] = 1;
            break;
        active0:
            other = tag[0];
            call4 = owner;
            if (other != 1)
                goto query0;
            other = E20Field(tag, int*, 40);
            if (other < 0)
                goto check_player0;
            value = other * 11;
            MATCHING_KEEP(value);
            other = (int)E20Pool;
            value <<= 3;
            value += other;
            value = ((unsigned char*)value)[72] & 128;
            if (!value)
                goto check_player0;
            value = E20Field(tag, int*, 48);
            vector16 = E20Vector;
            arg5 = E20Field((void*)value, int*, 12);
            call4 = vector16;
            E20CopyVector(call4, (unsigned char*)arg5 + 16);
            value = E20Field(tag, int*, 48);
            arg5 = E20Field((void*)value, int*, 12);
            call4 = (unsigned char*)vector16 - 20;
            E20BuildCameraVectorOrientation(call4, (void*)arg5, (unsigned char*)arg5 + 16);
            E20SharedGate = 17;
            E20Field(tag, int*, 52) = 60;
            owner[72] = 3;
        check_player0:
            other = tag[0];
            call4 = owner;
            if (other != 1)
                goto query0;
            other = E20Field(E20Player, int*, 368);
            if (other == 3)
                goto trigger0;
        query0:
            value = E20UpdateMobyInteractionGate(call4, 0);
            call4 = owner;
            if (!value)
                goto trigger0;
            E20StartDialogue(call4, 0, 1);
            owner[72] = 1;
            break;
        trigger0:
            value = tag[2];
            if (!value)
                goto done;
            value = E20Field(tag, int*, 36);
            if (value)
                goto done;
            other = tag[0];
            if (other != 1)
                goto done;
            value = E20Field(E20Player, int*, 320);
            call4 = owner;
            if (value)
                goto done;
            goto enter2;
        case 1:
            value = E20Mode;
            other = 1;
            if (value == other)
                goto done;
            value = tag[0];
            if (value != other)
                goto reset0;
            value = E20Field(tag, int*, 36);
            call4 = owner;
            if (value)
                goto reset0;
        enter2:
            MATCHING_BARRIER("$5");
            arg5 = 2;
            MATCHING_KEEP(arg5);
            ((unsigned char*)call4)[73] = 1;
            ((unsigned char*)call4)[72] = 2;
            E20RequestMobyAnimation(call4, arg5);
            break;
        case 2:
            value = E20Contact;
            if (!value)
                goto subdispatch;
        reset0:
            owner[72] = 0;
            E20RequestMobyAnimation(owner, 0);
            break;
        subdispatch:
            other = owner[73];
            if (other == 1)
                goto sub1;
            if (other == 2)
                goto sub2;
            break;
        sub1:
            value = E20ReadSelectedFrameScalar(owner);
            call4 = (void*)522;
            if (value < 8)
                goto done;
            value = (int)E20Spawn((int)call4, owner);
            E20Field(tag, int*, 36) = value;
            owner[73] = 2;
            break;
        sub2:
            value = E20ReadSelectedFrameScalar(owner);
            if (value < 18)
                goto done;
            owner[73] = 3;
            call4 = E20Field(tag, void**, 36);
            if (!call4)
                goto done;
            ((unsigned char*)call4)[72] = 4;
            break;
        case 3:
            E20Field(E20Player, int*, 524) = 0x10000002;
            other = E20Field(tag, int*, 44);
            call4 = E20Pool;
            value = other * 88;
            call4 = (unsigned char*)call4 + value;
            E20SetClampedPlayerTargetAngles((unsigned char*)call4 + 12);
            value = E20CountTimerDown(tag + 52, 4);
            if (!value)
                goto done;
            other = E20Field(tag, int*, 44);
            value = other * 11;
            MATCHING_KEEP(value);
            other = (int)E20Pool;
            value <<= 3;
            value += other;
            ((unsigned char*)value)[72] = 9;
            E20Field(tag, int*, 52) = 90;
            owner[72] = 4;
            break;
        case 4:
            other = E20Field(tag, int*, 44);
            call4 = E20Pool;
            value = other * 88;
            call4 = (unsigned char*)call4 + value;
            E20SetClampedPlayerTargetAngles((unsigned char*)call4 + 12);
            value = 0x10000002;
            call4 = tag + 52;
            E20Field(E20Player, int*, 524) = value;
            value = E20CountTimerDown(call4, 4);
            if (!value)
                goto done;
            E20SharedGate = 0;
            tag[2] = 2;
            E20Field(tag, int*, 40) = -1;
            owner[72] = 0;
            break;
    }
done:;
}
#undef E20Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007D860.
* Assembly SHA256 cd70992f410e8ab71ea3333244a0085c9248b21f887b6d3d742eb7561bfd8850.
* AI generated; not human reviewed. All496 original instructions and every
* actual branch/call/internal target are required. Frame60 retains SP20..4F
* and every original S0/S1/S2/RA save/restore. No owned selector/data words.
* The original states0/1/2/3, three particle loops, callback setup, status
* byte address in S2 followed by loop-counter ownership, indirect spawn,
* signed trig loads and final shared call remain original instruction chains.
* Empty initialized dependencies and dead-before-producer clobbers emit no
* CPU instructions. No partial HI, FP shortcut or opcode assembly is used.
* Raw field units/fixed point, full helper contracts and caller cadence
* remain unresolved. Cadence here is per invocation. Binary identity does
* not establish synchronized retail runtime or complete game behavior.
* Falsification: every native/linked word and actual target, full EXE and
* every overlay retail hash must remain identical. */
#define Actor20Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor20QueryWorldHeightView1() __asm__("func_8001A358");
short Actor20ConfigureHudEntryView1() __asm__("func_8002803C");
unsigned char Actor20ResetHudEntryByHandleView1() __asm__("func_80028154");
int Actor20RandBetweenView1() __asm__("func_8003636C");
int Actor20RandSignedBetweenView1() __asm__("func_800363DC");
int Actor20ComputeArcVerticalVelocityView1() __asm__("func_800365E4");
unsigned char Actor20UpdateMobyPrivateBallisticMotionView1() __asm__("func_80039714");
unsigned char Actor20PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor20PlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor20CopyVectorView1() __asm__("func_8004F178");
unsigned char Actor20DeleteMobyView1() __asm__("func_80055B18");
extern unsigned char Actor20Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor20Data65920View1 __asm__("D_80065920");
extern int Actor20Data6C58CView1 __asm__("D_8006C58C");
extern int Actor20Data6C628View1 __asm__("D_8006C628");
extern int Actor20Data6C648View1 __asm__("D_8006C648");
extern int Actor20Data6C6C4View1 __asm__("D_8006C6C4");
extern unsigned char Actor20Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Actor20Data70300View1 __asm__("D_80070300");
extern unsigned char Actor20Data71A04View1 __asm__("D_80071A04");
extern unsigned char Actor20Call27A60View1 __asm__("func_80027A60");
extern unsigned char Actor20Call27EE4View1 __asm__("func_80027EE4");
extern unsigned char Actor20Call29AA0View1 __asm__("func_80029AA0");
extern int (*Actor20DataSpawnFragmentsView1)() __asm__("SpawnFragments");
extern void* (*Actor20DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor20DataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_20_8007D860(void* input) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register void* returnedOrAddressPointer2 __asm__("$2");
    register void* (*indirectSpawnCall2)() __asm__("$2");
    register void* ownerRecord17 __asm__("$17");
    register int loopCounterOrStatusAddress18 __asm__("$18");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
    } originalFrame;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord6;
    int temporaryWord8;
    int temporaryWord10;
    int temporaryWord9;
    void* temporaryPointer3;
    void* temporaryPointer4;
    void* temporaryPointer5;
    register void* privateRecord16 __asm__("$16");
    void* temporaryPointer7;
    void* temporaryPointer11;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    privateRecord16 = Actor20Field(ownerRecord17, void**, 0);
    if (Actor20Field(ownerRecord17, unsigned char*, 0x3C) != 0) {
        loopCounterOrStatusAddress18 = 0;
        Actor20UpdateMobyPrivateBallisticMotionView1();
        do {
            rawWord2 = Actor20Field(ownerRecord17, int*, 12);
            argumentWord4 = 0;
            originalFrame.sp20 = rawWord2;
            rawWord2 = Actor20Field(ownerRecord17, int*, 16);
            argumentWord5 = 0x12C;
            originalFrame.sp24 = rawWord2;
            __asm__ __volatile__(""
                                 : "=r"(loopCounterOrStatusAddress18)
                                 : "0"(loopCounterOrStatusAddress18), "r"(argumentWord4),
                                   "r"(argumentWord5)
                                 : "memory");
            rawWord2 = Actor20Field(ownerRecord17, int*, 20);
            loopCounterOrStatusAddress18 += 1;
            originalFrame.sp30 = 0;
            originalFrame.sp34 = 0;
            originalFrame.sp38 = 0;
            originalFrame.sp28 = rawWord2;
            originalFrame.sp20 += Actor20RandSignedBetweenView1(argumentWord4, argumentWord5);
            originalFrame.sp24 += Actor20RandSignedBetweenView1(0, 0x12C);
            originalFrame.sp28 += Actor20RandSignedBetweenView1(0, 0x12C);
            Actor20DataSpawnParticleView1(1, 0x37, &originalFrame.sp20, &originalFrame.sp30);
        } while (loopCounterOrStatusAddress18 <= 0);
        return;
    }
    if ((Actor20Data71A04View1 == 1) && (*Actor20Field(privateRecord16, int**, 0x14) == 0)) {
        *Actor20Field(privateRecord16, int**, 0x14) = (int)Actor20ConfigureHudEntryView1(
            7, 0xC8, &Actor20Call27EE4View1, &Actor20Call27A60View1, &Actor20Call29AA0View1,
            &Actor20Data6C6C4View1, Actor20Data6C628View1);
    }
    temporaryWord9 = Actor20Field(ownerRecord17, unsigned char*, 0x49);
    switch (temporaryWord9) {
        case 0:
            rawWord2 = Actor20Data6C7B4View1;
            rawWord2 &= 8;
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2)
                goto finishOwnerCall;
            rawWord2 = Actor20Data6C58CView1;
            rawWord2 = Actor20Field(&Actor20Data70300View1, unsigned char*, rawWord2);
            rawWord2 &= 8;
            if (rawWord2)
                goto finishOwnerCall;
            rawWord2 = Actor20Data6C628View1;
            Actor20Data6C6C4View1 = 0;
            rawWord2 += 1;
            Actor20Data6C628View1 = rawWord2;
            rawWord2 = 255;
            Actor20Field(ownerRecord17, unsigned char*, 0x4A) = rawWord2;
            rawWord2 = 1;
            Actor20Field(ownerRecord17, unsigned char*, 0x49) = rawWord2;
            return;
        case 1:
            temporaryWord1 = Actor20Field(ownerRecord17, int*, 0x18);
            if (temporaryWord1 & 0x100000) {
                Actor20Field(ownerRecord17, unsigned char*, 0x49) = 2U;
                goto checkTimedFields;
            }
            if (temporaryWord1 & 0x20000) {
                if (Actor20Field(privateRecord16, int*, 0) == 0) {
                    Actor20Field(ownerRecord17, int*, 0x18) = 0;
                    Actor20Field(privateRecord16, int*, 0) = (int)temporaryWord9;
                    Actor20Field(privateRecord16, int*, 4) =
                        (int)Actor20Field(ownerRecord17, unsigned char*, 0x44);
                    Actor20Field(privateRecord16, int*, 8) =
                        (int)Actor20Field(ownerRecord17, unsigned char*, 0x45);
                    Actor20Field(privateRecord16, int*, 0xC) =
                        (int)Actor20Field(ownerRecord17, int*, 0x14);
                    goto checkTimedFields;
                }
                goto updateTimedFields;
            }
        checkTimedFields:
            if (Actor20Field(privateRecord16, int*, 0) != 0) {
            updateTimedFields:
                temporaryWord10 = Actor20Field(privateRecord16, int*, 0) + Actor20Data6C648View1;
                Actor20Field(privateRecord16, int*, 0) = temporaryWord10;
                if (temporaryWord10 < 0x40) {
                    Actor20Field(ownerRecord17, unsigned char*, 0x44) =
                        (unsigned char)(Actor20Field(((temporaryWord10 >> 1) * 2) +
                                                         Actor20Field(privateRecord16, int*, 0x10),
                                                     unsigned char*, 0) +
                                        Actor20Field(privateRecord16, int*, 4));
                    Actor20Field(ownerRecord17, unsigned char*, 0x45) =
                        (unsigned char)(Actor20Field(
                                            ((((int)Actor20Field(privateRecord16, int*, 0) >> 1) *
                                              2) +
                                             Actor20Field(privateRecord16, int*, 0x10)),
                                            unsigned char*, 1) +
                                        Actor20Field(privateRecord16, int*, 8));
                    return;
                }
                Actor20Field(privateRecord16, int*, 0) = 0;
                Actor20Field(ownerRecord17, unsigned char*, 0x44) =
                    (unsigned char)Actor20Field(privateRecord16, int*, 4);
                Actor20Field(ownerRecord17, unsigned char*, 0x45) =
                    (unsigned char)Actor20Field(privateRecord16, int*, 8);
                return;
            }
            break;
        case 2:
            Actor20PlayMobySoundEventView1(ownerRecord17, 0, 0);
            if (Actor20Data71A04View1 == 0) {
                rawWord2 = Actor20Field(privateRecord16, int*, 0x14);
                rawWord2 = Actor20Field(rawWord2, int*, 0);
                argumentWord4 = 7;
                if (!rawWord2) {
                    argumentWord5 = 200;
                    *Actor20Field(privateRecord16, int**, 0x14) =
                        (int)Actor20ConfigureHudEntryView1(
                            argumentWord4, argumentWord5, &Actor20Call27EE4View1,
                            &Actor20Call27A60View1, &Actor20Call29AA0View1, &Actor20Data6C6C4View1,
                            Actor20Data6C628View1);
                }
            }
            loopCounterOrStatusAddress18 = (int)&Actor20Data71A04View1;
            rawWord2 = 1;
            Actor20Field(loopCounterOrStatusAddress18, unsigned char*, 0) = rawWord2;
            rawWord3 = Actor20Data6C628View1;
            rawWord2 = Actor20Data6C6C4View1;
            rawWord3 -= 1;
            rawWord2 += 1;
            Actor20Data6C628View1 = rawWord3;
            Actor20Data6C6C4View1 = rawWord2;
            argumentWord4 = 5;
            if (rawWord3 == 0) {
                temporaryWord2 = *Actor20Field(privateRecord16, int**, 0x14);
                if (temporaryWord2 != 0) {
                    Actor20ResetHudEntryByHandleView1(temporaryWord2);
                    rawWord2 = Actor20Field(privateRecord16, int*, 0x14);
                    Actor20Field(rawWord2, int*, 0) = 0;
                    __asm__ __volatile__("" ::: "$2", "memory");
                    rawWord2 = 2;
                    Actor20Field(loopCounterOrStatusAddress18, unsigned char*, 0) = rawWord2;
                }
                argumentWord4 = 5;
                argumentWord6 = (int)ownerRecord17;
                argumentWord5 = Actor20Field(ownerRecord17, short*, 0x36);
                __asm__ __volatile__("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                                     : "$18", "memory");
                loopCounterOrStatusAddress18 = 0;
                Actor20DataSpawnFragmentsView1(argumentWord4, argumentWord5, argumentWord6,
                                               Actor20Field(privateRecord16, int*, 0x20), 1, 0x100);
                do {
                    rawWord2 = Actor20Field(ownerRecord17, int*, 12);
                    argumentWord4 = 0;
                    originalFrame.sp20 = rawWord2;
                    rawWord2 = Actor20Field(ownerRecord17, int*, 16);
                    argumentWord5 = 0x2BC;
                    originalFrame.sp24 = rawWord2;
                    __asm__ __volatile__(""
                                         : "=r"(loopCounterOrStatusAddress18)
                                         : "0"(loopCounterOrStatusAddress18), "r"(argumentWord4),
                                           "r"(argumentWord5)
                                         : "memory");
                    rawWord2 = Actor20Field(ownerRecord17, int*, 20);
                    loopCounterOrStatusAddress18 += 1;
                    originalFrame.sp40 = 0;
                    originalFrame.sp44 = 0;
                    originalFrame.sp48 = 0;
                    originalFrame.sp28 = rawWord2;
                    originalFrame.sp20 +=
                        Actor20RandSignedBetweenView1(argumentWord4, argumentWord5);
                    originalFrame.sp24 += Actor20RandSignedBetweenView1(0, 0x2BC);
                    originalFrame.sp28 += Actor20RandBetweenView1(0, 0x5DC);
                    Actor20DataSpawnParticleView1(1, 0x37, &originalFrame.sp20,
                                                  &originalFrame.sp40);
                } while (loopCounterOrStatusAddress18 < 0xA);
                argumentWord4 = 132;
                Actor20Field(ownerRecord17, signed char*, 0x41) = 0;
                Actor20Field(ownerRecord17, signed char*, 0x4C) = 0;
                Actor20Field(ownerRecord17, signed char*, 0x4D) = 0;
                __asm__ __volatile__("" ::"r"(argumentWord4) : "$5", "memory");
                indirectSpawnCall2 = Actor20DataSpawnMobyView1;
                __asm__ __volatile__("" ::: "$5", "memory");
                argumentWord5 = (int)ownerRecord17;
                MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(indirectSpawnCall2, argumentWord5, "memory");
                Actor20Field(ownerRecord17, int*, 8) = 0;
                returnedOrAddressPointer2 = indirectSpawnCall2(argumentWord4, argumentWord5);
                MATCHING_KEEP(returnedOrAddressPointer2);
                rawWord3 = 6;
                Actor20Field(privateRecord16, void**, 0x1C) = returnedOrAddressPointer2;
                Actor20Field(returnedOrAddressPointer2, unsigned char*, 0x48) = rawWord3;
                __asm__ __volatile__("" ::: "$3", "memory");
                rawWord3 = 255;
                Actor20Field(ownerRecord17, unsigned char*, 0x4A) = rawWord3;
                Actor20Field(Actor20Field(privateRecord16, void**, 0x1C), unsigned char*, 0x4A) =
                    rawWord3;
                Actor20Field(Actor20Field(privateRecord16, void**, 0x1C), signed char*, 0x4C) =
                    0x30;
                *Actor20Field(Actor20Field(privateRecord16, void**, 0x1C), short**, 0) = 3;
                temporaryPointer11 = Actor20Field(privateRecord16, void**, 0x18);
                if (temporaryPointer11 != 0) {
                    rawWord3 = (int)temporaryPointer11;
                    rawWord2 = Actor20Field(rawWord3, short*, 2);
                    rawWord3 = Actor20Field(rawWord3, int*, 12);
                    argumentWord4 = Actor20Field(ownerRecord17, int*, 12);
                    argumentWord5 = Actor20Field(ownerRecord17, int*, 16);
                    rawWord2 <<= 4;
                    rawWord2 += rawWord3;
                    MATCHING_KEEP(rawWord2);
                    rawWord3 = Actor20Field(rawWord2, int*, 0);
                    rawWord2 = Actor20Field(rawWord2, int*, 4);
                    argumentWord4 = rawWord3 - argumentWord4;
                    argumentWord5 = rawWord2 - argumentWord5;
                    rawWord2 = Actor20PlanarHeadingLookupView1(argumentWord4, argumentWord5, 0);
                    argumentWord4 = (int)ownerRecord17 + 12;
                    MATCHING_KEEP(argumentWord4);
                    rawWord2 <<= 1;
                    rawWord3 = Actor20Field(&Actor20Data65920View1, short*, rawWord2);
                    __asm__ __volatile__("" ::: "$6", "memory");
                    argumentWord6 = 128;
                    MATCHING_KEEP2(rawWord3, argumentWord6);
                    rawWord3 >>= 5;
                    Actor20Field(privateRecord16, int*, 4) = rawWord3;
                    rawWord2 = Actor20Field(&Actor20Data658A0View1, short*, rawWord2);
                    rawWord3 = Actor20Field(privateRecord16, int*, 24);
                    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(rawWord2, "memory");
                    rawWord2 >>= 5;
                    Actor20Field(privateRecord16, int*, 8) = rawWord2;
                    Actor20Field(privateRecord16, int*, 12) =
                        Actor20ComputeArcVerticalVelocityView1(argumentWord4,
                                                               Actor20Field(rawWord3, void**, 12),
                                                               argumentWord6, -8, 0);
                    temporaryPointer7 =
                        Actor20Field(Actor20Field(privateRecord16, void**, 0x18), void**, 0xC);
                    temporaryWord6 = Actor20Field(temporaryPointer7, int*, 0x10);
                    Actor20Field(Actor20Field(privateRecord16, void**, 0x1C), unsigned char*,
                                 0x46) =
                        Actor20PlanarHeadingLookupView1(
                            temporaryWord6 - Actor20Field(temporaryPointer7, int*, 0),
                            Actor20Field(temporaryPointer7, int*, 0x14) -
                                Actor20Field(temporaryPointer7, int*, 4),
                            0, temporaryWord6);
                } else {
                    Actor20Field(privateRecord16, int*, 4) = 0;
                    Actor20Field(privateRecord16, int*, 8) = 0;
                    Actor20Field(privateRecord16, int*, 0xC) = 0xC0;
                    Actor20Field(Actor20Field(privateRecord16, void**, 0x1C), unsigned char*,
                                 0x46) =
                        (unsigned char)Actor20Field(ownerRecord17, unsigned char*, 0x46);
                }
                Actor20Field(ownerRecord17, unsigned char*, 0x49) = 3U;
                return;
            }
            argumentWord4 = 5;
            argumentWord6 = (int)ownerRecord17;
            argumentWord5 = Actor20Field(ownerRecord17, short*, 0x36);
            __asm__ __volatile__("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                                 : "$18", "memory");
            loopCounterOrStatusAddress18 = 0;
            Actor20DataSpawnFragmentsView1(argumentWord4, argumentWord5, argumentWord6,
                                           Actor20Field(privateRecord16, int*, 0x20), 1, 0x200);
            do {
                rawWord2 = Actor20Field(ownerRecord17, int*, 12);
                argumentWord4 = 0;
                originalFrame.sp20 = rawWord2;
                rawWord2 = Actor20Field(ownerRecord17, int*, 16);
                argumentWord5 = 0x2BC;
                originalFrame.sp24 = rawWord2;
                __asm__ __volatile__(""
                                     : "=r"(loopCounterOrStatusAddress18)
                                     : "0"(loopCounterOrStatusAddress18), "r"(argumentWord4),
                                       "r"(argumentWord5)
                                     : "memory");
                rawWord2 = Actor20Field(ownerRecord17, int*, 20);
                loopCounterOrStatusAddress18 += 1;
                originalFrame.sp30 = 0;
                originalFrame.sp34 = 0;
                originalFrame.sp38 = 0;
                originalFrame.sp28 = rawWord2;
                originalFrame.sp20 += Actor20RandSignedBetweenView1(argumentWord4, argumentWord5);
                originalFrame.sp24 += Actor20RandSignedBetweenView1(0, 0x2BC);
                originalFrame.sp28 += Actor20RandBetweenView1(0, 0x5DC);
                Actor20DataSpawnParticleView1(1, 0x37, &originalFrame.sp20, &originalFrame.sp30);
                argumentWord4 = (int)ownerRecord17;
            } while (loopCounterOrStatusAddress18 < 0xA);
            __asm__ __volatile__("" ::"r"(argumentWord4), "i"(0x8007DF28) : "memory");
            goto finishOwnerCall;
        case 3:
            temporaryPointer3 = Actor20Field(privateRecord16, void**, 0x1C);
            Actor20Field(privateRecord16, int*, 0xC) =
                (int)(Actor20Field(privateRecord16, int*, 0xC) - 8);
            Actor20Field(temporaryPointer3, int*, 0xC) =
                (int)(Actor20Field(temporaryPointer3, int*, 0xC) +
                      Actor20Field(privateRecord16, int*, 4));
            temporaryPointer4 = Actor20Field(privateRecord16, void**, 0x1C);
            Actor20Field(temporaryPointer4, int*, 0x10) =
                (int)(Actor20Field(temporaryPointer4, int*, 0x10) +
                      Actor20Field(privateRecord16, int*, 8));
            temporaryPointer5 = Actor20Field(privateRecord16, void**, 0x1C);
            Actor20Field(temporaryPointer5, int*, 0x14) =
                (int)(Actor20Field(temporaryPointer5, int*, 0x14) +
                      Actor20Field(privateRecord16, int*, 0xC));
            Actor20CopyVectorView1(&originalFrame.sp20,
                                   Actor20Field(privateRecord16, void**, 0x1C) + 0xC);
            originalFrame.sp28 += 0x200;
            temporaryWord8 = Actor20QueryWorldHeightView1(&originalFrame.sp20, 0x200);
            originalFrame.sp28 = temporaryWord8;
            if (temporaryWord8 != 0) {
                Actor20Field(Actor20Field(privateRecord16, void**, 0x1C), int*, 0x14) =
                    temporaryWord8;
                rawWord2 = Actor20Field(privateRecord16, int*, 12);
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                    Actor20Field(privateRecord16, int*, 4) = 0;
                    Actor20Field(privateRecord16, int*, 8) = 0;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord2, "memory");
                    rawWord2 >>= 1;
                    Actor20Field(privateRecord16, int*, 12) = rawWord2;
                    rawWord2 = rawWord2 < 16;
                    argumentWord4 = (int)ownerRecord17;
                    if (rawWord2) {
                        rawWord2 = Actor20Field(privateRecord16, int*, 0x1C);
                        Actor20Field(rawWord2, unsigned char*, 0x48) = 0;
                        goto finishOwnerCall;
                    }
                }
            }
            break;
    }
    return;
finishOwnerCall:
    Actor20DeleteMobyView1(argumentWord4);
}
#undef Actor20Field


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
void func_level_20_8007E020(Moby* moby) {
    Vector3D sp10, sp20, sp30, sp40, sp50;
    int temp_v1_3, count;
    Vehicle546Tag* mobyTag = (Vehicle546Tag*)moby->mobyTag;
    switch (moby->state) {
        case 0:
            switch (moby->substate) {
                case 0:
                    if (progressFlags.lvl20_WhirligigUsable)
                        goto deleteVehicle;
                    if (D_8006C73C != 0 && currentLevel != D_8006C73C &&
                        ((temp_v1_3 = D_8006C73C % 10, temp_v1_3 == 0) ||
                         (temp_v1_3 == 7 && D_8006C73C < 60))) {
                        moby->position.z += 0xC00;
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &moby->position);
                        camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        func_8004F178(&spyro.position, &moby->position);
                        spyro.position.z += spyro.unk4a + 0x280;
                        func_80012BA8(&camera.unk170);
                        func_8004F178(&camera.unk184, &camera.unk60);
                        moby->substate = 1;
                        moby->state = 7;
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
                            func_80055B18(moby);
                            return;
                        }
                        if (currentLevel != 10 || Vehicle546Table[lvlIdToIndex[17]] != 0) {
                            moby->substate = 1;
                            moby->state = 3;
                        } else {
                            moby->substate = 2;
                            moby->state = 1;
                            moby->position.z += 0xC00;
                        }
                        func_80055D24(moby, 2);
                        mobyTag->timer = 0;
                    }
                    break;
                case 1:
                    moby->state = 3;
                    break;
                case 2:
                    moby->position.z += 0xC00;
                    func_80055D24(moby, 2);
                    mobyTag->timer = 0;
                    moby->state = 1;
                    break;
            }
            func_8003B7B4(&moby->substate, 1, &unsavedData);
            break;
        case 2:
            moby->position.z -= 64;
            func_8004F178(&sp10, &moby->position);
            sp10.z += 512;
            sp10.z = func_8001A358(&sp10, 512);
            if (sp10.z != 0) {
                moby->position.z = sp10.z;
                moby->state = 3;
                func_8003B7B4(&moby->state, 1, &savedData);
                func_8003B7B4(&moby->state, 1, &unsavedData);
                moby->substate = 0;
            }
            func_80055D24(moby, 2);
            break;
        case 3:
            if (spyro.m_StoodOnMoby == moby) {
                moby->state = 4;
                case 4:
                    if (spyro.m_StoodOnMoby != moby) {
                        camera.unk168 = 0;
                        moby->state = 3;
                    } else {
                        if (ovlHeader.unk2b(&moby->position, moby->angle.yaw, 0) != 0) {
                            Vehicle506Global = 1;
                            func_8005663C();
                            moby->state = 5;
                        }
                        func_8004F178(&camera.unk184, &moby->position);
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &moby->position);
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
                moby->state = 6;
            } else {
                moby->state = 8;
            }
            break;

        case 6:
            moby->position.z = (int)(moby->position.z + 0x40);
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &moby->position);
            spyro.unk19.z += spyro.unk4a + 0x280;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &moby->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &moby->position);
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
                        func_80054F94(D_80070104.loadLevel, moby);
                    } else {
                        progressFlags.lvl63_BiancaStrikesBack = 1;
                        func_800584BC(6, 0x3F);
                    }
                }
            }
            func_80055D24(moby, 2);
            break;

        case 7:
            moby->position.z -= 0x40;
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &moby->position);
            spyro.unk19.z += spyro.unk4a + 0x280;
            spyro.unk18.roll = moby->angle.roll;
            spyro.unk18.pitch = moby->angle.pitch;
            spyro.unk18.yaw = moby->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            func_8004F178(&sp20, &moby->position);
            sp20.z += 0x200;
            sp20.z = func_8001A358(&sp20, 0x200);
            if (sp20.z != 0) {
                moby->position.z = sp20.z;
                func_80013B7C(0);
                moby->state = 8;
            }
            func_80055D24(moby, 2);
            break;

        case 8:
            sp30.x = D_80065920[moby->angle.yaw];
            sp30.y = D_800658A0[moby->angle.yaw];
            sp30.z = 0;
            func_8004F194(&sp30, &sp30, &moby->position);
            if (ovlHeader.unk2c(&sp30) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp30, moby->angle.yaw, 0);
                mobyTag->timer = 120;
                moby->state = 9;
            }
            break;

        case 9:
            sp40.x = D_80065920[moby->angle.yaw];
            sp40.y = D_800658A0[moby->angle.yaw];
            sp40.z = 0;
            func_8004F194(&sp40, &sp40, &moby->position);
            if (ovlHeader.unk2b(&sp40, moby->angle.yaw, 0) != 0) {
                func_8004F178(&sp50, &spyro.position);
                sp50.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp50, spyro.bodyRotation.yaw);
                moby->state = 3;
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
void func_level_20_8007E8A8(Moby* moby) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3;
    Vehicle635Tag* mobyTag;

    mobyTag = (Vehicle635Tag*)moby->mobyTag;
    switch (moby->state) {

        case 0:
            switch (moby->substate) {
                case 0:
                    if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                        func_80055B18(moby);
                        return;
                    } else {
                        moby->state = 1;
                        if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) &&
                            ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) ||
                             ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) &&
                            (moby->mobyClass == D_8006C528) && D_8006C73C != 47) {
                            func_80034F80(moby, 2);
                            moby->position.z += 0xC00;
                            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                          &moby->position);
                            camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                            camera.unk170.yaw = 0;
                            camera.unk170.pitch = 0;
                            spyro.unk17a = 0x1001A000;
                            spyro.unk20[1] = 0;
                            func_8004F178(&spyro.unk19, &moby->position);
                            spyro.unk19.z += spyro.unk4a + 0x604;
                            spyro.unk18.roll = moby->angle.roll;
                            spyro.unk18.pitch = moby->angle.pitch;
                            spyro.unk18.yaw = moby->angle.yaw;
                            func_80012BA8(&camera.unk170);
                            func_8004F178(&camera.unk184, &camera.unk60);
                            moby->state = 8;
                        } else if (moby->state == 0) {
                            moby->state = 1;
                        }
                    }
                    break;

                default:
                    break;

                case 1:
                    func_80034F80(moby, 2);
                    moby->position.z += 0xF00;
                    func_80055D24(moby, 2);
                    mobyTag->timer = 0;
                    moby->state = 10;
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
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
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
                func_80034F40(moby, 1);
                spyro.unk17a = 0x10018000;
                func_8004F178(&spyro.unk19, &moby->position);
                spyro.unk19.z += 0x400;
                {
                    int height = func_8001A358(&spyro.unk19, 0x800);
                    spyro.unk20[1] = 0;
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk19.z = height + spyro.unk4a;
                    spyro.unk18.yaw = moby->angle.yaw;
                }
                moby->state = 4;
            } else
                moby->state = 6;
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
                spyro.unk18.yaw = moby->angle.yaw;
            }
            if (D_8006C770 != 0) {
                func_80034F80(moby, 2);
                spyro.unk17a |= 0x2000;
                if (Vehicle635Moby != 0) {
                    *((unsigned char*)Vehicle635Moby + 0x4C) = 0;
                    *((unsigned char*)Vehicle635Moby + 0x4D) = 0;
                }
                mobyTag->timer = 120;
                moby->state = 5;
            }
            break;
        case 5:
            moby->position.z = (int)(moby->position.z + 0x40);
            spyro.unk17a = 0x1001A000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &moby->position);
            spyro.unk19.z += spyro.unk4a + 0x604;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &moby->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &moby->position);
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
                        func_80054F94(D_80070104.loadLevel, moby);
                    } else {
                        progressFlags.lvl67_AMonsterToEndAllMonsters = 1;
                        func_800584BC(6, 0x43);
                    }
                }
            }
            func_80055D24(moby, 2);
            break;

        case 6:
            sp10.x = D_80065920[moby->angle.yaw];
            sp10.y = D_800658A0[moby->angle.yaw];
            sp10.z = 0;
            func_8004F194(&sp10, &sp10, &moby->position);
            if (ovlHeader.unk2c(&sp10) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp10, moby->angle.yaw, 0);
                moby->state = 7;
            }
            break;

        case 7:
            sp20.x = D_80065920[moby->angle.yaw];
            sp20.y = D_800658A0[moby->angle.yaw];
            sp20.z = 0;
            func_8004F194(&sp20, &sp20, &moby->position);
            if (ovlHeader.unk2b(&sp20, moby->angle.yaw, 0) != 0) {
                func_8004F178(&sp30, &spyro.position);
                sp30.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp30, spyro.bodyRotation.yaw);
                moby->state = 1;
            }
            break;

        case 8:
            moby->position.z -= 0x40;
            spyro.unk17a = 0x1001A000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &moby->position);
            spyro.unk19.z += spyro.unk4a + 0x604;
            spyro.unk18.roll = moby->angle.roll;
            spyro.unk18.pitch = moby->angle.pitch;
            spyro.unk18.yaw = moby->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            func_8004F178(&sp40, &moby->position);
            moby->position.z += 0x400;
            sp40.z += 0x200;
            sp40.z = func_8001A358(&sp40, 0x200);
            if (sp40.z != 0) {
                moby->position.z = sp40.z;
                func_80034F40(moby, 3);
                spyro.unk17a = 0x10018000;
                func_8004F178(&spyro.unk19, &moby->position);
                spyro.unk19.z += 0xE00;
                {
                    int height = func_8001A358(&spyro.unk19, 0x800);
                    spyro.unk20[1] = 0;
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk19.z = height + spyro.unk4a;
                    spyro.unk18.yaw = moby->angle.yaw;
                }
                moby->state = 9;
            } else {
                moby->position.z -= 0x400;
            }
            func_80055D24(moby, 2);
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
                spyro.unk18.yaw = moby->angle.yaw;
            }
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            if (D_8006C770 != 0) {
                func_80034F80(moby, 0);
                func_80013B7C(0);
                moby->state = 6;
            }
            break;
    }
    func_80055D24(moby, 1);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007F294.
* AI generated; not human reviewed. All935 original instructions,six switch
* selectors and every actual destination must match:941 original owned words.
* FrameB8hex184 saves S0..S7/RA;SP38..8F keeps the original independent vectors
* and SP88 word phases. Thirteen physical callback arguments occupy the
* original outgoing area. Callback meaning and raw field units remain open.
* Verified level40 func8007C668 supplies shared coordinate/descriptor chains.
* Target global transition,three-way substate dispatch,state5,S6=256/S7=2,
* old timer/300,vector addresses and shared867/868 entries are independently
* decoded from this target. The donor-only66FCC branch is absent here.
* Original327 timer is the dividend before333/335 update it. Old299/step1
* gives new300,target256;using the updated300 would incorrectly yield255.
* Complete signed /300 and dynamic remainders retain all original results,
* zero/overflow traps and destinations. No isolated HI/LO product input.
* State5 preserves complete pointers,three angle calls,SP88 observations,
* independent positive/negative direction entries784/790,signed LH samples,
* arithmetic right shifts,late vector zero,flag/callback argument phases,
* descriptor projection and state stores. The original two field loads761/
* 762 remain separately ordered. Word metadata is dominated by full original
* stores;no padding or incoming saved register content is consumed.
* Empty metadata reads complete initialized values/addresses/written fields
* or clobbers dead registers before fresh whole producers;zero CPU words.
* No opcode asm,partialHI/LO,fixedFP,overlapping live fixed aliases or compiler/
* filter/flag changes. Known timer,angle/delta helper views reuse matched
* EXE/header evidence. Raw physical callback views invent no helper contract.
* Confidence is binary identity after every native/linked instruction,actual
* control/call/table target,owned selector and full EXE/every-overlay hash.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation,
* Rev1 mapping and synchronized runtime remain open. Next:human review and
* retail captures. The engine/browser implementation is unchanged.
*/
/* Original assembly SHA256 ef3e39c1112560e704f994d88e2add13ff3a25c2944c56f5f39bda1cfbd5d689 */
#define Level20_7F294Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level20_7F294SetCameraMode11TargetView1() __asm__("func_80013D44");
int Level20_7F294RequestMobyAnimationView1() __asm__("func_80034F40");
int Level20_7F294UpdateMobyMotionDescriptorView1() __asm__("func_80035194");
int Level20_7F294TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level20_7F294CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level20_7F294UpdateMobyPathMotionView1() __asm__("func_80035A80");
int Level20_7F294RandBetweenView1() __asm__("func_8003636C");
int Level20_7F294GetClosestPathNodeView1() __asm__("func_8003645C");
int Level20_7F294EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level20_7F294SetMobyZFromGroundProbeView1() __asm__("func_80037014");
int Level20_7F294InitializeMobyMotionStateView1() __asm__("func_80038BF8");
int Level20_7F294MarkMobyCollectionBitView1() __asm__("func_8003BA00");
int Level20_7F294PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level20_7F294PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level20_7F294ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Level20_7F294CopyVectorView1() __asm__("func_8004F178");
int Level20_7F294AddVectorView1() __asm__("func_8004F194");
int Level20_7F294SubtractVectorView1() __asm__("func_8004F1C8");
int Level20_7F294AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level20_7F294ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level20_7F294DeleteMobyView1() __asm__("func_80055B18");
int Level20_7F294RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level20_7F294InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Level20_7F294Data658A0View1 __asm__("D_800658A0");
extern int Level20_7F294Data65920View1 __asm__("D_80065920");
extern int Level20_7F294Data6C550View1 __asm__("D_8006C550");
extern int Level20_7F294Data6C58CView1 __asm__("D_8006C58C");
extern int Level20_7F294Data6C648View1 __asm__("D_8006C648");
extern int Level20_7F294Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level20_7F294Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level20_7F294Data6E048View1 __asm__("D_8006E048");
extern int Level20_7F294Data70300View1 __asm__("D_80070300");
extern int Level20_7F294Data70328View1 __asm__("D_80070328");
extern int (*Level20_7F294Data74314View1)() __asm__("unk_ovlheader_80074314");
void func_level_20_8007F294(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        originalTarget256 __asm__("$22"), originalSubstateTwo __asm__("$23");
    register int privateRecord18 __asm__("$18"), retainedIndexVectorHeadingOrFlag16 __asm__("$16"),
        retainedPlayerBaseHeadingOrFlag17 __asm__("$17"),
        retainedQuotientTargetOrLinkedRecord20 __asm__("$20"), retainedPlayerBase21 __asm__("$21");
    struct {
        int sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C,
            sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C;
    } originalFrame;
    int temporaryWord8;
    int temporaryWord14;
    int temporaryWord9;
    int temporaryWord12;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord15;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord13;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    privateRecord18 = Level20_7F294Field(ownerRecord19, void**, 0);
    if ((unsigned int)(Level20_7F294Field(ownerRecord19, unsigned char*, 0x48) - 3) >= 2U) {
        if (Level20_7F294Field(ownerRecord19, int*, 0x18) != 0) {
            Level20_7F294InitializeMobyMotionStateView1(ownerParameter, privateRecord18 + 24, 1, 3);
            Level20_7F294Field(privateRecord18, signed char*, 0x2B) = 0;
        } else if ((Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0x1D0) != 0) ||
                   (Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0x140) != 0)) {
            argumentWord4 = Level20_7F294Field(privateRecord18, int*, 4);
            rawWord3 = Level20_7F294Data6C550View1;
            Level20_7F294Field(ownerRecord19, signed char*, 65) = 0;
            Level20_7F294Field(ownerRecord19, signed char*, 76) = 0;
            Level20_7F294Field(ownerRecord19, signed char*, 77) = 0;
            Level20_7F294Field(ownerRecord19, int*, 8) = 0;
            rawWord2 = argumentWord4 * 88;
            rawWord3 += rawWord2;
            Level20_7F294Field(rawWord3, signed char*, 65) = 0;
            Level20_7F294Field(rawWord3, signed char*, 76) = 0;
            Level20_7F294Field(rawWord3, signed char*, 77) = 0;
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 4);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level20_7F294Data6C550View1;
            rawWord2 += rawWord3;
            Level20_7F294Field(rawWord2, int*, 8) = 0;
            Level20_7F294Field(Level20_7F294Field(privateRecord18, void**, 0x14), short*, 2) = 0;
            Level20_7F294Field(ownerRecord19, unsigned char*, 0x48) = 5U;
        }
    }
    rawWord3 = Level20_7F294Field(ownerRecord19, unsigned char*, 72);
    MATCHING_KEEP(rawWord3);
    switch (rawWord3) {
        case 0:
        case 1:
            MATCHING_OBSERVE_VOLATILE(rawWord3);
            temporaryWord10 = Level20_7F294Field(ownerRecord19, unsigned char*, 0x49);
            switch (temporaryWord10) {
                case 0:
                    if ((Level20_7F294Data6C7B4View1 & 4) ||
                        (Level20_7F294Field((int)&Level20_7F294Data70300View1, unsigned char*,
                                            Level20_7F294Data6C58CView1) &
                         4)) {
                        temporaryWord1 = (Level20_7F294Field(privateRecord18, int*, 4) * 0x58) +
                                         Level20_7F294Data6C550View1;
                        if (!(Level20_7F294Field(temporaryWord1, unsigned char*, 0x48) & 0x80)) {
                            Level20_7F294DeleteMobyView1(temporaryWord1);
                        }
                        Level20_7F294DeleteMobyView1(ownerRecord19);
                        return;
                    }
                    Level20_7F294Field(ownerRecord19, unsigned char*, 0x55) = 128;
                    Level20_7F294Field(ownerRecord19, unsigned char*, 0x56) = 192;
                    Level20_7F294Field(ownerRecord19, signed char*, 0x54) = 0;
                    Level20_7F294Field(ownerRecord19, signed char*, 0x57) = 0;
                    Level20_7F294Field(ownerRecord19, unsigned char*, 0x49) = 1U;
                    temporaryWord2 = Level20_7F294Data6C550View1 +
                                     (Level20_7F294Field(privateRecord18, int*, 4) * 0x58);
                    Level20_7F294Field(temporaryWord2, signed char*, 0x48) = 6;
                    Level20_7F294Field(temporaryWord2, int*, 0x1C) =
                        (int)(Level20_7F294Field(temporaryWord2, int*, 0x1C) & 0x7FFFFFFF);
                default:
                    goto reloadOriginalCommonStatus870;
                case 1:
                    argumentWord4 = (int)&originalFrame.sp38;
                    MATCHING_KEEP_CLOBBER(argumentWord4, "$16");
                    retainedIndexVectorHeadingOrFlag16 = (int)&Level20_7F294Data70328View1 + 152;
                    Level20_7F294CopyVectorView1(argumentWord4, retainedIndexVectorHeadingOrFlag16);
                    originalFrame.sp38 *= 0x14;
                    originalFrame.sp3C *= 0x14;
                    originalFrame.sp40 *= 0x14;
                    Level20_7F294ShiftVectorRightTowardZeroView1(&originalFrame.sp38, 6);
                    argumentWord4 = (int)&originalFrame.sp38;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord5 = argumentWord4;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4),
                              "r"(retainedIndexVectorHeadingOrFlag16));
                    retainedPlayerBaseHeadingOrFlag17 = retainedIndexVectorHeadingOrFlag16 - 152;
                    Level20_7F294AddVectorView1(argumentWord4, argumentWord5,
                                                retainedPlayerBaseHeadingOrFlag17);
                    if (({
                            rawWord2 = Level20_7F294ApproximatePlanarDistanceView1(
                                (int)ownerRecord19 + 12, &originalFrame.sp38);
                            argumentWord4 = (int)&originalFrame.sp48;
                            rawWord2;
                        }) < 6144) {
                        temporaryWord5 = Level20_7F294Field(privateRecord18, void**, 0);
                        argumentWord6 = Level20_7F294Field(temporaryWord5, short*, 2);
                        MATCHING_KEEP(argumentWord6);
                        temporaryWord11 = Level20_7F294Field(temporaryWord5, short*, 0);
                        retainedIndexVectorHeadingOrFlag16 =
                            (int)(argumentWord6 + Level20_7F294Field(temporaryWord5, short*, 0xA) +
                                  temporaryWord11) %
                            temporaryWord11;
                        __asm__ volatile("" ::: "$5", "memory");
                        argumentWord5 = retainedPlayerBaseHeadingOrFlag17;
                        __asm__(""
                                : "=r"(retainedIndexVectorHeadingOrFlag16)
                                : "0"(retainedIndexVectorHeadingOrFlag16), "r"(argumentWord5));
                        rawWord2 = Level20_7F294Field(temporaryWord5, int*, 12);
                        argumentWord6 *= 16;
                        argumentWord6 = rawWord2 + argumentWord6;
                        Level20_7F294SubtractVectorView1(argumentWord4, argumentWord5,
                                                         argumentWord6, temporaryWord5);
                        retainedPlayerBaseHeadingOrFlag17 = Level20_7F294PlanarHeadingLookupView1(
                            originalFrame.sp48, originalFrame.sp4C, 0);
                        rawWord2 = Level20_7F294Field(privateRecord18, int*, 0);
                        rawWord3 = Level20_7F294Field(rawWord2, int*, 12);
                        rawWord2 = Level20_7F294Field(rawWord2, short*, 2);
                        __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
                        argumentWord6 = 0;
                        rawWord2 *= 16;
                        rawWord2 += rawWord3;
                        argumentWord4 = Level20_7F294Field(rawWord2, int*, 0);
                        argumentWord5 = Level20_7F294Field(rawWord2, int*, 4);
                        MATCHING_KEEP_CLOBBER(retainedIndexVectorHeadingOrFlag16, "memory");
                        retainedIndexVectorHeadingOrFlag16 =
                            retainedIndexVectorHeadingOrFlag16 * 16 + rawWord3;
                        MATCHING_KEEP(retainedIndexVectorHeadingOrFlag16);
                        argumentWord7 =
                            Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, int*, 0);
                        rawWord3 = Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, int*, 4);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Level20_7F294PlanarHeadingLookupView1(
                            argumentWord4, argumentWord5, argumentWord6);
                        retainedPlayerBaseHeadingOrFlag17 =
                            Level20_7F294AbsoluteByteAngleDeltaView1(
                                retainedPlayerBaseHeadingOrFlag17, rawWord2);
                        if (retainedPlayerBaseHeadingOrFlag17 >= 0x20) {
                            if (({
                                    rawWord2 = retainedPlayerBaseHeadingOrFlag17 < 96;
                                    MATCHING_KEEP(rawWord2);
                                    rawWord2;
                                }) &&
                                (({
                                     rawWord2 = Level20_7F294PlanarHeadingLookupView1(
                                         -originalFrame.sp48, -originalFrame.sp4C, 0);
                                     retainedPlayerBaseHeadingOrFlag17 =
                                         (rawWord2 -
                                          Level20_7F294Field((int)&Level20_7F294Data70328View1,
                                                             unsigned char*, 14)) &
                                         255;
                                     MATCHING_KEEP(retainedPlayerBaseHeadingOrFlag17);
                                     ({
                                         rawWord2 = retainedPlayerBaseHeadingOrFlag17 < 128;
                                         MATCHING_KEEP(rawWord2);
                                         rawWord2;
                                     });
                                 }) != 0)) {
                                Level20_7F294PlayMobySoundEventView1(ownerRecord19, 0, 0);
                                goto reverseOriginalFirstDescriptor;
                            }
                        } else {
                        reverseOriginalFirstDescriptor:
                            temporaryWord12 = Level20_7F294Field(privateRecord18, void**, 0);
                            Level20_7F294Field(temporaryWord12, short*, 0xA) =
                                (short)-(short)(unsigned short)Level20_7F294Field(temporaryWord12,
                                                                                  short*, 0xA);
                            temporaryWord3 = Level20_7F294Field(privateRecord18, void**, 0);
                            temporaryWord13 = Level20_7F294Field(temporaryWord3, short*, 0);
                            Level20_7F294Field(temporaryWord3, short*, 2) =
                                (short)((int)(Level20_7F294Field(temporaryWord3, short*, 2) +
                                              (Level20_7F294Field(temporaryWord3, short*, 0xA) *
                                               2) +
                                              temporaryWord13) %
                                        temporaryWord13);
                            Level20_7F294Field(privateRecord18, int*, 8) = 0x1E;
                        }
                        argumentWord4 = (int)ownerRecord19;
                        argumentWord5 = 2;
                        Level20_7F294Field(privateRecord18, int*, 16) = 256;
                        rawWord2 = 2;
                        goto storeOriginalStateTwo867;
                    } else {
                        Level20_7F294TurnMobyTowardPlayerView1(ownerRecord19, 8, 0, 1);
                        if (Level20_7F294Data6C770View1 != 0) {
                            if (Level20_7F294Field(privateRecord18, int*, 8) == 0) {
                                Level20_7F294RequestMobyAnimationView1(ownerRecord19, 1);
                                Level20_7F294Field(privateRecord18, int*, 8) =
                                    Level20_7F294RandBetweenView1(1, 2);
                            } else {
                                Level20_7F294RequestMobyAnimationView1(ownerRecord19, 0);
                                Level20_7F294Field(privateRecord18, int*, 8) =
                                    (int)(Level20_7F294Field(privateRecord18, int*, 8) - 1);
                            }
                        }
                    }
                    goto reloadOriginalCommonStatus870;
            }
            break;
        case 2:
            rawWord3 = Level20_7F294Field(ownerRecord19, unsigned char*, 73);
            originalSubstateTwo = 2;
            if (rawWord3 == originalSubstateTwo)
                goto enterOriginalSubstate533;
            rawWord2 = rawWord3 < 3;
            if (!rawWord2)
                goto testOriginalUpperSubstate322;
            rawWord2 = 1;
            if (rawWord3 == rawWord2)
                goto enterOriginalSubstate327;
            goto reloadOriginalCommonStatus870;
        testOriginalUpperSubstate322:
            rawWord2 = 3;
            argumentWord4 = (int)ownerRecord19;
            if (rawWord3 == rawWord2)
                goto enterOriginalSubstate588;
            goto reloadOriginalCommonStatus870;
        enterOriginalSubstate327:
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 12);
            rawWord2 = Level20_7F294Data6C648View1;
            originalTarget256 = 256;
            rawWord2 = rawWord3 + rawWord2;
            argumentWord4 = rawWord3 / 300;
            argumentWord4 += rawWord3 >> 31;
            rawWord3 >>= 31;
            Level20_7F294Field(privateRecord18, int*, 12) = rawWord2;
            rawWord2 = rawWord2 < 7201;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord3), "r"(rawWord2));
            retainedQuotientTargetOrLinkedRecord20 = argumentWord4 - rawWord3;
            retainedQuotientTargetOrLinkedRecord20 =
                originalTarget256 - retainedQuotientTargetOrLinkedRecord20;
            if (!rawWord2) {
                Level20_7F294Field(privateRecord18, int*, 0xC) = 0x1C20;
            }
            argumentWord4 = (int)&originalFrame.sp48;
            MATCHING_KEEP_CLOBBER(argumentWord4, "$17");
            retainedPlayerBaseHeadingOrFlag17 = (int)&Level20_7F294Data70328View1 + 152;
            Level20_7F294CopyVectorView1(argumentWord4, retainedPlayerBaseHeadingOrFlag17);
            originalFrame.sp48 *= 0x14;
            originalFrame.sp4C *= 0x14;
            originalFrame.sp50 *= 0x14;
            Level20_7F294ShiftVectorRightTowardZeroView1(&originalFrame.sp48, 6);
            retainedPlayerBase21 = retainedPlayerBaseHeadingOrFlag17 - 0x98;
            Level20_7F294AddVectorView1(&originalFrame.sp48, &originalFrame.sp48,
                                        retainedPlayerBase21);
            retainedPlayerBaseHeadingOrFlag17 = ownerRecord19 + 0xC;
            retainedIndexVectorHeadingOrFlag16 = Level20_7F294ApproximatePlanarDistanceView1(
                retainedPlayerBaseHeadingOrFlag17, &originalFrame.sp48);
            temporaryWord14 = Level20_7F294Field(privateRecord18, int*, 0x10) + 8;
            Level20_7F294Field(privateRecord18, int*, 0x10) = temporaryWord14;
            if (temporaryWord14 >= 0x101) {
                Level20_7F294Field(privateRecord18, int*, 0x10) = 0x100;
            }
            if (!(Level20_7F294UpdateMobyPathMotionView1(
                      ownerRecord19, Level20_7F294Field(privateRecord18, void**, 0), 0x200,
                      retainedQuotientTargetOrLinkedRecord20, 0,
                      (int)Level20_7F294Field(privateRecord18, int*, 0x10) >> 4, 0x18, 5) &
                  4)) {
                Level20_7F294Field(privateRecord18, int*, 0x10) = 0;
            }
            rawWord2 = retainedIndexVectorHeadingOrFlag16 < 10241;
            argumentWord4 = privateRecord18 + 8;
            if (rawWord2)
                goto callOriginalTargetCountdown;
            rawWord2 = Level20_7F294ApproximatePlanarDistanceView1(
                retainedPlayerBaseHeadingOrFlag17, retainedPlayerBase21);
            MATCHING_KEEP(privateRecord18);
            argumentWord4 = privateRecord18 + 8;
            if (rawWord2 < 10241)
                goto callOriginalTargetCountdown;
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 0;
            Level20_7F294Field(privateRecord18, int*, 8) = originalSubstateTwo;
            Level20_7F294Field(ownerRecord19, unsigned char*, 72) = 0;
            goto callOriginalStateHelper868;
            {
            callOriginalTargetCountdown:
                Level20_7F294CountTimerDownView1(argumentWord4, 4);
                temporaryWord6 = Level20_7F294Field(privateRecord18, void**, 0);
                argumentWord6 = Level20_7F294Field(temporaryWord6, short*, 2);
                MATCHING_KEEP(argumentWord6);
                temporaryWord15 = Level20_7F294Field(temporaryWord6, short*, 0);
                retainedIndexVectorHeadingOrFlag16 =
                    (int)(argumentWord6 + Level20_7F294Field(temporaryWord6, short*, 0xA) +
                          temporaryWord15) %
                    temporaryWord15;
                __asm__ volatile("" ::: "$4", "$5", "memory");
                argumentWord4 = (int)&originalFrame.sp58;
                argumentWord5 = (int)&Level20_7F294Data70328View1;
                __asm__(""
                        : "=r"(retainedIndexVectorHeadingOrFlag16)
                        : "0"(retainedIndexVectorHeadingOrFlag16), "r"(argumentWord4),
                          "r"(argumentWord5));
                rawWord2 = Level20_7F294Field(temporaryWord6, int*, 12);
                argumentWord6 *= 16;
                argumentWord6 = rawWord2 + argumentWord6;
                Level20_7F294SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6,
                                                 temporaryWord6);
                retainedPlayerBaseHeadingOrFlag17 = Level20_7F294PlanarHeadingLookupView1(
                    originalFrame.sp58, originalFrame.sp5C, 0);
                rawWord2 = Level20_7F294Field(privateRecord18, int*, 0);
                rawWord3 = Level20_7F294Field(rawWord2, int*, 12);
                rawWord2 = Level20_7F294Field(rawWord2, short*, 2);
                __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
                argumentWord6 = 0;
                rawWord2 *= 16;
                rawWord2 += rawWord3;
                argumentWord4 = Level20_7F294Field(rawWord2, int*, 0);
                argumentWord5 = Level20_7F294Field(rawWord2, int*, 4);
                MATCHING_KEEP_CLOBBER(retainedIndexVectorHeadingOrFlag16, "memory");
                retainedIndexVectorHeadingOrFlag16 =
                    retainedIndexVectorHeadingOrFlag16 * 16 + rawWord3;
                MATCHING_KEEP(retainedIndexVectorHeadingOrFlag16);
                argumentWord7 = Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, int*, 0);
                rawWord3 = Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, int*, 4);
                argumentWord4 = argumentWord7 - argumentWord4;
                argumentWord5 = rawWord3 - argumentWord5;
                rawWord2 = Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                 argumentWord6);
                rawWord2 = retainedPlayerBaseHeadingOrFlag17 - rawWord2;
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
                        (Level20_7F294Field(privateRecord18, int*, 8) == 0)) {
                        rawWord2 = Level20_7F294Field((int)&Level20_7F294Data70328View1,
                                                      unsigned char*, 14);
                        rawWord2 = retainedPlayerBaseHeadingOrFlag17 - rawWord2;
                        MATCHING_KEEP(rawWord2);
                        retainedPlayerBaseHeadingOrFlag17 = rawWord2 & 255;
                        if (retainedPlayerBaseHeadingOrFlag17 >= 0x81) {
                            retainedPlayerBaseHeadingOrFlag17 -= 0x100;
                        }
                        if (((argumentWord4 > 0) && (retainedPlayerBaseHeadingOrFlag17 > 0)) ||
                            ((argumentWord4 < 0) && (retainedPlayerBaseHeadingOrFlag17 < 0))) {
                            Level20_7F294PlayMobySoundEventView1(ownerRecord19, 0, 0);
                            goto reverseOriginalSecondDescriptor;
                        }
                    }
                } else {
                reverseOriginalSecondDescriptor:
                    temporaryWord8 = Level20_7F294Field(privateRecord18, void**, 0);
                    Level20_7F294Field(temporaryWord8, short*, 0xA) = (short)-(
                        short)(unsigned short)Level20_7F294Field(temporaryWord8, short*, 0xA);
                    temporaryWord4 = Level20_7F294Field(privateRecord18, void**, 0);
                    temporaryWord9 = Level20_7F294Field(temporaryWord4, short*, 0);
                    Level20_7F294Field(temporaryWord4, short*, 2) =
                        (short)((int)(Level20_7F294Field(temporaryWord4, short*, 2) +
                                      (Level20_7F294Field(temporaryWord4, short*, 0xA) * 2) +
                                      temporaryWord9) %
                                temporaryWord9);
                    Level20_7F294Field(privateRecord18, int*, 8) = 0x1E;
                    Level20_7F294Field(privateRecord18, int*, 0x10) = 0x100;
                }
            }
            goto reloadOriginalCommonStatus870;
        enterOriginalSubstate533:
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 20);
            argumentWord6 = 0;
            rawWord2 = Level20_7F294Field(rawWord3, short*, 2);
            rawWord3 = Level20_7F294Field(rawWord3, int*, 12);
            rawWord2 *= 16;
            rawWord2 += rawWord3;
            argumentWord7 = Level20_7F294Field(rawWord2, int*, 0);
            argumentWord4 = Level20_7F294Field(rawWord3, int*, 0);
            rawWord2 = Level20_7F294Field(rawWord2, int*, 4);
            argumentWord5 = Level20_7F294Field(rawWord3, int*, 4);
            argumentWord4 = argumentWord7 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord4 = (int)ownerRecord19;
            argumentWord6 = 2048;
            MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord6, "$16");
            retainedIndexVectorHeadingOrFlag16 = rawWord2;
            argumentWord5 = Level20_7F294Field(privateRecord18, int*, 20);
            rawWord2 = (int)Level20_7F294Data74314View1;
            ((int (*)())rawWord2)(argumentWord4, Level20_7F294Field(argumentWord5, int*, 12),
                                  argumentWord6, retainedIndexVectorHeadingOrFlag16, 6, 256, 16, 16,
                                  255, 255, 0, 0, 0);
            argumentWord6 = 0;
            rawWord2 = Level20_7F294Field(privateRecord18, int*, 20);
            argumentWord7 = Level20_7F294Field(ownerRecord19, int*, 12);
            rawWord2 = Level20_7F294Field(rawWord2, int*, 12);
            rawWord3 = Level20_7F294Field(ownerRecord19, int*, 16);
            argumentWord4 = Level20_7F294Field(rawWord2, int*, 0);
            argumentWord5 = Level20_7F294Field(rawWord2, int*, 4);
            argumentWord4 = argumentWord7 - argumentWord4;
            argumentWord5 = rawWord3 - argumentWord5;
            rawWord2 =
                Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            if (Level20_7F294AbsoluteByteAngleDeltaView1(retainedIndexVectorHeadingOrFlag16,
                                                         rawWord2) < 7) {
                Level20_7F294Field(privateRecord18, int*, 8) = 90;
                Level20_7F294Field(ownerRecord19, unsigned char*, 73) = 3;
            }
            goto reloadOriginalCommonStatus870;
        enterOriginalSubstate588:
            Level20_7F294UpdateMobyPathMotionView1(ownerRecord19,
                                                   Level20_7F294Field(privateRecord18, void**, 0),
                                                   0x200, 0x100, 0, 0x10, 0x18, 5);
            if (Level20_7F294CountTimerDownView1(privateRecord18 + 8, 4) != 0) {
                Level20_7F294Field(privateRecord18, int*, 0x10) = 0;
                Level20_7F294Field(ownerRecord19, unsigned char*, 0x49) = 1U;
            }
            goto reloadOriginalCommonStatus870;
        case 3:
            Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0x20C) = 0x10000002;
            if (Level20_7F294UpdateMobyMotionDescriptorView1(ownerRecord19,
                                                             privateRecord18 + 0x18) == 0x100) {
                Level20_7F294CopyVectorView1(
                    &originalFrame.sp58,
                    Level20_7F294Field(Level20_7F294Field(privateRecord18, void**, 0), void**,
                                       0xC));
                originalFrame.sp60 +=
                    Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0x44);
                rawWord2 =
                    Level20_7F294Field(Level20_7F294Field(privateRecord18, void**, 0), void**, 0xC);
                argumentWord7 = Level20_7F294Field(rawWord2, int*, 0x10);
                Level20_7F294SetCameraMode11TargetView1(
                    &originalFrame.sp58,
                    Level20_7F294PlanarHeadingLookupView1(argumentWord7 -
                                                              Level20_7F294Field(rawWord2, int*, 0),
                                                          Level20_7F294Field(rawWord2, int*, 0x14) -
                                                              Level20_7F294Field(rawWord2, int*, 4),
                                                          0),
                    0, 0);
                if (Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0x280) < 0) {
                    Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0x280) = 0;
                }
                Level20_7F294RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                Level20_7F294MarkMobyCollectionBitView1(ownerRecord19);
                Level20_7F294EmitMobyVertexParticlesView1(ownerRecord19, 0x20);
                Level20_7F294Field(ownerRecord19, signed char*, 0x41) = 0;
                Level20_7F294Field(ownerRecord19, signed char*, 0x4C) = 0;
                Level20_7F294Field(ownerRecord19, signed char*, 0x4D) = 0;
                Level20_7F294Field(ownerRecord19, unsigned char*, 0x48) = 4U;
            }
            goto reloadOriginalCommonStatus870;
        case 4:
            if (Level20_7F294Data6E048View1 & 1) {
                rawWord2 = Level20_7F294Field(privateRecord18, int*, 0);
                rawWord3 = Level20_7F294Field(privateRecord18, int*, 4);
                retainedIndexVectorHeadingOrFlag16 = Level20_7F294Data6C550View1;
                argumentWord5 = Level20_7F294Field(rawWord2, int*, 12);
                rawWord2 = rawWord3 * 88;
                retainedIndexVectorHeadingOrFlag16 += rawWord2;
                argumentWord5 += 16;
                Level20_7F294CopyVectorView1(&originalFrame.sp68, argumentWord5);
                Level20_7F294CopyVectorView1(retainedIndexVectorHeadingOrFlag16 + 0xC,
                                             &originalFrame.sp68);
                Level20_7F294SetMobyZFromGroundProbeView1(retainedIndexVectorHeadingOrFlag16);
                Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, unsigned char*, 0x52) = 0xFE;
                Level20_7F294RefreshMobySpatialGridAndBasisView1(retainedIndexVectorHeadingOrFlag16,
                                                                 2);
                Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, signed char*, 0x48) = 1;
                rawWord2 =
                    Level20_7F294Field(Level20_7F294Field(privateRecord18, void**, 0), void**, 0xC);
                argumentWord6 = 0;
                argumentWord7 = Level20_7F294Field(rawWord2, int*, 0);
                argumentWord4 = Level20_7F294Field(rawWord2, int*, 0x10);
                rawWord3 = Level20_7F294Field(rawWord2, int*, 4);
                argumentWord5 = Level20_7F294Field(rawWord2, int*, 0x14);
            block_58:
                argumentWord4 = argumentWord7 - argumentWord4;
                argumentWord5 = rawWord3 - argumentWord5;
                rawWord2 = Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                 argumentWord6);
                argumentWord4 = (int)ownerRecord19;
                Level20_7F294Field(retainedIndexVectorHeadingOrFlag16, signed char*, 70) = rawWord2;
                Level20_7F294DeleteMobyView1(argumentWord4);
                return;
            }
            goto reloadOriginalCommonStatus870;
        case 5:
            rawWord2 = Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 464);
            if (rawWord2)
                goto reloadOriginalCommonStatus870;
            rawWord2 = Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 320);
            argumentWord6 = 0;
            if (rawWord2)
                goto reloadOriginalCommonStatus870;
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 20);
            argumentWord7 = Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 4);
            rawWord2 = Level20_7F294Field(rawWord3, short*, 2);
            rawWord3 = Level20_7F294Field(rawWord3, int*, 12);
            rawWord2 *= 16;
            rawWord2 += rawWord3;
            rawWord3 = Level20_7F294Field((int)&Level20_7F294Data70328View1, int*, 0);
            argumentWord4 = Level20_7F294Field(rawWord2, int*, 0);
            argumentWord5 = Level20_7F294Field(rawWord2, int*, 4);
            argumentWord4 = rawWord3 - argumentWord4;
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 4);
            argumentWord5 = argumentWord7 - argumentWord5;
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level20_7F294Data6C550View1;
            retainedQuotientTargetOrLinkedRecord20 = rawWord3 + rawWord2;
            rawWord2 =
                Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 20);
            retainedPlayerBaseHeadingOrFlag17 = rawWord2;
            rawWord2 = Level20_7F294Field(rawWord3, int*, 12);
            argumentWord6 = 0;
            argumentWord7 = Level20_7F294Field(rawWord2, int*, 16);
            argumentWord4 = Level20_7F294Field(rawWord2, int*, 0);
            rawWord3 = Level20_7F294Field(rawWord2, int*, 20);
            argumentWord5 = Level20_7F294Field(rawWord2, int*, 4);
            argumentWord4 = argumentWord7 - argumentWord4;
            argumentWord5 = rawWord3 - argumentWord5;
            rawWord2 =
                Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 20);
            rawWord3 = Level20_7F294Field(rawWord3, int*, 12);
            argumentWord6 = 0;
            originalFrame.sp88 = rawWord2;
            __asm__ __volatile__("" ::"m"(originalFrame.sp88), "r"(argumentWord6) : "$7");
            argumentWord7 = Level20_7F294Field(rawWord3, volatile int*, 32);
            argumentWord4 = Level20_7F294Field(rawWord3, volatile int*, 0);
            __asm__ __volatile__("" ::"r"(argumentWord7), "r"(argumentWord4) : "$2", "memory");
            rawWord2 = Level20_7F294Field(rawWord3, int*, 36);
            argumentWord5 = Level20_7F294Field(rawWord3, int*, 4);
            argumentWord4 = argumentWord7 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord5 = retainedPlayerBaseHeadingOrFlag17;
            argumentWord4 = originalFrame.sp88;
            MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$16");
            retainedIndexVectorHeadingOrFlag16 = rawWord2;
            rawWord2 = Level20_7F294AbsoluteByteAngleDeltaView1(argumentWord4, argumentWord5);
            argumentWord4 = retainedIndexVectorHeadingOrFlag16;
            argumentWord5 = retainedPlayerBaseHeadingOrFlag17;
            originalFrame.sp88 = rawWord2;
            rawWord2 = Level20_7F294AbsoluteByteAngleDeltaView1(argumentWord4, argumentWord5);
            rawWord3 = originalFrame.sp88;
            rawWord3 = rawWord3 < rawWord2;
            rawWord2 = 2;
            if (!rawWord3)
                goto enterOriginalNegativeDirection787;
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 20);
            Level20_7F294Field(rawWord3, short*, 2) = rawWord2;
            rawWord3 = Level20_7F294Field(privateRecord18, volatile int*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            goto storeOriginalDirection792;
        enterOriginalNegativeDirection787:
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 20);
            rawWord2 = 1;
            Level20_7F294Field(rawWord3, short*, 2) = rawWord2;
            rawWord3 = Level20_7F294Field(privateRecord18, volatile int*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = -1;
        storeOriginalDirection792:
            Level20_7F294Field(rawWord3, short*, 10) = rawWord2;
            rawWord2 = retainedPlayerBaseHeadingOrFlag17 + 128;
            retainedPlayerBaseHeadingOrFlag17 = rawWord2 & 255;
            MATCHING_KEEP(retainedPlayerBaseHeadingOrFlag17);
            rawWord3 = retainedPlayerBaseHeadingOrFlag17 * 2;
            rawWord2 = Level20_7F294Field((int)&Level20_7F294Data65920View1, short*, rawWord3);
            MATCHING_KEEP(rawWord2);
            rawWord2 >>= 1;
            originalFrame.sp78 = rawWord2;
            rawWord2 = Level20_7F294Field((int)&Level20_7F294Data658A0View1, short*, rawWord3);
            MATCHING_KEEP(rawWord2);
            retainedIndexVectorHeadingOrFlag16 = (int)&originalFrame.sp78;
            originalFrame.sp80 = 0;
            __asm__ __volatile__("" : "=r"(rawWord2) : "0"(rawWord2), "m"(originalFrame.sp80));
            rawWord2 >>= 1;
            originalFrame.sp7C = rawWord2;
            rawWord2 = Level20_7F294Field(privateRecord18, int*, 20);
            argumentWord4 = retainedIndexVectorHeadingOrFlag16;
            argumentWord6 = Level20_7F294Field(rawWord2, int*, 12);
            Level20_7F294AddVectorView1(argumentWord4, retainedIndexVectorHeadingOrFlag16,
                                        argumentWord6);
            Level20_7F294CopyVectorView1((int)ownerRecord19 + 12,
                                         retainedIndexVectorHeadingOrFlag16);
            Level20_7F294SetMobyZFromGroundProbeView1(ownerRecord19);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 2;
            MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$2");
            rawWord2 = 254;
            Level20_7F294Field(ownerRecord19, unsigned char*, 82) = rawWord2;
            Level20_7F294RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 1;
            MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$16");
            retainedIndexVectorHeadingOrFlag16 = 1;
            retainedPlayerBaseHeadingOrFlag17 = 32;
            Level20_7F294Field(ownerRecord19, signed char*, 65) =
                retainedIndexVectorHeadingOrFlag16;
            Level20_7F294Field(ownerRecord19, signed char*, 76) = retainedPlayerBaseHeadingOrFlag17;
            Level20_7F294Field(ownerRecord19, signed char*, 77) =
                retainedIndexVectorHeadingOrFlag16;
            Level20_7F294RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
            argumentWord4 = retainedQuotientTargetOrLinkedRecord20;
            argumentWord5 = 1;
            Level20_7F294Field(argumentWord4, signed char*, 65) =
                retainedIndexVectorHeadingOrFlag16;
            Level20_7F294Field(argumentWord4, signed char*, 76) = retainedPlayerBaseHeadingOrFlag17;
            Level20_7F294Field(argumentWord4, signed char*, 77) =
                retainedIndexVectorHeadingOrFlag16;
            Level20_7F294RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
            argumentWord6 = (int)&originalFrame.sp88;
            rawWord2 = Level20_7F294Field(privateRecord18, int*, 20);
            argumentWord5 = Level20_7F294Field(privateRecord18, int*, 0);
            argumentWord4 = Level20_7F294Field(rawWord2, short*, 2);
            rawWord2 = Level20_7F294Field(rawWord2, int*, 12);
            argumentWord4 *= 16;
            argumentWord4 = rawWord2 + argumentWord4;
            Level20_7F294GetClosestPathNodeView1(argumentWord4, argumentWord5, argumentWord6);
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 0);
            rawWord2 = originalFrame.sp88;
            argumentWord6 = 0;
            Level20_7F294Field(rawWord3, short*, 2) = rawWord2;
            rawWord3 = Level20_7F294Field(privateRecord18, int*, 0);
            argumentWord4 = Level20_7F294Field(ownerRecord19, int*, 12);
            argumentWord5 = Level20_7F294Field(ownerRecord19, int*, 16);
            rawWord2 = Level20_7F294Field(rawWord3, short*, 2);
            rawWord3 = Level20_7F294Field(rawWord3, int*, 12);
            rawWord2 *= 16;
            rawWord2 += rawWord3;
            rawWord3 = Level20_7F294Field(rawWord2, int*, 0);
            rawWord2 = Level20_7F294Field(rawWord2, int*, 4);
            argumentWord4 = rawWord3 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level20_7F294PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 2;
            Level20_7F294Field(ownerRecord19, unsigned char*, 70) = rawWord2;
            rawWord2 = 2;
            Level20_7F294Field(ownerRecord19, unsigned char*, 73) = rawWord2;
            goto storeOriginalStateTwo867;
        storeOriginalStateTwo867:
            Level20_7F294Field(ownerRecord19, unsigned char*, 72) = rawWord2;
        callOriginalStateHelper868:
            Level20_7F294RequestMobyAnimationView1(argumentWord4, argumentWord5);
            goto reloadOriginalCommonStatus870;
        reloadOriginalCommonStatus870:
            rawWord3 = Level20_7F294Field(ownerRecord19, unsigned char*, 72);
        testOriginalPreparedStatus871:
            MATCHING_BARRIER_VOLATILE("$2");
            if (rawWord3 != 4) {
                Level20_7F294RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                Level20_7F294InterpolateMobyVertexView1(
                    ownerRecord19, 0,
                    Level20_7F294Data6C550View1 +
                        (Level20_7F294Field(privateRecord18, int*, 4) * 0x58) + 0xC);
                temporaryWord7 = (Level20_7F294Field(privateRecord18, int*, 4) * 0x58) +
                                 Level20_7F294Data6C550View1;
                Level20_7F294Field(temporaryWord7, int*, 0x14) =
                    (int)(Level20_7F294Field(temporaryWord7, int*, 0x14) - 0x80);
                Level20_7F294Field(((Level20_7F294Field(privateRecord18, int*, 4) * 0x58) +
                                    Level20_7F294Data6C550View1),
                                   unsigned char*, 0x52) = 0xFE;
                Level20_7F294Field(((Level20_7F294Field(privateRecord18, int*, 4) * 0x58) +
                                    Level20_7F294Data6C550View1),
                                   unsigned char*, 0x46) =
                    (unsigned char)Level20_7F294Field(ownerRecord19, unsigned char*, 0x46);
            }
            return;
        default:
            goto testOriginalPreparedStatus871;
    }
}
#undef Level20_7F294Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Level20_80130Zero()                          \
    ({                                               \
        register int zero0 __asm__("$0");            \
        __asm__ volatile("" : "=r"(zero0) : "i"(0)); \
        zero0;                                       \
    })
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_20/moby/func_level_20_80080130.s SHA256 94aca6dae0ce4697092b679f9236f57c87963f23bf7d7501e8d56e3e4f26c77f. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level20_80130Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level20_80130QueryWorldSegmentWithOptions() __asm__("func_8001830C");
/* extern */
int Level20_80130QueryWorldSegment() __asm__("func_80018368");
/* extern */
int Level20_80130QueryWorldSphereWithOptions() __asm__("func_80019138");
/* extern */
int Level20_80130QueryWorldSphere() __asm__("func_80019194");
/* extern */
unsigned char Level20_80130QueryWorldHeight() __asm__("func_8001A358");
/* extern */
int Level20_80130QueryDynamicMobyGeometry() __asm__("func_8001BA30");
/* extern */
int Level20_80130RandSignedBetween() __asm__("func_800363DC");
/* extern */
int Level20_80130ComputeArcVerticalVelocity() __asm__("func_800365E4");
/* extern */
unsigned char Level20_80130UpdateMobyPrivateBallisticMotion() __asm__("func_80039714");
/* extern */
unsigned char Level20_80130PlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned char Level20_80130ResolvePlayerPoint193() __asm__("func_80049484");
/* extern */
int Level20_80130PlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned char Level20_80130TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
int Level20_80130MeasureVectorLength() __asm__("func_8004EDE8");
/* extern */
int Level20_80130ComputeVectorPlaneResponse() __asm__("func_8004EF74");
/* extern */
unsigned char Level20_80130ShiftVectorRightTowardZero() __asm__("func_8004F110");
/* extern */
unsigned char Level20_80130CopyVector() __asm__("func_8004F178");
/* extern */
unsigned char Level20_80130SubtractVector() __asm__("func_8004F1C8");
/* extern */
int Level20_80130AbsoluteByteAngleDelta() __asm__("func_8004F264");
/* extern */
int Level20_80130ApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned char Level20_80130DeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned char Level20_80130RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
unsigned char Level20_80130InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
unsigned char Level20_80130RefreshMobyPackedQueryField() __asm__("func_8005629C");
/* extern */
extern unsigned char Level20_80130_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level20_80130_D_80065920 __asm__("D_80065920");
extern unsigned int Level20_80130_D_8006C550 __asm__("D_8006C550");
extern int Level20_80130_D_8006C574 __asm__("D_8006C574");
extern int Level20_80130_D_8006C578 __asm__("D_8006C578");
extern unsigned int Level20_80130_D_8006C704 __asm__("D_8006C704");
extern unsigned short Level20_80130_D_8006E03E __asm__("D_8006E03E");
extern unsigned short Level20_80130_D_8006E040 __asm__("D_8006E040");
extern int Level20_80130_D_8006E044 __asm__("D_8006E044");
extern int Level20_80130_D_80070328 __asm__("D_80070328");
extern unsigned char Level20_80130_D_80071918 __asm__("D_80071918");
extern unsigned char (*Level20_80130_SpawnMoby)() __asm__("SpawnMoby");
extern unsigned char (*Level20_80130_SpawnParticle)() __asm__("SpawnParticle");

void func_level_20_80080130(void* ownerRecord) {
    /* Original frame: 0x80 bytes, six outgoing argument words, scratch
     * starts at SP+0x18 and saved registers at SP+0x58. The selected pool
     * record advances by 88 bytes. Table loads are signed halfwords with
     * byte offset index*2;
      the observed multiply165 then shift11 is retained.
     * Names describe raw roles, not unproved gameplay meaning. Physical
     * units, helper effects and update cadence remain unresolved. */
    struct {
        int sp18, sp1C, sp20;
        unsigned char pad24[4];
        int sp28;
        unsigned char pad2C[12];
        int sp38;
        unsigned char pad3C[12];
        int sp48, sp4C, sp50;
        unsigned char pad54[4];
    } scratch;

    register int word4 __asm__("$4");
    register int word2 __asm__("$2");
    register unsigned char (*callback3)() __asm__("$3");
    register unsigned char (*callback2)() __asm__("$2");
    register void* callArg7 __asm__("$7");
    register void* callArg5 __asm__("$5");
    register int* scratch17 __asm__("$17");
    register int* scratch19 __asm__("$19");
    register int mask17 __asm__("$17");
    register int* ownerWords16 __asm__("$16");
    register int* otherOwnerWords16 __asm__("$16");
    int* privateRecord20;
    int weightedWord;
    register int word6 __asm__("$6");
    register int word7 __asm__("$7");
    int helperResult;
    register int helperDelta2 __asm__("$2");
    register int loadedWord3 __asm__("$3");
    register int word5 __asm__("$5");
    register int comparisonWord5 __asm__("$5");
    int secondDifference16;
    register int callbackLoop16 __asm__("$16");
    register int otherCallbackLoop16 __asm__("$16");
    int firstDifference17;
    int bestComparison22;
    register int difference2 __asm__("$2");
    register int word3 __asm__("$3");
    unsigned int poolCursor19;
    unsigned int selectedRecord23;
    unsigned char stateByte;
    register int stateWord2 __asm__("$2");
    void** linkedRecord;
    void** cleanupLink;
    void* temp_s5;

    stateByte = Level20_80130Field(ownerRecord, unsigned char*, 0x48);
    privateRecord20 = Level20_80130Field(ownerRecord, int**, 0);
    switch (stateByte) {
        case 0:
            Level20_80130InterpolateMobyVertex(Level20_80130Field(privateRecord20, void***, 0x10),
                                               0, ownerRecord + 0xC);
            return;
        case 1:
            linkedRecord = Level20_80130Field(privateRecord20, void***, 0x10);
            if (linkedRecord != 0) {
                Level20_80130Field(*linkedRecord, int*, 0x24) = 0;
                Level20_80130Field(privateRecord20, void***, 0x10) = 0;
            }
            Level20_80130Field(ownerRecord, int*, 8) = 0;
            Level20_80130Field(ownerRecord, signed char*, 0x4C) = 0;
            Level20_80130Field(ownerRecord, signed char*, 0x4D) = 0;
            Level20_80130Field(ownerRecord, unsigned char*, 0x4A) = 0xFF;
            return;
        case 2:
            Level20_80130Field(ownerRecord, signed char*, 0x4C) = 0x40;
            Level20_80130ResolvePlayerPoint193(ownerRecord + 0xC);
            Level20_80130Field(ownerRecord, unsigned char*, 0x46) =
                (unsigned char)(Level20_80130Field(&Level20_80130_D_80070328, unsigned char*, 0xE) +
                                Level20_80130Field(&Level20_80130_D_80070328, unsigned char*,
                                                   0x12));
            if (Level20_80130_D_8006E044 == 7) {
                Level20_80130Field(ownerRecord, unsigned char*, 0x45) =
                    (unsigned char)(0xE - ((int)(Level20_80130_D_8006E03E << 0x10) >> 0x14));
                Level20_80130Field(ownerRecord, unsigned char*, 0x46) =
                    (unsigned char)((unsigned short)Level20_80130_D_8006E040 >> 4);
            } else {
                Level20_80130Field(ownerRecord, unsigned char*, 0x45) = 0xEU;
            }
            selectedRecord23 = 0;
            poolCursor19 = Level20_80130_D_8006C550;
            bestComparison22 = 0x7530;
            if (poolCursor19 < (unsigned int)Level20_80130_D_8006C704) {
                temp_s5 = ownerRecord + 0xC;
                do {
                    if (!(Level20_80130Field(poolCursor19, unsigned char*, 0x48) & 0x80) &&
                        (Level20_80130Field(poolCursor19, int*, 8) != 0)) {
                        Level20_80130CopyVector(&scratch.sp18, poolCursor19 + 0xC);
                        loadedWord3 = scratch.sp20;
                        word4 = scratch.sp18;
                        loadedWord3 += 0x80;
                        scratch.sp20 = loadedWord3;
                        word2 = Level20_80130Field(ownerRecord, int*, 0xC);
                        word7 = word4 - word2;
                        word4 = scratch.sp1C;
                        word2 = Level20_80130Field(ownerRecord, int*, 0x10);
                        word5 = word7;
                        if (word7 < 0)
                            word5 = -word5;
                        word6 = word4 - word2;
                        difference2 = word6;
                        if (word6 < 0)
                            difference2 = -difference2;
                        word4 = Level20_80130Field(ownerRecord, int*, 0x14);
                        word5 += difference2;
                        MATCHING_KEEP(word5);
                        word3 = loadedWord3 - word4;
                        if (word3 < 0)
                            word3 = -word3;
                        word5 += word3;
                        word2 = word5 < 0x6000;
                        MATCHING_KEEP(word2);
                        if (word2) {
                            firstDifference17 =
                                (Level20_80130PlanarHeadingLookup(word7, word6, 0, word7) -
                                 Level20_80130Field(ownerRecord, unsigned char*, 0x46)) &
                                0xFF;
                            if (firstDifference17 >= 0x81) {
                                firstDifference17 -= 0x100;
                            }
                            if (firstDifference17 < 0) {
                                firstDifference17 = -firstDifference17;
                            }
                            MATCHING_KEEP_VOLATILE(firstDifference17);
                            if (firstDifference17 < 6) {
                                secondDifference16 =
                                    ((Level20_80130PlanarHeadingLookup(
                                          Level20_80130ApproximatePlanarDistance(temp_s5,
                                                                                 &scratch.sp18),
                                          scratch.sp20 -
                                              Level20_80130Field(ownerRecord, int*, 0x14),
                                          0) -
                                      Level20_80130Field(ownerRecord, unsigned char*, 0x45)) +
                                     0xE) &
                                    0xFF;
                                if (secondDifference16 >= 0x81) {
                                    secondDifference16 -= 0x100;
                                }
                                if (secondDifference16 < 0) {
                                    secondDifference16 = -secondDifference16;
                                }
                                MATCHING_KEEP_VOLATILE(secondDifference16);
                                if (secondDifference16 < 6) {
                                    Level20_80130SubtractVector(&scratch.sp18, &scratch.sp18,
                                                                temp_s5);
                                    helperResult =
                                        Level20_80130MeasureVectorLength(&scratch.sp18, 0);
                                    comparisonWord5 = helperResult + Level20_80130Zero();
                                    if (comparisonWord5 < 0x3000) {
                                        helperDelta2 = comparisonWord5 - 0x800;
                                        comparisonWord5 = helperDelta2 + Level20_80130Zero();
                                        if (helperDelta2 < 0) {
                                            comparisonWord5 = -comparisonWord5;
                                        }
                                        weightedWord = comparisonWord5 + (firstDifference17 << 6) +
                                                       (secondDifference16 * 0x10);
                                        if (weightedWord < bestComparison22) {
                                            selectedRecord23 = poolCursor19;
                                            bestComparison22 = weightedWord;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    poolCursor19 += 0x58;
                } while (poolCursor19 < (unsigned int)Level20_80130_D_8006C704);
            }
            if (selectedRecord23 != 0) {
                Level20_80130CopyVector(&scratch.sp18, selectedRecord23 + 0xC);
                scratch.sp20 += 0x80;
                Level20_80130Field(privateRecord20, int*, 0) =
                    (int)(Level20_80130Field(&Level20_80130_D_80065920, short*,
                                             Level20_80130Field(ownerRecord, unsigned char*, 0x46) *
                                                 2) *
                          0xA5) >>
                    0xB;

                loadedWord3 =
                    Level20_80130Field(&Level20_80130_D_800658A0, short*,
                                       Level20_80130Field(ownerRecord, unsigned char*, 0x46) * 2);
                Level20_80130Field(privateRecord20, volatile int*, 8) = 0;
                Level20_80130Field(privateRecord20, int*, 4) = (loadedWord3 * 0xA5) >> 11;
                Level20_80130Field(privateRecord20, int*, 8) =
                    Level20_80130ComputeArcVerticalVelocity(ownerRecord + 0xC, &scratch.sp18, 0x14A,
                                                            -0xA, 0);
            } else {
                Level20_80130RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level20_80130Field(privateRecord20, int*, 0) = 0x14A;
                Level20_80130Field(privateRecord20, int*, 4) = 0;
                Level20_80130Field(privateRecord20, int*, 8) = 0;
                Level20_80130TransformVectorByBasis(ownerRecord + 0x20, privateRecord20,
                                                    privateRecord20);
            }
            Level20_80130Field(ownerRecord, unsigned char*, 0x48) = 3U;
            return;
        /* Original 0x80080598/0x800805BC/0x800805DC branches share state6.
     * Keep its producer before case4 and its byte store after case4: the
     * original first two BNE delays load6, and the third J delay stores it. */
        case 3:
            if ((Level20_80130Field(ownerRecord, int*, 0xC) >= 0x400) &&
                (Level20_80130Field(ownerRecord, int*, 0x10) >= 0x400) &&
                (Level20_80130Field(ownerRecord, int*, 0x14) >= 0x400)) {
                scratch19 = &scratch.sp28;
                word4 = (int)scratch19;
                MATCHING_KEEP(word4);
                ownerWords16 = ownerRecord + 0xC;
                Level20_80130CopyVector((void*)word4, ownerWords16);
                word4 = (int)ownerWords16;
                MATCHING_KEEP(word4);
                word2 = Level20_80130Field(ownerRecord, int*, 0xC);
                MATCHING_KEEP_VOLATILE_CLOBBER(word2, "memory");
                word3 = Level20_80130Field(privateRecord20, int*, 0);
                MATCHING_KEEP_CLOBBER(word3, "$5");
                word5 = 0x100;
                word2 += word3;
                Level20_80130Field(ownerRecord, int*, 0xC) = word2;
                word2 = Level20_80130Field(ownerRecord, int*, 0x10);
                MATCHING_KEEP_VOLATILE_CLOBBER(word2, "memory");
                word3 = Level20_80130Field(privateRecord20, int*, 4);
                MATCHING_KEEP_CLOBBER(word3, "$6");
                word6 = 0;
                word2 += word3;
                Level20_80130Field(ownerRecord, int*, 0x10) = word2;
                word2 = Level20_80130Field(ownerRecord, int*, 0x14);
                MATCHING_KEEP_VOLATILE_CLOBBER(word2, "memory");
                word3 = Level20_80130Field(privateRecord20, int*, 8);
                MATCHING_KEEP_CLOBBER(word3, "$7");
                word7 = 0;
                MATCHING_KEEP(word7);
                word2 += word3;
                Level20_80130Field(ownerRecord, int*, 0x14) = word2;
                word2 = Level20_80130Field(privateRecord20, int*, 8);
                MATCHING_KEEP_CLOBBER(word2, "$17");
                mask17 = 0x800000;
                word2 -= 0xA;
                Level20_80130Field(privateRecord20, int*, 8) = word2;
                if (Level20_80130QueryDynamicMobyGeometry((void*)word4, word5, word6, word7, mask17,
                                                          ownerRecord) != 0)
                    goto setState6;
                if (Level20_80130QueryWorldSphereWithOptions(ownerWords16, 0x80, 0, 0, mask17, 0) !=
                    0)
                    goto setState6;
                if (Level20_80130QueryWorldSegmentWithOptions(scratch19, ownerWords16, 0, mask17,
                                                              0) == 0)
                    goto commonHelperCalls;
            setState6:
                stateWord2 = 6;
                goto storeSelectedState;
            }
            goto cleanupTail;
        case 4:
            if ((Level20_80130Field(ownerRecord, int*, 0xC) >= 0x400) &&
                (Level20_80130Field(ownerRecord, int*, 0x10) >= 0x400) &&
                (Level20_80130Field(ownerRecord, int*, 0x14) >= 0x400)) {
                scratch17 = &scratch.sp38;
                word4 = (int)scratch17;
                MATCHING_KEEP(word4);
                otherOwnerWords16 = ownerRecord + 0xC;
                Level20_80130CopyVector((void*)word4, otherOwnerWords16);
                Level20_80130Field(ownerRecord, int*, 0xC) =
                    (int)(Level20_80130Field(ownerRecord, int*, 0xC) +
                          Level20_80130Field(privateRecord20, int*, 0));
                Level20_80130Field(ownerRecord, int*, 0x10) =
                    (int)(Level20_80130Field(ownerRecord, int*, 0x10) +
                          Level20_80130Field(privateRecord20, int*, 4));
                Level20_80130Field(ownerRecord, int*, 0x14) =
                    (int)(Level20_80130Field(ownerRecord, int*, 0x14) +
                          Level20_80130Field(privateRecord20, int*, 8));
                Level20_80130Field(privateRecord20, int*, 8) =
                    (int)(Level20_80130Field(privateRecord20, int*, 8) - 0x10);
                if ((Level20_80130QueryWorldSegment(scratch17, otherOwnerWords16) != 0) ||
                    (Level20_80130QueryWorldSphere(otherOwnerWords16, 0x80) != 0)) {
                    if (Level20_80130ComputeVectorPlaneResponse(
                            privateRecord20, &Level20_80130_D_80071918, privateRecord20) != 0) {
                        Level20_80130ShiftVectorRightTowardZero(privateRecord20, 2);
                        Level20_80130CopyVector(otherOwnerWords16, scratch17);
                        Level20_80130PlayMobySoundEvent(ownerRecord, 0, 0);
                    }
                    if (Level20_80130MeasureVectorLength(privateRecord20, 1) < 0x10) {
                        stateWord2 = 5;
                        __asm__ volatile("" : "=r"(stateWord2) : "0"(stateWord2), "i"(0x800806F0));
                        goto storeSelectedState;
                    }
                }
                goto commonHelperCalls;
            }
            goto cleanupTail;
        storeSelectedState:
            Level20_80130Field(ownerRecord, unsigned char*, 0x48) = stateWord2;
        commonHelperCalls:
            Level20_80130QueryWorldHeight(ownerRecord + 0xC, 0x2000);
            Level20_80130RefreshMobyPackedQueryField(ownerRecord);
            Level20_80130RefreshMobySpatialGridAndBasis(ownerRecord, 2);
            return;
        case 5:
            if (Level20_80130AbsoluteByteAngleDelta(
                    Level20_80130Field(&Level20_80130_D_80070328, unsigned char*, 0xE),
                    Level20_80130PlanarHeadingLookup(
                        Level20_80130Field(ownerRecord, int*, 0xC) -
                            Level20_80130Field(&Level20_80130_D_80070328, int*, 0),
                        Level20_80130Field(ownerRecord, int*, 0x10) -
                            Level20_80130Field(&Level20_80130_D_80070328, int*, 4),
                        0)) < 0x10) {
                /* Short circuit before reusing word2 for the height predicate.
             * The initialized word4 input preserves the original SLTI
             * destination without placing an asm barrier in the store arm. */
                word2 = Level20_80130ApproximatePlanarDistance(ownerRecord + 0xC,
                                                               &Level20_80130_D_80070328) -
                        0x258;
                word2 = word2 < 0xFA;
                MATCHING_KEEP(word2);
                word3 = Level20_80130Field(ownerRecord, int*, 0x14);
                word4 = Level20_80130Field(&Level20_80130_D_80070328, int*, 8);
                word3 += 0x164;
                word4 -= word3;
                if (word4 < 0)
                    word4 = -word4;
                MATCHING_KEEP_VOLATILE(word4);
                if (word2) {
                    word2 = word4 < 0x100;
                    __asm__("" : "=r"(word2) : "0"(word2), "r"(word4));
                    if (word2 && Level20_80130Field(&Level20_80130_D_80070328, int*, 0x170) == 0) {

                        Level20_80130Field(&Level20_80130_D_80070328, int*, 0x20C) = 0x10000001;
                        Level20_80130Field(&Level20_80130_D_80070328, void**, 0x218) = ownerRecord;
                        Level20_80130Field(ownerRecord, signed char*, 0x4F) = 0x20;
                        return;
                    }
                }
            } else {
                default:
                    return;
            }
            break;
        /* Original callback load precedes counter increment. The two empty
     * constraints retain initialized callback/counter operands so the
     * increment and scratch store occupy the original load/call delays. */
        case 6:
            Level20_80130PlayMobySoundEvent(ownerRecord, 1, 0);
            callbackLoop16 = 0;
            do {
                scratch.sp48 = Level20_80130RandSignedBetween(0, 0x28);
                scratch.sp4C = Level20_80130RandSignedBetween(0, 0x28);
                word2 = Level20_80130RandSignedBetween(0, 0x28);
                word4 = 1;
                word5 = 0;
                word6 = (int)(ownerRecord + 0xC);
                callArg7 = &scratch.sp48;
                MATCHING_KEEP_CLOBBER(callArg7, "$3");
                callback3 = Level20_80130_SpawnParticle;
                MATCHING_KEEP2_VOLATILE(callback3, callbackLoop16);
                callbackLoop16 += 1;
                scratch.sp50 = word2;
                callback3(word4, word5, word6, callArg7);
            } while (callbackLoop16 < 5);
            otherCallbackLoop16 = 0;
        callbackGateLoop:
            if ((Level20_80130_D_8006C578 - Level20_80130_D_8006C574) >= 0x15) {
                callArg5 = ownerRecord;
                MATCHING_KEEP(callArg5);
                word4 = Level20_80130Field(ownerRecord, short*, 0x36);
                callback2 = Level20_80130_SpawnMoby;
                MATCHING_KEEP2_VOLATILE(callback2, otherCallbackLoop16);
                otherCallbackLoop16 += 1;
                callback2(word4, callArg5);
                if (otherCallbackLoop16 < 4) {
                    goto callbackGateLoop;
                }
            }
        cleanupTail:
            cleanupLink = Level20_80130Field(privateRecord20, void***, 0x10);
            if (cleanupLink != 0) {
                Level20_80130Field(*cleanupLink, int*, 0x24) = 0;
                Level20_80130Field(privateRecord20, void***, 0x10) = 0;
            }
            Level20_80130DeleteMoby(ownerRecord);
            return;
        case 7:
            Level20_80130UpdateMobyPrivateBallisticMotion(ownerRecord);
            break;
    }
}
#undef Level20_80130Field

void func_80055B18(Moby*);
void func_level_20_80080904(Moby* moby) {
    unsigned char state;

    state = moby->state;
    switch (state) {
        case 0:
            moby->angle.pitch = 0x40;
            moby->state = 1;
            return;
        case 1:
            if (moby->damageFlags & 0x800000) {
                moby->state = 2;
                return;
            }
            return;
        case 2:
            func_80055B18(moby);
            break;
    }
}

void func_80037014(Moby*);
extern ProgressFlags progressFlags;

extern int D_8006C598, D_8006C73C, D_8006C528, currentLevel;
extern short D_800658A0[256], D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
/* AI generated adaptation of upstream func_level_17_8007D19C; not human reviewed.
 * Original SCUS-94467 level20 8008098C instruction route; units/cadence open. */
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
void func_level_20_8008098C(Moby* moby) {
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
                        ((currentLevel != 20) && !progressFlags.lvl20_WhirligigUsable))
                        goto deleteVehicle;
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
                        func_8004F178(&moby->position, (Vector3D*)((PathTag*)mobyTag->unk4)->nodes);
                        func_80037014(moby);
                        *((unsigned char*)moby + 0x52) = 254;
                        func_80055D24(moby, 2);
                        progressFlags.lvl20_WhirligigUsable = 1;
                        moby->state = 1;
                    } else {
                        if (count == 0) {
                        deleteVehicle:
                            func_80055B18(moby);
                            return;
                        }
                        SpawnMoby(count + 0x2B2, moby);
                        func_80055B18(moby);
                    }
                    {
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
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_20/moby/func_level_20_80081298.s SHA256 7041ebe29ebfd225460b1fac003a6a289445280afc358bf4d70e35e2f234a189. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level20_81298Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level20_81298_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level20_81298_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level20_81298_D_8006C550 __asm__("D_8006C550");
extern unsigned char Level20_81298_D_80070300[40] __asm__("D_80070300");
extern Spyro Level20_81298_D_80070328 __asm__("D_80070328");
extern unsigned char Level20_81298_D_80071FB0[40] __asm__("D_80071FB0");
void Level20_81298SetCameraMode11Target(Vector3D*, int, Vector3D*, int) __asm__("func_80013D44");
extern int Level20_81298AllocatePoolRecord20(char, char, int) __asm__("func_8002EC50");
void Level20_81298RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
void Level20_81298SetMobyZFromGroundProbe(Moby* moby) __asm__("func_80037014");
extern void Level20_81298ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level20_81298AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level20_81298ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level20_81298DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level20_81298RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level20_81298_rand() __asm__("rand");

int Level20_81298UpdateMobyInteractionGate() __asm__("func_80037BBC");
/* extern */
unsigned int Level20_81298SpawnSurfaceType4LinkedMoby() __asm__("func_800399E8");
/* extern */
unsigned int Level20_81298UpdateLinkedMobyReflection() __asm__("func_80039B6C");
/* extern */
unsigned int Level20_81298StartDialogue() __asm__("func_800512E4");
/* extern */
unsigned int Level20_81298InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern unsigned char Level20_81298_D_80066FCC __asm__("D_80066FCC");
extern int Level20_81298_D_8006C598 __asm__("D_8006C598");
extern int Level20_81298_D_8006C640 __asm__("D_8006C640");
extern int Level20_81298_D_8006C73C __asm__("D_8006C73C");
extern int Level20_81298_D_8006C770 __asm__("D_8006C770");
extern int Level20_81298_D_8006E048 __asm__("D_8006E048");
extern int Level20_81298_D_8006E344 __asm__("D_8006E344");

void func_level_20_80081298(Moby* ownerRecord) {
    /* Original0x48-byte frame;
     raw scratch triples atSP+0x10 andSP+0x20.
     * Field offsets are bytes. Ordered state/substate comparisons preserve
     * the original dispatch and shared tail at instruction536.
     * Signed table words are promoted before shifts;
      cached array pointers
     * retain original register lifetimes across the scratch stores.
     * Both signed /5 paths retain their original sign correction and
     * high-product intermediates. Helper pointer offsets remain bytes.
     * The state125 branch returns directly to the original epilogue.
     * All register constraints have initialized inputs;
      no instruction asm.
     * Units, helper meanings and frame cadence remain unresolved. */
    struct {
        int sp10;
        int sp14;
        int sp18;
        unsigned char pad1C[4];
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
    } originalFrame;

    Moby* temp_a0_2;
    Moby* temp_a0_5;
    Vector3D* temp_a0;
    Vector3D* temp_a0_4;
    int temp_a0_3;
    int temp_a2;
    register int scaledWord16 __asm__("16");
    int selectedCount19;
    signed char* temp_v0;
    unsigned int temp_s0_2;
    unsigned int temp_s0_3;
    unsigned int temp_s0_4;
    unsigned int rawState3;
    unsigned int rawSubstate3;
    register unsigned int nextRawState2 __asm__("2");
    void* privateRecord18;
    void* parentPrivate20;

    privateRecord18 = ownerRecord->mobyTag;
    parentPrivate20 =
        Level20_81298_D_8006C550[Level20_81298Field(privateRecord18, int*, 0x2C)].mobyTag;
    if ((Level20_81298Field(privateRecord18, int*, 0x24) != 0) &&
        ((unsigned int)(ownerRecord->state - 1) >= 2U) && (ownerRecord->damageFlags != 0)) {
        ownerRecord->state = 2;
        Level20_81298RequestMobyAnimation(ownerRecord, 2);
    }
    rawState3 = ownerRecord->state;
    if (rawState3 == 1)
        goto outerOne;
    if ((int)rawState3 >= 2)
        goto outerHigh;
    if (rawState3 == 0)
        goto outerZero;
    goto block_70;
outerHigh:
    if (rawState3 == 2)
        goto outerTwo;
    goto block_70;
outerZero:
    rawSubstate3 = ownerRecord->substate;
    if (rawSubstate3 == 1)
        goto innerOne;
    if ((int)rawSubstate3 >= 2)
        goto innerHigh;
    if (rawSubstate3 == 0)
        goto innerZero;
    goto block_70;
innerHigh:
    if (rawSubstate3 == 2)
        goto innerTwo;
    if (rawSubstate3 == 3)
        goto innerThree;
    goto block_70;
innerZero:
    if (!(Level20_81298_D_80070300[*(&Level20_81298_D_80066FCC +
                                     Level20_81298Field(privateRecord18, int*, 0x28))] &
          1) ||
        (Level20_81298_D_80071FB0[Level20_81298Field(&Level20_81298_D_80066FCC, unsigned char*,
                                                     0x1B)] != 0)) {
        Level20_81298DeleteMoby(ownerRecord);
        goto block_70;
    }
    selectedCount19 = 0;
    if (ownerRecord->mobyClass == 0x297) {
        Level20_81298Field(privateRecord18, int*, 0x38) =
            Level20_81298AllocatePoolRecord20(1, -2, 0x489090);
    }
    if (Level20_81298_D_80070300[Level20_81298Field(&Level20_81298_D_80066FCC, unsigned char*,
                                                    0x15)] &
        1) {
        selectedCount19 = 1;
    }
    if (Level20_81298_D_80070300[Level20_81298Field(&Level20_81298_D_80066FCC, unsigned char*,
                                                    0x16)] &
        1) {
        selectedCount19 += 1;
    }
    if (Level20_81298_D_80070300[Level20_81298Field(&Level20_81298_D_80066FCC, unsigned char*,
                                                    0x17)] &
        1) {
        selectedCount19 += 1;
    }
    if (Level20_81298_D_80070300[Level20_81298Field(&Level20_81298_D_80066FCC, unsigned char*,
                                                    0x18)] &
        1) {
        selectedCount19 += 1;
    }
    if (Level20_81298_D_80070300[Level20_81298Field(&Level20_81298_D_80066FCC, unsigned char*,
                                                    0x1A)] &
        1) {
        selectedCount19 += 1;
    }
    Level20_81298Field(privateRecord18, int*, 0x30) =
        (int)Level20_81298Field(parentPrivate20, int*, 0);
    if ((selectedCount19 == 5) &&
        (Level20_81298_D_8006C73C == Level20_81298Field(privateRecord18, int*, 0x28))) {
        if (ownerRecord->mobyClass == 0x295) {
            if (ownerRecord->state == 0x7D)
                return;
            if (Level20_81298Field(privateRecord18, Moby**, 0x34) == 0)
                Level20_81298SpawnSurfaceType4LinkedMoby(ownerRecord, privateRecord18 + 0x34);
        }
        nextRawState2 = 2;
        goto block_48;
    } else {
        {
            register int numerator2 __asm__("2");
            register int roundedHigh3 __asm__("3");
            numerator2 = Level20_81298Field(privateRecord18, int*, 0x30) << 8;
            roundedHigh3 = numerator2 / 5 + (numerator2 >> 31);
            MATCHING_KEEP(roundedHigh3);
            scaledWord16 = roundedHigh3 - (numerator2 >> 31);
        }
        __asm__("" : : "r"(scaledWord16) : "4", "5", "7");
        temp_a0 = &ownerRecord->position;
        if (selectedCount19 == 5) {
            {
                register int raw2 __asm__("2");
                raw2 = Level20_81298_D_8006C550[Level20_81298Field(privateRecord18, int*, 0x2C)]
                           .angle.yaw;
                __asm__("" : "=r"(raw2) : "0"(raw2), "r"(scaledWord16));
                scaledWord16 += 0x19;
                raw2 = scaledWord16 + raw2;
                temp_s0_2 = raw2 & 0xFF;
            }
            {
                register int tableWord2 __asm__("2");
                tableWord2 = Level20_81298_D_80065920[temp_s0_2];
                MATCHING_KEEP_CLOBBER(tableWord2, "memory");
                ownerRecord->position.x = tableWord2 >> 1;
                tableWord2 = Level20_81298_D_800658A0[temp_s0_2];
                ownerRecord->position.z = 0;
                __asm__("" : "=r"(tableWord2) : "0"(tableWord2), "m"(ownerRecord->position.z));
                ownerRecord->position.y = tableWord2 >> 1;
            }
            Level20_81298AddVector(
                temp_a0, temp_a0,
                Level20_81298Field(Level20_81298Field(parentPrivate20, void**, 4), Vector3D**,
                                   0xC));
            ownerRecord->angle.yaw = temp_s0_2;
        } else {
            {
                register int index3 __asm__("3");
                register Moby* base6 __asm__("6");
                index3 = Level20_81298Field(privateRecord18, int*, 0x2C);
                base6 = Level20_81298_D_8006C550;
                MATCHING_KEEP2(index3, base6);
                {
                    register int raw2 __asm__("2");
                    raw2 = base6[index3].angle.yaw;
                    raw2 = scaledWord16 + raw2;
                    MATCHING_KEEP(raw2);
                    temp_s0_3 = raw2 & 0xFF;
                }
                {
                    register int tableWord2 __asm__("2");
                    tableWord2 = Level20_81298_D_80065920[temp_s0_3];
                    MATCHING_KEEP_CLOBBER(tableWord2, "memory");
                    ownerRecord->position.x = tableWord2 >> 1;
                    tableWord2 = Level20_81298_D_800658A0[temp_s0_3];
                    ownerRecord->position.z = 0;
                    __asm__("" : "=r"(tableWord2) : "0"(tableWord2), "m"(ownerRecord->position.z));
                    ownerRecord->position.y = tableWord2 >> 1;
                }
                Level20_81298AddVector(
                    temp_a0, temp_a0,
                    &base6[Level20_81298Field(privateRecord18, int*, 0x2C)].position);
                ownerRecord->angle.yaw = temp_s0_3;
                if (Level20_81298Field(privateRecord18, int*, 0x30) != 0) {
                    ownerRecord->angle.yaw = temp_s0_3 + 0x80;
                }
            }
        }
        Level20_81298SetMobyZFromGroundProbe(ownerRecord);
        ownerRecord->subtype = 0xFE;
        Level20_81298RefreshMobySpatialGridAndBasis(ownerRecord, 6);
        temp_a0_2 = Level20_81298Field(privateRecord18, Moby**, 0x34);
        if (temp_a0_2 != 0) {
            Level20_81298DeleteMoby(temp_a0_2);
            Level20_81298Field(privateRecord18, Moby**, 0x34) = 0;
        }
        if (selectedCount19 == 5) {
            nextRawState2 = 2;
            MATCHING_OBSERVE(nextRawState2);
            Level20_81298Field(privateRecord18, signed char*, 2) = nextRawState2;
            nextRawState2 = 1;
            Level20_81298Field(privateRecord18, signed char*, 5) = 0;
        } else {
            nextRawState2 = Level20_81298Field(privateRecord18, int*, 0x30);
            MATCHING_KEEP(nextRawState2);
            if (nextRawState2 != 0) {
                nextRawState2 = 0x63;
                goto block_48;
            }
            nextRawState2 = 1;
        }
    block_48:
        ownerRecord->substate = nextRawState2;
        Level20_81298Field(parentPrivate20, int*, 0) =
            (int)(Level20_81298Field(parentPrivate20, int*, 0) + 1);
        goto block_70;
    }
    goto block_70;
innerOne:
    if (Level20_81298UpdateMobyInteractionGate(ownerRecord, 0) != 0) {
        Level20_81298StartDialogue(ownerRecord, 0, 1);
        ownerRecord->state = 1;
    }
    goto block_70;
innerTwo:
    if ((Level20_81298_D_80070328.ticksSinceLastSurfaceTouch == 0) &&
        (Level20_81298ApproximatePlanarDistance(
             &ownerRecord->position,
             (Vector3D*)((unsigned char*)&Level20_81298_D_80070328.ticksSinceLastSurfaceTouch -
                         0xB8)) < 0x1800)) {
        if (Level20_81298_D_8006C598 == 0) {
            Level20_81298Field(privateRecord18, signed char*, 2) = 1;
            Level20_81298StartDialogue(ownerRecord, 0, 1);
            ownerRecord->state = 1;
        } else {
            Level20_81298_D_80070328.unk17a = 0x10000002;
        }
    }
    goto block_70;
innerThree:
    if (Level20_81298_D_8006E048 == 1) {
        {
            register int input2 __asm__("2");
            register int quotient16 __asm__("16");
            register int roundedHigh4 __asm__("4");
            register int raw2 __asm__("2");
            input2 = Level20_81298Field(privateRecord18, int*, 0x30) << 8;
            MATCHING_KEEP(input2);
            roundedHigh4 = input2 / 5 + (input2 >> 31);
            input2 >>= 31;
            MATCHING_KEEP2(input2, roundedHigh4);
            quotient16 = roundedHigh4 - input2;
            raw2 =
                Level20_81298_D_8006C550[Level20_81298Field(privateRecord18, int*, 0x2C)].angle.yaw;
            __asm__("" : "=r"(raw2) : "0"(raw2), "r"(quotient16));
            quotient16 += 0x19;
            raw2 = quotient16 + raw2;
            temp_s0_4 = raw2 & 0xFF;
        }
        {
            register int tableWord2 __asm__("2");
            tableWord2 = Level20_81298_D_80065920[temp_s0_4];
            MATCHING_KEEP_CLOBBER(tableWord2, "memory");
            ownerRecord->position.x = tableWord2 >> 1;
            tableWord2 = Level20_81298_D_800658A0[temp_s0_4];
            ownerRecord->position.z = 0;
            __asm__("" : "=r"(tableWord2) : "0"(tableWord2), "m"(ownerRecord->position.z));
            ownerRecord->position.y = tableWord2 >> 1;
        }
        {
            register void* parent2 __asm__("2");
            register Vector3D* caller4 __asm__("4");
            parent2 = Level20_81298Field(parentPrivate20, void**, 4);
            __asm__ volatile("" : : : "4", "memory");
            caller4 = &ownerRecord->position;
            MATCHING_KEEP2_CLOBBER(parent2, caller4, "5");
            Level20_81298AddVector(caller4, caller4, Level20_81298Field(parent2, Vector3D**, 0xC));
        }
        Level20_81298SetMobyZFromGroundProbe(ownerRecord);
        ownerRecord->angle.yaw = temp_s0_4;
        ownerRecord->subtype = 0xFE;
        Level20_81298RefreshMobySpatialGridAndBasis(ownerRecord, 6);
        temp_a0_5 = Level20_81298Field(privateRecord18, Moby**, 0x34);
        if (temp_a0_5 != 0) {
            Level20_81298DeleteMoby(temp_a0_5);
            Level20_81298Field(privateRecord18, Moby**, 0x34) = 0;
        }
        ownerRecord->substate = 1;
    }
    goto block_70;
    goto block_70;
outerOne:
    if (Level20_81298_D_8006E344 != rawState3) {
        if (ownerRecord->substate == 2) {
            {
                register int word3 __asm__("3");
                register Moby* records4 __asm__("4");
                word3 = Level20_81298Field(privateRecord18, int*, 0x2C);
                records4 = Level20_81298_D_8006C550;
                MATCHING_KEEP2(word3, records4);
                word3 = Level20_81298_D_80065920[records4[word3].angle.yaw];
                originalFrame.sp10 = (word3 * 0x1D) >> 5;
                word3 = Level20_81298Field(privateRecord18, int*, 0x2C);
                word3 = Level20_81298_D_800658A0[records4[word3].angle.yaw];
                originalFrame.sp18 = 0;
                __asm__("" : "=r"(word3) : "0"(word3), "m"(originalFrame.sp18));
                originalFrame.sp14 = (word3 * 0x1D) >> 5;
            }
            Level20_81298AddVector(
                (Vector3D*)&originalFrame.sp10, (Vector3D*)&originalFrame.sp10,
                Level20_81298Field(Level20_81298Field(parentPrivate20, void**, 4), Vector3D**,
                                   0xC));
            originalFrame.sp18 += Level20_81298_D_80070328.unk4a;
            Level20_81298SetCameraMode11Target(
                (Vector3D*)&originalFrame.sp10,
                Level20_81298_D_8006C550[Level20_81298Field(privateRecord18, int*, 0x2C)]
                        .angle.yaw +
                    0x80,
                0, 0);
            Level20_81298Field(privateRecord18, signed char*, 5) = 0;
            ownerRecord->substate = 3;
        }
        ownerRecord->damageFlags = 0;
        ownerRecord->state = 0;
    }
    goto block_70;
outerTwo:
    if (Level20_81298_D_8006C770 != 0) {
        ownerRecord->damageFlags = 0;
        ownerRecord->state = 0;
        Level20_81298RequestMobyAnimation(ownerRecord, 0);
    } else if ((ownerRecord->damageFlags & 0x10000) && (Level20_81298_D_8006C640 & 1)) {
        originalFrame.sp20 = (Level20_81298_rand() & 0xF) - 8;
        originalFrame.sp24 = (Level20_81298_rand() & 0xF) - 8;
        originalFrame.sp28 = (Level20_81298_rand() & 0xF) + 8;
        temp_v0 = SpawnParticle(1, 0x37, &ownerRecord->position, (Vector3D*)&originalFrame.sp20);
        if (temp_v0 != 0) {
            Level20_81298Field(temp_v0, unsigned short*, 8) =
                (unsigned short)(Level20_81298Field(temp_v0, unsigned short*, 8) +
                                 (Level20_81298_rand() & 0xFF));
        }
    }
    goto block_70;
    goto block_70;
block_70:
    if (ownerRecord->mobyClass == 0x295) {
        if (ownerRecord->state != 0x7D) {
            if (Level20_81298Field(privateRecord18, Moby**, 0x34) != 0) {
                Level20_81298UpdateLinkedMobyReflection(ownerRecord, privateRecord18 + 0x34);
                return;
            }
        } else {
            goto block_75;
        }
    } else {
    block_75:
        if (ownerRecord->mobyClass == 0x297) {
            temp_a2 = Level20_81298Field(privateRecord18, int*, 0x38);
            if (temp_a2 != 0) {
                Level20_81298InterpolateMobyVertex(ownerRecord, 0, temp_a2);
                Level20_81298InterpolateMobyVertex(ownerRecord, 1, (int)&originalFrame.sp10);
                temp_a0_3 = Level20_81298Field(privateRecord18, int*, 0x38);
                Level20_81298AddVector((Vector3D*)temp_a0_3, (Vector3D*)temp_a0_3,
                                       (Vector3D*)&originalFrame.sp10);
                Level20_81298ShiftVectorRightTowardZero(
                    (Vector3D*)Level20_81298Field(privateRecord18, int*, 0x38), 1);
                Level20_81298Field(Level20_81298Field(privateRecord18, int*, 0x38), signed char*,
                                   0x13) = 8;
            }
        }
        return;
    }
}
#undef Level20_81298Field

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
int A4973MaskLinkedRecordFlagsById_26() __asm__("func_80021ED8");
void func_level_20_80081BBC(unsigned char* input) {
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
        A4973MaskLinkedRecordFlagsById_26(arg4, 252, 0);
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
void func_level_20_800827DC(Moby* moby) {
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
void func_level_20_80082B0C(Moby* actor) {
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

/* AI-generated; not human reviewed. Reuses verified func_level_10_800821F8
 * with this overlay's original fragment selector. Raw field units, helper
 * meanings and update cadence remain unverified. See batch 3771 provenance. */
extern unsigned char Controller821F8AngleTable[] __asm__("D_80065398");
extern unsigned char Controller821F8InitialTable[] __asm__("D_80066BDC");
#define Controller821F8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller821F8CDLoadTime(void) __asm__("CDLoadTime");
int Controller821F8ConfigureHudEntry(int, int, void*, int, void*, int,
                                     int) __asm__("func_8002803C");
int Controller821F8ResetHudEntryByHandle(int) __asm__("func_80028154");
int Controller821F8RelocateAndPublishModel(void*, int, int) __asm__("func_8002AF9C");
int Controller821F8RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller821F8CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller821F8SubAngle8(int, int) __asm__("func_8003613C");
int Controller821F8RequestIndexedLevelDataSlice(int, int, int) __asm__("func_80039974");
int Controller821F8PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller821F8TransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Controller821F8SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Controller821F8SetSoundHandleWord0CAndFlag10(int, int) __asm__("func_8003C140");
int Controller821F8SetClampedPlayerTargetAngles(void*, int) __asm__("func_800492DC");
int Controller821F8PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller821F8CopyVector(void*, void*) __asm__("func_8004F178");
int Controller821F8AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller821F8ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller821F8SetState15OwnerContext(void*, int) __asm__("func_800527C4");
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
void func_level_20_80082D18(void* input) {
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

    tag = ((Moby*)owner)->mobyTag;
    distance = Controller821F8ApproximatePlanarDistance(owner + 0xC, Controller821F8D_80070328);
    {
        register int heightOffset __asm__("$3") = ((Moby*)owner)->distanceToGround;
        temp_v0 = ((Moby*)owner)->position.z;
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
    temp_v1 = ((Moby*)owner)->state;
    switch (temp_v1) { /* switch 1 */
        case 0:        /* switch 1 */
            if (Controller821F8Field(tag, short*, 6) < 0) {
                Controller821F8Field(tag, short*, 6) = (short)((Moby*)owner)->angle.yaw;
            }
            temp_v1_2 = Controller821F8Field(tag, short*, 0);
            if (temp_v1_2 >= 0) {
                if ((((int)Controller821F8D_8006C7B4 >> temp_v1_2) & 1) ||
                    (((int)*(Controller821F8D_80070300 + Controller821F8D_8006C58C) >> temp_v1_2) &
                     1)) {
                    Controller821F8DeleteMoby(owner);
                } else if (Controller821F8ApproximatePlanarDistance(
                               owner + 0xC, Controller821F8D_80070328) < 0x2000) {
                    var_v0 = ((((Moby*)owner)->position.z - ((Moby*)owner)->distanceToGround) -
                              Controller821F8Field(Controller821F8D_80070328, int*, 8)) +
                             Controller821F8Field(Controller821F8D_80070328, int*, 0x44);
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    if ((var_v0 < 0x800) &&
                        ((Controller821F8AbsoluteByteAngleDelta(
                              ((Moby*)owner)->angle.yaw,
                              Controller821F8PlanarHeadingLookup(
                                  Controller821F8Field(Controller821F8D_80070328, int*, 0) -
                                      ((Moby*)owner)->position.x,
                                  Controller821F8Field(Controller821F8D_80070328, int*, 4) -
                                      ((Moby*)owner)->position.y,
                                  0)) < 0x20) ||
                         (Controller821F8Field(tag, short*, 0x16) != 0))) {
                        ((Moby*)owner)->state = 7U;
                        Controller821F8Field(tag, unsigned short*, 0xC) = 0U;
                    }
                }
            }
        default: /* switch 1 */
            goto sharedTail;
        case 7: /* switch 1 */
            if ((distance >= 0x2401) || (verticalDistance >= 0x901)) {
                ((Moby*)owner)->state = 0U;
            } else if ((distance < 0x800) && (verticalDistance < 0x200) &&
                       ((Controller821F8Field(Controller821F8D_80070328, int*, 0xB8) == 0) ||
                        ((unsigned int)(Controller821F8Field(Controller821F8D_80070328, int*,
                                                             0x50) -
                                        0xB) < 2U)) &&
                       ((Controller821F8AbsoluteByteAngleDelta(
                             ((Moby*)owner)->angle.yaw,
                             Controller821F8PlanarHeadingLookup(
                                 Controller821F8Field(Controller821F8D_80070328, int*, 0) -
                                     ((Moby*)owner)->position.x,
                                 Controller821F8Field(Controller821F8D_80070328, int*, 4) -
                                     ((Moby*)owner)->position.y,
                                 0)) < 0x20) ||
                        (Controller821F8Field(tag, short*, 0x16) != 0))) {
                ((Moby*)owner)->state = 1U;
            }
            goto sharedTail;
        case 1: /* switch 1 */
            Controller821F8SetState15OwnerContext(owner, Controller821F8Field(tag, short*, 0));
            /* fallthrough */
        case 2: /* switch 1 */
            if (Controller821F8SoundHandleMatchesOwnerInStates1Or2(
                    owner, Controller821F8Field(tag, short*, 0x14)) == 0) {
                temp_v0_2 = Controller821F8PlayMobySoundEvent(owner, 0, 4);
                Controller821F8Field(tag, short*, 0x14) = temp_v0_2;
                if (temp_v0_2 >= 0) {
                    Controller821F8SetSoundHandleWord0CAndFlag10(temp_v0_2, 1);
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
            Controller821F8SetClampedPlayerTargetAngles(owner + 0xC, var_a1);
            Controller821F8Field(tag, short*, 2) = 0xB4;
            Controller821F8D_8006C3EC = 0;
            ((Moby*)owner)->state = 3U;
            if (Controller821F8Field(
                    ((Controller821F8Field(tag, short*, 0) * 0xC) + Controller821F8D_8006C7A0),
                    unsigned char*, 7) == 0xFF) {
                Controller821F8Field(tag, short*, 4) = -1;
                ((Moby*)owner)->substate = 4U;
            } else {
                Controller821F8Field(tag, short*, 4) = Controller821F8ConfigureHudEntry(
                    0x36, -1, Controller821F8func_80027F88, 0, Controller821F8func_80029CF8,
                    *(int*)((Controller821F8Field(tag, short*, 0) * 0xC) +
                            Controller821F8D_8006C7A0),
                    0);
                Controller821F8D_8006E49C = 1;
                ((Moby*)owner)->substate = 0U;
            }
            goto sharedTail;
        case 3: /* switch 1 */
            if (Controller821F8SoundHandleMatchesOwnerInStates1Or2(
                    owner, Controller821F8Field(tag, short*, 0x14)) == 0) {
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
                        Controller821F8SetSoundHandleWord0CAndFlag10(var_a0, (var_a1 >> 6) | 1);
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
                height = ((Moby*)owner)->position.z;
                alpha = ((Moby*)owner)->size;
                MATCHING_KEEP2_CLOBBER(height, alpha, "$8");
                particle = Controller821F8SpawnParticle;
                MATCHING_KEEP2(particle, height);
                height += 128;
                height -= alpha;
                ((Moby*)owner)->position.z = height;
                particle(selector, kind, particleOwner, mode);
                height = ((Moby*)owner)->position.z;
                alpha = ((Moby*)owner)->size;
                __asm__ volatile(""
                                 : "=r"(height), "=r"(alpha)
                                 : "0"(height), "1"(alpha)
                                 : "$4", "memory");
                temp_a0_3 = ((Moby*)owner)->size;
                MATCHING_KEEP3(temp_a0_3, height, alpha);
                height -= 128;
                height += alpha;
                ((Moby*)owner)->position.z = height;
            }
            if ((temp_a0_3 != 0) &&
                ((unsigned int)owner >= (unsigned int)Controller821F8D_8006C704)) {
                ((Moby*)owner)->size = (unsigned char)*(int*)(Controller821F8D_80065398 + 0xA4 +
                                                              (Controller821F8D_8006C3EC * 0xC));
            }
            ((Moby*)owner)->angle.roll = (unsigned char)*(int*)(Controller821F8AngleTable + 0x9C +
                                                                (Controller821F8D_8006C3EC * 0xC));
            ((Moby*)owner)->angle.pitch = (unsigned char)*(int*)(Controller821F8D_80065398 + 0xA0 +
                                                                 (Controller821F8D_8006C3EC * 0xC));
            nextTableIndex = Controller821F8D_8006C3EC + 1;
            Controller821F8D_8006C3EC = nextTableIndex;
            if (nextTableIndex >= 0x40) {
                Controller821F8D_8006C3EC = 0x2F;
            }
            temp_v1_5 = ((Moby*)owner)->substate;
            switch (temp_v1_5) {
                case 0:
                    if (Controller821F8D_8006E48C != 0)
                        goto loadingDone;
                    if (Controller821F8CDLoadTime() != 0)
                        goto loadingBusy;
                    var_a1 = 0;
                    MATCHING_KEEP_CLOBBER(var_a1, "$4");
                    var_a0 = Controller821F8Field(tag, short*, 0);
                    Controller821F8RequestIndexedLevelDataSlice(var_a0, var_a1, 0x3000);
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
                    Controller821F8RequestIndexedLevelDataSlice(var_a0, var_a1, 0);
                    var_v0_2 = 3;
                    goto storeLoadingState;
                case 3:
                    if (Controller821F8CDLoadTime() != 0)
                        goto loadingBusy;
                    var_a1 = 500;
                    MATCHING_KEEP_CLOBBER(var_a1, "$4");
                    Controller821F8RelocateAndPublishModel(Controller821F8D_8006C5B0, var_a1,
                                                           0x80400000);
                    var_v0_2 = 4;
                storeLoadingState:
                    ((Moby*)owner)->substate = var_v0_2;
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
            Controller821F8SetClampedPlayerTargetAngles(owner + 0xC, var_a1);
            if ((Controller821F8CountTimerDown(tag + 2, 2) != 0) &&
                (((Moby*)owner)->substate == 4)) {
                if (Controller821F8Field(
                        ((Controller821F8Field(tag, short*, 0) * 0xC) + Controller821F8D_8006C7A0),
                        unsigned char*, 7) == 0xFF) {
                    Controller821F8Field(tag, void**, 8) = 0;
                } else {
                    Controller821F8Field(tag, void**, 8) = Controller821F8SpawnMoby(0x1F4, owner);
                }
                if (Controller821F8Field(tag, void**, 8) != 0) {
                    if ((unsigned int)(Controller821F8Field(tag, unsigned short*, 0) - 3) < 2) {
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
                    ((Moby*)owner)->state = 4U;
                    Controller821F8D_8006C3EC = 0;
                    Controller821F8Field(owner, signed char*, 0x4C) = 0;
                    Controller821F8Field(owner, signed char*, 0x4D) = 0;
                    Controller821F8RefreshMobySpatialGridAndBasis(
                        Controller821F8Field(tag, void**, 8), 4);
                    if (Controller821F8SoundHandleMatchesOwnerInStates1Or2(
                            owner, Controller821F8Field(tag, short*, 0x14)) != 0) {
                        Controller821F8TransitionSoundHandleTo3Or5(
                            Controller821F8Field(tag, short*, 0x14));
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
            Controller821F8SetClampedPlayerTargetAngles(&frame.vector, var_a1);
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
                    temp_a0_5 = ((Moby*)owner)->position.z;
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
                ((Moby*)owner)->state = 8U;
            }
            goto sharedTail;
        case 9: /* switch 1 */
            if (Controller821F8SoundHandleMatchesOwnerInStates1Or2(
                    owner, Controller821F8Field(tag, short*, 0x14)) != 0) {
                Controller821F8TransitionSoundHandleTo3Or5(Controller821F8Field(tag, short*, 0x14));
            }
            Controller821F8Field(tag, short*, 0x14) = -1;
            var_a1 = 0x10000002;
            {
                register int flags __asm__("$2") =
                    Controller821F8Field(Controller821F8D_80070328, int*, 0x20C);
                MATCHING_KEEP2(flags, var_a1);
                Controller821F8Field(Controller821F8D_80070328, int*, 0x20C) = flags | var_a1;
            }
            Controller821F8SetClampedPlayerTargetAngles(owner + 0xC, var_a1);
            Controller821F8Field(owner, int*, 0x54) =
                (int)(((((Moby*)owner)->position.z + Controller821F8Field(tag, short*, 2)) &
                       0xFFFFFF) |
                      0x80000000);
            temp_a0_6 = Controller821F8Field(tag, void**, 0x10);
            if (temp_a0_6 != 0) {
                Controller821F8Field(temp_a0_6, int*, 0x14) =
                    (int)(((Moby*)owner)->position.z + Controller821F8Field(tag, short*, 2));
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
            Controller821F8SetClampedPlayerTargetAngles(&frame.vector, var_a1);
            Controller821F8CopyVector(owner + 0xC, &frame.vector);
            Controller821F8Field(Controller821F8Field(tag, void**, 8), int*, 0x54) =
                (int)(((((Moby*)owner)->position.z + Controller821F8Field(tag, short*, 2)) &
                       0xFFFFFF) |
                      0x80000000);
            temp_a0_9 = Controller821F8Field(tag, void**, 0x10);
            if (temp_a0_9 != 0) {
                Controller821F8Field(temp_a0_9, int*, 0x14) =
                    (int)(((Moby*)owner)->position.z + Controller821F8Field(tag, short*, 2));
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
                ((Moby*)owner)->state = 5;
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
            Controller821F8ResetHudEntryByHandle(Controller821F8Field(tag, short*, 4));
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
            ((Moby*)owner)->state = 0xAU;
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
                var_v1 = Controller821F8SubAngle8(((Moby*)owner)->angle.roll, 0);
                if (var_v1 < 0) {
                    var_v1 -= 1;
                } else if (var_v1 > 0) {
                    var_v1 += 1;
                }
                ((Moby*)owner)->angle.roll =
                    (unsigned char)(((Moby*)owner)->angle.roll + (var_v1 >> 1));
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
                ((Moby*)owner)->angle.roll,
                (int)(*(unsigned short*)(Controller821F8D_800658A0 + (temp_v1_3 & 0x1FE))
                      << 0x10) >>
                    0x18);
            if (var_v1_2 < 0) {
                var_v1_2 -= 1;
            } else if (var_v1_2 > 0) {
                var_v1_2 += 1;
            }
            ((Moby*)owner)->angle.roll =
                (unsigned char)(((Moby*)owner)->angle.roll + (var_v1_2 >> 1));
            var_v1_3 = Controller821F8SubAngle8(
                ((Moby*)owner)->angle.pitch,
                (int)(*(unsigned short*)(Controller821F8D_80065920 +
                                         (Controller821F8Field(tag, unsigned short*, 0xC) & 0x1FE))
                      << 0x10) >>
                    0x18);
            if (var_v1_3 < 0) {
                var_v1_3 -= 1;
            } else if (var_v1_3 > 0) {
                var_v1_3 += 1;
            }
            ((Moby*)owner)->angle.pitch =
                (unsigned char)(((Moby*)owner)->angle.pitch + (var_v1_3 >> 1));
        }
    } else {
        return;
    }
}

void func_level_20_80083EAC(Moby* moby) {
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
void func_level_20_80083ECC(Moby* mobyArgument) {
    register Moby* moby __asm__("$10") = mobyArgument;
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

typedef struct {
    unsigned char reserved00[0x18];
    int counter;
} DecodedVectorForceTag;
extern short D_800658A0[], D_80065920[];
void func_level_20_800840CC(Moby* moby) {
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
void func_level_20_800841EC(Moby* moby) {
    if (D_8006C770 != 0)
        func_80055B18(moby);
}
