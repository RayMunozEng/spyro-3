#include "matching.h"
#include "common.h"
#include "savepoint.h" // vehicles
#include "camera.h" // anything with the camera
#include "mobyutil.h"
#include "spyro.h"
#include "ovl_header.h"

#include "moby/mobytag.h"
#include "moby/moby260.h"

// change arg0 to pMoby
// #define LEVEL_ID 17

////////////////////////////////////////////////////////////////////////////////////
// Includes etc.

// Collision - unclear types
extern int func_8001A358(Vector3D*, int);

// Sound
extern int func_8003BABC(Moby*, int, char); // fPlayMobySound
extern void func_8003BE70(int); // fKillSound
extern int func_8003BFC0(Moby*, int);

// Stdutil
extern void func_8004E790(void*, int, int); // memset
extern void func_8004F178(Vector3D*, Vector3D*); // fSetVector
extern void func_8004F194(Vector3D*, Vector3D*, Vector3D*); // fAddVector

// Update
extern void func_80054F94(int, Moby*); // unclear types

// UpdateMobys
extern Moby* func_80055A7C(); // get first empty allocated moby
extern void func_80055B18(Moby*); // fDeleteMoby
extern void func_80055C24(Moby*);
extern void func_80055D24(Moby*, int); // fUpdateMobyCollision

// Warp
extern void func_800584BC(int, int); // fWarpToLevel

// Psyq
extern int rand(); // rand

// .data 80064f9c
extern Sparx sparx;
extern short D_800658A0[0x100]; // sin
extern short D_80065920[0x100]; // cos
extern unsigned char lvlIdToIndex[0x48]; // 80066fcc

// .sdata 8006c3b0
extern int D_8006C528;
extern Moby* mobyArrayPtr; // moby array ptr
extern int D_8006C598;
extern int currentLevel; // 8006C5BC
extern int D_8006C73C;
extern int D_8006C784; // lifeCount
extern unsigned char D_8006C7B4; // EggsCollectedSinceEnteredBitmask

// .bss 8006c7f8
extern Game game; // 8006E344

extern MobyTag_120 D_8006E394; // bss, some sort of shared moby tag?? used by Sparx

 // not sure what this does yet, haven't currently typed it
// there's also possibly more afterwards from 80070160 to 80070260, but this might be separate

extern unsigned char eggsCollectedArray[40]; // 80070300 EggsCollectedBitmaskArray
extern ProgressFlags progressFlags; // 80071570

////////////////////////////////////////////////////////////////////////////////////
// Common mobys

/**
 * MobyUpdate_16() - func_level_17_80074CF8()
 * Butterfly (16), Extra Life Butterfly (211)
 * This one looks fucking awful, very WIP
 * https://decomp.me/scratch/L5FpK
 */
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
void func_level_17_80074CF8(Moby* mobyArgument) {
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

/**
 * MobyUpdate_120() - func_level_17_80075384()
 * Sparx
 * TODO
 */
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
void func_level_17_80075384(void* input) {
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


/**
 * MobyUpdate_260() - func_level_17_800768D4() - MATCHING
 * Thought about implementing with a static inline, but it doesn't compile the same!!
 * This is a common one that can be added to other levels too (keeping the asm for now)
 * https://decomp.me/scratch/IJ8Wz
 */
void func_level_17_800768D4(Moby* arg0) {
// MOBY_UPDATE_FUNC(260)
// MOBY_UPDATE_FUNC(260, LEVEL_ID) {
    //MobyUpdate_260(moby);
    Vector3D sp10;
    int temp_v0_3;
    unsigned char temp_v0_5;
    unsigned char var_a0;
    Vector3D* temp_a0;
    Vector3D* temp_s1;
    MobyTag_260* mobyTag;

    mobyTag = (MobyTag_260*)arg0->mobyTag;
    if (arg0->substate == 0) {
        if (mobyTag->unk4 > 0) {
            arg0->angle.yaw++;
            mobyTag->unkC.z = mobyTag->unkC.z - 6;
            if (mobyTag->unkC.z < -0x80) {
                mobyTag->unkC.z = -0x80;
            }
            arg0->position.x += mobyTag->unkC.x;
            arg0->position.y += mobyTag->unkC.y;
            arg0->position.z += mobyTag->unkC.z;
            temp_s1 = &arg0->position;
            if (arg0->position.z >= 0x400) {
                func_8001A358(temp_s1, 0x2000);
                func_8005629C(arg0);
                if (func_80019194(temp_s1, 0x100) != 0) {
                    func_8004F178(temp_s1, &D_80071900.targetedPosition);
                    func_8004EF04(&D_80071900.D_80071918, 0x1000);
                    temp_v0_3 = DOTPRODUCT(mobyTag->unkC, D_80071900.D_80071918) >> 0xB;
                    if (temp_v0_3 < 0) {
                        func_8004F08C(&D_80071900.D_80071918, 0x1000, -temp_v0_3);
                        func_8004F194(&mobyTag->unkC, &mobyTag->unkC, &D_80071900.D_80071918);
                    }
                }
                mobyTag->unk4--;
                return;
            }
            func_80055B18(arg0);
            return;
        }
        ovlHeader.SpawnParticle(0xA, 0x47, &arg0->position, 0);
        func_80055B18(arg0);
        return;
    }
    if (mobyTag->unk0->state != 0) {
        func_80055B18(arg0);
        return;
    }

    var_a0 = func_8004E880(camera.nextCameraPosCartesian.x - arg0->position.x, camera.nextCameraPosCartesian.y - arg0->position.y, 0);
    arg0->angle.yaw = (D_800658A0[(unsigned char)(D_8006C644 * 4)] >> 0x7) + (unsigned char)(var_a0 + 0x80);
    if (arg0->substate == 2) {
        var_a0 += 0x80;
    }

    sp10.x = 0;
    sp10.y = 0;
    if (arg0->substate != 3) {
        sp10.x =  D_800658A0[var_a0] / 28;
        sp10.y = -D_80065920[var_a0] / 28;
    }
    sp10.z = 0x520;
    func_8004F194(&arg0->position, &mobyTag->unk0->position, &sp10);
}

/**
 * MobyUpdate_272() - func_level_17_80076BD8()
 * 
 * Zoe
 */
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
void func_level_17_80076BD8(void* input) {
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


////////////////////////////////////////////////////////////////////////////////////
// Level 17 mobys

/**
 * MobyUpdate_401() - func_level_17_8007774C()
 * Buzz
 * Still very WIP but decent progress has been made
 * Contains A LOT of stuff for putting into contexts
 * https://decomp.me/scratch/w7teg
 * https://decomp.me/scratch/Bftil (newer)
 * https://decomp.me/scratch/ytT0h (newest)
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, func_level_17_8007774C (level17 class401).
 * AI generated; not human reviewed.
 * Original byte/halfword/word loads, shared state entries and both selector
 * tables are preserved. Saved words change roles only at actual original
 * producers. No incoming saved-register value is treated as a C input.
 * Every multiply produces an initialized signed64 value before its original
 * high/low projection. The signed division retains the original zero and
 * INT_MIN/-1 traps. No CPU instruction is supplied by an asm template.
 * Empty matching templates preserve complete initialized words/products;
 * dead-register boundaries occur before their fresh original definitions.
 * The two do-once lexical regions preserve ordinary frame-address lifetimes
 * across the particle loop; neither adds a reachable backedge or game state.
 * The frame represents the original312-byte o32 reservation. Outgoing
 * argument words use ordinary C calls, without writing their ABI homes.
 * Four-byte int values carry original pointer words. Literal resident bases
 * and pointer casts target this fixed-USA32-bit MIPS build, not portable C.
 * Native/control/data/selector/producer/numeric gates accompany this source.
 */
#define Level17_7774CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level17_7774CKeep(v) __asm__("" : "=r"(v) : "0"(v))
void Level17_7774CSetCameraOwnerAndControlWord(int, int) __asm__("func_80013ACC");
void Level17_7774CPrepareCameraMode9Vectors(int, int) __asm__("func_80013AE4");
void Level17_7774CSetCameraMode11Target(int, int, int, int) __asm__("func_80013D44");
int Level17_7774CQueryWorldHeight(int, int) __asm__("func_8001A358");
int Level17_7774CConfigureHudEntry(int, int, int, int, int, int, int) __asm__("func_8002803C");
int Level17_7774CResetHudEntryByHandle(int) __asm__("func_80028154");
void Level17_7774CRequestMobyAnimation(int, int) __asm__("func_80034F40");
int Level17_7774CUpdateMobyMotionDescriptor(int, int) __asm__("func_80035194");
void Level17_7774CEmptyAnimationTransitionHook(int) __asm__("func_80035734");
int Level17_7774CTurnMobyTowardPlayer(int, int, int, int) __asm__("func_8003573C");
int Level17_7774CTurnMobyTowardHeading(int, int, int, int, int, int) __asm__("func_8003585C");
int Level17_7774CCountTimerDown(int, int) __asm__("func_800359A4");
int Level17_7774CResolveMobyYawStep(int, int, int, int, int) __asm__("func_80035DDC");
void Level17_7774CResolveMobyHeadingStep(int, int, int, int, int, int) __asm__("func_80035EE0");
int Level17_7774CSubAngle8(int, int) __asm__("func_8003613C");
int Level17_7774CSubAngle12(int, int) __asm__("func_8003615C");
int Level17_7774CRandBetween(int, int) __asm__("func_8003636C");
int Level17_7774CRandSignedBetween(int, int) __asm__("func_800363DC");
void Level17_7774CInitializeMobyMotionState(int, int, int, int) __asm__("func_80038BF8");
void Level17_7774CRegisterTrackedValue(int, int, int) __asm__("func_8003B7B4");
int Level17_7774CPlayMobySoundEvent(int, int, int) __asm__("func_8003BABC");
int Level17_7774CPlaySoundFromGlobalByteTable(int, int, int) __asm__("func_8003BB10");
void Level17_7774CTransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
int Level17_7774CSoundHandleMatchesOwnerInStates1Or2(int, int) __asm__("func_8003BFC0");
void Level17_7774CSetClampedPlayerTargetAngles(int) __asm__("func_800492DC");
int Level17_7774CPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Level17_7774CMeasureVectorLength(int, int) __asm__("func_8004EDE8");
void Level17_7774CCopyVector(int, int) __asm__("func_8004F178");
void Level17_7774CSubtractVector(int, int, int) __asm__("func_8004F1C8");
int Level17_7774CAbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Level17_7774CApproximatePlanarDistance(int, int) __asm__("func_8004F334");
void Level17_7774CDeleteMoby(int) __asm__("func_80055B18");
void Level17_7774CRefreshMobySpatialGridAndBasis(int, int) __asm__("func_80055D24");
int Level17_7774CReadSelectedFrameScalar(int) __asm__("func_80055E84");
int Level17_7774C_rand(void) __asm__("rand");
extern int Level17_7774C_D_800658A0 __asm__("D_800658A0");
extern int Level17_7774C_D_80065920 __asm__("D_80065920");
extern unsigned char Level17_7774C_D_8006C408 __asm__("D_8006C408");
extern int Level17_7774C_D_8006C550 __asm__("D_8006C550");
extern int Level17_7774C_D_8006C58C __asm__("D_8006C58C");
extern int Level17_7774C_D_8006C648 __asm__("D_8006C648");
extern int Level17_7774C_D_8006C770 __asm__("D_8006C770");
extern int Level17_7774C_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level17_7774C_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level17_7774C_D_8006D088 __asm__("D_8006D088");
extern int Level17_7774C_D_8006E020 __asm__("D_8006E020");
extern int Level17_7774C_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level17_7774C_D_8006E040 __asm__("D_8006E040");
extern int Level17_7774C_D_8006E048 __asm__("D_8006E048");
extern int Level17_7774C_D_8006E788 __asm__("D_8006E788");
extern int Level17_7774C_D_8006EE2C __asm__("D_8006EE2C");
extern int Level17_7774C_D_80070328 __asm__("D_80070328");
extern unsigned char Level17_7774C_D_8007158C __asm__("D_8007158C");
extern int Level17_7774C_D_level_17_80083EEC __asm__("D_level_17_80083EEC");
extern int (*Level17_7774C_SpawnMoby)(int, int) __asm__("SpawnMoby");
extern int (*Level17_7774C_SpawnParticle)(int, int, int, int) __asm__("SpawnParticle");
extern int Level17_7774C_func_level_17_80074CF8 __asm__("func_level_17_80074CF8");
extern int Level17_7774C_main_TEXT_END __asm__("main_TEXT_END");
extern int Level17_7774C_main_TEXT_START __asm__("main_TEXT_START");
extern int Level17_7774C_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level17_7774C_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level17_7774C_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
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
} Level17_7774CProduct;
extern int Level17_7774CResident_D_80070328_540_int __asm__("D_80070328+540");
extern int Level17_7774CResident_D_80070328_544_int __asm__("D_80070328+544");
void func_level_17_8007774C(void* input) {
    register int workWord2 __asm__("$2");
    register int workWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register int argumentWord7 __asm__("$7");
    register int workWord8 __asm__("$8");
    register int workWord9 __asm__("$9");
    register int workWord10 __asm__("$10");
    register int workWord11 __asm__("$11");
    register int workWord12 __asm__("$12");
    register int workWord13 __asm__("$13");
    register int workWord14 __asm__("$14");
    register int workWord15 __asm__("$15");
    register int savedWord16 __asm__("$16");
    register int savedWord17 __asm__("$17");
    register int savedWord18 __asm__("$18");
    register int privateAddress19 __asm__("$19");
    register int savedWord20 __asm__("$20");
    register int ownerAddress21 __asm__("$21");
    register int savedWord22 __asm__("$22");
    register int savedWord23 __asm__("$23");
    register int workWord24 __asm__("$24");
    register int workWord25 __asm__("$25");
    int retainedPointer30, fifthArgument, sixthArgument, seventhArgument;
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
    } originalFrame;
    Level17_7774CProduct productAt333, productAt355, productAt359, productAt371, productAt384,
        productAt559, productAt569, productAt738, productAt749, productAt817, productAt831,
        productAt1041, productAt2089, productAt2099, productAt2443, productAt2454, productAt2550,
        productAt2560, productAt2590, productAt2600;
    ownerAddress21 = (int)input;
    Level17_7774CKeep(ownerAddress21);
    argumentWord4 = (int)input;
    privateAddress19 = Level17_7774CField(ownerAddress21, int*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    Level17_7774CField(&originalFrame.sp20, int*, 144) = 0;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord2, int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 4);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = (int)0x80070000U;
    Level17_7774CKeep(workWord10);
    workWord10 = Level17_7774CField(workWord10, unsigned char*, -15352);
    __asm__ volatile("" ::: "$3", "memory");
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, -14396);
    Level17_7774CField(&originalFrame.sp20, int*, 152) = workWord2;
    Level17_7774CKeep(workWord10);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    Level17_7774CField(&originalFrame.sp20, int*, 192) = workWord10;
    if (workWord3 != workWord2)
        goto original_800777E4;
    workWord10 = workWord10 + -4;
    Level17_7774CField(&originalFrame.sp20, int*, 192) = workWord10;
    if (workWord10 >= 0)
        goto original_80077814;
    Level17_7774CField(&originalFrame.sp20, int*, 192) = 0;
    goto original_80077814;
original_800777E4:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    if (workWord3 != workWord2)
        goto original_800777FC;
    MATCHING_BARRIER_VOLATILE("memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    workWord10 = workWord10 + 2;
    goto original_80077810;
original_800777FC:
    if (workWord3 != 0)
        goto original_80077814;
    MATCHING_BARRIER_VOLATILE("memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    workWord10 = workWord10 + 5;
original_80077810:
    Level17_7774CField(&originalFrame.sp20, int*, 192) = workWord10;
original_80077814:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, unsigned char*, 5516);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp20;
    if (workWord2 == 0)
        goto original_8007782C;
    Level17_7774CField(&originalFrame.sp20, int*, 192) = 0;
original_8007782C:
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = (int)&Level17_7774C_D_80070328;
    Level17_7774CKeep(savedWord16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord16 + 0;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = ownerAddress21 + 12;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord17 + 0;
    Level17_7774CSubtractVector(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp20;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    workWord2 = Level17_7774CMeasureVectorLength(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp20;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = Level17_7774CField(workWord3, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord16 + 0;
    Level17_7774CField(&originalFrame.sp20, int*, 168) = workWord2;
    Level17_7774CSubtractVector(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp20;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    workWord2 = Level17_7774CMeasureVectorLength(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp20;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = Level17_7774CField(workWord3, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord17 + 0;
    Level17_7774CField(&originalFrame.sp20, int*, 176) = workWord2;
    Level17_7774CSubtractVector(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp20;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    workWord2 = Level17_7774CMeasureVectorLength(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 888);
    workWord3 = workWord3 + -7;
    workWord3 = (unsigned int)workWord3 < 2;
    Level17_7774CField(&originalFrame.sp20, int*, 184) = workWord2;
    if (workWord3 == 0)
        goto original_800778B8;
    Level17_7774CField(privateAddress19, short*, 58) = 0;
original_800778B8:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 44);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80077948;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 13;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    Level17_7774CField(privateAddress19, short*, 106) = workWord2;
    MATCHING_BARRIER_VOLATILE("memory");
    argumentWord6 = Level17_7774CField(privateAddress19, short*, 106);
    MATCHING_BARRIER_VOLATILE("memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 106);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(privateAddress19, int*, 44) = workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(privateAddress19, int*, 48) = argumentWord6;
    Level17_7774CField(privateAddress19, int*, 52) = workWord2;
    Level17_7774CSetCameraOwnerAndControlWord(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 168);
    if (workWord2 >= 0)
        goto original_80077948;
    workWord2 = Level17_7774CConfigureHudEntry(
        23, 170, Level17_7774C_unk_ovlheader_80074368, Level17_7774C_unk_ovlheader_8007436C,
        Level17_7774C_unk_ovlheader_80074364, privateAddress19 + 52,
        Level17_7774CField(privateAddress19, int*, 52));
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    Level17_7774CField(privateAddress19, int*, 168) = workWord2;
original_80077948:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 66);
    if (workWord2 != 0)
        goto original_800779B0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 24);
    if (workWord2 != 0)
        goto original_8007797C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 888);
    if (workWord2 == 0)
        goto originalReturn;
original_8007797C:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 1384);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto originalReturn;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 13;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 30;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(privateAddress19, short*, 66) = workWord2;
    Level17_7774CSetCameraOwnerAndControlWord(argumentWord4, argumentWord5);
    goto originalReturn;
original_800779B0:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 220);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)&Level17_7774C_func_level_17_80074CF8;
    Level17_7774CKeep(workWord3);
    workWord2 = (unsigned int)workWord2 < (unsigned int)workWord3;
    savedWord16 = privateAddress19 + 220;
    if (workWord2 != 0)
        goto original_80077A48;
    Level17_7774CKeep(workWord2);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = (int)&Level17_7774C_D_level_17_80083EEC;
    Level17_7774CKeep(argumentWord6);
original_800779D4:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 220);
    workWord2 = (unsigned int)workWord3 < (unsigned int)argumentWord6;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    if (workWord2 == 0)
        goto original_80077A44;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, unsigned char*, 0);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 216);
    workWord2 = (int)((unsigned int)workWord2 << 8);
    workWord3 = workWord3 ^ workWord2;
    Level17_7774CField(privateAddress19, int*, 216) = workWord3;
original_800779FC:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, volatile int*, 216);
    workWord2 = workWord3 & 32768;
    if (workWord2) {
        workWord2 = (unsigned int)workWord3 << 1;
        workWord2 ^= 32773;
    } else
        workWord2 = (unsigned int)workWord3 << 1;
original_80077A14:
    Level17_7774CField(privateAddress19, int*, 216) = workWord2;
    argumentWord4 = argumentWord4 + 1;
    workWord2 = argumentWord4 < 8;
    if (workWord2 != 0)
        goto original_800779FC;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 220);
    argumentWord5 = argumentWord5 + 1;
    workWord2 = workWord2 + 1;
    Level17_7774CField(privateAddress19, int*, 220) = workWord2;
    workWord2 = argumentWord5 < 64;
    if (workWord2 != 0)
        goto original_800779D4;
original_80077A44:
    savedWord16 = privateAddress19 + 220;
original_80077A48:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile(""
                     : "=r"(argumentWord4), "=r"(argumentWord5)
                     : "0"(argumentWord4), "1"(argumentWord5)
                     : "$6", "$18", "memory");
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = (int)&Level17_7774C_D_8006D088;
    Level17_7774CKeep(savedWord18);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord18 + 0;
    Level17_7774CRegisterTrackedValue(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile(""
                     : "=r"(argumentWord4), "=r"(argumentWord5)
                     : "0"(argumentWord4), "1"(argumentWord5)
                     : "$6", "$17", "memory");
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = (int)&Level17_7774C_D_8006C7F8;
    Level17_7774CKeep(savedWord17);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord17 + 0;
    Level17_7774CRegisterTrackedValue(argumentWord4, argumentWord5, argumentWord6);
    savedWord16 = privateAddress19 + 216;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile(""
                     : "=r"(argumentWord4), "=r"(argumentWord5)
                     : "0"(argumentWord4), "1"(argumentWord5)
                     : "$6", "memory");
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord18 + 0;
    Level17_7774CRegisterTrackedValue(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile(""
                     : "=r"(argumentWord4), "=r"(argumentWord5)
                     : "0"(argumentWord4), "1"(argumentWord5)
                     : "$6", "memory");
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord17 + 0;
    Level17_7774CRegisterTrackedValue(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 24);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x00020000U;
    Level17_7774CKeep(workWord3);
    workWord2 = workWord2 & workWord3;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_80077DCC;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = (int)&Level17_7774C_D_80070328;
    Level17_7774CKeep(savedWord16);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(savedWord16, int*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(savedWord16, int*, 4);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, unsigned char*, 822);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 48;
    if (workWord2 == 0)
        goto original_80077DCC;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
    Level17_7774CKeep(argumentWord4);
    workWord2 = argumentWord4 + -6;
    workWord2 = (unsigned int)workWord2 < 2;
    workWord3 = argumentWord4 & 255;
    if (workWord2 != 0)
        goto original_80077DCC;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 16;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 50, 1) : (workWord2 = 0 + 50, 0))
        goto original_80077DCC;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 12, 1) : (workWord2 = 0 + 12, 0))
        goto original_80077DCC;
    if (workWord3 == workWord2 ? (workWord2 = argumentWord4 + -8, 1)
                               : (workWord2 = argumentWord4 + -8, 0))
        goto original_80077DCC;
    workWord2 = (unsigned int)workWord2 < 2;
    if (workWord2 != 0 ? (workWord2 = 0 + 30, 1) : (workWord2 = 0 + 30, 0))
        goto original_80077DCC;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_80077DCC;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    workWord2 = workWord3 ^ 1;
    Level17_7774CKeep(workWord2);
    savedWord17 = (unsigned int)workWord2 < 1;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_80077B60;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
