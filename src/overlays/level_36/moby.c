#include "matching.h"
#include "common.h"
#include "spu.h"
#include "savepoint.h"
#include "moby/mobytag.h"
#include "spyro.h"
#include "stdutil.h"
#include "ovl_header.h"
extern int func_80039714(Moby*);

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
void func_level_36_80074AD0(void* input) {
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
void func_level_36_8007572C(Moby* mobyArgument) {
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
void func_level_36_80075DB8(void* input) {
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
void func_level_36_80077308(Moby* moby) {
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
void func_level_36_800775C8(Moby* mobyArgument) {
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
void func_level_36_80077AE8(Moby* moby) {
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
void func_level_36_80077DEC(void* input) {
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
void func_level_36_80078960(Moby* moby) {
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
void func_level_36_80078D90(Moby* owner) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Controller7CAA0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller7CAA0D_800652B0[] __asm__("D_800652B0");
extern unsigned char Controller7CAA0D_800652B4[] __asm__("D_800652B4");
extern unsigned char Controller7CAA0D_800652B6[] __asm__("D_800652B6");
extern unsigned char Controller7CAA0D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller7CAA0D_80065920[] __asm__("D_80065920");
extern unsigned char Controller7CAA0D_80068F7C[] __asm__("D_80068F7C");
extern unsigned char Controller7CAA0D_80068F90[] __asm__("D_80068F90");
extern unsigned char Controller7CAA0D_8006C7F8[] __asm__("D_8006C7F8");
extern unsigned char Controller7CAA0D_8006D088[] __asm__("D_8006D088");
extern unsigned char Controller7CAA0D_80070328[] __asm__("D_80070328");
extern unsigned char Controller7CAA0D_800719A8[] __asm__("D_800719A8");
extern unsigned char Controller7CAA0D_800719F0[] __asm__("D_800719F0");
extern int Controller7CAA0D_8006C3F4 __asm__("D_8006C3F4");
extern int Controller7CAA0D_8006C4F8 __asm__("D_8006C4F8");
extern int Controller7CAA0D_8006C598 __asm__("D_8006C598");
extern int Controller7CAA0D_8006C640 __asm__("D_8006C640");
extern int Controller7CAA0D_8006C6D0 __asm__("D_8006C6D0");
extern int Controller7CAA0D_8006C6E0 __asm__("D_8006C6E0");
extern int Controller7CAA0D_8006E344 __asm__("D_8006E344");
extern int Controller7CAA0D_800719BC __asm__("D_800719BC");
extern int Controller7CAA0D_800719C0 __asm__("D_800719C0");
extern int Controller7CAA0D_800719C4 __asm__("D_800719C4");
extern unsigned char Controller7CAA0D_80071577 __asm__("D_80071577");
int Controller7CAA0CopyCameraPositionWithWrappedAngle(void*, void*, int) __asm__("func_800135A4");
int Controller7CAA0RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Controller7CAA0SetMobyAnimation(void*, int) __asm__("func_80034F80");
int Controller7CAA0TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Controller7CAA0CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller7CAA0ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
int Controller7CAA0ResolveMobyYawStep(void*, int, int, int, int) __asm__("func_80035DDC");
int Controller7CAA0UpdateMobyInteractionGate(void*, int) __asm__("func_80037BBC");
int Controller7CAA0RestoreOrClearTrackedSnapshot(void*) __asm__("func_8003B74C");
int Controller7CAA0RegisterTrackedValue(void*, int, void*) __asm__("func_8003B7B4");
int Controller7CAA0PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller7CAA0TransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Controller7CAA0SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Controller7CAA0ConfigurePrimaryRangeRequest(int, int, int) __asm__("func_8004F984");
int Controller7CAA0StartDialogue(void*, int, int) __asm__("func_800512E4");
int Controller7CAA0RefreshMobyPackedQueryField(void*) __asm__("func_8005629C");
extern int (*Controller7CAA0SpawnMoby)(int, void*) __asm__("SpawnMoby");
extern int (*Controller7CAA0unk_ovlheader_80074318)(void*, int) __asm__("unk_ovlheader_80074318");
extern int (*Controller7CAA0unk_ovlheader_80074320)(void*, int,
                                                    void*) __asm__("unk_ovlheader_80074320");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level24/8007CAA0 and level41/8007C604, each 307 original words.
 * Original symbols match except the flag store: D_80071577 in level24 and
 * D_80071590 in level41. Preserve that per-copy symbol; no owned table rows.
 * Four state paths retain unsigned resource halfwords, signed table samples
 * multiplied by 13 then shifted by 5, six-argument stack layout, byte rereads,
 * helper/callback arguments and original signed high-product division.
 * Divide producer: word shifted left 4, signed MULT by 0x88888889,
 * high word added to numerator, arithmetic shift 11 minus sign word.
 * Units, helper semantics and invocation cadence remain unresolved. Updates
 * occur once per invocation. Confidence: exact original native/linked words
 * and full retail hashes, not semantic runtime review. Falsifiable vectors:
 * all 614 original words, per-copy flag relocations and complete SHA set.
 * Empty constraints preserve original scheduling without opcode patches.
 */
extern unsigned char Controller7CAA0D_8006C7B4 __asm__("D_8006C7B4");
extern int Controller7CAA0D_8006C58C __asm__("D_8006C58C");
extern unsigned char Controller7CAA0D_80070300[] __asm__("D_80070300");
extern unsigned char* Controller7CAA0D_8006C550 __asm__("D_8006C550");
int Controller7CAA0PreparePortalLevelTransition() __asm__("func_80053F50");
int Controller7CAA0WriteTrackedSnapshot() __asm__("func_8003B634");
void func_level_36_80078F1C(void* input) {
    register unsigned char* owner __asm__("$18") = input;
    int resourceStart;
    int desiredAnimation;
    int callbackValue;
    unsigned char state;
    unsigned char previousAnimation;
    register void* tag __asm__("$16");
    register void* stateAddress __asm__("$16");
    register void* nextStateAddress __asm__("$16");

    ((Moby*)owner)->updateDistance = 0xFF;
    tag = ((Moby*)owner)->mobyTag;
    if ((Controller7CAA0D_8006C640 > 0) && (Controller7CAA0Field(tag, int*, 0x60) == 0)) {
        resourceStart =
            Controller7CAA0D_8006C3F4 + Controller7CAA0Field(Controller7CAA0D_800652B0, int*, 0xE0);
        Controller7CAA0ConfigurePrimaryRangeRequest(
            resourceStart,
            resourceStart + Controller7CAA0Field(Controller7CAA0D_800652B4, unsigned short*, 0xE0),
            Controller7CAA0Field(Controller7CAA0D_800652B6, unsigned short*, 0xE0));
        Controller7CAA0Field(tag, int*, 0x60) = 1;
    }
    state = ((Moby*)owner)->state;
    switch (state) { /* irregular */
        case 0:
            if ((Controller7CAA0Field(tag, unsigned char*, 2) == 1) &&
                !(Controller7CAA0D_8006C7B4 & 1) &&
                !(Controller7CAA0D_80070300[Controller7CAA0D_8006C58C] & 1)) {
                Controller7CAA0Field(tag, unsigned char*, 2) = 4;
            }
            {
            initializeTag:
                ((Moby*)owner)->distanceToGround = 0;
                Controller7CAA0Field(tag, signed char*, 5) = 1;
                if ((Controller7CAA0D_8006C598 == 0) &&
                    (Controller7CAA0UpdateMobyInteractionGate(owner, 0) != 0)) {
                    Controller7CAA0StartDialogue(owner, 0, 0xD);
                    ((Moby*)owner)->state = 0xDU;
                }
            }
            break;
        case 13:
            if (Controller7CAA0D_8006E344 != 1) {
                Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0x20C) = 0x10000002;
                if ((Controller7CAA0Field(tag, unsigned char*, 4) == 2) ||
                    (Controller7CAA0Field(tag, unsigned char*, 4) == 5)) {
                    Controller7CAA0PreparePortalLevelTransition(-1);
                    break;
                }
                Controller7CAA0WriteTrackedSnapshot(
                    Controller7CAA0D_8006D088,
                    Controller7CAA0D_8006C550 + Controller7CAA0Field(tag, int*, 0x44) * 88 + 12,
                    Controller7CAA0Field(Controller7CAA0D_8006C550 +
                                             Controller7CAA0Field(tag, int*, 0x44) * 88,
                                         unsigned char*, 0x46));
                Controller7CAA0Field(tag, int*, 0x58) = 0x3C;
                ((Moby*)owner)->state = 1U;
                Controller7CAA0RequestMobyAnimation(owner, 1);
            }
            break;
        case 1:
            Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0x20C) = 0x10000002;
            if (Controller7CAA0TurnMobyTowardHeading(owner,
                                                     Controller7CAA0Field(tag, int*, 0x34) + 0x80,
                                                     8, 0x10, (int)state, 0) != 0) {
                Controller7CAA0ResolveMobyYawStep(owner, 0x80, 0, 0, 0);
            }
            if (Controller7CAA0CountTimerDown(tag + 0x58, 4) == 2) {
                nextStateAddress = owner + 0x48;
                ((Moby*)owner)->state = 3U;
                Controller7CAA0RegisterTrackedValue(nextStateAddress, 1, Controller7CAA0D_8006D088);
                Controller7CAA0RegisterTrackedValue(nextStateAddress, 1, Controller7CAA0D_8006C7F8);
                Controller7CAA0RestoreOrClearTrackedSnapshot(Controller7CAA0D_8006D088);
                ((Moby*)owner)->state = 1U;
            }
            break;
        case 3:
            Controller7CAA0unk_ovlheader_80074318(owner, 0x55);
            Controller7CAA0D_8006C6D0 = 0x100;
            Controller7CAA0CopyCameraPositionWithWrappedAngle(Controller7CAA0D_800719A8,
                                                              Controller7CAA0D_80068F7C, 0);
            Controller7CAA0CopyCameraPositionWithWrappedAngle(Controller7CAA0D_800719F0,
                                                              Controller7CAA0D_80068F90, 0);
            if ((Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0x24C) == 2) &&
                (previousAnimation = ((Moby*)owner)->animationState.nextId,
                 desiredAnimation =
                     Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0x48) - 0x55,
                 (desiredAnimation != previousAnimation))) {
                if ((unsigned int)(previousAnimation - 0xB) < 2U) {
                    Controller7CAA0SetMobyAnimation(owner, desiredAnimation);
                } else {
                    Controller7CAA0RequestMobyAnimation(owner, desiredAnimation);
                }
                if (Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0x48) == 0x5B) {
                    Controller7CAA0SpawnMoby(0x41, owner);
                }
                Controller7CAA0Field(tag, int*, 0x48) = 0;
            } else if (({
                           MATCHING_BARRIER_VOLATILE("memory");
                           ((Moby*)owner)->animationState.nextId;
                       }) == 1) {
                {
                    register int numerator __asm__("$3") =
                        Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0xB4);
                    if (numerator != 0) {
                        register int multiplier __asm__("$2") = (int)0x88888889;
                        register int high __asm__("$8");
                        register int quotient __asm__("$2");
                        MATCHING_KEEP(multiplier);
                        numerator <<= 4;
                        __asm__ volatile("" : "=h"(high) : "l"(numerator * multiplier) : "memory");
                        MATCHING_KEEP(high);
                        quotient = high + numerator;
                        quotient >>= 11;
                        numerator >>= 31;
                        callbackValue = quotient - numerator;
                    } else {
                        MATCHING_BARRIER_VOLATILE("$5");
                        callbackValue = 8;
                    }
                }
                Controller7CAA0unk_ovlheader_80074320(owner, callbackValue, tag + 0x48);
            }
            if (Controller7CAA0Field(Controller7CAA0D_80070328, int*, 0x48) == 0x5B) {
                if (Controller7CAA0SoundHandleMatchesOwnerInStates1Or2(
                        owner, Controller7CAA0Field(tag, int*, 0x5C)) == 0) {
                    Controller7CAA0Field(tag, int*, 0x5C) =
                        Controller7CAA0PlayMobySoundEvent(owner, 0, 4);
                }
            } else {
                if (Controller7CAA0SoundHandleMatchesOwnerInStates1Or2(
                        owner, Controller7CAA0Field(tag, int*, 0x5C)) != 0) {
                    Controller7CAA0TransitionSoundHandleTo3Or5(
                        Controller7CAA0Field(tag, int*, 0x5C));
                }
                Controller7CAA0Field(tag, int*, 0x5C) = -1;
            }
            break;
    }
    Controller7CAA0ProbeGroundFromRaisedMoby(owner);
    Controller7CAA0RefreshMobyPackedQueryField(owner);
}

extern Moby* D_8006C550;
void func_80055B18(Moby*);
void func_level_36_8007938C(Moby* moby) {
    Moby* linked;

    linked = &D_8006C550[moby->linkedMoby];
    if (linked->animationState.nextId != 6) {
        func_80055B18(moby);
        return;
    }
    func_8004F178(&moby->position, &linked->position);
    moby->angle.roll = linked->angle.roll;
    moby->angle.pitch = linked->angle.pitch;
    moby->angle.yaw = linked->angle.yaw;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller79430QueryWorldHeight() __asm__("func_8001A358"); /* extern */
int Controller79430SetMobyAnimation() __asm__("func_80034F80"); /* extern */
int Controller79430DeleteMoby() __asm__("func_80055B18");       /* extern */
extern int Controller79430_D_8006C550 __asm__("D_8006C550");

void func_level_36_80079430(Moby* moby) {
    register Moby* arg0 __asm__("$19") = moby;
    Vector3D sp18;
    Vector3D sp28;
    Vector3D sp38;
    Vector3D sp48;
    register Moby* var_s1 __asm__("$17");
    register int temp_a0_3 __asm__("$4");
    register Moby* (*spawn2)(int, Moby*)__asm__("$2");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int temp_v0 __asm__("$2");
    int temp_v0_10;
    register int temp_v0_2 __asm__("$3");
    int temp_v0_4;
    register int temp_v0_5 __asm__("$2");
    int temp_v0_7;
    register int temp_v0_9 __asm__("$2");
    int temp_v1_2;
    register int temp_v1_3 __asm__("$3");
    register int temp_v1_4 __asm__("$3");
    int temp_v1_5;
    register int temp_v1_6 __asm__("$3");
    register int var_a1 __asm__("$5");
    register int var_s0 __asm__("$16");
    register int var_v1 __asm__("$3");
    unsigned char temp_v1;
    unsigned char temp_v1_7;
    register int var_v0 __asm__("$2");
    register void* temp_a0 __asm__("$4");
    register void* temp_a0_2 __asm__("$4");
    register void* temp_a0_4 __asm__("$4");
    register void* temp_a1 __asm__("$5");
    register void* temp_s2 __asm__("$18");
    void* temp_v0_3;
    void* temp_v0_6;
    void* temp_v0_8;

    temp_v1 = arg0->state;
    temp_s2 = arg0->mobyTag;
    switch (temp_v1) {
        case 0:
            var_s1 = arg0;
            var_s0 = 0;
            call4 = 0x45;
            do {
                call5 = (int)var_s1;
                spawn2 = SpawnMoby;
                value3 = var_s0 + 1;
                MATCHING_KEEP(value3);
                var_s1 = spawn2(call4, (var_s0 = value3, (Moby*)call5));
                Controller79430SetMobyAnimation(var_s1, var_s0);
                call4 = 0x45;
            } while (var_s0 < 2);
            if (M2C_FIELD(temp_s2, int*, 4) >= 0) {
                var_s1 = SpawnMoby(call4, var_s1);
                MATCHING_KEEP(var_s1);
                value3 = (int)var_s1->mobyTag;
                value2 = M2C_FIELD(temp_s2, int*, 4);
                M2C_FIELD((void*)value3, int*, 4) = value2;
                M2C_FIELD(temp_s2, int*, 4) = -1;
                var_s1->lowDrawDistance = 0;
                var_s1->drawn = 0;
                var_s1->unknownCollision = 0;
            }
            var_s1->substate = 1;
            arg0->state = 1;
            break;
        case 1:
            if (arg0->damageFlags & 0x04000000) {
                M2C_FIELD(temp_s2, int*, 8) = 0;
                arg0->state = 5;
            }
            break;
        case 2:
            temp_a0 = M2C_FIELD(temp_s2, void**, 0);
            M2C_FIELD(temp_a0, int*, 0x18) =
                (int)(M2C_FIELD(temp_a0, int*, 0x18) | arg0->damageFlags);
            temp_a0_2 = M2C_FIELD(temp_s2, void**, 0);
            if (((unsigned int)(M2C_FIELD(temp_a0_2, unsigned char*, 0x48) - 1) >= 2U) ||
                ((arg0->position.z - M2C_FIELD(temp_a0_2, int*, 0x14)) >= 0x801)) {
                value3 = (int)M2C_FIELD(temp_a0_2, void**, 0);
                M2C_FIELD(temp_s2, int*, 8) = 0x40;
                temp_v0 = M2C_FIELD((void*)value3, int*, 8);
                if (temp_v0 > 0) {
                    M2C_FIELD(temp_s2, int*, 8) = (int)((temp_v0 >> 1) + 0x40);
                }
                M2C_FIELD(temp_s2, int*, 0xC) = (int)(arg0->position.z - 0x600);
                func_8004F178(&sp18, &arg0->position);
                sp18.z += 0x200;
                temp_v0_2 = Controller79430QueryWorldHeight(&sp18, 0x2000);
                sp18.z = temp_v0_2;
                if (M2C_FIELD(temp_s2, int*, 0xC) < temp_v0_2) {
                    M2C_FIELD(temp_s2, int*, 0xC) = temp_v0_2;
                }
                value2 = arg0->position.z;
                call4 = M2C_FIELD(temp_s2, int*, 8);
                value3 = 3;
                arg0->state = value3;
                arg0->position.z = value2 + call4;
            }
            break;
        case 3:
            temp_v0_3 = M2C_FIELD(temp_s2, void**, 0);
            if ((temp_v0_3 != 0) && (M2C_FIELD(temp_v0_3, unsigned char*, 0x48) & 0x80)) {
                M2C_FIELD(temp_s2, void**, 0) = 0;
                func_8004F178(&sp28, &arg0->position);
                sp28.z += 0x200;
                M2C_FIELD(temp_s2, int*, 0xC) = Controller79430QueryWorldHeight(&sp28, 0x2000);
            }
            temp_v0_4 = M2C_FIELD(temp_s2, int*, 8) - 8;
            M2C_FIELD(temp_s2, int*, 8) = temp_v0_4;
            if (temp_v0_4 < -0xF0) {
                M2C_FIELD(temp_s2, int*, 8) = -0xF0;
            }
            temp_v1_2 = arg0->position.z + M2C_FIELD(temp_s2, int*, 8);
            arg0->position.z = temp_v1_2;
            if ((M2C_FIELD(temp_s2, int*, 8) < 0) && (M2C_FIELD(temp_s2, int*, 0xC) >= temp_v1_2)) {
                temp_v1_3 = M2C_FIELD(temp_s2, int*, 4);
                if (temp_v1_3 >= 0) {
                    if (M2C_FIELD(((temp_v1_3 * 0x58) + Controller79430_D_8006C550), short*,
                                  0x36) == 0xCB) {
                        call4 = (int)arg0;
                        var_a1 = 2;
                        goto helperState3;
                    } else {
                        goto block_27;
                    }
                } else {
                block_27:
                    call4 = (int)arg0;
                    var_a1 = 0;
                }
            helperState3:
                func_8003BABC(call4, var_a1, 0);
                if (arg0->substate == 1) {
                    temp_v1_4 = M2C_FIELD(temp_s2, int*, 4);
                    if (temp_v1_4 >= 0) {
                        temp_a1 = M2C_FIELD(temp_s2, void**, 0);
                        if ((temp_a1 != 0) &&
                            (M2C_FIELD(((temp_v1_4 * 0x58) + Controller79430_D_8006C550), short*,
                                       0x36) == 0x88)) {
                            M2C_FIELD(temp_a1, unsigned char*, 0x48) = 5U;
                            M2C_FIELD(temp_s2, void**, 0) = (void*)*M2C_FIELD(temp_a1, void***, 0);
                            func_8004F178(&sp38, &arg0->position);
                            sp38.z += 0x200;
                            var_v1 = Controller79430QueryWorldHeight(&sp38, 0x2000);
                            MATCHING_KEEP(var_v1);
                            sp38.z = var_v1;
                            value2 = M2C_FIELD(temp_s2, int*, 0);
                            if (value2 == 0)
                                goto storeHeight3;
                            temp_v0_5 = arg0->position.z - 0x600;
                            M2C_FIELD(temp_s2, int*, 12) = temp_v0_5;
                            var_v1 = sp38.z;
                            if (temp_v0_5 >= var_v1) {
                                var_v0 = 3;
                                goto block_61;
                            }
                        storeHeight3:
                            M2C_FIELD(temp_s2, int*, 12) = var_v1;
                            var_v0 = 3;
                            goto block_61;
                        } else {
                            goto block_36;
                        }
                    } else {
                    block_36:
                        M2C_FIELD(temp_s2, int*, 8) = 0x40;
                        var_v0 = 4;
                    }
                    goto block_61;
                }
                if (M2C_FIELD(temp_s2, void**, 0) != 0) {
                    arg0->state = 2;
                    goto clearFlags;
                } else {
                    goto block_60;
                }
            }
            break;
        case 4:
            temp_v0_6 = M2C_FIELD(temp_s2, void**, 0);
            if (temp_v0_6 != 0) {
                if (M2C_FIELD(temp_v0_6, unsigned char*, 0x48) & 0x80) {
                    M2C_FIELD(temp_s2, void**, 0) = 0;
                    func_8004F178(&sp38, &arg0->position);
                    sp38.z += 0x200;
                    M2C_FIELD(temp_s2, int*, 0xC) = Controller79430QueryWorldHeight(&sp38, 0x2000);
                }
                if (M2C_FIELD(temp_s2, void**, 0) == 0) {
                    goto block_43;
                }
            } else {
            block_43:
                if (arg0->damageFlags & 0x04000000) {
                    M2C_FIELD(temp_s2, int*, 8) = 0;
                    arg0->state = 5;
                }
            }
            temp_v0_7 = M2C_FIELD(temp_s2, int*, 8) - 8;
            M2C_FIELD(temp_s2, int*, 8) = temp_v0_7;
            if (temp_v0_7 < -0xF0) {
                M2C_FIELD(temp_s2, int*, 8) = -0xF0;
            }
            temp_v1_5 = arg0->position.z + M2C_FIELD(temp_s2, int*, 8);
            arg0->position.z = temp_v1_5;
            if ((M2C_FIELD(temp_s2, int*, 8) < 0) && (M2C_FIELD(temp_s2, int*, 0xC) >= temp_v1_5)) {
                temp_v0_8 = M2C_FIELD(temp_s2, void**, 0);
                if ((temp_v0_8 != 0) && ((temp_v1_5 - M2C_FIELD(temp_v0_8, int*, 0x14)) >= 0x801)) {
                    func_8004F178(&sp48, &arg0->position);
                    sp48.z += 0x200;
                    sp48.z = Controller79430QueryWorldHeight(&sp48, 0x2000);
                    temp_v0_9 = M2C_FIELD(temp_s2, int*, 0xC) - 0x600;
                    M2C_FIELD(temp_s2, int*, 0xC) = temp_v0_9;
                    value3 = sp48.z;
                    if (temp_v0_9 >= value3) {
                        var_v0 = 3;
                        goto directStateStore;
                    }
                    var_v0 = 3;
                    M2C_FIELD(temp_s2, int*, 12) = value3;
                    goto block_61;
                } else {
                    temp_v1_6 = M2C_FIELD(temp_s2, int*, 4);
                    if (temp_v1_6 >= 0) {
                        if (M2C_FIELD(((temp_v1_6 * 0x58) + Controller79430_D_8006C550), short*,
                                      0x36) == 0xCB) {
                            func_8003BABC(arg0, 3, 0);
                        } else {
                            goto block_57;
                        }
                    } else {
                    block_57:
                        temp_v0_10 = func_8003BABC(arg0, 0, 0);
                        call4 = temp_v0_10;
                        if (temp_v0_10 >= 0) {
                            func_8003C140(call4, 0xC00);
                        }
                    }
                    value2 = M2C_FIELD(temp_s2, int*, 0);
                    if (value2 != 0) {
                        var_v0 = 2;
                        goto block_61;
                    }
                    goto block_60;
                }
                goto block_61;
            }
            goto tail;
        block_60:
            var_v0 = 1;
        block_61:
            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(var_v0, "memory");
        directStateStore:
            MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(var_v0, "memory");
            arg0->state = var_v0;
        clearFlags:
            arg0->damageFlags = 0;
            goto tail;
        case 5:
            func_8003BABC(arg0, 1, 0);
            temp_v1_7 = arg0->animationState.id;
            SpawnFragments(3, 0x47, arg0, M2C_FIELD(temp_s2, int*, 0x10) + (temp_v1_7 * 0x24),
                           temp_v1_7 * 3, 0x200);
            Controller79430DeleteMoby(arg0);
            break;
    }
tail:
    temp_a0_3 = M2C_FIELD(temp_s2, int*, 4);
    if (temp_a0_3 >= 0) {
        value2 = temp_a0_3 * 0x58;
        value3 = Controller79430_D_8006C550;
        temp_a0_4 = (void*)(value2 + value3);
        if ((M2C_FIELD(temp_a0_4, unsigned char*, 0x48) & 0x80) || (arg0->state == 1)) {
            Controller79430DeleteMoby(arg0);
            return;
        }
        func_8004F178(temp_a0_4 + 0xC, &arg0->position);
    }
}
#undef M2C_FIELD

extern int D_8006C578, D_8006C574;
Moby* func_800391E8(int, int, Moby*, int, int, int, int);
int func_80039714(Moby*);
void func_level_36_80079AE8(Moby* moby) {
    short* tag = moby->mobyTag;
    if (!moby->substate && tag[6] <= 0) {
        int index;
        moby->substate = 0x70;
        for (index = 0; index < 4; index++) {
            Moby* piece;
            if (D_8006C578 - D_8006C574 < 21)
                break;
            piece = func_800391E8(1, moby->mobyClass, moby, 0, 8, 0x40, 0x100);
            if (piece) {
                piece->substate = 1;
                piece->size = 0x7F;
            }
        }
    }
    func_80039714(moby);
}

int rand(void);
void func_level_36_80079BC0(Moby* moby) {
    Vector3D position;
    int index;
    if (moby->animationState.id == 0) {
        if (moby->damageFlags & 0x4000000) {
            func_80036A68(moby, 1, 0, 0);
            index = 0;
            do {
                index++;
                position.x = (rand() & 0x1FE) - 255;
                position.y = (rand() & 0x1FE) - 255;
                position.z = (rand() & 0x1FE) - 255;
                func_8004F194(&position, &position, &moby->position);
                SpawnParticle(4, 15, &position, 0);
            } while (index < 4);
            func_800391E8(8, 0x4A, moby, 1, 3, 0x100, 0x100);
            func_8003BABC(moby, 0, 0);
            func_8003BA00(moby);
            func_80055B18(moby);
        }
    } else if (func_80039714(moby))
        SpawnParticle(8, 15, &moby->position, 0);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80079D08.
* Assembly SHA256 0d85689b4e10136e64c7eda578113634b2368ba3de87ea0596b579314bdcfa24.
* AI generated; not human reviewed. All545 original instructions,6
* selectors bias0 and every actual branch/call/internal target are required.
* Frame58 retains SP10..3F and all original S0/S1/S2/S3/RA saves/restores.
* The original32-bit XOR/shift check, four original multi-addend relocations,
* state0 jumps, state1 handle-call entrances, signed trig producers,
* independent post-call distance load and final copy/draw tail remain exact.
* The original branch at8007A4A0 skips the post-normalization A0 reset and
* joins at8007A4B8; matching instruction operations alone cannot prove this.
* Analysis-only arithmetic folding preserved every original addend value;
* original assembly and the frozen compiler/pipeline were never modified.
* Empty initialized dependencies and dead-before-producer clobbers emit no
* CPU instructions. No partial HI, FP shortcut or opcode assembly is used.
* Raw field units/fixed point, full helper contracts and caller cadence
* remain unresolved. Cadence here is per invocation. Binary identity does
* not establish synchronized retail runtime or complete game behavior.
* Falsification: every native/linked word and actual target, all selectors,
* full EXE and every overlay retail hash must remain identical. */
#define Actor36Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Actor36DataPlaySoundView1() __asm__("PlaySound");
int Actor36QueryWorldHeightView1() __asm__("func_8001A358");
int Actor36CountTimerDownView1() __asm__("func_800359A4");
unsigned char Actor36RegisterTrackedValueView1() __asm__("func_8003B7B4");
int Actor36PlayMobySoundEventView1() __asm__("func_8003BABC");
unsigned char Actor36TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Actor36SoundHandleMatchesOwnerInStates1Or2View1() __asm__("func_8003BFC0");
unsigned char Actor36SetSoundHandleScaledDescriptorAverageView1() __asm__("func_8003C0B0");
unsigned char Actor36SetSoundHandleWord0CAndFlag10View1() __asm__("func_8003C140");
int Actor36PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor36MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Actor36NormalizeVectorToLengthView1() __asm__("func_8004EF04");
unsigned char Actor36ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Actor36CopyVectorView1() __asm__("func_8004F178");
unsigned char Actor36AddVectorView1() __asm__("func_8004F194");
unsigned char Actor36SubtractVectorView1() __asm__("func_8004F1C8");
int Actor36ApproximatePlanarDistanceView1() __asm__("func_8004F334");
unsigned char Actor36DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor36RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern unsigned char Actor36Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor36Data65920View1 __asm__("D_80065920");
extern unsigned char Actor36Data66BC8View1 __asm__("D_80066BC8");
extern int Actor36Data6C58CView1 __asm__("D_8006C58C");
extern void* Actor36Data6C654View1 __asm__("D_8006C654");
extern unsigned char Actor36Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Actor36Data6C7F8View1 __asm__("D_8006C7F8");
extern unsigned char Actor36Data6E020View1 __asm__("D_8006E020");
extern int Actor36Data6E1D4View1 __asm__("D_8006E1D4");
extern int Actor36Data6E1D8View1 __asm__("D_8006E1D8");
extern unsigned char Actor36Data70300View1 __asm__("D_80070300");
extern unsigned char Actor36Data70328View1 __asm__("D_80070328");
extern short Actor36Data719DCView1 __asm__("D_800719DC");
extern int Actor36Data722B8View1 __asm__("D_800722B8");
extern unsigned char Actor36Call2CA50View1 __asm__("func_8002CA50");
extern unsigned char Actor36Call2D044View1 __asm__("func_8002D044");
extern int Actor36Data74358View1 __asm__("unk_ovlheader_80074358");
extern void* (*Actor36DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor36Data74340View1)() __asm__("unk_ovlheader_80074340");
extern unsigned char Actor36Data70310View __asm__("D_80070300 + 16");
void func_level_36_80079D08(void* input) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register void* argumentPointer4 __asm__("$4");
    register int argumentWord4 __asm__("$4");
    register void* argumentPointer6 __asm__("$6");
    register int argumentWord7 __asm__("$7");
    register int (*indirectCall2)() __asm__("$2");
    register void* ownerRecord18 __asm__("$18");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C;
    } originalFrame;
    unsigned char* temporaryWord1;
    register unsigned char* firstOwnerPosition19 __asm__("$19");
    register unsigned char* secondOwnerPosition19 __asm__("$19");
    unsigned char* temporaryWord14;
    unsigned char* temporaryWord15;
    register unsigned char* positionOrScratch16 __asm__("$16");
    register int temporaryWord16 __asm__("$5");
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord12;
    register int temporaryWord13 __asm__("$4");
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord11;
    register void* privateRecord17 __asm__("$17");
    register void* temporaryWord5 __asm__("$16");
    void* temporaryPointer10;
    ownerRecord18 = input;
    MATCHING_KEEP(ownerRecord18);
    privateRecord17 = Actor36Field(ownerRecord18, void**, 0);
    if (Actor36Field(privateRecord17, void**, 0x60) == 0) {
        Actor36Field(privateRecord17, void**, 0x60) = (void*)(&Actor36Call2CA50View1 - 0x1C4D);
    }
    temporaryPointer10 = Actor36Field(privateRecord17, void**, 0x60);
    temporaryWord13 = 0;
    if ((unsigned int)temporaryPointer10 < (unsigned int)(&Actor36Call2D044View1 - 0x1C4D)) {
        temporaryWord16 = 0x80050000;
        Actor36Field(privateRecord17, int*, 0x64) =
            (int)(Actor36Field(privateRecord17, int*, 0x64) ^
                  (Actor36Field(temporaryPointer10, unsigned char*, 0x1C4F) << 0x18));
        do {
            temporaryWord2 = Actor36Field(privateRecord17, int*, 0x64);
            if (temporaryWord2 < 0) {
                temporaryWord17 = (temporaryWord2 * 2) ^ 0x80050000;
            } else {
                temporaryWord17 = temporaryWord2 * 2;
            }
            Actor36Field(privateRecord17, int*, 0x64) = temporaryWord17;
            temporaryWord13 += 1;
        } while (temporaryWord13 < 8);
        Actor36Field(privateRecord17, void**, 0x60) =
            (void*)(Actor36Field(privateRecord17, void**, 0x60) + 1);
    } else {
        temporaryWord16 = 0xFFFF0;
        if (((((int)Actor36Field(privateRecord17, int*, 0x64) >> 0xC) & 0xFFFF0) |
             (Actor36Data722B8View1 & 0xFFF0000F)) != Actor36Data74358View1) {
            Actor36Data70310View = (unsigned char)(Actor36Data70310View & 0xFE);
            Actor36Field(privateRecord17, int*, 0x64) = 0;
        }
    }
    temporaryWord11 = Actor36Field(ownerRecord18, unsigned char*, 0x48);
    switch (temporaryWord11) {
        case 0:
            rawWord2 = Actor36Data6C7B4View1 & 1;
            if (rawWord2)
                goto flagged545;
            rawWord2 = Actor36Data6C58CView1;
            rawWord2 = Actor36Field(&Actor36Data70300View1, unsigned char*, rawWord2) & 1;
            positionOrScratch16 = ownerRecord18 + 12;
            if (!rawWord2)
                goto initialize545;
        flagged545:
            rawWord2 = Actor36Field(privateRecord17, int*, 0x44);
            positionOrScratch16 = ownerRecord18 + 12;
            if (rawWord2)
                goto raised545;
            rawWord2 = Actor36Field(privateRecord17, int*, 0x48);
            temporaryWord16 = Actor36Field(rawWord2, int*, 12);
            argumentPointer4 = positionOrScratch16;
            temporaryWord16 += 16;
            Actor36CopyVectorView1(argumentPointer4, temporaryWord16);
            __asm__ __volatile__("" ::"i"(0x80079EA8) : "memory");
            argumentPointer4 = positionOrScratch16;
            goto prepared545;
        raised545:
            rawWord2 = Actor36Field(privateRecord17, int*, 0x48);
            temporaryWord16 = Actor36Field(rawWord2, int*, 12);
            Actor36CopyVectorView1(positionOrScratch16, temporaryWord16);
            argumentPointer4 = positionOrScratch16;
            rawWord2 = Actor36Field(ownerRecord18, int*, 20);
            temporaryWord16 = 8192;
            rawWord2 += 4096;
            Actor36Field(ownerRecord18, int*, 20) = rawWord2;
            rawWord2 = Actor36QueryWorldHeightView1(argumentPointer4, temporaryWord16);
            rawWord2 -= 16;
            Actor36Field(ownerRecord18, int*, 20) = rawWord2;
            rawWord2 = 1;
            __asm__ __volatile__("" ::"i"(0x80079EE8) : "memory");
            Actor36Field(ownerRecord18, unsigned char*, 0x49) = rawWord2;
            goto setState4;
        initialize545:
            argumentPointer4 = positionOrScratch16;
        prepared545:
            __asm__ __volatile__("" ::: "$5", "memory");
            temporaryWord16 = (int)positionOrScratch16;
            argumentWord7 = Actor36Field(privateRecord17, int*, 4);
            __asm__ __volatile__("" ::"r"(argumentWord7) : "$2", "memory");
            indirectCall2 = Actor36Data74340View1;
            indirectCall2(argumentPointer4, temporaryWord16, privateRecord17 + 8, argumentWord7);
            Actor36CopyVectorView1(&originalFrame.sp10, positionOrScratch16);
            originalFrame.sp18 += 256;
            rawWord2 = Actor36QueryWorldHeightView1(&originalFrame.sp10, 1024);
            rawWord2 -= 16;
            Actor36Field(ownerRecord18, int*, 20) = rawWord2;
            rawWord2 = 1;
            Actor36Field(ownerRecord18, unsigned char*, 0x48) = rawWord2;
            __asm__ __volatile__("" ::: "$4", "$5", "memory");
            Actor36CopyVectorView1(privateRecord17 + 0x54, ownerRecord18 + 12);
        case 1:
            if ((Actor36Field(privateRecord17, int*, 0x54) !=
                 Actor36Field(ownerRecord18, int*, 0xC)) ||
                (Actor36Field(privateRecord17, int*, 0x58) !=
                 Actor36Field(ownerRecord18, int*, 0x10)) ||
                (Actor36Field(privateRecord17, int*, 0x5C) !=
                 Actor36Field(ownerRecord18, int*, 0x14))) {
                if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                        ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) == 0) {
                    Actor36Field(privateRecord17, int*, 0x4C) =
                        Actor36PlayMobySoundEventView1(ownerRecord18, 0, 4);
                }
                if (Actor36Field(privateRecord17, int*, 0x4C) >= 0) {
                    temporaryWord3 = Actor36Field(privateRecord17, int*, 0x50) + 0x100;
                    Actor36Field(privateRecord17, int*, 0x50) = temporaryWord3;
                    if (temporaryWord3 >= 0x1001) {
                        Actor36Field(privateRecord17, int*, 0x50) = 0x1000;
                    }
                    argumentPointer4 = (void*)Actor36Field(privateRecord17, int*, 0x4C);
                    temporaryWord16 = Actor36Field(privateRecord17, int*, 0x50);
                    __asm__ __volatile__("" ::"i"(0x80079FE8) : "memory");
                    goto sharedHandleCallReady;
                }
            } else if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                           ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) != 0) {
                rawWord2 = Actor36Field(privateRecord17, int*, 0x50);
                MATCHING_KEEP(rawWord2);
                temporaryWord16 = rawWord2 - 512;
                Actor36Field(privateRecord17, int*, 0x50) = temporaryWord16;
                if (temporaryWord16 <= 0) {
                    if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                            ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) != 0) {
                        Actor36TransitionSoundHandleTo3Or5View1(
                            Actor36Field(privateRecord17, int*, 0x4C));
                    }
                    Actor36Field(privateRecord17, int*, 0x4C) = -1;
                } else {
                prepareSharedHandleCall:
                    MATCHING_BARRIER_GNU_VOLATILE("memory");
                    argumentPointer4 = (void*)Actor36Field(privateRecord17, int*, 0x4C);
                sharedHandleCallReady:
                    Actor36SetSoundHandleWord0CAndFlag10View1(argumentPointer4, temporaryWord16);
                }
            }
            if (Actor36Field(privateRecord17, int*, 0x44) == 0) {
                positionOrScratch16 = (unsigned char*)&originalFrame.sp20;
                argumentPointer4 = positionOrScratch16;
                MATCHING_KEEP(argumentPointer4);
                firstOwnerPosition19 = ownerRecord18 + 12;
                MATCHING_KEEP(firstOwnerPosition19);
                Actor36CopyVectorView1(argumentPointer4, firstOwnerPosition19);
                originalFrame.sp28 += 0x100;
                if (Actor36QueryWorldHeightView1(&originalFrame.sp20, 0x200) == 0) {
                    Actor36SubtractVectorView1(privateRecord17 + 0x2C, firstOwnerPosition19,
                                               privateRecord17 + 0x20);
                    temporaryWord4 = Actor36PlanarHeadingLookupView1(
                        Actor36Field(privateRecord17, int*, 0x2C),
                        Actor36Field(privateRecord17, int*, 0x30), 0);
                    rawWord2 = temporaryWord4;
                    rawWord3 = Actor36Field(ownerRecord18, unsigned char*, 0x46);
                    Actor36Field(privateRecord17, int*, 0x38) = 0;
                    rawWord3 -= 32;
                    rawWord2 -= rawWord3;
                    rawWord3 = rawWord2 & 255;
                    Actor36Field(privateRecord17, int*, 0x3C) = 0;
                    rawWord2 = rawWord3 < 64;
                    if (!rawWord2)
                        goto highSector545;
                    rawWord2 = -6;
                    Actor36Field(privateRecord17, int*, 0x3C) = rawWord2;
                    goto sectorDone545;
                highSector545:
                    rawWord2 = rawWord3 < 128;
                    if (rawWord2)
                        goto negativeAxis545;
                    rawWord2 = rawWord3 < 192;
                    if (!rawWord2)
                        goto positiveAxis545;
                    rawWord2 = 6;
                    Actor36Field(privateRecord17, int*, 0x3C) = rawWord2;
                    goto sectorDone545;
                negativeAxis545:
                    rawWord2 = -6;
                    goto storeAxis545;
                positiveAxis545:
                    rawWord2 = 6;
                storeAxis545:
                    Actor36Field(privateRecord17, int*, 0x38) = rawWord2;
                sectorDone545:
                    Actor36Field(privateRecord17, int*, 0x34) = 0;
                    Actor36NormalizeVectorToLengthView1(privateRecord17 + 0x2C, 0x20);
                    Actor36Field(privateRecord17, int*, 0x40) = 0x3C;
                    Actor36Field(ownerRecord18, signed char*, 0x47) = 0;
                    Actor36Field(ownerRecord18, unsigned char*, 0x48) = 5U;
                    Actor36RegisterTrackedValueView1(ownerRecord18 + 0x48, 1,
                                                     &Actor36Data6C7F8View1);
                    Actor36Field(ownerRecord18, signed char*, 0x49) = 0;
                    if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                            ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) != 0) {
                        Actor36TransitionSoundHandleTo3Or5View1(
                            Actor36Field(privateRecord17, int*, 0x4C));
                    }
                    Actor36Field(privateRecord17, int*, 0x4C) = -1;
                    Actor36Field(ownerRecord18, unsigned char*, 0x48) = 2U;
                    Actor36Field(&Actor36Data66BC8View1, signed char*, 0xE) = 3;
                    Actor36Data719DCView1 = 1;
                    Actor36DataPlaySoundView1(
                        Actor36Field(Actor36Data6C654View1, unsigned char*, 0x23), ownerRecord18,
                        0xA1);
                    temporaryWord5 = Actor36DataSpawnMobyView1(0xD3, ownerRecord18);
                    if (temporaryWord5 != 0) {
                        Actor36CopyVectorView1(temporaryWord5 + 0xC, &Actor36Data70328View1);
                        rawWord2 = Actor36Field(&Actor36Data70328View1, unsigned char*, 14);
                        rawWord2 <<= 1;
                        rawWord3 = Actor36Field(&Actor36Data65920View1, short*, rawWord2);
                        rawWord2 = rawWord3 * 25;
                        rawWord3 = Actor36Field(temporaryWord5, int*, 12);
                        rawWord2 >>= 7;
                        rawWord3 += rawWord2;
                        Actor36Field(temporaryWord5, int*, 12) = rawWord3;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        rawWord2 = Actor36Field(&Actor36Data70328View1, unsigned char*, 14);
                        rawWord3 = Actor36Field(temporaryWord5, int*, 20);
                        rawWord2 <<= 1;
                        argumentWord4 = Actor36Field(&Actor36Data658A0View1, short*, rawWord2);
                        rawWord3 += 500;
                        Actor36Field(temporaryWord5, int*, 20) = rawWord3;
                        rawWord3 = Actor36Field(temporaryWord5, int*, 16);
                        rawWord2 = argumentWord4 * 25;
                        rawWord2 >>= 7;
                        rawWord3 += rawWord2;
                        Actor36Field(temporaryWord5, int*, 16) = rawWord3;
                        goto updatePositionFields;
                    }
                } else {
                    if (Actor36ApproximatePlanarDistanceView1(
                            firstOwnerPosition19,
                            Actor36Field(Actor36Field(privateRecord17, void**, 0x48),
                                         unsigned char**, 0xC)) >=
                        (Actor36Field(privateRecord17, int*, 4) * 2)) {
                        Actor36Field(ownerRecord18, signed char*, 0x49) = 1;
                    } else {
                        Actor36Field(ownerRecord18, signed char*, 0x49) = 0;
                    }
                    goto updatePositionFields;
                }
            } else {
                rawWord2 = Actor36ApproximatePlanarDistanceView1(
                    ownerRecord18 + 12,
                    Actor36Field(Actor36Field(privateRecord17, void**, 0x48), unsigned char**, 12));
                rawWord3 = Actor36Field(privateRecord17, int*, 4);
                rawWord3 >>= 1;
                rawWord3 = rawWord3 < rawWord2;
                MATCHING_KEEP(rawWord3);
                if (!rawWord3) {
                    __asm__ __volatile__("" ::: "$3", "memory");
                    Actor36Field(privateRecord17, int*, 0x14) = 0;
                    Actor36Field(privateRecord17, int*, 0x18) = 0;
                    if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                            ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) != 0) {
                        Actor36TransitionSoundHandleTo3Or5View1(
                            Actor36Field(privateRecord17, int*, 0x4C));
                    }
                    Actor36Field(privateRecord17, int*, 0x4C) = -1;
                    Actor36Field(ownerRecord18, unsigned char*, 0x48) = 3U;
                updatePositionFields:
                }
            }
            Actor36RegisterTrackedValueView1(ownerRecord18 + 12, 4, &Actor36Data6C7F8View1);
            Actor36RegisterTrackedValueView1(ownerRecord18 + 0x10, 4, &Actor36Data6C7F8View1);
            goto prepareCopyTail;
        case 2:
            if (Actor36Field(ownerRecord18, int*, 12) < 1024)
                goto finishState2;
            if (Actor36Field(ownerRecord18, int*, 16) < 1024)
                goto finishState2;
            if (Actor36Field(ownerRecord18, int*, 20) < 1024)
                goto finishState2;
            if (!Actor36CountTimerDownView1(privateRecord17 + 0x40, 4))
                goto movement545;
        finishState2:
            Actor36PlayMobySoundEventView1(ownerRecord18, 1, 0);
            temporaryWord18 =
                Actor36ApproximatePlanarDistanceView1(&Actor36Data6E020View1, ownerRecord18 + 0xC);
            if (temporaryWord18 > 0x7FFF) {
                temporaryWord18 = 0x7FFF;
            }
            Actor36Data6E1D4View1 = (int)((0x8000 - temporaryWord18) << 0xC) >> 0xF;
            Actor36Data6E1D8View1 = 0x1E;
            Actor36DeleteMobyView1(ownerRecord18);
            __asm__ __volatile__("" ::"i"(0x8007A3D0) : "memory");
            return;
        movement545:
            temporaryWord6 = Actor36Field(privateRecord17, int*, 0x34) - 8;
            Actor36Field(privateRecord17, int*, 0x34) = temporaryWord6;
            if (temporaryWord6 < -0xF0) {
                Actor36Field(privateRecord17, int*, 0x34) = -0xF0;
            }
            temporaryWord1 = ownerRecord18 + 0xC;
            Actor36AddVectorView1(temporaryWord1, temporaryWord1, privateRecord17 + 0x2C);
            Actor36Field(ownerRecord18, unsigned char*, 0x44) =
                (unsigned char)(Actor36Field(ownerRecord18, unsigned char*, 0x44) +
                                Actor36Field(privateRecord17, int*, 0x38));
            Actor36Field(ownerRecord18, unsigned char*, 0x45) =
                (unsigned char)(Actor36Field(ownerRecord18, unsigned char*, 0x45) +
                                Actor36Field(privateRecord17, int*, 0x3C));
            goto prepareCopyTail;
        case 3:
            if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) == 0) {
                temporaryWord7 = Actor36PlayMobySoundEventView1(ownerRecord18, 0, 4);
                Actor36Field(privateRecord17, int*, 0x4C) = temporaryWord7;
                if (temporaryWord7 >= 0) {
                    Actor36SetSoundHandleScaledDescriptorAverageView1(temporaryWord7, 0xC00);
                }
            }
            positionOrScratch16 = (unsigned char*)&originalFrame.sp30;
            argumentPointer4 = positionOrScratch16;
            MATCHING_KEEP(argumentPointer4);
            rawWord2 = Actor36Field(privateRecord17, int*, 0x48);
            __asm__ __volatile__("" ::: "$19", "memory");
            secondOwnerPosition19 = ownerRecord18 + 12;
            MATCHING_KEEP(secondOwnerPosition19);
            argumentPointer6 = Actor36Field(rawWord2, void**, 12);
            Actor36SubtractVectorView1(argumentPointer4, secondOwnerPosition19, argumentPointer6);
            originalFrame.sp38 = 0;
            temporaryWord8 = Actor36MeasureVectorLengthView1(&originalFrame.sp30, 0);
            argumentPointer4 = secondOwnerPosition19;
            if (temporaryWord8 >= 0x21) {
                __asm__ __volatile__("" ::"r"(argumentPointer4), "i"(0x8007A4A4) : "memory");
                Actor36ScaleVectorRatioQ15View1(&originalFrame.sp30, temporaryWord8, 0x20);
                argumentPointer4 = secondOwnerPosition19;
            }
            Actor36AddVectorView1(argumentPointer4, secondOwnerPosition19, &originalFrame.sp30);
            Actor36CopyVectorView1(&originalFrame.sp30, secondOwnerPosition19);
            originalFrame.sp38 += 0x100;
            temporaryWord9 = Actor36QueryWorldHeightView1(&originalFrame.sp30, 0x200) - 0x10;
            temporaryWord12 = Actor36Field(ownerRecord18, int*, 0x14) - 0x10;
            Actor36Field(ownerRecord18, int*, 0x14) = temporaryWord12;
            temporaryWord15 = privateRecord17 + 0x54;
            if (temporaryWord9 >= temporaryWord12) {
                Actor36Field(ownerRecord18, int*, 0x14) = temporaryWord9;
                Actor36Field(ownerRecord18, signed char*, 0x49) = 1;
                if (Actor36SoundHandleMatchesOwnerInStates1Or2View1(
                        ownerRecord18, Actor36Field(privateRecord17, int*, 0x4C)) != 0) {
                    Actor36TransitionSoundHandleTo3Or5View1(
                        Actor36Field(privateRecord17, int*, 0x4C));
                }
                Actor36Field(privateRecord17, int*, 0x4C) = -1;
                goto setState4;
            }
            goto copyAndDrawTail;
        setState4:
            Actor36Field(ownerRecord18, unsigned char*, 0x48) = 4;
            goto prepareCopyTail;
        case 5:
            Actor36DeleteMobyView1(ownerRecord18);
            __asm__ __volatile__("" ::"i"(0x8007A54C) : "memory");
            return;
        default:
            goto prepareCopyTail;
    }
