#include "matching.h"
#include "common.h"
#include "camera.h"
#include "savepoint.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "mobyutil.h"
#include "ovl_header.h"
#include "spyro.h"
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
void func_level_28_80074A0C(void* input) {
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
void func_level_28_80075668(Moby* mobyArgument) {
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
void func_level_28_80075CF4(void* input) {
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
void func_level_28_80077244(Moby* moby) {
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
void func_level_28_80077380(Moby* moby) {
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
void func_level_28_8007743C(Moby* moby) {
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
void func_level_28_800774F0(Moby* moby) {
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
void func_level_28_800777F4(void* input) {
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
void func_level_28_80078368(void* input) {
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

void func_level_28_800794BC(Moby* moby) {
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
void func_level_28_800794DC(Moby* mobyArgument) {
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

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 406 instructions per copy are the acceptance authority.
 * Preserve byte and signed-halfword accesses, original 0x78-byte frame,
 * table shifts, helper registers, bottom-tested actor loop and fallthroughs.
 * Empty constraints emit no instructions; separate aliases preserve original
 * table address lifetimes. Units, table meanings, complete helper contracts
 * and caller cadence remain unresolved. No runtime completeness claimed.
 * Falsifiable check: every original linked word and full binary hashes.
 */
#define Actor79724Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor79724QueryWorldSegment(void*, void*) __asm__("func_80018368");
void* Actor79724QueryDynamicMobyGeometry(void*, int, int, int, int, void*) __asm__("func_8001BA30");
int Actor79724CountTimerDown(void*, int) __asm__("func_800359A4");
int Actor79724BlendBoundedAngle8Step(int, int, int, int) __asm__("func_800360F8");
int Actor79724PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Actor79724TransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Actor79724SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Actor79724PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Actor79724ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Actor79724CopyVector(void*, void*) __asm__("func_8004F178");
int Actor79724AddVector(void*, void*, void*) __asm__("func_8004F194");
int Actor79724SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Actor79724ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Actor79724DeleteMoby(void*) __asm__("func_80055B18");
int Actor79724rand(void) __asm__("rand");
extern short Actor79724D_80065920[] __asm__("D_80065920");
extern short Actor79724D_800658A0[] __asm__("D_800658A0");
extern short Actor79724Late65920[] __asm__("D_80065920");
extern short Actor79724Late658A0[] __asm__("D_800658A0");
extern short Actor79724Loop658A0[] __asm__("D_800658A0");
extern int Actor79724D_8006C574 __asm__("D_8006C574");
extern int Actor79724D_8006C578 __asm__("D_8006C578");
extern void* Actor79724D_8006E788[] __asm__("D_8006E788");
extern void* (*Actor79724SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int (*Actor79724SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");
void func_level_28_800796DC(void* input) {
    register unsigned char* owner __asm__("$19") = input;
    struct {
        int sp18, sp1C, sp20, pad24;
        int sp28, sp2C, sp30, pad34;
        int sp38, sp3C, sp40, pad44;
        int pad48, pad4C, pad50, pad54;
    } frame;
    register short* particleTable __asm__("$18");
    register int* ownerPosition __asm__("$16");
    register int* particlePosition __asm__("$20");
    int positionZ;
    int positionY;
    int positionX;
    register int randomByteOffset __asm__("$2");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    register void* call7 __asm__("$7");
    register short* raw3 __asm__("$3");
    register short* raw2 __asm__("$2");
    register int (*particle3)(int, int, void*, void*) __asm__("$3");
    register short* table18 __asm__("$18");
    register short* table20 __asm__("$20");
    register int* vector22 __asm__("$22");
    register int candidateScore __asm__("$3");
    register int angleDifference __asm__("$16");
    register int particleIndex __asm__("$16");
    register int particleSelector __asm__("$17");
    register int minimumScore __asm__("$22");
    register int spawnCount __asm__("$22");
    int var_v0;
    int var_v0_2;
    register int distanceDifference __asm__("$3");
    register int signedAngleDifference __asm__("$3");
    register int helperAngle __asm__("$16");
    register int currentAngle __asm__("$4");
    unsigned char stateByte;
    register int updatedAngle __asm__("$2");
    register void** candidateCursor __asm__("$18");
    register void** spawnCursor __asm__("$20");
    void* selectedActor;
    register void* spawnedState __asm__("$16");
    register void* spawnCandidate __asm__("$18");
    register void* state __asm__("$21");
    register void* hitActor __asm__("$17");
    register void* spawnedActor __asm__("$17");
    register void* candidateActor __asm__("$17");
    positionX = ((Moby*)owner)->position.x;
    state = ((Moby*)owner)->mobyTag;
    if ((positionX >= 0x400) &&
        (positionY = ((Moby*)owner)->position.y, ((positionY < 0x400) == 0)) &&
        (positionZ = ((Moby*)owner)->position.z, ((positionZ < 0x400) == 0)) &&
        (positionX <= 0x3E800) && (positionY <= 0x3E800) && (positionZ <= 0x3E800) &&
        (((Moby*)owner)->drawn != 0)) {
        Actor79724CopyVector(&frame.sp18, owner + 0xC);
        stateByte = ((Moby*)owner)->state;
        switch (stateByte) { /* irregular */
            case 0:
                minimumScore = 0x1869F;
                Actor79724Field(state, void**, 4) = 0;
                candidateActor = Actor79724D_8006E788[0];
                candidateCursor = Actor79724D_8006E788 + 1;
                if (candidateActor != 0) {
                    do {
                        if (Actor79724Field(candidateActor, int*, 8) != 0) {
                            Actor79724CopyVector(&frame.sp38, candidateActor + 0xC);
                            angleDifference = (Actor79724PlanarHeadingLookup(
                                                   frame.sp38 - ((Moby*)owner)->position.x,
                                                   frame.sp3C - ((Moby*)owner)->position.y, 0) -
                                               ((Moby*)owner)->angle.yaw) &
                                              0xFF;
                            if (angleDifference >= 0x81) {
                                angleDifference -= 0x100;
                            }
                            if (angleDifference < 0) {
                                angleDifference = -angleDifference;
                            }
                            MATCHING_KEEP(angleDifference);
                            if (angleDifference < 6) {
                                distanceDifference = 0x1000 - Actor79724ApproximatePlanarDistance(
                                                                  owner + 0xC, &frame.sp38);
                                if (distanceDifference < 0) {
                                    distanceDifference = -distanceDifference;
                                }
                                MATCHING_KEEP(distanceDifference);
                                work2 = angleDifference << 5;
                                MATCHING_KEEP2(work2, distanceDifference);
                                candidateScore = distanceDifference + work2;
                                if (candidateScore < minimumScore) {
                                    Actor79724Field(state, void**, 4) = candidateActor;
                                    minimumScore = candidateScore;
                                }
                            }
                        }
                        candidateActor = *candidateCursor;
                        candidateCursor += 1;
                    } while (candidateActor != 0);
                }
                ((Moby*)owner)->state = 1U;
            /* fallthrough */
            case 1:
                if (Actor79724SoundHandleMatchesOwnerInStates1Or2(
                        owner, Actor79724Field(state, int*, 8)) == 0) {
                    Actor79724Field(state, int*, 8) = Actor79724PlayMobySoundEvent(owner, 1, 4);
                }
                if (Actor79724Field(Actor79724Field(state, void**, 4), unsigned char*, 0x48) &
                    0x80) {
                    Actor79724Field(state, void**, 4) = 0;
                }
                selectedActor = Actor79724Field(state, void**, 4);
                if (selectedActor != 0) {
                    Actor79724CopyVector(&frame.sp28, selectedActor + 0xC);
                    frame.sp20 += 0x80;
                    Actor79724SubtractVector(&frame.sp28, &frame.sp28, owner + 0xC);
                    frame.sp30 += 0x100;
                    Actor79724PlanarHeadingLookup(frame.sp28, frame.sp2C, 0);
                    work2 = Actor79724PlanarHeadingLookup(frame.sp28, frame.sp2C, 0);
                    currentAngle = ((Moby*)owner)->angle.yaw;
                    MATCHING_KEEP2(work2, currentAngle);
                    signedAngleDifference = (work2 - currentAngle) & 255;
                    if (signedAngleDifference >= 129)
                        signedAngleDifference -= 256;
                    work2 = signedAngleDifference < -3;
                    if (work2) {
                        signedAngleDifference = -3;
                        MATCHING_KEEP(signedAngleDifference);
                    }
                    work2 = signedAngleDifference < 4;
                    if (work2) {
                        updatedAngle = currentAngle + signedAngleDifference;
                    } else {
                        signedAngleDifference = 3;
                        MATCHING_KEEP(signedAngleDifference);
                        updatedAngle = currentAngle + signedAngleDifference;
                    }
                    ((Moby*)owner)->angle.yaw = updatedAngle;
                }
                ownerPosition = owner + 0xC;
                work2 = ((Moby*)owner)->angle.yaw;
                MATCHING_BARRIER_GNU_VOLATILE("$4");
                call4 = ownerPosition;
                MATCHING_KEEP2(work2, call4);
                work2 = Actor79724D_80065920[work2];
                MATCHING_BARRIER_GNU_VOLATILE("$5");
                call5 = ownerPosition;
                MATCHING_KEEP2(work2, call5);
                frame.sp28 = work2 >> 4;
                work2 = ((Moby*)owner)->angle.yaw;
                MATCHING_BARRIER_GNU_VOLATILE("$22");
                vector22 = &frame.sp28;
                MATCHING_KEEP2(work2, vector22);
                work2 = Actor79724D_800658A0[work2];
                MATCHING_BARRIER_GNU_VOLATILE("$6");
                call6 = vector22;
                MATCHING_KEEP2(work2, call6);
                frame.sp30 = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(work2, "memory");
                frame.sp2C = work2 >> 4;
                Actor79724AddVector(call4, call5, call6);
                ((Moby*)owner)->angle.roll = (unsigned char)(((Moby*)owner)->angle.roll + 4);
                work2 = (int)Actor79724QueryDynamicMobyGeometry(ownerPosition, 0x80, 1, 0, 0x110000,
                                                                owner);
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(work2, "memory");
                table18 = Actor79724Late65920;
                table20 = Actor79724Late658A0;
                MATCHING_KEEP3(table18, table20, work2);
                hitActor = (void*)work2;
                if (hitActor != 0) {
                    work2 = Actor79724PlanarHeadingLookup(
                        Actor79724Field(hitActor, int*, 12) - ((Moby*)owner)->position.x,
                        Actor79724Field(hitActor, int*, 16) - ((Moby*)owner)->position.y, 0);
                    call6 = 0;
                    call4 = (void*)frame.sp28;
                    call5 = (void*)frame.sp2C;
                    MATCHING_KEEP4(work2, call6, call4, call5);
                    helperAngle = work2;
                    work2 = Actor79724PlanarHeadingLookup((int)call4, (int)call5, (int)call6);
                    Actor79724Field(hitActor, signed char*, 0x51) =
                        Actor79724BlendBoundedAngle8Step(helperAngle, work2, 32, 64);
                    if (Actor79724Field(state, short*, 2) != 0) {
                        ((Moby*)owner)->state = 2U;
                        return;
                    }
                    goto block_46;
                }
                if (Actor79724CountTimerDown(state, 2) == 0) {
                    if (Actor79724QueryWorldSegment(&frame.sp18, ownerPosition) != 0) {
                        Actor79724CopyVector(ownerPosition, &frame.sp18);
                    block_46:
                        ((Moby*)owner)->state = 3U;
                        return;
                    }
                    work2 = Actor79724rand();
                    call4 = &frame.sp18;
                    MATCHING_KEEP2(call4, work2);
                    randomByteOffset = (work2 & 255) * 2;
                    raw3 = (short*)(randomByteOffset + (int)table18);
                    call5 = call4;
                    MATCHING_KEEP4(raw3, call5, call4, table18);
                    work3 = *raw3;
                    MATCHING_KEEP3(work3, randomByteOffset, table20);
                    raw2 = (short*)(randomByteOffset + (int)table20);
                    MATCHING_KEEP2(work3, raw2);
                    frame.sp18 = work3 >> 7;
                    work2 = *raw2;
                    MATCHING_BARRIER_GNU_VOLATILE("$6");
                    call6 = vector22;
                    MATCHING_KEEP2(work2, call6);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    frame.sp20 = 0;
                    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(work2, "memory");
                    frame.sp1C = work2 >> 7;
                    Actor79724AddVector(call4, call5, call6);
                    Actor79724ShiftVectorRightTowardZero(&frame.sp18, 2);
                    Actor79724SpawnParticle(1, 0x37, ownerPosition, &frame.sp18);
                    return;
                }
                goto block_62;
            case 2:
                spawnCursor = Actor79724D_8006E788;
                spawnCount = 0;
                goto nextActor;
            actorBody:
                if (spawnCount >= 4)
                    goto actorEnd;
                if ((Actor79724Field(spawnCandidate, int*, 8) != 0) &&
                    !(Actor79724Field(spawnCandidate, int*, 0x18) & 0x110000) &&
                    (Actor79724ApproximatePlanarDistance(owner + 0xC, spawnCandidate + 0xC) <
                     0x1000)) {
                    spawnedActor = Actor79724SpawnMoby(((Moby*)owner)->mobyClass, owner);
                    call6 = 0;
                    if (spawnedActor != 0) {
                        spawnCount++;
                        work3 = Actor79724Field(spawnCandidate, int*, 12);
                        call4 = (void*)((Moby*)owner)->position.x;
                        work2 = Actor79724Field(spawnCandidate, int*, 16);
                        call5 = (void*)((Moby*)owner)->position.y;
                        MATCHING_KEEP5(work3, call4, work2, call5, spawnedActor);
                        spawnedState = Actor79724Field(spawnedActor, void**, 0);
                        MATCHING_KEEP5(spawnedState, work3, call4, work2, call5);
                        call4 = (void*)(work3 - (int)call4);
                        call5 = (void*)(work2 - (int)call5);
                        Actor79724Field(spawnedActor, signed char*, 0x46) =
                            Actor79724PlanarHeadingLookup((int)call4, (int)call5, (int)call6);
                        Actor79724Field(spawnedState, void**, 4) = spawnCandidate;
                    }
                }
            nextActor:
                spawnCandidate = *spawnCursor;
                spawnCursor++;
                if (spawnCandidate != 0 && Actor79724D_8006C578 - Actor79724D_8006C574 >= 21)
                    goto actorBody;
            actorEnd:
                if (spawnCount == 0) {
                    case 3:
                        particleIndex = 0;
                        particleSelector = Actor79724rand() & 0xFF;
                        particlePosition = owner + 0xC;
                        raw3 = Actor79724D_80065920;
                        MATCHING_KEEP2(raw3, particleSelector);
                        work2 = particleSelector << 1;
                        particleTable = (short*)(work2 + (int)raw3);
                        do {
                            call4 = (void*)1;
                            call5 = (void*)55;
                            call6 = particlePosition;
                            MATCHING_KEEP4(call4, call5, call6, particleTable);
                            work2 = *particleTable;
                            particle3 = Actor79724SpawnParticle;
                            MATCHING_KEEP2(work2, particle3);
                            work2 >>= 7;
                            MATCHING_KEEP(work2);
                            frame.sp18 = work2;
                            work2 = particleSelector << 1;
                            MATCHING_KEEP(work2);
                            work2 = *(short*)((unsigned char*)Actor79724Loop658A0 + work2);
                            MATCHING_BARRIER_GNU_VOLATILE("$7");
                            call7 = &frame.sp18;
                            MATCHING_KEEP2(work2, call7);
                            frame.sp20 = 0;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(work2, "memory");
                            frame.sp1C = work2 >> 7;
                            particle3((int)call4, (int)call5, call6, call7);
                            if (particleIndex & 1) {
                                Actor79724ShiftVectorRightTowardZero(&frame.sp18, 1);
                                Actor79724SpawnParticle(1, 0x37, particlePosition, &frame.sp18);
                            }
                            particleTable += 0x20;
                            particleIndex += 1;
                            particleSelector += 0x20;
                        } while (particleIndex < 8);
                }
                goto block_62;
        }
    } else {
    block_62:
        if (Actor79724SoundHandleMatchesOwnerInStates1Or2(owner, Actor79724Field(state, int*, 8)) !=
            0) {
            if (Actor79724SoundHandleMatchesOwnerInStates1Or2(
                    owner, Actor79724Field(state, int*, 8)) != 0) {
                Actor79724TransitionSoundHandleTo3Or5(Actor79724Field(state, int*, 8));
            }
            Actor79724Field(state, int*, 8) = -1;
        }
        Actor79724DeleteMoby(owner);
    }
}
#undef Actor79724Field

/* Partial retail tag layout; meanings of the reserved words are unresolved. */
typedef struct {
    unsigned char reserved00[0x1C];
    int flags, reserved20, timer, reserved28, word2C;
} DecodedCritterAttachmentRecord;
extern short D_800658A0[];
void func_80055B18(Moby*);
void func_80055F14(Moby*, int, Vector3D*);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
void func_level_28_80079D34(Moby* moby) {
    Moby* first;
    Moby* current;
    Moby** slot;
    DecodedCritterAttachmentRecord* tag;
    Vector3D* position;
    /* Preserve both original loads through the upstream aliases. */
    first = g_Spyro.critterMobyPtr;
    slot = &spyro.critterMobyPtr;
    current = *slot;
    tag = first->mobyTag;
    if (current) {
        if (!(tag->flags & 1) || tag->timer <= 0 || !moby->drawn) {
            func_80055B18(moby);
            tag->word2C = 0;
            return;
        }
        position = &moby->position;
        func_80055F14(current, 0, position);
        func_8001BA30(position, 0x400, 1, 0, 0x80000, *slot);
        if (tag->timer < 0xB4) {
            register int delta __asm__("$3") = tag->timer - 0xB4;
            register int shifted __asm__("$2");
            register int index __asm__("$3");
            register int byteOffset __asm__("$2");
            int wave, strength;
            /* Empty constraints preserve retail register allocation and shifts. */
            MATCHING_KEEP(delta);
            shifted = delta * 8;
            MATCHING_KEEP(shifted);
            index = shifted & 0xFF;
            MATCHING_KEEP(index);
            byteOffset = index * 2;
            MATCHING_KEEP(byteOffset);
            wave = *(short*)((char*)D_800658A0 + byteOffset);
            if (wave < 0)
                wave = -wave;
            MATCHING_KEEP(wave);
            strength = wave >> 8;
            if (strength >= 0x10)
                strength = 0xF;
            *(int*)&moby->colour = 0;
            moby->colour.a = strength | 0x30;
        }
    }
}

#define Controller79EA8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Controller79EA8D_800658A0 __asm__("D_800658A0");
extern short Controller79EA8D_80065920[] __asm__("D_80065920");
extern int Controller79EA8D_8006C574 __asm__("D_8006C574");
extern int Controller79EA8D_8006C578 __asm__("D_8006C578");
extern void* Controller79EA8D_8006E788 __asm__("D_8006E788");
int Controller79EA8QueryWorldSegmentWithOptions(void*, void*, int, int,
                                                void*) __asm__("func_8001830C");
int Controller79EA8QueryWorldSegment(void*, void*) __asm__("func_80018368");
void* Controller79EA8QueryDynamicMobyGeometry(void*, int, int, int, int,
                                              void*) __asm__("func_8001BA30");
int Controller79EA8CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller79EA8PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller79EA8PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller79EA8TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Controller79EA8ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Controller79EA8CopyVector(void*, void*) __asm__("func_8004F178");
int Controller79EA8AddVector(void*, void*, void*) __asm__("func_8004F194");
int Controller79EA8SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Controller79EA8AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller79EA8ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Controller79EA8ClearHistorySourceWord(void*) __asm__("func_800509E8");
int Controller79EA8DeleteMoby(void*) __asm__("func_80055B18");
int Controller79EA8RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
extern void* (*Controller79EA8SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int (*Controller79EA8SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level18/80079EA8, level28/80079E60, level38/80079E64 and
 * level48/80079E88; each has 365 equal original instructions and exact
 * helper/global symbols, without owned table rows. Local vectors retain
 * offsets 0x18/0x28/0x38/0x48/0x58/0x68 and target pointers stride 4.
 * Preserve target-score early exit, signed heading differences/clamps,
 * duplicate angle helper calls, original trace masks and pointer rereads,
 * eight particle iterations and signed table shifts by 7.
 * Helper semantics, coordinate units and caller cadence remain unresolved;
 * updates occur once per invocation. Confidence: exact compiled/linked
 * original words and complete retail hashes, not semantic runtime review.
 * Falsifiable vectors: all 1,460 original words and EXE/all-overlay SHA set.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_28_80079E60(void* input) {
    struct {
        Vector3D a;
        int pad24;
        Vector3D b;
        int pad34;
        Vector3D c;
        int pad44;
        Vector3D d;
        int pad54;
        Vector3D e;
        int pad64;
        Vector3D f;
        int pad74;
    } frame;
    register unsigned char* owner __asm__("$19") = input;
    register short* cosineEntry __asm__("$18");
    register int* currentPosition __asm__("$17");
    register int* probePosition __asm__("$17");
    register int* updatedPosition __asm__("$18");
    register int targetScore __asm__("$3");
    register int absoluteTurn __asm__("$16");
    register int particleIndex __asm__("$16");
    register int stepValue __asm__("$17");
    register int particleAngle __asm__("$17");
    register int bestScore __asm__("$20");
    register int absoluteDelta __asm__("$2");
    register int distanceDelta __asm__("$3");
    register int turnDelta __asm__("$3");
    register int previousHeading __asm__("$4");
    unsigned char state;
    register int nextHeading __asm__("$2");
    register void** targetCursor __asm__("$18");
    void* cleanupHandle;
    void* finalHandle;
    void* selectedTarget;
    register void* candidateTarget __asm__("$17");
    register void* particlePosition __asm__("$21");
    register void* particleVector __asm__("$20");
    register void* tag __asm__("$22");
    register void* firstHit __asm__("$17");
    register void* secondHit __asm__("$16");
    register void* spawnedChild __asm__("$16");

    tag = ((Moby*)owner)->mobyTag;
    if (((Moby*)owner)->drawn == 0) {
        cleanupHandle = Controller79EA8Field(tag, void**, 8);
        if (cleanupHandle != 0) {
            Controller79EA8ClearHistorySourceWord(cleanupHandle);
        }
        goto removeOwner;
    }
    state = ((Moby*)owner)->state;
    switch (state) { /* irregular */
        case 0:
            bestScore = 0x1869F;
            targetCursor = &Controller79EA8D_8006E788;
            Controller79EA8Field(tag, void**, 4) = 0;
            goto nextTarget;
        evaluateTarget:
            {
                if (Controller79EA8Field(candidateTarget, int*, 8) != 0) {
                    Controller79EA8CopyVector(&frame.a.x, candidateTarget + 0xC);
                    absoluteTurn = (Controller79EA8PlanarHeadingLookup(
                                        frame.a.x - ((Moby*)owner)->position.x,
                                        frame.a.y - ((Moby*)owner)->position.y, 0) -
                                    ((Moby*)owner)->angle.yaw) &
                                   0xFF;
                    if (absoluteTurn >= 0x81) {
                        absoluteTurn -= 0x100;
                    }
                    if (absoluteTurn < 0) {
                        absoluteTurn = -absoluteTurn;
                    }
                    MATCHING_BARRIER_VOLATILE("$4");
                    distanceDelta =
                        0x1000 - Controller79EA8ApproximatePlanarDistance(owner + 0xC, &frame.a.x);
                    if (distanceDelta < 0) {
                        distanceDelta = -distanceDelta;
                    }
                    MATCHING_KEEP_CLOBBER(distanceDelta, "$2");
                    {
                        register int shifted __asm__("$2") = absoluteTurn << 8;
                        MATCHING_KEEP(shifted);
                        targetScore = distanceDelta + shifted;
                    }
                    if (targetScore < bestScore) {
                        Controller79EA8Field(tag, void**, 4) = candidateTarget;
                        if (targetScore < 0x801)
                            goto targetSelected;
                        {
                            bestScore = targetScore;
                            goto nextTarget;
                        }
                    } else {
                        goto nextTarget;
                    }
                } else {
                    goto nextTarget;
                }
            }
        nextTarget:
            candidateTarget = *targetCursor;
            targetCursor += 1;
            if (candidateTarget != 0)
                goto evaluateTarget;
        targetSelected:
            MATCHING_KEEP(candidateTarget);
            if (bestScore == 0x1869F) {
                Controller79EA8Field(tag, void**, 4) = 0;
            }
            ((Moby*)owner)->state = 1U;
            /* fallthrough */
        case 1:
            if ((((Moby*)owner)->position.x < 0x400) || (((Moby*)owner)->position.y < 0x400) ||
                (((Moby*)owner)->position.z < 0x400) ||
                (Controller79EA8CountTimerDown(tag, 4) != 0)) {
                ((Moby*)owner)->state = 2U;
                return;
            }
            {
                register void* prepared __asm__("$4") = &frame.b.x;
                MATCHING_KEEP(prepared);
                currentPosition = owner + 0xC;
                Controller79EA8CopyVector(prepared, currentPosition);
            }
            if (Controller79EA8Field(Controller79EA8Field(tag, void**, 4), unsigned char*, 0x48) &
                0x80) {
                Controller79EA8Field(tag, void**, 4) = 0;
            }
            selectedTarget = Controller79EA8Field(tag, void**, 4);
            if (selectedTarget != 0) {
                Controller79EA8CopyVector(&frame.d.x, selectedTarget + 0xC);
                frame.d.z += 0x80;
                Controller79EA8SubtractVector(&frame.c.x, &frame.d.x, currentPosition);
                frame.c.z += 0x100;
                Controller79EA8PlanarHeadingLookup(frame.c.x, frame.c.y, 0);
                {
                    register int angle __asm__("$2") =
                        Controller79EA8PlanarHeadingLookup(frame.c.x, frame.c.y, 0);
                    previousHeading = ((Moby*)owner)->angle.yaw;
                    turnDelta = (angle - previousHeading) & 255;
                }
                if (turnDelta >= 0x81) {
                    turnDelta -= 0x100;
                }
                absoluteDelta = turnDelta;
                if (turnDelta < 0) {
                    absoluteDelta = -absoluteDelta;
                }
                stepValue = 0x80;
                if (absoluteDelta < 0x30) {
                    stepValue = 0xFA;
                }
                if (turnDelta < -4) {
                    turnDelta = -4;
                    MATCHING_KEEP(turnDelta);
                }
                if (turnDelta >= 5) {
                    turnDelta = 4;
                    MATCHING_KEEP(turnDelta);
                }
                nextHeading = previousHeading + turnDelta;
                ((Moby*)owner)->angle.yaw = nextHeading;
            } else {
                stepValue = 0xFA;
                ((Moby*)owner)->state = 0U;
            }
            Controller79EA8RefreshMobySpatialGridAndBasis(owner, 4);
            frame.c.x = stepValue;
            frame.c.y = 0;
            frame.c.z = 0;
            Controller79EA8TransformVectorByBasis(owner + 0x20, &frame.c.x, &frame.c.x);
            updatedPosition = owner + 0xC;
            Controller79EA8AddVector(updatedPosition, updatedPosition, &frame.c.x);
            if (Controller79EA8QueryWorldSegmentWithOptions(&frame.b.x, updatedPosition, 0,
                                                            0x110000, owner) != 0) {
                Controller79EA8CopyVector(updatedPosition, &frame.b.x);
                goto enterStateTwo;
            }
            firstHit =
                Controller79EA8QueryDynamicMobyGeometry(updatedPosition, 0x200, 1, 0, 0, owner);
            if (firstHit != 0) {
                Controller79EA8CopyVector(&frame.e.x, firstHit + 0xC);
                frame.e.z += 0x80;
                if (Controller79EA8QueryWorldSegment(updatedPosition, &frame.e.x) == 0) {
                    Controller79EA8Field(firstHit, int*, 0x18) =
                        (int)(Controller79EA8Field(firstHit, int*, 0x18) | 0x110000);
                enterStateTwo:
                    ((Moby*)owner)->state = 2U;
                }
            }
            if (Controller79EA8Field(tag, void**, 8) != 0) {
                if ((Controller79EA8AbsoluteByteAngleDelta(((Moby*)owner)->angle.yaw, 0) < 0x20) ||
                    (Controller79EA8AbsoluteByteAngleDelta(((Moby*)owner)->angle.yaw, 0x80) <
                     0x20)) {
                    Controller79EA8Field(Controller79EA8Field(tag, void**, 8), unsigned char*,
                                         0x66) = 0xF4;
                    return;
                }
                Controller79EA8Field(Controller79EA8Field(tag, void**, 8), signed char*, 0x66) = 7;
                return;
            }
            return;
        case 2:
            particleIndex = 0;
            particleAngle = rand() & 0xFF;
            particlePosition = owner + 0xC;
            particleVector = &frame.f.x;
            MATCHING_KEEP(particleVector);
            MATCHING_KEEP2(particleVector, particlePosition);
            {
                register short* base __asm__("$3") = Controller79EA8D_80065920;
                register int offset __asm__("$2");
                MATCHING_KEEP(base);
                offset = particleAngle * 2;
                cosineEntry = (short*)(offset + (int)base);
            }
            do {
                register int type __asm__("$4") = 1;
                register int selector __asm__("$5") = 0x37;
                register void* position __asm__("$6") = particlePosition;
                register int sample __asm__("$2");
                register void* vectorArgument __asm__("$7");
                register int (*emit)(int, int, void*, void*) __asm__("$3");
                MATCHING_KEEP3(type, selector, position);
                sample = *cosineEntry;
                emit = Controller79EA8SpawnParticle;
                MATCHING_KEEP2(sample, emit);
                frame.f.x = sample >> 7;
                MATCHING_BARRIER_VOLATILE("memory");
                {
                    register int offset __asm__("$2") = particleAngle * 2;
                    MATCHING_KEEP(offset);
                    sample = *(short*)((unsigned char*)&Controller79EA8D_800658A0 + offset);
                }
                MATCHING_KEEP_CLOBBER(sample, "$7");
                vectorArgument = particleVector;
                MATCHING_KEEP(vectorArgument);
                frame.f.z = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(sample, "memory");
                frame.f.y = sample >> 7;
                emit(type, selector, position, vectorArgument);
                if (particleIndex & 1) {
                    Controller79EA8ShiftVectorRightTowardZero(particleVector, 1);
                    Controller79EA8SpawnParticle(1, 0x37, particlePosition, particleVector);
                }
                cosineEntry += 0x20;
                particleIndex += 1;
                particleAngle += 0x20;
            } while (particleIndex < 8);
            probePosition = owner + 0xC;
            secondHit =
                Controller79EA8QueryDynamicMobyGeometry(probePosition, 0x400, 1, 0, 0, owner);
            if ((secondHit != 0) &&
                (Controller79EA8QueryWorldSegment(probePosition, secondHit + 0xC) == 0)) {
                Controller79EA8Field(secondHit, int*, 0x18) =
                    (int)(Controller79EA8Field(secondHit, int*, 0x18) | 0x110000);
            }
            if ((Controller79EA8D_8006C578 - Controller79EA8D_8006C574) >= 0x15) {
                spawnedChild = Controller79EA8SpawnMoby(0x146, owner);
                if (spawnedChild != 0) {
                    Controller79EA8Field(spawnedChild, signed char*, 0x47) = 8;
                    Controller79EA8Field(spawnedChild, signed char*, 0x4C) = 0x3F;
                    Controller79EA8Field(spawnedChild, signed char*, 0x4E) = 0x3F;
                }
            }
            finalHandle = Controller79EA8Field(tag, void**, 8);
            if (finalHandle != 0) {
                Controller79EA8ClearHistorySourceWord(finalHandle);
            }
            Controller79EA8PlayMobySoundEvent(owner, 1, 0);
        removeOwner:
            Controller79EA8DeleteMoby(owner);
            break;
    }
}

#undef Controller79EA8Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_28/moby", D_level_28_800745A4);

typedef struct {
    int type, retain, hudIndex;
} DecodedCollectibleHudTag;
typedef struct {
    int value[4];
} DecodedCollectibleHudIds;
extern DecodedCollectibleHudIds DecodedCollectibleHudData __asm__("D_level_28_800745A4");
extern unsigned char DecodedCollectibleHudPlayer[] __asm__("D_80070328");
extern unsigned char D_8006C7F8[];
void DecodedCollectibleHudSave(void*, int, void*) __asm__("func_8003B7B4");
void DecodedCollectibleHudSound(Moby*, int, int) __asm__("func_8003BABC");
void DecodedCollectibleHudUpdate(void*) __asm__("func_80027D60");
void DecodedCollectibleHudDraw(void*) __asm__("func_8002982C");
short DecodedCollectibleHudCreate(int, int, void (*)(void*), int, void (*)(void*), int,
                                  int) __asm__("func_8002803C");
void DecodedCollectibleHudDelete(int) __asm__("func_80028154");
void func_level_28_8007A414(Moby* moby) {
    DecodedCollectibleHudTag* tag = moby->mobyTag;
    DecodedCollectibleHudIds ids = DecodedCollectibleHudData;
    int distance;
    Moby* spawned;
    moby->size = 40;
    distance = func_8004F334(&moby->position, DecodedCollectibleHudPlayer);
    switch (moby->state) {
        case 0:
            switch (tag->type) {
                case 0:
                    moby->colour.r = 0xCF;
                    moby->colour.g = 0x20;
                    moby->colour.b = 0x20;
                    break;
                case 1:
                    moby->colour.r = 0x20;
                    moby->colour.g = 0xCF;
                    moby->colour.b = 0x20;
                    break;
                case 2:
                    moby->colour.r = 0x20;
                    moby->colour.g = 0x20;
                    moby->colour.b = 0xCF;
                    break;
                default:
                    tag->type = 3;
                    moby->colour.r = 0xFF;
                    moby->colour.g = 0xB0;
                    moby->colour.b = 0x20;
                    break;
            }
            DecodedCollectibleHudSave(tag, 4, D_8006C7F8);
            moby->colour.a = 0x3F;
            moby->angle.roll = 0x40;
            moby->angle.pitch = 0x20;
            moby->state = 1;
            /* Retail initialization continues into the state 1 yaw update. */
        case 1:
            moby->angle.yaw += 8;
            if (distance < 900) {
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
                moby->state = 2;
                DecodedCollectibleHudSave(&moby->state, 1, D_8006C7F8);
                DecodedCollectibleHudSound(moby, 0, 0);
                if (!tag->retain) {
                    spawned = SpawnMoby(0x110, moby);
                    if (spawned) {
                        spawned->angle.yaw = 0;
                        spawned->size = 16;
                        ((unsigned char*)spawned->mobyTag)[4] = 0;
                    }
                }
            }
            break;
        case 2:
            if (tag->hudIndex == -1)
                tag->hudIndex = DecodedCollectibleHudCreate(0x15, ids.value[tag->type],
                                                            DecodedCollectibleHudUpdate, 0,
                                                            DecodedCollectibleHudDraw, 0, 0);
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            func_8004F178(&moby->position, DecodedCollectibleHudPlayer);
            break;
        case 3:
            if (tag->hudIndex != -1) {
                DecodedCollectibleHudDelete(tag->hudIndex);
                tag->hudIndex = -1;
            }
            func_80055B18(moby);
            break;
        case 4:
            moby->angle.pitch = 0;
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 8007A6BC.
* Assembly SHA256 5d8f5d7e8b47487484b71a985e6a6f633a23257f293fb71e17b26b3a2850a5df.
* AI generated; not human reviewed. All 944 original instructions and
* actual branch/call/internal targets are required. Frame E8 retains every
* S0/S1/S2/S3/S4/RA save/restore and original SP20..CF local extent.
* Original packed data at 800745CC is exactly 12 bytes:
* 20 00 00 00 00 00 00 00 E0 FF FF FF; it is not a jump table.
* The physical dispatch order is 4/8/16/2. Each successful 4/8/16 arm
* retains its original countdown read and jump to the shared decrement.
* Independent named data views resolve to the exact original addresses;
* the final palette channel uses the original signed halfword at +2.
* Empty initialized constraints and dead-before-producer clobbers emit no
* CPU instructions. They retain original ownership, scheduling and joins.
* Raw units/fixed point, full helper contracts and caller cadence remain
* unresolved. Cadence here is per invocation. Binary identity does not
* establish synchronized retail runtime or complete game behavior.
* Falsification: every native/linked word and actual target, complete data
* bytes, full EXE and every overlay retail hash must remain identical. */
#define Actor28Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Actor28CopyCameraPositionWithWrappedAngleView1() __asm__("func_800135A4");
int Actor28QueryWorldSegmentView1() __asm__("func_80018368");
int Actor28ConfigureHudEntryView1() __asm__("func_8002803C");
short Actor28ConfigureHudEntryView2() __asm__("func_8002803C");
unsigned char Actor28ResetHudEntryByHandleView1() __asm__("func_80028154");
unsigned char Actor28EmptyAnimationTransitionHookView1() __asm__("func_80035734");
unsigned char Actor28TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor28CountTimerDownView1() __asm__("func_800359A4");
int Actor28AddAngle8View1() __asm__("func_8003617C");
int Actor28PlayMobySoundEventView1() __asm__("func_8003BABC");
unsigned char Actor28TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Actor28SoundHandleMatchesOwnerInStates1Or2View1() __asm__("func_8003BFC0");
int Actor28AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
void* Actor28AllocateVectorTrailRecordView1() __asm__("func_80050844");
unsigned char Actor28ClearHistorySourceWordView1() __asm__("func_800509E8");
unsigned char Actor28DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor28RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor28ReadSelectedFrameScalarView1() __asm__("func_80055E84");
unsigned char Actor28InterpolateMobyVertexView1() __asm__("func_80055F14");
extern int Actor28Data6580CView1 __asm__("D_8006580C");
extern unsigned char Actor28Data6585CView1 __asm__("D_8006585C");
extern unsigned char Actor28Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor28Data65920View1 __asm__("D_80065920");
extern unsigned char Actor28Data68F7CView1 __asm__("D_80068F7C");
extern unsigned char Actor28Data68F90View1 __asm__("D_80068F90");
extern unsigned int Actor28Data6C550View1 __asm__("D_8006C550");
extern int Actor28Data6C58CView1 __asm__("D_8006C58C");
extern int Actor28Data6C640View1 __asm__("D_8006C640");
extern int Actor28Data6C6D0View1 __asm__("D_8006C6D0");
extern unsigned int Actor28Data6C704View1 __asm__("D_8006C704");
extern int Actor28Data6C770View1 __asm__("D_8006C770");
extern int Actor28Data6E344View1 __asm__("D_8006E344");
extern int Actor28Data6E538View1 __asm__("D_8006E538");
extern unsigned char Actor28Data70328View1 __asm__("D_80070328");
extern unsigned char Actor28Data716ACView1 __asm__("D_800716AC");
extern unsigned char Actor28Data719A8View1 __asm__("D_800719A8");
extern unsigned char Actor28Data719F0View1 __asm__("D_800719F0");
extern unsigned char Actor28Data745D8View1 __asm__("D_level_28_800745D8");
extern int Actor28Data74364View1 __asm__("unk_ovlheader_80074364");
extern int Actor28Data74368View1 __asm__("unk_ovlheader_80074368");
extern int Actor28Data7436CView1 __asm__("unk_ovlheader_8007436C");
extern void* (*Actor28DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor28DataSpawnParticleView1)() __asm__("SpawnParticle");
extern int (*Actor28Data74318View1)() __asm__("unk_ovlheader_80074318");
const unsigned char Actor28Data745CCView1[12] __asm__("D_level_28_800745CC")
    __attribute__((aligned(4))) = {32, 0, 0, 0, 0, 0, 0, 0, 224, 255, 255, 255};
extern unsigned char Actor28Data745CCView2 __asm__("D_level_28_800745CC");
extern int Actor28Data70328View2 __asm__("D_80070328 + 640 + 0 - 0");
extern int Actor28Data70328View3 __asm__("D_80070328 + 640 + 1 - 1");
extern int Actor28Data70328View4 __asm__("D_80070328 + 640 + 2 - 2");
extern int Actor28Data70328View5 __asm__("D_80070328 + 640 + 3 - 3");
extern int Actor28Data70328View6 __asm__("D_80070328 + 640 + 4 - 4");
extern int Actor28Data70328View7 __asm__("D_80070328 + 640 + 5 - 5");
extern unsigned char Actor28Data6585CView2 __asm__("D_8006585C + 0 + 6 - 6");
extern unsigned char Actor28Data6585CView3 __asm__("D_8006585C + 0 + 7 - 7");
extern unsigned char Actor28Data6585CView4 __asm__("D_8006585C + 0 + 8 - 8");
extern unsigned char Actor28Data6585CView5 __asm__("D_8006585C + 0 + 9 - 9");
extern unsigned char Actor28Data6585CView6 __asm__("D_8006585C + 2 + 10 - 10");
void func_level_28_8007A6BC(void* input) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register unsigned int addressWord4 __asm__("$4");
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register void* memoryCursor3 __asm__("$3");
    register unsigned char* copyEnd8 __asm__("$8");
    register void* spawnedRecord18 __asm__("$18");
    register void* ownerRecord20 __asm__("$20");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC;
    } originalFrame;
    register unsigned char* temporaryWord9 __asm__("$5");
    register unsigned char* temporaryWord10 __asm__("$5");
    register unsigned char* temporaryWord16 __asm__("$6");
    register unsigned char* temporaryWord17 __asm__("$7");
    int temporaryWord3;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord11;
    int temporaryWord15;
    register int firstSpawnIndex16 __asm__("$16");
    register int secondSpawnIndex16 __asm__("$16");
    int temporaryWord13;
    int temporaryWord12;
    void* temporaryPointer4;
    void* temporaryPointer5;
    register void* playerModePointer16 __asm__("$16");
    register void* privateRecord19 __asm__("$19");
    void* temporaryPointer14;
    ownerRecord20 = input;
    MATCHING_KEEP(ownerRecord20);
    privateRecord19 = Actor28Field(ownerRecord20, void**, 0);
    rawWord2 = Actor28Field(privateRecord19, short*, 4);
    if (rawWord2)
        goto initialized28;
    {
        rawWord2 = 1;
        addressWord4 = Actor28Data6C550View1;
        rawWord3 = Actor28Data6C704View1;
        Actor28Field(privateRecord19, short*, 4) = rawWord2;
        rawWord3 = addressWord4 < (unsigned int)rawWord3;
        Actor28Field(privateRecord19, short*, 0x32) = 0;
        if (!rawWord3)
            goto listDone28;
        argumentWord6 = 1;
        argumentWord5 = 381;
        memoryCursor3 = (void*)(addressWord4 + 71);
        MATCHING_KEEP(memoryCursor3);
        do {
            rawWord2 = Actor28Field(memoryCursor3, short*, -17);
            if (rawWord2 == argumentWord6) {
                Actor28Field(memoryCursor3, short*, -17) = argumentWord5;
                Actor28Field(memoryCursor3, unsigned char*, 0) = 0;
            }
            rawWord2 = Actor28Data6C704View1;
            addressWord4 += 88;
            rawWord2 = addressWord4 < (unsigned int)rawWord2;
            memoryCursor3 += 88;
        } while (rawWord2);
    listDone28:
        temporaryWord11 = Actor28Field(&Actor28Data70328View1, int*, 0x280) * 2;
        Actor28Field(privateRecord19, int*, 0x28) = temporaryWord11;
        if (temporaryWord11 >= 7) {
            Actor28Field(privateRecord19, int*, 0x28) = 6;
        }
        if (Actor28Field(privateRecord19, int*, 0x28) <= 0) {
            Actor28Field(privateRecord19, int*, 0x28) = 1;
        }
        rawWord2 =
            Actor28ConfigureHudEntryView1(0x17, 0xB4, Actor28Data74368View1, Actor28Data7436CView1,
                                          Actor28Data74364View1, privateRecord19 + 0x28, 6);
        rawWord2 <<= 16;
        rawWord3 = Actor28Data6C58CView1;
        rawWord2 >>= 16;
        Actor28Field(privateRecord19, int*, 0x40) = rawWord2;
        temporaryWord1 = rawWord3 * 6;
        temporaryWord12 = *(&Actor28Data716ACView1 + temporaryWord1);
        if (temporaryWord12 < 0xFFU) {
            *(&Actor28Data716ACView1 + temporaryWord1) = temporaryWord12 + 1;
        }
    }
initialized28:
    if (Actor28Data6E344View1 == 1) {
        temporaryWord2 = Actor28Field(privateRecord19, int*, 0x40);
        if (temporaryWord2 != -1) {
            Actor28ResetHudEntryByHandleView1(temporaryWord2);
            Actor28Field(privateRecord19, int*, 0x40) = -1;
        }
    } else if (Actor28Field(privateRecord19, int*, 0x40) == -1) {
        Actor28Field(privateRecord19, int*, 0x40) = (int)Actor28ConfigureHudEntryView2(
            0x17, 0xB4, Actor28Data74368View1, Actor28Data7436CView1, Actor28Data74364View1,
            privateRecord19 + 0x28, 6);
    }
    Actor28Data74318View1(ownerRecord20, 0x98);
    if ((Actor28Field(privateRecord19, int*, 0x1C) & 0x21) == 0x20) {
        if ((Actor28Data6C640View1 % 15) < 0xC) {
            Actor28Field(ownerRecord20, signed char*, 0x4C) = 0;
            Actor28Field(ownerRecord20, signed char*, 0x4D) = 0;
        } else {
            Actor28Field(ownerRecord20, signed char*, 0x4C) = 0x20;
            Actor28Field(ownerRecord20, signed char*, 0x4D) = 1;
        }
    }
    Actor28Data6C6D0View1 = 0;
    Actor28CopyCameraPositionWithWrappedAngleView1(&Actor28Data719A8View1, &Actor28Data68F7CView1,
                                                   0);
    Actor28CopyCameraPositionWithWrappedAngleView1(&Actor28Data719F0View1, &Actor28Data68F90View1,
                                                   0);
    rawWord2 = Actor28Field(privateRecord19, int*, 0x28);
    if (rawWord2 > 0)
        goto positiveCount28;
    Actor28Field(&Actor28Data70328View1, int*, 0x280) = 0;
    Actor28Field(&Actor28Data70328View1, int*, 0x24) |= 1;
    return;
positiveCount28:
    rawWord2 += 1;
    addressWord4 = (unsigned int)(&Actor28Data70328View1 + 0x280);
    MATCHING_KEEP(addressWord4);
    rawWord3 = (unsigned int)rawWord2 >> 31;
    rawWord2 += rawWord3;
    rawWord3 = Actor28Data6580CView1;
    rawWord2 >>= 1;
    Actor28Field(addressWord4, int*, 0) = rawWord2;
    if (rawWord3 < rawWord2)
        Actor28Field(addressWord4, int*, 0) = rawWord3;
    if (Actor28Field(privateRecord19, int*, 0x44) != 0) {
        Actor28TurnMobyTowardHeadingView1(ownerRecord20, 0x10E, 2, 0, 0, 0);
    }
    if (Actor28Field(privateRecord19, int*, 8) != 0) {
        Actor28PlayMobySoundEventView1(ownerRecord20, 0, 0);
        if (Actor28Field(ownerRecord20, unsigned char*, 0x3D) != 1) {
            Actor28Data6C770View1 = 0;
            Actor28Field(ownerRecord20, signed char*, 0x40) = 0x72;
            Actor28Field(ownerRecord20, unsigned char*, 0x3D) = 1U;
            Actor28Field(ownerRecord20, signed char*, 0x3F) = 0;
            Actor28EmptyAnimationTransitionHookView1(ownerRecord20);
        }
        Actor28Field(privateRecord19, int*, 8) = 0;
    }
    if ((Actor28ReadSelectedFrameScalarView1(ownerRecord20) >= 8) &&
        (Actor28Field(privateRecord19, int*, 0x3C) != 1) &&
        (Actor28Field(ownerRecord20, unsigned short*, 0x3C) == 0x101)) {
        Actor28PlayMobySoundEventView1(ownerRecord20, 1, 0);
        Actor28Field(privateRecord19, int*, 0x3C) = 1;
    } else if (Actor28Data6C770View1 != 0) {
        if (Actor28Field(ownerRecord20, unsigned char*, 0x3D) != 0) {
            Actor28Data6C770View1 = 0;
            Actor28Field(ownerRecord20, signed char*, 0x40) = 0x72;
            Actor28Field(ownerRecord20, unsigned char*, 0x3D) = 0U;
            Actor28Field(ownerRecord20, signed char*, 0x3F) = 0;
            Actor28EmptyAnimationTransitionHookView1(ownerRecord20);
        }
        Actor28Field(privateRecord19, int*, 0x3C) = 0;
    }
    if (Actor28Data6E538View1 & 0x80) {
        if (!(Actor28Field(privateRecord19, int*, 0x1C) & 1)) {
            if ((Actor28Data6E344View1 != 1) && (Actor28Data6E344View1 != 0xF)) {
                if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                        ownerRecord20, Actor28Field(privateRecord19, int*, 0x48)) == 0) {
                    Actor28Field(privateRecord19, int*, 0x48) =
                        Actor28PlayMobySoundEventView1(ownerRecord20, 3, 4);
                }
            } else {
                goto checkStatusBit;
            }
        } else {
            goto updateStatusHandle;
        }
    } else {
    checkStatusBit:
        if (Actor28Field(privateRecord19, int*, 0x1C) & 1) {
        updateStatusHandle:
            if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord20, Actor28Field(privateRecord19, int*, 0x48)) == 0) {
                Actor28Field(privateRecord19, int*, 0x48) =
                    Actor28PlayMobySoundEventView1(ownerRecord20, 4, 4);
            }
        } else if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                       ownerRecord20, Actor28Field(privateRecord19, int*, 0x48)) != 0) {
            if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord20, Actor28Field(privateRecord19, int*, 0x48)) != 0) {
                Actor28TransitionSoundHandleTo3Or5View1(Actor28Field(privateRecord19, int*, 0x48));
            }
            Actor28Field(privateRecord19, int*, 0x48) = -1;
        }
    }
    Actor28CountTimerDownView1(privateRecord19, 4);
    if ((Actor28Data6E538View1 & 0x60) &&
        (playerModePointer16 = &Actor28Data70328View1 + 0x48,
         (Actor28Field(&Actor28Data70328View1, int*, 0x48) != 0x99)) &&
        (Actor28Data6E344View1 != 1)) {
        if (Actor28Data6E344View1 != 0xF) {
            if (Actor28Field(privateRecord19, int*, 0) <= 0) {
                if (Actor28Data6E538View1 & 0x40) {
                    rawWord2 = Actor28Field(privateRecord19, int*, 0x1C);
                    MATCHING_KEEP(rawWord2);
                    rawWord3 = rawWord2 & 0x1E;
                    switch (rawWord3) {
                        case 4:
                            temporaryWord9 = &Actor28Data745CCView2;
                            MATCHING_KEEP(temporaryWord9);
                            rawWord2 = Actor28Field(temporaryWord9, int*, 0);
                            rawWord3 = Actor28Field(temporaryWord9, int*, 4);
                            argumentWord4 = Actor28Field(temporaryWord9, int*, 8);
                            originalFrame.sp20 = rawWord2;
                            originalFrame.sp24 = rawWord3;
                            originalFrame.sp28 = argumentWord4;
                            __asm__ __volatile__("" ::: "$16", "memory");
                            firstSpawnIndex16 = 0;
                            do {
                                spawnedRecord18 = Actor28DataSpawnMobyView1(0xBB, ownerRecord20);
                                MATCHING_KEEP(spawnedRecord18);
                                if (spawnedRecord18 != 0) {
                                    Actor28Field(spawnedRecord18, unsigned char*, 0x46) =
                                        Actor28AddAngle8View1(
                                            Actor28Field(spawnedRecord18, unsigned char*, 0x46),
                                            Actor28Field((((unsigned char*)&originalFrame - 0x20) +
                                                          (firstSpawnIndex16 * 4)),
                                                         int*, 0x20));
                                    if (Actor28QueryWorldSegmentView1(&Actor28Data70328View1,
                                                                      spawnedRecord18 + 0xC) != 0) {
                                        Actor28DeleteMobyView1(spawnedRecord18);
                                    }
                                    Actor28PlayMobySoundEventView1(spawnedRecord18, 0, 1);
                                }
                                firstSpawnIndex16 += 1;
                            } while (firstSpawnIndex16 < 3);
                            rawWord2 = Actor28Field(privateRecord19, int*, 0x20);
                            __asm__ __volatile__(""
                                                 : "=r"(rawWord2)
                                                 : "0"(rawWord2)
                                                 : "$3", "memory");
                            rawWord3 = 50;
                            __asm__ __volatile__("" ::"r"(rawWord2), "r"(rawWord3), "i"(0x8007ad04)
                                                 : "memory");
                            Actor28Field(privateRecord19, int*, 0) = rawWord3;
                            goto decrementCountdown;
                        case 8:
                            temporaryWord10 = &Actor28Data745CCView2;
                            MATCHING_KEEP(temporaryWord10);
                            rawWord2 = Actor28Field(temporaryWord10, int*, 0);
                            rawWord3 = Actor28Field(temporaryWord10, int*, 4);
                            argumentWord4 = Actor28Field(temporaryWord10, int*, 8);
                            originalFrame.sp30 = rawWord2;
                            originalFrame.sp34 = rawWord3;
                            originalFrame.sp38 = argumentWord4;
                            __asm__ __volatile__("" ::: "$16", "memory");
                            secondSpawnIndex16 = 0;
                            do {
                                spawnedRecord18 = Actor28DataSpawnMobyView1(0x97, ownerRecord20);
                                MATCHING_KEEP(spawnedRecord18);
                                if (spawnedRecord18 != 0) {
                                    Actor28Field(spawnedRecord18, unsigned char*, 0x46) =
                                        Actor28AddAngle8View1(
                                            Actor28Field(spawnedRecord18, unsigned char*, 0x46),
                                            Actor28Field((((unsigned char*)&originalFrame - 0x20) +
                                                          (secondSpawnIndex16 * 4)),
                                                         int*, 0x30));
                                    if (Actor28QueryWorldSegmentView1(&Actor28Data70328View1,
                                                                      spawnedRecord18 + 0xC) != 0) {
                                        if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                                                spawnedRecord18,
                                                Actor28Field(
                                                    Actor28Field(spawnedRecord18, void**, 0), int*,
                                                    8)) != 0) {
                                            if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                                                    ownerRecord20,
                                                    Actor28Field(
                                                        Actor28Field(spawnedRecord18, void**, 0),
                                                        int*, 8)) != 0) {
                                                Actor28TransitionSoundHandleTo3Or5View1(
                                                    Actor28Field(
                                                        Actor28Field(spawnedRecord18, void**, 0),
                                                        int*, 8));
                                            }
                                            Actor28Field(Actor28Field(spawnedRecord18, void**, 0),
                                                         int*, 8) = -1;
                                        }
                                        Actor28DeleteMobyView1(spawnedRecord18);
                                    }
                                    Actor28PlayMobySoundEventView1(spawnedRecord18, 0, 1);
                                }
                                secondSpawnIndex16 += 1;
                            } while (secondSpawnIndex16 < 3);
                            rawWord2 = Actor28Field(privateRecord19, int*, 0x20);
                            __asm__ __volatile__(""
                                                 : "=r"(rawWord2)
                                                 : "0"(rawWord2)
                                                 : "$3", "memory");
                            rawWord3 = 50;
                            __asm__ __volatile__("" ::"r"(rawWord2), "r"(rawWord3), "i"(0x8007ae0c)
                                                 : "memory");
                            Actor28Field(privateRecord19, int*, 0) = rawWord3;
                            goto decrementCountdown;
                        case 16:
                            spawnedRecord18 = Actor28DataSpawnMobyView1(0x251, ownerRecord20);
                            MATCHING_KEEP(spawnedRecord18);
                            if (spawnedRecord18 != 0) {
                                if (Actor28QueryWorldSegmentView1(playerModePointer16 - 0x48,
                                                                  spawnedRecord18 + 0xC) != 0) {
                                    Actor28DeleteMobyView1(spawnedRecord18);
                                } else {
                                    Actor28Field(Actor28Field(spawnedRecord18, void**, 0), int*,
                                                 0) =
                                        (int)((int)(Actor28Field(
                                                        &Actor28Data65920View1, short*,
                                                        (Actor28Field(&Actor28Data70328View1,
                                                                      unsigned char*, 0xE) *
                                                         2)) *
                                                    0xAF) >>
                                              0xC);
                                    Actor28Field(Actor28Field(spawnedRecord18, void**, 0), int*,
                                                 4) =
                                        (int)((int)(Actor28Field(
                                                        &Actor28Data658A0View1, short*,
                                                        (Actor28Field(&Actor28Data70328View1,
                                                                      unsigned char*, 0xE) *
                                                         2)) *
                                                    0xAF) >>
                                              0xC);
                                    Actor28Field(Actor28Field(spawnedRecord18, void**, 0), int*,
                                                 8) = 0;
                                    rawWord2 = Actor28Field(privateRecord19, int*, 0x20);
                                    __asm__ __volatile__(""
                                                         : "=r"(rawWord2)
                                                         : "0"(rawWord2)
                                                         : "$3", "memory");
                                    rawWord3 = 50;
                                    __asm__ __volatile__("" ::"r"(rawWord2), "r"(rawWord3),
                                                         "i"(0x8007aef0)
                                                         : "memory");
                                    Actor28Field(privateRecord19, int*, 0) = rawWord3;
                                    goto decrementCountdown;
                                }
                            }
                            break;
                        case 2:
                            temporaryWord17 = (unsigned char*)&originalFrame.sp40;
                            temporaryWord16 = &Actor28Data745D8View1;
                            copyEnd8 = temporaryWord16 + 128;
                            do {
                                rawWord2 = Actor28Field(temporaryWord16, int*, 0);
                                rawWord3 = Actor28Field(temporaryWord16, int*, 4);
                                argumentWord4 = Actor28Field(temporaryWord16, int*, 8);
                                argumentWord5 = Actor28Field(temporaryWord16, int*, 12);
                                Actor28Field(temporaryWord17, int*, 0) = rawWord2;
                                Actor28Field(temporaryWord17, int*, 4) = rawWord3;
                                Actor28Field(temporaryWord17, int*, 8) = argumentWord4;
                                Actor28Field(temporaryWord17, int*, 12) = argumentWord5;
                                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(temporaryWord16, "memory");
                                temporaryWord16 += 0x10;
                                temporaryWord17 += 0x10;
                            } while (temporaryWord16 != copyEnd8);
                            temporaryWord13 = Actor28Field(privateRecord19, unsigned short*, 0x30);
                            if (temporaryWord13 >= 0x1FU) {
                                Actor28Field(privateRecord19, unsigned short*, 0x30) = 0U;
                            } else {
                                Actor28Field(privateRecord19, unsigned short*, 0x30) =
                                    (unsigned short)(temporaryWord13 + 1);
                            }
                            spawnedRecord18 = Actor28DataSpawnMobyView1(0x175, ownerRecord20);
                            MATCHING_KEEP(spawnedRecord18);
                            if (spawnedRecord18 != 0) {
                                Actor28Field(privateRecord19, int*, 0) = 1;
                                Actor28Field(Actor28Field(spawnedRecord18, void**, 0), int*, 0) =
                                    (int)((int)(Actor28Field(
                                                    &Actor28Data65920View1, short*,
                                                    (Actor28AddAngle8View1(
                                                         Actor28Field(&Actor28Data70328View1,
                                                                      unsigned char*, 0xE),
                                                         Actor28Field(
                                                             &(&originalFrame
                                                                    .sp20)[(short)Actor28Field(
                                                                 privateRecord19, unsigned short*,
                                                                 0x30)],
                                                             int*, 0x20)) *
                                                     2)) *
                                                0xE1) >>
                                          0xB);
                                Actor28Field(Actor28Field(spawnedRecord18, void**, 0), int*, 4) =
                                    (int)((int)(Actor28Field(
                                                    &Actor28Data658A0View1, short*,
                                                    (Actor28AddAngle8View1(
                                                         Actor28Field(&Actor28Data70328View1,
                                                                      unsigned char*, 0xE),
                                                         Actor28Field(
                                                             &(&originalFrame
                                                                    .sp20)[(short)Actor28Field(
                                                                 privateRecord19, unsigned short*,
                                                                 0x30)],
                                                             int*, 0x20)) *
                                                     2)) *
                                                0xE1) >>
                                          0xB);
                                Actor28Field(Actor28Field(spawnedRecord18, void**, 0), int*, 8) = 0;
                                if (Actor28QueryWorldSegmentView1((&Actor28Data70328View1 + 0xE) -
                                                                      0xE,
                                                                  spawnedRecord18 + 0xC) != 0) {
                                    Actor28DeleteMobyView1(spawnedRecord18);
                                }
                                if (Actor28Field(privateRecord19, int*, 0x20) ==
                                    ((Actor28Field(privateRecord19, int*, 0x20) / 5) * 5)) {
                                    Actor28PlayMobySoundEventView1(spawnedRecord18, 0, 1);
                                }
                            }
                            rawWord2 = Actor28Field(privateRecord19, int*, 0x20);
                        decrementCountdown:
                            rawWord2 -= 1;
                            Actor28Field(privateRecord19, int*, 0x20) = rawWord2;
                            if ((rawWord2 <= 0) &&
                                (temporaryWord3 = Actor28Field(privateRecord19, short*, 0x36),
                                 Actor28Field(privateRecord19, int*, 0x1C) =
                                     (int)(Actor28Field(privateRecord19, int*, 0x1C) & ~0x1E),
                                 (temporaryWord3 != -1))) {
                                Actor28ResetHudEntryByHandleView1((int)temporaryWord3);
                            }
                            break;
                        default:
                            break;
                    }
                } else if ((Actor28Data6E538View1 & 0x20) &&
                           (Actor28Field(privateRecord19, short*, 0x32) < 0x37) &&
                           (spawnedRecord18 = Actor28DataSpawnMobyView1(0x175, ownerRecord20),
                            (spawnedRecord18 != 0))) {
                    Actor28Field(privateRecord19, int*, 0) = 0xB;
                    MATCHING_KEEP(spawnedRecord18);
                    if (Actor28QueryWorldSegmentView1(playerModePointer16 - 0x48,
                                                      spawnedRecord18 + 0xC) != 0) {
                        Actor28DeleteMobyView1(spawnedRecord18);
                    }
                    Actor28PlayMobySoundEventView1(spawnedRecord18, 0, 1);
                }
            }
        } else {
            goto resetSequenceIndex;
        }
    } else {
    resetSequenceIndex:
        rawWord2 = -1;
        Actor28Field(privateRecord19, unsigned short*, 0x30) = rawWord2;
    }
    Actor28Field(privateRecord19, short*, 0x32) = 0;
    Actor28RefreshMobySpatialGridAndBasisView1(ownerRecord20, 4);
    rawWord2 = Actor28Data70328View2;
    rawWord2 = Actor28Field(&Actor28Data6585CView2, int*, rawWord2 * 4);
    Actor28Field(ownerRecord20, int*, 0x54) = rawWord2;
    __asm__ __volatile__("" ::: "$3", "$4", "$5", "memory");
    if (Actor28Data70328View3 >= 2) {
        Actor28InterpolateMobyVertexView1(ownerRecord20, 1, &originalFrame.sp20);
        originalFrame.sp28 =
            (int)(originalFrame.sp28 + Actor28Field(ownerRecord20, int*, 0x14)) >> 1;
        Actor28DataSpawnParticleView1(2, 0x42, &originalFrame.sp20, 0);
        Actor28InterpolateMobyVertexView1(ownerRecord20, 2, &originalFrame.sp20);
        originalFrame.sp28 =
            (int)(originalFrame.sp28 + Actor28Field(ownerRecord20, int*, 0x14)) >> 1;
        Actor28DataSpawnParticleView1(2, 0x42, &originalFrame.sp20, 0);
    }
    if (Actor28Field(&Actor28Data70328View1, int*, 0x48) == 0x99) {
        Actor28InterpolateMobyVertexView1(ownerRecord20, 0, privateRecord19 + 0x10);
        temporaryPointer4 = Actor28Field(privateRecord19, void**, 0xC);
        Actor28Field(privateRecord19, int*, 0x18) =
            (int)(Actor28Field(privateRecord19, int*, 0x18) + 0x100);
        if ((unsigned char)Actor28Field(temporaryPointer4, unsigned char*, 0x65) < 0x10U) {
            if (temporaryPointer4 != 0) {
                Actor28ClearHistorySourceWordView1(temporaryPointer4);
            }
            Actor28Field(privateRecord19, void**, 0xC) = 0;
        }
        if (Actor28Field(privateRecord19, void**, 0xC) == 0) {
            Actor28Field(privateRecord19, void**, 0xC) = Actor28AllocateVectorTrailRecordView1(
                privateRecord19 + 0x10, -0xC, 0x10,
                Actor28Field(&Actor28Data6585CView3, int*, (Actor28Data70328View4 * 4)) & 0xFFFFFF);
        } else {
            if (Actor28AbsoluteByteAngleDeltaView1(
                    Actor28Field(ownerRecord20, unsigned char*, 0x46), 0) < 32)
                goto bright28;
            if (Actor28AbsoluteByteAngleDeltaView1(
                    Actor28Field(ownerRecord20, unsigned char*, 0x46), 128) >= 32)
                goto dark28;
        bright28:
            memoryCursor3 = Actor28Field(privateRecord19, void**, 12);
            __asm__ __volatile__("" ::"r"(memoryCursor3), "i"(0x8007B2D8) : "memory");
            rawWord2 = 244;
            goto color28;
        dark28:
            rawWord2 = 7;
            memoryCursor3 = Actor28Field(privateRecord19, void**, 12);
        color28:
            MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(rawWord2, memoryCursor3, "memory");
            Actor28Field(memoryCursor3, signed char*, 0x66) = rawWord2;
            __asm__ __volatile__("" ::: "$3", "$4", "$5", "memory");
            Actor28Field(Actor28Field(privateRecord19, void**, 0xC), signed char*, 0x68) =
                (signed char)Actor28Field(&Actor28Data6585CView4, int*,
                                          (Actor28Data70328View5 * 4));
            __asm__ __volatile__("" ::: "$3", "$4", "$5", "memory");
            Actor28Field(Actor28Field(privateRecord19, void**, 0xC), signed char*, 0x69) =
                (signed char)((int)Actor28Field(&Actor28Data6585CView5, int*,
                                                (Actor28Data70328View6 * 4)) >>
                              8);
            __asm__ __volatile__("" ::: "$3", "$4", "$5", "memory");
            rawWord2 = Actor28Data70328View7;
            memoryCursor3 = Actor28Field(privateRecord19, void**, 12);
            rawWord2 = Actor28Field(&Actor28Data6585CView6, short*, rawWord2 * 4);
            MATCHING_KEEP(rawWord2);
            Actor28Field(memoryCursor3, signed char*, 0x6A) = rawWord2;
        }
    } else {
        temporaryPointer14 = Actor28Field(privateRecord19, void**, 0xC);
        if (temporaryPointer14 != 0) {
            Actor28Field(temporaryPointer14, unsigned char*, 0x65) =
                (unsigned char)(Actor28Field(temporaryPointer14, unsigned char*, 0x65) - 1);
            temporaryPointer5 = Actor28Field(privateRecord19, void**, 0xC);
            if (Actor28Field(temporaryPointer5, unsigned char*, 0x65) == 0) {
                Actor28ClearHistorySourceWordView1(temporaryPointer5);
                Actor28Field(privateRecord19, void**, 0xC) = 0;
            } else {
                Actor28InterpolateMobyVertexView1(ownerRecord20, 0, privateRecord19 + 0x10);
                Actor28Field(privateRecord19, int*, 0x18) =
                    (int)(Actor28Field(privateRecord19, int*, 0x18) + 0x100);
            }
        }
    }
    temporaryWord15 = Actor28Field(privateRecord19, int*, 0x1C) & 0x21;
    switch (temporaryWord15) {
        case 1:
            if (Actor28CountTimerDownView1(privateRecord19 + 0x24, 4) != 0) {
                if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                        ownerRecord20, Actor28Field(privateRecord19, int*, 0x48)) != 0) {
                    if (Actor28SoundHandleMatchesOwnerInStates1Or2View1(
                            ownerRecord20, Actor28Field(privateRecord19, int*, 0x48)) != 0) {
                        Actor28TransitionSoundHandleTo3Or5View1(
                            Actor28Field(privateRecord19, int*, 0x48));
                    }
                    Actor28Field(privateRecord19, int*, 0x48) = -1;
                }
                temporaryWord6 = Actor28Field(privateRecord19, short*, 0x34);
                Actor28Field(privateRecord19, int*, 0x1C) =
                    (int)(Actor28Field(privateRecord19, int*, 0x1C) & ~0x21);
                if (temporaryWord6 != -1) {
                    Actor28ResetHudEntryByHandleView1((int)temporaryWord6);
                }
                Actor28Field(privateRecord19, short*, 0x34) = -1;
            } else if (Actor28Field(privateRecord19, void***, 0x2C) == 0) {
                Actor28Field(privateRecord19, void***, 0x2C) =
                    Actor28DataSpawnMobyView1(0xA3, ownerRecord20);
            }
            break;
        case 32:
            if (Actor28CountTimerDownView1(privateRecord19 + 0x24, 4) != 0) {
                temporaryWord7 = Actor28Field(privateRecord19, short*, 0x34);
                Actor28Field(privateRecord19, int*, 0x1C) =
                    (int)(Actor28Field(privateRecord19, int*, 0x1C) & ~0x21);
                if (temporaryWord7 != -1) {
                    Actor28ResetHudEntryByHandleView1((int)temporaryWord7);
                }
                Actor28Field(privateRecord19, short*, 0x34) = -1;
                Actor28Field(ownerRecord20, signed char*, 0x4C) = 0x20;
                Actor28Field(ownerRecord20, signed char*, 0x4D) = 1;
            }
            break;
    }
    rawWord2 = Actor28Field(privateRecord19, int*, 0x1C);
    MATCHING_KEEP(rawWord2);
    rawWord3 = rawWord2 & 30;
    if (rawWord3 == 4)
        goto finishActiveCountdown;
    if (rawWord3 >= 5)
        goto upper28;
    if (rawWord3 == 2)
        goto finishActiveCountdown;
    goto exit28;
upper28:
    if (rawWord3 == 8)
        goto finishActiveCountdown;
    if (rawWord3 != 16)
        goto exit28;
finishActiveCountdown:
    if (Actor28Field(privateRecord19, int*, 0x20) <= 0) {
        temporaryWord8 = Actor28Field(privateRecord19, short*, 0x36);
        Actor28Field(privateRecord19, int*, 0x1C) =
            (int)(Actor28Field(privateRecord19, int*, 0x1C) & ~0x1E);
        if (temporaryWord8 != -1) {
            Actor28ResetHudEntryByHandleView1((int)temporaryWord8);
        }
    }
exit28:;
}
#undef Actor28Field


/* AI-generated; not human reviewed. SCUS-94467 USA Rev0 original
 * words govern this actor family. Reuses verified raw601 signed trig/packet
 * code; original owner count, collision/helper chain, delta resets retained.
 * Raw coordinates, producer/helper semantics and cadence remain unresolved.
 * Test: independent original object/linked words and every retail hash. */
typedef struct {
    Vector3D delta;
    int timer;
} DecodedRawProjectileTag;
typedef struct {
    Vector3D oldPosition;
    int pad24;
    Vector3D particlePosition;
    int pad34;
    Vector3D direction;
    int pad44;
    int reserved48[4];
} DecodedRawProjectileWork;
extern void* DecodedRawProjectilePlayerLink __asm__("D_80070328+0x250");
extern short D_800658A0[], D_80065920[];
void func_level_28_8007B57C(Moby* mobyArgument) {
    DecodedRawProjectileWork work;
    register Moby* moby __asm__("$18") = mobyArgument;
    register DecodedRawProjectileTag* tag __asm__("$19");
    register int x __asm__("$6") = moby->position.x;
    register int y __asm__("$5");
    register int z __asm__("$4");
    register void* retained __asm__("$17");
    register int opposite __asm__("$19");
    register int heading __asm__("$16");
    register Vector3D* position __asm__("$20");
    register void* parent __asm__("$7");
    register int maximum __asm__("$3");
    char* particle;
    MATCHING_KEEP(moby);
    {
        register void* link __asm__("$2") = DecodedRawProjectilePlayerLink;
        register int below __asm__("$3");
        tag = moby->mobyTag;
        below = x < 1024;
        /* These ties preserve computed values and emit no instructions. */
        __asm__("" : "=r"(below) : "0"(below), "r"(link), "r"(tag));
        parent = *(void**)link;
        if (below)
            goto cleanup;
    }
    y = moby->position.y;
    if (y < 1024)
        goto cleanup;
    z = moby->position.z;
    if (z < 1024)
        goto cleanup;
    maximum = 256000;
    MATCHING_KEEP(maximum);
    {
        register int outside __asm__("$2");
        outside = x > maximum;
        MATCHING_KEEP(outside);
        if (outside)
            goto cleanup;
        outside = y > maximum;
        MATCHING_KEEP(outside);
        if (outside)
            goto cleanup;
        outside = z > maximum;
        MATCHING_KEEP(outside);
        if (outside)
            goto cleanup;
    }
    if (!*((unsigned char*)moby + 0x4D))
        goto cleanup;
    position = &moby->position;
    *(unsigned short*)((char*)parent + 0x32) += 1;
    func_8004F178(&work.oldPosition, position);
    moby->position.x += tag->delta.x;
    moby->position.y += tag->delta.y;
    moby->position.z += tag->delta.z;
    if (moby->state == 0) {
        retained = func_8001BA30(position, 50, 1, 0, 0x10000, moby);
        if (retained) {
            register int firstHeading __asm__("$2") =
                func_8004E880(((Moby*)retained)->position.x - moby->position.x,
                              ((Moby*)retained)->position.y - moby->position.y, 0);
            {
                register int zero __asm__("$6") = 0;
                int deltaHeading;
                __asm__("" : "=r"(zero) : "0"(zero), "r"(firstHeading));
                heading = firstHeading;
                deltaHeading = func_8004E880(tag->delta.x, tag->delta.y, zero);
                ((unsigned char*)retained)[0x51] = func_800360F8(heading, deltaHeading, 32, 64);
            }
        }
        if (func_800359A4(&tag->timer, 4) || retained || ({
                int collided;
                /* The collision pointer is already tested and dead here.
                     * Retail passes a fresh zero rather than reusing that register.
                     * This clobber emits no instruction. */
                MATCHING_BARRIER("$17");
                collided = func_8001830C(&work.oldPosition, position, 0, 0x10000, moby);
                collided;
            })) {
            tag->delta.x = 0;
            tag->delta.y = 0;
            tag->delta.z = 0;
            func_8004F178(&moby->position, &work.oldPosition);
            moby->state = 98;
        }
        {
            register int result __asm__("$2") = func_8004E880(tag->delta.x, tag->delta.y, 0);
            register int low __asm__("$4") = 0;
            register int high __asm__("$5") = 14;
            __asm__("" : "=r"(low), "=r"(high) : "0"(low), "1"(high), "r"(result));
            heading = result;
            heading += func_800363DC(low, high);
        }
        opposite = heading;
        MATCHING_OBSERVE_VOLATILE(opposite);
        retained = &work.particlePosition;
        func_8004F178(retained, &moby->position);
        /* Preserve both signed table lanes and the raw particle packet writes. */
        {
            register int primaryIndex __asm__("$3") = opposite & 255;
            register int oppositeIndex __asm__("$7");
            register int cosine __asm__("$5");
            register int kind __asm__("$4");
            register int selector __asm__("$5");
            register Vector3D* positionArg __asm__("$6");
            register char* (*spawn)(int, int, Vector3D*, Vector3D*)__asm__("$8");
            MATCHING_KEEP(primaryIndex);
            opposite = heading - 128;
            MATCHING_KEEP(opposite);
            primaryIndex *= 2;
            kind = 1;
            MATCHING_KEEP(kind);
            oppositeIndex = (opposite & 255) * 2;
            MATCHING_KEEP2(primaryIndex, oppositeIndex);
            cosine = *(short*)((char*)D_80065920 + primaryIndex);
            spawn = SpawnParticle;
            MATCHING_KEEP2(cosine, spawn);
            work.direction.x = (cosine * 15) >> 11;
            {
                register int sine __asm__("$3") = *(short*)((char*)D_800658A0 + primaryIndex);
                MATCHING_KEEP(sine);
                positionArg = retained;
                MATCHING_KEEP(positionArg);
                work.direction.z = 0;
                MATCHING_BARRIER_VOLATILE("memory");
                work.direction.y = (sine * 15) >> 11;
            }
            {
                register int sample __asm__("$3") = *(short*)((char*)D_80065920 + oppositeIndex);
                MATCHING_KEEP_CLOBBER(sample, "$5");
                selector = 13;
                __asm__("" : "=r"(selector) : "0"(selector), "r"(sample));
                work.particlePosition.x += (sample * 5) >> 9;
            }
            {
                register int sample __asm__("$2") = *(short*)((char*)D_800658A0 + oppositeIndex);
                register int product __asm__("$3") = sample * 5;
                MATCHING_KEEP(product);
                work.particlePosition.y += product >> 9;
            }
            particle = spawn(kind, selector, positionArg, &work.direction);
        }
        particle[2] = 14;
        particle[10] += 56;
    }
done:
    if (moby->state != 98)
        return;
cleanup:
    func_80055B18(moby);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_28/moby", D_level_28_800745D8);

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Actor8007B874ExpandSignedHalfwordVector(void*, void*) __asm__("func_8004F554");
int Actor8007B874NarrowWordVectorToHalfwords(void*, void*) __asm__("func_8004F570");
extern unsigned char Actor8007B874D_800676E8[] __asm__("D_800676E8");
extern int Actor8007B874D_8006C58C __asm__("D_8006C58C");
extern int Actor8007B874D_8006C5C8 __asm__("D_8006C5C8");
#define Actor8007B874Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor8007B874TestSubdividedSegmentPath(void*, void*, int) __asm__("func_80013E38");
int Actor8007B874QueryWorldSphere(void*, int) __asm__("func_80019194");
int Actor8007B874QueryWorldHeight(void*, int) __asm__("func_8001A358");
void* Actor8007B874AllocatePoolRecord16(int) __asm__("func_8002F040");
int Actor8007B874WriteGlobalVectorAnglePair(void*) __asm__("func_80036188");
int Actor8007B874AwardMobyCollectionValue(void*) __asm__("func_80036E60");
int Actor8007B874PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Actor8007B874PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Actor8007B874TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Actor8007B874MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
int Actor8007B874ComputeVectorPlaneResponse(void*, void*, void*) __asm__("func_8004EF74");
int Actor8007B874ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Actor8007B874CopyVector(void*, void*) __asm__("func_8004F178");
int Actor8007B874AddVector(void*, void*, void*) __asm__("func_8004F194");
int Actor8007B874SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Actor8007B874MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Actor8007B874DivideVector(void*, void*, int) __asm__("func_8004F228");
int Actor8007B874ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Actor8007B874DeleteMoby(void*) __asm__("func_80055B18");
int Actor8007B874RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Actor8007B874RefreshMobyQueryByte52(void*) __asm__("func_80056270");
int Actor8007B874RefreshMobyPackedQueryField(void*) __asm__("func_8005629C");
extern int Actor8007B874D_80065810 __asm__("D_80065810");
extern int Actor8007B874D_80065818 __asm__("D_80065818");
extern unsigned char Actor8007B874D_800658A0[] __asm__("D_800658A0");
extern unsigned char Actor8007B874D_80065920[] __asm__("D_80065920");
extern unsigned char Actor8007B874D_80066964[] __asm__("D_80066964");
extern unsigned char Actor8007B874D_80066988[] __asm__("D_80066988");
extern unsigned char Actor8007B874D_80066990[] __asm__("D_80066990");
extern unsigned char Actor8007B874D_80066A48[] __asm__("D_80066A48");
extern int Actor8007B874D_8006C648 __asm__("D_8006C648");
extern void* Actor8007B874D_8006C65C __asm__("D_8006C65C");
extern unsigned char Actor8007B874D_8006DEF8[] __asm__("D_8006DEF8");
extern int Actor8007B874D_8006E020 __asm__("D_8006E020");
extern int Actor8007B874D_8006E024 __asm__("D_8006E024");
extern unsigned short Actor8007B874D_8006E040 __asm__("D_8006E040");
extern unsigned char Actor8007B874D_80070328[] __asm__("D_80070328");
extern int Actor8007B874D_80071908 __asm__("D_80071908");
extern unsigned char Actor8007B874D_80071918[] __asm__("D_80071918");
extern int Actor8007B874D_8007192C __asm__("D_8007192C");
extern int (*Actor8007B874SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
void func_level_28_8007B874(void* input) {
    struct {
        struct {
            int x, y, z;
        } first;
        int p1C;
        struct {
            int x, y, z;
        } fifth;
        int p2C;
        struct {
            int x, y, z;
        } sixth;
        int p3C;
        struct {
            int x, y, z;
        } seventh;
        int p4C;
        struct {
            int x, y, z;
        } delta;
        int p5C;
        struct {
            int x, y, z;
        } eighth;
        int p6C;
        int pad70[4];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
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
    register unsigned char* tag __asm__("$18");
    register unsigned char* callbackTag __asm__("$17");
    void* callbackOwnerReference;
    void* temp_v1_6;

    workingPosition = owner + 0xC;
    tag = ((Moby*)owner)->mobyTag;
    temp_v0 = Actor8007B874ApproximatePlanarDistance(workingPosition, Actor8007B874D_80070328);
    {
        register int old3 __asm__("$3") = Actor8007B874Field(tag, short*, 0xA);
        register int old __asm__("$4");
        register int predicate __asm__("$3");
        MATCHING_KEEP2(old3, temp_v0);
        old = old3;
        predicate = old3 < 0x218;
        MATCHING_KEEP3(old, predicate, temp_v0);
        distanceResult = temp_v0;
        if (predicate) {
            temp_v0 = Actor8007B874D_8006C648;
            temp_v0 = old + temp_v0;
            Actor8007B874Field(tag, short*, 0xA) = temp_v0;
        } else {
            selectedResource = Actor8007B874AllocatePoolRecord16(((Moby*)owner)->substate);
            if (selectedResource != 0) {
                if (distanceResult < 0x3000) {
                    Actor8007B874Field(tag, unsigned char*, 0x13) =
                        (unsigned char)((int)(selectedResource - Actor8007B874D_8006DEF8) >> 4);
                    Actor8007B874Field(tag, short*, 0xA) =
                        (short)((unsigned short)Actor8007B874Field(tag, short*, 0xA) - 0x20);
                    Actor8007B874Field(tag, unsigned char*, 0x14) =
                        (unsigned char)((((Moby*)owner)->substate * 2) + (rand() & 1));
                } else {
                    Actor8007B874CopyVector(selectedResource, workingPosition);
                    if (distanceResult <= 0x7FFF) {
                        Actor8007B874Field(tag, short*, 0xA) =
                            (short)((unsigned short)Actor8007B874Field(tag, short*, 0xA) - 0x80);
                        Actor8007B874Field(selectedResource, int*, 8) =
                            (int)(Actor8007B874Field(selectedResource, int*, 8) + 0x80);
                    } else {
                        Actor8007B874Field(tag, short*, 0xA) =
                            (short)((unsigned short)Actor8007B874Field(tag, short*, 0xA) - 0x100);
                    }
                    Actor8007B874Field(tag, unsigned char*, 0x13) = 0xFFU;
                }
                Actor8007B874Field(selectedResource, unsigned char*, 0xD) =
                    (unsigned char)(Actor8007B874Field(selectedResource, unsigned char*, 0xD) +
                                    (rand() & 0x3F));
            } else {
                Actor8007B874Field(tag, short*, 0xA) =
                    (short)((unsigned short)Actor8007B874Field(tag, short*, 0xA) - 0x100);
            }
            Actor8007B874Field(tag, short*, 0xA) =
                (short)((unsigned short)Actor8007B874Field(tag, short*, 0xA) - (rand() & 0xFF));
        }
    }
    temp_s0 = Actor8007B874Field(tag, unsigned char*, 0x13);
    MATCHING_KEEP(temp_s0);
    selectorOwner = owner;
    if (temp_s0 < 0x10U) {
        MATCHING_KEEP(selectorOwner);
        selectorMode = 4;
        MATCHING_KEEP(selectorMode);
        temp_s0 *= 16;
        MATCHING_KEEP_CLOBBER(temp_s0, "$2");
        {
            register unsigned char* base __asm__("$2") = Actor8007B874D_8006DEF8;
            resourceRecord = (unsigned char*)(temp_s0 + (int)base);
        }
        Actor8007B874RefreshMobySpatialGridAndBasis(selectorOwner, selectorMode);
        Actor8007B874CopyVector(resourceRecord,
                                (Actor8007B874Field(tag, unsigned char*, 0x14) * 0xC) +
                                    (Actor8007B874D_80066A48 + 0x30));
        Actor8007B874MultiplyVectorGpfSf0(resourceRecord, resourceRecord, 2);
        Actor8007B874TransformVectorByBasis(owner + 0x20, resourceRecord, resourceRecord);
        Actor8007B874AddVector(resourceRecord, resourceRecord, owner + 0xC);
        if ((unsigned char)Actor8007B874Field(resourceRecord, unsigned char*, 0xC) < 4U) {
            Actor8007B874Field(tag, unsigned char*, 0x13) = 0xFFU;
        }
    }
    if ((((Moby*)owner)->drawn != 0) || (distanceResult < 0x1801) || (((Moby*)owner)->state != 1) ||
        (Actor8007B874Field(tag, unsigned char*, 0x11) != 0)) {
        {
            register unsigned char* base __asm__("$4") = Actor8007B874D_800676E8;
            register int row __asm__("$3");
            register int column __asm__("$2");
            register int height __asm__("$3");
            __asm__("" : "=r"(base) : "0"(base) : "$3", "$2");
            row = Actor8007B874D_8006C58C;
            column = Actor8007B874D_8006C5C8;
            MATCHING_KEEP2(row, column);
            row = row * 16 + (int)base;
            MATCHING_KEEP(row);
            column = column * 4 + row;
            MATCHING_KEEP_CLOBBER(column, "$3");
            height = ((Moby*)owner)->position.z;
            column = *(int*)column;
            if (column >= height) {
                Actor8007B874CopyVector(owner + 0xC, Actor8007B874D_80070328);
            }
        }
        temp_v1 = ((Moby*)owner)->state;
        switch (temp_v1) { /* switch 1; irregular */
            case 0:        /* switch 1 */
                Actor8007B874CopyVector(&frame.first.x, owner + 0xC);
                frame.first.z += 0x400;
                Actor8007B874QueryWorldHeight(&frame.first.x, 0x10000);
                Actor8007B874WriteGlobalVectorAnglePair(tag + 0xE);
                if (Actor8007B874Field(tag, int*, 0xC) & 0xFFFF0000) {
                    ((Moby*)owner)->angle.yaw = 0U;
                }
                ((Moby*)owner)->position.z = (int)Actor8007B874D_80071908;
                Actor8007B874Field(tag, short*, 0xA) = (short)((rand() & 0xFF) + 0x100);
                ((Moby*)owner)->state = 1U;
                temp_v0_2 = *(Actor8007B874D_80066964 + ((Moby*)owner)->gemValue);
                ((Moby*)owner)->substate = temp_v0_2;
                ((Moby*)owner)->animationState.id =
                    (unsigned char)*(Actor8007B874D_80066988 + (temp_v0_2 & 0xFF));
                ((Moby*)owner)->colour.r =
                    (unsigned char)*(Actor8007B874D_80066990 + ((Moby*)owner)->substate);
                goto block_75;
            case 1: /* switch 1 */
                if (Actor8007B874Field(tag, short*, 0xA) >= 0x1E) {
                    MATCHING_KEEP_VOLATILE_CLOBBER(distanceResult, "$4");
                    temp_a0 = Actor8007B874Field(Actor8007B874D_80070328, int*, 0x44);
                    if (({
                            register int pred __asm__("$2") = distanceResult < temp_a0 + 0x180;
                            MATCHING_KEEP(pred);
                            pred;
                        })) {
                        temp_v1_3 = Actor8007B874Field(Actor8007B874D_80070328, int*, 8) -
                                    ((Moby*)owner)->position.z;
                        if (temp_v1_3 < temp_a0 + 0x80) {
                            var_v0_2 = -Actor8007B874Field(Actor8007B874D_80070328, int*, 0x44);
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_v0_2, "$6");
                            var_v0_2 = var_v0_2 < temp_v1_3;
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_v0_2, "memory");
                            if (!var_v0_2)
                                goto block_75;
                            goto block_70;
                        }
                    }
                }
                goto block_75;
            case 2: /* switch 1 */
                workingPosition = (unsigned char*)&frame.fifth.x;
                Actor8007B874ExpandSignedHalfwordVector(workingPosition, tag + 4);
                Actor8007B874MultiplyVectorGpfSf0(workingPosition, workingPosition,
                                                  Actor8007B874D_8006C648);
                Actor8007B874ShiftVectorRightTowardZero(workingPosition, 1);
                {
                    register void* first __asm__("$4") = workingPosition;
                    MATCHING_KEEP_CLOBBER(first, "$20");
                    ownerPosition = owner + 12;
                    Actor8007B874AddVector(first, ownerPosition, workingPosition);
                }
                temp_v0_4 = Actor8007B874Field(tag, short*, 8);
                MATCHING_KEEP(temp_v0_4);
                {
                    register int old __asm__("$4") = temp_v0_4;
                    temp_v0_4 = temp_v0_4 < -215;
                    if (!temp_v0_4) {
                        register int delta __asm__("$3") = Actor8007B874D_8006C648;
                        register int product __asm__("$2");
                        MATCHING_KEEP2(old, delta);
                        product = delta * 5;
                        product = old - product;
                        Actor8007B874Field(tag, short*, 8) = product;
                    }
                }
                if (frame.fifth.z < 0x400) {
                    Actor8007B874AwardMobyCollectionValue(owner);
                    Actor8007B874DeleteMoby(owner);
                    return;
                }
                frame.fifth.z += 0xF0;
                if (Actor8007B874QueryWorldSphere(workingPosition, 0xF0) != 0) {
                    stateTwoNormal = &frame.sixth.x;
                    MATCHING_KEEP(stateTwoNormal);
                    Actor8007B874CopyVector(stateTwoNormal, Actor8007B874D_80071918);
                    Actor8007B874CopyVector(ownerPosition, Actor8007B874D_80071918 - 0xC);
                    ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z - 0xF0);
                    if (Actor8007B874Field(tag, unsigned char*, 0x12) == 0) {
                        {
                            register int height __asm__("$2") =
                                Actor8007B874QueryWorldHeight(workingPosition, 0x400);
                            register void* first __asm__("$4") = stateTwoNormal;
                            register int zero __asm__("$5") = 0;
                            register int magnitude __asm__("$5");
                            register int signedAngle __asm__("$2");
                            MATCHING_KEEP2_CLOBBER(first, zero, "$16");
                            sampledHeight = height;
                            magnitude = Actor8007B874MeasureVectorLength(first, zero);
                            signedAngle =
                                Actor8007B874PlanarHeadingLookup(frame.sixth.z, magnitude, 0);
                            signedAngle <<= 24;
                            MATCHING_KEEP(signedAngle);
                            signedAngleResult = signedAngle >> 24;
                        }
                        if (((frame.fifth.z - 0x190) < sampledHeight) &&
                            (signedAngleResult < 0x18)) {
                            ((Moby*)owner)->state = 1U;
                            Actor8007B874CopyVector(ownerPosition, workingPosition);
                            ((Moby*)owner)->position.z = sampledHeight;
                            Actor8007B874WriteGlobalVectorAnglePair(tag + 0xE);
                            if (Actor8007B874Field(tag, int*, 0xC) & 0xFFFF0000) {
                                ((Moby*)owner)->angle.yaw = 0U;
                            }
                            Actor8007B874Field(owner, signed char*, 0x52) = 0;
                            Actor8007B874RefreshMobyQueryByte52(owner);
                            Actor8007B874RefreshMobyPackedQueryField(owner);
                        } else {
                            Actor8007B874Field(tag, unsigned char*, 0x12) =
                                (unsigned char)(Actor8007B874Field(tag, unsigned char*, 0x12) + 1);
                        }
                        if (Actor8007B874Field(tag, unsigned char*, 0x12) != 0) {
                            goto block_52;
                        }
                    } else {
                    block_52:
                        stateThreeDelta = &frame.seventh.x;
                        {
                            register void* arg __asm__("$4") = stateThreeDelta;
                            MATCHING_KEEP_CLOBBER(arg, "$19");
                            workingPosition = tag + 4;
                            Actor8007B874ExpandSignedHalfwordVector(arg, workingPosition);
                        }
                        {
                            register int result __asm__("$2") =
                                Actor8007B874ComputeVectorPlaneResponse(
                                    &frame.seventh.x, &frame.sixth.x, &frame.seventh.x);
                            register void* arg __asm__("$4") = workingPosition;
                            if (result != 0) {
                                Actor8007B874Field(tag, unsigned char*, 0x12) =
                                    (unsigned char)(Actor8007B874Field(tag, unsigned char*, 0x12) -
                                                    1);
                                frame.seventh.x = (frame.seventh.x >> 3) + (rand() & 0x3F) - 0x20;
                                frame.seventh.y = (frame.seventh.y >> 3) + (rand() & 0x3F) - 0x20;
                                frame.seventh.z = (frame.seventh.z >> 2) + (rand() & 0xF);
                                Actor8007B874PlayMobySoundEvent(owner, 1, 0);
                            }
                            Actor8007B874NarrowWordVectorToHalfwords(workingPosition,
                                                                     stateThreeDelta);
                        }
                    }
                } else {
                    frame.fifth.z -= 0xF0;
                    Actor8007B874CopyVector(ownerPosition, workingPosition);
                    Actor8007B874QueryWorldHeight(workingPosition, 0x10000);
                    Actor8007B874RefreshMobyPackedQueryField(owner);
                }
                MATCHING_BARRIER_VOLATILE("memory");
                if (Actor8007B874Field(tag, short*, 0xA) >= 0x1E) {
                    MATCHING_KEEP_VOLATILE_CLOBBER(distanceResult, "$5");
                    temp_a0_2 = Actor8007B874Field(Actor8007B874D_80070328, int*, 0x44) + 0x80;
                    if (({
                            register int pred __asm__("$2") = distanceResult < temp_a0_2;
                            MATCHING_KEEP(pred);
                            pred;
                        })) {
                        temp_v1_4 = Actor8007B874Field(Actor8007B874D_80070328, int*, 8) -
                                    ((Moby*)owner)->position.z;
                        if (temp_v1_4 < temp_a0_2) {
                            var_v0_2 = -Actor8007B874Field(Actor8007B874D_80070328, int*, 0x44);
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_v0_2, "$7");
                            var_v0_2 = var_v0_2 < temp_v1_4;
                            MATCHING_KEEP_VOLATILE_CLOBBER(var_v0_2, "memory");
                            if (!var_v0_2)
                                goto block_75;
                            goto block_70;
                        }
                    }
                }
                goto block_75;
            case 3: /* switch 1 */
                stateThreeVector = &frame.eighth.x;
                MATCHING_KEEP(stateThreeVector);
                Actor8007B874ExpandSignedHalfwordVector(stateThreeVector, tag + 4);
                if (Actor8007B874Field(tag, short*, 0xA) >= 30) {
                    Actor8007B874CopyVector(owner + 0xC, Actor8007B874D_80070328);
                } else {
                    stateThreeDelta = &frame.delta.x;
                    MATCHING_KEEP_CLOBBER(stateThreeDelta, "$20");
                    {
                        register void* first __asm__("$4") = stateThreeDelta;
                        MATCHING_KEEP_CLOBBER(first, "$20");
                        savedPlayer = Actor8007B874D_80070328;
                        Actor8007B874SubtractVector(first, savedPlayer, stateThreeVector);
                    }
                    Actor8007B874DivideVector(stateThreeDelta, stateThreeDelta, 30);
                    if (Actor8007B874MeasureVectorLength(stateThreeDelta, 1) >= 0x1E1) {
                        Actor8007B874CopyVector(owner + 12, savedPlayer);
                        Actor8007B874Field(tag, short*, 0xA) = 30;
                    } else {
                        Actor8007B874MultiplyVectorGpfSf0(stateThreeDelta, stateThreeDelta,
                                                          Actor8007B874Field(tag, short*, 0xA));
                        Actor8007B874AddVector(owner + 0xC, stateThreeVector, stateThreeDelta);
                        ((Moby*)owner)->position.z =
                            (int)(((Moby*)owner)->position.z +
                                  (short)((short)*(unsigned short*)(Actor8007B874D_800658A0 +
                                                                    (Actor8007B874Field(tag, short*,
                                                                                        0xA) *
                                                                     8)) /
                                          10));
                    }
                }
                {
                    register int offset __asm__("$2") =
                        Actor8007B874Field(tag, unsigned char*, 0xE);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = ((Moby*)owner)->angle.roll;
                    offset += 249;
                    old += offset;
                    ((Moby*)owner)->angle.roll = old;
                }
                {
                    register int offset __asm__("$2") =
                        Actor8007B874Field(tag, unsigned char*, 0xF);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = ((Moby*)owner)->angle.pitch;
                    offset += 249;
                    old += offset;
                    ((Moby*)owner)->angle.pitch = old;
                }
                {
                    register int offset __asm__("$2") =
                        Actor8007B874Field(tag, unsigned char*, 0x10);
                    register int old __asm__("$3");
                    MATCHING_KEEP_CLOBBER(offset, "$3");
                    old = ((Moby*)owner)->angle.yaw;
                    offset += 249;
                    old += offset;
                    ((Moby*)owner)->angle.yaw = old;
                }
                if ((Actor8007B874Field(tag, short*, 0xA) < 0x1E) ||
                    (temp_a0_3 = Actor8007B874Field(Actor8007B874D_80070328, int*, 0x44) + 0x80,
                     ((({
                          register int pred __asm__("$2") = distanceResult < temp_a0_3;
                          MATCHING_KEEP(pred);
                          pred;
                      })) == 0)) ||
                    (temp_v1_5 = Actor8007B874Field(Actor8007B874D_80070328, int*, 8) -
                                 ((Moby*)owner)->position.z,
                     ((temp_v1_5 < temp_a0_3) == 0)) ||
                    (-Actor8007B874Field(Actor8007B874D_80070328, int*, 0x44) >= temp_v1_5)) {
                    var_v0_2 = Actor8007B874Field(tag, short*, 0xA) < 65;
                    if (!var_v0_2)
                        ((Moby*)owner)->state = 4;
                    goto block_75;
                }
                goto block_70;
            block_70:
                ((Moby*)owner)->state = 4;
                goto block_75;
            case 4: /* switch 1 */
                Actor8007B874RefreshMobySpatialGridAndBasis(owner, 4);
                Actor8007B874SpawnParticle(4, 12, owner, ((Moby*)owner)->substate);
                Actor8007B874SpawnParticle(4, 12, owner, ((Moby*)owner)->substate);
                Actor8007B874AwardMobyCollectionValue(owner);
                Actor8007B874PlayMobySoundEvent(owner, 0, 0);
                Actor8007B874DeleteMoby(owner);
                goto block_75;
        }
    block_75:
        if ((unsigned char)((Moby*)owner)->state < 3U) {

                {
                register int sample __asm__("$2") =
                    *(unsigned short*)(Actor8007B874D_80065920 +
                                       (Actor8007B874Field(tag, unsigned char*, 0x10) * 2));
                register int base __asm__("$3");
                MATCHING_KEEP_CLOBBER(sample, "$3");
                base = Actor8007B874Field(tag, unsigned char*, 0xE);
                MATCHING_KEEP2(sample, base);
                sample = (sample << 16) >> 23;
                sample += base;
                ((Moby*)owner)->angle.roll = sample;
            }
            {
                register int sample __asm__("$2") =
                    *(unsigned short*)(Actor8007B874D_800658A0 +
                                       (Actor8007B874Field(tag, unsigned char*, 0x10) * 2));
                register int base __asm__("$3");
                MATCHING_KEEP_CLOBBER(sample, "$3");
                base = Actor8007B874Field(tag, unsigned char*, 0xF);
                MATCHING_KEEP2(sample, base);
                sample = (sample << 16) >> 23;
                sample += base;
                ((Moby*)owner)->angle.pitch = sample;
            }
            Actor8007B874Field(tag, unsigned char*, 0x10) =
                (unsigned char)(Actor8007B874Field(tag, unsigned char*, 0x10) +
                                (Actor8007B874D_8006C648 * 2));
        }
    }
}
#undef Actor8007B874Field