original_80077B60:
    argumentWord5 = privateAddress19 + 12;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 6;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    Level17_7774CField(privateAddress19, short*, 160) = 0;
    Level17_7774CInitializeMobyMotionState(argumentWord4, argumentWord5, argumentWord6,
                                           argumentWord7);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, short*, 54);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 6;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_8006EE2C + workWord2), int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 84);
    workWord2 = Level17_7774CField(workWord2, unsigned char*, 0);
    Level17_7774CField(ownerAddress21, unsigned char*, 60) = workWord3;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 62) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = workWord3;
    workWord2 = (unsigned int)workWord2 < 2;
    workWord2 = workWord2 ^ 1;
    workWord2 = 0 - workWord2;
    workWord2 = workWord2 & 48;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 300;
    Level17_7774CField(privateAddress19, short*, 16) = workWord2;
    if (savedWord17 == 0)
        goto original_80077C44;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 62);
    workWord2 = workWord2 < 251;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 != 0)
        goto original_80077C44;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(savedWord16, int*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord16, int*, 4);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 24;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = 0 + 1;
    if (workWord2 == 0)
        goto original_80077C44;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, unsigned short*, 16);
    Level17_7774CField(&originalFrame.sp20, int*, 144) = workWord10;
    workWord3 = (int)((unsigned int)workWord3 << 16);
    workWord2 = (workWord3 >> 16);
    workWord3 = (int)((unsigned int)workWord3 >> 31);
    workWord2 = workWord2 + workWord3;
    workWord2 = (workWord2 >> 1);
    Level17_7774CField(privateAddress19, short*, 16) = workWord2;
original_80077C44:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    workWord2 = workWord10 < 6;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = 0 + 0;
    if (workWord2 != 0)
        goto original_80077C94;
    Level17_7774CKeep(savedWord17);
    workWord3 = workWord10 + -5;
    workWord2 = workWord3 < 6;
    if (workWord2 != 0 ? (workWord2 = (int)((unsigned int)workWord3 << 4), 1)
                       : (workWord2 = (int)((unsigned int)workWord3 << 4), 0))
        goto original_80077C70;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 5;
    Level17_7774CKeep(workWord3);
    workWord2 = (int)((unsigned int)workWord3 << 4);
original_80077C70:
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 16);
    MATCHING_KEEP_VOLATILE_CLOBBER(workWord2, "memory");
    workWord2 = workWord2 + 256;
    Level17_7774CKeep(workWord3);
    Level17_7774CKeep(workWord2);
    productAt333.full = (long long)workWord3 * (long long)workWord2;
    __asm__("" : "=x"(productAt333.full) : "0"(productAt333.full));
    workWord10 = (int)productAt333.words.low;
    Level17_7774CKeep(workWord10);
    workWord2 = (workWord10 >> 8);
    Level17_7774CField(privateAddress19, short*, 16) = workWord2;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = 0 + 0;
original_80077C94:
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = (int)&originalFrame.sp30;
original_80077C98:
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = Level17_7774CField(privateAddress19, short*, 16);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned char*, 26);
    argumentWord4 = savedWord16 / workWord2;
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(workWord2);
    productAt355.full = (long long)workWord2 * (long long)workWord2;
    __asm__("" : "=x"(productAt355.full) : "0"(productAt355.full));
    workWord3 = (int)productAt355.words.low;
    Level17_7774CKeep(workWord3);
    savedWord16 = savedWord16 - workWord3;
    Level17_7774CKeep(savedWord16);
    Level17_7774CKeep(argumentWord4);
    productAt359.full = (long long)savedWord16 * (long long)argumentWord4;
    __asm__("" : "=x"(productAt359.full) : "0"(productAt359.full));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = ownerAddress21 + 12;
    savedWord16 = (int)productAt359.words.low;
    Level17_7774CKeep(savedWord16);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord18 + 0;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned char*, 29);
    workWord2 = (int)((unsigned int)workWord2 << 1);
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(savedWord16);
    productAt371.full = (long long)workWord2 * (long long)savedWord16;
    __asm__("" : "=x"(productAt371.full) : "0"(productAt371.full));
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 16);
    __asm__ volatile(""
                     : "=x"(productAt371.full)
                     : "0"(productAt371.full), "m"(originalFrame.sp30)
                     : "memory");
    workWord3 = (int)productAt371.words.low;
    Level17_7774CKeep(workWord3);
    workWord3 = (workWord3 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 16) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned char*, 29);
    workWord2 = (int)((unsigned int)workWord2 << 1);
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(savedWord16);
    productAt384.full = (long long)workWord2 * (long long)savedWord16;
    __asm__("" : "=x"(productAt384.full) : "0"(productAt384.full));
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 20);
    __asm__ volatile(""
                     : "=x"(productAt384.full)
                     : "0"(productAt384.full), "m"(originalFrame.sp34)
                     : "memory");
    workWord3 = (int)productAt384.words.low;
    Level17_7774CKeep(workWord3);
    workWord3 = (workWord3 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 20) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord18 + 0;
    workWord2 = Level17_7774CApproximatePlanarDistance(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 13824;
    workWord3 = workWord3 - workWord2;
    workWord2 = workWord3 + 5500;
    workWord2 = (unsigned int)workWord2 < 7001;
    if (workWord2 != 0)
        goto original_80077D98;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = 0 + 1;
    goto original_80077DA8;
original_80077D98:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 16);
    workWord2 = workWord2 + 30;
    Level17_7774CField(privateAddress19, short*, 16) = workWord2;
original_80077DA8:
    if (savedWord17 == 0)
        goto original_80077C94;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    if (workWord3 >= 0)
        goto original_80077DC0;
    Level17_7774CField(privateAddress19, short*, 182) = workWord2;
    goto original_80077DC4;
original_80077DC0:
    Level17_7774CField(privateAddress19, short*, 182) = 0;
original_80077DC4:
    if (savedWord17 == 0)
        goto original_80077C98;
original_80077DCC:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 220);
    if (workWord2 != 0)
        goto original_80077DF8;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, volatile int*, -14964);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)&Level17_7774C_main_TEXT_START + 2;
    Level17_7774CKeep(workWord3);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(privateAddress19, int*, 220) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 220);
original_80077DF8:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)&Level17_7774C_main_TEXT_END;
    Level17_7774CKeep(workWord3);
    workWord2 = (unsigned int)workWord2 < (unsigned int)workWord3;
    if (workWord2 == 0)
        goto original_80077EAC;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = workWord3 + 0;
original_80077E14:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 220);
    workWord2 = (unsigned int)workWord3 < (unsigned int)argumentWord6;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    if (workWord2 == 0)
        goto original_80077EA0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, unsigned char*, 0);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 216);
    workWord2 = (int)((unsigned int)workWord2 << 8);
    workWord3 = workWord3 ^ workWord2;
    Level17_7774CField(privateAddress19, int*, 216) = workWord3;
original_80077E3C:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, volatile int*, 216);
    workWord2 = workWord3 & 32768;
    if (workWord2) {
        workWord2 = (unsigned int)workWord3 << 1;
        workWord2 ^= 32773;
    } else
        workWord2 = (unsigned int)workWord3 << 1;
original_80077E54:
    Level17_7774CField(privateAddress19, int*, 216) = workWord2;
    argumentWord4 = argumentWord4 + 1;
    workWord2 = argumentWord4 < 8;
    if (workWord2 != 0)
        goto original_80077E3C;
    argumentWord5 = argumentWord5 + 1;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 216);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 220);
    workWord2 = workWord2 & 3;
    workWord2 = workWord2 + 1;
    workWord3 = workWord3 + workWord2;
    workWord2 = argumentWord5 < 64;
    Level17_7774CField(privateAddress19, int*, 220) = workWord3;
    if (workWord2 != 0)
        goto original_80077E14;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)&Level17_7774C_main_TEXT_END;
    Level17_7774CKeep(workWord2);
    workWord2 = (unsigned int)workWord3 < (unsigned int)workWord2;
    if (workWord2 != 0)
        goto original_80077EAC;
original_80077EA0:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)&Level17_7774C_func_level_17_80074CF8;
    Level17_7774CKeep(workWord2);
    Level17_7774CField(privateAddress19, int*, 220) = workWord2;
original_80077EAC:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    workWord3 = workWord10 < 7;
    argumentWord5 = 0 < workWord10;
    if (workWord3 != 0)
        goto original_80077EC4;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
original_80077EC4:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 1448);
    workWord2 = workWord2 < 2;
    if (workWord2 != 0)
        goto original_80077EE4;
    if (workWord3 != 0)
        goto original_80077F08;
original_80077EE4:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 220);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)&Level17_7774C_D_level_17_80083EEC;
    Level17_7774CKeep(workWord2);
    if (workWord3 != workWord2)
        goto original_80077F0C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 216);
    if (workWord2 == 0)
        goto original_80077F0C;
original_80077F08:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
original_80077F0C:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)&Level17_7774C_D_8006E788;
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, int*, 0);
    workWord3 = workWord3 + 4;
    if (workWord2 == 0)
        goto original_80077F68;
    __asm__ volatile("" ::: "$8", "memory");
    workWord8 = 0 + 543;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 16;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 211;
original_80077F30:
    workWord2 = Level17_7774CField(workWord2, short*, 54);
    if (workWord2 != workWord8)
        goto original_80077F44;
    argumentWord4 = argumentWord4 + 1;
original_80077F44:
    if (workWord2 == argumentWord7)
        goto original_80077F54;
    if (workWord2 != argumentWord6)
        goto original_80077F58;
original_80077F54:
    argumentWord4 = argumentWord4 + 1;
original_80077F58:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, int*, 0);
    workWord3 = workWord3 + 4;
    if (workWord2 != 0)
        goto original_80077F30;
original_80077F68:
    workWord2 = argumentWord4 < argumentWord5;
    argumentWord4 = privateAddress19 + 172;
    if (workWord2 == 0)
        goto original_800780DC;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 543;
    if (workWord2 == 0)
        goto original_800780DC;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 17120);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = ownerAddress21 + 0;
    workWord2 = ((int (*)(int, int))workWord2)(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$20", "memory");
    savedWord20 = workWord2 + 0;
    Level17_7774CKeep(savedWord20);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1200;
    if (savedWord20 == 0)
        goto original_800780D0;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = Level17_7774CField(savedWord20, int*, 0);
    workWord2 = Level17_7774C_rand();
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 500;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 1500;
    MATCHING_KEEP2_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = workWord2 + 0;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    MATCHING_KEEP2_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "memory");
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = workWord2 + 0;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    argumentWord4 = savedWord20 + 12;
    Level17_7774CField(savedWord17, unsigned char*, 23) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 176);
    MATCHING_KEEP_VOLATILE_CLOBBER(workWord2, "memory");
    workWord2 = workWord2 & 255;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord3, int*, 12);
    workWord2 = (int)((unsigned int)workWord2 << 4);
    argumentWord5 = argumentWord5 + workWord2;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    savedWord16 = savedWord16 & 255;
    savedWord16 = (int)((unsigned int)savedWord16 << 1);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + savedWord16), short*, 0);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(savedWord18);
    productAt559.full = (long long)workWord2 * (long long)savedWord18;
    __asm__("" : "=x"(productAt559.full) : "0"(productAt559.full));
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord20, int*, 12);
    __asm__ volatile("" : "=x"(productAt559.full) : "0"(productAt559.full) : "memory");
    workWord10 = (int)productAt559.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(savedWord20, int*, 12) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + savedWord16), short*, 0);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(savedWord18);
    productAt569.full = (long long)workWord2 * (long long)savedWord18;
    __asm__("" : "=x"(productAt569.full) : "0"(productAt569.full));
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord20, int*, 20);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 255;
    Level17_7774CField(savedWord20, unsigned char*, 74) = workWord3;
    workWord2 = workWord2 + 9000;
    Level17_7774CField(savedWord20, int*, 20) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 256;
    Level17_7774CField(savedWord20, short*, 56) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord20, int*, 16);
    __asm__ volatile("" : "=x"(productAt569.full) : "0"(productAt569.full) : "memory");
    workWord10 = (int)productAt569.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(savedWord20, int*, 16) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 176);
    Level17_7774CField(savedWord17, int*, 8) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 4;
    workWord2 = Level17_7774CField(workWord2, int*, 8);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 12;
    Level17_7774CField(savedWord17, int*, 16) = workWord2;
    workWord2 = Level17_7774CRandSignedBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 4;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 12;
    Level17_7774CField(savedWord17, unsigned char*, 20) = workWord2;
    workWord2 = Level17_7774CRandSignedBetween(argumentWord4, argumentWord5);
    Level17_7774CField(savedWord17, unsigned char*, 21) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    Level17_7774CField(savedWord17, unsigned char*, 13) = workWord2;
    Level17_7774CField(savedWord20, unsigned char*, 72) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord20, int*, 28);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80000000U;
    Level17_7774CKeep(workWord3);
    Level17_7774CField(savedWord20, unsigned char*, 65) = 0;
    Level17_7774CField(savedWord20, unsigned char*, 76) = 0;
    Level17_7774CField(savedWord20, unsigned char*, 77) = 0;
    workWord2 = workWord2 | workWord3;
    Level17_7774CField(savedWord20, int*, 28) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1200;
original_800780D0:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 1500;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    Level17_7774CField(privateAddress19, int*, 172) = workWord2;
original_800780DC:
    argumentWord4 = privateAddress19 + 88;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    argumentWord4 = privateAddress19 + 160;
    if (workWord2 != 0)
        goto original_80078108;
    workWord3 = (int)&Level17_7774C_D_80070328 + 36;
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, int*, 0);
    workWord2 = workWord2 | 22;
    Level17_7774CField(workWord3, int*, 0) = workWord2;
original_80078108:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 2;
    if (workWord2 != workWord3)
        goto original_80078144;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    if (workWord2 == 0 ? (workWord2 = 0 + -1, 1) : (workWord2 = 0 + -1, 0))
        goto original_80078140;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
original_80078140:
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
original_80078144:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 160);
    if (workWord2 == 0)
        goto original_80078354;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = (int)&originalFrame.sp30;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = (int)&Level17_7774C_D_80070328;
    Level17_7774CKeep(savedWord17);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord17 + 0;
    argumentWord6 = privateAddress19 + 144;
    Level17_7774CSubtractVector(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    workWord2 = Level17_7774CMeasureVectorLength(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 156);
    workWord3 = workWord3 + 300;
    workWord2 = workWord2 < workWord3;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_80078240;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 844);
    workWord2 = workWord2 | 14;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 36, int*, 0) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(savedWord17, int*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 144);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 812);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 148);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x10000000U;
    Level17_7774CKeep(argumentWord5);
    workWord2 = workWord2 & 255;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
    argumentWord5 = argumentWord5 | 1024;
    workWord3 = (int)((unsigned int)argumentWord4 << 2);
    workWord3 = workWord3 + argumentWord4;
    argumentWord4 = (int)((unsigned int)workWord3 << 4);
    workWord3 = workWord3 + argumentWord4;
    workWord3 = (workWord3 >> 11);
    Level17_7774CResident_D_80070328_540_int = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 40;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 548, int*, 0) = workWord2;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 524, int*, 0) = argumentWord5;
    workWord2 = (int)((unsigned int)workWord3 << 2);
    workWord2 = workWord2 + workWord3;
    workWord3 = (int)((unsigned int)workWord2 << 4);
    workWord2 = workWord2 + workWord3;
    workWord2 = (workWord2 >> 11);
    Level17_7774CResident_D_80070328_544_int = workWord2;
original_80078240:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80078264;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 3;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 4;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
original_80078264:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 156);
    workWord2 = workWord2 + 90;
    Level17_7774CField(privateAddress19, int*, 156) = workWord2;
    workWord2 = workWord2 < 1501;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = 0 + 0;
    if (workWord2 != 0)
        goto original_80078288;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1500;
    Level17_7774CField(privateAddress19, int*, 156) = workWord2;
original_80078288:
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = (int)&originalFrame.sp40;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord17 + 0;
original_80078290:
    argumentWord5 = privateAddress19 + 144;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, short*, 56);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 20);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 7;
    workWord2 = workWord2 - workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 40) = workWord2;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    workWord2 = savedWord16 + workWord2;
    workWord2 = workWord2 & 255;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 156);
    Level17_7774CKeep(argumentWord4);
    Level17_7774CKeep(workWord3);
    productAt738.full = (long long)argumentWord4 * (long long)workWord3;
    __asm__("" : "=x"(productAt738.full) : "0"(productAt738.full));
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 32);
    __asm__ volatile(""
                     : "=x"(productAt738.full)
                     : "0"(productAt738.full), "m"(originalFrame.sp40)
                     : "memory");
    workWord10 = (int)productAt738.words.low;
    Level17_7774CKeep(workWord10);
    argumentWord4 = (workWord10 >> 12);
    workWord3 = workWord3 + argumentWord4;
    Level17_7774CField(&originalFrame.sp20, int*, 32) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 156);
    Level17_7774CKeep(workWord3);
    Level17_7774CKeep(workWord2);
    productAt749.full = (long long)workWord3 * (long long)workWord2;
    __asm__("" : "=x"(productAt749.full) : "0"(productAt749.full));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 13;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord17 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = (int)&originalFrame.sp50;
    savedWord16 = savedWord16 + 8;
    __asm__ volatile("" ::: "$8", "memory");
    workWord8 = (int)0x80070000U;
    Level17_7774CKeep(workWord8);
    workWord8 = Level17_7774CField(workWord8, int*, 17124);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1;
    Level17_7774CField(&originalFrame.sp20, int*, 48) = 0;
    Level17_7774CField(&originalFrame.sp20, int*, 52) = 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 50;
    Level17_7774CField(&originalFrame.sp20, int*, 56) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 36);
    __asm__ volatile(""
                     : "=x"(productAt749.full)
                     : "0"(productAt749.full), "m"(originalFrame.sp44)
                     : "memory");
    workWord10 = (int)productAt749.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 36) = workWord2;
    ((int (*)())workWord8)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
    workWord2 = savedWord16 < 256;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord17 + 0;
    if (workWord2 != 0)
        goto original_80078290;
original_80078354:
    Level17_7774CField(&originalFrame.sp20, int*, 160) = 0;
    workWord8 = (int)&Level17_7774C_D_80070328 + 8;
    Level17_7774CKeep(workWord8);
    __asm__ volatile("" ::: "$23", "memory");
    savedWord23 = privateAddress19 + 0;
original_80078364:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 7;
    if (workWord3 == workWord2)
        goto original_80078554;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(savedWord23, int*, 116);
    workWord2 = argumentWord4 < 7001;
    if (argumentWord4 < 0)
        goto original_80078554;
    __asm__ volatile("" ::: "$22", "memory");
    savedWord22 = 0 + -1;
    if (workWord2 != 0)
        goto original_80078398;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
    Level17_7774CField(savedWord23, int*, 116) = workWord2;
    goto original_80078554;
original_80078398:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14776);
    retainedPointer30 = savedWord23 + 0;
    workWord3 = (int)((unsigned int)workWord2 << 1);
    workWord3 = workWord3 + workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 4);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = argumentWord4 + workWord2;
    Level17_7774CField(savedWord23, int*, 116) = workWord2;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = 0 + 28;
original_800783C4:
    Level17_7774CKeep(workWord10);
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = 0 + 0;
    if (workWord10 == 0)
        goto original_80078544;
    __asm__ volatile("" ::: "$20", "memory");
    savedWord20 = 0 + 0;
original_800783D0:
    Level17_7774CField(&originalFrame.sp20, int*, 232) = workWord8;
    workWord2 = Level17_7774C_rand();
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + -150;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 150;
    workWord2 = workWord2 & 1;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = Level17_7774CField(retainedPointer30, int*, 116);
    savedWord16 = savedWord16 + savedWord20;
    savedWord16 = savedWord16 + workWord2;
    savedWord16 = savedWord16 & 255;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    savedWord16 = (int)((unsigned int)savedWord16 << 1);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + savedWord16), short*, 0);
    Level17_7774CKeep(workWord3);
    Level17_7774CKeep(savedWord17);
    productAt817.full = (long long)workWord3 * (long long)savedWord17;
    __asm__("" : "=x"(productAt817.full) : "0"(productAt817.full));
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + -150;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 150;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" : "=x"(productAt817.full) : "0"(productAt817.full) : "memory");
    workWord10 = (int)productAt817.words.low;
    Level17_7774CKeep(workWord10);
    argumentWord6 = (workWord10 >> 12);
    workWord3 = workWord3 + argumentWord6;
    workWord3 = workWord3 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 48) = workWord3;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + savedWord16), short*, 0);
    Level17_7774CKeep(workWord3);
    Level17_7774CKeep(savedWord17);
    productAt831.full = (long long)workWord3 * (long long)savedWord17;
    __asm__("" : "=x"(productAt831.full) : "0"(productAt831.full));
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" : "=x"(productAt831.full) : "0"(productAt831.full) : "memory");
    workWord10 = (int)productAt831.words.low;
    Level17_7774CKeep(workWord10);
    argumentWord4 = (workWord10 >> 12);
    workWord3 = workWord3 + argumentWord4;
    workWord3 = workWord3 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 52) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, short*, 56);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 20);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord2 - workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 56) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(retainedPointer30, int*, 116);
    __asm__ volatile("" ::: "$8", "memory");
    workWord8 = Level17_7774CField(&originalFrame.sp20, int*, 232);
    workWord2 = workWord10 - workWord3;
    if (workWord2 < 0 ? (workWord2 = workWord2 < 200, 1) : (workWord2 = workWord2 < 200, 0))
        goto original_8007849C;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1;
    if (workWord2 != 0)
        goto original_800784B4;
    goto original_800784FC;
original_8007849C:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord3 - workWord10;
    workWord2 = workWord2 < 200;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1;
    if (workWord2 == 0)
        goto original_800784FC;
