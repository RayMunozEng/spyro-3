#include "matching.h"
#include "common.h"
#include "savepoint.h"
#include "spu.h"
#include "camera.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
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
void func_level_42_80074F78(void* input) {
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
                if ((var_v0 < var_a0) && (Controller74C50D_8006C65C != 0) &&
                    ((((Moby*)owner)->state != 2) ||
                     ((unsigned char)Controller74C50Field(tag, unsigned char*, 0x12) < 3U)) &&
                    (callbackTag = Controller74C50Field(Controller74C50D_8006C65C, void**, 0),
                     Controller74C50CopyVector(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64,
                     (Controller74C50TestSubdividedSegmentPath(Controller74C50D_8006C65C + 0xC,
                                                               &frame.ninth.x, 0) != 0))) {
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
void func_level_42_80075BD4(Moby* mobyArgument) {
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

/* AI generated; not yet human reviewed. Derived from SCUS-94467 USA Rev 0
 * original instructions and all five dispatch tables, including padding.
 * Offsets, signedness, shifts, and integer operations preserve the disc data.
 * Physical units, helper meanings, and caller cadence remain unresolved;
 * this routine describes one invocation. Empty compiler constraints preserve
 * proven register allocation and scheduling without emitting instructions.
 */
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
void func_level_42_80076260(void* input) {
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

    tag = ((Moby*)owner)->mobyTag;
    originalAngle = ((Moby*)owner)->angle.yaw;
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
            register void* particleVector __asm__("$16") = &frame.second.x;
            register void* first __asm__("$4") = particleVector;
            register int angleIndex __asm__("$3") = ((Moby*)owner)->angle.yaw;
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
}

#undef Controller75F38Field


typedef struct {
    short counter;
    unsigned char unk2, unk3;
} DecodedColourTag;
void func_80055B18(Moby*);
void func_level_42_800777B0(Moby* moby) {
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
void func_level_42_800778EC(Moby* moby) {
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
void func_level_42_800779A8(Moby* moby) {
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
void func_level_42_80077A5C(Moby* moby) {
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
void func_level_42_80077D1C(Moby* mobyArgument) {
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
int A4914SetMobyZFromGroundProbe() __asm__("func_80037014");
int A4914ConfigureHudEntry() __asm__("func_8002803C");
int A4914InitializeHudCounterEntry() __asm__("func_80027D60");
int A4914DrawHudIcon() __asm__("func_8002982C");
int A4914PlanarHeadingLookup() __asm__("func_8004E880");
int A4914AbsoluteByteAngleDelta() __asm__("func_8004F264");
int A4914CopyVector() __asm__("func_8004F178");
int A4914SetState15OwnerContext() __asm__("func_800527C4");
int A4914PlayMobySoundEvent() __asm__("func_8003BABC");
int A4914SubtractVector() __asm__("func_8004F1C8");
int A4914ShiftVectorRightTowardZero() __asm__("func_8004F110");
int A4914MultiplyVectorGpfSf0() __asm__("func_8004F1FC");
int A4914DivideVector() __asm__("func_8004F228");
int A4914AddVector() __asm__("func_8004F194");
int A4914TurnMobyTowardHeading() __asm__("func_8003585C");
int A4914SetClampedPlayerTargetAngles() __asm__("func_800492DC");
int A4914RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int A4914DeleteMoby() __asm__("func_80055B18");
int A4914ResetHudEntryByHandle() __asm__("func_80028154");
int A4914UpdateMobyHitColour() __asm__("func_800368A4");
int A4914Rand() __asm__("rand");
void func_level_42_8007823C(unsigned char* input) {
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
        A4914SetMobyZFromGroundProbe(owner19);
    work3 = A4914W(private18, 28);
    work2 = work3 * 88;
    work3 = (int)A4914Models;
    work2 += work3;
    if (A4914B((void*)work2, 72) >= 128 && A4914W(private18, 32) == -1)
        A4914W(private18, 32) = (short)A4914ConfigureHudEntry(
            6, 4000, A4914InitializeHudCounterEntry, 0, A4914DrawHudIcon, 0, 0);
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
            A4914SetState15OwnerContext(owner19, -1);
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
            A4914SetClampedPlayerTargetAngles((void*)(A4914W(private18, 36) + 12));
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
                A4914ResetHudEntryByHandle(arg4);
            A4914W(private18, 32) = counter16;
            A4914DeleteMoby(owner19);
            goto done;
    }
    goto update;
update:
common:
    A4914W(private18, 20) = A4914UpdateMobyHitColour(owner19, A4914W(private18, 20),
                                                     A4914F(owner19, short*, 54) != 201);
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
void func_level_42_80078CAC(Moby* moby) {
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
void func_level_42_8007902C(Moby* moby) {
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
void func_level_42_80079330(Moby* moby) {
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
void func_level_42_80079638(void* input) {
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
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            Controller78288Field(prefixTag, unsigned char*, 5) = 1U;
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
                                Controller78288StartDialogue(owner, 0, 0);
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
                    if (Controller78288D_8006E344 != 1) {
                        goto setSubstateFour;
                    }
                    goto clearExtraHandle;
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
void func_level_42_8007A1AC(Moby* moby) {
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
void func_level_42_8007A5DC(Moby* moby) {
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
void func_level_42_8007A944(Moby* owner) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Original SCUS-94467 assembly SHA256 c16145efb704709cac56c76f963b03352fa67c4fc6f71424e7d9d583dc419fc1. Rev1 raw131 provides a structural crosswalk only. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))


int Desert7AAD0QueryWorldSegmentWithOptions() __asm__("func_8001830C");
int Desert7AAD0QueryWorldSphereWithOptions() __asm__("func_80019138");
void* Desert7AAD0QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int Desert7AAD0BuildPackedAngleBasisMatrix() __asm__("func_8004EA90");
int Desert7AAD0TransformVectorByBasis() __asm__("func_8004ED6C");
int Desert7AAD0MeasureVectorLength() __asm__("func_8004EDE8");
int Desert7AAD0DeleteMoby() __asm__("func_80055B18");
extern unsigned char Desert7AAD0_D_800658A0 __asm__("D_800658A0");
extern unsigned char Desert7AAD0_D_80065920 __asm__("D_80065920");
extern int Desert7AAD0_D_8006C574 __asm__("D_8006C574");
extern int Desert7AAD0_D_8006C578 __asm__("D_8006C578");
extern int Desert7AAD0_D_8006C640 __asm__("D_8006C640");
extern unsigned char Desert7AAD0_D_8006EE2C __asm__("D_8006EE2C");
extern int Desert7AAD0_D_80071934 __asm__("D_80071934");

int DesertAAD0_State0Timer() __asm__("func_800359A4");
int DesertAAD0_State3Timer() __asm__("func_800359A4");

void func_level_42_8007AAD0(Moby* inputMoby) {
    /* Member names retain original stack offsets and raw retail units. */
    struct {
        Vector3D sp18;
        char pad_24[4];
        unsigned char sp28;
        char pad_29[23];
        Vector3D sp40;
        char pad_4c[4];
        int sp50;
        int sp54;
        int sp58;
        char pad_5c[12];
    } originalStack;

register Moby* moby __asm__("$18") = inputMoby;

    register Moby* childMoby __asm__("$16");
    register Moby* child541 __asm__("$3");
    register Moby* child482 __asm__("$3");
    register Vector3D* mobyPosition __asm__("$16");
    register Vector3D* mobyPositionAgain __asm__("$16");
    register Vector3D* mobyPositionFinal __asm__("$16");
    register int tableValue7 __asm__("$7");
    register int angle2 __asm__("$2");
    register int positionY4 __asm__("$4");
    register int positionX5 __asm__("$5");
    register int sizeQuotient2 __asm__("$2");
    register int positionZ3 __asm__("$3");
    register int tableIndex3 __asm__("$3");
    register int particleCount __asm__("$16");
    register int angleByte2 __asm__("$2");
    register int state3 __asm__("$3");
    register void* privateData __asm__("$19");
    register void* contactMoby __asm__("$16");
    register void* privateVectorAddress4 __asm__("$4");


    register int* querySlot17 __asm__("$17");
    register Vector3D* particlePosition17 __asm__("$17");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    MATCHING_KEEP(moby);
    positionX5 = moby->position.x;
    privateData = moby->mobyTag;
    value2 = positionX5 > 0x3D400;
    if (value2)
        goto releaseMoby;
    positionY4 = moby->position.y;
    value2 = positionY4 > 0x3D400;
    if (value2)
        goto releaseMoby;
    positionZ3 = moby->position.z;
    value2 = positionZ3 > 0x1E000;
    if (value2)
        goto releaseMoby;
    value2 = positionX5 < 0x800;
    if (value2)
        goto releaseMoby;
    value2 = positionY4 < 0x800;
    if (value2)
        goto releaseMoby;
    value2 = positionZ3 < 0x800;
    if (value2)
        goto releaseMoby;
    {
        state3 = moby->state;
        switch (state3) {
            case 0:
                MATCHING_KEEP(state3);
                value2 = moby->substate;
                MATCHING_KEEP_CLOBBER(value2, "$4");
                privateVectorAddress4 = privateData + 0x10;
                if (value2 == 0) {
                    MATCHING_KEEP(value2);
                    argument4 = (int)moby;
                    argument5 = 0;
                    MATCHING_KEEP2(argument4, argument5);
                    func_8003BABC(argument4, argument5, 0);
                    moby->substate = 1;
                    MATCHING_KEEP_VOLATILE(privateData);
                    privateVectorAddress4 = privateData + 0x10;
                    MATCHING_KEEP(privateVectorAddress4);
                }
                angle2 = M2C_FIELD(privateData, short*, 0xE);
                tableIndex3 = angle2 * 2;
                tableValue7 = M2C_FIELD(&Desert7AAD0_D_80065920, short*, tableIndex3);
                value3 = M2C_FIELD(&Desert7AAD0_D_800658A0, short*, tableIndex3);
                M2C_FIELD(privateData, short*, 0xE) = (short)((angle2 + 0xE) & 0xFF);
                M2C_FIELD(privateData, int*, 0) = 0x226;
                M2C_FIELD(privateData, int*, 4) = (int)((int)(tableValue7 * 0xF) >> 0xB);
                M2C_FIELD(privateData, int*, 8) = (int)((int)(value3 * 0xF) >> 0xB);
                Desert7AAD0BuildPackedAngleBasisMatrix(privateVectorAddress4, &originalStack.sp28,
                                                       0, tableValue7);
                Desert7AAD0TransformVectorByBasis(&originalStack.sp28, privateData, privateData);
                argument4 = (int)&originalStack.sp18;
                MATCHING_KEEP(argument4);
                mobyPosition = &moby->position;
                func_8004F178(argument4, mobyPosition);
                func_8004F194(mobyPosition, mobyPosition, (Vector3D*)privateData);
                argument4 = (int)&originalStack.sp18;
                argument5 = (int)mobyPosition;
                argument6 = 2;
                argument7 = 0;
                MATCHING_KEEP4(argument4, argument5, argument6, argument7);
                querySlot17 = &Desert7AAD0_D_80071934;
                *querySlot17 = 0;
                if (Desert7AAD0QueryWorldSegmentWithOptions(argument4, argument5, argument6,
                                                            argument7, 0) != 0) {
                    moby->state = 1;
                }
                if (*querySlot17 != 0) {
                    moby->state = 1;
                }
                contactMoby =
                    Desert7AAD0QueryDynamicMobyGeometry(mobyPosition, 0x12C, 0, 0, 0x940000, moby);
                if (contactMoby != 0) {
                    angleByte2 = func_8004E880(M2C_FIELD(privateData, int*, 0),
                                               M2C_FIELD(privateData, int*, 4), 0);
                    M2C_FIELD(contactMoby, signed char*, 0x51) = angleByte2;
                    if (!(angleByte2 & 0xFF)) {
                        M2C_FIELD(contactMoby, signed char*, 0x51) = 1;
                    }
                    moby->state = 1;
                }
                mobyPositionAgain = &moby->position;
                Desert7AAD0QueryWorldSphereWithOptions(mobyPositionAgain, 0x190, 2, 0, 0x950000,
                                                       moby);
                argument4 = (int)&originalStack.sp18;
                argument5 = (int)mobyPositionAgain;
                MATCHING_KEEP2(argument4, argument5);
                querySlot17 = &Desert7AAD0_D_80071934;
                *querySlot17 = 0;
                func_8004F178(argument4, argument5);
                originalStack.sp18.z -= 0x400;
                Desert7AAD0QueryWorldSegmentWithOptions(mobyPositionAgain, &originalStack.sp18, 2,
                                                        0, 0);
                if (*querySlot17 != 0) {
                    moby->state = 1;
                }
                if ((Desert7AAD0_D_8006C640 == ((Desert7AAD0_D_8006C640 / 3) * 3)) &&
                    ((Desert7AAD0_D_8006C578 - Desert7AAD0_D_8006C574) >= 0x15)) {
                    childMoby = SpawnMoby((int)moby->mobyClass, moby);
                    if (childMoby != 0) {
                        childMoby->angle.pitch =
                            func_8004E880(Desert7AAD0MeasureVectorLength(privateData, 0),
                                          M2C_FIELD(privateData, int*, 8), 0);
                        childMoby->angle.yaw = func_8004E880(M2C_FIELD(privateData, int*, 0),
                                                             M2C_FIELD(privateData, int*, 4), 0);
                        value2 = childMoby->mobyClass;
                        MATCHING_KEEP_CLOBBER(value2, "$3");
                        value3 = 1;
                        MATCHING_KEEP2(value2, value3);
                        childMoby->state = value3;
                        childMoby->unknown3[1] = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value2 = (int)M2C_FIELD(&Desert7AAD0_D_8006EE2C, void**, value2 * 4);
                        value2 = (int)M2C_FIELD(value2, unsigned char**, 0x40);
                        value2 = M2C_FIELD(value2, unsigned char*, 0);
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        childMoby->animationState.id = value3;
                        childMoby->animationState.nextId = value3;
                        childMoby->animationState.nextFrame = value3;
                        value3 = 2;
                        childMoby->animationState.frame = 0;
                        childMoby->state = value3;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value2 = (unsigned int)value2 < 2U;
                        MATCHING_KEEP(value2);
                        value2 ^= 1;
                        value2 = -value2;
                        value2 &= 0x30;
                        childMoby->animationProgress = value2;
                    }
                }
                if (moby->state != 0)
                    return;
                if (DesertAAD0_State0Timer(privateData + 12, 2) == 0)
                    return;
                goto releaseMoby;
            case 1:
                MATCHING_KEEP(state3);
                func_8003BABC(moby, 1, 0);
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
                M2C_FIELD(privateData, short*, 0xC) = 0x28;
                moby->state = 3;
                /* fallthrough */
            case 3:

            if (M2C_FIELD(privateData, short*, 0xC) >= 0xB) {
                    particleCount = 0;
                    particlePosition17 = &originalStack.sp40;
                    do {
                        originalStack.sp50 = func_800363DC(0, 0x96);
                        originalStack.sp54 = func_800363DC(0, 0x96);
                        originalStack.sp58 = func_8003636C(-0x32, 0x50);
                        func_8004F178(particlePosition17, &moby->position);
                        value2 = func_800363DC(0, 100);
                        argument4 = 0;
                        argument5 = 100;
                        MATCHING_KEEP2_VOLATILE(argument4, argument5);
                        value3 = originalStack.sp40.x;
                        MATCHING_KEEP(value3);
                        particleCount += 1;
                        value3 += value2;
                        originalStack.sp40.x = value3;
                        originalStack.sp40.y += func_800363DC(argument4, argument5);
                        originalStack.sp40.z += func_800363DC(0, 0x64);
                        SpawnParticle(1, 0x27, particlePosition17, (Vector3D*)&originalStack.sp50);
                    } while (particleCount < 4);

                    if ((M2C_FIELD(privateData, short*, 0xC) >= 0xB) &&
                        ((Desert7AAD0_D_8006C578 - Desert7AAD0_D_8006C574) >= 0x15)) {
                        child541 = SpawnMoby(0x21D, moby);
                        if (child541 != 0) {
                            child541->unknown4 = 8;
                            child541->lowDrawDistance = 0x30;
                            child541->highDrawDistance = 0x30;
                            child541->size = 0x7F;
                        }
                    }
                }
                if ((func_800359A4(privateData + 19, 1) != 0) &&
                    ((Desert7AAD0_D_8006C578 - Desert7AAD0_D_8006C574) >= 0x15)) {
                    child482 = SpawnMoby(0x1E2, moby);
                    if (child482 != 0) {
                        child482->unknown4 = 8;
                        child482->lowDrawDistance = 0x20;
                        child482->highDrawDistance = 0x20;
                    }
                    M2C_FIELD(privateData, signed char*, 0x13) = func_8003636C(2, 4);
                }
                MATCHING_KEEP_VOLATILE(privateData);
                mobyPositionFinal = &moby->position;
                Desert7AAD0QueryDynamicMobyGeometry(mobyPositionFinal, 0x7D0, 0, 0, 0x940000, moby);
                Desert7AAD0QueryWorldSphereWithOptions(mobyPositionFinal, 0x7D0, 2, 0, 0x950000,
                                                       moby);
                if (DesertAAD0_State3Timer(privateData + 12, 2) == 0)
                    return;
                goto releaseMoby;
            case 2:
                MATCHING_KEEP2_VOLATILE(state3, privateData);
                if (func_800359A4(privateData + 12, 2) != 0) {
                releaseMoby:
                    Desert7AAD0DeleteMoby(moby);
                    return;
                }
                value3 = M2C_FIELD(privateData, short*, 12);
                value2 = value3 * 20;
                value3 = 1024 - value2;
                value2 = 16384;
                sizeQuotient2 = value2 / value3;
                moby->size = (unsigned char)sizeQuotient2;
                if ((unsigned int)(sizeQuotient2 & 0xFF) >= 0x80U) {
                    moby->size = 0x7F;
                }
                if ((unsigned char)moby->size < 0x12U) {
                    moby->size = 0x12;
                }
                moby->colour.r = (unsigned char)(unsigned short)M2C_FIELD(privateData, short*, 0xC);
                moby->colour.g = (unsigned char)(unsigned short)M2C_FIELD(privateData, short*, 0xC);
                moby->colour.b = (unsigned char)(unsigned short)M2C_FIELD(privateData, short*, 0xC);
                break;
        }
    }
}
#undef M2C_FIELD


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Original SCUS-94467 assembly SHA256 e7e96cae5c66739263152b37e65283826bce1ef5051dd7bfdd7c76bb3abd5e13. Rev1 raw134 provides a structural crosswalk only. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))


int Desert7B1B4QueryWorldSegmentWithOptions() __asm__("func_8001830C");
void* Desert7B1B4QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int Desert7B1B4TestPlayerSphereOverlap() __asm__("func_8001C288");
int Desert7B1B4ApproximatePlanarDistance() __asm__("func_8004F334");
int Desert7B1B4DeleteMoby() __asm__("func_80055B18");
int Desert7B1B4RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern unsigned char Desert7B1B4_D_800658A0 __asm__("D_800658A0");
extern unsigned char Desert7B1B4_D_80065920 __asm__("D_80065920");
extern int Desert7B1B4_D_8006C550 __asm__("D_8006C550");
extern int Desert7B1B4_D_8006C574 __asm__("D_8006C574");
extern int Desert7B1B4_D_8006C578 __asm__("D_8006C578");
extern int Desert7B1B4_D_8006C640 __asm__("D_8006C640");
extern int Desert7B1B4_D_8006E020 __asm__("D_8006E020");
extern int Desert7B1B4_D_8006E024 __asm__("D_8006E024");
extern unsigned short Desert7B1B4_D_8006E040 __asm__("D_8006E040");
extern unsigned char Desert7B1B4_D_80070328 __asm__("D_80070328");

void func_level_42_8007B1B4(Moby* inputMoby) {
    /* Members retain the original stack offsets and retail integer units. */
    struct {
        int sp18;
        int sp1C;
        int sp20;
        char pad_24[4];
        int sp28;
        int sp2C;
        int sp30;
        char pad_34[4];
    } originalStack;

register Moby* moby __asm__("$17") = inputMoby;

    Moby* childMoby;
    register Vector3D* mobyPosition __asm__("$18");
    register int linkedIndex __asm__("$4");
    register int timerOrProduct4 __asm__("$4");
    register int product3 __asm__("$3");
    register int horizontalRange __asm__("$18");
    register int childCount __asm__("$19");
    register int verticalRange __asm__("$20");
    register int childDrawDistance __asm__("$21");
    register int vectorArgument __asm__("$4");
    register int zeroArgument6 __asm__("$6");
    register int test2 __asm__("$2");
    register int yawTest2 __asm__("$2");
    register int quotient2 __asm__("$2");
    register int pitchStep3 __asm__("$3");
    register int yawStep3 __asm__("$3");
    register int state __asm__("$3");
    register void* privateData __asm__("$22");
    void* contactMoby;

    MATCHING_KEEP(moby);
    state = moby->state;
    privateData = moby->mobyTag;
    switch (state) {
        case 0:
            MATCHING_KEEP(state);
            if (moby->drawn != 0) {
                moby->angle.roll += 0xF4;
                if ((func_8004F264((int)(Desert7B1B4_D_8006E040 << 0x10) >> 0x14,
                                   func_8004E880(moby->position.x - Desert7B1B4_D_8006E020,
                                                 moby->position.y - Desert7B1B4_D_8006E024, 0)) >=
                     0x1D) ||
                    (func_8004F264(
                         (int)moby->angle.yaw,
                         func_8004E880(
                             M2C_FIELD(&Desert7B1B4_D_80070328, int*, 0) - moby->position.x,
                             M2C_FIELD(&Desert7B1B4_D_80070328, int*, 4) - moby->position.y, 0)) >=
                     0x41)) {
                    M2C_FIELD(privateData, int*, 8) = 0;
                }
                test2 = M2C_FIELD(privateData, int*, 8);
                vectorArgument = (int)&originalStack.sp18;
                MATCHING_KEEP(vectorArgument);
                if (test2) {
                    test2 = Desert7B1B4_D_8006C640 & 1;
                    MATCHING_KEEP_VOLATILE_CLOBBER(test2, "$6");
                    zeroArgument6 = 0;
                    if (!test2)
                        goto steerYawReady;
                    {
                        pitchStep3 = func_8003613C(
                            (int)moby->angle.pitch,
                            func_8004E880(
                                Desert7B1B4ApproximatePlanarDistance(
                                    &moby->position, &Desert7B1B4_D_80070328, zeroArgument6),
                                M2C_FIELD(&Desert7B1B4_D_80070328, int*, 8) - moby->position.z, 0));
                        test2 = pitchStep3 < 2;
                        if (!test2) {
                            pitchStep3 = 1;
                            MATCHING_KEEP(pitchStep3);
                        }
                        test2 = pitchStep3 < -1;
                        if (test2 != 0) {
                            pitchStep3 = -1;
                        }
                        moby->angle.pitch += pitchStep3;
                    }
                    MATCHING_BARRIER_VOLATILE("$6");
                    zeroArgument6 = 0;
                steerYawReady:
                    yawStep3 = func_8003613C(
                        (int)moby->angle.yaw,
                        func_8004E880(
                            M2C_FIELD(&Desert7B1B4_D_80070328, int*, 0) - moby->position.x,
                            M2C_FIELD(&Desert7B1B4_D_80070328, int*, 4) - moby->position.y,
                            zeroArgument6));
                    yawTest2 = yawStep3 < 3;
                    if (!yawTest2) {
                        yawStep3 = 2;
                        MATCHING_KEEP(yawStep3);
                    }
                    yawTest2 = yawStep3 < -2;
                    if (yawTest2 != 0) {
                        yawStep3 = -2;
                    }
                    moby->angle.yaw += yawStep3;
                }
                vectorArgument = (int)&originalStack.sp18;
                MATCHING_KEEP(vectorArgument);
                mobyPosition = &moby->position;
                func_8004F178(vectorArgument, mobyPosition);
                originalStack.sp18 += func_800363DC(0, 0x96);
                originalStack.sp1C += func_800363DC(0, 0x96);
                originalStack.sp20 += func_800363DC(0, 0x96);
                originalStack.sp28 = func_800363DC(0, 0xA);
                originalStack.sp2C = func_800363DC(0, 0xA);
                originalStack.sp30 = func_8003636C(5, 8);
                SpawnParticle(1, 0x27, (Vector3D*)&originalStack.sp18,
                              (Vector3D*)&originalStack.sp28);
                func_8004F178(&originalStack.sp18, mobyPosition);
                originalStack.sp28 =
                    (int)(((int)(M2C_FIELD(&Desert7B1B4_D_80065920, short*, (moby->angle.yaw * 2)) *
                                 0xF) >>
                           8) *
                          M2C_FIELD(&Desert7B1B4_D_80065920, short*, (moby->angle.pitch * 2))) >>
                    0xC;
                originalStack.sp2C =
                    (int)(((int)(M2C_FIELD(&Desert7B1B4_D_800658A0, short*, (moby->angle.yaw * 2)) *
                                 0xF) >>
                           8) *
                          M2C_FIELD(&Desert7B1B4_D_80065920, short*, (moby->angle.pitch * 2))) >>
                    0xC;
                originalStack.sp30 =
                    (int)(M2C_FIELD(&Desert7B1B4_D_800658A0, short*, (moby->angle.pitch * 2)) *
                          0xF) >>
                    8;
                func_8004F194(mobyPosition, mobyPosition, (Vector3D*)&originalStack.sp28);
                contactMoby = Desert7B1B4QueryDynamicMobyGeometry(mobyPosition, 0x100, 3, 0, 1,
                                                                  Desert7B1B4_D_8006C550 +
                                                                      (moby->linkedMoby * 0x58));
                if (((contactMoby != 0) && (M2C_FIELD(contactMoby, short*, 0x36) == 0x213)) ||
                    (Desert7B1B4TestPlayerSphereOverlap(mobyPosition, 0xC8, 0) != 0)) {
                    linkedIndex = M2C_FIELD(privateData, int*, 0);
                    if (linkedIndex != -1) {
                        M2C_FIELD(((linkedIndex * 0x58) + Desert7B1B4_D_8006C550), signed char*,
                                  0x49) = 1;
                    }
                    goto setState1;
                }
                if ((moby->position.x < 0x400) || (moby->position.y < 0x400) ||
                    (moby->position.z < 0x400) || (func_800359A4(privateData + 4, 4) != 0)) {
                    Desert7B1B4RefreshMobySpatialGridAndBasis(moby, 4);
                    func_800369B8(moby, 0x30);
                    goto releaseMoby;
                }
                if (Desert7B1B4QueryWorldSegmentWithOptions(&originalStack.sp18, mobyPosition, 3, 0,
                                                            0) != 0) {
                setState1:
                    moby->state = 1;
                    return;
                }
            } else {
                goto releaseMoby;
            }
            break;
        case 1:
            func_8003BABC(moby, 0, 0);
            M2C_FIELD(privateData, int*, 4) = 0x28;
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            moby->state = 2;
            /* fallthrough */
        case 2:
            horizontalRange = 0x44C;
            timerOrProduct4 = M2C_FIELD(privateData, int*, 4);
            verticalRange = 0x384;
            if (timerOrProduct4 >= 0x15) {
                MATCHING_KEEP2_VOLATILE(horizontalRange, verticalRange);
                product3 = 40 - timerOrProduct4;
                timerOrProduct4 = product3 * horizontalRange;
                product3 *= verticalRange;
                quotient2 = timerOrProduct4 / 40;
                horizontalRange = quotient2 + 0x226;
                quotient2 = product3 / 40;
            } else {
                MATCHING_KEEP2_VOLATILE(horizontalRange, verticalRange);
                product3 = timerOrProduct4 * horizontalRange;
                timerOrProduct4 *= verticalRange;
                quotient2 = product3 / 40;
                horizontalRange = quotient2 + 0x226;
                quotient2 = timerOrProduct4 / 40;
            }
            verticalRange = quotient2 + 0x1C2;
            childCount = 0;
            childDrawDistance = 0x40;
        requestChild:
            if ((Desert7B1B4_D_8006C578 - Desert7B1B4_D_8006C574) >= 0x15) {
                childMoby = SpawnMoby(0x146, moby);
                if (childMoby != 0) {
                    childMoby->lowDrawDistance = childDrawDistance;
                    childMoby->highDrawDistance = childDrawDistance;
                    childMoby->position.x += func_800363DC(0, horizontalRange);
                    childMoby->position.y += func_800363DC(0, horizontalRange);
                    childMoby->position.z += func_800363DC(0, verticalRange);
                }
                childCount += 1;
                if (childCount < 2) {
                    goto requestChild;
                }
            }
            MATCHING_BARRIER_VOLATILE("memory");
            if (func_800359A4(privateData + 4, 4) != 0) {
                goto releaseMoby;
            }
            break;
    }
    return;
releaseMoby:
    Desert7B1B4DeleteMoby(moby);
}
#undef M2C_FIELD

void func_level_42_8007B864(Moby* moby) {
    func_80039714(moby);
}

typedef struct {
    unsigned char unk0, unk1;
    short offset;
    Moby* parent;
} DecodedFollowTag;
extern unsigned short D_8006E040, D_8006E03E;
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_42_8007B884(Moby* moby) {
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
int DecodedDialogueGateSound(Moby*, int, int) __asm__("func_8003BB10");
void func_level_42_8007B9D8(Moby* moby) {
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
                            ->substate = 1;
                    if (tag->targetIndex != -1)
                        DecodedDialogueGateTarget(tag->targetIndex, 0xFC, 0);
                    func_80055B18(moby);
                    break;
                }
            }
            if ((tag->linkedIndex != -1 || tag->targetIndex != -1) && tag->phase == 4) {
                DecodedDialogueGateSound(0, 3, 0);
                if (tag->linkedIndex != -1)
                    ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))
                        ->substate = 1;
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-derived C. Original source asm/nonmatchings/overlays/level_42/moby/func_level_42_8007BC30.s SHA256 3a31d73dc615e8cf9068fa65edcc9a8868ab8a2976e15c9b83f3355e77b15d67. Rev1 raw277 entry 0x8007BD10, 523 words, SHA256 7F8F22873645B2B0C8782B4FE3B3207BFEC341849765F496F6FD73D05D668F70; tools/yotd_re/playable_desert_raw277_source_frontier_runtime.py supplies source-local route evidence. Raw bytes/words and signed arithmetic follow each source; cadence per invocation only. Helpers, callback/global producers and consumers, assets and retail runtime verification remain unresolved. No whole-actor or runtime parity claim. Exact native/linked/full retail hashes required. */
#define DesertField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Desert277ConfigureHudEntry() __asm__("func_8002803C");              /* extern */
int Desert277CountListedMobysBelowState80() __asm__("func_800369D8");   /* extern */
int Desert277UpdateMobyInteractionGate() __asm__("func_80037BBC");      /* extern */
int Desert277ShiftVectorRightTowardZero() __asm__("func_8004F110");     /* extern */
int Desert277StartDialogue() __asm__("func_800512E4");                  /* extern */
int Desert277RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Desert277InterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
int Desert277_rand() __asm__("rand");                                   /* extern */
extern int Desert277_D_8006580C __asm__("D_8006580C");
extern int Desert277_D_80065834 __asm__("D_80065834");
extern unsigned char Desert277_D_800658A0 __asm__("D_800658A0");
extern unsigned char Desert277_D_80065920 __asm__("D_80065920");
extern int Desert277_D_8006C54C __asm__("D_8006C54C");
extern int Desert277_D_8006C550 __asm__("D_8006C550");
extern int Desert277_D_8006C58C __asm__("D_8006C58C");
extern int Desert277_D_8006C628 __asm__("D_8006C628");
extern int Desert277_D_8006C640 __asm__("D_8006C640");
extern int Desert277_D_8006C648 __asm__("D_8006C648");
extern int Desert277_D_8006C6C4 __asm__("D_8006C6C4");
extern int Desert277_D_8006C770 __asm__("D_8006C770");
extern unsigned char Desert277_D_8006C7B4 __asm__("D_8006C7B4");
extern Savepoint Desert277_D_8006C7F8 __asm__("D_8006C7F8");
extern Savepoint Desert277_D_8006D088 __asm__("D_8006D088");
extern int Desert277_D_8006E344 __asm__("D_8006E344");
extern int DesertLatchRead __asm__("D_80070328+0x254");
extern Vector3D Desert277_D_80070328 __asm__("D_80070328");
extern unsigned char Desert277_D_800716AC __asm__("D_800716AC");
extern unsigned char Desert277_func_80027A60 __asm__("func_80027A60");
extern unsigned char Desert277_func_80027EE4 __asm__("func_80027EE4");
extern unsigned char Desert277_func_80029AA0 __asm__("func_80029AA0");

void func_level_42_8007BC30(Moby* inputOwner) {
    struct {
        Vector3D sp20;
        char pad_2c[4];
        int sp30;
        int sp34;
        int sp38;
        char pad_3c[4];
        Vector3D sp40;
        char pad_4c[4];
        Vector3D sp50;
        char pad_5c[4];
    } frame;

    register Moby* owner __asm__("$20") = inputOwner;

    Vector3D* linkedVector2;
    register int counterIndex4 __asm__("$4");
    register int helperResult2 __asm__("$2");
    register int state10Timer2 __asm__("$2");
    register int state11Timer2 __asm__("$2");
    signed char* particle16;
    register int nextMode2 __asm__("$2");
    register int privateMode4 __asm__("$4");
    register int state3 __asm__("$3");
    register int counterByte3 __asm__("$3");
    register void* modeByte16 __asm__("$16");
    register void* record17 __asm__("$17");
    register void* privateData __asm__("$19");
    void* timer4;
    void* modeAddress4;
    register void* modeByte16Initial __asm__("$16");

    register int argument4 __asm__("$4");
    register int argument6 __asm__("$6");
    register int argument5 __asm__("$5");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register void* mode4 __asm__("$4");
    register void* vector17 __asm__("$17");
    register void* vector16 __asm__("$16");
    register void* vector18 __asm__("$18");
    MATCHING_KEEP(owner);
    mode4 = (char*)&Desert277_D_80070328 + 0x50;
    MATCHING_KEEP(mode4);
    privateData = owner->mobyTag;
    if (((unsigned int)(DesertField(mode4, unsigned int*, 0) - 0xB) < 2U) &&
        (DesertLatchRead == 0)) {
        DesertField(&Desert277_D_80070328, int*, 0x254) = 7;
        func_8004F178((Vector3D*)((char*)mode4 + 0x208),
                      DesertField(DesertField(privateData, void**, 0x54), Vector3D**, 0xC));
        DesertField(&Desert277_D_80070328, int*, 0x264) = 0x8800;
        DesertField(&Desert277_D_80070328, int*, 0x260) =
            (int)(DesertField(&Desert277_D_80070328, int*, 0x260) - 0x1400);
    } else if (((unsigned int)DesertField(&Desert277_D_80070328, unsigned int*, 0x50) < 2U) ||
               (DesertField(&Desert277_D_80070328, unsigned int*, 0x50) == 4) ||
               (DesertField(&Desert277_D_80070328, unsigned int*, 0x50) == 2)) {
        DesertField(&Desert277_D_80070328, int*, 0x254) = 0;
    }
    timer4 = privateData + 0x5C;
    if ((Desert277_D_8006C640 != 0) && (Desert277_D_8006C54C == 0)) {
        Desert277_D_8006580C = 1;
        Desert277_D_80065834 = 1;
        MATCHING_KEEP_VOLATILE_CLOBBER(privateData, "memory");
        timer4 = privateData + 0x5C;
    }
    if (func_800359A4(timer4, 4) != 0) {
        DesertField(privateData, int*, 0x60) = func_8003636C(0x14, 0x28);
        DesertField(privateData, int*, 0x5C) = func_8003636C(0x5A, 0xFA);
    }
    if (((func_800359A4(privateData + 0x60, 4) == 0) || (owner->animationState.nextId == 1)) &&
        (func_800359A4(privateData + 0x64, 4) != 0)) {
        frame.sp30 = Desert277_rand() & 7;
        frame.sp34 = Desert277_rand() & 7;
        frame.sp38 = func_8003636C(0xA, 0x14);
        Desert277RefreshMobySpatialGridAndBasis(owner, 4);
        argument4 = (int)owner;
        argument5 = 0;
        MATCHING_KEEP2(argument4, argument5);
        vector17 = &frame.sp40;
        Desert277InterpolateMobyVertex(argument4, argument5, vector17);
        argument4 = (int)owner;
        argument5 = 1;
        MATCHING_KEEP2(argument4, argument5);
        vector16 = &frame.sp50;
        Desert277InterpolateMobyVertex(argument4, argument5, vector16);
        func_8004F194(&frame.sp20, vector17, vector16);
        Desert277ShiftVectorRightTowardZero(&frame.sp20, 1);
        frame.sp20.x = frame.sp20.x + func_800363DC(0, 0x46);
        frame.sp20.y += func_800363DC(0, 0x46);
        particle16 = SpawnParticle(1, 0x27, &frame.sp20, (Vector3D*)&frame.sp30);
        DesertField(particle16, signed char*, 0xA) = func_8003636C(8, 0x10);
        DesertField(privateData, int*, 0x64) = func_8003636C(2, 8);
    }
    state3 = owner->state;
    switch (state3) { /* irregular */
        case 0:
            if (Desert277UpdateMobyInteractionGate(owner, 1) != 0) {
                Desert277StartDialogue(owner, 0, 1);
                owner->state = 1;
                return;
            }
            return;
        case 1:
            if (Desert277_D_8006E344 != state3) {
                privateMode4 = DesertField(privateData, unsigned char*, 4);
                if ((privateMode4 == state3) || (privateMode4 == 7) || (privateMode4 == 9)) {
                    vector16 = &frame.sp30;
                    func_8004F178(vector16, &Desert277_D_80070328);
                    frame.sp38 -= 0x17C;
                    func_8003B634(&Desert277_D_8006D088, vector16,
                                  (int)DesertField(&Desert277_D_80070328, unsigned char*, 0xE));
                    DesertField(&Desert277_D_80070328, int*, 0x20C) = 0x10000002;
                    DesertField(
                        ((DesertField(privateData, int*, 0x44) * 0x58) + (int)Desert277_D_8006C550),
                        signed char*, 0x48) = 0x14;
                    linkedVector2 =
                        DesertField(DesertField(privateData, void**, 0x48), Vector3D**, 0xC);
                    func_80013D44(
                        DesertField(DesertField(privateData, void**, 0x48), Vector3D**, 0xC),
                        func_8004E880(DesertField(linkedVector2, int*, 0x10) - linkedVector2->x,
                                      DesertField(linkedVector2, int*, 0x14) - linkedVector2->y, 0),
                        0, 0x29);
                    if (owner->animationState.nextId != 0) {
                        Desert277_D_8006C770 = 0;
                        owner->animationProgress = 0x72;
                        owner->animationState.nextId = 0;
                        owner->animationState.nextFrame = 0;
                        func_80035734(owner);
                    }
                    if (DesertField(privateData, unsigned char*, 4) != 9) {
                        helperResult2 = Desert277CountListedMobysBelowState80(0);
                        Desert277_D_8006C6C4 = helperResult2;
                        value2 = Desert277ConfigureHudEntry(
                            0x17, 0x1A4, &Desert277_func_80027EE4, &Desert277_func_80027A60,
                            &Desert277_func_80029AA0, &Desert277_D_8006C628, helperResult2);
                        value2 <<= 16;
                        value3 = Desert277_D_8006C58C;
                        __asm__("" : "=r"(value3) : "0"(value3), "r"(value2));
                        value2 >>= 16;
                        DesertField(privateData, int*, 0x50) = value2;
                        value2 = value3 * 3;
                        MATCHING_KEEP(value2);
                        counterIndex4 = value2 * 2;
                        counterByte3 = *(&Desert277_D_800716AC + 1 + counterIndex4);
                        if (counterByte3 < 0xFFU) {
                            *(&Desert277_D_800716AC + 1 + counterIndex4) =
                                (value2 = counterByte3 + 1);
                        }
                        owner->state = 0xA;
                        return;
                    }
                    owner->state = 0xB;
                    return;
                }
                owner->state = 0;
                func_80034F40(owner, 0);
                return;
            }
            break;
        case 10:
            Desert277_D_8006C628 = Desert277_D_8006C6C4 - Desert277CountListedMobysBelowState80(0);
            if (func_800359A4(privateData + 0x4C, 4) == 2) {
                value2 = Desert277CountListedMobysBelowState80(0);
                MATCHING_KEEP(value2);
                modeByte16Initial = privateData + 2;
                if (value2 != 0)
                    goto state10Nonzero;
                {
                    Desert277_D_8006C7B4 |= 2;
                    func_8004F178(&frame.sp40, &owner->position);
                    record17 = privateData + 5;
                    frame.sp40.z += 0x1F4;
                    frame.sp40.x =
                        frame.sp40.x +
                        ((int)(DesertField(&Desert277_D_80065920, short*, (owner->angle.yaw * 2)) *
                               0x27) >>
                         6);
                    frame.sp40.y +=
                        (int)(DesertField(&Desert277_D_800658A0, short*, (owner->angle.yaw * 2)) *
                              0x27) >>
                        6;
                    DesertField(privateData, signed char*, 5) = 2;
                    func_8003B7B4(record17, 1, &Desert277_D_8006D088);
                    func_8003B7B4(record17, 1, &Desert277_D_8006C7F8);
                    func_8003B634(&Desert277_D_8006D088, &frame.sp40, owner->angle.yaw + 0x80);
                }
                goto sharedFinish;
            state10Nonzero:
                modeAddress4 = modeByte16Initial;
                argument5 = 1;
                record17 = &Desert277_D_8006D088;
                __asm__("" : "=r"(record17) : "0"(record17), "r"(modeAddress4), "r"(argument5));
                argument6 = (int)record17;
                MATCHING_KEEP3(modeAddress4, argument5, argument6);
                nextMode2 = 3;
                goto writeModeAndRecords;
            }
            state10Timer2 = DesertField(privateData, int*, 0x58) + Desert277_D_8006C648;
            DesertField(privateData, int*, 0x58) = state10Timer2;
            if (state10Timer2 >= 0x3E9) {
                DesertField(privateData, int*, 0x58) = 0x3E8;
            }
            if ((DesertField(
                     ((DesertField(privateData, int*, 0x44) * 0x58) + (int)Desert277_D_8006C550),
                     unsigned char*, 0x49) != 0) ||
                ((DesertField(privateData, int*, 0x58) >= 0x5B) &&
                 (DesertField(&Desert277_D_80070328, int*, 0x48) != 0x26))) {
                DesertField(&Desert277_D_80070328, int*, 0x20C) =
                    (int)(DesertField(&Desert277_D_80070328, int*, 0x20C) | 0x10000002);
                if (DesertField(privateData, int*, 0x4C) == 0) {
                    DesertField(privateData, int*, 0x4C) = 0x3C;
                }
            }
            if (Desert277CountListedMobysBelowState80(0) != 0) {
                return;
            }
            goto seedTimerIfZero;
        case 11:
            value2 = func_800359A4(privateData + 0x4C, 4);
            MATCHING_KEEP(value2);
            modeByte16Initial = privateData + 2;
            if (value2 == 2) {
                modeAddress4 = modeByte16Initial;
                argument5 = 1;
                record17 = &Desert277_D_8006D088;
                __asm__("" : "=r"(record17) : "0"(record17), "r"(modeAddress4), "r"(argument5));
                argument6 = (int)record17;
                MATCHING_KEEP3(modeAddress4, argument5, argument6);
                nextMode2 = 5;
            writeModeAndRecords:
                DesertField(privateData, signed char*, 2) = nextMode2;
                func_8003B7B4(modeAddress4, argument5, argument6);
                argument4 = (int)modeByte16Initial;
                argument5 = 1;
                MATCHING_KEEP2(argument4, argument5);
                vector18 = &Desert277_D_8006C7F8;
                MATCHING_KEEP(vector18);
                func_8003B7B4(argument4, argument5, vector18);
                modeByte16 = privateData + 5;
                DesertField(privateData, signed char*, 5) = 2;
                func_8003B7B4(modeByte16, 1, record17);
                func_8003B7B4(modeByte16, 1, vector18);
            sharedFinish:
                func_8003B74C(&Desert277_D_8006D088);
                return;
            }
            state11Timer2 = DesertField(privateData, int*, 0x58) + Desert277_D_8006C648;
            DesertField(privateData, int*, 0x58) = state11Timer2;
            if (state11Timer2 >= 0x3E9) {
                DesertField(privateData, int*, 0x58) = 0x3E8;
            }
            if ((DesertField(
                     ((DesertField(privateData, int*, 0x44) * 0x58) + (int)Desert277_D_8006C550),
                     unsigned char*, 0x49) != 0) ||
                ((DesertField(privateData, int*, 0x58) >= 0x5B) &&
                 (DesertField(&Desert277_D_80070328, int*, 0x48) != 0x26))) {
                DesertField(&Desert277_D_80070328, int*, 0x20C) =
                    (int)(DesertField(&Desert277_D_80070328, int*, 0x20C) | 0x10000002);
            } else
                goto returnController;
        seedTimerIfZero:
            MATCHING_BARRIER_VOLATILE("memory");
            if (DesertField(privateData, int*, 0x4C) == 0)
                DesertField(privateData, int*, 0x4C) = 0x3C;
            break;
    }
returnController:;
}
#undef DesertField

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
void func_level_42_8007C45C(Moby* moby) {
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

extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_8007158A;
void func_level_42_8007C778(Moby* moby) {
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
    unsigned char reserved00[0x18];
    short timer, selector;
} DecodedControlledSpawnTag;
extern int D_8006C770, D_8006E048, D_8006E53C;
extern unsigned int DecodedControlledPlayerFlags __asm__("D_80070328 + 0x20C");
extern int DecodedControlledPlayerState __asm__("D_80070328 + 0x23C");
extern Moby* DecodedControlledPlayerActor __asm__("D_80070328 + 0x250");
int DecodedControlledTimer(void*, int) __asm__("func_800359A4");
void DecodedControlledUpdate(Moby*, void*, int) __asm__("func_80037168");
void func_level_42_8007C8C8(Moby* moby) {
    DecodedControlledSpawnTag* tag = moby->mobyTag;
    Moby* spawned;
    register unsigned int* playerFlags __asm__("$4");
    register unsigned int flagBits __asm__("$5");
    register unsigned int initialFlags __asm__("$3");
    register int cameraGate __asm__("$2");
    switch (moby->state) {
        case 0:
            if (moby->animationState.nextId != 0) {
                D_8006C770 = 0;
                moby->animationProgress = 0x72;
                moby->animationState.nextId = 0;
                moby->animationState.nextFrame = 0;
                func_80035734(moby);
            }
            DecodedControlledUpdate(moby, tag, 1);
            func_80055D24(moby, 1);
            break;
        case 0x14:
            initialFlags = 0x10000002;
            MATCHING_KEEP(initialFlags);
            moby->unknownCollision = 0;
            MATCHING_BARRIER("memory");
            cameraGate = D_8006E048;
            MATCHING_KEEP(cameraGate);
            playerFlags = &DecodedControlledPlayerFlags;
            MATCHING_KEEP(playerFlags);
            *playerFlags = initialFlags;
            if (cameraGate & 1) {
                *playerFlags = 0x10000082;
                DecodedControlledPlayerState = 0x26;
                DecodedControlledPlayerActor = moby;
                moby->state = 1;
                moby->unknownCollision = 0;
            }
            break;
        case 1:
            if (moby->animationState.nextId != 1) {
                D_8006C770 = 0;
                moby->animationProgress = 0x72;
                moby->animationState.nextId = 1;
                moby->animationState.nextFrame = 0;
                func_80035734(moby);
            }
            if (moby->substate) {
                flagBits = 0x10000080;
                MATCHING_KEEP(flagBits);
                playerFlags = &DecodedControlledPlayerFlags;
                MATCHING_KEEP(playerFlags);
                cameraGate = *playerFlags;
                MATCHING_KEEP_CLOBBER(cameraGate, "memory");
                DecodedControlledPlayerState = 0x29;
                MATCHING_KEEP_CLOBBER(cameraGate, "memory");
                *playerFlags = cameraGate | flagBits;
                moby->state = 0;
                return;
            }
            moby->unknownCollision = 0;
            if (DecodedControlledTimer(&tag->timer, 2) && (D_8006E53C & 0x20)) {
                spawned = SpawnMoby(0x83, moby);
                if (spawned) {
                    func_80055D24(moby, 4);
                    func_80055F14(moby, tag->selector, &spawned->position);
                    tag->timer = 0x14;
                    tag->selector = tag->selector == 0;
                }
            }
            break;
    }
    moby->damageFlags = 0;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Controller7CACCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller7CACCCountListedMobysBelowState80() __asm__("func_800369D8");   /* extern */
int Controller7CACCDeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7CACCRefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7CACCInterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
int Controller7CACC_rand() __asm__("rand");                                   /* extern */
extern unsigned char Controller7CACC_D_80066BC8 __asm__("D_80066BC8");
extern int Controller7CACC_D_8006C574 __asm__("D_8006C574");
extern int Controller7CACC_D_8006C578 __asm__("D_8006C578");
extern int Controller7CACC_D_8006EE2C __asm__("D_8006EE2C");
extern short Controller7CACC_D_800719DC __asm__("D_800719DC");

void func_level_42_8007CACC(Moby* incomingMoby) {
    struct {
        Vector3D sp10;
        char pad_1c[4];
        int sp20;
        int sp24;
        int sp28;
        char pad_2c[4];
    } frame;

    register Moby* moby __asm__("$18") = incomingMoby;

    register Moby* child16 __asm__("$16");
    register Moby* loopChild16 __asm__("$16");
    register Moby* linkedChild16 __asm__("$16");
    register Moby* linkedChild4 __asm__("$4");
    register int frameCount19 __asm__("$19");
    register int animationId4 __asm__("$4");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register void* pointer3 __asm__("$3");
    register int remainder3 __asm__("$3");
    register int childRemainder3 __asm__("$3");
    register int remaining17 __asm__("$17");
    register int attempt19 __asm__("$19");
    unsigned char animationRun4;
    register int substate16 __asm__("$16");
    register void* tag17 __asm__("$17");
    void* linkedTag;

    MATCHING_KEEP(moby);
    if (moby->substate == 0x63) {
        moby->damageFlags =
            Controller7CACCField(Controller7CACCField(moby->mobyTag, void**, 0), int*, 0x18);
    }
    if (moby->substate == 0) {
        value2 = *Controller7CACCField(
            ((moby->animationState.id * 4) +
             Controller7CACCField(&Controller7CACC_D_8006EE2C, int*, moby->mobyClass * 4)),
            unsigned char**, 0x3C);
        MATCHING_KEEP(value2);
        frameCount19 = value2 - 1;
        moby->angle.yaw = Controller7CACC_rand();
        moby->size = (Controller7CACC_rand() & 7) + 0x1C;
        remainder3 = Controller7CACC_rand() % frameCount19;
        moby->animationProgress = 0x30;
        value2 = remainder3 + 1;
        MATCHING_KEEP(value2);
        moby->animationState.frame = remainder3;
        moby->animationState.nextFrame = value2;
        remaining17 = (Controller7CACC_rand() & 1) + 1;
        if (remaining17 > 0) {
            do {
                child16 = SpawnMoby((int)moby->mobyClass, moby);
                MATCHING_KEEP(child16);
                if (child16 != 0) {
                    value2 = 99;
                    MATCHING_KEEP(value2);
                    pointer3 = child16->mobyTag;
                    MATCHING_KEEP(pointer3);
                    child16->substate = value2;
                    Controller7CACCField(pointer3, Moby**, 0) = moby;
                    child16->angle.yaw = Controller7CACC_rand();
                    child16->size = (Controller7CACC_rand() & 7) + 0x1C;
                    child16->unknownCollision = 0;
                    child16->lowDrawDistance = 0x20;
                    childRemainder3 = Controller7CACC_rand() % frameCount19;
                    child16->animationProgress = 0x30;
                    value2 = childRemainder3 + 1;
                    MATCHING_KEEP(value2);
                    child16->animationState.frame = childRemainder3;
                    child16->animationState.nextFrame = value2;
                }
                remaining17 -= 1;
            } while (remaining17 > 0);
        }
        moby->substate = 1;
    }
    if (moby->damageFlags & 0x100000) {
        value2 = Controller7CACC_rand() & ((unsigned char)moby->size >> 4);
        MATCHING_KEEP(value2);
        __asm__ __volatile__("" : "=r"(attempt19));
        attempt19 = 0;
        if (!value2) {
            MATCHING_KEEP_GNU_VOLATILE(attempt19);
            func_8004F178(&frame.sp10, &moby->position);
            frame.sp10.x += func_8003636C(0, 0xBB8);
            frame.sp10.y += func_8003636C(0, 0xBB8);
            frame.sp10.z += func_8003636C(0, 0xBB8);
            frame.sp20 = Controller7CACC_rand() & 3;
            frame.sp24 = Controller7CACC_rand() & 3;
            frame.sp28 = func_8003636C(0xA, 0xF);
            SpawnParticle(1, 0x27, &frame.sp10, (Vector3D*)&frame.sp20);
            __asm__ __volatile__("" : "=r"(attempt19));
            attempt19 = 0;
        }
    spawnLoop:
        if ((Controller7CACC_D_8006C578 - Controller7CACC_D_8006C574) >= 0x15) {
            loopChild16 = SpawnMoby(0x23A, moby);
            MATCHING_KEEP(loopChild16);
            if (loopChild16 != 0) {
                tag17 = loopChild16->mobyTag;
                value2 = func_8003636C(0, 2);
                value3 = loopChild16->animationState.id;
                MATCHING_KEEP(value3);
                animationId4 = value2;
                MATCHING_KEEP(animationId4);
                if (value3 != animationId4) {
                    loopChild16->unknown3[1] = 0;
                    value2 = -((unsigned char)*Controller7CACCField(
                                   ((animationId4 * 4) +
                                    Controller7CACCField(&Controller7CACC_D_8006EE2C, int*,
                                                         loopChild16->mobyClass * 4)),
                                   unsigned char**, 0x3C) >= 2U) &
                             0x30;
                    MATCHING_KEEP(value2);
                    loopChild16->animationState.id = (unsigned char)animationId4;
                    loopChild16->animationState.nextId = (unsigned char)animationId4;
                    loopChild16->animationState.frame = 0;
                    loopChild16->animationState.nextFrame = 1;
                    loopChild16->animationProgress = value2;
                }
                Controller7CACCRefreshMobySpatialGridAndBasis(moby, 4);
                Controller7CACCInterpolateMobyVertex(moby, attempt19, &loopChild16->position);
                Controller7CACCField(tag17, short*, 0) = func_800363DC(0, 0x50);
                Controller7CACCField(tag17, short*, 2) = func_800363DC(0, 0x50);
                Controller7CACCField(tag17, short*, 4) = func_8003636C(0, 0x1E);
                Controller7CACCField(tag17, short*, 0x12) = 3;
                Controller7CACCField(tag17, short*, 0xE) = 0x1E;
                Controller7CACCField(tag17, short*, 0xC) = (short)(func_8003636C(0, 0x3C) + 0x5A);
                Controller7CACCField(tag17, short*, 6) = func_800363DC(0, 0xA);
                Controller7CACCField(tag17, short*, 8) = func_800363DC(0, 0xA);
                Controller7CACCField(tag17, short*, 0xA) = func_800363DC(0, 0xA);
            }
            attempt19 += 1;
            if (attempt19 < 5) {
                goto spawnLoop;
            }
        }
        substate16 = moby->substate;
        if (substate16 == 1) {
            animationRun4 = moby->animationRun;
            if ((animationRun4 != 0xFF) &&
                !(Controller7CACCField(&Controller7CACC_D_80066BC8, unsigned char*, 0xF) & 1) &&
                (Controller7CACCCountListedMobysBelowState80(animationRun4) == substate16)) {
                Controller7CACCField(&Controller7CACC_D_80066BC8, unsigned char*, 0xF) = 3U;
                Controller7CACC_D_800719DC = 1;
                PlaySound((int)D_8006C654->skillPoint, moby, 0xA1);
                linkedChild16 = SpawnMoby(0xD3, moby);
                MATCHING_KEEP(linkedChild16);
                if (linkedChild16 != 0) {
                    linkedChild4 = SpawnMoby(0xAA, linkedChild16);
                    MATCHING_KEEP(linkedChild4);
                    if (linkedChild4 != 0) {
                        value2 = 1;
                        MATCHING_KEEP(value2);
                        pointer3 = linkedChild4->mobyTag;
                        MATCHING_KEEP(pointer3);
                        linkedTag = pointer3;
                        Controller7CACCField(linkedTag, signed char*, 0) = value2;
                        Controller7CACCField(linkedTag, unsigned char*, 1) = 0xD3;
                        Controller7CACCField(linkedTag, short*, 2) = 0x46;
                        Controller7CACCField(linkedTag, Moby**, 4) = linkedChild16;
                        linkedChild4->size = 0xF;
                    }
                }
            }
        }
        if (moby->substate != 0x63) {
            func_8003BA00(moby);
        }
        Controller7CACCDeleteMoby(moby);
    }
}
#undef Controller7CACCField

extern void (*DecodedOverlayCallback)(Moby*, int, Vector3D*, Vector3D*, int,
                                      int) __asm__("unk_ovlheader_800743EC");
void func_level_42_8007CFC8(Moby* moby) {
    int* tag = moby->mobyTag;
    if (moby->damageFlags & 0x100000) {
        func_8003BABC(moby, 0, 0);
        moby->state = 1;
    }
    switch (moby->state) {
        case 0:
            DecodedOverlayCallback(moby, tag[0], (Vector3D*)(tag + 6), (Vector3D*)(tag + 9), 6, 0);
            break;
        case 1:
            SpawnFragments(3, 0x1BC, moby, tag[5], 0, 0x100);
            func_8003BA00(moby);
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Controller7D0A8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

extern Moby* ActorPointer250 __asm__("D_80070328+0x250");
int Controller7D0A8ShiftVectorRightTowardZero() __asm__("func_8004F110");     /* extern */
int Controller7D0A8ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller7D0A8DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7D0A8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7D0A8InterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
extern int Controller7D0A8_D_8006C550 __asm__("D_8006C550");
extern int Controller7D0A8_D_8006C770 __asm__("D_8006C770");
extern int Controller7D0A8_D_8006E020 __asm__("D_8006E020");
extern int Controller7D0A8_D_8006E024 __asm__("D_8006E024");
extern unsigned short Controller7D0A8_D_8006E040 __asm__("D_8006E040");
extern unsigned char Controller7D0A8_D_80070328 __asm__("D_80070328");

void func_level_42_8007D0A8(Moby* incomingMoby) {
    register Moby* moby __asm__("$19") = incomingMoby;
    struct {
        Vector3D sp10;
        int pad10;
        Vector3D sp20;
        int pad20;
        Vector3D sp30;
        int pad30;
        Vector3D sp40;
        int pad40;
        Vector3D sp50;
        int pad50;
        Vector3D sp60;
        int pad60;
    } frame;
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int call7 __asm__("$7");
    register Moby* linkedMoby18 __asm__("$18");
    register Moby* child17 __asm__("$17");
    register Vector3D* position16 __asm__("$16");
    register Vector3D* position16Again __asm__("$16");
    int linkedIndex;
    register int headingDifference21 __asm__("$21");
    int var_v0;
    int var_v0_2;
    int var_v0_3;
    register int predicate2 __asm__("$2");
    register int signedResult3 __asm__("$3");
    register void* childTag16 __asm__("$16");
    register void* vector17 __asm__("$17");
    register void* globalPointer18 __asm__("$18");
    register void* tag20 __asm__("$20");

    MATCHING_KEEP(moby);
    tag20 = moby->mobyTag;
    linkedIndex = Controller7D0A8Field(tag20, int*, 0);
    if (linkedIndex != -1) {
        if (moby->state != 5) {
            call5 = 4;
            MATCHING_KEEP(call5);
            value2 = linkedIndex * 11;
            value3 = Controller7D0A8_D_8006C550;
            __asm__("" : "=r"(value3) : "0"(value3), "r"(value2));
            value2 <<= 3;
            linkedMoby18 = (Moby*)(value3 + value2);
            Controller7D0A8RefreshMobySpatialGridAndBasis(linkedMoby18, call5);
            Controller7D0A8InterpolateMobyVertex(linkedMoby18, 0xE, &frame.sp10);
            Controller7D0A8InterpolateMobyVertex(linkedMoby18, 0xF, &frame.sp20);
            position16 = &moby->position;
            func_8004F194(position16, &frame.sp10, &frame.sp20);
            Controller7D0A8ShiftVectorRightTowardZero(position16, 1);
            moby->angle.yaw = linkedMoby18->angle.yaw + 0x80;
            moby->angle.pitch = (unsigned char)-(int)linkedMoby18->angle.pitch;
            if ((unsigned char)linkedMoby18->state >= 0x80U) {
                call7 = 5;
                value3 = linkedMoby18->unkb;
                moby->damageFlags = 0x100000;
                moby->unkb = value3;
                func_80038BF8(moby, tag20 + 8, 6, call7);
                value2 = 8;
                Controller7D0A8Field(tag20, unsigned char*, 0x16) = value2;
                MATCHING_BARRIER("memory");
                value2 = 0x96;
                Controller7D0A8Field(tag20, unsigned char*, 0x1E) = value2;
                Controller7D0A8Field(tag20, unsigned short*, 0xC) =
                    (unsigned short)(Controller7D0A8Field(tag20, unsigned short*, 0xC) + 0xAA);
                Controller7D0A8Field(tag20, unsigned short*, 0xE) =
                    (unsigned short)(Controller7D0A8Field(tag20, unsigned short*, 0xE) + 0x50);
                moby->unknownCollision = 0;
            }
        }
    }
    switch (moby->state) {
        case 0:
            headingDifference21 = func_8004F264(
                (int)moby->angle.yaw,
                func_8004E880(
                    Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 0) - moby->position.x,
                    Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 4) - moby->position.y,
                    0));
            if ((headingDifference21 >= 0x31) && (Controller7D0A8Field(tag20, int*, 4) < 0x1E)) {
                Controller7D0A8Field(tag20, int*, 4) = 0x1E;
            }
            globalPointer18 = &Controller7D0A8_D_80070328 + 0x250;
            MATCHING_KEEP(globalPointer18);
            if ((Controller7D0A8Field(globalPointer18, void**, 0) != 0) &&
                (Controller7D0A8Field(ActorPointer250, short*, 0x36) == 0x213) &&
                (func_800359A4(tag20 + 4, 4) != 0) &&
                (((func_8004F264((int)(Controller7D0A8_D_8006E040 << 0x10) >> 0x14,
                                 func_8004E880(moby->position.x - Controller7D0A8_D_8006E020,
                                               moby->position.y - Controller7D0A8_D_8006E024, 0)) <
                   0xC) != 0)) &&
                (position16Again = &moby->position, ({
                     MATCHING_KEEP(position16Again);
                     call4 = (int)position16Again;
                     MATCHING_KEEP2(call4, globalPointer18);
                     0;
                 }),
                 vector17 = globalPointer18 - 0x250,
                 ((({
                       value2 = Controller7D0A8ApproximatePlanarDistance(call4, vector17);
                       __asm__("" : "=r"(position16Again) : "0"(position16Again), "r"(value2));
                       value2;
                   }) > 0x9FFF) == 0)) &&
                (Controller7D0A8ApproximatePlanarDistance(position16Again, vector17) >= 0x1801)) {
                var_v0 = ((moby->position.z - moby->distanceToGround) -
                          Controller7D0A8Field(globalPointer18, int*, -0x248)) +
                         Controller7D0A8Field(globalPointer18, int*, -0x20C);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < 0x1400) && ((value2 = headingDifference21 < 40), ({
                                              MATCHING_KEEP(value2);
                                              value2;
                                          }))) {
                    moby->state = 1;
                    func_80034F40(moby, 1);
                    return;
                }
            } else {
                default:
                    return;
            }
            break;
        case 1:
            if (func_8004F264((int)(Controller7D0A8_D_8006E040 << 0x10) >> 0x14,
                              func_8004E880(moby->position.x - Controller7D0A8_D_8006E020,
                                            moby->position.y - Controller7D0A8_D_8006E024, 0)) <
                0x1B) {
                var_v0_2 = ((moby->position.z - moby->distanceToGround) -
                            Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 8)) +
                           Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 0x44);
                if (var_v0_2 < 0) {
                    var_v0_2 = -var_v0_2;
                }
                if (var_v0_2 < 0x1C01) {
                    MATCHING_BARRIER("$4");
                    value2 = Controller7D0A8_D_8006C770;
                    if (value2) {
                        func_8003BABC(moby, 0, 0);
                        Controller7D0A8Field(tag20, int*, 4) = 0x28;
                        moby->state = 2;
                        func_80034F40(moby, 2);
                        return;
                    }
                } else {
                block_40:
                    goto block_41;
                }
            } else {
                call4 = (int)moby;
                goto cleanupReady;
            }
            break;
        case 2:
            if (func_8004F264((int)(Controller7D0A8_D_8006E040 << 0x10) >> 0x14,
                              func_8004E880(moby->position.x - Controller7D0A8_D_8006E020,
                                            moby->position.y - Controller7D0A8_D_8006E024, 0)) <
                0x1B) {
                var_v0_3 = ((moby->position.z - moby->distanceToGround) -
                            Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 8)) +
                           Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 0x44);
                if (var_v0_3 < 0) {
                    var_v0_3 = -var_v0_3;
                }
                if (var_v0_3 < 0x1C01) {
                    if (func_800359A4(tag20 + 4, 4) != 0) {
                        child17 = SpawnMoby(0x86, moby);
                        call4 = (int)moby;
                        if (child17 != 0) {
                            MATCHING_KEEP(child17);
                            childTag16 = child17->mobyTag;
                            Controller7D0A8RefreshMobySpatialGridAndBasis(call4, 4);
                            Controller7D0A8InterpolateMobyVertex(moby, 0, &child17->position);
                            func_8003BABC(moby, 1, 1);
                            child17->lowDrawDistance = 0x50;
                            child17->highDrawDistance = 0x50;
                            Controller7D0A8Field(childTag16, int*, 4) = 0xB4;
                            Controller7D0A8Field(childTag16, int*, 8) = 1;
                            Controller7D0A8Field(childTag16, int*, 0) =
                                (int)Controller7D0A8Field(tag20, int*, 0x20);
                            child17->angle.yaw = moby->angle.yaw;
                            signedResult3 = func_8003613C(
                                (int)moby->angle.yaw,
                                func_8004E880(
                                    Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 0) -
                                        moby->position.x,
                                    Controller7D0A8Field(&Controller7D0A8_D_80070328, int*, 4) -
                                        moby->position.y,
                                    0));
                            value2 = signedResult3 < 2;
                            if (value2) {
                                predicate2 = signedResult3 < -1;
                            } else {
                                signedResult3 = 1;
                                MATCHING_KEEP(signedResult3);
                                predicate2 = signedResult3 < -1;
                            }
                            if (predicate2 != 0) {
                                signedResult3 = -1;
                            }
                            child17->angle.yaw += signedResult3 * 0x10;
                        }
                        moby->state = 3;
                        func_80034F40(moby, 3);
                        return;
                    }
                } else {
                    goto block_40;
                }
            } else {
                call4 = (int)moby;
                goto cleanupReady;
            }
            break;
        case 3:
            if (Controller7D0A8_D_8006C770 != 0) {
            block_41:
                MATCHING_BARRIER("$4");
                call4 = (int)moby;
            cleanupReady:
                Controller7D0A8Field(tag20, int*, 4) = 120;
                ((Moby*)call4)->state = 0;
                func_80034F40((Moby*)call4, 0);
                return;
            }
            break;
        case 5:
            Controller7D0A8RefreshMobySpatialGridAndBasis(moby, 4);
            Controller7D0A8InterpolateMobyVertex(moby, 1, &frame.sp50);
            Controller7D0A8InterpolateMobyVertex(moby, 2, &frame.sp60);
            func_8004F194(&frame.sp30, &frame.sp50, &frame.sp60);
            Controller7D0A8ShiftVectorRightTowardZero(&frame.sp30, 1);
            frame.sp40.x = func_800363DC(0, 0xA);
            frame.sp40.y = func_800363DC(0, 0xA);
            frame.sp40.z = func_8003636C(5, 8);
            SpawnParticle(1, 0x27, &frame.sp30, (Vector3D*)&frame.sp40.x);
            if (func_80035194(moby, tag20 + 8) == 0x100) {
                Controller7D0A8RefreshMobySpatialGridAndBasis(moby, 4);
                func_8003BA00(moby);
                func_800369B8(moby, 0x20);
                Controller7D0A8DeleteMoby(moby);
            }
            break;
    }
}
#undef Controller7D0A8Field

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
void func_level_42_8007D724(Moby* actor) {
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

int ControllerA4E4SetCameraOwnerAndControlWord(Moby*, int) __asm__("func_80013ACC");
#define ControllerA4E4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char ControllerA4E4Player[] __asm__("D_80070328");
extern int D_8006C3F4, D_8006C4F8, D_8006C598, D_8006C640, D_8006C648, D_8006C6D0, D_8006C6E0,
    D_8006E344;
extern unsigned char D_80071592;
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
int ControllerA4E4RestoreOrClearTrackedSnapshot(void*) __asm__("func_8003B74C");
int ControllerA4E4RegisterTrackedValue(unsigned char*, int, void*) __asm__("func_8003B7B4");
int ControllerA4E4StartDialogue(Moby*, int, int) __asm__("func_800512E4");
int ControllerA4E4CopyCameraPositionWithWrappedAngle(void*, void*, int) __asm__("func_800135A4");
int ControllerA4E4ConfigurePrimaryRangeRequest(int, int, int) __asm__("func_8004F984");
/* AI-generated; not human reviewed. Reuses verified level11 A4E4 C.
 * Original level42 flag byte D_80071592 and helper call 13ACC(owner,15)
 * after the second camera-copy helper are preserved. Raw field units,
 * helper meanings and cadence remain unresolved. */
void func_level_42_8007D9D0(Moby* moby) {
    register Moby* owner __asm__("$18") = moby;
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
        ControllerA4E4ConfigurePrimaryRangeRequest(
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
                    ControllerA4E4RegisterTrackedValue(statePointer0, 1, &ControllerA4E4Control0);
                    ControllerA4E4RegisterTrackedValue(statePointer0, 1, &ControllerA4E4Control1);
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
                    ControllerA4E4StartDialogue(owner, 0, 0xF);
                    owner->state = 0xF;
                }
            }
            break;
        case 15:
            if (D_8006E344 != 1) {
                ControllerA4E4Field(ControllerA4E4Player, int*, 0x20C) = 0x10000002;
                D_80071592 = 1;
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
                ControllerA4E4RegisterTrackedValue(statePointer1, 1, &ControllerA4E4Control0);
                ControllerA4E4RegisterTrackedValue(statePointer1, 1, &ControllerA4E4Control1);
                ControllerA4E4RestoreOrClearTrackedSnapshot(&ControllerA4E4Control0);
                owner->state = 1;
            }
            break;
        case 3:
            ControllerA4E4Header(owner, 0x41);
            D_8006C6D0 = 0;
            ControllerA4E4CopyCameraPositionWithWrappedAngle(&ControllerA4E4Camera0,
                                                             &ControllerA4E4CameraSource0, 0);
            ControllerA4E4CopyCameraPositionWithWrappedAngle(&ControllerA4E4Camera1,
                                                             &ControllerA4E4CameraSource1, 0);
            ControllerA4E4SetCameraOwnerAndControlWord(owner, 15);
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

typedef struct {
    unsigned char reserved00[0x18];
    int threshold;
} DecodedSpawnThreshold;
extern int D_8006C578, D_8006C574, D_8006C770, D_8006C640;
int rand(void);
void func_80055B18(Moby*);
int func_80055E84(Moby*);
void func_level_42_8007DE10(Moby* actor) {
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

extern unsigned char D_8006C7B4;
extern int D_8006C58C, D_8006E344;
extern int ControllerA918NormalX __asm__("D_80071918");
extern int ControllerA918NormalY __asm__("D_8007191C");
extern int ControllerA918NormalZ __asm__("D_80071920");
extern unsigned char ControllerA918Saved[] __asm__("D_80070300");
extern unsigned char ControllerA918Table[] __asm__("D_80066650");
extern unsigned char* ControllerA918Output __asm__("D_8006C530");
extern Moby* ControllerA918Hit __asm__("D_80071930");
int ControllerA918QueryWorldSegment(Vector3D*, Vector3D*) __asm__("func_80018368");
void ControllerA918TransformVectorByBasis(SHORTMATRIX*, Vector3D*,
                                          Vector3D*) __asm__("func_8004ED6C");
void ControllerA918SubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void ControllerA918MultiplyVectorGpfSf0(Vector3D*, Vector3D*, int) __asm__("func_8004F1FC");
void ControllerA918ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
int ControllerA918Absolute12BitAngleDelta(int, int) __asm__("func_8004F284");
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
void func_level_42_8007DFCC(Moby* moby) {
    register Moby* owner __asm__("$18") = moby;
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
                ControllerA918TransformVectorByBasis(
                    &owner->rotationMatrix, (Vector3D*)(ControllerA918Table + byteOffset), scratch);
                func_8004F194(scratch, scratch, &owner->position);
                ControllerA918SubtractVector(scratch, scratch, &origin);
                {
                    register Vector3D* first __asm__("$4") = scratch;
                    register Vector3D* second __asm__("$5") = scratch;
                    MATCHING_KEEP2(first, second);
                    ControllerA918MultiplyVectorGpfSf0(first, second, *phase);
                }
                pointIndex += 1;
                ControllerA918ShiftVectorRightTowardZero(scratch, 8);
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
                    if ((ControllerA918QueryWorldSegment((Vector3D*)playerField, scratch) != 0) &&
                        (ControllerA918Hit == owner) &&
                        ((unsigned int)(ControllerA918NormalZ + 0x28) < 0x51U) &&
                        ((unsigned int)(ControllerA918Absolute12BitAngleDelta(
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

/* This caller only reads the signed halfword at tag +0xC. */
typedef struct {
    unsigned char reserved00[0xC];
    short unkC;
} DecodedCloneTag;
extern int D_8006C578, D_8006C574;
void func_level_42_8007E3D8(Moby* moby) {
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
void func_level_42_8007E4B0(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level42:
 * 8007E784 complete246 original instructions captured in sibling4412.
 * Verified11 routine establishes overlapping helper argument shapes only.
 * Raw offsets/branches/constants, unresolved units and semantic contracts.
 * Acceptance: original native/internal targets, linked words, every hash. */
#define Actor42Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Actor42Flags __asm__("D_8006C7B4");
extern unsigned char Actor42Levels[] __asm__("D_80070300");
extern int Actor42Level __asm__("D_8006C58C");
extern int Actor42Mode __asm__("D_8006E344");
extern unsigned char* Actor42Pool __asm__("D_8006C550");
extern int Actor42PlayerFlags __asm__("D_80070328 + 0x20C");
int Actor42UpdateMobyInteractionGate() __asm__("func_80037BBC");
int Actor42StartDialogue() __asm__("func_800512E4");
int Actor42UpdateMobyPathMotion() __asm__("func_80035A80");
int Actor42CountTimerDown() __asm__("func_800359A4");
int Actor42ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor42RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor42RequestMobyAnimation() __asm__("func_80034F40");
int Actor42DeleteMoby() __asm__("func_80055B18");
int Actor42TransitionCameraModes9And10() __asm__("func_80013B7C");
int Actor42PrepareCameraMode9Vectors() __asm__("func_80013AE4");
int Actor42SetClampedPlayerTargetAngles() __asm__("func_800492DC");
extern void* (*Actor42SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_42_8007E784(void* input) {
    register unsigned char* owner __asm__("$16") = input;
    register int stateByte __asm__("$17");
    register unsigned char* tag __asm__("$18");
    register int one __asm__("$4");
    register int work2 __asm__("$2");
    unsigned char substate;
    MATCHING_KEEP(owner);
    one = 1;
    MATCHING_KEEP(one);
    stateByte = ((Moby*)owner)->state;
    tag = Actor42Field(owner, unsigned char**, 0);
    switch (stateByte) {
        case 0:
            MATCHING_KEEP(stateByte);
            substate = ((Moby*)owner)->substate;
            switch (substate) {
                case 0:
                    if ((Actor42Flags & 1) || (Actor42Levels[Actor42Level] & 1))
                        goto remove;
                    ((Moby*)owner)->unknown3[0] = 0;
                    ((Moby*)owner)->lowDrawDistance = 0;
                    ((Moby*)owner)->drawn = 0;
                    Actor42Field(owner, int*, 8) = 0;
                    return;
                case 1:
                    Actor42RefreshMobySpatialGridAndBasis(owner, 7);
                    if (Actor42UpdateMobyInteractionGate(owner, 0)) {
                        Actor42Flags |= 1;
                        Actor42StartDialogue(owner, 0, 1);
                        ((Moby*)owner)->state = 1;
                    }
                    return;
                case 2:
                    Actor42RefreshMobySpatialGridAndBasis(owner, 7);
                    if (Actor42CountTimerDown(tag + 0x24, 4)) {
                        ((Moby*)owner)->substate = 1;
                        ((Moby*)owner)->state = 2;
                        Actor42RequestMobyAnimation(owner, 2);
                    }
                    goto player;
                case 3:
                    ((Moby*)owner)->unknown3[0] = 1;
                    ((Moby*)owner)->lowDrawDistance = 64;
                    ((Moby*)owner)->drawn = 1;
                    Actor42RefreshMobySpatialGridAndBasis(owner, 7);
                    if (Actor42CountTimerDown(tag + 0x24, 4)) {
                        ((Moby*)owner)->state = 2;
                        Actor42RequestMobyAnimation(owner, 2);
                    }
                    return;
            }
            return;
        case 1:
            Actor42RefreshMobySpatialGridAndBasis(owner, 7);
            if (Actor42Mode != stateByte) {
                Actor42Field(Actor42Field(tag, void**, 0x28), short*, 10) = 1;
                Actor42Field(Actor42Field(tag, void**, 0x28), short*, 2) = 0;
                Actor42Field(tag, int*, 0x24) = 60;
                ((Moby*)owner)->substate = 2;
                ((Moby*)owner)->state = 0;
            }
            return;
        case 2:
            MATCHING_KEEP(stateByte);
            Actor42RefreshMobySpatialGridAndBasis(owner, 7);
            if (Actor42Field(tag, int*, 0x30) >= 0 &&
                Actor42ApproximatePlanarDistance(
                    owner + 12, Actor42Pool + Actor42Field(tag, int*, 0x30) * 88 + 12) < 512)
                Actor42SpawnParticle(2, 12, Actor42Pool + Actor42Field(tag, int*, 0x30) * 88,
                                     (void*)5);
            substate = ((Moby*)owner)->substate;
            if (substate == 1)
                goto first;
            if (substate == 3)
                goto third;
            return;
        first:
            if (!(Actor42UpdateMobyPathMotion(owner, Actor42Field(tag, void**, 0x28), 512, 128, 0,
                                              8, 12, 5) &
                  1))
                goto player;
            if (Actor42Field(Actor42Field(tag, void**, 0x28), short*, 2))
                goto player;
        remove:
            Actor42DeleteMoby(owner);
            return;
        third:
            {
                if (Actor42UpdateMobyPathMotion(owner, Actor42Field(tag, void**, 0x34), 512, 128, 0,
                                                8, 12, 5) &
                    1) {
                    if (Actor42Field(Actor42Field(tag, void**, 0x34), short*, 2))
                        goto player;
                    ((Moby*)owner)->state = 0;
                    Actor42RequestMobyAnimation(owner, 0);
                    Actor42TransitionCameraModes9And10(1);
                    ((Moby*)owner)->substate = 1;
                } else {
                    void* nested = Actor42Field(tag, void**, 0x38);
                    void* first = Actor42Field(nested, void**, 12);
                    Actor42PrepareCameraMode9Vectors(first, first + 16);
                }
                goto player;
            }
            return;
    }
    return;
player:
    Actor42PlayerFlags = 0x10000002;
    Actor42SetClampedPlayerTargetAngles(owner + 12);
}
#undef Actor42Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007EB5C.
* Assembly SHA256 0b2ad19429aa52c4600391c29659e5b2e230626cda8222d062d88ea7e5364e7e.
* AI generated; not human reviewed. All679 original instructions and six
* selector words/actual targets are required. Frame0x68 retains original
* S0/S1/S2/S3/S4/RA saves and SP20..4F local extent. State is reloaded
* after the original distance helper; the incoming first call keeps all
* three original arguments. Physical state/substate joins and both route
* end stores retain their original order and shared helper destinations.
* Signed LH trig inputs, low32-bit products, original index reuse, square
* products, shifts12/4/6, wrapping0xFFF and threshold0x801 remain exact.
* The second heading is independently reloaded. Every original private
* word reload and signed shift is retained through the integration tail.
* Empty initialized dependencies and late consumers emit0 instructions;
* immediate tags identify scheduling sites, not retail addresses. Each
* fixed scalar has one live GPR role. No partial HI, overlapping live
* aliases, FP shortcut or opcode assembly is used. Raw units/fixed point,
* complete helper contracts, caller cadence and synchronized runtime
* remain open. Cadence is per invocation; confidence is binary identity
* after all acceptance gates. Falsification: every native/linked word,
* actual transfer/table target, selector/padding byte, full EXE and every
* overlay retail hash must remain identical. */
#define Actor42_7EB5CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor42_7EB5CQueryWorldHeightView1() __asm__("func_8001A358");
unsigned char Actor42_7EB5CRequestMobyAnimationView1() __asm__("func_80034F40");
unsigned char Actor42_7EB5CSetMobyAnimationView1() __asm__("func_80034F80");
int Actor42_7EB5CTurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Actor42_7EB5CCountTimerDownView1() __asm__("func_800359A4");
unsigned char Actor42_7EB5CUpdateMobyPathMotionView1() __asm__("func_80035A80");
int Actor42_7EB5CProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Actor42_7EB5CTestPaddedRotatedBoxView1() __asm__("func_80036220");
void* Actor42_7EB5CSpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
unsigned char Actor42_7EB5CMarkMobyCollectionBitView1() __asm__("func_8003BA00");
unsigned char Actor42_7EB5CPlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor42_7EB5CPlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor42_7EB5CTransformVectorByBasisView1() __asm__("func_8004ED6C");
unsigned char Actor42_7EB5CCopyVectorView1() __asm__("func_8004F178");
unsigned char Actor42_7EB5CAddVectorView1() __asm__("func_8004F194");
int Actor42_7EB5CAbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor42_7EB5CApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor42_7EB5CEstimateSquareRootFromTableView1() __asm__("func_8004F388");
unsigned char Actor42_7EB5CDeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor42_7EB5CRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor42_7EB5CReadSelectedFrameScalarView1() __asm__("func_80055E84");
extern unsigned char Actor42_7EB5CData658A0View1 __asm__("D_800658A0");
extern unsigned char Actor42_7EB5CData65920View1 __asm__("D_80065920");
extern int Actor42_7EB5CData6C550View1 __asm__("D_8006C550");
extern int Actor42_7EB5CData6C574View1 __asm__("D_8006C574");
extern int Actor42_7EB5CData6C578View1 __asm__("D_8006C578");
extern int Actor42_7EB5CData6C58CView1 __asm__("D_8006C58C");
extern int Actor42_7EB5CData6C770View1 __asm__("D_8006C770");
extern unsigned char Actor42_7EB5CData6C7B4View1 __asm__("D_8006C7B4");
extern int Actor42_7EB5CData6E020View1 __asm__("D_8006E020");
extern int Actor42_7EB5CData6E024View1 __asm__("D_8006E024");
extern unsigned short Actor42_7EB5CData6E040View1 __asm__("D_8006E040");
extern unsigned char Actor42_7EB5CData70300View1 __asm__("D_80070300");
extern unsigned char Actor42_7EB5CData70328View1 __asm__("D_80070328");
extern int Actor42_7EB5CData71918View1 __asm__("D_80071918");
extern int Actor42_7EB5CData7191CView1 __asm__("D_8007191C");
extern int Actor42_7EB5CData71920View1 __asm__("D_80071920");
extern int Actor42_7EB5CData71930View1 __asm__("D_80071930");
extern void* (*Actor42_7EB5CDataSpawnMobyView1)() __asm__("SpawnMoby");
void func_level_42_8007EB5C(void* input) {
    register void* ownerRecord17 __asm__("$17");
    register int distanceAngleOrAddress16 __asm__("$16"), retainedIndex18 __asm__("$18"),
        privateRecord19 __asm__("$19"), retainedOffset20 __asm__("$20");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        rawProduct8 __asm__("$8"), rawProduct10 __asm__("$10");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
    } originalFrame;
    unsigned char copyDestination7;
    short temporaryWord4;
    int temporaryWord6;
    register int temporaryWord2 __asm__("$3");
    unsigned char temporaryWord3;
    void* temporaryPointer1;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    privateRecord19 = (int)Actor42_7EB5CField(ownerRecord17, void**, 0);
    if (Actor42_7EB5CField(ownerRecord17, int*, 0x18) != 0) {
        Actor42_7EB5CPlayMobySoundEventView1(input, 0, 0);
        retainedIndex18 = 0;
        retainedOffset20 = 0;
    loop_2:
        if ((Actor42_7EB5CData6C578View1 - Actor42_7EB5CData6C574View1) >= 0x15) {
            distanceAngleOrAddress16 = Actor42_7EB5CDataSpawnMobyView1(0x288, ownerRecord17);
            MATCHING_KEEP(distanceAngleOrAddress16);
            if (distanceAngleOrAddress16 != 0) {
                Actor42_7EB5CField(Actor42_7EB5CField(distanceAngleOrAddress16, void**, 0), short*,
                                   0x12) = 1;
                Actor42_7EB5CSetMobyAnimationView1(distanceAngleOrAddress16, retainedIndex18);
                Actor42_7EB5CCopyVectorView1(&originalFrame.sp20,
                                             Actor42_7EB5CField(privateRecord19, int*, 0x3C) +
                                                 retainedOffset20);
                Actor42_7EB5CTransformVectorByBasisView1(ownerRecord17 + 0x20, &originalFrame.sp20,
                                                         &originalFrame.sp20);
                Actor42_7EB5CAddVectorView1(distanceAngleOrAddress16 + 0xC, ownerRecord17 + 0xC,
                                            &originalFrame.sp20);
                Actor42_7EB5CField(distanceAngleOrAddress16, unsigned char*, 0x44) =
                    (unsigned char)Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x44);
                Actor42_7EB5CField(distanceAngleOrAddress16, unsigned char*, 0x45) =
                    (unsigned char)Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x45);
                Actor42_7EB5CField(distanceAngleOrAddress16, unsigned char*, 0x46) =
                    (unsigned char)Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x46);
            }
            retainedIndex18 += 1;
            retainedOffset20 += 0xC;
            if (retainedIndex18 < 6) {
                goto loop_2;
            }
        }
        argumentWord4 = Actor42_7EB5CField(privateRecord19, int*, 0x40);
        if (argumentWord4 >= 0) {
            Actor42_7EB5CField(((argumentWord4 * 0x58) + Actor42_7EB5CData6C550View1), signed char*,
                               0x48) = 0;
        }
        distanceAngleOrAddress16 =
            Actor42_7EB5CSpawnMobyFromValueSelectorView1(ownerRecord17, 0, 0, 0);
        MATCHING_KEEP(distanceAngleOrAddress16);
        if ((distanceAngleOrAddress16 != 0) &&
            (Actor42_7EB5CProbeGroundFromRaisedMobyView1(ownerRecord17) != 0) &&
            (Actor42_7EB5CData71930View1 != 0)) {
            Actor42_7EB5CField(Actor42_7EB5CField(distanceAngleOrAddress16, void**, 0),
                               signed char*, 0x11) = 1;
            Actor42_7EB5CField(distanceAngleOrAddress16, signed char*, 0x47) = 6;
        }
        Actor42_7EB5CMarkMobyCollectionBitView1(ownerRecord17);
        Actor42_7EB5CDeleteMobyView1(ownerRecord17);
        return;
    }
    distanceAngleOrAddress16 = Actor42_7EB5CApproximatePlanarDistanceView1(
        ownerRecord17 + 0xC, &Actor42_7EB5CData70328View1);
    temporaryWord2 = Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord2) {
        case 0:
            temporaryWord3 = Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49);
            switch (temporaryWord3) {
                case 0:
                    rawWord2 = Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x44);
                    rawWord3 = Actor42_7EB5CField(privateRecord19, int*, 0x40);
                    rawWord2 <<= 4;
                    Actor42_7EB5CField(privateRecord19, int*, 0x2C) = rawWord2;
                    rawWord2 = Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x45);
                    Actor42_7EB5CField(privateRecord19, int*, 0x34) = 0;
                    Actor42_7EB5CField(privateRecord19, int*, 0x38) = 0;
                    rawWord2 <<= 4;
                    Actor42_7EB5CField(privateRecord19, int*, 0x30) = rawWord2;
                    if (rawWord3 >= 0) {
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = Actor42_7EB5CData6C550View1;
                        argumentWord4 = rawWord2 + rawWord3;
                        temporaryWord4 = *Actor42_7EB5CField(argumentWord4, short**, 0);
                        if ((((int)Actor42_7EB5CData6C7B4View1 >> temporaryWord4) & 1) ||
                            (((int)*(&Actor42_7EB5CData70300View1 + Actor42_7EB5CData6C58CView1) >>
                              temporaryWord4) &
                             1)) {
                            Actor42_7EB5CField(privateRecord19, int*, 0x40) = -1;
                        } else {
                            Actor42_7EB5CField(argumentWord4, signed char*, 0x48) = 6;
                        }
                    }
                    if (Actor42_7EB5CField(privateRecord19, void**, 0xC) != 0) {
                        if (Actor42_7EB5CField(privateRecord19, int*, 4) != 0) {
                            Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) = 3U;
                        } else {
                            rawWord2 = 1;
                            __asm__ __volatile__(""
                                                 : "=r"(rawWord2)
                                                 : "0"(rawWord2), "i"(6787329)
                                                 : "memory");
                            Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                            argumentWord4 = (int)ownerRecord17;
                            __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787073) : "memory");
                            argumentWord5 = 1;
                            goto callSharedModeHelper;
                        }
                    } else {
                        goto setSubstateAfterSpawn;
                    }
                    break;
                case 1:
                    Actor42_7EB5CTurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 1);
                    if (distanceAngleOrAddress16 < 0x1800) {
                        rawWord2 = 2;
                        __asm__ __volatile__(""
                                             : "=r"(rawWord2)
                                             : "0"(rawWord2), "i"(6787330)
                                             : "memory");
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                        argumentWord4 = (int)ownerRecord17;
                        __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787074) : "memory");
                        argumentWord5 = 2;
                        goto callSharedModeHelper;
                    }
                    break;
                case 2:
                    if (distanceAngleOrAddress16 < 0x1800) {
                        rawWord2 = 2;
                        __asm__ __volatile__(""
                                             : "=r"(rawWord2)
                                             : "0"(rawWord2), "i"(6787331)
                                             : "memory");
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                        argumentWord4 = (int)ownerRecord17;
                        __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787075) : "memory");
                        argumentWord5 = 2;
                        goto callSharedModeHelper;
                    }
                    if (Actor42_7EB5CCountTimerDownView1(privateRecord19 + 0x28, 4) != 0) {
                        rawWord2 = 1;
                        __asm__ __volatile__(""
                                             : "=r"(rawWord2)
                                             : "0"(rawWord2), "i"(6787332)
                                             : "memory");
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                        argumentWord4 = (int)ownerRecord17;
                        __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787076) : "memory");
                        argumentWord5 = 1;
                        goto callSharedModeHelper;
                    }
                    break;
                case 3:
                    if (distanceAngleOrAddress16 < 0x1800) {
                        argumentWord4 = (int)ownerRecord17;
                        __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787077) : "memory");
                        argumentWord5 = 2;
                        Actor42_7EB5CField(privateRecord19, void**, 0xC) = 0;
                        Actor42_7EB5CField(privateRecord19, int*, 4) = 0;
                        rawWord2 = 2;
                        __asm__ __volatile__(""
                                             : "=r"(rawWord2)
                                             : "0"(rawWord2), "i"(6787333)
                                             : "memory");
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                        goto callSharedModeHelper;
                    }
                    if (Actor42_7EB5CTestPaddedRotatedBoxView1(&Actor42_7EB5CData70328View1,
                                                               privateRecord19 + 0x10, 0, 0) != 0) {
                        rawWord2 = 1;
                        __asm__ __volatile__(""
                                             : "=r"(rawWord2)
                                             : "0"(rawWord2), "i"(6787334)
                                             : "memory");
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                        argumentWord4 = (int)ownerRecord17;
                        __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787078) : "memory");
                        argumentWord5 = 1;
                        goto callSharedModeHelper;
                    }
                    break;
            }
            break;
        case 1:
            if (distanceAngleOrAddress16 < 0x1800) {
                if (Actor42_7EB5CField(privateRecord19, int*, 4) == 0) {
                    argumentWord4 = (int)ownerRecord17;
                    rawWord2 = 2;
                    __asm__ __volatile__(""
                                         : "=r"(rawWord2)
                                         : "0"(rawWord2), "r"(argumentWord4), "i"(6787335)
                                         : "memory");
                    Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                    argumentWord4 = (int)ownerRecord17;
                    __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787079) : "memory");
                    argumentWord5 = 2;
                    goto callSharedModeHelper;
                }
                goto block_45;
            }
        block_45:
            copyDestination7 = 0x40;
            if (Actor42_7EB5CField(privateRecord19, int*, 4) != 0) {
                copyDestination7 = 0x80;
            }
            Actor42_7EB5CUpdateMobyPathMotionView1(ownerRecord17,
                                                   Actor42_7EB5CField(privateRecord19, void**, 0xC),
                                                   0x200, copyDestination7, 0x300, 8, 0x10, 0x27);
            temporaryPointer1 = Actor42_7EB5CField(privateRecord19, void**, 0xC);
            if (Actor42_7EB5CApproximatePlanarDistanceView1(
                    ownerRecord17 + 0xC,
                    Actor42_7EB5CField(temporaryPointer1, int*, 0xC) +
                        (Actor42_7EB5CField(temporaryPointer1, short*, 2) * 0x10)) < 0x201) {
                argumentWord4 = Actor42_7EB5CField(privateRecord19, void**, 0xC);
                if (Actor42_7EB5CField(argumentWord4, short*, 0xA) == 1) {
                    if (Actor42_7EB5CField(argumentWord4, short*, 2) ==
                        (Actor42_7EB5CField(argumentWord4, short*, 0) - 1)) {
                        if (Actor42_7EB5CField(privateRecord19, int*, 4) != 0) {
                            rawWord2 = 1;
                            Actor42_7EB5CField(privateRecord19, void**, 0xC) = 0;
                            Actor42_7EB5CField(privateRecord19, int*, 4) = 0;
                        } else {
                            rawWord2 = -1;
                            Actor42_7EB5CField(argumentWord4, short*, 0xA) = rawWord2;
                            rawWord3 = Actor42_7EB5CField(privateRecord19, int*, 0xC);
                            rawWord2 = Actor42_7EB5CField(rawWord3, unsigned short*, 0);
                            rawWord2 -= 2;
                            Actor42_7EB5CField(rawWord3, short*, 2) = rawWord2;
                            rawWord2 = 60;
                            Actor42_7EB5CField(privateRecord19, int*, 0x28) = rawWord2;
                            rawWord2 = 2;
                        }
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) = rawWord2;
                        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = 0;
                        __asm__ __volatile__("" ::: "$4", "memory");
                        argumentWord4 = (int)ownerRecord17;
                        __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787080) : "memory");
                        argumentWord5 = 0;
                        goto callSharedModeHelper;
                    }
                    goto block_55;
                }
            block_55:
                if ((Actor42_7EB5CField(argumentWord4, short*, 0xA) == -1) &&
                    (Actor42_7EB5CField(argumentWord4, short*, 2) == 0)) {
                    if (Actor42_7EB5CField(privateRecord19, int*, 4) != 0) {
                        rawWord2 = 1;
                        Actor42_7EB5CField(privateRecord19, void**, 0xC) = 0;
                        Actor42_7EB5CField(privateRecord19, int*, 4) = 0;
                    } else {
                        rawWord3 = 1;
                        Actor42_7EB5CField(argumentWord4, short*, 0xA) = rawWord3;
                        rawWord2 = Actor42_7EB5CField(privateRecord19, int*, 0xC);
                        Actor42_7EB5CField(rawWord2, short*, 2) = rawWord3;
                        rawWord2 = 60;
                        Actor42_7EB5CField(privateRecord19, int*, 0x28) = rawWord2;
                        rawWord2 = 2;
                    }
                    Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) = rawWord2;
                    Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = 0;
                    __asm__ __volatile__("" ::: "$4", "memory");
                    argumentWord4 = (int)ownerRecord17;
                    __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787081) : "memory");
                    argumentWord5 = 0;
                    goto callSharedModeHelper;
                }
            }
            break;
        case 2:
            Actor42_7EB5CTurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 1);
            if (Actor42_7EB5CData6C770View1 != 0) {
                argumentWord4 = (int)ownerRecord17;
                __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787082) : "memory");
                argumentWord5 = 3;
                rawWord2 = 0x1E;
                Actor42_7EB5CField(privateRecord19, int*, 0x28) = rawWord2;
                rawWord2 = 3;
                __asm__ __volatile__("" : "=r"(rawWord2) : "0"(rawWord2), "i"(6787336) : "memory");
                Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                goto callSharedModeHelper;
            }
            break;
        case 3:
            if (Actor42_7EB5CTurnMobyTowardPlayerView1(ownerRecord17, 8, 0x10, 1) != 0) {
                if (distanceAngleOrAddress16 < 0x1400) {
                    temporaryWord6 = ((Actor42_7EB5CField(ownerRecord17, int*, 0x14) -
                                       Actor42_7EB5CField(ownerRecord17, short*, 0x38)) -
                                      Actor42_7EB5CField(&Actor42_7EB5CData70328View1, int*, 8)) +
                                     Actor42_7EB5CField(&Actor42_7EB5CData70328View1, int*, 0x44);
                    if (temporaryWord6 < 0) {
                        temporaryWord6 = -temporaryWord6;
                    }
                    if (temporaryWord6 < 0x800) {
                        if ((Actor42_7EB5CAbsoluteByteAngleDeltaView1(
                                 (int)(Actor42_7EB5CData6E040View1 << 0x10) >> 0x14,
                                 Actor42_7EB5CPlanarHeadingLookupView1(
                                     Actor42_7EB5CField(ownerRecord17, int*, 0xC) -
                                         Actor42_7EB5CData6E020View1,
                                     Actor42_7EB5CField(ownerRecord17, int*, 0x10) -
                                         Actor42_7EB5CData6E024View1,
                                     0)) < 0x1C) &&
                            (Actor42_7EB5CField(&Actor42_7EB5CData70328View1, int*, 0x240) == 0)) {
                            if (Actor42_7EB5CCountTimerDownView1(privateRecord19 + 0x28, 4) != 0) {
                                argumentWord4 = (int)ownerRecord17;
                                __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787083)
                                                     : "memory");
                                argumentWord5 = 4;
                                Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) = 0U;
                                rawWord2 = 4;
                                __asm__ __volatile__(""
                                                     : "=r"(rawWord2)
                                                     : "0"(rawWord2), "i"(6787337)
                                                     : "memory");
                                Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                                goto callSharedModeHelper;
                            }
                        } else {
                            goto block_73;
                        }
                    } else {
                        goto block_73;
                    }
                } else {
                block_73:
                    rawWord2 = 0x1E;
                    Actor42_7EB5CField(privateRecord19, int*, 0x28) = rawWord2;
                    goto block_74;
                }
            } else {
            block_74:
                if (distanceAngleOrAddress16 >= 0x2001) {
                    rawWord2 = 5;
                    __asm__ __volatile__(""
                                         : "=r"(rawWord2)
                                         : "0"(rawWord2), "i"(6787338)
                                         : "memory");
                    Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                    argumentWord4 = (int)ownerRecord17;
                    __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787084) : "memory");
                    argumentWord5 = 5;
                    goto callSharedModeHelper;
                }
            }
            break;
        case 4:
            Actor42_7EB5CTurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 1);
            if (Actor42_7EB5CField(&Actor42_7EB5CData70328View1, int*, 0x240) != 0) {
                rawWord2 = 3;
                __asm__ __volatile__("" : "=r"(rawWord2) : "0"(rawWord2), "i"(6787339) : "memory");
                Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                argumentWord4 = (int)ownerRecord17;
                __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787085) : "memory");
                argumentWord5 = 3;
                goto callSharedModeHelper;
            }
            if ((Actor42_7EB5CData6C770View1 != 0) ||
                (((Actor42_7EB5CAbsoluteByteAngleDeltaView1(
                       (int)(Actor42_7EB5CData6E040View1 << 0x10) >> 0x14,
                       Actor42_7EB5CPlanarHeadingLookupView1(
                           Actor42_7EB5CField(ownerRecord17, int*, 0xC) -
                               Actor42_7EB5CData6E020View1,
                           Actor42_7EB5CField(ownerRecord17, int*, 0x10) -
                               Actor42_7EB5CData6E024View1,
                           0)) < 0x25) == 0))) {
                if (distanceAngleOrAddress16 < 0x1400) {
                    rawWord2 = 2;
                    __asm__ __volatile__(""
                                         : "=r"(rawWord2)
                                         : "0"(rawWord2), "i"(6787340)
                                         : "memory");
                    Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                    argumentWord4 = (int)ownerRecord17;
                    __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787086) : "memory");
                    argumentWord5 = 2;
                } else if (Actor42_7EB5CField(privateRecord19, void**, 0xC) != 0) {
                    rawWord2 = 1;
                    __asm__ __volatile__(""
                                         : "=r"(rawWord2)
                                         : "0"(rawWord2), "i"(6787341)
                                         : "memory");
                    Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                    argumentWord4 = (int)ownerRecord17;
                    __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787087) : "memory");
                    argumentWord5 = 1;
                } else {
                    goto resetStateWithoutChild;
                }
                goto callSharedModeHelper;
            }
            if ((Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) == 0) &&
                (Actor42_7EB5CReadSelectedFrameScalarView1(ownerRecord17) >= 0x17)) {
                Actor42_7EB5CDataSpawnMobyView1(0x1F7, ownerRecord17);
            setSubstateAfterSpawn:
                Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) = 1;
            }
            break;
        case 5:
            Actor42_7EB5CTurnMobyTowardPlayerView1(ownerRecord17, 8, 0, 1);
            if (Actor42_7EB5CData6C770View1 == 0)
                break;
            if (Actor42_7EB5CField(privateRecord19, void**, 0xC) != 0) {
                rawWord2 = 1;
                __asm__ __volatile__("" : "=r"(rawWord2) : "0"(rawWord2), "i"(6787342) : "memory");
                Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = rawWord2;
                argumentWord4 = (int)ownerRecord17;
                __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787088) : "memory");
                argumentWord5 = 1;
                goto callSharedModeHelper;
            }
        resetStateWithoutChild:
            argumentWord4 = (int)ownerRecord17;
            __asm__ __volatile__("" ::"r"(argumentWord4), "i"(6787089) : "memory");
            argumentWord5 = 0;
            Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x49) = 1;
            Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x48) = 0;
        callSharedModeHelper:
            Actor42_7EB5CRequestMobyAnimationView1(argumentWord4, argumentWord5);
            break;
    }
    MATCHING_OBSERVE_GNU_VOLATILE(distanceAngleOrAddress16);
    if (Actor42_7EB5CField(privateRecord19, int*, 0) != 0) {
        Actor42_7EB5CCopyVectorView1(&originalFrame.sp30, ownerRecord17 + 0xC);
        originalFrame.sp38 += 0x80;
        rawWord2 = Actor42_7EB5CQueryWorldHeightView1(&originalFrame.sp30, 0x100);
        distanceAngleOrAddress16 = 0;
        if (rawWord2) {
            rawWord2 = Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x46);
            argumentWord6 = Actor42_7EB5CData71918View1;
            rawWord2 <<= 1;
            rawWord3 = Actor42_7EB5CField(&Actor42_7EB5CData65920View1, short*, rawWord2);
            rawWord3 = argumentWord6 * rawWord3;
            argumentWord5 = Actor42_7EB5CData7191CView1;
            MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord3, "memory");
            rawWord2 = Actor42_7EB5CField(&Actor42_7EB5CData658A0View1, short*, rawWord2);
            rawProduct8 = argumentWord5 * rawWord2;
            rawWord3 += rawProduct8;
            rawWord3 >>= 12;
            originalFrame.sp30 = rawWord3;
            argumentWord4 = Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x46);
            argumentWord4 <<= 1;
            rawWord2 = Actor42_7EB5CField(&Actor42_7EB5CData65920View1, short*, argumentWord4);
            rawProduct8 = argumentWord5 * rawWord2;
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawProduct8));
            argumentWord7 = rawWord3 * rawWord3;
            rawWord3 = Actor42_7EB5CData71920View1;
            argumentWord5 = rawWord3 * rawWord3;
            rawWord2 = Actor42_7EB5CField(&Actor42_7EB5CData658A0View1, short*, argumentWord4);
            rawProduct10 = argumentWord6 * rawWord2;
            originalFrame.sp38 = rawWord3;
            argumentWord4 = argumentWord7 + argumentWord5;
            rawWord2 = rawProduct8 - rawProduct10;
            rawWord2 >>= 12;
            originalFrame.sp34 = rawWord2;
            rawWord2 = Actor42_7EB5CEstimateSquareRootFromTableView1(argumentWord4, argumentWord5,
                                                                     argumentWord6, argumentWord7);
            distanceAngleOrAddress16 =
                -Actor42_7EB5CPlanarHeadingLookupView1(rawWord2, originalFrame.sp34, 1);
            rawWord2 =
                Actor42_7EB5CPlanarHeadingLookupView1(originalFrame.sp38, originalFrame.sp30, 1);
            rawWord3 = Actor42_7EB5CField(privateRecord19, int*, 0x2C);
            argumentWord5 = -rawWord2;
            rawWord3 = distanceAngleOrAddress16 - rawWord3;
            distanceAngleOrAddress16 = rawWord3 & 0xFFF;
            if (distanceAngleOrAddress16 >= 0x801)
                distanceAngleOrAddress16 -= 0x1000;
            rawWord2 = Actor42_7EB5CField(privateRecord19, int*, 0x30);
            rawWord2 = argumentWord5 - rawWord2;
            argumentWord5 = rawWord2 & 0xFFF;
            if (argumentWord5 >= 0x801)
                argumentWord5 -= 0x1000;
        } else {
            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(distanceAngleOrAddress16, "$2");
            argumentWord5 = 0;
        }
        rawWord3 = distanceAngleOrAddress16 << 1;
        argumentWord4 = Actor42_7EB5CField(privateRecord19, int*, 0x34);
        rawWord3 >>= 4;
        rawWord2 = argumentWord4 << 4;
        rawWord2 >>= 6;
        rawWord3 -= rawWord2;
        argumentWord4 += rawWord3;
        rawWord3 = argumentWord5 << 1;
        rawWord3 >>= 4;
        Actor42_7EB5CField(privateRecord19, int*, 0x34) = argumentWord4;
        __asm__ __volatile__("" ::"m"(Actor42_7EB5CField(privateRecord19, int*, 0x34)),
                             "r"(rawWord3)
                             : "memory");
        argumentWord4 = Actor42_7EB5CField(privateRecord19, int*, 0x38);
        argumentWord5 = Actor42_7EB5CField(privateRecord19, int*, 0x34);
        rawWord2 = argumentWord4 << 4;
        rawWord2 >>= 6;
        rawWord3 -= rawWord2;
        argumentWord4 += rawWord3;
        rawWord2 = Actor42_7EB5CField(privateRecord19, int*, 0x2C);
        rawWord3 = Actor42_7EB5CField(privateRecord19, int*, 0x30);
        Actor42_7EB5CField(privateRecord19, int*, 0x38) = argumentWord4;
        MATCHING_KEEP(privateRecord19);
        argumentWord4 = Actor42_7EB5CField(privateRecord19, int*, 0x38);
        rawWord2 += argumentWord5;
        rawWord2 &= 0xFFF;
        rawWord3 += argumentWord4;
        Actor42_7EB5CField(privateRecord19, int*, 0x2C) = rawWord2;
        MATCHING_KEEP(privateRecord19);
        rawWord2 = Actor42_7EB5CField(privateRecord19, int*, 0x2C);
        rawWord3 &= 0xFFF;
        Actor42_7EB5CField(privateRecord19, int*, 0x30) = rawWord3;
        rawWord2 >>= 4;
        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x44) = rawWord2;
        rawWord2 = Actor42_7EB5CField(privateRecord19, int*, 0x30);
        rawWord2 >>= 4;
        Actor42_7EB5CField(ownerRecord17, unsigned char*, 0x45) = rawWord2;
    } else {
        argumentWord4 = Actor42_7EB5CField(privateRecord19, int*, 8);
        if (argumentWord4 >= 0) {
            rawWord2 = argumentWord4 * 88;
            rawWord3 = Actor42_7EB5CData6C550View1;
            rawWord2 += rawWord3;
            rawWord3 = Actor42_7EB5CField(rawWord2, int*, 0x14);
            rawWord2 = Actor42_7EB5CField(rawWord2, int*, 0);
            rawWord3 += 4096;
            Actor42_7EB5CField(ownerRecord17, int*, 0x14) = rawWord3;
            rawWord2 = Actor42_7EB5CField(rawWord2, int*, 0x10);
            if (rawWord2 >= 4096) {
                Actor42_7EB5CField(ownerRecord17, int*, 0x18) |= 0x10000;
            }
        }
    }
    Actor42_7EB5CRefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
}
#undef Actor42_7EB5CField