/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level18 8007CC40 / level28 8007C200 / level48 8007C228.
 * Each original contains483 instructions plus20 owned switch/padding words.
 * Offset names describe observed storage; helper contracts, physical units,
 * actor meanings and caller cadence remain unresolved. Preserve pool stride88,
 * signed-halfword handle/selectors, byte stores, pointer rereads, distinct
 * switch paths and the signed quotient/subtract remainder chain. Compiler
 * constraints are empty and emit no CPU instructions. Linked original words,
 * all hashes and owned switch targets/padding are acceptance requirements.
 */
#define P7CC40Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int P7CC40SyncHudCounterTarget() __asm__("func_80027A60");
int P7CC40SnapHudCounterToSource() __asm__("func_80027AC0");
int P7CC40InitializeHudDecimalCounterLayout() __asm__("func_80027E40");
int P7CC40ConfigureHudEntry() __asm__("func_8002803C");
int P7CC40ResetHudEntryByHandle() __asm__("func_80028154");
int P7CC40DrawHudIconAndDecimalCounter() __asm__("func_80029904");
int P7CC40SetMobyAnimation() __asm__("func_80034F80");
int P7CC40CountTimerDown() __asm__("func_800359A4");
int P7CC40UpdateMobyWanderMotion() __asm__("func_80037168");
int P7CC40TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int P7CC40SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int P7CC40ApproximatePlanarDistance() __asm__("func_8004F334");
int P7CC40DeleteMoby() __asm__("func_80055B18");
extern unsigned int P7CC40D_8006C550 __asm__("D_8006C550");
extern unsigned int P7CC40D_8006C704 __asm__("D_8006C704");
extern int P7CC40D_8006C640 __asm__("D_8006C640");
extern int P7CC40D_8006C770 __asm__("D_8006C770");
extern unsigned char P7CC40D_8006EE2C[] __asm__("D_8006EE2C");
extern unsigned char P7CC40D_80070328[] __asm__("D_80070328");
extern void* P7CC40unk_ovlheader_800743B8 __asm__("unk_ovlheader_800743B8");
extern void* P7CC40unk_ovlheader_800743BC __asm__("unk_ovlheader_800743BC");
extern void* P7CC40unk_ovlheader_800743C0 __asm__("unk_ovlheader_800743C0");
extern void* (*P7CC40SpawnParticle)() __asm__("SpawnParticle");
void func_level_28_8007C200(void* owner) {
    register void* helperCallback7 __asm__("$7");
    register int helperSelector5 __asm__("$5");
    register int helperKind4 __asm__("$4");
    register void* helperProducer6 __asm__("$6");
    register void* tablePointer2 __asm__("$2");
    register unsigned int tableByte2 __asm__("$2");
    register int particleArgument7 __asm__("$7");
    register int particleKind4 __asm__("$4");
    register int particleSelector5 __asm__("$5");
    register void* particleOwner6 __asm__("$6");
    register void* (*particleCallback2)() __asm__("$2");
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_5;
    int temp_a0_6;
    int temp_a0_7;
    short colorCaseHalfword;
    short particleCaseHalfword;
    short temp_v1;
    int temp_a0;
    register int tickRemainder4 __asm__("$4");
    int temp_v0_2;
    register int quotient3 __asm__("$3");
    int var_v0;
    int var_v1_2;
    register int colorWord2 __asm__("$2");
    register int colorWord3 __asm__("$3");
    register int case3Result2 __asm__("$2");
    register int case3Halfword3 __asm__("$3");
    register int payloadWord2 __asm__("$2");
    register void* payloadHeader3 __asm__("$3");
    register int payloadLimit8 __asm__("$8");
    register unsigned int poolCursor3 __asm__("$3");
    register unsigned int poolEnd4 __asm__("$4");
    register int poolType5 __asm__("$5");
    unsigned char ownerStateByte48;
    void* linkedPrivate;
    void* privateState;
    void* temp_v0;
    void* privateWord44Address;

    privateState = ((Moby*)owner)->mobyTag;
    if (P7CC40Field(P7CC40D_80070328, int*, 0x250) != 0) {
        if (((Moby*)owner)->state == 2) {
            ((Moby*)owner)->unknown3[0] = 0;
            ((Moby*)owner)->lowDrawDistance = 0;
            ((Moby*)owner)->drawn = 0;
            temp_v0 = P7CC40Field(privateState, void**, 0x4C);
            if (temp_v0 != 0) {
                P7CC40Field(temp_v0, unsigned char*, 0x41) = 0;
                P7CC40Field(P7CC40Field(privateState, void**, 0x4C), unsigned char*, 0x4C) = 0;
                P7CC40Field(P7CC40Field(privateState, void**, 0x4C), unsigned char*, 0x4D) = 0;
            }
            temp_a0 = P7CC40Field(privateState, int*, 0x50);
            if (temp_a0 != 0) {
                P7CC40DeleteMoby(temp_a0);
                P7CC40Field(privateState, int*, 0x50) = 0;
            }
            goto exitFunction;
        foundPool:
            P7CC40Field(privateState, unsigned int*, 0x48) = poolCursor3;
            goto poolReady;
        } else {
            privateWord44Address = privateState + 0x44;
            if (P7CC40Field(privateState, short*, 0xE) == 0) {
                P7CC40Field(privateState, short*, 0xE) = 1;
                if (((Moby*)owner)->animationState.id != 0) {
                    tablePointer2 = *(void**)(P7CC40D_8006EE2C + ((Moby*)owner)->mobyClass * 4);
                    tablePointer2 = P7CC40Field(tablePointer2, void**, 0x3C);
                    MATCHING_KEEP(tablePointer2);
                    P7CC40D_8006C770 = 0;
                    tableByte2 = *(unsigned char*)tablePointer2;
                    MATCHING_KEEP(tableByte2);
                    ((Moby*)owner)->animationState.id = 0;
                    ((Moby*)owner)->animationState.nextId = 0;
                    ((Moby*)owner)->animationState.frame = 0;
                    ((Moby*)owner)->animationState.nextFrame = 1;
                    MATCHING_KEEP_CLOBBER(tableByte2, "memory");
                    tableByte2 = tableByte2 < 2U;
                    MATCHING_KEEP(tableByte2);
                    tableByte2 ^= 1;
                    tableByte2 = -tableByte2;
                    tableByte2 &= 0x30;
                    ((Moby*)owner)->animationProgress = tableByte2;
                }
                poolCursor3 = P7CC40D_8006C550;
                poolEnd4 = P7CC40D_8006C704;
                poolType5 = 0x170;
                if (poolCursor3 < poolEnd4) {
                scanPool:
                    if (P7CC40Field(poolCursor3, short*, 0x36) != poolType5) {
                        poolCursor3 += 0x58;
                        if (poolCursor3 < poolEnd4) {
                            goto scanPool;
                        }
                    } else {
                        goto foundPool;
                    }
                }
            poolReady:
                privateWord44Address = privateState + 0x44;
            }
            linkedPrivate = *P7CC40Field(privateState, void***, 0x48);
            if (P7CC40CountTimerDown(privateWord44Address, 4) == 2) {
                temp_v1 = P7CC40Field(privateState, short*, 0xC);
                switch (temp_v1) {
                    case 0:
                        temp_v0_2 = P7CC40Field(linkedPrivate, int*, 0x28) + 2;
                        P7CC40Field(linkedPrivate, int*, 0x28) = temp_v0_2;
                        if (temp_v0_2 >= 7) {
                            P7CC40Field(linkedPrivate, int*, 0x28) = 6;
                            default:
                        }
                        break;
                    case 1:
                        temp_a0_2 = P7CC40Field(linkedPrivate, short*, 0x36);
                        P7CC40Field(linkedPrivate, int*, 0x1C) =
                            (int)(P7CC40Field(linkedPrivate, int*, 0x1C) & ~0x1E);
                        if (temp_a0_2 != -1) {
                            P7CC40ResetHudEntryByHandle(temp_a0_2);
                        }
                        helperKind4 = 0x12;
                        helperSelector5 = 0xB7;
                        helperProducer6 = (void*)&P7CC40InitializeHudDecimalCounterLayout;
                        helperCallback7 = &P7CC40SyncHudCounterTarget;
                        MATCHING_KEEP4(helperKind4, helperSelector5, helperProducer6,
                                       helperCallback7);
                        var_v1_2 = 9;
                        P7CC40Field(linkedPrivate, int*, 0x20) = 9;
                        var_v0 = P7CC40Field(linkedPrivate, int*, 0x1C) | 8;
                        goto createWord20Handle;
                    case 2:
                        temp_a0_3 = P7CC40Field(linkedPrivate, short*, 0x34);
                        P7CC40Field(linkedPrivate, int*, 0x1C) =
                            (int)(P7CC40Field(linkedPrivate, int*, 0x1C) & ~0x21);
                        if (temp_a0_3 != -1) {
                            P7CC40ResetHudEntryByHandle(temp_a0_3);
                        }
                        helperKind4 = 0x14;
                        helperSelector5 = 0xB6;
                        helperProducer6 = P7CC40unk_ovlheader_800743B8;
                        helperCallback7 = P7CC40unk_ovlheader_800743C0;
                        MATCHING_KEEP4(helperKind4, helperSelector5, helperProducer6,
                                       helperCallback7);
                        payloadWord2 = P7CC40Field(linkedPrivate, int*, 0x1C);
                        payloadHeader3 = P7CC40unk_ovlheader_800743BC;
                        payloadLimit8 = 0x5DC;
                        P7CC40Field(linkedPrivate, int*, 0x24) = payloadLimit8;
                        payloadWord2 |= 1;
                        P7CC40Field(linkedPrivate, int*, 0x1C) = payloadWord2;
                        P7CC40Field(linkedPrivate, short*, 0x34) = P7CC40ConfigureHudEntry(
                            helperKind4, helperSelector5, helperProducer6, helperCallback7,
                            payloadHeader3, linkedPrivate + 0x24, payloadLimit8);
                        if (P7CC40SoundHandleMatchesOwnerInStates1Or2(
                                (void**)P7CC40Field(privateState, unsigned int*, 0x48),
                                P7CC40Field(linkedPrivate, int*, 0x48)) != 0) {
                            if (P7CC40SoundHandleMatchesOwnerInStates1Or2(
                                    (void**)P7CC40Field(privateState, unsigned int*, 0x48),
                                    P7CC40Field(linkedPrivate, int*, 0x48)) != 0) {
                                P7CC40TransitionSoundHandleTo3Or5(
                                    P7CC40Field(linkedPrivate, int*, 0x48));
                            }
                            P7CC40Field(linkedPrivate, int*, 0x48) = -1;
                        }
                        break;
                    case 3:
                        temp_a0_4 = P7CC40Field(linkedPrivate, short*, 0x36);
                        P7CC40Field(linkedPrivate, int*, 0x1C) =
                            (int)(P7CC40Field(linkedPrivate, int*, 0x1C) & ~0x1E);
                        if (temp_a0_4 != -1) {
                            P7CC40ResetHudEntryByHandle(temp_a0_4);
                        }
                        helperKind4 = 0x12;
                        helperSelector5 = 0xB8;
                        helperProducer6 = (void*)&P7CC40InitializeHudDecimalCounterLayout;
                        helperCallback7 = &P7CC40SyncHudCounterTarget;
                        MATCHING_KEEP4(helperKind4, helperSelector5, helperProducer6,
                                       helperCallback7);
                        var_v1_2 = 9;
                        P7CC40Field(linkedPrivate, int*, 0x20) = 9;
                        var_v0 = P7CC40Field(linkedPrivate, int*, 0x1C) | 4;
                        goto createWord20Handle;
                    case 4:
                        temp_a0_5 = P7CC40Field(linkedPrivate, short*, 0x36);
                        P7CC40Field(linkedPrivate, int*, 0x1C) =
                            (int)(P7CC40Field(linkedPrivate, int*, 0x1C) & ~0x1E);
                        if (temp_a0_5 != -1) {
                            P7CC40ResetHudEntryByHandle(temp_a0_5);
                        }
                        helperKind4 = 0x12;
                        helperSelector5 = 0xB5;
                        helperProducer6 = (void*)&P7CC40InitializeHudDecimalCounterLayout;
                        helperCallback7 = &P7CC40SnapHudCounterToSource;
                        MATCHING_KEEP4(helperKind4, helperSelector5, helperProducer6,
                                       helperCallback7);
                        var_v1_2 = 0x12C;
                        P7CC40Field(linkedPrivate, int*, 0x20) = 0x12C;
                        var_v0 = P7CC40Field(linkedPrivate, int*, 0x1C) | 2;
                        goto createWord20Handle;
                    case 5:
                        temp_a0_6 = P7CC40Field(linkedPrivate, short*, 0x36);
                        P7CC40Field(linkedPrivate, int*, 0x1C) =
                            (int)(P7CC40Field(linkedPrivate, int*, 0x1C) & ~0x1E);
                        if (temp_a0_6 != -1) {
                            P7CC40ResetHudEntryByHandle(temp_a0_6);
                        }
                        helperKind4 = 0x12;
                        helperSelector5 = 0xB9;
                        helperProducer6 = (void*)&P7CC40InitializeHudDecimalCounterLayout;
                        helperCallback7 = &P7CC40SyncHudCounterTarget;
                        MATCHING_KEEP4(helperKind4, helperSelector5, helperProducer6,
                                       helperCallback7);
                        var_v1_2 = 9;
                        P7CC40Field(linkedPrivate, int*, 0x20) = 9;
                        var_v0 = P7CC40Field(linkedPrivate, int*, 0x1C) | 0x10;
                    createWord20Handle:
                        P7CC40Field(linkedPrivate, int*, 0x1C) = var_v0;
                        P7CC40Field(linkedPrivate, short*, 0x36) = P7CC40ConfigureHudEntry(
                            helperKind4, helperSelector5, helperProducer6, helperCallback7,
                            &P7CC40DrawHudIconAndDecimalCounter, linkedPrivate + 0x20, var_v1_2);
                        break;
                    case 6:
                        temp_a0_7 = P7CC40Field(linkedPrivate, short*, 0x34);
                        P7CC40Field(linkedPrivate, int*, 0x1C) =
                            (int)(P7CC40Field(linkedPrivate, int*, 0x1C) & ~0x21);
                        if (temp_a0_7 != -1) {
                            P7CC40ResetHudEntryByHandle(temp_a0_7);
                        }
                        helperKind4 = 0x14;
                        helperSelector5 = 0xB6;
                        helperProducer6 = P7CC40unk_ovlheader_800743B8;
                        helperCallback7 = P7CC40unk_ovlheader_800743C0;
                        MATCHING_KEEP4(helperKind4, helperSelector5, helperProducer6,
                                       helperCallback7);
                        payloadWord2 = P7CC40Field(linkedPrivate, int*, 0x1C);
                        payloadHeader3 = P7CC40unk_ovlheader_800743BC;
                        payloadLimit8 = 0x5DC;
                        P7CC40Field(linkedPrivate, int*, 0x24) = payloadLimit8;
                        payloadWord2 |= 0x20;
                        P7CC40Field(linkedPrivate, int*, 0x1C) = payloadWord2;
                        P7CC40Field(linkedPrivate, short*, 0x34) = P7CC40ConfigureHudEntry(
                            helperKind4, helperSelector5, helperProducer6, helperCallback7,
                            payloadHeader3, linkedPrivate + 0x24, payloadLimit8);
                        break;
                }
                ((Moby*)owner)->state = 2U;
                return;
            }
            if ((P7CC40ApproximatePlanarDistance(owner + 0xC, P7CC40D_80070328) < 0x3E8) &&
                (P7CC40Field(privateState, int*, 0x44) == 0)) {
                P7CC40Field(privateState, int*, 0x44) = 0xA;
                P7CC40Field(linkedPrivate, void**, 8) = owner;
            }
            if (P7CC40Field(privateState, short*, 0xC) == 6) {
                tickRemainder4 = P7CC40D_8006C640;
                quotient3 = tickRemainder4 / 15;
                tickRemainder4 -= quotient3 * 15;
                if (tickRemainder4 == 0) {
                    ((Moby*)owner)->lowDrawDistance = 0;
                    ((Moby*)owner)->drawn = 0;
                } else if (tickRemainder4 == 0xC) {
                    ((Moby*)owner)->lowDrawDistance = 0x20;
                    ((Moby*)owner)->drawn = 1;
                }
            }
            ownerStateByte48 = ((Moby*)owner)->state;
            switch (ownerStateByte48) {
                case 0:
                    if (P7CC40Field(privateState, short*, 0xC) != 0) {
                        P7CC40SetMobyAnimation(owner, 1);
                        colorCaseHalfword =
                            (unsigned short)P7CC40Field(privateState, short*, 0xC) - 1;
                        switch (colorCaseHalfword) {
                            case 0:
                                ((Moby*)owner)->colour.r = 0xDF;
                                colorWord2 = 0x40;
                                goto storeByte55;
                            case 2:
                                colorWord2 = 0xDF;
                                colorWord3 = 0x40;
                                ((Moby*)owner)->colour.r = colorWord2;
                                ((Moby*)owner)->colour.b = colorWord2;
                                colorWord2 = 0x3A;
                                ((Moby*)owner)->colour.g = colorWord3;
                                MATCHING_OBSERVE2(colorWord2, colorWord3);
                                goto storeByte57;
                            case 3:
                                colorWord2 = 0x40;
                                colorWord3 = 0xDF;
                                ((Moby*)owner)->colour.r = colorWord2;
                                ((Moby*)owner)->colour.b = colorWord2;
                                colorWord2 = 0x3A;
                                ((Moby*)owner)->colour.g = colorWord3;
                                goto storeByte57;
                            case 4:
                                colorWord2 = 0x40;
                                ((Moby*)owner)->colour.r = colorWord2;
                                ((Moby*)owner)->colour.g = colorWord2;
                                colorWord2 = 0xDF;
                                goto storeByte56;
                            case 1:
                            case 5:
                                colorWord2 = 0x80;
                                ((Moby*)owner)->colour.r = colorWord2;
                            storeByte55:
                                ((Moby*)owner)->colour.g = colorWord2;
                            storeByte56:
                                ((Moby*)owner)->colour.b = colorWord2;
                                colorWord2 = 0x3A;
                            storeByte57:
                                ((Moby*)owner)->colour.a = colorWord2;
                                break;
                        }

                }
                    goto storeOwnerState1;
                case 1:
                    if ((P7CC40Field(privateState, int*, 0x1C) != 0) &&
                        (P7CC40ApproximatePlanarDistance(owner + 0xC, P7CC40D_80070328) <
                         P7CC40Field(privateState, short*, 0x40))) {
                        ((Moby*)owner)->state = 3U;
                    }
                    if (P7CC40Field(privateState, int*, 0x18) == 0) {
                        P7CC40UpdateMobyWanderMotion(owner, privateState + 0x28, 0x4001);
                    }
                    break;
                case 3:
                    case3Result2 = P7CC40ApproximatePlanarDistance(owner + 0xC, P7CC40D_80070328);
                    case3Halfword3 = P7CC40Field(privateState, short*, 0x42);
                    MATCHING_KEEP(case3Halfword3);
                    case3Halfword3 = case3Halfword3 < case3Result2;
                    MATCHING_KEEP(case3Halfword3);
                    if (case3Halfword3 == 0)
                        break;
                storeOwnerState1:
                    ((Moby*)owner)->state = 1;
                    break;
            }
            particleCaseHalfword = (unsigned short)P7CC40Field(privateState, short*, 0xC) - 1;
            switch (particleCaseHalfword) {
                case 0:
                    particleKind4 = 3;
                    particleSelector5 = 0xC;
                    particleOwner6 = owner;
                    particleCallback2 = P7CC40SpawnParticle;
                    MATCHING_KEEP4(particleKind4, particleSelector5, particleOwner6,
                                   particleCallback2);
                    particleArgument7 = 4;
                    goto callParticleCallback;
                case 2:
                    particleKind4 = 3;
                    particleSelector5 = 0xC;
                    particleOwner6 = owner;
                    particleCallback2 = P7CC40SpawnParticle;
                    MATCHING_KEEP4(particleKind4, particleSelector5, particleOwner6,
                                   particleCallback2);
                    particleArgument7 = 4;
                    goto callParticleCallback;
                case 3:
                    particleKind4 = 3;
                    particleSelector5 = 0xC;
                    particleOwner6 = owner;
                    particleCallback2 = P7CC40SpawnParticle;
                    MATCHING_KEEP4(particleKind4, particleSelector5, particleOwner6,
                                   particleCallback2);
                    particleArgument7 = 1;
                    goto callParticleCallback;
                case 4:
                    particleKind4 = 3;
                    particleSelector5 = 0xC;
                    particleOwner6 = owner;
                    particleCallback2 = P7CC40SpawnParticle;
                    MATCHING_KEEP4(particleKind4, particleSelector5, particleOwner6,
                                   particleCallback2);
                    particleArgument7 = 0;
                    goto callParticleCallback;
                case 1:
                case 5:
                    particleKind4 = 3;
                    particleSelector5 = 0xC;
                    particleOwner6 = owner;
                    particleCallback2 = P7CC40SpawnParticle;
                    MATCHING_KEEP4(particleKind4, particleSelector5, particleOwner6,
                                   particleCallback2);
                    particleArgument7 = 3;
                callParticleCallback:
                    particleCallback2(particleKind4, particleSelector5, particleOwner6,
                                      particleArgument7);
                    break;
            }
        }
    }
exitFunction:
    return;
}

