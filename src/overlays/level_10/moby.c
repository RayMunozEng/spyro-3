#include "matching.h"
#include "common.h"
#include "savepoint.h"
#include "camera.h"
#include "mobyutil.h"
#include "spu.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

/*
// Maybe all of this (except level ID) in a separate file for useful macros
#define LEVEL_ID 10

// String things
#define STRINGLIT( x ) # x
#define EXPAND( x ) STRINGLIT( x )
#define STRINGQUOTE( x ) EXPAND( EXPAND( x ) )
#define CONCAT2(a, b) a##b
#define CONCAT(a, b) CONCAT2(a, b)

// Overlay functions
#define MOBYUPDATE(a) CONCAT(MobyUpdate_ ## a ## _L, LEVEL_ID)
#define MOBYUPDATE2(a) void MOBYUPDATE(a) (Moby* pMoby)
#define SUFFIX(a) CONCAT(a ## _L, LEVEL_ID)
// #define MOBYUPDATEL(a, b) CONCAT(MobyUpdate_ ## a ## _L, b)
// #define MOBYUPDATE(a) MOBYUPDATEL(a, LEVEL_ID)
// MOBYUPDATE and MOBYUPDATE2 seem to work well as functions
*/

// For fragment mobys
extern void func_80039714(Moby*); // fUpdateFragmentMoby

// 942
typedef struct {
    Vector3D position;
    int xWidth;
    int yWidth;
    int angle;
} BoxTag;
extern int func_80036220(Vector3D*, BoxTag*, int, int); // isInBox; second arg should be a box tag actually

// For 486
extern void func_8004F194(Vector3D*, Vector3D*, Vector3D*); // fAddVector
extern void func_80055B18(Moby*); // fDeleteMoby
extern short D_800658A0[0x100]; // sin
extern short D_80065920[0x100]; // cos
extern Moby* D_8006C550; // moby array ptr

typedef struct {
    Moby* unk0;
    int unk4;
} MobyTag_486;

// Placeholder for now, used in 486
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
} MobyTag_514;

////////////////////////////////////////////////////////////////////////////////////

/**
 * MobyUpdate_1() - func_level_10_80074C50()
 * Gem
 * A good one to use to update the context
 * https://decomp.me/scratch/zKX9n
 * https://decomp.me/scratch/Birmk (newer)
 * https://decomp.me/scratch/6CkM7 (newest)
 */