typedef struct {
    Vector3D step;
    int timer, selector;
} DecodedMovingParticleTag;
int DecodedMovingTimer(void*, int) __asm__("func_800359A4");
int DecodedMovingWorld(Vector3D*, Vector3D*) __asm__("func_80018368");
int DecodedMovingPoint(Vector3D*, int, int) __asm__("func_8001C288");
int DecodedMovingQuery(Vector3D*, int, int, int, int, int) __asm__("func_8001BA30");
void func_level_42_8007F5F8(Moby* moby) {
    DecodedMovingParticleTag* tag = moby->mobyTag;
    Vector3D previous;
    switch (moby->state) {
        case 0:
            if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400 ||
                DecodedMovingTimer(&tag->timer, 4))
                goto remove;
            func_8004F178(&previous, &moby->position);
            func_8004F194(&moby->position, &moby->position, &tag->step);
            if (DecodedMovingWorld(&previous, &moby->position) ||
                DecodedMovingPoint(&moby->position, 0x80, 7)) {
                func_8004F178(&moby->position, &previous);
                moby->state = 1;
            } else if (DecodedMovingQuery(&moby->position, 0x200, 0, 0, 0x10000000, tag->selector))
                moby->state = 1;
            func_80055D24(moby, 2);
            break;
        case 1:
            func_8003BABC(moby, 0, 0);
        remove:
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_42/moby/func_level_42_8007F740.s SHA256 aacab9b4283d650dc4776d042d108949cf6b520d1425c24381a122d074c4491a. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level42_7F740Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level42_7F740QueryWorldHeight() __asm__("func_8001A358");
/* extern */
int Level42_7F740SetMobyAnimation() __asm__("func_80034F80");
/* extern */
int Level42_7F740SpawnMobyFromValueSelector() __asm__("func_80036A68");
/* extern */
int Level42_7F740TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
int Level42_7F740ShiftVectorRightTowardZero() __asm__("func_8004F110");
/* extern */
int Level42_7F740ApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
int Level42_7F740DeleteMoby() __asm__("func_80055B18");
/* extern */
int Level42_7F740RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int Level42_7F740ReadSelectedFrameScalar() __asm__("func_80055E84");
/* extern */
int Level42_7F740InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
int Level42_7F740_rand() __asm__("rand");
/* extern */
extern unsigned char Level42_7F740_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level42_7F740_D_80065920 __asm__("D_80065920");
extern int Level42_7F740_D_8006C54C __asm__("D_8006C54C");
extern int Level42_7F740_D_8006C550 __asm__("D_8006C550");
extern int Level42_7F740_D_8006C574 __asm__("D_8006C574");
extern int Level42_7F740_D_8006C578 __asm__("D_8006C578");
extern int Level42_7F740_D_8006C640 __asm__("D_8006C640");
extern int Level42_7F740_D_8006C770 __asm__("D_8006C770");
extern Vector3D Level42_7F740_D_80070328 __asm__("D_80070328");
extern unsigned char Level42_7F740_D_80071AB0 __asm__("D_80071AB0");

void func_level_42_8007F740(Moby* inputOwner) {
    /* Original frame0x70 and scratch offsets SP10/SP20/SP30/SP40 retained.
     * Separate entries restore the owner argument on the original paths.
     * The private-counter test uses the architectural zero register as the
     * callback argument, even though its loaded predicate is also zero.
     * Empty constraints preserve these producers without emitting opcodes.
     * Units, fixed-point domains, helper meanings, cadence and synchronized
     * runtime chains remain unresolved. Confirmed machine identity only. */
    struct {
        Vector3D sp10;
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
    } scratch;

    register Moby* owner18 __asm__("$18") = inputOwner;

    register Moby* child16 __asm__("$16");
    register Vector3D* temp_s1 __asm__("$17");
    register int* temp_s0_2 __asm__("$16");
    int damageFlags;
    register int temp_ret __asm__("$2");
    register int temp_s0 __asm__("$16");
    register int temp_s1_2 __asm__("$17");
    register int temp_s3 __asm__("$19");
    register int temp_s6 __asm__("$22");
    register int temp_v0_2 __asm__("$2");
    register int temp_v0_3 __asm__("$2");
    register int temp_v0_4 __asm__("$2");
    register int temp_v0_5 __asm__("$2");
    register int temp_v0_6 __asm__("$2");
    register int temp_v0_7 __asm__("$2");
    register int temp_v1_2 __asm__("$3");
    register int temp_v1_3 __asm__("$3");
    register int temp_v1_4 __asm__("$3");
    register int var_a1 __asm__("$5");
    register int var_s0 __asm__("$16");
    register int var_s1 __asm__("$17");
    register int var_s3 __asm__("$19");
    register int var_s3_2 __asm__("$19");
    register int var_s5 __asm__("$21");
    register int var_v0 __asm__("$2");
    register int temp_v1 __asm__("$3");
    register void* ownerPrivate20 __asm__("$20");
    register void* temp_v0 __asm__("$2");

    register Vector3D* workVector16 __asm__("$16");
    register Vector3D* particleVector17 __asm__("$17");
    register Vector3D* player16 __asm__("$16");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register int product8 __asm__("$8");
    register int product9 __asm__("$9");
    MATCHING_KEEP(owner18);
    damageFlags = owner18->damageFlags;
    ownerPrivate20 = owner18->mobyTag;
    if (damageFlags & 0x10000)
        goto initializeChildren;
    if (Level42_7F740Field(&Level42_7F740_D_80070328, int*, 0x24C) != 1)
        goto block_10;
    if (damageFlags == 0) {
        argument4 = (int)owner18;
        goto setupArgsReady;
    }
    argument4 = (int)owner18;
    MATCHING_KEEP_VOLATILE(argument4);
initializeChildren:
    func_8003BABC(owner18, 0, 0);
    var_s1 = 0;
    var_s3_2 = 0;
spawnChildren:
    value2 = Level42_7F740_D_8006C578;
    value3 = Level42_7F740_D_8006C574;
    value2 -= value3;
    argument4 = 504;
    if (value2 >= 21) {
        child16 = SpawnMoby(argument4, owner18);
        MATCHING_KEEP(child16);
        if (child16 != 0) {
            Level42_7F740Field(child16->mobyTag, short*, 0x12) = 1;
            Level42_7F740SetMobyAnimation(child16, var_s1);
            func_8004F178(&scratch.sp10, Level42_7F740Field(ownerPrivate20, int*, 0x1C) + var_s3_2);
            Level42_7F740TransformVectorByBasis(&owner18->rotationMatrix, &scratch.sp10,
                                                &scratch.sp10);
            func_8004F194(&child16->position, &owner18->position, &scratch.sp10);
            child16->angle.roll = owner18->angle.roll;
            child16->angle.pitch = owner18->angle.pitch;
            child16->angle.yaw = owner18->angle.yaw;
        }
        var_s1 += 1;
        var_s3_2 += 0xC;
        if (var_s1 < 0xA) {
            goto spawnChildren;
        }
    }
    Level42_7F740SpawnMobyFromValueSelector(owner18, 1, 0, 0);
    func_8003BA00(owner18);
    Level42_7F740DeleteMoby(owner18);
    goto done;
block_10:
    argument4 = (int)owner18;
    MATCHING_OBSERVE_VOLATILE(argument4);
setupArgsReady:
    __asm__("" : "=r"(argument4));
    func_8003573C(argument4, 8, 0, 1);
    workVector16 = &scratch.sp20;
    argument4 = (int)workVector16;
    MATCHING_KEEP(argument4);
    temp_s1 = (Vector3D*)((unsigned char*)&Level42_7F740_D_80070328 + 0x98);
    func_8004F178(argument4, temp_s1);
    scratch.sp20.x *= 30;
    scratch.sp20.y *= 0x1E;
    scratch.sp20.z *= 0x1E;
    Level42_7F740ShiftVectorRightTowardZero(workVector16, 6);
    func_8004F194(workVector16, workVector16, (unsigned char*)temp_s1 - 0x98);
    temp_s3 = Level42_7F740ApproximatePlanarDistance(&owner18->position, workVector16);
    if ((Level42_7F740_D_8006C640 != 0) && (Level42_7F740_D_8006C54C == 0) &&
        !(Level42_7F740_D_8006C640 & 0x1F)) {
        temp_ret = Level42_7F740_rand();
        value3 = temp_ret >> 31;
        MATCHING_KEEP(value3);
        argument4 = temp_ret / 40 + (temp_ret >> 31);
        temp_s1_2 = argument4 - value3;
        MATCHING_KEEP(temp_s1_2);
        value3 = temp_s1_2 * 40;
        temp_s1_2 = temp_ret - value3;
        if (temp_s1_2 < 0x1B) {
            temp_s0 = Level42_7F740_rand() & 7;
            value2 = Level42_7F740_rand() & 7;
            argument4 = 1;
            argument5 = (int)&Level42_7F740_D_80071AB0;
            value3 = temp_s1_2 << 5;
            value3 += argument5;
            temp_s0 <<= 2;
            temp_s0_2 = (int*)(temp_s0 + value3);
            value3 = *temp_s0_2;
            argument4 <<= value2;
            value3 |= argument4;
            *temp_s0_2 = value3;
        }
    }
    temp_v1 = owner18->state;
    switch (temp_v1) { /* irregular */
        case 0:
            value2 = temp_s3 < 0x2800;
            MATCHING_KEEP(value2);
            if ((value2) && (Level42_7F740Field(ownerPrivate20, int*, 8) == 0)) {
                owner18->state = 1;
                argument4 = (int)owner18;
                MATCHING_KEEP_VOLATILE(argument4);
                var_a1 = 1;
                goto callStateCallback;
            }
            break;
        case 1:
            if (Level42_7F740_D_8006C770 != 0) {
                owner18->state = 2;
                argument4 = (int)owner18;
                MATCHING_KEEP_VOLATILE(argument4);
                var_a1 = 2;
                goto callStateCallback;
            }
            break;
        case 2:
            value2 = temp_s3 < 0x1800;
            MATCHING_KEEP(value2);
            if (value2) {
                owner18->state = 3;
                argument4 = (int)owner18;
                MATCHING_KEEP_VOLATILE(argument4);
                var_a1 = 3;
                goto callStateCallback;
            }
            value2 = temp_s3 < 0x3001;
            MATCHING_KEEP(value2);
            if (!value2) {
                owner18->state = 0;
                argument4 = (int)owner18;
                goto prepareStateCallback;
            }
            break;
        case 3:
            if (Level42_7F740ReadSelectedFrameScalar(owner18) >= 0xA) {
                value2 = Level42_7F740Field(ownerPrivate20, int*, 8);
                MATCHING_KEEP_CLOBBER(value2, "$4");
                argument4 = (int)owner18;
                if (!value2) {
                    MATCHING_BARRIER("$2");
                    Level42_7F740InterpolateMobyVertex(argument4, 0, ownerPrivate20 + 0x10);
                    Level42_7F740Field(ownerPrivate20, int*, 8) = 0xC0;
                }
            }
            value2 = Level42_7F740_D_8006C770;
            argument4 = (int)owner18;
            if (!value2)
                goto restoreOwnerArgument;
            owner18->state = 0;
            goto prepareStateCallback;
    }
    goto call55D24;
prepareStateCallback:
    var_a1 = 0;
callStateCallback:
    func_80034F40(argument4, var_a1);
restoreOwnerArgument:
    MATCHING_BARRIER("$4");
call55D24:
    argument4 = (int)owner18;
    MATCHING_OBSERVE_VOLATILE(argument4);
    Level42_7F740RefreshMobySpatialGridAndBasis(argument4, 4);
    temp_v1_2 = Level42_7F740Field(ownerPrivate20, int*, 4);
    if (temp_v1_2 >= 0) {
        value2 = temp_v1_2 * 88;
        value3 = Level42_7F740_D_8006C550;
        temp_v0 = (void*)(value2 + value3);
        value3 = Level42_7F740Field(temp_v0, int*, 0x14);
        value2 = (int)Level42_7F740Field(temp_v0, void**, 0);
        value3 += 4096;
        owner18->position.z = value3;
        if (Level42_7F740Field((void*)value2, int*, 0x10) >= 0x1000) {
            owner18->damageFlags |= 0x10000;
        }
    }
    temp_v0_2 = Level42_7F740Field(ownerPrivate20, int*, 8);
    temp_s6 = temp_v0_2 * 2;
    if (temp_v0_2 != 0) {
        if (temp_s6 < 0x1000) {
            value2 = 4096;
            var_s5 = value2 - temp_s6;
        } else {
            var_s5 = 0;
        }
        var_s3 = 0;
        scratch.sp30 = 0;
        scratch.sp34 = 0;
        scratch.sp38 = 8;
        particleVector17 = (Vector3D*)&scratch.sp40;
        value2 = owner18->angle.yaw;
        var_s0 = value2 - 12;
        do {
            temp_v0_3 = ((var_s0 + func_8003636C(0, 3)) & 0xFF) * 2;
            argument4 = Level42_7F740Field(&Level42_7F740_D_80065920, short*, temp_v0_3);
            value3 = Level42_7F740Field(ownerPrivate20, int*, 8);
            scratch.sp40 = (argument4 * value3) >> 12;
            value3 = Level42_7F740Field(&Level42_7F740_D_800658A0, short*, temp_v0_3);
            value2 = Level42_7F740Field(ownerPrivate20, int*, 8);
            {
                int secondProduct = value3 * value2;
                argument5 = (int)particleVector17;
                argument6 = (int)ownerPrivate20 + 16;
                argument4 = (int)particleVector17;
                MATCHING_KEEP3(argument4, argument5, argument6);
                scratch.sp48 = 0;
                MATCHING_BARRIER_VOLATILE("memory");
                scratch.sp44 = secondProduct >> 12;
            }
            func_8004F194(argument4, argument5, argument6);
            temp_v1_3 = owner18->position.z;
            scratch.sp48 = temp_v1_3;
            if (Level42_7F740Field(ownerPrivate20, int*, 0) != 0) {
                argument4 = (int)particleVector17;
                argument5 = 1024;
                MATCHING_KEEP2(argument4, argument5);
                value2 = temp_v1_3 + 512;
                scratch.sp48 = value2;
                temp_v0_4 = Level42_7F740QueryWorldHeight(argument4, argument5);
                scratch.sp48 = temp_v0_4;
                if (temp_v0_4 == 0) {
                    scratch.sp48 = owner18->position.z;
                }
            }
            temp_v0_5 = scratch.sp48 + 0x80;
            scratch.sp48 = temp_v0_5;
            if (var_s5 != 0) {
                value3 = temp_s6 * temp_v0_5;
                value2 = Level42_7F740Field(ownerPrivate20, int*, 0x18);
                product9 = var_s5 * value2;
                value2 = value3 + product9;
                value2 >>= 12;
                scratch.sp48 = value2;
            }
            argument4 = 1;
            argument5 = 32;
            argument6 = (int)&scratch.sp40;
            argument7 = (int)&scratch.sp30;
            MATCHING_KEEP4(argument4, argument5, argument6, argument7);
            var_s0 += 3;
            var_s3 += 1;
            SpawnParticle(argument4, argument5, argument6, argument7);
        } while (var_s3 < 8);
        player16 = &Level42_7F740_D_80070328;
        temp_s3 = Level42_7F740ApproximatePlanarDistance(player16, ownerPrivate20 + 0x10);
        temp_v1_4 = Level42_7F740Field(ownerPrivate20, int*, 8);
        value2 = temp_v1_4 + 512;
        value2 = temp_s3 < value2;
        MATCHING_KEEP(value2);
        if (value2) {
            value2 = temp_v1_4 - 512;
            value2 = value2 < temp_s3;
            MATCHING_KEEP(value2);
            if (value2) {
                var_v0 = ((owner18->position.z - owner18->distanceToGround) -
                          Level42_7F740_D_80070328.z) +
                         Level42_7F740Field(&Level42_7F740_D_80070328, int*, 0x44);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < 0x200) &&
                    (func_8004F264((int)owner18->angle.yaw,
                                   func_8004E880(Level42_7F740_D_80070328.x - owner18->position.x,
                                                 Level42_7F740_D_80070328.y - owner18->position.y,
                                                 0)) < 0xC)) {
                    Level42_7F740Field(&Level42_7F740_D_80070328, int*, 0x24) =
                        (int)(Level42_7F740Field(&Level42_7F740_D_80070328, int*, 0x24) | 0xE);
                }
            }
        }
        temp_v0_7 = Level42_7F740Field(ownerPrivate20, int*, 8) + 0xC0;
        Level42_7F740Field(ownerPrivate20, int*, 8) = temp_v0_7;
        if (temp_v0_7 >= 0x1001) {
            Level42_7F740Field(ownerPrivate20, int*, 8) = 0;
        }
    }
    return;