original_800784B4:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, short*, 56);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 20);
    workWord2 = workWord2 - workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord8, int*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(workWord8, int*, 60);
    workWord2 = workWord2 - workWord3;
    workWord2 = workWord2 + argumentWord4;
    if (workWord2 >= 0)
        goto original_800784E0;
    workWord2 = 0 - workWord2;
original_800784E0:
    workWord2 = workWord2 < 300;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1;
    if (workWord2 == 0)
        goto original_800784FC;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord8, int*, 28);
    workWord2 = workWord2 | 14;
    Level17_7774CField(workWord8, int*, 28) = workWord2;
original_800784FC:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 32;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = (int)&originalFrame.sp50;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = (int)&originalFrame.sp60;
    savedWord18 = savedWord18 + 2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 17124);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 8;
    Level17_7774CField(&originalFrame.sp20, int*, 64) = 0;
    Level17_7774CField(&originalFrame.sp20, int*, 68) = 0;
    Level17_7774CField(&originalFrame.sp20, int*, 72) = workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 232) = workWord8;
    ((int (*)(int, int, int, int))workWord3)(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
    workWord2 = (int)((unsigned int)savedWord22 << 1);
    savedWord20 = savedWord20 + workWord2;
    workWord2 = savedWord18 < 28;
    __asm__ volatile("" ::: "$8", "memory");
    workWord8 = Level17_7774CField(&originalFrame.sp20, int*, 232);
    if (workWord2 != 0)
        goto original_800783D0;
original_80078544:
    savedWord22 = savedWord22 + 2;
    workWord2 = savedWord22 < 2;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = 0 + 28;
    if (workWord2 != 0)
        goto original_800783C4;
original_80078554:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 160);
    savedWord23 = savedWord23 + 4;
    workWord10 = workWord10 + 1;
    workWord2 = workWord10 < 3;
    Level17_7774CField(&originalFrame.sp20, int*, 160) = workWord10;
    if (workWord2 != 0)
        goto original_80078364;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 9;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 30, 1) : (workWord2 = 0 + 30, 0))
        goto original_800785C8;
    if (workWord3 == workWord2)
        goto original_800785C8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 69);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    workWord2 = Level17_7774CSubAngle8(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = workWord2 + 0;
    workWord2 = workWord3 < 33;
    if (workWord2 != 0 ? (workWord2 = workWord3 < -32, 1) : (workWord2 = workWord3 < -32, 0))
        goto original_800785A8;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 32;
    Level17_7774CKeep(workWord3);
    workWord2 = workWord3 < -32;
original_800785A8:
    if (workWord2 == 0)
        goto original_800785B4;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + -32;
original_800785B4:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 69);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(ownerAddress21, unsigned char*, 69) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
original_800785C8:
original_800785D0:
    switch ((unsigned int)workWord3) {
        case 0:
            goto original_80078820;
        case 1:
            goto original_800792A4;
        case 2:
            goto original_800786CC;
        case 3:
            goto original_8007A26C;
        case 4:
            goto original_8007A26C;
        case 5:
            goto original_8007A26C;
        case 6:
            goto original_8007967C;
        case 7:
            goto original_80079ECC;
        case 8:
            goto original_80078B48;
        case 9:
            goto original_80078B78;
        case 10:
            goto original_8007A26C;
        case 11:
            goto original_800795B8;
        case 12:
            goto original_8007A26C;
        case 13:
            goto original_8007A26C;
        case 14:
            goto original_8007A26C;
        case 15:
            goto original_80078820;
        case 16:
            goto original_800785F0;
        case 17:
            goto original_8007A26C;
        case 18:
            goto original_8007A26C;
        case 19:
            goto original_8007A26C;
        case 20:
            goto original_80079CB8;
        case 21:
            goto original_80079CC4;
        case 22:
            goto original_8007A26C;
        case 23:
            goto original_8007A26C;
        case 24:
            goto original_8007A26C;
        case 25:
            goto original_8007A26C;
        case 26:
            goto original_8007A26C;
        case 27:
            goto original_8007A26C;
        case 28:
            goto original_8007A26C;
        case 29:
            goto original_8007A26C;
        case 30:
            goto original_800790A8;
        case 31:
            goto original_8007A26C;
        case 32:
            goto original_8007A26C;
        case 33:
            goto original_8007A26C;
        case 34:
            goto original_8007A26C;
        case 35:
            goto original_8007A26C;
        case 36:
            goto original_8007A26C;
        case 37:
            goto original_8007A26C;
        case 38:
            goto original_8007A26C;
        case 39:
            goto original_8007A26C;
        case 40:
            goto original_80078940;
        case 41:
            goto original_8007A26C;
        case 42:
            goto original_8007A26C;
        case 43:
            goto original_8007A26C;
        case 44:
            goto original_8007A26C;
        case 45:
            goto original_8007A26C;
        case 46:
            goto original_8007A26C;
        case 47:
            goto original_8007A26C;
        case 48:
            goto original_8007A26C;
        case 49:
            goto original_8007A26C;
        case 50:
            goto original_80079710;
        default:
            goto original_8007A26C;
    }
original_800785F0:
    MATCHING_OBSERVE_VOLATILE(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    if (workWord2 == 0 ? (workWord2 = 0 + 15, 1) : (workWord2 = 0 + 15, 0))
        goto original_80078634;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_80078634;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 15;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80078634:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 7;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 1300;
    if (workWord2 == 0)
        goto original_800786A8;
    workWord3 = (int)&Level17_7774C_D_80070328 + 36;
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, int*, 0);
    workWord2 = workWord2 | 134;
    Level17_7774CField(workWord3, int*, 0) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    workWord2 = workWord2 + 128;
    workWord2 = workWord2 & 255;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 664, int*, 0) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 110);
    workWord2 = workWord2 < 20;
    if (workWord2 == 0 ? (workWord2 = 0 + 20, 1) : (workWord2 = 0 + 20, 0))
        goto original_800786A8;
    Level17_7774CField(privateAddress19, short*, 110) = workWord2;
original_800786A8:
    argumentWord4 = privateAddress19 + 110;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 15;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 60;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 15;
    goto original_80079CA8;
original_800786CC:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CReadSelectedFrameScalar(argumentWord4);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = workWord10 < 700;
    if (workWord2 == 0)
        goto original_8007874C;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, short*, 56);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 20);
    workWord2 = workWord2 - workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 816);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, 876);
    workWord2 = workWord2 - workWord3;
    workWord2 = workWord2 + argumentWord4;
    if (workWord2 >= 0)
        goto original_8007871C;
    workWord2 = 0 - workWord2;
original_8007871C:
    workWord2 = workWord2 < 1500;
    if (workWord2 == 0 ? (workWord2 = 0 + 4, 1) : (workWord2 = 0 + 4, 0))
        goto original_8007874C;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 888);
    if (workWord3 != workWord2 ? ({
            workWord3 = (int)0x00020000U;
            Level17_7774CKeep(workWord3);
            1;
        })
                               : ({
                                     workWord3 = (int)0x00020000U;
                                     Level17_7774CKeep(workWord3);
                                     0;
                                 }))
        goto original_8007874C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 24);
    workWord2 = workWord2 | workWord3;
    Level17_7774CField(ownerAddress21, int*, 24) = workWord2;
original_8007874C:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_800787C8;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 63);
    workWord2 = (unsigned int)workWord2 < 2;
    if (workWord2 != 0 ? (workWord2 = argumentWord5 < 36, 1) : (workWord2 = argumentWord5 < 36, 0))
        goto original_800787C8;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    if (workWord2 != 0)
        goto original_800787CC;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x55550000U;
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, short*, 142);
    MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
    workWord3 = workWord3 | 21846;
    argumentWord4 = argumentWord4 + 1;
    Level17_7774CKeep(argumentWord4);
    Level17_7774CKeep(workWord3);
    productAt1041.full = (long long)argumentWord4 * (long long)workWord3;
    __asm__("" : "=x"(productAt1041.full) : "0"(productAt1041.full));
    workWord3 = (argumentWord4 >> 31);
    workWord10 = (int)productAt1041.words.high;
    Level17_7774CKeep(workWord10);
    workWord3 = workWord10 - workWord3;
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    argumentWord4 = argumentWord4 - workWord2;
    Level17_7774CField(privateAddress19, short*, 142) = argumentWord4;
    argumentWord4 = (int)((unsigned int)argumentWord4 << 16);
    argumentWord4 = (argumentWord4 >> 14);
    argumentWord4 = argumentWord4 + privateAddress19;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1200;
    Level17_7774CField(argumentWord4, int*, 116) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
original_800787C8:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
original_800787CC:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    if (workWord2 == 0)
        goto original_8007A26C;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 140);
    workWord2 = workWord2 + -1;
    Level17_7774CField(privateAddress19, short*, 140) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 > 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 15;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 60;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 15;
    goto original_80079CA8;
original_80078820:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    argumentWord4 = privateAddress19 + 64;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    if (workWord2 == 0)
        goto original_800788F4;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 176);
    workWord2 = workWord10 < 13824;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_800788F4;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, -8160);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, -8156);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, unsigned short*, -8128);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    argumentWord4 = (int)((unsigned int)argumentWord4 << 16);
    argumentWord4 = (argumentWord4 >> 20);
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 16;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_800788F4;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 808);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 812);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 8;
    if (workWord2 == 0 ? (workWord2 = 0 + 40, 1) : (workWord2 = 0 + 40, 0))
        goto original_800788F4;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 150;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
original_800788F4:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 880);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 28;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 58, 1) : (workWord2 = 0 + 58, 0))
        goto original_80078924;
    if (workWord3 == workWord2)
        goto original_80078924;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 176);
    workWord2 = workWord10 < 14125;
    if (workWord2 != 0)
        goto original_8007A26C;
original_80078924:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 10240;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_8007A26C;
    goto original_80079604;
original_80078940:
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    if (savedWord16 == workWord2 ? (workWord2 = savedWord16 < 2, 1)
                                 : (workWord2 = savedWord16 < 2, 0))
        goto original_800789A8;
    if (workWord2 == 0)
        goto original_80078968;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (savedWord16 == 0)
        goto original_8007897C;
    goto original_8007A26C;
original_80078968:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (savedWord16 == workWord2)
        goto original_80078B1C;
    goto original_8007A26C;
original_8007897C:
    Level17_7774CKeep(savedWord16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    if (workWord2 == 0)
        goto original_8007A26C;
    goto original_80079B18;
original_800789A8:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp50;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 94);
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
    workWord2 = (int)((unsigned int)workWord3 << 5);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 + workWord3;
    workWord3 = (int)((unsigned int)workWord2 << 4);
    workWord2 = workWord2 + workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 48);
    workWord2 = (workWord2 >> 10);
    workWord3 = workWord3 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 48) = workWord3;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 94);
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
    workWord2 = (int)((unsigned int)workWord3 << 5);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 + workWord3;
    workWord3 = (int)((unsigned int)workWord2 << 4);
    workWord2 = workWord2 + workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 52);
    workWord2 = (workWord2 >> 10);
    workWord3 = workWord3 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 52) = workWord3;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == savedWord16)
        goto original_80078A74;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80078A74:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 48);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 52);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 7;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 30;
    fifthArgument = savedWord16;
    sixthArgument = 0;
    workWord2 = Level17_7774CTurnMobyTowardHeading(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7, fifthArgument, sixthArgument);
    argumentWord4 = ownerAddress21 + 12;
    if (workWord2 == 0)
        goto original_80078B00;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 62);
    workWord2 = workWord2 + 30;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    workWord2 = workWord2 < 301;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80078AE4;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 300;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
original_80078AE4:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 62);
    __asm__ volatile("" ::: "$2", "memory");
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
    fifthArgument = workWord2;
    workWord2 = Level17_7774CResolveMobyYawStep(argumentWord4, argumentWord5, argumentWord6,
                                                argumentWord7, fifthArgument);
    Level17_7774CKeep(ownerAddress21);
    argumentWord4 = ownerAddress21 + 12;
original_80078B00:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)&originalFrame.sp50;
    workWord2 = Level17_7774CApproximatePlanarDistance(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 1024;
    if (workWord2 == 0)
        goto original_8007A26C;
    goto original_80079B18;
original_80078B1C:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 10;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 1;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_8007A26C;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
    goto original_8007A26C;
original_80078B48:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 7;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 9;
    goto original_80079C98;
original_80078B78:
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = 0 + 0;
    __asm__ volatile("" ::: "$20", "memory");
    savedWord20 = (int)&originalFrame.sp70;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord20 + 0;
original_80078B84:
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = ownerAddress21 + 12;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    workWord2 = Level17_7774CField(workWord2, int*, 8);
    Level17_7774CField(&originalFrame.sp20, int*, 88) = workWord2;
    workWord2 = savedWord18 < 4;
    savedWord16 = savedWord17 + 64;
    if (workWord2 == 0)
        goto original_80078BBC;
    savedWord16 = savedWord17 + -64;
original_80078BBC:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 12;
    workWord2 = Level17_7774CRandSignedBetween(argumentWord4, argumentWord5);
    savedWord16 = savedWord16 + workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 4;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 79;
    workWord8 = savedWord16 & 255;
    __asm__ volatile("" ::: "$9", "memory");
    workWord9 = (int)&Level17_7774C_D_80065920;
    Level17_7774CKeep(workWord9);
    workWord8 = (int)((unsigned int)workWord8 << 1);
    workWord9 = workWord8 + workWord9;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord9, short*, 0);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord20 + 0;
    workWord2 = (int)((unsigned int)workWord3 << 5);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 + workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 80);
    workWord2 = (workWord2 >> 10);
    workWord3 = workWord3 + workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)&Level17_7774C_D_800658A0;
    Level17_7774CKeep(workWord2);
    workWord8 = workWord8 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 80) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord8, short*, 0);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = (int)&originalFrame.sp80;
    workWord2 = (int)((unsigned int)workWord3 << 5);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 + workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 84);
    workWord2 = (workWord2 >> 10);
    workWord3 = workWord3 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 84) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord9, short*, 0);
    savedWord18 = savedWord18 + 1;
    workWord2 = (int)((unsigned int)workWord3 << 3);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    workWord2 = 0 - workWord2;
    workWord2 = (workWord2 >> 12);
    Level17_7774CField(&originalFrame.sp20, int*, 96) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord8, short*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -70;
    Level17_7774CField(&originalFrame.sp20, int*, 104) = workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 3);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 - workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    workWord2 = 0 - workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 17124);
    workWord2 = (workWord2 >> 12);
    Level17_7774CField(&originalFrame.sp20, int*, 100) = workWord2;
    ((int (*)(int, int, int, int))workWord3)(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
    workWord2 = savedWord18 < 8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord20 + 0;
    if (workWord2 != 0)
        goto original_80078B84;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 69);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    workWord2 = workWord2 + -32;
    Level17_7774CField(ownerAddress21, unsigned char*, 69) = workWord2;
    if (workWord3 == 0)
        goto original_80078CD8;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = 0 + 250;
    if (workWord3 == workWord2)
        goto original_80078DB4;
    goto original_80078FFC;
original_80078CD8:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80078D00;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 1;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 4;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
original_80078D00:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 9;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    argumentWord4 = privateAddress19 + 92;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_80078FFC;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 808);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 812);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 24;
    if (workWord2 == 0 ? (workWord2 = 0 + 240, 1) : (workWord2 = 0 + 240, 0))
        goto original_80078FFC;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 40);
    Level17_7774CField(privateAddress19, volatile short*, 92) = workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 4);
    workWord2 = workWord2 - workWord3;
    workWord3 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord3 + 240;
    Level17_7774CField(privateAddress19, short*, 92) = workWord2;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    workWord2 = workWord3 + 300;
    if (workWord10 != 0)
        goto original_80078D90;
    Level17_7774CField(privateAddress19, short*, 92) = workWord2;
original_80078D90:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    Level17_7774CField(privateAddress19, short*, 180) = 0;
    workWord2 = (int)((unsigned int)workWord2 << 4);
    Level17_7774CField(privateAddress19, int*, 184) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    workWord2 = workWord2 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = workWord2;
    goto original_80078FFC;
original_80078DB4:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80078DD8;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 1;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 4;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
original_80078DD8:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    workWord2 = workWord10 < 8;
    workWord3 = workWord10 + -7;
    if (workWord2 != 0)
        goto original_80078E08;
    workWord2 = workWord3 < 5;
    if (workWord2 != 0 ? (workWord2 = (int)((unsigned int)workWord3 << 4), 1)
                       : (workWord2 = (int)((unsigned int)workWord3 << 4), 0))
        goto original_80078E00;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 4;
    Level17_7774CKeep(workWord3);
    workWord2 = (int)((unsigned int)workWord3 << 4);
original_80078E00:
    workWord2 = workWord2 - workWord3;
    savedWord16 = savedWord16 - workWord2;
original_80078E08:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 62);
    workWord2 = savedWord16 < workWord2;
    if (workWord2 == 0)
        goto original_80078E20;
    Level17_7774CField(privateAddress19, short*, 62) = savedWord16;
original_80078E20:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 2501;
    workWord3 = savedWord16 + 30;
    if (workWord2 != 0)
        goto original_80078E50;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 62);
    workWord2 = workWord3 < workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_80078E68;
    Level17_7774CField(privateAddress19, short*, 62) = workWord3;
    goto original_80078E68;
original_80078E50:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 62);
    workWord2 = savedWord16 < workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_80078E68;
    Level17_7774CField(privateAddress19, short*, 62) = savedWord16;
original_80078E68:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 1000;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 62);
    __asm__ volatile("" ::: "$2", "memory");
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
    fifthArgument = workWord2;
    workWord2 = Level17_7774CResolveMobyYawStep(argumentWord4, argumentWord5, argumentWord6,
                                                argumentWord7, fifthArgument);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 32;
    Level17_7774CKeep(workWord3);
    if (workWord2 != workWord3)
        goto original_80078E90;
    Level17_7774CField(privateAddress19, short*, 92) = 0;
original_80078E90:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 12201;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 1;
    if (workWord2 != 0)
        goto original_80078EC4;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(&originalFrame.sp20, int*, 152);
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 65;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 1;
    if (workWord2 != 0)
        goto original_80078EC4;
    Level17_7774CField(privateAddress19, short*, 92) = 0;
original_80078EC4:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 808);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 812);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 184);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CSubAngle12(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = workWord2 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = argumentWord4 + 0;
    if (argumentWord4 >= 0)
        goto original_80078F04;
    workWord2 = 0 - workWord2;
original_80078F04:
    workWord2 = workWord2 < 33;
    if (workWord2 != 0)
        goto original_80078FA0;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 8825;
    if (workWord2 != 0)
        goto original_80078F30;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 180);
    workWord2 = workWord2 + 7;
    goto original_80078F3C;
original_80078F30:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 180);
    workWord2 = workWord2 + 2;
original_80078F3C:
    Level17_7774CField(privateAddress19, short*, 180) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 180);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = argumentWord4 + 0;
    if (argumentWord4 >= 0)
        goto original_80078F50;
    workWord3 = 0 - workWord3;
original_80078F50:
    workWord2 = workWord3 < workWord2;
    if (workWord2 == 0)
        goto original_80078F60;
    Level17_7774CField(privateAddress19, short*, 180) = workWord3;
original_80078F60:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 180);
    workWord2 = workWord3 < argumentWord4;
    if (workWord2 == 0)
        goto original_80078F78;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = workWord3 + 0;
original_80078F78:
    workWord3 = 0 - workWord3;
    workWord2 = argumentWord4 < workWord3;
    if (workWord2 == 0)
        goto original_80078F8C;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = workWord3 + 0;
original_80078F8C:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 184);
    workWord2 = workWord2 + argumentWord4;
    Level17_7774CField(privateAddress19, int*, 184) = workWord2;
    goto original_80078FA4;
original_80078FA0:
    Level17_7774CField(privateAddress19, short*, 180) = 0;
original_80078FA4:
    argumentWord4 = privateAddress19 + 92;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 184);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    workWord2 = (workWord2 >> 4);
    Level17_7774CField(ownerAddress21, unsigned char*, 70) = workWord2;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    if (workWord2 == 0)
        goto original_80078FFC;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    if (workWord2 == 0 ? (workWord2 = 0 + -1, 1) : (workWord2 = 0 + -1, 0))
        goto original_80078FE8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
original_80078FE8:
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 90;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 52;
    Level17_7774CField(privateAddress19, short*, 164) = workWord2;
original_80078FFC:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 1300;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_80079044;
    workWord3 = (int)&Level17_7774C_D_80070328 + 36;
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, int*, 0);
    workWord2 = workWord2 | 22;
    Level17_7774CField(workWord3, int*, 0) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 60;
    Level17_7774CField(privateAddress19, int*, 88) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 80;
    Level17_7774CField(privateAddress19, short*, 92) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 180;
    Level17_7774CField(privateAddress19, int*, 84) = 0;
    goto original_80079064;
original_80079044:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 176);
    workWord2 = workWord10 < 14325;
    if (workWord2 != 0 ? (workWord2 = 0 + 80, 1) : (workWord2 = 0 + 80, 0))
        goto original_8007A26C;
    Level17_7774CField(privateAddress19, short*, 92) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 180;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
original_80079064:
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, 808);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, 812);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord2, int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 4);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, short*, 94) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 30;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    goto originalReturn;
original_800790A8:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 69);
    workWord2 = workWord2 + -32;
    Level17_7774CField(ownerAddress21, unsigned char*, 69) = workWord2;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 13824;
    workWord2 = workWord2 - workWord10;
    workWord2 = workWord2 < 2000;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 2;
    if (workWord2 == 0)
        goto original_800790D4;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 9;
original_800790D4:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 128;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 94);
    __asm__ volatile("" ::: "$2", "memory");
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    fifthArgument = workWord2;
    sixthArgument = 0;
    workWord2 = Level17_7774CTurnMobyTowardHeading(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7, fifthArgument, sixthArgument);
    if (workWord2 == 0)
        goto original_80079168;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 62);
    workWord2 = workWord2 + 30;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    workWord2 = workWord2 < 351;
    if (workWord2 != 0 ? (workWord2 = 0 + 350, 1) : (workWord2 = 0 + 350, 0))
        goto original_80079120;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
original_80079120:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 12824;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80079150;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(&originalFrame.sp20, int*, 152);
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 50;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_80079168;
original_80079150:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 62);
    __asm__ volatile("" ::: "$2", "memory");
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
    fifthArgument = workWord2;
    workWord2 = Level17_7774CResolveMobyYawStep(argumentWord4, argumentWord5, argumentWord6,
                                                argumentWord7, fifthArgument);