/* AI generated; not yet human reviewed. Derived from the original SCUS-94467
 * USA Rev 0 instructions, including all five dispatch targets and padding.
 * Field offsets and integer operations preserve the disc representation.
 * Helper semantics, physical units, and caller update cadence remain unresolved;
 * this routine describes one invocation. Empty constraints preserve compiler
 * allocation/scheduling and emit no instruction or opcode patch.
 */
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
void func_level_10_80074C50(void* input) {
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
    tag = Controller74C50Field(owner, void**, 0);
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
            case 3: /* switch 1 */
                stateThreeVector = &frame.eighth.x;
                MATCHING_KEEP(stateThreeVector);
                Controller74C50Helper4F52C(stateThreeVector, tag + 4);
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
                if ((var_v0 < var_a0) && (Controller74C50D_8006C65C != 0) &&
                    ((Controller74C50Field(owner, unsigned char*, 0x48) != 2) ||
                     ((unsigned char)Controller74C50Field(tag, unsigned char*, 0x12) < 3U)) &&
                    (callbackTag = Controller74C50Field(Controller74C50D_8006C65C, void**, 0),
                     Controller74C50CopyVector(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64,
                     (Controller74C50Helper13E38(Controller74C50D_8006C65C + 0xC, &frame.ninth.x,
                                                 0) != 0))) {
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
void func_level_10_800758AC(Moby* argument) {
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

/* AI generated; not yet human reviewed. Derived from SCUS-94467 USA Rev 0
 * original instructions and all five dispatch tables, including padding.
 * Offsets, signedness, shifts, and integer operations preserve the disc data.
 * Physical units, helper meanings, and caller cadence remain unresolved;
 * this routine describes one invocation. Empty compiler constraints preserve
 * proven register allocation and scheduling without emitting instructions.
 */
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
void func_level_10_80075F38(void* input) {
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

    tag = Controller75F38Field(owner, void**, 0);
    originalAngle = Controller75F38Field(owner, unsigned char*, 0x46);
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
            register void* particleVector __asm__("$16") = &frame.second.x;
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
}

#undef Controller75F38Field


/**
 * MobyUpdate_200() - func_level_10_80077488() - MATCHING
 * Gem Basket
 * Ready to add, but seems to use a non-struct version of the overlay header
 * Will need to start defining the function pointers individually in ovl_header.h
 * https://decomp.me/scratch/HOd1q
 */
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
void func_level_10_80077488(Moby* moby) {
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
void func_level_10_80077748(Moby* argument) {
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
void func_level_10_80077C68(Moby* moby) {
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
void func_level_10_80077FE8(Moby* moby) {
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
extern unsigned char Controller78288D_80066FD3[] __asm__("D_80066FCC+7");
extern unsigned char Controller78288D_80070300[] __asm__("D_80070300");
extern unsigned char Controller78288D_80071595 __asm__("D_80071595");
extern int Controller78288D_8006C5BC __asm__("D_8006C5BC");
extern int Controller78288D_8006C73C __asm__("D_8006C73C");
int Controller78288ActivateSparxPowers() __asm__("ActivateSparxPowers");
int Controller78288Helper584BC() __asm__("func_800584BC");
extern unsigned char Controller78288D_800715B3 __asm__("D_800715B3");
extern unsigned char Controller78288CheatByte __asm__("g_CheatFlags+2");
int Controller78288Helper142AC() __asm__("func_800142AC");
void func_level_10_800782EC(void* input) {
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
        tag = Controller78288Field(owner, void**, 0);
        prefixTag = 0;
    } else {
        MATCHING_KEEP(owner);
        prefixTag = Controller78288Field(owner, void**, 0);
        tag = prefixTag + 0x2C;
    }
    distanceResult = Controller78288ApproximatePlanarDistance((void*)((int)(owner + 12)),
                                                              Controller78288D_80070328);
    if ((prefixTag != 0) && (Controller78288Field(prefixTag, unsigned char*, 0) == 200) &&
        (Controller78288D_800715B3 == 0))
        goto removeController;
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
                                if ((unsigned int)(Controller78288Field(prefixTag, unsigned char*,
                                                                        0) -
                                                   11) < 2)
                                    goto checkOriginalPrefixKind;
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                    checkOriginalPrefixKind:
                        if (({
                                register int prefix3 __asm__("$3") =
                                    Controller78288Field(prefixTag, unsigned char*, 0);
                                register int twelve2 __asm__("$2");
                                MATCHING_KEEP_CLOBBER(prefix3, "$2");
                                twelve2 = 12;
                                MATCHING_KEEP2(prefix3, twelve2);
                                prefix3 == twelve2;
                            })) {
                        checkPrefixFlags:
                            if (!(Controller78288D_80070300
                                      [Controller78288D_80066FD3[Controller78288D_8006C5BC]] &
                                  1))
                                goto removeController;
                        }
                        MATCHING_BARRIER_VOLATILE("memory");
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            {
                                register int rawOne4 __asm__("$4") = 1;
                                register int rawKind3 __asm__("$3");
                                register int nine2 __asm__("$2");
                                MATCHING_KEEP_CLOBBER(rawOne4, "$3");
                                rawKind3 = Controller78288Field(prefixTag, unsigned char*, 0);
                                MATCHING_KEEP_CLOBBER(rawKind3, "$2");
                                nine2 = 11;
                                MATCHING_KEEP3(rawOne4, rawKind3, nine2);
                                Controller78288Field(prefixTag, unsigned char*, 5) = rawOne4;
                                if (rawKind3 == nine2)
                                    goto readOriginalPrefixBank;
                                if (rawKind3 == 12) {
                                    if ((Controller78288D_8006C73C == 18) &&
                                        (Controller78288D_80071595 == 0))
                                        goto storeOriginalLowering;
                                readOriginalPrefixBank:
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
                                        }
                                    }
                                }
                            }
                        storeOriginalLowering:
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
                        removeController:
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
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 11) {
                                    if (Controller78288CheatByte)
                                        Controller78288Field(prefixTag, unsigned char*, 2) = 4;
                                    else
                                        Controller78288Field(prefixTag, unsigned char*, 2) = 0;
                                    MATCHING_BARRIER_VOLATILE("memory");
                                }
                                if (Controller78288Field(prefixTag, unsigned char*, 0) == 12) {
                                    if (Controller78288D_80070300[Controller78288D_80066FD3[0xB]] &
                                        1) {
                                        register unsigned char* flag3 __asm__("$3") =
                                            &Controller78288D_80071595;
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
                                Controller78288Helper512E4(owner, 0, 0);
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
                    if (Controller78288D_8006E344 == 1)
                        goto clearExtraHandle;
                    {
                        register int prefix3 __asm__("$3") =
                            Controller78288Field(prefixTag, unsigned char*, 0);
                        register int raw2 __asm__("$2");
                        if (prefix3 == 11) {
                            prefix3 = Controller78288Field(prefixTag, unsigned char*, 4);
                            if (prefix3 == 3)
                                Controller78288CheatByte = 1;
                            else if (prefix3 == 6)
                                Controller78288CheatByte = 0;
                            else
                                goto storeOriginalTagOne;
                            Controller78288Helper142AC();
                            goto storeOriginalTagOne;
                        }
                        if (prefix3 != 12)
                            goto setSubstateFour;
                        prefix3 = Controller78288Field(prefixTag, unsigned char*, 2);
                        if (prefix3 == 3)
                            Controller78288Helper584BC(0, Controller78288D_8006C5BC + 8);
                    storeOriginalTagOne:
                        Controller78288Field(tag, unsigned char*, 2) = 1;
                        goto setSubstateFour;
                    }

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
                Controller78288Helper492DC(((int)(owner + 12)));
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
void func_level_10_80079088(Moby* moby) {
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
void func_level_10_800794B8(Moby* moby) {
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
void func_level_10_80079820(Moby* owner) {
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
void func_level_10_800799AC(Moby* moby) {
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
void DecodedDialogueGateBegin(Moby*, int, int) __asm__("func_800512E4");
void func_level_10_80079B00(Moby* moby) {
    DecodedDialogueGateTag* tag = moby->mobyTag;
    int gate, targetIndex;
    switch (moby->state) {
        case 0:
            if (!D_80071584)
                tag->phase = 5;
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
                DecodedDialogueGateBegin(moby, 0, 1);
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
void func_level_10_80079D58(Moby* actor) {
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

/**
 * MobyUpdate_459() - func_level_10_80079EE4() - MATCHING
 * 
 * https://decomp.me/scratch/ebfYd
 */
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_10_80079EE4(Moby* moby) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
extern unsigned char Controller7C02CFlagPlayer[] __asm__("D_80070328");
#define Controller7C02CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Controller7C02Cfunc_8002803C(int, int, int, int, int, void*, int) __asm__("func_8002803C");
void* Controller7C02Cfunc_8002F540(int, int, int) __asm__("func_8002F540");
int Controller7C02CPlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller7C02Cfunc_8003BFC0(void*, int) __asm__("func_8003BFC0");
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
extern int Controller7C02CD_8006C7C4 __asm__("D_8006C7C4");
extern unsigned char Controller7C02CD_8006C7B4 __asm__("D_8006C7B4");
extern unsigned char Controller7C02CD_80070300[] __asm__("D_80070300");
extern unsigned char Controller7C02CEvent1BC[] __asm__("D_80070328 + 0x1BC");
extern unsigned char Controller7C02CEvent1C0[] __asm__("D_80070328 + 0x1C0");
extern unsigned char Controller7C02CCounters[] __asm__("D_800716AC + 0x2");
void func_level_10_80079FBC(void* input) {
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
    controller = Controller7C02CField(owner, void**, 0);
    distance = Controller7C02CApproximatePlanarDistance(owner + 0xC, Controller7C02CD_80070328);
    Controller7C02CField(controller, int*, 0x14) = distance;
    if (distance < 0x1000) {
        {
            register int index __asm__("$3") = Controller7C02CField(owner, unsigned char*, 70);
            register int component __asm__("$2") =
                Controller7C02CField(Controller7C02CD_80070328, int*, 4);
            register int ownerComponent __asm__("$4") = Controller7C02CField(owner, int*, 16);
            register int firstProduct __asm__("$5");
            MATCHING_KEEP3(index, component, ownerComponent);
            index <<= 1;
            firstProduct = *(short*)(Controller7C02CD_800658A0 + index);
            component -= ownerComponent;
            firstProduct *= component;
            index = *(short*)(Controller7C02CD_80065920 + index);
            ownerComponent = Controller7C02CField(owner, int*, 12);
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
    temp_a0_2 = Controller7C02CField(owner, unsigned char*, 0x50);
    if (temp_a0_2 != 0xFF) {
        temp_v0_3 = Controller7C02CSpawnMoby(temp_a0_2, owner);
        Controller7C02CField(controller, void**, 0x24) = temp_v0_3;
        if (temp_v0_3 != 0) {
            Controller7C02CCopyVector(temp_v0_3 + 0xC, owner + 0xC);
            temp_v1_3 = Controller7C02CField(controller, void**, 0x24);
            Controller7C02CField(temp_v1_3, int*, 0x14) =
                (int)(Controller7C02CField(temp_v1_3, int*, 0x14) + 0x580);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x46) =
                (unsigned char)Controller7C02CField(owner, unsigned char*, 0x46);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x4C) =
                (unsigned char)Controller7C02CField(owner, unsigned char*, 0x4C);
            Controller7C02CField(Controller7C02CField(controller, void**, 0x24), unsigned char*,
                                 0x52) =
                (unsigned char)Controller7C02CField(owner, unsigned char*, 0x52);
            if (Controller7C02CField(owner, unsigned char*, 0x50) == 0x21) {
                Controller7C02CField(Controller7C02CField(controller, void**, 0x24), int*, 0x54) =
                    0x2A606060;
            }
            Controller7C02CField(owner, unsigned char*, 0x50) = 0xFFU;
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
    state = Controller7C02CField(owner, unsigned char*, 72);
    if (!state) {
        Controller7C02CField(owner, unsigned char*, 72) = 1;
        return;
    }
    switch (state) {
        case 1:
            break;
        default:
            return;
    }
    if ((Controller7C02CField(owner, unsigned char*, 0x4D) != 0) &&
        (Controller7C02CField(controller, int*, 0x14) < 0x4000) &&
        !(Controller7C02Crand() & 0x3F)) {
        spawnedChild = Controller7C02CSpawnMoby(0x1CBU, owner);
        spawnedRecord = Controller7C02CField(spawnedChild, void**, 0);
        {
            register int factor __asm__("$2") = Controller7C02Crand();
            register int trig __asm__("$3") = Controller7C02CField(owner, unsigned char*, 70);
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
            trig = Controller7C02CField(owner, unsigned char*, 70);
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
    if (Controller7C02Cfunc_8003BFC0(owner, Controller7C02CField(controller, int*, 0x20)) == 0) {
        Controller7C02CField(controller, int*, 0x20) =
            Controller7C02CPlayMobySoundEvent(owner, 0, 4);
    }
    if (Controller7C02CField(owner, unsigned char*, 0x4D) != 0) {
        temp_a0_4 = Controller7C02CField(controller, int*, 0x14);
        if ((temp_a0_4 <= 0x9FFF) && (!(Controller7C02CD_8006C640 & 3) ||
                                      (!(Controller7C02CD_8006C640 & 1) && (temp_a0_4 < 0x5000)))) {
            frame.sp20 = 0;
            frame.sp24 = 0x352 - (Controller7C02Crand() % 1700);
            frame.sp28 = 0;
            Controller7C02CTransformVectorByBasis(owner + 32, &frame.sp20, &frame.sp20);
            Controller7C02CAddVector(&frame.sp20, &frame.sp20, owner + 0xC);
            Controller7C02CSpawnParticle(1, 4, &frame.sp20,
                                         Controller7C02CField(owner, int*, 0x14) + 0x640);
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
                temp_v0_7 = Controller7C02Cfunc_8002F540(4, 1, 0x608080);
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
    Controller7C02CField(owner, unsigned char*, 0x57) =
        (unsigned char)(Controller7C02CField(owner, unsigned char*, 0x57) +
                        (Controller7C02Crand() & 3));
    temp_v1_8 = Controller7C02CField(controller, int*, 0x14);
    if ((temp_v1_8 < 0x1000) && (crossedSide != 0) && (temp_v1_8 < 0x380)) {
        temp_v1_9 =
            Controller7C02CField(owner, int*, 0x14) - Controller7C02CField(owner, short*, 0x38);
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
                        register int word __asm__("$3") = Controller7C02CField(controller, int*, 0);
                        register int value __asm__("$2");
                        register unsigned char* destination __asm__("$4");
                        register int one __asm__("$3");
                        __asm__("" : "=r"(word) : "0"(word) : "$2", "$4");
                        value = Controller7C02CD_8006C7C4;
                        MATCHING_KEEP_CLOBBER(value, "$4");
                        destination = Controller7C02CEvent1BC;
                        MATCHING_KEEP2(value, destination);
                        *(int*)destination = word;
                        if (value == 0) {
                            value = Controller7C02CD_8006C7B4 & 4;
                            if (value == 0) {
                                value = Controller7C02CD_8006C58C;
                                value = Controller7C02CD_80070300[value] & 4;
                                if (value == 0) {
                                    value = word + 120;
                                    MATCHING_KEEP(value);
                                    *(int*)destination = value;
                                }
                            }
                        }
                        destination = Controller7C02CEvent1C0;
                        MATCHING_KEEP_CLOBBER(destination, "memory");
                        eventDestination = destination - 4;
                        value = Controller7C02CD_8006C58C;
                        MATCHING_KEEP_CLOBBER(value, "$3");
                        one = 1;
                        *(int*)destination = one;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        value <<= 2;
                        value = *(int*)(Controller7C02CD_80067648 + value);
                        Controller7C02CField(Controller7C02CD_80070328, int*, 0xF8) = value;
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
                    Controller7C02Cfunc_8002803C(4, eventSelector,
                                                 Controller7C02Cunk_ovlheader_800743B8,
                                                 Controller7C02Cunk_ovlheader_800743C0,
                                                 Controller7C02Cunk_ovlheader_800743BC,
                                                 eventDestination, *(int*)eventDestination);
                }
                {
                    register int flags __asm__("$2") = Controller7C02CD_8006C7B4 & 4;
                    register int bank __asm__("$3");
                    register int offset __asm__("$4");
                    register unsigned int count __asm__("$3");
                    register unsigned int within __asm__("$2");
                    register unsigned int incremented __asm__("$2");
                    register int triple __asm__("$2");
                    if (flags == 0) {
                        bank = Controller7C02CD_8006C58C;
                        flags = Controller7C02CD_80070300[bank] & 4;
                        if (flags == 0) {
                            triple = bank * 3;
                            MATCHING_KEEP(triple);
                            offset = triple * 2;
                            count = Controller7C02CCounters[offset];
                            within = count < 255;
                            __asm__("" : "=r"(within) : "0"(within), "r"(count));
                            if (within) {
                                incremented = count + 1;
                                Controller7C02CCounters[offset] = incremented;
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

/**
 * MobyUpdate_265() - func_level_10_8007A840() - MATCHING
 * Portal text letters
 * Note that this uses "cos" as a label for the cos table
 * Not sure if this will work in practice as it's supposedly a built-in function, may need a new label
 * https://decomp.me/scratch/f6rLY
 */
typedef struct {
    Moby* parent;
    unsigned char unk4, unk5;
} DecodedYawTag;
extern int D_8006C644;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_level_10_8007A840(Moby* moby) {
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

/**
 * MobyUpdate_559() - func_level_10_8007A8F0() - MATCHING
 * Breakable rock fragment
 * https://decomp.me/scratch/ebfYd
 */
void func_level_10_8007A8F0(Moby* moby) {
    func_80039714(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original level10 controller8007A910.
 * Assembly SHA256 46121d611abdc075f2df8f8bb5f8e657d2ed5dc6e996b83fa076b66a04746b65.
 * AI generated; not human reviewed.1964 native instructions and FIVE
 * original .rodata tables:11 outer selectors at800745A8,one zero pad at
 * 800745D4,and6 inner selectors each at800745D8,800745F0,80074608,
 * 80074620. There are35 selectors+one pad=2000 owned original words.
 * Names describe physical fields,register phases and source selectors;
 * gameplay,asset,SFX and animation meanings are not inferred.
 * Original152-byte frame retains local vectors SP20/24/28,30/34/38,
 * 40/44/48,50/54/58,60/64/68 and70/74/78. Every local scalar load,
 * vector input,call word and HILO input has a real original producer.
 * Original4F178 copies define all three output words; original4F194
 * defines all three sum words. The finite path-sensitive original audit
 * checks2097 states/2237 edges,all five JR tables,and no incoming saved
 * GP or unwritten local value. Every call destroys caller GP/HILO and
 * outgoing homes. No callback output or guessed initializer is needed.
 * All four original DIV operations consume complete signed16 index/count
 * loads and their signed32 index+count-1 numerator. Original zero and
 * signed-overflow trap instructions are retained. There are no MULT
 * operations,partial HI/LO inputs or register-pair projections. Trig
 * samples are complete signed16 values multiplied13 then shifted5,or
 * multiplied39 then shifted6,exactly matching the original shift ladders.
 * Reused S0 index/one/local-vector roles and S1 position-pointer roles
 * have disjoint initialized phases. Original A0/A1/A2 argument values
 * and byte254/255 producers are retained before their narrow stores.
 * One common substate4 producer is at the actual substate store entry;
 * readonly original selector context after each original return store
 * lets GCC place that single producer in all five original J delays.
 * Shared deletion,heading,state2,state6,mode1 and callback entries retain
 * their original physical locations and every actual incoming target.
 * Empty metadata emits no CPU instruction. It observes complete initialized
 * words,addresses,original frame cells or exact original branch-source
 * bytes. Selector immediates are actual dominating source case values;
 * an outer-only context repeats that same outer value. Dead-register
 * boundaries end only an original phase before its fresh definition.
 * There is no opcode asm,manual outgoing home,fixed FP/SP,incoming saved
 * read,overlapping live alias or invented default. Known views retain
 * original physical helper/callback argument words. This targets frozen
 *32-bit MIPS wrap,narrow and arithmetic-shift behavior. Portable C numeric
 * domains,full helper/caller/archive contracts,object pointer provenance,
 * units,cadence beyond invocation,Rev1 mappings,synchronized original
 * runtime captures and human review remain open. Acceptance requires all
 * linked native/data/addend/35selector/pad bytes and every retail hash.
 */
#define Actor1964Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Actor1964Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Actor1964_func_8001A358(void*, int) __asm__("func_8001A358");
void Actor1964RequestMobyAnimation(void*, int) __asm__("func_80034F40");
int Actor1964TurnMobyTowardHeading(void*, int, int, int, int, int) __asm__("func_8003585C");
int Actor1964_func_80035A80(void*, void*, int, int, int, int, int, int) __asm__("func_80035A80");
int Actor1964_func_80036220(void*, void*, int, int) __asm__("func_80036220");
int Actor1964_func_800365E4(void*, void*, int, int, int) __asm__("func_800365E4");
void Actor1964_func_80037014(void*) __asm__("func_80037014");
int Actor1964_func_80037BBC(void*, int) __asm__("func_80037BBC");
int Actor1964PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void Actor1964CopyVector(void*, void*) __asm__("func_8004F178");
void Actor1964AddVector(void*, void*, void*) __asm__("func_8004F194");
int Actor1964ApproximatePlanarDistance(void*, void*) __asm__("func_8004F334");
void Actor1964_func_800512E4(void*, int, int) __asm__("func_800512E4");
void Actor1964DeleteMoby(void*) __asm__("func_80055B18");
void Actor1964RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Actor1964_func_80055E84(void*) __asm__("func_80055E84");
extern short Actor1964_D_800658A0[] __asm__("D_800658A0");
extern short Actor1964_D_80065920[] __asm__("D_80065920");
extern int Actor1964_D_8006C58C __asm__("D_8006C58C");
extern int Actor1964_D_8006C770 __asm__("D_8006C770");
extern unsigned char Actor1964_D_8006C7B4 __asm__("D_8006C7B4");
extern int Actor1964_D_8006E344 __asm__("D_8006E344");
extern unsigned char Actor1964_D_80070300[] __asm__("D_80070300");
extern unsigned char Actor1964_D_80070328[] __asm__("D_80070328");
extern unsigned char Actor1964_D_80071570 __asm__("D_80071570");
extern unsigned char Actor1964_D_8007157A __asm__("D_8007157A");
extern unsigned char Actor1964_D_80071583 __asm__("D_80071583");
extern void (*Actor1964_unk_ovlheader_80074330)(void*, int, int) __asm__("unk_ovlheader_80074330");
void func_level_10_8007A910(void* input) {
    register int resultWord2 __asm__("$2"), intermediateWord3 __asm__("$3"),
        argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"),
        argumentWord7 __asm__("$7"), pathCountOrPointArray8 __asm__("$8");
    register int ownerAddress18 __asm__("$18"), privateAddress19 __asm__("$19"),
        retainedIndexConstantOrVectorAddress16 __asm__("$16"),
        retainedOwnerPositionAddress17 __asm__("$17");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54,
            sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C;
    } originalFrame;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord18;
    int temporaryWord24;
    int temporaryWord29;
    int temporaryWord34;
    int temporaryWord41;
    int temporaryWord47;
    int temporaryWord48;
    int temporaryWord52;
    int temporaryWord54;
    int temporaryWord59;
    int temporaryWord60;
    int temporaryWord66;
    int temporaryWord67;
    int temporaryWord39;
    int outer2Substate48;
    int outer3Substate48;
    int outer5Substate48;
    int outer6Substate48;
    int outer7Substate48;
    int outer8Substate48;
    int outer9Substate48;
    int outer1Substate48;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord11;
    int temporaryWord13;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord20;
    int temporaryWord21;
    int temporaryWord22;
    int temporaryWord23;
    int temporaryWord25;
    int temporaryWord26;
    int temporaryWord27;
    int temporaryWord19;
    int temporaryWord30;
    int temporaryWord31;
    int temporaryWord32;
    int temporaryWord33;
    int temporaryWord28;
    int temporaryWord35;
    int temporaryWord36;
    int temporaryWord37;
    int temporaryWord38;
    int temporaryWord40;
    int temporaryWord42;
    int temporaryWord45;
    int temporaryWord46;
    int temporaryWord51;
    int temporaryWord49;
    int temporaryWord57;
    int temporaryWord58;
    int temporaryWord53;
    int temporaryWord64;
    int temporaryWord65;
    int temporaryWord62;
    int temporaryWord68;
    int temporaryWord69;
    int temporaryWord70;
    int temporaryWord71;
    ownerAddress18 = (int)input;
    Actor1964Keep(ownerAddress18);
    temporaryWord39 = Actor1964Field(ownerAddress18, unsigned char*, 0x49);
    privateAddress19 = Actor1964Field(ownerAddress18, void**, 0);
    switch (temporaryWord39) {
        case 0:
            if (Actor1964Field(privateAddress19, unsigned char*, 0) == 0) {
                if (!(Actor1964_D_8006C7B4 & 1) &&
                    !(Actor1964Field((int)&Actor1964_D_80070300 + Actor1964_D_8006C58C,
                                     unsigned char*, 0) &
                      1)) {
                    if (Actor1964_D_80071583 != 0) {
                        resultWord2 = 2;
                        argumentWord4 = Actor1964Field(privateAddress19, void**, 60);
                        __asm__ volatile("" ::: "$3", "memory");
                        intermediateWord3 = 1;
                        Actor1964Field(privateAddress19, unsigned char*, 2) = resultWord2;
                        Actor1964Field(privateAddress19, void**, 0x2C) = argumentWord4;
                        Actor1964Field(argumentWord4, short*, 2) = intermediateWord3;
                        retainedOwnerPositionAddress17 = ownerAddress18 + 0xC;
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*,
                                       0xA) = intermediateWord3;
                        temporaryWord11 = Actor1964Field(privateAddress19, void**, 0x2C);
                        Actor1964CopyVector(
                            retainedOwnerPositionAddress17,
                            Actor1964Field(temporaryWord11, int*, 0xC) +
                                (Actor1964Field(temporaryWord11, short*, 2) * 0x10));
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2) =
                            0;
                        temporaryWord49 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord19 = (Actor1964Field(temporaryWord49, short*, 2) * 0x10) +
                                          Actor1964Field(temporaryWord49, int*, 0xC);
                        resultWord2 = Actor1964PlanarHeadingLookup(
                            Actor1964Field(temporaryWord19, int*, 0) -
                                Actor1964Field(ownerAddress18, int*, 0xC),
                            Actor1964Field(temporaryWord19, int*, 4) -
                                Actor1964Field(ownerAddress18, int*, 0x10),
                            0);
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        Actor1964Field(ownerAddress18, unsigned char*, 0x46) = resultWord2;
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2) =
                            2;
                        Actor1964_func_80037014(argumentWord4);
                        __asm__ volatile("" ::"i"(0), "i"(0) : "memory");
                        argumentWord4 = ownerAddress18;
                        argumentWord5 = 2;
                        MATCHING_KEEP2(argumentWord4, argumentWord5);
                        retainedIndexConstantOrVectorAddress16 = 254;
                        Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                        Actor1964Field(ownerAddress18, signed char*, 0x52) =
                            retainedIndexConstantOrVectorAddress16;
                        Actor1964RefreshMobySpatialGridAndBasis(argumentWord4, argumentWord5);
                        temporaryWord53 = Actor1964Field(privateAddress19, void**, 0x38);
                        Actor1964Field(privateAddress19, void**, 0x2C) = temporaryWord53;
                        Actor1964Field(temporaryWord53, short*, 2) =
                            (short)(Actor1964Field(temporaryWord53, unsigned short*, 0) - 2);
                        temporaryWord28 = Actor1964Field(privateAddress19, void**, 0x2C);
                        Actor1964CopyVector(
                            retainedOwnerPositionAddress17,
                            Actor1964Field(temporaryWord28, int*, 0xC) +
                                (Actor1964Field(temporaryWord28, short*, 2) * 0x10));
                        temporaryWord62 = Actor1964Field(privateAddress19, void**, 0x2C);
                        Actor1964Field(temporaryWord62, short*, 2) =
                            (short)(Actor1964Field(temporaryWord62, unsigned short*, 0) - 1);
                        temporaryWord68 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord35 = (Actor1964Field(temporaryWord68, short*, 2) * 0x10) +
                                          Actor1964Field(temporaryWord68, int*, 0xC);
                        resultWord2 = Actor1964PlanarHeadingLookup(
                            Actor1964Field(temporaryWord35, int*, 0) -
                                Actor1964Field(ownerAddress18, int*, 0xC),
                            Actor1964Field(temporaryWord35, int*, 4) -
                                Actor1964Field(ownerAddress18, int*, 0x10),
                            0);
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        Actor1964Field(ownerAddress18, unsigned char*, 0x46) = resultWord2;
                        Actor1964_func_80037014(argumentWord4);
                        __asm__ volatile("" ::"i"(0), "i"(0) : "memory");
                        argumentWord4 = ownerAddress18;
                        argumentWord5 = 2;
                        Actor1964Field(ownerAddress18, signed char*, 0x52) =
                            retainedIndexConstantOrVectorAddress16;
                        Actor1964RefreshMobySpatialGridAndBasis(argumentWord4, argumentWord5);
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 0;
                        Actor1964Field(argumentWord4, unsigned char*, 0x49) = 10;
                        __asm__ volatile("" ::"m"(Actor1964_D_80071583));
                        Actor1964Field(argumentWord4, unsigned char*, 0x48) = 0;
                    } else if (Actor1964_D_80071570 != 0) {
                        temporaryWord69 = Actor1964Field(privateAddress19, void**, 0x34);
                        Actor1964Field(privateAddress19, void**, 0x2C) = temporaryWord69;
                        Actor1964Field(temporaryWord69, short*, 2) =
                            (short)(Actor1964Field(temporaryWord69, unsigned short*, 0) - 2);
                        temporaryWord36 = Actor1964Field(privateAddress19, void**, 0x2C);
                        Actor1964CopyVector(
                            ownerAddress18 + 0xC,
                            Actor1964Field(temporaryWord36, int*, 0xC) +
                                (Actor1964Field(temporaryWord36, short*, 2) * 0x10));
                        temporaryWord70 = Actor1964Field(privateAddress19, void**, 0x2C);
                        Actor1964Field(temporaryWord70, short*, 2) =
                            (short)((unsigned short)Actor1964Field(temporaryWord70, short*, 2) + 1);
                        temporaryWord71 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord37 = (Actor1964Field(temporaryWord71, short*, 2) * 0x10) +
                                          Actor1964Field(temporaryWord71, int*, 0xC);
                        resultWord2 = Actor1964PlanarHeadingLookup(
                            Actor1964Field(temporaryWord37, int*, 0) -
                                Actor1964Field(ownerAddress18, int*, 0xC),
                            Actor1964Field(temporaryWord37, int*, 4) -
                                Actor1964Field(ownerAddress18, int*, 0x10),
                            0);
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        Actor1964Field(ownerAddress18, unsigned char*, 0x46) = resultWord2;
                        Actor1964_func_80037014(argumentWord4);
                        __asm__ volatile("" ::"i"(0), "i"(0) : "memory");
                        argumentWord4 = ownerAddress18;
                        argumentWord5 = 2;
                        MATCHING_KEEP2(argumentWord4, argumentWord5);
                        resultWord2 = 254;
                        Actor1964Keep(resultWord2);
                        Actor1964Field(ownerAddress18, signed char*, 0x52) = resultWord2;
                        Actor1964RefreshMobySpatialGridAndBasis(argumentWord4, argumentWord5);
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 0;
                        Actor1964Field(argumentWord4, unsigned char*, 0x49) = 2;
                        __asm__ volatile("" ::"m"(Actor1964_D_80071570));
                        Actor1964Field(argumentWord4, unsigned char*, 0x48) = 0;
                    } else {
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord6 = 1;
                        Actor1964Keep(argumentWord6);
                        Actor1964_D_80071570 = argumentWord6;
                        resultWord2 = Actor1964Field(privateAddress19, void**, 52);
                        __asm__ volatile("" ::: "$5", "memory");
                        argumentWord5 = 2;
                        __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "r"(argumentWord5));
                        Actor1964Field(privateAddress19, void**, 44) = resultWord2;
                        Actor1964Field(resultWord2, short*, 2) = 0;
                        intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
                        resultWord2 = 1;
                        Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
                        resultWord2 = 255;
                        Actor1964Keep(resultWord2);
                        Actor1964Field(argumentWord4, signed char*, 74) = resultWord2;
                        resultWord2 = 2;
                        Actor1964Field(argumentWord4, unsigned char*, 73) = argumentWord6;
                        goto storeOriginalSubstate48;
                    }
                    goto callOriginalAnimationAndReturn;
                    default:
                        return;
                }
                goto deleteOriginalOwnerAndReturn;
            }
            resultWord2 = Actor1964_D_8007157A;
            if (resultWord2 ? (resultWord2 = 1, 1) : (resultWord2 = 1, 0))
                goto storeOriginalGlobal7157AOne;
            resultWord2 = Actor1964_D_8006C7B4;
            resultWord2 &= 8;
            if (resultWord2 ? (resultWord2 = 1, 1) : (resultWord2 = 1, 0))
                goto storeOriginalGlobal7157AOne;
            resultWord2 = Actor1964Field((int)&Actor1964_D_80070300 + Actor1964_D_8006C58C,
                                         unsigned char*, 0);
            resultWord2 &= 8;
            if (resultWord2 ? (resultWord2 = 1, 1) : (resultWord2 = 1, 0))
                goto storeOriginalGlobal7157AOne;
            MATCHING_OBSERVE_VOLATILE(resultWord2);
            goto storeOriginalOuterState2;
        case 1:
            outer1Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer1Substate48) {
                case 2:
                    retainedIndexConstantOrVectorAddress16 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2);
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    argumentWord4 = Actor1964_func_80035A80(
                        ownerAddress18, Actor1964Field(privateAddress19, void**, 0x2C), 0x200, 0xC0,
                        0, 8, 0x18, 5);
                    Actor1964Keep(argumentWord4);
                    __asm__ volatile("" ::"i"(1), "i"(2) : "memory");
                    resultWord2 = argumentWord4 & 1;
                    Actor1964Keep(resultWord2);
                    if (resultWord2) {
                        temporaryWord38 = Actor1964Field(privateAddress19, void**, 0x2C);
                        argumentWord5 = 0;
                        if (Actor1964Field(temporaryWord38, short*, 2) ==
                            ((short)Actor1964Field(temporaryWord38, unsigned short*, 0) - 1)) {
                            Actor1964Field(ownerAddress18, unsigned char*, 72) = 0;
                            __asm__ volatile("" ::"i"(1), "i"(2));
                            argumentWord4 = ownerAddress18;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    temporaryWord40 = Actor1964Field(privateAddress19, void**, 0x2C);
                    pathCountOrPointArray8 = Actor1964Field(temporaryWord40, int*, 0xC);
                    resultWord2 =
                        retainedIndexConstantOrVectorAddress16 * 16 + pathCountOrPointArray8;
                    resultWord2 = Actor1964Field(resultWord2, int*, 12);
                    MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                    resultWord2 &= 1;
                    if (resultWord2) {
                        resultWord2 = argumentWord4 & 1;
                        Actor1964Keep(resultWord2);
                        argumentWord4 = ownerAddress18 + 12;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                argumentWord4,
                                pathCountOrPointArray8 +
                                    (Actor1964Field(temporaryWord40, short*, 2) * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(1), "i"(2) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            __asm__ volatile("" ::"i"(1), "i"(2));
                            goto produceOriginalSubstateFour;
                        }
                        resultWord2 = Actor1964ApproximatePlanarDistance(
                            argumentWord4, pathCountOrPointArray8 +
                                               (Actor1964Field(temporaryWord40, short*, 2) * 0x10));
                        __asm__ volatile("" ::"i"(1), "i"(2) : "memory");
                        if (resultWord2 < 0x780) {
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 3U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 3;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 4:
                    retainedIndexConstantOrVectorAddress16 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2);
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    resultWord2 = Actor1964_func_80035A80(
                        ownerAddress18, Actor1964Field(privateAddress19, void**, 0x2C), 0x200, 0xC0,
                        0, 8, 0x18, 0x10000);
                    __asm__ volatile("" ::"i"(1), "i"(4) : "memory");
                    if (resultWord2 & 1) {
                        temporaryWord1 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord6 = Actor1964Field(temporaryWord1, short*, 2);
                        if (temporaryWord6 ==
                            ((short)Actor1964Field(temporaryWord1, unsigned short*, 0) - 1)) {
                            Actor1964_func_80037014(ownerAddress18);
                            __asm__ volatile("" ::"i"(1), "i"(4) : "memory");
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 0;
                            goto callOriginalAnimationAndReturn;
                        }
                        temporaryWord41 = Actor1964Field(temporaryWord1, int*, 0xC);
                        resultWord2 = retainedIndexConstantOrVectorAddress16 * 16 + temporaryWord41;
                        resultWord2 = Actor1964Field(resultWord2, int*, 12);
                        MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                        resultWord2 &= 1;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                ownerAddress18 + 0xC, temporaryWord41 + (temporaryWord6 * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(1), "i"(4) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            resultWord2 = 3;
                            __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(1), "i"(4));
                            Actor1964Field(argumentWord4, signed char*, 61) = resultWord2;
                            goto callOriginalAnimationAndReturn;
                        }
                        goto updateOriginalOuter1Height;
                    }
                updateOriginalOuter1Height:
                    temporaryWord12 = Actor1964Field(privateAddress19, int*, 0x30) - 8;
                    Actor1964Field(privateAddress19, int*, 0x30) = temporaryWord12;
                    Actor1964Field(ownerAddress18, int*, 0x14) =
                        (int)(Actor1964Field(ownerAddress18, int*, 0x14) + temporaryWord12);
                    Actor1964CopyVector(&originalFrame.sp20, ownerAddress18 + 0xC);
                    originalFrame.sp28 += 0x200;
                    resultWord2 = Actor1964_func_8001A358(&originalFrame.sp20, 0x200);
                    __asm__ volatile("" ::"i"(1), "i"(4) : "memory");
                    if (resultWord2 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 2U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 2;
                        goto callOriginalAnimationAndReturn;
                    }
                    intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 60);
                    resultWord2 = 3;
                    if (intermediateWord3 == resultWord2) {
                        resultWord2 = Actor1964_D_8006C770;
                        __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(1), "i"(4));
                        if (resultWord2) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 4;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 0:
                    goto evaluateOriginalSharedOuter1Or5Heading;
                case 3:
                    goto originalSharedSubstate3;
            }
            break;
        case 2:
            outer2Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer2Substate48) {
                case 0:
                    retainedIndexConstantOrVectorAddress16 = 1;
                    Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                    if ((Actor1964Field(privateAddress19, unsigned char*, 0) == 5) &&
                        ((Actor1964_D_8007157A != 0) || (Actor1964_D_8006C7B4 & 8) ||
                         (Actor1964Field((int)&Actor1964_D_80070300 + Actor1964_D_8006C58C,
                                         unsigned char*, 0) &
                          8))) {
                        resultWord2 = 1;
                    storeOriginalGlobal7157AOne:
                        Actor1964_D_8007157A = resultWord2;
                    deleteOriginalOwnerAndReturn:
                        Actor1964DeleteMoby(ownerAddress18);
                        return;
                    }
                    retainedIndexConstantOrVectorAddress16 = 1;
                    Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                    Actor1964Field(privateAddress19, signed char*, 5) =
                        retainedIndexConstantOrVectorAddress16;
                    __asm__ volatile("" ::"i"(2), "i"(0));
                    resultWord2 = Actor1964_func_80037BBC(ownerAddress18, 0);
                    __asm__ volatile("" ::"i"(2), "i"(0) : "memory");
                    if (resultWord2 != 0) {
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 0;
                        Actor1964Keep(argumentWord5);
                        argumentWord6 = 1;
                        goto callOriginalShared512E4WithSavedOne;
                    }
                    if ((Actor1964Field((int)&Actor1964_D_80070328, int*, 0xB8) == 0) &&
                        (Actor1964CopyVector(&originalFrame.sp20,
                                             ((int)&Actor1964_D_80070328 + 0xB8) - 0xB8),
                         originalFrame.sp28 -=
                         Actor1964Field((int)&Actor1964_D_80070328, int*, 0x44),
                         (Actor1964Field(privateAddress19, unsigned char*, 0) == 0))) {
                        if (Actor1964_func_80036220(&originalFrame.sp20, privateAddress19 + 0x58, 0,
                                                    0x100) != 0) {
                            argumentWord4 = ownerAddress18;
                            resultWord2 = Actor1964Field(privateAddress19, void**, 56);
                            intermediateWord3 = 1;
                            Actor1964Field(privateAddress19, void**, 44) = resultWord2;
                            Actor1964Field(resultWord2, short*, 2) = intermediateWord3;
                            resultWord2 = Actor1964Field(privateAddress19, void**, 44);
                            argumentWord5 = 2;
                            Actor1964Field(resultWord2, short*, 10) = intermediateWord3;
                            __asm__ volatile("" ::"i"(2), "i"(0));
                            resultWord2 = 3;
                            goto storeOriginalOuterState49;
                        }
                        if (Actor1964_func_80036220(&originalFrame.sp20, privateAddress19 + 0x40, 0,
                                                    0x100) != 0) {
                            argumentWord4 = (int)&originalFrame.sp20;
                            Actor1964Keep(argumentWord4);
                            resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                            resultWord2 *= 2;
                            intermediateWord3 =
                                Actor1964Field((int)&Actor1964_D_80065920 + resultWord2, short*, 0);
                            resultWord2 = (intermediateWord3 * 13) >> 5;
                            originalFrame.sp20 = resultWord2;
                            resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                            argumentWord5 = argumentWord4;
                            resultWord2 *= 2;
                            intermediateWord3 =
                                Actor1964Field((int)&Actor1964_D_800658A0 + resultWord2, short*, 0);
                            __asm__ volatile("" ::: "$6", "memory");
                            argumentWord6 = ownerAddress18 + 12;
                            MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                            originalFrame.sp28 = 0;
                            __asm__ volatile("" ::"m"(originalFrame.sp28));
                            resultWord2 = (intermediateWord3 * 13) >> 5;
                            originalFrame.sp24 = resultWord2;
                            Actor1964AddVector(argumentWord4, argumentWord5, argumentWord6);
                            __asm__ volatile("" ::"i"(2), "i"(0) : "memory");
                            argumentWord4 = (int)&originalFrame.sp20;
                            argumentWord6 = 0;
                            argumentWord5 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                            MATCHING_KEEP3_CLOBBER(argumentWord4, argumentWord5, argumentWord6,
                                                   "memory");
                            resultWord2 = (int)Actor1964_unk_ovlheader_80074330;
                            __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(2), "i"(0));
                            ((void (*)(void*, int, int))resultWord2)(
                                argumentWord4, argumentWord5 + 128, argumentWord6);
                            Actor1964Field(privateAddress19, signed char*, 5) =
                                retainedIndexConstantOrVectorAddress16;
                            return;
                        }
                    }
                    break;
                case 1:
                    if (Actor1964_D_8006E344 != outer2Substate48) {
                        if (Actor1964Field(privateAddress19, unsigned char*, 0) == 0) {
                            argumentWord4 = ownerAddress18;
                            resultWord2 = Actor1964Field(privateAddress19, void**, 56);
                            intermediateWord3 = 1;
                            Actor1964Field(privateAddress19, void**, 44) = resultWord2;
                            Actor1964Field(resultWord2, short*, 2) = intermediateWord3;
                            resultWord2 = Actor1964Field(privateAddress19, void**, 44);
                            argumentWord5 = 2;
                            Actor1964Field(resultWord2, short*, 10) = intermediateWord3;
                            __asm__ volatile("" ::"i"(2), "i"(1));
                            resultWord2 = 3;
                            goto storeOriginalOuterState49;
                        }
                        Actor1964_D_8007157A = 1;
                        __asm__ volatile("" ::"i"(2), "i"(1));
                        goto storeOriginalOuterState6AndClear;
                    }
                    break;
            }
            break;
        case 3:
            outer3Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer3Substate48) {
                case 0:
                    temporaryWord45 = Actor1964Field(privateAddress19, void**, 0x2C);
                    temporaryWord15 = (Actor1964Field(temporaryWord45, short*, 2) * 0x10) +
                                      Actor1964Field(temporaryWord45, int*, 0xC);
                    if (Actor1964TurnMobyTowardHeading(
                            ownerAddress18,
                            Actor1964PlanarHeadingLookup(
                                Actor1964Field(temporaryWord15, int*, 0) -
                                    Actor1964Field(ownerAddress18, int*, 0xC),
                                Actor1964Field(temporaryWord15, int*, 4) -
                                    Actor1964Field(ownerAddress18, int*, 0x10),
                                0),
                            8, 8, 1, 0) != 0) {
                        Actor1964Field(ownerAddress18, signed char*, 0x4A) = 0x10;
                        __asm__ volatile("" ::"i"(3), "i"(0));
                        Actor1964Field(ownerAddress18, unsigned char*, 0x49) = 4U;
                        return;
                    }
                    break;
                case 2:
                    retainedIndexConstantOrVectorAddress16 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2);
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    argumentWord4 = Actor1964_func_80035A80(
                        ownerAddress18, Actor1964Field(privateAddress19, void**, 0x2C), 0x200, 0xC0,
                        0, 8, 0x18, 5);
                    Actor1964Keep(argumentWord4);
                    __asm__ volatile("" ::"i"(3), "i"(2) : "memory");
                    resultWord2 = argumentWord4 & 1;
                    Actor1964Keep(resultWord2);
                    if (resultWord2) {
                        temporaryWord16 = Actor1964Field(privateAddress19, void**, 0x2C);
                        argumentWord5 = 0;
                        if (Actor1964Field(temporaryWord16, short*, 2) ==
                            ((short)Actor1964Field(temporaryWord16, unsigned short*, 0) - 1)) {
                            Actor1964Field(ownerAddress18, unsigned char*, 72) = 0;
                            __asm__ volatile("" ::"i"(3), "i"(2));
                            argumentWord4 = ownerAddress18;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    temporaryWord46 = Actor1964Field(privateAddress19, void**, 0x2C);
                    pathCountOrPointArray8 = Actor1964Field(temporaryWord46, int*, 0xC);
                    resultWord2 =
                        retainedIndexConstantOrVectorAddress16 * 16 + pathCountOrPointArray8;
                    resultWord2 = Actor1964Field(resultWord2, int*, 12);
                    MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                    resultWord2 &= 1;
                    if (resultWord2) {
                        resultWord2 = argumentWord4 & 1;
                        Actor1964Keep(resultWord2);
                        argumentWord4 = ownerAddress18 + 12;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                argumentWord4,
                                pathCountOrPointArray8 +
                                    (Actor1964Field(temporaryWord46, short*, 2) * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(3), "i"(2) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            __asm__ volatile("" ::"i"(3), "i"(2));
                            goto produceOriginalSubstateFour;
                        }
                        resultWord2 = Actor1964ApproximatePlanarDistance(
                            argumentWord4, pathCountOrPointArray8 +
                                               (Actor1964Field(temporaryWord46, short*, 2) * 0x10));
                        __asm__ volatile("" ::"i"(3), "i"(2) : "memory");
                        if (resultWord2 < 0x780) {
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 3U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 3;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 3:
                    goto originalSharedSubstate3;
                case 4:
                    retainedIndexConstantOrVectorAddress16 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2);
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    resultWord2 = Actor1964_func_80035A80(
                        ownerAddress18, Actor1964Field(privateAddress19, void**, 0x2C), 0x200, 0xC0,
                        0, 8, 0x18, 0x10000);
                    __asm__ volatile("" ::"i"(3), "i"(4) : "memory");
                    if (resultWord2 & 1) {
                        temporaryWord2 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord7 = Actor1964Field(temporaryWord2, short*, 2);
                        if (temporaryWord7 ==
                            ((short)Actor1964Field(temporaryWord2, unsigned short*, 0) - 1)) {
                            Actor1964_func_80037014(ownerAddress18);
                            __asm__ volatile("" ::"i"(3), "i"(4) : "memory");
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 0;
                            goto callOriginalAnimationAndReturn;
                        }
                        temporaryWord47 = Actor1964Field(temporaryWord2, int*, 0xC);
                        resultWord2 = retainedIndexConstantOrVectorAddress16 * 16 + temporaryWord47;
                        resultWord2 = Actor1964Field(resultWord2, int*, 12);
                        MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                        resultWord2 &= 1;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                ownerAddress18 + 0xC, temporaryWord47 + (temporaryWord7 * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(3), "i"(4) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            resultWord2 = 3;
                            __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(3), "i"(4));
                            Actor1964Field(argumentWord4, signed char*, 61) = resultWord2;
                            goto callOriginalAnimationAndReturn;
                        }
                        goto updateOriginalOuter3Height;
                    }
                updateOriginalOuter3Height:
                    retainedIndexConstantOrVectorAddress16 = (int)&originalFrame.sp30;
                    Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                    argumentWord4 = retainedIndexConstantOrVectorAddress16;
                    Actor1964Keep(argumentWord4);
                    intermediateWord3 = Actor1964Field(privateAddress19, int*, 48);
                    __asm__ volatile("" ::: "$17", "memory");
                    retainedOwnerPositionAddress17 = ownerAddress18 + 12;
                    intermediateWord3 -= 8;
                    Actor1964Field(privateAddress19, int*, 48) = intermediateWord3;
                    resultWord2 = Actor1964Field(ownerAddress18, int*, 20);
                    argumentWord5 = retainedOwnerPositionAddress17;
                    resultWord2 += intermediateWord3;
                    Actor1964Field(ownerAddress18, int*, 20) = resultWord2;
                    Actor1964CopyVector(argumentWord4, argumentWord5);
                    originalFrame.sp38 += 0x200;
                    resultWord2 =
                        Actor1964_func_8001A358(retainedIndexConstantOrVectorAddress16, 0x200);
                    __asm__ volatile("" ::"i"(3), "i"(4) : "memory");
                    if (resultWord2 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    temporaryWord17 = Actor1964Field(privateAddress19, void**, 0x2C);
                    resultWord2 = Actor1964ApproximatePlanarDistance(
                        retainedOwnerPositionAddress17,
                        Actor1964Field(temporaryWord17, int*, 0xC) +
                            (Actor1964Field(temporaryWord17, short*, 2) * 0x10));
                    __asm__ volatile("" ::"i"(3), "i"(4) : "memory");
                    if (resultWord2 < 0x900) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 60);
                    resultWord2 = 3;
                    if (intermediateWord3 == resultWord2) {
                        resultWord2 = Actor1964_D_8006C770;
                        __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(3), "i"(4));
                        if (resultWord2) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 4;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 5:
                    if (Actor1964_func_80055E84(ownerAddress18) < 0xC) {
                        Actor1964_func_80035A80(ownerAddress18,
                                                Actor1964Field(privateAddress19, void**, 0x2C),
                                                0x200, 0xC0, 0, 8, 0x18, 0x10000);
                        __asm__ volatile("" ::"i"(3), "i"(5) : "memory");
                    }
                    temporaryWord48 = Actor1964Field(privateAddress19, int*, 0x30) - 8;
                    Actor1964Field(privateAddress19, int*, 0x30) = temporaryWord48;
                    Actor1964Field(ownerAddress18, int*, 0x14) =
                        (int)(Actor1964Field(ownerAddress18, int*, 0x14) + temporaryWord48);
                    Actor1964CopyVector(&originalFrame.sp40, ownerAddress18 + 0xC);
                    originalFrame.sp48 += 0x200;
                    temporaryWord18 = Actor1964_func_8001A358(&originalFrame.sp40, 0x200);
                    __asm__ volatile("" ::"i"(3), "i"(5) : "memory");
                    originalFrame.sp48 = temporaryWord18;
                    if (temporaryWord18 != 0) {
                        Actor1964Field(ownerAddress18, int*, 0x14) = temporaryWord18;
                        Actor1964Field(privateAddress19, int*, 0x30) = 0;
                    }
                    if (Actor1964_D_8006C770 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 2U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 2;
                        goto callOriginalAnimationAndReturn;
                    }
                    break;
            }
            break;
        case 4:
            intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 72);
            if (intermediateWord3 == 0) {
                if (Actor1964Field((int)&Actor1964_D_80070328, int*, 8) <
                    (Actor1964Field(ownerAddress18, int*, 0x14) - 0x100)) {
                    argumentWord4 = ownerAddress18;
                    intermediateWord3 = Actor1964Field(privateAddress19, void**, 56);
                    Actor1964Field(privateAddress19, void**, 44) = intermediateWord3;
                    resultWord2 = Actor1964Field(intermediateWord3, unsigned short*, 0);
                    argumentWord5 = 2;
                    resultWord2 -= 1;
                    Actor1964Field(intermediateWord3, short*, 2) = resultWord2;
                    intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
                    resultWord2 = -1;
                    Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
                    resultWord2 = 5;
                    goto storeOriginalOuterState49;
                }
                retainedIndexConstantOrVectorAddress16 = &originalFrame.sp30;
                if (Actor1964Field((int)&Actor1964_D_80070328, int*, 0xB8) == 0) {
                    Actor1964CopyVector(retainedIndexConstantOrVectorAddress16,
                                        ((int)&Actor1964_D_80070328 + 8) - 8);
                    originalFrame.sp38 -= Actor1964Field((int)&Actor1964_D_80070328, int*, 0x44);
                    if (Actor1964_func_80036220(retainedIndexConstantOrVectorAddress16,
                                                privateAddress19 + 0x58, 0, 0x100) != 0) {
                        if ((unsigned char)Actor1964Field(privateAddress19, unsigned char*, 2) <
                            2U) {
                            Actor1964Field(privateAddress19, unsigned char*, 2) = 2U;
                            __asm__ volatile("" ::"i"(4), "i"(4));
                        }
                        resultWord2 = Actor1964_func_80037BBC(ownerAddress18, 0);
                        __asm__ volatile("" ::"i"(4), "i"(4) : "memory");
                        if (resultWord2 != 0) {
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 0;
                            argumentWord6 = 1;
                            MATCHING_KEEP3(argumentWord4, argumentWord5, argumentWord6);
                            retainedIndexConstantOrVectorAddress16 = 1;
                            Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                            Actor1964_D_80071583 = retainedIndexConstantOrVectorAddress16;
                            __asm__ volatile("" ::"i"(4), "i"(4));
                        callOriginalShared512E4WithSavedOne:
                            Actor1964_func_800512E4(argumentWord4, argumentWord5, argumentWord6);
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) =
                                retainedIndexConstantOrVectorAddress16;
                            return;
                        }
                        resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                        resultWord2 *= 2;
                        intermediateWord3 =
                            Actor1964Field((int)&Actor1964_D_80065920 + resultWord2, short*, 0);
                        __asm__ volatile("" ::: "$4", "memory");
                        argumentWord4 = retainedIndexConstantOrVectorAddress16;
                        Actor1964Keep(argumentWord4);
                        resultWord2 = (intermediateWord3 * 13) >> 5;
                        originalFrame.sp30 = resultWord2;
                        resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                        argumentWord5 = retainedIndexConstantOrVectorAddress16;
                        resultWord2 *= 2;
                        intermediateWord3 =
                            Actor1964Field((int)&Actor1964_D_800658A0 + resultWord2, short*, 0);
                        __asm__ volatile("" ::: "$6", "memory");
                        argumentWord6 = ownerAddress18 + 12;
                        MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                        originalFrame.sp38 = 0;
                        __asm__ volatile("" ::"m"(originalFrame.sp38));
                        resultWord2 = (intermediateWord3 * 13) >> 5;
                        originalFrame.sp34 = resultWord2;
                        goto addOriginalLocalVectorAndCallHeader;
                    }
                    if (Actor1964_func_80036220(retainedIndexConstantOrVectorAddress16,
                                                privateAddress19 + 0x70, 0, 0x100) != 0) {
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        Actor1964_D_80071583 = 1;
                        argumentWord5 = 2;
                        goto selectOriginalPrivate3CPath;
                    }
                }
            } else {
                goto testOriginalSharedSubstate1;
            }
            break;
        case 5:
            outer5Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer5Substate48) {
                case 0:
                evaluateOriginalSharedOuter1Or5Heading:
                    temporaryWord42 = Actor1964Field(privateAddress19, void**, 0x2C);
                    temporaryWord13 = (Actor1964Field(temporaryWord42, short*, 2) * 0x10) +
                                      Actor1964Field(temporaryWord42, int*, 0xC);
                    if (Actor1964TurnMobyTowardHeading(
                            ownerAddress18,
                            Actor1964PlanarHeadingLookup(
                                Actor1964Field(temporaryWord13, int*, 0) -
                                    Actor1964Field(ownerAddress18, int*, 0xC),
                                Actor1964Field(temporaryWord13, int*, 4) -
                                    Actor1964Field(ownerAddress18, int*, 0x10),
                                0),
                            8, 8, 1, 0) != 0) {
                        Actor1964Field(ownerAddress18, signed char*, 0x4A) = 0x10;
                    storeOriginalOuterState2:
                        Actor1964Field(ownerAddress18, unsigned char*, 0x49) = 2U;
                        return;
                    }
                    break;
                case 2:
                    argumentWord4 = ownerAddress18;
                    argumentWord6 = 512;
                    MATCHING_KEEP2(argumentWord4, argumentWord6);
                    temporaryWord20 = Actor1964Field(privateAddress19, void**, 0x2C);
                    intermediateWord3 = Actor1964Field(temporaryWord20, short*, 2);
                    pathCountOrPointArray8 =
                        (short)Actor1964Field(temporaryWord20, unsigned short*, 0);
                    resultWord2 = pathCountOrPointArray8 - 1;
                    Actor1964Keep(resultWord2);
                    intermediateWord3 += resultWord2;
                    retainedIndexConstantOrVectorAddress16 =
                        intermediateWord3 % pathCountOrPointArray8;
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    argumentWord4 = Actor1964_func_80035A80(
                        argumentWord4, Actor1964Field(privateAddress19, void**, 0x2C),
                        argumentWord6, 0xC0, 0, 8, 0x18, 5);
                    Actor1964Keep(argumentWord4);
                    __asm__ volatile("" ::"i"(5), "i"(2) : "memory");
                    resultWord2 = argumentWord4 & 1;
                    Actor1964Keep(resultWord2);
                    if (resultWord2) {
                        temporaryWord21 = Actor1964Field(privateAddress19, void**, 0x2C);
                        if (Actor1964Field(temporaryWord21, short*, 2) ==
                            ((short)Actor1964Field(temporaryWord21, unsigned short*, 0) - 1)) {
                            resultWord2 = 1;
                            intermediateWord3 = Actor1964Field(privateAddress19, void**, 52);
                            Actor1964Field(privateAddress19, void**, 44) = intermediateWord3;
                            Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
                            intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
                            argumentWord4 = ownerAddress18;
                            resultWord2 = Actor1964Field(intermediateWord3, unsigned short*, 0);
                            argumentWord5 = 0;
                            resultWord2 -= 1;
                            Actor1964Field(intermediateWord3, short*, 2) = resultWord2;
                            __asm__ volatile("" ::"i"(5), "i"(2));
                            goto clearOriginalSubstateAfterReversePath;
                        }
                    }
                    temporaryWord51 = Actor1964Field(privateAddress19, void**, 0x2C);
                    pathCountOrPointArray8 = Actor1964Field(temporaryWord51, int*, 0xC);
                    resultWord2 =
                        retainedIndexConstantOrVectorAddress16 * 16 + pathCountOrPointArray8;
                    resultWord2 = Actor1964Field(resultWord2, int*, 12);
                    MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                    resultWord2 &= 1;
                    if (resultWord2) {
                        resultWord2 = argumentWord4 & 1;
                        Actor1964Keep(resultWord2);
                        argumentWord4 = ownerAddress18 + 12;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                argumentWord4,
                                pathCountOrPointArray8 +
                                    (Actor1964Field(temporaryWord51, short*, 2) * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(5), "i"(2) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            __asm__ volatile("" ::"i"(5), "i"(2));
                            goto produceOriginalSubstateFour;
                        }
                        resultWord2 = Actor1964ApproximatePlanarDistance(
                            argumentWord4, pathCountOrPointArray8 +
                                               (Actor1964Field(temporaryWord51, short*, 2) * 0x10));
                        __asm__ volatile("" ::"i"(5), "i"(2) : "memory");
                        if (resultWord2 < 0x780) {
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 3U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 3;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 3:
                    goto originalSharedSubstate3;
                case 4:
                    argumentWord4 = ownerAddress18;
                    argumentWord6 = 512;
                    MATCHING_KEEP2(argumentWord4, argumentWord6);
                    temporaryWord22 = Actor1964Field(privateAddress19, void**, 0x2C);
                    intermediateWord3 = Actor1964Field(temporaryWord22, short*, 2);
                    pathCountOrPointArray8 =
                        (short)Actor1964Field(temporaryWord22, unsigned short*, 0);
                    resultWord2 = pathCountOrPointArray8 - 1;
                    Actor1964Keep(resultWord2);
                    intermediateWord3 += resultWord2;
                    retainedIndexConstantOrVectorAddress16 =
                        intermediateWord3 % pathCountOrPointArray8;
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    resultWord2 = Actor1964_func_80035A80(
                        argumentWord4, Actor1964Field(privateAddress19, void**, 0x2C),
                        argumentWord6, 0xC0, 0, 8, 0x18, 0x10000);
                    __asm__ volatile("" ::"i"(5), "i"(4) : "memory");
                    if (resultWord2 & 1) {
                        temporaryWord3 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord8 = Actor1964Field(temporaryWord3, short*, 2);
                        if (temporaryWord8 ==
                            ((short)Actor1964Field(temporaryWord3, unsigned short*, 0) - 1)) {
                            Actor1964_func_80037014(ownerAddress18);
                            __asm__ volatile("" ::"i"(5), "i"(4) : "memory");
                            resultWord2 = 1;
                            intermediateWord3 = Actor1964Field(privateAddress19, void**, 52);
                            Actor1964Field(privateAddress19, void**, 44) = intermediateWord3;
                            Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
                            intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
                            argumentWord4 = ownerAddress18;
                            resultWord2 = Actor1964Field(intermediateWord3, unsigned short*, 0);
                            argumentWord5 = 0;
                            resultWord2 -= 1;
                            Actor1964Field(intermediateWord3, short*, 2) = resultWord2;
                            __asm__ volatile("" ::"i"(5), "i"(4));
                            goto clearOriginalSubstateAfterReversePath;
                        }
                        temporaryWord52 = Actor1964Field(temporaryWord3, int*, 0xC);
                        resultWord2 = retainedIndexConstantOrVectorAddress16 * 16 + temporaryWord52;
                        resultWord2 = Actor1964Field(resultWord2, int*, 12);
                        MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                        resultWord2 &= 1;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                ownerAddress18 + 0xC, temporaryWord52 + (temporaryWord8 * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(5), "i"(4) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            resultWord2 = 3;
                            __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(5), "i"(4));
                            Actor1964Field(argumentWord4, signed char*, 61) = resultWord2;
                            goto callOriginalAnimationAndReturn;
                        }
                        goto updateOriginalOuter5Height;
                    }
                updateOriginalOuter5Height:
                    retainedIndexConstantOrVectorAddress16 = (int)&originalFrame.sp50;
                    Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                    argumentWord4 = retainedIndexConstantOrVectorAddress16;
                    Actor1964Keep(argumentWord4);
                    intermediateWord3 = Actor1964Field(privateAddress19, int*, 48);
                    __asm__ volatile("" ::: "$17", "memory");
                    retainedOwnerPositionAddress17 = ownerAddress18 + 12;
                    intermediateWord3 -= 8;
                    Actor1964Field(privateAddress19, int*, 48) = intermediateWord3;
                    resultWord2 = Actor1964Field(ownerAddress18, int*, 20);
                    argumentWord5 = retainedOwnerPositionAddress17;
                    resultWord2 += intermediateWord3;
                    Actor1964Field(ownerAddress18, int*, 20) = resultWord2;
                    Actor1964CopyVector(argumentWord4, argumentWord5);
                    originalFrame.sp58 += 0x200;
                    resultWord2 =
                        Actor1964_func_8001A358(retainedIndexConstantOrVectorAddress16, 0x200);
                    __asm__ volatile("" ::"i"(5), "i"(4) : "memory");
                    if (resultWord2 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    temporaryWord23 = Actor1964Field(privateAddress19, void**, 0x2C);
                    resultWord2 = Actor1964ApproximatePlanarDistance(
                        retainedOwnerPositionAddress17,
                        Actor1964Field(temporaryWord23, int*, 0xC) +
                            (Actor1964Field(temporaryWord23, short*, 2) * 0x10));
                    __asm__ volatile("" ::"i"(5), "i"(4) : "memory");
                    if (resultWord2 < 0x900) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 60);
                    resultWord2 = 3;
                    if (intermediateWord3 == resultWord2) {
                        resultWord2 = Actor1964_D_8006C770;
                        __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(5), "i"(4));
                        if (resultWord2) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 4;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 5:
                    if (Actor1964_func_80055E84(ownerAddress18) < 0xC) {
                        Actor1964_func_80035A80(ownerAddress18,
                                                Actor1964Field(privateAddress19, void**, 0x2C),
                                                0x200, 0xC0, 0, 8, 0x18, 0x10000);
                        __asm__ volatile("" ::"i"(5), "i"(5) : "memory");
                    }
                    temporaryWord54 = Actor1964Field(privateAddress19, int*, 0x30) - 8;
                    Actor1964Field(privateAddress19, int*, 0x30) = temporaryWord54;
                    Actor1964Field(ownerAddress18, int*, 0x14) =
                        (int)(Actor1964Field(ownerAddress18, int*, 0x14) + temporaryWord54);
                    Actor1964CopyVector(&originalFrame.sp60, ownerAddress18 + 0xC);
                    originalFrame.sp68 += 0x200;
                    temporaryWord24 = Actor1964_func_8001A358(&originalFrame.sp60, 0x200);
                    __asm__ volatile("" ::"i"(5), "i"(5) : "memory");
                    originalFrame.sp68 = temporaryWord24;
                    if (temporaryWord24 != 0) {
                        Actor1964Field(ownerAddress18, int*, 0x14) = temporaryWord24;
                        Actor1964Field(privateAddress19, int*, 0x30) = 0;
                    }
                    if (Actor1964_D_8006C770 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 2U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 2;
                        goto callOriginalAnimationAndReturn;
                    }
                    break;
            }
            break;
        case 6:
            outer6Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer6Substate48) {
                case 0:
                    resultWord2 = Actor1964_func_80037BBC(ownerAddress18, 0);
                    __asm__ volatile("" ::"i"(6), "i"(0) : "memory");
                    if (!resultWord2)
                        return;
                    argumentWord4 = ownerAddress18;
                    Actor1964Keep(argumentWord4);
                    goto callOriginalShared512E4AndSetSubstate1;
                    break;
                case 1:
                    if (Actor1964_D_8006E344 != outer6Substate48) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                        return;
                    }
                    break;
            }
            break;
        case 7:
            outer7Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer7Substate48) {
                case 0:
                    temporaryWord57 = Actor1964Field(privateAddress19, void**, 0x2C);
                    temporaryWord25 = (Actor1964Field(temporaryWord57, short*, 2) * 0x10) +
                                      Actor1964Field(temporaryWord57, int*, 0xC);
                    if (Actor1964TurnMobyTowardHeading(
                            ownerAddress18,
                            Actor1964PlanarHeadingLookup(
                                Actor1964Field(temporaryWord25, int*, 0) -
                                    Actor1964Field(ownerAddress18, int*, 0xC),
                                Actor1964Field(temporaryWord25, int*, 4) -
                                    Actor1964Field(ownerAddress18, int*, 0x10),
                                0),
                            8, 8, 1, 0) != 0) {
                        Actor1964Field(ownerAddress18, signed char*, 0x4A) = 0x10;
                        __asm__ volatile("" ::"i"(7), "i"(0));
                        Actor1964Field(ownerAddress18, unsigned char*, 0x49) = 8U;
                        return;
                    }
                    break;
                case 2:
                    retainedIndexConstantOrVectorAddress16 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2);
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    argumentWord4 = Actor1964_func_80035A80(
                        ownerAddress18, Actor1964Field(privateAddress19, void**, 0x2C), 0x200, 0xC0,
                        0, 8, 0x18, 5);
                    Actor1964Keep(argumentWord4);
                    __asm__ volatile("" ::"i"(7), "i"(2) : "memory");
                    resultWord2 = argumentWord4 & 1;
                    Actor1964Keep(resultWord2);
                    if (resultWord2) {
                        temporaryWord26 = Actor1964Field(privateAddress19, void**, 0x2C);
                        argumentWord5 = 0;
                        if (Actor1964Field(temporaryWord26, short*, 2) ==
                            ((short)Actor1964Field(temporaryWord26, unsigned short*, 0) - 1)) {
                            Actor1964Field(ownerAddress18, unsigned char*, 72) = 0;
                            __asm__ volatile("" ::"i"(7), "i"(2));
                            argumentWord4 = ownerAddress18;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    temporaryWord58 = Actor1964Field(privateAddress19, void**, 0x2C);
                    pathCountOrPointArray8 = Actor1964Field(temporaryWord58, int*, 0xC);
                    resultWord2 =
                        retainedIndexConstantOrVectorAddress16 * 16 + pathCountOrPointArray8;
                    resultWord2 = Actor1964Field(resultWord2, int*, 12);
                    MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                    resultWord2 &= 1;
                    if (resultWord2) {
                        resultWord2 = argumentWord4 & 1;
                        Actor1964Keep(resultWord2);
                        argumentWord4 = ownerAddress18 + 12;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                argumentWord4,
                                pathCountOrPointArray8 +
                                    (Actor1964Field(temporaryWord58, short*, 2) * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(7), "i"(2) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            __asm__ volatile("" ::"i"(7), "i"(2));
                            goto produceOriginalSubstateFour;
                        }
                        resultWord2 = Actor1964ApproximatePlanarDistance(
                            argumentWord4, pathCountOrPointArray8 +
                                               (Actor1964Field(temporaryWord58, short*, 2) * 0x10));
                        __asm__ volatile("" ::"i"(7), "i"(2) : "memory");
                        if (resultWord2 < 0x780) {
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 3U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 3;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 3:
                    goto originalSharedSubstate3;
                case 4:
                    retainedIndexConstantOrVectorAddress16 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), short*, 2);
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    resultWord2 = Actor1964_func_80035A80(
                        ownerAddress18, Actor1964Field(privateAddress19, void**, 0x2C), 0x200, 0xC0,
                        0, 8, 0x18, 0x10000);
                    __asm__ volatile("" ::"i"(7), "i"(4) : "memory");
                    if (resultWord2 & 1) {
                        temporaryWord4 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord9 = Actor1964Field(temporaryWord4, short*, 2);
                        if (temporaryWord9 ==
                            ((short)Actor1964Field(temporaryWord4, unsigned short*, 0) - 1)) {
                            Actor1964_func_80037014(ownerAddress18);
                            __asm__ volatile("" ::"i"(7), "i"(4) : "memory");
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 0;
                            goto callOriginalAnimationAndReturn;
                        }
                        temporaryWord59 = Actor1964Field(temporaryWord4, int*, 0xC);
                        resultWord2 = retainedIndexConstantOrVectorAddress16 * 16 + temporaryWord59;
                        resultWord2 = Actor1964Field(resultWord2, int*, 12);
                        MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                        resultWord2 &= 1;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                ownerAddress18 + 0xC, temporaryWord59 + (temporaryWord9 * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(7), "i"(4) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            resultWord2 = 3;
                            __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(7), "i"(4));
                            Actor1964Field(argumentWord4, signed char*, 61) = resultWord2;
                            goto callOriginalAnimationAndReturn;
                        }
                        goto updateOriginalOuter7Height;
                    }
                updateOriginalOuter7Height:
                    retainedIndexConstantOrVectorAddress16 = (int)&originalFrame.sp40;
                    Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                    argumentWord4 = retainedIndexConstantOrVectorAddress16;
                    Actor1964Keep(argumentWord4);
                    intermediateWord3 = Actor1964Field(privateAddress19, int*, 48);
                    __asm__ volatile("" ::: "$17", "memory");
                    retainedOwnerPositionAddress17 = ownerAddress18 + 12;
                    intermediateWord3 -= 8;
                    Actor1964Field(privateAddress19, int*, 48) = intermediateWord3;
                    resultWord2 = Actor1964Field(ownerAddress18, int*, 20);
                    argumentWord5 = retainedOwnerPositionAddress17;
                    resultWord2 += intermediateWord3;
                    Actor1964Field(ownerAddress18, int*, 20) = resultWord2;
                    Actor1964CopyVector(argumentWord4, argumentWord5);
                    originalFrame.sp48 += 0x200;
                    resultWord2 =
                        Actor1964_func_8001A358(retainedIndexConstantOrVectorAddress16, 0x200);
                    __asm__ volatile("" ::"i"(7), "i"(4) : "memory");
                    if (resultWord2 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    temporaryWord27 = Actor1964Field(privateAddress19, void**, 0x2C);
                    resultWord2 = Actor1964ApproximatePlanarDistance(
                        retainedOwnerPositionAddress17,
                        Actor1964Field(temporaryWord27, int*, 0xC) +
                            (Actor1964Field(temporaryWord27, short*, 2) * 0x10));
                    __asm__ volatile("" ::"i"(7), "i"(4) : "memory");
                    if (resultWord2 < 0x900) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 60);
                    resultWord2 = 3;
                    if (intermediateWord3 == resultWord2) {
                        resultWord2 = Actor1964_D_8006C770;
                        __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(7), "i"(4));
                        if (resultWord2) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 4;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 5:
                    if (Actor1964_func_80055E84(ownerAddress18) < 0xC) {
                        Actor1964_func_80035A80(ownerAddress18,
                                                Actor1964Field(privateAddress19, void**, 0x2C),
                                                0x200, 0xC0, 0, 8, 0x18, 0x10000);
                        __asm__ volatile("" ::"i"(7), "i"(5) : "memory");
                    }
                    temporaryWord60 = Actor1964Field(privateAddress19, int*, 0x30) - 8;
                    Actor1964Field(privateAddress19, int*, 0x30) = temporaryWord60;
                    Actor1964Field(ownerAddress18, int*, 0x14) =
                        (int)(Actor1964Field(ownerAddress18, int*, 0x14) + temporaryWord60);
                    Actor1964CopyVector(&originalFrame.sp50, ownerAddress18 + 0xC);
                    originalFrame.sp58 += 0x200;
                    temporaryWord29 = Actor1964_func_8001A358(&originalFrame.sp50, 0x200);
                    __asm__ volatile("" ::"i"(7), "i"(5) : "memory");
                    originalFrame.sp58 = temporaryWord29;
                    if (temporaryWord29 != 0) {
                        Actor1964Field(ownerAddress18, int*, 0x14) = temporaryWord29;
                        Actor1964Field(privateAddress19, int*, 0x30) = 0;
                    }
                    if (Actor1964_D_8006C770 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 2U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 2;
                        goto callOriginalAnimationAndReturn;
                    }
                    break;
            }
            break;
        case 8:
            outer8Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer8Substate48) {
                case 0:
                    if (Actor1964Field((int)&Actor1964_D_80070328, int*, 8) <
                        (Actor1964Field(ownerAddress18, int*, 0x14) - 0x100)) {
                        argumentWord4 = ownerAddress18;
                        intermediateWord3 = Actor1964Field(privateAddress19, void**, 60);
                        Actor1964Field(privateAddress19, void**, 44) = intermediateWord3;
                        resultWord2 = Actor1964Field(intermediateWord3, unsigned short*, 0);
                        argumentWord5 = 2;
                        resultWord2 -= 3;
                        Actor1964Field(intermediateWord3, short*, 2) = resultWord2;
                        intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
                        resultWord2 = -1;
                        Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
                        resultWord2 = 9;
                        goto storeOriginalOuterState49;
                    }
                    retainedIndexConstantOrVectorAddress16 = &originalFrame.sp40;
                    if (Actor1964Field((int)&Actor1964_D_80070328, int*, 0xB8) == 0) {
                        Actor1964CopyVector(retainedIndexConstantOrVectorAddress16,
                                            ((int)&Actor1964_D_80070328 + 8) - 8);
                        originalFrame.sp48 -=
                            Actor1964Field((int)&Actor1964_D_80070328, int*, 0x44);
                        if (Actor1964_func_80036220(retainedIndexConstantOrVectorAddress16,
                                                    privateAddress19 + 0x70, 0, 0x100) != 0) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            resultWord2 = Actor1964_D_8006C7B4;
                            argumentWord5 = 0;
                            resultWord2 |= 1;
                            Actor1964_D_8006C7B4 = resultWord2;
                            resultWord2 = 2;
                            Actor1964Field(privateAddress19, signed char*, 5) = resultWord2;
                            resultWord2 = Actor1964_func_80037BBC(argumentWord4, argumentWord5);
                            __asm__ volatile("" ::"i"(8), "i"(0) : "memory");
                            argumentWord4 = ownerAddress18;
                            if (resultWord2 != 0)
                                goto callOriginalShared512E4AndSetSubstate1;
                            Actor1964Keep(argumentWord4);
                            {
                                resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                                resultWord2 *= 2;
                                intermediateWord3 = Actor1964Field(
                                    (int)&Actor1964_D_80065920 + resultWord2, short*, 0);
                                __asm__ volatile("" ::: "$4", "memory");
                                argumentWord4 = retainedIndexConstantOrVectorAddress16;
                                Actor1964Keep(argumentWord4);
                                resultWord2 = (intermediateWord3 * 39) >> 6;
                                originalFrame.sp40 = resultWord2;
                                resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                                argumentWord5 = retainedIndexConstantOrVectorAddress16;
                                resultWord2 *= 2;
                                intermediateWord3 = Actor1964Field(
                                    (int)&Actor1964_D_800658A0 + resultWord2, short*, 0);
                                __asm__ volatile("" ::: "$6", "memory");
                                argumentWord6 = ownerAddress18 + 12;
                                MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                                originalFrame.sp48 = 0;
                                __asm__ volatile("" ::"m"(originalFrame.sp48));
                                resultWord2 = (intermediateWord3 * 39) >> 6;
                                originalFrame.sp44 = resultWord2;
                                goto addOriginalLocalVectorAndCallHeader;
                            }
                        }
                    }
                    break;
                case 1:
                    if (Actor1964_D_8006E344 != outer8Substate48) {
                    storeOriginalOuterState6AndClear:
                        Actor1964Field(ownerAddress18, unsigned char*, 0x49) = 6U;
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 0U;
                        return;
                    }
                    break;
            }
            break;
        case 9:
            outer9Substate48 = Actor1964Field(ownerAddress18, unsigned char*, 0x48);
            switch (outer9Substate48) {
                case 0:
                    temporaryWord64 = Actor1964Field(privateAddress19, void**, 0x2C);
                    temporaryWord30 = (Actor1964Field(temporaryWord64, short*, 2) * 0x10) +
                                      Actor1964Field(temporaryWord64, int*, 0xC);
                    if (Actor1964TurnMobyTowardHeading(
                            ownerAddress18,
                            Actor1964PlanarHeadingLookup(
                                Actor1964Field(temporaryWord30, int*, 0) -
                                    Actor1964Field(ownerAddress18, int*, 0xC),
                                Actor1964Field(temporaryWord30, int*, 4) -
                                    Actor1964Field(ownerAddress18, int*, 0x10),
                                0),
                            8, 8, 1, 0) != 0) {
                        Actor1964Field(ownerAddress18, signed char*, 0x4A) = 0x10;
                        __asm__ volatile("" ::"i"(9), "i"(0));
                        Actor1964Field(privateAddress19, signed char*, 5) = 1;
                        __asm__ volatile("" ::"i"(9), "i"(0));
                        Actor1964Field(ownerAddress18, unsigned char*, 0x49) = 0xAU;
                        return;
                    }
                    break;
                case 2:
                    argumentWord4 = ownerAddress18;
                    argumentWord6 = 512;
                    MATCHING_KEEP2(argumentWord4, argumentWord6);
                    temporaryWord31 = Actor1964Field(privateAddress19, void**, 0x2C);
                    intermediateWord3 = Actor1964Field(temporaryWord31, short*, 2);
                    pathCountOrPointArray8 =
                        (short)Actor1964Field(temporaryWord31, unsigned short*, 0);
                    resultWord2 = pathCountOrPointArray8 - 1;
                    Actor1964Keep(resultWord2);
                    intermediateWord3 += resultWord2;
                    retainedIndexConstantOrVectorAddress16 =
                        intermediateWord3 % pathCountOrPointArray8;
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    argumentWord4 = Actor1964_func_80035A80(
                        argumentWord4, Actor1964Field(privateAddress19, void**, 0x2C),
                        argumentWord6, 0xC0, 0, 8, 0x18, 5);
                    Actor1964Keep(argumentWord4);
                    __asm__ volatile("" ::"i"(9), "i"(2) : "memory");
                    resultWord2 = argumentWord4 & 1;
                    Actor1964Keep(resultWord2);
                    if (resultWord2) {
                        temporaryWord65 = Actor1964Field(privateAddress19, void**, 0x2C);
                        argumentWord5 = 0;
                        if (Actor1964Field(temporaryWord65, short*, 2) == 0) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            Actor1964Field(temporaryWord65, short*, 2) = 0;
                            __asm__ volatile("" ::"i"(9), "i"(2));
                            goto clearOriginalSubstateAfterReversePath;
                        }
                        goto testOriginalOuter9PointFlags;
                    }
                testOriginalOuter9PointFlags:
                    pathCountOrPointArray8 =
                        Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C), int*, 0xC);
                    resultWord2 =
                        retainedIndexConstantOrVectorAddress16 * 16 + pathCountOrPointArray8;
                    resultWord2 = Actor1964Field(resultWord2, int*, 12);
                    MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                    resultWord2 &= 1;
                    if (resultWord2) {
                        resultWord2 = argumentWord4 & 1;
                        Actor1964Keep(resultWord2);
                        argumentWord4 = ownerAddress18 + 12;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                argumentWord4,
                                pathCountOrPointArray8 +
                                    (Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C),
                                                    short*, 2) *
                                     0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(9), "i"(2) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            __asm__ volatile("" ::"i"(9), "i"(2));
                            goto produceOriginalSubstateFour;
                        }
                        resultWord2 = Actor1964ApproximatePlanarDistance(
                            argumentWord4,
                            pathCountOrPointArray8 +
                                (Actor1964Field(Actor1964Field(privateAddress19, void**, 0x2C),
                                                short*, 2) *
                                 0x10));
                        __asm__ volatile("" ::"i"(9), "i"(2) : "memory");
                        if (resultWord2 < 0x780) {
                            Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 3U;
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 3;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 3:
                originalSharedSubstate3:
                    if (Actor1964_func_80055E84(ownerAddress18) >= 0xA) {
                        temporaryWord14 = Actor1964Field(privateAddress19, void**, 0x2C);
                        Actor1964Field(privateAddress19, int*, 0x30) = Actor1964_func_800365E4(
                            ownerAddress18 + 0xC,
                            Actor1964Field(temporaryWord14, int*, 0xC) +
                                (Actor1964Field(temporaryWord14, short*, 2) * 0x10),
                            0xC0, -8, 0);
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 4U;
                    }
                    Actor1964_func_80035A80(ownerAddress18,
                                            Actor1964Field(privateAddress19, void**, 0x2C), 0x200,
                                            0xC0, 0, 8, 0x18, 0x10000);
                    return;
                case 4:
                    argumentWord4 = ownerAddress18;
                    argumentWord6 = 512;
                    MATCHING_KEEP2(argumentWord4, argumentWord6);
                    temporaryWord32 = Actor1964Field(privateAddress19, void**, 0x2C);
                    intermediateWord3 = Actor1964Field(temporaryWord32, short*, 2);
                    pathCountOrPointArray8 =
                        (short)Actor1964Field(temporaryWord32, unsigned short*, 0);
                    resultWord2 = pathCountOrPointArray8 - 1;
                    Actor1964Keep(resultWord2);
                    intermediateWord3 += resultWord2;
                    retainedIndexConstantOrVectorAddress16 =
                        intermediateWord3 % pathCountOrPointArray8;
                    MATCHING_KEEP_CLOBBER(retainedIndexConstantOrVectorAddress16, "$7");
                    resultWord2 = Actor1964_func_80035A80(
                        argumentWord4, Actor1964Field(privateAddress19, void**, 0x2C),
                        argumentWord6, 0xC0, 0, 8, 0x18, 0x10000);
                    __asm__ volatile("" ::"i"(9), "i"(4) : "memory");
                    if (resultWord2 & 1) {
                        temporaryWord5 = Actor1964Field(privateAddress19, void**, 0x2C);
                        temporaryWord10 = Actor1964Field(temporaryWord5, short*, 2);
                        if (temporaryWord10 ==
                            ((short)Actor1964Field(temporaryWord5, unsigned short*, 0) - 1)) {
                            Actor1964_func_80037014(ownerAddress18);
                            __asm__ volatile("" ::"i"(9), "i"(4) : "memory");
                            resultWord2 = 1;
                            intermediateWord3 = Actor1964Field(privateAddress19, void**, 52);
                            Actor1964Field(privateAddress19, void**, 44) = intermediateWord3;
                            Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
                            intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
                            argumentWord4 = ownerAddress18;
                            resultWord2 = Actor1964Field(intermediateWord3, unsigned short*, 0);
                            argumentWord5 = 0;
                            resultWord2 -= 1;
                            Actor1964Field(intermediateWord3, short*, 2) = resultWord2;
                            __asm__ volatile("" ::"i"(9), "i"(4));
                            goto clearOriginalSubstateAfterReversePath;
                        }
                        temporaryWord66 = Actor1964Field(temporaryWord5, int*, 0xC);
                        resultWord2 = retainedIndexConstantOrVectorAddress16 * 16 + temporaryWord66;
                        resultWord2 = Actor1964Field(resultWord2, int*, 12);
                        MATCHING_OBSERVE_VOLATILE(retainedIndexConstantOrVectorAddress16);
                        resultWord2 &= 1;
                        if (resultWord2) {
                            resultWord2 = Actor1964_func_800365E4(
                                ownerAddress18 + 0xC, temporaryWord66 + (temporaryWord10 * 0x10),
                                0xC0, -8, 0);
                            __asm__ volatile("" ::"i"(9), "i"(4) : "memory");
                            argumentWord4 = ownerAddress18;
                            argumentWord5 = 4;
                            MATCHING_KEEP2(argumentWord4, argumentWord5);
                            Actor1964Field(privateAddress19, int*, 48) = resultWord2;
                            resultWord2 = 3;
                            __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(9), "i"(4));
                            Actor1964Field(argumentWord4, signed char*, 61) = resultWord2;
                            goto callOriginalAnimationAndReturn;
                        }
                        goto updateOriginalOuter9Height;
                    }
                updateOriginalOuter9Height:
                    retainedIndexConstantOrVectorAddress16 = (int)&originalFrame.sp50;
                    Actor1964Keep(retainedIndexConstantOrVectorAddress16);
                    argumentWord4 = retainedIndexConstantOrVectorAddress16;
                    Actor1964Keep(argumentWord4);
                    intermediateWord3 = Actor1964Field(privateAddress19, int*, 48);
                    __asm__ volatile("" ::: "$17", "memory");
                    retainedOwnerPositionAddress17 = ownerAddress18 + 12;
                    intermediateWord3 -= 8;
                    Actor1964Field(privateAddress19, int*, 48) = intermediateWord3;
                    resultWord2 = Actor1964Field(ownerAddress18, int*, 20);
                    argumentWord5 = retainedOwnerPositionAddress17;
                    resultWord2 += intermediateWord3;
                    Actor1964Field(ownerAddress18, int*, 20) = resultWord2;
                    Actor1964CopyVector(argumentWord4, argumentWord5);
                    originalFrame.sp58 += 0x200;
                    resultWord2 =
                        Actor1964_func_8001A358(retainedIndexConstantOrVectorAddress16, 0x200);
                    __asm__ volatile("" ::"i"(9), "i"(4) : "memory");
                    if (resultWord2 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    temporaryWord33 = Actor1964Field(privateAddress19, void**, 0x2C);
                    resultWord2 = Actor1964ApproximatePlanarDistance(
                        retainedOwnerPositionAddress17,
                        Actor1964Field(temporaryWord33, int*, 0xC) +
                            (Actor1964Field(temporaryWord33, short*, 2) * 0x10));
                    __asm__ volatile("" ::"i"(9), "i"(4) : "memory");
                    if (resultWord2 < 0x900) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 5U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 5;
                        goto callOriginalAnimationAndReturn;
                    }
                    intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 60);
                    resultWord2 = 3;
                    if (intermediateWord3 == resultWord2) {
                        resultWord2 = Actor1964_D_8006C770;
                        __asm__("" : "=r"(resultWord2) : "0"(resultWord2), "i"(9), "i"(4));
                        if (resultWord2) {
                            argumentWord4 = ownerAddress18;
                            Actor1964Keep(argumentWord4);
                            argumentWord5 = 4;
                            goto callOriginalAnimationAndReturn;
                        }
                    }
                    break;
                case 5:
                    if (Actor1964_func_80055E84(ownerAddress18) < 0xC) {
                        Actor1964_func_80035A80(ownerAddress18,
                                                Actor1964Field(privateAddress19, void**, 0x2C),
                                                0x200, 0xC0, 0, 8, 0x18, 0x10000);
                        __asm__ volatile("" ::"i"(9), "i"(5) : "memory");
                    }
                    temporaryWord67 = Actor1964Field(privateAddress19, int*, 0x30) - 8;
                    Actor1964Field(privateAddress19, int*, 0x30) = temporaryWord67;
                    Actor1964Field(ownerAddress18, int*, 0x14) =
                        (int)(Actor1964Field(ownerAddress18, int*, 0x14) + temporaryWord67);
                    Actor1964CopyVector(&originalFrame.sp70, ownerAddress18 + 0xC);
                    originalFrame.sp78 += 0x200;
                    temporaryWord34 = Actor1964_func_8001A358(&originalFrame.sp70, 0x200);
                    __asm__ volatile("" ::"i"(9), "i"(5) : "memory");
                    originalFrame.sp78 = temporaryWord34;
                    if (temporaryWord34 != 0) {
                        Actor1964Field(ownerAddress18, int*, 0x14) = temporaryWord34;
                        Actor1964Field(privateAddress19, int*, 0x30) = 0;
                    }
                    if (Actor1964_D_8006C770 != 0) {
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 2U;
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                        argumentWord5 = 2;
                        goto callOriginalAnimationAndReturn;
                    }
                    break;
            }
            break;
        case 10:
            intermediateWord3 = Actor1964Field(ownerAddress18, unsigned char*, 72);
            if (intermediateWord3 != 0) {
            testOriginalSharedSubstate1:
                if (intermediateWord3 == 1)
                    goto testOriginalModeOneGlobal;
                return;
            }
            retainedIndexConstantOrVectorAddress16 = &originalFrame.sp50;
            if (Actor1964Field((int)&Actor1964_D_80070328, int*, 0xB8) == 0) {
                Actor1964CopyVector(retainedIndexConstantOrVectorAddress16,
                                    ((int)&Actor1964_D_80070328 + 0xB8) - 0xB8);
                originalFrame.sp58 -= Actor1964Field((int)&Actor1964_D_80070328, int*, 0x44);
                if (Actor1964_func_80036220(retainedIndexConstantOrVectorAddress16,
                                            privateAddress19 + 0x58, 0, 0x100) != 0) {
                    resultWord2 = Actor1964_func_80037BBC(ownerAddress18, 0);
                    __asm__ volatile("" ::"i"(10), "i"(10) : "memory");
                    if (resultWord2 != 0) {
                        argumentWord4 = ownerAddress18;
                        Actor1964Keep(argumentWord4);
                    callOriginalShared512E4AndSetSubstate1:
                        MATCHING_OBSERVE_VOLATILE(argumentWord4);
                        argumentWord5 = 0;
                        argumentWord6 = 1;
                        Actor1964_func_800512E4(argumentWord4, argumentWord5, argumentWord6);
                        Actor1964Field(ownerAddress18, unsigned char*, 0x48) = 1U;
                        return;
                    }
                    resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                    resultWord2 *= 2;
                    intermediateWord3 =
                        Actor1964Field((int)&Actor1964_D_80065920 + resultWord2, short*, 0);
                    __asm__ volatile("" ::: "$4", "memory");
                    argumentWord4 = retainedIndexConstantOrVectorAddress16;
                    Actor1964Keep(argumentWord4);
                    resultWord2 = (intermediateWord3 * 13) >> 5;
                    originalFrame.sp50 = resultWord2;
                    resultWord2 = Actor1964Field(ownerAddress18, unsigned char*, 70);
                    argumentWord5 = retainedIndexConstantOrVectorAddress16;
                    resultWord2 *= 2;
                    intermediateWord3 =
                        Actor1964Field((int)&Actor1964_D_800658A0 + resultWord2, short*, 0);
                    __asm__ volatile("" ::: "$6", "memory");
                    argumentWord6 = ownerAddress18 + 12;
                    MATCHING_KEEP_CLOBBER(argumentWord6, "memory");
                    originalFrame.sp58 = 0;
                    __asm__ volatile("" ::"m"(originalFrame.sp58));
                    resultWord2 = (intermediateWord3 * 13) >> 5;
                    originalFrame.sp54 = resultWord2;
                addOriginalLocalVectorAndCallHeader:
                    Actor1964AddVector(argumentWord4, argumentWord5, argumentWord6);
                    Actor1964_unk_ovlheader_80074330(
                        retainedIndexConstantOrVectorAddress16,
                        Actor1964Field(ownerAddress18, unsigned char*, 0x46) + 0x80, 0);
                    Actor1964Field(privateAddress19, signed char*, 5) = 1;
                    return;
                }
                if (Actor1964_func_80036220(retainedIndexConstantOrVectorAddress16,
                                            privateAddress19 + 0x70, 0, 0x100) != 0) {
                    argumentWord4 = ownerAddress18;
                    Actor1964Keep(argumentWord4);
                    Actor1964_D_80071583 = 1;
                    argumentWord5 = 2;
                    goto selectOriginalPrivate3CPath;
                }
            }
            break;
    }
    return;
testOriginalModeOneGlobal:
    resultWord2 = Actor1964_D_8006E344;
    if (resultWord2 == intermediateWord3)
        return;
    argumentWord4 = ownerAddress18;
    argumentWord5 = 2;
selectOriginalPrivate3CPath:
    intermediateWord3 = Actor1964Field(privateAddress19, void**, 60);
    resultWord2 = 2;
    Actor1964Field(privateAddress19, void**, 44) = intermediateWord3;
    Actor1964Field(intermediateWord3, short*, 2) = resultWord2;
    intermediateWord3 = Actor1964Field(privateAddress19, void**, 44);
    resultWord2 = 1;
    Actor1964Field(intermediateWord3, short*, 10) = resultWord2;
    resultWord2 = 7;
storeOriginalOuterState49:
    Actor1964Field(argumentWord4, unsigned char*, 73) = resultWord2;
    resultWord2 = 2;
    goto storeOriginalSubstate48;
produceOriginalSubstateFour:
    resultWord2 = 4;
storeOriginalSubstate48:
    Actor1964Field(argumentWord4, unsigned char*, 72) = resultWord2;
    goto callOriginalAnimationAndReturn;
clearOriginalSubstateAfterReversePath:
    Actor1964Field(argumentWord4, unsigned char*, 72) = 0;
callOriginalAnimationAndReturn:
    Actor1964RequestMobyAnimation(argumentWord4, argumentWord5);
    return;
}
#undef Actor1964Field
#undef Actor1964Keep


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C7C0.
 * AI generated; not human reviewed. 844 native words,9 actual selectors
 * and one zero pad must match:854 owned words. Frame80 (128 bytes) saves
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
 * widths,literals,callbacks and invocation order. Completion byte is80071571.
 * Level10 uses helper A3=256 and no blocked-state modal writes.
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
/* Original assembly SHA256 aa3c20e37750f54ed6eb3ccdf1e4c6974ab1836470321acfb4bd09bf9bd05575 */
#define Level10_7C7C0Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level10_7C7C0MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level10_7C7C0CaptureHigh(dst)                                       \
    do {                                                                    \
        int wholeCapturedHigh;                                              \
        __asm__("" : "=h"(wholeCapturedHigh) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedHigh;                                          \
        Level10_7C7C0Keep(dst);                                             \
    } while (0)
#define Level10_7C7C0CaptureLow(dst)                                       \
    do {                                                                   \
        int wholeCapturedLow;                                              \
        __asm__("" : "=l"(wholeCapturedLow) : "x"(completeSignedProduct)); \
        (dst) = wholeCapturedLow;                                          \
        Level10_7C7C0Keep(dst);                                            \
    } while (0)
#define Level10_7C7C0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Level10_7C7C0Call136F0View1(void*, int, int) __asm__("func_800136F0");
int Level10_7C7C0CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level10_7C7C0Call36220View1(void*, void*, int, int) __asm__("func_80036220");
void Level10_7C7C0Call37014View1(void*) __asm__("func_80037014");
int Level10_7C7C0Call37BBCView1(void*, int) __asm__("func_80037BBC");
int Level10_7C7C0PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
void Level10_7C7C0Call492DCView1(void*) __asm__("func_800492DC");
int Level10_7C7C0PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
void Level10_7C7C0TransformVectorByBasisView1(void*, int, int) __asm__("func_8004ED6C");
void Level10_7C7C0ClearVectorView1(void*) __asm__("func_8004F168");
void Level10_7C7C0CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level10_7C7C0AddVectorView1(void*, void*, void*) __asm__("func_8004F194");
void Level10_7C7C0SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level10_7C7C0AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
void* Level10_7C7C0Call50B00View1(int, int, int, int, int) __asm__("func_80050B00");
void Level10_7C7C0Call50B88View1(void*) __asm__("func_80050B88");
void Level10_7C7C0Call512E4View1(void*, int, int) __asm__("func_800512E4");
void Level10_7C7C0DeleteMobyView1(void*) __asm__("func_80055B18");
void Level10_7C7C0RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
extern unsigned char Level10_7C7C0Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level10_7C7C0Data65920View1[] __asm__("D_80065920");
extern int Level10_7C7C0Data6C574View1 __asm__("D_8006C574");
extern int Level10_7C7C0Data6C578View1 __asm__("D_8006C578");
extern int Level10_7C7C0Data6C74CView1 __asm__("D_8006C74C");
extern int Level10_7C7C0Data6C7C0View1 __asm__("D_8006C7C0");
extern int Level10_7C7C0Data6E020View1 __asm__("D_8006E020");
extern int Level10_7C7C0Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level10_7C7C0Data6E040View1 __asm__("D_8006E040");
extern int Level10_7C7C0Data6E160View1 __asm__("D_8006E160");
extern int Level10_7C7C0Data6E174View1 __asm__("D_8006E174");
extern int Level10_7C7C0Data6E178View1 __asm__("D_8006E178");
extern int Level10_7C7C0Data6E17CView1 __asm__("D_8006E17C");
extern int Level10_7C7C0Data6E344View1 __asm__("D_8006E344");
extern int Level10_7C7C0Data70328View1 __asm__("D_80070328");
extern unsigned char Level10_7C7C0Data71571View1 __asm__("D_80071571");
extern int (*Level10_7C7C0DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int (*Level10_7C7C0Data74330View1)() __asm__("unk_ovlheader_80074330");
extern int (*Level10_7C7C0Data743ECView1)() __asm__("unk_ovlheader_800743EC");
void func_level_10_8007C7C0(unsigned char* ownerParameter) {
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
    Level10_7C7C0Keep(ownerThenGeometryOffset20);
    temp_v1 = Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    privateRecord19 = Level10_7C7C0Field(ownerThenGeometryOffset20, int*, 0);
    switch (temp_v1) {
        case 0:
            resultOrField2 = Level10_7C7C0Data71571View1;
            naturalCountRecordOrOffset16 = 0;
            if (resultOrField2) {
                Level10_7C7C0DeleteMobyView1(ownerThenGeometryOffset20);
                return;
            }
            resultOrField2 = 255;
            Level10_7C7C0Keep(resultOrField2);
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x41) = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x4C) = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x4D) = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x4A) = resultOrField2;
            do {
                Level10_7C7C0Keep(naturalCountRecordOrOffset16);
                angleCreatedOrSourceOffset17 = naturalCountRecordOrOffset16 * 2;
                Level10_7C7C0Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 + naturalCountRecordOrOffset16;
                argumentOrField4 *= 4;
                argumentOrField4 += 0x74;
                argumentOrField4 = privateRecord19 + argumentOrField4;
                argumentOrField5 = ownerThenGeometryOffset20 + 12;
                Level10_7C7C0CopyVectorView1(argumentOrField4, argumentOrField5);
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
                Level10_7C7C0Keep(argumentOrField5);
                resultOrField2 = naturalCountRecordOrOffset16 + 1;
                __asm__(""
                        : "=r"(resultOrField2)
                        : "0"(resultOrField2), "r"(argumentOrField4), "r"(fieldHighOrAddress3),
                          "r"(argumentOrField5));
                naturalCountRecordOrOffset16 = resultOrField2;
                Level10_7C7C0Keep(naturalCountRecordOrOffset16);
                argumentOrField4 = privateRecord19 + argumentOrField4;
                fieldHighOrAddress3 = privateRecord19 + fieldHighOrAddress3;
                resultOrField2 = angleCreatedOrSourceOffset17 + 2;
                Level10_7C7C0Field(argumentOrField4, unsigned char*, 0x4F4) = argumentOrField6;
                Level10_7C7C0Field(argumentOrField4, unsigned char*, 0x4F5) = argumentOrField6;
                Level10_7C7C0Field(argumentOrField4, unsigned char*, 0x4F6) = argumentOrField6;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x575) = resultOrField2;
                resultOrField2 = angleCreatedOrSourceOffset17 + 1;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x576) = resultOrField2;
                resultOrField2 = angleCreatedOrSourceOffset17 + 3;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x577) = resultOrField2;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x574) =
                    angleCreatedOrSourceOffset17;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x578) = argumentOrField5;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x579) =
                    naturalCountRecordOrOffset16;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x57A) = argumentOrField5;
                Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 0x57B) =
                    naturalCountRecordOrOffset16;
            } while (naturalCountRecordOrOffset16 < 32);
            resultOrField2 = naturalCountRecordOrOffset16 * 8;
            resultOrField2 += privateRecord19;
            fieldHighOrAddress3 = -1;
            Level10_7C7C0Field(resultOrField2, int*, 0x56C) = fieldHighOrAddress3;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, unsigned short*, 0x6E);
            resultOrField2 &= 0xFF9F;
            resultOrField2 |= 0x40;
            Level10_7C7C0Field(privateRecord19, short*, 0x6E) = resultOrField2;
            resultOrField2 = 1;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = resultOrField2;
            goto renderOriginalCommonPhase;
        default:
            goto renderOriginalCommonPhase;
        case 1:
            Level10_7C7C0CopyVectorView1(&originalFrame.sp18, &Level10_7C7C0Data70328View1);
            originalFrame.sp20 -= Level10_7C7C0Field(&Level10_7C7C0Data70328View1, int*, 0x44);
            if (Level10_7C7C0Call36220View1(&originalFrame.sp18, privateRecord19 + 0x3C, 0, 256) !=
                0) {
                if (Level10_7C7C0Field(&Level10_7C7C0Data70328View1, int*, 0xB8) == 0) {
                    resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 36);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    argumentOrField6 = Level10_7C7C0Field(resultOrField2, short*, 0);
                    resultOrField2 = Level10_7C7C0Field(resultOrField2, int*, 12);
                    argumentOrField6 *= 16;
                    argumentOrField5 = argumentOrField6 - 16;
                    argumentOrField5 = resultOrField2 + argumentOrField5;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level10_7C7C0SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
                    argumentOrField4 = originalFrame.sp18;
                    argumentOrField5 = originalFrame.sp1C;
                    argumentOrField6 = 0;
                    resultOrField2 = Level10_7C7C0PlanarHeadingLookupView1(
                        argumentOrField4, argumentOrField5, argumentOrField6);
                    naturalCountRecordOrOffset16 = resultOrField2;
                    Level10_7C7C0Keep(naturalCountRecordOrOffset16);
                    argumentOrField4 = naturalCountRecordOrOffset16 * 2;
                    fieldHighOrAddress3 =
                        Level10_7C7C0Field(&Level10_7C7C0Data65920View1, short*, argumentOrField4);
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp18 = resultOrField2;
                    fieldHighOrAddress3 =
                        Level10_7C7C0Field(&Level10_7C7C0Data658A0View1, short*, argumentOrField4);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    originalFrame.sp20 = 0;
                    resultOrField2 = fieldHighOrAddress3 * 13;
                    resultOrField2 >>= 5;
                    originalFrame.sp1C = resultOrField2;
                    resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 36);
                    argumentOrField5 = argumentOrField4;
                    argumentOrField6 = Level10_7C7C0Field(resultOrField2, short*, 0);
                    resultOrField2 = Level10_7C7C0Field(resultOrField2, int*, 12);
                    argumentOrField6 *= 16;
                    argumentOrField6 -= 32;
                    argumentOrField6 = resultOrField2 + argumentOrField6;
                    Level10_7C7C0AddVectorView1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    argumentOrField4 = (int)&originalFrame.sp18;
                    __asm__(""
                            : "=r"(argumentOrField4)
                            : "0"(argumentOrField4), "m"(originalFrame.sp18));
                    argumentOrField5 = naturalCountRecordOrOffset16 + 128;
                    argumentOrField6 = 0;
                    Level10_7C7C0Data74330View1(argumentOrField4, argumentOrField5,
                                                argumentOrField6);
                    Level10_7C7C0Field(privateRecord19, signed char*, 5) = 1;
                    Level10_7C7C0Field(Level10_7C7C0Field(privateRecord19, int*, 0x24), short*, 2) =
                        1;
                    Level10_7C7C0CopyVectorView1(
                        &Level10_7C7C0Data6E17CView1,
                        Level10_7C7C0Field(Level10_7C7C0Field(privateRecord19, int*, 0x28), int*,
                                           0xC) +
                            0x10);
                    temp_a1_3 = Level10_7C7C0Field(Level10_7C7C0Field(privateRecord19, int*, 0x28),
                                                   int*, 0xC);
                    Level10_7C7C0Call136F0View1((int)&Level10_7C7C0Data6E17CView1 - 0x14, temp_a1_3,
                                                temp_a1_3 + 0x10);
                    Level10_7C7C0Data6E160View1 = 0x11;
                    Level10_7C7C0Data6C74CView1 = 1;
                    Level10_7C7C0Data6E174View1 = 0;
                    Level10_7C7C0Data6E178View1 = 0;
                    Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 2U;
                }
            }
            goto renderOriginalCommonPhase;
        case 2:
            if (Level10_7C7C0Call36220View1(&Level10_7C7C0Data70328View1, privateRecord19 + 0x3C, 0,
                                            0) != 0) {
                naturalCountRecordOrOffset16 = (int)&originalFrame.sp28;
                argumentOrField4 = naturalCountRecordOrOffset16;
                fieldHighOrAddress3 = Level10_7C7C0Field(privateRecord19, int*, 36);
                Level10_7C7C0Data6C74CView1 = 1;
                argumentOrField6 = Level10_7C7C0Field(fieldHighOrAddress3, short*, 0);
                resultOrField2 = Level10_7C7C0Field(fieldHighOrAddress3, int*, 12);
                argumentOrField6 *= 16;
                argumentOrField5 = argumentOrField6 - 16;
                argumentOrField5 = resultOrField2 + argumentOrField5;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level10_7C7C0SubtractVectorView1(argumentOrField4, argumentOrField5,
                                                 argumentOrField6);
                argumentOrField4 = originalFrame.sp28;
                argumentOrField5 = originalFrame.sp2C;
                argumentOrField6 = 0;
                resultOrField2 = Level10_7C7C0PlanarHeadingLookupView1(
                    argumentOrField4, argumentOrField5, argumentOrField6);
                angleCreatedOrSourceOffset17 = resultOrField2;
                Level10_7C7C0Keep(angleCreatedOrSourceOffset17);
                argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
                fieldHighOrAddress3 =
                    Level10_7C7C0Field(&Level10_7C7C0Data65920View1, short*, argumentOrField4);
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp28 = resultOrField2;
                fieldHighOrAddress3 =
                    Level10_7C7C0Field(&Level10_7C7C0Data658A0View1, short*, argumentOrField4);
                argumentOrField5 = naturalCountRecordOrOffset16;
                originalFrame.sp30 = 0;
                resultOrField2 = fieldHighOrAddress3 * 13;
                resultOrField2 >>= 5;
                originalFrame.sp2C = resultOrField2;
                resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 36);
                __asm__(""
                        : "=r"(naturalCountRecordOrOffset16)
                        : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
                argumentOrField4 = naturalCountRecordOrOffset16;
                argumentOrField6 = Level10_7C7C0Field(resultOrField2, short*, 0);
                resultOrField2 = Level10_7C7C0Field(resultOrField2, int*, 12);
                argumentOrField6 *= 16;
                argumentOrField6 -= 32;
                argumentOrField6 = resultOrField2 + argumentOrField6;
                Level10_7C7C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
                argumentOrField4 = naturalCountRecordOrOffset16;
                __asm__(""
                        : "=r"(argumentOrField4)
                        : "0"(argumentOrField4), "m"(originalFrame.sp28));
                argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
                argumentOrField6 = 0;
                Level10_7C7C0Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
                Level10_7C7C0Field(privateRecord19, signed char*, 5) = 1;
                Level10_7C7C0Call492DCView1(ownerThenGeometryOffset20 + 0xC);
                if (Level10_7C7C0AbsoluteByteAngleDeltaView1(
                        (int)(Level10_7C7C0Data6E040View1 << 0x10) >> 0x14,
                        Level10_7C7C0PlanarHeadingLookupView1(
                            Level10_7C7C0Field(ownerThenGeometryOffset20, int*, 0xC) -
                                Level10_7C7C0Data6E020View1,
                            Level10_7C7C0Field(ownerThenGeometryOffset20, int*, 0x10) -
                                Level10_7C7C0Data6E024View1,
                            0)) < 0x18) {
                    Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 3U;
                }
            } else {
                goto restoreOriginalStateOne;
            }
            goto renderOriginalCommonPhase;
        case 4:
            Level10_7C7C0PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x41) = 1;
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x4C) = 0x10;
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x4D) = 1;
            Level10_7C7C0Call37014View1(ownerThenGeometryOffset20);
            argumentOrField6 = 0;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$18");
            recordOrHistoryCount18 = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x44) = 0U;
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x45) = 0;
            temp_v1_6 = Level10_7C7C0Field(privateRecord19, int*, 0x24);
            temp_v0_11 = (Level10_7C7C0Field(temp_v1_6, short*, 2) * 0x10) +
                         Level10_7C7C0Field(temp_v1_6, int*, 0xC);
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x46) =
                Level10_7C7C0PlanarHeadingLookupView1(
                    Level10_7C7C0Field(temp_v0_11, int*, 0) -
                        Level10_7C7C0Field(ownerThenGeometryOffset20, int*, 0xC),
                    Level10_7C7C0Field(temp_v0_11, int*, 4) -
                        Level10_7C7C0Field(ownerThenGeometryOffset20, int*, 0x10),
                    argumentOrField6);
        emitOriginalFirstSix:
            resultOrField2 = Level10_7C7C0Data6C578View1;
            fieldHighOrAddress3 = Level10_7C7C0Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone4;
            angleCreatedOrSourceOffset17 =
                Level10_7C7C0DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalFirstSix;
        originalSixDone4:
            recordOrHistoryCount18 = 0;
        emitOriginalFirstTwelve:
            resultOrField2 = Level10_7C7C0Data6C578View1;
            fieldHighOrAddress3 = Level10_7C7C0Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone4;
            angleCreatedOrSourceOffset17 =
                Level10_7C7C0DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level10_7C7C0Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext4;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x58);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level10_7C7C0Field(resultOrField2, unsigned char*, 0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x58);
            naturalCountRecordOrOffset16 =
                Level10_7C7C0Field(angleCreatedOrSourceOffset17, int*, 0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 1);
            argumentOrField5 = 4;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level10_7C7C0RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level10_7C7C0Field(naturalCountRecordOrOffset16, int*, 12) = resultOrField2;
            Level10_7C7C0Field(naturalCountRecordOrOffset16, int*, 16) = 0;
            Level10_7C7C0Field(naturalCountRecordOrOffset16, int*, 20) = 0;
            Level10_7C7C0TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level10_7C7C0Keep(resultOrField2);
            Level10_7C7C0MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level10_7C7C0Field(angleCreatedOrSourceOffset17, int*, 20);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, int*, 20) = resultOrField2;
            Level10_7C7C0CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext4:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalFirstTwelve;
        originalTwelveDone4:
            Level10_7C7C0Field(privateRecord19, int*, 0x2C) = 0x1E;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 5U;
        case 5:
            if (Level10_7C7C0CountTimerDownView1(privateRecord19 + 0x2C, 4) != 0) {
                Level10_7C7C0Data6E160View1 = 0;
                Level10_7C7C0Field(privateRecord19, signed char*, 5) = 2;
                Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 6U;
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 44);
            resultOrField2 <<= 8;
            Level10_7C7C0Keep(resultOrField2);
            Level10_7C7C0MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level10_7C7C0CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level10_7C7C0Data6C7C0View1 = fieldHighOrAddress3;
        case 3:
            if (Level10_7C7C0Call36220View1(&Level10_7C7C0Data70328View1, privateRecord19 + 0x3C, 0,
                                            0) == 0) {
                resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 36);
                argumentOrField4 = ownerThenGeometryOffset20 + 12;
                Level10_7C7C0Field(resultOrField2, short*, 2) = 0;
                resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 36);
                angleCreatedOrSourceOffset17 = 0;
                argumentOrField5 = Level10_7C7C0Field(resultOrField2, int*, 12);
                naturalCountRecordOrOffset16 = 116;
                Level10_7C7C0CopyVectorView1(argumentOrField4, argumentOrField5);
                Level10_7C7C0ClearVectorView1(privateRecord19 + 0x30);
                Level10_7C7C0Field(privateRecord19, int*, 0x2C) = 0;
                do {
                    Level10_7C7C0CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                                 ownerThenGeometryOffset20 + 0xC);
                    angleCreatedOrSourceOffset17 += 1;
                    naturalCountRecordOrOffset16 += 0xC;
                } while (angleCreatedOrSourceOffset17 < 0x20);
            restoreOriginalStateOne:
                resultOrField2 = 1;
                Level10_7C7C0Data6E160View1 = 0;
                Level10_7C7C0Data6C74CView1 = 0;
                Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) =
                    resultOrField2;
                goto renderOriginalCommonPhase;
            }
            naturalCountRecordOrOffset16 = (int)&originalFrame.sp38;
            argumentOrField4 = naturalCountRecordOrOffset16;
            fieldHighOrAddress3 = Level10_7C7C0Field(privateRecord19, int*, 36);
            Level10_7C7C0Data6C74CView1 = 1;
            argumentOrField6 = Level10_7C7C0Field(fieldHighOrAddress3, short*, 0);
            resultOrField2 = Level10_7C7C0Field(fieldHighOrAddress3, int*, 12);
            argumentOrField6 *= 16;
            argumentOrField5 = argumentOrField6 - 16;
            argumentOrField5 = resultOrField2 + argumentOrField5;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level10_7C7C0SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = originalFrame.sp38;
            argumentOrField5 = originalFrame.sp3C;
            argumentOrField6 = 0;
            resultOrField2 = Level10_7C7C0PlanarHeadingLookupView1(
                argumentOrField4, argumentOrField5, argumentOrField6);
            angleCreatedOrSourceOffset17 = resultOrField2;
            Level10_7C7C0Keep(angleCreatedOrSourceOffset17);
            argumentOrField4 = angleCreatedOrSourceOffset17 * 2;
            fieldHighOrAddress3 =
                Level10_7C7C0Field(&Level10_7C7C0Data65920View1, short*, argumentOrField4);
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp38 = resultOrField2;
            fieldHighOrAddress3 =
                Level10_7C7C0Field(&Level10_7C7C0Data658A0View1, short*, argumentOrField4);
            argumentOrField5 = naturalCountRecordOrOffset16;
            originalFrame.sp40 = 0;
            resultOrField2 = fieldHighOrAddress3 * 13;
            resultOrField2 >>= 5;
            originalFrame.sp3C = resultOrField2;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 36);
            __asm__(""
                    : "=r"(naturalCountRecordOrOffset16)
                    : "0"(naturalCountRecordOrOffset16), "r"(resultOrField2));
            argumentOrField4 = naturalCountRecordOrOffset16;
            argumentOrField6 = Level10_7C7C0Field(resultOrField2, short*, 0);
            resultOrField2 = Level10_7C7C0Field(resultOrField2, int*, 12);
            argumentOrField6 *= 16;
            argumentOrField6 -= 32;
            argumentOrField6 = resultOrField2 + argumentOrField6;
            Level10_7C7C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
            argumentOrField4 = naturalCountRecordOrOffset16;
            __asm__("" : "=r"(argumentOrField4) : "0"(argumentOrField4), "m"(originalFrame.sp38));
            argumentOrField5 = angleCreatedOrSourceOffset17 + 128;
            argumentOrField6 = 0;
            Level10_7C7C0Data74330View1(argumentOrField4, argumentOrField5, argumentOrField6);
            Level10_7C7C0Call492DCView1(ownerThenGeometryOffset20 + 0xC);
            if (Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) == 3) {
                temp_v0_17 = Level10_7C7C0Field(privateRecord19, int*, 0x24);
                if (Level10_7C7C0Field(temp_v0_17, short*, 2) ==
                    (Level10_7C7C0Field(temp_v0_17, short*, 0) - 1)) {
                    Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 4U;
                } else {
                    Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x44) =
                        (unsigned char)(Level10_7C7C0Field(ownerThenGeometryOffset20,
                                                           unsigned char*, 0x44) +
                                        4);
                    naturalCountRecordOrOffset16 = Level10_7C7C0Field(
                        Level10_7C7C0Field(privateRecord19, int*, 0x24), short*, 2);
                    Level10_7C7C0Keep(naturalCountRecordOrOffset16);
                    Level10_7C7C0Data743ECView1(
                        ownerThenGeometryOffset20, Level10_7C7C0Field(privateRecord19, int*, 0x24),
                        privateRecord19 + 0x30, privateRecord19 + 0x2C, 8, 0);
                    fieldHighOrAddress3 = Level10_7C7C0Field(privateRecord19, int*, 36);
                    Level10_7C7C0Keep(fieldHighOrAddress3);
                    if (Level10_7C7C0Field(fieldHighOrAddress3, short*, 2) !=
                        naturalCountRecordOrOffset16) {
                        resultOrField2 = Level10_7C7C0Field(fieldHighOrAddress3, int*, 12);
                        fieldHighOrAddress3 = naturalCountRecordOrOffset16 * 16;
                        Level10_7C7C0Keep(fieldHighOrAddress3);
                        fieldHighOrAddress3 += resultOrField2;
                        resultOrField2 = Level10_7C7C0Field(fieldHighOrAddress3, int*, 12);
                        if (resultOrField2) {
                            Level10_7C7C0PlayMobySoundEventView1(ownerThenGeometryOffset20, 1, 0);
                        }
                    }
                }
            }
            goto renderOriginalCommonPhase;
        case 6:
            temp_v1_10 = Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x48);
            switch (temp_v1_10) {
                case 0:
                    if (Level10_7C7C0Call37BBCView1(ownerThenGeometryOffset20, 0) != 0) {
                        Level10_7C7C0Data71571View1 = 1;
                        Level10_7C7C0Call512E4View1(ownerThenGeometryOffset20, 0, 1);
                        Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x48) = 1U;
                    }
                    break;
                case 1:
                    if (Level10_7C7C0Data6E344View1 != temp_v1_10) {
                        Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 7U;
                    }
                    break;
            }
            goto renderOriginalCommonPhase;
        case 7:
            Level10_7C7C0PlayMobySoundEventView1(ownerThenGeometryOffset20, 0, 0);
            recordOrHistoryCount18 = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x41) = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x4C) = 0;
            Level10_7C7C0Field(ownerThenGeometryOffset20, signed char*, 0x4D) = 0;
        emitOriginalSecondSix:
            resultOrField2 = Level10_7C7C0Data6C578View1;
            fieldHighOrAddress3 = Level10_7C7C0Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 426;
            if (resultOrField2 < 21)
                goto originalSixDone7;
            angleCreatedOrSourceOffset17 =
                Level10_7C7C0DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            if (angleCreatedOrSourceOffset17)
                Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) =
                    recordOrHistoryCount18;
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 6)
                goto emitOriginalSecondSix;
        originalSixDone7:
            recordOrHistoryCount18 = 0;
        emitOriginalSecondTwelve:
            resultOrField2 = Level10_7C7C0Data6C578View1;
            fieldHighOrAddress3 = Level10_7C7C0Data6C574View1;
            resultOrField2 -= fieldHighOrAddress3;
            argumentOrField4 = 427;
            if (resultOrField2 < 21)
                goto originalTwelveDone7;
            angleCreatedOrSourceOffset17 =
                Level10_7C7C0DataSpawnMobyView1(argumentOrField4, ownerThenGeometryOffset20);
            Level10_7C7C0Keep(angleCreatedOrSourceOffset17);
            fieldHighOrAddress3 = recordOrHistoryCount18 * 2;
            if (!angleCreatedOrSourceOffset17)
                goto originalTwelveNext7;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x58);
            resultOrField2 += fieldHighOrAddress3;
            resultOrField2 = Level10_7C7C0Field(resultOrField2, unsigned char*, 0);
            argumentOrField4 = angleCreatedOrSourceOffset17;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x46) = resultOrField2;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x58);
            naturalCountRecordOrOffset16 =
                Level10_7C7C0Field(angleCreatedOrSourceOffset17, int*, 0);
            fieldHighOrAddress3 = fieldHighOrAddress3 + resultOrField2;
            resultOrField2 = Level10_7C7C0Field(fieldHighOrAddress3, unsigned char*, 1);
            argumentOrField5 = 4;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x45) = resultOrField2;
            Level10_7C7C0RefreshMobySpatialGridAndBasisView1(argumentOrField4, argumentOrField5);
            argumentOrField4 = angleCreatedOrSourceOffset17 + 32;
            argumentOrField5 = naturalCountRecordOrOffset16 + 12;
            argumentOrField6 = argumentOrField5;
            resultOrField2 = 128;
            Level10_7C7C0Field(naturalCountRecordOrOffset16, int*, 12) = resultOrField2;
            Level10_7C7C0Field(naturalCountRecordOrOffset16, int*, 16) = 0;
            Level10_7C7C0Field(naturalCountRecordOrOffset16, int*, 20) = 0;
            Level10_7C7C0TransformVectorByBasisView1(argumentOrField4, argumentOrField5,
                                                     argumentOrField6);
            resultOrField2 = 0x2AAAAAAB;
            Level10_7C7C0Keep(resultOrField2);
            Level10_7C7C0MultiplyComplete(recordOrHistoryCount18, resultOrField2);
            resultOrField2 = Level10_7C7C0Field(angleCreatedOrSourceOffset17, int*, 20);
            fieldHighOrAddress3 = recordOrHistoryCount18 >> 31;
            resultOrField2 += 1024;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, int*, 20) = resultOrField2;
            Level10_7C7C0CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 - fieldHighOrAddress3;
            resultOrField2 = fieldHighOrAddress3 * 6;
            resultOrField2 = recordOrHistoryCount18 - resultOrField2;
            Level10_7C7C0Field(angleCreatedOrSourceOffset17, unsigned char*, 0x49) = resultOrField2;
        originalTwelveNext7:
            recordOrHistoryCount18++;
            if (recordOrHistoryCount18 < 12)
                goto emitOriginalSecondTwelve;
        originalTwelveDone7:
            temp_a0_6 = Level10_7C7C0Field(privateRecord19, int*, 0x64);
            if (temp_a0_6 != 0) {
                Level10_7C7C0Call50B88View1(temp_a0_6);
            }
            temp_a0_7 = Level10_7C7C0Field(privateRecord19, int*, 0x70);
            if (temp_a0_7 != 0) {
                Level10_7C7C0Call50B88View1(temp_a0_7);
            }
            Level10_7C7C0Field(privateRecord19, int*, 0x2C) = 0x1E;
            Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49) = 8U;
        case 8:
            if (Level10_7C7C0CountTimerDownView1(privateRecord19 + 0x2C, 4) != 0) {
                Level10_7C7C0DeleteMobyView1(ownerThenGeometryOffset20);
            }
            fieldHighOrAddress3 = (int)0x88888889;
            resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 44);
            resultOrField2 <<= 8;
            Level10_7C7C0Keep(resultOrField2);
            Level10_7C7C0MultiplyComplete(resultOrField2, fieldHighOrAddress3);
            Level10_7C7C0CaptureHigh(capturedHighOrLow8);
            fieldHighOrAddress3 = capturedHighOrLow8 + resultOrField2;
            fieldHighOrAddress3 >>= 4;
            resultOrField2 >>= 31;
            fieldHighOrAddress3 -= resultOrField2;
            Level10_7C7C0Data6C7C0View1 = fieldHighOrAddress3;
            goto renderOriginalCommonPhase;
    }