done:;
}
#undef Level42_7F740Field

#define PFDE0_FIELD(type, base, offset) (*(type*)((unsigned char*)(base) + (offset)))
extern unsigned char PFDE0Player[] __asm__("D_80070328");
extern unsigned char* PFDE0End __asm__("D_8006C54C");
extern unsigned char D_level_42_8008FEBC[];
extern int PFDE0Table[] __asm__("D_80071A10");
extern int D_8006C640, D_8006C774, D_8006C644;
/* Register bindings and empty constraints preserve the original compiler scheduling.
 * Raw offsets retain fields whose complete producer/consumer meaning is unresolved. */
void func_level_42_8007FDE0(Moby* moby) {
    register Moby* owner __asm__("$18") = moby;
    Vector3D targetPosition;
    Vector3D previousPosition;
    register Vector3D* ownerPosition __asm__("$19");
    register int *tableEntry4 __asm__("$4"), *table3 __asm__("$3");
    register int remainder4 __asm__("$4"), work3 __asm__("$3");
    register int targetAngle __asm__("$16");
    register int work2 __asm__("$2");
    register int offset2 __asm__("$2");
    int raisedOffset;
    register int loweredOffset2 __asm__("$2");
    int temp_v1;
    unsigned char state;
    register int nextState2 __asm__("$2");
    register Vector3D *distance4 __asm__("$4"), *distance5 __asm__("$5");
    register int angle2 __asm__("$2");
    register int motion2 __asm__("$2"), motion3 __asm__("$3"), motion4 __asm__("$4"),
        motion5 __asm__("$5");
    register void* pathData __asm__("$16");
    register void* privateData __asm__("$17");

    MATCHING_KEEP(owner);
    privateData = owner->mobyTag;
    pathData = PFDE0_FIELD(void*, privateData, 0x1C);
    if (pathData != 0) {
        func_8004F178(&targetPosition,
                      PFDE0_FIELD(int, pathData, 0xC) + (PFDE0_FIELD(short, pathData, 2) * 0x10));
        ownerPosition = &owner->position;
        if (func_8004F334(ownerPosition, &targetPosition) < 0x101) {
            PFDE0_FIELD(short, pathData, 2) =
                (short)((unsigned short)PFDE0_FIELD(short, pathData, 2) ^ 1);
        }
        angle2 = func_8004E880(targetPosition.x - owner->position.x,
                               targetPosition.y - owner->position.y, 0);
        distance4 = ownerPosition;
        distance5 = &targetPosition;
        MATCHING_OBSERVE3_CLOBBER(distance4, distance5, angle2, "$16");
        targetAngle = angle2;
        if (func_8004F334(distance4, distance5) >= 0x101) {
            func_8004F178(&previousPosition, ownerPosition);
            func_80035EE0(owner, targetAngle, 0x20, 0, 0, 0);
            if (PFDE0_FIELD(Moby*, PFDE0Player, 0x13C) == owner) {
                motion3 = 0x10000000;
                MATCHING_KEEP(motion3);
                motion2 = owner->position.x;
                motion4 = owner->position.y;
                __asm__("" : "=r"(motion4) : "0"(motion4), "r"(motion2), "r"(motion3));
                motion3 |= 8;
                PFDE0_FIELD(int, PFDE0Player, 0x20C) = motion3;
                motion3 = previousPosition.x;
                motion5 = PFDE0_FIELD(int, PFDE0Player, 4);
                PFDE0_FIELD(int, PFDE0Player, 0x224) = 0;
                motion2 -= motion3;
                motion4 -= motion5;
                PFDE0_FIELD(int, PFDE0Player, 0x21C) = motion2;
                PFDE0_FIELD(int, PFDE0Player, 0x220) = motion4;
            }
        }
    }
    if (((PFDE0End - 1) == D_level_42_8008FEBC) && (D_8006C774 != 0) && !(D_8006C640 & 7)) {
        work2 = rand();
        __asm__("" : "=r"(work2) : "0"(work2) : "$12", "$10");
        remainder4 = work2 / 27;
        __asm__("" : "=r"(remainder4) : "0"(remainder4), "r"(work2));
        work3 = remainder4 * 27;
        remainder4 = work2 - work3;
        MATCHING_KEEP(remainder4);
        table3 = PFDE0Table;
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
    state = owner->state;
    switch (state) {
        case 0:
            PFDE0_FIELD(int, privateData, 0x10) =
                (int)(0x1000 - PFDE0_FIELD(int, privateData, 0xC));
            *(unsigned int*)((unsigned char*)owner + 0x54) =
                (PFDE0_FIELD(int, privateData, 8) & 0xFFFFFF) | 0x80000000;
            work2 = D_8006C644;
            __asm__("" : "=r"(privateData) : "0"(privateData), "r"(work2) : "memory");
            PFDE0_FIELD(int, privateData, 0x14) = work2;
            goto stateOne;
        case 1:
            offset2 = -D_800658A0[(D_8006C644 - PFDE0_FIELD(int, privateData, 0x14)) & 0xFF] >> 5;
            PFDE0_FIELD(int, privateData, 0x10) = offset2;
            offset2 += 0x1000;
            MATCHING_KEEP(offset2);
            PFDE0_FIELD(int, privateData, 0x10) = offset2 - PFDE0_FIELD(int, privateData, 0xC);
            if ((PFDE0_FIELD(Moby*, PFDE0Player, 0x13C) == owner) &&
                (PFDE0_FIELD(int, privateData, 0x18) != 0)) {
                func_8003BB10(owner, 2, 0);
                nextState2 = 2;
                goto storeState;
            }
            break;
        case 2:
            raisedOffset = PFDE0_FIELD(int, privateData, 0x10) + 0x18;
            PFDE0_FIELD(int, privateData, 0x10) = raisedOffset;
            if (raisedOffset >= 0x1100) {
                PFDE0_FIELD(int, privateData, 0x10) = 0x1100;
                nextState2 = 3;
                goto storeState;
            }
            break;
        case 3:
            work2 = (int)PFDE0_FIELD(Moby*, PFDE0Player, 0x13C);
            MATCHING_KEEP_CLOBBER(work2, "$3");
            if (work2 != (int)owner) {
                work2 = (unsigned int)(PFDE0_FIELD(int, PFDE0Player, 0x50) - 7) < 2U;
                MATCHING_KEEP_CLOBBER(work2, "$3");
                work3 = 0x1000;
                if (!work2 || (PFDE0_FIELD(int, privateData, 0x10) < 0x1000)) {
                    loweredOffset2 = PFDE0_FIELD(int, privateData, 0x10) - 0x20;
                    work3 -= PFDE0_FIELD(int, privateData, 0xC);
                    PFDE0_FIELD(int, privateData, 0x10) = loweredOffset2;
                    if (work3 >= loweredOffset2) {
                        work2 = D_8006C644;
                        __asm__("" : "=r"(work2) : "0"(work2), "r"(work3));
                        PFDE0_FIELD(int, privateData, 0x10) = work3;
                        PFDE0_FIELD(int, privateData, 0x14) = work2;
                        goto stateOne;
                    }
                }
            } else {
                nextState2 = 2;
                goto storeState;
            }
            break;
    }
    goto updateHeight;
stateOne:
    nextState2 = 1;
storeState:
    owner->state = nextState2;
updateHeight:
    owner->position.z = PFDE0_FIELD(int, privateData, 8) - PFDE0_FIELD(int, privateData, 0x10);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_42/moby/func_level_42_8008017C.s SHA256 cc212a0ade0f24426d51748bd5dd8a35b8fa5d1019f0979d5fdba1429dfe1738. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Controller8017CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char Controller8017CRequestMobyAnimation() __asm__("func_80034F40");        /* extern */
int Controller8017CCountTimerDown() __asm__("func_800359A4");                        /* extern */
int Controller8017CUpdateMobyInteractionGate() __asm__("func_80037BBC");             /* extern */
int Controller8017CPlayMobySoundEvent() __asm__("func_8003BABC");                    /* extern */
unsigned char Controller8017CTransitionSoundHandleTo3Or5() __asm__("func_8003BE70"); /* extern */
int Controller8017CSoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");   /* extern */
unsigned char Controller8017CStartDialogue() __asm__("func_800512E4");               /* extern */
int Controller8017C_rand() __asm__("rand");                                          /* extern */
extern int Controller8017C_D_8006C58C __asm__("D_8006C58C");
extern int Controller8017C_D_8006C640 __asm__("D_8006C640");
extern int Controller8017C_D_8006C770 __asm__("D_8006C770");
extern unsigned char Controller8017C_D_8006C7B4 __asm__("D_8006C7B4");
extern int Controller8017C_D_8006E344 __asm__("D_8006E344");
extern unsigned char Controller8017C_D_80070300 __asm__("D_80070300");
extern unsigned char Controller8017C_D_level_42_8008FEBC __asm__("D_level_42_8008FEBC");
extern void* (*Controller8017C_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char
    Controller8017C_Address_func_level_42_80074F78 __asm__("func_level_42_80074F78");
extern unsigned char main_TEXT_END;
extern unsigned char main_TEXT_START;

void func_level_42_8008017C(void* inputOwner) {
    register void* owner __asm__("$18") = inputOwner;
    register unsigned char* scanLimit6 __asm__("$6");
    register void* stateOwner4 __asm__("$4");
    /* Original frame: three particle arguments at SP+0x10..0x18;
     * saves start at SP+0x20. Raw field offsets are bytes. The three loops
     * update private+0x28 using the original eight rounds and 64-byte limit.
     * Empty constraints emit no instructions and preserve original producers.
     * Helper meanings, physical units and caller cadence remain unresolved. */
    struct {
        int sp10, sp14, sp18, pad1C;
    } originalFrame;

    register int nextMode5 __asm__("$5");
    register int firstPrivateWord28 __asm__("$3");
    register int secondPrivateWord28 __asm__("$3");
    register int thirdPrivateWord28 __asm__("$3");
    register int firstBitCount4 __asm__("$4");
    register int secondBitCount4 __asm__("$4");
    register int thirdBitCount4 __asm__("$4");
    register int firstByteCount5 __asm__("$5");
    register int secondByteCount5 __asm__("$5");
    register int thirdByteCount5 __asm__("$5");
    register int firstUpdatedWord2 __asm__("$2");
    register int secondUpdatedWord2 __asm__("$2");
    register int thirdUpdatedWord2 __asm__("$2");
    register int nextState2 __asm__("$2");
    register unsigned char* firstCursor3 __asm__("$3");
    unsigned char* advancedFirstCursor;
    register unsigned char* secondCursor3 __asm__("$3");
    register unsigned char* thirdCursor3 __asm__("$3");
    unsigned char temp_v1;
    register unsigned int initialStateByte2 __asm__("$2");
    register int initialModeSix3 __asm__("$3");
    register unsigned char* executableEnd3 __asm__("$3");
    register unsigned char* executableCursor2 __asm__("$2");
    unsigned char temp_v1_5;
    register void* privateData __asm__("$16");
    register void* firstParticle __asm__("$17");
    register void* secondParticle __asm__("$16");

    MATCHING_KEEP(owner);
    initialModeSix3 = 6;
    MATCHING_KEEP(initialModeSix3);
    initialStateByte2 = ((Moby*)owner)->state;
    MATCHING_KEEP_CLOBBER(initialStateByte2, "memory");
    privateData = ((Moby*)owner)->mobyTag;
    if ((initialStateByte2 != initialModeSix3) && (Controller8017C_D_8006C640 < 0xA) &&
        ((Controller8017C_D_8006C7B4 & 1) ||
         (*(&Controller8017C_D_80070300 + Controller8017C_D_8006C58C) & 1))) {
        Controller8017CField(owner, signed char*, 0x41) = 0;
        Controller8017CField(owner, signed char*, 0x4C) = 0;
        Controller8017CField(owner, signed char*, 0x4D) = 0;
        Controller8017CField(owner, int*, 8) = 0;
        ((Moby*)owner)->state = 6U;
    }
    temp_v1 = ((Moby*)owner)->state;
    if ((temp_v1 < 2U) && (temp_v1 != 1) && (((Moby*)owner)->damageFlags != 0)) {
        if (Controller8017CSoundHandleMatchesOwnerInStates1Or2(
                owner, Controller8017CField(privateData, int*, 0x30)) == 0) {
            Controller8017CField(privateData, int*, 0x30) =
                Controller8017CPlayMobySoundEvent(owner, 0, 4);
        }
        ((Moby*)owner)->state = 2U;
        Controller8017CRequestMobyAnimation(owner, 2);
    }
    if (Controller8017CField(privateData, unsigned char**, 0x34) == 0) {
        Controller8017CField(privateData, unsigned char**, 0x34) =
            (unsigned char*)(Controller8017C_D_8006C58C + (&main_TEXT_START + 2));
    }
    executableCursor2 = Controller8017CField(privateData, unsigned char**, 0x34);
    executableEnd3 = &main_TEXT_END;
    MATCHING_KEEP(executableEnd3);
    if ((unsigned int)executableCursor2 < (unsigned int)executableEnd3) {
        firstByteCount5 = 0;
        scanLimit6 = executableEnd3;
        MATCHING_KEEP(scanLimit6);
    scanExecutableByte:
        firstCursor3 = Controller8017CField(privateData, unsigned char**, 0x34);
        if ((unsigned int)firstCursor3 < (unsigned int)scanLimit6) {
            firstBitCount4 = 0;
            Controller8017CField(privateData, int*, 0x28) =
                (int)(Controller8017CField(privateData, int*, 0x28) ^ (*firstCursor3 << 8));
            do {
                firstPrivateWord28 = Controller8017CField(privateData, int*, 0x28);
                if (firstPrivateWord28 & 0x8000) {
                    firstUpdatedWord2 = (firstPrivateWord28 * 2) ^ 0x8005;
                } else {
                    firstUpdatedWord2 = firstPrivateWord28 * 2;
                }
                Controller8017CField(privateData, int*, 0x28) = firstUpdatedWord2;
                MATCHING_BARRIER("memory");
                firstBitCount4 += 1;
            } while (firstBitCount4 < 8);
            firstByteCount5 += 1;
            advancedFirstCursor = Controller8017CField(privateData, unsigned char**, 0x34) +
                                  ((Controller8017CField(privateData, int*, 0x28) & 3) + 1);
            Controller8017CField(privateData, unsigned char**, 0x34) = advancedFirstCursor;
            if (firstByteCount5 >= 0x40) {
                if ((unsigned int)advancedFirstCursor >= (unsigned int)&main_TEXT_END) {
                    goto startOverlayScan;
                }
            } else {
                goto scanExecutableByte;
            }
        } else {
        startOverlayScan:
            Controller8017CField(privateData, unsigned char**, 0x34) =
                &Controller8017C_Address_func_level_42_80074F78;
        }
    }
    temp_v1_5 = ((Moby*)owner)->state;
    switch (temp_v1_5) {
        case 0:
            if ((Controller8017CField(privateData, unsigned char**, 0x34) ==
                 &Controller8017C_D_level_42_8008FEBC) &&
                (Controller8017CField(privateData, int*, 0x28) != 0)) {
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 7) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0xF) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x10) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x18) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x19) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x21) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x22) = 0;
                Controller8017CField(privateData, int*, 0x28) = 0;
            }
            if (!(Controller8017C_D_8006C7B4 & 1) &&
                !(*(&Controller8017C_D_80070300 + Controller8017C_D_8006C58C) & 1) &&
                (Controller8017CUpdateMobyInteractionGate(owner, 0) != 0)) {
                Controller8017CStartDialogue(owner, 0, 1);
                ((Moby*)owner)->state = 1U;
            }
            secondByteCount5 = 0;
            if ((unsigned int)Controller8017CField(privateData, unsigned char**, 0x34) >=
                (unsigned int)&Controller8017C_Address_func_level_42_80074F78) {
                scanLimit6 = &Controller8017C_D_level_42_8008FEBC;
                MATCHING_KEEP(scanLimit6);
            scanOverlayByteStateZero:
                secondCursor3 = Controller8017CField(privateData, unsigned char**, 0x34);
                secondBitCount4 = 0;
                if ((unsigned int)secondCursor3 < (unsigned int)scanLimit6) {
                    Controller8017CField(privateData, int*, 0x28) =
                        (int)(Controller8017CField(privateData, int*, 0x28) ^
                              (*secondCursor3 << 8));
                    do {
                        secondPrivateWord28 = Controller8017CField(privateData, int*, 0x28);
                        if (secondPrivateWord28 & 0x8000) {
                            secondUpdatedWord2 = (secondPrivateWord28 * 2) ^ 0x8005;
                        } else {
                            secondUpdatedWord2 = secondPrivateWord28 * 2;
                        }
                        Controller8017CField(privateData, int*, 0x28) = secondUpdatedWord2;
                        MATCHING_BARRIER("memory");
                        secondBitCount4 += 1;
                    } while (secondBitCount4 < 8);
                    secondByteCount5 += 1;
                    Controller8017CField(privateData, unsigned char**, 0x34) =
                        (unsigned char*)(Controller8017CField(privateData, unsigned char**, 0x34) +
                                         1);
                    if (secondByteCount5 < 0x40) {
                        goto scanOverlayByteStateZero;
                    }
                }
            }
        default:
            return;
        case 1:
            if (Controller8017C_D_8006E344 != 1) {
                ((Moby*)owner)->damageFlags = 0;
                ((Moby*)owner)->state = 0U;
                return;
            }
            break;
        case 2:
            if ((((Moby*)owner)->damageFlags & 0x10000) && (Controller8017C_D_8006C640 & 1)) {
                originalFrame.sp10 = (Controller8017C_rand() & 0xF) - 8;
                originalFrame.sp14 = (Controller8017C_rand() & 0xF) - 8;
                originalFrame.sp18 = (Controller8017C_rand() & 0xF) + 8;
                firstParticle =
                    Controller8017C_SpawnParticle(1, 0x37, owner + 0xC, &originalFrame.sp10);
                if (firstParticle != 0) {
                    Controller8017CField(firstParticle, unsigned short*, 8) =
                        (unsigned short)(Controller8017CField(firstParticle, unsigned short*, 8) +
                                         (Controller8017C_rand() & 0xFF));
                }
            }
            if (Controller8017C_D_8006C770 != 0) {
                stateOwner4 = owner;
                nextMode5 = 3;
                Controller8017CField(privateData, int*, 0x24) = 0x3C;
                nextState2 = 3;
                goto applySharedState;
            }
            break;
        case 3:
            if (Controller8017CCountTimerDown(privateData + 0x24, 4) != 0) {
                ((Moby*)owner)->damageFlags = 0;
                if (Controller8017CSoundHandleMatchesOwnerInStates1Or2(
                        owner, Controller8017CField(privateData, int*, 0x30)) != 0) {
                    Controller8017CTransitionSoundHandleTo3Or5(
                        Controller8017CField(privateData, int*, 0x30));
                }
                stateOwner4 = owner;
                nextMode5 = 4;
                Controller8017CField(privateData, int*, 0x30) = -1;
                nextState2 = 4;
            applySharedState:
                Controller8017CField(stateOwner4, signed char*, 0x48) = nextState2;
                Controller8017CRequestMobyAnimation(stateOwner4, nextMode5);
                return;
            }
            if ((((Moby*)owner)->damageFlags & 0x10000) && (Controller8017C_D_8006C640 & 1)) {
                originalFrame.sp10 = (Controller8017C_rand() & 0xF) - 8;
                originalFrame.sp14 = (Controller8017C_rand() & 0xF) - 8;
                originalFrame.sp18 = (Controller8017C_rand() & 0xF) + 8;
                secondParticle =
                    Controller8017C_SpawnParticle(1, 0x37, owner + 0xC, &originalFrame.sp10);
                if (secondParticle != 0) {
                    Controller8017CField(secondParticle, unsigned short*, 8) =
                        (unsigned short)(Controller8017CField(secondParticle, unsigned short*, 8) +
                                         (Controller8017C_rand() & 0xFF));
                    return;
                }
            }
            break;
        case 4:
            if (Controller8017C_D_8006C770 != 0) {
                ((Moby*)owner)->state = 0U;
                Controller8017CRequestMobyAnimation(owner, 0);
                return;
            }
            break;
        case 6:
            if ((Controller8017CField(privateData, unsigned char**, 0x34) ==
                 &Controller8017C_D_level_42_8008FEBC) &&
                (Controller8017CField(privateData, int*, 0x28) != 0)) {
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 7) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0xF) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x10) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x18) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x19) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x21) = 0;
                Controller8017CField(&Controller8017C_D_80070300, signed char*, 0x22) = 0;
                Controller8017CField(privateData, int*, 0x28) = 0;
            }
            thirdByteCount5 = 0;
            if ((unsigned int)Controller8017CField(privateData, unsigned char**, 0x34) >=
                (unsigned int)&Controller8017C_Address_func_level_42_80074F78) {
                scanLimit6 = &Controller8017C_D_level_42_8008FEBC;
                MATCHING_KEEP(scanLimit6);
            scanOverlayByteStateSix:
                thirdCursor3 = Controller8017CField(privateData, unsigned char**, 0x34);
                thirdBitCount4 = 0;
                if ((unsigned int)thirdCursor3 < (unsigned int)scanLimit6) {
                    Controller8017CField(privateData, int*, 0x28) =
                        (int)(Controller8017CField(privateData, int*, 0x28) ^ (*thirdCursor3 << 8));
                    do {
                        thirdPrivateWord28 = Controller8017CField(privateData, int*, 0x28);
                        if (thirdPrivateWord28 & 0x8000) {
                            thirdUpdatedWord2 = (thirdPrivateWord28 * 2) ^ 0x8005;
                        } else {
                            thirdUpdatedWord2 = thirdPrivateWord28 * 2;
                        }
                        Controller8017CField(privateData, int*, 0x28) = thirdUpdatedWord2;
                        MATCHING_BARRIER("memory");
                        thirdBitCount4 += 1;
                    } while (thirdBitCount4 < 8);
                    thirdByteCount5 += 1;
                    Controller8017CField(privateData, unsigned char**, 0x34) =
                        (unsigned char*)(Controller8017CField(privateData, unsigned char**, 0x34) +
                                         1);
                    if (thirdByteCount5 < 0x40) {
                        goto scanOverlayByteStateSix;
                    }
                }
            }
            break;
    }
}
#undef Controller8017CField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. C derived from original instructions. Original source asm/nonmatchings/overlays/level_42/moby/func_level_42_800807FC.s SHA256 b8a4b926ef1d17bfbc206baf8ad66d3b16622745e870d8bc7a9a75535c15760d. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Desert807FCMaskLinkedRecordFlagsById() __asm__("func_80021ED8");
int Desert807FCQueryShiftedLinkedRecordWordByByteId() __asm__("func_80021F3C");
int Desert807FCSetMobyAnimation() __asm__("func_80034F80");
int Desert807FCGetClosestPathNode() __asm__("func_8003645C");
int Desert807FCSpawnMobyFromValueSelector() __asm__("func_80036A68");
int Desert807FCBuildPackedAngleBasisMatrix() __asm__("func_8004EA90");
int Desert807FCTransformVectorByBasis() __asm__("func_8004ED6C");
int Desert807FCShiftVectorRightTowardZero() __asm__("func_8004F110");
int Desert807FCSubtractVector() __asm__("func_8004F1C8");
int Desert807FCDeleteMoby() __asm__("func_80055B18");
int Desert807FCRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Desert807FCReadSelectedFrameScalar() __asm__("func_80055E84");
int Desert807FCInterpolateMobyVertex() __asm__("func_80055F14");
int Desert807FC_rand() __asm__("rand");
extern unsigned char Desert807FC_D_800658A0 __asm__("D_800658A0");
extern unsigned char Desert807FC_D_80065920 __asm__("D_80065920");
extern int Desert807FC_D_8006C574 __asm__("D_8006C574");
extern int Desert807FC_D_8006C578 __asm__("D_8006C578");
extern int Desert807FC_D_8006C644 __asm__("D_8006C644");
extern int Desert807FC_D_8006C770 __asm__("D_8006C770");
extern unsigned char Desert807FC_D_8006D048 __asm__("D_8006D048");
extern short Desert807FC_D_8006E03E __asm__("D_8006E03E");
extern unsigned char Desert807FC_D_80070328 __asm__("D_80070328");