prepareCopyTail:
    temporaryWord15 = privateRecord17 + 0x54;
copyAndDrawTail:
    Actor36CopyVectorView1(temporaryWord15, ownerRecord18 + 12);
    Actor36RefreshMobySpatialGridAndBasisView1(ownerRecord18, 2);
}
#undef Actor36Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * level36:8007A58C complete248 instructions, sibling4420. Verified25
 * helper shapes reused. Raw byte/word domains, constants and signed shifts;
 * semantic meanings, physical units and cadence unresolved. All original
 * native/internal/linked words and complete hashes required for acceptance. */
#define Actor36Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char* Actor36Pool __asm__("D_8006C550");
extern unsigned char Actor36PlayerYaw __asm__("D_80070328 + 0xE");
extern unsigned char Actor36PlayerPitch __asm__("D_80070328 + 0xD");
extern unsigned char Actor36Matrix[] __asm__("D_80070328 + 0x30");
int Actor36CopyVector() __asm__("func_8004F178");
int Actor36PlanarHeadingLookup() __asm__("func_8004E880");
int Actor36ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor36SubtractVector() __asm__("func_8004F1C8");
int Actor36NormalizeVectorToLength() __asm__("func_8004EF04");
int Actor36TransformVectorByBasis() __asm__("func_8004ED6C");
int Actor36CountTimerDown() __asm__("func_800359A4");
int Actor36AddVector() __asm__("func_8004F194");
int Actor36TestPlayerSphereOverlap() __asm__("func_8001C288");
int Actor36QueryWorldSphere() __asm__("func_80019194");
int Actor36QueryWorldSegment() __asm__("func_80018368");
int Actor36QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int Actor36RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor36QueryWorldHeight() __asm__("func_8001A358");
int Actor36RefreshMobyPackedQueryField() __asm__("func_8005629C");
int Actor36DeleteMoby() __asm__("func_80055B18");
extern void* (*Actor36SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_36_8007A58C(void* input) {
    register unsigned char* owner __asm__("$17") = input;
    int vector[4];
    int previous[4];
    register int* tag __asm__("$19");
    register unsigned char* target __asm__("$18");
    register int firstAngle __asm__("$16");
    register int secondAngle __asm__("$3");
    register void* firstPosition __asm__("$16");
    register void* secondPosition __asm__("$18");
    register void* previousVector __asm__("$18");
    register void* savedVector __asm__("$20");
    register unsigned char* hit __asm__("$16");
    register int work2 __asm__("$2");
    register void* call4 __asm__("$4");
    unsigned char heading;
    MATCHING_KEEP(owner);
    tag = Actor36Field(owner, int**, 0);
    switch (((Moby*)owner)->state) {
        case 0:
            goto state0;
        case 1:
            goto state1;
        case 2:
            goto state2;
        default:
            return;
    }
state1:
    {
        register int index __asm__("$3") = ((Moby*)owner)->linkedMoby;
        register int offset __asm__("$2");
        register unsigned char* pool __asm__("$3");
        MATCHING_KEEP(index);
        offset = index * 11;
        MATCHING_KEEP(offset);
        pool = Actor36Pool;
        MATCHING_KEEP(pool);
        target = pool + offset * 8;
        secondAngle = (int)pool;
    }
    work2 = Actor36Field(target, unsigned char*, 0x48) & 128;
    if (!work2) {
        Actor36CopyVector(vector, target + 12);
        vector[2] += 512;
        firstAngle = (Actor36PlanarHeadingLookup(vector[0] - ((Moby*)owner)->position.x,
                                                 vector[1] - ((Moby*)owner)->position.y, 0) -
                      Actor36PlayerYaw) &
                     255;
        if (firstAngle > 128)
            firstAngle -= 256;
        secondAngle =
            (Actor36PlanarHeadingLookup(Actor36ApproximatePlanarDistance(owner + 12, vector),
                                        vector[2] - ((Moby*)owner)->position.z, 0) -
             Actor36PlayerPitch) &
            255;
        if (secondAngle > 128)
            secondAngle -= 256;
        if (firstAngle < 0)
            firstAngle = -firstAngle;
        if (secondAngle < 0)
            secondAngle = -secondAngle;
        MATCHING_KEEP2(firstAngle, secondAngle);
        work2 = firstAngle < 12;
        MATCHING_KEEP(work2);
        if (!work2)
            target = 0;
        else {
            work2 = secondAngle < 12;
            if (!work2)
                target = 0;
        }
    } else
        target = 0;
    MATCHING_OBSERVE(secondAngle);
    if (target) {
        Actor36SubtractVector(tag, vector, owner + 12);
        Actor36NormalizeVectorToLength(tag, 512);
    } else {
        MATCHING_KEEP(target);
        tag[0] = 512;
        tag[1] = 0;
        tag[2] = 16;
        Actor36TransformVectorByBasis(Actor36Matrix, tag, tag);
    }
    tag[3] = 120;
    ((Moby*)owner)->substate = 1;
    ((Moby*)owner)->state = 0;
state0:
    if (((Moby*)owner)->position.x < 1024 || ((Moby*)owner)->position.y < 1024 ||
        ((Moby*)owner)->position.z < 1024)
        goto remove;
    if (Actor36CountTimerDown(tag + 3, 4))
        goto remove;
    previousVector = previous;
    call4 = previousVector;
    MATCHING_KEEP(call4);
    firstPosition = owner + 12;
    Actor36CopyVector(call4, firstPosition);
    Actor36AddVector(firstPosition, firstPosition, tag);
    if (!((Moby*)owner)->substate) {
        if (((Moby*)owner)->damageFlags & 0x08000000) {
            Actor36CopyVector(firstPosition, previousVector);
            ((Moby*)owner)->state = 1;
            return;
        }
        if (Actor36TestPlayerSphereOverlap(firstPosition, 384, 1)) {
            Actor36CopyVector(firstPosition, previousVector);
            goto contact;
        }
    }
    secondPosition = owner + 12;
    if (Actor36QueryWorldSphere(secondPosition, 384))
        goto worldContact;
    savedVector = previous;
    if (Actor36QueryWorldSegment(savedVector, secondPosition)) {
    worldContact:
        Actor36CopyVector(secondPosition, previous);
        goto contact;
    }
    if (((Moby*)owner)->substate == 1) {
        hit = Actor36QueryDynamicMobyGeometry(secondPosition, 384, 0, 0, 0x10000, owner);
        if (hit) {
            Actor36CopyVector(secondPosition, savedVector);
            heading = Actor36PlanarHeadingLookup(tag[0], tag[1], 0);
            Actor36Field(hit, unsigned char*, 0x51) = heading;
            if (!heading)
                Actor36Field(hit, unsigned char*, 0x51) = 1;
        contact:
            ((Moby*)owner)->state = 2;
            return;
        }
    }
    Actor36RefreshMobySpatialGridAndBasis(owner, 2);
    firstPosition = owner + 12;
    Actor36QueryWorldHeight(firstPosition, 8192);
    Actor36RefreshMobyPackedQueryField(owner);
    Actor36SpawnParticle(1, 5, firstPosition, 0);
    return;
state2:
    Actor36SpawnParticle(24, 15, owner + 12, 0);
remove:
    Actor36DeleteMoby(owner);
}
#undef Actor36Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level36:
 * 8007A96C complete250 instructions and six dispatch words, sibling4433.
 * Verified41 helper shapes reused; raw field domains and state selectors
 * only. Units, helper meanings, caller cadence unresolved. Acceptance
 * requires all original native/linked words, internal targets and hashes. */
#define Actor36A9Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* Actor36A9Active __asm__("D_8006E164");
extern int Actor36A9Type __asm__("D_8006E160");
extern unsigned char* Actor36A9Pool __asm__("D_8006C550");
extern unsigned char Actor36A9Player[] __asm__("D_80070328");
extern int Actor36A9Contact __asm__("D_8006C770");
int Actor36A9SpawnMobyFromValueSelector() __asm__("func_80036A68");
int Actor36A9InitializeMobyMotionStateWithDeceleration() __asm__("func_80038F14");
int Actor36A9TestPaddedRotatedBox() __asm__("func_80036220");
int Actor36A9CountTimerDown() __asm__("func_800359A4");
int Actor36A9RequestMobyAnimation() __asm__("func_80034F40");
int Actor36A9ReadSelectedFrameScalar() __asm__("func_80055E84");
int Actor36A9TurnMobyTowardHeading() __asm__("func_8003585C");
int Actor36A9UpdateMobyPathMotion() __asm__("func_80035A80");
int Actor36A9UpdateMobyMotionDescriptor() __asm__("func_80035194");
int Actor36A9RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor36A9MarkMobyCollectionBit() __asm__("func_8003BA00");
int Actor36A9EmitMobyVertexParticles() __asm__("func_800369B8");
int Actor36A9DeleteMoby() __asm__("func_80055B18");
extern void* (*Actor36A9SpawnMoby)(int, void*)__asm__("SpawnMoby");
void func_level_36_8007A96C(void* input) {
    register unsigned char* owner __asm__("$16") = input;
    register unsigned char* tag __asm__("$17");
    register void** activeAddress __asm__("$3");
    register int* typeAddress __asm__("$5");
    void* nested;
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    register void* arg7 __asm__("$7");
    register int value __asm__("$2");
    MATCHING_KEEP(owner);
    tag = Actor36A9Field(owner, unsigned char**, 0);
    if (((Moby*)owner)->state == 5)
        goto dispatch;
    if (((Moby*)owner)->damageFlags) {
        activeAddress = &Actor36A9Active;
        if (*activeAddress == owner) {
            Actor36A9Type = 0;
            *activeAddress = 0;
        }
        nested = Actor36A9Field(tag, void**, 0x30);
        call4 = owner;
        if (nested) {
            arg5 = 1;
            arg7 = Actor36A9Field(nested, void**, 12);
            MATCHING_OBSERVE3(call4, arg5, arg7);
            arg6 = 0;
            goto invoke;
        } else {
            arg5 = 1;
            arg6 = 0;
            arg7 = 0;
            MATCHING_OBSERVE4(call4, arg5, arg6, arg7);
        }
    invoke:
        Actor36A9SpawnMobyFromValueSelector(call4, arg5, arg6, arg7);
        Actor36A9InitializeMobyMotionStateWithDeceleration(owner, tag + 0x34, 0, 5);
        goto dispatch;
    }
    if (!(((Moby*)owner)->substate & 1)) {
        if (Actor36A9TestPaddedRotatedBox(Actor36A9Player, tag + 12, 0, 2048))
            ((Moby*)owner)->substate |= 1;
        goto dispatch;
    }
    if (!Actor36A9TestPaddedRotatedBox(Actor36A9Player, tag + 12, 1024, 2048)) {
        activeAddress = &Actor36A9Active;
        if (*activeAddress == owner) {
            Actor36A9Type = 0;
            *activeAddress = 0;
        }
        ((Moby*)owner)->substate &= 254;
        goto dispatch;
    }
    typeAddress = &Actor36A9Type;
    if (*typeAddress) {
        if (Actor36A9Field(tag, int*, 0x24) < 0)
            goto dispatch;
        if (Actor36A9Active != Actor36A9Pool + Actor36A9Field(tag, int*, 0x24) * 88)
            goto dispatch;
    }
    *typeAddress = 13;
    Actor36A9Active = owner;
dispatch:
    switch (((Moby*)owner)->state) {
        case 0:
        case 1:
            if (Actor36A9Field(tag, int*, 0x2C)) {
                call4 = owner;
                MATCHING_KEEP(call4);
                value = Actor36A9Field(call4, unsigned char*, 0x46);
                MATCHING_KEEP_CLOBBER(value, "$5");
                arg5 = 4;
                MATCHING_KEEP(arg5);
                Actor36A9Field(tag, int*, 0x28) = value;
                goto enter4;
            }
            call4 = tag + 4;
            if (Actor36A9CountTimerDown(call4, 4)) {
                ((Moby*)owner)->state = 2;
                Actor36A9RequestMobyAnimation(owner, 2);
            }
            break;
        case 2:
            if (Actor36A9ReadSelectedFrameScalar(owner) >= 9 && Actor36A9Field(tag, int*, 4) <= 0) {
                Actor36A9SpawnMoby(116, owner);
                Actor36A9Field(tag, int*, 4) = 1;
            }
            if (Actor36A9Contact) {
                ((Moby*)owner)->state = 3;
                Actor36A9RequestMobyAnimation(owner, 3);
            }
            break;
        case 3:
            if (Actor36A9Contact) {
                call4 = owner;
                if (Actor36A9Field(tag, int*, 0x2C)) {
                    arg5 = 4;
                enter4:
                    Actor36A9Field(call4, unsigned char*, 0x48) = 4;
                    Actor36A9Field(call4, unsigned char*, 0x49) &= 253;
                    Actor36A9RequestMobyAnimation(call4, arg5);
                } else {
                    Actor36A9Field(tag, int*, 4) = Actor36A9Field(tag, int*, 8);
                    Actor36A9Field(call4, unsigned char*, 0x48) = 0;
                    Actor36A9RequestMobyAnimation(call4, 0);
                }
            }
            break;
        case 4:
            if (((Moby*)owner)->substate & 2) {
                if (Actor36A9TurnMobyTowardHeading(owner, Actor36A9Field(tag, int*, 0x28), 8, 8, 1,
                                                   0)) {
                    Actor36A9Field(tag, int*, 4) = 0;
                    ((Moby*)owner)->state = 2;
                    Actor36A9RequestMobyAnimation(owner, 2);
                }
            } else if (Actor36A9UpdateMobyPathMotion(owner, Actor36A9Field(tag, void**, 0x2C), 512,
                                                     128, 0, 8, 8, 5) &
                       1)
                ((Moby*)owner)->substate |= 2;
            break;
        case 5:
            Actor36A9UpdateMobyMotionDescriptor(owner, tag + 0x34);
            if (Actor36A9Contact) {
                Actor36A9RefreshMobySpatialGridAndBasis(owner, 4);
                Actor36A9MarkMobyCollectionBit(owner);
                Actor36A9EmitMobyVertexParticles(owner, 48);
                Actor36A9DeleteMoby(owner);
            }
            break;
    }
}
#undef Actor36A9Field

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
void func_level_36_8007AD54(Moby* mobyArgument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original level36 controller8007B044.
 * AI generated; not human reviewed.1171 original instructions,30 selectors
 * and2 zero padding words=1203 owned words. Assembly SHA256 ae4eef2f9036a1163e3a7338bcc6e8c3dfbb5441fac9a8083781989d44055f3d.
 * The original64-byte frame keeps SP18/1C/20 as a three-word vector and
 * saves S0..S4/RA at28..3C. Every consumed vector word follows an explicit
 * original write,4F178 complete copy or4F1C8 complete subtraction producer.
 * SP24..27 is unconsumed reservation. There is no fixed FP/SP or padding read.
 * S0 phases are initialized path index/byte offset,heading,owner+C address,
 * or descriptor archive address. S1 phases are initialized path remainder
 * or owner+C address. Former values die before their next original producer.
 * S4's3 is produced on the first false predicate and only consumed on the
 * overall false predicate. No incoming saved value or overlapping alias is used.
 * Six original signed16-count modulo operations keep DIV's zero/overflow
 * guards and full signed numerators. All three MULT sites consume complete
 * signed64 products before two low32 and one high32 projections. The /24
 * high-product/sign correction and signed trig shifts preserve native words.
 * Original flag bytes are exactly D70300+6,+15,+24. Symbol+addend declarations
 * express addresses only; they emit no instructions. CRC reads,bit shifts,
 * actor stride88/list termination,byte/halfword writes and selected path
 * fields preserve original source widths and actual branch destinations.
 * The outer14-way guard enters the common compare without reloading its
 * initialized state word. Case1's helper-success edge enters the common
 * reload,not the nearby actor-list rejection. Table destinations are gated
 * separately for7+14+9 selectors and the two original zero pads.
 * Empty metadata observes complete initialized values/products/addresses or
 * a just-written field; clobbered GP roles are dead before fresh producers.
 * The late path's LH then LW uses only a memory sequencing boundary. The
 * native fifth zero argument and all other stack arguments are compiler-made.
 * No opcode templates,partial HILO inputs,manual stack writes,compiler/flag/
 * filter changes or weakened native/control/data/table/hash gate are used.
 * Known signatures reuse original camera,mobyutil and stdutil contracts.
 * Other helpers retain original physical word call views,including initialized
 * extra GP words ignored by actual callees. Names describe storage only.
 * Physical units,fixed-point producer/consumer domains,full helper/caller/
 * allocation chains,cadence beyond invocation and synchronized retail runtime
 * remain open. Acceptance establishes binary identity; human review and retail
 * captures remain required. Engine/browser behavior is unchanged.
 */
#define Level36_7B044MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level36_7B044CaptureLow(v)                                 \
    do {                                                           \
        int wholeLow;                                              \
        __asm__("" : "=l"(wholeLow) : "x"(completeSignedProduct)); \
        v = wholeLow;                                              \
        Level36_7B044Keep(v);                                      \
    } while (0)
#define Level36_7B044CaptureHigh(v)                                 \
    do {                                                            \
        int wholeHigh;                                              \
        __asm__("" : "=h"(wholeHigh) : "x"(completeSignedProduct)); \
        v = wholeHigh;                                              \
        Level36_7B044Keep(v);                                       \
    } while (0)
#define Level36_7B044Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level36_7B044Keep(v) __asm__("" : "=r"(v) : "0"(v))
void Level36_7B044SetCameraMode11Target(void*, int, void*, int) __asm__("func_80013D44");
int Level36_7B044QueryWorldHeight(void*, int) __asm__("func_8001A358");
int Level36_7B044MaskLinkedRecordFlagsById() __asm__("func_80021ED8");
int Level36_7B044QueryShiftedLinkedRecordWordByByteId() __asm__("func_80021F3C");
int Level36_7B044RequestMobyAnimation() __asm__("func_80034F40");
int Level36_7B044TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Level36_7B044CountTimerDown(void*, int) __asm__("func_800359A4");
int Level36_7B044ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Level36_7B044RandBetween(int, int) __asm__("func_8003636C");
int Level36_7B044ComputeArcVerticalVelocity(void*, void*, int, int, void*) __asm__("func_800365E4");
int Level36_7B044CountListedMobysBelowState80(int) __asm__("func_800369D8");
int Level36_7B044UpdateMobyInteractionGate(void*, int) __asm__("func_80037BBC");
int Level36_7B044ResolveMobyMotionCollision(void*, void*, int, int, int) __asm__("func_80038000");
int Level36_7B044RegisterTrackedValue() __asm__("func_8003B7B4");
int Level36_7B044PlaySoundFromGlobalByteTable() __asm__("func_8003BB10");
int Level36_7B044PlanarHeadingLookup() __asm__("func_8004E880");
int Level36_7B044MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
void Level36_7B044CopyVector(void*, void*) __asm__("func_8004F178");
int Level36_7B044AddVector() __asm__("func_8004F194");
void Level36_7B044SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Level36_7B044AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level36_7B044ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Level36_7B044StartDialogue() __asm__("func_800512E4");
void Level36_7B044DeleteMoby(void*) __asm__("func_80055B18");
void Level36_7B044RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Level36_7B044ReadSelectedFrameScalar(void*) __asm__("func_80055E84");
void Level36_7B044RefreshMobyQueryByte52(void*) __asm__("func_80056270");
void Level36_7B044RefreshMobyPackedQueryField(void*) __asm__("func_8005629C");
extern short Level36_7B044Data800658A0 __asm__("D_800658A0");
extern short Level36_7B044Data80065920 __asm__("D_80065920");
extern int Level36_7B044Data8006C550 __asm__("D_8006C550");
extern int Level36_7B044Data8006C58C __asm__("D_8006C58C");
extern int Level36_7B044Data8006C730 __asm__("D_8006C730");
extern int Level36_7B044Data8006C770 __asm__("D_8006C770");
extern unsigned char Level36_7B044Data8006C7B4 __asm__("D_8006C7B4");
extern int Level36_7B044Data8006C7F8 __asm__("D_8006C7F8");
extern int Level36_7B044Data8006E048 __asm__("D_8006E048");
extern int Level36_7B044Data8006E160 __asm__("D_8006E160");
extern int Level36_7B044Data8006E344 __asm__("D_8006E344");
struct Actor1171Flags {
    unsigned char pad0[6], field6, pad7[8], field15, pad16[8], field24;
};
extern struct Actor1171Flags Level36_7B044Data80070300 __asm__("D_80070300");
extern unsigned char Level36_7B044Flag24 __asm__("D_80070300+24");
extern unsigned char Level36_7B044Flag15 __asm__("D_80070300+15");
extern unsigned char Level36_7B044Flag6 __asm__("D_80070300+6");
extern int Level36_7B044Data80070328 __asm__("D_80070328");
extern int Actor1171_D_level_36_800867F4 __asm__("D_level_36_800867F4");
extern int (*Level36_7B044SpawnMoby)() __asm__("SpawnMoby");
extern int Actor1171_func_level_36_80074AD0 __asm__("func_level_36_80074AD0");
extern int Level36_7B044_main_TEXT_END __asm__("main_TEXT_END");
extern int Actor1171_main_TEXT_START __asm__("main_TEXT_START");
void func_level_36_8007B044(void* ownerParameter) {
    register int ownerAddress19 __asm__("$19"), privateAddress18 __asm__("$18");
    register int resultOrIntermediate2 __asm__("$2"), fieldOrIntermediate3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField7 __asm__("$7"), initializedOneOrThree8 __asm__("$8");
    register int retainedIndexHeadingOrAddress16 __asm__("$16"),
        retainedIndexOrAddress17 __asm__("$17"), initializedThree20 __asm__("$20"),
        completeProductProjection9 __asm__("$9");
    long long completeSignedProduct;
    struct {
        int sp18, sp1C, sp20;
    } originalFrame;
    register int argumentOrField6 __asm__("$6");
    int temporaryWord2;
    int temporaryWord12;
    int temporaryWord13;
    unsigned int temporaryWord5;
    unsigned int temporaryWord10;
    unsigned char temporaryWord4;
    unsigned char temporaryWord8;
    unsigned char temporaryWord9;
    int temporaryWord11;
    int temporaryWord1;
    int temporaryWord3;
    int temporaryWord6;
    int temporaryWord7;
    ownerAddress19 = (int)ownerParameter;
    Level36_7B044Keep(ownerAddress19);
    privateAddress18 = Level36_7B044Field(ownerAddress19, int*, 0);
    if ((unsigned int)Level36_7B044Field(privateAddress18, unsigned int*, 0x84) >=
        (unsigned int)(int)&Actor1171_func_level_36_80074AD0) {
        temporaryWord13 = 0;
        argumentOrField6 = (int)&Actor1171_D_level_36_800867F4;
    loop_2:
        temporaryWord5 = Level36_7B044Field(privateAddress18, unsigned int*, 0x84);
        if ((unsigned int)temporaryWord5 < (unsigned int)argumentOrField6) {
            temporaryWord12 = 0;
            Level36_7B044Field(privateAddress18, int*, 0x80) =
                (int)(Level36_7B044Field(privateAddress18, int*, 0x80) ^
                      (Level36_7B044Field(temporaryWord5, unsigned char*, 0) << 8));
            do {
                fieldOrIntermediate3 = Level36_7B044Field(privateAddress18, int*, 0x80);
                resultOrIntermediate2 = fieldOrIntermediate3 & 0x8000;
                if (resultOrIntermediate2) {
                    resultOrIntermediate2 = fieldOrIntermediate3 * 2;
                    resultOrIntermediate2 ^= 0x8005;
                } else
                    resultOrIntermediate2 = fieldOrIntermediate3 * 2;
                Level36_7B044Field(privateAddress18, int*, 0x80) = resultOrIntermediate2;
                temporaryWord12 += 1;
            } while (temporaryWord12 < 8);
            temporaryWord13 += 1;
            Level36_7B044Field(privateAddress18, unsigned int*, 0x84) =
                (unsigned int)(Level36_7B044Field(privateAddress18, unsigned int*, 0x84) + 1);
            if (temporaryWord13 < 0x40) {
                goto loop_2;
            }
        }
    }
    temporaryWord8 = Level36_7B044Field(ownerAddress19, unsigned char*, 0x48);
    switch (temporaryWord8) {
        case 0:
        case 1:
            if (Level36_7B044UpdateMobyInteractionGate(ownerAddress19, 0) != 0) {
                temporaryWord9 = Level36_7B044Field(ownerAddress19, unsigned char*, 0x49);
                if (temporaryWord9 == 9) {
                    Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                        (unsigned char)Level36_7B044Field(privateAddress18, unsigned char*, 0x4F);
                } else if (temporaryWord9 == 0xA) {
                    Level36_7B044Data8006C7B4 |= 1;
                }
                Level36_7B044StartDialogue(ownerAddress19, 0, 2);
                Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 2U;
                return;
            }
            if (Level36_7B044Field(ownerAddress19, int*, 0x18) & 0x04000000) {
                Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 6U;
                argumentOrField4 = ownerAddress19;
                argumentOrField5 = 6;
                goto block_133;
            } else {
                if (Level36_7B044Field(privateAddress18, unsigned int*, 0x84) == 0) {
                    Level36_7B044Field(privateAddress18, unsigned int*, 0x84) =
                        (unsigned int)(Level36_7B044Data8006C58C +
                                       ((int)&Actor1171_main_TEXT_START + 2));
                    MATCHING_BARRIER_VOLATILE("memory");
                }
                resultOrIntermediate2 = Level36_7B044Field(privateAddress18, unsigned int*, 132);
                fieldOrIntermediate3 = (int)&Level36_7B044_main_TEXT_END;
                Level36_7B044Keep(fieldOrIntermediate3);
                if ((unsigned int)resultOrIntermediate2 < (unsigned int)fieldOrIntermediate3) {
                    argumentOrField5 = 0;
                    argumentOrField6 = fieldOrIntermediate3;
                loop_23:
                    temporaryWord10 = Level36_7B044Field(privateAddress18, unsigned int*, 0x84);
                    if ((unsigned int)temporaryWord10 < (unsigned int)argumentOrField6) {
                        argumentOrField4 = 0;
                        Level36_7B044Field(privateAddress18, int*, 0x80) =
                            (int)(Level36_7B044Field(privateAddress18, int*, 0x80) ^
                                  (Level36_7B044Field(temporaryWord10, unsigned char*, 0) << 8));
                        do {
                            fieldOrIntermediate3 = Level36_7B044Field(privateAddress18, int*, 0x80);
                            resultOrIntermediate2 = fieldOrIntermediate3 & 0x8000;
                            if (resultOrIntermediate2) {
                                resultOrIntermediate2 = fieldOrIntermediate3 * 2;
                                resultOrIntermediate2 ^= 0x8005;
                            } else
                                resultOrIntermediate2 = fieldOrIntermediate3 * 2;
                            Level36_7B044Field(privateAddress18, int*, 0x80) =
                                resultOrIntermediate2;
                            __asm__ volatile(
                                "" ::"m"(Level36_7B044Field(privateAddress18, int*, 128))
                                : "memory");
                            argumentOrField4 += 1;
                        } while ((resultOrIntermediate2 = argumentOrField4 < 8));
                        MATCHING_BARRIER_VOLATILE("memory");
                        resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 128);
                        fieldOrIntermediate3 =
                            Level36_7B044Field(privateAddress18, unsigned int*, 132);
                        resultOrIntermediate2 &= 3;
                        resultOrIntermediate2++;
                        fieldOrIntermediate3 += resultOrIntermediate2;
                        argumentOrField5++;
                        Level36_7B044Field(privateAddress18, unsigned int*, 132) =
                            fieldOrIntermediate3;
                        if (argumentOrField5 >= 0x40) {
                            if (({
                                    resultOrIntermediate2 =
                                        (unsigned int)fieldOrIntermediate3 <
                                        (unsigned int)(int)&Level36_7B044_main_TEXT_END;
                                    Level36_7B044Keep(resultOrIntermediate2);
                                    resultOrIntermediate2 == 0;
                                })) {
                                goto block_30;
                            }
                        } else {
                            goto loop_23;
                        }
                    } else {
                    block_30:
                        Level36_7B044Field(privateAddress18, unsigned int*, 0x84) =
                            (unsigned int)(int)&Actor1171_func_level_36_80074AD0;
                    }
                }
                if ((Level36_7B044Field(privateAddress18, unsigned int*, 0x84) ==
                     (int)&Actor1171_D_level_36_800867F4) &&
                    (Level36_7B044Field(privateAddress18, int*, 0x80) != 0)) {
                    resultOrIntermediate2 = Level36_7B044Flag6;
                    fieldOrIntermediate3 = Level36_7B044Flag24;
                    resultOrIntermediate2 &= 254;
                    Level36_7B044Flag6 = resultOrIntermediate2;
                    resultOrIntermediate2 = Level36_7B044Flag15;
                    fieldOrIntermediate3 &= 254;
                    Level36_7B044Flag24 = fieldOrIntermediate3;
                    resultOrIntermediate2 &= 254;
                    Level36_7B044Flag15 = resultOrIntermediate2;
                    Level36_7B044Field(privateAddress18, int*, 0x80) = 0;
                }
                temporaryWord11 = Level36_7B044Field(ownerAddress19, unsigned char*, 0x49);
                if ((unsigned int)temporaryWord11 >= 14U)
                    goto compareLoadedStateForIdle;
                switch (temporaryWord11) {
                    case 0:
                        if ((Level36_7B044Data8006C7B4 & 1) ||
                            (Level36_7B044Field((int)&Level36_7B044Data80070300 +
                                                    Level36_7B044Data8006C58C,
                                                unsigned char*, 0) &
                             1)) {
                            Level36_7B044DeleteMoby(ownerAddress19);
                            return;
                        }
                        if (Level36_7B044Field(privateAddress18, int*, 0x60) != 0) {
                            temporaryWord1 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                            Level36_7B044CopyVector(
                                ownerAddress19 + 0xC,
                                Level36_7B044Field(temporaryWord1, int*, 0xC) +
                                    (Level36_7B044Field(temporaryWord1, short*, 2) * 0x10));
                            argumentOrField5 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                            fieldOrIntermediate3 = Level36_7B044Field(argumentOrField5, short*, 0);
                            resultOrIntermediate2 = Level36_7B044Field(argumentOrField5, short*, 2);
                            argumentOrField4 = fieldOrIntermediate3 + 1;
                            resultOrIntermediate2 += argumentOrField4;
                            fieldOrIntermediate3 = resultOrIntermediate2 % fieldOrIntermediate3;
                            Level36_7B044Field(argumentOrField5, short*, 2) = fieldOrIntermediate3;
                            temporaryWord6 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                            temporaryWord3 =
                                (Level36_7B044Field(temporaryWord6, short*, 2) * 0x10) +
                                Level36_7B044Field(temporaryWord6, int*, 0xC);
                            Level36_7B044Field(ownerAddress19, unsigned char*, 0x46) =
                                Level36_7B044PlanarHeadingLookup(
                                    Level36_7B044Field(temporaryWord3, int*, 0) -
                                        Level36_7B044Field(ownerAddress19, int*, 0xC),
                                    Level36_7B044Field(temporaryWord3, int*, 4) -
                                        Level36_7B044Field(ownerAddress19, int*, 0x10),
                                    0);
                            Level36_7B044ProbeGroundFromRaisedMoby(ownerAddress19);
                            Level36_7B044RefreshMobyQueryByte52(ownerAddress19);
                            Level36_7B044RefreshMobyPackedQueryField(ownerAddress19);
                            Level36_7B044RefreshMobySpatialGridAndBasis(ownerAddress19, 2);
                            Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                (unsigned char)Level36_7B044Field(
                                    (privateAddress18 +
                                     Level36_7B044Field(privateAddress18, int*, 0x60)),
                                    unsigned char*, 0x44);
                            if (Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) == 0xA) {
                                Level36_7B044Data8006C7B4 |= 1;
                                Level36_7B044Field(privateAddress18, signed char*, 5) = 1;
                            }
                        }
                        Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) =
                            (unsigned char)Level36_7B044Field(privateAddress18, int*, 0x64);
                        goto reloadStateForOriginalIdle;
                    case 1:
                        if (Level36_7B044CountListedMobysBelowState80(
                                Level36_7B044Field(privateAddress18, int*, 0x68)) == 0) {
                            argumentOrField4 = ownerAddress19;
                            Level36_7B044Keep(argumentOrField4);
                            resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 96);
                            resultOrIntermediate2++;
                            Level36_7B044Field(privateAddress18, int*, 96) = resultOrIntermediate2;
                            __asm__ volatile(
                                "" ::"m"(Level36_7B044Field(privateAddress18, int*, 96)));
                            resultOrIntermediate2 = Level36_7B044Field(
                                privateAddress18 + resultOrIntermediate2, unsigned char*, 68);
                            argumentOrField5 = 3;
                            Level36_7B044Field(privateAddress18, signed char*, 5) = 0;
                            Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                resultOrIntermediate2;
                            resultOrIntermediate2 = 4;
                            MATCHING_KEEP(resultOrIntermediate2);
                            Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                resultOrIntermediate2;
                            goto block_61;
                        }
                        goto reloadStateForOriginalIdle;
                    rejectOriginalActorList:
                        MATCHING_BARRIER_VOLATILE("$7");
                        argumentOrField7 = 0;
                        goto testOriginalActorListResult;
                    case 3:
                        argumentOrField7 = 1;
                        initializedOneOrThree8 = 1;
                        argumentOrField6 = Level36_7B044Data8006C550;
                        resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 104);
                        fieldOrIntermediate3 = Level36_7B044Data8006C730;
                        resultOrIntermediate2 *= 4;
                        resultOrIntermediate2 += fieldOrIntermediate3;
                        argumentOrField4 = Level36_7B044Field(resultOrIntermediate2, int*, 0);
                    scanOriginalActorList:
                        argumentOrField5 = Level36_7B044Field(argumentOrField4, unsigned short*, 0);
                        resultOrIntermediate2 = argumentOrField5 & 32767;
                        fieldOrIntermediate3 = resultOrIntermediate2 * 11;
                        fieldOrIntermediate3 *= 8;
                        fieldOrIntermediate3 += argumentOrField6;
                        resultOrIntermediate2 =
                            Level36_7B044Field(fieldOrIntermediate3, unsigned char*, 72);
                        if ((unsigned int)resultOrIntermediate2 >= 128U) {
                            resultOrIntermediate2 = (unsigned int)argumentOrField5 << 16;
                            goto advanceOriginalActorList;
                        }
                        resultOrIntermediate2 =
                            Level36_7B044Field(fieldOrIntermediate3, unsigned char*, 73);
                        if (resultOrIntermediate2 != initializedOneOrThree8)
                            goto rejectOriginalActorList;
                        resultOrIntermediate2 = (unsigned int)argumentOrField5 << 16;
                    advanceOriginalActorList:
                        argumentOrField4 += 2;
                        if (resultOrIntermediate2 >= 0)
                            goto scanOriginalActorList;
                    testOriginalActorListResult:
                        Level36_7B044Keep(argumentOrField7);
                        if (argumentOrField7 != 0) {
                            argumentOrField4 = ownerAddress19;
                            Level36_7B044Keep(argumentOrField4);
                            resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 96);
                            resultOrIntermediate2++;
                            Level36_7B044Field(privateAddress18, int*, 96) = resultOrIntermediate2;
                            __asm__ volatile(
                                "" ::"m"(Level36_7B044Field(privateAddress18, int*, 96)),
                                "r"(argumentOrField4));
                            resultOrIntermediate2 = Level36_7B044Field(
                                privateAddress18 + resultOrIntermediate2, unsigned char*, 68);
                            argumentOrField5 = 3;
                            Level36_7B044Field(privateAddress18, signed char*, 5) = 0;
                            Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                resultOrIntermediate2;
                            resultOrIntermediate2 = 4;
                            __asm__(""
                                    : "=r"(resultOrIntermediate2)
                                    : "0"(resultOrIntermediate2), "r"(argumentOrField4));
                            Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                resultOrIntermediate2;
                            goto block_61;
                        }
                        goto reloadStateForOriginalIdle;
                    case 8:
                        if ((Level36_7B044CountTimerDown(privateAddress18 + 0x50, 4) != 0) &&
                            (Level36_7B044Field(
                                 ((Level36_7B044Field(
                                       ((Level36_7B044Field(privateAddress18, int*, 0x6C) * 4) +
                                        privateAddress18),
                                       int*, 0x70) *
                                   0x58) +
                                  Level36_7B044Data8006C550),
                                 unsigned char*, 0x49) == 2)) {
                            argumentOrField4 = ownerAddress19;
                            argumentOrField5 = 4;
                            Level36_7B044Keep(argumentOrField5);
                            resultOrIntermediate2 = 180;
                            Level36_7B044Field(privateAddress18, int*, 80) = resultOrIntermediate2;
                            Level36_7B044RefreshMobySpatialGridAndBasis(argumentOrField4,
                                                                        argumentOrField5);
                            argumentOrField4 = ownerAddress19;
                            argumentOrField5 = 5;
                            resultOrIntermediate2 = 5;
                            goto block_62;
                        }
                        if (Level36_7B044Field(
                                ((Level36_7B044Field(
                                      ((Level36_7B044Field(privateAddress18, int*, 0x6C) * 4) +
                                       privateAddress18),
                                      int*, 0x70) *
                                  0x58) +
                                 Level36_7B044Data8006C550),
                                unsigned char*, 0x49) == 9) {
                            argumentOrField4 = ownerAddress19;
                            Level36_7B044Keep(argumentOrField4);
                            resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 96);
                            resultOrIntermediate2++;
                            Level36_7B044Field(privateAddress18, int*, 96) = resultOrIntermediate2;
                            __asm__ volatile(
                                "" ::"m"(Level36_7B044Field(privateAddress18, int*, 96)));
                            resultOrIntermediate2 = Level36_7B044Field(
                                privateAddress18 + resultOrIntermediate2, unsigned char*, 68);
                            argumentOrField5 = 3;
                            Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                resultOrIntermediate2;
                            resultOrIntermediate2 = 4;
                            __asm__(""
                                    : "=r"(resultOrIntermediate2)
                                    : "0"(resultOrIntermediate2), "r"(privateAddress18));
                            Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                resultOrIntermediate2;
                            goto block_61;
                        }
                        goto reloadStateForOriginalIdle;
                    case 9:
                        if ((Level36_7B044ApproximatePlanarDistance(
                                 ownerAddress19 + 0xC, (int)&Level36_7B044Data80070328) >=
                             0x1001) ||
                            (Level36_7B044AbsoluteByteAngleDelta(
                                 Level36_7B044Field(ownerAddress19, unsigned char*, 0x46),
                                 Level36_7B044PlanarHeadingLookup(
                                     Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 0) -
                                         Level36_7B044Field(ownerAddress19, int*, 0xC),
                                     Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 4) -
                                         Level36_7B044Field(ownerAddress19, int*, 0x10),
                                     0)) >= 0x21)) {
                            argumentOrField4 = ownerAddress19;
                            Level36_7B044Keep(argumentOrField4);
                            argumentOrField5 = 3;
                            resultOrIntermediate2 = 4;
                            Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                resultOrIntermediate2;
                            goto block_61;
                        }
                        goto reloadStateForOriginalIdle;
                    case 11:
                        Level36_7B044PlaySoundFromGlobalByteTable(ownerAddress19, 1, 0);
                        Level36_7B044MaskLinkedRecordFlagsById(
                            Level36_7B044Field(privateAddress18, int*, 0x7C), 0xFC, 0);
                        argumentOrField6 = 0x10000002;
                        Level36_7B044Keep(argumentOrField6);
                        argumentOrField4 = ownerAddress19;
                        resultOrIntermediate2 = 12;
                        fieldOrIntermediate3 = (int)&Level36_7B044Data80070328 + 524;
                        Level36_7B044Keep(fieldOrIntermediate3);
                        Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                            resultOrIntermediate2;
                        resultOrIntermediate2 = Level36_7B044Field(fieldOrIntermediate3, int*, 0);
                        argumentOrField5 = 3;
                        resultOrIntermediate2 |= argumentOrField6;
                        Level36_7B044Field(fieldOrIntermediate3, int*, 0) = resultOrIntermediate2;
                    block_61:
                        resultOrIntermediate2 = 3;
                    block_62:
                        Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) =
                            resultOrIntermediate2;
                        Level36_7B044RequestMobyAnimation(argumentOrField4, argumentOrField5);
                        goto reloadStateForOriginalIdle;
                    case 13:
                        if (Level36_7B044QueryShiftedLinkedRecordWordByByteId(
                                Level36_7B044Field(privateAddress18, int*, 0x7C)) &
                            2) {
                            Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 0x63U;
                        }
                        Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 0x20C) =
                            (int)(Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 0x20C) |
                                  0x10000002);
                        goto reloadStateForOriginalIdle;
                    default:
                    reloadStateForOriginalIdle:
                        temporaryWord11 = Level36_7B044Field(ownerAddress19, unsigned char*, 73);
                    compareLoadedStateForIdle:
                        MATCHING_BARRIER_VOLATILE("$2");
                        if ((temporaryWord11 != 8) && (Level36_7B044Data8006C770 != 0)) {
                            if (Level36_7B044Field(privateAddress18, int*, 0x50) == 0) {
                                Level36_7B044RequestMobyAnimation(ownerAddress19, 1);
                                Level36_7B044Field(privateAddress18, int*, 0x50) =
                                    Level36_7B044RandBetween(3, 6);
                                return;
                            }
                            Level36_7B044RequestMobyAnimation(ownerAddress19, 0);
                            Level36_7B044Field(privateAddress18, int*, 0x50) =
                                (int)(Level36_7B044Field(privateAddress18, int*, 0x50) - 1);
                            return;
                        }
                        return;
                }
            }
            break;
        case 2:
            Level36_7B044Field(ownerAddress19, int*, 0x18) = 0;
            if (Level36_7B044Data8006E344 != 1) {
                temporaryWord4 = Level36_7B044Field(ownerAddress19, unsigned char*, 0x49);
                switch (temporaryWord4) {
                    case 2:
                        argumentOrField6 = 0;
                        resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 108);
                        argumentOrField4 = Level36_7B044Field(privateAddress18, int*, 92);
                        resultOrIntermediate2 *= 4;
                        resultOrIntermediate2 += privateAddress18;
                        fieldOrIntermediate3 = Level36_7B044Field(resultOrIntermediate2, int*, 112);
                        retainedIndexHeadingOrAddress16 =
                            Level36_7B044Field(argumentOrField4, short*, 2);
                        resultOrIntermediate2 = fieldOrIntermediate3 * 11;
                        resultOrIntermediate2 *= 8;
                        fieldOrIntermediate3 = Level36_7B044Data8006C550;
                        retainedIndexHeadingOrAddress16 *= 16;
                        resultOrIntermediate2 += fieldOrIntermediate3;
                        fieldOrIntermediate3 = Level36_7B044Field(argumentOrField4, int*, 12);
                        argumentOrField7 = Level36_7B044Field(resultOrIntermediate2, int*, 12);
                        resultOrIntermediate2 = Level36_7B044Field(resultOrIntermediate2, int*, 16);
                        fieldOrIntermediate3 =
                            retainedIndexHeadingOrAddress16 + fieldOrIntermediate3;
                        argumentOrField4 = Level36_7B044Field(fieldOrIntermediate3, int*, 0);
                        argumentOrField5 = Level36_7B044Field(fieldOrIntermediate3, int*, 4);
                        argumentOrField4 = argumentOrField7 - argumentOrField4;
                        argumentOrField5 = resultOrIntermediate2 - argumentOrField5;
                        resultOrIntermediate2 = Level36_7B044PlanarHeadingLookup(
                            argumentOrField4, argumentOrField5, argumentOrField6, argumentOrField7);
                        argumentOrField5 = resultOrIntermediate2;
                        resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 92);
                        argumentOrField6 = 0;
                        argumentOrField4 = Level36_7B044Field(resultOrIntermediate2, int*, 12);
                        argumentOrField7 = 0;
                        Level36_7B044SetCameraMode11Target(
                            argumentOrField4 + retainedIndexHeadingOrAddress16, argumentOrField5,
                            argumentOrField6, argumentOrField7);
                        Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 6U;
                        return;
                    case 6:
                        if (Level36_7B044Data8006E048 == 1) {
                            resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 92);
                            fieldOrIntermediate3 =
                                Level36_7B044Field(resultOrIntermediate2, short*, 0);
                            resultOrIntermediate2 =
                                Level36_7B044Field(resultOrIntermediate2, short*, 2);
                            argumentOrField4 = fieldOrIntermediate3 + 1;
                            resultOrIntermediate2 += argumentOrField4;
                            retainedIndexOrAddress17 = resultOrIntermediate2 % fieldOrIntermediate3;
                            argumentOrField6 = (int)&Level36_7B044Data80070328 + 100;
                            fieldOrIntermediate3 = Level36_7B044Field(argumentOrField6, int*, 0);
                            argumentOrField4 = (int)&originalFrame.sp18;
                            fieldOrIntermediate3 >>= 4;
                            fieldOrIntermediate3 *= 2;
                            argumentOrField7 = Level36_7B044Field(
                                (int)&Level36_7B044Data80065920 + fieldOrIntermediate3, short*, 0);
                            argumentOrField5 = argumentOrField4;
                            resultOrIntermediate2 = argumentOrField7 * 3;
                            resultOrIntermediate2 >>= 3;
                            originalFrame.sp18 = resultOrIntermediate2;
                            fieldOrIntermediate3 = Level36_7B044Field(
                                (int)&Level36_7B044Data800658A0 + fieldOrIntermediate3, short*, 0);
                            argumentOrField6 -= 100;
                            originalFrame.sp20 = 0;
                            resultOrIntermediate2 = fieldOrIntermediate3 * 3;
                            resultOrIntermediate2 >>= 3;
                            originalFrame.sp1C = resultOrIntermediate2;
                            Level36_7B044AddVector(argumentOrField4, argumentOrField5,
                                                   argumentOrField6, argumentOrField7);
                            resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 92);
                            argumentOrField4 = ownerAddress19 + 12;
                            resultOrIntermediate2 =
                                Level36_7B044Field(resultOrIntermediate2, int*, 12);
                            argumentOrField5 = retainedIndexOrAddress17 * 16;
                            argumentOrField5 = resultOrIntermediate2 + argumentOrField5;
                            Level36_7B044CopyVector(argumentOrField4, argumentOrField5);
                            Level36_7B044Field(ownerAddress19, unsigned char*, 0x46) =
                                Level36_7B044PlanarHeadingLookup(
                                    originalFrame.sp18 -
                                        Level36_7B044Field(ownerAddress19, int*, 0xC),
                                    originalFrame.sp1C -
                                        Level36_7B044Field(ownerAddress19, int*, 0x10),
                                    0);
                            Level36_7B044Field(privateAddress18, int*, 0x64) = 8;
                            Level36_7B044RegisterTrackedValue(privateAddress18 + 0x64, 4,
                                                              (int)&Level36_7B044Data8006C7F8);
                            Level36_7B044Field(Level36_7B044Field(privateAddress18, int*, 0x5C),
                                               short*, 2) = (short)retainedIndexOrAddress17;
                            Level36_7B044RegisterTrackedValue(
                                Level36_7B044Field(privateAddress18, int*, 0x5C) + 2, 2,
                                (int)&Level36_7B044Data8006C7F8);
                            argumentOrField5 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                            fieldOrIntermediate3 = Level36_7B044Field(argumentOrField5, short*, 0);
                            resultOrIntermediate2 = Level36_7B044Field(argumentOrField5, short*, 2);
                            argumentOrField4 = fieldOrIntermediate3 + 1;
                            resultOrIntermediate2 += argumentOrField4;
                            fieldOrIntermediate3 = resultOrIntermediate2 % fieldOrIntermediate3;
                            Level36_7B044Field(argumentOrField5, short*, 2) = fieldOrIntermediate3;
                            Level36_7B044ProbeGroundFromRaisedMoby(ownerAddress19,
                                                                   argumentOrField5);
                            Level36_7B044RefreshMobyQueryByte52(ownerAddress19);
                            Level36_7B044RefreshMobyPackedQueryField(ownerAddress19);
                            Level36_7B044RefreshMobySpatialGridAndBasis(ownerAddress19, 2);
                            Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 7U;
                            return;
                        }
                        break;
                    case 7:
                        fieldOrIntermediate3 = Level36_7B044Data8006E160;
                        resultOrIntermediate2 = 11;
                        argumentOrField4 = ownerAddress19;
                        if (fieldOrIntermediate3 != resultOrIntermediate2) {
                            argumentOrField5 = 0;
                            resultOrIntermediate2 = 8;
                            Level36_7B044Field(argumentOrField4, unsigned char*, 73) =
                                resultOrIntermediate2;
                            resultOrIntermediate2 = 60;
                            goto block_131;
                        }
                        break;
                    case 8:
                        argumentOrField5 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                        fieldOrIntermediate3 = Level36_7B044Field(argumentOrField5, short*, 0);
                        resultOrIntermediate2 = Level36_7B044Field(argumentOrField5, short*, 2);
                        argumentOrField4 = fieldOrIntermediate3 - 2;
                        resultOrIntermediate2 += argumentOrField4;
                        fieldOrIntermediate3 = resultOrIntermediate2 % fieldOrIntermediate3;
                        Level36_7B044Field(argumentOrField5, short*, 2) = fieldOrIntermediate3;
                        Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 2U;
                        return;
                    case 10:
                        argumentOrField4 = 0x10000000;
                        Level36_7B044Keep(argumentOrField4);
                        resultOrIntermediate2 = 255;
                        Level36_7B044Field(privateAddress18, signed char*, 5) =
                            resultOrIntermediate2;
                        resultOrIntermediate2 = 11;
                        fieldOrIntermediate3 = (int)&Level36_7B044Data80070328 + 524;
                        Level36_7B044Keep(fieldOrIntermediate3);
                        Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                            resultOrIntermediate2;
                        resultOrIntermediate2 = Level36_7B044Field(fieldOrIntermediate3, int*, 0);
                        argumentOrField4 |= 2;
                        resultOrIntermediate2 |= argumentOrField4;
                        Level36_7B044Field(fieldOrIntermediate3, int*, 0) = resultOrIntermediate2;
                    default:
                        if (Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) == 9) {
                            Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                (unsigned char)Level36_7B044Field(
                                    (privateAddress18 +
                                     Level36_7B044Field(privateAddress18, int*, 0x60)),
                                    unsigned char*, 0x44);
                        }
                        Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 0U;
                        return;
                }
            }
            break;
        case 3:
        case 4:
            argumentOrField4 = (int)&originalFrame.sp18;
            Level36_7B044Keep(argumentOrField4);
            retainedIndexOrAddress17 = ownerAddress19 + 12;
            Level36_7B044Field(ownerAddress19, int*, 24) = 0;
            resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 92);
            __asm__ volatile("" ::"r"(resultOrIntermediate2) : "$6", "memory");
            argumentOrField6 = retainedIndexOrAddress17;
            argumentOrField5 = Level36_7B044Field(resultOrIntermediate2, short*, 2);
            resultOrIntermediate2 = Level36_7B044Field(resultOrIntermediate2, int*, 12);
            argumentOrField5 *= 16;
            Level36_7B044SubtractVector(argumentOrField4, resultOrIntermediate2 + argumentOrField5,
                                        argumentOrField6);
            resultOrIntermediate2 =
                Level36_7B044PlanarHeadingLookup(originalFrame.sp18, originalFrame.sp1C, 0);
            argumentOrField4 = ownerAddress19;
            retainedIndexHeadingOrAddress16 = resultOrIntermediate2;
            Level36_7B044Keep(retainedIndexHeadingOrAddress16);
            Level36_7B044TurnMobyTowardHeading(argumentOrField4, retainedIndexHeadingOrAddress16, 8,
                                               255, 1, 0);
            if (Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) == 5) {
                resultOrIntermediate2 = Level36_7B044MeasureVectorLength(&originalFrame.sp18, 0);
                fieldOrIntermediate3 = Level36_7B044Field(privateAddress18, int*, 84);
                fieldOrIntermediate3 -= 8;
                Level36_7B044Field(privateAddress18, int*, 84) = fieldOrIntermediate3;
                fieldOrIntermediate3 = Level36_7B044Field(privateAddress18, int*, 88);
                resultOrIntermediate2 >>= 1;
                fieldOrIntermediate3 = resultOrIntermediate2 < fieldOrIntermediate3;
                if (fieldOrIntermediate3)
                    Level36_7B044Field(privateAddress18, int*, 88) = resultOrIntermediate2;
                argumentOrField4 = retainedIndexHeadingOrAddress16 * 2;
                fieldOrIntermediate3 = Level36_7B044Field(
                    (int)&Level36_7B044Data80065920 + argumentOrField4, short*, 0);
                resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 88);
                Level36_7B044MultiplyComplete(fieldOrIntermediate3, resultOrIntermediate2);
                Level36_7B044CaptureLow(completeProductProjection9);
                resultOrIntermediate2 = completeProductProjection9 >> 12;
                originalFrame.sp18 = resultOrIntermediate2;
                fieldOrIntermediate3 = Level36_7B044Field(
                    (int)&Level36_7B044Data800658A0 + argumentOrField4, short*, 0);
                resultOrIntermediate2 = Level36_7B044Field(privateAddress18, int*, 88);
                Level36_7B044MultiplyComplete(fieldOrIntermediate3, resultOrIntermediate2);
                argumentOrField6 = retainedIndexOrAddress17;
                argumentOrField4 = (int)&originalFrame.sp18;
                originalFrame.sp20 = 0;
                Level36_7B044CaptureLow(completeProductProjection9);
                resultOrIntermediate2 = completeProductProjection9 >> 12;
                originalFrame.sp1C = resultOrIntermediate2;
                originalFrame.sp20 = Level36_7B044Field(privateAddress18, int*, 0x54);
                argumentOrField5 = argumentOrField4;
                Level36_7B044AddVector(argumentOrField4, argumentOrField5, argumentOrField6);
                Level36_7B044ResolveMobyMotionCollision(ownerAddress19, &originalFrame.sp18, 0x100,
                                                        0x100, 0x1021);
                Level36_7B044CopyVector(&originalFrame.sp18, retainedIndexOrAddress17);
                if (Level36_7B044Field(privateAddress18, int*, 0x54) < 0) {
                    originalFrame.sp20 += 0x80;
                    if (Level36_7B044QueryWorldHeight(&originalFrame.sp18, 0x100) != 0) {
                        Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 4U;
                    }
                }
            } else if (Level36_7B044AbsoluteByteAngleDelta(
                           retainedIndexHeadingOrAddress16,
                           Level36_7B044Field(ownerAddress19, unsigned char*, 0x46)) < 0x10) {
                fieldOrIntermediate3 = Level36_7B044Field(ownerAddress19, unsigned char*, 73);
                Level36_7B044Keep(fieldOrIntermediate3);
                resultOrIntermediate2 = (unsigned int)(fieldOrIntermediate3 - 1) < 2U;
                fieldOrIntermediate3 &= 255;
                if (resultOrIntermediate2 || ({
                        initializedThree20 = 3;
                        Level36_7B044Keep(initializedThree20);
                        fieldOrIntermediate3 == initializedThree20;
                    }) ||
                    fieldOrIntermediate3 == 10) {
                    argumentOrField6 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                    fieldOrIntermediate3 = Level36_7B044Field(argumentOrField6, short*, 0);
                    resultOrIntermediate2 = Level36_7B044Field(argumentOrField6, short*, 2);
                    argumentOrField4 = fieldOrIntermediate3 + 1;
                    resultOrIntermediate2 += argumentOrField4;
                    fieldOrIntermediate3 = resultOrIntermediate2 % fieldOrIntermediate3;
                    Level36_7B044Field(argumentOrField6, short*, 2) = fieldOrIntermediate3;
                    Level36_7B044RequestMobyAnimation(ownerAddress19, 0, argumentOrField6);
                    Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 0U;
                } else if ((Level36_7B044ApproximatePlanarDistance(
                                retainedIndexOrAddress17, (int)&Level36_7B044Data80070328) <
                            0xC00) &&
                           (Level36_7B044AbsoluteByteAngleDelta(
                                Level36_7B044Field(ownerAddress19, unsigned char*, 0x46),
                                Level36_7B044PlanarHeadingLookup(
                                    Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 0) -
                                        Level36_7B044Field(ownerAddress19, int*, 0xC),
                                    Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 4) -
                                        Level36_7B044Field(ownerAddress19, int*, 0x10),
                                    0)) < 0x18) &&
                           (Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) != 0xC)) {
                    Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 9U;
                    Level36_7B044Field(privateAddress18, int*, 0x50) = initializedThree20;
                    Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 0U;
                    Level36_7B044RequestMobyAnimation(ownerAddress19, 0);
                } else {
                    if (Level36_7B044MeasureVectorLength(&originalFrame.sp18, 0) < 0x100) {
                        argumentOrField5 = Level36_7B044Field(privateAddress18, int*, 0x5C);
                        fieldOrIntermediate3 = Level36_7B044Field(argumentOrField5, short*, 0);
                        argumentOrField4 = Level36_7B044Field(argumentOrField5, short*, 2);
                        Level36_7B044Keep(argumentOrField4);
                        resultOrIntermediate2 = fieldOrIntermediate3 + 1;
                        resultOrIntermediate2 = argumentOrField4 + resultOrIntermediate2;
                        retainedIndexOrAddress17 = resultOrIntermediate2 % fieldOrIntermediate3;
                        Level36_7B044Keep(retainedIndexOrAddress17);
                        if (retainedIndexOrAddress17 == (fieldOrIntermediate3 - 1)) {
                            Level36_7B044PlaySoundFromGlobalByteTable(ownerAddress19, 2, 0);
                            Level36_7B044MaskLinkedRecordFlagsById(
                                Level36_7B044Field(privateAddress18, int*, 0x7C), 0xFC, 0);
                            Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 0xDU;
                            Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 0U;
                            Level36_7B044RequestMobyAnimation(ownerAddress19, 0);
                        } else {
                            fieldOrIntermediate3 = Level36_7B044Field(argumentOrField5, int*, 12);
                            resultOrIntermediate2 = retainedIndexOrAddress17 * 16;
                            resultOrIntermediate2 += fieldOrIntermediate3;
                            resultOrIntermediate2 =
                                Level36_7B044Field(resultOrIntermediate2, int*, 12);
                            __asm__ volatile("" ::: "$8", "memory");
                            initializedOneOrThree8 = 1;
                            Level36_7B044Keep(initializedOneOrThree8);
                            if (resultOrIntermediate2 == initializedOneOrThree8) {
                                argumentOrField4 = (int)&originalFrame.sp18;
                                Level36_7B044Keep(argumentOrField4);
                                retainedIndexHeadingOrAddress16 = ownerAddress19 + 12;
                                Level36_7B044Field(argumentOrField5, short*, 2) =
                                    retainedIndexOrAddress17;
                                resultOrIntermediate2 =
                                    Level36_7B044Field(privateAddress18, int*, 92);
                                argumentOrField6 = retainedIndexHeadingOrAddress16;
                                argumentOrField5 =
                                    Level36_7B044Field(resultOrIntermediate2, short*, 2);
                                resultOrIntermediate2 =
                                    Level36_7B044Field(resultOrIntermediate2, int*, 12);
                                argumentOrField5 *= 16;
                                Level36_7B044SubtractVector(
                                    argumentOrField4, resultOrIntermediate2 + argumentOrField5,
                                    argumentOrField6);
                                resultOrIntermediate2 =
                                    Level36_7B044MeasureVectorLength(&originalFrame.sp18, 0);
                                fieldOrIntermediate3 = 0x2AAAAAAB;
                                Level36_7B044MultiplyComplete(resultOrIntermediate2,
                                                              fieldOrIntermediate3);
                                argumentOrField4 = retainedIndexHeadingOrAddress16;
                                resultOrIntermediate2 >>= 31;
                                argumentOrField6 = Level36_7B044Field(privateAddress18, int*, 92);
                                Level36_7B044CaptureHigh(completeProductProjection9);
                                fieldOrIntermediate3 = completeProductProjection9 >> 2;
                                fieldOrIntermediate3 -= resultOrIntermediate2;
                                Level36_7B044Field(privateAddress18, int*, 88) =
                                    fieldOrIntermediate3;
                                argumentOrField5 = Level36_7B044Field(argumentOrField6, short*, 2);
                                MATCHING_BARRIER_VOLATILE("memory");
                                resultOrIntermediate2 =
                                    Level36_7B044Field(argumentOrField6, int*, 12);
                                Level36_7B044Field(privateAddress18, int*, 84) =
                                    Level36_7B044ComputeArcVerticalVelocity(
                                        argumentOrField4,
                                        resultOrIntermediate2 + (argumentOrField5 * 16),
                                        Level36_7B044Field(privateAddress18, int*, 88), -8, 0);
                                Level36_7B044RequestMobyAnimation(ownerAddress19, 4);
                                Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 4U;
                                Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) = 5U;
                            } else {
                                resultOrIntermediate2 = argumentOrField4 * 16;
                                resultOrIntermediate2 += fieldOrIntermediate3;
                                fieldOrIntermediate3 =
                                    Level36_7B044Field(resultOrIntermediate2, int*, 12);
                                argumentOrField7 = 2;
                                Level36_7B044Keep(argumentOrField7);
                                Level36_7B044Keep(privateAddress18);
                                argumentOrField4 = privateAddress18 + 100;
                                if (fieldOrIntermediate3 == argumentOrField7) {
                                    argumentOrField5 = 4;
                                    Level36_7B044Keep(argumentOrField5);
                                    retainedIndexHeadingOrAddress16 =
                                        (int)&Level36_7B044Data8006C7F8;
                                    Level36_7B044Keep(retainedIndexHeadingOrAddress16);
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    resultOrIntermediate2 = 1;
                                    goto writeSharedOriginalDescriptor14;
                                }
                                initializedOneOrThree8 = 3;
                                Level36_7B044Keep(initializedOneOrThree8);
                                resultOrIntermediate2 = 4;
                                if (fieldOrIntermediate3 == initializedOneOrThree8) {
                                    Level36_7B044Keep(privateAddress18);
                                    argumentOrField4 = privateAddress18 + 100;
                                    argumentOrField5 = 4;
                                    Level36_7B044Keep(argumentOrField5);
                                    retainedIndexHeadingOrAddress16 =
                                        (int)&Level36_7B044Data8006C7F8;
                                    Level36_7B044Keep(retainedIndexHeadingOrAddress16);
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    resultOrIntermediate2 = 2;
                                    Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                        resultOrIntermediate2;
                                    Level36_7B044Field(privateAddress18, int*, 100) =
                                        argumentOrField7;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5, argumentOrField6,
                                        argumentOrField7);
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 92);
                                    argumentOrField5 = 2;
                                    Level36_7B044Field(resultOrIntermediate2, short*, 2) =
                                        retainedIndexOrAddress17;
                                    argumentOrField4 =
                                        Level36_7B044Field(privateAddress18, int*, 92);
                                    __asm__ volatile("" ::: "$6", "memory");
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4 + 2, argumentOrField5, argumentOrField6);
                                    argumentOrField4 = privateAddress18 + 108;
                                    argumentOrField5 = 4;
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 108);
                                    __asm__ volatile("" ::: "$6", "memory");
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    resultOrIntermediate2++;
                                    Level36_7B044Field(privateAddress18, int*, 108) =
                                        resultOrIntermediate2;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5, argumentOrField6);
                                    argumentOrField4 = privateAddress18 + 96;
                                    argumentOrField5 = 4;
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    goto writeSharedOriginalDescriptor35;
                                }
                                Level36_7B044Keep(resultOrIntermediate2);
                                if (fieldOrIntermediate3 == resultOrIntermediate2) {
                                    Level36_7B044Keep(privateAddress18);
                                    argumentOrField4 = privateAddress18 + 100;
                                    argumentOrField5 = 4;
                                    Level36_7B044Keep(argumentOrField5);
                                    retainedIndexHeadingOrAddress16 =
                                        (int)&Level36_7B044Data8006C7F8;
                                    Level36_7B044Keep(retainedIndexHeadingOrAddress16);
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    resultOrIntermediate2 = 3;
                                writeSharedOriginalDescriptor14:
                                    Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                        resultOrIntermediate2;
                                    Level36_7B044Field(privateAddress18, int*, 100) =
                                        initializedOneOrThree8;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5, argumentOrField6,
                                        argumentOrField7);
                                    argumentOrField5 = 2;
                                    argumentOrField4 =
                                        Level36_7B044Field(privateAddress18, int*, 92);
                                    __asm__ volatile("" ::: "$6", "memory");
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4 + 2, argumentOrField5, argumentOrField6);
                                    argumentOrField4 = privateAddress18 + 104;
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 92);
                                    argumentOrField5 = 4;
                                    Level36_7B044Field(resultOrIntermediate2, short*, 2) =
                                        retainedIndexOrAddress17;
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 104);
                                    __asm__ volatile("" ::: "$6", "memory");
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    resultOrIntermediate2++;
                                    Level36_7B044Field(privateAddress18, int*, 104) =
                                        resultOrIntermediate2;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5, argumentOrField6);
                                    argumentOrField4 = privateAddress18 + 96;
                                    argumentOrField5 = 4;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5,
                                        retainedIndexHeadingOrAddress16);
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 96);
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18 + resultOrIntermediate2,
                                                           unsigned char*, 68);
                                    Level36_7B044Field(privateAddress18, signed char*, 5) = 0;
                                    Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                        resultOrIntermediate2;
                                    goto prepareOriginalVector;
                                }
                                resultOrIntermediate2 = 5;
                                Level36_7B044Keep(resultOrIntermediate2);
                                Level36_7B044Keep(privateAddress18);
                                if (fieldOrIntermediate3 == resultOrIntermediate2) {
                                    argumentOrField4 = privateAddress18 + 100;
                                    argumentOrField5 = 4;
                                    Level36_7B044Keep(argumentOrField5);
                                    retainedIndexHeadingOrAddress16 =
                                        (int)&Level36_7B044Data8006C7F8;
                                    Level36_7B044Keep(retainedIndexHeadingOrAddress16);
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    resultOrIntermediate2 = 10;
                                    Level36_7B044Field(ownerAddress19, unsigned char*, 73) =
                                        resultOrIntermediate2;
                                    __asm__ volatile("" ::"m"(Level36_7B044Field(
                                        ownerAddress19, unsigned char*, 73))
                                                     : "$2");
                                    resultOrIntermediate2 = 10;
                                    Level36_7B044Field(privateAddress18, int*, 100) =
                                        resultOrIntermediate2;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5, argumentOrField6,
                                        argumentOrField7);
                                    argumentOrField5 = 2;
                                    argumentOrField4 =
                                        Level36_7B044Field(privateAddress18, int*, 92);
                                    __asm__ volatile("" ::: "$6", "memory");
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4 + 2, argumentOrField5, argumentOrField6);
                                    argumentOrField4 = privateAddress18 + 96;
                                    argumentOrField5 = 4;
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 92);
                                    argumentOrField6 = retainedIndexHeadingOrAddress16;
                                    Level36_7B044Field(resultOrIntermediate2, short*, 2) =
                                        retainedIndexOrAddress17;
                                writeSharedOriginalDescriptor35:
                                    MATCHING_OBSERVE3_VOLATILE(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
                                    Level36_7B044RegisterTrackedValue(
                                        argumentOrField4, argumentOrField5, argumentOrField6);
                                    resultOrIntermediate2 =
                                        Level36_7B044Field(privateAddress18, int*, 96);
                                    fieldOrIntermediate3 =
                                        Level36_7B044Field(privateAddress18 + resultOrIntermediate2,
                                                           unsigned char*, 68);
                                    resultOrIntermediate2 = 1;
                                    Level36_7B044Field(privateAddress18, signed char*, 5) =
                                        resultOrIntermediate2;
                                    Level36_7B044Field(privateAddress18, unsigned char*, 2) =
                                        fieldOrIntermediate3;
                                    goto prepareOriginalVector;
                                }
                                Level36_7B044Field(argumentOrField5, short*, 2) =
                                    retainedIndexOrAddress17;
                            }
                        }
                    }
                prepareOriginalVector:
                    resultOrIntermediate2 = Level36_7B044Field(ownerAddress19, unsigned char*, 70);
                    resultOrIntermediate2 *= 2;
                    resultOrIntermediate2 = Level36_7B044Field(
                        (int)&Level36_7B044Data80065920 + resultOrIntermediate2, short*, 0);
                    __asm__ volatile("" ::: "$4", "memory");
                    argumentOrField4 = (int)&originalFrame.sp18;
                    Level36_7B044Keep(resultOrIntermediate2);
                    resultOrIntermediate2 >>= 5;
                    originalFrame.sp18 = resultOrIntermediate2;
                    resultOrIntermediate2 = Level36_7B044Field(ownerAddress19, unsigned char*, 70);
                    argumentOrField5 = argumentOrField4;
                    resultOrIntermediate2 *= 2;
                    resultOrIntermediate2 = Level36_7B044Field(
                        (int)&Level36_7B044Data800658A0 + resultOrIntermediate2, short*, 0);
                    __asm__ volatile("" ::: "$6", "memory");
                    argumentOrField6 = ownerAddress19 + 12;
                    originalFrame.sp20 = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(resultOrIntermediate2, "memory");
                    resultOrIntermediate2 >>= 5;
                    originalFrame.sp1C = resultOrIntermediate2;
                    Level36_7B044AddVector(argumentOrField4, argumentOrField5, argumentOrField6);
                    Level36_7B044ResolveMobyMotionCollision(ownerAddress19, &originalFrame.sp18,
                                                            0x100, 0x100, 5);
                }
            }
            if ((Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) == 4) &&
                (Level36_7B044Data8006C770 != 0)) {
                Level36_7B044RequestMobyAnimation(ownerAddress19, 3);
                Level36_7B044Field(ownerAddress19, unsigned char*, 0x48) = 3U;
            }
            if (Level36_7B044Field(ownerAddress19, unsigned char*, 0x49) == 0xC) {
                Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 0x20C) =
                    (int)(Level36_7B044Field((int)&Level36_7B044Data80070328, int*, 0x20C) |
                          0x10000002);
                return;
            }
            break;
        case 5:
            Level36_7B044Field(ownerAddress19, int*, 0x18) = 0;
            Level36_7B044CountTimerDown(privateAddress18 + 0x50, 4);
            temporaryWord2 = Level36_7B044ReadSelectedFrameScalar(ownerAddress19);
            temporaryWord7 = Level36_7B044Field(privateAddress18, int*, 0x78);
            if (temporaryWord7 == 0) {
                argumentOrField4 = 0x93;
                if (temporaryWord2 >= 8) {
                    Level36_7B044Field(privateAddress18, int*, 0x78) =
                        Level36_7B044SpawnMoby(argumentOrField4, ownerAddress19);
                }
            } else if (temporaryWord2 >= 0x10) {
                Level36_7B044Field(temporaryWord7, signed char*, 0x48) = 1;
            }
            resultOrIntermediate2 = Level36_7B044Data8006C770;
            argumentOrField4 = ownerAddress19;
            if (resultOrIntermediate2) {
                argumentOrField5 = 0;
                Level36_7B044Field(privateAddress18, int*, 120) = 0;
                goto block_132;
            }
            break;
        case 6:
            resultOrIntermediate2 = Level36_7B044Data8006C770;
            Level36_7B044Field(ownerAddress19, int*, 24) = 0;
            if (resultOrIntermediate2) {
                argumentOrField4 = ownerAddress19;
                argumentOrField5 = 0;
                resultOrIntermediate2 = 3;
            block_131:
                Level36_7B044Field(privateAddress18, int*, 80) = resultOrIntermediate2;
            block_132:
                Level36_7B044Field(argumentOrField4, unsigned char*, 72) = 0;
            block_133:
                MATCHING_OBSERVE2_VOLATILE(argumentOrField4, argumentOrField5);
                Level36_7B044RequestMobyAnimation(argumentOrField4, argumentOrField5);
            }
            break;
    }
}
#undef Level36_7B044Field
#undef Level36_7B044Keep

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_36/moby/func_level_36_8007C290.s SHA256 8100dd0257285a9e7262b7e61aca30c5a489cc13ead515e1040d35f1d1d05ef0. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int FrozenAltarsC290RequestMobyAnimation() __asm__("func_80034F40");       /* extern */
int FrozenAltarsC290UpdateMobyMotionDescriptor() __asm__("func_80035194"); /* extern */
int FrozenAltarsC290TurnMobyTowardPlayer() __asm__("func_8003573C");       /* extern */
int FrozenAltarsC290TestPaddedRotatedBox() __asm__("func_80036220");       /* extern */
int FrozenAltarsC290RandBetween() __asm__("func_8003636C");                /* extern */
int FrozenAltarsC290EmitMobyVertexParticles() __asm__("func_800369B8");    /* extern */
int FrozenAltarsC290SpawnMobyFromValueSelector() __asm__("func_80036A68"); /* extern */
int FrozenAltarsC290InitializeMobyMotionStateWithDeceleration() __asm__(
    "func_80038F14");                                                          /* extern */