#undef P7CC40Field


/* Original private record: two word actor indices and a child pointer. */
typedef struct {
    int gateIndex, sourceIndex;
    Moby* child;
} DecodedIndexedSpawnTag;
extern Moby* D_8006C550;
extern int D_8006E344, D_8006C5BC;
extern int DecodedIndexedPlayer44 __asm__("D_80070328 + 0x44");
extern int DecodedIndexedPlayer280 __asm__("D_80070328 + 0x280");
extern Vector3D DecodedIndexedPlayer __asm__("D_80070328");
extern short DecodedIndexedCos[] __asm__("D_80065920");
extern short DecodedIndexedSin[] __asm__("D_800658A0");
int func_8004F334(Vector3D*, Vector3D*);
void func_800584BC(int, int);
void func_level_28_8007C98C(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
    register DecodedIndexedSpawnTag* tag __asm__("$18") = moby->mobyTag;
    register Moby* child __asm__("$17");
    register unsigned char* stateAddress __asm__("$16");
    Vector3D offset;
    register Vector3D* work __asm__("$4");
    short* childPrivate;
    register int childYaw __asm__("$2");
    int sine, vertical;
    register Vector3D* copiedWork __asm__("$5");
    register Vector3D* childPosition __asm__("$6");
    register int visible __asm__("$3");
    Moby* secondChild;
    switch (moby->state) {
        case 0:
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            moby->updateDistance = 127;
            if (!(D_8006C550[tag->gateIndex].state & 128))
                break;
            child = SpawnMoby(132, &D_8006C550[tag->sourceIndex]);
            MATCHING_KEEP(child);
            work = &offset;
            if (!child)
                break;
            childYaw = D_8006C550[tag->sourceIndex].angle.yaw;
            childPrivate = child->mobyTag;
            child->angle.yaw = childYaw;
            MATCHING_OBSERVE_VOLATILE(childYaw);
            *childPrivate = 0;
            child->state = 1;
            moby->state = 1;
            tag->child = child;
            MATCHING_OBSERVE3_VOLATILE(moby, tag, child);
            offset.x = (DecodedIndexedCos[child->angle.yaw] * 13) >> 5;
            MATCHING_OBSERVE_VOLATILE(work);
            childYaw = child->angle.yaw;
            copiedWork = work;
            sine = DecodedIndexedSin[childYaw];
            vertical = DecodedIndexedPlayer44;
            childPosition = &child->position;
            /* Retail writes zero to this local slot before replacing it. */
            offset.z = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(copiedWork, childPosition, "memory");
            offset.z = vertical;
            offset.y = (sine * 13) >> 5;
            func_8004F194(work, copiedWork, childPosition);
            func_80013D44(&offset, (child->angle.yaw + 128) & 255, 0, 152);
            if (DecodedIndexedPlayer280 < 0)
                DecodedIndexedPlayer280 = 0;
            break;
        case 1:
            if ((tag->child->state & 128) && D_8006E344 != 15) {
                moby->state = 2;
                stateAddress = &moby->state;
                MATCHING_KEEP(stateAddress);
                func_8003B7B4(stateAddress, 1, &savedData);
                func_8003B7B4(stateAddress, 1, &unsavedData);
            }
            break;
        case 2:
            secondChild = SpawnMoby(603, moby);
            secondChild->position.z -= 512;
            secondChild->angle.pitch = 0;
            /* Empty constraints retain the original delayed visibility constant. */
            __asm__ volatile("" : : : "$3", "memory");
            visible = 1;
            MATCHING_KEEP(visible);
            moby->lowDrawDistance = 32;
            moby->angle.pitch = 64;
            moby->unknown3[0] = visible;
            moby->drawn = visible;
            moby->state = 3;
            /* Original state-2 route continues through the state-3 distance gate. */
        case 3:
            if (func_8004F334(&moby->position, &DecodedIndexedPlayer) < 768)
                func_800584BC(0, D_8006C5BC - 8);
            break;
    }
}