void func_level_42_800807FC(Moby* inputMoby) {
    /* Raw stack byte offsets, packed rotation bytes and signed table widths.
     * Empty constraints preserve original native words without instructions. */
    struct {
        Vector3D sp10;
        char pad_1c[4];
        Vector3D sp20;
        char pad_2c[4];
        Vector3D sp30;
        char pad_3c[4];
        int sp40;
        int sp44;
        int sp48;
        char pad_4c[20];
        int sp60;
        char pad_64[4];
        int sp68;
        int sp6C;
        int sp70;
        char pad_74[4];
    } originalStack;

    register Moby* moby __asm__("$18") = inputMoby;

    register Moby* spawnedChild16 __asm__("$16");
    register int pathIndex6 __asm__("$6");
    register int pathStep2 __asm__("$2");
    register int period4 __asm__("$4");
    register int pathPositions7 __asm__("$7");
    register int phaseRemainder5 __asm__("$5");
    register int firstRandom16 __asm__("$16");
    register int secondRandom16 __asm__("$16");
    register int animationFrame16 __asm__("$16");
    register int periodStart3 __asm__("$3");
    register int tableOffset3 __asm__("$3");
    register int childIndex17 __asm__("$17");
    register int childOffset20 __asm__("$20");
    register int absoluteAngle2 __asm__("$2");
    register int angleDifference3 __asm__("$3");
    register int state3 __asm__("$3");
    register void* queryPath5 __asm__("$5");
    register void* privateData19 __asm__("$19");
    register void* pathData2 __asm__("$2");
    register void* pathDataAfterCall2 __asm__("$2");
    register void* completedPath2 __asm__("$2");
    register void* interpolationPath2 __asm__("$2");
    register void* stepData3 __asm__("$3");
    register void* activePath3 __asm__("$3");

    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register void* vector16 __asm__("$16");
    register void* vector17 __asm__("$17");
    MATCHING_KEEP(moby);
    value3 = 3;
    value2 = moby->state;
    privateData19 = moby->mobyTag;
    if ((value2 != value3) && (moby->damageFlags & 0x02020000)) {
        func_8003BABC(inputMoby, 0, 0);
        childIndex17 = 0;
        childOffset20 = 0;
    spawnNextChild:
        if ((Desert807FC_D_8006C578 - Desert807FC_D_8006C574) >= 0x15) {
            spawnedChild16 = SpawnMoby(0x2EC, moby);
            MATCHING_KEEP(spawnedChild16);
            if (spawnedChild16 != 0) {
                M2C_FIELD(spawnedChild16->mobyTag, short*, 0x12) = 1;
                Desert807FCSetMobyAnimation(spawnedChild16, childIndex17);
                func_8004F178(&originalStack.sp10,
                              M2C_FIELD(privateData19, int*, 0x64) + childOffset20);
                Desert807FCTransformVectorByBasis(&moby->rotationMatrix, &originalStack.sp10,
                                                  &originalStack.sp10);
                func_8004F194(&spawnedChild16->position, &moby->position, &originalStack.sp10);
                spawnedChild16->angle.roll = moby->angle.roll;
                spawnedChild16->angle.pitch = moby->angle.pitch;
                value3 = moby->angle.yaw;
                value2 = 144;
                M2C_FIELD(spawnedChild16, int*, 84) = 0;
                spawnedChild16->colour.a = value2;
                spawnedChild16->angle.yaw = value3;
            }
            childIndex17 += 1;
            childOffset20 += 0xC;
            if (childIndex17 >= 8) {

            } else {
                goto spawnNextChild;
            }
        }
        Desert807FCSpawnMobyFromValueSelector(moby, 0, 0, 0);
        func_8003BA00(moby);
        moby->unknown3[0] = 0;
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
        moby->unknownCollision = 0;
        moby->state = 3;
    }
    state3 = moby->state;
    switch (state3) {
        case 0:
            if ((M2C_FIELD(privateData19, void**, 8) != 0) &&
                (M2C_FIELD(&Desert807FC_D_80070328, int*, 0x50) == 0xD)) {
                value2 = Desert807FC_D_8006E03E;
                value2 -= 3500;
                angleDifference3 = value2 & 4095;
                if (angleDifference3 >= 0x801) {
                    angleDifference3 -= 0x1000;
                }
                absoluteAngle2 = angleDifference3;
                if (angleDifference3 < 0) {
                    absoluteAngle2 = -absoluteAngle2;
                }
                if (absoluteAngle2 >= 0x61) {
                    M2C_FIELD(privateData19, int*, 0x60) =
                        (int)(Desert807FC_D_8006C644 - M2C_FIELD(privateData19, int*, 0x58));
                }
            }
            value2 = Desert807FC_D_8006C644;
            argument5 = M2C_FIELD(privateData19, int*, 96);
            periodStart3 = M2C_FIELD(privateData19, int*, 88);
            period4 = M2C_FIELD(privateData19, int*, 92);
            value2 -= argument5;
            period4 = periodStart3 + period4;
            phaseRemainder5 = value2 % period4;
            if ((periodStart3 = phaseRemainder5 < periodStart3) ||
                (value2 = period4 - 32, value2 = phaseRemainder5 < value2, !value2)) {
                if (moby->substate != 1) {
                    pathData2 = M2C_FIELD(privateData19, void**, 8);
                    if (pathData2 != 0) {
                        value2 = M2C_FIELD(pathData2, short*, 2);
                        MATCHING_BARRIER_VOLATILE("memory");
                        M2C_FIELD(privateData19, int*, 12) = value2;
                    } else {
                        MATCHING_KEEP(pathData2);
                        M2C_FIELD(privateData19, int*, 0xC) = 0;
                    }
                    moby->state = 1;
                    func_80034F40(moby, 1);
                    goto updateParticles;
                }
                goto spawnParticles;
            }
            value2 = M2C_FIELD(privateData19, int*, 4);
            value3 = M2C_FIELD(privateData19, int*, 12);
            value2 += value3;
            value3 = M2C_FIELD(&Desert807FC_D_8006D048, int*, 20);
            value2 *= 4;
            value2 += value3;
            value2 = *(int*)value2;
            M2C_FIELD((void*)value2, int*, 4) = 0;
            Desert807FCMaskLinkedRecordFlagsById(
                M2C_FIELD(privateData19, int*, 0) + M2C_FIELD(privateData19, int*, 0xC), 0xFE, 1);
            moby->substate = 0;
            goto updateParticles;
        case 1:
            if (Desert807FCReadSelectedFrameScalar(moby) >= 0x10) {
                Desert807FCInterpolateMobyVertex(moby, 0, &originalStack.sp20);
                Desert807FCInterpolateMobyVertex(moby, 1, &originalStack.sp30);
                func_8004F194(&originalStack.sp20, &originalStack.sp20, &originalStack.sp30);
                Desert807FCShiftVectorRightTowardZero(&originalStack.sp20, 1);
                if (M2C_FIELD(privateData19, void**, 8) != 0) {
                    M2C_FIELD(&originalStack.sp40, signed char*, 0) =
                        (Desert807FC_rand() & 30) - 15;
                    M2C_FIELD(&originalStack.sp40, signed char*, 1) = 0;
                    M2C_FIELD(&originalStack.sp40, unsigned char*, 2) = moby->angle.yaw;
                    Desert807FCBuildPackedAngleBasisMatrix(&originalStack.sp40, &originalStack.sp48,
                                                           0);
                    originalStack.sp30.x = 0;
                    originalStack.sp30.y = 0;
                    originalStack.sp30.z = -0x40;
                    Desert807FCTransformVectorByBasis((SHORTMATRIX*)&originalStack.sp48,
                                                      &originalStack.sp30, &originalStack.sp30);
                } else {
                    tableOffset3 =
                        (((moby->angle.yaw + (Desert807FC_rand() & 0x1E)) - 0xF) & 0xFF) * 2;
                    value2 = M2C_FIELD(&Desert807FC_D_80065920, short*, tableOffset3);
                    MATCHING_KEEP(value2);
                    originalStack.sp30.x = value2 >> 6;
                    value2 = M2C_FIELD(&Desert807FC_D_800658A0, short*, tableOffset3);
                    MATCHING_KEEP(value2);
                    value3 = -12;
                    originalStack.sp30.z = value3;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                    originalStack.sp30.y = value2 >> 6;
                }
                SpawnParticle(1, 0x37, &originalStack.sp20, (Vector3D*)&originalStack.sp30);
                M2C_FIELD(*(int*)(((M2C_FIELD(privateData19, int*, 4) +
                                    M2C_FIELD(privateData19, int*, 0xC)) *
                                   4) +
                                  M2C_FIELD(&Desert807FC_D_8006D048, int*, 0x14)),
                          int*, 4) = 1;
                Desert807FCMaskLinkedRecordFlagsById(M2C_FIELD(privateData19, int*, 0) +
                                                         M2C_FIELD(privateData19, int*, 0xC),
                                                     0xFC, 0);
                moby->substate = 1;
            }
            if (Desert807FC_D_8006C770 != 0) {
                queryPath5 = M2C_FIELD(privateData19, void**, 8);
                if ((queryPath5 != 0) &&
                    (Desert807FCGetClosestPathNode(&Desert807FC_D_80070328, queryPath5,
                                                   &originalStack.sp60),
                     pathDataAfterCall2 = M2C_FIELD(privateData19, void**, 8),
                     M2C_FIELD(pathDataAfterCall2, short*, 0xA) =
                         (short)(originalStack.sp60 -
                                 (unsigned short)M2C_FIELD(pathDataAfterCall2, short*, 2)),
                     stepData3 = M2C_FIELD(privateData19, void**, 8),
                     pathStep2 = M2C_FIELD(stepData3, short*, 0xA), (pathStep2 != 0))) {
                    if (pathStep2 < -1) {
                        M2C_FIELD(stepData3, short*, 0xA) = -1;
                    }
                    if (M2C_FIELD(M2C_FIELD(privateData19, void**, 8), short*, 0xA) >= 2) {
                        M2C_FIELD(M2C_FIELD(privateData19, void**, 8), short*, 0xA) = 1;
                    }
                    M2C_FIELD(M2C_FIELD(privateData19, void**, 8), unsigned short*, 2) =
                        (unsigned short)(M2C_FIELD(M2C_FIELD(privateData19, void**, 8),
                                                   unsigned short*, 2) +
                                         M2C_FIELD(M2C_FIELD(privateData19, void**, 8),
                                                   unsigned short*, 0xA));
                    moby->state = 2;
                    func_80034F40(moby, 2);
                } else {
                    moby->state = 0;
                    func_80034F40(moby, 0);
                }
            }
            goto updateParticles;
        case 2:
            if (Desert807FC_D_8006C770 != 0) {
                completedPath2 = M2C_FIELD(privateData19, void**, 8);
                func_8004F178(&moby->position, M2C_FIELD(completedPath2, int*, 0xC) +
                                                   (M2C_FIELD(completedPath2, short*, 2) * 0x10));
                moby->state = 0;
                func_80034F40(moby, 0);
            } else {
                value2 = Desert807FCReadSelectedFrameScalar(moby);
                vector17 = &originalStack.sp40;
                argument4 = (int)vector17;
                MATCHING_KEEP(argument4);
                activePath3 = M2C_FIELD(privateData19, void**, 8);
                animationFrame16 = value2;
                pathIndex6 = M2C_FIELD(activePath3, short*, 2);
                pathPositions7 = M2C_FIELD(activePath3, int*, 12);
                value3 = M2C_FIELD(activePath3, short*, 10);
                MATCHING_KEEP3_CLOBBER(value3, pathIndex6, pathPositions7, "$5");
                argument5 = pathIndex6 * 16;
                argument5 = pathPositions7 + argument5;
                argument6 = pathIndex6 - value3;
                MATCHING_KEEP(argument6);
                argument6 *= 16;
                argument6 = pathPositions7 + argument6;
                Desert807FCSubtractVector(argument4, argument5, argument6, pathPositions7);
                originalStack.sp48 = 0;
                originalStack.sp40 = (originalStack.sp40 * animationFrame16) / 20;
                originalStack.sp44 = (originalStack.sp44 * animationFrame16) / 20;
                interpolationPath2 = M2C_FIELD(privateData19, void**, 8);
                func_8004F194(&moby->position, (Vector3D*)&originalStack.sp40,
                              M2C_FIELD(interpolationPath2, int*, 0xC) +
                                  ((M2C_FIELD(interpolationPath2, short*, 2) -
                                    M2C_FIELD(interpolationPath2, short*, 0xA)) *
                                   0x10));
            }
            Desert807FCRefreshMobySpatialGridAndBasis(moby, 2);
            goto updateParticles;
        case 3:
            value2 = M2C_FIELD(privateData19, int*, 4);
            value3 = M2C_FIELD(privateData19, int*, 12);
            value2 += value3;
            value3 = M2C_FIELD(&Desert807FC_D_8006D048, int*, 20);
            value2 *= 4;
            value2 += value3;
            value2 = *(int*)value2;
            M2C_FIELD((void*)value2, int*, 4) = 0;
            Desert807FCMaskLinkedRecordFlagsById(
                M2C_FIELD(privateData19, int*, 0) + M2C_FIELD(privateData19, int*, 0xC), 0xFE, 1);
            if (Desert807FCQueryShiftedLinkedRecordWordByByteId(
                    M2C_FIELD(privateData19, int*, 0) + M2C_FIELD(privateData19, int*, 0xC)) &
                2) {
                Desert807FCDeleteMoby(moby);
                return;
            }
            goto updateParticles;
        default:
            goto updateParticles;
    }
updateParticles:
    if (moby->substate == 1) {
    spawnParticles:
        originalStack.sp68 = 0;
        originalStack.sp6C = 0;
        originalStack.sp70 = 8;
        if (M2C_FIELD(privateData19, void**, 8) != 0) {
            firstRandom16 = Desert807FC_rand() & 255;
            MATCHING_KEEP(firstRandom16);
            firstRandom16 -= 128;
            unk_ovlheader_800743E4(
                (Vector3D*)&originalStack.sp40, firstRandom16, (Desert807FC_rand() & 0xFF) - 0x80,
                privateData19 + ((M2C_FIELD(privateData19, int*, 0xC) * 0x18) + 0x10));
            value2 = M2C_FIELD(privateData19, int*, 8);
            value3 = M2C_FIELD((void*)value2, short*, 2);
            argument5 = moby->position.z;
            value2 = value3 * 24;
            value2 = (int)privateData19 + value2;
            argument4 = M2C_FIELD((void*)value2, int*, 24);
            originalStack.sp48 = func_8003636C(argument4, argument5);
        } else {
            secondRandom16 = Desert807FC_rand() & 255;
            MATCHING_KEEP(secondRandom16);
            secondRandom16 -= 128;
            unk_ovlheader_800743E4((Vector3D*)&originalStack.sp40, secondRandom16,
                                   (Desert807FC_rand() & 0xFF) - 0x80, privateData19 + 0x10);
        }
        SpawnParticle(1, 0xD, (Vector3D*)&originalStack.sp40, (Vector3D*)&originalStack.sp68);
    }
    return;
}
#undef M2C_FIELD