renderOriginalCommonPhase:
    resultOrField2 = Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 -= 3;
    recordOrHistoryCount18 = 31;
    if ((unsigned int)resultOrField2 >= 4U)
        return;
    angleCreatedOrSourceOffset17 = 0x1DC;
    naturalCountRecordOrOffset16 = 0x1E8;
    do {
        Level10_7C7C0CopyVectorView1(privateRecord19 + naturalCountRecordOrOffset16,
                                     privateRecord19 + angleCreatedOrSourceOffset17);
        angleCreatedOrSourceOffset17 -= 12;
        recordOrHistoryCount18--;
        naturalCountRecordOrOffset16 -= 12;
    } while (recordOrHistoryCount18 > 0);
    Level10_7C7C0CopyVectorView1(privateRecord19 + 0x74, ownerThenGeometryOffset20 + 12);
    fieldHighOrAddress3 = Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x49);
    resultOrField2 = 3;
    if (fieldHighOrAddress3 != resultOrField2) {
        resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x7C);
        resultOrField2 -= 1024;
        Level10_7C7C0Field(privateRecord19, int*, 0x7C) = resultOrField2;
    }
    resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x70);
    argumentOrField4 = privateRecord19 + 0x1F4;
    if (!resultOrField2) {
        resultOrField2 =
            Level10_7C7C0Call50B00View1(argumentOrField4, privateRecord19 + 0x4F4,
                                        privateRecord19 + 0x574, privateRecord19 + 0x68, 1);
        Level10_7C7C0Field(privateRecord19, int*, 0x70) = resultOrField2;
        __asm__("" : "=r"(privateRecord19) : "0"(privateRecord19), "r"(resultOrField2));
    }
    resultOrField2 = Level10_7C7C0Field(privateRecord19, int*, 0x64);
    emittedVertexCount21 = 0;
    if (!resultOrField2) {
        Level10_7C7C0Keep(emittedVertexCount21);
        resultOrField2 =
            Level10_7C7C0Call50B00View1(privateRecord19 + 0x1F4, privateRecord19 + 0x4F4,
                                        privateRecord19 + 0x574, privateRecord19 + 0x5C, 1);
        Level10_7C7C0Field(privateRecord19, int*, 0x64) = resultOrField2;
        __asm__ volatile(""
                         : "=r"(emittedVertexCount21)
                         : "0"(emittedVertexCount21), "r"(resultOrField2));
        emittedVertexCount21 = 0;
    }
    recordOrHistoryCount18 = 0;
    retainedOriginalTableBase = (int)&Level10_7C7C0Data658A0View1;
    vectorAddress23 = (int)&originalFrame.sp48;
    resultOrField2 = Level10_7C7C0Field(ownerThenGeometryOffset20, unsigned char*, 0x44);
    ownerThenGeometryOffset20 = 0x1F4;
    resultOrField2 += 64;
    retainedAngle22 = resultOrField2 & 255;
    do {
        argumentOrField6 = 0;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "$16");
        naturalCountRecordOrOffset16 = recordOrHistoryCount18 * 2;
        Level10_7C7C0Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 += recordOrHistoryCount18;
        Level10_7C7C0Keep(naturalCountRecordOrOffset16);
        naturalCountRecordOrOffset16 *= 4;
        fieldHighOrAddress3 = privateRecord19 + naturalCountRecordOrOffset16;
        angleCreatedOrSourceOffset17 = recordOrHistoryCount18 + 1;
        resultOrField2 = angleCreatedOrSourceOffset17 * 12;
        resultOrField2 = privateRecord19 + resultOrField2;
        argumentOrField7 = Level10_7C7C0Field(fieldHighOrAddress3, int*, 0x74);
        argumentOrField4 = Level10_7C7C0Field(resultOrField2, int*, 0x74);
        fieldHighOrAddress3 = Level10_7C7C0Field(fieldHighOrAddress3, int*, 0x78);
        argumentOrField5 = Level10_7C7C0Field(resultOrField2, int*, 0x78);
        argumentOrField4 = argumentOrField7 - argumentOrField4;
        argumentOrField5 = fieldHighOrAddress3 - argumentOrField5;
        resultOrField2 = Level10_7C7C0PlanarHeadingLookupView1(argumentOrField4, argumentOrField5,
                                                               argumentOrField6);
        resultOrField2 += 64;
        resultOrField2 &= 255;
        resultOrField2 *= 2;
        capturedHighOrLow8 = (int)&Level10_7C7C0Data65920View1;
        Level10_7C7C0Keep(capturedHighOrLow8);
        fieldHighOrAddress3 = resultOrField2 + capturedHighOrLow8;
        MATCHING_KEEP_VOLATILE_CLOBBER(fieldHighOrAddress3, "$7");
        argumentOrField7 = retainedAngle22 * 2;
        argumentOrField5 = argumentOrField7 + capturedHighOrLow8;
        fieldHighOrAddress3 = Level10_7C7C0Field(fieldHighOrAddress3, short*, 0);
        argumentOrField4 = Level10_7C7C0Field(argumentOrField5, short*, 0);
        MATCHING_KEEP2(fieldHighOrAddress3, argumentOrField4);
        fieldHighOrAddress3 >>= 4;
        Level10_7C7C0MultiplyComplete(fieldHighOrAddress3, argumentOrField4);
        resultOrField2 += retainedOriginalTableBase;
        Level10_7C7C0CaptureLow(capturedHighOrLow8);
        fieldHighOrAddress3 = capturedHighOrLow8 >> 12;
        originalFrame.sp48 = fieldHighOrAddress3;
        resultOrField2 = Level10_7C7C0Field(resultOrField2, short*, 0);
        fieldHighOrAddress3 = Level10_7C7C0Field(argumentOrField5, short*, 0);
        MATCHING_KEEP2(resultOrField2, fieldHighOrAddress3);
        resultOrField2 >>= 4;
        Level10_7C7C0MultiplyComplete(resultOrField2, fieldHighOrAddress3);
        __asm__(""
                : "=r"(emittedVertexCount21)
                : "0"(emittedVertexCount21), "x"(completeSignedProduct));
        emittedVertexCount21++;
        Level10_7C7C0Keep(emittedVertexCount21);
        emittedVertexCount21++;
        recordOrHistoryCount18 = angleCreatedOrSourceOffset17;
        naturalCountRecordOrOffset16 += 0x74;
        currentHistoryPositionAddress = privateRecord19 + naturalCountRecordOrOffset16;
        Level10_7C7C0Keep(currentHistoryPositionAddress);
        argumentOrField6 = vectorAddress23;
        argumentOrField7 += retainedOriginalTableBase;
        MATCHING_KEEP_VOLATILE_CLOBBER(argumentOrField7, "$4");
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        ownerThenGeometryOffset20 += 12;
        Level10_7C7C0CaptureLow(capturedHighOrLow8);
        resultOrField2 = capturedHighOrLow8 >> 12;
        originalFrame.sp4C = resultOrField2;
        resultOrField2 = Level10_7C7C0Field(argumentOrField7, short*, 0);
        __asm__(""
                : "=r"(currentHistoryPositionAddress)
                : "0"(currentHistoryPositionAddress), "r"(resultOrField2));
        argumentOrField5 = currentHistoryPositionAddress;
        Level10_7C7C0Keep(resultOrField2);
        resultOrField2 >>= 4;
        originalFrame.sp50 = resultOrField2;
        Level10_7C7C0AddVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        argumentOrField4 = privateRecord19 + ownerThenGeometryOffset20;
        argumentOrField5 = currentHistoryPositionAddress;
        argumentOrField6 = vectorAddress23;
        Level10_7C7C0SubtractVectorView1(argumentOrField4, argumentOrField5, argumentOrField6);
        resultOrField2 = retainedAngle22 - 4;
        retainedAngle22 = resultOrField2 & 255;
        ownerThenGeometryOffset20 += 12;
    } while (recordOrHistoryCount18 < 32);
    resultOrField2 = emittedVertexCount21 * 12;
    resultOrField2 = privateRecord19 + resultOrField2;
    fieldHighOrAddress3 = -1;
    Level10_7C7C0Field(resultOrField2, int*, 0x1F4) = fieldHighOrAddress3;
    Level10_7C7C0Field(resultOrField2, int*, 0x1F8) = fieldHighOrAddress3;
    Level10_7C7C0Field(resultOrField2, int*, 0x1FC) = fieldHighOrAddress3;
    return;
}
#undef Level10_7C7C0Field


