#include "matching.h"
#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "camera.h"
#include "savepoint.h"
#include "spu.h"
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
void func_level_26_80074DC8(void* input) {
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
void func_level_26_80075A24(Moby* mobyArgument) {
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
void func_level_26_800760B0(void* input) {
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
void func_level_26_80077600(Moby* moby) {
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
void func_level_26_8007773C(Moby* moby) {
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
void func_level_26_800779FC(Moby* mobyArgument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev 0 source asm/nonmatchings/overlays/level_26/moby/func_level_26_80077F1C.s; SHA256 c3886f71f9627c1b0b4e8edf470b65cacfe06db06c4abbad4647c6af65c454e4. */
/* AI generated;
 not human reviewed. SCUS-94467 USA Rev0 original417
 * instructions: sibling4768/4767. Units/helper meanings/cadence unresolved. */
#define SharedBurst417Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int SharedBurst417Delta __asm__("D_8006C648");
extern int SharedBurst417Count0 __asm__("D_8006C578"), SharedBurst417Count1 __asm__("D_8006C574");
extern short SharedBurst417Cos[] __asm__("D_80065920"), SharedBurst417Sin[] __asm__("D_800658A0");
extern unsigned char* SharedBurst417Models[] __asm__("D_8006EE2C");
extern unsigned char* (*SharedBurst417Spawn)() __asm__("SpawnMoby");
extern int (*SharedBurst417Particle)() __asm__("SpawnParticle");
int SharedBurst417Rand() __asm__("rand");
int SharedBurst417RandBetween() __asm__("func_8003636C");
int SharedBurst417UpdateEffectConfiguration() __asm__("func_80037A60");
int SharedBurst417CopyVector() __asm__("func_8004F178");
int SharedBurst417AddVector() __asm__("func_8004F194");
int SharedBurst417SpawnMobyFromValueSelector() __asm__("func_80036A68");
int SharedBurst417PlayMobySoundEvent() __asm__("func_8003BABC");
int SharedBurst417DeleteMoby() __asm__("func_80055B18");
#define SharedBurst417High(a, b)                                                     \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
#define SharedBurst417Low(a, b)             \
    ({                                      \
        register int low __asm__("lo");     \
        low = (int)(a) * (int)(b);          \
        __asm__("" : "=l"(low) : "0"(low)); \
        low;                                \
    })
/* Original 417-word function and 0x70-byte frame. Raw table indices,
 * signed HI/LO products and register-width remainders retain the original
 * producer instructions. Empty constraints preserve their scheduling.
 * Physical units, helper meanings and frame cadence remain unresolved. */
void func_level_26_80077F1C(void* input) {
    struct {
        int first[4], second[4], third[4];
    } frame;
    register unsigned char* owner __asm__("$21") = input;
    unsigned char* tag;
    register int index17 __asm__("$17");
    register int five18 __asm__("$18");
    register unsigned char* small16 __asm__("$16");
    register int angle0 __asm__("$16");
    register int angle1 __asm__("$17");
    register unsigned char* child20 __asm__("$20");
    register unsigned char* nested22 __asm__("$22");
    register int count23 __asm__("$23");
    register short* cosine0 __asm__("$19");
    register short* cosine1 __asm__("$18");
    register short* sine22 __asm__("$22");
    register int* vector20 __asm__("$20");
    register int value __asm__("$2");
    register int other __asm__("$3");
    register void* call4 __asm__("$4");
    register int arg5 __asm__("$5");
    register void* arg6 __asm__("$6");
    register void* arg7 __asm__("$7");
    MATCHING_KEEP(owner);
    value = owner[72];
    tag = SharedBurst417Field(owner, unsigned char**, 0);
    if (!value) {
        value = ((Moby*)owner)->damageFlags;
        if (value)
            owner[72] = 2;
    }
    other = owner[72];
    value = 1;
    ((Moby*)owner)->damageFlags = 0;
    if (other == value)
        goto state1;
    if (other < 2) {
        if (!other)
            goto state0;
        goto done;
    }
    value = 2;
    call4 = owner;
    if (other == value)
        goto state2;
    goto done;
state0:
    value = tag[0];
    if (!value) {
        tag[0] = 1;
        value = ((Moby*)owner)->position.z;
        SharedBurst417Field(tag, int*, 4) = value;
    }
    other = SharedBurst417Delta;
    value = tag[1];
    value += other;
    tag[1] = value;
    value &= 255;
    value <<= 1;
    other = *(short*)((unsigned char*)SharedBurst417Sin + value);
    MATCHING_KEEP(other);
    value = other * 5;
    other = (value << 4) - value;
    value = SharedBurst417Field(tag, int*, 4);
    other >>= 10;
    value += other;
    ((Moby*)owner)->position.z = value;
    goto done;
state1:
    value = SharedBurst417UpdateEffectConfiguration(owner, tag + 2, 2, 16, -200);
    if (!value)
        goto done;
    owner[73] = 112;
    index17 = 0;
    five18 = 5;
small_loop:
    value = SharedBurst417Count0;
    other = SharedBurst417Count1;
    value -= other;
    call4 = (void*)631;
    if (value < 21)
        goto small_done;
    small16 = SharedBurst417Spawn(call4, owner);
    call4 = 0;
    if (small16) {
        value = SharedBurst417RandBetween(call4, 300);
        other = SharedBurst417Field(small16, int*, 20);
        other += value;
        value = index17 < 6;
        SharedBurst417Field(small16, int*, 20) = other;
        if (value)
            small16[73] = five18;
    }
    index17++;
    if (index17 < 16)
        goto small_loop;
small_done:
    index17 = 0;
    call4 = frame.first;
first_particles:
    SharedBurst417CopyVector(call4, owner + 12);
    index17++;
    value = SharedBurst417Rand();
    other = frame.first[0];
    value &= 255;
    other += 128;
    other -= value;
    frame.first[0] = other;
    value = SharedBurst417Rand();
    other = frame.first[1];
    value &= 255;
    other += 128;
    other -= value;
    frame.first[1] = other;
    value = SharedBurst417Rand();
    call4 = (void*)1;
    arg5 = 2;
    arg6 = frame.first;
    arg7 = 0;
    MATCHING_KEEP5(call4, arg5, arg6, arg7, value);
    value &= 511;
    other = frame.first[2];
    other += value;
    frame.first[2] = other;
    SharedBurst417Particle(call4, arg5, arg6, arg7);
    SharedBurst417Particle(4, 70, frame.first, 24);
    value = index17 < 4;
    call4 = frame.first;
    if (value)
        goto first_particles;
    SharedBurst417SpawnMobyFromValueSelector(owner, 0, 0, 0);
    SharedBurst417PlayMobySoundEvent(owner, 1, 0);
    SharedBurst417DeleteMoby(owner);
    goto done;
state2:
    SharedBurst417PlayMobySoundEvent(call4, 0, 0);
    count23 = 0;
child_loop:
    value = SharedBurst417Count0;
    other = SharedBurst417Count1;
    value -= other;
    call4 = (void*)630;
    if (value < 21)
        goto child_done;
    child20 = SharedBurst417Spawn(call4, owner);
    nested22 = SharedBurst417Field(child20, unsigned char**, 0);
    MATCHING_KEEP2(child20, nested22);
    if (!child20)
        goto child_next;
    angle0 = SharedBurst417Rand();
    angle1 = SharedBurst417Rand();
    value = SharedBurst417Rand();
    other = 0x55555556;
    MATCHING_KEEP(other);
    {
        register int quotient9 __asm__("$9");
        quotient9 = SharedBurst417High(value, other);
        call4 = (void*)(value >> 31);
        angle0 = (angle0 & 255) << 1;
        angle1 = (angle1 & 255) << 1;
        __asm__("" : "=r"(quotient9) : "0"(quotient9), "r"(angle1));
        call4 = (void*)(quotient9 - (int)call4);
    }
    value -= (int)call4 * 3;
    {
        register short* table9 __asm__("$9");
        register int product9 __asm__("$9");
        __asm__ volatile("" : : "r"(value) : "memory", "$9");
        table9 = SharedBurst417Cos;
        cosine0 = (short*)(angle0 + (int)table9);
        child20[60] = value;
        other = *cosine0;
        cosine1 = (short*)(angle1 + (int)table9);
        value = other * 25;
        other = *cosine1;
        value >>= 7;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        value = product9 >> 12;
        table9 = SharedBurst417Sin;
        angle0 += (int)table9;
        SharedBurst417Field(child20, int*, 12) = value;
        other = *(short*)angle0;
        value = other * 25;
        other = *cosine1;
        value >>= 7;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        arg6 = owner + 12;
        call4 = child20 + 12;
        value = product9 >> 12;
        table9 = SharedBurst417Sin;
        angle1 += (int)table9;
        SharedBurst417Field(child20, int*, 16) = value;
        other = *(short*)angle1;
        arg5 = (int)call4;
        value = other * 25;
        value >>= 7;
        SharedBurst417Field(child20, int*, 20) = value;
        SharedBurst417AddVector(call4, (void*)arg5, arg6);
        value = SharedBurst417Field(child20, int*, 20);
        value += 2000;
        SharedBurst417Field(child20, int*, 20) = value;
        other = *cosine0;
        value = other * 25;
        other = *cosine1;
        value >>= 10;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        value = product9 >> 12;
        SharedBurst417Field(nested22, short*, 0) = value;
        other = *(short*)angle0;
        value = other * 25;
        other = *cosine1;
        value >>= 10;
        product9 = SharedBurst417Low(value, other);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)30;
        value = product9 >> 12;
        SharedBurst417Field(nested22, short*, 2) = value;
        other = *(short*)angle1;
        arg5 = 60;
        value = other * 25;
        value >>= 10;
        SharedBurst417Field(nested22, short*, 4) = value;
        value = SharedBurst417RandBetween(call4, arg5);
        SharedBurst417Field(nested22, int*, 12) = value;
    }
child_next:
    count23++;
    if (count23 < 16)
        goto child_loop;
child_done:
    count23 = 0;
    sine22 = SharedBurst417Sin;
    vector20 = frame.second;
particle_loop:
    count23++;
    angle0 = SharedBurst417Rand();
    value = SharedBurst417Rand();
    call4 = (void*)200;
    arg5 = 1100;
    MATCHING_KEEP2(call4, arg5);
    angle1 = value;
    value = SharedBurst417RandBetween(call4, arg5);
    {
        register short* table9 __asm__("$9");
        register int product9 __asm__("$9");
        angle0 = (angle0 & 255) << 1;
        table9 = SharedBurst417Cos;
        cosine0 = (short*)(angle0 + (int)table9);
        other = *cosine0;
        MATCHING_KEEP(other);
        value &= 255;
        {
            register int heldLow __asm__("lo");
            heldLow = other * value;
            __asm__("" : "=l"(heldLow), "=r"(angle1) : "0"(heldLow), "1"(angle1));
            angle1 = (angle1 & 255) << 1;
            cosine1 = (short*)(angle1 + (int)table9);
            product9 = heldLow;
            MATCHING_KEEP_CLOBBER(product9, "memory");
        }
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        angle0 += (int)sine22;
        other = product9 >> 12;
        frame.second[0] = other;
        other = *(short*)angle0;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        angle1 += (int)sine22;
        other = product9 >> 12;
        frame.second[1] = other;
        other = *(short*)angle1;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        arg5 = (int)vector20;
        MATCHING_KEEP(arg5);
        arg6 = owner + 12;
        call4 = vector20;
        value = product9 >> 12;
        frame.second[2] = value;
        SharedBurst417AddVector(call4, (void*)arg5, arg6);
        call4 = (void*)40;
        value = frame.second[2];
        arg5 = 70;
        value += 2000;
        frame.second[2] = value;
        value = SharedBurst417RandBetween(call4, arg5);
        other = *cosine0;
        value &= 255;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        other = product9 >> 12;
        frame.third[0] = other;
        other = *(short*)angle0;
        product9 = SharedBurst417Low(other, value);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        call4 = (void*)(int)*cosine1;
        other = product9 >> 12;
        product9 = SharedBurst417Low(other, (int)call4);
        MATCHING_KEEP_CLOBBER(product9, "memory");
        other = product9 >> 12;
        frame.third[1] = other;
        other = *(short*)angle1;
        product9 = SharedBurst417Low(other, value);
        arg5 = 0;
        MATCHING_KEEP_CLOBBER(arg5, "$6");
        arg6 = vector20;
        arg7 = frame.third;
        call4 = (void*)1;
        {
            register int (*route3)() __asm__("$3") = SharedBurst417Particle;
            __asm__("" : "=r"(product9) : "0"(product9), "r"(route3));
            value = product9 >> 12;
            frame.third[2] = value;
            route3(call4, arg5, arg6, arg7);
        }
    }
    value = count23 < 20;
    other = 1;
    if (value)
        goto particle_loop;
    SharedBurst417Field(tag, short*, 2) = 0;
    value = ((Moby*)owner)->mobyClass;
    owner[72] = other;
    value = **(unsigned char**)(SharedBurst417Models[value] + 64);
    owner[60] = other;
    owner[61] = other;
    owner[62] = 0;
    owner[63] = other;
    value = (unsigned)value >= 2;
    MATCHING_KEEP(value);
    value = -value & 48;
    owner[64] = value;
done:;
}
#undef SharedBurst417Field


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
void func_level_26_800785A0(Moby* moby) {
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
void func_level_26_800788A4(void* input) {
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
void func_level_26_80079418(Moby* moby) {
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
void func_level_26_80079848(Moby* moby) {
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
void func_level_26_80079BB0(Moby* owner) {
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
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_26/moby/func_level_26_80079D3C.s SHA256 4f9be77c82e45269d7fbdb1be7b32fa16d3e628f5ffef1d05491dcc278ec9b0a. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
int Controller79D3C_Call_PlaySound() __asm__("PlaySound");
#define Controller79D3CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned char Controller79D3CRequestMobyAnimation() __asm__("func_80034F40");           /* extern */
int Controller79D3CUpdateMobyMotionDescriptor() __asm__("func_80035194");               /* extern */
unsigned char Controller79D3CTurnMobyTowardHeading() __asm__("func_8003585C");          /* extern */
int Controller79D3CCountTimerDown() __asm__("func_800359A4");                           /* extern */
unsigned char Controller79D3CResolveMobyYawStep() __asm__("func_80035DDC");             /* extern */
int Controller79D3CRandBetween() __asm__("func_8003636C");                              /* extern */
unsigned char Controller79D3CEmitMobyVertexParticles() __asm__("func_800369B8");        /* extern */
int Controller79D3CCountListedMobysBelowState80() __asm__("func_800369D8");             /* extern */
unsigned char Controller79D3CInitializeMobyMotionState() __asm__("func_80038BF8");      /* extern */
int Controller79D3CPlanarHeadingLookup() __asm__("func_8004E880");                      /* extern */
unsigned char Controller79D3CCopyVector() __asm__("func_8004F178");                     /* extern */
int Controller79D3CApproximatePlanarDistance() __asm__("func_8004F334");                /* extern */
unsigned char Controller79D3CDeleteMoby() __asm__("func_80055B18");                     /* extern */
unsigned char Controller79D3CRefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller79D3CReadSelectedFrameScalar() __asm__("func_80055E84");                  /* extern */
extern unsigned char Controller79D3C_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller79D3C_D_80065920 __asm__("D_80065920");
extern unsigned char Controller79D3C_D_80066BC8 __asm__("D_80066BC8");
extern int Controller79D3C_D_8006C550 __asm__("D_8006C550");
extern int Controller79D3C_D_8006C640 __asm__("D_8006C640");
extern void* Controller79D3C_D_8006C654 __asm__("D_8006C654");
extern int Controller79D3C_D_8006C770 __asm__("D_8006C770");
extern int Controller79D3C_D_80070328 __asm__("D_80070328");
extern short Controller79D3C_D_800719DC __asm__("D_800719DC");
extern void* (*Controller79D3C_SpawnMoby)() __asm__("SpawnMoby");
extern unsigned char (*Controller79D3C_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char (*Controller79D3C_unk_ovlheader_80074314)() __asm__("unk_ovlheader_80074314");

void func_level_26_80079D3C(void* inputOwner) {
    register void* owner __asm__("$17") = inputOwner;
    /* Original frame0x90: vectors at SP+0x38,+0x48,+0x58,+0x68;
     * thirteen-argument indirect call uses stack+0x10..0x30. Saves from0x78.
     * Raw pointer offsets are bytes; the two tables use signed halfwords.
     * Empty constraints preserve original producers and emit no instruction.
     * Helper meanings, fixed-point units and caller cadence remain unresolved. */
    struct {
        int sp38, sp3C, sp40, pad44, sp48, sp4C, sp50, pad54, sp58, sp5C, sp60, pad64, sp68, sp6C,
            sp70, pad74;
    } originalFrame;

    short nextCounterHalfword;
    register void* privateData __asm__("$18");
    register void* ownerPosition __asm__("$19");
    register int initialDistanceWord __asm__("$16");
    int animationReturnWord;
    int temp_v0;
    int temp_v0_3;
    int temp_v0_5;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_6;
    register int distanceOffsetWord __asm__("$16");
    int var_v0;
    register int comparisonWord2 __asm__("$2");
    register int distanceWord3 __asm__("$3");
    register int tableWord4 __asm__("$4");
    register int positionWord3 __asm__("$3");
    register int randomWord2 __asm__("$2");
    unsigned char temp_a0;
    unsigned char temp_v1;
    void* spawnedChild;
    void* spawnedRecord;
    void* temp_v1_5;
    register void* counterAddress4 __asm__("$4");
    void* distancePosition;

    privateData = Controller79D3CField(owner, int**, 0);
    initialDistanceWord =
        Controller79D3CApproximatePlanarDistance(owner + 0xC, &Controller79D3C_D_80070328);
    temp_v1 = ((Moby*)owner)->state;
    if (temp_v1 != 1 && temp_v1 != 0x15 && ((Moby*)owner)->damageFlags != 0) {
        Controller79D3CInitializeMobyMotionState(owner, privateData + 0x18, 0, 1);
        Controller79D3CField(privateData, unsigned short*, 0x1E) += 0xB4;
    }
    switch (((Moby*)owner)->state) {
        case 21:
            distanceWord3 = initialDistanceWord - 0x3E9;
            __asm__("" : "=r"(distanceWord3) : "0"(distanceWord3), "r"(initialDistanceWord));
            if ((unsigned int)distanceWord3 <= 0x9C16U) {
                temp_v1_2 = ((Moby*)owner)->position.z - ((Moby*)owner)->distanceToGround;
                temp_v0 = temp_v1_2 - Controller79D3CField(&Controller79D3C_D_80070328, int*, 8);
                if (temp_v0 >= 0) {
                    if (temp_v0 < 0xBB9) {
                        return;
                    }
                    goto checkPrivateIndex;
                }
                if ((Controller79D3CField(&Controller79D3C_D_80070328, int*, 8) - temp_v1_2) >=
                    0xBB9) {
                checkPrivateIndex:
                    temp_v1_3 = Controller79D3CField(privateData, int*, 0x30);
                    if ((temp_v1_3 == -1) || ((unsigned char)Controller79D3CField(
                                                  ((temp_v1_3 * 0x58) + Controller79D3C_D_8006C550),
                                                  unsigned char*, 0x48) >= 0x80U)) {
                        ((Moby*)owner)->state = 0x16U;
                        nextCounterHalfword = 0x3C;
                        goto storePrivateCounter;
                    }
                }
            }
            break;
        case 22:
            counterAddress4 = privateData + 0xC;
            if (Controller79D3CField(privateData, short*, 0xC) < 0x15) {
                goto updatePrivateCounter;
            }
            {
                MATCHING_OBSERVE_VOLATILE(counterAddress4);
                originalFrame.sp38 = Controller79D3CRandBetween(0, 0x14) - 0xA;
                originalFrame.sp3C = Controller79D3CRandBetween(0, 0x14) - 0xA;
                originalFrame.sp40 = Controller79D3CRandBetween(0, 0xA);
                Controller79D3CCopyVector(&originalFrame.sp48, owner + 0xC);
                randomWord2 = Controller79D3CRandBetween(0, 0x50);
                positionWord3 = originalFrame.sp48 - 0x28;
                __asm__("" : "=r"(positionWord3) : "0"(positionWord3), "r"(randomWord2));
                positionWord3 += randomWord2;
                MATCHING_KEEP(positionWord3);
                originalFrame.sp48 = positionWord3;
                randomWord2 = Controller79D3CRandBetween(0, 0x50);
                positionWord3 = originalFrame.sp4C - 0x28;
                __asm__("" : "=r"(positionWord3) : "0"(positionWord3), "r"(randomWord2));
                positionWord3 += randomWord2;
                MATCHING_KEEP(positionWord3);
                originalFrame.sp4C = positionWord3;
                originalFrame.sp50 = Controller79D3CField(privateData, int*, 8);
                Controller79D3C_SpawnParticle(1, 0x3F, &originalFrame.sp48, &originalFrame.sp38);
                MATCHING_KEEP(privateData);
                counterAddress4 = privateData + 0xC;
            }
        updatePrivateCounter:
            if (Controller79D3CCountTimerDown(counterAddress4, 2) != 0) {
                ((Moby*)owner)->state = 3U;
                Controller79D3CRequestMobyAnimation(owner, 3);
                Controller79D3CField(owner, signed char*, 0x41) = 1;
                Controller79D3CField(owner, signed char*, 0x4C) = 0x20;
                Controller79D3CField(owner, signed char*, 0x4D) = 1;
                Controller79D3CField(owner, signed char*, 0x46) =
                    Controller79D3CPlanarHeadingLookup(
                        Controller79D3CField(&Controller79D3C_D_80070328, int*, 0) -
                            ((Moby*)owner)->position.x,
                        Controller79D3CField(&Controller79D3C_D_80070328, int*, 4) -
                            ((Moby*)owner)->position.y,
                        0);
                Controller79D3CRefreshMobySpatialGridAndBasis(owner, 7);
                Controller79D3CField(owner, int*, 0x54) =
                    (int)(Controller79D3CField(privateData, int*, 8) - 0x80000000);
                return;
            }
            break;
        case 0:
            distanceOffsetWord = 0;
            if (Controller79D3C_D_8006C640 == 0) {
                Controller79D3CField(owner, signed char*, 0x41) = 0;
                Controller79D3CField(owner, signed char*, 0x4C) = 0;
                Controller79D3CField(owner, signed char*, 0x4D) = 0;
                Controller79D3CField(owner, int*, 8) = 0;
                ((Moby*)owner)->state = 0x15U;
                ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z - 0x190);
                if (Controller79D3CField(privateData, void**, 0x10) == 0) {
                    spawnedChild = Controller79D3C_SpawnMoby(0x164, owner);
                    if (spawnedChild != 0) {
                        Controller79D3CField(privateData, void**, 0x10) = spawnedChild;
                        return;
                    }
                }
            } else {
                if (Controller79D3CField(privateData, short*, 0xC) != 0) {
                    temp_v1_4 = ((Moby*)owner)->position.z - ((Moby*)owner)->distanceToGround;
                    temp_v0_3 =
                        temp_v1_4 - Controller79D3CField(&Controller79D3C_D_80070328, int*, 8);
                    if (temp_v0_3 >= 0) {
                        if (temp_v0_3 >= 0x5DC) {
                            distanceOffsetWord = 0x2710;
                            goto farDistanceCalls;
                        }
                        goto nearDistanceCalls;
                    }
                    if ((Controller79D3CField(&Controller79D3C_D_80070328, int*, 8) - temp_v1_4) <
                        0x5DC) {
                        goto nearDistanceCalls;
                    }
                    goto farDistanceStart;
                }
            nearDistanceCalls:
                Controller79D3CTurnMobyTowardHeading(
                    owner,
                    Controller79D3CPlanarHeadingLookup(
                        Controller79D3CField(privateData, int*, 0) - ((Moby*)owner)->position.x,
                        Controller79D3CField(privateData, int*, 4) - ((Moby*)owner)->position.y, 0),
                    0xE, 2, 1, 0);
                Controller79D3CResolveMobyYawStep(owner, 0x64, 0, 0, 4);
                distancePosition = owner + 0xC;
                goto joinDistance;
            farDistanceStart:
                distanceOffsetWord = 0x2710;
            farDistanceCalls:
                randomWord2 =
                    Controller79D3CPlanarHeadingLookup(
                        ((Moby*)owner)->position.x - Controller79D3CField(privateData, int*, 0),
                        ((Moby*)owner)->position.y - Controller79D3CField(privateData, int*, 4),
                        0) +
                    8;
                MATCHING_KEEP_CLOBBER(randomWord2, "memory");
                Controller79D3C_unk_ovlheader_80074314(owner, privateData, 0x258,
                                                       randomWord2 & 0xFF, 4, 0x4B, 5, 0x80, 0xFF,
                                                       0xFF, 0, 0, 0);
                distancePosition = owner + 0xC;
            joinDistance:
                distanceOffsetWord +=
                    Controller79D3CApproximatePlanarDistance(distancePosition, privateData);
                MATCHING_KEEP(distanceOffsetWord);
                comparisonWord2 = distanceOffsetWord < 0x46;
                __asm__("" : "=r"(comparisonWord2) : "0"(comparisonWord2), "r"(distanceOffsetWord));
                if (comparisonWord2) {
                    Controller79D3CRequestMobyAnimation(owner, 4);
                    ((Moby*)owner)->state = 0x19U;
                    return;
                }
            }
            break;
        case 25:
            ownerPosition = owner + 0xC;
            animationReturnWord = Controller79D3CReadSelectedFrameScalar(owner);
            Controller79D3CCopyVector(ownerPosition, privateData);
            if ((((Moby*)owner)->animationState.id == 4) &&
                ((animationReturnWord >= 0xB) || (animationReturnWord < 0xF))) {
                ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z - 0x19);
                originalFrame.sp68 = Controller79D3CRandBetween(0, 0x14) - 0xA;
                originalFrame.sp6C = Controller79D3CRandBetween(0, 0x14) - 0xA;
                originalFrame.sp70 = Controller79D3CRandBetween(0, 0xA);
                Controller79D3CCopyVector(&originalFrame.sp58, ownerPosition);
                randomWord2 = Controller79D3CRandBetween(0, 0x50);
                positionWord3 = originalFrame.sp58 - 0x28;
                __asm__("" : "=r"(positionWord3) : "0"(positionWord3), "r"(randomWord2));
                positionWord3 += randomWord2;
                MATCHING_KEEP(positionWord3);
                originalFrame.sp58 = positionWord3;
                randomWord2 = Controller79D3CRandBetween(0, 0x50);
                positionWord3 = originalFrame.sp5C - 0x28;
                __asm__("" : "=r"(positionWord3) : "0"(positionWord3), "r"(randomWord2));
                positionWord3 += randomWord2;
                MATCHING_KEEP(positionWord3);
                originalFrame.sp5C = positionWord3;
                originalFrame.sp60 = Controller79D3CField(privateData, int*, 8);
                Controller79D3C_SpawnParticle(1, 0x3F, &originalFrame.sp58, &originalFrame.sp68);
            }
            Controller79D3CField(owner, int*, 0x54) =
                (int)(Controller79D3CField(privateData, int*, 8) - 0x80000000);
            if (Controller79D3C_D_8006C770 != 0) {
                Controller79D3CCopyVector(owner + 0xC, privateData);
                Controller79D3CField(owner, signed char*, 0x41) = 0;
                Controller79D3CField(owner, signed char*, 0x4C) = 0;
                Controller79D3CField(owner, signed char*, 0x4D) = 0;
                Controller79D3CField(owner, int*, 8) = 0;
                positionWord3 = Controller79D3CField(privateData, int*, 8);
                MATCHING_KEEP_CLOBBER(positionWord3, "memory");
                ((Moby*)owner)->state = 0x15U;
                Controller79D3CField(owner, signed char*, 0x49) = 0;
                MATCHING_KEEP_CLOBBER(positionWord3, "memory");
                ((Moby*)owner)->position.z = positionWord3 - 0x190;
                return;
            }
            break;
        case 1:
            if (Controller79D3CUpdateMobyMotionDescriptor(owner, privateData + 0x18) == 0x100) {
                Controller79D3CRefreshMobySpatialGridAndBasis(owner, 4);
                Controller79D3CEmitMobyVertexParticles(owner, 0x18);
                Controller79D3CCopyVector(owner + 0xC, privateData);
                temp_v1_5 = Controller79D3CField(privateData, void**, 0x10);
                if (temp_v1_5 != 0) {
                    Controller79D3CField(temp_v1_5, signed char*, 0x49) = 1;
                    Controller79D3CField(privateData, void**, 0x10) = 0;
                }
                temp_a0 = ((Moby*)owner)->animationRun;
                if ((temp_a0 != 0xFF) &&
                    (Controller79D3CCountListedMobysBelowState80(temp_a0) == 1)) {
                    Controller79D3CField(&Controller79D3C_D_80066BC8, signed char*, 8) = 3;
                    Controller79D3C_D_800719DC = 1;
                    Controller79D3C_Call_PlaySound(
                        Controller79D3CField(Controller79D3C_D_8006C654, unsigned char*, 0x23),
                        owner, 0xA1);
                    spawnedRecord = Controller79D3C_SpawnMoby(0xD3, owner);
                    if (spawnedRecord != 0) {
                        Controller79D3CCopyVector(spawnedRecord + 0xC, &Controller79D3C_D_80070328);
                        positionWord3 = Controller79D3CField(
                            &Controller79D3C_D_80065920, short*,
                            Controller79D3CField(&Controller79D3C_D_80070328, unsigned char*, 0xE) *
                                2);
                        randomWord2 = positionWord3 * 0x19;
                        __asm__("" : "=r"(randomWord2) : "0"(randomWord2), "r"(positionWord3));
                        positionWord3 = Controller79D3CField(spawnedRecord, int*, 0xC);
                        positionWord3 += randomWord2 >> 7;
                        Controller79D3CField(spawnedRecord, int*, 0xC) = positionWord3;
                        MATCHING_BARRIER_VOLATILE("memory");
                        tableWord4 = Controller79D3CField(
                            &Controller79D3C_D_800658A0, short*,
                            Controller79D3CField(&Controller79D3C_D_80070328, unsigned char*, 0xE) *
                                2);
                        MATCHING_KEEP(tableWord4);
                        positionWord3 = Controller79D3CField(spawnedRecord, int*, 0x14) + 0x1F4;
                        Controller79D3CField(spawnedRecord, int*, 0x14) = positionWord3;
                        positionWord3 = Controller79D3CField(spawnedRecord, int*, 0x10);
                        __asm__(""
                                : "=r"(positionWord3)
                                : "0"(positionWord3), "r"(tableWord4)
                                : "memory");
                        randomWord2 = (tableWord4 * 0x19) >> 7;
                        positionWord3 += randomWord2;
                        Controller79D3CField(spawnedRecord, int*, 0x10) = positionWord3;
                    }
                }
                Controller79D3CDeleteMoby(owner);
                return;
            }
            break;
        case 3:
            if ((unsigned int)(Controller79D3CReadSelectedFrameScalar(owner) - 6) < 2U) {
                temp_v0_5 = ((Moby*)owner)->position.z + 0xC8;
                ((Moby*)owner)->position.z = temp_v0_5;
                temp_v1_6 = Controller79D3CField(privateData, int*, 8);
                if (temp_v1_6 < temp_v0_5) {
                    ((Moby*)owner)->position.z = temp_v1_6;
                }
            }
            if (Controller79D3C_D_8006C770 != 0) {
                Controller79D3CRefreshMobySpatialGridAndBasis(owner, 7);
                ((Moby*)owner)->state = 0U;
                Controller79D3CRequestMobyAnimation(owner, 0);
                nextCounterHalfword = 0xB4;
                Controller79D3CField(owner, int*, 0x54) = 0;
            storePrivateCounter:
                Controller79D3CField(privateData, short*, 0xC) = nextCounterHalfword;
            }
            break;
    }
}
#undef Controller79D3CField


typedef struct {
    unsigned char reserved00[0x18];
    int threshold;
} DecodedSpawnThreshold;
extern int D_8006C578, D_8006C574, D_8006C770, D_8006C640;
int rand(void);
void func_80055B18(Moby*);
int func_80055E84(Moby*);
void func_level_26_8007A4CC(Moby* actor) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define P7D820Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int P7D820CopyCameraPositionWithWrappedAngle() __asm__("func_800135A4");
int P7D820QueryWorldHeight() __asm__("func_8001A358");
int P7D820RequestMobyAnimation() __asm__("func_80034F40");
int P7D820TurnMobyTowardHeading() __asm__("func_8003585C");
int P7D820CountTimerDown() __asm__("func_800359A4");
int P7D820ResolveMobyYawStep() __asm__("func_80035DDC");
int P7D820UpdateMobyInteractionGate() __asm__("func_80037BBC");
int P7D820RestoreOrClearTrackedSnapshot() __asm__("func_8003B74C");
int P7D820RegisterTrackedValue() __asm__("func_8003B7B4");
int P7D820ConfigurePrimaryRangeRequest() __asm__("func_8004F984");
int P7D820StartDialogue() __asm__("func_800512E4");
int P7D820RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int P7D820RefreshMobyPackedQueryField() __asm__("func_8005629C");
extern unsigned char P7D820D_800652B0[] __asm__("D_800652B0");
extern unsigned char P7D820D_800652B4[] __asm__("D_800652B4");
extern unsigned char P7D820D_800652B6[] __asm__("D_800652B6");
extern unsigned char P7D820D_800658A0[] __asm__("D_800658A0");
extern unsigned char P7D820D_80065920[] __asm__("D_80065920");
extern unsigned char P7D820D_80068CAC[] __asm__("D_80068CAC");
extern unsigned char P7D820D_80068F7C[] __asm__("D_80068F7C");
extern unsigned char P7D820D_80068F90[] __asm__("D_80068F90");
extern unsigned char P7D820D_80068FA4[] __asm__("D_80068FA4");
extern int P7D820D_8006C3F4 __asm__("D_8006C3F4");
extern int P7D820D_8006C4F8 __asm__("D_8006C4F8");
extern int P7D820D_8006C598 __asm__("D_8006C598");
extern int P7D820D_8006C640 __asm__("D_8006C640");
extern int P7D820D_8006C658 __asm__("D_8006C658");
extern int P7D820D_8006C6D0 __asm__("D_8006C6D0");
extern int P7D820D_8006C6E0 __asm__("D_8006C6E0");
extern int P7D820D_8006C768 __asm__("D_8006C768");
extern unsigned char P7D820D_8006C7F8[] __asm__("D_8006C7F8");
extern unsigned char P7D820D_8006D088[] __asm__("D_8006D088");
extern int P7D820D_8006E044 __asm__("D_8006E044");
extern int P7D820D_8006E048 __asm__("D_8006E048");
extern int P7D820D_8006E078 __asm__("D_8006E078");
extern int P7D820D_8006E08C __asm__("D_8006E08C");
extern signed char P7D820D_8006E13F __asm__("D_8006E13F");
extern int P7D820D_8006E344 __asm__("D_8006E344");
extern int P7D820D_8006E53C __asm__("D_8006E53C");
extern unsigned char P7D820D_80070328[] __asm__("D_80070328");
extern signed char P7D820D_80071576 __asm__("D_80071576");
extern unsigned char P7D820D_800719A8[] __asm__("D_800719A8");
extern int P7D820D_800719BC __asm__("D_800719BC");
extern int P7D820D_800719C0 __asm__("D_800719C0");
extern int P7D820D_800719C4 __asm__("D_800719C4");
extern short P7D820D_800719D4 __asm__("D_800719D4");
extern unsigned char P7D820D_800719F0[] __asm__("D_800719F0");
extern int (*P7D820SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7D820unk_ovlheader_80074318)() __asm__("unk_ovlheader_80074318");
extern int (*P7D820unk_ovlheader_80074320)() __asm__("unk_ovlheader_80074320");
extern unsigned char P7D820D_8006C7B4 __asm__("D_8006C7B4");
extern int P7D820D_8006C58C __asm__("D_8006C58C");
extern unsigned char P7D820D_80070300[] __asm__("D_80070300");
extern unsigned char* P7D820D_8006C550 __asm__("D_8006C550");
int P7D820PreparePortalLevelTransition() __asm__("func_80053F50");
int P7D820WriteTrackedSnapshot() __asm__("func_8003B634");
void func_level_26_8007A688(void* owner) {
    register unsigned char* sourceArg5 __asm__("5");
    register void* copyDestination4 __asm__("4");
    register int tableWord3 __asm__("3");
    int headerBaseWord;
    int requestedSelector;
    int headerArg5;
    register int workWord2 __asm__("2");
    register int workWord3 __asm__("3");
    int selector48;
    void* selectorAddress1;
    void* selectorAddress99;
    void* state;
    register void* positionArg4 __asm__("4");
    int scaledHeaderWord;
    void* stateArg4;

    ((Moby*)owner)->updateDistance = 0xFF;
    state = ((Moby*)owner)->mobyTag;
    if ((P7D820D_8006C640 > 0) && (P7D820Field(state, int*, 0x60) == 0)) {
        headerBaseWord = P7D820D_8006C3F4 + P7D820Field(&P7D820D_800652B0, int*, 0x10);
        P7D820ConfigurePrimaryRangeRequest(
            headerBaseWord, headerBaseWord + P7D820Field(&P7D820D_800652B4, unsigned short*, 0x10),
            P7D820Field(&P7D820D_800652B6, unsigned short*, 0x10));
        P7D820Field(state, int*, 0x60) = 1;
    }
    selector48 = ((Moby*)owner)->state;
    if (selector48 == 3)
        goto selector3;
    if (selector48 < 4) {
        if (selector48 == 0)
            goto selector0;
        if (selector48 == 1)
            goto selector1;
        goto finishPositionArgument;
    }
    if (selector48 == 10)
        goto selector10;
    if (selector48 == 99)
        goto selector99;
    goto finishPositionArgument;
selector0:
    if ((P7D820Field(state, unsigned char*, 2) == 1) && !(P7D820D_8006C7B4 & 1) &&
        !(P7D820D_80070300[P7D820D_8006C58C] & 1)) {
        P7D820Field(state, unsigned char*, 2) = 4;
    }
initializeState0:
    ((Moby*)owner)->distanceToGround = 0;
    P7D820Field(state, signed char*, 5) = 1;
    positionArg4 = owner + 0xC;
    if (P7D820D_8006C598 == 0) {
        if (P7D820UpdateMobyInteractionGate(owner, 0) != 0) {
            P7D820StartDialogue(owner, 0, 0xA);
            ((Moby*)owner)->state = 0xAU;
        }
        goto finishPosition;
    }
    goto finishPositionArgument;
selector10:
    if (P7D820D_8006E344 == 1)
        goto finishPositionArgument;
    P7D820Field(&P7D820D_80070328, int*, 0x20C) = 0x10000002;
    if (P7D820Field(state, unsigned char*, 4) == 2) {
        P7D820PreparePortalLevelTransition(-1);
        goto finishPositionArgument;
    }
    P7D820WriteTrackedSnapshot(
        P7D820D_8006D088, P7D820D_8006C550 + P7D820Field(state, int*, 0x58) * 88 + 12,
        P7D820Field(P7D820D_8006C550 + P7D820Field(state, int*, 0x58) * 88, unsigned char*, 0x46));
    P7D820Field(state, int*, 0x24) = 0x3C;
    ((Moby*)owner)->state = 1U;
    P7D820RequestMobyAnimation(owner, 1);
    positionArg4 = owner + 0xC;

    goto finishPositionArgument;
selector1:
    P7D820D_800719D4 = 1;
    P7D820Field(&P7D820D_80070328, int*, 0x20C) = 0x10000002;
    if (P7D820TurnMobyTowardHeading(owner, P7D820Field(state, int*, 0x48) + 0x80, 8, 0x10,
                                    (int)selector48, 0) != 0) {
        P7D820ResolveMobyYawStep(owner, 0x80, 0, 0, 0);
    }
    positionArg4 = owner + 0xC;
    if (P7D820CountTimerDown(state + 0x24, 4) == 2) {
        selectorAddress1 = owner + 0x48;
        ((Moby*)owner)->state = 3U;
        P7D820RegisterTrackedValue(selectorAddress1, 1, &P7D820D_8006D088);
        P7D820RegisterTrackedValue(selectorAddress1, 1, &P7D820D_8006C7F8);
        P7D820RestoreOrClearTrackedSnapshot(&P7D820D_8006D088);
        ((Moby*)owner)->state = 1U;
        goto finishPosition;
    }
    goto finishPositionArgument;
selector3:
    P7D820unk_ovlheader_80074318(owner, 0x64);
    P7D820D_8006C6D0 = 0;
    if (P7D820Field(&P7D820D_80070328, int*, 0x50) == selector48) {
        copyDestination4 = &P7D820D_800719A8;
        sourceArg5 = &P7D820D_80068FA4;
        MATCHING_KEEP2(copyDestination4, sourceArg5);
    } else {
        copyDestination4 = &P7D820D_800719A8;
        sourceArg5 = &P7D820D_80068F7C;
        MATCHING_KEEP2(copyDestination4, sourceArg5);
    }
    P7D820CopyCameraPositionWithWrappedAngle(copyDestination4, sourceArg5, 0);
    P7D820CopyCameraPositionWithWrappedAngle(&P7D820D_800719F0, &P7D820D_80068F90, 0);
    if (P7D820Field(&P7D820D_80070328, int*, 0xB8) == 0) {
        P7D820Field(state, int*, 0x2C) = 0;
    }
    if ((P7D820D_8006E044 == 7) && ((unsigned int)(P7D820D_8006E048 - 3) < 2U)) {
        P7D820D_8006C768 = 1;
        P7D820Field(&P7D820D_80070328, int*, 0x288) = 1;
        P7D820D_8006E13F = 1;
    } else {
        P7D820D_8006C768 = 0;
    }
    if (P7D820Field(&P7D820D_80070328, int*, 0x24C) == 3) {
        requestedSelector = P7D820Field(&P7D820D_80070328, int*, 0x48) - 0x64;
        if (requestedSelector != ((Moby*)owner)->animationState.nextId) {
            P7D820RequestMobyAnimation(owner, requestedSelector);
            P7D820Field(state, int*, 0x3C) = 0;
            goto selector3Counter;
        }
        goto updateSelector3;
    }
updateSelector3:
    stateArg4 = state + 0x24;
    if (((Moby*)owner)->animationState.nextId == 1) {
        if (P7D820Field(&P7D820D_80070328, int*, 0xB4) != 0) {
            scaledHeaderWord = (int)((unsigned int)P7D820Field(&P7D820D_80070328, int*, 0xB4) << 4);
            headerArg5 = scaledHeaderWord / 3840;
        } else {
            headerArg5 = 8;
        }
        P7D820unk_ovlheader_80074320(owner, headerArg5, state + 0x3C);
    selector3Counter:
        stateArg4 = state + 0x24;
    }
    if ((P7D820CountTimerDown(stateArg4, 4) != 0) && (P7D820D_8006E53C & 0x20) &&
        (P7D820D_8006E044 != 0x26) && (P7D820Field(&P7D820D_80070328, int*, 0x240) == 0)) {
        P7D820RefreshMobySpatialGridAndBasis(owner, 4);
        if (P7D820SpawnMoby(0x5A, owner) != 0) {
            P7D820Field(state, int*, 0x24) = 0x28;
            P7D820Field(state, int*, 0x28) = (int)(1 - P7D820Field(state, int*, 0x28));
        }
    }
    if ((((int*)P7D820D_80068CAC)[P7D820Field(&P7D820D_80070328, int*, 0x48)] == 0x1E) &&
        (P7D820D_8006E53C & 0x10)) {
        P7D820Field(state, int*, 0x2C) = (int)(1 - P7D820Field(state, int*, 0x2C));
    }
    positionArg4 = owner + 0xC;
    if (P7D820D_8006E044 == 0x26) {
        workWord2 = P7D820D_8006E08C;
        workWord3 = P7D820D_8006E078;
        workWord2 -= workWord3;
        workWord3 = workWord2 & 0xFFF;
        if (workWord3 >= 0x801) {
            workWord3 -= 0x1000;
        }
        workWord2 = workWord3;
        if (workWord3 < 0) {
            workWord2 = -workWord2;
        }
        if (workWord2 < 0x80) {
            P7D820Field(owner, signed char*, 0x4C) = 0;
            P7D820Field(owner, signed char*, 0x4D) = 0;
            P7D820D_8006C768 = 1;
            positionArg4 = owner + 0xC;
        } else {
            P7D820Field(owner, signed char*, 0x4C) = 0x10;
            P7D820D_8006C768 = 0;
            positionArg4 = owner + 0xC;
        }
    }
    goto finishPositionArgument;
selector99:
    if (P7D820D_8006E044 != 11)
        goto finishPositionArgument;
    ((Moby*)owner)->state = 0;
notifySelector:
    selectorAddress99 = owner + 0x48;
    P7D820RegisterTrackedValue(selectorAddress99, 1, &P7D820D_8006D088);
    P7D820RegisterTrackedValue(selectorAddress99, 1, &P7D820D_8006C7F8);
finishPosition:
finishPositionArgument:
    positionArg4 = owner + 0xC;
    ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z + 0x100);
    P7D820QueryWorldHeight(positionArg4, 0x1000);
    ((Moby*)owner)->position.z = (int)(((Moby*)owner)->position.z - 0x100);
    P7D820RefreshMobyPackedQueryField(owner);
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original functions: level13 8007DEA8, level22 80083A40,
 * level26 8007ACC0 and level34 8007DA38; 564 instructions each.
 * Offset names describe storage. Helper meanings, physical units and caller
 * cadence remain unresolved. Preserve signed halfword widths, wrapped
 * differences, ordered clamps, 32-bit shift wrapping and signed /180.
 * Empty compiler constraints emit no CPU instructions. Verified acceptance
 * requires every original linked word and full EXE/all-overlay hashes.
 */
#define P7DEA8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int P7DEA8TestSubdividedSegmentPath() __asm__("func_80013E38");
int P7DEA8QueryWorldSegmentWithOptions() __asm__("func_8001830C");
int P7DEA8QueryWorldSegment() __asm__("func_80018368");
void* P7DEA8QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int P7DEA8CountTimerDown() __asm__("func_800359A4");
int P7DEA8PlayMobySoundEvent() __asm__("func_8003BABC");
int P7DEA8TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int P7DEA8SoundHandleMatchesOwnerInStates1Or2() __asm__("func_8003BFC0");
int P7DEA8SetSoundHandleScaledDescriptorAverage() __asm__("func_8003C0B0");
int P7DEA8GetSurfaceTypeFromFlags() __asm__("func_80040954");
int P7DEA8PlanarHeadingLookup() __asm__("func_8004E880");
int P7DEA8TransformVectorByBasis() __asm__("func_8004ED6C");
int P7DEA8MeasureVectorLength() __asm__("func_8004EDE8");
int P7DEA8ShiftVectorLeft() __asm__("func_8004F0E8");
int P7DEA8ShiftVectorRightTowardZero() __asm__("func_8004F110");
int P7DEA8CopyVector() __asm__("func_8004F178");
int P7DEA8AddVector() __asm__("func_8004F194");
int P7DEA8SubtractVector() __asm__("func_8004F1C8");
int P7DEA8ApproximatePlanarDistance() __asm__("func_8004F334");
int P7DEA8DeleteMoby() __asm__("func_80055B18");
int P7DEA8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
extern unsigned char P7DEA8D_800658A0[] __asm__("D_800658A0");
extern unsigned char P7DEA8D_80065920[] __asm__("D_80065920");
extern int P7DEA8D_8006C574 __asm__("D_8006C574");
extern int P7DEA8D_8006C578 __asm__("D_8006C578");
extern unsigned char P7DEA8D_8006D048[] __asm__("D_8006D048");
extern void* P7DEA8D_8006E788 __asm__("D_8006E788");
extern int P7DEA8D_80071924 __asm__("D_80071924");
extern void* (*P7DEA8SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7DEA8SpawnParticle)() __asm__("SpawnParticle");
void func_level_26_8007ACC0(void* arg0) {
    register void* owner __asm__("$20");
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
    register int* savedVector28 __asm__("$17");
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
        int sp88;
        int sp8C;
        int sp90;
        int sp94;
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
    register void** objectListCursor __asm__("$22");
    void* temp_a0_2;
    void* linkedObject00;
    register void* privateState __asm__("$21");
    register void* ownerVector0C __asm__("$23");
    register void* queriedObject __asm__("$17");
    register void* temp_v0_2 __asm__("$16");
    register void* temp_v0_3 __asm__("$16");
    void* temp_v1_6;
    register void* scannedObject __asm__("$19");

    owner = arg0;
    ownerState48 = P7DEA8Field(owner, unsigned char*, 0x48);
    privateState = P7DEA8Field(owner, void**, 0);
    switch (ownerState48) {
        case 0:
            bestScore = 0x1869F;
            P7DEA8Field(privateState, void**, 0) = 0;
            objectListCursor = &P7DEA8D_8006E788;
            MATCHING_KEEP(objectListCursor);
            scannedObject = *objectListCursor;
            objectListCursor += 1;
            if (scannedObject != 0) {
                ownerVector0C = owner + 0xC;
                do {
                    if (!(P7DEA8Field(scannedObject, unsigned char*, 0x48) & 0x80) &&
                        (P7DEA8Field(scannedObject, int*, 8) != 0)) {
                        P7DEA8CopyVector(&frame.sp18, scannedObject + 0xC);
                        frame.sp20 += 0x80;
                        wrappedDifference46 = (P7DEA8PlanarHeadingLookup(
                                                   frame.sp18 - P7DEA8Field(owner, int*, 0xC),
                                                   frame.sp1C - P7DEA8Field(owner, int*, 0x10), 0) -
                                               P7DEA8Field(owner, unsigned char*, 0x46)) &
                                              0xFF;
                        if (wrappedDifference46 >= 0x81) {
                            wrappedDifference46 -= 0x100;
                        }
                        wrappedDifference45 =
                            (P7DEA8PlanarHeadingLookup(
                                 P7DEA8ApproximatePlanarDistance(ownerVector0C, &frame.sp18),
                                 frame.sp20 - P7DEA8Field(owner, int*, 0x14), 0) -
                             P7DEA8Field(owner, unsigned char*, 0x45)) &
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
                        if ((wrappedDifference46 < 0xC) && (wrappedDifference45 < 0xC)) {
                            distanceScore = 0x2800 - P7DEA8ApproximatePlanarDistance(ownerVector0C,
                                                                                     &frame.sp18);
                            absoluteDistanceScore = distanceScore;
                            if (distanceScore < 0) {
                                absoluteDistanceScore = -absoluteDistanceScore;
                            }
                            result2 = (wrappedDifference46 + wrappedDifference45) << 10;
                            MATCHING_KEEP(result2);
                            combinedScore = absoluteDistanceScore + result2;
                            if ((combinedScore < bestScore) &&
                                (P7DEA8TestSubdividedSegmentPath(ownerVector0C, &frame.sp18, 4) !=
                                 0)) {
                                P7DEA8Field(privateState, void**, 0) = scannedObject;
                                bestScore = combinedScore;
                            }
                        }
                    }
                    scannedObject = *objectListCursor;
                    objectListCursor += 1;
                } while (scannedObject != 0);
            }
            if (bestScore == 0x1869F) {
                P7DEA8Field(privateState, void**, 0) = 0;
            }
            initWord2 = P7DEA8Field(owner, unsigned char*, 0x44) << 4;
            MATCHING_KEEP(initWord2);
            P7DEA8Field(privateState, short*, 4) = initWord2;
            initWord2 = P7DEA8Field(owner, unsigned char*, 0x45) << 4;
            MATCHING_KEEP(initWord2);
            P7DEA8Field(privateState, short*, 6) = initWord2;
            phaseByte3 = P7DEA8Field(owner, unsigned char*, 0x46);
            initWord2 = 0xB4;
            P7DEA8Field(privateState, short*, 0xE) = initWord2;
            initWord2 = -1;
            P7DEA8Field(privateState, int*, 0x10) = initWord2;
            MATCHING_BARRIER("memory");
            initWord2 = 1;
            P7DEA8Field(privateState, short*, 0xA) = 0;
            P7DEA8Field(privateState, short*, 0xC) = 0;
            P7DEA8Field(privateState, short*, 8) = phaseByte3 << 4;
            P7DEA8Field(owner, unsigned char*, 0x48) = initWord2;
        case 1:
            ownerWord0C = P7DEA8Field(owner, int*, 0xC);
            if ((ownerWord0C > 0x3D400) ||
                (ownerWord10 = P7DEA8Field(owner, int*, 0x10), ((ownerWord10 > 0x3D400) != 0)) ||
                (ownerWord14 = P7DEA8Field(owner, int*, 0x14), ((ownerWord14 > 0x1E000) != 0)) ||
                (ownerWord0C < 0x400) || (ownerWord10 < 0x400) || (ownerWord14 < 0x400) ||
                ((result2 = P7DEA8CountTimerDown(privateState + 0xE, 2)), (stackArg4 = &frame.sp28),
                 result2 != 0)) {
                if (P7DEA8SoundHandleMatchesOwnerInStates1Or2(
                        owner, P7DEA8Field(privateState, int*, 0x10)) != 0) {
                    P7DEA8TransitionSoundHandleTo3Or5(P7DEA8Field(privateState, int*, 0x10));
                }
                goto block_93;
            }
            MATCHING_KEEP(owner);
            savedOwnerVector0C = owner + 0xC;
            P7DEA8CopyVector(stackArg4, savedOwnerVector0C);
            if (P7DEA8Field(P7DEA8Field(privateState, void**, 0), unsigned char*, 0x48) & 0x80) {
                P7DEA8Field(privateState, void**, 0) = 0;
            }
            linkedObject00 = P7DEA8Field(privateState, void**, 0);
            if (linkedObject00 != 0) {
                P7DEA8CopyVector(&frame.sp48, linkedObject00 + 0xC);
                frame.sp50 += 0x80;
                vector38 = &frame.sp38;
                P7DEA8SubtractVector(vector38, &frame.sp48, savedOwnerVector0C);
                frame.sp40 += 0x100;
                P7DEA8PlanarHeadingLookup(frame.sp38, frame.sp3C, 1);
                result2 = P7DEA8PlanarHeadingLookup(frame.sp38, frame.sp3C, 1);
                halfword3 = P7DEA8Field(privateState, short*, 8);
                wrappedDifference08 = (result2 - halfword3) & 0xFFF;
                previousHalfword08 = halfword3;
                if (wrappedDifference08 >= 0x801) {
                    wrappedDifference08 -= 0x1000;
                }
                absoluteDifference08 = wrappedDifference08;
                if (wrappedDifference08 < 0) {
                    absoluteDifference08 = -absoluteDifference08;
                }
                if (absoluteDifference08 < 0x300) {
                    work3 = 0xB4;
                    result2 = P7DEA8Field(privateState, short*, 0xE);
                    work3 -= result2;
                    MATCHING_KEEP(work3);
                    upperStep = work3 >> 2;
                    lowerStep = -upperStep;
                    if (upperStep >= 9) {
                        upperStep = 8;
                        MATCHING_KEEP(upperStep);
                        lowerStep = -upperStep;
                    }
                    if (wrappedDifference08 < lowerStep)
                        wrappedDifference08 = lowerStep;
                    if (upperStep < wrappedDifference08)
                        wrappedDifference08 = upperStep;
                    P7DEA8Field(privateState, short*, 8) =
                        (short)(previousHalfword08 + wrappedDifference08);
                    result2 = P7DEA8MeasureVectorLength(vector38, 0, wrappedDifference08,
                                                        previousHalfword08);
                    result2 = P7DEA8PlanarHeadingLookup(result2, frame.sp40, 1);
                    previousHalfword06 = P7DEA8Field(privateState, short*, 6);
                    wrappedDifference06 = (result2 - previousHalfword06) & 0xFFF;
                    if (wrappedDifference06 >= 0x801) {
                        wrappedDifference06 -= 0x1000;
                    }
                    absoluteDifference06 = wrappedDifference06;
                    if (wrappedDifference06 < 0) {
                        absoluteDifference06 = -absoluteDifference06;
                    }
                    if (absoluteDifference06 < 0x300) {
                        if (wrappedDifference06 < lowerStep)
                            wrappedDifference06 = lowerStep;
                        if (upperStep < wrappedDifference06)
                            wrappedDifference06 = upperStep;
                        updatedHalfword06 = previousHalfword06 + wrappedDifference06;
                        P7DEA8Field(privateState, short*, 6) = updatedHalfword06;
                    } else {
                        goto block_63;
                    }
                } else {
                block_63:
                    P7DEA8Field(privateState, void**, 0) = 0;
                }
            }
            P7DEA8Field(owner, unsigned char*, 0x44) =
                (unsigned char)((unsigned short)P7DEA8Field(privateState, unsigned short*, 4) >> 4);
            P7DEA8Field(owner, unsigned char*, 0x45) =
                (unsigned char)((unsigned short)P7DEA8Field(privateState, short*, 6) >> 4);
            P7DEA8Field(owner, unsigned char*, 0x46) =
                (unsigned char)((unsigned short)P7DEA8Field(privateState, short*, 8) >> 4);
            P7DEA8RefreshMobySpatialGridAndBasis(owner, 4);
            frame.sp38 = 0x180;
            frame.sp3C = 0;
            frame.sp40 = 0;
            P7DEA8TransformVectorByBasis(owner + 0x20, &frame.sp38, &frame.sp38);
            ownerVectorArgument = owner + 0xC;
            P7DEA8AddVector(ownerVectorArgument, ownerVectorArgument, &frame.sp38);
            savedVector28 = &frame.sp28;
            if (P7DEA8QueryWorldSegmentWithOptions(savedVector28, ownerVectorArgument, 0, 0x10000,
                                                   owner) != 0) {
                globalWordAddress16 = &P7DEA8D_80071924;
                if (P7DEA8GetSurfaceTypeFromFlags(*globalWordAddress16) == 3) {
                    temp_a0_2 =
                        *(void**)((unsigned char*)P7DEA8Field(P7DEA8D_8006D048, void**, 0x14) +
                                  ((*globalWordAddress16 & 0x3F) * 4));
                    P7DEA8Field(temp_a0_2, int*, 4) =
                        (int)(P7DEA8Field(temp_a0_2, int*, 4) | 0x10000);
                }
                P7DEA8CopyVector(ownerVectorArgument, savedVector28);
                goto block_71;
            }
            queriedObject =
                P7DEA8QueryDynamicMobyGeometry(ownerVectorArgument, 0x200, 1, 0, 0, owner);
            if (queriedObject != 0) {
                P7DEA8CopyVector(&frame.sp58, queriedObject + 0xC);
                frame.sp60 += 0x80;
                if (P7DEA8QueryWorldSegment(ownerVectorArgument, &frame.sp58) == 0) {
                    P7DEA8Field(queriedObject, int*, 0x18) =
                        (int)(P7DEA8Field(queriedObject, int*, 0x18) | 0x10000);
                block_71:
                    P7DEA8Field(owner, unsigned char*, 0x48) = 2U;
                }
            }
            if (P7DEA8SoundHandleMatchesOwnerInStates1Or2(
                    owner, P7DEA8Field(privateState, int*, 0x10)) == 0) {
                P7DEA8Field(privateState, int*, 0x10) = P7DEA8PlayMobySoundEvent(owner, 0, 4);
            } else {
                /* Keep the original division constant before the signed load. */
                signedDivision180Magic = (int)0xB60B60B7;
                __asm__("" : "=r"(privateState) : "0"(privateState), "r"(signedDivision180Magic));
                halfword3 = P7DEA8Field(privateState, short*, 0xE);
                result2 = (int)((unsigned int)(0xB4 - halfword3) << 13);
                work3 = result2 / 180;
                MATCHING_KEEP(work3);
                result2 = 0x1000;
                MATCHING_KEEP(result2);
                scaledWord16 = result2 - work3;
                if (scaledWord16 < 0xA00) {
                    scaledWord16 = 0xA00;
                }
                P7DEA8SetSoundHandleScaledDescriptorAverage(P7DEA8Field(privateState, int*, 0x10),
                                                            scaledWord16);
            }
            P7DEA8ShiftVectorRightTowardZero(&frame.sp38, 2);
            P7DEA8SpawnParticle(1, 0x37, owner + 0xC, &frame.sp38);
            return;
        case 2:
            temp_s1_3 = owner + 0xC;
            temp_v0_2 = P7DEA8QueryDynamicMobyGeometry(temp_s1_3, 0x400, 1, 0, 0, owner);
            if ((temp_v0_2 != 0) && (P7DEA8QueryWorldSegment(temp_s1_3, temp_v0_2 + 0xC) == 0)) {
                P7DEA8Field(temp_v0_2, int*, 0x18) =
                    (int)(P7DEA8Field(temp_v0_2, int*, 0x18) | 0x10000);
            }
            if (P7DEA8SoundHandleMatchesOwnerInStates1Or2(
                    owner, P7DEA8Field(privateState, int*, 0x10)) != 0) {
                P7DEA8TransitionSoundHandleTo3Or5(P7DEA8Field(privateState, int*, 0x10));
            }
            if ((P7DEA8D_8006C578 - P7DEA8D_8006C574) >= 0x15) {
                temp_v0_3 = P7DEA8SpawnMoby(0x146, owner);
                if (temp_v0_3 != 0) {
                    P7DEA8Field(temp_v0_3, signed char*, 0x47) = 8;
                    P7DEA8Field(temp_v0_3, signed char*, 0x4C) = 0x3F;
                    P7DEA8Field(temp_v0_3, signed char*, 0x4E) = 0x3F;
                }
            }
            P7DEA8PlayMobySoundEvent(owner, 1, 0);
            P7DEA8Field(privateState, short*, 0xE) = 4;
            P7DEA8Field(owner, unsigned char*, 0x48) = 3U;
        case 3:
            temp_v0_4 = P7DEA8Field(privateState, short*, 0xE);
            temp_v0_5 = (int)((unsigned int)temp_v0_4 << 4);
            var_s2_2 = temp_v0_5 / 4;
            var_s1_3 = 0;
            signedTable65920 = (short*)P7DEA8D_80065920;
            signedTable658A0 = (short*)P7DEA8D_800658A0;
            do {
                temp_v1_6 = P7DEA8Field(privateState, unsigned char**, 0x14) + (var_s1_3 * 2);
                tableIndex4 = P7DEA8Field(temp_v1_6, unsigned char*, 0) * 2;
                tablePointer2 =
                    (short*)((unsigned char*)(long)tableIndex4 + (long)signedTable65920);
                tableProduct2 = *tablePointer2 * var_s2_2;
                tableIndex5 = P7DEA8Field(temp_v1_6, unsigned char*, 1) * 2;
                temp_a2 = (short*)((unsigned char*)(long)tableIndex5 + (long)signedTable65920);
                tableHalfword3 = *temp_a2;
                tableProduct2 = (tableProduct2 >> 12) * tableHalfword3;
                tablePointer4 =
                    (short*)((unsigned char*)(long)tableIndex4 + (long)signedTable658A0);
                frame.sp78 = tableProduct2 >> 12;
                tableProduct2 = *tablePointer4 * var_s2_2;
                tableHalfword3 = *temp_a2;
                tableProduct2 = (tableProduct2 >> 12) * tableHalfword3;
                tablePointer5 =
                    (short*)((unsigned char*)(long)tableIndex5 + (long)signedTable658A0);
                frame.sp7C = tableProduct2 >> 12;
                tableProduct2 = *tablePointer5 * var_s2_2;
                var_s1_3 += 1;
                frame.sp80 = tableProduct2 >> 12;
                P7DEA8CopyVector(&frame.sp68, &frame.sp78, temp_a2);
                P7DEA8ShiftVectorLeft(&frame.sp68, 4);
                P7DEA8AddVector(&frame.sp68, &frame.sp68, owner + 0xC);
                P7DEA8SpawnParticle(1, 0x13, &frame.sp68, &frame.sp78);
            } while (var_s1_3 < 0xC);
            if (P7DEA8CountTimerDown(privateState + 0xE, 2) != 0) {
                goto block_93;
            }
            break;
    }
    return;
block_93:
    P7DEA8DeleteMoby(owner);
}

#undef P7DEA8Field

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
void func_level_26_8007B590(Moby* moby) {
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

int func_8004EDE8(Vector3D*, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level_12/moby/func_level_12_8008243C.s,
 * level_13/moby/func_level_13_80081F50.s,
 * level_26/moby/func_level_26_8007B99C.s; all251 instructions read per copy.
 * Three tag words+0/+4/+8; signed remainder retains original division traps.
 * Original halfword table samples shift three in initialization, seven after
 * multiplication by three for particle components. Clamp is64; local bounds
 * retain the original multiply/shift and strict comparisons. Stack components
 * preserve their original 16-byte spacing. Units and fixed-point interpretation,
 * table/helper producers and caller cadence remain unresolved. Once per call.
 * Existing names do not establish semantics. Confidence: exact compiled words.
 * Falsifiable vectors: every original linked word and all complete retail hashes.
 * Empty constraints preserve original register lifetimes without opcode patches.
 */
typedef struct {
    int phaseOffset, firstSpan, secondSpan;
} Controller8243CTag;
extern short RawPulseCos[] __asm__("D_80065920");
extern short RawPulseSin[] __asm__("D_800658A0");
extern int RawPulseTick __asm__("D_8006C644");
extern int RawPulsePlayerFlags __asm__("D_8007034C");
extern int RawPulsePlayerHeading __asm__("D_800705C0");
extern Vector3D RawPulsePlayer __asm__("D_80070328");
extern Vector3D RawPulseCollision __asm__("D_80071900");
extern Vector3D RawPulseNormal __asm__("D_80071918");
extern int RawPulseNormalY __asm__("D_8007191C");
extern int RawPulseNormalZ __asm__("D_80071920");
void RawPulsePosition(Moby*, int, Vector3D*) __asm__("func_80055F14");
void RawPulseCopyMatrix(SHORTMATRIX*, SHORTMATRIX*) __asm__("func_8004ECF4");
void func_level_26_8007B99C(Moby* moby) {
    register Moby* owner __asm__("$18") = moby;
    Vector3D origin;
    int reserved1C;
    Vector3D target;
    int reserved2C;
    Vector3D particle;
    int reserved3C;
    Vector3D offset;
    int reserved4C;
    SHORTMATRIX matrix;
    register Controller8243CTag* tag __asm__("$19");
    register int phase __asm__("$16");
    register int lower __asm__("$19");
    register int upper __asm__("$20");
    register Vector3D* position __asm__("$17");
    register Vector3D* scratch __asm__("$16");
    int value;
    {
        register int first __asm__("$2");
        register int state __asm__("$3");
        register Vector3D* initializeArgument __asm__("$4");
        MATCHING_OBSERVE_CLOBBER(owner, "$2");
        first = 1;
        state = owner->state;
        tag = owner->mobyTag;
        __asm__(""
                : "=r"(first), "=r"(state)
                : "0"(first), "1"(state), "r"(owner), "r"(tag)
                : "$4");
        if (state == first)
            goto sharedPhase;
        if (state < 2) {
            initializeArgument = &origin;
            if (state == 0)
                goto initialize;
            goto sharedPhase;
        }
        if (state == 2)
            goto emitParticle;
        goto sharedPhase;
    initialize:
        MATCHING_BARRIER("$3");

        {
            register Vector3D* prepared __asm__("$4") = initializeArgument;
            register Vector3D* preparedPosition __asm__("$5");
            register Vector3D* preparedDirection __asm__("$6");
            register int sample __asm__("$2");
            __asm__("" : "=r"(prepared) : "0"(prepared) : "$17", "$16", "$5", "$6");
            sample = owner->angle.yaw;
            MATCHING_KEEP_CLOBBER(sample, "$17");
            position = &owner->position;
            MATCHING_BARRIER("$5");
            sample = D_80065920[sample];
            __asm__(""
                    : "=r"(sample), "=r"(position)
                    : "0"(sample), "1"(position)
                    : "$16", "$6", "$5");
            preparedPosition = position;
            target.x = sample >> 3;
            sample = owner->angle.yaw;
            MATCHING_KEEP_CLOBBER(sample, "$16");
            scratch = &target;
            MATCHING_BARRIER("$6");
            sample = D_800658A0[sample];
            MATCHING_KEEP2_CLOBBER(sample, scratch, "$6");
            preparedDirection = scratch;
            target.z = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            target.y = sample >> 3;
            func_8004F194(prepared, preparedPosition, preparedDirection);
        }
        func_8004F1C8(scratch, position, scratch);
        {
            register int hit __asm__("$2") = func_80018368(&origin, scratch);
            register Vector3D* destination __asm__("$4");
            MATCHING_KEEP2_CLOBBER(hit, position, "$4");
            destination = position;
            if (hit) {
                MATCHING_BARRIER("$2");
                scratch = &RawPulseCollision;
                MATCHING_KEEP(scratch);
                func_8004F178(destination, scratch);
                owner->angle.yaw = func_8004E880(*(int*)((char*)scratch + 24), RawPulseNormalY, 0);
                scratch = (Vector3D*)((char*)scratch + 24);
                MATCHING_KEEP(scratch);
                value = func_8004EDE8(scratch, 0);
                owner->angle.pitch = func_8004E880(value, RawPulseNormalZ, 0);
                func_80055D24(owner, 4);
            }
        }
        owner->state = 1;
        goto sharedPhase;
    emitParticle:;
        {
            register Moby* prepared __asm__("$4") = owner;
            register int zero __asm__("$5");
            MATCHING_KEEP_CLOBBER(prepared, "$5");
            zero = 0;
            MATCHING_KEEP2_CLOBBER(prepared, zero, "$16");
            scratch = &particle;
            RawPulsePosition(prepared, zero, scratch);
        }
        offset.x = (*(short*)((char*)RawPulseCos + owner->angle.yaw * 2) * 3) >> 7;
        offset.y = (*(short*)((char*)RawPulseSin + owner->angle.yaw * 2) * 3) >> 7;
        offset.z = 0;
        {
            register int noise __asm__("$2") = rand();
            register int component __asm__("$3") = offset.x;
            __asm__("" : "=r"(noise) : "0"(noise), "r"(component));
            component -= 7;
            MATCHING_KEEP(component);
            offset.x = component + (noise & 14);
        }
        {
            register int noise __asm__("$2") = rand();
            register int component __asm__("$3") = offset.y;
            __asm__("" : "=r"(noise) : "0"(noise), "r"(component));
            component -= 7;
            MATCHING_KEEP(component);
            offset.y = component + (noise & 14);
        }
        {
            register int noise __asm__("$2") = rand();
            register int type __asm__("$4") = 1;
            register int selector __asm__("$5") = 19;
            register Vector3D* particlePosition __asm__("$6") = scratch;
            register int component __asm__("$3");
            MATCHING_OBSERVE3_CLOBBER(type, selector, particlePosition, "$3");
            component = *(volatile int*)&offset.z;
            __asm__ volatile("" : "=r"(noise) : "0"(noise), "m"(offset.z));
            noise &= 14;
            component -= 7;
            component += noise;
            MATCHING_KEEP_CLOBBER(component, "$7");
            offset.z = component;
            SpawnParticle(type, selector, particlePosition, &offset);
        }
    }
sharedPhase:
    {
        register int numerator __asm__("$3") = RawPulseTick;
        register int start __asm__("$5") = tag->phaseOffset;
        register int active __asm__("$4") = tag->firstSpan;
        register int inactive __asm__("$2") = tag->secondSpan;
        int denominator;
        __asm__(""
                : "=r"(numerator), "=r"(start), "=r"(active)
                : "0"(numerator), "1"(start), "2"(active), "r"(inactive));
        numerator += start;
        denominator = active + inactive;
        phase = numerator % denominator;
        active = phase < active;
        MATCHING_KEEP(active);
        if (active) {
            if (owner->state != 2)
                func_8003BABC(owner, 0, 0);
            owner->state = 2;
        } else
            owner->state = 1;
    }
    if (tag->secondSpan == 0) {
        upper = 3072;
        lower = 0;
    } else if (owner->state == 2) {
        register int scaled __asm__("$2");
        if (phase > 64) {
            phase = 64;
            MATCHING_KEEP(phase);
        }
        scaled = phase * 2;
        scaled = (scaled + phase) << 5;
        MATCHING_KEEP(scaled);
        upper = scaled >> 1;
        lower = 0;
    } else {
        register int active __asm__("$2") = tag->firstSpan;
        register int scaled __asm__("$3") = (active * 3) << 5;
        MATCHING_KEEP2(scaled, active);
        upper = scaled >> 1;
        active = phase - active;
        scaled = (active * 3) << 5;
        MATCHING_KEEP(scaled);
        lower = scaled >> 1;
    }
    if (lower < upper) {
        func_8004F1C8(&offset, &RawPulsePlayer, &owner->position);
        RawPulseCopyMatrix(&matrix, &owner->rotationMatrix);
        func_8004ED6C(&matrix, &offset, &offset);
        {
            register int x __asm__("$3") = offset.x;
            register int inside __asm__("$2");
            inside = lower < x;
            MATCHING_KEEP2(inside, x);
            if (!inside)
                goto done;
            inside = x < upper;
            MATCHING_KEEP(inside);
            if (!inside)
                goto done;
        }
        if (ABS(offset.y) < 512 && ABS(offset.z) < 512) {
            RawPulsePlayerFlags |= 14;
            RawPulsePlayerHeading = owner->angle.yaw;
        }
    }
done:;
}

extern int D_8006C770;
void func_80055B18(Moby*);
int func_80055E84(Moby*);
void func_level_26_8007BD88(Moby* moby) {
    if (D_8006C770)
        func_80055B18(moby);
    else {
        register int value asm("$3") = func_80055E84(moby) - 0x23;
        /* Non-emitting constraint preserves the two retail arithmetic steps. */
        MATCHING_KEEP_VOLATILE(value);
        if (value >= -0xF) {
            register int alpha __asm__("$2");
            value += 0x10;
            MATCHING_KEEP_VOLATILE(value);
            alpha = value | 0x30;
            MATCHING_KEEP_VOLATILE(alpha);
            *(int*)&moby->colour = 0;
            moby->colour.a = alpha;
        }
    }
}

typedef struct {
    unsigned char reserved00[0x48];
    int heading;
    Vector3D position;
} DecodedCheckpointTag;
int DecodedCheckpointBounds(Vector3D*, void*, int, int) __asm__("func_80036220");
void func_level_26_8007BDEC(Moby* moby) {
    Vector3D position;
    int heading;
    unsigned char state;
    register void* bounds __asm__("$5") = moby->mobyTag;
    MATCHING_KEEP(bounds);
    if (DecodedCheckpointBounds((Vector3D*)&spyro, bounds, 0, 0x400)) {
        DecodedCheckpointTag* tag = spyro.critterMobyPtr->mobyTag;
        heading = tag->heading;
        position.x = (D_80065920[heading] * 13) >> 5;
        heading -= 0x80;
        MATCHING_KEEP(heading);
        position.y = (D_800658A0[tag->heading] * 13) >> 5;
        position.z = 0;
        func_8004F194(&position, &position, &tag->position);
        state = spyro.critterMobyPtr->state;
        spyro.critterMobyPtr->state = 0;
        func_8003B7B4(&spyro.critterMobyPtr->state, 1, &unsavedData);
        spyro.critterMobyPtr->state = state;
        func_8003B634(&savedData, &position, heading & 255);
        func_8003B74C(&savedData);
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
    int soundIndex, enabled, linkedIndex;
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
extern Moby* D_8006C550;
/* SCUS-94467 USA Rev0 8007BF1C..8007C3C4, 299 original words.
 * Reuses verified func_level_13_80082590; Original tag+28 linked index and linked Moby state>=128 activation.
 * Raw field widths, helper identities and fixed-point shifts remain retail.
 * Complete units, producer/helper semantics and caller cadence remain open.
 * Empty constraints retain compiler lifetimes and emit no instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1659.
 */
void func_level_26_8007BF1C(Moby* mobyArgument) {
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
            if (!DecodedEventTick && tag->linkedIndex != -1 &&
                D_8006C550[tag->linkedIndex].state >= 128) {
                moby->updateDistance = 255;
                moby->state = 1;
                DecodedEventTimer(&moby->state, 1, DecodedEventTimerData);
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
void func_level_26_8007C3C8(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original function8007C6F8.
* Assembly SHA256 937679b0144a39c07d746c940ad7edb855a5c8063cffea0bf57f9956c21af47f.
* Original328 instructions and conditional/internal targets are required.
* Branch196 consumes the range predicate before ADDI197 writes v0. The old
* counter remains in v1, and SW198 stores the distinct incremented result.
* Paired .set modes emit zero CPU instructions; C produces the branch, sum
* and store. Original input/result boundaries use distinct initialized values.
* Original frame/scratch and byte-domain addresses, signed table loads,
* helper argument producers and compound executable-symbol address expressions
* remain unchanged. Existing raw55 Rev1 evidence supplies structural leads,
* not implicit helper/region equivalence. Physical units/fixed point, complete
* helper semantics and caller cadence remain unresolved.
* Falsification: every native/linked word, target, preserved data and full
* executable/every-overlay retail hash, with unchanged compiler/pipeline/flags.
* AI-generated; not human reviewed. No synchronized runtime parity claim. */
/* AI generated; not human reviewed. Original-instruction-derived raw55 handler; Rev1 raw55 structural evidence is a lead only. Compound original address expressions preserved as symbol aliases. Unknown raw units/helper/cadence/runtime. Exact native/linked/full hashes required. */
#define Level26_7C6F8_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level26_7C6F8QueryWorldSegment() __asm__("func_80018368");
/* extern */
unsigned char Level26_7C6F8SetMobyAnimation() __asm__("func_80034F80");
/* extern */
int Level26_7C6F8MeasureVectorLength() __asm__("func_8004EDE8");
/* extern */
unsigned char Level26_7C6F8ShiftVectorRightTowardZero() __asm__("func_8004F110");
/* extern */
unsigned char Level26_7C6F8SubtractVector() __asm__("func_8004F1C8");
/* extern */
unsigned char Level26_7C6F8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
unsigned char Level26_7C6F8InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern unsigned char Level26_7C6F8_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level26_7C6F8_D_80065920 __asm__("D_80065920");
extern int Level26_7C6F8_D_8006C54C __asm__("D_8006C54C");
extern int Level26_7C6F8_D_8006C640 __asm__("D_8006C640");
extern int Level26_7C6F8_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level26_7C6F8Byte307 __asm__("D_80070300+7");
extern int Level26_7C6F8_D_80071918 __asm__("D_80071918");
extern int Level26_7C6F8_D_8007191C __asm__("D_8007191C");
extern int Level26_7C6F8_D_80071920 __asm__("D_80071920");
extern int Level26_7C6F8_D_800722B8 __asm__("D_800722B8");
extern unsigned char Level26_7C6F8ByteBeginBias __asm__("func_8002CA50 + 1 - 0x642F");
extern unsigned char Level26_7C6F8ByteEndBias __asm__("func_8002D044 + 1 - 0x642F");
extern int Level26_7C6F8Mode1Flag __asm__("D_8006C770");
extern int Level26_7C6F8Mode3Flag __asm__("D_8006C770");
void func_level_26_8007C6F8(Moby* moby) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        int pad1c;
        Vector3D sp20;
        int pad2c;
        Vector3D sp30;
        int pad3c;
        int sp40;
        int pad44[3];
        int sp50;
        int pad54;
        int sp58;
        int pad5c;
        int sp60;
        int pad64[3];
    } frame;
    register Moby* arg0 __asm__("$20") = moby;
    register void* vector16 __asm__("$16");
    register void* vector17 __asm__("$17");
    register void* vector18 __asm__("$18");
    register unsigned char* temp_v1 __asm__("$3");
    Moby* temp_v0;
    register Vector3D* temp_s1 __asm__("$17");
    int temp_v0_2;
    int temp_v0_3;
    register int temp_v1_2 __asm__("$3");
    register int var_a0 __asm__("$4");
    register int var_a1 __asm__("$5");
    int var_v0;
    int var_v0_2;
    register unsigned char temp_v1_3 __asm__("$3");
    int value2;
    register int sample3 __asm__("$3");
    register int result4 __asm__("$4");
    register void* call4 __asm__("$4");
    register int argument5 __asm__("$5");
    register void* argument6 __asm__("$6");
    register void* temp_s3 __asm__("$19");
    MATCHING_KEEP(arg0);
    temp_s3 = arg0->mobyTag;
    if (arg0->state != 4) {
        if (arg0->damageFlags != 0) {
            Level26_7C6F8_Field(temp_s3, int*, 0xC) = 0x40;
            if (Level26_7C6F8_Field(temp_s3, int*, 4) < 0x80) {
                Level26_7C6F8_Field(temp_s3, int*, 4) = 0x40;
            } else {
                Level26_7C6F8_Field(temp_s3, int*, 4) = 0xC0;
            }
            func_8003BABC(arg0, 0, 0);
        }
        arg0->damageFlags = 0;
        if (Level26_7C6F8_Field(temp_s3, Moby**, 0) == 0) {
            temp_v0 = SpawnMoby(0x37, arg0);
            Level26_7C6F8_Field(temp_s3, Moby**, 0) = temp_v0;
            if (temp_v0 != 0) {
                Level26_7C6F8SetMobyAnimation(temp_v0, 4);
                vector16 = &frame.sp30;
                func_8004F178(vector16, &arg0->position);
                frame.sp30.z += 0x800;
                value2 = arg0->angle.yaw;
                MATCHING_KEEP_CLOBBER(value2, "$17");
                vector17 = &frame.sp20;
                value2 *= 2;
                value2 = Level26_7C6F8_Field(&Level26_7C6F8_D_80065920, short*, value2);
                MATCHING_KEEP(value2);
                call4 = vector17;
                frame.sp10 = value2 >> 3;
                value2 = arg0->angle.yaw;
                MATCHING_KEEP_CLOBBER(value2, "$5");
                argument5 = (int)vector16;
                value2 *= 2;
                value2 = Level26_7C6F8_Field(&Level26_7C6F8_D_800658A0, short*, value2);
                MATCHING_KEEP_CLOBBER(value2, "$6");
                argument6 = &frame.sp10;
                frame.sp18 = 0;
                MATCHING_OBSERVE2_VOLATILE_CLOBBER(value2, argument6, "memory");
                frame.sp14 = value2 >> 3;
                func_8004F194(call4, argument5, argument6);
                Level26_7C6F8SubtractVector(&frame.sp10, vector16, &frame.sp10);
                if (Level26_7C6F8QueryWorldSegment(vector17, &frame.sp10) != 0) {
                    vector16 = &Level26_7C6F8_D_80071918;
                    MATCHING_KEEP(vector16);
                    Level26_7C6F8_Field(temp_s3, Moby**, 0)->angle.yaw =
                        func_8004E880(*(int*)vector16, Level26_7C6F8_D_8007191C, 0) + 0x40;
                    Level26_7C6F8_Field(temp_s3, Moby**, 0)->angle.pitch = func_8004E880(
                        Level26_7C6F8MeasureVectorLength(vector16, 0), Level26_7C6F8_D_80071920, 0);
                    Level26_7C6F8RefreshMobySpatialGridAndBasis(
                        Level26_7C6F8_Field(temp_s3, Moby**, 0), 4);
                    Level26_7C6F8InterpolateMobyVertex(Level26_7C6F8_Field(temp_s3, Moby**, 0), 4,
                                                       &frame.sp10);
                    Level26_7C6F8SubtractVector(&frame.sp10,
                                                &Level26_7C6F8_Field(temp_s3, Moby**, 0)->position,
                                                &frame.sp10);
                    func_8004F194(&Level26_7C6F8_Field(temp_s3, Moby**, 0)->position,
                                  (Vector3D*)&frame.sp10,
                                  (Vector3D*)((unsigned char*)vector16 - 0x18));
                }
                arg0->angle.yaw = Level26_7C6F8_Field(temp_s3, Moby**, 0)->angle.yaw;
                Level26_7C6F8_Field(temp_s3, Moby**, 0)->unknownCollision = 0;
                Level26_7C6F8_Field(temp_s3, Moby**, 0)->state = 4;
                Level26_7C6F8_Field(temp_s3, int*, 0xC) = 0x100;
            }
        }
        if (Level26_7C6F8_Field(temp_s3, unsigned char**, 0x10) == 0) {
            Level26_7C6F8_Field(temp_s3, unsigned char**, 0x10) = &Level26_7C6F8ByteBeginBias;
        }
        temp_v1 = Level26_7C6F8_Field(temp_s3, unsigned char**, 0x10);
        var_a0 = 0;
        if ((unsigned int)temp_v1 < (unsigned int)&Level26_7C6F8ByteEndBias) {
            Level26_7C6F8_Field(temp_s3, int*, 8) =
                (int)(Level26_7C6F8_Field(temp_s3, int*, 8) ^
                      (Level26_7C6F8_Field(temp_v1, unsigned char*, 0x642F) << 0x18));
            do {
                temp_v0_2 = Level26_7C6F8_Field(temp_s3, int*, 8);
                if (temp_v0_2 < 0) {
                    var_v0 = (temp_v0_2 * 2) ^ 0x80050000;
                } else {
                    var_v0 = temp_v0_2 * 2;
                }
                Level26_7C6F8_Field(temp_s3, int*, 8) = var_v0;
                MATCHING_BARRIER_VOLATILE("memory");
                var_a0 += 1;
            } while (var_a0 < 8);
            Level26_7C6F8_Field(temp_s3, unsigned char**, 0x10) =
                (unsigned char*)(Level26_7C6F8_Field(temp_s3, unsigned char**, 0x10) + 1);
        } else if (((((int)Level26_7C6F8_Field(temp_s3, int*, 8) >> 0xC) & 0xFFFF0) |
                    (Level26_7C6F8_D_800722B8 & 0xFFF0000F)) != unk_ovlheader_800743C8) {
            value2 = Level26_7C6F8Byte307;
            value2 &= 254;
            Level26_7C6F8Byte307 = value2;
            Level26_7C6F8_Field(temp_s3, int*, 8) = 0;
        }
        temp_v1_2 = Level26_7C6F8_Field(temp_s3, int*, 0xC);
        /* Original196/197 is BEQ/ADDI2,3,1. Both source and result
        * are initialized and distinct; the predicate is consumed first.
        * Mode metadata emits zero CPU instructions. */
        value2 = temp_v1_2 < 0x100;
        __asm__ volatile(".set\tnoreorder" : : "r"(value2));
        if (value2) {
            value2 = temp_v1_2 + 1;
            __asm__ volatile(".set\treorder" : "=r"(value2) : "0"(value2), "r"(temp_v1_2));
            Level26_7C6F8_Field(temp_s3, int*, 12) = value2;
        }
        MATCHING_KEEP_CLOBBER(temp_v1_2, "$2");
        value2 = Level26_7C6F8_Field(temp_s3, int*, 4);
        value2 *= 2;
        sample3 = Level26_7C6F8_Field(&Level26_7C6F8_D_800658A0, short*, value2);
        value2 = Level26_7C6F8_Field(temp_s3, int*, 0xC);
        __asm__("" : "=r"(value2) : "0"(value2), "r"(sample3));
        result4 = sample3 / value2;
        MATCHING_KEEP_CLOBBER(result4, "$5");
        argument5 = arg0->angle.pitch;
        result4 = func_8003613C(result4, argument5);
        MATCHING_KEEP(result4);
        value2 = result4 - 1;
        if (result4 < 0)
            goto applyPitch;
        value2 = result4 + 1;
        if (result4 > 0) {
        applyPitch:
            sample3 = arg0->angle.pitch;
            value2 >>= 1;
            sample3 -= value2;
            arg0->angle.pitch = sample3;
        }
        Level26_7C6F8_Field(temp_s3, int*, 4) =
            (int)((Level26_7C6F8_Field(temp_s3, int*, 4) + 4) & 0xFF);
        temp_v1_3 = arg0->animationState.id;
        if (temp_v1_3 == 1)
            goto animation1;
        if (temp_v1_3 == 3)
            goto animation3;
        goto afterAnimation;
    animation1:
        value2 = Level26_7C6F8Mode1Flag;
        if (!value2)
            goto afterAnimation;
        value2 = Level26_7C6F8_D_8006C640;
        MATCHING_KEEP_CLOBBER(value2, "$4");
        call4 = arg0;
        if (!value2)
            goto animation2;
        value2 = Level26_7C6F8_D_8006C54C;
        MATCHING_KEEP_CLOBBER(value2, "$5");
        if (!value2)
            goto afterAnimation;
    animation2:
        argument5 = 2;
        goto animationCall;
    animation3:
        value2 = Level26_7C6F8Mode3Flag;
        MATCHING_KEEP_CLOBBER(value2, "$4");
        call4 = arg0;
        if (!value2)
            goto afterAnimation;
        argument5 = 0;
    animationCall:
        func_80034F40(call4, argument5);
    afterAnimation:
        if (Level26_7C6F8_Field(temp_s3, Moby**, 0) != 0) {
            Level26_7C6F8RefreshMobySpatialGridAndBasis(arg0, 6);
            argument5 = 2;
            MATCHING_KEEP_CLOBBER(argument5, "$18");
            vector18 = &frame.sp40;
            Level26_7C6F8InterpolateMobyVertex(Level26_7C6F8_Field(temp_s3, Moby**, 0), argument5,
                                               vector18);
            argument5 = 3;
            MATCHING_KEEP_CLOBBER(argument5, "$16");
            vector16 = &frame.sp50;
            Level26_7C6F8InterpolateMobyVertex(Level26_7C6F8_Field(temp_s3, Moby**, 0), argument5,
                                               vector16);
            func_8004F194((Vector3D*)vector18, (Vector3D*)vector18, (Vector3D*)vector16);
            Level26_7C6F8ShiftVectorRightTowardZero(vector18, 1);
            Level26_7C6F8InterpolateMobyVertex(arg0, 0, vector16);
            call4 = arg0;
            MATCHING_KEEP_CLOBBER(call4, "$5");
            argument5 = 1;
            MATCHING_KEEP_CLOBBER(argument5, "$17");
            vector17 = &frame.sp60;
            Level26_7C6F8InterpolateMobyVertex(call4, argument5, vector17);
            func_8004F194((Vector3D*)vector16, (Vector3D*)vector16, (Vector3D*)vector17);
            Level26_7C6F8ShiftVectorRightTowardZero(vector16, 1);
            call4 = vector16;
            MATCHING_KEEP_CLOBBER(call4, "$17");
            temp_s1 = &arg0->position;
            Level26_7C6F8SubtractVector(call4, temp_s1, vector16);
            frame.sp58 += 0x80;
            func_8004F194(temp_s1, (Vector3D*)vector16, (Vector3D*)vector18);
        }
    }
}
#undef Level26_7C6F8_Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/level_26/moby/func_level_26_8007CC18.s SHA256 77a00e09272fdd2315487c5810fa005c0e2952578e5a93e64d4221638cddb32b. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level26_7CC18Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Spyro Level26_7CC18_D_80070328 __asm__("D_80070328");
extern int Level26_7CC18QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
void Level26_7CC18SyncHudCounterTarget(HudEntry*) __asm__("func_80027A60");
void Level26_7CC18InitializeHudDecimalCounterLayout(HudEntry*) __asm__("func_80027E40");
int Level26_7CC18ConfigureHudEntry(int, int, void*, void*, void*, int*,
                                   int) __asm__("func_8002803C");
int Level26_7CC18ResetHudEntryByHandle(int) __asm__("func_80028154");
int Level26_7CC18DrawHudIconAndDecimalCounter(HudEntry*) __asm__("func_80029904");
int Level26_7CC18CountTimerDown(void*, int) __asm__("func_800359A4");
int Level26_7CC18ProbeGroundFromRaisedMoby(Moby* moby) __asm__("func_80035D38");
int Level26_7CC18PlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
extern void Level26_7CC18CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern int Level26_7CC18ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level26_7CC18DeleteMoby(Moby*) __asm__("func_80055B18");

int Level26_7CC18QueryWorldSegment(Spyro*, Vector3D*) __asm__("func_80018368");
/* extern */
int Level26_7CC18QueryWorldSphereWithOptions(Vector3D*, int, unsigned char, unsigned char, int,
                                             Moby*) __asm__("func_80019138");
/* extern */
int Level26_7CC18QueryDynamicMobyGeometry(Vector3D*, int, unsigned char, unsigned char, int,
                                          Moby*) __asm__("func_8001BA30");
/* extern */
int Level26_7CC18GetSurfaceTypeFromFlags(int) __asm__("func_80040954");
/* extern */
extern unsigned char Level26_7CC18_D_8006D048 __asm__("D_8006D048");
extern int Level26_7CC18_D_8006E044 __asm__("D_8006E044");
extern int Level26_7CC18_D_80071924 __asm__("D_80071924");

void func_level_26_8007CC18(Moby* inputOwner) {
    /* Original 0x58 frame, SP20/SP30 vectors, five-entry selector and
     * shared final 55B18 destination are retained. The position helper
     * uses the movement-state address minus 0x50 BYTES (the player base),
     * and the alternate anchor is D_8006E044 minus 0x24 BYTES. Word-sized
     * helper arguments preserve original 0x200 and 0x800 values. The HUD
     * constructor keeps seven arguments and the original signed-16 handle.
     * Angle bytes, word reloads, branch constants and spawned-field stores
     * retain their original producer order. Empty constraints emit no
     * instructions. Helper meanings, units/fixed point, frame cadence and
     * synchronized runtime validation remain unresolved. AI generated;
     * not human reviewed. */
    register Moby* owner17 __asm__("$17") = inputOwner;
    struct {
        Vector3D first;
        int pad2C;
        Vector3D second;
        int pad3C;
    } scratch;
    Moby* spawned;
    Moby* effect;
    register Vector3D* position16 __asm__("$16");
    register Vector3D* fallingPosition16 __asm__("$16");
    register Vector3D* landingPosition16 __asm__("$16");
    register int rotationDelta4 __asm__("$4");
    register int raw2 __asm__("$2");
    register int raw3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int* levelWord5 __asm__("$5");
    register int* selectedWord16 __asm__("$16");
    register Spyro* player19 __asm__("$19");
    register int temp_v0 __asm__("$2");
    int temp_v0_2;
    int temp_v0_6;
    int temp_v0_7;
    int var_v0;
    int var_v0_2;
    register int var_v0_3 __asm__("$2");
    unsigned char temp_v0_4;
    unsigned char temp_v0_5;
    register int state3 __asm__("$3");
    register void* playerMobyPrivate16 __asm__("$16");
    register void* private18 __asm__("$18");
    register void* spawnedPrivate18 __asm__("$18");
    register void* linkedPrivate19 __asm__("$19");
    register void* playerMobyPrivate20 __asm__("$20");
    void* temp_v1_2;

    MATCHING_KEEP(owner17);
    state3 = owner17->state;
    private18 = owner17->mobyTag;
    switch (state3) {
        case 0:
            owner17->drawn = 0;
            owner17->lowDrawDistance = 0;
            if ((Level26_7CC18Field(private18, Moby**, 0) == 0) &&
                (Level26_7CC18CountTimerDown(private18 + 6, 2) != 0)) {
                Level26_7CC18Field(private18, Moby**, 0) = SpawnMoby(0x68, owner17);
                return;
            }
        default:
            return;
        case 1:
            owner17->angle.yaw += 5;
            if (((unsigned int)(Level26_7CC18_D_80070328.movementState - 7) >= 2U) &&
                (Level26_7CC18ApproximatePlanarDistance(
                     &owner17->position,
                     (Vector3D*)((unsigned char*)&Level26_7CC18_D_80070328.movementState - 0x50)) <
                 0x200)) {
                raw2 = Level26_7CC18_D_80070328.position.z;
                argument4 = Level26_7CC18_D_80070328.unk4a;
                argument5 = owner17->distanceToGround;
                raw3 = owner17->position.z;
                raw2 -= argument4;
                raw3 += argument5;
                var_v0 = raw2 - raw3;
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if (var_v0 < 0x140) {
                    playerMobyPrivate16 = Level26_7CC18_D_80070328.critterMobyPtr->mobyTag;
                    linkedPrivate19 = Level26_7CC18Field(private18, Moby**, 0)->mobyTag;
                    if (Level26_7CC18Field(playerMobyPrivate16, Moby**, 0x30) == 0) {
                        Level26_7CC18PlayMobySoundEvent(Level26_7CC18_D_80070328.critterMobyPtr, 1,
                                                        0);
                        owner17->unknownCollision = 0;
                        Level26_7CC18Field(playerMobyPrivate16, int*, 0x34) = 4;
                        Level26_7CC18Field(playerMobyPrivate16, Moby**, 0x30) = owner17;
                        Level26_7CC18Field(private18, int*, 0x10) =
                            (short)Level26_7CC18ConfigureHudEntry(
                                0x15, 6, Level26_7CC18InitializeHudDecimalCounterLayout,
                                Level26_7CC18SyncHudCounterTarget,
                                Level26_7CC18DrawHudIconAndDecimalCounter,
                                playerMobyPrivate16 + 0x34,
                                Level26_7CC18Field(playerMobyPrivate16, int*, 0x34));
                        Level26_7CC18Field(linkedPrivate19, int*, 0) = 0;
                        Level26_7CC18Field(linkedPrivate19, unsigned short*, 6) =
                            (unsigned short)Level26_7CC18Field(linkedPrivate19, unsigned short*, 4);
                        Level26_7CC18Field(private18, int*, 0xC) =
                            (int)((owner17->angle.yaw - Level26_7CC18_D_80070328.bodyRotation.yaw) &
                                  0xFF);
                        owner17->state = 2;
                        owner17->angle.pitch = 0;
                        return;
                    }
                }
            }
            break;
        case 2:
            rotationDelta4 = Level26_7CC18Field(private18, int*, 0xC);
            raw2 = (int)Level26_7CC18_D_80070328.critterMobyPtr;
            raw3 = rotationDelta4 < 128;
            playerMobyPrivate20 = Level26_7CC18Field((void*)raw2, void**, 0);
            temp_v0 = rotationDelta4 + 4;
            if (!raw3) {
                Level26_7CC18Field(private18, int*, 12) = temp_v0;
                MATCHING_BARRIER_VOLATILE("memory");
                if (temp_v0 >= 0x100) {
                    Level26_7CC18Field(private18, int*, 0xC) = 0;
                }
            } else {
                temp_v0_2 = rotationDelta4 - 4;
                if (rotationDelta4 > 0) {
                    Level26_7CC18Field(private18, int*, 0xC) = temp_v0_2;
                    if (temp_v0_2 < 0) {
                        Level26_7CC18Field(private18, int*, 0xC) = 0;
                    }
                }
            }
            owner17->unknownCollision = 0;
            owner17->angle.roll = Level26_7CC18_D_80070328.bodyRotation.roll;
            owner17->angle.pitch = Level26_7CC18_D_80070328.bodyRotation.pitch + 0x40;
            owner17->angle.yaw = Level26_7CC18_D_80070328.bodyRotation.yaw +
                                 Level26_7CC18Field(private18, int*, 0xC);
            if (Level26_7CC18Field(playerMobyPrivate20, int*, 0x38) != 0) {
                Level26_7CC18PlayMobySoundEvent(owner17, 0, 0);
                if (Level26_7CC18Field(playerMobyPrivate20, int*, 0x34) < 2) {
                    if ((({
                             raw2 = 38;
                             MATCHING_KEEP(raw2);
                             levelWord5 = &Level26_7CC18_D_8006E044;
                             MATCHING_KEEP(levelWord5);
                             raw3 = *levelWord5;
                             raw3;
                         }) == raw2) &&
                        (owner17->lowDrawDistance == 0)) {
                        Level26_7CC18CopyVector(&owner17->position,
                                                (Vector3D*)((unsigned char*)levelWord5 - 0x24));
                        owner17->lowDrawDistance = 0x10;
                        owner17->position.z -= 0x200;
                    }
                    player19 = &Level26_7CC18_D_80070328;
                    argument4 = (int)player19;
                    MATCHING_KEEP_CLOBBER(argument4, "$16");
                    position16 = &owner17->position;
                    Level26_7CC18Field(playerMobyPrivate20, int*, 0x30) = 0;
                    Level26_7CC18Field(private18, short*, 6) = 0xB4;
                    if (Level26_7CC18QueryWorldSegment((Spyro*)argument4, position16) != 0) {
                        Level26_7CC18CopyVector(position16, &Level26_7CC18_D_80070328.position);
                        owner17->position.z = Level26_7CC18ProbeGroundFromRaisedMoby(owner17) + 0xA;
                        var_v0_2 = 0x14;
                    } else {
                        var_v0_2 = (int)Level26_7CC18_D_80070328.unk7a[3].z >> 5;
                    }
                    Level26_7CC18Field(private18, int*, 8) = var_v0_2;
                    owner17->state = 3;
                    Level26_7CC18ResetHudEntryByHandle(Level26_7CC18Field(private18, int*, 0x10));
                    return;
                }
                spawned = SpawnMoby((int)owner17->mobyClass, owner17);
                raw3 = 38;
                if (spawned != 0) {
                    raw2 = owner17->angle.roll;
                    spawned->angle.roll = raw2;
                    raw2 = owner17->angle.pitch;
                    levelWord5 = &Level26_7CC18_D_8006E044;
                    MATCHING_KEEP(levelWord5);
                    spawned->angle.pitch = raw2;
                    raw2 = owner17->angle.yaw;
                    spawned->unknownCollision = 0;
                    spawned->angle.yaw = raw2;
                    raw2 = *levelWord5;
                    spawnedPrivate18 = spawned->mobyTag;
                    if ((raw2 == raw3) && (owner17->lowDrawDistance == 0)) {
                        Level26_7CC18CopyVector(&spawned->position,
                                                (Vector3D*)((unsigned char*)levelWord5 - 0x24));
                        spawned->position.z -= 0x200;
                    }
                    Level26_7CC18Field(spawnedPrivate18, short*, 6) = 0x12C;
                    if (Level26_7CC18QueryWorldSegment(&Level26_7CC18_D_80070328,
                                                       &spawned->position) != 0) {
                        owner17->position.z = Level26_7CC18_D_80070328.position.z;
                        raw2 = Level26_7CC18ProbeGroundFromRaisedMoby(spawned);
                        raw2 += 10;
                        spawned->position.z = raw2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        var_v0_3 = 0x14;
                    } else {
                        var_v0_3 = (int)Level26_7CC18_D_80070328.unk7a[3].z >> 5;
                    }
                    Level26_7CC18Field(spawnedPrivate18, int*, 8) = var_v0_3;
                    spawned->state = 3;
                    Level26_7CC18Field(playerMobyPrivate20, int*, 0x34) =
                        (int)(Level26_7CC18Field(playerMobyPrivate20, int*, 0x34) - 1);
                    return;
                }
            }
            break;
        case 3:
            raw2 = owner17->angle.pitch;
            if (raw2) {
                raw2 -= 4;
                owner17->angle.pitch = raw2;
                MATCHING_BARRIER_VOLATILE("memory");
                if ((unsigned int)(raw2 & 255) >= 253) {
                    owner17->angle.pitch = 0;
                }
            }
            if (owner17->position.z >= 0x400) {
                argument4 = (int)&scratch.first;
                MATCHING_KEEP_CLOBBER(argument4, "$16");
                fallingPosition16 = &owner17->position;
                Level26_7CC18CopyVector((Vector3D*)argument4, fallingPosition16);
                temp_v0_6 = Level26_7CC18Field(private18, int*, 8) - 8;
                Level26_7CC18Field(private18, int*, 8) = temp_v0_6;
                if (temp_v0_6 < -0xC0) {
                    Level26_7CC18Field(private18, int*, 8) = -0xC0;
                }
                owner17->position.z += Level26_7CC18Field(private18, int*, 8);
                if (Level26_7CC18QueryWorldSegment((Spyro*)&scratch.first, fallingPosition16) !=
                    0) {
                    Level26_7CC18CopyVector(fallingPosition16, &scratch.first);
                    goto enterState4;
                }
                if (Level26_7CC18QueryDynamicMobyGeometry(fallingPosition16, 0x200, 1, 0, 0x100000,
                                                          owner17) != 0) {
                enterState4:
                    owner17->state = 4;
                    return;
                }
            } else {
                goto runFinal55B18;
            }
            break;
        case 4:
            landingPosition16 = &owner17->position;
            Level26_7CC18QueryDynamicMobyGeometry(landingPosition16, 0x800, 1, 0, 0x100000,
                                                  owner17);
            if (Level26_7CC18QueryWorldSphereWithOptions(landingPosition16, 0x800, 0, 0, 0x100000,
                                                         owner17) != 0) {
                selectedWord16 = &Level26_7CC18_D_80071924;
                MATCHING_KEEP(selectedWord16);
                if (Level26_7CC18GetSurfaceTypeFromFlags(*selectedWord16) == 3) {
                    temp_v1_2 =
                        *(void**)(((*selectedWord16 & 0x3F) * 4) +
                                  Level26_7CC18Field(&Level26_7CC18_D_8006D048, int*, 0x14));
                    Level26_7CC18Field(temp_v1_2, int*, 4) =
                        (int)(Level26_7CC18Field(temp_v1_2, int*, 4) | 0x100000);
                }
            }
            Level26_7CC18CopyVector(&scratch.second, &owner17->position);
            scratch.second.z += 0x200;
            temp_v0_7 = Level26_7CC18QueryWorldHeight(&scratch.second, 0x400);
            scratch.second.z = temp_v0_7;
            if (temp_v0_7 != 0) {
                owner17->position.z = temp_v0_7;
            }
            Level26_7CC18PlayMobySoundEvent(owner17, 1, 0);
            effect = SpawnMoby(0x1AE, owner17);
            if (effect != 0) {
                effect->lowDrawDistance = 0x20;
            }
            goto runFinal55B18;
    }
    return;
runFinal55B18:
    Level26_7CC18DeleteMoby(owner17);
}
#undef Level26_7CC18Field

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
void func_level_26_8007D244(void* input) {
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
                    if (Controller821F8Field(tag, short*, 0) == 3) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007E3D0:340 instructions,41 dispatch entries and padding, original4679.
 * Verified43/46 helper shapes reused only where original agrees. Raw fields;
 * units, helper contracts, cadence and runtime parity unresolved. */
#define D26Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* D26Active __asm__("D_8006E164");
extern int D26Type __asm__("D_8006E160");
extern unsigned char* D26Pool __asm__("D_8006C550");
extern unsigned char D26Player[] __asm__("D_80070328");
extern int D26Contact __asm__("D_8006C770");
int D26SpawnMobyFromValueSelector() __asm__("func_80036A68");
int D26RequestMobyAnimation() __asm__("func_80034F40");
int D26ReadSelectedFrameScalar() __asm__("func_80055E84");
int D26UpdateMobyPathMotion() __asm__("func_80035A80");
int D26UpdateMobyMotionDescriptor() __asm__("func_80035194");
int D26RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int D26MarkMobyCollectionBit() __asm__("func_8003BA00");
int D26EmitMobyVertexParticles() __asm__("func_800369B8");
int D26DeleteMoby() __asm__("func_80055B18");
extern void* (*D26SpawnMoby)(int, void*)__asm__("SpawnMoby");
int D26TurnMobyTowardPlayer() __asm__("func_8003573C");
int D26ApproximatePlanarDistance() __asm__("func_8004F334");
int D26InitializeMobyMotionState() __asm__("func_80038BF8");
int D26PlanarHeadingLookup() __asm__("func_8004E880");
int D26AbsoluteByteAngleDelta() __asm__("func_8004F264");
int D26TestSubdividedSegmentPath() __asm__("func_80013E38");
int D26CopyVector() __asm__("func_8004F178");
extern unsigned char D26Position[] __asm__("D_8006E020");
extern int D26Y __asm__("D_8006E024");
extern unsigned short D26Heading __asm__("D_8006E040");
extern int D26Mode __asm__("D_8006E344");
int D26InterpolateMobyVertex() __asm__("func_80055F14");
int D26ComputeArcVerticalVelocity() __asm__("func_800365E4");
extern int (*D26Fragments)() __asm__("SpawnFragments");
extern int D26ContactZ __asm__("D_80071908");
extern short D26Cos[] __asm__("D_80065920"), D26Sin[] __asm__("D_800658A0");
void func_level_26_8007E3D0(void* input) {
    struct {
        int first[4], second[4], third[2];
    } frame;
    register unsigned char* owner __asm__("$17") = input;
    register unsigned char* tag __asm__("$18");
    register unsigned char* temporary16 __asm__("$16");
    register int distance16 __asm__("$16");
    register unsigned char* player19 __asm__("$19");
    register int value __asm__("$2");
    int other;
    register void* call4 __asm__("$4");
    register int heading4 __asm__("$4");
    register int arg5 __asm__("$5");
    register int arg6 __asm__("$6");
    register int arg7 __asm__("$7");
    MATCHING_KEEP(owner);
    value = ((Moby*)owner)->damageFlags;
    tag = D26Field(owner, unsigned char**, 0);
    if (!value)
        goto dispatch_reload;
    other = owner[72];
    if (other == 8)
        goto dispatch_ready;
    D26InitializeMobyMotionState(input, tag, 2, 8);
    call4 = owner;
    arg5 = 0;
    arg6 = 0;
    arg7 = 0;
    D26Field(tag, unsigned short*, 4) += 50;
    D26SpawnMobyFromValueSelector(call4, arg5, arg6, arg7);
dispatch_reload:
    other = owner[72];
dispatch_ready:
    switch (other) {
        case 0:
            value = D26Field(tag, int*, 24);
            call4 = owner;
            if (value) {
                D26RequestMobyAnimation(call4, 7);
                D26UpdateMobyPathMotion(owner, D26Field(tag, void**, 24), 256, 75, 300, 4, 32, 0);
            } else {
                arg5 = 5;
                MATCHING_KEEP(arg5);
                __asm__("" : "=r"(arg6) : "0"(0));
                D26TurnMobyTowardPlayer(call4, arg5, arg6, 1);
            }
            player19 = D26Player + 80;
            MATCHING_KEEP(player19);
            if ((unsigned int)(D26Field(player19, int*, 0) - 7) < 2)
                goto enter5;
            call4 = frame.first;
            MATCHING_KEEP(call4);
            temporary16 = owner + 12;
            D26CopyVector(call4, temporary16);
            call4 = temporary16;
            temporary16 = player19 - 80;
            arg5 = (int)temporary16;
            frame.first[2] += 512;
            if (D26ApproximatePlanarDistance(call4, (void*)arg5) >= D26Field(tag, int*, 28))
                goto done;
            value = D26Field(D26Player, int*, 576);
            call4 = frame.first;
            if (value)
                goto done;
            arg5 = (int)temporary16;
            MATCHING_KEEP(arg5);
            MATCHING_BARRIER("$2");
            value = D26TestSubdividedSegmentPath(call4, (void*)arg5, 0);
            if (!value)
                goto done;
            goto enter2;
        case 2:
            D26TurnMobyTowardPlayer(owner, 5, 0, 1);
            if (D26Contact) {
                owner[72] = 3;
                D26RequestMobyAnimation(owner, 3);
            }
            break;
        case 3:
            call4 = owner + 12;
            MATCHING_KEEP(call4);
            player19 = D26Player;
            value = D26ApproximatePlanarDistance(call4, player19);
            call4 = owner;
            arg5 = 5;
            arg6 = 0;
            arg7 = 1;
            MATCHING_KEEP4(call4, arg5, arg6, arg7);
            distance16 = value;
            D26TurnMobyTowardPlayer(call4, arg5, arg6, arg7);
            if ((unsigned int)(D26Field(D26Player, int*, 80) - 7) < 2)
                goto enter5;
            if (distance16 >= D26Field(tag, int*, 32))
                goto retreat;
            if (D26Field(D26Player, int*, 576))
                goto retreat;
            if (D26Field(D26Player, int*, 8) - ((Moby*)owner)->position.z >= 4096)
                goto retreat;
            value =
                D26PlanarHeadingLookup(((Moby*)owner)->position.x - D26Field(D26Position, int*, 0),
                                       ((Moby*)owner)->position.y - D26Y, 0);
            heading4 = D26Heading;
            MATCHING_KEEP(heading4);
            arg5 = value;
            heading4 = (heading4 << 16) >> 20;
            value = D26AbsoluteByteAngleDelta(heading4, arg5);
            call4 = owner;
            if (value >= 24)
                goto retreat;
            D26RefreshMobySpatialGridAndBasis(call4, 4);
            call4 = owner;
            arg5 = 0;
            MATCHING_KEEP(arg5);
            temporary16 = (unsigned char*)frame.second;
            D26InterpolateMobyVertex(call4, arg5, temporary16);
            if (D26ComputeArcVerticalVelocity(temporary16, player19, 300, 10, frame.third) >= 200)
                goto done;
            owner[72] = 4;
            D26RequestMobyAnimation(owner, 4);
            break;
        retreat:
            if (distance16 <= D26Field(tag, int*, 28) + 1024)
                goto done;
            value = D26Field(tag, int*, 24);
            call4 = owner;
            if (value)
                goto reset7_ready;
            owner[72] = 0;
            goto reset0_ready;
        case 4:
            if ((unsigned int)(D26Field(D26Player, int*, 80) - 7) < 2)
                owner[73] = 1;
            D26TurnMobyTowardPlayer(owner, 5, 0, 1);
            if (owner[60] == 4) {
                value = D26ReadSelectedFrameScalar(owner);
                call4 = (void*)149;
                if (value >= 15) {
                    if (D26SpawnMoby((int)call4, owner))
                        owner[72] = 40;
                }
            }
        case 40:
            if ((unsigned int)(D26Field(D26Player, int*, 80) - 7) < 2)
                owner[73] = 1;
            call4 = owner;
            if (!D26Contact)
                goto done;
            arg5 = 6;
            D26Field(tag, int*, 36) = 1;
            ((unsigned char*)call4)[72] = 6;
            D26RequestMobyAnimation(call4, arg5);
            break;
        case 6:
            if ((unsigned int)(D26Field(D26Player, int*, 80) - 7) < 2)
                owner[73] = 1;
        case 5:
            D26TurnMobyTowardPlayer(owner, 5, 0, 1);
            if (!D26Contact)
                goto done;
            if (owner[73]) {
                owner[73] = 0;
                D26Field(tag, int*, 36) = 0;
                if (owner[72] == 6) {
                enter5:
                    owner[72] = 5;
                    D26RequestMobyAnimation(owner, 5);
                    goto done;
                }
            }
            if (D26ApproximatePlanarDistance(owner + 12, D26Player) < D26Field(tag, int*, 28)) {
            enter2:
                owner[72] = 2;
                D26RequestMobyAnimation(owner, 2);
                goto done;
            }
            value = D26Field(tag, int*, 24);
            D26Field(tag, int*, 36) = 0;
            if (value) {
                call4 = owner;
            reset7_ready:
                D26RequestMobyAnimation(call4, 7);
                owner[72] = 0;
                goto done;
            }
            owner[72] = 0;
            call4 = owner;
        reset0_ready:
            D26RequestMobyAnimation(call4, 0);
            break;
        case 8:
            value = D26UpdateMobyMotionDescriptor(owner, tag);
            call4 = owner;
            if (value != 256)
                goto done;
            D26RefreshMobySpatialGridAndBasis(call4, 4);
            D26MarkMobyCollectionBit(owner);
            D26EmitMobyVertexParticles(owner, 36);
            D26DeleteMoby(owner);
            break;
    }
done:;
}
#undef D26Field

typedef struct {
    Vector3D velocity;
    Moby* excluded;
} DecodedFallingImpactTag;
extern int DecodedFallingImpactPlayerHeading __asm__("D_80070328 + 0x298");
void DecodedFallingImpactAnimation(Moby*) __asm__("func_80039714");
int DecodedFallingImpactSweep(Vector3D*, Vector3D*) __asm__("func_80018368");
int DecodedFallingImpactPlayerQuery(Vector3D*, int, int) __asm__("func_8001C288");
Moby* DecodedFallingImpactActorQuery(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
int DecodedFallingImpactWorldQuery(Vector3D*, int) __asm__("func_80019194");
Moby* DecodedFallingImpactFragments(int, int, Moby*, int, int, int, int) __asm__("func_800391E8");
void func_level_26_8007E920(Moby* moby) {
    DecodedFallingImpactTag* tag;
    Vector3D previous;
    Moby* target;
    Moby* fragment;
    int state;
    if (moby->animationState.id) {
        DecodedFallingImpactAnimation(moby);
        return;
    }
    state = moby->state;
    tag = moby->mobyTag;
    switch (state) {
        case 0:
            func_8004F178(&previous, &moby->position);
            func_8004F194(&moby->position, &moby->position, &tag->velocity);
            tag->velocity.z -= 10;
            func_8004EDE8(&tag->velocity, 1);
            if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400)
                goto remove;
            if (DecodedFallingImpactSweep(&previous, &moby->position)) {
                func_8004F1C8(&moby->position, &moby->position, &tag->velocity);
                moby->state = 1;
            } else if (DecodedFallingImpactPlayerQuery(&moby->position, 0x64, 7)) {
                DecodedFallingImpactPlayerHeading =
                    func_8004E880(tag->velocity.x, tag->velocity.y, 0);
                moby->state = 1;
            } else {
                target = DecodedFallingImpactActorQuery(&moby->position, 0x12C, 1, 0, 0x800000,
                                                        tag->excluded);
                if (target) {
                    target->unkb = func_8004E880(tag->velocity.x, tag->velocity.y, 0);
                    if (!target->unkb)
                        target->unkb = 1;
                    moby->state = 1;
                } else if (DecodedFallingImpactWorldQuery(&moby->position, 0x7D))
                    moby->state = 1;
            }
            func_80035D38(moby);
            func_8005629C(moby);
            break;
        case 1:
            func_8003BABC(moby, 0, 0);
            DecodedFallingImpactFragments(5, moby->mobyClass, moby, 2, 3, 0x40, 0x100);
            moby->position.z += 0x200;
            fragment =
                DecodedFallingImpactFragments(1, moby->mobyClass, moby, 1, state, 0x40, 0x100);
            if (fragment)
                func_8004F178(&fragment->position, &moby->position);
        remove:
            func_80055B18(moby);
            break;
    }
}

extern Spyro Actor26EB64_D_80070328 __asm__("D_80070328");
extern int Actor26EB64_D_8006C770 __asm__("D_8006C770");
extern short Actor26EB64_D_800658A0[] __asm__("D_800658A0");
extern short Actor26EB64_D_80065920[] __asm__("D_80065920");
void Actor26EB64DeleteMoby(Moby*) __asm__("func_80055B18");
void Actor26EB64RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
void Actor26EB64RefreshMobyPackedQueryField(Moby*) __asm__("func_8005629C");
int Actor26EB64ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
void Actor26EB64SubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void Actor26EB64RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
int Actor26EB64UpdateMobyMotionDescriptor(Moby* input0, void* arg1) __asm__("func_80035194");
int Actor26EB64TurnMobyTowardPlayer(Moby* arg0, int arg1, int arg2,
                                    int arg3) __asm__("func_8003573C");
int Actor26EB64CountTimerDown(void* pTimer, int pTimerType) __asm__("func_800359A4");
int Actor26EB64RandBetween(int low, int high) __asm__("func_8003636C");
void Actor26EB64EmitMobyVertexParticles() __asm__("func_800369B8");
Moby* Actor26EB64SpawnMobyFromValueSelector(Moby* arg0, int arg1, Vector3D* arg2,
                                            Vector3D* arg3) __asm__("func_80036A68");
void Actor26EB64MarkMobyCollectionBit(Moby* moby) __asm__("func_8003BA00");
int Actor26EB64PlayMobySoundEvent(Moby* owner, int index, int selector) __asm__("func_8003BABC");
void Actor26EB64ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
void Actor26EB64SubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void func_level_26_8007EB64(Moby* moby) {
    Vector3D offset;
    Vector3D* position;
    unsigned char* privateBytes;
    int lowerValue;
    int spanValue;
    int sampleX;
    int distance;
    int actorZ;
    int actorZAgain;
    register int randomMagnitude __asm__("$2");
    register int divisor __asm__("$3");
    register int comparison __asm__("$2");
    register unsigned char* timerPointer __asm__("$4");
    register int xTable __asm__("$2");
    register int xPosition __asm__("$3");
    register int argumentOne __asm__("$5");
    register int yTable __asm__("$2");
    register int yPosition __asm__("$3");
    register int byte2C __asm__("$2");
    register int playerZ __asm__("$4");
    register int playerZAgain __asm__("$2");
    register int byte2E __asm__("$3");
    register int byte2D __asm__("$2");
    unsigned char substate;
    unsigned char state;

    privateBytes = moby->mobyTag;
    if ((*(int*)((unsigned char*)(privateBytes) + 0x24)) < 0x1400) {
        func_8004F178(&offset, &moby->position);
        offset.z += 0x400;
        (*(int*)((unsigned char*)(privateBytes) + 0x24)) =
            (int)((*(int*)((unsigned char*)(privateBytes) + 0x24)) +
                  func_8001A358(&offset, 0x2800));
        moby->substate = 1;
    }
    if ((moby->damageFlags != 0) && (moby->state != 7)) {
        (*(int*)((unsigned char*)(privateBytes) + 0x38)) = func_8001A358(&offset, 0x5000);
        Actor26EB64SpawnMobyFromValueSelector(moby, 1, 0, privateBytes + 0x30);
        func_80038BF8(moby, privateBytes + 0x3C, 7, 7);
        (*(unsigned short*)((unsigned char*)(privateBytes) + 0x40)) =
            (unsigned short)((*(unsigned short*)((unsigned char*)(privateBytes) + 0x40)) + 0x46);
        (*(signed char*)((unsigned char*)(privateBytes) + 0x52)) =
            Actor26EB64RandBetween(0x5A, 0x6E);
    }
    xTable = (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2C));
    MATCHING_KEEP(xTable);
    timerPointer = privateBytes + 0x2F;
    MATCHING_KEEP_CLOBBER(timerPointer, "$5");
    xTable = (int)((unsigned short)Actor26EB64_D_800658A0[xTable] << 16);
    xPosition = moby->position.x;
    MATCHING_KEEP2(xTable, xPosition);
    xTable >>= 23;
    xPosition += xTable;
    MATCHING_KEEP(xPosition);
    moby->position.x = xPosition;
    argumentOne = 1;
    yTable =
        (int)((unsigned short)
                  Actor26EB64_D_80065920[(*(unsigned char*)((unsigned char*)(privateBytes) + 0x2D))]
              << 0x10);
    yPosition = moby->position.y;
    __asm__("" : "=r"(yTable), "=r"(yPosition) : "0"(yTable), "1"(yPosition), "r"(argumentOne));
    yTable >>= 23;
    yPosition += yTable;
    MATCHING_KEEP(yPosition);
    moby->position.y = yPosition;
    moby->position.z +=
        (int)((unsigned short)
                  Actor26EB64_D_800658A0[(*(unsigned char*)((unsigned char*)(privateBytes) + 0x2E))]
              << 0x10) >>
        0x17;
    byte2C = (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2C));
    byte2E = (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2E));
    MATCHING_KEEP2(byte2C, byte2E);
    byte2C += 3;
    (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2C)) = byte2C;
    byte2D = (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2D));
    MATCHING_KEEP2(byte2E, byte2D);
    byte2E += 7;
    (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2E)) = byte2E;
    __asm__("" : "=r"(byte2D) : "0"(byte2D), "m"(*(unsigned char*)(privateBytes + 0x2E)));
    byte2D += 5;
    (*(unsigned char*)((unsigned char*)(privateBytes) + 0x2D)) = byte2D;
    if (Actor26EB64CountTimerDown(timerPointer, 1) != 0) {
        (*(signed char*)((unsigned char*)(privateBytes) + 0x2F)) =
            (signed char)((rand() & 0x1F) + 0x20);
        sampleX = (rand() & 0xFF) - 0x80;
        unk_ovlheader_800743E4(privateBytes + 0x18, sampleX, (rand() & 0xFF) - 0x80, privateBytes);
        randomMagnitude = rand();
        divisor = (*(int*)((unsigned char*)(privateBytes) + 0x28));
        MATCHING_KEEP2(randomMagnitude, divisor);
        if (randomMagnitude < 0) {
            randomMagnitude = -randomMagnitude;
        }
        (*(int*)((unsigned char*)(privateBytes) + 0x20)) =
            (int)((*(int*)((unsigned char*)(privateBytes) + 0x24)) + (randomMagnitude % divisor));
        moby->substate = 0x14;
    } else {
        position = &moby->position;
        Actor26EB64SubtractVector(&offset, privateBytes + 0x18, position);
        Actor26EB64ShiftVectorRightTowardZero(&offset, ((unsigned char)moby->substate >> 2) + 5);
        substate = moby->substate;
        if (substate != 0) {
            moby->substate = substate - 1;
        }
        func_8004F194(position, position, &offset);
    }
    Actor26EB64TurnMobyTowardPlayer(moby, 5, 3, 1);
    playerZ = Actor26EB64_D_80070328.position.z;
    MATCHING_KEEP(playerZ);
    lowerValue = (*(int*)((unsigned char*)(privateBytes) + 0x24));
    if (lowerValue < playerZ) {
        spanValue = (*(int*)((unsigned char*)(privateBytes) + 0x28));
        if (playerZ < (lowerValue + (spanValue * 2))) {
            actorZ = moby->position.z;
            comparison = actorZ < playerZ;
            MATCHING_KEEP(comparison);
            if (comparison && (actorZ < (lowerValue + spanValue))) {
                moby->position.z = actorZ + 0xA;
            }
            playerZAgain = Actor26EB64_D_80070328.position.z;
            MATCHING_KEEP(playerZAgain);
            actorZAgain = moby->position.z;
            if ((playerZAgain < actorZAgain) &&
                ((*(int*)((unsigned char*)(privateBytes) + 0x24)) < actorZAgain)) {
                moby->position.z = actorZAgain - 0xA;
            }
        }
    }
    state = moby->state;
    switch (state) {
        case 0:
            if (Actor26EB64ApproximatePlanarDistance(&moby->position,
                                                     &Actor26EB64_D_80070328.position) < 0x1800) {
                moby->state = 3;
                Actor26EB64RequestMobyAnimation(moby, 3);
            } else {
                default:
            }
            goto finishCalls;
        case 3:
            if (Actor26EB64_D_8006C770 != 0) {
                moby->state = 2;
                Actor26EB64RequestMobyAnimation(moby, 2);
            }
            goto finishCalls;
        case 2:
            distance = Actor26EB64ApproximatePlanarDistance(&moby->position,
                                                            &Actor26EB64_D_80070328.position);
            if (distance < 0xC00) {
                moby->state = 5;
                Actor26EB64RequestMobyAnimation(moby, 5);
            } else if (distance >= 0x1C01) {
                moby->state = 4;
                Actor26EB64RequestMobyAnimation(moby, 4);
            }
            goto finishCalls;
        case 4:
        case 5:
            if (Actor26EB64_D_8006C770 != 0) {
                moby->state = 0;
                Actor26EB64RequestMobyAnimation(moby, 0);
            }
            goto finishCalls;
        case 7:
            if (Actor26EB64UpdateMobyMotionDescriptor(moby, privateBytes + 0x3C) == 0x100) {
                Actor26EB64PlayMobySoundEvent(moby, 0, 0);
                Actor26EB64RefreshMobySpatialGridAndBasis(moby, 4);
                Actor26EB64MarkMobyCollectionBit(moby);
                Actor26EB64EmitMobyVertexParticles(moby, 0x24);
                Actor26EB64DeleteMoby(moby);
                return;
            }
        finishCalls:
            func_8001A358(&moby->position, 0x5000);
            Actor26EB64RefreshMobySpatialGridAndBasis(moby, 3);
            Actor26EB64RefreshMobyPackedQueryField(moby);
            return;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_26/moby/func_level_26_8007F030.s SHA256 c6e24542d4097dff791ffb8c3be93583be143f903f03ec83b7a3cc3e1df2d9b4. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level26_7F030Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level26_7F030QueryWorldHeight() __asm__("func_8001A358");
/* extern */
unsigned char Level26_7F030RequestMobyAnimation() __asm__("func_80034F40");
/* extern */
int Level26_7F030UpdateMobyMotionDescriptor() __asm__("func_80035194");
/* extern */
unsigned char Level26_7F030TurnMobyTowardPlayer() __asm__("func_8003573C");
/* extern */
int Level26_7F030CountTimerDown() __asm__("func_800359A4");
/* extern */
unsigned char Level26_7F030EmitMobyVertexParticles() __asm__("func_800369B8");
/* extern */
unsigned char Level26_7F030SpawnMobyFromValueSelector() __asm__("func_80036A68");
/* extern */
unsigned char Level26_7F030InitializeMobyMotionState() __asm__("func_80038BF8");
/* extern */
unsigned char Level26_7F030MarkMobyCollectionBit() __asm__("func_8003BA00");
/* extern */
int Level26_7F030PlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
int Level26_7F030MeasureVectorLength() __asm__("func_8004EDE8");
/* extern */
unsigned char Level26_7F030ScaleVectorRatioQ15() __asm__("func_8004F08C");
/* extern */
unsigned char Level26_7F030ShiftVectorRightTowardZero() __asm__("func_8004F110");
/* extern */
unsigned char Level26_7F030CopyVector() __asm__("func_8004F178");
/* extern */
unsigned char Level26_7F030AddVector() __asm__("func_8004F194");
/* extern */
unsigned char Level26_7F030SubtractVector() __asm__("func_8004F1C8");
/* extern */
int Level26_7F030ApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned char Level26_7F030DeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned char Level26_7F030RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int Level26_7F030ReadSelectedFrameScalar() __asm__("func_80055E84");
/* extern */
unsigned char Level26_7F030InterpolateMobyVertex() __asm__("func_80055F14");
/* extern */
extern unsigned char Level26_7F030_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level26_7F030_D_80065920 __asm__("D_80065920");
extern int Level26_7F030_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level26_7F030_D_80070328 __asm__("D_80070328");
extern void* (*Level26_7F030_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level26_7F030_unk_ovlheader_8007440C)() __asm__("unk_ovlheader_8007440C");

void func_level_26_8007F030(void* ownerRecord) {
    /* Original scratch slots retain SP+0x10/+0x18/+0x20/+0x30/+0x40/+0x48.
     * The4E880 result stays a full signed word through range comparisons;
     * the65920/658A0 tables retain original signed LH loads. The shared
     * active block is original8007F220, after the case0 condition, and the
     * reset block retains its separate incoming store/call edges. Empty
     * constraints preserve raw register producers without adding opcodes.
     * Helper semantics, physical units/fixed point and cadence remain open. */
    struct {
        unsigned char sp10;
        unsigned char pad11[7];
        int sp18;
        unsigned char pad1C[4];
        unsigned char sp20;
        unsigned char pad21[15];
        unsigned char sp30;
        unsigned char pad31[15];
        unsigned char sp40;
        unsigned char pad41[7];
        int sp48;
        unsigned char pad4C[4];
    } scratch;

    unsigned char* ownerPayload16;
    unsigned char* ownerPayload16b;
    unsigned char* ownerPayload16c;
    int distanceWord18;
    register int constant2 __asm__("$2");
    int temp_v0;
    register int temp_v0_4 __asm__("$3");
    register int return2 __asm__("$2");
    register int difference2 __asm__("$2");
    register int scratch4 __asm__("$4");
    int temp_v0_5;
    int var_v0_2;
    int helperWord16;
    int helperWord2;
    unsigned int var_v0;
    register int childSelector5 __asm__("$5");
    register void* owner4 __asm__("$4");
    unsigned char temp_v1;
    register int selector5 __asm__("$5");
    void* childPayload16;
    void* childPrivate20;
    void* privateRecord22;
    void* childRecord21;

    privateRecord22 = Level26_7F030Field(ownerRecord, void**, 0);
    if ((Level26_7F030Field(ownerRecord, int*, 0x18) & 0x10000000) &&
        (temp_v1 = Level26_7F030Field(ownerRecord, unsigned char*, 0x48), (temp_v1 != 0xD))) {
        if (temp_v1 != 0x2B) {
            Level26_7F030RequestMobyAnimation(ownerRecord, 9);
            Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 0x2BU;
        }
    }
    temp_v0 = Level26_7F030Field(ownerRecord, int*, 0x18) & 0xEFFFFFFF;
    Level26_7F030Field(ownerRecord, int*, 0x18) = temp_v0;
    if (temp_v0 != 0) {
        if (Level26_7F030Field(ownerRecord, unsigned char*, 0x48) != 0xD) {
            Level26_7F030InitializeMobyMotionState(ownerRecord, privateRecord22, 4, 0xD);
            Level26_7F030Field(privateRecord22, unsigned short*, 4) =
                (unsigned short)(Level26_7F030Field(privateRecord22, unsigned short*, 4) + 0x5A);
            Level26_7F030SpawnMobyFromValueSelector(ownerRecord, 0, 0, 0);
        }
    }
    Level26_7F030Field(ownerRecord, int*, 0x18) = 0;
    switch (Level26_7F030Field(ownerRecord, unsigned char*, 0x48)) {
        case 43:
            ownerPayload16 = ownerRecord + 0xC;
            if (Level26_7F030_D_8006C770 != 0) {
                if ((Level26_7F030ApproximatePlanarDistance(ownerPayload16,
                                                            &Level26_7F030_D_80070328) < 0x2800) &&
                    (Level26_7F030Field(&Level26_7F030_D_80070328, int*, 0x240) == 0)) {
                    if (Level26_7F030PlanarHeadingLookup(
                            Level26_7F030ApproximatePlanarDistance(ownerPayload16,
                                                                   &Level26_7F030_D_80070328),
                            Level26_7F030Field(&Level26_7F030_D_80070328, int*, 8) -
                                Level26_7F030Field(ownerRecord, int*, 0x14),
                            0) < 0x2C)
                        goto sharedActiveCall;
                    Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 0;
                    goto sharedResetCall;
                }
                goto storeResetState;
            }
        default:
            return;
        case 0:
            Level26_7F030TurnMobyTowardPlayer(ownerRecord, 5, 0, 1);
            ownerPayload16b = ownerRecord + 0xC;
            if ((Level26_7F030ApproximatePlanarDistance(ownerPayload16b,
                                                        &Level26_7F030_D_80070328) < 0x2800) &&
                (Level26_7F030Field(&Level26_7F030_D_80070328, int*, 0x240) == 0) &&
                (Level26_7F030PlanarHeadingLookup(
                     Level26_7F030ApproximatePlanarDistance(ownerPayload16b,
                                                            &Level26_7F030_D_80070328),
                     Level26_7F030Field(&Level26_7F030_D_80070328, int*, 8) -
                         Level26_7F030Field(ownerRecord, int*, 0x14),
                     0) < 0x2C)) {
            sharedActiveCall:
                Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 1;
                Level26_7F030RequestMobyAnimation(ownerRecord, 1);
                return;
            }
            break;
        case 1:
            Level26_7F030TurnMobyTowardPlayer(ownerRecord, 5, 0, 1);
            if (Level26_7F030_D_8006C770 != 0) {
                Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 2U;
                Level26_7F030RequestMobyAnimation(ownerRecord, 2U);
                return;
            }
            break;
        case 9:
            Level26_7F030TurnMobyTowardPlayer(ownerRecord, 5, 0, 1);
            if (Level26_7F030_D_8006C770 != 0) {
            storeResetState:
                Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 0U;
            sharedResetCall:
                Level26_7F030RequestMobyAnimation(ownerRecord, 0U);
                return;
            }
            break;
        case 2:
        case 3:
        case 4:
            ownerPayload16c = ownerRecord + 0xC;
            distanceWord18 =
                Level26_7F030ApproximatePlanarDistance(ownerPayload16c, &Level26_7F030_D_80070328);
            Level26_7F030TurnMobyTowardPlayer(ownerRecord, 5, 0, 1);
            Level26_7F030CopyVector(&scratch.sp10, ownerPayload16c);
            scratch.sp18 += 0x200;
            helperWord16 = Level26_7F030PlanarHeadingLookup(
                Level26_7F030ApproximatePlanarDistance(&scratch.sp10, &Level26_7F030_D_80070328),
                Level26_7F030Field(&Level26_7F030_D_80070328, int*, 8) - scratch.sp18, 0);
            if ((unsigned int)(helperWord16 - 0x10) >= 0xB1U) {
                owner4 = ownerRecord;
                MATCHING_KEEP_CLOBBER(owner4, "$5");
                selector5 = 2;
            } else if (helperWord16 < 0x20) {
                owner4 = ownerRecord;
                MATCHING_KEEP_CLOBBER(owner4, "$5");
                selector5 = 3;
            } else {
                owner4 = ownerRecord;
                MATCHING_KEEP_CLOBBER(owner4, "$5");
                selector5 = 4;
            }
            Level26_7F030RequestMobyAnimation(owner4, selector5);
            if (Level26_7F030CountTimerDown(privateRecord22 + 0x18, 4) != 0) {
                if (distanceWord18 < 0x2000) {
                    if ((unsigned int)(Level26_7F030Field(&Level26_7F030_D_80070328, int*, 0x50) -
                                       7) >= 2U) {
                        if (Level26_7F030Field(&Level26_7F030_D_80070328, int*, 0x240) == 0) {
                            if (Level26_7F030_unk_ovlheader_8007440C(ownerRecord) != 0) {
                                if ((unsigned int)(helperWord16 - 0x10) >= 0xB1U) {
                                    Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 5U;
                                    Level26_7F030RequestMobyAnimation(ownerRecord, 5U);
                                    return;
                                }
                                if (helperWord16 < 0x20) {
                                    Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 6U;
                                    Level26_7F030RequestMobyAnimation(ownerRecord, 6U);
                                    return;
                                }
                                Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 7U;
                                Level26_7F030RequestMobyAnimation(ownerRecord, 7U);
                                return;
                            }
                            goto recomputeRange;
                        }
                    }
                }
                goto testRange;
            }
        recomputeRange:
        testRange:
            if (((unsigned int)(helperWord16 - 53) < 139U) || (distanceWord18 >= 0x2C01)) {
                Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 9U;
                Level26_7F030RequestMobyAnimation(ownerRecord, 9U);
                return;
            }
            break;
        case 5:
        case 6:
        case 7:
            Level26_7F030TurnMobyTowardPlayer(ownerRecord, 5, 0, 1);
            if (((unsigned int)(Level26_7F030Field(ownerRecord, unsigned char*, 0x3C) - 5) < 3U) &&
                (Level26_7F030ReadSelectedFrameScalar(ownerRecord) >= 0xB)) {
                if ((unsigned int)(Level26_7F030Field(&Level26_7F030_D_80070328, int*, 0x50) - 7) >=
                    2U) {
                    if (Level26_7F030_unk_ovlheader_8007440C(ownerRecord) != 0) {
                        childRecord21 = Level26_7F030_SpawnMoby(0xA4, ownerRecord);
                        if (childRecord21 != 0) {
                            childPrivate20 = Level26_7F030Field(childRecord21, void**, 0);
                            Level26_7F030RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                            Level26_7F030InterpolateMobyVertex(ownerRecord, 0, &scratch.sp20);
                            Level26_7F030InterpolateMobyVertex(ownerRecord, 1, &scratch.sp30);
                            childPayload16 = childRecord21 + 0xC;
                            Level26_7F030AddVector(childPayload16, &scratch.sp20, &scratch.sp30);
                            Level26_7F030ShiftVectorRightTowardZero(childPayload16, 1);
                            Level26_7F030Field(childRecord21, unsigned char*, 0x46) =
                                (unsigned char)Level26_7F030Field(ownerRecord, unsigned char*,
                                                                  0x46);
                            Level26_7F030CopyVector(&scratch.sp40,
                                                    (&Level26_7F030_D_80070328 + 0x50) - 0x50);
                            return2 = Level26_7F030QueryWorldHeight(&scratch.sp40, 4096);
                            scratch4 = scratch.sp48;
                            __asm__("" : "=r"(scratch4) : "0"(scratch4), "r"(return2) : "$3");
                            temp_v0_4 = return2;
                            difference2 = scratch4 - temp_v0_4;
                            if (difference2 < 0)
                                goto reverseDifference;
                            if (difference2 < 1800)
                                goto raiseScratch;
                            goto finalizeScratch;
                        reverseDifference:
                            difference2 = temp_v0_4 - scratch4;
                            if (difference2 >= 1800)
                                goto finalizeScratch;
                        raiseScratch:
                            difference2 = temp_v0_4 + 300;
                            scratch.sp48 = difference2;
                        finalizeScratch:
                            Level26_7F030SubtractVector(childPrivate20, &scratch.sp40,
                                                        childRecord21 + 0xC);
                            Level26_7F030ScaleVectorRatioQ15(
                                childPrivate20, Level26_7F030MeasureVectorLength(childPrivate20, 1),
                                0x12C);
                            helperWord2 = Level26_7F030PlanarHeadingLookup(
                                Level26_7F030MeasureVectorLength(childPrivate20, 0),
                                Level26_7F030Field(childPrivate20, int*, 8), 0);
                            Level26_7F030Field(childRecord21, signed char*, 0x45) = helperWord2;
                            if ((unsigned int)((helperWord2 - 0x2D) & 0xFF) < 0x53U) {
                                Level26_7F030Field(childPrivate20, int*, 0) =
                                    (int)((int)(((int)(*(short*)(&Level26_7F030_D_80065920 +
                                                                 (Level26_7F030PlanarHeadingLookup(
                                                                      Level26_7F030Field(
                                                                          &Level26_7F030_D_80070328,
                                                                          int*, 0) -
                                                                          Level26_7F030Field(
                                                                              ownerRecord, int*,
                                                                              0xC),
                                                                      Level26_7F030Field(
                                                                          &Level26_7F030_D_80070328,
                                                                          int*, 4) -
                                                                          Level26_7F030Field(
                                                                              ownerRecord, int*,
                                                                              0x10),
                                                                      0) *
                                                                  2)) *
                                                       0x4B) >>
                                                 0xA) *
                                                Level26_7F030Field(&Level26_7F030_D_80065920,
                                                                   short*, 0x58)) >>
                                          0xC);
                                Level26_7F030Field(childPrivate20, int*, 4) =
                                    (int)((int)(((int)(*(short*)(&Level26_7F030_D_800658A0 +
                                                                 (Level26_7F030PlanarHeadingLookup(
                                                                      Level26_7F030Field(
                                                                          &Level26_7F030_D_80070328,
                                                                          int*, 0) -
                                                                          Level26_7F030Field(
                                                                              ownerRecord, int*,
                                                                              0xC),
                                                                      Level26_7F030Field(
                                                                          &Level26_7F030_D_80070328,
                                                                          int*, 4) -
                                                                          Level26_7F030Field(
                                                                              ownerRecord, int*,
                                                                              0x10),
                                                                      0) *
                                                                  2)) *
                                                       0x4B) >>
                                                 0xA) *
                                                Level26_7F030Field(&Level26_7F030_D_80065920,
                                                                   short*, 0x58)) >>
                                          0xC);
                                Level26_7F030Field(childPrivate20, int*, 8) =
                                    (int)((int)(Level26_7F030Field(&Level26_7F030_D_800658A0,
                                                                   short*, 0x58) *
                                                0x4B) >>
                                          0xA);
                                Level26_7F030Field(childRecord21, signed char*, 0x45) = 0x2C;
                            }
                            Level26_7F030RefreshMobySpatialGridAndBasis(childRecord21, 4);
                            Level26_7F030Field(childPrivate20, short*, 0xC) = 0x78;
                            Level26_7F030Field(childPrivate20, short*, 0x12) = 0xC;
                            Level26_7F030Field(childPrivate20, signed char*, 0x11) = 0x10;
                        }
                    }
                }
                Level26_7F030Field(ownerRecord, unsigned char*, 0x48) = 0x28U;
            }
            /* fallthrough */
        case 40:
            if (Level26_7F030_D_8006C770 != 0) {
                owner4 = ownerRecord;
                MATCHING_KEEP_CLOBBER(owner4, "$5");
                childSelector5 = Level26_7F030Field(owner4, unsigned char*, 0x3C);
                MATCHING_KEEP_CLOBBER(childSelector5, "$2");
                constant2 = 60;
                Level26_7F030Field(privateRecord22, int*, 0x18) = constant2;
                MATCHING_KEEP_VOLATILE_CLOBBER(childSelector5, "memory");
                childSelector5 -= 3;
                Level26_7F030Field(owner4, unsigned char*, 0x48) = childSelector5;
                Level26_7F030RequestMobyAnimation(owner4, childSelector5);
                return;
            }
            break;
        case 13:
            if (Level26_7F030UpdateMobyMotionDescriptor(ownerRecord, privateRecord22) == 0x100) {
                Level26_7F030RefreshMobySpatialGridAndBasis(ownerRecord, 4);
                Level26_7F030MarkMobyCollectionBit(ownerRecord);
                Level26_7F030EmitMobyVertexParticles(ownerRecord, 0x24);
                Level26_7F030DeleteMoby(ownerRecord);
            }
            break;
    }
}
#undef Level26_7F030Field

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Actor26F7D4ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Actor26F7D4RefreshMobyPackedQueryField() __asm__("func_8005629C");
#define Actor26F7D4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor26F7D4QueryWorldSegment() __asm__("func_80018368");
int Actor26F7D4QueryWorldSphere() __asm__("func_80019194");
int Actor26F7D4QueryDynamicMobyGeometry() __asm__("func_8001BA30");
int Actor26F7D4TestPlayerSphereOverlap() __asm__("func_8001C288");
int Actor26F7D4CountTimerDown() __asm__("func_800359A4");
int Actor26F7D4EmitMobyVertexParticles() __asm__("func_800369B8");
int Actor26F7D4PlanarHeadingLookup() __asm__("func_8004E880");
int Actor26F7D4ComputeVectorPlaneResponse() __asm__("func_8004EF74");
int Actor26F7D4CopyVector() __asm__("func_8004F178");
int Actor26F7D4AddVector() __asm__("func_8004F194");
int Actor26F7D4SubtractVector() __asm__("func_8004F1C8");
int Actor26F7D4DeleteMoby() __asm__("func_80055B18");
int Actor26F7D4RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Actor26F7D4InterpolateMobyVertex() __asm__("func_80055F14");
extern unsigned char Actor26F7D4D_80070328[] __asm__("D_80070328");
extern unsigned char Actor26F7D4D_80071918[] __asm__("D_80071918");
void func_level_26_8007F7D4(void* input) {
    register unsigned char* owner __asm__("$18") = input;
    int sp18[4];
    int sp28[4];
    int sp38[4];
    int sp48[4];
    short firstHandle;
    short actorHandle;
    short lastHandle;
    register int firstDelta __asm__("$2");
    register int actorDelta __asm__("$2");
    register int lastDelta __asm__("$2");
    int secondVectorResult;
    register int hitActorAddress __asm__("$6");
    register int secondVectorSelected __asm__("$20");
    register int firstMagnitude __asm__("$2");
    register int actorMagnitude __asm__("$2");
    register int lastMagnitude __asm__("$2");
    register int byteDelta __asm__("$6");
    unsigned char stateByte;
    register void* scratchPointer __asm__("$16");
    register void* state __asm__("$17");
    register void* stateField0C __asm__("$4");
    register void* secondVector __asm__("$19");
    register void* call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int call7 __asm__("$7");
    register int work2 __asm__("$2");
    register int call6 __asm__("$6");

    MATCHING_KEEP(owner);
    stateByte = ((Moby*)owner)->state;
    state = ((Moby*)owner)->mobyTag;
    switch (stateByte) {
        case 1:
            goto delete;
        case 0:
            goto checkBounds;
        case 2:
            Actor26F7D4Field(state, int*, 8) -= 12;
            ((Moby*)owner)->angle.pitch += Actor26F7D4Field(state, unsigned char*, 0x12);
            Actor26F7D4RefreshMobySpatialGridAndBasis(owner, 4);
        checkBounds:
            if (((Moby*)owner)->position.x < 0x400 || ((Moby*)owner)->position.y < 0x400 ||
                ((Moby*)owner)->position.z < 0x400)
                goto delete;
            call4 = &sp18;
            MATCHING_KEEP(call4);
            scratchPointer = owner + 0xC;
            Actor26F7D4CopyVector(call4, scratchPointer);
            Actor26F7D4AddVector(scratchPointer, scratchPointer, state);
        initializeVectors:
            MATCHING_BARRIER_VOLATILE("$4");
            call4 = owner;
            call5 = 0;
            MATCHING_KEEP2(call4, call5);
            scratchPointer = &sp28;
            Actor26F7D4InterpolateMobyVertex(call4, call5, scratchPointer);
            call4 = owner;
            call5 = 1;
            MATCHING_KEEP2(call4, call5);
            secondVector = &sp38;
            Actor26F7D4InterpolateMobyVertex(call4, call5, secondVector);
            secondVectorSelected = 0;
            {
                register int check __asm__("$4");
                if (((Moby*)owner)->state == 2) {
                    MATCHING_KEEP(secondVectorSelected);
                    check = Actor26F7D4TestPlayerSphereOverlap(scratchPointer, 100, 0);
                    if (check != 0)
                        goto firstContact;
                    check = Actor26F7D4TestPlayerSphereOverlap(secondVector, 100, 0);
                    secondVectorSelected = check != 0;
                } else {
                    MATCHING_KEEP(secondVectorSelected);
                    check = Actor26F7D4TestPlayerSphereOverlap(scratchPointer, 100, 7);
                }
                if (check != 0) {
                firstContact:
                    ((Moby*)owner)->substate++;
                    if (secondVectorSelected != 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        firstDelta = -0xC;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        firstDelta = 0xC;
                    }
                    Actor26F7D4Field(state, short*, 0x12) = firstDelta;
                    MATCHING_BARRIER_GNU_VOLATILE("memory");
                    Actor26F7D4Field(&Actor26F7D4D_80070328, int*, 0x298) =
                        Actor26F7D4PlanarHeadingLookup(Actor26F7D4Field(state, int*, 0),
                                                       Actor26F7D4Field(state, int*, 4), 0);
                    scratchPointer = &sp48;
                    Actor26F7D4SubtractVector(scratchPointer, owner + 0xC,
                                              ((unsigned char*)&Actor26F7D4D_80070328 + 0x298) -
                                                  0x298);
                    if (Actor26F7D4ComputeVectorPlaneResponse(state, scratchPointer, state) != 0) {
                        Actor26F7D4Field(state, int*, 0) =
                            (int)((int)(Actor26F7D4Field(state, int*, 0) * 6) >> 3);
                        Actor26F7D4Field(state, int*, 4) =
                            (int)((int)(Actor26F7D4Field(state, int*, 4) * 6) >> 3);
                        Actor26F7D4Field(state, int*, 8) =
                            (int)((int)(Actor26F7D4Field(state, int*, 8) * 6) >> 3);
                    }
                    ((Moby*)owner)->state = 2;
                }
            }
            if (Actor26F7D4CountTimerDown(state + 0x11, 1)) {
                hitActorAddress =
                    Actor26F7D4QueryDynamicMobyGeometry(&sp28, 0x96, 1, 0, 0x10000000, owner);
                if (((Moby*)owner)->state == 2 && hitActorAddress == 0) {
                    MATCHING_KEEP(hitActorAddress);
                    call4 = &sp38;
                    call5 = 150;
                    call6 = 1;
                    MATCHING_KEEP3(call4, call5, call6);
                    call7 = 0;
                    hitActorAddress = Actor26F7D4QueryDynamicMobyGeometry(call4, call5, call6,
                                                                          call7, 0x10000000, owner);
                    stateField0C = state + 0xC;
                    if (hitActorAddress != 0) {
                        secondVectorSelected = 1;
                        goto block_24;
                    }
                }
                {
                block_24:
                    if (!hitActorAddress)
                        goto block_35;
                    ((Moby*)owner)->substate++;
                    if (secondVectorSelected != 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        actorDelta = -0xC;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        actorDelta = 0xC;
                    }
                    Actor26F7D4Field(state, short*, 0x12) = actorDelta;
                    scratchPointer = &sp48;
                    Actor26F7D4SubtractVector(scratchPointer, owner + 0xC, hitActorAddress + 0xC);
                    if (Actor26F7D4ComputeVectorPlaneResponse(state, scratchPointer, state) != 0) {
                        Actor26F7D4Field(state, int*, 0) =
                            (int)((int)(Actor26F7D4Field(state, int*, 0) * 6) >> 3);
                        Actor26F7D4Field(state, int*, 4) =
                            (int)((int)(Actor26F7D4Field(state, int*, 4) * 6) >> 3);
                        Actor26F7D4Field(state, int*, 8) =
                            (int)((int)(Actor26F7D4Field(state, int*, 8) * 6) >> 3);
                    }
                    ((Moby*)owner)->state = 2;
                }
            }
        block_35:
            stateField0C = state + 0xC;
        block_36:
            if (Actor26F7D4CountTimerDown(stateField0C, 2) != 0)
                goto remove;
            if (((Moby*)owner)->substate < 11)
                goto block_40;
        remove:
            Actor26F7D4EmitMobyVertexParticles(owner, 24);
        delete:
            Actor26F7D4DeleteMoby(owner);
            goto finish;
        block_40:
            {
                {
                    register int check __asm__("$4") = Actor26F7D4QueryWorldSphere(&sp28, 150);
                    if (((Moby*)owner)->state == 2 && !check) {
                        check = Actor26F7D4QueryWorldSphere(&sp38, 150);
                        if (check)
                            secondVectorSelected = 1;
                    }
                    if (!check && !Actor26F7D4QueryWorldSegment(&sp18, owner + 12))
                        goto finishUpdate;
                    ((Moby*)owner)->substate++;
                    if (secondVectorSelected != 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        lastDelta = -0xC;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        lastDelta = 0xC;
                    }
                    Actor26F7D4Field(state, short*, 0x12) = lastDelta;
                    if (Actor26F7D4ComputeVectorPlaneResponse(state, &Actor26F7D4D_80071918,
                                                              state) != 0) {
                        Actor26F7D4Field(state, int*, 0) =
                            (int)((int)(Actor26F7D4Field(state, int*, 0) * 6) >> 3);
                        Actor26F7D4Field(state, int*, 4) =
                            (int)((int)(Actor26F7D4Field(state, int*, 4) * 6) >> 3);
                        Actor26F7D4Field(state, int*, 8) =
                            (int)(((int)(Actor26F7D4Field(state, int*, 8) * 6) >> 3) + 0x14);
                    }
                    ((Moby*)owner)->state = 2;
                }
            finishUpdate:
                Actor26F7D4ProbeGroundFromRaisedMoby(owner);
                Actor26F7D4RefreshMobyPackedQueryField(owner);
            }
            break;
    }
finish:;
}
#undef Actor26F7D4Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007FC74.
 * AI generated; not human reviewed. All1831 native instructions,44
 * selectors,two zero padding words,actual targets,addends and full retail
 * hashes remain mandatory. Compiler/filter/flags are unchanged.
 * Original frameF0 saves S0..S6/RA at SPD0..EC. Outgoing homes are
 * SP10..1C. Eleven complete vector regions occupy SP20..C8; reserve
 * SP2C/3C/4C/5C/6C/7C/8C/9C/AC/BC/CC is never read for content.
 * Original EXE4F178 loads all3 source words before all3 destination
 * writes;4F194 loads both complete vectors before all3 result stores.
 * Every original local read follows explicit component writes or these
 * proved full outputs. There is no invented frame initializer.
 * OwnerS2 is the parameter;privateS3 is owner+0. S4/S5 are initialized
 * linked actor/private on the nonnegative selector path. Other S4/S5
 * position/frame roles occur only on the disjoint controller path.
 * S0 position pointers die only after F178 consumes them. A complete
 * 35A80 V0 result becomes S0 in that call delay,not before its pointer
 * input. Later frame restores recompute owner+12. The decoder's false
 * pointer/result overlap is not inherited. S1 has similarly distinct
 * initialized position and complete-return phases. No incoming saved
 * value,fixed FP/SP,live fixed alias or manual outgoing home is used.
 * Shared source labels own their actual original producers. Reorg may
 * steal those initialized producers into original branch/call delays;
 * duplicated address producers and invented branch values are absent.
 * Every metadata template is empty. Inputs are complete initialized
 * scalar/address values or freshly written fields; phase GP clobbers
 * occur only after the old value dies,before a fresh original producer.
 * LH/LBU/SB/SH widths,byte angle indexing,signed shifts,original divide
 * traps,and unsigned32 CRC shifts remain explicit. Trig signed16*39
 * stays in int32 before>>6. There are no partial HI/LO inputs or scales
 * inferred from visuals. No local product union or layout escapes.
 * Typed helper views record existing native arity/return and address
 * words. Pointer formals use void* ABI views,not invented structures.
 * E880's original extra A3 caller staging is retained;its known formal
 * contract has3 scalar arguments and returns int. External helper
 * semantics,allocation/writer closure,index ranges,coordinate domains,
 * cadence beyond invocation,Rev1 correspondence and synchronized runtime
 * captures remain separate unresolved evidence. This C is accepted for
 * original-compiler binary identity;human review remains outstanding.
 */
extern unsigned char Level26_7FC74Global6 __asm__("D_80070300+6");
extern unsigned char Level26_7FC74Global15 __asm__("D_80070300+15");
#define Level26_7FC74Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level26_7FC74CompleteValue(v) __asm__("" : "=r"(v) : "0"(v))
void Level26_7FC74PrepareCameraMode9Vectors(void*, void*) __asm__("func_80013AE4");
void Level26_7FC74SetCameraMode11Target(void*, int, void*, int) __asm__("func_80013D44");
int Level26_7FC74TestSubdividedSegmentPath(void*, void*, int) __asm__("func_80013E38");
int Level26_7FC74TestPlayerSphereOverlap(void*, int, int) __asm__("func_8001C288");
int Level26_7FC74ConfigureHudEntry(int, int, void*, void*, void*, void*,
                                   int) __asm__("func_8002803C");
void Level26_7FC74RequestMobyAnimation(void*, int) __asm__("func_80034F40");
void Level26_7FC74SetMobyAnimation(void*, int) __asm__("func_80034F80");
int Level26_7FC74TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Level26_7FC74CountTimerDown(void*, int) __asm__("func_800359A4");
int Level26_7FC74UpdateMobyPathMotion(void*, void*, int, int, int, int, int,
                                      int) __asm__("func_80035A80");
int Level26_7FC74ProbeGroundFromRaisedMoby(void*) __asm__("func_80035D38");
int Level26_7FC74ResolveMobyYawStep(void*, int, int, int, int) __asm__("func_80035DDC");
int Level26_7FC74TestPaddedRotatedBox(void*, void*, int, int) __asm__("func_80036220");
int Level26_7FC74RandBetween(int, int) __asm__("func_8003636C");
int Level26_7FC74UpdateMobyInteractionGate(void*, int) __asm__("func_80037BBC");
void Level26_7FC74RegisterTrackedValue(void*, int, void*) __asm__("func_8003B7B4");
int Level26_7FC74PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Level26_7FC74SoundHandleMatchesOwnerInStates1Or2(void*, int) __asm__("func_8003BFC0");
int Level26_7FC74PlanarHeadingLookup() __asm__("func_8004E880");
void Level26_7FC74ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
void Level26_7FC74CopyVector(void*, void*) __asm__("func_8004F178");
void Level26_7FC74AddVector(void*, void*, void*) __asm__("func_8004F194");
int Level26_7FC74AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level26_7FC74ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
void Level26_7FC74StartDialogue(void*, int, int) __asm__("func_800512E4");
void Level26_7FC74RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
extern int Level26_7FC74_D_800658A0 __asm__("D_800658A0");
extern int Level26_7FC74_D_80065920 __asm__("D_80065920");
extern int Level26_7FC74_D_8006C550 __asm__("D_8006C550");
extern int Level26_7FC74_D_8006C58C __asm__("D_8006C58C");
extern int Level26_7FC74_D_8006C59C __asm__("D_8006C59C");
extern int Level26_7FC74_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level26_7FC74_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level26_7FC74_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level26_7FC74_D_8006E048 __asm__("D_8006E048");
extern int Level26_7FC74_D_8006E160 __asm__("D_8006E160");
extern int Level26_7FC74_D_8006E344 __asm__("D_8006E344");
extern int Level26_7FC74_D_80070300 __asm__("D_80070300");
extern int Level26_7FC74_D_80070328 __asm__("D_80070328");
extern int Level26_7FC74_D_level_26_8008ADD8 __asm__("D_level_26_8008ADD8");
extern int Level26_7FC74_func_80027A60 __asm__("func_80027A60");
extern int Level26_7FC74_func_80027EE4 __asm__("func_80027EE4");
extern int Level26_7FC74_func_80029AA0 __asm__("func_80029AA0");
extern int Level26_7FC74_func_level_26_80074DC8 __asm__("func_level_26_80074DC8");
extern int Level26_7FC74_main_TEXT_END __asm__("main_TEXT_END");
extern int Level26_7FC74_main_TEXT_START __asm__("main_TEXT_START");
void func_level_26_8007FC74(void* ownerParameter) {
    register int positionFlagsOrAddress16 __asm__("$16"), positionOrFlags17 __asm__("$17"),
        owner18 __asm__("$18"), private19 __asm__("$19"), linkedOwnerOrPosition20 __asm__("$20"),
        linkedPrivate21 __asm__("$21"), controllerEnabled22 __asm__("$22");
    register int resultOrField2 __asm__("$2"), fieldOrArithmetic3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C,
            sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4,
            spC8, spCC;
    } originalFrame;
    int temp_v1_18;
    int temp_v1_4;
    int temp_a0_4;
    int temp_a0_5;
    int temp_v0_2;
    int temp_v1_34;
    int temp_v1_6;
    int var_a0_2;
    int var_v0_15;
    int var_v0_3;
    int var_v0_5;
    int var_v0_6;
    int temp_v1_22;
    int temp_v1_36;
    int temp_v1_42;
    int var_v0_14;
    int temp_a1;
    int temp_a1_3;
    int temp_a1_4;
    int temp_v0;
    int temp_v0_4;
    int temp_v0_6;
    int temp_v0_8;
    int temp_v1_11;
    int temp_v1_16;
    int temp_v1_17;
    int temp_v1_33;
    int temp_v1_35;
    int temp_v1_7;
    owner18 = (int)ownerParameter;
    Level26_7FC74CompleteValue(owner18);
    private19 = Level26_7FC74Field(owner18, int*, 0);
    if (Level26_7FC74SoundHandleMatchesOwnerInStates1Or2(
            (void*)((int)ownerParameter), Level26_7FC74Field(private19, short*, 0xEC)) == 0) {
        Level26_7FC74Field(private19, short*, 0xEC) =
            Level26_7FC74PlayMobySoundEvent((void*)(owner18), 0, 4);
    }
    resultOrField2 = Level26_7FC74Field(private19, volatile int*, 244);
    fieldOrArithmetic3 = (int)&Level26_7FC74_func_level_26_80074DC8;
    resultOrField2 = (unsigned int)resultOrField2 < (unsigned int)fieldOrArithmetic3;
    if (!resultOrField2) {
        MATCHING_OBSERVE_VOLATILE_CLOBBER(private19, "$2");
        argumentOrField5 = 0;
        Level26_7FC74CompleteValue(argumentOrField5);
        argumentOrField6 = (int)&Level26_7FC74_D_level_26_8008ADD8;
        Level26_7FC74CompleteValue(argumentOrField6);
    actor1831OverlayCRC:
        /* Incremental overlay-byte CRC phase; original unsigned 32-bit shifts and cursor writes. */
        fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 244);
        resultOrField2 = (unsigned int)fieldOrArithmetic3 < (unsigned int)argumentOrField6;
        if (resultOrField2) {
            argumentOrField4 = 0;
            resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, unsigned char*, 0);
            fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 240);
            resultOrField2 <<= 8;
            fieldOrArithmetic3 ^= resultOrField2;
            Level26_7FC74Field(private19, volatile int*, 240) = fieldOrArithmetic3;
            do {
                fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 240);
                if (fieldOrArithmetic3 & 0x8000)
                    resultOrField2 = ((unsigned int)fieldOrArithmetic3 << 1) ^ 0x8005U;
                else
                    resultOrField2 = (unsigned int)fieldOrArithmetic3 << 1;
                Level26_7FC74Field(private19, volatile int*, 240) = resultOrField2;
                argumentOrField4++;
            } while (argumentOrField4 < 8);
            resultOrField2 = Level26_7FC74Field(private19, volatile int*, 244);
            argumentOrField5++;
            resultOrField2++;
            Level26_7FC74Field(private19, volatile int*, 244) = resultOrField2;
            if (argumentOrField5 < 64)
                goto actor1831OverlayCRC;
        }
    }
    fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 56);
    if (fieldOrArithmetic3 >= 0) {
        resultOrField2 = fieldOrArithmetic3 * 2;
        Level26_7FC74CompleteValue(resultOrField2);
        resultOrField2 += fieldOrArithmetic3;
        Level26_7FC74CompleteValue(resultOrField2);
        resultOrField2 *= 4;
        Level26_7FC74CompleteValue(resultOrField2);
        resultOrField2 -= fieldOrArithmetic3;
        Level26_7FC74CompleteValue(resultOrField2);
        resultOrField2 *= 8;
        Level26_7FC74CompleteValue(resultOrField2);
        fieldOrArithmetic3 = Level26_7FC74_D_8006C550;
        argumentOrField4 = Level26_7FC74Field(owner18, unsigned char*, 72);
        Level26_7FC74CompleteValue(argumentOrField4);
        linkedOwnerOrPosition20 = fieldOrArithmetic3 + resultOrField2;
        Level26_7FC74CompleteValue(linkedOwnerOrPosition20);
        linkedPrivate21 = Level26_7FC74Field(linkedOwnerOrPosition20, int*, 0);
        switch (argumentOrField4) {
            case 0:
                MATCHING_OBSERVE_VOLATILE(argumentOrField4);
                positionFlagsOrAddress16 = owner18 + 12;
                argumentOrField4 = positionFlagsOrAddress16;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField4, "$17");
                positionOrFlags17 = linkedOwnerOrPosition20 + 12;
                Level26_7FC74Field(owner18, signed char*, 79) = 48;
                Level26_7FC74CopyVector((void*)(positionFlagsOrAddress16),
                                        (void*)(positionOrFlags17));
                Level26_7FC74AddVector((void*)(positionFlagsOrAddress16),
                                       (void*)(positionFlagsOrAddress16),
                                       (void*)(positionOrFlags17));
                Level26_7FC74AddVector((void*)(positionFlagsOrAddress16),
                                       (void*)(positionFlagsOrAddress16),
                                       (void*)(positionOrFlags17));
                Level26_7FC74AddVector((void*)(positionFlagsOrAddress16),
                                       (void*)(positionFlagsOrAddress16),
                                       (void*)(Level26_7FC74Field(linkedPrivate21, int*, 0) + 0xC));
                Level26_7FC74ShiftVectorRightTowardZero((void*)(positionFlagsOrAddress16), 2);
                resultOrField2 = Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 69);
                argumentOrField4 = owner18;
                argumentOrField5 = 6;
                resultOrField2 = (int)((unsigned int)resultOrField2 << 24) >> 25;
                Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, int*, 20);
                fieldOrArithmetic3 =
                    Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 70);
                resultOrField2 += 512;
                Level26_7FC74Field(owner18, int*, 20) = resultOrField2;
                fieldOrArithmetic3 += 192;
                Level26_7FC74Field(owner18, unsigned char*, 70) = fieldOrArithmetic3;
                Level26_7FC74SetMobyAnimation((void*)(owner18), 6);
                resultOrField2 = 1;
                goto block_91;
            default:
                break;
            case 1:
                positionOrFlags17 = owner18 + 12;
                argumentOrField4 = positionOrFlags17;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField4, "$16");
                positionFlagsOrAddress16 = linkedOwnerOrPosition20 + 12;
                Level26_7FC74CopyVector((void*)(argumentOrField4),
                                        (void*)(positionFlagsOrAddress16));
                Level26_7FC74AddVector((void*)(positionOrFlags17), (void*)(positionOrFlags17),
                                       (void*)(positionFlagsOrAddress16));
                Level26_7FC74AddVector((void*)(positionOrFlags17), (void*)(positionOrFlags17),
                                       (void*)(positionFlagsOrAddress16));
                Level26_7FC74AddVector((void*)(positionOrFlags17), (void*)(positionOrFlags17),
                                       (void*)(Level26_7FC74Field(linkedPrivate21, int*, 0) + 0xC));
                Level26_7FC74ShiftVectorRightTowardZero((void*)(positionOrFlags17), 2);
                resultOrField2 = Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 69);
                argumentOrField4 = positionOrFlags17;
                argumentOrField5 = positionFlagsOrAddress16;
                resultOrField2 = (int)((unsigned int)resultOrField2 << 24) >> 25;
                Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, int*, 20);
                fieldOrArithmetic3 =
                    Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 70);
                resultOrField2 += 512;
                Level26_7FC74Field(owner18, int*, 20) = resultOrField2;
                fieldOrArithmetic3 += 192;
                Level26_7FC74Field(owner18, unsigned char*, 70) = fieldOrArithmetic3;
                if (Level26_7FC74ApproximatePlanarDistance(
                        (void*)(positionOrFlags17), (void*)((int)&Level26_7FC74_D_80070328)) <
                    0xC00) {
                    var_v0_3 = ((Level26_7FC74Field(owner18, int*, 0x14) -
                                 Level26_7FC74Field(owner18, short*, 0x38)) -
                                Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 8)) +
                               Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 0x44);
                    if (var_v0_3 < 0) {
                        var_v0_3 = -var_v0_3;
                    }
                    if ((var_v0_3 < 0x600) && (Level26_7FC74TestSubdividedSegmentPath(
                                                   (void*)((int)&Level26_7FC74_D_80070328),
                                                   (void*)(positionOrFlags17), 0) != 0)) {
                        Level26_7FC74RequestMobyAnimation((void*)(linkedOwnerOrPosition20), 1);
                        resultOrField2 = 2;
                        goto block_91;
                    }
                }
                break;
            case 2:
                positionFlagsOrAddress16 = owner18 + 12;
                argumentOrField4 = positionFlagsOrAddress16;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField4, "$17");
                positionOrFlags17 = linkedOwnerOrPosition20 + 12;
                Level26_7FC74CopyVector((void*)(argumentOrField4), (void*)(positionOrFlags17));
                Level26_7FC74AddVector((void*)(positionFlagsOrAddress16),
                                       (void*)(positionFlagsOrAddress16),
                                       (void*)(positionOrFlags17));
                Level26_7FC74AddVector((void*)(positionFlagsOrAddress16),
                                       (void*)(positionFlagsOrAddress16),
                                       (void*)(positionOrFlags17));
                Level26_7FC74AddVector((void*)(positionFlagsOrAddress16),
                                       (void*)(positionFlagsOrAddress16),
                                       (void*)(Level26_7FC74Field(linkedPrivate21, int*, 0) + 0xC));
                Level26_7FC74ShiftVectorRightTowardZero((void*)(positionFlagsOrAddress16), 2);
                resultOrField2 = Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 69);
                resultOrField2 = (int)((unsigned int)resultOrField2 << 24) >> 25;
                Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, int*, 20);
                fieldOrArithmetic3 =
                    Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 70);
                resultOrField2 += 512;
                Level26_7FC74Field(owner18, int*, 20) = resultOrField2;
                fieldOrArithmetic3 += 192;
                Level26_7FC74Field(owner18, unsigned char*, 70) = fieldOrArithmetic3;
                if (Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 0x3C) == 2) {
                    temp_v1_4 = Level26_7FC74Field(private19, int*, 0xE4);
                    if (temp_v1_4 != 0) {
                        Level26_7FC74Field(temp_v1_4, int*, 0) += 1;
                        Level26_7FC74Field(owner18, unsigned char*, 0x48) = 0xAU;
                        Level26_7FC74RegisterTrackedValue((void*)(owner18 + 0x48), 1,
                                                          (void*)((int)&Level26_7FC74_D_8006C7F8));
                        argumentOrField4 = Level26_7FC74Field(private19, int*, 228);
                        fieldOrArithmetic3 = Level26_7FC74Field(argumentOrField4, int*, 0);
                        if (fieldOrArithmetic3 == 5) {
                            resultOrField2 = 6;
                            Level26_7FC74Field(argumentOrField4, int*, 0) = resultOrField2;
                            resultOrField2 = Level26_7FC74_D_8006C7B4;
                            resultOrField2 &= 4;
                            if (!resultOrField2) {
                                resultOrField2 = 12;
                                goto block_91;
                            }
                        }
                        resultOrField2 = 3;
                    } else {
                        resultOrField2 = 3;
                    }
                    goto block_91;
                }
                break;
            case 12:
                argumentOrField4 = (int)&Level26_7FC74_D_8006E160;
                Level26_7FC74CompleteValue(argumentOrField4);
                resultOrField2 = Level26_7FC74Field(argumentOrField4, int*, 0);
                if (resultOrField2 == 0 && Level26_7FC74_D_8006E344 == 0) {
                    Level26_7FC74_D_8006C7B4 |= 4;
                    argumentOrField5 = (int)&Level26_7FC74_D_80070328;
                    argumentOrField4 -= 320;
                    Level26_7FC74PrepareCameraMode9Vectors((void*)(argumentOrField4),
                                                           (void*)(argumentOrField5));
                    resultOrField2 = 11;
                    goto block_91;
                }
                break;
            case 3:
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, unsigned char*, 68);
                Level26_7FC74CompleteValue(fieldOrArithmetic3);
                argumentOrField4 = fieldOrArithmetic3 & 0xFF;
                {
                    if (argumentOrField4 >= 129U) {
                        resultOrField2 = fieldOrArithmetic3 + 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    } else if (argumentOrField4) {
                        resultOrField2 = fieldOrArithmetic3 - 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    }
                }
                resultOrField2 = Level26_7FC74Field(private19, int*, 232);
                argumentOrField4 = owner18;
                if (resultOrField2) {
                    if ((resultOrField2 = Level26_7FC74CountTimerDown((void*)(private19 + 227), 1),
                         positionFlagsOrAddress16 = owner18 + 12, resultOrField2)) {
                        if (Level26_7FC74ApproximatePlanarDistance(
                                (void*)(positionFlagsOrAddress16),
                                (void*)(linkedOwnerOrPosition20 + 0xC)) >= 0x800) {
                            if (Level26_7FC74AbsoluteByteAngleDelta(
                                    Level26_7FC74Field(owner18, unsigned char*, 0x46),
                                    Level26_7FC74PlanarHeadingLookup(
                                        Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*,
                                                           0) -
                                            Level26_7FC74Field(owner18, int*, 0xC),
                                        Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*,
                                                           4) -
                                            Level26_7FC74Field(owner18, int*, 0x10),
                                        0)) < 0x30) {
                                if (Level26_7FC74ApproximatePlanarDistance(
                                        (void*)(positionFlagsOrAddress16),
                                        (void*)((int)&Level26_7FC74_D_80070328)) < 0x800) {
                                    var_v0_5 = ((Level26_7FC74Field(owner18, int*, 0x14) -
                                                 Level26_7FC74Field(owner18, short*, 0x38)) -
                                                Level26_7FC74Field((int)&Level26_7FC74_D_80070328,
                                                                   int*, 8)) +
                                               Level26_7FC74Field((int)&Level26_7FC74_D_80070328,
                                                                  int*, 0x44);
                                    if (var_v0_5 < 0) {
                                        var_v0_5 = -var_v0_5;
                                    }
                                    if (var_v0_5 >= 0x400) {
                                        goto block_40;
                                    }
                                    resultOrField2 = 60;
                                    goto actor1831TimerReset;
                                } else {
                                    goto block_41;
                                }
                            } else {
                            block_40:
                                goto block_41;
                            }
                        } else {
                        block_41:
                            if (Level26_7FC74UpdateMobyPathMotion(
                                    (void*)(owner18),
                                    (void*)(Level26_7FC74Field(private19, int*, 0xE8)), 0x100, 0x96,
                                    0, 0xA, 0x30, 0) &
                                2) {
                                Level26_7FC74RequestMobyAnimation((void*)(linkedOwnerOrPosition20),
                                                                  3);
                                MATCHING_OBSERVE_VOLATILE_CLOBBER(linkedOwnerOrPosition20,
                                                                  "memory");
                                resultOrField2 = 4;
                                goto block_91;
                            }
                            temp_a1 = Level26_7FC74Field(private19, int*, 0xE8);
                            temp_a0_4 = Level26_7FC74Field(owner18, int*, 0x14);
                            temp_v1_6 = Level26_7FC74Field(temp_a1, short*, 2) * 0x10;
                            if (Level26_7FC74Field(
                                    (temp_v1_6 +
                                     Level26_7FC74Field(Level26_7FC74Field(private19, int*, 0x3C),
                                                        int*, 0xC)),
                                    int*, 8) < temp_a0_4) {
                                temp_a0_5 = temp_a0_4 - 0x28;
                                Level26_7FC74Field(owner18, int*, 0x14) = temp_a0_5;
                                temp_v1_7 = Level26_7FC74Field(private19, int*, 0xE8);
                                var_v0_6 = Level26_7FC74Field(
                                    ((Level26_7FC74Field(temp_v1_7, short*, 2) * 0x10) +
                                     Level26_7FC74Field(temp_v1_7, int*, 0xC)),
                                    int*, 8);
                                var_a0_2 = temp_a0_5 < var_v0_6;
                                goto block_47;
                            }
                            if (temp_a0_4 <
                                Level26_7FC74Field(
                                    temp_v1_6 + Level26_7FC74Field(temp_a1, int*, 12), int*, 8)) {
                                argumentOrField4 = temp_a0_4 + 40;
                                Level26_7FC74Field(owner18, int*, 20) = argumentOrField4;
                                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 232);
                                resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                                fieldOrArithmetic3 =
                                    Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                                resultOrField2 *= 16;
                                resultOrField2 += fieldOrArithmetic3;
                                resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 8);
                                var_v0_6 = resultOrField2;
                                var_a0_2 = resultOrField2 < argumentOrField4;
                            block_47:
                                if (var_a0_2 != 0) {
                                    Level26_7FC74Field(owner18, int*, 0x14) = var_v0_6;
                                }
                            }
                        }
                    }
                    goto actor1831FirstSwitchDone;
                actor1831TimerReset:
                    /* Original late timer store shared by the earlier range test. */
                    Level26_7FC74Field(private19, signed char*, 227) = resultOrField2;
                    goto actor1831FirstSwitchDone;
                } else {
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField4, "$2");
                    Level26_7FC74ResolveMobyYawStep((void*)(argumentOrField4), 75, 0, 0, 0);
                    resultOrField2 = Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18));
                    fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                    resultOrField2 += 308;
                    if (resultOrField2 < fieldOrArithmetic3) {
                        resultOrField2 = fieldOrArithmetic3 - 20;
                        Level26_7FC74Field(owner18, int*, 20) = resultOrField2;
                    }
                    if (Level26_7FC74ApproximatePlanarDistance(
                            (void*)(owner18 + 0xC), (void*)(linkedOwnerOrPosition20 + 0xC)) >=
                        0x801) {
                        Level26_7FC74RequestMobyAnimation((void*)(linkedOwnerOrPosition20), 3);
                        resultOrField2 = 4;
                        goto block_91;
                    }
                }
                break;
            case 4:
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, unsigned char*, 68);
                Level26_7FC74CompleteValue(fieldOrArithmetic3);
                argumentOrField4 = fieldOrArithmetic3 & 0xFF;
                {
                    if (argumentOrField4 >= 129U) {
                        resultOrField2 = fieldOrArithmetic3 + 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    } else if (argumentOrField4) {
                        resultOrField2 = fieldOrArithmetic3 - 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    }
                }
                temp_v1_11 = Level26_7FC74Field(private19, int*, 0xE8);
                if (temp_v1_11 != 0) {
                    temp_v0 = (Level26_7FC74Field(temp_v1_11, short*, 0) * 0x10) +
                              Level26_7FC74Field(temp_v1_11, int*, 0xC);
                    Level26_7FC74TurnMobyTowardHeading(
                        (void*)(owner18),
                        Level26_7FC74PlanarHeadingLookup(
                            Level26_7FC74Field(temp_v0, int*, -0x20) -
                                Level26_7FC74Field(owner18, int*, 0xC),
                            Level26_7FC74Field(temp_v0, int*, -0x1C) -
                                Level26_7FC74Field(owner18, int*, 0x10),
                            0),
                        0xA, 0, 0, 0);
                }
                resultOrField2 = Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18));
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                resultOrField2 += 308;
                if (resultOrField2 < fieldOrArithmetic3) {
                    resultOrField2 = fieldOrArithmetic3 - 20;
                    Level26_7FC74Field(owner18, int*, 20) = resultOrField2;
                }
                if (Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 0x3C) == 0) {
                    argumentOrField4 = owner18 + 72;
                    argumentOrField5 = 1;
                    argumentOrField6 = (int)&Level26_7FC74_D_8006C7F8;
                    MATCHING_OBSERVE3_VOLATILE(argumentOrField4, argumentOrField5,
                                               argumentOrField6);
                    resultOrField2 = 10;
                    Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                    Level26_7FC74RegisterTrackedValue((void*)(argumentOrField4), argumentOrField5,
                                                      (void*)(argumentOrField6));
                    resultOrField2 = 5;
                    goto block_91;
                }
                break;
            case 5:
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, unsigned char*, 68);
                Level26_7FC74CompleteValue(fieldOrArithmetic3);
                argumentOrField4 = fieldOrArithmetic3 & 0xFF;
                {
                    if (argumentOrField4 >= 129U) {
                        resultOrField2 = fieldOrArithmetic3 + 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    } else if (argumentOrField4) {
                        resultOrField2 = fieldOrArithmetic3 - 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    }
                }
                resultOrField2 = Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18));
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                resultOrField2 += 308;
                if (resultOrField2 < fieldOrArithmetic3) {
                    resultOrField2 = fieldOrArithmetic3 - 20;
                    Level26_7FC74Field(owner18, int*, 20) = resultOrField2;
                }
                if (Level26_7FC74UpdateMobyInteractionGate((void*)(owner18), 0) != 0) {
                    if (Level26_7FC74_D_8006C7B4 & 4) {
                        Level26_7FC74Field(private19, unsigned char*, 2) = 3U;
                    }
                    temp_v0_2 =
                        5 - Level26_7FC74Field(Level26_7FC74Field(private19, int*, 0xE4), int*, 0);
                    Level26_7FC74_D_8006C59C = temp_v0_2;
                    if (temp_v0_2 == 1) {
                        Level26_7FC74Field(private19, unsigned char*, 2) = 2U;
                    }
                    Level26_7FC74StartDialogue((void*)(owner18), 6, 9);
                    resultOrField2 = 6;
                    goto block_91;
                }
                break;
            case 6:
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, unsigned char*, 68);
                Level26_7FC74CompleteValue(fieldOrArithmetic3);
                argumentOrField4 = fieldOrArithmetic3 & 0xFF;
                {
                    if (argumentOrField4 >= 129U) {
                        resultOrField2 = fieldOrArithmetic3 + 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    } else if (argumentOrField4) {
                        resultOrField2 = fieldOrArithmetic3 - 1;
                        Level26_7FC74Field(owner18, unsigned char*, 68) = resultOrField2;
                    }
                }
                if (Level26_7FC74_D_8006E344 != 1) {
                    Level26_7FC74RequestMobyAnimation((void*)(owner18), 6);
                    resultOrField2 = 5;
                    goto block_91;
                }
                break;
            case 11:
                argumentOrField4 = owner18;
                if (Level26_7FC74_D_8006E048 == 1) {
                    MATCHING_OBSERVE_VOLATILE(argumentOrField4);
                    resultOrField2 = Level26_7FC74Field(private19, int*, 232);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "$4");
                    argumentOrField4 = owner18 + 12;
                    if (resultOrField2) {
                        argumentOrField5 = Level26_7FC74Field(resultOrField2, short*, 0);
                        resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 12);
                        argumentOrField5 *= 16;
                        argumentOrField5 -= 16;
                        Level26_7FC74CompleteValue(argumentOrField5);
                        argumentOrField5 = resultOrField2 + argumentOrField5;
                        Level26_7FC74CopyVector((void*)(argumentOrField4),
                                                (void*)(argumentOrField5));
                        Level26_7FC74Field(owner18, int*, 0x14) =
                            (int)(Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18)) + 0x134);
                        Level26_7FC74Field(owner18, unsigned char*, 0x44) = 0U;
                        temp_v1_16 = Level26_7FC74Field(private19, int*, 0xE8);
                        temp_v0_4 = (Level26_7FC74Field(temp_v1_16, short*, 0) * 0x10) +
                                    Level26_7FC74Field(temp_v1_16, int*, 0xC);
                        Level26_7FC74Field(owner18, unsigned char*, 0x46) =
                            Level26_7FC74PlanarHeadingLookup(
                                Level26_7FC74Field(temp_v0_4, int*, -0x20) -
                                    Level26_7FC74Field(owner18, int*, 0xC),
                                Level26_7FC74Field(temp_v0_4, int*, -0x1C) -
                                    Level26_7FC74Field(owner18, int*, 0x10),
                                0);
                    } else {
                        resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                        resultOrField2 *= 2;
                        resultOrField2 = Level26_7FC74Field((int)&Level26_7FC74_D_80065920, short*,
                                                            resultOrField2);
                        __asm__ volatile("" ::"r"(owner18) : "memory", "$5");
                        argumentOrField5 = linkedOwnerOrPosition20 + 12;
                        __asm__(""
                                : "=r"(resultOrField2)
                                : "0"(resultOrField2), "r"(argumentOrField5));
                        resultOrField2 >>= 1;
                        originalFrame.sp20 = resultOrField2;
                        resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                        argumentOrField6 = (int)&originalFrame.sp20;
                        resultOrField2 *= 2;
                        resultOrField2 = Level26_7FC74Field((int)&Level26_7FC74_D_800658A0, short*,
                                                            resultOrField2);
                        __asm__ volatile("" ::"r"(owner18) : "memory", "$3");
                        fieldOrArithmetic3 = 512;
                        originalFrame.sp28 = fieldOrArithmetic3;
                        __asm__ volatile(""
                                         : "=r"(resultOrField2)
                                         : "0"(resultOrField2), "r"(fieldOrArithmetic3),
                                           "m"(originalFrame.sp28)
                                         : "memory");
                        resultOrField2 >>= 1;
                        originalFrame.sp24 = resultOrField2;
                        Level26_7FC74AddVector((void*)(argumentOrField4), (void*)(argumentOrField5),
                                               (void*)(argumentOrField6));
                        Level26_7FC74Field(owner18, int*, 0x14) =
                            (int)(Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18)) + 0x134);
                    }
                    Level26_7FC74SetMobyAnimation((void*)(owner18), 6);
                    Level26_7FC74Field(Level26_7FC74Field(owner18, int*, 0), unsigned char*, 5) = 2;
                    __asm__ volatile("" ::"r"(owner18) : "memory", "$16");
                    resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                    positionFlagsOrAddress16 = (int)&originalFrame.sp30;
                    resultOrField2 *= 2;
                    fieldOrArithmetic3 =
                        Level26_7FC74Field((int)&Level26_7FC74_D_80065920, short*, resultOrField2);
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                    argumentOrField4 = positionFlagsOrAddress16;
                    Level26_7FC74CompleteValue(argumentOrField4);
                    resultOrField2 = fieldOrArithmetic3 * 5;
                    Level26_7FC74CompleteValue(resultOrField2);
                    resultOrField2 = resultOrField2 * 8 - fieldOrArithmetic3;
                    Level26_7FC74CompleteValue(resultOrField2);
                    resultOrField2 >>= 6;
                    originalFrame.sp30 = resultOrField2;
                    resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                    __asm__ volatile("" ::"r"(owner18) : "memory", "$5");
                    argumentOrField5 = positionFlagsOrAddress16;
                    Level26_7FC74CompleteValue(argumentOrField5);
                    resultOrField2 *= 2;
                    fieldOrArithmetic3 =
                        Level26_7FC74Field((int)&Level26_7FC74_D_800658A0, short*, resultOrField2);
                    resultOrField2 = Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 68);
                    argumentOrField6 = owner18 + 12;
                    Level26_7FC74Field((int)&originalFrame.sp38, volatile int*, 0) = 0;
                    Level26_7FC74Field((int)&originalFrame.sp38, volatile int*, 0) = resultOrField2;
                    resultOrField2 = fieldOrArithmetic3 * 5;
                    Level26_7FC74CompleteValue(resultOrField2);
                    resultOrField2 = resultOrField2 * 8 - fieldOrArithmetic3;
                    Level26_7FC74CompleteValue(resultOrField2);
                    resultOrField2 >>= 6;
                    originalFrame.sp34 = resultOrField2;
                    Level26_7FC74AddVector((void*)(argumentOrField4), (void*)(argumentOrField5),
                                           (void*)(argumentOrField6));
                    Level26_7FC74SetCameraMode11Target(
                        (void*)(positionFlagsOrAddress16),
                        (Level26_7FC74Field(owner18, unsigned char*, 70) + 128) & 255, (void*)(0),
                        100);
                    resultOrField2 = Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 640);
                    if (resultOrField2 < 0) {
                        Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 640) = 0;
                        resultOrField2 = 5;
                        Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                    } else {
                        resultOrField2 = 5;
                        goto block_91;
                    }
                } else {
                    goto actor1831FirstSwitchCall;
                }
                break;
            case 10:
                Level26_7FC74Field(owner18, signed char*, 0x4F) = 0x30;
                resultOrField2 = Level26_7FC74Field(private19, int*, 232);
                if (resultOrField2) {
                    argumentOrField4 = owner18 + 12;
                    argumentOrField5 = Level26_7FC74Field(resultOrField2, short*, 0);
                    resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 12);
                    argumentOrField5 *= 16;
                    argumentOrField5 -= 16;
                    Level26_7FC74CompleteValue(argumentOrField5);
                    argumentOrField5 = resultOrField2 + argumentOrField5;
                    Level26_7FC74CopyVector((void*)(argumentOrField4), (void*)(argumentOrField5));
                    Level26_7FC74Field(owner18, int*, 0x14) =
                        (int)(Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18)) + 0x134);
                    Level26_7FC74Field(owner18, unsigned char*, 0x44) = 0U;
                    temp_v1_17 = Level26_7FC74Field(private19, int*, 0xE8);
                    temp_v0_6 = (Level26_7FC74Field(temp_v1_17, short*, 0) * 0x10) +
                                Level26_7FC74Field(temp_v1_17, int*, 0xC);
                    Level26_7FC74Field(owner18, unsigned char*, 0x46) =
                        Level26_7FC74PlanarHeadingLookup(
                            Level26_7FC74Field(temp_v0_6, int*, -0x20) -
                                Level26_7FC74Field(owner18, int*, 0xC),
                            Level26_7FC74Field(temp_v0_6, int*, -0x1C) -
                                Level26_7FC74Field(owner18, int*, 0x10),
                            0);
                } else {
                    argumentOrField5 = linkedOwnerOrPosition20 + 12;
                    resultOrField2 =
                        Level26_7FC74Field(linkedOwnerOrPosition20, unsigned char*, 70);
                    argumentOrField4 = owner18 + 12;
                    resultOrField2 += 192;
                    Level26_7FC74Field(owner18, unsigned char*, 70) = resultOrField2;
                    resultOrField2 &= 255;
                    resultOrField2 *= 2;
                    resultOrField2 =
                        Level26_7FC74Field((int)&Level26_7FC74_D_80065920, short*, resultOrField2);
                    Level26_7FC74CompleteValue(resultOrField2);
                    resultOrField2 >>= 1;
                    originalFrame.sp20 = resultOrField2;
                    resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                    argumentOrField6 = (int)&originalFrame.sp20;
                    resultOrField2 *= 2;
                    resultOrField2 =
                        Level26_7FC74Field((int)&Level26_7FC74_D_800658A0, short*, resultOrField2);
                    __asm__ volatile("" ::"r"(owner18) : "memory", "$3");
                    fieldOrArithmetic3 = 512;
                    originalFrame.sp28 = fieldOrArithmetic3;
                    __asm__ volatile(""
                                     : "=r"(resultOrField2)
                                     : "0"(resultOrField2), "r"(fieldOrArithmetic3),
                                       "m"(originalFrame.sp28)
                                     : "memory");
                    resultOrField2 >>= 1;
                    originalFrame.sp24 = resultOrField2;
                    Level26_7FC74AddVector((void*)(argumentOrField4), (void*)(argumentOrField5),
                                           (void*)(argumentOrField6));
                    Level26_7FC74Field(owner18, int*, 0x14) =
                        (int)(Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18)) + 0x134);
                }
                temp_v1_18 = Level26_7FC74Field(private19, int*, 0xE4);
                if (temp_v1_18 != 0) {
                    Level26_7FC74Field(temp_v1_18, int*, 0) += 1;
                }
                Level26_7FC74SetMobyAnimation((void*)(owner18), 6);
                resultOrField2 = 5;
            block_91:
                Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                break;
        }
    actor1831FirstSwitchDone:
        argumentOrField4 = owner18;
    actor1831FirstSwitchCall:
        /* This entry already has the initialized original A0 owner address. */
        Level26_7FC74RefreshMobySpatialGridAndBasis((void*)(argumentOrField4), 2);
        return;
    }
    controllerEnabled22 = 0;
    resultOrField2 = Level26_7FC74Field(private19, volatile int*, 244);
    if (!resultOrField2) {
        Level26_7FC74Field(private19, volatile int*, 244) =
            Level26_7FC74_D_8006C58C + ((int)&Level26_7FC74_main_TEXT_START + 2);
        resultOrField2 = Level26_7FC74Field(private19, volatile int*, 244);
    }
    fieldOrArithmetic3 = (int)&Level26_7FC74_main_TEXT_END;
    Level26_7FC74CompleteValue(fieldOrArithmetic3);
    if ((unsigned int)resultOrField2 < (unsigned int)fieldOrArithmetic3) {
        argumentOrField5 = 0;
        argumentOrField6 = fieldOrArithmetic3;
        Level26_7FC74CompleteValue(argumentOrField6);
    actor1831MainCRC:
        /* Separate executable-byte CRC phase with the original bounded per-invocation cursor work. */
        fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 244);
        if ((unsigned int)fieldOrArithmetic3 < (unsigned int)argumentOrField6) {
            argumentOrField4 = 0;
            resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, unsigned char*, 0);
            fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 240);
            resultOrField2 <<= 8;
            fieldOrArithmetic3 ^= resultOrField2;
            Level26_7FC74Field(private19, volatile int*, 240) = fieldOrArithmetic3;
            do {
                fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 240);
                if (fieldOrArithmetic3 & 0x8000)
                    resultOrField2 = ((unsigned int)fieldOrArithmetic3 << 1) ^ 0x8005U;
                else
                    resultOrField2 = (unsigned int)fieldOrArithmetic3 << 1;
                Level26_7FC74Field(private19, volatile int*, 240) = resultOrField2;
                argumentOrField4++;
            } while (argumentOrField4 < 8);
            resultOrField2 = Level26_7FC74Field(private19, volatile int*, 240);
            fieldOrArithmetic3 = Level26_7FC74Field(private19, volatile int*, 244);
            resultOrField2 &= 3;
            resultOrField2++;
            fieldOrArithmetic3 += resultOrField2;
            argumentOrField5++;
            Level26_7FC74Field(private19, int*, 244) = fieldOrArithmetic3;
            if (argumentOrField5 < 64)
                goto actor1831MainCRC;
            resultOrField2 = (int)&Level26_7FC74_main_TEXT_END;
            Level26_7FC74CompleteValue(resultOrField2);
            if ((unsigned int)fieldOrArithmetic3 < (unsigned int)resultOrField2)
                goto actor1831AfterCRC;
        }
        Level26_7FC74Field(private19, int*, 244) = (int)&Level26_7FC74_func_level_26_80074DC8;
    }
actor1831AfterCRC:
    if (Level26_7FC74Field(private19, int*, 244) == (int)&Level26_7FC74_D_level_26_8008ADD8 &&
        Level26_7FC74Field(private19, int*, 240) != 0) {
        resultOrField2 = Level26_7FC74Global6;
        fieldOrArithmetic3 = Level26_7FC74Global15;
        resultOrField2 &= 254;
        fieldOrArithmetic3 &= 254;
        Level26_7FC74Global6 = resultOrField2;
        Level26_7FC74Global15 = fieldOrArithmetic3;
        Level26_7FC74Field(private19, int*, 240) = 0;
    }
    temp_v1_22 = Level26_7FC74Field(owner18, unsigned char*, 0x48);
    switch (temp_v1_22) {
        case 0:
            Level26_7FC74ConfigureHudEntry(7, 0x104, (void*)((int)&Level26_7FC74_func_80027EE4),
                                           (void*)((int)&Level26_7FC74_func_80027A60),
                                           (void*)((int)&Level26_7FC74_func_80029AA0),
                                           (void*)(Level26_7FC74Field(private19, int*, 0xE4)), 5);
            Level26_7FC74Field(owner18, unsigned char*, 0x48) = 1U;
            Level26_7FC74Field(owner18, int*, 0x14) =
                (int)(Level26_7FC74Field(owner18, int*, 0x14) + 0x19A);
            break;
        case 1:
            if (Level26_7FC74_D_8006C770 != 0) {
                if (Level26_7FC74Field(private19, short*, 0xEE) == 0) {
                    Level26_7FC74RequestMobyAnimation((void*)(owner18), 1);
                    Level26_7FC74Field(private19, short*, 0xEE) = Level26_7FC74RandBetween(3, 8);
                } else {
                    Level26_7FC74RequestMobyAnimation((void*)(owner18), 0);
                    Level26_7FC74Field(private19, short*, 0xEE) =
                        (short)((unsigned short)Level26_7FC74Field(private19, short*, 0xEE) - 1);
                }
            }
            Level26_7FC74Field(owner18, int*, 0x14) =
                (int)(Level26_7FC74Field(owner18, int*, 0x14) - 0x100);
            if ((Level26_7FC74Field(private19, int*, 0x6C) == 0) &&
                (Level26_7FC74UpdateMobyInteractionGate((void*)(owner18), 0) != 0)) {
                Level26_7FC74StartDialogue((void*)(owner18), 0, 3);
                Level26_7FC74Field(owner18, unsigned char*, 0x48) = 2U;
            } else {
                controllerEnabled22 = 1;
            }
            Level26_7FC74Field(owner18, int*, 0x14) =
                (int)(Level26_7FC74Field(owner18, int*, 0x14) + 0x100);
            break;
        case 2:
            if (Level26_7FC74_D_8006E344 != 1) {
                if (Level26_7FC74Field(private19, unsigned char*, 4) == 3) {
                    Level26_7FC74StartDialogue((void*)(owner18), 0, 3);
                } else {
                    goto block_186;
                }
            }
            break;
        case 3:
            resultOrField2 = Level26_7FC74CountTimerDown((void*)(private19 + 227), 1);
            argumentOrField4 = (int)&originalFrame.sp20;
            if (resultOrField2) {
                MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField4, "$20");
                positionFlagsOrAddress16 = owner18 + 12;
                Level26_7FC74CopyVector((void*)(argumentOrField4),
                                        (void*)(positionFlagsOrAddress16));
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 60);
                argumentOrField4 = owner18;
                resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                resultOrField2 *= 16;
                resultOrField2 += fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 8);
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                resultOrField2 -= fieldOrArithmetic3;
                resultOrField2 >>= 2;
                fieldOrArithmetic3 += resultOrField2;
                Level26_7FC74Field(owner18, int*, 20) = fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74UpdateMobyPathMotion(
                    (void*)(owner18), (void*)(Level26_7FC74Field(private19, int*, 60)), 256, 200, 0,
                    8, 32, 256);
                argumentOrField4 = (int)&originalFrame.sp40;
                argumentOrField5 = positionFlagsOrAddress16;
                MATCHING_KEEP2_VOLATILE_CLOBBER(argumentOrField4, argumentOrField5, "memory");
                positionFlagsOrAddress16 = resultOrField2;
                Level26_7FC74CopyVector((void*)(argumentOrField4), (void*)(argumentOrField5));
                resultOrField2 = originalFrame.sp48;
                resultOrField2 += 500;
                originalFrame.sp48 = resultOrField2;
                resultOrField2 = positionFlagsOrAddress16 & 2;
                if (resultOrField2)
                    goto block_128;
                resultOrField2 = positionFlagsOrAddress16 & 1;
                if (!resultOrField2)
                    goto actor1831VectorReload40;
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 60);
                resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                resultOrField2 *= 16;
                resultOrField2 += fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 12);
                if (!resultOrField2)
                    goto actor1831VectorReload40;
            block_128:
                /* Original successful path transition; one producer for each shared argument address. */
                argumentOrField4 = owner18 + 73;
                argumentOrField5 = 1;
                __asm__ volatile("" ::"r"(argumentOrField5) : "memory", "$16");
                positionFlagsOrAddress16 = (int)&Level26_7FC74_D_8006C7F8;
                argumentOrField6 = positionFlagsOrAddress16;
                __asm__ volatile("" ::"r"(argumentOrField6) : "memory", "$22", "$3");
                controllerEnabled22 = 1;
                resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 73);
                fieldOrArithmetic3 = 10;
                Level26_7FC74Field(owner18, unsigned char*, 72) = fieldOrArithmetic3;
                resultOrField2++;
                Level26_7FC74Field(owner18, unsigned char*, 73) = resultOrField2;
                Level26_7FC74RegisterTrackedValue((void*)(argumentOrField4), argumentOrField5,
                                                  (void*)(argumentOrField6));
                Level26_7FC74RegisterTrackedValue((void*)(owner18 + 72), 1,
                                                  (void*)(positionFlagsOrAddress16));
                Level26_7FC74RegisterTrackedValue(
                    (void*)(Level26_7FC74Field(private19, int*, 60) + 2), 2,
                    (void*)(positionFlagsOrAddress16));
                resultOrField2 = 1;
                Level26_7FC74Field(private19, int*, 108) = resultOrField2;
                resultOrField2 = 4;
                Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                goto actor1831AfterVectorTest40;
            actor1831VectorReload40:
                argumentOrField4 = (int)&originalFrame.sp40;
                if (Level26_7FC74TestPlayerSphereOverlap((void*)(argumentOrField4), 768, 0)) {
                    resultOrField2 = 60;
                    Level26_7FC74Field(private19, signed char*, 227) = resultOrField2;
                    Level26_7FC74CopyVector((void*)(owner18 + 12), (void*)(&originalFrame.sp20));
                }
            actor1831AfterVectorTest40:;
            } else {
                argumentOrField4 = (int)&originalFrame.sp50;
                Level26_7FC74CompleteValue(argumentOrField4);
                positionFlagsOrAddress16 = owner18 + 12;
                Level26_7FC74CopyVector((void*)(argumentOrField4),
                                        (void*)(positionFlagsOrAddress16));
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 60);
                argumentOrField4 = owner18;
                resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                resultOrField2 *= 16;
                resultOrField2 += fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 8);
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                resultOrField2 -= fieldOrArithmetic3;
                resultOrField2 >>= 2;
                fieldOrArithmetic3 += resultOrField2;
                Level26_7FC74Field(owner18, int*, 20) = fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74UpdateMobyPathMotion(
                    (void*)(owner18), (void*)(Level26_7FC74Field(private19, int*, 60)), 256, 200, 0,
                    8, 32, 256);
                argumentOrField4 = (int)&originalFrame.sp60;
                argumentOrField5 = positionFlagsOrAddress16;
                MATCHING_KEEP2_VOLATILE_CLOBBER(argumentOrField4, argumentOrField5, "memory");
                positionFlagsOrAddress16 = resultOrField2;
                Level26_7FC74CopyVector((void*)(argumentOrField4), (void*)(argumentOrField5));
                resultOrField2 = originalFrame.sp68;
                resultOrField2 += 500;
                originalFrame.sp68 = resultOrField2;
                resultOrField2 = positionFlagsOrAddress16 & 2;
                if (resultOrField2)
                    goto block_135;
                resultOrField2 = positionFlagsOrAddress16 & 1;
                if (!resultOrField2)
                    goto actor1831VectorReload60;
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 60);
                resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                resultOrField2 *= 16;
                resultOrField2 += fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 12);
                if (!resultOrField2)
                    goto actor1831VectorReload60;
            block_135:
                /* Separate original successful path transition for the second saved vector. */
                argumentOrField4 = owner18 + 73;
                argumentOrField5 = 1;
                __asm__ volatile("" ::"r"(argumentOrField5) : "memory", "$16");
                positionFlagsOrAddress16 = (int)&Level26_7FC74_D_8006C7F8;
                argumentOrField6 = positionFlagsOrAddress16;
                __asm__ volatile("" ::"r"(argumentOrField6) : "memory", "$22", "$3");
                controllerEnabled22 = 1;
                resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 73);
                fieldOrArithmetic3 = 10;
                Level26_7FC74Field(owner18, unsigned char*, 72) = fieldOrArithmetic3;
                resultOrField2++;
                Level26_7FC74Field(owner18, unsigned char*, 73) = resultOrField2;
                Level26_7FC74RegisterTrackedValue((void*)(argumentOrField4), argumentOrField5,
                                                  (void*)(argumentOrField6));
                Level26_7FC74RegisterTrackedValue((void*)(owner18 + 72), 1,
                                                  (void*)(positionFlagsOrAddress16));
                Level26_7FC74RegisterTrackedValue(
                    (void*)(Level26_7FC74Field(private19, int*, 60) + 2), 2,
                    (void*)(positionFlagsOrAddress16));
                resultOrField2 = 1;
                Level26_7FC74Field(private19, int*, 108) = resultOrField2;
                resultOrField2 = 4;
                Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                goto actor1831AfterVectorTest60;
            actor1831VectorReload60:
                argumentOrField4 = (int)&originalFrame.sp60;
                if (Level26_7FC74TestPlayerSphereOverlap((void*)(argumentOrField4), 1024, 0)) {
                    resultOrField2 = 60;
                    Level26_7FC74Field(private19, signed char*, 227) = resultOrField2;
                }
            actor1831AfterVectorTest60:;
                Level26_7FC74CopyVector((void*)(owner18 + 0xC), (void*)(&originalFrame.sp50));
            }
            break;
        case 4:
            if ((unsigned char)Level26_7FC74Field(owner18, unsigned char*, 0x49) < 0xDU) {
                if (Level26_7FC74CountTimerDown((void*)(private19 + 0xE3), 1) != 0) {
                    argumentOrField4 = (int)&originalFrame.sp70;
                    Level26_7FC74CompleteValue(argumentOrField4);
                    linkedOwnerOrPosition20 = owner18 + 12;
                    Level26_7FC74CopyVector((void*)(argumentOrField4),
                                            (void*)(linkedOwnerOrPosition20));
                    resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 73);
                    argumentOrField5 = resultOrField2 - 1;
                    resultOrField2 = argumentOrField5 < 11;
                    if (!resultOrField2) {
                        argumentOrField5 = 10;
                        Level26_7FC74CompleteValue(argumentOrField5);
                    }
                    argumentOrField5 *= 4;
                    temp_a1_3 = argumentOrField5 + private19;
                    fieldOrArithmetic3 = Level26_7FC74Field(temp_a1_3, int*, 64);
                    resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                    fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                    resultOrField2 *= 16;
                    resultOrField2 += fieldOrArithmetic3;
                    resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 8);
                    fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                    resultOrField2 -= fieldOrArithmetic3;
                    resultOrField2 >>= 4;
                    fieldOrArithmetic3 += resultOrField2;
                    Level26_7FC74Field(owner18, int*, 20) = fieldOrArithmetic3;
                    resultOrField2 = Level26_7FC74UpdateMobyPathMotion(
                        (void*)(owner18), (void*)(Level26_7FC74Field(temp_a1_3, int*, 64)), 256,
                        150, 0, 8, 8, 256);
                    argumentOrField4 = (int)&originalFrame.sp80;
                    argumentOrField5 = linkedOwnerOrPosition20;
                    MATCHING_OBSERVE2_VOLATILE(argumentOrField4, argumentOrField5);
                    positionOrFlags17 = resultOrField2;
                    Level26_7FC74CopyVector((void*)(argumentOrField4), (void*)(argumentOrField5));
                    originalFrame.sp88 += 0x1F4;
                    if (Level26_7FC74TestPlayerSphereOverlap((void*)(&originalFrame.sp80), 0x300,
                                                             0) != 0) {
                        Level26_7FC74Field(private19, signed char*, 0xE3) = 0x3C;
                        Level26_7FC74CopyVector((void*)(linkedOwnerOrPosition20),
                                                (void*)(&originalFrame.sp70));
                    } else if (({
                                   resultOrField2 = positionOrFlags17 & 2;
                                   Level26_7FC74CompleteValue(resultOrField2);
                                   resultOrField2;
                               })) {
                        goto block_147;
                    }
                    goto actor1831Switch2Done;
                block_147:
                    resultOrField2 = 5;
                    Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                    goto actor1831Switch2Done;
                } else {
                    argumentOrField4 = (int)&originalFrame.sp90;
                    Level26_7FC74CompleteValue(argumentOrField4);
                    positionOrFlags17 = owner18 + 12;
                    Level26_7FC74CopyVector((void*)(argumentOrField4), (void*)(positionOrFlags17));
                    resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 73);
                    argumentOrField5 = resultOrField2 - 1;
                    resultOrField2 = argumentOrField5 < 14;
                    if (!resultOrField2) {
                        argumentOrField5 = 7;
                        Level26_7FC74CompleteValue(argumentOrField5);
                    }
                    resultOrField2 = argumentOrField5 < 11;
                    if (!resultOrField2) {
                        argumentOrField5 = 10;
                        Level26_7FC74CompleteValue(argumentOrField5);
                    }
                    argumentOrField5 *= 4;
                    temp_a1_4 = argumentOrField5 + private19;
                    fieldOrArithmetic3 = Level26_7FC74Field(temp_a1_4, int*, 64);
                    resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                    fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                    resultOrField2 *= 16;
                    resultOrField2 += fieldOrArithmetic3;
                    resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 8);
                    fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 20);
                    resultOrField2 -= fieldOrArithmetic3;
                    resultOrField2 >>= 4;
                    fieldOrArithmetic3 += resultOrField2;
                    Level26_7FC74Field(owner18, int*, 20) = fieldOrArithmetic3;
                    Level26_7FC74UpdateMobyPathMotion(
                        (void*)(owner18), (void*)(Level26_7FC74Field(temp_a1_4, int*, 0x40)), 0x100,
                        0x96, 0, 8, 8, 0x100);
                    Level26_7FC74CopyVector((void*)(&originalFrame.spA0),
                                            (void*)(positionOrFlags17));
                    originalFrame.spA8 += 0x1F4;
                    if (Level26_7FC74TestPlayerSphereOverlap((void*)(&originalFrame.spA0), 0x400,
                                                             0) != 0) {
                        Level26_7FC74Field(private19, signed char*, 0xE3) = 0x3C;
                    }
                    Level26_7FC74CopyVector((void*)(positionOrFlags17),
                                            (void*)(&originalFrame.sp90));
                }
            } else {
                goto block_147;
            }
            break;
        case 12:
            if ((Level26_7FC74_D_8006E160 == 0) && (Level26_7FC74_D_8006E344 == 0)) {
                resultOrField2 = Level26_7FC74_D_8006C7B4;
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 0);
                resultOrField2 |= 2;
                Level26_7FC74_D_8006C7B4 = resultOrField2;
                resultOrField2 = 2;
                Level26_7FC74Field(fieldOrArithmetic3, unsigned char*, 5) = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                positionFlagsOrAddress16 = (int)&originalFrame.spB0;
                resultOrField2 *= 2;
                fieldOrArithmetic3 =
                    Level26_7FC74Field((int)&Level26_7FC74_D_80065920, short*, resultOrField2);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                argumentOrField4 = positionFlagsOrAddress16;
                Level26_7FC74CompleteValue(argumentOrField4);
                resultOrField2 = fieldOrArithmetic3 * 5;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 = resultOrField2 * 8 - fieldOrArithmetic3;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 >>= 6;
                originalFrame.spB0 = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                __asm__ volatile("" ::"r"(owner18) : "memory", "$5");
                argumentOrField5 = positionFlagsOrAddress16;
                Level26_7FC74CompleteValue(argumentOrField5);
                resultOrField2 *= 2;
                fieldOrArithmetic3 =
                    Level26_7FC74Field((int)&Level26_7FC74_D_800658A0, short*, resultOrField2);
                resultOrField2 = Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 68);
                argumentOrField6 = owner18 + 12;
                Level26_7FC74Field((int)&originalFrame.spB8, volatile int*, 0) = 0;
                Level26_7FC74Field((int)&originalFrame.spB8, volatile int*, 0) = resultOrField2;
                resultOrField2 = fieldOrArithmetic3 * 5;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 = resultOrField2 * 8 - fieldOrArithmetic3;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 >>= 6;
                originalFrame.spB4 = resultOrField2;
                Level26_7FC74AddVector((void*)(argumentOrField4), (void*)(argumentOrField5),
                                       (void*)(argumentOrField6));
                Level26_7FC74SetCameraMode11Target(
                    (void*)(positionFlagsOrAddress16),
                    (Level26_7FC74Field(owner18, unsigned char*, 70) + 128) & 255, (void*)(0), 100);
                __asm__ volatile("" ::"m"(originalFrame.spB0) : "memory");
                if (Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 0x280) < 0) {
                    Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 0x280) = 0;
                    __asm__ volatile("" ::"m"(originalFrame.spB0) : "memory");
                    Level26_7FC74Field(owner18, unsigned char*, 0x48) = 1U;
                } else {
                    goto block_187;
                }
            }
            break;
        case 13:
            if ((Level26_7FC74_D_8006E160 == 0) && (Level26_7FC74_D_8006E344 == 0)) {
                resultOrField2 = Level26_7FC74_D_8006C7B4;
                fieldOrArithmetic3 = Level26_7FC74Field(owner18, int*, 0);
                resultOrField2 |= 1;
                Level26_7FC74_D_8006C7B4 = resultOrField2;
                resultOrField2 = 2;
                Level26_7FC74Field(fieldOrArithmetic3, unsigned char*, 5) = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                positionFlagsOrAddress16 = (int)&originalFrame.spC0;
                resultOrField2 *= 2;
                fieldOrArithmetic3 =
                    Level26_7FC74Field((int)&Level26_7FC74_D_80065920, short*, resultOrField2);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(owner18, "memory");
                argumentOrField4 = positionFlagsOrAddress16;
                Level26_7FC74CompleteValue(argumentOrField4);
                resultOrField2 = fieldOrArithmetic3 * 5;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 = resultOrField2 * 8 - fieldOrArithmetic3;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 >>= 6;
                originalFrame.spC0 = resultOrField2;
                resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 70);
                __asm__ volatile("" ::"r"(owner18) : "memory", "$5");
                argumentOrField5 = positionFlagsOrAddress16;
                Level26_7FC74CompleteValue(argumentOrField5);
                resultOrField2 *= 2;
                fieldOrArithmetic3 =
                    Level26_7FC74Field((int)&Level26_7FC74_D_800658A0, short*, resultOrField2);
                resultOrField2 = Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 68);
                argumentOrField6 = owner18 + 12;
                Level26_7FC74Field((int)&originalFrame.spC8, volatile int*, 0) = 0;
                Level26_7FC74Field((int)&originalFrame.spC8, volatile int*, 0) = resultOrField2;
                resultOrField2 = fieldOrArithmetic3 * 5;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 = resultOrField2 * 8 - fieldOrArithmetic3;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 >>= 6;
                originalFrame.spC4 = resultOrField2;
                Level26_7FC74AddVector((void*)(argumentOrField4), (void*)(argumentOrField5),
                                       (void*)(argumentOrField6));
                Level26_7FC74SetCameraMode11Target(
                    (void*)(positionFlagsOrAddress16),
                    (Level26_7FC74Field(owner18, unsigned char*, 70) + 128) & 255, (void*)(0), 100);
                __asm__ volatile("" ::"m"(originalFrame.spC0) : "memory");
                if (Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 0x280) < 0) {
                    Level26_7FC74Field((int)&Level26_7FC74_D_80070328, int*, 0x280) = 0;
                    __asm__ volatile("" ::"m"(originalFrame.spC0) : "memory");
                    Level26_7FC74Field(owner18, unsigned char*, 0x48) = 1U;
                } else {
                    goto block_187;
                }
            }
            break;
        case 5:
            resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 73);
            fieldOrArithmetic3 = resultOrField2 - 1;
            resultOrField2 = fieldOrArithmetic3 < 14;
            if (!resultOrField2) {
                fieldOrArithmetic3 = 8;
                Level26_7FC74CompleteValue(fieldOrArithmetic3);
            }
            resultOrField2 = fieldOrArithmetic3 < 11;
            if (!resultOrField2) {
                fieldOrArithmetic3 = 10;
                Level26_7FC74CompleteValue(fieldOrArithmetic3);
            }
            resultOrField2 = fieldOrArithmetic3 * 4;
            temp_v1_33 = Level26_7FC74Field(resultOrField2 + private19, int*, 64);
            positionFlagsOrAddress16 =
                Level26_7FC74Field(((Level26_7FC74Field(temp_v1_33, short*, 0) * 0x10) +
                                    Level26_7FC74Field(temp_v1_33, int*, 0xC)),
                                   int*, -8);
            temp_v1_34 = Level26_7FC74Field(owner18, int*, 0x14);
            Level26_7FC74Field(owner18, int*, 0x14) =
                (int)(temp_v1_34 + ((int)(positionFlagsOrAddress16 - temp_v1_34) >> 4));
            if ((unsigned char)Level26_7FC74Field(owner18, unsigned char*, 0x49) >= 0xBU) {
                var_v0_14 = 0x20;
            } else {
                temp_v1_35 = Level26_7FC74Field(private19, int*, 0x3C);
                temp_v0_8 = (Level26_7FC74Field(temp_v1_35, short*, 2) * 0x10) +
                            Level26_7FC74Field(temp_v1_35, int*, 0xC);
                var_v0_14 = Level26_7FC74PlanarHeadingLookup(
                    Level26_7FC74Field(temp_v0_8, int*, 0) - Level26_7FC74Field(owner18, int*, 0xC),
                    Level26_7FC74Field(temp_v0_8, int*, 4) -
                        Level26_7FC74Field(owner18, int*, 0x10),
                    0);
            }
            if (Level26_7FC74TurnMobyTowardHeading((void*)(owner18), var_v0_14, 8, 0, 0, 0) != 0) {
                var_v0_15 = positionFlagsOrAddress16 - Level26_7FC74Field(owner18, int*, 0x14);
                if (var_v0_15 < 0) {
                    var_v0_15 = -var_v0_15;
                }
                if (var_v0_15 < 0x40) {
                    temp_v1_36 = Level26_7FC74Field(owner18, unsigned char*, 0x49);
                    if (temp_v1_36 == 5) {
                        resultOrField2 = Level26_7FC74_D_8006C7B4;
                        resultOrField2 &= 2;
                        if (resultOrField2)
                            goto actor1831State4;
                        __asm__ volatile("" ::"r"(owner18) : "$2", "$4");
                        argumentOrField4 = owner18;
                        argumentOrField5 = 0;
                        resultOrField2 = 12;
                        goto block_180;
                    }
                    if (temp_v1_36 == 0xB) {
                        resultOrField2 = Level26_7FC74_D_8006C7B4;
                        resultOrField2 &= 1;
                        if (resultOrField2)
                            goto actor1831State7;
                        __asm__ volatile("" ::"r"(owner18) : "$2", "$4");
                        argumentOrField4 = owner18;
                        argumentOrField5 = 0;
                        resultOrField2 = 13;
                    block_180:
                        Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                        Level26_7FC74RequestMobyAnimation((void*)(argumentOrField4),
                                                          argumentOrField5);
                        Level26_7FC74Field(private19, int*, 108) = 0;
                        goto actor1831Switch2Done;
                    actor1831State4:
                        resultOrField2 = 4;
                        goto block_181;
                    actor1831State7:
                        resultOrField2 = 7;
                    block_181:
                        Level26_7FC74Field(private19, unsigned char*, 2) = resultOrField2;
                        Level26_7FC74Field(private19, int*, 108) = 0;
                        goto block_185;
                    } else {
                        if ((Level26_7FC74Field(owner18, int*, 0x14) -
                             Level26_7FC74ProbeGroundFromRaisedMoby((void*)(owner18))) < 0x200) {
                            Level26_7FC74Field(private19, int*, 0x6C) = 0;
                        } else {
                            resultOrField2 = 1;
                            Level26_7FC74Field(private19, int*, 108) = resultOrField2;
                        }
                    block_185:
                        goto block_186;
                    }
                }
            }
            break;
        block_186:
            Level26_7FC74RequestMobyAnimation((void*)(owner18), 0);
        block_187:
            Level26_7FC74Field(owner18, unsigned char*, 72) = 1;
            goto actor1831Switch2Done;
        case 10:
            fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 60);
            resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
            fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, short*, 0);
            resultOrField2 += fieldOrArithmetic3;
            resultOrField2--;
            positionFlagsOrAddress16 = resultOrField2 % fieldOrArithmetic3;
            Level26_7FC74ConfigureHudEntry(7, 0x104, (void*)((int)&Level26_7FC74_func_80027EE4),
                                           (void*)((int)&Level26_7FC74_func_80027A60),
                                           (void*)((int)&Level26_7FC74_func_80029AA0),
                                           (void*)(Level26_7FC74Field(private19, int*, 0xE4)), 5);
            positionFlagsOrAddress16 = positionFlagsOrAddress16 * 0x10;
            Level26_7FC74CopyVector(
                (void*)(owner18 + 0xC),
                (void*)(Level26_7FC74Field(Level26_7FC74Field(private19, int*, 0x3C), int*, 0xC) +
                        positionFlagsOrAddress16));
            resultOrField2 = Level26_7FC74Field(owner18, unsigned char*, 73);
            resultOrField2 = (unsigned int)resultOrField2 < 11;
            argumentOrField6 = 0;
            if (!resultOrField2) {
                resultOrField2 = 32;
            } else {
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 60);
                resultOrField2 = Level26_7FC74Field(fieldOrArithmetic3, short*, 2);
                fieldOrArithmetic3 = Level26_7FC74Field(fieldOrArithmetic3, int*, 12);
                resultOrField2 *= 16;
                resultOrField2 += fieldOrArithmetic3;
                fieldOrArithmetic3 = positionFlagsOrAddress16 + fieldOrArithmetic3;
                argumentOrField7 = Level26_7FC74Field(resultOrField2, int*, 0);
                argumentOrField4 = Level26_7FC74Field(fieldOrArithmetic3, int*, 0);
                resultOrField2 = Level26_7FC74Field(resultOrField2, int*, 4);
                argumentOrField5 = Level26_7FC74Field(fieldOrArithmetic3, int*, 4);
                argumentOrField4 = argumentOrField7 - argumentOrField4;
                argumentOrField5 = resultOrField2 - argumentOrField5;
                resultOrField2 = Level26_7FC74PlanarHeadingLookup(
                    argumentOrField4, argumentOrField5, argumentOrField6, argumentOrField7);
            }
            Level26_7FC74Field(owner18, unsigned char*, 70) = resultOrField2;
            __asm__ volatile("" ::"r"(owner18) : "memory", "$22");
            controllerEnabled22 = 1;
            resultOrField2 = 1;
            Level26_7FC74Field(private19, int*, 108) = resultOrField2;
            Level26_7FC74Field(owner18, unsigned char*, 0x48) = 4U;
            Level26_7FC74Field(owner18, unsigned char*, 82) = 254;
            break;
    }
actor1831Switch2Done:
    /* Join the original controller states before the final byte-state dispatch. */
    Level26_7FC74CompleteValue(controllerEnabled22);
    if (controllerEnabled22 != 0) {
        temp_v1_42 = Level26_7FC74Field(owner18, unsigned char*, 0x49);
        switch (temp_v1_42) {
            case 0:
                if ((Level26_7FC74Field(private19, unsigned char*, 2) == 1) ||
                    (Level26_7FC74TestPaddedRotatedBox((void*)((int)&Level26_7FC74_D_80070328),
                                                       (void*)(private19 + 0x70), 0, 0x800) != 0)) {
                    Level26_7FC74Field(private19, unsigned char*, 5) = 0U;
                    Level26_7FC74RequestMobyAnimation((void*)(owner18), 2);
                    argumentOrField4 = private19 + 2;
                    Level26_7FC74CompleteValue(argumentOrField4);
                    Level26_7FC74Field(owner18, unsigned char*, 0x48) = 3U;
                    resultOrField2 = Level26_7FC74Field(private19, unsigned char*, 224);
                    argumentOrField5 = 1;
                    goto block_215;
                }
                break;
            case 1:
                if ((Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0x88) * 0x58) +
                                         Level26_7FC74_D_8006C550),
                                        unsigned char*, 0x48) &
                     0x80) ||
                    (Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0x90) * 0x58) +
                                         Level26_7FC74_D_8006C550),
                                        unsigned char*, 0x48) &
                     0x80) ||
                    (Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0x94) * 0x58) +
                                         Level26_7FC74_D_8006C550),
                                        unsigned char*, 0x48) &
                     0x80)) {
                    Level26_7FC74RequestMobyAnimation((void*)(owner18), 2);
                    argumentOrField4 = private19 + 2;
                    Level26_7FC74CompleteValue(argumentOrField4);
                    Level26_7FC74Field(owner18, unsigned char*, 0x48) = 3U;
                    resultOrField2 = Level26_7FC74Field(private19, unsigned char*, 225);
                    argumentOrField5 = 1;
                    goto block_215;
                }
                break;
            case 2:
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 140);
                resultOrField2 = fieldOrArithmetic3 * 2;
                goto actor1831LateScale;
            case 3:
                if (!(Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0x90) * 0x58) +
                                          Level26_7FC74_D_8006C550),
                                         unsigned char*, 0x48) &
                      0x80)) {
                    resultOrField2 =
                        Level26_7FC74Field(Level26_7FC74_D_8006C550 +
                                               Level26_7FC74Field(private19, int*, 148) * 88,
                                           unsigned char*, 72) &
                        128;
                    goto actor1831LateTest;
                }
                goto actor1831LateOwner;
            case 4:
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 148);
                resultOrField2 = fieldOrArithmetic3 * 2;
                goto actor1831LateScale;
            case 5:
                if ((Level26_7FC74Field(private19, unsigned char*, 2) == 4) &&
                    (Level26_7FC74Field(private19, unsigned char*, 5) == 0)) {
                    argumentOrField4 = owner18;
                    goto actor1831LateOwnerReady;
                }
                break;
            case 6:
                if (!(Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0x98) * 0x58) +
                                          Level26_7FC74_D_8006C550),
                                         unsigned char*, 0x48) &
                      0x80) ||
                    !(Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0x9C) * 0x58) +
                                          Level26_7FC74_D_8006C550),
                                         unsigned char*, 0x48) &
                      0x80) ||
                    !(Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0xA0) * 0x58) +
                                          Level26_7FC74_D_8006C550),
                                         unsigned char*, 0x48) &
                      0x80)) {
                    fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 164);
                    resultOrField2 = fieldOrArithmetic3 * 2;
                    goto actor1831LateScale;
                }
                argumentOrField4 = owner18;
                goto actor1831LateOwnerReady;
            case 7:
                if (Level26_7FC74Field(((Level26_7FC74Field(private19, int*, 0xA4) * 0x58) +
                                        Level26_7FC74_D_8006C550),
                                       unsigned char*, 0x48) &
                    0x80) {
                    Level26_7FC74RequestMobyAnimation((void*)(owner18), 2);
                    argumentOrField4 = private19 + 2;
                    Level26_7FC74CompleteValue(argumentOrField4);
                    Level26_7FC74Field(owner18, unsigned char*, 0x48) = 3U;
                    argumentOrField5 = 1;
                    resultOrField2 = Level26_7FC74Field(private19, unsigned char*, 226);
                block_215:
                    Level26_7FC74Field(private19, unsigned char*, 2) = resultOrField2;
                    Level26_7FC74RegisterTrackedValue((void*)(argumentOrField4), argumentOrField5,
                                                      (void*)((int)&Level26_7FC74_D_8006C7F8));
                    return;
                }
                break;
            case 8:
                if (((Level26_7FC74Field(Level26_7FC74_D_8006C550 +
                                             Level26_7FC74Field(private19, int*, 168) * 88,
                                         unsigned char*, 72) &
                      128) &&
                     (Level26_7FC74Field(Level26_7FC74_D_8006C550 +
                                             Level26_7FC74Field(private19, int*, 172) * 88,
                                         unsigned char*, 72) &
                      128)) ||
                    Level26_7FC74TestPaddedRotatedBox((void*)((int)&Level26_7FC74_D_80070328),
                                                      (void*)(private19 + 184), 0, 0)) {
                    argumentOrField4 = owner18;
                    argumentOrField5 = 2;
                    resultOrField2 = 15;
                    Level26_7FC74Field(owner18, unsigned char*, 73) = resultOrField2;
                    goto actor1831LateCall;
                }
                return;
            case 15:
            case 16:
                argumentOrField4 = owner18;
                argumentOrField5 = 2;
                resultOrField2 = 9;
                Level26_7FC74Field(owner18, unsigned char*, 73) = resultOrField2;
                goto actor1831LateCall;
            case 9:
                if ((Level26_7FC74Field(Level26_7FC74_D_8006C550 +
                                            Level26_7FC74Field(private19, int*, 176) * 88,
                                        unsigned char*, 72) &
                     128) &&
                    (Level26_7FC74Field(Level26_7FC74_D_8006C550 +
                                            Level26_7FC74Field(private19, int*, 180) * 88,
                                        unsigned char*, 72) &
                     128)) {
                    argumentOrField4 = owner18;
                    goto actor1831LateOwnerReady;
                }
                resultOrField2 = Level26_7FC74TestPaddedRotatedBox(
                    (void*)((int)&Level26_7FC74_D_80070328), (void*)(private19 + 184), 0, 0);
                goto actor1831LateTest;
            case 10:
                fieldOrArithmetic3 = Level26_7FC74Field(private19, int*, 208);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(private19, "memory");
                resultOrField2 = fieldOrArithmetic3 * 2;
            actor1831LateScale:
                /* Original shared actor-index scale and class-flag read; no invented index bound. */
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 += fieldOrArithmetic3;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 *= 4;
                Level26_7FC74CompleteValue(resultOrField2);
                resultOrField2 -= fieldOrArithmetic3;
                Level26_7FC74CompleteValue(resultOrField2);
                fieldOrArithmetic3 = Level26_7FC74_D_8006C550;
                resultOrField2 *= 8;
                resultOrField2 += fieldOrArithmetic3;
                resultOrField2 = Level26_7FC74Field(resultOrField2, unsigned char*, 72);
                resultOrField2 &= 128;
            actor1831LateTest:
                if (resultOrField2 == 0)
                    return;
            actor1831LateOwner:
                argumentOrField4 = owner18;
            actor1831LateOwnerReady:
                argumentOrField5 = 2;
            actor1831LateCall:
                Level26_7FC74RequestMobyAnimation((void*)(argumentOrField4), argumentOrField5);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(private19, "memory");
                resultOrField2 = 3;
                Level26_7FC74Field(owner18, unsigned char*, 72) = resultOrField2;
                return;
            case 11:
                if ((Level26_7FC74_D_8006C7B4 & 1) && (Level26_7FC74_D_8006C7B4 & 4)) {
                    Level26_7FC74Field(private19, unsigned char*, 2) = 8U;
                    Level26_7FC74Field(owner18, unsigned char*, 0x49) =
                        (unsigned char)(Level26_7FC74Field(owner18, unsigned char*, 0x49) + 1);
                }
                break;
        }
    }
}
#undef Level26_7FC74Field
#undef Level26_7FC74CompleteValue

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80081910.
* Assembly SHA256 5d761a10779d63c88df2ddff7d9d7277fc00c0fc738c089a2841a382a06be2e7.
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
#define Actor26_81910Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor26_81910QueryWorldHeightView1() __asm__("func_8001A358");
int Actor26_81910RequestMobyAnimationView1() __asm__("func_80034F40");
int Actor26_81910UpdateMobyBallisticMotionView1() __asm__("func_80035030");
int Actor26_81910EmptyAnimationTransitionHookView1() __asm__("func_80035734");
int Actor26_81910TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor26_81910CountTimerDownView1() __asm__("func_800359A4");
int Actor26_81910ProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Actor26_81910ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Actor26_81910BlendBoundedAngle8StepView1() __asm__("func_800360F8");
int Actor26_81910RandSignedBetweenView1() __asm__("func_800363DC");
int Actor26_81910EmitMobyVertexParticlesView1() __asm__("func_800369B8");
int Actor26_81910PlayMobySoundEventView1() __asm__("func_8003BABC");
int Actor26_81910TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Actor26_81910SoundHandleMatchesOwnerInStates1Or2View1() __asm__("func_8003BFC0");
int Actor26_81910PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor26_81910MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Actor26_81910ComputeVectorPlaneResponseView1() __asm__("func_8004EF74");
int Actor26_81910ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Actor26_81910ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Actor26_81910CopyVectorView1() __asm__("func_8004F178");
int Actor26_81910AddVectorView1() __asm__("func_8004F194");
int Actor26_81910SubtractVectorView1() __asm__("func_8004F1C8");
int Actor26_81910ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor26_81910DeleteMobyView1() __asm__("func_80055B18");
int Actor26_81910RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Actor26_81910CallrandView1() __asm__("rand");
extern int Actor26_81910Data658A0View1 __asm__("D_800658A0");
extern int Actor26_81910Data65920View1 __asm__("D_80065920");
extern int Actor26_81910Data6C550View1 __asm__("D_8006C550");
extern int Actor26_81910Data6C770View1 __asm__("D_8006C770");
extern int Actor26_81910Data70328View1 __asm__("D_80070328");
extern int Actor26_81910Data71918View1 __asm__("D_80071918");
extern int Actor26_81910Data71920View1 __asm__("D_80071920");
extern void* (*Actor26_81910DataSpawnMobyView1)() __asm__("SpawnMoby");
void func_level_26_80081910(void* input) {
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
    rawWord2 = Actor26_81910Field(ownerRecord19, unsigned char*, 0x48);
    privateRecord20 = (int)Actor26_81910Field(ownerRecord19, void**, 0);
    if ((rawWord2 == rawWord3) || (Actor26_81910Field(ownerRecord19, unsigned char*, 0x4D) != 0)) {
        if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x49) == 0) {
            Actor26_81910Field(ownerRecord19, unsigned char*, 0x49) = 1U;
            rawWord2 = Actor26_81910ProbeGroundFromRaisedMobyView1(ownerRecord19) +
                       Actor26_81910Field(ownerRecord19, short*, 0x38);
            Actor26_81910Field(ownerRecord19, int*, 0x14) = rawWord2;
            Actor26_81910Field(privateRecord20, int*, 8) = rawWord2;
        }
        if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) != 1) {
            if (Actor26_81910SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord19, Actor26_81910Field(privateRecord20, int*, 0x24)) != 0) {
                Actor26_81910TransitionSoundHandleTo3Or5View1(
                    Actor26_81910Field(privateRecord20, int*, 0x24));
                Actor26_81910Field(privateRecord20, int*, 0x24) = -1;
            }
        }
        if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) != 3) {
            rawWord3 = Actor26_81910Field(ownerRecord19, int*, 0x18);
            if (rawWord3 & 0x10000) {
                Actor26_81910Field(privateRecord20, int*, 0x1C) = 0xFA;
                rawWord2 = Actor26_81910Field(ownerRecord19, unsigned char*, 0x51);
                argumentWord6 = 0;
                if (rawWord2 == 0) {
                    MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                    rawWord2 = Actor26_81910BlendBoundedAngle8StepView1(
                        Actor26_81910PlanarHeadingLookupView1(
                            Actor26_81910Field(ownerRecord19, int*, 0xC) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 0),
                            Actor26_81910Field(ownerRecord19, int*, 0x10) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 4),
                            argumentWord6),
                        Actor26_81910Field(((void*)&Actor26_81910Data70328View1), unsigned char*,
                                           0xE),
                        0x20, 0x40);
                }
                Actor26_81910Field(privateRecord20, int*, 0x18) = (int)rawWord2;
                Actor26_81910Field(privateRecord20, int*, 0x20) = 0xA4;
                rawWord2 = Actor26_81910Field(ownerRecord19, int*, 0x18);
                rawWord2 &= 0x100000;
                argumentWord4 = 16;
                if (rawWord2) {
                    Actor26_81910Field(privateRecord20, int*, 0x1C) =
                        (int)(Actor26_81910Field(privateRecord20, int*, 0x1C) + 0x64);
                    Actor26_81910Field(privateRecord20, int*, 0x20) =
                        (int)(Actor26_81910Field(privateRecord20, int*, 0x20) + 0x50);
                }
                rawWord2 = (int)Actor26_81910DataSpawnMobyView1;
                argumentWord5 = (int)ownerRecord19;
                goto callSharedSpawnHelper;
            }
            if (rawWord3 != 0) {
                Actor26_81910Field(privateRecord20, int*, 0x1C) = 0x12C;
                rawWord2 = Actor26_81910Field(ownerRecord19, unsigned char*, 0x51);
                if (rawWord2 == 0) {
                    MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                    rawWord2 = Actor26_81910BlendBoundedAngle8StepView1(
                        Actor26_81910PlanarHeadingLookupView1(
                            Actor26_81910Field(ownerRecord19, int*, 0xC) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 0),
                            Actor26_81910Field(ownerRecord19, int*, 0x10) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 4),
                            0),
                        Actor26_81910Field(((void*)&Actor26_81910Data70328View1), unsigned char*,
                                           0xE),
                        0x20, 0x40);
                }
                argumentWord4 = 16;
                argumentWord5 = (int)ownerRecord19;
                Actor26_81910Field(privateRecord20, int*, 0x18) = rawWord2;
                rawWord2 = (int)Actor26_81910DataSpawnMobyView1;
                rawWord3 = 164;
                Actor26_81910Field(privateRecord20, int*, 0x20) = rawWord3;
            callSharedSpawnHelper:
                ((void* (*)())rawWord2)(argumentWord4, argumentWord5);
                argumentWord4 = (int)ownerRecord19;
                argumentWord5 = 3;
                __asm__ __volatile__("" ::"r"(argumentWord4), "r"(argumentWord5) : "$2", "memory");
                rawWord2 = 3;
                Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
                Actor26_81910RequestMobyAnimationView1(argumentWord4, argumentWord5);
            }
        }
        rawWord3 = Actor26_81910Field(ownerRecord19, unsigned char*, 0x48);
        switch (rawWord3) {
            case 0:
                rawWord2 = Actor26_81910CountTimerDownView1(privateRecord20 + 0x14, 2);
                argumentWord4 = (int)&originalFrame.sp20;
                if (rawWord2 == 0)
                    goto state0CommonVectorReady;
                {
                    rawWord3 = Actor26_81910Field(privateRecord20, int*, 0xC);
                    MATCHING_KEEP_CLOBBER(rawWord3, "$21");
                    retainedShiftOrAddress21 = 3;
                    if (rawWord3 >= 0) {
                        Actor26_81910SubtractVectorView1(&originalFrame.sp40,
                                                         Actor26_81910Data6C550View1 +
                                                             (rawWord3 * 0x58) + 0xC,
                                                         ownerRecord19 + 0xC);
                        originalFrame.sp48 = 0;
                        retainedDistanceOrFlags18 =
                            Actor26_81910MeasureVectorLengthView1(&originalFrame.sp40, 0) >> 3;
                        if (retainedDistanceOrFlags18 < 0x60) {
                            rawWord2 = Actor26_81910CallrandView1();
                            retainedWordOrAddress16 = (int)&originalFrame.sp50;
                            if (rawWord2 & 1) {
                                MATCHING_OBSERVE_GNU_VOLATILE(retainedWordOrAddress16);
                                rawWord2 = Actor26_81910CallrandView1();
                                rawWord2 &= 127;
                                rawWord2 += 60;
                                Actor26_81910Field(privateRecord20, short*, 0x14) = rawWord2;
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
                        Actor26_81910SubtractVectorView1(retainedWordOrAddress16, privateRecord20,
                                                         ownerRecord19 + 12);
                        originalFrame.sp58 = 0;
                        rawWord2 =
                            Actor26_81910MeasureVectorLengthView1(retainedWordOrAddress16, 0);
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
                        Actor26_81910Field(privateRecord20, short*, 0x12) = 0;
                        Actor26_81910Field(privateRecord20, short*, 0x10) =
                            (short)((Actor26_81910CallrandView1() & 0xFF) + 0x200);
                        if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) != 1) {
                            Actor26_81910Data6C770View1 = 0;
                            Actor26_81910Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) = 1U;
                            Actor26_81910Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor26_81910EmptyAnimationTransitionHookView1(ownerRecord19);
                        }
                        Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = 5U;
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
                        Actor26_81910ScaleVectorRatioQ15View1(argumentWord4, argumentWord5,
                                                              argumentWord6);
                        Actor26_81910ShiftVectorRightTowardZeroView1(&originalFrame.sp50,
                                                                     retainedShiftOrAddress21 + 4);
                        Actor26_81910AddVectorView1(&originalFrame.sp40, &originalFrame.sp40,
                                                    &originalFrame.sp50);
                        if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) == 5) {
                            Actor26_81910Field(privateRecord20, int*, 0x18) =
                                Actor26_81910PlanarHeadingLookupView1(originalFrame.sp40,
                                                                      originalFrame.sp44, 0);
                        } else {
                            retainedWordOrAddress16 = Actor26_81910PlanarHeadingLookupView1(
                                originalFrame.sp40, originalFrame.sp44, 0);
                            Actor26_81910Field(privateRecord20, int*, 0x18) =
                                (int)(((retainedWordOrAddress16 +
                                        (Actor26_81910CallrandView1() & 0x1F)) -
                                       0x10) &
                                      0xFF);
                        }
                        Actor26_81910Field(privateRecord20, short*, 0x14) =
                            (short)((Actor26_81910CallrandView1() & 0x7F) + 0x3C);
                    } else {
                        rawWord2 = Actor26_81910CallrandView1(&originalFrame.sp20);
                        retainedWordOrAddress16 = (int)&originalFrame.sp60;
                        if (!(rawWord2 & 7)) {
                            MATCHING_OBSERVE_GNU_VOLATILE(retainedWordOrAddress16);
                            Actor26_81910Field(privateRecord20, short*, 0x14) =
                                (short)((Actor26_81910CallrandView1() & 0x7F) + 0x3C);
                            rawWord2 = 4;
                            goto storeSharedState;
                        }
                        argumentWord4 = retainedWordOrAddress16;
                        argumentWord5 = privateRecord20;
                        MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$17");
                        retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                        Actor26_81910SubtractVectorView1(argumentWord4, argumentWord5,
                                                         retainedWordOrAddress17);
                        originalFrame.sp68 = 0;
                        Actor26_81910ShiftVectorRightTowardZeroView1(&originalFrame.sp60, 3);
                        originalFrame.sp70 =
                            (int)(Actor26_81910Field(((void*)&Actor26_81910Data65920View1), short*,
                                                     ((Actor26_81910CallrandView1() & 0xFF) * 2)) *
                                  5) >>
                            2;
                        rawWord3 = Actor26_81910Field(((void*)&Actor26_81910Data658A0View1), short*,
                                                      ((Actor26_81910CallrandView1() & 0xFF) * 2));
                        originalFrame.sp78 = 0;
                        originalFrame.sp74 = (int)(rawWord3 * 5) >> 2;
                        Actor26_81910AddVectorView1(&originalFrame.sp70, &originalFrame.sp70,
                                                    &originalFrame.sp60);
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            Actor26_81910PlanarHeadingLookupView1(originalFrame.sp70,
                                                                  originalFrame.sp74, 0);
                        Actor26_81910Field(privateRecord20, short*, 0x14) =
                            (short)((Actor26_81910CallrandView1() & 0x7F) + 0x3C);
                        if ((Actor26_81910ApproximatePlanarDistanceView1(
                                 retainedWordOrAddress17, privateRecord20) >= 0x2001) &&
                            !(Actor26_81910CallrandView1() & 3)) {
                            Actor26_81910Field(privateRecord20, short*, 0x12) = 0;
                            Actor26_81910Field(privateRecord20, short*, 0x10) =
                                (short)((Actor26_81910CallrandView1(&originalFrame.sp20) & 0xFF) +
                                        0x200);
                            if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) != 1) {
                                Actor26_81910Data6C770View1 = 0;
                                Actor26_81910Field(ownerRecord19, signed char*, 0x40) = 0x72;
                                Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) = 1U;
                                Actor26_81910Field(ownerRecord19, signed char*, 0x3F) = 0;
                                Actor26_81910EmptyAnimationTransitionHookView1(ownerRecord19);
                            }
                            rawWord2 = 5;
                        storeSharedState:
                            Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
                        }
                    }
                }
                argumentWord4 = (int)&originalFrame.sp20;
            state0CommonVectorReady:
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$18");
                retainedDistanceOrFlags18 = (int)ownerRecord19 + 12;
                Actor26_81910CopyVectorView1(argumentWord4, retainedDistanceOrFlags18);
                Actor26_81910TurnMobyTowardHeadingView1(
                    ownerRecord19, Actor26_81910Field(privateRecord20, int*, 0x18), 6, 0, 0, 0);
                originalFrame.sp30 =
                    (int)(Actor26_81910Field(
                              ((void*)&Actor26_81910Data65920View1), short*,
                              (Actor26_81910Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.sp34 =
                    (int)(Actor26_81910Field(
                              ((void*)&Actor26_81910Data658A0View1), short*,
                              (Actor26_81910Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.sp38 = 0;
                Actor26_81910AddVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                            retainedDistanceOrFlags18);
                originalFrame.sp38 = Actor26_81910Field(ownerRecord19, int*, 0x14) + 0x100;
                rawWord2 = Actor26_81910QueryWorldHeightView1(&originalFrame.sp30, 0x400);
                originalFrame.sp38 = rawWord2;
                rawWord3 = Actor26_81910Field(ownerRecord19, int*, 0x14);
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
                    Actor26_81910Field(ownerRecord19, int*, 0x14) = rawWord2;
                    rawWord2 = 50;
                    retainedWordOrAddress17 = Actor26_81910ResolveMobyYawStepView1(
                        argumentWord4, argumentWord5, argumentWord6, argumentWord7, rawWord2);
                    if (retainedWordOrAddress17 & 0x10) {
                        Actor26_81910SubtractVectorView1(
                            &originalFrame.sp80, retainedDistanceOrFlags18, &originalFrame.sp20);
                        argumentWord5 =
                            Actor26_81910MeasureVectorLengthView1(&originalFrame.sp80, 1);
                        argumentWord4 = privateRecord20 + 0x16;
                        if (argumentWord5 >= 0x65) {
                            Actor26_81910ScaleVectorRatioQ15View1(&originalFrame.sp80,
                                                                  argumentWord5, 0x64);
                            Actor26_81910AddVectorView1(retainedDistanceOrFlags18,
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
                if (Actor26_81910CountTimerDownView1(argumentWord4, 2) != 0) {
                    Actor26_81910SubtractVectorView1(&originalFrame.sp90, ownerRecord19 + 0xC,
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
                        Actor26_81910Field(privateRecord20, short*, 0x16) = 0x3C;
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            (int)((Actor26_81910Field(privateRecord20, int*, 0x18) + 0x80) & 0xFF);
                        goto block_79;
                    }
                    if (({
                            rawWord2 = rawWord3 < 32;
                            MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
                            rawWord2;
                        })) {
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            Actor26_81910PlanarHeadingLookupView1(originalFrame.sp90,
                                                                  originalFrame.sp94, 0);
                        Actor26_81910Field(privateRecord20, short*, 0x16) = 5;
                    } else if (({
                                   rawWord2 = retainedWordOrAddress17 & 2;
                                   MATCHING_OBSERVE_GNU_VOLATILE(retainedWordOrAddress17);
                                   rawWord2;
                               })) {
                        retainedWordOrAddress16 = (int)&Actor26_81910Data71918View1;
                        MATCHING_KEEP(retainedWordOrAddress16);
                        argumentWord4 = Actor26_81910Field(retainedWordOrAddress16, int*, 0);
                        rawWord3 = Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                        rawWord2 = Actor26_81910Data71920View1;
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
                            rawWord2 = Actor26_81910Field(privateRecord20, int*, 0x18);
                            rawWord2 = (unsigned int)rawWord2 << 1;
                            rawWord2 =
                                Actor26_81910Field(&Actor26_81910Data65920View1, short*, rawWord2);
                            MATCHING_KEEP(rawWord2);
                            rawWord2 >>= 5;
                            originalFrame.sp90 = rawWord2;
                            __asm__ __volatile__("" ::: "$5", "memory");
                            rawWord2 = Actor26_81910Field(privateRecord20, int*, 0x18);
                            argumentWord5 = retainedWordOrAddress16;
                            rawWord2 = (unsigned int)rawWord2 << 1;
                            rawWord2 =
                                Actor26_81910Field(&Actor26_81910Data658A0View1, short*, rawWord2);
                            __asm__ __volatile__("" ::: "$6", "memory");
                            argumentWord6 = argumentWord4;
                            originalFrame.sp98 = 0;
                            __asm__ __volatile__(""
                                                 : "=r"(rawWord2)
                                                 : "0"(rawWord2), "m"(originalFrame.sp98)
                                                 : "memory");
                            rawWord2 >>= 5;
                            originalFrame.sp94 = rawWord2;
                            rawWord2 = Actor26_81910ComputeVectorPlaneResponseView1(
                                argumentWord4, argumentWord5, argumentWord6);
                            if (rawWord2 != 0) {
                                Actor26_81910Field(privateRecord20, int*, 0x18) =
                                    Actor26_81910PlanarHeadingLookupView1(originalFrame.sp90,
                                                                          originalFrame.sp94, 0);
                                rawWord2 = (short)(5);
                                goto block_78;
                            }
                            MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                            argumentWord4 = Actor26_81910Field(retainedWordOrAddress16, int*, 0);
                            if (argumentWord4 != 0 || ({
                                    rawWord2 = Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                                    rawWord2 != 0;
                                })) {
                                MATCHING_KEEP(retainedWordOrAddress16);
                                argumentWord5 =
                                    Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                                argumentWord6 = 0;
                                rawWord2 = Actor26_81910PlanarHeadingLookupView1(
                                    argumentWord4, argumentWord5, argumentWord6);
                                Actor26_81910Field(privateRecord20, int*, 0x18) = rawWord2;
                                rawWord2 = (short)(0x3C);
                            block_78:
                                Actor26_81910Field(privateRecord20, short*, 0x16) = rawWord2;
                            }
                        block_79:
                            Actor26_81910Field(privateRecord20, short*, 0x14) =
                                (short)((Actor26_81910CallrandView1() & 0x3F) + 0x1E);
                        }
                    }
                }
                rawWord2 = Actor26_81910ProbeGroundFromRaisedMobyView1(ownerRecord19) +
                           Actor26_81910Field(ownerRecord19, short*, 0x38);
                Actor26_81910Field(ownerRecord19, int*, 0x14) = rawWord2;
                rawWord2 = rawWord2 - originalFrame.sp28;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                argumentWord4 = ownerRecord19 + 0xC;
                if (rawWord2 >= 0x81) {
                    Actor26_81910CopyVectorView1(argumentWord4, &originalFrame.sp20);
                    MATCHING_KEEP(ownerRecord19);
                    argumentWord4 = ownerRecord19 + 0xC;
                }
                if (Actor26_81910ApproximatePlanarDistanceView1(
                        argumentWord4, ((void*)&Actor26_81910Data70328View1)) < 0x1000) {
                    Actor26_81910Field(privateRecord20, int*, 0x18) =
                        Actor26_81910PlanarHeadingLookupView1(
                            Actor26_81910Field(ownerRecord19, int*, 0xC) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 0),
                            Actor26_81910Field(ownerRecord19, int*, 0x10) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 4),
                            0);
                    Actor26_81910Field(privateRecord20, short*, 0x14) =
                        (short)((Actor26_81910CallrandView1() & 0x3F) + 0x1E);
                    Actor26_81910Field(privateRecord20, short*, 0x12) = 0;
                    rawWord2 = Actor26_81910CallrandView1();
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 1;
                    rawWord2 &= 127;
                    MATCHING_KEEP(rawWord2);
                    rawWord2 += 384;
                    goto storeTimerAndEnterState1;
                }
                break;
            case 4:
                if (Actor26_81910CountTimerDownView1(privateRecord20 + 0x14, 2) != 0) {
                    Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    return;
                }
                break;
            case 1:
                rawWord2 = Actor26_81910SoundHandleMatchesOwnerInStates1Or2View1(
                    ownerRecord19, Actor26_81910Field(privateRecord20, int*, 0x24));
                if (rawWord2 != 0) {
                    retainedShiftOrAddress21 = (int)&originalFrame.sp60;
                    goto state1VectorAddressReady;
                }
                MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                Actor26_81910Field(privateRecord20, int*, 0x24) =
                    Actor26_81910PlayMobySoundEventView1(ownerRecord19, 0, 4);
                retainedShiftOrAddress21 = (int)&originalFrame.sp60;
            state1VectorAddressReady:
                argumentWord4 = retainedShiftOrAddress21;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                Actor26_81910Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor26_81910Field(ownerRecord19, int*, 0x14) -
                          Actor26_81910Field(privateRecord20, short*, 0x12));
                Actor26_81910CopyVectorView1(argumentWord4, retainedWordOrAddress17);
                Actor26_81910TurnMobyTowardHeadingView1(
                    ownerRecord19, Actor26_81910Field(privateRecord20, int*, 0x18), 6, 0, 0, 0);
                originalFrame.spA0 =
                    (int)(Actor26_81910Field(
                              ((void*)&Actor26_81910Data65920View1), short*,
                              (Actor26_81910Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spA4 =
                    (int)(Actor26_81910Field(
                              ((void*)&Actor26_81910Data658A0View1), short*,
                              (Actor26_81910Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spA8 = 0;
                Actor26_81910AddVectorView1(&originalFrame.spA0, &originalFrame.spA0,
                                            retainedWordOrAddress17);
                originalFrame.spA8 = Actor26_81910Field(ownerRecord19, int*, 0x14) + 0x100;
                rawWord2 = Actor26_81910QueryWorldHeightView1(&originalFrame.spA0, 0x400);
                originalFrame.spA8 = rawWord2;
                if ((Actor26_81910Field(ownerRecord19, int*, 0x14) - rawWord2) < 0x100) {
                    retainedDistanceOrFlags18 = Actor26_81910ResolveMobyYawStepView1(
                        ownerRecord19, 0x91, 0x12C, 0x3E8, 0x36);
                    if (retainedDistanceOrFlags18 & 0x10) {
                        Actor26_81910SubtractVectorView1(
                            &originalFrame.spB0, retainedWordOrAddress17, retainedShiftOrAddress21);
                        argumentWord5 =
                            Actor26_81910MeasureVectorLengthView1(&originalFrame.spB0, 1);
                        if (argumentWord5 >= 0x92) {
                            Actor26_81910ScaleVectorRatioQ15View1(&originalFrame.spB0,
                                                                  argumentWord5, 0x91);
                            Actor26_81910AddVectorView1(retainedWordOrAddress17,
                                                        &originalFrame.spB0,
                                                        retainedShiftOrAddress21);
                        }
                    }
                } else {
                    retainedDistanceOrFlags18 = 0;
                }
                argumentWord5 = Actor26_81910Field(privateRecord20, short*, 0x12);
                argumentWord4 = Actor26_81910Field(privateRecord20, short*, 0x10);
                rawWord2 = argumentWord5 < argumentWord4;
                rawWord3 = argumentWord5;
                if (!rawWord2)
                    goto clamp0Reduce;
                rawWord2 = rawWord3 + 10;
                Actor26_81910Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor26_81910Field(privateRecord20, short*, 0x10);
                argumentWord4 = rawWord3;
                rawWord3 = rawWord3 < rawWord2;
                if (!rawWord3)
                    goto clamp0Done;
                Actor26_81910Field(privateRecord20, short*, 0x12) = argumentWord4;
                goto clamp0Done;
            clamp0Reduce:
                rawWord2 = argumentWord4 < argumentWord5;
                if (!rawWord2)
                    goto clamp0Done;
                rawWord2 = rawWord3 - 10;
                Actor26_81910Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor26_81910Field(privateRecord20, short*, 0x10);
                rawWord2 = rawWord2 < rawWord3;
                argumentWord4 = rawWord3;
                if (!rawWord2)
                    goto clamp0Done;
                Actor26_81910Field(privateRecord20, short*, 0x12) = argumentWord4;
            clamp0Done:
                if (Actor26_81910CountTimerDownView1(privateRecord20 + 0x16, 2) != 0) {
                    argumentWord4 = (int)&originalFrame.spC0;
                    __asm__ __volatile__(""
                                         : "=r"(retainedShiftOrAddress21)
                                         : "0"(retainedShiftOrAddress21), "r"(argumentWord4)
                                         : "$6", "memory");
                    Actor26_81910SubtractVectorView1(argumentWord4, ownerRecord19 + 12,
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
                        Actor26_81910Field(privateRecord20, short*, 0x16) = 0x3C;
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            (int)((Actor26_81910Field(privateRecord20, int*, 0x18) + 0x80) & 0xFF);
                    } else {
                        if (({
                                rawWord2 = rawWord3 < 32;
                                MATCHING_OBSERVE_GNU_VOLATILE(rawWord3);
                                rawWord2;
                            })) {
                            rawWord2 = Actor26_81910PlanarHeadingLookupView1(originalFrame.spC0,
                                                                             originalFrame.spC4, 0);
                            Actor26_81910Field(privateRecord20, int*, 0x18) = rawWord2;
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
                            retainedWordOrAddress16 = (int)&Actor26_81910Data71918View1;
                            MATCHING_KEEP(retainedWordOrAddress16);
                            argumentWord4 = Actor26_81910Field(retainedWordOrAddress16, int*, 0);
                            rawWord3 = Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                            rawWord2 = Actor26_81910Data71920View1;
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
                                rawWord2 = Actor26_81910Field(privateRecord20, int*, 0x18);
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor26_81910Field(&Actor26_81910Data65920View1, short*,
                                                              rawWord2);
                                MATCHING_KEEP(rawWord2);
                                rawWord2 >>= 5;
                                originalFrame.spC0 = rawWord2;
                                __asm__ __volatile__("" ::: "$5", "memory");
                                rawWord2 = Actor26_81910Field(privateRecord20, int*, 0x18);
                                argumentWord5 = retainedWordOrAddress16;
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor26_81910Field(&Actor26_81910Data658A0View1, short*,
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
                                rawWord2 = Actor26_81910ComputeVectorPlaneResponseView1(
                                    argumentWord4, argumentWord5, argumentWord6);
                                if (rawWord2 != 0) {
                                    Actor26_81910Field(privateRecord20, int*, 0x18) =
                                        Actor26_81910PlanarHeadingLookupView1(
                                            originalFrame.spC0, originalFrame.spC4, 0);
                                    rawWord2 = (short)(5);
                                    goto block_123;
                                }
                                MATCHING_KEEP_GNU_VOLATILE(rawWord2);
                                argumentWord4 =
                                    Actor26_81910Field(retainedWordOrAddress16, int*, 0);
                                if (argumentWord4 != 0 || ({
                                        rawWord2 =
                                            Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                                        rawWord2 != 0;
                                    })) {
                                    MATCHING_KEEP(retainedWordOrAddress16);
                                    argumentWord5 =
                                        Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                                    argumentWord6 = 0;
                                    rawWord2 = Actor26_81910PlanarHeadingLookupView1(
                                        argumentWord4, argumentWord5, argumentWord6);
                                    Actor26_81910Field(privateRecord20, int*, 0x18) = rawWord2;
                                    rawWord2 = (short)(0x3C);
                                block_123:
                                    Actor26_81910Field(privateRecord20, short*, 0x16) = rawWord2;
                                }
                            }
                        }
                    }
                }
                rawWord2 = Actor26_81910Field(ownerRecord19, int*, 0x14);
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
                    Actor26_81910CopyVectorView1(ownerRecord19 + 12, &originalFrame.sp60);
                    MATCHING_KEEP(privateRecord20);
                    argumentWord4 = privateRecord20 + 0x14;
                }
                Actor26_81910Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor26_81910Field(ownerRecord19, int*, 0x14) +
                          Actor26_81910Field(privateRecord20, short*, 0x12));
                if (Actor26_81910CountTimerDownView1(argumentWord4, 2) != 0) {
                    if (Actor26_81910ApproximatePlanarDistanceView1(
                            ownerRecord19 + 0xC, ((void*)&Actor26_81910Data70328View1)) >= 0x1801) {
                        Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                        Actor26_81910RequestMobyAnimationView1(ownerRecord19, 2);
                        return;
                    }
                    rawWord2 = Actor26_81910PlanarHeadingLookupView1(
                        Actor26_81910Field(ownerRecord19, int*, 0xC) -
                            Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 0),
                        Actor26_81910Field(ownerRecord19, int*, 0x10) -
                            Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 4),
                        0);
                    argumentWord4 = 32;
                    argumentWord5 = 64;
                    __asm__(""
                            : "=r"(rawWord2)
                            : "0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5));
                    retainedWordOrAddress16 = rawWord2;
                    rawWord2 = Actor26_81910RandSignedBetweenView1(argumentWord4, argumentWord5);
                    retainedWordOrAddress16 = (unsigned int)retainedWordOrAddress16 + rawWord2;
                    retainedWordOrAddress16 &= 255;
                    MATCHING_KEEP(retainedWordOrAddress16);
                    Actor26_81910Field(privateRecord20, int*, 0x18) = retainedWordOrAddress16;
                    Actor26_81910Field(privateRecord20, short*, 0x14) =
                        (short)((Actor26_81910CallrandView1() & 0x3F) + 0x1E);
                    Actor26_81910Field(privateRecord20, short*, 0x10) =
                        (short)((Actor26_81910CallrandView1() & 0x7F) + 0x180);
                    return;
                }
                break;
            case 2:
                rawWord3 = Actor26_81910Field(privateRecord20, short*, 0x12);
                rawWord2 = Actor26_81910Field(ownerRecord19, int*, 0x14);
                rawWord2 -= rawWord3;
                Actor26_81910Field(ownerRecord19, int*, 0x14) = rawWord2;
                rawWord3 = Actor26_81910Field(privateRecord20, short*, 0x12);
                rawWord2 = (unsigned int)rawWord3 << 1;
                rawWord2 += rawWord3;
                rawWord3 = Actor26_81910Data6C770View1;
                argumentWord4 = rawWord2 >> 2;
                Actor26_81910Field(privateRecord20, short*, 0x12) = argumentWord4;
                if (rawWord3 != 0) {
                    if (Actor26_81910ApproximatePlanarDistanceView1(ownerRecord19 + 0xC,
                                                                    privateRecord20) >= 0x2801) {
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            Actor26_81910PlanarHeadingLookupView1(
                                Actor26_81910Field(privateRecord20, int*, 0) -
                                    Actor26_81910Field(ownerRecord19, int*, 0xC),
                                Actor26_81910Field(privateRecord20, int*, 4) -
                                    Actor26_81910Field(ownerRecord19, int*, 0x10),
                                0);
                    } else {
                        rawWord2 = Actor26_81910CallrandView1();
                        argumentWord6 = 0;
                        __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord6));
                        retainedWordOrAddress16 = rawWord2;
                        argumentWord7 = Actor26_81910Field(privateRecord20, int*, 0);
                        argumentWord4 = Actor26_81910Field(ownerRecord19, int*, 0xC);
                        rawWord3 = Actor26_81910Field(privateRecord20, int*, 4);
                        argumentWord5 = Actor26_81910Field(ownerRecord19, int*, 0x10);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = rawWord3 - argumentWord5;
                        rawWord2 = Actor26_81910PlanarHeadingLookupView1(
                            argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                        retainedWordOrAddress16 = (unsigned int)retainedWordOrAddress16 + rawWord2;
                        retainedWordOrAddress16 >>= 1;
                        retainedWordOrAddress16 &= 255;
                        MATCHING_KEEP(retainedWordOrAddress16);
                        Actor26_81910Field(privateRecord20, int*, 0x18) = retainedWordOrAddress16;
                    }
                    Actor26_81910Field(privateRecord20, short*, 0x14) =
                        (short)((Actor26_81910CallrandView1() & 0x7F) + 0x3C);
                    Actor26_81910Field(privateRecord20, short*, 0x12) = 0;
                    Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                    Actor26_81910RequestMobyAnimationView1(ownerRecord19, 0);
                    return;
                }
                Actor26_81910Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor26_81910Field(ownerRecord19, int*, 0x14) + argumentWord4);
                return;
            case 5:
                rawWord2 = Actor26_81910CountTimerDownView1(privateRecord20 + 0x14, 2);
                retainedShiftOrAddress21 = (int)&originalFrame.spD0;
                if (rawWord2 == 0)
                    goto mode5VectorReady;
                rawWord3 = Actor26_81910Field(privateRecord20, int*, 0xC);
                retainedShiftOrAddress21 = 3;
                if (rawWord3 >= 0) {
                    retainedWordOrAddress16 = (int)&originalFrame.spF0;
                    argumentWord4 = retainedWordOrAddress16;
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                    retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                    Actor26_81910SubtractVectorView1(
                        argumentWord4, Actor26_81910Data6C550View1 + rawWord3 * 88 + 12,
                        retainedWordOrAddress17);
                    originalFrame.spF8 = 0;
                    retainedDistanceOrFlags18 =
                        Actor26_81910MeasureVectorLengthView1(&originalFrame.spF0, 0) >> 3;
                    Actor26_81910SubtractVectorView1(&originalFrame.sp100, privateRecord20,
                                                     retainedWordOrAddress17);
                    originalFrame.sp108 = 0;
                    rawWord2 = Actor26_81910MeasureVectorLengthView1(&originalFrame.sp100, 0);
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
                    if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) != 2) {
                        Actor26_81910Data6C770View1 = 0;
                        Actor26_81910Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) = 2U;
                        Actor26_81910Field(ownerRecord19, signed char*, 0x3F) = 0;
                        Actor26_81910EmptyAnimationTransitionHookView1(ownerRecord19);
                    }
                    Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = 2U;
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
                    Actor26_81910ScaleVectorRatioQ15View1(argumentWord4, argumentWord5,
                                                          argumentWord6);
                    Actor26_81910ShiftVectorRightTowardZeroView1(&originalFrame.sp100,
                                                                 retainedShiftOrAddress21 + 4);
                    Actor26_81910AddVectorView1(&originalFrame.spF0, &originalFrame.spF0,
                                                &originalFrame.sp100);
                    Actor26_81910Field(privateRecord20, int*, 0x18) =
                        Actor26_81910PlanarHeadingLookupView1(originalFrame.spF0,
                                                              originalFrame.spF4, 0);
                    Actor26_81910Field(privateRecord20, short*, 0x14) =
                        (short)((Actor26_81910CallrandView1() & 0x7F) + 0x3C);
                    Actor26_81910Field(privateRecord20, short*, 0x10) =
                        (short)((Actor26_81910CallrandView1() & 0xFF) + 0x200);
                } else {
                    retainedWordOrAddress16 = (int)&originalFrame.sp110;
                    argumentWord4 = retainedWordOrAddress16;
                    argumentWord5 = privateRecord20;
                    MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$17");
                    retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                    Actor26_81910SubtractVectorView1(argumentWord4, argumentWord5,
                                                     retainedWordOrAddress17);
                    originalFrame.sp118 = 0;
                    Actor26_81910ShiftVectorRightTowardZeroView1(&originalFrame.sp110, 3);
                    originalFrame.sp120 =
                        (int)(Actor26_81910Field(((void*)&Actor26_81910Data65920View1), short*,
                                                 ((Actor26_81910CallrandView1() & 0xFF) * 2)) *
                              5) >>
                        2;
                    rawWord3 = Actor26_81910Field(((void*)&Actor26_81910Data658A0View1), short*,
                                                  ((Actor26_81910CallrandView1() & 0xFF) * 2));
                    originalFrame.sp128 = 0;
                    originalFrame.sp124 = (int)(rawWord3 * 5) >> 2;
                    Actor26_81910AddVectorView1(&originalFrame.sp120, &originalFrame.sp120,
                                                &originalFrame.sp110);
                    Actor26_81910Field(privateRecord20, int*, 0x18) =
                        Actor26_81910PlanarHeadingLookupView1(originalFrame.sp120,
                                                              originalFrame.sp124, 0);
                    Actor26_81910Field(privateRecord20, short*, 0x14) =
                        (short)((Actor26_81910CallrandView1() & 0x7F) + 0x3C);
                    if ((Actor26_81910ApproximatePlanarDistanceView1(retainedWordOrAddress17,
                                                                     privateRecord20) < 0x2000) ||
                        !(Actor26_81910CallrandView1() & 3)) {
                        if (Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) != 2) {
                            Actor26_81910Data6C770View1 = 0;
                            Actor26_81910Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor26_81910Field(ownerRecord19, unsigned char*, 0x3D) = 2U;
                            Actor26_81910Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor26_81910EmptyAnimationTransitionHookView1(ownerRecord19);
                        }
                        Actor26_81910Field(ownerRecord19, unsigned char*, 0x48) = 2U;
                    }
                }
                retainedShiftOrAddress21 = (int)&originalFrame.spD0;
            mode5VectorReady:
                argumentWord4 = retainedShiftOrAddress21;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
                retainedWordOrAddress17 = (int)ownerRecord19 + 12;
                Actor26_81910Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor26_81910Field(ownerRecord19, int*, 0x14) -
                          Actor26_81910Field(privateRecord20, short*, 0x12));
                Actor26_81910CopyVectorView1(argumentWord4, retainedWordOrAddress17);
                Actor26_81910TurnMobyTowardHeadingView1(
                    ownerRecord19, Actor26_81910Field(privateRecord20, int*, 0x18), 6, 0, 0, 0);
                originalFrame.spE0 =
                    (int)(Actor26_81910Field(
                              ((void*)&Actor26_81910Data65920View1), short*,
                              (Actor26_81910Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spE4 =
                    (int)(Actor26_81910Field(
                              ((void*)&Actor26_81910Data658A0View1), short*,
                              (Actor26_81910Field(ownerRecord19, unsigned char*, 0x46) * 2)) *
                          0x99) >>
                    0xA;
                originalFrame.spE8 = 0;
                Actor26_81910AddVectorView1(&originalFrame.spE0, &originalFrame.spE0,
                                            retainedWordOrAddress17);
                originalFrame.spE8 = Actor26_81910Field(ownerRecord19, int*, 0x14) + 0x100;
                rawWord2 = Actor26_81910QueryWorldHeightView1(&originalFrame.spE0, 0x400);
                originalFrame.spE8 = rawWord2;
                if ((Actor26_81910Field(ownerRecord19, int*, 0x14) - rawWord2) < 0x100) {
                    retainedDistanceOrFlags18 = Actor26_81910ResolveMobyYawStepView1(
                        ownerRecord19, 0x91, 0x12C, 0x3E8, 0x36);
                    if (retainedDistanceOrFlags18 & 0x10) {
                        Actor26_81910SubtractVectorView1(&originalFrame.sp130,
                                                         retainedWordOrAddress17,
                                                         retainedShiftOrAddress21);
                        argumentWord5 =
                            Actor26_81910MeasureVectorLengthView1(&originalFrame.sp130, 1);
                        if (argumentWord5 >= 0x92) {
                            Actor26_81910ScaleVectorRatioQ15View1(&originalFrame.sp130,
                                                                  argumentWord5, 0x91);
                            Actor26_81910AddVectorView1(retainedWordOrAddress17,
                                                        &originalFrame.sp130,
                                                        retainedShiftOrAddress21);
                        }
                    }
                } else {
                    retainedDistanceOrFlags18 = 0;
                }
                argumentWord5 = Actor26_81910Field(privateRecord20, short*, 0x12);
                argumentWord4 = Actor26_81910Field(privateRecord20, short*, 0x10);
                rawWord2 = argumentWord5 < argumentWord4;
                rawWord3 = argumentWord5;
                if (!rawWord2)
                    goto clamp1Reduce;
                rawWord2 = rawWord3 + 10;
                Actor26_81910Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor26_81910Field(privateRecord20, short*, 0x10);
                argumentWord4 = rawWord3;
                rawWord3 = rawWord3 < rawWord2;
                if (!rawWord3)
                    goto clamp1Done;
                Actor26_81910Field(privateRecord20, short*, 0x12) = argumentWord4;
                goto clamp1Done;
            clamp1Reduce:
                rawWord2 = argumentWord4 < argumentWord5;
                if (!rawWord2)
                    goto clamp1Done;
                rawWord2 = rawWord3 - 10;
                Actor26_81910Field(privateRecord20, short*, 0x12) = rawWord2;
                MATCHING_KEEP(privateRecord20);
                rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
                rawWord3 = Actor26_81910Field(privateRecord20, short*, 0x10);
                rawWord2 = rawWord2 < rawWord3;
                argumentWord4 = rawWord3;
                if (!rawWord2)
                    goto clamp1Done;
                Actor26_81910Field(privateRecord20, short*, 0x12) = argumentWord4;
            clamp1Done:
                if (Actor26_81910CountTimerDownView1(privateRecord20 + 0x16, 2) != 0) {
                    argumentWord4 = (int)&originalFrame.sp140;
                    __asm__ __volatile__(""
                                         : "=r"(retainedShiftOrAddress21)
                                         : "0"(retainedShiftOrAddress21), "r"(argumentWord4)
                                         : "$6", "memory");
                    Actor26_81910SubtractVectorView1(argumentWord4, ownerRecord19 + 12,
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
                        Actor26_81910Field(privateRecord20, short*, 0x16) = 0x3C;
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            (int)((Actor26_81910Field(privateRecord20, int*, 0x18) + 0x80) & 0xFF);
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
                            retainedWordOrAddress16 = (int)&Actor26_81910Data71918View1;
                            MATCHING_KEEP(retainedWordOrAddress16);
                            argumentWord4 = Actor26_81910Field(retainedWordOrAddress16, int*, 0);
                            rawWord3 = Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                            rawWord2 = Actor26_81910Data71920View1;
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
                                rawWord2 = Actor26_81910Field(privateRecord20, int*, 0x18);
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor26_81910Field(&Actor26_81910Data65920View1, short*,
                                                              rawWord2);
                                MATCHING_KEEP(rawWord2);
                                rawWord2 >>= 5;
                                originalFrame.sp140 = rawWord2;
                                __asm__ __volatile__("" ::: "$5", "memory");
                                rawWord2 = Actor26_81910Field(privateRecord20, int*, 0x18);
                                argumentWord5 = retainedWordOrAddress16;
                                rawWord2 = (unsigned int)rawWord2 << 1;
                                rawWord2 = Actor26_81910Field(&Actor26_81910Data658A0View1, short*,
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
                                rawWord2 = Actor26_81910ComputeVectorPlaneResponseView1(
                                    argumentWord4, argumentWord5, argumentWord6);
                                if (rawWord2 != 0) {
                                    argumentWord4 = originalFrame.sp140;
                                    argumentWord5 = originalFrame.sp144;
                                    goto block_188;
                                }
                                argumentWord4 =
                                    Actor26_81910Field(retainedWordOrAddress16, int*, 0);
                                if ((argumentWord4 != 0) ||
                                    (Actor26_81910Field(retainedWordOrAddress16, int*, 4) != 0)) {
                                    argumentWord5 =
                                        Actor26_81910Field(retainedWordOrAddress16, int*, 4);
                                    goto block_188;
                                }
                            }
                            goto block_190;
                        }
                    } else {
                    block_188:
                        Actor26_81910Field(privateRecord20, int*, 0x18) =
                            Actor26_81910PlanarHeadingLookupView1(argumentWord4, argumentWord5, 0);
                    block_190:
                        Actor26_81910Field(privateRecord20, short*, 0x16) = 5;
                    }
                }
                rawWord2 = Actor26_81910Field(ownerRecord19, int*, 0x14);
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
                    Actor26_81910CopyVectorView1(argumentWord4, &originalFrame.spD0);
                    MATCHING_KEEP(ownerRecord19);
                    argumentWord4 = ownerRecord19 + 0xC;
                }
                Actor26_81910Field(ownerRecord19, int*, 0x14) =
                    (int)(Actor26_81910Field(ownerRecord19, int*, 0x14) +
                          Actor26_81910Field(privateRecord20, short*, 0x12));
                if (Actor26_81910ApproximatePlanarDistanceView1(
                        argumentWord4, ((void*)&Actor26_81910Data70328View1)) < 0x1000) {
                    Actor26_81910Field(privateRecord20, int*, 0x18) =
                        Actor26_81910PlanarHeadingLookupView1(
                            Actor26_81910Field(ownerRecord19, int*, 0xC) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 0),
                            Actor26_81910Field(ownerRecord19, int*, 0x10) -
                                Actor26_81910Field(((void*)&Actor26_81910Data70328View1), int*, 4),
                            0);
                    Actor26_81910Field(privateRecord20, short*, 0x14) =
                        (short)((Actor26_81910CallrandView1() & 0x3F) + 0x1E);
                    rawWord2 = Actor26_81910CallrandView1();
                    argumentWord4 = (int)ownerRecord19;
                    argumentWord5 = 1;
                    rawWord2 &= 255;
                    MATCHING_KEEP(rawWord2);
                    rawWord2 += 512;
                storeTimerAndEnterState1:
                    Actor26_81910Field(privateRecord20, short*, 0x10) = rawWord2;
                    rawWord2 = 1;
                    Actor26_81910Field(argumentWord4, unsigned char*, 0x48) = rawWord2;
                    Actor26_81910RequestMobyAnimationView1(argumentWord4, argumentWord5);
                    return;
                }
                break;
            case 3:
                Actor26_81910UpdateMobyBallisticMotionView1(
                    ownerRecord19, privateRecord20 + 0x1C,
                    Actor26_81910Field(privateRecord20, int*, 0x18), privateRecord20 + 0x20, 0xC,
                    0x10, 0x140, 1);
                if (Actor26_81910Data6C770View1 != 0) {
                    Actor26_81910RefreshMobySpatialGridAndBasisView1(ownerRecord19, 4);
                    Actor26_81910EmitMobyVertexParticlesView1(ownerRecord19, 0x18);
                    Actor26_81910DeleteMobyView1(ownerRecord19);
                }
                break;
        }
    } else {
    }
}
#undef Actor26_81910Field

void func_level_26_80082EFC(Moby* moby) {
    func_80039714(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80082F1C.
* Assembly SHA256 4052c693ae6e16ee264cd01b4971fbe533b8c5c1d345576b825329e7e9be59ec.
* AI generated;not human reviewed. All783 instructions/100 selectors and
* every actual native/linked target must match. FrameB8 preserves S0..S7/
* RA and full SP18..8F local extent. Original signed bit15 timer branches,
* three independently executed clear tails,frame18/28/38/48/58/68 vectors,
* retained player/record pointers and all raw byte offsets remain exact.
* Empty tied owner/memory operands preserve original clear-write order.
* Their immediate0/96/97 inputs identify the original case contexts for
* compiler metadata;the empty templates emit zero CPU instructions.
* State2/state3 enter the shared1A358 call after state5's A0=S0 producer.
* Actual state3 jumps315/324 retain the original A0 reload entry356.
* Original two-input spawn view and no-input rand view remove synthetic
* decoder arguments. Native rand8005C644..670 reads its seed global and
* overwrites A0 before any incoming A0 read. F1108004F110..164 reads only
* A0/A1 and overwrites A2 before reading it. All original argument-register
* values/producers,indirect targets,signed LH/trig words and call delays
* still match. State99 preloaded player records,independent signed scratch
* values,position stores,1/32/10/minus1/96/97 producers and shared call/store
* entries retain every native word and target. Initialized empty metadata
* emits zero;no opcode assembly,partialHI,fixedFP,unknown saved-register
* inputs or overlapping live aliases. Raw units/fixed point,remaining full
* helper contracts,caller cadence and synchronized retail runtime remain
* open. Cadence is per invocation;confidence is Rev0 binary identity after
* all gates. Falsification:every native/linked word/actual transfer,all100
* selector targets,full EXE and every overlay retail hash must match.
*/
#define Level26_82F1CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level26_82F1CQueryWorldSegmentView1() __asm__("func_80018368");
int Level26_82F1CQueryWorldSphereView1() __asm__("func_80019194");
int Level26_82F1CQueryWorldHeightView1() __asm__("func_8001A358");
int Level26_82F1CQueryDynamicMobyGeometryView1() __asm__("func_8001BA30");
int Level26_82F1CMaskLinkedRecordFlagsByIdView1() __asm__("func_80021ED8");
int Level26_82F1CWriteMatchingLinkedSelectorsView1() __asm__("func_80021F8C");
int Level26_82F1CProbeGroundFromRaisedMobyView1() __asm__("func_80035D38");
int Level26_82F1CRegisterTrackedValueView1() __asm__("func_8003B7B4");
int Level26_82F1CPlayMobySoundEventView1() __asm__("func_8003BABC");
int Level26_82F1CGetSurfaceTypeFromFlagsView1() __asm__("func_80040954");
int Level26_82F1CMeasureVectorLengthView1() __asm__("func_8004EDE8");
int Level26_82F1CScaleVectorRatioQ15View1() __asm__("func_8004F08C");
void Level26_82F1CShiftVectorRightTowardZeroView1(void*, int) __asm__("func_8004F110");
int Level26_82F1CCopyVectorView1() __asm__("func_8004F178");
int Level26_82F1CAddVectorView1() __asm__("func_8004F194");
int Level26_82F1CSubtractVectorView1() __asm__("func_8004F1C8");
int Level26_82F1CApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level26_82F1CRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level26_82F1CRefreshMobyPackedQueryFieldView1() __asm__("func_8005629C");
int Level26_82F1CDatarandView1(void) __asm__("rand");
extern int Level26_82F1CData658A0View1 __asm__("D_800658A0");
extern int Level26_82F1CData65920View1 __asm__("D_80065920");
extern int Level26_82F1CData6C550View1 __asm__("D_8006C550");
extern unsigned char Level26_82F1CData6C62CView1 __asm__("D_8006C62C");
extern int Level26_82F1CData6C7F8View1 __asm__("D_8006C7F8");
extern int Level26_82F1CData6E020View1 __asm__("D_8006E020");
extern int Level26_82F1CData6E024View1 __asm__("D_8006E024");
extern int Level26_82F1CData6E044View1 __asm__("D_8006E044");
extern int Level26_82F1CData70328View1 __asm__("D_80070328");
extern int Level26_82F1CData71900View1 __asm__("D_80071900");
extern int Level26_82F1CData7190CView1 __asm__("D_8007190C");
extern int Level26_82F1CData71924View1 __asm__("D_80071924");
extern void* (*Level26_82F1CDataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern int (*Level26_82F1CDataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_26_80082F1C(void* input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void* ownerRecord18 __asm__("$18");
    register int privateRecord19 __asm__("$19"), addressOrResult16 __asm__("$16"),
        retainedVectorOrRecord17 __asm__("$17"), retainedVectorOrRecord20 __asm__("$20"),
        retainedFlag21 __asm__("$21"), retainedOwnerVector23 __asm__("$23");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84,
            sp88, sp8C;
    } originalFrame;
    ownerRecord18 = input;
    MATCHING_KEEP(ownerRecord18);
    rawWord3 = Level26_82F1CField(ownerRecord18, unsigned char*, 0x48);
    privateRecord19 = Level26_82F1CField(ownerRecord18, void**, 0);
    switch (rawWord3) {
        case 0:
            rawWord2 = Level26_82F1CField(privateRecord19, int*, 0x18);
            if (rawWord2 >= 0) {
                rawWord2 = 99;
                goto clearOriginalStateZero;
            }
            rawWord2 = Level26_82F1CField(privateRecord19, int*, 0x1C);
            if (rawWord2 < 0)
                goto loadOriginalStateOne;
            rawWord2 = 99;
        clearOriginalStateZero:
            Level26_82F1CField(ownerRecord18, signed char*, 0x4D) = 0;
            __asm__(""
                    : "=r"(ownerRecord18)
                    : "0"(ownerRecord18),
                      "m"(Level26_82F1CField(ownerRecord18, unsigned char*, 0x4D)), "i"(0));
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C) = 0;
            __asm__(""
                    : "=r"(ownerRecord18)
                    : "0"(ownerRecord18),
                      "m"(Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C)), "i"(0));
            Level26_82F1CField(ownerRecord18, int*, 8) = 0;
            goto storeOriginalFinalState;
        loadOriginalStateOne:
            rawWord2 = 1;
            goto storeOriginalFinalState;
        default:
            return;
        case 0x1:
            retainedVectorOrRecord17 = 0;
            if ((unsigned int)(Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x50) -
                               7) >= 2U) {
                if (Level26_82F1CApproximatePlanarDistanceView1(
                        ownerRecord18 + 0xC, ((int)&Level26_82F1CData70328View1 + 0x50) - 0x50) <
                    0x200) {
                    rawWord2 =
                        ((Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 8) -
                          Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x44)) -
                         Level26_82F1CField(ownerRecord18, int*, 0x14)) -
                        Level26_82F1CField(ownerRecord18, short*, 0x38);
                    if (rawWord2 < 0) {
                        rawWord2 = -rawWord2;
                    }
                    if (rawWord2 < 0x200) {
                        addressOrResult16 = Level26_82F1CField(
                            Level26_82F1CField((int)&Level26_82F1CData70328View1, void**, 0x250),
                            int*, 0);
                        if ((Level26_82F1CField(addressOrResult16, void**, 0x30) == 0) &&
                            (Level26_82F1CData6C62CView1 & 2)) {
                            Level26_82F1CPlayMobySoundEventView1(
                                Level26_82F1CField((int)&Level26_82F1CData70328View1, void**,
                                                   0x250),
                                1, 0);
                            Level26_82F1CField(addressOrResult16, void**, 0x30) = ownerRecord18;
                            Level26_82F1CField(addressOrResult16, int*, 0x34) = 1;
                            Level26_82F1CField(privateRecord19, short*, 0x14) =
                                (short)(Level26_82F1CField(ownerRecord18, unsigned char*, 0x46) -
                                        Level26_82F1CField((int)&Level26_82F1CData70328View1,
                                                           unsigned char*, 0xE));
                            Level26_82F1CField(ownerRecord18, int*, 8) = 0;
                            Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = 2U;
                        }
                    }
                }
            }
            argumentWord4 = (int)&originalFrame.sp18;
            MATCHING_KEEP_CLOBBER(argumentWord4, "$16");
            addressOrResult16 = (int)ownerRecord18 + 12;
            Level26_82F1CCopyVectorView1(argumentWord4, addressOrResult16);
            originalFrame.sp20 += 0x140;
            if (Level26_82F1CQueryDynamicMobyGeometryView1(&originalFrame.sp18, 0x140, 0, 0, 0,
                                                           ownerRecord18) != 0) {
                Level26_82F1CCopyVectorView1(&originalFrame.sp18,
                                             (int)&Level26_82F1CData7190CView1);
                retainedVectorOrRecord17 = 1;
            }
            if (Level26_82F1CQueryWorldSphereView1(&originalFrame.sp18, 0x140) != 0) {
                Level26_82F1CCopyVectorView1(&originalFrame.sp18,
                                             (int)&Level26_82F1CData7190CView1);
                retainedVectorOrRecord17 = 1;
            }
            if (retainedVectorOrRecord17 != 0) {
                originalFrame.sp20 -= 0x140;
                Level26_82F1CCopyVectorView1(addressOrResult16, &originalFrame.sp18);
                if (Level26_82F1CQueryWorldHeightView1(&originalFrame.sp18, 0x1C0) == 0) {
                    Level26_82F1CField(privateRecord19, int*, 0x10) = 0;
                    Level26_82F1CField(ownerRecord18, unsigned char*, 0x49) = 3U;
                    return;
                }
            }
            break;
        case 2:
            argumentWord4 = Level26_82F1CField(privateRecord19, short*, 0x14);
            rawWord2 = Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x250);
            retainedVectorOrRecord20 = Level26_82F1CField(rawWord2, int*, 0);
            rawWord3 = argumentWord4;
            if (argumentWord4 != 0) {
                if (argumentWord4 > 0) {
                    rawWord2 = rawWord3 - 4;
                    Level26_82F1CField(privateRecord19, short*, 0x14) = rawWord2;
                    rawWord2 <<= 16;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 < 0)
                        Level26_82F1CField(privateRecord19, short*, 0x14) = 0;
                } else {
                    rawWord2 = rawWord3 + 4;
                    Level26_82F1CField(privateRecord19, short*, 0x14) = rawWord2;
                    rawWord2 <<= 16;
                    MATCHING_KEEP(rawWord2);
                    if (rawWord2 > 0)
                        Level26_82F1CField(privateRecord19, short*, 0x14) = 0;
                }
            }
            addressOrResult16 = (int)&originalFrame.sp28;
            MATCHING_KEEP(addressOrResult16);
            rawWord2 = Level26_82F1CField((int)&Level26_82F1CData70328View1, unsigned char*, 12);
            argumentWord4 = addressOrResult16;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x44) = rawWord2;
            rawWord2 = Level26_82F1CField((int)&Level26_82F1CData70328View1, unsigned char*, 13);
            retainedVectorOrRecord17 = (int)ownerRecord18 + 12;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x45) = rawWord2;
            rawWord2 = Level26_82F1CField((int)&Level26_82F1CData70328View1, unsigned char*, 14);
            rawWord3 = Level26_82F1CField(privateRecord19, unsigned char*, 0x14);
            argumentWord5 = retainedVectorOrRecord17;
            rawWord2 += rawWord3;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x46) = rawWord2;
            Level26_82F1CCopyVectorView1(argumentWord4, argumentWord5);
            originalFrame.sp30 += 0x80;
            if ((Level26_82F1CQueryWorldSegmentView1(addressOrResult16, retainedVectorOrRecord17) !=
                 0) &&
                (Level26_82F1CGetSurfaceTypeFromFlagsView1(({
                     addressOrResult16 = (int)&Level26_82F1CData71924View1;
                     MATCHING_KEEP(addressOrResult16);
                     Level26_82F1CField(addressOrResult16, int*, 0);
                 })) == 1)) {
                Level26_82F1CField(
                    Level26_82F1CField(
                        Level26_82F1CField((int)&Level26_82F1CData70328View1, void**, 0x250), int*,
                        0),
                    int*, 0x30) = 0;
                Level26_82F1CCopyVectorView1(retainedVectorOrRecord17, addressOrResult16 - 0x24);
                rawWord2 = Level26_82F1CField(ownerRecord18, int*, 0x14);
                MATCHING_KEEP(rawWord2);
                Level26_82F1CField(ownerRecord18, int*, 0x54) = rawWord2;
                rawWord2 = 128;
                Level26_82F1CField(ownerRecord18, unsigned char*, 0x57) = rawWord2;
                rawWord2 = 4;
                Level26_82F1CField(privateRecord19, int*, 0x10) = 0;
                goto storeOriginalFinalState;
            }
            rawWord2 = Level26_82F1CField(retainedVectorOrRecord20, int*, 0x38);
            if (rawWord2) {
                rawWord2 = 38;
                rawWord3 = Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x250);
                argumentWord4 = Level26_82F1CData6E044View1;
                argumentWord5 = Level26_82F1CField(rawWord3, int*, 0);
                if (argumentWord4 == rawWord2) {
                    rawWord2 = Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C);
                    if (!rawWord2) {
                        rawWord2 = Level26_82F1CData6E020View1;
                        Level26_82F1CField(ownerRecord18, int*, 12) = rawWord2;
                        rawWord3 = Level26_82F1CData6E024View1;
                        rawWord2 = 32;
                        Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C) = rawWord2;
                        Level26_82F1CField(ownerRecord18, int*, 16) = rawWord3;
                    }
                }
                Level26_82F1CField(argumentWord5, int*, 0x30) = 0;
                if (Level26_82F1CQueryWorldSegmentView1((int)&Level26_82F1CData70328View1,
                                                        (int)ownerRecord18 + 12)) {
                    rawWord2 = Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 8);
                    Level26_82F1CField(ownerRecord18, int*, 20) = rawWord2;
                    rawWord2 = Level26_82F1CProbeGroundFromRaisedMobyView1(ownerRecord18);
                    rawWord2 += 10;
                    Level26_82F1CField(ownerRecord18, int*, 20) = rawWord2;
                    rawWord2 = 20;
                } else {
                    rawWord2 = Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0xA0);
                    rawWord2 >>= 5;
                }
                Level26_82F1CField(privateRecord19, int*, 16) = rawWord2;
                rawWord2 = 3;
                Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
            }
            MATCHING_BARRIER_GNU_VOLATILE("$4");
            argumentWord4 = (int)ownerRecord18 + 12;
            goto callOriginalSharedHeightHelpers;
        case 0x3:
            rawWord2 = Level26_82F1CField(ownerRecord18, int*, 0x14);
            if (rawWord2 >= 0x400) {
                retainedVectorOrRecord20 = (int)&originalFrame.sp38;
                argumentWord4 = retainedVectorOrRecord20;
                MATCHING_KEEP_CLOBBER(argumentWord4, "$17");
                retainedVectorOrRecord17 = (int)ownerRecord18 + 12;
                Level26_82F1CCopyVectorView1(argumentWord4, retainedVectorOrRecord17);
                addressOrResult16 = (int)&originalFrame.sp48;
                Level26_82F1CCopyVectorView1(addressOrResult16, retainedVectorOrRecord17);
                rawWord2 = Level26_82F1CField(privateRecord19, int*, 0x10) - 8;
                Level26_82F1CField(privateRecord19, int*, 0x10) = rawWord2;
                if (rawWord2 < -0xC0) {
                    Level26_82F1CField(privateRecord19, int*, 0x10) = -0xC0;
                }
                originalFrame.sp50 += Level26_82F1CField(privateRecord19, int*, 0x10);
                Level26_82F1CQueryDynamicMobyGeometryView1(addressOrResult16, 0x200, 3, 0, 0x30000,
                                                           ownerRecord18);
                if (Level26_82F1CQueryWorldSegmentView1(retainedVectorOrRecord20,
                                                        addressOrResult16) != 0) {
                    Level26_82F1CCopyVectorView1(retainedVectorOrRecord17,
                                                 (int)&Level26_82F1CData71900View1);
                    if (Level26_82F1CGetSurfaceTypeFromFlagsView1(Level26_82F1CData71924View1) ==
                        1) {
                        rawWord2 = Level26_82F1CField(ownerRecord18, int*, 0x14);
                        MATCHING_KEEP(rawWord2);
                        Level26_82F1CField(ownerRecord18, int*, 0x54) = rawWord2;
                        rawWord2 = 128;
                        Level26_82F1CField(ownerRecord18, unsigned char*, 0x57) = rawWord2;
                        Level26_82F1CField(privateRecord19, int*, 0x10) = 0;
                        Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = 4U;
                    } else {
                        Level26_82F1CPlayMobySoundEventView1(ownerRecord18, 0, 0);
                        Level26_82F1CRefreshMobySpatialGridAndBasisView1(ownerRecord18, 3);
                        Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = 1U;
                    }
                } else {
                    originalFrame.sp50 += 0x140;
                    if (Level26_82F1CQueryDynamicMobyGeometryView1(addressOrResult16, 0x140, 0, 0,
                                                                   0, ownerRecord18) != 0) {
                        Level26_82F1CCopyVectorView1(addressOrResult16,
                                                     (int)&Level26_82F1CData7190CView1);
                    }
                    if (Level26_82F1CQueryWorldSphereView1(addressOrResult16, 0x140) != 0) {
                        Level26_82F1CCopyVectorView1(addressOrResult16,
                                                     (int)&Level26_82F1CData7190CView1);
                    }
                    originalFrame.sp50 -= 0x140;
                    Level26_82F1CCopyVectorView1(retainedVectorOrRecord17, addressOrResult16);
                }
                MATCHING_BARRIER_GNU_VOLATILE("$4");
                argumentWord4 = (int)ownerRecord18 + 12;
                goto callOriginalSharedHeightHelpers;
            }
            rawWord2 = 5;
            goto storeOriginalFinalState;
        case 0x4:
            Level26_82F1CField(privateRecord19, int*, 0x10) =
                (int)(Level26_82F1CField(privateRecord19, int*, 0x10) + 0x10);
            rawWord2 = Level26_82F1CField(ownerRecord18, int*, 20);
            argumentWord7 = rawWord2 - 16;
            Level26_82F1CField(ownerRecord18, int*, 0x14) = argumentWord7;
            argumentWord6 = Level26_82F1CField(privateRecord19, int*, 0x10);
            argumentWord4 = 0x4C;
            if (argumentWord6 >= 0x201) {
                argumentWord5 = (int)ownerRecord18;
                rawWord3 = (int)Level26_82F1CDataSpawnMobyView1;
                rawWord2 = argumentWord7 + argumentWord6;
                Level26_82F1CField(ownerRecord18, int*, 20) = rawWord2;
                ((int (*)(int, void*))rawWord3)(argumentWord4, argumentWord5);
                rawWord3 = Level26_82F1CField(ownerRecord18, int*, 20);
                argumentWord4 = Level26_82F1CField(privateRecord19, int*, 16);
                rawWord2 = 5;
                Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
                rawWord3 -= argumentWord4;
                Level26_82F1CField(ownerRecord18, int*, 20) = rawWord3;
            }
            rawWord2 = (Level26_82F1CDatarandView1() & 0xFF) * 2;
            retainedVectorOrRecord17 = (int)&originalFrame.sp68;
            argumentWord4 = retainedVectorOrRecord17;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = Level26_82F1CField((int)&Level26_82F1CData65920View1, short*, rawWord2);
            MATCHING_KEEP_CLOBBER(rawWord3, "$16");
            addressOrResult16 = (int)&originalFrame.sp58;
            rawWord3 >>= 4;
            originalFrame.sp58 = rawWord3;
            rawWord2 = Level26_82F1CField((int)&Level26_82F1CData658A0View1, short*, rawWord2);
            MATCHING_KEEP_CLOBBER(rawWord2, "$5");
            argumentWord5 = addressOrResult16;
            originalFrame.sp60 = 0;
            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(argumentWord5) : "memory");
            rawWord2 >>= 4;
            originalFrame.sp5C = rawWord2;
            Level26_82F1CCopyVectorView1(argumentWord4, argumentWord5);
            Level26_82F1CAddVectorView1(addressOrResult16, addressOrResult16, ownerRecord18 + 0xC);
            originalFrame.sp60 += Level26_82F1CField(privateRecord19, int*, 0x10);
            Level26_82F1CShiftVectorRightTowardZeroView1(retainedVectorOrRecord17, 5);
            originalFrame.sp70 = 0x10;
            Level26_82F1CDataSpawnParticleView1(1, 0x37, addressOrResult16,
                                                retainedVectorOrRecord17);
            return;
        case 0x5:
            addressOrResult16 = ownerRecord18 + 0xC;
            Level26_82F1CCopyVectorView1(addressOrResult16, privateRecord19);
            Level26_82F1CDataSpawnParticleView1(0x10, 0xC, ownerRecord18, 0);
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x44) = 0U;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x45) = 0U;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x46) = 0U;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = 1U;
            Level26_82F1CRefreshMobySpatialGridAndBasisView1(ownerRecord18, 3);
            argumentWord4 = addressOrResult16;
        callOriginalSharedHeightHelpers:
            Level26_82F1CQueryWorldHeightView1(argumentWord4, 0x3000);
            Level26_82F1CRefreshMobyPackedQueryFieldView1(ownerRecord18);
            return;
        case 0x60:
            Level26_82F1CMaskLinkedRecordFlagsByIdView1(
                Level26_82F1CField(privateRecord19, short*, 0x16), 0xFC, 0);
            Level26_82F1CWriteMatchingLinkedSelectorsView1(
                Level26_82F1CField(privateRecord19, short*, 0x16), 0x3B, 0);
            argumentWord5 = (int)ownerRecord18 + 12;
            MATCHING_KEEP(argumentWord5);
            rawWord3 = Level26_82F1CField(privateRecord19, int*, 0x18);
            addressOrResult16 = Level26_82F1CData6C550View1;
            MATCHING_KEEP(addressOrResult16);
            rawWord2 = rawWord3 * 88;
            addressOrResult16 += rawWord2;
            Level26_82F1CCopyVectorView1(addressOrResult16 + 12, argumentWord5);
            argumentWord4 = addressOrResult16;
            argumentWord5 = 3;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$2");
            rawWord2 = 10;
            Level26_82F1CField(argumentWord4, signed char*, 0x48) = rawWord2;
            Level26_82F1CRefreshMobySpatialGridAndBasisView1(argumentWord4, argumentWord5);
            rawWord2 = -1;
            Level26_82F1CField(privateRecord19, int*, 0x1C) = rawWord2;
            rawWord2 = 1;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x49) = rawWord2;
            rawWord2 = 0x62;
            Level26_82F1CField(ownerRecord18, signed char*, 0x4D) = 0;
            __asm__(""
                    : "=r"(ownerRecord18)
                    : "0"(ownerRecord18),
                      "m"(Level26_82F1CField(ownerRecord18, unsigned char*, 0x4D)), "i"(96));
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C) = 0;
            __asm__(""
                    : "=r"(ownerRecord18)
                    : "0"(ownerRecord18),
                      "m"(Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C)), "i"(96));
            Level26_82F1CField(ownerRecord18, int*, 8) = 0;
            goto storeOriginalFinalState;
        case 0x61:
            Level26_82F1CMaskLinkedRecordFlagsByIdView1(
                Level26_82F1CField(privateRecord19, short*, 0x16), 0xFC, 0);
            Level26_82F1CWriteMatchingLinkedSelectorsView1(
                Level26_82F1CField(privateRecord19, short*, 0x16), 0x3B, 0);
            argumentWord5 = (int)ownerRecord18 + 12;
            MATCHING_KEEP(argumentWord5);
            rawWord3 = Level26_82F1CField(privateRecord19, int*, 0x1C);
            addressOrResult16 = Level26_82F1CData6C550View1;
            MATCHING_KEEP(addressOrResult16);
            rawWord2 = rawWord3 * 88;
            addressOrResult16 += rawWord2;
            Level26_82F1CCopyVectorView1(addressOrResult16 + 12, argumentWord5);
            Level26_82F1CRefreshMobySpatialGridAndBasisView1(addressOrResult16, 3);
            rawWord2 = 10;
            Level26_82F1CField(addressOrResult16, signed char*, 0x48) = rawWord2;
            rawWord2 = -1;
            Level26_82F1CField(privateRecord19, int*, 0x18) = rawWord2;
            rawWord2 = 1;
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x49) = rawWord2;
            rawWord2 = 0x62;
            Level26_82F1CField(ownerRecord18, signed char*, 0x4D) = 0;
            __asm__(""
                    : "=r"(ownerRecord18)
                    : "0"(ownerRecord18),
                      "m"(Level26_82F1CField(ownerRecord18, unsigned char*, 0x4D)), "i"(97));
            Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C) = 0;
            __asm__(""
                    : "=r"(ownerRecord18)
                    : "0"(ownerRecord18),
                      "m"(Level26_82F1CField(ownerRecord18, unsigned char*, 0x4C)), "i"(97));
            Level26_82F1CField(ownerRecord18, int*, 8) = 0;
            goto storeOriginalFinalState;
        case 0xA:
            Level26_82F1CField(ownerRecord18, int*, 0x14) =
                Level26_82F1CProbeGroundFromRaisedMobyView1(ownerRecord18);
            return;
        case 0x62:
            rawWord3 = Level26_82F1CField(privateRecord19, int*, 0x18);
            retainedVectorOrRecord20 = 0;
            if ((rawWord3 >= 0) ||
                (rawWord3 = Level26_82F1CField(privateRecord19, int*, 0x1C), (rawWord3 >= 0))) {
                rawWord2 = rawWord3 * 11;
                MATCHING_KEEP(rawWord2);
                rawWord3 = Level26_82F1CData6C550View1;
                rawWord2 <<= 3;
                retainedVectorOrRecord20 = rawWord3 + rawWord2;
            }
            if ((retainedVectorOrRecord20 != 0) &&
                (Level26_82F1CField(ownerRecord18, unsigned char*, 0x49) == 0)) {
                retainedOwnerVector23 = ownerRecord18 + 0xC;
                addressOrResult16 = (int)&originalFrame.sp78;
                argumentWord4 = addressOrResult16;
                argumentWord5 = retainedOwnerVector23;
                __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4) : "$17");
                retainedVectorOrRecord17 = retainedVectorOrRecord20 + 12;
                Level26_82F1CSubtractVectorView1(argumentWord4, argumentWord5,
                                                 retainedVectorOrRecord17);
                rawWord2 = Level26_82F1CMeasureVectorLengthView1(&originalFrame.sp78, 1);
                retainedFlag21 = rawWord2 < 0x81;
                if (retainedFlag21 == 0) {
                    Level26_82F1CScaleVectorRatioQ15View1(&originalFrame.sp78, rawWord2, 0x80);
                }
                Level26_82F1CAddVectorView1(retainedVectorOrRecord17, retainedVectorOrRecord17,
                                            &originalFrame.sp78);
                Level26_82F1CSubtractVectorView1(&originalFrame.sp78,
                                                 (int)&Level26_82F1CData70328View1,
                                                 retainedVectorOrRecord17);
                originalFrame.sp80 -= 0x140;
                rawWord2 = Level26_82F1CMeasureVectorLengthView1(&originalFrame.sp78, 1);
                if (rawWord2 <
                    (Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x44) + 0x140)) {
                    Level26_82F1CScaleVectorRatioQ15View1(&originalFrame.sp78, rawWord2, 0x20);
                    Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x20C) = 0x10000400;
                    Level26_82F1CCopyVectorView1((int)&Level26_82F1CData70328View1 + 0x21C,
                                                 &originalFrame.sp78);
                    return;
                }
                if (retainedFlag21 != 0) {
                    Level26_82F1CMaskLinkedRecordFlagsByIdView1(
                        Level26_82F1CField(privateRecord19, short*, 0x16), 0xFC, 0);
                    Level26_82F1CField(ownerRecord18, unsigned char*, 0x49) = 1U;
                    Level26_82F1CPlayMobySoundEventView1(retainedVectorOrRecord20, 0, 0);
                    Level26_82F1CCopyVectorView1(retainedVectorOrRecord17, retainedOwnerVector23);
                    Level26_82F1CRefreshMobySpatialGridAndBasisView1(retainedVectorOrRecord20, 3);
                    return;
                }
            }
            break;
        case 0x63:
            addressOrResult16 = 0;
            rawWord3 = Level26_82F1CField(privateRecord19, int*, 0x18);
            retainedVectorOrRecord17 = 0;
            if (rawWord3 >= 0) {
                rawWord2 = rawWord3 * 11;
                MATCHING_KEEP(rawWord2);
                rawWord3 = Level26_82F1CData6C550View1;
                rawWord2 <<= 3;
                addressOrResult16 = rawWord3 + rawWord2;
            }
            rawWord3 = Level26_82F1CField(privateRecord19, int*, 0x1C);
            if (rawWord3 >= 0) {
                rawWord2 = rawWord3 * 11;
                MATCHING_KEEP(rawWord2);
                rawWord3 = Level26_82F1CData6C550View1;
                rawWord2 <<= 3;
                retainedVectorOrRecord17 = rawWord3 + rawWord2;
            }
            if ((addressOrResult16 != 0) &&
                ((unsigned char)Level26_82F1CField(addressOrResult16, unsigned char*, 0x48) < 4U) &&
                (Level26_82F1CApproximatePlanarDistanceView1(ownerRecord18 + 0xC,
                                                             addressOrResult16 + 0xC) < 0x200)) {
                argumentWord4 = Level26_82F1CField(addressOrResult16, int*, 0x14);
                rawWord3 = Level26_82F1CField(ownerRecord18, short*, 0x38);
                rawWord2 = Level26_82F1CField(ownerRecord18, int*, 0x14);
                rawWord3 = rawWord2 - rawWord3;
                rawWord2 = rawWord3 - argumentWord4;
                if (rawWord2 >= 0) {
                    if (rawWord2 < 0x800) {
                        goto prepareOriginalFirstRecord;
                    }
                    goto checkOriginalSecondRecord;
                }
                if (({
                        rawWord2 = argumentWord4 - rawWord3;
                        rawWord2 = rawWord2 < 0x800;
                        MATCHING_KEEP(rawWord2);
                        rawWord2;
                    })) {
                prepareOriginalFirstRecord:
                    argumentWord4 = ownerRecord18 + 0x48;
                    rawWord3 = Level26_82F1CField(addressOrResult16, unsigned char*, 0x48);
                    argumentWord4 = (int)ownerRecord18 + 0x48;
                    if (rawWord3 == 2) {
                        rawWord2 = 38;
                        rawWord3 =
                            Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x250);
                        argumentWord4 = Level26_82F1CData6E044View1;
                        rawWord3 = Level26_82F1CField(rawWord3, int*, 0);
                        if (argumentWord4 == rawWord2) {
                            rawWord2 = Level26_82F1CField(addressOrResult16, unsigned char*, 0x4C);
                            if (!rawWord2) {
                                rawWord2 = Level26_82F1CData6E020View1;
                                Level26_82F1CField(addressOrResult16, int*, 12) = rawWord2;
                                rawWord2 = Level26_82F1CData6E024View1;
                                Level26_82F1CField(addressOrResult16, int*, 16) = rawWord2;
                            }
                        }
                        Level26_82F1CField(rawWord3, int*, 0x30) = 0;
                        argumentWord4 = (int)ownerRecord18 + 0x48;
                    }
                    argumentWord5 = 1;
                    argumentWord6 = (int)&Level26_82F1CData6C7F8View1;
                    __asm__(""
                            : "=r"(argumentWord6)
                            : "0"(argumentWord6), "r"(argumentWord4), "r"(argumentWord5)
                            : "$2");
                    rawWord2 = 32;
                    Level26_82F1CField(addressOrResult16, unsigned char*, 0x4C) = rawWord2;
                    rawWord2 = 10;
                    Level26_82F1CField(addressOrResult16, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = -1;
                    Level26_82F1CField(privateRecord19, int*, 0x1C) = rawWord2;
                    rawWord2 = 96;
                    goto storeOriginalSelectionAndCall;
                }
                goto checkOriginalSecondRecord;
            }
        checkOriginalSecondRecord:
            if ((retainedVectorOrRecord17 != 0) &&
                ((unsigned char)Level26_82F1CField(retainedVectorOrRecord17, unsigned char*, 0x48) <
                 4U) &&
                (Level26_82F1CApproximatePlanarDistanceView1(
                     ownerRecord18 + 0xC, retainedVectorOrRecord17 + 0xC) < 0x200)) {
                argumentWord4 = Level26_82F1CField(retainedVectorOrRecord17, int*, 0x14);
                rawWord3 = Level26_82F1CField(ownerRecord18, short*, 0x38);
                rawWord2 = Level26_82F1CField(ownerRecord18, int*, 0x14);
                rawWord3 = rawWord2 - rawWord3;
                rawWord2 = rawWord3 - argumentWord4;
                if (rawWord2 >= 0) {
                    if (rawWord2 < 0x800) {
                        goto prepareOriginalSecondRecord;
                    }
                } else if (({
                               rawWord2 = argumentWord4 - rawWord3;
                               rawWord2 = rawWord2 < 0x800;
                               MATCHING_KEEP(rawWord2);
                               rawWord2;
                           })) {
                prepareOriginalSecondRecord:
                    argumentWord4 = ownerRecord18 + 0x48;
                    rawWord3 = Level26_82F1CField(retainedVectorOrRecord17, unsigned char*, 0x48);
                    argumentWord4 = (int)ownerRecord18 + 0x48;
                    if (rawWord3 == 2) {
                        rawWord2 = 38;
                        rawWord3 =
                            Level26_82F1CField((int)&Level26_82F1CData70328View1, int*, 0x250);
                        argumentWord4 = Level26_82F1CData6E044View1;
                        rawWord3 = Level26_82F1CField(rawWord3, int*, 0);
                        if (argumentWord4 == rawWord2) {
                            rawWord2 = Level26_82F1CField(addressOrResult16, unsigned char*, 0x4C);
                            if (!rawWord2) {
                                rawWord2 = Level26_82F1CData6E020View1;
                                Level26_82F1CField(retainedVectorOrRecord17, int*, 12) = rawWord2;
                                rawWord2 = Level26_82F1CData6E024View1;
                                Level26_82F1CField(retainedVectorOrRecord17, int*, 16) = rawWord2;
                            }
                        }
                        Level26_82F1CField(rawWord3, int*, 0x30) = 0;
                        argumentWord4 = (int)ownerRecord18 + 0x48;
                    }
                    argumentWord5 = 1;
                    argumentWord6 = (int)&Level26_82F1CData6C7F8View1;
                    __asm__(""
                            : "=r"(argumentWord6)
                            : "0"(argumentWord6), "r"(argumentWord4), "r"(argumentWord5)
                            : "$2");
                    rawWord2 = 32;
                    Level26_82F1CField(retainedVectorOrRecord17, unsigned char*, 0x4C) = rawWord2;
                    rawWord2 = 10;
                    Level26_82F1CField(retainedVectorOrRecord17, unsigned char*, 0x48) = rawWord2;
                    rawWord2 = -1;
                    Level26_82F1CField(privateRecord19, int*, 0x18) = rawWord2;
                    rawWord2 = 97;
                storeOriginalSelectionAndCall:
                    Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
                    Level26_82F1CRegisterTrackedValueView1(argumentWord4, argumentWord5,
                                                           argumentWord6);
                    rawWord2 = 0x62;
                storeOriginalFinalState:
                    Level26_82F1CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
                    return;
                }
            }
            break;
    }
}
#undef Level26_82F1CField

extern Moby* D_8006C550;
void func_level_26_80083B58(Moby* moby) {
    int* tag = moby->mobyTag;
    Moby* actors = D_8006C550;
    unsigned int state = *(unsigned short*)&actors[tag[1]].state;
    if (state == 0x162 && *(unsigned short*)&actors[tag[2]].state == state) {
        SpawnFragments(7, 0x126, moby, tag[0], 0, 0x200);
        func_8003BB10(moby, 0, 0);
        func_8003BA00(moby);
        func_80055B18(moby);
    }
}

int func_8003BB10(Moby*, int, int);
void func_8003BA00(Moby*);
void func_80055B18(Moby*);
void func_level_26_80083C2C(Moby* moby) {
    if (moby->damageFlags) {
        SpawnFragments(7, 0x126, moby, *(Vector3D**)moby->mobyTag, 0, 0x200);
        func_8003BB10(moby, 0, 0);
        func_8003BA00(moby);
        func_80055B18(moby);
    }
}

void func_level_26_80083CA8(Moby* moby) {
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
void func_level_26_80083CC8(Moby* mobyArgument) {
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
void func_level_26_80083EC8(Moby* moby) {
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

extern int D_8006C58C, D_80067648[];
void func_level_26_80083F90(Moby* moby) {
    int* tag = moby->mobyTag;
    if (moby->state == 0 && func_80036220((Vector3D*)&spyro, tag, 0, 0)) {
        *(int*)((char*)&spyro + 0xF8) = D_80067648[D_8006C58C] + tag[6];
        moby->state = 1;
    }
    if (moby->state == 1 && !func_80036220((Vector3D*)&spyro, tag, 0, 0)) {
        *(int*)((char*)&spyro + 0xF8) = D_80067648[D_8006C58C];
        moby->state = 0;
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * The original 401 instructions in each copy are the acceptance authority.
 * Preserve the 0x90-byte frame, signed table loads, byte offsets, wrapped
 * 32-bit products, arithmetic shifts, helper order and descriptor updates.
 * Empty constraints emit no opcodes and preserve original allocation/order.
 * Table meanings, physical units, full helper contracts and caller cadence
 * remain unresolved. No retail runtime completeness is claimed.
 * Falsifiable check: original linked words and every full retail binary hash.
 */
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
void func_level_26_80084070(void* input) {
    register unsigned char* owner __asm__("$23") = input;
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
    register int* ownerWord0C __asm__("$16");
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
    register void* state __asm__("$20");
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
    ownerWord0C = owner + 12;
    Actor84070QueryDynamicMobyGeometry(ownerWord0C, 1000, 1, 0, 0x40000, owner);
    initialCondition = Actor84070Field(state, short*, 2);
    if (initialCondition != 0) {
        initialCondition = initialCondition < 10;
        goto initialBound;
    }
    initialCondition = initialCondition < 10;
    MATCHING_KEEP(initialCondition);
    Actor84070SpawnParticle(10, 70, ownerWord0C, (void*)30);
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
        if (!value12)
            goto done;
    }
    {
        temp_a0_3 = Actor84070Field(state, int*, 8);
        if (temp_a0_3 != 0) {
            Actor84070ClearFiveWordSlotMarker(temp_a0_3);
        }
        Actor84070DeleteMoby(owner);
    }
done:;
}

#undef Actor84070Field
