#include "matching.h"
#include "common.h"
#include "spu.h"
#include "savepoint.h"
#include "spyro.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "mobyutil.h"

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
void func_level_16_80074AB4(void* input) {
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
void func_level_16_80075710(Moby* mobyArgument) {
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
void func_level_16_80075D9C(void* input) {
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
void func_level_16_800772EC(Moby* moby) {
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
void func_level_16_800775AC(Moby* mobyArgument) {
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
void func_level_16_80077ACC(Moby* moby) {
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
void func_level_16_80077DD0(void* input) {
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
void func_level_16_80078944(Moby* moby) {
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
void func_level_16_80078D74(Moby* moby) {
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
void func_level_16_800790DC(Moby* moby) {
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
void func_level_16_800793F8(Moby* actor) {
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

extern int D_8006C770;
void func_level_16_800795C4(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_16/moby/func_level_16_80079654.s SHA256 ecada6ec19210767ed9208884d450a5ad2798d7ad5470a423569df5d05e4fa9a. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller79654RequestMobyAnimation() __asm__("func_80034F40");       /* extern */
int Controller79654CountTimerDown() __asm__("func_800359A4");             /* extern */
int Controller79654RandBetween() __asm__("func_8003636C");                /* extern */
int Controller79654SpawnMobyFromValueSelector() __asm__("func_80036A68"); /* extern */
int Controller79654PlayMobySoundEvent() __asm__("func_8003BABC");         /* extern */
int Controller79654TransformVectorByBasis() __asm__("func_8004ED6C");     /* extern */
int Controller79654MeasureVectorLength() __asm__("func_8004EDE8");        /* extern */
int Controller79654ScaleVectorRatioQ15() __asm__("func_8004F08C");        /* extern */
int Controller79654CopyVector() __asm__("func_8004F178");                 /* extern */
int Controller79654AddVector() __asm__("func_8004F194");                  /* extern */
int Controller79654ApproximatePlanarDistance() __asm__("func_8004F334");  /* extern */
int Controller79654DeleteMoby() __asm__("func_80055B18");                 /* extern */
extern unsigned char Controller79654_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller79654_D_80065920 __asm__("D_80065920");
extern int Controller79654_D_8006C550 __asm__("D_8006C550");
extern int Controller79654_D_8006C574 __asm__("D_8006C574");
extern int Controller79654_D_8006C578 __asm__("D_8006C578");
extern void* Controller79654_D_8006C730 __asm__("D_8006C730");
extern unsigned char Controller79654_D_80070300 __asm__("D_80070300");
extern unsigned char Controller79654_D_80070328 __asm__("D_80070328");
extern int Controller79654_D_800722B8 __asm__("D_800722B8");
extern void* (*Controller79654_SpawnMoby)() __asm__("SpawnMoby");
extern unsigned char Controller79654_func_8002CA50 __asm__("func_8002CA50");
extern unsigned char Controller79654_func_8002D044 __asm__("func_8002D044");
extern int Controller79654_unk_ovlheader_800743B8 __asm__("unk_ovlheader_800743B8");
extern unsigned char (*Controller79654_unk_ovlheader_80074410)() __asm__("unk_ovlheader_80074410");

void func_level_16_80079654(void* input_arg0) {
    register void* owner __asm__("$20") = input_arg0;
    /* Original vector frame begins at0x18; saved registers begin at0x38. */
    struct {
        int sp18, sp1C, sp20, pad24, sp28, pad2C, sp30, pad34;
    } frame;
    register int sharedHelperArg5 __asm__("$5");
    register void* call4 __asm__("$4");
    register int value2 __asm__("$2");
    register void* pool6 __asm__("$6");
    register void* ownerData __asm__("$19");
    register int* firstScanEntry __asm__("$4");
    register int accumulatorWord __asm__("$2");
    register int firstEntryIndex __asm__("$3");
    int bitIndex;
    register int firstScanIndex __asm__("$5");
    register int selectedCount __asm__("$7");
    register int scanCountOrOne __asm__("$17");
    register int selectedIndex __asm__("$18");
    register int childOffsetBytes __asm__("$21");
    int nextAccumulatorWord;
    register int childIndex __asm__("$18");
    register unsigned short* secondScanEntry __asm__("$4");
    register unsigned short packedSecondEntry __asm__("$5");
    unsigned char ownerState;
    void* childVector;
    register void* childData __asm__("$16");
    register void* ownerVector __asm__("$16");
    register void* selectedObject __asm__("$16");
    register void* child __asm__("$17");
    void* sourcePointer;

    /* Original s2 is assigned only when the first scan selects an entry. */
    MATCHING_KEEP(owner);
    selectedCount = 0;
    scanCountOrOne = 0;
    firstScanIndex = 0;
    ownerData = M2C_FIELD(owner, int**, 0);
    pool6 = Controller79654_D_8006C550;
    firstScanEntry = ownerData;
    do {
        firstEntryIndex = *firstScanEntry;
        value2 = firstEntryIndex * 88;
        MATCHING_KEEP(value2);
        if (M2C_FIELD((pool6 + value2), unsigned char*, 0x48) == 0x14) {
            selectedIndex = firstEntryIndex;
            selectedCount += 1;
        }
        firstScanIndex += 1;
        firstScanEntry += 1;
    } while (firstScanIndex < 2);
    pool6 = Controller79654_D_8006C550;
    secondScanEntry = M2C_FIELD(Controller79654_D_8006C730, unsigned short**, 0x1C);
    do {
        packedSecondEntry = *secondScanEntry;
        if (M2C_FIELD((((packedSecondEntry & 0x7FFF) * 0x58) + pool6), unsigned short*, 0x48) !=
            0x14) {
            scanCountOrOne += 1;
        }
        secondScanEntry += 1;
        value2 = packedSecondEntry << 16;
    } while (value2 >= 0);
    MATCHING_OBSERVE(packedSecondEntry);
    childOffsetBytes = 0;
    if (M2C_FIELD(owner, int*, 0x18) & 0x80000) {
        childIndex = 0;
    spawnChildLoop:
        if ((Controller79654_D_8006C578 - Controller79654_D_8006C574) >= 0x15) {
            child = Controller79654_SpawnMoby(0xA2, owner);
            MATCHING_KEEP(child);
            if (child != 0) {
                value2 = 63;
                M2C_FIELD(child, signed char*, 0x4C) = value2;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(child, "memory");
                M2C_FIELD(child, signed char*, 0x3C) = childIndex;
                value2 = 255;
                M2C_FIELD(child, unsigned char*, 0x4A) = value2;
                childData = M2C_FIELD(child, void**, 0);
                Controller79654CopyVector(&frame.sp18,
                                          M2C_FIELD(ownerData, int*, 0x10) + childOffsetBytes);
                Controller79654TransformVectorByBasis(owner + 0x20, &frame.sp18, &frame.sp18);
                childVector = child + 0xC;
                Controller79654AddVector(childVector, childVector, &frame.sp18);
                Controller79654ScaleVectorRatioQ15(
                    &frame.sp18, Controller79654MeasureVectorLength(&frame.sp18, 1), 0x8C);
                M2C_FIELD(childData, short*, 0) = (short)frame.sp18;
                M2C_FIELD(childData, short*, 2) = (short)frame.sp1C;
                M2C_FIELD(childData, short*, 4) = (short)frame.sp20;
            }
            childIndex += 1;
            childOffsetBytes += 0xC;
            if (childIndex < 4) {
                goto spawnChildLoop;
            }
        }
        MATCHING_BARRIER_VOLATILE("$4");
        MATCHING_KEEP(owner);
        call4 = &frame.sp28;
        MATCHING_KEEP(call4);
        Controller79654CopyVector(call4, owner + 0xC);
        frame.sp30 += 0x258;
        Controller79654_unk_ovlheader_80074410(&frame.sp28, 0, 0x14, 0x50, 0x50);
        Controller79654PlayMobySoundEvent(owner, 0, 0);
        Controller79654SpawnMobyFromValueSelector(owner, 1, 0, 0);
        Controller79654DeleteMoby(owner);
        return;
    }
    if (M2C_FIELD(ownerData, void**, 0x14) == 0) {
        M2C_FIELD(ownerData, void**, 0x14) = (void*)(&Controller79654_func_8002CA50 - 0x2370);
    }
    sourcePointer = M2C_FIELD(ownerData, void**, 0x14);
    bitIndex = 0;
    if ((unsigned int)sourcePointer < (unsigned int)(&Controller79654_func_8002D044 - 0x2370)) {
        M2C_FIELD(ownerData, int*, 0x18) =
            (int)(M2C_FIELD(ownerData, int*, 0x18) ^
                  (M2C_FIELD(sourcePointer, unsigned char*, 0x2370) << 0x18));
        do {
            accumulatorWord = M2C_FIELD(ownerData, int*, 0x18);
            if (accumulatorWord < 0) {
                nextAccumulatorWord = (accumulatorWord * 2) ^ 0x80050000;
            } else {
                nextAccumulatorWord = accumulatorWord * 2;
            }
            M2C_FIELD(ownerData, int*, 0x18) = nextAccumulatorWord;
            bitIndex += 1;
        } while (bitIndex < 8);
        M2C_FIELD(ownerData, void**, 0x14) = (void*)(M2C_FIELD(ownerData, void**, 0x14) + 1);
    } else if (((((int)M2C_FIELD(ownerData, int*, 0x18) >> 0xC) & 0xFFFF0) |
                (Controller79654_D_800722B8 & 0xFFF0000F)) !=
               Controller79654_unk_ovlheader_800743B8) {
        M2C_FIELD(&Controller79654_D_80070300, signed char*, 7) = 0;
        M2C_FIELD(ownerData, int*, 0x18) = 0;
    }
    ownerState = M2C_FIELD(owner, unsigned char*, 0x48);
    switch (ownerState) { /* irregular */
        case 0:
            if (selectedCount != 0) {
                /* The matched executable helper accepts these two arguments. */
                if (Controller79654CountTimerDown(ownerData + 0xC, 4) == 0)
                    return;
                ownerVector = owner + 0xC;
                if (Controller79654ApproximatePlanarDistance(ownerVector,
                                                             &Controller79654_D_80070328) < 0xC01)
                    return;
                value2 = scanCountOrOne < 5;
                MATCHING_KEEP(value2);
                if (value2) {
                    sharedHelperArg5 = (int)ownerVector;
                    MATCHING_KEEP(sharedHelperArg5);
                    value2 = selectedIndex * 88;
                    MATCHING_KEEP(value2);
                    selectedObject = (void*)Controller79654_D_8006C550;
                    scanCountOrOne = 1;
                    selectedObject += value2;
                    M2C_FIELD(selectedObject, signed char*, 0x49) = scanCountOrOne;
                    M2C_FIELD(selectedObject, int*, 0x18) = 0;
                    M2C_FIELD(selectedObject, unsigned char*, 0x46) =
                        (unsigned char)M2C_FIELD(owner, unsigned char*, 0x46);
                    Controller79654CopyVector(selectedObject + 0xC, (void*)sharedHelperArg5);
                    M2C_FIELD(selectedObject, int*, 0xC) =
                        (int)(M2C_FIELD(selectedObject, int*, 0xC) +
                              ((int)(*(signed short*)(&Controller79654_D_80065920 +
                                                      (M2C_FIELD(owner, unsigned char*, 0x46) *
                                                       2)) *
                                     0x145) >>
                               0xA));
                    call4 = owner;
                    sharedHelperArg5 = 1;
                    M2C_FIELD(selectedObject, int*, 0x10) =
                        (int)(M2C_FIELD(selectedObject, int*, 0x10) +
                              ((int)(*(signed short*)(&Controller79654_D_800658A0 +
                                                      (M2C_FIELD(owner, unsigned char*, 0x46) *
                                                       2)) *
                                     0x145) >>
                               0xA));
                    M2C_FIELD(ownerData, int*, 0xC) = 0x28;
                    M2C_FIELD(call4, unsigned char*, 0x48) = scanCountOrOne;
                    goto callSharedHelper;
                }
            }
            return;
        case 1:
            if (Controller79654CountTimerDown(ownerData + 0xC, 4) != 0) {
                value2 = Controller79654RandBetween(0x32, 0x8C);
                call4 = owner;
                sharedHelperArg5 = 0;
                M2C_FIELD(ownerData, int*, 0xC) = value2;
                M2C_FIELD(call4, unsigned char*, 0x48) = 0;
            callSharedHelper:
                Controller79654RequestMobyAnimation(call4, sharedHelperArg5);
            }
            break;
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, func_level_16_80079AF4.
 * AI generated; not human reviewed.
 * Original stage and saved argument phases remain separate C objects.
 * The case-five word40 is initialized as an ordinary value before37A60,
 * and enters saved GP19 only at its later35A80 argument consumer.
 * The old GP19 stage is used only on the separate outer case-zero route.
 * Empty metadata observes complete initialized values; the sole multiply
 * creates the entire signed64-bit product before its high-word projection.
 * int address/argument words target the frozen32-bit MIPS/o32 compiler.
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
} Level16_79AF4Product;
#define Level16_79AF4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level16_79AF4Keep(v) __asm__("" : "=r"(v) : "0"(v))
void Level16_79AF4RequestMobyAnimation(int, int) __asm__("func_80034F40");
void Level16_79AF4EmptyAnimationTransitionHook(int) __asm__("func_80035734");
int Level16_79AF4TurnMobyTowardPlayer(int, int, int, int) __asm__("func_8003573C");
int Level16_79AF4TurnMobyTowardHeading(int, int, int, int, int, int) __asm__("func_8003585C");
int Level16_79AF4CountTimerDown(int, int) __asm__("func_800359A4");
int Level16_79AF4UpdateMobyPathMotion(int, int, int, int, int, int, int,
                                      int) __asm__("func_80035A80");
int Level16_79AF4ResolveMobyYawStep(int, int, int, int, int) __asm__("func_80035DDC");
int Level16_79AF4TestPaddedRotatedBox(int, int, int, int) __asm__("func_80036220");
int Level16_79AF4RandBetween(int, int) __asm__("func_8003636C");
int Level16_79AF4ComputeArcVerticalVelocity(int, int, int, int, int*) __asm__("func_800365E4");
int Level16_79AF4CountListedMobysBelowState80(int) __asm__("func_800369D8");
void Level16_79AF4SetMobyZFromGroundProbe(int) __asm__("func_80037014");
int Level16_79AF4UpdateEffectConfiguration(int, int, int, int, int) __asm__("func_80037A60");
int Level16_79AF4UpdateMobyInteractionGate(int, int) __asm__("func_80037BBC");
void Level16_79AF4RegisterTrackedValue(int, int, int) __asm__("func_8003B7B4");
int Level16_79AF4PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Level16_79AF4CopyVector(int, int) __asm__("func_8004F178");
int Level16_79AF4ApproximatePlanarDistance(int, int) __asm__("func_8004F334");
void Level16_79AF4StartDialogue(int, int, int) __asm__("func_800512E4");
void Level16_79AF4DeleteMoby(int) __asm__("func_80055B18");
void Level16_79AF4RefreshMobySpatialGridAndBasis(int, int) __asm__("func_80055D24");
int Level16_79AF4_rand(void) __asm__("rand");
int Level16_79AF4_sprintf(int, const char*, ...) __asm__("sprintf");
extern int Level16_79AF4_D_80066FCC __asm__("D_80066FCC");
extern int Level16_79AF4_D_8006C420 __asm__("D_8006C420");
extern int Level16_79AF4_D_8006C550 __asm__("D_8006C550");
extern int Level16_79AF4_D_8006C58C __asm__("D_8006C58C");
extern int Level16_79AF4_D_8006C640 __asm__("D_8006C640");
extern int Level16_79AF4_D_8006C730 __asm__("D_8006C730");
extern int Level16_79AF4_D_8006C76C __asm__("D_8006C76C");
extern int Level16_79AF4_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level16_79AF4_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level16_79AF4_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level16_79AF4_D_8006E344 __asm__("D_8006E344");
extern int Level16_79AF4_D_80070300 __asm__("D_80070300");
extern int Level16_79AF4_D_80070328 __asm__("D_80070328");
extern int Level16_79AF4_D_level_16_800866F8 __asm__("D_level_16_800866F8");
extern int Level16_79AF4_func_level_16_80074AB4 __asm__("func_level_16_80074AB4");
extern int Level16_79AF4_main_TEXT_END __asm__("main_TEXT_END");
extern int Level16_79AF4_main_TEXT_START __asm__("main_TEXT_START");
extern int (*Level16_79AF4unk_ovlheader_80074338)(int, int, int) __asm__("unk_ovlheader_80074338");
extern int (*Level16_79AF4unk_ovlheader_800743D8)(int, int) __asm__("unk_ovlheader_800743D8");
static __inline__ int Level16_79AF4ReadyOwner(int value) {
    __asm__ volatile("" ::"r"(value) : "$19", "memory");
    return value;
}
void func_level_16_80079AF4(void* input) {
    register int resultWord2 __asm__("$2"), workWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), capturedWord9 __asm__("$9"),
        capturedWord8 __asm__("$8"), argumentWord7 __asm__("$7");
    Level16_79AF4Product remainderProduct;
    register int ownerAddress18 __asm__("$18"), privateAddress17 __asm__("$17"),
        workWord16 __asm__("$16"), workWord21 __asm__("$21");
    struct {
        int output;
        int unusedOriginal24, unusedOriginal28, unusedOriginal2C, unusedOriginal30,
            unusedOriginal34;
    } originalFrame;
    int var_a2;
    short temp_a1_2;
    short temp_v0_13;
    short temp_v0_14;
    short temp_v1_12;
    short temp_v1_16;
    short temp_v1_17;
    register int originalStage19 __asm__("$19");
    int case5FortyWord;
    short var_v1;
    int temp_a0_2;
    int temp_a1_7;
    int temp_a3;
    int temp_v0_12;
    int temp_v0_2;
    int temp_v0_4;
    int temp_v0_7;
    int temp_v1_11;
    int temp_v1_8;
    signed char var_v0_3;
    int var_a0_4;
    int var_a0_5;
    int var_a0_6;
    unsigned short temp_a1_4;
    unsigned short temp_a1_5;
    unsigned short temp_a1_6;
    unsigned int temp_v1;
    unsigned int temp_v1_3;
    unsigned int temp_v1_5;
    register unsigned int var_s4 __asm__("$20");
    unsigned char temp_a1_3;
    unsigned char temp_v0_6;
    unsigned char temp_v1_13;
    unsigned char temp_v1_15;
    unsigned char temp_v1_6;
    unsigned char temp_v1_7;
    unsigned char var_v0_4;
    int temp_a0;
    int temp_v0;
    int temp_v0_10;
    int temp_v0_11;
    int temp_v0_15;
    int temp_v0_3;
    int temp_v0_5;
    int temp_v0_8;
    int temp_v0_9;
    int temp_v1_10;
    int temp_v1_14;
    int temp_v1_9;
    int var_a0_3;
    ownerAddress18 = (int)input;
    Level16_79AF4Keep(ownerAddress18);
    privateAddress17 = Level16_79AF4Field(ownerAddress18, int*, 0);
    resultWord2 = 0x55555556;
    argumentWord5 = Level16_79AF4Field(privateAddress17, int*, 112);
    workWord3 = (int)((unsigned int)argumentWord5 + 2U);
    remainderProduct.full = (long long)workWord3 * (long long)resultWord2;
    __asm__ volatile("" : "=x"(remainderProduct.full) : "0"(remainderProduct.full));
    argumentWord4 = Level16_79AF4_D_8006C640;
    __asm__ volatile("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$2", "memory");
    resultWord2 = workWord3 >> 31;
    __asm__("" : "=x"(remainderProduct.full) : "0"(remainderProduct.full), "r"(resultWord2));
    capturedWord9 = remainderProduct.words.high;
    Level16_79AF4Keep(capturedWord9);
    workWord16 = capturedWord9 - resultWord2;
    Level16_79AF4Keep(workWord16);
    resultWord2 = workWord16 * 2;
    resultWord2 += workWord16;
    workWord16 = workWord3 - resultWord2;
    if (argumentWord4 == 0) {
        if (argumentWord5 != 0) {
            workWord3 = (int)&Level16_79AF4_D_8006C420;
            Level16_79AF4Keep(workWord3);
            resultWord2 = Level16_79AF4_D_8006C76C;
            argumentWord4 = Level16_79AF4Field(privateAddress17, int*, 12);
            resultWord2 *= 8;
            resultWord2 += workWord3;
            workWord3 = argumentWord5 * 4;
            workWord3 += resultWord2;
            argumentWord6 = Level16_79AF4Field(workWord3, int*, -4);
            Level16_79AF4_sprintf(argumentWord4, "%s", argumentWord6);
        }
        if (((int)Level16_79AF4_D_8006C7B4 >> workWord16) & 1) {
            Level16_79AF4DeleteMoby(ownerAddress18);
            return;
        }
        if (Level16_79AF4Field(privateAddress17, short*, 0x74) >= 3) {
            resultWord2 = Level16_79AF4Field(privateAddress17, int*, 68);
            argumentWord5 = Level16_79AF4Field(resultWord2, short*, 2);
            argumentWord4 = ownerAddress18 + 12;
            if (argumentWord5) {
                argumentWord5 *= 16;
                resultWord2 = Level16_79AF4Field(resultWord2, int*, 12);
                __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "r"(argumentWord5));
                argumentWord5 -= 16;
                argumentWord5 = resultWord2 + argumentWord5;
                Level16_79AF4CopyVector(argumentWord4, argumentWord5);
                Level16_79AF4SetMobyZFromGroundProbe(ownerAddress18);
                Level16_79AF4Field(ownerAddress18, unsigned char*, 82) = 254;
                Level16_79AF4RefreshMobySpatialGridAndBasis(ownerAddress18, 2);
            }
        } else {
            goto originalBlock8;
        }
    } else {
    originalBlock8:
        if ((unsigned int)Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) >=
            (unsigned int)(int)&Level16_79AF4_func_level_16_80074AB4) {
            argumentWord5 = 0;
            argumentWord6 = (int)&Level16_79AF4_D_level_16_800866F8;
        loop_10:
            temp_v1 = Level16_79AF4Field(privateAddress17, unsigned int*, 0x110);
            if (temp_v1 < (unsigned int)argumentWord6) {
                argumentWord4 = 0;
                Level16_79AF4Field(privateAddress17, int*, 0x10C) =
                    (int)(Level16_79AF4Field(privateAddress17, int*, 0x10C) ^
                          (Level16_79AF4Field(temp_v1, unsigned char*, 0) << 8));
                do {
                    workWord3 = Level16_79AF4Field(privateAddress17, int*, 268);
                    resultWord2 = workWord3 & 0x8000;
                    if (resultWord2) {
                        resultWord2 = (unsigned int)workWord3 << 1;
                        resultWord2 ^= 0x8005;
                    } else
                        resultWord2 = (unsigned int)workWord3 << 1;
                    Level16_79AF4Field(privateAddress17, int*, 0x10C) = resultWord2;
                    argumentWord4 += 1;
                } while (argumentWord4 < 8);
                argumentWord5 += 1;
                Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) =
                    (unsigned int)(Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) + 1);
                if (argumentWord5 < 0x40) {
                    goto loop_10;
                }
            }
        }
        if (Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) == 0) {
            Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) =
                (unsigned int)(Level16_79AF4_D_8006C58C +
                               ((int)&Level16_79AF4_main_TEXT_START + 2));
        }
        resultWord2 = Level16_79AF4Field(privateAddress17, unsigned int*, 272);
        workWord3 = (int)&Level16_79AF4_main_TEXT_END;
        Level16_79AF4Keep(workWord3);
        if ((unsigned int)resultWord2 < (unsigned int)workWord3) {
            argumentWord5 = 0;
            argumentWord6 = workWord3;
        loop_20:
            temp_v1_3 = Level16_79AF4Field(privateAddress17, unsigned int*, 0x110);
            if (temp_v1_3 < (unsigned int)argumentWord6) {
                argumentWord4 = 0;
                Level16_79AF4Field(privateAddress17, int*, 0x10C) =
                    (int)(Level16_79AF4Field(privateAddress17, int*, 0x10C) ^
                          (Level16_79AF4Field(temp_v1_3, unsigned char*, 0) << 8));
                do {
                    workWord3 = Level16_79AF4Field(privateAddress17, int*, 268);
                    resultWord2 = workWord3 & 0x8000;
                    if (resultWord2) {
                        resultWord2 = (unsigned int)workWord3 << 1;
                        resultWord2 ^= 0x8005;
                    } else
                        resultWord2 = (unsigned int)workWord3 << 1;
                    Level16_79AF4Field(privateAddress17, int*, 0x10C) = resultWord2;
                    argumentWord4 += 1;
                } while (argumentWord4 < 8);
                MATCHING_BARRIER_VOLATILE("memory");
                resultWord2 = Level16_79AF4Field(privateAddress17, int*, 268);
                workWord3 = Level16_79AF4Field(privateAddress17, unsigned int*, 272);
                resultWord2 &= 3;
                resultWord2++;
                workWord3 += resultWord2;
                argumentWord5++;
                Level16_79AF4Field(privateAddress17, unsigned int*, 272) = workWord3;
                if (argumentWord5 >= 0x40) {
                    if ((resultWord2 = (unsigned int)workWord3 <
                                       (unsigned int)(int)&Level16_79AF4_main_TEXT_END) == 0) {
                        goto originalBlock27;
                    }
                } else {
                    goto loop_20;
                }
            } else {
            originalBlock27:
                Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) =
                    (unsigned int)(int)&Level16_79AF4_func_level_16_80074AB4;
            }
        }
        temp_v1_6 = Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48);
        switch (temp_v1_6) {
            case 12:
                resultWord2 = Level16_79AF4_D_8006C770;
                argumentWord4 = ownerAddress18;
                if (resultWord2) {
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 72) = 0;
                    __asm__ volatile(
                        "" ::"m"(Level16_79AF4Field(ownerAddress18, unsigned char*, 72))
                        : "$5", "memory");
                    Level16_79AF4RequestMobyAnimation(argumentWord4, 0);
                    Level16_79AF4Field(ownerAddress18, int*, 0x18) = 0;
                    return;
                }
                goto originalBlock284;
            case 0:
                var_s4 = 0;
                originalStage19 = Level16_79AF4Field(privateAddress17, short*, 0x74);
                workWord21 = 0;
                if (Level16_79AF4Field(privateAddress17, int*, 0x100) != 0) {
                    originalStage19 -= 1;
                }
                if ((Level16_79AF4Field(privateAddress17, unsigned int*, 0x110) ==
                     (int)&Level16_79AF4_D_level_16_800866F8) &&
                    (Level16_79AF4Field(privateAddress17, int*, 0x10C) != 0)) {
                    Level16_79AF4Field((int)&Level16_79AF4_D_80070300 +
                                           Level16_79AF4Field((int)&Level16_79AF4_D_80066FCC,
                                                              unsigned char*, 0x10),
                                       unsigned char*, 0) =
                        Level16_79AF4Field((int)&Level16_79AF4_D_80070300 +
                                               Level16_79AF4Field((int)&Level16_79AF4_D_80066FCC,
                                                                  unsigned char*, 0x10),
                                           unsigned char*, 0) &
                        0xFE;
                }
                Level16_79AF4RegisterTrackedValue(Level16_79AF4Field(privateAddress17, int*, 0x44) +
                                                      2,
                                                  2, (int)&Level16_79AF4_D_8006C7F8);
                Level16_79AF4RegisterTrackedValue(privateAddress17 + 0x74, 2,
                                                  (int)&Level16_79AF4_D_8006C7F8);
                switch (originalStage19) {
                    case 0:
                        if (Level16_79AF4Field(privateAddress17, int*, 0x100) == 0) {
                            if ((Level16_79AF4Field(privateAddress17, int*, 0x70) == 0) &&
                                (Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*, 0x244) !=
                                 0)) {
                                Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*, 0x20C) =
                                    0x10000002;
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0x14U;
                                return;
                            }
                            if (Level16_79AF4Field(privateAddress17, int*, 0x100) == 0) {
                                if (Level16_79AF4TestPaddedRotatedBox(
                                        (int)&Level16_79AF4_D_80070328, privateAddress17 + 0xB4, 0,
                                        0x200) != 0) {
                                    Level16_79AF4unk_ovlheader_800743D8(
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x43),
                                        3);
                                }
                                resultWord2 = Level16_79AF4Field(privateAddress17, int*, 256);
                                argumentWord4 = ownerAddress18;
                                if (!resultWord2) {
                                    MATCHING_BARRIER_VOLATILE("$2");
                                    resultWord2 =
                                        Level16_79AF4UpdateMobyInteractionGate(argumentWord4, 0);
                                } else
                                    goto originalBlock101;
                                if (resultWord2) {
                                    Level16_79AF4Field(privateAddress17, unsigned char*, 0x76) = 1U;
                                    Level16_79AF4unk_ovlheader_800743D8(
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x43),
                                        Level16_79AF4Field(privateAddress17, short*, 0x74) + 1);
                                    argumentWord4 = ownerAddress18;
                                    goto originalBlock255;
                                }
                                goto originalBlock101;
                            }
                            goto originalBlock101;
                        }
                        goto originalBlock101;
                    case 1:
                        resultWord2 = Level16_79AF4Field(privateAddress17, int*, 256);
                        var_s4 = 1;
                        if (resultWord2)
                            goto originalBlock62;
                        MATCHING_BARRIER_VOLATILE("$2");
                        workWord16 = (int)&Level16_79AF4_D_80070328;
                        Level16_79AF4Keep(workWord16);
                        resultWord2 = Level16_79AF4TestPaddedRotatedBox(
                            workWord16, privateAddress17 + 180, 0, 512);
                        if (resultWord2) {
                            resultWord2 = 3;
                            Level16_79AF4Field(ownerAddress18, unsigned char*, 73) = resultWord2;
                        }
                        resultWord2 = Level16_79AF4Field(privateAddress17, int*, 256);
                        __asm__("" : "=r"(var_s4) : "0"(var_s4), "r"(resultWord2));
                        var_s4 = 1;
                        if (resultWord2)
                            goto originalBlock62;
                        resultWord2 = Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*, 184);
                        argumentWord4 = workWord16;
                        if (resultWord2)
                            goto originalBlock62;
                        MATCHING_BARRIER_VOLATILE("$2");
                        resultWord2 = Level16_79AF4TestPaddedRotatedBox(
                            argumentWord4, privateAddress17 + 204, 0, 512);
                        if (resultWord2) {
                            resultWord2 = 2;
                            Level16_79AF4Field(ownerAddress18, unsigned char*, 73) = resultWord2;
                        }
                        Level16_79AF4Keep(var_s4);
                        var_s4 = 1;
                        goto originalBlock62;
                    case 2:
                        resultWord2 = Level16_79AF4Field(privateAddress17, int*, 256);
                        var_s4 = 5;
                        if (!resultWord2) {
                            MATCHING_BARRIER_VOLATILE("$2");
                            resultWord2 = Level16_79AF4TestPaddedRotatedBox(
                                (int)&Level16_79AF4_D_80070328, privateAddress17 + 180, 0, 512);
                            if (resultWord2) {
                                resultWord2 = 3;
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 73) =
                                    resultWord2;
                            }
                            Level16_79AF4Keep(var_s4);
                            var_s4 = 5;
                        }
                        workWord21 = 8;
                    originalBlock62:
                        resultWord2 = 1;
                        Level16_79AF4Field(privateAddress17, signed char*, 2) = resultWord2;
                        goto originalBlock101;
                    case 3:
                    case 4:
                    case 5:
                        workWord3 = Level16_79AF4Field(privateAddress17, short*, 116);
                        Level16_79AF4Keep(workWord3);
                        resultWord2 = 3;
                        argumentWord4 = workWord3;
                        if (workWord3 == resultWord2) {
                            resultWord2 = 2;
                            Level16_79AF4Field(privateAddress17, signed char*, 2) = resultWord2;
                        } else {
                            resultWord2 = argumentWord4 - 4;
                            Level16_79AF4Keep(resultWord2);
                            resultWord2 &= 65535;
                            if ((unsigned int)resultWord2 < 4U)
                                Level16_79AF4Field(privateAddress17, signed char*, 2) =
                                    argumentWord4;
                        }
                        if (originalStage19 == 3) {
                            var_s4 = 5;
                            workWord21 = 0xF1;
                        }
                        if (originalStage19 == 4) {
                            var_s4 = 5;
                            workWord21 = 0x66;
                        }
                        if (originalStage19 == 5) {
                            Level16_79AF4Keep(originalStage19);
                            var_s4 = 5;
                            workWord21 = 0x5C;
                        }
                        resultWord2 = Level16_79AF4Field(privateAddress17, int*, 256);
                        argumentWord4 = ownerAddress18;
                        if (resultWord2)
                            goto actor1513Stage345Callback;
                        {
                            resultWord2 = Level16_79AF4Field(privateAddress17, short*, 116);
                            resultWord2 <<= 2;
                            resultWord2 = privateAddress17 + resultWord2;
                            resultWord2 = Level16_79AF4CountListedMobysBelowState80(
                                Level16_79AF4Field(resultWord2, int*, 112));
                            argumentWord4 = ownerAddress18;
                            if (resultWord2)
                                goto actor1513Stage345Callback;
                            MATCHING_OBSERVE_VOLATILE(argumentWord4);
                            Level16_79AF4unk_ovlheader_800743D8(
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 0x43),
                                Level16_79AF4Field(privateAddress17, short*, 0x74) + 1);
                        }
                        argumentWord4 = ownerAddress18;
                    actor1513Stage345Callback:
                        resultWord2 = Level16_79AF4UpdateMobyInteractionGate(argumentWord4, 0);
                        argumentWord4 = ownerAddress18;
                        if (!resultWord2)
                            goto originalBlock101;
                        Level16_79AF4Keep(argumentWord4);
                        goto originalBlock255;
                    case 6:
                        var_s4 = 2;
                        if ((Level16_79AF4Field(privateAddress17, int*, 0x100) == 0) &&
                            ((temp_v1_13 = Level16_79AF4Field(
                                  ((Level16_79AF4Field(privateAddress17, int*, 0x108) * 0x58) +
                                   Level16_79AF4_D_8006C550),
                                  unsigned char*, 0x48),
                              ((temp_v1_13 < 0x80U) == 0)) ||
                             (temp_v1_13 == var_s4))) {
                            resultWord2 = Level16_79AF4Field(privateAddress17, unsigned char*, 116);
                            resultWord2++;
                            __asm__ volatile("" ::"r"(originalStage19), "r"(resultWord2), "i"(6));
                            goto actor1513StoreTransition;
                        }
                        goto originalBlock101;
                    case 7:
                        workWord16 = 1;
                        var_s4 = 3;
                        argumentWord7 = 20;
                        resultWord2 = Level16_79AF4_D_8006C730;
                        argumentWord6 = Level16_79AF4_D_8006C550;
                        argumentWord4 = Level16_79AF4Field(resultWord2, int*, 28);
                    actor1513Stage7Loop:
                        argumentWord5 = Level16_79AF4Field(argumentWord4, unsigned short*, 0);
                        resultWord2 = argumentWord5 & 32767;
                        workWord3 = resultWord2 * 88;
                        workWord3 = argumentWord6 + workWord3;
                        resultWord2 = Level16_79AF4Field(workWord3, unsigned char*, 72);
                        if (resultWord2 != argumentWord7)
                            workWord16 = 0;
                        resultWord2 = (unsigned int)argumentWord5 << 16;
                        Level16_79AF4Keep(resultWord2);
                        argumentWord4 += 2;
                        if (resultWord2 >= 0)
                            goto actor1513Stage7Loop;
                        if ((Level16_79AF4Field(privateAddress17, int*, 256) == 0) &&
                            (Level16_79AF4CountListedMobysBelowState80(5) == 0) && workWord16) {
                            Level16_79AF4unk_ovlheader_800743D8(
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 67),
                                Level16_79AF4Field(privateAddress17, short*, 116) + 1);
                        }
                        goto originalBlock101;
                    case 8:
                        Level16_79AF4Field(privateAddress17, signed char*, 2) = 3;
                        if (Level16_79AF4UpdateMobyInteractionGate(ownerAddress18, 0) == 0) {
                            var_s4 = 1;
                            if ((Level16_79AF4Field(privateAddress17, int*, 0x100) == 0) &&
                                ((Level16_79AF4TestPaddedRotatedBox((int)&Level16_79AF4_D_80070328,
                                                                    privateAddress17 + 0xE4, 0,
                                                                    0) != 0) ||
                                 (Level16_79AF4CountListedMobysBelowState80(
                                      Level16_79AF4Field(privateAddress17, int*, 0x80)) == 0))) {
                                Level16_79AF4Field(privateAddress17, short*, 0x74) = 3;
                                resultWord2 = 4;
                                __asm__ volatile("" ::"r"(originalStage19), "r"(resultWord2),
                                                 "i"(8));
                                goto actor1513StoreTransition;
                            }
                            goto originalBlock101;
                        }
                        argumentWord4 = ownerAddress18;
                        goto originalBlock255;
                    case 9:
                        if (Level16_79AF4Field(privateAddress17, short*, 0x74) == 9) {
                            Level16_79AF4Field(privateAddress17, signed char*, 2) = 8;
                        }
                        var_s4 = 4;
                        if ((Level16_79AF4Field(privateAddress17, int*, 0x100) == 0) &&
                            (Level16_79AF4CountListedMobysBelowState80(
                                 (resultWord2 = Level16_79AF4Field(privateAddress17, short*, 116),
                                  resultWord2 <<= 2, resultWord2 = privateAddress17 + resultWord2,
                                  Level16_79AF4Field(resultWord2, int*, 112))) == 0)) {
                            resultWord2 = Level16_79AF4Field(privateAddress17, unsigned char*, 116);
                            resultWord2++;
                            goto actor1513StoreTransition;
                        }
                        goto originalBlock101;
                    actor1513StoreTransition:
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 73) = resultWord2;
                        goto originalBlock101;
                    default:
                    originalBlock101:
                        var_a0_3 = privateAddress17 + 0x100;
                        if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x49) != 0) {
                            Level16_79AF4Field(privateAddress17, unsigned char*, 5) = 0U;
                            Level16_79AF4Field(privateAddress17, unsigned char*, 118) = 0;
                            MATCHING_BARRIER_VOLATILE("memory");
                            workWord3 = Level16_79AF4Field(ownerAddress18, unsigned char*, 73);
                            Level16_79AF4Keep(workWord3);
                            resultWord2 = Level16_79AF4Field(privateAddress17, short*, 116);
                            if (resultWord2 < workWord3) {
                                Level16_79AF4Field(privateAddress17, int*, 0x100) =
                                    Level16_79AF4RandBetween(0xA, 0x32);
                                if (Level16_79AF4Field(privateAddress17, short*, 0x74) == 9) {
                                    Level16_79AF4Field(privateAddress17, int*, 0x100) = 1;
                                }
                                Level16_79AF4Field(privateAddress17, short*, 0x74) =
                                    (short)Level16_79AF4Field(ownerAddress18, unsigned char*, 0x49);
                            }
                            if ((unsigned int)((unsigned short)Level16_79AF4Field(privateAddress17,
                                                                                  short*, 0x74) -
                                               7) < 2U) {
                                Level16_79AF4Field(privateAddress17, unsigned char*, 5) = 1U;
                            }
                            Level16_79AF4Field(ownerAddress18, unsigned char*, 0x49) = 0U;
                            var_a0_3 = privateAddress17 + 0x100;
                        }
                        if (Level16_79AF4CountTimerDown(var_a0_3, 4) == 2) {
                            Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 5);
                            return;
                        }
                        switch (var_s4) {
                            case 0:
                                if ((Level16_79AF4CountTimerDown(privateAddress17 + 0x64, 4) !=
                                     0) &&
                                    (Level16_79AF4_D_8006C770 != 0)) {
                                    temp_v0_2 =
                                        Level16_79AF4Field(privateAddress17, int*, 0x68) == 0;
                                    Level16_79AF4Field(privateAddress17, int*, 0x68) = temp_v0_2;
                                    if (temp_v0_2 == 0) {
                                        Level16_79AF4Field(privateAddress17, int*, 0x64) =
                                            Level16_79AF4RandBetween(0x78, 0xB4);
                                        if (Level16_79AF4Field(ownerAddress18, unsigned char*,
                                                               0x3D) == 5) {
                                            Level16_79AF4_D_8006C770 = 0;
                                            Level16_79AF4Field(ownerAddress18, signed char*, 0x40) =
                                                0x72;
                                            Level16_79AF4Field(ownerAddress18, unsigned char*,
                                                               0x3D) = 0U;
                                            Level16_79AF4Field(ownerAddress18, unsigned char*,
                                                               0x3F) = 0U;
                                            Level16_79AF4EmptyAnimationTransitionHook(
                                                ownerAddress18);
                                        }
                                        Level16_79AF4Field(privateAddress17, int*, 0x6C) = 0;
                                    } else {
                                        Level16_79AF4Field(privateAddress17, int*, 0x64) =
                                            Level16_79AF4RandBetween(0xB4, 0xF0);
                                        if (Level16_79AF4Field(ownerAddress18, unsigned char*,
                                                               0x3D) != 5) {
                                            Level16_79AF4_D_8006C770 = 0;
                                            Level16_79AF4Field(ownerAddress18, signed char*, 0x40) =
                                                0x72;
                                            Level16_79AF4Field(ownerAddress18, unsigned char*,
                                                               0x3D) = 5U;
                                            Level16_79AF4Field(ownerAddress18, unsigned char*,
                                                               0x3F) = 0U;
                                            Level16_79AF4EmptyAnimationTransitionHook(
                                                ownerAddress18);
                                        }
                                    }
                                }
                                if (Level16_79AF4Field(privateAddress17, int*, 0x68) == 0) {
                                    if (Level16_79AF4_D_8006C770 != 0) {
                                        if (Level16_79AF4Field(privateAddress17, int*, 0x6C) == 0) {
                                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 1);
                                            Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                                Level16_79AF4RandBetween(1, 2);
                                        } else {
                                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 0);
                                            MATCHING_OBSERVE_VOLATILE_CLOBBER(privateAddress17,
                                                                              "memory");
                                            Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                                (int)(Level16_79AF4Field(privateAddress17, int*,
                                                                         0x6C) -
                                                      1);
                                        }
                                    }
                                } else {
                                    if (((Level16_79AF4_D_8006C640 == 0) ||
                                         (Level16_79AF4_D_8006C770 != 0)) &&
                                        (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) !=
                                         5)) {
                                        Level16_79AF4_D_8006C770 = 0;
                                        Level16_79AF4Field(ownerAddress18, signed char*, 0x40) =
                                            0x72;
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) =
                                            5U;
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) =
                                            0U;
                                        Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                                    }
                                    resultWord2 =
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 61);
                                    workWord16 = 4;
                                    if (resultWord2 != workWord16) {
                                        Level16_79AF4unk_ovlheader_80074338(
                                            ownerAddress18, privateAddress17 + 0x4C, 1);
                                    }
                                    resultWord2 = Level16_79AF4_rand();
                                    resultWord2 = (resultWord2 & 1023) < 7;
                                    if (!resultWord2)
                                        goto originalBlock220;
                                    resultWord2 =
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 61);
                                    argumentWord4 = ownerAddress18;
                                    if (resultWord2 != workWord16) {
                                        Level16_79AF4_D_8006C770 = 0;
                                        workWord3 =
                                            Level16_79AF4Field(ownerAddress18, unsigned char*, 61);
                                        argumentWord5 =
                                            Level16_79AF4Field(ownerAddress18, unsigned char*, 63);
                                        resultWord2 = 114;
                                        Level16_79AF4Field(ownerAddress18, signed char*, 64) =
                                            resultWord2;
                                        resultWord2 = 4;
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 61) =
                                            resultWord2;
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 63) = 0;
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 60) =
                                            workWord3;
                                        Level16_79AF4Field(ownerAddress18, unsigned char*, 62) =
                                            argumentWord5;
                                        goto originalBlock219;
                                    }
                                }
                                goto originalBlock220;
                            case 1:
                                if ((Level16_79AF4TurnMobyTowardPlayer(ownerAddress18, 6, 0xC, 1) !=
                                     0) &&
                                    (Level16_79AF4_D_8006C770 != 0)) {
                                    if (Level16_79AF4Field(privateAddress17, int*, 0x6C) == 0) {
                                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 1);
                                        Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                            Level16_79AF4RandBetween(1, 2);
                                    } else {
                                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 0);
                                        MATCHING_OBSERVE_VOLATILE_CLOBBER(privateAddress17,
                                                                          "memory");
                                        Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                            (int)(Level16_79AF4Field(privateAddress17, int*, 0x6C) -
                                                  1);
                                    }
                                }
                                resultWord2 =
                                    Level16_79AF4UpdateMobyInteractionGate(ownerAddress18, 0);
                                __asm__ volatile(""
                                                 : "=r"(resultWord2)
                                                 : "0"(resultWord2), "i"(1)
                                                 : "memory");
                                if (!resultWord2)
                                    goto originalBlock220;
                                argumentWord4 = ownerAddress18;
                                Level16_79AF4Keep(argumentWord4);
                                goto originalBlock255;
                            case 5:
                                if ((Level16_79AF4TurnMobyTowardHeading(ownerAddress18, workWord21,
                                                                        6, 0xC, 1, 0) != 0) &&
                                    (Level16_79AF4_D_8006C770 != 0)) {
                                    if (Level16_79AF4Field(privateAddress17, int*, 0x6C) == 0) {
                                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 1);
                                        Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                            Level16_79AF4RandBetween(1, 2);
                                    } else {
                                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 0);
                                        MATCHING_OBSERVE_VOLATILE_CLOBBER(privateAddress17,
                                                                          "memory");
                                        Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                            (int)(Level16_79AF4Field(privateAddress17, int*, 0x6C) -
                                                  1);
                                    }
                                }
                                resultWord2 =
                                    Level16_79AF4UpdateMobyInteractionGate(ownerAddress18, 0);
                                __asm__ volatile(""
                                                 : "=r"(resultWord2)
                                                 : "0"(resultWord2), "i"(5)
                                                 : "memory");
                                if (!resultWord2)
                                    goto originalBlock220;
                                argumentWord4 = ownerAddress18;
                                Level16_79AF4Keep(argumentWord4);
                                goto originalBlock255;
                            case 2:
                                if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) !=
                                    0xA) {
                                    Level16_79AF4_D_8006C770 = 0;
                                    Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 0xAU;
                                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                                    Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                                }
                                temp_v0_3 =
                                    (Level16_79AF4Field(privateAddress17, int*, 0x108) * 0x58) +
                                    Level16_79AF4_D_8006C550;
                                resultWord2 = Level16_79AF4PlanarHeadingLookup(
                                    Level16_79AF4Field(temp_v0_3, int*, 0xC) -
                                        Level16_79AF4Field(ownerAddress18, int*, 0xC),
                                    Level16_79AF4Field(temp_v0_3, int*, 0x10) -
                                        Level16_79AF4Field(ownerAddress18, int*, 0x10),
                                    0);
                                argumentWord4 = ownerAddress18;
                                argumentWord5 = resultWord2;
                                argumentWord6 = 5;
                                goto originalBlock197;
                            case 3:
                                if (Level16_79AF4Field(privateAddress17, unsigned char*, 5) == 0) {
                                    if (Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*,
                                                           0xB8) == 0) {
                                        temp_v1_8 =
                                            Level16_79AF4Field(ownerAddress18, int*, 0x14) -
                                            Level16_79AF4Field(ownerAddress18, short*, 0x38);
                                        temp_v0_4 = temp_v1_8 -
                                                    Level16_79AF4Field(
                                                        (int)&Level16_79AF4_D_80070328, int*, 8);
                                        if (temp_v0_4 >= 0) {
                                            if (temp_v0_4 < 0x2BC) {
                                                goto originalBlock160;
                                            }
                                            goto originalBlock173;
                                        }
                                        if ((Level16_79AF4Field((int)&Level16_79AF4_D_80070328,
                                                                int*, 8) -
                                             temp_v1_8) < 0x2BC) {
                                        originalBlock160:
                                            if (Level16_79AF4ApproximatePlanarDistance(
                                                    ownerAddress18 + 0xC,
                                                    (int)&Level16_79AF4_D_80070328) < 0x5DC) {
                                                goto originalBlock161;
                                            }
                                            goto originalBlock173;
                                        }
                                        goto originalBlock173;
                                    }
                                    goto originalBlock173;
                                }
                            originalBlock161:
                                resultWord2 =
                                    Level16_79AF4Field(privateAddress17, unsigned char*, 118);
                                if (resultWord2)
                                    resultWord2 = 7;
                                else
                                    resultWord2 = 6;
                                Level16_79AF4Field(privateAddress17, signed char*, 2) = resultWord2;
                                __asm__ volatile("" ::"m"(
                                    Level16_79AF4Field(privateAddress17, signed char*, 2)));
                                if (Level16_79AF4TurnMobyTowardHeading(ownerAddress18, 0, 6, 0x18,
                                                                       1, 0) != 0) {
                                    if (Level16_79AF4_D_8006C770 != 0) {
                                        if (Level16_79AF4Field(privateAddress17, int*, 0x6C) == 0) {
                                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 1);
                                            Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                                Level16_79AF4RandBetween(1, 2);
                                        } else {
                                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 0);
                                            MATCHING_OBSERVE_VOLATILE_CLOBBER(privateAddress17,
                                                                              "memory");
                                            Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                                (int)(Level16_79AF4Field(privateAddress17, int*,
                                                                         0x6C) -
                                                      1);
                                        }
                                    }
                                    resultWord2 =
                                        Level16_79AF4UpdateMobyInteractionGate(ownerAddress18, 0);
                                    __asm__ volatile(""
                                                     : "=r"(resultWord2)
                                                     : "0"(resultWord2), "i"(3)
                                                     : "memory");
                                    if (!resultWord2)
                                        goto originalBlock220;
                                    argumentWord4 = ownerAddress18;
                                    Level16_79AF4Keep(argumentWord4);
                                    goto originalBlock255;
                                    goto originalBlock220;
                                }
                                goto originalBlock220;
                            actor1513SelectFirst:
                                Level16_79AF4Field(privateAddress17, int*, 252) = workWord3;
                                goto actor1513FirstDone;
                            actor1513SelectSecond:
                                Level16_79AF4Field(privateAddress17, int*, 252) = workWord3;
                                goto actor1513SecondDone;
                            originalBlock173:
                                workWord3 = Level16_79AF4Field(ownerAddress18, unsigned char*, 61);
                                resultWord2 = 11;
                                argumentWord4 = ownerAddress18;
                                if (workWord3 != resultWord2) {
                                    resultWord2 = 114;
                                    Level16_79AF4_D_8006C770 = 0;
                                    Level16_79AF4Field(ownerAddress18, signed char*, 64) =
                                        resultWord2;
                                    resultWord2 = 11;
                                    Level16_79AF4Field(ownerAddress18, unsigned char*, 61) =
                                        resultWord2;
                                    Level16_79AF4Field(ownerAddress18, unsigned char*, 63) = 0;
                                    Level16_79AF4EmptyAnimationTransitionHook(argumentWord4);
                                }
                                argumentWord4 = Level16_79AF4Field(privateAddress17, int*, 252);
                                resultWord2 = 138;
                                if (!argumentWord4)
                                    goto actor1513FirstReload;
                                workWord3 = Level16_79AF4Field(argumentWord4, short*, 54);
                                {
                                    if (workWord3 == resultWord2 ? (resultWord2 = 20, 1)
                                                                 : (resultWord2 = 20, 0)) {
                                        workWord3 =
                                            Level16_79AF4Field(argumentWord4, unsigned char*, 72);
                                        if (workWord3 == resultWord2) {
                                            Level16_79AF4Field(privateAddress17, int*, 252) = 0;
                                            MATCHING_BARRIER_VOLATILE("memory");
                                            argumentWord4 =
                                                Level16_79AF4Field(privateAddress17, int*, 252);
                                        }
                                    }
                                }
                                MATCHING_OBSERVE_VOLATILE(resultWord2);
                                resultWord2 = 154;
                                if (!argumentWord4)
                                    goto actor1513FirstReload;
                                workWord3 = Level16_79AF4Field(argumentWord4, short*, 54);
                                if (workWord3 == resultWord2) {
                                    resultWord2 =
                                        Level16_79AF4Field(argumentWord4, unsigned char*, 72);
                                    resultWord2 = (unsigned int)resultWord2 < 128U;
                                    Level16_79AF4Keep(resultWord2);
                                    if (!resultWord2) {
                                        MATCHING_BARRIER_VOLATILE("$2");
                                        Level16_79AF4Field(privateAddress17, int*, 252) = 0;
                                    }
                                }
                                MATCHING_BARRIER_VOLATILE("memory");
                                resultWord2 = Level16_79AF4Field(privateAddress17, int*, 252);
                                capturedWord8 = 20;
                                if (resultWord2) {
                                    Level16_79AF4Keep(capturedWord8);
                                    workWord3 = Level16_79AF4Field(resultWord2, short*, 54);
                                    resultWord2 = 138;
                                    if (workWord3 == resultWord2)
                                        goto actor1513FirstDone;
                                } else
                                    goto actor1513FirstBody;
                            actor1513FirstReload:
                                capturedWord8 = 20;
                            actor1513FirstBody:
                                argumentWord7 = 3;
                                resultWord2 = Level16_79AF4_D_8006C730;
                                argumentWord6 = Level16_79AF4_D_8006C550;
                                argumentWord4 = Level16_79AF4Field(resultWord2, int*, 28);
                            actor1513FirstLoop:
                                argumentWord5 =
                                    Level16_79AF4Field(argumentWord4, unsigned short*, 0);
                                workWord3 = argumentWord5 & 32767;
                                resultWord2 = workWord3 * 88;
                                workWord3 = argumentWord6 + resultWord2;
                                resultWord2 = Level16_79AF4Field(workWord3, unsigned char*, 72);
                                if (resultWord2 != capturedWord8 && resultWord2 != argumentWord7)
                                    goto actor1513SelectFirst;
                                resultWord2 = (unsigned int)argumentWord5 << 16;
                                Level16_79AF4Keep(resultWord2);
                                argumentWord4 += 2;
                                if (resultWord2 >= 0)
                                    goto actor1513FirstLoop;
                            actor1513FirstDone:
                                MATCHING_BARRIER_VOLATILE("memory");
                                resultWord2 = Level16_79AF4Field(privateAddress17, int*, 252);
                                argumentWord6 = 0;
                                if (resultWord2)
                                    goto actor1513HeadingLoaded;
                                resultWord2 = Level16_79AF4_D_8006C730;
                                argumentWord6 = Level16_79AF4_D_8006C550;
                                argumentWord4 = Level16_79AF4Field(resultWord2, int*, 20);
                            actor1513SecondLoop:
                                argumentWord5 =
                                    Level16_79AF4Field(argumentWord4, unsigned short*, 0);
                                resultWord2 = argumentWord5 & 32767;
                                workWord3 = resultWord2 * 88;
                                workWord3 = argumentWord6 + workWord3;
                                resultWord2 = Level16_79AF4Field(workWord3, unsigned char*, 72);
                                resultWord2 = (unsigned int)resultWord2 < 128U;
                                Level16_79AF4Keep(resultWord2);
                                if (resultWord2)
                                    goto actor1513SelectSecond;
                                resultWord2 = (unsigned int)argumentWord5 << 16;
                                Level16_79AF4Keep(resultWord2);
                                argumentWord4 += 2;
                                if (resultWord2 >= 0)
                                    goto actor1513SecondLoop;
                            actor1513SecondDone:
                                MATCHING_BARRIER_VOLATILE("memory");
                                resultWord2 = Level16_79AF4Field(privateAddress17, int*, 252);
                                argumentWord6 = 0;
                                if (!resultWord2)
                                    goto originalBlock220;
                                MATCHING_BARRIER_VOLATILE("memory");
                                resultWord2 = Level16_79AF4Field(privateAddress17, int*, 252);
                            actor1513HeadingLoaded:
                                argumentWord4 = Level16_79AF4Field(ownerAddress18, int*, 12);
                                argumentWord5 = Level16_79AF4Field(ownerAddress18, int*, 16);
                                workWord3 = Level16_79AF4Field(resultWord2, int*, 12);
                                resultWord2 = Level16_79AF4Field(resultWord2, int*, 16);
                                resultWord2 = Level16_79AF4PlanarHeadingLookup(
                                    workWord3 - argumentWord4, resultWord2 - argumentWord5,
                                    argumentWord6);
                                argumentWord4 = ownerAddress18;
                                argumentWord5 = resultWord2;
                                argumentWord6 = 6;
                            originalBlock197:
                                Level16_79AF4TurnMobyTowardHeading(argumentWord4, argumentWord5,
                                                                   argumentWord6, 0, 0, 0);
                                goto originalBlock220;
                            case 4:
                                resultWord2 =
                                    Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*, 184);
                                if (resultWord2)
                                    goto originalBlock213;
                                workWord3 = Level16_79AF4Field(ownerAddress18, short*, 56);
                                resultWord2 = Level16_79AF4Field(ownerAddress18, int*, 20);
                                argumentWord4 =
                                    Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*, 8);
                                workWord3 = resultWord2 - workWord3;
                                resultWord2 = workWord3 - argumentWord4;
                                if (resultWord2 < 0)
                                    goto actor1513Case4Negative;
                                resultWord2 = resultWord2 < 700;
                                Level16_79AF4Keep(resultWord2);
                                if (!resultWord2)
                                    goto originalBlock213;
                                goto originalBlock203;
                            actor1513Case4Negative:
                                resultWord2 = argumentWord4 - workWord3;
                                resultWord2 = resultWord2 < 700;
                                argumentWord6 = 0;
                                if (!resultWord2)
                                    goto actor1513LoadedZeroHeading;
                                MATCHING_OBSERVE_VOLATILE(argumentWord6);
                            originalBlock203:
                                resultWord2 = Level16_79AF4ApproximatePlanarDistance(
                                    ownerAddress18 + 12, (int)&Level16_79AF4_D_80070328);
                                if (resultWord2 < 1800) {
                                    if (Level16_79AF4TurnMobyTowardPlayer(ownerAddress18, 6, 2,
                                                                          1) != 0) {
                                        if (Level16_79AF4_D_8006C770 != 0) {
                                            if (Level16_79AF4Field(privateAddress17, int*, 0x6C) ==
                                                0) {
                                                Level16_79AF4RequestMobyAnimation(ownerAddress18,
                                                                                  1);
                                                Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                                    Level16_79AF4RandBetween(1, 2);
                                            } else {
                                                Level16_79AF4RequestMobyAnimation(ownerAddress18,
                                                                                  0);
                                                MATCHING_OBSERVE_VOLATILE_CLOBBER(privateAddress17,
                                                                                  "memory");
                                                Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                                    (int)(Level16_79AF4Field(privateAddress17, int*,
                                                                             0x6C) -
                                                          1);
                                            }
                                        }
                                        resultWord2 = Level16_79AF4UpdateMobyInteractionGate(
                                            ownerAddress18, 0);
                                        __asm__ volatile(""
                                                         : "=r"(resultWord2)
                                                         : "0"(resultWord2), "i"(4)
                                                         : "memory");
                                        if (!resultWord2)
                                            goto originalBlock220;
                                        argumentWord4 = ownerAddress18;
                                        Level16_79AF4Keep(argumentWord4);
                                        goto originalBlock255;
                                        goto originalBlock220;
                                    }
                                    goto originalBlock216;
                                }
                                goto originalBlock213;
                            originalBlock213:
                                argumentWord6 = 0;
                            actor1513LoadedZeroHeading:
                                MATCHING_OBSERVE_VOLATILE(argumentWord6);
                                temp_v0_8 =
                                    (Level16_79AF4Field(privateAddress17, int*, 0x104) * 0x58) +
                                    Level16_79AF4_D_8006C550;
                                resultWord2 = Level16_79AF4TurnMobyTowardHeading(
                                    ownerAddress18,
                                    Level16_79AF4PlanarHeadingLookup(
                                        Level16_79AF4Field(temp_v0_8, int*, 0xC) -
                                            Level16_79AF4Field(ownerAddress18, int*, 0xC),
                                        Level16_79AF4Field(temp_v0_8, int*, 0x10) -
                                            Level16_79AF4Field(ownerAddress18, int*, 0x10),
                                        argumentWord6),
                                    6, 0, 0, 0);
                                if (!resultWord2)
                                    goto originalBlock216;
                                resultWord2 = 9;
                                workWord3 = Level16_79AF4Field(ownerAddress18, unsigned char*, 61);
                                argumentWord4 = ownerAddress18;
                                if (workWord3 == resultWord2)
                                    goto originalBlock220;
                                resultWord2 = 114;
                                Level16_79AF4_D_8006C770 = 0;
                                Level16_79AF4Field(ownerAddress18, signed char*, 64) = resultWord2;
                                resultWord2 = 9;
                                goto originalBlock218;
                            originalBlock216:
                                workWord3 = Level16_79AF4Field(ownerAddress18, unsigned char*, 61);
                                resultWord2 = 5;
                                argumentWord4 = ownerAddress18;
                                if (workWord3 == resultWord2)
                                    goto originalBlock220;
                                resultWord2 = 114;
                                Level16_79AF4_D_8006C770 = 0;
                                Level16_79AF4Field(ownerAddress18, signed char*, 64) = resultWord2;
                                resultWord2 = 5;
                            originalBlock218:
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 61) =
                                    resultWord2;
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 63) = 0;
                            originalBlock219:
                                Level16_79AF4EmptyAnimationTransitionHook(argumentWord4);
                                goto originalBlock220;
                            default:
                            originalBlock220:
                                MATCHING_OBSERVE_VOLATILE(var_s4);
                                if (Level16_79AF4Field(ownerAddress18, int*, 0x18) != 0) {
                                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0xCU;
                                    Level16_79AF4RequestMobyAnimation(ownerAddress18, 0xC);
                                }
                                Level16_79AF4Field(ownerAddress18, int*, 0x18) = 0;
                                goto originalBlock284;
                        }
                        break;
                }
                break;
            case 30:
                temp_v1_14 = Level16_79AF4Field(privateAddress17, int*, 0x44);
                temp_v0_9 = (Level16_79AF4Field(temp_v1_14, short*, 0) * 0x10) +
                            Level16_79AF4Field(temp_v1_14, int*, 0xC);
                temp_a3 = Level16_79AF4Field(temp_v0_9, int*, -0x20);
                temp_a1_7 = Level16_79AF4PlanarHeadingLookup(
                                temp_a3 - Level16_79AF4Field(temp_v0_9, int*, -0x10),
                                Level16_79AF4Field(temp_v0_9, int*, -0x1C) -
                                    Level16_79AF4Field(temp_v0_9, int*, -0xC),
                                0) &
                            0xFF;
                Level16_79AF4Field(privateAddress17, unsigned char*, 5) = 1U;
                if (Level16_79AF4TurnMobyTowardHeading(ownerAddress18, temp_a1_7, 5, 4, 1, 0) !=
                    0) {
                    if (Level16_79AF4_D_8006C770 != 0) {
                        if (Level16_79AF4Field(privateAddress17, int*, 0x6C) == 0) {
                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 1);
                            Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                Level16_79AF4RandBetween(1, 2);
                        } else {
                            Level16_79AF4RequestMobyAnimation(ownerAddress18, 3);
                            Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                                (int)(Level16_79AF4Field(privateAddress17, int*, 0x6C) - 1);
                        }
                    }
                    Level16_79AF4Field(privateAddress17, signed char*, 2) =
                        (signed char)(Level16_79AF4Field(privateAddress17, int*, 0x70) + 9);
                    if (Level16_79AF4UpdateMobyInteractionGate(ownerAddress18, 0) != 0) {
                        Level16_79AF4_D_8006C7B4 |= 1 << workWord16;
                        Level16_79AF4StartDialogue(ownerAddress18, 0, 2);
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0x1FU;
                        return;
                    }
                    goto originalBlock284;
                }
                goto originalBlock284;
            case 31:
                if (Level16_79AF4_D_8006E344 == 1)
                    goto originalBlock284;
                resultWord2 = 32;
                goto originalBlock246;
            case 32:
                if (Level16_79AF4Field(ownerAddress18, int*, 0x18) != 0) {
                    if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) != 0xC) {
                        Level16_79AF4_D_8006C770 = 0;
                        Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 0xCU;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                        Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                    }
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0x21U;
                    return;
                }
                Level16_79AF4Field(ownerAddress18, int*, 0x18) = 0;
                if ((Level16_79AF4TurnMobyTowardPlayer(ownerAddress18, 5, 0x10, 1) != 0) &&
                    (Level16_79AF4_D_8006C770 != 0)) {
                    if (Level16_79AF4Field(privateAddress17, int*, 0x6C) == 0) {
                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 1);
                        Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                            Level16_79AF4RandBetween(1, 2);
                    } else {
                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 3);
                        Level16_79AF4Field(privateAddress17, int*, 0x6C) =
                            (int)(Level16_79AF4Field(privateAddress17, int*, 0x6C) - 1);
                    }
                }
                goto originalBlock284;
            case 33:
                if (Level16_79AF4_D_8006C770 != 0) {
                    if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) != 0) {
                        Level16_79AF4_D_8006C770 = 0;
                        Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 0U;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                        Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                    }
                    resultWord2 = 32;
                originalBlock246:
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 72) = resultWord2;
                }
                goto originalBlock284;
            case 20:
                Level16_79AF4Field((int)&Level16_79AF4_D_80070328, int*, 0x20C) = 0x10000002;
                Level16_79AF4Field(privateAddress17, unsigned char*, 5) = 1U;
                temp_v1_15 = Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D);
                if (((temp_v1_15 != 4) || (Level16_79AF4_D_8006C770 != 0)) && (temp_v1_15 != 5)) {
                    Level16_79AF4_D_8006C770 = 0;
                    Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 5U;
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                    Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                }
                if ((Level16_79AF4TurnMobyTowardPlayer(ownerAddress18, 6, 0x14, 1) != 0) &&
                    (Level16_79AF4ResolveMobyYawStep(ownerAddress18, 0x5A, 0x12C, 0x12C, 0x37) !=
                     0)) {
                    Level16_79AF4Field(privateAddress17, short*, 0x74) = 1;
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                }
                resultWord2 = Level16_79AF4UpdateMobyInteractionGate(ownerAddress18, 0);
                argumentWord4 = ownerAddress18;
                if (resultWord2) {
                originalBlock255:
                    __asm__ volatile("" ::"r"(argumentWord4) : "$5", "memory");
                    argumentWord5 = 0;
                    Level16_79AF4StartDialogue(argumentWord4, argumentWord5, 2);
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 72) = 2;
                    return;
                }
                goto originalBlock284;
            case 2:
                if (Level16_79AF4_D_8006E344 != 1) {
                    Level16_79AF4Field(privateAddress17, unsigned char*, 0x76) = 1U;
                    if (Level16_79AF4Field(privateAddress17, short*, 0x74) == 0) {
                        Level16_79AF4unk_ovlheader_800743D8(
                            Level16_79AF4Field(ownerAddress18, unsigned char*, 0x43), 3);
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x49) = 1U;
                        Level16_79AF4Field(privateAddress17, short*, 0x74) = 1;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        Level16_79AF4RequestMobyAnimation(ownerAddress18, 5);
                        Level16_79AF4Field(ownerAddress18, int*, 0x18) = 0;
                        return;
                    }
                    Level16_79AF4Field(privateAddress17, int*, 0x68) = 0;
                    Level16_79AF4Field(privateAddress17, int*, 0x64) =
                        Level16_79AF4RandBetween(0x28, 0x50);
                    Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                    goto originalBlock284;
                }
                goto originalBlock284;
            case 5:
                workWord16 = 170;
                case5FortyWord = 40;
                resultWord2 = Level16_79AF4UpdateEffectConfiguration(
                    ownerAddress18, privateAddress17 + 72, 4, 12, -200);
                if (resultWord2) {
                    workWord16 = 0x6E;
                    if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) != 5) {
                        Level16_79AF4_D_8006C770 = 0;
                        Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 5U;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                        Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                    }
                }
                if (Level16_79AF4_D_8006C770 != 0) {
                    if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) == 6) {
                        Level16_79AF4_D_8006C770 = 0;
                        Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 7U;
                        Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                        Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                    }
                }
                {
                    register int case5SavedForty19 __asm__("$19") = case5FortyWord;
                    if ((Level16_79AF4UpdateMobyPathMotion(
                             ownerAddress18, Level16_79AF4Field(privateAddress17, int*, 0x44),
                             0x100, workWord16, 0, 5, case5SavedForty19, 1) &
                         1) &&
                        (temp_v0_10 = Level16_79AF4Field(privateAddress17, int*, 0x44),
                         temp_v1_16 = Level16_79AF4Field(temp_v0_10, short*, 2),
                         (temp_v1_16 > 0))) {
                        if (Level16_79AF4Field(
                                ((temp_v1_16 * 0x10) + Level16_79AF4Field(temp_v0_10, int*, 0xC)),
                                int*, -4) &
                            1) {
                            Level16_79AF4Field(privateAddress17, unsigned char*, 0x77) = 1U;
                        }
                        temp_v0_11 = Level16_79AF4Field(privateAddress17, int*, 0x44);
                        temp_v1_17 = Level16_79AF4Field(temp_v0_11, short*, 2);
                        if (temp_v1_17 <= 0)
                            goto originalBlock280;
                        resultWord2 = Level16_79AF4Field(((temp_v1_17 * 16) +
                                                          Level16_79AF4Field(temp_v0_11, int*, 12)),
                                                         int*, -4) &
                                      65534;
                        Level16_79AF4Keep(resultWord2);
                        argumentWord5 = resultWord2;
                        if (resultWord2) {
                            if (argumentWord5 == 4096) {
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0x1EU;
                                return;
                            }
                            resultWord2 = Level16_79AF4Field(privateAddress17, short*, 116);
                            workWord3 = resultWord2;
                            argumentWord4 = 1U << resultWord2;
                            if (argumentWord5 >= argumentWord4) {
                                resultWord2 = argumentWord4 < argumentWord5;
                                Level16_79AF4Keep(resultWord2);
                                if (resultWord2) {
                                    argumentWord4 = 1;
                                    do {
                                        resultWord2 = workWord3 + 1;
                                        workWord3 = resultWord2;
                                        resultWord2 = argumentWord4 << resultWord2;
                                        resultWord2 = resultWord2 < argumentWord5;
                                        Level16_79AF4Keep(resultWord2);
                                        Level16_79AF4Field(privateAddress17, short*, 116) =
                                            workWord3;
                                    } while (resultWord2);
                                }
                                Level16_79AF4CopyVector(privateAddress17 + 0x4C,
                                                        ownerAddress18 + 0xC);
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                                if ((unsigned int)((unsigned short)Level16_79AF4Field(
                                                       privateAddress17, short*, 0x74) -
                                                   7) < 2U) {
                                    Level16_79AF4Field(privateAddress17, unsigned char*, 5) = 1U;
                                    return;
                                }
                            } else {
                                goto originalBlock280;
                            }
                        } else {
                            goto originalBlock280;
                        }
                    } else {
                    originalBlock280:
                        if ((Level16_79AF4Field(privateAddress17, unsigned char*, 0x77) != 0) &&
                            (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) == 5)) {
                            temp_v0_15 = Level16_79AF4Field(privateAddress17, int*, 0x44);
                            Level16_79AF4Field(privateAddress17, unsigned char*, 0x77) = 0U;
                            Level16_79AF4Field(privateAddress17, int*, 0x48) =
                                Level16_79AF4ComputeArcVerticalVelocity(
                                    ownerAddress18 + 0xC,
                                    Level16_79AF4Field(temp_v0_15, int*, 0xC) +
                                        (Level16_79AF4Field(temp_v0_15, short*, 2) * 0x10),
                                    0xAA, -0xC, &originalFrame.output);
                            if (Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) != 6) {
                                Level16_79AF4_D_8006C770 = 0;
                                Level16_79AF4Field(ownerAddress18, signed char*, 0x40) = 0x72;
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3D) = 6U;
                                Level16_79AF4Field(ownerAddress18, unsigned char*, 0x3F) = 0U;
                                Level16_79AF4EmptyAnimationTransitionHook(ownerAddress18);
                            }
                        }
                        goto originalBlock284;
                    }
                }
                break;
            default:
            originalBlock284:
                MATCHING_BARRIER_VOLATILE("memory");
                Level16_79AF4Field(ownerAddress18, int*, 0x18) = 0;
                return;
        }
    }
}
#undef Level16_79AF4Field
#undef Level16_79AF4Keep

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_16/moby/func_level_16_8007B298.s SHA256 ed2d82261fae80c03046b17632561806e6a7734d203e7e03226e1546e702c388. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level16_7B298Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level16_7B298_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level16_7B298_D_80065920[0x100] __asm__("D_80065920");
extern Spyro Level16_7B298_D_80070328 __asm__("D_80070328");
void Level16_7B298SetCameraOwnerAndControlWord(Moby*, int) __asm__("func_80013ACC");
void Level16_7B298RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level16_7B298UpdateMobyMotionDescriptor(Moby*, void*) __asm__("func_80035194");
void Level16_7B298EmptyAnimationTransitionHook(Moby* moby) __asm__("func_80035734");
int Level16_7B298TurnMobyTowardPlayer(Moby* owner, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level16_7B298TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
int Level16_7B298ResolveMobyYawStep(Moby* owner, int arg1, int arg2, int arg3,
                                    int arg4) __asm__("func_80035DDC");
int Level16_7B298BlendBoundedAngle8Step(int owner, int arg1, int arg2,
                                        unsigned char arg3) __asm__("func_800360F8");
void Level16_7B298EmitMobyVertexParticles() __asm__("func_800369B8");
extern int Level16_7B298PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern int Level16_7B298AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level16_7B298ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level16_7B298DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level16_7B298RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level16_7B298ReadSelectedFrameScalar(Moby*) __asm__("func_80055E84");
struct _m2c_stack_func_level_16_8007B298 {
    /* 0x00 */ char pad0[0x30];
};
/* size = 0x30 */

unsigned char Level16_7B298SpawnMobyFromValueSelector(Moby*, unsigned char, unsigned char,
                                                      unsigned char) __asm__("func_80036A68");
/* extern */
extern int Level16_7B298_D_8006C770 __asm__("D_8006C770");
extern int Level16_7B298_D_8006E020 __asm__("D_8006E020");
extern int Level16_7B298_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level16_7B298_D_8006E040 __asm__("D_8006E040");
extern int Level16_7B298_D_8006E160 __asm__("D_8006E160");
extern int Level16_7B298_D_8006E164 __asm__("D_8006E164");
extern int Level16_7B298_D_8006E344 __asm__("D_8006E344");

void func_level_16_8007B298(Moby* owner) {
    /* Original frame0x30 and explicit dispatch/control entries retained.
     * The private-position+0x28 and Spyro-field-0xB8 offsets use bytes.
     * The shared state callback has two entries: one restores the owner
     * argument and the other uses its preceding original producer.
     * Signed height predicates, sine-table byte indices, separate global
     * stores and animation argument/load order follow original words.
     * Empty constraints emit no instructions or opcode patches.
     * Units/fixed-point domains, helper meanings, cadence and synchronized
     * runtime chains remain unresolved. Machine identity only. */
    Vector3D* privatePosition;
    register int* globalPointer3 __asm__("$3");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int playerZ4 __asm__("$4");
    register int argument6 __asm__("$6");
    int angleOrPosition16;
    int heightDelta;
    int heightDelta1;
    int heightDelta3;
    int groundPosition;
    int groundPosition1;
    int temp_v1_4;
    int groundPosition3;
    register int argument5 __asm__("$5");
    register int ownerArgument4 __asm__("$4");
    int mode20;
    int heightCondition;
    unsigned char temp_a1;
    unsigned char temp_a1_2;
    unsigned char temp_a1_3;
    int stateWord;
    unsigned char temp_v1_2;
    unsigned char temp_v1_6;
    unsigned char temp_v1_7;

    privatePosition = owner->mobyTag;
    if ((owner->damageFlags != 0) && (owner->state != 2)) {
        value2 = owner->unkb;
        argument6 = 0;
        if (value2 == 0) {
            MATCHING_BARRIER("$2");
            value2 = Level16_7B298BlendBoundedAngle8Step(
                Level16_7B298PlanarHeadingLookup(
                    owner->position.x - Level16_7B298_D_80070328.position.x,
                    owner->position.y - Level16_7B298_D_80070328.position.y, argument6),
                (int)Level16_7B298_D_80070328.bodyRotation.yaw, 0x20, 0x40U);
        }
        Level16_7B298Field(privatePosition, unsigned char*, 0x39) = value2;
        value2 = owner->damageFlags;
        value3 = 0x10000;
        value2 &= value3;
        if (value2)
            value2 = 0x118;
        else
            value2 = 0x190;
        Level16_7B298Field(privatePosition, short*, 0x2C) = value2;
        __asm__ volatile("" : : "m"(Level16_7B298Field(privatePosition, short*, 0x2C)) : "$3");
        value2 = 0x32;
        Level16_7B298Field(privatePosition, short*, 0x2E) = value2;
        globalPointer3 = &Level16_7B298_D_8006E164;
        if (*globalPointer3 == (int)owner) {
            Level16_7B298_D_8006E160 = 0;
            *globalPointer3 = 0;
        }
        if (owner->state != 0) {
            *Level16_7B298Field(privatePosition, int**, 0x20) = 0;
        }
        Level16_7B298SpawnMobyFromValueSelector(owner, 0, 0, 0);
        owner->state = 2;
        Level16_7B298RequestMobyAnimation(owner, 2);
    }
    stateWord = owner->state;
    value2 = 2;
    if (stateWord == value2)
        goto state2;
    value2 = stateWord < 3;
    if (!value2)
        goto dispatchUpperStates;
    if (!stateWord)
        goto state0;
    value2 = 1;
    ownerArgument4 = (int)owner;
    if (stateWord == value2)
        goto state1;
    goto call55D24;
dispatchUpperStates:
    value2 = 4;
    if (stateWord == value2)
        goto state4;
    value2 = stateWord < 4;
    ownerArgument4 = (int)owner;
    if (value2)
        goto state3;
    value2 = 99;
    if (stateWord == value2)
        goto state99;
    goto restoreOwnerAndCall55D24;
    {
    state0:
        Level16_7B298TurnMobyTowardPlayer(owner, 0xA, 0, 0);
        value2 = *Level16_7B298Field(privatePosition, int**, 0x20);
        ownerArgument4 = (int)owner;
        if (!value2) {
            groundPosition = owner->position.z - owner->distanceToGround;
            heightDelta = groundPosition - Level16_7B298_D_80070328.position.z;
            if (heightDelta >= 0) {
                ownerArgument4 = (int)owner;
                if (heightDelta < 0x320)
                    goto checkState0Contact;
                goto call55D24;
            }
            value2 = (Level16_7B298_D_80070328.position.z - groundPosition) < 0x320;
            ownerArgument4 = (int)owner;
            if (value2) {
            checkState0Contact:
                if ((Level16_7B298_D_80070328.ticksSinceLastSurfaceTouch == 0) &&
                    (Level16_7B298AbsoluteByteAngleDelta(
                         (int)(Level16_7B298_D_8006E040 << 0x10) >> 0x14,
                         Level16_7B298PlanarHeadingLookup(
                             owner->position.x - Level16_7B298_D_8006E020,
                             owner->position.y - Level16_7B298_D_8006E024, 0)) < 0x18) &&
                    (Level16_7B298ApproximatePlanarDistance(
                         &owner->position, (Vector3D*)((unsigned char*)&Level16_7B298_D_80070328
                                                           .ticksSinceLastSurfaceTouch -
                                                       0xB8)) <
                     Level16_7B298Field(privatePosition, int*, 0x24))) {
                    *Level16_7B298Field(privatePosition, int**, 0x20) = 1;
                    Level16_7B298SetCameraOwnerAndControlWord(owner, 0xD);
                    owner->state = 1;
                    return;
                }
            finishState:
                goto restoreOwnerAndCall55D24;
            }
            goto call55D24;
        }
    state0Fallback:
        goto call55D24;
    state1:
        mode20 = 4;
        if (owner->animationState.nextId != stateWord) {
            Level16_7B298_D_8006C770 = 0;
            temp_v1_2 = owner->animationState.nextId;
            temp_a1 = owner->animationState.nextFrame;
            owner->animationProgress = 0x72;
            owner->animationState.nextId = 1;
            owner->animationState.nextFrame = 0;
            owner->animationState.id = temp_v1_2;
            owner->animationState.frame = temp_a1;
            Level16_7B298EmptyAnimationTransitionHook(owner);
        }
        angleOrPosition16 = Level16_7B298PlanarHeadingLookup(
            Level16_7B298_D_80070328.position.x - owner->position.x,
            Level16_7B298_D_80070328.position.y - owner->position.y, 0);
        if (Level16_7B298ApproximatePlanarDistance(&owner->position,
                                                   &Level16_7B298_D_80070328.position) < 0xBB8) {
            mode20 = 8;
        }
        if ((Level16_7B298TurnMobyTowardHeading(owner, angleOrPosition16 & 0xFF, mode20, 0x1E,
                                                (int)stateWord, 0) == 0) ||
            (Level16_7B298ResolveMobyYawStep(owner, 0xC8, 0x12C, 0x12C, 0x205) == 0)) {
            if (Level16_7B298_D_80070328.ticksSinceLastSurfaceTouch == 0) {
                value3 = owner->distanceToGround;
                value2 = owner->position.z;
                playerZ4 = Level16_7B298_D_80070328.position.z;
                value3 = value2 - value3;
                value2 = value3 - playerZ4;
                if (value2 >= 0)
                    value2 = value2 < 0x321;
                else
                    value2 = (playerZ4 - value3) < 0x321;
                if (value2) {
                    goto checkState1Contact;
                }
                goto clearContactRecord;
            }
        checkState1Contact:
            if ((Level16_7B298ApproximatePlanarDistance(&owner->position, privatePosition) <
                 0x3001) &&
                (Level16_7B298_D_8006E344 != 1)) {
                if ((Level16_7B298ApproximatePlanarDistance(
                         &owner->position, &Level16_7B298_D_80070328.position) < 0x7D0) &&
                    ((value2 = Level16_7B298AbsoluteByteAngleDelta(
                          (int)owner->angle.yaw,
                          Level16_7B298PlanarHeadingLookup(
                              Level16_7B298_D_80070328.position.x - owner->position.x,
                              Level16_7B298_D_80070328.position.y - owner->position.y, 0)),
                      ownerArgument4 = (int)owner, value2 < 0x14))) {
                    argument5 = 3;
                    Level16_7B298Field(privatePosition, int*, 0x10) = 0x64;
                    Level16_7B298Field(privatePosition, int*, 0x1C) = 0;
                    owner->state = 3;
                    goto call34F40;
                }
                goto finishState;
            }
            goto clearContactRecord;
        }
        goto clearContactRecord;
    state2:
        Level16_7B298UpdateMobyMotionDescriptor(owner,
                                                ((void*)((unsigned char*)privatePosition + 0x28)));
        if (Level16_7B298_D_8006C770 != 0) {
            Level16_7B298RefreshMobySpatialGridAndBasis(owner, 4);
            Level16_7B298EmitMobyVertexParticles(owner, 0x18);
            Level16_7B298DeleteMoby(owner);
            return;
        }
        goto finishState;
    state3:
        Level16_7B298TurnMobyTowardPlayer(owner, 4, 0, 0);
        if (Level16_7B298ResolveMobyYawStep(owner, Level16_7B298Field(privatePosition, int*, 0x10),
                                            0x12C, 0x12C, 5) != 0) {
        clearContactRecord:
            *Level16_7B298Field(privatePosition, int**, 0x20) = 0;
            globalPointer3 = &Level16_7B298_D_8006E164;
            if (*globalPointer3 == (int)owner) {
                Level16_7B298_D_8006E160 = 0;
                *globalPointer3 = 0;
            }
            goto storeState99;
        }
        if (Level16_7B298ReadSelectedFrameScalar(owner) >= 9) {
            temp_v1_4 = Level16_7B298Field(privatePosition, int*, 0x10);
            if (temp_v1_4 >= 0x51) {
                Level16_7B298Field(privatePosition, int*, 0x10) = (int)(temp_v1_4 - 5);
            }
        }
        if (Level16_7B298ApproximatePlanarDistance(&owner->position,
                                                   &Level16_7B298_D_80070328.position) < 0x4B0) {
            groundPosition3 = owner->position.z - owner->distanceToGround;
            heightDelta3 = groundPosition3 - Level16_7B298_D_80070328.position.z;
            if (heightDelta3 >= 0) {
                if (heightDelta3 < 0x384) {
                    goto updateContactFlag;
                }
            } else if ((Level16_7B298_D_80070328.position.z - groundPosition3) < 0x384) {
            updateContactFlag:
                if ((Level16_7B298Field(privatePosition, int*, 0x1C) == 0) &&
                    (Level16_7B298_D_80070328.animationState != 0x47)) {
                    Level16_7B298Field(privatePosition, int*, 0x1C) = 1;
                    Level16_7B298_D_80070328.unk17a = 0x10000400;
                    Level16_7B298_D_80070328.damageFlags |= 1;
                    Level16_7B298_D_80070328.unk17e.x =
                        (int)(Level16_7B298_D_80065920[owner->angle.yaw] * 0x55) >> 0xB;
                    value2 = owner->angle.yaw;
                    value2 *= 2;
                    value3 = Level16_7B298Field(&Level16_7B298_D_800658A0, short*, value2);
                    value2 = 0x32;
                    __asm__ volatile("" : "=r"(value3) : "0"(value3), "r"(value2));
                    Level16_7B298_D_80070328.unk17e.z = value2;
                    __asm__ volatile("" : : "r"(value3) : "$2", "memory");
                    value2 = (value3 * 0x55) >> 0xB;
                    Level16_7B298_D_80070328.unk17e.y = value2;
                } else if (Level16_7B298Field(privatePosition, int*, 0x1C) == 1) {
                    Level16_7B298Field(privatePosition, int*, 0x1C) = 2;
                }
            }
        }
        if (Level16_7B298_D_8006C770 != 0) {
            owner->state = 4;
            Level16_7B298RequestMobyAnimation(owner, 4);
        state4:
            value2 = Level16_7B298_D_8006C770;
            ownerArgument4 = (int)owner;
            if (value2) {
                *Level16_7B298Field(privatePosition, int**, 0x20) = 0;
                globalPointer3 = &Level16_7B298_D_8006E164;
                if (*globalPointer3 == (int)owner) {
                    Level16_7B298_D_8006E160 = 0;
                    *globalPointer3 = 0;
                }
                if (owner->animationState.nextId != 1) {
                    Level16_7B298_D_8006C770 = 0;
                    temp_v1_6 = owner->animationState.nextId;
                    temp_a1_2 = owner->animationState.nextFrame;
                    owner->animationProgress = 0x72;
                    owner->animationState.nextId = 1;
                    owner->animationState.nextFrame = 0;
                    owner->animationState.id = temp_v1_6;
                    owner->animationState.frame = temp_a1_2;
                    Level16_7B298EmptyAnimationTransitionHook(owner);
                }
                goto storeState99;
            }
            goto call55D24;
        }
        goto finishState;
    storeState99:
        owner->state = 0x63;
        return;
    state99:
        if (Level16_7B298TurnMobyTowardHeading(
                owner,
                Level16_7B298PlanarHeadingLookup(privatePosition->x - owner->position.x,
                                                 privatePosition->y - owner->position.y, 0),
                4, 0x14, 1, 0) != 0) {
            Level16_7B298ResolveMobyYawStep(owner, 0x5A, 0, 0, 5);
        }
        ownerArgument4 = (int)owner;
        if (owner->animationState.nextId != 1) {
            Level16_7B298_D_8006C770 = 0;
            temp_v1_7 = owner->animationState.nextId;
            temp_a1_3 = owner->animationState.nextFrame;
            owner->animationProgress = 0x72;
            owner->animationState.nextId = 1;
            owner->animationState.nextFrame = 0;
            owner->animationState.id = temp_v1_7;
            owner->animationState.frame = temp_a1_3;
            Level16_7B298EmptyAnimationTransitionHook(ownerArgument4);
        }
        value2 = Level16_7B298ApproximatePlanarDistance(&owner->position, privatePosition);
        ownerArgument4 = (int)owner;
        if (value2 < 0x80) {
            owner->state = 0;
            argument5 = 0;
            goto call34F40;
        }
        goto finishState;
    }
    return;
call34F40:
    Level16_7B298RequestMobyAnimation(ownerArgument4, argument5);
restoreOwnerAndCall55D24:
    MATCHING_BARRIER("$4");
    ownerArgument4 = (int)owner;
call55D24:
    Level16_7B298RefreshMobySpatialGridAndBasis(ownerArgument4, 1);
}
#undef Level16_7B298Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Derived from all 442 original
 * SCUS-94467 USA Rev0 instructions at level16:8007BA74 (sibling5237).
 * Raw field offsets and instruction order are the evidence. Helper meanings,
 * units, fixed point domains and update cadence remain unresolved.
 * Empty constraints control compiler registers and emit no opcode.
 * Every native instruction/target, linked word and retail hash is required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int ControllerBA74UpdateMobyPathMotion() __asm__("func_80035A80");           /* extern */
int ControllerBA74SpawnMobyFromValueSelector() __asm__("func_80036A68");     /* extern */
int ControllerBA74ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int ControllerBA74DeleteMoby() __asm__("func_80055B18");                     /* extern */
int ControllerBA74RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
extern int ControllerBA74D6C640 __asm__("D_8006C640");
extern int ControllerBA74D6C770 __asm__("D_8006C770");
extern int ControllerBA74D6E020 __asm__("D_8006E020");
extern int ControllerBA74D6E024 __asm__("D_8006E024");
extern unsigned short ControllerBA74D6E040 __asm__("D_8006E040");
extern int ControllerBA74D6E344 __asm__("D_8006E344");
extern unsigned char ControllerBA74D70328 __asm__("D_80070328");

void func_level_16_8007BA74(Moby* moby) {
    register Moby* arg0 __asm__("$16") = moby;
    register Vector3D* temp_s3 __asm__("$19");
    short temp_a0;
    register Moby* call4 __asm__("$4");
    int temp_v0;
    register int temp_v0_4 __asm__("$2");
    register int player4 __asm__("$4");
    register int height3 __asm__("$3");
    register int z2 __asm__("$2");
    int temp_v0_5;
    register int temp_v1_2 __asm__("$3");
    int temp_v1_3;
    int var_v0;
    register int temp_v0_2 __asm__("$2");
    register int temp_v1 __asm__("$3");
    register int var_a1 __asm__("$5");
    void* temp_a1;
    register void* temp_s1 __asm__("$17");
    void* temp_v0_3;
    void* var_a0;

    MATCHING_KEEP(arg0);
    temp_s1 = arg0->mobyTag;
    if ((arg0->damageFlags != 0) && (arg0->state != 3)) {
        ControllerBA74SpawnMobyFromValueSelector(moby, 0, 0, 0);
        func_80038BF8(arg0, (EnemyTag*)temp_s1, 5, 3);
    }
    arg0->damageFlags = 0;
    if (M2C_FIELD(temp_s1, int*, 0x2C) == 1) {
        if (ControllerBA74D6C640 == 0) {
            arg0->updateDistance = 0x1C;
            arg0->unknownCollision = 0;
            arg0->unknown3[0] = 0;
            arg0->lowDrawDistance = 0;
            arg0->drawn = 0;
            arg0->state = 0x14;
            return;
        }
        if (arg0->state == 0x14) {
            if (arg0->substate != 0) {
                arg0->substate = 0;
                arg0->unknown3[0] = 1;
                arg0->lowDrawDistance = 0x30;
                arg0->drawn = 1;
                ControllerBA74RefreshMobySpatialGridAndBasis(arg0, 1);
                arg0->state = 0;
                goto block_9;
            }
        } else {
            goto block_10;
        }
    } else {
    block_9:
    block_10:
        switch ((int)arg0->state) { /* irregular */
            case 0:
                if (func_800359A4(temp_s1 + 0x1C, 4) != 0) {
                    temp_v0 = M2C_FIELD(temp_s1, int*, 0x20) == 0;
                    M2C_FIELD(temp_s1, int*, 0x20) = temp_v0;
                    if (temp_v0 == 0) {
                        M2C_FIELD(temp_s1, int*, 0x1C) = func_8003636C(0x78, 0xB4);
                        if (arg0->animationState.nextId != 0) {
                            call4 = arg0;
                            MATCHING_KEEP(call4);
                            ControllerBA74D6C770 = 0;
                            temp_v0_2 = arg0->animationState.nextId;
                            var_a1 = arg0->animationState.nextFrame;
                            arg0->animationProgress = 0x72;
                            arg0->animationState.nextId = 0;
                            arg0->animationState.nextFrame = 0;
                            arg0->animationState.id = temp_v0_2;
                            goto block_23;
                        }
                    } else {
                        M2C_FIELD(temp_s1, int*, 0x1C) = func_8003636C(0xB4, 0xF0);
                        if (arg0->animationState.nextId != 1) {
                            call4 = arg0;
                            MATCHING_KEEP(call4);
                            ControllerBA74D6C770 = 0;
                            temp_v1 = arg0->animationState.nextId;
                            MATCHING_KEEP_CLOBBER(temp_v1, "memory");
                            var_a1 = arg0->animationState.nextFrame;
                            arg0->animationProgress = 0x72;
                            arg0->animationState.nextId = 1;
                            arg0->animationState.nextFrame = 0;
                            arg0->animationState.id = temp_v1;
                        block_23:
                            arg0->animationState.frame = var_a1;
                            func_80035734(call4);
                        }
                    }
                }
                if (M2C_FIELD(temp_s1, int*, 0x20) == 0) {
                    if (arg0->animationState.nextId != 0) {
                        ControllerBA74D6C770 = 0;
                        arg0->animationProgress = 0x72;
                        arg0->animationState.nextId = 0;
                        arg0->animationState.nextFrame = 0;
                        func_80035734(arg0);
                        var_a0 = temp_s1 + 0x24;
                    } else {
                        goto block_31;
                    }
                } else {
                    if (arg0->animationState.nextId != 1) {
                        ControllerBA74D6C770 = 0;
                        arg0->animationProgress = 0x72;
                        arg0->animationState.nextId = 1;
                        arg0->animationState.nextFrame = 0;
                        func_80035734(arg0);
                    }
                    if (ControllerBA74UpdateMobyPathMotion(arg0, M2C_FIELD(temp_s1, void**, 0x18),
                                                           0x200, 0x3C, 0x12C, 3, 0x80, 0x23) &
                        1) {
                        temp_v0 = func_8003636C(
                            1, M2C_FIELD(M2C_FIELD(temp_s1, void**, 0x18), short*, 0) - 2);
                        temp_a1 = M2C_FIELD(temp_s1, void**, 0x18);
                        temp_a0 = M2C_FIELD(temp_a1, short*, 0);
                        M2C_FIELD(temp_a1, short*, 2) =
                            (short)((int)(M2C_FIELD(temp_a1, short*, 2) + temp_v0 + temp_a0) %
                                    temp_a0);
                    }
                block_31:
                    var_a0 = temp_s1 + 0x24;
                }
                if ((func_800359A4(var_a0, 4) != 0) &&
                    (ControllerBA74ApproximatePlanarDistance((temp_s3 = &arg0->position),
                                                             &ControllerBA74D70328) < 0x1770) &&
                    (ControllerBA74D6E344 == 0) &&
                    ((func_8004F264(
                          (int)arg0->angle.yaw,
                          func_8004E880(
                              M2C_FIELD(&ControllerBA74D70328, int*, 0) - arg0->position.x,
                              M2C_FIELD(&ControllerBA74D70328, int*, 4) - arg0->position.y, 0)) <
                      0x26) ||
                     (ControllerBA74ApproximatePlanarDistance(temp_s3, &ControllerBA74D70328) <
                      0x7D0)) &&
                    (func_8004F264((int)(ControllerBA74D6E040 << 0x10) >> 0x14,
                                   func_8004E880(arg0->position.x - ControllerBA74D6E020,
                                                 arg0->position.y - ControllerBA74D6E024, 0)) <
                     0x1C)) {
                    M2C_FIELD(temp_s1, int*, 0x24) = 0xB4;
                    arg0->state = 1;
                    func_80034F40(arg0, 1);
                    return;
                }
                return;
            case 1:
                func_8003573C(arg0, 6, 0, 0);
                temp_v0_3 = M2C_FIELD(temp_s1, void**, 0x18);
                if ((ControllerBA74ApproximatePlanarDistance(
                         &arg0->position, M2C_FIELD(temp_v0_3, int*, 0xC) +
                                              (M2C_FIELD(temp_v0_3, short*, 2) * 0x10)) < 0x1F41) &&
                    (ControllerBA74D6E344 == 0)) {
                    if (M2C_FIELD(&ControllerBA74D70328, int*, 0xB8) == 0) {
                        height3 = arg0->distanceToGround;
                        z2 = arg0->position.z;
                        temp_v1_2 = z2 - height3;
                        player4 = M2C_FIELD(&ControllerBA74D70328, int*, 8);
                        temp_v0_4 = temp_v1_2 - player4;
                        if (temp_v0_4 >= 0)
                            var_v0 = temp_v0_4 < 0x1F5;
                        else
                            var_v0 = (player4 - temp_v1_2) < 0x1F5;
                        if (var_v0 != 0) {
                            goto block_45;
                        }
                        goto block_46;
                    }
                block_45:
                    if (func_80035DDC(arg0, 0x50, 0x15E, 0x15E, 0x23) != 0) {
                    block_46:
                        goto block_47;
                    }
                } else {
                block_47:
                    M2C_FIELD(temp_s1, int*, 0x20) = 1;
                    M2C_FIELD(temp_s1, int*, 0x1C) = 0xB4;
                    if (arg0->animationState.nextId != 1) {
                        ControllerBA74D6C770 = 0;
                        arg0->animationProgress = 0x72;
                        arg0->animationState.nextId = 1;
                        arg0->animationState.nextFrame = 0;
                        func_80035734(arg0);
                    }
                    arg0->state = 0;
                }
                if (ControllerBA74ApproximatePlanarDistance(&arg0->position,
                                                            &ControllerBA74D70328) < 0x3E8) {
                    arg0->state = 2;
                    func_80034F40(arg0, 2);
                    return;
                }
                break;
            case 2:
                func_8003573C(arg0, 8, 0, 0);
                ControllerBA74RefreshMobySpatialGridAndBasis(arg0, 5);
                if (M2C_FIELD(&ControllerBA74D70328, int*, 0xB8) == 0) {
                    temp_v1_3 = arg0->position.z - arg0->distanceToGround;
                    temp_v0_5 = temp_v1_3 - M2C_FIELD(&ControllerBA74D70328, int*, 8);
                    if (temp_v0_5 >= 0) {
                        if (temp_v0_5 < 0x1F5) {

                        } else {
                            goto block_57;
                        }
                    } else if ((M2C_FIELD(&ControllerBA74D70328, int*, 8) - temp_v1_3) >= 0x1F5) {
                    block_57:
                        M2C_FIELD(temp_s1, int*, 0x20) = 1;
                        M2C_FIELD(temp_s1, int*, 0x1C) = 0xB4;
                        if (arg0->animationState.nextId != 1) {
                            ControllerBA74D6C770 = 0;
                            arg0->animationProgress = 0x72;
                            arg0->animationState.nextId = 1;
                            arg0->animationState.nextFrame = 0;
                            func_80035734(arg0);
                        }
                        arg0->state = 0;
                    }
                }
                if (ControllerBA74D6C770 != 0) {
                    M2C_FIELD(temp_s1, int*, 0x20) = 1;
                    M2C_FIELD(temp_s1, int*, 0x1C) = 0xB4;
                    if (arg0->animationState.nextId != 1) {
                        ControllerBA74D6C770 = 0;
                        arg0->animationProgress = 0x72;
                        arg0->animationState.nextId = 1;
                        arg0->animationState.nextFrame = 0;
                        func_80035734(arg0);
                    }
                    arg0->state = 0;
                    return;
                }
                break;
            case 3:
                func_80035194(arg0, temp_s1);
                ControllerBA74RefreshMobySpatialGridAndBasis(arg0, 1);
                if (ControllerBA74D6C770 != 0) {
                    if (M2C_FIELD(temp_s1, int*, 0x2C) == 1) {
                        ControllerBA74RefreshMobySpatialGridAndBasis(arg0, 4);
                        func_800369B8(arg0, 0x20);
                        arg0->unknownCollision = 0;
                        arg0->unknown3[0] = 0;
                        arg0->lowDrawDistance = 0;
                        arg0->drawn = 0;
                        arg0->state = 0x14;
                        arg0->substate = 0;
                        return;
                    }
                    ControllerBA74RefreshMobySpatialGridAndBasis(arg0, 4);
                    func_8003BA00(arg0);
                    func_800369B8(arg0, 0x40);
                    ControllerBA74DeleteMoby(arg0);
                }
                break;
        }
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"
#define ControllerC15CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char ControllerC15CPlayer[] __asm__("D_80070328");
extern int D_8006C3F4, D_8006C4F8, D_8006C598, D_8006C640, D_8006C648, D_8006C6D0, D_8006C6E0,
    D_8006E344;
extern unsigned char D_8007157D;
extern unsigned char ControllerC15CData0[] __asm__("D_800652B0");
extern unsigned char ControllerC15CData4[] __asm__("D_800652B4");
extern unsigned char ControllerC15CData6[] __asm__("D_800652B6");
extern unsigned char ControllerC15CControl0[] __asm__("D_8006D088");
extern unsigned char ControllerC15CControl1[] __asm__("D_8006C7F8");
extern Vector3D ControllerC15CVector __asm__("D_800719BC");
extern int ControllerC15CVectorY __asm__("D_800719C0");
extern int ControllerC15CVectorZ __asm__("D_800719C4");
extern unsigned char ControllerC15CCamera0[] __asm__("D_800719A8");
extern unsigned char ControllerC15CCamera1[] __asm__("D_800719F0");
extern unsigned char ControllerC15CCameraSource0[] __asm__("D_80068F7C");
extern unsigned char ControllerC15CCameraSource1[] __asm__("D_80068F90");
extern void (*ControllerC15CHeader)(Moby*, int) __asm__("unk_ovlheader_80074318");
int ControllerC15CRestoreOrClearTrackedSnapshot(void*) __asm__("func_8003B74C");
int ControllerC15CRegisterTrackedValue(unsigned char*, int, void*) __asm__("func_8003B7B4");
int ControllerC15CStartDialogue(Moby*, int, int) __asm__("func_800512E4");
int ControllerC15CCopyCameraPositionWithWrappedAngle(void*, void*, int) __asm__("func_800135A4");
int ControllerC15CConfigurePrimaryRangeRequest(int, int, int) __asm__("func_8004F984");
extern unsigned char ControllerC15CFlag __asm__("D_8006C7B4");
extern unsigned char ControllerC15CTable[] __asm__("D_80070300");
extern int ControllerC15CIndex __asm__("D_8006C58C");
extern unsigned char* ControllerC15CRecords __asm__("D_8006C550");
int ControllerC15CPreparePortalLevelTransition(int) __asm__("func_80053F50");
int ControllerC15CWriteTrackedSnapshot(void*, void*, int) __asm__("func_8003B634");
/* AI-generated; not human reviewed. Verified level23 C baseline adapted to
 * complete original SCUS-94467 Rev0 level16/8007C15C instructions.
 * Raw tag bytes2/4/5 and words44/48/50 retain original widths; record stride88.
 * Helper meanings, raw units and caller cadence remain unresolved. */
void func_level_16_8007C15C(Moby* moby) {
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
    if ((D_8006C640 > 0) && (ControllerC15CField(tag, int*, 0x50) == 0)) {
        dataStart = D_8006C3F4 + ControllerC15CField(&ControllerC15CData0, int*, 0x40);
        ControllerC15CConfigurePrimaryRangeRequest(
            dataStart, dataStart + ControllerC15CField(&ControllerC15CData4, unsigned short*, 0x40),
            (int)ControllerC15CField(&ControllerC15CData6, unsigned short*, 0x40));
        ControllerC15CField(tag, int*, 0x50) = 1;
    }
    state = owner->state;
    switch (state) { /* irregular */
        case 0:
            if (ControllerC15CField(tag, unsigned char*, 2) == 0 && D_8007157D != 0) {
                ControllerC15CField(tag, unsigned char*, 2) = 4;
            } else if (ControllerC15CField(tag, unsigned char*, 2) == 1 &&
                       (ControllerC15CFlag & 1) == 0 &&
                       (ControllerC15CTable[ControllerC15CIndex] & 1) == 0) {
                ControllerC15CField(tag, unsigned char*, 2) = 5;
            }
            owner->distanceToGround = 0;
            ControllerC15CField(tag, signed char*, 5) = 1;
            if (D_8006C598 == 0 && func_80037BBC(owner, 0) != 0) {
                D_8007157D = 1;
                ControllerC15CStartDialogue(owner, 0, 15);
                owner->state = 15;
            }
            break;
        case 15:
            if (D_8006E344 != 1) {
                ControllerC15CField(ControllerC15CPlayer, int*, 0x20C) = 0x10000002;
                if (ControllerC15CField(tag, unsigned char*, 4) == 2) {
                    ControllerC15CPreparePortalLevelTransition(-1);
                    break;
                }
                ControllerC15CWriteTrackedSnapshot(
                    ControllerC15CControl0,
                    ControllerC15CRecords + ControllerC15CField(tag, int*, 0x44) * 88 + 12,
                    ControllerC15CField(ControllerC15CRecords +
                                            ControllerC15CField(tag, int*, 0x44) * 88,
                                        unsigned char*, 0x46));
                ControllerC15CField(tag, int*, 0x48) = 60;
                owner->state = 1;
                func_80034F40(owner, 1);
            }
            break;
        case 1:
            ControllerC15CField(ControllerC15CPlayer, int*, 0x20C) = 0x10000002;
            if (func_8003585C(owner, ControllerC15CField(tag, int*, 0x34) + 0x80, 8, 0x10, 1, 0) !=
                0) {
                func_80035DDC(owner, 0x80, 0, 0, 0);
            }
            value = func_800359A4((unsigned char*)tag + 0x48, 4);
            statePointer1 = &owner->state;
            if (value == 2) {
                owner->state = 3;
                ControllerC15CRegisterTrackedValue(statePointer1, 1, &ControllerC15CControl0);
                ControllerC15CRegisterTrackedValue(statePointer1, 1, &ControllerC15CControl1);
                ControllerC15CRestoreOrClearTrackedSnapshot(&ControllerC15CControl0);
                owner->state = 1;
            }
            break;
        case 3:
            ControllerC15CHeader(owner, 0x41);
            D_8006C6D0 = 0;
            ControllerC15CCopyCameraPositionWithWrappedAngle(&ControllerC15CCamera0,
                                                             &ControllerC15CCameraSource0, 0);
            ControllerC15CCopyCameraPositionWithWrappedAngle(&ControllerC15CCamera1,
                                                             &ControllerC15CCameraSource1, 0);
            if (ControllerC15CField(ControllerC15CPlayer, int*, 0x24C) == 1) {
                animationOffset = ControllerC15CField(ControllerC15CPlayer, int*, 0x48) - 0x41;
                if (animationOffset != owner->animationState.nextId) {
                    func_80034F40(owner, animationOffset);
                }
            }
            if (ControllerC15CField(ControllerC15CPlayer, int*, 0x50) == 10) {
                *(unsigned int*)&owner->colour =
                    -ControllerC15CField(ControllerC15CPlayer, int*, 0xF4) & 0xFFFFFF;
                owner->colour.a = 0x80;
            } else {
                *(unsigned int*)&owner->colour = 0;
            }
            if ((unsigned int)(ControllerC15CField(ControllerC15CPlayer, int*, 0x50) - 2) >= 2U) {
                value = ControllerC15CField(tag, int*, 0x48) + D_8006C648;
                ControllerC15CField(tag, int*, 0x48) = value;
                if (value >= 0x1771) {
                    ControllerC15CField(tag, int*, 0x48) = 0x1770;
                }
            }
            break;
    }
    func_80035D38(owner);
    func_8005629C(owner);
}
#undef ControllerC15CField

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
void func_level_16_8007C554(Moby* moby) {
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

typedef struct {
    unsigned char reserved00[0x34];
    int angle;
    Vector3D point;
} DecodedCheckpointPositionTag;
extern short D_800658A0[], D_80065920[];
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
void func_level_16_8007C960(Moby* moby) {
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
void func_level_16_8007CA90(Moby* moby) {
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
void func_level_16_8007CDC0(Moby* actor) {
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

#define Controller7CFCCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Controller7CFCCD_800658A0[] __asm__("D_800658A0");
extern short Controller7CFCCD_80065920[] __asm__("D_80065920");
extern int Controller7CFCCD_8006C574 __asm__("D_8006C574");
extern int Controller7CFCCD_8006C578 __asm__("D_8006C578");
extern int Controller7CFCCD_80071918 __asm__("D_80071918");
extern int Controller7CFCCD_8007191C __asm__("D_8007191C");
extern int Controller7CFCCD_80071920 __asm__("D_80071920");
extern void* (*Controller7CFCCSpawnMoby)(int, void*)__asm__("SpawnMoby");
int Controller7CFCCQueryWorldSphereWithOptions(void*, int, int, int, int,
                                               int) __asm__("func_80019138");
int Controller7CFCCCountTimerDown(void*, int) __asm__("func_800359A4");
int Controller7CFCCEmitMobyVertexParticles(void*, int) __asm__("func_800369B8");
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
void func_level_16_8007CFCC(void* input) {
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
    tag = ((Moby*)owner)->mobyTag;
    MATCHING_KEEP(owner);
    queryThreshold = 0x100;
    if (Controller7CFCCField(tag, short*, 0x12) == 1) {
        queryThreshold = 0x80;
    }
    if (Controller7CFCCQueryWorldSphereWithOptions(owner + 0xC, queryThreshold, 1, 0, 0, 0) != 0) {
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
        Controller7CFCCEmitMobyVertexParticles(preparedArgument, 0x28);
        Controller7CFCCDeleteMoby(owner);
        return;
    }
    ((Moby*)owner)->position.x =
        (int)(((Moby*)owner)->position.x + Controller7CFCCField(tag, short*, 0));
    ((Moby*)owner)->position.y =
        (int)(((Moby*)owner)->position.y + Controller7CFCCField(tag, short*, 2));
    decrementedZ = (unsigned short)Controller7CFCCField(tag, short*, 4) - 0xA;
    Controller7CFCCField(tag, short*, 4) = decrementedZ;
    if (decrementedZ < -0xC8) {
        Controller7CFCCField(tag, short*, 4) = -0xC8;
    }
    ((Moby*)owner)->position.z =
        (int)(((Moby*)owner)->position.z + Controller7CFCCField(tag, short*, 4));
    ((Moby*)owner)->angle.roll =
        (unsigned char)(((Moby*)owner)->angle.roll + Controller7CFCCField(tag, unsigned char*, 6));
    ((Moby*)owner)->angle.pitch =
        (unsigned char)(((Moby*)owner)->angle.pitch + Controller7CFCCField(tag, unsigned char*, 8));
    ((Moby*)owner)->angle.yaw =
        (unsigned char)(((Moby*)owner)->angle.yaw + Controller7CFCCField(tag, unsigned char*, 0xA));
}

#undef Controller7CFCCField

extern unsigned char* D_8006C54C;
extern unsigned char D_level_16_800866F8;
extern unsigned char D_80070300[];
extern int D_8006C774;
void func_level_16_8007D4AC(void) {
    if (D_8006C54C - 1 == &D_level_16_800866F8 && D_8006C774) {
        unsigned char* flags = &D_80070300[1];
        if (*flags & 1)
            *flags ^= 1;
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
void func_level_16_8007D504(void* input) {
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


extern void func_80039714(Moby*);

/**
 * MobyUpdate_501() - func_level_16_8007E658()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_16_8007E658(Moby* moby) {
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
void func_level_16_8007E678(Moby* mobyArgument) {
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

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007E878..8007EBDC. Original damage word is owner+24; no new
 * interpretation of factory results, global producers or cadence. */
extern unsigned char DecodedSpooky110Player[] __asm__("D_80070328");
extern int D_8006C578, D_8006C574, D_8006C7C4;
extern int D_8006E020, D_8006E024, D_8006E1D8, D_8006E1D4;
extern unsigned short DecodedSpooky110Angle __asm__("D_8006E040");
void DecodedSheila110Extra(Moby*, int, int, int) __asm__("func_80036A68");
void func_level_16_8007E878(Moby* mobyArgument) {
    register Moby* moby __asm__("$17") = mobyArgument;
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
        DecodedSheila110Extra(moby, 0, 0, 0);
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