typedef struct {
    int timer;
    Colour* colours;
} DecodedColourFadeTag;
extern int D_8006C648;
void func_80055B18(Moby*);
void func_level_10_8007D4F0(Moby* moby) {
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
void func_level_10_8007D62C(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_10/moby/func_level_10_8007D7BC.s SHA256 03b5dd8a8ff30befa787a2145c8daffad114e67a832ff0ae0c151f88aa10e6fe. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level10_7D7BCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

unsigned int Level10_7D7BC_func_80034F40() __asm__("func_80034F40");
/* extern */
unsigned int Level10_7D7BCEmptyAnimationTransitionHook() __asm__("func_80035734");
/* extern */
int Level10_7D7BCTurnMobyTowardHeading() __asm__("func_8003585C");
/* extern */
int Level10_7D7BCCountTimerDown() __asm__("func_800359A4");
/* extern */
int Level10_7D7BC_func_80035DDC() __asm__("func_80035DDC");
/* extern */
int Level10_7D7BCSubAngle8() __asm__("func_8003613C");
/* extern */
unsigned int Level10_7D7BCRandBetween() __asm__("func_8003636C");
/* extern */
int Level10_7D7BCRandSignedBetween() __asm__("func_800363DC");
/* extern */
unsigned int Level10_7D7BCGetClosestPathNode() __asm__("func_8003645C");
/* extern */
unsigned int Level10_7D7BC_func_800369B8() __asm__("func_800369B8");
/* extern */
unsigned int Level10_7D7BCPlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
int Level10_7D7BCPlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
int Level10_7D7BCAbsoluteByteAngleDelta() __asm__("func_8004F264");
/* extern */
int Level10_7D7BCApproximatePlanarDistance() __asm__("func_8004F334");
/* extern */
unsigned int Level10_7D7BCDeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned int Level10_7D7BCRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
extern int Level10_7D7BC_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level10_7D7BC_D_80070328 __asm__("D_80070328");
extern unsigned char (*Level10_7D7BC_SpawnMoby)() __asm__("SpawnMoby");

void func_level_10_8007D7BC(void* arg0) {
    /* Original0x40-byte frame;
     stack result atSP+0x18.
     * Field offsets are bytes;
      index table entries are signed halfwords.
     * The heading helper precedes both original signed remainder chains.
     * Byte counters are loaded after their original helper calls.
     * Reloaded signed halfword and raw clamp joins remain distinct.
     * Initialized empty constraints retain the original register copies,
     * multiplication and load/branch delays. No instruction asm is added.
     * Raw units, helper semantics and frame cadence remain unresolved. */
    struct {
        int sp18;
        unsigned char pad1C[4];
    } originalFrame;

    register int temp_a0 __asm__("4");
    register int temp_a1 __asm__("5");
    register int var_v1 __asm__("3");
    register int count2 __asm__("2");
    int temp_a3_2;
    int temp_a3_3;
    int nextIndex21;
    int previousIndex20;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int distanceWord16;
    int temp_s1;
    int temp_s1_2;
    register int temp_s1_3 __asm__("17");
    int temp_v0_2;
    int temp_v0_3;
    register int signedHelperWord3 __asm__("3");
    int temp_v0_8;
    int temp_v1_6;
    int var_a0;
    register int absoluteWord2 __asm__("2");
    register int var_v0_3 __asm__("2");
    register int var_v0_4 __asm__("2");
    register int var_v0_5 __asm__("2");
    register int var_v1_2 __asm__("3");
    register int var_v1_3 __asm__("3");
    unsigned int temp_v0_9;
    unsigned int temp_a0_2;
    register unsigned int temp_a0_3 __asm__("4");
    unsigned int temp_a1_2;
    unsigned int temp_s0;
    register unsigned int temp_v0_4 __asm__("2");
    register unsigned int temp_v1_7 __asm__("3");
    unsigned int var_v0_2;
    unsigned int var_v0_6;
    register void* temp_a3 __asm__("7");
    register void* privateRecord18 __asm__("18");
    register void* ownerRecord19 __asm__("19");
    register void* originalOwner4 __asm__("4");
    void* temp_v0;
    void* temp_v0_5;
    void* temp_v0_6;
    void* temp_v1;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_4;
    void* temp_v1_5;

    originalOwner4 = arg0;
    MATCHING_KEEP(originalOwner4);
    ownerRecord19 = arg0;
    MATCHING_KEEP(ownerRecord19);
    privateRecord18 = Level10_7D7BCField(ownerRecord19, void**, 0);
    if (Level10_7D7BCField(ownerRecord19, int*, 0x18) == 0) {
        goto block_2;
    }
    Level10_7D7BCPlayMobySoundEvent(originalOwner4, 0, 0);
    Level10_7D7BC_SpawnMoby(0x10, ownerRecord19);
    Level10_7D7BCRefreshMobySpatialGridAndBasis(ownerRecord19, 4);
    Level10_7D7BC_func_800369B8(ownerRecord19, 0x20);
    Level10_7D7BCDeleteMoby(ownerRecord19);
block_2:
    temp_s0 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x48);
    if (temp_s0 == 1) {
        goto block_18;
    }
    if ((int)temp_s0 >= 2) {
        goto block_6;
    }
    if (temp_s0 == 0) {
        goto block_8;
    }
    return;
block_6:
    if (temp_s0 == 2) {
        goto block_43;
    }
    return;
block_8:
    if (Level10_7D7BCApproximatePlanarDistance(ownerRecord19 + 0xC, &Level10_7D7BC_D_80070328) >=
        0x1C00) {
        goto block_15;
    }
    temp_s1 =
        Level10_7D7BCPlanarHeadingLookup(Level10_7D7BCField(&Level10_7D7BC_D_80070328, int*, 0) -
                                             Level10_7D7BCField(ownerRecord19, int*, 0xC),
                                         Level10_7D7BCField(&Level10_7D7BC_D_80070328, int*, 4) -
                                             Level10_7D7BCField(ownerRecord19, int*, 0x10),
                                         0);
    temp_a3 = Level10_7D7BCField(privateRecord18, void**, 0x14);
    temp_a1 = Level10_7D7BCField(temp_a3, short*, 2);
    temp_a0 = Level10_7D7BCField(temp_a3, short*, 0);
    MATCHING_KEEP2(temp_a0, temp_a1);
    nextIndex21 = (int)(temp_a1 + 1) % temp_a0;
    {
        register int preceding3 __asm__("3");
        preceding3 = temp_a0 - 1;
        MATCHING_KEEP(preceding3);
        temp_a1 += preceding3;
        MATCHING_KEEP(temp_a1);
        previousIndex20 = temp_a1 % temp_a0;
    }
    temp_v1 = (nextIndex21 * 0x10) + Level10_7D7BCField(temp_a3, int*, 0xC);
    temp_a3_2 = Level10_7D7BCField(temp_v1, int*, 0);
    temp_s0_2 = Level10_7D7BCPlanarHeadingLookup(
        temp_a3_2 - Level10_7D7BCField(ownerRecord19, int*, 0xC),
        Level10_7D7BCField(temp_v1, int*, 4) - Level10_7D7BCField(ownerRecord19, int*, 0x10), 0,
        temp_a3_2);
    temp_v1_2 = (previousIndex20 * 0x10) +
                Level10_7D7BCField(Level10_7D7BCField(privateRecord18, void**, 0x14), int*, 0xC);
    temp_a3_3 = Level10_7D7BCField(temp_v1_2, int*, 0);
    temp_s0_3 = Level10_7D7BCPlanarHeadingLookup(
        temp_a3_3 - Level10_7D7BCField(ownerRecord19, int*, 0xC),
        Level10_7D7BCField(temp_v1_2, int*, 4) - Level10_7D7BCField(ownerRecord19, int*, 0x10), 0,
        temp_a3_3);
    temp_s0_4 = Level10_7D7BCAbsoluteByteAngleDelta(temp_s1, temp_s0_2);
    if (Level10_7D7BCAbsoluteByteAngleDelta(temp_s1, temp_s0_3) >= temp_s0_4) {
        goto block_11;
    }
    Level10_7D7BCField(Level10_7D7BCField(privateRecord18, void**, 0x14), short*, 2) =
        (short)nextIndex21;
    goto block_12;
block_11:
    Level10_7D7BCField(Level10_7D7BCField(privateRecord18, void**, 0x14), short*, 2) =
        (short)previousIndex20;
block_12:
    temp_v1_3 = Level10_7D7BCField(privateRecord18, void**, 0x14);
    temp_v0 = (Level10_7D7BCField(temp_v1_3, short*, 2) * 0x10) +
              Level10_7D7BCField(temp_v1_3, int*, 0xC);
    temp_s1_2 = Level10_7D7BCPlanarHeadingLookup(
        Level10_7D7BCField(temp_v0, int*, 0) - Level10_7D7BCField(ownerRecord19, int*, 0xC),
        Level10_7D7BCField(temp_v0, int*, 4) - Level10_7D7BCField(ownerRecord19, int*, 0x10), 0);
    temp_s1_3 = temp_s1_2 + Level10_7D7BCRandSignedBetween(0, 0x20);
    MATCHING_KEEP_CLOBBER(temp_s1_3, "6");
    {
        register int field3 __asm__("3");
        register int field2 __asm__("2");
        register int caller4 __asm__("4");
        register int caller5 __asm__("5");
        register int caller6 __asm__("6");
        caller6 = 0;
        MATCHING_KEEP(caller6);
        field3 = Level10_7D7BCField(ownerRecord19, int*, 0xC);
        caller4 = Level10_7D7BCField(&Level10_7D7BC_D_80070328, int*, 0);
        field2 = Level10_7D7BCField(ownerRecord19, int*, 0x10);
        caller5 = Level10_7D7BCField(&Level10_7D7BC_D_80070328, int*, 4);
        MATCHING_KEEP4(field3, field2, caller4, caller5);
        caller4 = field3 - caller4;
        caller5 = field2 - caller5;
        temp_v0_2 = Level10_7D7BCPlanarHeadingLookup(caller4, caller5, caller6);
    }
    {
        register int productReturn2 __asm__("2");
        register int factor3 __asm__("3");
        productReturn2 = Level10_7D7BCSubAngle8(temp_v0_2, temp_s1_3 & 0xFF);
        factor3 = 0x6C;
        __asm__("" : "=r"(factor3) : "0"(factor3), "r"(productReturn2));
        Level10_7D7BCField(privateRecord18, unsigned char*, 0x18) =
            temp_v0_2 + ((productReturn2 * factor3) >> 7);
    }
    Level10_7D7BCField(privateRecord18, unsigned char*, 0x1A) =
        Level10_7D7BCRandBetween(0x6E, 0x8C);
    temp_v1_4 = Level10_7D7BCField(privateRecord18, void**, 0x14);
    Level10_7D7BCField(privateRecord18, unsigned char*, 0x1B) = 0U;
    temp_v0_3 =
        (int)(Level10_7D7BCApproximatePlanarDistance(
                  ownerRecord19 + 0xC, Level10_7D7BCField(temp_v1_4, int*, 0xC) +
                                           (Level10_7D7BCField(temp_v1_4, short*, 2) * 0x10)) /
              (int)Level10_7D7BCField(privateRecord18, unsigned char*, 0x1A)) >>
        1;
    Level10_7D7BCField(privateRecord18, signed char*, 0x19) = (signed char)temp_v0_3;
    if ((unsigned int)(temp_v0_3 & 0xFF) < 0x5BU) {
        goto block_14;
    }
    Level10_7D7BCField(privateRecord18, signed char*, 0x19) = 0x5A;
block_14:
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x48) = 1U;
    Level10_7D7BC_func_80034F40(ownerRecord19, 1);
block_15:
    if (Level10_7D7BC_D_8006C770 == 0) {
        goto block_72;
    }
    if (Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3D) == 0) {
        goto block_72;
    }
    Level10_7D7BC_D_8006C770 = 0;
    temp_v0_4 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3D);
    temp_a1_2 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3F);
    Level10_7D7BCField(ownerRecord19, signed char*, 0x40) = 0x72;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3D) = 0U;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3F) = 0U;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3C) = temp_v0_4;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x3E) = temp_a1_2;
    Level10_7D7BCEmptyAnimationTransitionHook(ownerRecord19, temp_a1_2);
    return;