/* Rev1 raw965 supplies the route; Rev0 instructions pin every field and call. */
typedef struct {
    void* helperArgument;
    int fragmentClass, fragmentCount;
    Vector3D* offsets;
    unsigned char bounds[24];
    int poolIndex;
} DecodedGateFragmentTag;
typedef struct {
    unsigned char reserved00[0x24];
    int timer;
    unsigned char reserved28[0x10];
    void* attachment;
} DecodedGateFragmentPrivate;
extern unsigned char DecodedGateFragmentFlags __asm__("D_8006C7B4");
extern int DecodedGateFragmentIndex __asm__("D_8006C58C");
extern unsigned char DecodedGateFragmentBytes[] __asm__("D_80070300");
extern int DecodedGateFragmentFrame __asm__("D_8006C640");
extern Vector3D DecodedGateFragmentPlayer __asm__("D_80070328");
extern int DecodedGateFragmentPlayerMode __asm__("D_80070328 + 0x20C");
extern int DecodedGateFragmentInput __asm__("D_8006E048");
extern Moby* DecodedGateFragmentPool __asm__("D_8006C550");
void DecodedGateFragmentHelper(void*, int, int) __asm__("func_80021ED8");
int DecodedGateFragmentBounds(Vector3D*, void*, int, int) __asm__("func_80036220");
void DecodedGateFragmentRange(void*, void*) __asm__("func_80013AE4");
void DecodedGateFragmentOwner(Moby*, int, int) __asm__("func_8003BB10");
void DecodedGateFragmentRelease(Moby*) __asm__("func_80055B18");
void func_level_42_80081010(Moby* moby) {
    DecodedGateFragmentTag* tag = moby->mobyTag;
    DecodedGateFragmentPrivate* otherPrivate;
    void* range;
    if ((DecodedGateFragmentFlags & 1) ||
        (DecodedGateFragmentBytes[DecodedGateFragmentIndex] & 1)) {
        DecodedGateFragmentHelper(tag->helperArgument, 252, 0);
        if (DecodedGateFragmentFrame >= 11 && tag->fragmentCount > 0)
            SpawnFragments(tag->fragmentCount, tag->fragmentClass, moby, tag->offsets, 0, 512);
        goto release;
    }
    if (!DecodedGateFragmentBounds(&DecodedGateFragmentPlayer, tag->bounds, 0, 0))
        return;
    otherPrivate = 0;
    if (tag->poolIndex != -1) {
        otherPrivate = DecodedGateFragmentPool[tag->poolIndex].mobyTag;
        range = *(void**)((char*)otherPrivate->attachment + 12);
        DecodedGateFragmentRange(range, (char*)range + 16);
        DecodedGateFragmentPlayerMode = 0x10000002;
    }
    if (!(DecodedGateFragmentInput & 1) && tag->poolIndex != -1)
        return;
    DecodedGateFragmentHelper(tag->helperArgument, 252, 0);
    if (DecodedGateFragmentFrame >= 11 && tag->fragmentCount > 0) {
        SpawnFragments(tag->fragmentCount, tag->fragmentClass, moby, tag->offsets, 0, 512);
        DecodedGateFragmentOwner(moby, 5, 1);
    }
    if (tag->poolIndex != -1) {
        DecodedGateFragmentPool[tag->poolIndex].substate = 3;
        /* Retail writes through the earlier indexed actor private pointer. */
        otherPrivate->timer = 120;
    }
release:
    DecodedGateFragmentRelease(moby);
}