original_80079168:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 12824;
    if (workWord2 != 0 ? (workWord2 = workWord10 < 8193, 1) : (workWord2 = workWord10 < 8193, 0))
        goto original_800791D8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, short*, 94);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    if (workWord2 == 0)
        goto original_800791CC;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    if (workWord2 == 0 ? (workWord2 = 0 + -1, 1) : (workWord2 = 0 + -1, 0))
        goto original_800791B8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
original_800791B8:
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 120;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 52;
    Level17_7774CField(privateAddress19, short*, 164) = workWord2;
original_800791CC:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 8193;
original_800791D8:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 != 0)
        goto original_80079254;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = Level17_7774CField(ownerAddress21, int*, 12);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(workWord2, int*, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord2, int*, 4);
    argumentWord4 = argumentWord7 - argumentWord4;
    argumentWord5 = workWord3 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, short*, 94);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 12;
    if (workWord2 == 0)
        goto original_80079254;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    if (workWord2 == 0 ? (workWord2 = 0 + -1, 1) : (workWord2 = 0 + -1, 0))
        goto original_80079240;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
original_80079240:
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 120;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 52;
    Level17_7774CField(privateAddress19, short*, 164) = workWord2;
original_80079254:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 12289;
    if (workWord2 != 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    if (workWord2 == 0 ? (workWord2 = 0 + -1, 1) : (workWord2 = 0 + -1, 0))
        goto original_8007928C;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
original_8007928C:
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 120;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 52;
    Level17_7774CField(privateAddress19, short*, 164) = workWord2;
    goto original_8007A26C;
original_800792A4:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 1;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 62);
    workWord2 = workWord2 + 50;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    workWord2 = workWord2 < 301;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_800792E4;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 300;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
original_800792E4:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 62);
    __asm__ volatile("" ::: "$2", "memory");
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
    fifthArgument = workWord2;
    workWord2 = Level17_7774CResolveMobyYawStep(argumentWord4, argumentWord5, argumentWord6,
                                                argumentWord7, fifthArgument);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 3500;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_80079388;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 808);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 812);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 32;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_8007938C;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 60);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    if (workWord3 != workWord2 ? (workWord2 = 0 + 11, 1) : (workWord2 = 0 + 11, 0))
        goto original_8007938C;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_8007938C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 11;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80079388:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
original_8007938C:
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = (int)&Level17_7774C_D_80070328;
    Level17_7774CKeep(savedWord16);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(savedWord16, int*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord16, int*, 4);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 51;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_800793E8;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 15;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 80;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 15;
    Level17_7774CField(argumentWord4, unsigned char*, 72) = workWord2;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
    goto originalReturn;
original_800793E8:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 176);
    workWord2 = workWord10 < 14125;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 != 0)
        goto original_80079468;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(savedWord16, int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(savedWord16, int*, 4);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord2, int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 4);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, short*, 94) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 40;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 10;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    if (workWord3 == workWord2)
        goto original_80079460;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 10;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80079460:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 40;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
original_80079468:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned short*, 60);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2827;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 != workWord2)
        goto original_80079578;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 2000;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = 0 + 4;
    if (workWord2 == 0)
        goto original_80079578;
    savedWord17 = (int)&Level17_7774C_D_80070328 + 80;
    Level17_7774CKeep(savedWord17);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord17, int*, 0);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 != savedWord16)
        goto original_800794F4;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, 808);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, 812);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, unsigned char*, 822);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 32;
    if (workWord2 != 0)
        goto original_80079578;
original_800794F4:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CReadSelectedFrameScalar(argumentWord4);
    workWord2 = workWord2 < 6;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 != 0)
        goto original_80079578;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, 808);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, 812);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, unsigned char*, 822);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 81;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = 0 + 2;
    if (workWord2 != 0)
        goto original_80079558;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord17, int*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == savedWord16)
        goto original_80079560;
original_80079558:
    Level17_7774CField(&originalFrame.sp20, int*, 144) = workWord10;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
original_80079560:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 11;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 90;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 11;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
original_80079578:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 11;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 1, 1) : (workWord2 = 0 + 1, 0))
        goto original_8007A26C;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
    goto original_8007A26C;
original_800795B8:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    if (workWord2 == 0 ? (workWord2 = 0 + 15, 1) : (workWord2 = 0 + 15, 0))
        goto original_800795F0;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 15;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
original_800795F0:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 176);
    workWord2 = workWord10 < 14125;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 != 0)
        goto original_8007A26C;
original_80079604:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, 808);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, 812);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord2, int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 4);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, short*, 94) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 40;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 10;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    if (workWord3 == workWord2)
        goto original_80079670;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 10;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80079670:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 40;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    goto original_8007A26C;
original_8007967C:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 182);
    if (workWord2 != 0)
        goto original_800796A4;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 12825;
    if (workWord2 != 0 ? (workWord2 = workWord10 < 19825, 1) : (workWord2 = workWord10 < 19825, 0))
        goto original_800796B0;
    Level17_7774CField(privateAddress19, short*, 16) = 0;
original_800796A4:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 19825;
original_800796B0:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_800796BC;
    Level17_7774CField(privateAddress19, short*, 16) = 0;
original_800796BC:
    argumentWord5 = privateAddress19 + 12;
    workWord2 = Level17_7774CUpdateMobyMotionDescriptor(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 256;
    if (workWord2 != workWord3)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 13825;
    if (workWord2 != 0 ? (workWord2 = 0 + 20, 1) : (workWord2 = 0 + 20, 0))
        goto original_80079708;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    Level17_7774CField(privateAddress19, short*, 164) = 0;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 50;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    goto originalReturn;
original_80079708:
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    goto original_8007A26C;
original_80079710:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 96);
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = workWord2 - workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, -15024);
    workWord2 = (int)((unsigned int)workWord2 << 3);
    savedWord20 = workWord3 + workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 52);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    if (workWord3 != workWord2)
        goto original_80079788;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    workWord2 = (unsigned int)workWord2 < 4;
    if (workWord2 == 0)
        goto original_80079788;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 176);
    workWord2 = workWord10 < 12824;
    if (workWord2 == 0)
        goto original_80079788;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 12;
    Level17_7774CSetClampedPlayerTargetAngles(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x10000000U;
    Level17_7774CKeep(workWord2);
    workWord2 = workWord2 | 2;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 524, int*, 0) = workWord2;
original_80079788:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    if (workWord2 == 0 ? (workWord2 = (unsigned int)workWord2 < 4, 1)
                       : (workWord2 = (unsigned int)workWord2 < 4, 0))
        goto original_80079874;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    if (workWord2 == 0)
        goto original_80079874;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = 0 + 0;
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = (int)&originalFrame.sp60;
original_800797A8:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 150;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord18 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = ownerAddress21 + 12;
    savedWord16 = workWord2 + 850;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 100);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 7;
    Level17_7774CField(&originalFrame.sp20, int*, 72) = workWord2;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    workWord2 = savedWord17 + workWord2;
    workWord2 = workWord2 & 255;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
    Level17_7774CKeep(workWord3);
    Level17_7774CKeep(savedWord16);
    productAt2089.full = (long long)workWord3 * (long long)savedWord16;
    __asm__("" : "=x"(productAt2089.full) : "0"(productAt2089.full));
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 64);
    __asm__ volatile(""
                     : "=x"(productAt2089.full)
                     : "0"(productAt2089.full), "m"(originalFrame.sp60)
                     : "memory");
    workWord10 = (int)productAt2089.words.low;
    Level17_7774CKeep(workWord10);
    argumentWord4 = (workWord10 >> 12);
    workWord3 = workWord3 + argumentWord4;
    Level17_7774CField(&originalFrame.sp20, int*, 64) = workWord3;
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(savedWord16);
    productAt2099.full = (long long)workWord2 * (long long)savedWord16;
    __asm__("" : "=x"(productAt2099.full) : "0"(productAt2099.full));
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 50;
    savedWord17 = savedWord17 + 8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 35;
    Level17_7774CField(&originalFrame.sp20, int*, 80) = 0;
    Level17_7774CField(&originalFrame.sp20, int*, 84) = 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 68);
    __asm__ volatile(""
                     : "=x"(productAt2099.full)
                     : "0"(productAt2099.full), "m"(originalFrame.sp64)
                     : "memory");
    workWord10 = (int)productAt2099.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 68) = workWord2;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 1;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 13;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = savedWord18 + 0;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 17124);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = (int)&originalFrame.sp70;
    Level17_7774CField(&originalFrame.sp20, int*, 88) = workWord2;
    ((int (*)(int, int, int, int))workWord3)(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
    workWord2 = savedWord17 < 256;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    if (workWord2 != 0)
        goto original_800797A8;
original_80079874:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    workWord2 = (unsigned int)workWord3 < 5;
    if (workWord2 == 0)
        goto original_8007A26C;
    switch ((unsigned int)workWord3) {
        case 0:
            goto original_800798A0;
        case 1:
            goto original_80079914;
        case 2:
            goto original_80079974;
        case 3:
            goto original_80079A34;
        case 4:
            goto original_80079B2C;
        default:
            goto original_8007A26C;
    }
original_800798A0:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 12;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 1024;
    workWord2 = Level17_7774CQueryWorldHeight(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x00FF0000U;
    Level17_7774CKeep(workWord3);
    Level17_7774CField(privateAddress19, int*, 100) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 253;
    Level17_7774CField(ownerAddress21, unsigned char*, 71) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 100);
    workWord3 = workWord3 | 65535;
    workWord2 = workWord2 & workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80000000U;
    Level17_7774CKeep(workWord3);
    workWord2 = workWord2 | workWord3;
    Level17_7774CField(ownerAddress21, int*, 84) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(savedWord20, unsigned char*, 73) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 13;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_80079B18;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 13;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
    goto original_80079B18;
original_80079914:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_8007993C;
    Level17_7774CKeep(workWord2);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 0;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 4;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
original_8007993C:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 3;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(&originalFrame.sp20, int*, 152);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    fifthArgument = 0;
    sixthArgument = 0;
    workWord2 = Level17_7774CTurnMobyTowardHeading(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7, fifthArgument, sixthArgument);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 20);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 100);
    workWord2 = workWord3 - workWord2;
    if (workWord2 <= 0 ? (workWord2 = workWord3 + -30, 1) : (workWord2 = workWord3 + -30, 0))
        goto original_80079B18;
    Level17_7774CField(ownerAddress21, int*, 20) = workWord2;
    goto original_8007A26C;
original_80079974:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 3;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(&originalFrame.sp20, int*, 152);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    fifthArgument = 0;
    sixthArgument = 0;
    workWord2 = Level17_7774CTurnMobyTowardHeading(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7, fifthArgument, sixthArgument);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 24);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x02000000U;
    Level17_7774CKeep(workWord3);
    workWord2 = workWord2 & workWord3;
    if (workWord2 == 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, int*, 188);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CSoundHandleMatchesOwnerInStates1Or2(argumentWord4, argumentWord5);
    if (workWord2 == 0 ? (workWord2 = 0 + -1, 1) : (workWord2 = 0 + -1, 0))
        goto original_800799C8;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 188);
    Level17_7774CTransitionSoundHandleTo3Or5(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + -1;
original_800799C8:
    Level17_7774CField(privateAddress19, int*, 188) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 60);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 14;
    if (workWord3 == workWord2 ? (workWord3 = 0 + 14, 1) : (workWord3 = 0 + 14, 0))
        goto original_80079B18;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, short*, 54);
    workWord2 = (int)((unsigned int)workWord2 << 2);
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_8006EE2C + workWord2), int*, 0);
    workWord2 = Level17_7774CField(workWord2, int*, 116);
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    workWord2 = Level17_7774CField(workWord2, unsigned char*, 0);
    Level17_7774CField(ownerAddress21, unsigned char*, 60) = workWord3;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 62) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = workWord3;
    workWord2 = (unsigned int)workWord2 < 2;
    workWord2 = workWord2 ^ 1;
    workWord2 = 0 - workWord2;
    workWord2 = workWord2 & 48;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    goto original_80079B18;
original_80079A34:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    if (workWord2 == 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 48);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 52);
    workWord2 = workWord2 + -1;
    workWord3 = workWord3 + -1;
    Level17_7774CField(privateAddress19, int*, 48) = workWord2;
    Level17_7774CField(privateAddress19, int*, 52) = workWord3;
    if (workWord3 > 0)
        goto original_80079AA0;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 7;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 7;
    Level17_7774CField(argumentWord4, unsigned char*, 72) = workWord2;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, int*, 168);
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = 0 + -1;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
    if (argumentWord4 == savedWord16)
        goto original_80079A94;
    workWord2 = Level17_7774CResetHudEntryByHandle(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
original_80079A94:
    Level17_7774CField(privateAddress19, int*, 168) = savedWord16;
    Level17_7774CField(privateAddress19, int*, 208) = workWord2;
    goto originalReturn;
original_80079AA0:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 48);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 > 0)
        goto original_80079AC4;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 40);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 106);
    workWord2 = workWord2 + 1;
    Level17_7774CField(privateAddress19, int*, 48) = workWord3;
    Level17_7774CField(privateAddress19, int*, 40) = workWord2;
original_80079AC4:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    Level17_7774CPlaySoundFromGlobalByteTable(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 12;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_80079B10;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 12;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80079B10:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 140;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
original_80079B18:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    workWord2 = workWord2 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = workWord2;
    goto original_8007A26C;
original_80079B2C:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    workWord2 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 20);
    workWord2 = Level17_7774CField(workWord2, int*, 8);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, short*, 56);
    workWord2 = workWord2 - argumentWord4;
    workWord3 = workWord2 + workWord3;
    workWord2 = workWord3 < 201;
    if (workWord2 != 0 ? (workWord2 = workWord3 < -200, 1) : (workWord2 = workWord3 < -200, 0))
        goto original_80079B60;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 200;
    Level17_7774CKeep(workWord3);
    workWord2 = workWord3 < -200;
original_80079B60:
    if (workWord2 == 0 ? (workWord2 = argumentWord4 + workWord3, 1)
                       : (workWord2 = argumentWord4 + workWord3, 0))
        goto original_80079B70;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + -200;
    Level17_7774CKeep(workWord3);
    workWord2 = argumentWord4 + workWord3;
original_80079B70:
    Level17_7774CField(ownerAddress21, int*, 20) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = (int)&originalFrame.sp70;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 152);
    argumentWord5 = (int)((unsigned int)workWord10 << 1);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + argumentWord5), short*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 12;
    workWord2 = (int)((unsigned int)workWord3 << 5);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 3);
    workWord2 = workWord2 - workWord3;
    workWord3 = (int)((unsigned int)workWord2 << 2);
    workWord3 = workWord3 - workWord2;
    workWord3 = (int)((unsigned int)workWord3 << 4);
    workWord3 = 0 - workWord3;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 80);
    workWord3 = (workWord3 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 80) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + argumentWord5), short*, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord16 + 0;
    workWord2 = (int)((unsigned int)workWord3 << 5);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 3);
    workWord2 = workWord2 - workWord3;
    workWord3 = (int)((unsigned int)workWord2 << 2);
    workWord3 = workWord3 - workWord2;
    workWord3 = (int)((unsigned int)workWord3 << 4);
    workWord3 = 0 - workWord3;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 84);
    workWord3 = (workWord3 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 84) = workWord2;
    workWord2 = Level17_7774CApproximatePlanarDistance(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 401;
    if (workWord2 != 0 ? (workWord2 = 0 + 2, 1) : (workWord2 = 0 + 2, 0))
        goto original_80079C70;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 62);
    workWord2 = workWord2 + 40;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    workWord2 = workWord2 < 351;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 != 0)
        goto original_80079C50;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 350;
    Level17_7774CField(privateAddress19, short*, 62) = workWord2;
original_80079C50:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 62);
    __asm__ volatile("" ::: "$2", "memory");
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    fifthArgument = workWord2;
    workWord2 = Level17_7774CResolveMobyYawStep(argumentWord4, argumentWord5, argumentWord6,
                                                argumentWord7, fifthArgument);
    goto original_8007A26C;
original_80079C70:
    Level17_7774CField(ownerAddress21, unsigned char*, 71) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 40);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 9;
    workWord2 = workWord2 + 1;
    Level17_7774CField(privateAddress19, int*, 84) = workWord2;
original_80079C98:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 30;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    Level17_7774CField(privateAddress19, short*, 92) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 9;
original_80079CA8:
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
    goto original_8007A26C;
original_80079CB8:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 21;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
original_80079CC4:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    workWord2 = Level17_7774CReadSelectedFrameScalar(argumentWord4);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 7;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    MATCHING_KEEP4_VOLATILE_CLOBBER(argumentWord4, argumentWord5, argumentWord6, argumentWord7,
                                    "memory");
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = workWord2 + 0;
    workWord2 = Level17_7774CTurnMobyTowardPlayer(argumentWord4, argumentWord5, argumentWord6,
                                                  argumentWord7);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    if (workWord3 == 0)
        goto original_80079D04;
    if (workWord3 == workWord2)
        goto original_80079E7C;
    goto original_8007A26C;
original_80079D04:
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = (int)&Level17_7774C_D_80070328;
    Level17_7774CKeep(savedWord17);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(savedWord17, int*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, 812);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = Level17_7774CField(privateAddress19, short*, 104);
    Level17_7774CKeep(argumentWord6);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 20;
    if (argumentWord6 == 0)
        goto original_80079D44;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + -20;
original_80079D44:
    savedWord16 = workWord2 + workWord3;
    argumentWord4 = privateAddress19 + 68;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord17 + 0;
    workWord2 = (unsigned int)argumentWord6 < 1;
    Level17_7774CField(privateAddress19, short*, 104) = workWord2;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    savedWord16 = savedWord16 & 255;
    savedWord16 = (int)((unsigned int)savedWord16 << 1);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + savedWord16), short*, 0);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(workWord10);
    productAt2443.full = (long long)workWord2 * (long long)workWord10;
    __asm__("" : "=x"(productAt2443.full) : "0"(productAt2443.full));
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 68);
    __asm__ volatile("" : "=x"(productAt2443.full) : "0"(productAt2443.full) : "memory");
    workWord10 = (int)productAt2443.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(privateAddress19, int*, 68) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + savedWord16), short*, 0);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(workWord10);
    productAt2454.full = (long long)workWord2 * (long long)workWord10;
    __asm__("" : "=x"(productAt2454.full) : "0"(productAt2454.full));
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 72);
    __asm__ volatile("" : "=x"(productAt2454.full) : "0"(productAt2454.full) : "memory");
    workWord10 = (int)productAt2454.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(privateAddress19, int*, 72) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, unsigned char*, 73);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    workWord2 = workWord2 + 1;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 68);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 72);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, unsigned char*, 70);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    workWord2 = Level17_7774CSubAngle8(argumentWord4, argumentWord5);
    if (workWord2 >= 0 ? (workWord2 = 0 + 5, 1) : (workWord2 = 0 + 5, 0))
        goto original_80079E24;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 4;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_80079E54;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 4;
    goto original_80079E48;
original_80079E24:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_80079E54;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 5;
original_80079E48:
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_80079E54:
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 68);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 72);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    Level17_7774CField(privateAddress19, unsigned char*, 29) = workWord2;
    goto original_8007A26C;
original_80079E7C:
    workWord2 = savedWord16 + -5;
    workWord2 = (unsigned int)workWord2 < 18;
    if (workWord2 == 0)
        goto original_80079EB4;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 184);
    workWord2 = workWord10 < 12524;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord2 == 0)
        goto original_80079EB4;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 155;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, unsigned char*, 29);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    fifthArgument = 0;
    sixthArgument = workWord3;
    Level17_7774CResolveMobyHeadingStep(argumentWord4, argumentWord5, argumentWord6, argumentWord7,
                                        fifthArgument, sixthArgument);
original_80079EB4:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 164);
    if (workWord2 != 0 ? (workWord2 = 0 + 51, 1) : (workWord2 = 0 + 51, 0))
        goto original_8007A26C;
    Level17_7774CField(privateAddress19, short*, 164) = workWord2;
    goto original_8007A26C;