block_18:
    temp_v0_5 = Level10_7D7BCField(privateRecord18, void**, 0x14);
    distanceWord16 = Level10_7D7BCApproximatePlanarDistance(
        ownerRecord19 + 0xC, Level10_7D7BCField(temp_v0_5, int*, 0xC) +
                                 (Level10_7D7BCField(temp_v0_5, short*, 2) * 0x10));
    temp_a0_2 = Level10_7D7BCField(privateRecord18, unsigned char*, 0x1B);
    if (temp_a0_2 >= (unsigned char)Level10_7D7BCField(privateRecord18, unsigned char*, 0x1A)) {
        goto block_20;
    }
    Level10_7D7BCField(privateRecord18, unsigned char*, 0x1B) = (unsigned char)(temp_a0_2 + 0xA);
block_20:
    if (Level10_7D7BCCountTimerDown(privateRecord18 + 0x19, 1) == 0) {
        goto block_30;
    }
    temp_v1_5 = Level10_7D7BCField(privateRecord18, void**, 0x14);
    temp_v0_6 = (Level10_7D7BCField(temp_v1_5, short*, 2) * 0x10) +
                Level10_7D7BCField(temp_v1_5, int*, 0xC);
    signedHelperWord3 = Level10_7D7BCSubAngle8(
        Level10_7D7BCPlanarHeadingLookup(
            Level10_7D7BCField(temp_v0_6, int*, 0) - Level10_7D7BCField(ownerRecord19, int*, 0xC),
            Level10_7D7BCField(temp_v0_6, int*, 4) - Level10_7D7BCField(ownerRecord19, int*, 0x10),
            0),
        Level10_7D7BCField(privateRecord18, unsigned char*, 0x18));
    MATCHING_KEEP(signedHelperWord3);
    absoluteWord2 = signedHelperWord3;
    if (signedHelperWord3 >= 0) {
        goto block_23;
    }
    absoluteWord2 = -absoluteWord2;
