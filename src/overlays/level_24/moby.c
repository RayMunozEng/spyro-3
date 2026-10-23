#include "matching.h"
#include "common.h"
#include "camera.h"
#include "savepoint.h"
#include "spu.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
#include "ovl_header.h"
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
void func_level_24_8007572C(void* input) {
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
void func_level_24_80076388(Moby* mobyArgument) {
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
void func_level_24_80076A14(void* input) {
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
void func_level_24_80077F64(Moby* moby) {
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
void func_level_24_800780A0(Moby* moby) {
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
void func_level_24_8007815C(Moby* moby) {
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
void func_level_24_80078210(Moby* moby) {
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
void func_level_24_800784D0(Moby* mobyArgument) {
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

#define Controller789F0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int Controller789F0D_8006C574 __asm__("D_8006C574");
extern int Controller789F0D_8006C578 __asm__("D_8006C578");
extern int Controller789F0D_8006C648 __asm__("D_8006C648");
extern int Controller789F0D_8006E53C __asm__("D_8006E53C");
int Controller789F0PrepareCameraMode9Vectors(int, int) __asm__("func_80013AE4");
int Controller789F0TransitionCameraModes9And10(int) __asm__("func_80013B7C");
int Controller789F0CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller789F0ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
int Controller789F0RandBetween(int, int) __asm__("func_8003636C");
int Controller789F0RandSignedBetween(int, int) __asm__("func_800363DC");
int Controller789F0SpawnMobyFromValueSelector(void*, int, int, int) __asm__("func_80036A68");
int Controller789F0PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller789F0CopyVector(void*, void*) __asm__("func_8004F178");
int Controller789F0DeleteMoby(void*) __asm__("func_80055B18");
int Controller789F0RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Controller789F0RefreshMobyQueryByte52(void*) __asm__("func_80056270");
extern void* (*Controller789F0SpawnMoby)(int, void*)__asm__("SpawnMoby");
extern int (*Controller789F0SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level24/800789F0 and level34/80078F2C; 294 equal original
 * instructions and helper/global symbols each, no owned table rows.
 * Preserve 88-byte frame and vectors at 0x10/0x20/0x30, original helper
 * arguments (including retained incoming owner), 12 child attempts, four
 * randomized particles and 40/8 repeat paths, signed record-index reads,
 * 16-byte record strides, unsigned halfword increment, counter producer
 * and exact shared state/loop branch entries. Units, helper semantics and
 * caller cadence remain unresolved; updates are once per invocation.
 * Confidence: exact original native/linked words and complete retail SHA
 * set, not semantic runtime review. Falsifiable vectors: all 588 original
 * words and EXE/all-overlay hashes. Empty constraints retain scheduling
 * without opcode patches.
 */
void func_level_24_800789F0(void* input) {
    struct {
        Vector3D first;
        int pad1C;
        Vector3D second;
        int pad2C;
        Vector3D third;
        int pad3C;
    } frame;
    register unsigned char* owner __asm__("$16") = input;
    register int recordOffset __asm__("$5");
    register int three __asm__("$19");
    register int one __asm__("$18");
    register void* savedVector __asm__("$19");
    register int recordBase __asm__("$2");
    register int updatedCounter __asm__("$2");
    register int spawnIndex __asm__("$17");
    register int randomParticleIndex __asm__("$17");
    register int repeatIndex __asm__("$17");
    unsigned char nextState;
    register void* ownerPosition __asm__("$18");
    register void* repeatPosition __asm__("$18");
    register void* tag __asm__("$20");
    void* child;
    void* positionRecord;
    register void* nextRecord __asm__("$2");
    void* countRecord;
    void* updatedRecord;

    tag = ((Moby*)owner)->mobyTag;
    if (((Moby*)owner)->damageFlags != 0) {
        if (((Moby*)owner)->state == 1) {
            Controller789F0PlayMobySoundEvent(owner, 0, 0);
            ((Moby*)owner)->updateDistance = 0xFF;
            countRecord = Controller789F0Field(tag, void**, 0);
            Controller789F0Field(tag, int*, 4) = 0x1E;
            spawnIndex = 0;
            if (Controller789F0Field(countRecord, short*, 2) >=
                Controller789F0Field(countRecord, short*, 0)) {
                Controller789F0Field(owner, signed char*, 0x49) = 0x70;
                three = 3;
                one = 1;
                MATCHING_KEEP2(three, one);
            spawnChildLoop:
                if ((Controller789F0D_8006C578 - Controller789F0D_8006C574) >= 0x15) {
                    child = Controller789F0SpawnMoby(0x132, owner);
                    if (child != 0) {
                        if (spawnIndex < 5) {
                            Controller789F0Field(child, signed char*, 0x49) = three;
                        } else {
                            Controller789F0Field(child, signed char*, 0x3C) = one;
                        }
                    }
                    spawnIndex += 1;
                    if (spawnIndex < 0xC) {
                        goto spawnChildLoop;
                    }
                }
                randomParticleIndex = 0;
                do {
                    Controller789F0CopyVector(&frame.first.x, owner + 0xC);
                    randomParticleIndex += 1;
                    {
                        register int randomValue __asm__("$2") = rand();
                        register int previous __asm__("$3") = frame.first.x;
                        MATCHING_KEEP2(previous, randomValue);
                        randomValue &= 511;
                        previous += 256;
                        previous -= randomValue;
                        frame.first.x = previous;
                    }
                    {
                        register int randomValue __asm__("$2") = rand();
                        register int previous __asm__("$3") = frame.first.y;
                        MATCHING_KEEP2(previous, randomValue);
                        randomValue &= 511;
                        previous += 256;
                        previous -= randomValue;
                        frame.first.y = previous;
                    }
                    frame.first.z += rand() & 0x1FF;
                    Controller789F0SpawnParticle(1, 2, &frame.first.x, 0);
                    Controller789F0SpawnParticle(4, 0x46, &frame.first.x, 0x18);
                } while (randomParticleIndex < 4);
                Controller789F0SpawnMobyFromValueSelector(owner, 0, 0, 0);
                Controller789F0DeleteMoby(owner);
                return;
            }
            savedVector = &frame.second.x;
            MATCHING_KEEP(savedVector);
            ownerPosition = owner + 12;
            do {
                Controller789F0CopyVector(savedVector, ownerPosition);
                {
                    register int result __asm__("$2") = Controller789F0RandSignedBetween(0, 300);
                    register int zero __asm__("$4") = 0;
                    register int range __asm__("$5") = 300;
                    register int previous __asm__("$3");
                    MATCHING_KEEP2(zero, range);
                    previous = ((Moby*)owner)->position.x;
                    MATCHING_KEEP(previous);
                    spawnIndex++;
                    previous += result;
                    ((Moby*)owner)->position.x = previous;
                    result = Controller789F0RandSignedBetween(zero, range);
                    zero = 0;
                    MATCHING_KEEP(zero);
                    previous = ((Moby*)owner)->position.y;
                    MATCHING_KEEP_CLOBBER(previous, "$5");
                    range = 700;
                    MATCHING_KEEP2(range, previous);
                    previous += result;
                    ((Moby*)owner)->position.y = previous;
                    result = Controller789F0RandBetween(zero, range);
                    {
                        register int type __asm__("$4") = 1;
                        register int selector __asm__("$5") = 12;
                        register void* particleOwner __asm__("$6") = owner;
                        register int mode __asm__("$7") = 3;
                        register int (*emit)(int, int, void*, int) __asm__("$8");
                        MATCHING_KEEP4(type, selector, particleOwner, mode);
                        previous = ((Moby*)owner)->position.z;
                        emit = Controller789F0SpawnParticle;
                        MATCHING_KEEP2(emit, previous);
                        previous += result;
                        ((Moby*)owner)->position.z = previous;
                        emit(type, selector, particleOwner, mode);
                    }
                }
                Controller789F0CopyVector(ownerPosition, savedVector);
            } while (spawnIndex < 0x28);
            Controller789F0Field(owner, signed char*, 0x41) = 0;
            Controller789F0Field(owner, signed char*, 0x4C) = 0;
            Controller789F0Field(owner, signed char*, 0x4D) = 0;
            ((Moby*)owner)->state = 2U;
            goto readState;
        }
        goto readStateAlias;
    }
readState:
readStateAlias:
    ((Moby*)owner)->damageFlags = 0;
    switch ((int)((Moby*)owner)->state) { /* irregular */
        case 0:
            Controller789F0Field(Controller789F0Field(tag, void**, 0), short*, 2) = 0;
            goto storeStateOne;
        case 2:
            if (Controller789F0CountTimerDown(tag + 4, 4) != 0) {
                Controller789F0Field(owner, signed char*, 0x41) = 1;
                Controller789F0Field(owner, signed char*, 0x4C) = 0x28;
                Controller789F0Field(owner, signed char*, 0x4D) = 1;
                positionRecord = Controller789F0Field(tag, void**, 0);
                Controller789F0CopyVector(
                    owner + 0xC, Controller789F0Field(positionRecord, int*, 0xC) +
                                     (Controller789F0Field(positionRecord, short*, 2) * 0x10));
                Controller789F0RefreshMobySpatialGridAndBasis(owner, 2);
                nextRecord = Controller789F0Field(tag, void**, 0);
                recordOffset = Controller789F0Field(nextRecord, short*, 2);
                recordBase = Controller789F0Field(nextRecord, int*, 12);
                MATCHING_KEEP2(recordOffset, recordBase);
                recordOffset *= 16;
                {
                    register int nextAddress __asm__("$4") = recordOffset + 16;
                    MATCHING_KEEP(nextAddress);
                    nextAddress = recordBase + nextAddress;
                    Controller789F0PrepareCameraMode9Vectors(nextAddress,
                                                             recordBase + recordOffset);
                }
                updatedRecord = Controller789F0Field(tag, void**, 0);
                Controller789F0Field(updatedRecord, short*, 2) =
                    (short)((unsigned short)Controller789F0Field(updatedRecord, short*, 2) + 2);
                Controller789F0Field(tag, int*, 4) = 0x14;
                ((Moby*)owner)->subtype = 0xFE;
                Controller789F0ProbeGroundFromRaisedMoby(owner);
                Controller789F0RefreshMobyQueryByte52(owner);
                nextState = 3;
                goto storeNextState;
            }
            break;
        case 3:
            if (Controller789F0CountTimerDown(tag + 4, 4) != 0) {
                ((Moby*)owner)->state = 4U;
                return;
            }
            break;
        case 4:
            if (Controller789F0Field(tag, int*, 4) < 0x10) {
                repeatIndex = 0;
                savedVector = &frame.third.x;
                MATCHING_KEEP(savedVector);
                repeatPosition = owner + 12;
                {
                    register void* copyArgument __asm__("$4") = savedVector;
                    do {
                        MATCHING_KEEP(copyArgument);
                        Controller789F0CopyVector(copyArgument, repeatPosition);
                        {
                            register int result __asm__("$2") =
                                Controller789F0RandSignedBetween(0, 300);
                            register int zero __asm__("$4") = 0;
                            register int range __asm__("$5") = 300;
                            register int previous __asm__("$3");
                            MATCHING_KEEP2(zero, range);
                            previous = ((Moby*)owner)->position.x;
                            MATCHING_KEEP(previous);
                            repeatIndex++;
                            previous += result;
                            ((Moby*)owner)->position.x = previous;
                            result = Controller789F0RandSignedBetween(zero, range);
                            zero = 0;
                            MATCHING_KEEP(zero);
                            previous = ((Moby*)owner)->position.y;
                            MATCHING_KEEP_CLOBBER(previous, "$5");
                            range = 700;
                            MATCHING_KEEP2(range, previous);
                            previous += result;
                            ((Moby*)owner)->position.y = previous;
                            result = Controller789F0RandBetween(zero, range);
                            {
                                register int type __asm__("$4") = 1;
                                register int selector __asm__("$5") = 12;
                                register void* particleOwner __asm__("$6") = owner;
                                register int mode __asm__("$7") = 3;
                                register int (*emit)(int, int, void*, int) __asm__("$8");
                                MATCHING_KEEP4(type, selector, particleOwner, mode);
                                previous = ((Moby*)owner)->position.z;
                                emit = Controller789F0SpawnParticle;
                                MATCHING_KEEP2(emit, previous);
                                previous += result;
                                ((Moby*)owner)->position.z = previous;
                                emit(type, selector, particleOwner, mode);
                            }
                        }
                        Controller789F0CopyVector(repeatPosition, savedVector);
                        copyArgument = savedVector;
                    } while (repeatIndex < 8);
                }
            }
            updatedCounter = Controller789F0Field(tag, int*, 4);
            MATCHING_KEEP_CLOBBER(updatedCounter, "$3");
            {
                register int increment __asm__("$3") = Controller789F0D_8006C648;
                updatedCounter += increment;
            }
            Controller789F0Field(tag, int*, 4) = updatedCounter;
            MATCHING_KEEP_VOLATILE_CLOBBER(updatedCounter, "memory");
            {
                register int belowLimit __asm__("$2") = updatedCounter < 120;
                register int prepared __asm__("$4");
                MATCHING_KEEP_CLOBBER(belowLimit, "$4");
                prepared = 1;
                if (!belowLimit || (Controller789F0D_8006E53C & 0x800)) {
                    MATCHING_KEEP(prepared);
                    ((Moby*)owner)->updateDistance = 0x1E;
                    Controller789F0TransitionCameraModes9And10(prepared);
                    goto storeStateOne;
                }
            }
            break;
    }
    return;
storeStateOne:
    nextState = 1;
storeNextState:
    ((Moby*)owner)->state = nextState;
}

#undef Controller789F0Field


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
void func_level_24_80078E88(Moby* moby) {
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
void func_level_24_80079208(Moby* moby) {
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
void func_level_24_8007950C(void* input) {
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
void func_level_24_8007A080(Moby* moby) {
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
/* SCUS-94467 USA Rev0, level24 8007A4B0, exactly908 instruction words.
 * Original assembly SHA256 4b84213136345c689cff3c52fe6a946523d6b9a08f3fe73c0a63dcc25fbc9412.
 * Exact original899 sibling20_80079A48 differs only at original word502:
 * this actor inserts the ignored 1BA30 call using the current radius, zero
 * third/fourth words, mask0x10000000 and complete owner word before the
 * existing radius+1000 call. Original S0 retains owner.position for these
 * two calls, then receives the second call's returned pointer. All other
 * native words, actual branch targets, symbols and addends are rechecked.
 * This is independent of the unrelated908-instruction level11 controller
 * whose separate22-word selector table is not part of this actor family.
 * AI generated; not human reviewed. Full linked retail hashes remain
 * required; all inherited899 numeric/helper/cadence/runtime gaps stay open.
 */
/* SCUS-94467 USA Rev0; original908-word level24 actor function.
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
extern Vector3D Original908PlayerPositionView __asm__("D_80070328");
extern Vector3D Original908CameraPositionView __asm__("D_8006E020");
/* Local views preserve existing TU declarations. Symbols and word ABI are
* verified against original callers and existing tracers.h/tracers.c. */
void* Original908CreateHandleView(int, int, int, int, int) __asm__("func_80050B00");
void Original908ReleaseHandleView(int*) __asm__("func_80050B88");
#include "ovl_header.h"
extern int D_8006C574, D_8006C578, D_8006C640, D_8006C7E8, D_80071924, D_80071934;
extern unsigned char* Original908ModelTableView[] __asm__("D_8006EE2C");
extern unsigned char D_8006D048[];
extern short D_800658A0[256], D_80065920[256];
int func_8001830C(Vector3D*, Vector3D*, int, int, int);
int func_80019138(Vector3D*, int, int, int, int, Moby*);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
int func_80040954(int);
void func_8004EA90(Angle*, SHORTMATRIX*, int);
void func_8004F0E8(Vector3D*, int);
void Original908MatrixCallView(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int func_8004EDE8(Vector3D*, int);
int Original908PlayMobySoundEventView(Moby*, int, int) __asm__("func_8003BABC");
void func_80055D24(Moby*, int);
int rand(void);
typedef struct {
    unsigned char current0, next1, other2, otherNext3, byte4, byte5, byte6, byte7;
} Original908IndexWords;
typedef struct {
    short cursor0;
    unsigned short count2;
    Vector3D positions4[12];
    Vector3D vertices94[10];
    int sentinel10C;
    unsigned char colours110[8];
    Original908IndexWords indices118[5];
    int sentinel140;
} Original908Buffer;
typedef struct {
    Vector3D16 vector0;
    unsigned char byte6, timer7;
    Original908Buffer* buffer8;
    int* handleC;
    int words10[2];
} Original908PrivateRecord;
typedef struct {
    int word0;
    unsigned int word4;
} Original908FlagWords;
static __inline__ void Original908InitializeChild(Moby* child) {
    unsigned char* descriptor;
    unsigned int first, flag;
    ((volatile Moby*)child)->state = 1;
    child->unknown3[1] = 0;
    descriptor = *(unsigned char**)(Original908ModelTableView[child->mobyClass] + 0x40);
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
} Original908CompleteProduct;
void func_level_24_8007A4B0(Moby* moby) {
    Moby* owner = moby;
    int x = owner->position.x;
    register Original908PrivateRecord* tag __asm__("$22") = owner->mobyTag;
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
    Original908IndexWords* indices;
    if (x < 1024 || (y = owner->position.y) < 1024 || owner->position.z < 1024 || x > 0x3C000 ||
        y > 0x3C000) {
        if (tag->handleC)
            Original908ReleaseHandleView(tag->handleC);
        func_80055B18(owner);
        /* Original continues after this helper; no early return is added. */
    }
    MATCHING_OBSERVE(tag);
    if (owner->state != 2 && owner->substate == 0) {
        Vector3D* position = &owner->position;
        Original908Buffer* buffer = tag->buffer8;
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
        if (func_8001830C(&owner->position, &Original908PlayerPositionView, 2, 0, 0))
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
                    Original908InitializeChild(child);
                }
            }
            if (owner->state == 0 && func_800359A4((char*)&tag->timer7, 1)) {
                if (tag->handleC)
                    Original908ReleaseHandleView(tag->handleC);
                tag->handleC = 0;
                owner->state = 1;
            }
            break;
        }
        case 1: {
            register int loopIndex __asm__("$20");
            Original908PlayMobySoundEventView(owner, 1, 0);
            if (D_8006C578 - D_8006C574 >= 21 && D_8006C7E8 >= 30001) {
                Moby* child = SpawnMoby(326, owner);
                if (child) {
                    D_8006C7E8 -= 1500;
                    child->unknown4 = 7;
                }
            }
            loopIndex = 0;
            if (D_8006C578 - D_8006C574 >= 21) {
                register Vector3D* cameraPosition __asm__("$21") = &Original908CameraPositionView;
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
                    Original908MatrixCallView(&originalFrame.matrix48, &originalFrame.vector28,
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
            func_8001BA30(&owner->position, radius, 0, 0, 0x10000000, owner);
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
                    Original908FlagWords* flags =
                        (*(Original908FlagWords***)(D_8006D048 + 0x14))[*sourceWord & 63];
                    flags->word4 |= 0x950000;
                }
            }
            if (func_800359A4((char*)&tag->timer7, 1)) {
                if (tag->handleC)
                    Original908ReleaseHandleView(tag->handleC);
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
        Original908Buffer* buffer = tag->buffer8;
        register int previousCursor3 __asm__("$3") = buffer->cursor0;
        register int previousPositionByteOffset2 __asm__("$2") = previousCursor3 * 12;
        register int initialPositionByteOffset20 __asm__("$20");
        int retainedPositionByteOffset;
        register int nextCursorInput6 __asm__("$6") = previousCursor3 + 1;
        Original908CompleteProduct completeDivisionProduct;
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
            Original908MatrixCallView(&originalFrame.matrix78, firstVector68, firstVector68);
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
                Original908MatrixCallView(&originalFrame.matrix78, secondVector18, secondVector18);
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
            Original908IndexWords* item = (Original908IndexWords*)(loopIndex * 8 + (int)indices);
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
            tag->handleC = (int*)Original908CreateHandleView(callVertices, callColours, callIndices,
                                                             callWords, 1);
        }
    }
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
void func_level_24_8007B2E0(Moby* moby) {
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
void func_level_24_8007B648(Moby* owner) {
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

void func_level_24_8007B7D4(Moby* moby) {
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
void func_level_24_8007B7F4(Moby* moby) {
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

#define Controller810A0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller810A0Sin[] __asm__("D_800658A0");
extern unsigned char Controller810A0Cos[] __asm__("D_80065920");
extern unsigned short Controller810A0Angle0 __asm__("D_8006E03E"), Controller810A0Angle1
    __asm__("D_8006E040");
extern unsigned char Controller810A0Player[] __asm__("D_80070328");
extern void* Controller810A0Models[] __asm__("D_8006EE2C");
extern int D_8006C770;
extern void* (*Controller810A0Spawn)(int, void*)__asm__("SpawnMoby");
int Controller810A0QueryWorldSegment(void*, void*) __asm__("func_80018368");
void* Controller810A0QueryDynamicMobyGeometry(void*, int, int, int, int,
                                              int) __asm__("func_8001BA30");
int Controller810A0TestPlayerSphereOverlap(void*, int, int) __asm__("func_8001C288");
int Controller810A0CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller810A0PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller810A0PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller810A0CopyVector(void*, void*) __asm__("func_8004F178");
int Controller810A0AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller810A0AllocateVectorTrailRecord(void*, int, int, int) __asm__("func_80050844");
int Controller810A0ClearHistorySourceWord(int) __asm__("func_800509E8");
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
void func_level_24_8007B948(void* input) {
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
        state = ((Moby*)owner)->state;
        tag = ((Moby*)owner)->mobyTag;
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
                spawned = Controller810A0Spawn(((Moby*)owner)->mobyClass, owner);
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
                        Controller810A0AllocateVectorTrailRecord(spawned + 0xC, 7, 0xA, 0x4080E0);
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
    ((Moby*)owner)->state = 0xAU;
    idlePosition = owner + 0xC;
idle:
    nearby = Controller810A0QueryDynamicMobyGeometry(idlePosition, 0x7D0, 0, 0, 0x30000, 0);
    if (nearby != 0) {
        Controller810A0Field(nearby, signed char*, 0x51) = Controller810A0PlanarHeadingLookup(
            Controller810A0Field(nearby, int*, 0xC) - ((Moby*)owner)->position.x,
            Controller810A0Field(nearby, int*, 0x10) - ((Moby*)owner)->position.y, 0);
    }
    if (Controller810A0TestPlayerSphereOverlap(idlePosition, 0x4B0, 7) != 0) {
        playerAngle =
            Controller810A0PlanarHeadingLookup(
                Controller810A0Field(&Controller810A0Player, int*, 0) - ((Moby*)owner)->position.x,
                Controller810A0Field(&Controller810A0Player, int*, 4) - ((Moby*)owner)->position.y,
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
    ((Moby*)owner)->position.x =
        (int)(((Moby*)owner)->position.x +
              ((int)(((int)(*(short*)(Controller810A0Cos +
                                      (Controller810A0Field(tag, unsigned char*, 1) * 2)) *
                            Controller810A0Field(tag, short*, 2)) >>
                      0xC) *
                     *(short*)(Controller810A0Cos +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2))) >>
               0xC));
    ((Moby*)owner)->position.y =
        (int)(((Moby*)owner)->position.y +
              ((int)(((int)(*(short*)(Controller810A0Sin +
                                      (Controller810A0Field(tag, unsigned char*, 1) * 2)) *
                            Controller810A0Field(tag, short*, 2)) >>
                      0xC) *
                     *(short*)(Controller810A0Cos +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2))) >>
               0xC));
    ((Moby*)owner)->position.z =
        (int)(((Moby*)owner)->position.z +
              ((int)(*(short*)(Controller810A0Sin +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2)) *
                     Controller810A0Field(tag, short*, 2)) >>
               0xC));
    if (Controller810A0QueryWorldSegment(&frame.previous, position) != 0) {
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
            Controller810A0ClearHistorySourceWord(handle);
        }
        goto removeOwner;
    }
    goto finished;
removeOwner:
    Controller810A0DeleteMoby(owner);
finished:;
}

#undef Controller810A0Field


extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_80071582;
void func_level_24_8007BE04(Moby* moby) {
    SpeechProps* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->mobyClass == 0x198) {
                if (!D_80071582)
                    tag->nextMsg = 0;
                else {
                    if (D_80070300[D_80066FCC[0x24]] & 1)
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

extern int deltaTime;
void func_80055B18(Moby*);
void func_level_24_8007BF54(Moby* moby) {
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
void func_level_24_8007C02C(void* input) {
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
            }
        }
    }
    return;
}
#undef Controller7C02CField


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
void func_level_24_8007C7F4(Moby* actor) {
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
int Controller7CAA0AddVector(void*, void*, void*) __asm__("func_8004F194");
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
void func_level_24_8007CAA0(void* input) {
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
            if ((Controller7CAA0D_8006E344 == 0xD) && (((Moby*)owner)->substate == 0)) {
                if (Controller7CAA0D_8006C4F8 != 1) {
                    ((Moby*)owner)->state = 3U;
                    stateAddress = owner + 0x48;
                    Controller7CAA0RegisterTrackedValue(stateAddress, 1, Controller7CAA0D_8006D088);
                    Controller7CAA0RegisterTrackedValue(stateAddress, 1, Controller7CAA0D_8006C7F8);
                } else {
                    {
                        register int sample __asm__("$3");
                        register int result __asm__("$2");
                        register int* vector __asm__("$4");
                        register int* sameVector __asm__("$5");
                        sample =
                            *(short*)(Controller7CAA0D_80065920 + ((Moby*)owner)->angle.yaw * 2);
                        MATCHING_KEEP_CLOBBER(sample, "$4");
                        vector = &Controller7CAA0D_800719BC;
                        MATCHING_KEEP(vector);
                        result = (sample * 13) >> 5;
                        *vector = result;
                        {
                            register int heading __asm__("$2") = ((Moby*)owner)->angle.yaw;
                            MATCHING_KEEP_CLOBBER(heading, "$5");
                            sameVector = vector;
                            MATCHING_KEEP(sameVector);
                            sample = *(short*)(Controller7CAA0D_800658A0 + heading * 2);
                        }
                        MATCHING_KEEP_CLOBBER(sample, "memory");
                        Controller7CAA0D_800719C4 = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(sample, "memory");
                        Controller7CAA0D_800719C0 = (sample * 13) >> 5;
                        Controller7CAA0AddVector(vector, sameVector, owner + 12);
                    }
                    Controller7CAA0D_8006C6E0 = ((((Moby*)owner)->angle.yaw + 0x80) * 0x10) & 0xFFF;
                    goto initializeTag;
                }
            } else {
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
                Controller7CAA0D_80071577 = 1;
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

#undef Controller7CAA0Field


extern Moby* D_8006C550;
void func_80055B18(Moby*);
void func_level_24_8007CF6C(Moby* moby) {
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
void func_level_24_8007D010(Moby* moby) {
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
void func_level_24_8007D41C(Moby* moby) {
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
void func_level_24_8007D488(Moby* mobyArgument) {
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
void func_level_24_8007D8C0(Moby* moby) {
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
void func_level_24_8007DBF0(Moby* actor) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_24/moby/func_level_24_8007DDFC.s SHA256 e6eb90ea2c0cc811968da5cd90718cc374d212e20e8b933ae610ee1866e844b2. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level24_7DDFCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level24_7DDFC_D_8006C550 __asm__("D_8006C550");
extern Spyro Level24_7DDFC_D_80070328 __asm__("D_80070328");
int Level24_7DDFCCountTimerDown(void*, int) __asm__("func_800359A4");
int Level24_7DDFCResolveMobyYawStep(Moby* ownerRecord, int arg1, int arg2, int arg3,
                                    int arg4) __asm__("func_80035DDC");
int Level24_7DDFCResolveMobyHeadingStep(Moby*, int, int, int, int, int) __asm__("func_80035EE0");
void Level24_7DDFCEmitMobyVertexParticles() __asm__("func_800369B8");
void Level24_7DDFCMarkMobyCollectionBit(Moby* moby) __asm__("func_8003BA00");
int Level24_7DDFCPlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
void Level24_7DDFCTransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Level24_7DDFCSoundHandleMatchesOwnerInStates1Or2(Moby*, int) __asm__("func_8003BFC0");
extern int Level24_7DDFCPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level24_7DDFCTransformVectorByBasis(SHORTMATRIX*, Vector3D*,
                                                Vector3D*) __asm__("func_8004ED6C");
extern void Level24_7DDFCAddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level24_7DDFCDeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level24_7DDFCRefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level24_7DDFC_rand() __asm__("rand");

int Level24_7DDFCQueryWorldSegmentWithOptions(Vector3D*, int*, unsigned int, unsigned int,
                                              int) __asm__("func_8001830C");
/* extern */
int Level24_7DDFCQueryWorldHeightWithOptions(Vector3D*, unsigned int, unsigned int,
                                             unsigned int) __asm__("func_8001A310");
/* extern */
int Level24_7DDFCQueryDynamicMobyGeometry(Vector3D*, unsigned int, unsigned int, unsigned int, int,
                                          Moby*) __asm__("func_8001BA30");
/* extern */
int Level24_7DDFCTestPlayerSphereOverlap(Vector3D*, unsigned int,
                                         unsigned int) __asm__("func_8001C288");
/* extern */
int Level24_7DDFCUpdateMobyPathMotion(Moby*, void*, unsigned int, unsigned int, int, int, int,
                                      int) __asm__("func_80035A80");
/* extern */
int Level24_7DDFCTestPaddedRotatedBox(Spyro*, void*, unsigned int,
                                      unsigned int) __asm__("func_80036220");
/* extern */
Moby* Level24_7DDFCSpawnMobyFromValueSelector(Moby*, int, Vector3D*,
                                              Vector3D*) __asm__("func_80036A68");
/* extern */
extern int Level24_7DDFC_D_8006C574 __asm__("D_8006C574");
extern int Level24_7DDFC_D_8006C578 __asm__("D_8006C578");
extern unsigned int Level24_7DDFC_D_8006C704 __asm__("D_8006C704");
extern int Level24_7DDFC_D_8006E1D4 __asm__("D_8006E1D4");
extern int Level24_7DDFC_D_8006E1D8 __asm__("D_8006E1D8");

void func_level_24_8007DDFC(Moby* ownerArgument) {
    /* SCUS-94467 original8007DDFC;
     original assembly SHA256 above.
     * Original0x70-byte frame: three scratch vectors atSP+0x20/+0x30/
     * +0x40;
      saved16..21 atSP+0x50..0x64 and RA atSP+0x68.
     * Record offsets are bytes and the pool stride is88 bytes.
     * The matched EXE36A68 helper takes owner, selector1 and two null
     * pointers here;
      original caller21..24 retain that four-argument ABI.
     * Empty constraints preserve initialized raw register producers and
     * emit no CPU instructions. Shared state writes are after the switch;
     * state2 producers follow their branch consumers, never live across
     * a helper call. Parameter4 is initialized AFTER rand at607.
     * Both height results retain saved16;
      pitch2 and height3 at224..226
     * follow prepared arguments4/5/6. Global constant20_2 follows a dead2
     * boundary after preceding stores. Sentinel3 follows boundary2 loads.
     * Case1 writes SP30 before the shared SP38 store at326. Vector fields
     * remain contiguous;
      separate int locals would lose required stores.
     * Physical units/fixed point, helper/SFX meanings and caller cadence
     * remain unresolved. Cadence per invocation;
      frame rate unknown.
     * Falsification: all791 original instructions, all16 owned selectors,
     * native/linked targets and complete EXE/every-overlay original hashes.
     * AI generated;
      not human reviewed. No synchronized runtime claim. */
    register Moby* ownerRecord __asm__("17") = ownerArgument;
    register Vector3D* spawnVector20 __asm__("20");
    struct {
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
    } scratch;
    register Moby* poolRecord16 __asm__("16");
    register Moby* animationRecord16 __asm__("16");
    register Moby* stateRecord16 __asm__("16");
    register Moby* otherAnimationRecord16 __asm__("16");
    register Moby* otherSpawnedRecord16 __asm__("16");
    register Moby* spawnedRecord16 __asm__("16");
    Vector3D* temp_a0;
    Vector3D* positionVector16;
    Vector3D* nextPositionVector16;
    Vector3D* followPositionVector16;
    Vector3D* positionVector18;
    int boundsResult16;
    int movementResult18;
    register Moby* preparedOwner4 __asm__("4");
    register int preparedSelector5 __asm__("5");
    register int globalConstant20_2 __asm__("2");
    int temp_v0;
    int temp_v0_12;
    int temp_v0_2;
    int heightResult16;
    int temp_v0_4;
    int otherHeightResult16;
    register int firstHeightResult16 __asm__("16");
    register int secondHeightResult16 __asm__("16");
    int temp_v0_9;
    int temp_v1_2;
    int temp_v1_4;
    register int spawnParameter4 __asm__("4");
    int var_v0_2;
    register unsigned int cachedYaw21 __asm__("21");
    unsigned char temp_v0_13;
    unsigned int temp_v1;
    register unsigned int temp_v1_3 __asm__("3");
    register int spawnIndex18 __asm__("18");
    register int sharedStateWord2 __asm__("2");
    register void* privateRecord19 __asm__("19");
    void* temp_v0_10;

    privateRecord19 = ownerRecord->mobyTag;
    temp_v0 = ownerRecord->damageFlags & 0xF7FFFFFF;
    ownerRecord->damageFlags = temp_v0;
    if (temp_v0 != 0) {
        if ((unsigned int)ownerRecord < (unsigned int)Level24_7DDFC_D_8006C704) {
            Level24_7DDFCSpawnMobyFromValueSelector(ownerRecord, 1, 0, 0);
        }
        Level24_7DDFCPlayMobySoundEvent(ownerRecord, 1, 0);
        ownerRecord->state = 3;
    }
    temp_v1 = ownerRecord->state;
    ownerRecord->damageFlags = 0;
    switch (temp_v1) { /* switch 1 */
        case 0:        /* switch 1 */
        case 11:       /* switch 1 */
            temp_v1_2 = Level24_7DDFCField(privateRecord19, int*, 0);
            if (temp_v1_2 >= 0) {
                poolRecord16 = &Level24_7DDFC_D_8006C550[temp_v1_2];
                if (((unsigned int)(poolRecord16->state - 0x50) < 2U) &&
                    (Level24_7DDFCTestPaddedRotatedBox(&Level24_7DDFC_D_80070328,
                                                       privateRecord19 + 0x18, 0, 0) != 0)) {
                    {
                        register void* tag2 __asm__("2");
                        tag2 = poolRecord16->mobyTag;
                        MATCHING_KEEP(tag2);
                        Level24_7DDFCField(tag2, int*, 0xC) = 0;
                    }
                    {
                        register unsigned int state3 __asm__("3");
                        register int compare2 __asm__("2");
                        state3 = ownerRecord->state;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(state3, "2");
                        compare2 = 0xB;
                        MATCHING_KEEP(compare2);
                        if (state3 == compare2) {
                            sharedStateWord2 = 0xC;
                        } else {
                            sharedStateWord2 = 1;
                        }
                        goto writeSharedState;
                    }
                }
            }
        default: /* switch 1 */
            return;
        case 1:  /* switch 1 */
        case 12: /* switch 1 */
        {
            register int index3 __asm__("3");
            register int stride2 __asm__("2");
            register Moby* base3 __asm__("3");
            index3 = Level24_7DDFCField(privateRecord19, int*, 0);
            stride2 = index3 * 88;
            base3 = Level24_7DDFC_D_8006C550;
            animationRecord16 = (Moby*)((int)base3 + stride2);
            MATCHING_KEEP(animationRecord16);
        }
            temp_v1_3 = animationRecord16->animationState.id;
            if ((temp_v1_3 == 0xC) &&
                ((unsigned char)animationRecord16->animationState.frame >= 3U)) {
                if (ownerRecord->state == temp_v1_3) {
                    ownerRecord->angle.yaw = Level24_7DDFCPlanarHeadingLookup(
                        Level24_7DDFC_D_80070328.position.x - ownerRecord->position.x,
                        Level24_7DDFC_D_80070328.position.y - ownerRecord->position.y, 0);
                }
                Level24_7DDFCPlayMobySoundEvent(ownerRecord, 2, 0);
                ownerRecord->state = 0xD;
                Level24_7DDFCField(privateRecord19, int*, 0xC) = 0;
                Level24_7DDFCField(privateRecord19, short*, 0x10) = 0;
                return;
            }
            break;
        case 13: /* switch 1 */
            Level24_7DDFCResolveMobyYawStep(ownerRecord, 0x89, 0, 0, 1);
            temp_v0_2 = ownerRecord->position.z - Level24_7DDFCField(privateRecord19, int*, 0xC);
            ownerRecord->position.z = temp_v0_2;
            ownerRecord->position.z = temp_v0_2 + Level24_7DDFCField(privateRecord19, short*, 0x10);
            Level24_7DDFCField(privateRecord19, int*, 0xC) =
                (int)(Level24_7DDFCField(privateRecord19, int*, 0xC) + 0xA);
            heightResult16 =
                Level24_7DDFCQueryWorldHeightWithOptions(&ownerRecord->position, 0x320, 3, 0);
            if (heightResult16 != 0) {
                Level24_7DDFCPlayMobySoundEvent(ownerRecord, 5, 0);
                preparedOwner4 = ownerRecord;
                preparedSelector5 = 0x3C;
                MATCHING_KEEP2(preparedOwner4, preparedSelector5);
                preparedOwner4->position.z = heightResult16 + 0x300;
                preparedOwner4->state = 2;
                Level24_7DDFCField(privateRecord19, short*, 0x10) = 0xFA;
                __asm__ volatile("" : : : "2", "memory");
                globalConstant20_2 = 0x14;
                MATCHING_KEEP(globalConstant20_2);
                Level24_7DDFCField(privateRecord19, int*, 0xC) = 0;
                goto block_20;
            }
            break;
        case 15: /* switch 1 */
            temp_v0_4 = ownerRecord->position.z - Level24_7DDFCField(privateRecord19, int*, 0xC);
            ownerRecord->position.z = temp_v0_4;
            ownerRecord->position.z = temp_v0_4 + Level24_7DDFCField(privateRecord19, short*, 0x10);
            Level24_7DDFCField(privateRecord19, int*, 0xC) =
                (int)(Level24_7DDFCField(privateRecord19, int*, 0xC) + 0xA);
            otherHeightResult16 =
                Level24_7DDFCQueryWorldHeightWithOptions(&ownerRecord->position, 0x320, 3, 0);
            if (otherHeightResult16 != 0) {
                Level24_7DDFCPlayMobySoundEvent(ownerRecord, 5, 0);
                preparedOwner4 = ownerRecord;
                preparedSelector5 = 0x3C;
                MATCHING_KEEP2(preparedOwner4, preparedSelector5);
                preparedOwner4->position.z = otherHeightResult16 + 0x300;
                preparedOwner4->state = 0;
                Level24_7DDFCField(privateRecord19, int*, 0) = -1;
                __asm__ volatile("" : : : "2", "memory");
                globalConstant20_2 = 0x14;
                MATCHING_KEEP(globalConstant20_2);
            block_20:
                Level24_7DDFC_D_8006E1D8 = globalConstant20_2;
                Level24_7DDFC_D_8006E1D4 = 0x1000;
                Level24_7DDFCEmitMobyVertexParticles(preparedOwner4, preparedSelector5);
                return;
            }
            break;
        case 2: /* switch 1 */
            if (Level24_7DDFCSoundHandleMatchesOwnerInStates1Or2(
                    ownerRecord, Level24_7DDFCField(privateRecord19, int*, 0x14)) == 0) {
                Level24_7DDFCField(privateRecord19, int*, 0x14) =
                    Level24_7DDFCPlayMobySoundEvent(ownerRecord, 3, 4);
            }
            Level24_7DDFCResolveMobyYawStep(ownerRecord, 0x89, 0, 0, 1);
            positionVector18 = &ownerRecord->position;
            firstHeightResult16 = ({
                register int return2 __asm__("2");
                return2 = Level24_7DDFCQueryWorldHeightWithOptions(positionVector18, 0x800, 3, 0);
                MATCHING_KEEP(return2);
                return2;
            });
            MATCHING_KEEP(firstHeightResult16);
            if (firstHeightResult16 != 0) {
                register Vector3D* argument4 __asm__("4");
                register int argument5 __asm__("5");
                register int argument6 __asm__("6");
                argument4 = positionVector18;
                argument5 = 0x400;
                argument6 = 1;
                MATCHING_KEEP3_VOLATILE_CLOBBER(argument4, argument5, argument6, "memory");
                {
                    register unsigned int pitch2 __asm__("2");
                    pitch2 = ownerRecord->angle.pitch;
                    MATCHING_KEEP(pitch2);
                    ownerRecord->position.z = firstHeightResult16 + 0x300;
                    MATCHING_OBSERVE_VOLATILE(firstHeightResult16);
                    pitch2 -= 4;
                    ownerRecord->angle.pitch = pitch2;
                }
                if (Level24_7DDFCTestPlayerSphereOverlap(argument4, argument5, argument6) != 0) {
                    Level24_7DDFC_D_80070328.unk22[5] = (int)ownerRecord->angle.yaw;
                    ownerRecord->state = 3;
                }
                scratch.sp20 = 0x400;
                scratch.sp24 = 0;
                scratch.sp28 = 0;
                Level24_7DDFCTransformVectorByBasis(&ownerRecord->rotationMatrix,
                                                    (Vector3D*)&scratch.sp20,
                                                    (Vector3D*)&scratch.sp20);
                Level24_7DDFCAddVector((Vector3D*)&scratch.sp20, positionVector18,
                                       (Vector3D*)&scratch.sp20);
                if (Level24_7DDFCQueryWorldSegmentWithOptions(positionVector18, &scratch.sp20, 3, 0,
                                                              0) != 0) {
                    sharedStateWord2 = 3;
                    goto writeSharedState;
                }
            } else {
                goto writeStateThree;
            }
            break;
        case 3: /* switch 1 */
            cachedYaw21 = ownerRecord->angle.yaw;
            Level24_7DDFCPlayMobySoundEvent(ownerRecord, 0, 0);
            {
                register unsigned int yaw2 __asm__("2");
                preparedOwner4 = ownerRecord;
                preparedSelector5 = 4;
                MATCHING_KEEP2(preparedOwner4, preparedSelector5);
                spawnIndex18 = 0;
                yaw2 = Level24_7DDFC_D_80070328.bodyRotation.yaw;
                MATCHING_KEEP(yaw2);
                spawnVector20 = (Vector3D*)&scratch.sp30;
                __asm__("" : "=r"(spawnVector20) : "0"(spawnVector20), "r"(yaw2));
                ownerRecord->angle.pitch = 0;
                ownerRecord->angle.roll = 0;
                ownerRecord->angle.yaw = yaw2;
                Level24_7DDFCRefreshMobySpatialGridAndBasis(preparedOwner4, preparedSelector5);
            }
        loop_29:
            if ((Level24_7DDFC_D_8006C578 - Level24_7DDFC_D_8006C574) >= 0x15) {
                spawnedRecord16 = SpawnMoby(8, ownerRecord);
                if (spawnedRecord16 != 0) {
                    spawnedRecord16->size = 0x2C;
                    spawnedRecord16->lowDrawDistance = 0x3F;
                    spawnedRecord16->updateDistance = 0xFF;
                    spawnedRecord16->animationState.id = spawnIndex18;
                    spawnedRecord16->angle.yaw = cachedYaw21;
                    switch (spawnIndex18) {
                        case 0:
                            scratch.sp30 = 0x1A6;
                            scratch.sp34 = 0x32;
                            scratch.sp38 = 0x180;
                            break;
                        case 1:
                            scratch.sp34 = -0x8C;
                            scratch.sp30 = 0;
                            scratch.sp38 = 0x400;
                            break;
                        case 2:
                            scratch.sp30 = 0xA;
                            scratch.sp34 = -0x148;
                            scratch.sp38 = 0x200;
                            break;
                    }
                    Level24_7DDFCTransformVectorByBasis(&ownerRecord->rotationMatrix, spawnVector20,
                                                        spawnVector20);
                    temp_a0 = &spawnedRecord16->position;
                    Level24_7DDFCAddVector(temp_a0, temp_a0, spawnVector20);
                    scratch.sp38 = 0;
                }
                spawnIndex18 += 1;
                if ((int)spawnIndex18 < 3) {
                    goto loop_29;
                }
            }
            Level24_7DDFCField(privateRecord19, void**, 4) = 0;
            Level24_7DDFCEmitMobyVertexParticles(ownerRecord, 0x64);
            if (Level24_7DDFCSoundHandleMatchesOwnerInStates1Or2(
                    ownerRecord, Level24_7DDFCField(privateRecord19, int*, 0x14)) != 0) {
                Level24_7DDFCTransitionSoundHandleTo3Or5(
                    Level24_7DDFCField(privateRecord19, int*, 0x14));
            }
            {
                register unsigned int boundary2 __asm__("2");
                register int sentinel3 __asm__("3");
                boundary2 = Level24_7DDFC_D_8006C704;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(boundary2, "3");
                sentinel3 = -1;
                __asm__("" : "=r"(sentinel3) : "0"(sentinel3), "r"(boundary2));
                Level24_7DDFCField(privateRecord19, int*, 0x14) = sentinel3;
                if ((unsigned int)ownerRecord >= boundary2)
                    goto block_71;
            }
            {
            block_46:
                Level24_7DDFCMarkMobyCollectionBit(ownerRecord);
            }
            goto block_71;
        case 14: /* switch 1 */
            if (Level24_7DDFCSoundHandleMatchesOwnerInStates1Or2(
                    ownerRecord, Level24_7DDFCField(privateRecord19, int*, 0x14)) == 0) {
                Level24_7DDFCField(privateRecord19, int*, 0x14) =
                    Level24_7DDFCPlayMobySoundEvent(ownerRecord, 3, 4);
            }
            Level24_7DDFCResolveMobyHeadingStep(ownerRecord, (ownerRecord->angle.yaw + 0x80) & 0xFF,
                                                0x12C, 0, 0, 0x400);
            scratch.sp40 = -0x400;
            scratch.sp44 = 0;
            scratch.sp48 = 0;
            Level24_7DDFCTransformVectorByBasis(&ownerRecord->rotationMatrix,
                                                (Vector3D*)&scratch.sp40, (Vector3D*)&scratch.sp40);
            positionVector16 = &ownerRecord->position;
            Level24_7DDFCAddVector((Vector3D*)&scratch.sp40, positionVector16,
                                   (Vector3D*)&scratch.sp40);
            secondHeightResult16 = ({
                register int return2 __asm__("2");
                return2 = Level24_7DDFCQueryWorldHeightWithOptions(positionVector16, 0x800, 3, 0);
                MATCHING_KEEP(return2);
                return2;
            });
            MATCHING_KEEP(secondHeightResult16);
            if (secondHeightResult16 == 0) {
                ownerRecord->position.z -= Level24_7DDFCField(privateRecord19, int*, 0xC);
                temp_v0_9 = Level24_7DDFCField(privateRecord19, int*, 0xC) + 0xA;
                Level24_7DDFCField(privateRecord19, int*, 0xC) = temp_v0_9;
                if (temp_v0_9 >= 0x2BD) {
                    if (Level24_7DDFCSoundHandleMatchesOwnerInStates1Or2(
                            ownerRecord, Level24_7DDFCField(privateRecord19, int*, 0x14)) != 0) {
                        Level24_7DDFCTransitionSoundHandleTo3Or5(
                            Level24_7DDFCField(privateRecord19, int*, 0x14));
                    }
                    {
                        register unsigned int boundary2 __asm__("2");
                        register int sentinel3 __asm__("3");
                        boundary2 = Level24_7DDFC_D_8006C704;
                        MATCHING_OBSERVE_VOLATILE_CLOBBER(boundary2, "3");
                        sentinel3 = -1;
                        __asm__("" : "=r"(sentinel3) : "0"(sentinel3), "r"(boundary2));
                        Level24_7DDFCField(privateRecord19, int*, 0x14) = sentinel3;
                        if (boundary2 < (unsigned int)ownerRecord)
                            goto block_71;
                    }
                    MATCHING_BARRIER_VOLATILE("memory");
                    goto block_46;
                }
                goto block_57;
            }
            if (Level24_7DDFCField(privateRecord19, int*, 0xC) == 0) {
                ownerRecord->position.z = secondHeightResult16 + 0x300;
                MATCHING_OBSERVE_VOLATILE(secondHeightResult16);
            block_57:
                nextPositionVector16 = &ownerRecord->position;
                if (Level24_7DDFCQueryWorldSegmentWithOptions(nextPositionVector16, &scratch.sp40,
                                                              3, 0, 0) == 0) {
                    ownerRecord->angle.pitch += 8;
                    if (Level24_7DDFCQueryDynamicMobyGeometry(nextPositionVector16, 0x400, 3, 0,
                                                              0x04000000, ownerRecord) == 0)
                        goto returnWithoutStateWrite;
                    sharedStateWord2 = 3;
                    MATCHING_BARRIER_VOLATILE("memory");
                    goto writeSharedState;
                } else {
                    sharedStateWord2 = 3;
                    goto writeSharedState;
                }
            } else {
                sharedStateWord2 = 3;
                goto writeSharedState;
            }
            break;
        case 4: /* switch 1 */
        {
            register void* header2 __asm__("2");
            register int one3 __asm__("3");
            header2 = Level24_7DDFCField(privateRecord19, void**, 4);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(header2, "3");
            one3 = 1;
            MATCHING_KEEP2(header2, one3);
            Level24_7DDFCField(header2, short*, 0xA) = one3;
            header2 = Level24_7DDFCField(privateRecord19, void**, 4);
            MATCHING_KEEP(header2);
            Level24_7DDFCField(header2, short*, 2) = one3;
        }
            __asm__ volatile("" : : : "2", "memory");
            sharedStateWord2 = 5;
            goto writeSharedState;
        case 5: /* switch 1 */
            if (Level24_7DDFCSoundHandleMatchesOwnerInStates1Or2(
                    ownerRecord, Level24_7DDFCField(privateRecord19, int*, 0x14)) == 0) {
                Level24_7DDFCField(privateRecord19, int*, 0x14) =
                    Level24_7DDFCPlayMobySoundEvent(ownerRecord, 3, 4);
            }
            followPositionVector16 = &ownerRecord->position;
            movementResult18 = Level24_7DDFCUpdateMobyPathMotion(
                ownerRecord, Level24_7DDFCField(privateRecord19, void**, 4), 0x78, 0x89, 0, 6, 0x60,
                0);
            ownerRecord->position.z =
                Level24_7DDFCQueryWorldHeightWithOptions(followPositionVector16, 0x800, 3, 0) +
                0x300;
            ownerRecord->angle.pitch -= 6;
            if (Level24_7DDFCTestPlayerSphereOverlap(followPositionVector16, 0x400, 1) != 0) {
                Level24_7DDFC_D_80070328.unk22[5] = Level24_7DDFCPlanarHeadingLookup(
                    Level24_7DDFC_D_80070328.position.x - ownerRecord->position.x,
                    Level24_7DDFC_D_80070328.position.y - ownerRecord->position.y, 0);
                ownerRecord->state = 3;
            }
            if (movementResult18 & 1) {
                temp_v0_10 = Level24_7DDFCField(privateRecord19, void**, 4);
                if (Level24_7DDFCField(temp_v0_10, short*, 2) ==
                    (Level24_7DDFCField(temp_v0_10, short*, 0) - 1)) {
                    ownerRecord->state = 2;
                    return;
                }
            }
            break;
        case 7: /* switch 1 */
            ownerRecord->updateDistance = 0xFF;
            ownerRecord->unknown3[0] = 0;
            ownerRecord->lowDrawDistance = 0;
            ownerRecord->drawn = 0;
            ownerRecord->unknownCollision = 0;
            ownerRecord->state = 6;
            Level24_7DDFCField(Level24_7DDFCField(privateRecord19, void**, 4), short*, 0xA) = 1;
            Level24_7DDFCField(Level24_7DDFCField(privateRecord19, void**, 4), short*, 2) = 1;
            return;
        case 6: /* switch 1 */
            ownerRecord->unknown3[0] = 0;
            ownerRecord->lowDrawDistance = 0;
            ownerRecord->drawn = 0;
            if ((Level24_7DDFC_D_8006C550[Level24_7DDFCField(privateRecord19, int*, 0x38)].state &
                 0x80) ||
                (Level24_7DDFC_D_8006C550[Level24_7DDFCField(privateRecord19, int*, 0x3C)].state &
                 0x80)) {
            block_71:
                Level24_7DDFCDeleteMoby(ownerRecord);
                return;
            }
            temp_v1_4 = Level24_7DDFCField(privateRecord19, int*, 0x30);
            if ((temp_v1_4 < 0) || (Level24_7DDFC_D_8006C550[temp_v1_4].state & 0x80)) {
                boundsResult16 = Level24_7DDFCTestPaddedRotatedBox(&Level24_7DDFC_D_80070328,
                                                                   privateRecord19 + 0x18, 0, 0);
                if (Level24_7DDFCCountTimerDown(privateRecord19 + 8, 4) != 0) {
                    if (boundsResult16 != 0) {
                        if ((Level24_7DDFC_rand() & 0xF) < 8) {
                            spawnParameter4 = 0x173;
                        } else {
                            spawnParameter4 = 7;
                        }
                        {
                            register Moby* return2 __asm__("2");
                            return2 = SpawnMoby(spawnParameter4, ownerRecord);
                            MATCHING_KEEP(return2);
                            otherSpawnedRecord16 = return2;
                            MATCHING_KEEP(otherSpawnedRecord16);
                        }
                        if (otherSpawnedRecord16 != 0) {
                            otherSpawnedRecord16->updateDistance = 0xFF;
                            otherSpawnedRecord16->lowDrawDistance = 0x40;
                            otherSpawnedRecord16->state = 5;
                            otherSpawnedRecord16->angle.yaw = ownerRecord->angle.yaw;
                            Level24_7DDFCField(otherSpawnedRecord16->mobyTag, void**, 4) =
                                (void*)Level24_7DDFCField(privateRecord19, void**, 4);
                            Level24_7DDFCField(Level24_7DDFCField(privateRecord19, void**, 4),
                                               short*, 0xA) = 1;
                            Level24_7DDFCField(Level24_7DDFCField(privateRecord19, void**, 4),
                                               short*, 2) = 1;
                            Level24_7DDFCField(privateRecord19, int*, 8) = 0x168;
                            return;
                        }
                    } else {
                        goto block_81;
                    }
                } else if (boundsResult16 == 0) {
                block_81:
                    if (Level24_7DDFCField(privateRecord19, int*, 8) < 0x78) {
                        Level24_7DDFCField(privateRecord19, int*, 8) = 0x78;
                        return;
                    }
                }
            }
            break;
        case 8: /* switch 1 */
        {
            register int index3 __asm__("3");
            register int stride2 __asm__("2");
            register Moby* base3 __asm__("3");
            index3 = Level24_7DDFCField(privateRecord19, int*, 0);
            stride2 = index3 * 88;
            base3 = Level24_7DDFC_D_8006C550;
            stateRecord16 = (Moby*)((int)base3 + stride2);
            MATCHING_KEEP(stateRecord16);
        }
            if ((stateRecord16->state == 0x50) &&
                (Level24_7DDFCTestPaddedRotatedBox(&Level24_7DDFC_D_80070328,
                                                   privateRecord19 + 0x18, 0, 0) != 0)) {
                Level24_7DDFCField(stateRecord16->mobyTag, int*, 0xC) = 0;
                Level24_7DDFCPlayMobySoundEvent(ownerRecord, 2, 0);
                sharedStateWord2 = 9;
                goto writeSharedState;
            }
            break;
        case 9: /* switch 1 */
        {
            register int index3 __asm__("3");
            register int stride2 __asm__("2");
            register Moby* base3 __asm__("3");
            index3 = Level24_7DDFCField(privateRecord19, int*, 0);
            stride2 = index3 * 88;
            base3 = Level24_7DDFC_D_8006C550;
            otherAnimationRecord16 = (Moby*)((int)base3 + stride2);
            MATCHING_KEEP(otherAnimationRecord16);
        }
            if ((otherAnimationRecord16->animationState.id == 0xC) &&
                ((unsigned char)otherAnimationRecord16->animationState.frame >= 3U)) {
                ownerRecord->state = 0xA;
                Level24_7DDFCField(privateRecord19, int*, 0xC) = 0;
                Level24_7DDFCField(privateRecord19, short*, 0x10) = 0;
                ownerRecord->substate = 0;
                return;
            }
            break;
        case 10: /* switch 1 */
            Level24_7DDFCResolveMobyYawStep(ownerRecord, 0x89, 0, 0, 1);
            ownerRecord->angle.pitch -= 4;
            temp_v0_12 = ownerRecord->position.z - Level24_7DDFCField(privateRecord19, int*, 0xC);
            ownerRecord->position.z = temp_v0_12;
            ownerRecord->position.z =
                temp_v0_12 + Level24_7DDFCField(privateRecord19, short*, 0x10);
            Level24_7DDFCField(privateRecord19, int*, 0xC) =
                (int)(Level24_7DDFCField(privateRecord19, int*, 0xC) + 0xA);
            if ((Level24_7DDFCQueryWorldHeightWithOptions(&ownerRecord->position, 0x320, 3, 0) ==
                 0) ||
                (Level24_7DDFCPlayMobySoundEvent(ownerRecord, 5, 0),
                 Level24_7DDFCField(privateRecord19, short*, 0x10) = 0xFA,
                 Level24_7DDFCField(privateRecord19, int*, 0xC) = 0,
                 Level24_7DDFC_D_8006E1D8 = 0x14, Level24_7DDFC_D_8006E1D4 = 0x1000,
                 Level24_7DDFCEmitMobyVertexParticles(ownerRecord, 0x3C),
                 temp_v0_13 = ownerRecord->substate + 1, ownerRecord->substate = temp_v0_13,
                 (((unsigned int)(temp_v0_13 & 0xFF) < 4U) != 0))) {
                MATCHING_KEEP_VOLATILE(ownerRecord);
                if (Level24_7DDFCTestPlayerSphereOverlap(&ownerRecord->position, 0x400, 1) != 0) {
                    Level24_7DDFC_D_80070328.unk22[5] = Level24_7DDFCPlanarHeadingLookup(
                        Level24_7DDFC_D_80070328.position.x - ownerRecord->position.x,
                        Level24_7DDFC_D_80070328.position.y - ownerRecord->position.y, 0);
                    Level24_7DDFC_D_8006E1D8 = 0x14;
                    Level24_7DDFC_D_8006E1D4 = 0x1000;
                    Level24_7DDFCEmitMobyVertexParticles(ownerRecord, 0x3C);
                    goto writeStateThree;
                }
            } else {
                sharedStateWord2 = 3;
                goto writeSharedState;
            }
            break;
    }
returnWithoutStateWrite:
    return;
writeStateThree:
    sharedStateWord2 = 3;
writeSharedState:
    MATCHING_KEEP(sharedStateWord2);
    ownerRecord->state = sharedStateWord2;
}
#undef Level24_7DDFCField

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
void func_level_24_8007EA58(void* input) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original8007EF38. AI generated; not human reviewed.
 * Required:3689 original native words,194 absolute selectors,two zero pads,
 * actual transfers/data addends,and unchanged parent EXE/every-overlay hashes.
 * Original F0 frame saves S0..S6/RA at D0..EC. Produced vector/scalar homes
 * occupy20..CC; outgoing argument homes are generated by the unchanged compiler.
 * OwnerS3 is the parameter; privateS2 is owner+0. Saved GP roles have distinct
 * initialized phases. No fixed FP/SP,manual outgoing homes or live aliases.
 * One complete signed64 product implements original magic remainder40. Its
 * ordinary union high view follows compiler endian order, not retail memory.
 * Primary original CFG/helper proofs cover every consumed local and full GP.
 * Nonnull365E4 fifth outputs are original SP40/SP44/SPB8, written by EXE36674;
 * two other fifth arguments are actualNULL. No local initializer is fabricated.
 * Empty metadata emits zero CPU instructions and observes only initialized full
 * values,real addresses or actual produced cells. GP clobbers retire a dead
 * original role before its new producer. Mode0/1 contexts follow the original
 * captured private24 decision; no global writer bound is inferred. Distinct
 * descriptor entries use initialized old A5, next A0 and V1, and resolve to the
 * SAME original native3548. Ready-owner entries preserve exact branch targets.
 * Helper types describe the proven four-byte call ABI and primary local outputs;
 * full external semantics,allocation/writer closure,coordinate domains/cadence,
 * Rev1 correspondence,retail runtime captures and human review remain open.
 * Original-compiler identity proves this slice,not complete game behavior or
 * portable signed-overflow/alias semantics. Pipeline/filter/flags unchanged.
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
} Level24_7EF38CompleteProduct;
/* SCUS-94467 USA Rev0 original3689native+ownedselectors. AI generated; not human reviewed. Uninstalled original-backed probe. */
#define Level24_7EF38Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level24_7EF38CompleteValue(v) __asm__("" : "=r"(v) : "0"(v))
void Level24_7EF38PrepareCameraMode9Vectors(void*, void*) __asm__("func_80013AE4");
void Level24_7EF38TransitionCameraModes9And10(int) __asm__("func_80013B7C");
int Level24_7EF38TestSubdividedSegmentPath(void*, void*, int) __asm__("func_80013E38");
void Level24_7EF38MaskLinkedRecordFlagsById(int, int, int) __asm__("func_80021ED8");
int Level24_7EF38QueryShiftedLinkedRecordWordByByteId(int) __asm__("func_80021F3C");
void Level24_7EF38WriteMatchingLinkedSelectors(int, int, int) __asm__("func_80021F8C");
void Level24_7EF38RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Level24_7EF38TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Level24_7EF38CountTimerDown(void*, int) __asm__("func_800359A4");
int Level24_7EF38UpdateMobyPathMotion(void*, void*, int, int, int, int, int,
                                      int) __asm__("func_80035A80");
int Level24_7EF38ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
int Level24_7EF38ResolveMobyYawStep(void*, int, int, int, int) __asm__("func_80035DDC");
void Level24_7EF38ResolveMobyHeadingStep(void*, int, int, int, int, int) __asm__("func_80035EE0");
int Level24_7EF38RandBetween(int, int) __asm__("func_8003636C");
int Level24_7EF38ComputeArcVerticalVelocity(void*, void*, int, int, void*) __asm__("func_800365E4");
int Level24_7EF38UpdateMobyInteractionGate(void*, int) __asm__("func_80037BBC");
void Level24_7EF38RegisterTrackedValue(void*, int, void*) __asm__("func_8003B7B4");
int Level24_7EF38PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
void Level24_7EF38PlaySoundFromGlobalByteTable(void*, int, int) __asm__("func_8003BB10");
void Level24_7EF38TransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Level24_7EF38SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
void Level24_7EF38SetClampedPlayerTargetAngles(void*) __asm__("func_800492DC");
int Level24_7EF38PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Level24_7EF38ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
void Level24_7EF38CopyVector(void*, void*) __asm__("func_8004F178");
void Level24_7EF38AddVector(void*, void*, void*) __asm__("func_8004F194");
void Level24_7EF38SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Level24_7EF38AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level24_7EF38ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
void Level24_7EF38StartDialogue(void*, int, int) __asm__("func_800512E4");
void Level24_7EF38DeleteMoby(void*) __asm__("func_80055B18");
void Level24_7EF38RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Level24_7EF38ReadSelectedFrameScalar(void*) __asm__("func_80055E84");
void Level24_7EF38InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
int Level24_7EF38_rand(void) __asm__("rand");
extern int Level24_7EF38_D_800658A0 __asm__("D_800658A0");
extern int Level24_7EF38_D_80065920 __asm__("D_80065920");
extern int Level24_7EF38_D_8006C550 __asm__("D_8006C550");
extern int Level24_7EF38_D_8006C58C __asm__("D_8006C58C");
extern int Level24_7EF38_D_8006C640 __asm__("D_8006C640");
extern int Level24_7EF38_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level24_7EF38_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level24_7EF38_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level24_7EF38_D_8006E044 __asm__("D_8006E044");
extern int Level24_7EF38_D_8006E048 __asm__("D_8006E048");
extern int Level24_7EF38_D_8006E344 __asm__("D_8006E344");
extern int Level24_7EF38_D_8006E53C __asm__("D_8006E53C");
extern int Level24_7EF38_D_80070300 __asm__("D_80070300");
extern int Level24_7EF38_D_80070328 __asm__("D_80070328");
extern int Level24_7EF38_D_80071AB0 __asm__("D_80071AB0");
extern int Level24_7EF38_D_level_24_80096B68 __asm__("D_level_24_80096B68");
extern int (*Level24_7EF38_SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
extern int Level24_7EF38_func_level_24_8007572C __asm__("func_level_24_8007572C");
extern int Level24_7EF38_main_TEXT_END __asm__("main_TEXT_END");
extern int Level24_7EF38_main_TEXT_START __asm__("main_TEXT_START");
void func_level_24_8007EF38(void* ownerParameter) {
    register int classLiteral8 __asm__("$8");
    Level24_7EF38CompleteProduct remainderBy40Product;
    register int productHigh9 __asm__("$9");
    register int savedHeadingFrameOrActor16 __asm__("$16"), savedIndexFrameOrActor17 __asm__("$17"),
        private18 __asm__("$18"), owner19 __asm__("$19"), savedIndexOrVector20 __asm__("$20"),
        savedPrivate21 __asm__("$21"), enabled22 __asm__("$22"), unusedSaved23 __asm__("$23");
    register int resultOrArithmetic2 __asm__("$2"), fieldOrAddress3 __asm__("$3"),
        argumentOrAddress4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrIndex6 __asm__("$6"), argumentOrField7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC;
    } originalFrame;
    int captured_a0_26;
    int captured_a2_2;
    int captured_a2_4;
    int captured_v0_14;
    int captured_v0_19;
    int captured_v0_28;
    int captured_v1_30;
    int captured_v1_47;
    int captured_v1_49;
    int captured_a0_21;
    int captured_a0_22;
    int captured_v0_12;
    int captured_v0_26;
    int captured_v1;
    int captured_v1_2;
    int captured_v1_37;
    int captured_v1_44;
    int captured_a0_11;
    int captured_a0_12;
    int captured_a0_14;
    int captured_a0_18;
    int captured_a0_20;
    int captured_a0_23;
    int captured_a0_2;
    int captured_a0_30;
    int captured_a0_31;
    int captured_a0_3;
    int captured_a0_9;
    int captured_a3;
    int captured_a3_2;
    int captured_a3_3;
    int captured_a3_5;
    int captured_a3_7;
    int captured_a3_8;
    int captured_hi;
    int captured_v0_16;
    int captured_v0_30;
    int captured_v1_13;
    int captured_v1_21;
    int captured_v1_22;
    int captured_v1_23;
    int captured_v1_25;
    int captured_v1_32;
    int captured_v1_33;
    int captured_v1_40;
    int captured_v1_50;
    int captured_v1_51;
    int captured_v1_55;
    int captured_v0_25;
    int captured_v1_15;
    int captured_v1_18;
    int captured_v0_17;
    int captured_v1_12;
    int captured_v1_14;
    int captured_v1_17;
    int captured_v1_26;
    int captured_v1_42;
    int captured_v1_46;
    int captured_v1_5;
    int captured_a0_10;
    int captured_a0_13;
    int captured_a0_16;
    int captured_a0_19;
    int captured_a0_24;
    int captured_a0_25;
    int captured_a0_27;
    int captured_a0_28;
    int captured_a0_29;
    int captured_a1_3;
    int captured_a1_4;
    int captured_a2_5;
    int captured_v0;
    int captured_v0_11;
    int captured_v0_15;
    int captured_v0_20;
    int captured_v0_29;
    int captured_v0_33;
    int captured_v0_5;
    int captured_v0_7;
    int captured_v0_9;
    int captured_v1_10;
    int captured_v1_11;
    int captured_v1_29;
    int captured_v1_31;
    int captured_v1_38;
    int captured_v1_41;
    int captured_v1_48;
    int captured_v1_53;
    int captured_v1_56;
    int captured_v1_57;
    int captured_v1_58;
    int captured_v1_6;
    int captured_v1_7;
    int captured_v1_8;
    int captured_v1_9;
    owner19 = (int)ownerParameter;
    Level24_7EF38CompleteValue(owner19);
    private18 = Level24_7EF38Field(owner19, int*, 0);
    enabled22 = 1;
    if (Level24_7EF38Field(private18, unsigned char*, 0x24) != 3) {
        goto block_2;
    }
    Level24_7EF38DeleteMoby((void*)(ownerParameter));
    __asm__ volatile("" ::"r"(owner19), "i"(3));
    return;
block_2:
    if (Level24_7EF38Field(owner19, int*, 0x18) == 0) {
        goto block_11;
    }
    argumentOrAddress4 = Level24_7EF38Field(owner19, unsigned char*, 0x49);
    resultOrArithmetic2 = 9;
    if (argumentOrAddress4)
        goto block_11;
    Level24_7EF38CompleteValue(argumentOrAddress4);
    fieldOrAddress3 = Level24_7EF38_D_8006E044;
    if (fieldOrAddress3 == resultOrArithmetic2)
        goto block_11;
    resultOrArithmetic2 = argumentOrAddress4 | 1;
    Level24_7EF38Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
    resultOrArithmetic2 = Level24_7EF38Field(owner19, int*, 0x18);
    Level24_7EF38CompleteValue(resultOrArithmetic2);
    fieldOrAddress3 = 0x10000;
    resultOrArithmetic2 &= fieldOrAddress3;
    if (!resultOrArithmetic2) {
        resultOrArithmetic2 = argumentOrAddress4 | 9;
        goto block_7;
    }
    resultOrArithmetic2 = argumentOrAddress4 | 9;
    Level24_7EF38Field(owner19, unsigned char*, 0x49) = resultOrArithmetic2;
block_7:
    captured_v1 = Level24_7EF38Field(private18, int*, 0x5C);
    Level24_7EF38Field(private18, unsigned short*, 0x60) =
        (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
    Level24_7EF38Field(private18, short*, 0x62) =
        (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
    if (captured_v1 == 0) {
        goto block_10;
    }
    captured_a0_2 = Level24_7EF38Field(captured_v1, int*, 0);
    if (captured_a0_2 >= (Level24_7EF38Field(private18, unsigned char*, 0x25) * 4)) {
        goto block_10;
    }
    Level24_7EF38Field(captured_v1, int*, 0) = captured_a0_2 - 1;
block_10:
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x5FU;
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0xA));
block_11:
    Level24_7EF38Field(owner19, int*, 0x18) = 0;
    if (!(Level24_7EF38Field(owner19, unsigned char*, 0x49) & 8)) {
        goto block_14;
    }
    originalFrame.sp20 = (Level24_7EF38_rand() & 0xF) - 8;
    originalFrame.sp24 = (Level24_7EF38_rand() & 0xF) - 8;
    originalFrame.sp28 = (Level24_7EF38_rand() & 0xF) + 8;
    captured_v0 = Level24_7EF38_SpawnParticle((int)(1), (int)(0x37), (void*)(owner19 + 0xC),
                                              (int)(&originalFrame.sp20));
    if (captured_v0 == 0) {
        goto block_14;
    }
    Level24_7EF38Field(captured_v0, unsigned short*, 8) =
        (unsigned short)(Level24_7EF38Field(captured_v0, unsigned short*, 8) +
                         (Level24_7EF38_rand() & 0xFF));
block_14:
    if (!(Level24_7EF38Field(owner19, unsigned char*, 0x49) & 1)) {
        goto block_19;
    }
    if (Level24_7EF38_D_8006C770 == 0) {
        goto block_19;
    }
    Level24_7EF38RequestMobyAnimation((void*)(owner19),
                                      (int)(Level24_7EF38Field(private18, short*, 0x62)));
    Level24_7EF38Field(owner19, unsigned char*, 0x48) =
        (unsigned char)Level24_7EF38Field(private18, unsigned short*, 0x60);
    Level24_7EF38Field(owner19, unsigned char*, 0x49) =
        (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) & 0xF6);
    captured_v1_2 = Level24_7EF38Field(private18, int*, 0x5C);
    if (captured_v1_2 == 0) {
        goto block_19;
    }
    captured_a0_3 = Level24_7EF38Field(captured_v1_2, int*, 0);
    if (captured_a0_3 >= (Level24_7EF38Field(private18, unsigned char*, 0x25) * 4)) {
        goto block_19;
    }
    Level24_7EF38Field(captured_v1_2, int*, 0) = captured_a0_3 + 1;
block_19:
    if (Level24_7EF38Field(private18, unsigned char*, 0x24) == 2) {
        goto block_28;
    }
    if ((unsigned char)Level24_7EF38Field(owner19, unsigned char*, 0x48) >= 0x3CU) {
        goto block_28;
    }
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x38);
    if (fieldOrAddress3 < 0)
        goto block_24;
    resultOrArithmetic2 = fieldOrAddress3 * 11;
    fieldOrAddress3 = Level24_7EF38_D_8006C550;
    resultOrArithmetic2 *= 8;
    resultOrArithmetic2 += fieldOrAddress3;
    argumentOrAddress4 = Level24_7EF38Field(resultOrArithmetic2, unsigned char*, 0x48);
    resultOrArithmetic2 = 0x63;
    Level24_7EF38CompleteValue(resultOrArithmetic2);
    Level24_7EF38CompleteValue(argumentOrAddress4);
    fieldOrAddress3 = argumentOrAddress4 & 0xFF;
    if (fieldOrAddress3 == resultOrArithmetic2)
        goto block_24;
    resultOrArithmetic2 = argumentOrAddress4 & 0x80;
    if (!resultOrArithmetic2)
        goto block_28;
block_24:
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x3C);
    if (fieldOrAddress3 < 0)
        goto block_27;
    resultOrArithmetic2 = fieldOrAddress3 * 11;
    fieldOrAddress3 = Level24_7EF38_D_8006C550;
    resultOrArithmetic2 *= 8;
    resultOrArithmetic2 += fieldOrAddress3;
    argumentOrAddress4 = Level24_7EF38Field(resultOrArithmetic2, unsigned char*, 0x48);
    resultOrArithmetic2 = 0x63;
    Level24_7EF38CompleteValue(resultOrArithmetic2);
    Level24_7EF38CompleteValue(argumentOrAddress4);
    fieldOrAddress3 = argumentOrAddress4 & 0xFF;
    if (fieldOrAddress3 == resultOrArithmetic2)
        goto block_27;
    resultOrArithmetic2 = argumentOrAddress4 & 0x80;
    argumentOrAddress4 = private18 + 0x84;
    if (!resultOrArithmetic2)
        goto block_29;
block_27:
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x3CU;
block_28:
    argumentOrAddress4 = private18 + 0x84;
block_29:
    resultOrArithmetic2 = Level24_7EF38CountTimerDown((void*)(argumentOrAddress4), (int)(2));
    argumentOrAddress4 = owner19 + 0xC;
    if (resultOrArithmetic2 == 0)
        goto block_33;
    if (Level24_7EF38ApproximatePlanarDistance((void*)(argumentOrAddress4),
                                               (void*)((int)&Level24_7EF38_D_80070328)) >= 0x400) {
        goto block_36;
    }
    if (Level24_7EF38AbsoluteByteAngleDelta(
            (int)(Level24_7EF38Field(owner19, unsigned char*, 0x46)),
            (int)(Level24_7EF38PlanarHeadingLookup(
                (int)(Level24_7EF38Field((int)&Level24_7EF38_D_80070328, int*, 0) -
                      Level24_7EF38Field(owner19, int*, 0xC)),
                (int)(Level24_7EF38Field((int)&Level24_7EF38_D_80070328, int*, 4) -
                      Level24_7EF38Field(owner19, int*, 0x10)),
                (int)(0)))) >= 0x20) {
        goto block_36;
    }
    enabled22 = 0;
    goto block_35;
block_33:
    Level24_7EF38CompleteValue(resultOrArithmetic2);
    enabled22 = 0;
    if (Level24_7EF38ApproximatePlanarDistance((void*)(argumentOrAddress4),
                                               (void*)((int)&Level24_7EF38_D_80070328)) >= 0x800) {
        goto block_36;
    }
    if (Level24_7EF38AbsoluteByteAngleDelta(
            (int)(Level24_7EF38Field(owner19, unsigned char*, 0x46)),
            (int)(Level24_7EF38PlanarHeadingLookup(
                (int)(Level24_7EF38Field((int)&Level24_7EF38_D_80070328, int*, 0) -
                      Level24_7EF38Field(owner19, int*, 0xC)),
                (int)(Level24_7EF38Field((int)&Level24_7EF38_D_80070328, int*, 4) -
                      Level24_7EF38Field(owner19, int*, 0x10)),
                (int)(0)))) >= 0x28) {
        goto block_36;
    }
block_35:
    Level24_7EF38Field(private18, short*, 0x84) = 0x3C;
block_36:
    Level24_7EF38CompleteValue(enabled22);
    if (Level24_7EF38Field(private18, int*, 0x70) < 0) {
        goto block_46;
    }
    if (!(Level24_7EF38_D_8006E53C & 0x800)) {
        goto block_46;
    }
    if (Level24_7EF38_D_8006E044 != 9) {
        goto block_46;
    }
    captured_v1_5 = Level24_7EF38Field(owner19, unsigned char*, 0x48);
    if ((unsigned int)(captured_v1_5 - 0x4A) < 2U) {
        goto block_41;
    }
    if ((unsigned int)(captured_v1_5 - 0x4F) >= 2U) {
        goto block_46;
    }
block_41:
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x74);
    argumentOrAddress4 = Level24_7EF38_D_8006C550;
    resultOrArithmetic2 = fieldOrAddress3 * 11;
    resultOrArithmetic2 *= 8;
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x78);
    argumentOrField5 = argumentOrAddress4 + resultOrArithmetic2;
    fieldOrAddress3 = -fieldOrAddress3;
    Level24_7EF38CompleteValue(fieldOrAddress3);
    resultOrArithmetic2 = fieldOrAddress3 * 11;
    resultOrArithmetic2 *= 8;
    fieldOrAddress3 = Level24_7EF38Field(argumentOrField5, int*, 0);
    argumentOrAddress4 += resultOrArithmetic2;
    resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, int*, 0x74);
    fieldOrAddress3 = Level24_7EF38Field(argumentOrAddress4, int*, 0);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x4D;
        goto block_43;
    }
    resultOrArithmetic2 = 0x42;
block_43:
    Level24_7EF38Field(argumentOrField5, signed char*, 0x48) = resultOrArithmetic2;
    resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, int*, 0x74);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x4D;
        goto block_45;
    }
    resultOrArithmetic2 = 0x42;
block_45:
    Level24_7EF38Field(argumentOrAddress4, signed char*, 0x48) = resultOrArithmetic2;
    Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0) =
        Level24_7EF38Field(private18, unsigned char*, 0x25) * 8;
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x4DU;
    Level24_7EF38TransitionCameraModes9And10((int)(1));
block_46:
    argumentOrField5 = Level24_7EF38Field(private18, int*, 0x78);
    classLiteral8 = 0x4E;
    if (argumentOrField5 < 0)
        goto block_71;
    Level24_7EF38CompleteValue(classLiteral8);
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x74);
    resultOrArithmetic2 = fieldOrAddress3 * 11;
    fieldOrAddress3 = Level24_7EF38_D_8006C550;
    resultOrArithmetic2 *= 8;
    argumentOrIndex6 = resultOrArithmetic2 + fieldOrAddress3;
    Level24_7EF38CompleteValue(argumentOrIndex6);
    resultOrArithmetic2 = Level24_7EF38Field(argumentOrIndex6, unsigned char*, 0x48);
    if (resultOrArithmetic2 == classLiteral8) {
        argumentOrField7 = 0x5F;
        goto block_71;
    }
    argumentOrField7 = 0x5F;
    if (resultOrArithmetic2 == argumentOrField7)
        goto block_71;
    resultOrArithmetic2 = argumentOrField5 * 11;
    resultOrArithmetic2 *= 8;
    argumentOrAddress4 = resultOrArithmetic2 + fieldOrAddress3;
    Level24_7EF38CompleteValue(argumentOrAddress4);
    resultOrArithmetic2 = Level24_7EF38Field(argumentOrAddress4, unsigned char*, 0x48);
    if (resultOrArithmetic2 == classLiteral8)
        goto block_71;
    if (resultOrArithmetic2 == argumentOrField7)
        goto block_71;
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x5C);
    fieldOrAddress3 = Level24_7EF38Field(private18, unsigned char*, 0x25);
    resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, 0);
    savedHeadingFrameOrActor16 = argumentOrIndex6;
    if (resultOrArithmetic2 != fieldOrAddress3)
        goto block_71;
    savedIndexOrVector20 = argumentOrAddress4;
    savedIndexFrameOrActor17 = Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0);
    savedPrivate21 = Level24_7EF38Field(savedIndexOrVector20, int*, 0);
    Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0x18) = 0;
    Level24_7EF38Field(savedIndexOrVector20, int*, 0x18) = 0;
    if (Level24_7EF38_D_8006E044 == 9) {
        goto block_54;
    }
    captured_a0_9 = Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x80), int*, 0xC);
    Level24_7EF38PrepareCameraMode9Vectors((void*)(captured_a0_9), (void*)(captured_a0_9 + 0x10));
    goto block_71;
block_54:
    if (Level24_7EF38_D_8006E048 != 1) {
        goto block_71;
    }
    resultOrArithmetic2 = Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x74);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x4A;
        goto block_57;
    }
    argumentOrAddress4 = savedHeadingFrameOrActor16 + 0x48;
    argumentOrField5 = 1;
    Level24_7EF38CompleteValue(argumentOrField5);
    argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
    Level24_7EF38CompleteValue(argumentOrIndex6);
    resultOrArithmetic2 = 0x42;
    Level24_7EF38Field(savedHeadingFrameOrActor16, unsigned char*, 0x48) = resultOrArithmetic2;
    Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                      (void*)(argumentOrIndex6));
    resultOrArithmetic2 = 0x40;
block_57:
    Level24_7EF38Field(savedHeadingFrameOrActor16, unsigned char*, 0x48) = resultOrArithmetic2;
    resultOrArithmetic2 = Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x54);
    if (resultOrArithmetic2 != 0) {
        goto block_59;
    }
    resultOrArithmetic2 = Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x50);
    if (resultOrArithmetic2 == 0) {
        goto block_60;
    }
block_59:
    Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x4C) = resultOrArithmetic2;
block_60:
    resultOrArithmetic2 = Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x4C);
    argumentOrAddress4 = savedHeadingFrameOrActor16 + 0xC;
    argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, short*, 0);
    resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, 0xC);
    argumentOrField5 *= 16;
    argumentOrField5 -= 16;
    Level24_7EF38CopyVector((void*)(argumentOrAddress4),
                            (void*)(resultOrArithmetic2 + argumentOrField5));
    captured_v1_6 = Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x4C);
    captured_v0_5 = (Level24_7EF38Field(captured_v1_6, short*, 0) * 0x10) +
                    Level24_7EF38Field(captured_v1_6, int*, 0xC);
    captured_a3 = Level24_7EF38Field(captured_v0_5, int*, -0x10);
    Level24_7EF38Field(savedHeadingFrameOrActor16, unsigned char*, 0x46) =
        Level24_7EF38PlanarHeadingLookup(
            (int)(captured_a3 - Level24_7EF38Field(captured_v0_5, int*, -0x20)),
            (int)(Level24_7EF38Field(captured_v0_5, int*, -0xC) -
                  Level24_7EF38Field(captured_v0_5, int*, -0x1C)),
            (int)(0));
    Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(savedHeadingFrameOrActor16), (int)(6));
    captured_v1_7 = Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x4C);
    Level24_7EF38Field(captured_v1_7, short*, 2) =
        (short)((unsigned short)Level24_7EF38Field(captured_v1_7, short*, 0) - 1);
    Level24_7EF38RequestMobyAnimation((void*)(savedHeadingFrameOrActor16), (int)(0));
    resultOrArithmetic2 = Level24_7EF38Field(savedPrivate21, int*, 0x74);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x4A;
        goto block_62;
    }
    argumentOrAddress4 = savedIndexOrVector20 + 0x48;
    argumentOrField5 = 1;
    Level24_7EF38CompleteValue(argumentOrField5);
    argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
    Level24_7EF38CompleteValue(argumentOrIndex6);
    resultOrArithmetic2 = 0x42;
    Level24_7EF38Field(savedIndexOrVector20, unsigned char*, 0x48) = resultOrArithmetic2;
    Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                      (void*)(argumentOrIndex6));
    resultOrArithmetic2 = 0x40;
block_62:
    Level24_7EF38Field(savedIndexOrVector20, unsigned char*, 0x48) = resultOrArithmetic2;
    resultOrArithmetic2 = Level24_7EF38Field(savedPrivate21, int*, 0x54);
    if (resultOrArithmetic2 != 0) {
        goto block_64;
    }
    resultOrArithmetic2 = Level24_7EF38Field(savedPrivate21, int*, 0x50);
    if (resultOrArithmetic2 == 0) {
        goto block_65;
    }
block_64:
    Level24_7EF38Field(savedPrivate21, int*, 0x4C) = resultOrArithmetic2;
block_65:
    resultOrArithmetic2 = Level24_7EF38Field(savedPrivate21, int*, 0x4C);
    argumentOrAddress4 = savedIndexOrVector20 + 0xC;
    argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, short*, 0);
    resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, 0xC);
    argumentOrField5 *= 16;
    argumentOrField5 -= 16;
    Level24_7EF38CopyVector((void*)(argumentOrAddress4),
                            (void*)(resultOrArithmetic2 + argumentOrField5));
    captured_v1_8 = Level24_7EF38Field(savedPrivate21, int*, 0x4C);
    captured_v0_7 = (Level24_7EF38Field(captured_v1_8, short*, 0) * 0x10) +
                    Level24_7EF38Field(captured_v1_8, int*, 0xC);
    captured_a3_2 = Level24_7EF38Field(captured_v0_7, int*, -0x10);
    Level24_7EF38Field(savedIndexOrVector20, unsigned char*, 0x46) =
        Level24_7EF38PlanarHeadingLookup(
            (int)(captured_a3_2 - Level24_7EF38Field(captured_v0_7, int*, -0x20)),
            (int)(Level24_7EF38Field(captured_v0_7, int*, -0xC) -
                  Level24_7EF38Field(captured_v0_7, int*, -0x1C)),
            (int)(0));
    Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(savedIndexOrVector20), (int)(6));
    captured_v1_9 = Level24_7EF38Field(savedPrivate21, int*, 0x4C);
    Level24_7EF38Field(captured_v1_9, short*, 2) =
        (short)((unsigned short)Level24_7EF38Field(captured_v1_9, short*, 0) - 1);
    Level24_7EF38RequestMobyAnimation((void*)(savedIndexOrVector20), (int)(0));
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x74);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x4A;
        goto block_67;
    }
    argumentOrAddress4 = owner19 + 0x48;
    argumentOrField5 = 1;
    Level24_7EF38CompleteValue(argumentOrField5);
    argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
    Level24_7EF38CompleteValue(argumentOrIndex6);
    resultOrArithmetic2 = 0x42;
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
    Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                      (void*)(argumentOrIndex6));
    resultOrArithmetic2 = 0x40;
block_67:
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x54);
    if (resultOrArithmetic2 != 0) {
        goto block_69;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x50);
    if (resultOrArithmetic2 == 0) {
        goto block_70;
    }
block_69:
    Level24_7EF38Field(private18, int*, 0x4C) = resultOrArithmetic2;
block_70:
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x4C);
    argumentOrAddress4 = owner19 + 0xC;
    argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, short*, 0);
    resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, 0xC);
    argumentOrField5 *= 16;
    argumentOrField5 -= 16;
    Level24_7EF38CopyVector((void*)(argumentOrAddress4),
                            (void*)(resultOrArithmetic2 + argumentOrField5));
    captured_v1_10 = Level24_7EF38Field(private18, int*, 0x4C);
    captured_v0_9 = (Level24_7EF38Field(captured_v1_10, short*, 0) * 0x10) +
                    Level24_7EF38Field(captured_v1_10, int*, 0xC);
    captured_a3_3 = Level24_7EF38Field(captured_v0_9, int*, -0x10);
    Level24_7EF38Field(owner19, unsigned char*, 0x46) = Level24_7EF38PlanarHeadingLookup(
        (int)(captured_a3_3 - Level24_7EF38Field(captured_v0_9, int*, -0x20)),
        (int)(Level24_7EF38Field(captured_v0_9, int*, -0xC) -
              Level24_7EF38Field(captured_v0_9, int*, -0x1C)),
        (int)(0));
    Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(owner19), (int)(6));
    captured_v1_11 = Level24_7EF38Field(private18, int*, 0x4C);
    Level24_7EF38Field(captured_v1_11, short*, 2) =
        (short)((unsigned short)Level24_7EF38Field(captured_v1_11, short*, 0) - 1);
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
    Level24_7EF38Field(private18, int*, 0x78) = (int)-Level24_7EF38Field(private18, int*, 0x78);
block_71:
    captured_v1_12 = Level24_7EF38Field(private18, unsigned char*, 0x24);
    if (captured_v1_12 == 1) {
        goto block_379;
    }
    if ((int)captured_v1_12 >= 2) {
        goto block_75;
    }
    if (captured_v1_12 == 0) {
        goto block_168;
    }
    return;
block_75:
    if (captured_v1_12 != 2) {
        goto block_542;
    }
    if (Level24_7EF38_D_8006C640 != 0) {
        goto block_87;
    }
    if (Level24_7EF38_D_8006C7B4 & 1) {
        goto block_79;
    }
    if (!(Level24_7EF38Field((int)&Level24_7EF38_D_80070300 + Level24_7EF38_D_8006C58C,
                             unsigned char*, 0) &
          1)) {
        goto block_87;
    }
block_79:
    captured_v1_13 = Level24_7EF38Field(private18, int*, 0x90);
    if (captured_v1_13 < 0) {
        goto block_82;
    }
    captured_a0_10 = (captured_v1_13 * 0x58) + Level24_7EF38_D_8006C550;
    if (Level24_7EF38Field(captured_a0_10, unsigned char*, 0x48) != 0x32) {
        goto block_82;
    }
    Level24_7EF38Field(captured_a0_10, signed char*, 0x49) = 2;
block_82:
    captured_v1_14 = Level24_7EF38Field(private18, unsigned char*, 0);
    if (captured_v1_14 == 3) {
        goto block_86;
    }
    if (captured_v1_14 != 2) {
        goto block_88;
    }
    captured_a0_11 = Level24_7EF38Field(private18, int*, 0x70);
    if (captured_a0_11 < 0) {
        goto block_88;
    }
    Level24_7EF38MaskLinkedRecordFlagsById((int)(captured_a0_11), (int)(0xFC), (int)(0));
    Level24_7EF38MaskLinkedRecordFlagsById((int)(Level24_7EF38Field(private18, int*, 0x70) + 1),
                                           (int)(0xFC), (int)(0));
    Level24_7EF38WriteMatchingLinkedSelectors((int)(Level24_7EF38Field(private18, int*, 0x70)),
                                              (int)(0x22), (int)(0));
    Level24_7EF38WriteMatchingLinkedSelectors((int)(Level24_7EF38Field(private18, int*, 0x70) + 1),
                                              (int)(0x22), (int)(0));
    goto block_156;
block_86:
    Level24_7EF38Field(private18, signed char*, 2) = 2;
block_87:
block_88:
    if (Level24_7EF38Field(private18, unsigned char*, 0) != 3) {
        goto block_97;
    }
    if ((unsigned int)Level24_7EF38Field(private18, unsigned int*, 0x58) <
        (unsigned int)(int)&Level24_7EF38_func_level_24_8007572C) {
        goto block_97;
    }
    argumentOrField5 = 0;
    argumentOrIndex6 = (int)&Level24_7EF38_D_level_24_80096B68;
loop_91:
    captured_v1_15 = Level24_7EF38Field(private18, unsigned int*, 0x58);
    if (captured_v1_15 >= (unsigned int)argumentOrIndex6) {
        goto block_97;
    }
    argumentOrAddress4 = 0;
    Level24_7EF38Field(private18, int*, 0x34) =
        (int)(Level24_7EF38Field(private18, int*, 0x34) ^
              (Level24_7EF38Field(captured_v1_15, unsigned char*, 0) << 8));
loop_93:
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x34);
    resultOrArithmetic2 = fieldOrAddress3 & 0x8000;
    if (resultOrArithmetic2) {
        resultOrArithmetic2 = (unsigned int)fieldOrAddress3 << 1;
        resultOrArithmetic2 ^= 0x8005;
    } else
        resultOrArithmetic2 = (unsigned int)fieldOrAddress3 << 1;
block_95:
    Level24_7EF38Field(private18, int*, 0x34) = resultOrArithmetic2;
    argumentOrAddress4 += 1;
    if (argumentOrAddress4 < 8) {
        goto loop_93;
    }
    argumentOrField5 += 1;
    Level24_7EF38Field(private18, unsigned int*, 0x58) =
        (unsigned int)(Level24_7EF38Field(private18, unsigned int*, 0x58) + 1);
    if (argumentOrField5 < 0x40) {
        goto loop_91;
    }
block_97:
    captured_v1_17 = Level24_7EF38Field(owner19, unsigned char*, 0x48);
    if (captured_v1_17 == 0x54) {
        goto block_143;
    }
    if ((int)captured_v1_17 >= 0x55) {
        goto block_105;
    }
    if (captured_v1_17 == 0x4C) {
        goto block_161;
    }
    if ((int)captured_v1_17 >= 0x4D) {
        goto block_103;
    }
    if (captured_v1_17 == 0) {
        goto block_108;
    }
    goto block_163;
block_103:
    if (captured_v1_17 == 0x53) {
        goto block_137;
    }
    goto block_163;
block_105:
    if (captured_v1_17 == 0x55) {
        goto block_146;
    }
    if (captured_v1_17 == 0x60) {
        goto block_132;
    }
    goto block_163;
block_108:
    if (Level24_7EF38_D_8006C770 == 0) {
        goto block_112;
    }
    if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
        goto block_111;
    }
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
    Level24_7EF38Field(private18, short*, 0x86) = Level24_7EF38RandBetween((int)(3), (int)(8));
    goto block_112;
block_111:
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
    Level24_7EF38Field(private18, short*, 0x86) =
        (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
block_112:
    /* Original EXE CRC cursor: actual unsigned byte input, 64 by 8 update loops and polynomial0x8005. */
    if (Level24_7EF38Field(private18, unsigned char*, 0) != 3) {
        goto block_126;
    }
    if (Level24_7EF38Field(private18, unsigned int*, 0x58) != 0) {
        goto block_115;
    }
    Level24_7EF38Field(private18, unsigned int*, 0x58) =
        (unsigned int)(Level24_7EF38_D_8006C58C + ((int)&Level24_7EF38_main_TEXT_START + 2));
block_115:
    resultOrArithmetic2 = Level24_7EF38Field(private18, unsigned int*, 0x58);
    fieldOrAddress3 = (int)&Level24_7EF38_main_TEXT_END;
    Level24_7EF38CompleteValue(fieldOrAddress3);
    if ((unsigned int)resultOrArithmetic2 >= (unsigned int)fieldOrAddress3)
        goto block_125;
    argumentOrField5 = 0;
    argumentOrIndex6 = fieldOrAddress3;
loop_117:
    captured_v1_18 = Level24_7EF38Field(private18, unsigned int*, 0x58);
    argumentOrAddress4 = 0;
    if (captured_v1_18 >= (unsigned int)argumentOrIndex6) {
        goto block_124;
    }
    Level24_7EF38Field(private18, int*, 0x34) =
        (int)(Level24_7EF38Field(private18, int*, 0x34) ^
              (Level24_7EF38Field(captured_v1_18, unsigned char*, 0) << 8));
loop_119:
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x34);
    resultOrArithmetic2 = fieldOrAddress3 & 0x8000;
    if (resultOrArithmetic2) {
        resultOrArithmetic2 = (unsigned int)fieldOrAddress3 << 1;
        resultOrArithmetic2 ^= 0x8005;
    } else
        resultOrArithmetic2 = (unsigned int)fieldOrAddress3 << 1;
block_121:
    Level24_7EF38Field(private18, int*, 0x34) = resultOrArithmetic2;
    argumentOrAddress4 += 1;
    if (argumentOrAddress4 < 8) {
        goto loop_119;
    }
    MATCHING_BARRIER_VOLATILE("memory");
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x34);
    fieldOrAddress3 = Level24_7EF38Field(private18, unsigned int*, 0x58);
    resultOrArithmetic2 &= 3;
    resultOrArithmetic2++;
    fieldOrAddress3 += resultOrArithmetic2;
    argumentOrField5++;
    Level24_7EF38Field(private18, unsigned int*, 0x58) = fieldOrAddress3;
    if (argumentOrField5 < 0x40) {
        goto loop_117;
    }
    resultOrArithmetic2 = (int)&Level24_7EF38_main_TEXT_END;
    resultOrArithmetic2 = (unsigned int)fieldOrAddress3 < (unsigned int)resultOrArithmetic2;
    if (resultOrArithmetic2) {
        goto block_126;
    }
block_124:
    Level24_7EF38Field(private18, unsigned int*, 0x58) =
        (unsigned int)(int)&Level24_7EF38_func_level_24_8007572C;
block_125:
block_126:
    if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) == 0) {
        goto block_163;
    }
    if (Level24_7EF38Field(private18, unsigned char*, 0) != 2) {
        goto block_130;
    }
    if (Level24_7EF38_D_8006C7B4 & 1) {
        goto block_131;
    }
    Level24_7EF38_D_8006C7B4 |= 1;
block_130:
block_131:
    Level24_7EF38StartDialogue((void*)(owner19), (int)(0), (int)(6));
    Level24_7EF38Field(private18, unsigned short*, 0x60) =
        (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
    Level24_7EF38Field(private18, short*, 0x62) =
        (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x60U;
    Level24_7EF38Field(owner19, unsigned char*, 0x49) =
        (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) | 2);
    goto block_163;
block_132:
    if (Level24_7EF38_D_8006E344 == 1) {
        goto block_163;
    }
    if (Level24_7EF38Field(private18, int*, 0x70) < 0) {
        goto block_136;
    }
    if (Level24_7EF38Field(private18, unsigned char*, 4) != 1) {
        goto block_136;
    }
    argumentOrAddress4 = owner19 + 0x48;
    argumentOrField5 = 1;
    Level24_7EF38CompleteValue(argumentOrField5);
    argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
    Level24_7EF38CompleteValue(argumentOrIndex6);
    resultOrArithmetic2 = 0x4C;
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
    Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                      (void*)(argumentOrIndex6));
    captured_a0_12 = Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x80), int*, 0xC);
    Level24_7EF38PrepareCameraMode9Vectors((void*)(captured_a0_12), (void*)(captured_a0_12 + 0x10));
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x53U;
    Level24_7EF38Field(private18, int*, 0x8C) = 0x3C;
    goto block_163;
block_136:
    Level24_7EF38RequestMobyAnimation((void*)(owner19),
                                      (int)(Level24_7EF38Field(private18, short*, 0x62)));
    Level24_7EF38Field(owner19, unsigned char*, 0x48) =
        (unsigned char)Level24_7EF38Field(private18, unsigned short*, 0x60);
    Level24_7EF38Field(owner19, unsigned char*, 0x49) =
        (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) & 0xFD);
    goto block_163;
block_137:
    if (Level24_7EF38_D_8006E048 != 2) {
        goto block_163;
    }
    if (Level24_7EF38CountTimerDown((void*)(private18 + 0x8C), (int)(4)) == 0) {
        goto block_163;
    }
    captured_v1_21 = Level24_7EF38Field(private18, int*, 0x90);
    if (captured_v1_21 < 0) {
        goto block_142;
    }
    captured_a0_13 = (captured_v1_21 * 0x58) + Level24_7EF38_D_8006C550;
    if (Level24_7EF38Field(captured_a0_13, unsigned char*, 0x48) != 0x32) {
        goto block_142;
    }
    Level24_7EF38Field(captured_a0_13, signed char*, 0x49) = 2;
block_142:
    Level24_7EF38PlaySoundFromGlobalByteTable((void*)(owner19), (int)(4), (int)(1));
    Level24_7EF38MaskLinkedRecordFlagsById((int)(Level24_7EF38Field(private18, int*, 0x70)),
                                           (int)(0xFC), (int)(0));
    Level24_7EF38MaskLinkedRecordFlagsById((int)(Level24_7EF38Field(private18, int*, 0x70) + 1),
                                           (int)(0xFC), (int)(0));
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x54U;
    Level24_7EF38Field(private18, int*, 0x8C) = 0x5A;
    goto block_163;
block_143:
    if (!(Level24_7EF38QueryShiftedLinkedRecordWordByByteId(
              (int)(Level24_7EF38Field(private18, int*, 0x70))) &
          2)) {
        goto block_163;
    }
    if (Level24_7EF38CountTimerDown((void*)(private18 + 0x8C), (int)(4)) == 0) {
        goto block_163;
    }
    Level24_7EF38Field(private18, int*, 0x70) = 0;
    Level24_7EF38TransitionCameraModes9And10((int)(1));
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
    Level24_7EF38Field(private18, int*, 0x8C) = 0x3C;
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x55U;
    goto block_163;
block_146:
    if (Level24_7EF38CountTimerDown((void*)(private18 + 0x8C), (int)(4)) == 0) {
        goto block_159;
    }
    savedIndexOrVector20 = Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x54), short*, 2);
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(5));
    captured_v1_22 = Level24_7EF38Field(private18, int*, 0x70);
    if (captured_v1_22 == 0) {
        goto block_150;
    }
    if (captured_v1_22 == 1) {
        goto block_154;
    }
    goto block_160;
block_150:
    if (!(Level24_7EF38UpdateMobyPathMotion(
              (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x54)), (int)(0x200),
              (int)(0x80), (int)(0), (int)(8), (int)(0xC), (int)(5)) &
          1)) {
        goto block_159;
    }
    captured_a1_3 = Level24_7EF38Field(private18, int*, 0x54);
    captured_a2_2 = Level24_7EF38Field(captured_a1_3, short*, 2);
    if (captured_a2_2 == 0) {
        goto block_156;
    }
    captured_v1_23 = Level24_7EF38Field(captured_a1_3, int*, 0xC);
    if (!(Level24_7EF38Field(((savedIndexOrVector20 * 0x10) + captured_v1_23), int*, 0xC) & 1)) {
        goto block_159;
    }
    Level24_7EF38Field(private18, short*, 0x26) = Level24_7EF38ComputeArcVerticalVelocity(
        (void*)(owner19 + 0xC), (void*)(captured_v1_23 + (captured_a2_2 * 0x10)), (int)(0x80),
        (int)(-0xC), (void*)(0));
    Level24_7EF38Field(private18, int*, 0x70) = 1;
    Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(3));
    goto block_160;
block_154:
    resultOrArithmetic2 = Level24_7EF38UpdateMobyPathMotion(
        (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x54)), (int)(0x200),
        (int)(0x80), (int)(0), (int)(8), (int)(0xC), (int)(0));
    argumentOrAddress4 = (int)&originalFrame.sp30;
    Level24_7EF38CompleteValue(argumentOrAddress4);
    savedIndexFrameOrActor17 = owner19 + 0xC;
    argumentOrField5 = savedIndexFrameOrActor17;
    fieldOrAddress3 = Level24_7EF38Field(private18, unsigned short*, 0x26);
    __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "r"(fieldOrAddress3));
    savedHeadingFrameOrActor16 = resultOrArithmetic2;
    Level24_7EF38CompleteValue(savedHeadingFrameOrActor16);
    fieldOrAddress3 -= 0xC;
    Level24_7EF38Field(private18, short*, 0x26) = fieldOrAddress3;
    fieldOrAddress3 = (unsigned int)fieldOrAddress3 << 16;
    argumentOrIndex6 = Level24_7EF38Field(owner19, int*, 0x14);
    fieldOrAddress3 >>= 16;
    argumentOrIndex6 += fieldOrAddress3;
    Level24_7EF38Field(owner19, int*, 0x14) = argumentOrIndex6;
    Level24_7EF38CopyVector((void*)(argumentOrAddress4), (void*)(argumentOrField5));
    originalFrame.sp38 += 0x200;
    Level24_7EF38_SpawnParticle((int)(2), (int)(0xC), (void*)(owner19), (int)((int*)5));
    resultOrArithmetic2 = savedHeadingFrameOrActor16 & 1;
    Level24_7EF38CompleteValue(resultOrArithmetic2);
    if (!resultOrArithmetic2) {
        goto block_159;
    }
    captured_a1_4 = Level24_7EF38Field(private18, int*, 0x54);
    captured_a2_4 = Level24_7EF38Field(captured_a1_4, short*, 2);
    if (captured_a2_4 != 0) {
        goto block_157;
    }
block_156:
    Level24_7EF38DeleteMoby((void*)(owner19));
    return;
block_157:
    captured_v1_25 = Level24_7EF38Field(captured_a1_4, int*, 0xC);
    if (!(Level24_7EF38Field(((savedIndexOrVector20 * 0x10) + captured_v1_25), int*, 0xC) & 1)) {
        goto block_159;
    }
    Level24_7EF38Field(private18, short*, 0x26) = Level24_7EF38ComputeArcVerticalVelocity(
        (void*)(savedIndexFrameOrActor17), (void*)(captured_v1_25 + (captured_a2_4 * 0x10)),
        (int)(0x80), (int)(-0xC), (void*)(0));
block_159:
block_160:
    Level24_7EF38Field((int)&Level24_7EF38_D_80070328, int*, 0x20C) = 0x10000002;
    Level24_7EF38SetClampedPlayerTargetAngles((void*)(owner19 + 0xC));
    goto block_163;
block_161:
    captured_a0_14 = Level24_7EF38Field(private18, int*, 0x70);
    if (captured_a0_14 < 0) {
        goto block_163;
    }
    Level24_7EF38MaskLinkedRecordFlagsById((int)(captured_a0_14), (int)(0xFC), (int)(0));
    Level24_7EF38MaskLinkedRecordFlagsById((int)(Level24_7EF38Field(private18, int*, 0x70) + 1),
                                           (int)(0xFC), (int)(0));
    Level24_7EF38WriteMatchingLinkedSelectors((int)(Level24_7EF38Field(private18, int*, 0x70)),
                                              (int)(0x22), (int)(0));
    Level24_7EF38WriteMatchingLinkedSelectors((int)(Level24_7EF38Field(private18, int*, 0x70) + 1),
                                              (int)(0x22), (int)(0));
    Level24_7EF38Field(private18, int*, 0x70) = -1;
    Level24_7EF38DeleteMoby((void*)(owner19));
    return;
block_163:
    /* Original completed CRC endpoint; complete signed64 magic product, high-word projection, then exact remainder40. */
    if (Level24_7EF38Field(private18, unsigned int*, 0x58) !=
        (int)&Level24_7EF38_D_level_24_80096B68) {
        goto block_542;
    }
    if (Level24_7EF38Field(private18, int*, 0x34) == 0) {
        goto block_542;
    }
    if (Level24_7EF38_D_8006C640 & 0x1F) {
        goto block_542;
    }
    resultOrArithmetic2 = Level24_7EF38_rand();
    fieldOrAddress3 = 0x66666667;
    remainderBy40Product.full = (long long)resultOrArithmetic2 * (long long)fieldOrAddress3;
    __asm__("" : "=x"(remainderBy40Product.full) : "0"(remainderBy40Product.full));
    fieldOrAddress3 = resultOrArithmetic2 >> 31;
    productHigh9 = remainderBy40Product.words.high;
    Level24_7EF38CompleteValue(productHigh9);
    argumentOrAddress4 = productHigh9 >> 4;
    savedIndexFrameOrActor17 = argumentOrAddress4 - fieldOrAddress3;
    Level24_7EF38CompleteValue(savedIndexFrameOrActor17);
    fieldOrAddress3 = savedIndexFrameOrActor17 * 5;
    fieldOrAddress3 *= 8;
    savedIndexFrameOrActor17 = resultOrArithmetic2 - fieldOrAddress3;
    if ((unsigned int)(savedIndexFrameOrActor17 - 9) < 9U) {
        goto block_542;
    }
    resultOrArithmetic2 = Level24_7EF38_rand();
    savedHeadingFrameOrActor16 = resultOrArithmetic2 & 7;
    resultOrArithmetic2 = Level24_7EF38_rand();
    resultOrArithmetic2 &= 7;
    argumentOrAddress4 = 1;
    argumentOrField5 = (int)&Level24_7EF38_D_80071AB0;
    fieldOrAddress3 = savedIndexFrameOrActor17 << 5;
    fieldOrAddress3 += argumentOrField5;
    savedHeadingFrameOrActor16 *= 4;
    savedHeadingFrameOrActor16 += fieldOrAddress3;
    fieldOrAddress3 = Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0);
    argumentOrAddress4 <<= resultOrArithmetic2;
    fieldOrAddress3 |= argumentOrAddress4;
    Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0) = fieldOrAddress3;
    return;
block_168:
    /* The original captured private24 value selected mode0. No external difficulty or actor-state bound is assumed. */
    if (Level24_7EF38_D_8006C640 != 0) {
        goto block_178;
    }
    if (Level24_7EF38_D_8006C7B4 & 1) {
        goto block_171;
    }
    if (!(Level24_7EF38Field((int)&Level24_7EF38_D_80070300 + Level24_7EF38_D_8006C58C,
                             unsigned char*, 0) &
          1)) {
        goto block_178;
    }
block_171:
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x64);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x47;
        goto block_177;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x74);
    if (resultOrArithmetic2 < 0) {
        goto block_174;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, unsigned char*, 0x25);
    fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
    resultOrArithmetic2 *= 8;
    Level24_7EF38Field(fieldOrAddress3, int*, 0) = resultOrArithmetic2;
    resultOrArithmetic2 = 0x4D;
    goto block_177;
block_174:
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x44);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x43;
        goto block_177;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x40);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x42;
        goto block_177;
    }
    resultOrArithmetic2 = 0x41;
block_177:
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
    __asm__("" ::"m"(Level24_7EF38Field(owner19, unsigned char*, 0x48)));
    Level24_7EF38RegisterTrackedValue((void*)(owner19 + 0x48), (int)(1),
                                      (void*)((int)&Level24_7EF38_D_8006C7F8));
block_178:
    captured_v1_26 = Level24_7EF38Field(owner19, unsigned char*, 0x48);
    if (captured_v1_26 >= 0x61U) {
        goto block_542;
    }
    switch (captured_v1_26) {
        default:
            goto block_542;
        case 0x60:
            goto sharedState60;
        case 0x0:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_184;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_183;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_184;
        block_183:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_184:
            Level24_7EF38Field(private18, signed char*, 5) = 0;
            if (Level24_7EF38Field(private18, int*, 0x28) == 0) {
                goto block_518;
            }
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 4U;
            goto block_208;
        case 0x4:
            if (Level24_7EF38Field(owner19, unsigned char*, 0x3C) != 0xB) {
                goto block_188;
            }
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) != 0) {
                goto block_520;
            }
        block_188:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_542;
            }
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x38);
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            fieldOrAddress3 = Level24_7EF38_D_8006C550;
            resultOrArithmetic2 *= 8;
            fieldOrAddress3 = resultOrArithmetic2 + fieldOrAddress3;
            argumentOrAddress4 = Level24_7EF38Field(fieldOrAddress3, short*, 0x36);
            savedHeadingFrameOrActor16 = 0;
            if (argumentOrAddress4 != 5) {
                goto block_194;
            }
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, unsigned char*, 0x48);
            if (!(fieldOrAddress3 & 0x80)) {
                goto block_192;
            }
            Level24_7EF38Field(private18, signed char*, 2) = 2;
            goto block_198;
        block_192:
            Level24_7EF38CompleteValue(fieldOrAddress3);
            if ((fieldOrAddress3 & 0xFF) == 0x61) {
                goto block_198;
            }
            savedHeadingFrameOrActor16 = 1;
            goto block_198;
        block_194:
            if (argumentOrAddress4 == 0xC) {
                goto block_196;
            }
            if (argumentOrAddress4 != 0x229) {
                goto block_198;
            }
        block_196:
            if ((unsigned char)Level24_7EF38Field(fieldOrAddress3, unsigned char*, 0x48) < 0x46U) {
                goto block_198;
            }
            savedHeadingFrameOrActor16 = 1;
        block_198:
            if (Level24_7EF38Field(owner19, unsigned char*, 0x3C) == 9) {
                goto block_201;
            }
            if (Level24_7EF38Field(private18, int*, 0x38) !=
                Level24_7EF38Field(private18, int*, 0x40)) {
                goto block_205;
            }
            if (Level24_7EF38_rand() & 1) {
                goto block_204;
            }
        block_201:
            if (Level24_7EF38Field(private18, int*, 0x28) == 0) {
                goto block_204;
            }
            if (savedHeadingFrameOrActor16 != 0) {
                goto block_204;
            }
            argumentOrAddress4 = owner19;
            resultOrArithmetic2 = Level24_7EF38Field(argumentOrAddress4, unsigned char*, 0x46);
            argumentOrField5 = 5;
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            resultOrArithmetic2 = 1;
            goto block_494;
        block_204:
            if (Level24_7EF38Field(private18, int*, 0x38) ==
                Level24_7EF38Field(private18, int*, 0x40)) {
                goto block_542;
            }
        block_205:
            if (!(Level24_7EF38_rand() & 3)) {
                goto block_208;
            }
            if (Level24_7EF38Field(owner19, unsigned char*, 0x3C) == 9) {
                goto block_208;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(9));
            return;
        block_208:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0xB));
            return;
        case 0x1:
            if (enabled22 == 0) {
                goto block_212;
            }
            if (!(Level24_7EF38UpdateMobyPathMotion(
                      (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x28)),
                      (int)(0x200), (int)(0x96), (int)(0x12C), (int)(3), (int)(0x20), (int)(6)) &
                  2)) {
                goto block_212;
            }
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x28), short*, 0xA) = -1;
            captured_v1_29 = Level24_7EF38Field(private18, int*, 0x28);
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0xA;
            Level24_7EF38Field(captured_v1_29, short*, 2) =
                (short)(Level24_7EF38Field(captured_v1_29, unsigned short*, 0) - 1);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 3U;
            goto block_539;
        block_212:
            captured_a0_16 =
                (Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550;
            captured_v1_30 = Level24_7EF38Field(captured_a0_16, short*, 0x36);
            argumentOrField5 = 0;
            if (captured_v1_30 != 5) {
                goto block_215;
            }
            if (Level24_7EF38Field(captured_a0_16, unsigned char*, 0x48) == 0x61) {
                goto block_219;
            }
            resultOrArithmetic2 = Level24_7EF38Field(captured_a0_16, int*, 0);
            resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, short*, 0x18);
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            argumentOrField5 = resultOrArithmetic2 == 0;
            goto block_219;
        block_215:
            if (captured_v1_30 == 0xC) {
                goto block_217;
            }
            if (captured_v1_30 != 0x229) {
                goto block_219;
            }
        block_217:
            if ((unsigned char)Level24_7EF38Field(captured_a0_16, unsigned char*, 0x48) < 0x46U) {
                goto block_219;
            }
            argumentOrField5 = 1;
        block_219:
            if (enabled22 == 0) {
                goto block_221;
            }
            if (argumentOrField5 == 0) {
                goto block_541;
            }
        block_221:
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x28);
            fieldOrAddress3 = -1;
            Level24_7EF38Field(resultOrArithmetic2, short*, 0xA) = fieldOrAddress3;
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x28);
            resultOrArithmetic2 = Level24_7EF38Field(argumentOrAddress4, short*, 2);
            fieldOrAddress3 = resultOrArithmetic2;
            if (resultOrArithmetic2 <= 0)
                goto block_223;
            resultOrArithmetic2 = fieldOrAddress3 - 1;
            Level24_7EF38Field(argumentOrAddress4, short*, 2) = resultOrArithmetic2;
        block_223:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 3U;
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0xA;
            goto block_539;
        case 0x2:
            argumentOrAddress4 = owner19;
            if (enabled22 == 0)
                goto block_226;
            __asm__("" : "=r"(argumentOrAddress4) : "0"(argumentOrAddress4), "i"(5));
            argumentOrField5 = 5;
            goto block_227;
        block_226:
            MATCHING_KEEP_VOLATILE_CLOBBER(enabled22, "$5");
            argumentOrField5 = 0;
        block_227:
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
            if (enabled22 == 0) {
                goto block_540;
            }
            resultOrArithmetic2 = Level24_7EF38UpdateMobyPathMotion(
                (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x28)), (int)(0x200),
                (int)(0x96), (int)(0x12C), (int)(3), (int)(0x20), (int)(6));
            resultOrArithmetic2 &= 2;
            argumentOrAddress4 = owner19;
            if (!resultOrArithmetic2) {
                goto block_540;
            }
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x28);
            resultOrArithmetic2 = 1;
            Level24_7EF38Field(fieldOrAddress3, short*, 0xA) = resultOrArithmetic2;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x28);
            argumentOrField5 = 0xB;
            Level24_7EF38Field(resultOrArithmetic2, short*, 2) = 0;
            resultOrArithmetic2 = 5;
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(0));
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            goto block_539;
        case 0x3:
            captured_v1_31 = Level24_7EF38Field(private18, int*, 0x28);
            captured_v0_11 = (Level24_7EF38Field(captured_v1_31, short*, 2) * 0x10) +
                             Level24_7EF38Field(captured_v1_31, int*, 0xC);
            Level24_7EF38TurnMobyTowardHeading(
                (void*)(owner19),
                (int)(Level24_7EF38PlanarHeadingLookup(
                    (int)(Level24_7EF38Field(captured_v0_11, int*, -0x10) -
                          Level24_7EF38Field(owner19, int*, 0xC)),
                    (int)(Level24_7EF38Field(captured_v0_11, int*, -0xC) -
                          Level24_7EF38Field(owner19, int*, 0x10)),
                    (int)(0))),
                (int)(6), (int)(2), (int)(1), (int)(0));
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_542;
            }
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 2U;
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(5));
            return;
        case 0x5:
            argumentOrAddress4 = owner19;
            argumentOrIndex6 = 6;
            argumentOrField7 = 2;
            argumentOrField5 = Level24_7EF38Field(private18, short*, 0x26);
            if (Level24_7EF38TurnMobyTowardHeading(
                    (void*)(argumentOrAddress4), (int)(argumentOrField5), (int)(argumentOrIndex6),
                    (int)(argumentOrField7), (int)(1), (int)(0)) == 0) {
                goto block_542;
            }
            fieldOrAddress3 = Level24_7EF38Field(private18, unsigned short*, 0x26);
            resultOrArithmetic2 = 4;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            Level24_7EF38Field(owner19, unsigned char*, 0x46) = fieldOrAddress3;
            return;
        case 0x3C:
            captured_a0_18 = Level24_7EF38Field(private18, int*, 0x64);
            if (captured_a0_18 >= 0) {
                goto block_241;
            }
            captured_v1_32 = Level24_7EF38Field(private18, int*, 0x44);
            if (captured_v1_32 < 0) {
                goto block_237;
            }
            if (!(Level24_7EF38Field(((captured_v1_32 * 0x58) + Level24_7EF38_D_8006C550),
                                     unsigned char*, 0x48) &
                  0x80)) {
                goto block_241;
            }
        block_237:
            captured_v1_33 = Level24_7EF38Field(private18, int*, 0x40);
            if (captured_v1_33 < 0) {
                goto block_239;
            }
            if (!(Level24_7EF38Field(((captured_v1_33 * 0x58) + Level24_7EF38_D_8006C550),
                                     unsigned char*, 0x48) &
                  0x80)) {
                goto block_241;
            }
        block_239:
            if (captured_a0_18 != -1) {
                goto block_241;
            }
            captured_v0_12 = Level24_7EF38Field(private18, int*, 0x5C);
            Level24_7EF38Field(captured_v0_12, int*, 0) += 1;
            Level24_7EF38Field(private18, int*, 0x64) = -2;
        block_241:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x3DU;
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x28), short*, 0xA) = 1;
            goto block_438;
        case 0x3D:
            if (Level24_7EF38Field(private18, int*, 0x28) != 0) {
                goto block_244;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            resultOrArithmetic2 = 2;
            goto block_249;
        block_244:
            if (enabled22 != 0) {
                goto block_248;
            }
            Level24_7EF38CompleteValue(enabled22);
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) == 0) {
                goto block_247;
            }
            Level24_7EF38StartDialogue((void*)(owner19), (int)(0), (int)(6));
            Level24_7EF38Field(private18, unsigned short*, 0x60) =
                (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
            Level24_7EF38Field(private18, short*, 0x62) =
                (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x60U;
            Level24_7EF38Field(owner19, unsigned char*, 0x49) =
                (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) | 2);
        block_247:
            resultOrArithmetic2 = 0;
            goto block_249;
        block_248:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(5));
            resultOrArithmetic2 = Level24_7EF38UpdateMobyPathMotion(
                (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x28)), (int)(0x200),
                (int)(0x96), (int)(0x12C), (int)(3), (int)(0x18), (int)(6));
        block_249:
            if (!(resultOrArithmetic2 & 2)) {
                goto block_540;
            }
            resultOrArithmetic2 = 0x3E;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x2000;
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(0));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            goto block_540;
        case 0x3E:
            savedIndexFrameOrActor17 = 6;
            if (Level24_7EF38Field(private18, short*, 0x26) == 0x2000) {
                goto block_253;
            }
            savedIndexFrameOrActor17 = 2;
        block_253:
            argumentOrAddress4 = owner19;
            if (enabled22 != 0) {
                goto block_258;
            }
            Level24_7EF38CompleteValue(enabled22);
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(0));
            argumentOrAddress4 = 0;
            if (Level24_7EF38Field(private18, short*, 0x26) != 0x2000) {
                goto block_262;
            }
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) == 0) {
                goto block_257;
            }
            Level24_7EF38StartDialogue((void*)(owner19), (int)(0), (int)(6));
            Level24_7EF38Field(private18, unsigned short*, 0x60) =
                (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
            Level24_7EF38Field(private18, short*, 0x62) =
                (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x60U;
            Level24_7EF38Field(owner19, unsigned char*, 0x49) =
                (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) | 2);
        block_257:
            argumentOrAddress4 = 0;
            goto block_262;
        block_258:
            if (Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), short*, 2) < 0) {
                goto block_261;
            }
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(5));
            argumentOrAddress4 = Level24_7EF38UpdateMobyPathMotion(
                (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x4C)), (int)(0x200),
                (int)(0x96), (int)(0x12C), (int)(3), (int)(0x18), (int)(savedIndexFrameOrActor17));
            if (!(argumentOrAddress4 & 2)) {
                goto block_277;
            }
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), short*, 2) = -1;
            goto block_262;
        block_261:
            argumentOrAddress4 = 2;
        block_262:
            resultOrArithmetic2 = argumentOrAddress4 & 2;
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            if (!resultOrArithmetic2) {
                goto block_277;
            }
            if (Level24_7EF38Field(private18, short*, 0x26) != 0x2000) {
                goto block_277;
            }
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), short*, 2) = 0;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x44);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x38);
            if (resultOrArithmetic2 == fieldOrAddress3) {
                resultOrArithmetic2 = 0x43;
                goto block_267;
            }
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x40);
            if (resultOrArithmetic2 != fieldOrAddress3) {
                resultOrArithmetic2 = 0x41;
                goto block_267;
            }
            resultOrArithmetic2 = 0x42;
        block_267:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            __asm__("" ::"m"(Level24_7EF38Field(owner19, unsigned char*, 0x48)));
            Level24_7EF38RegisterTrackedValue((void*)(owner19 + 0x48), (int)(1),
                                              (void*)((int)&Level24_7EF38_D_8006C7F8));
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x40);
            if (fieldOrAddress3 < 0) {
                goto block_270;
            }
            if (fieldOrAddress3 == Level24_7EF38Field(private18, int*, 0x38)) {
                goto block_270;
            }
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x2C);
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x50);
            resultOrArithmetic2 = 3;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x28) = fieldOrAddress3;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x40);
            argumentOrField5 = Level24_7EF38Field(private18, volatile int*, 0x28);
            resultOrArithmetic2 = -1;
            Level24_7EF38Field(private18, int*, 0x3C) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x4C) = argumentOrAddress4;
            Level24_7EF38Field(private18, int*, 0x38) = fieldOrAddress3;
            goto block_273;
        block_270:
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x44);
            if (fieldOrAddress3 < 0) {
                goto block_274;
            }
            if (fieldOrAddress3 == Level24_7EF38Field(private18, int*, 0x38)) {
                goto block_274;
            }
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x30);
            Level24_7EF38Field(private18, int*, 0x38) = fieldOrAddress3;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x48);
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x54);
            Level24_7EF38Field(private18, int*, 0x28) = resultOrArithmetic2;
            argumentOrField5 = Level24_7EF38Field(private18, volatile int*, 0x28);
            resultOrArithmetic2 = -1;
            Level24_7EF38Field(private18, int*, 0x40) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x3C) = fieldOrAddress3;
            Level24_7EF38Field(private18, int*, 0x4C) = argumentOrAddress4;
        block_273:
            resultOrArithmetic2 = Level24_7EF38Field(argumentOrField5, int*, 0xC);
            argumentOrIndex6 = 0;
            argumentOrField7 = Level24_7EF38Field(resultOrArithmetic2, int*, 0x10);
            argumentOrAddress4 = Level24_7EF38Field(resultOrArithmetic2, int*, 0);
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, 0x14);
            argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, int*, 4);
            argumentOrAddress4 = argumentOrField7 - argumentOrAddress4;
            resultOrArithmetic2 = Level24_7EF38PlanarHeadingLookup(
                (int)(argumentOrAddress4), (int)(fieldOrAddress3 - argumentOrField5),
                (int)(argumentOrIndex6));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0xB;
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 5U;
            goto block_539;
        block_274:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x3FU;
            if (Level24_7EF38Field(private18, int*, 0x64) < 0) {
                goto block_276;
            }
            captured_v1_37 = Level24_7EF38Field(private18, int*, 0x5C);
            Level24_7EF38Field(private18, signed char*, 2) = 2;
            fieldOrAddress3 = captured_v1_37;
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, int*, 0);
            resultOrArithmetic2++;
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(0));
            Level24_7EF38Field(fieldOrAddress3, int*, 0) = resultOrArithmetic2;
            goto block_538;
        block_276:
            Level24_7EF38Field(private18, signed char*, 2) = 4;
            goto block_538;
        block_277:
            if (enabled22 == 0) {
                goto block_285;
            }
            if (Level24_7EF38Field(private18, short*, 0x26) != 0x2000) {
                goto block_286;
            }
            captured_v1_38 = Level24_7EF38Field(private18, int*, 0x4C);
            captured_v0_14 = Level24_7EF38Field(captured_v1_38, short*, 2);
            if (captured_v0_14 < 0) {
                goto block_285;
            }
            captured_v0_15 =
                (captured_v0_14 * 0x10) + Level24_7EF38Field(captured_v1_38, int*, 0xC);
            if (Level24_7EF38AbsoluteByteAngleDelta(
                    (int)(Level24_7EF38Field(owner19, unsigned char*, 0x46)),
                    (int)(Level24_7EF38PlanarHeadingLookup(
                        (int)(Level24_7EF38Field(captured_v0_15, int*, 0) -
                              Level24_7EF38Field(owner19, int*, 0xC)),
                        (int)(Level24_7EF38Field(captured_v0_15, int*, 4) -
                              Level24_7EF38Field(owner19, int*, 0x10)),
                        (int)(0)))) >= 0x18) {
                goto block_285;
            }
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x4C);
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, short*, 2);
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0xC);
            resultOrArithmetic2 *= 16;
            argumentOrField5 = resultOrArithmetic2 + fieldOrAddress3;
            resultOrArithmetic2 = Level24_7EF38Field(owner19, int*, 0x14);
            fieldOrAddress3 = Level24_7EF38Field(argumentOrField5, int*, 8);
            resultOrArithmetic2 -= fieldOrAddress3;
            if (resultOrArithmetic2 >= 0) {
                goto block_283;
            }
            resultOrArithmetic2 = -resultOrArithmetic2;
        block_283:
            if (resultOrArithmetic2 < 0x101) {
                goto block_285;
            }
            resultOrArithmetic2 = Level24_7EF38ComputeArcVerticalVelocity(
                (void*)(owner19 + 0xC), (void*)(argumentOrField5), (int)(0x96), (int)(-0xC),
                (void*)(&originalFrame.sp40));
            __asm__("" ::"m"(originalFrame.sp40));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            goto block_540;
        block_285:
            if (Level24_7EF38Field(private18, short*, 0x26) == 0x2000) {
                goto block_541;
            }
        block_286:
            Level24_7EF38Field(owner19, int*, 0x14) =
                (int)(Level24_7EF38Field(owner19, int*, 0x14) +
                      Level24_7EF38Field(private18, short*, 0x26));
            captured_v0_16 = Level24_7EF38ProbeGroundFromRaisedMoby((void*)(owner19));
            if (captured_v0_16 < Level24_7EF38Field(owner19, int*, 0x14)) {
                goto block_288;
            }
            Level24_7EF38Field(owner19, int*, 0x14) = captured_v0_16;
            resultOrArithmetic2 = 0x2000;
            goto block_289;
        block_288:
            resultOrArithmetic2 = (unsigned short)Level24_7EF38Field(private18, short*, 0x26) - 0xC;
        block_289:
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(0));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            goto block_540;
        case 0x3F:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_294;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_293;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_294;
        block_293:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_294:
            captured_v1_40 = Level24_7EF38Field(private18, int*, 0x64);
            if (captured_v1_40 < 0) {
                goto block_296;
            }
            captured_v1_41 = Level24_7EF38_D_8006C550 + (captured_v1_40 * 0x58);
            captured_a3_5 = Level24_7EF38Field(captured_v1_41, int*, 0xC);
            resultOrArithmetic2 = Level24_7EF38PlanarHeadingLookup(
                (int)(captured_a3_5 - Level24_7EF38Field(owner19, int*, 0xC)),
                (int)(Level24_7EF38Field(captured_v1_41, int*, 0x10) -
                      Level24_7EF38Field(owner19, int*, 0x10)),
                (int)(0));
            argumentOrAddress4 = owner19;
            resultOrArithmetic2 = resultOrArithmetic2 + 8;
            goto block_491;
        block_296:
            if (Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0) >=
                (int)Level24_7EF38Field(private18, unsigned char*, 0x25)) {
                goto block_496;
            }
            Level24_7EF38TurnMobyTowardHeading(
                (void*)(owner19),
                (int)((Level24_7EF38Field(private18, short*, 0x26) + 0x80) & 0xFF), (int)(4),
                (int)(0), (int)(1), (int)(0));
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(0));
            goto block_519;
        case 0x4A:
            captured_a0_19 =
                (Level24_7EF38Field(private18, int*, 0x74) * 0x58) + Level24_7EF38_D_8006C550;
            captured_v1_42 = Level24_7EF38Field(captured_a0_19, unsigned char*, 0x48);
            if (captured_v1_42 == 0x40) {
                goto block_300;
            }
            if (captured_v1_42 != 0x4E) {
                goto block_542;
            }
        block_300:
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(captured_a0_19), (int)(4));
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(0), (void*)(&originalFrame.sp30));
            resultOrArithmetic2 = Level24_7EF38ComputeArcVerticalVelocity(
                (void*)(owner19 + 0xC), (void*)(&originalFrame.sp30), (int)(0x3C), (int)(-0xC),
                (void*)(&originalFrame.sp44));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0xA;
            Level24_7EF38CompleteValue(argumentOrAddress4);
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            __asm__("" ::"m"(originalFrame.sp44));
            resultOrArithmetic2 = 0x4B;
            goto block_494;
        case 0x4B:
            Level24_7EF38RefreshMobySpatialGridAndBasis(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(4));
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(0), (void*)(&originalFrame.sp48));
            Level24_7EF38Field(owner19, int*, 0x14) =
                (int)(Level24_7EF38Field(owner19, int*, 0x14) +
                      Level24_7EF38Field(private18, short*, 0x26));
            Level24_7EF38Field(private18, short*, 0x26) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x26) - 0xC);
            Level24_7EF38ResolveMobyHeadingStep(
                (void*)(owner19),
                (int)(Level24_7EF38PlanarHeadingLookup(
                    (int)(originalFrame.sp48 - Level24_7EF38Field(owner19, int*, 0xC)),
                    (int)(originalFrame.sp4C - Level24_7EF38Field(owner19, int*, 0x10)), (int)(0))),
                (int)(0x3C), (int)(0), (int)(0), (int)(0));
            resultOrArithmetic2 = Level24_7EF38Field(owner19, int*, 0x14);
            fieldOrAddress3 = originalFrame.sp50;
            resultOrArithmetic2 -= fieldOrAddress3;
            if (resultOrArithmetic2 >= 0) {
                goto block_303;
            }
            resultOrArithmetic2 = -resultOrArithmetic2;
        block_303:
            savedHeadingFrameOrActor16 = owner19 + 0xC;
            if (resultOrArithmetic2 >= 0x100) {
                goto block_540;
            }
            if (Level24_7EF38ApproximatePlanarDistance((void*)(savedHeadingFrameOrActor16),
                                                       (void*)(&originalFrame.sp48)) >= 0x100) {
                goto block_540;
            }
            Level24_7EF38CopyVector((void*)(savedHeadingFrameOrActor16),
                                    (void*)(&originalFrame.sp48));
            argumentOrAddress4 = owner19 + 0x48;
            argumentOrField5 = 1;
            Level24_7EF38CompleteValue(argumentOrField5);
            argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
            Level24_7EF38CompleteValue(argumentOrIndex6);
            resultOrArithmetic2 = 0x4D;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                              (void*)(argumentOrIndex6));
            if (Level24_7EF38Field(private18, int*, 0x70) < 0) {
                goto block_537;
            }
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x4FU;
            argumentOrAddress4 = owner19;
            argumentOrField5 = 3;
            goto block_539;
        case 0x4F:
            if (Level24_7EF38ReadSelectedFrameScalar((void*)(owner19)) < 0x13) {
                goto block_311;
            }
            captured_a0_20 = Level24_7EF38Field(private18, int*, 0x88);
            captured_a2_5 = (captured_a0_20 * 0x58) + Level24_7EF38_D_8006C550;
            if (Level24_7EF38Field(captured_a2_5, unsigned char*, 0x45) == 0xF8) {
                goto block_311;
            }
            if (captured_a0_20 < 0) {
                goto block_311;
            }
            Level24_7EF38Field(captured_a2_5, unsigned char*, 0x45) = 0xF8U;
            Level24_7EF38PlayMobySoundEvent(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x88) * 0x58)),
                (int)(0), (int)(0));
        block_311:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_315;
            }
            if (Level24_7EF38Field(private18, int*, 0x70) < 0) {
                goto block_314;
            }
            Level24_7EF38PlaySoundFromGlobalByteTable((void*)(owner19), (int)(6), (int)(0));
            Level24_7EF38MaskLinkedRecordFlagsById((int)(Level24_7EF38Field(private18, int*, 0x70)),
                                                   (int)(0xFC), (int)(0));
            Level24_7EF38Field(private18, int*, 0x8C) = 0x3C;
        block_314:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x50U;
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(2));
        block_315:
            if (Level24_7EF38Field(private18, int*, 0x88) < 0) {
                goto block_542;
            }
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(owner19), (int)(4));
            Level24_7EF38InterpolateMobyVertex((void*)(owner19), (int)(2),
                                               (void*)(&originalFrame.sp58));
            Level24_7EF38InterpolateMobyVertex((void*)(owner19), (int)(3),
                                               (void*)(&originalFrame.sp68));
            Level24_7EF38AddVector((void*)(&originalFrame.sp58), (void*)(&originalFrame.sp58),
                                   (void*)(&originalFrame.sp68));
            Level24_7EF38ShiftVectorRightTowardZero((void*)(&originalFrame.sp58), (int)(1));
            Level24_7EF38RefreshMobySpatialGridAndBasis(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x88) * 0x58)),
                (int)(4));
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x88) * 0x58)),
                (int)(0), (void*)(&originalFrame.sp68));
            Level24_7EF38SubtractVector((void*)(&originalFrame.sp58), (void*)(&originalFrame.sp68),
                                        (void*)(&originalFrame.sp58));
            Level24_7EF38ShiftVectorRightTowardZero((void*)(&originalFrame.sp58), (int)(2));
            captured_a0_21 = owner19 + 0xC;
            Level24_7EF38AddVector((void*)(captured_a0_21), (void*)(captured_a0_21),
                                   (void*)(&originalFrame.sp58));
            return;
        case 0x50:
            if (Level24_7EF38Field(private18, int*, 0x88) < 0) {
                goto block_319;
            }
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(owner19), (int)(4));
            Level24_7EF38InterpolateMobyVertex((void*)(owner19), (int)(2),
                                               (void*)(&originalFrame.sp78));
            Level24_7EF38InterpolateMobyVertex((void*)(owner19), (int)(3),
                                               (void*)(&originalFrame.sp88));
            Level24_7EF38AddVector((void*)(&originalFrame.sp78), (void*)(&originalFrame.sp78),
                                   (void*)(&originalFrame.sp88));
            Level24_7EF38ShiftVectorRightTowardZero((void*)(&originalFrame.sp78), (int)(1));
            Level24_7EF38RefreshMobySpatialGridAndBasis(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x88) * 0x58)),
                (int)(4));
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x88) * 0x58)),
                (int)(0), (void*)(&originalFrame.sp88));
            Level24_7EF38SubtractVector((void*)(&originalFrame.sp78), (void*)(&originalFrame.sp88),
                                        (void*)(&originalFrame.sp78));
            Level24_7EF38ShiftVectorRightTowardZero((void*)(&originalFrame.sp78), (int)(2));
            captured_a0_22 = owner19 + 0xC;
            Level24_7EF38AddVector((void*)(captured_a0_22), (void*)(captured_a0_22),
                                   (void*)(&originalFrame.sp78));
        block_319:
            captured_a0_23 = Level24_7EF38Field(private18, int*, 0x70);
            if (captured_a0_23 < 0) {
                goto block_542;
            }
            if (!(Level24_7EF38QueryShiftedLinkedRecordWordByByteId((int)(captured_a0_23)) & 2)) {
                goto block_542;
            }
            if (Level24_7EF38CountTimerDown((void*)(private18 + 0x8C), (int)(4)) == 0) {
                goto block_542;
            }
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0) =
                Level24_7EF38Field(private18, unsigned char*, 0x25) * 8;
            Level24_7EF38Field(private18, int*, 0x70) = -1;
            Level24_7EF38TransitionCameraModes9And10((int)(1));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0;
            resultOrArithmetic2 = 0x4E;
            goto block_494;
        case 0x4E:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_327;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_326;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_327;
        block_326:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_327:
            Level24_7EF38RefreshMobySpatialGridAndBasis(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(4));
            if (Level24_7EF38Field(private18, int*, 0x88) < 0) {
                goto block_331;
            }
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(0), (void*)(&originalFrame.sp98));
            if ((Level24_7EF38Field(owner19, int*, 0x14) - 0x40) >= originalFrame.spA0) {
                goto block_330;
            }
            Level24_7EF38Field(private18, int*, 0x88) = -1;
        block_330:
            argumentOrAddress4 = (int)&originalFrame.sp98;
            Level24_7EF38CompleteValue(argumentOrAddress4);
            argumentOrField5 = (int)&originalFrame.sp98;
            Level24_7EF38CompleteValue(argumentOrField5);
            savedHeadingFrameOrActor16 = owner19 + 0xC;
            Level24_7EF38SubtractVector((void*)(argumentOrAddress4), (void*)(argumentOrField5),
                                        (void*)(savedHeadingFrameOrActor16));
            Level24_7EF38ShiftVectorRightTowardZero((void*)(&originalFrame.sp98), (int)(2));
            Level24_7EF38AddVector((void*)(savedHeadingFrameOrActor16),
                                   (void*)(savedHeadingFrameOrActor16),
                                   (void*)(&originalFrame.sp98));
            goto block_332;
        block_331:
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(0), (void*)(owner19 + 0xC));
        block_332:
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(1), (void*)(&originalFrame.sp98));
            captured_v0_17 = Level24_7EF38PlanarHeadingLookup(
                (int)(originalFrame.sp98 - Level24_7EF38Field(owner19, int*, 0xC)),
                (int)(originalFrame.sp9C - Level24_7EF38Field(owner19, int*, 0x10)), (int)(0));
            fieldOrAddress3 = Level24_7EF38Field(owner19, unsigned char*, 0x46) - captured_v0_17;
            if (fieldOrAddress3 >= 0) {
                goto block_334;
            }
            fieldOrAddress3 = -fieldOrAddress3;
        block_334:
            if (fieldOrAddress3 >= 0x20) {
                goto block_336;
            }
            Level24_7EF38Field(owner19, unsigned char*, 0x46) = captured_v0_17;
            goto block_337;
        block_336:
            Level24_7EF38TurnMobyTowardHeading((void*)(owner19), (int)(captured_v0_17), (int)(8),
                                               (int)(0), (int)(1), (int)(0));
        block_337:
            resultOrArithmetic2 = Level24_7EF38_D_8006C640;
            resultOrArithmetic2 >>= 2;
            fieldOrAddress3 = resultOrArithmetic2 & 15;
            resultOrArithmetic2 = fieldOrAddress3 < 9;
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            if (resultOrArithmetic2) {
                resultOrArithmetic2 = fieldOrAddress3 - 4;
                goto block_339;
            }
            resultOrArithmetic2 = 16;
            fieldOrAddress3 = resultOrArithmetic2 - fieldOrAddress3;
            resultOrArithmetic2 = fieldOrAddress3 - 4;
        block_339:
            Level24_7EF38Field(owner19, signed char*, 0x44) = resultOrArithmetic2;
            goto block_540;
        case 0x44:
            argumentOrAddress4 = owner19;
            if (enabled22 == 0)
                goto block_342;
            __asm__("" : "=r"(argumentOrAddress4) : "0"(argumentOrAddress4), "i"(5));
            argumentOrField5 = 5;
            goto block_343;
        block_342:
            MATCHING_KEEP_VOLATILE_CLOBBER(enabled22, "$5");
            argumentOrField5 = 0;
        block_343:
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
            if (enabled22 == 0) {
                goto block_540;
            }
            if (Level24_7EF38ResolveMobyYawStep((void*)(owner19), (int)(0x96), (int)(0x12C),
                                                (int)(0x12C), (int)(0)) != 0) {
                goto block_346;
            }
            if (Level24_7EF38ApproximatePlanarDistance(
                    (void*)(owner19 + 0xC),
                    (void*)(Level24_7EF38_D_8006C550 +
                            (Level24_7EF38Field(private18, int*, 0x64) * 0x58) + 0xC)) >= 0x8C0) {
                goto block_541;
            }
        block_346:
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x5C);
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, 0);
            fieldOrAddress3++;
            Level24_7EF38Field(resultOrArithmetic2, int*, 0) = fieldOrAddress3;
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(4));
            resultOrArithmetic2 = 0x45;
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(0));
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            goto block_540;
        case 0x45:
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x64);
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            fieldOrAddress3 = Level24_7EF38_D_8006C550;
            resultOrArithmetic2 *= 8;
            savedIndexFrameOrActor17 = fieldOrAddress3 + resultOrArithmetic2;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
            resultOrArithmetic2 = Level24_7EF38Field(private18, unsigned char*, 0x25);
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0);
            resultOrArithmetic2 *= 2;
            savedIndexOrVector20 = savedIndexFrameOrActor17 + 0xC;
            if (fieldOrAddress3 != resultOrArithmetic2) {
                goto block_355;
            }
            savedHeadingFrameOrActor16 = Level24_7EF38Field(private18, int*, 0x68);
            captured_v0_19 = Level24_7EF38Field(savedHeadingFrameOrActor16, unsigned short*, 0) - 1;
            Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 2) = captured_v0_19;
            if (Level24_7EF38ApproximatePlanarDistance(
                    (void*)(savedIndexOrVector20),
                    (void*)(Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0xC) +
                            ((int)(captured_v0_19 << 0x10) >> 0xC))) >= 0x100) {
                goto block_352;
            }
            if (Level24_7EF38SoundHandleMatchesOwnerInStates1Or2(
                    (void*)(savedIndexFrameOrActor17),
                    (int)(Level24_7EF38Field(private18, short*, 0x26))) == 0) {
                goto block_351;
            }
            Level24_7EF38TransitionSoundHandleTo3Or5(
                (int)(Level24_7EF38Field(private18, short*, 0x26)));
            Level24_7EF38Field(private18, short*, 0x26) = -1;
        block_351:
            captured_v1_44 = Level24_7EF38Field(private18, int*, 0x5C);
            Level24_7EF38Field(private18, signed char*, 2) = 3;
            Level24_7EF38Field(captured_v1_44, int*, 0) += 1;
            goto block_357;
        block_352:
            captured_v0_20 = (Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 2) * 0x10) +
                             Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0xC);
            savedHeadingFrameOrActor16 = Level24_7EF38PlanarHeadingLookup(
                (int)(Level24_7EF38Field(captured_v0_20, int*, 0) -
                      Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0xC)),
                (int)(Level24_7EF38Field(captured_v0_20, int*, 4) -
                      Level24_7EF38Field(savedIndexFrameOrActor17, int*, 0x10)),
                (int)(0));
            if (Level24_7EF38SoundHandleMatchesOwnerInStates1Or2(
                    (void*)(savedIndexFrameOrActor17),
                    (int)(Level24_7EF38Field(private18, short*, 0x26))) != 0) {
                goto block_354;
            }
            Level24_7EF38Field(private18, short*, 0x26) = Level24_7EF38PlayMobySoundEvent(
                (void*)(savedIndexFrameOrActor17), (int)(0), (int)(4));
        block_354:
            /* Original signed16 trig samples times25, arithmetic shift12, SP A8/AC and real zero SP B0. */
            argumentOrAddress4 = savedIndexOrVector20;
            argumentOrIndex6 = savedHeadingFrameOrActor16 * 2;
            fieldOrAddress3 =
                Level24_7EF38Field((int)&Level24_7EF38_D_80065920, short*, argumentOrIndex6);
            argumentOrField5 = argumentOrAddress4;
            resultOrArithmetic2 = (fieldOrAddress3 * 25) >> 12;
            originalFrame.spA8 = resultOrArithmetic2;
            fieldOrAddress3 =
                Level24_7EF38Field((int)&Level24_7EF38_D_800658A0, short*, argumentOrIndex6);
            argumentOrIndex6 = (int)&originalFrame.spA8;
            MATCHING_OBSERVE2_VOLATILE(fieldOrAddress3, argumentOrIndex6);
            *(volatile int*)&originalFrame.spB0 = 0;
            __asm__("" : "=r"(fieldOrAddress3) : "0"(fieldOrAddress3), "m"(originalFrame.spB0));
            resultOrArithmetic2 = (fieldOrAddress3 * 25) >> 12;
            originalFrame.spAC = resultOrArithmetic2;
            Level24_7EF38AddVector((void*)(argumentOrAddress4), (void*)(argumentOrField5),
                                   (void*)(argumentOrIndex6));
            Level24_7EF38Field(savedIndexFrameOrActor17, unsigned char*, 0x44) =
                (unsigned char)(Level24_7EF38Field(savedIndexFrameOrActor17, unsigned char*, 0x44) -
                                1);
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(savedIndexFrameOrActor17),
                                                        (int)(6));
            goto block_357;
        block_355:
            if (Level24_7EF38SoundHandleMatchesOwnerInStates1Or2(
                    (void*)(savedIndexFrameOrActor17),
                    (int)(Level24_7EF38Field(private18, short*, 0x26))) == 0) {
                goto block_357;
            }
            Level24_7EF38TransitionSoundHandleTo3Or5(
                (int)(Level24_7EF38Field(private18, short*, 0x26)));
            Level24_7EF38Field(private18, short*, 0x26) = -1;
        block_357:
            if (enabled22 == 0) {
                goto block_360;
            }
            if (Level24_7EF38ApproximatePlanarDistance(
                    (void*)(owner19 + 0xC),
                    (void*)(Level24_7EF38_D_8006C550 +
                            (Level24_7EF38Field(private18, int*, 0x64) * 0x58) + 0xC)) < 0x8C1) {
                goto block_360;
            }
            Level24_7EF38ResolveMobyYawStep((void*)(owner19), (int)(0x19), (int)(0x12C),
                                            (int)(0x14), (int)(0x21));
            goto block_541;
        block_360:
            if ((Level24_7EF38Field(private18, unsigned char*, 0x25) * 2) >=
                Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0)) {
                goto block_540;
            }
            argumentOrAddress4 = owner19 + 0x48;
            argumentOrField5 = 1;
            Level24_7EF38CompleteValue(argumentOrField5);
            argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
            Level24_7EF38CompleteValue(argumentOrIndex6);
            resultOrArithmetic2 = 0x47;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                              (void*)(argumentOrIndex6));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 7;
            Level24_7EF38Field(private18, short*, 0x26) =
                (short)(Level24_7EF38Field(owner19, unsigned char*, 0x46) + 0x80);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x46U;
            goto block_539;
        case 0x46:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_367;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_365;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_366;
        block_365:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_366:
        block_367:
            Level24_7EF38TurnMobyTowardHeading((void*)(owner19),
                                               (int)(Level24_7EF38Field(private18, short*, 0x26)),
                                               (int)(6), (int)(2), (int)(1), (int)(0));
            return;
        case 0x41:
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x64);
            if (resultOrArithmetic2 >= 0) {
                resultOrArithmetic2 = 2;
                goto block_370;
            }
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x5C);
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, 0);
            fieldOrAddress3++;
            Level24_7EF38Field(resultOrArithmetic2, int*, 0) = fieldOrAddress3;
            resultOrArithmetic2 = 4;
        block_370:
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x3EU;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x4C);
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, short*, 0);
            resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, 0xC);
            __asm__(""
                    : "=r"(argumentOrField5)
                    : "0"(argumentOrField5), "r"(resultOrArithmetic2), "i"(0));
            argumentOrAddress4 = owner19 + 0xC;
            goto block_530;
        case 0x42:
            if (Level24_7EF38_D_8006E044 != 9) {
                goto block_373;
            }
            if (!(Level24_7EF38_D_8006E048 & 1)) {
                goto block_542;
            }
        block_373:
            resultOrArithmetic2 = 0x3E;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x40);
            argumentOrField5 = Level24_7EF38Field(private18, int*, 0x2C);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x50);
            resultOrArithmetic2 = 3;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = -1;
            Level24_7EF38Field(private18, int*, 0x3C) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x38) = argumentOrAddress4;
            argumentOrAddress4 = owner19 + 0xC;
            Level24_7EF38Field(private18, int*, 0x28) = argumentOrField5;
            goto descriptorEntryWithStoredPointer;
        case 0x43:
            resultOrArithmetic2 = 0x3E;
            goto block_528;
        case 0x47:
            argumentOrAddress4 = owner19 + 0xC;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x7C);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x64);
            savedIndexFrameOrActor17 = Level24_7EF38_D_8006C550;
            savedHeadingFrameOrActor16 = Level24_7EF38Field(private18, int*, 0x68);
            argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, int*, 0xC);
            resultOrArithmetic2 = fieldOrAddress3 * 11;
            resultOrArithmetic2 *= 8;
            savedIndexFrameOrActor17 += resultOrArithmetic2;
            Level24_7EF38CopyVector((void*)(argumentOrAddress4), (void*)(argumentOrField5));
            argumentOrIndex6 = 0;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x4C);
            argumentOrAddress4 = Level24_7EF38Field(owner19, int*, 0xC);
            argumentOrField5 = Level24_7EF38Field(owner19, int*, 0x10);
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, short*, 0);
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0xC);
            resultOrArithmetic2 *= 16;
            resultOrArithmetic2 += fieldOrAddress3;
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, -0x10);
            resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, -0xC);
            argumentOrAddress4 = fieldOrAddress3 - argumentOrAddress4;
            resultOrArithmetic2 = Level24_7EF38PlanarHeadingLookup(
                (int)(argumentOrAddress4), (int)(resultOrArithmetic2 - argumentOrField5),
                (int)(argumentOrIndex6));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            __asm__(""
                    : "=r"(savedIndexFrameOrActor17)
                    : "0"(savedIndexFrameOrActor17),
                      "m"(Level24_7EF38Field(private18, short*, 0x26)));
            resultOrArithmetic2 =
                Level24_7EF38Field(savedHeadingFrameOrActor16, unsigned short*, 0);
            argumentOrAddress4 = savedIndexFrameOrActor17;
            resultOrArithmetic2--;
            Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 2) = resultOrArithmetic2;
            __asm__ volatile("" ::"m"(Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 2))
                             : "memory");
            resultOrArithmetic2 = Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 0);
            fieldOrAddress3 = Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0xC);
            resultOrArithmetic2 *= 16;
            resultOrArithmetic2 += fieldOrAddress3;
            resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, -0x10);
            argumentOrField5 = 6;
            Level24_7EF38Field(argumentOrAddress4, int*, 0xC) = resultOrArithmetic2;
            resultOrArithmetic2 = Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 0);
            fieldOrAddress3 = Level24_7EF38Field(savedHeadingFrameOrActor16, int*, 0xC);
            resultOrArithmetic2 *= 16;
            resultOrArithmetic2 += fieldOrAddress3;
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, -0xC);
            resultOrArithmetic2 = 0x60;
            Level24_7EF38Field(argumentOrAddress4, signed char*, 0x44) = resultOrArithmetic2;
            Level24_7EF38Field(argumentOrAddress4, int*, 0x10) = fieldOrAddress3;
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(argumentOrAddress4),
                                                        (int)(argumentOrField5));
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(owner19), (int)(6));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 1;
            resultOrArithmetic2 = 3;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x46;
            goto block_494;
        case 0x4D:
            if (Level24_7EF38_D_8006E044 != 9) {
                goto block_378;
            }
            if (!(Level24_7EF38_D_8006E048 & 1)) {
                goto block_542;
            }
        block_378:
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0) =
                Level24_7EF38Field(private18, unsigned char*, 0x25) * 2;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x74);
            argumentOrField5 = 4;
            goto block_533;
    }
block_379:
    /* The original captured private24 value selected mode1; helper calls may subsequently change memory. */
    if (Level24_7EF38_D_8006C640 != 0) {
        goto block_388;
    }
    if (Level24_7EF38_D_8006C7B4 & 1) {
        goto block_382;
    }
    if (!(Level24_7EF38Field((int)&Level24_7EF38_D_80070300 + Level24_7EF38_D_8006C58C,
                             unsigned char*, 0) &
          1)) {
        goto block_388;
    }
block_382:
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x64);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x47;
        goto block_387;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x74);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x4D;
        goto block_387;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x44);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x43;
        goto block_387;
    }
    resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x40);
    if (resultOrArithmetic2 >= 0) {
        resultOrArithmetic2 = 0x42;
        goto block_387;
    }
    resultOrArithmetic2 = 0x41;
block_387:
    Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
    __asm__("" ::"m"(Level24_7EF38Field(owner19, unsigned char*, 0x48)));
    Level24_7EF38RegisterTrackedValue((void*)(owner19 + 0x48), (int)(1),
                                      (void*)((int)&Level24_7EF38_D_8006C7F8));
block_388:
    captured_v1_46 = Level24_7EF38Field(owner19, unsigned char*, 0x48);
    if (captured_v1_46 >= 0x61U) {
        goto block_542;
    }
    switch (captured_v1_46) {
        default:
            goto block_542;
        case 0x60:
        sharedState60:
            if (Level24_7EF38_D_8006E344 == 1) {
                goto block_542;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19),
                                              (int)(Level24_7EF38Field(private18, short*, 0x62)));
            Level24_7EF38Field(owner19, unsigned char*, 0x48) =
                (unsigned char)Level24_7EF38Field(private18, unsigned short*, 0x60);
            Level24_7EF38Field(owner19, unsigned char*, 0x49) =
                (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) & 0xFD);
            return;
        case 0x0:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_397;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_395;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_396;
        block_395:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_396:
        block_397:
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) != 0) {
                goto block_520;
            }
            if (Level24_7EF38Field(private18, int*, 0x28) == 0) {
                goto block_542;
            }
            captured_a0_24 =
                (Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550;
            captured_v1_47 = Level24_7EF38Field(captured_a0_24, short*, 0x36);
            if (captured_v1_47 == 0xC) {
                goto block_401;
            }
            if (captured_v1_47 != 0x229) {
                goto block_402;
            }
        block_401:
            if (Level24_7EF38Field(captured_a0_24, unsigned char*, 0x48) == 0xA) {
                goto block_404;
            }
        block_402:
            captured_a0_25 =
                (Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550;
            if (Level24_7EF38Field(captured_a0_25, short*, 0x36) != 0x11) {
                goto block_542;
            }
            if (Level24_7EF38Field(captured_a0_25, unsigned char*, 0x48) != 0x5B) {
                goto block_542;
            }
        block_404:
            resultOrArithmetic2 = Level24_7EF38Field(private18, short*, 0x26);
            Level24_7EF38Field(private18, signed char*, 5) = 0;
            fieldOrAddress3 = resultOrArithmetic2;
            if (resultOrArithmetic2 == 0)
                goto block_406;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x28);
            Level24_7EF38Field(resultOrArithmetic2, short*, 2) = fieldOrAddress3;
            Level24_7EF38Field(private18, short*, 0x26) = 0;
        block_406:
            argumentOrAddress4 = owner19;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x4C);
            argumentOrField5 = 5;
            Level24_7EF38Field(resultOrArithmetic2, short*, 2) = 0;
            resultOrArithmetic2 = 6;
            goto block_494;
        case 0x6:
            captured_v1_48 =
                (Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550;
            captured_a0_26 = Level24_7EF38Field(captured_v1_48, short*, 0x36);
            if (captured_a0_26 == 0xC) {
                goto block_409;
            }
            if (captured_a0_26 != 0x229) {
                goto block_410;
            }
        block_409:
            savedHeadingFrameOrActor16 =
                Level24_7EF38Field(Level24_7EF38Field(captured_v1_48, int*, 0), int*, 4);
            goto block_411;
        block_410:
            savedHeadingFrameOrActor16 =
                Level24_7EF38Field(Level24_7EF38Field(captured_v1_48, int*, 0), int*, 0x18);
        block_411:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_413;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(5));
        block_413:
            if (Level24_7EF38Field(private18, short*, 0x26) <= 0) {
                goto block_415;
            }
            savedHeadingFrameOrActor16 = 0xDC;
            Level24_7EF38CountTimerDown((void*)(private18 + 0x26), (int)(2));
            goto block_425;
        block_415:
            captured_a0_27 = Level24_7EF38Field(private18, int*, 0x28);
            captured_v0_25 = Level24_7EF38Field(captured_a0_27, unsigned short*, 0);
            captured_hi =
                (int)((Level24_7EF38Field(captured_a0_27, short*, 2) + (short)captured_v0_25) -
                      Level24_7EF38Field(savedHeadingFrameOrActor16, short*, 2)) %
                (short)captured_v0_25;
            if (captured_hi >= 2) {
                goto block_417;
            }
            savedHeadingFrameOrActor16 = 0xDC;
            Level24_7EF38Field(private18, short*, 0x26) = 0x78;
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0xA;
            goto block_424;
        block_417:
            savedHeadingFrameOrActor16 = 0x96;
            if (captured_hi < ((int)(captured_v0_25 << 0x10) >> 0x11)) {
                goto block_425;
            }
            captured_a0_28 =
                (Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550;
            captured_v1_49 = Level24_7EF38Field(captured_a0_28, short*, 0x36);
            if (captured_v1_49 == 0xC) {
                goto block_420;
            }
            if (captured_v1_49 != 0x229) {
                goto block_421;
            }
        block_420:
            fieldOrAddress3 = Level24_7EF38Field(captured_a0_28, unsigned char*, 0x48);
            resultOrArithmetic2 = 0xA;
            argumentOrAddress4 = owner19;
            if (fieldOrAddress3 != resultOrArithmetic2) {
                goto block_423;
            }
        block_421:
            captured_a0_29 =
                (Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550;
            if (Level24_7EF38Field(captured_a0_29, short*, 0x36) != 0x11) {
                goto block_427;
            }
            fieldOrAddress3 = Level24_7EF38Field(captured_a0_29, unsigned char*, 0x48);
            argumentOrAddress4 = owner19;
            if (fieldOrAddress3 == 0x5B) {
                goto block_425;
            }
        block_423:
            argumentOrField5 = 0;
            Level24_7EF38Field(private18, short*, 0x26) = 0;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0U;
        block_424:
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
        block_425:
            if (Level24_7EF38Field(
                    ((Level24_7EF38Field(private18, int*, 0x38) * 0x58) + Level24_7EF38_D_8006C550),
                    short*, 0x36) != 0x11) {
                goto block_428;
            }
            savedHeadingFrameOrActor16 = savedHeadingFrameOrActor16 >> 1;
        block_427:
        block_428:
            Level24_7EF38UpdateMobyPathMotion(
                (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x28)), (int)(0x200),
                (int)(savedHeadingFrameOrActor16), (int)(0x12C), (int)(6), (int)(0x20), (int)(0));
            goto block_541;
        case 0x3C:
            captured_a0_30 = Level24_7EF38Field(private18, int*, 0x64);
            if (captured_a0_30 >= 0) {
                goto block_436;
            }
            captured_v1_50 = Level24_7EF38Field(private18, int*, 0x44);
            if (captured_v1_50 < 0) {
                goto block_432;
            }
            if (!(Level24_7EF38Field(((captured_v1_50 * 0x58) + Level24_7EF38_D_8006C550),
                                     unsigned char*, 0x48) &
                  0x80)) {
                goto block_436;
            }
        block_432:
            captured_v1_51 = Level24_7EF38Field(private18, int*, 0x40);
            if (captured_v1_51 < 0) {
                goto block_434;
            }
            if (!(Level24_7EF38Field(((captured_v1_51 * 0x58) + Level24_7EF38_D_8006C550),
                                     unsigned char*, 0x48) &
                  0x80)) {
                goto block_436;
            }
        block_434:
            if (captured_a0_30 != -1) {
                goto block_437;
            }
            captured_v0_26 = Level24_7EF38Field(private18, int*, 0x5C);
            Level24_7EF38Field(captured_v0_26, int*, 0) += 1;
            Level24_7EF38Field(private18, int*, 0x64) = -2;
        block_436:
        block_437:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(5));
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x3DU;
        block_438:
            Level24_7EF38Field(private18, signed char*, 2) = 1;
            return;
        case 0x3D:
            if (Level24_7EF38Field(private18, int*, 0x28) != 0) {
                goto block_441;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            resultOrArithmetic2 = 2;
            goto block_446;
        block_441:
            if (enabled22 != 0) {
                goto block_445;
            }
            Level24_7EF38CompleteValue(enabled22);
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) == 0) {
                goto block_444;
            }
            Level24_7EF38StartDialogue((void*)(owner19), (int)(0), (int)(6));
            Level24_7EF38Field(private18, unsigned short*, 0x60) =
                (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
            Level24_7EF38Field(private18, short*, 0x62) =
                (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x60U;
            Level24_7EF38Field(owner19, unsigned char*, 0x49) =
                (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) | 2);
        block_444:
            resultOrArithmetic2 = 0;
            goto block_446;
        block_445:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(5));
            resultOrArithmetic2 = Level24_7EF38UpdateMobyPathMotion(
                (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x28)), (int)(0x200),
                (int)(0x96), (int)(0x12C), (int)(3), (int)(0x18), (int)(6));
        block_446:
            if (!(resultOrArithmetic2 & 1)) {
                goto block_540;
            }
            if (Level24_7EF38TestSubdividedSegmentPath(
                    (void*)(owner19 + 0xC),
                    (void*)(Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), int*,
                                               0xC)),
                    (int)(0)) == 0) {
                goto block_540;
            }
            resultOrArithmetic2 = 0x3E;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x2000;
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(1));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            goto block_540;
        case 0x3E:
            savedIndexFrameOrActor17 = 6;
            if (Level24_7EF38Field(private18, short*, 0x26) == 0x2000) {
                goto block_451;
            }
            savedIndexFrameOrActor17 = 2;
        block_451:
            argumentOrAddress4 = owner19;
            if (enabled22 != 0) {
                goto block_456;
            }
            Level24_7EF38CompleteValue(enabled22);
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(0));
            argumentOrAddress4 = 0;
            if (Level24_7EF38Field(private18, short*, 0x26) != 0x2000) {
                goto block_460;
            }
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(owner19), (int)(0)) == 0) {
                goto block_455;
            }
            Level24_7EF38StartDialogue((void*)(owner19), (int)(0), (int)(6));
            Level24_7EF38Field(private18, unsigned short*, 0x60) =
                (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
            Level24_7EF38Field(private18, short*, 0x62) =
                (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x60U;
            Level24_7EF38Field(owner19, unsigned char*, 0x49) =
                (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) | 2);
        block_455:
            argumentOrAddress4 = 0;
            goto block_460;
        block_456:
            if (Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), short*, 2) < 0) {
                goto block_459;
            }
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(5));
            argumentOrAddress4 = Level24_7EF38UpdateMobyPathMotion(
                (void*)(owner19), (void*)(Level24_7EF38Field(private18, int*, 0x4C)), (int)(0x200),
                (int)(0x96), (int)(0x12C), (int)(3), (int)(0x18), (int)(savedIndexFrameOrActor17));
            if (!(argumentOrAddress4 & 2)) {
                goto block_472;
            }
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), short*, 2) = -1;
            goto block_460;
        block_459:
            argumentOrAddress4 = 2;
        block_460:
            resultOrArithmetic2 = argumentOrAddress4 & 2;
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            if (!resultOrArithmetic2) {
                goto block_472;
            }
            if (Level24_7EF38Field(private18, short*, 0x26) != 0x2000) {
                goto block_472;
            }
            Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x4C), short*, 2) = 0;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x40);
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x38);
            if (fieldOrAddress3 != resultOrArithmetic2) {
                resultOrArithmetic2 = 0x41;
                goto block_464;
            }
            resultOrArithmetic2 = 0x42;
        block_464:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            __asm__("" ::"m"(Level24_7EF38Field(owner19, unsigned char*, 0x48)));
            Level24_7EF38RegisterTrackedValue((void*)(owner19 + 0x48), (int)(1),
                                              (void*)((int)&Level24_7EF38_D_8006C7F8));
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x40);
            if (fieldOrAddress3 < 0)
                goto block_468;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x38);
            if (fieldOrAddress3 == resultOrArithmetic2)
                goto block_467;
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x50);
            argumentOrField5 = Level24_7EF38Field(private18, int*, 0x2C);
            resultOrArithmetic2 = 3;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            resultOrArithmetic2 = -1;
            Level24_7EF38Field(private18, int*, 0x3C) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x28) = 0;
            Level24_7EF38Field(private18, int*, 0x38) = fieldOrAddress3;
            Level24_7EF38Field(private18, int*, 0x4C) = argumentOrAddress4;
            resultOrArithmetic2 = Level24_7EF38Field(argumentOrField5, int*, 0xC);
            argumentOrIndex6 = 0;
            argumentOrField7 = Level24_7EF38Field(resultOrArithmetic2, int*, 0x10);
            argumentOrAddress4 = Level24_7EF38Field(resultOrArithmetic2, int*, 0);
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, 0x14);
            argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, int*, 4);
            argumentOrAddress4 = argumentOrField7 - argumentOrAddress4;
            resultOrArithmetic2 = Level24_7EF38PlanarHeadingLookup(
                (int)(argumentOrAddress4), (int)(fieldOrAddress3 - argumentOrField5),
                (int)(argumentOrIndex6));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0xB;
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            resultOrArithmetic2 = 5;
            Level24_7EF38Field(private18, unsigned char*, 0x24) = 0;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            goto block_539;
        block_467:
        block_468:
            resultOrArithmetic2 = 0x3F;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x64);
            if (resultOrArithmetic2 < 0)
                goto block_470;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
            resultOrArithmetic2 = 2;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            __asm__("" : "=r"(fieldOrAddress3) : "0"(fieldOrAddress3), "i"(2));
            goto block_471;
        block_470:
            resultOrArithmetic2 = 2;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
            __asm__("" : "=r"(fieldOrAddress3) : "0"(fieldOrAddress3), "r"(resultOrArithmetic2));
            resultOrArithmetic2 = 4;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            __asm__("" : "=r"(fieldOrAddress3) : "0"(fieldOrAddress3), "i"(4));
        block_471:
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, int*, 0);
            resultOrArithmetic2++;
            Level24_7EF38Field(fieldOrAddress3, int*, 0) = resultOrArithmetic2;
            goto block_538;
        block_472:
            if (enabled22 == 0) {
                goto block_480;
            }
            if (Level24_7EF38Field(private18, short*, 0x26) != 0x2000) {
                goto block_481;
            }
            captured_v1_53 = Level24_7EF38Field(private18, int*, 0x4C);
            captured_v0_28 = Level24_7EF38Field(captured_v1_53, short*, 2);
            if (captured_v0_28 < 0) {
                goto block_480;
            }
            captured_v0_29 =
                (captured_v0_28 * 0x10) + Level24_7EF38Field(captured_v1_53, int*, 0xC);
            if (Level24_7EF38AbsoluteByteAngleDelta(
                    (int)(Level24_7EF38Field(owner19, unsigned char*, 0x46)),
                    (int)(Level24_7EF38PlanarHeadingLookup(
                        (int)(Level24_7EF38Field(captured_v0_29, int*, 0) -
                              Level24_7EF38Field(owner19, int*, 0xC)),
                        (int)(Level24_7EF38Field(captured_v0_29, int*, 4) -
                              Level24_7EF38Field(owner19, int*, 0x10)),
                        (int)(0)))) >= 0x18) {
                goto block_480;
            }
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x4C);
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, short*, 2);
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0xC);
            resultOrArithmetic2 *= 16;
            argumentOrField5 = resultOrArithmetic2 + fieldOrAddress3;
            resultOrArithmetic2 = Level24_7EF38Field(owner19, int*, 0x14);
            fieldOrAddress3 = Level24_7EF38Field(argumentOrField5, int*, 8);
            resultOrArithmetic2 -= fieldOrAddress3;
            if (resultOrArithmetic2 >= 0) {
                goto block_478;
            }
            resultOrArithmetic2 = -resultOrArithmetic2;
        block_478:
            if (resultOrArithmetic2 < 0x101) {
                goto block_480;
            }
            resultOrArithmetic2 = Level24_7EF38ComputeArcVerticalVelocity(
                (void*)(owner19 + 0xC), (void*)(argumentOrField5), (int)(0x96), (int)(-0xC),
                (void*)(&originalFrame.spB8));
            __asm__("" ::"m"(originalFrame.spB8));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            goto block_540;
        block_480:
            if (Level24_7EF38Field(private18, short*, 0x26) == 0x2000) {
                goto block_541;
            }
        block_481:
            Level24_7EF38Field(owner19, int*, 0x14) =
                (int)(Level24_7EF38Field(owner19, int*, 0x14) +
                      Level24_7EF38Field(private18, short*, 0x26));
            captured_v0_30 = Level24_7EF38ProbeGroundFromRaisedMoby((void*)(owner19));
            if (captured_v0_30 < Level24_7EF38Field(owner19, int*, 0x14)) {
                goto block_483;
            }
            Level24_7EF38Field(owner19, int*, 0x14) = captured_v0_30;
            resultOrArithmetic2 = 0x2000;
            goto block_484;
        block_483:
            resultOrArithmetic2 = (unsigned short)Level24_7EF38Field(private18, short*, 0x26) - 0xC;
        block_484:
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(1));
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            goto block_540;
        case 0x3F:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_489;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_488;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_489;
        block_488:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_489:
            captured_v1_55 = Level24_7EF38Field(private18, int*, 0x64);
            if (captured_v1_55 < 0) {
                goto block_495;
            }
            captured_v1_56 = Level24_7EF38_D_8006C550 + (captured_v1_55 * 0x58);
            captured_a3_7 = Level24_7EF38Field(captured_v1_56, int*, 0xC);
            resultOrArithmetic2 = Level24_7EF38PlanarHeadingLookup(
                (int)(captured_a3_7 - Level24_7EF38Field(owner19, int*, 0xC)),
                (int)(Level24_7EF38Field(captured_v1_56, int*, 0x10) -
                      Level24_7EF38Field(owner19, int*, 0x10)),
                (int)(0));
            argumentOrAddress4 = owner19;
            resultOrArithmetic2 = resultOrArithmetic2 + 0xFE;
        block_491:
            resultOrArithmetic2 = Level24_7EF38TurnMobyTowardHeading(
                (void*)(argumentOrAddress4), (int)(resultOrArithmetic2 & 0xFF), (int)(6), (int)(0),
                (int)(1), (int)(0));
            argumentOrAddress4 = owner19;
            if (resultOrArithmetic2 == 0)
                goto animationWithPreparedOwner;
            argumentOrField5 = 5;
            if (Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0) <
                (int)Level24_7EF38Field(private18, unsigned char*, 0x25)) {
                goto block_519;
            }
            Level24_7EF38Field(private18, signed char*, 2) = 1;
            resultOrArithmetic2 = 0x44;
        block_494:
            Level24_7EF38Field(argumentOrAddress4, signed char*, 0x48) = resultOrArithmetic2;
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
            return;
        block_495:
            if (Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0) <
                (int)Level24_7EF38Field(private18, unsigned char*, 0x25)) {
                goto block_497;
            }
        block_496:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x40U;
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            return;
        block_497:
            Level24_7EF38TurnMobyTowardHeading(
                (void*)(owner19),
                (int)((Level24_7EF38Field(private18, short*, 0x26) + 0x80) & 0xFF), (int)(4),
                (int)(0), (int)(1), (int)(0));
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(1));
            goto block_519;
        case 0x44:
            argumentOrAddress4 = owner19;
            if (enabled22 == 0)
                goto block_501;
            resultOrArithmetic2 = Level24_7EF38Field(private18, unsigned char*, 0x25);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
            resultOrArithmetic2 *= 2;
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0);
            resultOrArithmetic2--;
            argumentOrField5 = 0;
            if (fieldOrAddress3 != resultOrArithmetic2)
                goto block_502;
            __asm__("" : "=r"(owner19) : "0"(owner19), "i"(5));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 5;
            goto block_502;
        block_501:
            MATCHING_KEEP_VOLATILE_CLOBBER(enabled22, "$5");
            argumentOrField5 = 0;
        block_502:
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
            if (enabled22 == 0) {
                goto block_540;
            }
            __asm__ volatile("" : "=r"(owner19) : "0"(owner19), "r"(enabled22));
            resultOrArithmetic2 = Level24_7EF38Field(private18, unsigned char*, 0x25);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
            resultOrArithmetic2 *= 2;
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0);
            resultOrArithmetic2--;
            argumentOrAddress4 = owner19;
            if (fieldOrAddress3 != resultOrArithmetic2)
                goto updateWithPreparedOwner;
            if (Level24_7EF38ResolveMobyYawStep((void*)(argumentOrAddress4), (int)(0x96),
                                                (int)(0x12C), (int)(0x1F4), (int)(2)) != 0) {
                goto block_506;
            }
            if (Level24_7EF38ApproximatePlanarDistance(
                    (void*)(owner19 + 0xC),
                    (void*)(Level24_7EF38_D_8006C550 +
                            (Level24_7EF38Field(private18, int*, 0x64) * 0x58) + 0xC)) >= 0x8C0) {
                goto block_541;
            }
        block_506:
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x5C);
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, 0);
            fieldOrAddress3++;
            Level24_7EF38Field(resultOrArithmetic2, int*, 0) = fieldOrAddress3;
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(4));
            resultOrArithmetic2 = 0x45;
            __asm__("" : "=r"(resultOrArithmetic2) : "0"(resultOrArithmetic2), "i"(1));
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            goto block_540;
        case 0x45:
            if (enabled22 == 0) {
                goto block_510;
            }
            if (Level24_7EF38ApproximatePlanarDistance(
                    (void*)(owner19 + 0xC),
                    (void*)(Level24_7EF38_D_8006C550 +
                            (Level24_7EF38Field(private18, int*, 0x64) * 0x58) + 0xC)) < 0x8C1) {
                goto block_510;
            }
            Level24_7EF38ResolveMobyYawStep((void*)(owner19), (int)(0x19), (int)(0x12C),
                                            (int)(0x1F4), (int)(2));
            goto block_541;
        block_510:
            if ((Level24_7EF38Field(private18, unsigned char*, 0x25) * 2) >=
                Level24_7EF38Field(Level24_7EF38Field(private18, int*, 0x5C), int*, 0)) {
                goto block_540;
            }
            argumentOrAddress4 = owner19 + 0x48;
            argumentOrField5 = 1;
            Level24_7EF38CompleteValue(argumentOrField5);
            argumentOrIndex6 = (int)&Level24_7EF38_D_8006C7F8;
            Level24_7EF38CompleteValue(argumentOrIndex6);
            resultOrArithmetic2 = 0x47;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            Level24_7EF38RegisterTrackedValue((void*)(argumentOrAddress4), (int)(argumentOrField5),
                                              (void*)(argumentOrIndex6));
            Level24_7EF38Field(private18, short*, 0x26) =
                (short)(Level24_7EF38Field(owner19, unsigned char*, 0x46) + 0x80);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x46U;
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, signed char*, 2) = 3;
            goto block_540;
        case 0x46:
            if (Level24_7EF38_D_8006C770 == 0) {
                goto block_517;
            }
            if (Level24_7EF38Field(private18, short*, 0x86) != 0) {
                goto block_515;
            }
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(1));
            Level24_7EF38Field(private18, short*, 0x86) =
                Level24_7EF38RandBetween((int)(3), (int)(8));
            goto block_516;
        block_515:
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            Level24_7EF38Field(private18, short*, 0x86) =
                (short)((unsigned short)Level24_7EF38Field(private18, short*, 0x86) - 1);
        block_516:
        block_517:
            argumentOrAddress4 = owner19;
            argumentOrIndex6 = 6;
            argumentOrField7 = 2;
            argumentOrField5 = Level24_7EF38Field(private18, short*, 0x26);
            if (Level24_7EF38TurnMobyTowardHeading(
                    (void*)(argumentOrAddress4), (int)(argumentOrField5), (int)(argumentOrIndex6),
                    (int)(argumentOrField7), (int)(1), (int)(0)) == 0) {
                goto block_542;
            }
        block_518:
        block_519:
            argumentOrAddress4 = owner19;
        animationWithPreparedOwner:
            /* Original3300 reaches JAL37BBC after its A0 setup; other entries include the real owner copy. */
            if (Level24_7EF38UpdateMobyInteractionGate((void*)(argumentOrAddress4), (int)(0)) ==
                0) {
                goto block_542;
            }
        block_520:
            Level24_7EF38StartDialogue((void*)(owner19), (int)(0), (int)(6));
            Level24_7EF38Field(private18, unsigned short*, 0x60) =
                (unsigned short)Level24_7EF38Field(owner19, unsigned char*, 0x48);
            Level24_7EF38Field(private18, short*, 0x62) =
                (short)Level24_7EF38Field(owner19, unsigned char*, 0x3D);
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x60U;
            Level24_7EF38Field(owner19, unsigned char*, 0x49) =
                (unsigned char)(Level24_7EF38Field(owner19, unsigned char*, 0x49) | 2);
            return;
        case 0x41:
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x64);
            if (resultOrArithmetic2 >= 0) {
                resultOrArithmetic2 = 2;
                goto block_523;
            }
            resultOrArithmetic2 = 4;
        block_523:
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x3EU;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x4C);
            Level24_7EF38CompleteValue(resultOrArithmetic2);
            argumentOrField5 = Level24_7EF38Field(resultOrArithmetic2, short*, 0);
            resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, 0xC);
            __asm__(""
                    : "=r"(argumentOrField5)
                    : "0"(argumentOrField5), "r"(resultOrArithmetic2), "i"(1));
            argumentOrAddress4 = owner19 + 0xC;
            goto block_530;
        case 0x42:
            if (Level24_7EF38_D_8006E044 != 9) {
                goto block_526;
            }
            if (!(Level24_7EF38_D_8006E048 & 1)) {
                goto block_542;
            }
        block_526:
            resultOrArithmetic2 = 3;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            Level24_7EF38Field(private18, unsigned char*, 0x24) = 0;
            resultOrArithmetic2 = 0x3E;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x40);
            argumentOrField5 = Level24_7EF38Field(private18, int*, 0x2C);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x50);
            resultOrArithmetic2 = -1;
            Level24_7EF38Field(private18, int*, 0x3C) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x38) = argumentOrAddress4;
            argumentOrAddress4 = owner19 + 0xC;
            Level24_7EF38Field(private18, int*, 0x28) = argumentOrField5;
            goto descriptorEntryWithVector;
        case 0x43:
            resultOrArithmetic2 = 0x3E;
            Level24_7EF38Field(private18, unsigned char*, 0x24) = 0U;
        block_528:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x44);
            argumentOrField5 = Level24_7EF38Field(private18, int*, 0x48);
            argumentOrIndex6 = Level24_7EF38Field(private18, int*, 0x30);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x54);
            resultOrArithmetic2 = -1;
            Level24_7EF38Field(private18, int*, 0x40) = resultOrArithmetic2;
            Level24_7EF38Field(private18, int*, 0x38) = argumentOrAddress4;
            argumentOrAddress4 = owner19 + 0xC;
            Level24_7EF38Field(private18, int*, 0x3C) = argumentOrField5;
            Level24_7EF38Field(private18, int*, 0x28) = argumentOrIndex6;
        descriptorEntryWithStoredPointer:
            /* Zero-CPU source entries coincide at original native3548. Every incoming old A5 and descriptor V1 is initialized. */
            __asm__ volatile(""
                             : "=r"(fieldOrAddress3)
                             : "0"(fieldOrAddress3), "r"(argumentOrField5));
        descriptorEntryWithVector:
            /* Observe the actual next vector destination; no arbitrary tag or extra instruction. */
            __asm__ volatile(""
                             : "=r"(fieldOrAddress3)
                             : "0"(fieldOrAddress3), "r"(argumentOrAddress4));
        block_529:
            Level24_7EF38CompleteValue(fieldOrAddress3);
            Level24_7EF38Field(private18, int*, 0x4C) = fieldOrAddress3;
            argumentOrField5 = Level24_7EF38Field(fieldOrAddress3, short*, 0);
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, int*, 0xC);
        block_530:
            argumentOrField5 *= 16;
            argumentOrField5 -= 16;
            Level24_7EF38CopyVector((void*)(argumentOrAddress4),
                                    (void*)(resultOrArithmetic2 + argumentOrField5));
            captured_v1_57 = Level24_7EF38Field(private18, int*, 0x4C);
            captured_v0_33 = (Level24_7EF38Field(captured_v1_57, short*, 0) * 0x10) +
                             Level24_7EF38Field(captured_v1_57, int*, 0xC);
            captured_a3_8 = Level24_7EF38Field(captured_v0_33, int*, -0x10);
            Level24_7EF38Field(owner19, unsigned char*, 0x46) = Level24_7EF38PlanarHeadingLookup(
                (int)(captured_a3_8 - Level24_7EF38Field(captured_v0_33, int*, -0x20)),
                (int)(Level24_7EF38Field(captured_v0_33, int*, -0xC) -
                      Level24_7EF38Field(captured_v0_33, int*, -0x1C)),
                (int)(0));
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(owner19), (int)(6));
            captured_v1_58 = Level24_7EF38Field(private18, int*, 0x4C);
            Level24_7EF38Field(captured_v1_58, short*, 2) =
                (short)((unsigned short)Level24_7EF38Field(captured_v1_58, short*, 0) - 1);
            Level24_7EF38RequestMobyAnimation((void*)(owner19), (int)(0));
            return;
        case 0x47:
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x7C);
            resultOrArithmetic2 = 3;
            Level24_7EF38Field(private18, signed char*, 2) = resultOrArithmetic2;
            argumentOrField5 = Level24_7EF38Field(fieldOrAddress3, int*, 0xC);
            Level24_7EF38CopyVector((void*)(owner19 + 0xC), (void*)(argumentOrField5));
            argumentOrIndex6 = 0;
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x4C);
            argumentOrAddress4 = Level24_7EF38Field(owner19, int*, 0xC);
            argumentOrField5 = Level24_7EF38Field(owner19, int*, 0x10);
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, short*, 0);
            fieldOrAddress3 = Level24_7EF38Field(fieldOrAddress3, int*, 0xC);
            resultOrArithmetic2 *= 16;
            resultOrArithmetic2 += fieldOrAddress3;
            fieldOrAddress3 = Level24_7EF38Field(resultOrArithmetic2, int*, -0x10);
            resultOrArithmetic2 = Level24_7EF38Field(resultOrArithmetic2, int*, -0xC);
            argumentOrAddress4 = fieldOrAddress3 - argumentOrAddress4;
            resultOrArithmetic2 = Level24_7EF38PlanarHeadingLookup(
                (int)(argumentOrAddress4), (int)(resultOrArithmetic2 - argumentOrField5),
                (int)(argumentOrIndex6));
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0;
            Level24_7EF38CompleteValue(argumentOrField5);
            Level24_7EF38Field(private18, short*, 0x26) = resultOrArithmetic2;
            resultOrArithmetic2 = 0x46;
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = resultOrArithmetic2;
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(owner19), (int)(6));
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x4C);
            resultOrArithmetic2 = Level24_7EF38Field(fieldOrAddress3, unsigned short*, 0);
            resultOrArithmetic2--;
            Level24_7EF38Field(fieldOrAddress3, short*, 2) = resultOrArithmetic2;
            return;
        case 0x4D:
            resultOrArithmetic2 = Level24_7EF38Field(private18, unsigned char*, 0x25);
            fieldOrAddress3 = Level24_7EF38Field(private18, int*, 0x5C);
            resultOrArithmetic2 *= 2;
            Level24_7EF38Field(fieldOrAddress3, int*, 0) = resultOrArithmetic2;
            resultOrArithmetic2 = Level24_7EF38Field(private18, int*, 0x74);
            argumentOrField5 = 4;
            Level24_7EF38Field(private18, unsigned char*, 0x24) = 0;
        block_533:
            argumentOrAddress4 = resultOrArithmetic2 * 11;
            resultOrArithmetic2 = Level24_7EF38_D_8006C550;
            argumentOrAddress4 *= 8;
            Level24_7EF38RefreshMobySpatialGridAndBasis(
                (void*)(resultOrArithmetic2 + argumentOrAddress4), (int)(argumentOrField5));
            Level24_7EF38InterpolateMobyVertex(
                (void*)(Level24_7EF38_D_8006C550 +
                        (Level24_7EF38Field(private18, int*, 0x74) * 0x58)),
                (int)(0), (void*)(owner19 + 0xC));
            captured_a0_31 = Level24_7EF38Field(private18, int*, 0x70);
            if (captured_a0_31 < 0) {
                goto block_535;
            }
            Level24_7EF38MaskLinkedRecordFlagsById((int)(captured_a0_31), (int)(0xFC), (int)(0));
            Level24_7EF38WriteMatchingLinkedSelectors(
                (int)(Level24_7EF38Field(private18, int*, 0x70)), (int)(0x1C), (int)(0));
            Level24_7EF38Field(private18, int*, 0x70) = -1;
        block_535:
            argumentOrAddress4 = Level24_7EF38Field(private18, int*, 0x88);
            if (argumentOrAddress4 < 0) {
                goto block_537;
            }
            Level24_7EF38Field(((argumentOrAddress4 * 0x58) + Level24_7EF38_D_8006C550),
                               unsigned char*, 0x45) = 0xF8;
        block_537:
            Level24_7EF38Field(owner19, unsigned char*, 0x48) = 0x4EU;
        block_538:
            argumentOrAddress4 = owner19;
            argumentOrField5 = 0;
        block_539:
            Level24_7EF38RequestMobyAnimation((void*)(argumentOrAddress4), (int)(argumentOrField5));
        block_540:
        block_541:
            argumentOrAddress4 = owner19;
        updateWithPreparedOwner:
            /* Original3363 reaches JAL55D24 after its A0 setup; other entries include the real owner copy. */
            Level24_7EF38RefreshMobySpatialGridAndBasis((void*)(argumentOrAddress4), (int)(6));
        block_542:
            return;
    }
}
#undef Level24_7EF38Field
#undef Level24_7EF38CompleteValue

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 800828DC..80082BEC, original words are the authority. Rev1 raw13
 * provides the source-local route; helper effects and cadence unresolved. */
extern Moby* D_8006C550;
extern int D_8006C578, D_8006C574;
extern unsigned char DecodedBambooPlayer[] __asm__("D_80070328");
void func_level_24_800828DC(Moby* mobyArgument) {
    register Moby* moby __asm__("$18") = mobyArgument;
    register int* tag __asm__("$17") = moby->mobyTag;
    register int selector __asm__("$3");
    register unsigned int offset __asm__("$2");
    register Moby* pool __asm__("$3");
    register Moby* selected __asm__("$16");
    Vector3D first;
    int pad1;
    Vector3D second;
    int pad2;
    register Vector3D* vector __asm__("$19");
    register int index __asm__("$17");
    register int one __asm__("$20");
    if (!moby->substate)
        moby->substate = 1;
    if (moby->substate == 1) {
        selector = tag[0];
        if (selector >= 0) {
            offset = selector * 11;
            MATCHING_KEEP(offset);
            pool = D_8006C550;
            offset <<= 3;
            selected = (Moby*)((unsigned int)pool + offset);
            if (selected->state == 0 || selected->state == 4 || selected->state == 8 ||
                selected->state == 11) {
                func_8004F178(&selected->position, &moby->position);
                selected->position.z += 1792;
                func_80055D24(selected, 6);
            }
        }
        selector = tag[1];
        if (selector >= 0) {
            register SHORTMATRIX* matrix __asm__("$4") = &moby->rotationMatrix;
            register Vector3D* firstArg __asm__("$5") = &first;
            register Vector3D* output __asm__("$6") = firstArg;
            __asm__(""
                    : "=r"(matrix), "=r"(firstArg), "=r"(output)
                    : "0"(matrix), "1"(firstArg), "2"(output), "r"(selector));
            {
                register int value __asm__("$2") = -800;
                first.x = value;
                MATCHING_BARRIER("memory");
                value = -1500;
                first.y = value;
                MATCHING_BARRIER("memory");
            }
            offset = selector * 11;
            MATCHING_KEEP(offset);
            pool = D_8006C550;
            MATCHING_KEEP(pool);
            offset <<= 3;
            __asm__("" : "=r"(offset) : "0"(offset), "r"(pool));
            first.z = 0;
            MATCHING_BARRIER("memory");
            selected = (Moby*)((unsigned int)pool + offset);
            func_8004ED6C(matrix, firstArg, output);
            func_8004F194(&selected->position, &moby->position, &first);
            selected->angle.yaw = moby->angle.yaw;
        }
        moby->substate = 2;
    } else {
        if (!moby->damageFlags)
            return;
        selector = tag[0];
        if (selector >= 0) {
            offset = selector * 11;
            MATCHING_KEEP(offset);
            pool = D_8006C550;
            offset <<= 3;
            selected = (Moby*)((unsigned int)pool + offset);
            tag = selected->mobyTag;
            if (selected->state < 2 || selected->state == 12) {
                func_8003BABC(selected, 2, 0);
                selected->state = 15;
                tag[3] = 0;
                *(short*)((unsigned char*)tag + 16) = 0;
            }
        }
        index = 0;
        one = 1;
        vector = &second;
        MATCHING_KEEP3(index, one, vector);
        do {
            if (D_8006C578 - D_8006C574 < 21)
                goto cleanup;
            selected = SpawnMoby(8, moby);
            if (selected) {
                selected->size = 44;
                selected->lowDrawDistance = 63;
                selected->updateDistance = 255;
                selected->angle.yaw = DecodedBambooPlayer[14];
                {
                    register int value __asm__("$2");
                    if (index == one)
                        goto middle;
                    if (index < 2) {
                        if (index == 0)
                            goto first_child;
                        goto transform;
                    } else {
                        if (index == 2)
                            goto last_child;
                        goto transform;
                    }
                first_child:
                    selected->animationState.id = one;
                    value = 422;
                    second.x = value;
                    value = 50;
                    second.y = value;
                    value = 384;
                    goto store_height;
                middle:
                    selected->animationState.id = index;
                    value = -140;
                    second.y = value;
                    value = 1024;
                    second.x = 0;
                    goto store_height;
                last_child:
                    selected->animationState.id = index;
                    value = 10;
                    second.x = value;
                    value = -328;
                    second.y = value;
                    value = 512;
                store_height:
                    second.z = value;
                }
            transform:
                func_8004ED6C(&moby->rotationMatrix, vector, vector);
                func_8004F194(&selected->position, &selected->position, vector);
                second.z = 0;
            }
            index++;
        } while (index < 3);
    cleanup:
        func_8003BABC(moby, 0, 0);
        func_8003BA00(moby);
        func_80055B18(moby);
    }
}

extern int D_8006C64C;
void DecodedPlatformActivate(Moby*, void*, int, int, int, int, int, int) __asm__("func_80035A80");
void func_level_24_80082BEC(Moby* moby) {
    void** tag = moby->mobyTag;
    Vector3D delta;
    int state = moby->state;
    switch (state) {
        case 0:
            if (spyro.m_StoodOnMoby == moby)
                moby->state = 1;
            break;
        case 1: {
            Moby** standing = &spyro.m_StoodOnMoby;
            if (*standing == moby) {
                if (!moby->substate) {
                    DecodedPlatformActivate(moby, *tag, 0x200, 0x50, 0, state, 0x20, state);
                    func_8004F1C8(&delta, &moby->position, (Vector3D*)((char*)standing - 0x13C));
                    spyro.unk17a = 0x10000008;
                    func_8004F178((Vector3D*)((char*)standing + 0xE0), &delta);
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk18.yaw = 0;
                    if (D_8006C64C)
                        spyro.superflameTimer = 0;
                    else
                        spyro.unk17a |= 0x10020000;
                } else if (moby->substate == state)
                    moby->substate = 0;
            } else {
                moby->state = 0;
                moby->substate = 0;
            }
        } break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80082D3C.
* AI generated; not human reviewed. All972 original instructions,45 selector
* entries and one zero padding word,1018 owned words, require exact native
* and linked words and every actual transfer/table destination.
* Frame70 saves S0/S1/S2/RA and retains original SP20..5F locals.
* Original physical shared writers remain at368/369,645/647 and734/736.
* Complete record/index/address producers preserve both descriptor paths.
* Signed39/shift6 and signed sample/halfword products remain complete C
* low32 values; zero-vector writes and original signed reloads are retained.
* EXE80035EE0 and its matched source/header consume six arguments: original
* caller SP10=0,SP14=1 on both physical heading paths are preserved.
* Literal42 and independent literal1 producers retain original call slots.
* Complete old/new coordinate and countdown reads preserve original widths.
* Empty metadata consumes initialized full words/addresses or clobbers a
* dead caller value before its next complete producer. No CPU instructions,
* partialHI,fixedFP,undefined saved inputs or pipeline changes are added.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Binary identity is confirmed only
* after all gates. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned data,padding and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 0d45428ab1b87b3890f3c6ed0f8779dc8da64f850d00e0abefa70486314f0fdc */
#define Level24_82D3CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level24_82D3CPrepareCameraMode9VectorsView1() __asm__("func_80013AE4");
int Level24_82D3CSetCameraMode11TargetView1() __asm__("func_80013D44");
int Level24_82D3CQueryWorldSphereView1() __asm__("func_80019194");
int Level24_82D3CMaskLinkedRecordFlagsByIdView1() __asm__("func_80021ED8");
void Level24_82D3CRequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level24_82D3CTurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level24_82D3CCountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level24_82D3CUpdateMobyPathMotionView1() __asm__("func_80035A80");
int Level24_82D3CProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Level24_82D3CResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level24_82D3CResolveMobyHeadingStepView1(void*, int, int, int, int,
                                             int) __asm__("func_80035EE0");
int Level24_82D3CTestPaddedRotatedBoxView1() __asm__("func_80036220");
int Level24_82D3CUpdateMobyInteractionGateView1() __asm__("func_80037BBC");
int Level24_82D3CRestoreOrClearTrackedSnapshotView1() __asm__("func_8003B74C");
int Level24_82D3CRegisterTrackedValueView1() __asm__("func_8003B7B4");
int Level24_82D3CPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level24_82D3CMeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level24_82D3CComputeVectorPlaneResponseView1() __asm__("func_8004EF74");
void Level24_82D3CCopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level24_82D3CAddVectorView1(void*, void*, void*) __asm__("func_8004F194");
int Level24_82D3CApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level24_82D3CStartDialogueView1() __asm__("func_800512E4");
extern int Level24_82D3CData658A0View1 __asm__("D_800658A0");
extern int Level24_82D3CData65920View1 __asm__("D_80065920");
extern int Level24_82D3CData6C550View1 __asm__("D_8006C550");
extern int Level24_82D3CData6C58CView1 __asm__("D_8006C58C");
extern int Level24_82D3CData6C598View1 __asm__("D_8006C598");
extern int Level24_82D3CData6C770View1 __asm__("D_8006C770");
extern unsigned char Level24_82D3CData6C7B4View1 __asm__("D_8006C7B4");
extern int Level24_82D3CData6C7F8View1 __asm__("D_8006C7F8");
extern int Level24_82D3CData6D088View1 __asm__("D_8006D088");
extern int Level24_82D3CData6E044View1 __asm__("D_8006E044");
extern int Level24_82D3CData6E048View1 __asm__("D_8006E048");
extern int Level24_82D3CData6E344View1 __asm__("D_8006E344");
extern int Level24_82D3CData70328View1 __asm__("D_80070328");
extern int Level24_82D3CData716ACView1 __asm__("D_800716AC");
extern int Level24_82D3CData71918View1 __asm__("D_80071918");
extern int (*Level24_82D3CData74330View1)() __asm__("unk_ovlheader_80074330");
extern int (*Level24_82D3CData74334View1)() __asm__("unk_ovlheader_80074334");
void func_level_24_80082D3C(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord18 __asm__("$18");
    register int privateRecord17 __asm__("$17"), retainedRecordOrVector16 __asm__("$16");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C;
    } originalFrame;
    int temporaryWord6;
    int temporaryWord34;
    int temporaryWord26;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord21;
    int temporaryWord24;
    int temporaryWord25;
    int temporaryWord28;
    int temporaryWord12;
    int temporaryWord20;
    int temporaryWord27;
    int temporaryWord33;
    int temporaryWord1;
    int temporaryWord13;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord18;
    int temporaryWord19;
    int temporaryWord22;
    int temporaryWord23;
    int temporaryWord29;
    int temporaryWord30;
    int temporaryWord31;
    int temporaryWord32;
    ownerRecord18 = ownerParameter;
    MATCHING_KEEP(ownerRecord18);
    privateRecord17 = Level24_82D3CField(ownerRecord18, void**, 0);
    if ((Level24_82D3CField(ownerRecord18, int*, 0x18) & 0x10000000) &&
        (Level24_82D3CField(Level24_82D3CField(privateRecord17, int*, 0x4C), int*, 0) < 0x10) &&
        ((unsigned char)Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) < 0x24U)) {
        retainedRecordOrVector16 =
            Level24_82D3CField(((Level24_82D3CField(privateRecord17, int*, 0x3C) * 0x58) +
                                Level24_82D3CData6C550View1),
                               int*, 0);
        Level24_82D3CField(privateRecord17, unsigned short*, 0x40) = 0x4BU;
        Level24_82D3CField(privateRecord17, unsigned short*, 0x42) = 0x64U;
        Level24_82D3CRequestMobyAnimationView1(ownerParameter, 5);
        Level24_82D3CField(ownerRecord18, signed char*, 0x49) = 0x1E;
        if (Level24_82D3CData6E044View1 == 9) {
            Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0x24U;
        } else {
            Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0x2BU;
            rawWord2 = Level24_82D3CField(privateRecord17, int*, 52);
            argumentWord4 = (int)&originalFrame.sp20;
            if (rawWord2 >= 0) {
                rawWord2 = Level24_82D3CField(retainedRecordOrVector16, int*, 0);
                MATCHING_OBSERVE_CLOBBER(rawWord2, "memory");
                argumentWord5 = Level24_82D3CField(privateRecord17, unsigned short*, 68);
                rawWord2 = Level24_82D3CField(rawWord2, int*, 12);
                MATCHING_KEEP(rawWord2);
                argumentWord5 *= 16;
            } else {
                rawWord3 = Level24_82D3CField(privateRecord17, int*, 56);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level24_82D3CData6C550View1;
                rawWord2 += rawWord3;
                rawWord2 = Level24_82D3CField(rawWord2, int*, 0);
                argumentWord5 = Level24_82D3CField(rawWord2, int*, 12);
                rawWord2 = Level24_82D3CField(retainedRecordOrVector16, int*, 0);
                argumentWord5 *= 16;
                rawWord2 = Level24_82D3CField(rawWord2, int*, 12);
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(rawWord2));
                argumentWord5 += 96;
            }
            argumentWord5 = rawWord2 + argumentWord5;
            Level24_82D3CCopyVectorView1(argumentWord4, argumentWord5);
            originalFrame.sp28 += 0x2000;
            Level24_82D3CPrepareCameraMode9VectorsView1(&originalFrame.sp20, ownerRecord18 + 0xC);
        }
    }
    temporaryWord20 = Level24_82D3CField(ownerRecord18, unsigned char*, 0x48);
    Level24_82D3CField(ownerRecord18, int*, 0x18) = 0;
    switch (temporaryWord20) {
        case 38:
            if ((Level24_82D3CData6C598View1 == 0) &&
                ((Level24_82D3CTestPaddedRotatedBoxView1((int)&Level24_82D3CData70328View1,
                                                         privateRecord17 + 0x50, 0, 0x400) != 0) ||
                 (Level24_82D3CUpdateMobyInteractionGateView1(ownerRecord18, 0) != 0))) {
                Level24_82D3CStartDialogueView1(ownerRecord18, 0, 0xA);
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0x27U;
                return;
            }
            if ((Level24_82D3CData6E044View1 != 9) &&
                (Level24_82D3CField(Level24_82D3CField(privateRecord17, int*, 0x4C), int*, 0) ==
                 0x10)) {
                temporaryWord12 = Level24_82D3CField(privateRecord17, unsigned short*, 0x42) + 1;
                Level24_82D3CField(privateRecord17, unsigned short*, 0x42) = temporaryWord12;
                if ((short)temporaryWord12 >= 0x3D) {
                    Level24_82D3CField(((Level24_82D3CField(privateRecord17, int*, 0x3C) * 0x58) +
                                        Level24_82D3CData6C550View1),
                                       signed char*, 0x49) = 2;
                    Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x20C) =
                        (int)(Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x20C) |
                              0x10002000);
                    Level24_82D3CField(Level24_82D3CField(ownerRecord18, void**, 0), signed char*,
                                       5) = 2;
                    rawWord2 = Level24_82D3CField(ownerRecord18, unsigned char*, 70);
                    retainedRecordOrVector16 = (int)&originalFrame.sp30;
                    rawWord2 *= 2;
                    rawWord3 =
                        Level24_82D3CField((int)&Level24_82D3CData65920View1, short*, rawWord2);
                    argumentWord6 = (int)ownerRecord18 + 12;
                    rawWord2 = (rawWord3 * 39) >> 6;
                    originalFrame.sp30 = rawWord2;
                    rawWord2 = Level24_82D3CField(ownerRecord18, unsigned char*, 70);
                    argumentWord5 = retainedRecordOrVector16;
                    rawWord2 *= 2;
                    rawWord3 =
                        Level24_82D3CField((int)&Level24_82D3CData658A0View1, short*, rawWord2);
                    MATCHING_KEEP_CLOBBER(rawWord3, "memory");
                    rawWord2 = Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 68);
                    argumentWord4 = retainedRecordOrVector16;
                    originalFrame.sp38 = 0;
                    MATCHING_BARRIER_VOLATILE("memory");
                    originalFrame.sp38 = rawWord2;
                    rawWord2 = (rawWord3 * 39) >> 6;
                    originalFrame.sp34 = rawWord2;
                    Level24_82D3CAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                    Level24_82D3CSetCameraMode11TargetView1(
                        &originalFrame.sp30,
                        (Level24_82D3CField(ownerRecord18, unsigned char*, 0x46) + 0x80) & 0xFF, 0,
                        0);
                    if (Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x280) < 0) {
                        Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x280) = 0;
                    }
                    temporaryWord26 = Level24_82D3CField(privateRecord17, void**, 0x4C);
                    Level24_82D3CData6C7B4View1 |= 2;
                    Level24_82D3CField(temporaryWord26, int*, 0) += 1;
                    Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0x2CU;
                    return;
                }
            }
        default:
            return;
        case 44:
            Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x20C) =
                (int)(Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x20C) |
                      0x10002000);
            if ((Level24_82D3CData6E044View1 == 0xB) && (Level24_82D3CData6E048View1 == 1)) {
                rawWord2 = 38;
                goto writeSharedOriginalState38;
            }
            break;
        case 41:
            if (Level24_82D3CApproximatePlanarDistanceView1(
                    Level24_82D3CData6C550View1 +
                        (Level24_82D3CField(privateRecord17, int*, 0x3C) * 0x58) + 0xC,
                    (int)&Level24_82D3CData70328View1) < 0xC00) {
                if (Level24_82D3CData74334View1(
                        Level24_82D3CData6C550View1 +
                        (Level24_82D3CField(privateRecord17, int*, 0x3C) * 0x58) + 0xC) != 0) {
                    rawWord2 = 38;
                    goto writeSharedOriginalState38;
                }
            } else {
                temporaryWord1 = Level24_82D3CData6C550View1 +
                                 (Level24_82D3CField(privateRecord17, int*, 0x3C) * 0x58);
                if (Level24_82D3CData74330View1(
                        temporaryWord1 + 0xC,
                        Level24_82D3CField(temporaryWord1, unsigned char*, 0x46), 0) != 0) {
                    rawWord2 = 38;
                    goto writeSharedOriginalState38;
                }
            }
            break;
        case 42:
            temporaryWord13 =
                Level24_82D3CField(Level24_82D3CField(privateRecord17, void**, 0x68), void**, 0xC);
            temporaryWord9 = Level24_82D3CField(temporaryWord13, int*, 0x10);
            if (Level24_82D3CData74330View1(
                    Level24_82D3CField(Level24_82D3CField(privateRecord17, void**, 0x68), void**,
                                       0xC),
                    Level24_82D3CPlanarHeadingLookupView1(
                        temporaryWord9 - Level24_82D3CField(temporaryWord13, int*, 0),
                        Level24_82D3CField(temporaryWord13, int*, 0x14) -
                            Level24_82D3CField(temporaryWord13, int*, 4),
                        0),
                    0) != 0) {
                rawWord2 = 38;
                goto writeSharedOriginalState38;
            }
            break;
        case 39:
            rawWord2 = Level24_82D3CData6E344View1;
            rawWord3 = 1;
            if (rawWord2 != rawWord3) {
                rawWord2 = Level24_82D3CField(privateRecord17, unsigned char*, 4);
                if (rawWord2 == rawWord3) {
                    rawWord2 = 42;
                    MATCHING_KEEP_CLOBBER(rawWord2, "$3");
                    retainedRecordOrVector16 = privateRecord17 + 5;
                    Level24_82D3CField(privateRecord17, signed char*, 5) = 1;
                    Level24_82D3CRegisterTrackedValueView1(retainedRecordOrVector16, 1,
                                                           (int)&Level24_82D3CData6D088View1);
                    Level24_82D3CRegisterTrackedValueView1(retainedRecordOrVector16, 1,
                                                           (int)&Level24_82D3CData6C7F8View1);
                    temporaryWord2 = Level24_82D3CData6C58CView1 * 6;
                    temporaryWord27 = Level24_82D3CField((int)&Level24_82D3CData716ACView1,
                                                         unsigned char*, 1 + temporaryWord2);
                    if (temporaryWord27 < 0xFFU) {
                        Level24_82D3CField((int)&Level24_82D3CData716ACView1, unsigned char*,
                                           1 + temporaryWord2) = temporaryWord27 + 1;
                    }
                    rawWord2 = 0x29;
                } else
                    rawWord2 = 42;
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 0);
                return;
            }
            break;
        case 0:
            if ((Level24_82D3CField(privateRecord17, void**, 0x2C) == 0) &&
                (Level24_82D3CField(privateRecord17, void**, 0x30) == 0)) {
                Level24_82D3CField(ownerRecord18, int*, 0x14) =
                    Level24_82D3CProbeGroundFromRaisedMobyView1(ownerRecord18);
                rawWord2 = 38;
            writeSharedOriginalState38:
                Level24_82D3CField(ownerRecord18, unsigned char*, 72) = rawWord2;
                return;
            }
            if (Level24_82D3CField(privateRecord17, int*, 0x34) <= 0) {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x47) = 0xFE;
                goto writeSharedOriginalState8;
            }
            temporaryWord14 =
                Level24_82D3CField(Level24_82D3CField(privateRecord17, void**, 0x2C), void**, 0xC);
            temporaryWord10 = Level24_82D3CField(temporaryWord14, int*, 0x10);
            Level24_82D3CField(privateRecord17, unsigned short*, 0x40) =
                Level24_82D3CPlanarHeadingLookupView1(
                    temporaryWord10 - Level24_82D3CField(temporaryWord14, int*, 0),
                    Level24_82D3CField(temporaryWord14, int*, 0x14) -
                        Level24_82D3CField(temporaryWord14, int*, 4),
                    0);
            Level24_82D3CCopyVectorView1(
                ownerRecord18 + 0xC,
                Level24_82D3CField(Level24_82D3CField(privateRecord17, void**, 0x2C), void**, 0xC));
            rawWord3 = Level24_82D3CField(privateRecord17, unsigned short*, 64);
            rawWord2 = 11;
            Level24_82D3CField(ownerRecord18, unsigned char*, 69) = 0;
            Level24_82D3CField(ownerRecord18, unsigned char*, 72) = rawWord2;
            Level24_82D3CField(ownerRecord18, unsigned char*, 70) = rawWord3;
            return;
        case 11:
            temporaryWord28 = Level24_82D3CField(privateRecord17, int*, 0x3C);
            if ((temporaryWord28 >= 0) &&
                (Level24_82D3CField(
                     Level24_82D3CField(
                         Level24_82D3CField(
                             ((temporaryWord28 * 0x58) + Level24_82D3CData6C550View1), int*, 0),
                         int*, 0),
                     short*, 2) == Level24_82D3CField(privateRecord17, unsigned short*, 0x44)) &&
                (Level24_82D3CField(privateRecord17, void**, 0x2C) != 0)) {
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 8);
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 1U;
                Level24_82D3CField(Level24_82D3CField(privateRecord17, void**, 0x2C), short*, 2) =
                    0;
                temporaryWord15 = Level24_82D3CField(
                    Level24_82D3CField(privateRecord17, void**, 0x2C), void**, 0xC);
                temporaryWord11 = Level24_82D3CField(temporaryWord15, int*, 0x10);
                Level24_82D3CField(privateRecord17, unsigned short*, 0x40) =
                    Level24_82D3CPlanarHeadingLookupView1(
                        temporaryWord11 - Level24_82D3CField(temporaryWord15, int*, 0),
                        Level24_82D3CField(temporaryWord15, int*, 0x14) -
                            Level24_82D3CField(temporaryWord15, int*, 4),
                        0);
                Level24_82D3CCopyVectorView1(
                    ownerRecord18 + 0xC,
                    Level24_82D3CField(Level24_82D3CField(privateRecord17, void**, 0x2C), void**,
                                       0xC));
                rawWord2 = Level24_82D3CField(privateRecord17, unsigned short*, 64);
                MATCHING_KEEP_CLOBBER(rawWord2, "memory");
                Level24_82D3CField(ownerRecord18, unsigned char*, 69) = 0;
                Level24_82D3CField(ownerRecord18, unsigned char*, 70) = rawWord2;
                return;
            }
            break;
        case 1:
            if (Level24_82D3CUpdateMobyPathMotionView1(
                    ownerRecord18, Level24_82D3CField(privateRecord17, void**, 0x2C), 0x200, 0x50,
                    0, 1, 0x20, 1) &
                1) {
                temporaryWord29 = Level24_82D3CField(privateRecord17, void**, 0x2C);
                if (Level24_82D3CField(((Level24_82D3CField(temporaryWord29, short*, 2) * 0x10) +
                                        Level24_82D3CField(temporaryWord29, void**, 0xC)),
                                       int*, 0xC) != 0) {
                    Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 2U;
                    return;
                }
            }
            break;
        case 2:
            if (Level24_82D3CUpdateMobyPathMotionView1(
                    ownerRecord18, Level24_82D3CField(privateRecord17, void**, 0x2C), 0x200, 0x50,
                    0, 1, 0x20, 1) &
                1) {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0xAU;
                return;
            }
            break;
        case 10:
            if (Level24_82D3CTurnMobyTowardHeadingView1(
                    ownerRecord18,
                    (short)Level24_82D3CField(privateRecord17, unsigned short*, 0x40), 6, 3, 1,
                    0) != 0) {
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 3);
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 3U;
                return;
            }
            break;
        case 3:
            temporaryWord3 = Level24_82D3CField(ownerRecord18, int*, 0x14) +
                             Level24_82D3CField(privateRecord17, short*, 0x4A);
            Level24_82D3CField(ownerRecord18, int*, 0x14) = temporaryWord3;
            rawWord3 = Level24_82D3CField(privateRecord17, int*, 44);
            rawWord2 = Level24_82D3CField(rawWord3, short*, 2);
            rawWord3 = Level24_82D3CField(rawWord3, int*, 12);
            rawWord2 *= 16;
            rawWord3 = rawWord2 + rawWord3;
            temporaryWord30 = rawWord3;
            if (Level24_82D3CField(temporaryWord30, int*, 8) < (temporaryWord3 + 0x80)) {
                if (Level24_82D3CField(temporaryWord30, int*, 0xC) != 0) {
                    Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 4);
                    Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 4U;
                }
                temporaryWord31 = Level24_82D3CField(privateRecord17, void**, 0x2C);
                Level24_82D3CField(temporaryWord31, short*, 2) =
                    (short)((unsigned short)Level24_82D3CField(temporaryWord31, short*, 2) + 1);
                return;
            }
            break;
        case 4:
            if (Level24_82D3CData6C770View1 != 0) {
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 8);
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0xCU;
            }
            temporaryWord32 = Level24_82D3CField(privateRecord17, void**, 0x2C);
            temporaryWord21 = Level24_82D3CField(ownerRecord18, int*, 0x14);
            if (temporaryWord21 <
                Level24_82D3CField(((Level24_82D3CField(temporaryWord32, short*, 2) * 0x10) +
                                    Level24_82D3CField(temporaryWord32, void**, 0xC)),
                                   int*, 8)) {
                temporaryWord4 =
                    temporaryWord21 + Level24_82D3CField(privateRecord17, short*, 0x4A);
                Level24_82D3CField(ownerRecord18, int*, 0x14) = temporaryWord4;
                temporaryWord22 = Level24_82D3CField(privateRecord17, void**, 0x2C);
                temporaryWord16 =
                    Level24_82D3CField(((Level24_82D3CField(temporaryWord22, short*, 2) * 0x10) +
                                        Level24_82D3CField(temporaryWord22, void**, 0xC)),
                                       int*, 8);
                if (temporaryWord16 < temporaryWord4) {
                    Level24_82D3CField(ownerRecord18, int*, 0x14) = temporaryWord16;
                    return;
                }
            } else {
                Level24_82D3CResolveMobyYawStepView1(ownerRecord18, 0x14, 0x32, 0x32, 1);
                return;
            }
            break;
        case 5:
            argumentWord5 = Level24_82D3CField(privateRecord17, int*, 0x3C);
            if ((argumentWord5 >= 0) &&
                (Level24_82D3CField(
                     Level24_82D3CField(
                         Level24_82D3CField(((argumentWord5 * 0x58) + Level24_82D3CData6C550View1),
                                            int*, 0),
                         int*, 0),
                     short*, 2) >= 0x62)) {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0U;
                return;
            }
            break;
        case 12:
            temporaryWord5 = Level24_82D3CField(ownerRecord18, int*, 0x14) +
                             Level24_82D3CField(privateRecord17, short*, 0x4A);
            Level24_82D3CField(ownerRecord18, int*, 0x14) = temporaryWord5;
            temporaryWord23 = Level24_82D3CField(privateRecord17, void**, 0x2C);
            temporaryWord17 =
                Level24_82D3CField(((Level24_82D3CField(temporaryWord23, short*, 2) * 0x10) +
                                    Level24_82D3CField(temporaryWord23, void**, 0xC)),
                                   int*, 8);
            if (temporaryWord17 < temporaryWord5) {
                Level24_82D3CField(ownerRecord18, int*, 0x14) = temporaryWord17;
            }
            if (Level24_82D3CUpdateMobyPathMotionView1(
                    ownerRecord18, Level24_82D3CField(privateRecord17, void**, 0x2C), 0x80, 0x50, 0,
                    1, 0x20, 1) &
                2) {
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 0);
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x47) = 0xFE;
                if (Level24_82D3CField(privateRecord17, int*, 0x38) > 0) {
                    Level24_82D3CField(privateRecord17, int*, 0x34) = -1;
                writeSharedOriginalState8:
                    Level24_82D3CField(ownerRecord18, unsigned char*, 72) = 8;
                    return;
                }
                goto writeSharedOriginalState5;
            }
            break;
        case 8:
            temporaryWord18 = Level24_82D3CField(privateRecord17, void**, 0x2C);
            if (temporaryWord18 != 0) {
                temporaryWord19 = Level24_82D3CField(temporaryWord18, void**, 0xC);
                Level24_82D3CTurnMobyTowardHeadingView1(
                    ownerRecord18,
                    Level24_82D3CPlanarHeadingLookupView1(
                        Level24_82D3CField(temporaryWord19, int*, 0) -
                            Level24_82D3CField(ownerRecord18, int*, 0xC),
                        Level24_82D3CField(temporaryWord19, int*, 4) -
                            Level24_82D3CField(ownerRecord18, int*, 0x10),
                        0),
                    4, 0, 1, 0);
            }
            temporaryWord24 = Level24_82D3CField(privateRecord17, int*, 0x3C);
            if ((temporaryWord24 >= 0) &&
                (Level24_82D3CField(
                     Level24_82D3CField(
                         Level24_82D3CField(
                             ((temporaryWord24 * 0x58) + Level24_82D3CData6C550View1), int*, 0),
                         int*, 0),
                     short*, 2) == Level24_82D3CField(privateRecord17, unsigned short*, 0x46))) {
                temporaryWord6 = Level24_82D3CField(privateRecord17, short*, 0x48);
                if (temporaryWord6 >= 0) {
                    Level24_82D3CMaskLinkedRecordFlagsByIdView1(temporaryWord6, 0xFC, 0);
                }
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 9U;
                return;
            }
            break;
        case 9:
            argumentWord4 = Level24_82D3CField(privateRecord17, int*, 0x38);
            if ((argumentWord4 >= 0) &&
                (Level24_82D3CField(((argumentWord4 * 0x58) + Level24_82D3CData6C550View1),
                                    unsigned char*, 0x48) == 5)) {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 6U;
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 7);
                return;
            }
            break;
        case 6:
            if (Level24_82D3CUpdateMobyPathMotionView1(
                    ownerRecord18, Level24_82D3CField(privateRecord17, void**, 0x30), 0x100, 0x50,
                    0, 3, 0x20, 0) &
                2) {
                Level24_82D3CRequestMobyAnimationView1(ownerRecord18, 0);
            writeSharedOriginalState5:
                Level24_82D3CField(ownerRecord18, unsigned char*, 72) = 5;
                return;
            }
            break;
        case 43:
            Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x20C) =
                (int)(Level24_82D3CField((int)&Level24_82D3CData70328View1, int*, 0x20C) |
                      0x10002000);
            Level24_82D3CField(((Level24_82D3CField(privateRecord17, int*, 0x3C) * 0x58) +
                                Level24_82D3CData6C550View1),
                               signed char*, 0x49) = 1;
            if ((Level24_82D3CData6E044View1 == 9) && (Level24_82D3CData6E048View1 == 1)) {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x48) = 0x28U;
                Level24_82D3CField(ownerRecord18, signed char*, 0x49) = 0x1E;
            }
        case 40:
            rawWord2 = Level24_82D3CField(privateRecord17, int*, 60);
            argumentWord4 = Level24_82D3CData6C550View1;
            rawWord3 = rawWord2 * 88;
            rawWord3 += argumentWord4;
            rawWord2 = Level24_82D3CField(privateRecord17, int*, 52);
            argumentWord6 = Level24_82D3CField(rawWord3, int*, 0);
            if (rawWord2 >= 0) {
                argumentWord4 = (int)&originalFrame.sp40;
                rawWord2 = Level24_82D3CField(argumentWord6, int*, 0);
                MATCHING_OBSERVE_CLOBBER(rawWord2, "memory");
                argumentWord5 = Level24_82D3CField(privateRecord17, unsigned short*, 68);
                rawWord2 = Level24_82D3CField(rawWord2, int*, 12);
                MATCHING_KEEP(rawWord2);
                argumentWord5 *= 16;
            } else {
                rawWord3 = Level24_82D3CField(privateRecord17, int*, 56);
                rawWord2 = rawWord3 * 88;
                rawWord2 += argumentWord4;
                rawWord2 = Level24_82D3CField(rawWord2, int*, 0);
                argumentWord4 = (int)&originalFrame.sp40;
                argumentWord5 = Level24_82D3CField(rawWord2, int*, 12);
                rawWord2 = Level24_82D3CField(argumentWord6, int*, 0);
                argumentWord5 *= 16;
                rawWord2 = Level24_82D3CField(rawWord2, int*, 12);
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(rawWord2));
                argumentWord5 += 96;
            }
            argumentWord5 = rawWord2 + argumentWord5;
            Level24_82D3CCopyVectorView1(argumentWord4, argumentWord5);
            originalFrame.sp48 += 0x2000;
            Level24_82D3CPrepareCameraMode9VectorsView1(&originalFrame.sp40, ownerRecord18 + 0xC);
        case 36:
            rawWord2 = Level24_82D3CData6C770View1;
            argumentWord4 = (int)ownerRecord18;
            if (rawWord2) {
                Level24_82D3CRequestMobyAnimationView1(argumentWord4, 1);
            }
            __asm__("" ::: "$4", "memory");
            rawWord2 = Level24_82D3CField(privateRecord17, int*, 52);
            argumentWord4 = (int)ownerRecord18;
            if (rawWord2 >= 0) {
                argumentWord7 = 0;
                __asm__("" : "=r"(argumentWord7) : "0"(argumentWord7) : "$2", "memory");
                argumentWord5 = Level24_82D3CField(ownerRecord18, unsigned char*, 70);
                argumentWord6 = Level24_82D3CField(privateRecord17, short*, 66);
                rawWord2 = 1;
                argumentWord5 = (argumentWord5 + 128) & 255;
                Level24_82D3CResolveMobyHeadingStepView1(argumentWord4, argumentWord5,
                                                         argumentWord6, argumentWord7, 0, rawWord2);
            } else {
                __asm__("" ::: "$7", "memory");
                argumentWord7 = 0;
                __asm__("" : "=r"(argumentWord7) : "0"(argumentWord7) : "$2", "memory");
                argumentWord5 = Level24_82D3CField(ownerRecord18, unsigned char*, 81);
                argumentWord6 = Level24_82D3CField(privateRecord17, short*, 66);
                rawWord2 = 1;
                Level24_82D3CResolveMobyHeadingStepView1(argumentWord4, argumentWord5,
                                                         argumentWord6, argumentWord7, 0, rawWord2);
            }
            Level24_82D3CField(ownerRecord18, int*, 0x14) =
                (int)(Level24_82D3CField(ownerRecord18, int*, 0x14) +
                      (short)Level24_82D3CField(privateRecord17, unsigned short*, 0x40));
            Level24_82D3CField(privateRecord17, unsigned short*, 0x40) =
                (unsigned short)(Level24_82D3CField(privateRecord17, unsigned short*, 0x40) - 5);
            temporaryWord7 = Level24_82D3CProbeGroundFromRaisedMobyView1(ownerRecord18);
            if (((short)Level24_82D3CField(privateRecord17, unsigned short*, 0x42) == 0x64) ||
                ((unsigned char)Level24_82D3CField(ownerRecord18, unsigned char*, 0x45) >= 8U)) {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x45) =
                    (unsigned char)(Level24_82D3CField(ownerRecord18, unsigned char*, 0x45) + 8);
            } else {
                Level24_82D3CField(ownerRecord18, unsigned char*, 0x45) = 0U;
            }
            if (temporaryWord7 >= Level24_82D3CField(ownerRecord18, int*, 0x14)) {
                Level24_82D3CField(ownerRecord18, int*, 0x14) = temporaryWord7;
                rawWord2 = Level24_82D3CField(privateRecord17, short*, 64);
                if (rawWord2 <= 0) {
                    rawWord2 = -rawWord2;
                    rawWord3 = Level24_82D3CField(privateRecord17, unsigned short*, 66);
                    rawWord2 >>= 1;
                    Level24_82D3CField(privateRecord17, short*, 64) = rawWord2;
                    MATCHING_BARRIER("memory");
                    rawWord2 = Level24_82D3CField(privateRecord17, short*, 64);
                    rawWord3 = (rawWord3 << 16) >> 17;
                    rawWord2 = rawWord2 < 10;
                    Level24_82D3CField(privateRecord17, short*, 66) = rawWord3;
                    goto checkOriginalSmallSignedValue;
                }
            } else if ((Level24_82D3CCountTimerDownView1(ownerRecord18 + 0x49, 1) != 0) &&
                       (Level24_82D3CQueryWorldSphereView1(ownerRecord18 + 0xC, 0x140) != 0)) {
                if (Level24_82D3CField(privateRecord17, int*, 0x34) >= 0) {
                    temporaryWord33 =
                        (Level24_82D3CField(ownerRecord18, unsigned char*, 0x46) + 0x80) & 0xFF;
                } else {
                    temporaryWord33 = Level24_82D3CField(ownerRecord18, unsigned char*, 0x51);
                }
                temporaryWord8 = temporaryWord33 * 2;
                originalFrame.sp50 =
                    (int)(Level24_82D3CField((int)&Level24_82D3CData65920View1, short*,
                                             temporaryWord8) *
                          (short)Level24_82D3CField(privateRecord17, unsigned short*, 0x42)) >>
                    0xC;
                rawWord3 =
                    Level24_82D3CField((int)&Level24_82D3CData658A0View1, short*, temporaryWord8);
                rawWord2 = Level24_82D3CField(privateRecord17, short*, 66);
                __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2) : "memory");
                originalFrame.sp58 = 0;
                originalFrame.sp54 = (rawWord3 * rawWord2) >> 12;
                originalFrame.sp58 =
                    (int)(short)Level24_82D3CField(privateRecord17, unsigned short*, 0x40);
                if (Level24_82D3CComputeVectorPlaneResponseView1(&originalFrame.sp50,
                                                                 (int)&Level24_82D3CData71918View1,
                                                                 &originalFrame.sp50) != 0) {
                    originalFrame.sp50 = originalFrame.sp50 >> 1;
                    temporaryWord25 = originalFrame.sp58 >> 1;
                    originalFrame.sp58 = temporaryWord25;
                    originalFrame.sp54 = originalFrame.sp54 >> 1;
                    Level24_82D3CField(privateRecord17, unsigned short*, 0x40) =
                        (unsigned short)temporaryWord25;
                    originalFrame.sp58 = 0;
                    Level24_82D3CField(privateRecord17, unsigned short*, 0x42) =
                        Level24_82D3CMeasureVectorLengthView1(&originalFrame.sp50, 0);
                    Level24_82D3CField(ownerRecord18, unsigned char*, 0x51) =
                        Level24_82D3CPlanarHeadingLookupView1(originalFrame.sp50,
                                                              originalFrame.sp54, 0);
                }
                temporaryWord34 = (short)Level24_82D3CField(privateRecord17, unsigned short*, 0x40);
                if (temporaryWord34 < 0) {
                    temporaryWord34 = -temporaryWord34;
                }
                rawWord2 = temporaryWord34 < 0xA;
            checkOriginalSmallSignedValue:
                if (rawWord2 != 0) {
                    Level24_82D3CRestoreOrClearTrackedSnapshotView1(
                        (int)&Level24_82D3CData6D088View1);
                }
            }
            break;
    }
}
#undef Level24_82D3CField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_24/moby/func_level_24_80083C6C.s SHA256 02b8d0da5eb643a8ca38e8e101c1610745ac642460f8bab5770ecb02a8993236. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level24_83C6CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level24_83C6C_D_8006C550 __asm__("D_8006C550");
void Level24_83C6CRequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level24_83C6CProbeGroundFromRaisedMoby(Moby* moby) __asm__("func_80035D38");
int Level24_83C6CResolveMobyHeadingStep(Moby*, int, int, int, int, int) __asm__("func_80035EE0");
void Level24_83C6CEmitMobyVertexParticles() __asm__("func_800369B8");
void Level24_83C6CMarkMobyCollectionBit(Moby* moby) __asm__("func_8003BA00");
extern int Level24_83C6CMeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
extern void Level24_83C6CDeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level24_83C6CRefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level24_83C6CReadSelectedFrameScalar(Moby*) __asm__("func_80055E84");

int Level24_83C6CUpdateMobyPathMotion(Moby*, int, unsigned char, unsigned char, int, int, int,
                                      int) __asm__("func_80035A80");
/* extern */
extern int Level24_83C6C_D_8006C770 __asm__("D_8006C770");
extern int Level24_83C6C_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level24_83C6C_D_80071920 __asm__("D_80071920");

void func_level_24_80083C6C(Moby* inputOwner) {
    /* Original 0x30 frame, 88-byte pool stride and two consecutive parent
     * pointer loads are retained. The helper vector starts eight BYTES
     * before D_80071920;
      it is not int-pointer subtraction. Shared state-2
     * and state-71 callback blocks remain at the original control targets.
     * Position and private halfword reloads follow their disc producers.
     * Empty constraints and comment markers emit no instructions. Helper
     * contracts, physical units/fixed point, frame cadence and synchronized
     * runtime captures remain unresolved. AI generated;
      not human reviewed. */
    register Moby* owner17 __asm__("$17") = inputOwner;
    int* temp_v1;
    register int anchorIndex5 __asm__("$5");
    register int alternateAnchor5 __asm__("$5");
    register int helperResult16 __asm__("$16");
    int parentIndex;
    int oldPositionZ;
    register int* vectorAddress2 __asm__("$2");
    register void* helperVector4 __asm__("$4");
    register int magnitudeOrPredicate16 __asm__("$16");
    int nextPositionZ;
    unsigned char decrementedSubstate;
    register int state3 __asm__("$3");
    unsigned char oldSubstate72;
    unsigned char oldSubstate70;
    register int nextState2 __asm__("$2");
    register int nextSubstate2 __asm__("$2");
    register void* private16 __asm__("$16");

    MATCHING_KEEP(owner17);
    private16 = owner17->mobyTag;
    if ((owner17->damageFlags != 0) && ((unsigned char)owner17->state < 0x46U)) {
        temp_v1 = Level24_83C6CField(private16, int**, 0x14);
        *temp_v1 += 1;
        Level24_83C6CRequestMobyAnimation(inputOwner, 8);
        owner17->substate = 0x78;
        if (Level24_83C6CField(private16, int*, 0x10) >= 0) {
            Level24_83C6CField(private16, short*, 4) = 0x12C;
            Level24_83C6CField(private16, short*, 6) = 0x96;
            __asm__ volatile("# initialized-positive");
            nextState2 = 0x48;
        } else {
            Level24_83C6CField(private16, short*, 4) = 0x190;
            Level24_83C6CField(private16, short*, 6) = 0xC8;
            __asm__ volatile("# initialized-negative");
            nextState2 = 0x46;
        }
        owner17->state = nextState2;
    }
    state3 = owner17->state;
    owner17->damageFlags = 0;
    switch (state3) {
        case 0x0:
            if (Level24_83C6CField(private16, int*, 0x10) >= 0) {
                owner17->drawn = 0;
                owner17->lowDrawDistance = 0;
                owner17->state = 4;
                owner17->position.z += 0x2800;
                return;
            }
            anchorIndex5 = Level24_83C6CField(private16, int*, 8);
            if ((anchorIndex5 >= 0) && (Level24_83C6C_D_8006C550[anchorIndex5].state == 3)) {
                Level24_83C6CRequestMobyAnimation(owner17, 3);
                owner17->state = 1;
                return;
            }
        default:
            return;
        case 0x1:
            alternateAnchor5 = Level24_83C6CField(private16, int*, 8);
            if ((alternateAnchor5 >= 0) &&
                (helperVector4 = owner17, Level24_83C6C_D_8006C550[alternateAnchor5].state == 4)) {
                __asm__ volatile("# route-to-state-2");
                goto resetToState2;
            }
            break;
        case 0x2:
            if ((owner17->animationState.id == 5) &&
                (Level24_83C6CReadSelectedFrameScalar(owner17) >= 9)) {
                Level24_83C6C_D_8006C550[Level24_83C6CField(private16, int*, 8)].damageFlags =
                    0x10000000;
                Level24_83C6C_D_8006C550[Level24_83C6CField(private16, int*, 8)].unkb =
                    owner17->angle.yaw + 0x40;
            }
            if (Level24_83C6C_D_8006C770 != 0) {
                Level24_83C6CRequestMobyAnimation(owner17, 6);
                owner17->state = 3;
                return;
            }
            break;
        case 0x3:
            if (Level24_83C6C_D_8006C770 != 0) {
                Level24_83C6CRequestMobyAnimation(owner17, 0);
                owner17->state = 0;
                return;
            }
            break;
        case 0x4:
            parentIndex = Level24_83C6CField(private16, int*, 0x10);
            if ((parentIndex >= 0) &&
                (Level24_83C6CField(
                     Level24_83C6CField(Level24_83C6C_D_8006C550[parentIndex].mobyTag, void**, 0),
                     short*, 2) == Level24_83C6CField(private16, int*, 0xC))) {
                owner17->lowDrawDistance = 0x20;
                owner17->state = 5;
                return;
            }
            break;
        case 0x5:
            helperResult16 = Level24_83C6CProbeGroundFromRaisedMoby(owner17);
            oldPositionZ = owner17->position.z;
            if ((oldPositionZ - helperResult16) < 0xC00) {
                Level24_83C6CRequestMobyAnimation(owner17, 0xB);
                nextPositionZ = owner17->position.z - 0x1E;
            } else {
                nextPositionZ = oldPositionZ - 0xA0;
            }
            owner17->position.z = nextPositionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            if (helperResult16 >= owner17->position.z) {
                owner17->position.z = helperResult16;
                Level24_83C6CRequestMobyAnimation(owner17, 0xC);
                owner17->state = 6;
                return;
            }
            break;
        case 0x6:
            if (Level24_83C6C_D_8006C770 != 0) {
                Level24_83C6CRequestMobyAnimation(owner17, 7);
                owner17->state = 7;
                return;
            }
            break;
        case 0x7:
            if (Level24_83C6CUpdateMobyPathMotion(owner17, Level24_83C6CField(private16, int*, 0),
                                                  0x80, 0x96, 0, 1, 0x20, 1) &
                2) {
                Level24_83C6CRequestMobyAnimation(owner17, 3);
                nextSubstate2 = Level24_83C6C_D_8006C7C4;
                if (nextSubstate2) {
                    nextSubstate2 = 1;
                } else {
                    nextSubstate2 = 3;
                }
                owner17->substate = nextSubstate2;
                owner17->state = 8;
                return;
            }
            break;
        case 0x8:
            if (!Level24_83C6C_D_8006C770)
                goto done;
            decrementedSubstate = owner17->substate - 1;
            owner17->substate = decrementedSubstate;
            helperVector4 = owner17;
            if (decrementedSubstate & 255)
                goto done;
        resetToState2:
            Level24_83C6CRequestMobyAnimation((Moby*)helperVector4, 5);
            owner17->state = 2;
            goto done;
        case 0x48:
            if (Level24_83C6C_D_8006C770)
                Level24_83C6CRequestMobyAnimation(owner17, 9);
            owner17->position.z += Level24_83C6CField(private16, short*, 4);
            Level24_83C6CField(private16, short*, 4) =
                (short)((unsigned short)Level24_83C6CField(private16, short*, 4) - 10);
            if (!Level24_83C6CResolveMobyHeadingStep(
                    owner17, owner17->unkb, Level24_83C6CField(private16, short*, 6), 0, 500, 1))
                goto updateState72Substate;
            vectorAddress2 = &Level24_83C6C_D_80071920;
            MATCHING_KEEP(vectorAddress2);
            helperVector4 = (unsigned char*)vectorAddress2 - 8;
            MATCHING_KEEP(helperVector4);
            magnitudeOrPredicate16 = *vectorAddress2;
            if (magnitudeOrPredicate16 < 0)
                magnitudeOrPredicate16 = -magnitudeOrPredicate16;
            magnitudeOrPredicate16 = magnitudeOrPredicate16 <
                                     Level24_83C6CMeasureVectorLength((Vector3D*)helperVector4, 0);
            MATCHING_KEEP(magnitudeOrPredicate16);
            if (magnitudeOrPredicate16)
                goto runFinalCallbacks;
            Level24_83C6CRequestMobyAnimation(owner17, 10);
            owner17->state = 71;
        updateState72Substate:
            oldSubstate72 = owner17->substate;
            owner17->substate = oldSubstate72 + 255;
            if (oldSubstate72)
                goto done;
            if (owner17->state != 72)
                goto done;
            goto resetToState71;
        case 0x46:
            if (Level24_83C6C_D_8006C770)
                Level24_83C6CRequestMobyAnimation(owner17, 9);
            owner17->position.z += Level24_83C6CField(private16, short*, 4);
            Level24_83C6CField(private16, short*, 4) =
                (short)((unsigned short)Level24_83C6CField(private16, short*, 4) - 10);
            Level24_83C6CResolveMobyHeadingStep(owner17, (owner17->angle.yaw + 128) & 255,
                                                Level24_83C6CField(private16, short*, 6), 0, 0, 0);
            oldSubstate70 = owner17->substate;
            owner17->substate = oldSubstate70 + 255;
            if (!oldSubstate70)
                goto resetToState71;
            if (owner17->position.z < 8192)
                goto resetToState71;
            if (owner17->position.x < 1024)
                goto resetToState71;
            if (owner17->position.y >= 1024)
                goto done;
        resetToState71:
            Level24_83C6CRequestMobyAnimation(owner17, 10);
            owner17->state = 71;
            goto done;
        case 0x47:
            if (!Level24_83C6C_D_8006C770)
                goto done;
        runFinalCallbacks:
            Level24_83C6CRefreshMobySpatialGridAndBasis(owner17, 4);
            Level24_83C6CMarkMobyCollectionBit(owner17);
            Level24_83C6CEmitMobyVertexParticles(owner17, 48);
            Level24_83C6CDeleteMoby(owner17);
            goto done;
    }
done:;
}
#undef Level24_83C6CField

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
void func_level_24_80084240(void* input) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80085394.
* Assembly SHA256 045c78770076d0fbee0b58cca17244b7dc6ff1ce1a70623fcb2a2785f84d7b55.
* AI generated; not human reviewed. All1403 original instructions and six
* original selector words and actual targets are required. Frame0x1A0
* retains S0..S5/RA and the original SP20..17F local extent. State0 and
* state1 branches retain their exact destinations, including skips over
* stack-address producers already executed in branch delay slots.
* Both rescale predicates, complete low32-bit products, signed16 clamps,
* independent halfword reloads and trig shifts retain native word order.
* Physical shared state1 entry remains after state5, with the original
* random masks, timer arithmetic, record store and shared call arguments.
* Raw units/fixed point, full helper contracts, caller cadence and
* synchronized retail runtime remain unresolved. Cadence is per invocation.
* Empty initialized identities, late consumers and dead clobbers emit no
* CPU instructions. Tags identify scheduling sites, not retail addresses.
* No partial HI input, overlapping live aliases, FP shortcut or opcode
* assembly is used. Confidence is binary identity after all gates.
* Falsification: every native/linked instruction, actual transfer/table
* target, original data byte, EXE and every overlay hash must match. */
#define Actor24_85394Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor24_85394QueryWorldHeightView1() __asm__("func_8001A358");
int Actor24_85394RequestMobyAnimationView1() __asm__("func_80034F40");
int Actor24_85394UpdateMobyBallisticMotionView1() __asm__("func_80035030");
int Actor24_85394EmptyAnimationTransitionHookView1() __asm__("func_80035734");
int Actor24_85394TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor24_85394CountTimerDownView1() __asm__("func_800359A4");
int Actor24_85394ProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Actor24_85394ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Actor24_85394BlendBoundedAngle8StepView1() __asm__("func_800360F8");
int Actor24_85394RandSignedBetweenView1() __asm__("func_800363DC");
int Actor24_85394EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Actor24_85394PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor24_85394TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Actor24_85394SoundHandleMatchesOwnerInStates1Or2View1() __asm__("func_8003BFC0");
int Actor24_85394PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor24_85394MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Actor24_85394ComputeVectorPlaneResponseView1() __asm__("func_8004EF74");
int Actor24_85394ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Actor24_85394ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Actor24_85394CopyVectorView1() __asm__("func_8004F178");
int Actor24_85394AddVectorView1() __asm__("func_8004F194");
int Actor24_85394SubtractVectorView1() __asm__("func_8004F1C8");
int Actor24_85394ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor24_85394DeleteMobyView1() __asm__("func_80055B18");
int Actor24_85394RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor24_85394CallrandView1() __asm__("rand");
extern int Actor24_85394Data658A0View1 __asm__("D_800658A0");
extern int Actor24_85394Data65920View1 __asm__("D_80065920");
extern int Actor24_85394Data6C550View1 __asm__("D_8006C550");
extern int Actor24_85394Data6C770View1 __asm__("D_8006C770");
extern int Actor24_85394Data70328View1 __asm__("D_80070328");
extern int Actor24_85394Data71918View1 __asm__("D_80071918");
extern int Actor24_85394Data71920View1 __asm__("D_80071920");
extern void* (*Actor24_85394DataSpawnMobyView1)() __asm__("SpawnMoby");
void func_level_24_80085394(void* input) {
    register void* ownerRecord19 __asm__("$19");
    register int retainedWordOrAddress16 __asm__("$16"), retainedWordOrAddress17 __asm__("$17"),
        retainedDistanceOrFlags18 __asm__("$18"), privateRecord20 __asm__("$20"),
        retainedShiftOrAddress21 __asm__("$21");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC, spF0, spF4, spF8, spFC,
            sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C, sp120, sp124, sp128, sp12C,
            sp130, sp134, sp138, sp13C, sp140, sp144, sp148, sp14C, sp150, sp154, sp158, sp15C,
            sp160, sp164, sp168, sp16C, sp170, sp174, sp178, sp17C;
    } originalFrame;
    int firstCompleteLowProduct;
    int secondCompleteLowProduct;
    ownerRecord19 = input;
    MATCHING_KEEP(ownerRecord19);
    rawWord3 = 3;
    rawWord2 = Actor24_85394Field(ownerRecord19, unsigned char*, 0x48);
    privateRecord20 = (int)Actor24_85394Field(ownerRecord19, void**, 0);
    if ((rawWord2 == rawWord3) || (Actor24_85394Field(ownerRecord19, unsigned char*, 0x4D) != 0)) {
        if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x49) == 0) {
            Actor24_85394Field(ownerRecord19, unsigned char*, 0x49) = 1U;
            rawWord2 = Actor24_85394ProbeGroundFromRaisedMobyView1(ownerRecord19) +
                       Actor24_85394Field(ownerRecord19, short*, 0x38);
            Actor24_85394Field(ownerRecord19, int*, 0x14) = rawWord2;
            Actor24_85394Field(privateRecord20, int*, 8) = rawWord2;
        }
        if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) != 1) {
            if (Actor24_85394SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord19, Actor24_85394Field(privateRecord20, int*, 0x24)) != 0) {
                Actor24_85394TransitionSoundHandleTo3Or5View1(
                    Actor24_85394Field(privateRecord20, int*, 0x24));
                Actor24_85394Field(privateRecord20, int*, 0x24) = -1;
            }
        }
        if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) != 3) {
            rawWord3 = Actor24_85394Field(ownerRecord19, int*, 0x18);
            if (rawWord3 & 0x10000) {
                Actor24_85394Field(privateRecord20, int*, 0x1C) = 0xFA;
                rawWord2 = Actor24_85394Field(ownerRecord19, unsigned char*, 0x51);
                argumentWord6 = 0;
                if (rawWord2 == 0) {
                    MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                    rawWord2 = Actor24_85394BlendBoundedAngle8StepView1(
                        Actor24_85394PlanarHeadingLookupView1(
                            Actor24_85394Field(ownerRecord19, int*, 0xC) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 0),
                            Actor24_85394Field(ownerRecord19, int*, 0x10) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 4),
                            argumentWord6),
                        Actor24_85394Field(((void*)&Actor24_85394Data70328View1), unsigned char*,
                                           0xE),
                        0x20, 0x40);
                }
                Actor24_85394Field(privateRecord20, int*, 0x18) = (int)rawWord2;
                Actor24_85394Field(privateRecord20, int*, 0x20) = 0xA4;
                rawWord2 = Actor24_85394Field(ownerRecord19, int*, 0x18);
                rawWord2 &= 0x100000;
                argumentWord4 = 16;
                if (rawWord2) {
                    Actor24_85394Field(privateRecord20, int*, 0x1C) =
                        (int)(Actor24_85394Field(privateRecord20, int*, 0x1C) + 0x64);
                    Actor24_85394Field(privateRecord20, int*, 0x20) =
                        (int)(Actor24_85394Field(privateRecord20, int*, 0x20) + 0x50);
                }
                rawWord2 = (int)Actor24_85394DataSpawnMobyView1;
                argumentWord5 = (int)ownerRecord19;
                goto callSharedSpawnHelper;
            }
            if (rawWord3 != 0) {
                Actor24_85394Field(privateRecord20, int*, 0x1C) = 0x12C;
                rawWord2 = Actor24_85394Field(ownerRecord19, unsigned char*, 0x51);
                if (rawWord2 == 0) {
                    MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                    rawWord2 = Actor24_85394BlendBoundedAngle8StepView1(
                        Actor24_85394PlanarHeadingLookupView1(
                            Actor24_85394Field(ownerRecord19, int*, 0xC) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 0),
                            Actor24_85394Field(ownerRecord19, int*, 0x10) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 4),
                            0),
                        Actor24_85394Field(((void*)&Actor24_85394Data70328View1), unsigned char*,
                                           0xE),
                        0x20, 0x40);
                }
                argumentWord4 = 16;
                argumentWord5 = (int)ownerRecord19;
                Actor24_85394Field(privateRecord20, int*, 0x18) = rawWord2;
                rawWord2 = (int)Actor24_85394DataSpawnMobyView1;
                rawWord3 = 164;
                Actor24_85394Field(privateRecord20, int*, 0x20) = rawWord3;
            callSharedSpawnHelper:
                ((void* (*)())rawWord2)(argumentWord4, argumentWord5);
                argumentWord4 = (int)ownerRecord19;
                argumentWord5 = 3;
                __asm__ __volatile__("" ::"r"(argumentWord4), "r"(argumentWord5) : "$2", "memory");
                rawWord2 = 3;
                Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
                Actor24_85394RequestMobyAnimationView1(argumentWord4, argumentWord5);
            }
        }
        rawWord3 = Actor24_85394Field(ownerRecord19, unsigned char*, 0x48);
        switch (rawWord3) {
            case 0:
                rawWord2 = Actor24_85394CountTimerDownView1(privateRecord20 + 0x14, 2);
                argumentWord4 = (int)&originalFrame.sp20;
                if (rawWord2 == 0)
                    goto state0CommonVectorReady;
                {
                    rawWord3 = Actor24_85394Field(privateRecord20, int*, 0xC);
                    MATCHING_KEEP_CLOBBER(rawWord3, "$21");
                    retainedShiftOrAddress21 = 3;
                    if (rawWord3 >= 0) {
                        Actor24_85394SubtractVectorView1(&originalFrame.sp40,
                                                         Actor24_85394Data6C550View1 +
                                                             (rawWord3 * 0x58) + 0xC,
                                                         ownerRecord19 + 0xC);
                        originalFrame.sp48 = 0;
                        retainedDistanceOrFlags18 =
                            Actor24_85394MeasureVectorLengthView1(&originalFrame.sp40, 0) >> 3;
                        if (retainedDistanceOrFlags18 < 0x60) {
                            rawWord2 = Actor24_85394CallrandView1();
                            retainedWordOrAddress16 = (int)&originalFrame.sp50;
                            if (rawWord2 & 1) {
                                MATCHING_OBSERVE_GNU_VOLATILE(retainedWordOrAddress16);
                                rawWord2 = Actor24_85394CallrandView1();
                                rawWord2 &= 127;
                                rawWord2 += 60;
                                Actor24_85394Field(privateRecord20, short*, 0x14) = rawWord2;
                                __asm__ __volatile__("" ::"i"(140301) : "memory");
                                rawWord2 = 4;
                                goto storeSharedState;
                            }
                            goto firstVectorAddressReady;
                        }
                    prepareFirstVectorAddress:
                        MATCHING_BARRIER_GNU_VOLATILE("$16");
                        retainedWordOrAddress16 = (int)&originalFrame.sp50;
                    firstVectorAddressReady:
                        Actor24_85394SubtractVectorView1(retainedWordOrAddress16, privateRecord20,
                                                         ownerRecord19 + 12);
                        originalFrame.sp58 = 0;
                        rawWord2 =
                            Actor24_85394MeasureVectorLengthView1(retainedWordOrAddress16, 0);
                        MATCHING_KEEP(retainedShiftOrAddress21);
                        rawWord2 >>= retainedShiftOrAddress21;
                        rawWord2 = rawWord2 < 1025;
                        if (!rawWord2)
                            goto rescaleAEnter;
                        rawWord2 = retainedDistanceOrFlags18 < 1025;
                        if (rawWord2) {
                            rawWord2 = retainedDistanceOrFlags18 < 65;
                            goto rescaleACheck;
                        }
                    rescaleAEnter:
                        Actor24_85394Field(privateRecord20, short*, 0x12) = 0;
                        Actor24_85394Field(privateRecord20, short*, 0x10) =
                            (short)((Actor24_85394CallrandView1() & 0xFF) + 0x200);
                        if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) != 1) {
                            Actor24_85394Data6C770View1 = 0;
                            Actor24_85394Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) = 1U;
                            Actor24_85394Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor24_85394EmptyAnimationTransitionHookView1(ownerRecord19);
                        }
                        Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = 5U;
                        rawWord2 = retainedDistanceOrFlags18 < 65;
                    rescaleACheck:
                        argumentWord6 = retainedDistanceOrFlags18;
                        if (rawWord2 == 0) {
                        loop_34:
                            firstCompleteLowProduct = argumentWord6 * argumentWord6;
                            if (argumentWord6 >= 0x41) {
                                retainedDistanceOrFlags18 = retainedDistanceOrFlags18 >> 1;
                                argumentWord6 = argumentWord6 >> 1;
                                retainedShiftOrAddress21 += 1;
                                if (retainedDistanceOrFlags18 < 0x41) {
                                    goto block_36;
                                }
                                goto loop_34;
                            }
                        } else {
                        block_36:
                            firstCompleteLowProduct = argumentWord6 * argumentWord6;
                        }
                        retainedWordOrAddress17 = (int)&originalFrame.sp40;
                        argumentWord4 = retainedWordOrAddress17;
                        argumentWord5 = retainedDistanceOrFlags18;
                        MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$6");
                        argumentWord6 = firstCompleteLowProduct;
                        MATCHING_KEEP(argumentWord6);
                        argumentWord6 >>= 4;
                        Actor24_85394ScaleVectorRatioQ15View1(argumentWord4, argumentWord5,
                                                              argumentWord6);
                        Actor24_85394ShiftVectorRightTowardZeroView1(&originalFrame.sp50,
                                                                     retainedShiftOrAddress21 + 4);
                        Actor24_85394AddVectorView1(&originalFrame.sp40, &originalFrame.sp40,
                                                    &originalFrame.sp50);
                        if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) == 5) {
                            Actor24_85394Field(privateRecord20, int*, 0x18) =
                                Actor24_85394PlanarHeadingLookupView1(originalFrame.sp40,
                                                                      originalFrame.sp44, 0);
                        } else {
                            retainedWordOrAddress16 = Actor24_85394PlanarHeadingLookupView1(
                                originalFrame.sp40, originalFrame.sp44, 0);
                            Actor24_85394Field(privateRecord20, int*, 0x18) =
                                (int)(((retainedWordOrAddress16 +
                                        (Actor24_85394CallrandView1() & 0x1F)) -
                                       0x10) &
                                      0xFF);
                        }
                        Actor24_85394Field(privateRecord20, short*, 0x14) =
                            (short)((Actor24_85394CallrandView1() & 0x7F) + 0x3C);
                    } else {
                        rawWord2 = Actor24_85394CallrandView1(&originalFrame.sp20);
                        retainedWordOrAddress16 = (int)&originalFrame.sp60;
                        if (!(rawWord2 & 7)) {
                            MATCHING_OBSERVE_GNU_VOLATILE(retainedWordOrAddress16);
                            Actor24_85394Field(privateRecord20, short*, 0x14) =
                                (short)((Actor24_85394CallrandView1() & 0x7F) + 0x3C);
                            rawWord2 = 4;
                            goto storeSharedState;
                        }
                        argumentWord4 = retainedWordOrAddress16;
                        argumentWord5 = privateRecord20;
                        MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$17");
                        retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                        Actor24_85394SubtractVectorView1(argumentWord4, argumentWord5,
                                                         retainedWordOrAddress17);
                        originalFrame.sp68 = 0;
                        Actor24_85394ShiftVectorRightTowardZeroView1(&originalFrame.sp60, 3);
                        originalFrame.sp70 =
                            (int)(Actor24_85394Field(((void*)&Actor24_85394Data65920View1), short*,
                                                     ((Actor24_85394CallrandView1() & 0xFF) * 2)) *
                                  5) >>
                            2;
                        rawWord3 = Actor24_85394Field(((void*)&Actor24_85394Data658A0View1), short*,
                                                      ((Actor24_85394CallrandView1() & 0xFF) * 2));
                        originalFrame.sp78 = 0;
                        originalFrame.sp74 = (int)(rawWord3 * 5) >> 2;
                        Actor24_85394AddVectorView1(&originalFrame.sp70, &originalFrame.sp70,
                                                    &originalFrame.sp60);
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            Actor24_85394PlanarHeadingLookupView1(originalFrame.sp70,
                                                                  originalFrame.sp74, 0);
                        Actor24_85394Field(privateRecord20, short*, 0x14) =
                            (short)((Actor24_85394CallrandView1() & 0x7F) + 0x3C);
                        if ((Actor24_85394ApproximatePlanarDistanceView1(
                                 retainedWordOrAddress17, privateRecord20) >= 0x2001) &&
                            !(Actor24_85394CallrandView1() & 3)) {
                            Actor24_85394Field(privateRecord20, short*, 0x12) = 0;
                            Actor24_85394Field(privateRecord20, short*, 0x10) =
                                (short)((Actor24_85394CallrandView1(&originalFrame.sp20) & 0xFF) +
                                        0x200);
                            if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) != 1) {
                                Actor24_85394Data6C770View1 = 0;
                                Actor24_85394Field(ownerRecord19, signed char*, 0x40) = 0x72;
                                Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) = 1U;
                                Actor24_85394Field(ownerRecord19, signed char*, 0x3F) = 0;
                                Actor24_85394EmptyAnimationTransitionHookView1(ownerRecord19);
                            }
                            rawWord2 = 5;
                        storeSharedState:
                            Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
                        }
                    }
                }
                argumentWord4 = (int)&originalFrame.sp20;
            state0CommonVectorReady:
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$18");
                retainedDistanceOrFlags18 = (int)ownerRecord19 + 12;
                Actor24_85394CopyVectorView1(argumentWord4, retainedDistanceOrFlags18);
                Actor24_85394TurnMobyTowardHeadingView1(
                    ownerRecord19, Actor24_85394Field(privateRecord20, int*, 0x18), 6, 0, 0, 0);
                originalFrame.sp30 =
                    (int)(Actor24_85394Field(
                              ((void*)&Actor24_85394Data65920View1), short*,
                              (Actor24_85394Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.sp34 =
                    (int)(Actor24_85394Field(
                              ((void*)&Actor24_85394Data658A0View1), short*,
                              (Actor24_85394Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.sp38 = 0;
                Actor24_85394AddVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                            retainedDistanceOrFlags18);
                originalFrame.sp38 = Actor24_85394Field(ownerRecord19, int*, 0x14) + 0x100;
                rawWord2 = Actor24_85394QueryWorldHeightView1(&originalFrame.sp30, 0x400);
                originalFrame.sp38 = rawWord2;
                rawWord3 = Actor24_85394Field(ownerRecord19, int*, 0x14);
                if ((rawWord3 - rawWord2) < 0x100) {
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 100;
                    argumentWord6 = 300;
                    argumentWord7 = 1000;
                    __asm__(""
                            : "=r"(rawWord3)
                            : "0"(rawWord3), "r"(argumentWord4), "r"(argumentWord5),
                              "r"(argumentWord6), "r"(argumentWord7));
                    rawWord2 = rawWord3 + 256;
                    Actor24_85394Field(ownerRecord19, int*, 0x14) = rawWord2;
                    rawWord2 = 50;
                    retainedWordOrAddress17 = Actor24_85394ResolveMobyYawStepView1(
                        argumentWord4, argumentWord5, argumentWord6, argumentWord7, rawWord2);
                    if (retainedWordOrAddress17 & 0x10) {
                        Actor24_85394SubtractVectorView1(
                            &originalFrame.sp80, retainedDistanceOrFlags18, &originalFrame.sp20);
                        argumentWord5 =
                            Actor24_85394MeasureVectorLengthView1(&originalFrame.sp80, 1);
                        argumentWord4 = privateRecord20 + 0x16;
                        if (argumentWord5 >= 0x65) {
                            Actor24_85394ScaleVectorRatioQ15View1(&originalFrame.sp80,
                                                                  argumentWord5, 0x64);
                            Actor24_85394AddVectorView1(retainedDistanceOrFlags18,
                                                        &originalFrame.sp80, &originalFrame.sp20);
                            MATCHING_KEEP(privateRecord20);
                            argumentWord4 = privateRecord20 + 0x16;
                        }
                    } else {
                        goto block_55;
                    }
                } else {
                    retainedWordOrAddress17 = 0;
                block_55:
                    argumentWord4 = privateRecord20 + 0x16;
                }
                if (Actor24_85394CountTimerDownView1(argumentWord4, 2) != 0) {
                    Actor24_85394SubtractVectorView1(&originalFrame.sp90, ownerRecord19 + 0xC,
                                                     &originalFrame.sp20);
                    argumentWord4 = originalFrame.sp90;
                    argumentWord5 = originalFrame.sp94;
                    rawWord2 = argumentWord4;
                    if (argumentWord4 < 0) {
                        MATCHING_KEEP(rawWord2);
                        rawWord2 = -rawWord2;
                    }
                    rawWord3 = argumentWord5;
                    if (argumentWord5 < 0) {
                        MATCHING_KEEP(rawWord3);
                        rawWord3 = -rawWord3;
                    }
                    rawWord3 = rawWord2 + rawWord3;
                    if (rawWord3 < 8) {
                        Actor24_85394Field(privateRecord20, short*, 0x16) = 0x3C;
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            (int)((Actor24_85394Field(privateRecord20, int*, 0x18) + 0x80) & 0xFF);
                        goto block_79;
                    }
                    if (({
                            rawWord2 = rawWord3 < 32;
                            MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
                            rawWord2;
                        })) {
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            Actor24_85394PlanarHeadingLookupView1(originalFrame.sp90,
                                                                  originalFrame.sp94, 0);
                        Actor24_85394Field(privateRecord20, short*, 0x16) = 5;
                    } else if (({
                                   rawWord2 = retainedWordOrAddress17 & 2;
                                   MATCHING_OBSERVE_GNU_VOLATILE(retainedWordOrAddress17);
                                   rawWord2;
                               })) {
                        retainedWordOrAddress16 = (int)&Actor24_85394Data71918View1;
                        MATCHING_KEEP(retainedWordOrAddress16);
                        argumentWord4 = Actor24_85394Field(retainedWordOrAddress16, int*, 0);
                        rawWord3 = Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                        rawWord2 = Actor24_85394Data71920View1;
                        if (argumentWord4 < 0) {
                            argumentWord4 = -argumentWord4;
                        }
                        if (rawWord3 < 0)
                            rawWord3 = -rawWord3;
                        argumentWord4 += rawWord3;
                        MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                        if (rawWord2 < 0)
                            rawWord2 = -rawWord2;
                        if ((rawWord2 >> 1) < argumentWord4) {
                            argumentWord4 = (int)&originalFrame.sp90;
                            MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "memory");
                            rawWord2 = Actor24_85394Field(privateRecord20, int*, 0x18);
                            rawWord2 = (unsigned int)rawWord2 << 1;
                            rawWord2 =
                                Actor24_85394Field(&Actor24_85394Data65920View1, short*, rawWord2);
                            MATCHING_KEEP(rawWord2);
                            rawWord2 >>= 5;
                            originalFrame.sp90 = rawWord2;
                            __asm__ __volatile__("" ::: "$5", "memory");
                            rawWord2 = Actor24_85394Field(privateRecord20, int*, 0x18);
                            argumentWord5 = retainedWordOrAddress16;
                            rawWord2 = (unsigned int)rawWord2 << 1;
                            rawWord2 =
                                Actor24_85394Field(&Actor24_85394Data658A0View1, short*, rawWord2);
                            __asm__ __volatile__("" ::: "$6", "memory");
                            argumentWord6 = argumentWord4;
                            originalFrame.sp98 = 0;
                            __asm__ __volatile__(""
                                                 : "=r"(rawWord2)
                                                 : "0"(rawWord2), "m"(originalFrame.sp98)
                                                 : "memory");
                            rawWord2 >>= 5;
                            originalFrame.sp94 = rawWord2;
                            rawWord2 = Actor24_85394ComputeVectorPlaneResponseView1(
                                argumentWord4, argumentWord5, argumentWord6);
                            if (rawWord2 != 0) {
                                Actor24_85394Field(privateRecord20, int*, 0x18) =
                                    Actor24_85394PlanarHeadingLookupView1(originalFrame.sp90,
                                                                          originalFrame.sp94, 0);
                                rawWord2 = (short)(5);
                                goto block_78;
                            }
                            MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                            argumentWord4 = Actor24_85394Field(retainedWordOrAddress16, int*, 0);
                            if (argumentWord4 != 0 || ({
                                    rawWord2 = Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                                    rawWord2 != 0;
                                })) {
                                MATCHING_KEEP(retainedWordOrAddress16);
                                argumentWord5 =
                                    Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                                argumentWord6 = 0;
                                rawWord2 = Actor24_85394PlanarHeadingLookupView1(
                                    argumentWord4, argumentWord5, argumentWord6);
                                Actor24_85394Field(privateRecord20, int*, 0x18) = rawWord2;
                                rawWord2 = (short)(0x3C);
                            block_78:
                                Actor24_85394Field(privateRecord20, short*, 0x16) = rawWord2;
                            }
                        block_79:
                            Actor24_85394Field(privateRecord20, short*, 0x14) =
                                (short)((Actor24_85394CallrandView1() & 0x3F) + 0x1E);
                        }
                    }
                }
                rawWord2 = Actor24_85394ProbeGroundFromRaisedMobyView1(ownerRecord19) +
                           Actor24_85394Field(ownerRecord19, short*, 0x38);
                Actor24_85394Field(ownerRecord19, int*, 0x14) = rawWord2;
                rawWord2 = rawWord2 - originalFrame.sp28;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                argumentWord4 = ownerRecord19 + 0xC;
                if (rawWord2 >= 0x81) {
                    Actor24_85394CopyVectorView1(argumentWord4, &originalFrame.sp20);
                    MATCHING_KEEP(ownerRecord19);
                    argumentWord4 = ownerRecord19 + 0xC;
                }
                if (Actor24_85394ApproximatePlanarDistanceView1(
                        argumentWord4, ((void*)&Actor24_85394Data70328View1)) < 0x1000) {
                    Actor24_85394Field(privateRecord20, int*, 0x18) =
                        Actor24_85394PlanarHeadingLookupView1(
                            Actor24_85394Field(ownerRecord19, int*, 0xC) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 0),
                            Actor24_85394Field(ownerRecord19, int*, 0x10) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 4),
                            0);
                    Actor24_85394Field(privateRecord20, short*, 0x14) =
                        (short)((Actor24_85394CallrandView1() & 0x3F) + 0x1E);
                    Actor24_85394Field(privateRecord20, short*, 0x12) = 0;
                    rawWord2 = Actor24_85394CallrandView1();
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 1;
                    rawWord2 &= 127;
                    MATCHING_KEEP(rawWord2);
                    rawWord2 += 384;
                    goto storeTimerAndEnterState1;
                }
                break;
            case 4:
                if (Actor24_85394CountTimerDownView1(privateRecord20 + 0x14, 2) != 0) {
                    Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    return;
                }
                break;
            case 1:
                rawWord2 = Actor24_85394SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord19, Actor24_85394Field(privateRecord20, int*, 0x24));
                if (rawWord2 != 0) {
                    retainedShiftOrAddress21 = (int)&originalFrame.sp60;
                    goto state1VectorAddressReady;
                }
                MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                Actor24_85394Field(privateRecord20, int*, 0x24) =
                    Actor24_85394PlayMobySoundEventView1(ownerRecord19, 0, 4);
                retainedShiftOrAddress21 = (int)&originalFrame.sp60;
            state1VectorAddressReady:
                argumentWord4 = retainedShiftOrAddress21;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                Actor24_85394Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor24_85394Field(ownerRecord19, int*, 0x14) -
                          Actor24_85394Field(privateRecord20, short*, 0x12));
                Actor24_85394CopyVectorView1(argumentWord4, retainedWordOrAddress17);
                Actor24_85394TurnMobyTowardHeadingView1(
                    ownerRecord19, Actor24_85394Field(privateRecord20, int*, 0x18), 6, 0, 0, 0);
                originalFrame.spA0 =
                    (int)(Actor24_85394Field(
                              ((void*)&Actor24_85394Data65920View1), short*,
                              (Actor24_85394Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spA4 =
                    (int)(Actor24_85394Field(
                              ((void*)&Actor24_85394Data658A0View1), short*,
                              (Actor24_85394Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spA8 = 0;
                Actor24_85394AddVectorView1(&originalFrame.spA0, &originalFrame.spA0,
                                            retainedWordOrAddress17);
                originalFrame.spA8 = Actor24_85394Field(ownerRecord19, int*, 0x14) + 0x100;
                rawWord2 = Actor24_85394QueryWorldHeightView1(&originalFrame.spA0, 0x400);
                originalFrame.spA8 = rawWord2;
                if ((Actor24_85394Field(ownerRecord19, int*, 0x14) - rawWord2) < 0x100) {
                    retainedDistanceOrFlags18 = Actor24_85394ResolveMobyYawStepView1(
                        ownerRecord19, 0x91, 0x12C, 0x3E8, 0x36);
                    if (retainedDistanceOrFlags18 & 0x10) {
                        Actor24_85394SubtractVectorView1(
                            &originalFrame.spB0, retainedWordOrAddress17, retainedShiftOrAddress21);
                        argumentWord5 =
                            Actor24_85394MeasureVectorLengthView1(&originalFrame.spB0, 1);
                        if (argumentWord5 >= 0x92) {
                            Actor24_85394ScaleVectorRatioQ15View1(&originalFrame.spB0,
                                                                  argumentWord5, 0x91);
                            Actor24_85394AddVectorView1(retainedWordOrAddress17,
                                                        &originalFrame.spB0,
                                                        retainedShiftOrAddress21);
                        }
                    }
                } else {
                    retainedDistanceOrFlags18 = 0;
                }
                argumentWord5 = Actor24_85394Field(privateRecord20, short*, 0x12);
                argumentWord4 = Actor24_85394Field(privateRecord20, short*, 0x10);
                rawWord2 = argumentWord5 < argumentWord4;
                rawWord3 = argumentWord5;
                if (!rawWord2)
                    goto clamp0Reduce;
                rawWord2 = rawWord3 + 10;
                Actor24_85394Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor24_85394Field(privateRecord20, short*, 0x10);
                argumentWord4 = rawWord3;
                rawWord3 = rawWord3 < rawWord2;
                if (!rawWord3)
                    goto clamp0Done;
                Actor24_85394Field(privateRecord20, short*, 0x12) = argumentWord4;
                goto clamp0Done;
            clamp0Reduce:
                rawWord2 = argumentWord4 < argumentWord5;
                if (!rawWord2)
                    goto clamp0Done;
                rawWord2 = rawWord3 - 10;
                Actor24_85394Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor24_85394Field(privateRecord20, short*, 0x10);
                rawWord2 = rawWord2 < rawWord3;
                argumentWord4 = rawWord3;
                if (!rawWord2)
                    goto clamp0Done;
                Actor24_85394Field(privateRecord20, short*, 0x12) = argumentWord4;
            clamp0Done:
                if (Actor24_85394CountTimerDownView1(privateRecord20 + 0x16, 2) != 0) {
                    argumentWord4 = (int)&originalFrame.spC0;
                    __asm__ __volatile__(""
                                         : "=r"(retainedShiftOrAddress21)
                                         : "0"(retainedShiftOrAddress21), "r"(argumentWord4)
                                         : "$6", "memory");
                    Actor24_85394SubtractVectorView1(argumentWord4, ownerRecord19 + 12,
                                                     &originalFrame.sp60);
                    argumentWord4 = originalFrame.spC0;
                    argumentWord5 = originalFrame.spC4;
                    rawWord2 = argumentWord4;
                    if (argumentWord4 < 0) {
                        MATCHING_KEEP(rawWord2);
                        rawWord2 = -rawWord2;
                    }
                    rawWord3 = argumentWord5;
                    if (argumentWord5 < 0) {
                        MATCHING_KEEP(rawWord3);
                        rawWord3 = -rawWord3;
                    }
                    rawWord3 = rawWord2 + rawWord3;
                    if (rawWord3 < 8) {
                        Actor24_85394Field(privateRecord20, short*, 0x16) = 0x3C;
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            (int)((Actor24_85394Field(privateRecord20, int*, 0x18) + 0x80) & 0xFF);
                    } else {
                        if (({
                                rawWord2 = rawWord3 < 32;
                                MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
                                rawWord2;
                            })) {
                            rawWord2 = Actor24_85394PlanarHeadingLookupView1(originalFrame.spC0,
                                                                             originalFrame.spC4, 0);
                            Actor24_85394Field(privateRecord20, int*, 0x18) = rawWord2;
                            __asm__ __volatile__("" ::"i"(140320) : "memory");
                            rawWord2 = (short)(5);
                            goto block_123;
                        }
                        if (({
                                MATCHING_BARRIER_GNU_VOLATILE("$2");
                                rawWord2 = retainedDistanceOrFlags18 & 2;
                                MATCHING_OBSERVE_GNU_VOLATILE(retainedDistanceOrFlags18);
                                rawWord2;
                            })) {
                            retainedWordOrAddress16 = (int)&Actor24_85394Data71918View1;
                            MATCHING_KEEP(retainedWordOrAddress16);
                            argumentWord4 = Actor24_85394Field(retainedWordOrAddress16, int*, 0);
                            rawWord3 = Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                            rawWord2 = Actor24_85394Data71920View1;
                            if (argumentWord4 < 0) {
                                argumentWord4 = -argumentWord4;
                            }
                            if (rawWord3 < 0)
                                rawWord3 = -rawWord3;
                            argumentWord4 += rawWord3;
                            MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                            if (rawWord2 < 0)
                                rawWord2 = -rawWord2;
                            if ((rawWord2 >> 1) < argumentWord4) {
                                argumentWord4 = (int)&originalFrame.spC0;
                                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "memory");
                                rawWord2 = Actor24_85394Field(privateRecord20, int*, 0x18);
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor24_85394Field(&Actor24_85394Data65920View1, short*,
                                                              rawWord2);
                                MATCHING_KEEP(rawWord2);
                                rawWord2 >>= 5;
                                originalFrame.spC0 = rawWord2;
                                __asm__ __volatile__("" ::: "$5", "memory");
                                rawWord2 = Actor24_85394Field(privateRecord20, int*, 0x18);
                                argumentWord5 = retainedWordOrAddress16;
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor24_85394Field(&Actor24_85394Data658A0View1, short*,
                                                              rawWord2);
                                __asm__ __volatile__("" ::: "$6", "memory");
                                argumentWord6 = argumentWord4;
                                originalFrame.spC8 = 0;
                                __asm__ __volatile__(""
                                                     : "=r"(rawWord2)
                                                     : "0"(rawWord2), "m"(originalFrame.spC8)
                                                     : "memory");
                                rawWord2 >>= 5;
                                originalFrame.spC4 = rawWord2;
                                rawWord2 = Actor24_85394ComputeVectorPlaneResponseView1(
                                    argumentWord4, argumentWord5, argumentWord6);
                                if (rawWord2 != 0) {
                                    Actor24_85394Field(privateRecord20, int*, 0x18) =
                                        Actor24_85394PlanarHeadingLookupView1(
                                            originalFrame.spC0, originalFrame.spC4, 0);
                                    rawWord2 = (short)(5);
                                    goto block_123;
                                }
                                MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                                argumentWord4 =
                                    Actor24_85394Field(retainedWordOrAddress16, int*, 0);
                                if (argumentWord4 != 0 || ({
                                        rawWord2 =
                                            Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                                        rawWord2 != 0;
                                    })) {
                                    MATCHING_KEEP(retainedWordOrAddress16);
                                    argumentWord5 =
                                        Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                                    argumentWord6 = 0;
                                    rawWord2 = Actor24_85394PlanarHeadingLookupView1(
                                        argumentWord4, argumentWord5, argumentWord6);
                                    Actor24_85394Field(privateRecord20, int*, 0x18) = rawWord2;
                                    rawWord2 = (short)(0x3C);
                                block_123:
                                    Actor24_85394Field(privateRecord20, short*, 0x16) = rawWord2;
                                }
                            }
                        }
                    }
                }
                rawWord2 = Actor24_85394Field(ownerRecord19, int*, 0x14);
                rawWord3 = originalFrame.sp68;
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                argumentWord4 = privateRecord20 + 0x14;
                if (rawWord2 >= 0x81) {
                    __asm__ __volatile__(""
                                         : "=r"(retainedShiftOrAddress21)
                                         : "0"(retainedShiftOrAddress21)
                                         : "$5", "memory");
                    Actor24_85394CopyVectorView1(ownerRecord19 + 12, &originalFrame.sp60);
                    MATCHING_KEEP(privateRecord20);
                    argumentWord4 = privateRecord20 + 0x14;
                }
                Actor24_85394Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor24_85394Field(ownerRecord19, int*, 0x14) +
                          Actor24_85394Field(privateRecord20, short*, 0x12));
                if (Actor24_85394CountTimerDownView1(argumentWord4, 2) != 0) {
                    if (Actor24_85394ApproximatePlanarDistanceView1(
                            ownerRecord19 + 0xC, ((void*)&Actor24_85394Data70328View1)) >= 0x1801) {
                        Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                        Actor24_85394RequestMobyAnimationView1(ownerRecord19, 2);
                        return;
                    }
                    rawWord2 = Actor24_85394PlanarHeadingLookupView1(
                        Actor24_85394Field(ownerRecord19, int*, 0xC) -
                            Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 0),
                        Actor24_85394Field(ownerRecord19, int*, 0x10) -
                            Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 4),
                        0);
                    argumentWord4 = 32;
                    argumentWord5 = 64;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
                    retainedWordOrAddress16 = rawWord2;
                    rawWord2 = Actor24_85394RandSignedBetweenView1(argumentWord4, argumentWord5);
                    retainedWordOrAddress16 = (unsigned int)retainedWordOrAddress16 + rawWord2;
                    retainedWordOrAddress16 &= 255;
                    MATCHING_KEEP(retainedWordOrAddress16);
                    Actor24_85394Field(privateRecord20, int*, 0x18) = retainedWordOrAddress16;
                    Actor24_85394Field(privateRecord20, short*, 0x14) =
                        (short)((Actor24_85394CallrandView1() & 0x3F) + 0x1E);
                    Actor24_85394Field(privateRecord20, short*, 0x10) =
                        (short)((Actor24_85394CallrandView1() & 0x7F) + 0x180);
                    return;
                }
                break;
            case 2:
                rawWord3 = Actor24_85394Field(privateRecord20, short*, 0x12);
                rawWord2 = Actor24_85394Field(ownerRecord19, int*, 0x14);
                rawWord2 -= rawWord3;
                Actor24_85394Field(ownerRecord19, int*, 0x14) = rawWord2;
                rawWord3 = Actor24_85394Field(privateRecord20, short*, 0x12);
                rawWord2 = (unsigned int)rawWord3 << 1;
                rawWord2 += rawWord3;
                rawWord3 = Actor24_85394Data6C770View1;
                argumentWord4 = rawWord2 >> 2;
                Actor24_85394Field(privateRecord20, short*, 0x12) = argumentWord4;
                if (rawWord3 != 0) {
                    if (Actor24_85394ApproximatePlanarDistanceView1(ownerRecord19 + 0xC,
                                                                    privateRecord20) >= 0x2801) {
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            Actor24_85394PlanarHeadingLookupView1(
                                Actor24_85394Field(privateRecord20, int*, 0) -
                                    Actor24_85394Field(ownerRecord19, int*, 0xC),
                                Actor24_85394Field(privateRecord20, int*, 4) -
                                    Actor24_85394Field(ownerRecord19, int*, 0x10),
                                0);
                    } else {
                        rawWord2 = Actor24_85394CallrandView1();
                        argumentWord6 = 0;
                        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
                        retainedWordOrAddress16 = rawWord2;
                        argumentWord7 = Actor24_85394Field(privateRecord20, int*, 0);
                        argumentWord4 = Actor24_85394Field(ownerRecord19, int*, 0xC);
                        rawWord3 = Actor24_85394Field(privateRecord20, int*, 4);
                        argumentWord5 = Actor24_85394Field(ownerRecord19, int*, 0x10);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Actor24_85394PlanarHeadingLookupView1(
                            argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                        retainedWordOrAddress16 = (unsigned int)retainedWordOrAddress16 + rawWord2;
                        retainedWordOrAddress16 >>= 1;
                        retainedWordOrAddress16 &= 255;
                        MATCHING_KEEP(retainedWordOrAddress16);
                        Actor24_85394Field(privateRecord20, int*, 0x18) = retainedWordOrAddress16;
                    }
                    Actor24_85394Field(privateRecord20, short*, 0x14) =
                        (short)((Actor24_85394CallrandView1() & 0x7F) + 0x3C);
                    Actor24_85394Field(privateRecord20, short*, 0x12) = 0;
                    Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    Actor24_85394RequestMobyAnimationView1(ownerRecord19, 0);
                    return;
                }
                Actor24_85394Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor24_85394Field(ownerRecord19, int*, 0x14) + argumentWord4);
                return;
            case 5:
                rawWord2 = Actor24_85394CountTimerDownView1(privateRecord20 + 0x14, 2);
                retainedShiftOrAddress21 = (int)&originalFrame.spD0;
                if (rawWord2 == 0)
                    goto mode5VectorReady;
                rawWord3 = Actor24_85394Field(privateRecord20, int*, 0xC);
                retainedShiftOrAddress21 = 3;
                if (rawWord3 >= 0) {
                    retainedWordOrAddress16 = (int)&originalFrame.spF0;
                    argumentWord4 = retainedWordOrAddress16;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                    retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                    Actor24_85394SubtractVectorView1(
                        argumentWord4, Actor24_85394Data6C550View1 + rawWord3 * 88 + 12,
                        retainedWordOrAddress17);
                    originalFrame.spF8 = 0;
                    retainedDistanceOrFlags18 =
                        Actor24_85394MeasureVectorLengthView1(&originalFrame.spF0, 0) >> 3;
                    Actor24_85394SubtractVectorView1(&originalFrame.sp100, privateRecord20,
                                                     retainedWordOrAddress17);
                    originalFrame.sp108 = 0;
                    rawWord2 = Actor24_85394MeasureVectorLengthView1(&originalFrame.sp100, 0);
                    rawWord2 >>= 3;
                    rawWord2 = rawWord2 < 1024;
                    if (rawWord2)
                        goto rescaleBEnter;
                    rawWord2 = retainedDistanceOrFlags18 < 1024;
                    if (!rawWord2) {
                        rawWord2 = retainedDistanceOrFlags18 < 65;
                        goto rescaleBCheck;
                    }
                rescaleBEnter:
                    if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) != 2) {
                        Actor24_85394Data6C770View1 = 0;
                        Actor24_85394Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) = 2U;
                        Actor24_85394Field(ownerRecord19, signed char*, 0x3F) = 0;
                        Actor24_85394EmptyAnimationTransitionHookView1(ownerRecord19);
                    }
                    Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                    rawWord2 = retainedDistanceOrFlags18 < 65;
                rescaleBCheck:
                    argumentWord6 = retainedDistanceOrFlags18;
                    if (rawWord2 == 0) {
                    loop_146:
                        secondCompleteLowProduct = argumentWord6 * argumentWord6;
                        if (argumentWord6 >= 0x41) {
                            retainedDistanceOrFlags18 = retainedDistanceOrFlags18 >> 1;
                            argumentWord6 = argumentWord6 >> 1;
                            retainedShiftOrAddress21 += 1;
                            if (retainedDistanceOrFlags18 < 0x41) {
                                goto block_148;
                            }
                            goto loop_146;
                        }
                    } else {
                    block_148:
                        secondCompleteLowProduct = argumentWord6 * argumentWord6;
                    }
                    retainedWordOrAddress17 = (int)&originalFrame.spF0;
                    argumentWord4 = retainedWordOrAddress17;
                    argumentWord5 = retainedDistanceOrFlags18;
                    MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$6");
                    argumentWord6 = secondCompleteLowProduct;
                    MATCHING_KEEP(argumentWord6);
                    argumentWord6 >>= 4;
                    Actor24_85394ScaleVectorRatioQ15View1(argumentWord4, argumentWord5,
                                                          argumentWord6);
                    Actor24_85394ShiftVectorRightTowardZeroView1(&originalFrame.sp100,
                                                                 retainedShiftOrAddress21 + 4);
                    Actor24_85394AddVectorView1(&originalFrame.spF0, &originalFrame.spF0,
                                                &originalFrame.sp100);
                    Actor24_85394Field(privateRecord20, int*, 0x18) =
                        Actor24_85394PlanarHeadingLookupView1(originalFrame.spF0,
                                                              originalFrame.spF4, 0);
                    Actor24_85394Field(privateRecord20, short*, 0x14) =
                        (short)((Actor24_85394CallrandView1() & 0x7F) + 0x3C);
                    Actor24_85394Field(privateRecord20, short*, 0x10) =
                        (short)((Actor24_85394CallrandView1() & 0xFF) + 0x200);
                } else {
                    retainedWordOrAddress16 = (int)&originalFrame.sp110;
                    argumentWord4 = retainedWordOrAddress16;
                    argumentWord5 = privateRecord20;
                    MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$17");
                    retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                    Actor24_85394SubtractVectorView1(argumentWord4, argumentWord5,
                                                     retainedWordOrAddress17);
                    originalFrame.sp118 = 0;
                    Actor24_85394ShiftVectorRightTowardZeroView1(&originalFrame.sp110, 3);
                    originalFrame.sp120 =
                        (int)(Actor24_85394Field(((void*)&Actor24_85394Data65920View1), short*,
                                                 ((Actor24_85394CallrandView1() & 0xFF) * 2)) *
                              5) >>
                        2;
                    rawWord3 = Actor24_85394Field(((void*)&Actor24_85394Data658A0View1), short*,
                                                  ((Actor24_85394CallrandView1() & 0xFF) * 2));
                    originalFrame.sp128 = 0;
                    originalFrame.sp124 = (int)(rawWord3 * 5) >> 2;
                    Actor24_85394AddVectorView1(&originalFrame.sp120, &originalFrame.sp120,
                                                &originalFrame.sp110);
                    Actor24_85394Field(privateRecord20, int*, 0x18) =
                        Actor24_85394PlanarHeadingLookupView1(originalFrame.sp120,
                                                              originalFrame.sp124, 0);
                    Actor24_85394Field(privateRecord20, short*, 0x14) =
                        (short)((Actor24_85394CallrandView1() & 0x7F) + 0x3C);
                    if ((Actor24_85394ApproximatePlanarDistanceView1(retainedWordOrAddress17,
                                                                     privateRecord20) < 0x2000) ||
                        !(Actor24_85394CallrandView1() & 3)) {
                        if (Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) != 2) {
                            Actor24_85394Data6C770View1 = 0;
                            Actor24_85394Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor24_85394Field(ownerRecord19, unsigned char*, 0x3D) = 2U;
                            Actor24_85394Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor24_85394EmptyAnimationTransitionHookView1(ownerRecord19);
                        }
                        Actor24_85394Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                    }
                }
                retainedShiftOrAddress21 = (int)&originalFrame.spD0;
            mode5VectorReady:
                argumentWord4 = retainedShiftOrAddress21;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                Actor24_85394Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor24_85394Field(ownerRecord19, int*, 0x14) -
                          Actor24_85394Field(privateRecord20, short*, 0x12));
                Actor24_85394CopyVectorView1(argumentWord4, retainedWordOrAddress17);
                Actor24_85394TurnMobyTowardHeadingView1(
                    ownerRecord19, Actor24_85394Field(privateRecord20, int*, 0x18), 6, 0, 0, 0);
                originalFrame.spE0 =
                    (int)(Actor24_85394Field(
                              ((void*)&Actor24_85394Data65920View1), short*,
                              (Actor24_85394Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spE4 =
                    (int)(Actor24_85394Field(
                              ((void*)&Actor24_85394Data658A0View1), short*,
                              (Actor24_85394Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spE8 = 0;
                Actor24_85394AddVectorView1(&originalFrame.spE0, &originalFrame.spE0,
                                            retainedWordOrAddress17);
                originalFrame.spE8 = Actor24_85394Field(ownerRecord19, int*, 0x14) + 0x100;
                rawWord2 = Actor24_85394QueryWorldHeightView1(&originalFrame.spE0, 0x400);
                originalFrame.spE8 = rawWord2;
                if ((Actor24_85394Field(ownerRecord19, int*, 0x14) - rawWord2) < 0x100) {
                    retainedDistanceOrFlags18 = Actor24_85394ResolveMobyYawStepView1(
                        ownerRecord19, 0x91, 0x12C, 0x3E8, 0x36);
                    if (retainedDistanceOrFlags18 & 0x10) {
                        Actor24_85394SubtractVectorView1(&originalFrame.sp130,
                                                         retainedWordOrAddress17,
                                                         retainedShiftOrAddress21);
                        argumentWord5 =
                            Actor24_85394MeasureVectorLengthView1(&originalFrame.sp130, 1);
                        if (argumentWord5 >= 0x92) {
                            Actor24_85394ScaleVectorRatioQ15View1(&originalFrame.sp130,
                                                                  argumentWord5, 0x91);
                            Actor24_85394AddVectorView1(retainedWordOrAddress17,
                                                        &originalFrame.sp130,
                                                        retainedShiftOrAddress21);
                        }
                    }
                } else {
                    retainedDistanceOrFlags18 = 0;
                }
                argumentWord5 = Actor24_85394Field(privateRecord20, short*, 0x12);
                argumentWord4 = Actor24_85394Field(privateRecord20, short*, 0x10);
                rawWord2 = argumentWord5 < argumentWord4;
                rawWord3 = argumentWord5;
                if (!rawWord2)
                    goto clamp1Reduce;
                rawWord2 = rawWord3 + 10;
                Actor24_85394Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor24_85394Field(privateRecord20, short*, 0x10);
                argumentWord4 = rawWord3;
                rawWord3 = rawWord3 < rawWord2;
                if (!rawWord3)
                    goto clamp1Done;
                Actor24_85394Field(privateRecord20, short*, 0x12) = argumentWord4;
                goto clamp1Done;
            clamp1Reduce:
                rawWord2 = argumentWord4 < argumentWord5;
                if (!rawWord2)
                    goto clamp1Done;
                rawWord2 = rawWord3 - 10;
                Actor24_85394Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor24_85394Field(privateRecord20, short*, 0x10);
                rawWord2 = rawWord2 < rawWord3;
                argumentWord4 = rawWord3;
                if (!rawWord2)
                    goto clamp1Done;
                Actor24_85394Field(privateRecord20, short*, 0x12) = argumentWord4;
            clamp1Done:
                if (Actor24_85394CountTimerDownView1(privateRecord20 + 0x16, 2) != 0) {
                    argumentWord4 = (int)&originalFrame.sp140;
                    __asm__ __volatile__(""
                                         : "=r"(retainedShiftOrAddress21)
                                         : "0"(retainedShiftOrAddress21), "r"(argumentWord4)
                                         : "$6", "memory");
                    Actor24_85394SubtractVectorView1(argumentWord4, ownerRecord19 + 12,
                                                     &originalFrame.spD0);
                    argumentWord4 = originalFrame.sp140;
                    argumentWord5 = originalFrame.sp144;
                    rawWord2 = argumentWord4;
                    if (argumentWord4 < 0) {
                        MATCHING_KEEP(rawWord2);
                        rawWord2 = -rawWord2;
                    }
                    rawWord3 = argumentWord5;
                    if (argumentWord5 < 0) {
                        MATCHING_KEEP(rawWord3);
                        rawWord3 = -rawWord3;
                    }
                    rawWord3 = rawWord2 + rawWord3;
                    if (rawWord3 < 8) {
                        Actor24_85394Field(privateRecord20, short*, 0x16) = 0x3C;
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            (int)((Actor24_85394Field(privateRecord20, int*, 0x18) + 0x80) & 0xFF);
                    } else if (!({
                                   rawWord2 = rawWord3 < 32;
                                   MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
                                   rawWord2;
                               })) {
                        if (({
                                rawWord2 = retainedDistanceOrFlags18 & 2;
                                MATCHING_OBSERVE_GNU_VOLATILE(retainedDistanceOrFlags18);
                                rawWord2;
                            })) {
                            retainedWordOrAddress16 = (int)&Actor24_85394Data71918View1;
                            MATCHING_KEEP(retainedWordOrAddress16);
                            argumentWord4 = Actor24_85394Field(retainedWordOrAddress16, int*, 0);
                            rawWord3 = Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                            rawWord2 = Actor24_85394Data71920View1;
                            if (argumentWord4 < 0) {
                                argumentWord4 = -argumentWord4;
                            }
                            if (rawWord3 < 0)
                                rawWord3 = -rawWord3;
                            argumentWord4 += rawWord3;
                            MATCHING_OBSERVE_GNU_VOLATILE(argumentWord4);
                            if (rawWord2 < 0)
                                rawWord2 = -rawWord2;
                            if ((rawWord2 >> 1) < argumentWord4) {
                                argumentWord4 = (int)&originalFrame.sp140;
                                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "memory");
                                rawWord2 = Actor24_85394Field(privateRecord20, int*, 0x18);
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor24_85394Field(&Actor24_85394Data65920View1, short*,
                                                              rawWord2);
                                MATCHING_KEEP(rawWord2);
                                rawWord2 >>= 5;
                                originalFrame.sp140 = rawWord2;
                                __asm__ __volatile__("" ::: "$5", "memory");
                                rawWord2 = Actor24_85394Field(privateRecord20, int*, 0x18);
                                argumentWord5 = retainedWordOrAddress16;
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor24_85394Field(&Actor24_85394Data658A0View1, short*,
                                                              rawWord2);
                                __asm__ __volatile__("" ::: "$6", "memory");
                                argumentWord6 = argumentWord4;
                                originalFrame.sp148 = 0;
                                __asm__ __volatile__(""
                                                     : "=r"(rawWord2)
                                                     : "0"(rawWord2), "m"(originalFrame.sp148)
                                                     : "memory");
                                rawWord2 >>= 5;
                                originalFrame.sp144 = rawWord2;
                                rawWord2 = Actor24_85394ComputeVectorPlaneResponseView1(
                                    argumentWord4, argumentWord5, argumentWord6);
                                if (rawWord2 != 0) {
                                    argumentWord4 = originalFrame.sp140;
                                    argumentWord5 = originalFrame.sp144;
                                    goto block_188;
                                }
                                argumentWord4 =
                                    Actor24_85394Field(retainedWordOrAddress16, int*, 0);
                                if ((argumentWord4 != 0) ||
                                    (Actor24_85394Field(retainedWordOrAddress16, int*, 4) != 0)) {
                                    argumentWord5 =
                                        Actor24_85394Field(retainedWordOrAddress16, int*, 4);
                                    goto block_188;
                                }
                            }
                            goto block_190;
                        }
                    } else {
                    block_188:
                        Actor24_85394Field(privateRecord20, int*, 0x18) =
                            Actor24_85394PlanarHeadingLookupView1(argumentWord4, argumentWord5, 0);
                    block_190:
                        Actor24_85394Field(privateRecord20, short*, 0x16) = 5;
                    }
                }
                rawWord2 = Actor24_85394Field(ownerRecord19, int*, 0x14);
                rawWord3 = originalFrame.spD8;
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                argumentWord4 = ownerRecord19 + 0xC;
                if (rawWord2 >= 0x81) {
                    __asm__ __volatile__(""
                                         : "=r"(retainedShiftOrAddress21)
                                         : "0"(retainedShiftOrAddress21)
                                         : "$5", "memory");
                    Actor24_85394CopyVectorView1(argumentWord4, &originalFrame.spD0);
                    MATCHING_KEEP(ownerRecord19);
                    argumentWord4 = ownerRecord19 + 0xC;
                }
                Actor24_85394Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor24_85394Field(ownerRecord19, int*, 0x14) +
                          Actor24_85394Field(privateRecord20, short*, 0x12));
                if (Actor24_85394ApproximatePlanarDistanceView1(
                        argumentWord4, ((void*)&Actor24_85394Data70328View1)) < 0x1000) {
                    Actor24_85394Field(privateRecord20, int*, 0x18) =
                        Actor24_85394PlanarHeadingLookupView1(
                            Actor24_85394Field(ownerRecord19, int*, 0xC) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 0),
                            Actor24_85394Field(ownerRecord19, int*, 0x10) -
                                Actor24_85394Field(((void*)&Actor24_85394Data70328View1), int*, 4),
                            0);
                    Actor24_85394Field(privateRecord20, short*, 0x14) =
                        (short)((Actor24_85394CallrandView1() & 0x3F) + 0x1E);
                    rawWord2 = Actor24_85394CallrandView1();
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 1;
                    rawWord2 &= 255;
                    MATCHING_KEEP(rawWord2);
                    rawWord2 += 512;
                storeTimerAndEnterState1:
                    Actor24_85394Field(privateRecord20, short*, 0x10) = rawWord2;
                    rawWord2 = 1;
                    Actor24_85394Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                    Actor24_85394RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    return;
                }
                break;
            case 3:
                Actor24_85394UpdateMobyBallisticMotionView1(
                    ownerRecord19, privateRecord20 + 0x1C,
                    Actor24_85394Field(privateRecord20, int*, 0x18), privateRecord20 + 0x20, 0xC,
                    0x10, 0x140, 1);
                if (Actor24_85394Data6C770View1 != 0) {
                    Actor24_85394RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                    Actor24_85394EmitMobyVertexParticlesView1(ownerRecord19, 0x18);
                    Actor24_85394DeleteMobyView1(ownerRecord19);
                }
                break;
        }
    } else {
    }
}
#undef Actor24_85394Field

void func_level_24_80086980(Moby* moby) {
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
void func_level_24_800869A0(Moby* mobyArgument) {
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
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_24/moby/func_level_24_80086BA0.s SHA256 cdf8a6bea45bfae8f963071e7e88c7695cbbef51f3054060e3dd865498817434. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level24_86BA0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level24_86BA0QueryWorldSegmentWithOptions() __asm__("func_8001830C");
/* extern */
int Level24_86BA0QueryWorldHeightWithOptions() __asm__("func_8001A310");
/* extern */
int Level24_86BA0QueryDynamicMobyGeometry() __asm__("func_8001BA30");
/* extern */
int Level24_86BA0TestPlayerSphereOverlap() __asm__("func_8001C288");
/* extern */
int Level24_86BA0UpdateMobyPathMotion() __asm__("func_80035A80");
/* extern */
unsigned char Level24_86BA0ResolveMobyYawStep() __asm__("func_80035DDC");
/* extern */
unsigned char Level24_86BA0ResolveMobyHeadingStep() __asm__("func_80035EE0");
/* extern */
int Level24_86BA0TestPaddedRotatedBox() __asm__("func_80036220");
/* extern */
unsigned char Level24_86BA0EmitMobyVertexParticles() __asm__("func_800369B8");
/* extern */
unsigned char Level24_86BA0MarkMobyCollectionBit() __asm__("func_8003BA00");
/* extern */
int Level24_86BA0PlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned char Level24_86BA0TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
/* extern */
int Level24_86BA0SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
/* extern */
int Level24_86BA0PlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned char Level24_86BA0TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
unsigned char Level24_86BA0AddVector() __asm__("func_8004F194");
/* extern */
unsigned char Level24_86BA0DeleteMoby() __asm__("func_80055B18");
/* extern */
extern int Level24_86BA0_D_8006C550 __asm__("D_8006C550");
extern unsigned int Level24_86BA0_D_8006C704 __asm__("D_8006C704");
extern int Level24_86BA0_D_8006E1D4 __asm__("D_8006E1D4");
extern int Level24_86BA0_D_8006E1D8 __asm__("D_8006E1D8");
extern unsigned char Level24_86BA0_D_80070328 __asm__("D_80070328");
extern void* (*Level24_86BA0_SpawnMoby)() __asm__("SpawnMoby");

void func_level_24_80086BA0(void* inputOwner) {
    /* Original frame0x58 and scratch SP20/SP24/SP28/SP30/SP34/SP38.
     * Outgoing helper argument five is explicitly zero at SP10, as in
     * original words380..386. The compiler constraint captures SP29 and
     * emits no opcode;
      the four named arguments use the original registers.
     * Shared state and destruction entries, raw helper returns, byte offsets
     * and signed field widths retain all original words and targets.
     * Units, fixed-point domains, helper meanings and cadence unresolved. */
    register void* owner17 __asm__("$17") = inputOwner;
    register int stateValue2 __asm__("$2");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register unsigned char* outgoingStack __asm__("$29");
    struct {
        int sp20;
        int sp24;
        int sp28;
        unsigned char pad2C[4];
        int sp30;
        int sp34;
        int sp38;
        unsigned char pad3C[4];
    } scratch;

    register int savedResult19 __asm__("$19");
    int temp_v0;
    register int temp_v0_2 __asm__("$3");
    int temp_v0_3;
    register int temp_v0_4 __asm__("$3");
    int temp_v0_5;
    register int temp_v0_7 __asm__("$3");
    register int temp_v0_8 __asm__("$3");
    int temp_v0_9;
    int flagsWord;
    register int poolIndex3 __asm__("$3");
    int var_v0_3;
    unsigned char entryState;
    register unsigned int state3 __asm__("$3");

    register void* poolOwner16 __asm__("$16");
    register void* trackedOwner16 __asm__("$16");
    register void* state2Position16 __asm__("$16");
    register void* state3Position16 __asm__("$16");
    register void* vectorOrPosition16 __asm__("$16");
    register void* state14Position16 __asm__("$16");
    register void* state5Position16 __asm__("$16");
    register void* private18 __asm__("$18");
    void* temp_v0_10;
    void* temp_v0_6;

    flagsWord = Level24_86BA0Field(owner17, int*, 0x18);
    private18 = Level24_86BA0Field(owner17, void**, 0);
    if (flagsWord != 0) {
        if (flagsWord & 0x08000000) {
            entryState = Level24_86BA0Field(owner17, unsigned char*, 0x48);
            if ((entryState == 2) || (entryState == 5)) {
                MATCHING_BARRIER("$4");
                argument4 = (int)owner17;
                if (entryState != 0xE) {
                    Level24_86BA0PlayMobySoundEvent(argument4, 2, 0);
                    stateValue2 = 0xE;
                    goto storeEntryState;
                }
            } else {
                goto handleOtherFlags;
            }
        } else {
        handleOtherFlags:
            if (Level24_86BA0Field(owner17, unsigned char*, 0x48) != 0xE) {
                Level24_86BA0PlayMobySoundEvent(owner17, 1, 0);
                if (Level24_86BA0TestPlayerSphereOverlap(owner17 + 0xC, 0x400, 1) != 0) {
                    Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 0x298) =
                        Level24_86BA0PlanarHeadingLookup(
                            Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 0) -
                                Level24_86BA0Field(owner17, int*, 0xC),
                            Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 4) -
                                Level24_86BA0Field(owner17, int*, 0x10),
                            0);
                }
                stateValue2 = 3;
            storeEntryState:
                Level24_86BA0Field(owner17, unsigned char*, 0x48) = stateValue2;
            }
        }
    }
    state3 = Level24_86BA0Field(owner17, unsigned char*, 0x48);
    Level24_86BA0Field(owner17, int*, 0x18) = 0;
    switch (state3) {
        case 0:
            poolIndex3 = Level24_86BA0Field(private18, int*, 0);
            if (poolIndex3 >= 0) {
                poolOwner16 = Level24_86BA0_D_8006C550 + (poolIndex3 * 0x58);
                if (((unsigned int)(Level24_86BA0Field(poolOwner16, unsigned char*, 0x48) - 0x50) <
                     2U) &&
                    (Level24_86BA0TestPaddedRotatedBox(&Level24_86BA0_D_80070328, private18 + 0x18,
                                                       0, 0) != 0)) {
                    stateValue2 = (int)Level24_86BA0Field(poolOwner16, void**, 0);
                    Level24_86BA0Field((void*)stateValue2, int*, 0xC) = 0;
                    stateValue2 = 1;
                    goto storeState;
                }
            }
        default:
            return;
        case 1:
            poolIndex3 = Level24_86BA0Field(private18, int*, 0);
            stateValue2 = poolIndex3 * 0x58;
            poolIndex3 = Level24_86BA0_D_8006C550;
            trackedOwner16 = (void*)(poolIndex3 + stateValue2);
            if ((Level24_86BA0Field(trackedOwner16, unsigned char*, 0x3C) == 0xC) &&
                ((unsigned char)Level24_86BA0Field(trackedOwner16, unsigned char*, 0x3E) >= 3U)) {
                Level24_86BA0Field(owner17, unsigned char*, 0x48) = 0xDU;
                Level24_86BA0Field(private18, int*, 0xC) = 0;
                Level24_86BA0Field(private18, short*, 0x10) = 0;
                return;
            }
            break;
        case 13:
            Level24_86BA0ResolveMobyYawStep(owner17, 0x89, 0, 0, 1);
            temp_v0 =
                Level24_86BA0Field(owner17, int*, 0x14) - Level24_86BA0Field(private18, int*, 0xC);
            Level24_86BA0Field(owner17, int*, 0x14) = temp_v0;
            Level24_86BA0Field(owner17, int*, 0x14) =
                (int)(temp_v0 + Level24_86BA0Field(private18, short*, 0x10));
            Level24_86BA0Field(private18, int*, 0xC) =
                (int)(Level24_86BA0Field(private18, int*, 0xC) + 0xA);
            temp_v0_2 = Level24_86BA0QueryWorldHeightWithOptions(owner17 + 0xC, 0x320, 3, 0);
            argument4 = (int)owner17;
            if (temp_v0_2 != 0) {
                argument5 = 0x3C;
                stateValue2 = temp_v0_2 + 0x300;
                Level24_86BA0Field((void*)argument4, int*, 0x14) = stateValue2;
                stateValue2 = 2;
                Level24_86BA0Field((void*)argument4, unsigned char*, 0x48) = stateValue2;
                stateValue2 = 0xFA;
                Level24_86BA0Field(private18, short*, 0x10) = stateValue2;
                stateValue2 = 0x14;
                Level24_86BA0Field(private18, int*, 0xC) = 0;
                goto publishReset;
            }
            break;
        case 15:
            temp_v0_3 =
                Level24_86BA0Field(owner17, int*, 0x14) - Level24_86BA0Field(private18, int*, 0xC);
            Level24_86BA0Field(owner17, int*, 0x14) = temp_v0_3;
            Level24_86BA0Field(owner17, int*, 0x14) =
                (int)(temp_v0_3 + Level24_86BA0Field(private18, short*, 0x10));
            Level24_86BA0Field(private18, int*, 0xC) =
                (int)(Level24_86BA0Field(private18, int*, 0xC) + 0xA);
            temp_v0_4 = Level24_86BA0QueryWorldHeightWithOptions(owner17 + 0xC, 0x320, 3, 0);
            argument4 = (int)owner17;
            if (temp_v0_4 != 0) {
                argument5 = 0x3C;
                stateValue2 = temp_v0_4 + 0x300;
                Level24_86BA0Field((void*)argument4, int*, 0x14) = stateValue2;
                stateValue2 = -1;
                Level24_86BA0Field((void*)argument4, unsigned char*, 0x48) = 0;
                Level24_86BA0Field(private18, int*, 0) = stateValue2;
                stateValue2 = 0x14;
            publishReset:
                Level24_86BA0_D_8006E1D8 = stateValue2;
                stateValue2 = 0x1000;
                Level24_86BA0_D_8006E1D4 = stateValue2;
                Level24_86BA0EmitMobyVertexParticles(argument4, argument5);
                return;
            }
            break;
        case 2:
            if (Level24_86BA0SoundHandleMatchesOwnerInStates1Or2(
                    owner17, Level24_86BA0Field(private18, int*, 0x14)) == 0) {
                Level24_86BA0Field(private18, int*, 0x14) =
                    Level24_86BA0PlayMobySoundEvent(owner17, 0, 4);
            }
            Level24_86BA0ResolveMobyYawStep(owner17, 0x89, 0, 0, 1);
            state2Position16 = owner17 + 0xC;
            temp_v0_5 = Level24_86BA0QueryWorldHeightWithOptions(state2Position16, 0x800, 3, 0);
            if (temp_v0_5 == 0) {
                stateValue2 = 3;
                goto storeState;
            }
            Level24_86BA0Field(owner17, int*, 0x14) = (int)(temp_v0_5 + 0x200);
            Level24_86BA0Field(owner17, unsigned char*, 0x45) =
                (unsigned char)(Level24_86BA0Field(owner17, unsigned char*, 0x45) - 4);
            if (Level24_86BA0TestPlayerSphereOverlap(state2Position16, 0x400, 1) != 0) {
                Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 0x298) =
                    (int)Level24_86BA0Field(owner17, unsigned char*, 0x46);
                Level24_86BA0Field(owner17, unsigned char*, 0x48) = 3U;
            }
            scratch.sp20 = 0x400;
            scratch.sp24 = 0;
            scratch.sp28 = 0;
            Level24_86BA0TransformVectorByBasis(owner17 + 0x20, &scratch.sp20, &scratch.sp20);
            Level24_86BA0AddVector(&scratch.sp20, state2Position16, &scratch.sp20);
            if (Level24_86BA0QueryWorldSegmentWithOptions(state2Position16, &scratch.sp20, 3, 0,
                                                          0) != 0) {
                Level24_86BA0Field(owner17, unsigned char*, 0x48) = 3U;
                return;
            }
            break;
        case 3:
            temp_v0_6 = Level24_86BA0_SpawnMoby(0x169, owner17);
            if (temp_v0_6 != 0) {
                temp_v0_7 = Level24_86BA0QueryWorldHeightWithOptions(owner17 + 0xC, 0x800, 3, 0);
                if (temp_v0_7 != 0) {
                    Level24_86BA0Field(temp_v0_6, int*, 0x14) = temp_v0_7;
                }
                Level24_86BA0Field(temp_v0_6, signed char*, 0x4C) = 0x40;
                Level24_86BA0Field(temp_v0_6, signed char*, 0x4E) = 0x40;
            }
            Level24_86BA0Field(private18, void**, 4) = 0;
            Level24_86BA0EmitMobyVertexParticles(owner17, 0x64);
            stateValue2 = Level24_86BA0SoundHandleMatchesOwnerInStates1Or2(
                owner17, Level24_86BA0Field(private18, int*, 0x14));
            state3Position16 = owner17 + 0xC;
            if (stateValue2 != 0) {
                Level24_86BA0TransitionSoundHandleTo3Or5(Level24_86BA0Field(private18, int*, 0x14));
            }
            Level24_86BA0Field(private18, int*, 0x14) = -1;
            Level24_86BA0QueryDynamicMobyGeometry(state3Position16, 0x800, 3, 0, 0x04000000,
                                                  owner17);
            Level24_86BA0TestPlayerSphereOverlap(state3Position16, 0x800, 1);
            stateValue2 = Level24_86BA0_D_8006C704;
            goto destroyOwner;
        case 14:
            if (Level24_86BA0SoundHandleMatchesOwnerInStates1Or2(
                    owner17, Level24_86BA0Field(private18, int*, 0x14)) == 0) {
                Level24_86BA0Field(private18, int*, 0x14) =
                    Level24_86BA0PlayMobySoundEvent(owner17, 0, 4);
            }
            Level24_86BA0ResolveMobyHeadingStep(
                owner17, (Level24_86BA0Field(owner17, unsigned char*, 0x46) + 0x80) & 0xFF, 0x12C,
                0, 0, 0x400);
            scratch.sp30 = -0x400;
            scratch.sp34 = 0;
            scratch.sp38 = 0;
            argument4 = (int)(owner17 + 0x20);
            MATCHING_OBSERVE_CLOBBER(argument4, "$16");
            vectorOrPosition16 = &scratch.sp30;
            MATCHING_KEEP(vectorOrPosition16);
            Level24_86BA0TransformVectorByBasis(argument4, vectorOrPosition16, vectorOrPosition16);
            argument4 = (int)vectorOrPosition16;
            MATCHING_KEEP(argument4);
            vectorOrPosition16 = owner17 + 0xC;
            Level24_86BA0AddVector(argument4, vectorOrPosition16, argument4);
            temp_v0_8 = Level24_86BA0QueryWorldHeightWithOptions(vectorOrPosition16, 0x800, 3, 0);
            if (temp_v0_8 == 0) {
                Level24_86BA0Field(owner17, int*, 0x14) =
                    (int)(Level24_86BA0Field(owner17, int*, 0x14) -
                          Level24_86BA0Field(private18, int*, 0xC));
                temp_v0_9 = Level24_86BA0Field(private18, int*, 0xC) + 0xA;
                Level24_86BA0Field(private18, int*, 0xC) = temp_v0_9;
                if (temp_v0_9 >= 0x2BD) {
                    if (Level24_86BA0SoundHandleMatchesOwnerInStates1Or2(
                            owner17, Level24_86BA0Field(private18, int*, 0x14)) != 0) {
                        Level24_86BA0TransitionSoundHandleTo3Or5(
                            Level24_86BA0Field(private18, int*, 0x14));
                    }
                    stateValue2 = Level24_86BA0_D_8006C704;
                    Level24_86BA0Field(private18, int*, 0x14) = -1;
                destroyOwner:
                    stateValue2 = (unsigned int)owner17 < (unsigned int)stateValue2;
                    if (stateValue2)
                        Level24_86BA0MarkMobyCollectionBit(owner17);
                    Level24_86BA0DeleteMoby(owner17);
                    return;
                }
                goto checkState14Contact;
            }
            stateValue2 = Level24_86BA0Field(private18, int*, 0xC);
            if (stateValue2 == 0) {
                stateValue2 = temp_v0_8 + 0x200;
                Level24_86BA0Field(owner17, int*, 0x14) = stateValue2;
            checkState14Contact:
                __asm__("" : "=r"(outgoingStack));
                Level24_86BA0Field(outgoingStack, volatile int*, 0x10) = 0;
                state14Position16 = owner17 + 0xC;
                if (Level24_86BA0QueryWorldSegmentWithOptions(state14Position16, &scratch.sp30, 3,
                                                              0) == 0) {
                    Level24_86BA0Field(owner17, unsigned char*, 0x45) =
                        (unsigned char)(Level24_86BA0Field(owner17, unsigned char*, 0x45) + 8);
                    stateValue2 = Level24_86BA0QueryDynamicMobyGeometry(state14Position16, 0x400, 3,
                                                                        0, 0x04000000, owner17);
                    MATCHING_KEEP(stateValue2);
                    if (stateValue2 != 0) {
                        stateValue2 = 3;
                        MATCHING_KEEP(stateValue2);
                        Level24_86BA0Field(owner17, unsigned char*, 0x48) = stateValue2;
                        return;
                    }
                } else {
                    stateValue2 = 3;
                    goto storeState;
                }
            } else {
                stateValue2 = 3;
                goto storeState;
            }
            break;
        case 5:
            if (Level24_86BA0SoundHandleMatchesOwnerInStates1Or2(
                    owner17, Level24_86BA0Field(private18, int*, 0x14)) == 0) {
                Level24_86BA0Field(private18, int*, 0x14) =
                    Level24_86BA0PlayMobySoundEvent(owner17, 0, 4);
            }
            savedResult19 = Level24_86BA0UpdateMobyPathMotion(
                owner17, Level24_86BA0Field(private18, void**, 4), 0x78, 0x89, 0, 6, 0x60, 0);
            state5Position16 = owner17 + 0xC;
            Level24_86BA0Field(owner17, int*, 0x14) =
                (int)(Level24_86BA0QueryWorldHeightWithOptions(state5Position16, 0x800, 3, 0) +
                      0x200);
            Level24_86BA0Field(owner17, unsigned char*, 0x45) =
                (unsigned char)(Level24_86BA0Field(owner17, unsigned char*, 0x45) - 6);
            if (Level24_86BA0TestPlayerSphereOverlap(state5Position16, 0x400, 1) != 0) {
                Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 0x298) =
                    Level24_86BA0PlanarHeadingLookup(
                        Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 0) -
                            Level24_86BA0Field(owner17, int*, 0xC),
                        Level24_86BA0Field(&Level24_86BA0_D_80070328, int*, 4) -
                            Level24_86BA0Field(owner17, int*, 0x10),
                        0);
                Level24_86BA0Field(owner17, unsigned char*, 0x48) = 3U;
            }
            stateValue2 = savedResult19 & 1;
            MATCHING_OBSERVE(savedResult19);
            if (stateValue2) {
                temp_v0_10 = Level24_86BA0Field(private18, void**, 4);
                if (Level24_86BA0Field(temp_v0_10, short*, 2) ==
                    (Level24_86BA0Field(temp_v0_10, short*, 0) - 1)) {
                    stateValue2 = 2;
                    goto storeState;
                }
            }
            break;
    }
    return;
storeState:
    Level24_86BA0Field(owner17, unsigned char*, 0x48) = stateValue2;
}
#undef Level24_86BA0Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80087308.
* AI generated; not human reviewed. All957 original instructions,14 selector
* entries and two zero padding words,973 owned words, must match with every
* actual control and table destination. Frame50 saves S0..S6/RA,SP20..2F.
* Physical state99/active/high/regular blocks and606/809/811/840 shared
* entries remain original. EXE38F14 consumes the owner/private/0/2 arguments
* in A0/A1/A2/A3, as proven by its original38F14..38F40 producers/consumers.
* State is read after36220. Original regular3 child-state1 return and its
* other-child activation edge remain; the parser omitted that latter edge.
* The12288 saved bound, independent bound comparisons, signed samples,
* complete low32 shift products, typed record fields and argument producers
* retain original widths and load/call delays. The independent player-Y
* view resolves to the exact original D_80070328+4 relocation addend.
* Original state71/76 failure blocks and calls remain distinct. Owner-Z+6
* stays with its original producer. The20 descriptor field follows the
* second signed sample. Both original unconditional zero arguments retain
* their branch delays; S0 status is dead before its next full height producer.
* Empty metadata consumes full initialized words or clobbers only before
* new producers, and emits zero CPU instructions. No opcode assembly,
* partialHI,fixedFP,undefined saved inputs,overlapping aliases or pipeline
* changes. Units/fixed point, complete helper/caller chains,cadence beyond
* invocation and synchronized runtime remain open. Confidence is binary
* identity after every gate. Next: human review and retail runtime capture.
* Falsification: every native/linked word, actual target, original data and
* full EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 6683e9cb2562ca2a0c6ed104279241dfbf6b08e48f561107c5a00ac8cfe72ab7 */
extern int Level24_87308Data70328View1 __asm__("D_80070328 + 4");
#define Level24_87308Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level24_87308TestSubdividedSegmentPathView1() __asm__("func_80013E38");
int Level24_87308QueryWorldHeightView1() __asm__("func_8001A358");
void Level24_87308RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level24_87308SetMobyAnimationView1() __asm__("func_80034F80");
int Level24_87308UpdateMobyMotionDescriptorView1() __asm__("func_80035194");
int Level24_87308TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level24_87308CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level24_87308UpdateMobyPathMotionView1() __asm__("func_80035A80");
int Level24_87308ProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Level24_87308ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level24_87308BlendBoundedAngle8StepView1() __asm__("func_800360F8");
int Level24_87308TestPaddedRotatedBoxView1() __asm__("func_80036220");
int Level24_87308GetClosestPathNodeView1() __asm__("func_8003645C");
int Level24_87308EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level24_87308SpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
int Level24_87308InitializeMobyMotionStateWithDecelerationView1() __asm__("func_80038F14");
int Level24_87308MarkMobyCollectionBitView1() __asm__("func_8003BA00");
int Level24_87308PlayMobySoundEventView1() __asm__("func_8003BABC");
int Level24_87308PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level24_87308CopyVectorView1() __asm__("func_8004F178");
int Level24_87308AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level24_87308ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level24_87308DeleteMobyView1() __asm__("func_80055B18");
int Level24_87308RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Level24_87308Data658A0View1 __asm__("D_800658A0");
extern int Level24_87308Data65920View1 __asm__("D_80065920");
extern int Level24_87308Data6C550View1 __asm__("D_8006C550");
extern int Level24_87308Data6C770View1 __asm__("D_8006C770");
extern int Level24_87308Data6E020View1 __asm__("D_8006E020");
extern int Level24_87308Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level24_87308Data6E040View1 __asm__("D_8006E040");
extern int Level24_87308Data70328View2 __asm__("D_80070328");
void func_level_24_80087308(void* input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    register int retainedOriginalBound22 __asm__("$22");
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord18 __asm__("$18"), retainedStatusOrHeight16 __asm__("$16"),
        retainedOwnerVectorOrLimit19 __asm__("$19"), retainedOwnerHalfword21 __asm__("$21");
    struct {
        int sp20, sp24, sp28, sp2C;
    } originalFrame;
    int temporaryWord11;
    int temporaryWord3;
    int temporaryWord7;
    int temporaryWord13;
    int temporaryWord1;
    int temporaryWord8;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord14;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord2;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord9;
    int temporaryWord15;
    ownerRecord17 = input;
    MATCHING_KEEP(ownerRecord17);
    privateRecord18 = Level24_87308Field(ownerRecord17, void**, 0);
    retainedOriginalBound22 = 0x3000;
    if (Level24_87308Field(ownerRecord17, unsigned char*, 0x48) != 0x63) {
        if (Level24_87308Field(ownerRecord17, int*, 0x18) & 0x30000) {
            Level24_87308InitializeMobyMotionStateWithDecelerationView1(
                input, privateRecord18 + 0x28, 0, 2);
            rawWord2 = Level24_87308Field(ownerRecord17, int*, 24);
            rawWord3 = 0x10000;
            rawWord2 &= rawWord3;
            if (rawWord2)
                rawWord2 = 280;
            else
                rawWord2 = 400;
            Level24_87308Field(privateRecord18, short*, 0x2C) = rawWord2;
            temporaryWord16 = Level24_87308Field(ownerRecord17, unsigned char*, 0x51);
            argumentWord4 = (int)ownerRecord17;
            if (temporaryWord16 == 0) {
                temporaryWord16 = Level24_87308BlendBoundedAngle8StepView1(
                    Level24_87308PlanarHeadingLookupView1(
                        Level24_87308Field(ownerRecord17, int*, 0xC) -
                            Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0),
                        Level24_87308Field(ownerRecord17, int*, 0x10) -
                            Level24_87308Field((int)&Level24_87308Data70328View2, int*, 4),
                        0),
                    Level24_87308Field((int)&Level24_87308Data70328View2, unsigned char*, 0xE),
                    0x20, 0x40);
                argumentWord4 = (int)ownerRecord17;
            }
            Level24_87308Field(privateRecord18, unsigned char*, 0x39) = temporaryWord16;
            Level24_87308Field(privateRecord18, short*, 0x2E) = 0x32;
            Level24_87308Field(privateRecord18, signed char*, 0x36) = 0xC;
            Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 0x63U;
            Level24_87308SpawnMobyFromValueSelectorView1(argumentWord4, 1, 0, 0);
        }
        argumentWord4 = (int)&originalFrame.sp20;
        if (Level24_87308Field(ownerRecord17, unsigned char*, 0x48) != 0x63)
            goto enterOriginalActiveBody;
    }
updateOriginalState99:
    if (Level24_87308UpdateMobyMotionDescriptorView1(ownerRecord17, privateRecord18 + 0x28) ==
        0x100) {
        Level24_87308RefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
        Level24_87308MarkMobyCollectionBitView1(ownerRecord17);
        Level24_87308EmitMobyVertexParticlesView1(ownerRecord17, 0x40);
        Level24_87308DeleteMobyView1(ownerRecord17);
        return;
    }
    return;
enterOriginalActiveBody:
    retainedOwnerVectorOrLimit19 = ownerRecord17 + 0xC;
    Level24_87308CopyVectorView1(argumentWord4, retainedOwnerVectorOrLimit19);
    originalFrame.sp28 += 0x100;
    if ((unsigned char)Level24_87308Field(ownerRecord17, unsigned char*, 0x48) < 0x46U) {
        if ((Level24_87308AbsoluteByteAngleDeltaView1(
                 (int)(Level24_87308Data6E040View1 << 0x10) >> 0x14,
                 Level24_87308PlanarHeadingLookupView1(
                     Level24_87308Field(ownerRecord17, int*, 0xC) - Level24_87308Data6E020View1,
                     Level24_87308Field(ownerRecord17, int*, 0x10) - Level24_87308Data6E024View1,
                     0)) < 0x20) &&
            (Level24_87308ApproximatePlanarDistanceView1(retainedOwnerVectorOrLimit19,
                                                         (int)&Level24_87308Data70328View2) < ({
                 MATCHING_KEEP(retainedOriginalBound22);
                 retainedOriginalBound22;
             })) &&
            (Level24_87308TestSubdividedSegmentPathView1(
                 &originalFrame.sp20, (int)&Level24_87308Data70328View2, 0) != 0)) {
            if (Level24_87308Field(privateRecord18, short*, 0) != 2) {
                {
                    int completeHeightResult =
                        Level24_87308ProbeGroundFromRaisedMobyView1(ownerRecord17);
                    retainedStatusOrHeight16 =
                        completeHeightResult - Level24_87308QueryWorldHeightView1(
                                                   (int)&Level24_87308Data70328View2, 0x800);
                }
                if (retainedStatusOrHeight16 < 0) {
                    retainedStatusOrHeight16 = -retainedStatusOrHeight16;
                }
                if (retainedStatusOrHeight16 < 0x80) {
                    goto checkOriginalLinkedRoot;
                }
            } else {
            checkOriginalLinkedRoot:
                temporaryWord7 = Level24_87308Field(privateRecord18, int*, 0x40);
                if ((temporaryWord7 < 0) ||
                    (Level24_87308ApproximatePlanarDistanceView1(
                         retainedOwnerVectorOrLimit19,
                         Level24_87308Data6C550View1 + (temporaryWord7 * 0x58) + 0xC) >= 0x2801)) {
                    Level24_87308Field(privateRecord18, unsigned char*, 0xC) =
                        (unsigned char)Level24_87308Field(ownerRecord17, unsigned char*, 0x48);
                    Level24_87308Field(privateRecord18, unsigned char*, 0xD) =
                        (unsigned char)Level24_87308Field(ownerRecord17, unsigned char*, 0x3D);
                    Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 0x46U;
                }
            }
        }
        temporaryWord1 = Level24_87308Field(ownerRecord17, unsigned char*, 0x48);
        if (temporaryWord1 < 0x46U)
            goto enterOriginalRegularStates;
    }
updateOriginalHighStates:
    retainedOwnerVectorOrLimit19 = 0x32;
    if (Level24_87308Field(privateRecord18, short*, 0) == 2) {
        retainedOwnerVectorOrLimit19 = 0x37;
    }
    retainedStatusOrHeight16 = -(Level24_87308TestPaddedRotatedBoxView1(
                                     ownerRecord17 + 0xC, privateRecord18 + 0x10, 0, 0) != 0);
    temporaryWord8 = Level24_87308Field(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord8) {
        case 0x4B:
            Level24_87308TurnMobyTowardHeadingView1(
                ownerRecord17,
                Level24_87308PlanarHeadingLookupView1(
                    Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0) -
                        Level24_87308Field(ownerRecord17, int*, 0xC),
                    Level24_87308Field((int)&Level24_87308Data70328View2, int*, 4) -
                        Level24_87308Field(ownerRecord17, int*, 0x10),
                    0),
                7, 2, 1, retainedStatusOrHeight16);
            if (Level24_87308Data6C770View1 != 0) {
                Level24_87308RequestMobyAnimationView1(ownerRecord17, 1U);
                temporaryWord17 = 0x47;
                Level24_87308Field(privateRecord18, int*, 0x44) = 0;
                goto writeSharedOriginalHighState;
            }
            break;
        case 0x46:
            if (Level24_87308AbsoluteByteAngleDeltaView1(
                    (int)Level24_87308Field(ownerRecord17, unsigned char*, 0x46),
                    Level24_87308PlanarHeadingLookupView1(
                        Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0) -
                            Level24_87308Field(ownerRecord17, int*, 0xC),
                        Level24_87308Field((int)&Level24_87308Data70328View2, int*, 4) -
                            Level24_87308Field(ownerRecord17, int*, 0x10),
                        0)) < 0x10) {
                Level24_87308RequestMobyAnimationView1(ownerRecord17, 4U);
                MATCHING_OBSERVE_VOLATILE(ownerRecord17);
                temporaryWord17 = 0x4B;
            } else {
                Level24_87308RequestMobyAnimationView1(ownerRecord17, 1U);
                temporaryWord17 = 0x48;
            }
            goto writeSharedOriginalHighState;
        case 0x47:
            temporaryWord3 = Level24_87308Field(privateRecord18, int*, 0x44) + 0x1E;
            Level24_87308Field(privateRecord18, int*, 0x44) = temporaryWord3;
            if (temporaryWord3 >= 0xF1) {
                Level24_87308Field(privateRecord18, int*, 0x44) = 0xF0;
            }
            Level24_87308TurnMobyTowardHeadingView1(
                ownerRecord17,
                Level24_87308PlanarHeadingLookupView1(
                    Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0) -
                        Level24_87308Field(ownerRecord17, int*, 0xC),
                    Level24_87308Field((int)&Level24_87308Data70328View2, int*, 4) -
                        Level24_87308Field(ownerRecord17, int*, 0x10),
                    0),
                3, 2, 0, retainedStatusOrHeight16);
            if ((Level24_87308ResolveMobyYawStepView1(
                     ownerRecord17, Level24_87308Field(privateRecord18, int*, 68), 300, 300,
                     retainedOwnerVectorOrLimit19) != 0) ||
                (Level24_87308AbsoluteByteAngleDeltaView1(
                     (int)(Level24_87308Data6E040View1 << 16) >> 20,
                     Level24_87308PlanarHeadingLookupView1(
                         Level24_87308Field(ownerRecord17, int*, 12) - Level24_87308Data6E020View1,
                         Level24_87308Field(ownerRecord17, int*, 16) - Level24_87308Data6E024View1,
                         0)) >= 33))
                goto enterOriginalState71Failure;
            rawWord2 = Level24_87308GetClosestPathNodeView1(
                ownerRecord17 + 12, Level24_87308Field(privateRecord18, int*, 4), 0);
            rawWord3 = retainedOriginalBound22 + 1024;
            rawWord3 = rawWord3 < rawWord2;
            if (rawWord3)
                goto enterOriginalState71Failure;
            if (Level24_87308Field(privateRecord18, short*, 0) == 2)
                goto enterOriginalState71Success;
            {
                int completeHeightResult =
                    Level24_87308ProbeGroundFromRaisedMobyView1(ownerRecord17);
                retainedStatusOrHeight16 =
                    completeHeightResult -
                    Level24_87308QueryWorldHeightView1((int)&Level24_87308Data70328View2, 2048);
            }
            if (retainedStatusOrHeight16 < 0)
                retainedStatusOrHeight16 = -retainedStatusOrHeight16;
            if (retainedStatusOrHeight16 < 129)
                goto enterOriginalState71Success;
        enterOriginalState71Failure:
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 1;
            __asm__(""
                    : "=r"(argumentWord5)
                    : "0"(argumentWord5), "r"(argumentWord4), "r"(retainedOwnerVectorOrLimit19)
                    : "$2", "memory");
            rawWord2 = 600;
            Level24_87308Field(privateRecord18, short*, 14) = rawWord2;
            Level24_87308RequestMobyAnimationView1(argumentWord4, argumentWord5);
            MATCHING_OBSERVE_VOLATILE(privateRecord18);
            temporaryWord17 = 73;
            goto writeSharedOriginalHighState;
        enterOriginalState71Success:
            if (Level24_87308ApproximatePlanarDistanceView1(ownerRecord17 + 12,
                                                            (int)&Level24_87308Data70328View2) <
                Level24_87308Field(privateRecord18, int*, 68) * 13) {
                Level24_87308RequestMobyAnimationView1(ownerRecord17, 3);
                Level24_87308PlayMobySoundEventView1(ownerRecord17, 0, 0);
                temporaryWord17 = 74;
                goto writeSharedOriginalHighState;
            }
            break;
        case 0x4A:
            retainedOwnerHalfword21 = Level24_87308Field(ownerRecord17, short*, 0x38);
            Level24_87308TurnMobyTowardHeadingView1(
                ownerRecord17,
                Level24_87308PlanarHeadingLookupView1(
                    Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0) -
                        Level24_87308Field(ownerRecord17, int*, 0xC),
                    Level24_87308Data70328View1 - Level24_87308Field(ownerRecord17, int*, 0x10), 0),
                3, 2, 0, retainedStatusOrHeight16);
            rawWord2 = Level24_87308ResolveMobyYawStepView1(ownerRecord17, 240, 300, 300,
                                                            retainedOwnerVectorOrLimit19);
            rawWord3 = -6;
            retainedStatusOrHeight16 = rawWord2;
            Level24_87308Field(ownerRecord17, short*, 56) = rawWord3;
            rawWord3 = Level24_87308Field(ownerRecord17, int*, 20);
            rawWord2 = Level24_87308Field((int)&Level24_87308Data70328View2, int*, 8);
            argumentWord4 = Level24_87308Field((int)&Level24_87308Data70328View2, int*, 68);
            rawWord3 += 6;
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2), "r"(argumentWord4));
            rawWord3 -= rawWord2;
            rawWord3 += argumentWord4;
            if (rawWord3 < 0) {
                rawWord3 = -rawWord3;
            }
            if ((rawWord3 < 0x200) && ({
                    rawWord2 = Level24_87308ApproximatePlanarDistanceView1(
                        ownerRecord17 + 12, (int)&Level24_87308Data70328View2);
                    argumentWord6 = 0;
                    rawWord2 < 1024;
                }) &&
                (Level24_87308AbsoluteByteAngleDeltaView1(
                     (int)Level24_87308Field(ownerRecord17, unsigned char*, 0x46),
                     Level24_87308PlanarHeadingLookupView1(
                         Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0) -
                             Level24_87308Field(ownerRecord17, int*, 0xC),
                         Level24_87308Field((int)&Level24_87308Data70328View2, int*, 4) -
                             Level24_87308Field(ownerRecord17, int*, 0x10),
                         argumentWord6)) < 0x20)) {
                Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0x24) =
                    (int)(Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0x24) | 0x80);
                Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0x298) =
                    (int)Level24_87308Field(ownerRecord17, unsigned char*, 0x46);
                Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0x21C) =
                    (int)((int)(Level24_87308Field(
                                    (int)&Level24_87308Data65920View1, short*,
                                    (Level24_87308Field(ownerRecord17, unsigned char*, 0x46) * 2)) *
                                0x7D) >>
                          0xC);
                rawWord2 = Level24_87308Field(ownerRecord17, unsigned char*, 70);
                rawWord2 *= 2;
                rawWord3 = Level24_87308Field((int)&Level24_87308Data658A0View1, short*, rawWord2);
                __asm__("" ::: "$2", "memory");
                rawWord2 = 20;
                Level24_87308Field((int)&Level24_87308Data70328View2, int*, 548) = rawWord2;
                rawWord2 = (rawWord3 * 125) >> 12;
                Level24_87308Field((int)&Level24_87308Data70328View2, int*, 544) = rawWord2;
                goto writeOriginalState76;
            }
            argumentWord6 = 0;
            if ((retainedStatusOrHeight16 == 0) && ({
                    MATCHING_BARRIER("$16");
                    Level24_87308AbsoluteByteAngleDeltaView1(
                        (int)(Level24_87308Data6E040View1 << 0x10) >> 0x14,
                        Level24_87308PlanarHeadingLookupView1(
                            Level24_87308Field(ownerRecord17, int*, 0xC) -
                                Level24_87308Data6E020View1,
                            Level24_87308Field(ownerRecord17, int*, 0x10) -
                                Level24_87308Data6E024View1,
                            argumentWord6)) < 0x21;
                })) {
                if (({
                        argumentWord6 = 0;
                        Level24_87308GetClosestPathNodeView1(
                            ownerRecord17 + 12, Level24_87308Field(privateRecord18, int*, 4),
                            argumentWord6);
                    }) <= retainedOriginalBound22 + 0x400) {
                    if (Level24_87308Field(privateRecord18, short*, 0) != 2) {
                        {
                            int completeHeightResult =
                                Level24_87308ProbeGroundFromRaisedMobyView1(ownerRecord17);
                            retainedStatusOrHeight16 =
                                completeHeightResult -
                                Level24_87308QueryWorldHeightView1(
                                    (int)&Level24_87308Data70328View2, 0x800);
                        }
                        if (retainedStatusOrHeight16 < 0) {
                            retainedStatusOrHeight16 = -retainedStatusOrHeight16;
                        }
                        if (retainedStatusOrHeight16 >= 0x81) {
                            goto activateOriginalState76;
                        }
                    }
                } else {
                    goto activateOriginalState76Failure;
                }
            } else {
            activateOriginalState76:
            activateOriginalState76Failure:
                Level24_87308RequestMobyAnimationView1(ownerRecord17, 4U);
            writeOriginalState76:
                Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 0x4CU;
            }
            Level24_87308Field(ownerRecord17, short*, 0x38) = retainedOwnerHalfword21;
            break;
        case 0x48:
            if ((Level24_87308TurnMobyTowardHeadingView1(
                     ownerRecord17,
                     Level24_87308PlanarHeadingLookupView1(
                         Level24_87308Field((int)&Level24_87308Data70328View2, int*, 0) -
                             Level24_87308Field(ownerRecord17, int*, 0xC),
                         Level24_87308Field((int)&Level24_87308Data70328View2, int*, 4) -
                             Level24_87308Field(ownerRecord17, int*, 0x10),
                         0),
                     7, 2, 1, retainedStatusOrHeight16) != 0) &&
                (Level24_87308Data6C770View1 != 0)) {
                Level24_87308RequestMobyAnimationView1(ownerRecord17, 4U);
                temporaryWord17 = 0x4B;
                goto writeSharedOriginalHighState;
            }
            break;
        case 0x4C:
            if (Level24_87308Data6C770View1 != 0) {
                if (Level24_87308Field(ownerRecord17, unsigned char*, 0x3D) != 4) {
                    Level24_87308RequestMobyAnimationView1(ownerRecord17, 4U);
                } else {
                    argumentWord4 = (int)ownerRecord17;
                    argumentWord5 = 1;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4), "r"(privateRecord18)
                            : "$2", "memory");
                    rawWord2 = 600;
                    Level24_87308Field(privateRecord18, short*, 14) = rawWord2;
                    Level24_87308RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    temporaryWord17 = 0x49;
                    goto writeSharedOriginalHighState;
                }
            }
            break;
        case 0x49:
            temporaryWord9 = Level24_87308Field(privateRecord18, void**, 4);
            temporaryWord4 =
                (((int)(Level24_87308Field(temporaryWord9, unsigned short*, 0) << 0x10) >> 0x11) *
                 0x10) +
                Level24_87308Field(temporaryWord9, int*, 0xC);
            if ((Level24_87308TurnMobyTowardHeadingView1(
                     ownerRecord17,
                     Level24_87308PlanarHeadingLookupView1(
                         Level24_87308Field(temporaryWord4, int*, 0) -
                             Level24_87308Field(ownerRecord17, int*, 0xC),
                         Level24_87308Field(temporaryWord4, int*, 4) -
                             Level24_87308Field(ownerRecord17, int*, 0x10),
                         0),
                     6, 0xE, 1, retainedStatusOrHeight16) != 0) &&
                ((Level24_87308ResolveMobyYawStepView1(ownerRecord17, 0x96, 0x12C, 0,
                                                       retainedOwnerVectorOrLimit19),
                  temporaryWord5 = Level24_87308Field(privateRecord18, void**, 4),
                  ((Level24_87308ApproximatePlanarDistanceView1(
                        ownerRecord17 + 0xC,
                        Level24_87308Field(temporaryWord5, int*, 0xC) +
                            (((int)(Level24_87308Field(temporaryWord5, unsigned short*, 0)
                                    << 0x10) >>
                              0x11) *
                             0x10)) < 0x800) != 0)) ||
                 (Level24_87308CountTimerDownView1(privateRecord18 + 0xE, 2) != 0))) {
                Level24_87308RequestMobyAnimationView1(
                    ownerRecord17, Level24_87308Field(privateRecord18, unsigned char*, 0xD));
                temporaryWord17 = Level24_87308Field(privateRecord18, unsigned char*, 0xC);
            writeSharedOriginalHighState:
                Level24_87308Field(ownerRecord17, unsigned char*, 72) = temporaryWord17;
            }
            break;
    }
    temporaryWord10 = Level24_87308Field(ownerRecord17, unsigned char*, 0x48);
    if ((temporaryWord10 >= 0x46U) && (temporaryWord10 != 0x49) &&
        ((Level24_87308AbsoluteByteAngleDeltaView1(
              (int)(Level24_87308Data6E040View1 << 0x10) >> 0x14,
              Level24_87308PlanarHeadingLookupView1(
                  Level24_87308Field(ownerRecord17, int*, 0xC) - Level24_87308Data6E020View1,
                  Level24_87308Field(ownerRecord17, int*, 0x10) - Level24_87308Data6E024View1,
                  0)) >= 0x29) ||
         (temporaryWord6 = Level24_87308Field(privateRecord18, void**, 4), ({
              rawWord2 = Level24_87308ApproximatePlanarDistanceView1(
                  ownerRecord17 + 12,
                  Level24_87308Field(temporaryWord6, int*, 12) +
                      ((short)Level24_87308Field(temporaryWord6, unsigned short*, 2) * 16));
              rawWord3 = retainedOriginalBound22 + 3072;
              rawWord3 = rawWord3 < rawWord2;
              rawWord3;
          })))) {
        Level24_87308RequestMobyAnimationView1(ownerRecord17, 1U);
        Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 0x49U;
        Level24_87308Field(privateRecord18, short*, 0xE) = 0x258;
    }
    return;
enterOriginalRegularStates:
    temporaryWord11 = Level24_87308Field(privateRecord18, short*, 0);
    switch (temporaryWord11) {
        case 2:
        case 0:
            temporaryWord12 = Level24_87308Field(ownerRecord17, unsigned char*, 0x48);
            switch (temporaryWord12) {
                case 5:
                    if (Level24_87308Data6C770View1 != 0) {
                        Level24_87308Field(ownerRecord17, unsigned char*, 0x46) =
                            (unsigned char)(Level24_87308Field(ownerRecord17, unsigned char*,
                                                               0x46) +
                                            0x80);
                        argumentWord5 = Level24_87308Field(privateRecord18, int*, 0x40);
                        if ((argumentWord5 < 0) ||
                            (Level24_87308ApproximatePlanarDistanceView1(
                                 ownerRecord17 + 12,
                                 Level24_87308Data6C550View1 + argumentWord5 * 88 + 12) >= 10240))
                            rawWord2 = 1;
                        else
                            rawWord2 = 6;
                        Level24_87308Field(ownerRecord17, unsigned char*, 72) = rawWord2;
                        Level24_87308SetMobyAnimationView1(ownerRecord17, 0);
                        return;
                    }
                    argumentWord4 = Level24_87308Field(privateRecord18, int*, 8);
                    if (argumentWord4 >= 0) {
                        argumentWord4 = (argumentWord4 * 0x58) + Level24_87308Data6C550View1;
                        if (Level24_87308Field(argumentWord4, unsigned char*, 0x48) == 1) {
                            rawWord3 = Level24_87308Field(
                                Level24_87308Field(argumentWord4, void**, 0), void**, 0x28);
                            if ((Level24_87308Field(rawWord3, short*, 0) -
                                 Level24_87308Field(rawWord3, short*, 2)) < 3) {
                                rawWord2 = 2;
                                goto writeSharedOriginalRegularStateTwo;
                            }
                        }
                    }
                    break;
                case 6:
                    if ((Level24_87308Data6C770View1 != 0) &&
                        (Level24_87308Field(privateRecord18, void**, 4) != 0) &&
                        ((temporaryWord13 = Level24_87308Field(privateRecord18, int*, 0x40),
                          (temporaryWord13 < 0)) ||
                         (Level24_87308ApproximatePlanarDistanceView1(
                              ownerRecord17 + 0xC,
                              Level24_87308Data6C550View1 + (temporaryWord13 * 0x58) + 0xC) >=
                          0x2801))) {
                        Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                        argumentWord4 = (int)ownerRecord17;
                        argumentWord5 = 1;
                        goto callSharedOriginalRegularState;
                    }
                    goto checkSharedOriginalRegularRoot;
                case 1:
                    rawWord3 = Level24_87308Field(ownerRecord17, unsigned char*, 60);
                    rawWord2 = Level24_87308Field(ownerRecord17, unsigned char*, 61);
                    argumentWord4 = (int)ownerRecord17;
                    if (rawWord3 == rawWord2) {
                        Level24_87308RequestMobyAnimationView1(argumentWord4, 1);
                        argumentWord4 = (int)ownerRecord17;
                    }
                    rawWord2 = Level24_87308UpdateMobyPathMotionView1(
                        argumentWord4, Level24_87308Field(privateRecord18, int*, 4), 512, 80, 300,
                        3, 16, 0);
                    rawWord2 &= 2;
                    argumentWord4 = (int)ownerRecord17;
                    if (rawWord2) {
                        rawWord3 = Level24_87308Field(privateRecord18, void**, 4);
                        Level24_87308Field(rawWord3, unsigned short*, 0xA) = (unsigned short)-(
                            int)Level24_87308Field(rawWord3, unsigned short*, 0xA);
                        argumentWord5 = Level24_87308Field(privateRecord18, void**, 4);
                        rawWord2 = Level24_87308Field(argumentWord5, unsigned short*, 2);
                        rawWord3 = Level24_87308Field(argumentWord5, unsigned short*, 0);
                        rawWord2 += 1;
                        rawWord3 -= rawWord2;
                        Level24_87308Field(argumentWord5, unsigned short*, 2) = rawWord3;
                        argumentWord5 = 5;
                        Level24_87308Field(privateRecord18, unsigned short*, 2) =
                            (unsigned short)(Level24_87308Field(ownerRecord17, unsigned char*,
                                                                0x46) +
                                             0x80);
                        Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 5U;
                    callSharedOriginalRegularState:
                        Level24_87308RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    }
                checkSharedOriginalRegularRoot:
                    argumentWord4 = Level24_87308Field(privateRecord18, int*, 8);
                    if (argumentWord4 >= 0) {
                        argumentWord4 = (argumentWord4 * 0x58) + Level24_87308Data6C550View1;
                        if (Level24_87308Field(argumentWord4, unsigned char*, 0x48) == 1) {
                            rawWord3 = Level24_87308Field(
                                Level24_87308Field(argumentWord4, void**, 0), void**, 0x28);
                            if ((Level24_87308Field(rawWord3, short*, 0) -
                                 Level24_87308Field(rawWord3, short*, 2)) < 3) {
                                Level24_87308RequestMobyAnimationView1(ownerRecord17, 1U);
                                rawWord2 = 2;
                            writeSharedOriginalRegularStateTwo:
                                Level24_87308Field(ownerRecord17, unsigned char*, 72) = rawWord2;
                                return;
                            }
                        }
                    }
                    break;
                case 2:
                    temporaryWord2 = (Level24_87308Field(privateRecord18, int*, 8) * 0x58) +
                                     Level24_87308Data6C550View1;
                    if ((Level24_87308TurnMobyTowardHeadingView1(
                             ownerRecord17,
                             Level24_87308PlanarHeadingLookupView1(
                                 Level24_87308Field(temporaryWord2, int*, 0xC) -
                                     Level24_87308Field(ownerRecord17, int*, 0xC),
                                 Level24_87308Field(temporaryWord2, int*, 0x10) -
                                     Level24_87308Field(ownerRecord17, int*, 0x10),
                                 0),
                             6, 2, 0, 0) != 0) &&
                        (Level24_87308Data6C770View1 != 0)) {
                        Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 3U;
                        Level24_87308RequestMobyAnimationView1(ownerRecord17, 0U);
                        return;
                    }
                    break;
                case 3:
                    temporaryWord14 =
                        Level24_87308Field(((Level24_87308Field(privateRecord18, int*, 8) * 0x58) +
                                            Level24_87308Data6C550View1),
                                           unsigned char*, 0x48);
                    if (temporaryWord14 == 3) {
                        Level24_87308Field(ownerRecord17, unsigned char*, 72) = 4;
                        Level24_87308RequestMobyAnimationView1(ownerRecord17, 4);
                        return;
                    }
                    if (temporaryWord14 == 1)
                        return;
                    goto activateOriginalStateOne;
                case 4:
                    if (Level24_87308Data6C770View1 != 0) {
                        case 0:
                        activateOriginalStateOne:
                            Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 1U;
                            Level24_87308RequestMobyAnimationView1(ownerRecord17, 1U);
                            return;
                    }
                    break;
            }
            break;
        case 1:
            switch (temporaryWord1) {
                case 6:
                    temporaryWord15 = Level24_87308Field(privateRecord18, void**, 4);
                    if (temporaryWord15 != 0) {
                        Level24_87308Field(temporaryWord15, unsigned short*, 2) =
                            (unsigned short)Level24_87308Field(privateRecord18, unsigned short*, 2);
                        Level24_87308Field(ownerRecord17, unsigned char*, 0x48) = 0xAU;
                        Level24_87308RequestMobyAnimationView1(ownerRecord17, 1U);
                        return;
                    }
                    break;
                case 10:
                    Level24_87308UpdateMobyPathMotionView1(
                        ownerRecord17, Level24_87308Field(privateRecord18, void**, 4), 0x200, 0xC8,
                        0x12C, 3, 0x20, 0);
                    break;
            }
            break;
    }
    return;
}
#undef Level24_87308Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original24 800881FC.
* Assembly SHA256 8ff903b61d872aeca274443d181d4bf7158dee712a0d32afb62aeef4b883fd35.
* AI generated; not human reviewed. Exactly1152 native instructions,
* 51 original switch selectors and one zero padding word=1204 owned words.
* Accepted935 supplies the complete coordinate/descriptor source chains;
* every target-specific field width,offset,helper argument and branch remains
* independently tied to this original body. FrameB0hex saves S0..S5/RA;
* SP20..8F preserves separate vectors and helper-output byte homes.
* Original state0 private4->private0 store uses the original global-load
* ordering. Descriptor count/current/step are signed16, records stride16;
* dynamic remainders retain the original divide-zero and overflow traps.
* All three /200 chains divide the OLD SIGNED16 timer, then add/store step
* as low16 and clamp the signed new timer at7200. They never divide the
* updated unsigned halfword. Example:old199,step1 gives target256; dividing
* new200 would incorrectly give255. old-201 gives signed quotient-1.
* Helpers retain the original eight argument words, return flag checks,
* count increment, descriptor switch and independent shared state entries.
* State3 reads position.z AFTER35D38 returns; its original signed halfword
* table values use*13,arithmetic>>5 and the late written vector-zero phase.
* State4/50 and common code preserve original88-byte linked-record stride,
* original independent pointer producers,byte/halfword stores and call order.
* States5..49 explicitly enter the original common-status reload; out-of-range
* states enter the already initialized status comparison one word later.
* Every actual selector destination and its zero padding must independently pass.
* Empty metadata observes complete initialized GP words/addresses or a word
* dominated by its original zero store,or clobbers dead GP before fresh values;
* it emits zero CPU words. No partial HI/LO input,opcode asm,fixed FP/SP,
* incoming saved value,unwritten local read or overlapping live fixed aliases.
* Known timer/angle helper types reuse include/mobyutil.h and stdutil.h.
* Unknown helpers keep their original physical word ABI,without invented
* semantics. Compiler,filter and acceptance flags remain frozen.
* Confidence requires every native/linked instruction,actual conditional/
* internal-J/call/table target,data symbol/addend and full EXE/every-overlay
* retail hash. Units,fixed-point domains beyond raw shifts,full helper/caller
* chains,cadence,Rev1 mapping,human review and synchronized captures remain open.
*/
#define Level24_881FCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level24_881FCData658A0View[0x100] __asm__("D_800658A0");
extern short Level24_881FCData65920View[0x100] __asm__("D_80065920");
extern Moby* Level24_881FCData6C550View __asm__("D_8006C550");
extern int Level24_881FCData6C648View __asm__("D_8006C648");
extern unsigned char Level24_881FCData70300View[40] __asm__("D_80070300");
extern Spyro Level24_881FCData70328View __asm__("D_80070328");
void Level24_881FCSetCameraMode11TargetView() __asm__("func_80013D44");
void Level24_881FCRequestMobyAnimationView() __asm__("func_80034F40");
int Level24_881FCUpdateMobyMotionDescriptorView() __asm__("func_80035194");
int Level24_881FCTurnMobyTowardPlayerView() __asm__("func_8003573C");
int Level24_881FCCountTimerDownView(void*, int) __asm__("func_800359A4");
int Level24_881FCProbeGroundFromRaisedMobyView() __asm__("func_80035D38");
int Level24_881FCRandBetweenView() __asm__("func_8003636C");
void Level24_881FCEmitMobyVertexParticlesView() __asm__("func_800369B8");
void Level24_881FCSetMobyZFromGroundProbeView() __asm__("func_80037014");
void Level24_881FCInitializeMobyMotionStateView() __asm__("func_80038BF8");
void Level24_881FCMarkMobyCollectionBitView() __asm__("func_8003BA00");
int Level24_881FCPlayMobySoundEventView() __asm__("func_8003BABC");
extern int Level24_881FCPlanarHeadingLookupView(int, int, int) __asm__("func_8004E880");
extern void Level24_881FCShiftVectorRightTowardZeroView() __asm__("func_8004F110");
extern void Level24_881FCCopyVectorView() __asm__("func_8004F178");
extern void Level24_881FCAddVectorView() __asm__("func_8004F194");
extern void Level24_881FCSubtractVectorView() __asm__("func_8004F1C8");
extern int Level24_881FCAbsoluteByteAngleDeltaView(int, int) __asm__("func_8004F264");
extern int Level24_881FCApproximatePlanarDistanceView() __asm__("func_8004F334");
extern void Level24_881FCDeleteMobyView() __asm__("func_80055B18");
extern void Level24_881FCRefreshMobySpatialGridAndBasisView() __asm__("func_80055D24");
int Level24_881FCUpdateMobyPathMotionView() __asm__("func_80035A80");
int Level24_881FCComputeArcVerticalVelocityView() __asm__("func_800365E4");
unsigned char Level24_881FCInterpolateMobyVertexView() __asm__("func_80055F14");
extern int Level24_881FCData6C58CView __asm__("D_8006C58C");
extern int Level24_881FCData6C770View __asm__("D_8006C770");
extern unsigned char Level24_881FCData6C7B4View __asm__("D_8006C7B4");
extern int Level24_881FCData6E048View __asm__("D_8006E048");
void func_level_24_800881FC(Moby* ownerParameter) {
    register int ownerRecord20 __asm__("$20"), privateRecord19 __asm__("$19"),
        retainedIndexVectorHeadingOrFlags16 __asm__("$16"),
        retainedPlayerBaseVectorHeadingOrLinkedRecord17 __asm__("$17"),
        originalSubstateOrVectorAddress18 __asm__("$18"), retainedDivisionTarget21 __asm__("$21");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C;
    } originalFrame;
    Moby* temporaryValue1;
    Moby* temporaryValue2;
    Moby* temporaryValue11;
    int temporaryValue4;
    int temporaryValue5;
    int temporaryValue24;
    int temporaryValue25;
    int temporaryValue27;
    int temporaryValue28;
    int temporaryValue30;
    int temporaryValue10;
    int temporaryValue14;
    int temporaryValue18;
    int temporaryValue31;
    int temporaryValue12;
    int temporaryValue13;
    int temporaryValue29;
    unsigned char temporaryValue22;
    void* temporaryValue3;
    void* temporaryValue6;
    void* temporaryValue7;
    void* temporaryValue8;
    void* temporaryValue9;
    void* temporaryValue15;
    void* temporaryValue16;
    void* temporaryValue17;
    void* temporaryValue19;
    void* temporaryValue20;
    void* temporaryValue21;
    void* temporaryValue23;
    void* temporaryValue26;
    int temporaryWord11;
    int temporaryWord5;
    int temporaryWord15;
    int temporaryWord6;
    argumentWord4 = (int)ownerParameter;
    ownerRecord20 = argumentWord4;
    MATCHING_KEEP(ownerRecord20);
    privateRecord19 = ((Moby*)ownerRecord20)->mobyTag;
    if (((unsigned int)(((Moby*)ownerRecord20)->state - 3) >= 2U) &&
        (((Moby*)ownerRecord20)->damageFlags != 0)) {
        Level24_881FCInitializeMobyMotionStateView(argumentWord4, privateRecord19 + 0x1C, 1, 3);
        Level24_881FCField(privateRecord19, signed char*, 0x2F) = 0;
    }
    temporaryValue22 = ((Moby*)ownerRecord20)->state;
    switch (temporaryValue22) {
        case 0:
        case 1:
            originalSubstateOrVectorAddress18 = ((Moby*)ownerRecord20)->substate;
            switch (originalSubstateOrVectorAddress18) {
                case 0:
                    rawWord2 = Level24_881FCData6C7B4View;
                    rawWord3 = Level24_881FCField(privateRecord19, int*, 4);
                    rawWord2 &= 32;
                    Level24_881FCField(privateRecord19, int*, 0) = rawWord3;
                    if (rawWord2 ||
                        (Level24_881FCData70300View[Level24_881FCData6C58CView] & 0x20)) {
                        rawWord3 = Level24_881FCField(privateRecord19, int*, 12);
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = (int)Level24_881FCData6C550View;
                        argumentWord4 = rawWord2 + rawWord3;
                        temporaryValue1 = (Moby*)argumentWord4;
                        if (!(temporaryValue1->state & 0x80)) {
                            Level24_881FCDeleteMobyView(temporaryValue1);
                        }
                        Level24_881FCDeleteMobyView(ownerRecord20);
                        return;
                    }
                    ((Moby*)ownerRecord20)->colour.g = 0x80;
                    ((Moby*)ownerRecord20)->colour.b = 0xC0;
                    ((Moby*)ownerRecord20)->colour.r = 0;
                    ((Moby*)ownerRecord20)->colour.a = 0;
                    ((Moby*)ownerRecord20)->substate = 1;
                    temporaryValue2 =
                        &Level24_881FCData6C550View[Level24_881FCField(privateRecord19, int*, 0xC)];
                    temporaryValue2->state = 6;
                    temporaryValue2->unknown &= 0x7FFFFFFF;
                default:
                    goto reloadOriginalCommonStatus1089;
                case 1:
                    argumentWord4 = (int)&originalFrame.sp20;
                    MATCHING_KEEP_CLOBBER(argumentWord4, "$16");
                    MATCHING_KEEP(originalSubstateOrVectorAddress18);
                    retainedIndexVectorHeadingOrFlags16 = (int)&Level24_881FCData70328View + 152;
                    Level24_881FCCopyVectorView(argumentWord4, retainedIndexVectorHeadingOrFlags16);
                    originalFrame.sp20 *= 0x14;
                    originalFrame.sp24 *= 0x14;
                    originalFrame.sp28 *= 0x14;
                    Level24_881FCShiftVectorRightTowardZeroView(&originalFrame.sp20, 6);
                    argumentWord4 = (int)&originalFrame.sp20;
                    MATCHING_KEEP(argumentWord4);
                    argumentWord5 = argumentWord4;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4),
                              "r"(retainedIndexVectorHeadingOrFlags16));
                    retainedPlayerBaseVectorHeadingOrLinkedRecord17 =
                        retainedIndexVectorHeadingOrFlags16 - 152;
                    Level24_881FCAddVectorView(argumentWord4, argumentWord5,
                                               retainedPlayerBaseVectorHeadingOrLinkedRecord17);
                    if (({
                            rawWord2 = Level24_881FCApproximatePlanarDistanceView(
                                (int)ownerRecord20 + 12, &originalFrame.sp20);
                            argumentWord4 = (int)&originalFrame.sp30;
                            rawWord2;
                        }) < 6144) {
                        temporaryWord5 = Level24_881FCField(privateRecord19, void**, 0);
                        argumentWord6 = Level24_881FCField(temporaryWord5, short*, 2);
                        MATCHING_KEEP(argumentWord6);
                        temporaryWord11 = Level24_881FCField(temporaryWord5, short*, 0);
                        retainedIndexVectorHeadingOrFlags16 =
                            (int)(argumentWord6 + Level24_881FCField(temporaryWord5, short*, 0xA) +
                                  temporaryWord11) %
                            temporaryWord11;
                        __asm__ volatile("" ::: "$5", "memory");
                        argumentWord5 = retainedPlayerBaseVectorHeadingOrLinkedRecord17;
                        __asm__(""
                                : "=r"(retainedIndexVectorHeadingOrFlags16)
                                : "0"(retainedIndexVectorHeadingOrFlags16), "r"(argumentWord5));
                        rawWord2 = Level24_881FCField(temporaryWord5, int*, 12);
                        argumentWord6 *= 16;
                        argumentWord6 = rawWord2 + argumentWord6;
                        Level24_881FCSubtractVectorView(argumentWord4, argumentWord5, argumentWord6,
                                                        temporaryWord5);
                        retainedPlayerBaseVectorHeadingOrLinkedRecord17 =
                            Level24_881FCPlanarHeadingLookupView(originalFrame.sp30,
                                                                 originalFrame.sp34, 0);
                        rawWord2 = Level24_881FCField(privateRecord19, int*, 0);
                        rawWord3 = Level24_881FCField(rawWord2, int*, 12);
                        rawWord2 = Level24_881FCField(rawWord2, short*, 2);
                        __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
                        argumentWord6 = 0;
                        rawWord2 *= 16;
                        rawWord2 += rawWord3;
                        argumentWord4 = Level24_881FCField(rawWord2, int*, 0);
                        argumentWord5 = Level24_881FCField(rawWord2, int*, 4);
                        MATCHING_KEEP_CLOBBER(retainedIndexVectorHeadingOrFlags16, "memory");
                        retainedIndexVectorHeadingOrFlags16 =
                            retainedIndexVectorHeadingOrFlags16 * 16 + rawWord3;
                        MATCHING_KEEP(retainedIndexVectorHeadingOrFlags16);
                        argumentWord7 =
                            Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 0);
                        rawWord3 = Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 4);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Level24_881FCPlanarHeadingLookupView(
                            argumentWord4, argumentWord5, argumentWord6);
                        rawWord2 = Level24_881FCAbsoluteByteAngleDeltaView(
                            retainedPlayerBaseVectorHeadingOrLinkedRecord17, rawWord2);
                        argumentWord5 = Level24_881FCField(privateRecord19, int*, 0);
                        retainedIndexVectorHeadingOrFlags16 = -1;
                        argumentWord6 = Level24_881FCField(argumentWord5, short*, 2);
                        argumentWord4 = Level24_881FCField(argumentWord5, int*, 12);
                        rawWord3 = argumentWord6 * 16 + argumentWord4;
                        rawWord3 = Level24_881FCField(rawWord3, int*, 12);
                        retainedPlayerBaseVectorHeadingOrLinkedRecord17 = rawWord2;
                        if (rawWord3 == originalSubstateOrVectorAddress18)
                            retainedIndexVectorHeadingOrFlags16 = argumentWord6;
                        if (retainedPlayerBaseVectorHeadingOrLinkedRecord17 < 0x20) {
                            Level24_881FCField(argumentWord5, short*, 0xA) =
                                (short)-(short)(unsigned short)Level24_881FCField(argumentWord5,
                                                                                  short*, 0xA);
                            goto reverseOriginalFirstDescriptor;
                        }
                        if (({
                                rawWord2 = retainedPlayerBaseVectorHeadingOrLinkedRecord17 < 96;
                                MATCHING_KEEP(rawWord2);
                                rawWord2;
                            })) {
                            if (({
                                    rawWord2 = Level24_881FCPlanarHeadingLookupView(
                                        -originalFrame.sp30, -originalFrame.sp34, 0);
                                    retainedPlayerBaseVectorHeadingOrLinkedRecord17 =
                                        (rawWord2 - Level24_881FCData70328View.bodyRotation.yaw) &
                                        255;
                                    MATCHING_KEEP(retainedPlayerBaseVectorHeadingOrLinkedRecord17);
                                    rawWord2 =
                                        retainedPlayerBaseVectorHeadingOrLinkedRecord17 < 128;
                                    MATCHING_KEEP(rawWord2);
                                    rawWord2;
                                })) {
                                Level24_881FCPlayMobySoundEventView(ownerRecord20, 0, 0);
                                temporaryValue26 = Level24_881FCField(privateRecord19, void**, 0);
                                Level24_881FCField(temporaryValue26, short*, 0xA) =
                                    (short)-(short)(unsigned short)Level24_881FCField(
                                        temporaryValue26, short*, 0xA);
                            reverseOriginalFirstDescriptor:
                                temporaryValue3 = Level24_881FCField(privateRecord19, void**, 0);
                                temporaryValue27 = Level24_881FCField(temporaryValue3, short*, 0);
                                Level24_881FCField(temporaryValue3, short*, 2) =
                                    (short)((int)(Level24_881FCField(temporaryValue3, short*, 2) +
                                                  Level24_881FCField(temporaryValue3, short*, 0xA) +
                                                  temporaryValue27) %
                                            temporaryValue27);
                                temporaryValue19 = Level24_881FCField(privateRecord19, void**, 0);
                                temporaryValue4 = Level24_881FCField(temporaryValue19, short*, 2);
                                if (Level24_881FCField(
                                        ((temporaryValue4 * 0x10) +
                                         Level24_881FCField(temporaryValue19, int*, 0xC)),
                                        int*, 0xC) == originalSubstateOrVectorAddress18) {
                                    retainedIndexVectorHeadingOrFlags16 = temporaryValue4;
                                }
                                Level24_881FCField(privateRecord19, short*, 0x10) = 0x1E;
                            }
                        }
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) = 0x100U;
                        if (retainedIndexVectorHeadingOrFlags16 >= 0) {
                            Level24_881FCField(Level24_881FCField(privateRecord19, void**, 0),
                                               short*, 2) = retainedIndexVectorHeadingOrFlags16;
                            temporaryValue6 = Level24_881FCField(privateRecord19, void**, 0);
                            temporaryValue28 = Level24_881FCField(temporaryValue6, short*, 0);
                            Level24_881FCField(temporaryValue6, short*, 2) =
                                (short)((int)(Level24_881FCField(temporaryValue6, short*, 2) +
                                              Level24_881FCField(temporaryValue6, short*, 0xA) +
                                              temporaryValue28) %
                                        temporaryValue28);
                            temporaryValue20 = Level24_881FCField(privateRecord19, void**, 0);
                            Level24_881FCField(privateRecord19, int*, 0x14) =
                                Level24_881FCComputeArcVerticalVelocityView(
                                    &((Moby*)ownerRecord20)->position,
                                    Level24_881FCField(temporaryValue20, int*, 0xC) +
                                        (Level24_881FCField(temporaryValue20, short*, 2) * 0x10),
                                    0xF6, -0xF, &originalFrame.sp40);
                            ((Moby*)ownerRecord20)->substate = 2;
                        }
                        ((Moby*)ownerRecord20)->state = 2;
                        temporaryValue31 = 2;
                        argumentWord4 = ownerRecord20;
                        argumentWord5 = temporaryValue31;
                        goto callOriginalStateHelper1087;
                    } else {
                        Level24_881FCTurnMobyTowardPlayerView(ownerRecord20, 8, 0, 1);
                        if (Level24_881FCData6C770View != 0) {
                            if (Level24_881FCField(privateRecord19, short*, 0x10) == 0) {
                                Level24_881FCRequestMobyAnimationView(ownerRecord20, 1);
                                Level24_881FCField(privateRecord19, short*, 0x10) =
                                    Level24_881FCRandBetweenView(1, 2);
                            } else {
                                Level24_881FCRequestMobyAnimationView(ownerRecord20, 0);
                                Level24_881FCField(privateRecord19, short*, 0x10) =
                                    (short)((unsigned short)Level24_881FCField(privateRecord19,
                                                                               short*, 0x10) -
                                            1);
                            }
                        }
                    }
                    goto reloadOriginalCommonStatus1089;
            }
            break;
        case 2:
            originalSubstateOrVectorAddress18 = ((Moby*)ownerRecord20)->substate;
            switch (originalSubstateOrVectorAddress18) {
                case 1:
                    rawWord2 = Level24_881FCField(privateRecord19, unsigned short*, 0x12);
                    argumentWord4 = (int)((unsigned int)rawWord2 << 16);
                    rawWord3 = argumentWord4 >> 16;
                    rawWord3 = rawWord3 / 200;
                    rawWord3 += argumentWord4 >> 31;
                    argumentWord4 >>= 31;
                    rawWord2 += Level24_881FCData6C648View;
                    Level24_881FCField(privateRecord19, unsigned short*, 0x12) = rawWord2;
                    rawWord2 = (short)rawWord2 < 7201;
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(argumentWord4), "r"(rawWord2));
                    retainedDivisionTarget21 = rawWord3 - argumentWord4;
                    rawWord3 = 256;
                    retainedDivisionTarget21 = rawWord3 - retainedDivisionTarget21;
                    if (!rawWord2) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x12) = 0x1C20U;
                    }
                    Level24_881FCCopyVectorView(&originalFrame.sp30,
                                                &Level24_881FCData70328View.unk7a[3]);
                    originalFrame.sp30 = (int)originalFrame.sp30 * 0x14;
                    originalFrame.sp34 *= 0x14;
                    originalFrame.sp38 *= 0x14;
                    Level24_881FCShiftVectorRightTowardZeroView(&originalFrame.sp30, 6);
                    Level24_881FCAddVectorView(
                        &originalFrame.sp30, &originalFrame.sp30,
                        (Vector3D*)((unsigned char*)&Level24_881FCData70328View.unk7a[3] - 0x98));
                    retainedPlayerBaseVectorHeadingOrLinkedRecord17 =
                        &((Moby*)ownerRecord20)->position;
                    retainedIndexVectorHeadingOrFlags16 =
                        Level24_881FCApproximatePlanarDistanceView(
                            retainedPlayerBaseVectorHeadingOrLinkedRecord17, &originalFrame.sp30);
                    temporaryValue29 =
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) + 8;
                    Level24_881FCField(privateRecord19, unsigned short*, 0x18) = temporaryValue29;
                    if ((short)temporaryValue29 >= 0x101) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) = 0x100U;
                    }
                    temporaryValue7 = Level24_881FCField(privateRecord19, void**, 0);
                    temporaryValue5 = Level24_881FCField(temporaryValue7, short*, 2);
                    if (Level24_881FCField(((temporaryValue5 * 0x10) +
                                            Level24_881FCField(temporaryValue7, int*, 0xC)),
                                           int*, 0xC) == originalSubstateOrVectorAddress18) {
                        temporaryValue30 = Level24_881FCField(temporaryValue7, short*, 0);
                        Level24_881FCField(temporaryValue7, short*, 2) =
                            (short)((int)(temporaryValue5 +
                                          Level24_881FCField(temporaryValue7, short*, 0xA) +
                                          temporaryValue30) %
                                    temporaryValue30);
                        temporaryValue21 = Level24_881FCField(privateRecord19, void**, 0);
                        Level24_881FCField(privateRecord19, int*, 0x14) =
                            Level24_881FCComputeArcVerticalVelocityView(
                                retainedPlayerBaseVectorHeadingOrLinkedRecord17,
                                Level24_881FCField(temporaryValue21, int*, 0xC) +
                                    (Level24_881FCField(temporaryValue21, short*, 2) * 0x10),
                                0xF6, -0xF, &originalFrame.sp44);
                        ((Moby*)ownerRecord20)->substate = 2;
                    }
                    argumentWord4 = Level24_881FCUpdateMobyPathMotionView(
                        ownerRecord20, Level24_881FCField(privateRecord19, void**, 0), 0x200,
                        retainedDivisionTarget21, 0, ({
                            rawWord3 = (int)((unsigned int)Level24_881FCField(privateRecord19,
                                                                              unsigned short*, 24)
                                             << 16) >>
                                       20;
                            MATCHING_KEEP(rawWord3);
                            rawWord3;
                        }),
                        0x18, 4);
                    MATCHING_KEEP(argumentWord4);
                    rawWord2 = argumentWord4 & 2;
                    if (rawWord2)
                        Level24_881FCField(privateRecord19, unsigned short*, 0x1A) =
                            Level24_881FCField(privateRecord19, unsigned short*, 0x1A) + 1;
                    rawWord2 = argumentWord4 & 1;
                    if (rawWord2) {
                        rawWord3 = Level24_881FCField(privateRecord19, int*, 0);
                        rawWord2 = Level24_881FCField(privateRecord19, int*, 4);
                        if (rawWord3 == rawWord2) {
                            rawWord3 = Level24_881FCField(rawWord3, short*, 2);
                            rawWord2 = 15;
                            if (rawWord3 == rawWord2) {
                                rawWord3 = Level24_881FCField(privateRecord19, int*, 8);
                                rawWord2 = 4;
                                Level24_881FCField(privateRecord19, int*, 0) = rawWord3;
                                Level24_881FCField(rawWord3, short*, 2) = rawWord2;
                                rawWord2 = Level24_881FCField(privateRecord19, int*, 4);
                                rawWord3 = Level24_881FCField(privateRecord19, int*, 0);
                                rawWord2 = Level24_881FCField(rawWord2, unsigned short*, 10);
                                Level24_881FCField(rawWord3, short*, 10) = rawWord2;
                            }
                        }
                    }
                    rawWord2 = argumentWord4 & 4;
                    if (!rawWord2)
                        Level24_881FCField(privateRecord19, short*, 24) = 0;
                    if (((Moby*)ownerRecord20)->substate == 1) {
                        rawWord2 = retainedIndexVectorHeadingOrFlags16 < 10241;
                        argumentWord4 = privateRecord19 + 16;
                        if (rawWord2)
                            goto callOriginalCountdown513;
                        rawWord2 = Level24_881FCApproximatePlanarDistanceView(
                            ownerRecord20 + 12, &Level24_881FCData70328View);
                        MATCHING_KEEP(privateRecord19);
                        argumentWord4 = privateRecord19 + 16;
                        if (rawWord2 < 10241)
                            goto callOriginalCountdown513;
                        argumentWord4 = ownerRecord20;
                        argumentWord5 = 0;
                        Level24_881FCField(privateRecord19, short*, 16) = 2;
                        goto storeOriginalStateZero1086;
                    callOriginalCountdown513:
                        Level24_881FCCountTimerDownView(argumentWord4, 2);
                        temporaryWord6 = Level24_881FCField(privateRecord19, void**, 0);
                        argumentWord6 = Level24_881FCField(temporaryWord6, short*, 2);
                        MATCHING_KEEP(argumentWord6);
                        temporaryWord15 = Level24_881FCField(temporaryWord6, short*, 0);
                        retainedIndexVectorHeadingOrFlags16 =
                            (int)(argumentWord6 + Level24_881FCField(temporaryWord6, short*, 0xA) +
                                  temporaryWord15) %
                            temporaryWord15;
                        __asm__ volatile("" ::: "$4", "$5", "memory");
                        argumentWord4 = (int)&originalFrame.sp48;
                        argumentWord5 = (int)&Level24_881FCData70328View;
                        __asm__(""
                                : "=r"(retainedIndexVectorHeadingOrFlags16)
                                : "0"(retainedIndexVectorHeadingOrFlags16), "r"(argumentWord4),
                                  "r"(argumentWord5));
                        rawWord2 = Level24_881FCField(temporaryWord6, int*, 12);
                        argumentWord6 *= 16;
                        argumentWord6 = rawWord2 + argumentWord6;
                        Level24_881FCSubtractVectorView(argumentWord4, argumentWord5, argumentWord6,
                                                        temporaryWord6);
                        retainedPlayerBaseVectorHeadingOrLinkedRecord17 =
                            Level24_881FCPlanarHeadingLookupView(originalFrame.sp48,
                                                                 originalFrame.sp4C, 0);
                        rawWord2 = Level24_881FCField(privateRecord19, int*, 0);
                        rawWord3 = Level24_881FCField(rawWord2, int*, 12);
                        rawWord2 = Level24_881FCField(rawWord2, short*, 2);
                        __asm__ volatile("" ::: "$4", "$5", "$6", "$7", "memory");
                        argumentWord6 = 0;
                        rawWord2 *= 16;
                        rawWord2 += rawWord3;
                        argumentWord4 = Level24_881FCField(rawWord2, int*, 0);
                        argumentWord5 = Level24_881FCField(rawWord2, int*, 4);
                        MATCHING_KEEP_CLOBBER(retainedIndexVectorHeadingOrFlags16, "memory");
                        retainedIndexVectorHeadingOrFlags16 =
                            retainedIndexVectorHeadingOrFlags16 * 16 + rawWord3;
                        MATCHING_KEEP(retainedIndexVectorHeadingOrFlags16);
                        argumentWord7 =
                            Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 0);
                        rawWord3 = Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 4);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Level24_881FCPlanarHeadingLookupView(
                            argumentWord4, argumentWord5, argumentWord6);
                        rawWord2 = retainedPlayerBaseVectorHeadingOrLinkedRecord17 - rawWord2;
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
                                (Level24_881FCField(privateRecord19, short*, 0x10) == 0)) {
                                rawWord2 = Level24_881FCData70328View.bodyRotation.yaw;
                                rawWord2 =
                                    retainedPlayerBaseVectorHeadingOrLinkedRecord17 - rawWord2;
                                MATCHING_KEEP(rawWord2);
                                retainedPlayerBaseVectorHeadingOrLinkedRecord17 = rawWord2 & 255;
                                if (retainedPlayerBaseVectorHeadingOrLinkedRecord17 >= 0x81) {
                                    retainedPlayerBaseVectorHeadingOrLinkedRecord17 -= 0x100;
                                }
                                if (((argumentWord4 > 0) &&
                                     (retainedPlayerBaseVectorHeadingOrLinkedRecord17 > 0)) ||
                                    ((argumentWord4 < 0) &&
                                     (retainedPlayerBaseVectorHeadingOrLinkedRecord17 < 0))) {
                                    Level24_881FCPlayMobySoundEventView(ownerRecord20, 0, 0);
                                    goto reverseOriginalSecondDescriptor;
                                }
                            }
                        } else {
                        reverseOriginalSecondDescriptor:
                            temporaryValue23 = Level24_881FCField(privateRecord19, void**, 0);
                            Level24_881FCField(temporaryValue23, short*, 0xA) =
                                (short)-(short)(unsigned short)Level24_881FCField(temporaryValue23,
                                                                                  short*, 0xA);
                            temporaryValue8 = Level24_881FCField(privateRecord19, void**, 0);
                            temporaryValue24 = Level24_881FCField(temporaryValue8, short*, 0);
                            Level24_881FCField(temporaryValue8, short*, 2) =
                                (short)((int)(Level24_881FCField(temporaryValue8, short*, 2) +
                                              (Level24_881FCField(temporaryValue8, short*, 0xA) *
                                               2) +
                                              temporaryValue24) %
                                        temporaryValue24);
                            Level24_881FCField(privateRecord19, short*, 0x10) = 0x1E;
                            Level24_881FCField(privateRecord19, unsigned short*, 0x18) = 0x100U;
                        }
                    }
                    break;
                case 2:
                    rawWord2 = Level24_881FCField(privateRecord19, unsigned short*, 0x12);
                    argumentWord4 = (int)((unsigned int)rawWord2 << 16);
                    rawWord3 = argumentWord4 >> 16;
                    rawWord3 = rawWord3 / 200;
                    rawWord3 += argumentWord4 >> 31;
                    argumentWord4 >>= 31;
                    rawWord2 += Level24_881FCData6C648View;
                    Level24_881FCField(privateRecord19, unsigned short*, 0x12) = rawWord2;
                    rawWord2 = (short)rawWord2 < 7201;
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(argumentWord4), "r"(rawWord2));
                    originalSubstateOrVectorAddress18 = rawWord3 - argumentWord4;
                    rawWord3 = 256;
                    originalSubstateOrVectorAddress18 =
                        rawWord3 - originalSubstateOrVectorAddress18;
                    if (!rawWord2) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x12) = 0x1C20U;
                    }
                    Level24_881FCCopyVectorView(&originalFrame.sp48,
                                                &Level24_881FCData70328View.unk7a[3]);
                    originalFrame.sp48 = (int)originalFrame.sp48 * 0x14;
                    originalFrame.sp4C *= 0x14;
                    originalFrame.sp50 *= 0x14;
                    Level24_881FCShiftVectorRightTowardZeroView(&originalFrame.sp48, 6);
                    Level24_881FCAddVectorView(
                        &originalFrame.sp48, &originalFrame.sp48,
                        (Vector3D*)((unsigned char*)&Level24_881FCData70328View.unk7a[3] - 0x98));
                    Level24_881FCApproximatePlanarDistanceView(&((Moby*)ownerRecord20)->position,
                                                               &originalFrame.sp48);
                    temporaryValue12 =
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) + 8;
                    Level24_881FCField(privateRecord19, unsigned short*, 0x18) = temporaryValue12;
                    if ((short)temporaryValue12 >= 0x101) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) = 0x100U;
                    }
                    rawWord2 = Level24_881FCUpdateMobyPathMotionView(
                        ownerRecord20, Level24_881FCField(privateRecord19, void**, 0), 0x200,
                        originalSubstateOrVectorAddress18, 0,
                        (int)(Level24_881FCField(privateRecord19, unsigned short*, 0x18) << 0x10) >>
                            0x14,
                        0x18, 0);
                    argumentWord6 = 0;
                    __asm__ volatile("" ::"r"(argumentWord6) : "$16", "memory");
                    retainedIndexVectorHeadingOrFlags16 = rawWord2;
                    argumentWord4 = Level24_881FCField(privateRecord19, int*, 0);
                    argumentWord5 = Level24_881FCField(ownerRecord20, int*, 16);
                    rawWord3 = Level24_881FCField(argumentWord4, short*, 2);
                    argumentWord4 = Level24_881FCField(argumentWord4, int*, 12);
                    rawWord3 *= 16;
                    rawWord3 += argumentWord4;
                    argumentWord7 = Level24_881FCField(rawWord3, int*, 0);
                    argumentWord4 = Level24_881FCField(ownerRecord20, int*, 12);
                    rawWord3 = Level24_881FCField(rawWord3, int*, 4);
                    argumentWord4 = argumentWord7 - argumentWord4;
                    argumentWord5 = rawWord3 - argumentWord5;
                    rawWord2 = Level24_881FCPlanarHeadingLookupView(argumentWord4, argumentWord5,
                                                                    argumentWord6);
                    argumentWord4 = Level24_881FCField(ownerRecord20, unsigned char*, 0x46);
                    rawWord2 = Level24_881FCAbsoluteByteAngleDeltaView(argumentWord4, rawWord2);
                    if (rawWord2 < 24) {
                        rawWord2 = Level24_881FCField(ownerRecord20, int*, 20);
                        rawWord3 = Level24_881FCField(privateRecord19, int*, 20);
                        rawWord2 += rawWord3;
                        Level24_881FCField(ownerRecord20, int*, 20) = rawWord2;
                        rawWord2 = Level24_881FCField(privateRecord19, int*, 20);
                        rawWord2 -= 15;
                        Level24_881FCField(privateRecord19, int*, 20) = rawWord2;
                    }
                    rawWord2 = retainedIndexVectorHeadingOrFlags16 & 4;
                    if (!rawWord2)
                        Level24_881FCField(privateRecord19, short*, 24) = 0;
                    rawWord2 = retainedIndexVectorHeadingOrFlags16 & 1;
                    if (rawWord2)
                        Level24_881FCField(ownerRecord20, unsigned char*, 73) = 3;
                    break;
                case 3:
                    rawWord2 = Level24_881FCProbeGroundFromRaisedMobyView(ownerRecord20);
                    rawWord3 = ((Moby*)ownerRecord20)->position.z;
                    rawWord2 -= rawWord3;
                    rawWord2 >>= 1;
                    rawWord3 += rawWord2;
                    ((Moby*)ownerRecord20)->position.z = rawWord3;
                    rawWord2 = Level24_881FCField(privateRecord19, unsigned short*, 0x12);
                    argumentWord4 = (int)((unsigned int)rawWord2 << 16);
                    rawWord3 = argumentWord4 >> 16;
                    rawWord3 = rawWord3 / 200;
                    rawWord3 += argumentWord4 >> 31;
                    argumentWord4 >>= 31;
                    rawWord2 += Level24_881FCData6C648View;
                    Level24_881FCField(privateRecord19, unsigned short*, 0x12) = rawWord2;
                    rawWord2 = (short)rawWord2 < 7201;
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(argumentWord4), "r"(rawWord2));
                    originalSubstateOrVectorAddress18 = rawWord3 - argumentWord4;
                    rawWord3 = 256;
                    originalSubstateOrVectorAddress18 =
                        rawWord3 - originalSubstateOrVectorAddress18;
                    if (!rawWord2) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x12) = 0x1C20U;
                    }
                    Level24_881FCCopyVectorView(&originalFrame.sp58,
                                                &Level24_881FCData70328View.unk7a[3]);
                    originalFrame.sp58 = (int)originalFrame.sp58 * 0x14;
                    originalFrame.sp5C *= 0x14;
                    originalFrame.sp60 *= 0x14;
                    Level24_881FCShiftVectorRightTowardZeroView(&originalFrame.sp58, 6);
                    Level24_881FCAddVectorView(
                        &originalFrame.sp58, &originalFrame.sp58,
                        (Vector3D*)((unsigned char*)&Level24_881FCData70328View.unk7a[3] - 0x98));
                    retainedPlayerBaseVectorHeadingOrLinkedRecord17 =
                        &((Moby*)ownerRecord20)->position;
                    Level24_881FCApproximatePlanarDistanceView(
                        retainedPlayerBaseVectorHeadingOrLinkedRecord17, &originalFrame.sp58);
                    temporaryValue13 =
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) + 8;
                    Level24_881FCField(privateRecord19, unsigned short*, 0x18) = temporaryValue13;
                    if ((short)temporaryValue13 >= 0x101) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) = 0x100U;
                    }
                    temporaryValue14 = Level24_881FCUpdateMobyPathMotionView(
                        ownerRecord20, Level24_881FCField(privateRecord19, void**, 0), 0x200,
                        originalSubstateOrVectorAddress18, 0,
                        (int)(Level24_881FCField(privateRecord19, unsigned short*, 0x18) << 0x10) >>
                            0x14,
                        0x18, 0);
                    if (!(temporaryValue14 & 4)) {
                        Level24_881FCField(privateRecord19, unsigned short*, 0x18) = 0U;
                    }
                    if (temporaryValue14 & 1) {
                        ((Moby*)ownerRecord20)->substate = 1;
                        temporaryValue9 = Level24_881FCField(privateRecord19, void**, 0);
                        retainedIndexVectorHeadingOrFlags16 =
                            Level24_881FCField(temporaryValue9, short*, 2);
                        if (Level24_881FCField(((retainedIndexVectorHeadingOrFlags16 * 0x10) +
                                                Level24_881FCField(temporaryValue9, int*, 0xC)),
                                               int*, 0xC) == 1) {
                            temporaryValue25 = Level24_881FCField(temporaryValue9, short*, 0);
                            Level24_881FCField(temporaryValue9, short*, 2) =
                                (short)((int)(retainedIndexVectorHeadingOrFlags16 +
                                              Level24_881FCField(temporaryValue9, short*, 0xA) +
                                              temporaryValue25) %
                                        temporaryValue25);
                            temporaryValue15 = Level24_881FCField(privateRecord19, void**, 0);
                            Level24_881FCField(privateRecord19, int*, 0x14) =
                                Level24_881FCComputeArcVerticalVelocityView(
                                    retainedPlayerBaseVectorHeadingOrLinkedRecord17,
                                    Level24_881FCField(temporaryValue15, int*, 0xC) +
                                        (Level24_881FCField(temporaryValue15, short*, 2) * 0x10),
                                    0xF6, -0xF, &originalFrame.sp68);
                            Level24_881FCField(Level24_881FCField(privateRecord19, void**, 0),
                                               short*, 2) = retainedIndexVectorHeadingOrFlags16;
                            ((Moby*)ownerRecord20)->substate = 2;
                        }
                    }
                    break;
            }
            goto reloadOriginalCommonStatus1089;
        case 3:
            Level24_881FCData70328View.unk17a = 0x10000002;
            if (Level24_881FCUpdateMobyMotionDescriptorView(ownerRecord20,
                                                            privateRecord19 + 0x1C) == 0x100) {
                temporaryValue16 = Level24_881FCField(privateRecord19, void**, 4);
                retainedIndexVectorHeadingOrFlags16 =
                    (Level24_881FCField(temporaryValue16, short*, 0) - 1) * 0x10;
                temporaryValue17 = retainedIndexVectorHeadingOrFlags16 +
                                   Level24_881FCField(temporaryValue16, int*, 0xC);
                temporaryValue18 = Level24_881FCPlanarHeadingLookupView(
                    Level24_881FCField(temporaryValue17, int*, -0x10) -
                        Level24_881FCField(temporaryValue17, int*, 0),
                    Level24_881FCField(temporaryValue17, int*, -0xC) -
                        Level24_881FCField(temporaryValue17, int*, 4),
                    0);
                rawWord2 = temporaryValue18 * 2;
                argumentWord4 = Level24_881FCField(&Level24_881FCData65920View, short*, rawWord2);
                MATCHING_KEEP(argumentWord4);
                rawWord3 = (argumentWord4 * 13) >> 5;
                originalFrame.sp70 = rawWord3;
                rawWord3 = Level24_881FCField(&Level24_881FCData658A0View, short*, rawWord2);
                __asm__ volatile("" ::: "$17", "memory");
                retainedPlayerBaseVectorHeadingOrLinkedRecord17 = (int)&originalFrame.sp70;
                originalFrame.sp78 = 0;
                __asm__(""
                        : "=r"(rawWord3)
                        : "0"(rawWord3), "m"(originalFrame.sp78),
                          "r"(retainedPlayerBaseVectorHeadingOrLinkedRecord17));
                rawWord2 = (rawWord3 * 13) >> 5;
                originalFrame.sp74 = rawWord2;
                rawWord2 = Level24_881FCField(privateRecord19, int*, 4);
                __asm__ volatile("" ::: "$5", "memory");
                argumentWord5 = retainedPlayerBaseVectorHeadingOrLinkedRecord17;
                __asm__ volatile("" ::"r"(argumentWord5) : "$4", "memory");
                argumentWord6 = Level24_881FCField(rawWord2, int*, 12);
                argumentWord4 = retainedPlayerBaseVectorHeadingOrLinkedRecord17;
                argumentWord6 += retainedIndexVectorHeadingOrFlags16;
                Level24_881FCAddVectorView(argumentWord4, argumentWord5, argumentWord6);
                retainedIndexVectorHeadingOrFlags16 =
                    retainedIndexVectorHeadingOrFlags16 +
                    Level24_881FCField(Level24_881FCField(privateRecord19, void**, 4), int*, 0xC);
                temporaryValue10 = Level24_881FCPlanarHeadingLookupView(
                    Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 0) -
                        Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, -0x10),
                    Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 4) -
                        Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, -0xC),
                    0);
                originalFrame.sp78 += Level24_881FCData70328View.unk4a;
                Level24_881FCSetCameraMode11TargetView((Vector3D*)&originalFrame.sp70,
                                                       temporaryValue10, 0, 0);
                if (Level24_881FCData70328View.currentHealth < 0) {
                    Level24_881FCData70328View.currentHealth = 0;
                }
                Level24_881FCRefreshMobySpatialGridAndBasisView(ownerRecord20, 4);
                Level24_881FCMarkMobyCollectionBitView(ownerRecord20);
                Level24_881FCEmitMobyVertexParticlesView(ownerRecord20, 0x20);
                ((Moby*)ownerRecord20)->unknown3[0] = 0;
                ((Moby*)ownerRecord20)->lowDrawDistance = 0;
                ((Moby*)ownerRecord20)->drawn = 0;
                ((Moby*)ownerRecord20)->state = 4;
            }
            goto reloadOriginalCommonStatus1089;
        case 4:
            if (Level24_881FCData6E048View & 1) {
                originalSubstateOrVectorAddress18 = (int)&originalFrame.sp80;
                argumentWord4 = originalSubstateOrVectorAddress18;
                rawWord2 = Level24_881FCField(privateRecord19, int*, 4);
                rawWord3 = Level24_881FCField(privateRecord19, int*, 12);
                retainedPlayerBaseVectorHeadingOrLinkedRecord17 = (int)Level24_881FCData6C550View;
                MATCHING_OBSERVE_VOLATILE(retainedPlayerBaseVectorHeadingOrLinkedRecord17);
                retainedIndexVectorHeadingOrFlags16 = Level24_881FCField(rawWord2, short*, 0);
                MATCHING_KEEP_VOLATILE(rawWord2);
                argumentWord5 = Level24_881FCField(rawWord2, int*, 12);
                rawWord2 = rawWord3 * 88;
                retainedPlayerBaseVectorHeadingOrLinkedRecord17 += rawWord2;
                MATCHING_KEEP(retainedPlayerBaseVectorHeadingOrLinkedRecord17);
                retainedIndexVectorHeadingOrFlags16--;
                retainedIndexVectorHeadingOrFlags16 *= 16;
                argumentWord5 += retainedIndexVectorHeadingOrFlags16;
                Level24_881FCCopyVectorView(argumentWord4, argumentWord5);
                Level24_881FCCopyVectorView(
                    &((Moby*)retainedPlayerBaseVectorHeadingOrLinkedRecord17)->position,
                    &originalFrame.sp80);
                Level24_881FCSetMobyZFromGroundProbeView(
                    retainedPlayerBaseVectorHeadingOrLinkedRecord17);
                ((Moby*)retainedPlayerBaseVectorHeadingOrLinkedRecord17)->subtype = 0xFE;
                Level24_881FCRefreshMobySpatialGridAndBasisView(
                    retainedPlayerBaseVectorHeadingOrLinkedRecord17, 2);
                ((Moby*)retainedPlayerBaseVectorHeadingOrLinkedRecord17)->state = 1;
                retainedIndexVectorHeadingOrFlags16 =
                    retainedIndexVectorHeadingOrFlags16 +
                    Level24_881FCField(Level24_881FCField(privateRecord19, void**, 4), int*, 0xC);
                ((Moby*)retainedPlayerBaseVectorHeadingOrLinkedRecord17)->angle.yaw =
                    Level24_881FCPlanarHeadingLookupView(
                        Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, -0x10) -
                            Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 0),
                        Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, -0xC) -
                            Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 4),
                        0);
                Level24_881FCDeleteMobyView(ownerRecord20);
                return;
            }
            goto reloadOriginalCommonStatus1089;
        case 50:
            rawWord2 = Level24_881FCField(ownerRecord20, unsigned char*, 73);
            if (!rawWord2) {
                rawWord2 = Level24_881FCField(ownerRecord20, int*, 20);
                rawWord3 = Level24_881FCField(privateRecord19, int*, 12);
                rawWord2 -= 2048;
                Level24_881FCField(ownerRecord20, int*, 20) = rawWord2;
                rawWord2 = rawWord3 * 88;
                rawWord3 = (int)Level24_881FCData6C550View;
                rawWord3 += rawWord2;
                rawWord2 = Level24_881FCField(rawWord3, int*, 20);
                rawWord2 -= 2048;
                Level24_881FCField(rawWord3, int*, 20) = rawWord2;
                rawWord2 = 1;
                Level24_881FCField(ownerRecord20, unsigned char*, 65) = 0;
                Level24_881FCField(ownerRecord20, unsigned char*, 76) = 0;
                Level24_881FCField(ownerRecord20, unsigned char*, 77) = 0;
                Level24_881FCField(rawWord3, unsigned char*, 65) = 0;
                Level24_881FCField(rawWord3, unsigned char*, 76) = 0;
                Level24_881FCField(rawWord3, unsigned char*, 77) = 0;
                Level24_881FCField(ownerRecord20, unsigned char*, 73) = rawWord2;
            } else if ((unsigned int)rawWord2 >= 2U) {
                argumentWord4 = ownerRecord20;
                argumentWord5 = 1;
                rawWord2 = Level24_881FCField(ownerRecord20, int*, 20);
                rawWord3 = Level24_881FCField(privateRecord19, int*, 12);
                __asm__ volatile("" ::"r"(argumentWord5) : "$16", "memory");
                retainedIndexVectorHeadingOrFlags16 = (int)Level24_881FCData6C550View;
                rawWord2 += 2048;
                Level24_881FCField(ownerRecord20, int*, 20) = rawWord2;
                rawWord2 = rawWord3 * 88;
                retainedIndexVectorHeadingOrFlags16 += rawWord2;
                MATCHING_KEEP(retainedIndexVectorHeadingOrFlags16);
                rawWord2 = Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 20);
                rawWord3 = 32;
                rawWord2 += 2048;
                Level24_881FCField(retainedIndexVectorHeadingOrFlags16, int*, 20) = rawWord2;
                rawWord2 = 1;
                Level24_881FCField(ownerRecord20, unsigned char*, 65) = rawWord2;
                Level24_881FCField(ownerRecord20, unsigned char*, 76) = rawWord3;
                Level24_881FCField(ownerRecord20, unsigned char*, 77) = rawWord2;
                Level24_881FCField(retainedIndexVectorHeadingOrFlags16, unsigned char*, 65) =
                    rawWord2;
                Level24_881FCField(retainedIndexVectorHeadingOrFlags16, unsigned char*, 76) =
                    rawWord3;
                Level24_881FCField(retainedIndexVectorHeadingOrFlags16, unsigned char*, 77) =
                    rawWord2;
                Level24_881FCRefreshMobySpatialGridAndBasisView(argumentWord4, argumentWord5);
                Level24_881FCRefreshMobySpatialGridAndBasisView(retainedIndexVectorHeadingOrFlags16,
                                                                1);
                argumentWord4 = ownerRecord20;
                argumentWord5 = 0;
                Level24_881FCField(ownerRecord20, unsigned char*, 73) = 0;
                goto storeOriginalStateZero1086;
            }
            goto reloadOriginalCommonStatus1089;
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
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            goto reloadOriginalCommonStatus1089;
        default:
            rawWord3 = temporaryValue22;
            goto testOriginalPreparedStatus1090;
    }
storeOriginalStateZero1086:
    ((Moby*)ownerRecord20)->state = 0;
callOriginalStateHelper1087:
    Level24_881FCRequestMobyAnimationView(argumentWord4, argumentWord5);
reloadOriginalCommonStatus1089:
    rawWord3 = ((Moby*)ownerRecord20)->state;
testOriginalPreparedStatus1090:
    MATCHING_BARRIER_VOLATILE("$2");
    if (rawWord3 != 4) {
        Level24_881FCRefreshMobySpatialGridAndBasisView(ownerRecord20, 4);
        Level24_881FCInterpolateMobyVertexView(
            ownerRecord20, 0,
            &Level24_881FCData6C550View[Level24_881FCField(privateRecord19, int*, 0xC)].position);
        rawWord3 = Level24_881FCField(privateRecord19, int*, 12);
        argumentWord4 = (int)Level24_881FCData6C550View;
        rawWord2 = rawWord3 * 88;
        rawWord2 = rawWord2 + argumentWord4;
        temporaryValue11 = (Moby*)rawWord2;
        temporaryValue11->position.z -= 0x80;
        Level24_881FCData6C550View[Level24_881FCField(privateRecord19, int*, 0xC)].subtype = 0xFE;
        Level24_881FCData6C550View[Level24_881FCField(privateRecord19, int*, 0xC)].angle.yaw =
            ((Moby*)ownerRecord20)->angle.yaw;
    }
    return;
}
#undef Level24_881FCField

extern int D_8006C640, D_8006C58C, D_8006E344, D_8006C770;
extern unsigned char D_8006C7B4, D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
void func_80034F40(Moby*, int);
void func_80055B18(Moby*);
void func_level_24_800893FC(Moby* moby) {
    register unsigned char* tag __asm__("$16") = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->damageFlags & 0x4000000) {
                moby->state = 4;
                func_80034F40(moby, 4);
            }
            moby->damageFlags = 0;
            if (!D_8006C640) {
                if ((D_8006C7B4 & 4) || (D_80070300[D_8006C58C] & 4)) {
                    func_80055B18(moby);
                    break;
                }
            }
            if (D_8006C7B4 & 4)
                tag[2] = 2;
            else if (*(int*)((char*)&spyro + 0x280) < 0) {
                tag[2] = 1;
                tag += 2;
                func_8003B7B4(tag, 1, &savedData);
                func_8003B7B4(tag, 1, &unsavedData);
            }
            if (func_80037BBC(moby, 0)) {
                func_800512E4(moby, 0, 2);
                moby->state = 2;
            }
            break;
        case 2:
            if (D_8006E344 == 1)
                break;
            goto reset;
        case 4:
            if (!D_8006C770)
                break;
        reset:
            moby->damageFlags = 0;
            moby->state = 0;
            func_80034F40(moby, 0);
            break;
    }
}

extern int P895C0PlayerZ __asm__("D_80070328 + 8");
extern int P895C0PlayerY __asm__("D_80070328 + 4");
extern Vector3D P895C0PlayerPosition __asm__("D_80070328");
#define P895C0_FIELD(type, base, offset) (*(type*)((unsigned char*)(base) + (offset)))
extern Moby* D_8006C550;
extern int D_8006E020;
extern int D_8006E024;
extern int D_8006E160;
extern Moby* D_8006E164;

/* USA SCUS-94467 Rev 0, 0x800895C0..0x80089978: 239 instructions.
 * Preserves 88-byte Moby indexing, signed path selectors and exact helper order.
 * Raw private offsets, physical units, caller cadence and complete helper
 * producer/consumer meanings remain unresolved. Constraints contain no opcodes.
 * AI generated; not yet human reviewed. */
void func_level_24_800895C0(Moby* moby) {
    Vector3D sample;
    register Moby* owner __asm__("$17") = moby;
    register int angle16 __asm__("$16");
    register int direction18 __asm__("$18");
    register signed char* privateData16 __asm__("$16");
    unsigned char substate;
    register int trig2 __asm__("$2");
    register Vector3D *vector6 __asm__("$6"), *copy4 __asm__("$4"), *copy5 __asm__("$5");
    register int selectedByte2 __asm__("$2");
    register int* playerZ18 __asm__("$18");
    register Vector3D* player20 __asm__("$20");
    register int playerValue3 __asm__("$3");
    register int one19 __asm__("$19");
    register void* path4 __asm__("$4");
    register int angle2 __asm__("$2"), index2 __asm__("$2");
    register Moby* pool4 __asm__("$4");
    register unsigned char* entry3 __asm__("$3");
    register void* pathEntry3 __asm__("$3");
    register int word3 __asm__("$3"), zero6 __asm__("$6"), x7 __asm__("$7"), x4 __asm__("$4"),
        y5 __asm__("$5");

    MATCHING_KEEP(owner);
    privateData16 = owner->mobyTag;
    index2 = P895C0_FIELD(int, privateData16, 0x30);
    MATCHING_KEEP_VOLATILE_CLOBBER(index2, "memory");
    pool4 = D_8006C550;
    __asm__("" : "=r"(pool4) : "0"(pool4), "r"(index2));
    entry3 = (unsigned char*)(index2 * 88 + (int)pool4);
    MATCHING_KEEP(entry3);
    if (P895C0_FIELD(unsigned char, entry3, 0x48) & 0x80)
        goto deleteMoby;
    index2 = P895C0_FIELD(int, privateData16, 0x34);
    entry3 = (unsigned char*)(index2 * 88 + (int)pool4);
    MATCHING_KEEP(entry3);
    if (P895C0_FIELD(unsigned char, entry3, 0x48) & 0x80) {
    deleteMoby:
        if (owner->state != 0) {
            D_8006E160 = 0;
            D_8006E164 = 0;
        }
        func_80055B18(owner);
        return;
    }
    if (owner->state == 0) {
        playerZ18 = &P895C0PlayerZ;
        playerValue3 = *playerZ18;
        MATCHING_KEEP(playerValue3);
        if ((P895C0_FIELD(int, privateData16, 0x18) < playerValue3) &&
            ((index2 = playerValue3 < P895C0_FIELD(int, privateData16, 0x1C)) != 0) &&
            (func_80036220((Vector3D*)((unsigned char*)playerZ18 - 8), privateData16, 0, 0) != 0) &&
            (D_8006E160 == 0)) {
            owner->angle.yaw = func_8004E880(P895C0_FIELD(int, playerZ18, -8) - D_8006E020,
                                             P895C0PlayerY - D_8006E024, 0);
            angle2 = func_8004E880(P895C0_FIELD(int, privateData16, 0x20) -
                                       P895C0_FIELD(int, playerZ18, -8),
                                   P895C0_FIELD(int, privateData16, 0x24) - P895C0PlayerY, 0);
            zero6 = 0;
            __asm__("" : "=r"(zero6) : "0"(zero6), "r"(angle2));
            path4 = P895C0_FIELD(void*, privateData16, 0x2C);
            __asm__("" : "=r"(path4) : "0"(path4), "r"(angle2));
            angle16 = angle2;
            y5 = P895C0PlayerY;
            word3 = P895C0_FIELD(short, path4, 2);
            path4 = (void*)P895C0_FIELD(int, path4, 0xC);
            word3 *= 16;
            pathEntry3 = (void*)(word3 + (int)path4);
            __asm__("" : "=r"(pathEntry3) : "0"(pathEntry3), "r"(y5));
            x7 = P895C0_FIELD(int, pathEntry3, 0);
            x4 = P895C0_FIELD(int, playerZ18, -8);
            word3 = P895C0_FIELD(int, pathEntry3, 4);
            func_8004E880(x7 - x4, word3 - y5, zero6);
            index2 = func_8003613C(angle16, (int)owner->angle.yaw);
            index2 = (unsigned int)index2 < 0x41U;
            MATCHING_KEEP(index2);
            if (index2)
                selectedByte2 = 0xFF;
            else
                selectedByte2 = 1;
            owner->substate = selectedByte2;
            __asm__ volatile("" : : "m"(owner->substate) : "memory");
            trig2 = owner->angle.yaw;
            trig2 = D_80065920[trig2];
            __asm__("" : "=r"(trig2) : "0"(trig2) : "$4", "$5");
            copy4 = &owner->position;
            sample.x = trig2;
            trig2 = owner->angle.yaw;
            __asm__("" : "=r"(trig2) : "0"(trig2), "m"(sample.x) : "$5");
            copy5 = &sample;
            __asm__("" : "=r"(copy5) : "0"(copy5), "r"(trig2));
            trig2 = D_800658A0[trig2];
            __asm__ volatile("" : "=r"(trig2) : "0"(trig2) : "$6", "memory");
            vector6 = &P895C0PlayerPosition;
            __asm__("" : "=r"(vector6) : "0"(vector6), "r"(trig2));
            sample.z = 0;
            sample.y = trig2;
            func_8004F194(copy4, copy5, vector6);
            func_80013ACC(owner, 0xC);
            owner->state = 1;
        }
    } else {
        substate = owner->substate;
        if (substate != 0) {
            one19 = 1;
            direction18 = -1;
            if (substate == one19) {
                direction18 = 1;
            }
            zero6 = 0;
            __asm__("" : "=r"(zero6) : "0"(zero6), "r"(direction18));
            player20 = &P895C0PlayerPosition;
            MATCHING_KEEP(player20);
            angle2 = func_8003585C(
                owner,
                func_8004E880(P895C0_FIELD(int, privateData16, 0x20) - player20->x,
                              P895C0_FIELD(int, privateData16, 0x24) - P895C0PlayerY, zero6),
                2, 0, one19, direction18);
            copy4 = &owner->position;
            if (angle2) {
                func_8004F178(copy4, (Vector3D*)(privateData16 + 0x20));
                owner->substate = 0;
            } else {
                sample.x = (int)D_80065920[owner->angle.yaw];
                trig2 = owner->angle.yaw;
                __asm__("" : "=r"(trig2) : "0"(trig2), "m"(sample.x) : "$5");
                copy5 = &sample;
                __asm__("" : "=r"(copy5) : "0"(copy5), "r"(trig2));
                trig2 = D_800658A0[trig2];
                __asm__ volatile("" : "=r"(trig2) : "0"(trig2) : "$6", "memory");
                vector6 = player20;
                __asm__("" : "=r"(vector6) : "0"(vector6), "r"(trig2));
                sample.z = 0;
                sample.y = trig2;
                func_8004F194(copy4, copy5, vector6);
            }
        }
        if (D_8006E164 != owner) {
            copy4 = &owner->position;
            MATCHING_KEEP(copy4);
            copy5 = (Vector3D*)(privateData16 + 0x20);
            goto copyPositionAndClearState;
        }
        if ((spyro.position.z < (P895C0_FIELD(int, privateData16, 0x18) - 0x200)) ||
            ((P895C0_FIELD(int, privateData16, 0x1C) + 0x200) < spyro.position.z) ||
            (func_80036220((Vector3D*)&spyro.position, privateData16, 0x200, 0) == 0)) {
            copy4 = &owner->position;
            copy5 = (Vector3D*)(privateData16 + 0x20);
            __asm__("" : "=r"(copy4) : "0"(copy4), "r"(copy5));
            D_8006E160 = 0;
            D_8006E164 = 0;
        copyPositionAndClearState:
            MATCHING_OBSERVE2(copy4, copy5);
            func_8004F178(copy4, copy5);
            owner->state = 0;
        }
    }
}

typedef struct {
    Vector3D position;
    int reserved0C;
} DecodedParticlePathPoint;
typedef struct {
    short count;
    unsigned char reserved02[10];
    DecodedParticlePathPoint* points;
} DecodedParticlePath;
typedef struct {
    int timer;
    DecodedParticlePath* path;
} DecodedPathParticleTag;
int rand(void);
void func_level_24_8008997C(Moby* moby) {
    DecodedPathParticleTag* tag = moby->mobyTag;
    Vector3D offset;
    int randomValue, spacing, index, remainder;
    if (func_800359A4(&tag->timer, 4)) {
        if (!tag->path)
            func_8004F178(&offset, &moby->position);
        else {
            randomValue = rand() & 0xFFF;
            spacing = 0x1000 / (tag->path->count - 1);
            index = randomValue / spacing;
            remainder = randomValue % spacing;
            func_8004F1C8(&offset, &tag->path->points[index + 1].position,
                          &tag->path->points[index].position);
            func_8004F08C(&offset, spacing, remainder);
            func_8004F194(&offset, &offset, &tag->path->points[index].position);
        }
        SpawnParticle(1, 0x30, &offset, (Vector3D*)(unsigned int)moby->angle.yaw);
        tag->timer = (rand() & 3) + 3;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80089AEC.
* AI generated; not human reviewed. All1157 original instructions and every
* actual destination must match:1157 recorded words;no selectors or padding.
* FrameE8hex=232 bytes saves S0..S7/FP/RA;SP18..BF retains original locals.
* The full proximity flag allocates naturally to FP;no fixed FP binding.
* Ordered dispatch0/1/4/2/3/6/20/5/97 and shared physical entries are retained.
* Original240 bypasses the fallthrough S0 producer275 and enters276,using
* the complete owner-position address already produced in its delay slot.
* Original first helper receives the incoming owner,not a null decoder guess.
* State0 success stores literal1,independently of the timer-helper result.
* Halfword flag writes and fresh unsigned reads remain separate operations.
* Independent full SP38 argument expressions retain both original ADDIU
* producers;the ABI stack pointer is read only. No stack-pointer assignment.
* Full trig samples preserve LHU/SLL16/SRA23 and original independent LW
* fillers. Products are complete low32 C values;no partial HI/LO synthesis.
* Complete owner/vector/player/spawn/counter phases retain original widths,
* RNG order,burst bounds,state stores and helper-visible memory ordering.
* Original1029 prepares A1 in the distance-branch delay slot;the following
* helper receives complete SP98/SPA8 vector addresses. Shared final writes
* and original state-helper entries keep all exact branch destinations.
* Empty metadata consumes complete initialized values or written fields,
* or clobbers dead values before fresh complete producers;zero CPU words.
* No opcode asm,undefined saved input,live overlapping fixed aliases or
* compiler/filter/flag changes. Units/fixed point,complete helper/caller
* chains,cadence beyond invocation,Rev1 mapping and synchronized runtime
* remain open. Confidence is binary identity after all gates. Next:human
* review and retail captures. Every native/linked word,actual destination,
* full EXE and every overlay retail hash must remain identical.
*/
/* Original assembly SHA256 42b6f338415bfc8a9c689398656f11f1eff8a4e78aff68f3bed1d0a548ca813b */
#define Level24_89AECField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level24_89AECTestSubdividedSegmentPathView1() __asm__("func_80013E38");
int Level24_89AECQueryWorldSegmentWithOptionsView1() __asm__("func_8001830C");
int Level24_89AECQueryWorldHeightView1() __asm__("func_8001A358");
int Level24_89AECQueryDynamicMobyGeometryView1() __asm__("func_8001BA30");
int Level24_89AECRequestMobyAnimationView1() __asm__("func_80034F40");
int Level24_89AECUpdateMobyMotionDescriptorView1() __asm__("func_80035194");
int Level24_89AECTurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level24_89AECTurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level24_89AECCountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level24_89AECResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level24_89AECRandBetweenView1() __asm__("func_8003636C");
int Level24_89AECEmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level24_89AECSpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
int Level24_89AECInitializeMobyMotionStateView1() __asm__("func_80038BF8");
int Level24_89AECMarkMobyCollectionBitView1() __asm__("func_8003BA00");
int Level24_89AECPlayMobySoundEventView1() __asm__("func_8003BABC");
int Level24_89AECPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level24_89AECTransformVectorByBasisView1() __asm__("func_8004ED6C");
int Level24_89AECMeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level24_89AECScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level24_89AECCopyVectorView1() __asm__("func_8004F178");
int Level24_89AECAddVectorView1() __asm__("func_8004F194");
int Level24_89AECSubtractVectorView1() __asm__("func_8004F1C8");
int Level24_89AECAbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level24_89AECApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level24_89AECDeleteMobyView1() __asm__("func_80055B18");
int Level24_89AECRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level24_89AECReadSelectedFrameScalarView1() __asm__("func_80055E84");
int Level24_89AECInterpolateMobyVertexView1() __asm__("func_80055F14");
int Level24_89AECDatarandView1(void) __asm__("rand");
extern int Level24_89AECData658A0View1 __asm__("D_800658A0");
extern int Level24_89AECData65920View1 __asm__("D_80065920");
extern int Level24_89AECData6C550View1 __asm__("D_8006C550");
extern int Level24_89AECData6C574View1 __asm__("D_8006C574");
extern int Level24_89AECData6C578View1 __asm__("D_8006C578");
extern int Level24_89AECData6C648View1 __asm__("D_8006C648");
extern int Level24_89AECData6C770View1 __asm__("D_8006C770");
extern int Level24_89AECData6C7C0View1 __asm__("D_8006C7C0");
extern int Level24_89AECData6E020View1 __asm__("D_8006E020");
extern int Level24_89AECData6E024View1 __asm__("D_8006E024");
extern unsigned short Level24_89AECData6E040View1 __asm__("D_8006E040");
extern int Level24_89AECData6E1D4View1 __asm__("D_8006E1D4");
extern int Level24_89AECData6E1D8View1 __asm__("D_8006E1D8");
extern int Level24_89AECData6E344View1 __asm__("D_8006E344");
extern int Level24_89AECData70328View1 __asm__("D_80070328");
extern int Level24_89AECData71908View1 __asm__("D_80071908");
extern void* (*Level24_89AECDataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level24_89AECDataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_24_80089AEC(void* ownerParameter) {
    register void* ownerRecord19 __asm__("$19");
    register int retainedTwoOrVector22 __asm__("$22"), retainedPlayerPosition23 __asm__("$23");
    register int privateRecord20 __asm__("$20"), retainedVectorRecordOrDistance16 __asm__("$16"),
        retainedLiteralPlayerSpawnOrIndex17 __asm__("$17"),
        retainedStateVectorOrParticleIndex18 __asm__("$18"),
        retainedStepFlagOrPosition21 __asm__("$21");
    register unsigned char* originalAbiStack29 __asm__("$29");
    register int productOrOriginalFrameFlag8 __asm__("$8");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84,
            sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC;
    } originalFrame;
    int temporaryWord6;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord5;
    int temporaryWord9;
    int var_fp;
    int temporaryWord12;
    int temporaryWord7;
    int temporaryWord10;
    int temporaryWord4;
    int temporaryWord8;
    int temporaryWord11;
    argumentWord4 = (int)ownerParameter;
    ownerRecord19 = ownerParameter;
    MATCHING_KEEP(ownerRecord19);
    temporaryWord3 =
        (unsigned int)(Level24_89AECField(ownerRecord19, unsigned char*, 0x48) - 5) >= 0x10U;
    originalFrame.spB8 = temporaryWord3;
    privateRecord20 = Level24_89AECField(ownerRecord19, void**, 0);
    var_fp = 0;
    if (temporaryWord3 != 0) {
        temporaryWord9 = Level24_89AECField(ownerRecord19, int*, 0x18);
        if (!(temporaryWord9 & 0x20000)) {
            if (temporaryWord9 & 0x10000) {
                Level24_89AECPlayMobySoundEventView1(argumentWord4, 0, 0);
                Level24_89AECSpawnMobyFromValueSelectorView1(ownerRecord19, 1, 0, 0);
                Level24_89AECField(ownerRecord19, unsigned char*, 0x4A) = 0xFF;
                Level24_89AECField(privateRecord20, short*, 0x1A) = 0;
                Level24_89AECField(ownerRecord19, int*, 0x18) = 0;
                Level24_89AECField(privateRecord20, int*, 0x14) = 0;
                Level24_89AECField(ownerRecord19, unsigned char*, 0x48) = 5U;
                Level24_89AECRequestMobyAnimationView1(ownerRecord19, 5);
                Level24_89AECField(ownerRecord19, unsigned char*, 0x40) = 0xA0;
                return;
            }
            goto checkOriginalInitialization54;
        }
        Level24_89AECSpawnMobyFromValueSelectorView1(ownerRecord19, 0, 0, 0);
        Level24_89AECInitializeMobyMotionStateView1(ownerRecord19, privateRecord20 + 0x24, 0, 6);
        goto checkOriginalInitialization54;
    }
checkOriginalInitialization54:
    rawWord2 = Level24_89AECField(ownerRecord19, unsigned char*, 73);
    if (rawWord2) {
        rawWord2 = 4;
        goto originalDispatch84;
    }
    retainedVectorRecordOrDistance16 = 1;
    rawWord3 = Level24_89AECField(ownerRecord19, unsigned char*, 72);
    rawWord2 = 97;
    Level24_89AECField(ownerRecord19, unsigned char*, 73) = retainedVectorRecordOrDistance16;
    if (rawWord3 == rawWord2) {
        argumentWord4 = (int)ownerRecord19;
        MATCHING_BARRIER_VOLATILE("$5");
        argumentWord5 = 0;
        argumentWord4 = (int)ownerRecord19;
        goto callOriginalStateHelper1142;
    }
    rawWord2 = Level24_89AECDatarandView1();
    argumentWord4 = (int)ownerRecord19;
    if (rawWord2 & 1) {
        MATCHING_BARRIER_VOLATILE("$5");
        argumentWord5 = 0;
        argumentWord4 = (int)ownerRecord19;
        MATCHING_BARRIER_VOLATILE("$5");
        argumentWord5 = 0;
        rawWord2 = 360;
        Level24_89AECField(privateRecord20, int*, 20) = rawWord2;
        __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, int*, 20)),
                         "r"(argumentWord4), "r"(argumentWord5), "i"(0x80089c20)
                         : "memory");
        Level24_89AECField(argumentWord4, unsigned char*, 72) = 0;
        argumentWord4 = (int)ownerRecord19;
        goto callOriginalStateHelper1142;
    }
    Level24_89AECField(ownerRecord19, unsigned char*, 72) = retainedVectorRecordOrDistance16;
    argumentWord5 = 1;
    argumentWord4 = (int)ownerRecord19;
    goto callOriginalStateHelper1142;
originalDispatch84:
    rawWord3 = Level24_89AECField(ownerRecord19, unsigned char*, 72);
    MATCHING_KEEP(rawWord3);
    if (rawWord3 == rawWord2)
        goto originalState4;
    if (rawWord3 < 5) {
        retainedLiteralPlayerSpawnOrIndex17 = 1;
        if (rawWord3 == retainedLiteralPlayerSpawnOrIndex17)
            goto originalState1;
        retainedTwoOrVector22 = 2;
        if (rawWord3 < 2) {
            if (!rawWord3)
                goto originalState0;
            goto checkOriginalProximity1064;
        }
        if (rawWord3 == retainedTwoOrVector22)
            goto originalState2;
        if (rawWord3 == 3)
            goto originalState3;
        goto checkOriginalProximity1064;
    }
    if (rawWord3 == 6)
        goto originalState6;
    if (rawWord3 < 6)
        goto originalState5;
    if (rawWord3 == 20)
        goto originalState20;
    retainedLiteralPlayerSpawnOrIndex17 = 0;
    if (rawWord3 == 97)
        goto originalState97;
    goto checkOriginalProximity1064;
originalState0:
    MATCHING_KEEP(rawWord3);
    var_fp = 1;
    if (Level24_89AECField(privateRecord20, short*, 0x1A) != 0) {
        Level24_89AECRequestMobyAnimationView1(ownerRecord19, 0);
        Level24_89AECField(ownerRecord19, unsigned char*, 0x48) =
            (unsigned char)(unsigned short)Level24_89AECField(privateRecord20, short*, 0x1A);
        return;
    }
    rawWord2 = Level24_89AECCountTimerDownView1(privateRecord20 + 20, 4);
    if (rawWord2) {
        rawWord2 = 1;
        MATCHING_KEEP(rawWord2);
        Level24_89AECField(ownerRecord19, unsigned char*, 72) = rawWord2;
        __asm__ volatile("" ::"m"(Level24_89AECField(ownerRecord19, unsigned char*, 72))
                         : "$4", "$5", "memory");
        argumentWord4 = (int)ownerRecord19;
        argumentWord5 = 1;
        goto callOriginalStateHelper1142;
    }
    goto checkOriginalProximity1064;
originalState1:
    MATCHING_KEEP(rawWord3);
    MATCHING_KEEP(retainedLiteralPlayerSpawnOrIndex17);
    var_fp = 1;
    if (Level24_89AECData6C770View1 != 0) {
        Level24_89AECField(privateRecord20, int*, 0x14) = 0x12C;
        Level24_89AECField(ownerRecord19, unsigned char*, 0x48) = 0U;
        Level24_89AECRequestMobyAnimationView1(ownerRecord19, 0);
    }
    goto checkOriginalProximity1064;
originalState4:
    rawWord2 = Level24_89AECData6C770View1;
    if (!rawWord2)
        goto checkOriginalProximity1064;
    rawWord2 = Level24_89AECField(privateRecord20, short*, 14);
    if (rawWord2 > 0) {
        rawWord2 = 2;
        goto writeOriginalState1139;
    }
    argumentWord4 = (int)ownerRecord19;
    MATCHING_BARRIER_VOLATILE("$5");
    argumentWord5 = 0;
    argumentWord4 = (int)ownerRecord19;
    MATCHING_BARRIER_VOLATILE("$5");
    argumentWord5 = 0;
    rawWord2 = 360;
    Level24_89AECField(privateRecord20, int*, 20) = rawWord2;
    __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, int*, 20)), "r"(argumentWord4),
                     "r"(argumentWord5), "i"(0x80089d68)
                     : "memory");
    Level24_89AECField(argumentWord4, unsigned char*, 72) = 0;
    goto callOriginalStateHelper1142;
originalState2:
    argumentWord4 = Level24_89AECField(privateRecord20, unsigned short*, 0x10);
    rawWord2 = argumentWord4 & 1;
    if (!rawWord2) {
        rawWord2 = argumentWord4 & 2;
        goto originalBit2Test224;
    }
    {
        rawWord2 = Level24_89AECField(privateRecord20, short*, 18);
        rawWord3 = Level24_89AECField(ownerRecord19, unsigned char*, 70);
        rawWord2 -= rawWord3;
        if (rawWord2 < 0) {
            rawWord2 = -rawWord2;
        }
        if (rawWord2 < 8) {
            if ((Level24_89AECTestSubdividedSegmentPathView1(
                     ownerRecord19 + 0xC, (int)&Level24_89AECData70328View1, 0) != 0) &&
                (Level24_89AECAbsoluteByteAngleDeltaView1(
                     (int)(Level24_89AECData6E040View1 << 0x10) >> 0x14,
                     Level24_89AECPlanarHeadingLookupView1(
                         Level24_89AECField(ownerRecord19, int*, 0xC) -
                             Level24_89AECField((int)&Level24_89AECData6E020View1, int*, 0),
                         Level24_89AECField(ownerRecord19, int*, 0x10) -
                             Level24_89AECData6E024View1,
                         0)) < 0x18) &&
                (Level24_89AECData6E344View1 != retainedLiteralPlayerSpawnOrIndex17)) {
                argumentWord4 = (int)ownerRecord19;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$5");
                argumentWord5 = 3;
                rawWord2 = 3;
                __asm__(""
                        : "=r"(rawWord2)
                        : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
                Level24_89AECField(privateRecord20, volatile unsigned short*, 16) = 0;
                Level24_89AECField(privateRecord20, short*, 24) = 0;
                __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, unsigned short*, 16)),
                                 "m"(Level24_89AECField(privateRecord20, short*, 24)),
                                 "r"(argumentWord4), "r"(argumentWord5), "r"(rawWord2),
                                 "i"(0x80089e34)
                                 : "memory");
                Level24_89AECField(argumentWord4, unsigned char*, 72) = rawWord2;
            } else {
                MATCHING_BARRIER_VOLATILE("$5");
                argumentWord5 = 0;
                argumentWord4 = (int)ownerRecord19;
                MATCHING_BARRIER_VOLATILE("$5");
                argumentWord5 = 0;
                rawWord2 = 360;
                Level24_89AECField(privateRecord20, int*, 20) = rawWord2;
                __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, int*, 20)),
                                 "r"(argumentWord4), "r"(argumentWord5), "i"(0x80089e4c)
                                 : "memory");
                Level24_89AECField(argumentWord4, unsigned char*, 72) = 0;
            }
            goto callOriginalStateHelper1142;
        }
        rawWord2 = argumentWord4 & 252;
        Level24_89AECField(privateRecord20, unsigned short*, 16) = rawWord2;
        __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, unsigned short*, 16))
                         : "memory");
        argumentWord4 = Level24_89AECField(privateRecord20, unsigned short*, 16);
        rawWord2 = argumentWord4 & 2;
        goto testOriginalHeadingBit224;
    }
testOriginalHeadingBit224:
originalBit2Test224:
    if (rawWord2 != 0) {
        rawWord2 = Level24_89AECField(privateRecord20, short*, 18);
        rawWord3 = Level24_89AECField(ownerRecord19, unsigned char*, 70);
        rawWord2 -= rawWord3;
        if (rawWord2 < 0) {
            rawWord2 = -rawWord2;
        }
        if (rawWord2 >= 8) {
            rawWord2 = argumentWord4 & 252;
            Level24_89AECField(privateRecord20, unsigned short*, 16) = rawWord2;
        }
    }
    retainedVectorRecordOrDistance16 = ownerRecord19 + 0xC;
    MATCHING_KEEP(ownerRecord19);
    retainedVectorRecordOrDistance16 = (int)ownerRecord19 + 12;
    if (Level24_89AECField(privateRecord20, unsigned short*, 16) & 3)
        goto originalDistance276;
    {
        MATCHING_OBSERVE_VOLATILE(retainedVectorRecordOrDistance16);
        argumentWord4 = (int)ownerRecord19 + 32;
        argumentWord5 = (int)&originalFrame.sp18;
        __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5) : "$16", "memory");
        retainedVectorRecordOrDistance16 = (int)&originalFrame.sp28;
        rawWord2 = Level24_89AECField(privateRecord20, short*, 14);
        argumentWord6 = retainedVectorRecordOrDistance16;
        originalFrame.sp1C = 0;
        originalFrame.sp20 = 0;
        rawWord2 += 1024;
        originalFrame.sp18 = rawWord2;
        Level24_89AECTransformVectorByBasisView1(argumentWord4, argumentWord5, argumentWord6);
        argumentWord4 = retainedVectorRecordOrDistance16;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
        MATCHING_KEEP(ownerRecord19);
        retainedLiteralPlayerSpawnOrIndex17 = (int)ownerRecord19 + 12;
        argumentWord5 = retainedLiteralPlayerSpawnOrIndex17;
        argumentWord6 = retainedVectorRecordOrDistance16;
        Level24_89AECAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
        if (Level24_89AECQueryWorldSegmentWithOptionsView1(
                retainedLiteralPlayerSpawnOrIndex17, retainedVectorRecordOrDistance16, 1, 0, 0)) {
            rawWord2 = Level24_89AECField(privateRecord20, unsigned short*, 16) | 1;
        } else
            rawWord2 = Level24_89AECField(privateRecord20, unsigned short*, 16) | 2;
        Level24_89AECField(privateRecord20, unsigned short*, 16) = rawWord2;
        rawWord2 = Level24_89AECField(ownerRecord19, unsigned char*, 70);
        Level24_89AECField(privateRecord20, short*, 18) = rawWord2;
    }
    __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, short*, 18)) : "$16", "memory");
    MATCHING_KEEP(ownerRecord19);
    retainedVectorRecordOrDistance16 = (int)ownerRecord19 + 12;
originalDistance276:
    argumentWord4 = retainedVectorRecordOrDistance16;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
    retainedLiteralPlayerSpawnOrIndex17 = (int)&Level24_89AECData70328View1;
    temporaryWord5 = Level24_89AECApproximatePlanarDistanceView1(
        argumentWord4, retainedLiteralPlayerSpawnOrIndex17);
    if (temporaryWord5 < Level24_89AECField(privateRecord20, short*, 0xC)) {
        if ((Level24_89AECTestSubdividedSegmentPathView1(
                 retainedVectorRecordOrDistance16, (int)&Level24_89AECData70328View1, 0) != 0) &&
            (Level24_89AECAbsoluteByteAngleDeltaView1(
                 (int)(Level24_89AECData6E040View1 << 0x10) >> 0x14,
                 Level24_89AECPlanarHeadingLookupView1(
                     Level24_89AECField(ownerRecord19, int*, 0xC) -
                         Level24_89AECField((int)&Level24_89AECData6E020View1, int*, 0),
                     Level24_89AECField(ownerRecord19, int*, 0x10) - Level24_89AECData6E024View1,
                     0)) < 0x18) &&
            (Level24_89AECData6E344View1 != 1)) {
            argumentWord4 = (int)ownerRecord19;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$5");
            argumentWord5 = 3;
            rawWord2 = 3;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
            Level24_89AECField(privateRecord20, unsigned short*, 16) = 0;
            Level24_89AECField(privateRecord20, short*, 24) = 0;
            __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, unsigned short*, 16)),
                             "m"(Level24_89AECField(privateRecord20, short*, 24)),
                             "r"(argumentWord4), "r"(argumentWord5), "r"(rawWord2), "i"(0x80089fdc)
                             : "memory");
            Level24_89AECField(argumentWord4, unsigned char*, 72) = rawWord2;
        } else {
            MATCHING_BARRIER_VOLATILE("$5");
            argumentWord5 = 0;
            argumentWord4 = (int)ownerRecord19;
            MATCHING_BARRIER_VOLATILE("$5");
            argumentWord5 = 0;
            rawWord2 = 360;
            Level24_89AECField(privateRecord20, int*, 20) = rawWord2;
            __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, int*, 20)),
                             "r"(argumentWord4), "r"(argumentWord5), "i"(0x80089ff4)
                             : "memory");
            Level24_89AECField(argumentWord4, unsigned char*, 72) = 0;
        }
        goto callOriginalStateHelper1142;
    }
    if ((Level24_89AECField(privateRecord20, unsigned short*, 0x10) & 4) ||
        ((rawWord2 = Level24_89AECApproximatePlanarDistanceView1(retainedVectorRecordOrDistance16,
                                                                 privateRecord20)),
         (rawWord3 = Level24_89AECField(privateRecord20, short*, 14)),
         (rawWord3 = rawWord3 < rawWord2))) {
        Level24_89AECTurnMobyTowardHeadingView1(
            ownerRecord19,
            Level24_89AECPlanarHeadingLookupView1(Level24_89AECField(privateRecord20, int*, 0) -
                                                      Level24_89AECField(ownerRecord19, int*, 0xC),
                                                  Level24_89AECField(privateRecord20, int*, 4) -
                                                      Level24_89AECField(ownerRecord19, int*, 0x10),
                                                  0),
            8, 0x18, 0, 0);
        temporaryWord10 = Level24_89AECField(privateRecord20, unsigned short*, 0x10);
        if (temporaryWord10 & 4) {
            if (Level24_89AECApproximatePlanarDistanceView1(retainedVectorRecordOrDistance16,
                                                            privateRecord20) < 0x100) {
                Level24_89AECField(privateRecord20, unsigned short*, 0x10) =
                    (unsigned short)(Level24_89AECField(privateRecord20, unsigned short*, 0x10) &
                                     0xFB);
            }
        } else {
            Level24_89AECField(privateRecord20, unsigned short*, 0x10) =
                (unsigned short)(temporaryWord10 | 4);
        }
    } else {
        MATCHING_KEEP(rawWord3);
        Level24_89AECTurnMobyTowardPlayerView1(ownerRecord19, 8, 0, 0);
    }
    Level24_89AECResolveMobyYawStepView1(ownerRecord19, 0x64, 0, 0, 4);
    temporaryWord1 = Level24_89AECField(privateRecord20, short*, 0xC) +
                     Level24_89AECField(privateRecord20, short*, 0xE);
    if (!(Level24_89AECField(privateRecord20, unsigned short*, 0x10) & 4) &&
        (temporaryWord1 < temporaryWord5)) {
        Level24_89AECField(privateRecord20, unsigned short*, 0x10) = 0U;
        if ((Level24_89AECField(privateRecord20, short*, 0x1A) != 0) ||
            (Level24_89AECDatarandView1() & 1)) {
            MATCHING_BARRIER_VOLATILE("$5");
            argumentWord5 = 0;
            argumentWord4 = (int)ownerRecord19;
            MATCHING_BARRIER_VOLATILE("$5");
            argumentWord5 = 0;
            rawWord2 = 360;
            Level24_89AECField(privateRecord20, int*, 20) = rawWord2;
            __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, int*, 20)),
                             "r"(argumentWord4), "r"(argumentWord5), "i"(0x8008a138)
                             : "memory");
            Level24_89AECField(argumentWord4, unsigned char*, 72) = 0;
        } else {
            Level24_89AECField(ownerRecord19, unsigned char*, 72) = 1;
            argumentWord4 = (int)ownerRecord19;
            MATCHING_OBSERVE_VOLATILE(argumentWord4);
            argumentWord5 = 1;
        }
        goto callOriginalStateHelper1142;
    }
    goto checkOriginalProximity1064;
originalState3:
    retainedVectorRecordOrDistance16 = Level24_89AECReadSelectedFrameScalarView1(ownerRecord19);
    if ((unsigned int)(retainedVectorRecordOrDistance16 - 0x16) < 6U) {
        Level24_89AECRefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
        Level24_89AECInterpolateMobyVertexView1(ownerRecord19, 0, &originalFrame.sp18);
        originalFrame.sp38 = 0;
        originalFrame.sp3C = 0;
        originalFrame.sp40 = 0x1E;
        Level24_89AECDataSpawnParticleView1(1, 0xD, &originalFrame.sp18, &originalFrame.sp38);
    }
    retainedStateVectorOrParticleIndex18 = Level24_89AECField(ownerRecord19, unsigned char*, 0x49);
    if (retainedStateVectorOrParticleIndex18 == retainedLiteralPlayerSpawnOrIndex17) {
        retainedStepFlagOrPosition21 = 0;
        rawWord2 = retainedVectorRecordOrDistance16 < 35;
        if (!rawWord2) {
            retainedLiteralPlayerSpawnOrIndex17 = Level24_89AECDataSpawnMobyView1(6, ownerRecord19);
            if (retainedLiteralPlayerSpawnOrIndex17 != 0) {
                Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 0x4A) =
                    0xFF;
                Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 0x44) =
                    (unsigned char)Level24_89AECField(ownerRecord19, unsigned char*, 0x44);
                Level24_89AECRefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
                Level24_89AECInterpolateMobyVertexView1(ownerRecord19, 1,
                                                        retainedLiteralPlayerSpawnOrIndex17 + 0xC);
                rawWord2 = Level24_89AECField(privateRecord20, short*, 24);
                retainedVectorRecordOrDistance16 = (int)&originalFrame.sp38;
                if (rawWord2 == 0) {
                    Level24_89AECCopyVectorView1(retainedVectorRecordOrDistance16,
                                                 (int)&Level24_89AECData70328View1);
                    originalFrame.sp40 += 256;
                    if (Level24_89AECQueryWorldHeightView1(retainedVectorRecordOrDistance16, 4096))
                        originalFrame.sp40 = Level24_89AECData71908View1;
                    else
                        originalFrame.sp40 -= 2048;
                    goto originalPosition505;
                }
                MATCHING_KEEP(retainedVectorRecordOrDistance16);
                if (rawWord2 == retainedStateVectorOrParticleIndex18) {
                    argumentWord4 = (int)originalAbiStack29 + 56;
                    rawWord2 = Level24_89AECField(privateRecord20, int*, 28);
                    retainedStepFlagOrPosition21 = 2;
                    goto originalActorIndex495;
                }
                if (rawWord2 == retainedTwoOrVector22) {
                    argumentWord4 = (int)originalAbiStack29 + 56;
                } else {
                    argumentWord4 = (int)ownerRecord19 + 12;
                    goto originalDistance506;
                }
                rawWord2 = Level24_89AECField(privateRecord20, int*, 32);
                retainedStepFlagOrPosition21 = 2;
            originalActorIndex495:
                rawWord3 = rawWord2 * 88;
                rawWord2 = Level24_89AECData6C550View1 + rawWord3;
                Level24_89AECCopyVectorView1(argumentWord4, rawWord2 + 12);
            originalPosition505:
                argumentWord4 = (int)ownerRecord19 + 12;
            originalDistance506:
                Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 0x45) =
                    Level24_89AECPlanarHeadingLookupView1(
                        Level24_89AECApproximatePlanarDistanceView1(argumentWord4,
                                                                    &originalFrame.sp38),
                        originalFrame.sp40 - Level24_89AECField(ownerRecord19, int*, 0x14), 0);
                Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 0x46) =
                    (unsigned char)Level24_89AECField(ownerRecord19, unsigned char*, 0x46);
                Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, int*, 0x14) =
                    (int)(Level24_89AECField(ownerRecord19, int*, 0x14) + 0x180);
                Level24_89AECTurnMobyTowardHeadingView1(
                    retainedLiteralPlayerSpawnOrIndex17,
                    Level24_89AECPlanarHeadingLookupView1(
                        originalFrame.sp38 -
                            Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, int*, 0xC),
                        originalFrame.sp3C -
                            Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, int*, 0x10),
                        0),
                    0x80, 0, 0, 0);
                retainedVectorRecordOrDistance16 =
                    Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, int*, 0);
                rawWord2 = Level24_89AECDatarandView1();
                rawWord2 &= 31;
                rawWord3 =
                    Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 68);
                rawWord2 *= 8;
                rawWord3 += rawWord2;
                Level24_89AECField(retainedVectorRecordOrDistance16, signed char*, 0) = rawWord3;
                rawWord2 =
                    Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 69);
                Level24_89AECField(retainedVectorRecordOrDistance16, unsigned char*, 1) = rawWord2;
                rawWord3 =
                    Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, unsigned char*, 70);
                __asm__ volatile("" ::: "$2", "memory");
                rawWord2 = 180;
                MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord2, rawWord3, "memory");
                Level24_89AECField(retainedVectorRecordOrDistance16, int*, 8) = rawWord2;
                Level24_89AECField(retainedVectorRecordOrDistance16, signed char*, 3) =
                    retainedStepFlagOrPosition21;
                Level24_89AECField(retainedVectorRecordOrDistance16, unsigned char*, 2) = rawWord3;
            }
            Level24_89AECField(ownerRecord19, unsigned char*, 0x49) = 2U;
            return;
        }
    }
    rawWord3 = Level24_89AECField(privateRecord20, short*, 24);
    if (!rawWord3) {
        argumentWord5 = (int)&Level24_89AECData70328View1;
        argumentWord4 = (int)originalAbiStack29 + 56;
        goto originalCopy580;
    }
    rawWord2 = 1;
    if (rawWord3 == rawWord2) {
        rawWord2 = Level24_89AECField(privateRecord20, int*, 28);
        argumentWord4 = (int)originalAbiStack29 + 56;
        goto originalIndex571;
    }
    rawWord2 = 2;
    argumentWord6 = 0;
    if (rawWord3 != rawWord2)
        goto originalHeading583;
    rawWord2 = Level24_89AECField(privateRecord20, int*, 32);
    argumentWord4 = (int)originalAbiStack29 + 56;
originalIndex571:
    rawWord3 = rawWord2 * 88;
    rawWord2 = Level24_89AECData6C550View1 + rawWord3;
    argumentWord5 = rawWord2 + 12;
originalCopy580:
    Level24_89AECCopyVectorView1(argumentWord4, argumentWord5);
    argumentWord6 = 0;
originalHeading583:
    Level24_89AECTurnMobyTowardHeadingView1(
        ownerRecord19,
        Level24_89AECPlanarHeadingLookupView1(
            originalFrame.sp38 - Level24_89AECField(ownerRecord19, int*, 0xC),
            originalFrame.sp3C - Level24_89AECField(ownerRecord19, int*, 0x10), 0),
        6, 2, 1, 0);
    argumentWord5 = 4;
    if (Level24_89AECData6C770View1 != 0) {
        Level24_89AECField(ownerRecord19, unsigned char*, 0x49) = 1U;
        Level24_89AECField(ownerRecord19, unsigned char*, 0x48) = 4U;
        argumentWord4 = (int)ownerRecord19;
        goto callOriginalStateHelper1142;
    }
    goto checkOriginalProximity1064;
originalState6:
    rawWord2 = Level24_89AECUpdateMobyMotionDescriptorView1(ownerRecord19, privateRecord20 + 36);
    rawWord3 = 256;
    if (rawWord2 != rawWord3)
        goto checkOriginalProximity1064;
    MATCHING_OBSERVE_VOLATILE(ownerRecord19);
    goto enterOriginalRemoval927;
originalState20:
    retainedStepFlagOrPosition21 = 0;
    originalFrame.sp48 = 0;
    originalFrame.sp4C = 0;
    originalFrame.sp50 = 0;
    Level24_89AECDataSpawnParticleView1(1, 0xD, ownerRecord19 + 0xC, &originalFrame.sp48);
    argumentWord5 = Level24_89AECField(privateRecord20, short*, 0x28);
    if (Level24_89AECField(privateRecord20, short*, 0x12) > 0) {
        if (argumentWord5 < 0) {
            Level24_89AECField(ownerRecord19, unsigned char*, 0x45) =
                (unsigned char)(Level24_89AECField(ownerRecord19, unsigned char*, 0x45) +
                                (Level24_89AECData6C648View1 * 4));
        } else {
            Level24_89AECField(ownerRecord19, unsigned char*, 0x45) =
                (unsigned char)(Level24_89AECField(ownerRecord19, unsigned char*, 0x45) +
                                (Level24_89AECData6C648View1 * 3));
        }
        temporaryWord6 = (unsigned short)Level24_89AECField(privateRecord20, short*, 0x12) - 1;
        Level24_89AECField(privateRecord20, short*, 0x12) = temporaryWord6;
        temporaryWord11 = ownerRecord19 + 0x20;
        if ((temporaryWord6 << 0x10) == 0) {
            Level24_89AECField(privateRecord20, int*, 0) =
                (int)Level24_89AECField(ownerRecord19, unsigned char*, 0x44);
            Level24_89AECField(privateRecord20, int*, 4) =
                (int)Level24_89AECField(ownerRecord19, unsigned char*, 0x45);
            rawWord2 = Level24_89AECField(ownerRecord19, unsigned char*, 70);
            MATCHING_KEEP(rawWord2);
            Level24_89AECField(privateRecord20, unsigned short*, 42) = 0;
            Level24_89AECField(privateRecord20, int*, 8) = rawWord2;
        }
    } else {
        argumentWord6 = Level24_89AECField(privateRecord20, int*, 0);
        rawWord3 = (argumentWord6 & 255) * 2;
        rawWord2 = Level24_89AECField((int)&Level24_89AECData65920View1, unsigned short*, rawWord3);
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = Level24_89AECField(privateRecord20, int*, 8);
        MATCHING_KEEP_VOLATILE_CLOBBER(rawWord2, "memory");
        rawWord2 = (rawWord2 << 16) >> 23;
        rawWord2 += argumentWord4;
        Level24_89AECField(ownerRecord19, unsigned char*, 70) = rawWord2;
        rawWord2 = Level24_89AECField((int)&Level24_89AECData658A0View1, unsigned short*, rawWord3);
        __asm__ volatile("" ::: "$3", "memory");
        rawWord3 = Level24_89AECField(privateRecord20, int*, 4);
        MATCHING_KEEP_VOLATILE_CLOBBER(rawWord2, "memory");
        rawWord2 = (rawWord2 << 16) >> 23;
        rawWord2 += rawWord3;
        Level24_89AECField(ownerRecord19, unsigned char*, 69) = rawWord2;
        temporaryWord2 = argumentWord6;
        temporaryWord7 = Level24_89AECField(privateRecord20, unsigned short*, 0x2A) + 1;
        Level24_89AECField(privateRecord20, unsigned short*, 0x2A) = temporaryWord7;
        if ((short)temporaryWord7 >= 0x1D) {
            rawWord2 = Level24_89AECData6C648View1;
            productOrOriginalFrameFlag8 = argumentWord5 * rawWord2;
        } else {
            if ((short)temporaryWord7 >= 0xD) {
                temporaryWord12 = Level24_89AECData6C648View1 * 0x14;
            } else {
                temporaryWord12 = Level24_89AECData6C648View1 * 0xA;
            }
            productOrOriginalFrameFlag8 = argumentWord5 * temporaryWord12;
        }
        rawWord2 = temporaryWord2 + productOrOriginalFrameFlag8;
        rawWord2 &= 255;
        Level24_89AECField(privateRecord20, int*, 0) = rawWord2;
        temporaryWord11 = ownerRecord19 + 0x20;
    }
    originalFrame.sp58 = 0;
    originalFrame.sp5C = 0;
    originalFrame.sp60 = Level24_89AECData6C648View1 * 0x12C;
    Level24_89AECTransformVectorByBasisView1(temporaryWord11, &originalFrame.sp58,
                                             &originalFrame.sp58);
    argumentWord4 = (int)&originalFrame.sp68;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
    retainedLiteralPlayerSpawnOrIndex17 = (int)ownerRecord19 + 12;
    Level24_89AECCopyVectorView1(argumentWord4, retainedLiteralPlayerSpawnOrIndex17);
    Level24_89AECAddVectorView1(retainedLiteralPlayerSpawnOrIndex17,
                                retainedLiteralPlayerSpawnOrIndex17, &originalFrame.sp58);
    Level24_89AECAddVectorView1(&originalFrame.sp58, retainedLiteralPlayerSpawnOrIndex17,
                                &originalFrame.sp68);
    originalFrame.sp48 = 0;
    originalFrame.sp4C = 0;
    originalFrame.sp50 = 0;
    originalFrame.sp58 = (int)(originalFrame.sp58 << 9) >> 0xA;
    originalFrame.sp5C = (int)(originalFrame.sp5C << 9) >> 0xA;
    originalFrame.sp60 = (int)(originalFrame.sp60 << 9) >> 0xA;
    Level24_89AECDataSpawnParticleView1(1, 0xD, &originalFrame.sp58, &originalFrame.sp48);
    Level24_89AECSubtractVectorView1(&originalFrame.sp48, retainedLiteralPlayerSpawnOrIndex17,
                                     &originalFrame.sp68);
    Level24_89AECScaleVectorRatioQ15View1(
        &originalFrame.sp48, Level24_89AECMeasureVectorLengthView1(&originalFrame.sp48, 1), 0x400);
    Level24_89AECAddVectorView1(&originalFrame.sp48, &originalFrame.sp68, &originalFrame.sp48);
    temporaryWord8 = Level24_89AECQueryDynamicMobyGeometryView1(retainedLiteralPlayerSpawnOrIndex17,
                                                                0x400, 2, 0, 0, ownerRecord19);
    if ((temporaryWord8 != 0) && (Level24_89AECField(temporaryWord8, short*, 0x36) != 9)) {
        retainedStepFlagOrPosition21 = 1;
        Level24_89AECField(temporaryWord8, int*, 0x18) =
            (int)(Level24_89AECField(temporaryWord8, int*, 0x18) | 0x10010000);
    }
    if (((Level24_89AECField(privateRecord20, int*, 0x14) < 0x64) &&
         (Level24_89AECQueryWorldSegmentWithOptionsView1(&originalFrame.sp68, &originalFrame.sp48,
                                                         1, 0, 0) != 0)) ||
        (Level24_89AECCountTimerDownView1(privateRecord20 + 0x14, 4) != 0) ||
        (retainedStepFlagOrPosition21 != 0)) {
        retainedLiteralPlayerSpawnOrIndex17 = Level24_89AECDataSpawnMobyView1(100, ownerRecord19);
        if (retainedLiteralPlayerSpawnOrIndex17) {
            Level24_89AECField(retainedLiteralPlayerSpawnOrIndex17, signed char*, 72) = 0;
        }
        if (Level24_89AECAbsoluteByteAngleDeltaView1(
                (int)(Level24_89AECData6E040View1 << 0x10) >> 0x14,
                Level24_89AECPlanarHeadingLookupView1(
                    Level24_89AECField(ownerRecord19, int*, 0xC) -
                        Level24_89AECField((int)&Level24_89AECData6E020View1, int*, 0),
                    Level24_89AECField(ownerRecord19, int*, 0x10) - Level24_89AECData6E024View1,
                    0)) < 0xA) {
            Level24_89AECData6E1D8View1 = 0x14;
            Level24_89AECData6E1D4View1 = 0x1000;
            if (Level24_89AECApproximatePlanarDistanceView1(
                    ownerRecord19 + 0xC, (int)&Level24_89AECData70328View1) < 0x3000) {
                Level24_89AECData6C7C0View1 = 0xFF;
            }
        }
        retainedStateVectorOrParticleIndex18 = 0;
    emitOriginalBurst864:
        if ((Level24_89AECData6C578View1 - Level24_89AECData6C574View1) >= 0x15) {
            temporaryWord4 = Level24_89AECDataSpawnMobyView1(0x64, ownerRecord19);
            if (temporaryWord4 != 0) {
                retainedVectorRecordOrDistance16 = Level24_89AECField(temporaryWord4, void**, 0);
                Level24_89AECField(temporaryWord4, signed char*, 0x48) = 1;
                Level24_89AECField(temporaryWord4, signed char*, 0x41) = 0;
                Level24_89AECField(temporaryWord4, signed char*, 0x4C) = 0;
                Level24_89AECField(temporaryWord4, signed char*, 0x4D) = 0;
                originalFrame.sp78 = Level24_89AECRandBetweenView1(0, 0x50) - 0x28;
                originalFrame.sp7C = Level24_89AECRandBetweenView1(0, 0x50) - 0x28;
                originalFrame.sp80 = Level24_89AECRandBetweenView1(0x32, 0xC8);
                Level24_89AECField(temporaryWord4, int*, 0xC) =
                    (int)(Level24_89AECField(temporaryWord4, int*, 0xC) + (originalFrame.sp78 * 3));
                Level24_89AECField(temporaryWord4, int*, 0x10) =
                    (int)(Level24_89AECField(temporaryWord4, int*, 0x10) +
                          (originalFrame.sp7C * 3));
                Level24_89AECCopyVectorView1(retainedVectorRecordOrDistance16 + 4,
                                             &originalFrame.sp78);
                Level24_89AECField(retainedVectorRecordOrDistance16, int*, 0x10) = 0;
                Level24_89AECField(retainedVectorRecordOrDistance16, int*, 0) = 0xC8;
            }
            retainedStateVectorOrParticleIndex18 += 1;
            if (retainedStateVectorOrParticleIndex18 < 8) {
                goto emitOriginalBurst864;
            }
        }
        MATCHING_BARRIER_VOLATILE("$4");
        Level24_89AECPlayMobySoundEventView1(ownerRecord19, 1, 0);
    enterOriginalRemoval927:
        Level24_89AECRefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
        Level24_89AECMarkMobyCollectionBitView1(ownerRecord19);
        Level24_89AECEmitMobyVertexParticlesView1(ownerRecord19, 0x28);
        Level24_89AECDeleteMobyView1(ownerRecord19);
        return;
    }
    MATCHING_BARRIER_VOLATILE("$4");
    Level24_89AECRefreshMobySpatialGridAndBasisView1(ownerRecord19, 6);
    goto checkOriginalProximity1064;
originalState5:
    Level24_89AECRefreshMobySpatialGridAndBasisView1(ownerRecord19, 5);
    Level24_89AECInterpolateMobyVertexView1(ownerRecord19, 1, &originalFrame.sp78);
    originalFrame.sp88 = 0;
    originalFrame.sp8C = 0;
    originalFrame.sp90 = -0x64;
    Level24_89AECDataSpawnParticleView1(1, 0xD, &originalFrame.sp78, &originalFrame.sp88);
    if ((Level24_89AECField(ownerRecord19, unsigned char*, 0x3C) == 5) ||
        (Level24_89AECData6C770View1 != 0)) {
        rawWord2 = Level24_89AECDatarandView1();
        rawWord2 &= 1;
        if (rawWord2)
            rawWord2 = -1;
        else
            rawWord2 = 1;
        Level24_89AECField(privateRecord20, short*, 40) = rawWord2;
        __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, short*, 40))
                         : "$4", "memory");
        Level24_89AECField(privateRecord20, short*, 0x12) = 7;
        Level24_89AECField(privateRecord20, int*, 0x14) = 0x5A;
        Level24_89AECField(ownerRecord19, unsigned char*, 0x48) = 0x14U;
        Level24_89AECField(ownerRecord19, unsigned char*, 0x45) =
            (unsigned char)(Level24_89AECField(ownerRecord19, unsigned char*, 0x45) + 0x14);
        Level24_89AECTurnMobyTowardPlayerView1(ownerRecord19, 0x80, 0, 0);
    }
    goto checkOriginalProximity1064;
originalState97:
    var_fp = 1;
    retainedTwoOrVector22 = (int)&originalFrame.sp98;
    retainedStepFlagOrPosition21 = (int)ownerRecord19 + 12;
    retainedStateVectorOrParticleIndex18 = (int)&originalFrame.spA8;
    retainedPlayerPosition23 = (int)&Level24_89AECData6E020View1;
    rawWord2 = Level24_89AECField(privateRecord20, int*, 28);
    rawWord3 = rawWord2 * 88;
    rawWord2 = Level24_89AECData6C550View1;
    retainedVectorRecordOrDistance16 = rawWord2 + rawWord3;
checkOriginalTarget1007:
    Level24_89AECCopyVectorView1(retainedTwoOrVector22, retainedStepFlagOrPosition21);
    originalFrame.spA0 += 0x200;
    Level24_89AECCopyVectorView1(retainedStateVectorOrParticleIndex18,
                                 retainedVectorRecordOrDistance16 + 12);
    originalFrame.spB0 += 0x200;
    rawWord2 = Level24_89AECApproximatePlanarDistanceView1(retainedStepFlagOrPosition21,
                                                           retainedStateVectorOrParticleIndex18);
    rawWord3 = Level24_89AECField(privateRecord20, short*, 12);
    argumentWord4 = Level24_89AECField(privateRecord20, short*, 14);
    rawWord3 += argumentWord4;
    rawWord2 = rawWord2 < rawWord3;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(rawWord2, "$5");
    argumentWord5 = retainedStateVectorOrParticleIndex18;
    if (!rawWord2)
        goto originalNext24;
    if (Level24_89AECTestSubdividedSegmentPathView1(retainedTwoOrVector22, argumentWord5, 0) == 0)
        goto originalNext24;
    if ((Level24_89AECAbsoluteByteAngleDeltaView1(
             (int)(Level24_89AECField(retainedPlayerPosition23, unsigned short*, 32) << 0x10) >>
                 0x14,
             Level24_89AECPlanarHeadingLookupView1(
                 Level24_89AECField(ownerRecord19, int*, 0xC) -
                     Level24_89AECField(retainedPlayerPosition23, int*, 0),
                 Level24_89AECField(ownerRecord19, int*, 0x10) -
                     Level24_89AECField(retainedPlayerPosition23, int*, 4),
                 0)) >= 0x18))
        goto originalNext24;
    argumentWord5 = 3;
    if (Level24_89AECData6E344View1 != 1)
        goto originalSelect1126;
originalNext24:
    rawWord3 = Level24_89AECField(privateRecord20, int*, 32);
    if (rawWord3 == -1)
        goto checkOriginalProximity1064;
    retainedLiteralPlayerSpawnOrIndex17++;
    rawWord2 = rawWord3 * 88;
    rawWord3 = Level24_89AECData6C550View1;
    retainedVectorRecordOrDistance16 = rawWord3 + rawWord2;
    if (retainedLiteralPlayerSpawnOrIndex17 < 2)
        goto checkOriginalTarget1007;
    goto checkOriginalProximity1064;
checkOriginalProximity1064:
    if (!var_fp)
        goto originalEpilogue1144;
    argumentWord4 = (int)&originalFrame.sp88;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$17");
    retainedLiteralPlayerSpawnOrIndex17 = (int)ownerRecord19 + 12;
    Level24_89AECCopyVectorView1(argumentWord4, retainedLiteralPlayerSpawnOrIndex17);
    originalFrame.sp90 += 512;
    if (!Level24_89AECTestSubdividedSegmentPathView1(&originalFrame.sp88,
                                                     (int)&Level24_89AECData70328View1, 0))
        goto originalEpilogue1144;
    rawWord2 = Level24_89AECApproximatePlanarDistanceView1(retainedLiteralPlayerSpawnOrIndex17,
                                                           (int)&Level24_89AECData70328View1);
    argumentWord4 = Level24_89AECField(privateRecord20, short*, 12);
    rawWord3 = rawWord2;
    if (rawWord3 >= argumentWord4)
        goto originalOutside1132;
    productOrOriginalFrameFlag8 = originalFrame.spB8;
    if (!productOrOriginalFrameFlag8)
        goto originalEpilogue1144;
    rawWord2 = Level24_89AECPlanarHeadingLookupView1(
        Level24_89AECField(ownerRecord19, int*, 12) -
            Level24_89AECField((int)&Level24_89AECData6E020View1, int*, 0),
        Level24_89AECField(ownerRecord19, int*, 16) - Level24_89AECData6E024View1, 0);
    argumentWord4 = Level24_89AECData6E040View1;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = rawWord2;
    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(argumentWord5));
    argumentWord4 = (argumentWord4 << 16) >> 20;
    if (Level24_89AECAbsoluteByteAngleDeltaView1(argumentWord4, argumentWord5) >= 24)
        goto originalEpilogue1144;
    rawWord3 = Level24_89AECData6E344View1;
    if (rawWord3 == 1)
        goto originalEpilogue1144;
    argumentWord4 = (int)ownerRecord19;
    argumentWord5 = 3;
    rawWord2 = 3;
    Level24_89AECField(privateRecord20, short*, 24) = 0;
    __asm__ volatile("" ::"m"(Level24_89AECField(privateRecord20, short*, 24)), "r"(argumentWord4),
                     "r"(argumentWord5), "r"(rawWord2), "i"(0x8008AC78)
                     : "memory");
    Level24_89AECField(argumentWord4, unsigned char*, 72) = rawWord2;
    goto callOriginalStateHelper1142;
originalSelect1126:
    argumentWord4 = (int)ownerRecord19;
    rawWord2 = retainedLiteralPlayerSpawnOrIndex17 + 1;
    Level24_89AECField(privateRecord20, short*, 24) = rawWord2;
    rawWord2 = 3;
    Level24_89AECField(argumentWord4, unsigned char*, 72) = rawWord2;
    goto callOriginalStateHelper1142;
originalOutside1132:
    rawWord2 = Level24_89AECField(privateRecord20, short*, 14);
    if (rawWord2 <= 0)
        goto originalEpilogue1144;
    rawWord2 += argumentWord4;
    if (rawWord3 >= rawWord2)
        goto originalEpilogue1144;
    rawWord2 = 2;
writeOriginalState1139:
    Level24_89AECField(ownerRecord19, unsigned char*, 72) = rawWord2;
    argumentWord4 = (int)ownerRecord19;
    argumentWord5 = 2;
callOriginalStateHelper1142:
    Level24_89AECRequestMobyAnimationView1(argumentWord4, argumentWord5);
originalEpilogue1144:
    return;
}
#undef Level24_89AECField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_24/moby/func_level_24_8008AD00.s SHA256 ff2f8e5308d68f9c2cd59176a0bc7f8d2607f6e516dafbe0c66d9d11a3b47fd0. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Bulk5233_9QueryWorldSegmentWithOptions() __asm__("func_8001830C");   /* extern */
void* Bulk5233_9QueryDynamicMobyGeometry() __asm__("func_8001BA30");     /* extern */
int Bulk5233_9TestPlayerSphereOverlap() __asm__("func_8001C288");        /* extern */
int Bulk5233_9TransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Bulk5233_9SubtractVector() __asm__("func_8004F1C8");                 /* extern */
int Bulk5233_9DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Bulk5233_9RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
extern unsigned char Bulk5233_9_D_800658A0 __asm__("D_800658A0");
extern unsigned char Bulk5233_9_D_80065920 __asm__("D_80065920");
extern int Bulk5233_9_D_8006C550 __asm__("D_8006C550");
extern int Bulk5233_9_D_8006C574 __asm__("D_8006C574");
extern int Bulk5233_9_D_8006C578 __asm__("D_8006C578");
extern int Bulk5233_9_D_8006C648 __asm__("D_8006C648");
extern int Bulk5233_9_D_8006E020 __asm__("D_8006E020");
extern int Bulk5233_9_D_8006E024 __asm__("D_8006E024");
extern unsigned short Bulk5233_9_D_8006E040 __asm__("D_8006E040");
extern int Bulk5233_9_D_8006E044 __asm__("D_8006E044");
extern int Bulk5233_9_D_8006E1D4 __asm__("D_8006E1D4");
extern int Bulk5233_9_D_8006E1D8 __asm__("D_8006E1D8");
extern unsigned char Bulk5233_9_D_80070328 __asm__("D_80070328");

void func_level_24_8008AD00(Moby* moby) {
    register int* outgoing __asm__("$29");
    struct {
        Vector3D sp18;
        int pad24;
        Vector3D sp28;
        int pad34;
        Vector3D sp38;
        int pad44;
        Vector3D sp48;
        int pad54;
    } originalStack;

    register Moby* arg0 __asm__("$19") = moby;

    register Moby* temp_v0_2 __asm__("$17");
    register Vector3D* temp_s0 __asm__("$16");
    register Vector3D* temp_s0_2 __asm__("$16");
    register int temp_v1 __asm__("$3");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int call4 __asm__("$4");
    register int call5 __asm__("$5");
    register Vector3D* stackVector17 __asm__("$17");
    register int var_s4 __asm__("$20");
    register int var_s4_2 __asm__("$20");
    register int var_s5 __asm__("$21");
    register int var_v0 __asm__("$2");
    register void* temp_s0_3 __asm__("$16");
    register void* temp_s2 __asm__("$18");
    void* temp_v0;

    MATCHING_KEEP(arg0);
    var_s5 = 0;
    temp_s2 = arg0->mobyTag;
    value3 = M2C_FIELD(arg0, unsigned short*, 0x1A);
    var_s4 = value3 & 1;
    if ((unsigned int)(M2C_FIELD(temp_s2, unsigned char*, 3) - 1) < 2U) {
        value2 = M2C_FIELD(temp_s2, unsigned char*, 0) * 2;
        value2 = M2C_FIELD(&Bulk5233_9_D_80065920, unsigned short*, value2);
        value3 = M2C_FIELD(temp_s2, unsigned char*, 2);
        value2 <<= 16;
        value2 >>= 23;
        value2 += value3;
        arg0->angle.yaw = value2;
        value2 = M2C_FIELD(temp_s2, unsigned char*, 0) * 2;
        value2 = M2C_FIELD(&Bulk5233_9_D_800658A0, unsigned short*, value2);
        value3 = M2C_FIELD(temp_s2, unsigned char*, 1);
        value2 <<= 16;
        value2 >>= 23;
        value2 += value3;
        arg0->angle.pitch = value2;
        temp_v1 = M2C_FIELD(temp_s2, int*, 8);
        if (temp_v1 >= 0x95) {
            M2C_FIELD(temp_s2, unsigned char*, 0) = (unsigned char)arg0->angle.roll;
            arg0->angle.pitch = M2C_FIELD(temp_s2, unsigned char*, 1);
            arg0->angle.yaw = M2C_FIELD(temp_s2, unsigned char*, 2);
        } else {
            if (temp_v1 >= 0x75) {
                value2 = Bulk5233_9_D_8006C648;
                value3 = M2C_FIELD(temp_s2, unsigned char*, 0);
                value2 <<= 4;
            } else if (temp_v1 >= 0x55) {
                value2 = Bulk5233_9_D_8006C648;
                value3 = M2C_FIELD(temp_s2, unsigned char*, 0);
                value2 <<= 3;
            } else {
                MATCHING_KEEP(temp_v1);
                value2 = temp_v1 < 0x15;
                if (!value2) {
                    value2 = Bulk5233_9_D_8006C648;
                    value3 = M2C_FIELD(temp_s2, unsigned char*, 0);
                    value2 <<= 2;
                } else {
                    value2 = Bulk5233_9_D_8006C648;
                    value3 = M2C_FIELD(temp_s2, unsigned char*, 0);
                    value2 <<= 1;
                }
            }
            value3 += value2;
            M2C_FIELD(temp_s2, unsigned char*, 0) = value3;
        }
    }
    Bulk5233_9RefreshMobySpatialGridAndBasis(arg0, 4);
    stackVector17 = &originalStack.sp28;
    call4 = (int)stackVector17;
    MATCHING_KEEP2(call4, stackVector17);
    temp_s0 = &arg0->position;
    originalStack.sp18.x = 0x12C;
    originalStack.sp18.y = 0;
    originalStack.sp18.z = 0;
    func_8004F178((Vector3D*)call4, temp_s0);
    call5 = (int)&originalStack.sp18;
    Bulk5233_9TransformVectorByBasis(&arg0->rotationMatrix, call5, call5);
    __asm__("" : "=r"(call5));
    func_8004F194(temp_s0, temp_s0, (Vector3D*)&originalStack.sp18);
    call4 = (int)&originalStack.sp38;
    if (M2C_FIELD(temp_s2, unsigned char*, 3) == 0) {
        Bulk5233_9SubtractVector(call4, &Bulk5233_9_D_80070328, stackVector17);
        value3 = originalStack.sp38.x;
        value2 = originalStack.sp18.x;
        call4 = value3 * value2;
        value3 = originalStack.sp38.y;
        value2 = originalStack.sp18.y;
        value3 = value3 * value2;
        value2 = call4 + value3;
        if (value2 < 0) {
            M2C_FIELD(temp_s2, unsigned char*, 3) = 1U;
            M2C_FIELD(temp_s2, int*, 8) = 0x94;
        }
    }
    /* Original 8008AEF4 stores the fifth raw ABI argument, zero, at
     * SP+0x10. The original frame is SP-0x78. Capturing that proven SP
     * emits no instruction; staging the fifth argument here preserves
     * the original ordering before A0=SP+0x28 and S0=owner+0x0C.
     * The following C call supplies four register arguments; the fifth
     * argument is supplied by this explicit outgoing-stack store. */
    __asm__("" : "=r"(outgoing) : : "$4");
    outgoing[4] = 0;
    call4 = (int)&originalStack.sp28;
    MATCHING_KEEP_CLOBBER(call4, "memory");
    temp_s0_2 = &arg0->position;
    if (Bulk5233_9QueryWorldSegmentWithOptions(call4, temp_s0_2, 3, 0) != 0) {
        var_s4 = 1;
        var_s5 = 2;
    }
    originalStack.sp18.x = 0;
    originalStack.sp18.y = 0;
    originalStack.sp18.z = 0;
    SpawnParticle(1, 0xD, temp_s0_2, (Vector3D*)&originalStack.sp18);
    if ((M2C_FIELD(temp_s2, unsigned char*, 3) == 0) && (Bulk5233_9_D_8006E044 != 9)) {
        if (Bulk5233_9_D_8006E044 != 0xB) {
            if (M2C_FIELD(&Bulk5233_9_D_80070328, int*, 0x240) == 0) {
                if (Bulk5233_9TestPlayerSphereOverlap(temp_s0_2, 0x100, 7) != 0) {
                    M2C_FIELD(&Bulk5233_9_D_80070328, int*, 0x298) = (int)arg0->angle.yaw;
                    var_s5 = 2;
                } else {
                    goto block_22;
                }
            } else {
                goto block_24;
            }
        } else {
            goto block_23;
        }
    } else {
    block_22:
    block_23:
    block_24:
        temp_v0 = Bulk5233_9QueryDynamicMobyGeometry(
            &arg0->position, 0xC8, 2, 0, 0, Bulk5233_9_D_8006C550 + (arg0->linkedMoby * 0x58));
        if ((temp_v0 != 0) && (M2C_FIELD(temp_v0, short*, 0x36) != 9)) {
            var_s5 = 2;
            var_s4 = 1;
            M2C_FIELD(temp_v0, int*, 0x18) = (int)(M2C_FIELD(temp_v0, int*, 0x18) | 0x10030000);
        }
    }
    if (var_s4 != 0) {
        if (func_8004F264((int)(Bulk5233_9_D_8006E040 << 0x10) >> 0x14,
                          func_8004E880(arg0->position.x - Bulk5233_9_D_8006E020,
                                        arg0->position.y - Bulk5233_9_D_8006E024, 0)) < 0xA) {
            Bulk5233_9_D_8006E1D8 = 0x14;
            Bulk5233_9_D_8006E1D4 = 0x1000;
        }
        var_s4_2 = 0;
    loop_31:
        if ((Bulk5233_9_D_8006C578 - Bulk5233_9_D_8006C574) >= 0x15) {
            temp_v0_2 = SpawnMoby(0x64, arg0);
            MATCHING_KEEP(temp_v0_2);
            if (temp_v0_2 != 0) {
                temp_s0_3 = temp_v0_2->mobyTag;
                temp_v0_2->state = 1;
                temp_v0_2->unknown3[0] = 0;
                temp_v0_2->lowDrawDistance = 0;
                temp_v0_2->drawn = 0;
                originalStack.sp48.x = func_8003636C(0, 0x50) - 0x28;
                originalStack.sp48.y = func_8003636C(0, 0x50) - 0x28;
                originalStack.sp48.z = func_8003636C(0x32, 0xC8);
                temp_v0_2->position.x += originalStack.sp48.x * 3;
                temp_v0_2->position.y += originalStack.sp48.y * 3;
                func_8004F178(temp_s0_3 + 4, (Vector3D*)&originalStack.sp48);
                M2C_FIELD(temp_s0_3, int*, 0x10) = 0;
                M2C_FIELD(temp_s0_3, int*, 0) = 0xC8;
            }
            var_s4_2 += 1;
            if (var_s4_2 < 8) {
                goto loop_31;
            }
        }
    }
    if ((var_s5 != 0) || (func_800359A4(temp_s2 + 8, 4) != 0)) {
        if (func_8003BFC0(arg0, (int)M2C_FIELD(temp_s2, unsigned char*, 4)) != 0) {
            func_8003BE70((int)M2C_FIELD(temp_s2, unsigned char*, 4));
        }
        func_8003BABC(arg0, 1, 0);
        func_800369B8(arg0, 0x14);
        Bulk5233_9DeleteMoby(arg0);
        return;
    }
    if (func_8003BFC0(arg0, (int)M2C_FIELD(temp_s2, unsigned char*, 4)) == 0) {
        __asm__("" : "=r"(var_s5));
        M2C_FIELD(temp_s2, unsigned char*, 4) = func_8003BABC(arg0, 0, 4);
    }
}
#undef M2C_FIELD

extern int D_8006C578, D_8006C574;
void func_level_24_8008B220(Moby* moby) {
    Vector3D offset;
    Moby* spawned;
    int index, heading;
    if (moby->damageFlags) {
        heading = moby->angle.yaw;
        func_80055D24(moby, 4);
        moby->angle.yaw = *((unsigned char*)&spyro + 0xE);
        index = 0;
    spawnNext:
        if (D_8006C578 - D_8006C574 < 21)
            goto finished;
        spawned = SpawnMoby(10, moby);
        if (spawned) {
            spawned->size = 0x18;
            spawned->lowDrawDistance = 0x3F;
            spawned->updateDistance = 0xFF;
            spawned->animationState.id = index;
            spawned->angle.yaw = heading;
            switch (index) {
                case 0:
                    offset.x = 0xD3;
                    offset.y = 25;
                    offset.z = 0x81;
                    break;
                case 1:
                    offset.x = 0;
                    offset.y = -70;
                    offset.z = 0x2FA;
                    break;
                case 2:
                    offset.x = 5;
                    offset.y = -164;
                    offset.z = 0x214;
                    break;
            }
            func_8004ED6C(&moby->rotationMatrix, &offset, &offset);
            func_8004F194(&spawned->position, &spawned->position, &offset);
        }
        index++;
        if (index < 3)
            goto spawnNext;
    finished:
        func_80055B18(moby);
    }
}

typedef struct {
    short x, y, z;
    unsigned char roll, reserved07, pitch, reserved09, yaw, reserved0B;
    short timer;
} DecodedFallingMotionTag;
void func_level_24_8008B394(Moby* moby) {
    DecodedFallingMotionTag* tag = moby->mobyTag;
    if (func_800359A4(&tag->timer, 2))
        func_80055B18(moby);
    else {
        moby->position.x += tag->x;
        moby->position.y += tag->y;
        tag->z -= 10;
        if (tag->z < -200)
            tag->z = -200;
        moby->position.z += tag->z;
        moby->angle.roll += tag->roll;
        moby->angle.pitch += tag->pitch;
        moby->angle.yaw += tag->yaw;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_24/moby/func_level_24_8008B488.s SHA256 50e784e26e8a8bd503595f6c2f308529f03c7a17abe13dcf1d107b13e72998ff. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level24_8B488Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Spyro Level24_8B488_D_80070328 __asm__("D_80070328");
void Level24_8B488RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level24_8B488UpdateMobyMotionDescriptor(Moby*, void*) __asm__("func_80035194");
int Level24_8B488TurnMobyTowardPlayer(Moby* ownerRecord, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level24_8B488TurnMobyTowardHeading(Moby*, int, int, int, int, int) __asm__("func_8003585C");
int Level24_8B488CountTimerDown(void*, int) __asm__("func_800359A4");
int Level24_8B488ResolveMobyYawStep(Moby* ownerRecord, int arg1, int arg2, int arg3,
                                    int arg4) __asm__("func_80035DDC");
void Level24_8B488EmitMobyVertexParticles() __asm__("func_800369B8");
void Level24_8B488InitializeMobyMotionStateWithDeceleration(Moby*, void*, unsigned int,
                                                            int) __asm__("func_80038F14");
void Level24_8B488MarkMobyCollectionBit(Moby* moby) __asm__("func_8003BA00");
extern int Level24_8B488PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level24_8B488ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level24_8B488CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level24_8B488AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level24_8B488AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level24_8B488ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level24_8B488DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level24_8B488RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level24_8B488ReadSelectedFrameScalar(Moby*) __asm__("func_80055E84");
extern int Level24_8B488_rand() __asm__("rand");

int Level24_8B488UpdateMobyPathMotion() __asm__("func_80035A80");
/* extern */
unsigned char Level24_8B488SpawnMobyFromValueSelector() __asm__("func_80036A68");
/* extern */
extern int Level24_8B488_D_8006580C __asm__("D_8006580C");
extern int Level24_8B488_D_80065834 __asm__("D_80065834");
extern int Level24_8B488_D_8006C54C __asm__("D_8006C54C");
extern int Level24_8B488_D_8006C770 __asm__("D_8006C770");
extern int Level24_8B488_D_8006C774 __asm__("D_8006C774");
extern int Level24_8B488_D_8006E020 __asm__("D_8006E020");
extern int Level24_8B488_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level24_8B488_D_8006E040 __asm__("D_8006E040");
extern int Level24_8B488_D_8006E344 __asm__("D_8006E344");
extern signed char Level24_8B488_D_80071598 __asm__("D_80071598");
extern unsigned char Level24_8B488_D_level_24_80096B68 __asm__("D_level_24_80096B68");

void func_level_24_8008B488(Moby* ownerRecord) {
    /* SCUS-94467, 8008B488: original 0x88-byte frame. Scratch vectors at
     * SP+0x20/+0x30/+0x40/+0x50/+0x60;
      saved16..20 atSP+0x70..0x80,
     * RA atSP+0x84. Fields and vector adjustments are byte offsets.
     * Raw register identities preserve separate original state writers,
     * shared state91 at569, condition818, random reset820 and callback831.
     * Signed limitLH at519 follows the distance call517. State5 is written
     * through owner19 before caller4 is copied, as instructions397/398.
     * Empty constraints contain no CPU instructions;
      inputs are initialized.
     * Physical units/fixed point, helper semantics and caller cadence remain
     * unresolved. Cadence is one invocation;
      no synchronized runtime claim.
     * Falsification: all842 instructions and94 owned selector words, every
     * native/linked transfer target and complete EXE/every-overlay hashes. */
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
    } originalFrame;

    Vector3D* positionVector17;
    Vector3D* privateVector20;
    short temp_a0;
    int distanceWord4;
    int offsetWord16;
    int helperResult16;
    int heightDifference18;
    register unsigned int rangeWord2 __asm__("2");
    register int randomResult2 __asm__("2");
    int temp_v0_2;
    int temp_v0_3;
    register int heightWord2 __asm__("2");
    int temp_v1;
    register int privateHeight3 __asm__("3");
    register int callbackParameter5 __asm__("5");
    register Moby* sharedCaller4 __asm__("4");
    register int heightDifference2 __asm__("2");
    register int heightWord3 __asm__("3");
    register int sharedCondition2 __asm__("2");
    int var_v0_5;
    register unsigned int stateByte4 __asm__("4");
    unsigned char temp_v1_2;
    register unsigned int substateWord2 __asm__("2");
    register unsigned int nextSubstateWord2 __asm__("2");
    void* temp_v0;
    void* temp_v0_5;

    privateVector20 = ownerRecord->mobyTag;
    if (((unsigned int)(ownerRecord->state - 7) >= 3U) &&
        (((temp_a0 = ownerRecord->mobyClass, (temp_a0 == 0x11)) &&
          (ownerRecord->damageFlags & 0x0C090000)) ||
         ((temp_a0 == 4) && (ownerRecord->damageFlags & 0x04000000)))) {
        Level24_8B488SpawnMobyFromValueSelector(ownerRecord, 1, 0, 0);
        Level24_8B488InitializeMobyMotionStateWithDeceleration(
            ownerRecord, ((void*)((unsigned char*)((unsigned char*)privateVector20 + 0x1C))), 1U,
            7);
        Level24_8B488RefreshMobySpatialGridAndBasis(ownerRecord, 5);
    }
    if (ownerRecord->substate == 0) {
        /* GCC merges these observer arms only on the same source line. */
        // clang-format off
        if (Level24_8B488_rand() & 3) { substateWord2 = 1; MATCHING_KEEP(substateWord2); } else { substateWord2 = 4; MATCHING_KEEP(substateWord2); }
        // clang-format on
        ownerRecord->substate = substateWord2;
        MATCHING_BARRIER_VOLATILE("memory");
        stateByte4 = ownerRecord->state;
        MATCHING_KEEP(stateByte4);
        temp_v1 = stateByte4 & 0xFF;
        if (temp_v1 != 0) {
            if (temp_v1 == 0x5C) {
                ownerRecord->position.z += 0x2000;
            } else if (((rangeWord2 = stateByte4 - 0x50), (rangeWord2 < 2U))) {
                Level24_8B488RequestMobyAnimation(ownerRecord, 0);
                Level24_8B488Field(privateVector20, int*, 0xC) = 1;
            }
            goto block_14;
        }
        goto block_113;
    }
block_14:
    if (((Level24_8B488_D_8006C54C - 1) == &Level24_8B488_D_level_24_80096B68) &&
        (Level24_8B488_D_8006C774 != 0)) {
        Level24_8B488_D_8006580C = 2;
        Level24_8B488_D_80065834 = 2;
        Level24_8B488_D_80071598 = 0;
    }
    temp_v1_2 = ownerRecord->state;
    switch (temp_v1_2) {
        case 0x0:
            temp_v0 = Level24_8B488Field(privateVector20, void**, 0x18);
            if ((temp_v0 != 0) && (Level24_8B488Field(temp_v0, short*, 0xA) == 1)) {
                Level24_8B488RequestMobyAnimation(ownerRecord, 6);
                goto block_76;
            }
            heightDifference2 = Level24_8B488_D_80070328.position.z;
            heightWord3 = ownerRecord->position.z;
            heightDifference2 -= heightWord3;
            if (heightDifference2 < 0) {
                heightDifference2 = -heightDifference2;
            }
            if ((heightDifference2 < 0x1000) &&
                (Level24_8B488ApproximatePlanarDistance(
                     &ownerRecord->position,
                     (Vector3D*)(((unsigned char*)&Level24_8B488_D_80070328.position.z - 8))) <
                 Level24_8B488Field(privateVector20, short*, 0x10))) {
                ownerRecord->state = 1;
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 1;
                goto block_115;
            } else {
                if ((ownerRecord->substate == 3) &&
                    (Level24_8B488TurnMobyTowardPlayer(ownerRecord, 8, 4, 0) != 0)) {
                    ownerRecord->substate = 1;
                    Level24_8B488Field(privateVector20, int*, 0xC) =
                        (int)(((Level24_8B488_rand() & 3) * 0x3C) + 0x78);
                    return;
                }
                default:
                    return;
            }
            break;
        case 0x1:
            Level24_8B488TurnMobyTowardPlayer(ownerRecord, 8, 0, 0);
            Level24_8B488CopyVector(&originalFrame.sp20, &Level24_8B488_D_80070328.unk7a[3]);
            originalFrame.sp20.x = (int)originalFrame.sp20.x * 0xF;
            originalFrame.sp20.y *= 0xF;
            originalFrame.sp20.z *= 0xF;
            Level24_8B488ShiftVectorRightTowardZero(&originalFrame.sp20, 6);
            Level24_8B488AddVector(
                &originalFrame.sp20, &originalFrame.sp20,
                (Vector3D*)((unsigned char*)&Level24_8B488_D_80070328.unk7a[3] - 0x98));
            distanceWord4 =
                Level24_8B488ApproximatePlanarDistance(&ownerRecord->position, &originalFrame.sp20);
            if ((Level24_8B488Field(privateVector20, short*, 0x16) == 2) &&
                (distanceWord4 < Level24_8B488Field(privateVector20, short*, 0x12)) &&
                (Level24_8B488AbsoluteByteAngleDelta(
                     (int)(Level24_8B488_D_8006E040 << 0x10) >> 0x14,
                     Level24_8B488PlanarHeadingLookup(
                         ownerRecord->position.x - Level24_8B488_D_8006E020,
                         ownerRecord->position.y - Level24_8B488_D_8006E024, 0)) < 0x18) &&
                (Level24_8B488_D_8006E344 != 1)) {
                ownerRecord->state = 4;
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 4;
                goto block_115;
            }
            if (Level24_8B488_D_8006C770 != 0) {
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP(sharedCaller4);
                callbackParameter5 = 2;
                Level24_8B488Field(privateVector20, int*, 0xC) = 0xB4;
                sharedCaller4->state = 2;
                goto block_115;
            }
            break;
        case 0x2:
            offsetWord16 = (ownerRecord->substate == 4) << 0xB;
            Level24_8B488TurnMobyTowardPlayer(ownerRecord, 8, 0, 0);
            Level24_8B488CopyVector(&originalFrame.sp30, &Level24_8B488_D_80070328.unk7a[3]);
            originalFrame.sp30.x = (int)originalFrame.sp30.x * 0xF;
            originalFrame.sp30.y *= 0xF;
            originalFrame.sp30.z *= 0xF;
            Level24_8B488ShiftVectorRightTowardZero(&originalFrame.sp30, 6);
            Level24_8B488AddVector(
                &originalFrame.sp30, &originalFrame.sp30,
                (Vector3D*)((unsigned char*)&Level24_8B488_D_80070328.unk7a[3] - 0x98));
            temp_v0_2 =
                Level24_8B488ApproximatePlanarDistance(&ownerRecord->position, &originalFrame.sp30);
            if ((temp_v0_2 < (Level24_8B488Field(privateVector20, short*, 0x12) + offsetWord16)) &&
                (Level24_8B488AbsoluteByteAngleDelta(
                     (int)(Level24_8B488_D_8006E040 << 0x10) >> 0x14,
                     Level24_8B488PlanarHeadingLookup(
                         ownerRecord->position.x - Level24_8B488_D_8006E020,
                         ownerRecord->position.y - Level24_8B488_D_8006E024, 0)) < 0x18) &&
                (Level24_8B488_D_8006E344 != 1)) {
                ownerRecord->state = 4;
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 4;
                goto block_115;
            }
            if (Level24_8B488Field(privateVector20, short*, 0x10) < temp_v0_2) {
                ownerRecord->state = 3;
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 3;
                goto block_115;
            }
            break;
        case 0x3:
            sharedCondition2 = Level24_8B488_D_8006C770;
            __asm__ volatile("" : "=r"(sharedCondition2) : "0"(sharedCondition2), "r"(ownerRecord));
            goto block_112;
            break;
        case 0x4:
            helperResult16 = Level24_8B488ReadSelectedFrameScalar(ownerRecord);
            Level24_8B488TurnMobyTowardPlayer(ownerRecord, 4, 2, 0);
            heightDifference18 = (ownerRecord->position.z - ownerRecord->distanceToGround) -
                                 Level24_8B488_D_80070328.position.z;
            if ((ownerRecord->substate != 2) && (ownerRecord->animationState.id == 4) &&
                ((unsigned int)(helperResult16 - 9) < 4U) &&
                (Level24_8B488_D_80070328.unk20[2] == 0) &&
                (Level24_8B488AbsoluteByteAngleDelta(
                     (int)ownerRecord->angle.yaw,
                     Level24_8B488PlanarHeadingLookup(
                         Level24_8B488_D_80070328.position.x - ownerRecord->position.x,
                         Level24_8B488_D_80070328.position.y - ownerRecord->position.y, 0)) < 8) &&
                (Level24_8B488ApproximatePlanarDistance(
                     &ownerRecord->position,
                     (Vector3D*)(((unsigned char*)&Level24_8B488_D_80070328.position.z - 8))) <
                 Level24_8B488Field(privateVector20, short*, 0x12)) &&
                ((unsigned int)(heightDifference18 + 0x3FF) < 0x47FU)) {
                Level24_8B488_D_80070328.unk22[5] = (ownerRecord->angle.yaw + 0x30) & 0xFF;
                Level24_8B488_D_80070328.damageFlags |= 7;
                ownerRecord->substate = 2;
            }
            if (Level24_8B488_D_8006C770 != 0) {
                /* GCC merges these observer arms only on the same source line. */
                // clang-format off
                if (Level24_8B488_rand() & 3) { nextSubstateWord2 = 1; MATCHING_KEEP(nextSubstateWord2); } else { nextSubstateWord2 = 4; MATCHING_KEEP(nextSubstateWord2); }
                // clang-format on
                ownerRecord->substate = nextSubstateWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                {
                    register unsigned int five2 __asm__("2");
                    five2 = 5;
                    __asm__("" : "=r"(five2) : "0"(five2), "r"(ownerRecord) : "4");
                    ownerRecord->state = five2;
                    __asm__ volatile("" : : : "4", "memory");
                }
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 5;
                goto block_115;
            }
            Level24_8B488RefreshMobySpatialGridAndBasis(ownerRecord, 5);
            return;
        case 0x5:
            sharedCondition2 = Level24_8B488_D_8006C770;
            goto block_112;
        case 0x6:
            Level24_8B488CopyVector(&originalFrame.sp40, &Level24_8B488_D_80070328.unk7a[3]);
            originalFrame.sp40.x = (int)originalFrame.sp40.x * 0xF;
            originalFrame.sp40.y *= 0xF;
            originalFrame.sp40.z *= 0xF;
            Level24_8B488ShiftVectorRightTowardZero(&originalFrame.sp40, 6);
            Level24_8B488AddVector(
                &originalFrame.sp40, &originalFrame.sp40,
                (Vector3D*)((unsigned char*)&Level24_8B488_D_80070328.unk7a[3] - 0x98));
            positionVector17 = &ownerRecord->position;
            temp_v0_3 =
                Level24_8B488ApproximatePlanarDistance(positionVector17, &originalFrame.sp40);
            if (temp_v0_3 < Level24_8B488Field(privateVector20, short*, 0x12)) {
                ownerRecord->substate = 1;
                if (Level24_8B488Field(privateVector20, short*, 0x16) == 2) {
                    if ((Level24_8B488AbsoluteByteAngleDelta(
                             (int)(Level24_8B488_D_8006E040 << 0x10) >> 0x14,
                             Level24_8B488PlanarHeadingLookup(
                                 ownerRecord->position.x - Level24_8B488_D_8006E020,
                                 ownerRecord->position.y - Level24_8B488_D_8006E024, 0)) < 0x18) &&
                        (Level24_8B488_D_8006E344 != 1)) {
                        ownerRecord->state = 4;
                        sharedCaller4 = ownerRecord;
                        MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                        callbackParameter5 = 4;
                        goto block_115;
                    } else {
                        goto block_64;
                    }
                } else {
                block_64:
                    ownerRecord->state = 1;
                    sharedCaller4 = ownerRecord;
                    MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                    callbackParameter5 = 1;
                    goto block_115;
                }
            }
            if (ownerRecord->substate == 2) {
                Level24_8B488TurnMobyTowardHeading(
                    ownerRecord,
                    Level24_8B488PlanarHeadingLookup(privateVector20->x - ownerRecord->position.x,
                                                     privateVector20->y - ownerRecord->position.y,
                                                     0),
                    8, 0x18, 0, 0);
                if (Level24_8B488ApproximatePlanarDistance(positionVector17, privateVector20) <
                    0x100) {
                    sharedCaller4 = ownerRecord;
                    MATCHING_KEEP(sharedCaller4);
                    callbackParameter5 = 0;
                    sharedCaller4->substate = 3;
                    Level24_8B488Field(privateVector20, int*, 0xC) = 0x10;
                    goto resetStore;
                }
                goto block_72;
            }
            if ((Level24_8B488Field(privateVector20, short*, 0x10) < temp_v0_3) || ({
                    register int returned2 __asm__("2");
                    register int limit3 __asm__("3");
                    returned2 =
                        Level24_8B488ApproximatePlanarDistance(positionVector17, privateVector20);
                    MATCHING_BARRIER_VOLATILE("memory");
                    limit3 = Level24_8B488Field(privateVector20, short*, 0x14);
                    limit3 = limit3 < returned2;
                    limit3;
                })) {
                ownerRecord->substate = 2;
            }
            Level24_8B488TurnMobyTowardPlayer(ownerRecord, 8, 0, 0);
        block_72:
            Level24_8B488ResolveMobyYawStep(ownerRecord, 0x64, 0, 0, 4);
            return;
        case 0x7:
            Level24_8B488RefreshMobySpatialGridAndBasis(ownerRecord, 5);
            if (Level24_8B488UpdateMobyMotionDescriptor(
                    ownerRecord,
                    ((void*)((unsigned char*)((unsigned char*)privateVector20 + 0x1C)))) == 0x100) {
                Level24_8B488RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level24_8B488MarkMobyCollectionBit(ownerRecord);
                Level24_8B488EmitMobyVertexParticles(ownerRecord, 0x40);
                Level24_8B488DeleteMoby(ownerRecord);
                return;
            }
            break;
        case 0x5A:
            Level24_8B488RequestMobyAnimation(ownerRecord, 6);
            Level24_8B488Field(Level24_8B488Field(privateVector20, void**, 0x18), short*, 0xA) = 1;
            Level24_8B488Field(Level24_8B488Field(privateVector20, void**, 0x18), short*, 2) = 1;
        block_76:
            ownerRecord->state = 0x5B;
            return;

        case 0x5B:
            Level24_8B488UpdateMobyPathMotion(ownerRecord,
                                              Level24_8B488Field(privateVector20, void**, 0x18),
                                              0x78, 0x64, 0, 4, 0x20, 4);
            if (Level24_8B488ApproximatePlanarDistance(&ownerRecord->position,
                                                       &Level24_8B488_D_80070328.position) <
                Level24_8B488Field(privateVector20, short*, 0x10)) {
                if (Level24_8B488Field(privateVector20, short*, 0x16) != 0) {
                    if (Level24_8B488_rand() & 1) {
                        ownerRecord->state = 6;
                        sharedCaller4 = ownerRecord;
                        MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                        callbackParameter5 = 6;
                        goto block_115;
                    } else {
                        goto block_82;
                    }
                } else {
                block_82:
                    ownerRecord->state = 1;
                    sharedCaller4 = ownerRecord;
                    MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                    callbackParameter5 = 1;
                    goto block_115;
                }
            }
            break;
        case 0x5C:
            Level24_8B488CopyVector(
                &originalFrame.sp50,
                Level24_8B488Field(Level24_8B488Field(privateVector20, void**, 0x18), Vector3D**,
                                   0xC));
            if (Level24_8B488ApproximatePlanarDistance(
                    &originalFrame.sp50, &Level24_8B488_D_80070328.position) < 0xC00) {
                ownerRecord->unknown3[0] = 1;
                ownerRecord->lowDrawDistance = 0x30;
                ownerRecord->drawn = 1;
                Level24_8B488RequestMobyAnimation(ownerRecord, 0xA);
                ownerRecord->state = 0x5D;
                return;
            }
            ownerRecord->unknown3[0] = 0;
            ownerRecord->lowDrawDistance = 0;
            ownerRecord->drawn = 0;
            return;
        case 0x5D:
            heightWord2 = ownerRecord->position.z - 0x96;
            ownerRecord->position.z = heightWord2;
            privateHeight3 = privateVector20->z;
            var_v0_5 = heightWord2 - privateHeight3;
            if (var_v0_5 < 0) {
                var_v0_5 = -var_v0_5;
            }
            if (var_v0_5 < 0x96) {
                ownerRecord->position.z = privateHeight3;
                Level24_8B488Field(privateVector20, void**, 0x18) = 0;
                randomResult2 = Level24_8B488_rand();
                sharedCaller4 = ownerRecord;
                callbackParameter5 = 0xB;
                MATCHING_KEEP2(sharedCaller4, callbackParameter5);
                Level24_8B488Field(privateVector20, int*, 0xC) =
                    (int)(((randomResult2 & 3) * 0x3C) + 0x78);
                sharedCaller4->state = 0xB;
                goto block_115;
            }
            break;
        case 0xB:
            if (Level24_8B488ApproximatePlanarDistance(&ownerRecord->position,
                                                       &Level24_8B488_D_80070328.position) <
                Level24_8B488Field(privateVector20, short*, 0x10)) {
                if (Level24_8B488Field(privateVector20, short*, 0x16) != 0) {
                    if (Level24_8B488_rand() & 1) {
                        ownerRecord->state = 6;
                        sharedCaller4 = ownerRecord;
                        MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                        callbackParameter5 = 6;
                        goto block_115;
                    } else {
                        goto block_95;
                    }
                } else {
                block_95:
                    ownerRecord->state = 1;
                    sharedCaller4 = ownerRecord;
                    MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                    callbackParameter5 = 1;
                    goto block_115;
                }
            }
            if (Level24_8B488_D_8006C770 != 0) {
                ownerRecord->state = 0;
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 0;
                goto block_115;
            }
            break;
        case 0x50:
            if (Level24_8B488Field(privateVector20, int*, 0xC) == 0) {
                ownerRecord->state = 0xC;
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP_VOLATILE_CLOBBER(sharedCaller4, "memory");
                callbackParameter5 = 0xC;
                goto block_115;
            }
            break;
        case 0xC:
            if (Level24_8B488_D_8006C770 != 0) {
                temp_v0_5 = Level24_8B488Field(privateVector20, void**, 0x18);
                if (temp_v0_5 != 0) {
                    Level24_8B488Field(temp_v0_5, short*, 0xA) = 1;
                    Level24_8B488Field(Level24_8B488Field(privateVector20, void**, 0x18), short*,
                                       2) = 1;
                    Level24_8B488RequestMobyAnimation(ownerRecord, 6);
                    ownerRecord->state = 0x57;
                    return;
                }
                goto block_113;
            }
            break;
        case 0x57:
            if (Level24_8B488UpdateMobyPathMotion(ownerRecord,
                                                  Level24_8B488Field(privateVector20, void**, 0x18),
                                                  0x78, 0x64, 0, 4, 0x20, 4) &
                2) {
                Level24_8B488Field(Level24_8B488Field(privateVector20, void**, 0x18), short*, 0xA) =
                    -1;
                goto block_113;
            }
            break;
        case 0x51:
            if (Level24_8B488Field(privateVector20, int*, 0xC) == 0) {
                Level24_8B488RequestMobyAnimation(ownerRecord, 0xC);
                ownerRecord->state = 0x55;
                return;
            }
            break;
        case 0x55:
            if (Level24_8B488_D_8006C770 != 0) {
                Level24_8B488Field(privateVector20, int*, 0xC) = 0x154;
                Level24_8B488RequestMobyAnimation(ownerRecord, 6);
                ownerRecord->state = 0x56;
                return;
            }
            break;
        case 0x56:
            Level24_8B488TurnMobyTowardPlayer(ownerRecord, 4, 0, 0);
            Level24_8B488ResolveMobyYawStep(ownerRecord, 0x6E, 0, 0, 4);
            Level24_8B488CopyVector(&originalFrame.sp60, &Level24_8B488_D_80070328.unk7a[3]);
            originalFrame.sp60.x = (int)originalFrame.sp60.x * 0x1E;
            originalFrame.sp60.y *= 0x1E;
            originalFrame.sp60.z *= 0x1E;
            Level24_8B488ShiftVectorRightTowardZero(&originalFrame.sp60, 6);
            Level24_8B488AddVector(
                &originalFrame.sp60, &originalFrame.sp60,
                (Vector3D*)((unsigned char*)&Level24_8B488_D_80070328.unk7a[3] - 0x98));
            if (Level24_8B488ApproximatePlanarDistance(&ownerRecord->position,
                                                       &originalFrame.sp60) <
                Level24_8B488Field(privateVector20, short*, 0x12)) {
                sharedCaller4 = ownerRecord;
                MATCHING_KEEP(sharedCaller4);
                callbackParameter5 = 4;
                sharedCaller4->substate = 1;
                sharedCaller4->state = 4;
                goto block_115;
            }
            sharedCondition2 = Level24_8B488CountTimerDown(
                ((void*)((unsigned char*)((unsigned char*)privateVector20 + 0xC))), 4);
        block_112:
            if (sharedCondition2 != 0) {
            block_113:
                randomResult2 = Level24_8B488_rand();
                sharedCaller4 = ownerRecord;
                callbackParameter5 = 0;
                MATCHING_KEEP2(sharedCaller4, callbackParameter5);
                Level24_8B488Field(privateVector20, int*, 0xC) =
                    (int)(((randomResult2 & 3) * 0x3C) + 0x78);
                goto resetStore;
            block_114:
                sharedCaller4 = ownerRecord;
            resetStore:
                sharedCaller4->state = 0;
            block_115:
                MATCHING_KEEP2(sharedCaller4, callbackParameter5);
                Level24_8B488RequestMobyAnimation(sharedCaller4, callbackParameter5);
                return;
            }
    }
}
#undef Level24_8B488Field

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
void func_level_24_8008C1B0(Moby* mobyArgument) {
    Vector3D first;
    int pad;
    Vector3D second;
    int pad2;
    register Moby* moby __asm__("$17") = mobyArgument;
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