original_80079ECC:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp70;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = ownerAddress21 + 12;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord16 + 0;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp60;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 88);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord16 + 0;
    workWord2 = workWord2 + 900;
    Level17_7774CField(&originalFrame.sp20, int*, 88) = workWord2;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 152);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 212);
    workWord3 = workWord10 + -80;
    workWord3 = workWord3 + workWord2;
    workWord2 = workWord2 + 1;
    workWord3 = workWord3 & 255;
    workWord3 = (int)((unsigned int)workWord3 << 1);
    Level17_7774CField(privateAddress19, int*, 212) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord3), short*, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 8000;
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(argumentWord5);
    productAt2550.full = (long long)workWord2 * (long long)argumentWord5;
    __asm__("" : "=x"(productAt2550.full) : "0"(productAt2550.full));
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 64);
    __asm__ volatile(""
                     : "=x"(productAt2550.full)
                     : "0"(productAt2550.full), "m"(originalFrame.sp60)
                     : "memory");
    workWord10 = (int)productAt2550.words.low;
    Level17_7774CKeep(workWord10);
    argumentWord4 = (workWord10 >> 12);
    workWord2 = workWord2 + argumentWord4;
    Level17_7774CField(&originalFrame.sp20, int*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord3), short*, 0);
    Level17_7774CKeep(workWord2);
    Level17_7774CKeep(argumentWord5);
    productAt2560.full = (long long)workWord2 * (long long)argumentWord5;
    __asm__("" : "=x"(productAt2560.full) : "0"(productAt2560.full));
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = 0 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 72);
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = (int)&originalFrame.sp90;
    workWord2 = workWord2 + 2500;
    Level17_7774CField(&originalFrame.sp20, int*, 72) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 68);
    __asm__ volatile(""
                     : "=x"(productAt2560.full)
                     : "0"(productAt2560.full), "m"(originalFrame.sp64)
                     : "memory");
    workWord10 = (int)productAt2560.words.low;
    Level17_7774CKeep(workWord10);
    workWord3 = (workWord10 >> 12);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(&originalFrame.sp20, int*, 68) = workWord2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    do {
    original_80079F7C:
        __asm__ volatile("" ::: "$5", "memory");
        argumentWord5 = 0 + 150;
        workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = savedWord18 + 0;
        __asm__ volatile("" ::: "$5", "memory");
        argumentWord5 = ownerAddress21 + 12;
        savedWord16 = workWord2 + 850;
        Level17_7774CCopyVector(argumentWord4, argumentWord5);
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = 0 + 0;
        __asm__ volatile("" ::: "$2", "memory");
        workWord2 = Level17_7774CField(privateAddress19, int*, 100);
        __asm__ volatile("" ::: "$5", "memory");
        argumentWord5 = 0 + 7;
        Level17_7774CField(&originalFrame.sp20, int*, 120) = workWord2;
        workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
        workWord2 = savedWord17 + workWord2;
        workWord2 = workWord2 & 255;
        workWord2 = (int)((unsigned int)workWord2 << 1);
        __asm__ volatile("" ::: "$3", "memory");
        workWord3 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
        Level17_7774CKeep(workWord3);
        Level17_7774CKeep(savedWord16);
        productAt2590.full = (long long)workWord3 * (long long)savedWord16;
        __asm__("" : "=x"(productAt2590.full) : "0"(productAt2590.full));
        __asm__ volatile("" ::: "$3", "memory");
        workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 112);
        __asm__ volatile(""
                         : "=x"(productAt2590.full)
                         : "0"(productAt2590.full), "m"(originalFrame.sp90)
                         : "memory");
        workWord10 = (int)productAt2590.words.low;
        Level17_7774CKeep(workWord10);
        argumentWord4 = (workWord10 >> 12);
        workWord3 = workWord3 + argumentWord4;
        Level17_7774CField(&originalFrame.sp20, int*, 112) = workWord3;
        workWord2 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
        Level17_7774CKeep(workWord2);
        Level17_7774CKeep(savedWord16);
        productAt2600.full = (long long)workWord2 * (long long)savedWord16;
        __asm__("" : "=x"(productAt2600.full) : "0"(productAt2600.full));
        __asm__ volatile("" ::: "$5", "memory");
        argumentWord5 = 0 + 50;
        savedWord17 = savedWord17 + 8;
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = 0 + 35;
        Level17_7774CField(&originalFrame.sp20, int*, 128) = 0;
        Level17_7774CField(&originalFrame.sp20, int*, 132) = 0;
        __asm__ volatile("" ::: "$2", "memory");
        workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 116);
        __asm__ volatile(""
                         : "=x"(productAt2600.full)
                         : "0"(productAt2600.full), "m"(originalFrame.sp94)
                         : "memory");
        workWord10 = (int)productAt2600.words.low;
        Level17_7774CKeep(workWord10);
        workWord3 = (workWord10 >> 12);
        workWord2 = workWord2 + workWord3;
        Level17_7774CField(&originalFrame.sp20, int*, 116) = workWord2;
        workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = 0 + 1;
        __asm__ volatile("" ::: "$5", "memory");
        argumentWord5 = 0 + 13;
        __asm__ volatile("" ::: "$6", "memory");
        argumentWord6 = savedWord18 + 0;
        __asm__ volatile("" ::: "$3", "memory");
        workWord3 = (int)0x80070000U;
        Level17_7774CKeep(workWord3);
        workWord3 = Level17_7774CField(workWord3, int*, 17124);
        do {
            __asm__ volatile("" ::: "$7", "memory");
            argumentWord7 = (int)&originalFrame.spA0;
            Level17_7774CField(&originalFrame.sp20, int*, 136) = workWord2;
            ((int (*)(int, int, int, int))workWord3)(argumentWord4, argumentWord5, argumentWord6,
                                                     argumentWord7);
        } while (0);
        __asm__ volatile("" ::: "$22", "memory");
        savedWord22 = (int)&Level17_7774C_D_80065920;
        Level17_7774CKeep(savedWord22);
        __asm__ volatile("" ::: "$23", "memory");
        savedWord23 = (int)&Level17_7774C_D_800658A0;
        Level17_7774CKeep(savedWord23);
        workWord2 = savedWord17 < 256;
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = 0 + 0;
        if (workWord2 != 0)
            goto original_80079F7C;
        __asm__ volatile("" ::: "$3", "memory");
        workWord3 = Level17_7774CField(privateAddress19, int*, 204);
        __asm__ volatile("" ::: "$2", "memory");
        workWord2 = 0 + 1;
        if (workWord3 == 0)
            goto original_8007A078;
        __asm__ volatile("" ::: "$4", "memory");
        argumentWord4 = (int)&originalFrame.sp60;
        if (workWord3 == workWord2)
            goto original_8007A138;
        goto original_8007A26C;
    } while (0);
original_8007A078:
    argumentWord4 = privateAddress19 + 208;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)&originalFrame.sp60;
    if (workWord2 != workWord3)
        goto original_8007A0B4;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)&originalFrame.sp70;
    Level17_7774CPrepareCameraMode9Vectors(argumentWord4, argumentWord5);
    workWord3 = (int)&Level17_7774C_D_80070328 + 640;
    Level17_7774CKeep(workWord3);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(workWord3, int*, 0);
    if (workWord2 >= 0)
        goto original_8007A0B4;
    Level17_7774CField(workWord3, int*, 0) = 0;
original_8007A0B4:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -8120);
    workWord2 = workWord2 & 1;
    if (workWord2 == 0 ? ({
            workWord2 = (int)0x10000000U;
            Level17_7774CKeep(workWord2);
            1;
        })
                       : ({
                             workWord2 = (int)0x10000000U;
                             Level17_7774CKeep(workWord2);
                             0;
                         }))
        goto original_8007A26C;
    workWord2 = workWord2 | 32768;
    argumentWord4 = (int)&Level17_7774C_D_80070328 + 524;
    Level17_7774CKeep(argumentWord4);
    Level17_7774CField(argumentWord4, int*, 0) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord2, int*, 12);
    argumentWord4 = argumentWord4 + 32;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    argumentWord5 = (int)&Level17_7774C_D_80070328 + 12;
    Level17_7774CKeep(argumentWord5);
    argumentWord4 = (int)&Level17_7774C_D_80070328 + 552;
    Level17_7774CKeep(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(argumentWord5, signed char*, 0);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(argumentWord5, signed char*, 1);
    Level17_7774CField(argumentWord4, unsigned char*, 0) = workWord2;
    Level17_7774CField(argumentWord4, unsigned char*, 1) = workWord3;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(argumentWord5, signed char*, 2);
    Level17_7774CField(argumentWord4, unsigned char*, 2) = workWord2;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 572, int*, 0) = 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 204);
    workWord2 = workWord2 + 1;
    Level17_7774CField(privateAddress19, int*, 204) = workWord2;
    goto original_8007A26C;
original_8007A138:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)&originalFrame.sp70;
    Level17_7774CPrepareCameraMode9Vectors(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 132;
    if (workWord2 == 0)
        goto original_8007A26C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 17120);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = ownerAddress21 + 0;
    workWord2 = ((int (*)(int, int))workWord2)(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$20", "memory");
    savedWord20 = workWord2 + 0;
    Level17_7774CKeep(savedWord20);
    savedWord16 = savedWord20 + 12;
    if (savedWord20 == 0)
        goto original_8007A248;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, int*, 36);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(workWord2, int*, 12);
    __asm__ volatile("" ::: "$18", "memory");
    savedWord18 = Level17_7774CField(savedWord20, int*, 0);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord16 + 0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(savedWord20, int*, 20);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 8192;
    workWord2 = workWord2 + 500;
    Level17_7774CField(savedWord20, int*, 20) = workWord2;
    workWord2 = Level17_7774CQueryWorldHeight(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$17", "memory");
    savedWord17 = (int)&originalFrame.spA0;
    Level17_7774CKeep(savedWord17);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord17 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = savedWord16 + 0;
    Level17_7774CField(savedWord20, int*, 20) = workWord2;
    Level17_7774CField(savedWord18, short*, 0) = 0;
    __asm__ volatile("" ::: "$16", "memory");
    savedWord16 = Level17_7774CField(savedWord20, unsigned char*, 70);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField(savedWord20, unsigned char*, 72) = workWord2;
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = savedWord17 + 0;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    savedWord16 = (int)((unsigned int)savedWord16 << 1);
    workWord2 = savedWord16 + savedWord22;
    Level17_7774CKeep(workWord2);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(workWord2, short*, 0);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, 876);
    workWord2 = (int)((unsigned int)workWord3 << 2);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 3);
    workWord2 = workWord2 - workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 128);
    workWord2 = (workWord2 >> 6);
    workWord3 = workWord3 + workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(&originalFrame.sp20, int*, 136);
    savedWord16 = savedWord16 + savedWord23;
    Level17_7774CField(&originalFrame.sp20, int*, 128) = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(savedWord16, short*, 0);
    workWord2 = workWord2 + argumentWord5;
    Level17_7774CField(&originalFrame.sp20, int*, 136) = workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 2);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 3);
    workWord2 = workWord2 - workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(&originalFrame.sp20, int*, 132);
    workWord2 = (workWord2 >> 6);
    workWord3 = workWord3 + workWord2;
    Level17_7774CField(&originalFrame.sp20, int*, 132) = workWord3;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(savedWord20, unsigned char*, 70);
    __asm__ volatile("" ::: "$7", "memory");
    argumentWord7 = 0 + 0;
    argumentWord5 = argumentWord5 + 128;
    Level17_7774CSetCameraMode11Target(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
original_8007A248:
    Level17_7774CField((int)&Level17_7774C_D_8006C408, unsigned char*, 0) = 0;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    Level17_7774CDeleteMoby(argumentWord4);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    Level17_7774CField((int)&Level17_7774C_D_8007158C, unsigned char*, 0) = workWord2;
    goto originalReturn;
original_8007A26C:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, unsigned short*, 164);
    workWord2 = argumentWord4 + -51;
    argumentWord5 = (unsigned int)workWord2 < 2;
    Level17_7774CKeep(argumentWord4);
    if (argumentWord5 != 0)
        goto original_8007A294;
    workWord2 = (int)((unsigned int)argumentWord4 << 16);
    workWord2 = (workWord2 >> 16);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 53;
    if (workWord2 != workWord3)
        goto original_8007A5CC;
original_8007A294:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 50;
    if (workWord3 == workWord2)
        goto original_8007A5CC;
    workWord2 = (int)((unsigned int)argumentWord4 << 16);
    if (argumentWord5 == 0)
        goto original_8007A544;
    workWord2 = (workWord2 >> 16);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = 0 + 51;
    if (workWord2 != workWord3 ? (workWord2 = 0 + 53, 1) : (workWord2 = 0 + 53, 0))
        goto original_8007A2C0;
    Level17_7774CField(privateAddress19, short*, 164) = workWord2;
original_8007A2C0:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 192);
    workWord2 = workWord10 < 7;
    if (workWord2 != 0 ? (workWord2 = workWord10 < 2, 1) : (workWord2 = workWord10 < 2, 0))
        goto original_8007A2F0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 64);
    workWord2 = workWord2 < 60;
    if (workWord2 == 0 ? (workWord2 = 0 + 60, 1) : (workWord2 = 0 + 60, 0))
        goto original_8007A32C;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    goto original_8007A32C;
original_8007A2F0:
    if (workWord2 != 0)
        goto original_8007A314;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 64);
    workWord2 = workWord2 < 40;
    if (workWord2 == 0 ? (workWord2 = 0 + 40, 1) : (workWord2 = 0 + 40, 0))
        goto original_8007A32C;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
    goto original_8007A32C;
original_8007A314:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, short*, 64);
    workWord2 = workWord2 < 30;
    if (workWord2 == 0 ? (workWord2 = 0 + 30, 1) : (workWord2 = 0 + 30, 0))
        goto original_8007A32C;
    Level17_7774CField(privateAddress19, short*, 64) = workWord2;
original_8007A32C:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 40);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 15;
    Level17_7774CField(privateAddress19, short*, 166) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 1;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 2, 1) : (workWord2 = 0 + 2, 0))
        goto original_8007A354;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    if (workWord3 == workWord2)
        goto original_8007A418;
    goto original_8007A4D4;
original_8007A354:
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = 0 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 100;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, short*, 108);
    Level17_7774CField(privateAddress19, volatile short*, 162) = workWord2;
    workWord3 = (int)((unsigned int)argumentWord4 << 4);
    workWord3 = workWord3 - argumentWord4;
    workWord3 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(privateAddress19, volatile short*, 162) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    workWord2 = workWord2 < 31;
    if (workWord2 != 0)
        goto original_8007A404;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 8192;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_8007A404;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, -8160);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, -8156);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, unsigned short*, -8128);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    argumentWord4 = (int)((unsigned int)argumentWord4 << 16);
    argumentWord4 = (argumentWord4 >> 20);
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 24;
    if (workWord2 == 0 ? (workWord2 = 0 + 120, 1) : (workWord2 = 0 + 120, 0))
        goto original_8007A404;
    Level17_7774CField(privateAddress19, volatile short*, 110) = 0;
    Level17_7774CField(privateAddress19, short*, 110) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 16;
    Level17_7774CField(privateAddress19, short*, 108) = 0;
    Level17_7774CField(privateAddress19, short*, 166) = workWord2;
    goto original_8007A4D4;
original_8007A404:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 108);
    workWord2 = workWord2 + 1;
    Level17_7774CField(privateAddress19, short*, 108) = workWord2;
    goto original_8007A4D4;
original_8007A418:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 100;
    workWord2 = Level17_7774CRandBetween(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(privateAddress19, short*, 112);
    Level17_7774CField(privateAddress19, volatile short*, 162) = workWord2;
    workWord3 = (int)((unsigned int)argumentWord4 << 4);
    workWord3 = workWord3 - argumentWord4;
    workWord3 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    Level17_7774CField(privateAddress19, volatile short*, 162) = workWord2;
    workWord2 = (int)((unsigned int)workWord2 << 16);
    workWord2 = (workWord2 >> 16);
    workWord2 = workWord2 < 31;
    if (workWord2 != 0)
        goto original_8007A4C4;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 168);
    workWord2 = workWord10 < 8192;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord2 == 0)
        goto original_8007A4C4;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, int*, -8160);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(ownerAddress21, int*, 16);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord5);
    argumentWord5 = Level17_7774CField(argumentWord5, int*, -8156);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = (int)0x80070000U;
    Level17_7774CKeep(argumentWord4);
    argumentWord4 = Level17_7774CField(argumentWord4, unsigned short*, -8128);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = workWord2 + 0;
    argumentWord4 = (int)((unsigned int)argumentWord4 << 16);
    argumentWord4 = (argumentWord4 >> 20);
    workWord2 = Level17_7774CAbsoluteByteAngleDelta(argumentWord4, argumentWord5);
    workWord2 = workWord2 < 24;
    if (workWord2 == 0 ? (workWord2 = 0 + 3, 1) : (workWord2 = 0 + 3, 0))
        goto original_8007A4C4;
    Level17_7774CField(privateAddress19, short*, 140) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    Level17_7774CField(privateAddress19, short*, 114) = 0;
    Level17_7774CField(privateAddress19, short*, 112) = 0;
    Level17_7774CField(privateAddress19, short*, 166) = workWord2;
    goto original_8007A4D4;
original_8007A4C4:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 112);
    workWord2 = workWord2 + 1;
    Level17_7774CField(privateAddress19, short*, 112) = workWord2;
original_8007A4D4:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 166);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 15;
    if (workWord3 == workWord2 ? (workWord2 = 0 + 21, 1) : (workWord2 = 0 + 21, 0))
        goto original_8007A544;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
    argumentWord4 = privateAddress19 + 144;
    if (workWord3 != workWord2)
        goto original_8007A4FC;
    argumentWord5 = privateAddress19 + 68;
    goto original_8007A500;
original_8007A4FC:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = ownerAddress21 + 12;
original_8007A500:
    Level17_7774CCopyVector(argumentWord4, argumentWord5);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 2;
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    workWord2 = Level17_7774CPlayMobySoundEvent(argumentWord4, argumentWord5, argumentWord6);
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 166);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 300;
    Level17_7774CField(privateAddress19, int*, 156) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 16;
    if (workWord3 != workWord2)
        goto original_8007A53C;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 110);
    workWord2 = workWord2 + 60;
    goto original_8007A540;
original_8007A53C:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 90;
original_8007A540:
    Level17_7774CField(privateAddress19, short*, 160) = workWord2;
original_8007A544:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 164);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 52;
    if (workWord3 == workWord2)
        goto original_8007A568;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, -14480);
    if (workWord2 == 0)
        goto original_8007A5CC;
original_8007A568:
    Level17_7774CField(privateAddress19, short*, 164) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 73) = 0;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, short*, 166);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 16;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = workWord3 + 0;
    if (workWord3 != workWord2)
        goto original_8007A5BC;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 61);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 10;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_8007A5B0;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 114;
    Level17_7774CField((int)&Level17_7774C_D_8006C770, int*, 0) = 0;
    Level17_7774CField(ownerAddress21, unsigned char*, 64) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 10;
    Level17_7774CField(ownerAddress21, unsigned char*, 61) = workWord2;
    Level17_7774CField(ownerAddress21, unsigned char*, 63) = 0;
    Level17_7774CEmptyAnimationTransitionHook(argumentWord4);
original_8007A5B0:
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = Level17_7774CField(privateAddress19, unsigned short*, 166);
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = workWord2;
    goto original_8007A5CC;
original_8007A5BC:
    Level17_7774CField(ownerAddress21, unsigned char*, 72) = argumentWord4;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(privateAddress19, short*, 166);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    Level17_7774CRequestMobyAnimation(argumentWord4, argumentWord5);
original_8007A5CC:
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 144);
    __asm__ volatile("" ::: "$6", "memory");
    argumentWord6 = 0 + 0;
    if (workWord10 == 0)
        goto original_8007A6F0;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 808);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(ownerAddress21, int*, 12);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = (int)0x80070000U;
    Level17_7774CKeep(workWord2);
    workWord2 = Level17_7774CField(workWord2, int*, 812);
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = Level17_7774CField(ownerAddress21, int*, 16);
    argumentWord4 = workWord3 - argumentWord4;
    argumentWord5 = workWord2 - argumentWord5;
    workWord2 = Level17_7774CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
    workWord2 = workWord2 & 255;
    workWord2 = (int)((unsigned int)workWord2 << 1);
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = Level17_7774CField(((int)&Level17_7774C_D_80065920 + workWord2), short*, 0);
    workWord3 = (int)((unsigned int)argumentWord4 << 1);
    workWord3 = workWord3 + argumentWord4;
    workWord3 = (int)((unsigned int)workWord3 << 3);
    workWord3 = workWord3 + argumentWord4;
    workWord3 = (workWord3 >> 10);
    Level17_7774CResident_D_80070328_540_int = workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(((int)&Level17_7774C_D_800658A0 + workWord2), short*, 0);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 30;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 548, int*, 0) = workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    workWord2 = (int)((unsigned int)workWord2 << 3);
    workWord2 = workWord2 + workWord3;
    workWord2 = (workWord2 >> 10);
    Level17_7774CResident_D_80070328_544_int = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 25;
    Level17_7774CField(privateAddress19, int*, 80) = workWord2;
    __asm__ volatile("" ::: "$10", "memory");
    workWord10 = Level17_7774CField(&originalFrame.sp20, int*, 144);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    if (workWord10 != workWord2)
        goto original_8007A704;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 1348);
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    workWord3 = (int)((unsigned int)workWord2 >> 31);
    workWord2 = workWord2 + workWord3;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = (int)0x80070000U;
    Level17_7774CKeep(workWord3);
    workWord3 = Level17_7774CField(workWord3, int*, 1352);
    workWord2 = (workWord2 >> 1);
    Level17_7774CResident_D_80070328_540_int = workWord2;
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    workWord3 = (int)((unsigned int)workWord2 >> 31);
    workWord2 = workWord2 + workWord3;
    workWord2 = (workWord2 >> 1);
    Level17_7774CResident_D_80070328_544_int = workWord2;
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(privateAddress19, int*, 80);
    workWord2 = (int)((unsigned int)workWord3 << 1);
    workWord2 = workWord2 + workWord3;
    workWord3 = (int)((unsigned int)workWord2 >> 31);
    workWord2 = workWord2 + workWord3;
    workWord2 = (workWord2 >> 1);
    Level17_7774CField(privateAddress19, int*, 80) = workWord2;
    goto original_8007A704;
original_8007A6F0:
    argumentWord4 = privateAddress19 + 80;
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 4;
    workWord2 = Level17_7774CCountTimerDown(argumentWord4, argumentWord5);
    if (workWord2 != 0)
        goto original_8007A720;
original_8007A704:
    workWord2 = (int)0x10000000U;
original_8007A708:
    workWord2 = workWord2 | 1152;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 524, int*, 0) = workWord2;
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 7;
    Level17_7774CField((int)&Level17_7774C_D_80070328 + 572, int*, 0) = workWord2;
original_8007A720:
    __asm__ volatile("" ::: "$3", "memory");
    workWord3 = Level17_7774CField(ownerAddress21, unsigned char*, 72);
    __asm__ volatile("" ::: "$2", "memory");
    workWord2 = 0 + 2;
    __asm__ volatile("" ::: "$4", "memory");
    argumentWord4 = ownerAddress21 + 0;
    if (workWord3 == workWord2)
        goto original_8007A734;
    Level17_7774CField(ownerAddress21, int*, 24) = 0;
original_8007A734:
    __asm__ volatile("" ::: "$5", "memory");
    argumentWord5 = 0 + 5;
    Level17_7774CRefreshMobySpatialGridAndBasis(argumentWord4, argumentWord5);
originalReturn:
    return;
}
#undef Level17_7774CField
#undef Level17_7774CKeep