typedef struct {
    int selector, threshold;
} DecodedNearActorTag;
int func_8004F334(Vector3D*, Vector3D*);
void func_8003BABC(Moby*, int, int);
void func_80034F40(Moby*, int);
void func_level_28_8007CC74(Moby* moby) {
    DecodedNearActorTag* tag = moby->mobyTag;
    if (func_8004F334(&moby->position, &spyro.position) < tag->threshold) {
        if (tag->selector)
            func_8003BABC(moby, 0, 0);
        tag->selector = 0;
        moby->state = 0;
        func_8003B7B4(tag, 4, &unsavedData);
    }
    if (!moby->state) {
        func_80034F40(moby, tag->selector);
        moby->state = 1;
    }
    switch (tag->selector) {
        case 0:
            moby->colour.g = 0xFF;
            moby->colour.r = 0;
            moby->colour.b = 0;
            moby->colour.a = 0x38;
            break;
        case 1:
            moby->colour.r = 0xFF;
            moby->colour.g = 0;
            moby->colour.b = 0;
            moby->colour.a = 0x38;
            break;
    }
}

typedef struct {
    int timer, sound;
} DecodedDamageColourTag;
int DecodedDamageColourSound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedDamageColourPlaying(Moby*, int) __asm__("func_8003BFC0");
void func_level_28_8007CD6C(Moby* moby) {
    DecodedDamageColourTag* tag = moby->mobyTag;
    int blue, red, mode;
    register int firstBlue __asm__("$6");
    int firstMode;
    register int fullRed __asm__("$2");
    register int numerator __asm__("$2");
    register int counter __asm__("$3");
    register int product __asm__("$2");
    register int shifted __asm__("$3");
    register int encoded __asm__("$2");
    if (moby->damageFlags) {
        if (moby->state != 1)
            DecodedDamageColourSound(moby, 0, 0);
        tag->timer = 0;
        moby->damageFlags = 0;
    }
    if (!DecodedDamageColourPlaying(moby, tag->sound) &&
        !DecodedDamageColourPlaying(moby, tag->sound))
        tag->sound = DecodedDamageColourSound(moby, 1, 4);
    if (tag->timer >= 15)
        moby->state = 0;
    else if (tag->timer < 3)
        moby->state = 1;
    else
        moby->state = 2;
    switch (moby->state) {
        case 0:
            moby->colour.r = 0;
            moby->colour.g = 0;
            moby->colour.b = 0;
            moby->colour.a = 0;
            break;
        case 1:
            /* Original low-32-bit factorization: timer * 5 * 17 = timer * 85. */
            counter = tag->timer;
            product = counter * 5;
            shifted = product << 4;
            firstBlue = product + shifted;
            if (firstBlue > 255)
                firstBlue = 255;
            else if (firstBlue < 0)
                firstBlue = 0;
            numerator = (15 - tag->timer) * 8;
            /* Signed division truncates toward zero, as in the original instructions. */
            firstMode = numerator / 15;
            if (firstMode > 15)
                firstMode = 15;
            else if (firstMode < 0)
                firstMode = 0;
            fullRed = 255;
            /* Retain original allocation; this empty constraint emits no instructions. */
            __asm__ volatile("" : : "r"(fullRed), "r"(firstMode) : "$3", "$4");
            moby->colour.r = fullRed;
            encoded = firstMode | 0x30;
            moby->colour.g = 0;
            moby->colour.b = firstBlue;
            moby->colour.a = encoded;
            tag->timer++;
            break;
        case 2:
            red = tag->timer * 170;
            if (red > 255)
                red = 255;
            else if (red < 0)
                red = 0;
            blue = tag->timer * 85;
            if (blue > 255)
                blue = 255;
            else if (blue < 0)
                blue = 0;
            mode = ((15 - tag->timer) * 8) / 15;
            if (mode > 15)
                mode = 15;
            else if (mode < 0)
                mode = 0;
            moby->colour.r = red;
            moby->colour.g = 0;
            moby->colour.b = blue;
            moby->colour.a = mode | 0x30;
            tag->timer++;
            break;
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 403 instructions per copy are the acceptance authority.
 * Keep original field widths, integer arithmetic, stack matrix layout,
 * helper arguments, state fallthroughs and call order. Units, full helper
 * contracts, table meanings and caller cadence remain unresolved.
 * Empty constraints emit no instructions. The explicit nop preserves one
 * original rand call delay slot that GCC 2.7 otherwise fills with a move.
 * Falsifiable check: original linked words and every complete binary hash.
 */
#define Actor81438Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor81438QueryWorldSegment(void*, void*) __asm__("func_80018368");

int Actor81438QueryDynamicMobyGeometry(void*, int, int, int, int, void*) __asm__("func_8001BA30");

int Actor81438CountTimerDown(void*, int) __asm__("func_800359A4");

int Actor81438PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");

int Actor81438PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");

int Actor81438BuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");

int Actor81438TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");

int Actor81438ShiftVectorLeft(void*, int) __asm__("func_8004F0E8");

int Actor81438ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");

int Actor81438CopyVector(void*, void*) __asm__("func_8004F178");

int Actor81438AddVector(void*, void*, void*) __asm__("func_8004F194");

int Actor81438DeleteMoby(void*) __asm__("func_80055B18");

int Actor81438rand(void) __asm__("rand");

extern short Actor81438D_800658A0[] __asm__("D_800658A0");

extern short Actor81438D_80065920[] __asm__("D_80065920");

extern int Actor81438D_8006C574 __asm__("D_8006C574");

extern int Actor81438D_8006C578 __asm__("D_8006C578");

extern int Actor81438D_8006C640 __asm__("D_8006C640");

extern int Actor81438D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char Actor81438D_8006E020[] __asm__("D_8006E020");

extern void* (*Actor81438SpawnMoby)(int, void*)__asm__("SpawnMoby");

extern int (*Actor81438SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");

void func_level_28_8007D004(void* input) {
    register unsigned char* owner __asm__("$18") = input;

    struct {
        int sp18, sp1C, sp20, pad24;

        int sp28, sp2C, sp30, pad34;

        int sp38, sp3C, sp40, pad44;

        int sp48, sp4C, sp50, pad54;

        int matrix58[6];

        signed char sp70, sp71, sp72, pad73[5];

    } frame;

    register int (*particle3)(int, int, void*, void*) __asm__("$3");

    register void* call4 __asm__("$4");

    register int call5 __asm__("$5");

    register void* call6 __asm__("$6");

    register void* call7 __asm__("$7");

    register int work2 __asm__("$2");

    register int work3 __asm__("$3");

    register int scratch4 __asm__("$4");

    register unsigned char* player21 __asm__("$21");

    register int original800 __asm__("$23");

    register int constant112 __asm__("$22");

    register void* matrix21 __asm__("$21");

    register int* vector17 __asm__("$17");

    register int* vector16 __asm__("$16");

    int particleKind;

    register int* ownerPosition __asm__("$16");

    register int* particlePosition __asm__("$20");

    int positionZ;

    int positionY;

    int positionX;

    register int tableByteOffset __asm__("$16");

    register int selectedAngle __asm__("$16");

    register int firstParticleIndex __asm__("$19");

    register int spawnIndex __asm__("$19");

    register int matrixParticleIndex __asm__("$19");

    register int spawnOffset __asm__("$20");

    register int tableSelector __asm__("$21");

    register int firstRandom __asm__("$4");

    register int secondRandom __asm__("$8");

    register int firstBiasedRandom __asm__("$5");

    register int secondBiasedRandom __asm__("$9");

    unsigned char temp_v1;

    register void* state __asm__("$20");

    void* spawned146;

    register void* spawned21D __asm__("$17");

    void* spawned1E2;

    register void* timerPointer __asm__("$4");

    positionX = ((Moby*)owner)->position.x;

    state = ((Moby*)owner)->mobyTag;

    if ((positionX >= 0x400) &&
        (positionY = ((Moby*)owner)->position.y, ((positionY < 0x400) == 0)) &&
        (positionZ = ((Moby*)owner)->position.z, ((positionZ < 0x400) == 0)) &&
        (positionX <= 0x3E800) && (positionY <= 0x3E800) && (positionZ <= 0x3E800)) {
        ownerPosition = owner + 0xC;

        Actor81438CopyVector(&frame.sp18, ownerPosition);

        work2 = ((Moby*)owner)->position.x;
        work3 = Actor81438Field(state, int*, 0);

        MATCHING_KEEP2(work2, work3);

        work2 += work3;
        ((Moby*)owner)->position.x = work2;

        work2 = ((Moby*)owner)->position.y;
        work3 = Actor81438Field(state, int*, 4);

        MATCHING_KEEP2(work2, work3);

        work2 += work3;
        ((Moby*)owner)->position.y = work2;

        scratch4 = Actor81438Field(state, int*, 8);
        work3 = ((Moby*)owner)->angle.pitch;
        work2 = ((Moby*)owner)->angle.roll;

        MATCHING_KEEP3(scratch4, work3, work2);

        work3 += 2;
        ((Moby*)owner)->angle.pitch = work3;

        work3 = ((Moby*)owner)->position.z;

        MATCHING_KEEP3(work3, work2, scratch4);

        work2 += 5;
        ((Moby*)owner)->angle.roll = work2;

        work2 = ((Moby*)owner)->angle.yaw;

        MATCHING_KEEP3(work2, work3, scratch4);

        work3 += scratch4;
        ((Moby*)owner)->position.z = work3;

        work3 = ((Moby*)owner)->state;

        MATCHING_KEEP2(work3, work2);

        work2 += 3;
        ((Moby*)owner)->angle.yaw = work2;

        switch (work3) { /* irregular */
            case 0:
                call4 = ownerPosition;

                MATCHING_BARRIER_GNU_VOLATILE("$3");

                if ((Actor81438QueryDynamicMobyGeometry(call4, 0x180, 1, 0, 0, owner) != 0) ||
                    (Actor81438QueryWorldSegment(&frame.sp18, ownerPosition) != 0)) {
                    Actor81438Field(state, int*, 0) = 0;

                    Actor81438Field(state, int*, 4) = 0;

                    Actor81438Field(state, int*, 8) = 0;

                    Actor81438CopyVector(ownerPosition, &frame.sp18);

                    ((Moby*)owner)->state = 1U;

                    Actor81438Field(state, int*, 0xC) = 6;

                    return;
                }
                if (Actor81438CountTimerDown(state + 0xC, 4) != 0) {
                    ((Moby*)owner)->state = 1U;

                    Actor81438Field(state, int*, 0xC) = 6;

                    case 1:
                        firstParticleIndex = 0;

                        tableSelector = Actor81438rand() & 0xFF;

                        particlePosition = owner + 0xC;

                        do {
                            tableByteOffset = tableSelector * 2;

                            firstRandom = Actor81438rand();

                            work3 =
                                *(short*)((unsigned char*)Actor81438D_80065920 + tableByteOffset);

                            firstBiasedRandom = firstRandom;
                            work2 = work3 << 1;
                            work2 += work3;

                            MATCHING_KEEP4(firstRandom, firstBiasedRandom, work2, work3);

                            work3 = work2 << 4;

                            if (firstRandom < 0)
                                firstBiasedRandom = firstRandom + 15;

                            work2 = firstBiasedRandom >> 4;
                            work2 <<= 4;
                            work2 = firstRandom - work2;
                            work2 = work3 + work2;
                            work2 >>= 12;

                            frame.sp28 = work2;

                            secondRandom = Actor81438rand();

                            work3 =
                                *(short*)((unsigned char*)Actor81438D_800658A0 + tableByteOffset);

                            secondBiasedRandom = secondRandom;
                            work2 = work3 << 1;
                            work2 += work3;

                            MATCHING_KEEP4(secondRandom, secondBiasedRandom, work2, work3);

                            work3 = work2 << 4;

                            if (secondRandom < 0)
                                secondBiasedRandom = secondRandom + 15;

                            call4 = (void*)1;
                            call5 = 20;
                            call6 = particlePosition;
                            call7 = &frame.sp28;

                            MATCHING_KEEP4(call4, call5, call6, call7);

                            work2 = secondBiasedRandom >> 4;
                            work2 <<= 4;
                            work2 = secondRandom - work2;
                            work2 = work3 + work2;

                            particle3 = Actor81438SpawnParticle;

                            MATCHING_KEEP2(particle3, work2);

                            work2 >>= 12;
                            frame.sp2C = work2;
                            frame.sp30 = 0;

                            particle3((int)call4, call5, call6, call7);

                            if (firstParticleIndex & 1) {
                                Actor81438ShiftVectorRightTowardZero(&frame.sp28, 1);

                                Actor81438SpawnParticle(1, 0x14, particlePosition, &frame.sp28);
                            }
                            tableSelector += 0xA;

                            call4 = (void*)6;
                            call5 = 70;
                            call6 = particlePosition;
                            call7 = (void*)16;

                            MATCHING_KEEP4(call4, call5, call6, call7);

                            firstParticleIndex++;

                            Actor81438SpawnParticle((int)call4, call5, call6, call7);

                        } while (firstParticleIndex < 0x18);

                        if (((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15) &&
                            (Actor81438D_8006C7E8 >= 0x7531)) {
                            spawned146 = Actor81438SpawnMoby(0x146, owner);

                            if (spawned146 != 0) {
                                Actor81438Field(spawned146, signed char*, 0x47) = 7;
                            }
                        }
                        spawnIndex = 0;

                        if ((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15) {
                            player21 = Actor81438D_8006E020;

                            MATCHING_KEEP(player21);

                            spawnOffset = 0;

                        loop_32:
                            if (Actor81438D_8006C7E8 >= 0x7531) {
                                spawned21D = Actor81438SpawnMoby(0x21D, owner);

                                if (spawned21D != 0) {
                                    selectedAngle = Actor81438PlanarHeadingLookup(
                                        ((Moby*)owner)->position.x -
                                            Actor81438Field(player21, int*, 0),
                                        ((Moby*)owner)->position.y -
                                            Actor81438Field(player21, int*, 4),
                                        0);

                                    work2 = Actor81438rand();
                                    selectedAngle += 64;

                                    MATCHING_KEEP2(work2, selectedAngle);

                                    work2 &= 31;
                                    selectedAngle += work2;
                                    Actor81438Field(spawned21D, signed char*, 0x46) = selectedAngle;

                                    Actor81438Field(spawned21D, signed char*, 0x45) =
                                        (signed char)((spawnOffset + (Actor81438rand() & 0x1E)) -
                                                      0xF);

                                    Actor81438Field(spawned21D, signed char*, 0x47) = 8;

                                    Actor81438Field(spawned21D, signed char*, 0x4C) = 0x2A;
                                }
                                spawnIndex += 1;

                                spawnOffset += 0x33;

                                if ((spawnIndex < 0x19) &&
                                    ((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15)) {
                                    goto loop_32;
                                }
                            }
                        }
                        MATCHING_BARRIER_GNU_VOLATILE("$4");

                        Actor81438PlayMobySoundEvent(owner, 0, 0);

                        ((Moby*)owner)->state = 2U;

                        return;
                }
                break;

            case 2:
                if (Actor81438CountTimerDown(state + 0xC, 4) != 0) {
                    Actor81438QueryDynamicMobyGeometry(ownerPosition, 0x800, 1, 0, 0x110000, owner);

                    ((Moby*)owner)->state = 3U;

                    Actor81438Field(state, int*, 0xC) = 0x14;

                    Actor81438Field(owner, signed char*, 0x41) = 0;

                    Actor81438Field(owner, signed char*, 0x4C) = 0;

                    Actor81438Field(owner, signed char*, 0x4D) = 0;

                    case 3:
                        original800 = 0x800;

                        MATCHING_KEEP(original800);

                        matrixParticleIndex = 0;

                        matrix21 = frame.matrix58;
                        constant112 = 112;

                        vector17 = &frame.sp38;
                        vector16 = &frame.sp48;

                        MATCHING_KEEP4(matrix21, constant112, vector17, vector16);

                        do {
                            frame.sp70 = 0;

                            frame.sp71 = Actor81438rand();

                            frame.sp72 = Actor81438rand();

                            Actor81438BuildPackedAngleBasisMatrix(&frame.sp70, matrix21, 0);

                            work2 = Actor81438rand();

                            /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                            __asm__ __volatile__("nop"
                                                 : "=r"(work2)
                                                 : "0"(work2)
                                                 : "$4", "$5", "$6");

                            call4 = matrix21;
                            call5 = (int)vector17;
                            call6 = vector17;

                            MATCHING_KEEP4(call4, call5, call6, work2);

                            work2 &= 31;
                            work2 += constant112;
                            frame.sp38 = work2;

                            frame.sp3C = 0;

                            frame.sp40 = 0;

                            Actor81438TransformVectorByBasis(call4, (void*)call5, call6);

                            Actor81438CopyVector(vector16, vector17);

                            Actor81438ShiftVectorLeft(vector16, 2);

                            MATCHING_KEEP(owner);

                            Actor81438AddVector(vector16, vector16, owner + 0xC);

                            particleKind = 0x37;

                            if (original800 >= 0x401) {
                                particleKind = 0x14;
                            }
                            call4 = (void*)1;
                            call5 = particleKind;
                            call6 = vector16;
                            call7 = vector17;

                            MATCHING_KEEP4(call4, call5, call6, call7);

                            matrixParticleIndex++;

                            Actor81438SpawnParticle((int)call4, call5, call6, call7);

                        } while (matrixParticleIndex < 0x18);

                        call4 = (void*)6;

                        MATCHING_KEEP2(owner, call4);

                        Actor81438SpawnParticle((int)call4, 0x46, owner + 0xC, (int*)0x10);

                        timerPointer = state + 0xC;

                        if (!(Actor81438D_8006C640 & 1) &&
                            ((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15) &&
                            (Actor81438D_8006C7E8 >= 0x7531)) {
                            spawned1E2 = Actor81438SpawnMoby(0x1E2, owner);

                            if (spawned1E2 != 0) {
                                Actor81438Field(spawned1E2, signed char*, 0x4C) = 0x2A;

                                Actor81438Field(spawned1E2, signed char*, 0x47) = 0xA;
                            }
                            MATCHING_KEEP(state);

                            timerPointer = state + 0xC;
                        }
                        if (Actor81438CountTimerDown(timerPointer, 4) != 0) {
                            goto block_51;
                        }
                }
                break;
        }
    } else {
    block_51:
        Actor81438DeleteMoby(owner);
    }
}

#undef Actor81438Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_28/moby/func_level_28_8007D650.s SHA256 0a27b333774ba1519dfb346302e50cbd073c65a3e561df27fffd59103c2a87d8. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int ControllerD650QueryWorldSegment() __asm__("func_80018368");              /* extern */
int ControllerD650UpdateMobyBallisticMotion() __asm__("func_80035030");      /* extern */
int ControllerD650SpawnMobyFromValueSelector() __asm__("func_80036A68");     /* extern */
int ControllerD650PlayMobySoundEvent() __asm__("func_8003BABC");             /* extern */
int ControllerD650ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int ControllerD650DeleteMoby() __asm__("func_80055B18");                     /* extern */
int ControllerD650RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int ControllerD650ReadSelectedFrameScalar() __asm__("func_80055E84");        /* extern */
extern unsigned char ControllerD650_D_800658A0 __asm__("D_800658A0");
extern unsigned char ControllerD650_D_80065920 __asm__("D_80065920");
extern int ControllerD650_D_8006C550 __asm__("D_8006C550");
extern int ControllerD650_D_8006C7C4 __asm__("D_8006C7C4");
extern Moby* ControllerD650_D_8006E788 __asm__("D_8006E788");
extern Vector3D ControllerD650_D_80070328 __asm__("D_80070328");

INCLUDE_RODATA("asm/nonmatchings/overlays/level_28/moby", D_level_28_800746C0);
extern Vector3D ControllerD650Thresholds __asm__("D_level_28_800746C0");
void func_level_28_8007D650(Moby* inputOwner) {
    Vector3D thresholds;

    register Moby* owner21 __asm__("$21") = inputOwner;
    register Moby** poolCursor17 __asm__("$17");
    Moby* linkedActor;
    register Moby* child20 __asm__("$20");
    register Moby* poolActor16 __asm__("$16");
    Vector3D* ownerPosition;
    register Vector3D* childPosition19 __asm__("$19");
    register short* sine16 __asm__("$16");
    register short* cosine17 __asm__("$17");
    register int angleOffset17 __asm__("$17");
    register int distance18 __asm__("$18");
    register int timer2 __asm__("$2");
    register int poolIndex3 __asm__("$3");
    register int timer3 __asm__("$3");
    register int childIndex22 __asm__("$22");
    register int state16 __asm__("$16");
    register int yaw2 __asm__("$2");
    register void* linkedTag16 __asm__("$16");
    register void* linked17 __asm__("$17");
    register void* childTag18 __asm__("$18");
    register void* tag23 __asm__("$23");
    register int class19 __asm__("$19");
    register int stateTwo18 __asm__("$18");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");

    MATCHING_KEEP(owner21);
    tag23 = owner21->mobyTag;
    thresholds = ControllerD650Thresholds;
    if (owner21->state != 3) {
        if (owner21->damageFlags != 0) {
            timer2 = M2C_FIELD(tag23, int*, 0x14) - 1;
            M2C_FIELD(tag23, int*, 0x14) = timer2;
            if ((timer2 <= 0) || (owner21->damageFlags & 0x180000)) {
                ControllerD650SpawnMobyFromValueSelector(owner21, 1, 0, 0);
                owner21->updateDistance = 0xFF;
                owner21->state = 3;
                func_80034F40(owner21, 1);
                ControllerD650PlayMobySoundEvent(owner21, 0, 0);
                M2C_FIELD(tag23, int*, 0x2C) = 0xC8;
                M2C_FIELD(tag23, int*, 0x28) = 0;
                M2C_FIELD(tag23, int*, 0x24) =
                    func_8004E880(owner21->position.x - ControllerD650_D_80070328.x,
                                  owner21->position.y - ControllerD650_D_80070328.y, 0);
                ControllerD650UpdateMobyBallisticMotion(owner21, tag23 + 0x2C,
                                                        M2C_FIELD(tag23, int*, 0x24), tag23 + 0x28,
                                                        8, 0x10, 0x4B0, 0x23);
            } else {
                M2C_FIELD(tag23, int*, 0x2C) = 0xC8;
                M2C_FIELD(tag23, int*, 0x28) = 0;
                yaw2 = owner21->unkb;
                if (yaw2 == 0) {
                    MATCHING_KEEP(yaw2);
                    yaw2 = func_800360F8(
                        func_8004E880(owner21->position.x - ControllerD650_D_80070328.x,
                                      owner21->position.y - ControllerD650_D_80070328.y, 0),
                        (int)M2C_FIELD(&ControllerD650_D_80070328, unsigned char*, 0xE), 0x20,
                        0x40U);
                }
                M2C_FIELD(tag23, int*, 0x24) = (int)yaw2;
                ControllerD650UpdateMobyBallisticMotion(owner21, tag23 + 0x2C,
                                                        M2C_FIELD(tag23, int*, 0x24), tag23 + 0x28,
                                                        8, 0x10, 0x4B0, 0x23);
                ControllerD650PlayMobySoundEvent(owner21, 1, 0);
            }
            owner21->colour.r = 0xFF;
            owner21->colour.g = 0xFF;
            owner21->colour.b = 0xFF;
            owner21->colour.a = 0x3F;
            goto checkDamageColour;
        }
        goto clearColour;
    }
checkDamageColour:
    if ((owner21->damageFlags == 0) || (owner21->state == 3)) {
    clearColour:
        owner21->colour.r = 0;
        owner21->colour.g = 0;
        owner21->colour.b = 0;
        owner21->colour.a = 0;
    }
    func_8003573C(owner21, 5, 0, 0);
    linkedActor = M2C_FIELD(tag23, Moby**, 0);
    if (linkedActor != 0) {
        value2 =
            ControllerD650ApproximatePlanarDistance(&owner21->position, &linkedActor->position);
        poolCursor17 = &ControllerD650_D_8006E788;
        poolActor16 = *poolCursor17++;
        distance18 = value2;
        if (poolActor16 != 0) {
            class19 = 373;
            do {
                if (!(poolActor16->state & 0x80) && (poolActor16->mobyClass == class19) &&
                    (ControllerD650ApproximatePlanarDistance(
                         &owner21->position, &poolActor16->position) < distance18)) {
                    ControllerD650DeleteMoby(poolActor16);
                }
                poolActor16 = *poolCursor17;
                poolCursor17 += 1;
            } while (poolActor16 != 0);
        }
    }
    state16 = owner21->state;
    if (state16 == 1)
        goto state1;
    if (state16 < 2) {
        if (state16 == 0)
            goto state0;
        goto clearDamage;
    }
    stateTwo18 = 2;
    if (state16 == stateTwo18)
        goto state2;
    argument4 = (int)owner21;
    if (state16 == 3)
        goto state3;
    goto clearDamage;
state0:
    MATCHING_KEEP(state16);
    if ((ControllerD650ApproximatePlanarDistance(&owner21->position, &ControllerD650_D_80070328) <
         M2C_FIELD(tag23, short*, 0x18)) ||
        (owner21->damageFlags != 0)) {
        func_80034F40(owner21, 1);
        owner21->state = 1;
        owner21->substate = 0;
        M2C_FIELD(tag23, int*, 0x40) = 0;
    }
    goto clearDamage;
state1:
    MATCHING_KEEP(state16);
    timer3 = M2C_FIELD(tag23, int*, 0x40);
    value2 = ControllerD650_D_8006C7C4;
    MATCHING_KEEP2(timer3, value2);
    timer3 += 1;
    M2C_FIELD(tag23, int*, 0x40) = timer3;
    if (((((int*)&thresholds)[value2] < timer3) &&
         (ControllerD650ApproximatePlanarDistance(&owner21->position, &ControllerD650_D_80070328) <
          M2C_FIELD(tag23, short*, 0x1A))) ||
        (owner21->damageFlags != 0)) {
        func_80034F40(owner21, 2);
        owner21->state = 2;
    } else {
        value2 =
            ControllerD650ApproximatePlanarDistance(&owner21->position, &ControllerD650_D_80070328);
        value3 = M2C_FIELD(tag23, short*, 0x1C);
        value3 = value3 < value2;
        if (value3) {
            func_80034F40(owner21, 1);
            owner21->state = 0;
        }
    }
    goto clearDamage;
state2:
    value2 = ControllerD650ReadSelectedFrameScalar(owner21);
    childIndex22 = 0;
    if (value2 == 0x17) {
        ownerPosition = &owner21->position;
        do {
            child20 = SpawnMoby(0x259, owner21);
            MATCHING_KEEP(child20);
            childPosition19 = &child20->position;
            if (child20 != 0) {
                argument4 = (int)childPosition19;
                MATCHING_KEEP(argument4);
                sine16 = (short*)&ControllerD650_D_80065920;
                MATCHING_KEEP(sine16);
                angleOffset17 = childIndex22 * 16;
                sine16 = (short*)(angleOffset17 + (int)sine16);
                MATCHING_KEEP(sine16);
                argument5 = (int)childPosition19;
                MATCHING_KEEP(argument5);
                value2 = *sine16;
                childTag18 = child20->mobyTag;
                MATCHING_KEEP2(value2, childTag18);
                child20->position.x = value2 >> 2;
                cosine17 = angleOffset17 + &ControllerD650_D_800658A0;
                value2 = *cosine17;
                MATCHING_KEEP_CLOBBER(value2, "$6");
                argument6 = (int)ownerPosition;
                MATCHING_KEEP(argument6);
                child20->position.z = 0;
                MATCHING_KEEP_CLOBBER(value2, "memory");
                child20->position.y = value2 >> 2;
                func_8004F194((Vector3D*)argument4, (Vector3D*)argument5, (Vector3D*)argument6);
                value2 = 64;
                value3 = child20->position.z;
                MATCHING_KEEP_CLOBBER(value3, "$4");
                argument4 = (int)ownerPosition;
                MATCHING_KEEP(argument4);
                child20->angle.roll = value2;
                MATCHING_KEEP_CLOBBER(value3, "memory");
                value3 += 512;
                child20->position.z = value3;
                value3 = *sine16;
                MATCHING_KEEP_CLOBBER(value3, "$5");
                argument5 = (int)childPosition19;
                MATCHING_KEEP(argument5);
                value2 = (value3 * 125) >> 11;
                M2C_FIELD(childTag18, int*, 0) = value2;
                value3 = *cosine17;
                M2C_FIELD(childTag18, int*, 8) = 0;
                M2C_FIELD(childTag18, int*, 0xC) = 25;
                value2 = (value3 * 125) >> 11;
                M2C_FIELD(childTag18, int*, 4) = value2;
                if (ControllerD650QueryWorldSegment(argument4, argument5) != 0) {
                    ControllerD650DeleteMoby(child20);
                }
            }
            if ((childIndex22 == 0) && (child20 != 0)) {
                M2C_FIELD(tag23, Moby**, 0) = child20;
            }
            childIndex22 += 1;
        } while (childIndex22 < 0x20);
        if (child20 != 0) {
            ControllerD650PlayMobySoundEvent(child20, 0, 0);
        }
        func_80034F40(owner21, 1);
        owner21->state = 1;
        M2C_FIELD(tag23, int*, 0x40) = 0;
    }
    goto clearDamage;
state3:
    if (ControllerD650UpdateMobyBallisticMotion(owner21, tag23 + 0x2C, M2C_FIELD(tag23, int*, 0x24),
                                                tag23 + 0x28, 8, 0x10, 0x4B0, 0x23) == state16) {
        poolIndex3 = M2C_FIELD(tag23, int*, 0x30);
        if (poolIndex3 != -1) {
            value2 = poolIndex3 * 0x58;
            value3 = ControllerD650_D_8006C550;
            linked17 = (void*)(value3 + value2);
            MATCHING_KEEP(linked17);
            if (M2C_FIELD(linked17, unsigned char*, 0x48) == stateTwo18) {
                argument4 = (int)linked17 + 12;
                argument5 = (int)&owner21->position;
                MATCHING_KEEP2(argument4, argument5);
                value3 = 1;
                linkedTag16 = M2C_FIELD(linked17, void**, 0);
                value2 = 32;
                M2C_FIELD(linked17, signed char*, 0x41) = value3;
                M2C_FIELD(linked17, signed char*, 0x4C) = value2;
                M2C_FIELD(linked17, signed char*, 0x4D) = value3;
                func_8004F178((Vector3D*)argument4, (Vector3D*)argument5);
                M2C_FIELD(linkedTag16, short*, 0xC) = (short)M2C_FIELD(tag23, int*, 0x10);
                M2C_FIELD(linked17, unsigned char*, 0x48) = 0U;
            }
        }
        ControllerD650RefreshMobySpatialGridAndBasis(owner21, 4);
        func_8003BA00(owner21);
        func_800369B8(owner21, 0x30);
        ControllerD650DeleteMoby(owner21);
        return;
    }
    goto clearDamage;
clearDamage:
    owner21->damageFlags = 0;
}
#undef M2C_FIELD

/* Original SCUS-94467 Rev0 80081A84..80081E24, 232 words.
 * Reuses Rev1 raw601 branch/helper evidence; every numeric operation below
 * is checked against Rev0 words. Rev1 Python direction *3 is not reused:
 * Rev0 SLL4/SUBU proves *15. Raw coordinates are bounded1024..256000;
 * products retain low32 bits, divisions are signed /35, shifts are signed.
 * Units, table producers, helper effects and caller cadence remain unresolved.
 * Instruction-free constraints retain native compiler scheduling/lifetimes.
 * AI-generated reconstruction; not yet human reviewed. */
typedef struct {
    Vector3D delta;
    int timer;
} DecodedRaw601Tag;
typedef struct {
    Vector3D oldPosition;
    int pad24;
    Vector3D particlePosition;
    int pad34;
    Vector3D direction;
    int pad44;
    int reserved48[4];
} DecodedRaw601Work;
extern unsigned char DecodedRaw601Player[] __asm__("D_80070328");
extern Moby* D_8006C550;
extern void* DecodedRaw601PlayerLink __asm__("D_80070328+0x250");
extern int DecodedRaw601PlayerFlags __asm__("D_80070328+0x24");
static __inline__ int DecodedRaw601Quotient(int numerator) {
    return numerator / 35;
}
extern short D_80065920[], D_800658A0[];
int func_8004F334(Vector3D*, Vector3D*);
int func_8001830C(Vector3D*, Vector3D*, int, int, Moby*);
void func_80055B18(Moby*);
void func_level_28_8007DCD0(Moby* mobyArgument) {
    DecodedRaw601Work work;
    register Moby* moby __asm__("$18") = mobyArgument;
    register DecodedRaw601Tag* tag __asm__("$16");
    register int x __asm__("$6") = moby->position.x;
    register int y __asm__("$5");
    register int z __asm__("$4");
    int intensity;
    register void* retained __asm__("$17");
    register int opposite __asm__("$19");
    register int heading __asm__("$16");
    register int maximum __asm__("$3");
    char* particle;
    MATCHING_KEEP(moby);
    tag = moby->mobyTag;
    __asm__("" : "=r"(tag) : "0"(tag), "r"(x));
    moby->size = 32;
    if (x < 1024)
        goto cleanup;
    y = moby->position.y;
    if (y < 1024)
        goto cleanup;
    z = moby->position.z;
    if (z < 1024)
        goto cleanup;
    maximum = 256000;
    MATCHING_KEEP(maximum);
    {
        register int outside __asm__("$2");
        outside = x > maximum;
        MATCHING_KEEP(outside);
        if (outside)
            goto cleanup;
        outside = y > maximum;
        MATCHING_KEEP(outside);
        if (outside)
            goto cleanup;
        outside = z > maximum;
        MATCHING_KEEP(outside);
        if (outside)
            goto cleanup;
    }
    {
        register int numerator __asm__("$2") = tag->timer * 255;
        MATCHING_KEEP(numerator);
        intensity = DecodedRaw601Quotient(numerator);
    }
    if (intensity >= 256)
        intensity = 255;
    else if (intensity < 0)
        intensity = 0;
    /* Retail computes this secondary quotient before the callback although
     * its result is not subsequently consumed in this body. Keep the native
     * signed division and its fresh timer read; the constraint emits no code. */
    {
        register int numerator __asm__("$2") = tag->timer * 15;
        register int secondary __asm__("$3");
        MATCHING_KEEP(numerator);
        secondary = DecodedRaw601Quotient(numerator);
        MATCHING_OBSERVE_VOLATILE(secondary);
    }
    moby->colour.r = intensity;
    moby->colour.g = 0;
    moby->colour.b = 0;
    moby->colour.a = 63;
    SpawnParticle(1, 12, (Vector3D*)moby, (Vector3D*)4);
    retained = &moby->position;
    func_8004F178(&work.oldPosition, retained);
    moby->position.x += tag->delta.x;
    moby->position.y += tag->delta.y;
    moby->position.z += tag->delta.z;
    if (moby->state == 0) {
        int distance;
        retained = *(void**)DecodedRaw601PlayerLink;
        distance = func_8004F334(&moby->position, (Vector3D*)DecodedRaw601Player);
        if (moby->state != 98 && distance < 512) {
            if (!(*(int*)((char*)retained + 0x1C) & 1))
                DecodedRaw601PlayerFlags |= 1;
            moby->state = 98;
            goto done;
        }
        if (func_800359A4(&tag->timer, 4) ||
            func_8001830C(&work.oldPosition, &moby->position, 0, 0, moby))
            moby->state = 98;
        {
            register int result __asm__("$2") = func_8004E880(tag->delta.x, tag->delta.y, 0);
            register int low __asm__("$4") = 0;
            register int high __asm__("$5") = 14;
            __asm__("" : "=r"(low), "=r"(high) : "0"(low), "1"(high), "r"(result));
            heading = result;
            heading += func_800363DC(low, high);
        }
        opposite = heading;
        MATCHING_OBSERVE_VOLATILE(opposite);
        retained = &work.particlePosition;
        func_8004F178(retained, &moby->position);
        /* Preserve both signed table lanes and the raw particle packet writes. */
        {
            register int primaryIndex __asm__("$3") = opposite & 255;
            register int oppositeIndex __asm__("$7");
            register int cosine __asm__("$5");
            register int kind __asm__("$4");
            register int selector __asm__("$5");
            register Vector3D* positionArg __asm__("$6");
            register char* (*spawn)(int, int, Vector3D*, Vector3D*)__asm__("$8");
            MATCHING_KEEP(primaryIndex);
            opposite = heading - 128;
            MATCHING_KEEP(opposite);
            primaryIndex *= 2;
            kind = 1;
            MATCHING_KEEP(kind);
            oppositeIndex = (opposite & 255) * 2;
            MATCHING_KEEP2(primaryIndex, oppositeIndex);
            cosine = *(short*)((char*)D_80065920 + primaryIndex);
            spawn = SpawnParticle;
            MATCHING_KEEP2(cosine, spawn);
            work.direction.x = (cosine * 15) >> 11;
            {
                register int sine __asm__("$3") = *(short*)((char*)D_800658A0 + primaryIndex);
                MATCHING_KEEP(sine);
                positionArg = retained;
                MATCHING_KEEP(positionArg);
                work.direction.z = 0;
                MATCHING_BARRIER_VOLATILE("memory");
                work.direction.y = (sine * 15) >> 11;
            }
            {
                register int sample __asm__("$3") = *(short*)((char*)D_80065920 + oppositeIndex);
                MATCHING_KEEP_CLOBBER(sample, "$5");
                selector = 13;
                __asm__("" : "=r"(selector) : "0"(selector), "r"(sample));
                work.particlePosition.x += (sample * 5) >> 9;
            }
            {
                register int sample __asm__("$2") = *(short*)((char*)D_800658A0 + oppositeIndex);
                register int product __asm__("$3") = sample * 5;
                MATCHING_KEEP(product);
                work.particlePosition.y += product >> 9;
            }
            particle = spawn(kind, selector, positionArg, &work.direction);
        }
        particle[2] = 14;
        particle[10] += 56;
    }
done:
    if (moby->state != 98)
        return;
cleanup:
    {
        Moby** owner = D_8006C550[moby->linkedMoby].mobyTag;
        if (*owner == moby)
            *owner = 0;
    }
    func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_28/moby/func_level_28_8007E070.s SHA256 cd6f5eb68601e9a5ddf3481a604571c104e74fe75473d5563e530aa91d53c8bf. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level28_7E070Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level28_7E070TestSubdividedSegmentPath(Vector3D*, Vector3D*, int) __asm__("func_80013E38");
/* extern */
void Level28_7E070RequestMobyAnimation(Moby*, int) __asm__("func_80034F40");
/* extern */
int Level28_7E070UpdateMobyMotionDescriptor(Moby*, void*) __asm__("func_80035194");
/* extern */
int Level28_7E070TurnMobyTowardPlayer(Moby*, int, int, int) __asm__("func_8003573C");
/* extern */
int Level28_7E070TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
/* extern */
int Level28_7E070CountTimerDown(void*, int) __asm__("func_800359A4");
/* extern */
int Level28_7E070ResolveMobyYawStep(Moby*, int, int, int, int) __asm__("func_80035DDC");
/* extern */
int Level28_7E070TestPaddedRotatedBox(Vector3D*, char*, int, int) __asm__("func_80036220");
/* extern */
int Level28_7E070GetClosestPathNode(Vector3D*, void*, int*) __asm__("func_8003645C");
/* extern */
void Level28_7E070EmitMobyVertexParticles(Moby*, int) __asm__("func_800369B8");
/* extern */
void Level28_7E070MarkMobyCollectionBit(Moby*) __asm__("func_8003BA00");
/* extern */
int Level28_7E070PlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
/* extern */
int Level28_7E070PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
/* extern */
void Level28_7E070CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
/* extern */
int Level28_7E070ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
/* extern */
void Level28_7E070DeleteMoby(Moby*) __asm__("func_80055B18");
/* extern */
void Level28_7E070RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
/* extern */
extern Spyro Level28_7E070_D_80070328 __asm__("D_80070328");
extern void* Level28_7E070_D_80071930 __asm__("D_80071930");
extern int (*Level28_7E070_unk_ovlheader_800743C4)(unsigned char*, Vector3D*,
                                                   Vector3D*) __asm__("unk_ovlheader_800743C4");
extern void (*Level28_7E070_unk_ovlheader_800743E0)(int, int) __asm__("unk_ovlheader_800743E0");

void func_level_28_8007E070(void* ownerRecord) {
    /* SCUS-94467 original8007E070;
     assembly SHA256 above.
     * Original0x60 frame: scratch SP18..SP47;
      saved16..20 at48..58,
     * RA at5C. All record offsets and path-entry strides are bytes.
     * Path count/index use signed LH;
      index increment is truncated to
     * signed16 before comparison, including the32767->-32768 wrap.
     * Callback slots800743C4/E0 contain80083800/80083960 in the
     * original level28 image. Their existing C interfaces are respectively
     * (byte state, origin vector, target vector) and(index, state).
     * Original55B18 consumes one incoming owner;
     4E880 consumes three
     * integer operands.369B8 forwards raw4/5 unchanged to2E2D0, whose
     * original GTE producer consumes both. No sound meaning is inferred.
     * Empty constraints use initialized original producers: early private
     * identity18 keeps distinct flags stores;
      motion owner4 preserves two
     * shared entry labels;
      math4/5/6 retains raw operands;
      result2 precedes
     * default flag17;
      signed index store precedes count reload.
     * Private18/path19 and position18/movement-status19 have disjoint
     * state-specific lifetimes. Hardware register suffixes document them.
     * Units/fixed point, helper meanings and caller cadence are unresolved.
     * Cadence per invocation;
      no synchronized runtime/subsystem claim.
     * Falsification:415 native instructions,7 owned selectors, all linked
     * words/transfer targets and full EXE/every-overlay original hashes.
     * AI generated;
      not human reviewed. */
    struct {
        Vector3D savedPosition;
        unsigned char pad24[4];
        int selectedIndex;
        unsigned char pad2C[4];
        Vector3D targetPosition;
        unsigned char pad3C[12];
    } scratch;

    register Moby* deathOwner4 __asm__("4");
    register int deathSelector5 __asm__("5");
    register int deathParameter6 __asm__("6");
    register Moby* motionOwner4 __asm__("4");
    unsigned int movementParameter;
    unsigned int state3Parameter;
    unsigned int state4Parameter;
    unsigned int state5Parameter;
    unsigned int state6Parameter;
    int pathIndex;
    int distanceOrNextIndex;
    register int angleZero6 __asm__("6");
    int movementFlags2;
    int ownerX;
    register int initialDistance20 __asm__("20");
    int timerResult;
    register int movementStatus19 __asm__("19");
    register int state5DeltaX4 __asm__("4");
    register int state6DeltaX4 __asm__("4");
    register int state5DeltaY5 __asm__("5");
    register int state6DeltaY5 __asm__("5");
    register int defaultCheck17 __asm__("$17");
    register int activationCheck17 __asm__("$17");
    register int movementAngle17 __asm__("$17");
    int otherWord2;
    unsigned int privateFlags;
    unsigned int activationFlags;
    unsigned int counterByte;
    unsigned int initialState;
    unsigned int state;
    register void* ownerPosition17 __asm__("$17");
    register void* privateRecord18 __asm__("$18");
    register void* ownerPosition18 __asm__("$18");
    register void* pathRecord19 __asm__("$19");
    void* positionPointer;

    privateRecord18 = Level28_7E070Field(ownerRecord, void**, 0);
    initialState = Level28_7E070Field(ownerRecord, unsigned char*, 0x48);
    pathRecord19 = Level28_7E070Field(privateRecord18, void**, 0x38);
    defaultCheck17 = 0;
    if (initialState == 7) {
        Level28_7E070DeleteMoby(ownerRecord);
        return;
    }
    if ((Level28_7E070Field(ownerRecord, int*, 0x18) != 0) && (initialState != 2)) {
        if (initialState == 3) {
            counterByte = Level28_7E070Field(privateRecord18, unsigned char*, 0x1A);
            if (Level28_7E070Field(ownerRecord, unsigned char*, 0x43) == 0xC) {
                if ((int)counterByte >= 0x32) {
                    positionPointer = ownerRecord + 0xC;
                    goto measureInitialDistance;
                }
                goto prepareEarlyTerminal;
            }
            if ((int)counterByte < 0x46) {
                goto prepareEarlyTerminal;
            }
            goto preparePosition;
        }
    prepareEarlyTerminal:
        if ((Level28_7E070Field(ownerRecord, unsigned char*, 0x48) == 0) &&
            (Level28_7E070Field(privateRecord18, unsigned short*, 0x1C) & 4)) {
            Level28_7E070_unk_ovlheader_800743E0(
                Level28_7E070Field(ownerRecord, unsigned char*, 0x43), 1);
        }
        {
            register unsigned int flags2 __asm__("2");
            deathOwner4 = ownerRecord;
            deathSelector5 = 0;
            MATCHING_KEEP2(deathOwner4, deathSelector5);
            flags2 = Level28_7E070Field(privateRecord18, unsigned short*, 0x1C);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(flags2, "6");
            deathParameter6 = 0;
            flags2 |= 0x80;
            {
                register void* earlyTag18 __asm__("18");
                earlyTag18 = privateRecord18;
                __asm__ volatile(""
                                 : "=r"(earlyTag18), "=r"(flags2)
                                 : "0"(earlyTag18), "1"(flags2), "r"(deathOwner4)
                                 : "memory");
                Level28_7E070Field(earlyTag18, unsigned short*, 0x1C) = flags2;
            }
        }
        goto sharedTerminalCalls;
    }
preparePosition:
    positionPointer = ownerRecord + 0xC;
measureInitialDistance:
    Level28_7E070Field(ownerRecord, int*, 0x18) = 0;
    initialDistance20 =
        Level28_7E070ApproximatePlanarDistance(positionPointer, &Level28_7E070_D_80070328);
    state = Level28_7E070Field(ownerRecord, unsigned char*, 0x48);
    if ((state != 2) && (initialDistance20 < 0x400)) {
        deathOwner4 = ownerRecord;
        MATCHING_KEEP(deathOwner4);
        {
            register unsigned int global2 __asm__("2");
            global2 = Level28_7E070Field(&Level28_7E070_D_80070328, unsigned int*, 0x24);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(global2, "5");
            deathSelector5 = 0;
            global2 |= 1;
            Level28_7E070Field(&Level28_7E070_D_80070328, unsigned int*, 0x24) = global2;
        }
        {
            register unsigned int flags2 __asm__("2");
            flags2 = Level28_7E070Field(privateRecord18, unsigned short*, 0x1C);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(flags2, "6");
            deathParameter6 = 0;
            flags2 |= 0x80;
            Level28_7E070Field(privateRecord18, unsigned short*, 0x1C) = flags2;
        }
        goto sharedTerminalCalls;
    }
    switch (state) {
        case 0:
            Level28_7E070TurnMobyTowardPlayer(ownerRecord, 5, 0, 0);
            privateFlags = Level28_7E070Field(privateRecord18, unsigned short*, 0x1C);
            if (privateFlags & 0x80) {
                Level28_7E070Field(privateRecord18, unsigned short*, 0x1C) =
                    (unsigned short)(privateFlags & 0xFF7F);
                Level28_7E070Field(privateRecord18, unsigned char*, 0x1A) = 0x50U;
                Level28_7E070RequestMobyAnimation(ownerRecord, 1);
                defaultCheck17 = 0;
                Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 3U;
            } else {
                goto enableDefaultCheck;
            }
            goto checkActivation;
        case 1:
            if (initialDistance20 < 0x4075) {
                ownerPosition18 = ownerRecord + 0xC;
                Level28_7E070CopyVector(&scratch.savedPosition, ownerPosition18);
                movementParameter = 0x64;
                if (Level28_7E070Field(ownerRecord, unsigned char*, 0x43) == 0xC) {
                    movementParameter = 0x8C;
                }
                movementStatus19 = Level28_7E070ResolveMobyYawStep(ownerRecord, movementParameter,
                                                                   0x380, 0x380, 0x23);
                if (movementStatus19 & 0x20) {
                    ownerX = Level28_7E070Field(ownerRecord, int*, 0xC);
                    movementAngle17 = Level28_7E070PlanarHeadingLookup(
                        ownerX - Level28_7E070Field(Level28_7E070_D_80071930, int*, 0xC),
                        Level28_7E070Field(ownerRecord, int*, 0x10) -
                            Level28_7E070Field(Level28_7E070_D_80071930, int*, 0x10),
                        0);
                    if (Level28_7E070ApproximatePlanarDistance(
                            ownerPosition18, Level28_7E070_D_80071930 + 0xC) < 0xE0) {
                        motionOwner4 = ownerRecord;
                        if ((movementStatus19 & 0x10) == 0)
                            goto applyMovement;
                        MATCHING_BARRIER_VOLATILE("memory");
                        goto removeOwner;
                    }
                    goto prepareMovementOwner;
                }
                movementAngle17 = Level28_7E070_unk_ovlheader_800743C4(
                    ownerRecord + 0x49, ownerPosition18, &Level28_7E070_D_80070328);
            prepareMovementOwner:
                motionOwner4 = ownerRecord;
                MATCHING_KEEP(motionOwner4);
            applyMovement:
                MATCHING_OBSERVE_VOLATILE(movementStatus19);
                Level28_7E070TurnMobyTowardHeading(motionOwner4, movementAngle17 & 0xFF, 5, 0, 0,
                                                   0);
                return;
            }
            goto storeState4;
        case 2:
            if (Level28_7E070UpdateMobyMotionDescriptor(ownerRecord, privateRecord18 + 4) ==
                0x100) {
                deathOwner4 = ownerRecord;
                MATCHING_KEEP(deathOwner4);
                deathSelector5 = 0;
                deathParameter6 = 0;
            sharedTerminalCalls:
                Level28_7E070PlayMobySoundEvent(deathOwner4, deathSelector5, deathParameter6);
                Level28_7E070RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level28_7E070MarkMobyCollectionBit(ownerRecord);
                Level28_7E070EmitMobyVertexParticles(ownerRecord, 0x28);
            removeOwner:
                Level28_7E070DeleteMoby(ownerRecord);
                return;
            }
            goto checkActivation;
        case 3:
            state3Parameter = 0x64;
            if (Level28_7E070Field(ownerRecord, unsigned char*, 0x43) == 0xC) {
                state3Parameter = 0x8C;
            }
            Level28_7E070ResolveMobyYawStep(ownerRecord, state3Parameter, 0, 0x380, 0x21);
            if (Level28_7E070CountTimerDown(privateRecord18 + 0x1A, 1) != 0) {
            storeState4:
                __asm__ volatile("" : : : "2", "memory");
                Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 4U;
                goto checkActivation;
            }
            goto checkActivation;
        case 4:
            state4Parameter = 0x64;
            if (Level28_7E070Field(ownerRecord, unsigned char*, 0x43) == 0xC) {
                state4Parameter = 0x8C;
            }
            Level28_7E070ResolveMobyYawStep(ownerRecord, state4Parameter, 0, 0x380, 0x23);
            ownerPosition17 = ownerRecord + 0xC;
            if ((Level28_7E070TestSubdividedSegmentPath(ownerPosition17, privateRecord18 + 0x3C,
                                                        1) == 1) ||
                (pathRecord19 == 0)) {
                Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 5U;
            } else {
                Level28_7E070GetClosestPathNode(ownerPosition17, pathRecord19,
                                                &scratch.selectedIndex);
                Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 6U;
                Level28_7E070Field(pathRecord19, short*, 2) = (short)scratch.selectedIndex;
            }
            /* fallthrough */
        case 5:
            state5Parameter = 0x64;
            if (Level28_7E070Field(ownerRecord, unsigned char*, 0x43) == 0xC) {
                state5Parameter = 0x8C;
            }
            movementFlags2 =
                Level28_7E070ResolveMobyYawStep(ownerRecord, state5Parameter, 0x380, 0x380, 0x23);
            angleZero6 = 0;
            if (movementFlags2 & 0x20) {
                {
                    register void* target2 __asm__("2");
                    register int ownX7 __asm__("7");
                    register int ownY3 __asm__("3");
                    target2 = Level28_7E070_D_80071930;
                    ownX7 = Level28_7E070Field(ownerRecord, int*, 0xC);
                    ownY3 = Level28_7E070Field(ownerRecord, int*, 0x10);
                    state5DeltaX4 = Level28_7E070Field(target2, int*, 0xC);
                    state5DeltaY5 = Level28_7E070Field(target2, int*, 0x10);
                    state5DeltaX4 = ownX7 - state5DeltaX4;
                    state5DeltaY5 = ownY3 - state5DeltaY5;
                }
            } else {
                {
                    register int first3 __asm__("3");
                    register int second2 __asm__("2");
                    first3 = Level28_7E070Field(privateRecord18, int*, 0x3C);
                    state5DeltaX4 = Level28_7E070Field(ownerRecord, int*, 0xC);
                    second2 = Level28_7E070Field(privateRecord18, int*, 0x40);
                    state5DeltaY5 = Level28_7E070Field(ownerRecord, int*, 0x10);
                    state5DeltaX4 = first3 - state5DeltaX4;
                    state5DeltaY5 = second2 - state5DeltaY5;
                }
            }
            MATCHING_KEEP3(state5DeltaX4, state5DeltaY5, angleZero6);
            Level28_7E070TurnMobyTowardHeading(
                ownerRecord,
                Level28_7E070PlanarHeadingLookup(state5DeltaX4, state5DeltaY5, angleZero6) & 0xFF,
                5, 0, 1, 0);
            if (Level28_7E070ApproximatePlanarDistance(ownerRecord + 0xC, privateRecord18 + 0x3C) <
                0x200) {
                Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 0U;
                Level28_7E070RequestMobyAnimation(ownerRecord, 0);
                defaultCheck17 = 1;
            } else {
                goto enableDefaultCheck;
            }
            goto checkActivation;
        case 6:
            Level28_7E070CopyVector(&scratch.targetPosition,
                                    Level28_7E070Field(pathRecord19, int*, 0xC) +
                                        (Level28_7E070Field(pathRecord19, short*, 2) * 0x10));
            state6Parameter = 0x64;
            if (Level28_7E070Field(ownerRecord, unsigned char*, 0x43) == 0xC) {
                state6Parameter = 0x8C;
            }
            movementFlags2 =
                Level28_7E070ResolveMobyYawStep(ownerRecord, state6Parameter, 0x380, 0x380, 0x23);
            angleZero6 = 0;
            if (movementFlags2 & 0x20) {
                {
                    register void* target2 __asm__("2");
                    register int ownX7 __asm__("7");
                    register int ownY3 __asm__("3");
                    target2 = Level28_7E070_D_80071930;
                    ownX7 = Level28_7E070Field(ownerRecord, int*, 0xC);
                    ownY3 = Level28_7E070Field(ownerRecord, int*, 0x10);
                    state6DeltaX4 = Level28_7E070Field(target2, int*, 0xC);
                    state6DeltaY5 = Level28_7E070Field(target2, int*, 0x10);
                    state6DeltaX4 = ownX7 - state6DeltaX4;
                    state6DeltaY5 = ownY3 - state6DeltaY5;
                }
            } else {
                {
                    register int first3 __asm__("3");
                    register int second2 __asm__("2");
                    first3 = scratch.targetPosition.x;
                    state6DeltaX4 = Level28_7E070Field(ownerRecord, int*, 0xC);
                    second2 = scratch.targetPosition.y;
                    state6DeltaY5 = Level28_7E070Field(ownerRecord, int*, 0x10);
                    state6DeltaX4 = first3 - state6DeltaX4;
                    state6DeltaY5 = second2 - state6DeltaY5;
                }
            }
            MATCHING_KEEP3(state6DeltaX4, state6DeltaY5, angleZero6);
            Level28_7E070TurnMobyTowardHeading(
                ownerRecord,
                Level28_7E070PlanarHeadingLookup(state6DeltaX4, state6DeltaY5, angleZero6) & 0xFF,
                5, 0, 1, 0);
            {
                register int return2 __asm__("2");
                return2 = Level28_7E070ApproximatePlanarDistance(
                    ownerRecord + 0xC, (Vector3D*)&scratch.targetPosition);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(return2, "17");
                distanceOrNextIndex = return2;
            }
            defaultCheck17 = 1;
            if ((distanceOrNextIndex < 0x200) &&
                ((pathIndex = Level28_7E070Field(pathRecord19, short*, 2),
                  (({
                       register void* table3 __asm__("3");
                       register int offset2 __asm__("2");
                       register int word2 __asm__("2");
                       table3 = Level28_7E070Field(pathRecord19, void**, 0xC);
                       offset2 = pathIndex * 0x10;
                       word2 = Level28_7E070Field(offset2 + (int)table3, int*, 0xC);
                       word2;
                   }) != 0)) ||
                 (distanceOrNextIndex = pathIndex + 1,
                  Level28_7E070Field(pathRecord19, short*, 2) = distanceOrNextIndex,
                  ({ MATCHING_BARRIER_VOLATILE("memory"); }),
                  (((short)distanceOrNextIndex < Level28_7E070Field(pathRecord19, short*, 0)) ==
                   0)))) {
                Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 5U;
                goto enableDefaultCheck;
            }
            goto checkActivation;
        default:
            goto checkActivation;
    }
    return;
enableDefaultCheck:
    defaultCheck17 = 1;
checkActivation:
    if (defaultCheck17 != 0) {
        activationFlags = Level28_7E070Field(privateRecord18, unsigned short*, 0x1C);
        activationCheck17 = 0;
        if (activationFlags & 1) {
            {
                register int threshold2 __asm__("2");
                threshold2 = Level28_7E070Field(privateRecord18, short*, 0x1E);
                MATCHING_KEEP(threshold2);
                activationCheck17 = initialDistance20 < threshold2;
            }
        }
        if ((activationFlags & 2) &&
            (Level28_7E070TestPaddedRotatedBox((Vector3D*)&Level28_7E070_D_80070328,
                                               privateRecord18 + 0x20, 0, 0) != 0)) {
            activationCheck17 = 1;
        }
        if (initialDistance20 >= 0x4075) {
            activationCheck17 = 0;
        }
        MATCHING_OBSERVE_VOLATILE(initialDistance20);
        if (activationCheck17 != 0) {
            if (Level28_7E070Field(privateRecord18, unsigned short*, 0x1C) & 4) {
                Level28_7E070_unk_ovlheader_800743E0(
                    Level28_7E070Field(ownerRecord, unsigned char*, 0x43), 1);
            }
            Level28_7E070Field(ownerRecord, unsigned char*, 0x48) = 1U;
            Level28_7E070RequestMobyAnimation(ownerRecord, 1);
        }
    }
    return;
}
#undef Level28_7E070Field

extern int D_8006C770;
extern Moby* D_8006C550;
void func_80055B18(Moby*);
int func_800359A4(void*, int);
void func_level_28_8007E6EC(Moby* moby) {
    if (!moby->state) {
        if (D_8006C770 && moby->animationState.id == 1) {
            func_80055B18(moby);
            if (moby->linkedMoby) {
                Moby** entry = D_8006C550[moby->linkedMoby].mobyTag;
                int index;
                for (index = 0; index < 4; index++, entry++)
                    if (moby == *entry)
                        *entry = 0;
            }
        }
    } else if (func_800359A4(moby->mobyTag, 4)) {
        func_80055B18(moby);
    }
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_28/moby", D_level_28_800746EC);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_28/moby", D_level_28_800746F8);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; AI generated, not human reviewed.
* Mixed C/original assembly: three documented raw indexed LW sites,
* original closed25-word conditional and10-word outgoing-call fragments.
* No lookup bounds, defaults or manual SP/FP object are supplied.
* Every native/frame/control/table/source/helper/input/alias gate remains pending. */
#define Actor1228Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Actor1228Keep(v) __asm__("" : "=r"(v) : "0"(v))
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Actor1228Product;
extern int Actor1228_D_800658A0 __asm__("D_800658A0");
extern int Actor1228_D_80065920 __asm__("D_80065920");
extern int Actor1228_D_8006C550 __asm__("D_8006C550");
extern int Actor1228_D_8006C574 __asm__("D_8006C574");
extern int Actor1228_D_8006C578 __asm__("D_8006C578");
extern int Actor1228_D_8006C640 __asm__("D_8006C640");
extern int Actor1228_D_8006C730 __asm__("D_8006C730");
extern int Actor1228_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor1228_D_8006C7E8 __asm__("D_8006C7E8");
extern int Actor1228_D_8006C7F8 __asm__("D_8006C7F8");
extern int Actor1228_D_8006D088 __asm__("D_8006D088");
extern int Actor1228_D_8006E020 __asm__("D_8006E020");
extern int Actor1228_D_8006E788 __asm__("D_8006E788");
extern int Actor1228_D_8006EE2C __asm__("D_8006EE2C");
extern int Actor1228_D_80070328 __asm__("D_80070328");
extern int Actor1228_D_level_28_800746EC __asm__("D_level_28_800746EC");
extern int Actor1228_D_level_28_800746F8 __asm__("D_level_28_800746F8");
extern int Actor1228_SpawnMoby __asm__("SpawnMoby");
extern int Actor1228_SpawnParticle __asm__("SpawnParticle");
extern int Actor1228_unk_ovlheader_80074320 __asm__("unk_ovlheader_80074320");
extern int Actor1228_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Actor1228_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Actor1228_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
int Actor1228QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int Actor1228TestPlayerSphereOverlap() __asm__("func_8001C288");
int Actor1228ConfigureHudEntry() __asm__("func_8002803C");
int Actor1228ResetHudEntryByHandle() __asm__("func_80028154");
int Actor1228RequestMobyAnimation() __asm__("func_80034F40");
int Actor1228TurnMobyTowardPlayer() __asm__("func_8003573C");
int Actor1228CountTimerDown() __asm__("func_800359A4");
int Actor1228AddAngle8() __asm__("func_8003617C");
int Actor1228TestPaddedRotatedBox() __asm__("func_80036220");
int Actor1228GetClosestPathNode() __asm__("func_8003645C");
int Actor1228EmitMobyVertexParticles() __asm__("func_800369B8");
int Actor1228RegisterTrackedValue() __asm__("func_8003B7B4");
int Actor1228MarkMobyCollectionBit() __asm__("func_8003BA00");
int Actor1228PlayMobySoundEvent() __asm__("func_8003BABC");
int Actor1228TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int Actor1228SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int Actor1228PlanarHeadingLookup() __asm__("func_8004E880");
int Actor1228BuildPackedAngleBasisMatrix() __asm__("func_8004EA90");
int Actor1228TransformVectorByBasis() __asm__("func_8004ED6C");
int Actor1228MeasureVectorLength() __asm__("func_8004EDE8");
int Actor1228ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Actor1228ShiftVectorLeft() __asm__("func_8004F0E8");
int Actor1228ShiftVectorRightTowardZero() __asm__("func_8004F110");
int Actor1228CopyVector() __asm__("func_8004F178");
int Actor1228AddVector() __asm__("func_8004F194");
int Actor1228ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor1228ClearHistorySourceWord() __asm__("func_800509E8");
int Actor1228DeleteMoby() __asm__("func_80055B18");
int Actor1228InitializeMobySpatialGridAndBasis() __asm__("func_80055C24");
int Actor1228RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor1228_func_rand() __asm__("rand");
void func_level_28_8007E7CC(void* input) {
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
    register int actor __asm__("$22");
    register int valueS7 __asm__("$23");
    register int valueT8 __asm__("$24");
    register int valueT9 __asm__("$25");
    int privateData, stackArgument4, stackArgument5, stackArgument6, stackArgument7;
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
    } frame;
    long long completeSignedProduct;
    int actualHeader68, actualHeader6C;
    argument0 = (int)input;
    actor = (int)((unsigned int)argument0 + (unsigned int)0);
    Actor1228Keep(actor);
    valueS0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(valueS0);
    argument0 = (int)&Actor1228_D_80070328;
    Actor1228Keep(argument0);
    privateData = Actor1228Field(actor, int*, 0);
    Actor1228Keep(privateData);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueT1 = Actor1228Field(privateData, int*, 60);
    Actor1228Keep(valueT1);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument3);
    Actor1228Field((int)&frame, int*, 128) = valueT1;
    __asm__ volatile("" ::"m"(Actor1228Field((int)&frame, int*, 128)) : "$8", "memory");
    valueT0 = (int)&Actor1228_D_level_28_800746EC;
    Actor1228Keep(valueT0);
    valueV0 = Actor1228Field(valueT0, int*, 0);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(valueT0, int*, 4);
    Actor1228Keep(valueV1);
    argument1 = Actor1228Field(valueT0, int*, 8);
    Actor1228Keep(argument1);
    Actor1228Field((int)&frame, int*, 0) = valueV0;
    Actor1228Field((int)&frame, int*, 4) = valueV1;
    Actor1228Field((int)&frame, int*, 8) = argument1;
    valueV0 = Actor1228Field(privateData, int*, 28);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14544);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 0);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)privateData + (unsigned int)36);
    Actor1228Keep(argument1);
    Actor1228Field((int)&frame, int*, 136) = valueV0;
    valueV0 = Actor1228TestPaddedRotatedBox(argument0, argument1, argument2, argument3);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)-1), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)-1), 0))
        goto original1228_64;
    valueV1 = Actor1228Field(privateData, int*, 32);
    Actor1228Keep(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)7), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)7), 0))
        goto original1228_72;
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
    argument0 = (int)((unsigned int)0 + (unsigned int)53);
    if (valueV1 == valueV0)
        goto original1228_64;
    actualHeader68 = Actor1228_unk_ovlheader_80074368;
    actualHeader6C = Actor1228_unk_ovlheader_8007436C;
    __asm__(""
            : "=r"(privateData)
            : "0"(privateData), "r"(actualHeader68), "r"(actualHeader6C)
            : "$2");
    stackArgument5 = (int)((unsigned int)privateData + (unsigned int)20);
    stackArgument6 = (int)((unsigned int)0 + (unsigned int)50);
    stackArgument4 = Actor1228_unk_ovlheader_80074364;
    argument1 = (int)((unsigned int)0 + (unsigned int)280);
    valueV0 = Actor1228ConfigureHudEntry(argument0, argument1, actualHeader68, actualHeader6C,
                                         stackArgument4, stackArgument5, stackArgument6);
    valueV0 = (int)((unsigned int)valueV0 << 16);
    Actor1228Keep(valueV0);
    valueV0 = (valueV0 >> 16);
    Actor1228Keep(valueV0);
    Actor1228Field(privateData, int*, 32) = valueV0;
    goto original1228_72;
