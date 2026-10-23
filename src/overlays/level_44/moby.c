#include "matching.h"
#include "common.h"
#include "camera.h"
#include "moby/mobytag.h"
#include "spu.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
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
void func_level_44_800755AC(void* input) {
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
void func_level_44_80076208(Moby* mobyArgument) {
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
void func_level_44_80076894(void* input) {
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
void func_level_44_80077DE4(Moby* moby) {
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
void func_level_44_800780A4(Moby* mobyArgument) {
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
void func_level_44_800785C4(Moby* moby) {
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
/* Same existing collision storage, with its audited complete struct view. */
extern CollisionData Raw260CollisionData __asm__("D_80071900");
void func_level_44_80078944(Moby* moby) {
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
                    func_8004F178(position, &Raw260CollisionData.targetedPosition);
                    func_8004EF04(&Raw260CollisionData.D_80071918, 0x1000);
                    dotProduct = DOTPRODUCT(mobyTag->unkC, Raw260CollisionData.D_80071918) >> 0xB;
                    if (dotProduct < 0) {
                        func_8004F08C(&Raw260CollisionData.D_80071918, 0x1000, -dotProduct);
                        func_8004F194(&mobyTag->unkC, &mobyTag->unkC,
                                      &Raw260CollisionData.D_80071918);
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
void func_level_44_80078C48(void* input) {
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
void func_level_44_800797BC(Moby* moby) {
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
void func_level_44_80079BEC(Moby* moby) {
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
void func_level_44_80079F54(Moby* owner) {
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
void func_level_44_8007A0E0(Moby* moby) {
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

typedef struct {
    unsigned char unk0, unk1;
    short offset;
    Moby* parent;
} DecodedFollowTag;
extern unsigned short D_8006E040, D_8006E03E;
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_44_8007A170(Moby* moby) {
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
extern unsigned char D_8007157E;
void func_level_44_8007A2C4(Moby* moby) {
    SpeechProps* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->mobyClass == 0x2ad) {
                if (!D_8007157E)
                    tag->nextMsg = 0;
                else {
                    if (D_80070300[D_80066FCC[0x2e]] & 1)
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
void func_level_44_8007A414(Moby* actor) {
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

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level43 8007A6B4 / level44 8007A6C0, 514 original instructions each.
 * Their original flag stores select D_80071591 / D_80071591 respectively.
 * Offset names identify storage, not decoded semantics. Helper contracts,
 * physical units and caller cadence remain unresolved. Preserve 32-bit
 * shift wrapping, signed /2048 truncation, byte/halfword widths, pointer
 * rereads and distinct selector branches. Empty constraints emit no CPU
 * instructions. Acceptance requires linked original words and all hashes.
 */
#define P7A6B4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int P7A6B4CopyCameraPositionWithWrappedAngle() __asm__("func_800135A4");
int P7A6B4QueryWorldHeight() __asm__("func_8001A358");
int P7A6B4RequestMobyAnimation() __asm__("func_80034F40");
int P7A6B4TurnMobyTowardHeading() __asm__("func_8003585C");
int P7A6B4CountTimerDown() __asm__("func_800359A4");
int P7A6B4ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int P7A6B4ResolveMobyYawStep() __asm__("func_80035DDC");
int P7A6B4UpdateMobyInteractionGate() __asm__("func_80037BBC");
int P7A6B4RestoreOrClearTrackedSnapshot() __asm__("func_8003B74C");
int P7A6B4RegisterTrackedValue() __asm__("func_8003B7B4");
int P7A6B4TransformVectorByBasis() __asm__("func_8004ED6C");
int P7A6B4CopyVector() __asm__("func_8004F178");
int P7A6B4AddVector() __asm__("func_8004F194");
int P7A6B4ConfigurePrimaryRangeRequest() __asm__("func_8004F984");
int P7A6B4StartDialogue() __asm__("func_800512E4");
int P7A6B4ReadSelectedFrameScalar() __asm__("func_80055E84");
int P7A6B4RefreshMobyPackedQueryField() __asm__("func_8005629C");
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
void func_level_44_8007A6C0(void* owner) {
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
    void* privateState;
    void* linkedObject78;
    void* spawnedObject;

    ((Moby*)owner)->updateDistance = 0xFF;
    privateState = ((Moby*)owner)->mobyTag;
    if ((P7A6B4D_8006C640 > 0) && (P7A6B4Field(privateState, int*, 0x480) == 0)) {
        temp_a0 = P7A6B4D_8006C3F4 + P7A6B4Field(P7A6B4D_800652B0, int*, 0xB0);
        P7A6B4ConfigurePrimaryRangeRequest(
            temp_a0, temp_a0 + P7A6B4Field(P7A6B4D_800652B4, unsigned short*, 0xB0),
            P7A6B4Field(P7A6B4D_800652B6, unsigned short*, 0xB0));
        P7A6B4Field(privateState, int*, 0x480) = 1;
    }
    ownerState = ((Moby*)owner)->state;
    switch (ownerState) { /* irregular */
        case 0:
            if ((P7A6B4D_8006E344 == 0xD) && (((Moby*)owner)->substate == 0)) {
                if (P7A6B4D_8006C4F8 != 1) {
                    ((Moby*)owner)->state = 3U;
                    stateByteAddress = owner + 0x48;
                    P7A6B4RegisterTrackedValue(stateByteAddress, 1, P7A6B4D_8006D088);
                    P7A6B4RegisterTrackedValue(stateByteAddress, 1, P7A6B4D_8006C7F8);
                } else {
                    tableWord3 = ((short*)P7A6B4D_80065920)[((Moby*)owner)->angle.yaw];
                    tableArg4 = &P7A6B4D_800719BC;
                    *(int*)tableArg4 = (tableWord3 * 13) >> 5;
                    tableArg5 = tableArg4;
                    tableWord3 = ((short*)P7A6B4D_800658A0)[((Moby*)owner)->angle.yaw];
                    P7A6B4D_800719C4 = 0;
                    P7A6B4D_800719C0 = (tableWord3 * 13) >> 5;
                    P7A6B4AddVector(tableArg4, tableArg5, owner + 0xC);
                    P7A6B4D_8006C6E0 = ((((Moby*)owner)->angle.yaw + 0x80) * 0x10) & 0xFFF;
                    goto initializeState0;
                }
            } else {
            initializeState0:
                ((Moby*)owner)->distanceToGround = 0;
                P7A6B4Field(privateState, unsigned char*, 5) = 1;
                if ((P7A6B4D_8006C598 == 0) && (P7A6B4UpdateMobyInteractionGate(owner, 0) != 0)) {
                    P7A6B4StartDialogue(owner, 0, 0x12);
                    ((Moby*)owner)->state = 0x12U;
                }
            }
            break;
        case 18:
            if (P7A6B4D_8006E344 != 1) {
                P7A6B4Field(P7A6B4D_80070328, int*, 0x20C) = 0x10000002;
                P7A6B4D_80071591 = 1;
                P7A6B4Field(privateState, int*, 0x7C) = 0x3C;
                ((Moby*)owner)->state = 1U;
                P7A6B4RequestMobyAnimation(owner, 1);
            }
            break;
        case 1:
            P7A6B4Field(P7A6B4D_80070328, int*, 0x20C) = 0x10000002;
            if (P7A6B4TurnMobyTowardHeading(owner, P7A6B4Field(privateState, int*, 0x34) + 0x80, 8,
                                            0x10, (int)ownerState, 0) != 0) {
                P7A6B4ResolveMobyYawStep(owner, 0x80, 0, 0, 0);
            }
            timerResult2 = P7A6B4CountTimerDown(privateState + 0x7C, 4);
            MATCHING_KEEP2(owner, timerResult2);
            savedStateByteAddress = owner + 0x48;
            if (timerResult2 == 2) {
                ((Moby*)owner)->state = 3U;
                tableArg4 = savedStateByteAddress;
                helperSelector5 = 1;
                MATCHING_KEEP2(tableArg4, helperSelector5);
                callback17 = P7A6B4D_8006D088;
                P7A6B4RegisterTrackedValue(tableArg4, helperSelector5, callback17);
                P7A6B4RegisterTrackedValue(savedStateByteAddress, 1, P7A6B4D_8006C7F8);
                P7A6B4RestoreOrClearTrackedSnapshot(callback17);
                ((Moby*)owner)->state = 1U;
            }
            break;
        case 3:
            P7A6B4unk_ovlheader_80074318(owner, 0x73);
            P7A6B4D_8006C6D0 = 0;
            P7A6B4CopyCameraPositionWithWrappedAngle(P7A6B4D_800719A8, P7A6B4D_80068F7C, 0);
            P7A6B4CopyCameraPositionWithWrappedAngle(P7A6B4D_800719F0, P7A6B4D_80068F90, 0);
            if ((P7A6B4D_8006E044 == 0x1F) || (P7A6B4D_8006E044 == 0x28)) {
                ((Moby*)owner)->lowDrawDistance = 0;
                ((Moby*)owner)->drawn = 0;
                if (P7A6B4D_8006C65C != 0) {
                    P7A6B4Field(P7A6B4D_8006C65C, unsigned char*, 0x4C) = 0;
                    P7A6B4Field(P7A6B4D_8006C65C, unsigned char*, 0x4D) = 0;
                }
            } else {
                ((Moby*)owner)->lowDrawDistance = 0x10;
                if (P7A6B4D_8006C65C != 0) {
                    P7A6B4Field(P7A6B4D_8006C65C, unsigned char*, 0x4C) = 0x10;
                }
            }
            if (P7A6B4Field(P7A6B4D_80070328, int*, 0x24C) == 4) {
                selector4 = P7A6B4Field(P7A6B4D_80070328, int*, 0x48);
                ownerSelector3D = ((Moby*)owner)->animationState.nextId;
                helperSelector5 = selector4 - 0x73;
                if (helperSelector5 != ownerSelector3D) {
                    if (selector4 == 0x83) {
                        selector4 = ((Moby*)owner)->animationState.id;
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
                        selector4 = ((Moby*)owner)->animationState.id;
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
                if (((Moby*)owner)->animationState.nextId == 1) {
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
                    var_v0 = P7A6B4QueryWorldHeight(&frame.sp18, 0x800);
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
                            if (P7A6B4ReadSelectedFrameScalar(owner) >= 7) {
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
    P7A6B4RefreshMobyPackedQueryField(owner);
}

#undef P7A6B4Field

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
void func_level_44_8007AEC8(Moby* moby) {
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

extern unsigned char D_80066FCC[], D_80070300[];
void func_80021ED8(void*, int, int);
void func_80055B18(Moby*);
void func_level_44_8007B2D4(Moby* moby) {
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
void func_level_44_8007B340(Moby* mobyArgument) {
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
void func_level_44_8007B778(Moby* moby) {
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
void func_level_44_8007BAA8(void* input) {
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
                    if (Controller821F8Field(tag, short*, 0) == 4) {
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

void func_level_44_8007CC34(Moby* moby) {
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
void func_level_44_8007CC54(Moby* mobyArgument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_44/moby/func_level_44_8007CE54.s SHA256 6f415d9707b06bb25205303484ea3b7ad6c83a63fcf6090fe16752f0d0f67376. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level44_7CE54_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_7CE54QueryWorldSegmentWithOptions() __asm__("func_8001830C");
/* extern */
int Level44_7CE54QueryWorldHeight() __asm__("func_8001A358");
/* extern */
int Level44_7CE54TestPlayerSphereOverlap() __asm__("func_8001C288");
/* extern */
int Level44_7CE54SetMobyAnimation() __asm__("func_80034F80");
/* extern */
int Level44_7CE54TestPaddedRotatedBox() __asm__("func_80036220");
/* extern */
int Level44_7CE54RestoreOrClearTrackedSnapshot() __asm__("func_8003B74C");
/* extern */
int Level44_7CE54TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
int Level44_7CE54MeasureVectorLength() __asm__("func_8004EDE8");
/* extern */
int Level44_7CE54ScaleVectorRatioQ15() __asm__("func_8004F08C");
/* extern */
int Level44_7CE54ClearVector() __asm__("func_8004F168");
/* extern */
int Level44_7CE54SubtractVector() __asm__("func_8004F1C8");
/* extern */
int Level44_7CE54DeleteMoby() __asm__("func_80055B18");
/* extern */
int Level44_7CE54RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int Level44_7CE54ReleaseParticleRecord() __asm__("func_80056504");
/* extern */
int Level44_7CE54_rand() __asm__("rand");
/* extern */
extern unsigned char Level44_7CE54_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level44_7CE54_D_80065920 __asm__("D_80065920");
extern int Level44_7CE54_D_8006C574 __asm__("D_8006C574");
extern int Level44_7CE54_D_8006C578 __asm__("D_8006C578");
extern int Level44_7CE54_D_8006C58C __asm__("D_8006C58C");
extern int Level44_7CE54_D_8006C640 __asm__("D_8006C640");
extern unsigned char Level44_7CE54_D_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char Level44_7CE54_D_8006D088 __asm__("D_8006D088");
extern unsigned char Level44_7CE54_D_8006E020 __asm__("D_8006E020");
extern unsigned char Level44_7CE54_D_80070300 __asm__("D_80070300");
extern Vector3D Level44_7CE54_D_80070328 __asm__("D_80070328");
extern unsigned char Level44_7CE54_D_800716AC __asm__("D_800716AC");
extern Vector3D Level44_7CE54_D_80071900 __asm__("D_80071900");
extern int Level44_7CE54_D_80071908 __asm__("D_80071908");
void func_level_44_8007CE54(Moby* moby) {
    /* SCUS-94467 USA Rev0 address8007CE54; original source/SHA above.
    * 761 instructions plus six owned dispatch words. FrameA8; raw vectors
    *18/28/38/48/58/68/78, saves16..22 at88..A0, RA A4.
    * Original caller producers retain first indirect create3 and its SH
    * argument store in the call delay slot; indirect particle8 is loaded
    * after SP3C into word3, before word3 adjustment and the delay-slot SW.
    * Full-word yaw16 values retain original ADDU16 before byte stores;
    * unsigned byte stores preserve original D2/8C literal constructors.
    * Table addresses use byte offsets and signed LH samples. Original
    * signed MULT low-word products use inputs2/3, outputs5/6/3 and result2;
    * they are ordinary C multiplications, without fabricated HI/LO inputs.
    * Original arithmetic shifts11/12 and constants75 remain unchanged.
    * Dynamic signed DIV uses initialized original bound4=12000, retaining
    * disc divide guards; quotient3 signed division by4 retains correction.
    * Record pointer20 is replaced by vector68Pointer20 only on the original
    * admitted completion arm; pointer18 is either global71908 or a created
    * Moby on mutually exclusive paths. Stores and subsequent loads retain
    * their original producer order. The shared delete remains at the tail.
    * Empty constraints observe initialized original values, and dead
    * clobbers precede identified replacement producers. Native/linked
    * instructions, conditional/internal J targets, owned table words,
    * preserved data and full EXE/every-overlay hashes are the falsifiable
    * test vector. Compiler/flags/filters/matching gates are unchanged.
    * AI generated; not human reviewed. Exact binary identity is the
    * confirmed scope; helper/SFX/asset semantics, physical/fixed-point
    * units, complete chains and synchronized retail runtime verification
    * remain unresolved. Cadence per invocation; frame frequency unknown.
    * Browser code and behavior are unchanged. */
    struct {
        int sp18;
        int sp1C;
        int sp20;
        unsigned char pad24[4];
        Vector3D sp28;
        unsigned char pad34[4];
        Vector3D sp38;
        unsigned char pad44[4];
        int sp48;
        int sp4C;
        int sp50;
        unsigned char pad54[4];
        Vector3D sp58;
        unsigned char pad64[4];
        int sp68;
        int sp6C;
        int sp70;
        unsigned char pad74[4];
        Vector3D sp78;
        unsigned char pad84[4];
    } originalFrame;
    register Moby* firstMoby18 __asm__("18");
    register Moby* loopMoby18 __asm__("18");
    register Moby* secondMoby16 __asm__("16");
    Vector3D* temp_a0;
    register int returned2 __asm__("2");
    register int field3 __asm__("3");
    register int zero4 __asm__("4");
    register int bound5 __asm__("5");
    register int literal2 __asm__("2");
    register int literal3 __asm__("3");
    register Moby* owner5 __asm__("5");
    register int createdId4 __asm__("4");
    register Moby* (*create3)() __asm__("3");
    register void* vector4 __asm__("4");
    register int zero5 __asm__("5");
    register void* vector6 __asm__("6");
    register void* vector7 __asm__("7");
    register void* (*particle8)() __asm__("8");
    register void* vector5 __asm__("5");
    register void* vector48Pointer17 __asm__("17");
    register int globalField3 __asm__("3");
    register int globalFlags5 __asm__("5");
    register int rawWord2 __asm__("2");
    register int playerField2 __asm__("2");
    register int difference3 __asm__("3");
    Vector3D* temp_a0_5;
    register Vector3D* position16 __asm__("$16");
    register Vector3D* secondPosition16 __asm__("$16");
    register Vector3D* positionOrVector17 __asm__("$17");
    register Vector3D* copySource5 __asm__("5");
    register int* global71908Pointer18 __asm__("18");
    register Vector3D* vector68Pointer20 __asm__("20");
    register int bound4 __asm__("4");
    register int dividend2 __asm__("2");
    register int quotient3 __asm__("3");
    register int tableOrLiteralWord4 __asm__("4");
    register int table658A0Word5 __asm__("5");
    register short* table65920Pointer4 __asm__("4");
    register short* table658A0Pointer16 __asm__("$16");
    register int scaledTableWord4 __asm__("4");
    int temp_a0_6;
    register int tableByteOffset16 __asm__("$16");
    int temp_v0_12;
    int temp_v0_4;
    register int angleWord2 __asm__("2");
    register int angleByteOffset2 __asm__("2");
    int scaledTableWord2;
    register int admittedFlag21 __asm__("$21");
    register int iteration22 __asm__("$22");
    int selectedZWord;
    int particleByteWord;
    signed char* previousParticle;
    signed char* storedParticle;
    signed char* firstParticle;
    signed char* secondParticle;
    signed char* thirdParticle;
    register unsigned int firstYawWord16 __asm__("$16");
    register unsigned int loopYawWord16 __asm__("$16");
    unsigned char stateByte;
    unsigned char temp_v1_3;
    register void* firstPrivateData17 __asm__("$17");
    register void* secondPrivateData17 __asm__("$17");
    register void* loopPrivateData17 __asm__("$17");
    register void* privateData20 __asm__("$20");
    stateByte = moby->state;
    privateData20 = moby->mobyTag;
    switch (stateByte) {
        case 0:
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            if (!(Level44_7CE54_D_8006C7B4 & 2)) {
                if (moby->substate == 0) {
                    if (func_800359A4(privateData20 + 4, 2) != 0) {
                        createdId4 = 0x57;
                        owner5 = moby;
                        create3 = SpawnMoby;
                        MATCHING_KEEP3(create3, createdId4, owner5);
                        literal2 = 0x1E;
                        firstMoby18 = create3(
                            createdId4,
                            (Level44_7CE54_Field(privateData20, short*, 4) = literal2, owner5));
                        MATCHING_KEEP(firstMoby18);
                        if (firstMoby18 != 0) {
                            firstPrivateData17 = firstMoby18->mobyTag;
                            firstMoby18->state = 2;
                            firstYawWord16 = moby->angle.yaw;
                            returned2 = func_8003636C(8, 0x40);
                            firstYawWord16 += returned2;
                            MATCHING_KEEP(firstYawWord16);
                            firstMoby18->angle.yaw = firstYawWord16;
                            Level44_7CE54_Field(firstPrivateData17, int*, 8) = 0;
                            Level44_7CE54_Field(firstPrivateData17, int*, 0xC) = 0;
                            Level44_7CE54_Field(firstPrivateData17, int*, 0x10) = 0;
                            Level44_7CE54_Field(firstPrivateData17, signed char*, 0) =
                                (signed char)(func_8003636C(0, 0xA) - 5);
                            Level44_7CE54_Field(firstPrivateData17, signed char*, 1) =
                                (signed char)(func_8003636C(0, 0xA) - 5);
                            Level44_7CE54_Field(firstPrivateData17, signed char*, 2) =
                                (signed char)(func_8003636C(0, 0xA) - 5);
                            Level44_7CE54_Field(firstPrivateData17, int*, 4) = 0x78;
                            Level44_7CE54_Field(firstPrivateData17, signed char*, 3) = 3;
                            if (Level44_7CE54_rand() & 1) {
                                Level44_7CE54SetMobyAnimation(firstMoby18, 1);
                            }
                            firstMoby18->size = 0x42;
                            firstMoby18->lowDrawDistance = 0x30;
                            firstMoby18->highDrawDistance = 0x30;
                            firstMoby18->updateDistance = 0xFF;
                            originalFrame.sp18 = func_8003636C(0, 0xBB8) - 0x5DC;
                            originalFrame.sp1C = func_8003636C(0, 0xBB8) - 0x5DC;
                            originalFrame.sp20 = -0xC8;
                            Level44_7CE54TransformVectorByBasis(
                                &moby->rotationMatrix, &originalFrame.sp18, &originalFrame.sp18);
                            temp_a0 = &firstMoby18->position;
                            func_8004F194(temp_a0, temp_a0, (Vector3D*)&originalFrame.sp18);
                        }
                    }
                    if (Level44_7CE54TestPaddedRotatedBox(&Level44_7CE54_D_80070328,
                                                          privateData20 + 0x18, 0, 0x2800) != 0) {
                        moby->substate = 1;
                        Level44_7CE54_Field(privateData20, short*, 4) = 0;
                        goto activeInitialArm;
                    }
                } else {
                activeInitialArm:
                    if (func_8004F264(func_8004E880(Level44_7CE54_D_80070328.x - moby->position.x,
                                                    Level44_7CE54_D_80070328.y - moby->position.y,
                                                    0),
                                      (int)moby->angle.yaw) < 0x41) {
                        func_8004F178(&originalFrame.sp38, &moby->position);
                        Level44_7CE54ClearVector(&originalFrame.sp28);
                        originalFrame.sp38.z -= 0x400;
                        returned2 = func_8003636C(0, 0xBB8);
                        zero4 = 0;
                        field3 = originalFrame.sp38.x;
                        bound5 = 0xBB8;
                        field3 -= 0x5DC;
                        MATCHING_KEEP(field3);
                        field3 += returned2;
                        MATCHING_KEEP(field3);
                        originalFrame.sp38.x = field3;
                        returned2 = func_8003636C(0, 0xBB8);
                        createdId4 = 1;
                        zero5 = 0;
                        vector6 = &originalFrame.sp38;
                        vector7 = &originalFrame.sp28;
                        MATCHING_KEEP4(createdId4, zero5, vector6, vector7);
                        field3 = originalFrame.sp38.y;
                        particle8 = SpawnParticle;
                        MATCHING_KEEP(particle8);
                        field3 -= 0x5DC;
                        MATCHING_KEEP(field3);
                        field3 += returned2;
                        MATCHING_KEEP(field3);
                        firstParticle = particle8(createdId4, zero5, vector6,
                                                  (originalFrame.sp38.y = field3, vector7));
                        if (firstParticle != 0) {
                            Level44_7CE54_Field(firstParticle, unsigned char*, 0xA) = 0xD2;
                        }
                        if (func_800359A4(privateData20 + 4, 2) != 0) {
                            secondMoby16 = SpawnMoby(0x57, moby);
                            MATCHING_KEEP(secondMoby16);
                            if (secondMoby16 != 0) {
                                secondPrivateData17 = secondMoby16->mobyTag;
                                if (Level44_7CE54_D_8006C640 & 1) {
                                    func_8003BB10(moby, 7, 0);
                                }
                                returned2 = func_8003636C(0, 0xBB8);
                                zero4 = 0;
                                field3 = secondMoby16->position.x;
                                bound5 = 0xBB8;
                                field3 -= 0x5DC;
                                MATCHING_KEEP(field3);
                                field3 += returned2;
                                MATCHING_KEEP(field3);
                                secondMoby16->position.x = field3;
                                returned2 = func_8003636C(0, 0xBB8);
                                zero4 = 0;
                                field3 = secondMoby16->position.y;
                                bound5 = 0x7F;
                                field3 -= 0x5DC;
                                MATCHING_KEEP(field3);
                                field3 += returned2;
                                MATCHING_KEEP(field3);
                                secondMoby16->position.y = field3;
                                secondMoby16->angle.yaw = func_8003636C(0, 0x7F);
                                secondMoby16->state = 1;
                                secondMoby16->size = 0xC;
                                secondMoby16->lowDrawDistance = 0x28;
                                secondMoby16->highDrawDistance = 0x28;
                                secondMoby16->updateDistance = 0xFF;
                                Level44_7CE54_Field(secondPrivateData17, int*, 0x10) = 0;
                                Level44_7CE54_Field(secondPrivateData17, short*, 4) = 0x78;
                                if (Level44_7CE54_rand() & 1) {
                                    Level44_7CE54SetMobyAnimation(secondMoby16, 1);
                                }
                                Level44_7CE54_Field(privateData20, short*, 4) = 0xA;
                                return;
                            }
                        }
                    } else {
                        goto deleteMoby;
                    }
                }
            } else {
                goto deleteMoby;
                default:
                    return;
            }
            break;
        case 1:
            moby->position.z += Level44_7CE54_Field(privateData20, int*, 0x10);
            temp_v0_4 = Level44_7CE54_Field(privateData20, int*, 0x10) - 0x10;
            Level44_7CE54_Field(privateData20, int*, 0x10) = temp_v0_4;
            admittedFlag21 = 0;
            if (temp_v0_4 < -0xFA) {
                Level44_7CE54_Field(privateData20, int*, 0x10) = -0xFA;
            }
            positionOrVector17 = &moby->position;
            moby->position.z += 0x400;
            Level44_7CE54QueryWorldHeight(positionOrVector17, 0x2000);
            moby->position.z -= 0x400;
            if (Level44_7CE54TestPlayerSphereOverlap(positionOrVector17, 0x2BC, 7) != 0) {
                angleWord2 = func_8004E880(Level44_7CE54_D_80070328.x - moby->position.x,
                                           Level44_7CE54_D_80070328.y - moby->position.y, 0);
                returned2 = angleWord2;
                globalFlags5 = 0x10000480;
                globalField3 = Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x20C);
                MATCHING_KEEP_CLOBBER(globalField3, "4");
                tableOrLiteralWord4 = 0x39;
                Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x298) = returned2;
                MATCHING_KEEP_CLOBBER(returned2, "memory");
                angleByteOffset2 = returned2 * 2;
                Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x23C) = tableOrLiteralWord4;
                MATCHING_KEEP_VOLATILE_CLOBBER(globalField3, "memory");
                Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x20C) =
                    globalField3 | globalFlags5;
                tableOrLiteralWord4 = *(short*)(&Level44_7CE54_D_80065920 + angleByteOffset2);
                MATCHING_KEEP_VOLATILE_CLOBBER(tableOrLiteralWord4, "21");
                admittedFlag21 = 1;
                scaledTableWord4 = (tableOrLiteralWord4 * 0x4B) >> 0xC;
                originalFrame.sp48 = scaledTableWord4;
                table658A0Word5 = *(short*)(&Level44_7CE54_D_800658A0 + angleByteOffset2);
                MATCHING_KEEP(table658A0Word5);
                originalFrame.sp50 = 0;
                Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x21C) = scaledTableWord4;
                Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x224) = 0x32;
                MATCHING_KEEP_VOLATILE_CLOBBER(table658A0Word5, "memory");
                scaledTableWord2 = (table658A0Word5 * 0x4B) >> 0xC;
                originalFrame.sp4C = scaledTableWord2;
                Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x220) = scaledTableWord2;
            }
            if ((admittedFlag21 != 0) || (func_800359A4(privateData20 + 4, 2) != 0) ||
                (global71908Pointer18 = &Level44_7CE54_D_80071908, __extension__({
                     MATCHING_KEEP(global71908Pointer18);
                     moby->position.z < (*global71908Pointer18 + 0x78);
                 }))) {
                previousParticle = Level44_7CE54_Field(privateData20, signed char**, 0x14);
                if (previousParticle != 0) {
                    Level44_7CE54ReleaseParticleRecord(previousParticle);
                    Level44_7CE54_Field(privateData20, signed char**, 0x14) = 0;
                }
                if ((admittedFlag21 == 0) && (Level44_7CE54_Field(privateData20, short*, 4) != 0)) {
                    vector48Pointer17 = &originalFrame.sp48;
                    vector4 = vector48Pointer17;
                    vector5 = &Level44_7CE54_D_8006E020;
                    MATCHING_KEEP2_CLOBBER(vector4, vector5, "16");
                    position16 = &moby->position;
                    Level44_7CE54SubtractVector(vector4, vector5, position16);
                    Level44_7CE54ScaleVectorRatioQ15(&originalFrame.sp48, ({
                        MATCHING_KEEP(admittedFlag21);
                        Level44_7CE54MeasureVectorLength(&originalFrame.sp48, 0);
                    }),
                                                     0xC8);
                    originalFrame.sp50 = 0;
                    func_8004F194((Vector3D*)&originalFrame.sp48, position16,
                                  (Vector3D*)&originalFrame.sp48);
                    Level44_7CE54ClearVector(&originalFrame.sp58);
                    secondParticle = ({
                        MATCHING_KEEP(admittedFlag21);
                        SpawnParticle(1, 0, (Vector3D*)&originalFrame.sp48, &originalFrame.sp58);
                    });
                    if (secondParticle != 0) {
                        Level44_7CE54_Field(secondParticle, unsigned char*, 0xA) = 0x8C;
                    }
                    thirdParticle = ({
                        MATCHING_KEEP(admittedFlag21);
                        SpawnParticle(1, 0x47, (Vector3D*)&originalFrame.sp48, 0);
                    });
                    if (thirdParticle != 0) {
                        *thirdParticle = 0x48;
                    }
                    returned2 = Level44_7CE54_D_80071908;
                    literal3 = 3;
                    moby->state = literal3;
                    moby->position.z = returned2;
                    Level44_7CE54_Field(privateData20, short*, 4) = 0x2D;
                    return;
                }
                func_8003BABC(moby, 0, 0);
                Level44_7CE54RefreshMobySpatialGridAndBasis(moby, 4);
                moby->angle.roll = 0;
                moby->angle.pitch = 0;
                originalFrame.sp18 =
                    (int)(*(short*)(&Level44_7CE54_D_80065920 + (moby->angle.yaw * 2)) * 0x4B) >>
                    0xB;
                iteration22 = 0;
                rawWord2 = *(short*)(&Level44_7CE54_D_800658A0 + (moby->angle.yaw * 2));
                MATCHING_KEEP_VOLATILE_CLOBBER(rawWord2, "20");
                vector68Pointer20 = &originalFrame.sp68;
                originalFrame.sp20 = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(rawWord2, "memory");
                originalFrame.sp1C = (rawWord2 * 0x4B) >> 0xB;
            createdMobyLoop:
                createdId4 = 0x57;
                if ((Level44_7CE54_D_8006C578 - Level44_7CE54_D_8006C574) >= 0x15) {
                    loopMoby18 = SpawnMoby(createdId4, moby);
                    MATCHING_KEEP(loopMoby18);
                    if (loopMoby18 != 0) {
                        loopPrivateData17 = loopMoby18->mobyTag;
                        loopMoby18->state = 2;
                        loopYawWord16 = moby->angle.yaw;
                        loopMoby18->angle.yaw = ({
                            int randomWord;
                            randomWord = func_8003636C(8, 0x40);
                            MATCHING_KEEP(loopYawWord16);
                            loopYawWord16 + randomWord;
                        });
                        table65920Pointer4 = (short*)&Level44_7CE54_D_80065920;
                        MATCHING_KEEP(table65920Pointer4);
                        tableByteOffset16 = loopYawWord16 * 2;
                        table65920Pointer4 =
                            (short*)((int)tableByteOffset16 + (int)table65920Pointer4);
                        MATCHING_KEEP(table65920Pointer4);
                        {
                            register int sample3 __asm__("3");
                            register int word2 __asm__("2");
                            register int product5 __asm__("5");
                            register int product6 __asm__("6");
                            register int product3 __asm__("3");
                            sample3 = *table65920Pointer4;
                            word2 = originalFrame.sp18;
                            product5 = word2 * sample3;
                            table658A0Pointer16 = tableByteOffset16 + &Level44_7CE54_D_800658A0;
                            sample3 = *table658A0Pointer16;
                            word2 = originalFrame.sp1C;
                            product3 = word2 * sample3;
                            MATCHING_KEEP(product3);
                            word2 = (product5 - product3) >> 0xC;
                            Level44_7CE54_Field(loopPrivateData17, int*, 8) = word2;
                            sample3 = *table658A0Pointer16;
                            word2 = originalFrame.sp18;
                            product6 = word2 * sample3;
                            sample3 = *table65920Pointer4;
                            word2 = originalFrame.sp1C;
                            product3 = word2 * sample3;
                            MATCHING_KEEP(product3);
                            word2 = (product6 + product3) >> 0xC;
                            Level44_7CE54_Field(loopPrivateData17, int*, 0xC) = word2;
                        }
                        Level44_7CE54_Field(loopPrivateData17, int*, 0x10) =
                            func_8003636C(0x4B, 0xC8);
                        Level44_7CE54_Field(loopPrivateData17, signed char*, 0) =
                            (signed char)(func_8003636C(0, 0xA) - 5);
                        Level44_7CE54_Field(loopPrivateData17, signed char*, 1) =
                            (signed char)(func_8003636C(0, 0xA) - 5);
                        Level44_7CE54_Field(loopPrivateData17, signed char*, 2) =
                            (signed char)(func_8003636C(0, 0xA) - 5);
                        Level44_7CE54_Field(loopPrivateData17, int*, 4) = 0x78;
                        Level44_7CE54_Field(loopPrivateData17, signed char*, 3) = 3;
                        if (Level44_7CE54_rand() & 1) {
                            Level44_7CE54SetMobyAnimation(loopMoby18, 1);
                        }
                        if (admittedFlag21 != 0) {
                            selectedZWord = loopMoby18->position.z + 0x96;
                        } else {
                            selectedZWord = Level44_7CE54_D_80071908 + 0x96;
                        }
                        loopMoby18->position.z = selectedZWord;
                        MATCHING_BARRIER_VOLATILE("memory");
                        loopMoby18->size = 0x6A;
                        loopMoby18->lowDrawDistance = 0x3F;
                        loopMoby18->updateDistance = 0xFF;
                        originalFrame.sp68 = func_8003636C(0, 0x1F4) - 0xFA;
                        originalFrame.sp6C = func_8003636C(0, 0x1F4) - 0xFA;
                        originalFrame.sp70 = func_8003636C(0, 0xFA);
                        Level44_7CE54TransformVectorByBasis(&moby->rotationMatrix,
                                                            vector68Pointer20, vector68Pointer20);
                        temp_a0_5 = &loopMoby18->position;
                        func_8004F194(temp_a0_5, temp_a0_5, (Vector3D*)vector68Pointer20);
                    }
                    iteration22 += 1;
                    if (iteration22 < 5) {
                        goto createdMobyLoop;
                    }
                }
                vector4 = &moby->position;
                if (admittedFlag21 != 0) {
                    copySource5 = &Level44_7CE54_D_80070328;
                    MATCHING_KEEP(copySource5);
                } else {
                    copySource5 = &Level44_7CE54_D_80071900;
                }
                func_8004F178(vector4, copySource5);
                func_800369B8(moby, 0x1E);
                func_800369B8(moby, 0x1E);
                if (admittedFlag21 != 0) {
                    moby->unknown3[0] = 0;
                    moby->lowDrawDistance = 0;
                    moby->drawn = 0;
                    moby->state = 4;
                    return;
                }
                goto deleteMoby;
            }
            func_8004F178((Vector3D*)&originalFrame.sp18, positionOrVector17);
            if ((Level44_7CE54_Field(privateData20, signed char**, 0x14) != 0) ||
                (func_8004F178((Vector3D*)&originalFrame.sp18, positionOrVector17),
                 originalFrame.sp20 = *global71908Pointer18,
                 storedParticle = ({
                     MATCHING_KEEP(admittedFlag21);
                     SpawnParticle(1, 0x32, (Vector3D*)&originalFrame.sp18, 0);
                 }),
                 Level44_7CE54_Field(privateData20, signed char**, 0x14) = storedParticle,
                 (storedParticle != 0))) {
                playerField2 = moby->position.z;
                difference3 = *global71908Pointer18;
                MATCHING_KEEP2_VOLATILE_CLOBBER(playerField2, difference3, "4");
                bound4 = 0x2EE0;
                MATCHING_KEEP(bound4);
                difference3 = playerField2 - difference3;
                MATCHING_KEEP(bound4);
                returned2 = bound4 < difference3;
                MATCHING_KEEP(returned2);
                if (returned2 == 0) {
                    dividend2 = bound4 - difference3;
                } else {
                    difference3 = 0x2EE0;
                    MATCHING_KEEP(difference3);
                    dividend2 = bound4 - difference3;
                }
                quotient3 = (dividend2 << 9) / bound4;
                particleByteWord = quotient3 / 4;
                if (particleByteWord >= 0x100) {
                    particleByteWord = 0xFF;
                }
                Level44_7CE54_Field(Level44_7CE54_Field(privateData20, signed char**, 0x14),
                                    signed char*, 0xA) = (signed char)particleByteWord;
                func_8004F178(&originalFrame.sp78, positionOrVector17);
                originalFrame.sp78.z = *global71908Pointer18;
                func_8004F504(
                    (Vector3D16*)(Level44_7CE54_Field(privateData20, signed char**, 0x14) + 4),
                    (Vector3D16*)&originalFrame.sp78);
                return;
            }
            break;
        case 4:
            Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x20C) =
                (int)(Level44_7CE54_Field(&Level44_7CE54_D_80070328, int*, 0x20C) | 0x10000002);
            if (func_800359A4(privateData20 + 4, 2) != 0) {
                if (!(Level44_7CE54_D_8006C7B4 & 2) &&
                    !(*(&Level44_7CE54_D_80070300 + Level44_7CE54_D_8006C58C) & 2)) {
                    temp_a0_6 = Level44_7CE54_D_8006C58C * 6;
                    temp_v1_3 = *(&Level44_7CE54_D_800716AC + 1 + temp_a0_6);
                    if (temp_v1_3 < 0xFFU) {
                        *(&Level44_7CE54_D_800716AC + 1 + temp_a0_6) = temp_v1_3 + 1;
                    }
                }
                Level44_7CE54RestoreOrClearTrackedSnapshot(&Level44_7CE54_D_8006D088);
                return;
            }
            break;
        case 3:
            if (func_800359A4(privateData20 + 4, 2) != 0) {
                goto deleteMoby;
            }
            break;
        case 2:
            positionOrVector17 = &originalFrame.sp58;
            vector4 = positionOrVector17;
            MATCHING_KEEP_CLOBBER(vector4, "16");
            secondPosition16 = &moby->position;
            func_8004F178(vector4, secondPosition16);
            moby->position.x += Level44_7CE54_Field(privateData20, int*, 8);
            moby->position.y += Level44_7CE54_Field(privateData20, int*, 0xC);
            temp_v0_12 = Level44_7CE54_Field(privateData20, int*, 0x10) - 0xA;
            Level44_7CE54_Field(privateData20, int*, 0x10) = temp_v0_12;
            if (temp_v0_12 < -0xC8) {
                Level44_7CE54_Field(privateData20, int*, 0x10) = -0xC8;
            }
            moby->position.z += Level44_7CE54_Field(privateData20, int*, 0x10);
            moby->angle.roll += Level44_7CE54_Field(privateData20, unsigned char*, 0);
            moby->angle.pitch += Level44_7CE54_Field(privateData20, unsigned char*, 1);
            moby->angle.yaw += Level44_7CE54_Field(privateData20, unsigned char*, 2);
            if ((func_800359A4(privateData20 + 4, 2) != 0) ||
                (Level44_7CE54QueryWorldSegmentWithOptions(&originalFrame.sp58, secondPosition16, 5,
                                                           0, 0) != 0)) {
                func_800369B8(moby, 0x28);
                goto deleteMoby;
            }
            break;
    }
    return;
deleteMoby:
    Level44_7CE54DeleteMoby(moby);
    return;
}
#undef Level44_7CE54_Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; original 8007DA38.
* Original assembly SHA256 de31374dfa4496a736329b184985173f9c721a75a5a7973d0654024087c1b538.
* AI generated; not human reviewed. All 1031 original instructions,
* eight selector words and actual destinations must match: 1039 words.
* Original A0hex frame, S0..S7/FP/RA saves and SP18..77 storage remain.
* Both original multiplies have complete initialized signed64 C producers.
* The first consumes the complete product into its original LO word;
* rawWord2 then holds that signed low32 word before the second full product.
* The second consumes its complete product into the original HI word,
* followed by signed >>6 and the original signed dividend correction.
* Empty x-input/l-output and x-input/h-output metadata emit no CPU words;
* neither input is a synthetic low word, undefined HI/LO value or opcode.
* Replacing only the later product forces a spill: the earlier SI result
* otherwise makes reload reserve LO globally, overlapping the full DI pair.
* Both complete producers remove that allocator conflict. Lifetime phases
* are disjoint and no fixed FP or overlapping live fixed aliases are used.
* Original branch joins, load/store widths, dynamic divisions and their
* zero/overflow checks, callback arguments and eight selectors are retained.
* Shared helper views reuse existing matched EXE/header contracts.
* Compiler/filter/flags unchanged. Confidence: binary identity after every
* native/linked word, actual target, owned-data and full retail hash gate.
* Raw physical units/fixed point, full helper/caller chains, cadence beyond
* one invocation, Rev1 mapping and synchronized runtime remain unresolved.
* Next evidence: human review and synchronized retail captures.
*/
#define Level44_7DA38Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_7DA38TestSubdividedSegmentPath() __asm__("func_80013E38");
int Level44_7DA38QueryWorldSegmentWithOptions() __asm__("func_8001830C");
int Level44_7DA38QueryWorldSphereWithOptions() __asm__("func_80019138");
void* Level44_7DA38QueryDynamicObjectSegment() __asm__("func_8001AD60");
int Level44_7DA38TestPlayerSphereOverlap() __asm__("func_8001C288");
int Level44_7DA38SetMobyAnimation() __asm__("func_80034F80");
int Level44_7DA38TurnMobyTowardPlayer() __asm__("func_8003573C");
int Level44_7DA38CountTimerDown(void*, int) __asm__("func_800359A4");
int Level44_7DA38RandBetween() __asm__("func_8003636C");
int Level44_7DA38PlayMobySoundEvent() __asm__("func_8003BABC");
int Level44_7DA38GetSurfaceTypeFromFlags() __asm__("func_80040954");
int Level44_7DA38PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Level44_7DA38TransformVectorByBasis() __asm__("func_8004ED6C");
int Level44_7DA38MeasureVectorLength() __asm__("func_8004EDE8");
int Level44_7DA38ComputeVectorPlaneResponse() __asm__("func_8004EF74");
int Level44_7DA38ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Level44_7DA38CopyVector() __asm__("func_8004F178");
int Level44_7DA38AddVector() __asm__("func_8004F194");
int Level44_7DA38SubtractVector() __asm__("func_8004F1C8");
int Level44_7DA38ApproximatePlanarDistance() __asm__("func_8004F334");
int Level44_7DA38DeleteMoby() __asm__("func_80055B18");
int Level44_7DA38RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level44_7DA38Datarand(void) __asm__("rand");
extern int Level44_7DA38Data658A0 __asm__("D_800658A0");
extern int Level44_7DA38Data65920 __asm__("D_80065920");
extern int Level44_7DA38Data6C550 __asm__("D_8006C550");
extern int Level44_7DA38Data6D048 __asm__("D_8006D048");
extern int Level44_7DA38Data6E020 __asm__("D_8006E020");
extern int Level44_7DA38Data6E024 __asm__("D_8006E024");
extern int Level44_7DA38Data6E028 __asm__("D_8006E028");
extern unsigned short Level44_7DA38Data6E03E __asm__("D_8006E03E");
extern unsigned short Level44_7DA38Data6E040 __asm__("D_8006E040");
extern void* Level44_7DA38Data6E788 __asm__("D_8006E788");
extern int Level44_7DA38Data70328 __asm__("D_80070328");
extern int Level44_7DA38Data71900 __asm__("D_80071900");
extern int Level44_7DA38Data71918 __asm__("D_80071918");
extern int Level44_7DA38Data71924 __asm__("D_80071924");
extern void* (*Level44_7DA38DataSpawnMoby)() __asm__("SpawnMoby");
extern void* (*Level44_7DA38DataSpawnParticle)() __asm__("SpawnParticle");
extern int (*Level44_7DA38Data74424)() __asm__("unk_ovlheader_80074424");
extern void* (*Level44_7DA38Data74428)() __asm__("unk_ovlheader_80074428");
void func_level_44_8007DA38(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int retainedAngleOrRecord16 __asm__("$16"), retainedRecordOrVector17 __asm__("$17"),
        retainedAngleOrAddress18 __asm__("$18"), retainedRecordOrDataAddress20 __asm__("$20"),
        privateRecord21 __asm__("$21"), retainedSearchPosition22 __asm__("$22"),
        retainedSelectedRecord23 __asm__("$23");
    register int rangeBoundOrProductHigh10 __asm__("$10");
    register int rawWord2 __asm__("$2"), rawWord3, argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        nearestDifference8 __asm__("$8"), directionSign9 __asm__("$9");
    int retainedMinimumScoreOrDataAddress;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74;
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
    privateRecord21 = (int)Level44_7DA38Field(ownerRecord19, void**, 0);
    Level44_7DA38RefreshMobySpatialGridAndBasis(ownerParameter, 6);
    rawWord3 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48);
    retainedSearchPosition22 = 0;
    switch (rawWord3) {
        case 5:
            retainedMinimumScoreOrDataAddress = 0x1869F;
            retainedSelectedRecord23 = 0;
            retainedRecordOrDataAddress20 = (int)&Level44_7DA38Data6E788;
            retainedRecordOrVector17 = Level44_7DA38Field(retainedRecordOrDataAddress20, int*, 0);
            retainedRecordOrDataAddress20 += 4;
            if (retainedRecordOrVector17 != 0) {
                retainedSearchPosition22 = ownerRecord19 + 0xC;
                do {
                    if ((Level44_7DA38Field(retainedRecordOrVector17, short*, 0x36) != 0x63) &&
                        !(Level44_7DA38Field(retainedRecordOrVector17, unsigned char*, 0x48) &
                          0x80) &&
                        (Level44_7DA38Field(retainedRecordOrVector17, int*, 8) != 0) &&
                        (Level44_7DA38Field(ownerRecord19, unsigned char*, 0x4D) != 0)) {
                        rangeBoundOrProductHigh10 = 0x8000;
                        __asm__(""
                                : "=r"(rangeBoundOrProductHigh10)
                                : "0"(rangeBoundOrProductHigh10)
                                : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9");
                        rawWord3 = Level44_7DA38Field(retainedRecordOrVector17, int*, 0xC);
                        rawWord2 = Level44_7DA38Field(ownerRecord19, int*, 0xC);
                        argumentWord4 = rawWord3 - rawWord2;
                        rawWord2 = argumentWord4;
                        if (argumentWord4 < 0) {
                            MATCHING_KEEP(rawWord2);
                            rawWord2 = -rawWord2;
                        }
                        if (rawWord2 <= rangeBoundOrProductHigh10) {
                            rawWord3 = Level44_7DA38Field(retainedRecordOrVector17, int*, 0x10);
                            rawWord2 = Level44_7DA38Field(ownerRecord19, int*, 0x10);
                            argumentWord5 = rawWord3 - rawWord2;
                            rawWord2 = argumentWord5;
                            if (argumentWord5 < 0) {
                                MATCHING_KEEP(rawWord2);
                                rawWord2 = -rawWord2;
                            }
                            if (rawWord2 <= rangeBoundOrProductHigh10) {
                                retainedAngleOrRecord16 =
                                    (Level44_7DA38PlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                      0) -
                                     Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46)) &
                                    0xFF;
                                __asm__(""
                                        : "=r"(retainedSearchPosition22)
                                        : "0"(retainedSearchPosition22),
                                          "r"(retainedAngleOrRecord16));
                                argumentWord4 = retainedSearchPosition22;
                                if (retainedAngleOrRecord16 >= 0x81) {
                                    retainedAngleOrRecord16 -= 0x100;
                                }
                                MATCHING_BARRIER_GNU_VOLATILE("$18");
                                retainedAngleOrAddress18 = retainedRecordOrVector17 + 0xC;
                                rawWord3 =
                                    (Level44_7DA38PlanarHeadingLookup(
                                         Level44_7DA38ApproximatePlanarDistance(
                                             argumentWord4, retainedAngleOrAddress18),
                                         Level44_7DA38Field(retainedRecordOrVector17, int*, 0x14) -
                                             Level44_7DA38Field(ownerRecord19, int*, 0x14),
                                         0) -
                                     Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45)) &
                                    0xFF;
                                if (rawWord3 >= 0x81) {
                                    rawWord3 -= 0x100;
                                }
                                if (retainedAngleOrRecord16 < 0) {
                                    retainedAngleOrRecord16 = -retainedAngleOrRecord16;
                                }
                                if (rawWord3 < 0) {
                                    MATCHING_KEEP(rawWord3);
                                    rawWord3 = -rawWord3;
                                }
                                __asm__(""
                                        : "=r"(retainedAngleOrRecord16)
                                        : "0"(retainedAngleOrRecord16), "r"(rawWord3));
                                if ((retainedAngleOrRecord16 < 8) && (rawWord3 < 8)) {
                                    retainedAngleOrRecord16 =
                                        (retainedAngleOrRecord16 * 8) + rawWord3;
                                    MATCHING_KEEP(retainedAngleOrRecord16);
                                    retainedAngleOrRecord16 +=
                                        Level44_7DA38ApproximatePlanarDistance(
                                            retainedSearchPosition22, retainedAngleOrAddress18) >>
                                        10;
                                    if ((retainedAngleOrRecord16 <
                                         retainedMinimumScoreOrDataAddress) &&
                                        (Level44_7DA38TestSubdividedSegmentPath(
                                             retainedSearchPosition22, retainedAngleOrAddress18,
                                             4) != 0)) {
                                        retainedSelectedRecord23 = retainedRecordOrVector17;
                                        retainedMinimumScoreOrDataAddress = retainedAngleOrRecord16;
                                    }
                                }
                            }
                        }
                    }
                    retainedRecordOrVector17 =
                        Level44_7DA38Field(retainedRecordOrDataAddress20, void**, 0);
                    retainedRecordOrDataAddress20 += 4;
                } while (retainedRecordOrVector17 != 0);
            }
            argumentWord4 = privateRecord21;
            if (retainedSelectedRecord23 != 0) {
                argumentWord5 = retainedSelectedRecord23 + 12;
                argumentWord6 = Level44_7DA38Data6C550;
                rawWord2 = 7;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
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
                rawWord2 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46);
                rawWord3 >>= 3;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x49) = rawWord3;
                Level44_7DA38Field(argumentWord4, unsigned char*, 0xF) = rawWord2;
                Level44_7DA38CopyVector(argumentWord4, argumentWord5, argumentWord6);
                return;
            }
            Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) = 0U;
            retainedSearchPosition22 = 1;
        case 6:
            if (Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) == 6) {
                Level44_7DA38TurnMobyTowardPlayer(ownerRecord19, 0x80, 0, 0);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45) =
                    Level44_7DA38PlanarHeadingLookup(
                        Level44_7DA38ApproximatePlanarDistance(ownerRecord19 + 0xC,
                                                               ((void*)&Level44_7DA38Data70328)),
                        Level44_7DA38Field(((void*)&Level44_7DA38Data70328), int*, 8) -
                            Level44_7DA38Field(ownerRecord19, int*, 0x14),
                        0);
                Level44_7DA38RefreshMobySpatialGridAndBasis(ownerRecord19, 4);
                argumentWord4 = (int)ownerRecord19 + 0x20;
                argumentWord5 = (int)&originalFrame.sp18;
                rawWord2 = Level44_7DA38Field(privateRecord21, short*, 0xC);
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord5);
                argumentWord6 = privateRecord21;
                originalFrame.sp1C = 0;
                originalFrame.sp20 = 0;
                originalFrame.sp18 = rawWord2;
                Level44_7DA38TransformVectorByBasis(argumentWord4, argumentWord5, argumentWord6);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                case 7:
            }
            retainedAngleOrAddress18 = 0;
            if (Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) == 7) {
                argumentWord4 = (int)&originalFrame.sp18;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                rawWord3 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x49);
                argumentWord5 = (int)ownerRecord19 + 12;
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level44_7DA38Data6C550;
                retainedRecordOrDataAddress20 = rawWord3 + rawWord2;
                retainedAngleOrRecord16 = retainedRecordOrDataAddress20 + 12;
                MATCHING_KEEP(retainedAngleOrRecord16);
                Level44_7DA38SubtractVector(argumentWord4, argumentWord5, retainedAngleOrRecord16);
                rawWord2 =
                    Level44_7DA38PlanarHeadingLookup(originalFrame.sp18, originalFrame.sp1C, 0);
                retainedRecordOrVector17 = (int)&originalFrame.sp28;
                argumentWord4 = retainedRecordOrVector17;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                argumentWord5 = retainedAngleOrRecord16;
                rawWord3 = rawWord2 - 128;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46) = rawWord3;
                retainedAngleOrRecord16 =
                    Level44_7DA38Field(retainedRecordOrDataAddress20, unsigned char*, 0x46);
                MATCHING_OBSERVE_GNU_VOLATILE(retainedAngleOrRecord16);
                argumentWord6 = privateRecord21;
                retainedAngleOrRecord16 -= rawWord2;
                retainedAngleOrRecord16 &= 255;
                Level44_7DA38SubtractVector(argumentWord4, argumentWord5, argumentWord6);
                rawWord2 = Level44_7DA38MeasureVectorLength(retainedRecordOrVector17, 0);
                retainedAngleOrRecord16 += 64;
                retainedAngleOrRecord16 &= 255;
                retainedAngleOrRecord16 <<= 1;
                rawWord3 =
                    Level44_7DA38Field(&Level44_7DA38Data65920, short*, retainedAngleOrRecord16);
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
                    rawWord3 = (int)&Level44_7DA38Data658A0;
                    argumentWord5 = rawWord2 + rawWord3;
                    do {
                        rawWord2 = Level44_7DA38Field(argumentWord5, short*, 0) - argumentWord6;
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
                Level44_7DA38CopyVector(retainedAngleOrRecord16, retainedRecordOrDataAddress20 + 12,
                                        argumentWord6, argumentWord7);
                argumentWord4 = (int)ownerRecord19 + 12;
                rawWord2 = originalFrame.sp30;
                argumentWord5 = retainedAngleOrRecord16;
                rawWord2 += 500;
                originalFrame.sp30 = rawWord2;
                rawWord2 = Level44_7DA38ApproximatePlanarDistance(argumentWord4, argumentWord5);
                argumentWord4 = rawWord2;
                rawWord2 = originalFrame.sp30;
                argumentWord5 = Level44_7DA38Field(ownerRecord19, int*, 0x14);
                argumentWord6 = 0;
                argumentWord5 = rawWord2 - argumentWord5;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45) =
                    Level44_7DA38PlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46) =
                    (unsigned char)(Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46) +
                                    retainedAngleOrAddress18);
                originalFrame.sp28 = 0x258;
                originalFrame.sp2C = 0;
                originalFrame.sp30 = 0;
                Level44_7DA38RefreshMobySpatialGridAndBasis(ownerRecord19, 4);
                Level44_7DA38TransformVectorByBasis(ownerRecord19 + 0x20, retainedAngleOrRecord16,
                                                    privateRecord21);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45) =
                    Level44_7DA38PlanarHeadingLookup(
                        Level44_7DA38MeasureVectorLength(privateRecord21, 1),
                        Level44_7DA38Field(privateRecord21, int*, 8), 0);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46) =
                    Level44_7DA38PlanarHeadingLookup(Level44_7DA38Field(privateRecord21, int*, 0),
                                                     Level44_7DA38Field(privateRecord21, int*, 4),
                                                     0);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) = 0U;
            }
        case 0:
            retainedAngleOrRecord16 = 0;
            rawWord3 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x3A);
            MATCHING_KEEP(rawWord3);
            retainedRecordOrVector17 = 0;
            if (rawWord3 < 0xFFU) {
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level44_7DA38Data6C550;
                retainedAngleOrRecord16 = rawWord3 + rawWord2;
            }
            if ((retainedSearchPosition22 != 0) && (retainedAngleOrRecord16 != 0)) {
                Level44_7DA38CopyVector(&originalFrame.sp48, retainedAngleOrRecord16 + 0xC);
                originalFrame.sp50 += 0x200;
            } else {
                Level44_7DA38CopyVector(&originalFrame.sp48, ownerRecord19 + 0xC);
            }
            argumentWord4 = (int)&originalFrame.sp38;
            MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
            retainedAngleOrAddress18 = (int)ownerRecord19 + 12;
            Level44_7DA38AddVector(argumentWord4, retainedAngleOrAddress18, privateRecord21);
            if ((originalFrame.sp38 < 0x1068) || (originalFrame.sp3C < 0x1068) ||
                (originalFrame.sp40 < 0x1068) || (originalFrame.sp38 > 0x3E738) ||
                (originalFrame.sp3C > 0x3E738) || (originalFrame.sp40 > 0x3E738)) {
                temp_a0_2 = Level44_7DA38Field(privateRecord21, void**, 0x14);
                if (temp_a0_2 != 0) {
                    Level44_7DA38DeleteMoby(temp_a0_2);
                    __asm__ __volatile__("" ::"i"(103111) : "memory");
                    Level44_7DA38Field(privateRecord21, void**, 0x14) = 0;
                }
                goto block_134;
            }
            if ((retainedAngleOrRecord16 != 0) &&
                (Level44_7DA38Field(retainedAngleOrRecord16, short*, 0x36) != 0x63) &&
                (Level44_7DA38TestPlayerSphereOverlap(retainedAngleOrAddress18, 0xC8, 1) != 0)) {
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord5, "memory");
                rawWord2 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46);
                rawWord3 = (int)Level44_7DA38DataSpawnMoby;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(rawWord2, rawWord3, "$17");
                retainedRecordOrVector17 = (int)&Level44_7DA38Data70328 + 0x298;
                Level44_7DA38Field(retainedRecordOrVector17, int*, 0) = rawWord2;
                retainedAngleOrRecord16 = ((void* (*)())rawWord3)(argumentWord4, argumentWord5);
                MATCHING_KEEP(retainedAngleOrRecord16);
                if (retainedAngleOrRecord16 != 0) {
                    rawWord3 = Level44_7DA38Field(retainedAngleOrRecord16, void**, 0);
                    Level44_7DA38Field(retainedAngleOrRecord16, signed char*, 0x48) = 4;
                    Level44_7DA38Field(retainedAngleOrRecord16, signed char*, 0x41) = 0;
                    Level44_7DA38Field(retainedAngleOrRecord16, signed char*, 0x4C) = 0;
                    Level44_7DA38Field(retainedAngleOrRecord16, signed char*, 0x4D) = 0;
                    Level44_7DA38Field(rawWord3, short*, 0x10) = 0xF;
                    Level44_7DA38Field(rawWord3, short*, 0x12) = 1;
                    Level44_7DA38CopyVector(retainedAngleOrRecord16 + 0xC,
                                            retainedRecordOrVector17 - 0x298);
                    Level44_7DA38Field(retainedAngleOrRecord16, int*, 0x14) =
                        (int)Level44_7DA38Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            if (Level44_7DA38Field(privateRecord21, short*, 0xC) >= 0xFA1) {
                rawWord2 =
                    Level44_7DA38Data74424(&originalFrame.sp48, &originalFrame.sp38, 0, 1) == 0;
            } else {
                rawWord2 = Level44_7DA38QueryWorldSegmentWithOptions(&originalFrame.sp48,
                                                                     &originalFrame.sp38, 2, 1, 0);
            }
            if (rawWord2 == 0) {
                rawWord2 = Level44_7DA38Field(privateRecord21, short*, 0xC);
                if (rawWord2 >= 4001) {
                    argumentWord4 = (int)&originalFrame.sp48;
                    argumentWord5 = (int)&originalFrame.sp38;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord5, "memory");
                    rawWord2 = (int)Level44_7DA38Data74428;
                    argumentWord6 = 0;
                    retainedAngleOrRecord16 =
                        ((void* (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6);
                } else {
                    argumentWord4 = (int)&originalFrame.sp48;
                    argumentWord5 = (int)&originalFrame.sp38;
                    argumentWord6 = 0;
                    argumentWord7 = 0;
                    retainedAngleOrRecord16 = Level44_7DA38QueryDynamicObjectSegment(
                        argumentWord4, argumentWord5, argumentWord6, argumentWord7, ownerRecord19);
                }
                if (retainedAngleOrRecord16 != 0) {
                    goto block_89;
                }
                goto block_120;
            }
            if (Level44_7DA38Field(privateRecord21, short*, 0xC) >= 0xFA1) {
                retainedAngleOrRecord16 = Level44_7DA38Data74428(
                    &originalFrame.sp48, ((void*)&Level44_7DA38Data71900), 0);
            } else {
                retainedAngleOrRecord16 = Level44_7DA38QueryDynamicObjectSegment(
                    &originalFrame.sp48, ((void*)&Level44_7DA38Data71900), 0, 0, ownerRecord19);
            }
            if (retainedAngleOrRecord16 != 0) {
            block_89:
                rawWord2 = Level44_7DA38PlanarHeadingLookup(
                    Level44_7DA38Field(privateRecord21, int*, 0),
                    Level44_7DA38Field(privateRecord21, int*, 4), 0);
                argumentWord4 = 197;
                argumentWord5 = 0;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
                Level44_7DA38Field(retainedAngleOrRecord16, unsigned char*, 0x51) = rawWord2;
                rawWord2 = 0x10000;
                rawWord3 = Level44_7DA38Field(retainedAngleOrRecord16, int*, 0x18);
                argumentWord6 = (int)Level44_7DA38DataSpawnMoby;
                rawWord3 |= rawWord2;
                Level44_7DA38Field(retainedAngleOrRecord16, int*, 0x18) = rawWord3;
                retainedRecordOrVector17 =
                    ((void* (*)())argumentWord6)(argumentWord4, argumentWord5, argumentWord6);
                MATCHING_KEEP(retainedRecordOrVector17);
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level44_7DA38Field(retainedRecordOrVector17, void**, 0);
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                    Level44_7DA38Field(rawWord3, short*, 0x10) = 0xF;
                    Level44_7DA38Field(rawWord3, short*, 0x12) = 1;
                    Level44_7DA38CopyVector(retainedRecordOrVector17 + 0xC,
                                            retainedAngleOrRecord16 + 0xC);
                    Level44_7DA38Field(retainedRecordOrVector17, int*, 0x14) =
                        (int)Level44_7DA38Field(ownerRecord19, int*, 0x14);
                }
                goto block_94;
            }
            if (Level44_7DA38Field(privateRecord21, unsigned char*, 0xE) != 0) {
                MATCHING_KEEP(retainedAngleOrRecord16);
                retainedRecordOrVector17 = Level44_7DA38DataSpawnMoby(0xC5, 0);
                MATCHING_KEEP(retainedRecordOrVector17);
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level44_7DA38Field(retainedRecordOrVector17, void**, 0);
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                    Level44_7DA38Field(rawWord3, short*, 0x10) = 0x1E;
                    Level44_7DA38Field(rawWord3, short*, 0x12) = 0xF;
                    Level44_7DA38CopyVector(retainedRecordOrVector17 + 0xC,
                                            ((void*)&Level44_7DA38Data71900));
                }
            block_94:
                retainedRecordOrVector17 = 1;
                goto block_120;
            } else {
                MATCHING_KEEP(retainedAngleOrRecord16);
                retainedAngleOrAddress18 = (int)&Level44_7DA38Data71924;
                if (Level44_7DA38GetSurfaceTypeFromFlags(
                        Level44_7DA38Field(retainedAngleOrAddress18, int*, 0)) == 3) {
                    temp_a0_5 = Level44_7DA38Field(
                        Level44_7DA38Field(((void*)&Level44_7DA38Data6D048), int*, 0x14), void**,
                        (Level44_7DA38Field(retainedAngleOrAddress18, int*, 0) & 0x3F) * 4);
                    Level44_7DA38Field(temp_a0_5, int*, 4) =
                        (int)(Level44_7DA38Field(temp_a0_5, int*, 4) | 0x10000);
                }
                Level44_7DA38Field(privateRecord21, unsigned char*, 0xE) =
                    (unsigned char)(Level44_7DA38Field(privateRecord21, unsigned char*, 0xE) + 1);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                retainedRecordOrVector17 = Level44_7DA38DataSpawnMoby(0xC5, 0);
                MATCHING_KEEP(retainedRecordOrVector17);
                retainedAngleOrRecord16 = retainedRecordOrVector17 + 0xC;
                if (retainedRecordOrVector17 != 0) {
                    argumentWord4 = retainedAngleOrRecord16;
                    __asm__(""
                            : "=r"(retainedAngleOrAddress18)
                            : "0"(retainedAngleOrAddress18), "r"(argumentWord4));
                    retainedMinimumScoreOrDataAddress = retainedAngleOrAddress18 - 0x24;
                    Level44_7DA38Field(Level44_7DA38Field(retainedRecordOrVector17, void**, 0),
                                       short*, 0x10) = 2;
                    Level44_7DA38CopyVector(retainedAngleOrRecord16,
                                            retainedMinimumScoreOrDataAddress);
                    rawWord2 = Level44_7DA38RandBetween(0, 0xFF);
                    argumentWord4 = retainedAngleOrRecord16;
                    retainedAngleOrRecord16 = (int)&Level44_7DA38Data6E020;
                    argumentWord5 = retainedAngleOrRecord16;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
                    retainedSearchPosition22 = rawWord2;
                    Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x44) =
                        retainedSearchPosition22;
                    rawWord2 = Level44_7DA38ApproximatePlanarDistance(argumentWord4, argumentWord5);
                    argumentWord4 = rawWord2;
                    rawWord2 = Level44_7DA38Data6E028;
                    argumentWord5 = Level44_7DA38Field(retainedRecordOrVector17, int*, 0x14);
                    argumentWord6 = 0;
                    argumentWord5 = rawWord2 - argumentWord5;
                    rawWord2 = Level44_7DA38PlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                argumentWord6);
                    argumentWord6 = 0;
                    __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
                    retainedRecordOrDataAddress20 = rawWord2;
                    Level44_7DA38Field(retainedRecordOrVector17, unsigned char*, 0x45) =
                        retainedRecordOrDataAddress20;
                    rawWord2 = Level44_7DA38PlanarHeadingLookup(
                        Level44_7DA38Field(retainedAngleOrRecord16, int*, 0) -
                            Level44_7DA38Field(retainedRecordOrVector17, int*, 0xC),
                        Level44_7DA38Data6E024 -
                            Level44_7DA38Field(retainedRecordOrVector17, int*, 0x10),
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
                    Level44_7DA38Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = 13;
                    Level44_7DA38Field(argumentWord4, unsigned char*, 0x46) =
                        retainedAngleOrAddress18;
                    Level44_7DA38Field(argumentWord4, unsigned char*, 0x54) =
                        retainedAngleOrRecord16;
                    Level44_7DA38Field(argumentWord4, unsigned char*, 0x55) = 0;
                    Level44_7DA38Field(argumentWord4, unsigned char*, 0x56) = 0;
                    Level44_7DA38Field(argumentWord4, unsigned char*, 0x57) = rawWord2;
                    Level44_7DA38SetMobyAnimation(argumentWord4, argumentWord5);
                    retainedRecordOrVector17 = Level44_7DA38DataSpawnMoby(0xC5, 0);
                    MATCHING_KEEP(retainedRecordOrVector17);
                    if (retainedRecordOrVector17 != 0) {
                        Level44_7DA38Field(Level44_7DA38Field(retainedRecordOrVector17, void**, 0),
                                           short*, 0x10) = 2;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x57) = 0xF;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x44) =
                            retainedSearchPosition22;
                        Level44_7DA38Field(retainedRecordOrVector17, unsigned char*, 0x45) =
                            retainedRecordOrDataAddress20;
                        Level44_7DA38Field(retainedRecordOrVector17, unsigned char*, 0x46) =
                            retainedAngleOrAddress18;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x54) =
                            retainedAngleOrRecord16;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x55) =
                            retainedAngleOrRecord16;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x56) =
                            retainedAngleOrRecord16;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x48) = 3;
                        Level44_7DA38CopyVector(retainedRecordOrVector17 + 0xC,
                                                retainedMinimumScoreOrDataAddress);
                        Level44_7DA38SetMobyAnimation(retainedRecordOrVector17, 3);
                    }
                }
                Level44_7DA38CopyVector(ownerRecord19 + 0xC, ((void*)&Level44_7DA38Data71900));
                Level44_7DA38CopyVector(&originalFrame.sp38,
                                        ((void*)&Level44_7DA38Data71900) + 0x18);
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
                argumentWord4 = privateRecord21;
                if (rawWord2)
                    goto integrateOriginalVector;
            clearOriginalVerticalComponent:
                originalFrame.sp40 = 0;
                argumentWord4 = privateRecord21;
            integrateOriginalVector:
                MATCHING_BARRIER_GNU_VOLATILE("$17");
                retainedRecordOrVector17 = (int)&originalFrame.sp38;
                Level44_7DA38ComputeVectorPlaneResponse(argumentWord4, retainedRecordOrVector17,
                                                        privateRecord21);
                if (Level44_7DA38Field(privateRecord21, short*, 0xC) >= 0xFA1) {
                    Level44_7DA38Field(privateRecord21, short*, 0xC) = 0x258;
                }
                Level44_7DA38ScaleVectorRatioQ15(
                    privateRecord21, Level44_7DA38MeasureVectorLength(privateRecord21, 1),
                    Level44_7DA38Field(privateRecord21, short*, 0xC));
                Level44_7DA38CopyVector(retainedRecordOrVector17, privateRecord21);
                Level44_7DA38ScaleVectorRatioQ15(
                    retainedRecordOrVector17,
                    Level44_7DA38MeasureVectorLength(retainedRecordOrVector17, 1), 0x320);
                argumentWord4 = retainedRecordOrVector17;
                MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                retainedAngleOrAddress18 = (int)ownerRecord19 + 12;
                Level44_7DA38AddVector(argumentWord4, retainedAngleOrAddress18,
                                       retainedRecordOrVector17);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45) =
                    Level44_7DA38PlanarHeadingLookup(
                        Level44_7DA38MeasureVectorLength(privateRecord21, 1),
                        Level44_7DA38Field(privateRecord21, int*, 8), 0);
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46) =
                    Level44_7DA38PlanarHeadingLookup(Level44_7DA38Field(privateRecord21, int*, 0),
                                                     Level44_7DA38Field(privateRecord21, int*, 4),
                                                     0);
                Level44_7DA38PlayMobySoundEvent(ownerRecord19, 1, 0);
                retainedAngleOrRecord16 = (int)&originalFrame.sp58;
                argumentWord4 = retainedAngleOrRecord16;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$20");
                retainedRecordOrDataAddress20 = (int)&Level44_7DA38Data71918;
                Level44_7DA38CopyVector(argumentWord4, retainedRecordOrDataAddress20);
                Level44_7DA38ScaleVectorRatioQ15(
                    &originalFrame.sp58, Level44_7DA38MeasureVectorLength(&originalFrame.sp58, 1),
                    0x37);
                Level44_7DA38AddVector(&originalFrame.sp58, retainedAngleOrAddress18,
                                       &originalFrame.sp58);
                if ((Level44_7DA38QueryWorldSphereWithOptions(&originalFrame.sp58, 0x32, 1, 0, 0,
                                                              0) != 0) ||
                    (Level44_7DA38QueryWorldSegmentWithOptions(
                         retainedRecordOrVector17, &originalFrame.sp58, 3, 0, 0) != 0)) {
                    if (Level44_7DA38GetSurfaceTypeFromFlags(Level44_7DA38Data71924) == 3) {
                        temp_a0_6 = Level44_7DA38Field(
                            Level44_7DA38Field(((void*)&Level44_7DA38Data6D048), int*, 0x14),
                            void**, (Level44_7DA38Data71924 & 0x3F) * 4);
                        Level44_7DA38Field(temp_a0_6, int*, 4) =
                            (int)(Level44_7DA38Field(temp_a0_6, int*, 4) | 0x10000);
                    }
                    retainedRecordOrVector17 = Level44_7DA38DataSpawnMoby(0xC5, 0);
                    MATCHING_KEEP(retainedRecordOrVector17);
                    if (retainedRecordOrVector17 != 0) {
                        rawWord3 = Level44_7DA38Field(retainedRecordOrVector17, void**, 0);
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x48) = 4;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x41) = 0;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x4C) = 0;
                        Level44_7DA38Field(retainedRecordOrVector17, signed char*, 0x4D) = 0;
                        Level44_7DA38Field(rawWord3, short*, 0x10) = 0x1E;
                        Level44_7DA38Field(rawWord3, short*, 0x12) = 0xF;
                        Level44_7DA38CopyVector(retainedRecordOrVector17 + 0xC,
                                                retainedRecordOrDataAddress20 - 0x18);
                    }
                    temp_a0_7 = Level44_7DA38Field(privateRecord21, void**, 0x14);
                    if (temp_a0_7 != 0) {
                        Level44_7DA38DeleteMoby(temp_a0_7);
                        __asm__ __volatile__("" ::"i"(103113) : "memory");
                        Level44_7DA38Field(privateRecord21, void**, 0x14) = 0;
                    }
                    goto block_134;
                }
                Level44_7DA38CopyVector(retainedAngleOrAddress18, retainedRecordOrVector17);
                rawWord3 = Level44_7DA38Field(privateRecord21, void**, 0x14);
                if (rawWord3 != 0) {
                    Level44_7DA38Field(rawWord3, unsigned char*, 0x45) =
                        (unsigned char)Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45);
                    Level44_7DA38Field(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                       unsigned char*, 0x46) =
                        (unsigned char)Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46);
                    Level44_7DA38CopyVector(Level44_7DA38Field(privateRecord21, void**, 0x14) + 0xC,
                                            retainedAngleOrAddress18);
                    rawWord3 = Level44_7DA38Field(privateRecord21, int*, 0x14);
                    rawWord2 = 255;
                    Level44_7DA38Field(rawWord3, unsigned char*, 0x54) = rawWord2;
                    Level44_7DA38Field(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                       signed char*, 0x55) = 0;
                    Level44_7DA38Field(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                       signed char*, 0x56) = 0;
                    Level44_7DA38Field(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                       signed char*, 0x57) = 0x38;
                    Level44_7DA38SetMobyAnimation(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                                  4);
                    return;
                }
                default:
                    return;
            }
        block_120:
            if ((retainedRecordOrVector17 != 0) ||
                (Level44_7DA38CountTimerDown(privateRecord21 + 0x10, 2) != 0)) {
                temp_a0_3 = Level44_7DA38Field(privateRecord21, void**, 0x14);
                if (temp_a0_3 != 0) {
                    Level44_7DA38DeleteMoby(temp_a0_3);
                    __asm__ __volatile__("" ::"i"(103112) : "memory");
                    Level44_7DA38Field(privateRecord21, void**, 0x14) = 0;
                }
                goto block_134;
            }
            Level44_7DA38CopyVector(ownerRecord19 + 0xC, &originalFrame.sp38);
            temp_a0_4 = Level44_7DA38Field(privateRecord21, void**, 0x14);
            if (temp_a0_4 != 0) {
                Level44_7DA38CopyVector(temp_a0_4 + 0xC, &originalFrame.sp38);
                Level44_7DA38Field(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                   unsigned char*, 0x45) =
                    (unsigned char)Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45);
                Level44_7DA38Field(Level44_7DA38Field(privateRecord21, void**, 0x14),
                                   unsigned char*, 0x46) =
                    (unsigned char)Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46);
                return;
            }
            break;
        case 4:
            Level44_7DA38Field(ownerRecord19, signed char*, 0x41) = 0;
            Level44_7DA38Field(ownerRecord19, signed char*, 0x4C) = 0;
            Level44_7DA38Field(ownerRecord19, unsigned char*, 0x4D) = 0U;
            if (Level44_7DA38Field(privateRecord21, short*, 0x10) != 0) {
                originalFrame.sp68 = (Level44_7DA38Datarand() & 0xF) - 7;
                originalFrame.sp6C = (Level44_7DA38Datarand() & 0xF) - 7;
                originalFrame.sp70 = Level44_7DA38Datarand() & 0x3F;
                Level44_7DA38DataSpawnParticle(1, 0, ownerRecord19 + 0xC, &originalFrame.sp68);
            }
            if (Level44_7DA38Field(privateRecord21, short*, 0x12) != 0) {
                Level44_7DA38CountTimerDown(privateRecord21 + 0x12, 2);
                temp_v0_12 =
                    Level44_7DA38DataSpawnParticle(1, 0x3D, ownerRecord19 + 0xC, (int*)0x808080);
                if (temp_v0_12 != 0) {
                    Level44_7DA38Field(temp_v0_12, signed char*, 0xA) = 0x32;
                }
            }
            if (Level44_7DA38CountTimerDown(privateRecord21 + 0x10, 2) != 0) {
                goto block_134;
            }
            break;
        case 1:
        case 3:
            if (Level44_7DA38Field(privateRecord21, short*, 0x10) != 0)
                goto continueOriginalStatesOneOrThree;
        block_134:
            Level44_7DA38DeleteMoby(ownerRecord19);
            return;
        continueOriginalStatesOneOrThree:
            if (Level44_7DA38CountTimerDown(privateRecord21 + 0x10, 2) != 0) {
                rawWord2 = 48;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x4F) = rawWord2;
                rawWord2 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x54);
                rawWord3 = 13;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x57) = rawWord3;
                rawWord3 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x56);
                rawWord2 >>= 3;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x54) = rawWord2;
                rawWord2 = Level44_7DA38Field(ownerRecord19, unsigned char*, 0x55);
                rawWord3 = (unsigned int)rawWord3 >> 3;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x56) = rawWord3;
                rawWord2 >>= 3;
                Level44_7DA38Field(ownerRecord19, unsigned char*, 0x55) = rawWord2;
            }
            Level44_7DA38Field(ownerRecord19, unsigned char*, 0x46) =
                (unsigned char)(((int)(Level44_7DA38Data6E040 << 0x10) >> 0x14) - 0x80);
            Level44_7DA38Field(ownerRecord19, unsigned char*, 0x45) =
                (unsigned char)((unsigned short)Level44_7DA38Data6E03E >> 4);
            break;
    }
}
#undef Level44_7DA38Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007EA54.
* AI generated; not human reviewed. All1015 instructions,47 selectors and
* one zero padding word,1063 owned words, require exact native/linked words
* and every actual transfer/table destination. Frame78 saves S0..S4/RA,
* SP20..5F locals. The old S0 index survives until its final record consumer,
* then becomes a position address; later status/position phases are disjoint.
* Original447 jumps to the one actual contact helper at752. Both complete
* argument/height entries and the independent shared height restore remain.
* Reset test/clear/call entries614/616/618 remain distinct; early literal4
* enters field writer814 after the independent late literal4 producer813.
* Shared animation writer976 and final helper1004 remain physically late.
* Complete first25/shift7 samples preserve original coordinate loads/stores.
* Signed halfword narrowing,constructor return/argument phases,byte stores,
* and all four-register helper inputs preserve their original instructions.
* Per-arm owner/selector calls merge into original55F14 entry875; independent
* SP40 pointer producers remain in original caller registers without S5.
* The zero-argument matched369B8 helper ignores its caller's full owner/56
* values; these original caller producers remain as unused C89 call arguments.
* Owner4 is initialized on both final type-comparison paths. Empty metadata
* consumes complete initialized values/addresses or clobbers dead values
* before full producers; zero CPU words. No partialHI,fixedFP,undefined saved
* inputs,live alias overlap or compiler/filter/flag changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence: binary identity only
* after all gates. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned data/padding and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 e7ea5c3ee7302c2f1f5a55b77c023efe673f59a8a30ee97c0833dbaed4b12979 */
#define Level44_7EA54Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_7EA54DataPlaySoundView1() __asm__("PlaySound");
int Level44_7EA54TestSubdividedSegmentPathView1() __asm__("func_80013E38");
int Level44_7EA54QueryWorldHeightView1() __asm__("func_8001A358");
void Level44_7EA54RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level44_7EA54SetMobyAnimationView1() __asm__("func_80034F80");
int Level44_7EA54UpdateMobyMotionDescriptorView1() __asm__("func_80035194");
int Level44_7EA54TurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level44_7EA54TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level44_7EA54CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level44_7EA54UpdateMobyPathMotionView1() __asm__("func_80035A80");
int Level44_7EA54ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level44_7EA54TestPaddedRotatedBoxView1() __asm__("func_80036220");
int Level44_7EA54RandBetweenView1(int, int) __asm__("func_8003636C");
void Level44_7EA54EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level44_7EA54SpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
int Level44_7EA54InitializeMobyMotionStateWithDecelerationView1() __asm__("func_80038F14");
int Level44_7EA54MarkMobyCollectionBitView1() __asm__("func_8003BA00");
int Level44_7EA54PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level44_7EA54ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
void Level44_7EA54CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level44_7EA54AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
int Level44_7EA54AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level44_7EA54ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level44_7EA54AllocateVectorTrailRecordView1() __asm__("func_80050844");
int Level44_7EA54DeleteMobyView1() __asm__("func_80055B18");
int Level44_7EA54RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level44_7EA54ReadSelectedFrameScalarView1() __asm__("func_80055E84");
void Level44_7EA54InterpolateMobyVertexView1(void*, int, void*) __asm__("func_80055F14");
extern int Level44_7EA54Data658A0View1 __asm__("D_800658A0");
extern int Level44_7EA54Data65920View1 __asm__("D_80065920");
extern int Level44_7EA54Data66BC8View1 __asm__("D_80066BC8");
extern int Level44_7EA54Data6C550View1 __asm__("D_8006C550");
extern int Level44_7EA54Data6C5C8View1 __asm__("D_8006C5C8");
extern int Level44_7EA54Data6C654View1 __asm__("D_8006C654");
extern int Level44_7EA54Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level44_7EA54Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level44_7EA54Data6E020View1 __asm__("D_8006E020");
extern int Level44_7EA54Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level44_7EA54Data6E040View1 __asm__("D_8006E040");
extern int Level44_7EA54Data70328View1 __asm__("D_80070328");
extern int Level44_7EA54Data71908View1 __asm__("D_80071908");
extern short Level44_7EA54Data719DCView1 __asm__("D_800719DC");
extern void* (*Level44_7EA54DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
void func_level_44_8007EA54(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord19 __asm__("$19"), retainedIndexPositionOrStatus16 __asm__("$16"),
        retainedPlayerBaseOrSpawn18 __asm__("$18"), spawnedPrivateRecord20 __asm__("$20");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C;
    } originalFrame;
    int temporaryWord8;
    int temporaryWord13;
    int temporaryWord17;
    int temporaryWord4;
    int temporaryWord11;
    int temporaryWord19;
    int temporaryWord6;
    int temporaryWord1;
    int temporaryWord3;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord16;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord7;
    int temporaryWord12;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord18;
    ownerRecord17 = ownerParameter;
    MATCHING_KEEP(ownerRecord17);
    temporaryWord9 = Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48);
    privateRecord19 = Level44_7EA54Field(ownerRecord17, void**, 0);
    if ((temporaryWord9 != 0x20) && (temporaryWord9 != 0x22)) {
        Level44_7EA54RefreshMobySpatialGridAndBasisView1(ownerParameter, 7);
    }
    temporaryWord1 = Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48);
    if ((temporaryWord1 != 6) && (Level44_7EA54Field(ownerRecord17, int*, 0x18) & 0x90000)) {
        if (temporaryWord1 == 0x2E) {
            Level44_7EA54Field((int)&Level44_7EA54Data66BC8View1, signed char*, 0x12) = 3;
            Level44_7EA54Data719DCView1 = 1;
            Level44_7EA54DataPlaySoundView1(
                Level44_7EA54Field(Level44_7EA54Data6C654View1, unsigned char*, 0x23),
                ownerRecord17, 0xA1);
            temporaryWord5 = Level44_7EA54DataSpawnMobyView1(0xD3, ownerRecord17);
            if (temporaryWord5 != 0) {
                Level44_7EA54CopyVectorView1(temporaryWord5 + 0xC,
                                             (int)&Level44_7EA54Data70328View1);
                rawWord2 =
                    Level44_7EA54Field((int)&Level44_7EA54Data70328View1, unsigned char*, 14);
                rawWord2 *= 2;
                rawWord3 = Level44_7EA54Field((int)&Level44_7EA54Data65920View1, short*, rawWord2);
                rawWord2 = rawWord3 * 25;
                rawWord3 = Level44_7EA54Field(temporaryWord5, int*, 12);
                rawWord2 >>= 7;
                rawWord3 += rawWord2;
                Level44_7EA54Field(temporaryWord5, int*, 12) = rawWord3;
                rawWord2 =
                    Level44_7EA54Field((int)&Level44_7EA54Data70328View1, unsigned char*, 14);
                rawWord3 = Level44_7EA54Field(temporaryWord5, int*, 20);
                rawWord2 *= 2;
                argumentWord4 =
                    Level44_7EA54Field((int)&Level44_7EA54Data658A0View1, short*, rawWord2);
                rawWord3 += 500;
                Level44_7EA54Field(temporaryWord5, int*, 20) = rawWord3;
                rawWord3 = Level44_7EA54Field(temporaryWord5, int*, 16);
                rawWord2 = (argumentWord4 * 25) >> 7;
                rawWord3 += rawWord2;
                Level44_7EA54Field(temporaryWord5, int*, 16) = rawWord3;
            }
        }
        Level44_7EA54SpawnMobyFromValueSelectorView1(ownerRecord17, 1, 0, 0);
        Level44_7EA54InitializeMobyMotionStateWithDecelerationView1(ownerRecord17,
                                                                    privateRecord19 + 4, 2, 6);
    }
    temporaryWord10 = Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord10) {
        case 44:
            if (!(Level44_7EA54Data6C7B4View1 & 8)) {
                Level44_7EA54Field(ownerRecord17, signed char*, 0x57) = 0x38;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x54) = 0xFF;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4E) = 0x20;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x20U;
                Level44_7EA54Field(ownerRecord17, int*, 8) = 0;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x41) = 0;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4C) = 0;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4D) = 0;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49) = 5U;
                return;
            }
            goto callSharedOriginalFinalHelper;
        default:
            return;
        case 33:
            Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49) = 4U;
        case 30:
            if (!(Level44_7EA54Data6C7B4View1 & 8)) {
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4E) = 0x20;
                Level44_7EA54Field(ownerRecord17, int*, 8) = 0;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x41) = 0;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4C) = 0;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4D) = 0;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x20U;
                temporaryWord2 = Level44_7EA54Field(privateRecord19, void**, 0x1C);
                if (temporaryWord2 != 0) {
                    if (Level44_7EA54Field(temporaryWord2, short*, 0) == 1) {
                        Level44_7EA54Field(ownerRecord17, int*, 0x14) = (int)Level44_7EA54Field(
                            Level44_7EA54Field(temporaryWord2, void**, 0xC), int*, 8);
                        return;
                    }
                    Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49) = 3U;
                    return;
                }
            } else {
                goto callSharedOriginalFinalHelper;
            }
            break;
        case 31:
            if (!(Level44_7EA54Data6C7B4View1 & 8)) {
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4E) = 0x20;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x20U;
                Level44_7EA54Field(ownerRecord17, int*, 8) = 0;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49) = 3U;
                return;
            }
            goto callSharedOriginalFinalHelper;
        case 34:
            temporaryWord11 = Level44_7EA54Field(privateRecord19, int*, 0x40);
            temporaryWord19 = 0;
            if ((temporaryWord11 < 0) ||
                (temporaryWord12 = Level44_7EA54Data6C550View1 + (temporaryWord11 * 0x58),
                 temporaryWord3 = Level44_7EA54Field(temporaryWord12, unsigned char*, 0x48),
                 temporaryWord13 = Level44_7EA54Field(temporaryWord12, short*, 0x36),
                 ((temporaryWord3 & 0x80) != 0)) ||
                ((temporaryWord13 == 0x25D) && (temporaryWord3 == 5)) ||
                ((temporaryWord13 == 0x240) && (temporaryWord3 == 6))) {
                temporaryWord19 = 1;
            }
            if ((temporaryWord19 != 0) &&
                (Level44_7EA54CountTimerDownView1(privateRecord19, 2) != 0)) {
                rawWord3 = 1;
                MATCHING_KEEP_CLOBBER(rawWord3, "$2");
                rawWord2 = 32;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 76) = rawWord2;
                rawWord2 = 24;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 65) = rawWord3;
                Level44_7EA54Field(ownerRecord17, unsigned char*, 77) = rawWord3;
                Level44_7EA54Field(privateRecord19, unsigned short*, 0) = 0x18U;
                if (({
                        rawWord2 =
                            (unsigned int)(Level44_7EA54Field(ownerRecord17, unsigned char*, 73) -
                                           3) < 2;
                        argumentWord4 = (int)ownerRecord17;
                        rawWord2;
                    })) {
                    Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                    temporaryWord14 = Level44_7EA54Field(privateRecord19, void**, 0x1C);
                    if (temporaryWord14 != 0) {
                        argumentWord5 = 5;
                        if (Level44_7EA54Field(temporaryWord14, short*, 0) >= 2) {
                            rawWord3 = temporaryWord14;
                            Level44_7EA54Field(rawWord3, short*, 2) = 0;
                            rawWord2 = Level44_7EA54Field(privateRecord19, int*, 28);
                            rawWord3 = 1;
                            Level44_7EA54Field(rawWord2, short*, 10) = rawWord3;
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "memory");
                            rawWord2 = 22;
                            goto callSharedOriginalStateAnimation;
                        }
                    }
                    goto clearSharedOriginalOwnerState;
                }
                Level44_7EA54Field(ownerRecord17, int*, 0x14) =
                    (int)(Level44_7EA54Field(ownerRecord17, int*, 0x14) - 0xC00);
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 7);
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x24U;
                return;
            }
            break;
        case 36:
            Level44_7EA54Field(ownerRecord17, int*, 0x14) =
                (int)(Level44_7EA54Field(ownerRecord17, int*, 0x14) + 0x80);
            temporaryWord6 = Level44_7EA54Field(privateRecord19, unsigned short*, 0) - 1;
            Level44_7EA54Field(privateRecord19, unsigned short*, 0) = temporaryWord6;
            if ((temporaryWord6 << 0x10) <= 0) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                temporaryWord15 = Level44_7EA54Field(privateRecord19, void**, 0x1C);
                if (temporaryWord15) {
                    rawWord2 = Level44_7EA54Field(temporaryWord15, short*, 0);
                    argumentWord4 = (int)ownerRecord17;
                    if (rawWord2 >= 2) {
                        argumentWord5 = 5;
                        rawWord3 = temporaryWord15;
                        Level44_7EA54Field(rawWord3, short*, 2) = 0;
                        rawWord2 = Level44_7EA54Field(privateRecord19, int*, 28);
                        rawWord3 = 1;
                        Level44_7EA54Field(rawWord2, short*, 10) = rawWord3;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord3, "memory");
                        rawWord2 = 22;
                        goto callSharedOriginalStateAnimation;
                    }
                    MATCHING_OBSERVE_VOLATILE(argumentWord4);
                }
            }
            rawWord2 = Level44_7EA54Data6C770View1;
            argumentWord4 = (int)ownerRecord17;
            if (!rawWord2)
                return;
            MATCHING_OBSERVE_VOLATILE(argumentWord4);
            goto callSharedOriginalResetAnimation;
            break;
        case 28:
            if (Level44_7EA54Field(privateRecord19, void**, 0x1C) != 0) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                return;
            }
            Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x17U;
            return;
        case 26:
            if ((Level44_7EA54TestPaddedRotatedBoxView1((int)&Level44_7EA54Data70328View1,
                                                        privateRecord19 + 0x20, 0, 0x2800) != 0) ||
                (Level44_7EA54ApproximatePlanarDistanceView1(
                     ownerRecord17 + 0xC, (int)&Level44_7EA54Data70328View1) < 0x1800)) {
                Level44_7EA54Field(Level44_7EA54Field(privateRecord19, void**, 0x38), signed char*,
                                   0x48) = 1;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x41) = 1;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4C) = 0x2A;
                Level44_7EA54Field(ownerRecord17, signed char*, 0x4D) = 1;
                Level44_7EA54RefreshMobySpatialGridAndBasisView1(ownerRecord17, 7);
                temporaryWord7 = Level44_7EA54Field(privateRecord19, void**, 0x1C);
                argumentWord4 = (int)ownerRecord17;
                if (temporaryWord7 != 0) {
                    argumentWord5 = 7;
                    rawWord2 = temporaryWord7;
                    Level44_7EA54Field(rawWord2, short*, 2) = 0;
                    rawWord2 = Level44_7EA54Field(privateRecord19, int*, 28);
                    rawWord3 = 1;
                    Level44_7EA54Field(rawWord2, short*, 10) = rawWord3;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "memory");
                    rawWord2 = 24;
                    goto callSharedOriginalStateAnimation;
                }
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 7U;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 7);
                return;
            }
            break;
        case 23:
            rawWord2 = Level44_7EA54TestPaddedRotatedBoxView1((int)&Level44_7EA54Data70328View1,
                                                              privateRecord19 + 0x20, 0, 0x2800);
            goto testSharedOriginalResetResult;
        case 20:
            if (Level44_7EA54TestPaddedRotatedBoxView1((int)&Level44_7EA54Data70328View1,
                                                       privateRecord19 + 0x20, 0, 0x2800) != 0) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x15U;
                case 21:
                    argumentWord4 = (int)ownerRecord17;
                    argumentWord5 = 5;
                    rawWord2 = Level44_7EA54Field(privateRecord19, int*, 28);
                    Level44_7EA54Field(rawWord2, short*, 2) = 0;
                    rawWord3 = Level44_7EA54Field(privateRecord19, int*, 28);
                    rawWord2 = 1;
                    Level44_7EA54Field(rawWord3, short*, 10) = rawWord2;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord3, "memory");
                    rawWord2 = 22;
                    goto callSharedOriginalStateAnimation;
            }
            break;
        case 24:
            if (Level44_7EA54Data6C770View1 != 0) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x16U;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 5);
                return;
            }
            break;
        case 46:
            Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 5);
            if (Level44_7EA54UpdateMobyPathMotionView1(
                    ownerRecord17, Level44_7EA54Field(privateRecord19, void**, 0x1C), 0x78, 0x64, 0,
                    4, 0x20, 4) &
                2) {
                goto callSharedOriginalFinalHelper;
            }
            break;
        case 22:
            retainedIndexPositionOrStatus16 =
                Level44_7EA54Field(Level44_7EA54Field(privateRecord19, void**, 0x1C), short*, 2);
            __asm__(""
                    : "=r"(retainedIndexPositionOrStatus16)
                    : "0"(retainedIndexPositionOrStatus16)
                    : "$7", "memory");
            if (Level44_7EA54UpdateMobyPathMotionView1(
                    ownerRecord17, Level44_7EA54Field(privateRecord19, void**, 0x1C), 0x78, 0x64, 0,
                    4, 0x20, 4) &
                2) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 0);
            }
            argumentWord4 = Level44_7EA54Field(privateRecord19, int*, 28);
            rawWord2 = Level44_7EA54Field(argumentWord4, short*, 2);
            if (rawWord2 != retainedIndexPositionOrStatus16) {
                rawWord2 = retainedIndexPositionOrStatus16 * 16;
                rawWord3 = Level44_7EA54Field(argumentWord4, int*, 12);
                rawWord2 += rawWord3;
                rawWord3 = Level44_7EA54Field(rawWord2, int*, 12);
                rawWord2 = 1;
                retainedIndexPositionOrStatus16 = (int)ownerRecord17 + 12;
                if (rawWord3 == rawWord2) {
                    Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 9U;
                    Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 9);
                    return;
                }
                goto checkOriginalPlayerDistance;
            }
            retainedIndexPositionOrStatus16 = ownerRecord17 + 0xC;
        checkOriginalPlayerDistance:
            argumentWord4 = retainedIndexPositionOrStatus16;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$18", "memory");
            retainedPlayerBaseOrSpawn18 = (int)&Level44_7EA54Data70328View1;
            if (Level44_7EA54ApproximatePlanarDistanceView1(argumentWord4,
                                                            retainedPlayerBaseOrSpawn18) < 0x1800) {
                temporaryWord17 = retainedIndexPositionOrStatus16;
                if (Level44_7EA54AbsoluteByteAngleDeltaView1(
                        (int)(Level44_7EA54Data6E040View1 << 0x10) >> 0x14,
                        Level44_7EA54PlanarHeadingLookupView1(
                            Level44_7EA54Field(ownerRecord17, int*, 0xC) -
                                Level44_7EA54Data6E020View1,
                            Level44_7EA54Field(ownerRecord17, int*, 0x10) -
                                Level44_7EA54Data6E024View1,
                            0)) < 0x18) {
                    argumentWord4 = retainedIndexPositionOrStatus16;
                    argumentWord5 = retainedPlayerBaseOrSpawn18;
                    rawWord2 = Level44_7EA54Field(ownerRecord17, int*, 20);
                    argumentWord6 = 0;
                    rawWord2 += 500;
                    Level44_7EA54Field(ownerRecord17, int*, 20) = rawWord2;
                    goto callSharedOriginalContact;
                }
            }
            break;
        case 9:
            argumentWord6 = 0;
            rawWord3 = Level44_7EA54Field(privateRecord19, int*, 28);
            argumentWord4 = Level44_7EA54Field(ownerRecord17, int*, 12);
            rawWord2 = Level44_7EA54Field(rawWord3, short*, 2);
            rawWord3 = Level44_7EA54Field(rawWord3, int*, 12);
            argumentWord5 = Level44_7EA54Field(ownerRecord17, int*, 16);
            rawWord2 *= 16;
            rawWord2 += rawWord3;
            rawWord3 = Level44_7EA54Field(rawWord2, int*, 0);
            rawWord2 = Level44_7EA54Field(rawWord2, int*, 4);
            argumentWord4 = rawWord3 - argumentWord4;
            argumentWord5 = rawWord2 - argumentWord5;
            rawWord2 =
                Level44_7EA54PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            Level44_7EA54TurnMobyTowardHeadingView1(ownerRecord17, rawWord2, 4, 2, 1, 0);
            if (Level44_7EA54Data6C770View1 != 0) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0xAU;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 0xA);
                Level44_7EA54Field(privateRecord19, short*, 0x3E) = 0x64;
                return;
            }
            break;
        case 10:
            Level44_7EA54CopyVectorView1(&originalFrame.sp20, ownerRecord17 + 0xC);
            originalFrame.sp28 += 0x200;
            Level44_7EA54Field(ownerRecord17, int*, 0x14) =
                (int)(Level44_7EA54Field(ownerRecord17, int*, 0x14) +
                      Level44_7EA54Field(privateRecord19, short*, 0x3E));
            temporaryWord8 =
                (unsigned short)Level44_7EA54Field(privateRecord19, short*, 0x3E) - 0x10;
            Level44_7EA54Field(privateRecord19, short*, 0x3E) = temporaryWord8;
            temporaryWord8 = (short)temporaryWord8;
            if (temporaryWord8 < -0x190) {
                Level44_7EA54Field(privateRecord19, short*, 0x3E) = -0x190;
            }
            Level44_7EA54ResolveMobyYawStepView1(ownerRecord17, 0x64, 0, 0, 0);
            if ((Level44_7EA54Field(privateRecord19, short*, 0x3E) < 0) &&
                (Level44_7EA54QueryWorldHeightView1(&originalFrame.sp20, 0x1000) != 0) &&
                ((Level44_7EA54Field(ownerRecord17, int*, 0x14) - Level44_7EA54Data71908View1) <
                 0x100)) {
                argumentWord4 = (int)ownerRecord17;
                argumentWord5 = 11;
                rawWord2 = 11;
                Level44_7EA54Field(argumentWord4, int*, 20) = Level44_7EA54Data71908View1;
                goto callSharedOriginalStateAnimation;
            }
            break;
        case 11:
            if (Level44_7EA54Data6C770View1 != 0) {
                if (Level44_7EA54AbsoluteByteAngleDeltaView1(
                        (int)(Level44_7EA54Data6E040View1 << 0x10) >> 0x14,
                        Level44_7EA54PlanarHeadingLookupView1(
                            Level44_7EA54Field(ownerRecord17, int*, 0xC) -
                                Level44_7EA54Data6E020View1,
                            Level44_7EA54Field(ownerRecord17, int*, 0x10) -
                                Level44_7EA54Data6E024View1,
                            0)) < 0x18) {
                    Level44_7EA54Field(ownerRecord17, int*, 0x14) =
                        (int)(Level44_7EA54Field(ownerRecord17, int*, 0x14) + 0x1F4);
                    if (Level44_7EA54TestSubdividedSegmentPathView1(
                            ownerRecord17 + 0xC, (int)&Level44_7EA54Data70328View1, 0) != 0) {
                        Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 4U;
                        Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 4);
                        Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x26U;
                        Level44_7EA54Field(ownerRecord17, unsigned char*, 0x40) = 0xF0;
                        Level44_7EA54Field(privateRecord19, short*, 2) = 0x14;
                    }
                    goto restoreOriginalHeight;
                }
                goto clearSharedOriginalOwnerState;
            }
            break;
        case 38:
            Level44_7EA54TurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            if (Level44_7EA54Data6C770View1 != 0) {
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 0);
            }
            if (Level44_7EA54CountTimerDownView1(privateRecord19 + 2, 2) != 0) {
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 1);
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x28U;
                return;
            }
            break;
        case 40:
            if (Level44_7EA54Field(ownerRecord17, unsigned char*, 0x3C) == 1) {
                Level44_7EA54SetMobyAnimationView1(ownerRecord17, 8);
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0x29U;
                return;
            }
            break;
        case 3:
            if (Level44_7EA54Data6C770View1 != 0) {
                rawWord2 = 4;
                MATCHING_KEEP(rawWord2);
                goto writeSharedOriginalResetFields;
            }
            break;
        case 7:
        case 8:
            rawWord2 = Level44_7EA54Data6C770View1;
        testSharedOriginalResetResult:
            if (!rawWord2)
                return;
        clearSharedOriginalOwnerState:
            Level44_7EA54Field(ownerRecord17, unsigned char*, 72) = 0;
            argumentWord4 = (int)ownerRecord17;
        callSharedOriginalResetAnimation:
            Level44_7EA54RequestMobyAnimationView1(argumentWord4, 0);
            return;
        case 0:
        case 4:
            retainedPlayerBaseOrSpawn18 = (int)&Level44_7EA54Data70328View1 + 0x24C;
            if (Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 0x24C) == 4) {
                retainedIndexPositionOrStatus16 = 0;
            } else {
                Level44_7EA54CopyVectorView1(&originalFrame.sp30,
                                             retainedPlayerBaseOrSpawn18 - 0x1B4);
                temporaryWord4 = originalFrame.sp34;
                originalFrame.sp30 *= 0x23;
                originalFrame.sp34 = temporaryWord4 * 0x23;
                originalFrame.sp38 *= 0x23;
                Level44_7EA54ShiftVectorRightTowardZeroView1(&originalFrame.sp30, 6);
                Level44_7EA54AddVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                            retainedPlayerBaseOrSpawn18 - 0x24C);
                retainedIndexPositionOrStatus16 = Level44_7EA54ApproximatePlanarDistanceView1(
                    ownerRecord17 + 0xC, &originalFrame.sp30);
            }
            if (retainedIndexPositionOrStatus16 < 0x4650) {
                Level44_7EA54TurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            }
            if ((Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) == 0) &&
                (Level44_7EA54CountTimerDownView1(privateRecord19, 2) != 0)) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 4U;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 4);
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x40) = 0xF0;
            }
            if (Level44_7EA54Data6C770View1 != 0) {
                temporaryWord18 = privateRecord19 + 2;
                if (Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) == 4) {
                    Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0U;
                    Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 0);
                    Level44_7EA54Field(ownerRecord17, unsigned char*, 0x40) = 0xF0;
                    Level44_7EA54Field(privateRecord19, unsigned short*, 0) =
                        (unsigned short)(Level44_7EA54RandBetweenView1(0, 0x96) + 0xC8);
                    goto reloadOriginalCountdownPointer;
                }
            } else {
            reloadOriginalCountdownPointer:
                temporaryWord18 = privateRecord19 + 2;
            }
            if ((Level44_7EA54CountTimerDownView1(temporaryWord18, 2) != 0) &&
                (retainedIndexPositionOrStatus16 < 0x4000) &&
                (({
                     retainedPlayerBaseOrSpawn18 = (int)&Level44_7EA54Data70328View1;
                     Level44_7EA54AbsoluteByteAngleDeltaView1(
                         (int)Level44_7EA54Field(ownerRecord17, unsigned char*, 70),
                         Level44_7EA54PlanarHeadingLookupView1(
                             Level44_7EA54Field(retainedPlayerBaseOrSpawn18, int*, 0) -
                                 Level44_7EA54Field(ownerRecord17, int*, 12),
                             Level44_7EA54Field(retainedPlayerBaseOrSpawn18, int*, 4) -
                                 Level44_7EA54Field(ownerRecord17, int*, 16),
                             0));
                 }) < 10) &&
                (Level44_7EA54AbsoluteByteAngleDeltaView1(
                     (int)(Level44_7EA54Data6E040View1 << 0x10) >> 0x14,
                     Level44_7EA54PlanarHeadingLookupView1(
                         Level44_7EA54Field(ownerRecord17, int*, 0xC) - Level44_7EA54Data6E020View1,
                         Level44_7EA54Field(ownerRecord17, int*, 0x10) -
                             Level44_7EA54Data6E024View1,
                         0)) < 0x18)) {
                Level44_7EA54Field(ownerRecord17, int*, 0x14) =
                    (int)(Level44_7EA54Field(ownerRecord17, int*, 0x14) + 0x1F4);
                if (retainedIndexPositionOrStatus16 == 0)
                    goto writeSharedOriginalStateOne;
                argumentWord4 = (int)ownerRecord17 + 12;
                argumentWord5 = retainedPlayerBaseOrSpawn18;
                argumentWord6 = 0;
            callSharedOriginalContact:
                rawWord2 = Level44_7EA54TestSubdividedSegmentPathView1(argumentWord4, argumentWord5,
                                                                       argumentWord6);
                if (!rawWord2)
                    goto restoreOriginalHeight;
            writeSharedOriginalStateOne:
                Level44_7EA54Field(ownerRecord17, unsigned char*, 72) = 1;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 1);
            restoreOriginalHeight:
                Level44_7EA54Field(ownerRecord17, int*, 20) -= 500;
                return;
            }
            break;
        case 1:
            Level44_7EA54TurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            if (Level44_7EA54Data6C770View1 != 0) {
                if (Level44_7EA54Data6C5C8View1 != 3) {
                    if (Level44_7EA54ApproximatePlanarDistanceView1(
                            ownerRecord17 + 0xC, (int)&Level44_7EA54Data70328View1) < 0x4000) {
                        if (Level44_7EA54AbsoluteByteAngleDeltaView1(
                                (int)(Level44_7EA54Data6E040View1 << 0x10) >> 0x14,
                                Level44_7EA54PlanarHeadingLookupView1(
                                    Level44_7EA54Field(ownerRecord17, int*, 0xC) -
                                        Level44_7EA54Data6E020View1,
                                    Level44_7EA54Field(ownerRecord17, int*, 0x10) -
                                        Level44_7EA54Data6E024View1,
                                    0)) < 0x18) {
                            case 41:
                                goto writeOriginalStateTwo;
                        }
                        goto produceOriginalResetFour;
                    }
                    goto produceOriginalResetFour;
                }
            writeOriginalStateTwo:
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 2U;
                Level44_7EA54RequestMobyAnimationView1(ownerRecord17, 2);
                return;
            }
            return;
        produceOriginalResetFour:
            rawWord2 = 4;
        writeSharedOriginalResetFields:
            Level44_7EA54Data6C770View1 = 0;
            Level44_7EA54Field(ownerRecord17, unsigned char*, 60) = rawWord2;
            Level44_7EA54Field(ownerRecord17, signed char*, 0x3D) = 0;
            Level44_7EA54Field(ownerRecord17, signed char*, 0x3E) = 0;
            Level44_7EA54Field(ownerRecord17, signed char*, 0x3F) = 0;
            Level44_7EA54Field(ownerRecord17, unsigned char*, 0x48) = 0U;
            Level44_7EA54Field(ownerRecord17, unsigned char*, 0x40) = 0x80;
            if ((short)Level44_7EA54Field(privateRecord19, unsigned short*, 0) < 0x14) {
                Level44_7EA54Field(privateRecord19, unsigned short*, 0) = 0x14U;
                return;
            }
            break;
        case 2:
            rawWord2 = Level44_7EA54ReadSelectedFrameScalarView1(ownerRecord17);
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 4;
            argumentWord6 = 2;
            argumentWord7 = 1;
            __asm__(""
                    : "=r"(argumentWord7)
                    : "0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5),
                      "r"(argumentWord6), "r"(rawWord2));
            retainedIndexPositionOrStatus16 = rawWord2;
            Level44_7EA54TurnMobyTowardPlayerView1(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7);
            temporaryWord16 = Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49);
            if (temporaryWord16 == 0) {
                if ((unsigned int)(retainedIndexPositionOrStatus16 - 6) >= 4U) {
                    goto checkOriginalStatusRange;
                }
                goto spawnOriginalClass608;
            }
        checkOriginalStatusRange:
            if ((temporaryWord16 == 1) && (({
                    rawWord2 = (unsigned int)(retainedIndexPositionOrStatus16 - 8) < 4;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(retainedIndexPositionOrStatus16));
                    rawWord2;
                }))) {
            spawnOriginalClass608:
                retainedPlayerBaseOrSpawn18 = Level44_7EA54DataSpawnMobyView1(0x260, ownerRecord17);
                MATCHING_KEEP(retainedPlayerBaseOrSpawn18);
                if (retainedPlayerBaseOrSpawn18 != 0) {
                    spawnedPrivateRecord20 =
                        Level44_7EA54Field(retainedPlayerBaseOrSpawn18, void**, 0);
                    Level44_7EA54RefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
                    if (Level44_7EA54Field(ownerRecord17, unsigned char*, 73) == 0) {
                        Level44_7EA54Field(ownerRecord17, unsigned char*, 73) = 1;
                        argumentWord4 = (int)ownerRecord17;
                        Level44_7EA54InterpolateMobyVertexView1(argumentWord4, 6,
                                                                &originalFrame.sp40);
                    } else {
                        Level44_7EA54Field(ownerRecord17, unsigned char*, 73) = 2;
                        argumentWord4 = (int)ownerRecord17;
                        Level44_7EA54InterpolateMobyVertexView1(argumentWord4, 7,
                                                                &originalFrame.sp40);
                    }
                    retainedIndexPositionOrStatus16 = (int)retainedPlayerBaseOrSpawn18 + 12;
                    argumentWord4 = retainedIndexPositionOrStatus16;
                    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4) : "$5", "memory");
                    argumentWord5 = (int)&originalFrame.sp40;
                    __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5) : "$2", "memory");
                    rawWord2 = 1;
                    Level44_7EA54Field(retainedPlayerBaseOrSpawn18, unsigned char*, 72) = rawWord2;
                    rawWord2 = 32;
                    Level44_7EA54Field(retainedPlayerBaseOrSpawn18, unsigned char*, 79) = rawWord2;
                    Level44_7EA54CopyVectorView1(argumentWord4, argumentWord5);
                    Level44_7EA54Field(spawnedPrivateRecord20, int*, 0) = 0x64;
                    Level44_7EA54Field(spawnedPrivateRecord20, int*, 4) =
                        Level44_7EA54AllocateVectorTrailRecordView1(retainedIndexPositionOrStatus16,
                                                                    2, 0xA, 0xFF);
                    Level44_7EA54Field(retainedPlayerBaseOrSpawn18, unsigned char*, 0x46) =
                        (unsigned char)Level44_7EA54Field(ownerRecord17, unsigned char*, 0x46);
                    Level44_7EA54Field(retainedPlayerBaseOrSpawn18, signed char*, 0x45) =
                        Level44_7EA54PlanarHeadingLookupView1(
                            Level44_7EA54ApproximatePlanarDistanceView1(
                                retainedIndexPositionOrStatus16, (int)&Level44_7EA54Data70328View1),
                            Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 8) -
                                Level44_7EA54Field(retainedPlayerBaseOrSpawn18, int*, 0x14),
                            0);
                }
            }
            if ((Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 0x50) == 7) &&
                (Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 0x24C) != 4)) {
                Level44_7EA54Field(privateRecord19, short*, 0x3C) = 1;
            }
            if (Level44_7EA54Data6C770View1 != 0) {
                Level44_7EA54Field(ownerRecord17, unsigned char*, 0x49) = 0U;
                if (Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 0x24C) == 4) {
                    retainedIndexPositionOrStatus16 = 0;
                } else {
                    retainedIndexPositionOrStatus16 = Level44_7EA54ApproximatePlanarDistanceView1(
                        ownerRecord17 + 0xC, ((int)&Level44_7EA54Data70328View1 + 0x24C) - 0x24C);
                }
                Level44_7EA54CopyVectorView1(&originalFrame.sp50, ownerRecord17 + 0xC);
                originalFrame.sp58 += 0x1F4;
                if ((Level44_7EA54Field(privateRecord19, short*, 0x3C) != 0) ||
                    (retainedIndexPositionOrStatus16 >= 0x4001) ||
                    (Level44_7EA54AbsoluteByteAngleDeltaView1(
                         (int)Level44_7EA54Field(ownerRecord17, unsigned char*, 0x46),
                         Level44_7EA54PlanarHeadingLookupView1(
                             Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 0) -
                                 Level44_7EA54Field(ownerRecord17, int*, 0xC),
                             Level44_7EA54Field((int)&Level44_7EA54Data70328View1, int*, 4) -
                                 Level44_7EA54Field(ownerRecord17, int*, 0x10),
                             0)) >= 0xB) ||
                    ((retainedIndexPositionOrStatus16 > 0) &&
                     (Level44_7EA54TestSubdividedSegmentPathView1(
                          &originalFrame.sp50, (int)&Level44_7EA54Data70328View1, 0) == 0))) {
                    argumentWord4 = (int)ownerRecord17;
                    argumentWord5 = 3;
                    rawWord2 = 3;
                    Level44_7EA54Field(privateRecord19, short*, 60) = 0;
                callSharedOriginalStateAnimation:
                    Level44_7EA54Field(argumentWord4, unsigned char*, 72) = rawWord2;
                    Level44_7EA54RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    return;
                }
            }
            break;
        case 6:
            if (Level44_7EA54UpdateMobyMotionDescriptorView1(ownerRecord17, privateRecord19 + 4) ==
                0x100) {
                if (Level44_7EA54Data6C5C8View1 == 3) {
                    Level44_7EA54RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                } else {
                    Level44_7EA54RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                    Level44_7EA54MarkMobyCollectionBitView1(ownerRecord17);
                }
                Level44_7EA54EmitMobyVertexParticlesView1(ownerRecord17, 56);
            callSharedOriginalFinalHelper:
                Level44_7EA54DeleteMobyView1(ownerRecord17);
                return;
            }
            break;
    }
}
#undef Level44_7EA54Field

extern int D_8006C770;
void func_level_44_8007FA30(Moby* moby) {
    EnemyTag* tag = moby->mobyTag;
    if (moby->state != 5 && moby->damageFlags) {
        func_80038BF8(moby, tag, 1, 5);
        tag->unkF = 0x10;
        *(short*)((char*)tag + 0xA) = 0x258;
        tag->unk4 *= 2;
    }
    switch (moby->state) {
        case 0:
        case 2:
            break;
        case 1:
            if (D_8006C770) {
                moby->state = 2;
                func_80034F40(moby, 2);
            }
            break;
        case 3:
        case 4:
            if (D_8006C770) {
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        case 5:
            if (func_80035194(moby, tag) == 0x100) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 0x20);
                func_80055B18(moby);
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007FB5C.
* Assembly SHA256 cfab7b2d35ba98925234a4a0513392b92bb6094fcfed663de530faba90119029.
* AI generated; not human reviewed. All408 original instructions,23
* selectors bias0 and every actual branch/call/internal target are required.
* Frame68 retains SP18..47 and all original S0..S5/RA saves/restores.
* States0/20/22/1/2 retain physical order. The final state20 store is shared
* at its original tail. Original indirect-spawn3, S4 result/S1 scratch,
* signed trig/counter widths and tag-byte load priorities remain exact.
* Empty initialized dependencies and dead-before-producer clobbers emit no
* CPU instructions. No partial HI, FP shortcut or opcode assembly is used.
* Raw field units/fixed point, full helper contracts and caller cadence
* remain unresolved. Cadence here is per invocation. Binary identity does
* not establish synchronized retail runtime or complete game behavior.
* Falsification: every native/linked word and actual target, all selectors,
* full EXE and every overlay retail hash must remain identical. */
#define Actor44Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor44TestSubdividedSegmentPathView1() __asm__("func_80013E38");
unsigned char Actor44RequestMobyAnimationView1() __asm__("func_80034F40");
unsigned char Actor44SetMobyAnimationView1() __asm__("func_80034F80");
unsigned char Actor44TurnMobyTowardPlayerView1() __asm__("func_8003573C");
unsigned char Actor44EmitMobyVertexParticlesView1() __asm__("func_800369B8");
unsigned char Actor44SpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
unsigned char Actor44MarkMobyCollectionBitView1() __asm__("func_8003BA00");
void* Actor44PlayMobySoundEventView1() __asm__("func_8003BABC");
unsigned char Actor44TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Actor44SoundHandleMatchesOwnerInStates1Or2View1() __asm__("func_8003BFC0");
int Actor44PlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor44ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
unsigned char Actor44CopyVectorView1() __asm__("func_8004F178");
unsigned char Actor44AddVectorView1() __asm__("func_8004F194");
int Actor44AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor44ApproximatePlanarDistanceView1() __asm__("func_8004F334");
unsigned char Actor44DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor44RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
unsigned char Actor44InterpolateMobyVertexView1() __asm__("func_80055F14");
extern unsigned char Actor44Data658A0View1 __asm__("D_800658A0");
extern int Actor44Data6C770View1 __asm__("D_8006C770");
extern int Actor44Data6E020View1 __asm__("D_8006E020");
extern int Actor44Data6E024View1 __asm__("D_8006E024");
extern unsigned short Actor44Data6E040View1 __asm__("D_8006E040");
extern unsigned char Actor44Data70328View1 __asm__("D_80070328");
extern int (*Actor44DataSpawnFragmentsView1)() __asm__("SpawnFragments");
extern void* (*Actor44DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor44DataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_44_8007FB5C(void* input) {
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register void* (*indirectSpawnCall3)() __asm__("$3");
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register void* argumentPointer4 __asm__("$4");
    register int* scratchVector17 __asm__("$17");
    register void* ownerRecord19 __asm__("$19");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    } originalFrame;
    int temporaryWord7;
    int temporaryWord8;
    register int* vectorPointer16 __asm__("$16");
    register int* spawnedPrivate18 __asm__("$18");
    register int* playerBase20 __asm__("$20");
    register int temporaryWord2 __asm__("$16");
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord6;
    register void* firstPlayerVector17 __asm__("$17");
    register void* secondPlayerVector17 __asm__("$17");
    register void* ownerPosition18 __asm__("$18");
    register void* privateRecord21 __asm__("$21");
    void* temporaryPointer1;
    register void* temporaryWord5 __asm__("$20");
    ownerRecord19 = input;
    privateRecord21 = Actor44Field(ownerRecord19, void**, 0);
    if (Actor44Field(ownerRecord19, int*, 0x18) & 0x8A0000) {
        if (Actor44SoundHandleMatchesOwnerInStates1Or2View1(
                ownerRecord19, Actor44Field(privateRecord21, void**, 0x10)) != 0) {
            Actor44TransitionSoundHandleTo3Or5View1(Actor44Field(privateRecord21, void**, 0x10));
        }
        Actor44Field(privateRecord21, void**, 0x10) = (void*)-1;
        Actor44PlayMobySoundEventView1(ownerRecord19, 2, 0);
        Actor44SpawnMobyFromValueSelectorView1(ownerRecord19, 0, 0, 0);
        Actor44DataSpawnFragmentsView1(5, 0x113, ownerRecord19,
                                       Actor44Field(privateRecord21, int*, 0xC), 0, 0x100);
        Actor44DataSpawnParticleView1(0x10, 0x46, ownerRecord19 + 0xC, 0x20);
        Actor44Field(Actor44Field(privateRecord21, void**, 8), int*, 0x18) = 0x20000;
        Actor44RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
        Actor44MarkMobyCollectionBitView1(ownerRecord19);
        Actor44EmitMobyVertexParticlesView1(ownerRecord19, 0x20);
        Actor44DeleteMobyView1(ownerRecord19);
        return;
    }
    temporaryWord6 = Actor44Field(ownerRecord19, unsigned char*, 0x48);
    switch (temporaryWord6) {
        case 0:
            argumentWord4 = 579;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = Actor44Field(ownerRecord19, unsigned char*, 0x46);
            indirectSpawnCall3 = Actor44DataSpawnMobyView1;
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = (int)ownerRecord19;
            __asm__ __volatile__(""
                                 : "=r"(indirectSpawnCall3), "=r"(argumentWord5)
                                 : "0"(indirectSpawnCall3), "1"(argumentWord5), "r"(rawWord2)
                                 : "memory");
            Actor44Field(privateRecord21, int*, 4) = rawWord2;
            temporaryPointer1 = indirectSpawnCall3(argumentWord4, argumentWord5);
            Actor44Field(privateRecord21, void**, 8) = temporaryPointer1;
            if (temporaryPointer1 != 0) {
                Actor44Field(temporaryPointer1, unsigned char*, 0x46) =
                    (unsigned char)Actor44Field(ownerRecord19, unsigned char*, 0x46);
                Actor44Field(temporaryPointer1, unsigned char*, 0x4C) =
                    (unsigned char)Actor44Field(ownerRecord19, unsigned char*, 0x4C);
                Actor44Field(temporaryPointer1, unsigned char*, 0x4A) =
                    (unsigned char)Actor44Field(ownerRecord19, unsigned char*, 0x4A);
                goto setState20;
            }
        default:
            return;
        case 20:
            argumentPointer4 = &originalFrame.sp18;
            MATCHING_KEEP(argumentPointer4);
            firstPlayerVector17 = &Actor44Data70328View1 + 0x98;
            MATCHING_KEEP(firstPlayerVector17);
            Actor44CopyVectorView1(argumentPointer4, firstPlayerVector17);
            originalFrame.sp18 *= 0x1E;
            originalFrame.sp1C *= 0x1E;
            originalFrame.sp20 *= 0x1E;
            Actor44ShiftVectorRightTowardZeroView1(&originalFrame.sp18, 6);
            argumentPointer4 = &originalFrame.sp18;
            argumentWord5 = (int)argumentPointer4;
            MATCHING_KEEP2(argumentPointer4, argumentWord5);
            playerBase20 = firstPlayerVector17 - 0x98;
            Actor44AddVectorView1(argumentPointer4, argumentWord5, playerBase20);
            ownerPosition18 = ownerRecord19 + 0xC;
            temporaryWord2 =
                Actor44ApproximatePlanarDistanceView1(ownerPosition18, &originalFrame.sp18);
            if (temporaryWord2 < 0x4000) {
                Actor44TurnMobyTowardPlayerView1(ownerRecord19, 4, 2, 1);
                Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x46) =
                    (unsigned char)Actor44Field(ownerRecord19, unsigned char*, 0x46);
            }
            rawWord2 = temporaryWord2 < 0x36B0;
            MATCHING_KEEP(rawWord2);
            if (rawWord2 &&
                (Actor44AbsoluteByteAngleDeltaView1(
                     (int)(Actor44Data6E040View1 << 0x10) >> 0x14,
                     Actor44PlanarHeadingLookupView1(
                         Actor44Field(ownerRecord19, int*, 0xC) - Actor44Data6E020View1,
                         Actor44Field(ownerRecord19, int*, 0x10) - Actor44Data6E024View1, 0)) <
                 0x18) &&
                (Actor44AbsoluteByteAngleDeltaView1(
                     (int)Actor44Field(ownerRecord19, unsigned char*, 0x46),
                     Actor44PlanarHeadingLookupView1(
                         Actor44Field(firstPlayerVector17, int*, -0x98) -
                             Actor44Field(ownerRecord19, int*, 0xC),
                         Actor44Field(&Actor44Data70328View1, int*, 4) -
                             Actor44Field(ownerRecord19, int*, 0x10),
                         0)) < 0x10)) {
                Actor44Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor44Field(ownerRecord19, int*, 0x14) + 0x320);
                if (Actor44TestSubdividedSegmentPathView1(ownerPosition18, playerBase20, 0) != 0) {
                    Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x48) =
                        1U;
                    Actor44RequestMobyAnimationView1(Actor44Field(privateRecord21, void**, 8), 1);
                    Actor44Field(ownerRecord19, unsigned char*, 0x48) = 0x16U;
                }
                Actor44Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor44Field(ownerRecord19, int*, 0x14) - 0x320);
                return;
            }
            break;
        case 22:
            Actor44TurnMobyTowardPlayerView1(ownerRecord19, 4, 2, 1);
            Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x46) =
                (unsigned char)Actor44Field(ownerRecord19, unsigned char*, 0x46);
            if (Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x48) == 2) {
                Actor44SetMobyAnimationView1(ownerRecord19, 1);
                Actor44Field(ownerRecord19, unsigned char*, 0x48) = 1U;
                Actor44Field(privateRecord21, int*, 4) =
                    (int)Actor44Field(ownerRecord19, unsigned char*, 0x46);
                return;
            }
            break;
        case 1:
            if (Actor44SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord19, Actor44Field(privateRecord21, void**, 0x10)) == 0) {
                Actor44Field(privateRecord21, void**, 0x10) =
                    Actor44PlayMobySoundEventView1(ownerRecord19, 0, 4);
            }
            temporaryWord3 = Actor44Field(privateRecord21, unsigned short*, 0) + 3;
            Actor44Field(privateRecord21, unsigned short*, 0) = temporaryWord3;
            if ((short)temporaryWord3 >= 0x100) {
                if (Actor44SoundHandleMatchesOwnerInStates1Or2View1(
                        ownerRecord19, Actor44Field(privateRecord21, void**, 0x10)) != 0) {
                    Actor44TransitionSoundHandleTo3Or5View1(
                        Actor44Field(privateRecord21, void**, 0x10));
                }
                temporaryWord7 = (short)Actor44Field(privateRecord21, unsigned short*, 0);
                Actor44Field(privateRecord21, void**, 0x10) = (void*)-1;
                temporaryWord8 = temporaryWord7;
                if (temporaryWord7 < 0) {
                    temporaryWord8 = temporaryWord7 + 0xFF;
                }
                Actor44Field(privateRecord21, unsigned short*, 0) =
                    (unsigned short)(temporaryWord7 - ((temporaryWord8 >> 8) << 8));
                Actor44Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                Actor44RequestMobyAnimationView1(ownerRecord19, 2);
                Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x48) = 4U;
                Actor44RequestMobyAnimationView1(Actor44Field(privateRecord21, void**, 8), 4);
                Actor44Field(privateRecord21, unsigned short*, 2) = 0U;
                Actor44PlayMobySoundEventView1(ownerRecord19, 1, 0);
                return;
            }
            rawWord2 = ((short)temporaryWord3) * 2;
            __asm__ __volatile__("" ::: "$16", "memory");
            vectorPointer16 = &originalFrame.sp28;
            argumentPointer4 = vectorPointer16;
            MATCHING_KEEP(argumentPointer4);
            secondPlayerVector17 = &Actor44Data70328View1 + 0x98;
            temporaryWord4 = (Actor44Field(&Actor44Data658A0View1, short*, rawWord2) >> 7) +
                             Actor44Field(privateRecord21, int*, 4);
            Actor44Field(ownerRecord19, unsigned char*, 0x46) = temporaryWord4;
            Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x46) =
                temporaryWord4;
            Actor44CopyVectorView1(argumentPointer4, secondPlayerVector17);
            originalFrame.sp28 *= 0x1E;
            originalFrame.sp2C *= 0x1E;
            originalFrame.sp30 *= 0x1E;
            Actor44ShiftVectorRightTowardZeroView1(&originalFrame.sp28, 6);
            Actor44AddVectorView1(&originalFrame.sp28, &originalFrame.sp28,
                                  secondPlayerVector17 - 0x98);
            if (Actor44ApproximatePlanarDistanceView1(ownerRecord19 + 0xC, &originalFrame.sp28) >=
                0x36B1) {
                if (Actor44SoundHandleMatchesOwnerInStates1Or2View1(
                        ownerRecord19, Actor44Field(privateRecord21, void**, 0x10)) != 0) {
                    Actor44TransitionSoundHandleTo3Or5View1(
                        Actor44Field(privateRecord21, void**, 0x10));
                }
                Actor44Field(privateRecord21, void**, 0x10) = (void*)-1;
                Actor44RequestMobyAnimationView1(ownerRecord19, 0);
                Actor44Field(ownerRecord19, unsigned char*, 0x48) = 0x14U;
                Actor44RequestMobyAnimationView1(Actor44Field(privateRecord21, void**, 8), 3);
                Actor44Field(Actor44Field(privateRecord21, void**, 8), unsigned char*, 0x48) = 3U;
                Actor44Field(privateRecord21, unsigned short*, 2) = 0U;
                return;
            }
            if (!(Actor44Field(privateRecord21, unsigned short*, 2) & 1)) {
                temporaryWord5 = Actor44DataSpawnMobyView1(0x260, ownerRecord19);
                MATCHING_KEEP(temporaryWord5);
                if (temporaryWord5 != 0) {
                    spawnedPrivate18 = Actor44Field(temporaryWord5, int**, 0);
                    Actor44RefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                    argumentPointer4 = ownerRecord19;
                    argumentWord5 = 0;
                    MATCHING_KEEP2(argumentPointer4, argumentWord5);
                    scratchVector17 = &originalFrame.sp38;
                    Actor44InterpolateMobyVertexView1(argumentPointer4, argumentWord5,
                                                      scratchVector17);
                    argumentPointer4 = ownerRecord19;
                    argumentWord5 = 1;
                    MATCHING_KEEP2(argumentPointer4, argumentWord5);
                    vectorPointer16 = temporaryWord5 + 12;
                    Actor44InterpolateMobyVertexView1(argumentPointer4, argumentWord5,
                                                      vectorPointer16);
                    Actor44AddVectorView1(vectorPointer16, vectorPointer16, scratchVector17);
                    Actor44ShiftVectorRightTowardZeroView1(vectorPointer16, 1);
                    rawWord2 = 2;
                    Actor44Field(temporaryWord5, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = 32;
                    Actor44Field(temporaryWord5, unsigned char*, 0x4F) = rawWord2;
                    rawWord2 = 100;
                    *spawnedPrivate18 = rawWord2;
                    rawWord3 = Actor44Field(ownerRecord19, unsigned char*, 0x46);
                    __asm__ __volatile__("" ::: "$2", "memory");
                    rawWord2 = 254;
                    MATCHING_KEEP(rawWord2);
                    Actor44Field(temporaryWord5, unsigned char*, 0x45) = rawWord2;
                    Actor44Field(temporaryWord5, unsigned char*, 0x46) = rawWord3;
                }
            }
            Actor44Field(privateRecord21, unsigned short*, 2) =
                (unsigned short)(Actor44Field(privateRecord21, unsigned short*, 2) + 1);
            return;
        case 2:
            if (Actor44Data6C770View1 != 0) {
                Actor44RequestMobyAnimationView1(ownerRecord19, 0);
                goto setState20;
            }
            break;
    }
    return;
setState20:
    Actor44Field(ownerRecord19, unsigned char*, 0x48) = 20;
}
#undef Actor44Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_44/moby", D_level_44_8007472C);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Mixed C/original assembly implementation.
* Original SCUS-94467 level44 function800801BC, frame144.
* The one executable assembly load is original80080FE4:8C630020.
* Its input is the initialized current selector and actual local table address.
* Unsigned address arithmetic reproduces SLL2/ADDU modulo32, with the original
* LW displacement32. No arbitrary guest address is dereferenced as a C array.
* A memory clobber retains the current-memory read and foreign alias effects.
* Provenance and exact verification status are recorded in the accompanying audit manifests.
* Native identity is not a complete semantic or lifecycle review.
*/
typedef char Actor1011OriginalWordWidth
    [(sizeof(unsigned int) == 4 && sizeof(int) == 4 && sizeof(void*) == 4) ? 1 : -1];
#define Actor1011Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
typedef struct {
    int originalWords[3];
} Actor1011ThreeWords;
int Actor1011_PlaySound() __asm__("PlaySound");
int Actor1011QueryWorldSphere() __asm__("func_80019194");
int Actor1011QueryWorldHeight() __asm__("func_8001A358");
int Actor1011RequestMobyAnimation() __asm__("func_80034F40");
int Actor1011UpdateMobyMotionDescriptor() __asm__("func_80035194");
int Actor1011TurnMobyTowardPlayer() __asm__("func_8003573C");
int Actor1011TurnMobyTowardHeading() __asm__("func_8003585C");
int Actor1011CountTimerDown() __asm__("func_800359A4");
int Actor1011UpdateMobyPathMotion() __asm__("func_80035A80");
int Actor1011TestPaddedRotatedBox() __asm__("func_80036220");
int Actor1011RandBetween() __asm__("func_8003636C");
int Actor1011RandSignedBetween() __asm__("func_800363DC");
int Actor1011EmitMobyVertexParticles() __asm__("func_800369B8");
int Actor1011CountListedMobysBelowState80() __asm__("func_800369D8");
int Actor1011SpawnMobyFromValueSelector() __asm__("func_80036A68");
int Actor1011InitializeMobyMotionState() __asm__("func_80038BF8");
int Actor1011RegisterTrackedValue() __asm__("func_8003B7B4");
int Actor1011MarkMobyCollectionBit() __asm__("func_8003BA00");
int Actor1011PlanarHeadingLookup() __asm__("func_8004E880");
int Actor1011CopyVector() __asm__("func_8004F178");
int Actor1011AddVector() __asm__("func_8004F194");
int Actor1011AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Actor1011ApproximatePlanarDistance() __asm__("func_8004F334");
int Actor1011DeleteMoby() __asm__("func_80055B18");
int Actor1011RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor1011ReadSelectedFrameScalar() __asm__("func_80055E84");
int Actor1011InterpolateMobyVertex() __asm__("func_80055F14");
int Actor1011RefreshMobyPackedQueryField() __asm__("func_8005629C");
extern int Actor1011_D_800658A0 __asm__("D_800658A0");
extern int Actor1011_D_80065920 __asm__("D_80065920");
extern int Actor1011_D_80066BC8 __asm__("D_80066BC8");
extern int Actor1011_D_80067630 __asm__("D_80067630");
extern int Actor1011_D_80067634 __asm__("D_80067634");
extern int Actor1011_D_80067638 __asm__("D_80067638");
extern int Actor1011_D_8006C54C __asm__("D_8006C54C");
extern int Actor1011_D_8006C640 __asm__("D_8006C640");
extern int Actor1011_D_8006C648 __asm__("D_8006C648");
extern int Actor1011_D_8006C654 __asm__("D_8006C654");
extern int Actor1011_D_8006C770 __asm__("D_8006C770");
extern int Actor1011_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor1011_D_8006C7F8 __asm__("D_8006C7F8");
extern int Actor1011_D_8006D088 __asm__("D_8006D088");
extern int Actor1011_D_8006E020 __asm__("D_8006E020");
extern int Actor1011_D_8006E024 __asm__("D_8006E024");
extern unsigned short Actor1011_D_8006E040 __asm__("D_8006E040");
extern int Actor1011_D_8006E344 __asm__("D_8006E344");
extern int Actor1011_D_80070328 __asm__("D_80070328");
extern int Actor1011_D_8007190C __asm__("D_8007190C");
extern short Actor1011_D_800719DC __asm__("D_800719DC");
extern int Actor1011_D_level_44_8007472C __asm__("D_level_44_8007472C");
extern int (*Actor1011_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Actor1011_SpawnParticle)() __asm__("SpawnParticle");
#define Actor1011Keep(v) __asm__("" : "=r"(v) : "0"(v))
void func_level_44_800801BC(void* input) {
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
    register int actor __asm__("$17");
    register int valueS2 __asm__("$18");
    register int valueS3 __asm__("$19");
    register int privateData __asm__("$20");
    register int valueS5 __asm__("$21");
    register int valueS6 __asm__("$22");
    register int valueS7 __asm__("$23");
    register int valueT8 __asm__("$24");
    register int valueT9 __asm__("$25");
    int outgoingWord5, outgoingWord6, outgoingWord7, outgoingWord8;
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
    } frame;
    actor = (int)input;
    Actor1011Keep(actor);
    argument0 = (int)input;
    privateData = Actor1011Field(actor, int*, 0);
    Actor1011Keep(privateData);
    argument1 = (int)&Actor1011_D_level_44_8007472C;
    Actor1011Keep(argument1);
    valueV0 = Actor1011Field(argument1, int*, 0);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(argument1, int*, 4);
    Actor1011Keep(valueV1);
    argument0 = Actor1011Field(argument1, int*, 8);
    Actor1011Keep(argument0);
    Actor1011Field((int)&frame, int*, 0) = valueV0;
    Actor1011Field((int)&frame, int*, 4) = valueV1;
    Actor1011Field((int)&frame, int*, 8) = argument0;
    valueV1 = Actor1011Field(actor, unsigned char*, 72);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(46));
    Actor1011Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = (unsigned int)valueV1 < 40, 1)
                           : (valueV0 = (unsigned int)valueV1 < 40, 0))
        goto original1011_1000;
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(4)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(4)), 0))
        goto original1011_559;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(42));
    Actor1011Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1011_106;
    MATCHING_OBSERVE2_VOLATILE(valueV0, valueV1);
    valueV0 = Actor1011Field(actor, int*, 24);
    Actor1011Keep(valueV0);
    if (valueV0 == 0)
        goto original1011_106;
    MATCHING_OBSERVE_VOLATILE(valueV0);
    argument0 = Actor1011Field(actor, unsigned char*, 67);
    Actor1011Keep(argument0);
    valueV0 = Actor1011CountListedMobysBelowState80(argument0);
    valueV1 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueV1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 != valueV1)
        goto original1011_95;
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument1);
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, -14764);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(3));
    Actor1011Keep(valueV0);
    Actor1011Field((int)&Actor1011_D_80066BC8 + 17, unsigned char*, 0) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    Actor1011Field((int)&Actor1011_D_800719DC, short*, 0) = valueV0;
    argument0 = Actor1011Field(valueV1, unsigned char*, 35);
    Actor1011Keep(argument0);
    argument2 = (int)((unsigned int)0 + (unsigned int)(161));
    valueV0 = Actor1011_PlaySound(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)(211));
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 17120);
    Actor1011Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(valueS0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueS0 == 0)
        goto original1011_95;
    argument1 = (int)&Actor1011_D_80070328;
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)(12));
    valueV0 = Actor1011CopyVector(argument0, argument1);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, unsigned char*, 822);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(((int)&Actor1011_D_80065920 + valueV0), short*, 0);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueS0, int*, 12);
    Actor1011Keep(valueV1);
    valueV0 = (valueV0 >> 7);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field(valueS0, int*, 12) = valueV1;
    __asm__ volatile("" ::"r"(valueV1), "r"(valueS0) : "$2", "memory");
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, unsigned char*, 822);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueS0, int*, 20);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1011Keep(valueV0);
    argument0 = Actor1011Field(((int)&Actor1011_D_800658A0 + valueV0), short*, 0);
    Actor1011Keep(argument0);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)(500));
    Actor1011Keep(valueV1);
    Actor1011Field(valueS0, int*, 20) = valueV1;
    valueV1 = Actor1011Field(valueS0, int*, 16);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)argument0 << 1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 3);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)argument0);
    Actor1011Keep(valueV0);
    valueV0 = (valueV0 >> 7);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field(valueS0, int*, 16) = valueV1;
    __asm__ volatile("" ::"r"(valueV1), "r"(valueS0) : "$4", "memory");
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
original1011_95:
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1011SpawnMobyFromValueSelector(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1011Keep(argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(44));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(120));
    Actor1011Keep(valueV0);
    Actor1011Field(privateData, short*, 8) = valueV0;
original1011_106:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14784);
    Actor1011Keep(valueV0);
    if (valueV0 == 0)
        goto original1011_140;
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -15028);
    Actor1011Keep(valueV0);
    if (valueV0 != 0)
        goto original1011_140;
    MATCHING_OBSERVE_VOLATILE(valueV0);
    argument0 = (int)&Actor1011_D_80067630;
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field(argument0, int*, 0);
    Actor1011Keep(valueV1);
    valueV0 = valueV1 < 1025;
    Actor1011Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(-32)), 1)
                     : (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(-32)), 0))
        goto original1011_124;
    Actor1011Field(argument0, int*, 0) = valueV0;
original1011_124:
    valueV1 = (int)0x80060000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 30260);
    Actor1011Keep(valueV1);
    valueV0 = valueV1 < 1025;
    Actor1011Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(-32)), 1)
                     : (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(-32)), 0))
        goto original1011_132;
    Actor1011Field((int)&Actor1011_D_80067634, int*, 0) = valueV0;
original1011_132:
    valueV1 = (int)0x80060000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 30264);
    Actor1011Keep(valueV1);
    valueV0 = valueV1 < 1025;
    Actor1011Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(-32)), 1)
                     : (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(-32)), 0))
        goto original1011_140;
    Actor1011Field((int)&Actor1011_D_80067638, int*, 0) = valueV0;
original1011_140:
    valueV1 = Actor1011Field(actor, unsigned char*, 72);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(42));
    Actor1011Keep(valueV0);
    if (valueV1 == valueV0 ? (valueV0 = valueV1 < 43, 1) : (valueV0 = valueV1 < 43, 0))
        goto original1011_162;
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(40)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(40)), 0))
        goto original1011_150;
    if (valueV1 == valueV0)
        goto original1011_155;
    goto original1011Return;
original1011_150:
    valueV0 = (int)((unsigned int)0 + (unsigned int)(44));
    Actor1011Keep(valueV0);
    valueS2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV1 == valueV0)
        goto original1011_356;
    goto original1011Return;
original1011_155:
    valueV0 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(privateData, int*, 4);
    Actor1011Keep(valueV1);
    Actor1011Field(valueV0, short*, 2) = valueV1;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(42));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    goto original1011Return;
original1011_162:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    valueV1 = Actor1011Field(actor, unsigned char*, 73);
    Actor1011Keep(valueV1);
    switch ((unsigned int)valueV1) {
        case 0:
            MATCHING_OBSERVE_VOLATILE(valueV1);
            goto original1011_178;
        case 1:
            goto original1011_284;
        case 2:
            goto original1011_304;
        case 3:
            goto original1011_295;
        case 4:
            goto original1011_304;
        case 5:
            goto original1011_304;
        case 6:
            goto original1011_226;
        case 7:
            goto original1011_239;
        default:
            goto original1011_304;
    }
original1011_178:
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1011Keep(argument0);
    valueS0 = (int)&Actor1011_D_80070328;
    Actor1011Keep(valueS0);
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1011ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 14000;
    Actor1011Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_304;
    valueV1 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1011Keep(argument0);
    argument0 = Actor1011Field(argument0, int*, -8160);
    Actor1011Keep(argument0);
    valueV0 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1011Keep(argument1);
    argument1 = Actor1011Field(argument1, int*, -8156);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)0x80070000U;
    Actor1011Keep(argument0);
    argument0 = Actor1011Field(argument0, unsigned short*, -8128);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)argument0 << 16);
    Actor1011Keep(argument0);
    argument0 = (argument0 >> 20);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 18;
    Actor1011Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_304;
    valueV1 = Actor1011Field(valueS0, int*, 0);
    Actor1011Keep(valueV1);
    argument0 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 812);
    Actor1011Keep(valueV0);
    argument1 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 50;
    Actor1011Keep(valueV0);
    valueS0 = (int)&frame.sp40;
    if (valueV0 == 0)
        goto original1011_305;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(240));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 64) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(6));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 73) = valueV0;
    goto original1011_304;
original1011_226:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
    valueS0 = (int)&frame.sp40;
    if (valueV0 == 0)
        goto original1011_305;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(240));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 64) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(7));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 73) = valueV0;
    goto original1011_304;
original1011_239:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1011ReadSelectedFrameScalar(argument0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(-36));
    Actor1011Keep(valueV0);
    valueV0 = (unsigned int)valueV0 < 14;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_284;
    argument1 = (int)((unsigned int)0 + (unsigned int)(5));
    valueV0 = Actor1011RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument1);
    valueS3 = (int)&frame.sp30;
    Actor1011Keep(valueS3);
    argument2 = (int)((unsigned int)valueS3 + (unsigned int)0);
    valueV0 = Actor1011InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)(608));
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 17120);
    Actor1011Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS2 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(valueS2);
    valueS0 = (int)((unsigned int)valueS2 + (unsigned int)(12));
    if (valueS2 == 0)
        goto original1011_284;
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueS3 + (unsigned int)0);
    Actor1011Keep(argument1);
    valueV1 = Actor1011Field(valueS2, int*, 0);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 73) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(200));
    Actor1011Keep(valueV0);
    Actor1011Field(valueV1, int*, 0) = valueV0;
    Actor1011Field(valueS2, unsigned char*, 72) = 0;
    valueV0 = Actor1011CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    argument1 = (int)&Actor1011_D_80070328;
    Actor1011Keep(argument1);
    Actor1011Field(valueS2, unsigned char*, 70) = valueV0;
    valueV0 = Actor1011ApproximatePlanarDistance(argument0, argument1);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 816);
    Actor1011Keep(valueV0);
    argument1 = Actor1011Field(valueS2, int*, 20);
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1011Field(valueS2, unsigned char*, 69) = valueV0;
original1011_284:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
    valueS0 = (int)&frame.sp40;
    if (valueV0 == 0)
        goto original1011_305;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(3));
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(8));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 73) = valueV0;
    goto original1011_304;
original1011_295:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
    valueS0 = (int)&frame.sp40;
    if (valueV0 == 0)
        goto original1011_305;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    Actor1011Field(actor, unsigned char*, 73) = 0;
original1011_304:
    valueS0 = (int)&frame.sp40;
    Actor1011Keep(valueS0);
original1011_305:
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueS2 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1011Keep(valueS2);
    argument1 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1011CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(150));
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field((int)&frame, volatile int*, 32);
    Actor1011Keep(valueV1);
    argument1 = (int)((unsigned int)0 + (unsigned int)(150));
    Actor1011Keep(argument1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field((int)&frame, int*, 32) = valueV1;
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field((int)&frame, volatile int*, 36);
    Actor1011Keep(valueV1);
    argument1 = (int)((unsigned int)0 + (unsigned int)(150));
    Actor1011Keep(argument1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field((int)&frame, int*, 36) = valueV1;
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    valueV1 = Actor1011Field((int)&frame, volatile int*, 40);
    Actor1011Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field((int)&frame, int*, 40) = valueV1;
    valueV0 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueV0);
    Actor1011Field((int)&frame, int*, 16) = valueV0;
    valueV0 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, unsigned short*, 2);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    Actor1011Field((int)&frame, short*, 20) = valueV0;
    valueV1 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 16);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueV1, short*, 0);
    Actor1011Keep(valueV1);
    valueV0 = (valueV0 >> 16);
    Actor1011Keep(valueV0);
    valueV0 = valueV0 < valueV1;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)valueV1 + (unsigned int)0);
    if (valueV0 != 0)
        goto original1011_346;
    valueV0 = (int)((unsigned int)argument0 + (unsigned int)(-1));
    Actor1011Keep(valueV0);
    Actor1011Field((int)&frame, short*, 20) = valueV0;
original1011_346:
    argument0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(62));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument2);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 17124);
    Actor1011Keep(valueV0);
    argument3 = (int)&frame.sp30;
    Actor1011Keep(argument3);
    Actor1011Field((int)&frame, short*, 22) = 0;
    valueV0 = ((int (*)())valueV0)(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    goto original1011_550;
original1011_356:
    argument0 = (int)((unsigned int)privateData + (unsigned int)(8));
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1011CountTimerDown(argument0, argument1);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(46)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(46)), 0))
        goto original1011_379;
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    valueS0 = (int)((unsigned int)actor + (unsigned int)(72));
    Actor1011Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument2 = (int)&Actor1011_D_8006D088;
    Actor1011Keep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument2 = (int)&Actor1011_D_8006C7F8;
    Actor1011Keep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    valueV0 = Actor1011RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(32));
    goto original1011_998;
original1011_379:
    MATCHING_KEEP_VOLATILE(valueS2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    valueS0 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueS0);
    argument0 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(argument0);
    argument1 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 70) = valueV0;
    valueV0 = Actor1011Field(valueS0, short*, 2);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueS0, int*, 12);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueV0, int*, 0);
    Actor1011Keep(valueV1);
    valueV0 = Actor1011Field(valueV0, int*, 4);
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 65;
    Actor1011Keep(valueV0);
    if (valueV0 != 0)
        goto original1011_402;
    valueS2 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueS2);
original1011_402:
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 70) = valueV0;
    if (valueS2 == 0)
        goto original1011_446;
    argument0 = Actor1011Field(valueS0, short*, 2);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field(valueS0, short*, 0);
    Actor1011Keep(valueV1);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)(1));
    Actor1011Keep(argument0);
    valueV0 = (int)((unsigned int)argument0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV1 = valueV0 % valueV1;
    Actor1011Keep(valueV1);
    MATCHING_BARRIER_VOLATILE("memory");
    valueV0 = Actor1011Field(valueS0, short*, 0);
    Actor1011Keep(valueV0);
    argument0 = argument0 < valueV0;
    Actor1011Keep(argument0);
    Actor1011Field(valueS0, short*, 2) = valueV1;
    if (argument0 != 0)
        goto original1011_446;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(46));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    valueS0 = (int)((unsigned int)actor + (unsigned int)(72));
    Actor1011Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument2 = (int)&Actor1011_D_8006D088;
    Actor1011Keep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument2 = (int)&Actor1011_D_8006C7F8;
    Actor1011Keep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    valueV0 = Actor1011RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(32));
    goto original1011_998;
original1011_446:
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    valueV0 = Actor1011Field(valueS0, short*, 2);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueS0, int*, 12);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    argument3 = Actor1011Field(valueV0, int*, 16);
    Actor1011Keep(argument3);
    argument0 = Actor1011Field(valueV0, int*, 0);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field(valueV0, int*, 20);
    Actor1011Keep(valueV1);
    argument1 = Actor1011Field(valueV0, int*, 4);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)argument3 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV1 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(6));
    Actor1011Keep(argument2);
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    argument3 = (int)((unsigned int)0 + (unsigned int)(6));
    Actor1011Keep(argument3);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 70) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    outgoingWord5 = valueV0;
    outgoingWord6 = 0;
    valueV0 = Actor1011TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                             outgoingWord5, outgoingWord6);
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    valueS2 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1011Keep(valueS2);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(128));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 70) = valueV0;
    valueV0 = valueV0 & 255;
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(((int)&Actor1011_D_80065920 + valueV0), short*, 0);
    Actor1011Keep(valueV1);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1011Keep(valueV0);
    valueV0 = (valueV0 >> 12);
    Actor1011Keep(valueV0);
    Actor1011Field((int)&frame, int*, 16) = valueV0;
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    argument1 = (int)&frame.sp30;
    Actor1011Keep(argument1);
    valueV0 = (int)((unsigned int)valueV0 << 1);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(((int)&Actor1011_D_800658A0 + valueV0), short*, 0);
    Actor1011Keep(valueV1);
    argument2 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1011Keep(argument2);
    Actor1011Field((int)&frame, int*, 24) = 0;
    __asm__ volatile("" ::"m"(frame.sp38) : "memory");
    valueV0 = (int)((unsigned int)valueV1 << 1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 << 2);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1011Keep(valueV0);
    valueV0 = (valueV0 >> 12);
    Actor1011Keep(valueV0);
    Actor1011Field((int)&frame, int*, 20) = valueV0;
    valueV0 = Actor1011AddVector(argument0, argument1, argument2);
    valueV0 = Actor1011Field(valueS0, short*, 2);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(valueS0, int*, 12);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 << 4);
    Actor1011Keep(valueV0);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 8);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(3072));
    Actor1011Keep(valueV0);
    valueV0 = valueV1 < valueV0;
    Actor1011Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(50)), 1)
                     : (valueV0 = (int)((unsigned int)valueV1 + (unsigned int)(50)), 0))
        goto original1011_519;
    Actor1011Field(actor, int*, 20) = valueV0;
original1011_519:
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(700));
    valueV0 = Actor1011QueryWorldSphere(argument0, argument1);
    if (valueV0 == 0)
        goto original1011_528;
    argument1 = (int)&Actor1011_D_8007190C;
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueS2 + (unsigned int)0);
    valueV0 = Actor1011CopyVector(argument0, argument1);
original1011_528:
    valueV1 = Actor1011Field(actor, unsigned char*, 61);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(5));
    Actor1011Keep(valueV0);
    if (valueV1 != valueV0)
        goto original1011_542;
    MATCHING_OBSERVE2_VOLATILE(valueV0, valueV1);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14776);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 1);
    Actor1011Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    valueV0 = Actor1011Field(actor, unsigned char*, 69);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 << 1);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 69) = valueV0;
    goto original1011_549;
original1011_542:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_549;
    argument1 = (int)((unsigned int)0 + (unsigned int)(5));
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
original1011_549:
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    Actor1011Keep(argument0);
original1011_550:
    argument1 = (int)((unsigned int)0 + (unsigned int)(8192));
    valueV0 = Actor1011QueryWorldHeight(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1011RefreshMobyPackedQueryField(argument0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1011RefreshMobySpatialGridAndBasis(argument0, argument1);
    goto original1011Return;
original1011_559:
    if (valueV1 == valueV0)
        goto original1011_576;
    valueV0 = Actor1011Field(actor, int*, 24);
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_576;
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1011SpawnMobyFromValueSelector(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)privateData + (unsigned int)(12));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(6));
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(4));
    valueV0 = Actor1011InitializeMobyMotionState(argument0, argument1, argument2, argument3);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(180));
    Actor1011Keep(valueV0);
    Actor1011Field(privateData, unsigned char*, 34) = valueV0;
original1011_576:
    valueV1 = Actor1011Field(actor, unsigned char*, 72);
    Actor1011Keep(valueV1);
    switch ((unsigned int)valueV1) {
        case 0:
            goto original1011_624;
        case 1:
            goto original1011_731;
        case 2:
            goto original1011_837;
        case 3:
            goto original1011_922;
        case 4:
            goto original1011_933;
        case 5:
            goto original1011Return;
        case 6:
            goto original1011Return;
        case 7:
            goto original1011Return;
        case 8:
            goto original1011Return;
        case 9:
            goto original1011Return;
        case 10:
            goto original1011Return;
        case 11:
            goto original1011Return;
        case 12:
            goto original1011Return;
        case 13:
            goto original1011Return;
        case 14:
            goto original1011Return;
        case 15:
            goto original1011Return;
        case 16:
            goto original1011Return;
        case 17:
            goto original1011Return;
        case 18:
            goto original1011Return;
        case 19:
            goto original1011Return;
        case 20:
            MATCHING_OBSERVE_VOLATILE(valueV1);
            goto original1011_587;
        case 21:
            goto original1011Return;
        case 22:
            goto original1011_604;
        default:
            goto original1011Return;
    }
original1011_587:
    argument0 = (int)&Actor1011_D_80070328;
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)privateData + (unsigned int)(40));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(16384));
    valueV0 = Actor1011TestPaddedRotatedBox(argument0, argument1, argument2, argument3);
    if (valueV0 == 0)
        goto original1011Return;
    valueV0 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueV0);
    Actor1011Field(valueV0, short*, 2) = 0;
    valueV1 = Actor1011Field(privateData, int*, 36);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    Actor1011Field(valueV1, short*, 10) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(22));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    goto original1011Return;
original1011_604:
    valueV0 = Actor1011UpdateMobyPathMotion(actor, Actor1011Field(privateData, int*, 36), 120, 100,
                                            0, 4, 32, 0);
    valueV0 = valueV0 & 2;
    Actor1011Keep(valueV0);
    if (valueV0 != 0)
        goto original1011_927;
    argument1 = (int)&Actor1011_D_80070328;
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    valueV0 = Actor1011ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 8192;
    goto original1011_924;
original1011_624:
    argument1 = (int)&Actor1011_D_80070328;
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    valueV0 = Actor1011ApproximatePlanarDistance(argument0, argument1);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(valueS0);
    valueV0 = valueS0 < 14336;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_667;
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    argument0 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(argument0);
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 816);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)argument0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    if (valueV0 >= 0)
        goto original1011_644;
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1011Keep(valueV0);
original1011_644:
    valueV0 = valueV0 < 51;
    Actor1011Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = argument0 < valueV1, 1) : (valueV0 = argument0 < valueV1, 0))
        goto original1011_654;
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)argument0 + (unsigned int)(50)), 1)
                     : (valueV0 = (int)((unsigned int)argument0 + (unsigned int)(50)), 0))
        goto original1011_651;
    Actor1011Field(actor, int*, 20) = valueV0;
    goto original1011_655;
original1011_651:
    valueV0 = (int)((unsigned int)argument0 + (unsigned int)(-50));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, int*, 20) = valueV0;
    goto original1011_655;
original1011_654:
    Actor1011Field(actor, int*, 20) = valueV1;
original1011_655:
    valueV1 = Actor1011Field(privateData, short*, 0);
    Actor1011Keep(valueV1);
    argument0 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(argument0);
    valueV0 = valueV1 < argument0;
    Actor1011Keep(valueV0);
    if (valueV0 != 0)
        goto original1011_666;
    valueV1 = Actor1011Field(privateData, short*, 2);
    Actor1011Keep(valueV1);
    valueV0 = argument0 < valueV1;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)privateData + (unsigned int)(8));
    if (valueV0 == 0)
        goto original1011_668;
original1011_666:
    Actor1011Field(actor, int*, 20) = valueV1;
original1011_667:
    argument0 = (int)((unsigned int)privateData + (unsigned int)(8));
    Actor1011Keep(argument0);
original1011_668:
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1011CountTimerDown(argument0, argument1);
    if (valueV0 == 0 ? (valueV0 = valueS0 < 9216, 1) : (valueV0 = valueS0 < 9216, 0))
        goto original1011Return;
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 0))
        goto original1011Return;
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, -7356);
    Actor1011Keep(valueV1);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(15)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(15)), 0))
        goto original1011Return;
    if (valueV1 == valueV0)
        goto original1011Return;
    valueV0 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 816);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    if (valueV0 >= 0)
        goto original1011_689;
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1011Keep(valueV0);
original1011_689:
    valueV0 = valueV0 < 3072;
    Actor1011Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011Return;
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 808);
    Actor1011Keep(valueV1);
    argument0 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 812);
    Actor1011Keep(valueV0);
    argument1 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 8;
    Actor1011Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011Return;
    valueV1 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1011Keep(argument0);
    argument0 = Actor1011Field(argument0, int*, -8160);
    Actor1011Keep(argument0);
    valueV0 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1011Keep(argument1);
    argument1 = Actor1011Field(argument1, int*, -8156);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)0x80070000U;
    Actor1011Keep(argument0);
    argument0 = Actor1011Field(argument0, unsigned short*, -8128);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)argument0 << 16);
    Actor1011Keep(argument0);
    argument0 = (argument0 >> 20);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 18;
    Actor1011Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 0))
        goto original1011Return;
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    goto original1011Return;
original1011_731:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
    argument0 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(argument0);
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 816);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)argument0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    if (valueV0 >= 0)
        goto original1011_744;
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1011Keep(valueV0);
original1011_744:
    valueV0 = valueV0 < 51;
    Actor1011Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = argument0 < valueV1, 1) : (valueV0 = argument0 < valueV1, 0))
        goto original1011_754;
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)argument0 + (unsigned int)(50)), 1)
                     : (valueV0 = (int)((unsigned int)argument0 + (unsigned int)(50)), 0))
        goto original1011_751;
    Actor1011Field(actor, int*, 20) = valueV0;
    goto original1011_755;
original1011_751:
    valueV0 = (int)((unsigned int)argument0 + (unsigned int)(-50));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, int*, 20) = valueV0;
    goto original1011_755;
original1011_754:
    Actor1011Field(actor, int*, 20) = valueV1;
original1011_755:
    valueV1 = Actor1011Field(privateData, short*, 0);
    Actor1011Keep(valueV1);
    argument1 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(argument1);
    valueV0 = valueV1 < argument1;
    Actor1011Keep(valueV0);
    if (valueV0 == 0)
        goto original1011_763;
    Actor1011Field(actor, int*, 20) = valueV1;
    goto original1011_769;
original1011_763:
    argument0 = Actor1011Field(privateData, short*, 2);
    Actor1011Keep(argument0);
    valueV0 = argument1 < argument0;
    Actor1011Keep(valueV0);
    if (valueV0 == 0)
        goto original1011_769;
    MATCHING_OBSERVE_VOLATILE(valueV0);
    Actor1011Field(actor, int*, 20) = argument0;
original1011_769:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(1)), 0))
        goto original1011Return;
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, -7356);
    Actor1011Keep(valueV1);
    if (valueV1 == valueV0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(15)), 1)
                           : (valueV0 = (int)((unsigned int)0 + (unsigned int)(15)), 0))
        goto original1011_927;
    if (valueV1 == valueV0)
        goto original1011_927;
    argument3 = (int)&Actor1011_D_80070328 + 8;
    Actor1011Keep(argument3);
    valueV0 = Actor1011Field(actor, int*, 20);
    Actor1011Keep(valueV0);
    valueV1 = Actor1011Field(argument3, int*, 0);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 - (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    if (valueV0 >= 0)
        goto original1011_790;
    valueV0 = (int)((unsigned int)0 - (unsigned int)valueV0);
    Actor1011Keep(valueV0);
original1011_790:
    valueV0 = valueV0 < 3072;
    Actor1011Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_927;
    valueS0 = (int)((unsigned int)argument3 + (unsigned int)(-8));
    Actor1011Keep(valueS0);
    valueV1 = Actor1011Field(argument3, int*, -8);
    Actor1011Keep(valueV1);
    argument0 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 812);
    Actor1011Keep(valueV0);
    argument1 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 8;
    Actor1011Keep(valueV0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_927;
    valueV1 = Actor1011Field(actor, int*, 12);
    Actor1011Keep(valueV1);
    argument0 = (int)0x80070000U;
    Actor1011Keep(argument0);
    argument0 = Actor1011Field(argument0, int*, -8160);
    Actor1011Keep(argument0);
    valueV0 = Actor1011Field(actor, int*, 16);
    Actor1011Keep(valueV0);
    argument1 = (int)0x80070000U;
    Actor1011Keep(argument1);
    argument1 = Actor1011Field(argument1, int*, -8156);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)valueV1 - (unsigned int)argument0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = (int)0x80070000U;
    Actor1011Keep(argument0);
    argument0 = Actor1011Field(argument0, unsigned short*, -8128);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(argument1);
    argument0 = (int)((unsigned int)argument0 << 16);
    Actor1011Keep(argument0);
    argument0 = (argument0 >> 20);
    valueV0 = Actor1011AbsoluteByteAngleDelta(argument0, argument1);
    valueV0 = valueV0 < 18;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)(12));
    if (valueV0 == 0)
        goto original1011_927;
    argument1 = (int)((unsigned int)valueS0 + (unsigned int)0);
    valueV0 = Actor1011ApproximatePlanarDistance(argument0, argument1);
    valueV0 = valueV0 < 9216;
    Actor1011Keep(valueV0);
    if (valueV0 == 0 ? (valueV0 = (int)((unsigned int)0 + (unsigned int)(2)), 1)
                     : (valueV0 = (int)((unsigned int)0 + (unsigned int)(2)), 0))
        goto original1011_927;
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(2));
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    goto original1011Return;
original1011_837:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1011ReadSelectedFrameScalar(argument0);
    valueS0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(valueS0);
    valueV0 = valueS0 < 35;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_847;
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)(2));
    Actor1011Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)(1));
    valueV0 = Actor1011TurnMobyTowardPlayer(argument0, argument1, argument2, argument3);
original1011_847:
    valueV0 = Actor1011Field(actor, unsigned char*, 73);
    Actor1011Keep(valueV0);
    if (valueV0 != 0 ? (valueV0 = (int)((unsigned int)valueS0 + (unsigned int)(-36)), 1)
                     : (valueV0 = (int)((unsigned int)valueS0 + (unsigned int)(-36)), 0))
        goto original1011_893;
    valueV0 = (unsigned int)valueV0 < 14;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_893;
    argument1 = (int)((unsigned int)0 + (unsigned int)(5));
    valueV0 = Actor1011RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument1);
    valueS3 = (int)&frame.sp30;
    Actor1011Keep(valueS3);
    argument2 = (int)((unsigned int)valueS3 + (unsigned int)0);
    valueV0 = Actor1011InterpolateMobyVertex(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)(608));
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 17120);
    Actor1011Keep(valueV0);
    argument1 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = ((int (*)())valueV0)(argument0, argument1);
    valueS2 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(valueS2);
    valueS0 = (int)((unsigned int)valueS2 + (unsigned int)(12));
    if (valueS2 == 0)
        goto original1011_893;
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)valueS3 + (unsigned int)0);
    Actor1011Keep(argument1);
    valueV1 = Actor1011Field(valueS2, int*, 0);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 73) = valueV0;
    valueV0 = (int)((unsigned int)0 + (unsigned int)(200));
    Actor1011Keep(valueV0);
    Actor1011Field(valueV1, int*, 0) = valueV0;
    Actor1011Field(valueS2, unsigned char*, 72) = 0;
    valueV0 = Actor1011CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV0 = Actor1011Field(actor, unsigned char*, 70);
    Actor1011Keep(valueV0);
    argument1 = (int)&Actor1011_D_80070328;
    Actor1011Keep(argument1);
    Actor1011Field(valueS2, unsigned char*, 70) = valueV0;
    valueV0 = Actor1011ApproximatePlanarDistance(argument0, argument1);
    argument0 = (int)((unsigned int)valueV0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, 816);
    Actor1011Keep(valueV0);
    argument1 = Actor1011Field(valueS2, int*, 20);
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument2);
    argument1 = (int)((unsigned int)valueV0 - (unsigned int)argument1);
    valueV0 = Actor1011PlanarHeadingLookup(argument0, argument1, argument2);
    Actor1011Field(valueS2, unsigned char*, 69) = valueV0;
original1011_893:
    MATCHING_OBSERVE_VOLATILE(valueV0);
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
    if (valueV0 == 0)
        goto original1011Return;
    valueV0 = Actor1011Field(privateData, unsigned short*, 10);
    Actor1011Keep(valueV0);
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, -14396);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)(1));
    Actor1011Keep(valueV0);
    Actor1011Field(privateData, short*, 10) = valueV0;
    valueV0 = (int)((unsigned int)valueV0 << 16);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 << 2);
    Actor1011Keep(valueV1);
    valueV1 = (int)((unsigned int)&frame + (unsigned int)valueV1 - 32U);
    Actor1011Keep(valueV1);
    __asm__ volatile("lw %0,32(%0)" : "=r"(valueV1) : "0"(valueV1) : "memory");
    valueV0 = (valueV0 >> 16);
    Actor1011Keep(valueV0);
    valueV0 = valueV0 < valueV1;
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 == 0)
        goto original1011_913;
    Actor1011Field(actor, unsigned char*, 73) = 0;
    goto original1011Return;
original1011_913:
    argument1 = (int)((unsigned int)0 + (unsigned int)(3));
    Actor1011Keep(argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(3));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 72) = valueV0;
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(60));
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 73) = 0;
    Actor1011Field(privateData, short*, 8) = valueV0;
    Actor1011Field(privateData, short*, 10) = 0;
    goto original1011Return;
original1011_922:
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14480);
    Actor1011Keep(valueV0);
original1011_924:
    if (valueV0 == 0)
        goto original1011Return;
original1011_927:
    Actor1011Field(actor, unsigned char*, 72) = 0;
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    valueV0 = Actor1011RequestMobyAnimation(argument0, argument1);
    goto original1011Return;
original1011_933:
    valueS0 = (int)&frame.sp50;
    Actor1011Keep(valueS0);
    argument0 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)actor + (unsigned int)(12));
    valueV0 = Actor1011CopyVector(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(150));
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field((int)&frame, volatile int*, 48);
    Actor1011Keep(valueV1);
    argument1 = (int)((unsigned int)0 + (unsigned int)(150));
    Actor1011Keep(argument1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field((int)&frame, int*, 48) = valueV1;
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field((int)&frame, volatile int*, 52);
    Actor1011Keep(valueV1);
    argument1 = (int)((unsigned int)0 + (unsigned int)(150));
    Actor1011Keep(argument1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field((int)&frame, int*, 52) = valueV1;
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    valueV1 = Actor1011Field((int)&frame, volatile int*, 56);
    Actor1011Keep(valueV1);
    argument1 = (int)((unsigned int)0 + (unsigned int)(10));
    Actor1011Keep(argument1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    Actor1011Field((int)&frame, int*, 56) = valueV1;
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(10));
    Actor1011Keep(argument1);
    Actor1011Field((int)&frame, int*, 64) = valueV0;
    valueV0 = Actor1011RandSignedBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)(5));
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(8));
    Actor1011Keep(argument1);
    Actor1011Field((int)&frame, int*, 68) = valueV0;
    valueV0 = Actor1011RandBetween(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)(1));
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(39));
    Actor1011Keep(argument1);
    argument2 = (int)((unsigned int)valueS0 + (unsigned int)0);
    Actor1011Keep(argument2);
    valueV1 = (int)0x80070000U;
    Actor1011Keep(valueV1);
    valueV1 = Actor1011Field(valueV1, int*, 17124);
    Actor1011Keep(valueV1);
    argument3 = (int)&frame.sp60;
    Actor1011Keep(argument3);
    Actor1011Field((int)&frame, int*, 72) = valueV0;
    valueV0 = ((int (*)())valueV1)(argument0, argument1, argument2, argument3);
    valueV1 = Actor1011Field(actor, unsigned char*, 61);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)0 + (unsigned int)(5));
    Actor1011Keep(valueV0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV1 != valueV0)
        goto original1011_987;
    valueV0 = (int)0x80070000U;
    Actor1011Keep(valueV0);
    valueV0 = Actor1011Field(valueV0, int*, -14776);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV0 << 1);
    Actor1011Keep(valueV1);
    valueV1 = (int)((unsigned int)valueV1 + (unsigned int)valueV0);
    Actor1011Keep(valueV1);
    valueV0 = Actor1011Field(actor, unsigned char*, 69);
    Actor1011Keep(valueV0);
    valueV1 = (int)((unsigned int)valueV1 << 1);
    Actor1011Keep(valueV1);
    valueV0 = (int)((unsigned int)valueV0 + (unsigned int)valueV1);
    Actor1011Keep(valueV0);
    Actor1011Field(actor, unsigned char*, 69) = valueV0;
original1011_987:
    argument1 = (int)((unsigned int)privateData + (unsigned int)(12));
    valueV0 = Actor1011UpdateMobyMotionDescriptor(argument0, argument1);
    valueV1 = (int)((unsigned int)0 + (unsigned int)(256));
    Actor1011Keep(valueV1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    if (valueV0 != valueV1)
        goto original1011Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)(4));
    valueV0 = Actor1011RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1011MarkMobyCollectionBit(argument0);
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    Actor1011Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)(40));
    Actor1011Keep(argument1);
original1011_998:
    valueV0 = Actor1011EmitMobyVertexParticles(argument0, argument1);
original1011_1000:
    argument0 = (int)((unsigned int)actor + (unsigned int)0);
    valueV0 = Actor1011DeleteMoby(argument0);
original1011Return:
    return;
}
#undef Actor1011Field
#undef Actor1011Keep


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80081188.
* Assembly SHA256 53b344e1443d26b34701f888954ef938c6b06b511379591b77f11fe3ef0a910a.
* AI generated; not human reviewed. All525 original instructions and
* actual branch/call/internal targets are required. The original29-entry
* selector table has bias0 and one padding word; debug text occupies18
* bytes plus two original alignment bytes. Frame50 retains original
* SP20/SP24 local stores, SP28..37 vector and S0/S1/S2/S3/RA saves.
* The two original XOR/shift checks retain their full32-bit loads/stores;
* no inferred16-bit truncation or invented polynomial behavior is used.
* The packed private word mask uses original LW at80081590. The original
* state3 owner stores use A0; state20 retains the original local coordinate
* stores and three-argument call; state24 retains both SP30 stores and
* signed table loads. Shared deletion stays at its original target.
* Empty initialized constraints, memory dependencies and clobbers of dead
* registers emit no CPU instructions. No partial HI, FP shortcut or opcode
* assembly is used. Raw field units/fixed point, full helper contracts,
* caller cadence and synchronized runtime behavior remain unresolved.
* Cadence here is per invocation; confidence is binary identity only.
* Falsification: every native/linked word and actual target, all selectors,
* debug/alignment bytes, full EXE/every-overlay hashes must match. */
#define Actor44Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Actor44SetCameraMode11TargetView1() __asm__("func_80013D44");
unsigned char Actor44MaskLinkedRecordFlagsByIdView1() __asm__("func_80021ED8");
int Actor44QueryShiftedLinkedRecordWordByByteIdView1() __asm__("func_80021F3C");
unsigned char Actor44RequestMobyAnimationView1() __asm__("func_80034F40");
int Actor44TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor44UpdateMobyPathMotionView1() __asm__("func_80035A80");
int Actor44UpdateMobyInteractionGateView1() __asm__("func_80037BBC");
unsigned char Actor44RegisterTrackedValueView1() __asm__("func_8003B7B4");
int Actor44PlanarHeadingLookupView1() __asm__("func_8004E880");
unsigned char Actor44AddVectorView1() __asm__("func_8004F194");
int Actor44AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor44ApproximatePlanarDistanceView1() __asm__("func_8004F334");
unsigned char Actor44StartDialogueView1() __asm__("func_800512E4");
unsigned char Actor44DeleteMobyView1() __asm__("func_80055B18");
unsigned char Actor44WriteFormattedOutputView1() __asm__("func_8005F5FC");
extern unsigned char Actor44Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor44Data65920View1 __asm__("D_80065920");
extern int Actor44Data6C550View1 __asm__("D_8006C550");
extern int Actor44Data6C58CView1 __asm__("D_8006C58C");
extern int Actor44Data6C598View1 __asm__("D_8006C598");
extern int Actor44Data6C640View1 __asm__("D_8006C640");
extern unsigned char Actor44Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Actor44Data6C7F8View1 __asm__("D_8006C7F8");
extern unsigned char Actor44Data6D088View1 __asm__("D_8006D088");
extern int Actor44Data6E344View1 __asm__("D_8006E344");
extern unsigned char Actor44Data70300View1 __asm__("D_80070300");
extern unsigned char Actor44Data70328View1 __asm__("D_80070328");
extern signed char Actor44Data71A04View1 __asm__("D_80071A04");
extern unsigned char Actor44Data93E5CView1 __asm__("D_level_44_80093E5C");
extern unsigned char Actor44Call755ACView1 __asm__("func_level_44_800755AC");
extern unsigned char Actor44Datamain_TEXT_ENDView1 __asm__("main_TEXT_END");
extern unsigned char Actor44Datamain_TEXT_STARTView1 __asm__("main_TEXT_START");
extern int (*Actor44Data74330View1)() __asm__("unk_ovlheader_80074330");
const char Actor44DebugData[18] __asm__("D_level_44_800747B4")
    __attribute__((aligned(4))) = "Resetting puzzle\n";
extern unsigned char Actor44DebugTextView __asm__("D_level_44_800747B4");
void func_level_44_80081188(void* input) {
    register void* ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"),
        argumentWord6 __asm__("$6");
    register void* vectorPointer16 __asm__("$16");
    struct {
        volatile int sp20;
        int sp24, sp28, sp2C;
        volatile int sp30;
        int sp34;
    } originalFrame;
    register unsigned char* checkEndPointer6 __asm__("$6");
    register int rawAngle16 __asm__("$16");
    int temporaryWord2;
    register int firstBitIndex4 __asm__("$4");
    register int secondBitIndex4 __asm__("$4");
    register int processedByteCount5 __asm__("$5");
    register int state0Predicate19 __asm__("$19");
    int temporaryWord13;
    int temporaryWord14;
    signed char* temporaryWord12;
    unsigned int temporaryWord3;
    unsigned int temporaryWord4;
    unsigned int temporaryWord5;
    register int state3RawType19 __asm__("$19");
    int temporaryWord6;
    int temporaryWord7;
    void* temporaryPointer1;
    register void* firstPrivateBytePointer16 __asm__("$16");
    register void* secondPrivateBytePointer16 __asm__("$16");
    register void* privateRecord17 __asm__("$17");
    ownerRecord18 = input;
    MATCHING_KEEP(ownerRecord18);
    privateRecord17 = Actor44Field(ownerRecord18, void**, 0);
    if ((unsigned int)Actor44Field(privateRecord17, unsigned int*, 0x30) >=
        (unsigned int)&Actor44Call755ACView1) {
        processedByteCount5 = 0;
        checkEndPointer6 = &Actor44Data93E5CView1;
        MATCHING_KEEP(checkEndPointer6);
    checkOverlayByte:
        temporaryWord3 = Actor44Field(privateRecord17, unsigned int*, 0x30);
        if (temporaryWord3 < (unsigned int)checkEndPointer6) {
            firstBitIndex4 = 0;
            Actor44Field(privateRecord17, int*, 0x34) =
                (int)(Actor44Field(privateRecord17, int*, 0x34) ^
                      (Actor44Field(temporaryWord3, unsigned char*, 0) << 8));
            do {
                rawWord3 = Actor44Field(privateRecord17, volatile int*, 0x34);
                rawWord2 = rawWord3 & 0x8000;
                if (rawWord2)
                    rawWord2 = (rawWord3 * 2) ^ 0x8005;
                else
                    rawWord2 = rawWord3 * 2;
                Actor44Field(privateRecord17, volatile int*, 0x34) = rawWord2;
                firstBitIndex4 += 1;
                rawWord2 = firstBitIndex4 < 8;
            } while (rawWord2);
            processedByteCount5 += 1;
            Actor44Field(privateRecord17, unsigned int*, 0x30) =
                (unsigned int)(Actor44Field(privateRecord17, unsigned int*, 0x30) + 1);
            if (processedByteCount5 >= 0x40) {
            } else {
                goto checkOverlayByte;
            }
        }
    }
    if ((Actor44Field(privateRecord17, unsigned int*, 0x30) == &Actor44Data93E5CView1) &&
        (Actor44Field(privateRecord17, int*, 0x34) != 0)) {
        temporaryWord14 = 0x1A;
        temporaryWord12 = &Actor44Data70300View1 + 0x1A;
        do {
            *temporaryWord12 = 0;
            temporaryWord14 -= 1;
            temporaryWord12 -= 1;
        } while (temporaryWord14 >= 0);
        Actor44Field(privateRecord17, int*, 0x34) = 0;
    }
    if (Actor44Field(privateRecord17, unsigned int*, 0x30) == 0) {
        Actor44Field(privateRecord17, unsigned int*, 0x30) =
            (unsigned int)(Actor44Data6C58CView1 + (&Actor44Datamain_TEXT_STARTView1 + 2));
    }
    rawWord2 = Actor44Field(privateRecord17, unsigned int*, 0x30);
    rawWord3 = (int)&Actor44Datamain_TEXT_ENDView1;
    MATCHING_KEEP(rawWord3);
    if ((unsigned int)rawWord2 < (unsigned int)rawWord3) {
        processedByteCount5 = 0;
        checkEndPointer6 = (unsigned char*)rawWord3;
        MATCHING_KEEP(checkEndPointer6);
    checkExecutableByte:
        temporaryWord4 = Actor44Field(privateRecord17, unsigned int*, 0x30);
        if (temporaryWord4 < (unsigned int)checkEndPointer6) {
            secondBitIndex4 = 0;
            Actor44Field(privateRecord17, int*, 0x34) =
                (int)(Actor44Field(privateRecord17, int*, 0x34) ^
                      (Actor44Field(temporaryWord4, unsigned char*, 0) << 8));
            do {
                rawWord3 = Actor44Field(privateRecord17, volatile int*, 0x34);
                rawWord2 = rawWord3 & 0x8000;
                if (rawWord2)
                    rawWord2 = (rawWord3 * 2) ^ 0x8005;
                else
                    rawWord2 = rawWord3 * 2;
                Actor44Field(privateRecord17, volatile int*, 0x34) = rawWord2;
                secondBitIndex4 += 1;
                rawWord2 = secondBitIndex4 < 8;
            } while (rawWord2);
            processedByteCount5 += 1;
            rawWord2 = Actor44Field(privateRecord17, volatile int*, 0x34);
            rawWord3 = Actor44Field(privateRecord17, int*, 0x30);
            rawWord2 = (rawWord2 & 3) + 1;
            rawWord3 += rawWord2;
            Actor44Field(privateRecord17, unsigned int*, 0x30) = rawWord3;
            temporaryWord5 = rawWord3;
            if (processedByteCount5 >= 0x40) {
                if (temporaryWord5 >= (unsigned int)&Actor44Datamain_TEXT_ENDView1) {
                    goto resetCheckPointer;
                }
            } else {
                goto checkExecutableByte;
            }
        } else {
        resetCheckPointer:
            Actor44Field(privateRecord17, unsigned int*, 0x30) =
                (unsigned int)&Actor44Call755ACView1;
        }
    }
    temporaryWord6 = Actor44Field(ownerRecord18, unsigned char*, 0x48);
    switch (temporaryWord6) {
        case 0:
            state0Predicate19 = 0;
            if ((Actor44Field(privateRecord17, unsigned char*, 0) == 2) &&
                (Actor44Data6C640View1 == 0) && (Actor44Data6C7B4View1 & 8)) {
                Actor44WriteFormattedOutputView1(&Actor44DebugTextView);
                goto deleteOwner;
            }
            if (Actor44Field(privateRecord17, unsigned char*, 0) == 0) {
                if ((Actor44Data6C640View1 == 0) &&
                    ((Actor44Data6C7B4View1 & 1) ||
                     (*(&Actor44Data70300View1 + Actor44Data6C58CView1) & 1))) {
                    Actor44MaskLinkedRecordFlagsByIdView1(0x12, 0xFC, 0);
                    goto deleteOwner;
                }
                if ((Actor44Field(privateRecord17, unsigned char*, 0) == 0) &&
                    (Actor44Field(ownerRecord18, unsigned char*, 0x49) == 0) &&
                    ((temporaryWord2 = Actor44QueryShiftedLinkedRecordWordByByteIdView1(
                          Actor44Field(privateRecord17, int*, 0x28)),
                      (((temporaryWord2 >> 8) & 0xFF) != 0)) ||
                     !(temporaryWord2 & 0xF))) {
                    Actor44Field(privateRecord17, signed char*, 5) = 1;
                    Actor44Field(privateRecord17, signed char*, 2) = 1;
                    Actor44Field(ownerRecord18, unsigned char*, 0x49) = 1U;
                    Actor44Field(ownerRecord18, unsigned char*, 0x46) =
                        (unsigned char)(Actor44Field(ownerRecord18, unsigned char*, 0x46) + 0x80);
                }
                goto checkState0Proximity;
            }
        checkState0Proximity:
            if ((Actor44Field(privateRecord17, unsigned char*, 0) == 2) &&
                (Actor44Data6C598View1 == 0) &&
                (Actor44AbsoluteByteAngleDeltaView1(
                     Actor44Field(ownerRecord18, unsigned char*, 0x46),
                     Actor44PlanarHeadingLookupView1(Actor44Field(&Actor44Data70328View1, int*, 0) -
                                                         Actor44Field(ownerRecord18, int*, 0xC),
                                                     Actor44Field(&Actor44Data70328View1, int*, 4) -
                                                         Actor44Field(ownerRecord18, int*, 0x10),
                                                     0)) >= 0x41)) {
                rawWord2 = Actor44Field(ownerRecord18, int*, 0x14);
                rawWord3 = Actor44Field(&Actor44Data70328View1, int*, 8);
                rawWord2 -= rawWord3;
                temporaryWord13 = rawWord2;
                if (temporaryWord13 < 0) {
                    temporaryWord13 = -temporaryWord13;
                }
                if (temporaryWord13 < 0x800) {
                    if (Actor44ApproximatePlanarDistanceView1(ownerRecord18 + 0xC,
                                                              &Actor44Data70328View1) < 0x1800) {
                        state0Predicate19 = 1;
                    }
                }
            }
            if ((state0Predicate19 == 1) ||
                (Actor44UpdateMobyInteractionGateView1(ownerRecord18, 0) != 0)) {
                if ((Actor44Field(privateRecord17, unsigned int*, 0) & 0xFF00FF) == 0x10000) {
                    Actor44Data6C7B4View1 |= 1;
                }
                Actor44StartDialogueView1(ownerRecord18, 0, 3);
                Actor44Field(ownerRecord18, unsigned char*, 0x48) = 3U;
                Actor44RequestMobyAnimationView1(ownerRecord18, 3);
                return;
            }
        case 27:
        case 28:
        default:
            return;
        case 3:
            if (Actor44Data6E344View1 != 1) {
                state3RawType19 = Actor44Field(privateRecord17, unsigned char*, 0);
                if (state3RawType19 == 2) {
                    temporaryWord7 = Actor44Field(privateRecord17, unsigned char*, 4);
                    if (temporaryWord7 == 1) {
                        firstPrivateBytePointer16 = privateRecord17 + 2;
                        Actor44Field(privateRecord17, signed char*, 2) = 4;
                        Actor44RegisterTrackedValueView1(firstPrivateBytePointer16, 1,
                                                         &Actor44Data6D088View1);
                        Actor44RegisterTrackedValueView1(firstPrivateBytePointer16, 1,
                                                         &Actor44Data6C7F8View1);
                        argumentWord4 = (int)ownerRecord18;
                        MATCHING_KEEP(argumentWord4);
                        rawWord3 = Actor44Field(privateRecord17, int*, 0x38);
                        __asm__ __volatile__("" ::: "$5", "memory");
                        argumentWord5 = 0;
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = Actor44Data6C550View1;
                        rawWord2 += rawWord3;
                        rawWord3 = 20;
                        Actor44Field(rawWord2, unsigned char*, 0x48) = rawWord3;
                        rawWord2 = 24;
                        Actor44Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                        __asm__ __volatile__("" ::: "$2", "memory");
                        rawWord2 = 255;
                        MATCHING_KEEP(rawWord2);
                        Actor44Field(argumentWord4, unsigned char*, 0x4A) = rawWord2;
                        Actor44RequestMobyAnimationView1(argumentWord4, argumentWord5);
                        Actor44Data71A04View1 = 1;
                        return;
                    }
                    secondPrivateBytePointer16 = privateRecord17 + 2;
                    if ((temporaryWord7 == 5) || (temporaryWord7 == state3RawType19)) {
                        Actor44Field(privateRecord17, signed char*, 2) = 3;
                        Actor44RegisterTrackedValueView1(secondPrivateBytePointer16, 1,
                                                         &Actor44Data6D088View1);
                        Actor44RegisterTrackedValueView1(secondPrivateBytePointer16, 1,
                                                         &Actor44Data6C7F8View1);
                        Actor44RequestMobyAnimationView1(ownerRecord18, 0);
                        Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0x1CU;
                        if (Actor44Field(privateRecord17, unsigned char*, 4) == state3RawType19) {
                            Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0x1AU;
                            return;
                        }
                    } else {
                        goto finishState3;
                    }
                } else {
                finishState3:
                    if ((Actor44Field(privateRecord17, unsigned char*, 0) == 0) &&
                        (Actor44Field(privateRecord17, unsigned char*, 4) == 2)) {
                        Actor44MaskLinkedRecordFlagsByIdView1(0x12, 0xFC, 0);
                        Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0x14U;
                        return;
                    }
                    Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0U;
                    Actor44RequestMobyAnimationView1(ownerRecord18, 0);
                    return;
                }
            }
            break;
        case 26:
            temporaryPointer1 =
                Actor44Data6C550View1 + (Actor44Field(privateRecord17, int*, 0x3C) * 0x58);
            if (Actor44Data74330View1(
                    temporaryPointer1 + 0xC,
                    (Actor44Field(temporaryPointer1, unsigned char*, 0x46) + 0x80) & 0xFF,
                    0) != 0) {
                Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0U;
                return;
            }
            break;
        case 20:
            rawWord2 = Actor44Field(privateRecord17, int*, 0x2C);
            rawWord3 = Actor44Field(rawWord2, int*, 0xC);
            rawWord2 = Actor44Field(ownerRecord18, int*, 0xC);
            argumentWord4 = Actor44Field(rawWord3, int*, 0);
            argumentWord4 -= rawWord2;
            originalFrame.sp20 = argumentWord4;
            MATCHING_BARRIER("memory");
            argumentWord5 = Actor44Field(rawWord3, int*, 4);
            rawWord2 = Actor44Field(ownerRecord18, int*, 0x10);
            argumentWord6 = 0;
            argumentWord5 -= rawWord2;
            originalFrame.sp24 = argumentWord5;
            rawWord2 = Actor44PlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
            __asm__ __volatile__("" ::"m"(originalFrame.sp24));
            argumentWord4 = (int)ownerRecord18;
            argumentWord5 = 2;
            __asm__("" ::"r"(argumentWord4), "r"(argumentWord5) : "$16", "memory");
            rawAngle16 = rawWord2;
            Actor44RequestMobyAnimationView1(argumentWord4, argumentWord5);
            if (Actor44TurnMobyTowardHeadingView1(ownerRecord18, rawAngle16, 6, 3, 1, 0) != 0) {
                Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0x16U;
                return;
            }
            break;
        case 22:
            if (!(Actor44UpdateMobyPathMotionView1(ownerRecord18,
                                                   Actor44Field(privateRecord17, void**, 0x2C),
                                                   0x78, 0x50, 0, 6, 2, 0) &
                  2))
                return;
        deleteOwner:
            Actor44DeleteMobyView1(ownerRecord18);
            return;
            break;
        case 24:
            if (Actor44Field(
                    ((Actor44Field(privateRecord17, int*, 0x38) * 0x58) + Actor44Data6C550View1),
                    unsigned char*, 0x48) == 0x1E) {
                Actor44Data71A04View1 = 0;
                Actor44Field(ownerRecord18, unsigned char*, 0x48) = 0U;
                Actor44RequestMobyAnimationView1(ownerRecord18, 0);
                rawWord2 = Actor44Data6C7B4View1;
                rawWord3 = Actor44Field(ownerRecord18, int*, 0);
                rawWord2 |= 8;
                Actor44Data6C7B4View1 = rawWord2;
                rawWord2 = 2;
                Actor44Field(rawWord3, unsigned char*, 5) = rawWord2;
                rawWord2 = Actor44Field(ownerRecord18, unsigned char*, 0x46);
                __asm__ __volatile__("" ::: "$16", "memory");
                vectorPointer16 = (void*)&originalFrame.sp28;
                MATCHING_KEEP(vectorPointer16);
                rawWord3 = Actor44Field(&Actor44Data65920View1, short*, rawWord2 * 2);
                argumentWord4 = (int)vectorPointer16;
                rawWord2 = (rawWord3 * 39) >> 6;
                originalFrame.sp28 = rawWord2;
                rawWord2 = Actor44Field(ownerRecord18, unsigned char*, 0x46);
                __asm__ __volatile__("" ::: "$5", "memory");
                argumentWord5 = (int)vectorPointer16;
                rawWord3 = Actor44Field(&Actor44Data658A0View1, short*, rawWord2 * 2);
                __asm__ __volatile__("" : "=r"(rawWord3) : "0"(rawWord3) : "$6", "memory");
                rawWord2 = Actor44Field(&Actor44Data70328View1, int*, 0x44);
                argumentWord6 = (int)ownerRecord18 + 0xC;
                originalFrame.sp30 = 0;
                originalFrame.sp30 = rawWord2;
                rawWord2 = (rawWord3 * 39) >> 6;
                originalFrame.sp2C = rawWord2;
                Actor44AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                Actor44SetCameraMode11TargetView1(
                    vectorPointer16,
                    (Actor44Field(ownerRecord18, unsigned char*, 0x46) + 0x80) & 0xFF, 0, 0x73);
                if (Actor44Field(&Actor44Data70328View1, int*, 0x280) < 0) {
                    Actor44Field(&Actor44Data70328View1, int*, 0x280) = 0;
                }
            }
            break;
    }
}
#undef Actor44Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_44/moby/func_level_44_800819BC.s SHA256 186a39c09cb3ac71cc4e924d070de4b8b1fc1ff157e5d534057206f0de20761b. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))


Moby* Controller819BCSpawn() __asm__("func_800391E8");
int Controller819BCUpdateMobyPrivateBallisticMotion() __asm__("func_80039714"); /* extern */
int Controller819BCRestoreOrClearTrackedSnapshot() __asm__("func_8003B74C");    /* extern */
int Controller819BCTransformVectorByBasis() __asm__("func_8004ED6C");           /* extern */
int Controller819BCClearVector() __asm__("func_8004F168");                      /* extern */
int Controller819BCApproximatePlanarDistance() __asm__("func_8004F334");        /* extern */
int Controller819BCDeleteMoby() __asm__("func_80055B18");                       /* extern */
int Controller819BCRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");   /* extern */
extern unsigned char Controller819BC_D_80065920 __asm__("D_80065920");
extern int Controller819BC_D_8006C574 __asm__("D_8006C574");
extern int Controller819BC_D_8006C578 __asm__("D_8006C578");
extern int Controller819BC_D_8006C58C __asm__("D_8006C58C");
extern unsigned char Controller819BC_D_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char Controller819BC_D_8006D088 __asm__("D_8006D088");
extern int Controller819BC_D_8006E020 __asm__("D_8006E020");
extern int Controller819BC_D_8006E024 __asm__("D_8006E024");
extern unsigned char Controller819BC_D_80070300 __asm__("D_80070300");
extern unsigned char Controller819BC_D_80070328 __asm__("D_80070328");
extern unsigned char Controller819BC_D_800716AC __asm__("D_800716AC");

void func_level_44_800819BC(Moby* inputOwner) {
    struct {
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
        Vector3D sp50;
        char pad_5c[4];
    } originalStack;

register Moby* owner17 __asm__("$17") = inputOwner;

    register Moby* child18 __asm__("$18");
    Moby* spawnedChild;
    Moby* spawnedActor;
    register int tableOffset4 __asm__("$4");
    register int phase4 __asm__("$4");
    register int spawnOrdinal7 __asm__("$7");
    register int random2 __asm__("$2");
    register int distance16 __asm__("$16");
    register int phase3 __asm__("$3");
    register int particleType5 __asm__("$5");
    register int spawnIndex16 __asm__("$16");
    register int particleIndex16 __asm__("$16");
    register int wrappedPhase2 __asm__("$2");
    register int heightDelta2 __asm__("$2");
    register signed char* particle3 __asm__("$3");
    register signed char* particleState3 __asm__("$3");
    register signed char* radialParticle3 __asm__("$3");
    register int savedYaw16 __asm__("$16");
    register int savedSubstate23 __asm__("$23");
    unsigned char state;
    unsigned char progressByte;
    int initialState;
    register void* childTag16 __asm__("$16");
    register void* tag20 __asm__("$20");
    register void* spawnTag22 __asm__("$22");
    register int constant21 __asm__("$21");
    register int constant19 __asm__("$19");
    register int constant18 __asm__("$18");
    register Vector3D* vector18 __asm__("$18");
    register Vector3D* vector19 __asm__("$19");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");

    MATCHING_KEEP(owner17);
    state = owner17->state;
    tag20 = owner17->mobyTag;
    if (state == 24) {
        M2C_FIELD(&Controller819BC_D_80070328, int*, 0x20C) =
            (int)(M2C_FIELD(&Controller819BC_D_80070328, int*, 0x20C) | 0x10000002);
        if (func_800359A4(tag20 + 8, 4) != 0) {
            if (!(Controller819BC_D_8006C7B4 & 2) &&
                !(*(&Controller819BC_D_80070300 + Controller819BC_D_8006C58C) & 2)) {
                value3 = Controller819BC_D_8006C58C;
                value2 = (value3 << 1) + value3;
                tableOffset4 = value2 << 1;
                progressByte = *(&Controller819BC_D_800716AC + 1 + tableOffset4);
                if (progressByte < 0xFFU) {
                    *(&Controller819BC_D_800716AC + 1 + tableOffset4) = progressByte + 1;
                }
            }
            Controller819BCRestoreOrClearTrackedSnapshot(&Controller819BC_D_8006D088);
            return;
        }
        return;
    } else if (state == 2) {
        child18 = M2C_FIELD(tag20, Moby**, 4);
        childTag16 = child18->mobyTag;
        func_800359A4(tag20 + 8, 4);
        if (owner17->substate == 0xA) {
            if (M2C_FIELD(tag20, int*, 0x10) == 0x16) {
                owner17->state = 0x18;
                return;
            }
            Controller819BCDeleteMoby(owner17);
            return;
        }
        child18->angle.yaw = func_8004E880(Controller819BC_D_8006E020 - owner17->position.x,
                                           Controller819BC_D_8006E024 - owner17->position.y, 0);
        if (M2C_FIELD(childTag16, short*, 0x14) < 3) {
            M2C_FIELD(childTag16, unsigned short*, 0) =
                (unsigned short)(M2C_FIELD(childTag16, unsigned short*, 0) + 0x32);
        }
        if (M2C_FIELD(childTag16, short*, 0x14) < 4) {
            M2C_FIELD(childTag16, unsigned short*, 0x16) =
                (unsigned short)(M2C_FIELD(childTag16, unsigned short*, 0x16) + 0x32);
        }
        M2C_FIELD(childTag16, unsigned short*, 2) =
            (unsigned short)(M2C_FIELD(childTag16, unsigned short*, 2) + 0x64);
        if (M2C_FIELD(childTag16, short*, 0x14) < 7) {
            func_8004F178(&originalStack.sp20, &owner17->position);
            value2 = func_8003636C(0, 200);
            value3 = originalStack.sp20.x;
            value3 -= 100;
            MATCHING_KEEP(value3);
            value3 += value2;
            originalStack.sp20.x = value3;
            value2 = func_8003636C(0, 200);
            value3 = originalStack.sp20.y;
            value3 -= 100;
            MATCHING_KEEP(value3);
            value3 += value2;
            originalStack.sp20.y = value3;
            originalStack.sp20.z += 0xC8;
            random2 = func_8003636C(0, 0xC8);
            originalStack.sp30 = 0;
            originalStack.sp34 = 0;
            originalStack.sp38 = 0;
            value3 = originalStack.sp20.z;
            value3 -= 100;
            MATCHING_KEEP(value3);
            value3 += random2;
            originalStack.sp20.z = value3;
            value2 = M2C_FIELD(childTag16, short*, 0x14);
            MATCHING_KEEP_CLOBBER(value2, "$4");
            argument4 = 1;
            if (value2 < 4) {
                MATCHING_BARRIER_VOLATILE("memory");
                particleType5 = 0;
            } else {
                MATCHING_BARRIER_VOLATILE("memory");
                particleType5 = 0xD;
            }
            particle3 = SpawnParticle(argument4, particleType5, &originalStack.sp20,
                                      (Vector3D*)&originalStack.sp30);
            if (particle3 != 0) {
                M2C_FIELD(particle3, signed char*, 0xA) = 0x64;
                return;
            }
        }
        return;
    } else if (state == 3) {
        if (M2C_FIELD(tag20, short*, 0xC) >= 0x15) {
            originalStack.sp40 = 0;
            originalStack.sp44 = 0;
            originalStack.sp48 = 0;
            particleState3 =
                SpawnParticle(1, 1, &owner17->position, (Vector3D*)&originalStack.sp40);
            if (particleState3 != 0) {
                M2C_FIELD(particleState3, signed char*, 0xA) = 0x64;
            }
        }
        Controller819BCUpdateMobyPrivateBallisticMotion(owner17);
        return;
    } else {
        if (owner17->substate == 0) {
            M2C_FIELD(tag20, int*, 0xC) = (int)owner17->position.z;
            initialState = owner17->state;
            owner17->substate = 1;
            if (initialState == 0x16) {
                owner17->substate = 0x16;
                owner17->state = 0x14;
                M2C_FIELD(tag20, int*, 0x10) = (int)initialState;
            }
        }
        if (owner17->state == 0x14) {
            phase3 = M2C_FIELD(tag20, int*, 8);
            phase4 = phase3 + 4;
            M2C_FIELD(tag20, int*, 8) = phase4;
            if (phase4 >= 0x100) {
                wrappedPhase2 = phase4;
                if (phase4 < 0) {
                    wrappedPhase2 = phase3 + 0x103;
                }
                wrappedPhase2 = phase4 - ((wrappedPhase2 >> 8) << 8);
                M2C_FIELD(tag20, int*, 8) = wrappedPhase2;
                owner17->position.z = (int)M2C_FIELD(tag20, int*, 0xC);
            }
            value2 = M2C_FIELD(&Controller819BC_D_80065920, unsigned short*,
                               M2C_FIELD(tag20, unsigned char*, 8) * 2);
            value3 = owner17->position.z;
            owner17->position.z = value3 + ((value2 << 16) >> 22);
        }
        distance16 = Controller819BCApproximatePlanarDistance(&owner17->position,
                                                              &Controller819BC_D_80070328);
        if ((distance16 < 0x1000) || (owner17->damageFlags != 0)) {
            func_80034F40(owner17, 1);
            argument6 = 0;
            if (owner17->damageFlags == 0) {
                value2 = distance16 < 0x398;
                if (value2) {
                    value3 = M2C_FIELD(&Controller819BC_D_80070328, int*, 8) - 600;
                    MATCHING_KEEP(value3);
                    heightDelta2 = owner17->position.z - value3;
                    if (heightDelta2 < 0) {
                        heightDelta2 = -heightDelta2;
                    }
                    if (heightDelta2 < 0x320) {
                        goto spawnChildren;
                    }
                }
            } else {
            spawnChildren:
                savedSubstate23 = owner17->substate;
                owner17->substate = 0x14;
                value3 = Controller819BC_D_8006E020;
                argument4 = owner17->position.x;
                value2 = Controller819BC_D_8006E024;
                argument5 = owner17->position.y;
                savedYaw16 = owner17->angle.yaw;
                argument4 = value3 - argument4;
                argument5 = value2 - argument5;
                owner17->angle.yaw = func_8004E880(argument4, argument5, argument6);
                owner17->position.z += 0x12C;
                spawnedChild = SpawnMoby(0x3F7, owner17);
                M2C_FIELD(tag20, Moby**, 4) = spawnedChild;
                if (spawnedChild != 0) {
                    spawnTag22 = spawnedChild->mobyTag;
                    spawnIndex16 = 0;
                    constant21 = 200;
                    constant19 = 256;
                    constant18 = 3;
                nextChild:
                    if ((Controller819BC_D_8006C578 - Controller819BC_D_8006C574) >= 0x15) {
                        argument5 = 598;
                        __asm__("" : "=r"(argument5) : "0"(argument5) : "$7", "$4", "$6");
                        argument4 = 1;
                        argument6 = (int)owner17;
                        MATCHING_KEEP2(argument4, argument6);
                        spawnOrdinal7 = spawnIndex16 + 2;
                        spawnedActor =
                            Controller819BCSpawn(argument4, argument5, argument6, spawnOrdinal7,
                                                 spawnOrdinal7, constant21, constant19);
                        if (spawnedActor != 0) {
                            spawnedActor->state = constant18;
                        }
                        spawnIndex16 += 1;
                        if (spawnIndex16 < 3) {
                            goto nextChild;
                        }
                    }
                    particleIndex16 = 0;
                    vector18 = (Vector3D*)&originalStack.sp40;
                    vector19 = &originalStack.sp50;
                    do {
                        owner17->angle.roll = particleIndex16 << 5;
                        originalStack.sp40 = 0;
                        originalStack.sp44 = 0x4E2;
                        originalStack.sp48 = 0;
                        Controller819BCRefreshMobySpatialGridAndBasis(owner17, 4);
                        Controller819BCTransformVectorByBasis(&owner17->rotationMatrix, vector18,
                                                              vector18);
                        func_8004F194(vector18, &owner17->position, vector18);
                        Controller819BCClearVector(vector19);
                        radialParticle3 = SpawnParticle(1, 0xD, vector18, vector19);
                        if (radialParticle3 != 0) {
                            M2C_FIELD(radialParticle3, signed char*, 0xA) = 0x3C;
                        }
                        MATCHING_KEEP(owner17);
                        particleIndex16 += 1;
                    } while (particleIndex16 < 8);
                    SpawnParticle(0x10, 0x46, &owner17->position, (Vector3D*)0x20);
                    M2C_FIELD(spawnTag22, short*, 2) = 0x190;
                    owner17->unknown3[0] = 0;
                    owner17->lowDrawDistance = 0;
                    owner17->drawn = 0;
                    owner17->unknownCollision = 0;
                    owner17->state = 2;
                    func_8003BABC(owner17, 0, 0);
                    M2C_FIELD(tag20, int*, 8) = 0x3C;
                } else {
                    owner17->angle.yaw = savedYaw16;
                    owner17->position.z -= 0x12C;
                }
                owner17->substate = savedSubstate23;
                return;
            }
        } else {
            func_80034F40(owner17, 0);
        }
        return;
    }
}
#undef M2C_FIELD

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 80082008..80082350. Original instructions define numeric branches.
 * Verified Crystal179 C supplies the discovery baseline; indirect extra arguments remain unknown. */
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern int D_8006C770, D_8006C774;
extern unsigned char* D_8006C54C;
extern unsigned char D_level_44_80093E5C[];
extern unsigned char D_80071573;
void func_level_44_80082008(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
    register int* tag __asm__("$17") = moby->mobyTag;
    int angle;
    if (moby->state != 3) {
        if (*(unsigned int*)((unsigned char*)moby + 0x18) & 0x10000) {
            tag[11] = 250;
            angle = *((unsigned char*)moby + 0x51);
            if (!angle)
                angle = func_800360F8(
                    func_8004E880(moby->position.x - *(int*)DecodedCrystalPlayer,
                                  moby->position.y - *(int*)(DecodedCrystalPlayer + 4), 0),
                    DecodedCrystalPlayer[14], 32, 64);
            tag[10] = angle;
            tag[12] = 140;
            SpawnMoby(16, moby);
            moby->state = 3;
            func_80034F40(moby, 3);
        } else if (*(unsigned int*)((unsigned char*)moby + 0x18) & 0x20000) {
            tag[11] = 300;
            angle = *((unsigned char*)moby + 0x51);
            if (!angle)
                angle = func_800360F8(
                    func_8004E880(moby->position.x - *(int*)DecodedCrystalPlayer,
                                  moby->position.y - *(int*)(DecodedCrystalPlayer + 4), 0),
                    DecodedCrystalPlayer[14], 32, 64);
            tag[10] = angle;
            tag[12] = 120;
            SpawnMoby(16, moby);
            moby->state = 3;
            func_80034F40(moby, 3);
        }
    }
    if (D_8006C54C - 1 == D_level_44_80093E5C && D_8006C774)
        D_80071573 = 1;
    switch (moby->state) {
        case 0:
        case 1:
            if (*((unsigned char*)moby + 0x4D) &&
                func_8004F334(&moby->position, (Vector3D*)DecodedCrystalPlayer) < 16384) {
                if (func_800359A4((char*)tag + 38, 2)) {
                    func_80034F40(moby, 1);
                    *(short*)((char*)tag + 38) = 120;
                } else if (func_800359A4((char*)tag + 36, 2)) {
                    if (D_8006C770) {
                        *(short*)((char*)tag + 36) = func_8003636C(3, 7);
                        moby->state = 2;
                        func_80034F40(moby, 2);
                    }
                } else if (D_8006C770)
                    func_80034F40(moby, 0);
            }
            break;
        case 2:
            func_80037168(moby, (Vector3D*)(tag + 3), 1);
            if (D_8006C770 && --*(short*)((char*)tag + 36) <= 0) {
                *(short*)((char*)tag + 36) = func_8003636C(30, 90);
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        case 3:
            func_80035030(moby, tag + 11, tag[10], tag + 12, 12, 16, 320, 1);
            if (D_8006C770) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 24);
                func_80055B18(moby);
            }
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80082354.
 * AI generated; not human reviewed. All969 native words and39 selector
 * entries must match:1008 owned words,with no padding. Frame78 (120 bytes)
 * saves S0..S5/RA at SP58..70. Local words occupy SP20..57;original vector
 * homes begin20/30/40 and the output steps home is50. Reserve contents are
 * never read. The eight-argument path call owns outgoing SP10..1C.
 * The39-entry state dispatch retains every original branch,fallthrough,
 * byte/halfword width,callback and timer check. Physical reset and shared
 * state-one entries stay distinct where the original control flow differs.
 * A snapshot of the path index precedes35A80;the path pointer is reloaded
 * after an initialized snapshot boundary. Its four outgoing words are
 * generated by the ordinary C call. There are no manual outgoing stores.
 * Both2DE constructors keep the actual returned owner and its private load.
 * Their S2/S4 roles reverse on disjoint paths;one C role per physical register
 * has sequential,nonoverlapping values. S1 is explicitly initialized to the
 * frame40 address before the second constructor's vector calls.
 * Original signed LH trig values use integer1125 with signed SRA9.
 * 32767*1125=36862875,SRA9=71997;-32768*1125=-36864000,SRA9=-72000.
 * The sole variable MULT forms the complete signed64 product of original
 * signed16 helper return doubled and55555556. The complete high word minus
 * the original sign gives signed division by3 toward zero. Vectors:
 * return00008001 narrows to-32767,doubles to-65534,quotient-21844;
 * return00007FFF doubles to65534,quotient21844;return-1 gives0.
 * The4F110 helper uses its two actual arguments;its initialized A2 vector
 * sample remains where original arithmetic needs it. 369B8 is a zero-input
 * callee whose original caller still establishes A0 owner and A1=38;the
 * old-style void caller view preserves these ignored original ABI values.
 * Every local read has an original dominating producer. No incoming saved
 * register,partial HILO input,fixed FP/SP or live fixed alias is used.
 * Empty metadata consumes complete initialized values/addresses or freshly
 * written original frame/field words;zero CPU instructions. Dead S1 is
 * clobbered only after its final original distance-call use. Full owner
 * identities separate vector phases and retain fresh original addresses.
 * Compiler,filter,flags,actual transfer/data-target checks and full EXE/all
 * overlay hashes remain unchanged and mandatory. Confidence after gates is
 * binary identity. Physical units,fixed-point domains,complete allocation,
 * caller/helper chains,cadence beyond invocation,Rev1 mapping and retail
 * runtime verification remain open. Next:human review,synchronized captures.
 */
/* Original assembly SHA256 ae7b0f342fb4334852ec21e9edb62842864105c24435bb2c93bcfbb6d80f22ab */
#define Level44_82354Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level44_82354MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level44_82354CaptureHigh(dst)                                       \
    do {                                                                    \
        int wholeCapturedHigh;                                              \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedHigh;                                          \
        Level44_82354Keep(dst);                                             \
    } while (0)
#define Level44_82354CaptureLow(dst)                                       \
    do {                                                                   \
        int wholeCapturedLow;                                              \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedLow;                                          \
        Level44_82354Keep(dst);                                            \
    } while (0)
#define Level44_82354Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_82354TestSubdividedSegmentPathView1(void*, void*, int) __asm__("func_80013E38");
int Level44_82354QueryWorldHeightView1(void*, int) __asm__("func_8001A358");
void Level44_82354RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level44_82354UpdateMobyMotionDescriptorView1(void*, void*) __asm__("func_80035194");
int Level44_82354TurnMobyTowardPlayerView1(void*, int, int, int) __asm__("func_8003573C");
int Level44_82354TurnMobyTowardHeadingView1(void*, int, int, int, int,
                                            int) __asm__("func_8003585C");
int Level44_82354CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level44_82354UpdateMobyPathMotionView1(void*, void*, int, int, int, int, int,
                                           int) __asm__("func_80035A80");
int Level44_82354ResolveMobyYawStepView1(void*, int, int, int, int) __asm__("func_80035DDC");
int Level44_82354TestPaddedRotatedBoxView1(void*, void*, int, int) __asm__("func_80036220");
int Level44_82354RandBetweenView1(int, int) __asm__("func_8003636C");
int Level44_82354ComputeArcVerticalVelocityView1(void*, void*, int, int,
                                                 int*) __asm__("func_800365E4");
void Level44_82354EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level44_82354SpawnMobyFromValueSelectorView1(void*, int, int, int) __asm__("func_80036A68");
void Level44_82354InitializeMobyMotionStateWithDecelerationView1(void*, void*, unsigned int,
                                                                 int) __asm__("func_80038F14");
void Level44_82354RegisterTrackedValueView1(void*, int, void*) __asm__("func_8003B7B4");
void Level44_82354MarkMobyCollectionBitView1(void*) __asm__("func_8003BA00");
int Level44_82354PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level44_82354ShiftVectorRightTowardZeroView1(void*, int) __asm__("func_8004F110");
void Level44_82354CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level44_82354AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
int Level44_82354AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level44_82354ApproximatePlanarDistanceView1(void*, void*) __asm__("func_8004F334");
void Level44_82354DeleteMobyView1(void*) __asm__("func_80055B18");
void Level44_82354RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
int Level44_82354ReadSelectedFrameScalarView1(void*) __asm__("func_80055E84");
void Level44_82354InterpolateMobyVertexView1(void*, int, void*) __asm__("func_80055F14");
void Level44_82354RefreshMobyPackedQueryFieldView1(void*) __asm__("func_8005629C");
extern int Level44_82354Data658A0View1 __asm__("D_800658A0");
extern int Level44_82354Data65920View1 __asm__("D_80065920");
extern int Level44_82354Data6C550View1 __asm__("D_8006C550");
extern int Level44_82354Data6C5C8View1 __asm__("D_8006C5C8");
extern int Level44_82354Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level44_82354Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level44_82354Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level44_82354Data6E020View1 __asm__("D_8006E020");
extern int Level44_82354Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level44_82354Data6E040View1 __asm__("D_8006E040");
extern int Level44_82354Data70328View1 __asm__("D_80070328");
extern int Level44_82354Data71908View1 __asm__("D_80071908");
extern void* (*Level44_82354DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
void func_level_44_80082354(void* ownerParameter) {
    register int pathIndexOrVectorOrPlayerAddress16 __asm__("$16"),
        playerOrFrameAddress17 __asm__("$17"), createdOwnerOrPrivate18 __asm__("$18"),
        owner19 __asm__("$19"), createdOwnerOrPrivate20 __asm__("$20"),
        privateRecord21 __asm__("$21");
    register int resultOrField2 __asm__("$2"), fieldOrIntermediate3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7"), capturedHigh8 __asm__("$8");
    long long completeSignedProduct;
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54;
    } originalFrame;
    short temp_v0_5;
    int temp_v1_5;
    int temp_a2;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_9;
    int temp_v1_3;
    int var_a1;
    int temp_v0_13;
    int temp_v0_2;
    int temp_a0_2;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_6;
    int temp_a0;
    int temp_v0_3;
    int temp_v1_4;
    int temp_v1_7;
    owner19 = (int)ownerParameter;
    Level44_82354Keep(owner19);
    temp_v1 = Level44_82354Field(owner19, unsigned char*, 0x48);
    privateRecord21 = Level44_82354Field(owner19, void**, 0);
    if (temp_v1 == 0x20) {
        goto block_3;
    }
    if (temp_v1 == 0x22) {
        goto block_4;
    }
    Level44_82354RefreshMobySpatialGridAndBasisView1(ownerParameter, 7);
block_3:
block_4:
    if (Level44_82354Field(owner19, unsigned char*, 0x48) == 6) {
        goto block_7;
    }
    if (!(Level44_82354Field(owner19, int*, 0x18) & 0x90000)) {
        goto block_7;
    }
    Level44_82354SpawnMobyFromValueSelectorView1(owner19, 1, 0, 0);
    Level44_82354InitializeMobyMotionStateWithDecelerationView1(owner19, privateRecord21 + 8, 2, 6);
block_7:
    temp_v1_2 = Level44_82354Field(owner19, unsigned char*, 0x48);
    if (temp_v1_2 >= 0x27U) {
        goto block_139;
    }
    switch (temp_v1_2) {
        case 33:
            Level44_82354Field(owner19, unsigned char*, 0x49) = 4U;
        case 30:
            if (Level44_82354Data6C7B4View1 & 8) {
                goto block_138;
            }
            Level44_82354Field(owner19, int*, 8) = 0;
            Level44_82354Field(owner19, signed char*, 0x41) = 0;
            Level44_82354Field(owner19, signed char*, 0x4C) = 0;
            Level44_82354Field(owner19, signed char*, 0x4D) = 0;
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x20U;
            temp_a0 = Level44_82354Field(privateRecord21, void**, 0x28);
            if (temp_a0 == 0) {
                goto block_139;
            }
            if (Level44_82354Field(temp_a0, short*, 0) != 1) {
                goto block_14;
            }
            Level44_82354Field(owner19, int*, 0x14) =
                (int)Level44_82354Field(Level44_82354Field(temp_a0, void**, 0xC), int*, 8);
            return;
        block_14:
            Level44_82354Field(owner19, unsigned char*, 0x49) = 2U;
            return;
        case 34:
            temp_v1_3 = Level44_82354Field(privateRecord21, int*, 0x48);
            var_a1 = 0;
            if (temp_v1_3 < 0) {
                goto block_21;
            }
            temp_v1_4 = Level44_82354Data6C550View1 + (temp_v1_3 * 0x58);
            temp_a0_2 = Level44_82354Field(temp_v1_4, unsigned char*, 0x48);
            temp_v1_5 = Level44_82354Field(temp_v1_4, short*, 0x36);
            if (temp_a0_2 & 0x80) {
                goto block_21;
            }
            if (temp_v1_5 != 0x25D) {
                goto block_19;
            }
            if (temp_a0_2 == 5) {
                goto block_21;
            }
        block_19:
            if (temp_v1_5 != 0x240) {
                goto block_22;
            }
            if (temp_a0_2 != 6) {
                goto block_22;
            }
        block_21:
            var_a1 = 1;
        block_22:
            if (var_a1 == 0) {
                goto block_139;
            }
            if (Level44_82354CountTimerDownView1(privateRecord21, 2) == 0) {
                goto block_139;
            }
            fieldOrIntermediate3 = 1;
            resultOrField2 = 32;
            Level44_82354Field(owner19, unsigned char*, 0x4C) = resultOrField2;
            resultOrField2 = 24;
            Level44_82354Field(owner19, unsigned char*, 0x41) = fieldOrIntermediate3;
            Level44_82354Field(owner19, unsigned char*, 0x4D) = fieldOrIntermediate3;
            Level44_82354Field(privateRecord21, short*, 0) = resultOrField2;
            temp_v1_6 = Level44_82354Field(owner19, unsigned char*, 0x49);
            if (temp_v1_6 == 2) {
                goto block_26;
            }
            if (temp_v1_6 != 4) {
                goto block_33;
            }
        block_26:
            resultOrField2 = Level44_82354Field(privateRecord21, int*, 40);
            if (!resultOrField2)
                goto block_29;
            resultOrField2 = Level44_82354Field(resultOrField2, short*, 0);
            argumentOrField4 = owner19;
            if (resultOrField2 < 2)
                goto block_29;
            Level44_82354Field(argumentOrField4, unsigned char*, 0x49) = 0;
            resultOrField2 = Level44_82354Field(privateRecord21, int*, 40);
            argumentOrField5 = 4;
            Level44_82354Field(resultOrField2, short*, 2) = 0;
            __asm__ volatile("" ::"r"(argumentOrField4),
                             "m"(Level44_82354Field(resultOrField2, short*, 2))
                             : "memory");
            fieldOrIntermediate3 = Level44_82354Field(privateRecord21, int*, 40);
            resultOrField2 = 1;
            Level44_82354Field(fieldOrIntermediate3, short*, 10) = resultOrField2;
            __asm__ volatile("" ::"m"(Level44_82354Field(fieldOrIntermediate3, short*, 10))
                             : "memory");
            resultOrField2 = 22;
            goto block_76;
        block_29:
            if (Level44_82354Field(owner19, unsigned char*, 0x49) != 4) {
                goto block_31;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 1U;
            Level44_82354RequestMobyAnimationView1(owner19, 1);
            Level44_82354Field(owner19, unsigned char*, 0x40) = 0xF0;
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x26U;
            Level44_82354Field(privateRecord21, short*, 2) = 0x3C;
            goto block_32;
        block_31:
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            Level44_82354RequestMobyAnimationView1(owner19, 0);
        block_32:
            Level44_82354Field(owner19, unsigned char*, 0x49) = 0U;
            return;
        block_33:
            Level44_82354Field(owner19, int*, 0x14) =
                (int)(Level44_82354Field(owner19, int*, 0x14) - 0xC00);
            Level44_82354RequestMobyAnimationView1(owner19, 5);
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x24U;
            return;
        case 38:
            Level44_82354TurnMobyTowardPlayerView1(owner19, 4, 2, 1);
            if (Level44_82354Data6C770View1 == 0) {
                goto block_36;
            }
            Level44_82354RequestMobyAnimationView1(owner19, 0);
        block_36:
            if (Level44_82354CountTimerDownView1(privateRecord21 + 2, 2) == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            goto block_80;
        case 36:
            Level44_82354Field(owner19, int*, 0x14) =
                (int)(Level44_82354Field(owner19, int*, 0x14) + 0x80);
            temp_v0_2 = Level44_82354Field(privateRecord21, unsigned short*, 0) - 1;
            Level44_82354Field(privateRecord21, unsigned short*, 0) = temp_v0_2;
            if ((temp_v0_2 << 0x10) > 0) {
                goto block_42;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            temp_v1_7 = Level44_82354Field(privateRecord21, void**, 0x28);
            if (temp_v1_7 == 0) {
                goto block_42;
            }
            if (Level44_82354Field(temp_v1_7, short*, 0) < 2) {
                goto block_42;
            }
            argumentOrField4 = owner19;
            argumentOrField5 = 4;
            fieldOrIntermediate3 = temp_v1_7;
            Level44_82354Field(fieldOrIntermediate3, short*, 2) = 0;
            __asm__ volatile("" ::"r"(argumentOrField4),
                             "m"(Level44_82354Field(fieldOrIntermediate3, short*, 2))
                             : "memory");
            resultOrField2 = Level44_82354Field(privateRecord21, int*, 40);
            fieldOrIntermediate3 = 1;
            Level44_82354Field(resultOrField2, short*, 10) = fieldOrIntermediate3;
            resultOrField2 = 22;
            goto block_76;
        block_42:
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
            goto block_81;
        case 28:
            if (Level44_82354Field(privateRecord21, void**, 0x28) == 0) {
                goto block_46;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x14U;
            return;
        block_46:
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x17U;
            return;
        case 26:
            if (Level44_82354TestPaddedRotatedBoxView1((int)&Level44_82354Data70328View1,
                                                       privateRecord21 + 0x2C, 0, 0x2800) != 0) {
                goto block_49;
            }
            if (Level44_82354ApproximatePlanarDistanceView1(
                    owner19 + 0xC, (int)&Level44_82354Data70328View1) >= 0x1800) {
                goto block_139;
            }
        block_49:
            Level44_82354Field(Level44_82354Field(privateRecord21, void**, 0x44), signed char*,
                               0x48) = 1;
            Level44_82354Field(owner19, signed char*, 0x41) = 1;
            Level44_82354Field(owner19, signed char*, 0x4C) = 0x2A;
            Level44_82354Field(owner19, signed char*, 0x4D) = 1;
            Level44_82354RefreshMobySpatialGridAndBasisView1(owner19, 7);
            temp_v0_3 = Level44_82354Field(privateRecord21, void**, 0x28);
            if (temp_v0_3 == 0) {
                goto block_51;
            }
            argumentOrField4 = owner19;
            argumentOrField5 = 5;
            resultOrField2 = temp_v0_3;
            Level44_82354Field(resultOrField2, short*, 2) = 0;
            __asm__ volatile("" ::"r"(argumentOrField4),
                             "m"(Level44_82354Field(resultOrField2, short*, 2))
                             : "memory");
            resultOrField2 = Level44_82354Field(privateRecord21, int*, 40);
            fieldOrIntermediate3 = 1;
            Level44_82354Field(resultOrField2, short*, 10) = fieldOrIntermediate3;
            resultOrField2 = 24;
            goto block_76;
        block_51:
            Level44_82354Field(owner19, unsigned char*, 0x48) = 5U;
            Level44_82354RequestMobyAnimationView1(owner19, 5);
            return;
        case 23:
            if (Level44_82354TestPaddedRotatedBoxView1((int)&Level44_82354Data70328View1,
                                                       privateRecord21 + 0x2C, 0, 0x2800) == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            goto block_80;
        case 20:
            if (Level44_82354TestPaddedRotatedBoxView1((int)&Level44_82354Data70328View1,
                                                       privateRecord21 + 0x2C, 0, 0x2800) == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x15U;
            Level44_82354RegisterTrackedValueView1(owner19 + 0x48, 1,
                                                   (int)&Level44_82354Data6C7F8View1);
        case 21:
            argumentOrField4 = owner19;
            resultOrField2 = Level44_82354Field(privateRecord21, int*, 40);
            argumentOrField5 = 4;
            Level44_82354Field(resultOrField2, short*, 2) = 0;
            __asm__ volatile("" ::"r"(argumentOrField4),
                             "m"(Level44_82354Field(resultOrField2, short*, 2))
                             : "memory");
            fieldOrIntermediate3 = Level44_82354Field(privateRecord21, int*, 40);
            resultOrField2 = 1;
            Level44_82354Field(fieldOrIntermediate3, short*, 10) = resultOrField2;
            resultOrField2 = 22;
            goto block_76;
        case 24:
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0x16U;
            Level44_82354RequestMobyAnimationView1(owner19, 4);
            return;
        case 5:
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            goto block_80;
        case 22:
            argumentOrField4 = owner19;
            argumentOrField6 = 120;
            resultOrField2 = Level44_82354Field(privateRecord21, int*, 40);
            fieldOrIntermediate3 = 4;
            pathIndexOrVectorOrPlayerAddress16 = Level44_82354Field(resultOrField2, short*, 2);
            resultOrField2 = 32;
            MATCHING_KEEP_VOLATILE_CLOBBER(pathIndexOrVectorOrPlayerAddress16, "memory");
            if (!(Level44_82354UpdateMobyPathMotionView1(
                      argumentOrField4, Level44_82354Field(privateRecord21, int*, 40),
                      argumentOrField6, 100, 0, fieldOrIntermediate3, resultOrField2,
                      fieldOrIntermediate3) &
                  2)) {
                goto block_65;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            Level44_82354RequestMobyAnimationView1(owner19, 0);
            if (Level44_82354AbsoluteByteAngleDeltaView1(
                    (int)(Level44_82354Data6E040View1 << 0x10) >> 0x14,
                    Level44_82354PlanarHeadingLookupView1(
                        Level44_82354Field(owner19, int*, 0xC) - Level44_82354Data6E020View1,
                        Level44_82354Field(owner19, int*, 0x10) - Level44_82354Data6E024View1,
                        0)) >= 0x18) {
                goto block_139;
            }
            Level44_82354Field(owner19, int*, 0x14) =
                (int)(Level44_82354Field(owner19, int*, 0x14) + 0x9F6);
            if (Level44_82354TestSubdividedSegmentPathView1(
                    owner19 + 0xC, (int)&Level44_82354Data70328View1, 0) == 0) {
                goto block_103;
            }
            goto block_101;
        block_65:
            argumentOrField4 = Level44_82354Field(privateRecord21, int*, 40);
            resultOrField2 = Level44_82354Field(argumentOrField4, short*, 2);
            resultOrField2 = (resultOrField2 == pathIndexOrVectorOrPlayerAddress16);
            if (resultOrField2)
                goto block_139;
            resultOrField2 = pathIndexOrVectorOrPlayerAddress16 * 16;
            fieldOrIntermediate3 = Level44_82354Field(argumentOrField4, int*, 12);
            resultOrField2 += fieldOrIntermediate3;
            fieldOrIntermediate3 = Level44_82354Field(resultOrField2, int*, 12);
            resultOrField2 = 1;
            if (fieldOrIntermediate3 != resultOrField2)
                goto block_139;
            resultOrField2 = 8;
            Level44_82354Field(owner19, unsigned char*, 0x48) = resultOrField2;
            Level44_82354RequestMobyAnimationView1(owner19, 8);
            return;
        case 8:
            argumentOrField6 = 0;
            fieldOrIntermediate3 = Level44_82354Field(privateRecord21, int*, 40);
            argumentOrField4 = Level44_82354Field(owner19, int*, 12);
            argumentOrField5 = Level44_82354Field(owner19, int*, 16);
            resultOrField2 = Level44_82354Field(fieldOrIntermediate3, short*, 2);
            fieldOrIntermediate3 = Level44_82354Field(fieldOrIntermediate3, int*, 12);
            resultOrField2 *= 16;
            resultOrField2 += fieldOrIntermediate3;
            fieldOrIntermediate3 = Level44_82354Field(resultOrField2, int*, 0);
            resultOrField2 = Level44_82354Field(resultOrField2, int*, 4);
            argumentOrField4 = fieldOrIntermediate3 - argumentOrField4;
            argumentOrField5 = resultOrField2 - argumentOrField5;
            resultOrField2 = Level44_82354PlanarHeadingLookupView1(
                argumentOrField4, argumentOrField5, argumentOrField6);
            Level44_82354TurnMobyTowardHeadingView1(owner19, resultOrField2, 4, 2, 1, 0);
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 9U;
            Level44_82354RequestMobyAnimationView1(owner19, 9);
            Level44_82354Field(privateRecord21, short*, 6) = 0x64;
            return;
        case 9:
            Level44_82354CopyVectorView1(&originalFrame.sp20, owner19 + 0xC);
            originalFrame.sp28 += 0x200;
            Level44_82354Field(owner19, int*, 0x14) =
                (int)(Level44_82354Field(owner19, int*, 0x14) +
                      Level44_82354Field(privateRecord21, short*, 6));
            temp_v0_5 = (unsigned short)Level44_82354Field(privateRecord21, short*, 6) - 0x10;
            Level44_82354Field(privateRecord21, short*, 6) = temp_v0_5;
            if (temp_v0_5 >= -0x190) {
                goto block_72;
            }
            Level44_82354Field(privateRecord21, short*, 6) = -0x190;
        block_72:
            Level44_82354ResolveMobyYawStepView1(owner19, 0x64, 0, 0, 0);
            if (Level44_82354Field(privateRecord21, short*, 6) >= 0) {
                goto block_139;
            }
            if (Level44_82354QueryWorldHeightView1(&originalFrame.sp20, 0x1000) == 0) {
                goto block_139;
            }
            if ((Level44_82354Field(owner19, int*, 0x14) - Level44_82354Data71908View1) >= 0x100) {
                goto block_139;
            }
            argumentOrField4 = owner19;
            argumentOrField5 = 10;
            resultOrField2 = 10;
            Level44_82354Field(argumentOrField4, int*, 20) = Level44_82354Data71908View1;
        block_76:
            Level44_82354Field(argumentOrField4, unsigned char*, 0x48) = resultOrField2;
            Level44_82354RequestMobyAnimationView1(argumentOrField4, argumentOrField5);
            return;
        case 10:
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
            if (Level44_82354AbsoluteByteAngleDeltaView1(
                    (int)(Level44_82354Data6E040View1 << 0x10) >> 0x14,
                    Level44_82354PlanarHeadingLookupView1(
                        Level44_82354Field(owner19, int*, 0xC) - Level44_82354Data6E020View1,
                        Level44_82354Field(owner19, int*, 0x10) - Level44_82354Data6E024View1, 0)) <
                0x18) {
                goto block_105;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
        block_80:
        block_81:
            Level44_82354RequestMobyAnimationView1(owner19, 0);
            return;
        case 0:
        case 1:
            pathIndexOrVectorOrPlayerAddress16 = (int)&originalFrame.sp30;
            argumentOrField4 = pathIndexOrVectorOrPlayerAddress16;
            Level44_82354Keep(argumentOrField4);
            playerOrFrameAddress17 = (int)&Level44_82354Data70328View1 + 152;
            Level44_82354CopyVectorView1(argumentOrField4, playerOrFrameAddress17);
            temp_a2 = originalFrame.sp34;
            originalFrame.sp30 *= 0x23;
            originalFrame.sp34 = temp_a2 * 0x23;
            originalFrame.sp38 *= 0x23;
            Level44_82354ShiftVectorRightTowardZeroView1(&originalFrame.sp30, 6);
            Level44_82354AddVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                        playerOrFrameAddress17 - 0x98);
            temp_v0_6 =
                Level44_82354ApproximatePlanarDistanceView1(owner19 + 0xC, &originalFrame.sp30);
            pathIndexOrVectorOrPlayerAddress16 = temp_v0_6;
            if (Level44_82354Field((int)&Level44_82354Data70328View1, int*, 0x24C) != 4) {
                goto block_84;
            }
            pathIndexOrVectorOrPlayerAddress16 = 0;
        block_84:
            if (pathIndexOrVectorOrPlayerAddress16 >= 0x4000) {
                goto block_86;
            }
            Level44_82354TurnMobyTowardPlayerView1(owner19, 4, 2, 1);
        block_86:
            if (Level44_82354Field(owner19, unsigned char*, 0x48) != 0) {
                goto block_89;
            }
            if (Level44_82354CountTimerDownView1(privateRecord21, 2) == 0) {
                goto block_89;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 1U;
            Level44_82354RequestMobyAnimationView1(owner19, 1);
            Level44_82354Field(owner19, unsigned char*, 0x40) = 0xF0;
        block_89:
            if (Level44_82354Field(owner19, unsigned char*, 0x48) != 1) {
                goto block_92;
            }
            if (Level44_82354Data6C770View1 == 0) {
                goto block_92;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 0U;
            Level44_82354RequestMobyAnimationView1(owner19, 0);
            Level44_82354Field(owner19, unsigned char*, 0x40) = 0xF0;
            Level44_82354Field(privateRecord21, unsigned short*, 0) =
                (unsigned short)(Level44_82354RandBetweenView1(0, 0x96) + 0xC8);
        block_92:
            if (Level44_82354Field(owner19, unsigned char*, 0x3D) == 1) {
                goto block_139;
            }
            if (Level44_82354CountTimerDownView1(privateRecord21 + 2, 2) == 0) {
                goto block_139;
            }
            resultOrField2 = pathIndexOrVectorOrPlayerAddress16 < 14000;
            MATCHING_OBSERVE2_VOLATILE(pathIndexOrVectorOrPlayerAddress16, resultOrField2);
            if (!resultOrField2) {
                goto block_139;
            }
            if (Level44_82354AbsoluteByteAngleDeltaView1(
                    (int)(Level44_82354Data6E040View1 << 0x10) >> 0x14,
                    Level44_82354PlanarHeadingLookupView1(
                        Level44_82354Field(owner19, int*, 0xC) - Level44_82354Data6E020View1,
                        Level44_82354Field(owner19, int*, 0x10) - Level44_82354Data6E024View1,
                        0)) >= 0x18) {
                goto block_139;
            }
            if (Level44_82354AbsoluteByteAngleDeltaView1(
                    (int)Level44_82354Field(owner19, unsigned char*, 0x46),
                    Level44_82354PlanarHeadingLookupView1(
                        Level44_82354Field((int)&Level44_82354Data70328View1, int*, 0) -
                            Level44_82354Field(owner19, int*, 0xC),
                        Level44_82354Field((int)&Level44_82354Data70328View1, int*, 4) -
                            Level44_82354Field(owner19, int*, 0x10),
                        0)) >= 0xA) {
                goto block_139;
            }
            Level44_82354Field(owner19, int*, 0x14) =
                (int)(Level44_82354Field(owner19, int*, 0x14) + 0x9F6);
            if (Level44_82354TestSubdividedSegmentPathView1(
                    owner19 + 0xC, (int)&Level44_82354Data70328View1, 0) == 0) {
                goto block_103;
            }
            if (temp_v0_6 >= 0xC00) {
                goto block_100;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 7U;
            argumentOrField4 = owner19;
            __asm__ volatile(""
                             : "=r"(argumentOrField4)
                             : "0"(argumentOrField4),
                               "m"(Level44_82354Field(owner19, unsigned char*, 0x48)));
            argumentOrField5 = 7;
            goto block_102;
        block_100:
        block_101:
            Level44_82354Field(owner19, unsigned char*, 0x48) = 3U;
            argumentOrField4 = owner19;
            argumentOrField5 = 3;
        block_102:
            Level44_82354Keep(argumentOrField4);
            Level44_82354RequestMobyAnimationView1(argumentOrField4, argumentOrField5);
        block_103:
            Level44_82354Field(owner19, int*, 0x14) =
                (int)(Level44_82354Field(owner19, int*, 0x14) - 0x9F6);
            return;
        case 2:
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
        block_105:
            Level44_82354Field(owner19, unsigned char*, 0x48) = 3U;
            Level44_82354RequestMobyAnimationView1(owner19, 3);
            return;
        case 7:
            temp_v0_7 = Level44_82354ReadSelectedFrameScalarView1(owner19);
            if (temp_v0_7 >= 0x20) {
                goto block_108;
            }
            Level44_82354TurnMobyTowardPlayerView1(owner19, 4, 2, 1);
        block_108:
            if ((unsigned int)(temp_v0_7 - 0x21) >= 6U) {
                goto block_112;
            }
            if (Level44_82354Field(owner19, unsigned char*, 0x49) != 0) {
                goto block_112;
            }
            createdOwnerOrPrivate20 = Level44_82354DataSpawnMobyView1(0x2DE, owner19);
            Level44_82354Keep(createdOwnerOrPrivate20);
            argumentOrField5 = 6;
            if (createdOwnerOrPrivate20 == 0) {
                goto block_112;
            }
            Level44_82354Keep(argumentOrField5);
            argumentOrField4 = owner19;
            Level44_82354Keep(argumentOrField4);
            pathIndexOrVectorOrPlayerAddress16 = createdOwnerOrPrivate20 + 12;
            argumentOrField6 = pathIndexOrVectorOrPlayerAddress16;
            createdOwnerOrPrivate18 = Level44_82354Field(createdOwnerOrPrivate20, int*, 0);
            resultOrField2 = 1;
            Level44_82354Field(owner19, unsigned char*, 0x49) = resultOrField2;
            Level44_82354InterpolateMobyVertexView1(argumentOrField4, argumentOrField5,
                                                    argumentOrField6);
            Level44_82354InterpolateMobyVertexView1(owner19, 7, &originalFrame.sp40);
            Level44_82354AddVectorView1(pathIndexOrVectorOrPlayerAddress16,
                                        pathIndexOrVectorOrPlayerAddress16, &originalFrame.sp40);
            Level44_82354ShiftVectorRightTowardZeroView1(pathIndexOrVectorOrPlayerAddress16, 1);
            Level44_82354Field(createdOwnerOrPrivate20, int*, 0x1C) =
                (int)(Level44_82354Field(createdOwnerOrPrivate20, int*, 0x1C) | 0x80000000);
            Level44_82354QueryWorldHeightView1(pathIndexOrVectorOrPlayerAddress16, 0x2800);
            Level44_82354RefreshMobyPackedQueryFieldView1(createdOwnerOrPrivate20);
            Level44_82354Field(createdOwnerOrPrivate20, unsigned char*, 0x46) =
                (unsigned char)Level44_82354Field(owner19, unsigned char*, 0x46);
            fieldOrIntermediate3 = Level44_82354Field(privateRecord21, int*, 32);
            resultOrField2 = 50;
            Level44_82354Field(createdOwnerOrPrivate18, short*, 2) = resultOrField2;
            resultOrField2 = 200;
            Level44_82354Field(createdOwnerOrPrivate18, int*, 4) = resultOrField2;
            resultOrField2 = -50;
            Level44_82354Field(createdOwnerOrPrivate18, short*, 0) = resultOrField2;
            Level44_82354Field(createdOwnerOrPrivate18, int*, 8) = fieldOrIntermediate3;
        block_112:
            resultOrField2 = Level44_82354Data6C770View1;
            argumentOrField4 = owner19;
            if (!resultOrField2)
                goto block_139;
            argumentOrField5 = 1;
            resultOrField2 = 1;
            Level44_82354Field(argumentOrField4, unsigned char*, 0x49) = 0;
            goto writeOriginalStateOne;
        case 3:
            temp_v0_9 = Level44_82354ReadSelectedFrameScalarView1(owner19);
            if (temp_v0_9 >= 0x1D) {
                goto block_116;
            }
            Level44_82354TurnMobyTowardPlayerView1(owner19, 4, 2, 1);
        block_116:
            if ((unsigned int)(temp_v0_9 - 0x1E) >= 9U) {
                goto block_126;
            }
            if (Level44_82354Field(owner19, unsigned char*, 0x49) != 0) {
                goto block_126;
            }
            createdOwnerOrPrivate18 = Level44_82354DataSpawnMobyView1(0x2DE, owner19);
            Level44_82354Keep(createdOwnerOrPrivate18);
            if (createdOwnerOrPrivate18 == 0) {
                goto block_126;
            }
            argumentOrField4 = owner19;
            Level44_82354Keep(argumentOrField4);
            argumentOrField5 = 6;
            Level44_82354Keep(argumentOrField5);
            pathIndexOrVectorOrPlayerAddress16 = createdOwnerOrPrivate18 + 12;
            argumentOrField6 = pathIndexOrVectorOrPlayerAddress16;
            createdOwnerOrPrivate20 = Level44_82354Field(createdOwnerOrPrivate18, int*, 0);
            resultOrField2 = 1;
            Level44_82354Field(owner19, unsigned char*, 0x49) = resultOrField2;
            Level44_82354InterpolateMobyVertexView1(argumentOrField4, argumentOrField5,
                                                    argumentOrField6);
            argumentOrField4 = owner19;
            argumentOrField5 = 7;
            Level44_82354Keep(argumentOrField5);
            playerOrFrameAddress17 = (int)&originalFrame.sp40;
            Level44_82354Keep(playerOrFrameAddress17);
            Level44_82354InterpolateMobyVertexView1(argumentOrField4, argumentOrField5,
                                                    playerOrFrameAddress17);
            Level44_82354AddVectorView1(pathIndexOrVectorOrPlayerAddress16,
                                        pathIndexOrVectorOrPlayerAddress16, playerOrFrameAddress17);
            Level44_82354ShiftVectorRightTowardZeroView1(pathIndexOrVectorOrPlayerAddress16, 1);
            Level44_82354Field(createdOwnerOrPrivate18, int*, 0x1C) =
                (int)(Level44_82354Field(createdOwnerOrPrivate18, int*, 0x1C) | 0x80000000);
            Level44_82354QueryWorldHeightView1(pathIndexOrVectorOrPlayerAddress16, 0x2800);
            Level44_82354RefreshMobyPackedQueryFieldView1(createdOwnerOrPrivate18);
            __asm__(""
                    : "=r"(createdOwnerOrPrivate18), "=r"(owner19)
                    : "0"(createdOwnerOrPrivate18), "1"(owner19), "m"(originalFrame.sp40));
            argumentOrField4 = playerOrFrameAddress17;
            pathIndexOrVectorOrPlayerAddress16 = (int)&Level44_82354Data70328View1 + 152;
            resultOrField2 = Level44_82354Field(owner19, unsigned char*, 0x46);
            argumentOrField5 = pathIndexOrVectorOrPlayerAddress16;
            Level44_82354Field(createdOwnerOrPrivate18, unsigned char*, 0x46) = resultOrField2;
            fieldOrIntermediate3 = Level44_82354Field(privateRecord21, int*, 32);
            resultOrField2 = 200;
            Level44_82354Field(createdOwnerOrPrivate20, int*, 4) = resultOrField2;
            Level44_82354Field(createdOwnerOrPrivate20, int*, 8) = fieldOrIntermediate3;
            Level44_82354CopyVectorView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = playerOrFrameAddress17;
            argumentOrField5 = 6;
            fieldOrIntermediate3 = originalFrame.sp40;
            argumentOrField6 = originalFrame.sp44;
            resultOrField2 = fieldOrIntermediate3 * 35;
            originalFrame.sp40 = resultOrField2;
            resultOrField2 = argumentOrField6 * 35;
            fieldOrIntermediate3 = originalFrame.sp48;
            originalFrame.sp44 = resultOrField2;
            resultOrField2 = fieldOrIntermediate3 * 35;
            originalFrame.sp48 = resultOrField2;
            Level44_82354ShiftVectorRightTowardZeroView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = playerOrFrameAddress17;
            argumentOrField5 = playerOrFrameAddress17;
            argumentOrField6 = pathIndexOrVectorOrPlayerAddress16 - 152;
            Level44_82354AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            __asm__("" : "=r"(owner19) : "0"(owner19), "m"(originalFrame.sp40));
            argumentOrField4 = owner19 + 12;
            argumentOrField5 = playerOrFrameAddress17;
            resultOrField2 =
                Level44_82354ApproximatePlanarDistanceView1(argumentOrField4, argumentOrField5);
            __asm__ volatile("" : "=r"(owner19) : "0"(owner19), "r"(resultOrField2) : "$17");
            argumentOrField4 = resultOrField2;
            resultOrField2 = argumentOrField4 < 5120;
            if (resultOrField2)
                resultOrField2 = 200;
            else
                resultOrField2 = 300;
            Level44_82354Field(createdOwnerOrPrivate20, short*, 2) = resultOrField2;
            fieldOrIntermediate3 =
                Level44_82354Field((int)&Level44_82354Data70328View1, int*, 0x24C);
            resultOrField2 = 4;
            if (fieldOrIntermediate3 == resultOrField2)
                goto block_124;
            resultOrField2 = argumentOrField4 < 9001;
            argumentOrField4 = createdOwnerOrPrivate18 + 12;
            if (resultOrField2)
                goto block_125;
            resultOrField2 = Level44_82354Field(owner19, unsigned char*, 0x46);
            resultOrField2 *= 2;
            fieldOrIntermediate3 =
                Level44_82354Field((int)&Level44_82354Data65920View1, short*, resultOrField2);
            MATCHING_KEEP_VOLATILE(fieldOrIntermediate3);
            argumentOrField4 = (int)&originalFrame.sp40;
            Level44_82354Keep(fieldOrIntermediate3);
            resultOrField2 = fieldOrIntermediate3 * 5;
            Level44_82354Keep(resultOrField2);
            fieldOrIntermediate3 = resultOrField2 * 16 - resultOrField2;
            Level44_82354Keep(fieldOrIntermediate3);
            resultOrField2 = fieldOrIntermediate3 * 16 - fieldOrIntermediate3;
            resultOrField2 >>= 9;
            originalFrame.sp40 = resultOrField2;
            __asm__("" : "=r"(owner19) : "0"(owner19), "m"(originalFrame.sp40));
            resultOrField2 = Level44_82354Field(owner19, unsigned char*, 0x46);
            Level44_82354Keep(resultOrField2);
            argumentOrField5 = owner19 + 12;
            resultOrField2 *= 2;
            fieldOrIntermediate3 =
                Level44_82354Field((int)&Level44_82354Data658A0View1, short*, resultOrField2);
            MATCHING_KEEP_VOLATILE(fieldOrIntermediate3);
            argumentOrField6 = argumentOrField4;
            originalFrame.sp48 = 0;
            __asm__(""
                    : "=r"(fieldOrIntermediate3)
                    : "0"(fieldOrIntermediate3), "m"(originalFrame.sp48));
            Level44_82354Keep(fieldOrIntermediate3);
            resultOrField2 = fieldOrIntermediate3 * 5;
            Level44_82354Keep(resultOrField2);
            fieldOrIntermediate3 = resultOrField2 * 16 - resultOrField2;
            Level44_82354Keep(fieldOrIntermediate3);
            resultOrField2 = fieldOrIntermediate3 * 16 - fieldOrIntermediate3;
            resultOrField2 >>= 9;
            originalFrame.sp44 = resultOrField2;
            Level44_82354AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        block_124:
            argumentOrField4 = createdOwnerOrPrivate18 + 12;
        block_125:
            argumentOrField5 = (int)&originalFrame.sp40;
            argumentOrField7 = -16;
            argumentOrField6 = Level44_82354Field(createdOwnerOrPrivate20, short*, 2);
            resultOrField2 = Level44_82354ComputeArcVerticalVelocityView1(
                argumentOrField4, argumentOrField5, argumentOrField6, argumentOrField7,
                &originalFrame.sp50);
            fieldOrIntermediate3 = 0x55555556;
            resultOrField2 = (int)(resultOrField2 << 16) >> 15;
            Level44_82354Keep(resultOrField2);
            Level44_82354MultiplyComplete(resultOrField2, fieldOrIntermediate3);
            resultOrField2 >>= 31;
            Level44_82354CaptureHigh(capturedHigh8);
            resultOrField2 = capturedHigh8 - resultOrField2;
            Level44_82354Field(createdOwnerOrPrivate20, short*, 0) = resultOrField2;
        block_126:
            if (Level44_82354Data6C770View1 == 0) {
                goto block_139;
            }
            Level44_82354Field(owner19, unsigned char*, 0x49) = 0U;
            temp_v0_13 = Level44_82354Field(privateRecord21, unsigned short*, 4) + 1;
            Level44_82354Field(privateRecord21, unsigned short*, 4) = temp_v0_13;
            if ((short)temp_v0_13 < 3) {
                goto block_130;
            }
        block_129:
            argumentOrField4 = owner19;
            argumentOrField5 = 1;
            resultOrField2 = 1;
        writeOriginalStateOne:
            Level44_82354Field(argumentOrField4, unsigned char*, 0x48) = resultOrField2;
            Level44_82354RequestMobyAnimationView1(argumentOrField4, argumentOrField5);
            Level44_82354Field(privateRecord21, short*, 2) = 0x3C;
            Level44_82354Field(privateRecord21, unsigned short*, 4) = 0U;
            return;
        block_130:
            if (Level44_82354ApproximatePlanarDistanceView1(
                    owner19 + 0xC, (int)&Level44_82354Data70328View1) >= 0xC00) {
                goto block_132;
            }
            Level44_82354Field(owner19, unsigned char*, 0x48) = 7U;
            Level44_82354RequestMobyAnimationView1(owner19, 7);
            return;
        block_132:
            Level44_82354Data6C770View1 = 0;
            Level44_82354Field(owner19, unsigned char*, 0x40) = 0xF0;
            return;
        case 6:
            if (Level44_82354UpdateMobyMotionDescriptorView1(owner19, privateRecord21 + 8) !=
                0x100) {
                goto block_139;
            }
            if (Level44_82354Data6C5C8View1 != 3) {
                goto block_136;
            }
            Level44_82354RefreshMobySpatialGridAndBasisView1(owner19, 4);
            goto block_137;
        block_136:
            Level44_82354RefreshMobySpatialGridAndBasisView1(owner19, 4);
            Level44_82354MarkMobyCollectionBitView1(owner19);
        block_137:
            Level44_82354EmitMobyVertexParticlesView1(owner19, 0x38);
        block_138:
            Level44_82354DeleteMobyView1(owner19);
        block_139:
            return;
        default:
            return;
    }
}
#undef Level44_82354Field

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 80083278..80083580. Rev1 raw608 discovery; original routes and reads
 * control C. S7 is inherited on early cleanup paths: its caller producer
 * is unknown and must not be replaced by zero. Empty output captures the
 * existing register without emitting instructions. Tag register allocation
 * is native; no explicit FP binding. Callback payload, units/cadence open. */
extern Moby* D_8006C550;
extern unsigned char DecodedDinoPlayer[] __asm__("D_80070328");
extern int D_80071900, D_80071904;
void func_8004F168(Vector3D*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
void* func_8001830C(Vector3D*, Vector3D*, int, int, int);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
void* func_8001C288(Vector3D*, int, int);
void func_800509E8(void*);
void func_level_44_80083278(Moby* mobyArgument) {
    Vector3D movement;
    int reserved24;
    Vector3D previous;
    int reserved34;
    register Moby* moby __asm__("$17") = mobyArgument;
    register Moby* dynamicResult __asm__("$19");
    register void* playerResult __asm__("$22");
    register void* staticResult __asm__("$23");
    register int speed __asm__("$18");
    register int radius __asm__("$20");
    register Vector3D* oldPosition __asm__("$21");
    register Vector3D* work __asm__("$16");
    register int* tag;
    MATCHING_KEEP(moby);
    dynamicResult = 0;
    MATCHING_KEEP(dynamicResult);
    tag = moby->mobyTag;
    playerResult = 0;
    if (moby->state == 0) {
        func_8004F178(&movement, &moby->position);
        {
            int delta = func_800363DC(0, 150);
            __asm__("" : : : "$18", "$20");
            {
                register int zero __asm__("$4") = 0;
                register int bound __asm__("$5") = 150;
                register int coordinate __asm__("$3");
                MATCHING_KEEP2(zero, bound);
                speed = 150;
                coordinate = *(volatile int*)&movement.x;
                radius = 128;
                coordinate += delta;
                MATCHING_KEEP(coordinate);
                movement.x = coordinate;
                movement.y += func_800363DC(zero, bound);
            }
        }
        movement.z += func_800363DC(0, 150);
        work = &previous;
        func_8004F168(work);
        SpawnParticle(1, 39, &movement, work);
    } else {
        MATCHING_BARRIER("$2");
        if (moby->state == 2) {
            speed = 400;
            radius = 128;
        } else {
            speed = 1024;
            radius = 256;
        }
    }
    oldPosition = &previous;
    {
        register Vector3D* prepared __asm__("$4") = oldPosition;
        MATCHING_KEEP_CLOBBER(prepared, "$16");
        work = &moby->position;
        func_8004F178(prepared, work);
    }
    func_80055D24(moby, 4);
    movement.x = speed;
    movement.y = 0;
    movement.z = 0;
    func_8004ED6C(&moby->rotationMatrix, &movement, &movement);
    func_8004F194(work, work, &movement);
    func_80055D24(moby, 2);
    __asm__ volatile("" : "=r"(staticResult));
    if (moby->position.x < 1024 || moby->position.y < 1024 || moby->position.z < 1024)
        goto cleanup;
    if (func_800359A4(tag, 4))
        goto cleanup;
    staticResult = func_8001830C(oldPosition, work, 3, 0, 0);
    {
        register Vector3D* prepared __asm__("$4") = work;
        if (staticResult)
            goto cleanup;
        MATCHING_KEEP3_VOLATILE(staticResult, dynamicResult, playerResult);
        dynamicResult = func_8001BA30(prepared, 256, 3, 0, 0x10000, &D_8006C550[moby->linkedMoby]);
    }
    if (dynamicResult)
        goto cleanup;
    playerResult = func_8001C288(work, radius, 7);
    if (!playerResult)
        return;
cleanup:
    if (playerResult) {
        *(int*)(DecodedDinoPlayer + 664) = moby->angle.yaw;
        moby->position.x = *(int*)DecodedDinoPlayer;
        MATCHING_BARRIER_VOLATILE("memory");
        moby->position.y = *(int*)(DecodedDinoPlayer + 4);
    } else if (dynamicResult) {
        dynamicResult->unkb = moby->angle.yaw;
        moby->position.x = dynamicResult->position.x;
        moby->position.y = dynamicResult->position.y;
    } else {
        MATCHING_KEEP(dynamicResult);
        if (staticResult) {
            func_8003BABC(moby, func_8003636C(0, 2), 0);
            moby->position.x = D_80071900;
            MATCHING_BARRIER_VOLATILE("memory");
            moby->position.y = D_80071904;
        }
    }
    func_800369B8(moby, 20);
    if (tag[1])
        func_800509E8((void*)tag[1]);
    func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_44/moby/func_level_44_80083584.s SHA256 9d5754116d3198bb1a158c8c23eeb3b5d16e708d60942b37d19b27567a2cde51. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller83584QueryWorldSegmentWithOptions() __asm__("func_8001830C");   /* extern */
int Controller83584QueryWorldSphereWithOptions() __asm__("func_80019138");    /* extern */
int Controller83584QueryWorldHeight() __asm__("func_8001A358");               /* extern */
void* Controller83584QueryDynamicMobyGeometry() __asm__("func_8001BA30");     /* extern */
int Controller83584TestPlayerSphereOverlap() __asm__("func_8001C288");        /* extern */
int Controller83584TransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Controller83584ClearVector() __asm__("func_8004F168");                    /* extern */
int Controller83584ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller83584DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller83584RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller83584InterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
int Controller83584RefreshMobyPackedQueryField() __asm__("func_8005629C");    /* extern */
extern unsigned char Controller83584_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller83584_D_80065920 __asm__("D_80065920");
extern int Controller83584_D_8006C550 __asm__("D_8006C550");
extern int Controller83584_D_8006E020 __asm__("D_8006E020");
extern int Controller83584_D_8006E024 __asm__("D_8006E024");
extern unsigned char Controller83584_D_80070328 __asm__("D_80070328");
extern int Controller83584_D_80071918 __asm__("D_80071918");
extern int Controller83584_D_8007191C __asm__("D_8007191C");
extern int Controller83584_D_80071920 __asm__("D_80071920");

void func_level_44_80083584(Moby* inputOwner) {
    struct {
        int sp18;
        int sp1C;
        int sp20;
        char pad_24[4];
        int sp28;
        int sp2C;
        int sp30;
        char pad_34[4];
        Vector3D sp38;
        char pad_44[4];
        int sp48;
        int sp4C;
        int sp50;
        char pad_54[4];
        Vector3D sp58;
        char pad_64[4];
    } originalStack;

    register Moby* owner16 __asm__("$16") = inputOwner;

    register int queryRadius19 __asm__("$19");
    register Moby* linked17 __asm__("$17");
    register Vector3D* position18 __asm__("$18");
    register Vector3D* position19 __asm__("$19");
    short fallVelocity;
    int floorZ;
    register int particleIndex18 __asm__("$18");
    register int queryHit20 __asm__("$20");
    register int queryHit21 __asm__("$21");
    register int ratio2 __asm__("$2");
    register int otherRatio2 __asm__("$2");
    register signed char* particle3 __asm__("$3");
    unsigned char state;
    unsigned char linkedIndex;
    unsigned char unusedLinkedIndex;
    register void* tag17 __asm__("$17");
    register void* queried17 __asm__("$17");
    register void* queried18 __asm__("$18");
    register Vector3D* previous22 __asm__("$22");
    register Vector3D* vector17 __asm__("$17");
    register Vector3D* vector19 __asm__("$19");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");

    MATCHING_KEEP(owner16);
    state = owner16->state;
    tag17 = owner16->mobyTag;
    if (state == 0)
        goto updateState0;
    linked17 = 0;
    if (state == 1)
        goto updateState1;
    return;
updateState0:
    previous22 = &originalStack.sp38;
    argument4 = (int)previous22;
    MATCHING_KEEP_CLOBBER(argument4, "$19");
    position19 = &owner16->position;
    func_8004F178((Vector3D*)argument4, position19);
    originalStack.sp18 =
        (int)(M2C_FIELD(&Controller83584_D_80065920, short*, (owner16->angle.yaw * 2)) *
              M2C_FIELD(tag17, short*, 2)) >>
        0xC;
    queryHit20 = 0;
    originalStack.sp1C =
        (int)(M2C_FIELD(&Controller83584_D_800658A0, short*, (owner16->angle.yaw * 2)) *
              M2C_FIELD(tag17, short*, 2)) >>
        0xC;
    originalStack.sp20 = 0;
    func_8004F194(position19, position19, (Vector3D*)&originalStack.sp18);
    owner16->angle.pitch -= 8;
    owner16->angle.roll += 4;
    queryHit21 = 0;
    owner16->position.z += M2C_FIELD(tag17, short*, 0);
    fallVelocity = (unsigned short)M2C_FIELD(tag17, short*, 0) - 0x10;
    M2C_FIELD(tag17, short*, 0) = fallVelocity;
    queried18 = 0;
    if (fallVelocity < -0x1F4) {
        M2C_FIELD(tag17, short*, 0) = -0x1F4;
    }
    Controller83584QueryWorldHeight(position19, 0x2800);
    Controller83584RefreshMobyPackedQueryField(owner16);
    Controller83584RefreshMobySpatialGridAndBasis(owner16, 7);
    Controller83584InterpolateMobyVertex(owner16, 0, &originalStack.sp18);
    originalStack.sp28 = 0;
    originalStack.sp2C = 0;
    originalStack.sp30 = 0x1E;
    SpawnParticle(1, 0xD, (Vector3D*)&originalStack.sp18, (Vector3D*)&originalStack.sp28);
    MATCHING_KEEP3(queryHit20, queryHit21, queried18);
    if ((func_800359A4(tag17 + 4, 4) != 0) || (owner16->damageFlags != 0) ||
        (owner16->position.z < 0x400) || (owner16->position.x < 0x400) ||
        (owner16->position.y < 0x400) ||
        (queryHit20 =
             Controller83584QueryWorldSegmentWithOptions(previous22, position19, 3, 0, owner16),
         (queryHit20 != 0)) ||
        (queryHit20 = ({
             argument4 = (int)position19;
             MATCHING_KEEP2(argument4, queryHit20);
             Controller83584QueryWorldSphereWithOptions((Vector3D*)argument4, 0x12C, 1, 0, 0, 0);
         }),
         (queryHit20 != 0)) ||
        (queried18 = ({
             argument4 = (int)position19;
             MATCHING_KEEP2(argument4, queryHit20);
             Controller83584QueryDynamicMobyGeometry((Vector3D*)argument4, 0x100, 1, 0, 0x30000,
                                                     owner16);
         }),
         (queried18 != 0)) ||
        (queryHit21 = Controller83584TestPlayerSphereOverlap(position19, 0x80, 7),
         (queryHit21 != 0))) {
        if (queryHit21 == 0) {
            MATCHING_KEEP(queryHit21);
            if (queried18 != 0) {
                owner16->unkb =
                    func_8004E880(M2C_FIELD(queried18, int*, 0xC) - owner16->position.x,
                                  M2C_FIELD(queried18, int*, 0x10) - owner16->position.y, 0);
                linkedIndex = owner16->linkedMoby;
                if ((linkedIndex != 0xFF) &&
                    (queried18 == (Controller83584_D_8006C550 + (linkedIndex * 0x58)))) {
                    M2C_FIELD(queried18, int*, 0x18) = 0;
                    return;
                }
                goto checkQueryHits;
            }
            goto checkFloor;
        }
        M2C_FIELD(&Controller83584_D_80070328, int*, 0x298) =
            func_8004E880(M2C_FIELD(&Controller83584_D_80070328, int*, 0) - owner16->position.x,
                          M2C_FIELD(&Controller83584_D_80070328, int*, 4) - owner16->position.y, 0);
    checkQueryHits:
        if (queried18 == 0) {
        checkFloor:
            if (queryHit21 == 0) {
                if ((queryHit20 != 0) && (Controller83584_D_80071920 > 0)) {
                    ratio2 =
                        (int)(Controller83584_D_80071918 * 0x64) / (int)Controller83584_D_80071920;
                    if (ratio2 < 0) {
                        ratio2 = -ratio2;
                    }
                    if (ratio2 < 0xE) {
                        otherRatio2 = (int)(Controller83584_D_8007191C * 0x64) /
                                      (int)Controller83584_D_80071920;
                        if (otherRatio2 < 0) {
                            otherRatio2 = -otherRatio2;
                        }
                        if (otherRatio2 < 0xE) {
                            goto resetAngles;
                        }
                        goto updateAngles;
                    }
                    goto updateAngles;
                }
                goto updateAngles;
            } else {
                goto resetAngles;
            }
        } else {
            goto resetAngles;
        }
    resetAngles:
        floorZ = func_80035D38(owner16);
        owner16->angle.roll = 0;
        owner16->angle.pitch = 0;
        owner16->angle.yaw = 0;
        owner16->position.z = floorZ;
        goto enterState1;
    updateAngles:
        argument4 = Controller83584ApproximatePlanarDistance(&owner16->position,
                                                             &Controller83584_D_80070328);
        value2 = M2C_FIELD(&Controller83584_D_80070328, int*, 8);
        argument5 = owner16->position.z - 200;
        owner16->angle.roll = 0x40 - func_8004E880(argument4, value2 - argument5, 0);
        owner16->angle.pitch = 0;
        owner16->angle.yaw = func_8004E880(Controller83584_D_8006E020 - owner16->position.x,
                                           Controller83584_D_8006E024 - owner16->position.y, 0);
    enterState1:
        owner16->state = 1;
        linked17 = 0;
    updateState1:
        func_8003BABC(owner16, 0, 0);
        value3 = owner16->linkedMoby;
        MATCHING_KEEP(value3);
        if (value3 != 0xFF) {
            value2 = ((value3 * 3 << 2) - value3);
            MATCHING_KEEP(value2);
            value2 <<= 3;
            value3 = Controller83584_D_8006C550;
            linked17 = (Moby*)(value3 + value2);
        }
        queryRadius19 = 0x514;
        if (M2C_FIELD(&Controller83584_D_80070328, int*, 0x24C) == 4) {
            queryRadius19 = 0xBB8;
        }
        position18 = &owner16->position;
        queried17 =
            Controller83584QueryDynamicMobyGeometry(position18, 0x800, 1, 0, 0x30000, linked17);
        if (queried17 != 0) {
            M2C_FIELD(queried17, signed char*, 0x51) =
                func_8004E880(M2C_FIELD(queried17, int*, 0xC) - owner16->position.x,
                              M2C_FIELD(queried17, int*, 0x10) - owner16->position.y, 0);
        } else if (Controller83584TestPlayerSphereOverlap(position18, queryRadius19, 7) != 0) {
            MATCHING_KEEP(linked17);
            M2C_FIELD(&Controller83584_D_80070328, int*, 0x298) = func_8004E880(
                M2C_FIELD(&Controller83584_D_80070328, int*, 0) - owner16->position.x,
                M2C_FIELD(&Controller83584_D_80070328, int*, 4) - owner16->position.y, 0);
        }
        Controller83584RefreshMobySpatialGridAndBasis(owner16, 4);
        argument4 = 1005;
        argument5 = (int)owner16;
        __asm__(""
                : "=r"(argument4), "=r"(argument5)
                : "0"(argument4), "1"(argument5)
                : "$17", "$19");
        particleIndex18 = 0;
        vector17 = (Vector3D*)&originalStack.sp48;
        vector19 = &originalStack.sp58;
        SpawnMoby(argument4, (Moby*)argument5);
        owner16->angle.roll = 0;
        owner16->angle.pitch = 0;
        do {
            owner16->angle.yaw = particleIndex18 << 5;
            originalStack.sp48 = 0x400;
            originalStack.sp4C = 0;
            originalStack.sp50 = 0;
            Controller83584RefreshMobySpatialGridAndBasis(owner16, 4);
            Controller83584TransformVectorByBasis(&owner16->rotationMatrix, vector17, vector17);
            func_8004F194(vector17, &owner16->position, vector17);
            Controller83584ClearVector(vector19);
            particle3 = SpawnParticle(1, 0x37, vector17, vector19);
            if (particle3 != 0) {
                M2C_FIELD(particle3, signed char*, 0xA) = 0x3C;
            }
            MATCHING_KEEP(owner16);
            particleIndex18 += 1;
        } while (particleIndex18 < 8);
        Controller83584DeleteMoby(owner16);
    }
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_44/moby/func_level_44_80083C00.s SHA256 e21bff26f7aae81881ce020bb47b8ff58ea241ff0e224c9d969fba7b88bee5af. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller83C00SetMobyAnimation() __asm__("func_80034F80");               /* extern */
int Controller83C00SpawnMobyFromValueSelector() __asm__("func_80036A68");     /* extern */
int Controller83C00MarkMobyCollectionBit() __asm__("func_8003BA00");          /* extern */
int Controller83C00DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller83C00RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller83C00InterpolateMobyVertex() __asm__("func_80055F14");          /* extern */
int Controller83C00_rand() __asm__("rand");                                   /* extern */
extern unsigned char Controller83C00_D_80067648 __asm__("D_80067648");
extern int Controller83C00_D_8006C54C __asm__("D_8006C54C");
extern int Controller83C00_D_8006C574 __asm__("D_8006C574");
extern int Controller83C00_D_8006C578 __asm__("D_8006C578");
extern int Controller83C00_D_8006C640 __asm__("D_8006C640");
extern int Controller83C00_D_8006C648 __asm__("D_8006C648");
extern unsigned char Controller83C00_D_80070328 __asm__("D_80070328");

void func_level_44_80083C00(Moby* inputOwner) {
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
        char pad_3c[12];
    } originalStack;

    register Moby* owner18 __asm__("$18") = inputOwner;

    register Moby* child16 __asm__("$16");
    register int timer2 __asm__("$2");
    short quotient;
    short timer3;
    register int* table4 __asm__("$4");
    register int weight16 __asm__("$16");
    register int state19 __asm__("$19");
    register int offset2 __asm__("$2");
    register int tableValue3 __asm__("$3");
    register int weight3 __asm__("$3");
    register Vector3D* vector19 __asm__("$19");
    register int height16 __asm__("$16");
    register int spawn17 __asm__("$17");
    register int particle17 __asm__("$17");
    register int slot17 __asm__("$17");
    register int height20 __asm__("$20");
    unsigned short unusedTimer;
    register int unusedValue __asm__("$3");
    register int shiftedTimer3 __asm__("$3");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int signed4 __asm__("$4");
    register int remainder4 __asm__("$4");
    register int product3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register Vector3D* argument6 __asm__("$6");
    register int yProduct6 __asm__("$6");
    register int xProduct9 __asm__("$9");
    unsigned char state;
    register int alpha2 __asm__("$2");
    register void* tag16 __asm__("$16");

    MATCHING_KEEP(owner18);
    state = owner18->state;
    tag16 = owner18->mobyTag;
    switch (state) { /* Original states 0 and 1. */
        case 0:
            if (owner18->damageFlags & 0x10000) {
                M2C_FIELD(tag16, unsigned short*, 4) = 0U;
                M2C_FIELD(tag16, unsigned short*, 0xA) = func_8004E880(
                    owner18->position.x - M2C_FIELD(&Controller83C00_D_80070328, int*, 0),
                    owner18->position.y - M2C_FIELD(&Controller83C00_D_80070328, int*, 4), 0);
                owner18->colour.a = 0x30;
                owner18->colour.r = 0;
                owner18->colour.g = 0;
                owner18->colour.b = 0;
                Controller83C00RefreshMobySpatialGridAndBasis(owner18, 4);
                func_8003BABC(owner18, 0, 0);
                if (owner18->damageFlags & 0x100000) {
                    M2C_FIELD(tag16, unsigned short*, 4) = 0x3CU;
                }
                owner18->state = 1;
            }
            if (owner18->damageFlags & 0x20000) {
                M2C_FIELD(tag16, unsigned short*, 4) = 1U;
                func_8003BABC(owner18, 2, 0);
            }
            owner18->damageFlags = 0;
            timer2 = M2C_FIELD(tag16, short*, 4);
            if (timer2 != 0) {
                value3 = timer2;
                MATCHING_KEEP(value3);
                value2 = value3 + Controller83C00_D_8006C648;
                value3 = value2 << 16;
                MATCHING_KEEP(value3);
                M2C_FIELD(tag16, unsigned short*, 4) = value2;
                if ((value3 >> 16) < 0x40) {
                    value2 = value3 >> 17;
                    MATCHING_KEEP(value2);
                    owner18->angle.roll =
                        M2C_FIELD(value2 * 2 + M2C_FIELD(tag16, int*, 0), unsigned char*, 0) +
                        M2C_FIELD(tag16, unsigned char*, 6);
                    owner18->angle.pitch =
                        M2C_FIELD(
                            ((((int)(M2C_FIELD(tag16, unsigned short*, 4) << 0x10) >> 0x11) * 2) +
                             M2C_FIELD(tag16, int*, 0)),
                            unsigned char*, 1) +
                        M2C_FIELD(tag16, unsigned char*, 8);
                    return;
                }
                M2C_FIELD(tag16, unsigned short*, 4) = 0U;
                owner18->angle.roll = M2C_FIELD(tag16, unsigned short*, 6);
                owner18->angle.pitch = M2C_FIELD(tag16, unsigned short*, 8);
                return;
            }
            return;
        case 1:
            if ((Controller83C00_D_8006C640 != 0) && (Controller83C00_D_8006C54C == 0)) {
                value2 = Controller83C00_rand();
                remainder4 = value2 / 40;
                MATCHING_KEEP(remainder4);
                value3 = remainder4 * 40;
                remainder4 = value2 - value3;
                MATCHING_KEEP(remainder4);
                value3 = (int)&Controller83C00_D_80067648;
                value2 = remainder4 * 4;
                table4 = (int*)(value2 + value3);
                tableValue3 = *table4;
                if (tableValue3 >= 0x2801) {
                    value2 = tableValue3 - 0x40;
                    *table4 = value2;
                }
            }
            value2 = Controller83C00_D_8006C648;
            shiftedTimer3 = M2C_FIELD(tag16, unsigned short*, 4) + value2;
            M2C_FIELD(tag16, unsigned short*, 4) = shiftedTimer3;
            MATCHING_BARRIER("memory");
            shiftedTimer3 <<= 16;
            signed4 = shiftedTimer3 >> 16;
            if (signed4 >= 0x3C) {
                Controller83C00SpawnMobyFromValueSelector(owner18, 1, 0, 0);
                spawn17 = 0;
                height20 = -0x460;
                owner18->angle.yaw = (unsigned char)M2C_FIELD(tag16, unsigned short*, 0xA);
            nextChild:
                if ((Controller83C00_D_8006C578 - Controller83C00_D_8006C574) >= 0x15) {
                    child16 = SpawnMoby(0x2E4, owner18);
                    if (child16 != 0) {
                        state19 = func_8003636C(0, 2);
                        if (spawn17 < 4) {
                            Controller83C00InterpolateMobyVertex(owner18, spawn17,
                                                                 &child16->position);
                        } else {
                            value2 = child16->position.z + 0x96;
                            MATCHING_KEEP(value2);
                            child16->position.z = value2 + height20;
                            child16->position.x += func_800363DC(0, 0x46);
                            child16->position.y += func_800363DC(0, 0x46);
                        }
                        Controller83C00SetMobyAnimation(child16, state19);
                    }
                    spawn17 += 1;
                    height20 += 0x118;
                    if (spawn17 < 0xA) {
                        goto nextChild;
                    }
                }
                particle17 = 0;
                height16 = 0;
                do {
                    func_8004F178((Vector3D*)&originalStack.sp10, &owner18->position);
                    offset2 = func_800363DC(0, 0xC8);
                    argument4 = 0;
                    argument5 = 300;
                    MATCHING_OBSERVE2(argument4, argument5);
                    offset2 += 300;
                    MATCHING_KEEP(offset2);
                    offset2 = height16 + offset2;
                    height16 += 0x3C;
                    originalStack.sp18 += offset2;
                    originalStack.sp10 += func_800363DC(argument4, argument5);
                    particle17 += 1;
                    originalStack.sp14 += func_800363DC(0, 0x12C);
                    originalStack.sp20 = Controller83C00_rand() & 0xF;
                    originalStack.sp24 = Controller83C00_rand() & 0xF;
                    originalStack.sp28 = 0x14;
                    SpawnParticle(1, 1, (Vector3D*)&originalStack.sp10,
                                  (Vector3D*)&originalStack.sp20);
                } while (particle17 < 0x20);
                func_8003BABC(owner18, 1, 0);
                Controller83C00MarkMobyCollectionBit(owner18);
                Controller83C00DeleteMoby(owner18);
                return;
            }
            value2 = (short)(signed4 / 5);
            value3 = (short)value2;
            if (value3 >= 0x10) {
                value3 = 0xF;
                MATCHING_KEEP(value3);
            }
            alpha2 = value3 + 0x30;
            owner18->colour.a = alpha2;
            timer3 = (short)M2C_FIELD(tag16, unsigned short*, 4);
            if ((timer3 < 0x28) &&
                ((slot17 = 0, ((timer3 < 0x14) != 0)) || (Controller83C00_D_8006C640 & 1))) {
                vector19 = (Vector3D*)&originalStack.sp20;
                do {
                    value2 = Controller83C00_rand();
                    argument4 = (int)owner18;
                    argument5 = slot17;
                    argument6 = vector19;
                    weight16 = value2 & 0xF;
                    Controller83C00InterpolateMobyVertex(argument4, argument5, argument6);
                    weight3 = 0x10;
                    value2 = originalStack.sp20;
                    MATCHING_KEEP(value2);
                    argument4 = value2 * weight16;
                    MATCHING_KEEP_CLOBBER(argument4, "memory");
                    value2 = owner18->position.x;
                    weight3 -= weight16;
                    xProduct9 = value2 * weight3;
                    value2 = originalStack.sp24;
                    MATCHING_KEEP(value2);
                    yProduct6 = value2 * weight16;
                    value2 = (argument4 + xProduct9) >> 4;
                    originalStack.sp20 = value2;
                    weight3 = owner18->position.y * weight3;
                    value2 = (yProduct6 + weight3) >> 4;
                    originalStack.sp24 = value2;
                    slot17 += 1;
                    originalStack.sp28 -= func_8003636C(0, 0x12C);
                    originalStack.sp30 = (Controller83C00_rand() & 0xF) - 8;
                    originalStack.sp34 = (Controller83C00_rand() & 0xF) - 8;
                    originalStack.sp38 = func_8003636C(8, 0x10);
                    SpawnParticle(1, 0x28, vector19, (Vector3D*)&originalStack.sp30);
                } while (slot17 < 4);
            }
            break;
    }
}
#undef M2C_FIELD

/* Original signed halfwords and byte increments; no payload meaning is inferred. */
typedef struct {
    short x, y, z;
    unsigned char roll, reserved07, pitch, reserved09, yaw, reserved0B;
    short timer, countdown, reserved10, mode;
} DecodedCountdownMotionTag;
extern int DecodedCountdownMotionStep __asm__("D_8006C648");
extern int DecodedCountdownMotionFrame __asm__("D_8006C640");
extern unsigned char DecodedCountdownMotionBasis[] __asm__("D_80071918");
int DecodedCountdownMotionTimer(void*, int) __asm__("func_800359A4");
int DecodedCountdownMotionQuery(Vector3D*, int) __asm__("func_80019194");
int DecodedCountdownMotionTransform(Vector3D*, void*, Vector3D*) __asm__("func_8004EF74");
void DecodedCountdownMotionRelease(Moby*) __asm__("func_80055B18");
int rand(void);
void func_level_44_800841A0(Moby* moby) {
    DecodedCountdownMotionTag* tag = moby->mobyTag;
    Vector3D vector;
    /* Retain the original 0x38-byte frame and unused local stack reservation. */
    int reservedStack[2];
    register int current __asm__("$2");
    register int countdown __asm__("$3");
    int frame, quotient, particleClass;
    register int particleKind __asm__("$4");
    current = tag->countdown;
    MATCHING_OBSERVE_VOLATILE(current);
    if (!current)
        return;
    countdown = current;
    MATCHING_KEEP(countdown);
    if (current >= 2) {
        current = countdown - DecodedCountdownMotionStep;
        tag->countdown = current;
        if (tag->countdown <= 0)
            tag->countdown = 1;
    }
    if (DecodedCountdownMotionTimer(&tag->timer, 2) || (!moby->drawn && tag->countdown == 1)) {
        SpawnParticle(8, 70, &moby->position, (Vector3D*)16);
        DecodedCountdownMotionRelease(moby);
        return;
    }
    if (DecodedCountdownMotionQuery(&moby->position, 300)) {
        vector.x = tag->x;
        vector.y = tag->y;
        vector.z = tag->z;
        if (DecodedCountdownMotionTransform(&vector, DecodedCountdownMotionBasis, &vector)) {
            tag->x = vector.x;
            tag->y = vector.y;
            tag->z = vector.z;
        }
    }
    moby->position.x += tag->x;
    moby->position.y += tag->y;
    tag->z = (unsigned short)tag->z - 10;
    if (tag->z < -200)
        tag->z = -200;
    moby->position.z += tag->z;
    moby->angle.roll += tag->roll;
    moby->angle.pitch += tag->pitch;
    moby->angle.yaw += tag->yaw;
    if (tag->mode == 2)
        return;
    frame = DecodedCountdownMotionFrame;
    quotient = frame / 5;
    if (frame != quotient * 5)
        return;
    vector.x = rand() & 3;
    vector.y = rand() & 3;
    vector.z = 20;
    if (tag->mode == 1) {
        /* Retail keeps distinct mode-one and mode-zero callback routes. */
        particleClass = 0;
        MATCHING_BARRIER_VOLATILE("memory");
        particleKind = 1;
    } else if (tag->mode == 0) {
        particleKind = 1;
        MATCHING_OBSERVE_VOLATILE(particleKind);
        particleClass = 1;
    } else
        return;
    SpawnParticle(particleKind, particleClass, &moby->position, &vector);
}

void func_80055D24(Moby*, int);
void func_800369B8(Moby*, int);
void func_80055B18(Moby*);
void func_level_44_80084424(Moby* moby) {
    if (func_80039714(moby)) {
        func_80055D24(moby, 4);
        func_800369B8(moby, 0x30);
        SpawnParticle(10, 0x46, &moby->position, (Vector3D*)0x10);
        func_80055B18(moby);
    }
}

int func_80039714(Moby*);
void func_80055D24(Moby*, int);
void func_800369B8(Moby*, int);
void func_80055B18(Moby*);
void func_8004F168(Vector3D*);
void func_level_44_8008448C(Moby* moby) {
    Vector3D offset;
    if (moby->state == 0x32) {
        func_80055D24(moby, 4);
        func_800369B8(moby, 0x18);
        func_80055B18(moby);
    } else {
        func_80039714(moby);
        if (moby->mobyClass == 0x113) {
            func_8004F168(&offset);
            SpawnParticle(1, 0, &moby->position, &offset);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_44/moby", D_level_44_800748DC);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80084520.
* AI generated; not human reviewed. All1101 original instructions,10 selectors
* and every actual destination must match:1111 recorded owned words.
* Frame180hex=384 bytes saves S0..S7/FP/RA;SP10..157 retains original storage.
* Original12-byte D_level44_800748DC is separately audited. All three words
* are copied toSP10/14/18 before the original indexed SP10+4*D_8006C7C4 read.
* The table index domain and semantic units remain unresolved;no padding read
* or invented table value is added. Selector states45..54 preserve defaults.
* Packed descriptors retain pointer38/C8,short3C/3E/CC/CE and byte38/39/3A,
* 50/51/52,E0/E1/E2 views. SPB8/BC are WORD vector consumers,not byte reads.
* Original signed low-half descriptor count comparison follows SHCC;count5,
* index4 increments to5 then clamps descriptor index to4. Every width matches.
* Complete callback targets/arguments precede original late counters. Three
* repeated matrix/vector families retain original RNG call order and fields.
* Full retained heading allocates naturally to FP. Independent global byte
* and flag aliases resolve to original absolute addresses,preventing a cached
* player-byte address from displacing that heading or changing the frame.
* Saved pointer,index,scalar,matrix and vector phases do not overlap. Whole
* trig products/shifts,scan bounds,player flags and both SP118 stores remain.
* Empty metadata consumes initialized complete values/addresses or clobbers
* dead values before fresh complete producers;zero CPU words. No opcode asm,
* partialHI,fixedFP,undefined incoming values or compiler/filter/flag changes.
* Known timer,angle and callback views reuse matched EXE/header evidence.
* Raw units/fixed point,full helper/caller chains,cadence beyond invocation,
* Rev1 mapping and synchronized runtime remain open. Confidence is binary
* identity after all gates. Next:human review and retail captures. Every
* native/linked word,target,selector and table byte plus full EXE/every-overlay
* retail hash must remain identical.
*/
/* Original assembly SHA256 ad44995b9803c3c5071b5316abf05f955ce242090703baa34b1b7288fbba3f9a */
#define Level44_84520Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_84520SetCameraOwnerAndControlWordView1() __asm__("func_80013ACC");
int Level44_84520SetCameraMode11TargetView1() __asm__("func_80013D44");
int Level44_84520QueryWorldSegmentView1() __asm__("func_80018368");
int Level44_84520RequestMobyAnimationView1() __asm__("func_80034F40");
int Level44_84520CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level44_84520RandBetweenView1() __asm__("func_8003636C");
int Level44_84520UpdateMobyInteractionGateView1() __asm__("func_80037BBC");
int Level44_84520RestoreOrClearTrackedSnapshotView1() __asm__("func_8003B74C");
int Level44_84520RegisterTrackedValueView1() __asm__("func_8003B7B4");
int Level44_84520PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level44_84520BuildPackedAngleBasisMatrixView1() __asm__("func_8004EA90");
int Level44_84520TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level44_84520MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level44_84520ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level44_84520CopyVectorView1() __asm__("func_8004F178");
int Level44_84520AddVectorView1() __asm__("func_8004F194");
int Level44_84520SubtractVectorView1() __asm__("func_8004F1C8");
int Level44_84520AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level44_84520ApproachByteAngleView1() __asm__("func_8004F2EC");
int Level44_84520ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level44_84520StartDialogueView1() __asm__("func_800512E4");
int Level44_84520DeleteMobyView1() __asm__("func_80055B18");
int Level44_84520RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level44_84520Data658A0View1 __asm__("D_800658A0");
extern int Level44_84520Data65920View1 __asm__("D_80065920");
extern int Level44_84520Data6C550View1 __asm__("D_8006C550");
extern int Level44_84520Data6C58CView1 __asm__("D_8006C58C");
extern int Level44_84520Data6C640View1 __asm__("D_8006C640");
extern int Level44_84520Data6C65CView1 __asm__("D_8006C65C");
extern unsigned char Level44_84520Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level44_84520Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level44_84520Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level44_84520Data6D088View1 __asm__("D_8006D088");
extern int Level44_84520Data6E040View1 __asm__("D_8006E040");
extern int Level44_84520Data6E048View1 __asm__("D_8006E048");
extern int Level44_84520Data6E160View1 __asm__("D_8006E160");
extern int Level44_84520Data6E164View1 __asm__("D_8006E164");
extern int Level44_84520Data6E344View1 __asm__("D_8006E344");
extern int Level44_84520Data70300View1 __asm__("D_80070300");
extern int Level44_84520Data70328View1 __asm__("D_80070328");
extern int Level44_84520Data716ACView1 __asm__("D_800716AC");
extern int Level44_84520Data71930View1 __asm__("D_80071930");
extern int Level44_84520Data748DCView1 __asm__("D_level_44_800748DC");
extern void* (*Level44_84520DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
extern int Level44_84520Data748DCView2[3] __asm__("D_level_44_800748DC");
extern int Level44_84520Data70328View2 __asm__("D_80070328 + 72");
extern int Level44_84520Data70328View3 __asm__("D_80070328 + 524");
extern unsigned char Level44_84520Data70328View4 __asm__("D_80070328 + 14");
extern unsigned char Level44_84520Data70328View5 __asm__("D_80070328 + 14");
extern unsigned char Level44_84520Data70328View6 __asm__("D_80070328 + 14");
extern unsigned char Level44_84520Data70328View7 __asm__("D_80070328 + 14");
extern unsigned char Level44_84520Data70328View8 __asm__("D_80070328 + 14");
void func_level_44_80084520(void* ownerParameter) {
    register int originalFlagWord8 __asm__("$8");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        retainedOriginalMatrix23 __asm__("$23");
    register void* ownerRecord21 __asm__("$21");
    register int privateRecord22 __asm__("$22"), retainedVectorCounterOrRecord16 __asm__("$16"),
        retainedCounterAngleOrVector17 __asm__("$17"),
        retainedMatrixPathIndexOrPlayer18 __asm__("$18"),
        retainedDistanceSpeedOrMatrix19 __asm__("$19"),
        retainedPathOffsetOrPlayerView20 __asm__("$20");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4,
            spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC,
            spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C, sp120,
            sp124, sp128, sp12C, sp130, sp134, sp138, sp13C, sp140, sp144, sp148, sp14C, sp150,
            sp154;
    } originalFrame;
    int temporaryWord14;
    int temporaryWord4;
    int temporaryWord8;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord9;
    int temporaryWord12;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord7;
    int temporaryWord15;
    int temporaryWord1;
    int temporaryWord3;
    int temporaryWord13;
    ownerRecord21 = ownerParameter;
    MATCHING_KEEP(ownerRecord21);
    privateRecord22 = Level44_84520Field(ownerRecord21, int*, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level44_84520Data748DCView2;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level44_84520Field(argumentWord5, int*, 0);
    rawWord3 = Level44_84520Field(argumentWord5, int*, 4);
    argumentWord4 = Level44_84520Field(argumentWord5, int*, 8);
    MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord2, rawWord3, "memory");
    originalFrame.sp10 = rawWord2;
    originalFrame.sp14 = rawWord3;
    originalFrame.sp18 = argumentWord4;
    temporaryWord7 = Level44_84520Field(ownerRecord21, unsigned char*, 0x48);
    switch (temporaryWord7) {
        case 0x30:
            if (!(Level44_84520Data6C7B4View1 & 2)) {
                goto block_4;
            }
            Level44_84520Field(ownerRecord21, signed char*, 0x41) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4C) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4D) = 0;
            Level44_84520Field(ownerRecord21, int*, 8) = 0;
        block_4:
            Level44_84520Field(privateRecord22, unsigned char*, 2) = 2U;
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x2DU;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 8) =
                (int)(Level44_84520Field((int)&Level44_84520Data70328View1, int*, 8) + 0x800);
            if ((unsigned char)Level44_84520Field(ownerRecord21, unsigned char*, 0x49) >= 0xAU) {
                goto block_8;
            }
            if (Level44_84520Data6C65CView1 == 0) {
                goto block_7;
            }
            Level44_84520Field(Level44_84520Data6C65CView1, signed char*, 0x4C) = 0x10;
        block_7:
            Level44_84520Field(ownerRecord21, unsigned char*, 0x49) = 0xAU;
            retainedVectorCounterOrRecord16 = ownerRecord21 + 0x49;
            Level44_84520RegisterTrackedValueView1(retainedVectorCounterOrRecord16, 1,
                                                   (int)&Level44_84520Data6D088View1);
            Level44_84520RegisterTrackedValueView1(retainedVectorCounterOrRecord16, 1,
                                                   (int)&Level44_84520Data6C7F8View1);
        case 0x2D:
        block_8:
            rawWord2 = Level44_84520Data6C640View1;
            argumentWord4 = (int)ownerRecord21;
            if (rawWord2 != 0) {
                goto block_15;
            }
            if (!(Level44_84520Data6C7B4View1 & 2)) {
                goto block_11;
            }
            Level44_84520Field(ownerRecord21, signed char*, 0x41) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4C) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4D) = 0;
            rawWord2 = Level44_84520Data6C7B4View1;
            MATCHING_KEEP_CLOBBER(rawWord2, "memory");
            Level44_84520Field(ownerRecord21, int*, 8) = 0;
            if (rawWord2 & 2) {
                goto block_12;
            }
        block_11:
            rawWord2 = Level44_84520Field((int)&Level44_84520Data70300View1, unsigned char*,
                                          Level44_84520Data6C58CView1);
            MATCHING_BARRIER_VOLATILE("$4");
            argumentWord4 = (int)ownerRecord21;
            if (!(rawWord2 & 2)) {
                goto block_15;
            }
        block_12:
            temporaryWord1 = (Level44_84520Field(privateRecord22, int*, 0x34) * 0x58) +
                             Level44_84520Data6C550View1;
            if (Level44_84520Field(temporaryWord1, unsigned char*, 0x48) & 0x80) {
                goto block_14;
            }
            Level44_84520DeleteMobyView1(temporaryWord1);
        block_14:
            argumentWord4 = (int)ownerRecord21;
        block_15:
            rawWord2 = Level44_84520UpdateMobyInteractionGateView1(argumentWord4, 0);
            retainedVectorCounterOrRecord16 = (int)ownerRecord21 + 72;
            if (rawWord2 == 0) {
                goto block_17;
            }
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x30U;
            Level44_84520RegisterTrackedValueView1(retainedVectorCounterOrRecord16, 1,
                                                   (int)&Level44_84520Data6D088View1);
            Level44_84520RegisterTrackedValueView1(retainedVectorCounterOrRecord16, 1,
                                                   (int)&Level44_84520Data6C7F8View1);
            Level44_84520StartDialogueView1(ownerRecord21, 0, 2);
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x2EU;
            return;
        block_17:
            MATCHING_BARRIER_VOLATILE("$2");
            retainedCounterAngleOrVector17 = 0;
            retainedMatrixPathIndexOrPlayer18 = (int)&originalFrame.sp20;
            retainedVectorCounterOrRecord16 = (int)&originalFrame.sp40;
        emitOriginalFirstPacket149:
            rawWord2 = Level44_84520RandBetweenView1(0, 255);
            argumentWord4 = 0;
            argumentWord5 = 1024;
            __asm__ volatile(""
                             : "=r"(retainedCounterAngleOrVector17)
                             : "0"(retainedCounterAngleOrVector17), "r"(rawWord2),
                               "r"(argumentWord4), "r"(argumentWord5)
                             : "memory");
            retainedCounterAngleOrVector17++;
            Level44_84520Field(&originalFrame.sp50, signed char*, 0) = rawWord2;
            Level44_84520Field(&originalFrame.sp50, signed char*, 1) = 0;
            rawWord3 = Level44_84520Field(ownerRecord21, unsigned char*, 70);
            originalFrame.sp40 = 2048;
            Level44_84520Field(&originalFrame.sp50, unsigned char*, 2) = rawWord3;
            originalFrame.sp44 = Level44_84520RandBetweenView1(argumentWord4, argumentWord5) + 5632;
            originalFrame.sp48 = 0;
            Level44_84520BuildPackedAngleBasisMatrixView1(&originalFrame.sp50,
                                                          retainedMatrixPathIndexOrPlayer18, 0);
            Level44_84520TransformVectorByBasisView1(retainedMatrixPathIndexOrPlayer18,
                                                     retainedVectorCounterOrRecord16,
                                                     retainedVectorCounterOrRecord16);
            Level44_84520AddVectorView1(retainedVectorCounterOrRecord16, ownerRecord21 + 12,
                                        retainedVectorCounterOrRecord16);
            argumentWord4 = 1;
            argumentWord5 = 62;
            argumentWord6 = retainedVectorCounterOrRecord16;
            rawWord2 = originalFrame.sp48;
            rawWord3 = (int)Level44_84520DataSpawnParticleView1;
            rawWord2 += 4096;
            originalFrame.sp48 = rawWord2;
            __asm__(""
                    : "=r"(rawWord3)
                    : "0"(rawWord3), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                    : "memory");
            rawWord2 = Level44_84520Field(privateRecord22, int*, 48);
            argumentWord7 = (int)&originalFrame.sp38;
            Level44_84520Field(&originalFrame.sp3C, short*, 0) = 0;
            Level44_84520Field(&originalFrame.sp3C, short*, 2) = 0;
            originalFrame.sp38 = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if (retainedCounterAngleOrVector17 <= 0)
                goto emitOriginalFirstPacket149;
            rawWord3 = Level44_84520Field(privateRecord22, int*, 44);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level44_84520Data6C550View1;
            retainedVectorCounterOrRecord16 = rawWord3 + rawWord2;
            rawWord2 = Level44_84520PlanarHeadingLookupView1(
                Level44_84520Field(retainedVectorCounterOrRecord16, int*, 12) -
                    Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0),
                Level44_84520Field(retainedVectorCounterOrRecord16, int*, 16) -
                    Level44_84520Field((int)&Level44_84520Data70328View1, int*, 4),
                0);
            argumentWord4 = retainedVectorCounterOrRecord16 + 12;
            argumentWord5 = (int)&Level44_84520Data70328View1;
            __asm__(""
                    : "=r"(argumentWord5)
                    : "0"(argumentWord5), "r"(argumentWord4), "r"(rawWord2)
                    : "$17");
            retainedCounterAngleOrVector17 = rawWord2;
            if (Level44_84520ApproximatePlanarDistanceView1(argumentWord4, argumentWord5) >= 5120) {
                goto returnOriginalEpilogue1088;
            }
            if (Level44_84520AbsoluteByteAngleDeltaView1(
                    retainedCounterAngleOrVector17,
                    Level44_84520Field(retainedVectorCounterOrRecord16, unsigned char*, 0x46)) <
                0x41) {
                goto returnOriginalEpilogue1088;
            }
            Level44_84520SetCameraOwnerAndControlWordView1(
                Level44_84520Data6C550View1 +
                    (Level44_84520Field(privateRecord22, int*, 0x2C) * 0x58),
                0xD);
            Level44_84520Field(ownerRecord21, unsigned char*, 0x4A) = 0xFF;
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x2FU;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x23C) = 0;
            Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), short*, 2) = 0;
            Level44_84520Field(privateRecord22, int*, 0x28) = 0x2D;
            Level44_84520CopyVectorView1(privateRecord22 + 0x38, (int)&Level44_84520Data70328View1);
            return;
        case 0x2E:
            if (Level44_84520Data6E344View1 == 1) {
                goto returnOriginalEpilogue1088;
            }
            retainedCounterAngleOrVector17 = 0;
            if (Level44_84520Field(privateRecord22, unsigned char*, 2) != 1) {
                goto block_25;
            }
            argumentWord4 = (int)ownerRecord21;
            argumentWord5 = 0;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4));
            Level44_84520Field(ownerRecord21, unsigned char*, 72) = 0;
            Level44_84520RequestMobyAnimationView1(argumentWord4, argumentWord5);
            goto writeOriginalState45;
        block_25:
            retainedMatrixPathIndexOrPlayer18 = (int)&originalFrame.sp58;
            retainedVectorCounterOrRecord16 = (int)&originalFrame.sp70;
        emitOriginalSecondPacket269:
            rawWord2 = Level44_84520RandBetweenView1(0, 255);
            argumentWord4 = 0;
            argumentWord5 = 1024;
            __asm__ volatile(""
                             : "=r"(retainedCounterAngleOrVector17)
                             : "0"(retainedCounterAngleOrVector17), "r"(rawWord2),
                               "r"(argumentWord4), "r"(argumentWord5)
                             : "memory");
            retainedCounterAngleOrVector17++;
            Level44_84520Field(&originalFrame.sp50, signed char*, 0) = rawWord2;
            Level44_84520Field(&originalFrame.sp50, signed char*, 1) = 0;
            rawWord3 = Level44_84520Field(ownerRecord21, unsigned char*, 70);
            originalFrame.sp70 = 2048;
            Level44_84520Field(&originalFrame.sp50, unsigned char*, 2) = rawWord3;
            originalFrame.sp74 = Level44_84520RandBetweenView1(argumentWord4, argumentWord5) + 5632;
            originalFrame.sp78 = 0;
            Level44_84520BuildPackedAngleBasisMatrixView1(&originalFrame.sp50,
                                                          retainedMatrixPathIndexOrPlayer18, 0);
            Level44_84520TransformVectorByBasisView1(retainedMatrixPathIndexOrPlayer18,
                                                     retainedVectorCounterOrRecord16,
                                                     retainedVectorCounterOrRecord16);
            Level44_84520AddVectorView1(retainedVectorCounterOrRecord16, ownerRecord21 + 12,
                                        retainedVectorCounterOrRecord16);
            argumentWord4 = 1;
            argumentWord5 = 62;
            argumentWord6 = retainedVectorCounterOrRecord16;
            rawWord2 = originalFrame.sp78;
            rawWord3 = (int)Level44_84520DataSpawnParticleView1;
            rawWord2 += 4096;
            originalFrame.sp78 = rawWord2;
            __asm__(""
                    : "=r"(rawWord3)
                    : "0"(rawWord3), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                    : "memory");
            rawWord2 = Level44_84520Field(privateRecord22, int*, 48);
            argumentWord7 = (int)&originalFrame.sp38;
            Level44_84520Field(&originalFrame.sp3C, short*, 0) = 0;
            Level44_84520Field(&originalFrame.sp3C, short*, 2) = 0;
            originalFrame.sp38 = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if (retainedCounterAngleOrVector17 <= 0)
                goto emitOriginalSecondPacket269;
            rawWord3 = Level44_84520Field(privateRecord22, int*, 44);
            rawWord2 = rawWord3 * 88;
            rawWord3 = Level44_84520Data6C550View1;
            retainedVectorCounterOrRecord16 = rawWord3 + rawWord2;
            rawWord2 = Level44_84520PlanarHeadingLookupView1(
                Level44_84520Field(retainedVectorCounterOrRecord16, int*, 12) -
                    Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0),
                Level44_84520Field(retainedVectorCounterOrRecord16, int*, 16) -
                    Level44_84520Field((int)&Level44_84520Data70328View1, int*, 4),
                0);
            argumentWord4 = retainedVectorCounterOrRecord16 + 12;
            argumentWord5 = (int)&Level44_84520Data70328View1;
            __asm__(""
                    : "=r"(argumentWord5)
                    : "0"(argumentWord5), "r"(argumentWord4), "r"(rawWord2)
                    : "$17");
            retainedCounterAngleOrVector17 = rawWord2;
            if (Level44_84520ApproximatePlanarDistanceView1(argumentWord4, argumentWord5) >= 5120) {
                goto returnOriginalEpilogue1088;
            }
            if (Level44_84520AbsoluteByteAngleDeltaView1(
                    retainedCounterAngleOrVector17,
                    Level44_84520Field(retainedVectorCounterOrRecord16, unsigned char*, 0x46)) <
                0x41) {
                goto returnOriginalEpilogue1088;
            }
            Level44_84520SetCameraOwnerAndControlWordView1(
                Level44_84520Data6C550View1 +
                    (Level44_84520Field(privateRecord22, int*, 0x2C) * 0x58),
                0xD);
            Level44_84520Field(ownerRecord21, unsigned char*, 0x4A) = 0xFF;
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x2FU;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x23C) = 0;
            Level44_84520Field(privateRecord22, int*, 0x28) = 0x2D;
            Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), short*, 2) = 0;
            Level44_84520CopyVectorView1(privateRecord22 + 0x38, (int)&Level44_84520Data70328View1);
            return;
        case 0x2F:
            retainedDistanceSpeedOrMatrix19 = 0x186A0;
            retainedMatrixPathIndexOrPlayer18 = -1;
            originalFrame.sp140 = 0;
            if (Level44_84520CountTimerDownView1(privateRecord22 + 0x28, 4) == 0) {
                goto block_33;
            }
            if (Level44_84520Data6C65CView1 == 0) {
                goto block_33;
            }
            Level44_84520Field(Level44_84520Data6C65CView1, signed char*, 0x4C) = 0;
        block_33:
            rawWord2 = Level44_84520Field(privateRecord22, int*, 48);
            retainedVectorCounterOrRecord16 = Level44_84520Field(rawWord2, short*, 2);
            if (retainedVectorCounterOrRecord16 < 0)
                retainedVectorCounterOrRecord16 = 0;
            MATCHING_KEEP(retainedVectorCounterOrRecord16);
            rawWord3 = Level44_84520Field(rawWord2, short*, 0);
            retainedCounterAngleOrVector17 = retainedVectorCounterOrRecord16 + 2;
            if (rawWord3 >= retainedCounterAngleOrVector17) {
                rawWord2 = retainedVectorCounterOrRecord16 < retainedCounterAngleOrVector17;
                goto dispatchOriginalPath416;
            }
            retainedCounterAngleOrVector17 = rawWord3;
            goto compareOriginalPath415;
        scanOriginalPath401:
            rawWord2 = Level44_84520Field(privateRecord22, int*, 48);
            argumentWord5 = (int)&Level44_84520Data70328View1;
            rawWord2 = Level44_84520Field(rawWord2, int*, 12);
            __asm__ volatile("" ::: "$4", "memory");
            argumentWord4 = retainedVectorCounterOrRecord16 * 16;
            rawWord3 = Level44_84520ApproximatePlanarDistanceView1(rawWord2 + argumentWord4,
                                                                   argumentWord5);
            if (rawWord3 < retainedDistanceSpeedOrMatrix19) {
                retainedDistanceSpeedOrMatrix19 = rawWord3;
                retainedMatrixPathIndexOrPlayer18 = retainedVectorCounterOrRecord16;
            }
            retainedVectorCounterOrRecord16++;
        compareOriginalPath415:
            rawWord2 = retainedVectorCounterOrRecord16 < retainedCounterAngleOrVector17;
        dispatchOriginalPath416:
            if (rawWord2)
                goto scanOriginalPath401;
            if (retainedMatrixPathIndexOrPlayer18 < 0) {
                goto block_44;
            }
            Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), short*, 2) =
                retainedMatrixPathIndexOrPlayer18;
            goto block_45;
        block_44:
            retainedMatrixPathIndexOrPlayer18 =
                Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), short*, 2);
        block_45:
            if ((retainedMatrixPathIndexOrPlayer18 + 1) <
                Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), short*, 0)) {
                goto updateStatusHandle;
            }
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x33U;
            Level44_84520Field(privateRecord22, int*, 0x28) = 0x21;
            return;
        updateStatusHandle:
            argumentWord6 = (int)&Level44_84520Data70328View1 + 572;
            rawWord2 = Level44_84520Field(argumentWord6, int*, 0);
            if (rawWord2 == 57)
                goto returnOriginalEpilogue1088;
            if (Level44_84520Data70328View2 == 57)
                goto returnOriginalEpilogue1088;
            argumentWord5 = 0x10000088;
            retainedCounterAngleOrVector17 = (int)&originalFrame.sp50;
            argumentWord4 = retainedCounterAngleOrVector17;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
            rawWord2 = Level44_84520Data70328View3;
            rawWord3 = 42;
            Level44_84520Field(argumentWord6, int*, 0) = rawWord3;
            rawWord2 |= argumentWord5;
            Level44_84520Data70328View3 = rawWord2;
            rawWord2 = Level44_84520Field(privateRecord22, int*, 48);
            MATCHING_KEEP_VOLATILE_CLOBBER(retainedMatrixPathIndexOrPlayer18, "memory");
            retainedMatrixPathIndexOrPlayer18 *= 16;
            argumentWord6 = Level44_84520Field(rawWord2, int*, 12);
            retainedPathOffsetOrPlayerView20 = retainedMatrixPathIndexOrPlayer18 + 16;
            Level44_84520SubtractVectorView1(argumentWord4,
                                             argumentWord6 + retainedPathOffsetOrPlayerView20,
                                             argumentWord6 + retainedMatrixPathIndexOrPlayer18);
            temporaryWord10 = Level44_84520PlanarHeadingLookupView1((int)originalFrame.sp50,
                                                                    originalFrame.sp54, 0);
            Level44_84520AbsoluteByteAngleDeltaView1(temporaryWord10, Level44_84520Data70328View4);
            retainedDistanceSpeedOrMatrix19 =
                Level44_84520Field(&originalFrame.sp10, int*, Level44_84520Data6C7C4View1 * 4);
            Level44_84520ScaleVectorRatioQ15View1(
                &originalFrame.sp50, Level44_84520MeasureVectorLengthView1(&originalFrame.sp50, 1),
                0);
            Level44_84520Field(&originalFrame.sp38, signed char*, 0) = 0;
            Level44_84520Field(&originalFrame.sp38, signed char*, 1) = 0;
            Level44_84520Field(&originalFrame.sp38, signed char*, 2) = Level44_84520Data70328View5;
            retainedOriginalMatrix23 = (int)&originalFrame.spA0;
            Level44_84520BuildPackedAngleBasisMatrixView1(&originalFrame.sp38,
                                                          retainedOriginalMatrix23, 0);
            originalFrame.sp80 = retainedDistanceSpeedOrMatrix19;
            originalFrame.sp84 = 0;
            originalFrame.sp88 = 0;
            Level44_84520TransformVectorByBasisView1(retainedOriginalMatrix23, &originalFrame.sp80,
                                                     &originalFrame.sp80);
            Level44_84520AddVectorView1((int*)&originalFrame.sp50, &originalFrame.sp80,
                                        (int*)&originalFrame.sp50);
            temporaryWord4 =
                Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), void**, 0xC);
            Level44_84520SubtractVectorView1(&originalFrame.spB8,
                                             temporaryWord4 + retainedPathOffsetOrPlayerView20,
                                             temporaryWord4 + retainedMatrixPathIndexOrPlayer18);
            temporaryWord11 = Level44_84520PlanarHeadingLookupView1((int)originalFrame.spB8,
                                                                    originalFrame.spBC, 0);
            temporaryWord12 = Level44_84520AbsoluteByteAngleDeltaView1(temporaryWord11,
                                                                       Level44_84520Data70328View6);
            if (temporaryWord12 < 0x11) {
                goto block_51;
            }
            temporaryWord5 = (temporaryWord12 - 0x10) * 3;
            Level44_84520Field((int)&Level44_84520Data70328View1, signed char*, 0x22A) =
                (signed char)(Level44_84520ApproachByteAngleView1(
                                  temporaryWord11, Level44_84520Data70328View7, temporaryWord5,
                                  (temporaryWord5 >> 1) + 1) -
                              Level44_84520Data70328View8);
        block_51:
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x21C) =
                (int)originalFrame.sp50;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x220) = originalFrame.sp54;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x224) = originalFrame.sp58;
            argumentWord5 = Level44_84520Field(privateRecord22, int*, 48);
            rawWord2 = Level44_84520Field(argumentWord5, short*, 2);
            rawWord3 = Level44_84520Field(argumentWord5, short*, 0);
            retainedMatrixPathIndexOrPlayer18 = rawWord2 + 16;
            retainedVectorCounterOrRecord16 = 0;
            if (retainedMatrixPathIndexOrPlayer18 < rawWord3)
                goto prepareOriginalPathParticle562;
            retainedMatrixPathIndexOrPlayer18 = rawWord3 - 1;
        prepareOriginalPathParticle562:
            retainedPathOffsetOrPlayerView20 = (int)&Level44_84520Data6E040View1;
            retainedDistanceSpeedOrMatrix19 = retainedOriginalMatrix23;
            retainedCounterAngleOrVector17 = (int)&originalFrame.spD0;
            MATCHING_KEEP(retainedPathOffsetOrPlayerView20);
            rawWord3 = Level44_84520Field(privateRecord22, int*, 44);
            argumentWord4 = Level44_84520Data6C550View1;
            rawWord2 = rawWord3 * 88;
            argumentWord4 += rawWord2;
            argumentWord4 += 12;
            rawWord2 = Level44_84520Field(argumentWord5, int*, 12);
            argumentWord5 = retainedMatrixPathIndexOrPlayer18 * 16;
            Level44_84520CopyVectorView1(argumentWord4, rawWord2 + argumentWord5);
        emitOriginalPathPacket580:
            rawWord2 = Level44_84520RandBetweenView1(0, 255);
            argumentWord4 = 0;
            rawWord3 = Level44_84520Field(retainedPathOffsetOrPlayerView20, unsigned short*, 0);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = 1024;
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, rawWord2, "memory");
            Level44_84520Field(&originalFrame.spE0, signed char*, 0) = rawWord2;
            Level44_84520Field(&originalFrame.spE0, signed char*, 1) = 0;
            originalFrame.spD0 = 0;
            rawWord3 >>= 4;
            Level44_84520Field(&originalFrame.spE0, signed char*, 2) = rawWord3;
            originalFrame.spD4 = Level44_84520RandBetweenView1(argumentWord4, argumentWord5) + 2560;
            originalFrame.spD8 = 0;
            Level44_84520BuildPackedAngleBasisMatrixView1(&originalFrame.spE0,
                                                          retainedDistanceSpeedOrMatrix19, 0);
            Level44_84520TransformVectorByBasisView1(retainedDistanceSpeedOrMatrix19,
                                                     retainedCounterAngleOrVector17,
                                                     retainedCounterAngleOrVector17);
            rawWord2 = originalFrame.spD0;
            argumentWord4 = Level44_84520Field(retainedPathOffsetOrPlayerView20, int*, -32);
            rawWord3 = originalFrame.spD4;
            argumentWord5 = Level44_84520Field(retainedPathOffsetOrPlayerView20, int*, -28);
            originalFrame.spD0 = rawWord2 + argumentWord4;
            originalFrame.spD4 = rawWord3 + argumentWord5;
            temporaryWord13 = Level44_84520Field(privateRecord22, void**, 0x30);
            originalFrame.spD8 +=
                Level44_84520Field(((Level44_84520Field(temporaryWord13, short*, 2) * 0x10) +
                                    Level44_84520Field(temporaryWord13, void**, 0xC)),
                                   int*, 8);
            originalFrame.spC8 = Level44_84520Field(privateRecord22, void**, 0x30);
            temporaryWord14 = (unsigned short)Level44_84520Field(
                                  Level44_84520Field(privateRecord22, void**, 0x30), short*, 2) +
                              1;
            Level44_84520Field(&originalFrame.spCC, short*, 0) = temporaryWord14;
            rawWord3 =
                Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), short*, 0);
            if ((short)temporaryWord14 < rawWord3) {
                goto emitOriginalPackedDescriptor640;
            }
            argumentWord4 = rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = argumentWord4 - 1;
            Level44_84520Field(&originalFrame.spCC, short*, 0) = rawWord2;
        emitOriginalPackedDescriptor640:
            MATCHING_BARRIER_VOLATILE("$4");
            argumentWord4 = 1;
            argumentWord5 = 62;
            argumentWord6 = retainedCounterAngleOrVector17;
            argumentWord7 = (int)&originalFrame.spC8;
            MATCHING_OBSERVE4_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                               argumentWord7, "memory");
            rawWord2 = (int)Level44_84520DataSpawnParticleView1;
            __asm__ volatile(""
                             : "=r"(retainedVectorCounterOrRecord16)
                             : "0"(retainedVectorCounterOrRecord16), "r"(argumentWord4),
                               "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7)
                             : "memory");
            retainedVectorCounterOrRecord16++;
            Level44_84520Field(&originalFrame.spCC, short*, 2) = 0;
            ((int (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if (retainedVectorCounterOrRecord16 < 2) {
                goto emitOriginalPathPacket580;
            }
            retainedCounterAngleOrVector17 = (int)&originalFrame.sp50;
            argumentWord4 = retainedCounterAngleOrVector17;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
            retainedMatrixPathIndexOrPlayer18 = (int)&Level44_84520Data70328View1;
            Level44_84520CopyVectorView1(argumentWord4, retainedMatrixPathIndexOrPlayer18);
            argumentWord4 = retainedMatrixPathIndexOrPlayer18 + 48;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$16");
            retainedVectorCounterOrRecord16 = (int)&originalFrame.sp80;
            argumentWord5 = retainedVectorCounterOrRecord16;
            argumentWord6 = retainedVectorCounterOrRecord16;
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                               "memory");
            originalFrame.sp80 = 900;
            originalFrame.sp84 = 0;
            originalFrame.sp88 = 0;
            originalFrame.sp58 -= 384;
            Level44_84520TransformVectorByBasisView1(argumentWord4, argumentWord5, argumentWord6);
            Level44_84520AddVectorView1(retainedVectorCounterOrRecord16,
                                        retainedVectorCounterOrRecord16,
                                        retainedCounterAngleOrVector17);
            if (Level44_84520ApproximatePlanarDistanceView1(retainedMatrixPathIndexOrPlayer18,
                                                            privateRecord22 + 56) >= 0xC8) {
                goto testOriginalPathCollision704;
            }
            argumentWord4 = (int)&originalFrame.sp90;
            argumentWord5 = argumentWord4;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$7");
            argumentWord7 = temporaryWord10 * 2;
            MATCHING_KEEP(argumentWord7);
            rawWord3 = Level44_84520Field((int)&Level44_84520Data65920View1, short*, argumentWord7);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedMatrixPathIndexOrPlayer18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord6, "memory");
            rawWord2 = (rawWord3 * 125) >> 9;
            originalFrame.sp90 = rawWord2;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data658A0View1, short*, argumentWord7);
            __asm__ volatile("" ::: "$8", "memory");
            originalFlagWord8 = 1;
            originalFrame.sp140 = originalFlagWord8;
            originalFrame.sp98 = 0;
            __asm__ volatile("" ::"m"(originalFrame.sp140), "m"(originalFrame.sp98), "r"(rawWord3)
                             : "$2");
            rawWord2 = (rawWord3 * 125) >> 9;
            originalFrame.sp94 = rawWord2;
            Level44_84520AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
        testOriginalPathCollision704:
            if (Level44_84520QueryWorldSegmentView1(retainedCounterAngleOrVector17,
                                                    retainedVectorCounterOrRecord16) == 0) {
                goto testOriginalParticleFlag715;
            }
            if (Level44_84520Data71930View1 != 0) {
                goto writeOriginalPlayerFlags728;
            }
        testOriginalParticleFlag715:
            originalFlagWord8 = originalFrame.sp140;
            if (originalFlagWord8 == 0) {
                goto copyOriginalPlayerVector;
            }
            if (Level44_84520QueryWorldSegmentView1(retainedMatrixPathIndexOrPlayer18,
                                                    &originalFrame.sp90) == 0) {
                goto copyOriginalPlayerVector;
            }
            if (Level44_84520Data71930View1 == 0) {
                goto copyOriginalPlayerVector;
            }
        writeOriginalPlayerFlags728:
            MATCHING_BARRIER_VOLATILE("$5");
            argumentWord5 = 0x10000480;
            rawWord2 = Level44_84520Field((int)&Level44_84520Data70328View1, unsigned char*, 14);
            rawWord3 = 57;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 572) = rawWord3;
            rawWord2 = (rawWord2 + 128) & 255;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 664) = rawWord2;
            MATCHING_BARRIER_VOLATILE("memory");
            rawWord2 = Level44_84520Data70328View3;
            argumentWord4 = Level44_84520Field((int)&Level44_84520Data70328View1, int*, 664);
            rawWord2 |= argumentWord5;
            argumentWord4 *= 2;
            Level44_84520Data70328View3 = rawWord2;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data65920View1, short*, argumentWord4);
            rawWord2 = (rawWord3 * 25) >> 10;
            originalFrame.sp50 = rawWord2;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data658A0View1, short*, argumentWord4);
            originalFrame.sp58 = 0;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 540) = rawWord2;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 548) = 0;
            rawWord2 = (rawWord3 * 25) >> 10;
            originalFrame.sp54 = rawWord2;
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 544) = rawWord2;
            Level44_84520Field(ownerRecord21, unsigned char*, 72) = 53;
            rawWord2 = Level44_84520Data6C7B4View1;
            rawWord3 = 60;
            Level44_84520Field(privateRecord22, int*, 40) = rawWord3;
            if (rawWord2 & 2)
                goto copyOriginalPlayerVector;
            if (Level44_84520Field((int)&Level44_84520Data70300View1, unsigned char*,
                                   Level44_84520Data6C58CView1) &
                2) {
                goto copyOriginalPlayerVector;
            }
            temporaryWord2 = Level44_84520Data6C58CView1 * 6;
            temporaryWord15 = Level44_84520Field((int)&Level44_84520Data716ACView1, unsigned char*,
                                                 1 + temporaryWord2);
            if (temporaryWord15 >= 0xFFU) {
                goto copyOriginalPlayerVector;
            }
            Level44_84520Field((int)&Level44_84520Data716ACView1, unsigned char*,
                               1 + temporaryWord2) = temporaryWord15 + 1;
        copyOriginalPlayerVector:
            Level44_84520CopyVectorView1(privateRecord22 + 0x38, (int)&Level44_84520Data70328View1);
            return;
        case 0x35:
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x20C) =
                (int)(Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x20C) |
                      0x10000002);
            if (Level44_84520CountTimerDownView1(privateRecord22 + 0x28, 4) == 0) {
                goto returnOriginalEpilogue1088;
            }
            Level44_84520RestoreOrClearTrackedSnapshotView1((int)&Level44_84520Data6D088View1);
            return;
        case 0x33:
            retainedCounterAngleOrVector17 = 0;
            retainedDistanceSpeedOrMatrix19 = (int)&Level44_84520Data6E040View1;
            retainedMatrixPathIndexOrPlayer18 = (int)&originalFrame.spE8;
            retainedVectorCounterOrRecord16 = (int)&originalFrame.sp100;
            MATCHING_KEEP(retainedDistanceSpeedOrMatrix19);
        emitOriginalExitPacket832:
            rawWord2 = Level44_84520RandBetweenView1(0, 255);
            argumentWord4 = 0;
            argumentWord5 = 1024;
            rawWord3 = Level44_84520Field(retainedDistanceSpeedOrMatrix19, unsigned short*, 0);
            __asm__ volatile(""
                             : "=r"(retainedCounterAngleOrVector17)
                             : "0"(retainedCounterAngleOrVector17), "r"(argumentWord5),
                               "r"(rawWord2)
                             : "memory");
            retainedCounterAngleOrVector17++;
            Level44_84520Field(&originalFrame.spE0, signed char*, 0) = rawWord2;
            Level44_84520Field(&originalFrame.spE0, signed char*, 1) = 0;
            originalFrame.sp100 = 0;
            rawWord3 >>= 4;
            Level44_84520Field(&originalFrame.spE0, signed char*, 2) = rawWord3;
            originalFrame.sp104 =
                Level44_84520RandBetweenView1(argumentWord4, argumentWord5) + 1536;
            originalFrame.sp108 = 0;
            Level44_84520BuildPackedAngleBasisMatrixView1(&originalFrame.spE0,
                                                          retainedMatrixPathIndexOrPlayer18, 0);
            Level44_84520TransformVectorByBasisView1(retainedMatrixPathIndexOrPlayer18,
                                                     retainedVectorCounterOrRecord16,
                                                     retainedVectorCounterOrRecord16);
            Level44_84520AddVectorView1(retainedVectorCounterOrRecord16,
                                        retainedDistanceSpeedOrMatrix19 - 32,
                                        retainedVectorCounterOrRecord16);
            originalFrame.spC8 = Level44_84520Field(privateRecord22, int*, 48);
            argumentWord4 = 1;
            argumentWord5 = 62;
            argumentWord6 = retainedVectorCounterOrRecord16;
            rawWord2 = Level44_84520Field(privateRecord22, int*, 48);
            __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                             : "$3", "memory");
            rawWord3 = (int)Level44_84520DataSpawnParticleView1;
            rawWord2 = Level44_84520Field(rawWord2, unsigned short*, 0);
            argumentWord7 = (int)&originalFrame.spC8;
            Level44_84520Field(&originalFrame.spCC, short*, 2) = 0;
            rawWord2 -= 1;
            Level44_84520Field(&originalFrame.spCC, short*, 0) = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if (retainedCounterAngleOrVector17 < 2) {
                goto emitOriginalExitPacket832;
            }
            if (Level44_84520CountTimerDownView1(privateRecord22 + 0x28, 4) == 0) {
                goto returnOriginalEpilogue1088;
            }
            Level44_84520Data6E160View1 = 0;
            Level44_84520Data6E164View1 = 0;
            Level44_84520Field(privateRecord22, unsigned char*, 2) = 1U;
            rawWord2 = Level44_84520Data6C7B4View1;
            rawWord3 = Level44_84520Field(ownerRecord21, int*, 0);
            MATCHING_BARRIER_VOLATILE("memory");
            rawWord2 |= 2;
            Level44_84520Data6C7B4View1 = rawWord2;
            rawWord2 = 2;
            Level44_84520Field(rawWord3, signed char*, 5) = rawWord2;
            rawWord2 = Level44_84520Field(ownerRecord21, unsigned char*, 70);
            retainedVectorCounterOrRecord16 = (int)&originalFrame.sp110;
            rawWord2 *= 2;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data65920View1, short*, rawWord2);
            argumentWord4 = retainedVectorCounterOrRecord16;
            rawWord2 = (rawWord3 * 39) >> 6;
            originalFrame.sp110 = rawWord2;
            rawWord2 = Level44_84520Field(ownerRecord21, unsigned char*, 70) * 2;
            argumentWord5 = retainedVectorCounterOrRecord16;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data658A0View1, short*, rawWord2);
            rawWord2 = Level44_84520Field((int)&Level44_84520Data70328View1, int*, 68);
            argumentWord6 = (int)ownerRecord21 + 12;
            originalFrame.sp118 = 0;
            __asm__ volatile("" ::"m"(originalFrame.sp118));
            originalFrame.sp118 = rawWord2;
            rawWord2 = (rawWord3 * 39) >> 6;
            originalFrame.sp114 = rawWord2;
            Level44_84520AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            Level44_84520SetCameraMode11TargetView1(
                &originalFrame.sp110,
                (Level44_84520Field(ownerRecord21, unsigned char*, 0x46) + 0x80) & 0xFF, 0, 0x29);
            if (Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x280) >= 0) {
                goto block_76;
            }
            Level44_84520Field((int)&Level44_84520Data70328View1, int*, 0x280) = 0;
        block_76:
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x34U;
            if (Level44_84520Data6C65CView1 == 0) {
                goto returnOriginalEpilogue1088;
            }
            Level44_84520Field(Level44_84520Data6C65CView1, signed char*, 0x4C) = 0x10;
            return;
        case 0x34:
            if (Level44_84520Data6E048View1 != 1) {
                goto returnOriginalEpilogue1088;
            }
            temporaryWord3 = (Level44_84520Field(privateRecord22, int*, 0x34) * 0x58) +
                             Level44_84520Data6C550View1;
            if (Level44_84520Field(temporaryWord3, unsigned char*, 0x48) & 0x80) {
                goto resetOriginalLinkedRecord;
            }
            Level44_84520DeleteMobyView1(temporaryWord3);
        resetOriginalLinkedRecord:
            Level44_84520CopyVectorView1(
                Level44_84520Data6C550View1 +
                    (Level44_84520Field(privateRecord22, int*, 0x2C) * 0x58) + 0xC,
                Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), void**, 0xC));
            temporaryWord8 =
                Level44_84520Field(Level44_84520Field(privateRecord22, void**, 0x30), void**, 0xC);
            temporaryWord6 = Level44_84520Field(temporaryWord8, int*, 0x10);
            Level44_84520Field(((Level44_84520Field(privateRecord22, int*, 0x2C) * 0x58) +
                                Level44_84520Data6C550View1),
                               signed char*, 0x46) =
                Level44_84520PlanarHeadingLookupView1(
                    temporaryWord6 - Level44_84520Field(temporaryWord8, int*, 0),
                    Level44_84520Field(temporaryWord8, int*, 0x14) -
                        Level44_84520Field(temporaryWord8, int*, 4),
                    0);
        writeOriginalState45:
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x2DU;
            return;
        case 0x31:
            Level44_84520Field(ownerRecord21, signed char*, 0x41) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4C) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4D) = 0;
            Level44_84520Field(ownerRecord21, int*, 8) = 0;
            Level44_84520Field(ownerRecord21, unsigned char*, 0x48) = 0x32U;
            return;
        case 0x36:
            Level44_84520Field(ownerRecord21, signed char*, 0x41) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4C) = 0;
            Level44_84520Field(ownerRecord21, signed char*, 0x4D) = 0;
            Level44_84520Field(ownerRecord21, int*, 8) = 0;
            rawWord2 = Level44_84520Field(ownerRecord21, unsigned char*, 70) * 2;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data65920View1, short*, rawWord2);
            retainedCounterAngleOrVector17 = 0;
            originalFrame.sp130 = (rawWord3 * 225) >> 11;
            rawWord2 = Level44_84520Field(ownerRecord21, unsigned char*, 70) * 2;
            retainedMatrixPathIndexOrPlayer18 = (int)&Level44_84520Data65920View1;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data658A0View1, short*, rawWord2);
            retainedVectorCounterOrRecord16 = (int)&originalFrame.sp120;
            originalFrame.sp138 = 0;
            originalFrame.sp134 = (rawWord3 * 225) >> 11;
        emitOriginalRing1045:
            rawWord2 = Level44_84520Field(ownerRecord21, unsigned char*, 68);
            __asm__ volatile("" ::: "$4", "memory");
            argumentWord4 = retainedVectorCounterOrRecord16;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "memory");
            rawWord2 *= 2;
            rawWord2 = rawWord2 + retainedMatrixPathIndexOrPlayer18;
            MATCHING_KEEP(rawWord2);
            rawWord3 = Level44_84520Field(rawWord2, short*, 0);
            __asm__ volatile("" ::: "$5", "memory");
            argumentWord5 = (int)ownerRecord21 + 12;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "memory");
            originalFrame.sp120 = (rawWord3 * 3) >> 2;
            rawWord2 = Level44_84520Field(ownerRecord21, unsigned char*, 68) * 2;
            rawWord3 = Level44_84520Field((int)&Level44_84520Data658A0View1, short*, rawWord2);
            argumentWord6 = retainedVectorCounterOrRecord16;
            MATCHING_KEEP_VOLATILE_CLOBBER(retainedCounterAngleOrVector17, "memory");
            retainedCounterAngleOrVector17++;
            temporaryWord9 = (rawWord3 * 3) >> 2;
            originalFrame.sp124 = temporaryWord9;
            originalFrame.sp128 = temporaryWord9;
            originalFrame.sp124 = 0;
            Level44_84520AddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            originalFrame.sp128 += 0xC00;
            Level44_84520DataSpawnParticleView1(1, 39, retainedVectorCounterOrRecord16,
                                                &originalFrame.sp130);
            Level44_84520Field(ownerRecord21, unsigned char*, 0x44) =
                (unsigned char)(Level44_84520Field(ownerRecord21, unsigned char*, 0x44) + 0x10);
            Level44_84520RefreshMobySpatialGridAndBasisView1(ownerRecord21, 4);
            if (retainedCounterAngleOrVector17 < 0x10) {
                goto emitOriginalRing1045;
            }
        default:
            goto returnOriginalEpilogue1088;
    }
returnOriginalEpilogue1088:
    return;
}
#undef Level44_84520Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))


int Controller85654QueryWorldHeightWithOptions() __asm__("func_8001A310");    /* extern */
int Controller85654TestPaddedRotatedBox() __asm__("func_80036220");           /* extern */
int Controller85654TransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Controller85654ClearVector() __asm__("func_8004F168");                    /* extern */
int Controller85654SubtractVector() __asm__("func_8004F1C8");                 /* extern */
int Controller85654ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller85654RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
extern unsigned char Controller85654_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller85654_D_80065920 __asm__("D_80065920");
extern unsigned char Controller85654_D_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char Controller85654_D_80070328 __asm__("D_80070328");
extern int Controller85654_D_80071908 __asm__("D_80071908");

void func_level_44_80085654(Moby* moby) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        char pad_1c[4];
        int sp20;
        int sp24;
        int sp28;
        char pad_2c[4];
        Vector3D sp30;
        char pad_3c[4];
        int sp40;
        int sp44;
        int sp48;
        char pad_4c[4];
        int sp50;
        int sp54;
        int sp58;
        char pad_5c[4];
        Vector3D sp60;
        char pad_6c[4];
        int sp70;
        int sp74;
        int sp78;
        char pad_7c[4];
        Vector3D sp80;
        char pad_8c[4];
    } originalStack;

    register Moby* arg0 __asm__("$17") = moby;

    register Vector3D* temp_a0 __asm__("$4");
    register Vector3D* position22 __asm__("$22");
    register Vector3D* vector21 __asm__("$21");
    register Vector3D* vector20 __asm__("$20");
    register Vector3D* vector19 __asm__("$19");
    register int* global23 __asm__("$23");
    register int* global4 __asm__("$4");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register Vector3D* temp_s0 __asm__("$16");
    register Vector3D* temp_s3_2 __asm__("$19");
    register Vector3D* temp_s3_3 __asm__("$19");
    register Vector3D* temp_s3_4 __asm__("$19");
    short temp_a1;
    register int var_s2 __asm__("$18");
    register int var_v0 __asm__("$2");
    register unsigned char* temp_v0 __asm__("$3");
    register unsigned char* temp_v0_2 __asm__("$3");
    register unsigned char* temp_v0_3 __asm__("$3");
    register unsigned char* temp_v0_4 __asm__("$3");
    register unsigned char* temp_v0_5 __asm__("$3");
    register unsigned char* temp_v0_6 __asm__("$3");
    register unsigned char* temp_v0_7 __asm__("$3");
    register unsigned char* temp_v0_8 __asm__("$3");
    register unsigned int temp_v1 __asm__("$3");
    register void* temp_s3 __asm__("$19");

    MATCHING_KEEP(arg0);
    temp_s3 = arg0->mobyTag;
    if (arg0->unknownCollision != 0) {
        if (Controller85654TestPaddedRotatedBox(&Controller85654_D_80070328, temp_s3 + 0x28, 0,
                                                0x4000) != 0) {
            arg0->unknownCollision = 0;
        } else if (arg0->unknownCollision == 0) {
            goto block_4;
        }
    } else {
    block_4:
        if (Controller85654ApproximatePlanarDistance(&arg0->position,
                                                     &Controller85654_D_80070328) >= 0x3A99) {
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 7);
        }
    }
    temp_v1 = arg0->state;
    switch (temp_v1) {
        case 5:
            if (Controller85654_D_8006C7B4 & 2) {
                arg0->updateDistance = 0xFF;
            }
            arg0->angle.pitch += 0x40;
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 4);
            originalStack.sp10 = 0xC00;
            originalStack.sp14 = 0;
            originalStack.sp18 = 0;
            Controller85654TransformVectorByBasis(&arg0->rotationMatrix, &originalStack.sp10,
                                                  &originalStack.sp10);
            temp_a0 = &arg0->position;
            func_8004F194(temp_a0, temp_a0, (Vector3D*)&originalStack.sp10);
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 3);
            if (M2C_FIELD(temp_s3, short*, 0) >= 0) {
                arg0->state = 4;
                return;
            }
        block_45:
            arg0->state = 0;
        case 0:
        default:
            goto finished;
        case 4:
            if (((Controller85654_D_8006C7B4 & 2) &&
                 (arg0->updateDistance = 0xFF, ((Controller85654_D_8006C7B4 & 2) != 0))) ||
                (Controller85654TestPaddedRotatedBox(&Controller85654_D_80070328, temp_s3 + 4, 0,
                                                     0x4000) != 0)) {
                arg0->state = (unsigned char)(unsigned short)M2C_FIELD(temp_s3, short*, 0);
                temp_a1 = M2C_FIELD(temp_s3, short*, 2);
                if (temp_a1 >= 0) {
                    func_8003BB10(arg0, (int)temp_a1, 0);
                    return;
                }
            }
            break;
        case 1:
            temp_s3_2 = &arg0->position;
            arg0->position.z -= 0x64;
            if (Controller85654QueryWorldHeightWithOptions(temp_s3_2, 0x1800, 3, arg0) != 0) {
                global4 = &Controller85654_D_80071908;
                MATCHING_KEEP(global4);
                value2 = arg0->position.z;
                value3 = *global4;
                var_v0 = value2 - value3;
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                var_s2 = 0;
                if (var_v0 < 0x15E) {
                    temp_s0 = &originalStack.sp30;
                    position22 = temp_s3_2;
                    MATCHING_KEEP(position22);
                    vector21 = (Vector3D*)&originalStack.sp20;
                    vector20 = (Vector3D*)&originalStack.sp50;
                    originalStack.sp50 = (int)(M2C_FIELD(&Controller85654_D_80065920, short*,
                                                         (((arg0->angle.yaw + 0xC0) & 0xFF) * 2)) *
                                               0xAF) >>
                                         0xA;
                    global23 = global4;
                    originalStack.sp54 = (int)(M2C_FIELD(&Controller85654_D_800658A0, short*,
                                                         (((arg0->angle.yaw + 0xC0) & 0xFF) * 2)) *
                                               0xAF) >>
                                         0xA;
                    vector19 = (Vector3D*)&originalStack.sp40;
                    originalStack.sp58 = 0;
                    do {
                        originalStack.sp20 = (int)(M2C_FIELD(&Controller85654_D_80065920, short*,
                                                             (arg0->angle.yaw * 2)) *
                                                   var_s2 * 0x180) >>
                                             0xC;
                        originalStack.sp24 = (int)(M2C_FIELD(&Controller85654_D_800658A0, short*,
                                                             (arg0->angle.yaw * 2)) *
                                                   var_s2 * 0x180) >>
                                             0xC;
                        originalStack.sp28 = 0;
                        func_8004F194(temp_s0, position22, vector21);
                        func_8004F194(temp_s0, temp_s0, vector20);
                        value2 = *global23;
                        originalStack.sp40 = 0;
                        originalStack.sp44 = 0;
                        originalStack.sp48 = 0;
                        originalStack.sp30.z = value2;
                        temp_v0 = SpawnParticle(1, 0, temp_s0, vector19);
                        if (temp_v0 != 0) {
                            value2 = 0x8C;
                            M2C_FIELD(temp_v0, unsigned char*, 0xA) = value2;
                        }
                        temp_v0_2 = SpawnParticle(1, 0x47, temp_s0, 0);
                        if (temp_v0_2 != 0) {
                            value2 = 0x48;
                            *temp_v0_2 = value2;
                        }
                        Controller85654SubtractVector(temp_s0, position22, vector21);
                        func_8004F194(temp_s0, temp_s0, vector20);
                        value2 = *global23;
                        originalStack.sp40 = 0;
                        originalStack.sp44 = 0;
                        originalStack.sp48 = 0;
                        originalStack.sp30.z = value2;
                        temp_v0_3 = SpawnParticle(1, 0, temp_s0, vector19);
                        if (temp_v0_3 != 0) {
                            value2 = 0x8C;
                            M2C_FIELD(temp_v0_3, unsigned char*, 0xA) = value2;
                        }
                        temp_v0_4 = SpawnParticle(1, 0x47, temp_s0, 0);
                        if (temp_v0_4 != 0) {
                            value2 = 0x48;
                            *temp_v0_4 = value2;
                        }
                        var_s2 += 1;
                    } while (var_s2 < 8);
                    func_8003BB10(arg0, 8, 0);
                    value2 = Controller85654_D_80071908;
                    arg0->state = 0;
                    arg0->position.z = value2 + 0x15E;
                    return;
                }
            }
            break;
        case 2:
            arg0->angle.pitch -= 1;
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 4);
            originalStack.sp50 = 0xC00;
            originalStack.sp54 = 0;
            originalStack.sp58 = 0;
            Controller85654TransformVectorByBasis(&arg0->rotationMatrix, &originalStack.sp50,
                                                  &originalStack.sp50);
            temp_a0 = &arg0->position;
            temp_s3_3 = temp_s3 + 0x1C;
            func_8004F194(temp_a0, temp_s3_3, (Vector3D*)&originalStack.sp50);
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 3);
            if ((unsigned char)arg0->angle.pitch < 0x1EU) {
                Controller85654ClearVector(&originalStack.sp60);
                value2 = originalStack.sp50;
                value3 = originalStack.sp58;
                value2 <<= 1;
                originalStack.sp50 = value2;
                value2 = originalStack.sp54;
                value3 <<= 1;
                originalStack.sp58 = value3;
                value2 <<= 1;
                originalStack.sp54 = value2;
                func_8004F194((Vector3D*)&originalStack.sp50, temp_s3_3,
                              (Vector3D*)&originalStack.sp50);
                temp_v0_5 =
                    SpawnParticle(1, 0, (Vector3D*)&originalStack.sp50, &originalStack.sp60);
                if (temp_v0_5 != 0) {
                    value2 = 0x8C;
                    M2C_FIELD(temp_v0_5, unsigned char*, 0xA) = value2;
                }
                temp_v0_6 = SpawnParticle(1, 0x47, (Vector3D*)&originalStack.sp50, 0);
                if (temp_v0_6 != 0) {
                    value2 = 0x48;
                    *temp_v0_6 = value2;
                }
            }
            if ((unsigned char)arg0->angle.pitch < 0x14U) {
                arg0->state = 0;
                return;
            }
            break;
        case 3:
            temp_s0 = &arg0->position;
            temp_a0 = temp_s0;
            temp_s3_4 = temp_s3 + 0x1C;
            func_8004F178(temp_a0, temp_s3_4);
            arg0->angle.pitch += 1;
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 4);
            originalStack.sp70 = 0xC00;
            originalStack.sp74 = 0;
            originalStack.sp78 = 0;
            Controller85654TransformVectorByBasis(&arg0->rotationMatrix, &originalStack.sp70,
                                                  &originalStack.sp70);
            func_8004F194(temp_s0, temp_s0, (Vector3D*)&originalStack.sp70);
            Controller85654RefreshMobySpatialGridAndBasis(arg0, 3);
            if ((unsigned char)arg0->angle.pitch >= 0x63U) {
                Controller85654ClearVector(&originalStack.sp80);
                value2 = originalStack.sp70;
                value3 = originalStack.sp78;
                value2 <<= 1;
                originalStack.sp70 = value2;
                value2 = originalStack.sp74;
                value3 <<= 1;
                originalStack.sp78 = value3;
                value2 <<= 1;
                originalStack.sp74 = value2;
                func_8004F194((Vector3D*)&originalStack.sp70, temp_s3_4,
                              (Vector3D*)&originalStack.sp70);
                temp_v0_7 =
                    SpawnParticle(1, 0, (Vector3D*)&originalStack.sp70, &originalStack.sp80);
                if (temp_v0_7 != 0) {
                    value2 = 0x8C;
                    M2C_FIELD(temp_v0_7, unsigned char*, 0xA) = value2;
                }
                temp_v0_8 = SpawnParticle(1, 0x47, (Vector3D*)&originalStack.sp70, 0);
                if (temp_v0_8 != 0) {
                    value2 = 0x48;
                    *temp_v0_8 = value2;
                }
            }
            if ((unsigned char)arg0->angle.pitch < 0x6D)
                goto finished;
            arg0->state = 0;
            break;
    }
finished:;
}
#undef M2C_FIELD

int func_80039714(Moby*);
void func_80055D24(Moby*, int);
void func_80055B18(Moby*);
void func_level_44_80085D68(Moby* moby) {
    unsigned char state;

    if (moby->animationState.nextId != 0) {
        if (func_80039714(moby) != 0) {
            func_80055D24(moby, 4);
            func_800369B8(moby, 0x20);
        }
    } else {
        state = moby->state;
        if ((state != 0) && (state == 1)) {
            func_8003BABC(moby, 0, 0);
            func_800391E8(6, 0x2FC, moby, 1, 3, 0xC8, 0x100U);
            func_80055D24(moby, 4);
            func_800369B8(moby, 0x38);
            func_80055B18(moby);
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80085E38.
* AI generated; not human reviewed. All159 original instructions and every
* actual branch/call destination must match. Frame50hex=80 bytes saves
* S0..S5/RA;SP10..2F retains the original two vector workspaces.
* Complete original block addresses preserve the distinct missing-record,
* existing-record and active entries. Empty metadata emits zero CPU words.
* Original private-pointer phase ends before that retained value becomes
* the complete initialized0x55555556 division scalar. Ordinary signed C%3
* produces the complete remainder. Repeated scalar assignment inside the
* structured loop enables constant reuse;the compiler emits one initializer
* before the loop. The S4 byte12 initializer is outside the loop. Branch145
* must return to original115,skipping every constant initializer.
* Four iterations retain two particle callbacks and three RNG samples each;
* original vector words subtract512 before adding each complete RNG result.
* Capacity difference20 stops the second loop;21 permits a spawn. At most12
* spawn attempts occur. Signed remainder vectors7->1 and-7->-1 preserve C
* truncation toward zero. Original byte180,72,112,12 writes keep their widths.
* Metadata consumes initialized complete C words/addresses or clobbers dead
* values before fresh complete producers. No opcode asm,synthetic partialHI,
* fixedFP,undefined saved inputs or overlapping live aliases. Compiler,
* filter and flags remain frozen. Units/fixed point,complete helper/caller
* chains,cadence beyond invocation,Rev1 mapping and synchronized retail
* runtime remain open. Confidence is binary identity after all gates. Next:
* human review and retail captures. Every native/linked instruction,target
* and full EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 071006a4400bd8225ffc0f260ea976baa3674a70bb916719e2e4a3876fce17a0 */
#define Level44_85E38Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_85E38MaskLinkedRecordFlagsByIdView1() __asm__("func_80021ED8");
int Level44_85E38QueryShiftedLinkedRecordWordByByteIdView1() __asm__("func_80021F3C");
int Level44_85E38RandBetweenView1() __asm__("func_8003636C");
int Level44_85E38PlaySoundFromGlobalByteTableView1() __asm__("func_8003BB10");
int Level44_85E38ClearVectorView1() __asm__("func_8004F168");
int Level44_85E38CopyVectorView1() __asm__("func_8004F178");
int Level44_85E38ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level44_85E38DeleteMobyView1() __asm__("func_80055B18");
int Level44_85E38DatarandView1(void) __asm__("rand");
extern int Level44_85E38Data6C574View1 __asm__("D_8006C574");
extern int Level44_85E38Data6C578View1 __asm__("D_8006C578");
extern int Level44_85E38Data6D048View1 __asm__("D_8006D048");
extern int Level44_85E38Data6E020View1 __asm__("D_8006E020");
extern void* (*Level44_85E38DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level44_85E38DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_44_80085E38(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    int privatePointerThenDivisionScalar18;
    register int retainedRecord16 __asm__("$16"), retainedFlagsThenLoopIndex17 __asm__("$17"),
        retainedRecordFieldThenByteValue20 __asm__("$20"),
        retainedOriginalFlagResult21 __asm__("$21");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C;
    } originalFrame;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    __asm__ volatile("" ::"i"(&&checkOriginalMissingRecord27), "i"(&&checkOriginalExistingRecord31),
                     "i"(&&clearOriginalRecordField42), "i"(&&testOriginalCapacity115),
                     "i"(&&removeOriginalOwner147));
    privatePointerThenDivisionScalar18 = Level44_85E38Field(ownerRecord19, int*, 0);
    retainedOriginalFlagResult21 = Level44_85E38QueryShiftedLinkedRecordWordByByteIdView1(
        Level44_85E38Field(privatePointerThenDivisionScalar18, int*, 4));
    argumentWord4 = retainedOriginalFlagResult21 >> 8;
    rawWord2 = Level44_85E38Field(privatePointerThenDivisionScalar18, int*, 4);
    rawWord3 = Level44_85E38Field((int)&Level44_85E38Data6D048View1, int*, 20);
    retainedRecord16 = Level44_85E38Field(rawWord2 * 4 + rawWord3, int*, 0);
    retainedFlagsThenLoopIndex17 = argumentWord4 & 255;
    rawWord2 = Level44_85E38Field(retainedRecord16, int*, 4);
    retainedRecordFieldThenByteValue20 = retainedRecord16 + 4;
    if (rawWord2)
        goto checkOriginalExistingRecord31;
checkOriginalMissingRecord27:
    if (!retainedFlagsThenLoopIndex17)
        return;
    goto clearOriginalRecordField42;
checkOriginalExistingRecord31:
    if (retainedFlagsThenLoopIndex17)
        goto clearOriginalRecordField42;
    rawWord2 = Level44_85E38ApproximatePlanarDistanceView1(ownerRecord19 + 12,
                                                           (int)&Level44_85E38Data6E020View1);
    MATCHING_KEEP(retainedFlagsThenLoopIndex17);
    if (rawWord2 >= 32001) {
        Level44_85E38Field(retainedRecord16, int*, 4) = 0;
        return;
    }
clearOriginalRecordField42:
    Level44_85E38Field(retainedRecordFieldThenByteValue20, int*, 0) = 0;
    if (!retainedFlagsThenLoopIndex17) {
        rawWord2 = retainedOriginalFlagResult21 & 15;
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(retainedOriginalFlagResult21));
        if (rawWord2) {
            MATCHING_KEEP_VOLATILE(retainedFlagsThenLoopIndex17);
            Level44_85E38MaskLinkedRecordFlagsByIdView1(
                Level44_85E38Field(privatePointerThenDivisionScalar18, int*, 4), 252, 0);
        }
    }
    Level44_85E38PlaySoundFromGlobalByteTableView1(ownerRecord19, 10, 0);
    Level44_85E38CopyVectorView1(&originalFrame.sp10, ownerRecord19 + 12);
    Level44_85E38ClearVectorView1(&originalFrame.sp20);
    retainedFlagsThenLoopIndex17 = 0;
    do {
        rawWord3 =
            Level44_85E38DataSpawnParticleView1(1, 0, &originalFrame.sp10, &originalFrame.sp20);
        if (rawWord3)
            Level44_85E38Field(rawWord3, unsigned char*, 10) = 180;
        rawWord3 = Level44_85E38DataSpawnParticleView1(1, 71, &originalFrame.sp10, 0);
        if (rawWord3)
            Level44_85E38Field(rawWord3, signed char*, 0) = 72;
        rawWord2 = Level44_85E38RandBetweenView1(0, 1024);
        argumentWord4 = 0;
        rawWord3 = originalFrame.sp10;
        argumentWord5 = 1024;
        rawWord3 -= 512;
        __asm__(""
                : "=r"(rawWord3)
                : "0"(rawWord3), "r"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
        rawWord3 += rawWord2;
        originalFrame.sp10 = rawWord3;
        rawWord2 = Level44_85E38RandBetweenView1(argumentWord4, argumentWord5);
        argumentWord4 = 0;
        rawWord3 = originalFrame.sp14;
        argumentWord5 = 1024;
        rawWord3 -= 512;
        __asm__(""
                : "=r"(rawWord3)
                : "0"(rawWord3), "r"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
        rawWord3 += rawWord2;
        originalFrame.sp14 = rawWord3;
        rawWord2 = Level44_85E38RandBetweenView1(argumentWord4, argumentWord5);
        rawWord3 = originalFrame.sp18;
        MATCHING_KEEP_VOLATILE_CLOBBER(retainedFlagsThenLoopIndex17, "memory");
        retainedFlagsThenLoopIndex17++;
        rawWord3 -= 512;
        rawWord3 += rawWord2;
        originalFrame.sp18 = rawWord3;
    } while (retainedFlagsThenLoopIndex17 < 4);
    Level44_85E38Field(ownerRecord19, signed char*, 73) = 112;
    __asm__ volatile("" ::"m"(Level44_85E38Field(ownerRecord19, signed char*, 73))
                     : "$17", "memory");
    retainedFlagsThenLoopIndex17 = 0;
    privatePointerThenDivisionScalar18 = 0x55555556;
    MATCHING_OBSERVE_VOLATILE(privatePointerThenDivisionScalar18);
    retainedRecordFieldThenByteValue20 = 12;
    do {
        privatePointerThenDivisionScalar18 = 0x55555556;
    testOriginalCapacity115:
        if (Level44_85E38Data6C578View1 - Level44_85E38Data6C574View1 < 21)
            break;
        retainedRecord16 = Level44_85E38DataSpawnMobyView1(568, ownerRecord19);
        if (retainedRecord16) {
            rawWord2 = Level44_85E38DatarandView1();
            MATCHING_OBSERVE_VOLATILE(privatePointerThenDivisionScalar18);
            Level44_85E38Field(retainedRecord16, signed char*, 79) =
                retainedRecordFieldThenByteValue20;
            rawWord2 %= 3;
            Level44_85E38Field(retainedRecord16, signed char*, 60) = rawWord2;
        }
        retainedFlagsThenLoopIndex17++;
    } while (retainedFlagsThenLoopIndex17 < 12);
removeOriginalOwner147:
    Level44_85E38DeleteMobyView1(ownerRecord19);
}
#undef Level44_85E38Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800860B4.
* Assembly SHA256 9d86c3c1a5ac4ce69eff1db9b87dff610dae7d15eefae174a75bcd13f9acd262.
* AI generated;not human reviewed. All807 original instructions,37 table
* selectors and one zero padding word must match,including actual targets.
* FrameA0 retains S0..S7/FP/RA and original SP20..77 extent. The original
* word vector at SP30/34/38 and packed halfwords at SP30/32/34 are separate
* typed views of the same frame bytes. Every load/store width is original.
* The outer dispatch owns31 entries and its inner dispatch owns6 entries.
* The list walkers retain their20-record bounds,terminator reads,class576/
* 605 checks and combined state pairs420/520. The first original branch
* enters the second class compare directly;the later state-pair branch
* enters its distinct signed class reload. Those targets are independent
* acceptance checks. Original byte state writes remain separate from the
* halfword pair reads. Ordinary1056 allocates naturally to FP;no fixed FP.
* Height transitions,angle calls,relative byte offsets,counter updates,
* signed halfword vector samples,arithmetic shifts and packed matrix inputs
* retain every original producer and consumer. State0/30 leave through
* their original table entries. Known359A4/4E880/3B7B4/spawn views reuse
* existing contracts;other complete helper meanings remain unresolved.
* Empty initialized identities,late inputs and dead-before-producer
* clobbers emit zero instructions. Memory metadata retains original load
* delays and repeated accesses. No opcode assembly,partialHI,unknown
* saved-register inputs,overlapping live aliases or compiler changes.
* Cadence per invocation;caller/frame timing and physical units/fixed point
* remain open. Confidence is binary identity after all acceptance gates.
* Next evidence:human review,complete helper/caller chains and synchronized
* retail runtime. Falsification:every native/linked instruction,actual
* branch/call/table target,all original data,full EXE/every overlay hash.
*/
#define Level44_860B4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level44_860B4BuildCameraVectorOrientationView1() __asm__("func_800136F0");
int Level44_860B4QueryWorldHeightView1() __asm__("func_8001A358");
int Level44_860B4ConfigureHudEntryView1() __asm__("func_8002803C");
int Level44_860B4ResetHudEntryByHandleView1() __asm__("func_80028154");
int Level44_860B4RefreshHudEntryByHandleView1() __asm__("func_800281D0");
int Level44_860B4TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level44_860B4CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level44_860B4ResolveMobyYawStepView1() __asm__("func_80035DDC");
void Level44_860B4RegisterTrackedValueView1(void*, int, void*) __asm__("func_8003B7B4");
int Level44_860B4BuildOrientedInputPairView1() __asm__("func_80040F48");
int Level44_860B4PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level44_860B4TransposePackedHalfwordMatrix3x3View1() __asm__("func_8004ECF4");
int Level44_860B4TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level44_860B4CopyVectorView1() __asm__("func_8004F178");
int Level44_860B4AddVectorView1() __asm__("func_8004F194");
int Level44_860B4SubtractVectorView1() __asm__("func_8004F1C8");
int Level44_860B4ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level44_860B4ProjectPointWithGlobalGteMatrixView1() __asm__("func_8004F408");
int Level44_860B4BuildEulerBasisPairView1() __asm__("func_8004F6C4");
int Level44_860B4RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level44_860B4Data6580CView1 __asm__("D_8006580C");
extern int Level44_860B4Data658A0View1 __asm__("D_800658A0");
extern int Level44_860B4Data65920View1 __asm__("D_80065920");
extern int Level44_860B4Data6C550View1 __asm__("D_8006C550");
extern int Level44_860B4Data6C58CView1 __asm__("D_8006C58C");
extern int Level44_860B4Data6C65CView1 __asm__("D_8006C65C");
extern int Level44_860B4Data6C730View1 __asm__("D_8006C730");
extern int Level44_860B4Data6C768View1 __asm__("D_8006C768");
extern unsigned char Level44_860B4Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level44_860B4Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level44_860B4Data6D088View1 __asm__("D_8006D088");
extern unsigned short Level44_860B4Data6E03CView1 __asm__("D_8006E03C");
extern unsigned short Level44_860B4Data6E03EView1 __asm__("D_8006E03E");
extern unsigned short Level44_860B4Data6E040View1 __asm__("D_8006E040");
extern int Level44_860B4Data6E160View1 __asm__("D_8006E160");
extern int Level44_860B4Data6E174View1 __asm__("D_8006E174");
extern int Level44_860B4Data6E178View1 __asm__("D_8006E178");
extern int Level44_860B4Data6E17CView1 __asm__("D_8006E17C");
extern int Level44_860B4Data70300View1 __asm__("D_80070300");
extern int Level44_860B4Data70328View1 __asm__("D_80070328");
extern int Level44_860B4Data714F4View1 __asm__("D_800714F4");
extern int Level44_860B4Data716ACView1 __asm__("D_800716AC");
extern void* (*Level44_860B4DataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern int Level44_860B4Data7445CView1 __asm__("unk_ovlheader_8007445C");
extern int Level44_860B4Data74460View1 __asm__("unk_ovlheader_80074460");
extern unsigned char Level44_860B4Data29904View1 __asm__("func_80029904");
void func_level_44_800860B4(void* input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        recordStateConstant8 __asm__("$8"), recordStateConstant9 __asm__("$9"),
        recordClassConstant10 __asm__("$10");
    register void* ownerRecord20 __asm__("$20");
    register int privateRecord19 __asm__("$19"), addressOrRecord16 __asm__("$16"),
        cursorOrMatrix17 __asm__("$17"), addressOrOne18 __asm__("$18"),
        visitedCount21 __asm__("$21"), recordFlag22 __asm__("$22"), recordTimer23 __asm__("$23");
    int originalStatePair;
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74;
    } originalFrame;
    ownerRecord20 = input;
    MATCHING_KEEP(ownerRecord20);
    rawWord3 = Level44_860B4Field(ownerRecord20, unsigned char*, 0x48);
    privateRecord19 = Level44_860B4Field(ownerRecord20, void**, 0);
    switch (rawWord3) {
        case 0:
        case 30:
            goto finishOriginalDispatch;
        case 4:
            if (!(Level44_860B4Data6C7B4View1 & 8) &&
                !(Level44_860B4Field((int)&Level44_860B4Data70300View1, unsigned char*,
                                     Level44_860B4Data6C58CView1) &
                  8)) {
                rawWord3 = Level44_860B4Data6C58CView1;
                rawWord2 = rawWord3 * 3;
                MATCHING_KEEP(rawWord2);
                argumentWord4 = rawWord2 * 2;
                rawWord3 = Level44_860B4Field((int)&Level44_860B4Data716ACView1, unsigned char*,
                                              3 + argumentWord4);
                if (rawWord3 < 0xFFU) {
                    rawWord2 = rawWord3 + 1;
                    Level44_860B4Field((int)&Level44_860B4Data716ACView1, unsigned char*,
                                       3 + argumentWord4) = rawWord2;
                }
            }
            Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = 0U;
            return;
        case 20:
            addressOrRecord16 = ownerRecord20 + 0x48;
            Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = 4U;
            Level44_860B4RegisterTrackedValueView1(addressOrRecord16, 1,
                                                   (int)&Level44_860B4Data6D088View1);
            Level44_860B4RegisterTrackedValueView1(addressOrRecord16, 1,
                                                   (int)&Level44_860B4Data6C7F8View1);
            addressOrRecord16 = (int)&Level44_860B4Data70328View1 + 0x280;
            rawWord2 = Level44_860B4Field(addressOrRecord16, int*, 0);
            if (rawWord2 < 3)
                Level44_860B4Field(addressOrRecord16, int*, 0) = 3;
            rawWord2 = Level44_860B4Field(addressOrRecord16, int*, 0);
            rawWord3 = Level44_860B4Data6C65CView1;
            Level44_860B4Field(privateRecord19, int*, 0x30) = rawWord2;
            if (!rawWord3)
                Level44_860B4Data6C65CView1 = Level44_860B4DataSpawnMobyView1(120, ownerRecord20);
            Level44_860B4Field(privateRecord19, unsigned short*, 0x2A) = 0U;
            Level44_860B4Field(Level44_860B4Field(privateRecord19, void**, 0), short*, 0xA) = 1;
            Level44_860B4Field(Level44_860B4Field(privateRecord19, void**, 0), short*, 2) = 2;
            Level44_860B4Field(privateRecord19, short*, 4) = 0x3C;
            Level44_860B4Field(privateRecord19, short*, 0x28) = 0;
            Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 2U;
            Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = 1U;
            Level44_860B4CopyVectorView1(
                ownerRecord20 + 0xC,
                Level44_860B4Field(Level44_860B4Field(privateRecord19, void**, 0), void**, 0xC));
            rawWord2 =
                Level44_860B4Field(
                    Level44_860B4Field(Level44_860B4Field(privateRecord19, void**, 0), void**, 0xC),
                    int*, 8) +
                0x100;
            Level44_860B4Field(ownerRecord20, int*, 0x14) = rawWord2;
            Level44_860B4Field(privateRecord19, int*, 0xC) = rawWord2;
            Level44_860B4Field(ownerRecord20, unsigned char*, 0x4A) = 255;
            rawWord2 =
                Level44_860B4Field(Level44_860B4Field(privateRecord19, void**, 0), void**, 0xC);
            argumentWord7 = Level44_860B4Field(rawWord2, int*, 0x10);
            Level44_860B4Field(ownerRecord20, unsigned char*, 0x46) =
                Level44_860B4PlanarHeadingLookupView1(argumentWord7 -
                                                          Level44_860B4Field(rawWord2, int*, 0),
                                                      Level44_860B4Field(rawWord2, int*, 0x14) -
                                                          Level44_860B4Field(rawWord2, int*, 4),
                                                      0);
            Level44_860B4Field(privateRecord19, int*, 0x2C) =
                (short)Level44_860B4ConfigureHudEntryView1(
                    0x16, 0x1B8, Level44_860B4Data7445CView1, Level44_860B4Data74460View1,
                    &Level44_860B4Data29904View1, (int)&Level44_860B4Data70328View1 + 0x280,
                    Level44_860B4Data6580CView1);
            return;
        case 2:
            addressOrOne18 = (int)&Level44_860B4Data70328View1 + 0x280;
            MATCHING_KEEP(addressOrOne18);
            rawWord2 = Level44_860B4Field(addressOrOne18, int*, 0);
            argumentWord4 = (int)&originalFrame.sp20;
            if (rawWord2 < 0) {
                rawWord3 =
                    Level44_860B4Field((int)&Level44_860B4Data70328View1, unsigned char*, 14);
                __asm__("" ::: "$17", "memory");
                cursorOrMatrix17 = addressOrOne18 - 640;
                rawWord3 *= 2;
                rawWord2 = Level44_860B4Field((int)&Level44_860B4Data65920View1, short*, rawWord3);
                __asm__("" ::: "$5", "memory");
                argumentWord5 = cursorOrMatrix17;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5));
                rawWord2 >>= 1;
                originalFrame.sp20 = rawWord2;
                rawWord2 = Level44_860B4Field((int)&Level44_860B4Data658A0View1, short*, rawWord3);
                __asm__("" ::: "$6", "memory");
                argumentWord6 = argumentWord4;
                originalFrame.sp28 = 0;
                __asm__(""
                        : "=r"(rawWord2)
                        : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp28));
                rawWord2 >>= 1;
                originalFrame.sp24 = rawWord2;
                Level44_860B4SubtractVectorView1(argumentWord4, argumentWord5, argumentWord6);
                addressOrRecord16 = (int)&Level44_860B4Data6E17CView1;
                Level44_860B4CopyVectorView1(addressOrRecord16, &originalFrame.sp20);
                Level44_860B4BuildCameraVectorOrientationView1(
                    addressOrRecord16 - 20, &originalFrame.sp20, cursorOrMatrix17);
                rawWord2 = 17;
                Level44_860B4Data6E160View1 = rawWord2;
                rawWord2 = 120;
                Level44_860B4Data6E174View1 = 0;
                Level44_860B4Data6E178View1 = 0;
                Level44_860B4Field(privateRecord19, short*, 4) = rawWord2;
                rawWord2 = 3;
                Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = rawWord2;
                rawWord2 = 1;
                Level44_860B4Field(addressOrOne18, int*, -604) = rawWord2;
                rawWord2 = Level44_860B4Field(ownerRecord20, unsigned char*, 0x46);
                rawWord2 += 128;
                rawWord2 &= 255;
                Level44_860B4Field(addressOrOne18, int*, 24) = rawWord2;
                return;
            }
            rawWord3 = Level44_860B4Field(ownerRecord20, unsigned char*, 0x49);
            switch (rawWord3) {
                case 0:
                    argumentWord7 = 1;
                    argumentWord6 = 0;
                    recordClassConstant10 = 576;
                    MATCHING_KEEP_CLOBBER(recordClassConstant10, "$9");
                    recordStateConstant9 = 32;
                    MATCHING_KEEP(recordStateConstant9);
                    rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                    recordStateConstant8 = 34;
                    rawWord2 = Level44_860B4Field(rawWord3, short*, 2);
                    rawWord3 = Level44_860B4Field(rawWord3, int*, 12);
                    rawWord2 *= 16;
                    rawWord2 += rawWord3;
                    rawWord2 = Level44_860B4Field(rawWord2, unsigned char*, 13);
                    rawWord3 = Level44_860B4Data6C730View1;
                    rawWord2 *= 4;
                    rawWord2 += rawWord3;
                    argumentWord5 = Level44_860B4Field(rawWord2, int*, 0);
                scanOriginalRecordReadiness:
                    rawWord3 = Level44_860B4Field(argumentWord5, unsigned short*, 0);
                    rawWord3 &= 32767;
                    rawWord2 = rawWord3 * 88;
                    rawWord3 = Level44_860B4Data6C550View1;
                    argumentWord4 = rawWord3 + rawWord2;
                    rawWord2 = Level44_860B4Field(argumentWord4, short*, 0x36);
                    MATCHING_KEEP_CLOBBER(rawWord2, "memory");
                    if (rawWord2 == recordClassConstant10) {
                        rawWord2 = Level44_860B4Field(argumentWord4, unsigned char*, 0x48);
                        if (rawWord2 == recordStateConstant9)
                            goto storeOriginalRecordState34;
                    }
                    rawWord3 = Level44_860B4Field(argumentWord4, short*, 0x36);
                    rawWord2 = 605;
                    if (rawWord3 == rawWord2) {
                        rawWord2 = Level44_860B4Field(argumentWord4, unsigned char*, 0x48);
                        if (rawWord2 == recordStateConstant9) {
                        storeOriginalRecordState34:
                            Level44_860B4Field(argumentWord4, unsigned char*, 0x48) =
                                recordStateConstant8;
                        }
                    }
                    rawWord3 = Level44_860B4Field(argumentWord4, unsigned char*, 0x48);
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = rawWord3 & 128;
                    if (!rawWord2) {
                        rawWord2 = Level44_860B4Field(argumentWord4, short*, 0x36);
                        if (rawWord2 != recordClassConstant10)
                            goto clearOriginalReadiness;
                        rawWord3 &= 255;
                        rawWord2 = 46;
                        if (rawWord3 != rawWord2) {
                        clearOriginalReadiness:
                            argumentWord7 = 0;
                        }
                    }
                    rawWord2 = Level44_860B4Field(argumentWord5, short*, 0);
                    argumentWord5 += 2;
                    if (rawWord2 >= 0) {
                        argumentWord6++;
                        rawWord2 = argumentWord6 < 20;
                        MATCHING_KEEP(rawWord2);
                        if (rawWord2)
                            goto scanOriginalRecordReadiness;
                    }
                    if ((argumentWord7 != 0) &&
                        (Level44_860B4CountTimerDownView1(privateRecord19 + 4, 2) != 0)) {
                        rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                        Level44_860B4Field(privateRecord19, unsigned short*, 0x2A) =
                            (unsigned short)(Level44_860B4Field(privateRecord19, unsigned short*,
                                                                0x2A) +
                                             1);
                        if (Level44_860B4Field(rawWord3, short*, 2) ==
                            (Level44_860B4Field(rawWord3, short*, 0) - 1)) {
                            addressOrRecord16 = ownerRecord20 + 0x48;
                            Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = 0U;
                            Level44_860B4RegisterTrackedValueView1(
                                addressOrRecord16, 1, (int)&Level44_860B4Data6D088View1);
                            Level44_860B4RegisterTrackedValueView1(
                                addressOrRecord16, 1, (int)&Level44_860B4Data6C7F8View1);
                            Level44_860B4ResetHudEntryByHandleView1(
                                Level44_860B4Field(privateRecord19, int*, 0x2C));
                            Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = 0x1EU;
                            Level44_860B4Data6C768View1 = 0;
                        } else {
                            Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 2U;
                            rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                            if ((Level44_860B4Field(
                                     ((Level44_860B4Field(rawWord3, short*, 2) * 0x10) +
                                      Level44_860B4Field(rawWord3, void**, 0xC)),
                                     int*, 0xC) &
                                 0xF) == 2) {
                                Level44_860B4Field(privateRecord19, short*, 4) = 0;
                            } else {
                                Level44_860B4Field(privateRecord19, short*, 4) = 0x14;
                            }
                            rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                            Level44_860B4Field(rawWord3, short*, 2) =
                                (short)((unsigned short)Level44_860B4Field(rawWord3, short*, 2) +
                                        1);
                            rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                            argumentWord6 = 0;
                            goto callOriginalSharedAngle;
                        }
                    }
                    break;
                case 2:
                    if (Level44_860B4CountTimerDownView1(privateRecord19 + 4, 2) != 0) {
                        Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 1U;
                        Level44_860B4Field(privateRecord19, short*, 4) = 0;
                    }
                    break;
                case 4:
                case 5:
                    rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                    rawWord2 = Level44_860B4Field(rawWord3, short*, 2);
                    rawWord3 = Level44_860B4Field(rawWord3, int*, 12);
                    rawWord2 *= 16;
                    rawWord2 += rawWord3;
                    rawWord2 = Level44_860B4Field(rawWord2, int*, 8);
                    argumentWord4 = Level44_860B4Field(ownerRecord20, int*, 20);
                    rawWord3 = rawWord2 + 256;
                    rawWord2 = rawWord3 - argumentWord4;
                    if (rawWord2 > 0) {
                        if (rawWord2 < 31)
                            goto storeOriginalTargetHeight;
                        rawWord2 = argumentWord4 + 30;
                        Level44_860B4Field(ownerRecord20, int*, 20) = rawWord2;
                        goto continueOriginalMovement;
                    }
                    if (rawWord2 < 0) {
                        if (rawWord2 >= -30)
                            goto storeOriginalTargetHeight;
                        rawWord2 = argumentWord4 - 30;
                        Level44_860B4Field(ownerRecord20, int*, 20) = rawWord2;
                        goto continueOriginalMovement;
                    }
                    goto retainOriginalEqualHeight;
                storeOriginalTargetHeight:
                    Level44_860B4Field(ownerRecord20, int*, 20) = rawWord3;
                    goto continueOriginalMovement;
                retainOriginalEqualHeight:
                    rawWord3 = Level44_860B4Field(ownerRecord20, volatile int*, 20);
                    __asm__("" ::: "$2", "memory");
                    rawWord2 = 1;
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2));
                    Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = rawWord2;
                    Level44_860B4Field(privateRecord19, short*, 0x28) = 0;
                    Level44_860B4Field(privateRecord19, int*, 12) = rawWord3;
                continueOriginalMovement:
                case 1:
                    argumentWord6 = 0;
                    rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                    argumentWord4 = Level44_860B4Field(ownerRecord20, int*, 12);
                    argumentWord5 = Level44_860B4Field(ownerRecord20, int*, 16);
                    rawWord2 = Level44_860B4Field(rawWord3, short*, 2);
                    rawWord3 = Level44_860B4Field(rawWord3, int*, 12);
                    rawWord2 *= 16;
                    rawWord2 += rawWord3;
                    rawWord3 = Level44_860B4Field(rawWord2, int*, 0);
                    rawWord2 = Level44_860B4Field(rawWord2, int*, 4);
                    rawWord2 = Level44_860B4PlanarHeadingLookupView1(
                        rawWord3 - argumentWord4, rawWord2 - argumentWord5, argumentWord6);
                    argumentWord4 = (int)ownerRecord20;
                    argumentWord5 = rawWord2;
                    argumentWord6 = 1;
                    MATCHING_KEEP(argumentWord6);
                    argumentWord7 = 1;
                    MATCHING_KEEP_CLOBBER(argumentWord7, "$16");
                    addressOrRecord16 = 1;
                    Level44_860B4TurnMobyTowardHeadingView1(argumentWord4, argumentWord5,
                                                            argumentWord6, argumentWord7,
                                                            addressOrRecord16, 0);
                    Level44_860B4ResolveMobyYawStepView1(ownerRecord20, 0x50, 0, 0, 0);
                    rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                    rawWord2 = Level44_860B4Field(rawWord3, short*, 2);
                    rawWord3 = Level44_860B4Field(rawWord3, int*, 12);
                    rawWord2 *= 16;
                    rawWord2 += rawWord3;
                    rawWord2 = Level44_860B4Field(rawWord2, int*, 8);
                    rawWord3 = Level44_860B4Field(ownerRecord20, unsigned char*, 0x49);
                    argumentWord4 = rawWord2 + 256;
                    if (rawWord3 == addressOrRecord16) {
                        rawWord3 = Level44_860B4Field(privateRecord19, int*, 0xC);
                        if (rawWord3 < argumentWord4) {
                            addressOrRecord16 = (int)&originalFrame.sp30;
                            rawWord2 = Level44_860B4Field(ownerRecord20, unsigned char*, 0x46);
                            rawWord2 *= 2;
                            rawWord2 = Level44_860B4Field((int)&Level44_860B4Data65920View1, short*,
                                                          rawWord2);
                            __asm__("" ::: "$4", "memory");
                            argumentWord4 = addressOrRecord16;
                            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                            rawWord2 >>= 2;
                            originalFrame.sp30 = rawWord2;
                            rawWord2 = Level44_860B4Field(ownerRecord20, unsigned char*, 0x46);
                            __asm__("" ::: "$5", "memory");
                            argumentWord5 = (int)ownerRecord20 + 12;
                            rawWord2 *= 2;
                            rawWord2 = Level44_860B4Field((int)&Level44_860B4Data658A0View1, short*,
                                                          rawWord2);
                            __asm__("" ::: "$6", "memory");
                            argumentWord6 = addressOrRecord16;
                            originalFrame.sp38 = 0;
                            __asm__(""
                                    : "=r"(rawWord2)
                                    : "0"(rawWord2), "r"(argumentWord6), "m"(originalFrame.sp38));
                            rawWord2 >>= 2;
                            originalFrame.sp34 = rawWord2;
                            Level44_860B4AddVectorView1(argumentWord4, argumentWord5,
                                                        argumentWord6);
                            originalFrame.sp38 += 0x400;
                            if (Level44_860B4Field(privateRecord19, int*, 0xC) <
                                (Level44_860B4QueryWorldHeightView1(&originalFrame.sp30, 0x800) +
                                 0xC8)) {
                                Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 4U;
                            }
                        } else if (({
                                       rawWord2 = argumentWord4 < rawWord3;
                                       MATCHING_KEEP(rawWord2);
                                       rawWord2;
                                   })) {
                            rawWord2 =
                                Level44_860B4QueryWorldHeightView1(ownerRecord20 + 0xC, 0x800);
                            if ((rawWord2 > 0) &&
                                ((rawWord2 + 0x12C) <
                                 Level44_860B4Field(privateRecord19, int*, 0xC))) {
                                Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 5U;
                            }
                        }
                        rawWord3 = Level44_860B4Field(ownerRecord20, int*, 0x14) + ({
                                       rawWord2 = Level44_860B4Field(
                                           (int)&Level44_860B4Data658A0View1, unsigned short*,
                                           (Level44_860B4Field(privateRecord19, short*, 0x28) * 2));
                                       rawWord2 <<= 16;
                                       MATCHING_KEEP(rawWord2);
                                       rawWord2 >> 23;
                                   });
                        Level44_860B4Field(ownerRecord20, int*, 0x14) = rawWord3;
                        if (rawWord3 < Level44_860B4Field(privateRecord19, int*, 0xC)) {
                            Level44_860B4Field(privateRecord19, short*, 0x28) =
                                (short)(((unsigned short)Level44_860B4Field(privateRecord19, short*,
                                                                            0x28) +
                                         6) &
                                        0xFF);
                            Level44_860B4Field(ownerRecord20, int*, 0x14) =
                                (int)Level44_860B4Field(privateRecord19, int*, 0xC);
                        }
                        Level44_860B4Field(privateRecord19, short*, 0x28) =
                            (short)(((unsigned short)Level44_860B4Field(privateRecord19, short*,
                                                                        0x28) +
                                     6) &
                                    0xFF);
                    }
                    rawWord2 = Level44_860B4Field(privateRecord19, void**, 0);
                    rawWord2 = Level44_860B4ApproximatePlanarDistanceView1(
                        ownerRecord20 + 12, Level44_860B4Field(rawWord2, void**, 12) +
                                                (Level44_860B4Field(rawWord2, short*, 2) * 16));
                    visitedCount21 = 0;
                    if (rawWord2 < 128) {
                        originalStatePair = 1056;
                        MATCHING_KEEP(originalStatePair);
                        rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                        MATCHING_KEEP_CLOBBER(rawWord3, "$18");
                        addressOrOne18 = 1;
                        rawWord2 = Level44_860B4Field(rawWord3, unsigned short*, 2);
                        MATCHING_KEEP_CLOBBER(rawWord2, "$22");
                        recordFlag22 = 32;
                        MATCHING_KEEP(recordFlag22);
                        rawWord2++;
                        Level44_860B4Field(rawWord3, short*, 2) = rawWord2;
                        rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                        MATCHING_KEEP_CLOBBER(rawWord3, "$23");
                        recordTimer23 = 120;
                        cursorOrMatrix17 = Level44_860B4Field(
                            ((Level44_860B4Field(((Level44_860B4Field(rawWord3, short*, 2) * 0x10) +
                                                  Level44_860B4Field(rawWord3, void**, 0xC)),
                                                 unsigned char*, 0xD) *
                              4) +
                             Level44_860B4Data6C730View1),
                            int*, 0);
                    updateOriginalRecordList:
                        rawWord3 = Level44_860B4Field(cursorOrMatrix17, unsigned short*, 0);
                        rawWord3 &= 32767;
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = Level44_860B4Data6C550View1;
                        addressOrRecord16 = rawWord3 + rawWord2;
                        rawWord3 = Level44_860B4Field(addressOrRecord16, short*, 0x36);
                        rawWord2 = 576;
                        if (rawWord3 != rawWord2)
                            goto compareOriginalSecondRecordClass;
                        rawWord3 = Level44_860B4Field(addressOrRecord16, unsigned short*, 0x48);
                        rawWord2 = 1312;
                        if (rawWord3 == originalStatePair)
                            goto updateOriginalSelectedRecord;
                        if (rawWord3 != rawWord2)
                            goto reloadOriginalRecordClass;
                        argumentWord4 = addressOrRecord16;
                        argumentWord5 = 7;
                        __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4));
                        rawWord2 = 46;
                        Level44_860B4Field(addressOrRecord16, volatile unsigned char*, 0x48) =
                            rawWord2;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x41) =
                            addressOrOne18;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x4C) = recordFlag22;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x4D) =
                            addressOrOne18;
                        Level44_860B4RefreshMobySpatialGridAndBasisView1(argumentWord4,
                                                                         argumentWord5);
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x49) = 0;
                        goto advanceOriginalRecordCursor;
                    reloadOriginalRecordClass:
                        MATCHING_BARRIER("memory");
                        rawWord3 = Level44_860B4Field(addressOrRecord16, short*, 0x36);
                    compareOriginalSecondRecordClass:
                        rawWord2 = 605;
                        __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2));
                        if (rawWord3 != rawWord2)
                            goto advanceOriginalRecordCursor;
                        rawWord2 = Level44_860B4Field(addressOrRecord16, unsigned short*, 0x48);
                        if (rawWord2 != originalStatePair)
                            goto advanceOriginalRecordCursor;
                    updateOriginalSelectedRecord:
                        rawWord3 = Level44_860B4Field(addressOrRecord16, int*, 0);
                        Level44_860B4Field(addressOrRecord16, volatile unsigned char*, 0x48) = 0;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x41) =
                            addressOrOne18;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x4C) = recordFlag22;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x4D) =
                            addressOrOne18;
                        rawWord2 = Level44_860B4Field(rawWord3, unsigned short*, 0);
                        Level44_860B4Field(rawWord3, unsigned short*, 0) = recordTimer23;
                        Level44_860B4Field(rawWord3, unsigned short*, 2) = rawWord2;
                        Level44_860B4Field(addressOrRecord16, unsigned char*, 0x49) = 0;
                    advanceOriginalRecordCursor:
                        rawWord2 = Level44_860B4Field(cursorOrMatrix17, short*, 0);
                        cursorOrMatrix17 += 2;
                        if (rawWord2 >= 0) {
                            visitedCount21 += 1;
                            if (visitedCount21 < 0x14) {
                                goto updateOriginalRecordList;
                            }
                        }
                        argumentWord6 = 0;
                        rawWord2 = 3;
                        Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = rawWord2;
                        rawWord3 = Level44_860B4Field(privateRecord19, int*, 0);
                        rawWord2 = 20;
                        Level44_860B4Field(privateRecord19, short*, 4) = rawWord2;
                    callOriginalSharedAngle:
                        argumentWord4 = Level44_860B4Field(ownerRecord20, int*, 12);
                        argumentWord5 = Level44_860B4Field(ownerRecord20, int*, 16);
                        rawWord2 = Level44_860B4Field(rawWord3, short*, 2);
                        rawWord3 = Level44_860B4Field(rawWord3, int*, 12);
                        rawWord2 *= 16;
                        rawWord2 = rawWord2 + rawWord3;
                        rawWord3 = Level44_860B4Field(rawWord2, int*, 0);
                        rawWord2 = Level44_860B4Field(rawWord2, int*, 4);
                        rawWord2 = Level44_860B4PlanarHeadingLookupView1(
                            rawWord3 - argumentWord4, rawWord2 - argumentWord5, argumentWord6);
                        Level44_860B4Field(ownerRecord20, unsigned char*, 0x46) = rawWord2;
                    }
                    break;
                case 3:
                    if (Level44_860B4CountTimerDownView1(privateRecord19 + 4, 2) != 0) {
                        rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                        if (Level44_860B4Field(((Level44_860B4Field(rawWord3, short*, 2) * 0x10) +
                                                Level44_860B4Field(rawWord3, void**, 0xC)),
                                               unsigned char*, 0xC) == 1) {
                            Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 2U;
                            rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                            Level44_860B4Field(rawWord3, short*, 2) =
                                (short)((unsigned short)Level44_860B4Field(rawWord3, short*, 2) +
                                        1);
                        } else {
                            Level44_860B4Field(ownerRecord20, unsigned char*, 0x49) = 0U;
                            rawWord3 = Level44_860B4Field(privateRecord19, void**, 0);
                            Level44_860B4Field(privateRecord19, short*, 4) = 0x3C;
                            Level44_860B4Field(privateRecord19, short*, 6) = Level44_860B4Field(
                                ((Level44_860B4Field(rawWord3, short*, 2) * 0x10) +
                                 Level44_860B4Field(rawWord3, void**, 0xC)),
                                unsigned char*, 0xD);
                        }
                    }
                    break;
            }
        case 1:
            if (Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) == 1) {
                if (Level44_860B4CountTimerDownView1(privateRecord19 + 4, 2) != 0) {
                    Level44_860B4Field(ownerRecord20, unsigned char*, 0x48) = 2U;
                }
            }
            Level44_860B4Field((int)&Level44_860B4Data70328View1, int*, 0x20C) = 0x10028000;
            Level44_860B4Field((int)&Level44_860B4Data70328View1, int*, 0x23C) = 0x73;
            Level44_860B4CopyVectorView1((int)&Level44_860B4Data70328View1 + 0x20C + 0x20,
                                         ownerRecord20 + 0xC);
            Level44_860B4Field((int)&Level44_860B4Data70328View1, unsigned char*, 0x228) =
                (unsigned char)Level44_860B4Field(ownerRecord20, unsigned char*, 0x44);
            Level44_860B4Field((int)&Level44_860B4Data70328View1, unsigned char*, 0x229) =
                (unsigned char)Level44_860B4Field(ownerRecord20, unsigned char*, 0x45);
            Level44_860B4Field((int)&Level44_860B4Data70328View1, unsigned char*, 0x22A) =
                (unsigned char)Level44_860B4Field(ownerRecord20, unsigned char*, 0x46);
            if (Level44_860B4Field((int)&Level44_860B4Data70328View1, int*, 0x280) !=
                Level44_860B4Field(privateRecord19, int*, 0x30)) {
                Level44_860B4Field(privateRecord19, int*, 0x30) =
                    (int)Level44_860B4Field((int)&Level44_860B4Data70328View1, int*, 0x280);
                rawWord2 =
                    Level44_860B4Field((int)&Level44_860B4Data70328View1, volatile int*, 0x280);
                if (!rawWord2) {
                    argumentWord5 = 442;
                    goto updateOriginalCounterDescriptor;
                }
                rawWord2 = rawWord2 < 3;
                argumentWord5 = 441;
                if (!rawWord2)
                    argumentWord5 = 440;
            updateOriginalCounterDescriptor:
                Level44_860B4RefreshHudEntryByHandleView1(
                    Level44_860B4Field(privateRecord19, int*, 0x2C), argumentWord5);
            }
            Level44_860B4BuildOrientedInputPairView1(&originalFrame.sp50, 0);
            rawWord3 = (Level44_860B4Field(privateRecord19, unsigned short*, 8) +
                        (originalFrame.sp54 >> 3)) &
                       0xFFF;
            Level44_860B4Field(privateRecord19, unsigned short*, 8) = (unsigned short)rawWord3;
            if (rawWord3 >= 0x801) {
                rawWord2 = rawWord3 - 4096;
                Level44_860B4Field(privateRecord19, unsigned short*, 8) = rawWord2;
            }
            if ((short)Level44_860B4Field(privateRecord19, unsigned short*, 8) < -0xD0) {
                rawWord2 = -208;
                Level44_860B4Field(privateRecord19, short*, 8) = rawWord2;
            }
            if ((short)Level44_860B4Field(privateRecord19, unsigned short*, 8) >= 0xD1) {
                Level44_860B4Field(privateRecord19, unsigned short*, 8) = 0xD0U;
            }
            rawWord3 = (Level44_860B4Field(privateRecord19, unsigned short*, 0xA) -
                        (originalFrame.sp50 >> 3)) &
                       0xFFF;
            Level44_860B4Field(privateRecord19, unsigned short*, 0xA) = (unsigned short)rawWord3;
            if (rawWord3 >= 0x801) {
                rawWord2 = rawWord3 - 4096;
                Level44_860B4Field(privateRecord19, unsigned short*, 10) = rawWord2;
            }
            if ((short)Level44_860B4Field(privateRecord19, unsigned short*, 0xA) < -0x12C) {
                rawWord2 = -300;
                Level44_860B4Field(privateRecord19, short*, 10) = rawWord2;
            }
            if ((short)Level44_860B4Field(privateRecord19, unsigned short*, 0xA) >= 0x12D) {
                Level44_860B4Field(privateRecord19, unsigned short*, 0xA) = 0x12CU;
            }
            addressOrOne18 = (int)&Level44_860B4Data6E03CView1;
            MATCHING_KEEP(addressOrOne18);
            argumentWord4 = (int)&originalFrame.sp30;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = Level44_860B4Field(addressOrOne18, unsigned short*, 0);
            __asm__("" ::: "$17", "memory");
            cursorOrMatrix17 = (int)&originalFrame.sp58;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(cursorOrMatrix17));
            Level44_860B4Field(&originalFrame.sp30, unsigned short*, 0) = rawWord2;
            __asm__("" ::"m"(originalFrame.sp30) : "$5");
            rawWord2 = Level44_860B4Data6E03EView1;
            rawWord3 = Level44_860B4Field(privateRecord19, unsigned short*, 8);
            __asm__("" ::: "$5", "memory");
            argumentWord5 = cursorOrMatrix17;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3), "r"(argumentWord5));
            rawWord2 += rawWord3;
            rawWord2 &= 4095;
            Level44_860B4Field(&originalFrame.sp30, unsigned short*, 2) = rawWord2;
            __asm__("" ::"m"(originalFrame.sp30) : "$6");
            rawWord2 = Level44_860B4Data6E040View1;
            rawWord3 = Level44_860B4Field(privateRecord19, unsigned short*, 10);
            __asm__("" ::: "$6", "memory");
            argumentWord6 = (int)ownerRecord20 + 32;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(rawWord3), "r"(argumentWord6));
            rawWord2 += rawWord3;
            rawWord2 &= 4095;
            Level44_860B4Field(&originalFrame.sp30, unsigned short*, 4) = rawWord2;
            Level44_860B4BuildEulerBasisPairView1(argumentWord4, argumentWord5, argumentWord6);
            Level44_860B4TransposePackedHalfwordMatrix3x3View1(cursorOrMatrix17, cursorOrMatrix17);
            argumentWord4 = cursorOrMatrix17;
            MATCHING_KEEP(argumentWord4);
            addressOrRecord16 = (int)&originalFrame.sp40;
            originalFrame.sp40 = 512;
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0;
            Level44_860B4TransformVectorByBasisView1(argumentWord4, addressOrRecord16,
                                                     addressOrRecord16);
            argumentWord4 = privateRecord19 + 16;
            argumentWord5 = addressOrRecord16;
            MATCHING_KEEP(argumentWord5);
            addressOrOne18 -= 28;
            Level44_860B4AddVectorView1(argumentWord4, argumentWord5, addressOrOne18);
            originalFrame.sp40 = 16384;
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0;
            Level44_860B4TransformVectorByBasisView1(cursorOrMatrix17, addressOrRecord16,
                                                     addressOrRecord16);
            cursorOrMatrix17 = privateRecord19 + 28;
            Level44_860B4AddVectorView1(cursorOrMatrix17, addressOrRecord16, addressOrOne18);
            Level44_860B4ProjectPointWithGlobalGteMatrixView1((int)&Level44_860B4Data714F4View1,
                                                              cursorOrMatrix17, 1);
            return;
        case 3:
            rawWord2 = Level44_860B4Field(privateRecord19, short*, 4);
            rawWord3 = rawWord2;
            if (rawWord2 > 0) {
                MATCHING_KEEP(rawWord3);
                rawWord2 = rawWord3 - 1;
                Level44_860B4Field(privateRecord19, short*, 4) = rawWord2;
                if ((rawWord2 << 0x10) <= 0) {
                    Level44_860B4Data6E160View1 = 0;
                }
            }
        finishOriginalDispatch:
            MATCHING_BARRIER("memory");
            return;
        default:
            return;
    }
}
#undef Level44_860B4Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Actor84070Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor84070QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int Actor84070RandBetween() __asm__("func_8003636C");
int Actor84070AddVector() __asm__("func_8004F194");
int Actor84070AllocateFiveWordSlot() __asm__("func_80050B00");
int Actor84070ClearFiveWordSlotMarker() __asm__("func_80050B88");
int Actor84070DeleteMoby() __asm__("func_80055B18");
extern short Actor84070D_80065920[] __asm__("D_80065920");
extern short Actor84070D_800658A0[] __asm__("D_800658A0");
extern void* (*Actor84070SpawnParticle)(int, int, void*, void*)__asm__("SpawnParticle");
int Actor84070ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
int Actor84070PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Actor84070AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Actor84070D_8006E020 __asm__("D_8006E020");
extern int Actor84070D_8006E024 __asm__("D_8006E024");
extern unsigned short Actor84070D_8006E040 __asm__("D_8006E040");
void func_level_44_80086D50(void* input) {
    register unsigned char* owner __asm__("$20") = input;
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
    register int* originalPlayerVector16 __asm__("$16");
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
    register void* state __asm__("$23");
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
    state = ((Moby*)owner)->mobyTag;
    frame.sp38 = *Actor84070Field(state, int**, 0x10);
    ((Moby*)owner)->unknown3[0] = 0;
    ((Moby*)owner)->lowDrawDistance = 0;
    ((Moby*)owner)->drawn = 0;
    initialCondition = Actor84070Field(state, short*, 2);
    if (initialCondition != 0) {
        initialCondition = initialCondition < 10;
        goto initialBound;
    }
    initialCondition = initialCondition < 10;
    MATCHING_KEEP(initialCondition);
    Actor84070SpawnParticle(10, 70, owner + 12, (void*)30);
    initialCondition = Actor84070Field(state, short*, 2) < 10;
initialBound:
    if (initialCondition) {
        randomResult = Actor84070RandBetween(0, 0x400);
        value3 = ((Moby*)owner)->position.x - 0x200;
        MATCHING_KEEP(value3);
        value3 += randomResult;
        MATCHING_KEEP(value3);
        frame.sp18 = value3;
        randomResult = Actor84070RandBetween(0, 0x400);
        value3 = ((Moby*)owner)->position.y - 0x200;
        MATCHING_KEEP(value3);
        value3 += randomResult;
        MATCHING_KEEP(value3);
        frame.sp1C = value3;
        randomResult = Actor84070RandBetween(0, 0x100);
        value3 = ((Moby*)owner)->position.z;
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
            work2 = ((Moby*)owner)->angle.roll;
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
            work2 = (((Moby*)owner)->angle.yaw + 128) & 255;
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
            Actor84070AllocateFiveWordSlot(call4, call5, call6, value12 + 12, 1);
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
        if (value12)
            goto originalCleanup;
        call4 = owner + 12;
        MATCHING_KEEP(call4);
        originalPlayerVector16 = &Actor84070D_8006E020;
        if (Actor84070ApproximatePlanarDistance(call4, originalPlayerVector16) < 3000)
            goto originalCleanup;
        work2 = Actor84070PlanarHeadingLookup(((Moby*)owner)->position.x - *originalPlayerVector16,
                                              ((Moby*)owner)->position.y - Actor84070D_8006E024, 0);
        if (Actor84070AbsoluteByteAngleDelta(work2, (int)(Actor84070D_8006E040 << 16) >> 20) < 65)
            goto done;
    }
originalCleanup:
    {
        temp_a0_3 = Actor84070Field(state, int*, 8);
        if (temp_a0_3 != 0) {
            Actor84070ClearFiveWordSlotMarker(temp_a0_3);
        }
        Actor84070DeleteMoby(owner);
    }
done:;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_44/moby/func_level_44_800873C0.s SHA256 ace1010470ad953a5c3f675fd463960a457cd5edad39a889146bb09e2e002fd9. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int SharedRecord583QueryDynamicMobyGeometry() __asm__("func_8001BA30");
/* extern */
int SharedRecord583TestPlayerSphereOverlap() __asm__("func_8001C288");
/* extern */
int SharedRecord583TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
signed char* SharedRecord583AllocateFiveWordSlot() __asm__("func_80050B00");
/* extern */
int SharedRecord583ClearFiveWordSlotMarker() __asm__("func_80050B88");
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
void func_level_44_800873C0(Moby* inputOwner) {
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
        if (SharedRecord583TestPlayerSphereOverlap(&owner->position, 0x400, 7) != 0) {
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
        if (SharedRecord583QueryDynamicMobyGeometry(&owner->position, 0x5DC, 1, 0, 0x40000,
                                                    owner) != 0) {
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
        word2 = (int)SharedRecord583AllocateFiveWordSlot(caller4, caller5, caller6,
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
        SharedRecord583ClearFiveWordSlotMarker(caller4);
        loadedAddress15 = scratch.sp38;
    }
    caller4 = M2C_FIELD(loadedAddress15, void**, 12);
    if (caller4)
        SharedRecord583ClearFiveWordSlotMarker(caller4);
    SharedRecord583DeleteMoby(owner);
doneRaw:;
}
#undef SharedRecord583Low
#undef SharedRecord583High
#undef M2C_FIELD