block_23:
    var_a0 = 1;
    if (absoluteWord2 < 0x1F) {
        goto block_25;
    }
    var_a0 = 2;
block_25:
    if (signedHelperWord3 <= 0) {
        goto block_27;
    }
    var_v0_2 = Level10_7D7BCField(privateRecord18, unsigned char*, 0x18) - var_a0;
    goto block_29;
block_27:
    if (signedHelperWord3 >= 0) {
        goto block_30;
    }
    var_v0_2 = Level10_7D7BCField(privateRecord18, unsigned char*, 0x18) + var_a0;
block_29:
    Level10_7D7BCField(privateRecord18, unsigned char*, 0x18) = var_v0_2;
block_30:
    if (Level10_7D7BCTurnMobyTowardHeading(
            ownerRecord19, Level10_7D7BCField(privateRecord18, unsigned char*, 0x18), 5, 0x14, 1,
            0) == 0) {
        goto block_39;
    }
    if (Level10_7D7BC_func_80035DDC(ownerRecord19,
                                    Level10_7D7BCField(privateRecord18, unsigned char*, 0x1B),
                                    0x12C, 0x12C, 0x55) == 0) {
        goto block_33;
    }
    Level10_7D7BCField(privateRecord18, unsigned short*, 0x12) =
        (unsigned short)(Level10_7D7BCField(privateRecord18, unsigned short*, 0x12) + 1);
    goto block_34;
block_33:
    Level10_7D7BCField(privateRecord18, unsigned short*, 0x12) = 0U;
block_34:
    if ((short)Level10_7D7BCField(privateRecord18, unsigned short*, 0x12) < 4) {
        var_v0_3 = distanceWord16 < 0x708;
        goto block_40;
    }
    if (Level10_7D7BC_D_8006C770 == 0) {
        goto block_39;
    }
    if (distanceWord16 >= 0x1400) {
        goto block_38;
    }
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x48) = 0U;
    goto block_39;
block_38:
    Level10_7D7BCField(privateRecord18, unsigned char*, 0x18) =
        (unsigned char)(Level10_7D7BCField(privateRecord18, unsigned char*, 0x18) +
                        Level10_7D7BCRandSignedBetween(0x3C, 0x64));
block_39:
    var_v0_3 = distanceWord16 < 0x708;
block_40:
    if (var_v0_3 == 0) {
        goto block_72;
    }
    if (Level10_7D7BC_D_8006C770 == 0) {
        goto block_72;
    }
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x48) = 0U;
    return;
block_43:
    temp_v0_8 = Level10_7D7BCCountTimerDown(privateRecord18 + 0x19, 1);
    if (temp_v0_8 == 0) {
        goto block_72;
    }
    if (temp_v0_8 != temp_s0) {
        goto block_46;
    }
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x4C) = 0x30U;
    Level10_7D7BCField(ownerRecord19, signed char*, 0x41) = 1;
    Level10_7D7BCField(ownerRecord19, signed char*, 0x4D) = 1;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x4E) =
        (unsigned char)Level10_7D7BCField(ownerRecord19, unsigned char*, 0x4C);
block_46:
    temp_v0_9 = Level10_7D7BCField(privateRecord18, unsigned short*, 0x10) - 0xC;
    Level10_7D7BCField(privateRecord18, unsigned short*, 0x10) = temp_v0_9;
    if ((short)temp_v0_9 >= -0x1F4) {
        goto block_48;
    }
    {
        register int floor2 __asm__("2");
        floor2 = -0x1F4;
        MATCHING_KEEP(floor2);
        Level10_7D7BCField(privateRecord18, short*, 0x10) = floor2;
    }
block_48:
    temp_v1_6 = Level10_7D7BCField(ownerRecord19, int*, 0x14) +
                (short)Level10_7D7BCField(privateRecord18, unsigned short*, 0x10);
    Level10_7D7BCField(ownerRecord19, int*, 0x14) = temp_v1_6;
    if ((Level10_7D7BCField(privateRecord18, int*, 0x1C) +
         Level10_7D7BCField(ownerRecord19, short*, 0x38)) < temp_v1_6) {
        goto block_55;
    }
    if ((short)Level10_7D7BCField(privateRecord18, unsigned short*, 0x10) >= 0) {
        goto block_55;
    }
    count2 = Level10_7D7BCField(privateRecord18, unsigned char*, 0x22);
    MATCHING_BARRIER_VOLATILE("memory");
    var_v1 = Level10_7D7BCField(privateRecord18, short*, 0x10);
    count2 += 1;
    MATCHING_KEEP2(count2, var_v1);
    if (var_v1 >= 0) {
        goto block_52;
    }
    var_v1 = -var_v1;
block_52:
    Level10_7D7BCField(privateRecord18, unsigned char*, 0x22) = count2;
    if (var_v1 >= 0x32) {
        goto block_54;
    }
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x44) = 0U;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x45) = 0U;
    Level10_7D7BCField(ownerRecord19, int*, 0x14) =
        (int)(Level10_7D7BCField(privateRecord18, int*, 0x1C) +
              Level10_7D7BCField(ownerRecord19, short*, 0x38));
    Level10_7D7BCGetClosestPathNode(ownerRecord19 + 0xC,
                                    Level10_7D7BCField(privateRecord18, void**, 0x14),
                                    &originalFrame.sp18);
    Level10_7D7BCField(Level10_7D7BCField(privateRecord18, void**, 0x14), short*, 2) =
        (short)originalFrame.sp18;
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x48) = 0U;
    Level10_7D7BC_func_80034F40(ownerRecord19, 0);
block_54:
    Level10_7D7BCField(privateRecord18, unsigned short*, 0x10) = (unsigned short)-(
        (int)((short)Level10_7D7BCField(privateRecord18, unsigned short*, 0x10) * 5) >> 3);
block_55:
    if ((unsigned char)Level10_7D7BCField(privateRecord18, unsigned char*, 0x22) < 2U) {
        goto block_70;
    }
    temp_v1_7 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x44);
    if (temp_v1_7 >= 0x80U) {
        goto block_58;
    }
    var_v1_2 = -(int)temp_v1_7;
    goto block_59;
block_58:
    {
        register int fullTurn2 __asm__("2");
        fullTurn2 = 0x100;
        MATCHING_KEEP(fullTurn2);
        var_v1_2 = fullTurn2 - temp_v1_7;
    }
block_59:
    if (var_v1_2 < 6) {
        var_v0_4 = var_v1_2 < -5;
        goto block_61;
    }
    var_v1_2 = 5;
    MATCHING_KEEP(var_v1_2);
    var_v0_4 = var_v1_2 < -5;
block_61:
    if (var_v0_4 == 0) {
        goto block_63;
    }
    var_v1_2 = -5;
block_63:
    temp_a0_3 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x45);
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x44) =
        (unsigned char)(Level10_7D7BCField(ownerRecord19, unsigned char*, 0x44) + var_v1_2);
    var_v1_3 = -(int)temp_a0_3;
    if (temp_a0_3 < 0x80U) {
        goto block_65;
    }
    {
        register int fullTurn2 __asm__("2");
        fullTurn2 = 0x100;
        MATCHING_KEEP(fullTurn2);
        var_v1_3 = fullTurn2 - temp_a0_3;
    }
block_65:
    if (var_v1_3 < 6) {
        var_v0_5 = var_v1_3 < -5;
        goto block_67;
    }
    var_v1_3 = 5;
    MATCHING_KEEP(var_v1_3);
    var_v0_5 = var_v1_3 < -5;
block_67:
    if (var_v0_5 == 0) {
        goto block_69;
    }
    var_v1_3 = -5;
block_69:
    {
        register int field2 __asm__("2");
        field2 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x45);
        MATCHING_KEEP(field2);
        var_v0_6 = field2 + var_v1_3;
    }
    goto block_71;
block_70:
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x44) =
        (unsigned char)(Level10_7D7BCField(ownerRecord19, unsigned char*, 0x44) +
                        Level10_7D7BCField(privateRecord18, unsigned char*, 0x20));
    {
        register int field2 __asm__("2");
        register int field3 __asm__("3");
        MATCHING_BARRIER_VOLATILE("memory");
        field2 = Level10_7D7BCField(ownerRecord19, unsigned char*, 0x45);
        field3 = Level10_7D7BCField(privateRecord18, unsigned char*, 0x21);
        MATCHING_KEEP2(field2, field3);
        var_v0_6 = field2 + field3;
    }
block_71:
    Level10_7D7BCField(ownerRecord19, unsigned char*, 0x45) = var_v0_6;
    Level10_7D7BCRefreshMobySpatialGridAndBasis(ownerRecord19, 2);