/**
 * MobyUpdate_488() - func_level_17_8007A770()
 * Sheila
 * TODO
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007A770.
* Assembly SHA256 c1d2cbb6f15afd4b430d6c39ddb153d89d4e6c67d92e47e0a67f7bcd692c8ff1.
* AI generated; not human reviewed. All741 instructions,7 selectors and
* one original zero padding word require exact native/linked identity and
* actual branch/call/table targets. Frame78 retains S0..S6/RA and SP38..57.
* Entry preserves separate source-coordinate and index-times88 producers.
* The text cursor consumes unsigned BYTES and advances by one BYTE. Its
* polynomial80050000 and mask000FFFF0 are full initialized original words.
* Four player-byte accesses retain distinct absolute symbol-plus-offset
* views, original XOR1, flag-clear ordering and original CRC reset.
* Raw signed result clamps32/10 and both absolute-value paths preserve
* every producer and original delay slot. The nonnegative arm precedes
* the negative arm; the initialized negative V0 identity retains NEG V0,V0.
* Old record fields are consumed before S0 becomes the55E84 result.
* Original state20 timer-store/increment joins occur after substate5.
* Late owner states retain distinct S2/S1 archive bases and exact shared
* byte-helper entries. Empty initialized identities,late inputs and dead
* clobbers emit zero CPU instructions. No opcode assembly,partialHI,
* fixedFP or live fixed-register alias overlap. Binary identity is the
* confidence claim. Units/fixed point, complete helper contracts, caller
* cadence and synchronized retail runtime remain open. Per invocation is
* the recorded cadence. Falsification:all native/linked words and targets,
* original data bytes,complete EXE and every overlay retail hash. */
#define Actor17_7A770Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Actor17_7A770RequestMobyAnimationView1() __asm__("func_80034F40");
void Actor17_7A770EmptyAnimationTransitionHookView1() __asm__("func_80035734");
int Actor17_7A770TurnMobyTowardHeadingView1() __asm__("func_8003585C");
int Actor17_7A770ResolveMobyYawStepView1() __asm__("func_80035DDC");
int Actor17_7A770ResolveMobyHeadingStepView1() __asm__("func_80035EE0");
int Actor17_7A770SubAngle8View1() __asm__("func_8003613C");
int Actor17_7A770UpdateEffectConfigurationView1() __asm__("func_80037A60");
int Actor17_7A770UpdateMobyInteractionGateView1() __asm__("func_80037BBC");
int Actor17_7A770RegisterTrackedValueView1() __asm__("func_8003B7B4");
int Actor17_7A770PlanarHeadingLookupView1() __asm__("func_8004E880");
int Actor17_7A770CopyVectorView1() __asm__("func_8004F178");
int Actor17_7A770ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Actor17_7A770StartDialogueView1() __asm__("func_800512E4");
int Actor17_7A770ReadSelectedFrameScalarView1() __asm__("func_80055E84");
extern int Actor17_7A770Data658A0View1 __asm__("D_800658A0");
extern int Actor17_7A770Data65920View1 __asm__("D_80065920");
extern int Actor17_7A770Data6C550View1 __asm__("D_8006C550");
extern int Actor17_7A770Data6C598View1 __asm__("D_8006C598");
extern int Actor17_7A770Data6C770View1 __asm__("D_8006C770");
extern int Actor17_7A770Data6C7F8View1 __asm__("D_8006C7F8");
extern int Actor17_7A770Data6D088View1 __asm__("D_8006D088");
extern int Actor17_7A770Data6E344View1 __asm__("D_8006E344");
extern unsigned char Actor17_7A770Data70300View1 __asm__("D_80070300+2");
extern unsigned char Actor17_7A770Data70300View2 __asm__("D_80070300+3");
extern unsigned char Actor17_7A770Data70300View3 __asm__("D_80070300+4");
extern unsigned char Actor17_7A770Data70300View4 __asm__("D_80070300+1");
extern int Actor17_7A770Data70300View5 __asm__("D_80070300");
extern signed char Actor17_7A770Data71586View1 __asm__("D_80071586");
extern int Actor17_7A770Data722B8View1 __asm__("D_800722B8");
extern int Actor17_7A770Call3A40CView1 __asm__("func_8003A40C");
extern int Actor17_7A770Call3A584View1 __asm__("func_8003A584");
extern int Actor17_7A770Data74438View1 __asm__("unk_ovlheader_80074438");
extern int (*Actor17_7A770Data74314View1)() __asm__("unk_ovlheader_80074314");
void func_level_17_8007A770(void* input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord6 __asm__("$6"),
        argumentWord7 __asm__("$7"), recordAddressOrResult16 __asm__("$16"),
        retainedResult20 __asm__("$20");
    register void* ownerRecord19 __asm__("$19");
    register int privateRecordOrArchiveBase17 __asm__("$17"), firstResult22 __asm__("$22"),
        firstResultByte21 __asm__("$21"), distanceOrArchiveBase18 __asm__("$18"),
        polynomialMaskOrArgument5 __asm__("$5"), counterOrArgument4 __asm__("$4");
    int absoluteResult;
    struct {
        int sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54;
    } originalFrame;
    int* temporaryWord6;
    int* temporaryWord7;
    int* temporaryWord8;
    int* temporaryWord9;
    int* temporaryWord11;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord10;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord12;
    int temporaryWord13;
    ownerRecord19 = input;
    MATCHING_KEEP(ownerRecord19);
    privateRecordOrArchiveBase17 = Actor17_7A770Field(ownerRecord19, void**, 0);
    rawWord2 = Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C);
    argumentWord6 = 0;
    rawWord3 = Actor17_7A770Field(rawWord2, void**, 12);
    rawWord2 = Actor17_7A770Field(ownerRecord19, int*, 12);
    counterOrArgument4 = Actor17_7A770Field(rawWord3, int*, 0);
    polynomialMaskOrArgument5 = Actor17_7A770Field(rawWord3, int*, 4);
    counterOrArgument4 = rawWord2 - counterOrArgument4;
    rawWord2 = Actor17_7A770Field(ownerRecord19, int*, 16);
    rawWord3 = Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x30);
    polynomialMaskOrArgument5 = rawWord2 - polynomialMaskOrArgument5;
    rawWord2 = rawWord3 * 3;
    rawWord2 <<= 2;
    rawWord2 -= rawWord3;
    rawWord3 = Actor17_7A770Data6C550View1;
    rawWord2 <<= 3;
    recordAddressOrResult16 = rawWord3 + rawWord2;
    firstResult22 = Actor17_7A770PlanarHeadingLookupView1(counterOrArgument4,
                                                          polynomialMaskOrArgument5, argumentWord6);
    if (Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x40) == 0) {
        Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x40) = &Actor17_7A770Call3A40CView1;
    }
    counterOrArgument4 = 0;
    if ((unsigned int)Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x40) <
        (unsigned int)&Actor17_7A770Call3A584View1) {
        polynomialMaskOrArgument5 = 0x80050000;
        MATCHING_KEEP(polynomialMaskOrArgument5);
        Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x3C) =
            (int)(Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x3C) ^
                  (Actor17_7A770Field(Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x40),
                                      unsigned char*, 0)
                   << 0x18));
        do {
            temporaryWord5 = Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x3C);
            if (temporaryWord5 < 0) {
                temporaryWord15 = (temporaryWord5 * 2) ^ polynomialMaskOrArgument5;
            } else {
                temporaryWord15 = temporaryWord5 * 2;
            }
            Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x3C) = temporaryWord15;
            counterOrArgument4 += 1;
        } while (counterOrArgument4 < 8);
        Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x40) =
            (Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x40) + 1);
    } else {
        polynomialMaskOrArgument5 = 0xFFFF0;
        MATCHING_KEEP(polynomialMaskOrArgument5);
        if (((((int)Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x3C) >> 0xC) &
              polynomialMaskOrArgument5) |
             (Actor17_7A770Data722B8View1 & 0xFFF0000F)) != Actor17_7A770Data74438View1) {
            rawWord2 = Actor17_7A770Data70300View4;
            rawWord2 ^= 1;
            Actor17_7A770Data71586View1 = 0;
            Actor17_7A770Data70300View4 = rawWord2;
            Actor17_7A770Data70300View1 = (unsigned char)(Actor17_7A770Data70300View1 ^ 1);
            Actor17_7A770Data70300View2 = (unsigned char)(Actor17_7A770Data70300View2 ^ 1);
            Actor17_7A770Data70300View3 = (unsigned char)(Actor17_7A770Data70300View3 ^ 1);
            Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x3C) = 0;
        }
    }
    temporaryWord12 = Actor17_7A770Field(ownerRecord19, unsigned char*, 0x48);
    switch (temporaryWord12) {
        case 0:
            temporaryWord2 = Actor17_7A770Field(recordAddressOrResult16, int*, 0xC);
            temporaryWord6 = Actor17_7A770Field(
                Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C), int**, 0xC);
            retainedResult20 = Actor17_7A770PlanarHeadingLookupView1(
                temporaryWord2 - Actor17_7A770Field(temporaryWord6, int*, 0),
                Actor17_7A770Field(recordAddressOrResult16, int*, 0x10) -
                    Actor17_7A770Field(temporaryWord6, int*, 4),
                0, temporaryWord2);
            firstResultByte21 = firstResult22 & 0xFF;
            rawWord2 = Actor17_7A770SubAngle8View1(retainedResult20 & 255, firstResultByte21);
            rawWord3 = Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x2C);
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2) : "$16");
            recordAddressOrResult16 = rawWord2;
            polynomialMaskOrArgument5 = Actor17_7A770Field(rawWord3, int*, 12);
            __asm__(""
                    : "=r"(recordAddressOrResult16)
                    : "0"(recordAddressOrResult16), "r"(polynomialMaskOrArgument5));
            distanceOrArchiveBase18 = Actor17_7A770ApproximatePlanarDistanceView1(
                                          ownerRecord19 + 12, polynomialMaskOrArgument5) -
                                      0x2C00;
            if (distanceOrArchiveBase18 < 0) {
                distanceOrArchiveBase18 = -distanceOrArchiveBase18;
            }
            rawWord2 = recordAddressOrResult16 * 2;
            if (recordAddressOrResult16 == 0) {
                recordAddressOrResult16 = 1;
                MATCHING_KEEP(recordAddressOrResult16);
                rawWord2 = recordAddressOrResult16 * 2;
            }
            recordAddressOrResult16 =
                (((rawWord2 + recordAddressOrResult16) * 8) + recordAddressOrResult16) * 4;
            rawWord2 = recordAddressOrResult16 < 33;
            if (rawWord2)
                goto joinRawResultClamp32;
            recordAddressOrResult16 = 32;
            MATCHING_KEEP(recordAddressOrResult16);
        joinRawResultClamp32:
            rawWord2 = recordAddressOrResult16 < -32;
            argumentWord7 = retainedResult20 + recordAddressOrResult16;
            if (rawWord2 != 0) {
                recordAddressOrResult16 = -0x20;
                MATCHING_KEEP(recordAddressOrResult16);
                argumentWord7 = retainedResult20 + recordAddressOrResult16;
            }
            recordAddressOrResult16 =
                Actor17_7A770SubAngle8View1(argumentWord7 & 0xFF, firstResultByte21);
            MATCHING_KEEP(recordAddressOrResult16);
            absoluteResult = recordAddressOrResult16;
            if (recordAddressOrResult16 < 0) {
                absoluteResult = -absoluteResult;
            }
            if (absoluteResult >= 9 || distanceOrArchiveBase18 >= 701 ||
                Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) == 1) {
                if (recordAddressOrResult16 >= 0) {
                    rawWord2 = recordAddressOrResult16;
                } else {
                    rawWord2 = recordAddressOrResult16;
                    MATCHING_KEEP(rawWord2);
                    rawWord2 = -rawWord2;
                }
                if ((rawWord2 < 4) && (rawWord2 = distanceOrArchiveBase18 < 0x200, rawWord2)) {
                    if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 0) {
                        counterOrArgument4 = (int)ownerRecord19;
                        MATCHING_KEEP(counterOrArgument4);
                        Actor17_7A770Data6C770View1 = 0;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 0U;
                        goto clearByteAndCall35734;
                    }
                } else if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 1) {
                    counterOrArgument4 = (int)ownerRecord19;
                    MATCHING_KEEP(counterOrArgument4);
                    Actor17_7A770Data6C770View1 = 0;
                    Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                    Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 1U;
                clearByteAndCall35734:
                    Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                    Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                }
                rawWord2 = recordAddressOrResult16 < 11;
                if (rawWord2)
                    goto joinRawResultClamp10;
                recordAddressOrResult16 = 10;
                MATCHING_KEEP(recordAddressOrResult16);
            joinRawResultClamp10:
                rawWord2 = recordAddressOrResult16 < -10;
                argumentWord7 = firstResult22 - recordAddressOrResult16;
                if (rawWord2 != 0) {
                    recordAddressOrResult16 = -0xA;
                    MATCHING_KEEP(recordAddressOrResult16);
                    argumentWord7 = firstResult22 - recordAddressOrResult16;
                }
                Actor17_7A770Data74314View1(
                    ownerRecord19,
                    Actor17_7A770Field(
                        Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C), int**, 0xC),
                    0x2C00, argumentWord7 & 0xFF, 4, 0xB4, 7, 0x80, 0xFF, 0xFF, 0, 0, 1);
            } else {
                temporaryWord7 = Actor17_7A770Field(
                    Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C), int**, 0xC);
                Actor17_7A770TurnMobyTowardHeadingView1(
                    ownerRecord19,
                    Actor17_7A770PlanarHeadingLookupView1(
                        Actor17_7A770Field(temporaryWord7, int*, 0) -
                            Actor17_7A770Field(ownerRecord19, int*, 0xC),
                        Actor17_7A770Field(temporaryWord7, int*, 4) -
                            Actor17_7A770Field(ownerRecord19, int*, 0x10),
                        0),
                    7, 0, 0, 0);
            }
            if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49) != 0) {
                Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49) = 0U;
                if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 1) {
                    counterOrArgument4 = (int)ownerRecord19;
                    MATCHING_KEEP(counterOrArgument4);
                    Actor17_7A770Data6C770View1 = 0;
                    Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                    Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 1U;
                    Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                    Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                }
                rawWord2 = 0x14;
            storeOwnerState:
                Actor17_7A770Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
            }
        default:
            return;
        case 20:
            temporaryWord13 = Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49);
            switch (temporaryWord13) {
                case 0:
                    temporaryWord3 = Actor17_7A770Field(recordAddressOrResult16, int*, 0xC);
                    temporaryWord8 = Actor17_7A770Field(
                        Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C), int**, 0xC);
                    rawWord2 = Actor17_7A770PlanarHeadingLookupView1(
                        temporaryWord3 - Actor17_7A770Field(temporaryWord8, int*, 0),
                        Actor17_7A770Field(recordAddressOrResult16, int*, 0x10) -
                            Actor17_7A770Field(temporaryWord8, int*, 4),
                        0, temporaryWord3);
                    rawWord3 = Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x2C);
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2) : "$4", "$16");
                    counterOrArgument4 = (int)&originalFrame.sp38;
                    polynomialMaskOrArgument5 = Actor17_7A770Field(rawWord3, int*, 12);
                    __asm__(""
                            : "=r"(counterOrArgument4)
                            : "0"(counterOrArgument4), "r"(polynomialMaskOrArgument5)
                            : "$16");
                    recordAddressOrResult16 = rawWord2;
                    Actor17_7A770CopyVectorView1(counterOrArgument4, polynomialMaskOrArgument5);
                    recordAddressOrResult16 = (recordAddressOrResult16 & 0xFF) * 2;
                    temporaryWord4 = originalFrame.sp38 +
                                     ((int)(Actor17_7A770Field(&Actor17_7A770Data65920View1, short*,
                                                               recordAddressOrResult16) *
                                            0x5F5) >>
                                      9);
                    originalFrame.sp38 = temporaryWord4;
                    temporaryWord1 = originalFrame.sp3C +
                                     ((int)(Actor17_7A770Field(&Actor17_7A770Data658A0View1, short*,
                                                               recordAddressOrResult16) *
                                            0x5F5) >>
                                      9);
                    originalFrame.sp3C = temporaryWord1;
                    if (Actor17_7A770TurnMobyTowardHeadingView1(
                            ownerRecord19,
                            Actor17_7A770PlanarHeadingLookupView1(
                                temporaryWord4 - Actor17_7A770Field(ownerRecord19, int*, 0xC),
                                temporaryWord1 - Actor17_7A770Field(ownerRecord19, int*, 0x10), 0,
                                temporaryWord4),
                            5, 0x14, 1, 0) != 0) {
                        Actor17_7A770ResolveMobyYawStepView1(ownerRecord19, 0xE6, 0, 0, 5);
                    }
                    if (Actor17_7A770ApproximatePlanarDistanceView1(ownerRecord19 + 0xC,
                                                                    &originalFrame.sp38) < 0x1F4) {
                        goto incrementOwnerSubstate;
                    }
                    break;
                case 1:
                    rawWord2 = Actor17_7A770ReadSelectedFrameScalarView1(ownerRecord19,
                                                                         polynomialMaskOrArgument5);
                    argumentWord6 = 0;
                    __asm__("" : "=r"(argumentWord6) : "0"(argumentWord6), "r"(rawWord2));
                    argumentWord7 = Actor17_7A770Field(recordAddressOrResult16, int*, 12);
                    rawWord3 = Actor17_7A770Field(recordAddressOrResult16, int*, 16);
                    recordAddressOrResult16 = rawWord2;
                    counterOrArgument4 = Actor17_7A770Field(ownerRecord19, int*, 12);
                    polynomialMaskOrArgument5 = Actor17_7A770Field(ownerRecord19, int*, 16);
                    counterOrArgument4 = argumentWord7 - counterOrArgument4;
                    polynomialMaskOrArgument5 = rawWord3 - polynomialMaskOrArgument5;
                    rawWord2 = Actor17_7A770PlanarHeadingLookupView1(counterOrArgument4,
                                                                     polynomialMaskOrArgument5,
                                                                     argumentWord6, argumentWord7);
                    rawWord2 = Actor17_7A770TurnMobyTowardHeadingView1(ownerRecord19, rawWord2, 7,
                                                                       20, 1, 0);
                    if (rawWord2 &&
                        (rawWord2 = recordAddressOrResult16 - 2, (unsigned int)rawWord2 < 4U)) {
                        Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x34) = 0x17C;
                        goto incrementOwnerSubstate;
                    }
                    break;
                case 2:
                    if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) == 1) {
                        counterOrArgument4 = (int)ownerRecord19;
                        MATCHING_KEEP(counterOrArgument4);
                        Actor17_7A770Data6C770View1 = 0;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 2U;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                        Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                    }
                    if ((Actor17_7A770Data6C770View1 != 0) &&
                        (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 3)) {
                        counterOrArgument4 = (int)ownerRecord19;
                        MATCHING_KEEP(counterOrArgument4);
                        Actor17_7A770Data6C770View1 = 0;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 3U;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                        Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                    }
                    Actor17_7A770TurnMobyTowardHeadingView1(
                        ownerRecord19,
                        Actor17_7A770PlanarHeadingLookupView1(
                            Actor17_7A770Field(recordAddressOrResult16, int*, 0xC) -
                                Actor17_7A770Field(ownerRecord19, int*, 0xC),
                            Actor17_7A770Field(recordAddressOrResult16, int*, 0x10) -
                                Actor17_7A770Field(ownerRecord19, int*, 0x10),
                            0),
                        5, 0, 0, 0);
                    Actor17_7A770ResolveMobyHeadingStepView1(
                        ownerRecord19,
                        Actor17_7A770PlanarHeadingLookupView1(
                            Actor17_7A770Field(recordAddressOrResult16, int*, 0xC) -
                                Actor17_7A770Field(ownerRecord19, int*, 0xC),
                            Actor17_7A770Field(recordAddressOrResult16, int*, 0x10) -
                                Actor17_7A770Field(ownerRecord19, int*, 0x10),
                            0),
                        0xE6, 0, 0, 1);
                    if (Actor17_7A770ApproximatePlanarDistanceView1(
                            ownerRecord19 + 0xC, recordAddressOrResult16 + 0xC) < 0x2BC) {
                        if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 5) {
                            counterOrArgument4 = (int)ownerRecord19;
                            MATCHING_KEEP(counterOrArgument4);
                            Actor17_7A770Data6C770View1 = 0;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 5U;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                        }
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49) =
                            (unsigned char)(Actor17_7A770Field(ownerRecord19, unsigned char*,
                                                               0x49) +
                                            1);
                    }
                    Actor17_7A770UpdateEffectConfigurationView1(
                        ownerRecord19, privateRecordOrArchiveBase17 + 0x34, 4, 0xE, -0xC8);
                    return;
                case 3:
                    temporaryWord9 = Actor17_7A770Field(
                        Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C), int**, 0xC);
                    Actor17_7A770TurnMobyTowardHeadingView1(
                        ownerRecord19,
                        Actor17_7A770PlanarHeadingLookupView1(
                            Actor17_7A770Field(temporaryWord9, int*, 0) -
                                Actor17_7A770Field(ownerRecord19, int*, 0xC),
                            Actor17_7A770Field(temporaryWord9, int*, 4) -
                                Actor17_7A770Field(ownerRecord19, int*, 0x10),
                            0),
                        0xA, 0, 0, 0);
                    if (Actor17_7A770Data6C770View1 != 0) {
                        if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 6) {
                            counterOrArgument4 = (int)ownerRecord19;
                            MATCHING_KEEP(counterOrArgument4);
                            Actor17_7A770Data6C770View1 = 0;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 6U;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                        }
                        rawWord2 = -0x1F4;
                        goto storePrivateCountdown;
                    }
                    break;
                case 4:
                    temporaryWord10 = Actor17_7A770Field(ownerRecord19, int*, 0x14) +
                                      Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x34);
                    Actor17_7A770Field(ownerRecord19, int*, 0x14) = temporaryWord10;
                    temporaryWord14 = Actor17_7A770Field(recordAddressOrResult16, int*, 0x14);
                    if ((temporaryWord10 - temporaryWord14) < 0x400) {
                        Actor17_7A770Field(ownerRecord19, int*, 0x14) =
                            (int)(temporaryWord14 + 0x400);
                        if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 7) {
                            counterOrArgument4 = (int)ownerRecord19;
                            MATCHING_KEEP(counterOrArgument4);
                            Actor17_7A770Data6C770View1 = 0;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 7U;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                        }
                        Actor17_7A770Field(recordAddressOrResult16, int*, 0x18) = 0x02000000;
                        goto incrementOwnerSubstate;
                    }
                    break;
                case 5:
                    if (Actor17_7A770Data6C770View1 != 0) {
                        if (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 2) {
                            counterOrArgument4 = (int)ownerRecord19;
                            MATCHING_KEEP(counterOrArgument4);
                            Actor17_7A770Data6C770View1 = 0;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                            Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 2U;
                            Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                            Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                        }
                        rawWord2 = (firstResult22 + 12) & 255;
                        Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x38) = rawWord2;
                        rawWord2 = 0xDC;
                        goto storePrivateCountdown;
                    }
                    return;
                storePrivateCountdown:
                    Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x34) = rawWord2;
                incrementOwnerSubstate:
                    rawWord2 = Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49);
                    rawWord2 += 1;
                    Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49) = rawWord2;
                    return;
                case 6:
                    if ((Actor17_7A770Data6C770View1 != 0) &&
                        (Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) != 3)) {
                        counterOrArgument4 = (int)ownerRecord19;
                        MATCHING_KEEP(counterOrArgument4);
                        Actor17_7A770Data6C770View1 = 0;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x40) = 0x72;
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x3D) = 3U;
                        Actor17_7A770Field(ownerRecord19, signed char*, 0x3F) = 0;
                        Actor17_7A770EmptyAnimationTransitionHookView1(counterOrArgument4);
                    }
                    Actor17_7A770CopyVectorView1(
                        &originalFrame.sp48,
                        Actor17_7A770Field(
                            Actor17_7A770Field(privateRecordOrArchiveBase17, void**, 0x2C), int**,
                            0xC));
                    originalFrame.sp48 +=
                        (int)(Actor17_7A770Field(
                                  &Actor17_7A770Data65920View1, short*,
                                  (Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x38) *
                                   2)) *
                              0xB) >>
                        2;
                    originalFrame.sp4C +=
                        (int)(Actor17_7A770Field(
                                  &Actor17_7A770Data658A0View1, short*,
                                  (Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x38) *
                                   2)) *
                              0xB) >>
                        2;
                    if (Actor17_7A770ApproximatePlanarDistanceView1(ownerRecord19 + 0xC,
                                                                    &originalFrame.sp48) >= 0x12D) {
                        Actor17_7A770TurnMobyTowardHeadingView1(
                            ownerRecord19,
                            Actor17_7A770PlanarHeadingLookupView1(
                                originalFrame.sp48 - Actor17_7A770Field(ownerRecord19, int*, 0xC),
                                originalFrame.sp4C - Actor17_7A770Field(ownerRecord19, int*, 0x10),
                                0),
                            5, 0, 0, 0);
                        Actor17_7A770ResolveMobyHeadingStepView1(
                            ownerRecord19,
                            Actor17_7A770PlanarHeadingLookupView1(
                                originalFrame.sp48 - Actor17_7A770Field(ownerRecord19, int*, 0xC),
                                originalFrame.sp4C - Actor17_7A770Field(ownerRecord19, int*, 0x10),
                                0),
                            0xE6, 0, 0, 1);
                    }
                    if (Actor17_7A770UpdateEffectConfigurationView1(
                            ownerRecord19, privateRecordOrArchiveBase17 + 0x34, 4, 0xE, -0xC8) !=
                        0) {
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x49) = 0U;
                        Actor17_7A770Field(ownerRecord19, unsigned char*, 0x48) = 0U;
                        Actor17_7A770RequestMobyAnimationView1(ownerRecord19, 0);
                        return;
                    }
                    break;
            }
            break;
        case 8:
            recordAddressOrResult16 = privateRecordOrArchiveBase17 + 0x44;
            if (Actor17_7A770Data6E344View1 == 1)
                return;
            counterOrArgument4 = recordAddressOrResult16;
            polynomialMaskOrArgument5 = 4;
            distanceOrArchiveBase18 = (int)&Actor17_7A770Data6D088View1;
            __asm__(""
                    : "=r"(distanceOrArchiveBase18)
                    : "0"(distanceOrArchiveBase18), "r"(counterOrArgument4),
                      "r"(polynomialMaskOrArgument5));
            Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x44) = 1;
            Actor17_7A770RegisterTrackedValueView1(counterOrArgument4, polynomialMaskOrArgument5,
                                                   distanceOrArchiveBase18);
            counterOrArgument4 = recordAddressOrResult16;
            polynomialMaskOrArgument5 = 4;
            privateRecordOrArchiveBase17 = (int)&Actor17_7A770Data6C7F8View1;
            __asm__(""
                    : "=r"(privateRecordOrArchiveBase17)
                    : "0"(privateRecordOrArchiveBase17), "r"(counterOrArgument4),
                      "r"(polynomialMaskOrArgument5));
            Actor17_7A770RegisterTrackedValueView1(counterOrArgument4, polynomialMaskOrArgument5,
                                                   privateRecordOrArchiveBase17);
            counterOrArgument4 = (int)ownerRecord19;
            polynomialMaskOrArgument5 = 0;
            Actor17_7A770Field(ownerRecord19, unsigned char*, 0x48) = 0;
            goto callSharedOwnerByteArchives;
        case 9:
            rawWord2 = Actor17_7A770Field(privateRecordOrArchiveBase17, int*, 0x44);
            counterOrArgument4 = (int)ownerRecord19;
            if (!rawWord2)
                goto initializeOwnerState9;
            Actor17_7A770Field(ownerRecord19, unsigned char*, 0x48) = 0;
            polynomialMaskOrArgument5 = 0;
        callSharedOwnerByteArchives:
            recordAddressOrResult16 = (int)ownerRecord19 + 0x48;
            Actor17_7A770RequestMobyAnimationView1(counterOrArgument4, polynomialMaskOrArgument5);
            Actor17_7A770RegisterTrackedValueView1(recordAddressOrResult16, 1,
                                                   &Actor17_7A770Data6D088View1);
            Actor17_7A770RegisterTrackedValueView1(recordAddressOrResult16, 1,
                                                   &Actor17_7A770Data6C7F8View1);
            return;
        initializeOwnerState9:
            rawWord2 = 1;
            Actor17_7A770Field(ownerRecord19, short*, 0x38) = 0;
            Actor17_7A770Field(privateRecordOrArchiveBase17, signed char*, 5) = rawWord2;
            rawWord2 = Actor17_7A770Data6C598View1;
            if (rawWord2)
                return;
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            if (Actor17_7A770UpdateMobyInteractionGateView1(counterOrArgument4, 0)) {
                Actor17_7A770StartDialogueView1(ownerRecord19, 0, 8);
                rawWord2 = 8;
                Actor17_7A770Field(ownerRecord19, unsigned char*, 0x48) = rawWord2;
            }
            return;
    }
}
#undef Actor17_7A770Field