extern int D_8006E160;
void func_level_42_80081240(Moby* moby) {
    void* tag = moby->mobyTag;
    switch (moby->state) {
        case 0: {
            register int* state __asm__("$4") = &spyro.movementState;
            MATCHING_KEEP(state);
            if (*state == 0xD && func_80036220((Vector3D*)((char*)state - 0x50), tag, 0, 0))
                moby->state = 1;
            break;
        }
        case 1: {
            register int* requested __asm__("$17") = &D_8006E160;
            MATCHING_KEEP(requested);
            if (!*requested)
                func_80013ACC(moby, 0x10);
            if (*requested == 0x10 && spyro.movementState != 0xD && spyro.movementState != 3 &&
                spyro.movementState != 7)
                func_80013ACC(0, 0);
            break;
        }
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
void func_level_42_8008131C(Moby* mobyArgument) {
    Vector3D offset;
    int reserved24;
    Vector3D direction;
    int reserved34[3];
    register Moby* moby __asm__("$20") = mobyArgument;
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
void func_level_42_80081754(Moby* moby) {
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
void func_level_42_80081A84(Moby* mobyArgument) {
    Vector3D difference;
    int kind;
    register Moby* moby __asm__("$17") = mobyArgument;
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
void func_level_42_80081FAC(void* input) {
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

#undef Controller821F8Field

void func_level_42_80083100(Moby* moby) {
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
void func_level_42_80083120(Moby* mobyArgument) {
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

extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_42_80083320(Moby* moby) {
    if (D_8006C770 != 0)
        func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Native C matched against original instructions. Original source asm/nonmatchings/overlays/level_42/moby/func_level_42_8008334C.s SHA256 df432a40d9aefd9b64bcedc53471823cb2887df7ba5fb369083a5576556cb57d. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Bulk5233_25QueryWorldHeight() __asm__("func_8001A358");               /* extern */
int Bulk5233_25SetMobyAnimation() __asm__("func_80034F80");               /* extern */
int Bulk5233_25SpawnMobyFromValueSelector() __asm__("func_80036A68");     /* extern */
int Bulk5233_25TransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Bulk5233_25ShiftVectorRightTowardZero() __asm__("func_8004F110");     /* extern */
int Bulk5233_25ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Bulk5233_25DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Bulk5233_25RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Bulk5233_25ReadSelectedFrameScalar() __asm__("func_80055E84");        /* extern */
int Bulk5233_25InterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
extern unsigned char Bulk5233_25_D_800658A0 __asm__("D_800658A0");
extern unsigned char Bulk5233_25_D_80065920 __asm__("D_80065920");
extern int Bulk5233_25_D_8006C550 __asm__("D_8006C550");
extern int Bulk5233_25_D_8006C574 __asm__("D_8006C574");
extern int Bulk5233_25_D_8006C578 __asm__("D_8006C578");
extern int Bulk5233_25_D_8006C770 __asm__("D_8006C770");
extern Vector3D Controller334CVector98 __asm__("D_80070328+0x98");
extern Vector3D Bulk5233_25_D_80070328 __asm__("D_80070328");

void func_level_42_8008334C(Moby* moby) {
    struct {
        Vector3D sp10;
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
    } originalStack;

    register Moby* arg0 __asm__("$18") = moby;

    register Moby* temp_v0_8 __asm__("$16");
    register Vector3D* temp_s1 __asm__("$17");
    int temp_a0;
    register int temp_a0_2 __asm__("$4");
    register int temp_s6 __asm__("$22");
    register int temp_v0_2 __asm__("$2");
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    register int temp_v0_6 __asm__("$4");
    register int temp_v0_7 __asm__("$2");
    register int temp_v1_2 __asm__("$3");
    int temp_v1_3;
    register int temp_v1_4 __asm__("$3");
    register int var_a1 __asm__("$5");
    register int var_s0 __asm__("$16");
    register int var_s1 __asm__("$17");
    register int var_s3 __asm__("$19");
    register int var_s3_2 __asm__("$19");
    register int var_s5 __asm__("$21");
    register int var_v0 __asm__("$2");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register Vector3D* argument6 __asm__("$6");
    register Vector3D* argument7 __asm__("$7");
    unsigned char temp_v1;
    register void* temp_s4 __asm__("$20");
    register void* temp_v0 __asm__("$2");
    register Vector3D* vector16 __asm__("$16");
    register Vector3D* vector17 __asm__("$17");
    register Vector3D* global16 __asm__("$16");
    register int index2 __asm__("$2");
    register int sample4 __asm__("$4");
    register int sample3 __asm__("$3");

    MATCHING_KEEP(arg0);
    temp_a0 = arg0->damageFlags;
    temp_s4 = arg0->mobyTag;
    if (!(temp_a0 & 0x10000)) {
        if (M2C_FIELD(&Bulk5233_25_D_80070328, int*, 0x24C) == 1) {
            if (temp_a0 == 0) {
                argument4 = (int)arg0;
                goto normalArgsReady;
            }
            argument4 = (int)arg0;
            MATCHING_KEEP_VOLATILE(argument4);
        } else
            goto block_10;
    }
block_3:
    func_8003BABC(arg0, 0, 0);
    var_s1 = 0;
    var_s3_2 = 0;
loop_4:
    argument4 = 0x1D3;
    if ((Bulk5233_25_D_8006C578 - Bulk5233_25_D_8006C574) >= 0x15) {
        temp_v0_8 = SpawnMoby(argument4, arg0);
        argument4 = (int)temp_v0_8;
        if (temp_v0_8 != 0) {
            MATCHING_KEEP(temp_v0_8);
            M2C_FIELD(temp_v0_8->mobyTag, short*, 0x12) = 1;
            Bulk5233_25SetMobyAnimation(argument4, var_s1);
            func_8004F178(&originalStack.sp10, M2C_FIELD(temp_s4, int*, 0x1C) + var_s3_2);
            Bulk5233_25TransformVectorByBasis(&arg0->rotationMatrix, &originalStack.sp10,
                                              &originalStack.sp10);
            func_8004F194(&temp_v0_8->position, &arg0->position, &originalStack.sp10);
            temp_v0_8->angle.roll = arg0->angle.roll;
            temp_v0_8->angle.pitch = arg0->angle.pitch;
            temp_v0_8->angle.yaw = arg0->angle.yaw;
        }
        var_s1 += 1;
        var_s3_2 += 0xC;
        if (var_s1 < 0xA) {
            goto loop_4;
        }
    }
    Bulk5233_25SpawnMobyFromValueSelector(arg0, 1, 0, 0);
    func_8003BA00(arg0);
    Bulk5233_25DeleteMoby(arg0);
    return;
block_10:
    argument4 = (int)arg0;
    MATCHING_OBSERVE_VOLATILE(argument4);
normalArgsReady:
    /* Original A0 producer: 800833A4 branch delay supplies owner on
         * the zero-word path; 800834A8 supplies owner on the other path.
         * Capture the proven common value at original 800834AC. */
    __asm__("" : "=r"(argument4));
    func_8003573C(argument4, 8, 0, 1);
    vector16 = &originalStack.sp20;
    argument4 = (int)vector16;
    MATCHING_KEEP(argument4);
    temp_s1 = &Controller334CVector98;
    func_8004F178(argument4, temp_s1);
    originalStack.sp20.x *= 30;
    originalStack.sp20.y *= 0x1E;
    originalStack.sp20.z *= 0x1E;
    Bulk5233_25ShiftVectorRightTowardZero(vector16, 6);
    func_8004F194(vector16, vector16, (Vector3D*)((char*)temp_s1 - 0x98));
    temp_a0_2 = Bulk5233_25ApproximatePlanarDistance(&arg0->position, vector16);
    temp_v1 = arg0->state;
    switch (temp_v1) { /* irregular */
        case 0:
            if ((var_v0 = temp_a0_2 < 0x2800)) {
                if (M2C_FIELD(temp_s4, int*, 8) == 0) {
                    arg0->state = 1;
                    argument4 = (int)arg0;
                    MATCHING_KEEP(argument4);
                    var_a1 = 1;
                    goto block_32;
                }
            }
            break;
        case 1:
            if (Bulk5233_25_D_8006C770 != 0) {
                arg0->state = 2;
                argument4 = (int)arg0;
                MATCHING_KEEP(argument4);
                var_a1 = 2;
                goto block_32;
            }
            break;
        case 2:
            if (temp_a0_2 < 0x1800) {
                arg0->state = 3;
                argument4 = (int)arg0;
                MATCHING_KEEP(argument4);
                var_a1 = 3;
                goto block_32;
            }
            if (!(var_v0 = temp_a0_2 < 0x3001)) {
                arg0->state = 0;
                goto block_31;
            }
            break;
        case 3:
            if ((Bulk5233_25ReadSelectedFrameScalar(arg0) >= 0xA) &&
                (M2C_FIELD(temp_s4, int*, 8) == 0)) {
                Bulk5233_25InterpolateMobyVertex(arg0, 0, temp_s4 + 0x10);
                M2C_FIELD(temp_s4, int*, 8) = 0xC0;
            }
            if (Bulk5233_25_D_8006C770 != 0) {
                arg0->state = 0;
                goto block_31;
            }
            break;
    }
    goto afterState;
block_31:
    argument4 = (int)arg0;
    var_a1 = 0;
block_32:
    func_80034F40(argument4, var_a1);
afterState:
    Bulk5233_25RefreshMobySpatialGridAndBasis(arg0, 4);
    temp_v1_2 = M2C_FIELD(temp_s4, int*, 4);
    if (temp_v1_2 >= 0) {
        index2 = temp_v1_2 * 0x58;
        sample3 = Bulk5233_25_D_8006C550;
        temp_v0 = (void*)(index2 + sample3);
        MATCHING_KEEP(temp_v0);
        sample3 = M2C_FIELD(temp_v0, int*, 0x14);
        temp_v0 = M2C_FIELD(temp_v0, void**, 0);
        arg0->position.z = sample3 + 0x1000;
        if (M2C_FIELD(temp_v0, int*, 0x10) >= 0x1000) {
            arg0->damageFlags |= 0x10000;
        }
    }
    temp_v0_2 = M2C_FIELD(temp_s4, int*, 8);
    temp_s6 = temp_v0_2 * 2;
    if (temp_v0_2 != 0) {
        if (temp_s6 < 0x1000) {
            var_v0 = 0x1000;
            MATCHING_KEEP(var_v0);
            var_s5 = var_v0 - temp_s6;
        } else {
            var_s5 = 0;
        }
        var_s3 = 0;
        originalStack.sp30 = 0;
        originalStack.sp34 = 0;
        originalStack.sp38 = 8;
        index2 = arg0->angle.yaw;
        MATCHING_KEEP_CLOBBER(index2, "memory");
        vector17 = (Vector3D*)&originalStack.sp40;
        var_s0 = index2 - 0xC;
        do {
            temp_v0_3 = ((var_s0 + func_8003636C(0, 3)) & 0xFF) * 2;
            index2 = temp_v0_3;
            sample4 = M2C_FIELD(&Bulk5233_25_D_80065920, short*, index2);
            MATCHING_KEEP(sample4);
            originalStack.sp40 = (sample4 * M2C_FIELD(temp_s4, int*, 8)) >> 12;
            sample3 = M2C_FIELD(&Bulk5233_25_D_800658A0, short*, index2);
            MATCHING_KEEP(sample3);
            index2 = M2C_FIELD(temp_s4, int*, 8);
            MATCHING_KEEP(index2);
            originalStack.sp48 = 0;
            originalStack.sp44 = (sample3 * index2) >> 12;
            func_8004F194(vector17, vector17, temp_s4 + 0x10);
            temp_v1_3 = arg0->position.z;
            originalStack.sp48 = temp_v1_3;
            if (M2C_FIELD(temp_s4, int*, 0) != 0) {
                originalStack.sp48 = temp_v1_3 + 0x200;
                temp_v0_4 = Bulk5233_25QueryWorldHeight(vector17, 0x400);
                originalStack.sp48 = temp_v0_4;
                if (temp_v0_4 == 0) {
                    originalStack.sp48 = arg0->position.z;
                }
            }
            temp_v0_5 = originalStack.sp48 + 0x80;
            originalStack.sp48 = temp_v0_5;
            if (var_s5 != 0) {
                originalStack.sp48 =
                    (int)((temp_s6 * temp_v0_5) + (var_s5 * M2C_FIELD(temp_s4, int*, 0x18))) >> 0xC;
            }
            argument4 = 1;
            argument5 = 32;
            argument6 = (Vector3D*)&originalStack.sp40;
            argument7 = (Vector3D*)&originalStack.sp30;
            MATCHING_OBSERVE4(argument4, argument5, argument6, argument7);
            var_s0 += 3;
            var_s3 += 1;
            SpawnParticle(argument4, argument5, argument6, argument7);
        } while (var_s3 < 8);
        global16 = &Bulk5233_25_D_80070328;
        temp_v0_6 = Bulk5233_25ApproximatePlanarDistance(global16, temp_s4 + 0x10);
        temp_v1_4 = M2C_FIELD(temp_s4, int*, 8);
        if ((temp_v0_6 < (temp_v1_4 + 0x200)) && ((var_v0 = temp_v1_4 - 0x200) < temp_v0_6)) {
            var_v0 = ((arg0->position.z - arg0->distanceToGround) - Bulk5233_25_D_80070328.z) +
                     M2C_FIELD(&Bulk5233_25_D_80070328, int*, 0x44);
            if (var_v0 < 0) {
                var_v0 = -var_v0;
            }
            if ((var_v0 < 0x200) &&
                (func_8004F264((int)arg0->angle.yaw,
                               func_8004E880(global16->x - arg0->position.x,
                                             Bulk5233_25_D_80070328.y - arg0->position.y, 0)) <
                 0xC)) {
                M2C_FIELD(&Bulk5233_25_D_80070328, int*, 0x24) =
                    (int)(M2C_FIELD(&Bulk5233_25_D_80070328, int*, 0x24) | 0xE);
            }
        }
        temp_v0_7 = M2C_FIELD(temp_s4, int*, 8) + 0xC0;
        M2C_FIELD(temp_s4, int*, 8) = temp_v0_7;
        if (temp_v0_7 >= 0x1001) {
            M2C_FIELD(temp_s4, int*, 8) = 0;
        }
    }
    return;
}
#undef M2C_FIELD

void func_level_42_80083940(Moby* moby) {
    if (spyro.critterMode == 1) {
        int difference = spyro.position.y - moby->position.y;
        if (spyro.unk17a == 0) {
            spyro.unk17a = 0x10000008;
            spyro.unk17e.x = 0;
            spyro.unk17e.y = -difference;
            spyro.unk17e.z = 0;
        }
    }
}