original1228_64:
    valueV1 = Actor1228Field(privateData, int*, 32);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)-1);
    Actor1228Keep(valueV0);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)7), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)7), 0))
        goto original1228_72;
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
    if (valueV1 != valueV0)
        goto original1228Return;
original1228_72:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    valueS5 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228_80;
original1228_77:
    valueV0 = valueS5 < 8;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_108;
original1228_80:
    valueT1 = Actor1228Field((int)&frame, volatile int*, 136);
    Actor1228Keep(valueT1);
    valueV0 = (int)((unsigned int)valueS5 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueT1);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(valueV0, unsigned short*, 0);
    Actor1228Keep(valueV1);
    valueV1 = valueV1 & 32767;
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -15024);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, unsigned char*, 72);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_100;
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(valueS0);
original1228_100:
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    valueS5 = (int)((unsigned int)valueS5 + (unsigned int)1);
    if (valueV0 != 0)
        goto original1228_77;
    valueV0 = valueS5 < 4;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_80;
original1228_108:
    valueV0 = (int)((unsigned int)0 + (unsigned int)2);
    if (valueS0 == 0)
        goto original1228_147;
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
    if (valueV1 != valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)5), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)5), 0))
        goto original1228_149;
    valueV0 = Actor1228Field(privateData, int*, 12);
    Actor1228Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)5), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)5), 0))
        goto original1228_149;
    valueV0 = Actor1228Field(actor, unsigned char*, 77);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228_148;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)3);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    Actor1228RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(privateData, int*, 68);
    Actor1228Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)(int)&frame + (unsigned int)valueV0 - 32U);
    Actor1228Keep(valueV0);
    /* Original Rev0 0x8007e9d8; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,32(%1)" : "=r"(valueV0) : "0"(valueV0) : "memory");
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    Actor1228Field(privateData, int*, 12) = valueV0;
    valueV0 = Actor1228SoundHandleMatchesOwnerInStates1Or2(argument0, argument1);
    if (valueV0 == 0)
        goto original1228_147;
    argument1 = Actor1228Field(privateData, int*, 68);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1228SoundHandleMatchesOwnerInStates1Or2(argument0, argument1);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)-1), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)-1), 0))
        goto original1228_146;
    argument0 = Actor1228Field(privateData, int*, 68);
    Actor1228Keep(argument0);
    valueV0 = Actor1228TransitionSoundHandleTo3Or5(argument0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)-1);
    Actor1228Keep(valueV0);
original1228_146:
    Actor1228Field(privateData, int*, 68) = valueV0;
original1228_147:
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
original1228_148:
    valueV0 = (int)((unsigned int)0 + (unsigned int)5);
    Actor1228Keep(valueV0);
original1228_149:
    if (valueV1 == valueV0)
        goto original1228_344;
    valueS7 = (int)&Actor1228_D_8006E788;
    Actor1228Keep(valueS7);
    valueS2 = Actor1228Field(valueS7, int*, 0);
    Actor1228Keep(valueS2);
    valueS7 = (int)((unsigned int)valueS7 + (unsigned int)4);
    if (valueS2 == 0)
        goto original1228_344;
    valueS5 = (int)&frame.sp30;
    Actor1228Keep(valueS5);
original1228_158:
    valueV0 = Actor1228Field(valueS2, unsigned char*, 72);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor1228Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)373), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)373), 0))
        goto original1228_340;
    valueV1 = Actor1228Field(valueS2, short*, 54);
    Actor1228Keep(valueV1);
    Actor1228Keep(valueV1);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)187), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)187), 0))
        goto original1228_171;
    valueT1 = (int)((unsigned int)0 + (unsigned int)151);
    if (valueV1 == valueV0)
        goto original1228_171;
    if (valueV1 != valueT1)
        goto original1228_340;
original1228_171:
    argument0 = (int)((unsigned int)actor + (unsigned int)12);
    Actor1228Keep(argument0);
    valueS3 = (int)((unsigned int)valueS2 + (unsigned int)12);
    Actor1228Keep(valueS3);
    argument1 = (int)((unsigned int)valueS3 + (unsigned int)0);
    valueV0 = Actor1228ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 2048;
    Actor1228Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)2), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)2), 0))
        goto original1228_340;
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    if (valueV1 != valueV0)
        goto original1228_315;
    valueV1 = Actor1228Field(valueS2, short*, 54);
    Actor1228Keep(valueV1);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)373);
    Actor1228Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV1 != valueV0)
        goto original1228_237;
    valueV1 = Actor1228Field(valueS2, int*, 12);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(argument0);
    valueV0 = Actor1228Field(valueS2, int*, 16);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(argument1);
    valueS1 = Actor1228Field(valueS2, int*, 0);
    Actor1228Keep(valueS1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1228PlanarHeadingLookup(argument0, argument1, argument2);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1228_func_rand();
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = valueV0 & 31;
    valueV0 = Actor1228AddAngle8(argument0, argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    valueT1 = (int)&Actor1228_D_80065920;
    Actor1228Keep(valueT1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueT1);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV1 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 4);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (valueV0 >> 10);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS1, int*, 0) = valueV0;
    valueV1 = Actor1228Field(valueS2, int*, 12);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(argument0);
    valueV0 = Actor1228Field(valueS2, int*, 16);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1228PlanarHeadingLookup(argument0, argument1, argument2);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1228_func_rand();
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = valueV0 & 31;
    valueV0 = Actor1228AddAngle8(argument0, argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    argument0 = Actor1228Field(
        ((int)((unsigned int)(int)&Actor1228_D_800658A0 + (unsigned int)valueV0)), short*, 0);
    Actor1228Keep(argument0);
    Actor1228Keep(argument0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)30);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS1, int*, 8) = 0;
    Actor1228Field(valueS1, int*, 12) = valueV0;
    __asm__ volatile("" ::"m"(Actor1228Field(valueS1, int*, 12)) : "memory");
    valueV1 = (int)((unsigned int)argument0 << 2);
    Actor1228Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)argument0);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 4);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (valueV0 >> 10);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS1, int*, 4) = valueV0;
    goto original1228_340;
original1228_237:
    valueS0 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1228_func_rand();
    valueS1 = valueV0 & 255;
    Actor1228Keep(valueS1);
    valueS4 = (int)((unsigned int)valueS3 + (unsigned int)0);
    Actor1228Keep(valueS4);
    valueV0 = (int)((unsigned int)valueS1 << 1);
    Actor1228Keep(valueV0);
    valueT1 = (int)&Actor1228_D_80065920;
    Actor1228Keep(valueT1);
    valueS3 = (int)((unsigned int)valueV0 + (unsigned int)valueT1);
    Actor1228Keep(valueS3);
original1228_245:
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)55);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS4 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = Actor1228Field(valueS3, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, 17124);
    Actor1228Keep(valueV1);
    valueV0 = (valueV0 >> 7);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 16) = valueV0;
    valueV0 = (int)((unsigned int)valueS1 << 1);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(
        ((int)((unsigned int)(int)&Actor1228_D_800658A0 + (unsigned int)valueV0)), short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    argument3 = (int)((unsigned int)valueS5 + (unsigned int)0);
    Actor1228Keep(argument3);
    Actor1228Field((int)&frame, int*, 24) = 0;
    __asm__("" : "=r"(valueV0) : "0"(valueV0), "m"(Actor1228Field((int)&frame, int*, 24)));
    valueV0 = (valueV0 >> 7);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 20) = valueV0;
    valueV0 = ((int (*)())valueV1)(argument0, argument1, argument2, argument3);
    valueV0 = valueS0 & 1;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueS5 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228_275;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    valueV0 = Actor1228ShiftVectorRightTowardZero(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)55);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS4 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17124);
    Actor1228Keep(valueV0);
    argument3 = (int)((unsigned int)valueS5 + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1, argument2, argument3);
original1228_275:
    valueS3 = (int)((unsigned int)valueS3 + (unsigned int)64);
    Actor1228Keep(valueS3);
    valueS0 = (int)((unsigned int)valueS0 + (unsigned int)1);
    Actor1228Keep(valueS0);
    valueV0 = valueS0 < 8;
    Actor1228Keep(valueV0);
    valueS1 = (int)((unsigned int)valueS1 + (unsigned int)32);
    if (valueV0 != 0)
        goto original1228_245;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)0 + (unsigned int)326);
    if (valueV0 != 0)
        goto original1228_301;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17120);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueV1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)8);
    if (valueV1 == 0)
        goto original1228_301;
    Actor1228Field(valueV1, unsigned char*, 71) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)63);
    Actor1228Keep(valueV0);
    Actor1228Field(valueV1, unsigned char*, 76) = valueV0;
    Actor1228Field(valueV1, unsigned char*, 78) = valueV0;
original1228_301:
    valueV1 = Actor1228Field(valueS2, short*, 54);
    Actor1228Keep(valueV1);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)187);
    Actor1228Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1228_319;
    valueV0 = Actor1228Field(valueS2, int*, 0);
    Actor1228Keep(valueV0);
    argument0 = Actor1228Field(valueV0, int*, 8);
    Actor1228Keep(argument0);
    if (argument0 == 0)
        goto original1228_319;
    Actor1228ClearHistorySourceWord(argument0);
    goto original1228_319;
original1228_315:
    argument1 = (int)((unsigned int)0 + (unsigned int)24);
    Actor1228Keep(argument1);
    valueV0 = (int)0x00010000U;
    Actor1228Keep(valueV0);
    Actor1228Field(actor, int*, 24) = valueV0;
    Actor1228EmitMobyVertexParticles(argument0, argument1);
original1228_319:
    valueV0 = Actor1228Field(valueS2, short*, 54);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueT1 = (int)((unsigned int)0 + (unsigned int)151);
    Actor1228Keep(valueT1);
    if (valueV0 != valueT1)
        goto original1228_338;
    valueV0 = Actor1228Field(valueS2, int*, 0);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(valueV0, int*, 8);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1228SoundHandleMatchesOwnerInStates1Or2(argument0, argument1);
    if (valueV0 == 0)
        goto original1228_338;
    valueV0 = Actor1228Field(valueS2, int*, 0);
    Actor1228Keep(valueV0);
    argument0 = Actor1228Field(valueV0, int*, 8);
    Actor1228Keep(argument0);
    valueV0 = Actor1228TransitionSoundHandleTo3Or5(argument0);
    valueV1 = Actor1228Field(valueS2, int*, 0);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)-1);
    Actor1228Keep(valueV0);
    Actor1228Field(valueV1, int*, 8) = valueV0;
original1228_338:
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1228DeleteMoby(argument0);
original1228_340:
    valueS2 = Actor1228Field(valueS7, int*, 0);
    Actor1228Keep(valueS2);
    valueS7 = (int)((unsigned int)valueS7 + (unsigned int)4);
    if (valueS2 != 0)
        goto original1228_158;
original1228_344:
    valueV0 = Actor1228Field(actor, int*, 24);
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_532;
    valueV0 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)-5);
    Actor1228Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 2;
    Actor1228Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)255), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)255), 0))
        goto original1228_532;
    Actor1228Field(actor, unsigned char*, 84) = valueV0;
    Actor1228Field(actor, unsigned char*, 85) = valueV0;
    Actor1228Field(actor, unsigned char*, 86) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)63);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 87) = valueV0;
    valueV0 = Actor1228Field(privateData, int*, 20);
    Actor1228Keep(valueV0);
    if (valueV0 <= 0 ? (valueV0 = (int)((unsigned int)valueV0 + (unsigned int)-1), 1)
                     : (valueV0 = (int)((unsigned int)valueV0 + (unsigned int)-1), 0))
        goto original1228_365;
    Actor1228Field(privateData, int*, 20) = valueV0;
    if (valueV0 > 0)
        goto original1228_526;
original1228_365:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)3);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = (int)((unsigned int)0 + (unsigned int)5);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1228PlayMobySoundEvent(argument0, argument1, argument2);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    valueS5 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228_379;
original1228_376:
    valueV0 = valueS5 < 8;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_536;
original1228_379:
    valueT1 = Actor1228Field((int)&frame, volatile int*, 136);
    Actor1228Keep(valueT1);
    valueV0 = (int)((unsigned int)valueS5 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueT1);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(valueV0, unsigned short*, 0);
    Actor1228Keep(valueV1);
    valueV1 = valueV1 & 32767;
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -15024);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(argument1);
    valueV0 = Actor1228Field(argument1, unsigned char*, 72);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_516;
    valueS0 = (int)((unsigned int)argument1 + (unsigned int)0);
    valueV0 = Actor1228_func_rand();
    valueS3 = valueV0 & 255;
    Actor1228Keep(valueS3);
    valueS1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(valueS1);
    valueS7 = (int)((unsigned int)valueS0 + (unsigned int)12);
    Actor1228Keep(valueS7);
    valueS4 = (int)&frame.sp30;
    Actor1228Keep(valueS4);
    valueV1 = (int)&Actor1228_D_80065920;
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueS3 << 1);
    Actor1228Keep(valueV0);
    valueS2 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueS2);
original1228_408:
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)55);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS7 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = Actor1228Field(valueS2, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, 17124);
    Actor1228Keep(valueV1);
    valueV0 = (valueV0 >> 7);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 16) = valueV0;
    valueV0 = (int)((unsigned int)valueS3 << 1);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(
        ((int)((unsigned int)(int)&Actor1228_D_800658A0 + (unsigned int)valueV0)), short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    argument3 = (int)((unsigned int)valueS4 + (unsigned int)0);
    Actor1228Keep(argument3);
    Actor1228Field((int)&frame, int*, 24) = 0;
    __asm__("" : "=r"(valueV0) : "0"(valueV0), "m"(Actor1228Field((int)&frame, int*, 24)));
    valueV0 = (valueV0 >> 7);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 20) = valueV0;
    valueV0 = ((int (*)())valueV1)(argument0, argument1, argument2, argument3);
    valueV0 = valueS1 & 1;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueS4 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228_438;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    valueV0 = Actor1228ShiftVectorRightTowardZero(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)55);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS7 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17124);
    Actor1228Keep(valueV0);
    argument3 = (int)((unsigned int)valueS4 + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1, argument2, argument3);
original1228_438:
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)64);
    Actor1228Keep(valueS2);
    valueS1 = (int)((unsigned int)valueS1 + (unsigned int)1);
    Actor1228Keep(valueS1);
    valueV0 = valueS1 < 8;
    Actor1228Keep(valueV0);
    valueS3 = (int)((unsigned int)valueS3 + (unsigned int)32);
    if (valueV0 != 0)
        goto original1228_408;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_465;
    argument0 = (int)((unsigned int)0 + (unsigned int)326);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17120);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueS0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)8);
    if (valueS0 == 0)
        goto original1228_465;
    Actor1228Field(valueS0, unsigned char*, 71) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)63);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, unsigned char*, 76) = valueV0;
    Actor1228Field(valueS0, unsigned char*, 78) = valueV0;
original1228_465:
    valueT1 = Actor1228Field((int)&frame, volatile int*, 136);
    Actor1228Keep(valueT1);
    valueS0 = (int)((unsigned int)valueS5 << 1);
    Actor1228Keep(valueS0);
    valueS0 = (int)((unsigned int)valueS0 + (unsigned int)valueT1);
    Actor1228Keep(valueS0);
    valueV0 = Actor1228Field(valueS0, unsigned short*, 0);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Actor1228Keep(argument1);
    valueV0 = valueV0 & 32767;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)valueV0);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 - (unsigned int)valueV0);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -15024);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    Actor1228RefreshMobySpatialGridAndBasis(argument0, argument1);
    valueV0 = Actor1228Field(valueS0, unsigned short*, 0);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 32767;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)valueV0);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 - (unsigned int)valueV0);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -15024);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    valueV0 = Actor1228MarkMobyCollectionBit(argument0);
    valueV0 = Actor1228Field(valueS0, unsigned short*, 0);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)0 + (unsigned int)24);
    Actor1228Keep(argument1);
    valueV0 = valueV0 & 32767;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)valueV0);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 - (unsigned int)valueV0);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -15024);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    Actor1228EmitMobyVertexParticles(argument0, argument1);
    valueV0 = Actor1228Field(valueS0, unsigned short*, 0);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 32767;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)valueV0);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)argument0 - (unsigned int)valueV0);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -15024);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)argument0 << 3);
    Actor1228Keep(argument0);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    valueV0 = Actor1228DeleteMoby(argument0);
original1228_516:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    valueS5 = (int)((unsigned int)valueS5 + (unsigned int)1);
    if (valueV0 != 0)
        goto original1228_376;
    valueV0 = valueS5 < 4;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_536_from522;
    goto original1228_379;
original1228_526:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1228PlayMobySoundEvent(argument0, argument1, argument2);
    goto original1228_536;
original1228_532:
    Actor1228Field(actor, unsigned char*, 84) = 0;
    Actor1228Field(actor, unsigned char*, 85) = 0;
    Actor1228Field(actor, unsigned char*, 86) = 0;
    Actor1228Field(actor, unsigned char*, 87) = 0;
original1228_536_from522:
    MATCHING_OBSERVE_VOLATILE(actor);
original1228_536:
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, int*, 24) = 0;
    if (valueV1 != valueV0)
        goto original1228_559;
    argument0 = (int)((unsigned int)actor + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2048);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument3);
    valueV0 = (int)0x00030000U;
    Actor1228Keep(valueV0);
    stackArgument4 = valueV0;
    stackArgument5 = 0;
    valueV0 = Actor1228QueryDynamicMobyGeometry(argument0, argument1, argument2, argument3,
                                                stackArgument4, stackArgument5);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueS0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueS0 == 0)
        goto original1228_559;
    valueV1 = Actor1228Field(valueS0, int*, 12);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(argument0);
    valueV0 = Actor1228Field(valueS0, int*, 16);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1228PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1228Field(valueS0, unsigned char*, 81) = valueV0;
original1228_559:
    argument0 = (int)((unsigned int)actor + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2048);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)7);
    valueV0 = Actor1228TestPlayerSphereOverlap(argument0, argument1, argument2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228_604;
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, 808);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 812);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1228PlanarHeadingLookup(argument0, argument1, argument2);
    valueV1 = (int)0x10000000U;
    Actor1228Keep(valueV1);
    valueV1 = valueV1 | 1024;
    Actor1228Keep(valueV1);
    valueV0 = valueV0 & 255;
    Actor1228Keep(valueV0);
    Actor1228Field((int)&Actor1228_D_80070328 + 664, int*, 0) = valueV0;
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&Actor1228_D_80070328 + 524, int*, 0) = valueV1;
    argument0 = Actor1228Field(
        ((int)((unsigned int)(int)&Actor1228_D_80065920 + (unsigned int)valueV0)), short*, 0);
    Actor1228Keep(argument0);
    Actor1228Keep(argument0);
    valueV1 = (int)((unsigned int)argument0 << 3);
    Actor1228Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)argument0);
    Actor1228Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1228Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(valueV1);
    valueV1 = (valueV1 >> 10);
    Actor1228Keep(valueV1);
    Actor1228Field((int)&Actor1228_D_80070328 + 540, int*, 0) = valueV1;
    valueV1 = Actor1228Field(
        ((int)((unsigned int)(int)&Actor1228_D_800658A0 + (unsigned int)valueV0)), short*, 0);
    Actor1228Keep(valueV1);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 3);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (valueV0 >> 10);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&Actor1228_D_80070328 + 544, int*, 0) = valueV0;
original1228_604:
    valueV1 = Actor1228Field(actor, unsigned char*, 72);
    Actor1228Keep(valueV1);
    switch ((unsigned int)valueV1) {
        case 0:
            MATCHING_OBSERVE_VOLATILE(valueV1);
            goto original1228_615;
        case 1:
            goto original1228_627;
        case 2:
            goto original1228_644;
        case 3:
            goto original1228_753;
        case 4:
            goto original1228_771;
        case 5:
            goto original1228_947;
        case 6:
            goto original1228_1102;
        case 7:
            goto original1228_1205;
        default:
            goto original1228Return;
    }
original1228_615:
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)(int)&frame + (unsigned int)valueV0 - 32U);
    Actor1228Keep(valueV0);
    /* Original Rev0 0x8007f17c; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,32(%1)" : "=r"(valueV0) : "0"(valueV0) : "memory");
    Actor1228Field(privateData, int*, 12) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)50);
    Actor1228Keep(valueV0);
    Actor1228Field(privateData, int*, 20) = valueV0;
original1228_627:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1228TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)privateData + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    valueV0 = Actor1228CountTimerDown(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)180);
    Actor1228Keep(valueV0);
    Actor1228Field(privateData, int*, 12) = valueV0;
    goto original1228Return;
original1228_644:
    argument1 = Actor1228Field(privateData, int*, 68);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1228SoundHandleMatchesOwnerInStates1Or2(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 != 0)
        goto original1228_654;
    MATCHING_BARRIER_VOLATILE("$2");
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)4);
    valueV0 = Actor1228PlayMobySoundEvent(argument0, argument1, argument2);
    Actor1228Field(privateData, int*, 68) = valueV0;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
original1228_654:
    argument1 = (int)((unsigned int)0 + (unsigned int)16);
    Actor1228Keep(argument1);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17184);
    Actor1228Keep(valueV0);
    argument2 = (int)((unsigned int)privateData + (unsigned int)16);
    valueV0 = ((int (*)())valueV0)(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)privateData + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    valueV0 = Actor1228CountTimerDown(argument0, argument1);
    valueT1 = Actor1228Field((int)&frame, volatile int*, 128);
    Actor1228Keep(valueT1);
    argument0 = (int)((unsigned int)actor + (unsigned int)12);
    if (valueT1 == 0)
        goto original1228Return;
    argument1 = Actor1228Field((int)&frame, volatile int*, 128);
    Actor1228Keep(argument1);
    argument2 = (int)&frame.sp40;
    valueV0 = Actor1228GetClosestPathNode(argument0, argument1, argument2);
    valueT1 = Actor1228Field((int)&frame, volatile int*, 128);
    Actor1228Keep(valueT1);
    argument0 = Actor1228Field((int)&frame, volatile int*, 32);
    Actor1228Keep(argument0);
    valueV1 = Actor1228Field(valueT1, short*, 2);
    Actor1228Keep(valueV1);
    Actor1228Keep(valueV1);
    /* Original closed 674..698 instruction block, mixed C/assembly.
    * GP2/3/4/9 are real initialized values from the immediately preceding
    * native loads/call. GP16 and GP5 are defined along every exit path.
    * The explicit memory operand binds frame.sp40 at original SP40.
    * Other reads remain original SPA0 and the original T1 field reads.
    * Conditional SH retains its original address and order. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "beq\t$4,$3,4f\n\t"
                     "slti\t$2,$2,513\n\t"
                     "bne\t$2,$0,6f\n\t"
                     "addiu\t$16,$sp,48\n\t"
                     "bne\t$3,$0,1f\n\t"
                     "addiu\t$2,$3,-1\n\t"
                     "lh\t$2,0($9)\n\t"
                     "nop\n\t"
                     "addiu\t$2,$2,-1\n\t"
                     "bne\t$4,$2,2f\n\t"
                     "addu\t$4,$16,$0\n\t"
                     "j\t7f\n\t"
                     "nop\n\t"
                     "1: beq\t$4,$2,5f\n\t"
                     "addiu\t$16,$sp,48\n\t"
                     "2: lw\t$2,%9\n\t"
                     "lw\t$9,160($sp)\n\t"
                     "nop\n\t"
                     "sh\t$2,2($9)\n\t"
                     "4: addiu\t$16,$sp,48\n\t"
                     "5: lw\t$9,160($sp)\n\t"
                     "6: addu\t$4,$16,$0\n\t"
                     "7: lh\t$5,2($9)\n\t"
                     "lw\t$2,12($9)\n\t"
                     "sll\t$5,$5,4\n\t"
                     ".set\treorder"
                     : "=r"(valueV0), "=r"(argument0), "=r"(argument1), "=r"(valueT1), "=r"(valueS0)
                     : "0"(valueV0), "1"(argument0), "3"(valueT1), "r"(valueV1), "m"(frame.sp40)
                     : "memory");
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)argument1);
    valueV0 = Actor1228CopyVector(argument0, argument1);
    Actor1228Keep(actor);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV1 = Actor1228Field((int)&frame, volatile int*, 16);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(argument0);
    valueV0 = Actor1228Field((int)&frame, volatile int*, 20);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1228PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = (int)0x51EB0000U;
    Actor1228Keep(argument1);
    argument1 = argument1 | 34079;
    Actor1228Keep(argument1);
    argument0 = Actor1228Field(privateData, int*, 20);
    Actor1228Keep(argument0);
    valueV1 = (int)((unsigned int)0 + (unsigned int)50);
    Actor1228Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(valueV1);
    valueT0 = (int)((unsigned int)valueV1 << 2);
    Actor1228Keep(valueT0);
    valueT0 = (int)((unsigned int)valueT0 + (unsigned int)valueV1);
    Actor1228Keep(valueT0);
    valueT0 = (int)((unsigned int)valueT0 << 4);
    Actor1228Keep(valueT0);
    Actor1228Keep(valueT0);
    Actor1228Keep(argument1);
    completeSignedProduct = (long long)valueT0 * (long long)argument1;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument3);
    /* Original719..728, mixed C/assembly: six scalar o32 arguments.
    * SP10/SP14 are actual allocated outgoing homes, not a C array view.
    * GP7 was initialized to zero immediately before this packet. GP2 is
    * the real E880 return; GP8 and whole HI/LO are the initialized product.
    * Saved actor supplies A0. Callee scratch and return are explicit. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "sw\t$zero,16($sp)\n\t"
                     "sw\t$zero,20($sp)\n\t"
                     "addu\t$4,$22,$zero\n\t"
                     "andi\t$5,$2,255\n\t"
                     "sra\t$8,$8,31\n\t"
                     "mfhi\t$9\n\t"
                     "sra\t$6,$9,4\n\t"
                     "subu\t$6,$6,$8\n\t"
                     "jal\tfunc_80035EE0\n\t"
                     "addiu\t$6,$6,80\n\t"
                     ".set\treorder"
                     : "=r"(valueV0), "=r"(valueT0), "=r"(argument3), "=x"(completeSignedProduct)
                     : "0"(valueV0), "1"(valueT0), "2"(argument3), "3"(completeSignedProduct),
                       "r"(actor)
                     : "$3", "$4", "$5", "$6", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
                       "$24", "$25", "$31", "memory");
    argument0 = (int)((unsigned int)actor + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1228ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 512;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228Return;
    valueT1 = Actor1228Field((int)&frame, volatile int*, 128);
    Actor1228Keep(valueT1);
    valueV0 = Actor1228Field(valueT1, short*, 2);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(valueT1, short*, 0);
    Actor1228Keep(valueV1);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)1);
    Actor1228Keep(valueV0);
    valueV1 = valueV0 % valueV1;
    Actor1228Keep(valueV1);
    Actor1228Field(valueT1, short*, 2) = valueV1;
    goto original1228Return;
original1228_753:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1228TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)privateData + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    valueV0 = Actor1228CountTimerDown(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)3);
    Actor1228RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)4);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)20);
    Actor1228Keep(valueV0);
    Actor1228Field(privateData, int*, 12) = valueV0;
    Actor1228Field(privateData, int*, 24) = 0;
    goto original1228Return;
original1228_771:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1228TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)privateData + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    valueV0 = Actor1228CountTimerDown(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1228Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1228PlayMobySoundEvent(argument0, argument1, argument2);
    valueS2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(valueS2);
    valueS4 = (int)&Actor1228_D_80065920;
    Actor1228Keep(valueS4);
    valueS3 = (int)&Actor1228_D_800658A0;
    Actor1228Keep(valueS3);
original1228_789:
    argument1 = (int)&Actor1228_D_level_28_800746F8;
    Actor1228Keep(argument1);
    valueV0 = Actor1228Field(argument1, int*, 0);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(argument1, int*, 4);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(argument1, int*, 8);
    Actor1228Keep(argument0);
    Actor1228Field((int)&frame, int*, 40) = valueV0;
    Actor1228Field((int)&frame, int*, 44) = valueV1;
    Actor1228Field((int)&frame, int*, 48) = argument0;
    valueV0 = Actor1228Field(argument1, int*, 12);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 52) = valueV0;
    valueS5 = Actor1228Field(privateData, int*, 24);
    Actor1228Keep(valueS5);
    valueT1 = Actor1228Field((int)&frame, volatile int*, 136);
    Actor1228Keep(valueT1);
    valueV0 = (int)((unsigned int)valueS5 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueT1);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(valueV0, unsigned short*, 0);
    Actor1228Keep(valueV1);
    valueV1 = valueV1 & 32767;
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -15024);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1228Keep(valueV0);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueS0);
    valueV0 = Actor1228Field(valueS0, unsigned char*, 72);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 128;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_907;
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228InitializeMobySpatialGridAndBasis(argument0);
    valueV0 = Actor1228Field(valueS0, short*, 54);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, int*, 24) = 0;
    Actor1228Field(valueS0, unsigned char*, 81) = 0;
    Actor1228Field(valueS0, unsigned char*, 72) = 0;
    Actor1228Field(valueS0, unsigned char*, 66) = 0;
    __asm__(""
            : "=r"(valueV0)
            : "0"(valueV0), "m"(Actor1228Field(valueS0, unsigned char*, 66))
            : "memory");
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(
        ((int)((unsigned int)(int)&Actor1228_D_8006EE2C + (unsigned int)valueV0)), int*, 0);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 60);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, unsigned char*, 0);
    Actor1228Keep(valueV0);
    valueV1 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(valueV1);
    Actor1228Field(valueS0, unsigned char*, 60) = 0;
    Actor1228Field(valueS0, unsigned char*, 61) = 0;
    Actor1228Field(valueS0, unsigned char*, 62) = 0;
    Actor1228Field(valueS0, unsigned char*, 63) = valueV1;
    __asm__(""
            : "=r"(valueV0)
            : "0"(valueV0), "m"(Actor1228Field(valueS0, unsigned char*, 63))
            : "memory");
    valueV0 = (unsigned int)valueV0 < 2;
    Actor1228Keep(valueV0);
    valueV0 = valueV0 ^ 1;
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 & 48;
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, unsigned char*, 64) = valueV0;
    valueV0 = Actor1228Field(actor, unsigned char*, 70);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueS4);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueV0 = (valueV0 >> 1);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 56) = valueV0;
    valueV0 = Actor1228Field(actor, unsigned char*, 70);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueS3);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueS1 = (int)((unsigned int)valueS2 << 2);
    Actor1228Keep(valueS1);
    Actor1228Field((int)&frame, int*, 64) = 0;
    __asm__("" : "=r"(valueV0) : "0"(valueV0), "m"(Actor1228Field((int)&frame, int*, 64)));
    valueV0 = (valueV0 >> 1);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 60) = valueV0;
    valueV0 = (int)&frame.sp20;
    Actor1228Keep(valueV0);
    valueS1 = (int)((unsigned int)valueS1 + (unsigned int)valueV0);
    Actor1228Keep(valueS1);
    argument0 = Actor1228Field(actor, unsigned char*, 70);
    Actor1228Keep(argument0);
    argument1 = Actor1228Field(valueS1, int*, 40);
    Actor1228Keep(argument1);
    valueV0 = Actor1228AddAngle8(argument0, argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueS4);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    valueV0 = (valueV0 >> 4);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 72) = valueV0;
    argument0 = Actor1228Field(actor, unsigned char*, 70);
    Actor1228Keep(argument0);
    argument1 = Actor1228Field(valueS1, int*, 40);
    Actor1228Keep(argument1);
    valueV0 = Actor1228AddAngle8(argument0, argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueS3);
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, short*, 0);
    Actor1228Keep(valueV0);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 80) = 0;
    __asm__("" : "=r"(valueV0) : "0"(valueV0), "m"(Actor1228Field((int)&frame, int*, 80)));
    valueV0 = (valueV0 >> 4);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 76) = valueV0;
    valueV0 = Actor1228Field((int)&frame, volatile int*, 56);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field((int)&frame, volatile int*, 72);
    Actor1228Keep(argument0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, int*, 12) = valueV0;
    valueV0 = Actor1228Field((int)&frame, volatile int*, 60);
    Actor1228Keep(valueV0);
    valueV1 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field((int)&frame, volatile int*, 76);
    Actor1228Keep(argument0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, int*, 16) = valueV0;
    valueV0 = Actor1228Field(actor, int*, 20);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, unsigned char*, 68) = 0;
    Actor1228Field(valueS0, unsigned char*, 69) = 0;
    Actor1228Field(valueS0, int*, 20) = valueV0;
    argument0 = Actor1228Field(actor, unsigned char*, 70);
    Actor1228Keep(argument0);
    argument1 = Actor1228Field(valueS1, int*, 40);
    Actor1228Keep(argument1);
    valueV0 = Actor1228AddAngle8(argument0, argument1);
    Actor1228Field(valueS0, unsigned char*, 70) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)20);
    Actor1228Keep(valueV0);
    Actor1228Field(privateData, int*, 12) = valueV0;
original1228_907:
    valueV1 = Actor1228Field(privateData, int*, 24);
    Actor1228Keep(valueV1);
    valueV0 = Actor1228Field(privateData, int*, 20);
    Actor1228Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)1);
    Actor1228Keep(valueV1);
    valueV0 = valueV0 < 34;
    Actor1228Keep(valueV0);
    Actor1228Field(privateData, int*, 24) = valueV1;
    if (valueV0 != 0)
        goto original1228_927;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = valueV1 < 8, 1) : (valueV0 = valueV1 < 8, 0))
        goto original1228_923;
    valueV0 = valueV1 < 4;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_930_from920;
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)1);
    goto original1228_942_from920;
original1228_923:
    if (valueV0 == 0)
        goto original1228_930;
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)1);
    goto original1228_942;
original1228_927:
    valueV0 = valueV1 < 4;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_941;
original1228_930_from920:
    MATCHING_OBSERVE_VOLATILE(actor);
original1228_930:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14396);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)(int)&frame + (unsigned int)valueV0 - 32U);
    Actor1228Keep(valueV0);
    /* Original Rev0 0x8007f668; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,32(%1)" : "=r"(valueV0) : "0"(valueV0) : "memory");
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument1);
    Actor1228Field(privateData, int*, 12) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    Actor1228RequestMobyAnimation(argument0, argument1);
original1228_941:
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)1);
    Actor1228Keep(valueS2);
original1228_942_from920:
    MATCHING_OBSERVE_VOLATILE(valueS2);
original1228_942:
    valueV0 = valueS2 < 4;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228Return;
    goto original1228_789;
original1228_947:
    argument0 = Actor1228Field(privateData, int*, 32);
    Actor1228Keep(argument0);
    valueV0 = (int)((unsigned int)0 + (unsigned int)-1);
    Actor1228Keep(valueV0);
    valueS5 = (int)((unsigned int)0 + (unsigned int)1);
    if (argument0 == valueV0)
        goto original1228_953;
    valueV0 = Actor1228ResetHudEntryByHandle(argument0);
original1228_953:
    valueS2 = (int)&frame.sp48;
    Actor1228Keep(valueS2);
    valueS3 = (int)((unsigned int)0 + (unsigned int)12);
    Actor1228Keep(valueS3);
original1228_955:
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)0 + (unsigned int)666);
    if (valueV0 != 0)
        goto original1228_1033;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17120);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueS1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)63);
    if (valueS1 == 0)
        goto original1228_1005;
    Actor1228Field(valueS1, unsigned char*, 76) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)255);
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1228Keep(argument0);
    Actor1228Field(valueS1, unsigned char*, 60) = valueS5;
    Actor1228Field(valueS1, unsigned char*, 74) = valueV0;
    argument1 = Actor1228Field(privateData, int*, 64);
    Actor1228Keep(argument1);
    valueS0 = Actor1228Field(valueS1, int*, 0);
    Actor1228Keep(valueS0);
    argument1 = (int)((unsigned int)argument1 + (unsigned int)valueS3);
    valueV0 = Actor1228CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)32);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1228TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS1 + (unsigned int)12);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)argument0 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1228AddVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    valueV0 = Actor1228MeasureVectorLength(argument0, argument1);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)140);
    Actor1228ScaleVectorRatioQ15(argument0, argument1, argument2);
    valueV0 = Actor1228Field((int)&frame, volatile int*, 40);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, short*, 0) = valueV0;
    valueV0 = Actor1228Field((int)&frame, volatile int*, 44);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, short*, 2) = valueV0;
    valueV0 = Actor1228Field((int)&frame, volatile int*, 48);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS0, short*, 4) = valueV0;
original1228_1005:
    valueS5 = (int)((unsigned int)valueS5 + (unsigned int)1);
    Actor1228Keep(valueS5);
    valueV0 = valueS5 < 5;
    Actor1228Keep(valueV0);
    valueS3 = (int)((unsigned int)valueS3 + (unsigned int)12);
    if (valueV0 != 0)
        goto original1228_955;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_1033;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14360);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 30001;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)0 + (unsigned int)326);
    if (valueV0 != 0)
        goto original1228_1033;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17120);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueV1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)7);
    if (valueV1 == 0)
        goto original1228_1033;
    Actor1228Field(valueV1, unsigned char*, 71) = valueV0;
original1228_1033:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    valueS5 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 != 0)
        goto original1228_1094;
    valueS3 = (int)&Actor1228_D_8006E020;
    Actor1228Keep(valueS3);
    MATCHING_KEEP_VOLATILE(valueV0);
    Actor1228Keep(valueS5);
    valueS2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(valueS2);
original1228_1045:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14360);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 30001;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)0 + (unsigned int)541);
    if (valueV0 != 0)
        goto original1228_1094;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17120);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueS1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueS1 == 0)
        goto original1228_1081;
    valueV1 = Actor1228Field(actor, int*, 12);
    Actor1228Keep(valueV1);
    argument0 = Actor1228Field(valueS3, int*, 0);
    Actor1228Keep(argument0);
    valueV0 = Actor1228Field(actor, int*, 16);
    Actor1228Keep(valueV0);
    argument1 = Actor1228Field(valueS3, int*, 4);
    Actor1228Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1228PlanarHeadingLookup(argument0, argument1, argument2);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1228_func_rand();
    valueS0 = (int)((unsigned int)valueS0 + (unsigned int)64);
    Actor1228Keep(valueS0);
    valueV0 = valueV0 & 31;
    Actor1228Keep(valueV0);
    valueS0 = (int)((unsigned int)valueS0 + (unsigned int)valueV0);
    Actor1228Keep(valueS0);
    Actor1228Field(valueS1, unsigned char*, 70) = valueS0;
    valueV0 = Actor1228_func_rand();
    valueV0 = valueV0 & 30;
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueS2 + (unsigned int)valueV0);
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)-15);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS1, unsigned char*, 69) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)8);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS1, unsigned char*, 71) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)42);
    Actor1228Keep(valueV0);
    Actor1228Field(valueS1, unsigned char*, 76) = valueV0;
original1228_1081:
    valueS5 = (int)((unsigned int)valueS5 + (unsigned int)1);
    Actor1228Keep(valueS5);
    valueV0 = valueS5 < 5;
    Actor1228Keep(valueV0);
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)51);
    if (valueV0 == 0)
        goto original1228_1094;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    if (valueV0 == 0)
        goto original1228_1045;
original1228_1094:
    valueV0 = (int)((unsigned int)0 + (unsigned int)20);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 65) = 0;
    Actor1228Field(actor, unsigned char*, 76) = 0;
    Actor1228Field(actor, unsigned char*, 77) = 0;
    Actor1228Field(privateData, int*, 12) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)6);
    Actor1228Keep(valueV0);
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    goto original1228Return;
original1228_1102:
    valueV0 = Actor1228Field(privateData, int*, 12);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 6;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_1152;
    MATCHING_OBSERVE_VOLATILE(valueS0);
    MATCHING_KEEP_VOLATILE(valueV0);
    valueS2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(valueS2);
    valueS3 = (int)&frame.sp88;
    Actor1228Keep(valueS3);
    valueS1 = (int)&frame.sp58;
    Actor1228Keep(valueS1);
    valueS0 = (int)&frame.sp78;
    Actor1228Keep(valueS0);
original1228_1111:
    Actor1228Field((int)&frame, unsigned char*, 72) = 0;
    valueV0 = Actor1228_func_rand();
    Actor1228Field((int)&frame, unsigned char*, 73) = valueV0;
    valueV0 = Actor1228_func_rand();
    argument0 = (int)&frame.sp68;
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueS3 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1228Keep(argument2);
    Actor1228Field((int)&frame, unsigned char*, 74) = valueV0;
    Actor1228BuildPackedAngleBasisMatrix(argument0, argument1, argument2);
    valueS2 = (int)((unsigned int)valueS2 + (unsigned int)1);
    valueV0 = Actor1228_func_rand();
    argument0 = (int)((unsigned int)valueS3 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS1 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = valueV0 & 31;
    Actor1228Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)48);
    Actor1228Keep(valueV0);
    Actor1228Field((int)&frame, int*, 56) = valueV0;
    Actor1228Field((int)&frame, int*, 60) = 0;
    Actor1228Field((int)&frame, int*, 64) = 0;
    Actor1228TransformVectorByBasis(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueS1 + (unsigned int)0);
    valueV0 = Actor1228CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Actor1228ShiftVectorLeft(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)actor + (unsigned int)12);
    valueV0 = Actor1228AddVector(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)13);
    Actor1228Keep(argument1);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument2);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17124);
    Actor1228Keep(valueV0);
    argument3 = (int)((unsigned int)valueS1 + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1, argument2, argument3);
    valueV0 = valueS2 < 4;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_1111;
original1228_1152:
    valueS0 = (int)0x80070000U;
    Actor1228Keep(valueS0);
    valueS0 = Actor1228Field(valueS0, int*, -14784);
    Actor1228Keep(valueS0);
    valueS0 = valueS0 & 1;
    valueV0 = Actor1228_func_rand();
    valueV0 = valueV0 & 1;
    Actor1228Keep(valueV0);
    argument0 = (int)((unsigned int)privateData + (unsigned int)12);
    if (valueS0 != valueV0)
        goto original1228_1187;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14984);
    Actor1228Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1228Keep(valueV1);
    valueV1 = Actor1228Field(valueV1, int*, -14988);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 21;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_1187;
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, -14360);
    Actor1228Keep(valueV0);
    valueV0 = valueV0 < 30001;
    Actor1228Keep(valueV0);
    if (valueV0 != 0)
        goto original1228_1187;
    argument0 = (int)((unsigned int)0 + (unsigned int)482);
    Actor1228Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1228Keep(valueV0);
    valueV0 = Actor1228Field(valueV0, int*, 17120);
    Actor1228Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueV1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1228Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)42);
    if (valueV1 == 0)
        goto original1228_1186;
    Actor1228Field(valueV1, unsigned char*, 76) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)10);
    Actor1228Keep(valueV0);
    Actor1228Field(valueV1, unsigned char*, 71) = valueV0;
original1228_1186:
    MATCHING_KEEP(privateData);
    argument0 = (int)((unsigned int)privateData + (unsigned int)12);
    Actor1228Keep(argument0);
original1228_1187:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    valueV0 = Actor1228CountTimerDown(argument0, argument1);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)7), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)7), 0))
        goto original1228Return;
    Actor1228Field(actor, unsigned char*, 72) = valueV0;
    valueS0 = (int)((unsigned int)actor + (unsigned int)72);
    Actor1228Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument2 = (int)&Actor1228_D_8006D088;
    Actor1228Keep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    valueV0 = Actor1228RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1228Keep(argument0);
    argument2 = (int)&Actor1228_D_8006C7F8;
    Actor1228Keep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    valueV0 = Actor1228RegisterTrackedValue(argument0, argument1, argument2);
    goto original1228Return;
original1228_1205:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Actor1228RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1228MarkMobyCollectionBit(argument0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1228Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)48);
    Actor1228EmitMobyVertexParticles(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1228DeleteMoby(argument0);
original1228Return:
    return;
}
#undef Actor1228Field
#undef Actor1228Keep


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007EB68,442 instructions, sibling4562. Verified28 spawn/particle C
 * reused; all raw fields, branches and constants from original28.
 * Units, helper contracts and cadence unresolved; uninstalled until exact. */