/**
 * MobyUpdate_543() - func_level_17_8007B304()
 * Sheep fodder
 * WIP
 * https://decomp.me/scratch/Zzeuz
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_17/moby/func_level_17_8007B304.s SHA256 cf0c1f7c4677913fe9dc9da43c83835c0bab6fb5b87f581272196bf9b5615d54. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level17_7B304Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Spyro Level17_7B304_D_80070328 __asm__("D_80070328");
void Level17_7B304RequestMobyAnimation() __asm__("func_80034F40");
void Level17_7B304EmptyAnimationTransitionHook() __asm__("func_80035734");
int Level17_7B304TurnMobyTowardHeading() __asm__("func_8003585C");
int Level17_7B304CountTimerDown() __asm__("func_800359A4");
int Level17_7B304ResolveMobyYawStep() __asm__("func_80035DDC");
int Level17_7B304SubAngle8() __asm__("func_8003613C");
int Level17_7B304RandBetween() __asm__("func_8003636C");
int Level17_7B304RandSignedBetween() __asm__("func_800363DC");
void Level17_7B304EmitMobyVertexParticles() __asm__("func_800369B8");
int Level17_7B304PlayMobySoundEvent() __asm__("func_8003BABC");
extern int Level17_7B304PlanarHeadingLookup() __asm__("func_8004E880");
extern int Level17_7B304AbsoluteByteAngleDelta() __asm__("func_8004F264");
extern int Level17_7B304ApproximatePlanarDistance() __asm__("func_8004F334");
extern void Level17_7B304DeleteMoby() __asm__("func_80055B18");
extern void Level17_7B304RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");

unsigned char Level17_7B304GetClosestPathNode() __asm__("func_8003645C");
/* extern */
extern int Level17_7B304_D_8006C770 __asm__("D_8006C770");

void func_level_17_8007B304(Moby* ownerRecord) {
    /* Original 0x40-byte frame: outgoing arguments occupy SP+0x10/0x14,
     * helper3645C writes the word at SP+0x18;
      saved S0 begins SP+0x20.
     * Register suffixes record original live roles rather than physical units. */
    struct {
        int sp18;
        unsigned char pad1C[4];
    } scratch;

    register int divisor4 __asm__("$4");
    register int moduloNumerator3 __asm__("$3");
    register int moduloNumerator5 __asm__("$5");
    register void* playerPosition16 __asm__("$16");
    register int absoluteHalfword3 __asm__("$3");
    register int halfword2 __asm__("$2");
    register int coordinate7 __asm__("$7");
    register int coordinate3 __asm__("$3");
    register void* nodePointer3 __asm__("$3");
    register int argument6 __asm__("$6");
    register int nextRemainder21 __asm__("$21");
    register int previousRemainder20 __asm__("$20");
    register int firstNodeResult16 __asm__("$16");
    register int secondNodeResult16 __asm__("$16");
    register int firstMetric16 __asm__("$16");
    register int distanceResult16 __asm__("$16");
    register int initialResult17 __asm__("$17");
    register int selectedNodeResult17 __asm__("$17");
    register int offsetResult17 __asm__("$17");
    register int oppositeResult16 __asm__("$16");
    int divisionResult2;
    register int signedHelperResult3 __asm__("$3");
    int state2HelperResult2;
    int updatedPosition3;
    register int phasePredicate3 __asm__("$3");
    int step4;
    register int absoluteResult2 __asm__("$2");
    register int distancePredicate2 __asm__("$2");
    register int rollPredicate2 __asm__("$2");
    register int pitchPredicate2 __asm__("$2");
    register int rollDelta3 __asm__("$3");
    register int pitchDelta3 __asm__("$3");
    register int updatedHalfword2 __asm__("$2");
    register int constant3 __asm__("$3");
    register int product8 __asm__("$8");
    register int returnWord2 __asm__("$2");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register void* positionArgument4 __asm__("$4");
    register unsigned int phaseByte4 __asm__("$4");
    register unsigned int pitchByte4 __asm__("$4");
    register unsigned int indexByte5 __asm__("$5");
    unsigned int animationFrame5;
    register int stateWord16 __asm__("$16");
    unsigned int animationByte2;
    register unsigned int rollByte3 __asm__("$3");
    unsigned int updatedByte2;
    unsigned int updatedPitch2;
    register void* tableRecord7 __asm__("$7");
    void* privateRecord18;
    void* selectedNode2;
    void* laterNode2;

    privateRecord18 = ownerRecord->mobyTag;
    if (ownerRecord->damageFlags != 0) {
        Level17_7B304PlayMobySoundEvent(ownerRecord, 0, 0);
        SpawnMoby(0x10, ownerRecord);
        Level17_7B304RefreshMobySpatialGridAndBasis(ownerRecord, 4);
        Level17_7B304EmitMobyVertexParticles(ownerRecord, 0x20);
        Level17_7B304DeleteMoby(ownerRecord);
        return;
    }
    stateWord16 = ownerRecord->state;
    switch (stateWord16) { /* irregular */
        case 0:
            positionArgument4 = &ownerRecord->position;
            MATCHING_KEEP(positionArgument4);
            playerPosition16 = &Level17_7B304_D_80070328.position;
            MATCHING_KEEP(playerPosition16);
            if (Level17_7B304ApproximatePlanarDistance(positionArgument4, playerPosition16) <
                0x1C00) {
                returnWord2 = Level17_7B304PlanarHeadingLookup(
                    Level17_7B304Field(playerPosition16, int*, 0) - ownerRecord->position.x,
                    Level17_7B304_D_80070328.position.y - ownerRecord->position.y, 0);
                tableRecord7 = Level17_7B304Field(privateRecord18, void**, 8);
                MATCHING_KEEP_CLOBBER(tableRecord7, "memory");
                indexByte5 = Level17_7B304Field(privateRecord18, unsigned char*, 0x17);
                divisor4 = Level17_7B304Field(tableRecord7, short*, 0);
                __asm__("" : "=r"(divisor4) : "0"(divisor4), "r"(indexByte5));
                /* Both signed DIV sequences retain their original zero/overflow
             * traps and HI results. The helper result stays in V0 until the
             * remainder producers finish, then moves to S1. */
                moduloNumerator3 = indexByte5 + 1;
                __asm__(""
                        : "=r"(moduloNumerator3)
                        : "0"(moduloNumerator3), "r"(divisor4), "r"(tableRecord7));
                nextRemainder21 = moduloNumerator3 % divisor4;
                moduloNumerator3 = divisor4 - 1;
                MATCHING_KEEP(moduloNumerator3);
                moduloNumerator5 = indexByte5 + moduloNumerator3;
                MATCHING_KEEP(moduloNumerator5);
                previousRemainder20 = moduloNumerator5 % divisor4;
                argument6 = 0;
                initialResult17 = returnWord2;
                __asm__("" : "=r"(initialResult17) : "0"(initialResult17), "r"(argument6));
                argument4 = Level17_7B304Field(tableRecord7, int*, 0xC);
                argument5 = ownerRecord->position.y;
                MATCHING_KEEP2(argument4, argument5);
                nodePointer3 = (void*)(nextRemainder21 * 0x10 + argument4);
                MATCHING_KEEP(nodePointer3);
                coordinate7 = Level17_7B304Field(nodePointer3, int*, 0);
                argument4 = ownerRecord->position.x;
                coordinate3 = Level17_7B304Field(nodePointer3, int*, 4);
                argument4 = coordinate7 - argument4;
                MATCHING_KEEP(argument4);
                returnWord2 =
                    Level17_7B304PlanarHeadingLookup(argument4, coordinate3 - argument5, argument6);
                argument6 = 0;
                __asm__("" : "=r"(returnWord2) : "0"(returnWord2), "r"(argument6));
                /* S0 first holds the first node result. Copy it into argument5
             * before replacing S0 with the second node result, and later
             * with the first metric in the original call delay. */
                firstNodeResult16 = returnWord2;
                nodePointer3 = Level17_7B304Field(privateRecord18, void**, 8);
                argument5 = ownerRecord->position.y;
                __asm__("" : "=r"(nodePointer3) : "0"(nodePointer3), "r"(argument5));
                argument4 = Level17_7B304Field(nodePointer3, int*, 0xC);
                nodePointer3 = (void*)(previousRemainder20 * 0x10 + argument4);
                MATCHING_KEEP(nodePointer3);
                coordinate7 = Level17_7B304Field(nodePointer3, int*, 0);
                argument4 = ownerRecord->position.x;
                coordinate3 = Level17_7B304Field(nodePointer3, int*, 4);
                argument4 = coordinate7 - argument4;
                MATCHING_KEEP(argument4);
                returnWord2 =
                    Level17_7B304PlanarHeadingLookup(argument4, coordinate3 - argument5, argument6);
                argument4 = initialResult17;
                argument5 = firstNodeResult16;
                MATCHING_KEEP2(argument4, argument5);
                secondNodeResult16 = returnWord2;
                returnWord2 = Level17_7B304AbsoluteByteAngleDelta(argument4, argument5);
                argument4 = initialResult17;
                argument5 = secondNodeResult16;
                MATCHING_KEEP2(argument4, argument5);
                firstMetric16 = returnWord2;
                if (Level17_7B304AbsoluteByteAngleDelta(argument4, argument5) < firstMetric16) {
                    Level17_7B304Field(privateRecord18, unsigned char*, 0x17) =
                        (unsigned char)nextRemainder21;
                } else {
                    Level17_7B304Field(privateRecord18, unsigned char*, 0x17) =
                        (unsigned char)previousRemainder20;
                }
                selectedNode2 =
                    (Level17_7B304Field(privateRecord18, unsigned char*, 0x17) * 0x10) +
                    Level17_7B304Field(Level17_7B304Field(privateRecord18, void**, 8), int*, 0xC);
                returnWord2 = Level17_7B304PlanarHeadingLookup(
                    Level17_7B304Field(selectedNode2, int*, 0) - ownerRecord->position.x,
                    Level17_7B304Field(selectedNode2, int*, 4) - ownerRecord->position.y, 0);
                argument4 = 0;
                argument5 = 0x20;
                MATCHING_KEEP2(argument4, argument5);
                selectedNodeResult17 = returnWord2;
                offsetResult17 =
                    selectedNodeResult17 + Level17_7B304RandSignedBetween(argument4, argument5);
                oppositeResult16 = Level17_7B304PlanarHeadingLookup(
                    ownerRecord->position.x - Level17_7B304_D_80070328.position.x,
                    ownerRecord->position.y - Level17_7B304_D_80070328.position.y, 0);
                returnWord2 = Level17_7B304SubAngle8(oppositeResult16, offsetResult17 & 0xFF);
                constant3 = 0x6C;
                MATCHING_KEEP(constant3);
                argument4 = 0x46;
                argument5 = 0x5A;
                product8 = returnWord2 * constant3;
                MATCHING_KEEP(product8);
                returnWord2 = product8 >> 7;
                oppositeResult16 = oppositeResult16 + returnWord2;
                Level17_7B304Field(privateRecord18, unsigned char*, 0xC) = oppositeResult16;
                Level17_7B304Field(privateRecord18, unsigned char*, 0xE) =
                    Level17_7B304RandBetween(argument4, argument5);
                Level17_7B304Field(privateRecord18, unsigned char*, 0xF) = 0U;
                divisionResult2 =
                    (int)(Level17_7B304ApproximatePlanarDistance(
                              &ownerRecord->position,
                              Level17_7B304Field(Level17_7B304Field(privateRecord18, void**, 8),
                                                 int*, 0xC) +
                                  (Level17_7B304Field(privateRecord18, unsigned char*, 0x17) *
                                   0x10)) /
                          (int)Level17_7B304Field(privateRecord18, unsigned char*, 0xE)) >>
                    1;
                Level17_7B304Field(privateRecord18, signed char*, 0xD) =
                    (signed char)divisionResult2;
                if ((unsigned int)(divisionResult2 & 0xFF) >= 0x5BU) {
                    Level17_7B304Field(privateRecord18, signed char*, 0xD) = 0x5A;
                }
                ownerRecord->state = 1;
                Level17_7B304RequestMobyAnimation(ownerRecord, 1);
                return;
            }
            if ((Level17_7B304_D_8006C770 != 0) && (ownerRecord->animationState.nextId != 0)) {
                Level17_7B304_D_8006C770 = 0;
                animationByte2 = ownerRecord->animationState.nextId;
                animationFrame5 = ownerRecord->animationState.nextFrame;
                ownerRecord->animationProgress = 0x72;
                ownerRecord->animationState.nextId = 0;
                ownerRecord->animationState.nextFrame = 0;
                ownerRecord->animationState.id = animationByte2;
                ownerRecord->animationState.frame = animationFrame5;
                Level17_7B304EmptyAnimationTransitionHook(ownerRecord);
                return;
            }
            return;
        case 1:
            returnWord2 = Level17_7B304ApproximatePlanarDistance(
                &ownerRecord->position,
                Level17_7B304Field(Level17_7B304Field(privateRecord18, void**, 8), int*, 0xC) +
                    (Level17_7B304Field(privateRecord18, unsigned char*, 0x17) * 0x10));
            phaseByte4 = Level17_7B304Field(privateRecord18, unsigned char*, 0xF);
            phasePredicate3 = phaseByte4 < Level17_7B304Field(privateRecord18, unsigned char*, 0xE);
            __asm__("" : "=r"(phasePredicate3) : "0"(phasePredicate3), "r"(returnWord2));
            __asm__("" : "=r"(returnWord2) : "0"(returnWord2), "r"(phasePredicate3));
            distanceResult16 = returnWord2;
            if (phasePredicate3) {
                MATCHING_KEEP(phaseByte4);
                returnWord2 = phaseByte4 + 0xA;
                MATCHING_KEEP(returnWord2);
                Level17_7B304Field(privateRecord18, unsigned char*, 0xF) = returnWord2;
            }
            if (Level17_7B304CountTimerDown(privateRecord18 + 0xD, 1) != 0) {
                laterNode2 =
                    (Level17_7B304Field(privateRecord18, unsigned char*, 0x17) * 0x10) +
                    Level17_7B304Field(Level17_7B304Field(privateRecord18, void**, 8), int*, 0xC);
                signedHelperResult3 = Level17_7B304SubAngle8(
                    Level17_7B304PlanarHeadingLookup(
                        Level17_7B304Field(laterNode2, int*, 0) - ownerRecord->position.x,
                        Level17_7B304Field(laterNode2, int*, 4) - ownerRecord->position.y, 0),
                    (int)Level17_7B304Field(privateRecord18, unsigned char*, 0xC));
                MATCHING_KEEP(signedHelperResult3);
                absoluteResult2 = signedHelperResult3;
                if (signedHelperResult3 < 0) {
                    absoluteResult2 = -absoluteResult2;
                    MATCHING_KEEP(absoluteResult2);
                }
                step4 = 1;
                if (absoluteResult2 >= 0x1F) {
                    step4 = 2;
                }
                if (signedHelperResult3 > 0) {
                    updatedByte2 = Level17_7B304Field(privateRecord18, unsigned char*, 0xC) - step4;
                    goto storeUpdatedByte;
                }
                if (signedHelperResult3 < 0) {
                    updatedByte2 = Level17_7B304Field(privateRecord18, unsigned char*, 0xC) + step4;
                storeUpdatedByte:
                    Level17_7B304Field(privateRecord18, unsigned char*, 0xC) = updatedByte2;
                }
            }
            if (Level17_7B304TurnMobyTowardHeading(
                    ownerRecord, (int)Level17_7B304Field(privateRecord18, unsigned char*, 0xC), 5,
                    0x14, 1, 0) != 0) {
                if (Level17_7B304ResolveMobyYawStep(
                        ownerRecord, (int)Level17_7B304Field(privateRecord18, unsigned char*, 0xF),
                        0x12C, 0x12C, 5) != 0) {
                    Level17_7B304Field(privateRecord18, unsigned short*, 6) =
                        (unsigned short)(Level17_7B304Field(privateRecord18, unsigned short*, 6) +
                                         1);
                } else {
                    Level17_7B304Field(privateRecord18, unsigned short*, 6) = 0U;
                }
                if ((short)Level17_7B304Field(privateRecord18, unsigned short*, 6) >= 4) {
                    if (Level17_7B304_D_8006C770 != 0) {
                        if (distanceResult16 < 0x1400) {
                            ownerRecord->state = 0;
                        } else {
                            Level17_7B304Field(privateRecord18, unsigned char*, 0xC) =
                                (unsigned char)(Level17_7B304Field(privateRecord18, unsigned char*,
                                                                   0xC) +
                                                Level17_7B304RandSignedBetween(0x3C, 0x64));
                        }
                    }
                    goto distanceCheck;
                }
                distancePredicate2 = distanceResult16 < 0x708;
            } else {
            distanceCheck:
                distancePredicate2 = distanceResult16 < 0x708;
            }
            if ((distancePredicate2 != 0) && (Level17_7B304_D_8006C770 != 0)) {
                ownerRecord->state = 0;
                return;
            }
            break;
        case 2:
            state2HelperResult2 = Level17_7B304CountTimerDown(privateRecord18 + 0xD, 1);
            if (state2HelperResult2 != 0) {
                if (state2HelperResult2 == stateWord16) {
                    ownerRecord->lowDrawDistance = 0x30;
                    ownerRecord->unknown3[0] = 1;
                    ownerRecord->drawn = 1;
                    ownerRecord->highDrawDistance = ownerRecord->lowDrawDistance;
                }
                updatedHalfword2 = Level17_7B304Field(privateRecord18, unsigned short*, 4) - 0xC;
                Level17_7B304Field(privateRecord18, unsigned short*, 4) = updatedHalfword2;
                if ((short)updatedHalfword2 < -0x1F4) {
                    Level17_7B304Field(privateRecord18, short*, 4) = -0x1F4;
                }
                updatedPosition3 = ownerRecord->position.z +
                                   (short)Level17_7B304Field(privateRecord18, unsigned short*, 4);
                ownerRecord->position.z = updatedPosition3;
                if ((Level17_7B304Field(privateRecord18, int*, 0x10) +
                     ownerRecord->distanceToGround) >= updatedPosition3) {
                    /* The original reads this signed halfword independently
                 * before the sign guard and before the absolute-value path.
                 * Retain the reload rather than assuming a cached sign. */
                    halfword2 = Level17_7B304Field(privateRecord18, short*, 4);
                    MATCHING_KEEP_CLOBBER(halfword2, "memory");
                    if (halfword2 >= 0)
                        goto checkCounterAndAngles;
                    returnWord2 = Level17_7B304Field(privateRecord18, unsigned char*, 0x16);
                    absoluteHalfword3 = Level17_7B304Field(privateRecord18, short*, 4);
                    __asm__(""
                            : "=r"(absoluteHalfword3)
                            : "0"(absoluteHalfword3), "r"(returnWord2));
                    returnWord2 += 1;
                    MATCHING_KEEP(returnWord2);
                    if (absoluteHalfword3 < 0) {
                        absoluteHalfword3 = -absoluteHalfword3;
                    }
                    Level17_7B304Field(privateRecord18, unsigned char*, 0x16) = returnWord2;
                    if (absoluteHalfword3 < 0x32) {
                        ownerRecord->angle.roll = 0;
                        ownerRecord->angle.pitch = 0;
                        ownerRecord->position.z = Level17_7B304Field(privateRecord18, int*, 0x10) +
                                                  ownerRecord->distanceToGround;
                        Level17_7B304GetClosestPathNode(
                            &ownerRecord->position, Level17_7B304Field(privateRecord18, void**, 8),
                            &scratch.sp18);
                        Level17_7B304Field(Level17_7B304Field(privateRecord18, void**, 8), short*,
                                           2) = (short)scratch.sp18;
                        ownerRecord->state = 0;
                        Level17_7B304RequestMobyAnimation(ownerRecord, 0);
                    }
                    Level17_7B304Field(privateRecord18, unsigned short*, 4) = (unsigned short)-(
                        (int)((short)Level17_7B304Field(privateRecord18, unsigned short*, 4) * 5) >>
                        3);
                }
            checkCounterAndAngles:
                if ((unsigned char)Level17_7B304Field(privateRecord18, unsigned char*, 0x16) >=
                    2U) {
                    rollByte3 = ownerRecord->angle.roll;
                    if (rollByte3 < 0x80U) {
                        rollDelta3 = -(int)rollByte3;
                    } else {
                        returnWord2 = 0x100;
                        MATCHING_KEEP(returnWord2);
                        rollDelta3 = returnWord2 - rollByte3;
                    }
                    if (rollDelta3 >= 6) {
                        rollDelta3 = 5;
                        MATCHING_KEEP(rollDelta3);
                    }
                    rollPredicate2 = rollDelta3 < -5;
                    if (rollPredicate2 != 0) {
                        rollDelta3 = -5;
                    }
                    pitchByte4 = ownerRecord->angle.pitch;
                    ownerRecord->angle.roll += rollDelta3;
                    pitchDelta3 = -(int)pitchByte4;
                    if (pitchByte4 >= 0x80U) {
                        returnWord2 = 0x100;
                        MATCHING_KEEP(returnWord2);
                        pitchDelta3 = returnWord2 - pitchByte4;
                    }
                    if (pitchDelta3 >= 6) {
                        pitchDelta3 = 5;
                        MATCHING_KEEP(pitchDelta3);
                    }
                    pitchPredicate2 = pitchDelta3 < -5;
                    if (pitchPredicate2 != 0) {
                        pitchDelta3 = -5;
                    }
                    returnWord2 = ownerRecord->angle.pitch;
                    MATCHING_KEEP(returnWord2);
                    updatedPitch2 = returnWord2 + pitchDelta3;
                } else {
                    returnWord2 = ownerRecord->angle.roll;
                    coordinate3 = Level17_7B304Field(privateRecord18, unsigned char*, 0x14);
                    MATCHING_KEEP2(returnWord2, coordinate3);
                    returnWord2 = returnWord2 + coordinate3;
                    ownerRecord->angle.roll = returnWord2;
                    MATCHING_BARRIER("memory");
                    returnWord2 = ownerRecord->angle.pitch;
                    coordinate3 = Level17_7B304Field(privateRecord18, unsigned char*, 0x15);
                    MATCHING_KEEP2(returnWord2, coordinate3);
                    updatedPitch2 = returnWord2 + coordinate3;
                }
                ownerRecord->angle.pitch = updatedPitch2;
                Level17_7B304RefreshMobySpatialGridAndBasis(ownerRecord, 2);
            }
            break;
    }
}
#undef Level17_7B304Field