block_72:
    return;
}
#undef Level10_7D7BCField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original929 words. AI generated, not human reviewed; uninstalled. */
#define Level10_7DF18Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level10_7DF18Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level10_7DF18_func_800136F0() __asm__("func_800136F0");
int Level10_7DF18_func_80013D44() __asm__("func_80013D44");
int Level10_7DF18_func_8001A358() __asm__("func_8001A358");
int Level10_7DF18RequestMobyAnimation() __asm__("func_80034F40");
int Level10_7DF18CountTimerDown() __asm__("func_800359A4");
int Level10_7DF18_func_80035A80() __asm__("func_80035A80");
int Level10_7DF18ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Level10_7DF18_func_80035DDC() __asm__("func_80035DDC");
int Level10_7DF18RandBetween() __asm__("func_8003636C");
int Level10_7DF18_func_800365E4() __asm__("func_800365E4");
int Level10_7DF18_func_80037BBC() __asm__("func_80037BBC");
int Level10_7DF18_func_800492DC() __asm__("func_800492DC");
int Level10_7DF18CopyVector() __asm__("func_8004F178");
int Level10_7DF18AddVector() __asm__("func_8004F194");
int Level10_7DF18SubtractVector() __asm__("func_8004F1C8");
int Level10_7DF18AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Level10_7DF18ApproximatePlanarDistance() __asm__("func_8004F334");
int Level10_7DF18_func_800512E4() __asm__("func_800512E4");
int Level10_7DF18DeleteMoby() __asm__("func_80055B18");
int Level10_7DF18RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level10_7DF18InterpolateMobyVertex() __asm__("func_80055F14");
int Level10_7DF18_func_80056270() __asm__("func_80056270");
int Level10_7DF18_func_8005629C() __asm__("func_8005629C");
extern int Level10_7DF18_D_800658A0 __asm__("D_800658A0");
extern int Level10_7DF18_D_80065920 __asm__("D_80065920");
extern int Level10_7DF18_D_80066FCC __asm__("D_80066FCC");
extern int Level10_7DF18_D_8006C550 __asm__("D_8006C550");
extern int Level10_7DF18_D_8006C598 __asm__("D_8006C598");
extern int Level10_7DF18_D_8006C59C __asm__("D_8006C59C");
extern int Level10_7DF18_D_8006C660 __asm__("D_8006C660");
extern int Level10_7DF18_D_8006C730 __asm__("D_8006C730");
extern int Level10_7DF18_D_8006C73C __asm__("D_8006C73C");
extern int Level10_7DF18_D_8006C770 __asm__("D_8006C770");
extern unsigned short Level10_7DF18_D_8006E040 __asm__("D_8006E040");
extern int Level10_7DF18_D_8006E048 __asm__("D_8006E048");
extern int Level10_7DF18_D_8006E160 __asm__("D_8006E160");
extern int Level10_7DF18_D_8006E17C __asm__("D_8006E17C");
extern int Level10_7DF18_D_8006E344 __asm__("D_8006E344");
extern int Level10_7DF18_D_80070300 __asm__("D_80070300");
extern int Level10_7DF18_D_80070328 __asm__("D_80070328");
extern int Level10_7DF18_D_80071570 __asm__("D_80071570");
extern signed char Level10_7DF18_D_80071586 __asm__("D_80071586");
extern int Level10_7DF18_D_80071FB0 __asm__("D_80071FB0");
extern int (*Level10_7DF18_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level10_7DF18_SpawnParticle)() __asm__("SpawnParticle");
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Level10_7DF18Product;
#define Level10_7DF18Low(a, b)                    \
    ({                                            \
        int x = (a), y = (b);                     \
        Level10_7DF18Product p;                   \
        p.full = (long long)x * (long long)y;     \
        __asm__("" : "=x"(p.full) : "0"(p.full)); \
        (int)p.words.low;                         \
    })
void func_level_10_8007DF18(void* ownerInput) {
    register int owner __asm__("$18");
    register int privateState __asm__("$19");
    register int saved16 __asm__("$16");
    register int saved17 __asm__("$17");
    register int saved20 __asm__("$20");
    int saved21;
    register int result __asm__("$2"), scratch3 __asm__("$3"), argument0 __asm__("$4"),
        argument1 __asm__("$5"), argument2 __asm__("$6");
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
    } originalFrame;

    int temp_v0_7;

    __asm__("" : "=r"(saved17));
    owner = (int)ownerInput;
    Level10_7DF18Keep(owner);
    privateState = *((int*)(((unsigned char*)owner) + 0));
    scratch3 = *((int*)(((unsigned char*)privateState) + 0x2C));
    if (scratch3 >= 0) {
        saved17 = *((int*)(((unsigned char*)((scratch3 * 0x58) + Level10_7DF18_D_8006C550)) + 0));
    }
    scratch3 = *((unsigned char*)(((unsigned char*)owner) + 0x48));
    switch (scratch3) {
        default:
            goto block_117;

        case 0:

        case 1:
            scratch3 = *((unsigned char*)(((unsigned char*)owner) + 0x49));
            switch (scratch3) {
                default:
                    goto block_117;

                case 0:
                    saved21 = ((int)(&Level10_7DF18_D_80066FCC)) + 0x11;
                    Level10_7DF18Keep(saved21);
                    saved20 = 0;
                    if ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80071FB0)) +
                                                              Level10_7DF18Field(
                                                                  saved21, unsigned char*, 0))) +
                                            0))) == 0) {
                        argument1 = ((*((int*)(((unsigned char*)privateState) + 0x3C))) * 0x58) +
                                    Level10_7DF18_D_8006C550;
                        saved16 = *((int*)argument1);
                        *((int*)(((unsigned char*)privateState) + 0x40)) =
                            Level10_7DF18_SpawnMoby(0x1E6, argument1);
                        *((int*)(((unsigned char*)saved16) + 4)) =
                            (int)((*((int*)(((unsigned char*)saved16) + 4))) + 1);
                        argument0 = *((int*)(((unsigned char*)saved17) + 0xC));
                        if ((argument0 < 0) ||
                            ((*((short*)(((unsigned char*)owner) + 0x36))) == 0x20F)) {
                            if (!((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80070300)) +
                                                                        (*((unsigned char*)(((unsigned char*)((
                                                                                                int)((unsigned char*)
                                                                                                         saved21 +
                                                                                                     (*((int*)(((unsigned char*)
                                                                                                                    saved17) +
                                                                                                               0)))))) +
                                                                                            (-0x11)))))) +
                                                      0))) &
                                  1)) {
                                if (((*((short*)(((unsigned char*)owner) + 0x36))) == 0x20F) &&
                                    ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80071570)) +
                                                                           argument0)) +
                                                         0))) == 0)) {
                                    *((unsigned char*)(((unsigned char*)owner) + 0x49)) = 5U;
                                    goto block_117;
                                }
                                goto block_112;
                            }
                            goto block_15;
                        }
                        if ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80071570)) +
                                                                  argument0)) +
                                                0))) != 0) {
                            if ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80070300)) +
                                                                      (*((unsigned char*)(((unsigned char*)((
                                                                                              int)((unsigned char*)
                                                                                                       saved21 +
                                                                                                   (*((int*)(((unsigned char*)
                                                                                                                  saved17) +
                                                                                                             0)))))) +
                                                                                          (-0x11)))))) +
                                                    0))) &
                                1) {
                            block_15:
                                saved20 = 1;

                                goto block_16;
                            }
                            goto block_112;
                        }
                    block_16:
                        *((unsigned char*)(((unsigned char*)owner) + 0x49)) = 1U;

                        if (saved20 != 0) {
                            *((int*)(((unsigned char*)saved16) + 8)) =
                                (int)((*((int*)(((unsigned char*)saved16) + 8))) + 1);
                            if ((*((int*)(((unsigned char*)saved16) + 0))) == 0) {
                                *((int*)(((unsigned char*)saved16) + 0)) = owner;
                            }
                            if ((*((int*)(((unsigned char*)saved17) + 0))) ==
                                Level10_7DF18_D_8006C73C) {
                                argument2 = 0;
                                argument0 = *(
                                    (int*)(((unsigned char*)(((*((unsigned char*)(((unsigned char*)
                                                                                       owner) +
                                                                                  0x43))) *
                                                              4) +
                                                             Level10_7DF18_D_8006C730)) +
                                           0));
                                do {
                                    argument1 =
                                        *((unsigned short*)(((unsigned char*)argument0) + 0));
                                    if ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80070300)) +
                                                                              (*((unsigned char*)(((unsigned char*)((*((int*)(*((
                                                                                                                        int*)(((unsigned char*)((
                                                                                                                                                    (*((int*)(((unsigned char*)(*((int*)(((unsigned char*)(((argument1 & 0x7FFF) * 0x58) + Level10_7DF18_D_8006C550)) +
                                                                                                                                                                                         0)))) +
                                                                                                                                                              0x2C))) *
                                                                                                                                                    0x58) +
                                                                                                                                                Level10_7DF18_D_8006C550)) +
                                                                                                                              0))))) +
                                                                                                                    ((int)(&Level10_7DF18_D_80066FCC)))) +
                                                                                                  0))))) +
                                                            0))) &
                                        1) {
                                        argument2 += 1;
                                    }
                                    result = (int)((unsigned int)argument1 << 16);
                                    Level10_7DF18Keep(result);
                                    argument0 += 2;
                                } while (result >= 0);
                                if (argument2 == 5) {
                                    *((int*)(((unsigned char*)saved16) + 8)) =
                                        (int)((*((int*)(((unsigned char*)saved16) + 8))) - 1);
                                    *((unsigned char*)(((unsigned char*)owner) + 0x49)) = 3U;
                                } else {
                                    Level10_7DF18CopyVector(
                                        owner + 0xC,
                                        (Level10_7DF18_D_8006C550 +
                                         ((*((int*)(((unsigned char*)privateState) + 0x3C))) *
                                          0x58)) +
                                            0xC);
                                    Level10_7DF18RefreshMobySpatialGridAndBasis(owner, 2);
                                    goto block_27;
                                }
                            } else {
                            block_27:
                                *((unsigned char*)(((unsigned char*)owner) + 0x48)) = 3U;

                                Level10_7DF18RequestMobyAnimation(owner, 3);
                            }
                        }
                    } else {
                        goto block_112;
                    }
                    goto block_117;

                case 1:
                    if ((*((int*)(((unsigned char*)(*(
                                      (int*)(((unsigned char*)(((*((int*)(((unsigned char*)
                                                                               privateState) +
                                                                          0x3C))) *
                                                                0x58) +
                                                               Level10_7DF18_D_8006C550)) +
                                             0)))) +
                                  8))) == 5) {
                        *((signed char*)(((unsigned char*)privateState) + 2)) = 2;
                        if ((*((unsigned char*)(((unsigned char*)(((*((int*)(((unsigned char*)
                                                                                  privateState) +
                                                                             0x3C))) *
                                                                   0x58) +
                                                                  Level10_7DF18_D_8006C550)) +
                                                0x48))) == 1) {
                            Level10_7DF18_D_80071586 = 1;
                            *((signed char*)(((unsigned char*)(((*((int*)(((unsigned char*)
                                                                               privateState) +
                                                                          0x3C))) *
                                                                0x58) +
                                                               Level10_7DF18_D_8006C550)) +
                                             0x48)) = 2;
                        }
                    } else {
                        argument0 = *((int*)(((unsigned char*)saved17) + 8));
                        if ((argument0 > 0) &&
                            ((*((unsigned char*)(((unsigned char*)privateState) + 5))) != 0xFF)) {
                            if (Level10_7DF18_D_8006C660 >= argument0 ? (result = 3, 1)
                                                                      : (result = 3, 0)) {
                                result = *((int*)(((unsigned char*)saved17) + 0xC));
                                if (result >= 0) {
                                    if ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80071570)) +
                                                                              result)) +
                                                            0))) != 0) {
                                        *((unsigned char*)(((unsigned char*)privateState) + 5)) =
                                            0U;
                                        *((signed char*)(((unsigned char*)privateState) + 2)) = 0;
                                    } else {
                                        goto block_38;
                                    }
                                } else {
                                block_38:
                                    *((unsigned char*)(((unsigned char*)privateState) + 5)) = 1U;

                                    result = 4;
                                    goto block_40;
                                }
                            } else {
                                Level10_7DF18_D_8006C59C = argument0;
                            block_40:
                                *((signed char*)(((unsigned char*)privateState) + 2)) = result;
                            }
                        }
                    }
                    if ((*((short*)(((unsigned char*)owner) + 0x36))) == 0x1B2) {
                        if (Level10_7DF18AbsoluteByteAngleDelta(
                                ((int)(Level10_7DF18_D_8006E040 << 0x10)) >> 0x14,
                                ((*((unsigned char*)(((unsigned char*)owner) + 0x46))) + 0x80) &
                                    0xFF) < 0x41) {
                            goto block_44;
                        }
                    } else {
                    block_44:
                        result = Level10_7DF18_func_80037BBC(owner, 0);
                        if (result != 0) {
                            argument0 = owner;
                            MATCHING_KEEP_VOLATILE(result);
                            argument1 = 0;
                            argument2 = 2;
                            goto block_58;
                        } else {
                            MATCHING_BARRIER_VOLATILE("$2");
                            result = Level10_7DF18_D_8006C770;
                            if (result != 0) {
                                result = Level10_7DF18Field(privateState, int*, 0x28);
                                argument0 = owner;
                                if (result == 0) {
                                    Level10_7DF18RequestMobyAnimation(argument0, 1);
                                    Level10_7DF18Field(privateState, int*, 0x28) =
                                        Level10_7DF18RandBetween(3, 6);
                                } else {
                                    Level10_7DF18RequestMobyAnimation(argument0, 0);
                                    result = Level10_7DF18Field(privateState, int*, 0x28) - 1;
                                    Level10_7DF18Field(privateState, int*, 0x28) = result;
                                }
                            }
                        }
                    }
                    goto block_117;

                case 2:
                    result = (*((int*)(((unsigned char*)privateState) + 0x34))) - 8;
                    *((int*)(((unsigned char*)privateState) + 0x34)) = result;
                    if (result < (-0xF0)) {
                        *((int*)(((unsigned char*)privateState) + 0x34)) = -0xF0;
                    }
                    *((int*)(((unsigned char*)owner) + 0x14)) =
                        (int)((*((int*)(((unsigned char*)owner) + 0x14))) +
                              (*((int*)(((unsigned char*)privateState) + 0x34))));
                    Level10_7DF18CopyVector(&originalFrame.sp20, owner + 0xC);
                    originalFrame.sp28 += 0x200;
                    result = Level10_7DF18_func_8001A358(&originalFrame.sp20, 0x200);
                    originalFrame.sp28 = result;
                    if (result != 0) {
                        argument0 = owner;
                        argument1 = 4;
                        Level10_7DF18Field(owner, int*, 0x14) = result;
                        *((int*)(((unsigned char*)privateState) + 0x28)) = 0x1E;
                        goto block_83;
                    }
                    goto block_117;

                case 3:
                    if (((*((int*)(((unsigned char*)((int)(&Level10_7DF18_D_80070328))) + 0xB8))) ==
                         0) &&
                        (Level10_7DF18ApproximatePlanarDistance(
                             owner + 0xC, (((int)(&Level10_7DF18_D_80070328)) + 0xB8) - 0xB8) <
                         0x1800)) {
                        if (Level10_7DF18_D_8006C598 == 0) {
                            argument0 = owner;
                            argument1 = 0;
                            argument2 = 2;
                            result = 1;
                            Level10_7DF18Field(privateState, signed char*, 2) = result;
                        block_58:
                            Level10_7DF18_func_800512E4(argument0, argument1, argument2);

                            *((unsigned char*)(((unsigned char*)owner) + 0x48)) = 2U;
                            goto block_117;
                        }
                        *((int*)(((unsigned char*)((int)(&Level10_7DF18_D_80070328))) + 0x20C)) =
                            0x10000002;
                    }
                    goto block_117;

                case 4:
                    argument1 = 3;
                    if (Level10_7DF18_D_8006E048 == 1) {
                        argument0 = owner;
                        Level10_7DF18Keep(argument0);
                        scratch3 = Level10_7DF18Field(privateState, int*, 0x3C);
                        Level10_7DF18_D_8006C73C = 0;
                        result = scratch3 * 88;
                        scratch3 = Level10_7DF18_D_8006C550;
                        result += scratch3;
                        scratch3 = 2;
                        Level10_7DF18Field(result, signed char*, 0x48) = scratch3;
                        result = 1;
                        Level10_7DF18_D_80071586 = result;
                        result = 3;
                        goto block_84;
                    }
                    goto block_117;

                case 5:
                    if ((*((unsigned char*)(((unsigned char*)(((int)(&Level10_7DF18_D_80071570)) +
                                                              (*((int*)(((unsigned char*)saved17) +
                                                                        0xC))))) +
                                            0))) != 0) {
                        result = *((int*)(((unsigned char*)privateState) + 0x38));
                        if (result != 0) {
                            argument2 = 0x10000000;
                            MATCHING_OBSERVE_VOLATILE(argument2);

                            Level10_7DF18CopyVector((int)(&Level10_7DF18_D_8006E17C),
                                                    (*((int*)(((unsigned char*)result) + 0xC))) +
                                                        0x10);
                            argument1 =
                                *((int*)(((unsigned char*)(*(
                                             (int*)(((unsigned char*)privateState) + 0x38)))) +
                                         0xC));
                            Level10_7DF18_func_800136F0(((int)(&Level10_7DF18_D_8006E17C)) - 0x14,
                                                        argument1, argument1 + 0x10);
                            Level10_7DF18_D_8006E160 = 0x11;
                            __asm__ volatile("" ::"m"(Level10_7DF18_D_8006E160) : "$6", "memory");
                            argument2 = 0x10000000;
                            Level10_7DF18Keep(argument2);
                        } else {
                            argument2 = 0x10000000;
                        }
                        MATCHING_KEEP_VOLATILE(argument2);
                        argument2 |= 2;
                        result = Level10_7DF18Field(privateState, int*, 0x30);
                        argument0 = owner;
                        Level10_7DF18Field(result, short*, 2) = 0;
                        scratch3 = Level10_7DF18Field(privateState, int*, 0x30);
                        result = 1;
                        Level10_7DF18Field(scratch3, short*, 0xA) = result;
                        result = Level10_7DF18Field(owner, int*, 0x14);
                        argument1 = 4;
                        result -= 0x80;
                        Level10_7DF18Field(owner, int*, 0x14) = result;
                        Level10_7DF18Field((int)&Level10_7DF18_D_80070328, int*, 0x20C) = argument2;
                        result = 4;
                        goto block_84;
                    }
                    goto block_117;
            }

            break;

        case 2:
            if (Level10_7DF18_D_8006E344 != 1) {
                scratch3 = *((unsigned char*)(((unsigned char*)privateState) + 4));
                if (scratch3 == 4) {
                    argument0 = *((int*)(((unsigned char*)privateState) + 0x2C));
                    if ((argument0 >= 0) &&
                        ((*((short*)(((unsigned char*)owner) + 0x36))) != 0x20F)) {
                        *((signed char*)(((unsigned char*)((argument0 * 0x58) +
                                                           Level10_7DF18_D_8006C550)) +
                                         0x48)) = 9;
                    }
                    if ((*((int*)(((unsigned char*)privateState) + 0x30))) != 0) {
                        result = *((int*)(((unsigned char*)privateState) + 0x38));
                        if (result != 0) {
                            Level10_7DF18CopyVector((int)(&Level10_7DF18_D_8006E17C),
                                                    (*((int*)(((unsigned char*)result) + 0xC))) +
                                                        0x10);
                            argument1 =
                                *((int*)(((unsigned char*)(*(
                                             (int*)(((unsigned char*)privateState) + 0x38)))) +
                                         0xC));
                            Level10_7DF18_func_800136F0(((int)(&Level10_7DF18_D_8006E17C)) - 0x14,
                                                        argument1, argument1 + 0x10);
                            Level10_7DF18_D_8006E160 = 0x11;
                        }
                        argument0 = owner;
                        argument1 = 4;
                        result = 1;
                        goto block_82;
                    }
                    goto block_77;
                }
                if (scratch3 == 1) {
                    scratch3 = Level10_7DF18Field(privateState, int*, 0x3C);
                    argument2 = Level10_7DF18_D_8006C550;
                    result = scratch3 * 88 + argument2;
                    scratch3 = Level10_7DF18Field(result, int*, 0);
                    result = 5;
                    Level10_7DF18Field(scratch3, int*, 8) = result;
                    scratch3 = Level10_7DF18Field(privateState, int*, 0x3C);
                    result = scratch3 * 88 + argument2;
                    result = Level10_7DF18Field(result, unsigned char*, 0x46);
                    result =
                        Level10_7DF18Field((int)&Level10_7DF18_D_80065920 + result * 2, short*, 0);
                    originalFrame.sp20 = result;
                    scratch3 = Level10_7DF18Field(privateState, int*, 0x3C);
                    result = scratch3 * 88 + argument2;
                    result = Level10_7DF18Field(result, unsigned char*, 0x46);
                    result =
                        Level10_7DF18Field((int)&Level10_7DF18_D_800658A0 + result * 2, short*, 0);
                    argument0 = (int)&originalFrame.sp20;
                    originalFrame.sp28 = 0;
                    originalFrame.sp24 = result;
                    scratch3 = Level10_7DF18Field(privateState, int*, 0x3C);
                    argument1 = argument0;
                    result = scratch3 * 88;
                    argument2 += result;
                    Level10_7DF18Keep(argument2);
                    Level10_7DF18AddVector(argument0, argument1, argument2 + 12);

                    originalFrame.sp28 = Level10_7DF18_func_8001A358(&originalFrame.sp20, 0x2000);
                    Level10_7DF18_func_80013D44(
                        &originalFrame.sp20,
                        (*((unsigned char*)(((unsigned char*)(((*((int*)(((unsigned char*)
                                                                              privateState) +
                                                                         0x3C))) *
                                                               0x58) +
                                                              Level10_7DF18_D_8006C550)) +
                                            0x46))) +
                            0x80,
                        0, 0);
                    *((unsigned char*)(((unsigned char*)owner) + 0x49)) = 4U;
                }
            block_77:
                *((unsigned char*)(((unsigned char*)owner) + 0x48)) = 0U;

                *((int*)(((unsigned char*)privateState) + 0x28)) = 3;
            }
            goto block_117;

        case 3:
            argument0 = owner;
            argument1 = 0;
            scratch3 = Level10_7DF18Field(privateState, int*, 0x3C);
            __asm__ volatile("" ::: "$17", "memory");
            saved17 = (int)&originalFrame.sp40;
            result = scratch3 * 88;
            scratch3 = Level10_7DF18_D_8006C550;
            result += scratch3;
            scratch3 = Level10_7DF18Field(privateState, int*, 0x40);
            saved20 = Level10_7DF18Field(result, int*, 0);
            result = Level10_7DF18Field(scratch3, unsigned char*, 0x46);
            argument2 = saved17;
            Level10_7DF18Field(owner, unsigned char*, 0x46) = result;
            Level10_7DF18InterpolateMobyVertex(argument0, argument1, argument2);
            argument1 = 0;
            MATCHING_KEEP_CLOBBER(argument1, "$16");
            saved16 = (int)&originalFrame.sp30;
            argument0 = Level10_7DF18Field(privateState, int*, 0x40);
            argument2 = saved16;
            Level10_7DF18InterpolateMobyVertex(argument0, argument1, argument2);
            Level10_7DF18SubtractVector(saved17, saved16, saved17);
            saved16 = owner + 0xC;
            Level10_7DF18AddVector(saved16, saved16, saved17);
            Level10_7DF18ProbeGroundFromRaisedMoby(owner);
            Level10_7DF18_func_80056270(owner);
            Level10_7DF18_func_8005629C(owner);
            Level10_7DF18RefreshMobySpatialGridAndBasis(owner, 6);
            Level10_7DF18CopyVector(saved17, saved16);
            originalFrame.sp48 += 0x200;
            result = Level10_7DF18_func_8001A358(saved17, 0x200);
            originalFrame.sp48 = result;
            if (result != 0) {
                argument0 = *((int*)(((unsigned char*)privateState) + 0x40));
                if (argument0 != 0) {
                    Level10_7DF18DeleteMoby(argument0);
                    *((int*)(((unsigned char*)privateState) + 0x40)) = 0;
                }
                argument0 = owner;
                result = originalFrame.sp48;
                argument1 = 4;
                Level10_7DF18Field(owner, int*, 0x14) = result;
                result = 30;
                Level10_7DF18Field(privateState, int*, 0x28) = result;
                result = 2;
            block_82:
                *((unsigned char*)(((unsigned char*)owner) + 0x49)) = result;

            block_83:
                result = 4;
                Level10_7DF18Keep(result);

            block_84:
                *((unsigned char*)(((unsigned char*)owner) + 0x48)) = result;

                Level10_7DF18RequestMobyAnimation(argument0, argument1);
                goto block_117;
            }
            if (((*((int*)(((unsigned char*)saved20) + 0))) == owner) &&
                (Level10_7DF18ApproximatePlanarDistance(
                     (int)(&Level10_7DF18_D_80070328),
                     (Level10_7DF18_D_8006C550 +
                      ((*((int*)(((unsigned char*)privateState) + 0x3C))) * 0x58)) +
                         0xC) < 0x1000)) {
                argument0 = *((int*)(((unsigned char*)privateState) + 0x40));
                if (argument0 != 0) {
                    Level10_7DF18DeleteMoby(argument0);
                    *((int*)(((unsigned char*)privateState) + 0x40)) = 0;
                }
                argument0 = owner;
                argument1 = 0;
                result = 2;
                Level10_7DF18Field(privateState, int*, 0x34) = 0;
                goto block_105;
            }
            goto block_117;

        case 4:
            scratch3 = *((unsigned char*)(((unsigned char*)owner) + 0x49));
            switch (scratch3) {
                case 1:
                    saved16 = *((short*)(((unsigned char*)(*(
                                             (int*)(((unsigned char*)privateState) + 0x30)))) +
                                         2));
                    if (Level10_7DF18_func_80035A80(
                            owner, *((int*)(((unsigned char*)privateState) + 0x30)), 0x200, 0x80, 0,
                            8, 0xC, 5) &
                        1) {
                        argument1 = *((int*)(((unsigned char*)privateState) + 0x30));
                        argument2 = *((short*)(((unsigned char*)argument1) + 2));
                        if (argument2 != 0) {
                            scratch3 = *((int*)(((unsigned char*)argument1) + 0xC));
                            if ((*((int*)(((unsigned char*)((saved16 * 0x10) + scratch3)) + 0xC))) &
                                1) {
                                *((int*)(((unsigned char*)privateState) + 0x34)) =
                                    Level10_7DF18_func_800365E4(
                                        owner + 0xC, scratch3 + (argument2 * 0x10), 0x80, -8, 0);
                                argument0 = owner;
                                argument1 = 5;
                                goto block_115;
                            }
                            goto block_116;
                        }
                        goto block_110;
                    }
                    goto block_116;

                case 2:
                    Level10_7DF18_func_80035DDC(owner, 0x80, 0, 0, 0);
                    result = Level10_7DF18CountTimerDown(privateState + 0x28, 4);
                    argument1 = 0;
                    if (result != 0) {
                        argument0 = owner;
                        goto block_104;
                    }
                    goto block_117;

                case 5:
                    *((int*)(((unsigned char*)((int)(&Level10_7DF18_D_80070328))) + 0x20C)) =
                        0x10000002;
                    if (Level10_7DF18_func_80035A80(
                            owner, *((int*)(((unsigned char*)privateState) + 0x30)), 0x200, 0x80, 0,
                            8, 0xC, (int)scratch3) &
                        1) {
                        argument1 = 0;
                        argument0 = owner;
                        result = 4;
                        Level10_7DF18Field(privateState, signed char*, 2) = result;
                    block_104:
                        result = 1;
                    block_105:
                        *((unsigned char*)(((unsigned char*)owner) + 0x49)) = result;

                        *((unsigned char*)(((unsigned char*)owner) + 0x48)) = 0U;
                        Level10_7DF18RequestMobyAnimation(argument0, argument1);
                        goto block_117;
                    }
                    goto block_117;
            }

            break;

        case 5:
            saved21 = *(
                (short*)(((unsigned char*)(*((int*)(((unsigned char*)privateState) + 0x30)))) + 2));
            temp_v0_7 = Level10_7DF18_func_80035A80(
                owner, *((int*)(((unsigned char*)privateState) + 0x30)), 0x200, 0x80, 0, 8, 0xC, 0);
            saved16 = (int)&originalFrame.sp50;
            argument0 = saved16;
            Level10_7DF18Keep(argument0);
            saved20 = owner + 0xC;
            argument2 = (*((int*)(((unsigned char*)privateState) + 0x34))) - 8;
            *((int*)(((unsigned char*)privateState) + 0x34)) = argument2;
            *((int*)(((unsigned char*)owner) + 0x14)) =
                (int)((*((int*)(((unsigned char*)owner) + 0x14))) + argument2);
            argument1 = saved20;
            Level10_7DF18CopyVector(argument0, argument1);
            originalFrame.sp58 += 0x200;
            if (Level10_7DF18_func_8001A358(saved16, 0x200) != 0) {
                *((unsigned char*)(((unsigned char*)owner) + 0x48)) = 4U;
                Level10_7DF18RequestMobyAnimation(owner, 4);
            }
            if (temp_v0_7 & 1) {
                argument1 = *((int*)(((unsigned char*)privateState) + 0x30));
                argument2 = *((short*)(((unsigned char*)argument1) + 2));
                if (argument2 == 0) {
                block_110:
                    if ((*((int*)(((unsigned char*)privateState) + 0x38))) != 0) {
                        Level10_7DF18_D_8006E160 = 0;
                    }

                block_112:
                    Level10_7DF18DeleteMoby(owner);

                    return;
                }
                scratch3 = *((int*)(((unsigned char*)argument1) + 0xC));
                if ((*((int*)(((unsigned char*)((saved21 * 0x10) + scratch3)) + 0xC))) & 1) {
                    *((int*)(((unsigned char*)privateState) + 0x34)) = Level10_7DF18_func_800365E4(
                        saved20, scratch3 + (argument2 * 0x10), 0x80, -8, 0);
                    argument0 = owner;
                    argument1 = 5;
                    *((signed char*)(((unsigned char*)owner) + 0x3D)) = 4;
                block_115:
                    result = 5;
                    Level10_7DF18Keep(result);
                    Level10_7DF18Field(owner, unsigned char*, 0x48) = result;
                    Level10_7DF18RequestMobyAnimation(argument0, argument1);
                }
                goto block_116;
            }
        block_116:
            *((int*)(((unsigned char*)((int)(&Level10_7DF18_D_80070328))) + 0x20C)) = 0x10000002;

            Level10_7DF18_func_800492DC(owner + 0xC);
            goto block_117;
    }