#define F28Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int F28QueryWorldSegment(void*, void*) __asm__("func_80018368");


int F28CountTimerDown(void*, int) __asm__("func_800359A4");

int F28PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");

int F28PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");

int F28BuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");

int F28TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");

int F28ShiftVectorLeft(void*, int) __asm__("func_8004F0E8");

int F28CopyVector(void*, void*) __asm__("func_8004F178");

int F28AddVector(void*, void*, void*) __asm__("func_8004F194");

int F28DeleteMoby(void*) __asm__("func_80055B18");

int F28rand(void) __asm__("rand");

extern short F28D_800658A0[] __asm__("D_800658A0");

extern short F28D_80065920[] __asm__("D_80065920");

extern int F28D_8006C574 __asm__("D_8006C574");

extern int F28D_8006C578 __asm__("D_8006C578");

extern int F28D_8006C640 __asm__("D_8006C640");

extern int F28D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char F28D_8006E020[] __asm__("D_8006E020");

extern void* (*F28SpawnMoby)(int, void*)__asm__("SpawnMoby");

extern int (*F28SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");

extern unsigned char F28D_80070328[] __asm__("D_80070328");

extern int F28Delta __asm__("D_8006C648");
extern int F28Reflect[] __asm__("D_80071918");

const int F28Initial[4] __asm__("D_level_28_80074728") = {75, 55, 55, 0};
extern unsigned char* F28Pool __asm__("D_8006C550");
extern unsigned short** F28Lists __asm__("D_8006C730");
extern int F28Mode __asm__("D_8006C7C4");
extern int F28Gate __asm__("D_8006C770");
int F28RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int F28SpawnMobyFromValueSelector() __asm__("func_80036A68");
int F28MarkMobyCollectionBit() __asm__("func_8003BA00");
int F28EmitMobyVertexParticles() __asm__("func_800369B8");
int F28InitializeMobySpatialGridAndBasis() __asm__("func_80055C24");
int F28ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int F28RefreshMobyPackedQueryField() __asm__("func_8005629C");
extern int (*F28Notify)() __asm__("unk_ovlheader_800743E0");
extern unsigned char* F28Classes[] __asm__("D_8006EE2C");
int F28SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int F28TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
void func_level_28_8007FAFC(void* input) {
    struct {
        int first[4], second[4], third[4], matrix[6];
        signed char angles[8];
    } frame;
    register unsigned char* owner __asm__("$18") = input;
    register unsigned char* state __asm__("$21");
    register int selectedAngle __asm__("$16");
    register unsigned char* nested16 __asm__("$16");
    register int minus17 __asm__("$17");
    register unsigned char* linked17 __asm__("$17");
    register void* spawned21D __asm__("$17");
    register int spawnIndex __asm__("$20");
    register int spawnOffset __asm__("$19");
    register unsigned char* player21 __asm__("$22");
    register int matrixParticleIndex __asm__("$19");
    register void* matrix21 __asm__("$20");
    register int* vector17 __asm__("$17");
    register int* vector16 __asm__("$16");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register void* call4 __asm__("$4");
    register int call5 __asm__("$5");
    register void* call6 __asm__("$6");
    register void* call7 __asm__("$7");
    void* spawned146;
    void* spawned1E2;
    unsigned char* linked;
    register unsigned short* list __asm__("$4");
    register unsigned int selector __asm__("$5");
    register unsigned char* pool7 __asm__("$7");
    register int mode6 __asm__("$6");
    int kind;
    MATCHING_KEEP(owner);
    state = F28Field(owner, unsigned char**, 0);
    __asm__("" : "=r"(state) : "0"(state) : "$2", "$3", "$4", "$5");
    {
        register int* initial5 __asm__("$5") = F28Initial;
        MATCHING_KEEP(initial5);
        {
            register int first2 __asm__("$2") = initial5[0];
            register int second3 __asm__("$3") = initial5[1];
            register int third4 __asm__("$4") = initial5[2];
            MATCHING_KEEP3(first2, second3, third4);
            frame.first[0] = first2;
            frame.first[1] = second3;
            frame.first[2] = third4;
        }
    }
    work3 = F28Field(state, int*, 8);
    if (work3 != -1 && ((Moby*)owner)->damageFlags)
        F28Notify(owner[0x43], 1);
    work3 = F28Field(state, int*, 16);
    minus17 = -1;
    if (work3 != minus17) {
        linked = F28Pool + work3 * 88;
        work2 = F28Field(linked, int*, 0);
        MATCHING_KEEP(work2);
        if (F28Field((void*)work2, int*, 0)) {
            ((Moby*)owner)->damageFlags = 0;
            if (!F28Field(state, int*, 20))
                F28Field(state, int*, 20) = (int)F28SpawnMoby(577, owner);
        } else {
            call4 = F28Field(state, void**, 20);
            if (call4) {
                nested16 = F28Field(call4, unsigned char**, 0);
                if (F28SoundHandleMatchesOwnerInStates1Or2(call4, F28Field(nested16, int*, 4))) {
                    if (F28SoundHandleMatchesOwnerInStates1Or2(F28Field(state, void**, 20),
                                                               F28Field(nested16, int*, 4)))
                        F28TransitionSoundHandleTo3Or5(F28Field(nested16, int*, 4));
                    F28Field(nested16, int*, 4) = minus17;
                }
                F28DeleteMoby(F28Field(state, void**, 20));
                F28Field(state, int*, 20) = 0;
            }
        }
    }
    if (((Moby*)owner)->damageFlags && (unsigned int)(owner[0x48] - 2) >= 2) {
        work2 = F28Field(state, int*, 12) - 1;
        F28Field(state, int*, 12) = work2;
        if (work2 <= 0 || (((Moby*)owner)->damageFlags & 0x180000)) {
            owner[0x48] = 2;
            call4 = owner;
            call5 = 1;
            goto emit;
        }
        call4 = owner;
        call5 = 0;
    emit:
        MATCHING_KEEP2_VOLATILE(call4, call5);
        F28PlayMobySoundEvent(call4, call5, 0);
        owner[0x54] = 255;
        owner[0x55] = 255;
        owner[0x56] = 255;
        owner[0x57] = 63;
    } else {
        owner[0x54] = 0;
        owner[0x55] = 0;
        owner[0x56] = 0;
        owner[0x57] = 0;
    }
    switch (owner[0x48]) {
        case 0:
            goto selection;
        case 1:
            goto timer;
        case 2:
            goto spawn;
        case 3:
            goto particles;
        default: {
            ((Moby*)owner)->damageFlags = 0;
            goto done;
        }
    }
selection:
    if (!F28CountTimerDown(state, 4))
        goto clear;
    {
        register unsigned char* pool6 __asm__("$6") = F28Pool;
        __asm__("" : "=r"(pool6) : "0"(pool6) : "$2", "$3", "$4");
        work2 = F28Field(state, int*, 8);
        MATCHING_KEEP_CLOBBER(work2, "$3");
        {
            register unsigned short** table3 __asm__("$3") = F28Lists;
            MATCHING_KEEP2(table3, work2);
            list = table3[work2];
        }
        do {
            selector = *list;
            work2 = selector & 32767;
            work3 = work2 * 11;
            MATCHING_KEEP(work3);
            work3 <<= 3;
            MATCHING_KEEP(work3);
            linked17 = (unsigned char*)(work3 + (int)pool6);
            MATCHING_KEEP(linked17);
            if (linked17[0x48] & 128)
                goto activate;
            work2 = selector << 16;
            list++;
        } while (work2 >= 0);
    }
    MATCHING_BARRIER_VOLATILE("memory");
    F28Field(owner, volatile int*, 24) = 0;
    goto done;
timer:
    if (!F28CountTimerDown(state, 4))
        goto clear;
    F28Field(state, int*, 0) = 15;
    owner[0x48] = 0;
    goto clear;
spawn:
    if (((F28D_8006C578 - F28D_8006C574) >= 0x15) && (F28D_8006C7E8 >= 0x7531)) {
        spawned146 = F28SpawnMoby(0x146, owner);

        if (spawned146 != 0) {
            F28Field(spawned146, signed char*, 0x47) = 7;
        }
    }
    spawnIndex = 0;

    if ((F28D_8006C578 - F28D_8006C574) >= 0x15) {
        player21 = F28D_8006E020;

        MATCHING_KEEP(player21);

        spawnOffset = 0;

    loop_32:
        if (F28D_8006C7E8 >= 0x7531) {
            spawned21D = F28SpawnMoby(0x21D, owner);

            if (spawned21D != 0) {
                selectedAngle = F28PlanarHeadingLookup(
                    ((Moby*)owner)->position.x - F28Field(player21, int*, 0),
                    ((Moby*)owner)->position.y - F28Field(player21, int*, 4), 0);

                work2 = F28rand();
                selectedAngle += 64;

                MATCHING_KEEP2(work2, selectedAngle);

                work2 &= 31;
                selectedAngle += work2;
                F28Field(spawned21D, signed char*, 0x46) = selectedAngle;

                F28Field(spawned21D, signed char*, 0x45) =
                    (signed char)((spawnOffset + (F28rand() & 0x1E)) - 0xF);

                F28Field(spawned21D, signed char*, 0x47) = 8;

                F28Field(spawned21D, signed char*, 0x4C) = 0x2A;
            }
            spawnIndex += 1;

            spawnOffset += 0x33;

            if ((spawnIndex < 5) && ((F28D_8006C578 - F28D_8006C574) >= 0x15)) {
                goto loop_32;
            }
        }
    }

    MATCHING_BARRIER("$2");
    owner[0x41] = 0;
    owner[0x4C] = 0;
    owner[0x4D] = 0;
    F28Field(state, int*, 0) = 20;
    owner[0x48] = 3;

particles:
    if (F28Field(state, int*, 0) >= 6) {
        __asm__ volatile("" : "=r"(call4));
        matrixParticleIndex = 0;
        matrix21 = frame.matrix;
        vector17 = frame.second;
        vector16 = frame.third;
        do {
            frame.angles[0] = 0;

            frame.angles[1] = F28rand();

            frame.angles[2] = F28rand();

            F28BuildPackedAngleBasisMatrix(&frame.angles[0], matrix21, 0);

            matrixParticleIndex++;
            work2 = F28rand();

            /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
            __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

            call4 = matrix21;
            call5 = (int)vector17;
            call6 = vector17;

            MATCHING_KEEP4_VOLATILE_CLOBBER(call4, call5, call6, work2, "memory");

            work2 &= 31;
            work2 += 48;
            frame.second[0] = work2;

            frame.second[1] = 0;

            frame.second[2] = 0;

            F28TransformVectorByBasis(call4, (void*)call5, call6);

            F28CopyVector(vector16, vector17);

            F28ShiftVectorLeft(vector16, 2);

            MATCHING_KEEP(owner);

            F28AddVector(vector16, vector16, owner + 0xC);

            call4 = (void*)1;
            call5 = 13;
            call6 = vector16;

            MATCHING_KEEP3(call4, call5, call6);

            F28SpawnParticle((int)call4, call5, call6, vector17);
            MATCHING_KEEP_CLOBBER(owner, "$22");

        } while (matrixParticleIndex < 4);

        call4 = (void*)6;
        call5 = 70;
        call6 = owner + 12;
        MATCHING_KEEP3(call4, call5, call6);
        F28SpawnParticle((int)call4, call5, call6, (void*)16);
    }
    if (!(F28D_8006C640 & 1) && F28D_8006C578 - F28D_8006C574 >= 21 && F28D_8006C7E8 >= 30001) {
        spawned1E2 = F28SpawnMoby(482, owner);
        if (spawned1E2) {
            F28Field(spawned1E2, unsigned char*, 76) = 42;
            F28Field(spawned1E2, unsigned char*, 71) = 10;
        }
    }
    if (!F28CountTimerDown(state, 4))
        goto clear;
    F28SpawnMobyFromValueSelector(owner, 1, 0, 0);
    F28RefreshMobySpatialGridAndBasis(owner, 4);
    F28MarkMobyCollectionBit(owner);
    F28EmitMobyVertexParticles(owner, 48);
    F28DeleteMoby(owner);
    goto done;
activate:
    F28CopyVector(linked17 + 12, owner + 12);
    F28InitializeMobySpatialGridAndBasis(linked17);
    work2 = F28Field(linked17, short*, 54);
    F28Field(linked17, int*, 24) = 0;
    linked17[0x51] = 0;
    linked17[0x48] = 0;
    linked17[0x42] = 0;
    work2 = F28Field(F28Classes[work2], int*, 60);
    work2 = F28Field((void*)work2, unsigned char*, 0);
    selectedAngle = 1;
    linked17[0x3C] = 0;
    linked17[0x3D] = 0;
    linked17[0x3E] = 0;
    linked17[0x3F] = selectedAngle;
    linked17[0x44] = 0;
    linked17[0x45] = 0;
    work2 = (unsigned int)work2 < 2;
    MATCHING_KEEP(work2);
    work2 ^= 1;
    work2 = -work2;
    work2 &= 48;
    linked17[0x40] = work2;
    linked17[0x46] = owner[0x46];
    F28ProbeGroundFromRaisedMoby(linked17);
    F28RefreshMobyPackedQueryField(linked17);
    F28Field(state, int*, 0) = frame.first[F28Mode];
    owner[0x48] = selectedAngle;
clear:
    ((Moby*)owner)->damageFlags = 0;
done:
    MATCHING_BARRIER_VOLATILE("memory");
}
#undef F28Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * 800801E4 complete405 instructions in sibling4556 and original assembly.
 * Verified38 spawning/vector/particle C reused; original28 controls all
 * branches, raw fields and constants. Units/helper meanings/cadence unknown.
 * Uninstalled until native and full retail hashes match. */
#define C28Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int C28QueryWorldSegment(void*, void*) __asm__("func_80018368");

int C28CountTimerDown(void*, int) __asm__("func_800359A4");

int C28PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");

int C28BuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");

int C28TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");

int C28ShiftVectorLeft(void*, int) __asm__("func_8004F0E8");

int C28CopyVector(void*, void*) __asm__("func_8004F178");

int C28AddVector(void*, void*, void*) __asm__("func_8004F194");

int C28DeleteMoby(void*) __asm__("func_80055B18");

int C28rand(void) __asm__("rand");

extern short C28D_800658A0[] __asm__("D_800658A0");

extern short C28D_80065920[] __asm__("D_80065920");

extern int C28D_8006C574 __asm__("D_8006C574");

extern int C28D_8006C578 __asm__("D_8006C578");

extern int C28D_8006C640 __asm__("D_8006C640");

extern int C28D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char C28D_8006E020[] __asm__("D_8006E020");

extern void* (*C28SpawnMoby)(int, void*)__asm__("SpawnMoby");

extern int (*C28SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");

extern unsigned char C28D_80070328[] __asm__("D_80070328");

int C28QueryWorldSphere() __asm__("func_80019194");
int C28ComputeVectorPlaneResponse() __asm__("func_8004EF74");
int C28RandBetween() __asm__("func_8003636C");
extern int C28Delta __asm__("D_8006C648");
extern int C28Reflect[] __asm__("D_80071918");

void func_level_28_800801E4(void* input) {
    struct {
        int first[4], second[4], third[4], matrix[6];
        signed char angles[8];
        int pad[2];
    } frame;
    register unsigned char* owner __asm__("$18") = input;
    register unsigned char* state __asm__("$19");
    register int selectedAngle __asm__("$16");
    register int one16 __asm__("$16");
    register void* spawned21D __asm__("$17");
    register int spawnIndex __asm__("$21");
    register int spawnOffset __asm__("$20");
    register unsigned char* player21 __asm__("$22");
    register int matrixParticleIndex __asm__("$20");
    register void* matrix21 __asm__("$21");
    register int* vector17 __asm__("$17");
    register int* vector16 __asm__("$16");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register void* call4 __asm__("$4");
    register int call5 __asm__("$5");
    register void* call6 __asm__("$6");
    register void* call7 __asm__("$7");
    void* spawned146;
    void* spawned1E2;
    register void* timerPointer __asm__("$4");
    MATCHING_KEEP(owner);
    state = C28Field(owner, unsigned char**, 0);
    work2 = C28Field(state, short*, 14);
    if (!work2)
        return;
    work3 = work2;
    MATCHING_KEEP2(work2, work3);
    if (work2 >= 2) {
        work2 = work3 - C28Delta;
        C28Field(state, short*, 14) = work2;
        if ((short)work2 <= 0)
            C28Field(state, short*, 14) = 1;
    }
    work3 = owner[0x48];
    one16 = 1;
    MATCHING_KEEP2(work3, one16);
    if (work3 == one16)
        goto spawn;
    if (work3 < 2) {
        if (!work3)
            goto movement;
        return;
    }
    if (work3 == 2)
        goto particles;
    return;
movement:
    if (C28CountTimerDown(state + 12, 2) || (!owner[0x4D] && C28Field(state, short*, 14) == one16))
        owner[0x48] = 1;
    if (C28QueryWorldSphere(owner + 12, 300)) {
        frame.first[0] = C28Field(state, short*, 0);
        frame.first[1] = C28Field(state, short*, 2);
        frame.first[2] = C28Field(state, short*, 4);
        if (C28ComputeVectorPlaneResponse(frame.first, C28Reflect, frame.first)) {
            C28Field(state, short*, 0) = frame.first[0];
            C28Field(state, short*, 2) = frame.first[1];
            C28Field(state, short*, 4) = frame.first[2];
        }
    }
    ((Moby*)owner)->position.x += C28Field(state, short*, 0);
    ((Moby*)owner)->position.y += C28Field(state, short*, 2);
    if (C28Field(state, short*, 18) == 3)
        C28Field(state, unsigned short*, 4) -= 5;
    else
        C28Field(state, unsigned short*, 4) -= 10;
    if (C28Field(state, short*, 4) < -200)
        C28Field(state, short*, 4) = -200;
    ((Moby*)owner)->position.z += C28Field(state, short*, 4);
    owner[0x44] += state[6];
    owner[0x45] += state[8];
    owner[0x46] += state[10];
    if (C28Field(state, short*, 18) == 2)
        return;
    if (C28D_8006C640 % 5)
        return;
    frame.first[0] = C28rand() & 3;
    frame.first[1] = C28rand() & 3;
    frame.first[2] = 20;
    work3 = C28Field(state, short*, 18);
    call4 = (void*)1;
    if (work3 == 1) {
        MATCHING_KEEP(call4);
        C28SpawnParticle((int)call4, 0, owner + 12, frame.first);
        return;
    }
    if (!work3) {
        C28SpawnParticle(1, 1, owner + 12, frame.first);
        return;
    }
    if (work3 != 3)
        return;
    frame.first[0] = ((short)C28Field(state, unsigned short*, 0)) >> 2;
    frame.first[1] = ((short)C28Field(state, unsigned short*, 0)) >> 2;
    frame.first[2] = ((short)C28Field(state, unsigned short*, 4)) >> 2;
    work2 = C28RandBetween(10, 20);
    frame.first[2] += work2;
    C28SpawnParticle(1, 39, owner + 12, frame.first);
    return;
spawn:
    if (((C28D_8006C578 - C28D_8006C574) >= 0x15) && (C28D_8006C7E8 >= 0x7531)) {
        spawned146 = C28SpawnMoby(0x146, owner);

        if (spawned146 != 0) {
            C28Field(spawned146, signed char*, 0x47) = 7;
        }
    }
    spawnIndex = 0;

    if ((C28D_8006C578 - C28D_8006C574) >= 0x15) {
        player21 = C28D_8006E020;

        MATCHING_KEEP(player21);

        spawnOffset = 0;

    loop_32:
        if (C28D_8006C7E8 >= 0x7531) {
            spawned21D = C28SpawnMoby(0x21D, owner);

            if (spawned21D != 0) {
                selectedAngle = C28PlanarHeadingLookup(
                    ((Moby*)owner)->position.x - C28Field(player21, int*, 0),
                    ((Moby*)owner)->position.y - C28Field(player21, int*, 4), 0);

                work2 = C28rand();
                selectedAngle += 64;

                MATCHING_KEEP2(work2, selectedAngle);

                work2 &= 31;
                selectedAngle += work2;
                C28Field(spawned21D, signed char*, 0x46) = selectedAngle;

                C28Field(spawned21D, signed char*, 0x45) =
                    (signed char)((spawnOffset + (C28rand() & 0x1E)) - 0xF);

                C28Field(spawned21D, signed char*, 0x47) = 8;

                C28Field(spawned21D, signed char*, 0x4C) = 0x2A;
            }
            spawnIndex += 1;

            spawnOffset += 0x33;

            if ((spawnIndex < 5) && ((C28D_8006C578 - C28D_8006C574) >= 0x15)) {
                goto loop_32;
            }
        }
    }

    MATCHING_BARRIER("$2");
    owner[0x41] = 0;
    owner[0x4C] = 0;
    owner[0x4D] = 0;
    C28Field(state, short*, 12) = 30;
    owner[0x48] = 2;
    return;
particles:
    if (C28Field(state, short*, 12) >= 8) {
        matrixParticleIndex = 0;
        matrix21 = frame.matrix;
        vector17 = frame.second;
        vector16 = frame.third;
        do {
            frame.angles[0] = 0;

            frame.angles[1] = C28rand();

            frame.angles[2] = C28rand();

            C28BuildPackedAngleBasisMatrix(&frame.angles[0], matrix21, 0);

            matrixParticleIndex++;
            work2 = C28rand();

            /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
            __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

            call4 = matrix21;
            call5 = (int)vector17;
            call6 = vector17;

            MATCHING_KEEP4_VOLATILE_CLOBBER(call4, call5, call6, work2, "memory");

            work2 &= 31;
            work2 += 48;
            frame.second[0] = work2;

            frame.second[1] = 0;

            frame.second[2] = 0;

            C28TransformVectorByBasis(call4, (void*)call5, call6);

            C28CopyVector(vector16, vector17);

            C28ShiftVectorLeft(vector16, 2);

            MATCHING_KEEP(owner);

            C28AddVector(vector16, vector16, owner + 0xC);

            call4 = (void*)1;
            call5 = 13;
            call6 = vector16;

            MATCHING_KEEP3(call4, call5, call6);

            C28SpawnParticle((int)call4, call5, call6, vector17);

        } while (matrixParticleIndex < 4);
    }
    selectedAngle = C28D_8006C640 & 1;
    if (selectedAngle == (C28rand() & 1) && C28D_8006C578 - C28D_8006C574 >= 21 &&
        C28D_8006C7E8 >= 30001) {
        spawned1E2 = C28SpawnMoby(482, owner);
        if (spawned1E2) {
            C28Field(spawned1E2, unsigned char*, 76) = 42;
            C28Field(spawned1E2, unsigned char*, 71) = 10;
        }
    }
    if (C28CountTimerDown(state + 12, 2)) {
        C28SpawnParticle(8, 70, owner + 12, (void*)16);
        C28DeleteMoby(owner);
    }
}
#undef C28Field

typedef struct {
    short mode, parentClass;
    int offsetZ;
    Moby* parent;
} DecodedParentFollowRecord;
extern unsigned short D_8006E040, D_8006E03E;
void func_80055B18(Moby*);
void func_80055F14(Moby*, int, Vector3D*);
void func_level_28_80080838(Moby* moby) {
    DecodedParentFollowRecord* tag;
    moby->angle.yaw = ((short)D_8006E040 >> 4) - 0x80;
    moby->angle.pitch = D_8006E03E >> 4;
    tag = moby->mobyTag;
    if (tag->mode == 1) {
        /* Retail continues this routine after the deletion helper call. */
        if (tag->parent->state >= 0x80 || tag->parent->mobyClass != tag->parentClass)
            func_80055B18(moby);
        if (tag->parent->mobyClass == 0x170)
            func_80055F14(spyro.critterMobyPtr, 0, &moby->position);
        else
            func_8004F178(&moby->position, &tag->parent->position);
        moby->position.z += tag->offsetZ;
    }
}

int func_8004F334(Vector3D*, Vector3D*);
void func_80055B18(Moby*);
void func_level_28_80080928(Moby* moby) {
    int* limit = moby->mobyTag;
    if (func_8004F334(&moby->position, &spyro.position) < *limit) {
        Moby* spawned = SpawnMoby(0x110, moby);
        if (spawned) {
            unsigned char* tag = spawned->mobyTag;
            spawned->angle.yaw = 0;
            spawned->size = 0x10;
            tag[4] = 0;
            func_80055B18(moby);
        }
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original callbacks: level28 800809B4 / level48 80081DA8.
 * Each has 444 instructions plus five owned switch target words.
 * Byte suffixes and offsets describe observed storage, not actor semantics.
 * Preserve the four pointer slots, signed halfword producers, repeated
 * helper calls, post-call rereads, state fallthrough and distinct exits.
 * Empty compiler constraints emit no instructions; register suffixes
 * preserve original producer lifetimes. Physical units, helper contracts,
 * caller cadence and synchronized runtime interpretation remain unresolved.
 * Acceptance requires all linked original words and every retail hash.
 */
#define P809B4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int P809B4MaskLinkedRecordFlagsById() __asm__("func_80021ED8");
int P809B4QueryShiftedLinkedRecordWordByByteId() __asm__("func_80021F3C");
int P809B4RequestMobyAnimation() __asm__("func_80034F40");
int P809B4SetMobyAnimation() __asm__("func_80034F80");
int P809B4TestPaddedRotatedBox() __asm__("func_80036220");
int P809B4RegisterTrackedValue() __asm__("func_8003B7B4");
int P809B4PlayMobySoundEvent() __asm__("func_8003BABC");
int P809B4TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int P809B4SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int P809B4CopyVector() __asm__("func_8004F178");
int P809B4ApproximatePlanarDistance() __asm__("func_8004F334");
extern unsigned int P809B4D_8006C550 __asm__("D_8006C550");
extern unsigned int P809B4D_8006C704 __asm__("D_8006C704");
extern int P809B4D_8006C640 __asm__("D_8006C640");
extern unsigned char P809B4D_8006C7F8[] __asm__("D_8006C7F8");
extern unsigned char P809B4D_8006D088[] __asm__("D_8006D088");
extern unsigned char P809B4D_80070328[] __asm__("D_80070328");
extern void* (*P809B4SpawnMoby)() __asm__("SpawnMoby");
void func_level_28_800809B4(void* owner) {
    register void* owner20 __asm__("$20") = owner;
    int initialByte4C;
    register int initialByte47 __asm__("$23");
    register int initialByte40 __asm__("$22");
    register int scanByte48 __asm__("$18");
    register void* targetPosition5 __asm__("$5");
    register int poolTypeWord3 __asm__("$3");
    register int scanTypeConstant2 __asm__("$2");
    register int queryHighWord3 __asm__("$3");
    register int queryLowWord2 __asm__("$2");
    int queryWord;
    int linkedIndex;
    register int targetOffsetWord2 __asm__("$2");
    register int linkedByte48Word2 __asm__("$2");
    register unsigned int poolEndWord2 __asm__("$2");
    register int helperSelector5 __asm__("$5");
    register int helperZero6 __asm__("$6");
    register int targetIndexWord3 __asm__("$3");
    register void* ownerPosition4 __asm__("$4");
    int initialSlotIndex;
    int clearSlotIndex;
    int respawnSlotIndex;
    register int linkedFlagOrSlotOffset21 __asm__("$21");
    int selectedIndex;
    int initialSlotByteIndex;
    int respawnByte3F;
    register unsigned int poolCursor17 __asm__("$17");
    unsigned char stateByte48;
    void* private19;
    void** initialSlotCursor;
    void** clearSlotCursor;
    void** respawnSlotCursor;
    void* firstSlotActor;
    void* clearSlotActor;
    void* ownerByte48Address;
    void* privateWord34Address;
    void* initialSpawn;
    void* alternateSpawn;
    void* respawnResult;
    void* initialSlotActor;
    void* alternateSlotActor;
    void* respawnSlotActor;
    register void* poolByte48Cursor16 __asm__("$16");

    MATCHING_KEEP(owner20);
    private19 = P809B4Field(owner20, void**, 0);
    linkedIndex = P809B4Field(private19, int*, 0x3C);
    linkedFlagOrSlotOffset21 = 0;
    if (linkedIndex != -1) {
        linkedByte48Word2 =
            P809B4Field(((linkedIndex * 0x58) + P809B4D_8006C550), unsigned char*, 0x48);
        MATCHING_KEEP(linkedByte48Word2);
        linkedFlagOrSlotOffset21 = linkedByte48Word2 & 0x80;
    }
    if ((P809B4Field(private19, void**, 0) == 0) &&
        (P809B4Field(owner20, unsigned char*, 0x48) == 0)) {
        initialSlotIndex = 0;
        initialByte4C = 0x28;
        initialByte47 = 0xFF;
        initialByte40 = 0x30;
        MATCHING_KEEP3(initialByte4C, initialByte47, initialByte40);
        initialSlotCursor = private19;
        initialSlotByteIndex = 0;
        do {
            if (P809B4Field(private19, int*, 0x18) != -1) {
                initialSpawn = P809B4SpawnMoby(0x268, owner20);
                *initialSlotCursor = initialSpawn;
                if (initialSpawn != 0) {
                    P809B4CopyVector(initialSpawn + 0xC, owner20 + 0xC);
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x46) =
                        (unsigned char)(P809B4Field(owner20, unsigned char*, 0x46) + 0x40);
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x44) = 0x40;
                    initialSlotActor = *initialSlotCursor;
                    P809B4Field(initialSlotActor, int*, 0x14) =
                        (int)(P809B4Field(initialSlotActor, int*, 0x14) +
                              (initialSlotIndex * P809B4Field(private19, short*, 0x10)));
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x4C) = initialByte4C;
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x47) = initialByte47;
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x4F) =
                        (unsigned char)P809B4Field(private19, int*, 0x18);
                    goto storeInitialSlotBytes;
                }
            } else {
                alternateSpawn = P809B4SpawnMoby(0x13E, owner20);
                *initialSlotCursor = alternateSpawn;
                if (alternateSpawn != 0) {
                    P809B4CopyVector(alternateSpawn + 0xC, owner20 + 0xC);
                    alternateSlotActor = *initialSlotCursor;
                    P809B4Field(alternateSlotActor, int*, 0x14) =
                        (int)(P809B4Field(alternateSlotActor, int*, 0x14) +
                              (initialSlotIndex * P809B4Field(private19, short*, 0x10)));
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x4C) = initialByte4C;
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x47) = initialByte47;
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x4F) = 0x20;
                storeInitialSlotBytes:
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x3E) = initialSlotByteIndex;
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x3F) =
                        (unsigned char)(initialSlotByteIndex + 1);
                    P809B4Field(*initialSlotCursor, unsigned char*, 0x40) = initialByte40;
                }
            }
            initialSlotCursor += 1;
            initialSlotIndex += 1;
            initialSlotByteIndex += 4;
        } while (initialSlotIndex < 4);
    }
    stateByte48 = P809B4Field(owner20, unsigned char*, 0x48);
    switch (stateByte48) {
        case 0:
            if (P809B4SoundHandleMatchesOwnerInStates1Or2(
                    P809B4Field(private19, void**, 0), P809B4Field(private19, int*, 0x38)) == 0) {
                P809B4Field(private19, int*, 0x38) =
                    P809B4PlayMobySoundEvent(P809B4Field(private19, void**, 0), 0, 4);
            }
            targetIndexWord3 = P809B4Field(private19, int*, 0x34);
            ownerPosition4 = owner20 + 0xC;
            if (targetIndexWord3 == -1) {
                targetPosition5 = P809B4D_80070328;
            } else {
                targetOffsetWord2 = targetIndexWord3 * 11;
                MATCHING_KEEP(targetOffsetWord2);
                targetPosition5 = (void*)P809B4D_8006C550;
                targetOffsetWord2 <<= 3;
                targetPosition5 += targetOffsetWord2;
                targetPosition5 += 0xC;
            }
            if ((P809B4ApproximatePlanarDistance(ownerPosition4, targetPosition5) < 0x800) ||
                (linkedFlagOrSlotOffset21 != 0)) {
                if (P809B4Field(private19, int*, 0x34) != -1) {
                    poolCursor17 = P809B4D_8006C550;
                    if (poolCursor17 < (unsigned int)P809B4D_8006C704) {
                        scanByte48 = 1;
                        MATCHING_KEEP(scanByte48);
                        poolByte48Cursor16 = (void*)(poolCursor17 + 0x48);
                        do {
                            poolTypeWord3 = P809B4Field(poolByte48Cursor16, short*, -0x12);
                            scanTypeConstant2 = 0x3CF;
                            MATCHING_KEEP2(scanTypeConstant2, poolTypeWord3);
                            if (poolTypeWord3 == scanTypeConstant2) {
                                selectedIndex = P809B4Field(
                                    P809B4Field((void*)poolCursor17, void**, 0), int*, 0x34);
                                goto compareSelectedIndex;
                            }
                            scanTypeConstant2 = 0x3D5;
                            MATCHING_KEEP(scanTypeConstant2);
                            if (poolTypeWord3 == scanTypeConstant2) {
                                selectedIndex = P809B4Field(
                                    P809B4Field((void*)poolCursor17, void**, 0), int*, 4);
                            compareSelectedIndex:
                                if (selectedIndex == P809B4Field(private19, int*, 0x34)) {
                                    P809B4Field(poolByte48Cursor16, unsigned char*, 0) = scanByte48;
                                    P809B4RegisterTrackedValue(poolByte48Cursor16, 1,
                                                               P809B4D_8006C7F8);
                                }
                            }
                            poolEndWord2 = P809B4D_8006C704;
                            MATCHING_KEEP(poolEndWord2);
                            poolCursor17 += 0x58;
                            poolByte48Cursor16 += 0x58;
                        } while (poolCursor17 < poolEndWord2);
                    }
                    P809B4Field(((P809B4Field(private19, int*, 0x34) * 0x58) + P809B4D_8006C550),
                                unsigned char*, 0x48) = 3;
                    P809B4RegisterTrackedValue(
                        P809B4D_8006C550 + (P809B4Field(private19, int*, 0x34) * 0x58) + 0x48, 1,
                        P809B4D_8006C7F8);
                }
                P809B4Field(owner20, unsigned char*, 0x48) = 1U;
                P809B4RegisterTrackedValue(owner20 + 0x48, 1, P809B4D_8006C7F8);
                case 1:
                    queryWord = P809B4QueryShiftedLinkedRecordWordByByteId(
                        P809B4Field(private19, short*, 0x12));
                    queryHighWord3 = queryWord >> 8;
                    queryLowWord2 = queryWord & 0xF;
                    MATCHING_KEEP2(queryHighWord3, queryLowWord2);
                    if (queryLowWord2 && !(queryHighWord3 & 0xFF)) {
                        P809B4MaskLinkedRecordFlagsById(P809B4Field(private19, short*, 0x12), 0xFC,
                                                        0);
                    }
                    if (P809B4SoundHandleMatchesOwnerInStates1Or2(
                            P809B4Field(private19, void**, 0),
                            P809B4Field(private19, int*, 0x38)) != 0) {
                        if (P809B4SoundHandleMatchesOwnerInStates1Or2(
                                P809B4Field(private19, void**, 0),
                                P809B4Field(private19, int*, 0x38)) != 0) {
                            P809B4TransitionSoundHandleTo3Or5(P809B4Field(private19, int*, 0x38));
                        }
                        P809B4Field(private19, int*, 0x38) = -1;
                    }
                    firstSlotActor = P809B4Field(private19, void**, 0);
                    if (firstSlotActor != 0) {
                        P809B4PlayMobySoundEvent(firstSlotActor, 1, 0);
                    }
                    clearSlotIndex = 0;
                    clearSlotCursor = private19;
                    do {
                        clearSlotActor = *clearSlotCursor;
                        if (clearSlotActor != 0) {
                            P809B4RequestMobyAnimation(clearSlotActor, 1);
                        }
                        clearSlotIndex += 1;
                        clearSlotCursor += 1;
                    } while (clearSlotIndex < 4);
                    P809B4Field(owner20, unsigned char*, 0x48) = 2U;
            }
        default:
            goto checkGlobalWordC640;
        case 2:
            if (P809B4TestPaddedRotatedBox(P809B4D_80070328, private19 + 0x1C, 0, 0) != 0) {
                ownerByte48Address = owner20 + 0x48;
                if (linkedFlagOrSlotOffset21 == 0) {
                    P809B4Field(owner20, unsigned char*, 0x48) = 0U;
                    P809B4RegisterTrackedValue(ownerByte48Address, 1, P809B4D_8006D088);
                    P809B4RegisterTrackedValue(ownerByte48Address, 1, P809B4D_8006C7F8);
                    privateWord34Address = private19 + 0x34;
                    P809B4Field(private19, int*, 0x34) = -1;
                    P809B4RegisterTrackedValue(privateWord34Address, 4, P809B4D_8006D088);
                    P809B4RegisterTrackedValue(privateWord34Address, 4, P809B4D_8006C7F8);
                    P809B4Field(owner20, unsigned char*, 0x48) = 3U;
                    case 3:
                        if ((P809B4QueryShiftedLinkedRecordWordByByteId(
                                 P809B4Field(private19, short*, 0x12)) &
                             0xFF) == 2) {
                            helperSelector5 = 0xFC;
                            helperZero6 = 0;
                            MATCHING_KEEP2(helperSelector5, helperZero6);
                            respawnSlotIndex = 0;
                            respawnSlotCursor = private19;
                            respawnByte3F = 1;
                            P809B4MaskLinkedRecordFlagsById(P809B4Field(private19, short*, 0x12),
                                                            helperSelector5, helperZero6);
                            P809B4Field(owner20, unsigned char*, 0x48) = 4U;
                            do {
                                respawnResult = P809B4SpawnMoby(0x268, owner20);
                                *respawnSlotCursor = respawnResult;
                                linkedFlagOrSlotOffset21 = respawnSlotIndex * 4;
                                MATCHING_KEEP(linkedFlagOrSlotOffset21);
                                if (respawnResult != 0) {
                                    P809B4CopyVector(respawnResult + 0xC, owner20 + 0xC);
                                    P809B4SetMobyAnimation(*respawnSlotCursor, 0);
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x46) =
                                        (unsigned char)(P809B4Field(owner20, unsigned char*, 0x46) +
                                                        0x40);
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x44) = 0x40;
                                    respawnSlotActor = *respawnSlotCursor;
                                    P809B4Field(respawnSlotActor, int*, 0x14) =
                                        (int)(P809B4Field(respawnSlotActor, int*, 0x14) +
                                              (respawnSlotIndex *
                                               P809B4Field(private19, short*, 0x10)));
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x4C) = 0x28;
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x47) = 0xFF;
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x4F) =
                                        (unsigned char)P809B4Field(private19, int*, 0x18);
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x3E) =
                                        (unsigned char)linkedFlagOrSlotOffset21;
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x3F) =
                                        respawnByte3F;
                                    P809B4Field(*respawnSlotCursor, unsigned char*, 0x40) = 0x30;
                                }
                                respawnSlotCursor += 1;
                                respawnSlotIndex += 1;
                                respawnByte3F += 4;
                            } while (respawnSlotIndex < 4);
                        }
                }
            }
            goto checkGlobalWordC640;
        case 4:
            if (P809B4SoundHandleMatchesOwnerInStates1Or2(
                    P809B4Field(private19, void**, 0), P809B4Field(private19, int*, 0x38)) == 0) {
                P809B4Field(private19, int*, 0x38) =
                    P809B4PlayMobySoundEvent(P809B4Field(private19, void**, 0), 0, 4);
            }
            if (linkedFlagOrSlotOffset21 != 0) {
                P809B4Field(owner20, unsigned char*, 0x48) = 1U;
                P809B4RegisterTrackedValue(owner20 + 0x48, 1, P809B4D_8006C7F8);
                goto exit_function;
            }
            goto exit_function;
    }
checkGlobalWordC640:
    if (P809B4D_8006C640 >= 9) {
        P809B4Field(owner20, unsigned char*, 0x4A) = 0xC;
    }
exit_function:
    return;
}

#undef P809B4Field