int FrozenAltarsC290MarkMobyCollectionBit() __asm__("func_8003BA00");          /* extern */
int FrozenAltarsC290PlanarHeadingLookup() __asm__("func_8004E880");            /* extern */
int FrozenAltarsC290AbsoluteByteAngleDelta() __asm__("func_8004F264");         /* extern */
int FrozenAltarsC290ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int FrozenAltarsC290DeleteMoby() __asm__("func_80055B18");                     /* extern */
int FrozenAltarsC290RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int FrozenAltarsC290ReadSelectedFrameScalar() __asm__("func_80055E84");        /* extern */
extern int FrozenAltarsC290_D_8006C550 __asm__("D_8006C550");
extern int FrozenAltarsC290_D_8006C770 __asm__("D_8006C770");
extern int FrozenAltarsC290_D_8006E020 __asm__("D_8006E020");
extern int FrozenAltarsC290_D_8006E024 __asm__("D_8006E024");
extern unsigned short FrozenAltarsC290_D_8006E040 __asm__("D_8006E040");
extern unsigned char FrozenAltarsC290_D_80070328 __asm__("D_80070328");
extern unsigned char (*FrozenAltarsC290_SpawnParticle)(unsigned char, unsigned char, void*,
                                                       int*) __asm__("SpawnParticle");