block_117:
    scratch3 = *((int*)(((unsigned char*)privateState) + 0x2C));

    if (((scratch3 >= 0) &&
         (((unsigned char)(*((unsigned char*)(((unsigned char*)owner) + 0x48)))) >= 4U)) &&
        (Level10_7DF18ApproximatePlanarDistance(
             owner + 0xC, (Level10_7DF18_D_8006C550 + (scratch3 * 0x58)) + 0xC) < 0x200)) {
        Level10_7DF18_SpawnParticle(2, 0xC,
                                    Level10_7DF18_D_8006C550 +
                                        ((*((int*)(((unsigned char*)privateState) + 0x2C))) * 0x58),
                                    5);
    }
    return;
}

#undef Level10_7DF18Field
#undef Level10_7DF18Keep
#undef Level10_7DF18Low


/**
 * MobyUpdate_486() - func_level_10_8007ED9C()
 * Balloon strings
 * https://decomp.me/scratch/2DEqI
 */
void func_level_10_8007ED9C(Moby* moby) {
    int angle;
    MobyTag_486* mobyTag;
    MobyTag_514* balloonTag;

    mobyTag = (MobyTag_486*)moby->mobyTag;
    if (mobyTag->unk0->state == 7) {
        balloonTag = (MobyTag_514*)D_8006C550[moby->linkedMoby].mobyTag;
        if (balloonTag->unk40 != 0) {
            balloonTag->unk40 = 0;
        }
        func_80055B18(moby);
        return;
    }

    angle = (mobyTag->unk4 + mobyTag->unk0->angle.yaw) & 0xFF;
    moby->angle.yaw = angle;
    moby->position.x = (D_80065920[angle] * 0xBB) >> 0xA;
    moby->position.y = (D_800658A0[angle] * 0xBB) >> 0xA;
    moby->position.z = 0x29A;
    func_8004F194(&moby->position, &moby->position, &mobyTag->unk0->position);
}

extern Moby* D_8006C550;
extern unsigned char D_80071570[];
void ChainWarp(int, int) __asm__("func_800584BC");
/* Rev0 0x8007EEBC..0x8007F0B8: 128 original words.
 * Linked indices, private offsets 44/12, byte gate and fresh reloads follow
 * retail. Producers and semantic interpretation remain unresolved.
 * AI generated; not yet human reviewed. See batch 2026-10-05-1594.
 */
void func_level_10_8007EEBC(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
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
            ChainWarp(6, 77);
        remove:
            func_80055B18(moby);
            break;
    }
}

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
void func_level_10_8007F0BC(Moby* arg0) {
    Vector3D sp10, sp20, sp30, sp40, sp50;
    int temp_v1_3, count;
    Vehicle546Tag* mobyTag = (Vehicle546Tag*)arg0->mobyTag;
    switch (arg0->state) {
        case 0:
            switch (arg0->substate) {
                case 0:
                    if (progressFlags.lvl20_WhirligigUsable)
                        goto deleteVehicle;
                    if (D_8006C73C != 0 && currentLevel != D_8006C73C &&
                        ((temp_v1_3 = D_8006C73C % 10, temp_v1_3 == 0) ||
                         (temp_v1_3 == 7 && D_8006C73C < 60))) {
                        arg0->position.z += 0xC00;
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &arg0->position);
                        camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        func_8004F178(&spyro.position, &arg0->position);
                        spyro.position.z += spyro.unk4a + 0x280;
                        func_80012BA8(&camera.unk170);
                        func_8004F178(&camera.unk184, &camera.unk60);
                        arg0->substate = 1;
                        arg0->state = 7;
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
                            func_80055B18(arg0);
                            return;
                        }
                        if (currentLevel != 10 || Vehicle546Table[lvlIdToIndex[17]] != 0) {
                            arg0->substate = 1;
                            arg0->state = 3;
                        } else {
                            arg0->substate = 2;
                            arg0->state = 1;
                            arg0->position.z += 0xC00;
                        }
                        func_80055D24(arg0, 2);
                        mobyTag->timer = 0;
                    }
                    break;
                case 1:
                    arg0->state = 3;
                    break;
                case 2:
                    arg0->position.z += 0xC00;
                    func_80055D24(arg0, 2);
                    mobyTag->timer = 0;
                    arg0->state = 1;
                    break;
            }
            func_8003B7B4(&arg0->substate, 1, &unsavedData);
            break;
        case 2:
            arg0->position.z -= 64;
            func_8004F178(&sp10, &arg0->position);
            sp10.z += 512;
            sp10.z = func_8001A358(&sp10, 512);
            if (sp10.z != 0) {
                arg0->position.z = sp10.z;
                arg0->state = 3;
                func_8003B7B4(&arg0->state, 1, &savedData);
                func_8003B7B4(&arg0->state, 1, &unsavedData);
                arg0->substate = 0;
            }
            func_80055D24(arg0, 2);
            break;
        case 3:
            if (spyro.m_StoodOnMoby == arg0) {
                arg0->state = 4;
                case 4:
                    if (spyro.m_StoodOnMoby != arg0) {
                        camera.unk168 = 0;
                        arg0->state = 3;
                    } else {
                        if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                            Vehicle506Global = 1;
                            func_8005663C();
                            arg0->state = 5;
                        }
                        func_8004F178(&camera.unk184, &arg0->position);
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &arg0->position);
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
                arg0->state = 6;
            } else {
                arg0->state = 8;
            }
            break;

    case 6:
            arg0->position.z = (int)(arg0->position.z + 0x40);
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x280;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &arg0->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
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
                        func_80054F94(D_80070104.loadLevel, arg0);
                    } else {
                        progressFlags.lvl63_BiancaStrikesBack = 1;
                        func_800584BC(6, 0x3F);
                    }
                }
            }
            func_80055D24(arg0, 2);
            break;

    case 7:
            arg0->position.z -= 0x40;
            spyro.unk17a = 0x10008000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x280;
            spyro.unk18.roll = arg0->angle.roll;
            spyro.unk18.pitch = arg0->angle.pitch;
            spyro.unk18.yaw = arg0->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            func_8004F178(&sp20, &arg0->position);
            sp20.z += 0x200;
            sp20.z = func_8001A358(&sp20, 0x200);
            if (sp20.z != 0) {
                arg0->position.z = sp20.z;
                func_80013B7C(0);
                arg0->state = 8;
            }
            func_80055D24(arg0, 2);
            break;

        case 8:
            sp30.x = D_80065920[arg0->angle.yaw];
            sp30.y = D_800658A0[arg0->angle.yaw];
            sp30.z = 0;
            func_8004F194(&sp30, &sp30, &arg0->position);
            if (ovlHeader.unk2c(&sp30) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp30, arg0->angle.yaw, 0);
                mobyTag->timer = 120;
                arg0->state = 9;
            }
            break;

        case 9:
            sp40.x = D_80065920[arg0->angle.yaw];
            sp40.y = D_800658A0[arg0->angle.yaw];
            sp40.z = 0;
            func_8004F194(&sp40, &sp40, &arg0->position);
            if (ovlHeader.unk2b(&sp40, arg0->angle.yaw, 0) != 0) {
                func_8004F178(&sp50, &spyro.position);
                sp50.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp50, spyro.bodyRotation.yaw);
                arg0->state = 3;
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
void func_level_10_8007F944(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3;
    Vehicle635Tag* mobyTag;

    mobyTag = (Vehicle635Tag*)arg0->mobyTag;
    switch (arg0->state) {

        case 0:
            switch (arg0->substate) {
                case 0:
                    if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                        func_80055B18(arg0);
                        return;
                    } else {
                        arg0->state = 1;
                        if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) &&
                            ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) ||
                             ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) &&
                            (arg0->mobyClass == D_8006C528) && D_8006C73C != 47) {
                            func_80034F80(arg0, 2);
                            arg0->position.z += 0xC00;
                            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                          &arg0->position);
                            camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                            camera.unk170.yaw = 0;
                            camera.unk170.pitch = 0;
                            spyro.unk17a = 0x1001A000;
                            spyro.unk20[1] = 0;
                            func_8004F178(&spyro.unk19, &arg0->position);
                            spyro.unk19.z += spyro.unk4a + 0x604;
                            spyro.unk18.roll = arg0->angle.roll;
                            spyro.unk18.pitch = arg0->angle.pitch;
                            spyro.unk18.yaw = arg0->angle.yaw;
                            func_80012BA8(&camera.unk170);
                            func_8004F178(&camera.unk184, &camera.unk60);
                            arg0->state = 8;
                        } else if (arg0->state == 0) {
                            arg0->state = 1;
                        }
                    }
                    break;

                default:
                    break;

                case 1:
                    func_80034F80(arg0, 2);
                    arg0->position.z += 0xF00;
                    func_80055D24(arg0, 2);
                    mobyTag->timer = 0;
                    arg0->state = 10;
                    break;
            }
            break;

        case 1:
            if (spyro.m_StoodOnMoby == arg0) {
                arg0->state = 2;
                case 2:
                    if (spyro.m_StoodOnMoby != arg0) {
                        camera.unk168 = 0;
                        arg0->state = 1;
                    } else {
                        if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                            Vehicle506Global = 1;
                            func_8005663C();
                            arg0->state = 3;
                        }
                        func_8004F178(&camera.unk184, &arg0->position);
                        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes,
                                      &arg0->position);
                        camera.unk170.yaw = 0;
                        camera.unk170.pitch = 0;
                        camera.unk168 = 0x11;
                    }
            }
            break;

        case 3:
            camera.unk168 = 0;
            if (D_80070104.loadLevel != 0) {
                func_80034F40(arg0, 1);
                spyro.unk17a = 0x10018000;
                func_8004F178(&spyro.unk19, &arg0->position);
                spyro.unk19.z += 0x400;
                {
                    int height = func_8001A358(&spyro.unk19, 0x800);
                    spyro.unk20[1] = 0;
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk19.z = height + spyro.unk4a;
                    spyro.unk18.yaw = arg0->angle.yaw;
                }
                arg0->state = 4;
            } else
                arg0->state = 6;
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
                spyro.unk18.yaw = arg0->angle.yaw;
            }
            if (D_8006C770 != 0) {
                func_80034F80(arg0, 2);
                spyro.unk17a |= 0x2000;
                if (Vehicle635Moby != 0) {
                    *((unsigned char*)Vehicle635Moby + 0x4C) = 0;
                    *((unsigned char*)Vehicle635Moby + 0x4D) = 0;
                }
                mobyTag->timer = 120;
                arg0->state = 5;
            }
            break;
        case 5:
            arg0->position.z = (int)(arg0->position.z + 0x40);
            spyro.unk17a = 0x1001A000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x604;
            spyro.unk18.roll = spyro.bodyRotation.roll;
            spyro.unk18.pitch = spyro.bodyRotation.pitch;
            spyro.unk18.yaw = spyro.bodyRotation.yaw;
            func_8004F178(&camera.unk184, &arg0->position);
            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
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
                        func_80054F94(D_80070104.loadLevel, arg0);
                    } else {
                        progressFlags.lvl67_AMonsterToEndAllMonsters = 1;
                        func_800584BC(6, 0x43);
                    }
                }
            }
            func_80055D24(arg0, 2);
            break;

        case 6:
            sp10.x = D_80065920[arg0->angle.yaw];
            sp10.y = D_800658A0[arg0->angle.yaw];
            sp10.z = 0;
            func_8004F194(&sp10, &sp10, &arg0->position);
            if (ovlHeader.unk2c(&sp10) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp10, arg0->angle.yaw, 0);
                arg0->state = 7;
            }
            break;

        case 7:
            sp20.x = D_80065920[arg0->angle.yaw];
            sp20.y = D_800658A0[arg0->angle.yaw];
            sp20.z = 0;
            func_8004F194(&sp20, &sp20, &arg0->position);
            if (ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0) != 0) {
                func_8004F178(&sp30, &spyro.position);
                sp30.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp30, spyro.bodyRotation.yaw);
                arg0->state = 1;
            }
            break;

        case 8:
            arg0->position.z -= 0x40;
            spyro.unk17a = 0x1001A000;
            spyro.unk20[1] = 0;
            func_8004F178(&spyro.unk19, &arg0->position);
            spyro.unk19.z += spyro.unk4a + 0x604;
            spyro.unk18.roll = arg0->angle.roll;
            spyro.unk18.pitch = arg0->angle.pitch;
            spyro.unk18.yaw = arg0->angle.yaw;
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            func_8004F178(&sp40, &arg0->position);
            arg0->position.z += 0x400;
            sp40.z += 0x200;
            sp40.z = func_8001A358(&sp40, 0x200);
            if (sp40.z != 0) {
                arg0->position.z = sp40.z;
                func_80034F40(arg0, 3);
                spyro.unk17a = 0x10018000;
                func_8004F178(&spyro.unk19, &arg0->position);
                spyro.unk19.z += 0xE00;
                {
                    int height = func_8001A358(&spyro.unk19, 0x800);
                    spyro.unk20[1] = 0;
                    spyro.unk18.roll = 0;
                    spyro.unk18.pitch = 0;
                    spyro.unk19.z = height + spyro.unk4a;
                    spyro.unk18.yaw = arg0->angle.yaw;
                }
                arg0->state = 9;
            } else {
                arg0->position.z -= 0x400;
            }
            func_80055D24(arg0, 2);
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
                spyro.unk18.yaw = arg0->angle.yaw;
            }
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            if (D_8006C770 != 0) {
                func_80034F80(arg0, 0);
                func_80013B7C(0);
                arg0->state = 6;
            }
            break;
    }
    func_80055D24(arg0, 1);
}

/* SCUS-94467 USA Rev 0, 0x80080330..0x800805A0, 156 instructions.
 * AI generated; not yet human reviewed. Substates 0/1/2 preserve the
 * original mask priority, tag word offsets, unsigned byte sample loads,
 * signed timer shift and two-byte stride. Child tag writes are halfwords;
 * all Moby stores retain their original widths and numeric constants.
 * Empty constraints preserve register lifetimes and argument scheduling;
 * none emit instructions. Tag/sample producers, helper meanings, units and
 * caller cadence remain unresolved. Evidence: original
 * level_10/moby/func_level_10_80080330.s; test: all linked words/full hashes.
 */
typedef struct {
    int timer;
    int roll;
    int pitch;
    int z;
    unsigned char* samples;
    Vector3D* fragments;
} Actor80330Tag;
extern unsigned char D_8006C7B4, D_80070300[];
extern int D_8006C58C, D_8006C648;
void func_80036A68(Moby*, int, int, int);
int func_8001A310(Vector3D*, int, int, Moby*);
void func_level_10_80080330(Moby* argument) {
    register Moby* moby __asm__("$18") = argument;
    register Actor80330Tag* tag __asm__("$17") = moby->mobyTag;
    register Moby* child __asm__("$16");
    register Moby* target __asm__("$4");

    switch (moby->substate) {
        case 0: {
            register int rejected __asm__("$2") = D_8006C7B4 & 16;
            MATCHING_KEEP2_CLOBBER(moby, rejected, "$4");
            target = moby;
            if (rejected)
                goto removeActor;
            if (D_80070300[D_8006C58C] & 16)
                goto removeActor;
        }
            moby->substate = 1;
            break;
        case 1: {
            register int flags __asm__("$4") = moby->damageFlags;
            MATCHING_KEEP(flags);
            if (flags & 0x80000) {
                func_8003BABC(moby, 0, 0);
                func_80036A68(moby, 1, 0, 0);
                moby->substate = 2;
            } else {
                register int damaged __asm__("$2") = flags & 0x20000;
                MATCHING_KEEP(damaged);
                if (damaged) {
                    if (!tag->timer) {
                        moby->damageFlags = 0;
                        tag->timer = 1;
                        tag->roll = moby->angle.roll;
                        tag->pitch = moby->angle.pitch;
                        tag->z = moby->position.z;
                    }
                }
            }
        }
            if (tag->timer) {
                tag->timer += D_8006C648;
                if (tag->timer < 64) {
                    moby->angle.roll = tag->samples[(tag->timer >> 1) * 2] + tag->roll;
                    moby->angle.pitch = tag->samples[(tag->timer >> 1) * 2 + 1] + tag->pitch;
                } else {
                    tag->timer = 0;
                    moby->angle.roll = tag->roll;
                    moby->angle.pitch = tag->pitch;
                }
            }
            break;
        case 2:
            moby->unknownCollision = 0;
            child = SpawnMoby(132, moby);
            MATCHING_KEEP(child);
            if (child) {
                register Vector3D* position __asm__("$4") = &child->position;
                register int limit __asm__("$5") = 2048;
                register int one __asm__("$6") = 1;
                MATCHING_KEEP3(position, limit, one);
                *(short*)child->mobyTag = 4;
                child->position.z += 512;
                child->position.z = func_8001A310(position, limit, one, moby);
                child->state = 1;
            }
            SpawnFragments(3, 559, moby, tag->fragments, 0, 256);
            {
                target = moby;
                MATCHING_KEEP(target);
                target->unknown3[0] = 0;
                target->lowDrawDistance = 0;
                target->drawn = 0;
            }
        removeActor:
            func_80055B18(target);
            break;
    }
}

extern ProgressFlags progressFlags;

extern int D_8006C598, D_8006C73C, D_8006C528, currentLevel;
extern short D_800658A0[256], D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
/* AI generated adaptation of upstream func_level_17_8007D19C; not human reviewed.
 * Original SCUS-94467 level10 800805A0 instruction route; units/cadence open. */
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
void func_level_10_800805A0(Moby* moby) {
    Vector3D vector1;
    Vector3D vector2;
    Vector3D vector3;
    Vector3D vector4;
    int remainder;
    Vehicle506Tag* mobyTag;

    mobyTag = (Vehicle506Tag*)moby->mobyTag;
    switch (moby->state) {

        case 0:
            switch (moby->substate) {
                case 0:
                    if (progressFlags.lvl30_RocketUsable ||
                        ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable)) {
                        func_80055B18(moby);
                        return;
                    } else {
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

/**
 * MobyUpdate_942() - func_level_10_80080D88() - MATCHING
 * Superfly deactivator
 * https://decomp.me/scratch/TSST1
 */
void func_level_10_80080D88(Moby* moby) {
    BoxTag* mobyTag;

    mobyTag = (BoxTag*)moby->mobyTag;
    if (func_80036220(&spyro.position, mobyTag, 0, 0)) {
        spyro.superflyTimer = 0;
    }
}

/**
 * MobyUpdate_983() - func_level_10_80080DC8() - MATCHING
 * 
 * https://decomp.me/scratch/Mln7L
 */
extern Moby* D_8006C550;
void func_level_10_80080DC8(Moby* moby) {
    int* tag = moby->mobyTag;
    if (D_8006C550[tag[6]].state & 0x80) {
        func_80055B18(moby);
    } else {
        register int* state __asm__("$4") = &spyro.movementState;
        MATCHING_KEEP(state);
        if ((unsigned int)(*state - 5) < 2 &&
            func_80036220((Vector3D*)((char*)state - 0x50), tag, 0, 0)) {
            spyro.unk17a = 0x10000080;
            spyro.unk20[1] = 0x12;
        }
    }
}

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
int A4973H21ED8_26() __asm__("func_80021ED8");
void func_level_10_80080E80(unsigned char* input) {
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
        A4973H21ED8_26(arg4, 252, 0);
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
void func_level_10_80081AA0(Moby* actor) {
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

/**
 * MobyUpdate_1023() - func_level_10_80081CAC()
 * Whirlwind
 * Uses an if statement rather than a switch statement
 * Haven't fully figured out the placement of the else statement yet, seems complicated
 * https://decomp.me/scratch/0cVy2
 * https://decomp.me/scratch/GQsha (newer)
 */
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
extern int DecodedProximityHold __asm__("D_80070328 + 0x1BC");
extern int DecodedProximityMode __asm__("D_80070328 + 0x23C");
/* SCUS-94467 USA Rev0 80081CAC..800821F4, 339 original words.
 * Reuses verified func_level_47_8007801C; Original player+1BC hold gating and request 0x10000080/mode7 transition.
 * Raw field widths, helper identities and fixed-point shifts remain retail.
 * Complete units, producer/helper semantics and caller cadence remain open.
 * Empty constraints retain compiler lifetimes and emit no instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1659.
 */
void func_level_10_80081CAC(Moby* argument) {
    Vector3D difference;
    int kind;
    register Moby* moby __asm__("$17") = argument;
    register DecodedProximityTag* tag __asm__("$18");
    register Vector3D* position __asm__("$19");
    register int two __asm__("$20");
    register int* disabledArgument __asm__("$5") = (int*)(DecodedProximityPlayer + 0x244);
    register int distance __asm__("$21");
    register Vector3D* playerPosition __asm__("$22");
    MATCHING_KEEP(moby);
    MATCHING_KEEP(disabledArgument);
    tag = moby->mobyTag;
    if (*disabledArgument) {
        if (moby->state)
            moby->state = 2;
        return;
    }
    two = 2;
    if (moby->state == two)
        moby->state = 1;
    playerPosition = (Vector3D*)((char*)disabledArgument - 0x244);
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
            if (DecodedProximityAnimation == 19 || distance > 0x2800)
                goto thirdSubstate;
            if (DecodedProximityHold)
                goto update;
            if (DecodedProximityZ - moby->position.z <= 0xC00)
                goto update;
        thirdSubstate:
            tag->timer = 60;
            moby->substate = 3;
            goto update;
        kindThreeFinished:
            if (DecodedProximityAnimation != 19 && func_800359A4(&tag->timer, 4)) {
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
            difference.z >= -0x3FF && difference.z < tag->verticalLimit) {
            if (DecodedProximityZ + 0xC00 < moby->position.z + tag->verticalLimit) {
                DecodedProximityRequest = 0x10000020;
                DecodedProximityOwner = moby;
                MATCHING_OBSERVE2(tag, distance);
            } else if (DecodedProximityHold) {
                DecodedProximityRequest = 0x10000080;
                DecodedProximityHold = 0;
                DecodedProximityMode = 7;
            }
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
void func_level_10_800821F8(void* input) {
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


/**
 * MobyUpdate_501() - func_level_10_8008334C() - MATCHING
 * Egg fragment
 * https://decomp.me/scratch/rqdZK
 */
void func_level_10_8008334C(Moby* moby) {
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
void func_level_10_8008336C(Moby* argument) {
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

typedef struct {
    unsigned char reserved00[0x18];
    int counter;
} DecodedVectorForceTag;
extern short D_800658A0[], D_80065920[];
void func_level_10_8008356C(Moby* moby) {
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