////////////////////////////////////////////////////////////////////////////////////
// Vehicles (level 10 mobys)
// Probable include split here - these are amongst level-specific mobys in Sunrise Spring Home though
// Possible that these are just taken straight from the level 10 mobys, assuming they're the same
// Sheep are probably different though

/**
 * MobyUpdate_514() - func_level_17_8007BA60()
 * 
 * TODO
 */
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

extern unsigned char D_8006C7B4;
/* AI generated adaptation; not human reviewed. SCUS-94467 level17 8007BA60. */
typedef struct {
    int unk0, unk4, unk8;
    PathTag* path;
    int timer;
} Vehicle546Tag;
extern unsigned char Vehicle546Table[] __asm__("D_80071FB0");
void func_level_17_8007BA60(Moby* moby) {
    Vector3D sp10, sp20, sp30, sp40, sp50, sp60;
    int temp_v1_3, count;
    Vehicle546Tag* mobyTag = (Vehicle546Tag*)moby->mobyTag;
    switch (moby->state) {
        case 0:
            switch (moby->substate) {
                case 0:
                    if (progressFlags.lvl20_WhirligigUsable) {
                        func_80055B18(moby);
                        return;
                    }
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
                        moby->substate = 2;
                        moby->state = 7;
                    } else {
                        moby->substate = 2;
                        moby->state = 1;
                        moby->position.z += 0x1000;
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
        case 1:
            if (mobyTag->timer != 0) {
                moby->position.z += 64;
                func_800359A4(&mobyTag->timer, 4);
                if (moby->substate == 0) {
                    spyro.unk17a = 0x10000002;
                    if (spyro.movementState == 0)
                        moby->substate = 1;
                }
            }
            if (D_8006C7B4 & 1)
                moby->state = 2;
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
            spyro.unk17a = 0x10000002;
            break;
        case 3:
            switch (moby->substate) {
                case 0:
                    sp20.x = (D_80065920[moby->angle.yaw] * 3) >> 3;
                    sp20.y = (D_800658A0[moby->angle.yaw] * 3) >> 3;
                    sp20.z = 0;
                    func_8004F194(&sp20, &sp20, &moby->position);
                    if (ovlHeader.unk2b(&sp20, moby->angle.yaw + 0x80, 0) != 0) {
                        spyro.unk17c = 0;
                        func_8004F178(&sp20, &moby->position);
                        sp20.z += 0x280;
                        ovlHeader.unk2c(&sp20);
                        moby->substate = 1;
                    }
                    break;
                case 1:
                    func_8004F178(&sp20, &moby->position);
                    sp20.z += 0x280;
                    ovlHeader.unk2c(&sp20);
                    break;
            }
            if (spyro.m_StoodOnMoby == moby) {
                moby->state = 4;
                case 4:
                    if (spyro.m_StoodOnMoby != moby) {
                        camera.unk168 = 0;
                        moby->state = 3;
                    } else {
                        if (ovlHeader.unk2b(&moby->position, moby->angle.yaw, 0) != 0) {
                            D_80070104.loadLevel = currentLevel + 3;
                            if (D_80070104.loadLevel > 20)
                                D_80070104.loadLevel = 20;
                            mobyTag->timer = 120;
                            moby->state = 6;
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
            func_8004F178(&sp30, &moby->position);
            sp30.z += 0x200;
            sp30.z = func_8001A358(&sp30, 0x200);
            if (sp30.z != 0) {
                moby->position.z = sp30.z;
                func_80013B7C(0);
                moby->state = 8;
            }
            func_80055D24(moby, 2);
            break;

        case 8:
            sp40.x = D_80065920[moby->angle.yaw];
            sp40.y = D_800658A0[moby->angle.yaw];
            sp40.z = 0;
            func_8004F194(&sp40, &sp40, &moby->position);
            if (ovlHeader.unk2c(&sp40) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp40, moby->angle.yaw, 0);
                mobyTag->timer = 120;
                moby->state = 9;
            }
            break;

        case 9:
            sp50.x = D_80065920[moby->angle.yaw];
            sp50.y = D_800658A0[moby->angle.yaw];
            sp50.z = 0;
            func_8004F194(&sp50, &sp50, &moby->position);
            moby->position.z += 64;
            func_800359A4(&mobyTag->timer, 4);
            if (ovlHeader.unk2b(&sp50, moby->angle.yaw, 0) != 0) {
                func_8004F178(&sp60, &spyro.position);
                sp60.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp60, spyro.bodyRotation.yaw);
                moby->substate = 0;
                moby->state = 1;
            }
            break;
    }
}


/**
 * MobyUpdate_516() - func_level_17_8007C3D0()
 * 
 * TODO
 */
extern unsigned char D_8006C7B4;
/* AI generated adaptation; not human reviewed. Original SCUS-94467 level17 8007C3D0. */
typedef struct {
    int unk0;
    PathTag* path;
    int timer;
} Vehicle883Tag;
extern Moby* Vehicle883Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*, int);
void func_level_17_8007C3D0(Moby* moby) {
    Vector3D sp10, sp20, sp30, sp40, sp50, sp60;
    int temp_v1_3;
    Vehicle883Tag* mobyTag;

    mobyTag = (Vehicle883Tag*)moby->mobyTag;
    switch (moby->state) {

        case 0:
            switch (moby->substate) {
                case 0:
                    if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                        func_80055B18(moby);
                        return;
                    } else {
                        func_80034F80(moby, 2);
                        moby->position.z += 0x1000;
                        if (currentLevel == 37)
                            moby->position.z += 0x800;
                        spyro.unk17a = 0x1001A000;
                        spyro.unk20[1] = 0;
                        func_8004F178(&spyro.unk19, &moby->position);
                        spyro.unk19.z += spyro.unk4a + 0x604;
                        spyro.unk18.roll = moby->angle.roll;
                        spyro.unk18.pitch = moby->angle.pitch;
                        spyro.unk18.yaw = moby->angle.yaw;
                        moby->substate = 1;
                        func_8003B7B4(&moby->substate, 1, &savedData);
                        func_8003B7B4(&moby->substate, 1, &unsavedData);
                        moby->state = 8;
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
            switch (moby->substate) {
                case 0:
                    sp10.x = (D_80065920[moby->angle.yaw] * 3) >> 3;
                    sp10.y = (D_800658A0[moby->angle.yaw] * 3) >> 3;
                    sp10.z = 0;
                    func_8004F194(&sp10, &sp10, &moby->position);
                    if (ovlHeader.unk2b(&sp10, moby->angle.yaw + 0x80, 0) != 0) {
                        spyro.unk17c = 0;
                        func_8004F178(&sp10, &moby->position);
                        sp10.z += 0x280;
                        ovlHeader.unk2c(&sp10);
                        moby->substate = 1;
                    }
                    break;
                case 1:
                    func_8004F178(&sp10, &moby->position);
                    sp10.z += 0x280;
                    ovlHeader.unk2c(&sp10);
                    break;
            }
            if (spyro.m_StoodOnMoby == moby) {
                moby->state = 2;
                case 2:
                    if (spyro.m_StoodOnMoby != moby) {
                        camera.unk168 = 0;
                        moby->state = 1;
                    } else {
                        if (ovlHeader.unk2b(&moby->position, moby->angle.yaw, 0) != 0) {
                            D_80070104.loadLevel = ((currentLevel / 10) + 1) * 10;
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
                if (Vehicle883Moby != 0) {
                    *((unsigned char*)Vehicle883Moby + 0x4C) = 0;
                    *((unsigned char*)Vehicle883Moby + 0x4D) = 0;
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
            sp20.x = D_80065920[moby->angle.yaw];
            sp20.y = D_800658A0[moby->angle.yaw];
            sp20.z = 0;
            func_8004F194(&sp20, &sp20, &moby->position);
            if (ovlHeader.unk2c(&sp20) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp20, moby->angle.yaw, 0);
                moby->state = 7;
            }
            break;

        case 7:
            sp30.x = D_80065920[moby->angle.yaw];
            sp30.y = D_800658A0[moby->angle.yaw];
            sp30.z = 0;
            func_8004F194(&sp30, &sp30, &moby->position);
            if (ovlHeader.unk2b(&sp30, moby->angle.yaw, 0) != 0) {
                func_8004F178(&sp40, &spyro.position);
                sp40.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp40, spyro.bodyRotation.yaw);
                mobyTag->timer = 120;
                moby->substate = 0;
                func_80034F40(moby, 1);
                moby->state = 10;
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
            func_8004F178(&sp50, &moby->position);
            moby->position.z += 0x400;
            sp50.z += 0x200;
            sp50.z = func_8001A358(&sp50, 0x200);
            if (sp50.z != 0) {
                moby->position.z = sp50.z;
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
                goto updateCollision2;
            } else
                goto rollbackLanding;
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
        case 10:
            if (mobyTag->timer != 0) {
                moby->position.z += 64;
                func_800359A4(&mobyTag->timer, 4);
                if (moby->substate == 0) {
                    spyro.unk17a = 0x10000002;
                    if (spyro.movementState == 0)
                        moby->substate = 1;
                }
            }
            if (D_8006C7B4 & 1) {
                func_80034F40(moby, 3);
                moby->state = 11;
            } else if (moby->animationState.id == 1 && D_8006C770 != 0)
                func_80034F80(moby, 2);
            break;
        case 11:
            if (moby->animationState.id == 3 && D_8006C770 != 0)
                func_80034F80(moby, 0);
            spyro.unk17a = 0x10000002;
            moby->position.z -= 64;
            func_8004F178(&sp60, &moby->position);
            moby->position.z += 1024;
            sp60.z += 512;
            sp60.z = func_8001A358(&sp60, 512);
            if (sp60.z != 0) {
                moby->position.z = sp60.z;
                if (moby->animationState.id == 0) {
                    moby->substate = 0;
                    moby->state = 1;
                }
            } else {
            rollbackLanding:
                moby->position.z -= 1024;
            }
        updateCollision2:
            func_80055D24(moby, 2);
            break;
    }
    func_80055D24(moby, 1);
}


/**
 * MobyUpdate_651() - func_level_17_8007D19C() - MATCHING
 * Tonnes of includes which should be in the decomp.me context really
 * ASM not deleted yet for cross-level reasons, todo
 * https://decomp.me/scratch/YdBst
 */
typedef struct {
    int unk0;
    int unk4;
    PathTag* unk8;
    int unkC; // countdown timer of some sort
    int unk10;
} MobyTag_651;

/* AI-generated readability only, not human reviewed. Local names describe
 * typed vectors and the actual remainder; unknown fields/control remain intact.
 * Original instruction/frame/table/helper and complete image gates apply. */
void func_level_17_8007D19C(Moby* moby) {
    Vector3D vector1;
    Vector3D vector2;
    Vector3D vector3;
    Vector3D vector4;
    Vector3D vector5;
    Vector3D vector6;
    int remainder;
    MobyTag_651* mobyTag;

    mobyTag = (MobyTag_651*)moby->mobyTag;
    switch (moby->state) {

        case 0:
            switch (moby->substate) {
                case 0:
                    if (progressFlags.lvl30_RocketUsable ||
                        ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable)) {
                        func_80055B18(moby);
                        return;
                    } else {
                        moby->position.z += 0x1000;
                        spyro.unk17a = 0x10018000;
                        spyro.unk20[1] = 0;
                        func_8004F178(&spyro.unk19, &moby->position);
                        spyro.unk19.z += spyro.unk4a + 0x133;
                        spyro.unk18.roll = moby->angle.roll;
                        spyro.unk18.pitch = moby->angle.pitch;
                        spyro.unk18.yaw = moby->angle.yaw;
                        moby->substate = 1;
                        func_8003B7B4(&moby->substate, 1, &savedData);
                        func_8003B7B4(&moby->substate, 1, &unsavedData);
                        moby->state = 7;
                        if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) &&
                            ((remainder = D_8006C73C % 10, (remainder == 0)) ||
                             ((remainder == 7) && (D_8006C73C < 0x3C))) &&
                            (moby->mobyClass == D_8006C528)) {
                            moby->position.z += 0xC00;
                            func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes,
                                          &moby->position);
                            camera.unk170.yaw = 0;
                            camera.unk170.pitch = 0;
                            spyro.unk17a = 0x10018000;
                            spyro.unk20[1] = 0;
                            camera.unk170.pos.azimuth -= spyro.rotation.yaw;
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
            switch (moby->substate) {
                case 0:
                    vector1.x = (D_80065920[moby->angle.yaw] * 3) >> 3;
                    vector1.y = (D_800658A0[moby->angle.yaw] * 3) >> 3;
                    vector1.z = 0;
                    func_8004F194(&vector1, &vector1, &moby->position);
                    if (ovlHeader.unk2b(&vector1, moby->angle.yaw + 0x80, 0) != 0) {
                        spyro.unk17c = 0;
                        func_8004F178(&vector1, &moby->position);
                        vector1.z += 0x280;
                        ovlHeader.unk2c(&vector1);
                        moby->substate = 1;
                    }
                    break;
                case 1:
                    func_8004F178(&vector1, &moby->position);
                    vector1.z += 0x280;
                    ovlHeader.unk2c(&vector1);
                    break;
            }
            if (spyro.m_StoodOnMoby == moby) {
                moby->state = 2;
                case 2:
                    if (spyro.m_StoodOnMoby != moby) {
                        camera.unk168 = 0;
                        moby->state = 1;
                    } else {
                        if (ovlHeader.unk2b(&moby->position, moby->angle.yaw, 0) != 0) {
                            D_80070104.loadLevel = ((currentLevel / 10) + 1) * 0xA;
                            moby->state = 4U;
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
            vector2.x = D_80065920[moby->angle.yaw];
            vector2.y = D_800658A0[moby->angle.yaw];
            vector2.z = 0;
            func_8004F194(&vector2, &vector2, &moby->position);
            if (ovlHeader.unk2c(&vector2) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&vector2, moby->angle.yaw, 0);
                moby->state = 6U;
            }
            break;

        case 6:
            vector3.x = D_80065920[moby->angle.yaw];
            vector3.y = D_800658A0[moby->angle.yaw];
            vector3.z = 0;
            func_8004F194(&vector3, &vector3, &moby->position);
            if (ovlHeader.unk2b(&vector3, moby->angle.yaw, 0) != 0) {
                func_8004F178(&vector4, &spyro.position);
                vector4.z -= spyro.unk4a;
                func_8003B634(&savedData, &vector4, spyro.bodyRotation.yaw);
                mobyTag->unkC = 0x78;
                moby->substate = 0;
                moby->state = 8;
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
            func_8004F178(&vector5, &moby->position);
            moby->position.z += 0x400;
            vector5.z += 0x200;
            vector5.z = func_8001A358(&vector5, 0x200);
            if (vector5.z != 0) {
                moby->position.z = vector5.z;
                func_80013B7C(0);
                moby->state = 5U;
            } else {
                moby->position.z -= 0x400;
            }
            func_80055D24(moby, 2);
            break;

        case 8:
            func_80034F40(moby, 1);
            if (mobyTag->unkC != 0) {
                moby->position.z += 0x40;
                func_800359A4(&mobyTag->unkC, 4);
                if (moby->substate == 0) {
                    spyro.unk17a = 0x10000002;
                    if (spyro.movementState == 0) {
                        moby->substate = 1;
                    }
                }
            }
            if (D_8006C7B4 & 1) {
                moby->state = 9;
            }
            break;

        case 9:
            spyro.unk17a = 0x10000002;
            func_80034F40(moby, 1);
            moby->position.z -= 0x40;
            func_8004F178(&vector6, &moby->position);
            moby->position.z += 0x400;
            vector6.z += 0x200;
            vector6.z = func_8001A358(&vector6, 0x200);
            if (vector6.z != 0) {
                moby->position.z = vector6.z;
                moby->substate = 0;
                moby->state = 1;
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

////////////////////////////////////////////////////////////////////////////////////
// Eggs

extern void func_80039714(Moby*);

/**
 * MobyUpdate_132() - func_level_17_8007DC38()
 * Eggs
 * WIP
 * https://decomp.me/scratch/U56AS
 */
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
void func_level_17_8007DC38(void* input) {
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


/**
 * MobyUpdate_501() - func_level_17_8007ED8C()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_17_8007ED8C(Moby* moby) {
    func_80039714(moby);
}

////////////////////////////////////////////////////////////////////////////////////
// Utils

/**
 * MobyUpdate_311() - func_level_17_8007EDAC()
 * Triangle to talk text
 * Difficult to match? Possibly lots of local variables which need specifying in the right places
 * https://decomp.me/scratch/RnpBS
 */
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
void func_level_17_8007EDAC(Moby* mobyArgument) {
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
