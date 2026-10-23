#include "matching.h"
#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "camera.h"
#include "mobyutil.h"
#include "spu.h"
#include "savepoint.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
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
void func_level_41_80075544(void* input) {
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
void func_level_41_800761A0(Moby* mobyArgument) {
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
void func_level_41_8007682C(void* input) {
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
void func_level_41_80077D7C(Moby* moby) {
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
void func_level_41_8007803C(Moby* mobyArgument) {
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
void func_level_41_8007855C(unsigned char* input) {
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


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0.
 * Original func_level_34_800793C4 and sibling:632 instructions.
 * Raw offsets, widths, signed shifts and helper addresses follow the disc.
 * Units, helper semantics, cadence and runtime parity remain unresolved.
 * Evidence sibling4947: exact native instructions/internal targets.
 * Full executable/every-overlay retail hashes gate installation acceptance. */
#define A4946F(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define A4946W(p, o) A4946F(p, int*, o)
#define A4946P(p, o) A4946F(p, unsigned char**, o)
#define A4946B(p, o) A4946F(p, unsigned char*, o)
#define A4946H(p, o) A4946F(p, short*, o)
extern unsigned short A4946Cos[] __asm__("D_80065920"), A4946Sin[] __asm__("D_800658A0");
extern unsigned char A4946Player[] __asm__("D_80070328");
extern int A4946P24 __asm__("D_80070328 + 0x24"), A4946P224 __asm__("D_80070328 + 0x224");
extern int A4946Delta __asm__("D_8006C648"), A4946C578 __asm__("D_8006C578"),
    A4946C574 __asm__("D_8006C574");
extern unsigned char* A4946List[] __asm__("D_8006E788");
extern unsigned char* (*A4946Spawn)() __asm__("SpawnMoby");
extern int (*A4946Particle)() __asm__("SpawnParticle");
int A4946Rand() __asm__("rand");
int A4946TransformVectorByBasis() __asm__("func_8004ED6C");
int A4946CopyVector() __asm__("func_8004F178");
int A4946ShiftVectorRightTowardZero() __asm__("func_8004F110");
int A4946AddVector() __asm__("func_8004F194");
int A4946SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int A4946PlayMobySoundEvent() __asm__("func_8003BABC");
int A4946TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int A4946ApproximatePlanarDistance() __asm__("func_8004F334");
int A4946QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int A4946SubtractVector() __asm__("func_8004F1C8");
int A4946MeasureVectorLength() __asm__("func_8004EDE8");
int A4946NormalizeVectorToLength() __asm__("func_8004EF04");
int A4946SpawnMobyFromValueSelector() __asm__("func_80036A68");
int A4946DeleteMoby() __asm__("func_80055B18");
void func_level_41_80078FCC(unsigned char* input) {
    struct {
        int v18[4], v28[4], v38[4], v48[4], v58[4], v68[4];
    } frame;
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int arg4 __asm__("$4");
    register int call5 __asm__("$5");
    register unsigned char* ptr4 __asm__("$4");
    register unsigned char* ptr6 __asm__("$6");
    register unsigned char* ptr7 __asm__("$7");
    register int saved16 __asm__("$16");
    register int saved17 __asm__("$17");
    register int saved18 __asm__("$18");
    register int saved19 __asm__("$19");
    register int counter20 __asm__("$20");
    register unsigned char* owner21 __asm__("$21");
    register unsigned char* private22 __asm__("$22");
    register int saved23 __asm__("$23");
    register unsigned char* ptr16 __asm__("$16");
    register unsigned char* ptr17 __asm__("$17");
    register unsigned char* ptr18 __asm__("$18");
    register unsigned char* ptr19 __asm__("$19");
    owner21 = input;
    private22 = A4946P(owner21, 0);
    switch (A4946B(owner21, 0x49)) {
        case 0:
            work3 = 0xB0000;
            MATCHING_KEEP(work3);
            if (!(A4946W(owner21, 0x18) & work3))
                break;
            A4946B(owner21, 0x4A) = 255;
            A4946B(owner21, 0x4C) = 60;
            A4946W(private22, 0) = 0;
            A4946W(private22, 4) = A4946B(owner21, 0x44);
            A4946W(private22, 8) = A4946B(owner21, 0x45);
            A4946W(private22, 12) = A4946W(owner21, 0x14);
            if ((A4946W(owner21, 0x18) & 0x30000) == 0x10000)
                A4946B(owner21, 0x49) = 1;
            else
                A4946B(owner21, 0x49) = 2;
            break;
        case 1:
            A4946W(private22, 0) += A4946Delta;
            if (A4946W(private22, 0) < 120) {
                saved18 = 0;
                ptr17 = (unsigned char*)frame.v28;
                saved19 = 4;
                saved16 = 84;
                do {
                    ptr4 = owner21 + 32;
                    call5 = (int)frame.v18;
                    MATCHING_KEEP2(ptr4, call5);
                    work2 = A4946F((unsigned char*)A4946Cos + saved16, unsigned short*, 0);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(work2, "$6");
                    ptr6 = (unsigned char*)call5;
                    MATCHING_KEEP(ptr6);
                    work2 = (short)work2 >> 4;
                    MATCHING_KEEP(work2);
                    frame.v18[0] = work2;
                    work3 = A4946F((unsigned char*)A4946Sin + saved16, unsigned short*, 0);
                    MATCHING_KEEP(work3);
                    work2 = 384;
                    MATCHING_KEEP(work2);
                    frame.v18[2] = work2;
                    __asm__ volatile("" : : "m"(frame.v18[2]));
                    frame.v18[1] = (short)work3 >> 4;
                    A4946TransformVectorByBasis(ptr4, call5, ptr6);
                    A4946CopyVector(ptr17, frame.v18);
                    A4946ShiftVectorRightTowardZero(ptr17, 4);
                    A4946AddVector(frame.v18, frame.v18, owner21 + 12);
                    work2 = A4946Rand();
                    work3 = frame.v28[0];
                    work3 += 4;
                    MATCHING_KEEP(work3);
                    frame.v28[0] = work3 - (work2 & 7);
                    work2 = A4946Rand();
                    work3 = frame.v28[1];
                    work3 += 4;
                    MATCHING_KEEP(work3);
                    frame.v28[1] = work3 - (work2 & 7);
                    A4946Particle(1, 74, frame.v18, ptr17);
                    if (!(A4946Rand() & 7)) {
                        work2 = A4946Rand();
                        work3 = frame.v18[0];
                        work3 += 8;
                        MATCHING_KEEP(work3);
                        frame.v18[0] = work3 - (work2 & 15);
                        work2 = A4946Rand();
                        work3 = frame.v18[1];
                        work3 += 8;
                        MATCHING_KEEP(work3);
                        frame.v18[1] = work3 - (work2 & 15);
                        work2 = A4946Rand() & 7;
                        frame.v28[0] = saved19 - work2;
                        work2 = A4946Rand();
                        arg4 = 1;
                        call5 = 3;
                        ptr6 = (unsigned char*)(frame.v18);
                        ptr7 = (unsigned char*)(ptr17);
                        MATCHING_KEEP4(arg4, call5, ptr6, ptr7);
                        work2 &= 7;
                        frame.v28[1] = saved19 - work2;
                        frame.v28[2] = 8;
                        A4946Particle(arg4, call5, ptr6, ptr7);
                    }
                    saved18++;
                    saved16 += 170;
                } while (saved18 < 3);
                work3 = A4946W(private22, 0);
                MATCHING_KEEP(work3);
                if (work3 >= 57) {
                    arg4 = 120;
                    MATCHING_KEEP(arg4);
                    work2 = (arg4 - work3) >> 1;
                    work3 = (int)A4946P(private22, 0x1C);
                    work2 = (work2 << 1) + work3;
                    MATCHING_KEEP(work2);
                    work3 = A4946W(private22, 4);
                    work2 = A4946B(work2, 0);
                    work2 += work3;
                    MATCHING_KEEP(work2);
                    A4946B(owner21, 0x44) = work2;
                    work2 = (arg4 - A4946W(private22, 0)) >> 1;
                    work3 = (int)A4946P(private22, 0x1C);
                    work2 = (work2 << 1) + work3;
                    MATCHING_KEEP(work2);
                    work3 = A4946W(private22, 8);
                    work2 = A4946B(work2, 1);
                    work2 += work3;
                    MATCHING_KEEP(work2);
                    A4946B(owner21, 0x45) = work2;
                    work2 = A4946W(private22, 0);
                    MATCHING_KEEP(work2);
                    arg4 -= work2;
                    MATCHING_KEEP(arg4);
                    arg4 >>= 1;
                    work2 = (int)A4946P(private22, 0x1C);
                    arg4 = (arg4 << 1) + work2;
                    MATCHING_KEEP(arg4);
                    work3 = *(signed char*)arg4;
                    MATCHING_KEEP(work3);
                    work2 = *((signed char*)arg4 + 1);
                    MATCHING_KEEP(work2);
                    if (work3 < 0)
                        work3 = -work3;
                    MATCHING_KEEP(work3);
                    if (work2 < 0)
                        work2 = -work2;
                    MATCHING_KEEP(work2);
                    work3 += work2;
                    MATCHING_KEEP(work3);
                    work2 = work3 * 6;
                    MATCHING_KEEP(work2);
                    A4946W(owner21, 0x14) = work2;
                    work2 += A4946W(private22, 12);
                    MATCHING_KEEP(work2);
                    A4946W(owner21, 0x14) = work2;
                }
            } else {
                A4946W(private22, 0) = 0;
                A4946W(private22, 12) = A4946W(owner21, 0x14);
                A4946B(owner21, 0x49) = 2;
            }
            if (!A4946SoundHandleMatchesOwnerInStates1Or2(owner21, A4946W(private22, 0x18)))
                A4946W(private22, 0x18) = A4946PlayMobySoundEvent(owner21, 2, 4);
            break;
        case 2:
            MATCHING_BARRIER_VOLATILE("$4");
            work2 = A4946W(private22, 0);
            if (work2 == 0) {
                ptr4 = owner21;
                MATCHING_KEEP(ptr4);
                A4946B(owner21, 0x3C) = 1;
                MATCHING_KEEP(work2);
                A4946W(private22, 0x10) = 300;
                if (A4946SoundHandleMatchesOwnerInStates1Or2(ptr4, A4946W(private22, 0x18)))
                    A4946TransitionSoundHandleTo3Or5(A4946W(private22, 0x18));
                A4946PlayMobySoundEvent(owner21, 0, 0);
                counter20 = 0;
                MATCHING_OBSERVE_VOLATILE(counter20);
                saved23 = 16;
                for (; counter20 < 16; counter20++) {
                    if (A4946C578 - A4946C574 < 21)
                        break;
                    ptr16 = A4946Spawn(210, owner21);
                    ptr19 = A4946P(ptr16, 0);
                    saved18 = counter20 << 5;
                    A4946B(ptr16, 0x49) = (A4946Rand() & 1) + 18;
                    work2 = A4946Rand();
                    ptr17 = (unsigned char*)A4946Cos;
                    MATCHING_KEEP(ptr17);
                    ptr17 = (unsigned char*)saved18 + (int)ptr17;
                    MATCHING_KEEP2(ptr17, work2);
                    work2 &= 31;
                    arg4 = A4946W(ptr16, 12) - 15;
                    work3 = (short)*(unsigned short*)ptr17 >> 4;
                    MATCHING_KEEP(work3);
                    work3 += work2;
                    MATCHING_KEEP(work3);
                    arg4 += work3;
                    MATCHING_KEEP(arg4);
                    A4946W(ptr16, 12) = arg4;
                    work2 = A4946Rand();
                    work3 = (int)A4946Sin;
                    MATCHING_KEEP(work3);
                    ptr18 = (unsigned char*)saved18 + work3;
                    MATCHING_KEEP2(ptr18, work2);
                    work2 &= 31;
                    arg4 = A4946W(ptr16, 16) - 15;
                    work3 = (short)*(unsigned short*)ptr18 >> 4;
                    MATCHING_KEEP(work3);
                    work3 += work2;
                    MATCHING_KEEP(work3);
                    arg4 += work3;
                    MATCHING_KEEP(arg4);
                    A4946W(ptr16, 16) = arg4;
                    work2 = A4946Rand();
                    work3 = A4946W(ptr16, 20);
                    work3 += 128;
                    MATCHING_KEEP(work3);
                    work3 += work2 & 255;
                    MATCHING_KEEP(work3);
                    A4946W(ptr16, 20) = work3;
                    work2 = A4946Rand() & 31;
                    work3 = (short)*(unsigned short*)ptr17 >> 5;
                    MATCHING_KEEP(work3);
                    work3 += work2;
                    MATCHING_KEEP(work3);
                    work3 -= 15;
                    MATCHING_KEEP(work3);
                    A4946W(ptr19, 0) = work3;
                    work2 = A4946Rand() & 31;
                    work3 = (short)*(unsigned short*)ptr18 >> 5;
                    MATCHING_KEEP(work3);
                    work3 += work2;
                    MATCHING_KEEP(work3);
                    work3 -= 15;
                    MATCHING_KEEP(work3);
                    A4946W(ptr19, 4) = work3;
                    A4946W(ptr19, 8) = (A4946Rand() & 31) + 40;
                    A4946B(ptr16, 0x44) = A4946Rand();
                    A4946B(ptr16, 0x45) = A4946Rand();
                    A4946B(ptr16, 0x46) = A4946Rand();
                    work2 = A4946Rand() & 31;
                    A4946B(ptr19, 0x10) = saved23 - work2;
                    work2 = A4946Rand() & 31;
                    A4946B(ptr19, 0x11) = saved23 - work2;
                    work2 = A4946Rand() & 31;
                    A4946B(ptr19, 0x12) = saved23 - work2;
                    A4946W(ptr19, 12) = A4946W(owner21, 20);
                }
                counter20 = 0;
                ptr16 = (unsigned char*)frame.v38;
                saved17 = 8;
                do {
                    A4946CopyVector(ptr16, owner21 + 12);
                    counter20++;
                    work2 = A4946Rand();
                    work3 = frame.v38[0];
                    work3 += 128;
                    MATCHING_KEEP(work3);
                    frame.v38[0] = work3 - (work2 & 255);
                    work2 = A4946Rand();
                    work3 = frame.v38[1];
                    work3 += 128;
                    MATCHING_KEEP(work3);
                    frame.v38[1] = work3 - (work2 & 255);
                    work2 = A4946Rand();
                    work3 = frame.v38[2];
                    MATCHING_KEEP(work3);
                    work3 += work2 & 255;
                    MATCHING_KEEP(work3);
                    frame.v38[2] = work3;
                    work2 = A4946Rand() & 15;
                    MATCHING_KEEP(work2);
                    frame.v48[0] = saved17 - work2;
                    work2 = A4946Rand() & 15;
                    MATCHING_KEEP(work2);
                    frame.v48[1] = saved17 - work2;
                    work2 = A4946Rand();
                    arg4 = 1;
                    call5 = 1;
                    ptr6 = (unsigned char*)(ptr16);
                    ptr7 = (unsigned char*)(frame.v48);
                    MATCHING_KEEP4(arg4, call5, ptr6, ptr7);
                    work2 &= 7;
                    frame.v48[2] = work2;
                    A4946Particle(arg4, call5, ptr6, ptr7);
                } while (counter20 < 8);
                A4946B(owner21, 0x49) = 144;
                counter20 = 0;
                MATCHING_OBSERVE_VOLATILE(counter20);
                saved16 = 3;
                for (; counter20 < 8; counter20++) {
                    if (A4946C578 - A4946C574 < 21)
                        break;
                    ptr4 = (unsigned char*)309;
                    call5 = (int)owner21;
                    MATCHING_KEEP2(ptr4, call5);
                    work2 = (int)A4946Spawn(ptr4, call5);
                    A4946B(work2, 0x49) = saved16;
                }
                A4946B(owner21, 0x49) = 2;
                work2 = A4946W(private22, 0);
                MATCHING_KEEP(work2);
            }
            work3 = work2 + A4946Delta;
            MATCHING_KEEP(work3);
            A4946W(private22, 0) = work3;
            if (work3 < 27) {
                ptr17 = (unsigned char*)A4946List;
                ptr16 = *(unsigned char**)ptr17;
                ptr17 += 4;
                work3 += 2;
                work2 = work3 * 25;
                MATCHING_KEEP(work2);
                saved19 = work2 << 2;
                if (ptr16) {
                    saved18 = 2;
                    do {
                        if (A4946H(ptr16, 0x36) == A4946H(owner21, 0x36) && ptr16 != owner21) {
                            work2 = A4946ApproximatePlanarDistance(owner21 + 12, ptr16 + 12);
                            MATCHING_KEEP(work2);
                            {
                                int a = A4946W(private22, 12), c = A4946W(ptr16, 20);
                                work3 = a - c;
                                MATCHING_KEEP(work3);
                                if (work3 < 0)
                                    work3 = c - a;
                                MATCHING_KEEP(work3);
                            }
                            if (work2 < saved19) {
                                work2 = work3 < 500;
                                MATCHING_KEEP(work2);
                                if (work2 && A4946B(ptr16, 0x49) != saved18) {
                                    work3 = (int)A4946P(ptr16, 0);
                                    MATCHING_KEEP(work3);
                                    A4946B(ptr16, 0x49) = saved18;
                                    A4946W(work3, 0) = 0;
                                    A4946W(work3, 12) = A4946W(ptr16, 20);
                                }
                            }
                        }
                        ptr16 = *(unsigned char**)ptr17;
                        ptr17 += 4;
                    } while (ptr16);
                }
            }
            if (A4946W(private22, 0) < 15) {
                ptr16 = (unsigned char*)frame.v48;
                A4946CopyVector(ptr16, owner21 + 12);
                frame.v48[2] = A4946W(private22, 12) + 384;
                A4946QueryDynamicMobyGeometry(ptr16, (A4946W(private22, 0) + 2) << 7, 1, 0, 0x10000,
                                              owner21);
                if (!A4946W(private22, 0x14)) {
                    ptr17 = (unsigned char*)frame.v58;
                    ptr4 = ptr17;
                    MATCHING_OBSERVE_VOLATILE(ptr4);
                    ptr18 = A4946Player;
                    A4946SubtractVector(ptr17, ptr18, ptr16);
                    frame.v58[2] <<= 1;
                    work2 = A4946MeasureVectorLength(ptr17, 1);
                    MATCHING_KEEP(work2);
                    work3 = (A4946W(private22, 0) + 2) << 7;
                    MATCHING_KEEP(work3);
                    if (work2 < work3) {
                        ptr16 = ptr18 + 0x21C;
                        A4946CopyVector(ptr16, ptr17);
                        A4946P224 = 0;
                        A4946NormalizeVectorToLength(ptr16, 128);
                        work2 = A4946P24;
                        MATCHING_KEEP(work2);
                        A4946P224 = 32;
                        MATCHING_BARRIER_VOLATILE("memory");
                        A4946P24 = work2 | 0x86;
                        A4946W(private22, 0x14) = 1;
                    }
                }
            }
            work2 = A4946W(owner21, 20);
            arg4 = A4946W(private22, 16);
            work2 += arg4;
            MATCHING_KEEP(work2);
            work3 = A4946B(owner21, 0x45) + 4;
            MATCHING_KEEP(work3);
            A4946W(owner21, 20) = work2;
            A4946B(owner21, 0x45) = work3;
            work2 = A4946W(private22, 16) - 10;
            MATCHING_KEEP(work2);
            A4946W(private22, 16) = work2;
            if (work2 >= -300)
                break;
            A4946B(owner21, 0x49) = 112;
            counter20 = 0;
            MATCHING_OBSERVE_VOLATILE(counter20);
            saved17 = 5;
            saved16 = 1;
            for (; counter20 < 16; counter20++) {
                if (A4946C578 - A4946C574 < 21)
                    break;
                work3 = (int)A4946Spawn(309, owner21);
                MATCHING_KEEP(work3);
                if (counter20 < 6)
                    A4946B(work3, 0x49) = saved17;
                A4946B(work3, 0x3C) = saved16;
            }
            counter20 = 0;
            ptr16 = (unsigned char*)frame.v68;
            do {
                A4946CopyVector(ptr16, owner21 + 12);
                counter20++;
                work2 = A4946Rand();
                work3 = frame.v68[0];
                work3 += 128;
                MATCHING_KEEP(work3);
                frame.v68[0] = work3 - (work2 & 255);
                work2 = A4946Rand();
                work3 = frame.v68[1];
                work3 += 128;
                MATCHING_KEEP(work3);
                frame.v68[1] = work3 - (work2 & 255);
                work2 = A4946Rand();
                arg4 = 1;
                call5 = 2;
                ptr6 = (unsigned char*)(ptr16);
                ptr7 = (unsigned char*)(0);
                MATCHING_KEEP4(arg4, call5, ptr6, ptr7);
                work2 &= 511;
                frame.v68[2] += work2;
                A4946Particle(arg4, call5, ptr6, ptr7);
                A4946Particle(4, 70, ptr16, 24);
            } while (counter20 < 4);
            A4946SpawnMobyFromValueSelector(owner21, 0, 0, 0);
            A4946PlayMobySoundEvent(owner21, 1, 0);
            A4946DeleteMoby(owner21);
            break;
    }
}
#undef A4946F
#undef A4946W
#undef A4946P
#undef A4946B
#undef A4946H


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
void func_level_41_800799AC(Moby* moby) {
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

typedef struct {
    Vector3D step;
    int floorZ;
    Angle rotation;
} DecodedFallingParticleTag;
int rand(void);
void func_level_41_80079D2C(Moby* moby) {
    DecodedFallingParticleTag* tag = moby->mobyTag;
    Vector3D particle[2];
    Vector3D colour;
    if (!moby->drawn)
        func_80055B18(moby);
    moby->substate--;
    if (!moby->substate || moby->position.z < tag->floorZ) {
        SpawnParticle(8, 0x46, &moby->position, (Vector3D*)0x10);
        func_80055B18(moby);
    }
    func_8004F194(&moby->position, &moby->position, &tag->step);
    tag->step.z -= 12;
    moby->angle.roll += tag->rotation.roll;
    moby->angle.pitch += tag->rotation.pitch;
    moby->angle.yaw += tag->rotation.yaw;
    if (!(moby->substate & 1)) {
        func_8004F178(&particle[0], &moby->position);
        particle[1].x = rand() & 3;
        particle[1].y = rand() & 3;
        particle[1].z = 20;
        colour.x = 0x80;
        colour.y = 0x70;
        colour.z = 0x40;
        SpawnParticle(1, 0x11, &particle[0], &colour);
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
void func_level_41_80079E98(Moby* moby) {
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
void func_level_41_8007A19C(Moby* moby) {
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
void func_level_41_8007A4A4(void* input) {
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
void func_level_41_8007B018(Moby* moby) {
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
void func_level_41_8007B448(Moby* owner) {
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
void func_level_41_8007B5D4(Moby* moby) {
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
void func_level_41_8007B728(Moby* actor) {
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

extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_80071582;
void func_level_41_8007B968(Moby* moby) {
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
void func_level_41_8007BAB8(Moby* moby) {
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
void func_level_41_8007BB90(void* input) {
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
void func_level_41_8007C358(Moby* actor) {
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
extern unsigned char Controller7CAA0D_80071577 __asm__("D_80071590");
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
void func_level_41_8007C604(void* input) {
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
void func_level_41_8007CAD0(Moby* moby) {
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
void func_level_41_8007CB74(Moby* moby) {
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
void func_level_41_8007CF80(Moby* moby) {
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
void func_level_41_8007D260(Moby* moby) {
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
void func_level_41_8007D590(Moby* mobyArgument) {
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
void func_level_41_8007DAB8(void* input) {
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
                    if (Controller821F8Field(tag, short*, 0) == 0) {
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

void func_level_41_8007EC44(Moby* moby) {
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
void func_level_41_8007EC64(Moby* mobyArgument) {
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

void func_80055B18(Moby*);
void func_level_41_8007EE64(Moby* moby) {
    switch (moby->state) {
        case 0:
            moby->size -= 8;
            if (moby->size <= 0x20) {
                moby->size = 0;
                moby->state = 1;
            }
            break;
        case 1:
            if (moby->substate) {
                moby->size = 0x21;
                moby->state = 2;
            }
            break;
        case 2:
            moby->size += 8;
            if (moby->size >= 0x7F)
                func_80055B18(moby);
            break;
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
int A4962SoundHandleMatchesOwnerInStates1Or2_1() __asm__("func_8003BFC0");
int A4962TransitionSoundHandleTo3Or5_2() __asm__("func_8003BE70");
int A4962PlanarHeadingLookup_3() __asm__("func_8004E880");
int A4962RequestMobyAnimation_4() __asm__("func_80034F40");
int A4962SpawnMobyFromValueSelector_5() __asm__("func_80036A68");
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
int A4962SoundHandleMatchesOwnerInStates1Or2_24() __asm__("func_8003BFC0");
int A4962PlayMobySoundEvent_25() __asm__("func_8003BABC");
int A4962RandSignedBetween_26() __asm__("func_800363DC");
int A4962RandSignedBetween_27() __asm__("func_800363DC");
int A4962RandBetween_28() __asm__("func_8003636C");
int A4962ApproximatePlanarDistance_29() __asm__("func_8004F334");
int A4962PlanarHeadingLookup_30() __asm__("func_8004E880");
int A4962CountTimerDown_31() __asm__("func_800359A4");
int A4962SoundHandleMatchesOwnerInStates1Or2_32() __asm__("func_8003BFC0");
int A4962TransitionSoundHandleTo3Or5_33() __asm__("func_8003BE70");
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
int A4962ResolveMobyHeadingStep_52() __asm__("func_80035EE0");
int A4962CopyVector_53() __asm__("func_8004F178");
int A4962CountTimerDown_54() __asm__("func_800359A4");
int A4962QueryWorldHeight_55() __asm__("func_8001A358");
int A4962RefreshMobySpatialGridAndBasis_56() __asm__("func_80055D24");
int A4962MarkMobyCollectionBit_57() __asm__("func_8003BA00");
int A4962EmitMobyVertexParticles_58() __asm__("func_800369B8");
int A4962DeleteMoby_59() __asm__("func_80055B18");
void func_level_41_8007EF2C(unsigned char* input) {
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
        if (A4962SoundHandleMatchesOwnerInStates1Or2_1(owner17, A4962W(private19, 0x20)))
            A4962TransitionSoundHandleTo3Or5_2(A4962W(private19, 0x20));
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
        A4962SpawnMobyFromValueSelector_5(owner17, 0, 0, 0);
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
            if (!A4962SoundHandleMatchesOwnerInStates1Or2_24(owner17, A4962W(private19, 0x20)))
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
                if (A4962SoundHandleMatchesOwnerInStates1Or2_32(owner17, A4962W(private19, 0x20)))
                    A4962TransitionSoundHandleTo3Or5_33(A4962W(private19, 0x20));
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
            A4962ResolveMobyHeadingStep_52(owner17, arg5, arg6, 0, 500, 32);
            A4962CopyVector_53(ptr16, owner17 + 12);
            if (A4962CountTimerDown_54(private19, 2) ||
                (A4962H(private19, 0) < 150 && A4962QueryWorldHeight_55(ptr16, 512))) {
                A4962RefreshMobySpatialGridAndBasis_56(owner17, 4);
                A4962MarkMobyCollectionBit_57(owner17);
                A4962EmitMobyVertexParticles_58(owner17, 40);
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

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007FAEC..8007FDBC,181 original instructions. Rev1 raw276 routes
 * support discovery; original Rev0 defines offsets, signed shifts8,
 * threshold-before-add1500/+100 and fresh post-helper reads.
 * Raw units/private/pool/table/helper producers and cadence remain open.
 * Test: original linked words and every complete retail hash. */
extern int D_8006C770, D_8006C640;
extern Moby* D_8006C550;
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern short D_80065920[], D_800658A0[];
int func_80055E84(Moby*);
void func_level_41_8007FAEC(Moby* mobyArgument) {
    Vector3D work;
    int reserved1C;
    register Moby* moby __asm__("$16") = mobyArgument;
    register int* tag __asm__("$18");
    register int* playerZ __asm__("$17");
    int value, gap, angle;
    register int offset __asm__("$4");
    unsigned char* particle;
    tag = moby->mobyTag;
    MATCHING_BARRIER("$4");
    switch (moby->state) {
        case 0:
            value = func_80055E84(moby);
            if (value >= 23) {
                moby->colour.r = (26 - value) * 20 + 5;
                moby->colour.g = 0;
                moby->colour.b = 0;
            }
            if (D_8006C770)
                goto cleanup;
            if (moby->linkedMoby != 255) {
                register int selectedState __asm__("$3");
                register Moby* selected __asm__("$3");
                register int offset __asm__("$2") = moby->linkedMoby * 11;
                selected = D_8006C550;
                MATCHING_KEEP2(selected, offset);
                offset <<= 3;
                selected = (Moby*)((unsigned int)selected + offset);
                selectedState = selected->state;
                MATCHING_KEEP(selectedState);
                if (selectedState & 128)
                    goto cleanup;
                selectedState &= 255;
                if (selectedState == 20)
                    goto cleanup;
            }
            if (moby->substate == 0 && func_80055E84(moby) < 23) {
                playerZ = (int*)(DecodedCrystalPlayer + 8);
                MATCHING_KEEP(playerZ);
                {
                    register int actorZ __asm__("$3") = moby->position.z;
                    register int retailZ __asm__("$2") = *playerZ;
                    actorZ += 370;
                    MATCHING_KEEP2(actorZ, retailZ);
                    gap = retailZ - actorZ;
                }
                if (gap < 0)
                    gap = -gap;
                if (gap < 128) {
                    value = func_8004F334(&moby->position, (Vector3D*)(playerZ - 2));
                    if (value < tag[4]) {
                        moby->substate = 1;
                        angle = func_8004E880(playerZ[-2] - moby->position.x,
                                              playerZ[-1] - moby->position.y, 0);
                        {
                            register int mask __asm__("$5") = 0x10000000;
                            register int flags __asm__("$3") = *(int*)((char*)playerZ + 0x1C);
                            MATCHING_KEEP2(mask, flags);
                            mask |= 0x400;
                            *(int*)((char*)playerZ + 0x290) = angle;
                            {
                                register int otherFlags __asm__("$2") =
                                    *(int*)((char*)playerZ + 0x204);
                                flags |= 7;
                                *(int*)((char*)playerZ + 0x1C) = flags;
                                MATCHING_BARRIER_VOLATILE("memory");
                                offset = *(int*)(DecodedCrystalPlayer + 0x298);
                                *(int*)((char*)playerZ + 0x204) = otherFlags | mask;
                                __asm__(""
                                        : "=r"(offset)
                                        : "0"(offset), "m"(*(int*)((char*)playerZ + 0x204)));
                            }
                        }
                        {
                            register int sample __asm__("$3");
                            offset *= 2;
                            sample = *(short*)((char*)D_80065920 + offset);
                            MATCHING_KEEP(sample);
                            work.x = (sample * 5) >> 8;
                            sample = *(short*)((char*)D_800658A0 + offset);
                            MATCHING_KEEP(sample);
                            work.z = 0;
                            __asm__ volatile("" : : "m"(work.z));
                            *(int*)((char*)playerZ + 0x214) = work.x;
                            *(int*)((char*)playerZ + 0x21C) = 20;
                            work.y = (sample * 5) >> 8;
                            *(int*)((char*)playerZ + 0x218) = work.y;
                            __asm__ volatile("" : : "m"(work));
                        }
                    }
                }
            }
            /* Original threshold precedes the addition;1499 becomes1599. */
            if (tag[4] < 1500)
                tag[4] += 100;
            else
                tag[4] = 1500;
            break;
        case 1:
            if (D_8006C640 & 1) {
                work.x = 0;
                work.y = 0;
                work.z = tag[3] % 3 + 1;
                particle = (unsigned char*)SpawnParticle(1, 60, &moby->position, &work);
                if (particle)
                    particle[10] = 40;
            }
            func_8004F194(&moby->position, &moby->position, (Vector3D*)tag);
            tag[3]++;
            if (tag[3] >= 16)
                goto cleanup;
            break;
        cleanup:
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_41/moby/func_level_41_8007FDC0.s SHA256 8d387e83e39f1e60b9a9d4d0c5886bf20bfd4466906b7c7b595a11379051298b. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level41_7FDC0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level41_7FDC0QueryWorldSphere() __asm__("func_80019194");
/* extern */
int Level41_7FDC0QueryWorldHeight() __asm__("func_8001A358");
/* extern */
int Level41_7FDC0TestPaddedRotatedBox() __asm__("func_80036220");
/* extern */
int Level41_7FDC0UpdateMobyPrivateBallisticMotion() __asm__("func_80039714");
/* extern */
int Level41_7FDC0MeasureVectorLength() __asm__("func_8004EDE8");
/* extern */
int Level41_7FDC0ScaleVectorRatioQ15() __asm__("func_8004F08C");
/* extern */
int Level41_7FDC0ClearVector() __asm__("func_8004F168");
/* extern */
int Level41_7FDC0SubtractVector() __asm__("func_8004F1C8");
/* extern */
int Level41_7FDC0ApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
int Level41_7FDC0DeleteMoby() __asm__("func_80055B18");
/* extern */
int Level41_7FDC0RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
extern int Level41_7FDC0_D_8006C54C __asm__("D_8006C54C");
extern int Level41_7FDC0_D_8006C58C __asm__("D_8006C58C");
extern int Level41_7FDC0_D_8006C640 __asm__("D_8006C640");
extern unsigned char Level41_7FDC0_D_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char Level41_7FDC0_D_80070300 __asm__("D_80070300");
extern unsigned char Level41_7FDC0_D_80070328 __asm__("D_80070328");
extern Vector3D Level41_7FDC0_D_8007190C __asm__("D_8007190C");

extern int (*Level41_7FDC0PathCallback)() __asm__("unk_ovlheader_800743E8");
int Level41_7FDC0Raw391E8() __asm__("func_800391E8");
void func_level_41_8007FDC0(Moby* moby) {
    /* Original frame0x90 and scratch SP20/SP30/SP40/SP50/SP60 retained.
     * Words190..218 retain the invariant signed division multiplier inS5,
     * HI read inT0, sign/quotient inV0 and remainder arithmetic inA3.
     * Original outgoing arguments200/256 occupy SP14/SP18 explicitly;
     * the fifth named argument produces the original SW A3,SP10 call delay.
     * Empty constraints preserve the original SP/register lifetimes only.
     * Helper contracts, physical units/fixed point and frame cadence unresolved. */
    struct {
        Vector3D sp20;
        char pad_2c[4];
        Vector3D sp30;
        char pad_3c[4];
        Vector3D sp40;
        char pad_4c[4];
        int sp50;
        int sp54;
        int sp58;
        char pad_5c[4];
        Vector3D sp60;
        char pad_6c[4];
    } scratch;

    register Moby* owner18 __asm__("$18") = moby;

    register Moby* finalSpawn3 __asm__("$3");
    register Moby* child20 __asm__("$20");
    register Moby* spawned3 __asm__("$3");
    register Vector3D* temp_s0 __asm__("$16");
    register Vector3D* temp_s3 __asm__("$19");
    register Vector3D* temp_s3_2 __asm__("$19");
    register int temp_s4 __asm__("$20");
    register short temp_v0_12 __asm__("$2");
    register int temp_v1_4 __asm__("$3");
    register int temp_a3 __asm__("$7");
    register int temp_v0_7 __asm__("$16");
    register int divisionMagic21 __asm__("$21");
    register int high8 __asm__("$8");
    int product;
    register unsigned char* stack29 __asm__("$29");
    int var_hi;
    register int index16 __asm__("$16");
    register signed char* temp_v0 __asm__("$3");
    register signed char* temp_v0_2 __asm__("$3");
    register signed char* temp_v0_3 __asm__("$3");
    register signed char* temp_v0_4 __asm__("$3");
    register int temp_v0_8 __asm__("$2");
    register int temp_v1 __asm__("$3");
    register void* temp_a0 __asm__("$4");
    register void* private17 __asm__("$17");
    register void* temp_v0_11 __asm__("$2");
    register void* temp_v0_6 __asm__("$2");
    register void* temp_v1_2 __asm__("$3");
    register void* temp_v1_3 __asm__("$3");
    register void* temp_v1_5 __asm__("$3");

    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register int constant200 __asm__("$20");
    register int constant256 __asm__("$19");
    register void* vector16 __asm__("$16");
    register void* vector17 __asm__("$17");
    register void* vector19 __asm__("$19");
    MATCHING_KEEP(owner18);
    value3 = 22;
    value2 = owner18->state;
    private17 = owner18->mobyTag;
    if (value2 == value3) {
        if (Level41_7FDC0UpdateMobyPrivateBallisticMotion() != 0) {
            Level41_7FDC0ClearVector(&scratch.sp20);
            argument4 = 1;
            argument5 = 0;
            MATCHING_KEEP2(argument4, argument5);
            temp_s0 = &owner18->position;
            temp_v0 = SpawnParticle(argument4, argument5, temp_s0, &scratch.sp20);
            if (temp_v0 != 0) {
                Level41_7FDC0Field(temp_v0, signed char*, 0xA) = 0x3C;
            }
            temp_v0_2 = SpawnParticle(1, 0, temp_s0, &scratch.sp20);
            if (temp_v0_2 != 0) {
                Level41_7FDC0Field(temp_v0_2, signed char*, 0xA) = 0x28;
            }
            temp_v0_3 = SpawnParticle(1, 0x47, temp_s0, 0);
            if (temp_v0_3 != 0) {
                *temp_v0_3 = 0x48;
            }
            temp_v0_4 = SpawnParticle(1, 0x47, temp_s0, 0);
            if (temp_v0_4 != 0) {
                *temp_v0_4 = 0x48;
            }
        }
    } else {
        if ((Level41_7FDC0_D_8006C640 != 0) && (Level41_7FDC0_D_8006C54C == 0)) {
            VSync(2);
        }
        temp_v1 = owner18->state;
        if (temp_v1 >= 0x1EU) {
            if ((temp_v1 == 0x1E) && (func_800359A4(private17, 4) != 0)) {
                child20 = SpawnMoby(0x84, owner18);
                MATCHING_KEEP(child20);
                if (child20 != 0) {
                    value2 = 32;
                    owner18->state = value2;
                    value2 = 5;
                    value3 = (int)child20->mobyTag;
                    MATCHING_KEEP_CLOBBER(value3, "memory");
                    vector19 = &scratch.sp30;
                    Level41_7FDC0Field((void*)value3, short*, 0) = value2;
                    child20->state = 1;
                    temp_v0_6 = Level41_7FDC0Field(private17, void**, 0x10);
                    vector19 = &scratch.sp30;
                    argument4 = (int)vector19;
                    argument5 = Level41_7FDC0Field(temp_v0_6, short*, 0);
                    value2 = Level41_7FDC0Field(temp_v0_6, int*, 12);
                    argument5 = argument5 * 16 - 16;
                    func_8004F178(argument4, value2 + argument5);
                    func_8004F178(&scratch.sp40,
                                  Level41_7FDC0Field(Level41_7FDC0Field(private17, void**, 0x10),
                                                     Vector3D**, 0xC));
                    Level41_7FDC0SubtractVector(&scratch.sp50, &scratch.sp40, &scratch.sp30);
                    scratch.sp58 = 0;
                    scratch.sp30.z = Level41_7FDC0QueryWorldHeight(&scratch.sp30, 0x2000);
                    value2 = func_8004E880(scratch.sp50, scratch.sp54, 0);
                    argument4 = (int)vector19;
                    MATCHING_KEEP(argument4);
                    temp_v0_7 = value2;
                    func_80013D44(argument4, temp_v0_7, 0, 0);
                    if (Level41_7FDC0Field(&Level41_7FDC0_D_80070328, int*, 0x280) < 0) {
                        Level41_7FDC0Field(&Level41_7FDC0_D_80070328, int*, 0x280) = 0;
                    }
                    Level41_7FDC0ScaleVectorRatioQ15(
                        &scratch.sp50, Level41_7FDC0MeasureVectorLength(&scratch.sp50, 0), 0xC00);
                    func_8004F194(&child20->position, &scratch.sp30, (Vector3D*)&scratch.sp50);
                    argument4 = (int)owner18;
                    value3 = (int)child20->mobyTag;
                    temp_v0_8 = temp_v0_7 - 128;
                    child20->angle.yaw = temp_v0_8;
                    value2 = temp_v0_8 & 255;
                    Level41_7FDC0Field((void*)value3, short*, 6) = value2;
                    Level41_7FDC0DeleteMoby(argument4);
                }
            }
        } else {
            if ((Level41_7FDC0_D_8006C7B4 & 0x20) ||
                (*(&Level41_7FDC0_D_80070300 + Level41_7FDC0_D_8006C58C) & 0x20)) {
                Level41_7FDC0DeleteMoby(owner18);
                return;
            }
            __asm__("" : "=r"(stack29));
            if (owner18->damageFlags != 0) {
                index16 = 0;
                divisionMagic21 = 0x55555556;
                do {
                    product = index16 * divisionMagic21;
                    argument4 = 1;
                    argument5 = 279;
                    argument6 = (int)owner18;
                    constant200 = 200;
                    constant256 = 256;
                    value2 = index16 >> 31;
                    *(volatile int*)(stack29 + 20) = constant200;
                    *(volatile int*)(stack29 + 24) = constant256;
                    __asm__ volatile("" : "=h"(high8) : "l"(product));
                    value2 = high8 - value2;
                    argument7 = value2 << 1;
                    argument7 += value2;
                    argument7 = index16 - argument7 + 2;
                    spawned3 = (Moby*)Level41_7FDC0Raw391E8(argument4, argument5, argument6,
                                                            argument7, argument7);
                    if (spawned3 != 0) {
                        spawned3->size = 20;
                        spawned3->state = 22;
                    }
                    index16++;
                } while (index16 < 9);
                finalSpawn3 = func_800391E8(1, 279, owner18, 1, 1, 200, 256);
                if (finalSpawn3 != 0) {
                    finalSpawn3->state = 0x16;
                }
                if (func_8003BFC0(owner18, Level41_7FDC0Field(private17, int*, 0x3C)) != 0) {
                    func_8003BE70(Level41_7FDC0Field(private17, int*, 0x3C));
                    Level41_7FDC0Field(private17, int*, 0x3C) = -1;
                }
                func_8003BABC(owner18, 1, 0);
                func_800369B8(owner18, 0x30);
                owner18->state = 0x1E;
                owner18->unknown3[0] = 0;
                owner18->lowDrawDistance = 0;
                owner18->drawn = 0;
                owner18->unknownCollision = 0;
                Level41_7FDC0Field(private17, int*, 0) = 0x5A;
                return;
            }
            MATCHING_BARRIER_VOLATILE("$2");
            switch (temp_v1) { /* irregular */
                case 20:
                    if (Level41_7FDC0TestPaddedRotatedBox(&Level41_7FDC0_D_80070328,
                                                          private17 + 0x24, 0, 0x4000) != 0) {
                        owner18->state = 0;
                        owner18->updateDistance = 0xFF;
                        Level41_7FDC0Field(Level41_7FDC0Field(private17, void**, 0x10), short*, 2) =
                            1;
                        Level41_7FDC0Field(private17, int*, 0x3C) = -1;
                        Level41_7FDC0Field(Level41_7FDC0Field(private17, void**, 0x10), short*,
                                           0xA) = 1;
                        Level41_7FDC0Field(private17, int*, 0) = 0xB4;
                        Level41_7FDC0Field(private17, short*, 0x22) = 0;
                        owner18->lowDrawDistance = 0x40;
                        owner18->highDrawDistance = 0x40;
                        Level41_7FDC0Field(private17, short*, 0x18) = 0x15E;
                        return;
                    }
                    return;
                case 24:
                    if (func_8003BFC0(owner18, Level41_7FDC0Field(private17, int*, 0x3C)) == 0) {
                        Level41_7FDC0Field(private17, int*, 0x3C) = func_8003BABC(owner18, 0, 4);
                    }
                    temp_v0_11 = Level41_7FDC0Field(private17, void**, 0x10);
                    argument4 = (int)&scratch.sp40;
                    argument5 = Level41_7FDC0Field(temp_v0_11, short*, 0);
                    value2 = Level41_7FDC0Field(temp_v0_11, int*, 12);
                    argument5 = argument5 * 16 - 16;
                    func_8004F178(argument4, value2 + argument5);
                    if (func_800359A4(private17, 4) != 0) {
                        if (func_8004F264(func_8004E880(scratch.sp40.x - owner18->position.x,
                                                        scratch.sp40.y - owner18->position.y, 0),
                                          (int)owner18->angle.yaw) >= 0x41) {
                            temp_v1_2 = Level41_7FDC0Field(private17, void**, 0x10);
                            Level41_7FDC0Field(private17, int*, 0) = 0x3C;
                            Level41_7FDC0Field(temp_v1_2, short*, 2) =
                                (short)((unsigned short)Level41_7FDC0Field(temp_v1_2, short*, 0) -
                                        1);
                            Level41_7FDC0Field(private17, short*, 0x22) = 0;
                        }
                    }
                    Level41_7FDC0PathCallback(owner18, Level41_7FDC0Field(private17, void**, 16),
                                              private17 + 20);
                    Level41_7FDC0RefreshMobySpatialGridAndBasis(owner18, 6);
                    vector16 = &scratch.sp40;
                    argument4 = (int)vector16;
                    MATCHING_KEEP(argument4);
                    temp_s3 = &owner18->position;
                    func_8004F178(argument4, temp_s3);
                    scratch.sp40.z += 0x2BC;
                    if (Level41_7FDC0QueryWorldSphere(&scratch.sp40, 0x384) != 0) {
                        func_8004F178(temp_s3, &Level41_7FDC0_D_8007190C);
                        owner18->position.z -= 0x2BC;
                    }
                    if (Level41_7FDC0ApproximatePlanarDistance(temp_s3, &Level41_7FDC0_D_80070328) <
                        0x4E20) {
                        owner18->state = 0;
                        Level41_7FDC0Field(private17, int*, 0) = 0;
                        return;
                    }
                    break;
                case 0:
                    temp_s4 =
                        Level41_7FDC0Field(Level41_7FDC0Field(private17, void**, 0x10), short*, 2);
                    if (func_8003BFC0(owner18, Level41_7FDC0Field(private17, int*, 0x3C)) == 0) {
                        Level41_7FDC0Field(private17, int*, 0x3C) = func_8003BABC(owner18, 0, 4);
                    }
                    if (func_800359A4(private17, 4) != 0) {
                        Level41_7FDC0Field(private17, short*, 0x22) = 1;
                        Level41_7FDC0Field(private17, short*, 0x1A) = 0x28;
                        temp_v0_12 =
                            ((int)Level41_7FDC0Field(&Level41_7FDC0_D_80070328, int*, 0xB4) >> 5) +
                            0x32;
                        Level41_7FDC0Field(private17, short*, 0x18) = temp_v0_12;
                        if (temp_v0_12 < 0x96) {
                            Level41_7FDC0Field(private17, short*, 0x18) = 0x96;
                        }
                        if (Level41_7FDC0Field(private17, short*, 0x18) >= 0x12D) {
                            Level41_7FDC0Field(private17, short*, 0x18) = 0x12C;
                        }
                    }
                    vector16 = &scratch.sp60;
                    argument4 = (int)vector16;
                    MATCHING_KEEP(argument4);
                    temp_s3_2 = &owner18->position;
                    func_8004F178(argument4, temp_s3_2);
                    scratch.sp60.z += 0x2BC;
                    if (Level41_7FDC0QueryWorldSphere(&scratch.sp60, 0x384) != 0) {
                        func_8004F178(temp_s3_2, &Level41_7FDC0_D_8007190C);
                        owner18->position.z -= 0x2BC;
                    }
                    if ((Level41_7FDC0Field(private17, int*, 0) == 0) &&
                        (func_8004F264(
                             func_8004E880(Level41_7FDC0Field(&Level41_7FDC0_D_80070328, int*, 0) -
                                               owner18->position.x,
                                           Level41_7FDC0Field(&Level41_7FDC0_D_80070328, int*, 4) -
                                               owner18->position.y,
                                           0),
                             (int)owner18->angle.yaw) < 0x1A)) {
                        if (Level41_7FDC0ApproximatePlanarDistance(
                                temp_s3_2, &Level41_7FDC0_D_80070328) < 0x4000) {
                            temp_v1_3 = Level41_7FDC0Field(private17, void**, 0x10);
                            value2 = Level41_7FDC0Field(temp_v1_3, short*, 10);
                            MATCHING_KEEP(value2);
                            Level41_7FDC0Field(temp_v1_3, short*, 10) = -value2;
                            temp_a0 = Level41_7FDC0Field(private17, void**, 0x10);
                            temp_v1_4 = Level41_7FDC0Field(temp_a0, short*, 0);
                            Level41_7FDC0Field(temp_a0, short*, 2) =
                                (short)((int)(Level41_7FDC0Field(temp_a0, short*, 2) +
                                              Level41_7FDC0Field(temp_a0, short*, 0xA) +
                                              temp_v1_4) %
                                        temp_v1_4);
                            Level41_7FDC0Field(private17, int*, 0) = 0x78;
                            Level41_7FDC0Field(private17, short*, 0x1A) = 0x41;
                            Level41_7FDC0Field(private17, short*, 0x18) = 0xB4;
                            Level41_7FDC0Field(private17, short*, 0x22) = 0;
                        }
                    }
                    Level41_7FDC0PathCallback(owner18, Level41_7FDC0Field(private17, void**, 16),
                                              private17 + 20);
                    Level41_7FDC0RefreshMobySpatialGridAndBasis(owner18, 6);
                    if (Level41_7FDC0Field(Level41_7FDC0Field(private17, void**, 0x10), short*,
                                           2) != temp_s4) {
                        if (Level41_7FDC0Field(private17, int*, 0) < 0x1E) {
                            Level41_7FDC0Field(private17, int*, 0) = 0x1E;
                        }
                        Level41_7FDC0Field(private17, short*, 0x22) = 0;
                        if ((temp_s4 ==
                             (Level41_7FDC0Field(Level41_7FDC0Field(private17, void**, 0x10),
                                                 short*, 0) -
                              1)) &&
                            (Level41_7FDC0ApproximatePlanarDistance(
                                 &owner18->position, &Level41_7FDC0_D_80070328) >= 0x55F1)) {
                            temp_v1_5 = Level41_7FDC0Field(private17, void**, 0x10);
                            Level41_7FDC0Field(temp_v1_5, short*, 2) =
                                (short)((unsigned short)Level41_7FDC0Field(temp_v1_5, short*, 0) -
                                        1);
                            Level41_7FDC0Field(private17, short*, 0x1A) = 0x1E;
                            Level41_7FDC0Field(private17, short*, 0x18) = 0xB4;
                            Level41_7FDC0Field(private17, int*, 0) = 0x3C;
                            owner18->state = 0x18;
                        }
                    }
                    break;
            }
        }
    }
}
#undef Level41_7FDC0Field

extern unsigned char* D_8006C54C;
extern unsigned char D_level_41_80096324;
extern int D_8006C774;
extern unsigned int DecodedPatchedFunction[] asm("func_8005663C");
void func_level_41_8008067C(void) {
    if (D_8006C54C - 1 == &D_level_41_80096324 && D_8006C774) {
        /* Retail writes these two words into the EXE routine itself. */
        DecodedPatchedFunction[0] = 0x03E00008;
        DecodedPatchedFunction[1] = 0;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated, not human reviewed. UNINSTALLED fresh2445 probe; all
 * source/ownerInput/helper/alias/native/RTL/linked/fullimage gates pending. */
#define Level41_806C8Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level41_806C8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level41_806C8SetCameraMode11Target() __asm__("func_80013D44");
int Level41_806C8RequestMobyAnimation() __asm__("func_80034F40");
int Level41_806C8SetMobyAnimation() __asm__("func_80034F80");
int Level41_806C8TurnMobyTowardHeading() __asm__("func_8003585C");
int Level41_806C8CountTimerDown() __asm__("func_800359A4");
int Level41_806C8UpdateMobyPathMotion() __asm__("func_80035A80");
int Level41_806C8ResolveMobyYawStep() __asm__("func_80035DDC");
int Level41_806C8UpdateMobyInteractionGate() __asm__("func_80037BBC");
int Level41_806C8RegisterTrackedValue() __asm__("func_8003B7B4");
int Level41_806C8PlayMobySoundEvent() __asm__("func_8003BABC");
int Level41_806C8PlanarHeadingLookup() __asm__("func_8004E880");
int Level41_806C8CopyVector() __asm__("func_8004F178");
int Level41_806C8AddVector() __asm__("func_8004F194");
int Level41_806C8AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Level41_806C8ApproximatePlanarDistance() __asm__("func_8004F334");
int Level41_806C8AllocateVectorTrailRecord() __asm__("func_80050844");
int Level41_806C8StartDialogue() __asm__("func_800512E4");
int Level41_806C8DeleteMoby() __asm__("func_80055B18");
int Level41_806C8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level41_806C8ReadSelectedFrameScalar() __asm__("func_80055E84");
int Level41_806C8InterpolateMobyVertex() __asm__("func_80055F14");
extern int Level41_806C8_D_800658A0 __asm__("D_800658A0");
extern int Level41_806C8_D_80065920 __asm__("D_80065920");
extern int Level41_806C8_D_8006C550 __asm__("D_8006C550");
extern int Level41_806C8_D_8006C58C __asm__("D_8006C58C");
extern int Level41_806C8_D_8006C640 __asm__("D_8006C640");
extern int Level41_806C8_D_8006C730 __asm__("D_8006C730");
extern int Level41_806C8_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level41_806C8_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level41_806C8_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level41_806C8_D_8006D088 __asm__("D_8006D088");
extern int Level41_806C8_D_8006E344 __asm__("D_8006E344");
extern int Level41_806C8_D_80070300 __asm__("D_80070300");
extern int Level41_806C8_D_80070328 __asm__("D_80070328");
extern int Level41_806C8_D_level_41_80096324 __asm__("D_level_41_80096324");
extern int (*Level41_806C8_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level41_806C8_SpawnParticle)() __asm__("SpawnParticle");
extern void Level41_806C8_func_level_41_80075544(void) __asm__("func_level_41_80075544");
extern int Level41_806C8_main_TEXT_END __asm__("main_TEXT_END");
extern int Level41_806C8_main_TEXT_START __asm__("main_TEXT_START");
extern int (*Level41_806C8_unk_ovlheader_80074330)() __asm__("unk_ovlheader_80074330");
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
} Level41_806C8Product;
void func_level_41_800806C8(void* ownerInput) {
    int crcByteCounter, crcBitCounter, firstPoint, firstX, firstY;
    unsigned int crcCursor;

    register int temporary2 __asm__("$2");
    register int temporary3 __asm__("$3");
    register int argument0 __asm__("$4");
    register int argument1 __asm__("$5");
    register int argument2 __asm__("$6");
    register int argument3 __asm__("$7");
    register int temporary8 __asm__("$8");
    register int temporary9 __asm__("$9");
    register int temporary10 __asm__("$10");
    register int temporary11 __asm__("$11");
    register int temporary12 __asm__("$12");
    register int temporary13 __asm__("$13");
    register int temporary14 __asm__("$14");
    register int temporary15 __asm__("$15");
    register int saved16 __asm__("$16");
    register int saved17 __asm__("$17");
    register int saved18 __asm__("$18");
    register int owner __asm__("$19");
    register int privateState __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int saved23 __asm__("$23");
    register int temporary24 __asm__("$24");
    register int temporary25 __asm__("$25");
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
            int sp90;
            int sp94;
            int sp98;
            int sp9C;
            int spA0;
            int spA4;
            int spA8;
            int spAC;
            int spB0;
            int spB4;
            int spB8;
            int spBC;
            int spC0;
            int spC4;
            int spC8;
            int spCC;
            int spD0;
            int spD4;
            int spD8;
            int spDC;
            int spE0;
            int spE4;
            int spE8;
            int spEC;
            int spF0;
            int spF4;
            int spF8;
            int spFC;
            int sp100;
            int sp104;
            int sp108;
            int sp10C;
            int sp110;
            int sp114;
            int sp118;
            int sp11C;
            int sp120;
            int sp124;
            int sp128;
            int sp12C;
            int sp130;
            int sp134;
            int sp138;
            int sp13C;
            int sp140;
            int sp144;
            int sp148;
            int sp14C;
            int sp150;
            int sp154;
        } fields;
        struct {
            int prefix[57];
            int indexed[19];
            int tail[2];
        } selection;
    } locals;
    Level41_806C8Product wholeProduct381, wholeProduct2168;
    __asm__("" : "=m"(locals.fields.sp104), "=m"(locals.fields.sp114), "=m"(locals.fields.sp124));
    owner = (int)ownerInput;
    Level41_806C8Keep(owner);
    argument0 = (int)ownerInput;
    privateState = Level41_806C8Field(owner, int*, 0);
    if ((unsigned int)Level41_806C8Field(privateState, unsigned int*, 0x48) >=
        (unsigned int)(int)&Level41_806C8_func_level_41_80075544) {
        crcByteCounter = 0;
        argument2 = (int)&Level41_806C8_D_level_41_80096324;
        Level41_806C8Keep(argument2);
    loop_2:
        crcCursor = Level41_806C8Field(privateState, unsigned int*, 0x48);
        if (crcCursor < (unsigned int)argument2) {
            crcBitCounter = 0;
            Level41_806C8Field(privateState, int*, 0x44) =
                (int)(Level41_806C8Field(privateState, int*, 0x44) ^
                      (Level41_806C8Field(crcCursor, unsigned char*, 0) << 8));
        originalCRC2445First:
            temporary3 = Level41_806C8Field(privateState, volatile int*, 0x44);
            temporary2 = temporary3 & 0x8000;
            if (temporary2) {
                temporary2 = (unsigned int)temporary3 << 1;
                temporary2 ^= 0x8005;
            } else
                temporary2 = (unsigned int)temporary3 << 1;
            Level41_806C8Field(privateState, int*, 0x44) = temporary2;
            crcBitCounter += 1;
            temporary2 = crcBitCounter < 8;
            if (temporary2)
                goto originalCRC2445First;
            crcByteCounter += 1;
            Level41_806C8Field(privateState, unsigned int*, 0x48) =
                (unsigned int)(Level41_806C8Field(privateState, unsigned int*, 0x48) + 1);
            if (crcByteCounter >= 0x40) {

            } else {
                goto loop_2;
            }
        }
    }
    if ((Level41_806C8Field(privateState, unsigned int*, 0x48) ==
         (int)&Level41_806C8_D_level_41_80096324) &&
        (Level41_806C8Field(privateState, int*, 0x44) != 0)) {
        Level41_806C8Field((int)&Level41_806C8_D_80070300, signed char*, 0x10) = 0;
        Level41_806C8Field((int)&Level41_806C8_D_80070300, signed char*, 0x19) = 0;
        Level41_806C8Field(privateState, int*, 0x44) = 0;
    }
    temporary3 = Level41_806C8Field(owner, unsigned char*, 72);

    switch ((unsigned int)temporary3) {
        case 0:
            goto original2445_1692;
        case 1:
            goto original2445_1901;
        case 2:
            goto original2445Return;
        case 3:
            goto original2445Return;
        case 4:
            goto original2445_2029;
        case 5:
            goto original2445_2136;
        case 6:
            goto original2445_2324;
        case 7:
            goto original2445Return;
        case 8:
            goto original2445Return;
        case 9:
            goto original2445Return;
        case 10:
            goto original2445Return;
        case 11:
            goto original2445Return;
        case 12:
            goto original2445Return;
        case 13:
            goto original2445Return;
        case 14:
            goto original2445Return;
        case 15:
            goto original2445Return;
        case 16:
            goto original2445Return;
        case 17:
            goto original2445Return;
        case 18:
            goto original2445Return;
        case 19:
            goto original2445Return;
        case 20:
            goto original2445_1287;
        case 21:
            goto original2445_1369;
        case 22:
            goto original2445_1932;
        case 23:
            goto original2445_2431;
        case 24:
            goto original2445_1281;
        case 25:
            goto original2445_1651;
        case 26:
            goto original2445_1680;
        case 27:
            goto original2445Return;
        case 28:
            goto original2445_2387;
        case 29:
            goto original2445Return;
        case 30:
            goto original2445_2417;
        case 31:
            goto original2445Return;
        case 32:
            goto original2445_1055;
        case 33:
            goto original2445_1064;
        case 34:
            goto original2445_1077;
        case 35:
            goto original2445Return;
        case 36:
            goto original2445_1116;
        case 37:
            goto original2445Return;
        case 38:
            goto original2445Return;
        case 39:
            goto original2445Return;
        case 40:
            goto original2445_687;
        case 41:
            goto original2445Return;
        case 42:
            goto original2445_874;
        case 43:
            goto original2445Return;
        case 44:
            goto original2445_1020;
        case 45:
            goto original2445Return;
        case 46:
            goto original2445_2362;
        case 47:
            goto original2445Return;
        case 48:
            goto original2445_538;
        case 49:
            goto original2445Return;
        case 50:
            goto original2445_677;
        case 51:
            goto original2445Return;
        case 52:
            goto original2445_236;
        case 53:
            goto original2445Return;
        case 54:
            goto original2445_315;
        case 55:
            goto original2445Return;
        case 56:
            goto original2445_492;
        case 57:
            goto original2445Return;
        case 58:
            goto original2445_148;
        case 59:
            goto original2445_154;
        case 60:
            goto original2445_223;
        case 61:
            goto original2445Return;
        case 62:
            goto original2445_75;
        case 63:
            goto original2445Return;
        case 64:
            goto original2445_104;
        case 65:
            goto original2445Return;
        case 66:
            goto original2445_1418;
        case 67:
            goto original2445Return;
        case 68:
            goto original2445_1594;
        case 69:
            goto original2445Return;
        case 70:
            goto original2445_1623;
        case 71:
            goto original2445Return;
        case 72:
            goto original2445_2431;
        case 73:
            goto original2445Return;
        case 74:
            goto original2445_1590;
        case 75:
            goto original2445Return;
        case 76:
            goto original2445_1561;
        case 77:
            goto original2445Return;
        case 78:
            goto original2445_1472;
        case 79:
            goto original2445Return;
        case 80:
            goto original2445_1472;
        case 81:
            goto original2445Return;
        case 82:
            goto original2445_1561;
        default:
            goto original2445Return;
    }
original2445_75:
    firstPoint = Level41_806C8Field(Level41_806C8Field(privateState, int*, 0x34), int**, 0xC);
    firstX = Level41_806C8Field(firstPoint, int*, 0) - Level41_806C8Field(owner, int*, 0xC);
    locals.fields.sp20 = firstX;
    firstY = Level41_806C8Field(firstPoint, int*, 4) - Level41_806C8Field(owner, int*, 0x10);
    locals.fields.sp24 = firstY;
    if (Level41_806C8TurnMobyTowardHeading(
            owner, Level41_806C8PlanarHeadingLookup(firstX, firstY, 0), 6, 3, 1, 0) != 0) {
        Level41_806C8RequestMobyAnimation(owner, 0);
        Level41_806C8Field(owner, unsigned char*, 0x48) = 0x40U;
        goto original2445Return;
    }
    goto original2445Return;
original2445_104:
    if (Level41_806C8CountTimerDown(privateState + 0x40, 2) != 0) {
        Level41_806C8Field(owner, int*, 0x18) = 0;
        Level41_806C8Field(
            (int)((unsigned int)Level41_806C8Field(privateState, int*, 0x30) * 0x58U +
                  (unsigned int)Level41_806C8_D_8006C550),
            signed char*, 0x49) = 0;
        Level41_806C8Field(
            (int)((unsigned int)Level41_806C8Field(privateState, int*, 0x30) * 0x58U +
                  (unsigned int)Level41_806C8_D_8006C550),
            signed char*, 0x48) = 0;
        Level41_806C8Field(
            Level41_806C8Field(
                (int)((unsigned int)Level41_806C8Field(privateState, int*, 0x30) * 0x58U +
                      (unsigned int)Level41_806C8_D_8006C550),
                int*, 0),
            int*, 8) = 2;
        Level41_806C8Field(owner, unsigned char*, 0x48) = 0x3AU;
        goto original2445Return;
    }
    goto original2445Return;
original2445_148:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 & 1;
    if (temporary2 != 0 ? (temporary2 = 0 + 76, 1) : (temporary2 = 0 + 76, 0))
        goto original2445_1713;
original2445_154:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14784);

    if (temporary2 != 0)
        goto original2445_194;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 & 1;
    if (temporary2 != 0)
        goto original2445_174;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = Level41_806C8_D_8006C58C;

    temporary2 =
        Level41_806C8Field(((int)&Level41_806C8_D_80070300 + temporary2), unsigned char*, 0);

    temporary2 = temporary2 & 1;
    if (temporary2 == 0)
        goto original2445_194;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_174:
    temporary3 = Level41_806C8Field(privateState, int*, 48);
    argument0 = owner + 0;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    argument1 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = 0 + 128;
    Level41_806C8Field(argument1, int*, 8) = temporary2;
    argument1 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = 0 + 60;
    Level41_806C8Field(argument1, int*, 12) = temporary2;
    temporary2 = 0 + 1;
    Level41_806C8Field(temporary3, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 72) = temporary2;
    goto original2445_2432;
original2445_194:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2)
        goto original2445_206;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 == 0)
        goto original2445_206;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_206:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_212;
    argument1 = 0 + 3;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_212:
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = Level41_806C8UpdateMobyInteractionGate(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level41_806C8StartDialogue(argument0, argument1, argument2);
    temporary2 = 0 + 60;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_223:
    temporary3 = (int)0x80070000U;
    Level41_806C8Keep(temporary3);
    temporary3 = Level41_806C8Field(temporary3, int*, -7356);
    temporary2 = 0 + 1;
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original2445Return;
    argument1 = 0 + 4;
    Level41_806C8Field(owner, int*, 24) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 52;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 255;
    Level41_806C8Field(owner, unsigned char*, 74) = temporary2;
    goto original2445Return;
original2445_236:
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    argument0 = Level41_806C8Field(temporary3, int*, 12);
    temporary2 = Level41_806C8Field(owner, int*, 12);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 40) = argument0;
    argument1 = Level41_806C8Field(temporary3, int*, 16);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 44) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    argument0 = owner + 0;
    argument1 = 0 + 5;
    Level41_806C8RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP2(argument0, argument1);
    saved16 = (int)&locals.fields.sp38;
    Level41_806C8Keep(saved16);
    argument2 = saved16 + 0;
    Level41_806C8InterpolateMobyVertex(argument0, argument1, argument2);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(saved16, "$17");
    saved18 = (int)&locals.fields.sp28;
    Level41_806C8Keep(saved18);
    argument0 = saved18 + 0;
    saved17 = owner + 12;
    Level41_806C8Keep(saved17);
    argument1 = saved17 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved17 + 0;
    argument1 = saved16 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    temporary2 = (int)Level41_806C8_SpawnParticle;

    argument3 = 0 + 3;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary3 = temporary2 + 0;
    temporary2 = 0 + 96;
    if (temporary3 == 0)
        goto original2445_296;
    Level41_806C8Field(temporary3, unsigned char*, 12) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 13) = temporary2;
    temporary2 = 0 + 192;
    Level41_806C8Field(temporary3, unsigned char*, 14) = temporary2;
original2445_296:
    argument0 = saved17 + 0;
    argument1 = saved18 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 5;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 5;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 54;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 60;
    Level41_806C8Field(privateState, short*, 66) = temporary2;
    temporary2 = 0 + 400;
    Level41_806C8Field(privateState, short*, 64) = temporary2;
    goto original2445Return;
original2445_315:
    saved17 = 0 + 0;
    Level41_806C8Keep(saved17);
    argument0 = owner + 0;
    argument1 = 0 + 5;
    Level41_806C8RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP2(argument0, argument1);
    saved16 = (int)&locals.fields.sp60;
    Level41_806C8Keep(saved16);
    argument2 = saved16 + 0;
    Level41_806C8InterpolateMobyVertex(argument0, argument1, argument2);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(saved16, "$18");
    saved21 = (int)&locals.fields.sp50;
    Level41_806C8Keep(saved21);
    argument0 = saved21 + 0;
    saved18 = owner + 12;
    Level41_806C8Keep(saved18);
    argument1 = saved18 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved18 + 0;
    argument1 = saved16 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    temporary2 = (int)Level41_806C8_SpawnParticle;

    argument3 = 0 + 3;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary3 = temporary2 + 0;
    temporary2 = 0 + 96;
    if (temporary3 == 0)
        goto original2445_347;
    Level41_806C8Field(temporary3, unsigned char*, 12) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 13) = temporary2;
    temporary2 = 0 + 192;
    Level41_806C8Field(temporary3, unsigned char*, 14) = temporary2;
original2445_347:
    argument0 = saved18 + 0;
    argument1 = saved21 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    temporary2 = Level41_806C8Field(privateState, short*, 66);

    argument0 = privateState + 66;
    if (temporary2 != 0)
        goto original2445_374;
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    argument0 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = 0 + 128;
    Level41_806C8Field(argument0, int*, 8) = temporary2;
    argument0 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = 0 + 60;
    Level41_806C8Field(argument0, int*, 12) = temporary2;
    temporary2 = 0 + 1;
    Level41_806C8Field(temporary3, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 72) = temporary2;
    goto original2445_376;
original2445_374:
    argument1 = 0 + 2;
    temporary2 = Level41_806C8CountTimerDown(argument0, argument1);
original2445_376:
    argument0 = (short)Level41_806C8Field(privateState, unsigned short*, 64);
    argument0 = argument0 % 10;
    argument0 = (int)((unsigned int)argument0 << 16);
    if (argument0 != 0 ? (argument0 = 0 + 754, 1) : (argument0 = 0 + 754, 0))
        goto original2445_399;
    Level41_806C8Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 17120);
    Level41_806C8Keep(temporary2);

    argument1 = owner + 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved17 = temporary2 + 0;
    Level41_806C8Keep(saved17);
original2445_399:
    if (saved17 == 0) {
        argument0 = owner + 0;
        goto original2445_480;
    }
    argument0 = owner + 0;
    argument1 = 0 + 0;
    saved16 = Level41_806C8Field(saved17, int*, 0);
    argument2 = 0 + 0;
    Level41_806C8PlayMobySoundEvent(argument0, argument1, argument2);
    saved21 = saved17 + 12;
    Level41_806C8Keep(saved21);
    argument0 = saved21 + 0;
    saved18 = (int)&locals.fields.sp60;
    Level41_806C8Keep(saved18);
    argument1 = saved18 + 0;
    Level41_806C8Field(saved17, unsigned char*, 65) = 0;
    Level41_806C8Field(saved17, unsigned char*, 76) = 0;
    Level41_806C8Field(saved17, unsigned char*, 77) = 0;
    Level41_806C8Field(saved17, int*, 8) = 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved21 + 0;
    argument1 = 0 + 8;
    argument2 = 0 + 10;
    MATCHING_KEEP2_VOLATILE_CLOBBER(argument1, argument2, "$7");
    argument3 = (int)0x00C00000U;
    Level41_806C8Keep(argument3);
    argument3 = argument3 | 24672;
    MATCHING_KEEP_CLOBBER(argument3, "$2");
    temporary2 = 0 + 6;
    Level41_806C8Field(saved17, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 1;
    Level41_806C8Field(saved17, unsigned char*, 73) = temporary2;
    temporary2 = 0 + 120;
    Level41_806C8Field(saved16, short*, 0) = temporary2;
    temporary2 = Level41_806C8AllocateVectorTrailRecord(argument0, argument1, argument2, argument3);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    argument3 = 0 + 3;
    Level41_806C8Field(saved16, int*, 8) = temporary2;
    __asm__ volatile("" ::"r"(temporary2) : "$8", "memory");
    temporary3 = Level41_806C8Field(privateState, int*, 48);
    temporary8 = (int)Level41_806C8_SpawnParticle;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    Level41_806C8Field(saved16, int*, 12) = temporary3;
    temporary2 = ((int (*)())temporary8)(argument0, argument1, argument2, argument3);
    temporary3 = temporary2 + 0;
    Level41_806C8Field(saved16, int*, 16) = temporary3;
    if (temporary3 == 0)
        goto original2445_454;
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = 0 + 96;
    Level41_806C8Field(temporary3, unsigned char*, 12) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 13) = temporary2;
    temporary2 = 0 + 192;
    Level41_806C8Field(temporary3, unsigned char*, 14) = temporary2;
    temporary2 = 0 + 120;
    Level41_806C8Field(temporary3, unsigned char*, 10) = temporary2;
original2445_454:
    argument1 = Level41_806C8Field(saved16, int*, 12);
    argument0 = saved18 + 0;
    argument1 = argument1 + 12;
    Level41_806C8CopyVector(argument0, argument1);
    argument2 = 0 + 0;
    temporary2 = Level41_806C8Field((int)&locals, volatile int*, 72);
    temporary3 = Level41_806C8Field((int)&locals, volatile int*, 64);
    temporary2 = temporary2 + 1024;
    Level41_806C8Field((int)&locals, int*, 72) = temporary2;
    argument0 = Level41_806C8Field(saved17, int*, 12);
    temporary2 = Level41_806C8Field((int)&locals, volatile int*, 68);
    argument1 = Level41_806C8Field(saved17, int*, 16);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = saved21 + 0;
    argument1 = saved18 + 0;
    Level41_806C8Field(saved17, unsigned char*, 70) = temporary2;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    argument0 = temporary2 + 0;
    temporary2 = Level41_806C8Field((int)&locals, volatile int*, 72);
    argument1 = Level41_806C8Field(saved17, int*, 20);
    argument2 = 0 + 0;
    argument1 = temporary2 - argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    Level41_806C8Field(saved17, unsigned char*, 69) = temporary2;
original2445_480:
    argument0 = privateState + 64;
    argument1 = 0 + 2;
    temporary2 = Level41_806C8CountTimerDown(argument0, argument1);
    if (temporary2 == 0)
        goto original2445Return;
    argument0 = owner + 0;
    argument1 = 0 + 6;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 6;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 56;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_492:
    argument0 = owner + 0;
    argument1 = 0 + 5;
    Level41_806C8RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP2(argument0, argument1);
    saved16 = (int)&locals.fields.sp80;
    Level41_806C8Keep(saved16);
    argument2 = saved16 + 0;
    Level41_806C8InterpolateMobyVertex(argument0, argument1, argument2);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(saved16, "$17");
    saved18 = (int)&locals.fields.sp70;
    Level41_806C8Keep(saved18);
    argument0 = saved18 + 0;
    saved17 = owner + 12;
    Level41_806C8Keep(saved17);
    argument1 = saved17 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved17 + 0;
    argument1 = saved16 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    temporary2 = (int)Level41_806C8_SpawnParticle;

    argument3 = 0 + 3;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary3 = temporary2 + 0;
    temporary2 = 0 + 96;
    if (temporary3 == 0)
        goto original2445_523;
    Level41_806C8Field(temporary3, unsigned char*, 12) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 13) = temporary2;
    temporary2 = 0 + 192;
    Level41_806C8Field(temporary3, unsigned char*, 14) = temporary2;
original2445_523:
    argument0 = saved17 + 0;
    argument1 = saved18 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 0;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 4;
    Level41_806C8Field(privateState, short*, 64) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 62;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_538:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14784);

    if (temporary2 != 0)
        goto original2445_604;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 & 1;
    argument2 = 0 + 0;
    if (temporary2 != 0)
        goto original2445_558;
    temporary2 = Level41_806C8_D_8006C58C;

    temporary2 =
        Level41_806C8Field(((int)&Level41_806C8_D_80070300 + temporary2), unsigned char*, 0);

    temporary2 = temporary2 & 1;
    if (temporary2 == 0)
        goto original2445_604;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_558:
    temporary8 = 0 + 754;
    argument3 = 0 + 2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 67);
    temporary3 = Level41_806C8_D_8006C730;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 + temporary3;
    argument1 = Level41_806C8Field(temporary2, int*, 0);
original2445_566:

    temporary3 = Level41_806C8Field(argument1, unsigned short*, 0);

    temporary3 = temporary3 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    temporary2 = Level41_806C8Field(temporary3, short*, 54);

    if (temporary2 != temporary8)
        goto original2445_594;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary8);
    temporary2 = Level41_806C8Field(temporary3, unsigned char*, 72);

    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 == 0)
        goto original2445_594;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = Level41_806C8Field(temporary3, int*, 0);
    Level41_806C8Field(temporary3, unsigned char*, 72) = argument3;
    Level41_806C8Field(temporary3, unsigned char*, 73) = argument3;
    temporary3 = Level41_806C8Field(temporary3, int*, 20);
    argument0 = Level41_806C8Field(temporary2, unsigned short*, 2);
    Level41_806C8Field(temporary2, short*, 4) = temporary3;
    Level41_806C8Field(temporary2, short*, 0) = argument0;
original2445_594:
    temporary2 = Level41_806C8Field(argument1, short*, 0);

    argument1 = argument1 + 2;
    if (temporary2 < 0)
        goto original2445_2431;
    argument2 = argument2 + 1;
    temporary2 = argument2 < 10;
    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original2445_566;

    goto original2445_2432;
original2445_604:
    temporary3 = Level41_806C8Field(privateState, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    if (temporary3 < 0)
        goto original2445_620;
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, 72);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original2445_648;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_620:
    temporary3 = Level41_806C8Field(privateState, int*, 60);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    if (temporary3 < 0)
        goto original2445_636;
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, 72);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original2445_648;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_636:
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);
    temporary2 = 0 + 4;
    argument0 = owner + 0;
    if (temporary3 != temporary2)
        goto original2445_642;
    temporary2 = 0 + 1;
    Level41_806C8Field(privateState, unsigned char*, 2) = temporary2;
original2445_642:
    argument1 = 0 + 2;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 34;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    Level41_806C8Field(owner, int*, 24) = 0;
    goto original2445Return;
original2445_648:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2)
        goto original2445_660;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 == 0)
        goto original2445_660;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_660:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_666;
    argument1 = 0 + 3;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_666:
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = Level41_806C8UpdateMobyInteractionGate(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level41_806C8StartDialogue(argument0, argument1, argument2);
    temporary2 = 0 + 50;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_677:
    temporary3 = (int)0x80070000U;
    Level41_806C8Keep(temporary3);
    temporary3 = Level41_806C8Field(temporary3, int*, -7356);
    temporary2 = 0 + 1;
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original2445Return;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 48;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_687:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14784);

    saved17 = 0 + 0;
    if (temporary2 != 0)
        goto original2445_784;
    MATCHING_KEEP2_VOLATILE(saved17, temporary2);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 & 1;
    argument2 = 0 + 0;
    if (temporary2 != 0)
        goto original2445_707;
    temporary2 = Level41_806C8_D_8006C58C;

    temporary2 =
        Level41_806C8Field(((int)&Level41_806C8_D_80070300 + temporary2), unsigned char*, 0);

    temporary2 = temporary2 & 1;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(temporary2, "$21");
    saved21 = 0 + 4;
    if (temporary2 == 0)
        goto original2445_785;
original2445_707:
    temporary8 = 0 + 754;
    argument3 = 0 + 2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 67);
    temporary3 = Level41_806C8_D_8006C730;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 + temporary3;
    argument1 = Level41_806C8Field(temporary2, int*, 0);
original2445_715:

    temporary3 = Level41_806C8Field(argument1, unsigned short*, 0);

    temporary3 = temporary3 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    temporary2 = Level41_806C8Field(temporary3, short*, 54);

    if (temporary2 != temporary8)
        goto original2445_743;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary8);
    temporary2 = Level41_806C8Field(temporary3, unsigned char*, 72);

    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 == 0)
        goto original2445_743;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = Level41_806C8Field(temporary3, int*, 0);
    Level41_806C8Field(temporary3, unsigned char*, 72) = argument3;
    Level41_806C8Field(temporary3, unsigned char*, 73) = argument3;
    temporary3 = Level41_806C8Field(temporary3, int*, 20);
    argument0 = Level41_806C8Field(temporary2, unsigned short*, 2);
    Level41_806C8Field(temporary2, short*, 4) = temporary3;
    Level41_806C8Field(temporary2, short*, 0) = argument0;
original2445_743:
    temporary2 = Level41_806C8Field(argument1, short*, 0);

    argument1 = argument1 + 2;
    if (temporary2 < 0)
        goto original2445_751;
    argument2 = argument2 + 1;
    temporary2 = argument2 < 10;
    if (temporary2 != 0)
        goto original2445_715;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_751:
    saved17 = 0 + 0;
    Level41_806C8Keep(saved17);
    saved21 = 0 + 4;
    saved18 = privateState + 0;
    Level41_806C8Keep(saved18);
original2445_754:
    temporary3 = Level41_806C8Field(saved18, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    temporary3 = Level41_806C8Field(saved16, unsigned char*, 72);

    temporary2 = temporary3 & 128;
    if (temporary2 != 0)
        goto original2445_778;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = saved16 + 0;
    if (temporary3 == saved21)
        goto original2445_778;
    argument1 = 0 + 0;
    Level41_806C8Field(saved16, unsigned char*, 72) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary3 = Level41_806C8Field(saved16, int*, 0);
    temporary2 = 0 + 1;
    Level41_806C8Field(saved16, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, int*, 4) = 0;
original2445_778:
    saved17 = saved17 + 1;
    Level41_806C8Keep(saved17);
    temporary2 = saved17 < 2;
    saved18 = saved18 + 4;
    if (temporary2 != 0)
        goto original2445_754;
    argument0 = owner + 0;
    goto original2445_2432;
original2445_784:
    MATCHING_OBSERVE_VOLATILE_CLOBBER(saved17, "$21");
    saved21 = 0 + 4;
original2445_785:
    Level41_806C8Keep(saved17);
    temporary2 = (int)((unsigned int)saved17 << 2);
original2445_786:
    temporary2 = temporary2 + privateState;
    temporary3 = Level41_806C8Field(temporary2, int*, 56);
    argument0 = (int)&Level41_806C8_D_80070328;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    argument1 = saved16 + 12;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    temporary2 = temporary2 < 4500;
    if (temporary2 != 0)
        goto original2445_810;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary3 = Level41_806C8Field(saved16, unsigned char*, 72);

    temporary2 = temporary3 & 128;
    if (temporary2 != 0)
        goto original2445_810;
    MATCHING_KEEP_VOLATILE(temporary2);
    saved17 = saved17 + 1;
    if (temporary3 != saved21)
        goto original2445_843;
original2445_810:
    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner, "$18");
    saved18 = 0 + 0;
    saved17 = privateState + 0;
    Level41_806C8Keep(saved17);
original2445_812:
    temporary3 = Level41_806C8Field(saved17, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    temporary3 = Level41_806C8Field(saved16, unsigned char*, 72);

    temporary2 = temporary3 & 128;
    if (temporary2 != 0)
        goto original2445_837;
    MATCHING_KEEP_VOLATILE(temporary2);
    if (temporary3 == saved21)
        goto original2445_837;
    MATCHING_KEEP_VOLATILE(saved21);
    MATCHING_KEEP_VOLATILE(temporary3);
    argument0 = saved16 + 0;
    argument1 = 0 + 0;
    Level41_806C8Field(saved16, unsigned char*, 72) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary3 = Level41_806C8Field(saved16, int*, 0);
    temporary2 = 0 + 1;
    Level41_806C8Field(saved16, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, int*, 4) = 0;
original2445_837:
    saved18 = saved18 + 1;
    Level41_806C8Keep(saved18);
    temporary2 = saved18 < 2;
    saved17 = saved17 + 4;
    if (temporary2 != 0)
        goto original2445_812;
    temporary2 = 0 + 34;
    goto original2445_932;
original2445_843:
    temporary2 = saved17 < 2;
    if (temporary2 != 0 ? (temporary2 = (int)((unsigned int)saved17 << 2), 1)
                        : (temporary2 = (int)((unsigned int)saved17 << 2), 0))
        goto original2445_786;
    saved17 = 0 + 0;
    Level41_806C8Keep(saved17);
    argument1 = Level41_806C8_D_8006C550;
    argument0 = privateState + 0;
original2445_850:
    temporary3 = Level41_806C8Field(argument0, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = argument1 + temporary2;
    Level41_806C8Keep(saved16);
    temporary2 = Level41_806C8Field(saved16, int*, 0);
    MATCHING_KEEP_VOLATILE_CLOBBER(saved17, "memory");
    saved17 = saved17 + 1;
    Level41_806C8Field(temporary2, int*, 32) = owner;
    temporary2 = saved17 < 2;
    argument0 = argument0 + 4;
    if (temporary2 != 0)
        goto original2445_850;
    argument0 = owner + 0;
    argument1 = 0 + 2;
    MATCHING_KEEP_VOLATILE_CLOBBER(argument1, "$2");
    temporary3 = Level41_806C8Field(privateState, int*, 52);
    temporary2 = 0 + 1;
    Level41_806C8Field(temporary3, short*, 10) = temporary2;
    temporary3 = Level41_806C8Field(privateState, int*, 52);
    temporary2 = 0 + 2;
    Level41_806C8Field(temporary3, short*, 2) = temporary2;
    temporary2 = 0 + 42;
    goto original2445_1688;
original2445_874:
    saved17 = 0 + 0;
    Level41_806C8Keep(saved17);
    saved21 = 0 + 4;
    temporary2 = (int)((unsigned int)saved17 << 2);
original2445_877:
    temporary2 = temporary2 + privateState;
    temporary3 = Level41_806C8Field(temporary2, int*, 56);
    argument0 = (int)&Level41_806C8_D_80070328;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    argument1 = saved16 + 12;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    temporary2 = temporary2 < 4500;
    saved18 = 0 + 0;
    if (temporary2 != 0)
        goto original2445_902;
    Level41_806C8Keep(saved18);
    temporary3 = Level41_806C8Field(saved16, unsigned char*, 72);

    temporary2 = temporary3 & 128;
    if (temporary2 != 0)
        goto original2445_902;
    MATCHING_KEEP_VOLATILE(temporary2);
    saved17 = saved17 + 1;
    if (temporary3 != saved21)
        goto original2445_935;
    saved18 = 0 + 0;
original2445_902:
    saved17 = privateState + 0;
    Level41_806C8Keep(saved17);
original2445_903:
    temporary3 = Level41_806C8Field(saved17, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    temporary3 = Level41_806C8Field(saved16, unsigned char*, 72);

    temporary2 = temporary3 & 128;
    if (temporary2 != 0)
        goto original2445_927;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = saved16 + 0;
    if (temporary3 == saved21)
        goto original2445_927;
    argument1 = 0 + 0;
    Level41_806C8Field(saved16, unsigned char*, 72) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary3 = Level41_806C8Field(saved16, int*, 0);
    temporary2 = 0 + 1;
    Level41_806C8Field(saved16, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, int*, 4) = 0;
original2445_927:
    saved18 = saved18 + 1;
    Level41_806C8Keep(saved18);
    temporary2 = saved18 < 2;
    saved17 = saved17 + 4;
    if (temporary2 != 0)
        goto original2445_903;
    temporary2 = 0 + 34;
original2445_932:
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8Field(owner, int*, 24) = 0;
    goto original2445Return;
original2445_935:
    temporary2 = saved17 < 2;
    if (temporary2 != 0 ? (temporary2 = (int)((unsigned int)saved17 << 2), 1)
                        : (temporary2 = (int)((unsigned int)saved17 << 2), 0))
        goto original2445_877;
    temporary3 = Level41_806C8Field(privateState, int*, 52);

    temporary2 = Level41_806C8Field(temporary3, short*, 2);
    temporary3 = Level41_806C8Field(temporary3, int*, 12);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    argument0 = Level41_806C8Field(saved16, int*, 0);
    temporary2 = Level41_806C8Field(owner, int*, 12);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 112) = argument0;
    argument1 = Level41_806C8Field(saved16, int*, 4);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 116) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 80;
    argument2 = 0 + 0;
    argument3 = 0 + 0;
    MATCHING_KEEP3_CLOBBER(argument1, argument2, argument3, "$2");
    temporary2 = 0 + 4;
    stackArgument4 = temporary2;
    Level41_806C8ResolveMobyYawStep(argument0, argument1, argument2, argument3, stackArgument4);
    argument0 = saved16 + 0;
    argument1 = owner + 12;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    temporary3 = Level41_806C8Field(owner, unsigned char*, 73);

    temporary2 = temporary2 < 4096;
    if (temporary3 != 0)
        goto original2445_999;
    if (temporary2 == 0 ? (temporary2 = 0 + 1, 1) : (temporary2 = 0 + 1, 0))
        goto original2445_999;
    Level41_806C8Field(owner, unsigned char*, 73) = temporary2;
    temporary2 = Level41_806C8Field(privateState, int*, 52);

    temporary2 = Level41_806C8Field(temporary2, short*, 2);

    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = privateState + temporary2;
    temporary3 = Level41_806C8Field(temporary2, int*, 52);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 34;
    Level41_806C8Field(temporary2, unsigned char*, 72) = temporary3;
original2445_999:
    temporary2 = Level41_806C8Field(owner, int*, 24);
    temporary3 = (int)0x00040000U;
    Level41_806C8Keep(temporary3);
    temporary2 = temporary2 & temporary3;
    if (temporary2 == 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original2445Return;
    Level41_806C8Field(owner, int*, 24) = 0;
    argument0 = Level41_806C8Field(privateState, int*, 52);

    temporary3 = Level41_806C8Field(argument0, short*, 2);
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2), "r"(temporary3));
    if (temporary3 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original2445_1012;
    temporary2 = 0 + 1;
original2445_1012:
    Level41_806C8Field(argument0, short*, 2) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 3;
    Level41_806C8SetMobyAnimation(argument0, argument1);
    temporary2 = 0 + 44;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8Field(owner, unsigned char*, 73) = 0;
    goto original2445Return;
original2445_1020:
    temporary3 = Level41_806C8Field(privateState, int*, 52);

    temporary2 = Level41_806C8Field(temporary3, short*, 2);
    temporary3 = Level41_806C8Field(temporary3, int*, 12);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    argument0 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = Level41_806C8Field(owner, int*, 12);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 120) = argument0;
    argument1 = Level41_806C8Field(temporary3, int*, 4);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 124) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 42;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1055:
    argument0 = owner + 0;
    temporary3 = Level41_806C8Field(privateState, int*, 52);
    temporary2 = 0 + 1;
    Level41_806C8Field(temporary3, short*, 10) = temporary2;
    temporary2 = Level41_806C8Field(privateState, int*, 52);
    argument1 = 0 + 2;
    Level41_806C8Field(temporary2, short*, 2) = 0;
    temporary2 = 0 + 33;
    goto original2445_1688;
original2445_1064:
    temporary2 = Level41_806C8UpdateMobyPathMotion(
        owner, Level41_806C8Field(privateState, int*, 52), 120, 80, 0, 6, 2, 0);

    goto original2445Return;
original2445_1077:
    temporary2 = Level41_806C8Field(privateState, int*, 52);

    saved16 = Level41_806C8Field(temporary2, int*, 12);
    temporary2 = Level41_806C8Field(owner, int*, 12);
    argument0 = Level41_806C8Field(saved16, int*, 0);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 128) = argument0;
    argument1 = Level41_806C8Field(saved16, int*, 4);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 132) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    if (temporary2 == 0)
        goto original2445Return;
    Level41_806C8ResolveMobyYawStep(owner, 80, 0, 0, 4);
    argument0 = saved16 + 0;
    argument1 = owner + 12;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    temporary2 = temporary2 < 256;
    if (temporary2 == 0 ? (temporary2 = 0 + 36, 1) : (temporary2 = 0 + 36, 0))
        goto original2445Return;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8Field(privateState, short*, 64) = 0;
    goto original2445Return;
original2445_1116:
    temporary2 = Level41_806C8Field(privateState, int*, 52);

    temporary3 = Level41_806C8Field(temporary2, int*, 12);
    temporary2 = Level41_806C8Field(owner, int*, 12);
    argument0 = Level41_806C8Field(temporary3, int*, 16);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 136) = argument0;
    argument1 = Level41_806C8Field(temporary3, int*, 20);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 140) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1269;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary3 = Level41_806C8Field(privateState, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    if (temporary3 < 0)
        goto original2445_1158;
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, 72);

    temporary2 = temporary2 & 128;
    argument0 = owner + 12;
    if (temporary2 == 0)
        goto original2445_1180;
original2445_1158:
    temporary3 = Level41_806C8Field(privateState, int*, 60);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    if (temporary3 < 0)
        goto original2445_1174;
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, 72);

    temporary2 = temporary2 & 128;
    argument0 = owner + 12;
    if (temporary2 == 0)
        goto original2445_1180;
original2445_1174:
    temporary2 = 0 + 255;
    Level41_806C8Field(owner, unsigned char*, 74) = temporary2;
    temporary2 = 0 + 46;
    Level41_806C8Field(owner, int*, 24) = 0;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1180:
    saved16 = (int)&Level41_806C8_D_80070328;
    Level41_806C8Keep(saved16);
    argument1 = saved16 + 0;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    temporary2 = temporary2 < 7001;
    if (temporary2 != 0)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary3 = Level41_806C8Field(privateState, int*, 56);

    if (temporary3 < 0)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary3);
    argument0 = Level41_806C8Field(privateState, int*, 60);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    if (argument0 < 0)
        goto original2445Return;
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    argument1 = temporary2 + temporary3;
    argument2 = Level41_806C8Field(argument1, unsigned char*, 72);

    temporary2 = argument2 & 128;
    if (temporary2 != 0 ? (temporary2 = (int)((unsigned int)argument0 << 1), 1)
                        : (temporary2 = (int)((unsigned int)argument0 << 1), 0))
        goto original2445Return;
    temporary2 = temporary2 + argument0;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - argument0;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    argument0 = Level41_806C8Field(temporary2, unsigned char*, 72);

    temporary2 = argument0 & 128;
    if (temporary2 != 0 ? (temporary2 = argument2 & 255, 1) : (temporary2 = argument2 & 255, 0))
        goto original2445Return;
    temporary3 = 0 + 4;
    if (temporary2 == temporary3)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    if (argument0 == temporary3 ? (argument0 = saved16 + 0, 1) : (argument0 = saved16 + 0, 0))
        goto original2445Return;
    argument1 = argument1 + 12;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    argument0 = saved16 + 0;
    if (temporary2 == 0)
        goto original2445Return;
    temporary2 = Level41_806C8Field(privateState, int*, 60);
    argument1 = Level41_806C8_D_8006C550;
    temporary3 = (int)((unsigned int)temporary2 << 1);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 2);
    temporary3 = temporary3 - temporary2;
    temporary3 = (int)((unsigned int)temporary3 << 3);
    argument1 = argument1 + temporary3;
    argument1 = argument1 + 12;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    argument1 = 0 + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument2 = 0 + 32;
    argument0 = privateState + 0;
original2445_1241:
    temporary3 = Level41_806C8Field(argument0, int*, 56);
    argument0 = argument0 + 4;
    argument1 = argument1 + 1;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    temporary2 = argument1 < 2;
    Level41_806C8Field(temporary3, unsigned char*, 72) = argument2;
    if (temporary2 != 0)
        goto original2445_1241;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 2;
    MATCHING_KEEP_VOLATILE_CLOBBER(argument1, "$2");
    temporary3 = Level41_806C8Field(privateState, int*, 52);
    temporary2 = 0 + 1;
    Level41_806C8Field(temporary3, short*, 10) = temporary2;
    temporary3 = Level41_806C8Field(privateState, int*, 52);
    temporary2 = 0 + 2;
    Level41_806C8Field(temporary3, short*, 2) = temporary2;
    temporary2 = 0 + 42;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    Level41_806C8Field(owner, int*, 24) = 0;
    Level41_806C8Field(owner, unsigned char*, 73) = 0;
    goto original2445Return;
original2445_1269:
    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner, "$4");
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 2;
    if (temporary3 != temporary2)
        goto original2445Return;
    Level41_806C8ResolveMobyYawStep(owner, 30, 0, 0, 4);

    goto original2445Return;
original2445_1281:
    temporary2 = 0 + 2;
    Level41_806C8Field(privateState, unsigned char*, 5) = temporary2;
    temporary2 = 0 + 5;
    Level41_806C8Field(privateState, unsigned char*, 2) = temporary2;
    temporary2 = 0 + 20;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
original2445_1287:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 7;
    if (temporary3 != temporary2)
        goto original2445_1299;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    argument0 = owner + 0;
    temporary2 = Level41_806C8ReadSelectedFrameScalar(argument0);
    temporary2 = temporary2 < 16;
    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 != 0)
        goto original2445_1299;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_1299:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1305;
    argument1 = 0 + 7;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_1305:
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = Level41_806C8UpdateMobyInteractionGate(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1315;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level41_806C8StartDialogue(argument0, argument1, argument2);
    temporary2 = 0 + 21;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
original2445_1315:
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = Level41_806C8Field(temporary2, unsigned char*, 72);
    temporary2 = 0 + 84;
    MATCHING_OBSERVE2_VOLATILE_CLOBBER(temporary3, temporary2, "$4");
    argument0 = owner + 72;
    if (temporary3 != temporary2)
        goto original2445Return;
    argument1 = 0 + 1;
    Level41_806C8Keep(argument1);
    argument2 = (int)&Level41_806C8_D_8006C7F8;
    Level41_806C8Keep(argument2);
    temporary2 = 0 + 23;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);
    temporary3 = Level41_806C8Field(owner, int*, 0);
    temporary2 = 0 + 2;
    Level41_806C8Field(temporary3, unsigned char*, 5) = temporary2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 70);
    saved16 = (int)&locals.fields.spB0;
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level41_806C8Field(((int)&Level41_806C8_D_80065920 + temporary2), short*, 0);
    argument0 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level41_806C8Field((int)&locals, int*, 144) = temporary2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 70);
    argument1 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level41_806C8Field(((int)&Level41_806C8_D_800658A0 + temporary2), short*, 0);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 876);
    argument2 = owner + 12;
    Level41_806C8Field((int)&locals, volatile int*, 152) = 0;
    Level41_806C8Field((int)&locals, int*, 152) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level41_806C8Field((int)&locals, int*, 148) = temporary2;
    goto original2445_2004;
original2445_1369:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -7356);
    temporary3 = 0 + 1;
    if (temporary2 == temporary3)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    Level41_806C8Field(owner, int*, 24) = 0;
    argument0 = Level41_806C8Field(privateState, unsigned char*, 0);

    temporary2 = 0 + 4;
    if (argument0 != temporary3)
        goto original2445_1413;
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 4);

    if (temporary3 == temporary2)
        goto original2445_1401;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    if (temporary3 != argument0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original2445_1414;
    temporary3 = Level41_806C8Field(privateState, int*, 48);
    argument1 = 0 + 0;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 86;
    Level41_806C8Field(temporary2, unsigned char*, 72) = temporary3;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 66;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1401:
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary3 = 0 + 82;
    Level41_806C8Field(temporary2, unsigned char*, 72) = temporary3;
original2445_1413:
    argument0 = owner + 0;
original2445_1414:
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 20;
    goto original2445_1470;
original2445_1418:
    argument2 = 0 + 0;
    temporary3 = Level41_806C8Field(privateState, int*, 48);
    saved16 = Level41_806C8_D_8006C550;
    argument0 = Level41_806C8Field(owner, int*, 12);
    argument1 = Level41_806C8Field(owner, int*, 16);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = saved16 + temporary2;
    Level41_806C8Keep(saved16);
    temporary3 = Level41_806C8Field(saved16, int*, 12);
    temporary2 = Level41_806C8Field(saved16, int*, 16);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = saved16 + 12;
    argument1 = temporary2 + 0;
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 17200);

    argument2 = 0 + 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2);
    saved16 = owner + 72;
    if (temporary2 == 0)
        goto original2445Return;
    argument0 = saved16 + 0;
    argument1 = 0 + 1;
    Level41_806C8Keep(argument1);
    argument2 = (int)&Level41_806C8_D_8006D088;
    Level41_806C8Keep(argument2);
    temporary2 = 0 + 24;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    argument2 = (int)&Level41_806C8_D_8006C7F8;
    Level41_806C8Keep(argument2);
    argument1 = 0 + 1;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    Level41_806C8Field(temporary2, unsigned char*, 72) = 0;
    temporary2 = 0 + 255;
    Level41_806C8Field(owner, unsigned char*, 74) = temporary2;
    temporary2 = 0 + 20;
original2445_1470:
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1472:
    argument3 = 0 + 0;
    temporary9 = 0 + 754;
    temporary8 = 0 + 2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 67);
    temporary3 = Level41_806C8_D_8006C730;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 + temporary3;
    argument2 = Level41_806C8Field(temporary2, int*, 0);
original2445_1481:

    temporary3 = Level41_806C8Field(argument2, unsigned short*, 0);

    temporary3 = temporary3 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    argument1 = temporary3 + temporary2;
    Level41_806C8Keep(argument1);
    temporary2 = Level41_806C8Field(argument1, short*, 54);

    if (temporary2 != temporary9)
        goto original2445_1513;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary9);
    temporary2 = Level41_806C8Field(argument1, unsigned char*, 72);

    temporary2 = (unsigned int)temporary2 < 6;
    if (temporary2 == 0)
        goto original2445_1513;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = Level41_806C8Field(argument1, int*, 0);
    Level41_806C8Field(argument1, unsigned char*, 65) = 0;
    Level41_806C8Field(argument1, unsigned char*, 76) = 0;
    Level41_806C8Field(argument1, unsigned char*, 77) = 0;
    Level41_806C8Field(argument1, int*, 8) = 0;
    Level41_806C8Field(argument1, unsigned char*, 72) = temporary8;
    Level41_806C8Field(argument1, unsigned char*, 73) = temporary8;
    temporary3 = Level41_806C8Field(temporary2, unsigned short*, 2);
    argument0 = Level41_806C8Field(temporary2, short*, 4);
    Level41_806C8Field(temporary2, short*, 0) = temporary3;
    Level41_806C8Field(argument1, int*, 20) = argument0;
original2445_1513:
    temporary2 = Level41_806C8Field(argument2, short*, 0);

    argument2 = argument2 + 2;
    if (temporary2 < 0)
        goto original2445_1521;
    argument3 = argument3 + 1;
    temporary2 = argument3 < 10;
    if (temporary2 != 0)
        goto original2445_1481;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_1521:
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2)
        goto original2445_1557;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    saved18 = 0 + 0;
    saved21 = 0 + 4;
    saved17 = privateState + 0;
    Level41_806C8Keep(saved17);
original2445_1528:
    temporary3 = Level41_806C8Field(saved17, int*, 56);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    if (temporary3 < 0)
        goto original2445_1553;
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    saved16 = temporary3 + temporary2;
    Level41_806C8Keep(saved16);
    temporary3 = Level41_806C8Field(saved16, unsigned char*, 72);

    temporary2 = temporary3 & 128;
    if (temporary2 != 0)
        goto original2445_1553;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = saved16 + 0;
    if (temporary3 == saved21)
        goto original2445_1553;
    argument1 = 0 + 0;
    Level41_806C8Field(saved16, unsigned char*, 72) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary3 = Level41_806C8Field(saved16, int*, 0);
    temporary2 = 0 + 1;
    Level41_806C8Field(saved16, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, int*, 4) = 0;
original2445_1553:
    saved18 = saved18 + 1;
    Level41_806C8Keep(saved18);
    temporary2 = saved18 < 2;
    saved17 = saved17 + 4;
    if (temporary2 != 0)
        goto original2445_1528;
original2445_1557:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 72);
    temporary2 = 0 + 80;
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original2445_2432;
original2445_1561:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 72);
    temporary2 = 0 + 76;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 82, 1) : (temporary2 = 0 + 82, 0))
        goto original2445_1567;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original2445_1591;
original2445_1567:
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    argument0 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = 0 + 128;
    Level41_806C8Field(argument0, int*, 8) = temporary2;
    argument0 = Level41_806C8Field(temporary3, int*, 0);
    temporary2 = 0 + 60;
    Level41_806C8Field(argument0, int*, 12) = temporary2;
    temporary2 = 0 + 1;
    Level41_806C8Field(temporary3, unsigned char*, 73) = temporary2;
    Level41_806C8Field(temporary3, unsigned char*, 72) = temporary2;
    temporary3 = Level41_806C8Field(owner, unsigned char*, 72);
    temporary2 = 0 + 82;
    if (temporary3 == temporary2)
        goto original2445_2431;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    MATCHING_KEEP_VOLATILE(argument0);
original2445_1590:
    temporary2 = 0 + 2;
original2445_1591:
    Level41_806C8Field(privateState, unsigned char*, 2) = temporary2;
    temporary2 = 0 + 68;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
original2445_1594:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2)
        goto original2445_1606;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 == 0)
        goto original2445_1606;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_1606:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1612;
    argument1 = 0 + 3;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_1612:
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = Level41_806C8UpdateMobyInteractionGate(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level41_806C8StartDialogue(argument0, argument1, argument2);
    temporary2 = 0 + 70;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1623:
    temporary3 = (int)0x80070000U;
    Level41_806C8Keep(temporary3);
    temporary3 = Level41_806C8Field(temporary3, int*, -7356);
    temporary2 = 0 + 1;
    if (temporary3 == temporary2)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);

    temporary2 = temporary3 + -3;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 != 0 ? (temporary2 = 0 + 80, 1) : (temporary2 = 0 + 80, 0))
        goto original2445_1641;
    temporary3 = temporary3 & 255;
    temporary2 = 0 + 5;
    if (temporary3 != temporary2)
        goto original2445_1640;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = 0 + 82;
    goto original2445_1641;
original2445_1640:
    temporary2 = 0 + 72;
original2445_1641:
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    argument0 = owner + 72;
    argument2 = (int)&Level41_806C8_D_8006C7F8;
    Level41_806C8Keep(argument2);
    argument1 = 0 + 1;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 68;
    goto original2445_1687;
original2445_1651:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 7;
    if (temporary3 != temporary2)
        goto original2445_1663;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    argument0 = owner + 0;
    temporary2 = Level41_806C8ReadSelectedFrameScalar(argument0);
    temporary2 = temporary2 < 16;
    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 != 0)
        goto original2445_1663;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_1663:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1669;
    argument1 = 0 + 7;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_1669:
    argument0 = owner + 0;
    argument1 = 0 + 0;
    temporary2 = Level41_806C8UpdateMobyInteractionGate(argument0, argument1);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level41_806C8StartDialogue(argument0, argument1, argument2);
    temporary2 = 0 + 26;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1680:
    temporary3 = (int)0x80070000U;
    Level41_806C8Keep(temporary3);
    temporary3 = Level41_806C8Field(temporary3, int*, -7356);
    temporary2 = 0 + 1;
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original2445Return;
    argument1 = 0 + 0;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 25;
original2445_1687:
    Level41_806C8Field(argument0, int*, 24) = 0;
original2445_1688:
    Level41_806C8Field(argument0, unsigned char*, 72) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);

    goto original2445Return;
original2445_1692:
    temporary2 = Level41_806C8Field(privateState, unsigned char*, 0);

    temporary2 = temporary2 + -3;
    temporary2 = (unsigned int)temporary2 < 2;
    saved16 = 0 + 0;
    if (temporary2 == 0)
        goto original2445_1727;
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 & 1;
    if (temporary2 != 0 ? (temporary2 = 0 + 78, 1) : (temporary2 = 0 + 78, 0))
        goto original2445_1713;
    temporary2 = Level41_806C8_D_8006C58C;

    temporary2 =
        Level41_806C8Field(((int)&Level41_806C8_D_80070300 + temporary2), unsigned char*, 0);

    temporary2 = temporary2 & 1;
    if (temporary2 == 0 ? (temporary2 = 0 + 78, 1) : (temporary2 = 0 + 78, 0))
        goto original2445_1727;
original2445_1713:
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    saved16 = owner + 72;
    Level41_806C8Keep(saved16);
    argument0 = saved16 + 0;
    argument2 = (int)&Level41_806C8_D_8006D088;
    Level41_806C8Keep(argument2);
    argument1 = 0 + 1;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    argument2 = (int)&Level41_806C8_D_8006C7F8;
    Level41_806C8Keep(argument2);
    argument1 = 0 + 1;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);

    goto original2445Return;
original2445_1727:
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);
    temporary2 = 0 + 5;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original2445_1790;
    temporary2 = Level41_806C8Field(privateState, int*, 72);

    if (temporary2 != 0)
        goto original2445_1742;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = Level41_806C8_D_8006C58C;
    Level41_806C8Keep(temporary2);
    temporary3 = (int)&Level41_806C8_main_TEXT_START + 2;
    temporary2 = temporary2 + temporary3;
    Level41_806C8Field(privateState, int*, 72) = temporary2;
    temporary2 = Level41_806C8Field(privateState, volatile int*, 72);
original2445_1742:
    temporary3 = (int)&Level41_806C8_main_TEXT_END;
    Level41_806C8Keep(temporary3);
    temporary2 = (unsigned int)temporary2 < (unsigned int)temporary3;
    if (temporary2 == 0)
        goto original2445_1788;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument1 = 0 + 0;
    argument2 = temporary3 + 0;
original2445_1749:
    temporary3 = Level41_806C8Field(privateState, int*, 72);

    temporary2 = (unsigned int)temporary3 < (unsigned int)argument2;
    if (temporary2 == 0)
        goto original2445_1785;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = 0 + 0;
    temporary2 = Level41_806C8Field(temporary3, unsigned char*, 0);
    temporary3 = Level41_806C8Field(privateState, int*, 68);
    temporary2 = (int)((unsigned int)temporary2 << 8);
    temporary3 = temporary3 ^ temporary2;
    Level41_806C8Field(privateState, int*, 68) = temporary3;
original2445_1760:
    temporary3 = Level41_806C8Field(privateState, int*, 68);

    temporary2 = temporary3 & 32768;
    if (temporary2) {
        temporary2 = (int)((unsigned int)temporary3 << 1);
        temporary2 ^= 32773;
    } else
        temporary2 = (int)((unsigned int)temporary3 << 1);
original2445_1766:
    Level41_806C8Field(privateState, int*, 68) = temporary2;
    argument0 = argument0 + 1;
    temporary2 = argument0 < 8;
    if (temporary2 != 0)
        goto original2445_1760;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument1 = argument1 + 1;
    temporary2 = Level41_806C8Field(privateState, int*, 68);
    temporary3 = Level41_806C8Field(privateState, int*, 72);
    temporary2 = temporary2 & 3;
    temporary2 = temporary2 + 1;
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    temporary2 = argument1 < 64;
    Level41_806C8Field(privateState, int*, 72) = temporary3;
    if (temporary2 != 0)
        goto original2445_1749;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = (int)&Level41_806C8_main_TEXT_END;
    Level41_806C8Keep(temporary2);
    temporary2 = (unsigned int)temporary3 < (unsigned int)temporary2;
    if (temporary2 != 0)
        goto original2445_1788;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_1785:
    temporary2 = (int)&Level41_806C8_func_level_41_80075544;
    Level41_806C8Keep(temporary2);
    Level41_806C8Field(privateState, int*, 72) = temporary2;
original2445_1788:
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);
    temporary2 = 0 + 2;
original2445_1790:
    if (temporary3 == temporary2)
        goto original2445_1794;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    if (temporary3 != 0)
        goto original2445_1814;
    MATCHING_KEEP_VOLATILE(temporary3);
original2445_1794:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14784);

    if (temporary2 != 0)
        goto original2445_1814;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 & 1;
    if (temporary2 != 0)
        goto original2445_2431;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = Level41_806C8_D_8006C58C;

    temporary2 =
        Level41_806C8Field(((int)&Level41_806C8_D_80070300 + temporary2), unsigned char*, 0);

    temporary2 = temporary2 & 1;
    if (temporary2 != 0)
        goto original2445_2431;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_1814:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2)
        goto original2445_1826;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 == 0)
        goto original2445_1826;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_1826:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1832;
    argument1 = 0 + 3;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_1832:
    temporary2 = (int)0x00FF0000U;
    Level41_806C8Keep(temporary2);
    temporary3 = Level41_806C8Field(privateState, int*, 0);
    temporary2 = temporary2 | 255;
    temporary3 = temporary3 & temporary2;
    temporary2 = 0 + 2;
    argument1 = owner + 12;
    if (temporary3 != temporary2)
        goto original2445_1879;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 70);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level41_806C8Field(((int)&Level41_806C8_D_80065920 + temporary2), short*, 0);
    argument0 = (int)&locals.fields.spC0;
    Level41_806C8Keep(argument0);
    Level41_806C8Field((int)&locals, int*, 160) = temporary2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 70);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level41_806C8Field(((int)&Level41_806C8_D_800658A0 + temporary2), short*, 0);
    argument2 = argument0 + 0;
    Level41_806C8Field((int)&locals, int*, 168) = 0;
    Level41_806C8Field((int)&locals, int*, 164) = temporary2;
    Level41_806C8AddVector(argument0, argument1, argument2);
    argument2 = 0 + 0;
    temporary3 = Level41_806C8_D_80070328;
    argument0 = Level41_806C8Field((int)&locals, volatile int*, 160);
    temporary2 = Level41_806C8Field((int)&Level41_806C8_D_80070328, int*, 4);
    argument1 = Level41_806C8Field((int)&locals, volatile int*, 164);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument1 = Level41_806C8Field(owner, unsigned char*, 70);
    argument0 = temporary2 + 0;
    temporary2 = Level41_806C8AbsoluteByteAngleDelta(argument0, argument1);
    temporary2 = temporary2 < 65;
    if (temporary2 != 0)
        goto original2445_1879;
    MATCHING_KEEP_VOLATILE(temporary2);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 992);

    if (temporary2 != 0)
        goto original2445_1879;
    MATCHING_KEEP_VOLATILE(temporary2);
    saved16 = 0 + 1;
original2445_1879:
    argument0 = owner + 0;
    if (saved16 != 0)
        goto original2445_1885;
    Level41_806C8Keep(saved16);
    argument1 = 0 + 0;
    temporary2 = Level41_806C8UpdateMobyInteractionGate(argument0, argument1);
    if (temporary2 == 0)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_1885:
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);
    temporary2 = 0 + 2;
    argument0 = owner + 0;
    if (temporary3 != temporary2)
        goto original2445_1895;
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 | 1;

    Level41_806C8Field((int)&Level41_806C8_D_8006C7B4, unsigned char*, 0) = temporary2;
original2445_1895:
    argument1 = 0 + 0;
    argument2 = 0 + 1;
    Level41_806C8StartDialogue(argument0, argument1, argument2);
    temporary2 = 0 + 1;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1901:
    temporary3 = (int)0x80070000U;
    Level41_806C8Keep(temporary3);
    temporary3 = Level41_806C8Field(temporary3, int*, -7356);
    temporary2 = 0 + 1;
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original2445Return;
    argument1 = 0 + 0;
    Level41_806C8Field(owner, int*, 24) = 0;
    Level41_806C8Field(owner, unsigned char*, 72) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary3 = Level41_806C8Field(privateState, unsigned char*, 0);
    temporary2 = 0 + 2;
    if (temporary3 != temporary2)
        goto original2445_1920;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = Level41_806C8Field(privateState, unsigned char*, 4);

    if (temporary2 != 0 ? (temporary2 = 0 + 28, 1) : (temporary2 = 0 + 28, 0))
        goto original2445_1920;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_1920:
    temporary2 = Level41_806C8Field(privateState, unsigned char*, 0);

    temporary2 = temporary2 + -3;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 == 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original2445Return;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 4;
    Level41_806C8RequestMobyAnimation(argument0, argument1);

    goto original2445Return;
original2445_1932:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 7;
    if (temporary3 != temporary2)
        goto original2445_1944;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    argument0 = owner + 0;
    temporary2 = Level41_806C8ReadSelectedFrameScalar(argument0);
    temporary2 = temporary2 < 16;
    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 != 0)
        goto original2445_1944;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_1944:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_1950;
    argument1 = 0 + 7;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_1950:
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, 72);

    temporary2 = temporary2 & 128;
    argument0 = owner + 72;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 1;
    Level41_806C8Keep(argument1);
    argument2 = (int)&Level41_806C8_D_8006C7F8;
    Level41_806C8Keep(argument2);
    temporary2 = 0 + 23;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    Level41_806C8RegisterTrackedValue(argument0, argument1, argument2);
    temporary3 = Level41_806C8Field(owner, int*, 0);
    temporary2 = 0 + 2;
    Level41_806C8Field(temporary3, unsigned char*, 5) = temporary2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 70);
    saved16 = (int)&locals.fields.spD0;
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level41_806C8Field(((int)&Level41_806C8_D_80065920 + temporary2), short*, 0);
    argument0 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level41_806C8Field((int)&locals, int*, 176) = temporary2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 70);
    argument1 = saved16 + 0;
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary3 = Level41_806C8Field(((int)&Level41_806C8_D_800658A0 + temporary2), short*, 0);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 876);
    argument2 = owner + 12;
    Level41_806C8Field((int)&locals, volatile int*, 184) = 0;
    Level41_806C8Field((int)&locals, int*, 184) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 2);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 - temporary3;
    temporary2 = (temporary2 >> 6);
    Level41_806C8Field((int)&locals, int*, 180) = temporary2;
original2445_2004:

    Level41_806C8AddVector(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    argument2 = 0 + 0;
    argument1 = Level41_806C8Field(owner, unsigned char*, 70);
    argument3 = 0 + 85;
    argument1 = argument1 + 128;
    argument1 = argument1 & 255;
    Level41_806C8SetCameraMode11Target(argument0, argument1, argument2, argument3);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 1448);

    if (temporary2 >= 0)
        goto original2445_2020;
    MATCHING_KEEP_VOLATILE(temporary2);

    Level41_806C8Field((int)&Level41_806C8_D_80070328 + 640, int*, 0) = 0;
original2445_2020:
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, unsigned char*, -14412);

    temporary2 = temporary2 | 4;

    Level41_806C8Field((int)&Level41_806C8_D_8006C7B4, unsigned char*, 0) = temporary2;
    temporary2 = 0 + 25;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_2029:
    temporary3 = Level41_806C8Field(privateState, int*, 48);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    argument0 = Level41_806C8Field(temporary3, int*, 12);
    temporary2 = Level41_806C8Field(owner, int*, 12);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 224) = argument0;
    argument1 = Level41_806C8Field(temporary3, int*, 16);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 228) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    argument0 = owner + 0;
    argument1 = 0 + 5;
    Level41_806C8RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP2(argument0, argument1);
    saved17 = (int)&locals.fields.spF0;
    Level41_806C8Keep(saved17);
    argument2 = saved17 + 0;
    Level41_806C8InterpolateMobyVertex(argument0, argument1, argument2);
    saved18 = (int)&locals.fields.spE0;
    Level41_806C8Keep(saved18);
    argument0 = saved18 + 0;
    saved16 = owner + 12;
    Level41_806C8Keep(saved16);
    argument1 = saved16 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved16 + 0;
    argument1 = saved17 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    temporary2 = (int)Level41_806C8_SpawnParticle;

    argument3 = 0 + 2;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    argument0 = saved16 + 0;
    argument1 = saved18 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    argument1 = 0 + 0;
    if (temporary2 == 0)
        goto original2445Return;
    temporary8 = 0 + 754;
    argument3 = 0 + 1;
    argument2 = 0 + 2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 67);
    temporary3 = Level41_806C8_D_8006C730;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 + temporary3;
    argument0 = Level41_806C8Field(temporary2, int*, 0);
original2445_2099:

    temporary3 = Level41_806C8Field(argument0, unsigned short*, 0);

    temporary3 = temporary3 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    temporary2 = Level41_806C8Field(temporary3, short*, 54);

    if (temporary2 != temporary8)
        goto original2445_2120;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary8);
    temporary2 = Level41_806C8Field(temporary3, unsigned char*, 72);

    if (temporary2 != argument3)
        goto original2445_2120;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(argument3);
    Level41_806C8Field(temporary3, unsigned char*, 72) = argument2;
original2445_2120:
    temporary2 = Level41_806C8Field(argument0, short*, 0);

    argument0 = argument0 + 2;
    if (temporary2 < 0)
        goto original2445_2128;
    argument1 = argument1 + 1;
    temporary2 = argument1 < 10;
    if (temporary2 != 0)
        goto original2445_2099;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_2128:
    argument0 = owner + 0;
    argument1 = 0 + 5;
    MATCHING_KEEP_CLOBBER(argument1, "$2");
    temporary2 = 0 + 5;
    Level41_806C8Field(argument0, unsigned char*, 72) = temporary2;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 600;
    Level41_806C8Field(privateState, short*, 64) = temporary2;
    goto original2445Return;
original2445_2136:
    argument0 = owner + 0;
    argument1 = 0 + 5;
    Level41_806C8RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP2(argument0, argument1);
    saved22 = (int)&locals.fields.sp118;
    Level41_806C8Keep(saved22);
    argument2 = saved22 + 0;
    Level41_806C8InterpolateMobyVertex(argument0, argument1, argument2);
    saved17 = (int)&locals.fields.sp108;
    Level41_806C8Keep(saved17);
    argument0 = saved17 + 0;
    saved16 = owner + 12;
    Level41_806C8Keep(saved16);
    argument1 = saved16 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved16 + 0;
    argument1 = saved22 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    temporary2 = (int)Level41_806C8_SpawnParticle;

    argument3 = 0 + 2;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    argument0 = saved16 + 0;
    argument1 = saved17 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = (short)Level41_806C8Field(privateState, unsigned short*, 64);
    argument0 = argument0 % 10;
    argument0 = (int)((unsigned int)argument0 << 16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argument0, "$17");
    saved17 = 0 + 0;
    if (argument0 != 0)
        goto original2445_2187;
    argument0 = 0 + 754;
    Level41_806C8Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, 17120);
    Level41_806C8Keep(temporary2);

    argument1 = owner + 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved17 = temporary2 + 0;
    Level41_806C8Keep(saved17);
original2445_2187:
    saved18 = 0 + 0;
    if (saved17 == 0)
        goto original2445_2313;
    argument0 = owner + 0;
    argument1 = 0 + 0;
    saved21 = Level41_806C8Field(saved17, int*, 0);
    argument2 = 0 + 0;
    Level41_806C8PlayMobySoundEvent(argument0, argument1, argument2);
    saved16 = saved17 + 12;
    Level41_806C8Keep(saved16);
    argument0 = saved16 + 0;
    argument1 = saved22 + 0;
    Level41_806C8Field(saved17, unsigned char*, 65) = 0;
    Level41_806C8Field(saved17, unsigned char*, 76) = 0;
    Level41_806C8Field(saved17, unsigned char*, 77) = 0;
    Level41_806C8Field(saved17, int*, 8) = 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved16 + 0;
    argument1 = 0 + 8;
    argument2 = 0 + 10;
    MATCHING_KEEP2_VOLATILE_CLOBBER(argument1, argument2, "$7");
    argument3 = (int)0x00C00000U;
    Level41_806C8Keep(argument3);
    argument3 = argument3 | 24736;
    temporary2 = 0 + 6;
    Level41_806C8Field(saved17, unsigned char*, 72) = temporary2;
    temporary2 = 0 + 120;
    Level41_806C8Field(saved21, short*, 0) = temporary2;
    temporary2 = Level41_806C8AllocateVectorTrailRecord(argument0, argument1, argument2, argument3);
    argument2 = 0 + 0;
    temporary8 = 0 + 754;
    argument3 = Level41_806C8_D_8006C550;
    argument1 = (int)&locals.fields.sp20;
    Level41_806C8Field(saved21, int*, 8) = temporary2;
    temporary2 = Level41_806C8Field(owner, unsigned char*, 67);
    temporary3 = Level41_806C8_D_8006C730;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 + temporary3;
    argument0 = Level41_806C8Field(temporary2, int*, 0);
original2445_2224:

    temporary2 = Level41_806C8Field(argument0, unsigned short*, 0);

    temporary3 = temporary2 & 32767;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = argument3 + temporary2;
    temporary2 = Level41_806C8Field(temporary2, short*, 54);

    if (temporary2 != temporary8)
        goto original2445_2241;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary8);
    Level41_806C8Field(argument1, int*, 264) = temporary3;
    argument1 = argument1 + 4;
    saved18 = saved18 + 1;
    Level41_806C8Keep(saved18);
original2445_2241:
    temporary2 = Level41_806C8Field(argument0, short*, 0);

    argument0 = argument0 + 2;
    if (temporary2 < 0)
        goto original2445_2249;
    argument2 = argument2 + 1;
    temporary2 = argument2 < 10;
    if (temporary2 != 0)
        goto original2445_2224;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_2249:
    temporary2 = Level41_806C8Field(privateState, short*, 64);

    temporary3 = temporary2 % saved18;
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    argument3 = 0 + 2;
    temporary3 = locals.selection.indexed[temporary3 + 9];
    temporary8 = (int)Level41_806C8_SpawnParticle;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level41_806C8_D_8006C550;
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary3 = temporary3 + temporary2;
    Level41_806C8Keep(temporary3);
    Level41_806C8Field(saved21, int*, 12) = temporary3;
    temporary2 = ((int (*)())temporary8)(argument0, argument1, argument2, argument3);
    temporary3 = temporary2 + 0;
    Level41_806C8Field(saved21, int*, 16) = temporary3;
    if (temporary3 == 0)
        goto original2445_2286;
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = 0 + 120;
    Level41_806C8Field(temporary3, unsigned char*, 10) = temporary2;
original2445_2286:
    saved16 = (int)&locals.fields.sp118;
    Level41_806C8Keep(saved16);
    argument1 = Level41_806C8Field(saved21, int*, 12);
    argument0 = saved16 + 0;
    argument1 = argument1 + 12;
    Level41_806C8CopyVector(argument0, argument1);
    argument2 = 0 + 0;
    temporary2 = Level41_806C8Field((int)&locals, volatile int*, 256);
    temporary3 = Level41_806C8Field((int)&locals, volatile int*, 248);
    temporary2 = temporary2 + 512;
    Level41_806C8Field((int)&locals, int*, 256) = temporary2;
    argument0 = Level41_806C8Field(saved17, int*, 12);
    temporary2 = Level41_806C8Field((int)&locals, volatile int*, 252);
    argument1 = Level41_806C8Field(saved17, int*, 16);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = saved17 + 12;
    argument1 = saved16 + 0;
    Level41_806C8Field(saved17, unsigned char*, 70) = temporary2;
    temporary2 = Level41_806C8ApproximatePlanarDistance(argument0, argument1);
    argument0 = temporary2 + 0;
    temporary2 = Level41_806C8Field((int)&locals, volatile int*, 256);
    argument1 = Level41_806C8Field(saved17, int*, 20);
    argument2 = 0 + 0;
    argument1 = temporary2 - argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    Level41_806C8Field(saved17, unsigned char*, 69) = temporary2;
original2445_2313:
    argument0 = privateState + 64;
    argument1 = 0 + 2;
    temporary2 = Level41_806C8CountTimerDown(argument0, argument1);
    if (temporary2 == 0 ? (temporary2 = 0 + 6, 1) : (temporary2 = 0 + 6, 0))
        goto original2445Return;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 6;
    Level41_806C8RequestMobyAnimation(argument0, argument1);

    goto original2445Return;
original2445_2324:
    argument0 = owner + 0;
    argument1 = 0 + 5;
    Level41_806C8RefreshMobySpatialGridAndBasis(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    MATCHING_KEEP2(argument0, argument1);
    saved17 = (int)&locals.fields.sp140;
    Level41_806C8Keep(saved17);
    argument2 = saved17 + 0;
    Level41_806C8InterpolateMobyVertex(argument0, argument1, argument2);
    saved18 = (int)&locals.fields.sp128;
    Level41_806C8Keep(saved18);
    argument0 = saved18 + 0;
    saved16 = owner + 12;
    Level41_806C8Keep(saved16);
    argument1 = saved16 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = saved16 + 0;
    argument1 = saved17 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 12;
    MATCHING_KEEP2(argument0, argument1);
    argument2 = owner + 0;
    temporary2 = (int)Level41_806C8_SpawnParticle;

    argument3 = 0 + 2;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    argument0 = saved16 + 0;
    argument1 = saved18 + 0;
    Level41_806C8CopyVector(argument0, argument1);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445Return;
    argument1 = 0 + 0;
    Level41_806C8Field(privateState, short*, 64) = 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    temporary2 = 0 + 36;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_2362:
    temporary3 = Level41_806C8Field(owner, unsigned char*, 61);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2)
        goto original2445_2374;
    MATCHING_KEEP_VOLATILE(temporary2);
    MATCHING_KEEP_VOLATILE(temporary3);
    temporary2 = (int)0x80070000U;
    Level41_806C8Keep(temporary2);
    temporary2 = Level41_806C8Field(temporary2, int*, -14480);

    Level41_806C8Field(owner, int*, 24) = 0;
    if (temporary2 == 0)
        goto original2445_2374;
    MATCHING_KEEP_VOLATILE(temporary2);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
original2445_2374:
    temporary2 = Level41_806C8Field(owner, int*, 24);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original2445_2380;
    argument1 = 0 + 3;
    Level41_806C8SetMobyAnimation(argument0, argument1);
original2445_2380:
    argument0 = privateState + 64;
    argument1 = 0 + 2;
    temporary2 = Level41_806C8CountTimerDown(argument0, argument1);
    if (temporary2 == 0)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
    Level41_806C8Field(owner, unsigned char*, 72) = 0;
    goto original2445Return;
original2445_2387:
    temporary2 = Level41_806C8Field(privateState, int*, 52);

    temporary3 = Level41_806C8Field(temporary2, int*, 12);
    temporary2 = Level41_806C8Field(owner, int*, 12);
    argument0 = Level41_806C8Field(temporary3, int*, 0);

    argument0 = argument0 - temporary2;
    Level41_806C8Field((int)&locals, int*, 304) = argument0;
    argument1 = Level41_806C8Field(temporary3, int*, 4);
    temporary2 = Level41_806C8Field(owner, int*, 16);
    argument2 = 0 + 0;
    argument1 = argument1 - temporary2;
    Level41_806C8Field((int)&locals, int*, 308) = argument1;
    temporary2 = Level41_806C8PlanarHeadingLookup(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 2;
    MATCHING_KEEP2(argument0, argument1);
    saved16 = temporary2 + 0;
    Level41_806C8RequestMobyAnimation(argument0, argument1);
    argument0 = owner + 0;
    argument1 = saved16 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 3;
    MATCHING_KEEP2_CLOBBER(argument2, argument3, "$2");
    temporary2 = 0 + 1;
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level41_806C8TurnMobyTowardHeading(argument0, argument1, argument2, argument3,
                                                    stackArgument4, stackArgument5);
    if (temporary2 == 0 ? (temporary2 = 0 + 30, 1) : (temporary2 = 0 + 30, 0))
        goto original2445Return;
    Level41_806C8Field(owner, unsigned char*, 72) = temporary2;
    goto original2445Return;
original2445_2417:
    temporary2 = Level41_806C8UpdateMobyPathMotion(
        owner, Level41_806C8Field(privateState, int*, 52), 120, 80, 0, 6, 2, 0);
    temporary2 = temporary2 & 2;
    if (temporary2 == 0)
        goto original2445Return;
    MATCHING_KEEP_VOLATILE(temporary2);
original2445_2431:
    argument0 = owner + 0;
original2445_2432:

    Level41_806C8DeleteMoby(argument0);
original2445Return:
    Level41_806C8Keep(owner);
    Level41_806C8Keep(privateState);
    return;
}
#undef Level41_806C8Field
#undef Level41_806C8Keep

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80082CFC.
* AI generated; not human reviewed. All1080 instructions and22 selectors,
* 1102 owned original words, require every native/linked word and actual
* transfer/table destination. Frame100 saves S0..S7/FP/RA,SP28..D7 locals.
* Original shared state helper607,reset817,height helper1054 and independent
* owner-position entries remain in original physical order. Original847
* enters900 directly; later entries reload896 and produce their own899
* complete owner argument. Original vector and constructor paths retain
* independent complete owner inputs at848/884/899 and exact delay slots.
* Two whole75/shift10 vectors preserve signed sample/zero-store order.
* Signed halfword store precedes narrowing and the original -450 clamp.
* Complete loop pointer/count/sentinel producers,independent halfword
* selections,angle inputs and post-helper maximum comparisons remain exact.
* An ordinary initialized qualified-distance scalar allocates naturally
* to FP;no fixedFP. Saved address/angle/distance/loop phases are disjoint.
* Empty metadata consumes complete initialized values/addresses or has
* outputs/clobbers dead before complete producers;zero CPU instructions.
* No partialHI,undefined saved inputs,live alias overlap or pipeline changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence: binary identity only
* after every gate. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned selectors and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 7091fc3388b24c28627c3e3299bfc68bfac3dbb8bca7000d586df5b002c12c60 */
#define Level41_82CFCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level41_82CFCQueryWorldHeightView1() __asm__("func_8001A358");
int Level41_82CFCQueryDynamicMobyGeometryView1() __asm__("func_8001BA30");
int Level41_82CFCAllocatePoolRecord16View1() __asm__("func_8002F040");
void Level41_82CFCRequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level41_82CFCSetMobyAnimationView1() __asm__("func_80034F80");
int Level41_82CFCUpdateMobyMotionDescriptorView1() __asm__("func_80035194");
int Level41_82CFCTurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level41_82CFCTurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level41_82CFCCountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level41_82CFCResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level41_82CFCRandBetweenView1() __asm__("func_8003636C");
int Level41_82CFCEmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level41_82CFCSpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
int Level41_82CFCInitializeMobyMotionStateWithDecelerationView1() __asm__("func_80038F14");
int Level41_82CFCMarkMobyCollectionBitView1() __asm__("func_8003BA00");
int Level41_82CFCPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level41_82CFCCopyVectorView1() __asm__("func_8004F178");
int Level41_82CFCAddVectorView1() __asm__("func_8004F194");
int Level41_82CFCAbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level41_82CFCApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level41_82CFCDeleteMobyView1() __asm__("func_80055B18");
int Level41_82CFCRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level41_82CFCReadSelectedFrameScalarView1() __asm__("func_80055E84");
int Level41_82CFCInterpolateMobyVertexView1() __asm__("func_80055F14");
int Level41_82CFCRefreshMobyPackedQueryFieldView1() __asm__("func_8005629C");
int Level41_82CFCDatarandView1(void) __asm__("rand");
extern int Level41_82CFCData658A0View1 __asm__("D_800658A0");
extern int Level41_82CFCData65920View1 __asm__("D_80065920");
extern int Level41_82CFCData676E8View1 __asm__("D_800676E8");
extern int Level41_82CFCData6C550View1 __asm__("D_8006C550");
extern int Level41_82CFCData6C58CView1 __asm__("D_8006C58C");
extern int Level41_82CFCData6C5C8View1 __asm__("D_8006C5C8");
extern int Level41_82CFCData6C648View1 __asm__("D_8006C648");
extern int Level41_82CFCData6C770View1 __asm__("D_8006C770");
extern int Level41_82CFCData6DEF8View1 __asm__("D_8006DEF8");
extern int Level41_82CFCData6E020View1 __asm__("D_8006E020");
extern int Level41_82CFCData6E024View1 __asm__("D_8006E024");
extern unsigned short Level41_82CFCData6E040View1 __asm__("D_8006E040");
extern int Level41_82CFCData6E344View1 __asm__("D_8006E344");
extern int Level41_82CFCData70328View1 __asm__("D_80070328");
extern int Level41_82CFCData71908View1 __asm__("D_80071908");
extern int (*Level41_82CFCData74414View1)() __asm__("unk_ovlheader_80074414");
extern int (*Level41_82CFCData74418View1)() __asm__("unk_ovlheader_80074418");
extern int (*Level41_82CFCData7442CView1)() __asm__("unk_ovlheader_8007442C");
extern int (*Level41_82CFCData74430View1)() __asm__("unk_ovlheader_80074430");
void func_level_41_80082CFC(void* ownerParameter) {
    register int sentinelOrSelectedIndex9 __asm__("$9");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord19 __asm__("$19"), retainedAddressAngleOrDistance16 __asm__("$16"),
        retainedPositionOrDistance18 __asm__("$18"), retainedPositionVectorOrCount20 __asm__("$20"),
        retainedRecordOffset21 __asm__("$21"), retainedMaximumDistance23 __asm__("$23"),
        retainedVectorAddress22 __asm__("$22");
    struct {
        int sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C,
            sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94,
            sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4, spC8, spCC,
            spD0, spD4;
    } originalFrame;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord11;
    int retainedMaximumQualifiedDistance;
    int temporaryWord5;
    int temporaryWord7;
    int temporaryWord10;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    ownerRecord17 = ownerParameter;
    MATCHING_KEEP(ownerRecord17);
    privateRecord19 = Level41_82CFCField(ownerRecord17, void**, 0);
    rawWord2 = Level41_82CFCField(privateRecord19, short*, 44);
    rawWord3 = rawWord2;
    rawWord2 = rawWord2 < 536;
    retainedPositionOrDistance18 = 0;
    if (rawWord2) {
        rawWord2 = Level41_82CFCData6C648View1;
        rawWord2 = rawWord3 + rawWord2;
        Level41_82CFCField(privateRecord19, short*, 44) = rawWord2;
    } else {
        MATCHING_KEEP(retainedPositionOrDistance18);
        MATCHING_BARRIER("$2");
        if (Level41_82CFCAbsoluteByteAngleDeltaView1(
                (int)(Level41_82CFCData6E040View1 << 0x10) >> 0x14,
                Level41_82CFCPlanarHeadingLookupView1(
                    Level41_82CFCField(ownerRecord17, int*, 0xC) - Level41_82CFCData6E020View1,
                    Level41_82CFCField(ownerRecord17, int*, 0x10) - Level41_82CFCData6E024View1,
                    0)) < 0x20) {
            retainedPositionOrDistance18 = Level41_82CFCAllocatePoolRecord16View1(
                Level41_82CFCField(ownerRecord17, unsigned char*, 0x49));
        }
        retainedAddressAngleOrDistance16 = (int)ownerRecord17 + 12;
        if (retainedPositionOrDistance18 != 0) {
            if (Level41_82CFCApproximatePlanarDistanceView1(
                    retainedAddressAngleOrDistance16, (int)&Level41_82CFCData70328View1) < 0x3000) {
                Level41_82CFCField(privateRecord19, unsigned char*, 0x2E) =
                    (unsigned char)((int)(retainedPositionOrDistance18 -
                                          (int)&Level41_82CFCData6DEF8View1) >>
                                    4);
                Level41_82CFCField(privateRecord19, short*, 0x2C) =
                    (short)((unsigned short)Level41_82CFCField(privateRecord19, short*, 0x2C) -
                            0x10);
                Level41_82CFCField(privateRecord19, unsigned char*, 0x2F) =
                    Level41_82CFCRandBetweenView1(0, 5);
            } else {
                Level41_82CFCCopyVectorView1(retainedPositionOrDistance18,
                                             retainedAddressAngleOrDistance16);
                if (Level41_82CFCApproximatePlanarDistanceView1(
                        retainedAddressAngleOrDistance16, (int)&Level41_82CFCData70328View1) <=
                    0x7FFF) {
                    Level41_82CFCField(privateRecord19, short*, 0x2C) =
                        (short)((unsigned short)Level41_82CFCField(privateRecord19, short*, 0x2C) -
                                0x40);
                    Level41_82CFCField(retainedPositionOrDistance18, int*, 8) =
                        (int)(Level41_82CFCField(retainedPositionOrDistance18, int*, 8) + 0x80);
                } else {
                    Level41_82CFCField(privateRecord19, short*, 0x2C) =
                        (short)((unsigned short)Level41_82CFCField(privateRecord19, short*, 0x2C) -
                                0x80);
                }
                Level41_82CFCField(privateRecord19, unsigned char*, 0x2E) = 0xFFU;
            }
            Level41_82CFCField(retainedPositionOrDistance18, unsigned char*, 0xD) =
                (unsigned char)(Level41_82CFCField(retainedPositionOrDistance18, unsigned char*,
                                                   0xD) +
                                (Level41_82CFCDatarandView1() & 0x3F));
        } else {
            Level41_82CFCField(privateRecord19, short*, 0x2C) =
                (short)((unsigned short)Level41_82CFCField(privateRecord19, short*, 0x2C) - 0x80);
        }
        Level41_82CFCField(privateRecord19, short*, 0x2C) =
            (short)((unsigned short)Level41_82CFCField(privateRecord19, short*, 0x2C) -
                    ((int)(Level41_82CFCDatarandView1() & 0xFF) >> 1));
    }
    retainedAddressAngleOrDistance16 = Level41_82CFCField(privateRecord19, unsigned char*, 46);
    MATCHING_KEEP(retainedAddressAngleOrDistance16);
    if (retainedAddressAngleOrDistance16 < 16U) {
        argumentWord4 = (int)ownerRecord17;
        argumentWord5 = 4;
        __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$2");
        retainedAddressAngleOrDistance16 *= 16;
        rawWord2 = (int)&Level41_82CFCData6DEF8View1;
        retainedAddressAngleOrDistance16 += rawWord2;
        Level41_82CFCRefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
        Level41_82CFCInterpolateMobyVertexView1(
            ownerRecord17, Level41_82CFCField(privateRecord19, unsigned char*, 0x2F),
            retainedAddressAngleOrDistance16);
        if ((unsigned char)Level41_82CFCField(retainedAddressAngleOrDistance16, unsigned char*,
                                              0xC) < 4U) {
            Level41_82CFCField(privateRecord19, unsigned char*, 0x2E) = 0xFFU;
        }
    }
    retainedAddressAngleOrDistance16 = Level41_82CFCField(ownerRecord17, unsigned char*, 0x48);
    if (retainedAddressAngleOrDistance16 == 5)
        goto finishOriginalPreface;
    rawWord3 = 0x90000;
    rawWord2 = Level41_82CFCField(ownerRecord17, int*, 24);
    rawWord2 &= rawWord3;
    argumentWord4 = (int)ownerRecord17;
    if (rawWord2)
        goto activateOriginalPreface;
    argumentWord4 = (int)&Level41_82CFCData676E8View1;
    rawWord3 = Level41_82CFCData6C58CView1;
    rawWord2 = Level41_82CFCData6C5C8View1;
    rawWord3 *= 16;
    rawWord3 += argumentWord4;
    rawWord2 *= 4;
    rawWord2 += rawWord3;
    rawWord2 = Level41_82CFCField(rawWord2, int*, 0);
    rawWord3 = Level41_82CFCField(ownerRecord17, int*, 20);
    rawWord2 += 500;
    rawWord2 = rawWord2 < rawWord3;
    argumentWord4 = (int)ownerRecord17;
    if (rawWord2)
        goto finishOriginalPreface;
activateOriginalPreface:
    {
        Level41_82CFCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 7);
        Level41_82CFCInterpolateMobyVertexView1(ownerRecord17, 6U, &originalFrame.sp28);
        Level41_82CFCSpawnMobyFromValueSelectorView1(ownerRecord17, 0, 0, 0);
        Level41_82CFCInitializeMobyMotionStateWithDecelerationView1(ownerRecord17,
                                                                    privateRecord19 + 0x10, 1, 5);
        if (({
                rawWord2 = retainedAddressAngleOrDistance16 - 3;
                (unsigned int)rawWord2 < 2U;
            })) {
            Level41_82CFCField(ownerRecord17, int*, 0x14) =
                (int)(Level41_82CFCField(ownerRecord17, int*, 0x14) + 0x3E8);
            Level41_82CFCQueryWorldHeightView1((int)ownerRecord17 + 12, 0x2000);
            Level41_82CFCField(ownerRecord17, int*, 0x14) =
                (int)(Level41_82CFCField(ownerRecord17, int*, 0x14) - 0x3E8);
            if ((originalFrame.sp30 - Level41_82CFCData71908View1) >= 0x101) {
                Level41_82CFCSetMobyAnimationView1(ownerRecord17, 5);
                Level41_82CFCField(ownerRecord17, int*, 0x14) = (int)(originalFrame.sp30 + 0x80);
                Level41_82CFCField(privateRecord19, short*, 0x14) = 0xC8;
            }
        }
    }
finishOriginalPreface:
    temporaryWord5 = Level41_82CFCField(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord5) {
        case 0:
            retainedPositionVectorOrCount20 = (int)ownerRecord17 + 12;
            originalFrame.sp48 = Level41_82CFCApproximatePlanarDistanceView1(
                retainedPositionVectorOrCount20, (int)&Level41_82CFCData70328View1);
            retainedPositionOrDistance18 = (int)&originalFrame.sp38;
            MATCHING_KEEP(retainedPositionOrDistance18);
            Level41_82CFCCopyVectorView1(retainedPositionOrDistance18,
                                         (int)&Level41_82CFCData70328View1);
            if ((originalFrame.sp48 < 0x36B0) &&
                (Level41_82CFCAbsoluteByteAngleDeltaView1(
                     (int)(Level41_82CFCData6E040View1 << 0x10) >> 0x14,
                     Level41_82CFCPlanarHeadingLookupView1(
                         Level41_82CFCField(ownerRecord17, int*, 0xC) - Level41_82CFCData6E020View1,
                         Level41_82CFCField(ownerRecord17, int*, 0x10) -
                             Level41_82CFCData6E024View1,
                         0)) < 0x18)) {
                if (({
                        rawWord2 = Level41_82CFCData74418View1(
                            Level41_82CFCField(privateRecord19, void**, 12),
                            retainedPositionOrDistance18, &originalFrame.sp48, &originalFrame.sp4C,
                            -1);
                        MATCHING_KEEP(ownerRecord17);
                        argumentWord4 = (int)ownerRecord17 + 12;
                        rawWord2;
                    })) {
                    argumentWord5 = Level41_82CFCField(privateRecord19, int*, 40);
                    if (argumentWord5 >= 0) {
                        temporaryWord3 = (argumentWord5 * 0x58) + Level41_82CFCData6C550View1;
                        retainedAddressAngleOrDistance16 =
                            Level41_82CFCField(temporaryWord3, unsigned char*, 0x48);
                        if (Level41_82CFCApproximatePlanarDistanceView1(
                                retainedPositionVectorOrCount20, temporaryWord3 + 0xC) >= 0x7D1) {
                            if (!(retainedAddressAngleOrDistance16 & 0x80) &&
                                (retainedAddressAngleOrDistance16 != 0) &&
                                (retainedAddressAngleOrDistance16 != 0x14) &&
                                (retainedAddressAngleOrDistance16 != 5)) {
                                if (retainedAddressAngleOrDistance16 != 0x15) {
                                    goto block_35;
                                }
                                goto block_38;
                            }
                            goto block_37;
                        }
                    block_35:
                        if (originalFrame.sp48 < 0x1388) {
                            Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 2U;
                            Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 2);
                            MATCHING_KEEP(ownerRecord17);
                            argumentWord4 = (int)ownerRecord17 + 12;
                        } else {
                            goto produceOriginalOwnerPosition1053;
                        }
                    } else {
                    block_37:
                    block_38:
                        Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 1U;
                        Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 1);
                        argumentWord4 = (int)ownerRecord17 + 12;
                    }
                }
            } else {
                goto produceOriginalOwnerPosition1053;
            }
            goto callSharedOriginalHeightHelper1054;
        case 1:
            temporaryWord6 = Level41_82CFCField(privateRecord19, int*, 0x28);
            if ((temporaryWord6 < 0) ||
                (temporaryWord1 = (temporaryWord6 * 0x58) + Level41_82CFCData6C550View1,
                 temporaryWord7 = Level41_82CFCField(temporaryWord1, unsigned char*, 0x48),
                 ((temporaryWord7 & 0x80) != 0)) ||
                ((argumentWord4 = (int)ownerRecord17 + 12), temporaryWord7 == 5) ||
                (({
                     rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(argumentWord4,
                                                                            temporaryWord1 + 12);
                     MATCHING_KEEP(ownerRecord17);
                     argumentWord4 = (int)ownerRecord17;
                     rawWord2;
                 }) >= 2000)) {
                argumentWord4 = (int)ownerRecord17 + 12;
                if (Level41_82CFCField(privateRecord19, int*, 8) == 0) {
                    MATCHING_OBSERVE_VOLATILE(argumentWord4);
                    MATCHING_KEEP(ownerRecord17);
                    rawWord2 = Level41_82CFCField(ownerRecord17, unsigned char*, 70);
                    retainedAddressAngleOrDistance16 = (int)&originalFrame.sp60;
                    rawWord2 *= 2;
                    rawWord2 =
                        Level41_82CFCField((int)&Level41_82CFCData65920View1, short*, rawWord2);
                    argumentWord4 = retainedAddressAngleOrDistance16;
                    rawWord3 = rawWord2 * 5;
                    rawWord2 = (rawWord3 * 16 - rawWord3) >> 10;
                    originalFrame.sp60 = rawWord2;
                    rawWord2 = Level41_82CFCField(ownerRecord17, unsigned char*, 70);
                    argumentWord5 = (int)ownerRecord17 + 12;
                    rawWord2 *= 2;
                    rawWord2 =
                        Level41_82CFCField((int)&Level41_82CFCData658A0View1, short*, rawWord2);
                    argumentWord6 = retainedAddressAngleOrDistance16;
                    originalFrame.sp68 = 0;
                    MATCHING_BARRIER_VOLATILE("memory");
                    rawWord3 = rawWord2 * 5;
                    rawWord2 = (rawWord3 * 16 - rawWord3) >> 10;
                    originalFrame.sp64 = rawWord2;
                    Level41_82CFCAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                    if (({
                            rawWord2 = Level41_82CFCData74414View1(
                                Level41_82CFCField(privateRecord19, void**, 12),
                                &originalFrame.sp60);
                            MATCHING_KEEP(ownerRecord17);
                            argumentWord4 = (int)ownerRecord17 + 12;
                            !rawWord2;
                        })) {
                        argumentWord4 = (int)ownerRecord17;
                        argumentWord5 = (int)&Level41_82CFCData70328View1;
                        __asm__(""
                                : "=r"(argumentWord5)
                                : "0"(argumentWord5), "r"(argumentWord4)
                                : "$2", "memory");
                        rawWord2 = 1;
                        Level41_82CFCField(privateRecord19, int*, 8) = rawWord2;
                        Level41_82CFCData7442CView1(argumentWord4, argumentWord5,
                                                    Level41_82CFCField(privateRecord19, void**, 12),
                                                    privateRecord19 + 4, privateRecord19 + 6);
                        MATCHING_KEEP(ownerRecord17);
                        argumentWord4 = (int)ownerRecord17 + 12;
                    }
                }
                retainedAddressAngleOrDistance16 = (int)&Level41_82CFCData70328View1;
                rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(
                    argumentWord4, retainedAddressAngleOrDistance16);
                argumentWord4 = (int)&originalFrame.sp50;
                argumentWord5 = retainedAddressAngleOrDistance16;
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4));
                retainedPositionOrDistance18 = rawWord2;
                Level41_82CFCCopyVectorView1(argumentWord4, argumentWord5);
                if (Level41_82CFCField(privateRecord19, int*, 8) != 0) {
                    if (Level41_82CFCData74430View1(
                            ownerRecord17, 0x64, 4, 0, (int)&Level41_82CFCData70328View1,
                            Level41_82CFCField(privateRecord19, void**, 0xC), privateRecord19 + 4,
                            privateRecord19 + 6, 0x5DC) != 0) {
                        Level41_82CFCField(privateRecord19, int*, 8) = 0;
                    }
                } else {
                    Level41_82CFCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
                    Level41_82CFCResolveMobyYawStepView1(ownerRecord17, 0x64, 0, 0, 0);
                }
                if (Level41_82CFCData74418View1(
                        Level41_82CFCField(privateRecord19, void**, 0xC), &originalFrame.sp50,
                        &originalFrame.sp70, &originalFrame.sp74,
                        (int)Level41_82CFCField((int)&Level41_82CFCData70328View1, unsigned char*,
                                                0xE)) == 0) {
                    Level41_82CFCField(privateRecord19, unsigned short*, 2) =
                        (unsigned short)originalFrame.sp74;
                    Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                    Level41_82CFCField(privateRecord19, short*, 0) = 0x78;
                    Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 1);
                    Level41_82CFCField(privateRecord19, int*, 8) = 0;
                    goto produceOriginalOwnerPosition1053;
                }
                if ((Level41_82CFCData6E344View1 != 1) && ({
                        rawWord2 = retainedPositionOrDistance18 < 5000;
                        rawWord2;
                    }) &&
                    (Level41_82CFCAbsoluteByteAngleDeltaView1(
                         (int)(Level41_82CFCData6E040View1 << 0x10) >> 0x14,
                         Level41_82CFCPlanarHeadingLookupView1(
                             Level41_82CFCField(ownerRecord17, int*, 0xC) -
                                 Level41_82CFCData6E020View1,
                             Level41_82CFCField(ownerRecord17, int*, 0x10) -
                                 Level41_82CFCData6E024View1,
                             0)) < 0x18)) {
                    argumentWord4 = (int)ownerRecord17;
                    argumentWord5 = 2;
                    rawWord2 = 2;
                    Level41_82CFCField(privateRecord19, int*, 8) = 0;
                    goto callSharedOriginalStateHelper607;
                } else {
                    goto produceOriginalOwnerPosition1053;
                }
            } else {
                goto resetSharedOriginalOwnerState;
            }
            goto callSharedOriginalHeightHelper1054;
        case 2:
            Level41_82CFCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            if (Level41_82CFCData6C770View1 != 0) {
                if ((Level41_82CFCData6E344View1 == 1) ||
                    (Level41_82CFCAbsoluteByteAngleDeltaView1(
                         (int)(Level41_82CFCData6E040View1 << 0x10) >> 0x14,
                         Level41_82CFCPlanarHeadingLookupView1(
                             Level41_82CFCField(ownerRecord17, int*, 0xC) -
                                 Level41_82CFCData6E020View1,
                             Level41_82CFCField(ownerRecord17, int*, 0x10) -
                                 Level41_82CFCData6E024View1,
                             0)) >= 0x18)) {
                    Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 0U;
                    Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 0);
                    argumentWord4 = (int)ownerRecord17 + 12;
                } else {
                    Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 3U;
                    Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 3);
                    Level41_82CFCField(ownerRecord17, unsigned char*, 64) = 240;
                    Level41_82CFCField(privateRecord19, short*, 0x16) = 0x64;
                    goto produceOriginalOwnerPosition1053;
                }
            } else {
                goto produceOriginalOwnerPosition1053;
            }
            goto callSharedOriginalHeightHelper1054;
        case 3:
            Level41_82CFCField(ownerRecord17, int*, 0x14) =
                (int)(Level41_82CFCField(ownerRecord17, int*, 0x14) +
                      Level41_82CFCField(privateRecord19, short*, 0x16));
            rawWord2 = Level41_82CFCField(privateRecord19, unsigned short*, 22) - 16;
            Level41_82CFCField(privateRecord19, short*, 22) = rawWord2;
            MATCHING_KEEP_CLOBBER(rawWord2, "memory");
            rawWord2 = (short)rawWord2;
            if (rawWord2 < -450) {
                Level41_82CFCField(privateRecord19, short*, 0x16) = -0x1C2;
            }
            retainedPositionOrDistance18 = (int)ownerRecord17 + 12;
            retainedAddressAngleOrDistance16 = Level41_82CFCApproximatePlanarDistanceView1(
                retainedPositionOrDistance18, (int)&Level41_82CFCData70328View1);
            rawWord3 = Level41_82CFCData6E344View1;
            rawWord2 = 1;
            if (rawWord3 == rawWord2) {
                rawWord2 = retainedAddressAngleOrDistance16 < 1500;
                rawWord2 = -rawWord2;
                rawWord3 = -150;
                retainedAddressAngleOrDistance16 = rawWord2 & rawWord3;
                rawWord2 = retainedAddressAngleOrDistance16 < 151;
            } else {
                rawWord2 = retainedAddressAngleOrDistance16 < 151;
            }
            retainedPositionVectorOrCount20 = (int)&originalFrame.sp78;
            if (!rawWord2)
                retainedAddressAngleOrDistance16 = 150;
            Level41_82CFCCopyVectorView1(retainedPositionVectorOrCount20,
                                         retainedPositionOrDistance18);
            Level41_82CFCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            Level41_82CFCResolveMobyYawStepView1(ownerRecord17, retainedAddressAngleOrDistance16, 0,
                                                 0, 0);
            if (({
                    rawWord2 =
                        Level41_82CFCData74414View1(Level41_82CFCField(privateRecord19, void**, 12),
                                                    retainedPositionOrDistance18);
                    argumentWord4 = retainedPositionOrDistance18;
                    rawWord2;
                }) == 0) {
                Level41_82CFCCopyVectorView1(argumentWord4, retainedPositionVectorOrCount20);
                argumentWord4 = retainedPositionOrDistance18;
            }
            Level41_82CFCField(ownerRecord17, int*, 20) += 1000;
            Level41_82CFCQueryWorldHeightView1(argumentWord4, 8192);
            rawWord2 = Level41_82CFCField(ownerRecord17, int*, 20);
            rawWord3 = rawWord2 - 1000;
            Level41_82CFCField(ownerRecord17, int*, 20) = rawWord3;
            rawWord2 = Level41_82CFCField(privateRecord19, short*, 22);
            argumentWord4 = (int)ownerRecord17 + 12;
            if (rawWord2 >= 0)
                goto callSharedOriginalHeightHelper1054;
            argumentWord6 = Level41_82CFCData71908View1;
            rawWord2 = argumentWord6 < rawWord3;
            if (rawWord2)
                goto callSharedOriginalHeightHelper1054;
            rawWord2 = 4;
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 4;
            Level41_82CFCField(ownerRecord17, int*, 20) = argumentWord6;
        callSharedOriginalStateHelper607:
            Level41_82CFCField(ownerRecord17, unsigned char*, 72) = rawWord2;
            Level41_82CFCRequestMobyAnimationView1(argumentWord4, argumentWord5);
            argumentWord4 = (int)ownerRecord17 + 12;
            goto callSharedOriginalHeightHelper1054;
        case 4:
            temporaryWord4 = Level41_82CFCReadSelectedFrameScalarView1(ownerRecord17);
            if (temporaryWord4 >= 51)
                goto subtractOriginal51;
            Level41_82CFCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            rawWord2 = temporaryWord4 < 40;
            if (rawWord2) {
                rawWord2 = temporaryWord4 - 51;
                goto testOriginalFiveStates;
            }
            temporaryWord11 = Level41_82CFCApproximatePlanarDistanceView1(
                (int)ownerRecord17 + 12, (int)&Level41_82CFCData70328View1);
            if (temporaryWord11 >= 151)
                temporaryWord11 = 150;
            Level41_82CFCResolveMobyYawStepView1(ownerRecord17, temporaryWord11, 0, 0, 4);
        subtractOriginal51:
            rawWord2 = temporaryWord4 - 51;
        testOriginalFiveStates:
            if (rawWord2 < 5U) {
                retainedAddressAngleOrDistance16 = (int)&Level41_82CFCData70328View1 + 0xB8;
                retainedPositionOrDistance18 = (int)ownerRecord17 + 12;
                if (Level41_82CFCField(retainedAddressAngleOrDistance16, int*, 0) == 0) {
                    if (({
                            rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(
                                retainedPositionOrDistance18,
                                retainedAddressAngleOrDistance16 - 184);
                            argumentWord4 = retainedPositionOrDistance18;
                            rawWord2;
                        }) < 1500) {
                        MATCHING_KEEP_CLOBBER(retainedAddressAngleOrDistance16, "memory");
                        rawWord2 = Level41_82CFCField(retainedAddressAngleOrDistance16, int*, -148);
                        Level41_82CFCField(retainedAddressAngleOrDistance16, int*, 480) = 0;
                        rawWord2 |= 22;
                        Level41_82CFCField(retainedAddressAngleOrDistance16, int*, -148) = rawWord2;
                        Level41_82CFCField(ownerRecord17, unsigned char*, 0x49) = 1U;
                    }
                    Level41_82CFCQueryDynamicMobyGeometryView1(argumentWord4, 1550, 3, 0, 65536,
                                                               ownerRecord17);
                }
            }
            if (Level41_82CFCField(ownerRecord17, unsigned char*, 0x49) == 1) {
                rawWord3 = (int)&Level41_82CFCData70328View1 + 36;
                rawWord2 = Level41_82CFCField(rawWord3, int*, 0);
                Level41_82CFCField((int)&Level41_82CFCData70328View1, int*, 664) = 0;
                rawWord2 |= 22;
                Level41_82CFCField(rawWord3, int*, 0) = rawWord2;
            }
            retainedMaximumQualifiedDistance = 0;
            if (Level41_82CFCData6C770View1 != 0) {
                sentinelOrSelectedIndex9 = -1;
                retainedMaximumDistance23 = 0;
                __asm__(""
                        : "=r"(retainedMaximumDistance23)
                        : "0"(retainedMaximumDistance23), "r"(sentinelOrSelectedIndex9));
                originalFrame.spC0 = sentinelOrSelectedIndex9;
                rawWord3 = Level41_82CFCField(privateRecord19, int*, 12);
                originalFrame.spC8 = sentinelOrSelectedIndex9;
                rawWord2 = Level41_82CFCField(rawWord3, unsigned char*, 1);
                retainedPositionVectorOrCount20 = 0;
                if (rawWord2 > 0) {
                    retainedVectorAddress22 = (int)&originalFrame.sp88;
                    MATCHING_KEEP(retainedVectorAddress22);
                    retainedRecordOffset21 = 0;
                    do {
                        rawWord2 = rawWord3 + retainedRecordOffset21;
                        originalFrame.sp88 = Level41_82CFCField(rawWord2, int*, 20);
                        originalFrame.sp8C =
                            Level41_82CFCField((Level41_82CFCField(privateRecord19, void**, 0xC) +
                                                retainedRecordOffset21),
                                               int*, 0x18);
                        originalFrame.sp90 = Level41_82CFCField(ownerRecord17, int*, 0x14);
                        retainedPositionOrDistance18 = Level41_82CFCApproximatePlanarDistanceView1(
                            retainedVectorAddress22, (int)&Level41_82CFCData70328View1);
                        if ((retainedMaximumQualifiedDistance < retainedPositionOrDistance18) &&
                            (({
                                 rawWord2 = Level41_82CFCPlanarHeadingLookupView1(
                                     Level41_82CFCField((int)&Level41_82CFCData70328View1, int*,
                                                        0) -
                                         Level41_82CFCField(ownerRecord17, int*, 12),
                                     Level41_82CFCField((int)&Level41_82CFCData70328View1, int*,
                                                        4) -
                                         Level41_82CFCField(ownerRecord17, int*, 16),
                                     0);
                                 argumentWord6 = 0;
                                 __asm__(""
                                         : "=r"(argumentWord6)
                                         : "0"(argumentWord6), "r"(rawWord2)
                                         : "$16");
                                 retainedAddressAngleOrDistance16 = rawWord2;
                             }),
                             ((Level41_82CFCAbsoluteByteAngleDeltaView1(
                                   retainedAddressAngleOrDistance16, ({
                                       argumentWord7 = originalFrame.sp88;
                                       argumentWord4 = Level41_82CFCField(ownerRecord17, int*, 12);
                                       rawWord3 = originalFrame.sp8C;
                                       argumentWord5 = Level41_82CFCField(ownerRecord17, int*, 16);
                                       argumentWord4 = argumentWord7 - argumentWord4;
                                       argumentWord5 = rawWord3 - argumentWord5;
                                       Level41_82CFCPlanarHeadingLookupView1(
                                           argumentWord4, argumentWord5, argumentWord6);
                                   })) < 0x41) == 0))) {
                            temporaryWord8 = Level41_82CFCField(privateRecord19, int*, 0x28);
                            if (temporaryWord8 >= 0) {
                                rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(
                                    retainedVectorAddress22,
                                    Level41_82CFCData6C550View1 + temporaryWord8 * 88 + 12);
                                if (!rawWord2) {
                                    rawWord2 =
                                        retainedMaximumDistance23 < retainedPositionOrDistance18;
                                    goto compareOriginalLoopMaximum;
                                }
                            }
                            retainedMaximumQualifiedDistance = retainedPositionOrDistance18;
                            originalFrame.spC0 = retainedPositionVectorOrCount20;
                        }
                        rawWord2 = retainedMaximumDistance23 < retainedPositionOrDistance18;
                    compareOriginalLoopMaximum:
                        if (rawWord2) {
                            retainedMaximumDistance23 = retainedPositionOrDistance18;
                            originalFrame.spC8 = retainedPositionVectorOrCount20;
                        }
                        rawWord3 = Level41_82CFCField(privateRecord19, int*, 12);
                        rawWord2 = Level41_82CFCField(rawWord3, unsigned char*, 1);
                        __asm__(""
                                : "=r"(retainedPositionVectorOrCount20)
                                : "0"(retainedPositionVectorOrCount20), "r"(rawWord2));
                        retainedPositionVectorOrCount20 += 1;
                        rawWord2 = retainedPositionVectorOrCount20 < rawWord2;
                        __asm__(""
                                : "=r"(retainedRecordOffset21)
                                : "0"(retainedRecordOffset21), "r"(rawWord2));
                        retainedRecordOffset21 += 28;
                    } while (rawWord2);
                }
                sentinelOrSelectedIndex9 = originalFrame.spC0;
                if (sentinelOrSelectedIndex9 < 0) {
                    sentinelOrSelectedIndex9 =
                        Level41_82CFCField(&originalFrame.spC8, unsigned short*, 0);
                    Level41_82CFCField(privateRecord19, short*, 2) = sentinelOrSelectedIndex9;
                } else {
                    sentinelOrSelectedIndex9 =
                        Level41_82CFCField(&originalFrame.spC0, unsigned short*, 0);
                    Level41_82CFCField(privateRecord19, short*, 2) = sentinelOrSelectedIndex9;
                }
                argumentWord4 = (int)ownerRecord17 + 12;
                MATCHING_KEEP(argumentWord4);
                Level41_82CFCField(ownerRecord17, int*, 20) += 1000;
                Level41_82CFCField(ownerRecord17, int*, 20) =
                    Level41_82CFCQueryWorldHeightView1(argumentWord4, 8192);
                Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                Level41_82CFCField(privateRecord19, short*, 0) = 0x78;
                Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 1);
                MATCHING_KEEP(ownerRecord17);
                argumentWord4 = (int)ownerRecord17 + 12;
            } else {
                goto produceOriginalOwnerPosition1053;
            }
            goto callSharedOriginalHeightHelper1054;
        case 20:
            temporaryWord9 = Level41_82CFCField(privateRecord19, int*, 0x28);
            if (temporaryWord9 >= 0) {
                temporaryWord2 = (temporaryWord9 * 0x58) + Level41_82CFCData6C550View1;
                temporaryWord10 = Level41_82CFCField(temporaryWord2, unsigned char*, 0x48);
                if (!(temporaryWord10 & 0x80) &&
                    ((argumentWord4 = (int)ownerRecord17 + 12), temporaryWord10 != 5) && (({
                        rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(argumentWord4,
                                                                               temporaryWord2 + 12);
                        argumentWord4 = (int)ownerRecord17;
                        rawWord2 < 2000;
                    }))) {
                resetSharedOriginalOwnerState:
                    Level41_82CFCField(privateRecord19, int*, 8) = 0;
                    Level41_82CFCField(ownerRecord17, unsigned char*, 72) = 0;
                    Level41_82CFCRequestMobyAnimationView1(argumentWord4, 0);
                    argumentWord4 = (int)ownerRecord17 + 12;
                    goto callSharedOriginalHeightHelper1054;
                }
            }
            rawWord3 = Level41_82CFCField(privateRecord19, short*, 2);
            MATCHING_KEEP(rawWord3);
            rawWord2 = rawWord3 * 28;
            rawWord3 = Level41_82CFCField(privateRecord19, int*, 12);
            rawWord3 += rawWord2;
            rawWord2 = Level41_82CFCField(rawWord3, int*, 20);
            originalFrame.sp98 = rawWord2;
            rawWord3 = Level41_82CFCField(privateRecord19, short*, 2);
            MATCHING_KEEP(rawWord3);
            rawWord2 = rawWord3 * 28;
            rawWord3 = Level41_82CFCField(privateRecord19, int*, 12);
            rawWord3 += rawWord2;
            rawWord2 = Level41_82CFCField(rawWord3, int*, 24);
            originalFrame.sp9C = rawWord2;
            originalFrame.spA0 = Level41_82CFCField(ownerRecord17, int*, 0x14);
            rawWord2 = Level41_82CFCField(privateRecord19, int*, 8);
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2)
                goto callOriginalCallback900;
            {
                MATCHING_OBSERVE_VOLATILE(argumentWord4);
                rawWord2 = Level41_82CFCField(ownerRecord17, unsigned char*, 70);
                retainedAddressAngleOrDistance16 = (int)&originalFrame.spA8;
                rawWord2 *= 2;
                rawWord2 = Level41_82CFCField((int)&Level41_82CFCData65920View1, short*, rawWord2);
                argumentWord4 = retainedAddressAngleOrDistance16;
                rawWord3 = rawWord2 * 5;
                rawWord2 = (rawWord3 * 16 - rawWord3) >> 10;
                originalFrame.spA8 = rawWord2;
                rawWord2 = Level41_82CFCField(ownerRecord17, unsigned char*, 70);
                argumentWord5 = (int)ownerRecord17 + 12;
                rawWord2 *= 2;
                rawWord2 = Level41_82CFCField((int)&Level41_82CFCData658A0View1, short*, rawWord2);
                argumentWord6 = retainedAddressAngleOrDistance16;
                originalFrame.spB0 = 0;
                MATCHING_BARRIER_VOLATILE("memory");
                rawWord3 = rawWord2 * 5;
                rawWord2 = (rawWord3 * 16 - rawWord3) >> 10;
                originalFrame.spAC = rawWord2;
                Level41_82CFCAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
                if (({
                        rawWord2 = Level41_82CFCData74414View1(
                            Level41_82CFCField(privateRecord19, void**, 12), &originalFrame.spA8);
                        argumentWord4 = (int)ownerRecord17;
                        rawWord2;
                    }) == 0) {
                    Level41_82CFCField(privateRecord19, int*, 8) = 1;
                    Level41_82CFCData7442CView1(argumentWord4, &originalFrame.sp98,
                                                Level41_82CFCField(privateRecord19, void**, 0xC),
                                                privateRecord19 + 4, privateRecord19 + 6);
                }
            }
            MATCHING_BARRIER("$4");
            rawWord2 = Level41_82CFCField(privateRecord19, int*, 8);
            argumentWord4 = (int)ownerRecord17;
            if (rawWord2) {
            callOriginalCallback900:
                if (Level41_82CFCData74430View1(argumentWord4, 100, 4, 0, &originalFrame.sp98,
                                                Level41_82CFCField(privateRecord19, void**, 12),
                                                privateRecord19 + 4, privateRecord19 + 6,
                                                1500) != 0)
                    Level41_82CFCField(privateRecord19, int*, 8) = 0;
            } else {
                __asm__ volatile("" ::"r"(argumentWord4) : "$2", "$6");
                Level41_82CFCTurnMobyTowardHeadingView1(
                    ownerRecord17,
                    Level41_82CFCPlanarHeadingLookupView1(
                        originalFrame.sp98 - Level41_82CFCField(ownerRecord17, int*, 12),
                        originalFrame.sp9C - Level41_82CFCField(ownerRecord17, int*, 16), 0),
                    4, 2, 1, 0);
                Level41_82CFCResolveMobyYawStepView1(ownerRecord17, 100, 0, 0, 0);
            }
            argumentWord4 = privateRecord19;
            if (Level41_82CFCField(ownerRecord17, unsigned char*, 0x49) == 1) {
                argumentWord4 = (int)ownerRecord17 + 12;
                rawWord2 = (int)&Level41_82CFCData70328View1 + 36;
                rawWord3 = Level41_82CFCField(rawWord2, int*, 0);
                argumentWord5 = rawWord2 - 36;
                Level41_82CFCField((int)&Level41_82CFCData70328View1, int*, 664) = 0;
                rawWord3 |= 22;
                Level41_82CFCField(rawWord2, int*, 0) = rawWord3;
                if (({
                        rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(argumentWord4,
                                                                               argumentWord5);
                        MATCHING_KEEP(ownerRecord17);
                        argumentWord4 = (int)ownerRecord17 + 12;
                        rawWord2;
                    }) >= 2001) {
                    Level41_82CFCField(ownerRecord17, unsigned char*, 0x49) = 0U;
                }
            } else if ((({
                            rawWord2 = Level41_82CFCCountTimerDownView1(argumentWord4, 2);
                            argumentWord4 = (int)ownerRecord17 + 12;
                            rawWord2;
                        }) != 0) &&
                       (({
                            retainedAddressAngleOrDistance16 = (int)&Level41_82CFCData70328View1;
                            rawWord2 = Level41_82CFCApproximatePlanarDistanceView1(
                                argumentWord4, retainedAddressAngleOrDistance16);
                            MATCHING_KEEP(ownerRecord17);
                            rawWord2;
                        }) < 5000)) {
                if (({
                        rawWord2 = Level41_82CFCAbsoluteByteAngleDeltaView1(
                            (int)(Level41_82CFCData6E040View1 << 16) >> 20,
                            Level41_82CFCPlanarHeadingLookupView1(
                                Level41_82CFCField(ownerRecord17, int*, 12) -
                                    Level41_82CFCData6E020View1,
                                Level41_82CFCField(ownerRecord17, int*, 16) -
                                    Level41_82CFCData6E024View1,
                                0));
                        argumentWord4 = (int)ownerRecord17 + 12;
                        rawWord2;
                    }) < 24) {
                    if (Level41_82CFCData74414View1(Level41_82CFCField(privateRecord19, void**, 12),
                                                    retainedAddressAngleOrDistance16) != 0) {
                        Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 2U;
                        Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 2);
                    }
                    goto produceOriginalOwnerPosition1002;
                }
            } else {
            produceOriginalOwnerPosition1002:
                argumentWord4 = (int)ownerRecord17 + 12;
            }
            if (Level41_82CFCApproximatePlanarDistanceView1(argumentWord4, &originalFrame.sp98) <
                0x4B0) {
                Level41_82CFCField(privateRecord19, short*, 0) = 0;
                Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 0x15U;
                Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 1);
                Level41_82CFCField(ownerRecord17, unsigned char*, 0x49) = 0U;
                Level41_82CFCField(privateRecord19, int*, 8) = 0;
            }
            goto produceOriginalOwnerPosition1053;
            goto callSharedOriginalHeightHelper1054;
        case 21:
            if (Level41_82CFCTurnMobyTowardPlayerView1(ownerRecord17, 4, 4, 1) != 0) {
                Level41_82CFCField(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level41_82CFCRequestMobyAnimationView1(ownerRecord17, 0);
            }
            Level41_82CFCResolveMobyYawStepView1(ownerRecord17, 0x32, 0, 0, 4);
            argumentWord4 = (int)ownerRecord17 + 12;
            goto callSharedOriginalHeightHelper1054;
        case 5:
            if (({
                    rawWord2 = Level41_82CFCUpdateMobyMotionDescriptorView1(ownerRecord17,
                                                                            privateRecord19 + 16);
                    argumentWord4 = (int)ownerRecord17 + 12;
                    rawWord2;
                }) == 256) {
                MATCHING_OBSERVE_VOLATILE(argumentWord4);
                Level41_82CFCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Level41_82CFCMarkMobyCollectionBitView1(ownerRecord17);
                Level41_82CFCEmitMobyVertexParticlesView1(ownerRecord17, 0x30);
                Level41_82CFCDeleteMobyView1(ownerRecord17);
                return;
            }
            goto callSharedOriginalHeightHelper1054;
        default:
        produceOriginalOwnerPosition1053:
            argumentWord4 = (int)ownerRecord17 + 12;
        callSharedOriginalHeightHelper1054:
            Level41_82CFCField(ownerRecord17, int*, 20) += 200;
            Level41_82CFCQueryWorldHeightView1(argumentWord4, 8192);
            Level41_82CFCField(ownerRecord17, int*, 20) -= 200;
            Level41_82CFCRefreshMobyPackedQueryFieldView1(ownerRecord17);
            Level41_82CFCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 2);
            return;
    }
}
#undef Level41_82CFCField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80083DDC.
* AI generated; not human reviewed. All722 instructions,37 selectors and
* one zero pad require every native/linked word and actual target:760 words.
* Frame48 saves S0..S5/RA and keeps original SP18..27 workspace. Original
*36A68 receives incoming owner plus three zeros;matched EXE source1163
* records its four-argument contract. Saved S0 result,predicate,spawned
* position,player base,owner position and final target occupy disjoint phases.
* Complete constructor results retain S2 in both states. Vector table/record
* loads,original A0/A1 producer order and C0 bytes match the original words.
* Shared state writer605 and position/height chain630/631 remain physically
* after all states. A0 captures the complete owner+12 address before S0 gets
* ((10240-distance)/10)+256. With distance3210,target959 must not become the
* callee address;A0 remains owner+12. Full signed division reuses only its
* ordinary complete0x66666667 magic scalar;no partialHI/LO is synthesized.
* Original global word71908 reloads after each owner-word14 store. Signed
* comparisons,30/256 corrections and prepared branch entries are retained.
* Empty metadata consumes complete initialized words/addresses or clobbers
* only dead values before fresh complete producers;zero CPU instructions.
* Compiler/filter/flags unchanged;no opcode asm,fixedFP,undefined saved
* inputs or overlapping live aliases. Physical units/fixed point,complete
* helper/caller chains,cadence beyond invocation and synchronized runtime
* remain open. Confidence is binary identity after all gates. Next:human
* review and retail captures. Falsification:every native/linked word,actual
* destination,owned selector/padding and full EXE/every-overlay retail hash.
*/
/* Original assembly SHA256 06f9b20e77695624a7321105b7182b0a4a66147af065fc31bb9704fb7894eb08 */
#define Level41_83DDCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level41_83DDCQueryWorldHeightView1() __asm__("func_8001A358");
int Level41_83DDCRequestMobyAnimationView1() __asm__("func_80034F40");
int Level41_83DDCUpdateMobyMotionDescriptorView1() __asm__("func_80035194");
int Level41_83DDCTurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level41_83DDCTurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level41_83DDCCountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level41_83DDCResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level41_83DDCGetClosestPathNodeView1() __asm__("func_8003645C");
int Level41_83DDCEmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level41_83DDCSpawnMobyFromValueSelectorView1() __asm__("func_80036A68");
int Level41_83DDCInitializeMobyMotionStateView1() __asm__("func_80038BF8");
int Level41_83DDCMarkMobyCollectionBitView1() __asm__("func_8003BA00");
int Level41_83DDCPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level41_83DDCMeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level41_83DDCScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Level41_83DDCAddVectorView1() __asm__("func_8004F194");
int Level41_83DDCAbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level41_83DDCApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level41_83DDCDeleteMobyView1() __asm__("func_80055B18");
int Level41_83DDCRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level41_83DDCReadSelectedFrameScalarView1() __asm__("func_80055E84");
int Level41_83DDCInterpolateMobyVertexView1() __asm__("func_80055F14");
int Level41_83DDCRefreshMobyPackedQueryFieldView1() __asm__("func_8005629C");
extern int Level41_83DDCData6C770View1 __asm__("D_8006C770");
extern int Level41_83DDCData6E020View1 __asm__("D_8006E020");
extern int Level41_83DDCData6E024View1 __asm__("D_8006E024");
extern unsigned short Level41_83DDCData6E040View1 __asm__("D_8006E040");
extern int Level41_83DDCData6E344View1 __asm__("D_8006E344");
extern int Level41_83DDCData70328View1 __asm__("D_80070328");
extern int Level41_83DDCData71908View1 __asm__("D_80071908");
extern void* (*Level41_83DDCDataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern void* (*Level41_83DDCDataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
extern int (*Level41_83DDCData743C8View1)() __asm__("unk_ovlheader_800743C8");
void func_level_41_80083DDC(void* ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int retainedSpawnedRecord18 __asm__("$18");
    register void* ownerRecord17 __asm__("$17");
    register int privateRecord20 __asm__("$20"), retainedResultFlagBaseOrTarget16 __asm__("$16"),
        retainedSpawnedPrivate19 __asm__("$19"), retainedOriginalDistance21 __asm__("$21");
    struct {
        int sp18, sp1C, sp20, sp24;
    } originalFrame;
    int temporaryWord10;
    int temporaryWord13;
    int temporaryWord1;
    int temporaryWord6;
    int temporaryWord19;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord14;
    int temporaryWord18;
    int temporaryWord20;
    ownerRecord17 = ownerParameter;
    MATCHING_KEEP(ownerRecord17);
    privateRecord20 = Level41_83DDCField(ownerRecord17, void**, 0);
    retainedOriginalDistance21 = 0;
    if ((Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) != 4) &&
        (Level41_83DDCField(ownerRecord17, int*, 0x18) & 0x8B0000)) {
        Level41_83DDCSpawnMobyFromValueSelectorView1(ownerParameter, 0, 0, 0);
        Level41_83DDCInitializeMobyMotionStateView1(ownerRecord17, privateRecord20 + 8, 6, 4);
        Level41_83DDCField(privateRecord20, unsigned char*, 0x1E) =
            (unsigned char)(Level41_83DDCField(privateRecord20, unsigned char*, 0x1E) + 0x3C);
    }
    if (Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) == 0) {
        Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) = 1U;
        if (Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) != 0x1E) {
            Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0x14U;
            Level41_83DDCField(ownerRecord17, int*, 0x14) =
                (int)(Level41_83DDCField(ownerRecord17, int*, 0x14) + 0x100);
            Level41_83DDCField(Level41_83DDCField(privateRecord20, void**, 4), short*, 0xA) = 1;
            Level41_83DDCField(Level41_83DDCField(privateRecord20, void**, 4), short*, 2) =
                Level41_83DDCData743C8View1(Level41_83DDCField(privateRecord20, void**, 4));
        }
    }
    temporaryWord15 = Level41_83DDCField(ownerRecord17, unsigned char*, 0x48);
    switch (temporaryWord15) {
        case 30:
            Level41_83DDCGetClosestPathNodeView1(ownerRecord17 + 0xC,
                                                 Level41_83DDCField(privateRecord20, void**, 4),
                                                 &originalFrame.sp18);
            Level41_83DDCField(Level41_83DDCField(privateRecord20, void**, 4), short*, 2) =
                (short)originalFrame.sp18;
            Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0x20U;
            Level41_83DDCField(ownerRecord17, int*, 0x14) =
                (int)(Level41_83DDCField(ownerRecord17, int*, 0x14) + 0x400);
            return;
        case 32:
            temporaryWord7 = Level41_83DDCField(privateRecord20, void**, 0x20);
            if (temporaryWord7 == 0) {
                temporaryWord11 = Level41_83DDCField(privateRecord20, void**, 4);
                temporaryWord20 = Level41_83DDCField(temporaryWord11, int*, 0xC) +
                                  (Level41_83DDCField(temporaryWord11, short*, 2) * 0x10);
            } else {
                temporaryWord20 = temporaryWord7 + 0xC;
            }
            temporaryWord1 = Level41_83DDCField(temporaryWord20, int*, 0) -
                             Level41_83DDCField(ownerRecord17, int*, 0xC);
            originalFrame.sp20 = temporaryWord1;
            temporaryWord6 = Level41_83DDCField(temporaryWord20, int*, 4) -
                             Level41_83DDCField(ownerRecord17, int*, 0x10);
            originalFrame.sp24 = temporaryWord6;
            Level41_83DDCTurnMobyTowardHeadingView1(
                ownerRecord17,
                Level41_83DDCPlanarHeadingLookupView1(temporaryWord1, temporaryWord6, 0), 4, 2, 1,
                0);
            return;
        case 34:
            Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 1);
            Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0x24U;
            return;
        case 36:
            retainedResultFlagBaseOrTarget16 =
                Level41_83DDCReadSelectedFrameScalarView1(ownerRecord17);
            if (Level41_83DDCData6C770View1 != 0) {
                temporaryWord16 = Level41_83DDCField(ownerRecord17, unsigned char*, 0x3D);
                if (temporaryWord16 == Level41_83DDCField(ownerRecord17, unsigned char*, 0x3C)) {
                    if (temporaryWord16 == 1) {
                        Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 2);
                    }
                    goto checkOriginalState36Animation;
                }
            } else {
            checkOriginalState36Animation:
                if ((Level41_83DDCField(ownerRecord17, unsigned char*, 0x3D) ==
                     Level41_83DDCField(ownerRecord17, unsigned char*, 0x3C)) &&
                    (Level41_83DDCField(ownerRecord17, unsigned char*, 0x3D) == 2) && (({
                        rawWord2 = retainedResultFlagBaseOrTarget16 < 24;
                        MATCHING_KEEP(rawWord2);
                        !rawWord2;
                    })) &&
                    (Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) == 1)) {
                    retainedSpawnedRecord18 = Level41_83DDCDataSpawnMobyView1(0x289, ownerRecord17);
                    MATCHING_KEEP(retainedSpawnedRecord18);
                    if (retainedSpawnedRecord18 != 0) {
                        retainedSpawnedPrivate19 =
                            Level41_83DDCField(retainedSpawnedRecord18, void**, 0);
                        Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) = 2U;
                        Level41_83DDCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
                        __asm__ volatile("" ::: "$16", "memory");
                        argumentWord4 = (int)ownerRecord17;
                        argumentWord5 = 2;
                        __asm__(""
                                : "=r"(argumentWord5)
                                : "0"(argumentWord5), "r"(argumentWord4)
                                : "$16");
                        retainedResultFlagBaseOrTarget16 = retainedSpawnedRecord18 + 12;
                        Level41_83DDCInterpolateMobyVertexView1(argumentWord4, argumentWord5,
                                                                retainedResultFlagBaseOrTarget16);
                        Level41_83DDCField(retainedSpawnedRecord18, signed char*, 0x4F) = 0xC;
                        argumentWord4 = Level41_83DDCField(privateRecord20, int*, 32);
                        rawWord3 = Level41_83DDCField(retainedSpawnedRecord18, int*, 12);
                        rawWord2 = Level41_83DDCField(argumentWord4, int*, 12);
                        rawWord2 -= rawWord3;
                        Level41_83DDCField(retainedSpawnedPrivate19, int*, 0) = rawWord2;
                        rawWord2 = Level41_83DDCField(argumentWord4, int*, 16);
                        rawWord3 = Level41_83DDCField(retainedSpawnedRecord18, int*, 16);
                        argumentWord5 = 1;
                        rawWord2 -= rawWord3;
                        Level41_83DDCField(retainedSpawnedPrivate19, int*, 4) = rawWord2;
                        rawWord2 = Level41_83DDCField(argumentWord4, int*, 20);
                        rawWord3 = Level41_83DDCField(retainedSpawnedRecord18, int*, 20);
                        argumentWord4 = retainedSpawnedPrivate19;
                        rawWord2 -= rawWord3;
                        Level41_83DDCField(retainedSpawnedPrivate19, int*, 8) = rawWord2;
                        rawWord2 =
                            Level41_83DDCMeasureVectorLengthView1(argumentWord4, argumentWord5);
                        Level41_83DDCScaleVectorRatioQ15View1(retainedSpawnedPrivate19, rawWord2,
                                                              200);
                        Level41_83DDCAddVectorView1(retainedResultFlagBaseOrTarget16,
                                                    retainedSpawnedPrivate19,
                                                    retainedResultFlagBaseOrTarget16);
                        Level41_83DDCAddVectorView1(retainedResultFlagBaseOrTarget16,
                                                    retainedSpawnedPrivate19,
                                                    retainedResultFlagBaseOrTarget16);
                        temporaryWord12 =
                            Level41_83DDCDataSpawnParticleView1(1, 0xC, retainedSpawnedRecord18, 1);
                        if (temporaryWord12 != 0) {
                            Level41_83DDCField(temporaryWord12, unsigned char*, 0xC) = 0xC0;
                            Level41_83DDCField(temporaryWord12, unsigned char*, 0xD) = 0xC0;
                            Level41_83DDCField(temporaryWord12, unsigned char*, 0xE) = 0xC0;
                        }
                        Level41_83DDCField(retainedSpawnedPrivate19, int*, 0xC) = 0xB4;
                    }
                }
            }
            if (Level41_83DDCData6C770View1 != 0) {
                temporaryWord17 = Level41_83DDCField(ownerRecord17, unsigned char*, 0x3D);
                if ((temporaryWord17 == Level41_83DDCField(ownerRecord17, unsigned char*, 0x3C)) &&
                    (temporaryWord17 == 2)) {
                    Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) = 1U;
                    Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 0);
                    Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0x20U;
                    return;
                }
            }
            return;
        case 0:
            argumentWord4 = (int)ownerRecord17 + 12;
            retainedResultFlagBaseOrTarget16 = (int)&Level41_83DDCData70328View1;
            retainedOriginalDistance21 = Level41_83DDCApproximatePlanarDistanceView1(
                argumentWord4, retainedResultFlagBaseOrTarget16);
            if (retainedOriginalDistance21 < 0x2000) {
                Level41_83DDCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
                if ((Level41_83DDCCountTimerDownView1(privateRecord20, 4) != 0) &&
                    (Level41_83DDCData6E344View1 != 1) &&
                    (Level41_83DDCAbsoluteByteAngleDeltaView1(
                         (int)(Level41_83DDCData6E040View1 << 0x10) >> 0x14,
                         Level41_83DDCPlanarHeadingLookupView1(
                             Level41_83DDCField(ownerRecord17, int*, 0xC) -
                                 Level41_83DDCData6E020View1,
                             Level41_83DDCField(ownerRecord17, int*, 0x10) -
                                 Level41_83DDCData6E024View1,
                             0)) < 0x16) &&
                    (Level41_83DDCAbsoluteByteAngleDeltaView1(
                         Level41_83DDCPlanarHeadingLookupView1(
                             Level41_83DDCField(retainedResultFlagBaseOrTarget16, int*, 0) -
                                 Level41_83DDCField(ownerRecord17, int*, 0xC),
                             Level41_83DDCField(retainedResultFlagBaseOrTarget16, int*, 4) -
                                 Level41_83DDCField(ownerRecord17, int*, 0x10),
                             0),
                         Level41_83DDCField(ownerRecord17, unsigned char*, 0x46)) < 0xA)) {
                    Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 1U;
                    Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 1);
                    Level41_83DDCField(privateRecord20, int*, 0) = 0x96;
                }
                goto produceOriginalPosition630;
            } else {
                MATCHING_KEEP_CLOBBER(ownerRecord17, "$16");
                retainedResultFlagBaseOrTarget16 = (int)ownerRecord17 + 12;
                if (retainedOriginalDistance21 < 0x36B0) {
                    temporaryWord2 = Level41_83DDCField(privateRecord20, void**, 4);
                    if (temporaryWord2 != 0) {
                        temporaryWord13 = Level41_83DDCData743C8View1(temporaryWord2);
                        temporaryWord3 = Level41_83DDCField(privateRecord20, void**, 4);
                        if (temporaryWord13 != Level41_83DDCField(temporaryWord3, short*, 2)) {
                            Level41_83DDCField(temporaryWord3, short*, 2) = temporaryWord13;
                            Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                        }
                    }
                }
            }
            goto callOriginalPreparedPosition631;
        case 20:
            retainedOriginalDistance21 = Level41_83DDCApproximatePlanarDistanceView1(
                ownerRecord17 + 0xC, (int)&Level41_83DDCData70328View1);
            temporaryWord18 = Level41_83DDCField(privateRecord20, void**, 4);
            temporaryWord14 = (Level41_83DDCField(temporaryWord18, short*, 2) * 0x10) +
                              Level41_83DDCField(temporaryWord18, int*, 0xC);
            Level41_83DDCTurnMobyTowardHeadingView1(
                ownerRecord17,
                Level41_83DDCPlanarHeadingLookupView1(
                    Level41_83DDCField(temporaryWord14, int*, 0) -
                        Level41_83DDCField(ownerRecord17, int*, 0xC),
                    Level41_83DDCField(temporaryWord14, int*, 4) -
                        Level41_83DDCField(ownerRecord17, int*, 0x10),
                    0),
                4, 2, 1, 0);
            Level41_83DDCResolveMobyYawStepView1(ownerRecord17, 0x64, 0, 0, 0);
            if ((Level41_83DDCCountTimerDownView1(privateRecord20, 4) != 0) &&
                (Level41_83DDCData6E344View1 != 1) && (retainedOriginalDistance21 < 0x1800) &&
                (Level41_83DDCAbsoluteByteAngleDeltaView1(
                     (int)(Level41_83DDCData6E040View1 << 0x10) >> 0x14,
                     Level41_83DDCPlanarHeadingLookupView1(
                         Level41_83DDCField(ownerRecord17, int*, 0xC) - Level41_83DDCData6E020View1,
                         Level41_83DDCField(ownerRecord17, int*, 0x10) -
                             Level41_83DDCData6E024View1,
                         0)) < 0x16) &&
                (Level41_83DDCAbsoluteByteAngleDeltaView1(
                     Level41_83DDCPlanarHeadingLookupView1(
                         Level41_83DDCField((int)&Level41_83DDCData70328View1, int*, 0) -
                             Level41_83DDCField(ownerRecord17, int*, 0xC),
                         Level41_83DDCField((int)&Level41_83DDCData70328View1, int*, 4) -
                             Level41_83DDCField(ownerRecord17, int*, 0x10),
                         0),
                     Level41_83DDCField(ownerRecord17, unsigned char*, 0x46)) < 0xA)) {
                Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 1U;
                Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 1);
                Level41_83DDCField(privateRecord20, int*, 0) = 0x96;
                Level41_83DDCField(Level41_83DDCField(privateRecord20, void**, 4), short*, 2) = -1;
            }
            temporaryWord8 = Level41_83DDCField(privateRecord20, void**, 4);
            temporaryWord19 =
                Level41_83DDCApproximatePlanarDistanceView1(
                    ownerRecord17 + 0xC,
                    Level41_83DDCField(temporaryWord8, int*, 0xC) +
                        (Level41_83DDCField(temporaryWord8, short*, 2) * 0x10)) < 0x200;
            goto testOriginalStateZero605;
        case 1:
            Level41_83DDCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            if (Level41_83DDCData6C770View1 != 0) {
                Level41_83DDCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
                if ((({
                         argumentWord4 = (int)ownerRecord17 + 12;
                         retainedResultFlagBaseOrTarget16 = (int)&Level41_83DDCData70328View1;
                         Level41_83DDCApproximatePlanarDistanceView1(
                             argumentWord4, retainedResultFlagBaseOrTarget16);
                     }) < 0x2000) &&
                    (Level41_83DDCData6E344View1 != 1) &&
                    (Level41_83DDCAbsoluteByteAngleDeltaView1(
                         (int)Level41_83DDCField(ownerRecord17, unsigned char*, 0x46),
                         Level41_83DDCPlanarHeadingLookupView1(
                             Level41_83DDCField(retainedResultFlagBaseOrTarget16, int*, 0) -
                                 Level41_83DDCField(ownerRecord17, int*, 0xC),
                             Level41_83DDCField(retainedResultFlagBaseOrTarget16, int*, 4) -
                                 Level41_83DDCField(ownerRecord17, int*, 0x10),
                             0)) < 0xA) &&
                    (Level41_83DDCAbsoluteByteAngleDeltaView1(
                         (int)(Level41_83DDCData6E040View1 << 0x10) >> 0x14,
                         Level41_83DDCPlanarHeadingLookupView1(
                             Level41_83DDCField(ownerRecord17, int*, 0xC) -
                                 Level41_83DDCData6E020View1,
                             Level41_83DDCField(ownerRecord17, int*, 0x10) -
                                 Level41_83DDCData6E024View1,
                             0)) < 0x16)) {
                    Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 2U;
                    Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 2);
                    MATCHING_KEEP_CLOBBER(ownerRecord17, "$16");
                    retainedResultFlagBaseOrTarget16 = (int)ownerRecord17 + 12;
                } else {
                    Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 3U;
                    Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 3);
                    MATCHING_KEEP_CLOBBER(ownerRecord17, "$16");
                    retainedResultFlagBaseOrTarget16 = (int)ownerRecord17 + 12;
                }
            } else {
                goto produceOriginalPosition630;
            }
            goto callOriginalPreparedPosition631;
        case 2:
            rawWord2 = Level41_83DDCReadSelectedFrameScalarView1(ownerRecord17);
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 4;
            argumentWord6 = 2;
            argumentWord7 = 1;
            __asm__(""
                    : "=r"(argumentWord7)
                    : "0"(argumentWord7), "r"(rawWord2), "r"(argumentWord4), "r"(argumentWord5),
                      "r"(argumentWord6)
                    : "$16");
            retainedResultFlagBaseOrTarget16 = rawWord2;
            Level41_83DDCTurnMobyTowardPlayerView1(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7);
            retainedResultFlagBaseOrTarget16 = retainedResultFlagBaseOrTarget16 < 24;
            if (retainedResultFlagBaseOrTarget16)
                goto continueOriginalStateTwo566;
            if (Level41_83DDCField(ownerRecord17, unsigned char*, 73) == 1) {
                retainedSpawnedRecord18 = Level41_83DDCDataSpawnMobyView1(0x289, ownerRecord17);
                MATCHING_KEEP(retainedSpawnedRecord18);
                if (retainedSpawnedRecord18 != 0) {
                    retainedSpawnedPrivate19 =
                        Level41_83DDCField(retainedSpawnedRecord18, void**, 0);
                    Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) = 2U;
                    Level41_83DDCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 5);
                    __asm__ volatile("" ::: "$16", "memory");
                    argumentWord4 = (int)ownerRecord17;
                    argumentWord5 = 2;
                    __asm__(""
                            : "=r"(argumentWord5)
                            : "0"(argumentWord5), "r"(argumentWord4)
                            : "$16");
                    retainedResultFlagBaseOrTarget16 = retainedSpawnedRecord18 + 12;
                    Level41_83DDCInterpolateMobyVertexView1(argumentWord4, argumentWord5,
                                                            retainedResultFlagBaseOrTarget16);
                    Level41_83DDCField(retainedSpawnedRecord18, signed char*, 0x4F) = 0xC;
                    MATCHING_BARRIER_VOLATILE("memory");
                    rawWord2 = Level41_83DDCField((int)&Level41_83DDCData70328View1, int*, 0);
                    rawWord3 = Level41_83DDCField(retainedSpawnedRecord18, int*, 12);
                    rawWord2 -= rawWord3;
                    Level41_83DDCField(retainedSpawnedPrivate19, int*, 0) = rawWord2;
                    rawWord2 = Level41_83DDCField((int)&Level41_83DDCData70328View1, int*, 4);
                    rawWord3 = Level41_83DDCField(retainedSpawnedRecord18, int*, 16);
                    argumentWord5 = 1;
                    rawWord2 -= rawWord3;
                    Level41_83DDCField(retainedSpawnedPrivate19, int*, 4) = rawWord2;
                    rawWord2 = Level41_83DDCField((int)&Level41_83DDCData70328View1, int*, 8);
                    rawWord3 = Level41_83DDCField(retainedSpawnedRecord18, int*, 20);
                    __asm__ volatile("" ::: "$4", "memory");
                    argumentWord4 = retainedSpawnedPrivate19;
                    rawWord2 -= rawWord3;
                    Level41_83DDCField(retainedSpawnedPrivate19, int*, 8) = rawWord2;
                    rawWord2 = Level41_83DDCMeasureVectorLengthView1(argumentWord4, argumentWord5);
                    Level41_83DDCScaleVectorRatioQ15View1(retainedSpawnedPrivate19, rawWord2, 200);
                    Level41_83DDCAddVectorView1(retainedResultFlagBaseOrTarget16,
                                                retainedSpawnedPrivate19,
                                                retainedResultFlagBaseOrTarget16);
                    Level41_83DDCAddVectorView1(retainedResultFlagBaseOrTarget16,
                                                retainedSpawnedPrivate19,
                                                retainedResultFlagBaseOrTarget16);
                    temporaryWord9 =
                        Level41_83DDCDataSpawnParticleView1(1, 0xC, retainedSpawnedRecord18, 1);
                    if (temporaryWord9 != 0) {
                        Level41_83DDCField(temporaryWord9, unsigned char*, 0xC) = 0xC0;
                        Level41_83DDCField(temporaryWord9, unsigned char*, 0xD) = 0xC0;
                        Level41_83DDCField(temporaryWord9, unsigned char*, 0xE) = 0xC0;
                    }
                    Level41_83DDCField(retainedSpawnedPrivate19, int*, 0xC) = 0xB4;
                }
            }
        continueOriginalStateTwo566:
            retainedResultFlagBaseOrTarget16 = ownerRecord17 + 0xC;
            if (Level41_83DDCData6C770View1 != 0) {
                temporaryWord4 = Level41_83DDCField(privateRecord20, void**, 4);
                if (temporaryWord4 != 0) {
                    temporaryWord10 = Level41_83DDCData743C8View1(temporaryWord4);
                    temporaryWord5 = Level41_83DDCField(privateRecord20, void**, 4);
                    if (temporaryWord10 != Level41_83DDCField(temporaryWord5, short*, 2)) {
                        Level41_83DDCField(temporaryWord5, short*, 2) = temporaryWord10;
                        Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0x14U;
                    }
                }
                Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 0);
                Level41_83DDCField(ownerRecord17, unsigned char*, 0x49) = 1U;
                goto produceOriginalPosition630;
            }
            goto callOriginalPreparedPosition631;
        case 3:
            Level41_83DDCTurnMobyTowardPlayerView1(ownerRecord17, 4, 2, 1);
            temporaryWord19 = Level41_83DDCData6C770View1;
        testOriginalStateZero605:
            if (temporaryWord19 != 0) {
                Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) = 0U;
                Level41_83DDCRequestMobyAnimationView1(ownerRecord17, 0);
                retainedResultFlagBaseOrTarget16 = ownerRecord17 + 0xC;
            } else {
                goto produceOriginalPosition630;
            }
            goto callOriginalPreparedPosition631;
        case 4:
            if (({
                    rawWord2 = Level41_83DDCUpdateMobyMotionDescriptorView1(ownerRecord17,
                                                                            privateRecord20 + 8);
                    MATCHING_KEEP_CLOBBER(ownerRecord17, "$16");
                    retainedResultFlagBaseOrTarget16 = (int)ownerRecord17 + 12;
                    rawWord2;
                }) == 256) {
                Level41_83DDCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 4);
                Level41_83DDCMarkMobyCollectionBitView1(ownerRecord17);
                Level41_83DDCEmitMobyVertexParticlesView1(ownerRecord17, 0x20);
                Level41_83DDCDeleteMobyView1(ownerRecord17);
                return;
            }
            goto callOriginalPreparedPosition631;
        default:
            goto produceOriginalPosition630;
    }
produceOriginalPosition630:
    MATCHING_KEEP(ownerRecord17);
    retainedResultFlagBaseOrTarget16 = (int)ownerRecord17 + 12;
callOriginalPreparedPosition631:
    Level41_83DDCField(ownerRecord17, int*, 0x14) =
        (int)(Level41_83DDCField(ownerRecord17, int*, 0x14) + 0x400);
    Level41_83DDCQueryWorldHeightView1(retainedResultFlagBaseOrTarget16, 0x2000);
    Level41_83DDCField(ownerRecord17, int*, 0x14) =
        (int)(Level41_83DDCField(ownerRecord17, int*, 0x14) - 0x400);
    if (Level41_83DDCField(ownerRecord17, unsigned char*, 0x48) != 4) {
        {
            int signedDivision10Magic = 0x66666667;
            __asm__("" : "=r"(ownerRecord17) : "0"(ownerRecord17), "r"(signedDivision10Magic));
            rawWord3 = 10240;
            rawWord3 -= retainedOriginalDistance21;
            rawWord2 = rawWord3 / 10;
        }
        argumentWord4 = retainedResultFlagBaseOrTarget16;
        argumentWord5 = (int)&Level41_83DDCData70328View1;
        retainedResultFlagBaseOrTarget16 = rawWord2 + 256;
        rawWord2 = Level41_83DDCApproximatePlanarDistanceView1(argumentWord4, argumentWord5);
        if (rawWord2 < 8192) {
            argumentWord5 = (int)&Level41_83DDCData71908View1;
            rawWord3 = Level41_83DDCField(ownerRecord17, int*, 20);
            rawWord2 = Level41_83DDCField(argumentWord5, int*, 0);
            argumentWord4 = rawWord3 - rawWord2;
            if (argumentWord4 < retainedResultFlagBaseOrTarget16) {
                rawWord2 = rawWord3 + 30;
                Level41_83DDCField(ownerRecord17, int*, 20) = rawWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                rawWord3 = Level41_83DDCField(argumentWord5, int*, 0);
                rawWord2 -= rawWord3;
                if (retainedResultFlagBaseOrTarget16 < rawWord2) {
                    rawWord2 = rawWord3 + retainedResultFlagBaseOrTarget16;
                    Level41_83DDCField(ownerRecord17, int*, 20) = rawWord2;
                }
                goto callOriginalCommonHelpers707;
            }
            rawWord2 = retainedResultFlagBaseOrTarget16 < argumentWord4;
            MATCHING_KEEP(rawWord2);
            if (rawWord2) {
                rawWord2 = rawWord3 - 30;
                Level41_83DDCField(ownerRecord17, int*, 20) = rawWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                rawWord3 = Level41_83DDCField(argumentWord5, int*, 0);
                rawWord2 -= rawWord3;
                if (rawWord2 < retainedResultFlagBaseOrTarget16) {
                    rawWord2 = rawWord3 + retainedResultFlagBaseOrTarget16;
                    Level41_83DDCField(ownerRecord17, int*, 20) = rawWord2;
                }
            }
        } else {
            argumentWord4 = (int)&Level41_83DDCData71908View1;
            rawWord3 = Level41_83DDCField(ownerRecord17, int*, 20);
            rawWord2 = Level41_83DDCField(argumentWord4, int*, 0);
            rawWord2 = rawWord3 - rawWord2;
            if (rawWord2 >= 257) {
                rawWord2 = rawWord3 - 30;
                Level41_83DDCField(ownerRecord17, int*, 20) = rawWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                rawWord3 = Level41_83DDCField(argumentWord4, int*, 0);
                rawWord2 -= rawWord3;
                if (rawWord2 < 256) {
                    rawWord2 = rawWord3 + 256;
                    Level41_83DDCField(ownerRecord17, int*, 20) = rawWord2;
                }
            }
        }
    }
callOriginalCommonHelpers707:
    Level41_83DDCRefreshMobyPackedQueryFieldView1(ownerRecord17);
    Level41_83DDCRefreshMobySpatialGridAndBasisView1(ownerRecord17, 2);
    return;
}
#undef Level41_83DDCField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_41/moby/func_level_41_80084924.s SHA256 f9d22c6f605d202d273231b5b506781689e5ed9d052962480ffb6efca4d8f596. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level41_84924Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern short Level41_84924_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level41_84924_D_80065920[0x100] __asm__("D_80065920");
extern Spyro Level41_84924_D_80070328 __asm__("D_80070328");
void Level41_84924RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Level41_84924TurnMobyTowardPlayer(Moby* owner, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level41_84924CountTimerDown(void*, int) __asm__("func_800359A4");
int Level41_84924RandBetween(int low, int high) __asm__("func_8003636C");
void Level41_84924EmitMobyVertexParticles() __asm__("func_800369B8");
void Level41_84924MarkMobyCollectionBit(Moby* moby) __asm__("func_8003BA00");
int Level41_84924PlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
extern int Level41_84924PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level41_84924ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern void Level41_84924CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level41_84924AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level41_84924AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level41_84924ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level41_84924DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level41_84924RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
extern int Level41_84924ReadSelectedFrameScalar(Moby*) __asm__("func_80055E84");

int Level41_84924QueryWorldSphereWithOptions() __asm__("func_80019138");
/* extern */
unsigned char Level41_84924SetMobyAnimation() __asm__("func_80034F80");
/* extern */
unsigned char Level41_84924SpawnMobyFromValueSelector() __asm__("func_80036A68");
/* extern */
unsigned char Level41_84924InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern int Level41_84924_D_8006C640 __asm__("D_8006C640");
extern int Level41_84924_D_8006C770 __asm__("D_8006C770");
extern Vector3D Level41_84924_D_8006E020 __asm__("D_8006E020");
extern int Level41_84924_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level41_84924_D_8006E040 __asm__("D_8006E040");
extern int Level41_84924_D_8006E1D4 __asm__("D_8006E1D4");
extern int Level41_84924_D_8006E1D8 __asm__("D_8006E1D8");

void func_level_41_80084924(Moby* inputOwner) {
    register Moby* owner __asm__("$18") = inputOwner;
    /* Original frame 0xA0 and every scratch offset are retained.
     * Spyro vector-minus-0x98 and table step0x20 are byte offsets.
     * Trig producers are signed LH;
      raw25>>10 and75>>11 arithmetic remains.
     * S4 holds SP+0x28 before becoming the trig-table pointer;
      loop helper
     * argument5 is independently rebuilt from SP+0x28 after the table load.
     * Child/private S1 lifetimes, separate scratch zero stores and shared
     * state/call blocks retain original instruction order and targets.
     * Empty constraints emit no instructions or opcode patches.
     * Units/fixed-point domains, cadence, helper meanings and synchronized
     * runtime chains remain unresolved. Machine identity only. */
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
        int sp58;
        int sp5C;
        int sp60;
        unsigned char pad64[4];
        Vector3D sp68;
        unsigned char pad74[4];
    } scratch;

    register int finalArgument5 __asm__("$5");
    register void* argument4 __asm__("$4");
    register void* argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register int (*particleCall3)() __asm__("$3");
    register int word2 __asm__("$2");
    register int trig3 __asm__("$3");
    register Vector3D* vector20 __asm__("$20");
    register Vector3D* vector17 __asm__("$17");
    register Moby* child17 __asm__("$17");
    register Moby* loopChild17 __asm__("$17");
    Moby* spawnedMoby;
    register Vector3D* ownerPosition16 __asm__("$16");
    register Vector3D* ownerPosition16b __asm__("$16");
    register Vector3D* ownerPosition16c __asm__("$16");
    register short* trigTable20 __asm__("$20");
    register int trigWord3 __asm__("$3");
    register int trigWord4 __asm__("$4");
    int temp_a0;
    register int helperResult19 __asm__("$19");
    register int angleBase19 __asm__("$19");
    register int referenceAngle23 __asm__("$23");
    int temp_v0_7;
    register int counter19 __asm__("$19");
    register int height2 __asm__("$2");
    register int scaledTrig2 __asm__("$2");
    int var_v1;
    signed char* temp_v0;
    signed char* temp_v0_3;
    signed char* temp_v0_4;
    unsigned int temp_v0_2;
    register unsigned int counter20 __asm__("$20");
    register int colourWord2 __asm__("$2");
    unsigned char temp_v1;
    unsigned char temp_v1_2;
    unsigned char temp_v1_3;
    unsigned char temp_v1_4;
    unsigned char temp_v1_5;
    register void* childPrivate16 __asm__("$16");
    register void* childPrivate17 __asm__("$17");
    register void* spawnPrivate17 __asm__("$17");
    register void* ownerPrivate21 __asm__("$21");

    temp_v1 = owner->state;
    ownerPrivate21 = owner->mobyTag;
    if (temp_v1 == 0x15) {
        ownerPosition16 = ((void*)((unsigned char*)owner + 0xC));
        Level41_84924AddVector(ownerPosition16, ownerPosition16, ownerPrivate21 + 4);
        Level41_84924Field(ownerPrivate21, int*, 0xC) =
            (int)(Level41_84924Field(ownerPrivate21, int*, 0xC) - 8);
        if (((unsigned char)owner->colour.a >= 0x32U) || (owner->colour.r != 0)) {
            scratch.sp18 = 0;
            scratch.sp1C = 0;
            scratch.sp20 = 2;
            temp_v0 = SpawnParticle(1, 0x3C, ownerPosition16, (Vector3D*)&scratch.sp18);
            if (temp_v0 != 0) {
                Level41_84924Field(temp_v0, unsigned char*, 0xC) = 0xFF;
                Level41_84924Field(temp_v0, signed char*, 2) = 0xC;
                Level41_84924Field(temp_v0, signed char*, 0xD) = 0;
                Level41_84924Field(temp_v0, signed char*, 0xE) = 0;
                Level41_84924Field(temp_v0, signed char*, 0xA) = 0x14;
            }
            temp_v1_2 = owner->colour.a;
            if (temp_v1_2 >= 0x32U) {
                owner->colour.a = temp_v1_2 - 1;
            } else {
                temp_v1_3 = owner->colour.r;
                temp_v0_2 = temp_v1_3 & 0xFF;
                if (temp_v0_2 != 0) {
                    if (temp_v0_2 < 0x11U) {
                        owner->colour.r = 0;
                    } else {
                        owner->colour.r = temp_v1_3 - 0x10;
                    }
                }
            }
        }
        owner->position.z += 0x1F4;
        if ((Level41_84924CountTimerDown(ownerPrivate21 + 2, 2) != 0) ||
            (Level41_84924QueryWorldSphereWithOptions(((void*)((unsigned char*)owner + 0xC)), 0x100,
                                                      1, 0, 0, 0) != 0)) {
            owner->position.z -= 0x1F4;
            Level41_84924RefreshMobySpatialGridAndBasis(owner, 4);
            argument4 = owner;
            MATCHING_OBSERVE(argument4);
            finalArgument5 = 0x18;
            goto call369B8And55B18;
        }
        owner->position.z -= 0x1F4;
        return;
    }
    if (temp_v1 != 0x14) {
        word2 = owner->damageFlags;
        word2 &= 0x10000;
        MATCHING_KEEP_CLOBBER(word2, "$4");
        argument4 = owner;
        if (word2) {
            owner->state = 0x14;
            Level41_84924RequestMobyAnimation(argument4, 0);
            Level41_84924Field(ownerPrivate21, short*, 2) = 0;
            owner->colour.a = 0x31;
            owner->colour.r = 0x80;
        }
    }
    temp_v1_4 = owner->state;
    switch (temp_v1_4) { /* switch 1 */
        case 0:          /* switch 1 */
        case 5:          /* switch 1 */
            if (Level41_84924CountTimerDown(ownerPrivate21, 2) != 0) {
                Level41_84924CopyVector((Vector3D*)&scratch.sp18,
                                        &Level41_84924_D_80070328.unk7a[3]);
                scratch.sp18 *= 0x14;
                scratch.sp1C *= 0x14;
                scratch.sp20 *= 0x14;
                Level41_84924ShiftVectorRightTowardZero((Vector3D*)&scratch.sp18, 6);
                Level41_84924AddVector(
                    (Vector3D*)&scratch.sp18, (Vector3D*)&scratch.sp18,
                    (Vector3D*)((unsigned char*)&Level41_84924_D_80070328.unk7a[3] - 0x98));
                if (Level41_84924ApproximatePlanarDistance(&owner->position,
                                                           (Vector3D*)&scratch.sp18) < 0x2000) {
                    owner->state = 1;
                    Level41_84924RequestMobyAnimation(owner, 1);
                }
            }
            if (Level41_84924_D_8006C770 != 0) {
                if (owner->state != 0)
                    return;
                word2 = 5;
                goto storeState5AndCall34F40;
            }
        default: /* switch 1 */
            return;
        case 1: /* switch 1 */
            Level41_84924TurnMobyTowardPlayer(owner, 4, 1, 1);
            if (Level41_84924_D_8006C770 != 0) {
                owner->state = 3;
                Level41_84924RequestMobyAnimation(owner, 3);
                return;
            }
            break;
        case 2: /* switch 1 */
            word2 = Level41_84924ReadSelectedFrameScalar(owner);
            argument4 = owner;
            argument5 = (void*)4;
            argument6 = 1;
            argument7 = 1;
            __asm__(""
                    : "=r"(argument4), "=r"(argument5), "=r"(argument6), "=r"(argument7)
                    : "0"(argument4), "1"(argument5), "2"(argument6), "3"(argument7), "r"(word2)
                    : "$19");
            helperResult19 = word2;
            Level41_84924TurnMobyTowardPlayer(argument4, argument5, argument6, argument7);
            Level41_84924RefreshMobySpatialGridAndBasis(owner, 5);
            argument4 = owner;
            argument5 = 0;
            MATCHING_KEEP2_CLOBBER(argument4, argument5, "$20");
            vector20 = &scratch.sp28;
            Level41_84924InterpolateMobyVertex(argument4, argument5, vector20);
            if (helperResult19 < 0x14) {
                vector17 = &scratch.sp38;
                argument4 = vector17;
                MATCHING_OBSERVE_CLOBBER(argument4, "$16");
                ownerPosition16b = &owner->position;
                Level41_84924CopyVector(vector17, ownerPosition16b);
                Level41_84924CopyVector(ownerPosition16b, vector20);
                SpawnParticle(1, 0xC, (Vector3D*)owner, (Vector3D*)5);
                Level41_84924CopyVector(ownerPosition16b, vector17);
                scratch.sp48 = 0;
                scratch.sp4C = 0;
                word2 = helperResult19 % 3;
                __asm__("" : "=r"(word2) : "0"(word2), "r"(helperResult19) : "memory");
                particleCall3 = (int (*)())SpawnParticle;
                MATCHING_KEEP2(word2, particleCall3);
                word2 += 1;
                scratch.sp50 = word2;
                temp_v0_3 =
                    (signed char*)particleCall3(1, 0x3C, vector20, (Vector3D*)&scratch.sp48);
                if (temp_v0_3 != 0) {
                    Level41_84924Field(temp_v0_3, signed char*, 0xA) = 0x1E;
                    Level41_84924Field(temp_v0_3, signed char*, 2) = 0xC;
                }
            } else {
                ownerPosition16c = &owner->position;
                if (owner->substate == 0) {
                    vector17 = &scratch.sp68;
                    Level41_84924CopyVector(vector17, ownerPosition16c);
                    Level41_84924CopyVector(ownerPosition16c, vector20);
                    temp_v0_4 = SpawnParticle(3, 0xC, (Vector3D*)owner, (Vector3D*)5);
                    if (temp_v0_4 != 0) {
                        Level41_84924Field(temp_v0_4, signed char*, 0xA) = 0x64;
                    }
                    Level41_84924CopyVector(ownerPosition16c, vector17);
                    child17 = SpawnMoby(0x114, owner);
                    MATCHING_KEEP(child17);
                    if (child17 != 0) {
                        argument4 = &child17->position;
                        MATCHING_OBSERVE(argument4);
                        child17->angle.pitch = 0x40;
                        child17->unknown4 = 6;
                        child17->size = 0xC;
                        childPrivate17 = child17->mobyTag;
                        Level41_84924CopyVector(argument4, vector20);
                        var_v1 = Level41_84924ApproximatePlanarDistance(&Level41_84924_D_8006E020,
                                                                        ownerPosition16c);
                        if (var_v1 > 0x7FFF) {
                            var_v1 = 0x7FFF;
                        }
                        Level41_84924_D_8006E1D4 = (int)((0x8000 - var_v1) << 0xC) >> 0xF;
                        Level41_84924_D_8006E1D8 = 0x14;
                        owner->substate = 2;
                        Level41_84924Field(childPrivate17, int*, 0x10) = 0x64;
                    }
                    counter19 = 0;
                    trigTable20 = Level41_84924_D_80065920;
                    do {
                        loopChild17 = SpawnMoby(0x114, owner);
                        MATCHING_KEEP(loopChild17);
                        if (loopChild17 != 0) {
                            argument4 = &loopChild17->position;
                            MATCHING_OBSERVE(argument4);
                            trig3 = *trigTable20;
                            childPrivate16 = loopChild17->mobyTag;
                            MATCHING_OBSERVE(loopChild17);
                            scratch.sp58 = (int)(trig3 * 0x19) >> 0xA;
                            trig3 = Level41_84924Field(Level41_84924_D_800658A0, short*,
                                                       counter19 << 5);
                            MATCHING_KEEP_CLOBBER(trig3, "$5");
                            argument5 = &scratch.sp28;
                            MATCHING_OBSERVE2(argument5, trig3);
                            *(volatile int*)&scratch.sp60 = 0;
                            __asm__("" : : "m"(scratch.sp60) : "$2");
                            scratch.sp5C = (trig3 * 0x19) >> 0xA;
                            loopChild17->unknown3[0] = 0;
                            loopChild17->lowDrawDistance = 0;
                            loopChild17->drawn = 0;
                            Level41_84924CopyVector(argument4, argument5);
                            loopChild17->state = 1;
                            Level41_84924CopyVector((Vector3D*)childPrivate16,
                                                    (Vector3D*)&scratch.sp58);
                            Level41_84924Field(childPrivate16, int*, 0xC) = 0;
                        }
                        counter19 += 1;
                        trigTable20 = (short*)((unsigned char*)trigTable20 + 0x20);
                    } while (counter19 < 0x10);
                }
            }
            if (Level41_84924_D_8006C770 != 0) {
                owner->substate = 0;
                owner->state = 0;
                Level41_84924RequestMobyAnimation(owner, 0);
                Level41_84924Field(ownerPrivate21, short*, 0) = 0x78;
                return;
            }
            break;
        case 3: /* switch 1 */
            Level41_84924TurnMobyTowardPlayer(owner, 4, 1, 1);
            Level41_84924CopyVector((Vector3D*)&scratch.sp48, &Level41_84924_D_80070328.unk7a[3]);
            scratch.sp48 *= 0x14;
            scratch.sp4C *= 0x14;
            scratch.sp50 *= 0x14;
            Level41_84924ShiftVectorRightTowardZero((Vector3D*)&scratch.sp48, 6);
            Level41_84924AddVector(
                (Vector3D*)&scratch.sp48, (Vector3D*)&scratch.sp48,
                (Vector3D*)((unsigned char*)&Level41_84924_D_80070328.unk7a[3] - 0x98));
            temp_v0_7 =
                Level41_84924ApproximatePlanarDistance(&owner->position, (Vector3D*)&scratch.sp48);
            if ((temp_v0_7 < 0xC00) &&
                (Level41_84924AbsoluteByteAngleDelta(
                     (int)owner->angle.yaw,
                     Level41_84924PlanarHeadingLookup(
                         Level41_84924_D_80070328.position.x - owner->position.x,
                         Level41_84924_D_80070328.position.y - owner->position.y, 0)) < 8) &&
                (Level41_84924AbsoluteByteAngleDelta(
                     (int)(Level41_84924_D_8006E040 << 0x10) >> 0x14,
                     Level41_84924PlanarHeadingLookup(
                         owner->position.x - Level41_84924_D_8006E020.x,
                         owner->position.y - Level41_84924_D_8006E024, 0)) < 0x18)) {
                owner->state = 2;
                Level41_84924RequestMobyAnimation(owner, 2);
                return;
            }
            if (temp_v0_7 >= 0x2001) {
                owner->state = 4;
                Level41_84924RequestMobyAnimation(owner, 4);
                return;
            }
            break;
        case 4: /* switch 1 */
            word2 = Level41_84924_D_8006C770;
            if (!word2)
                return;
            word2 = 5;
        storeState5AndCall34F40:
            __asm__("" : : "r"(word2), "m"(owner->state));
            owner->state = word2;
            Level41_84924RequestMobyAnimation(owner, 5);
            return;
        case 20: /* switch 1 */
            temp_v1_5 = owner->colour.a;
            if (temp_v1_5 < 0x3AU) {
                owner->colour.a = temp_v1_5 + 1;
                return;
            }
            if ((unsigned char)owner->colour.r < 0xFFU) {
                if (!(Level41_84924_D_8006C640 & 1)) {
                    height2 = owner->position.z + 0x32;
                } else {
                    height2 = owner->position.z - 0x32;
                }
                owner->position.z = height2;
                __asm__("" : : "m"(owner->position.z) : "$2");
                word2 = owner->colour.r;
                __asm__("" : "=r"(word2) : "0"(word2), "m"(owner->position.z));
                colourWord2 = word2 + 0x20;
                owner->colour.r = colourWord2;
                if ((unsigned int)(colourWord2 & 0xFF) >= 0xDFU) {
                    argument6 = 0;
                    MATCHING_OBSERVE_CLOBBER(argument6, "$20");
                    counter20 = 0;
                    referenceAngle23 =
                        (Level41_84924PlanarHeadingLookup(
                             Level41_84924_D_80070328.position.x - owner->position.x,
                             Level41_84924_D_80070328.position.y - owner->position.y, 0) +
                         0x80) &
                        0xFF;
                    angleBase19 = referenceAngle23 - 0xA;
                    owner->colour.r = 0xFF;
                    do {
                        spawnedMoby = SpawnMoby(0x22B, owner);
                        if (spawnedMoby != 0) {
                            spawnPrivate17 = spawnedMoby->mobyTag;
                            spawnedMoby->state = 0x15;
                            Level41_84924Field(spawnPrivate17, short*, 2) = 0x5A;
                            Level41_84924SetMobyAnimation(spawnedMoby, counter20 + 6);
                            spawnedMoby->colour.r = 0xFF;
                            spawnedMoby->colour.a = 0x3A;
                            switch (counter20) { /* switch 2 */
                                case 0:          /* switch 2 */
                                    Level41_84924Field(spawnPrivate17, int*, 4) = 0;
                                    Level41_84924Field(spawnPrivate17, int*, 8) = 0;
                                    Level41_84924Field(spawnPrivate17, int*, 0xC) = 0xC8;
                                    break;
                                case 1: /* switch 2 */
                                    Level41_84924Field(spawnPrivate17, int*, 4) =
                                        (int)((int)(Level41_84924_D_80065920
                                                        [(angleBase19 +
                                                          Level41_84924RandBetween(0, 0x14)) &
                                                         0xFF] *
                                                    0x19) >>
                                              0xA);
                                    trigWord3 = Level41_84924_D_800658A0
                                        [(angleBase19 + Level41_84924RandBetween(0, 0x14)) & 0xFF];
                                    Level41_84924Field(spawnPrivate17, int*, 0xC) = 0x96;
                                    scaledTrig2 = (int)(trigWord3 * 0x19) >> 0xA;
                                    goto storeScaledTrig;
                                case 2: /* switch 2 */
                                    Level41_84924Field(spawnPrivate17, int*, 4) =
                                        (int)((int)(Level41_84924_D_80065920
                                                        [(angleBase19 +
                                                          Level41_84924RandBetween(0, 0x14)) &
                                                         0xFF] *
                                                    0x4B) >>
                                              0xB);
                                    trigWord4 = Level41_84924_D_800658A0
                                        [(angleBase19 + Level41_84924RandBetween(0, 0x14)) & 0xFF];
                                    Level41_84924Field(spawnPrivate17, int*, 0xC) = 0x64;
                                    goto scaleTrig75;
                                case 3: /* switch 2 */
                                    Level41_84924Field(spawnPrivate17, int*, 4) =
                                        (int)((int)(Level41_84924_D_80065920
                                                        [(angleBase19 +
                                                          Level41_84924RandBetween(0, 0x14)) &
                                                         0xFF] *
                                                    0x4B) >>
                                              0xB);
                                    trigWord4 = Level41_84924_D_800658A0
                                        [(angleBase19 + Level41_84924RandBetween(0, 0x14)) & 0xFF];
                                    Level41_84924Field(spawnPrivate17, int*, 0xC) = 0x96;
                                    goto scaleTrig75;
                                case 4: /* switch 2 */
                                    temp_a0 = (referenceAngle23 + 0x24) & 0xFF;
                                    Level41_84924Field(spawnPrivate17, int*, 4) =
                                        (int)((int)(Level41_84924_D_80065920[temp_a0] * 0x4B) >>
                                              0xB);
                                    trigWord4 = Level41_84924_D_800658A0[temp_a0];
                                    Level41_84924Field(spawnPrivate17, int*, 0xC) = 0;
                                    Level41_84924Field(spawnPrivate17, int*, 4) = 0x4B;
                                scaleTrig75:
                                    scaledTrig2 = (trigWord4 * 0x4B) >> 0xB;
                                storeScaledTrig:
                                    Level41_84924Field(spawnPrivate17, int*, 8) = scaledTrig2;
                                    break;
                            }
                        }
                        counter20 += 1;
                    } while ((int)counter20 < 5);
                    Level41_84924PlayMobySoundEvent(owner, 0, 0);
                    Level41_84924SpawnMobyFromValueSelector(owner, 1, 0, 0);
                    Level41_84924RefreshMobySpatialGridAndBasis(owner, 4);
                    Level41_84924MarkMobyCollectionBit(owner);
                    argument4 = owner;
                    MATCHING_OBSERVE(argument4);
                    finalArgument5 = 0x30;
                call369B8And55B18:
                    Level41_84924EmitMobyVertexParticles(argument4, finalArgument5);
                    Level41_84924DeleteMoby(owner);
                }
            }
            break;
    }
}
#undef Level41_84924Field

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 80085424..800856EC. Original instructions define numeric branches.
 * Rev1 raw562 is discovery only; indirect extra arguments remain unknown. */
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern int D_8006C770;
void func_level_41_80085424(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
    register int* tag __asm__("$17") = moby->mobyTag;
    int angle;
    if (moby->state != 2) {
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
            moby->state = 2;
            func_80034F40(moby, 2);
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
            moby->state = 2;
            func_80034F40(moby, 2);
        }
    }
    switch (moby->state) {
        case 0:
            if (*((unsigned char*)moby + 0x4D) &&
                func_8004F334(&moby->position, (Vector3D*)DecodedCrystalPlayer) < 16384 &&
                func_800359A4(tag + 9, 4) && D_8006C770) {
                tag[9] = func_8003636C(3, 7);
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            break;
        case 1:
            func_80037168(moby, (Vector3D*)(tag + 3), 1);
            if (D_8006C770 && --tag[9] <= 0) {
                tag[9] = func_8003636C(30, 90);
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        case 2:
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
/* SCUS-94467 USA Rev0, original800856F0.
* AI generated; not human reviewed. All691 original instructions,26 switch
* selectors and every actual target must match:717 original owned words.
* Frame90hex=144 saves S0..S7/FP/RA;SP18..67 preserves original storage.
* Independently matched level41 function800864C0 supplies four verified
* subtrees. Target entry,states22/25/1/2 and state3 prefix are independently
* derived from this function's original words;state0 retains argument75.
* Signed candidate terminator,ten accepted entries,fifty scan iterations,
* independent fallback slot SP60,random selector and complete low32 inverse
* product retain all original producer widths and actual destinations.
* Original631 enters650 with full V0=60 in its delay. The complete later
* child-flag value1 is formed after its own pointer decision674,allowing
* unchanged GCC scheduling to preserve that earlier slot. Read-only compiler
* resource tracing identified the former premature V0 liveness marker.
* Original674 retains its literal1 delay and original child flag/clear stores.
* Particle/vector,global counter,address,call argument and selected-record
* phases preserve their original widths,storage and order. Natural FP is
* an ordinary initialized loop count;no fixed FP or incoming saved reads.
* Empty metadata reads complete initialized values/written fields or clobbers
* dead registers before full producers;it emits no CPU instructions.
* No opcode asm,partial HI/LO,overlapping live fixed aliases or padding reads.
* Compiler/filter/flags remain unchanged. Existing matched timer/angle/spawn
* contracts are reused;raw field units and helper meanings are not invented.
* Confidence is binary identity after every native/linked/actual-target,
* owned-selector and full EXE/every-overlay hash gate. Units/fixed point,
* complete caller/helper chains,cadence beyond invocation,Rev1 mapping and
* synchronized runtime remain open. Next:human review and retail captures.
*/
/* Original assembly SHA256 5034410391e706aaa55a30353b6da5f9b3dd12b4b2edb556d223a16963f40edc */
#define Level41_856F0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level41_856F0RequestMobyAnimationView1() __asm__("func_80034F40");
int Level41_856F0SetMobyAnimationView1() __asm__("func_80034F80");
int Level41_856F0TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Level41_856F0CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level41_856F0ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Level41_856F0RandBetweenView1() __asm__("func_8003636C");
int Level41_856F0EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Level41_856F0PlanarHeadingLookupView1() __asm__("func_8004E880");
int Level41_856F0CopyVectorView1() __asm__("func_8004F178");
int Level41_856F0AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level41_856F0ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level41_856F0RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level41_856F0ReadSelectedFrameScalarView1() __asm__("func_80055E84");
extern int Level41_856F0Data6763CView1 __asm__("D_8006763C");
extern int Level41_856F0Data67640View1 __asm__("D_80067640");
extern int Level41_856F0Data67644View1 __asm__("D_80067644");
extern int Level41_856F0Data6C54CView1 __asm__("D_8006C54C");
extern int Level41_856F0Data6C550View1 __asm__("D_8006C550");
extern int Level41_856F0Data6C640View1 __asm__("D_8006C640");
extern int Level41_856F0Data6C730View1 __asm__("D_8006C730");
extern int Level41_856F0Data6C770View1 __asm__("D_8006C770");
extern int Level41_856F0Data70328View1 __asm__("D_80070328");
extern void* (*Level41_856F0DataSpawnMobyView1)() __asm__("SpawnMoby");
extern void* (*Level41_856F0DataSpawnParticleView1)(int, int, void*, void*)__asm__("SpawnParticle");
void func_level_41_800856F0(void* ownerParameter, int secondArgumentWord) {
    register void* ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        fallbackIndex8 __asm__("$8");
    register int retainedResultOrRecord16 __asm__("$16"),
        retainedCandidateOrScalar17 __asm__("$17"), candidateIndex19 __asm__("$19"),
        privateRecord20 __asm__("$20"), candidateList21 __asm__("$21"),
        acceptedCount22 __asm__("$22"), candidateDistance23 __asm__("$23");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64;
    } originalFrame;
    int candidateLoopCount;
    argumentWord4 = (int)ownerParameter;
    ownerRecord18 = (void*)argumentWord4;
    MATCHING_KEEP(ownerRecord18);
    argumentWord5 = secondArgumentWord;
    rawWord3 = Level41_856F0Field(ownerRecord18, unsigned char*, 0x48);
    privateRecord20 = Level41_856F0Field(ownerRecord18, void**, 0);
    if ((rawWord3 != 1) && (rawWord3 != 0x15)) {
        argumentWord5 = 1;
        if (Level41_856F0Field(ownerRecord18, int*, 0x18) & 0x04000000) {
            rawWord3 = Level41_856F0Field(Level41_856F0Data6C550View1 +
                                              Level41_856F0Field(privateRecord20, int*, 0x14) * 88,
                                          void**, 0);
            Level41_856F0Field(rawWord3, unsigned short*, 2) =
                (unsigned short)(Level41_856F0Field(rawWord3, unsigned short*, 2) - 1);
            rawWord3 = Level41_856F0Field(Level41_856F0Data6C550View1 +
                                              Level41_856F0Field(privateRecord20, int*, 0x14) * 88,
                                          void**, 0);
            Level41_856F0Field(rawWord3, int*, 8) =
                (int)(Level41_856F0Field(rawWord3, int*, 8) + 1);
            rawWord3 = Level41_856F0Field(privateRecord20, int*, 8);
            Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 1;
            Level41_856F0Field(ownerRecord18, int*, 0x14) = rawWord3;
            Level41_856F0SetMobyAnimationView1(ownerRecord18, 1);
            return;
        }
    }
    rawWord2 = Level41_856F0Data6C640View1;
    Level41_856F0Field(ownerRecord18, int*, 0x18) = 0;
    if (rawWord2 && (Level41_856F0Data6C54CView1 == 0)) {
        rawWord3 = (int)&Level41_856F0Data6763CView1;
        MATCHING_KEEP(rawWord3);
        rawWord2 = Level41_856F0Field(rawWord3, int*, 0);
        rawWord2 += 8;
        Level41_856F0Field(rawWord3, int*, 0) = rawWord2;
        rawWord2 = Level41_856F0Data67640View1;
        rawWord3 = Level41_856F0Data67644View1;
        rawWord2 += 8;
        rawWord3 += 8;
        Level41_856F0Data67640View1 = rawWord2;
        Level41_856F0Data67644View1 = rawWord3;
    }
    rawWord3 = Level41_856F0Field(ownerRecord18, unsigned char*, 0x48);
    switch (rawWord3) {
        case 20:
            Level41_856F0Field(ownerRecord18, signed char*, 0x41) = 0;
            Level41_856F0Field(ownerRecord18, signed char*, 0x4C) = 0;
            Level41_856F0Field(ownerRecord18, signed char*, 0x4D) = 0;
            Level41_856F0Field(ownerRecord18, int*, 8) = 0;
            Level41_856F0Field(ownerRecord18, int*, 0x14) =
                (int)(Level41_856F0Field(ownerRecord18, int*, 0x14) - 0x190);
            Level41_856F0Field(privateRecord20, short*, 0xE) = -1;
            Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 0x15U;
            return;
        case 21:
            if (Level41_856F0Field(ownerRecord18, unsigned char*, 0x49) == 1) {
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 0x16U;
                Level41_856F0Field(privateRecord20, short*, 0xC) = 0x3C;
                return;
            }
        default:
            return;
        case 22:
            rawWord2 = Level41_856F0Field(privateRecord20, short*, 12);
            rawWord2 = rawWord2 < 21;
            argumentWord4 = 0;
            if (!rawWord2) {
                originalFrame.sp18 = Level41_856F0RandBetweenView1(argumentWord4, 0x14) - 0xA;
                originalFrame.sp1C = Level41_856F0RandBetweenView1(0, 0x14) - 0xA;
                originalFrame.sp20 = Level41_856F0RandBetweenView1(0, 0xA);
                Level41_856F0CopyVectorView1(&originalFrame.sp28, ownerRecord18 + 0xC);
                rawWord2 = Level41_856F0RandBetweenView1(0, 80);
                argumentWord4 = 0;
                rawWord3 = originalFrame.sp28;
                argumentWord5 = 80;
                rawWord3 -= 40;
                rawWord3 += rawWord2;
                originalFrame.sp28 = rawWord3;
                rawWord2 = Level41_856F0RandBetweenView1(argumentWord4, argumentWord5);
                argumentWord4 = 1;
                argumentWord5 = 0x3F;
                rawWord3 = originalFrame.sp2C;
                argumentWord6 = (int)&originalFrame.sp28;
                rawWord3 -= 40;
                rawWord3 += rawWord2;
                originalFrame.sp2C = rawWord3;
                originalFrame.sp30 = Level41_856F0Field(privateRecord20, int*, 8);
                Level41_856F0DataSpawnParticleView1(argumentWord4, argumentWord5, argumentWord6,
                                                    &originalFrame.sp18);
            }
            MATCHING_KEEP_GNU_VOLATILE(privateRecord20);
            argumentWord4 = privateRecord20 + 12;
            if (Level41_856F0Field(privateRecord20, void**, 0x10) == 0) {
                if (Level41_856F0Field(privateRecord20, short*, 0xC) < 0x1E) {
                    rawWord2 = Level41_856F0DataSpawnMobyView1(0x164, ownerRecord18);
                    MATCHING_KEEP_GNU_VOLATILE(privateRecord20);
                    argumentWord4 = privateRecord20 + 12;
                    if (rawWord2 != 0) {
                        Level41_856F0Field(privateRecord20, void**, 0x10) = rawWord2;
                        goto block_18;
                    }
                } else {
                block_18:
                    MATCHING_KEEP_GNU_VOLATILE(privateRecord20);
                    argumentWord4 = privateRecord20 + 12;
                }
            }
            if (Level41_856F0CountTimerDownView1(argumentWord4, 2) != 0) {
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 2U;
                Level41_856F0RequestMobyAnimationView1(ownerRecord18, 2);
                Level41_856F0Field(ownerRecord18, signed char*, 0x41) = 1;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4C) = 0x20;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4D) = 1;
                Level41_856F0Field(ownerRecord18, signed char*, 0x46) =
                    Level41_856F0PlanarHeadingLookupView1(
                        Level41_856F0Field(&Level41_856F0Data70328View1, int*, 0) -
                            Level41_856F0Field(ownerRecord18, int*, 0xC),
                        Level41_856F0Field(&Level41_856F0Data70328View1, int*, 4) -
                            Level41_856F0Field(ownerRecord18, int*, 0x10),
                        0);
                Level41_856F0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 7);
                Level41_856F0Field(ownerRecord18, int*, 0x54) =
                    (int)(Level41_856F0Field(privateRecord20, int*, 8) - 0x80000000);
                return;
            }
            break;
        case 0:
            rawWord3 = Level41_856F0Field(privateRecord20, int*, 0x14);
            argumentWord5 = Level41_856F0Data6C550View1;
            rawWord2 = rawWord3 * 88;
            rawWord2 += argumentWord5;
            rawWord3 = Level41_856F0Field(rawWord2, unsigned char*, 0x48);
            retainedCandidateOrScalar17 = 0;
            if (rawWord3 != 0x50) {
                rawWord3 = Level41_856F0Field(privateRecord20, short*, 14);
                rawWord2 = rawWord3 * 88;
                retainedResultOrRecord16 = argumentWord5 + rawWord2;
                if (retainedResultOrRecord16 == ownerRecord18) {
                    MATCHING_KEEP_GNU_VOLATILE(ownerRecord18);
                    if (Level41_856F0Field(privateRecord20, short*, 0xC) == 0) {
                        Level41_856F0TurnMobyTowardHeadingView1(
                            ownerRecord18,
                            Level41_856F0PlanarHeadingLookupView1(
                                Level41_856F0Field(privateRecord20, int*, 0) -
                                    Level41_856F0Field(ownerRecord18, int*, 0xC),
                                Level41_856F0Field(privateRecord20, int*, 4) -
                                    Level41_856F0Field(ownerRecord18, int*, 0x10),
                                0),
                            4, 2, 1, 0);
                    } else {
                        retainedCandidateOrScalar17 = 0x2710;
                        Level41_856F0TurnMobyTowardHeadingView1(
                            ownerRecord18,
                            Level41_856F0PlanarHeadingLookupView1(
                                Level41_856F0Field(ownerRecord18, int*, 0xC) -
                                    Level41_856F0Field(&Level41_856F0Data70328View1, int*, 0),
                                Level41_856F0Field(ownerRecord18, int*, 0x10) -
                                    Level41_856F0Field(&Level41_856F0Data70328View1, int*, 4),
                                0),
                            4, 2, 1, 0);
                        Level41_856F0CountTimerDownView1(privateRecord20 + 0xC, 2);
                    }
                    Level41_856F0ResolveMobyYawStepView1(ownerRecord18, 0x4B, 0, 0, 4);
                    retainedCandidateOrScalar17 =
                        retainedCandidateOrScalar17 + Level41_856F0ApproximatePlanarDistanceView1(
                                                          ownerRecord18 + 0xC, privateRecord20);
                } else {
                    Level41_856F0TurnMobyTowardHeadingView1(
                        ownerRecord18,
                        Level41_856F0PlanarHeadingLookupView1(
                            Level41_856F0Field(retainedResultOrRecord16, int*, 0xC) -
                                Level41_856F0Field(ownerRecord18, int*, 0xC),
                            Level41_856F0Field(retainedResultOrRecord16, int*, 0x10) -
                                Level41_856F0Field(ownerRecord18, int*, 0x10),
                            0),
                        4, 2, 1, 0);
                    Level41_856F0ResolveMobyYawStepView1(ownerRecord18, 0x4B, 0, 0, 4);
                    retainedCandidateOrScalar17 = Level41_856F0ApproximatePlanarDistanceView1(
                        ownerRecord18 + 0xC, retainedResultOrRecord16 + 0xC);
                }
                rawWord2 = retainedCandidateOrScalar17 < 0xC8;
                if (rawWord2) {
                    rawWord2 = Level41_856F0DataSpawnMobyView1(0x164, ownerRecord18);
                    if (rawWord2 != 0) {
                        Level41_856F0Field(privateRecord20, void**, 0x10) = rawWord2;
                    }
                    Level41_856F0RequestMobyAnimationView1(ownerRecord18, 4);
                    Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 0x19U;
                    return;
                }
            }
            break;
        case 25:
            argumentWord4 = Level41_856F0ReadSelectedFrameScalarView1(ownerRecord18, argumentWord5);
            rawWord3 = Level41_856F0Field(ownerRecord18, unsigned char*, 0x3C);
            rawWord2 = 4;
            if (rawWord3 == rawWord2) {
                rawWord2 = argumentWord4 < 11;
                if (!rawWord2)
                    goto lowerOriginalState25Position;
                rawWord2 = argumentWord4 < 15;
                if (rawWord2) {
                lowerOriginalState25Position:
                    rawWord2 = Level41_856F0Field(ownerRecord18, int*, 20);
                    rawWord2 -= 25;
                    Level41_856F0Field(ownerRecord18, int*, 20) = rawWord2;
                }
            }
            Level41_856F0Field(ownerRecord18, int*, 0x54) =
                (int)(Level41_856F0Field(privateRecord20, int*, 8) - 0x80000000);
            if (Level41_856F0Data6C770View1 != 0) {
                Level41_856F0Field(((Level41_856F0Field(privateRecord20, short*, 0xE) * 0x58) +
                                    Level41_856F0Data6C550View1),
                                   signed char*, 0x49) = 0;
                Level41_856F0CopyVectorView1(ownerRecord18 + 0xC, privateRecord20);
                Level41_856F0Field(ownerRecord18, signed char*, 0x41) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4C) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4D) = 0;
                Level41_856F0Field(ownerRecord18, int*, 8) = 0;
                rawWord3 = Level41_856F0Field(privateRecord20, int*, 8);
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 21;
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x49) = 0;
                rawWord3 -= 400;
                Level41_856F0Field(ownerRecord18, int*, 20) = rawWord3;
                rawWord3 = Level41_856F0Field(privateRecord20, short*, 14);
                rawWord2 = (unsigned int)rawWord3 << 1;
                if (rawWord3 >= 0) {
                    rawWord2 += rawWord3;
                    rawWord2 <<= 2;
                    rawWord2 -= rawWord3;
                    rawWord3 = Level41_856F0Data6C550View1;
                    rawWord2 <<= 3;
                    argumentWord4 = rawWord2 + rawWord3;
                    if (Level41_856F0Field(argumentWord4, unsigned char*, 0x49) == 2) {
                        Level41_856F0Field(argumentWord4, unsigned char*, 0x49) = 0U;
                    }
                }
                Level41_856F0Field(privateRecord20, short*, 0xE) = -1;
                rawWord3 =
                    Level41_856F0Field(Level41_856F0Data6C550View1 +
                                           Level41_856F0Field(privateRecord20, int*, 0x14) * 88,
                                       void**, 0);
                Level41_856F0Field(rawWord3, unsigned short*, 2) =
                    (unsigned short)(Level41_856F0Field(rawWord3, unsigned short*, 2) - 1);
                goto loadOriginalChildRecord;
            }
            break;
        case 1:
            if (Level41_856F0Data6C770View1 != 0) {
                Level41_856F0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 4);
                Level41_856F0EmitMobyVertexParticlesView1(ownerRecord18, 0x18);
                Level41_856F0CopyVectorView1(ownerRecord18 + 0xC, privateRecord20);
                Level41_856F0Field(ownerRecord18, signed char*, 0x41) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4C) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4D) = 0;
                Level41_856F0Field(ownerRecord18, int*, 8) = 0;
                rawWord3 = Level41_856F0Field(privateRecord20, int*, 8);
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 21;
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x49) = 0;
                Level41_856F0Field(ownerRecord18, int*, 0x18) = 0;
                rawWord3 -= 400;
                Level41_856F0Field(ownerRecord18, int*, 20) = rawWord3;
                rawWord3 = Level41_856F0Field(privateRecord20, short*, 14);
                rawWord2 = (unsigned int)rawWord3 << 1;
                if (rawWord3 >= 0) {
                    rawWord2 += rawWord3;
                    rawWord2 <<= 2;
                    rawWord2 -= rawWord3;
                    rawWord3 = Level41_856F0Data6C550View1;
                    rawWord2 <<= 3;
                    argumentWord4 = rawWord2 + rawWord3;
                    if (Level41_856F0Field(argumentWord4, unsigned char*, 0x49) == 2) {
                        Level41_856F0Field(argumentWord4, unsigned char*, 0x49) = 0U;
                    }
                }
                rawWord3 = Level41_856F0Field(privateRecord20, void**, 16);
                rawWord2 = -1;
                Level41_856F0Field(privateRecord20, short*, 14) = rawWord2;
                goto testOriginalChildRecord;
            }
            break;
        case 2:
            rawWord2 = Level41_856F0ReadSelectedFrameScalarView1(ownerRecord18, argumentWord5);
            argumentWord4 = (int)ownerRecord18;
            argumentWord5 = 7;
            MATCHING_OBSERVE2_CLOBBER(argumentWord4, argumentWord5, "$16");
            retainedResultOrRecord16 = rawWord2;
            Level41_856F0RefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
            if (retainedResultOrRecord16 < 8) {
                rawWord2 = Level41_856F0Field(ownerRecord18, int*, 0x14) + 0x1E;
                Level41_856F0Field(ownerRecord18, int*, 0x14) = rawWord2;
                rawWord3 = Level41_856F0Field(privateRecord20, int*, 8) - 0xC8;
                rawWord2 = rawWord3 < rawWord2;
                goto block_50;
            }
            rawWord2 = retainedResultOrRecord16 < 19;
            if (!rawWord2) {
                rawWord2 = Level41_856F0Field(ownerRecord18, int*, 0x14) - 0x1E;
                Level41_856F0Field(ownerRecord18, int*, 0x14) = rawWord2;
                rawWord3 = Level41_856F0Field(privateRecord20, int*, 8) - 0x190;
                rawWord2 = rawWord2 < rawWord3;
            block_50:
                if (rawWord2 != 0) {
                    Level41_856F0Field(ownerRecord18, int*, 0x14) = rawWord3;
                }
            }
            if (Level41_856F0Data6C770View1 != 0) {
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 0x18U;
                Level41_856F0Field(privateRecord20, short*, 0xC) = 0x1E;
                Level41_856F0Field(ownerRecord18, int*, 8) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x41) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4C) = 0;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4D) = 0;
                return;
            }
            break;
        case 24:
            if (Level41_856F0CountTimerDownView1(privateRecord20 + 0xC, 2) != 0) {
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 3U;
                Level41_856F0RequestMobyAnimationView1(ownerRecord18, 3);
                Level41_856F0Field(ownerRecord18, signed char*, 0x41) = 1;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4C) = 0x20;
                Level41_856F0Field(ownerRecord18, signed char*, 0x4D) = 1;
                Level41_856F0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 7);
                return;
            }
            break;
        case 3:
            if ((unsigned int)(Level41_856F0ReadSelectedFrameScalarView1(ownerRecord18,
                                                                         argumentWord5) -
                               6) < 2U) {
                rawWord2 = Level41_856F0Field(ownerRecord18, int*, 0x14) + 0xC8;
                Level41_856F0Field(ownerRecord18, int*, 0x14) = rawWord2;
                rawWord3 = Level41_856F0Field(privateRecord20, int*, 8);
                if (rawWord3 < rawWord2) {
                    Level41_856F0Field(ownerRecord18, int*, 0x14) = rawWord3;
                }
            }
            acceptedCount22 = 0;
            if (Level41_856F0Data6C770View1 != 0) {
                fallbackIndex8 = -1;
                argumentWord4 = (int)ownerRecord18;
                argumentWord5 = 0;
                originalFrame.sp60 = fallbackIndex8;
                Level41_856F0Field(ownerRecord18, unsigned char*, 0x48) = 0;
                Level41_856F0RequestMobyAnimationView1(argumentWord4, argumentWord5);
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                rawWord2 = Level41_856F0Field(ownerRecord18, unsigned char*, 0x43);
                candidateLoopCount = 0;
                Level41_856F0Field(ownerRecord18, int*, 0x54) = 0;
                rawWord3 = Level41_856F0Data6C730View1;
                rawWord2 <<= 2;
                rawWord2 += rawWord3;
                candidateList21 = Level41_856F0Field(rawWord2, int*, 0);
                __asm__("" : "=r"(ownerRecord18) : "0"(ownerRecord18), "r"(candidateList21));
                argumentWord4 = (int)ownerRecord18 + 12;
            scanOriginalCandidates:
                rawWord2 = Level41_856F0Field(candidateList21, unsigned short*, 0);
                rawWord3 = Level41_856F0Data6C550View1;
                candidateIndex19 = rawWord2 & 0x7FFF;
                rawWord2 = candidateIndex19 * 88;
                retainedCandidateOrScalar17 = rawWord3 + rawWord2;
                candidateDistance23 = Level41_856F0ApproximatePlanarDistanceView1(
                    argumentWord4, retainedCandidateOrScalar17 + 0xC);
                rawWord3 = Level41_856F0Field(retainedCandidateOrScalar17, unsigned char*, 0x49);
                if (rawWord3)
                    goto testOriginalFallbackCandidate;
                rawWord3 = Level41_856F0Field(retainedCandidateOrScalar17, short*, 0x36);
                if (rawWord3 == 0x3C9)
                    goto testOriginalFallbackCandidate;
                rawWord2 = Level41_856F0PlanarHeadingLookupView1(
                    Level41_856F0Field(retainedCandidateOrScalar17, int*, 12) -
                        Level41_856F0Field(ownerRecord18, int*, 12),
                    Level41_856F0Field(retainedCandidateOrScalar17, int*, 16) -
                        Level41_856F0Field(ownerRecord18, int*, 16),
                    0);
                argumentWord6 = 0;
                MATCHING_OBSERVE_CLOBBER(argumentWord6, "$16");
                retainedResultOrRecord16 = rawWord2;
                argumentWord7 = Level41_856F0Field(&Level41_856F0Data70328View1, int*, 0);
                argumentWord4 = Level41_856F0Field(ownerRecord18, int*, 12);
                rawWord3 = Level41_856F0Field(&Level41_856F0Data70328View1, int*, 4);
                argumentWord5 = Level41_856F0Field(ownerRecord18, int*, 16);
                argumentWord4 = argumentWord7 - argumentWord4;
                argumentWord5 = rawWord3 - argumentWord5;
                rawWord2 = Level41_856F0PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                 argumentWord6, argumentWord7);
                rawWord2 =
                    Level41_856F0AbsoluteByteAngleDeltaView1(retainedResultOrRecord16, rawWord2);
                rawWord2 = rawWord2 < 33;
                if (rawWord2)
                    goto testOriginalFallbackCandidate;
                rawWord2 = candidateDistance23 - 0x801;
                if ((unsigned int)rawWord2 >= 0x7FFU)
                    goto testOriginalFallbackCandidate;
                {
                    Level41_856F0Field(&(&originalFrame.sp18)[acceptedCount22], int*, 0x20) =
                        candidateIndex19;
                    acceptedCount22 += 1;
                    goto advanceOriginalCandidate;
                }
            testOriginalFallbackCandidate:
                if (((fallbackIndex8 = originalFrame.sp60) < 0) &&
                    (Level41_856F0Field(retainedCandidateOrScalar17, unsigned char*, 0x49) == 0)) {
                    originalFrame.sp60 = candidateIndex19;
                }
            advanceOriginalCandidate:
                rawWord2 = Level41_856F0Field(candidateList21, short*, 0);
                candidateList21 += 2;
                if (rawWord2 >= 0 && acceptedCount22 < 10) {
                    candidateLoopCount += 1;
                    argumentWord4 = ownerRecord18 + 0xC;
                    if (candidateLoopCount < 0x32) {
                        goto scanOriginalCandidates;
                    }
                }
                argumentWord4 = 0;
                if (acceptedCount22 == 0) {
                    if ((fallbackIndex8 = originalFrame.sp60) == -1) {
                        rawWord2 = 60;
                        MATCHING_KEEP(rawWord2);
                        argumentWord4 = Level41_856F0Data6C550View1;
                        Level41_856F0Field(privateRecord20, short*, 12) = rawWord2;
                        MATCHING_KEEP_CLOBBER(argumentWord4, "memory");
                        argumentWord4 = (int)ownerRecord18 - argumentWord4;
                        rawWord2 = -((unsigned int)argumentWord4 * 0x45D1745DU);
                        rawWord2 >>= 3;
                        goto storeOriginalChosenIndex;
                    }
                    fallbackIndex8 = Level41_856F0Field(&originalFrame.sp60, unsigned short*, 0);
                    Level41_856F0Field(privateRecord20, short*, 0xE) = fallbackIndex8;
                } else {
                    rawWord2 = Level41_856F0Field(
                        &originalFrame.sp38, int*,
                        Level41_856F0RandBetweenView1(0, acceptedCount22 - 1) * 4);
                storeOriginalChosenIndex:
                    Level41_856F0Field(privateRecord20, short*, 0xE) = (short)rawWord2;
                }
                rawWord3 = Level41_856F0Field(privateRecord20, short*, 14);
                rawWord2 = rawWord3 * 88;
                rawWord3 = Level41_856F0Data6C550View1;
                retainedCandidateOrScalar17 = rawWord3 + rawWord2;
                rawWord2 = 2;
                Level41_856F0Field(retainedCandidateOrScalar17, signed char*, 0x49) = rawWord2;
            loadOriginalChildRecord:
                rawWord3 = Level41_856F0Field(privateRecord20, void**, 16);
            testOriginalChildRecord:
                if (rawWord3) {
                    rawWord2 = 1;
                    Level41_856F0Field(rawWord3, signed char*, 0x49) = rawWord2;
                    Level41_856F0Field(privateRecord20, void**, 16) = 0;
                }
            }
            break;
    }
}
#undef Level41_856F0Field

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 800861BC..800864BC. Rev1 raw649 routes; original helper order,
 * bounds, 88-byte pool addressing and fresh post-helper reads control C.
 * Dynamic private/actor producers, selector12 payload, units and cadence
 * remain unknown. Test: every original linked word and all retail hashes. */
extern Moby* D_8006C550;
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern Vector3D D_80071900;
int func_8001A358(Vector3D*, int);
void func_8005629C(Moby*);
void* func_80019138(Vector3D*, int, int, int, int, int);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
void* func_8001C288(Vector3D*, int, int);
void func_level_41_800861BC(Moby* mobyArgument) {
    register Moby* moby __asm__("$16") = mobyArgument;
    register Vector3D* tag __asm__("$21") = moby->mobyTag;
    register void* staticResult __asm__("$19");
    register void* playerResult __asm__("$20");
    register Moby* dynamicResult __asm__("$18");
    register Vector3D* position __asm__("$17");
    register int index __asm__("$17");
    register int shade __asm__("$18");
    register int lifetime __asm__("$19");
    unsigned char* particle;
    switch (moby->state) {
        case 0:
            staticResult = 0;
            playerResult = 0;
            dynamicResult = 0;
            position = &moby->position;
            func_8004F194(position, position, tag);
            {
                register int pitch __asm__("$2") = moby->angle.pitch;
                register int yaw __asm__("$3") = moby->angle.yaw;
                pitch -= 8;
                moby->angle.pitch = pitch;
                pitch = moby->angle.roll;
                yaw += 5;
                moby->angle.yaw = yaw;
                MATCHING_KEEP(yaw);
                pitch += 4;
                moby->angle.roll = pitch;
            }
            func_8001A358(position, 10240);
            func_8005629C(moby);
            particle = (unsigned char*)SpawnParticle(1, 12, (Vector3D*)moby, (Vector3D*)1);
            if (particle) {
                particle[12] = 192;
                particle[13] = 192;
                particle[14] = 192;
                particle[10] = 20;
            }
            if (func_800359A4((char*)tag + 12, 4))
                goto cleanup;
            if (moby->position.z < 1024 || moby->position.x < 1024 || moby->position.y < 1024)
                goto cleanup;
            staticResult = func_80019138(position, 256, 1, 0, 0, 0);
            if (staticResult)
                goto cleanup;
            MATCHING_KEEP3_VOLATILE(staticResult, dynamicResult, playerResult);
            dynamicResult =
                func_8001BA30(position, 256, 1, 0, 0x70000, &D_8006C550[moby->linkedMoby]);
            if (dynamicResult)
                goto cleanup;
            playerResult = func_8001C288(position, 128, 7);
            if (!playerResult)
                return;
        cleanup:
            func_8003BABC(moby, 0, 0);
            if (playerResult) {
                *(int*)(DecodedCrystalPlayer + 664) =
                    func_8004E880(*(int*)DecodedCrystalPlayer - moby->position.x,
                                  *(int*)(DecodedCrystalPlayer + 4) - moby->position.y, 0);
            } else {
                MATCHING_KEEP(playerResult);
                if (dynamicResult) {
                    moby->unkb = func_8004E880(dynamicResult->position.x - moby->position.x,
                                               dynamicResult->position.y - moby->position.y, 0);
                } else if (staticResult)
                    func_8004F178(&moby->position, &D_80071900);
            }
            index = 0;
            shade = 192;
            lifetime = 48;
            do {
                particle = (unsigned char*)SpawnParticle(1, 12, (Vector3D*)moby, (Vector3D*)1);
                if (particle) {
                    particle[12] = shade;
                    particle[13] = shade;
                    particle[14] = shade;
                    particle[10] = lifetime;
                }
            } while (++index < 3);
            goto remove;
        case 1:
            SpawnParticle(3, 12, (Vector3D*)moby, (Vector3D*)1);
        remove:
            func_800369B8(moby, 24);
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800864C0.
* Assembly SHA256 320bbeef59665a805f6494e24e7767d34fb71062872c406b69a53d3861ee9607.
* AI generated; not human reviewed. All620 instructions,27 selectors,one padding word and
* actual targets are required. Original frame0x90,all S0..S7/FP/RA saves
* and full SP18..67 local extent are retained. An ordinary initialized
* candidate counter naturally uses FP;there is no fixed FP binding.
* The incoming A0 survives to its original cleanup call and state store.
* Original single selector range check,particle producers,88-byte Moby
* indices,both angle inputs and physical shared child-reference clear match.
* List continuation reads its CURRENT signed halfword BEFORE adding two
* bytes. Candidate/fallback stack domains and original modulo32 inverse
* product/shift preserve their complete initialized producers/consumers.
* Empty initialized identities,late consumers,dead clobbers and compiler
* memory barriers emit no CPU instructions. No opcode assembly,partialHI,
* FP shortcut or overlapping live aliases. Confidence is binary identity
* after all gates. Raw units/fixed point,full helper contracts,caller cadence
* and synchronized runtime remain open. Cadence is per invocation.
* Falsification:every native/linked word,actual transfer/table target,owned
* data byte,EXE and every overlay retail hash. */
#define Actor41_864C0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor41_864C0RequestMobyAnimationView1() __asm__("func_80034F40");
int Actor41_864C0SetMobyAnimationView1() __asm__("func_80034F80");
int Actor41_864C0TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor41_864C0CountTimerDownView1() __asm__("func_800359A4");
int Actor41_864C0ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Actor41_864C0RandBetweenView1() __asm__("func_8003636C");
int Actor41_864C0RestoreOrClearTrackedSnapshotView1() __asm__("func_8003B74C");
int Actor41_864C0PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor41_864C0CopyVectorView1() __asm__("func_8004F178");
int Actor41_864C0AbsoluteByteAngleDeltaView1() __asm__("func_8004F264");
int Actor41_864C0ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor41_864C0RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
extern int Actor41_864C0Data6C550View1 __asm__("D_8006C550");
extern int Actor41_864C0Data6C730View1 __asm__("D_8006C730");
extern int Actor41_864C0Data6C770View1 __asm__("D_8006C770");
extern int Actor41_864C0Data6D088View1 __asm__("D_8006D088");
extern int Actor41_864C0Data6EE2CView1 __asm__("D_8006EE2C");
extern int Actor41_864C0Data70328View1 __asm__("D_80070328");
extern void* (*Actor41_864C0DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Actor41_864C0DataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_41_800864C0(void* input) {
    register void* ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        stackSentinel8 __asm__("$8");
    register int recordAddressOrAngle16 __asm__("$16"), recordAddressOrDistance17 __asm__("$17"),
        candidateIndex19 __asm__("$19"), privateRecord20 __asm__("$20"),
        halfwordListCursor21 __asm__("$21"), acceptedCandidateCount22 __asm__("$22"),
        candidateDistance23 __asm__("$23");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64;
    } originalFrame;
    int visitedCandidateCount;
    argumentWord4 = (int)input;
    ownerRecord18 = (void*)argumentWord4;
    MATCHING_KEEP(ownerRecord18);
    rawWord3 = Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48);
    privateRecord20 = Actor41_864C0Field(ownerRecord18, void**, 0);
    if (rawWord3 != 1) {
        if (rawWord3 != 0x15) {
            if (Actor41_864C0Field(ownerRecord18, int*, 0x18) != 0) {
                Actor41_864C0Field(((Actor41_864C0Field(privateRecord20, int*, 0x14) * 0x58) +
                                    Actor41_864C0Data6C550View1),
                                   signed char*, 0x48) = 0x50;
                Actor41_864C0Field(argumentWord4, unsigned char*, 0x48) = 1;
                Actor41_864C0SetMobyAnimationView1(argumentWord4, 1);
                return;
            }
            goto dispatchOriginalState;
        }
        goto dispatchOriginalState;
    }
dispatchOriginalState:
    {
        switch (rawWord2 = rawWord3) {
            case 20:
                MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
                Actor41_864C0Field(ownerRecord18, signed char*, 0x41) = 0;
                Actor41_864C0Field(ownerRecord18, signed char*, 0x4C) = 0;
                Actor41_864C0Field(ownerRecord18, signed char*, 0x4D) = 0;
                Actor41_864C0Field(ownerRecord18, int*, 8) = 0;
                Actor41_864C0Field(ownerRecord18, signed char*, 0x47) = 6;
                Actor41_864C0Field(ownerRecord18, int*, 0x14) =
                    (int)(Actor41_864C0Field(ownerRecord18, int*, 0x14) - 0x190);
                Actor41_864C0Field(privateRecord20, short*, 0xE) = -1;
                Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 0x15U;
                return;
            case 21:
                if (Actor41_864C0Field(ownerRecord18, unsigned char*, 0x49) == 1) {
                    rawWord2 = Actor41_864C0DataSpawnMobyView1(0x164, ownerRecord18);
                    if (rawWord2 != 0) {
                        Actor41_864C0Field(privateRecord20, void**, 0x10) = rawWord2;
                    }
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 0x16U;
                    Actor41_864C0Field(privateRecord20, short*, 0xC) = 0x3C;
                    return;
                }
                break;
            case 22:
                argumentWord4 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                if ((argumentWord4 != 0) &&
                    (Actor41_864C0Field(privateRecord20, short*, 0xC) < 0x1E) &&
                    ((rawWord3 = Actor41_864C0Field(argumentWord4, unsigned char*, 0x4F),
                      ((rawWord3 < 0x19U) == 0)) ||
                     (rawWord3 == 0))) {
                    if (rawWord3 == 0) {
                        Actor41_864C0Field(argumentWord4, unsigned char*, 0x4F) = 0x20U;
                    }
                    rawWord3 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                    Actor41_864C0Field(rawWord3, unsigned char*, 0x4F) =
                        (unsigned char)(Actor41_864C0Field(rawWord3, unsigned char*, 0x4F) - 4);
                }
                MATCHING_KEEP_GNU_VOLATILE(privateRecord20);
                argumentWord4 = privateRecord20 + 12;
                if (Actor41_864C0Field(privateRecord20, short*, 0xC) >= 0x15) {
                    originalFrame.sp18 = Actor41_864C0RandBetweenView1(0, 0x14) - 0xA;
                    originalFrame.sp1C = Actor41_864C0RandBetweenView1(0, 0x14) - 0xA;
                    originalFrame.sp20 = Actor41_864C0RandBetweenView1(0, 0xA);
                    Actor41_864C0CopyVectorView1(&originalFrame.sp28, ownerRecord18 + 0xC);
                    rawWord2 = Actor41_864C0RandBetweenView1(0, 80);
                    argumentWord4 = 0;
                    rawWord3 = originalFrame.sp28;
                    argumentWord5 = 80;
                    rawWord3 -= 40;
                    rawWord3 += rawWord2;
                    originalFrame.sp28 = rawWord3;
                    rawWord2 = Actor41_864C0RandBetweenView1(argumentWord4, argumentWord5);
                    argumentWord4 = 1;
                    argumentWord5 = 0x3F;
                    rawWord3 = originalFrame.sp2C;
                    argumentWord6 = (int)&originalFrame.sp28;
                    rawWord3 -= 40;
                    rawWord3 += rawWord2;
                    originalFrame.sp2C = rawWord3;
                    originalFrame.sp30 = Actor41_864C0Field(privateRecord20, int*, 8);
                    Actor41_864C0DataSpawnParticleView1(argumentWord4, argumentWord5, argumentWord6,
                                                        &originalFrame.sp18);
                    MATCHING_KEEP_GNU_VOLATILE(privateRecord20);
                    argumentWord4 = privateRecord20 + 12;
                }
                if (Actor41_864C0CountTimerDownView1(argumentWord4, 2) != 0) {
                    Actor41_864C0SetMobyAnimationView1(ownerRecord18, 2);
                    argumentWord6 = 0;
                    __asm__("" ::"r"(argumentWord6) : "$2", "$3", "$4");
                    rawWord2 = 2;
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = rawWord2;
                    rawWord3 = Actor41_864C0Field(privateRecord20, int*, 8);
                    argumentWord4 = 1;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x41) = argumentWord4;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4D) = argumentWord4;
                    argumentWord4 = Actor41_864C0Field(ownerRecord18, int*, 12);
                    argumentWord5 = Actor41_864C0Field(ownerRecord18, int*, 16);
                    rawWord2 = 32;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4C) = rawWord2;
                    rawWord3 += 50;
                    Actor41_864C0Field(ownerRecord18, int*, 0x14) = rawWord3;
                    rawWord3 = Actor41_864C0Field(&Actor41_864C0Data70328View1, int*, 0);
                    rawWord2 = Actor41_864C0Field(&Actor41_864C0Data70328View1, int*, 4);
                    argumentWord4 = rawWord3 - argumentWord4;
                    argumentWord5 = rawWord2 - argumentWord5;
                    rawWord2 = Actor41_864C0PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                     argumentWord6);
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x46) = rawWord2;
                    Actor41_864C0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 7);
                    Actor41_864C0Field(ownerRecord18, int*, 0x54) =
                        (int)(Actor41_864C0Field(privateRecord20, int*, 8) - 0x80000000);
                    return;
                }
                break;
            case 0:
                rawWord2 = Actor41_864C0Field(privateRecord20, short*, 14);
                rawWord3 = rawWord2 * 88;
                rawWord2 = Actor41_864C0Data6C550View1;
                recordAddressOrAngle16 = rawWord2 + rawWord3;
                recordAddressOrDistance17 = 0;
                if (recordAddressOrAngle16 == ownerRecord18) {
                    MATCHING_KEEP_GNU_VOLATILE(ownerRecord18);
                    if (Actor41_864C0Field(privateRecord20, short*, 0xC) == 0) {
                        Actor41_864C0TurnMobyTowardHeadingView1(
                            ownerRecord18,
                            Actor41_864C0PlanarHeadingLookupView1(
                                Actor41_864C0Field(privateRecord20, int*, 0) -
                                    Actor41_864C0Field(ownerRecord18, int*, 0xC),
                                Actor41_864C0Field(privateRecord20, int*, 4) -
                                    Actor41_864C0Field(ownerRecord18, int*, 0x10),
                                0),
                            4, 2, 1, 0);
                    } else {
                        recordAddressOrDistance17 = 0x2710;
                        Actor41_864C0TurnMobyTowardHeadingView1(
                            ownerRecord18,
                            Actor41_864C0PlanarHeadingLookupView1(
                                Actor41_864C0Field(ownerRecord18, int*, 0xC) -
                                    Actor41_864C0Field(&Actor41_864C0Data70328View1, int*, 0),
                                Actor41_864C0Field(ownerRecord18, int*, 0x10) -
                                    Actor41_864C0Field(&Actor41_864C0Data70328View1, int*, 4),
                                0),
                            4, 2, 1, 0);
                        Actor41_864C0CountTimerDownView1(privateRecord20 + 0xC, 2);
                    }
                    Actor41_864C0ResolveMobyYawStepView1(ownerRecord18, 0x32, 0, 0, 4);
                    recordAddressOrDistance17 =
                        recordAddressOrDistance17 + Actor41_864C0ApproximatePlanarDistanceView1(
                                                        ownerRecord18 + 0xC, privateRecord20);
                } else {
                    Actor41_864C0TurnMobyTowardHeadingView1(
                        ownerRecord18,
                        Actor41_864C0PlanarHeadingLookupView1(
                            Actor41_864C0Field(recordAddressOrAngle16, int*, 0xC) -
                                Actor41_864C0Field(ownerRecord18, int*, 0xC),
                            Actor41_864C0Field(recordAddressOrAngle16, int*, 0x10) -
                                Actor41_864C0Field(ownerRecord18, int*, 0x10),
                            0),
                        4, 2, 1, 0);
                    Actor41_864C0ResolveMobyYawStepView1(ownerRecord18, 0x32, 0, 0, 4);
                    recordAddressOrDistance17 = Actor41_864C0ApproximatePlanarDistanceView1(
                        ownerRecord18 + 0xC, recordAddressOrAngle16 + 0xC);
                }
                rawWord2 = recordAddressOrDistance17 < 0xC8;
                if (rawWord2) {
                    if (Actor41_864C0Field(privateRecord20, void**, 0x10) == 0) {
                        rawWord2 = Actor41_864C0DataSpawnMobyView1(0x164, ownerRecord18);
                        if (rawWord2 != 0) {
                            Actor41_864C0Field(privateRecord20, void**, 0x10) = rawWord2;
                        }
                    }
                    Actor41_864C0RequestMobyAnimationView1(ownerRecord18, 4);
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 0x19U;
                    return;
                }
                break;
            case 25:
                argumentWord4 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                if ((argumentWord4 != 0) &&
                    ((rawWord3 = Actor41_864C0Field(argumentWord4, unsigned char*, 0x4F),
                      ((rawWord3 < 0x19U) == 0)) ||
                     (rawWord3 == 0))) {
                    if (rawWord3 == 0) {
                        Actor41_864C0Field(argumentWord4, unsigned char*, 0x4F) = 0x20U;
                    }
                    rawWord3 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                    Actor41_864C0Field(rawWord3, unsigned char*, 0x4F) =
                        (unsigned char)(Actor41_864C0Field(rawWord3, unsigned char*, 0x4F) - 4);
                }
                Actor41_864C0Field(ownerRecord18, int*, 0x54) =
                    (int)(Actor41_864C0Field(privateRecord20, int*, 8) - 0x80000000);
                if (Actor41_864C0Data6C770View1 != 0) {
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x41) = 0;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4C) = 0;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4D) = 0;
                    Actor41_864C0Field(ownerRecord18, int*, 8) = 0;
                    Actor41_864C0CopyVectorView1(ownerRecord18 + 0xC, privateRecord20);
                    rawWord3 = Actor41_864C0Field(privateRecord20, int*, 8);
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 21;
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x49) = 0;
                    rawWord3 -= 400;
                    Actor41_864C0Field(ownerRecord18, int*, 0x14) = rawWord3;
                    rawWord3 = Actor41_864C0Field(privateRecord20, short*, 14);
                    MATCHING_KEEP(rawWord3);
                    if (rawWord3 >= 0) {
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = Actor41_864C0Data6C550View1;
                        argumentWord4 = rawWord2 + rawWord3;
                        if (Actor41_864C0Field(argumentWord4, unsigned char*, 0x49) == 2) {
                            Actor41_864C0Field(argumentWord4, unsigned char*, 0x49) = 0U;
                        }
                    }
                    rawWord3 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                    Actor41_864C0Field(privateRecord20, short*, 0xE) = -1;
                    if (rawWord3 != 0) {
                        Actor41_864C0Field(rawWord3, signed char*, 0x48) = 2;
                        goto clearChildReference;
                    }
                }
                break;
            case 2:
                Actor41_864C0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 7);
                Actor41_864C0Field(ownerRecord18, int*, 0x54) =
                    (int)(Actor41_864C0Field(privateRecord20, int*, 8) - 0x80000000);
                if (Actor41_864C0Data6C770View1 != 0) {
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 0x18U;
                    Actor41_864C0Field(privateRecord20, short*, 0xC) = 0x1E;
                    Actor41_864C0Field(ownerRecord18, int*, 8) = 0;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x41) = 0;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4C) = 0;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4D) = 0;
                    return;
                }
                break;
            case 24:
                if (Actor41_864C0CountTimerDownView1(privateRecord20 + 0xC, 2) != 0) {
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 3U;
                    Actor41_864C0RequestMobyAnimationView1(ownerRecord18, 3);
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x41) = 1;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4C) = 0x20;
                    Actor41_864C0Field(ownerRecord18, signed char*, 0x4D) = 1;
                    Actor41_864C0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 7);
                    return;
                }
                break;
            case 1:
                if (Actor41_864C0Data6C770View1 != 0) {
                    Actor41_864C0RefreshMobySpatialGridAndBasisView1(ownerRecord18, 4);
                    Actor41_864C0Field(ownerRecord18, int*, 8) = 0;
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 0x1AU;
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x49) = 0U;
                    Actor41_864C0Field(ownerRecord18, int*, 0x18) = 0;
                    rawWord3 = Actor41_864C0Field(privateRecord20, short*, 14);
                    MATCHING_KEEP(rawWord3);
                    if (rawWord3 >= 0) {
                        rawWord2 = rawWord3 * 88;
                        rawWord3 = Actor41_864C0Data6C550View1;
                        argumentWord4 = rawWord2 + rawWord3;
                        if (Actor41_864C0Field(argumentWord4, unsigned char*, 0x49) == 2) {
                            Actor41_864C0Field(argumentWord4, unsigned char*, 0x49) = 0U;
                        }
                    }
                    rawWord3 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                    Actor41_864C0Field(privateRecord20, short*, 0xE) = -1;
                    if (rawWord3 != 0) {
                        Actor41_864C0Field(rawWord3, signed char*, 0x48) = 2;
                        Actor41_864C0Field(privateRecord20, void**, 0x10) = 0;
                    }
                    Actor41_864C0RestoreOrClearTrackedSnapshotView1(&Actor41_864C0Data6D088View1);
                    return;
                }
                break;
            case 26:
                Actor41_864C0Field(ownerRecord18, signed char*, 0x3D) = 1;
                Actor41_864C0Field(ownerRecord18, signed char*, 0x3C) = 1;
                rawWord2 =
                    Actor41_864C0Field(
                        Actor41_864C0Field(
                            Actor41_864C0Field(&Actor41_864C0Data6EE2CView1, int*,
                                               Actor41_864C0Field(ownerRecord18, short*, 0x36) * 4),
                            void**, 0x40),
                        unsigned char*, 0) -
                    1;
                Actor41_864C0Field(ownerRecord18, signed char*, 0x3F) = rawWord2;
                Actor41_864C0Field(ownerRecord18, signed char*, 0x3E) = rawWord2;
                return;
            case 3:
                acceptedCandidateCount22 = 0;
                if (Actor41_864C0Data6C770View1 != 0) {
                    stackSentinel8 = -1;
                    argumentWord4 = (int)ownerRecord18;
                    __asm__("" : "=r"(stackSentinel8) : "0"(stackSentinel8), "r"(argumentWord4));
                    originalFrame.sp60 = stackSentinel8;
                    rawWord2 = Actor41_864C0Field(privateRecord20, int*, 8);
                    MATCHING_KEEP_CLOBBER(rawWord2, "$5");
                    argumentWord5 = 0;
                    Actor41_864C0Field(ownerRecord18, unsigned char*, 0x48) = 0;
                    Actor41_864C0Field(ownerRecord18, int*, 0x14) = rawWord2;
                    Actor41_864C0RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    MATCHING_BARRIER_GNU_VOLATILE("memory");
                    rawWord2 = Actor41_864C0Field(ownerRecord18, unsigned char*, 0x43);
                    visitedCandidateCount = 0;
                    Actor41_864C0Field(ownerRecord18, int*, 0x54) = 0;
                    rawWord3 = Actor41_864C0Data6C730View1;
                    rawWord2 <<= 2;
                    rawWord2 += rawWord3;
                    halfwordListCursor21 = Actor41_864C0Field(rawWord2, int*, 0);
                    __asm__(""
                            : "=r"(ownerRecord18)
                            : "0"(ownerRecord18), "r"(halfwordListCursor21));
                    argumentWord4 = (int)ownerRecord18 + 12;
                readCurrentCandidate:
                    rawWord2 = Actor41_864C0Field(halfwordListCursor21, unsigned short*, 0);
                    rawWord3 = Actor41_864C0Data6C550View1;
                    candidateIndex19 = rawWord2 & 0x7FFF;
                    rawWord2 = candidateIndex19 * 88;
                    recordAddressOrDistance17 = rawWord3 + rawWord2;
                    candidateDistance23 = Actor41_864C0ApproximatePlanarDistanceView1(
                        argumentWord4, recordAddressOrDistance17 + 0xC);
                    rawWord3 = Actor41_864C0Field(recordAddressOrDistance17, unsigned char*, 0x49);
                    if (rawWord3)
                        goto considerFallbackCandidate;
                    rawWord3 = Actor41_864C0Field(recordAddressOrDistance17, short*, 0x36);
                    if (rawWord3 == 0x3C9)
                        goto considerFallbackCandidate;
                    rawWord2 = Actor41_864C0PlanarHeadingLookupView1(
                        Actor41_864C0Field(recordAddressOrDistance17, int*, 12) -
                            Actor41_864C0Field(ownerRecord18, int*, 12),
                        Actor41_864C0Field(recordAddressOrDistance17, int*, 16) -
                            Actor41_864C0Field(ownerRecord18, int*, 16),
                        0);
                    argumentWord6 = 0;
                    MATCHING_OBSERVE_CLOBBER(argumentWord6, "$16");
                    recordAddressOrAngle16 = rawWord2;
                    argumentWord7 = Actor41_864C0Field(&Actor41_864C0Data70328View1, int*, 0);
                    argumentWord4 = Actor41_864C0Field(ownerRecord18, int*, 12);
                    rawWord3 = Actor41_864C0Field(&Actor41_864C0Data70328View1, int*, 4);
                    argumentWord5 = Actor41_864C0Field(ownerRecord18, int*, 16);
                    argumentWord4 = argumentWord7 - argumentWord4;
                    argumentWord5 = rawWord3 - argumentWord5;
                    rawWord2 = Actor41_864C0PlanarHeadingLookupView1(argumentWord4, argumentWord5,
                                                                     argumentWord6, argumentWord7);
                    rawWord2 =
                        Actor41_864C0AbsoluteByteAngleDeltaView1(recordAddressOrAngle16, rawWord2);
                    rawWord2 = rawWord2 < 33;
                    if (rawWord2)
                        goto considerFallbackCandidate;
                    rawWord2 = candidateDistance23 - 0x801;
                    if ((unsigned int)rawWord2 >= 0x7FFU)
                        goto considerFallbackCandidate;
                    {
                        Actor41_864C0Field(&(&originalFrame.sp18)[acceptedCandidateCount22], int*,
                                           0x20) = candidateIndex19;
                        acceptedCandidateCount22 += 1;
                        goto checkListContinuation;
                    }
                considerFallbackCandidate:
                    if (((stackSentinel8 = originalFrame.sp60) < 0) &&
                        (Actor41_864C0Field(recordAddressOrDistance17, unsigned char*, 0x49) ==
                         0)) {
                        originalFrame.sp60 = candidateIndex19;
                    }
                checkListContinuation:
                    rawWord2 = Actor41_864C0Field(halfwordListCursor21, short*, 0);
                    halfwordListCursor21 += 2;
                    if (rawWord2 >= 0 && acceptedCandidateCount22 < 10) {
                        visitedCandidateCount += 1;
                        argumentWord4 = ownerRecord18 + 0xC;
                        if (visitedCandidateCount < 0x32) {
                            goto readCurrentCandidate;
                        }
                    }
                    argumentWord4 = 0;
                    if (acceptedCandidateCount22 == 0) {
                        if ((stackSentinel8 = originalFrame.sp60) == -1) {
                            rawWord2 = 60;
                            argumentWord4 = Actor41_864C0Data6C550View1;
                            Actor41_864C0Field(privateRecord20, short*, 12) = rawWord2;
                            MATCHING_KEEP_CLOBBER(argumentWord4, "memory");
                            argumentWord4 = (int)ownerRecord18 - argumentWord4;
                            rawWord2 = -((unsigned int)argumentWord4 * 0x45D1745DU);
                            rawWord2 >>= 3;
                            goto storeSelectedIndex;
                        }
                        stackSentinel8 =
                            Actor41_864C0Field(&originalFrame.sp60, unsigned short*, 0);
                        Actor41_864C0Field(privateRecord20, short*, 0xE) = stackSentinel8;
                    } else {
                        rawWord2 = Actor41_864C0Field(
                            &originalFrame.sp38, int*,
                            Actor41_864C0RandBetweenView1(0, acceptedCandidateCount22 - 1) * 4);
                    storeSelectedIndex:
                        Actor41_864C0Field(privateRecord20, short*, 0xE) = (short)rawWord2;
                    }
                    rawWord2 = Actor41_864C0Field(privateRecord20, short*, 14);
                    rawWord3 = rawWord2 * 88;
                    rawWord2 = Actor41_864C0Data6C550View1;
                    recordAddressOrDistance17 = rawWord2 + rawWord3;
                    rawWord3 = 2;
                    Actor41_864C0Field(recordAddressOrDistance17, signed char*, 0x49) = rawWord3;
                    rawWord2 = Actor41_864C0Field(privateRecord20, void**, 0x10);
                    if (rawWord2 != 0) {
                        Actor41_864C0Field(rawWord2, signed char*, 0x48) = rawWord3;
                    clearChildReference:
                        Actor41_864C0Field(privateRecord20, void**, 0x10) = 0;
                    }
                }
                break;
        }
    }
}
#undef Actor41_864C0Field

typedef struct {
    unsigned char* angles;
    short timer;
    unsigned short savedRoll, savedPitch, reserved0A;
    Moby* spawned;
    unsigned char* light;
} DecodedAttachedObjectTag;
extern int D_8006C648;
void DecodedAttachedObjectSound(Moby*, int, int) __asm__("func_8003BABC");
void DecodedAttachedObjectDraw(Moby*, int) __asm__("func_80055D24");
void DecodedAttachedObjectTransform(void*, void*, void*) __asm__("func_8004ED6C");
void DecodedAttachedObjectAdd(void*, void*, void*) __asm__("func_8004F194");
unsigned char* DecodedAttachedObjectLight(int, int, int) __asm__("func_8002EC50");
void func_level_41_80086E70(Moby* moby) {
    DecodedAttachedObjectTag* tag = moby->mobyTag;
    register int changed __asm__("$16") = 0;
    register Moby* spawned __asm__("$16");
    Moby* initialSpawn;
    Vector3D offset;
    int reservedStack[1];
    switch (moby->state) {
        case 0:
            initialSpawn = SpawnMoby(0x1D5, moby);
            tag->spawned = initialSpawn;
            if (initialSpawn) {
                changed = 1;
                moby->state = 1;
                initialSpawn->colour.r = 5;
                initialSpawn->unknown4 = 2;
                initialSpawn->lowDrawDistance = 32;
                initialSpawn->highDrawDistance = 63;
            }
            break;
        case 1:
            if (moby->damageFlags & 0x20000) {
                tag->timer = 1;
                MATCHING_BARRIER_VOLATILE("memory");
                DecodedAttachedObjectSound(moby, 0, 0);
            }
            moby->damageFlags = 0;
            if (tag->timer) {
                tag->timer += D_8006C648;
                changed = 1;
                if (tag->timer < 64) {
                    moby->angle.roll =
                        tag->angles[(tag->timer >> 1) * 2] + *(unsigned char*)&tag->savedRoll;
                    moby->angle.pitch =
                        tag->angles[((short)*(unsigned short*)&tag->timer >> 1) * 2 + 1] +
                        *(unsigned char*)&tag->savedPitch;
                } else {
                    tag->timer = 0;
                    moby->angle.roll = tag->savedRoll;
                    moby->angle.pitch = tag->savedPitch;
                }
            }
            break;
    }
    if (changed) {
        spawned = tag->spawned;
        offset.x = 0;
        offset.y = 0;
        offset.z = 0x898;
        DecodedAttachedObjectDraw(moby, 4);
        DecodedAttachedObjectTransform(&moby->rotationMatrix, &offset, &offset);
        DecodedAttachedObjectAdd(&spawned->position, &moby->position, &offset);
        spawned->angle.roll = moby->angle.roll;
        spawned->angle.pitch = moby->angle.pitch;
        spawned->angle.yaw = moby->angle.yaw;
    }
    if (tag->spawned) {
        tag->spawned->angle.yaw += D_8006C648 * 2;
        if (!tag->spawned->drawn) {
            if (!tag->light)
                return;
            tag->light[0x10] = 0;
            tag->light = 0;
        } else if (!tag->light)
            tag->light = DecodedAttachedObjectLight(1, 250, 0xC060A0);
        if (tag->light) {
            func_8004F178(tag->light, &tag->spawned->position);
            *(int*)(tag->light + 8) -= 25;
            tag->light[0x13] = 8;
        }
    }
}

extern int Actor41_D_8006C648 __asm__("D_8006C648");
extern short Actor41_D_800658A0[] __asm__("D_800658A0");
extern short Actor41_D_80065920[] __asm__("D_80065920");
void Actor41DeleteMoby(Moby*) __asm__("func_80055B18");
void Actor41RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
int Actor41ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int Actor41CountTimerDown(void* pTimer, int pTimerType) __asm__("func_800359A4");
int Actor41PlayMobySoundEvent(Moby* owner, int index, int selector) __asm__("func_8003BABC");
void Actor41ClearHistorySourceWord(int* ptr) __asm__("func_800509E8");
void func_level_41_80087110(Moby* moby) {
    struct {
        int x, y, z;
        int reserved[1];
    } local;
    Vector3D* position;
    short counterAfter2;
    short counterAfter4;
    short counterAfter5;
    short counterValue;
    register int rawStep __asm__("$4");
    register int angle __asm__("$3");
    int* savedPointer;
    unsigned char* payload;
    unsigned char* newPayload;
    unsigned char* previousPayload;
    register unsigned int sizeAfter3 __asm__("$2");
    register unsigned int sizeAfter5 __asm__("$2");
    unsigned char state;
    void* privateData;

    state = moby->state;
    privateData = moby->mobyTag;
    switch (state) {
        case 6:
            local.x = 0x190;
            local.y = 0;
            local.z = 0;
            Actor41RefreshMobySpatialGridAndBasis(moby, 4);
            func_8004ED6C(&moby->rotationMatrix, &local.x, &local.x);
            position = &moby->position;
            func_8004F194(position, position, &local.x);
            previousPayload = (*(unsigned char**)((unsigned char*)(privateData) + 0x10));
            if (previousPayload != 0) {
                (*(unsigned char*)((unsigned char*)(previousPayload) + 0xC)) = 8;
                (*(unsigned char*)((unsigned char*)((
                                       *(unsigned char**)((unsigned char*)(privateData) + 0x10))) +
                                   0xD)) = 8;
                (*(unsigned char*)((unsigned char*)((
                                       *(unsigned char**)((unsigned char*)(privateData) + 0x10))) +
                                   0xE)) = 8;
            }
            payload = SpawnParticle(1, 0xC, (Vector3D*)moby, (Vector3D*)2);
            (*(unsigned char**)((unsigned char*)(privateData) + 0x10)) = payload;
            if (payload != 0) {
                (*(unsigned char*)((unsigned char*)(payload) + 0xA)) = 0x78;
                if (moby->substate == 1) {
                    (*(unsigned char*)((unsigned char*)((
                                           *(unsigned char**)((unsigned char*)(privateData) +
                                                              0x10))) +
                                       0xC)) = 0x60;
                    (*(unsigned char*)((unsigned char*)((
                                           *(unsigned char**)((unsigned char*)(privateData) +
                                                              0x10))) +
                                       0xD)) = 0x60;
                    (*(unsigned char*)((unsigned char*)((
                                           *(unsigned char**)((unsigned char*)(privateData) +
                                                              0x10))) +
                                       0xE)) = 0xC0;
                }
            }
            if ((Actor41ApproximatePlanarDistance(
                     &moby->position, (*(int*)((unsigned char*)(privateData) + 0xC)) + 0xC) <
                 0x1F4) ||
                (Actor41CountTimerDown(privateData, 2) != 0)) {
                savedPointer = (*(int**)((unsigned char*)(privateData) + 8));
                if (savedPointer != 0) {
                    Actor41ClearHistorySourceWord(savedPointer);
                }
                SpawnParticle(3, 0xC, (Vector3D*)moby, (Vector3D*)2);
                Actor41DeleteMoby(moby);
                return;
            }
            return;
    }
    switch (state) {
        case 0:
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            moby->unknown4 = 0;
            moby->unknownCollision = 0;
            moby->state = 1;
            (*(unsigned short*)((unsigned char*)(privateData) + 0)) =
                (unsigned short)(*(unsigned short*)((unsigned char*)(privateData) + 2));
            (*(short*)((unsigned char*)(privateData) + 4)) = (short)moby->position.z;
            return;
        case 2:
            if (Actor41CountTimerDown(privateData, 2) != 0) {
                moby->unknown3[0] = 1;
                moby->lowDrawDistance = 0x20;
                moby->drawn = 1;
                Actor41RefreshMobySpatialGridAndBasis(moby, 7);
                Actor41PlayMobySoundEvent(moby, 0, 0);
                moby->state = 3;
                moby->size = 0xFE;
                (*(short*)((unsigned char*)(privateData) + 6)) = 0;
                return;
            }
            break;
        case 3:
            moby->position.z +=
                (int)((unsigned short)
                          Actor41_D_80065920[(*(short*)((unsigned char*)(privateData) + 6))]
                      << 0x10) >>
                0x17;
            counterAfter2 = (unsigned short)(*(short*)((unsigned char*)(privateData) + 6)) + 2;
            (*(short*)((unsigned char*)(privateData) + 6)) = counterAfter2;
            if (counterAfter2 >= 0x101) {
                (*(short*)((unsigned char*)(privateData) + 6)) = 0;
                moby->position.z = (int)(*(short*)((unsigned char*)(privateData) + 4));
            }
            SpawnParticle(1, 0xC, (Vector3D*)moby, (Vector3D*)2);
            rawStep = Actor41_D_8006C648;
            angle = moby->angle.yaw;
            sizeAfter3 = moby->size;
            MATCHING_KEEP3(rawStep, angle, sizeAfter3);
            rawStep *= 4;
            angle += rawStep;
            sizeAfter3 -= 10;
            moby->size = sizeAfter3;
            moby->angle.yaw = angle;
            if ((unsigned int)(sizeAfter3 & 0xFF) < 0x20U) {
                moby->size = 0x20;
                moby->state = 4;
                (*(unsigned short*)((unsigned char*)(privateData) + 0)) = 0x258U;
                return;
            }
            break;
        case 4:
            moby->position.z +=
                (int)((unsigned short)
                          Actor41_D_80065920[(*(short*)((unsigned char*)(privateData) + 6))]
                      << 0x10) >>
                0x17;
            counterAfter4 = (unsigned short)(*(short*)((unsigned char*)(privateData) + 6)) + 2;
            (*(short*)((unsigned char*)(privateData) + 6)) = counterAfter4;
            if (counterAfter4 >= 0x101) {
                (*(short*)((unsigned char*)(privateData) + 6)) = 0;
                moby->position.z = (int)(*(short*)((unsigned char*)(privateData) + 4));
            }
            counterValue = (short)(*(unsigned short*)((unsigned char*)(privateData) + 0));
            if ((counterValue >= 0x1C3) &&
                ((counterValue >= 0x1D9) ||
                 (((int)((unsigned short)
                             Actor41_D_80065920[(*(short*)((unsigned char*)(privateData) + 6))]
                         << 0x10) >>
                   0x1A) >= 2))) {
                moby->angle.yaw +=
                    (int)((unsigned short)
                              Actor41_D_80065920[(*(short*)((unsigned char*)(privateData) + 6))]
                          << 0x10) >>
                    0x1A;
            }
            if ((Actor41ApproximatePlanarDistance(&moby->position, (Vector3D*)&D_8006E020) >=
                 0xBB9) &&
                (moby->substate != 2)) {
                newPayload = SpawnParticle(1, 0xC, (Vector3D*)moby, (Vector3D*)2);
                if (newPayload != 0) {
                    (*(unsigned char*)((unsigned char*)(newPayload) + 0xA)) = 0x96;
                }
            }
            if ((Actor41CountTimerDown(privateData, 2) != 0) && (moby->substate != 2)) {
                Actor41PlayMobySoundEvent(moby, 1, 0);
                moby->state = 5;
                moby->unknownCollision = 0;
                return;
            }
            break;
        case 5:
            moby->position.z +=
                (int)((unsigned short)
                          Actor41_D_80065920[(*(short*)((unsigned char*)(privateData) + 6))]
                      << 0x10) >>
                0x17;
            counterAfter5 = (unsigned short)(*(short*)((unsigned char*)(privateData) + 6)) + 2;
            (*(short*)((unsigned char*)(privateData) + 6)) = counterAfter5;
            if (counterAfter5 >= 0x101) {
                (*(short*)((unsigned char*)(privateData) + 6)) = 0;
                moby->position.z = (int)(*(short*)((unsigned char*)(privateData) + 4));
            }
            SpawnParticle(1, 0xC, (Vector3D*)moby, (Vector3D*)2);
            rawStep = Actor41_D_8006C648;
            angle = moby->angle.yaw;
            sizeAfter5 = moby->size;
            MATCHING_KEEP3(rawStep, angle, sizeAfter5);
            rawStep *= 4;
            angle -= rawStep;
            sizeAfter5 += 10;
            moby->size = sizeAfter5;
            moby->angle.yaw = angle;
            if ((unsigned int)(sizeAfter5 & 0xFF) >= 0xF4U) {
                SpawnParticle(3, 0xC, (Vector3D*)moby, (Vector3D*)2);
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
                moby->unknownCollision = 0;
                moby->state = 1;
                (*(unsigned short*)((unsigned char*)(privateData) + 0)) =
                    (unsigned short)(*(unsigned short*)((unsigned char*)(privateData) + 2));
                moby->position.z = (int)(*(short*)((unsigned char*)(privateData) + 4));
            }
            break;
    }
}

typedef struct {
    int reserved00, pathArgument;
    Vector3D pathVector;
    unsigned char reserved14[0x38];
    int sound, strength;
    Vector3D previous;
} DecodedMovementSoundTag;
extern void (*DecodedMovementSoundPath)(Vector3D*, Vector3D*, Vector3D*,
                                        int) __asm__("unk_ovlheader_80074340");
extern unsigned char DecodedMovementSoundUnsaved[] __asm__("D_8006C7F8");
int DecodedMovementSoundFloor(Vector3D*, int) __asm__("func_8001A358");
void DecodedMovementSoundSave(void*, int, void*) __asm__("func_8003B7B4");
void func_level_41_80087658(Moby* moby) {
    DecodedMovementSoundTag* tag = moby->mobyTag;
    Vector3D position;
    switch (moby->state) {
        case 0:
            DecodedMovementSoundPath(&moby->position, &moby->position, &tag->pathVector,
                                     tag->pathArgument);
            func_8004F178(&position, &moby->position);
            position.z += 0x100;
            moby->position.z = DecodedMovementSoundFloor(&position, 0x400) - 0x10;
            moby->state = 1;
            func_8004F178(&tag->previous, &moby->position);
            /* Initialization continues into the original state-one sound update. */
        case 1:
            if (tag->previous.x != moby->position.x || tag->previous.y != moby->position.y ||
                tag->previous.z != moby->position.z) {
                if (!func_8003BFC0(moby, tag->sound))
                    tag->sound = func_8003BABC(moby, 0, 4);
                if (tag->sound >= 0) {
                    tag->strength += 0x100;
                    if (tag->strength > 0x1000)
                        tag->strength = 0x1000;
                    func_8003C140(tag->sound, tag->strength);
                }
                DecodedMovementSoundSave(&moby->position.x, 4, DecodedMovementSoundUnsaved);
                DecodedMovementSoundSave(&moby->position.y, 4, DecodedMovementSoundUnsaved);
            } else if (func_8003BFC0(moby, tag->sound)) {
                tag->strength -= 0x200;
                if (tag->strength <= 0) {
                    if (func_8003BFC0(moby, tag->sound))
                        func_8003BE70(tag->sound);
                    tag->sound = -1;
                } else
                    func_8003C140(tag->sound, tag->strength);
            }
            break;
    }
    func_8004F178(&tag->previous, &moby->position);
    func_80055D24(moby, 2);
}

int func_80021F3C(int);
void func_80021ED8(int, int, int);
void func_level_41_80087854(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
        case 0:
            if (moby->substate == 1) {
                unsigned char* state;
                moby->state = 1;
                state = &moby->state;
                func_8003B7B4(state, 1, &savedData);
                func_8003B7B4(state, 1, &unsavedData);
            }
            break;
        case 1: {
            int value = func_80021F3C(tag[0]);
            if (!((value >> 8) & 0xFF)) {
                if (!(value & 0xF))
                    break;
                func_80021ED8(tag[0], 0xFC, 0);
                if (tag[1] >= 0)
                    func_8003BB10(moby, tag[1], 0);
            }
            if (value & 0xF)
                func_80055B18(moby);
            break;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_41/moby/func_level_41_80087950.s SHA256 30b2d1877e0e38750beef783cdfbc7fed23c0802a1394260ad9110d799e01011. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Controller87950Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

short Controller87950ConfigureHudEntry() __asm__("func_8002803C");                     /* extern */
unsigned char Controller87950ResetHudEntryByHandle() __asm__("func_80028154");         /* extern */
int Controller87950CountTimerDown() __asm__("func_800359A4");                          /* extern */
int Controller87950TestPaddedRotatedBox() __asm__("func_80036220");                    /* extern */
int Controller87950RandBetween() __asm__("func_8003636C");                             /* extern */
unsigned char Controller87950RestoreOrClearTrackedSnapshot() __asm__("func_8003B74C"); /* extern */
int Controller87950PlanarHeadingLookup() __asm__("func_8004E880");                     /* extern */
int Controller87950ApproximatePlanarDistance() __asm__("func_8004F334");               /* extern */
extern int Controller87950_D_8006C550 __asm__("D_8006C550");
extern int Controller87950_D_8006C58C __asm__("D_8006C58C");
extern int Controller87950_D_8006C730 __asm__("D_8006C730");
extern unsigned char Controller87950_D_8006C7B4 __asm__("D_8006C7B4");
extern int Controller87950_D_8006C7C4 __asm__("D_8006C7C4");
extern unsigned char Controller87950_D_8006D088 __asm__("D_8006D088");
extern int Controller87950_D_8006E160 __asm__("D_8006E160");
extern int Controller87950_D_8006E168 __asm__("D_8006E168");
extern unsigned char Controller87950_D_80070300 __asm__("D_80070300");
extern unsigned char Controller87950_D_80070328 __asm__("D_80070328");
extern unsigned char Controller87950_D_800716AC __asm__("D_800716AC");
extern unsigned char Controller87950_D_level_41_80074A40 __asm__("D_level_41_80074A40");
extern unsigned char Controller87950_func_80027A60 __asm__("func_80027A60");
extern unsigned char Controller87950_func_80027EE4 __asm__("func_80027EE4");
extern unsigned char Controller87950_func_80029AA0 __asm__("func_80029AA0");
extern unsigned char* Controller87950_unk_ovlheader_80074370 __asm__("unk_ovlheader_80074370");

void func_level_41_80087950(void* inputOwner) {
    register void* owner __asm__("$16") = inputOwner;
    /* Original frame: scratch starts at SP+0x20; signed16 candidates at
     * SP+0x30+index*2; saves start at SP+0x48. Pointer offsets are bytes.
     * Owner+0x48 uses both halfword/byte reads and byte writes in this stream.
     * Empty constraints emit no opcode. Helper semantics/units/cadence are open.
     */
    struct {
        int sp20, sp24, sp28, pad2C, pad30, pad34, pad38, pad3C, pad40, pad44;
    } originalFrame;

    register int* initialWords5 __asm__("$5");
    register int copyWord2 __asm__("$2");
    register int copyWord3 __asm__("$3");
    register int copyWord4 __asm__("$4");
    register int tableEntry __asm__("$2");
    register int* stateField4 __asm__("$4");
    register int returnWord2 __asm__("$2");
    register short scannedIndexWord __asm__("$17");
    register int scanCountWord __asm__("$21");
    register int nextHalfword2 __asm__("$2");
    register int* selectedInitialWord __asm__("$3");
    register int callbackWord7 __asm__("$7");
    register int poolWord2 __asm__("$2");
    register int poolWord3 __asm__("$3");
    register int poolWord4 __asm__("$4");
    register int poolWord5 __asm__("$5");
    register int nodeArgument4 __asm__("$4");
    register int nodeArgument5 __asm__("$5");
    int privateWordCFirst;
    int privateWord14First;
    int privateWord14Later;
    int indexTimesSix;
    register int stateWord3 __asm__("$3");
    register int privateWord8 __asm__("$3");
    register int candidateCount __asm__("$19");
    register unsigned short* tableCursor __asm__("$20");
    register int stateRead4 __asm__("$4");
    unsigned char archiveByte;
    register void* scannedPoolRecord __asm__("$16");
    register void* selectedPoolRecord __asm__("$16");
    register void* privateData __asm__("$18");

    MATCHING_KEEP(owner);
    privateData = ((Moby*)owner)->mobyTag;
    MATCHING_KEEP_CLOBBER(privateData, "memory");
    initialWords5 = (int*)&Controller87950_D_level_41_80074A40;
    MATCHING_KEEP_CLOBBER(initialWords5, "memory");
    copyWord2 = initialWords5[0];
    copyWord3 = initialWords5[1];
    copyWord4 = initialWords5[2];
    MATCHING_KEEP3(copyWord2, copyWord3, copyWord4);
    originalFrame.sp20 = copyWord2;
    originalFrame.sp24 = copyWord3;
    originalFrame.sp28 = copyWord4;
    if (Controller87950Field(owner, unsigned short*, 0x48) == 1) {
        if (Controller87950TestPaddedRotatedBox(&Controller87950_D_80070328, privateData + 0x18, 0,
                                                0x2800) == 0) {
            Controller87950Field(((Controller87950Field(privateData, int*, 0x30) * 0x58) +
                                  Controller87950_D_8006C550),
                                 signed char*, 0x48) = 0x18;
            privateWordCFirst = Controller87950Field(privateData, int*, 0xC);
            Controller87950Field(privateData, short*, 0) = 0;
            Controller87950Field(privateData, short*, 2) = 0;
            Controller87950Field(privateData, int*, 8) = 0;
            if (privateWordCFirst != 0) {
                Controller87950ResetHudEntryByHandle(privateWordCFirst);
            }
            privateWord14First = Controller87950Field(privateData, int*, 0x14);
            Controller87950Field(privateData, int*, 0xC) = 0;
            Controller87950Field(privateData, int*, 0x10) = 0;
            if (privateWord14First != 0) {
                Controller87950ResetHudEntryByHandle(privateWord14First);
            }
            Controller87950Field(privateData, int*, 0x14) = 0;
            ((Moby*)owner)->state = 0x15;
            Controller87950_D_8006E160 = 0;
            return;
        }
        goto stateDispatch;
    }
    if ((((Moby*)owner)->substate == 1) &&
        (Controller87950ApproximatePlanarDistance(owner + 0xC, &Controller87950_D_80070328) <
         0x3C8C)) {
        ((Moby*)owner)->substate = 0U;
        Controller87950_D_8006E160 = 0x21;
        Controller87950_D_8006E168 = Controller87950PlanarHeadingLookup(
            Controller87950Field(owner, int*, 0xC) -
                Controller87950Field(&Controller87950_D_80070328, int*, 0),
            ((Moby*)owner)->position.y - Controller87950Field(&Controller87950_D_80070328, int*, 4),
            0);
    }
stateDispatch:
    stateRead4 = (unsigned char)Controller87950Field(owner, unsigned short*, 0x48);
    returnWord2 = 0x54;
    MATCHING_KEEP2(stateRead4, returnWord2);
    stateWord3 = stateRead4 & 0xFF;
    if (stateWord3 != returnWord2) {
        if (stateWord3 == 4) {
            if (Controller87950CountTimerDown(privateData, 2) != 0) {
                Controller87950_D_8006E160 = 0;
                Controller87950ResetHudEntryByHandle(Controller87950Field(privateData, int*, 0x14));
                Controller87950ResetHudEntryByHandle(Controller87950Field(privateData, int*, 0xC));
                ((Moby*)owner)->state = 0x54;
            }
        } else if ((unsigned int)(stateRead4 - 0x14) >= 2U) {
            MATCHING_OBSERVE(stateRead4);
            if (stateWord3 == 0) {
                returnWord2 = 0xFF;
                MATCHING_KEEP(returnWord2);
                stateField4 = &Controller87950_D_8006E160;
                MATCHING_KEEP_CLOBBER(stateField4, "$3");
                ((Moby*)owner)->updateDistance = returnWord2;
                Controller87950Field(privateData, short*, 0) = 0;
                Controller87950Field(privateData, short*, 2) = 0;
                Controller87950Field(privateData, int*, 8) = 0;
                Controller87950Field(privateData, int*, 0x10) = 0;
                if (*stateField4 != 0x21) {
                    *stateField4 = 0x21;
                    Controller87950_D_8006E168 = Controller87950PlanarHeadingLookup(
                        ((Moby*)owner)->position.x -
                            Controller87950Field(&Controller87950_D_80070328, int*, 0),
                        ((Moby*)owner)->position.y -
                            Controller87950Field(&Controller87950_D_80070328, int*, 4),
                        0);
                }
                if (Controller87950Field(privateData, int*, 0x14) == 0) {
                    nodeArgument4 = 0x12;
                    nodeArgument5 = 3;
                    poolWord2 = (int)&originalFrame.sp20;
                    poolWord3 = Controller87950_D_8006C7C4;
                    callbackWord7 = (int)Controller87950_unk_ovlheader_80074370;
                    __asm__(""
                            : "=r"(callbackWord7)
                            : "0"(callbackWord7), "r"(poolWord2), "r"(poolWord3),
                              "r"(nodeArgument4), "r"(nodeArgument5));
                    poolWord3 <<= 2;
                    selectedInitialWord = (int*)(poolWord3 + poolWord2);
                    MATCHING_KEEP(selectedInitialWord);
                    Controller87950Field(privateData, int*, 0x10) = (int)*selectedInitialWord;
                    Controller87950Field(privateData, int*, 0x14) =
                        (int)Controller87950ConfigureHudEntry(nodeArgument4, nodeArgument5, 0, 0,
                                                              callbackWord7, privateData + 0x10,
                                                              *selectedInitialWord);
                }
                if (Controller87950Field(privateData, int*, 0xC) == 0) {
                    Controller87950Field(privateData, int*, 0xC) =
                        (int)Controller87950ConfigureHudEntry(
                            0x17, 0x19A, &Controller87950_func_80027EE4,
                            &Controller87950_func_80027A60, &Controller87950_func_80029AA0,
                            privateData + 8, Controller87950Field(privateData, int*, 4));
                }
                ((Moby*)owner)->state = 1;
                return;
            } else if (stateWord3 == 0x56) {
                Controller87950_D_8006E160 = 0x21;
                Controller87950_D_8006E168 = (int)((Moby*)owner)->angle.yaw;
                ((Moby*)owner)->state = 0x14;
                return;
            } else {
                if (stateWord3 == 0x52) {
                    stateWord3 = 0x21;
                    MATCHING_KEEP(stateWord3);
                    stateField4 = &Controller87950_D_8006E160;
                    MATCHING_KEEP(stateField4);
                    if (*stateField4 != stateWord3) {
                        *stateField4 = stateWord3;
                        Controller87950_D_8006E168 = Controller87950PlanarHeadingLookup(
                            ((Moby*)owner)->position.x -
                                Controller87950Field(&Controller87950_D_80070328, int*, 0),
                            ((Moby*)owner)->position.y -
                                Controller87950Field(&Controller87950_D_80070328, int*, 4),
                            0);
                    }
                    ((Moby*)owner)->state = 1;
                }
                if ((unsigned char)Controller87950Field(owner, unsigned short*, 0x48) == 0x50) {
                    Controller87950Field(&Controller87950_D_80070328, int*, 0x20C) =
                        (int)(Controller87950Field(&Controller87950_D_80070328, int*, 0x20C) |
                              0x10000002);
                    return;
                }
                if (Controller87950Field(privateData, int*, 8) >=
                    Controller87950Field(privateData, int*, 4)) {
                    ((Moby*)owner)->state = 4;
                    nextHalfword2 = 0x3C;
                    goto storeNextHalfword;
                }
                if (Controller87950CountTimerDown(privateData + 0x10, 4) != 0) {
                    privateWord14Later = Controller87950Field(privateData, int*, 0x14);
                    if (privateWord14Later != 0) {
                        Controller87950ResetHudEntryByHandle(privateWord14Later);
                        Controller87950ResetHudEntryByHandle(
                            Controller87950Field(privateData, int*, 0xC));
                        poolWord2 = Controller87950_D_8006C7B4 & 4;
                        MATCHING_KEEP_CLOBBER(poolWord2, "memory");
                        Controller87950Field(privateData, int*, 0x14) = 0;
                        if (!poolWord2 &&
                            !(*(&Controller87950_D_80070300 + Controller87950_D_8006C58C) & 4)) {
                            indexTimesSix = Controller87950_D_8006C58C * 6;
                            archiveByte = *(&Controller87950_D_800716AC + 2 + indexTimesSix);
                            if (archiveByte < 0xFFU) {
                                *(&Controller87950_D_800716AC + 2 + indexTimesSix) =
                                    archiveByte + 1;
                            }
                        }
                        Controller87950RestoreOrClearTrackedSnapshot(&Controller87950_D_8006D088);
                    }
                }
                if (Controller87950CountTimerDown(privateData, 2) != 0) {
                    scanCountWord = 0;
                    if (Controller87950Field(privateData, short*, 2) <
                        (Controller87950Field(privateData, int*, 4) -
                         Controller87950Field(privateData, int*, 8))) {
                        candidateCount = 0;
                        tableCursor = Controller87950Field((((Moby*)owner)->animationRun * 4) +
                                                               Controller87950_D_8006C730,
                                                           unsigned short**, 0);
                    scanTableEntry:
                        poolWord4 = (int)&Controller87950_D_80070328;
                        MATCHING_KEEP_CLOBBER(poolWord4, "memory");
                        poolWord3 = *tableCursor;
                        poolWord5 = Controller87950_D_8006C550;
                        __asm__("" : "=r"(poolWord5) : "0"(poolWord5), "r"(poolWord3));
                        poolWord3 &= 0x7FFF;
                        MATCHING_KEEP(poolWord3);
                        poolWord2 = poolWord3 * 11;
                        poolWord2 <<= 3;
                        scannedPoolRecord = (void*)(poolWord5 + poolWord2);
                        __asm__(""
                                : "=r"(scannedPoolRecord)
                                : "0"(scannedPoolRecord), "r"(poolWord3));
                        poolWord5 = (int)scannedPoolRecord + 0xC;
                        scannedIndexWord = poolWord3;
                        if (((unsigned int)(Controller87950ApproximatePlanarDistance(poolWord4,
                                                                                     poolWord5) -
                                            0x800) < 0x801U) &&
                            (Controller87950Field(scannedPoolRecord, unsigned char*, 0x49) == 0) &&
                            (Controller87950Field(scannedPoolRecord, short*, 0x36) != 0x3C9)) {
                            Controller87950Field(
                                ((candidateCount * 2) + (unsigned char*)&originalFrame.sp20),
                                short*, 0x10) = scannedIndexWord;
                            candidateCount += 1;
                        }
                        tableEntry = Controller87950Field(tableCursor, short*, 0);
                        MATCHING_KEEP(tableEntry);
                        tableCursor += 1;
                        if (tableEntry >= 0) {
                            if (candidateCount < 0xA) {
                                returnWord2 = scanCountWord + 1;
                                MATCHING_KEEP(returnWord2);
                                scanCountWord = returnWord2;
                                MATCHING_KEEP(returnWord2);
                                if ((short)returnWord2 < 0x32) {
                                    goto scanTableEntry;
                                }
                            }
                        }
                        if (candidateCount != 0) {
                            poolWord3 = Controller87950Field(
                                ((unsigned char*)&originalFrame.sp20 +
                                 (Controller87950RandBetween(0, candidateCount - 1) * 2)),
                                short*, 0x10);
                            MATCHING_KEEP(poolWord3);
                            poolWord2 = poolWord3 * 11;
                            MATCHING_KEEP(poolWord2);
                            poolWord3 = Controller87950_D_8006C550;
                            poolWord2 <<= 3;
                            selectedPoolRecord = (void*)(poolWord3 + poolWord2);
                            MATCHING_KEEP(selectedPoolRecord);
                            Controller87950Field(selectedPoolRecord, signed char*, 0x49) = 1;
                            if (Controller87950Field(selectedPoolRecord, short*, 0x36) == 0x235) {
                                Controller87950Field(privateData, short*, 2) =
                                    (short)((unsigned short)Controller87950Field(privateData,
                                                                                 short*, 2) +
                                            1);
                            }
                            privateWord8 = Controller87950Field(privateData, int*, 8);
                            if (privateWord8 >= 9) {
                                nextHalfword2 = 0xA;
                            } else if (privateWord8 >= 6) {
                                nextHalfword2 = 0x1E;
                            } else if (privateWord8 >= 4) {
                                nextHalfword2 = 0x32;
                            } else {
                                poolWord2 = privateWord8 < 2;
                                MATCHING_KEEP(poolWord2);
                                if (poolWord2)
                                    nextHalfword2 = 0xC8;
                                else
                                    nextHalfword2 = 0x64;
                                MATCHING_OBSERVE(privateWord8);
                            }
                        storeNextHalfword:
                            Controller87950Field(privateData, short*, 0) = nextHalfword2;
                        }
                    }
                }
            }
        }
    }
}
#undef Controller87950Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_41/moby", D_level_41_80074A40);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_41/moby", D_level_41_80074A4C);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_41/moby", D_level_41_80074A58);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_41/moby", D_level_41_80074A64);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80087F9C.
* AI generated; not human reviewed. All829 instructions,six selectors and
* every actual destination must match:835 recorded original owned words.
* FrameB0hex176,S0..S6/RA,SP10..8F retains original storage and widths.
* Verified level43 func80088980 supplies the shared complete body. Original
* target80..94 adds owner+72,state5 and two descriptor callbacks. Original
* S6/S4 descriptor addresses survive those calls and supply151/158. These
* target differences are independently decoded;original table references
* map to three separately audited12-byte level41 initializer objects.
* All36 original initializer bytes copy toSP10/14/18,SP20/24/28,SP30/34/38.
* The target third table ends at its switch table;no donor padding is added.
* Original negative-index result is compared plus1 before count-2 replaces
* it. Count=-1,index=-1 retains-3. Separate absolute player byte/word aliases,
* complete pointer consumers,signed trig samples,full products/shifts and
* complete signed /126 preserve original widths,physical entries and order.
* Height helper observes+1500 before each call;the-1500 reload follows it.
* SP29 denotes the initialized ABI frame address. Pointer,index,heading,
* descriptor,step,height and cursor roles have independent live phases.
* Empty metadata consumes complete initialized values/addresses/written
* fields or clobbers dead registers before whole producers;zero CPU words.
* No opcode asm,partialHI/LO,fixedFP,undefined incoming saved value,live fixed
* alias overlap or padding reads. Compiler/filter/flags remain unchanged.
* Confidence is binary identity after every native/linked/actual-target,
* selector/initializer byte and full EXE/every-overlay retail hash gate.
* Units/fixed point,index domain,complete helper/caller chains,cadence beyond
* invocation,Rev1 mapping and synchronized runtime remain open. Next:human
* review and retail captures. Raw fields have no invented semantic labels.
*/
/* Original assembly SHA256 ce58da50af45df69a7aa2c814edf89a5e3127eeee517d5ef923b9f07a36a19c1 */
#define Level41_87F9CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level41_87F9CSetCameraOwnerAndControlWordView1() __asm__("func_80013ACC");
int Level41_87F9CQueryWorldHeightView1() __asm__("func_8001A358");
int Level41_87F9CApproachAngle8View1() __asm__("func_80036018");
int Level41_87F9CSubAngle8View1() __asm__("func_8003613C");
int Level41_87F9CRegisterTrackedValueView1() __asm__("func_8003B7B4");
int Level41_87F9CBuildOrientedInputPairView1() __asm__("func_80040F48");
int Level41_87F9CPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level41_87F9CClearVectorView1() __asm__("func_8004F168");
int Level41_87F9CCopyVectorView1() __asm__("func_8004F178");
int Level41_87F9CAddVectorView1() __asm__("func_8004F194");
int Level41_87F9CAbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level41_87F9CApproachByteAngleView1() __asm__("func_8004F2EC");
extern int Level41_87F9CData658A0View1 __asm__("D_800658A0");
extern int Level41_87F9CData65920View1 __asm__("D_80065920");
extern int Level41_87F9CData6C550View1 __asm__("D_8006C550");
extern int Level41_87F9CData6C58CView1 __asm__("D_8006C58C");
extern int Level41_87F9CData6C704View1 __asm__("D_8006C704");
extern unsigned char Level41_87F9CData6C7B4View1 __asm__("D_8006C7B4");
extern int Level41_87F9CData6C7C4View1 __asm__("D_8006C7C4");
extern int Level41_87F9CData6C7F8View1 __asm__("D_8006C7F8");
extern int Level41_87F9CData6D088View1 __asm__("D_8006D088");
extern int Level41_87F9CData6E160View1 __asm__("D_8006E160");
extern int Level41_87F9CData6E164View1 __asm__("D_8006E164");
extern int Level41_87F9CData70300View1 __asm__("D_80070300");
extern int Level41_87F9CData70328View1 __asm__("D_80070328");
extern int Level41_87F9CData716ACView1 __asm__("D_800716AC");
extern int Level41_87F9CData71918View1 __asm__("D_80071918");
extern int Level41_87F9CData7191CView1 __asm__("D_8007191C");
extern int Level41_87F9CData71920View1 __asm__("D_80071920");
extern int Level41_87F9CData71924View1 __asm__("D_80071924");
extern int (*Level41_87F9CData743A4View1)() __asm__("unk_ovlheader_800743A4");
extern int Level41_87F9CData74A4CView1[3] __asm__("D_level_41_80074A4C");
extern int Level41_87F9CData74A58View1[3] __asm__("D_level_41_80074A58");
extern int Level41_87F9CData74A64View1[3] __asm__("D_level_41_80074A64");
extern unsigned char Level41_87F9CData70328View2 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View3 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View4 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View5 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View6 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View7 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View8 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View9 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View10 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View11 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View12 __asm__("D_80070328 + 14");
extern unsigned char Level41_87F9CData70328View13 __asm__("D_80070328 + 14");
extern int Level41_87F9CData70328View14 __asm__("D_80070328 + 572");
extern unsigned char Level41_87F9CData70328View15 __asm__("D_80070328 + 554");
extern unsigned char Level41_87F9CData70328View16 __asm__("D_80070328 + 554");
extern int Level41_87F9CData70328View17 __asm__("D_80070328 + 564");
extern int Level41_87F9CData70328View18 __asm__("D_80070328 + 564");
void func_level_41_80087F9C(void* ownerParameter) {
    register void* ownerRecord21 __asm__("$21");
    register int privateThenActorCursor17 __asm__("$17"),
        retainedHeadingVectorOrHeightView16 __asm__("$16"),
        retainedIndexHeadingOrClass18 __asm__("$18"), retainedPlayerPathOrHeading19 __asm__("$19"),
        retainedDescriptorPathOrStep20 __asm__("$20"), retainedDescriptorOrStep22 __asm__("$22");
    register unsigned char* originalAbiStackAddress29 __asm__("$29");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C;
    } originalFrame;
    int temporaryWord4;
    int temporaryWord14;
    int temporaryWord9;
    int temporaryWord19;
    int temporaryWord1;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord13;
    int temporaryWord18;
    int temporaryWord20;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord21, completeOriginalDivisionScalar;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord15;
    ownerRecord21 = ownerParameter;
    MATCHING_KEEP(ownerRecord21);
    privateThenActorCursor17 = Level41_87F9CField(ownerRecord21, void**, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level41_87F9CData74A4CView1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level41_87F9CField(argumentWord5, int*, 0);
    rawWord3 = Level41_87F9CField(argumentWord5, int*, 4);
    argumentWord4 = Level41_87F9CField(argumentWord5, int*, 8);
    originalFrame.sp10 = rawWord2;
    originalFrame.sp14 = rawWord3;
    originalFrame.sp18 = argumentWord4;
    __asm__ volatile("" ::"m"(originalFrame.sp10), "m"(originalFrame.sp14),
                     "m"(originalFrame.sp18));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level41_87F9CData74A58View1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level41_87F9CField(argumentWord5, int*, 0);
    rawWord3 = Level41_87F9CField(argumentWord5, int*, 4);
    argumentWord4 = Level41_87F9CField(argumentWord5, int*, 8);
    originalFrame.sp20 = rawWord2;
    originalFrame.sp24 = rawWord3;
    originalFrame.sp28 = argumentWord4;
    __asm__ volatile("" ::"m"(originalFrame.sp20), "m"(originalFrame.sp24),
                     "m"(originalFrame.sp28));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)Level41_87F9CData74A64View1;
    MATCHING_KEEP(argumentWord5);
    rawWord2 = Level41_87F9CField(argumentWord5, int*, 0);
    rawWord3 = Level41_87F9CField(argumentWord5, int*, 4);
    argumentWord4 = Level41_87F9CField(argumentWord5, int*, 8);
    originalFrame.sp30 = rawWord2;
    originalFrame.sp34 = rawWord3;
    originalFrame.sp38 = argumentWord4;
    __asm__ volatile("" ::"m"(originalFrame.sp30), "m"(originalFrame.sp34),
                     "m"(originalFrame.sp38));
    temporaryWord16 = Level41_87F9CField(ownerRecord21, unsigned char*, 0x48);
    switch (temporaryWord16) {
        case 5:
            if (!(Level41_87F9CData6C7B4View1 & 2) &&
                !(Level41_87F9CField((int)&Level41_87F9CData70300View1, unsigned char*,
                                     Level41_87F9CData6C58CView1) &
                  2)) {
                temporaryWord1 = Level41_87F9CData6C58CView1 * 6;
                temporaryWord17 = Level41_87F9CField((int)&Level41_87F9CData716ACView1,
                                                     unsigned char*, 1 + temporaryWord1);
                if (temporaryWord17 < 0xFFU) {
                    Level41_87F9CField((int)&Level41_87F9CData716ACView1, unsigned char*,
                                       1 + temporaryWord1) = temporaryWord17 + 1;
                }
            }
            Level41_87F9CField(ownerRecord21, unsigned char*, 0x48) = 0U;
            return;
        case 0:
            retainedPlayerPathOrHeading19 = (int)&Level41_87F9CData70328View1 + 184;
            MATCHING_KEEP(retainedPlayerPathOrHeading19);
            rawWord2 = Level41_87F9CField(retainedPlayerPathOrHeading19, int*, 0);
            retainedHeadingVectorOrHeightView16 = (int)ownerRecord21 + 72;
            if (rawWord2 == 0) {
                argumentWord4 = retainedHeadingVectorOrHeightView16;
                argumentWord5 = 1;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$22");
                retainedDescriptorOrStep22 = (int)&Level41_87F9CData6D088View1;
                argumentWord6 = retainedDescriptorOrStep22;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord6, "$2");
                rawWord2 = 5;
                Level41_87F9CField(ownerRecord21, unsigned char*, 72) = rawWord2;
                Level41_87F9CRegisterTrackedValueView1(argumentWord4, argumentWord5, argumentWord6);
                argumentWord4 = retainedHeadingVectorOrHeightView16;
                argumentWord5 = 1;
                MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$20");
                retainedDescriptorPathOrStep20 = (int)&Level41_87F9CData6C7F8View1;
                Level41_87F9CRegisterTrackedValueView1(argumentWord4, argumentWord5,
                                                       retainedDescriptorPathOrStep20);
                MATCHING_BARRIER_VOLATILE("$16");
                retainedHeadingVectorOrHeightView16 = (int)&originalFrame.sp40;
                argumentWord4 = retainedHeadingVectorOrHeightView16;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
                retainedIndexHeadingOrClass18 = retainedPlayerPathOrHeading19 - 184;
                Level41_87F9CCopyVectorView1(argumentWord4, retainedIndexHeadingOrClass18);
                originalFrame.sp48 += 0x200;
                if ((Level41_87F9CQueryWorldHeightView1(&originalFrame.sp40, 0x1000) != 0) &&
                    ((Level41_87F9CData71924View1 & 0xF) ==
                     Level41_87F9CField(privateThenActorCursor17, int*, 0x1C))) {
                    temporaryWord3 = Level41_87F9CField(privateThenActorCursor17, void**, 0);
                    temporaryWord5 =
                        (int)(Level41_87F9CField(temporaryWord3, unsigned short*, 0) << 0x10) >>
                        0x11;
                    Level41_87F9CField(Level41_87F9CField(privateThenActorCursor17, void**, 0),
                                       short*, 2) =
                        Level41_87F9CData743A4View1(retainedIndexHeadingOrClass18, temporaryWord3,
                                                    temporaryWord5, temporaryWord5);
                    temporaryWord2 = Level41_87F9CField(privateThenActorCursor17, void**, 0);
                    temporaryWord4 = Level41_87F9CField(temporaryWord2, short*, 2);
                    if ((temporaryWord4 + 1) <
                        (short)Level41_87F9CField(temporaryWord2, unsigned short*, 0)) {
                        temporaryWord10 =
                            (temporaryWord4 * 0x10) + Level41_87F9CField(temporaryWord2, int*, 0xC);
                        temporaryWord6 = Level41_87F9CField(temporaryWord10, int*, 0x10);
                        Level41_87F9CField(privateThenActorCursor17, int*, 0x14) =
                            Level41_87F9CPlanarHeadingLookupView1(
                                temporaryWord6 - Level41_87F9CField(temporaryWord10, int*, 0),
                                Level41_87F9CField(temporaryWord10, int*, 0x14) -
                                    Level41_87F9CField(temporaryWord10, int*, 4),
                                0);
                        Level41_87F9CSetCameraOwnerAndControlWordView1(ownerRecord21, 0xD);
                        retainedHeadingVectorOrHeightView16 = ownerRecord21 + 0x4A;
                        Level41_87F9CField(ownerRecord21, unsigned char*, 0x4A) = 0xFF;
                        Level41_87F9CRegisterTrackedValueView1(retainedHeadingVectorOrHeightView16,
                                                               1, retainedDescriptorOrStep22);
                        Level41_87F9CRegisterTrackedValueView1(retainedHeadingVectorOrHeightView16,
                                                               1, retainedDescriptorPathOrStep20);
                        Level41_87F9CField(ownerRecord21, unsigned char*, 0x48) = 1U;
                        Level41_87F9CClearVectorView1(privateThenActorCursor17 + 8);
                        MATCHING_KEEP(retainedPlayerPathOrHeading19);
                        rawWord2 = Level41_87F9CField(retainedPlayerPathOrHeading19, int*, -4);
                        rawWord3 = Level41_87F9CData6C7C4View1;
                        rawWord2 >>= 5;
                        Level41_87F9CField(privateThenActorCursor17, short*, 26) = rawWord2;
                        rawWord3 *= 4;
                        rawWord2 = (int)originalAbiStackAddress29 + rawWord3;
                        MATCHING_KEEP(rawWord2);
                        rawWord2 = Level41_87F9CField(rawWord2, int*, 16);
                        Level41_87F9CField(privateThenActorCursor17, short*, 24) = rawWord2;
                        return;
                    }
                }
            }
        default:
            return;
        case 1:
            retainedDescriptorPathOrStep20 =
                Level41_87F9CField(privateThenActorCursor17, void**, 0);
            retainedIndexHeadingOrClass18 = Level41_87F9CData743A4View1(
                (int)&Level41_87F9CData70328View1, retainedDescriptorPathOrStep20,
                Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 2), 2);
            rawWord2 = retainedIndexHeadingOrClass18 + 1;
            if (retainedIndexHeadingOrClass18 >= 0) {
                Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 2) =
                    retainedIndexHeadingOrClass18;
                goto readOriginalPathEntry180;
            }
            rawWord3 = Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 0);
            rawWord2 = rawWord2 < rawWord3;
            retainedIndexHeadingOrClass18 = rawWord3 - 2;
            if (rawWord2)
                retainedIndexHeadingOrClass18 =
                    Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 2);
        readOriginalPathEntry180:
            temporaryWord18 =
                Level41_87F9CField(((retainedIndexHeadingOrClass18 * 0x10) +
                                    Level41_87F9CField(retainedDescriptorPathOrStep20, int*, 0xC)),
                                   int*, 0xC);
            if (temporaryWord18 == 1) {
                temporaryWord20 =
                    Level41_87F9CField(&originalFrame.sp10, int*, Level41_87F9CData6C7C4View1 * 4) *
                    2;
                goto writeOriginalPathValue204;
            }
            if (temporaryWord18 == 0) {
                temporaryWord20 =
                    Level41_87F9CField(&originalFrame.sp10, int*, Level41_87F9CData6C7C4View1 * 4);
            writeOriginalPathValue204:
                Level41_87F9CField(privateThenActorCursor17, short*, 0x18) = (short)temporaryWord20;
            }
            argumentWord5 = Level41_87F9CField(privateThenActorCursor17, short*, 0x1A);
            rawWord3 = Level41_87F9CField(privateThenActorCursor17, short*, 0x18);
            rawWord2 = argumentWord5 < rawWord3;
            argumentWord4 = argumentWord5;
            if (rawWord2) {
                rawWord2 = argumentWord4 + Level41_87F9CField(&originalFrame.sp20, int*,
                                                              Level41_87F9CData6C7C4View1 * 4);
                goto writeOriginalAdjustedValue230;
            }
            rawWord2 = rawWord3 < argumentWord5;
            if (rawWord2) {
                rawWord2 = argumentWord4 - Level41_87F9CField(&originalFrame.sp30, int*,
                                                              Level41_87F9CData6C7C4View1 * 4);
            writeOriginalAdjustedValue230:
                Level41_87F9CField(privateThenActorCursor17, short*, 0x1A) = rawWord2;
            }
            argumentWord5 = 0x10008000;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$22");
            retainedDescriptorOrStep22 = 3;
            argumentWord6 = 0;
            argumentWord4 = (int)&Level41_87F9CData70328View1 + 524;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(argumentWord6));
            retainedPlayerPathOrHeading19 = Level41_87F9CData70328View2;
            rawWord2 = Level41_87F9CField(argumentWord4, int*, 0);
            rawWord3 = 49;
            Level41_87F9CData70328View14 = rawWord3;
            rawWord2 |= argumentWord5;
            Level41_87F9CField(argumentWord4, int*, 0) = rawWord2;
            temporaryWord12 = (retainedIndexHeadingOrClass18 * 0x10) +
                              Level41_87F9CField(retainedDescriptorPathOrStep20, int*, 0xC);
            temporaryWord7 = Level41_87F9CField(temporaryWord12, int*, 0x10);
            retainedHeadingVectorOrHeightView16 = Level41_87F9CPlanarHeadingLookupView1(
                temporaryWord7 - Level41_87F9CField(temporaryWord12, int*, 0),
                Level41_87F9CField(temporaryWord12, int*, 0x14) -
                    Level41_87F9CField(temporaryWord12, int*, 4),
                0);
            argumentWord4 = Level41_87F9CSubAngle8View1(retainedHeadingVectorOrHeightView16,
                                                        Level41_87F9CData70328View3);
            rawWord3 = argumentWord4;
            if (argumentWord4 < 0)
                rawWord3 = -rawWord3;
            if (rawWord3 >= 0x51) {
                rawWord2 = retainedHeadingVectorOrHeightView16 + 128;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                retainedPlayerPathOrHeading19 = rawWord2 - argumentWord4;
                if (Level41_87F9CAbsoluteByteAngleDeltaView1(
                        retainedPlayerPathOrHeading19,
                        Level41_87F9CField(privateThenActorCursor17, int*, 0x14)) >= 0x31) {
                    retainedDescriptorOrStep22 = 6;
                }
            } else {
                rawWord2 = rawWord3 < 49;
                if (!rawWord2) {
                    retainedPlayerPathOrHeading19 = Level41_87F9CApproachAngle8View1(
                        Level41_87F9CData70328View4, retainedHeadingVectorOrHeightView16, 0x30);
                }
            }
            argumentWord5 = Level41_87F9CField(privateThenActorCursor17, int*, 20);
            rawWord3 = Level41_87F9CField(privateThenActorCursor17, short*, 26);
            argumentWord4 = argumentWord5 * 2;
            rawWord2 = Level41_87F9CField((int)&Level41_87F9CData65920View1, short*, argumentWord4);
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp50 = rawWord2;
            rawWord3 = Level41_87F9CField(privateThenActorCursor17, short*, 26);
            rawWord2 = Level41_87F9CField((int)&Level41_87F9CData658A0View1, short*, argumentWord4);
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord3, rawWord2, "memory");
            argumentWord6 = retainedDescriptorOrStep22;
            argumentWord7 = (argumentWord6 >> 1) + 1;
            argumentWord4 = retainedPlayerPathOrHeading19;
            originalFrame.sp58 = 0;
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp54 = rawWord2;
            rawWord2 = Level41_87F9CApproachByteAngleView1(argumentWord4, argumentWord5,
                                                           argumentWord6, argumentWord7);
            retainedHeadingVectorOrHeightView16 = (int)&Level41_87F9CData70328View1 + 556;
            __asm__(""
                    : "=r"(retainedHeadingVectorOrHeightView16)
                    : "0"(retainedHeadingVectorOrHeightView16), "r"(rawWord2));
            argumentWord4 = retainedHeadingVectorOrHeightView16;
            argumentWord5 = retainedHeadingVectorOrHeightView16 - 556;
            argumentWord6 = (int)&originalFrame.sp50;
            Level41_87F9CField(privateThenActorCursor17, int*, 20) = rawWord2;
            Level41_87F9CAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 0x228) = 0;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 0x229) = 0;
            Level41_87F9CBuildOrientedInputPairView1(&originalFrame.sp60, 1);
            if (originalFrame.sp60 >= 0xB) {
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level41_87F9CField(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  4);
            } else if (originalFrame.sp60 < -0xA) {
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level41_87F9CField(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) -
                                  4);
            } else if (originalFrame.sp60 != 0) {
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level41_87F9CField(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  ((originalFrame.sp60 * 8) / 126));
            } else {
                Level41_87F9CField((int)&Level41_87F9CData70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level41_87F9CData70328View5;
            }
            retainedHeadingVectorOrHeightView16 = (int)&Level41_87F9CData70328View1 + 0x234;
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
            rawWord2 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0);
            argumentWord5 = 4096;
            rawWord2 += 1500;
            Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
            temporaryWord13 = Level41_87F9CQueryWorldHeightView1(argumentWord4, argumentWord5);
            argumentWord4 = privateThenActorCursor17 + 8;
            if (temporaryWord13 == 0) {
                rawWord2 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0);
                argumentWord5 = (int)&originalFrame.sp50;
                goto resetOriginalState564;
            }
            Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = temporaryWord13;
            Level41_87F9CField(privateThenActorCursor17, short*, 4) = 0;
            rawWord3 = Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 0);
            rawWord2 = retainedIndexHeadingOrClass18 + 1;
            rawWord2 = rawWord2 < rawWord3;
            if (!rawWord2)
                Level41_87F9CField(ownerRecord21, unsigned char*, 72) = 2;
            rawWord2 = Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 2);
            rawWord3 = Level41_87F9CField(retainedDescriptorPathOrStep20, short*, 0);
            retainedIndexHeadingOrClass18 = rawWord2 + 6;
            argumentWord4 = (int)ownerRecord21 + 12;
            if (retainedIndexHeadingOrClass18 >= rawWord3)
                retainedIndexHeadingOrClass18 = rawWord3 - 1;
            rawWord2 = Level41_87F9CField(retainedDescriptorPathOrStep20, int*, 12);
            argumentWord5 = retainedIndexHeadingOrClass18 * 16;
            goto copyOriginalPathVector611;
        case 2:
            retainedPlayerPathOrHeading19 = Level41_87F9CField(privateThenActorCursor17, void**, 0);
            temporaryWord14 =
                (unsigned short)Level41_87F9CField(privateThenActorCursor17, short*, 0x1A) - 8;
            Level41_87F9CField(privateThenActorCursor17, short*, 0x1A) = temporaryWord14;
            if ((short)temporaryWord14 < 9) {
                temporaryWord19 = (int)&Level41_87F9CData70328View1 + 0x20C;
                Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 0x23C) = 0;
                Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 0x20C) =
                    (int)(Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 0x20C) |
                          0x10008000);
                Level41_87F9CCopyVectorView1(temporaryWord19 + 0x20, temporaryWord19 - 0x20C);
                Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 0x228) = 0;
                Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 0x229) = 0;
                Level41_87F9CField((int)&Level41_87F9CData70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level41_87F9CData70328View6;
                Level41_87F9CField(ownerRecord21, unsigned char*, 0x48) = 4U;
                return;
            }
            argumentWord5 = 0x10008000;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$20");
            retainedDescriptorPathOrStep20 = 3;
            argumentWord6 = 0;
            argumentWord4 = (int)&Level41_87F9CData70328View1 + 524;
            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(argumentWord6));
            retainedIndexHeadingOrClass18 = Level41_87F9CData70328View7;
            rawWord2 = Level41_87F9CField(argumentWord4, int*, 0);
            rawWord3 = 49;
            Level41_87F9CData70328View14 = rawWord3;
            rawWord2 |= argumentWord5;
            Level41_87F9CField(argumentWord4, int*, 0) = rawWord2;
            temporaryWord15 =
                ((short)Level41_87F9CField(retainedPlayerPathOrHeading19, unsigned short*, 0) *
                 0x10) +
                Level41_87F9CField(retainedPlayerPathOrHeading19, int*, 0xC);
            temporaryWord8 = Level41_87F9CField(temporaryWord15, int*, -0x10);
            retainedHeadingVectorOrHeightView16 = Level41_87F9CPlanarHeadingLookupView1(
                temporaryWord8 - Level41_87F9CField(temporaryWord15, int*, -0x20),
                Level41_87F9CField(temporaryWord15, int*, -0xC) -
                    Level41_87F9CField(temporaryWord15, int*, -0x1C),
                0);
            argumentWord4 = Level41_87F9CSubAngle8View1(retainedHeadingVectorOrHeightView16,
                                                        Level41_87F9CData70328View8);
            rawWord3 = argumentWord4;
            if (argumentWord4 < 0)
                rawWord3 = -rawWord3;
            if (rawWord3 >= 0x51) {
                rawWord2 = retainedHeadingVectorOrHeightView16 + 128;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord4));
                retainedIndexHeadingOrClass18 = rawWord2 - argumentWord4;
                if (Level41_87F9CAbsoluteByteAngleDeltaView1(
                        retainedIndexHeadingOrClass18,
                        Level41_87F9CField(privateThenActorCursor17, int*, 0x14)) >= 0x31) {
                    retainedDescriptorPathOrStep20 = 6;
                }
            } else {
                rawWord2 = rawWord3 < 49;
                if (!rawWord2) {
                    retainedIndexHeadingOrClass18 = Level41_87F9CApproachAngle8View1(
                        Level41_87F9CData70328View9, retainedHeadingVectorOrHeightView16, 0x30);
                }
            }
            argumentWord5 = Level41_87F9CField(privateThenActorCursor17, int*, 20);
            rawWord3 = Level41_87F9CField(privateThenActorCursor17, short*, 26);
            argumentWord4 = argumentWord5 * 2;
            rawWord2 = Level41_87F9CField((int)&Level41_87F9CData65920View1, short*, argumentWord4);
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp68 = rawWord2;
            rawWord3 = Level41_87F9CField(privateThenActorCursor17, short*, 26);
            rawWord2 = Level41_87F9CField((int)&Level41_87F9CData658A0View1, short*, argumentWord4);
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(rawWord3, rawWord2, "memory");
            argumentWord6 = retainedDescriptorPathOrStep20;
            argumentWord7 = (argumentWord6 >> 1) + 1;
            argumentWord4 = retainedIndexHeadingOrClass18;
            originalFrame.sp70 = 0;
            rawWord2 = (rawWord3 * rawWord2) >> 12;
            originalFrame.sp6C = rawWord2;
            rawWord2 = Level41_87F9CApproachByteAngleView1(argumentWord4, argumentWord5,
                                                           argumentWord6, argumentWord7);
            retainedHeadingVectorOrHeightView16 = (int)&Level41_87F9CData70328View1 + 556;
            __asm__(""
                    : "=r"(retainedHeadingVectorOrHeightView16)
                    : "0"(retainedHeadingVectorOrHeightView16), "r"(rawWord2));
            argumentWord4 = retainedHeadingVectorOrHeightView16;
            argumentWord5 = retainedHeadingVectorOrHeightView16 - 556;
            argumentWord6 = (int)&originalFrame.sp68;
            Level41_87F9CField(privateThenActorCursor17, int*, 20) = rawWord2;
            Level41_87F9CAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 0x228) = 0;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 0x229) = 0;
            Level41_87F9CBuildOrientedInputPairView1(&originalFrame.sp78, 1);
            if (originalFrame.sp78 >= 0xB) {
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level41_87F9CField(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  4);
            } else if (originalFrame.sp78 < -0xA) {
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level41_87F9CField(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) -
                                  4);
            } else if (originalFrame.sp78 != 0) {
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, signed char*, -2) =
                    (signed char)(Level41_87F9CField(retainedHeadingVectorOrHeightView16,
                                                     unsigned char*, -0x21E) +
                                  ((originalFrame.sp78 * 8) / 126));
            } else {
                Level41_87F9CField((int)&Level41_87F9CData70328View1, unsigned char*, 0x22A) =
                    (unsigned char)Level41_87F9CData70328View10;
            }
            retainedHeadingVectorOrHeightView16 = (int)&Level41_87F9CData70328View1 + 0x234;
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
            rawWord2 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0);
            argumentWord5 = 4096;
            rawWord2 += 1500;
            Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
            temporaryWord11 = Level41_87F9CQueryWorldHeightView1(argumentWord4, argumentWord5);
            argumentWord4 = privateThenActorCursor17 + 8;
            if (temporaryWord11 == 0) {
                rawWord2 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0);
                argumentWord5 = (int)&originalFrame.sp68;
            resetOriginalState564:
                rawWord2 -= 1500;
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
                Level41_87F9CField(ownerRecord21, unsigned char*, 72) = 3;
                Level41_87F9CField(privateThenActorCursor17, unsigned short*, 6) = 25;
                Level41_87F9CCopyVectorView1(argumentWord4, argumentWord5);
                return;
            }
            Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = temporaryWord11;
            Level41_87F9CField(privateThenActorCursor17, short*, 4) = 0;
            rawWord3 = Level41_87F9CField(retainedPlayerPathOrHeading19, short*, 2);
            rawWord2 = Level41_87F9CField(retainedPlayerPathOrHeading19, short*, 0);
            rawWord3 += 6;
            argumentWord4 = (int)ownerRecord21 + 12;
            if (rawWord3 < rawWord2)
                goto loadOriginalPathTable609;
            if (Level41_87F9CField(ownerRecord21, unsigned char*, 73) == 1)
                return;
            Level41_87F9CField(ownerRecord21, unsigned char*, 73) = 1;
            privateThenActorCursor17 = Level41_87F9CData6C550View1;
            rawWord2 = Level41_87F9CData6C704View1;
            retainedIndexHeadingOrClass18 = 132;
            if ((unsigned int)privateThenActorCursor17 < (unsigned int)rawWord2) {
                retainedHeadingVectorOrHeightView16 = privateThenActorCursor17 + 12;
                do {
                    if (Level41_87F9CField(retainedHeadingVectorOrHeightView16, short*, 42) ==
                        retainedIndexHeadingOrClass18)
                        Level41_87F9CCopyVectorView1(ownerRecord21 + 12,
                                                     retainedHeadingVectorOrHeightView16);
                    rawWord2 = Level41_87F9CData6C704View1;
                    MATCHING_KEEP_VOLATILE_CLOBBER(privateThenActorCursor17, "memory");
                    privateThenActorCursor17 += 88;
                    retainedHeadingVectorOrHeightView16 += 88;
                } while ((unsigned int)privateThenActorCursor17 < (unsigned int)rawWord2);
            }
            return;
        loadOriginalPathTable609:
            rawWord2 = Level41_87F9CField(retainedPlayerPathOrHeading19, int*, 12);
            argumentWord5 = rawWord3 * 16;
        copyOriginalPathVector611:
            Level41_87F9CCopyVectorView1(argumentWord4, rawWord2 + argumentWord5);
            return;
        case 4:
            retainedHeadingVectorOrHeightView16 = ownerRecord21 + 0x48;
            Level41_87F9CData6E160View1 = 0;
            Level41_87F9CData6E164View1 = 0;
            Level41_87F9CField(ownerRecord21, unsigned char*, 0x48) = 0U;
            Level41_87F9CRegisterTrackedValueView1(retainedHeadingVectorOrHeightView16, 1,
                                                   (int)&Level41_87F9CData6D088View1);
            Level41_87F9CRegisterTrackedValueView1(retainedHeadingVectorOrHeightView16, 1,
                                                   (int)&Level41_87F9CData6C7F8View1);
            return;
        case 3:
            temporaryWord9 = (int)&Level41_87F9CData70328View1 + 0x20C;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 0x23C) = 7;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 0x20C) =
                (int)(Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 0x20C) |
                      0x10008000);
            Level41_87F9CAddVectorView1(temporaryWord9 + 0x20, temporaryWord9 - 0x20C,
                                        privateThenActorCursor17 + 8);
            rawWord2 = Level41_87F9CData70328View11;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 552) = 0;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, signed char*, 553) = 0;
            Level41_87F9CData70328View15 = rawWord2;
            rawWord3 = Level41_87F9CField(privateThenActorCursor17, short*, 4);
            rawWord2 = Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 8);
            rawWord2 += rawWord3;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 564) = rawWord2;
            rawWord2 = Level41_87F9CField(privateThenActorCursor17, unsigned short*, 4) - 12;
            Level41_87F9CField(privateThenActorCursor17, short*, 4) = rawWord2;
            __asm__ volatile("" ::"m"(Level41_87F9CField(privateThenActorCursor17, short*, 4))
                             : "memory");
            rawWord2 = Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 564);
            if (rawWord2 < -560)
                Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 564) = -560;
            Level41_87F9CBuildOrientedInputPairView1(&originalFrame.sp80, 1);
            argumentWord4 = originalFrame.sp80;
            if (argumentWord4) {
                completeOriginalDivisionScalar = 0x82082083;
                MATCHING_OBSERVE_VOLATILE(completeOriginalDivisionScalar);
                argumentWord4 *= 8;
                rawWord3 = argumentWord4 / 126;
                temporaryWord21 = Level41_87F9CData70328View12 + rawWord3;
            } else
                temporaryWord21 = Level41_87F9CData70328View13;
            Level41_87F9CField((int)&Level41_87F9CData70328View1, unsigned char*, 554) =
                temporaryWord21;
            rawWord2 = Level41_87F9CField(privateThenActorCursor17, unsigned short*, 6) - 1;
            Level41_87F9CField(privateThenActorCursor17, unsigned short*, 6) = rawWord2;
            argumentWord5 = 4096;
            if ((rawWord2 << 16) <= 0) {
                retainedHeadingVectorOrHeightView16 = (int)&Level41_87F9CData70328View17;
                MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
                argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
                __asm__ volatile("" ::"r"(argumentWord4) : "$2", "memory");
                rawWord2 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) + 1500;
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
                rawWord2 = Level41_87F9CQueryWorldHeightView1(argumentWord4, argumentWord5);
                rawWord3 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) - 1500;
                Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord3;
                if (rawWord2) {
                    Level41_87F9CData6E160View1 = 0;
                    Level41_87F9CData6E164View1 = 0;
                    Level41_87F9CField(ownerRecord21, unsigned char*, 72) = 0;
                    Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 148) = -8960;
                }
                return;
            }
            retainedHeadingVectorOrHeightView16 = (int)&Level41_87F9CData70328View18;
            MATCHING_KEEP(retainedHeadingVectorOrHeightView16);
            argumentWord4 = retainedHeadingVectorOrHeightView16 - 8;
            __asm__ volatile("" ::"r"(argumentWord4) : "$2", "memory");
            rawWord2 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) + 1500;
            Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord2;
            rawWord2 = Level41_87F9CQueryWorldHeightView1(argumentWord4, argumentWord5);
            rawWord3 = Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0);
            argumentWord5 = rawWord2;
            rawWord3 -= 1500;
            Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) = rawWord3;
            if (argumentWord5 &&
                argumentWord5 < Level41_87F9CField((int)&Level41_87F9CData70328View1, int*, 8) &&
                Level41_87F9CData71920View1) {
                rawWord2 = (Level41_87F9CData71918View1 * 100) / Level41_87F9CData71920View1;
                if (rawWord2 < 0)
                    rawWord2 = -rawWord2;
                MATCHING_KEEP(rawWord2);
                if (rawWord2 < 20) {
                    rawWord2 = (Level41_87F9CData7191CView1 * 100) / Level41_87F9CData71920View1;
                    if (rawWord2 < 0)
                        rawWord2 = -rawWord2;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 < 20) {
                        Level41_87F9CField(ownerRecord21, unsigned char*, 72) = 1;
                        Level41_87F9CField(retainedHeadingVectorOrHeightView16, int*, 0) =
                            argumentWord5;
                    }
                }
            }
            return;
    }
}
#undef Level41_87F9CField