extern int (*FrozenAltarsC290_unk_ovlheader_800743F0)() __asm__("unk_ovlheader_800743F0");

void func_level_36_8007C290(void* input_arg0) {
    register void* owner __asm__("$17") = input_arg0;
    /* Original stack offsets 0x28/0x2C/0x30, followed by padding. */
    struct {
        int sp28, sp2C, sp30, pad34;
    } frame;
    register int headerArg7 __asm__("$19");
    register unsigned char* global70328 __asm__("$16");
    register void* callOwner __asm__("$4");
    register int nextState __asm__("$5");
    int helperResult;
    register int ownerFlag49 __asm__("$2");
    int objectIndex;
    int delta0;
    int delta3;
    register int resetCondition __asm__("$2");
    register unsigned char currentState __asm__("$3");
    register unsigned char storedState __asm__("$2");
    register void* ownerData __asm__("$18");

    ownerData = M2C_FIELD(owner, void**, 0);
    if ((M2C_FIELD(owner, unsigned char*, 0x48) != 8) &&
        (M2C_FIELD(owner, int*, 0x18) & 0x04000000)) {
        /* Incoming owner remains in a0; original a1/a2/a3 are 1/0/0. */
        FrozenAltarsC290SpawnMobyFromValueSelector(owner, 1, 0, 0);
        FrozenAltarsC290InitializeMobyMotionStateWithDeceleration(owner, ownerData + 0x44, 0, 8);
        M2C_FIELD(ownerData, signed char*, 0x53) = 0x17;
        M2C_FIELD(ownerData, short*, 0x4E) = 0x280;
    }
    currentState = M2C_FIELD(owner, unsigned char*, 0x48);
    switch (currentState) {
        case 0:
        case 1:
            if (FrozenAltarsC290ApproximatePlanarDistance(owner + 0xC,
                                                          &FrozenAltarsC290_D_80070328) < 0x1400) {
                delta0 = ((M2C_FIELD(owner, int*, 0x14) - M2C_FIELD(owner, short*, 0x38)) -
                          M2C_FIELD(&FrozenAltarsC290_D_80070328, int*, 8)) +
                         M2C_FIELD(&FrozenAltarsC290_D_80070328, int*, 0x44);
                if (delta0 < 0) {
                    delta0 = -delta0;
                }
                if (delta0 < 0x400) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 2U;
                    FrozenAltarsC290RequestMobyAnimation(owner, 2);
                } else {
                    goto testOwnerData0;
                }
            } else {
            testOwnerData0:
                if (M2C_FIELD(ownerData, int*, 0) == 1) {
                    if ((FrozenAltarsC290TestPaddedRotatedBox(&FrozenAltarsC290_D_80070328,
                                                              ownerData + 0x14, 0, 0x800) != 0) &&
                        (FrozenAltarsC290AbsoluteByteAngleDelta(
                             (int)(FrozenAltarsC290_D_8006E040 << 0x10) >> 0x14,
                             FrozenAltarsC290PlanarHeadingLookup(
                                 M2C_FIELD(owner, int*, 0xC) - FrozenAltarsC290_D_8006E020,
                                 M2C_FIELD(owner, int*, 0x10) - FrozenAltarsC290_D_8006E024, 0)) <
                         0x1C)) {
                        callOwner = owner;
                        nextState = 7;
                        storedState = 7;
                        goto setStateAndClear49;
                    } else {
                        goto updateIdleState;
                    }
                } else {
                updateIdleState:
                    FrozenAltarsC290TurnMobyTowardPlayer(owner, 6, 0, 1);
                    if (FrozenAltarsC290_D_8006C770 != 0) {
                        if (M2C_FIELD(ownerData, int*, 4) == 0) {
                            FrozenAltarsC290RequestMobyAnimation(owner, 1);
                            M2C_FIELD(ownerData, int*, 4) = FrozenAltarsC290RandBetween(3, 6);
                        } else {
                            FrozenAltarsC290RequestMobyAnimation(owner, 0);
                            M2C_FIELD(ownerData, int*, 4) =
                                (int)(M2C_FIELD(ownerData, int*, 4) - 1);
                        }
                    }
                }
            }
            break;
        case 2:
            FrozenAltarsC290TurnMobyTowardPlayer(owner, 6, 0, 1);
            if (FrozenAltarsC290_D_8006C770 != 0) {
                M2C_FIELD(owner, unsigned char*, 0x48) = 3U;
                FrozenAltarsC290RequestMobyAnimation(owner, 3);
            }
            break;
        case 3:
            helperResult = FrozenAltarsC290ApproximatePlanarDistance(owner + 0xC,
                                                                     &FrozenAltarsC290_D_80070328);
            if (helperResult >= 0x1801) {
                M2C_FIELD(owner, unsigned char*, 0x48) = 4U;
                FrozenAltarsC290RequestMobyAnimation(owner, 4);
            } else if (helperResult < 0xE00) {
                delta3 = ((M2C_FIELD(owner, int*, 0x14) - M2C_FIELD(owner, short*, 0x38)) -
                          M2C_FIELD(&FrozenAltarsC290_D_80070328, int*, 8)) +
                         M2C_FIELD(&FrozenAltarsC290_D_80070328, int*, 0x44);
                if (delta3 < 0) {
                    delta3 = -delta3;
                }
                if ((delta3 < 0x400) &&
                    (FrozenAltarsC290TurnMobyTowardPlayer(owner, 6, 0, 1) != 0)) {
                    if (FrozenAltarsC290AbsoluteByteAngleDelta(
                            (int)(FrozenAltarsC290_D_8006E040 << 0x10) >> 0x14,
                            FrozenAltarsC290PlanarHeadingLookup(
                                M2C_FIELD(owner, int*, 0xC) - FrozenAltarsC290_D_8006E020,
                                M2C_FIELD(owner, int*, 0x10) - FrozenAltarsC290_D_8006E024, 0)) <
                        0x1C) {
                        nextState = 5;
                        callOwner = owner;
                        storedState = 5;
                    setStateAndClear49:
                        M2C_FIELD(owner, unsigned char*, 0x49) = 0U;
                        M2C_FIELD(owner, unsigned char*, 0x48) = storedState;
                        FrozenAltarsC290RequestMobyAnimation(callOwner, nextState);
                    }
                }
            }
            break;
        case 4:
            resetCondition = FrozenAltarsC290_D_8006C770;
            /* Preserve the distinct original state-4 route to the shared test. */
            MATCHING_KEEP_VOLATILE(resetCondition);
            goto testResetCondition;
            break;
        case 5:
            FrozenAltarsC290TurnMobyTowardPlayer(owner, 6, 0, 1);
            if ((unsigned int)(M2C_FIELD(&FrozenAltarsC290_D_80070328, int*, 0x50) - 7) < 2U) {
                M2C_FIELD(owner, unsigned char*, 0x49) = 1U;
            }
            if (FrozenAltarsC290_D_8006C770 != 0) {
                if (M2C_FIELD(owner, unsigned char*, 0x49) != 0) {
                    M2C_FIELD(owner, unsigned char*, 0x48) = 6U;
                    FrozenAltarsC290RequestMobyAnimation(owner, 6);
                } else {
                    goto resetState;
                }
            }
            break;
        case 6:
            FrozenAltarsC290TurnMobyTowardPlayer(owner, 6, 0, 1);
            resetCondition = FrozenAltarsC290_D_8006C770;
            goto testResetCondition;
        case 7:
            objectIndex = M2C_FIELD(ownerData, int*, 0x34);
            if ((objectIndex >= 0) &&
                (M2C_FIELD(((objectIndex * 0x58) + FrozenAltarsC290_D_8006C550), unsigned char*,
                           0x48) &
                 0x80)) {
                M2C_FIELD(ownerData, int*, 0x30) = 0;
                M2C_FIELD(ownerData, int*, 0x34) = -1;
            }
            ownerFlag49 = M2C_FIELD(owner, unsigned char*, 0x49);
            /* Original s3 producer follows the byte load and survives both calls. */
            headerArg7 = 1;
            __asm__("" : "=r"(headerArg7) : "0"(headerArg7), "r"(ownerFlag49));
            if (ownerFlag49 == headerArg7) {
                FrozenAltarsC290_unk_ovlheader_800743F0(
                    owner,
                    FrozenAltarsC290PlanarHeadingLookup(
                        M2C_FIELD(ownerData, int*, 8) - M2C_FIELD(owner, int*, 0xC),
                        M2C_FIELD(ownerData, int*, 0xC) - M2C_FIELD(owner, int*, 0x10), 0),
                    0x80, 0x280, 0x280, 0x27, ownerData + 0x2C, headerArg7,
                    M2C_FIELD(ownerData, int*, 0x30));
                resetCondition =
                    FrozenAltarsC290ApproximatePlanarDistance(owner + 0xC, ownerData + 8) < 0x200;
            testResetCondition:
                if (resetCondition != 0) {
                resetState:
                    M2C_FIELD(ownerData, int*, 4) = 3;
                    M2C_FIELD(owner, unsigned char*, 0x48) = 0U;
                    FrozenAltarsC290RequestMobyAnimation(owner, 0);
                }
                break;
            }
            global70328 = &FrozenAltarsC290_D_80070328;
            FrozenAltarsC290_unk_ovlheader_800743F0(
                owner,
                FrozenAltarsC290PlanarHeadingLookup(
                    M2C_FIELD(global70328, int*, 0) - M2C_FIELD(owner, int*, 0xC),
                    M2C_FIELD(global70328, int*, 4) - M2C_FIELD(owner, int*, 0x10), 0),
                0x80, 0x280, 0x280, 0x27, ownerData + 0x2C, headerArg7,
                M2C_FIELD(ownerData, int*, 0x30));
            if (FrozenAltarsC290TestPaddedRotatedBox(global70328, ownerData + 0x14, 0x400, 0x800) !=
                0) {
                if (FrozenAltarsC290AbsoluteByteAngleDelta(
                        (int)(FrozenAltarsC290_D_8006E040 << 0x10) >> 0x14,
                        FrozenAltarsC290PlanarHeadingLookup(
                            M2C_FIELD(owner, int*, 0xC) - FrozenAltarsC290_D_8006E020,
                            M2C_FIELD(owner, int*, 0x10) - FrozenAltarsC290_D_8006E024, 0)) <
                    0x21) {
                    if ((unsigned int)(M2C_FIELD(global70328, int*, 0x50) - 7) < 2U) {
                        goto setOwnerFlag49;
                    }
                } else {
                    goto setOwnerFlag49Alias;
                }
            } else {
            setOwnerFlag49:
            setOwnerFlag49Alias:
                M2C_FIELD(owner, unsigned char*, 0x49) = 1U;
            }
            break;
        case 8:
            if (FrozenAltarsC290UpdateMobyMotionDescriptor(owner, ownerData + 0x44) == 0x100) {
                FrozenAltarsC290RefreshMobySpatialGridAndBasis(owner, 4);
                FrozenAltarsC290MarkMobyCollectionBit(owner);
                FrozenAltarsC290EmitMobyVertexParticles(owner, 0x30);
                FrozenAltarsC290DeleteMoby(owner);
            }
            break;
    }
    if ((M2C_FIELD(owner, unsigned short*, 0x3C) != 0x101) ||
        (FrozenAltarsC290ReadSelectedFrameScalar(owner) < 0x32) ||
        (FrozenAltarsC290ReadSelectedFrameScalar(owner) >= 0x83)) {
        FrozenAltarsC290RefreshMobySpatialGridAndBasis(owner, 5);
        frame.sp28 = FrozenAltarsC290RandBetween(-0x10, 0x10);
        frame.sp2C = FrozenAltarsC290RandBetween(-0x10, 0x10);
        frame.sp30 = 0x20;
        FrozenAltarsC290_SpawnParticle(1, 0x25, owner, &frame.sp28);
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_36/moby/func_level_36_8007C940.s SHA256 1034bbf14bac5e7bcde1df3f6e42d031982466a4a6cbd65ae25e53e28f09e446. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int CharmedControllerPrepareCameraMode9Vectors() __asm__("func_80013AE4");            /* extern */
int CharmedControllerTransitionCameraModes9And10() __asm__("func_80013B7C");          /* extern */
int CharmedControllerMaskLinkedRecordFlagsById() __asm__("func_80021ED8");            /* extern */
int CharmedControllerQueryShiftedLinkedRecordWordByByteId() __asm__("func_80021F3C"); /* extern */
int CharmedControllerWriteMatchingLinkedSelectors() __asm__("func_80021F8C");         /* extern */
int CharmedControllerRequestMobyAnimation() __asm__("func_80034F40");                 /* extern */
int CharmedControllerSetMobyAnimation() __asm__("func_80034F80");                     /* extern */
int CharmedControllerCountTimerDown() __asm__("func_800359A4");                       /* extern */
int CharmedControllerApproximatePlanarDistance() __asm__("func_8004F334");            /* extern */
extern int CharmedController_D_8006C550 __asm__("D_8006C550");
extern int CharmedController_D_8006C58C __asm__("D_8006C58C");
extern int CharmedController_D_8006C770 __asm__("D_8006C770");
extern unsigned char CharmedController_D_8006C7B4 __asm__("D_8006C7B4");
extern Savepoint CharmedController_D_8006C7F8 __asm__("D_8006C7F8");
extern unsigned char CharmedController_D_8006E020 __asm__("D_8006E020");
extern int CharmedController_D_8006E048 __asm__("D_8006E048");
extern int CharmedController_D_8006E1D4 __asm__("D_8006E1D4");
extern int CharmedController_D_8006E1D8 __asm__("D_8006E1D8");
extern int CharmedController_D_8006E53C __asm__("D_8006E53C");
extern unsigned char CharmedController_D_80070300 __asm__("D_80070300");

void func_level_36_8007C940(Moby* inputOwner) {
    register Moby* owner __asm__("$17") = inputOwner;
    register int referencedPosition __asm__("$4");
    register int privateSelector4 __asm__("$5");
    register int privateSelector18 __asm__("$5");
    register int poolIndex __asm__("$3");
    register int distance __asm__("$3");
    register int substate __asm__("$3");
    register int poolState __asm__("$3");
    register void* activePoolMoby __asm__("$4");
    register void* privateData __asm__("$16");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register void* poolMoby __asm__("$3");
    register void* timerAddress6 __asm__("$4");
    register void* timerAddress7 __asm__("$4");

    MATCHING_KEEP(owner);
    substate = owner->substate;
    privateData = owner->mobyTag;
    switch (substate) {
        case 0:
            if ((CharmedController_D_8006C7B4 & 1) ||
                (*(&CharmedController_D_80070300 + CharmedController_D_8006C58C) & 1)) {
                owner->substate = 1;
                goto enterSubstate1;
            }
            owner->substate = 2;
            break;
        case 1:
        enterSubstate1:
            value3 = M2C_FIELD(privateData, int*, 0x14);
            value2 = value3 * 88;
            value3 = CharmedController_D_8006C550;
            poolMoby = (void*)(value2 + value3);
            if (M2C_FIELD(poolMoby, unsigned char*, 0x48) == 0) {
                M2C_FIELD(poolMoby, unsigned char*, 0x48) = 1U;
                M2C_FIELD(
                    ((M2C_FIELD(privateData, int*, 0x14) * 0x58) + CharmedController_D_8006C550),
                    unsigned char*, 0x4A) = 0xFF;
                M2C_FIELD(
                    ((M2C_FIELD(privateData, int*, 0x14) * 0x58) + CharmedController_D_8006C550),
                    signed char*, 0x49) = 1;
                M2C_FIELD(privateData, int*, 0x14) = -1;
            }
            privateSelector4 = M2C_FIELD(privateData, int*, 4);
            if (privateSelector4 >= 0) {
                CharmedControllerWriteMatchingLinkedSelectors(M2C_FIELD(privateData, int*, 0),
                                                              privateSelector4, 0);
            }
            CharmedControllerMaskLinkedRecordFlagsById(M2C_FIELD(privateData, int*, 0), 0xFC, 0);
            owner->damageFlags = 0;
            owner->substate = 9;
            break;
        case 2:
            if (owner->damageFlags != 0) {
                CharmedController_D_8006E1D4 = 0x2000;
                if (CharmedController_D_8006E1D8 < 0x78) {
                    CharmedController_D_8006E1D8 = 0x78;
                }
                argument4 = (int)owner;
                argument5 = 1;
                MATCHING_KEEP2(argument4, argument5);
                M2C_FIELD(privateData, int*, 0x10) = 0x1E;
                owner->substate = 3;
                owner->state = 1;
                goto setAnimationOne;
            }
            break;
        case 3:
            if (CharmedControllerCountTimerDown(privateData + 0x10, 4) != 0) {
                referencedPosition = M2C_FIELD(M2C_FIELD(privateData, void**, 0xC), int*, 0xC);
                CharmedControllerPrepareCameraMode9Vectors(referencedPosition,
                                                           referencedPosition + 0x10);
                owner->substate = 4;
            }
            break;
        case 4:
            if (CharmedController_D_8006E048 == 1) {
                owner->substate = 5;
            }
            break;
        case 5:
            if (CharmedController_D_8006E048 == 2) {
                M2C_FIELD(privateData, int*, 0x10) = 0x1E;
                owner->substate = 6;
            }
            break;
        case 6:
            value2 = M2C_FIELD(privateData, int*, 4);
            timerAddress6 = privateData + 16;
            if ((value2 >= 0) && (CharmedController_D_8006E53C & 0x800)) {
                owner->state = 2;
                M2C_FIELD(privateData, int*, 0x10) = 0;
                MATCHING_KEEP_CLOBBER(privateData, "$4");
                timerAddress6 = privateData + 0x10;
            }
            if (CharmedControllerCountTimerDown(timerAddress6, 4) != 0) {
                poolIndex = M2C_FIELD(privateData, int*, 0x14);
                if (poolIndex >= 0) {
                    value2 = poolIndex * 88;
                    value3 = CharmedController_D_8006C550;
                    activePoolMoby = (void*)(value2 + value3);
                    poolState = M2C_FIELD(activePoolMoby, unsigned char*, 0x48);
                    if (!(poolState & 0x80)) {
                        if (poolState == 0) {
                            M2C_FIELD(activePoolMoby, unsigned char*, 0x48) = 1U;
                            M2C_FIELD(((M2C_FIELD(privateData, int*, 0x14) * 0x58) +
                                       CharmedController_D_8006C550),
                                      unsigned char*, 0x4A) = 0xFF;
                        }
                        if (owner->state == 2) {
                            M2C_FIELD(((M2C_FIELD(privateData, int*, 0x14) * 0x58) +
                                       CharmedController_D_8006C550),
                                      signed char*, 0x49) = 1;
                            goto clearPoolIndex;
                        }
                    } else {
                    clearPoolIndex:
                        M2C_FIELD(privateData, int*, 0x14) = -1;
                    }
                } else {
                    if (owner->state != 2) {
                        privateSelector18 = M2C_FIELD(privateData, int*, 0x18);
                        if (privateSelector18 >= 0) {
                            func_8003BB10(owner, privateSelector18, 1);
                        }
                        CharmedControllerMaskLinkedRecordFlagsById(M2C_FIELD(privateData, int*, 0),
                                                                   0xFC, 0);
                        M2C_FIELD(privateData, int*, 0x10) = 0x78;
                    }
                    owner->substate = 7;
                }
            }
            break;
        case 7:
            value2 = M2C_FIELD(privateData, int*, 4);
            timerAddress7 = privateData + 16;
            if ((value2 >= 0) && (CharmedController_D_8006E53C & 0x800)) {
                owner->state = 2;
                M2C_FIELD(privateData, int*, 0x10) = 0;
                MATCHING_KEEP_CLOBBER(privateData, "$4");
                timerAddress7 = privateData + 0x10;
            }
            if (CharmedControllerCountTimerDown(timerAddress7, 4) != 0) {
                CharmedControllerTransitionCameraModes9And10(1);
                if (owner->state == 2) {
                    owner->substate = 8;
                } else {
                    goto resetController;
                }
            } else if ((M2C_FIELD(privateData, int*, 8) >= 0) && (owner->state != 3) &&
                       (((CharmedControllerQueryShiftedLinkedRecordWordByByteId(
                              M2C_FIELD(privateData, int*, 0)) >>
                          8) &
                         0xFF) >= M2C_FIELD(privateData, int*, 8))) {
                distance = CharmedControllerApproximatePlanarDistance(&CharmedController_D_8006E020,
                                                                      &owner->position);
                if (distance > 0x7FFF) {
                    distance = 0x7FFF;
                }
                CharmedController_D_8006E1D4 = (int)((0x8000 - distance) << 0xD) >> 0xF;
                CharmedController_D_8006E1D8 = 0x1E;
                owner->state = 3;
            }
            break;
        case 8:
            if (CharmedController_D_8006E048 == 0x81) {
                CharmedControllerWriteMatchingLinkedSelectors(M2C_FIELD(privateData, int*, 0),
                                                              M2C_FIELD(privateData, int*, 4), 0);
                CharmedControllerMaskLinkedRecordFlagsById(M2C_FIELD(privateData, int*, 0), 0xFC,
                                                           0);
            resetController:
                owner->substate = 1;
                func_8003B7B4(&owner->substate, 1, &CharmedController_D_8006C7F8);
                owner->damageFlags = 0;
                owner->substate = 9;
                owner->state = 0;
            }
            break;
        case 9:
            if (owner->damageFlags != 0) {
                value3 = 0x2000;
                owner->damageFlags = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(value3, "memory");
                CharmedController_D_8006E1D4 = value3;
                if (CharmedController_D_8006E1D8 < 0x78) {
                    CharmedController_D_8006E1D8 = 0x78;
                }
                CharmedControllerSetMobyAnimation(owner, 0);
                owner->state = 1;
                argument4 = (int)owner;
                argument5 = 1;
                MATCHING_KEEP(argument5);
                goto setAnimationOne;
            }
            break;
    }
    goto checkAnimation;
setAnimationOne:
    CharmedControllerRequestMobyAnimation(argument4, argument5);
checkAnimation:
    if ((owner->animationState.nextId == 1) && (CharmedController_D_8006C770 != 0)) {
        owner->damageFlags = 0;
        CharmedControllerRequestMobyAnimation(owner, 0);
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated, not human reviewed. SCUS-94467 USA Rev0 original
 * 8007CED8,314 instructions in sibling4510. Verified36 vector/angle C
 * forms reused, original instructions control every raw field and branch.
 * Units, helper semantics and cadence unresolved. Uninstalled until all
 * native words, linked words and complete original hashes match. */
#define B36F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char B36Yaw __asm__("D_80070328 + 0xE");
extern unsigned char B36Pitch __asm__("D_80070328 + 0xD");
extern unsigned char B36Player[] __asm__("D_80070328");
extern unsigned char* B36Start __asm__("D_8006C550");
extern unsigned char* B36End __asm__("D_8006C704");
extern short B36Cos[] __asm__("D_80065920");
extern short B36Sin[] __asm__("D_800658A0");
extern void* (*B36Particle)() __asm__("SpawnParticle");
int B36InterpolateMobyVertex() __asm__("func_80055F14");
int B36PlanarHeadingLookup() __asm__("func_8004E880");
int B36ApproximatePlanarDistance() __asm__("func_8004F334");
int B36CopyVector() __asm__("func_8004F178");
int B36ComputeArcVerticalVelocity() __asm__("func_800365E4");
int B36TransformVectorByBasis() __asm__("func_8004ED6C");
int B36CountTimerDown() __asm__("func_800359A4");
int B36AddVector() __asm__("func_8004F194");
int B36QueryWorldSegmentWithOptions() __asm__("func_8001830C");
int B36TestPlayerSphereOverlap() __asm__("func_8001C288");
int B36QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int B36RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int B36DeleteMoby() __asm__("func_80055B18");
void func_level_36_8007CED8(void* input) {
    struct {
        int vector[4], previous[4];
        void* volatile positionSlot;
        int pad;
    } frame;
    register unsigned char* owner __asm__("$19") = input;
    register int* tag __asm__("$22");
    register unsigned char* cursor __asm__("$21");
    register unsigned char* actor __asm__("$18");
    register unsigned char* best __asm__("$23");
    int score;
    register int yaw __asm__("$17");
    register int pitch __asm__("$16");
    register void* actorPosition __asm__("$20");
    register void* previousPointer __asm__("$17");
    register void* ownerPosition __asm__("$16");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register void* hit __asm__("$4");
    MATCHING_KEEP(owner);
    tag = B36F(owner, int**, 0);
    switch (owner[0x48]) {
        case 0:
            B36InterpolateMobyVertex((void*)tag[4], 0, owner + 12);
            return;
        case 2:
            goto choose;
        case 1:
            goto move;
        case 3:
            goto state3;
        default:
            return;
    }
choose:
    score = 99999;
    MATCHING_KEEP(score);
    cursor = B36Start;
    work2 = cursor < B36End;
    MATCHING_KEEP_CLOBBER(work2, "$23");
    best = 0;
    if (work2) {
        {
            register void* slot8 __asm__("$8") = owner + 12;
            MATCHING_KEEP(slot8);
            frame.positionSlot = slot8;
        }
        actor = cursor;
        do {
            MATCHING_OBSERVE(score);
            if (!(actor[0x48] & 128) && B36F(actor, short*, 0x36) == 137) {
                yaw = (B36PlanarHeadingLookup(B36F(actor, int*, 12) - B36F(owner, int*, 12),
                                              B36F(actor, int*, 16) - B36F(owner, int*, 16), 0) -
                       B36Yaw) &
                      255;
                actorPosition = cursor + 12;
                if (yaw > 128)
                    yaw -= 256;
                pitch = (B36PlanarHeadingLookup(
                             B36ApproximatePlanarDistance(frame.positionSlot, actorPosition),
                             B36F(actor, int*, 20) - B36F(owner, int*, 20), 0) -
                         B36Pitch) &
                        255;
                if (pitch > 128)
                    pitch -= 256;
                if (yaw < 0)
                    yaw = -yaw;
                if (pitch < 0)
                    pitch = -pitch;
                MATCHING_KEEP2(yaw, pitch);
                work2 = yaw < 12;
                MATCHING_KEEP(work2);
                if (work2 && pitch < 12) {
                    work3 = 10240 - B36ApproximatePlanarDistance(frame.positionSlot, actorPosition);
                    if (work3 < 0)
                        work3 = -work3;
                    MATCHING_KEEP_CLOBBER(work3, "$2");
                    work2 = (yaw + pitch) << 10;
                    work3 += work2;
                    if (work3 < score) {
                        best = actor;
                        score = work3;
                    }
                }
            }
            work2 = (int)B36End;
            MATCHING_KEEP_CLOBBER(work2, "$21");
            cursor += 88;
            actor += 88;
        } while (cursor < (unsigned char*)work2);
    }
    if (score == 99999)
        best = 0;
    MATCHING_KEEP(best);
    if (best) {
        work2 = B36PlanarHeadingLookup(B36F(best, int*, 12) - B36F(owner, int*, 12),
                                       B36F(best, int*, 16) - B36F(owner, int*, 16), 0);
        work3 = B36Cos[work2];
        tag[0] = ((work3 << 3) + work3) >> 7;
        work2 = B36PlanarHeadingLookup(B36F(best, int*, 12) - B36F(owner, int*, 12),
                                       B36F(best, int*, 16) - B36F(owner, int*, 16), 0);
        work3 = B36Sin[work2];
        tag[2] = 0;
        tag[1] = ((work3 << 3) + work3) >> 7;
        B36CopyVector(frame.vector, best + 12);
        frame.vector[2] += 1024;
        tag[2] = B36ComputeArcVerticalVelocity(owner + 12, frame.vector, 288, -8, 0);
    } else {
        MATCHING_BARRIER("$23");
        tag[0] = 288;
        tag[1] = 0;
        tag[2] = 160;
        B36TransformVectorByBasis(B36Player + 48, tag, tag);
    }
    owner[0x49] = 1;
    owner[0x48] = 1;
move:
    if (!owner[0x49] && (B36F(owner, int*, 24) & 0x08000000)) {
        owner[0x48] = 2;
        return;
    }
    if (B36F(owner, int*, 12) < 1024 || B36F(owner, int*, 16) < 1024 ||
        B36F(owner, int*, 20) < 1024)
        goto remove;
    if (B36CountTimerDown(tag + 3, 4))
        goto remove;
    previousPointer = frame.previous;
    {
        register void* call4 __asm__("$4") = previousPointer;
        MATCHING_KEEP_CLOBBER(call4, "$16");
        ownerPosition = owner + 12;
        B36CopyVector(call4, ownerPosition);
    }
    work2 = tag[2] - 8;
    tag[2] = work2;
    if (work2 < -240)
        tag[2] = -240;
    B36AddVector(ownerPosition, ownerPosition, tag);
    owner[0x45] += 12;
    if (B36QueryWorldSegmentWithOptions(previousPointer, ownerPosition, 0, 65536, owner) ||
        B36TestPlayerSphereOverlap(ownerPosition, 128, 0)) {
        B36CopyVector(ownerPosition, previousPointer);
        owner[0x48] = 3;
    } else {
        hit = (void*)B36QueryDynamicMobyGeometry(ownerPosition, 512, 0, 0, 0, owner);
        if (hit && (owner[0x49] || hit != (void*)tag[4])) {
            B36F(hit, int*, 24) |= 65536;
            owner[0x48] = 3;
        }
    }
    B36Particle(1, 5, owner + 12, 0);
    B36RefreshMobySpatialGridAndBasis(owner, 2);
    return;
state3:
    B36Particle(12, 15, owner + 12, 0);
remove:
    B36DeleteMoby(owner);
}
#undef B36F

void func_level_36_8007D3C0(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->damageFlags & 0x4000000)
                moby->state = 1;
            break;
        case 1:
            func_8003BABC(moby, 0, 0);
            SpawnFragments(3, 0x11D, moby, tag[0], 0, 0x200);
            func_8003BA00(moby);
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8007D46C.
 * Original292 words: sibling4762. Raw helpers/units/cadence unresolved. */
#define F36Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int F36CopyVector() __asm__("func_8004F178");
int F36AddVector() __asm__("func_8004F194");
int F36SubtractVector() __asm__("func_8004F1C8");
int F36MeasureVectorLength() __asm__("func_8004EDE8");
int F36PlanarHeadingLookup() __asm__("func_8004E880");
int F36ApproximatePlanarDistance() __asm__("func_8004F334");
int F36SpawnBallisticMobyBatch() __asm__("func_800391E8");
int F36SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int F36TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int F36PlayMobySoundEvent() __asm__("func_8003BABC");
int F36MarkMobyCollectionBit() __asm__("func_8003BA00");
int F36DeleteMoby() __asm__("func_80055B18");
int F36CopySoundSlotPosition() __asm__("func_8003C014");
int F36Rand() __asm__("rand");
extern int (*F36Particle)() __asm__("SpawnParticle");
extern unsigned char F36Player[] __asm__("D_8006E020");
extern int F36Mode __asm__("D_8006E048");
extern int F36Value __asm__("D_8006E1D4"), F36Timer __asm__("D_8006E1D8");
void func_level_36_8007D46C(void* input) {
    struct {
        int first[4], second[4];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$19");
    register void* position16 __asm__("$16");
    register int iteration16 __asm__("$16");
    register int magnitude16 __asm__("$16");
    register void* vector18 __asm__("$18");
    register int limit18 __asm__("$18");
    register void* position18 __asm__("$18");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register void* arg6 __asm__("$6");
    MATCHING_KEEP(owner);
    value = 1;
    other = owner[72];
    tag = F36Field(owner, unsigned char**, 0);
    if (other == value)
        goto state1;
    if (other < 2)
        goto done;
    value = 2;
    call4 = frame.first;
    if (other == value)
        goto state2;
    goto done;
state1:
    value = 2;
    owner[72] = value;
    goto done;
state2:
    position16 = owner + 12;
    F36CopyVector(call4, position16);
    value = owner[73];
    if (!value)
        goto advance;
    value = 129;
    other = F36Mode;
    call4 = position16;
    if (other != value)
        goto advance;
    value = F36Field(tag, int*, 0);
    arg5 = F36Field((void*)value, short*, 0);
    value = F36Field((void*)value, int*, 12);
    arg5 = (arg5 << 4) - 16;
    F36CopyVector(call4, (void*)(value + arg5));
    value = F36Field(tag, int*, 0);
    F36Field((void*)value, short*, 2) = 0;
    goto select;
advance:
    arg5 = F36Field(tag, int*, 0);
    other = F36Field((void*)arg5, short*, 0);
    value = F36Field((void*)arg5, short*, 2);
    call4 = (void*)(other + 1);
    value += (int)call4;
    other = value % other;
    F36Field((void*)arg5, short*, 2) = other;
select:
    value = F36Field(tag, int*, 0);
    arg5 = F36Field((void*)value, short*, 2);
    position18 = owner + 12;
    if (arg5)
        goto route;
    MATCHING_BARRIER("$5");
    iteration16 = 0;
    vector18 = frame.second;
random_loop:
    iteration16++;
    value = F36Rand();
    value = (value & 2046) - 1023;
    frame.second[0] = value;
    value = F36Rand();
    value = (value & 2046) - 1023;
    frame.second[1] = value;
    value = F36Rand();
    call4 = vector18;
    arg5 = (int)vector18;
    arg6 = owner + 12;
    MATCHING_KEEP4(call4, arg5, arg6, value);
    value = (value & 2046) - 1023;
    frame.second[2] = value;
    F36AddVector(call4, (void*)arg5, arg6);
    F36Particle(4, 15, vector18, 0);
    value = iteration16 < 8;
    call4 = (void*)1;
    if (value)
        goto random_loop;
    iteration16 = 0;
    limit18 = 256;
spawn_loop:
    arg5 = F36SpawnBallisticMobyBatch(call4, 74, owner, 1, 3, limit18, limit18);
    MATCHING_KEEP(arg5);
    if (!arg5)
        goto spawn_next;
    call4 = F36Field((void*)arg5, void**, 0);
    value = F36Field(call4, short*, 0);
    other = F36Field((void*)arg5, int*, 12);
    value <<= 2;
    other += value;
    F36Field((void*)arg5, int*, 12) = other;
    value = F36Field(call4, short*, 2);
    other = F36Field((void*)arg5, int*, 16);
    value <<= 2;
    other += value;
    F36Field((void*)arg5, int*, 16) = other;
    value = F36Field(call4, short*, 4);
    other = F36Field((void*)arg5, int*, 20);
    value <<= 2;
    other += value;
    F36Field((void*)arg5, int*, 20) = other;
spawn_next:
    iteration16++;
    value = iteration16 < 12;
    call4 = (void*)1;
    if (value)
        goto spawn_loop;
    other = F36ApproximatePlanarDistance(F36Player, owner + 12);
    value = 32767;
    if (other > value)
        other = 32767;
    value = 32768 - other;
    value = (int)((unsigned)value << 13) >> 15;
    F36Value = value;
    value = 30;
    F36Timer = value;
    value = F36SoundHandleMatchesOwnerInStates1Or2(owner, F36Field(tag, int*, 4));
    if (value)
        F36TransitionSoundHandleTo3Or5(F36Field(tag, int*, 4));
    value = -1;
    F36Field(tag, int*, 4) = value;
    F36PlayMobySoundEvent(owner, 2, 0);
    F36MarkMobyCollectionBit(owner);
    F36DeleteMoby(owner);
    goto done;
route:
    call4 = position18;
    value = F36Field((void*)value, int*, 12);
    arg5 <<= 4;
    F36CopyVector(call4, (void*)(value + arg5));
    call4 = frame.first;
    arg5 = (int)position18;
    MATCHING_KEEP2_CLOBBER(call4, arg5, "$6");
    arg6 = call4;
    F36SubtractVector(call4, (void*)arg5, arg6);
    value = F36MeasureVectorLength(frame.first, 1);
    arg6 = 0;
    MATCHING_KEEP(arg6);
    call4 = (void*)frame.first[0];
    arg5 = frame.first[1];
    __asm__("" : "=r"(value) : "0"(value), "r"(call4), "r"(arg5), "r"(arg6));
    magnitude16 = value;
    value = F36PlanarHeadingLookup(call4, arg5, arg6);
    owner[70] = value;
    value = owner[69];
    magnitude16 >>= 6;
    value -= magnitude16;
    owner[69] = value;
    other = F36Field(tag, int*, 0);
    value = F36Field((void*)other, short*, 2);
    other = F36Field((void*)other, int*, 12);
    value <<= 4;
    value += other;
    other = F36Field((void*)value, int*, 12);
    value = 1;
    if (other != value)
        goto route_other;
    value = F36SoundHandleMatchesOwnerInStates1Or2(owner, F36Field(tag, int*, 4));
    call4 = owner;
    if (!value) {
        MATCHING_BARRIER("$2");
        F36Field(tag, int*, 4) = F36PlayMobySoundEvent(call4, 0, 4);
    }
    call4 = (void*)F36Field(tag, int*, 4);
    if ((int)call4 >= 0)
        F36CopySoundSlotPosition(call4, frame.first);
    other = F36ApproximatePlanarDistance(F36Player, position18);
    value = 32767;
    if (other > value)
        other = 32767;
    value = 32768 - other;
    value = (int)((unsigned)value << 12) >> 15;
    F36Value = value;
    value = 10;
    F36Timer = value;
    goto done;
route_other:
    value = 2;
    if (other != value)
        goto stop_handle;
    value = F36SoundHandleMatchesOwnerInStates1Or2(owner, F36Field(tag, int*, 4));
    if (value)
        F36TransitionSoundHandleTo3Or5(F36Field(tag, int*, 4));
    value = -1;
    F36Field(tag, int*, 4) = value;
    F36PlayMobySoundEvent(owner, 1, 0);
    other = F36ApproximatePlanarDistance(F36Player, position18);
    value = 32767;
    if (other > value)
        other = 32767;
    value = 32768 - other;
    value = (int)((unsigned)value << 13) >> 15;
    F36Value = value;
    value = 30;
    F36Timer = value;
    goto done;
stop_handle:
    value = F36SoundHandleMatchesOwnerInStates1Or2(owner, F36Field(tag, int*, 4));
    if (value)
        F36TransitionSoundHandleTo3Or5(F36Field(tag, int*, 4));
    value = -1;
    F36Field(tag, int*, 4) = value;
done:;
}
#undef F36Field

void func_level_36_8007D8FC(Moby* moby) {
    if (func_80039714(moby))
        SpawnParticle(8, 0xF, &moby->position, 0);
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
void func_level_36_8007D944(Moby* moby) {
    register Moby* owner __asm__("$18") = moby;
    Vector3D origin;
    Vector3D transformed;
    Vector3D direction;
    register Vector3D* originalPlayer17 __asm__("$17");
    register int* phase __asm__("$19");
    int nextPhase;
    int nextHeight;
    register int byteOffset __asm__("$17");
    register int pointIndex __asm__("$20");
    register unsigned char* playerField __asm__("$19");
    register Vector3D* scratch __asm__("$16");
    register Vector3D* player __asm__("$16");
    unsigned char state;
    register int headingValue __asm__("$17");

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
            owner->position.z -= 0xC00;
            *phase = -0xC00;
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
                    {
                        register int phaseWord2 __asm__("$2") = *phase;
                        MATCHING_KEEP(phaseWord2);
                        pointIndex += 1;
                        ControllerA918MultiplyVectorGpfSf0(first, second, phaseWord2 * 3);
                    }
                }
                ControllerA918ShiftVectorRightTowardZero(scratch, 9);
                transformed.z += 0x180;
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
            if (func_8004F334(prepared, player) < 0xC00) {
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
                    register Vector3D* first __asm__("$4");
                    register Vector3D* second __asm__("$5");
                    register int originalIndex6 __asm__("$6");
                    register int originalTrig3 __asm__("$3");
                    register int originalProduct2 __asm__("$2");
                    scratch = &direction;
                    first = scratch;
                    MATCHING_KEEP(first);
                    originalIndex6 = headingValue * 2;
                    MATCHING_KEEP(originalIndex6);
                    second = scratch;
                    MATCHING_KEEP(second);
                    originalTrig3 = *(short*)((char*)D_80065920 + originalIndex6);
                    MATCHING_KEEP(originalTrig3);
                    originalPlayer17 = (Vector3D*)(playerField - 0xE);
                    __asm__(""
                            : "=r"(originalPlayer17)
                            : "0"(originalPlayer17), "r"(originalTrig3));
                    originalProduct2 = (originalTrig3 << 1) + originalTrig3;
                    originalProduct2 >>= 4;
                    direction.x = originalProduct2;
                    originalTrig3 = *(short*)((char*)D_800658A0 + originalIndex6);
                    MATCHING_KEEP(originalTrig3);
                    originalIndex6 = (int)originalPlayer17;
                    __asm__("" : "=r"(originalIndex6) : "0"(originalIndex6), "r"(originalTrig3));
                    direction.z = 0;
                    MATCHING_BARRIER_VOLATILE("memory");
                    originalProduct2 = (originalTrig3 << 1) + originalTrig3;
                    originalProduct2 >>= 4;
                    direction.y = originalProduct2;
                    func_8004F194(first, second, (Vector3D*)originalIndex6);
                    if ((ControllerA918QueryWorldSegment(originalPlayer17, scratch) != 0) &&
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

typedef struct {
    unsigned char reserved00[0x34];
    int angle;
    Vector3D point;
} DecodedCheckpointPositionTag;
extern short D_800658A0[], D_80065920[];
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
void func_level_36_8007DD58(Moby* moby) {
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
void func_level_36_8007DE88(Moby* moby) {
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
void func_level_36_8007E1B8(void* input) {
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

void func_level_36_8007F30C(Moby* moby) {
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
void func_level_36_8007F32C(Moby* mobyArgument) {
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
